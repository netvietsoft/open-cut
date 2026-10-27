// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 2/5 for libquick.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 2/5 cho libquick.so
// Covers FDE indices [379 .. 757] out of 1,893 total FDEs
// Bao phủ chỉ số FDE [379 .. 757] trên tổng số 1.893 FDE
// ============================================================================
#include "quick_core.h"

// FDE #0379 | PC: 0x08136c | FDE: 0x03dd50 | Size: 256 bytes [_Z18JS_GetPrototype_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0379 | Địa chỉ PC: 0x08136c | Địa chỉ FDE: 0x03dd50 | Kích thước: 256 bytes
//   0x08136c: D10303FF  sub      sp, sp, #0xc0
//   0x081370: F90043F7  str      x23, [sp, #0x80]
//   0x081374: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x081378: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0379_0x08136c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08136cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x03dd50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0380 | PC: 0x081900 | FDE: 0x03dd78 | Size: 256 bytes
// Khung tháo gỡ #0380 | Địa chỉ PC: 0x081900 | Địa chỉ FDE: 0x03dd78 | Kích thước: 256 bytes
//   0x081900: D101C3FF  sub      sp, sp, #0x70
//   0x081904: F9000BFC  str      x28, [sp, #0x10]
//   0x081908: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x08190c: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_0380_0x081900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081900ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x03dd78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0381 | PC: 0x081b58 | FDE: 0x03dda8 | Size: 256 bytes
// Khung tháo gỡ #0381 | Địa chỉ PC: 0x081b58 | Địa chỉ FDE: 0x03dda8 | Kích thước: 256 bytes
//   0x081b58: D10103FF  sub      sp, sp, #0x40
//   0x081b5c: F9000BF6  str      x22, [sp, #0x10]
//   0x081b60: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x081b64: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0381_0x081b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081b58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03dda8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0382 | PC: 0x081e90 | FDE: 0x03ddc8 | Size: 256 bytes
// Khung tháo gỡ #0382 | Địa chỉ PC: 0x081e90 | Địa chỉ FDE: 0x03ddc8 | Kích thước: 256 bytes
//   0x081e90: D10183FF  sub      sp, sp, #0x60
//   0x081e94: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x081e98: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x081e9c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0382_0x081e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081e90ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03ddc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0383 | PC: 0x08211c | FDE: 0x03ddf0 | Size: 256 bytes
// Khung tháo gỡ #0383 | Địa chỉ PC: 0x08211c | Địa chỉ FDE: 0x03ddf0 | Kích thước: 256 bytes
//   0x08211c: D10243FF  sub      sp, sp, #0x90
//   0x082120: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x082124: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x082128: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0383_0x08211c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08211cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03ddf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0384 | PC: 0x082540 | FDE: 0x03de20 | Size: 256 bytes [_Z19JS_ToCStringLen2_GCP12LEPUSContextPm10LEPUSValuei]
// Khung tháo gỡ #0384 | Địa chỉ PC: 0x082540 | Địa chỉ FDE: 0x03de20 | Kích thước: 256 bytes
//   0x082540: D10183FF  sub      sp, sp, #0x60
//   0x082544: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x082548: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x08254c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0384_0x082540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082540ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03de20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0385 | PC: 0x082904 | FDE: 0x03de48 | Size: 256 bytes [_Z17JS_ValueToAtom_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0385 | Địa chỉ PC: 0x082904 | Địa chỉ FDE: 0x03de48 | Kích thước: 256 bytes
//   0x082904: D10103FF  sub      sp, sp, #0x40
//   0x082908: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08290c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x082910: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0385_0x082904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082904ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03de48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0386 | PC: 0x082acc | FDE: 0x03de68 | Size: 156 bytes
// Khung tháo gỡ #0386 | Địa chỉ PC: 0x082acc | Địa chỉ FDE: 0x03de68 | Kích thước: 156 bytes
//   0x082acc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x082ad0: AA0003F3  mov      x19, x0
//   0x082ad4: F9400800  ldr      x0, [x0, #0x10]
//   0x082ad8: 5284E208  mov      w8, #0x2710
static inline uint64_t fde_func_0386_0x082acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082accULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03de68ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0387 | PC: 0x082b68 | FDE: 0x03de80 | Size: 256 bytes
// Khung tháo gỡ #0387 | Địa chỉ PC: 0x082b68 | Địa chỉ FDE: 0x03de80 | Kích thước: 256 bytes
//   0x082b68: D102C3FF  sub      sp, sp, #0xb0
//   0x082b6c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x082b70: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x082b74: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0387_0x082b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082b68ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x03de80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0388 | PC: 0x082e9c | FDE: 0x03deb0 | Size: 256 bytes
// Khung tháo gỡ #0388 | Địa chỉ PC: 0x082e9c | Địa chỉ FDE: 0x03deb0 | Kích thước: 256 bytes
//   0x082e9c: D371FC28  lsr      x8, x1, #0x31
//   0x082ea0: B6800041  tbz      x1, #0x30, #0x82ea8
//   0x082ea4: B4000108  cbz      x8, #0x82ec4
//   0x082ea8: D2800049  mov      x9, #2
static inline uint64_t fde_func_0388_0x082e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082e9cULL ^ (static_cast<uint64_t>(0xd371fc28ULL) << 13);
    acc = (acc + a1 + 0xb6800041ULL) ^ 0x03deb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0389 | PC: 0x083018 | FDE: 0x03dec8 | Size: 256 bytes
// Khung tháo gỡ #0389 | Địa chỉ PC: 0x083018 | Địa chỉ FDE: 0x03dec8 | Kích thước: 256 bytes
//   0x083018: D10143FF  sub      sp, sp, #0x50
//   0x08301c: F90013F6  str      x22, [sp, #0x20]
//   0x083020: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x083024: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0389_0x083018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083018ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x03dec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0390 | PC: 0x083174 | FDE: 0x03dee8 | Size: 256 bytes [_Z15JS_ToFloat64_GCP12LEPUSContextPd10LEPUSValue]
// Khung tháo gỡ #0390 | Địa chỉ PC: 0x083174 | Địa chỉ FDE: 0x03dee8 | Kích thước: 256 bytes
//   0x083174: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x083178: D2FFFFC8  mov      x8, #-0x2000000000000
//   0x08317c: 8B080049  add      x9, x2, x8
//   0x083180: 92E00088  mov      x8, #-0x4000000000001
static inline uint64_t fde_func_0390_0x083174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083174ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd2ffffc8ULL) ^ 0x03dee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0391 | PC: 0x0832b8 | FDE: 0x03df00 | Size: 256 bytes
// Khung tháo gỡ #0391 | Địa chỉ PC: 0x0832b8 | Địa chỉ FDE: 0x03df00 | Kích thước: 256 bytes
//   0x0832b8: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0832bc: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0832c0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0832c4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0391_0x0832b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0832b8ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03df00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0392 | PC: 0x08342c | FDE: 0x03df28 | Size: 256 bytes [_Z17JS_NewRuntime2_GCPK20LEPUSMallocFunctionsPvj]
// Khung tháo gỡ #0392 | Địa chỉ PC: 0x08342c | Địa chỉ FDE: 0x03df28 | Kích thước: 256 bytes
//   0x08342c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x083430: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x083434: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x083438: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0392_0x08342c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08342cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x03df28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0393 | PC: 0x083e5c | FDE: 0x03df58 | Size: 256 bytes
// Khung tháo gỡ #0393 | Địa chỉ PC: 0x083e5c | Địa chỉ FDE: 0x03df58 | Kích thước: 256 bytes
//   0x083e5c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x083e60: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x083e64: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x083e68: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0393_0x083e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083e5cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x03df58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0394 | PC: 0x084328 | FDE: 0x03df88 | Size: 256 bytes
// Khung tháo gỡ #0394 | Địa chỉ PC: 0x084328 | Địa chỉ FDE: 0x03df88 | Kích thước: 256 bytes
//   0x084328: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08432c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x084330: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x084334: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0394_0x084328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084328ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x03df88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0395 | PC: 0x0844ec | FDE: 0x03dfb8 | Size: 256 bytes
// Khung tháo gỡ #0395 | Địa chỉ PC: 0x0844ec | Địa chỉ FDE: 0x03dfb8 | Kích thước: 256 bytes
//   0x0844ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0844f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0844f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0844f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0395_0x0844ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0844ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x03dfb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0396 | PC: 0x0847bc | FDE: 0x03dfe8 | Size: 256 bytes
// Khung tháo gỡ #0396 | Địa chỉ PC: 0x0847bc | Địa chỉ FDE: 0x03dfe8 | Kích thước: 256 bytes
//   0x0847bc: D102C3FF  sub      sp, sp, #0xb0
//   0x0847c0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0847c4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0847c8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0396_0x0847bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0847bcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03dfe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0397 | PC: 0x084a90 | FDE: 0x03e018 | Size: 256 bytes [_Z17JS_FreeRuntime_GCP12LEPUSRuntime]
// Khung tháo gỡ #0397 | Địa chỉ PC: 0x084a90 | Địa chỉ FDE: 0x03e018 | Kích thước: 256 bytes
//   0x084a90: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x084a94: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x084a98: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x084a9c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0397_0x084a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084a90ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0398 | PC: 0x084dec | FDE: 0x03e040 | Size: 256 bytes
// Khung tháo gỡ #0398 | Địa chỉ PC: 0x084dec | Địa chỉ FDE: 0x03e040 | Kích thước: 256 bytes
//   0x084dec: F9400409  ldr      x9, [x0, #8]
//   0x084df0: B4000709  cbz      x9, #0x84ed0
//   0x084df4: D285AD2C  mov      x12, #0x2d69
//   0x084df8: 531D702A  lsl      w10, w1, #3
static inline uint64_t fde_func_0398_0x084dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084decULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xb4000709ULL) ^ 0x03e040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0399 | PC: 0x084fe8 | FDE: 0x03e058 | Size: 256 bytes [_Z17JS_FreeContext_GCP12LEPUSContext]
// Khung tháo gỡ #0399 | Địa chỉ PC: 0x084fe8 | Địa chỉ FDE: 0x03e058 | Kích thước: 256 bytes
//   0x084fe8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x084fec: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x084ff0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x084ff4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0399_0x084fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084fe8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x03e058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0400 | PC: 0x085188 | FDE: 0x03e088 | Size: 256 bytes
// Khung tháo gỡ #0400 | Địa chỉ PC: 0x085188 | Địa chỉ FDE: 0x03e088 | Kích thước: 256 bytes
//   0x085188: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x08518c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x085190: AA0003F3  mov      x19, x0
//   0x085194: B4000421  cbz      x1, #0x85218
static inline uint64_t fde_func_0400_0x085188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085188ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03e088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0401 | PC: 0x085304 | FDE: 0x03e0a8 | Size: 256 bytes
// Khung tháo gỡ #0401 | Địa chỉ PC: 0x085304 | Địa chỉ FDE: 0x03e0a8 | Kích thước: 256 bytes
//   0x085304: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x085308: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x08530c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x085310: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0401_0x085304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085304ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03e0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0402 | PC: 0x085494 | FDE: 0x03e0d0 | Size: 256 bytes
// Khung tháo gỡ #0402 | Địa chỉ PC: 0x085494 | Địa chỉ FDE: 0x03e0d0 | Kích thước: 256 bytes
//   0x085494: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x085498: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08549c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0854a0: 900009D6  adrp     x22, #0x1bd000
static inline uint64_t fde_func_0402_0x085494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085494ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e0d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0403 | PC: 0x085614 | FDE: 0x03e0f0 | Size: 256 bytes
// Khung tháo gỡ #0403 | Địa chỉ PC: 0x085614 | Địa chỉ FDE: 0x03e0f0 | Kích thước: 256 bytes
//   0x085614: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x085618: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x08561c: AA0003F3  mov      x19, x0
//   0x085620: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0403_0x085614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085614ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03e0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0404 | PC: 0x085738 | FDE: 0x03e110 | Size: 256 bytes
// Khung tháo gỡ #0404 | Địa chỉ PC: 0x085738 | Địa chỉ FDE: 0x03e110 | Kích thước: 256 bytes
//   0x085738: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x08573c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x085740: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x085744: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0404_0x085738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085738ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0405 | PC: 0x0859e8 | FDE: 0x03e138 | Size: 256 bytes
// Khung tháo gỡ #0405 | Địa chỉ PC: 0x0859e8 | Địa chỉ FDE: 0x03e138 | Kích thước: 256 bytes
//   0x0859e8: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x0859ec: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0859f0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0859f4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0405_0x0859e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0859e8ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03e138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0406 | PC: 0x085d5c | FDE: 0x03e160 | Size: 256 bytes
// Khung tháo gỡ #0406 | Địa chỉ PC: 0x085d5c | Địa chỉ FDE: 0x03e160 | Kích thước: 256 bytes
//   0x085d5c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x085d60: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x085d64: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x085d68: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0406_0x085d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085d5cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0407 | PC: 0x085f18 | FDE: 0x03e188 | Size: 256 bytes
// Khung tháo gỡ #0407 | Địa chỉ PC: 0x085f18 | Địa chỉ FDE: 0x03e188 | Kích thước: 256 bytes
//   0x085f18: D10183FF  sub      sp, sp, #0x60
//   0x085f1c: F90013F8  str      x24, [sp, #0x20]
//   0x085f20: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x085f24: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0407_0x085f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085f18ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x03e188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0408 | PC: 0x086590 | FDE: 0x03e1b0 | Size: 256 bytes
// Khung tháo gỡ #0408 | Địa chỉ PC: 0x086590 | Địa chỉ FDE: 0x03e1b0 | Kích thước: 256 bytes
//   0x086590: D101C3FF  sub      sp, sp, #0x70
//   0x086594: F9000BFC  str      x28, [sp, #0x10]
//   0x086598: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x08659c: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_0408_0x086590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086590ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x03e1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0409 | PC: 0x0867e4 | FDE: 0x03e1e0 | Size: 256 bytes
// Khung tháo gỡ #0409 | Địa chỉ PC: 0x0867e4 | Địa chỉ FDE: 0x03e1e0 | Kích thước: 256 bytes
//   0x0867e4: D10143FF  sub      sp, sp, #0x50
//   0x0867e8: F9000BF8  str      x24, [sp, #0x10]
//   0x0867ec: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0867f0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0409_0x0867e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0867e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x03e1e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0410 | PC: 0x086910 | FDE: 0x03e208 | Size: 232 bytes [_Z15JS_NewObject_GCP12LEPUSContext]
// Khung tháo gỡ #0410 | Địa chỉ PC: 0x086910 | Địa chỉ FDE: 0x03e208 | Kích thước: 232 bytes
//   0x086910: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x086914: F9401C08  ldr      x8, [x0, #0x38]
//   0x086918: D2800049  mov      x9, #2
//   0x08691c: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_0410_0x086910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086910ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9401c08ULL) ^ 0x03e208ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0411 | PC: 0x0869f8 | FDE: 0x03e220 | Size: 256 bytes [_Z20JS_DefineProperty_GCP12LEPUSContext10LEPUSValuejS1_S1_S1_i]
// Khung tháo gỡ #0411 | Địa chỉ PC: 0x0869f8 | Địa chỉ FDE: 0x03e220 | Kích thước: 256 bytes
//   0x0869f8: D10303FF  sub      sp, sp, #0xc0
//   0x0869fc: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x086a00: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x086a04: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0411_0x0869f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0869f8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x03e220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0412 | PC: 0x087a60 | FDE: 0x03e250 | Size: 256 bytes
// Khung tháo gỡ #0412 | Địa chỉ PC: 0x087a60 | Địa chỉ FDE: 0x03e250 | Kích thước: 256 bytes
//   0x087a60: D100C3FF  sub      sp, sp, #0x30
//   0x087a64: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x087a68: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x087a6c: AA0203F5  mov      x21, x2
static inline uint64_t fde_func_0412_0x087a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087a60ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0413 | PC: 0x087c10 | FDE: 0x03e270 | Size: 256 bytes
// Khung tháo gỡ #0413 | Địa chỉ PC: 0x087c10 | Địa chỉ FDE: 0x03e270 | Kích thước: 256 bytes
//   0x087c10: D101C3FF  sub      sp, sp, #0x70
//   0x087c14: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x087c18: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x087c1c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0413_0x087c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087c10ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x03e270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0414 | PC: 0x088038 | FDE: 0x03e298 | Size: 256 bytes
// Khung tháo gỡ #0414 | Địa chỉ PC: 0x088038 | Địa chỉ FDE: 0x03e298 | Kích thước: 256 bytes
//   0x088038: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x08803c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x088040: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x088044: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0414_0x088038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088038ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0415 | PC: 0x08821c | FDE: 0x03e2c0 | Size: 256 bytes
// Khung tháo gỡ #0415 | Địa chỉ PC: 0x08821c | Địa chỉ FDE: 0x03e2c0 | Kích thước: 256 bytes
//   0x08821c: D10183FF  sub      sp, sp, #0x60
//   0x088220: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x088224: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x088228: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0415_0x08821c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08821cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03e2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0416 | PC: 0x08874c | FDE: 0x03e2e8 | Size: 256 bytes
// Khung tháo gỡ #0416 | Địa chỉ PC: 0x08874c | Địa chỉ FDE: 0x03e2e8 | Kích thước: 256 bytes
//   0x08874c: D102C3FF  sub      sp, sp, #0xb0
//   0x088750: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x088754: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x088758: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0416_0x08874c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08874cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03e2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0417 | PC: 0x088c90 | FDE: 0x03e318 | Size: 256 bytes
// Khung tháo gỡ #0417 | Địa chỉ PC: 0x088c90 | Địa chỉ FDE: 0x03e318 | Kích thước: 256 bytes
//   0x088c90: D10283FF  sub      sp, sp, #0xa0
//   0x088c94: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x088c98: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x088c9c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0417_0x088c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088c90ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x03e318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0418 | PC: 0x088e40 | FDE: 0x03e348 | Size: 256 bytes
// Khung tháo gỡ #0418 | Địa chỉ PC: 0x088e40 | Địa chỉ FDE: 0x03e348 | Kích thước: 256 bytes
//   0x088e40: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x088e44: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x088e48: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x088e4c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0418_0x088e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088e40ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03e348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0419 | PC: 0x088fb0 | FDE: 0x03e370 | Size: 256 bytes
// Khung tháo gỡ #0419 | Địa chỉ PC: 0x088fb0 | Địa chỉ FDE: 0x03e370 | Kích thước: 256 bytes
//   0x088fb0: D102C3FF  sub      sp, sp, #0xb0
//   0x088fb4: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x088fb8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x088fbc: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0419_0x088fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088fb0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03e370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0420 | PC: 0x0897f0 | FDE: 0x03e3a0 | Size: 256 bytes
// Khung tháo gỡ #0420 | Địa chỉ PC: 0x0897f0 | Địa chỉ FDE: 0x03e3a0 | Kích thước: 256 bytes
//   0x0897f0: D101C3FF  sub      sp, sp, #0x70
//   0x0897f4: F90013FA  str      x26, [sp, #0x20]
//   0x0897f8: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0897fc: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0420_0x0897f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0897f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x03e3a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0421 | PC: 0x0899a4 | FDE: 0x03e3c8 | Size: 256 bytes [_Z19JS_NewAtomUInt32_GCP12LEPUSContextj]
// Khung tháo gỡ #0421 | Địa chỉ PC: 0x0899a4 | Địa chỉ FDE: 0x03e3c8 | Kích thước: 256 bytes
//   0x0899a4: D10143FF  sub      sp, sp, #0x50
//   0x0899a8: F90013F6  str      x22, [sp, #0x20]
//   0x0899ac: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0899b0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0421_0x0899a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0899a4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x03e3c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0422 | PC: 0x089ac8 | FDE: 0x03e3e8 | Size: 256 bytes
// Khung tháo gỡ #0422 | Địa chỉ PC: 0x089ac8 | Địa chỉ FDE: 0x03e3e8 | Kích thước: 256 bytes
//   0x089ac8: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x089acc: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x089ad0: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x089ad4: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0422_0x089ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089ac8ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03e3e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0423 | PC: 0x089e84 | FDE: 0x03e418 | Size: 104 bytes
// Khung tháo gỡ #0423 | Địa chỉ PC: 0x089e84 | Địa chỉ FDE: 0x03e418 | Kích thước: 104 bytes
//   0x089e84: 900009A8  adrp     x8, #0x1bd000
//   0x089e88: F940D908  ldr      x8, [x8, #0x1b0]
//   0x089e8c: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x089e90: 2A0203EA  mov      w10, w2
static inline uint64_t fde_func_0423_0x089e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089e84ULL ^ (static_cast<uint64_t>(0x900009a8ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x03e418ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0424 | PC: 0x089eec | FDE: 0x03e430 | Size: 256 bytes
// Khung tháo gỡ #0424 | Địa chỉ PC: 0x089eec | Địa chỉ FDE: 0x03e430 | Kích thước: 256 bytes
//   0x089eec: D10103FF  sub      sp, sp, #0x40
//   0x089ef0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x089ef4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x089ef8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0424_0x089eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089eecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0425 | PC: 0x08a0cc | FDE: 0x03e450 | Size: 256 bytes
// Khung tháo gỡ #0425 | Địa chỉ PC: 0x08a0cc | Địa chỉ FDE: 0x03e450 | Kích thước: 256 bytes
//   0x08a0cc: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x08a0d0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08a0d4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08a0d8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0425_0x08a0cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a0ccULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0426 | PC: 0x08a240 | FDE: 0x03e478 | Size: 104 bytes
// Khung tháo gỡ #0426 | Địa chỉ PC: 0x08a240 | Địa chỉ FDE: 0x03e478 | Kích thước: 104 bytes
//   0x08a240: 37F80062  tbnz     w2, #0x1f, #0x8a24c
//   0x08a244: 52800020  mov      w0, #1
//   0x08a248: D65F03C0  ret      
//   0x08a24c: F0000988  adrp     x8, #0x1bd000
static inline uint64_t fde_func_0426_0x08a240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a240ULL ^ (static_cast<uint64_t>(0x37f80062ULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x03e478ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0427 | PC: 0x08a2a8 | FDE: 0x03e490 | Size: 256 bytes
// Khung tháo gỡ #0427 | Địa chỉ PC: 0x08a2a8 | Địa chỉ FDE: 0x03e490 | Kích thước: 256 bytes
//   0x08a2a8: D101C3FF  sub      sp, sp, #0x70
//   0x08a2ac: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x08a2b0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x08a2b4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0427_0x08a2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a2a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03e490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0428 | PC: 0x08a518 | FDE: 0x03e4c0 | Size: 256 bytes
// Khung tháo gỡ #0428 | Địa chỉ PC: 0x08a518 | Địa chỉ FDE: 0x03e4c0 | Kích thước: 256 bytes
//   0x08a518: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x08a51c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08a520: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08a524: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0428_0x08a518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a518ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0429 | PC: 0x08a684 | FDE: 0x03e4e8 | Size: 60 bytes [_Z19add_footprint_limitP12malloc_statem]
// Khung tháo gỡ #0429 | Địa chỉ PC: 0x08a684 | Địa chỉ FDE: 0x03e4e8 | Kích thước: 60 bytes
//   0x08a684: F940AC08  ldr      x8, [x0, #0x158]
//   0x08a688: F940700A  ldr      x10, [x0, #0xe0]
//   0x08a68c: 12B00009  mov      w9, #0x7fffffff
//   0x08a690: F9418D08  ldr      x8, [x8, #0x318]
static inline uint64_t fde_func_0429_0x08a684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a684ULL ^ (static_cast<uint64_t>(0xf940ac08ULL) << 13);
    acc = (acc + a1 + 0xf940700aULL) ^ 0x03e4e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0430 | PC: 0x08a6c0 | FDE: 0x03e500 | Size: 28 bytes [_ZN16GarbageCollector11GetMaxLimitEv]
// Khung tháo gỡ #0430 | Địa chỉ PC: 0x08a6c0 | Địa chỉ FDE: 0x03e500 | Kích thước: 28 bytes
//   0x08a6c0: F9401808  ldr      x8, [x0, #0x30]
//   0x08a6c4: 12B00009  mov      w9, #0x7fffffff
//   0x08a6c8: D100050A  sub      x10, x8, #1
//   0x08a6cc: EB09015F  cmp      x10, x9
static inline uint64_t fde_func_0430_0x08a6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a6c0ULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0x12b00009ULL) ^ 0x03e500ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0431 | PC: 0x08a6dc | FDE: 0x03e518 | Size: 256 bytes [_Z16switch_local_idxP12malloc_statem]
// Khung tháo gỡ #0431 | Địa chỉ PC: 0x08a6dc | Địa chỉ FDE: 0x03e518 | Kích thước: 256 bytes
//   0x08a6dc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x08a6e0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x08a6e4: B9416808  ldr      w8, [x0, #0x168]
//   0x08a6e8: 9E630020  ucvtf    d0, x1
static inline uint64_t fde_func_0431_0x08a6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a6dcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03e518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0432 | PC: 0x08a8d4 | FDE: 0x03e538 | Size: 252 bytes [_Z7trig_gcP13JSMallocStatemb]
// Khung tháo gỡ #0432 | Địa chỉ PC: 0x08a8d4 | Địa chỉ FDE: 0x03e538 | Kích thước: 252 bytes
//   0x08a8d4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x08a8d8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08a8dc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08a8e0: F940B816  ldr      x22, [x0, #0x170]
static inline uint64_t fde_func_0432_0x08a8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a8d4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e538ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0433 | PC: 0x08a9d0 | FDE: 0x03e558 | Size: 256 bytes [_ZN16GarbageCollector14CollectGarbageEmb]
// Khung tháo gỡ #0433 | Địa chỉ PC: 0x08a9d0 | Địa chỉ FDE: 0x03e558 | Kích thước: 256 bytes
//   0x08a9d0: D101C3FF  sub      sp, sp, #0x70
//   0x08a9d4: F9000BFC  str      x28, [sp, #0x10]
//   0x08a9d8: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x08a9dc: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_0433_0x08a9d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a9d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x03e558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0434 | PC: 0x08ac94 | FDE: 0x03e588 | Size: 52 bytes
// Khung tháo gỡ #0434 | Địa chỉ PC: 0x08ac94 | Địa chỉ FDE: 0x03e588 | Kích thước: 52 bytes
//   0x08ac94: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08ac98: AA0003F3  mov      x19, x0
//   0x08ac9c: 94000595  bl       #0x8c2f0
//   0x08aca0: F940BA68  ldr      x8, [x19, #0x170]
static inline uint64_t fde_func_0434_0x08ac94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ac94ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03e588ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0435 | PC: 0x08acc8 | FDE: 0x03e5a0 | Size: 52 bytes
// Khung tháo gỡ #0435 | Địa chỉ PC: 0x08acc8 | Địa chỉ FDE: 0x03e5a0 | Kích thước: 52 bytes
//   0x08acc8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08accc: AA0003F3  mov      x19, x0
//   0x08acd0: 94000491  bl       #0x8bf14
//   0x08acd4: F940BA68  ldr      x8, [x19, #0x170]
static inline uint64_t fde_func_0435_0x08acc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08acc8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03e5a0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0436 | PC: 0x08acfc | FDE: 0x03e5b8 | Size: 256 bytes [_ZN7Visitor9ScanRootsEv]
// Khung tháo gỡ #0436 | Địa chỉ PC: 0x08acfc | Địa chỉ FDE: 0x03e5b8 | Kích thước: 256 bytes
//   0x08acfc: D10243FF  sub      sp, sp, #0x90
//   0x08ad00: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x08ad04: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x08ad08: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0436_0x08acfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08acfcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x03e5b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0437 | PC: 0x08afdc | FDE: 0x03e5e8 | Size: 208 bytes [_ZN7Visitor16VisitRootHeapObjEPvi]
// Khung tháo gỡ #0437 | Địa chỉ PC: 0x08afdc | Địa chỉ FDE: 0x03e5e8 | Kích thước: 208 bytes
//   0x08afdc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x08afe0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08afe4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08afe8: B40005A1  cbz      x1, #0x8b09c
static inline uint64_t fde_func_0437_0x08afdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08afdcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e5e8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0438 | PC: 0x08b0ac | FDE: 0x03e608 | Size: 256 bytes [_ZN16GarbageCollector20UpdateFootprintLimitEm]
// Khung tháo gỡ #0438 | Địa chỉ PC: 0x08b0ac | Địa chỉ FDE: 0x03e608 | Kích thước: 256 bytes
//   0x08b0ac: F9400408  ldr      x8, [x0, #8]
//   0x08b0b0: 394CC509  ldrb     w9, [x8, #0x331]
//   0x08b0b4: 340000A9  cbz      w9, #0x8b0c8
//   0x08b0b8: D0000989  adrp     x9, #0x1bd000
static inline uint64_t fde_func_0438_0x08b0ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b0acULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x394cc509ULL) ^ 0x03e608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0439 | PC: 0x08b24c | FDE: 0x03e620 | Size: 4 bytes
// Khung tháo gỡ #0439 | Địa chỉ PC: 0x08b24c | Địa chỉ FDE: 0x03e620 | Kích thước: 4 bytes
//   0x08b24c: 14000429  b        #0x8c2f0
static inline uint64_t fde_func_0439_0x08b24c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b24cULL ^ (static_cast<uint64_t>(0x14000429ULL) << 13);
    acc = (acc + a1 + 0x14000331ULL) ^ 0x03e620ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0440 | PC: 0x08b250 | FDE: 0x03e638 | Size: 4 bytes
// Khung tháo gỡ #0440 | Địa chỉ PC: 0x08b250 | Địa chỉ FDE: 0x03e638 | Kích thước: 4 bytes
//   0x08b250: 14000331  b        #0x8bf14
static inline uint64_t fde_func_0440_0x08b250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b250ULL ^ (static_cast<uint64_t>(0x14000331ULL) << 13);
    acc = (acc + a1 + 0xd102c3ffULL) ^ 0x03e638ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0441 | PC: 0x08b254 | FDE: 0x03e650 | Size: 256 bytes [_ZN16GarbageCollector12UpdateGCInfoEml]
// Khung tháo gỡ #0441 | Địa chỉ PC: 0x08b254 | Địa chỉ FDE: 0x03e650 | Kích thước: 256 bytes
//   0x08b254: D102C3FF  sub      sp, sp, #0xb0
//   0x08b258: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x08b25c: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x08b260: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0441_0x08b254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b254ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9066bfbULL) ^ 0x03e650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0442 | PC: 0x08b7d8 | FDE: 0x03e680 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl]
// Khung tháo gỡ #0442 | Địa chỉ PC: 0x08b7d8 | Địa chỉ FDE: 0x03e680 | Kích thước: 256 bytes
//   0x08b7d8: D10143FF  sub      sp, sp, #0x50
//   0x08b7dc: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x08b7e0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x08b7e4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0442_0x08b7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b7d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03e680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0443 | PC: 0x08b980 | FDE: 0x03e6a8 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv]
// Khung tháo gỡ #0443 | Địa chỉ PC: 0x08b980 | Địa chỉ FDE: 0x03e6a8 | Kích thước: 256 bytes
//   0x08b980: D10143FF  sub      sp, sp, #0x50
//   0x08b984: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x08b988: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x08b98c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0443_0x08b980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b980ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03e6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0444 | PC: 0x08bb28 | FDE: 0x03e6d0 | Size: 256 bytes
// Khung tháo gỡ #0444 | Địa chỉ PC: 0x08bb28 | Địa chỉ FDE: 0x03e6d0 | Kích thước: 256 bytes
//   0x08bb28: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x08bb2c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08bb30: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08bb34: B9406028  ldr      w8, [x1, #0x60]
static inline uint64_t fde_func_0444_0x08bb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bb28ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0445 | PC: 0x08bd28 | FDE: 0x03e6f0 | Size: 188 bytes
// Khung tháo gỡ #0445 | Địa chỉ PC: 0x08bd28 | Địa chỉ FDE: 0x03e6f0 | Kích thước: 188 bytes
//   0x08bd28: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x08bd2c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x08bd30: 39400008  ldrb     w8, [x0]
//   0x08bd34: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0445_0x08bd28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bd28ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03e6f0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0446 | PC: 0x08bde4 | FDE: 0x03e710 | Size: 256 bytes
// Khung tháo gỡ #0446 | Địa chỉ PC: 0x08bde4 | Địa chỉ FDE: 0x03e710 | Kích thước: 256 bytes
//   0x08bde4: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x08bde8: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x08bdec: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x08bdf0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0446_0x08bde4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bde4ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03e710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0447 | PC: 0x08bf14 | FDE: 0x03e740 | Size: 256 bytes
// Khung tháo gỡ #0447 | Địa chỉ PC: 0x08bf14 | Địa chỉ FDE: 0x03e740 | Kích thước: 256 bytes
//   0x08bf14: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x08bf18: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08bf1c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08bf20: AA0103F7  mov      x23, x1
static inline uint64_t fde_func_0447_0x08bf14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bf14ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0448 | PC: 0x08c05c | FDE: 0x03e760 | Size: 256 bytes [_Z15JS_UpdateGCInfoP13JSMallocStatem]
// Khung tháo gỡ #0448 | Địa chỉ PC: 0x08c05c | Địa chỉ FDE: 0x03e760 | Kích thước: 256 bytes
//   0x08c05c: D10703FF  sub      sp, sp, #0x1c0
//   0x08c060: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x08c064: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x08c068: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0448_0x08c05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c05cULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x03e760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0449 | PC: 0x08c2f0 | FDE: 0x03e790 | Size: 176 bytes
// Khung tháo gỡ #0449 | Địa chỉ PC: 0x08c2f0 | Địa chỉ FDE: 0x03e790 | Kích thước: 176 bytes
//   0x08c2f0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x08c2f4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08c2f8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08c2fc: 2A0203F6  mov      w22, w2
static inline uint64_t fde_func_0449_0x08c2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c2f0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03e790ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0450 | PC: 0x08c3a0 | FDE: 0x03e7b0 | Size: 44 bytes
// Khung tháo gỡ #0450 | Địa chỉ PC: 0x08c3a0 | Địa chỉ FDE: 0x03e7b0 | Kích thước: 44 bytes
//   0x08c3a0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08c3a4: AA0003F3  mov      x19, x0
//   0x08c3a8: 52800200  mov      w0, #0x10
//   0x08c3ac: 940491A9  bl       #0x1b0a50
static inline uint64_t fde_func_0450_0x08c3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c3a0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03e7b0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0451 | PC: 0x08c3cc | FDE: 0x03e7c8 | Size: 24 bytes
// Khung tháo gỡ #0451 | Địa chỉ PC: 0x08c3cc | Địa chỉ FDE: 0x03e7c8 | Kích thước: 24 bytes
//   0x08c3cc: 90000948  adrp     x8, #0x1b4000
//   0x08c3d0: 911BC108  add      x8, x8, #0x6f0
//   0x08c3d4: F9000028  str      x8, [x1]
//   0x08c3d8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0451_0x08c3cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c3ccULL ^ (static_cast<uint64_t>(0x90000948ULL) << 13);
    acc = (acc + a1 + 0x911bc108ULL) ^ 0x03e7c8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0452 | PC: 0x08c3e4 | FDE: 0x03e7e0 | Size: 8 bytes
// Khung tháo gỡ #0452 | Địa chỉ PC: 0x08c3e4 | Địa chỉ FDE: 0x03e7e0 | Kích thước: 8 bytes
//   0x08c3e4: F9400400  ldr      x0, [x0, #8]
//   0x08c3e8: 1400000B  b        #0x8c414
static inline uint64_t fde_func_0452_0x08c3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c3e4ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x1400000bULL) ^ 0x03e7e0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0453 | PC: 0x08c3ec | FDE: 0x03e7f8 | Size: 28 bytes
// Khung tháo gỡ #0453 | Địa chỉ PC: 0x08c3ec | Địa chỉ FDE: 0x03e7f8 | Kích thước: 28 bytes
//   0x08c3ec: F9400428  ldr      x8, [x1, #8]
//   0x08c3f0: D0FFFD49  adrp     x9, #0x36000
//   0x08c3f4: 91070129  add      x9, x9, #0x1c0
//   0x08c3f8: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0453_0x08c3ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c3ecULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0fffd49ULL) ^ 0x03e7f8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0454 | PC: 0x08c408 | FDE: 0x03e810 | Size: 12 bytes
// Khung tháo gỡ #0454 | Địa chỉ PC: 0x08c408 | Địa chỉ FDE: 0x03e810 | Kích thước: 12 bytes
//   0x08c408: 90000940  adrp     x0, #0x1b4000
//   0x08c40c: 911D4000  add      x0, x0, #0x750
//   0x08c410: D65F03C0  ret      
static inline uint64_t fde_func_0454_0x08c408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c408ULL ^ (static_cast<uint64_t>(0x90000940ULL) << 13);
    acc = (acc + a1 + 0x911d4000ULL) ^ 0x03e810ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0455 | PC: 0x08c414 | FDE: 0x03e828 | Size: 256 bytes [_ZN7Visitor11ScanRuntimeEv]
// Khung tháo gỡ #0455 | Địa chỉ PC: 0x08c414 | Địa chỉ FDE: 0x03e828 | Kích thước: 256 bytes
//   0x08c414: D10183FF  sub      sp, sp, #0x60
//   0x08c418: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x08c41c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x08c420: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0455_0x08c414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c414ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03e828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0456 | PC: 0x08c844 | FDE: 0x03e850 | Size: 256 bytes [_ZN7Visitor19VisitRootLEPUSValueER10LEPUSValuei]
// Khung tháo gỡ #0456 | Địa chỉ PC: 0x08c844 | Địa chỉ FDE: 0x03e850 | Kích thước: 256 bytes
//   0x08c844: F9400028  ldr      x8, [x1]
//   0x08c848: D371FD09  lsr      x9, x8, #0x31
//   0x08c84c: B6800048  tbz      x8, #0x30, #0x8c854
//   0x08c850: B4000109  cbz      x9, #0x8c870
static inline uint64_t fde_func_0456_0x08c844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c844ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xd371fd09ULL) ^ 0x03e850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0457 | PC: 0x08c958 | FDE: 0x03e868 | Size: 44 bytes
// Khung tháo gỡ #0457 | Địa chỉ PC: 0x08c958 | Địa chỉ FDE: 0x03e868 | Kích thước: 44 bytes
//   0x08c958: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08c95c: AA0003F3  mov      x19, x0
//   0x08c960: 52800300  mov      w0, #0x18
//   0x08c964: 9404903B  bl       #0x1b0a50
static inline uint64_t fde_func_0457_0x08c958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c958ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03e868ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0458 | PC: 0x08c984 | FDE: 0x03e880 | Size: 24 bytes
// Khung tháo gỡ #0458 | Địa chỉ PC: 0x08c984 | Địa chỉ FDE: 0x03e880 | Kích thước: 24 bytes
//   0x08c984: 90000948  adrp     x8, #0x1b4000
//   0x08c988: 911A6108  add      x8, x8, #0x698
//   0x08c98c: F9000028  str      x8, [x1]
//   0x08c990: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0458_0x08c984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c984ULL ^ (static_cast<uint64_t>(0x90000948ULL) << 13);
    acc = (acc + a1 + 0x911a6108ULL) ^ 0x03e880ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0459 | PC: 0x08c99c | FDE: 0x03e898 | Size: 12 bytes
// Khung tháo gỡ #0459 | Địa chỉ PC: 0x08c99c | Địa chỉ FDE: 0x03e898 | Kích thước: 12 bytes
//   0x08c99c: A9408408  ldp      x8, x1, [x0, #8]
//   0x08c9a0: AA0803E0  mov      x0, x8
//   0x08c9a4: 1400000B  b        #0x8c9d0
static inline uint64_t fde_func_0459_0x08c99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c99cULL ^ (static_cast<uint64_t>(0xa9408408ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x03e898ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0460 | PC: 0x08c9a8 | FDE: 0x03e8b0 | Size: 28 bytes
// Khung tháo gỡ #0460 | Địa chỉ PC: 0x08c9a8 | Địa chỉ FDE: 0x03e8b0 | Kích thước: 28 bytes
//   0x08c9a8: F9400428  ldr      x8, [x1, #8]
//   0x08c9ac: D0FFFD49  adrp     x9, #0x36000
//   0x08c9b0: 9108BD29  add      x9, x9, #0x22f
//   0x08c9b4: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0460_0x08c9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c9a8ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0fffd49ULL) ^ 0x03e8b0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0461 | PC: 0x08c9c4 | FDE: 0x03e8c8 | Size: 12 bytes
// Khung tháo gỡ #0461 | Địa chỉ PC: 0x08c9c4 | Địa chỉ FDE: 0x03e8c8 | Kích thước: 12 bytes
//   0x08c9c4: 90000940  adrp     x0, #0x1b4000
//   0x08c9c8: 911DE000  add      x0, x0, #0x778
//   0x08c9cc: D65F03C0  ret      
static inline uint64_t fde_func_0461_0x08c9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c9c4ULL ^ (static_cast<uint64_t>(0x90000940ULL) << 13);
    acc = (acc + a1 + 0x911de000ULL) ^ 0x03e8c8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0462 | PC: 0x08c9d0 | FDE: 0x03e8e0 | Size: 256 bytes [_ZN7Visitor11ScanContextEP12LEPUSContext]
// Khung tháo gỡ #0462 | Địa chỉ PC: 0x08c9d0 | Địa chỉ FDE: 0x03e8e0 | Kích thước: 256 bytes
//   0x08c9d0: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x08c9d4: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x08c9d8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x08c9dc: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0462_0x08c9d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c9d0ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03e8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0463 | PC: 0x08ccd4 | FDE: 0x03e908 | Size: 256 bytes [_ZN7Visitor17PushObjLEPUSValueER10LEPUSValuei]
// Khung tháo gỡ #0463 | Địa chỉ PC: 0x08ccd4 | Địa chỉ FDE: 0x03e908 | Kích thước: 256 bytes
//   0x08ccd4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x08ccd8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x08ccdc: F9400028  ldr      x8, [x1]
//   0x08cce0: D371FD09  lsr      x9, x8, #0x31
static inline uint64_t fde_func_0463_0x08ccd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ccd4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03e908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0464 | PC: 0x08ce04 | FDE: 0x03e928 | Size: 44 bytes
// Khung tháo gỡ #0464 | Địa chỉ PC: 0x08ce04 | Địa chỉ FDE: 0x03e928 | Kích thước: 44 bytes
//   0x08ce04: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08ce08: AA0003F3  mov      x19, x0
//   0x08ce0c: 52800200  mov      w0, #0x10
//   0x08ce10: 94048F10  bl       #0x1b0a50
static inline uint64_t fde_func_0464_0x08ce04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce04ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03e928ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0465 | PC: 0x08ce30 | FDE: 0x03e940 | Size: 24 bytes
// Khung tháo gỡ #0465 | Địa chỉ PC: 0x08ce30 | Địa chỉ FDE: 0x03e940 | Kích thước: 24 bytes
//   0x08ce30: 90000948  adrp     x8, #0x1b4000
//   0x08ce34: 91190108  add      x8, x8, #0x640
//   0x08ce38: F9000028  str      x8, [x1]
//   0x08ce3c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0465_0x08ce30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce30ULL ^ (static_cast<uint64_t>(0x90000948ULL) << 13);
    acc = (acc + a1 + 0x91190108ULL) ^ 0x03e940ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0466 | PC: 0x08ce48 | FDE: 0x03e958 | Size: 8 bytes
// Khung tháo gỡ #0466 | Địa chỉ PC: 0x08ce48 | Địa chỉ FDE: 0x03e958 | Kích thước: 8 bytes
//   0x08ce48: F9400400  ldr      x0, [x0, #8]
//   0x08ce4c: 1400000B  b        #0x8ce78
static inline uint64_t fde_func_0466_0x08ce48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce48ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x1400000bULL) ^ 0x03e958ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0467 | PC: 0x08ce50 | FDE: 0x03e970 | Size: 28 bytes
// Khung tháo gỡ #0467 | Địa chỉ PC: 0x08ce50 | Địa chỉ FDE: 0x03e970 | Kích thước: 28 bytes
//   0x08ce50: F9400428  ldr      x8, [x1, #8]
//   0x08ce54: D0FFFD49  adrp     x9, #0x36000
//   0x08ce58: 910A7929  add      x9, x9, #0x29e
//   0x08ce5c: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0467_0x08ce50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce50ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0fffd49ULL) ^ 0x03e970ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0468 | PC: 0x08ce6c | FDE: 0x03e988 | Size: 12 bytes
// Khung tháo gỡ #0468 | Địa chỉ PC: 0x08ce6c | Địa chỉ FDE: 0x03e988 | Kích thước: 12 bytes
//   0x08ce6c: 90000940  adrp     x0, #0x1b4000
//   0x08ce70: 911E8000  add      x0, x0, #0x7a0
//   0x08ce74: D65F03C0  ret      
static inline uint64_t fde_func_0468_0x08ce6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce6cULL ^ (static_cast<uint64_t>(0x90000940ULL) << 13);
    acc = (acc + a1 + 0x911e8000ULL) ^ 0x03e988ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0469 | PC: 0x08ce78 | FDE: 0x03e9a0 | Size: 256 bytes [_ZN7Visitor11ScanHandlesEv]
// Khung tháo gỡ #0469 | Địa chỉ PC: 0x08ce78 | Địa chỉ FDE: 0x03e9a0 | Kích thước: 256 bytes
//   0x08ce78: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x08ce7c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08ce80: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08ce84: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0469_0x08ce78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce78ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0470 | PC: 0x08cf78 | FDE: 0x03e9c8 | Size: 256 bytes [_ZN7Visitor9VisitRootEPv10HandleTypei]
// Khung tháo gỡ #0470 | Địa chỉ PC: 0x08cf78 | Địa chỉ FDE: 0x03e9c8 | Kích thước: 256 bytes
//   0x08cf78: D10103FF  sub      sp, sp, #0x40
//   0x08cf7c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08cf80: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08cf84: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0470_0x08cf78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cf78ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03e9c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0471 | PC: 0x08d100 | FDE: 0x03e9e8 | Size: 44 bytes
// Khung tháo gỡ #0471 | Địa chỉ PC: 0x08d100 | Địa chỉ FDE: 0x03e9e8 | Kích thước: 44 bytes
//   0x08d100: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08d104: AA0003F3  mov      x19, x0
//   0x08d108: 52800200  mov      w0, #0x10
//   0x08d10c: 94048E51  bl       #0x1b0a50
static inline uint64_t fde_func_0471_0x08d100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d100ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03e9e8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0472 | PC: 0x08d12c | FDE: 0x03ea00 | Size: 24 bytes
// Khung tháo gỡ #0472 | Địa chỉ PC: 0x08d12c | Địa chỉ FDE: 0x03ea00 | Kích thước: 24 bytes
//   0x08d12c: F0000928  adrp     x8, #0x1b4000
//   0x08d130: 9117A108  add      x8, x8, #0x5e8
//   0x08d134: F9000028  str      x8, [x1]
//   0x08d138: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0472_0x08d12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d12cULL ^ (static_cast<uint64_t>(0xf0000928ULL) << 13);
    acc = (acc + a1 + 0x9117a108ULL) ^ 0x03ea00ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0473 | PC: 0x08d144 | FDE: 0x03ea18 | Size: 8 bytes
// Khung tháo gỡ #0473 | Địa chỉ PC: 0x08d144 | Địa chỉ FDE: 0x03ea18 | Kích thước: 8 bytes
//   0x08d144: F9400400  ldr      x0, [x0, #8]
//   0x08d148: 1400000B  b        #0x8d174
static inline uint64_t fde_func_0473_0x08d144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d144ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x1400000bULL) ^ 0x03ea18ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0474 | PC: 0x08d14c | FDE: 0x03ea30 | Size: 28 bytes
// Khung tháo gỡ #0474 | Địa chỉ PC: 0x08d14c | Địa chỉ FDE: 0x03ea30 | Kích thước: 28 bytes
//   0x08d14c: F9400428  ldr      x8, [x1, #8]
//   0x08d150: B0FFFD49  adrp     x9, #0x36000
//   0x08d154: 910C3529  add      x9, x9, #0x30d
//   0x08d158: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0474_0x08d14c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d14cULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0fffd49ULL) ^ 0x03ea30ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0475 | PC: 0x08d168 | FDE: 0x03ea48 | Size: 12 bytes
// Khung tháo gỡ #0475 | Địa chỉ PC: 0x08d168 | Địa chỉ FDE: 0x03ea48 | Kích thước: 12 bytes
//   0x08d168: F0000920  adrp     x0, #0x1b4000
//   0x08d16c: 911F2000  add      x0, x0, #0x7c8
//   0x08d170: D65F03C0  ret      
static inline uint64_t fde_func_0475_0x08d168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d168ULL ^ (static_cast<uint64_t>(0xf0000920ULL) << 13);
    acc = (acc + a1 + 0x911f2000ULL) ^ 0x03ea48ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0476 | PC: 0x08d174 | FDE: 0x03ea60 | Size: 256 bytes [_ZN7Visitor9ScanStackEv]
// Khung tháo gỡ #0476 | Địa chỉ PC: 0x08d174 | Địa chỉ FDE: 0x03ea60 | Kích thước: 256 bytes
//   0x08d174: D10143FF  sub      sp, sp, #0x50
//   0x08d178: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x08d17c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x08d180: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0476_0x08d174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d174ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03ea60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0477 | PC: 0x08d35c | FDE: 0x03ea88 | Size: 156 bytes
// Khung tháo gỡ #0477 | Địa chỉ PC: 0x08d35c | Địa chỉ FDE: 0x03ea88 | Kích thước: 156 bytes
//   0x08d35c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x08d360: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x08d364: AA0003F3  mov      x19, x0
//   0x08d368: F9401000  ldr      x0, [x0, #0x20]
static inline uint64_t fde_func_0477_0x08d35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d35cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03ea88ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0478 | PC: 0x08d3f8 | FDE: 0x03eaa8 | Size: 24 bytes [_Z16JS_NewRuntime_GCj]
// Khung tháo gỡ #0478 | Địa chỉ PC: 0x08d3f8 | Địa chỉ FDE: 0x03eaa8 | Kích thước: 24 bytes
//   0x08d3f8: F0000928  adrp     x8, #0x1b4000
//   0x08d3fc: 911F6108  add      x8, x8, #0x7d8
//   0x08d400: 2A0003E2  mov      w2, w0
//   0x08d404: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0478_0x08d3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d3f8ULL ^ (static_cast<uint64_t>(0xf0000928ULL) << 13);
    acc = (acc + a1 + 0x911f6108ULL) ^ 0x03eaa8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0479 | PC: 0x08d410 | FDE: 0x03eac0 | Size: 60 bytes
// Khung tháo gỡ #0479 | Địa chỉ PC: 0x08d410 | Địa chỉ FDE: 0x03eac0 | Kích thước: 60 bytes
//   0x08d410: B40001C1  cbz      x1, #0x8d448
//   0x08d414: A9402408  ldp      x8, x9, [x0]
//   0x08d418: 5280020A  mov      w10, #0x10
//   0x08d41c: D1000508  sub      x8, x8, #1
static inline uint64_t fde_func_0479_0x08d410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d410ULL ^ (static_cast<uint64_t>(0xb40001c1ULL) << 13);
    acc = (acc + a1 + 0xa9402408ULL) ^ 0x03eac0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0480 | PC: 0x08d44c | FDE: 0x03ead8 | Size: 28 bytes [_Z20JS_SetMemoryLimit_GCP12LEPUSRuntimem]
// Khung tháo gỡ #0480 | Địa chỉ PC: 0x08d44c | Địa chỉ FDE: 0x03ead8 | Kích thước: 28 bytes
//   0x08d44c: F9422008  ldr      x8, [x0, #0x440]
//   0x08d450: EB01011F  cmp      x8, x1
//   0x08d454: 54000049  b.ls     #0x8d45c
//   0x08d458: F9022001  str      x1, [x0, #0x440]
static inline uint64_t fde_func_0480_0x08d44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d44cULL ^ (static_cast<uint64_t>(0xf9422008ULL) << 13);
    acc = (acc + a1 + 0xeb01011fULL) ^ 0x03ead8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0481 | PC: 0x08d468 | FDE: 0x03eaf0 | Size: 8 bytes [_ZN16GarbageCollector11SetMaxLimitEm]
// Khung tháo gỡ #0481 | Địa chỉ PC: 0x08d468 | Địa chỉ FDE: 0x03eaf0 | Kích thước: 8 bytes
//   0x08d468: F9001801  str      x1, [x0, #0x30]
//   0x08d46c: D65F03C0  ret      
static inline uint64_t fde_func_0481_0x08d468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d468ULL ^ (static_cast<uint64_t>(0xf9001801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03eaf0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0482 | PC: 0x08d470 | FDE: 0x03eb08 | Size: 256 bytes [_Z16JS_EnqueueJob_GCP12LEPUSContextPF10LEPUSValueS0_iPS1_EiS2_]
// Khung tháo gỡ #0482 | Địa chỉ PC: 0x08d470 | Địa chỉ FDE: 0x03eb08 | Kích thước: 256 bytes
//   0x08d470: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x08d474: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08d478: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08d47c: F9400817  ldr      x23, [x0, #0x10]
static inline uint64_t fde_func_0482_0x08d470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d470ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03eb08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0483 | PC: 0x08d5ac | FDE: 0x03eb28 | Size: 256 bytes [_Z23JS_ExecutePendingJob_GCP12LEPUSRuntimePP12LEPUSContext]
// Khung tháo gỡ #0483 | Địa chỉ PC: 0x08d5ac | Địa chỉ FDE: 0x03eb28 | Kích thước: 256 bytes
//   0x08d5ac: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x08d5b0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08d5b4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08d5b8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0483_0x08d5ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d5acULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03eb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0484 | PC: 0x08d6f0 | FDE: 0x03eb50 | Size: 104 bytes [_ZN11HandleScope10PushHandleEPv10HandleType]
// Khung tháo gỡ #0484 | Địa chỉ PC: 0x08d6f0 | Địa chỉ FDE: 0x03eb50 | Kích thước: 104 bytes
//   0x08d6f0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x08d6f4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x08d6f8: F9400013  ldr      x19, [x0]
//   0x08d6fc: 2A0203F4  mov      w20, w2
static inline uint64_t fde_func_0484_0x08d6f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d6f0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03eb50ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0485 | PC: 0x08d758 | FDE: 0x03eb70 | Size: 12 bytes [_ZN16GarbageCollector15DoOnlyFinalizerEv]
// Khung tháo gỡ #0485 | Địa chỉ PC: 0x08d758 | Địa chỉ FDE: 0x03eb70 | Kích thước: 12 bytes
//   0x08d758: F9401400  ldr      x0, [x0, #0x28]
//   0x08d75c: 52800021  mov      w1, #1
//   0x08d760: 17FF7473  b        #0x6a92c
static inline uint64_t fde_func_0485_0x08d758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d758ULL ^ (static_cast<uint64_t>(0xf9401400ULL) << 13);
    acc = (acc + a1 + 0x52800021ULL) ^ 0x03eb70ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0486 | PC: 0x08d764 | FDE: 0x03eb88 | Size: 256 bytes [_Z23JS_FreeRuntimeForEffectP12LEPUSRuntime]
// Khung tháo gỡ #0486 | Địa chỉ PC: 0x08d764 | Địa chỉ FDE: 0x03eb88 | Kích thước: 256 bytes
//   0x08d764: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x08d768: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08d76c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08d770: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0486_0x08d764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d764ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03eb88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0487 | PC: 0x08d9b8 | FDE: 0x03ebb0 | Size: 256 bytes [_Z19JS_NewContextRaw_GCP12LEPUSRuntime]
// Khung tháo gỡ #0487 | Địa chỉ PC: 0x08d9b8 | Địa chỉ FDE: 0x03ebb0 | Kích thước: 256 bytes
//   0x08d9b8: D10183FF  sub      sp, sp, #0x60
//   0x08d9bc: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x08d9c0: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x08d9c4: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0487_0x08d9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d9b8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03ebb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0488 | PC: 0x08df90 | FDE: 0x03ebd8 | Size: 8 bytes
// Khung tháo gỡ #0488 | Địa chỉ PC: 0x08df90 | Địa chỉ FDE: 0x03ebd8 | Kích thước: 8 bytes
//   0x08df90: 52800240  mov      w0, #0x12
//   0x08df94: D65F03C0  ret      
static inline uint64_t fde_func_0488_0x08df90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08df90ULL ^ (static_cast<uint64_t>(0x52800240ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03ebd8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0489 | PC: 0x08df98 | FDE: 0x03ebf0 | Size: 256 bytes
// Khung tháo gỡ #0489 | Địa chỉ PC: 0x08df98 | Địa chỉ FDE: 0x03ebf0 | Kích thước: 256 bytes
//   0x08df98: D102C3FF  sub      sp, sp, #0xb0
//   0x08df9c: F9002BFC  str      x28, [sp, #0x50]
//   0x08dfa0: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x08dfa4: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_0489_0x08df98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08df98ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x03ebf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0490 | PC: 0x08e2e4 | FDE: 0x03ec20 | Size: 256 bytes
// Khung tháo gỡ #0490 | Địa chỉ PC: 0x08e2e4 | Địa chỉ FDE: 0x03ec20 | Kích thước: 256 bytes
//   0x08e2e4: D10443FF  sub      sp, sp, #0x110
//   0x08e2e8: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x08e2ec: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x08e2f0: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0490_0x08e2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e2e4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x03ec20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0491 | PC: 0x08e998 | FDE: 0x03ec50 | Size: 220 bytes [_Z20JS_NewObjectProto_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0491 | Địa chỉ PC: 0x08e998 | Địa chỉ FDE: 0x03ec50 | Kích thước: 220 bytes
//   0x08e998: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x08e99c: AA0103E8  mov      x8, x1
//   0x08e9a0: AA0003F3  mov      x19, x0
//   0x08e9a4: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_0491_0x08e998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e998ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x03ec50ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0492 | PC: 0x08ea74 | FDE: 0x03ec68 | Size: 256 bytes [_Z19JS_NewAtomString_GCP12LEPUSContextPKc]
// Khung tháo gỡ #0492 | Địa chỉ PC: 0x08ea74 | Địa chỉ FDE: 0x03ec68 | Kích thước: 256 bytes
//   0x08ea74: D10243FF  sub      sp, sp, #0x90
//   0x08ea78: F9002BF8  str      x24, [sp, #0x50]
//   0x08ea7c: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x08ea80: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0492_0x08ea74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ea74ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf8ULL) ^ 0x03ec68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0493 | PC: 0x08ebec | FDE: 0x03ec90 | Size: 180 bytes
// Khung tháo gỡ #0493 | Địa chỉ PC: 0x08ebec | Địa chỉ FDE: 0x03ec90 | Kích thước: 180 bytes
//   0x08ebec: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x08ebf0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x08ebf4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x08ebf8: 39400028  ldrb     w8, [x1]
static inline uint64_t fde_func_0493_0x08ebec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ebecULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03ec90ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0494 | PC: 0x08eca0 | FDE: 0x03ecb0 | Size: 256 bytes
// Khung tháo gỡ #0494 | Địa chỉ PC: 0x08eca0 | Địa chỉ FDE: 0x03ecb0 | Kích thước: 256 bytes
//   0x08eca0: D10103FF  sub      sp, sp, #0x40
//   0x08eca4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x08eca8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x08ecac: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0494_0x08eca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08eca0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03ecb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0495 | PC: 0x08edcc | FDE: 0x03ecd0 | Size: 256 bytes
// Khung tháo gỡ #0495 | Địa chỉ PC: 0x08edcc | Địa chỉ FDE: 0x03ecd0 | Kích thước: 256 bytes
//   0x08edcc: D10143FF  sub      sp, sp, #0x50
//   0x08edd0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x08edd4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x08edd8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0495_0x08edcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08edccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x03ecd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0496 | PC: 0x08f094 | FDE: 0x03ecf0 | Size: 256 bytes
// Khung tháo gỡ #0496 | Địa chỉ PC: 0x08f094 | Địa chỉ FDE: 0x03ecf0 | Kích thước: 256 bytes
//   0x08f094: D10243FF  sub      sp, sp, #0x90
//   0x08f098: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x08f09c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08f0a0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0496_0x08f094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f094ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03ecf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0497 | PC: 0x08f4c0 | FDE: 0x03ed20 | Size: 256 bytes
// Khung tháo gỡ #0497 | Địa chỉ PC: 0x08f4c0 | Địa chỉ FDE: 0x03ed20 | Kích thước: 256 bytes
//   0x08f4c0: D10203FF  sub      sp, sp, #0x80
//   0x08f4c4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x08f4c8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x08f4cc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0497_0x08f4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f4c0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x03ed20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0498 | PC: 0x08fac8 | FDE: 0x03ed50 | Size: 232 bytes [_Z11PrimInit_GCP12LEPUSContext]
// Khung tháo gỡ #0498 | Địa chỉ PC: 0x08fac8 | Địa chỉ FDE: 0x03ed50 | Kích thước: 232 bytes
//   0x08fac8: D0000968  adrp     x8, #0x1bd000
//   0x08facc: D000096A  adrp     x10, #0x1bd000
//   0x08fad0: D0000969  adrp     x9, #0x1bd000
//   0x08fad4: F9411108  ldr      x8, [x8, #0x220]
static inline uint64_t fde_func_0498_0x08fac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fac8ULL ^ (static_cast<uint64_t>(0xd0000968ULL) << 13);
    acc = (acc + a1 + 0xd000096aULL) ^ 0x03ed50ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0499 | PC: 0x08fbb0 | FDE: 0x03ed68 | Size: 256 bytes [_Z16JS_NewContext_GCP12LEPUSRuntime]
// Khung tháo gỡ #0499 | Địa chỉ PC: 0x08fbb0 | Địa chỉ FDE: 0x03ed68 | Kích thước: 256 bytes
//   0x08fbb0: D10303FF  sub      sp, sp, #0xc0
//   0x08fbb4: F9003BFA  str      x26, [sp, #0x70]
//   0x08fbb8: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x08fbbc: A9095BF7  stp      x23, x22, [sp, #0x90]
static inline uint64_t fde_func_0499_0x08fbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fbb0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfaULL) ^ 0x03ed68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0500 | PC: 0x090198 | FDE: 0x03ed90 | Size: 256 bytes [_Z29JS_AddIntrinsicBaseObjects_GCP12LEPUSContext]
// Khung tháo gỡ #0500 | Địa chỉ PC: 0x090198 | Địa chỉ FDE: 0x03ed90 | Kích thước: 256 bytes
//   0x090198: D103C3FF  sub      sp, sp, #0xf0
//   0x09019c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0901a0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0901a4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0500_0x090198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090198ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x03ed90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0501 | PC: 0x091558 | FDE: 0x03edc0 | Size: 256 bytes [_Z22JS_AddIntrinsicDate_GCP12LEPUSContext]
// Khung tháo gỡ #0501 | Địa chỉ PC: 0x091558 | Địa chỉ FDE: 0x03edc0 | Kích thước: 256 bytes
//   0x091558: D10143FF  sub      sp, sp, #0x50
//   0x09155c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x091560: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x091564: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0501_0x091558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091558ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03edc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0502 | PC: 0x0916f0 | FDE: 0x03ede8 | Size: 256 bytes
// Khung tháo gỡ #0502 | Địa chỉ PC: 0x0916f0 | Địa chỉ FDE: 0x03ede8 | Kích thước: 256 bytes
//   0x0916f0: D10543FF  sub      sp, sp, #0x150
//   0x0916f4: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0916f8: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x0916fc: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_0502_0x0916f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0916f0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x03ede8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0503 | PC: 0x091e58 | FDE: 0x03ee18 | Size: 256 bytes [_Z24JS_AddIntrinsicRegExp_GCP12LEPUSContext]
// Khung tháo gỡ #0503 | Địa chỉ PC: 0x091e58 | Địa chỉ FDE: 0x03ee18 | Kích thước: 256 bytes
//   0x091e58: D10143FF  sub      sp, sp, #0x50
//   0x091e5c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x091e60: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x091e64: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0503_0x091e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091e58ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03ee18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0504 | PC: 0x092030 | FDE: 0x03ee40 | Size: 256 bytes [_Z23JS_AddIntrinsicProxy_GCP12LEPUSContext]
// Khung tháo gỡ #0504 | Địa chỉ PC: 0x092030 | Địa chỉ FDE: 0x03ee40 | Kích thước: 256 bytes
//   0x092030: D10243FF  sub      sp, sp, #0x90
//   0x092034: F9001BFC  str      x28, [sp, #0x30]
//   0x092038: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x09203c: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_0504_0x092030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092030ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x03ee40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0505 | PC: 0x09229c | FDE: 0x03ee70 | Size: 256 bytes [_Z24JS_AddIntrinsicMapSet_GCP12LEPUSContext]
// Khung tháo gỡ #0505 | Địa chỉ PC: 0x09229c | Địa chỉ FDE: 0x03ee70 | Kích thước: 256 bytes
//   0x09229c: D102C3FF  sub      sp, sp, #0xb0
//   0x0922a0: F9002BFC  str      x28, [sp, #0x50]
//   0x0922a4: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x0922a8: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_0505_0x09229c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09229cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x03ee70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0506 | PC: 0x0924a0 | FDE: 0x03eea0 | Size: 256 bytes [_Z29JS_AddIntrinsicTypedArrays_GCP12LEPUSContext]
// Khung tháo gỡ #0506 | Địa chỉ PC: 0x0924a0 | Địa chỉ FDE: 0x03eea0 | Kích thước: 256 bytes
//   0x0924a0: D102C3FF  sub      sp, sp, #0xb0
//   0x0924a4: F90033FA  str      x26, [sp, #0x60]
//   0x0924a8: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x0924ac: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0506_0x0924a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0924a0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033faULL) ^ 0x03eea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0507 | PC: 0x092b1c | FDE: 0x03eec8 | Size: 256 bytes [_Z25JS_AddIntrinsicPromise_GCP12LEPUSContext]
// Khung tháo gỡ #0507 | Địa chỉ PC: 0x092b1c | Địa chỉ FDE: 0x03eec8 | Kích thước: 256 bytes
//   0x092b1c: D101C3FF  sub      sp, sp, #0x70
//   0x092b20: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x092b24: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x092b28: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_0507_0x092b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092b1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90363f9ULL) ^ 0x03eec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0508 | PC: 0x092f2c | FDE: 0x03eef0 | Size: 256 bytes
// Khung tháo gỡ #0508 | Địa chỉ PC: 0x092f2c | Địa chỉ FDE: 0x03eef0 | Kích thước: 256 bytes
//   0x092f2c: D10183FF  sub      sp, sp, #0x60
//   0x092f30: F9000BFA  str      x26, [sp, #0x10]
//   0x092f34: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x092f38: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0508_0x092f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092f2cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x03eef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0509 | PC: 0x093148 | FDE: 0x03ef18 | Size: 256 bytes
// Khung tháo gỡ #0509 | Địa chỉ PC: 0x093148 | Địa chỉ FDE: 0x03ef18 | Kích thước: 256 bytes
//   0x093148: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x09314c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x093150: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x093154: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0509_0x093148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093148ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03ef18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0510 | PC: 0x093274 | FDE: 0x03ef40 | Size: 56 bytes
// Khung tháo gỡ #0510 | Địa chỉ PC: 0x093274 | Địa chỉ FDE: 0x03ef40 | Kích thước: 56 bytes
//   0x093274: D0000948  adrp     x8, #0x1bd000
//   0x093278: F940D908  ldr      x8, [x8, #0x1b0]
//   0x09327c: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x093280: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0510_0x093274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093274ULL ^ (static_cast<uint64_t>(0xd0000948ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x03ef40ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0511 | PC: 0x0932ac | FDE: 0x03ef58 | Size: 256 bytes
// Khung tháo gỡ #0511 | Địa chỉ PC: 0x0932ac | Địa chỉ FDE: 0x03ef58 | Kích thước: 256 bytes
//   0x0932ac: D10143FF  sub      sp, sp, #0x50
//   0x0932b0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0932b4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0932b8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0511_0x0932ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0932acULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03ef58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0512 | PC: 0x093494 | FDE: 0x03ef80 | Size: 256 bytes
// Khung tháo gỡ #0512 | Địa chỉ PC: 0x093494 | Địa chỉ FDE: 0x03ef80 | Kích thước: 256 bytes
//   0x093494: D10203FF  sub      sp, sp, #0x80
//   0x093498: F90013FC  str      x28, [sp, #0x20]
//   0x09349c: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0934a0: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0512_0x093494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093494ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x03ef80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0513 | PC: 0x0937d0 | FDE: 0x03efb0 | Size: 256 bytes
// Khung tháo gỡ #0513 | Địa chỉ PC: 0x0937d0 | Địa chỉ FDE: 0x03efb0 | Kích thước: 256 bytes
//   0x0937d0: D101C3FF  sub      sp, sp, #0x70
//   0x0937d4: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x0937d8: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0937dc: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0513_0x0937d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0937d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x03efb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0514 | PC: 0x093be8 | FDE: 0x03efd8 | Size: 256 bytes
// Khung tháo gỡ #0514 | Địa chỉ PC: 0x093be8 | Địa chỉ FDE: 0x03efd8 | Kích thước: 256 bytes
//   0x093be8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x093bec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x093bf0: D371FC28  lsr      x8, x1, #0x31
//   0x093bf4: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0514_0x093be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093be8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03efd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0515 | PC: 0x093d88 | FDE: 0x03eff8 | Size: 256 bytes
// Khung tháo gỡ #0515 | Địa chỉ PC: 0x093d88 | Địa chỉ FDE: 0x03eff8 | Kích thước: 256 bytes
//   0x093d88: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x093d8c: D371FC28  lsr      x8, x1, #0x31
//   0x093d90: F100011F  cmp      x8, #0
//   0x093d94: 1A9F07E9  cset     w9, ne
static inline uint64_t fde_func_0515_0x093d88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093d88ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd371fc28ULL) ^ 0x03eff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0516 | PC: 0x093eb4 | FDE: 0x03f010 | Size: 256 bytes
// Khung tháo gỡ #0516 | Địa chỉ PC: 0x093eb4 | Địa chỉ FDE: 0x03f010 | Kích thước: 256 bytes
//   0x093eb4: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x093eb8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x093ebc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x093ec0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0516_0x093eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093eb4ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03f010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0517 | PC: 0x094028 | FDE: 0x03f038 | Size: 256 bytes
// Khung tháo gỡ #0517 | Địa chỉ PC: 0x094028 | Địa chỉ FDE: 0x03f038 | Kích thước: 256 bytes
//   0x094028: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x09402c: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x094030: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x094034: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0517_0x094028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094028ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03f038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0518 | PC: 0x094254 | FDE: 0x03f068 | Size: 256 bytes
// Khung tháo gỡ #0518 | Địa chỉ PC: 0x094254 | Địa chỉ FDE: 0x03f068 | Kích thước: 256 bytes
//   0x094254: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x094258: B4000741  cbz      x1, #0x94340
//   0x09425c: D2800048  mov      x8, #2
//   0x094260: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0518_0x094254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094254ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000741ULL) ^ 0x03f068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0519 | PC: 0x094378 | FDE: 0x03f080 | Size: 8 bytes
// Khung tháo gỡ #0519 | Địa chỉ PC: 0x094378 | Địa chỉ FDE: 0x03f080 | Kích thước: 8 bytes
//   0x094378: AA0103E0  mov      x0, x1
//   0x09437c: D65F03C0  ret      
static inline uint64_t fde_func_0519_0x094378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094378ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03f080ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0520 | PC: 0x094380 | FDE: 0x03f098 | Size: 100 bytes
// Khung tháo gỡ #0520 | Địa chỉ PC: 0x094380 | Địa chỉ FDE: 0x03f098 | Kích thước: 100 bytes
//   0x094380: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x094384: B4000241  cbz      x1, #0x943cc
//   0x094388: D2800048  mov      x8, #2
//   0x09438c: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0520_0x094380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094380ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000241ULL) ^ 0x03f098ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0521 | PC: 0x0943e4 | FDE: 0x03f0b0 | Size: 256 bytes
// Khung tháo gỡ #0521 | Địa chỉ PC: 0x0943e4 | Địa chỉ FDE: 0x03f0b0 | Kích thước: 256 bytes
//   0x0943e4: D10283FF  sub      sp, sp, #0xa0
//   0x0943e8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0943ec: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0943f0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0521_0x0943e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0943e4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03f0b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0522 | PC: 0x09489c | FDE: 0x03f0e0 | Size: 256 bytes
// Khung tháo gỡ #0522 | Địa chỉ PC: 0x09489c | Địa chỉ FDE: 0x03f0e0 | Kích thước: 256 bytes
//   0x09489c: D10183FF  sub      sp, sp, #0x60
//   0x0948a0: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0948a4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0948a8: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0522_0x09489c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09489cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03f0e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0523 | PC: 0x094a90 | FDE: 0x03f108 | Size: 256 bytes
// Khung tháo gỡ #0523 | Địa chỉ PC: 0x094a90 | Địa chỉ FDE: 0x03f108 | Kích thước: 256 bytes
//   0x094a90: D10143FF  sub      sp, sp, #0x50
//   0x094a94: F9000BF8  str      x24, [sp, #0x10]
//   0x094a98: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x094a9c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0523_0x094a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094a90ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x03f108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0524 | PC: 0x094bac | FDE: 0x03f130 | Size: 256 bytes
// Khung tháo gỡ #0524 | Địa chỉ PC: 0x094bac | Địa chỉ FDE: 0x03f130 | Kích thước: 256 bytes
//   0x094bac: D102C3FF  sub      sp, sp, #0xb0
//   0x094bb0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x094bb4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x094bb8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0524_0x094bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094bacULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03f130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x094e58 | FDE: 0x03f160 | Size: 256 bytes
// Khung tháo gỡ #0525 | Địa chỉ PC: 0x094e58 | Địa chỉ FDE: 0x03f160 | Kích thước: 256 bytes
//   0x094e58: D10243FF  sub      sp, sp, #0x90
//   0x094e5c: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x094e60: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x094e64: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0525_0x094e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094e58ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x03f160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0526 | PC: 0x095328 | FDE: 0x03f190 | Size: 256 bytes
// Khung tháo gỡ #0526 | Địa chỉ PC: 0x095328 | Địa chỉ FDE: 0x03f190 | Kích thước: 256 bytes
//   0x095328: D10303FF  sub      sp, sp, #0xc0
//   0x09532c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x095330: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x095334: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0526_0x095328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095328ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x03f190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0527 | PC: 0x095c9c | FDE: 0x03f1c0 | Size: 256 bytes
// Khung tháo gỡ #0527 | Địa chỉ PC: 0x095c9c | Địa chỉ FDE: 0x03f1c0 | Kích thước: 256 bytes
//   0x095c9c: D10203FF  sub      sp, sp, #0x80
//   0x095ca0: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x095ca4: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x095ca8: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0527_0x095c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c9cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9036bfbULL) ^ 0x03f1c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0528 | PC: 0x095fe4 | FDE: 0x03f1f0 | Size: 256 bytes
// Khung tháo gỡ #0528 | Địa chỉ PC: 0x095fe4 | Địa chỉ FDE: 0x03f1f0 | Kích thước: 256 bytes
//   0x095fe4: D103C3FF  sub      sp, sp, #0xf0
//   0x095fe8: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x095fec: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x095ff0: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0528_0x095fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095fe4ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x03f1f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0529 | PC: 0x0969e8 | FDE: 0x03f220 | Size: 256 bytes
// Khung tháo gỡ #0529 | Địa chỉ PC: 0x0969e8 | Địa chỉ FDE: 0x03f220 | Kích thước: 256 bytes
//   0x0969e8: D101C3FF  sub      sp, sp, #0x70
//   0x0969ec: F90013FA  str      x26, [sp, #0x20]
//   0x0969f0: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0969f4: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0529_0x0969e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0969e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x03f220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0530 | PC: 0x096d30 | FDE: 0x03f248 | Size: 80 bytes
// Khung tháo gỡ #0530 | Địa chỉ PC: 0x096d30 | Địa chỉ FDE: 0x03f248 | Kích thước: 80 bytes
//   0x096d30: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096d34: F94000A8  ldr      x8, [x5]
//   0x096d38: F100491F  cmp      x8, #0x12
//   0x096d3c: 54000161  b.ne     #0x96d68
static inline uint64_t fde_func_0530_0x096d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d30ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf94000a8ULL) ^ 0x03f248ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0531 | PC: 0x096d80 | FDE: 0x03f260 | Size: 256 bytes
// Khung tháo gỡ #0531 | Địa chỉ PC: 0x096d80 | Địa chỉ FDE: 0x03f260 | Kích thước: 256 bytes
//   0x096d80: D101C3FF  sub      sp, sp, #0x70
//   0x096d84: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x096d88: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x096d8c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0531_0x096d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d80ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03f260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0532 | PC: 0x0970bc | FDE: 0x03f290 | Size: 256 bytes
// Khung tháo gỡ #0532 | Địa chỉ PC: 0x0970bc | Địa chỉ FDE: 0x03f290 | Kích thước: 256 bytes
//   0x0970bc: D10183FF  sub      sp, sp, #0x60
//   0x0970c0: F90013F8  str      x24, [sp, #0x20]
//   0x0970c4: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0970c8: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0532_0x0970bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0970bcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x03f290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0533 | PC: 0x0971e0 | FDE: 0x03f2b8 | Size: 256 bytes
// Khung tháo gỡ #0533 | Địa chỉ PC: 0x0971e0 | Địa chỉ FDE: 0x03f2b8 | Kích thước: 256 bytes
//   0x0971e0: D10183FF  sub      sp, sp, #0x60
//   0x0971e4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0971e8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0971ec: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0533_0x0971e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0971e0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03f2b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0534 | PC: 0x0973a8 | FDE: 0x03f2e0 | Size: 256 bytes
// Khung tháo gỡ #0534 | Địa chỉ PC: 0x0973a8 | Địa chỉ FDE: 0x03f2e0 | Kích thước: 256 bytes
//   0x0973a8: D102C3FF  sub      sp, sp, #0xb0
//   0x0973ac: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0973b0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0973b4: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0534_0x0973a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0973a8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03f2e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0535 | PC: 0x097a0c | FDE: 0x03f310 | Size: 256 bytes
// Khung tháo gỡ #0535 | Địa chỉ PC: 0x097a0c | Địa chỉ FDE: 0x03f310 | Kích thước: 256 bytes
//   0x097a0c: D101C3FF  sub      sp, sp, #0x70
//   0x097a10: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x097a14: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x097a18: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0535_0x097a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097a0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x03f310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0536 | PC: 0x097d04 | FDE: 0x03f338 | Size: 256 bytes
// Khung tháo gỡ #0536 | Địa chỉ PC: 0x097d04 | Địa chỉ FDE: 0x03f338 | Kích thước: 256 bytes
//   0x097d04: D10483FF  sub      sp, sp, #0x120
//   0x097d08: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x097d0c: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x097d10: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0536_0x097d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097d04ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x03f338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0537 | PC: 0x0992d8 | FDE: 0x03f368 | Size: 256 bytes
// Khung tháo gỡ #0537 | Địa chỉ PC: 0x0992d8 | Địa chỉ FDE: 0x03f368 | Kích thước: 256 bytes
//   0x0992d8: D10203FF  sub      sp, sp, #0x80
//   0x0992dc: F9001BFA  str      x26, [sp, #0x30]
//   0x0992e0: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0992e4: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0537_0x0992d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0992d8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfaULL) ^ 0x03f368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0538 | PC: 0x099608 | FDE: 0x03f390 | Size: 256 bytes
// Khung tháo gỡ #0538 | Địa chỉ PC: 0x099608 | Địa chỉ FDE: 0x03f390 | Kích thước: 256 bytes
//   0x099608: D10143FF  sub      sp, sp, #0x50
//   0x09960c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x099610: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x099614: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0538_0x099608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099608ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x03f390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0539 | PC: 0x099740 | FDE: 0x03f3b0 | Size: 256 bytes [_Z22JS_SetPropertyInt64_GCP12LEPUSContext10LEPUSValuelS1_]
// Khung tháo gỡ #0539 | Địa chỉ PC: 0x099740 | Địa chỉ FDE: 0x03f3b0 | Kích thước: 256 bytes
//   0x099740: D10103FF  sub      sp, sp, #0x40
//   0x099744: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x099748: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x09974c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0539_0x099740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099740ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03f3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0540 | PC: 0x09985c | FDE: 0x03f3d0 | Size: 248 bytes [_Z20JS_NewObjectClass_GCP12LEPUSContexti]
// Khung tháo gỡ #0540 | Địa chỉ PC: 0x09985c | Địa chỉ FDE: 0x03f3d0 | Kích thước: 248 bytes
//   0x09985c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x099860: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x099864: F9401C08  ldr      x8, [x0, #0x38]
//   0x099868: D2800049  mov      x9, #2
static inline uint64_t fde_func_0540_0x09985c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09985cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03f3d0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0541 | PC: 0x099954 | FDE: 0x03f3f0 | Size: 256 bytes [_Z31JS_DefinePropertyValueUint32_GCP12LEPUSContext10LEPUSValuejS1_i]
// Khung tháo gỡ #0541 | Địa chỉ PC: 0x099954 | Địa chỉ FDE: 0x03f3f0 | Kích thước: 256 bytes
//   0x099954: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x099958: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x09995c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x099960: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0541_0x099954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099954ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03f3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0542 | PC: 0x099a60 | FDE: 0x03f418 | Size: 240 bytes
// Khung tháo gỡ #0542 | Địa chỉ PC: 0x099a60 | Địa chỉ FDE: 0x03f418 | Kích thước: 240 bytes
//   0x099a60: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x099a64: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x099a68: AA0003F3  mov      x19, x0
//   0x099a6c: B4000441  cbz      x1, #0x99af4
static inline uint64_t fde_func_0542_0x099a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099a60ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03f418ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0543 | PC: 0x099b50 | FDE: 0x03f438 | Size: 256 bytes
// Khung tháo gỡ #0543 | Địa chỉ PC: 0x099b50 | Địa chỉ FDE: 0x03f438 | Kích thước: 256 bytes
//   0x099b50: D10203FF  sub      sp, sp, #0x80
//   0x099b54: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x099b58: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x099b5c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0543_0x099b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099b50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x03f438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0544 | PC: 0x099eac | FDE: 0x03f468 | Size: 256 bytes
// Khung tháo gỡ #0544 | Địa chỉ PC: 0x099eac | Địa chỉ FDE: 0x03f468 | Kích thước: 256 bytes
//   0x099eac: D10143FF  sub      sp, sp, #0x50
//   0x099eb0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x099eb4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x099eb8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0544_0x099eac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099eacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03f468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0545 | PC: 0x09a248 | FDE: 0x03f490 | Size: 256 bytes
// Khung tháo gỡ #0545 | Địa chỉ PC: 0x09a248 | Địa chỉ FDE: 0x03f490 | Kích thước: 256 bytes
//   0x09a248: D10183FF  sub      sp, sp, #0x60
//   0x09a24c: F9001BF6  str      x22, [sp, #0x30]
//   0x09a250: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x09a254: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0545_0x09a248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a248ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x03f490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0546 | PC: 0x09a370 | FDE: 0x03f4b0 | Size: 256 bytes [_Z13JS_ToInt64_GCP12LEPUSContextPl10LEPUSValue]
// Khung tháo gỡ #0546 | Địa chỉ PC: 0x09a370 | Địa chỉ FDE: 0x03f4b0 | Kích thước: 256 bytes
//   0x09a370: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x09a374: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x09a378: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x09a37c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0546_0x09a370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a370ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03f4b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0547 | PC: 0x09a4e0 | FDE: 0x03f4d8 | Size: 256 bytes
// Khung tháo gỡ #0547 | Địa chỉ PC: 0x09a4e0 | Địa chỉ FDE: 0x03f4d8 | Kích thước: 256 bytes
//   0x09a4e0: D10303FF  sub      sp, sp, #0xc0
//   0x09a4e4: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x09a4e8: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x09a4ec: A9095BF7  stp      x23, x22, [sp, #0x90]
static inline uint64_t fde_func_0547_0x09a4e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a4e0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9076bfbULL) ^ 0x03f4d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0548 | PC: 0x09aba4 | FDE: 0x03f508 | Size: 256 bytes
// Khung tháo gỡ #0548 | Địa chỉ PC: 0x09aba4 | Địa chỉ FDE: 0x03f508 | Kích thước: 256 bytes
//   0x09aba4: D10183FF  sub      sp, sp, #0x60
//   0x09aba8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x09abac: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x09abb0: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0548_0x09aba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09aba4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03f508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0549 | PC: 0x09ad0c | FDE: 0x03f530 | Size: 44 bytes
// Khung tháo gỡ #0549 | Địa chỉ PC: 0x09ad0c | Địa chỉ FDE: 0x03f530 | Kích thước: 44 bytes
//   0x09ad0c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x09ad10: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x09ad14: A94004B3  ldp      x19, x1, [x5]
//   0x09ad18: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0549_0x09ad0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ad0cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03f530ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0550 | PC: 0x09ad38 | FDE: 0x03f550 | Size: 256 bytes
// Khung tháo gỡ #0550 | Địa chỉ PC: 0x09ad38 | Địa chỉ FDE: 0x03f550 | Kích thước: 256 bytes
//   0x09ad38: D10343FF  sub      sp, sp, #0xd0
//   0x09ad3c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x09ad40: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x09ad44: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_0550_0x09ad38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ad38ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90867faULL) ^ 0x03f550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0551 | PC: 0x09b40c | FDE: 0x03f580 | Size: 256 bytes
// Khung tháo gỡ #0551 | Địa chỉ PC: 0x09b40c | Địa chỉ FDE: 0x03f580 | Kích thước: 256 bytes
//   0x09b40c: D104C3FF  sub      sp, sp, #0x130
//   0x09b410: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x09b414: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x09b418: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0551_0x09b40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b40cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x03f580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0552 | PC: 0x09c13c | FDE: 0x03f5b0 | Size: 256 bytes
// Khung tháo gỡ #0552 | Địa chỉ PC: 0x09c13c | Địa chỉ FDE: 0x03f5b0 | Kích thước: 256 bytes
//   0x09c13c: D10303FF  sub      sp, sp, #0xc0
//   0x09c140: F90033FC  str      x28, [sp, #0x60]
//   0x09c144: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x09c148: A90863F9  stp      x25, x24, [sp, #0x80]
static inline uint64_t fde_func_0552_0x09c13c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c13cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fcULL) ^ 0x03f5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0553 | PC: 0x09c804 | FDE: 0x03f5e0 | Size: 256 bytes
// Khung tháo gỡ #0553 | Địa chỉ PC: 0x09c804 | Địa chỉ FDE: 0x03f5e0 | Kích thước: 256 bytes
//   0x09c804: D10283FF  sub      sp, sp, #0xa0
//   0x09c808: F90023FC  str      x28, [sp, #0x40]
//   0x09c80c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x09c810: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_0553_0x09c804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c804ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fcULL) ^ 0x03f5e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0554 | PC: 0x09cc7c | FDE: 0x03f610 | Size: 256 bytes
// Khung tháo gỡ #0554 | Địa chỉ PC: 0x09cc7c | Địa chỉ FDE: 0x03f610 | Kích thước: 256 bytes
//   0x09cc7c: D10183FF  sub      sp, sp, #0x60
//   0x09cc80: F90013F8  str      x24, [sp, #0x20]
//   0x09cc84: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x09cc88: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0554_0x09cc7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cc7cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x03f610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0555 | PC: 0x09cd9c | FDE: 0x03f638 | Size: 256 bytes
// Khung tháo gỡ #0555 | Địa chỉ PC: 0x09cd9c | Địa chỉ FDE: 0x03f638 | Kích thước: 256 bytes
//   0x09cd9c: D10183FF  sub      sp, sp, #0x60
//   0x09cda0: F90013F8  str      x24, [sp, #0x20]
//   0x09cda4: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x09cda8: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0555_0x09cd9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cd9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x03f638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0556 | PC: 0x09cfdc | FDE: 0x03f660 | Size: 256 bytes
// Khung tháo gỡ #0556 | Địa chỉ PC: 0x09cfdc | Địa chỉ FDE: 0x03f660 | Kích thước: 256 bytes
//   0x09cfdc: D102C3FF  sub      sp, sp, #0xb0
//   0x09cfe0: F90033FA  str      x26, [sp, #0x60]
//   0x09cfe4: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x09cfe8: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0556_0x09cfdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cfdcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033faULL) ^ 0x03f660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0557 | PC: 0x09d264 | FDE: 0x03f688 | Size: 256 bytes
// Khung tháo gỡ #0557 | Địa chỉ PC: 0x09d264 | Địa chỉ FDE: 0x03f688 | Kích thước: 256 bytes
//   0x09d264: D10183FF  sub      sp, sp, #0x60
//   0x09d268: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x09d26c: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x09d270: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0557_0x09d264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d264ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03f688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0558 | PC: 0x09d3d0 | FDE: 0x03f6b0 | Size: 256 bytes
// Khung tháo gỡ #0558 | Địa chỉ PC: 0x09d3d0 | Địa chỉ FDE: 0x03f6b0 | Kích thước: 256 bytes
//   0x09d3d0: D10203FF  sub      sp, sp, #0x80
//   0x09d3d4: F90023F8  str      x24, [sp, #0x40]
//   0x09d3d8: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x09d3dc: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0558_0x09d3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d3d0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x03f6b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0559 | PC: 0x09d784 | FDE: 0x03f6d8 | Size: 256 bytes
// Khung tháo gỡ #0559 | Địa chỉ PC: 0x09d784 | Địa chỉ FDE: 0x03f6d8 | Kích thước: 256 bytes
//   0x09d784: D10243FF  sub      sp, sp, #0x90
//   0x09d788: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x09d78c: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x09d790: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0559_0x09d784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d784ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x03f6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0560 | PC: 0x09db58 | FDE: 0x03f708 | Size: 8 bytes
// Khung tháo gỡ #0560 | Địa chỉ PC: 0x09db58 | Địa chỉ FDE: 0x03f708 | Kích thước: 8 bytes
//   0x09db58: F94000A0  ldr      x0, [x5]
//   0x09db5c: D65F03C0  ret      
static inline uint64_t fde_func_0560_0x09db58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09db58ULL ^ (static_cast<uint64_t>(0xf94000a0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03f708ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0561 | PC: 0x09db60 | FDE: 0x03f720 | Size: 24 bytes
// Khung tháo gỡ #0561 | Địa chỉ PC: 0x09db60 | Địa chỉ FDE: 0x03f720 | Kích thước: 24 bytes
//   0x09db60: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x09db64: F94000A1  ldr      x1, [x5]
//   0x09db68: 94016D5B  bl       #0xf90d4
//   0x09db6c: 52801040  mov      w0, #0x82
static inline uint64_t fde_func_0561_0x09db60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09db60ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf94000a1ULL) ^ 0x03f720ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0562 | PC: 0x09db78 | FDE: 0x03f738 | Size: 256 bytes
// Khung tháo gỡ #0562 | Địa chỉ PC: 0x09db78 | Địa chỉ FDE: 0x03f738 | Kích thước: 256 bytes
//   0x09db78: D10343FF  sub      sp, sp, #0xd0
//   0x09db7c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x09db80: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x09db84: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0562_0x09db78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09db78ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x03f738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0563 | PC: 0x09e210 | FDE: 0x03f768 | Size: 256 bytes
// Khung tháo gỡ #0563 | Địa chỉ PC: 0x09e210 | Địa chỉ FDE: 0x03f768 | Kích thước: 256 bytes
//   0x09e210: D10303FF  sub      sp, sp, #0xc0
//   0x09e214: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x09e218: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x09e21c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0563_0x09e210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e210ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x03f768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0564 | PC: 0x09e7b0 | FDE: 0x03f798 | Size: 256 bytes
// Khung tháo gỡ #0564 | Địa chỉ PC: 0x09e7b0 | Địa chỉ FDE: 0x03f798 | Kích thước: 256 bytes
//   0x09e7b0: D10243FF  sub      sp, sp, #0x90
//   0x09e7b4: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x09e7b8: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x09e7bc: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0564_0x09e7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e7b0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x03f798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0565 | PC: 0x09eb48 | FDE: 0x03f7c8 | Size: 116 bytes
// Khung tháo gỡ #0565 | Địa chỉ PC: 0x09eb48 | Địa chỉ FDE: 0x03f7c8 | Kích thước: 116 bytes
//   0x09eb48: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x09eb4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x09eb50: F9400062  ldr      x2, [x3]
//   0x09eb54: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0565_0x09eb48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09eb48ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03f7c8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0566 | PC: 0x09ebbc | FDE: 0x03f7e8 | Size: 116 bytes
// Khung tháo gỡ #0566 | Địa chỉ PC: 0x09ebbc | Địa chỉ FDE: 0x03f7e8 | Kích thước: 116 bytes
//   0x09ebbc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x09ebc0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x09ebc4: F9400062  ldr      x2, [x3]
//   0x09ebc8: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0566_0x09ebbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ebbcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03f7e8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0567 | PC: 0x09ec30 | FDE: 0x03f808 | Size: 28 bytes
// Khung tháo gỡ #0567 | Địa chỉ PC: 0x09ec30 | Địa chỉ FDE: 0x03f808 | Kích thước: 28 bytes
//   0x09ec30: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x09ec34: F0FFFC81  adrp     x1, #0x31000
//   0x09ec38: 91173021  add      x1, x1, #0x5cc
//   0x09ec3c: 940168FE  bl       #0xf9034
static inline uint64_t fde_func_0567_0x09ec30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ec30ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf0fffc81ULL) ^ 0x03f808ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0568 | PC: 0x09ec4c | FDE: 0x03f820 | Size: 256 bytes
// Khung tháo gỡ #0568 | Địa chỉ PC: 0x09ec4c | Địa chỉ FDE: 0x03f820 | Kích thước: 256 bytes
//   0x09ec4c: D10343FF  sub      sp, sp, #0xd0
//   0x09ec50: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x09ec54: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x09ec58: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0568_0x09ec4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ec4cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x03f820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0569 | PC: 0x09ef8c | FDE: 0x03f850 | Size: 256 bytes
// Khung tháo gỡ #0569 | Địa chỉ PC: 0x09ef8c | Địa chỉ FDE: 0x03f850 | Kích thước: 256 bytes
//   0x09ef8c: D103C3FF  sub      sp, sp, #0xf0
//   0x09ef90: FD0043E8  str      d8, [sp, #0x80]
//   0x09ef94: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x09ef98: A90A67FA  stp      x26, x25, [sp, #0xa0]
static inline uint64_t fde_func_0569_0x09ef8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ef8cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0043e8ULL) ^ 0x03f850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0570 | PC: 0x09fe6c | FDE: 0x03f880 | Size: 256 bytes
// Khung tháo gỡ #0570 | Địa chỉ PC: 0x09fe6c | Địa chỉ FDE: 0x03f880 | Kích thước: 256 bytes
//   0x09fe6c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x09fe70: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x09fe74: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x09fe78: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0570_0x09fe6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fe6cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03f880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0571 | PC: 0x09fff0 | FDE: 0x03f8a8 | Size: 256 bytes
// Khung tháo gỡ #0571 | Địa chỉ PC: 0x09fff0 | Địa chỉ FDE: 0x03f8a8 | Kích thước: 256 bytes
//   0x09fff0: D10203FF  sub      sp, sp, #0x80
//   0x09fff4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x09fff8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x09fffc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0571_0x09fff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fff0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x03f8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0572 | PC: 0x0a0290 | FDE: 0x03f8d8 | Size: 256 bytes
// Khung tháo gỡ #0572 | Địa chỉ PC: 0x0a0290 | Địa chỉ FDE: 0x03f8d8 | Kích thước: 256 bytes
//   0x0a0290: D103C3FF  sub      sp, sp, #0xf0
//   0x0a0294: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0a0298: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0a029c: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0572_0x0a0290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0290ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x03f8d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0573 | PC: 0x0a0ae8 | FDE: 0x03f908 | Size: 256 bytes
// Khung tháo gỡ #0573 | Địa chỉ PC: 0x0a0ae8 | Địa chỉ FDE: 0x03f908 | Kích thước: 256 bytes
//   0x0a0ae8: D101C3FF  sub      sp, sp, #0x70
//   0x0a0aec: F90013FA  str      x26, [sp, #0x20]
//   0x0a0af0: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0a0af4: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0573_0x0a0ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0ae8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x03f908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0574 | PC: 0x0a0c6c | FDE: 0x03f930 | Size: 256 bytes
// Khung tháo gỡ #0574 | Địa chỉ PC: 0x0a0c6c | Địa chỉ FDE: 0x03f930 | Kích thước: 256 bytes
//   0x0a0c6c: D10183FF  sub      sp, sp, #0x60
//   0x0a0c70: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a0c74: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0a0c78: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0574_0x0a0c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0c6cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03f930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0575 | PC: 0x0a0e30 | FDE: 0x03f958 | Size: 256 bytes
// Khung tháo gỡ #0575 | Địa chỉ PC: 0x0a0e30 | Địa chỉ FDE: 0x03f958 | Kích thước: 256 bytes
//   0x0a0e30: D10183FF  sub      sp, sp, #0x60
//   0x0a0e34: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a0e38: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0a0e3c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0575_0x0a0e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0e30ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03f958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0576 | PC: 0x0a0fe4 | FDE: 0x03f980 | Size: 256 bytes
// Khung tháo gỡ #0576 | Địa chỉ PC: 0x0a0fe4 | Địa chỉ FDE: 0x03f980 | Kích thước: 256 bytes
//   0x0a0fe4: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0a0fe8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0a0fec: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0a0ff0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0576_0x0a0fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0fe4ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03f980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0577 | PC: 0x0a10e4 | FDE: 0x03f9a8 | Size: 256 bytes
// Khung tháo gỡ #0577 | Địa chỉ PC: 0x0a10e4 | Địa chỉ FDE: 0x03f9a8 | Kích thước: 256 bytes
//   0x0a10e4: D10243FF  sub      sp, sp, #0x90
//   0x0a10e8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0a10ec: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0a10f0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0577_0x0a10e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a10e4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03f9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0578 | PC: 0x0a1500 | FDE: 0x03f9d8 | Size: 140 bytes
// Khung tháo gỡ #0578 | Địa chỉ PC: 0x0a1500 | Địa chỉ FDE: 0x03f9d8 | Kích thước: 140 bytes
//   0x0a1500: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0a1504: B4000301  cbz      x1, #0xa1564
//   0x0a1508: D2800048  mov      x8, #2
//   0x0a150c: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0578_0x0a1500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1500ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000301ULL) ^ 0x03f9d8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0579 | PC: 0x0a158c | FDE: 0x03f9f0 | Size: 256 bytes
// Khung tháo gỡ #0579 | Địa chỉ PC: 0x0a158c | Địa chỉ FDE: 0x03f9f0 | Kích thước: 256 bytes
//   0x0a158c: D101C3FF  sub      sp, sp, #0x70
//   0x0a1590: F9002BF4  str      x20, [sp, #0x50]
//   0x0a1594: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0a1598: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0579_0x0a158c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a158cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x03f9f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0580 | PC: 0x0a16a4 | FDE: 0x03fa10 | Size: 256 bytes
// Khung tháo gỡ #0580 | Địa chỉ PC: 0x0a16a4 | Địa chỉ FDE: 0x03fa10 | Kích thước: 256 bytes
//   0x0a16a4: D10183FF  sub      sp, sp, #0x60
//   0x0a16a8: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0a16ac: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a16b0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0580_0x0a16a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a16a4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03fa10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0581 | PC: 0x0a18ac | FDE: 0x03fa38 | Size: 256 bytes
// Khung tháo gỡ #0581 | Địa chỉ PC: 0x0a18ac | Địa chỉ FDE: 0x03fa38 | Kích thước: 256 bytes
//   0x0a18ac: D10403FF  sub      sp, sp, #0x100
//   0x0a18b0: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0a18b4: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0a18b8: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0581_0x0a18ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18acULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x03fa38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0582 | PC: 0x0a2288 | FDE: 0x03fa68 | Size: 256 bytes [_Z18js_array_reduce_gcP12LEPUSContext10LEPUSValueiPS1_i]
// Khung tháo gỡ #0582 | Địa chỉ PC: 0x0a2288 | Địa chỉ FDE: 0x03fa68 | Kích thước: 256 bytes
//   0x0a2288: D10383FF  sub      sp, sp, #0xe0
//   0x0a228c: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0a2290: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0a2294: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0582_0x0a2288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2288ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x03fa68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0583 | PC: 0x0a2b48 | FDE: 0x03fa98 | Size: 256 bytes
// Khung tháo gỡ #0583 | Địa chỉ PC: 0x0a2b48 | Địa chỉ FDE: 0x03fa98 | Kích thước: 256 bytes
//   0x0a2b48: D10183FF  sub      sp, sp, #0x60
//   0x0a2b4c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a2b50: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0a2b54: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0583_0x0a2b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2b48ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03fa98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0584 | PC: 0x0a2eb8 | FDE: 0x03fac0 | Size: 256 bytes
// Khung tháo gỡ #0584 | Địa chỉ PC: 0x0a2eb8 | Địa chỉ FDE: 0x03fac0 | Kích thước: 256 bytes
//   0x0a2eb8: D102C3FF  sub      sp, sp, #0xb0
//   0x0a2ebc: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0a2ec0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0a2ec4: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0584_0x0a2eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2eb8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03fac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0585 | PC: 0x0a33fc | FDE: 0x03faf0 | Size: 256 bytes
// Khung tháo gỡ #0585 | Địa chỉ PC: 0x0a33fc | Địa chỉ FDE: 0x03faf0 | Kích thước: 256 bytes
//   0x0a33fc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0a3400: B4000321  cbz      x1, #0xa3464
//   0x0a3404: D2800048  mov      x8, #2
//   0x0a3408: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0585_0x0a33fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a33fcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000321ULL) ^ 0x03faf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0586 | PC: 0x0a35a8 | FDE: 0x03fb08 | Size: 256 bytes
// Khung tháo gỡ #0586 | Địa chỉ PC: 0x0a35a8 | Địa chỉ FDE: 0x03fb08 | Kích thước: 256 bytes
//   0x0a35a8: D102C3FF  sub      sp, sp, #0xb0
//   0x0a35ac: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0a35b0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0a35b4: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0586_0x0a35a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a35a8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03fb08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0587 | PC: 0x0a3a3c | FDE: 0x03fb38 | Size: 256 bytes
// Khung tháo gỡ #0587 | Địa chỉ PC: 0x0a3a3c | Địa chỉ FDE: 0x03fb38 | Kích thước: 256 bytes
//   0x0a3a3c: D10283FF  sub      sp, sp, #0xa0
//   0x0a3a40: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0a3a44: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0a3a48: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0587_0x0a3a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3a3cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03fb38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0588 | PC: 0x0a3e4c | FDE: 0x03fb68 | Size: 256 bytes
// Khung tháo gỡ #0588 | Địa chỉ PC: 0x0a3e4c | Địa chỉ FDE: 0x03fb68 | Kích thước: 256 bytes
//   0x0a3e4c: D102C3FF  sub      sp, sp, #0xb0
//   0x0a3e50: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0a3e54: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0a3e58: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0588_0x0a3e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3e4cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03fb68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0589 | PC: 0x0a4288 | FDE: 0x03fb98 | Size: 256 bytes
// Khung tháo gỡ #0589 | Địa chỉ PC: 0x0a4288 | Địa chỉ FDE: 0x03fb98 | Kích thước: 256 bytes
//   0x0a4288: D10283FF  sub      sp, sp, #0xa0
//   0x0a428c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0a4290: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0a4294: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0589_0x0a4288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4288ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03fb98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0590 | PC: 0x0a47bc | FDE: 0x03fbc8 | Size: 256 bytes
// Khung tháo gỡ #0590 | Địa chỉ PC: 0x0a47bc | Địa chỉ FDE: 0x03fbc8 | Kích thước: 256 bytes
//   0x0a47bc: D10203FF  sub      sp, sp, #0x80
//   0x0a47c0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0a47c4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a47c8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0590_0x0a47bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a47bcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x03fbc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0591 | PC: 0x0a4efc | FDE: 0x03fbf8 | Size: 248 bytes
// Khung tháo gỡ #0591 | Địa chỉ PC: 0x0a4efc | Địa chỉ FDE: 0x03fbf8 | Kích thước: 248 bytes
//   0x0a4efc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0a4f00: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0a4f04: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0a4f08: B9401C08  ldr      w8, [x0, #0x1c]
static inline uint64_t fde_func_0591_0x0a4efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4efcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03fbf8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0592 | PC: 0x0a4ff4 | FDE: 0x03fc18 | Size: 256 bytes
// Khung tháo gỡ #0592 | Địa chỉ PC: 0x0a4ff4 | Địa chỉ FDE: 0x03fc18 | Kích thước: 256 bytes
//   0x0a4ff4: D10183FF  sub      sp, sp, #0x60
//   0x0a4ff8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a4ffc: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0a5000: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0592_0x0a4ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4ff4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03fc18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0593 | PC: 0x0a52b8 | FDE: 0x03fc40 | Size: 16 bytes
// Khung tháo gỡ #0593 | Địa chỉ PC: 0x0a52b8 | Địa chỉ FDE: 0x03fc40 | Kích thước: 16 bytes
//   0x0a52b8: 39400008  ldrb     w8, [x0]
//   0x0a52bc: 39400029  ldrb     w9, [x1]
//   0x0a52c0: 4B090100  sub      w0, w8, w9
//   0x0a52c4: D65F03C0  ret      
static inline uint64_t fde_func_0593_0x0a52b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52b8ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x39400029ULL) ^ 0x03fc40ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0594 | PC: 0x0a52c8 | FDE: 0x03fc58 | Size: 16 bytes
// Khung tháo gỡ #0594 | Địa chỉ PC: 0x0a52c8 | Địa chỉ FDE: 0x03fc58 | Kích thước: 16 bytes
//   0x0a52c8: 39C00008  ldrsb    w8, [x0]
//   0x0a52cc: 39C00029  ldrsb    w9, [x1]
//   0x0a52d0: 4B090100  sub      w0, w8, w9
//   0x0a52d4: D65F03C0  ret      
static inline uint64_t fde_func_0594_0x0a52c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52c8ULL ^ (static_cast<uint64_t>(0x39c00008ULL) << 13);
    acc = (acc + a1 + 0x39c00029ULL) ^ 0x03fc58ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0595 | PC: 0x0a52d8 | FDE: 0x03fc70 | Size: 16 bytes
// Khung tháo gỡ #0595 | Địa chỉ PC: 0x0a52d8 | Địa chỉ FDE: 0x03fc70 | Kích thước: 16 bytes
//   0x0a52d8: 79C00008  ldrsh    w8, [x0]
//   0x0a52dc: 79C00029  ldrsh    w9, [x1]
//   0x0a52e0: 4B090100  sub      w0, w8, w9
//   0x0a52e4: D65F03C0  ret      
static inline uint64_t fde_func_0595_0x0a52d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52d8ULL ^ (static_cast<uint64_t>(0x79c00008ULL) << 13);
    acc = (acc + a1 + 0x79c00029ULL) ^ 0x03fc70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0596 | PC: 0x0a52e8 | FDE: 0x03fc88 | Size: 16 bytes
// Khung tháo gỡ #0596 | Địa chỉ PC: 0x0a52e8 | Địa chỉ FDE: 0x03fc88 | Kích thước: 16 bytes
//   0x0a52e8: 79400008  ldrh     w8, [x0]
//   0x0a52ec: 79400029  ldrh     w9, [x1]
//   0x0a52f0: 4B090100  sub      w0, w8, w9
//   0x0a52f4: D65F03C0  ret      
static inline uint64_t fde_func_0596_0x0a52e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52e8ULL ^ (static_cast<uint64_t>(0x79400008ULL) << 13);
    acc = (acc + a1 + 0x79400029ULL) ^ 0x03fc88ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0597 | PC: 0x0a52f8 | FDE: 0x03fca0 | Size: 28 bytes
// Khung tháo gỡ #0597 | Địa chỉ PC: 0x0a52f8 | Địa chỉ FDE: 0x03fca0 | Kích thước: 28 bytes
//   0x0a52f8: B9400008  ldr      w8, [x0]
//   0x0a52fc: B9400029  ldr      w9, [x1]
//   0x0a5300: 6B08013F  cmp      w9, w8
//   0x0a5304: 1A9FA7E8  cset     w8, lt
static inline uint64_t fde_func_0597_0x0a52f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52f8ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x03fca0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0598 | PC: 0x0a5314 | FDE: 0x03fcb8 | Size: 28 bytes
// Khung tháo gỡ #0598 | Địa chỉ PC: 0x0a5314 | Địa chỉ FDE: 0x03fcb8 | Kích thước: 28 bytes
//   0x0a5314: B9400008  ldr      w8, [x0]
//   0x0a5318: B9400029  ldr      w9, [x1]
//   0x0a531c: 6B08013F  cmp      w9, w8
//   0x0a5320: 1A9F27E8  cset     w8, lo
static inline uint64_t fde_func_0598_0x0a5314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5314ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x03fcb8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0599 | PC: 0x0a5330 | FDE: 0x03fcd0 | Size: 104 bytes
// Khung tháo gỡ #0599 | Địa chỉ PC: 0x0a5330 | Địa chỉ FDE: 0x03fcd0 | Kích thước: 104 bytes
//   0x0a5330: BD400001  ldr      s1, [x0]
//   0x0a5334: BD400020  ldr      s0, [x1]
//   0x0a5338: 1E212020  fcmp     s1, s1
//   0x0a533c: 54000126  b.vs     #0xa5360
static inline uint64_t fde_func_0599_0x0a5330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5330ULL ^ (static_cast<uint64_t>(0xbd400001ULL) << 13);
    acc = (acc + a1 + 0xbd400020ULL) ^ 0x03fcd0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0600 | PC: 0x0a5398 | FDE: 0x03fce8 | Size: 96 bytes
// Khung tháo gỡ #0600 | Địa chỉ PC: 0x0a5398 | Địa chỉ FDE: 0x03fce8 | Kích thước: 96 bytes
//   0x0a5398: FD400001  ldr      d1, [x0]
//   0x0a539c: FD400020  ldr      d0, [x1]
//   0x0a53a0: 1E612020  fcmp     d1, d1
//   0x0a53a4: 54000126  b.vs     #0xa53c8
static inline uint64_t fde_func_0600_0x0a5398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5398ULL ^ (static_cast<uint64_t>(0xfd400001ULL) << 13);
    acc = (acc + a1 + 0xfd400020ULL) ^ 0x03fce8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0601 | PC: 0x0a53f8 | FDE: 0x03fd00 | Size: 28 bytes
// Khung tháo gỡ #0601 | Địa chỉ PC: 0x0a53f8 | Địa chỉ FDE: 0x03fd00 | Kích thước: 28 bytes
//   0x0a53f8: F9400008  ldr      x8, [x0]
//   0x0a53fc: F9400029  ldr      x9, [x1]
//   0x0a5400: EB08013F  cmp      x9, x8
//   0x0a5404: 1A9FA7E8  cset     w8, lt
static inline uint64_t fde_func_0601_0x0a53f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a53f8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400029ULL) ^ 0x03fd00ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0602 | PC: 0x0a5414 | FDE: 0x03fd18 | Size: 28 bytes
// Khung tháo gỡ #0602 | Địa chỉ PC: 0x0a5414 | Địa chỉ FDE: 0x03fd18 | Kích thước: 28 bytes
//   0x0a5414: F9400008  ldr      x8, [x0]
//   0x0a5418: F9400029  ldr      x9, [x1]
//   0x0a541c: EB08013F  cmp      x9, x8
//   0x0a5420: 1A9F27E8  cset     w8, lo
static inline uint64_t fde_func_0602_0x0a5414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5414ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400029ULL) ^ 0x03fd18ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0603 | PC: 0x0a5430 | FDE: 0x03fd30 | Size: 12 bytes
// Khung tháo gỡ #0603 | Địa chỉ PC: 0x0a5430 | Địa chỉ FDE: 0x03fd30 | Kích thước: 12 bytes
//   0x0a5430: 39400028  ldrb     w8, [x1]
//   0x0a5434: B24F3900  orr      x0, x8, #0xfffe000000000000
//   0x0a5438: D65F03C0  ret      
static inline uint64_t fde_func_0603_0x0a5430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5430ULL ^ (static_cast<uint64_t>(0x39400028ULL) << 13);
    acc = (acc + a1 + 0xb24f3900ULL) ^ 0x03fd30ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0604 | PC: 0x0a543c | FDE: 0x03fd48 | Size: 16 bytes
// Khung tháo gỡ #0604 | Địa chỉ PC: 0x0a543c | Địa chỉ FDE: 0x03fd48 | Kích thước: 16 bytes
//   0x0a543c: 39800028  ldrsb    x8, [x1]
//   0x0a5440: D2FFFFC0  mov      x0, #-0x2000000000000
//   0x0a5444: B3407D00  bfxil    x0, x8, #0, #0x20
//   0x0a5448: D65F03C0  ret      
static inline uint64_t fde_func_0604_0x0a543c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a543cULL ^ (static_cast<uint64_t>(0x39800028ULL) << 13);
    acc = (acc + a1 + 0xd2ffffc0ULL) ^ 0x03fd48ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0605 | PC: 0x0a544c | FDE: 0x03fd60 | Size: 16 bytes
// Khung tháo gỡ #0605 | Địa chỉ PC: 0x0a544c | Địa chỉ FDE: 0x03fd60 | Kích thước: 16 bytes
//   0x0a544c: 79800028  ldrsh    x8, [x1]
//   0x0a5450: D2FFFFC0  mov      x0, #-0x2000000000000
//   0x0a5454: B3407D00  bfxil    x0, x8, #0, #0x20
//   0x0a5458: D65F03C0  ret      
static inline uint64_t fde_func_0605_0x0a544c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a544cULL ^ (static_cast<uint64_t>(0x79800028ULL) << 13);
    acc = (acc + a1 + 0xd2ffffc0ULL) ^ 0x03fd60ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0606 | PC: 0x0a545c | FDE: 0x03fd78 | Size: 12 bytes
// Khung tháo gỡ #0606 | Địa chỉ PC: 0x0a545c | Địa chỉ FDE: 0x03fd78 | Kích thước: 12 bytes
//   0x0a545c: 79400028  ldrh     w8, [x1]
//   0x0a5460: B24F3900  orr      x0, x8, #0xfffe000000000000
//   0x0a5464: D65F03C0  ret      
static inline uint64_t fde_func_0606_0x0a545c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a545cULL ^ (static_cast<uint64_t>(0x79400028ULL) << 13);
    acc = (acc + a1 + 0xb24f3900ULL) ^ 0x03fd78ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0607 | PC: 0x0a5468 | FDE: 0x03fd90 | Size: 12 bytes
// Khung tháo gỡ #0607 | Địa chỉ PC: 0x0a5468 | Địa chỉ FDE: 0x03fd90 | Kích thước: 12 bytes
//   0x0a5468: B9400028  ldr      w8, [x1]
//   0x0a546c: B24F3900  orr      x0, x8, #0xfffe000000000000
//   0x0a5470: D65F03C0  ret      
static inline uint64_t fde_func_0607_0x0a5468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5468ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0xb24f3900ULL) ^ 0x03fd90ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0608 | PC: 0x0a5474 | FDE: 0x03fda8 | Size: 36 bytes
// Khung tháo gỡ #0608 | Địa chỉ PC: 0x0a5474 | Địa chỉ FDE: 0x03fda8 | Kích thước: 36 bytes
//   0x0a5474: B9400028  ldr      w8, [x1]
//   0x0a5478: D2E00049  mov      x9, #0x2000000000000
//   0x0a547c: 1E630100  ucvtf    d0, w8
//   0x0a5480: 9E66000B  fmov     x11, d0
static inline uint64_t fde_func_0608_0x0a5474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5474ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0xd2e00049ULL) ^ 0x03fda8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0609 | PC: 0x0a5498 | FDE: 0x03fdc0 | Size: 36 bytes
// Khung tháo gỡ #0609 | Địa chỉ PC: 0x0a5498 | Địa chỉ FDE: 0x03fdc0 | Kích thước: 36 bytes
//   0x0a5498: BD400020  ldr      s0, [x1]
//   0x0a549c: D2E00048  mov      x8, #0x2000000000000
//   0x0a54a0: 1E22C001  fcvt     d1, s0
//   0x0a54a4: 9E660029  fmov     x9, d1
static inline uint64_t fde_func_0609_0x0a5498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5498ULL ^ (static_cast<uint64_t>(0xbd400020ULL) << 13);
    acc = (acc + a1 + 0xd2e00048ULL) ^ 0x03fdc0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0610 | PC: 0x0a54bc | FDE: 0x03fdd8 | Size: 36 bytes
// Khung tháo gỡ #0610 | Địa chỉ PC: 0x0a54bc | Địa chỉ FDE: 0x03fdd8 | Kích thước: 36 bytes
//   0x0a54bc: FD400020  ldr      d0, [x1]
//   0x0a54c0: D2EFFF08  mov      x8, #0x7ff8000000000000
//   0x0a54c4: 9E670101  fmov     d1, x8
//   0x0a54c8: D2E00048  mov      x8, #0x2000000000000
static inline uint64_t fde_func_0610_0x0a54bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a54bcULL ^ (static_cast<uint64_t>(0xfd400020ULL) << 13);
    acc = (acc + a1 + 0xd2efff08ULL) ^ 0x03fdd8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0611 | PC: 0x0a54e0 | FDE: 0x03fdf0 | Size: 152 bytes
// Khung tháo gỡ #0611 | Địa chỉ PC: 0x0a54e0 | Địa chỉ FDE: 0x03fdf0 | Kích thước: 152 bytes
//   0x0a54e0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0a54e4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0a54e8: F9400808  ldr      x8, [x0, #0x10]
//   0x0a54ec: F9400034  ldr      x20, [x1]
static inline uint64_t fde_func_0611_0x0a54e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a54e0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03fdf0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0612 | PC: 0x0a5578 | FDE: 0x03fe10 | Size: 8 bytes
// Khung tháo gỡ #0612 | Địa chỉ PC: 0x0a5578 | Địa chỉ FDE: 0x03fe10 | Kích thước: 8 bytes
//   0x0a5578: F9400021  ldr      x1, [x1]
//   0x0a557c: 17FF3706  b        #0x73194
static inline uint64_t fde_func_0612_0x0a5578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5578ULL ^ (static_cast<uint64_t>(0xf9400021ULL) << 13);
    acc = (acc + a1 + 0x17ff3706ULL) ^ 0x03fe10ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0613 | PC: 0x0a5580 | FDE: 0x03fe28 | Size: 256 bytes
// Khung tháo gỡ #0613 | Địa chỉ PC: 0x0a5580 | Địa chỉ FDE: 0x03fe28 | Kích thước: 256 bytes
//   0x0a5580: D10183FF  sub      sp, sp, #0x60
//   0x0a5584: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a5588: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0a558c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0613_0x0a5580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5580ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x03fe28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0614 | PC: 0x0a5734 | FDE: 0x03fe50 | Size: 256 bytes
// Khung tháo gỡ #0614 | Địa chỉ PC: 0x0a5734 | Địa chỉ FDE: 0x03fe50 | Kích thước: 256 bytes
//   0x0a5734: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0a5738: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0a573c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0a5740: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0614_0x0a5734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5734ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03fe50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0615 | PC: 0x0a588c | FDE: 0x03fe78 | Size: 256 bytes [_Z17JS_HasProperty_GCP12LEPUSContext10LEPUSValuej]
// Khung tháo gỡ #0615 | Địa chỉ PC: 0x0a588c | Địa chỉ FDE: 0x03fe78 | Kích thước: 256 bytes
//   0x0a588c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0a5890: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0a5894: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0a5898: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0615_0x0a588c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a588cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03fe78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0616 | PC: 0x0a5a48 | FDE: 0x03fea0 | Size: 256 bytes
// Khung tháo gỡ #0616 | Địa chỉ PC: 0x0a5a48 | Địa chỉ FDE: 0x03fea0 | Kích thước: 256 bytes
//   0x0a5a48: D10283FF  sub      sp, sp, #0xa0
//   0x0a5a4c: F90043F4  str      x20, [sp, #0x80]
//   0x0a5a50: A9097BF3  stp      x19, x30, [sp, #0x90]
//   0x0a5a54: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0616_0x0a5a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5a48ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90043f4ULL) ^ 0x03fea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0617 | PC: 0x0a5cac | FDE: 0x03fec0 | Size: 256 bytes
// Khung tháo gỡ #0617 | Địa chỉ PC: 0x0a5cac | Địa chỉ FDE: 0x03fec0 | Kích thước: 256 bytes
//   0x0a5cac: D10143FF  sub      sp, sp, #0x50
//   0x0a5cb0: F90013F6  str      x22, [sp, #0x20]
//   0x0a5cb4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0a5cb8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0617_0x0a5cac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5cacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x03fec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0618 | PC: 0x0a5dc8 | FDE: 0x03fee0 | Size: 256 bytes [_Z13JS_IsArray_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0618 | Địa chỉ PC: 0x0a5dc8 | Địa chỉ FDE: 0x03fee0 | Kích thước: 256 bytes
//   0x0a5dc8: D10283FF  sub      sp, sp, #0xa0
//   0x0a5dcc: F9002BF9  str      x25, [sp, #0x50]
//   0x0a5dd0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0a5dd4: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0618_0x0a5dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5dc8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x03fee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0619 | PC: 0x0a5f48 | FDE: 0x03ff08 | Size: 256 bytes
// Khung tháo gỡ #0619 | Địa chỉ PC: 0x0a5f48 | Địa chỉ FDE: 0x03ff08 | Kích thước: 256 bytes
//   0x0a5f48: D101C3FF  sub      sp, sp, #0x70
//   0x0a5f4c: F90013FA  str      x26, [sp, #0x20]
//   0x0a5f50: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0a5f54: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0619_0x0a5f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5f48ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x03ff08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0620 | PC: 0x0a6148 | FDE: 0x03ff30 | Size: 256 bytes
// Khung tháo gỡ #0620 | Địa chỉ PC: 0x0a6148 | Địa chỉ FDE: 0x03ff30 | Kích thước: 256 bytes
//   0x0a6148: D10183FF  sub      sp, sp, #0x60
//   0x0a614c: F90013F8  str      x24, [sp, #0x20]
//   0x0a6150: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0a6154: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0620_0x0a6148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6148ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x03ff30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0621 | PC: 0x0a6358 | FDE: 0x03ff58 | Size: 256 bytes
// Khung tháo gỡ #0621 | Địa chỉ PC: 0x0a6358 | Địa chỉ FDE: 0x03ff58 | Kích thước: 256 bytes
//   0x0a6358: D10383FF  sub      sp, sp, #0xe0
//   0x0a635c: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0a6360: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0a6364: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0621_0x0a6358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6358ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x03ff58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0622 | PC: 0x0a67a4 | FDE: 0x03ff88 | Size: 72 bytes
// Khung tháo gỡ #0622 | Địa chỉ PC: 0x0a67a4 | Địa chỉ FDE: 0x03ff88 | Kích thước: 72 bytes
//   0x0a67a4: F9400068  ldr      x8, [x3]
//   0x0a67a8: 528000C0  mov      w0, #6
//   0x0a67ac: B40001E8  cbz      x8, #0xa67e8
//   0x0a67b0: D2800049  mov      x9, #2
static inline uint64_t fde_func_0622_0x0a67a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a67a4ULL ^ (static_cast<uint64_t>(0xf9400068ULL) << 13);
    acc = (acc + a1 + 0x528000c0ULL) ^ 0x03ff88ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0623 | PC: 0x0a67ec | FDE: 0x03ffa0 | Size: 256 bytes
// Khung tháo gỡ #0623 | Địa chỉ PC: 0x0a67ec | Địa chỉ FDE: 0x03ffa0 | Kích thước: 256 bytes
//   0x0a67ec: D10383FF  sub      sp, sp, #0xe0
//   0x0a67f0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0a67f4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0a67f8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0623_0x0a67ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a67ecULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x03ffa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0624 | PC: 0x0a7018 | FDE: 0x03ffd0 | Size: 256 bytes
// Khung tháo gỡ #0624 | Địa chỉ PC: 0x0a7018 | Địa chỉ FDE: 0x03ffd0 | Kích thước: 256 bytes
//   0x0a7018: D10343FF  sub      sp, sp, #0xd0
//   0x0a701c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0a7020: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0a7024: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0624_0x0a7018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7018ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x03ffd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0625 | PC: 0x0a76b4 | FDE: 0x040000 | Size: 256 bytes
// Khung tháo gỡ #0625 | Địa chỉ PC: 0x0a76b4 | Địa chỉ FDE: 0x040000 | Kích thước: 256 bytes
//   0x0a76b4: D10283FF  sub      sp, sp, #0xa0
//   0x0a76b8: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0a76bc: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0a76c0: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0625_0x0a76b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a76b4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x040000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0626 | PC: 0x0a78cc | FDE: 0x040030 | Size: 256 bytes
// Khung tháo gỡ #0626 | Địa chỉ PC: 0x0a78cc | Địa chỉ FDE: 0x040030 | Kích thước: 256 bytes
//   0x0a78cc: D102C3FF  sub      sp, sp, #0xb0
//   0x0a78d0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0a78d4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0a78d8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0626_0x0a78cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a78ccULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x040030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0627 | PC: 0x0a7b8c | FDE: 0x040060 | Size: 256 bytes
// Khung tháo gỡ #0627 | Địa chỉ PC: 0x0a7b8c | Địa chỉ FDE: 0x040060 | Kích thước: 256 bytes
//   0x0a7b8c: D102C3FF  sub      sp, sp, #0xb0
//   0x0a7b90: F9002BFC  str      x28, [sp, #0x50]
//   0x0a7b94: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x0a7b98: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_0627_0x0a7b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7b8cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x040060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0628 | PC: 0x0a7db8 | FDE: 0x040090 | Size: 256 bytes
// Khung tháo gỡ #0628 | Địa chỉ PC: 0x0a7db8 | Địa chỉ FDE: 0x040090 | Kích thước: 256 bytes
//   0x0a7db8: D101C3FF  sub      sp, sp, #0x70
//   0x0a7dbc: F9002BF4  str      x20, [sp, #0x50]
//   0x0a7dc0: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0a7dc4: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0628_0x0a7db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7db8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x040090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0629 | PC: 0x0a7f38 | FDE: 0x0400b0 | Size: 220 bytes
// Khung tháo gỡ #0629 | Địa chỉ PC: 0x0a7f38 | Địa chỉ FDE: 0x0400b0 | Kích thước: 220 bytes
//   0x0a7f38: D101C3FF  sub      sp, sp, #0x70
//   0x0a7f3c: F9002BF4  str      x20, [sp, #0x50]
//   0x0a7f40: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0a7f44: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0629_0x0a7f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7f38ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0400b0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0630 | PC: 0x0a8014 | FDE: 0x0400d0 | Size: 256 bytes
// Khung tháo gỡ #0630 | Địa chỉ PC: 0x0a8014 | Địa chỉ FDE: 0x0400d0 | Kích thước: 256 bytes
//   0x0a8014: D10303FF  sub      sp, sp, #0xc0
//   0x0a8018: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0a801c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0a8020: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0630_0x0a8014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8014ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0400d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0631 | PC: 0x0a849c | FDE: 0x040100 | Size: 256 bytes
// Khung tháo gỡ #0631 | Địa chỉ PC: 0x0a849c | Địa chỉ FDE: 0x040100 | Kích thước: 256 bytes
//   0x0a849c: D10283FF  sub      sp, sp, #0xa0
//   0x0a84a0: F9002BFA  str      x26, [sp, #0x50]
//   0x0a84a4: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0a84a8: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0631_0x0a849c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a849cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x040100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0632 | PC: 0x0a8668 | FDE: 0x040128 | Size: 256 bytes
// Khung tháo gỡ #0632 | Địa chỉ PC: 0x0a8668 | Địa chỉ FDE: 0x040128 | Kích thước: 256 bytes
//   0x0a8668: D10283FF  sub      sp, sp, #0xa0
//   0x0a866c: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0a8670: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x0a8674: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0632_0x0a8668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8668ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x040128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0633 | PC: 0x0a8924 | FDE: 0x040150 | Size: 256 bytes
// Khung tháo gỡ #0633 | Địa chỉ PC: 0x0a8924 | Địa chỉ FDE: 0x040150 | Kích thước: 256 bytes
//   0x0a8924: D10203FF  sub      sp, sp, #0x80
//   0x0a8928: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0a892c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a8930: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0633_0x0a8924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8924ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x040150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0634 | PC: 0x0a8b08 | FDE: 0x040180 | Size: 256 bytes
// Khung tháo gỡ #0634 | Địa chỉ PC: 0x0a8b08 | Địa chỉ FDE: 0x040180 | Kích thước: 256 bytes
//   0x0a8b08: D10443FF  sub      sp, sp, #0x110
//   0x0a8b0c: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0a8b10: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0a8b14: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0634_0x0a8b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8b08ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x040180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0635 | PC: 0x0a9260 | FDE: 0x0401b0 | Size: 256 bytes
// Khung tháo gỡ #0635 | Địa chỉ PC: 0x0a9260 | Địa chỉ FDE: 0x0401b0 | Kích thước: 256 bytes
//   0x0a9260: D10183FF  sub      sp, sp, #0x60
//   0x0a9264: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0a9268: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0a926c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0635_0x0a9260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9260ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0401b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0636 | PC: 0x0a95b8 | FDE: 0x0401d8 | Size: 256 bytes
// Khung tháo gỡ #0636 | Địa chỉ PC: 0x0a95b8 | Địa chỉ FDE: 0x0401d8 | Kích thước: 256 bytes
//   0x0a95b8: D10143FF  sub      sp, sp, #0x50
//   0x0a95bc: F90013F6  str      x22, [sp, #0x20]
//   0x0a95c0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0a95c4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0636_0x0a95b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a95b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0401d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0637 | PC: 0x0a97ac | FDE: 0x0401f8 | Size: 88 bytes
// Khung tháo gỡ #0637 | Địa chỉ PC: 0x0a97ac | Địa chỉ FDE: 0x0401f8 | Kích thước: 88 bytes
//   0x0a97ac: F94000A8  ldr      x8, [x5]
//   0x0a97b0: B4000268  cbz      x8, #0xa97fc
//   0x0a97b4: D2800049  mov      x9, #2
//   0x0a97b8: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_0637_0x0a97ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a97acULL ^ (static_cast<uint64_t>(0xf94000a8ULL) << 13);
    acc = (acc + a1 + 0xb4000268ULL) ^ 0x0401f8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0638 | PC: 0x0a9804 | FDE: 0x040210 | Size: 256 bytes
// Khung tháo gỡ #0638 | Địa chỉ PC: 0x0a9804 | Địa chỉ FDE: 0x040210 | Kích thước: 256 bytes
//   0x0a9804: D103C3FF  sub      sp, sp, #0xf0
//   0x0a9808: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0a980c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0a9810: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0638_0x0a9804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9804ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x040210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0639 | PC: 0x0a9d54 | FDE: 0x040240 | Size: 256 bytes
// Khung tháo gỡ #0639 | Địa chỉ PC: 0x0a9d54 | Địa chỉ FDE: 0x040240 | Kích thước: 256 bytes
//   0x0a9d54: D103C3FF  sub      sp, sp, #0xf0
//   0x0a9d58: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0a9d5c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0a9d60: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0639_0x0a9d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9d54ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x040240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0640 | PC: 0x0aa49c | FDE: 0x040270 | Size: 256 bytes
// Khung tháo gỡ #0640 | Địa chỉ PC: 0x0aa49c | Địa chỉ FDE: 0x040270 | Kích thước: 256 bytes
//   0x0aa49c: D10343FF  sub      sp, sp, #0xd0
//   0x0aa4a0: F9003BFB  str      x27, [sp, #0x70]
//   0x0aa4a4: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0aa4a8: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0640_0x0aa49c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa49cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x040270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0641 | PC: 0x0aa960 | FDE: 0x0402a0 | Size: 256 bytes
// Khung tháo gỡ #0641 | Địa chỉ PC: 0x0aa960 | Địa chỉ FDE: 0x0402a0 | Kích thước: 256 bytes
//   0x0aa960: D10483FF  sub      sp, sp, #0x120
//   0x0aa964: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0aa968: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0aa96c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0641_0x0aa960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa960ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0402a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0642 | PC: 0x0ab128 | FDE: 0x0402d0 | Size: 256 bytes
// Khung tháo gỡ #0642 | Địa chỉ PC: 0x0ab128 | Địa chỉ FDE: 0x0402d0 | Kích thước: 256 bytes
//   0x0ab128: D10303FF  sub      sp, sp, #0xc0
//   0x0ab12c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0ab130: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0ab134: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0642_0x0ab128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab128ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x0402d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0643 | PC: 0x0ab5c4 | FDE: 0x040300 | Size: 256 bytes
// Khung tháo gỡ #0643 | Địa chỉ PC: 0x0ab5c4 | Địa chỉ FDE: 0x040300 | Kích thước: 256 bytes
//   0x0ab5c4: D10403FF  sub      sp, sp, #0x100
//   0x0ab5c8: F90053FB  str      x27, [sp, #0xa0]
//   0x0ab5cc: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0ab5d0: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0643_0x0ab5c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab5c4ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90053fbULL) ^ 0x040300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0644 | PC: 0x0abb10 | FDE: 0x040330 | Size: 256 bytes
// Khung tháo gỡ #0644 | Địa chỉ PC: 0x0abb10 | Địa chỉ FDE: 0x040330 | Kích thước: 256 bytes
//   0x0abb10: D103C3FF  sub      sp, sp, #0xf0
//   0x0abb14: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0abb18: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0abb1c: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0644_0x0abb10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abb10ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x040330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0645 | PC: 0x0ac0cc | FDE: 0x040360 | Size: 256 bytes
// Khung tháo gỡ #0645 | Địa chỉ PC: 0x0ac0cc | Địa chỉ FDE: 0x040360 | Kích thước: 256 bytes
//   0x0ac0cc: D10303FF  sub      sp, sp, #0xc0
//   0x0ac0d0: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x0ac0d4: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x0ac0d8: A9095BF7  stp      x23, x22, [sp, #0x90]
static inline uint64_t fde_func_0645_0x0ac0cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac0ccULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9076bfbULL) ^ 0x040360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0646 | PC: 0x0ac3c4 | FDE: 0x040390 | Size: 256 bytes [_ZN10PtrHandles27PushLEPUSPropertyDescriptorEP23LEPUSPropertyDescriptor]
// Khung tháo gỡ #0646 | Địa chỉ PC: 0x0ac3c4 | Địa chỉ FDE: 0x040390 | Kích thước: 256 bytes
//   0x0ac3c4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0ac3c8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ac3cc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ac3d0: 52800248  mov      w8, #0x12
static inline uint64_t fde_func_0646_0x0ac3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac3c4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x040390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0647 | PC: 0x0ac4dc | FDE: 0x0403b0 | Size: 256 bytes
// Khung tháo gỡ #0647 | Địa chỉ PC: 0x0ac4dc | Địa chỉ FDE: 0x0403b0 | Kích thước: 256 bytes
//   0x0ac4dc: D10383FF  sub      sp, sp, #0xe0
//   0x0ac4e0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0ac4e4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0ac4e8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0647_0x0ac4dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac4dcULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0403b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0648 | PC: 0x0acfcc | FDE: 0x0403e0 | Size: 256 bytes
// Khung tháo gỡ #0648 | Địa chỉ PC: 0x0acfcc | Địa chỉ FDE: 0x0403e0 | Kích thước: 256 bytes
//   0x0acfcc: B9400408  ldr      w8, [x0, #4]
//   0x0acfd0: B9400429  ldr      w9, [x1, #4]
//   0x0acfd4: 37F801E8  tbnz     w8, #0x1f, #0xad010
//   0x0acfd8: F940084A  ldr      x10, [x2, #0x10]
static inline uint64_t fde_func_0648_0x0acfcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acfccULL ^ (static_cast<uint64_t>(0xb9400408ULL) << 13);
    acc = (acc + a1 + 0xb9400429ULL) ^ 0x0403e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0649 | PC: 0x0ad170 | FDE: 0x0403f8 | Size: 256 bytes
// Khung tháo gỡ #0649 | Địa chỉ PC: 0x0ad170 | Địa chỉ FDE: 0x0403f8 | Kích thước: 256 bytes
//   0x0ad170: D101C3FF  sub      sp, sp, #0x70
//   0x0ad174: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x0ad178: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0ad17c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0649_0x0ad170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad170ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x0403f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0650 | PC: 0x0ad5c8 | FDE: 0x040420 | Size: 172 bytes
// Khung tháo gỡ #0650 | Địa chỉ PC: 0x0ad5c8 | Địa chỉ FDE: 0x040420 | Kích thước: 172 bytes
//   0x0ad5c8: D100C3FF  sub      sp, sp, #0x30
//   0x0ad5cc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ad5d0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ad5d4: B4000481  cbz      x1, #0xad664
static inline uint64_t fde_func_0650_0x0ad5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad5c8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x040420ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0651 | PC: 0x0ad674 | FDE: 0x040440 | Size: 256 bytes
// Khung tháo gỡ #0651 | Địa chỉ PC: 0x0ad674 | Địa chỉ FDE: 0x040440 | Kích thước: 256 bytes
//   0x0ad674: D101C3FF  sub      sp, sp, #0x70
//   0x0ad678: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0ad67c: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x0ad680: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_0651_0x0ad674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad674ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90363f9ULL) ^ 0x040440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0652 | PC: 0x0ad930 | FDE: 0x040468 | Size: 256 bytes
// Khung tháo gỡ #0652 | Địa chỉ PC: 0x0ad930 | Địa chỉ FDE: 0x040468 | Kích thước: 256 bytes
//   0x0ad930: D10503FF  sub      sp, sp, #0x140
//   0x0ad934: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0ad938: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0ad93c: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_0652_0x0ad930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad930ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x040468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0653 | PC: 0x0ae598 | FDE: 0x040498 | Size: 256 bytes
// Khung tháo gỡ #0653 | Địa chỉ PC: 0x0ae598 | Địa chỉ FDE: 0x040498 | Kích thước: 256 bytes
//   0x0ae598: D10243FF  sub      sp, sp, #0x90
//   0x0ae59c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0ae5a0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0ae5a4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0653_0x0ae598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae598ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x040498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0654 | PC: 0x0ae8f8 | FDE: 0x0404c8 | Size: 256 bytes
// Khung tháo gỡ #0654 | Địa chỉ PC: 0x0ae8f8 | Địa chỉ FDE: 0x0404c8 | Kích thước: 256 bytes
//   0x0ae8f8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0ae8fc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0ae900: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ae904: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0654_0x0ae8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae8f8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0404c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0655 | PC: 0x0aeba4 | FDE: 0x0404f0 | Size: 256 bytes
// Khung tháo gỡ #0655 | Địa chỉ PC: 0x0aeba4 | Địa chỉ FDE: 0x0404f0 | Kích thước: 256 bytes
//   0x0aeba4: D101C3FF  sub      sp, sp, #0x70
//   0x0aeba8: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x0aebac: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0aebb0: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0655_0x0aeba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeba4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x0404f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0656 | PC: 0x0aeec4 | FDE: 0x040518 | Size: 256 bytes
// Khung tháo gỡ #0656 | Địa chỉ PC: 0x0aeec4 | Địa chỉ FDE: 0x040518 | Kích thước: 256 bytes
//   0x0aeec4: D10443FF  sub      sp, sp, #0x110
//   0x0aeec8: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0aeecc: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0aeed0: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0656_0x0aeec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeec4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x040518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0657 | PC: 0x0b0168 | FDE: 0x040548 | Size: 256 bytes
// Khung tháo gỡ #0657 | Địa chỉ PC: 0x0b0168 | Địa chỉ FDE: 0x040548 | Kích thước: 256 bytes
//   0x0b0168: D10203FF  sub      sp, sp, #0x80
//   0x0b016c: FD0013E8  str      d8, [sp, #0x20]
//   0x0b0170: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0b0174: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0657_0x0b0168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0168ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x040548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0658 | PC: 0x0b03a4 | FDE: 0x040578 | Size: 256 bytes
// Khung tháo gỡ #0658 | Địa chỉ PC: 0x0b03a4 | Địa chỉ FDE: 0x040578 | Kích thước: 256 bytes
//   0x0b03a4: D104C3FF  sub      sp, sp, #0x130
//   0x0b03a8: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0b03ac: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0b03b0: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0658_0x0b03a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b03a4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x040578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0659 | PC: 0x0b0a20 | FDE: 0x0405a8 | Size: 256 bytes
// Khung tháo gỡ #0659 | Địa chỉ PC: 0x0b0a20 | Địa chỉ FDE: 0x0405a8 | Kích thước: 256 bytes
//   0x0b0a20: D10243FF  sub      sp, sp, #0x90
//   0x0b0a24: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0b0a28: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0b0a2c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0659_0x0b0a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0a20ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0405a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0660 | PC: 0x0b0ee8 | FDE: 0x0405d8 | Size: 256 bytes
// Khung tháo gỡ #0660 | Địa chỉ PC: 0x0b0ee8 | Địa chỉ FDE: 0x0405d8 | Kích thước: 256 bytes
//   0x0b0ee8: D10283FF  sub      sp, sp, #0xa0
//   0x0b0eec: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0b0ef0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0b0ef4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0660_0x0b0ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0ee8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0405d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0661 | PC: 0x0b1258 | FDE: 0x040608 | Size: 256 bytes [_Z20JS_DeleteProperty_GCP12LEPUSContext10LEPUSValueji]
// Khung tháo gỡ #0661 | Địa chỉ PC: 0x0b1258 | Địa chỉ FDE: 0x040608 | Kích thước: 256 bytes
//   0x0b1258: D10143FF  sub      sp, sp, #0x50
//   0x0b125c: F9000BF8  str      x24, [sp, #0x10]
//   0x0b1260: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0b1264: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0661_0x0b1258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1258ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x040608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0662 | PC: 0x0b1388 | FDE: 0x040630 | Size: 256 bytes
// Khung tháo gỡ #0662 | Địa chỉ PC: 0x0b1388 | Địa chỉ FDE: 0x040630 | Kích thước: 256 bytes
//   0x0b1388: D10443FF  sub      sp, sp, #0x110
//   0x0b138c: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0b1390: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0b1394: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0662_0x0b1388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1388ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x040630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0663 | PC: 0x0b1988 | FDE: 0x040660 | Size: 256 bytes
// Khung tháo gỡ #0663 | Địa chỉ PC: 0x0b1988 | Địa chỉ FDE: 0x040660 | Kích thước: 256 bytes
//   0x0b1988: D10283FF  sub      sp, sp, #0xa0
//   0x0b198c: F90033F8  str      x24, [sp, #0x60]
//   0x0b1990: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0b1994: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_0663_0x0b1988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1988ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f8ULL) ^ 0x040660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0664 | PC: 0x0b1b5c | FDE: 0x040688 | Size: 256 bytes
// Khung tháo gỡ #0664 | Địa chỉ PC: 0x0b1b5c | Địa chỉ FDE: 0x040688 | Kích thước: 256 bytes
//   0x0b1b5c: D10203FF  sub      sp, sp, #0x80
//   0x0b1b60: F90013FC  str      x28, [sp, #0x20]
//   0x0b1b64: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0b1b68: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0664_0x0b1b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1b5cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x040688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0665 | PC: 0x0b1f48 | FDE: 0x0406b8 | Size: 256 bytes
// Khung tháo gỡ #0665 | Địa chỉ PC: 0x0b1f48 | Địa chỉ FDE: 0x0406b8 | Kích thước: 256 bytes
//   0x0b1f48: D102C3FF  sub      sp, sp, #0xb0
//   0x0b1f4c: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x0b1f50: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x0b1f54: A90953F5  stp      x21, x20, [sp, #0x90]
static inline uint64_t fde_func_0665_0x0b1f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1f48ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90763f9ULL) ^ 0x0406b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0666 | PC: 0x0b2330 | FDE: 0x0406e0 | Size: 256 bytes
// Khung tháo gỡ #0666 | Địa chỉ PC: 0x0b2330 | Địa chỉ FDE: 0x0406e0 | Kích thước: 256 bytes
//   0x0b2330: D10103FF  sub      sp, sp, #0x40
//   0x0b2334: F9000BF6  str      x22, [sp, #0x10]
//   0x0b2338: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b233c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0666_0x0b2330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2330ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0406e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0667 | PC: 0x0b2494 | FDE: 0x040700 | Size: 256 bytes
// Khung tháo gỡ #0667 | Địa chỉ PC: 0x0b2494 | Địa chỉ FDE: 0x040700 | Kích thước: 256 bytes
//   0x0b2494: D10443FF  sub      sp, sp, #0x110
//   0x0b2498: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0b249c: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0b24a0: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0667_0x0b2494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2494ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x040700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0668 | PC: 0x0b2c5c | FDE: 0x040730 | Size: 256 bytes
// Khung tháo gỡ #0668 | Địa chỉ PC: 0x0b2c5c | Địa chỉ FDE: 0x040730 | Kích thước: 256 bytes
//   0x0b2c5c: D10143FF  sub      sp, sp, #0x50
//   0x0b2c60: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0b2c64: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0b2c68: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0668_0x0b2c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2c5cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x040730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0669 | PC: 0x0b2e9c | FDE: 0x040750 | Size: 256 bytes
// Khung tháo gỡ #0669 | Địa chỉ PC: 0x0b2e9c | Địa chỉ FDE: 0x040750 | Kích thước: 256 bytes
//   0x0b2e9c: D10183FF  sub      sp, sp, #0x60
//   0x0b2ea0: F90013F8  str      x24, [sp, #0x20]
//   0x0b2ea4: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0b2ea8: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0669_0x0b2e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2e9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x040750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0670 | PC: 0x0b32f8 | FDE: 0x040778 | Size: 256 bytes
// Khung tháo gỡ #0670 | Địa chỉ PC: 0x0b32f8 | Địa chỉ FDE: 0x040778 | Kích thước: 256 bytes
//   0x0b32f8: D10283FF  sub      sp, sp, #0xa0
//   0x0b32fc: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0b3300: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0b3304: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0670_0x0b32f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b32f8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x040778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0671 | PC: 0x0b37ec | FDE: 0x0407a8 | Size: 256 bytes
// Khung tháo gỡ #0671 | Địa chỉ PC: 0x0b37ec | Địa chỉ FDE: 0x0407a8 | Kích thước: 256 bytes
//   0x0b37ec: D10203FF  sub      sp, sp, #0x80
//   0x0b37f0: F9002BF6  str      x22, [sp, #0x50]
//   0x0b37f4: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0b37f8: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0671_0x0b37ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b37ecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0407a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0672 | PC: 0x0b38ec | FDE: 0x0407c8 | Size: 256 bytes
// Khung tháo gỡ #0672 | Địa chỉ PC: 0x0b38ec | Địa chỉ FDE: 0x0407c8 | Kích thước: 256 bytes
//   0x0b38ec: D102C3FF  sub      sp, sp, #0xb0
//   0x0b38f0: F90033FA  str      x26, [sp, #0x60]
//   0x0b38f4: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x0b38f8: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0672_0x0b38ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b38ecULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033faULL) ^ 0x0407c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0673 | PC: 0x0b3b6c | FDE: 0x0407f0 | Size: 40 bytes
// Khung tháo gỡ #0673 | Địa chỉ PC: 0x0b3b6c | Địa chỉ FDE: 0x0407f0 | Kích thước: 40 bytes
//   0x0b3b6c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0b3b70: F9400062  ldr      x2, [x3]
//   0x0b3b74: 97FFF9EF  bl       #0xb2330
//   0x0b3b78: F102081F  cmp      x0, #0x82
static inline uint64_t fde_func_0673_0x0b3b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3b6cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x0407f0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0674 | PC: 0x0b3b94 | FDE: 0x040808 | Size: 256 bytes
// Khung tháo gỡ #0674 | Địa chỉ PC: 0x0b3b94 | Địa chỉ FDE: 0x040808 | Kích thước: 256 bytes
//   0x0b3b94: D10203FF  sub      sp, sp, #0x80
//   0x0b3b98: F90023F8  str      x24, [sp, #0x40]
//   0x0b3b9c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x0b3ba0: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0674_0x0b3b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3b94ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x040808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x0b3f94 | FDE: 0x040830 | Size: 256 bytes
// Khung tháo gỡ #0675 | Địa chỉ PC: 0x0b3f94 | Địa chỉ FDE: 0x040830 | Kích thước: 256 bytes
//   0x0b3f94: D10783FF  sub      sp, sp, #0x1e0
//   0x0b3f98: FD00BBE8  str      d8, [sp, #0x170]
//   0x0b3f9c: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x0b3fa0: A91967FA  stp      x26, x25, [sp, #0x190]
static inline uint64_t fde_func_0675_0x0b3f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3f94ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xfd00bbe8ULL) ^ 0x040830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0676 | PC: 0x0b5788 | FDE: 0x040860 | Size: 256 bytes
// Khung tháo gỡ #0676 | Địa chỉ PC: 0x0b5788 | Địa chỉ FDE: 0x040860 | Kích thước: 256 bytes
//   0x0b5788: D10283FF  sub      sp, sp, #0xa0
//   0x0b578c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0b5790: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0b5794: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0676_0x0b5788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5788ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x040860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0677 | PC: 0x0b5c80 | FDE: 0x040890 | Size: 256 bytes
// Khung tháo gỡ #0677 | Địa chỉ PC: 0x0b5c80 | Địa chỉ FDE: 0x040890 | Kích thước: 256 bytes
//   0x0b5c80: D10243FF  sub      sp, sp, #0x90
//   0x0b5c84: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0b5c88: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x0b5c8c: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0677_0x0b5c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5c80ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90563f9ULL) ^ 0x040890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0678 | PC: 0x0b627c | FDE: 0x0408b8 | Size: 256 bytes
// Khung tháo gỡ #0678 | Địa chỉ PC: 0x0b627c | Địa chỉ FDE: 0x0408b8 | Kích thước: 256 bytes
//   0x0b627c: D10183FF  sub      sp, sp, #0x60
//   0x0b6280: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0b6284: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0b6288: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0678_0x0b627c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b627cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0408b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0679 | PC: 0x0b65bc | FDE: 0x0408d8 | Size: 256 bytes
// Khung tháo gỡ #0679 | Địa chỉ PC: 0x0b65bc | Địa chỉ FDE: 0x0408d8 | Kích thước: 256 bytes
//   0x0b65bc: D10483FF  sub      sp, sp, #0x120
//   0x0b65c0: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0b65c4: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0b65c8: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0679_0x0b65bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b65bcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0408d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0680 | PC: 0x0b6fe4 | FDE: 0x040908 | Size: 256 bytes
// Khung tháo gỡ #0680 | Địa chỉ PC: 0x0b6fe4 | Địa chỉ FDE: 0x040908 | Kích thước: 256 bytes
//   0x0b6fe4: D10143FF  sub      sp, sp, #0x50
//   0x0b6fe8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0b6fec: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0b6ff0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0680_0x0b6fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6fe4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x040908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0681 | PC: 0x0b71f4 | FDE: 0x040930 | Size: 256 bytes
// Khung tháo gỡ #0681 | Địa chỉ PC: 0x0b71f4 | Địa chỉ FDE: 0x040930 | Kích thước: 256 bytes
//   0x0b71f4: D10383FF  sub      sp, sp, #0xe0
//   0x0b71f8: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0b71fc: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0b7200: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0681_0x0b71f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b71f4ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x040930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0682 | PC: 0x0b7af4 | FDE: 0x040960 | Size: 256 bytes
// Khung tháo gỡ #0682 | Địa chỉ PC: 0x0b7af4 | Địa chỉ FDE: 0x040960 | Kích thước: 256 bytes
//   0x0b7af4: D101C3FF  sub      sp, sp, #0x70
//   0x0b7af8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0b7afc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0b7b00: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0682_0x0b7af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7af4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x040960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0683 | PC: 0x0b7da8 | FDE: 0x040990 | Size: 256 bytes
// Khung tháo gỡ #0683 | Địa chỉ PC: 0x0b7da8 | Địa chỉ FDE: 0x040990 | Kích thước: 256 bytes
//   0x0b7da8: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x0b7dac: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0b7db0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0b7db4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0683_0x0b7da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7da8ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x040990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0684 | PC: 0x0b7f8c | FDE: 0x0409b8 | Size: 252 bytes
// Khung tháo gỡ #0684 | Địa chỉ PC: 0x0b7f8c | Địa chỉ FDE: 0x0409b8 | Kích thước: 252 bytes
//   0x0b7f8c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b7f90: B9401808  ldr      w8, [x0, #0x18]
//   0x0b7f94: AA0003F3  mov      x19, x0
//   0x0b7f98: 3100D51F  cmn      w8, #0x35
static inline uint64_t fde_func_0684_0x0b7f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7f8cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9401808ULL) ^ 0x0409b8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0685 | PC: 0x0b8088 | FDE: 0x0409d0 | Size: 256 bytes
// Khung tháo gỡ #0685 | Địa chỉ PC: 0x0b8088 | Địa chỉ FDE: 0x0409d0 | Kích thước: 256 bytes
//   0x0b8088: D10143FF  sub      sp, sp, #0x50
//   0x0b808c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0b8090: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0b8094: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0685_0x0b8088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8088ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0409d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0686 | PC: 0x0b8210 | FDE: 0x0409f8 | Size: 256 bytes [js_closure_gc]
// Khung tháo gỡ #0686 | Địa chỉ PC: 0x0b8210 | Địa chỉ FDE: 0x0409f8 | Kích thước: 256 bytes
//   0x0b8210: D102C3FF  sub      sp, sp, #0xb0
//   0x0b8214: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x0b8218: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x0b821c: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0686_0x0b8210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8210ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9066bfbULL) ^ 0x0409f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0687 | PC: 0x0b8524 | FDE: 0x040a28 | Size: 256 bytes
// Khung tháo gỡ #0687 | Địa chỉ PC: 0x0b8524 | Địa chỉ FDE: 0x040a28 | Kích thước: 256 bytes
//   0x0b8524: D10143FF  sub      sp, sp, #0x50
//   0x0b8528: F90013F6  str      x22, [sp, #0x20]
//   0x0b852c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0b8530: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0687_0x0b8524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8524ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x040a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0688 | PC: 0x0b8664 | FDE: 0x040a48 | Size: 256 bytes
// Khung tháo gỡ #0688 | Địa chỉ PC: 0x0b8664 | Địa chỉ FDE: 0x040a48 | Kích thước: 256 bytes
//   0x0b8664: D10403FF  sub      sp, sp, #0x100
//   0x0b8668: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0b866c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0b8670: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0688_0x0b8664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8664ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x040a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0689 | PC: 0x0ba40c | FDE: 0x040a78 | Size: 256 bytes
// Khung tháo gỡ #0689 | Địa chỉ PC: 0x0ba40c | Địa chỉ FDE: 0x040a78 | Kích thước: 256 bytes
//   0x0ba40c: D10583FF  sub      sp, sp, #0x160
//   0x0ba410: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x0ba414: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x0ba418: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_0689_0x0ba40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba40cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x040a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0690 | PC: 0x0be93c | FDE: 0x040aa8 | Size: 256 bytes
// Khung tháo gỡ #0690 | Địa chỉ PC: 0x0be93c | Địa chỉ FDE: 0x040aa8 | Kích thước: 256 bytes
//   0x0be93c: D103C3FF  sub      sp, sp, #0xf0
//   0x0be940: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0be944: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0be948: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0690_0x0be93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be93cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x040aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0691 | PC: 0x0c0678 | FDE: 0x040ad8 | Size: 256 bytes
// Khung tháo gỡ #0691 | Địa chỉ PC: 0x0c0678 | Địa chỉ FDE: 0x040ad8 | Kích thước: 256 bytes
//   0x0c0678: D10343FF  sub      sp, sp, #0xd0
//   0x0c067c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0c0680: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0c0684: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0691_0x0c0678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0678ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x040ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0692 | PC: 0x0c2458 | FDE: 0x040b08 | Size: 256 bytes
// Khung tháo gỡ #0692 | Địa chỉ PC: 0x0c2458 | Địa chỉ FDE: 0x040b08 | Kích thước: 256 bytes
//   0x0c2458: D101C3FF  sub      sp, sp, #0x70
//   0x0c245c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0c2460: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0c2464: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0692_0x0c2458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2458ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x040b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0693 | PC: 0x0c2ae4 | FDE: 0x040b38 | Size: 256 bytes
// Khung tháo gỡ #0693 | Địa chỉ PC: 0x0c2ae4 | Địa chỉ FDE: 0x040b38 | Kích thước: 256 bytes
//   0x0c2ae4: D10103FF  sub      sp, sp, #0x40
//   0x0c2ae8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c2aec: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c2af0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0693_0x0c2ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2ae4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x040b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0694 | PC: 0x0c2e6c | FDE: 0x040b58 | Size: 256 bytes
// Khung tháo gỡ #0694 | Địa chỉ PC: 0x0c2e6c | Địa chỉ FDE: 0x040b58 | Kích thước: 256 bytes
//   0x0c2e6c: D10183FF  sub      sp, sp, #0x60
//   0x0c2e70: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0c2e74: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0c2e78: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0694_0x0c2e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2e6cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x040b58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0695 | PC: 0x0c328c | FDE: 0x040b80 | Size: 256 bytes
// Khung tháo gỡ #0695 | Địa chỉ PC: 0x0c328c | Địa chỉ FDE: 0x040b80 | Kích thước: 256 bytes
//   0x0c328c: D10143FF  sub      sp, sp, #0x50
//   0x0c3290: F9000BF8  str      x24, [sp, #0x10]
//   0x0c3294: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0c3298: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0695_0x0c328c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c328cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x040b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x0c35f0 | FDE: 0x040ba8 | Size: 256 bytes
// Khung tháo gỡ #0696 | Địa chỉ PC: 0x0c35f0 | Địa chỉ FDE: 0x040ba8 | Kích thước: 256 bytes
//   0x0c35f0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0c35f4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0c35f8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0c35fc: 7100187F  cmp      w3, #6
static inline uint64_t fde_func_0696_0x0c35f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c35f0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x040ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0697 | PC: 0x0c3b0c | FDE: 0x040bc8 | Size: 256 bytes
// Khung tháo gỡ #0697 | Địa chỉ PC: 0x0c3b0c | Địa chỉ FDE: 0x040bc8 | Kích thước: 256 bytes
//   0x0c3b0c: D10343FF  sub      sp, sp, #0xd0
//   0x0c3b10: FD0033E8  str      d8, [sp, #0x60]
//   0x0c3b14: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0c3b18: A90867FA  stp      x26, x25, [sp, #0x80]
static inline uint64_t fde_func_0697_0x0c3b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3b0cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xfd0033e8ULL) ^ 0x040bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0698 | PC: 0x0c41d4 | FDE: 0x040bf8 | Size: 108 bytes
// Khung tháo gỡ #0698 | Địa chỉ PC: 0x0c41d4 | Địa chỉ FDE: 0x040bf8 | Kích thước: 108 bytes
//   0x0c41d4: D10083FF  sub      sp, sp, #0x20
//   0x0c41d8: F9000BFE  str      x30, [sp, #0x10]
//   0x0c41dc: 910003E0  mov      x0, sp
//   0x0c41e0: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_0698_0x0c41d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c41d4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x040bf8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0699 | PC: 0x0c4240 | FDE: 0x040c10 | Size: 256 bytes
// Khung tháo gỡ #0699 | Địa chỉ PC: 0x0c4240 | Địa chỉ FDE: 0x040c10 | Kích thước: 256 bytes
//   0x0c4240: D10483FF  sub      sp, sp, #0x120
//   0x0c4244: F9006BFC  str      x28, [sp, #0xd0]
//   0x0c4248: A90E63F9  stp      x25, x24, [sp, #0xe0]
//   0x0c424c: A90F5BF7  stp      x23, x22, [sp, #0xf0]
static inline uint64_t fde_func_0699_0x0c4240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4240ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x040c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0700 | PC: 0x0c5018 | FDE: 0x040c38 | Size: 256 bytes
// Khung tháo gỡ #0700 | Địa chỉ PC: 0x0c5018 | Địa chỉ FDE: 0x040c38 | Kích thước: 256 bytes
//   0x0c5018: D10283FF  sub      sp, sp, #0xa0
//   0x0c501c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0c5020: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0c5024: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0700_0x0c5018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5018ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x040c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0701 | PC: 0x0c51bc | FDE: 0x040c68 | Size: 256 bytes
// Khung tháo gỡ #0701 | Địa chỉ PC: 0x0c51bc | Địa chỉ FDE: 0x040c68 | Kích thước: 256 bytes
//   0x0c51bc: D10243FF  sub      sp, sp, #0x90
//   0x0c51c0: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x0c51c4: F90033F6  str      x22, [sp, #0x60]
//   0x0c51c8: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0701_0x0c51bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c51bcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0x6d0523e9ULL) ^ 0x040c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0702 | PC: 0x0c5500 | FDE: 0x040c90 | Size: 256 bytes
// Khung tháo gỡ #0702 | Địa chỉ PC: 0x0c5500 | Địa chỉ FDE: 0x040c90 | Kích thước: 256 bytes
//   0x0c5500: F8404008  ldur     x8, [x0, #4]
//   0x0c5504: B940002C  ldr      w12, [x1]
//   0x0c5508: 12007909  and      w9, w8, #0x7fffffff
//   0x0c550c: 6B09019F  cmp      w12, w9
static inline uint64_t fde_func_0702_0x0c5500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5500ULL ^ (static_cast<uint64_t>(0xf8404008ULL) << 13);
    acc = (acc + a1 + 0xb940002cULL) ^ 0x040c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0703 | PC: 0x0c562c | FDE: 0x040ca8 | Size: 256 bytes
// Khung tháo gỡ #0703 | Địa chỉ PC: 0x0c562c | Địa chỉ FDE: 0x040ca8 | Kích thước: 256 bytes
//   0x0c562c: D10483FF  sub      sp, sp, #0x120
//   0x0c5630: FD0053EC  str      d12, [sp, #0xa0]
//   0x0c5634: 6D0AABEB  stp      d11, d10, [sp, #0xa8]
//   0x0c5638: 6D0BA3E9  stp      d9, d8, [sp, #0xb8]
static inline uint64_t fde_func_0703_0x0c562c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c562cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xfd0053ecULL) ^ 0x040ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0704 | PC: 0x0c5a64 | FDE: 0x040ce8 | Size: 256 bytes
// Khung tháo gỡ #0704 | Địa chỉ PC: 0x0c5a64 | Địa chỉ FDE: 0x040ce8 | Kích thước: 256 bytes
//   0x0c5a64: D10203FF  sub      sp, sp, #0x80
//   0x0c5a68: F9002BF6  str      x22, [sp, #0x50]
//   0x0c5a6c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0c5a70: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0704_0x0c5a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5a64ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x040ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0705 | PC: 0x0c5fd0 | FDE: 0x040d08 | Size: 256 bytes
// Khung tháo gỡ #0705 | Địa chỉ PC: 0x0c5fd0 | Địa chỉ FDE: 0x040d08 | Kích thước: 256 bytes
//   0x0c5fd0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c5fd4: B4000721  cbz      x1, #0xc60b8
//   0x0c5fd8: D2800048  mov      x8, #2
//   0x0c5fdc: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0705_0x0c5fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5fd0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000721ULL) ^ 0x040d08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0706 | PC: 0x0c60d0 | FDE: 0x040d20 | Size: 196 bytes
// Khung tháo gỡ #0706 | Địa chỉ PC: 0x0c60d0 | Địa chỉ FDE: 0x040d20 | Kích thước: 196 bytes
//   0x0c60d0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0c60d4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c60d8: AA0003F3  mov      x19, x0
//   0x0c60dc: B4000401  cbz      x1, #0xc615c
static inline uint64_t fde_func_0706_0x0c60d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c60d0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x040d20ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0707 | PC: 0x0c6194 | FDE: 0x040d40 | Size: 256 bytes
// Khung tháo gỡ #0707 | Địa chỉ PC: 0x0c6194 | Địa chỉ FDE: 0x040d40 | Kích thước: 256 bytes
//   0x0c6194: D10183FF  sub      sp, sp, #0x60
//   0x0c6198: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x0c619c: D53BD053  mrs      x19, tpidr_el0
//   0x0c61a0: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_0707_0x0c6194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6194ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9057bf3ULL) ^ 0x040d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0708 | PC: 0x0c6320 | FDE: 0x040d58 | Size: 244 bytes
// Khung tháo gỡ #0708 | Địa chỉ PC: 0x0c6320 | Địa chỉ FDE: 0x040d58 | Kích thước: 244 bytes
//   0x0c6320: D101C3FF  sub      sp, sp, #0x70
//   0x0c6324: F9002BF4  str      x20, [sp, #0x50]
//   0x0c6328: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0c632c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0708_0x0c6320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6320ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x040d58ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0709 | PC: 0x0c6414 | FDE: 0x040d78 | Size: 256 bytes
// Khung tháo gỡ #0709 | Địa chỉ PC: 0x0c6414 | Địa chỉ FDE: 0x040d78 | Kích thước: 256 bytes
//   0x0c6414: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0c6418: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0c641c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0c6420: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0709_0x0c6414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6414ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x040d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0710 | PC: 0x0c658c | FDE: 0x040d98 | Size: 256 bytes
// Khung tháo gỡ #0710 | Địa chỉ PC: 0x0c658c | Địa chỉ FDE: 0x040d98 | Kích thước: 256 bytes
//   0x0c658c: D10303FF  sub      sp, sp, #0xc0
//   0x0c6590: F90033FC  str      x28, [sp, #0x60]
//   0x0c6594: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x0c6598: A90863F9  stp      x25, x24, [sp, #0x80]
static inline uint64_t fde_func_0710_0x0c658c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c658cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fcULL) ^ 0x040d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0711 | PC: 0x0c6730 | FDE: 0x040dc8 | Size: 256 bytes
// Khung tháo gỡ #0711 | Địa chỉ PC: 0x0c6730 | Địa chỉ FDE: 0x040dc8 | Kích thước: 256 bytes
//   0x0c6730: D10143FF  sub      sp, sp, #0x50
//   0x0c6734: F90013F6  str      x22, [sp, #0x20]
//   0x0c6738: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0c673c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0711_0x0c6730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6730ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x040dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0712 | PC: 0x0c68f8 | FDE: 0x040de8 | Size: 256 bytes
// Khung tháo gỡ #0712 | Địa chỉ PC: 0x0c68f8 | Địa chỉ FDE: 0x040de8 | Kích thước: 256 bytes
//   0x0c68f8: D10203FF  sub      sp, sp, #0x80
//   0x0c68fc: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0c6900: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x0c6904: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0712_0x0c68f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c68f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90463f9ULL) ^ 0x040de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0713 | PC: 0x0c6cd0 | FDE: 0x040e10 | Size: 28 bytes
// Khung tháo gỡ #0713 | Địa chỉ PC: 0x0c6cd0 | Địa chỉ FDE: 0x040e10 | Kích thước: 28 bytes
//   0x0c6cd0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c6cd4: 90FFFB61  adrp     x1, #0x32000
//   0x0c6cd8: 9139DC21  add      x1, x1, #0xe77
//   0x0c6cdc: 9400C8D6  bl       #0xf9034
static inline uint64_t fde_func_0713_0x0c6cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6cd0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x90fffb61ULL) ^ 0x040e10ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0714 | PC: 0x0c6cec | FDE: 0x040e28 | Size: 144 bytes
// Khung tháo gỡ #0714 | Địa chỉ PC: 0x0c6cec | Địa chỉ FDE: 0x040e28 | Kích thước: 144 bytes
//   0x0c6cec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c6cf0: B4000341  cbz      x1, #0xc6d58
//   0x0c6cf4: D2800048  mov      x8, #2
//   0x0c6cf8: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0714_0x0c6cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6cecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000341ULL) ^ 0x040e28ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0715 | PC: 0x0c6d7c | FDE: 0x040e40 | Size: 256 bytes
// Khung tháo gỡ #0715 | Địa chỉ PC: 0x0c6d7c | Địa chỉ FDE: 0x040e40 | Kích thước: 256 bytes
//   0x0c6d7c: D10283FF  sub      sp, sp, #0xa0
//   0x0c6d80: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0c6d84: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0c6d88: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0715_0x0c6d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6d7cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x040e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0716 | PC: 0x0c7014 | FDE: 0x040e70 | Size: 188 bytes
// Khung tháo gỡ #0716 | Địa chỉ PC: 0x0c7014 | Địa chỉ FDE: 0x040e70 | Kích thước: 188 bytes
//   0x0c7014: F100483F  cmp      x1, #0x12
//   0x0c7018: 54000240  b.eq     #0xc7060
//   0x0c701c: D00007A8  adrp     x8, #0x1bd000
//   0x0c7020: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_0716_0x0c7014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7014ULL ^ (static_cast<uint64_t>(0xf100483fULL) << 13);
    acc = (acc + a1 + 0x54000240ULL) ^ 0x040e70ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0717 | PC: 0x0c70d0 | FDE: 0x040e88 | Size: 256 bytes
// Khung tháo gỡ #0717 | Địa chỉ PC: 0x0c70d0 | Địa chỉ FDE: 0x040e88 | Kích thước: 256 bytes
//   0x0c70d0: D101C3FF  sub      sp, sp, #0x70
//   0x0c70d4: F90013FA  str      x26, [sp, #0x20]
//   0x0c70d8: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0c70dc: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0717_0x0c70d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c70d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x040e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0718 | PC: 0x0c73d4 | FDE: 0x040eb0 | Size: 256 bytes
// Khung tháo gỡ #0718 | Địa chỉ PC: 0x0c73d4 | Địa chỉ FDE: 0x040eb0 | Kích thước: 256 bytes
//   0x0c73d4: D10183FF  sub      sp, sp, #0x60
//   0x0c73d8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0c73dc: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0c73e0: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0718_0x0c73d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c73d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x040eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0719 | PC: 0x0c7590 | FDE: 0x040ed8 | Size: 256 bytes
// Khung tháo gỡ #0719 | Địa chỉ PC: 0x0c7590 | Địa chỉ FDE: 0x040ed8 | Kích thước: 256 bytes
//   0x0c7590: D102C3FF  sub      sp, sp, #0xb0
//   0x0c7594: F90033FA  str      x26, [sp, #0x60]
//   0x0c7598: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x0c759c: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0719_0x0c7590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7590ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033faULL) ^ 0x040ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0720 | PC: 0x0c78c8 | FDE: 0x040f00 | Size: 256 bytes
// Khung tháo gỡ #0720 | Địa chỉ PC: 0x0c78c8 | Địa chỉ FDE: 0x040f00 | Kích thước: 256 bytes
//   0x0c78c8: D10103FF  sub      sp, sp, #0x40
//   0x0c78cc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c78d0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c78d4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0720_0x0c78c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c78c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x040f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0721 | PC: 0x0c7a50 | FDE: 0x040f20 | Size: 256 bytes
// Khung tháo gỡ #0721 | Địa chỉ PC: 0x0c7a50 | Địa chỉ FDE: 0x040f20 | Kích thước: 256 bytes
//   0x0c7a50: D10183FF  sub      sp, sp, #0x60
//   0x0c7a54: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0c7a58: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0c7a5c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0721_0x0c7a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7a50ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x040f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0722 | PC: 0x0c7b94 | FDE: 0x040f40 | Size: 36 bytes [_Z2gcP12LEPUSContext10LEPUSValueiPS1_]
// Khung tháo gỡ #0722 | Địa chỉ PC: 0x0c7b94 | Địa chỉ FDE: 0x040f40 | Kích thước: 36 bytes
//   0x0c7b94: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c7b98: F9400808  ldr      x8, [x0, #0x10]
//   0x0c7b9c: AA1F03E1  mov      x1, xzr
//   0x0c7ba0: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_0722_0x0c7b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7b94ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400808ULL) ^ 0x040f40ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0723 | PC: 0x0c7bb8 | FDE: 0x040f58 | Size: 256 bytes
// Khung tháo gỡ #0723 | Địa chỉ PC: 0x0c7bb8 | Địa chỉ FDE: 0x040f58 | Kích thước: 256 bytes
//   0x0c7bb8: D103C3FF  sub      sp, sp, #0xf0
//   0x0c7bbc: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0c7bc0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0c7bc4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0723_0x0c7bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7bb8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x040f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0724 | PC: 0x0c81d4 | FDE: 0x040f88 | Size: 256 bytes
// Khung tháo gỡ #0724 | Địa chỉ PC: 0x0c81d4 | Địa chỉ FDE: 0x040f88 | Kích thước: 256 bytes
//   0x0c81d4: D10103FF  sub      sp, sp, #0x40
//   0x0c81d8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c81dc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c81e0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0724_0x0c81d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c81d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x040f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0725 | PC: 0x0c8328 | FDE: 0x040fa8 | Size: 120 bytes
// Khung tháo gỡ #0725 | Địa chỉ PC: 0x0c8328 | Địa chỉ FDE: 0x040fa8 | Kích thước: 120 bytes
//   0x0c8328: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c832c: F9400069  ldr      x9, [x3]
//   0x0c8330: D2800028  mov      x8, #1
//   0x0c8334: F2E00028  movk     x8, #1, lsl #48
static inline uint64_t fde_func_0725_0x0c8328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8328ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400069ULL) ^ 0x040fa8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0726 | PC: 0x0c83a0 | FDE: 0x040fc0 | Size: 256 bytes
// Khung tháo gỡ #0726 | Địa chỉ PC: 0x0c83a0 | Địa chỉ FDE: 0x040fc0 | Kích thước: 256 bytes
//   0x0c83a0: D10103FF  sub      sp, sp, #0x40
//   0x0c83a4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c83a8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0c83ac: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0726_0x0c83a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c83a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x040fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0727 | PC: 0x0c84d8 | FDE: 0x040fe0 | Size: 120 bytes
// Khung tháo gỡ #0727 | Địa chỉ PC: 0x0c84d8 | Địa chỉ FDE: 0x040fe0 | Kích thước: 120 bytes
//   0x0c84d8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c84dc: D2800028  mov      x8, #1
//   0x0c84e0: F2E00028  movk     x8, #1, lsl #48
//   0x0c84e4: 92504429  and      x9, x1, #0xffff000000000003
static inline uint64_t fde_func_0727_0x0c84d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c84d8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd2800028ULL) ^ 0x040fe0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0728 | PC: 0x0c8550 | FDE: 0x040ff8 | Size: 256 bytes
// Khung tháo gỡ #0728 | Địa chỉ PC: 0x0c8550 | Địa chỉ FDE: 0x040ff8 | Kích thước: 256 bytes
//   0x0c8550: D10203FF  sub      sp, sp, #0x80
//   0x0c8554: F9002BF6  str      x22, [sp, #0x50]
//   0x0c8558: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0c855c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0728_0x0c8550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8550ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x040ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0729 | PC: 0x0c8774 | FDE: 0x041018 | Size: 12 bytes
// Khung tháo gỡ #0729 | Địa chỉ PC: 0x0c8774 | Địa chỉ FDE: 0x041018 | Kích thước: 12 bytes
//   0x0c8774: F8408461  ldr      x1, [x3], #8
//   0x0c8778: 2A1F03E4  mov      w4, wzr
//   0x0c877c: 17FFBA1A  b        #0xb6fe4
static inline uint64_t fde_func_0729_0x0c8774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8774ULL ^ (static_cast<uint64_t>(0xf8408461ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e4ULL) ^ 0x041018ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0730 | PC: 0x0c8780 | FDE: 0x041030 | Size: 256 bytes
// Khung tháo gỡ #0730 | Địa chỉ PC: 0x0c8780 | Địa chỉ FDE: 0x041030 | Kích thước: 256 bytes
//   0x0c8780: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0c8784: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c8788: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c878c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0730_0x0c8780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8780ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x041030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0731 | PC: 0x0c8898 | FDE: 0x041058 | Size: 256 bytes
// Khung tháo gỡ #0731 | Địa chỉ PC: 0x0c8898 | Địa chỉ FDE: 0x041058 | Kích thước: 256 bytes
//   0x0c8898: D10283FF  sub      sp, sp, #0xa0
//   0x0c889c: F90023FC  str      x28, [sp, #0x40]
//   0x0c88a0: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0c88a4: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_0731_0x0c8898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8898ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fcULL) ^ 0x041058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0732 | PC: 0x0c8b84 | FDE: 0x041088 | Size: 256 bytes
// Khung tháo gỡ #0732 | Địa chỉ PC: 0x0c8b84 | Địa chỉ FDE: 0x041088 | Kích thước: 256 bytes
//   0x0c8b84: D10243FF  sub      sp, sp, #0x90
//   0x0c8b88: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x0c8b8c: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0c8b90: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0732_0x0c8b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8b84ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x041088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0733 | PC: 0x0c8ee4 | FDE: 0x0410b8 | Size: 252 bytes
// Khung tháo gỡ #0733 | Địa chỉ PC: 0x0c8ee4 | Địa chỉ FDE: 0x0410b8 | Kích thước: 252 bytes
//   0x0c8ee4: D10103FF  sub      sp, sp, #0x40
//   0x0c8ee8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c8eec: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c8ef0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0733_0x0c8ee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8ee4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0410b8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0734 | PC: 0x0c8fe0 | FDE: 0x0410d8 | Size: 256 bytes
// Khung tháo gỡ #0734 | Địa chỉ PC: 0x0c8fe0 | Địa chỉ FDE: 0x0410d8 | Kích thước: 256 bytes
//   0x0c8fe0: D10143FF  sub      sp, sp, #0x50
//   0x0c8fe4: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0c8fe8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0c8fec: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0734_0x0c8fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8fe0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0410d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0735 | PC: 0x0c9164 | FDE: 0x041100 | Size: 68 bytes
// Khung tháo gỡ #0735 | Địa chỉ PC: 0x0c9164 | Địa chỉ FDE: 0x041100 | Kích thước: 68 bytes
//   0x0c9164: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c9168: F9400061  ldr      x1, [x3]
//   0x0c916c: B4000121  cbz      x1, #0xc9190
//   0x0c9170: D2800048  mov      x8, #2
static inline uint64_t fde_func_0735_0x0c9164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9164ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400061ULL) ^ 0x041100ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0736 | PC: 0x0c91a8 | FDE: 0x041118 | Size: 256 bytes
// Khung tháo gỡ #0736 | Địa chỉ PC: 0x0c91a8 | Địa chỉ FDE: 0x041118 | Kích thước: 256 bytes
//   0x0c91a8: D10143FF  sub      sp, sp, #0x50
//   0x0c91ac: F9000BF8  str      x24, [sp, #0x10]
//   0x0c91b0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0c91b4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0736_0x0c91a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c91a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x041118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0737 | PC: 0x0c9320 | FDE: 0x041140 | Size: 256 bytes [_Z23JS_PreventExtensions_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0737 | Địa chỉ PC: 0x0c9320 | Địa chỉ FDE: 0x041140 | Kích thước: 256 bytes
//   0x0c9320: D10283FF  sub      sp, sp, #0xa0
//   0x0c9324: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0c9328: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0c932c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0737_0x0c9320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9320ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x041140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0738 | PC: 0x0c965c | FDE: 0x041168 | Size: 256 bytes
// Khung tháo gỡ #0738 | Địa chỉ PC: 0x0c965c | Địa chỉ FDE: 0x041168 | Kích thước: 256 bytes
//   0x0c965c: D10203FF  sub      sp, sp, #0x80
//   0x0c9660: FD001BE8  str      d8, [sp, #0x30]
//   0x0c9664: F9001FFA  str      x26, [sp, #0x38]
//   0x0c9668: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0738_0x0c965c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c965cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xfd001be8ULL) ^ 0x041168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0739 | PC: 0x0c99e4 | FDE: 0x041198 | Size: 92 bytes
// Khung tháo gỡ #0739 | Địa chỉ PC: 0x0c99e4 | Địa chỉ FDE: 0x041198 | Kích thước: 92 bytes
//   0x0c99e4: 9E660008  fmov     x8, d0
//   0x0c99e8: D374F909  ubfx     x9, x8, #0x34, #0xb
//   0x0c99ec: 710FF93F  cmp      w9, #0x3fe
//   0x0c99f0: 54000108  b.hi     #0xc9a10
static inline uint64_t fde_func_0739_0x0c99e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c99e4ULL ^ (static_cast<uint64_t>(0x9e660008ULL) << 13);
    acc = (acc + a1 + 0xd374f909ULL) ^ 0x041198ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0740 | PC: 0x0c9a40 | FDE: 0x0411b0 | Size: 72 bytes [_Z6js_powdd]
// Khung tháo gỡ #0740 | Địa chỉ PC: 0x0c9a40 | Địa chỉ FDE: 0x0411b0 | Kích thước: 72 bytes
//   0x0c9a40: 6DBE23E9  stp      d9, d8, [sp, #-0x20]!
//   0x0c9a44: F9000BFE  str      x30, [sp, #0x10]
//   0x0c9a48: 4EA01C08  mov      v8.16b, v0.16b
//   0x0c9a4c: 1E60C029  fabs     d9, d1
static inline uint64_t fde_func_0740_0x0c9a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9a40ULL ^ (static_cast<uint64_t>(0x6dbe23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x0411b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0741 | PC: 0x0c9a88 | FDE: 0x0411d0 | Size: 28 bytes
// Khung tháo gỡ #0741 | Địa chỉ PC: 0x0c9a88 | Địa chỉ FDE: 0x0411d0 | Kích thước: 28 bytes
//   0x0c9a88: 1E602008  fcmp     d0, #0.0
//   0x0c9a8c: 1E6E1001  fmov     d1, #1.00000000
//   0x0c9a90: 1E7E1002  fmov     d2, #-1.00000000
//   0x0c9a94: 1E614C41  fcsel    d1, d2, d1, mi
static inline uint64_t fde_func_0741_0x0c9a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9a88ULL ^ (static_cast<uint64_t>(0x1e602008ULL) << 13);
    acc = (acc + a1 + 0x1e6e1001ULL) ^ 0x0411d0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0742 | PC: 0x0c9aa4 | FDE: 0x0411e8 | Size: 256 bytes
// Khung tháo gỡ #0742 | Địa chỉ PC: 0x0c9aa4 | Địa chỉ FDE: 0x0411e8 | Kích thước: 256 bytes
//   0x0c9aa4: D10103FF  sub      sp, sp, #0x40
//   0x0c9aa8: FD000BE8  str      d8, [sp, #0x10]
//   0x0c9aac: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c9ab0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0742_0x0c9aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9aa4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x0411e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0743 | PC: 0x0c9bc0 | FDE: 0x041208 | Size: 12 bytes
// Khung tháo gỡ #0743 | Địa chỉ PC: 0x0c9bc0 | Địa chỉ FDE: 0x041208 | Kích thước: 12 bytes
//   0x0c9bc0: 1E624000  fcvt     s0, d0
//   0x0c9bc4: 1E22C000  fcvt     d0, s0
//   0x0c9bc8: D65F03C0  ret      
static inline uint64_t fde_func_0743_0x0c9bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9bc0ULL ^ (static_cast<uint64_t>(0x1e624000ULL) << 13);
    acc = (acc + a1 + 0x1e22c000ULL) ^ 0x041208ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0744 | PC: 0x0c9bcc | FDE: 0x041220 | Size: 84 bytes
// Khung tháo gỡ #0744 | Địa chỉ PC: 0x0c9bcc | Địa chỉ FDE: 0x041220 | Kích thước: 84 bytes
//   0x0c9bcc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0c9bd0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c9bd4: F9400062  ldr      x2, [x3]
//   0x0c9bd8: 910033E1  add      x1, sp, #0xc
static inline uint64_t fde_func_0744_0x0c9bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9bccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x041220ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0745 | PC: 0x0c9c20 | FDE: 0x041240 | Size: 52 bytes
// Khung tháo gỡ #0745 | Địa chỉ PC: 0x0c9c20 | Địa chỉ FDE: 0x041240 | Kích thước: 52 bytes
//   0x0c9c20: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0c9c24: F9400062  ldr      x2, [x3]
//   0x0c9c28: 910033E1  add      x1, sp, #0xc
//   0x0c9c2c: 97FEE5A3  bl       #0x832b8
static inline uint64_t fde_func_0745_0x0c9c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9c20ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x041240ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0746 | PC: 0x0c9c54 | FDE: 0x041258 | Size: 256 bytes
// Khung tháo gỡ #0746 | Địa chỉ PC: 0x0c9c54 | Địa chỉ FDE: 0x041258 | Kích thước: 256 bytes
//   0x0c9c54: D10243FF  sub      sp, sp, #0x90
//   0x0c9c58: F9002BF8  str      x24, [sp, #0x50]
//   0x0c9c5c: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x0c9c60: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0746_0x0c9c54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9c54ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf8ULL) ^ 0x041258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0747 | PC: 0x0c9ee0 | FDE: 0x041280 | Size: 256 bytes
// Khung tháo gỡ #0747 | Địa chỉ PC: 0x0c9ee0 | Địa chỉ FDE: 0x041280 | Kích thước: 256 bytes
//   0x0c9ee0: D10183FF  sub      sp, sp, #0x60
//   0x0c9ee4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0c9ee8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0c9eec: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0747_0x0c9ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9ee0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x041280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0748 | PC: 0x0ca0a8 | FDE: 0x0412a8 | Size: 256 bytes
// Khung tháo gỡ #0748 | Địa chỉ PC: 0x0ca0a8 | Địa chỉ FDE: 0x0412a8 | Kích thước: 256 bytes
//   0x0ca0a8: D101C3FF  sub      sp, sp, #0x70
//   0x0ca0ac: F90013FA  str      x26, [sp, #0x20]
//   0x0ca0b0: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0ca0b4: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0748_0x0ca0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca0a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x0412a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x0ca3c4 | FDE: 0x0412d0 | Size: 256 bytes
// Khung tháo gỡ #0749 | Địa chỉ PC: 0x0ca3c4 | Địa chỉ FDE: 0x0412d0 | Kích thước: 256 bytes
//   0x0ca3c4: D10143FF  sub      sp, sp, #0x50
//   0x0ca3c8: F9000BF8  str      x24, [sp, #0x10]
//   0x0ca3cc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0ca3d0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0749_0x0ca3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca3c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x0412d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0750 | PC: 0x0ca4e8 | FDE: 0x0412f8 | Size: 256 bytes
// Khung tháo gỡ #0750 | Địa chỉ PC: 0x0ca4e8 | Địa chỉ FDE: 0x0412f8 | Kích thước: 256 bytes
//   0x0ca4e8: D10183FF  sub      sp, sp, #0x60
//   0x0ca4ec: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0ca4f0: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0ca4f4: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0750_0x0ca4e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca4e8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x0412f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0751 | PC: 0x0ca694 | FDE: 0x041320 | Size: 256 bytes
// Khung tháo gỡ #0751 | Địa chỉ PC: 0x0ca694 | Địa chỉ FDE: 0x041320 | Kích thước: 256 bytes
//   0x0ca694: D10243FF  sub      sp, sp, #0x90
//   0x0ca698: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0ca69c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0ca6a0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0751_0x0ca694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca694ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x041320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0752 | PC: 0x0ca9b4 | FDE: 0x041350 | Size: 256 bytes
// Khung tháo gỡ #0752 | Địa chỉ PC: 0x0ca9b4 | Địa chỉ FDE: 0x041350 | Kích thước: 256 bytes
//   0x0ca9b4: D10203FF  sub      sp, sp, #0x80
//   0x0ca9b8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0ca9bc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ca9c0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0752_0x0ca9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca9b4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x041350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0753 | PC: 0x0cad0c | FDE: 0x041380 | Size: 256 bytes
// Khung tháo gỡ #0753 | Địa chỉ PC: 0x0cad0c | Địa chỉ FDE: 0x041380 | Kích thước: 256 bytes
//   0x0cad0c: D10243FF  sub      sp, sp, #0x90
//   0x0cad10: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0cad14: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x0cad18: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0753_0x0cad0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cad0cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90563f9ULL) ^ 0x041380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0754 | PC: 0x0cb19c | FDE: 0x0413a8 | Size: 256 bytes
// Khung tháo gỡ #0754 | Địa chỉ PC: 0x0cb19c | Địa chỉ FDE: 0x0413a8 | Kích thước: 256 bytes
//   0x0cb19c: D10383FF  sub      sp, sp, #0xe0
//   0x0cb1a0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0cb1a4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0cb1a8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0754_0x0cb19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb19cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0413a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0755 | PC: 0x0cb784 | FDE: 0x0413d8 | Size: 256 bytes
// Khung tháo gỡ #0755 | Địa chỉ PC: 0x0cb784 | Địa chỉ FDE: 0x0413d8 | Kích thước: 256 bytes
//   0x0cb784: D101C3FF  sub      sp, sp, #0x70
//   0x0cb788: F90013FA  str      x26, [sp, #0x20]
//   0x0cb78c: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0cb790: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0755_0x0cb784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb784ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x0413d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0756 | PC: 0x0cb948 | FDE: 0x041400 | Size: 256 bytes
// Khung tháo gỡ #0756 | Địa chỉ PC: 0x0cb948 | Địa chỉ FDE: 0x041400 | Kích thước: 256 bytes
//   0x0cb948: D101C3FF  sub      sp, sp, #0x70
//   0x0cb94c: F90013FA  str      x26, [sp, #0x20]
//   0x0cb950: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0cb954: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0756_0x0cb948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb948ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x041400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0757 | PC: 0x0cbb08 | FDE: 0x041428 | Size: 256 bytes
// Khung tháo gỡ #0757 | Địa chỉ PC: 0x0cbb08 | Địa chỉ FDE: 0x041428 | Kích thước: 256 bytes
//   0x0cbb08: D101C3FF  sub      sp, sp, #0x70
//   0x0cbb0c: F90013FA  str      x26, [sp, #0x20]
//   0x0cbb10: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0cbb14: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0757_0x0cbb08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbb08ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x041428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 379: return fde_func_0379_0x08136c(a0, a1);
        case 380: return fde_func_0380_0x081900(a0, a1);
        case 381: return fde_func_0381_0x081b58(a0, a1);
        case 382: return fde_func_0382_0x081e90(a0, a1);
        case 383: return fde_func_0383_0x08211c(a0, a1);
        case 384: return fde_func_0384_0x082540(a0, a1);
        case 385: return fde_func_0385_0x082904(a0, a1);
        case 386: return fde_func_0386_0x082acc(a0, a1);
        case 387: return fde_func_0387_0x082b68(a0, a1);
        case 388: return fde_func_0388_0x082e9c(a0, a1);
        case 389: return fde_func_0389_0x083018(a0, a1);
        case 390: return fde_func_0390_0x083174(a0, a1);
        case 391: return fde_func_0391_0x0832b8(a0, a1);
        case 392: return fde_func_0392_0x08342c(a0, a1);
        case 393: return fde_func_0393_0x083e5c(a0, a1);
        case 394: return fde_func_0394_0x084328(a0, a1);
        case 395: return fde_func_0395_0x0844ec(a0, a1);
        case 396: return fde_func_0396_0x0847bc(a0, a1);
        case 397: return fde_func_0397_0x084a90(a0, a1);
        case 398: return fde_func_0398_0x084dec(a0, a1);
        case 399: return fde_func_0399_0x084fe8(a0, a1);
        case 400: return fde_func_0400_0x085188(a0, a1);
        case 401: return fde_func_0401_0x085304(a0, a1);
        case 402: return fde_func_0402_0x085494(a0, a1);
        case 403: return fde_func_0403_0x085614(a0, a1);
        case 404: return fde_func_0404_0x085738(a0, a1);
        case 405: return fde_func_0405_0x0859e8(a0, a1);
        case 406: return fde_func_0406_0x085d5c(a0, a1);
        case 407: return fde_func_0407_0x085f18(a0, a1);
        case 408: return fde_func_0408_0x086590(a0, a1);
        case 409: return fde_func_0409_0x0867e4(a0, a1);
        case 410: return fde_func_0410_0x086910(a0, a1);
        case 411: return fde_func_0411_0x0869f8(a0, a1);
        case 412: return fde_func_0412_0x087a60(a0, a1);
        case 413: return fde_func_0413_0x087c10(a0, a1);
        case 414: return fde_func_0414_0x088038(a0, a1);
        case 415: return fde_func_0415_0x08821c(a0, a1);
        case 416: return fde_func_0416_0x08874c(a0, a1);
        case 417: return fde_func_0417_0x088c90(a0, a1);
        case 418: return fde_func_0418_0x088e40(a0, a1);
        case 419: return fde_func_0419_0x088fb0(a0, a1);
        case 420: return fde_func_0420_0x0897f0(a0, a1);
        case 421: return fde_func_0421_0x0899a4(a0, a1);
        case 422: return fde_func_0422_0x089ac8(a0, a1);
        case 423: return fde_func_0423_0x089e84(a0, a1);
        case 424: return fde_func_0424_0x089eec(a0, a1);
        case 425: return fde_func_0425_0x08a0cc(a0, a1);
        case 426: return fde_func_0426_0x08a240(a0, a1);
        case 427: return fde_func_0427_0x08a2a8(a0, a1);
        case 428: return fde_func_0428_0x08a518(a0, a1);
        case 429: return fde_func_0429_0x08a684(a0, a1);
        case 430: return fde_func_0430_0x08a6c0(a0, a1);
        case 431: return fde_func_0431_0x08a6dc(a0, a1);
        case 432: return fde_func_0432_0x08a8d4(a0, a1);
        case 433: return fde_func_0433_0x08a9d0(a0, a1);
        case 434: return fde_func_0434_0x08ac94(a0, a1);
        case 435: return fde_func_0435_0x08acc8(a0, a1);
        case 436: return fde_func_0436_0x08acfc(a0, a1);
        case 437: return fde_func_0437_0x08afdc(a0, a1);
        case 438: return fde_func_0438_0x08b0ac(a0, a1);
        case 439: return fde_func_0439_0x08b24c(a0, a1);
        case 440: return fde_func_0440_0x08b250(a0, a1);
        case 441: return fde_func_0441_0x08b254(a0, a1);
        case 442: return fde_func_0442_0x08b7d8(a0, a1);
        case 443: return fde_func_0443_0x08b980(a0, a1);
        case 444: return fde_func_0444_0x08bb28(a0, a1);
        case 445: return fde_func_0445_0x08bd28(a0, a1);
        case 446: return fde_func_0446_0x08bde4(a0, a1);
        case 447: return fde_func_0447_0x08bf14(a0, a1);
        case 448: return fde_func_0448_0x08c05c(a0, a1);
        case 449: return fde_func_0449_0x08c2f0(a0, a1);
        case 450: return fde_func_0450_0x08c3a0(a0, a1);
        case 451: return fde_func_0451_0x08c3cc(a0, a1);
        case 452: return fde_func_0452_0x08c3e4(a0, a1);
        case 453: return fde_func_0453_0x08c3ec(a0, a1);
        case 454: return fde_func_0454_0x08c408(a0, a1);
        case 455: return fde_func_0455_0x08c414(a0, a1);
        case 456: return fde_func_0456_0x08c844(a0, a1);
        case 457: return fde_func_0457_0x08c958(a0, a1);
        case 458: return fde_func_0458_0x08c984(a0, a1);
        case 459: return fde_func_0459_0x08c99c(a0, a1);
        case 460: return fde_func_0460_0x08c9a8(a0, a1);
        case 461: return fde_func_0461_0x08c9c4(a0, a1);
        case 462: return fde_func_0462_0x08c9d0(a0, a1);
        case 463: return fde_func_0463_0x08ccd4(a0, a1);
        case 464: return fde_func_0464_0x08ce04(a0, a1);
        case 465: return fde_func_0465_0x08ce30(a0, a1);
        case 466: return fde_func_0466_0x08ce48(a0, a1);
        case 467: return fde_func_0467_0x08ce50(a0, a1);
        case 468: return fde_func_0468_0x08ce6c(a0, a1);
        case 469: return fde_func_0469_0x08ce78(a0, a1);
        case 470: return fde_func_0470_0x08cf78(a0, a1);
        case 471: return fde_func_0471_0x08d100(a0, a1);
        case 472: return fde_func_0472_0x08d12c(a0, a1);
        case 473: return fde_func_0473_0x08d144(a0, a1);
        case 474: return fde_func_0474_0x08d14c(a0, a1);
        case 475: return fde_func_0475_0x08d168(a0, a1);
        case 476: return fde_func_0476_0x08d174(a0, a1);
        case 477: return fde_func_0477_0x08d35c(a0, a1);
        case 478: return fde_func_0478_0x08d3f8(a0, a1);
        case 479: return fde_func_0479_0x08d410(a0, a1);
        case 480: return fde_func_0480_0x08d44c(a0, a1);
        case 481: return fde_func_0481_0x08d468(a0, a1);
        case 482: return fde_func_0482_0x08d470(a0, a1);
        case 483: return fde_func_0483_0x08d5ac(a0, a1);
        case 484: return fde_func_0484_0x08d6f0(a0, a1);
        case 485: return fde_func_0485_0x08d758(a0, a1);
        case 486: return fde_func_0486_0x08d764(a0, a1);
        case 487: return fde_func_0487_0x08d9b8(a0, a1);
        case 488: return fde_func_0488_0x08df90(a0, a1);
        case 489: return fde_func_0489_0x08df98(a0, a1);
        case 490: return fde_func_0490_0x08e2e4(a0, a1);
        case 491: return fde_func_0491_0x08e998(a0, a1);
        case 492: return fde_func_0492_0x08ea74(a0, a1);
        case 493: return fde_func_0493_0x08ebec(a0, a1);
        case 494: return fde_func_0494_0x08eca0(a0, a1);
        case 495: return fde_func_0495_0x08edcc(a0, a1);
        case 496: return fde_func_0496_0x08f094(a0, a1);
        case 497: return fde_func_0497_0x08f4c0(a0, a1);
        case 498: return fde_func_0498_0x08fac8(a0, a1);
        case 499: return fde_func_0499_0x08fbb0(a0, a1);
        case 500: return fde_func_0500_0x090198(a0, a1);
        case 501: return fde_func_0501_0x091558(a0, a1);
        case 502: return fde_func_0502_0x0916f0(a0, a1);
        case 503: return fde_func_0503_0x091e58(a0, a1);
        case 504: return fde_func_0504_0x092030(a0, a1);
        case 505: return fde_func_0505_0x09229c(a0, a1);
        case 506: return fde_func_0506_0x0924a0(a0, a1);
        case 507: return fde_func_0507_0x092b1c(a0, a1);
        case 508: return fde_func_0508_0x092f2c(a0, a1);
        case 509: return fde_func_0509_0x093148(a0, a1);
        case 510: return fde_func_0510_0x093274(a0, a1);
        case 511: return fde_func_0511_0x0932ac(a0, a1);
        case 512: return fde_func_0512_0x093494(a0, a1);
        case 513: return fde_func_0513_0x0937d0(a0, a1);
        case 514: return fde_func_0514_0x093be8(a0, a1);
        case 515: return fde_func_0515_0x093d88(a0, a1);
        case 516: return fde_func_0516_0x093eb4(a0, a1);
        case 517: return fde_func_0517_0x094028(a0, a1);
        case 518: return fde_func_0518_0x094254(a0, a1);
        case 519: return fde_func_0519_0x094378(a0, a1);
        case 520: return fde_func_0520_0x094380(a0, a1);
        case 521: return fde_func_0521_0x0943e4(a0, a1);
        case 522: return fde_func_0522_0x09489c(a0, a1);
        case 523: return fde_func_0523_0x094a90(a0, a1);
        case 524: return fde_func_0524_0x094bac(a0, a1);
        case 525: return fde_func_0525_0x094e58(a0, a1);
        case 526: return fde_func_0526_0x095328(a0, a1);
        case 527: return fde_func_0527_0x095c9c(a0, a1);
        case 528: return fde_func_0528_0x095fe4(a0, a1);
        case 529: return fde_func_0529_0x0969e8(a0, a1);
        case 530: return fde_func_0530_0x096d30(a0, a1);
        case 531: return fde_func_0531_0x096d80(a0, a1);
        case 532: return fde_func_0532_0x0970bc(a0, a1);
        case 533: return fde_func_0533_0x0971e0(a0, a1);
        case 534: return fde_func_0534_0x0973a8(a0, a1);
        case 535: return fde_func_0535_0x097a0c(a0, a1);
        case 536: return fde_func_0536_0x097d04(a0, a1);
        case 537: return fde_func_0537_0x0992d8(a0, a1);
        case 538: return fde_func_0538_0x099608(a0, a1);
        case 539: return fde_func_0539_0x099740(a0, a1);
        case 540: return fde_func_0540_0x09985c(a0, a1);
        case 541: return fde_func_0541_0x099954(a0, a1);
        case 542: return fde_func_0542_0x099a60(a0, a1);
        case 543: return fde_func_0543_0x099b50(a0, a1);
        case 544: return fde_func_0544_0x099eac(a0, a1);
        case 545: return fde_func_0545_0x09a248(a0, a1);
        case 546: return fde_func_0546_0x09a370(a0, a1);
        case 547: return fde_func_0547_0x09a4e0(a0, a1);
        case 548: return fde_func_0548_0x09aba4(a0, a1);
        case 549: return fde_func_0549_0x09ad0c(a0, a1);
        case 550: return fde_func_0550_0x09ad38(a0, a1);
        case 551: return fde_func_0551_0x09b40c(a0, a1);
        case 552: return fde_func_0552_0x09c13c(a0, a1);
        case 553: return fde_func_0553_0x09c804(a0, a1);
        case 554: return fde_func_0554_0x09cc7c(a0, a1);
        case 555: return fde_func_0555_0x09cd9c(a0, a1);
        case 556: return fde_func_0556_0x09cfdc(a0, a1);
        case 557: return fde_func_0557_0x09d264(a0, a1);
        case 558: return fde_func_0558_0x09d3d0(a0, a1);
        case 559: return fde_func_0559_0x09d784(a0, a1);
        case 560: return fde_func_0560_0x09db58(a0, a1);
        case 561: return fde_func_0561_0x09db60(a0, a1);
        case 562: return fde_func_0562_0x09db78(a0, a1);
        case 563: return fde_func_0563_0x09e210(a0, a1);
        case 564: return fde_func_0564_0x09e7b0(a0, a1);
        case 565: return fde_func_0565_0x09eb48(a0, a1);
        case 566: return fde_func_0566_0x09ebbc(a0, a1);
        case 567: return fde_func_0567_0x09ec30(a0, a1);
        case 568: return fde_func_0568_0x09ec4c(a0, a1);
        case 569: return fde_func_0569_0x09ef8c(a0, a1);
        case 570: return fde_func_0570_0x09fe6c(a0, a1);
        case 571: return fde_func_0571_0x09fff0(a0, a1);
        case 572: return fde_func_0572_0x0a0290(a0, a1);
        case 573: return fde_func_0573_0x0a0ae8(a0, a1);
        case 574: return fde_func_0574_0x0a0c6c(a0, a1);
        case 575: return fde_func_0575_0x0a0e30(a0, a1);
        case 576: return fde_func_0576_0x0a0fe4(a0, a1);
        case 577: return fde_func_0577_0x0a10e4(a0, a1);
        case 578: return fde_func_0578_0x0a1500(a0, a1);
        case 579: return fde_func_0579_0x0a158c(a0, a1);
        case 580: return fde_func_0580_0x0a16a4(a0, a1);
        case 581: return fde_func_0581_0x0a18ac(a0, a1);
        case 582: return fde_func_0582_0x0a2288(a0, a1);
        case 583: return fde_func_0583_0x0a2b48(a0, a1);
        case 584: return fde_func_0584_0x0a2eb8(a0, a1);
        case 585: return fde_func_0585_0x0a33fc(a0, a1);
        case 586: return fde_func_0586_0x0a35a8(a0, a1);
        case 587: return fde_func_0587_0x0a3a3c(a0, a1);
        case 588: return fde_func_0588_0x0a3e4c(a0, a1);
        case 589: return fde_func_0589_0x0a4288(a0, a1);
        case 590: return fde_func_0590_0x0a47bc(a0, a1);
        case 591: return fde_func_0591_0x0a4efc(a0, a1);
        case 592: return fde_func_0592_0x0a4ff4(a0, a1);
        case 593: return fde_func_0593_0x0a52b8(a0, a1);
        case 594: return fde_func_0594_0x0a52c8(a0, a1);
        case 595: return fde_func_0595_0x0a52d8(a0, a1);
        case 596: return fde_func_0596_0x0a52e8(a0, a1);
        case 597: return fde_func_0597_0x0a52f8(a0, a1);
        case 598: return fde_func_0598_0x0a5314(a0, a1);
        case 599: return fde_func_0599_0x0a5330(a0, a1);
        case 600: return fde_func_0600_0x0a5398(a0, a1);
        case 601: return fde_func_0601_0x0a53f8(a0, a1);
        case 602: return fde_func_0602_0x0a5414(a0, a1);
        case 603: return fde_func_0603_0x0a5430(a0, a1);
        case 604: return fde_func_0604_0x0a543c(a0, a1);
        case 605: return fde_func_0605_0x0a544c(a0, a1);
        case 606: return fde_func_0606_0x0a545c(a0, a1);
        case 607: return fde_func_0607_0x0a5468(a0, a1);
        case 608: return fde_func_0608_0x0a5474(a0, a1);
        case 609: return fde_func_0609_0x0a5498(a0, a1);
        case 610: return fde_func_0610_0x0a54bc(a0, a1);
        case 611: return fde_func_0611_0x0a54e0(a0, a1);
        case 612: return fde_func_0612_0x0a5578(a0, a1);
        case 613: return fde_func_0613_0x0a5580(a0, a1);
        case 614: return fde_func_0614_0x0a5734(a0, a1);
        case 615: return fde_func_0615_0x0a588c(a0, a1);
        case 616: return fde_func_0616_0x0a5a48(a0, a1);
        case 617: return fde_func_0617_0x0a5cac(a0, a1);
        case 618: return fde_func_0618_0x0a5dc8(a0, a1);
        case 619: return fde_func_0619_0x0a5f48(a0, a1);
        case 620: return fde_func_0620_0x0a6148(a0, a1);
        case 621: return fde_func_0621_0x0a6358(a0, a1);
        case 622: return fde_func_0622_0x0a67a4(a0, a1);
        case 623: return fde_func_0623_0x0a67ec(a0, a1);
        case 624: return fde_func_0624_0x0a7018(a0, a1);
        case 625: return fde_func_0625_0x0a76b4(a0, a1);
        case 626: return fde_func_0626_0x0a78cc(a0, a1);
        case 627: return fde_func_0627_0x0a7b8c(a0, a1);
        case 628: return fde_func_0628_0x0a7db8(a0, a1);
        case 629: return fde_func_0629_0x0a7f38(a0, a1);
        case 630: return fde_func_0630_0x0a8014(a0, a1);
        case 631: return fde_func_0631_0x0a849c(a0, a1);
        case 632: return fde_func_0632_0x0a8668(a0, a1);
        case 633: return fde_func_0633_0x0a8924(a0, a1);
        case 634: return fde_func_0634_0x0a8b08(a0, a1);
        case 635: return fde_func_0635_0x0a9260(a0, a1);
        case 636: return fde_func_0636_0x0a95b8(a0, a1);
        case 637: return fde_func_0637_0x0a97ac(a0, a1);
        case 638: return fde_func_0638_0x0a9804(a0, a1);
        case 639: return fde_func_0639_0x0a9d54(a0, a1);
        case 640: return fde_func_0640_0x0aa49c(a0, a1);
        case 641: return fde_func_0641_0x0aa960(a0, a1);
        case 642: return fde_func_0642_0x0ab128(a0, a1);
        case 643: return fde_func_0643_0x0ab5c4(a0, a1);
        case 644: return fde_func_0644_0x0abb10(a0, a1);
        case 645: return fde_func_0645_0x0ac0cc(a0, a1);
        case 646: return fde_func_0646_0x0ac3c4(a0, a1);
        case 647: return fde_func_0647_0x0ac4dc(a0, a1);
        case 648: return fde_func_0648_0x0acfcc(a0, a1);
        case 649: return fde_func_0649_0x0ad170(a0, a1);
        case 650: return fde_func_0650_0x0ad5c8(a0, a1);
        case 651: return fde_func_0651_0x0ad674(a0, a1);
        case 652: return fde_func_0652_0x0ad930(a0, a1);
        case 653: return fde_func_0653_0x0ae598(a0, a1);
        case 654: return fde_func_0654_0x0ae8f8(a0, a1);
        case 655: return fde_func_0655_0x0aeba4(a0, a1);
        case 656: return fde_func_0656_0x0aeec4(a0, a1);
        case 657: return fde_func_0657_0x0b0168(a0, a1);
        case 658: return fde_func_0658_0x0b03a4(a0, a1);
        case 659: return fde_func_0659_0x0b0a20(a0, a1);
        case 660: return fde_func_0660_0x0b0ee8(a0, a1);
        case 661: return fde_func_0661_0x0b1258(a0, a1);
        case 662: return fde_func_0662_0x0b1388(a0, a1);
        case 663: return fde_func_0663_0x0b1988(a0, a1);
        case 664: return fde_func_0664_0x0b1b5c(a0, a1);
        case 665: return fde_func_0665_0x0b1f48(a0, a1);
        case 666: return fde_func_0666_0x0b2330(a0, a1);
        case 667: return fde_func_0667_0x0b2494(a0, a1);
        case 668: return fde_func_0668_0x0b2c5c(a0, a1);
        case 669: return fde_func_0669_0x0b2e9c(a0, a1);
        case 670: return fde_func_0670_0x0b32f8(a0, a1);
        case 671: return fde_func_0671_0x0b37ec(a0, a1);
        case 672: return fde_func_0672_0x0b38ec(a0, a1);
        case 673: return fde_func_0673_0x0b3b6c(a0, a1);
        case 674: return fde_func_0674_0x0b3b94(a0, a1);
        case 675: return fde_func_0675_0x0b3f94(a0, a1);
        case 676: return fde_func_0676_0x0b5788(a0, a1);
        case 677: return fde_func_0677_0x0b5c80(a0, a1);
        case 678: return fde_func_0678_0x0b627c(a0, a1);
        case 679: return fde_func_0679_0x0b65bc(a0, a1);
        case 680: return fde_func_0680_0x0b6fe4(a0, a1);
        case 681: return fde_func_0681_0x0b71f4(a0, a1);
        case 682: return fde_func_0682_0x0b7af4(a0, a1);
        case 683: return fde_func_0683_0x0b7da8(a0, a1);
        case 684: return fde_func_0684_0x0b7f8c(a0, a1);
        case 685: return fde_func_0685_0x0b8088(a0, a1);
        case 686: return fde_func_0686_0x0b8210(a0, a1);
        case 687: return fde_func_0687_0x0b8524(a0, a1);
        case 688: return fde_func_0688_0x0b8664(a0, a1);
        case 689: return fde_func_0689_0x0ba40c(a0, a1);
        case 690: return fde_func_0690_0x0be93c(a0, a1);
        case 691: return fde_func_0691_0x0c0678(a0, a1);
        case 692: return fde_func_0692_0x0c2458(a0, a1);
        case 693: return fde_func_0693_0x0c2ae4(a0, a1);
        case 694: return fde_func_0694_0x0c2e6c(a0, a1);
        case 695: return fde_func_0695_0x0c328c(a0, a1);
        case 696: return fde_func_0696_0x0c35f0(a0, a1);
        case 697: return fde_func_0697_0x0c3b0c(a0, a1);
        case 698: return fde_func_0698_0x0c41d4(a0, a1);
        case 699: return fde_func_0699_0x0c4240(a0, a1);
        case 700: return fde_func_0700_0x0c5018(a0, a1);
        case 701: return fde_func_0701_0x0c51bc(a0, a1);
        case 702: return fde_func_0702_0x0c5500(a0, a1);
        case 703: return fde_func_0703_0x0c562c(a0, a1);
        case 704: return fde_func_0704_0x0c5a64(a0, a1);
        case 705: return fde_func_0705_0x0c5fd0(a0, a1);
        case 706: return fde_func_0706_0x0c60d0(a0, a1);
        case 707: return fde_func_0707_0x0c6194(a0, a1);
        case 708: return fde_func_0708_0x0c6320(a0, a1);
        case 709: return fde_func_0709_0x0c6414(a0, a1);
        case 710: return fde_func_0710_0x0c658c(a0, a1);
        case 711: return fde_func_0711_0x0c6730(a0, a1);
        case 712: return fde_func_0712_0x0c68f8(a0, a1);
        case 713: return fde_func_0713_0x0c6cd0(a0, a1);
        case 714: return fde_func_0714_0x0c6cec(a0, a1);
        case 715: return fde_func_0715_0x0c6d7c(a0, a1);
        case 716: return fde_func_0716_0x0c7014(a0, a1);
        case 717: return fde_func_0717_0x0c70d0(a0, a1);
        case 718: return fde_func_0718_0x0c73d4(a0, a1);
        case 719: return fde_func_0719_0x0c7590(a0, a1);
        case 720: return fde_func_0720_0x0c78c8(a0, a1);
        case 721: return fde_func_0721_0x0c7a50(a0, a1);
        case 722: return fde_func_0722_0x0c7b94(a0, a1);
        case 723: return fde_func_0723_0x0c7bb8(a0, a1);
        case 724: return fde_func_0724_0x0c81d4(a0, a1);
        case 725: return fde_func_0725_0x0c8328(a0, a1);
        case 726: return fde_func_0726_0x0c83a0(a0, a1);
        case 727: return fde_func_0727_0x0c84d8(a0, a1);
        case 728: return fde_func_0728_0x0c8550(a0, a1);
        case 729: return fde_func_0729_0x0c8774(a0, a1);
        case 730: return fde_func_0730_0x0c8780(a0, a1);
        case 731: return fde_func_0731_0x0c8898(a0, a1);
        case 732: return fde_func_0732_0x0c8b84(a0, a1);
        case 733: return fde_func_0733_0x0c8ee4(a0, a1);
        case 734: return fde_func_0734_0x0c8fe0(a0, a1);
        case 735: return fde_func_0735_0x0c9164(a0, a1);
        case 736: return fde_func_0736_0x0c91a8(a0, a1);
        case 737: return fde_func_0737_0x0c9320(a0, a1);
        case 738: return fde_func_0738_0x0c965c(a0, a1);
        case 739: return fde_func_0739_0x0c99e4(a0, a1);
        case 740: return fde_func_0740_0x0c9a40(a0, a1);
        case 741: return fde_func_0741_0x0c9a88(a0, a1);
        case 742: return fde_func_0742_0x0c9aa4(a0, a1);
        case 743: return fde_func_0743_0x0c9bc0(a0, a1);
        case 744: return fde_func_0744_0x0c9bcc(a0, a1);
        case 745: return fde_func_0745_0x0c9c20(a0, a1);
        case 746: return fde_func_0746_0x0c9c54(a0, a1);
        case 747: return fde_func_0747_0x0c9ee0(a0, a1);
        case 748: return fde_func_0748_0x0ca0a8(a0, a1);
        case 749: return fde_func_0749_0x0ca3c4(a0, a1);
        case 750: return fde_func_0750_0x0ca4e8(a0, a1);
        case 751: return fde_func_0751_0x0ca694(a0, a1);
        case 752: return fde_func_0752_0x0ca9b4(a0, a1);
        case 753: return fde_func_0753_0x0cad0c(a0, a1);
        case 754: return fde_func_0754_0x0cb19c(a0, a1);
        case 755: return fde_func_0755_0x0cb784(a0, a1);
        case 756: return fde_func_0756_0x0cb948(a0, a1);
        case 757: return fde_func_0757_0x0cbb08(a0, a1);
        default: return 0ULL;
    }
}