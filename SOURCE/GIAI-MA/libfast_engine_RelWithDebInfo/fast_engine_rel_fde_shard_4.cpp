// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 4/5 for libfast_engine_RelWithDebInfo.so
// Phân mảnh FDE AArch64 C++17 sạch 4/5 cho libfast_engine_RelWithDebInfo.so
// Covers FDE indices [1251 .. 1667] out of 2,082 total FDEs (.eh_frame_hdr @ 0x1127c8)
// Bao phủ chỉ số FDE [1251 .. 1667] trên tổng số 2,082 FDE (.eh_frame_hdr @ 0x1127c8)
// ============================================================================
#include "fast_engine_rel_core.h"

namespace fast_engine {

// FDE #1251 | PC: 0x0c27c4 | FDE: 0x122740 | Size: 148 bytes
// Hàm FDE #1251 | Địa chỉ PC: 0x0c27c4 | Địa chỉ FDE: 0x122740 | Kích thước: 148 bytes
//   0x0c27c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c27c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c27cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c27d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1251_0x0c27c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c27c4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122740ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1252 | PC: 0x0c2858 | FDE: 0x122768 | Size: 148 bytes
// Hàm FDE #1252 | Địa chỉ PC: 0x0c2858 | Địa chỉ FDE: 0x122768 | Kích thước: 148 bytes
//   0x0c2858: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c285c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c2860: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c2864: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1252_0x0c2858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2858ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122768ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1253 | PC: 0x0c28ec | FDE: 0x122790 | Size: 204 bytes
// Hàm FDE #1253 | Địa chỉ PC: 0x0c28ec | Địa chỉ FDE: 0x122790 | Kích thước: 204 bytes
//   0x0c28ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c28f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c28f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c28f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1253_0x0c28ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c28ecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122790ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1254 | PC: 0x0c29b8 | FDE: 0x122008 | Size: 212 bytes
// Hàm FDE #1254 | Địa chỉ PC: 0x0c29b8 | Địa chỉ FDE: 0x122008 | Kích thước: 212 bytes
//   0x0c29b8: D10103FF  sub      sp, sp, #0x40
//   0x0c29bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c29c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c29c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1254_0x0c29b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c29b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122008ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1255 | PC: 0x0c2a8c | FDE: 0x1227b8 | Size: 256 bytes
// Hàm FDE #1255 | Địa chỉ PC: 0x0c2a8c | Địa chỉ FDE: 0x1227b8 | Kích thước: 256 bytes
//   0x0c2a8c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c2a90: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c2a94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c2a98: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1255_0x0c2a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2a8cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1227b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1256 | PC: 0x0c2c7c | FDE: 0x122030 | Size: 256 bytes
// Hàm FDE #1256 | Địa chỉ PC: 0x0c2c7c | Địa chỉ FDE: 0x122030 | Kích thước: 256 bytes
//   0x0c2c7c: D10203FF  sub      sp, sp, #0x80
//   0x0c2c80: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0c2c84: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0c2c88: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1256_0x0c2c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2c7cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x122030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1257 | PC: 0x0c2f84 | FDE: 0x1227e8 | Size: 256 bytes
// Hàm FDE #1257 | Địa chỉ PC: 0x0c2f84 | Địa chỉ FDE: 0x1227e8 | Kích thước: 256 bytes
//   0x0c2f84: D10243FF  sub      sp, sp, #0x90
//   0x0c2f88: F90023F9  str      x25, [sp, #0x40]
//   0x0c2f8c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0c2f90: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1257_0x0c2f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2f84ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x1227e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1258 | PC: 0x0c33cc | FDE: 0x122060 | Size: 20 bytes
// Hàm FDE #1258 | Địa chỉ PC: 0x0c33cc | Địa chỉ FDE: 0x122060 | Kích thước: 20 bytes
//   0x0c33cc: 900003E8  adrp     x8, #0x13f000
//   0x0c33d0: F943ED08  ldr      x8, [x8, #0x7d8]
//   0x0c33d4: AA0103E2  mov      x2, x1
//   0x0c33d8: F9400101  ldr      x1, [x8]
static inline uint64_t fde_func_1258_0x0c33cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c33ccULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0xf943ed08ULL) ^ 0x122060ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1259 | PC: 0x0c33e0 | FDE: 0x122078 | Size: 100 bytes [_ZN11fast_engine11DictViewObjC2EPNS_7DictObjEPNS_7TypeObjEPNS_6EngineE]
// Hàm FDE #1259 | Địa chỉ PC: 0x0c33e0 | Địa chỉ FDE: 0x122078 | Kích thước: 100 bytes
//   0x0c33e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c33e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c33e8: 910043FD  add      x29, sp, #0x10
//   0x0c33ec: AA0303E8  mov      x8, x3
static inline uint64_t fde_func_1259_0x0c33e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c33e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122078ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1260 | PC: 0x0c3444 | FDE: 0x122098 | Size: 84 bytes [_ZN11fast_engine11DictViewObj5ClearEPNS_6EngineE]
// Hàm FDE #1260 | Địa chỉ PC: 0x0c3444 | Địa chỉ FDE: 0x122098 | Kích thước: 84 bytes
//   0x0c3444: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c3448: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c344c: 910043FD  add      x29, sp, #0x10
//   0x0c3450: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1260_0x0c3444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3444ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122098ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1261 | PC: 0x0c3498 | FDE: 0x122818 | Size: 96 bytes [_ZN11fast_engine17AllocDictKeysTypeEPNS_6EngineE]
// Hàm FDE #1261 | Địa chỉ PC: 0x0c3498 | Địa chỉ FDE: 0x122818 | Kích thước: 96 bytes
//   0x0c3498: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c349c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c34a0: 910043FD  add      x29, sp, #0x10
//   0x0c34a4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1261_0x0c3498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3498ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122818ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1262 | PC: 0x0c34f8 | FDE: 0x1220b8 | Size: 60 bytes [_ZN11fast_engine16InitDictKeysTypeEPNS_6EngineE]
// Hàm FDE #1262 | Địa chỉ PC: 0x0c34f8 | Địa chỉ FDE: 0x1220b8 | Kích thước: 60 bytes
//   0x0c34f8: 900003E8  adrp     x8, #0x13f000
//   0x0c34fc: F947B908  ldr      x8, [x8, #0xf70]
//   0x0c3500: D00003E9  adrp     x9, #0x141000
//   0x0c3504: 9000000A  adrp     x10, #0xc3000
static inline uint64_t fde_func_1262_0x0c34f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c34f8ULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0xf947b908ULL) ^ 0x1220b8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1263 | PC: 0x0c3534 | FDE: 0x1220d0 | Size: 24 bytes
// Hàm FDE #1263 | Địa chỉ PC: 0x0c3534 | Địa chỉ FDE: 0x1220d0 | Kích thước: 24 bytes
//   0x0c3534: F9402008  ldr      x8, [x0, #0x40]
//   0x0c3538: B4000068  cbz      x8, #0xc3544
//   0x0c353c: F9402100  ldr      x0, [x8, #0x40]
//   0x0c3540: D65F03C0  ret      
static inline uint64_t fde_func_1263_0x0c3534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3534ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x1220d0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1264 | PC: 0x0c354c | FDE: 0x1220e8 | Size: 168 bytes
// Hàm FDE #1264 | Địa chỉ PC: 0x0c354c | Địa chỉ FDE: 0x1220e8 | Kích thước: 168 bytes
//   0x0c354c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c3550: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c3554: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c3558: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1264_0x0c354c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c354cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1220e8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1265 | PC: 0x0c35f4 | FDE: 0x122108 | Size: 44 bytes
// Hàm FDE #1265 | Địa chỉ PC: 0x0c35f4 | Địa chỉ FDE: 0x122108 | Kích thước: 44 bytes
//   0x0c35f4: F9402000  ldr      x0, [x0, #0x40]
//   0x0c35f8: B40000C0  cbz      x0, #0xc3610
//   0x0c35fc: 900003E8  adrp     x8, #0x13f000
//   0x0c3600: F943ED08  ldr      x8, [x8, #0x7d8]
static inline uint64_t fde_func_1265_0x0c35f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c35f4ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb40000c0ULL) ^ 0x122108ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1266 | PC: 0x0c3620 | FDE: 0x122840 | Size: 256 bytes
// Hàm FDE #1266 | Địa chỉ PC: 0x0c3620 | Địa chỉ FDE: 0x122840 | Kích thước: 256 bytes
//   0x0c3620: D101C3FF  sub      sp, sp, #0x70
//   0x0c3624: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0c3628: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0c362c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1266_0x0c3620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3620ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x122840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1267 | PC: 0x0c37f4 | FDE: 0x122120 | Size: 256 bytes
// Hàm FDE #1267 | Địa chỉ PC: 0x0c37f4 | Địa chỉ FDE: 0x122120 | Kích thước: 256 bytes
//   0x0c37f4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c37f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c37fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c3800: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1267_0x0c37f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c37f4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1268 | PC: 0x0c3990 | FDE: 0x122870 | Size: 96 bytes [_ZN11fast_engine18AllocDictItemsTypeEPNS_6EngineE]
// Hàm FDE #1268 | Địa chỉ PC: 0x0c3990 | Địa chỉ FDE: 0x122870 | Kích thước: 96 bytes
//   0x0c3990: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c3994: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c3998: 910043FD  add      x29, sp, #0x10
//   0x0c399c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1268_0x0c3990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3990ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122870ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1269 | PC: 0x0c39f0 | FDE: 0x122148 | Size: 60 bytes [_ZN11fast_engine17InitDictItemsTypeEPNS_6EngineE]
// Hàm FDE #1269 | Địa chỉ PC: 0x0c39f0 | Địa chỉ FDE: 0x122148 | Kích thước: 60 bytes
//   0x0c39f0: 900003E8  adrp     x8, #0x13f000
//   0x0c39f4: F9441908  ldr      x8, [x8, #0x830]
//   0x0c39f8: D00003E9  adrp     x9, #0x141000
//   0x0c39fc: 9000000A  adrp     x10, #0xc3000
static inline uint64_t fde_func_1269_0x0c39f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c39f0ULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0xf9441908ULL) ^ 0x122148ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1270 | PC: 0x0c3a2c | FDE: 0x122160 | Size: 256 bytes
// Hàm FDE #1270 | Địa chỉ PC: 0x0c3a2c | Địa chỉ FDE: 0x122160 | Kích thước: 256 bytes
//   0x0c3a2c: D10103FF  sub      sp, sp, #0x40
//   0x0c3a30: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c3a34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c3a38: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1270_0x0c3a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3a2cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1271 | PC: 0x0c3b58 | FDE: 0x122188 | Size: 44 bytes
// Hàm FDE #1271 | Địa chỉ PC: 0x0c3b58 | Địa chỉ FDE: 0x122188 | Kích thước: 44 bytes
//   0x0c3b58: F9402000  ldr      x0, [x0, #0x40]
//   0x0c3b5c: B40000C0  cbz      x0, #0xc3b74
//   0x0c3b60: 900003E8  adrp     x8, #0x13f000
//   0x0c3b64: F945DD08  ldr      x8, [x8, #0xbb8]
static inline uint64_t fde_func_1271_0x0c3b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3b58ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb40000c0ULL) ^ 0x122188ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1272 | PC: 0x0c3b84 | FDE: 0x122898 | Size: 96 bytes [_ZN11fast_engine19AllocDictValuesTypeEPNS_6EngineE]
// Hàm FDE #1272 | Địa chỉ PC: 0x0c3b84 | Địa chỉ FDE: 0x122898 | Kích thước: 96 bytes
//   0x0c3b84: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c3b88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c3b8c: 910043FD  add      x29, sp, #0x10
//   0x0c3b90: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1272_0x0c3b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3b84ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122898ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1273 | PC: 0x0c3be4 | FDE: 0x1221a0 | Size: 52 bytes [_ZN11fast_engine18InitDictValuesTypeEPNS_6EngineE]
// Hàm FDE #1273 | Địa chỉ PC: 0x0c3be4 | Địa chỉ FDE: 0x1221a0 | Kích thước: 52 bytes
//   0x0c3be4: 900003E8  adrp     x8, #0x13f000
//   0x0c3be8: F9445108  ldr      x8, [x8, #0x8a0]
//   0x0c3bec: D00003E9  adrp     x9, #0x141000
//   0x0c3bf0: 9000000A  adrp     x10, #0xc3000
static inline uint64_t fde_func_1273_0x0c3be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3be4ULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0xf9445108ULL) ^ 0x1221a0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1274 | PC: 0x0c3c18 | FDE: 0x1221b8 | Size: 44 bytes
// Hàm FDE #1274 | Địa chỉ PC: 0x0c3c18 | Địa chỉ FDE: 0x1221b8 | Kích thước: 44 bytes
//   0x0c3c18: F9402000  ldr      x0, [x0, #0x40]
//   0x0c3c1c: B40000C0  cbz      x0, #0xc3c34
//   0x0c3c20: 900003E8  adrp     x8, #0x13f000
//   0x0c3c24: F9440908  ldr      x8, [x8, #0x810]
static inline uint64_t fde_func_1274_0x0c3c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3c18ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb40000c0ULL) ^ 0x1221b8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1275 | PC: 0x0c3c44 | FDE: 0x1228c0 | Size: 96 bytes [_ZN11fast_engine22AllocDictItemsIterTypeEPNS_6EngineE]
// Hàm FDE #1275 | Địa chỉ PC: 0x0c3c44 | Địa chỉ FDE: 0x1228c0 | Kích thước: 96 bytes
//   0x0c3c44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c3c48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c3c4c: 910043FD  add      x29, sp, #0x10
//   0x0c3c50: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1275_0x0c3c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3c44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1228c0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1276 | PC: 0x0c3ca4 | FDE: 0x1221d0 | Size: 208 bytes [_ZN11fast_engine21InitDictItemsIterTypeEPNS_6EngineE]
// Hàm FDE #1276 | Địa chỉ PC: 0x0c3ca4 | Địa chỉ FDE: 0x1221d0 | Kích thước: 208 bytes
//   0x0c3ca4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c3ca8: 910003FD  mov      x29, sp
//   0x0c3cac: 900003E9  adrp     x9, #0x13f000
//   0x0c3cb0: F945DD29  ldr      x9, [x9, #0xbb8]
static inline uint64_t fde_func_1276_0x0c3ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3ca4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1221d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1277 | PC: 0x0c3d74 | FDE: 0x1221f0 | Size: 256 bytes
// Hàm FDE #1277 | Địa chỉ PC: 0x0c3d74 | Địa chỉ FDE: 0x1221f0 | Kích thước: 256 bytes
//   0x0c3d74: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c3d78: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c3d7c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c3d80: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1277_0x0c3d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3d74ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1221f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1278 | PC: 0x0c4018 | FDE: 0x1228e8 | Size: 244 bytes
// Hàm FDE #1278 | Địa chỉ PC: 0x0c4018 | Địa chỉ FDE: 0x1228e8 | Kích thước: 244 bytes
//   0x0c4018: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c401c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4024: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1278_0x0c4018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4018ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1228e8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1279 | PC: 0x0c410c | FDE: 0x122910 | Size: 96 bytes [_ZN11fast_engine21AllocDictKeysIterTypeEPNS_6EngineE]
// Hàm FDE #1279 | Địa chỉ PC: 0x0c410c | Địa chỉ FDE: 0x122910 | Kích thước: 96 bytes
//   0x0c410c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c4110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c4114: 910043FD  add      x29, sp, #0x10
//   0x0c4118: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1279_0x0c410c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c410cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122910ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1280 | PC: 0x0c416c | FDE: 0x122218 | Size: 208 bytes [_ZN11fast_engine20InitDictKeysIterTypeEPNS_6EngineE]
// Hàm FDE #1280 | Địa chỉ PC: 0x0c416c | Địa chỉ FDE: 0x122218 | Kích thước: 208 bytes
//   0x0c416c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c4170: 910003FD  mov      x29, sp
//   0x0c4174: F00003C9  adrp     x9, #0x13f000
//   0x0c4178: F943ED29  ldr      x9, [x9, #0x7d8]
static inline uint64_t fde_func_1280_0x0c416c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c416cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x122218ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1281 | PC: 0x0c423c | FDE: 0x122238 | Size: 256 bytes
// Hàm FDE #1281 | Địa chỉ PC: 0x0c423c | Địa chỉ FDE: 0x122238 | Kích thước: 256 bytes
//   0x0c423c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c4240: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4244: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4248: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1281_0x0c423c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c423cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1282 | PC: 0x0c43f4 | FDE: 0x122938 | Size: 96 bytes [_ZN11fast_engine23AllocDictValuesIterTypeEPNS_6EngineE]
// Hàm FDE #1282 | Địa chỉ PC: 0x0c43f4 | Địa chỉ FDE: 0x122938 | Kích thước: 96 bytes
//   0x0c43f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c43f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c43fc: 910043FD  add      x29, sp, #0x10
//   0x0c4400: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1282_0x0c43f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c43f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122938ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1283 | PC: 0x0c4454 | FDE: 0x122258 | Size: 208 bytes [_ZN11fast_engine22InitDictValuesIterTypeEPNS_6EngineE]
// Hàm FDE #1283 | Địa chỉ PC: 0x0c4454 | Địa chỉ FDE: 0x122258 | Kích thước: 208 bytes
//   0x0c4454: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c4458: 910003FD  mov      x29, sp
//   0x0c445c: F00003C9  adrp     x9, #0x13f000
//   0x0c4460: F9440929  ldr      x9, [x9, #0x810]
static inline uint64_t fde_func_1283_0x0c4454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4454ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x122258ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1284 | PC: 0x0c4524 | FDE: 0x122278 | Size: 256 bytes
// Hàm FDE #1284 | Địa chỉ PC: 0x0c4524 | Địa chỉ FDE: 0x122278 | Kích thước: 256 bytes
//   0x0c4524: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c4528: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c452c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4530: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1284_0x0c4524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4524ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1285 | PC: 0x0c46c4 | FDE: 0x122298 | Size: 84 bytes [_ZN11fast_engine7DictObj16_NewKeysForClassEPNS_6EngineE]
// Hàm FDE #1285 | Địa chỉ PC: 0x0c46c4 | Địa chỉ FDE: 0x122298 | Kích thước: 84 bytes
//   0x0c46c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c46c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c46cc: 910043FD  add      x29, sp, #0x10
//   0x0c46d0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1285_0x0c46c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c46c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122298ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1286 | PC: 0x0c4718 | FDE: 0x1222b8 | Size: 256 bytes
// Hàm FDE #1286 | Địa chỉ PC: 0x0c4718 | Địa chỉ FDE: 0x1222b8 | Kích thước: 256 bytes
//   0x0c4718: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0c471c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c4720: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c4724: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1286_0x0c4718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4718ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1222b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1287 | PC: 0x0c4874 | FDE: 0x1222e8 | Size: 112 bytes [_ZN11fast_engine3Obj17_InitInlineValuesEPS0_PNS_7TypeObjEPNS_6EngineE]
// Hàm FDE #1287 | Địa chỉ PC: 0x0c4874 | Địa chỉ FDE: 0x1222e8 | Kích thước: 112 bytes
//   0x0c4874: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c4878: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c487c: 910043FD  add      x29, sp, #0x10
//   0x0c4880: F9416829  ldr      x9, [x1, #0x2d0]
static inline uint64_t fde_func_1287_0x0c4874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4874ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1222e8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1288 | PC: 0x0c48e4 | FDE: 0x122960 | Size: 256 bytes [_ZN11fast_engine3Obj23_MaterializeManagedDictEPS0_PNS_6EngineE]
// Hàm FDE #1288 | Địa chỉ PC: 0x0c48e4 | Địa chỉ FDE: 0x122960 | Kích thước: 256 bytes
//   0x0c48e4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c48e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c48ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c48f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1288_0x0c48e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c48e4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1289 | PC: 0x0c4abc | FDE: 0x122308 | Size: 256 bytes [_ZN11fast_engine7DictObj8_SetItemEPS0_PNS_3ObjES3_PNS_6EngineE]
// Hàm FDE #1289 | Địa chỉ PC: 0x0c4abc | Địa chỉ FDE: 0x122308 | Kích thước: 256 bytes
//   0x0c4abc: D10103FF  sub      sp, sp, #0x40
//   0x0c4ac0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c4ac4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c4ac8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1289_0x0c4abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4abcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1290 | PC: 0x0c4c0c | FDE: 0x122330 | Size: 256 bytes [_ZN11fast_engine3Obj23_StoreInstanceAttributeEPS0_S1_S1_PNS_6EngineE]
// Hàm FDE #1290 | Địa chỉ PC: 0x0c4c0c | Địa chỉ FDE: 0x122330 | Kích thước: 256 bytes
//   0x0c4c0c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c4c10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c4c14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c4c18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1290_0x0c4c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4c0cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1291 | PC: 0x0c4d38 | FDE: 0x122990 | Size: 256 bytes [_ZN11fast_engine3Obj14GenericGetDictEPS0_PNS_6EngineE]
// Hàm FDE #1291 | Địa chỉ PC: 0x0c4d38 | Địa chỉ FDE: 0x122990 | Kích thước: 256 bytes
//   0x0c4d38: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c4d3c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c4d40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c4d44: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1291_0x0c4d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4d38ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1292 | PC: 0x0c4f28 | FDE: 0x1229c0 | Size: 256 bytes
// Hàm FDE #1292 | Địa chỉ PC: 0x0c4f28 | Địa chỉ FDE: 0x1229c0 | Kích thước: 256 bytes
//   0x0c4f28: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0c4f2c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c4f30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c4f34: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1292_0x0c4f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4f28ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1229c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1293 | PC: 0x0c6360 | FDE: 0x122358 | Size: 232 bytes [_ZN11fast_engine3Obj24_TryGetInstanceAttributeEPS0_S1_PS1_PNS_6EngineE]
// Hàm FDE #1293 | Địa chỉ PC: 0x0c6360 | Địa chỉ FDE: 0x122358 | Kích thước: 232 bytes
//   0x0c6360: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c6364: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c6368: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c636c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1293_0x0c6360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6360ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122358ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1294 | PC: 0x0c6448 | FDE: 0x122380 | Size: 164 bytes [_ZN11fast_engine3Obj20_IsInstanceDictEmptyEPS0_]
// Hàm FDE #1294 | Địa chỉ PC: 0x0c6448 | Địa chỉ FDE: 0x122380 | Kích thước: 164 bytes
//   0x0c6448: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c644c: 910003FD  mov      x29, sp
//   0x0c6450: F9401408  ldr      x8, [x0, #0x28]
//   0x0c6454: F9408109  ldr      x9, [x8, #0x100]
static inline uint64_t fde_func_1294_0x0c6448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6448ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x122380ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1295 | PC: 0x0c64ec | FDE: 0x1223a0 | Size: 256 bytes [_ZN11fast_engine3Obj15_SetManagedDictEPS0_S1_PNS_6EngineE]
// Hàm FDE #1295 | Địa chỉ PC: 0x0c64ec | Địa chỉ FDE: 0x1223a0 | Kích thước: 256 bytes
//   0x0c64ec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c64f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c64f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c64f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1295_0x0c64ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c64ecULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1223a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1296 | PC: 0x0c6678 | FDE: 0x1223c8 | Size: 256 bytes [_ZN11fast_engine7DictObj17_DetachFromObjectEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1296 | Địa chỉ PC: 0x0c6678 | Địa chỉ FDE: 0x1223c8 | Kích thước: 256 bytes
//   0x0c6678: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c667c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c6680: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c6684: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1296_0x0c6678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6678ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1223c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1297 | PC: 0x0c67e0 | FDE: 0x1223f0 | Size: 12 bytes [_ZN11fast_engine3Obj16ClearManagedDictEPS0_PNS_6EngineE]
// Hàm FDE #1297 | Địa chỉ PC: 0x0c67e0 | Địa chỉ FDE: 0x1223f0 | Kích thước: 12 bytes
//   0x0c67e0: AA0103E2  mov      x2, x1
//   0x0c67e4: AA1F03E1  mov      x1, xzr
//   0x0c67e8: 17FDF69E  b        #0x44260
static inline uint64_t fde_func_1297_0x0c67e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c67e0ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1223f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1298 | PC: 0x0c67ec | FDE: 0x122408 | Size: 256 bytes
// Hàm FDE #1298 | Địa chỉ PC: 0x0c67ec | Địa chỉ FDE: 0x122408 | Kích thước: 256 bytes
//   0x0c67ec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c67f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c67f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c67f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1298_0x0c67ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c67ecULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1299 | PC: 0x0c69e0 | FDE: 0x1229f8 | Size: 256 bytes [_ZN11fast_engine3Obj12_DictSetItemEPNS_7TypeObjEPS0_PS3_S3_S3_PNS_6EngineE]
// Hàm FDE #1299 | Địa chỉ PC: 0x0c69e0 | Địa chỉ FDE: 0x1229f8 | Kích thước: 256 bytes
//   0x0c69e0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0c69e4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c69e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c69ec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1299_0x0c69e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c69e0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1229f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1300 | PC: 0x0c6bb8 | FDE: 0x122430 | Size: 4 bytes [_ZN11fast_engine8DictKeys7_DecRefEPS0_PNS_6EngineE]
// Hàm FDE #1300 | Địa chỉ PC: 0x0c6bb8 | Địa chỉ FDE: 0x122430 | Kích thước: 4 bytes
//   0x0c6bb8: 17FFFF0D  b        #0xc67ec
static inline uint64_t fde_func_1300_0x0c6bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6bb8ULL ^ (static_cast<uint64_t>(0x17ffff0dULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x122430ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1301 | PC: 0x0c6bbc | FDE: 0x122448 | Size: 48 bytes [_ZN11fast_engine8DictKeys26_GetVersionForCurrentStateEPS0_PNS_6EngineE]
// Hàm FDE #1301 | Địa chỉ PC: 0x0c6bbc | Địa chỉ FDE: 0x122448 | Kích thước: 48 bytes
//   0x0c6bbc: AA0003E8  mov      x8, x0
//   0x0c6bc0: B9401000  ldr      w0, [x0, #0x10]
//   0x0c6bc4: 35000120  cbnz     w0, #0xc6be8
//   0x0c6bc8: 52928809  mov      w9, #0x9440
static inline uint64_t fde_func_1301_0x0c6bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6bbcULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xb9401000ULL) ^ 0x122448ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1302 | PC: 0x0c6bec | FDE: 0x122460 | Size: 36 bytes [_ZN11fast_engine7DictObjD0Ev]
// Hàm FDE #1302 | Địa chỉ PC: 0x0c6bec | Địa chỉ FDE: 0x122460 | Kích thước: 36 bytes
//   0x0c6bec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c6bf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c6bf4: 910043FD  add      x29, sp, #0x10
//   0x0c6bf8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1302_0x0c6bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6becULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122460ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1303 | PC: 0x0c6c10 | FDE: 0x122480 | Size: 36 bytes [_ZN11fast_engine11DictViewObjD0Ev]
// Hàm FDE #1303 | Địa chỉ PC: 0x0c6c10 | Địa chỉ FDE: 0x122480 | Kích thước: 36 bytes
//   0x0c6c10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c6c14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c6c18: 910043FD  add      x29, sp, #0x10
//   0x0c6c1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1303_0x0c6c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6c10ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122480ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1304 | PC: 0x0c6c34 | FDE: 0x1224a0 | Size: 256 bytes
// Hàm FDE #1304 | Địa chỉ PC: 0x0c6c34 | Địa chỉ FDE: 0x1224a0 | Kích thước: 256 bytes
//   0x0c6c34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c6c38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c6c3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c6c40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1304_0x0c6c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6c34ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1224a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1305 | PC: 0x0c6dcc | FDE: 0x1224c0 | Size: 256 bytes
// Hàm FDE #1305 | Địa chỉ PC: 0x0c6dcc | Địa chỉ FDE: 0x1224c0 | Kích thước: 256 bytes
//   0x0c6dcc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c6dd0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c6dd4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c6dd8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1305_0x0c6dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6dccULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1224c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1306 | PC: 0x0c6fe8 | FDE: 0x1224e8 | Size: 256 bytes
// Hàm FDE #1306 | Địa chỉ PC: 0x0c6fe8 | Địa chỉ FDE: 0x1224e8 | Kích thước: 256 bytes
//   0x0c6fe8: D101C3FF  sub      sp, sp, #0x70
//   0x0c6fec: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0c6ff0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0c6ff4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1306_0x0c6fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6fe8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1224e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1307 | PC: 0x0c7854 | FDE: 0x122518 | Size: 256 bytes
// Hàm FDE #1307 | Địa chỉ PC: 0x0c7854 | Địa chỉ FDE: 0x122518 | Kích thước: 256 bytes
//   0x0c7854: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c7858: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c785c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c7860: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1307_0x0c7854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7854ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1308 | PC: 0x0c79a4 | FDE: 0x122a30 | Size: 256 bytes
// Hàm FDE #1308 | Địa chỉ PC: 0x0c79a4 | Địa chỉ FDE: 0x122a30 | Kích thước: 256 bytes
//   0x0c79a4: D101C3FF  sub      sp, sp, #0x70
//   0x0c79a8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0c79ac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0c79b0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1308_0x0c79a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c79a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x122a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1309 | PC: 0x0c7bc0 | FDE: 0x122a68 | Size: 256 bytes
// Hàm FDE #1309 | Địa chỉ PC: 0x0c7bc0 | Địa chỉ FDE: 0x122a68 | Kích thước: 256 bytes
//   0x0c7bc0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c7bc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c7bc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c7bcc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1309_0x0c7bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7bc0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1310 | PC: 0x0c7cd8 | FDE: 0x122540 | Size: 36 bytes [_ZN11fast_engine14DictIterObjOptD0Ev]
// Hàm FDE #1310 | Địa chỉ PC: 0x0c7cd8 | Địa chỉ FDE: 0x122540 | Kích thước: 36 bytes
//   0x0c7cd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c7cdc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c7ce0: 910043FD  add      x29, sp, #0x10
//   0x0c7ce4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1310_0x0c7cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7cd8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122540ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1311 | PC: 0x0c7cfc | FDE: 0x122560 | Size: 148 bytes [_ZN11fast_engine14DictIterObjOpt5ClearEPNS_6EngineE]
// Hàm FDE #1311 | Địa chỉ PC: 0x0c7cfc | Địa chỉ FDE: 0x122560 | Kích thước: 148 bytes
//   0x0c7cfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c7d00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c7d04: 910043FD  add      x29, sp, #0x10
//   0x0c7d08: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1311_0x0c7cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7cfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122560ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1312 | PC: 0x0c7d90 | FDE: 0x122580 | Size: 256 bytes
// Hàm FDE #1312 | Địa chỉ PC: 0x0c7d90 | Địa chỉ FDE: 0x122580 | Kích thước: 256 bytes
//   0x0c7d90: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c7d94: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c7d98: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c7d9c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1312_0x0c7d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7d90ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1313 | PC: 0x0c7ea8 | FDE: 0x122b48 | Size: 96 bytes [_ZN11fast_engine18AllocExceptionTypeEPNS_6EngineE]
// Hàm FDE #1313 | Địa chỉ PC: 0x0c7ea8 | Địa chỉ FDE: 0x122b48 | Kích thước: 96 bytes
//   0x0c7ea8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c7eac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c7eb0: 910043FD  add      x29, sp, #0x10
//   0x0c7eb4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1313_0x0c7ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7ea8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122b48ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1314 | PC: 0x0c7f08 | FDE: 0x122b70 | Size: 224 bytes [_ZN11fast_engine17InitExceptionTypeEPNS_6EngineE]
// Hàm FDE #1314 | Địa chỉ PC: 0x0c7f08 | Địa chỉ FDE: 0x122b70 | Kích thước: 224 bytes
//   0x0c7f08: D10143FF  sub      sp, sp, #0x50
//   0x0c7f0c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c7f10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c7f14: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1314_0x0c7f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7f08ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122b70ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1315 | PC: 0x0c7fe8 | FDE: 0x122ba0 | Size: 148 bytes
// Hàm FDE #1315 | Địa chỉ PC: 0x0c7fe8 | Địa chỉ FDE: 0x122ba0 | Kích thước: 148 bytes
//   0x0c7fe8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c7fec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c7ff0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c7ff4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1315_0x0c7fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7fe8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122ba0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1316 | PC: 0x0c807c | FDE: 0x122bd0 | Size: 256 bytes
// Hàm FDE #1316 | Địa chỉ PC: 0x0c807c | Địa chỉ FDE: 0x122bd0 | Kích thước: 256 bytes
//   0x0c807c: D10143FF  sub      sp, sp, #0x50
//   0x0c8080: F90013F5  str      x21, [sp, #0x20]
//   0x0c8084: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8088: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1316_0x0c807c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c807cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x122bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1317 | PC: 0x0c81fc | FDE: 0x122bf8 | Size: 96 bytes [_ZN11fast_engine18AllocTypeErrorTypeEPNS_6EngineE]
// Hàm FDE #1317 | Địa chỉ PC: 0x0c81fc | Địa chỉ FDE: 0x122bf8 | Kích thước: 96 bytes
//   0x0c81fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8200: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8204: 910043FD  add      x29, sp, #0x10
//   0x0c8208: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1317_0x0c81fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c81fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122bf8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1318 | PC: 0x0c825c | FDE: 0x122c20 | Size: 240 bytes [_ZN11fast_engine17InitTypeErrorTypeEPNS_6EngineE]
// Hàm FDE #1318 | Địa chỉ PC: 0x0c825c | Địa chỉ FDE: 0x122c20 | Kích thước: 240 bytes
//   0x0c825c: D10143FF  sub      sp, sp, #0x50
//   0x0c8260: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8264: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8268: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1318_0x0c825c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c825cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122c20ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1319 | PC: 0x0c834c | FDE: 0x122c50 | Size: 96 bytes [_ZN11fast_engine22AllocStopIterationTypeEPNS_6EngineE]
// Hàm FDE #1319 | Địa chỉ PC: 0x0c834c | Địa chỉ FDE: 0x122c50 | Kích thước: 96 bytes
//   0x0c834c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8350: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8354: 910043FD  add      x29, sp, #0x10
//   0x0c8358: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1319_0x0c834c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c834cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122c50ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1320 | PC: 0x0c83ac | FDE: 0x122c78 | Size: 240 bytes [_ZN11fast_engine21InitStopIterationTypeEPNS_6EngineE]
// Hàm FDE #1320 | Địa chỉ PC: 0x0c83ac | Địa chỉ FDE: 0x122c78 | Kích thước: 240 bytes
//   0x0c83ac: D10143FF  sub      sp, sp, #0x50
//   0x0c83b0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c83b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c83b8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1320_0x0c83ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c83acULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122c78ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1321 | PC: 0x0c849c | FDE: 0x122ca8 | Size: 96 bytes [_ZN11fast_engine21AllocRuntimeErrorTypeEPNS_6EngineE]
// Hàm FDE #1321 | Địa chỉ PC: 0x0c849c | Địa chỉ FDE: 0x122ca8 | Kích thước: 96 bytes
//   0x0c849c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c84a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c84a4: 910043FD  add      x29, sp, #0x10
//   0x0c84a8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1321_0x0c849c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c849cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122ca8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1322 | PC: 0x0c84fc | FDE: 0x122cd0 | Size: 240 bytes [_ZN11fast_engine20InitRuntimeErrorTypeEPNS_6EngineE]
// Hàm FDE #1322 | Địa chỉ PC: 0x0c84fc | Địa chỉ FDE: 0x122cd0 | Kích thước: 240 bytes
//   0x0c84fc: D10143FF  sub      sp, sp, #0x50
//   0x0c8500: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8504: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8508: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1322_0x0c84fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c84fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122cd0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1323 | PC: 0x0c85ec | FDE: 0x122d00 | Size: 96 bytes [_ZN11fast_engine19AllocValueErrorTypeEPNS_6EngineE]
// Hàm FDE #1323 | Địa chỉ PC: 0x0c85ec | Địa chỉ FDE: 0x122d00 | Kích thước: 96 bytes
//   0x0c85ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c85f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c85f4: 910043FD  add      x29, sp, #0x10
//   0x0c85f8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1323_0x0c85ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c85ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122d00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1324 | PC: 0x0c864c | FDE: 0x122d28 | Size: 240 bytes [_ZN11fast_engine18InitValueErrorTypeEPNS_6EngineE]
// Hàm FDE #1324 | Địa chỉ PC: 0x0c864c | Địa chỉ FDE: 0x122d28 | Kích thước: 240 bytes
//   0x0c864c: D10143FF  sub      sp, sp, #0x50
//   0x0c8650: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8654: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8658: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1324_0x0c864c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c864cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122d28ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1325 | PC: 0x0c873c | FDE: 0x122d58 | Size: 96 bytes [_ZN11fast_engine17AllocKeyErrorTypeEPNS_6EngineE]
// Hàm FDE #1325 | Địa chỉ PC: 0x0c873c | Địa chỉ FDE: 0x122d58 | Kích thước: 96 bytes
//   0x0c873c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8740: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8744: 910043FD  add      x29, sp, #0x10
//   0x0c8748: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1325_0x0c873c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c873cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122d58ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1326 | PC: 0x0c879c | FDE: 0x122d80 | Size: 240 bytes [_ZN11fast_engine16InitKeyErrorTypeEPNS_6EngineE]
// Hàm FDE #1326 | Địa chỉ PC: 0x0c879c | Địa chỉ FDE: 0x122d80 | Kích thước: 240 bytes
//   0x0c879c: D10143FF  sub      sp, sp, #0x50
//   0x0c87a0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c87a4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c87a8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1326_0x0c879c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c879cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122d80ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1327 | PC: 0x0c888c | FDE: 0x122db0 | Size: 96 bytes [_ZN11fast_engine23AllocAttributeErrorTypeEPNS_6EngineE]
// Hàm FDE #1327 | Địa chỉ PC: 0x0c888c | Địa chỉ FDE: 0x122db0 | Kích thước: 96 bytes
//   0x0c888c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8890: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8894: 910043FD  add      x29, sp, #0x10
//   0x0c8898: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1327_0x0c888c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c888cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122db0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1328 | PC: 0x0c88ec | FDE: 0x122dd8 | Size: 240 bytes [_ZN11fast_engine22InitAttributeErrorTypeEPNS_6EngineE]
// Hàm FDE #1328 | Địa chỉ PC: 0x0c88ec | Địa chỉ FDE: 0x122dd8 | Kích thước: 240 bytes
//   0x0c88ec: D10143FF  sub      sp, sp, #0x50
//   0x0c88f0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c88f4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c88f8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1328_0x0c88ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c88ecULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122dd8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1329 | PC: 0x0c89dc | FDE: 0x122e08 | Size: 96 bytes [_ZN11fast_engine19AllocIndexErrorTypeEPNS_6EngineE]
// Hàm FDE #1329 | Địa chỉ PC: 0x0c89dc | Địa chỉ FDE: 0x122e08 | Kích thước: 96 bytes
//   0x0c89dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c89e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c89e4: 910043FD  add      x29, sp, #0x10
//   0x0c89e8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1329_0x0c89dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c89dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122e08ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1330 | PC: 0x0c8a3c | FDE: 0x122e30 | Size: 240 bytes [_ZN11fast_engine18InitIndexErrorTypeEPNS_6EngineE]
// Hàm FDE #1330 | Địa chỉ PC: 0x0c8a3c | Địa chỉ FDE: 0x122e30 | Kích thước: 240 bytes
//   0x0c8a3c: D10143FF  sub      sp, sp, #0x50
//   0x0c8a40: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8a44: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8a48: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1330_0x0c8a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8a3cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122e30ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1331 | PC: 0x0c8b2c | FDE: 0x122e60 | Size: 96 bytes [_ZN11fast_engine18AllocNameErrorTypeEPNS_6EngineE]
// Hàm FDE #1331 | Địa chỉ PC: 0x0c8b2c | Địa chỉ FDE: 0x122e60 | Kích thước: 96 bytes
//   0x0c8b2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8b30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8b34: 910043FD  add      x29, sp, #0x10
//   0x0c8b38: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1331_0x0c8b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8b2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122e60ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1332 | PC: 0x0c8b8c | FDE: 0x122e88 | Size: 240 bytes [_ZN11fast_engine17InitNameErrorTypeEPNS_6EngineE]
// Hàm FDE #1332 | Địa chỉ PC: 0x0c8b8c | Địa chỉ FDE: 0x122e88 | Kích thước: 240 bytes
//   0x0c8b8c: D10143FF  sub      sp, sp, #0x50
//   0x0c8b90: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8b94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8b98: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1332_0x0c8b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8b8cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122e88ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1333 | PC: 0x0c8c7c | FDE: 0x122eb8 | Size: 96 bytes [_ZN11fast_engine20AllocImportErrorTypeEPNS_6EngineE]
// Hàm FDE #1333 | Địa chỉ PC: 0x0c8c7c | Địa chỉ FDE: 0x122eb8 | Kích thước: 96 bytes
//   0x0c8c7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8c80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8c84: 910043FD  add      x29, sp, #0x10
//   0x0c8c88: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1333_0x0c8c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8c7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122eb8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1334 | PC: 0x0c8cdc | FDE: 0x122ee0 | Size: 240 bytes [_ZN11fast_engine19InitImportErrorTypeEPNS_6EngineE]
// Hàm FDE #1334 | Địa chỉ PC: 0x0c8cdc | Địa chỉ FDE: 0x122ee0 | Kích thước: 240 bytes
//   0x0c8cdc: D10143FF  sub      sp, sp, #0x50
//   0x0c8ce0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8ce4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8ce8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1334_0x0c8cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8cdcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122ee0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1335 | PC: 0x0c8dcc | FDE: 0x122f10 | Size: 96 bytes [_ZN11fast_engine26AllocZeroDivisionErrorTypeEPNS_6EngineE]
// Hàm FDE #1335 | Địa chỉ PC: 0x0c8dcc | Địa chỉ FDE: 0x122f10 | Kích thước: 96 bytes
//   0x0c8dcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8dd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8dd4: 910043FD  add      x29, sp, #0x10
//   0x0c8dd8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1335_0x0c8dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8dccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122f10ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1336 | PC: 0x0c8e2c | FDE: 0x122f38 | Size: 240 bytes [_ZN11fast_engine25InitZeroDivisionErrorTypeEPNS_6EngineE]
// Hàm FDE #1336 | Địa chỉ PC: 0x0c8e2c | Địa chỉ FDE: 0x122f38 | Kích thước: 240 bytes
//   0x0c8e2c: D10143FF  sub      sp, sp, #0x50
//   0x0c8e30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8e34: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8e38: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1336_0x0c8e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8e2cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122f38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1337 | PC: 0x0c8f1c | FDE: 0x122f68 | Size: 96 bytes [_ZN11fast_engine22AllocOverflowErrorTypeEPNS_6EngineE]
// Hàm FDE #1337 | Địa chỉ PC: 0x0c8f1c | Địa chỉ FDE: 0x122f68 | Kích thước: 96 bytes
//   0x0c8f1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c8f20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c8f24: 910043FD  add      x29, sp, #0x10
//   0x0c8f28: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1337_0x0c8f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8f1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122f68ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1338 | PC: 0x0c8f7c | FDE: 0x122f90 | Size: 240 bytes [_ZN11fast_engine21InitOverflowErrorTypeEPNS_6EngineE]
// Hàm FDE #1338 | Địa chỉ PC: 0x0c8f7c | Địa chỉ FDE: 0x122f90 | Kích thước: 240 bytes
//   0x0c8f7c: D10143FF  sub      sp, sp, #0x50
//   0x0c8f80: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8f84: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8f88: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1338_0x0c8f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8f7cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122f90ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1339 | PC: 0x0c906c | FDE: 0x122fc0 | Size: 96 bytes [_ZN11fast_engine23AllocAssertionErrorTypeEPNS_6EngineE]
// Hàm FDE #1339 | Địa chỉ PC: 0x0c906c | Địa chỉ FDE: 0x122fc0 | Kích thước: 96 bytes
//   0x0c906c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c9070: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c9074: 910043FD  add      x29, sp, #0x10
//   0x0c9078: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1339_0x0c906c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c906cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122fc0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1340 | PC: 0x0c90cc | FDE: 0x122fe8 | Size: 240 bytes [_ZN11fast_engine22InitAssertionErrorTypeEPNS_6EngineE]
// Hàm FDE #1340 | Địa chỉ PC: 0x0c90cc | Địa chỉ FDE: 0x122fe8 | Kích thước: 240 bytes
//   0x0c90cc: D10143FF  sub      sp, sp, #0x50
//   0x0c90d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c90d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c90d8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1340_0x0c90cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c90ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122fe8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1341 | PC: 0x0c91bc | FDE: 0x123018 | Size: 96 bytes [_ZN11fast_engine20AllocSystemErrorTypeEPNS_6EngineE]
// Hàm FDE #1341 | Địa chỉ PC: 0x0c91bc | Địa chỉ FDE: 0x123018 | Kích thước: 96 bytes
//   0x0c91bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c91c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c91c4: 910043FD  add      x29, sp, #0x10
//   0x0c91c8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1341_0x0c91bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c91bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123018ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1342 | PC: 0x0c921c | FDE: 0x123040 | Size: 240 bytes [_ZN11fast_engine19InitSystemErrorTypeEPNS_6EngineE]
// Hàm FDE #1342 | Địa chỉ PC: 0x0c921c | Địa chỉ FDE: 0x123040 | Kích thước: 240 bytes
//   0x0c921c: D10143FF  sub      sp, sp, #0x50
//   0x0c9220: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c9224: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c9228: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1342_0x0c921c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c921cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x123040ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1343 | PC: 0x0c930c | FDE: 0x123070 | Size: 96 bytes [_ZN11fast_engine20AllocMemoryErrorTypeEPNS_6EngineE]
// Hàm FDE #1343 | Địa chỉ PC: 0x0c930c | Địa chỉ FDE: 0x123070 | Kích thước: 96 bytes
//   0x0c930c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c9310: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c9314: 910043FD  add      x29, sp, #0x10
//   0x0c9318: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1343_0x0c930c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c930cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123070ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1344 | PC: 0x0c936c | FDE: 0x123098 | Size: 240 bytes [_ZN11fast_engine19InitMemoryErrorTypeEPNS_6EngineE]
// Hàm FDE #1344 | Địa chỉ PC: 0x0c936c | Địa chỉ FDE: 0x123098 | Kích thước: 240 bytes
//   0x0c936c: D10143FF  sub      sp, sp, #0x50
//   0x0c9370: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c9374: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c9378: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1344_0x0c936c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c936cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x123098ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1345 | PC: 0x0c945c | FDE: 0x1230c8 | Size: 96 bytes [_ZN11fast_engine28AllocNotImplementedErrorTypeEPNS_6EngineE]
// Hàm FDE #1345 | Địa chỉ PC: 0x0c945c | Địa chỉ FDE: 0x1230c8 | Kích thước: 96 bytes
//   0x0c945c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c9460: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c9464: 910043FD  add      x29, sp, #0x10
//   0x0c9468: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1345_0x0c945c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c945cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1230c8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1346 | PC: 0x0c94bc | FDE: 0x1230f0 | Size: 240 bytes [_ZN11fast_engine27InitNotImplementedErrorTypeEPNS_6EngineE]
// Hàm FDE #1346 | Địa chỉ PC: 0x0c94bc | Địa chỉ FDE: 0x1230f0 | Kích thước: 240 bytes
//   0x0c94bc: D10143FF  sub      sp, sp, #0x50
//   0x0c94c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c94c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c94c8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1346_0x0c94bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c94bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1230f0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1347 | PC: 0x0c95ac | FDE: 0x122a98 | Size: 100 bytes [_ZN11fast_engine15ExceptionObjectC1EPNS_3ObjEPNS_6EngineEPNS_7TypeObjE]
// Hàm FDE #1347 | Địa chỉ PC: 0x0c95ac | Địa chỉ FDE: 0x122a98 | Kích thước: 100 bytes
//   0x0c95ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c95b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c95b4: 910043FD  add      x29, sp, #0x10
//   0x0c95b8: AA0303E8  mov      x8, x3
static inline uint64_t fde_func_1347_0x0c95ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c95acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122a98ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1348 | PC: 0x0c9610 | FDE: 0x122ab8 | Size: 56 bytes [_ZN11fast_engine15ExceptionObject5ClearEPNS_6EngineE]
// Hàm FDE #1348 | Địa chỉ PC: 0x0c9610 | Địa chỉ FDE: 0x122ab8 | Kích thước: 56 bytes
//   0x0c9610: F9402008  ldr      x8, [x0, #0x40]
//   0x0c9614: B4000128  cbz      x8, #0xc9638
//   0x0c9618: B9402109  ldr      w9, [x8, #0x20]
//   0x0c961c: 7100093F  cmp      w9, #2
static inline uint64_t fde_func_1348_0x0c9610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9610ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xb4000128ULL) ^ 0x122ab8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1349 | PC: 0x0c9648 | FDE: 0x123120 | Size: 256 bytes [_ZN11fast_engine15ExceptionObject4InitEPNS_6EngineE]
// Hàm FDE #1349 | Địa chỉ PC: 0x0c9648 | Địa chỉ FDE: 0x123120 | Kích thước: 256 bytes
//   0x0c9648: D10183FF  sub      sp, sp, #0x60
//   0x0c964c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c9650: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c9654: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1349_0x0c9648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9648ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x123120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1350 | PC: 0x0ca0ec | FDE: 0x122ad0 | Size: 256 bytes [_ZN11fast_engine15ExceptionObject16GetTypeFromErrorENS_9ErrorCodeE]
// Hàm FDE #1350 | Địa chỉ PC: 0x0ca0ec | Địa chỉ FDE: 0x122ad0 | Kích thước: 256 bytes
//   0x0ca0ec: 51000808  sub      w8, w0, #2
//   0x0ca0f0: 7101411F  cmp      w8, #0x50
//   0x0ca0f4: 54000328  b.hi     #0xca158
//   0x0ca0f8: D0000229  adrp     x9, #0x110000
static inline uint64_t fde_func_1350_0x0ca0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca0ecULL ^ (static_cast<uint64_t>(0x51000808ULL) << 13);
    acc = (acc + a1 + 0x7101411fULL) ^ 0x122ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1351 | PC: 0x0ca1f8 | FDE: 0x122ae8 | Size: 256 bytes [_ZN11fast_engine15ExceptionObject16GetErrorFromTypeEPNS_7TypeObjE]
// Hàm FDE #1351 | Địa chỉ PC: 0x0ca1f8 | Địa chỉ FDE: 0x122ae8 | Kích thước: 256 bytes
//   0x0ca1f8: B00003A8  adrp     x8, #0x13f000
//   0x0ca1fc: F9465908  ldr      x8, [x8, #0xcb0]
//   0x0ca200: F9400108  ldr      x8, [x8]
//   0x0ca204: EB00011F  cmp      x8, x0
static inline uint64_t fde_func_1351_0x0ca1f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca1f8ULL ^ (static_cast<uint64_t>(0xb00003a8ULL) << 13);
    acc = (acc + a1 + 0xf9465908ULL) ^ 0x122ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1352 | PC: 0x0ca384 | FDE: 0x123150 | Size: 248 bytes [_ZN11fast_engine15ExceptionObject15CreateFromErrorEPNS_6EngineENS_9ErrorCodeERKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE]
// Hàm FDE #1352 | Địa chỉ PC: 0x0ca384 | Địa chỉ FDE: 0x123150 | Kích thước: 248 bytes
//   0x0ca384: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ca388: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ca38c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ca390: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1352_0x0ca384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca384ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123150ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1353 | PC: 0x0ca47c | FDE: 0x122b00 | Size: 256 bytes [_ZN11fast_engine15ExceptionObject7MatchesEPKNS_3ObjES3_PNS_6EngineE]
// Hàm FDE #1353 | Địa chỉ PC: 0x0ca47c | Địa chỉ FDE: 0x122b00 | Kích thước: 256 bytes
//   0x0ca47c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ca480: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ca484: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ca488: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1353_0x0ca47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca47cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1354 | PC: 0x0ca57c | FDE: 0x122b28 | Size: 36 bytes [_ZN11fast_engine15ExceptionObjectD0Ev]
// Hàm FDE #1354 | Địa chỉ PC: 0x0ca57c | Địa chỉ FDE: 0x122b28 | Kích thước: 36 bytes
//   0x0ca57c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ca580: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ca584: 910043FD  add      x29, sp, #0x10
//   0x0ca588: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1354_0x0ca57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca57cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x122b28ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1355 | PC: 0x0ca5a0 | FDE: 0x123300 | Size: 96 bytes [_ZN11fast_engine16AllocExtDictTypeEPNS_6EngineE]
// Hàm FDE #1355 | Địa chỉ PC: 0x0ca5a0 | Địa chỉ FDE: 0x123300 | Kích thước: 96 bytes
//   0x0ca5a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ca5a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ca5a8: 910043FD  add      x29, sp, #0x10
//   0x0ca5ac: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1355_0x0ca5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca5a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123300ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1356 | PC: 0x0ca600 | FDE: 0x123328 | Size: 256 bytes [_ZN11fast_engine15InitExtDictTypeEPNS_6EngineE]
// Hàm FDE #1356 | Địa chỉ PC: 0x0ca600 | Địa chỉ FDE: 0x123328 | Kích thước: 256 bytes
//   0x0ca600: D10103FF  sub      sp, sp, #0x40
//   0x0ca604: F90013F3  str      x19, [sp, #0x20]
//   0x0ca608: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ca60c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1356_0x0ca600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca600ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x123328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1357 | PC: 0x0ca7c0 | FDE: 0x123180 | Size: 44 bytes
// Hàm FDE #1357 | Địa chỉ PC: 0x0ca7c0 | Địa chỉ FDE: 0x123180 | Kích thước: 44 bytes
//   0x0ca7c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca7c4: 910003FD  mov      x29, sp
//   0x0ca7c8: B00003A8  adrp     x8, #0x13f000
//   0x0ca7cc: F947C508  ldr      x8, [x8, #0xf88]
static inline uint64_t fde_func_1357_0x0ca7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca7c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123180ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1358 | PC: 0x0ca7ec | FDE: 0x1231a0 | Size: 44 bytes
// Hàm FDE #1358 | Địa chỉ PC: 0x0ca7ec | Địa chỉ FDE: 0x1231a0 | Kích thước: 44 bytes
//   0x0ca7ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca7f0: 910003FD  mov      x29, sp
//   0x0ca7f4: B00003A8  adrp     x8, #0x13f000
//   0x0ca7f8: F947C508  ldr      x8, [x8, #0xf88]
static inline uint64_t fde_func_1358_0x0ca7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca7ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1231a0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1359 | PC: 0x0ca818 | FDE: 0x1231c0 | Size: 12 bytes
// Hàm FDE #1359 | Địa chỉ PC: 0x0ca818 | Địa chỉ FDE: 0x1231c0 | Kích thước: 12 bytes
//   0x0ca818: F9400008  ldr      x8, [x0]
//   0x0ca81c: F9402502  ldr      x2, [x8, #0x48]
//   0x0ca820: D61F0040  br       x2
static inline uint64_t fde_func_1359_0x0ca818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca818ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9402502ULL) ^ 0x1231c0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1360 | PC: 0x0ca824 | FDE: 0x1231d8 | Size: 92 bytes
// Hàm FDE #1360 | Địa chỉ PC: 0x0ca824 | Địa chỉ FDE: 0x1231d8 | Kích thước: 92 bytes
//   0x0ca824: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca828: 910003FD  mov      x29, sp
//   0x0ca82c: F9401428  ldr      x8, [x1, #0x28]
//   0x0ca830: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_1360_0x0ca824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca824ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1231d8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1361 | PC: 0x0ca880 | FDE: 0x1231f8 | Size: 28 bytes
// Hàm FDE #1361 | Địa chỉ PC: 0x0ca880 | Địa chỉ FDE: 0x1231f8 | Kích thước: 28 bytes
//   0x0ca880: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca884: 910003FD  mov      x29, sp
//   0x0ca888: AA0303E0  mov      x0, x3
//   0x0ca88c: 97FDE8DD  bl       #0x44c00
static inline uint64_t fde_func_1361_0x0ca880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca880ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1231f8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1362 | PC: 0x0ca89c | FDE: 0x123218 | Size: 92 bytes
// Hàm FDE #1362 | Địa chỉ PC: 0x0ca89c | Địa chỉ FDE: 0x123218 | Kích thước: 92 bytes
//   0x0ca89c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca8a0: 910003FD  mov      x29, sp
//   0x0ca8a4: F9401428  ldr      x8, [x1, #0x28]
//   0x0ca8a8: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_1362_0x0ca89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca89cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123218ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1363 | PC: 0x0ca8f8 | FDE: 0x123238 | Size: 240 bytes
// Hàm FDE #1363 | Địa chỉ PC: 0x0ca8f8 | Địa chỉ FDE: 0x123238 | Kích thước: 240 bytes
//   0x0ca8f8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ca8fc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ca900: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ca904: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1363_0x0ca8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca8f8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x123238ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1364 | PC: 0x0ca9e8 | FDE: 0x123260 | Size: 24 bytes
// Hàm FDE #1364 | Địa chỉ PC: 0x0ca9e8 | Địa chỉ FDE: 0x123260 | Kích thước: 24 bytes
//   0x0ca9e8: F9400028  ldr      x8, [x1]
//   0x0ca9ec: F9403502  ldr      x2, [x8, #0x68]
//   0x0ca9f0: AA0003E8  mov      x8, x0
//   0x0ca9f4: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1364_0x0ca9e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca9e8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9403502ULL) ^ 0x123260ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1365 | PC: 0x0caa00 | FDE: 0x123350 | Size: 148 bytes
// Hàm FDE #1365 | Địa chỉ PC: 0x0caa00 | Địa chỉ FDE: 0x123350 | Kích thước: 148 bytes
//   0x0caa00: D10103FF  sub      sp, sp, #0x40
//   0x0caa04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0caa08: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0caa0c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1365_0x0caa00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0caa00ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x123350ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1366 | PC: 0x0caa94 | FDE: 0x123278 | Size: 72 bytes [_ZN11fast_engine10ExtDictObjC2EPNS_6EngineEl]
// Hàm FDE #1366 | Địa chỉ PC: 0x0caa94 | Địa chỉ FDE: 0x123278 | Kích thước: 72 bytes
//   0x0caa94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0caa98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0caa9c: 910043FD  add      x29, sp, #0x10
//   0x0caaa0: B00003A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1366_0x0caa94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0caa94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123278ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1367 | PC: 0x0caadc | FDE: 0x123298 | Size: 12 bytes [_ZN11fast_engine10ExtDictObj5ClearEPNS_6EngineE]
// Hàm FDE #1367 | Địa chỉ PC: 0x0caadc | Địa chỉ FDE: 0x123298 | Kích thước: 12 bytes
//   0x0caadc: F9400008  ldr      x8, [x0]
//   0x0caae0: F9403101  ldr      x1, [x8, #0x60]
//   0x0caae4: D61F0020  br       x1
static inline uint64_t fde_func_1367_0x0caadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0caadcULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9403101ULL) ^ 0x123298ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1368 | PC: 0x0caae8 | FDE: 0x1232b0 | Size: 52 bytes [_ZN11fast_engine10ExtDictObj6ToDictEPNS_6EngineE]
// Hàm FDE #1368 | Địa chỉ PC: 0x0caae8 | Địa chỉ FDE: 0x1232b0 | Kích thước: 52 bytes
//   0x0caae8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0caaec: 910003FD  mov      x29, sp
//   0x0caaf0: B00003A8  adrp     x8, #0x13f000
//   0x0caaf4: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1368_0x0caae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0caae8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1232b0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1369 | PC: 0x0cab1c | FDE: 0x1232d0 | Size: 4 bytes [_ZN11fast_engine10ExtDictObjD0Ev]
// Hàm FDE #1369 | Địa chỉ PC: 0x0cab1c | Địa chỉ FDE: 0x1232d0 | Kích thước: 4 bytes
//   0x0cab1c: D4200020  brk      #1
static inline uint64_t fde_func_1369_0x0cab1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cab1cULL ^ (static_cast<uint64_t>(0xd4200020ULL) << 13);
    acc = (acc + a1 + 0xa9007d1fULL) ^ 0x1232d0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1370 | PC: 0x0cab20 | FDE: 0x1232e8 | Size: 12 bytes [_ZN11fast_engine10ExtDictObj12KeySetExternEPNS_6EngineE]
// Hàm FDE #1370 | Địa chỉ PC: 0x0cab20 | Địa chỉ FDE: 0x1232e8 | Kích thước: 12 bytes
//   0x0cab20: A9007D1F  stp      xzr, xzr, [x8]
//   0x0cab24: F900091F  str      xzr, [x8, #0x10]
//   0x0cab28: D65F03C0  ret      
static inline uint64_t fde_func_1370_0x0cab20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cab20ULL ^ (static_cast<uint64_t>(0xa9007d1fULL) << 13);
    acc = (acc + a1 + 0xf900091fULL) ^ 0x1232e8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1371 | PC: 0x0cab2c | FDE: 0x1234a8 | Size: 96 bytes [_ZN11fast_engine16AllocExtListTypeEPNS_6EngineE]
// Hàm FDE #1371 | Địa chỉ PC: 0x0cab2c | Địa chỉ FDE: 0x1234a8 | Kích thước: 96 bytes
//   0x0cab2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cab30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cab34: 910043FD  add      x29, sp, #0x10
//   0x0cab38: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1371_0x0cab2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cab2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1234a8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1372 | PC: 0x0cab8c | FDE: 0x123378 | Size: 252 bytes [_ZN11fast_engine15InitExtListTypeEPNS_6EngineE]
// Hàm FDE #1372 | Địa chỉ PC: 0x0cab8c | Địa chỉ FDE: 0x123378 | Kích thước: 252 bytes
//   0x0cab8c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cab90: 910003FD  mov      x29, sp
//   0x0cab94: B00003A9  adrp     x9, #0x13f000
//   0x0cab98: F947E129  ldr      x9, [x9, #0xfc0]
static inline uint64_t fde_func_1372_0x0cab8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cab8cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123378ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1373 | PC: 0x0cac88 | FDE: 0x123398 | Size: 44 bytes
// Hàm FDE #1373 | Địa chỉ PC: 0x0cac88 | Địa chỉ FDE: 0x123398 | Kích thước: 44 bytes
//   0x0cac88: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cac8c: 910003FD  mov      x29, sp
//   0x0cac90: B00003A8  adrp     x8, #0x13f000
//   0x0cac94: F947C508  ldr      x8, [x8, #0xf88]
static inline uint64_t fde_func_1373_0x0cac88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cac88ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123398ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1374 | PC: 0x0cacb4 | FDE: 0x1233b8 | Size: 52 bytes
// Hàm FDE #1374 | Địa chỉ PC: 0x0cacb4 | Địa chỉ FDE: 0x1233b8 | Kích thước: 52 bytes
//   0x0cacb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cacb8: 910003FD  mov      x29, sp
//   0x0cacbc: B00003A8  adrp     x8, #0x13f000
//   0x0cacc0: F947C508  ldr      x8, [x8, #0xf88]
static inline uint64_t fde_func_1374_0x0cacb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cacb4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1233b8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1375 | PC: 0x0cace8 | FDE: 0x1233d8 | Size: 12 bytes
// Hàm FDE #1375 | Địa chỉ PC: 0x0cace8 | Địa chỉ FDE: 0x1233d8 | Kích thước: 12 bytes
//   0x0cace8: F9400008  ldr      x8, [x0]
//   0x0cacec: F9402502  ldr      x2, [x8, #0x48]
//   0x0cacf0: D61F0040  br       x2
static inline uint64_t fde_func_1375_0x0cace8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cace8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9402502ULL) ^ 0x1233d8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1376 | PC: 0x0cacf4 | FDE: 0x1233f0 | Size: 24 bytes
// Hàm FDE #1376 | Địa chỉ PC: 0x0cacf4 | Địa chỉ FDE: 0x1233f0 | Kích thước: 24 bytes
//   0x0cacf4: F9400008  ldr      x8, [x0]
//   0x0cacf8: F9401D03  ldr      x3, [x8, #0x38]
//   0x0cacfc: AA0103E8  mov      x8, x1
//   0x0cad00: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_1376_0x0cacf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cacf4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401d03ULL) ^ 0x1233f0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1377 | PC: 0x0cad0c | FDE: 0x123408 | Size: 24 bytes
// Hàm FDE #1377 | Địa chỉ PC: 0x0cad0c | Địa chỉ FDE: 0x123408 | Kích thước: 24 bytes
//   0x0cad0c: F9400008  ldr      x8, [x0]
//   0x0cad10: F9402103  ldr      x3, [x8, #0x40]
//   0x0cad14: AA0103E8  mov      x8, x1
//   0x0cad18: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_1377_0x0cad0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cad0cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9402103ULL) ^ 0x123408ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1378 | PC: 0x0cad24 | FDE: 0x123420 | Size: 24 bytes
// Hàm FDE #1378 | Địa chỉ PC: 0x0cad24 | Địa chỉ FDE: 0x123420 | Kích thước: 24 bytes
//   0x0cad24: F9400028  ldr      x8, [x1]
//   0x0cad28: F9403102  ldr      x2, [x8, #0x60]
//   0x0cad2c: AA0003E8  mov      x8, x0
//   0x0cad30: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1378_0x0cad24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cad24ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9403102ULL) ^ 0x123420ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1379 | PC: 0x0cad3c | FDE: 0x1234d0 | Size: 148 bytes
// Hàm FDE #1379 | Địa chỉ PC: 0x0cad3c | Địa chỉ FDE: 0x1234d0 | Kích thước: 148 bytes
//   0x0cad3c: D10103FF  sub      sp, sp, #0x40
//   0x0cad40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cad44: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0cad48: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1379_0x0cad3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cad3cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1234d0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1380 | PC: 0x0cadd0 | FDE: 0x123438 | Size: 72 bytes [_ZN11fast_engine10ExtListObjC2EPNS_6EngineEl]
// Hàm FDE #1380 | Địa chỉ PC: 0x0cadd0 | Địa chỉ FDE: 0x123438 | Kích thước: 72 bytes
//   0x0cadd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cadd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cadd8: 910043FD  add      x29, sp, #0x10
//   0x0caddc: B00003A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1380_0x0cadd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cadd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123438ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1381 | PC: 0x0cae18 | FDE: 0x123458 | Size: 12 bytes [_ZN11fast_engine10ExtListObj5ClearEPNS_6EngineE]
// Hàm FDE #1381 | Địa chỉ PC: 0x0cae18 | Địa chỉ FDE: 0x123458 | Kích thước: 12 bytes
//   0x0cae18: F9400008  ldr      x8, [x0]
//   0x0cae1c: F9402D01  ldr      x1, [x8, #0x58]
//   0x0cae20: D61F0020  br       x1
static inline uint64_t fde_func_1381_0x0cae18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cae18ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9402d01ULL) ^ 0x123458ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1382 | PC: 0x0cae24 | FDE: 0x123470 | Size: 52 bytes [_ZN11fast_engine10ExtListObj6ToListEPNS_6EngineE]
// Hàm FDE #1382 | Địa chỉ PC: 0x0cae24 | Địa chỉ FDE: 0x123470 | Kích thước: 52 bytes
//   0x0cae24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cae28: 910003FD  mov      x29, sp
//   0x0cae2c: B00003A8  adrp     x8, #0x13f000
//   0x0cae30: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1382_0x0cae24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cae24ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123470ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1383 | PC: 0x0cae58 | FDE: 0x123490 | Size: 4 bytes [_ZN11fast_engine10ExtListObjD0Ev]
// Hàm FDE #1383 | Địa chỉ PC: 0x0cae58 | Địa chỉ FDE: 0x123490 | Kích thước: 4 bytes
//   0x0cae58: D4200020  brk      #1
static inline uint64_t fde_func_1383_0x0cae58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cae58ULL ^ (static_cast<uint64_t>(0xd4200020ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x123490ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1384 | PC: 0x0cae5c | FDE: 0x1235e0 | Size: 96 bytes [_ZN11fast_engine14AllocFrameTypeEPNS_6EngineE]
// Hàm FDE #1384 | Địa chỉ PC: 0x0cae5c | Địa chỉ FDE: 0x1235e0 | Kích thước: 96 bytes
//   0x0cae5c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cae60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cae64: 910043FD  add      x29, sp, #0x10
//   0x0cae68: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1384_0x0cae5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cae5cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1235e0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1385 | PC: 0x0caebc | FDE: 0x1234f8 | Size: 28 bytes [_ZN11fast_engine13InitFrameTypeEPNS_6EngineE]
// Hàm FDE #1385 | Địa chỉ PC: 0x0caebc | Địa chỉ FDE: 0x1234f8 | Kích thước: 28 bytes
//   0x0caebc: B00003A8  adrp     x8, #0x13f000
//   0x0caec0: F9458908  ldr      x8, [x8, #0xb10]
//   0x0caec4: 90000009  adrp     x9, #0xca000
//   0x0caec8: 913B6129  add      x9, x9, #0xed8
static inline uint64_t fde_func_1385_0x0caebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0caebcULL ^ (static_cast<uint64_t>(0xb00003a8ULL) << 13);
    acc = (acc + a1 + 0xf9458908ULL) ^ 0x1234f8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1386 | PC: 0x0caed8 | FDE: 0x123608 | Size: 256 bytes
// Hàm FDE #1386 | Địa chỉ PC: 0x0caed8 | Địa chỉ FDE: 0x123608 | Kích thước: 256 bytes
//   0x0caed8: D106C3FF  sub      sp, sp, #0x1b0
//   0x0caedc: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0caee0: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0caee4: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_1386_0x0caed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0caed8ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9156ffcULL) ^ 0x123608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1387 | PC: 0x0cb244 | FDE: 0x123510 | Size: 160 bytes [_ZN11fast_engine8FrameObjC2EPNS_6EngineE]
// Hàm FDE #1387 | Địa chỉ PC: 0x0cb244 | Địa chỉ FDE: 0x123510 | Kích thước: 160 bytes
//   0x0cb244: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cb248: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cb24c: 910043FD  add      x29, sp, #0x10
//   0x0cb250: 900003A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1387_0x0cb244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb244ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123510ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1388 | PC: 0x0cb2e4 | FDE: 0x123530 | Size: 256 bytes [_ZN11fast_engine8FrameObj5ClearEPNS_6EngineE]
// Hàm FDE #1388 | Địa chỉ PC: 0x0cb2e4 | Địa chỉ FDE: 0x123530 | Kích thước: 256 bytes
//   0x0cb2e4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0cb2e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cb2ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cb2f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1388_0x0cb2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb2e4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1389 | PC: 0x0cb470 | FDE: 0x123558 | Size: 32 bytes [_ZN11fast_engine8FrameObj9SelfCacheEPNS_6EngineE]
// Hàm FDE #1389 | Địa chỉ PC: 0x0cb470 | Địa chỉ FDE: 0x123558 | Kích thước: 32 bytes
//   0x0cb470: F9402408  ldr      x8, [x0, #0x48]
//   0x0cb474: F9406509  ldr      x9, [x8, #0xc8]
//   0x0cb478: B4000069  cbz      x9, #0xcb484
//   0x0cb47c: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_1389_0x0cb470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb470ULL ^ (static_cast<uint64_t>(0xf9402408ULL) << 13);
    acc = (acc + a1 + 0xf9406509ULL) ^ 0x123558ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1390 | PC: 0x0cb490 | FDE: 0x123640 | Size: 84 bytes [_ZN11fast_engine8FrameObjD2Ev]
// Hàm FDE #1390 | Địa chỉ PC: 0x0cb490 | Địa chỉ FDE: 0x123640 | Kích thước: 84 bytes
//   0x0cb490: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cb494: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cb498: 910043FD  add      x29, sp, #0x10
//   0x0cb49c: 900003A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1390_0x0cb490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb490ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123640ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1391 | PC: 0x0cb4e4 | FDE: 0x123668 | Size: 92 bytes [_ZN11fast_engine8FrameObjD0Ev]
// Hàm FDE #1391 | Địa chỉ PC: 0x0cb4e4 | Địa chỉ FDE: 0x123668 | Kích thước: 92 bytes
//   0x0cb4e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cb4e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cb4ec: 910043FD  add      x29, sp, #0x10
//   0x0cb4f0: 900003A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1391_0x0cb4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb4e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123668ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1392 | PC: 0x0cb540 | FDE: 0x123690 | Size: 256 bytes [_ZN11fast_engine8FrameObj12FastToLocalsEPS0_PNS_6EngineE]
// Hàm FDE #1392 | Địa chỉ PC: 0x0cb540 | Địa chỉ FDE: 0x123690 | Kích thước: 256 bytes
//   0x0cb540: D10243FF  sub      sp, sp, #0x90
//   0x0cb544: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0cb548: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0cb54c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1392_0x0cb540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb540ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x123690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1393 | PC: 0x0cb7e0 | FDE: 0x123570 | Size: 244 bytes [_ZN11fast_engine8FrameObj12LocalsToFastEPS0_iPNS_6EngineE]
// Hàm FDE #1393 | Địa chỉ PC: 0x0cb7e0 | Địa chỉ FDE: 0x123570 | Kích thước: 244 bytes
//   0x0cb7e0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0cb7e4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0cb7e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0cb7ec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1393_0x0cb7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb7e0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x123570ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1394 | PC: 0x0cb8d4 | FDE: 0x123598 | Size: 256 bytes
// Hàm FDE #1394 | Địa chỉ PC: 0x0cb8d4 | Địa chỉ FDE: 0x123598 | Kích thước: 256 bytes
//   0x0cb8d4: D101C3FF  sub      sp, sp, #0x70
//   0x0cb8d8: F9000BFB  str      x27, [sp, #0x10]
//   0x0cb8dc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0cb8e0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1394_0x0cb8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb8d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x123598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1395 | PC: 0x0cba68 | FDE: 0x1235c8 | Size: 32 bytes [_ZN11fast_engine8FrameObj13GetLineNumberEPS0_]
// Hàm FDE #1395 | Địa chỉ PC: 0x0cba68 | Địa chỉ FDE: 0x1235c8 | Kích thước: 32 bytes
//   0x0cba68: F9402408  ldr      x8, [x0, #0x48]
//   0x0cba6c: B940780A  ldr      w10, [x0, #0x78]
//   0x0cba70: F9402509  ldr      x9, [x8, #0x48]
//   0x0cba74: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1395_0x0cba68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cba68ULL ^ (static_cast<uint64_t>(0xf9402408ULL) << 13);
    acc = (acc + a1 + 0xb940780aULL) ^ 0x1235c8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1396 | PC: 0x0cba88 | FDE: 0x1236c8 | Size: 256 bytes [_ZN11fast_engine8FrameObj9NewObjectEPNS_6EngineEPKNS_7FuncObjEPNS_7DictObjE]
// Hàm FDE #1396 | Địa chỉ PC: 0x0cba88 | Địa chỉ FDE: 0x1236c8 | Kích thước: 256 bytes
//   0x0cba88: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0cba8c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0cba90: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0cba94: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1396_0x0cba88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cba88ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1236c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1397 | PC: 0x0cbcd4 | FDE: 0x123700 | Size: 180 bytes [_ZN11fast_engine8FrameObj10BlockSetupEPS0_iiiPNS_6EngineE]
// Hàm FDE #1397 | Địa chỉ PC: 0x0cbcd4 | Địa chỉ FDE: 0x123700 | Kích thước: 180 bytes
//   0x0cbcd4: D10103FF  sub      sp, sp, #0x40
//   0x0cbcd8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cbcdc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0cbce0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1397_0x0cbcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbcd4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x123700ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1398 | PC: 0x0cbd88 | FDE: 0x123728 | Size: 188 bytes [_ZN11fast_engine8FrameObj8BlockPopEPS0_PNS_6EngineE]
// Hàm FDE #1398 | Địa chỉ PC: 0x0cbd88 | Địa chỉ FDE: 0x123728 | Kích thước: 188 bytes
//   0x0cbd88: D10143FF  sub      sp, sp, #0x50
//   0x0cbd8c: F90013F5  str      x21, [sp, #0x20]
//   0x0cbd90: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cbd94: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1398_0x0cbd88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbd88ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x123728ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1399 | PC: 0x0cbe44 | FDE: 0x123750 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv]
// Hàm FDE #1399 | Địa chỉ PC: 0x0cbe44 | Địa chỉ FDE: 0x123750 | Kích thước: 256 bytes
//   0x0cbe44: D101C3FF  sub      sp, sp, #0x70
//   0x0cbe48: F90013F9  str      x25, [sp, #0x20]
//   0x0cbe4c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0cbe50: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1399_0x0cbe44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbe44ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x123750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1400 | PC: 0x0cc00c | FDE: 0x123780 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi]
// Hàm FDE #1400 | Địa chỉ PC: 0x0cc00c | Địa chỉ FDE: 0x123780 | Kích thước: 256 bytes
//   0x0cc00c: D101C3FF  sub      sp, sp, #0x70
//   0x0cc010: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0cc014: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0cc018: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1400_0x0cc00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc00cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x123780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1401 | PC: 0x0cc1f4 | FDE: 0x123b68 | Size: 96 bytes [_ZN11fast_engine14AllocCFuncTypeEPNS_6EngineE]
// Hàm FDE #1401 | Địa chỉ PC: 0x0cc1f4 | Địa chỉ FDE: 0x123b68 | Kích thước: 96 bytes
//   0x0cc1f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cc1f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc1fc: 910043FD  add      x29, sp, #0x10
//   0x0cc200: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1401_0x0cc1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc1f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123b68ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1402 | PC: 0x0cc254 | FDE: 0x1237b8 | Size: 92 bytes [_ZN11fast_engine13InitCFuncTypeEPNS_6EngineE]
// Hàm FDE #1402 | Địa chỉ PC: 0x0cc254 | Địa chỉ FDE: 0x1237b8 | Kích thước: 92 bytes
//   0x0cc254: F0000388  adrp     x8, #0x13f000
//   0x0cc258: F946B508  ldr      x8, [x8, #0xd68]
//   0x0cc25c: 90000009  adrp     x9, #0xcc000
//   0x0cc260: 9000000B  adrp     x11, #0xcc000
static inline uint64_t fde_func_1402_0x0cc254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc254ULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0xf946b508ULL) ^ 0x1237b8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1403 | PC: 0x0cc2b0 | FDE: 0x1237d0 | Size: 252 bytes
// Hàm FDE #1403 | Địa chỉ PC: 0x0cc2b0 | Địa chỉ FDE: 0x1237d0 | Kích thước: 252 bytes
//   0x0cc2b0: D10103FF  sub      sp, sp, #0x40
//   0x0cc2b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0cc2b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cc2bc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1403_0x0cc2b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc2b0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1237d0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1404 | PC: 0x0cc3ac | FDE: 0x1237f8 | Size: 80 bytes
// Hàm FDE #1404 | Địa chỉ PC: 0x0cc3ac | Địa chỉ FDE: 0x1237f8 | Kích thước: 80 bytes
//   0x0cc3ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cc3b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc3b4: 910043FD  add      x29, sp, #0x10
//   0x0cc3b8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1404_0x0cc3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc3acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1237f8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1405 | PC: 0x0cc3fc | FDE: 0x123818 | Size: 176 bytes
// Hàm FDE #1405 | Địa chỉ PC: 0x0cc3fc | Địa chỉ FDE: 0x123818 | Kích thước: 176 bytes
//   0x0cc3fc: 32000048  orr      w8, w2, #1
//   0x0cc400: 71000D1F  cmp      w8, #3
//   0x0cc404: 54000141  b.ne     #0xcc42c
//   0x0cc408: F0000389  adrp     x9, #0x13f000
static inline uint64_t fde_func_1405_0x0cc3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc3fcULL ^ (static_cast<uint64_t>(0x32000048ULL) << 13);
    acc = (acc + a1 + 0x71000d1fULL) ^ 0x123818ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1406 | PC: 0x0cc4ac | FDE: 0x123b90 | Size: 256 bytes
// Hàm FDE #1406 | Địa chỉ PC: 0x0cc4ac | Địa chỉ FDE: 0x123b90 | Kích thước: 256 bytes
//   0x0cc4ac: D10103FF  sub      sp, sp, #0x40
//   0x0cc4b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cc4b4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0cc4b8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1406_0x0cc4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc4acULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x123b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1407 | PC: 0x0cc5ac | FDE: 0x123bb8 | Size: 96 bytes [_ZN11fast_engine16AllocCMethodTypeEPNS_6EngineE]
// Hàm FDE #1407 | Địa chỉ PC: 0x0cc5ac | Địa chỉ FDE: 0x123bb8 | Kích thước: 96 bytes
//   0x0cc5ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cc5b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc5b4: 910043FD  add      x29, sp, #0x10
//   0x0cc5b8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1407_0x0cc5ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc5acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123bb8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1408 | PC: 0x0cc60c | FDE: 0x123830 | Size: 92 bytes [_ZN11fast_engine15InitCMethodTypeEPNS_6EngineE]
// Hàm FDE #1408 | Địa chỉ PC: 0x0cc60c | Địa chỉ FDE: 0x123830 | Kích thước: 92 bytes
//   0x0cc60c: F0000388  adrp     x8, #0x13f000
//   0x0cc610: F9468108  ldr      x8, [x8, #0xd00]
//   0x0cc614: 90000009  adrp     x9, #0xcc000
//   0x0cc618: 9000000B  adrp     x11, #0xcc000
static inline uint64_t fde_func_1408_0x0cc60c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc60cULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0xf9468108ULL) ^ 0x123830ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1409 | PC: 0x0cc668 | FDE: 0x123be0 | Size: 256 bytes [_ZN11fast_engine8CFuncObjC1EPKNS_9MethodDefEPNS_3ObjES5_PNS_6EngineEl]
// Hàm FDE #1409 | Địa chỉ PC: 0x0cc668 | Địa chỉ FDE: 0x123be0 | Kích thước: 256 bytes
//   0x0cc668: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0cc66c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0cc670: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cc674: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1409_0x0cc668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc668ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x123be0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1410 | PC: 0x0cc7e0 | FDE: 0x123c10 | Size: 256 bytes
// Hàm FDE #1410 | Địa chỉ PC: 0x0cc7e0 | Địa chỉ FDE: 0x123c10 | Kích thước: 256 bytes
//   0x0cc7e0: D10203FF  sub      sp, sp, #0x80
//   0x0cc7e4: F90013FB  str      x27, [sp, #0x20]
//   0x0cc7e8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0cc7ec: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1410_0x0cc7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc7e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x123c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1411 | PC: 0x0cc9a0 | FDE: 0x123848 | Size: 36 bytes
// Hàm FDE #1411 | Địa chỉ PC: 0x0cc9a0 | Địa chỉ FDE: 0x123848 | Kích thước: 36 bytes
//   0x0cc9a0: F9402028  ldr      x8, [x1, #0x40]
//   0x0cc9a4: 9240F863  and      x3, x3, #0x7fffffffffffffff
//   0x0cc9a8: 39406109  ldrb     w9, [x8, #0x18]
//   0x0cc9ac: F9400505  ldr      x5, [x8, #8]
static inline uint64_t fde_func_1411_0x0cc9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc9a0ULL ^ (static_cast<uint64_t>(0xf9402028ULL) << 13);
    acc = (acc + a1 + 0x9240f863ULL) ^ 0x123848ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1412 | PC: 0x0cc9c4 | FDE: 0x123c48 | Size: 256 bytes
// Hàm FDE #1412 | Địa chỉ PC: 0x0cc9c4 | Địa chỉ FDE: 0x123c48 | Kích thước: 256 bytes
//   0x0cc9c4: D10183FF  sub      sp, sp, #0x60
//   0x0cc9c8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0cc9cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0cc9d0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1412_0x0cc9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc9c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x123c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1413 | PC: 0x0ccad0 | FDE: 0x123c78 | Size: 256 bytes
// Hàm FDE #1413 | Địa chỉ PC: 0x0ccad0 | Địa chỉ FDE: 0x123c78 | Kích thước: 256 bytes
//   0x0ccad0: D101C3FF  sub      sp, sp, #0x70
//   0x0ccad4: F90013F9  str      x25, [sp, #0x20]
//   0x0ccad8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ccadc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1413_0x0ccad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccad0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x123c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1414 | PC: 0x0ccbf4 | FDE: 0x123860 | Size: 148 bytes [_ZN11fast_engine8CFuncObj5ClearEPNS_6EngineE]
// Hàm FDE #1414 | Địa chỉ PC: 0x0ccbf4 | Địa chỉ FDE: 0x123860 | Kích thước: 148 bytes
//   0x0ccbf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ccbf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ccbfc: 910043FD  add      x29, sp, #0x10
//   0x0ccc00: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_1414_0x0ccbf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccbf4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123860ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1415 | PC: 0x0ccc88 | FDE: 0x123ca8 | Size: 176 bytes [_ZN11fast_engine10CMethodObjC1EPKNS_9MethodDefEPNS_3ObjES5_PKNS_7TypeObjEPNS_6EngineE]
// Hàm FDE #1415 | Địa chỉ PC: 0x0ccc88 | Địa chỉ FDE: 0x123ca8 | Kích thước: 176 bytes
//   0x0ccc88: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ccc8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ccc90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ccc94: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1415_0x0ccc88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccc88ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123ca8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1416 | PC: 0x0ccd38 | FDE: 0x123cd8 | Size: 96 bytes [_ZN11fast_engine13AllocFuncTypeEPNS_6EngineE]
// Hàm FDE #1416 | Địa chỉ PC: 0x0ccd38 | Địa chỉ FDE: 0x123cd8 | Kích thước: 96 bytes
//   0x0ccd38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ccd3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ccd40: 910043FD  add      x29, sp, #0x10
//   0x0ccd44: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1416_0x0ccd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccd38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123cd8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1417 | PC: 0x0ccd98 | FDE: 0x123880 | Size: 88 bytes [_ZN11fast_engine12InitFuncTypeEPNS_6EngineE]
// Hàm FDE #1417 | Địa chỉ PC: 0x0ccd98 | Địa chỉ FDE: 0x123880 | Kích thước: 88 bytes
//   0x0ccd98: F0000388  adrp     x8, #0x13f000
//   0x0ccd9c: F9460108  ldr      x8, [x8, #0xc00]
//   0x0ccda0: F000038A  adrp     x10, #0x13f000
//   0x0ccda4: 90000009  adrp     x9, #0xcc000
static inline uint64_t fde_func_1417_0x0ccd98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccd98ULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0xf9460108ULL) ^ 0x123880ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1418 | PC: 0x0ccdf0 | FDE: 0x123898 | Size: 60 bytes
// Hàm FDE #1418 | Địa chỉ PC: 0x0ccdf0 | Địa chỉ FDE: 0x123898 | Kích thước: 60 bytes
//   0x0ccdf0: B4000101  cbz      x1, #0xcce10
//   0x0ccdf4: F0000388  adrp     x8, #0x13f000
//   0x0ccdf8: F944D108  ldr      x8, [x8, #0x9a0]
//   0x0ccdfc: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1418_0x0ccdf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccdf0ULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xf0000388ULL) ^ 0x123898ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1419 | PC: 0x0cce2c | FDE: 0x123d00 | Size: 180 bytes
// Hàm FDE #1419 | Địa chỉ PC: 0x0cce2c | Địa chỉ FDE: 0x123d00 | Kích thước: 180 bytes
//   0x0cce2c: D10103FF  sub      sp, sp, #0x40
//   0x0cce30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cce34: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0cce38: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1419_0x0cce2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cce2cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x123d00ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1420 | PC: 0x0ccee0 | FDE: 0x1238b0 | Size: 220 bytes [_ZN11fast_engine7FuncObjC2EPNS_6EngineEPNS_7CodeObjEPNS_7DictObjEPNS_6StrObjE]
// Hàm FDE #1420 | Địa chỉ PC: 0x0ccee0 | Địa chỉ FDE: 0x1238b0 | Kích thước: 220 bytes
//   0x0ccee0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ccee4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ccee8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cceec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1420_0x0ccee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccee0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1238b0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1421 | PC: 0x0ccfbc | FDE: 0x1238d8 | Size: 48 bytes
// Hàm FDE #1421 | Địa chỉ PC: 0x0ccfbc | Địa chỉ FDE: 0x1238d8 | Kích thước: 48 bytes
//   0x0ccfbc: F9402829  ldr      x9, [x1, #0x50]
//   0x0ccfc0: AA0403E5  mov      x5, x4
//   0x0ccfc4: AA0203E8  mov      x8, x2
//   0x0ccfc8: 9240F864  and      x4, x3, #0x7fffffffffffffff
static inline uint64_t fde_func_1421_0x0ccfbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccfbcULL ^ (static_cast<uint64_t>(0xf9402829ULL) << 13);
    acc = (acc + a1 + 0xaa0403e5ULL) ^ 0x1238d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1422 | PC: 0x0ccfec | FDE: 0x1238f0 | Size: 256 bytes [_ZN11fast_engine7FuncObj5ClearEPNS_6EngineE]
// Hàm FDE #1422 | Địa chỉ PC: 0x0ccfec | Địa chỉ FDE: 0x1238f0 | Kích thước: 256 bytes
//   0x0ccfec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ccff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ccff4: 910043FD  add      x29, sp, #0x10
//   0x0ccff8: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_1422_0x0ccfec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccfecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1238f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1423 | PC: 0x0cd180 | FDE: 0x123d28 | Size: 96 bytes [_ZN11fast_engine15AllocMethodTypeEPNS_6EngineE]
// Hàm FDE #1423 | Địa chỉ PC: 0x0cd180 | Địa chỉ FDE: 0x123d28 | Kích thước: 96 bytes
//   0x0cd180: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cd184: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cd188: 910043FD  add      x29, sp, #0x10
//   0x0cd18c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1423_0x0cd180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd180ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123d28ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1424 | PC: 0x0cd1e0 | FDE: 0x123910 | Size: 96 bytes [_ZN11fast_engine14InitMethodTypeEPNS_6EngineE]
// Hàm FDE #1424 | Địa chỉ PC: 0x0cd1e0 | Địa chỉ FDE: 0x123910 | Kích thước: 96 bytes
//   0x0cd1e0: D0000388  adrp     x8, #0x13f000
//   0x0cd1e4: F9450508  ldr      x8, [x8, #0xa08]
//   0x0cd1e8: D0000389  adrp     x9, #0x13f000
//   0x0cd1ec: 9000000B  adrp     x11, #0xcd000
static inline uint64_t fde_func_1424_0x0cd1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd1e0ULL ^ (static_cast<uint64_t>(0xd0000388ULL) << 13);
    acc = (acc + a1 + 0xf9450508ULL) ^ 0x123910ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1425 | PC: 0x0cd240 | FDE: 0x123928 | Size: 28 bytes
// Hàm FDE #1425 | Địa chỉ PC: 0x0cd240 | Địa chỉ FDE: 0x123928 | Kích thước: 28 bytes
//   0x0cd240: B9402008  ldr      w8, [x0, #0x20]
//   0x0cd244: 7100091F  cmp      w8, #2
//   0x0cd248: 54000080  b.eq     #0xcd258
//   0x0cd24c: B9403808  ldr      w8, [x0, #0x38]
static inline uint64_t fde_func_1425_0x0cd240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd240ULL ^ (static_cast<uint64_t>(0xb9402008ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x123928ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1426 | PC: 0x0cd25c | FDE: 0x123940 | Size: 84 bytes
// Hàm FDE #1426 | Địa chỉ PC: 0x0cd25c | Địa chỉ FDE: 0x123940 | Kích thước: 84 bytes
//   0x0cd25c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cd260: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cd264: 910043FD  add      x29, sp, #0x10
//   0x0cd268: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1426_0x0cd25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd25cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123940ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1427 | PC: 0x0cd2b0 | FDE: 0x123960 | Size: 232 bytes
// Hàm FDE #1427 | Địa chỉ PC: 0x0cd2b0 | Địa chỉ FDE: 0x123960 | Kích thước: 232 bytes
//   0x0cd2b0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0cd2b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cd2b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cd2bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1427_0x0cd2b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd2b0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123960ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1428 | PC: 0x0cd398 | FDE: 0x123988 | Size: 196 bytes
// Hàm FDE #1428 | Địa chỉ PC: 0x0cd398 | Địa chỉ FDE: 0x123988 | Kích thước: 196 bytes
//   0x0cd398: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0cd39c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cd3a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cd3a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1428_0x0cd398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd398ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123988ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1429 | PC: 0x0cd45c | FDE: 0x1239b0 | Size: 164 bytes [_ZN11fast_engine9MethodObjC1EPNS_7FuncObjEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1429 | Địa chỉ PC: 0x0cd45c | Địa chỉ FDE: 0x1239b0 | Kích thước: 164 bytes
//   0x0cd45c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0cd460: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cd464: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cd468: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1429_0x0cd45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd45cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1239b0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1430 | PC: 0x0cd500 | FDE: 0x123d50 | Size: 256 bytes
// Hàm FDE #1430 | Địa chỉ PC: 0x0cd500 | Địa chỉ FDE: 0x123d50 | Kích thước: 256 bytes
//   0x0cd500: D102C3FF  sub      sp, sp, #0xb0
//   0x0cd504: F9002BFB  str      x27, [sp, #0x50]
//   0x0cd508: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0cd50c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1430_0x0cd500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd500ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x123d50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1431 | PC: 0x0cd764 | FDE: 0x1239d0 | Size: 148 bytes [_ZN11fast_engine9MethodObj5ClearEPNS_6EngineE]
// Hàm FDE #1431 | Địa chỉ PC: 0x0cd764 | Địa chỉ FDE: 0x1239d0 | Kích thước: 148 bytes
//   0x0cd764: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cd768: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cd76c: 910043FD  add      x29, sp, #0x10
//   0x0cd770: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1431_0x0cd764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd764ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1239d0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1432 | PC: 0x0cd7f8 | FDE: 0x123d88 | Size: 96 bytes [_ZN11fast_engine21AllocStaticMethodTypeEPNS_6EngineE]
// Hàm FDE #1432 | Địa chỉ PC: 0x0cd7f8 | Địa chỉ FDE: 0x123d88 | Kích thước: 96 bytes
//   0x0cd7f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cd7fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cd800: 910043FD  add      x29, sp, #0x10
//   0x0cd804: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1432_0x0cd7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd7f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123d88ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1433 | PC: 0x0cd858 | FDE: 0x1239f0 | Size: 64 bytes [_ZN11fast_engine20InitStaticMethodTypeEPNS_6EngineE]
// Hàm FDE #1433 | Địa chỉ PC: 0x0cd858 | Địa chỉ FDE: 0x1239f0 | Kích thước: 64 bytes
//   0x0cd858: D0000388  adrp     x8, #0x13f000
//   0x0cd85c: F9472D08  ldr      x8, [x8, #0xe58]
//   0x0cd860: 90000009  adrp     x9, #0xcd000
//   0x0cd864: 9000000A  adrp     x10, #0xcd000
static inline uint64_t fde_func_1433_0x0cd858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd858ULL ^ (static_cast<uint64_t>(0xd0000388ULL) << 13);
    acc = (acc + a1 + 0xf9472d08ULL) ^ 0x1239f0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1434 | PC: 0x0cd898 | FDE: 0x123db0 | Size: 188 bytes
// Hàm FDE #1434 | Địa chỉ PC: 0x0cd898 | Địa chỉ FDE: 0x123db0 | Kích thước: 188 bytes
//   0x0cd898: D10143FF  sub      sp, sp, #0x50
//   0x0cd89c: F90013F5  str      x21, [sp, #0x20]
//   0x0cd8a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cd8a4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1434_0x0cd898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd898ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x123db0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1435 | PC: 0x0cd954 | FDE: 0x123a08 | Size: 8 bytes
// Hàm FDE #1435 | Địa chỉ PC: 0x0cd954 | Địa chỉ FDE: 0x123a08 | Kích thước: 8 bytes
//   0x0cd954: F9402021  ldr      x1, [x1, #0x40]
//   0x0cd958: 17FDD91A  b        #0x43dc0
static inline uint64_t fde_func_1435_0x0cd954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd954ULL ^ (static_cast<uint64_t>(0xf9402021ULL) << 13);
    acc = (acc + a1 + 0x17fdd91aULL) ^ 0x123a08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1436 | PC: 0x0cd95c | FDE: 0x123dd8 | Size: 256 bytes
// Hàm FDE #1436 | Địa chỉ PC: 0x0cd95c | Địa chỉ FDE: 0x123dd8 | Kích thước: 256 bytes
//   0x0cd95c: D10183FF  sub      sp, sp, #0x60
//   0x0cd960: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0cd964: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0cd968: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1436_0x0cd95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd95cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x123dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1437 | PC: 0x0cdaa0 | FDE: 0x123e08 | Size: 156 bytes
// Hàm FDE #1437 | Địa chỉ PC: 0x0cdaa0 | Địa chỉ FDE: 0x123e08 | Kích thước: 156 bytes
//   0x0cdaa0: D10103FF  sub      sp, sp, #0x40
//   0x0cdaa4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cdaa8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0cdaac: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1437_0x0cdaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdaa0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x123e08ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1438 | PC: 0x0cdb3c | FDE: 0x123a20 | Size: 104 bytes [_ZN11fast_engine15StaticMethodObjC2EPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1438 | Địa chỉ PC: 0x0cdb3c | Địa chỉ FDE: 0x123a20 | Kích thước: 104 bytes
//   0x0cdb3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cdb40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cdb44: 910043FD  add      x29, sp, #0x10
//   0x0cdb48: D0000388  adrp     x8, #0x13f000
static inline uint64_t fde_func_1438_0x0cdb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdb3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123a20ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1439 | PC: 0x0cdba4 | FDE: 0x123a40 | Size: 52 bytes [_ZN11fast_engine15StaticMethodObj5ClearEPNS_6EngineE]
// Hàm FDE #1439 | Địa chỉ PC: 0x0cdba4 | Địa chỉ FDE: 0x123a40 | Kích thước: 52 bytes
//   0x0cdba4: F9402008  ldr      x8, [x0, #0x40]
//   0x0cdba8: B9402109  ldr      w9, [x8, #0x20]
//   0x0cdbac: 7100093F  cmp      w9, #2
//   0x0cdbb0: 540000C0  b.eq     #0xcdbc8
static inline uint64_t fde_func_1439_0x0cdba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdba4ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xb9402109ULL) ^ 0x123a40ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1440 | PC: 0x0cdbd8 | FDE: 0x123a58 | Size: 36 bytes [_ZN11fast_engine8CFuncObjD0Ev]
// Hàm FDE #1440 | Địa chỉ PC: 0x0cdbd8 | Địa chỉ FDE: 0x123a58 | Kích thước: 36 bytes
//   0x0cdbd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cdbdc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cdbe0: 910043FD  add      x29, sp, #0x10
//   0x0cdbe4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1440_0x0cdbd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdbd8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123a58ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1441 | PC: 0x0cdbfc | FDE: 0x123a78 | Size: 36 bytes [_ZN11fast_engine7FuncObjD0Ev]
// Hàm FDE #1441 | Địa chỉ PC: 0x0cdbfc | Địa chỉ FDE: 0x123a78 | Kích thước: 36 bytes
//   0x0cdbfc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cdc00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cdc04: 910043FD  add      x29, sp, #0x10
//   0x0cdc08: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1441_0x0cdbfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdbfcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123a78ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1442 | PC: 0x0cdc20 | FDE: 0x123a98 | Size: 36 bytes [_ZN11fast_engine9MethodObjD0Ev]
// Hàm FDE #1442 | Địa chỉ PC: 0x0cdc20 | Địa chỉ FDE: 0x123a98 | Kích thước: 36 bytes
//   0x0cdc20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cdc24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cdc28: 910043FD  add      x29, sp, #0x10
//   0x0cdc2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1442_0x0cdc20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdc20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123a98ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1443 | PC: 0x0cdc44 | FDE: 0x123ab8 | Size: 36 bytes [_ZN11fast_engine15StaticMethodObjD0Ev]
// Hàm FDE #1443 | Địa chỉ PC: 0x0cdc44 | Địa chỉ FDE: 0x123ab8 | Kích thước: 36 bytes
//   0x0cdc44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cdc48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cdc4c: 910043FD  add      x29, sp, #0x10
//   0x0cdc50: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1443_0x0cdc44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdc44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123ab8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1444 | PC: 0x0cdc68 | FDE: 0x123ad8 | Size: 36 bytes [_ZN11fast_engine10CMethodObjD0Ev]
// Hàm FDE #1444 | Địa chỉ PC: 0x0cdc68 | Địa chỉ FDE: 0x123ad8 | Kích thước: 36 bytes
//   0x0cdc68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cdc6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cdc70: 910043FD  add      x29, sp, #0x10
//   0x0cdc74: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1444_0x0cdc68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdc68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123ad8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1445 | PC: 0x0cdc8c | FDE: 0x123e30 | Size: 256 bytes
// Hàm FDE #1445 | Địa chỉ PC: 0x0cdc8c | Địa chỉ FDE: 0x123e30 | Kích thước: 256 bytes
//   0x0cdc8c: D101C3FF  sub      sp, sp, #0x70
//   0x0cdc90: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0cdc94: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0cdc98: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1445_0x0cdc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdc8cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x123e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1446 | PC: 0x0cdf90 | FDE: 0x123e68 | Size: 256 bytes [_ZN11fast_engine9MethodObj11GetOrCreateEPNS_3ObjES2_PNS_6EngineE]
// Hàm FDE #1446 | Địa chỉ PC: 0x0cdf90 | Địa chỉ FDE: 0x123e68 | Kích thước: 256 bytes
//   0x0cdf90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0cdf94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cdf98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cdf9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1446_0x0cdf90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdf90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123e68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1447 | PC: 0x0ce0b8 | FDE: 0x123af8 | Size: 36 bytes
// Hàm FDE #1447 | Địa chỉ PC: 0x0ce0b8 | Địa chỉ FDE: 0x123af8 | Kích thước: 36 bytes
//   0x0ce0b8: F9402000  ldr      x0, [x0, #0x40]
//   0x0ce0bc: B40000E0  cbz      x0, #0xce0d8
//   0x0ce0c0: B9402008  ldr      w8, [x0, #0x20]
//   0x0ce0c4: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_1447_0x0ce0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce0b8ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb40000e0ULL) ^ 0x123af8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1448 | PC: 0x0ce0dc | FDE: 0x123b10 | Size: 156 bytes
// Hàm FDE #1448 | Địa chỉ PC: 0x0ce0dc | Địa chỉ FDE: 0x123b10 | Kích thước: 156 bytes
//   0x0ce0dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ce0e0: 910003FD  mov      x29, sp
//   0x0ce0e4: B4000081  cbz      x1, #0xce0f4
//   0x0ce0e8: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1448_0x0ce0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce0dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123b10ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1449 | PC: 0x0ce178 | FDE: 0x123b30 | Size: 36 bytes
// Hàm FDE #1449 | Địa chỉ PC: 0x0ce178 | Địa chỉ FDE: 0x123b30 | Kích thước: 36 bytes
//   0x0ce178: F9402400  ldr      x0, [x0, #0x48]
//   0x0ce17c: B40000E0  cbz      x0, #0xce198
//   0x0ce180: B9402008  ldr      w8, [x0, #0x20]
//   0x0ce184: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_1449_0x0ce178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce178ULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xb40000e0ULL) ^ 0x123b30ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1450 | PC: 0x0ce19c | FDE: 0x123b48 | Size: 156 bytes
// Hàm FDE #1450 | Địa chỉ PC: 0x0ce19c | Địa chỉ FDE: 0x123b48 | Kích thước: 156 bytes
//   0x0ce19c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ce1a0: 910003FD  mov      x29, sp
//   0x0ce1a4: B4000081  cbz      x1, #0xce1b4
//   0x0ce1a8: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1450_0x0ce19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce19cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x123b48ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1451 | PC: 0x0ce238 | FDE: 0x123f40 | Size: 96 bytes [_ZN11fast_engine12AllocGenTypeEPNS_6EngineE]
// Hàm FDE #1451 | Địa chỉ PC: 0x0ce238 | Địa chỉ FDE: 0x123f40 | Kích thước: 96 bytes
//   0x0ce238: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ce23c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ce240: 910043FD  add      x29, sp, #0x10
//   0x0ce244: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1451_0x0ce238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce238ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123f40ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1452 | PC: 0x0ce298 | FDE: 0x123e98 | Size: 56 bytes [_ZN11fast_engine11InitGenTypeEPNS_6EngineE]
// Hàm FDE #1452 | Địa chỉ PC: 0x0ce298 | Địa chỉ FDE: 0x123e98 | Kích thước: 56 bytes
//   0x0ce298: B0000388  adrp     x8, #0x13f000
//   0x0ce29c: F9466D08  ldr      x8, [x8, #0xcd8]
//   0x0ce2a0: B0000389  adrp     x9, #0x13f000
//   0x0ce2a4: F944ED29  ldr      x9, [x9, #0x9d8]
static inline uint64_t fde_func_1452_0x0ce298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce298ULL ^ (static_cast<uint64_t>(0xb0000388ULL) << 13);
    acc = (acc + a1 + 0xf9466d08ULL) ^ 0x123e98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1453 | PC: 0x0ce2d0 | FDE: 0x123eb0 | Size: 256 bytes
// Hàm FDE #1453 | Địa chỉ PC: 0x0ce2d0 | Địa chỉ FDE: 0x123eb0 | Kích thước: 256 bytes
//   0x0ce2d0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0ce2d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ce2d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ce2dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1453_0x0ce2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce2d0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x123eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1454 | PC: 0x0ce4d4 | FDE: 0x123f68 | Size: 180 bytes
// Hàm FDE #1454 | Địa chỉ PC: 0x0ce4d4 | Địa chỉ FDE: 0x123f68 | Kích thước: 180 bytes
//   0x0ce4d4: D10103FF  sub      sp, sp, #0x40
//   0x0ce4d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ce4dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ce4e0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1454_0x0ce4d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce4d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x123f68ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1455 | PC: 0x0ce588 | FDE: 0x123ed8 | Size: 212 bytes [_ZN11fast_engine6GenObjC1EPNS_7TypeObjEPNS_8FrameObjEPNS_3ObjES6_PNS_6EngineE]
// Hàm FDE #1455 | Địa chỉ PC: 0x0ce588 | Địa chỉ FDE: 0x123ed8 | Kích thước: 212 bytes
//   0x0ce588: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ce58c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ce590: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ce594: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1455_0x0ce588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce588ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123ed8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1456 | PC: 0x0ce65c | FDE: 0x123f00 | Size: 256 bytes [_ZN11fast_engine6GenObj5ClearEPNS_6EngineE]
// Hàm FDE #1456 | Địa chỉ PC: 0x0ce65c | Địa chỉ FDE: 0x123f00 | Kích thước: 256 bytes
//   0x0ce65c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ce660: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ce664: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ce668: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1456_0x0ce65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce65cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1457 | PC: 0x0ce82c | FDE: 0x123f20 | Size: 36 bytes [_ZN11fast_engine6GenObjD0Ev]
// Hàm FDE #1457 | Địa chỉ PC: 0x0ce82c | Địa chỉ FDE: 0x123f20 | Kích thước: 36 bytes
//   0x0ce82c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ce830: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ce834: 910043FD  add      x29, sp, #0x10
//   0x0ce838: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1457_0x0ce82c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce82cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123f20ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1458 | PC: 0x0ce850 | FDE: 0x123f90 | Size: 104 bytes [_ZN11fast_engine15SequenceIterObjC2EPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1458 | Địa chỉ PC: 0x0ce850 | Địa chỉ FDE: 0x123f90 | Kích thước: 104 bytes
//   0x0ce850: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ce854: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ce858: 910043FD  add      x29, sp, #0x10
//   0x0ce85c: B0000388  adrp     x8, #0x13f000
static inline uint64_t fde_func_1458_0x0ce850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce850ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123f90ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1459 | PC: 0x0ce8b8 | FDE: 0x123fb0 | Size: 84 bytes [_ZN11fast_engine15SequenceIterObj5ClearEPNS_6EngineE]
// Hàm FDE #1459 | Địa chỉ PC: 0x0ce8b8 | Địa chỉ FDE: 0x123fb0 | Kích thước: 84 bytes
//   0x0ce8b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ce8bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ce8c0: 910043FD  add      x29, sp, #0x10
//   0x0ce8c4: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1459_0x0ce8b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce8b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x123fb0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1460 | PC: 0x0ce90c | FDE: 0x124028 | Size: 96 bytes [_ZN11fast_engine21AllocSequenceIterTypeEPNS_6EngineE]
// Hàm FDE #1460 | Địa chỉ PC: 0x0ce90c | Địa chỉ FDE: 0x124028 | Kích thước: 96 bytes
//   0x0ce90c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ce910: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ce914: 910043FD  add      x29, sp, #0x10
//   0x0ce918: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1460_0x0ce90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce90cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124028ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1461 | PC: 0x0ce96c | FDE: 0x123fd0 | Size: 44 bytes [_ZN11fast_engine20InitSequenceIterTypeEPNS_6EngineE]
// Hàm FDE #1461 | Địa chỉ PC: 0x0ce96c | Địa chỉ FDE: 0x123fd0 | Kích thước: 44 bytes
//   0x0ce96c: B0000388  adrp     x8, #0x13f000
//   0x0ce970: F946B108  ldr      x8, [x8, #0xd60]
//   0x0ce974: B0000389  adrp     x9, #0x13f000
//   0x0ce978: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1461_0x0ce96c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce96cULL ^ (static_cast<uint64_t>(0xb0000388ULL) << 13);
    acc = (acc + a1 + 0xf946b108ULL) ^ 0x123fd0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1462 | PC: 0x0ce998 | FDE: 0x123fe8 | Size: 252 bytes
// Hàm FDE #1462 | Địa chỉ PC: 0x0ce998 | Địa chỉ FDE: 0x123fe8 | Kích thước: 252 bytes
//   0x0ce998: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ce99c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ce9a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ce9a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1462_0x0ce998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce998ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x123fe8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1463 | PC: 0x0cea94 | FDE: 0x124008 | Size: 36 bytes [_ZN11fast_engine15SequenceIterObjD0Ev]
// Hàm FDE #1463 | Địa chỉ PC: 0x0cea94 | Địa chỉ FDE: 0x124008 | Kích thước: 36 bytes
//   0x0cea94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cea98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cea9c: 910043FD  add      x29, sp, #0x10
//   0x0ceaa0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1463_0x0cea94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cea94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124008ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1464 | PC: 0x0ceab8 | FDE: 0x124050 | Size: 148 bytes [_ZN11fast_engine9ModuleObj7GetAttrEPNS_3ObjEPNS_6StrObjEPNS_6EngineE]
// Hàm FDE #1464 | Địa chỉ PC: 0x0ceab8 | Địa chỉ FDE: 0x124050 | Kích thước: 148 bytes
//   0x0ceab8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ceabc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ceac0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ceac4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1464_0x0ceab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ceab8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124050ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1465 | PC: 0x0ceb4c | FDE: 0x124070 | Size: 152 bytes [_ZN11fast_engine9ModuleObj11GetAttrImplEPS0_PNS_6StrObjEPNS_6EngineEb]
// Hàm FDE #1465 | Địa chỉ PC: 0x0ceb4c | Địa chỉ FDE: 0x124070 | Kích thước: 152 bytes
//   0x0ceb4c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ceb50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ceb54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ceb58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1465_0x0ceb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ceb4cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124070ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1466 | PC: 0x0cebe4 | FDE: 0x1241c8 | Size: 256 bytes [_ZN11fast_engine9ModuleObj10LoadModuleEPS0_PNS_6EngineE]
// Hàm FDE #1466 | Địa chỉ PC: 0x0cebe4 | Địa chỉ FDE: 0x1241c8 | Kích thước: 256 bytes
//   0x0cebe4: D10403FF  sub      sp, sp, #0x100
//   0x0cebe8: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0cebec: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0cebf0: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1466_0x0cebe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cebe4ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1241c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1467 | PC: 0x0cf734 | FDE: 0x124200 | Size: 96 bytes [_ZN11fast_engine15AllocModuleTypeEPNS_6EngineE]
// Hàm FDE #1467 | Địa chỉ PC: 0x0cf734 | Địa chỉ FDE: 0x124200 | Kích thước: 96 bytes
//   0x0cf734: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cf738: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf73c: 910043FD  add      x29, sp, #0x10
//   0x0cf740: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1467_0x0cf734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf734ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124200ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1468 | PC: 0x0cf794 | FDE: 0x124098 | Size: 60 bytes [_ZN11fast_engine14InitModuleTypeEPNS_6EngineE]
// Hàm FDE #1468 | Địa chỉ PC: 0x0cf794 | Địa chỉ FDE: 0x124098 | Kích thước: 60 bytes
//   0x0cf794: 90000388  adrp     x8, #0x13f000
//   0x0cf798: F947A508  ldr      x8, [x8, #0xf48]
//   0x0cf79c: 90000009  adrp     x9, #0xcf000
//   0x0cf7a0: D000038B  adrp     x11, #0x141000
static inline uint64_t fde_func_1468_0x0cf794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf794ULL ^ (static_cast<uint64_t>(0x90000388ULL) << 13);
    acc = (acc + a1 + 0xf947a508ULL) ^ 0x124098ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1469 | PC: 0x0cf7d0 | FDE: 0x1240b0 | Size: 4 bytes
// Hàm FDE #1469 | Địa chỉ PC: 0x0cf7d0 | Địa chỉ FDE: 0x1240b0 | Kích thước: 4 bytes
//   0x0cf7d0: 17FDCEAC  b        #0x43280
static inline uint64_t fde_func_1469_0x0cf7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf7d0ULL ^ (static_cast<uint64_t>(0x17fdceacULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x1240b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1470 | PC: 0x0cf7d4 | FDE: 0x124228 | Size: 256 bytes
// Hàm FDE #1470 | Địa chỉ PC: 0x0cf7d4 | Địa chỉ FDE: 0x124228 | Kích thước: 256 bytes
//   0x0cf7d4: D101C3FF  sub      sp, sp, #0x70
//   0x0cf7d8: F90023F5  str      x21, [sp, #0x40]
//   0x0cf7dc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0cf7e0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1470_0x0cf7d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf7d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x124228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1471 | PC: 0x0cf93c | FDE: 0x1240c8 | Size: 148 bytes [_ZN11fast_engine9ModuleObj5ClearEPNS_6EngineE]
// Hàm FDE #1471 | Địa chỉ PC: 0x0cf93c | Địa chỉ FDE: 0x1240c8 | Kích thước: 148 bytes
//   0x0cf93c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cf940: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf944: 910043FD  add      x29, sp, #0x10
//   0x0cf948: F9406408  ldr      x8, [x0, #0xc8]
static inline uint64_t fde_func_1471_0x0cf93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf93cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1240c8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1472 | PC: 0x0cf9d0 | FDE: 0x124250 | Size: 256 bytes [_ZN11fast_engine9ModuleObjC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEbPNS_6EngineE]
// Hàm FDE #1472 | Địa chỉ PC: 0x0cf9d0 | Địa chỉ FDE: 0x124250 | Kích thước: 256 bytes
//   0x0cf9d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0cf9d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0cf9d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cf9dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1472_0x0cf9d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf9d0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x124250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1473 | PC: 0x0cfb1c | FDE: 0x1240e8 | Size: 16 bytes [_ZN11fast_engine9ModuleObjC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_PNS_6EngineEPS0_]
// Hàm FDE #1473 | Địa chỉ PC: 0x0cfb1c | Địa chỉ FDE: 0x1240e8 | Kích thước: 16 bytes
//   0x0cfb1c: AA0403E5  mov      x5, x4
//   0x0cfb20: AA0303E4  mov      x4, x3
//   0x0cfb24: 2A1F03E3  mov      w3, wzr
//   0x0cfb28: 17FDD506  b        #0x44f40
static inline uint64_t fde_func_1473_0x0cfb1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfb1cULL ^ (static_cast<uint64_t>(0xaa0403e5ULL) << 13);
    acc = (acc + a1 + 0xaa0303e4ULL) ^ 0x1240e8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1474 | PC: 0x0cfb2c | FDE: 0x124280 | Size: 256 bytes [_ZN11fast_engine9ModuleObjC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_bPNS_6EngineEPS0_]
// Hàm FDE #1474 | Địa chỉ PC: 0x0cfb2c | Địa chỉ FDE: 0x124280 | Kích thước: 256 bytes
//   0x0cfb2c: D101C3FF  sub      sp, sp, #0x70
//   0x0cfb30: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0cfb34: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0cfb38: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1474_0x0cfb2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfb2cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x124280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1475 | PC: 0x0cfd30 | FDE: 0x1242b0 | Size: 256 bytes
// Hàm FDE #1475 | Địa chỉ PC: 0x0cfd30 | Địa chỉ FDE: 0x1242b0 | Kích thước: 256 bytes
//   0x0cfd30: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0cfd34: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0cfd38: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0cfd3c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1475_0x0cfd30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfd30ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1242b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1476 | PC: 0x0cfe3c | FDE: 0x124100 | Size: 164 bytes [_ZN11fast_engine9ModuleObjD2Ev]
// Hàm FDE #1476 | Địa chỉ PC: 0x0cfe3c | Địa chỉ FDE: 0x124100 | Kích thước: 164 bytes
//   0x0cfe3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cfe40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cfe44: 910043FD  add      x29, sp, #0x10
//   0x0cfe48: 90000389  adrp     x9, #0x13f000
static inline uint64_t fde_func_1476_0x0cfe3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfe3cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124100ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1477 | PC: 0x0cfee0 | FDE: 0x1242e0 | Size: 124 bytes [_ZN11fast_engine9ModuleObjC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_S9_PNS_6EngineEPS0_b]
// Hàm FDE #1477 | Địa chỉ PC: 0x0cfee0 | Địa chỉ FDE: 0x1242e0 | Kích thước: 124 bytes
//   0x0cfee0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0cfee4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cfee8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cfeec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1477_0x0cfee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfee0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1242e0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1478 | PC: 0x0cff5c | FDE: 0x124120 | Size: 36 bytes [_ZN11fast_engine9ModuleObjD0Ev]
// Hàm FDE #1478 | Địa chỉ PC: 0x0cff5c | Địa chỉ FDE: 0x124120 | Kích thước: 36 bytes
//   0x0cff5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cff60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cff64: 910043FD  add      x29, sp, #0x10
//   0x0cff68: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1478_0x0cff5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cff5cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124120ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1479 | PC: 0x0cff80 | FDE: 0x124140 | Size: 108 bytes [_ZN11fast_engine9ModuleObj13GetItemStringEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1479 | Địa chỉ PC: 0x0cff80 | Địa chỉ FDE: 0x124140 | Kích thước: 108 bytes
//   0x0cff80: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0cff84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cff88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cff8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1479_0x0cff80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cff80ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124140ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1480 | PC: 0x0cffec | FDE: 0x124160 | Size: 256 bytes [_ZN11fast_engine9ModuleObj10GetItemRefEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1480 | Địa chỉ PC: 0x0cffec | Địa chỉ FDE: 0x124160 | Kích thước: 256 bytes
//   0x0cffec: D10103FF  sub      sp, sp, #0x40
//   0x0cfff0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0cfff4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cfff8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1480_0x0cffec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cffecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x124160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1481 | PC: 0x0d012c | FDE: 0x124188 | Size: 140 bytes [_ZN11fast_engine9ModuleObj8LoadCodeEPS0_PNS_6EngineE]
// Hàm FDE #1481 | Địa chỉ PC: 0x0d012c | Địa chỉ FDE: 0x124188 | Kích thước: 140 bytes
//   0x0d012c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d0130: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d0134: 910043FD  add      x29, sp, #0x10
//   0x0d0138: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1481_0x0d012c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d012cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124188ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1482 | PC: 0x0d01b8 | FDE: 0x124308 | Size: 256 bytes [_ZN11fast_engine9ModuleObj22GetResourceFromAbsNameEPS0_NSt6__ndk16vectorINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS7_IS9_EEEEPNS_6EngineE]
// Hàm FDE #1482 | Địa chỉ PC: 0x0d01b8 | Địa chỉ FDE: 0x124308 | Kích thước: 256 bytes
//   0x0d01b8: D103C3FF  sub      sp, sp, #0xf0
//   0x0d01bc: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0d01c0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0d01c4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1482_0x0d01b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d01b8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x124308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1483 | PC: 0x0d03ac | FDE: 0x124340 | Size: 256 bytes [_ZN11fast_engine9ModuleObj8AddCFunsEPS0_PKNS_9MethodDefEPNS_6EngineE]
// Hàm FDE #1483 | Địa chỉ PC: 0x0d03ac | Địa chỉ FDE: 0x124340 | Kích thước: 256 bytes
//   0x0d03ac: D101C3FF  sub      sp, sp, #0x70
//   0x0d03b0: F90013F9  str      x25, [sp, #0x20]
//   0x0d03b4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0d03b8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1483_0x0d03ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d03acULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x124340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1484 | PC: 0x0d04f0 | FDE: 0x124370 | Size: 204 bytes [_ZN11fast_engine9ModuleObj7AddTypeEPS0_PNS_7TypeObjEPNS_6EngineERKNSt6__ndk112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE]
// Hàm FDE #1484 | Địa chỉ PC: 0x0d04f0 | Địa chỉ FDE: 0x124370 | Kích thước: 204 bytes
//   0x0d04f0: D10143FF  sub      sp, sp, #0x50
//   0x0d04f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d04f8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d04fc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1484_0x0d04f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d04f0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x124370ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1485 | PC: 0x0d05bc | FDE: 0x1241a8 | Size: 52 bytes [_ZN11fast_engine9ModuleObj9AddMemberEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1485 | Địa chỉ PC: 0x0d05bc | Địa chỉ FDE: 0x1241a8 | Kích thước: 52 bytes
//   0x0d05bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d05c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d05c4: 910043FD  add      x29, sp, #0x10
//   0x0d05c8: F9406400  ldr      x0, [x0, #0xc8]
static inline uint64_t fde_func_1485_0x0d05bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d05bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1241a8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1486 | PC: 0x0d05f0 | FDE: 0x1243a0 | Size: 56 bytes [_ZN11fast_engine12BoolFromLongElPNS_6EngineE]
// Hàm FDE #1486 | Địa chỉ PC: 0x0d05f0 | Địa chỉ FDE: 0x1243a0 | Kích thước: 56 bytes
//   0x0d05f0: F0000368  adrp     x8, #0x13f000
//   0x0d05f4: F0000369  adrp     x9, #0x13f000
//   0x0d05f8: F9466508  ldr      x8, [x8, #0xcc8]
//   0x0d05fc: F9464D29  ldr      x9, [x9, #0xc98]
static inline uint64_t fde_func_1486_0x0d05f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d05f0ULL ^ (static_cast<uint64_t>(0xf0000368ULL) << 13);
    acc = (acc + a1 + 0xf0000369ULL) ^ 0x1243a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1487 | PC: 0x0d0628 | FDE: 0x124a10 | Size: 96 bytes [_ZN11fast_engine13AllocBoolTypeEPNS_6EngineE]
// Hàm FDE #1487 | Địa chỉ PC: 0x0d0628 | Địa chỉ FDE: 0x124a10 | Kích thước: 96 bytes
//   0x0d0628: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d062c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d0630: 910043FD  add      x29, sp, #0x10
//   0x0d0634: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1487_0x0d0628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0628ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124a10ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1488 | PC: 0x0d0688 | FDE: 0x124a38 | Size: 256 bytes [_ZN11fast_engine12InitBoolTypeEPNS_6EngineE]
// Hàm FDE #1488 | Địa chỉ PC: 0x0d0688 | Địa chỉ FDE: 0x124a38 | Kích thước: 256 bytes
//   0x0d0688: D10183FF  sub      sp, sp, #0x60
//   0x0d068c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d0690: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d0694: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1488_0x0d0688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0688ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x124a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1489 | PC: 0x0d090c | FDE: 0x124a68 | Size: 256 bytes
// Hàm FDE #1489 | Địa chỉ PC: 0x0d090c | Địa chỉ FDE: 0x124a68 | Kích thước: 256 bytes
//   0x0d090c: D101C3FF  sub      sp, sp, #0x70
//   0x0d0910: F9001BF7  str      x23, [sp, #0x30]
//   0x0d0914: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0d0918: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1489_0x0d090c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d090cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x124a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1490 | PC: 0x0d0a20 | FDE: 0x124a98 | Size: 256 bytes
// Hàm FDE #1490 | Địa chỉ PC: 0x0d0a20 | Địa chỉ FDE: 0x124a98 | Kích thước: 256 bytes
//   0x0d0a20: D10183FF  sub      sp, sp, #0x60
//   0x0d0a24: F90013F7  str      x23, [sp, #0x20]
//   0x0d0a28: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d0a2c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1490_0x0d0a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0a20ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x124a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1491 | PC: 0x0d0b44 | FDE: 0x1243b8 | Size: 124 bytes
// Hàm FDE #1491 | Địa chỉ PC: 0x0d0b44 | Địa chỉ FDE: 0x1243b8 | Kích thước: 124 bytes
//   0x0d0b44: F0000369  adrp     x9, #0x13f000
//   0x0d0b48: F9401408  ldr      x8, [x0, #0x28]
//   0x0d0b4c: F943D129  ldr      x9, [x9, #0x7a0]
//   0x0d0b50: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_1491_0x0d0b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0b44ULL ^ (static_cast<uint64_t>(0xf0000369ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x1243b8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1492 | PC: 0x0d0bc0 | FDE: 0x1243d0 | Size: 140 bytes
// Hàm FDE #1492 | Địa chỉ PC: 0x0d0bc0 | Địa chỉ FDE: 0x1243d0 | Kích thước: 140 bytes
//   0x0d0bc0: F0000369  adrp     x9, #0x13f000
//   0x0d0bc4: F9401408  ldr      x8, [x0, #0x28]
//   0x0d0bc8: F943D129  ldr      x9, [x9, #0x7a0]
//   0x0d0bcc: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_1492_0x0d0bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0bc0ULL ^ (static_cast<uint64_t>(0xf0000369ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x1243d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1493 | PC: 0x0d0c4c | FDE: 0x1243e8 | Size: 124 bytes
// Hàm FDE #1493 | Địa chỉ PC: 0x0d0c4c | Địa chỉ FDE: 0x1243e8 | Kích thước: 124 bytes
//   0x0d0c4c: F0000369  adrp     x9, #0x13f000
//   0x0d0c50: F9401408  ldr      x8, [x0, #0x28]
//   0x0d0c54: F943D129  ldr      x9, [x9, #0x7a0]
//   0x0d0c58: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_1493_0x0d0c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0c4cULL ^ (static_cast<uint64_t>(0xf0000369ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x1243e8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1494 | PC: 0x0d0cc8 | FDE: 0x124ac8 | Size: 256 bytes
// Hàm FDE #1494 | Địa chỉ PC: 0x0d0cc8 | Địa chỉ FDE: 0x124ac8 | Kích thước: 256 bytes
//   0x0d0cc8: D10203FF  sub      sp, sp, #0x80
//   0x0d0ccc: F90013FB  str      x27, [sp, #0x20]
//   0x0d0cd0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0d0cd4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1494_0x0d0cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0cc8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x124ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1495 | PC: 0x0d0fb4 | FDE: 0x124b00 | Size: 256 bytes
// Hàm FDE #1495 | Địa chỉ PC: 0x0d0fb4 | Địa chỉ FDE: 0x124b00 | Kích thước: 256 bytes
//   0x0d0fb4: D10143FF  sub      sp, sp, #0x50
//   0x0d0fb8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d0fbc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d0fc0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1495_0x0d0fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0fb4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x124b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1496 | PC: 0x0d112c | FDE: 0x124b30 | Size: 256 bytes [_ZN11fast_engine7LongObj4InitEPNS_6EngineE]
// Hàm FDE #1496 | Địa chỉ PC: 0x0d112c | Địa chỉ FDE: 0x124b30 | Kích thước: 256 bytes
//   0x0d112c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0d1130: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d1134: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d1138: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1496_0x0d112c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d112cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x124b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1497 | PC: 0x0d122c | FDE: 0x124400 | Size: 96 bytes [_ZN11fast_engine7LongObj8FinalizeEPNS_6EngineE]
// Hàm FDE #1497 | Địa chỉ PC: 0x0d122c | Địa chỉ FDE: 0x124400 | Kích thước: 96 bytes
//   0x0d122c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d1230: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d1234: 910043FD  add      x29, sp, #0x10
//   0x0d1238: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1497_0x0d122c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d122cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124400ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1498 | PC: 0x0d128c | FDE: 0x124b68 | Size: 256 bytes [_ZN11fast_engine7LongObj17FromUnicodeObjectEPNS_3ObjEiPNS_6EngineE]
// Hàm FDE #1498 | Địa chỉ PC: 0x0d128c | Địa chỉ FDE: 0x124b68 | Kích thước: 256 bytes
//   0x0d128c: D10383FF  sub      sp, sp, #0xe0
//   0x0d1290: FD003BE8  str      d8, [sp, #0x70]
//   0x0d1294: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0d1298: A90967FA  stp      x26, x25, [sp, #0x90]
static inline uint64_t fde_func_1498_0x0d128c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d128cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xfd003be8ULL) ^ 0x124b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1499 | PC: 0x0d1e64 | FDE: 0x124ba0 | Size: 256 bytes [_ZN11fast_engine7LongObj5_CopyEPKS0_PNS_6EngineE]
// Hàm FDE #1499 | Địa chỉ PC: 0x0d1e64 | Địa chỉ FDE: 0x124ba0 | Kích thước: 256 bytes
//   0x0d1e64: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d1e68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d1e6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d1e70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1499_0x0d1e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1e64ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124ba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1500 | PC: 0x0d1fcc | FDE: 0x124420 | Size: 256 bytes [_ZN11fast_engine7LongObj6_FrexpEPKS0_PlPNS_6EngineE]
// Hàm FDE #1500 | Địa chỉ PC: 0x0d1fcc | Địa chỉ FDE: 0x124420 | Kích thước: 256 bytes
//   0x0d1fcc: D10103FF  sub      sp, sp, #0x40
//   0x0d1fd0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d1fd4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d1fd8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1500_0x0d1fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1fccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x124420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1501 | PC: 0x0d2278 | FDE: 0x124440 | Size: 80 bytes [_ZN11fast_engine7LongObj11_RightShiftEPNS_3ObjEmPNS_6EngineE]
// Hàm FDE #1501 | Địa chỉ PC: 0x0d2278 | Địa chỉ FDE: 0x124440 | Kích thước: 80 bytes
//   0x0d2278: F9402008  ldr      x8, [x0, #0x40]
//   0x0d227c: AA0203E3  mov      x3, x2
//   0x0d2280: B4000128  cbz      x8, #0xd22a4
//   0x0d2284: B201E3E8  mov      x8, #-0x7777777777777778
static inline uint64_t fde_func_1501_0x0d2278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2278ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x124440ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1502 | PC: 0x0d22c8 | FDE: 0x124bd0 | Size: 256 bytes
// Hàm FDE #1502 | Địa chỉ PC: 0x0d22c8 | Địa chỉ FDE: 0x124bd0 | Kích thước: 256 bytes
//   0x0d22c8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d22cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d22d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d22d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1502_0x0d22c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d22c8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x124bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1503 | PC: 0x0d25a8 | FDE: 0x124458 | Size: 80 bytes [_ZN11fast_engine7LongObj10_LeftShiftEPNS_3ObjEmPNS_6EngineE]
// Hàm FDE #1503 | Địa chỉ PC: 0x0d25a8 | Địa chỉ FDE: 0x124458 | Kích thước: 80 bytes
//   0x0d25a8: F9402008  ldr      x8, [x0, #0x40]
//   0x0d25ac: AA0203E3  mov      x3, x2
//   0x0d25b0: B4000128  cbz      x8, #0xd25d4
//   0x0d25b4: B201E3E8  mov      x8, #-0x7777777777777778
static inline uint64_t fde_func_1503_0x0d25a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d25a8ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x124458ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1504 | PC: 0x0d25f8 | FDE: 0x124c00 | Size: 256 bytes
// Hàm FDE #1504 | Địa chỉ PC: 0x0d25f8 | Địa chỉ FDE: 0x124c00 | Kích thước: 256 bytes
//   0x0d25f8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0d25fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d2600: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d2604: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1504_0x0d25f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d25f8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x124c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1505 | PC: 0x0d2850 | FDE: 0x124c30 | Size: 256 bytes [_ZN11fast_engine17LongFromByteArrayEPKhmiiPNS_6EngineE]
// Hàm FDE #1505 | Địa chỉ PC: 0x0d2850 | Địa chỉ FDE: 0x124c30 | Kích thước: 256 bytes
//   0x0d2850: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d2854: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d2858: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d285c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1505_0x0d2850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2850ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x124c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1506 | PC: 0x0d2ac0 | FDE: 0x124c60 | Size: 256 bytes [_ZN11fast_engine7LongObj12FromLongLongExPNS_6EngineE]
// Hàm FDE #1506 | Địa chỉ PC: 0x0d2ac0 | Địa chỉ FDE: 0x124c60 | Kích thước: 256 bytes
//   0x0d2ac0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d2ac4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2ac8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2acc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1506_0x0d2ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2ac0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1507 | PC: 0x0d2bc0 | FDE: 0x124c88 | Size: 108 bytes [_ZN11fast_engine7LongObjC2EPNS_6EngineExPNS_7TypeObjE]
// Hàm FDE #1507 | Địa chỉ PC: 0x0d2bc0 | Địa chỉ FDE: 0x124c88 | Kích thước: 108 bytes
//   0x0d2bc0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d2bc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d2bc8: 910043FD  add      x29, sp, #0x10
//   0x0d2bcc: AA0303E8  mov      x8, x3
static inline uint64_t fde_func_1507_0x0d2bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2bc0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124c88ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1508 | PC: 0x0d2c2c | FDE: 0x124470 | Size: 172 bytes [_ZN11fast_engine7LongObj16InitFromLongLongEx]
// Hàm FDE #1508 | Địa chỉ PC: 0x0d2c2c | Địa chỉ FDE: 0x124470 | Kích thước: 172 bytes
//   0x0d2c2c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d2c30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2c34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2c38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1508_0x0d2c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2c2cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124470ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1509 | PC: 0x0d2cd8 | FDE: 0x124cb0 | Size: 192 bytes [_ZN11fast_engine7LongObjC1EPNS_6EngineEyPNS_7TypeObjE]
// Hàm FDE #1509 | Địa chỉ PC: 0x0d2cd8 | Địa chỉ FDE: 0x124cb0 | Kích thước: 192 bytes
//   0x0d2cd8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d2cdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2ce0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2ce4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1509_0x0d2cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2cd8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124cb0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1510 | PC: 0x0d2d98 | FDE: 0x124498 | Size: 156 bytes [_ZN11fast_engine7LongObj24InitFromUnsignedLongLongEy]
// Hàm FDE #1510 | Địa chỉ PC: 0x0d2d98 | Địa chỉ FDE: 0x124498 | Kích thước: 156 bytes
//   0x0d2d98: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d2d9c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2da0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2da4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1510_0x0d2d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2d98ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124498ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1511 | PC: 0x0d2e34 | FDE: 0x124cd8 | Size: 144 bytes [_ZN11fast_engine7LongObjC2ElPNS_6EngineEPNS_7TypeObjE]
// Hàm FDE #1511 | Địa chỉ PC: 0x0d2e34 | Địa chỉ FDE: 0x124cd8 | Kích thước: 144 bytes
//   0x0d2e34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d2e38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2e3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2e40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1511_0x0d2e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2e34ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124cd8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1512 | PC: 0x0d2ec4 | FDE: 0x124d00 | Size: 88 bytes [_ZN11fast_engine7LongObjD2Ev]
// Hàm FDE #1512 | Địa chỉ PC: 0x0d2ec4 | Địa chỉ FDE: 0x124d00 | Kích thước: 88 bytes
//   0x0d2ec4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d2ec8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d2ecc: 910043FD  add      x29, sp, #0x10
//   0x0d2ed0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1512_0x0d2ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2ec4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124d00ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1513 | PC: 0x0d2f1c | FDE: 0x124d28 | Size: 96 bytes [_ZN11fast_engine7LongObjD0Ev]
// Hàm FDE #1513 | Địa chỉ PC: 0x0d2f1c | Địa chỉ FDE: 0x124d28 | Kích thước: 96 bytes
//   0x0d2f1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d2f20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d2f24: 910043FD  add      x29, sp, #0x10
//   0x0d2f28: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1513_0x0d2f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2f1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124d28ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1514 | PC: 0x0d2f7c | FDE: 0x1244b8 | Size: 96 bytes [_ZN11fast_engine7LongObj18ReallocateWhenInitEl]
// Hàm FDE #1514 | Địa chỉ PC: 0x0d2f7c | Địa chỉ FDE: 0x1244b8 | Kích thước: 96 bytes
//   0x0d2f7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d2f80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d2f84: 910043FD  add      x29, sp, #0x10
//   0x0d2f88: F9402002  ldr      x2, [x0, #0x40]
static inline uint64_t fde_func_1514_0x0d2f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2f7cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1244b8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1515 | PC: 0x0d2fdc | FDE: 0x1244d8 | Size: 160 bytes [_ZN11fast_engine7LongObj8_NumBitsEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1515 | Địa chỉ PC: 0x0d2fdc | Địa chỉ FDE: 0x1244d8 | Kích thước: 160 bytes
//   0x0d2fdc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d2fe0: 910003FD  mov      x29, sp
//   0x0d2fe4: F9402008  ldr      x8, [x0, #0x40]
//   0x0d2fe8: F100011F  cmp      x8, #0
static inline uint64_t fde_func_1515_0x0d2fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2fdcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1244d8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1516 | PC: 0x0d307c | FDE: 0x124d50 | Size: 256 bytes [_ZN11fast_engine7LongObj10FromDoubleEdPNS_6EngineE]
// Hàm FDE #1516 | Địa chỉ PC: 0x0d307c | Địa chỉ FDE: 0x124d50 | Kích thước: 256 bytes
//   0x0d307c: D10143FF  sub      sp, sp, #0x50
//   0x0d3080: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x0d3084: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d3088: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1516_0x0d307c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d307cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x124d50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1517 | PC: 0x0d3274 | FDE: 0x1244f8 | Size: 256 bytes [_ZN11fast_engine7LongObj10AsLongLongEPS0_PNS_6EngineE]
// Hàm FDE #1517 | Địa chỉ PC: 0x0d3274 | Địa chỉ FDE: 0x1244f8 | Kích thước: 256 bytes
//   0x0d3274: D10103FF  sub      sp, sp, #0x40
//   0x0d3278: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d327c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d3280: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1517_0x0d3274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3274ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1244f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1518 | PC: 0x0d3388 | FDE: 0x124520 | Size: 256 bytes
// Hàm FDE #1518 | Địa chỉ PC: 0x0d3388 | Địa chỉ FDE: 0x124520 | Kích thước: 256 bytes
//   0x0d3388: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d338c: 910003FD  mov      x29, sp
//   0x0d3390: F940200C  ldr      x12, [x0, #0x40]
//   0x0d3394: B7F8006C  tbnz     x12, #0x3f, #0xd33a0
static inline uint64_t fde_func_1518_0x0d3388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3388ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x124520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1519 | PC: 0x0d3540 | FDE: 0x124540 | Size: 256 bytes [_ZN11fast_engine7LongObj16RoundWithNDigitsEPS0_xPNS_6EngineE]
// Hàm FDE #1519 | Địa chỉ PC: 0x0d3540 | Địa chỉ FDE: 0x124540 | Kích thước: 256 bytes
//   0x0d3540: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d3544: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d3548: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d354c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1519_0x0d3540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3540ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x124540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1520 | PC: 0x0d3d48 | FDE: 0x124570 | Size: 92 bytes [_ZN11fast_engine7LongObj18AsUnsignedLongLongEPS0_PNS_6EngineE]
// Hàm FDE #1520 | Địa chỉ PC: 0x0d3d48 | Địa chỉ FDE: 0x124570 | Kích thước: 92 bytes
//   0x0d3d48: D10083FF  sub      sp, sp, #0x20
//   0x0d3d4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d3d50: 910043FD  add      x29, sp, #0x10
//   0x0d3d54: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1520_0x0d3d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3d48ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124570ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1521 | PC: 0x0d3da4 | FDE: 0x124590 | Size: 248 bytes [_ZN11fast_engine7LongObj8AsDoubleEPS0_PNS_6EngineE]
// Hàm FDE #1521 | Địa chỉ PC: 0x0d3da4 | Địa chỉ FDE: 0x124590 | Kích thước: 248 bytes
//   0x0d3da4: D100C3FF  sub      sp, sp, #0x30
//   0x0d3da8: FD000BE8  str      d8, [sp, #0x10]
//   0x0d3dac: F9000FF3  str      x19, [sp, #0x18]
//   0x0d3db0: A9027BFD  stp      x29, x30, [sp, #0x20]
static inline uint64_t fde_func_1521_0x0d3da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3da4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x124590ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1522 | PC: 0x0d3e9c | FDE: 0x124d80 | Size: 256 bytes [_ZN11fast_engine7LongObj8AsStringEPS0_PNS_6EngineE]
// Hàm FDE #1522 | Địa chỉ PC: 0x0d3e9c | Địa chỉ FDE: 0x124d80 | Kích thước: 256 bytes
//   0x0d3e9c: D10203FF  sub      sp, sp, #0x80
//   0x0d3ea0: F90013FB  str      x27, [sp, #0x20]
//   0x0d3ea4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0d3ea8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1522_0x0d3e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3e9cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x124d80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1523 | PC: 0x0d4328 | FDE: 0x124db8 | Size: 96 bytes [_ZN11fast_engine13AllocLongTypeEPNS_6EngineE]
// Hàm FDE #1523 | Địa chỉ PC: 0x0d4328 | Địa chỉ FDE: 0x124db8 | Kích thước: 96 bytes
//   0x0d4328: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d432c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d4330: 910043FD  add      x29, sp, #0x10
//   0x0d4334: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1523_0x0d4328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4328ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124db8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1524 | PC: 0x0d4388 | FDE: 0x1245b0 | Size: 256 bytes [_ZN11fast_engine12InitLongTypeEPNS_6EngineE]
// Hàm FDE #1524 | Địa chỉ PC: 0x0d4388 | Địa chỉ FDE: 0x1245b0 | Kích thước: 256 bytes
//   0x0d4388: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d438c: 910003FD  mov      x29, sp
//   0x0d4390: F0000448  adrp     x8, #0x15f000
//   0x0d4394: 91148108  add      x8, x8, #0x520
static inline uint64_t fde_func_1524_0x0d4388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4388ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1245b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1525 | PC: 0x0d44c8 | FDE: 0x1245d0 | Size: 256 bytes
// Hàm FDE #1525 | Địa chỉ PC: 0x0d44c8 | Địa chỉ FDE: 0x1245d0 | Kích thước: 256 bytes
//   0x0d44c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d44cc: 910003FD  mov      x29, sp
//   0x0d44d0: F9401409  ldr      x9, [x0, #0x28]
//   0x0d44d4: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_1525_0x0d44c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d44c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1245d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1526 | PC: 0x0d45d4 | FDE: 0x1245f0 | Size: 256 bytes
// Hàm FDE #1526 | Địa chỉ PC: 0x0d45d4 | Địa chỉ FDE: 0x1245f0 | Kích thước: 256 bytes
//   0x0d45d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d45d8: 910003FD  mov      x29, sp
//   0x0d45dc: F9401409  ldr      x9, [x0, #0x28]
//   0x0d45e0: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_1526_0x0d45d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d45d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1245f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1527 | PC: 0x0d46e4 | FDE: 0x124de0 | Size: 256 bytes
// Hàm FDE #1527 | Địa chỉ PC: 0x0d46e4 | Địa chỉ FDE: 0x124de0 | Kích thước: 256 bytes
//   0x0d46e4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0d46e8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d46ec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d46f0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1527_0x0d46e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d46e4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x124de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1528 | PC: 0x0d4af4 | FDE: 0x124610 | Size: 256 bytes
// Hàm FDE #1528 | Địa chỉ PC: 0x0d4af4 | Địa chỉ FDE: 0x124610 | Kích thước: 256 bytes
//   0x0d4af4: D100C3FF  sub      sp, sp, #0x30
//   0x0d4af8: F9000BF3  str      x19, [sp, #0x10]
//   0x0d4afc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d4b00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1528_0x0d4af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4af4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x124610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1529 | PC: 0x0d4bf4 | FDE: 0x124630 | Size: 256 bytes
// Hàm FDE #1529 | Địa chỉ PC: 0x0d4bf4 | Địa chỉ FDE: 0x124630 | Kích thước: 256 bytes
//   0x0d4bf4: D10143FF  sub      sp, sp, #0x50
//   0x0d4bf8: F90013F5  str      x21, [sp, #0x20]
//   0x0d4bfc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d4c00: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1529_0x0d4bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4bf4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x124630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1530 | PC: 0x0d4d10 | FDE: 0x124650 | Size: 256 bytes
// Hàm FDE #1530 | Địa chỉ PC: 0x0d4d10 | Địa chỉ FDE: 0x124650 | Kích thước: 256 bytes
//   0x0d4d10: D105C3FF  sub      sp, sp, #0x170
//   0x0d4d14: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x0d4d18: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x0d4d1c: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1530_0x0d4d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4d10ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x124650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1531 | PC: 0x0d52c4 | FDE: 0x124680 | Size: 124 bytes
// Hàm FDE #1531 | Địa chỉ PC: 0x0d52c4 | Địa chỉ FDE: 0x124680 | Kích thước: 124 bytes
//   0x0d52c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d52c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d52cc: 910043FD  add      x29, sp, #0x10
//   0x0d52d0: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1531_0x0d52c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d52c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124680ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1532 | PC: 0x0d5340 | FDE: 0x1246a0 | Size: 56 bytes
// Hàm FDE #1532 | Địa chỉ PC: 0x0d5340 | Địa chỉ FDE: 0x1246a0 | Kích thước: 56 bytes
//   0x0d5340: D0000349  adrp     x9, #0x13f000
//   0x0d5344: F9401408  ldr      x8, [x0, #0x28]
//   0x0d5348: F946C129  ldr      x9, [x9, #0xd80]
//   0x0d534c: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_1532_0x0d5340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5340ULL ^ (static_cast<uint64_t>(0xd0000349ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x1246a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1533 | PC: 0x0d5378 | FDE: 0x1246b8 | Size: 164 bytes
// Hàm FDE #1533 | Địa chỉ PC: 0x0d5378 | Địa chỉ FDE: 0x1246b8 | Kích thước: 164 bytes
//   0x0d5378: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d537c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5380: 910043FD  add      x29, sp, #0x10
//   0x0d5384: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1533_0x0d5378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5378ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1246b8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1534 | PC: 0x0d541c | FDE: 0x1246d8 | Size: 16 bytes
// Hàm FDE #1534 | Địa chỉ PC: 0x0d541c | Địa chỉ FDE: 0x1246d8 | Kích thước: 16 bytes
//   0x0d541c: F9402008  ldr      x8, [x0, #0x40]
//   0x0d5420: F100011F  cmp      x8, #0
//   0x0d5424: 1A9F07E0  cset     w0, ne
//   0x0d5428: D65F03C0  ret      
static inline uint64_t fde_func_1534_0x0d541c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d541cULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x1246d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1535 | PC: 0x0d542c | FDE: 0x1246f0 | Size: 256 bytes
// Hàm FDE #1535 | Địa chỉ PC: 0x0d542c | Địa chỉ FDE: 0x1246f0 | Kích thước: 256 bytes
//   0x0d542c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d5430: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5434: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5438: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1535_0x0d542c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d542cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1246f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1536 | PC: 0x0d554c | FDE: 0x124710 | Size: 188 bytes
// Hàm FDE #1536 | Địa chỉ PC: 0x0d554c | Địa chỉ FDE: 0x124710 | Kích thước: 188 bytes
//   0x0d554c: D100C3FF  sub      sp, sp, #0x30
//   0x0d5550: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5554: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5558: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1536_0x0d554c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d554cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124710ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1537 | PC: 0x0d5608 | FDE: 0x124730 | Size: 188 bytes
// Hàm FDE #1537 | Địa chỉ PC: 0x0d5608 | Địa chỉ FDE: 0x124730 | Kích thước: 188 bytes
//   0x0d5608: D100C3FF  sub      sp, sp, #0x30
//   0x0d560c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5610: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5614: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1537_0x0d5608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5608ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124730ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1538 | PC: 0x0d56c4 | FDE: 0x124750 | Size: 56 bytes
// Hàm FDE #1538 | Địa chỉ PC: 0x0d56c4 | Địa chỉ FDE: 0x124750 | Kích thước: 56 bytes
//   0x0d56c4: F9401408  ldr      x8, [x0, #0x28]
//   0x0d56c8: 3942AD08  ldrb     w8, [x8, #0xab]
//   0x0d56cc: 360000C8  tbz      w8, #0, #0xd56e4
//   0x0d56d0: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1538_0x0d56c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d56c4ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x3942ad08ULL) ^ 0x124750ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1539 | PC: 0x0d56fc | FDE: 0x124768 | Size: 56 bytes
// Hàm FDE #1539 | Địa chỉ PC: 0x0d56fc | Địa chỉ FDE: 0x124768 | Kích thước: 56 bytes
//   0x0d56fc: F9401408  ldr      x8, [x0, #0x28]
//   0x0d5700: 3942AD08  ldrb     w8, [x8, #0xab]
//   0x0d5704: 360000C8  tbz      w8, #0, #0xd571c
//   0x0d5708: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1539_0x0d56fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d56fcULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x3942ad08ULL) ^ 0x124768ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1540 | PC: 0x0d5734 | FDE: 0x124780 | Size: 56 bytes
// Hàm FDE #1540 | Địa chỉ PC: 0x0d5734 | Địa chỉ FDE: 0x124780 | Kích thước: 56 bytes
//   0x0d5734: F9401408  ldr      x8, [x0, #0x28]
//   0x0d5738: 3942AD08  ldrb     w8, [x8, #0xab]
//   0x0d573c: 360000C8  tbz      w8, #0, #0xd5754
//   0x0d5740: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1540_0x0d5734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5734ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x3942ad08ULL) ^ 0x124780ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1541 | PC: 0x0d576c | FDE: 0x124e18 | Size: 212 bytes
// Hàm FDE #1541 | Địa chỉ PC: 0x0d576c | Địa chỉ FDE: 0x124e18 | Kích thước: 212 bytes
//   0x0d576c: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0d5770: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5774: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5778: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1541_0x0d576c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d576cULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x124e18ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1542 | PC: 0x0d5840 | FDE: 0x124798 | Size: 240 bytes
// Hàm FDE #1542 | Địa chỉ PC: 0x0d5840 | Địa chỉ FDE: 0x124798 | Kích thước: 240 bytes
//   0x0d5840: D100C3FF  sub      sp, sp, #0x30
//   0x0d5844: F9000BF3  str      x19, [sp, #0x10]
//   0x0d5848: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d584c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1542_0x0d5840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5840ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x124798ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1543 | PC: 0x0d5930 | FDE: 0x124e40 | Size: 256 bytes
// Hàm FDE #1543 | Địa chỉ PC: 0x0d5930 | Địa chỉ FDE: 0x124e40 | Kích thước: 256 bytes
//   0x0d5930: D10243FF  sub      sp, sp, #0x90
//   0x0d5934: FD0013E8  str      d8, [sp, #0x20]
//   0x0d5938: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0d593c: A90467FA  stp      x26, x25, [sp, #0x40]
static inline uint64_t fde_func_1543_0x0d5930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5930ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x124e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1544 | PC: 0x0d61b8 | FDE: 0x1247b8 | Size: 256 bytes
// Hàm FDE #1544 | Địa chỉ PC: 0x0d61b8 | Địa chỉ FDE: 0x1247b8 | Kích thước: 256 bytes
//   0x0d61b8: D10203FF  sub      sp, sp, #0x80
//   0x0d61bc: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0d61c0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d61c4: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1544_0x0d61b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d61b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x1247b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1545 | PC: 0x0d64d0 | FDE: 0x1247e0 | Size: 256 bytes
// Hàm FDE #1545 | Địa chỉ PC: 0x0d64d0 | Địa chỉ FDE: 0x1247e0 | Kích thước: 256 bytes
//   0x0d64d0: D10203FF  sub      sp, sp, #0x80
//   0x0d64d4: F9001BF9  str      x25, [sp, #0x30]
//   0x0d64d8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0d64dc: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1545_0x0d64d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d64d0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1247e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1546 | PC: 0x0d6788 | FDE: 0x124e78 | Size: 256 bytes
// Hàm FDE #1546 | Địa chỉ PC: 0x0d6788 | Địa chỉ FDE: 0x124e78 | Kích thước: 256 bytes
//   0x0d6788: D10543FF  sub      sp, sp, #0x150
//   0x0d678c: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0d6790: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x0d6794: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_1546_0x0d6788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6788ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x124e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1547 | PC: 0x0d6fdc | FDE: 0x124808 | Size: 256 bytes
// Hàm FDE #1547 | Địa chỉ PC: 0x0d6fdc | Địa chỉ FDE: 0x124808 | Kích thước: 256 bytes
//   0x0d6fdc: D101C3FF  sub      sp, sp, #0x70
//   0x0d6fe0: F9001BF7  str      x23, [sp, #0x30]
//   0x0d6fe4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0d6fe8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1547_0x0d6fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6fdcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x124808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1548 | PC: 0x0d71d8 | FDE: 0x124830 | Size: 180 bytes
// Hàm FDE #1548 | Địa chỉ PC: 0x0d71d8 | Địa chỉ FDE: 0x124830 | Kích thước: 180 bytes
//   0x0d71d8: AA0003E8  mov      x8, x0
//   0x0d71dc: F9402000  ldr      x0, [x0, #0x40]
//   0x0d71e0: B100041F  cmn      x0, #1
//   0x0d71e4: 540000E0  b.eq     #0xd7200
static inline uint64_t fde_func_1548_0x0d71d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d71d8ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9402000ULL) ^ 0x124830ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1549 | PC: 0x0d728c | FDE: 0x124848 | Size: 256 bytes
// Hàm FDE #1549 | Địa chỉ PC: 0x0d728c | Địa chỉ FDE: 0x124848 | Kích thước: 256 bytes
//   0x0d728c: F9401408  ldr      x8, [x0, #0x28]
//   0x0d7290: 3942AD08  ldrb     w8, [x8, #0xab]
//   0x0d7294: 36000088  tbz      w8, #0, #0xd72a4
//   0x0d7298: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1549_0x0d728c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d728cULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x3942ad08ULL) ^ 0x124848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1550 | PC: 0x0d73e0 | FDE: 0x124eb0 | Size: 140 bytes
// Hàm FDE #1550 | Địa chỉ PC: 0x0d73e0 | Địa chỉ FDE: 0x124eb0 | Kích thước: 140 bytes
//   0x0d73e0: D10103FF  sub      sp, sp, #0x40
//   0x0d73e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d73e8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d73ec: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1550_0x0d73e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d73e0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x124eb0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1551 | PC: 0x0d746c | FDE: 0x124860 | Size: 88 bytes [_ZN11fast_engine8FloatObjC1EPNS_6EngineEd]
// Hàm FDE #1551 | Địa chỉ PC: 0x0d746c | Địa chỉ FDE: 0x124860 | Kích thước: 88 bytes
//   0x0d746c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x0d7470: F90007F3  str      x19, [sp, #8]
//   0x0d7474: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d7478: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1551_0x0d746c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d746cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f3ULL) ^ 0x124860ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1552 | PC: 0x0d74c4 | FDE: 0x124880 | Size: 240 bytes [_ZN11fast_engine8FloatObj12RoundDefaultEdPNS_6EngineE]
// Hàm FDE #1552 | Địa chỉ PC: 0x0d74c4 | Địa chỉ FDE: 0x124880 | Kích thước: 240 bytes
//   0x0d74c4: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x0d74c8: F9000BF3  str      x19, [sp, #0x10]
//   0x0d74cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d74d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1552_0x0d74c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d74c4ULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x124880ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1553 | PC: 0x0d75b4 | FDE: 0x124ed8 | Size: 256 bytes [_ZN11fast_engine8FloatObj16RoundWithNDigitsEdxPNS_6EngineE]
// Hàm FDE #1553 | Địa chỉ PC: 0x0d75b4 | Địa chỉ FDE: 0x124ed8 | Kích thước: 256 bytes
//   0x0d75b4: D10143FF  sub      sp, sp, #0x50
//   0x0d75b8: FD000BEA  str      d10, [sp, #0x10]
//   0x0d75bc: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x0d75c0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1553_0x0d75b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d75b4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000beaULL) ^ 0x124ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1554 | PC: 0x0d793c | FDE: 0x124f08 | Size: 256 bytes [_ZN11fast_engine11DoubleToStrEd]
// Hàm FDE #1554 | Địa chỉ PC: 0x0d793c | Địa chỉ FDE: 0x124f08 | Kích thước: 256 bytes
//   0x0d793c: FC190FE8  str      d8, [sp, #-0x70]!
//   0x0d7940: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0d7944: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0d7948: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1554_0x0d793c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d793cULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x124f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1555 | PC: 0x0d818c | FDE: 0x124f40 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEd]
// Hàm FDE #1555 | Địa chỉ PC: 0x0d818c | Địa chỉ FDE: 0x124f40 | Kích thước: 256 bytes
//   0x0d818c: D101C3FF  sub      sp, sp, #0x70
//   0x0d8190: FD0013E8  str      d8, [sp, #0x20]
//   0x0d8194: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0d8198: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1555_0x0d818c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d818cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x124f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1556 | PC: 0x0d8354 | FDE: 0x124f70 | Size: 256 bytes [_ZN11fast_engine8FloatObj10FromStringEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1556 | Địa chỉ PC: 0x0d8354 | Địa chỉ FDE: 0x124f70 | Kích thước: 256 bytes
//   0x0d8354: FC1B0FE8  str      d8, [sp, #-0x50]!
//   0x0d8358: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d835c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d8360: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1556_0x0d8354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8354ULL ^ (static_cast<uint64_t>(0xfc1b0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x124f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1557 | PC: 0x0d85d0 | FDE: 0x1248a8 | Size: 256 bytes [_ZN11fast_engine8FloatObj8AsDoubleEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1557 | Địa chỉ PC: 0x0d85d0 | Địa chỉ FDE: 0x1248a8 | Kích thước: 256 bytes
//   0x0d85d0: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x0d85d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d85d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d85dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1557_0x0d85d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d85d0ULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1248a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1558 | PC: 0x0d8798 | FDE: 0x124fa0 | Size: 96 bytes [_ZN11fast_engine14AllocFloatTypeEPNS_6EngineE]
// Hàm FDE #1558 | Địa chỉ PC: 0x0d8798 | Địa chỉ FDE: 0x124fa0 | Kích thước: 96 bytes
//   0x0d8798: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d879c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d87a0: 910043FD  add      x29, sp, #0x10
//   0x0d87a4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1558_0x0d8798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8798ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124fa0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1559 | PC: 0x0d87f8 | FDE: 0x1248d0 | Size: 240 bytes [_ZN11fast_engine13InitFloatTypeEPNS_6EngineE]
// Hàm FDE #1559 | Địa chỉ PC: 0x0d87f8 | Địa chỉ FDE: 0x1248d0 | Kích thước: 240 bytes
//   0x0d87f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d87fc: 910003FD  mov      x29, sp
//   0x0d8800: F0000329  adrp     x9, #0x13f000
//   0x0d8804: F945A529  ldr      x9, [x9, #0xb48]
static inline uint64_t fde_func_1559_0x0d87f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d87f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1248d0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1560 | PC: 0x0d88e8 | FDE: 0x124fc8 | Size: 256 bytes
// Hàm FDE #1560 | Địa chỉ PC: 0x0d88e8 | Địa chỉ FDE: 0x124fc8 | Kích thước: 256 bytes
//   0x0d88e8: 6DBB23E9  stp      d9, d8, [sp, #-0x50]!
//   0x0d88ec: F9000BF7  str      x23, [sp, #0x10]
//   0x0d88f0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d88f4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1560_0x0d88e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d88e8ULL ^ (static_cast<uint64_t>(0x6dbb23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x124fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1561 | PC: 0x0d8a7c | FDE: 0x125000 | Size: 256 bytes
// Hàm FDE #1561 | Địa chỉ PC: 0x0d8a7c | Địa chỉ FDE: 0x125000 | Kích thước: 256 bytes
//   0x0d8a7c: 6DBB23E9  stp      d9, d8, [sp, #-0x50]!
//   0x0d8a80: F9000BF7  str      x23, [sp, #0x10]
//   0x0d8a84: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d8a88: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1561_0x0d8a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8a7cULL ^ (static_cast<uint64_t>(0x6dbb23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x125000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1562 | PC: 0x0d8c10 | FDE: 0x125038 | Size: 256 bytes
// Hàm FDE #1562 | Địa chỉ PC: 0x0d8c10 | Địa chỉ FDE: 0x125038 | Kích thước: 256 bytes
//   0x0d8c10: 6DBB23E9  stp      d9, d8, [sp, #-0x50]!
//   0x0d8c14: F9000BF7  str      x23, [sp, #0x10]
//   0x0d8c18: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d8c1c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1562_0x0d8c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8c10ULL ^ (static_cast<uint64_t>(0x6dbb23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x125038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1563 | PC: 0x0d8da4 | FDE: 0x125070 | Size: 256 bytes
// Hàm FDE #1563 | Địa chỉ PC: 0x0d8da4 | Địa chỉ FDE: 0x125070 | Kích thước: 256 bytes
//   0x0d8da4: D10143FF  sub      sp, sp, #0x50
//   0x0d8da8: FD000BE8  str      d8, [sp, #0x10]
//   0x0d8dac: F9000FF7  str      x23, [sp, #0x18]
//   0x0d8db0: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_1563_0x0d8da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8da4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x125070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1564 | PC: 0x0d8fc4 | FDE: 0x1250a0 | Size: 256 bytes
// Hàm FDE #1564 | Địa chỉ PC: 0x0d8fc4 | Địa chỉ FDE: 0x1250a0 | Kích thước: 256 bytes
//   0x0d8fc4: D10183FF  sub      sp, sp, #0x60
//   0x0d8fc8: FD0013E8  str      d8, [sp, #0x20]
//   0x0d8fcc: F90017F7  str      x23, [sp, #0x28]
//   0x0d8fd0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1564_0x0d8fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8fc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x1250a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1565 | PC: 0x0d92ac | FDE: 0x1250d0 | Size: 256 bytes
// Hàm FDE #1565 | Địa chỉ PC: 0x0d92ac | Địa chỉ FDE: 0x1250d0 | Kích thước: 256 bytes
//   0x0d92ac: D10183FF  sub      sp, sp, #0x60
//   0x0d92b0: FD000BEA  str      d10, [sp, #0x10]
//   0x0d92b4: 6D01A3E9  stp      d9, d8, [sp, #0x18]
//   0x0d92b8: F90017F7  str      x23, [sp, #0x28]
static inline uint64_t fde_func_1565_0x0d92ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d92acULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd000beaULL) ^ 0x1250d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1566 | PC: 0x0d99a0 | FDE: 0x125108 | Size: 180 bytes
// Hàm FDE #1566 | Địa chỉ PC: 0x0d99a0 | Địa chỉ FDE: 0x125108 | Kích thước: 180 bytes
//   0x0d99a0: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0d99a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d99a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d99ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1566_0x0d99a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d99a0ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125108ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1567 | PC: 0x0d9a54 | FDE: 0x125130 | Size: 236 bytes
// Hàm FDE #1567 | Địa chỉ PC: 0x0d9a54 | Địa chỉ FDE: 0x125130 | Kích thước: 236 bytes
//   0x0d9a54: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d9a58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d9a5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d9a60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1567_0x0d9a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9a54ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125130ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1568 | PC: 0x0d9b40 | FDE: 0x125160 | Size: 180 bytes
// Hàm FDE #1568 | Địa chỉ PC: 0x0d9b40 | Địa chỉ FDE: 0x125160 | Kích thước: 180 bytes
//   0x0d9b40: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0d9b44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d9b48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d9b4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1568_0x0d9b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9b40ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125160ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1569 | PC: 0x0d9bf4 | FDE: 0x1248f0 | Size: 16 bytes
// Hàm FDE #1569 | Địa chỉ PC: 0x0d9bf4 | Địa chỉ FDE: 0x1248f0 | Kích thước: 16 bytes
//   0x0d9bf4: FD402000  ldr      d0, [x0, #0x40]
//   0x0d9bf8: 1E602008  fcmp     d0, #0.0
//   0x0d9bfc: 1A9F07E0  cset     w0, ne
//   0x0d9c00: D65F03C0  ret      
static inline uint64_t fde_func_1569_0x0d9bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9bf4ULL ^ (static_cast<uint64_t>(0xfd402000ULL) << 13);
    acc = (acc + a1 + 0x1e602008ULL) ^ 0x1248f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1570 | PC: 0x0d9c04 | FDE: 0x124908 | Size: 12 bytes
// Hàm FDE #1570 | Địa chỉ PC: 0x0d9c04 | Địa chỉ FDE: 0x124908 | Kích thước: 12 bytes
//   0x0d9c04: FD402000  ldr      d0, [x0, #0x40]
//   0x0d9c08: AA0103E0  mov      x0, x1
//   0x0d9c0c: 17FDAE01  b        #0x45410
static inline uint64_t fde_func_1570_0x0d9c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9c04ULL ^ (static_cast<uint64_t>(0xfd402000ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x124908ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1571 | PC: 0x0d9c10 | FDE: 0x125188 | Size: 256 bytes
// Hàm FDE #1571 | Địa chỉ PC: 0x0d9c10 | Địa chỉ FDE: 0x125188 | Kích thước: 256 bytes
//   0x0d9c10: D10183FF  sub      sp, sp, #0x60
//   0x0d9c14: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x0d9c18: F90013F7  str      x23, [sp, #0x20]
//   0x0d9c1c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1571_0x0d9c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9c10ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x125188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1572 | PC: 0x0d9e50 | FDE: 0x1251c0 | Size: 256 bytes
// Hàm FDE #1572 | Địa chỉ PC: 0x0d9e50 | Địa chỉ FDE: 0x1251c0 | Kích thước: 256 bytes
//   0x0d9e50: 6DBB23E9  stp      d9, d8, [sp, #-0x50]!
//   0x0d9e54: F9000BF7  str      x23, [sp, #0x10]
//   0x0d9e58: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d9e5c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1572_0x0d9e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9e50ULL ^ (static_cast<uint64_t>(0x6dbb23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1251c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1573 | PC: 0x0da010 | FDE: 0x1251f8 | Size: 256 bytes
// Hàm FDE #1573 | Địa chỉ PC: 0x0da010 | Địa chỉ FDE: 0x1251f8 | Kích thước: 256 bytes
//   0x0da010: D10183FF  sub      sp, sp, #0x60
//   0x0da014: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0da018: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0da01c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1573_0x0da010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da010ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1251f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1574 | PC: 0x0da1dc | FDE: 0x124920 | Size: 8 bytes
// Hàm FDE #1574 | Địa chỉ PC: 0x0da1dc | Địa chỉ FDE: 0x124920 | Kích thước: 8 bytes
//   0x0da1dc: FD402000  ldr      d0, [x0, #0x40]
//   0x0da1e0: 17FDA800  b        #0x441e0
static inline uint64_t fde_func_1574_0x0da1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da1dcULL ^ (static_cast<uint64_t>(0xfd402000ULL) << 13);
    acc = (acc + a1 + 0x17fda800ULL) ^ 0x124920ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1575 | PC: 0x0da1e4 | FDE: 0x124938 | Size: 256 bytes
// Hàm FDE #1575 | Địa chỉ PC: 0x0da1e4 | Địa chỉ FDE: 0x124938 | Kích thước: 256 bytes
//   0x0da1e4: D10183FF  sub      sp, sp, #0x60
//   0x0da1e8: FD000BE8  str      d8, [sp, #0x10]
//   0x0da1ec: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0da1f0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1575_0x0da1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da1e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x124938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1576 | PC: 0x0da724 | FDE: 0x125228 | Size: 144 bytes
// Hàm FDE #1576 | Địa chỉ PC: 0x0da724 | Địa chỉ FDE: 0x125228 | Kích thước: 144 bytes
//   0x0da724: D10103FF  sub      sp, sp, #0x40
//   0x0da728: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0da72c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0da730: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1576_0x0da724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da724ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x125228ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1577 | PC: 0x0da7b4 | FDE: 0x125250 | Size: 256 bytes
// Hàm FDE #1577 | Địa chỉ PC: 0x0da7b4 | Địa chỉ FDE: 0x125250 | Kích thước: 256 bytes
//   0x0da7b4: FC190FE8  str      d8, [sp, #-0x70]!
//   0x0da7b8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0da7bc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0da7c0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1577_0x0da7b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da7b4ULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x125250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1578 | PC: 0x0daf18 | FDE: 0x124960 | Size: 36 bytes [_ZN11fast_engine8FloatObjD0Ev]
// Hàm FDE #1578 | Địa chỉ PC: 0x0daf18 | Địa chỉ FDE: 0x124960 | Kích thước: 36 bytes
//   0x0daf18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0daf1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0daf20: 910043FD  add      x29, sp, #0x10
//   0x0daf24: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1578_0x0daf18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daf18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x124960ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1579 | PC: 0x0daf3c | FDE: 0x125288 | Size: 256 bytes
// Hàm FDE #1579 | Địa chỉ PC: 0x0daf3c | Địa chỉ FDE: 0x125288 | Kích thước: 256 bytes
//   0x0daf3c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0daf40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0daf44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0daf48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1579_0x0daf3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daf3cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1580 | PC: 0x0db0ec | FDE: 0x1252b8 | Size: 256 bytes
// Hàm FDE #1580 | Địa chỉ PC: 0x0db0ec | Địa chỉ FDE: 0x1252b8 | Kích thước: 256 bytes
//   0x0db0ec: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0db0f0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0db0f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0db0f8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1580_0x0db0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db0ecULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1252b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1581 | PC: 0x0db3cc | FDE: 0x124980 | Size: 256 bytes
// Hàm FDE #1581 | Địa chỉ PC: 0x0db3cc | Địa chỉ FDE: 0x124980 | Kích thước: 256 bytes
//   0x0db3cc: D10183FF  sub      sp, sp, #0x60
//   0x0db3d0: F9000BF9  str      x25, [sp, #0x10]
//   0x0db3d4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0db3d8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1581_0x0db3cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db3ccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x124980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1582 | PC: 0x0dba4c | FDE: 0x1252e8 | Size: 256 bytes
// Hàm FDE #1582 | Địa chỉ PC: 0x0dba4c | Địa chỉ FDE: 0x1252e8 | Kích thước: 256 bytes
//   0x0dba4c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0dba50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0dba54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0dba58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1582_0x0dba4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dba4cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1252e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1583 | PC: 0x0dbbac | FDE: 0x125318 | Size: 256 bytes
// Hàm FDE #1583 | Địa chỉ PC: 0x0dbbac | Địa chỉ FDE: 0x125318 | Kích thước: 256 bytes
//   0x0dbbac: D101C3FF  sub      sp, sp, #0x70
//   0x0dbbb0: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0dbbb4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dbbb8: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1583_0x0dbbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbbacULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x125318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1584 | PC: 0x0dc084 | FDE: 0x1249a8 | Size: 220 bytes
// Hàm FDE #1584 | Địa chỉ PC: 0x0dc084 | Địa chỉ FDE: 0x1249a8 | Kích thước: 220 bytes
//   0x0dc084: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dc088: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dc08c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dc090: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1584_0x0dc084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc084ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1249a8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1585 | PC: 0x0dc160 | FDE: 0x125350 | Size: 256 bytes
// Hàm FDE #1585 | Địa chỉ PC: 0x0dc160 | Địa chỉ FDE: 0x125350 | Kích thước: 256 bytes
//   0x0dc160: D101C3FF  sub      sp, sp, #0x70
//   0x0dc164: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0dc168: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dc16c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1585_0x0dc160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc160ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x125350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1586 | PC: 0x0dc99c | FDE: 0x1249d0 | Size: 256 bytes
// Hàm FDE #1586 | Địa chỉ PC: 0x0dc99c | Địa chỉ FDE: 0x1249d0 | Kích thước: 256 bytes
//   0x0dc99c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dc9a0: 910003FD  mov      x29, sp
//   0x0dc9a4: 52800408  mov      w8, #0x20
//   0x0dc9a8: 12800009  mov      w9, #-1
static inline uint64_t fde_func_1586_0x0dc99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc99cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1249d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1587 | PC: 0x0dcc68 | FDE: 0x125388 | Size: 256 bytes
// Hàm FDE #1587 | Địa chỉ PC: 0x0dcc68 | Địa chỉ FDE: 0x125388 | Kích thước: 256 bytes
//   0x0dcc68: D101C3FF  sub      sp, sp, #0x70
//   0x0dcc6c: F90013F9  str      x25, [sp, #0x20]
//   0x0dcc70: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0dcc74: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1587_0x0dcc68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcc68ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x125388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1588 | PC: 0x0dcdb0 | FDE: 0x1253b8 | Size: 256 bytes
// Hàm FDE #1588 | Địa chỉ PC: 0x0dcdb0 | Địa chỉ FDE: 0x1253b8 | Kích thước: 256 bytes
//   0x0dcdb0: D10183FF  sub      sp, sp, #0x60
//   0x0dcdb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0dcdb8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0dcdbc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1588_0x0dcdb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcdb0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1253b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1589 | PC: 0x0dcf08 | FDE: 0x1249f0 | Size: 164 bytes
// Hàm FDE #1589 | Địa chỉ PC: 0x0dcf08 | Địa chỉ FDE: 0x1249f0 | Kích thước: 164 bytes
//   0x0dcf08: D10443FF  sub      sp, sp, #0x110
//   0x0dcf0c: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0dcf10: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0dcf14: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1589_0x0dcf08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcf08ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x1249f0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1590 | PC: 0x0dcfac | FDE: 0x1253e8 | Size: 168 bytes [_ZN11fast_engine3ObjC1EPNS_7TypeObjEPNS_6EngineEli]
// Hàm FDE #1590 | Địa chỉ PC: 0x0dcfac | Địa chỉ FDE: 0x1253e8 | Kích thước: 168 bytes
//   0x0dcfac: F0000308  adrp     x8, #0x13f000
//   0x0dcfb0: F945F508  ldr      x8, [x8, #0xbe8]
//   0x0dcfb4: A901081F  stp      xzr, x2, [x0, #0x10]
//   0x0dcfb8: 91004108  add      x8, x8, #0x10
static inline uint64_t fde_func_1590_0x0dcfac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcfacULL ^ (static_cast<uint64_t>(0xf0000308ULL) << 13);
    acc = (acc + a1 + 0xf945f508ULL) ^ 0x1253e8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1591 | PC: 0x0dd054 | FDE: 0x1258a0 | Size: 236 bytes [_ZN11fast_engine3ObjD2Ev]
// Hàm FDE #1591 | Địa chỉ PC: 0x0dd054 | Địa chỉ FDE: 0x1258a0 | Kích thước: 236 bytes
//   0x0dd054: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dd058: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd05c: 910043FD  add      x29, sp, #0x10
//   0x0dd060: D0000308  adrp     x8, #0x13f000
static inline uint64_t fde_func_1591_0x0dd054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd054ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1258a0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1592 | PC: 0x0dd140 | FDE: 0x125400 | Size: 36 bytes [_ZN11fast_engine3ObjD0Ev]
// Hàm FDE #1592 | Địa chỉ PC: 0x0dd140 | Địa chỉ FDE: 0x125400 | Kích thước: 36 bytes
//   0x0dd140: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dd144: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd148: 910043FD  add      x29, sp, #0x10
//   0x0dd14c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1592_0x0dd140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd140ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125400ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1593 | PC: 0x0dd164 | FDE: 0x125420 | Size: 12 bytes [_ZN11fast_engine3Obj2IsEPKS0_S2_]
// Hàm FDE #1593 | Địa chỉ PC: 0x0dd164 | Địa chỉ FDE: 0x125420 | Kích thước: 12 bytes
//   0x0dd164: EB01001F  cmp      x0, x1
//   0x0dd168: 1A9F17E0  cset     w0, eq
//   0x0dd16c: D65F03C0  ret      
static inline uint64_t fde_func_1593_0x0dd164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd164ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e0ULL) ^ 0x125420ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1594 | PC: 0x0dd170 | FDE: 0x125438 | Size: 228 bytes [_ZN11fast_engine3Obj10IsInstanceEPKS0_S2_PNS_6EngineE]
// Hàm FDE #1594 | Địa chỉ PC: 0x0dd170 | Địa chỉ FDE: 0x125438 | Kích thước: 228 bytes
//   0x0dd170: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dd174: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dd178: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dd17c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1594_0x0dd170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd170ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125438ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1595 | PC: 0x0dd254 | FDE: 0x125460 | Size: 240 bytes [_ZN11fast_engine3Obj10IsSubclassEPKS0_S2_PNS_6EngineE]
// Hàm FDE #1595 | Địa chỉ PC: 0x0dd254 | Địa chỉ FDE: 0x125460 | Kích thước: 240 bytes
//   0x0dd254: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dd258: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dd25c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dd260: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1595_0x0dd254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd254ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125460ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1596 | PC: 0x0dd344 | FDE: 0x125488 | Size: 96 bytes [_ZN11fast_engine3Obj4HashEPS0_PNS_6EngineE]
// Hàm FDE #1596 | Địa chỉ PC: 0x0dd344 | Địa chỉ FDE: 0x125488 | Kích thước: 96 bytes
//   0x0dd344: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dd348: 910003FD  mov      x29, sp
//   0x0dd34c: F9401409  ldr      x9, [x0, #0x28]
//   0x0dd350: F9404122  ldr      x2, [x9, #0x80]
static inline uint64_t fde_func_1596_0x0dd344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd344ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125488ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1597 | PC: 0x0dd3a4 | FDE: 0x1254a8 | Size: 80 bytes [_ZN11fast_engine3Obj18HashNotImplementedEPS0_PNS_6EngineE]
// Hàm FDE #1597 | Địa chỉ PC: 0x0dd3a4 | Địa chỉ FDE: 0x1254a8 | Kích thước: 80 bytes
//   0x0dd3a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dd3a8: 910003FD  mov      x29, sp
//   0x0dd3ac: F9401409  ldr      x9, [x0, #0x28]
//   0x0dd3b0: D0000308  adrp     x8, #0x13f000
static inline uint64_t fde_func_1597_0x0dd3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd3a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1254a8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1598 | PC: 0x0dd3f4 | FDE: 0x1254c8 | Size: 176 bytes [_ZN11fast_engine3Obj7GetAttrEPS0_S1_PNS_6EngineE]
// Hàm FDE #1598 | Địa chỉ PC: 0x0dd3f4 | Địa chỉ FDE: 0x1254c8 | Kích thước: 176 bytes
//   0x0dd3f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dd3f8: 910003FD  mov      x29, sp
//   0x0dd3fc: F9401428  ldr      x8, [x1, #0x28]
//   0x0dd400: 3942AD09  ldrb     w9, [x8, #0xab]
static inline uint64_t fde_func_1598_0x0dd3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd3f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1254c8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1599 | PC: 0x0dd4a4 | FDE: 0x1254e8 | Size: 212 bytes [_ZN11fast_engine3Obj9GetAttrIdEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1599 | Địa chỉ PC: 0x0dd4a4 | Địa chỉ FDE: 0x1254e8 | Kích thước: 212 bytes
//   0x0dd4a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dd4a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd4ac: 910043FD  add      x29, sp, #0x10
//   0x0dd4b0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1599_0x0dd4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd4a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1254e8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1600 | PC: 0x0dd578 | FDE: 0x125508 | Size: 124 bytes [_ZN11fast_engine3Obj14_LookupSpecialEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1600 | Địa chỉ PC: 0x0dd578 | Địa chỉ FDE: 0x125508 | Kích thước: 124 bytes
//   0x0dd578: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dd57c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd580: 910043FD  add      x29, sp, #0x10
//   0x0dd584: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1600_0x0dd578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd578ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125508ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1601 | PC: 0x0dd5f4 | FDE: 0x1258c8 | Size: 256 bytes [_ZN11fast_engine3Obj6FormatEPS0_S1_PNS_6EngineE]
// Hàm FDE #1601 | Địa chỉ PC: 0x0dd5f4 | Địa chỉ FDE: 0x1258c8 | Kích thước: 256 bytes
//   0x0dd5f4: D101C3FF  sub      sp, sp, #0x70
//   0x0dd5f8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dd5fc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0dd600: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1601_0x0dd5f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd5f4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1258c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1602 | PC: 0x0ddac8 | FDE: 0x125900 | Size: 256 bytes [_ZN11fast_engine3Obj3StrEPS0_PNS_6EngineE]
// Hàm FDE #1602 | Địa chỉ PC: 0x0ddac8 | Địa chỉ FDE: 0x125900 | Kích thước: 256 bytes
//   0x0ddac8: D10143FF  sub      sp, sp, #0x50
//   0x0ddacc: F90013F5  str      x21, [sp, #0x20]
//   0x0ddad0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ddad4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1602_0x0ddac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddac8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x125900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1603 | PC: 0x0ddcf4 | FDE: 0x125528 | Size: 256 bytes [_ZN11fast_engine3Obj15GetOptionalAttrEPS0_S1_PS1_PNS_6EngineE]
// Hàm FDE #1603 | Địa chỉ PC: 0x0ddcf4 | Địa chỉ FDE: 0x125528 | Kích thước: 256 bytes
//   0x0ddcf4: D10103FF  sub      sp, sp, #0x40
//   0x0ddcf8: F9000BF5  str      x21, [sp, #0x10]
//   0x0ddcfc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ddd00: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1603_0x0ddcf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddcf4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x125528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1604 | PC: 0x0dde68 | FDE: 0x125548 | Size: 16 bytes [_ZN11fast_engine3Obj14GenericGetAttrEPS0_PNS_6StrObjEPNS_6EngineE]
// Hàm FDE #1604 | Địa chỉ PC: 0x0dde68 | Địa chỉ FDE: 0x125548 | Kích thước: 16 bytes
//   0x0dde68: AA0203E4  mov      x4, x2
//   0x0dde6c: AA1F03E2  mov      x2, xzr
//   0x0dde70: 2A1F03E3  mov      w3, wzr
//   0x0dde74: 17FD950F  b        #0x432b0
static inline uint64_t fde_func_1604_0x0dde68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dde68ULL ^ (static_cast<uint64_t>(0xaa0203e4ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e2ULL) ^ 0x125548ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1605 | PC: 0x0dde78 | FDE: 0x125560 | Size: 256 bytes [_ZN11fast_engine3Obj22GenericGetAttrWithDictEPS0_PNS_6StrObjES1_bPNS_6EngineE]
// Hàm FDE #1605 | Địa chỉ PC: 0x0dde78 | Địa chỉ FDE: 0x125560 | Kích thước: 256 bytes
//   0x0dde78: D101C3FF  sub      sp, sp, #0x70
//   0x0dde7c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0dde80: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dde84: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1605_0x0dde78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dde78ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x125560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1606 | PC: 0x0de270 | FDE: 0x125928 | Size: 248 bytes [_ZN11fast_engine3Obj21GetOptionalAttrStringEPS0_PKcPS1_PNS_6EngineE]
// Hàm FDE #1606 | Địa chỉ PC: 0x0de270 | Địa chỉ FDE: 0x125928 | Kích thước: 248 bytes
//   0x0de270: D10183FF  sub      sp, sp, #0x60
//   0x0de274: F90013F7  str      x23, [sp, #0x20]
//   0x0de278: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0de27c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1606_0x0de270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de270ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x125928ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1607 | PC: 0x0de368 | FDE: 0x125590 | Size: 112 bytes [_ZN11fast_engine3Obj13HasAttrStringEPS0_PKcPNS_6EngineE]
// Hàm FDE #1607 | Địa chỉ PC: 0x0de368 | Địa chỉ FDE: 0x125590 | Kích thước: 112 bytes
//   0x0de368: D100C3FF  sub      sp, sp, #0x30
//   0x0de36c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de370: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de374: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1607_0x0de368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de368ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125590ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1608 | PC: 0x0de3d8 | FDE: 0x1255b0 | Size: 104 bytes [_ZN11fast_engine3Obj22HasAttrStringWithErrorEPS0_PKcPNS_6EngineE]
// Hàm FDE #1608 | Địa chỉ PC: 0x0de3d8 | Địa chỉ FDE: 0x1255b0 | Kích thước: 104 bytes
//   0x0de3d8: D100C3FF  sub      sp, sp, #0x30
//   0x0de3dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de3e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de3e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1608_0x0de3d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de3d8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1255b0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1609 | PC: 0x0de440 | FDE: 0x1255d0 | Size: 256 bytes [_ZN11fast_engine3Obj7SetAttrEPS0_S1_S1_PNS_6EngineE]
// Hàm FDE #1609 | Địa chỉ PC: 0x0de440 | Địa chỉ FDE: 0x1255d0 | Kích thước: 256 bytes
//   0x0de440: D10143FF  sub      sp, sp, #0x50
//   0x0de444: F9000BF7  str      x23, [sp, #0x10]
//   0x0de448: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0de44c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1609_0x0de440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de440ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1255d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1610 | PC: 0x0de600 | FDE: 0x1255f8 | Size: 92 bytes [_ZN11fast_engine3Obj9SetAttrIdEPS0_PNS_10IdentifierES1_PNS_6EngineE]
// Hàm FDE #1610 | Địa chỉ PC: 0x0de600 | Địa chỉ FDE: 0x1255f8 | Kích thước: 92 bytes
//   0x0de600: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0de604: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de608: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de60c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1610_0x0de600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de600ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1255f8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1611 | PC: 0x0de65c | FDE: 0x125618 | Size: 84 bytes [_ZN11fast_engine3Obj4SizeEPNS_6EngineEPS0_]
// Hàm FDE #1611 | Địa chỉ PC: 0x0de65c | Địa chỉ FDE: 0x125618 | Kích thước: 84 bytes
//   0x0de65c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0de660: 910003FD  mov      x29, sp
//   0x0de664: AA0003E8  mov      x8, x0
//   0x0de668: B4000141  cbz      x1, #0xde690
static inline uint64_t fde_func_1611_0x0de65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de65cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125618ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1612 | PC: 0x0de6b0 | FDE: 0x125638 | Size: 256 bytes [_ZN11fast_engine3Obj7GetItemEPNS_6EngineEPS0_S3_]
// Hàm FDE #1612 | Địa chỉ PC: 0x0de6b0 | Địa chỉ FDE: 0x125638 | Kích thước: 256 bytes
//   0x0de6b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0de6b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de6b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de6bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1612_0x0de6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1613 | PC: 0x0de7f4 | FDE: 0x125658 | Size: 256 bytes [_ZN11fast_engine3Obj7SetItemEPNS_6EngineEPS0_S3_S3_]
// Hàm FDE #1613 | Địa chỉ PC: 0x0de7f4 | Địa chỉ FDE: 0x125658 | Kích thước: 256 bytes
//   0x0de7f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0de7f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de7fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de800: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1613_0x0de7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de7f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1614 | PC: 0x0de950 | FDE: 0x125680 | Size: 256 bytes [_ZN11fast_engine3Obj7DelItemEPNS_6EngineEPS0_S3_]
// Hàm FDE #1614 | Địa chỉ PC: 0x0de950 | Địa chỉ FDE: 0x125680 | Kích thước: 256 bytes
//   0x0de950: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0de954: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de958: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de95c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1614_0x0de950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de950ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1615 | PC: 0x0deaa0 | FDE: 0x1256a0 | Size: 200 bytes [_ZN11fast_engine3Obj6IsTrueEPNS_6EngineEPS0_]
// Hàm FDE #1615 | Địa chỉ PC: 0x0deaa0 | Địa chỉ FDE: 0x1256a0 | Kích thước: 200 bytes
//   0x0deaa0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0deaa4: 910003FD  mov      x29, sp
//   0x0deaa8: B0000308  adrp     x8, #0x13f000
//   0x0deaac: F9464D08  ldr      x8, [x8, #0xc98]
static inline uint64_t fde_func_1615_0x0deaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0deaa0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1256a0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1616 | PC: 0x0deb68 | FDE: 0x1256c0 | Size: 24 bytes [_ZN11fast_engine3Obj20_ComputedDictPointerEPS0_]
// Hàm FDE #1616 | Địa chỉ PC: 0x0deb68 | Địa chỉ FDE: 0x1256c0 | Kích thước: 24 bytes
//   0x0deb68: F9401408  ldr      x8, [x0, #0x28]
//   0x0deb6c: F9408108  ldr      x8, [x8, #0x100]
//   0x0deb70: 8B080009  add      x9, x0, x8
//   0x0deb74: F100011F  cmp      x8, #0
static inline uint64_t fde_func_1616_0x0deb68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0deb68ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9408108ULL) ^ 0x1256c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1617 | PC: 0x0deb80 | FDE: 0x1256d8 | Size: 256 bytes [_ZN11fast_engine3Obj14GenericSetAttrEPS0_PNS_6StrObjES1_PNS_6EngineE]
// Hàm FDE #1617 | Địa chỉ PC: 0x0deb80 | Địa chỉ FDE: 0x1256d8 | Kích thước: 256 bytes
//   0x0deb80: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0deb84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0deb88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0deb8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1617_0x0deb80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0deb80ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1256d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1618 | PC: 0x0ded98 | FDE: 0x125700 | Size: 256 bytes [_ZN11fast_engine3Obj10LookupAttrEPS0_S1_PS1_PNS_6EngineE]
// Hàm FDE #1618 | Địa chỉ PC: 0x0ded98 | Địa chỉ FDE: 0x125700 | Kích thước: 256 bytes
//   0x0ded98: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ded9c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0deda0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0deda4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1618_0x0ded98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ded98ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1619 | PC: 0x0deea8 | FDE: 0x125720 | Size: 100 bytes [_ZN11fast_engine3Obj12LookupAttrIdEPS0_PNS_10IdentifierEPS1_PNS_6EngineE]
// Hàm FDE #1619 | Địa chỉ PC: 0x0deea8 | Địa chỉ FDE: 0x125720 | Kích thước: 100 bytes
//   0x0deea8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0deeac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0deeb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0deeb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1619_0x0deea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0deea8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125720ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1620 | PC: 0x0def0c | FDE: 0x125740 | Size: 100 bytes [_ZN11fast_engine3Obj10GetDictPtrEPS0_PNS_6EngineE]
// Hàm FDE #1620 | Địa chỉ PC: 0x0def0c | Địa chỉ FDE: 0x125740 | Kích thước: 100 bytes
//   0x0def0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0def10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0def14: 910043FD  add      x29, sp, #0x10
//   0x0def18: F9401409  ldr      x9, [x0, #0x28]
static inline uint64_t fde_func_1620_0x0def0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0def0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125740ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1621 | PC: 0x0def70 | FDE: 0x125760 | Size: 256 bytes [_ZN11fast_engine3Obj11RichCompareEPKS0_S2_NS_9CompareOpEPNS_6EngineE]
// Hàm FDE #1621 | Địa chỉ PC: 0x0def70 | Địa chỉ FDE: 0x125760 | Kích thước: 256 bytes
//   0x0def70: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0def74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0def78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0def7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1621_0x0def70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0def70ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1622 | PC: 0x0df0d8 | FDE: 0x125788 | Size: 252 bytes [_ZN11fast_engine3Obj15RichCompareBoolEPKS0_S2_NS_9CompareOpEPNS_6EngineE]
// Hàm FDE #1622 | Địa chỉ PC: 0x0df0d8 | Địa chỉ FDE: 0x125788 | Kích thước: 252 bytes
//   0x0df0d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df0dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df0e0: 910043FD  add      x29, sp, #0x10
//   0x0df0e4: AA0303F3  mov      x19, x3
static inline uint64_t fde_func_1622_0x0df0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df0d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125788ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1623 | PC: 0x0df1d4 | FDE: 0x1257a8 | Size: 20 bytes [_ZN11fast_engine3Obj5ClearEPNS_6EngineE]
// Hàm FDE #1623 | Địa chỉ PC: 0x0df1d4 | Địa chỉ FDE: 0x1257a8 | Kích thước: 20 bytes
//   0x0df1d4: F9401408  ldr      x8, [x0, #0x28]
//   0x0df1d8: 3942A108  ldrb     w8, [x8, #0xa8]
//   0x0df1dc: 37200048  tbnz     w8, #4, #0xdf1e4
//   0x0df1e0: D65F03C0  ret      
static inline uint64_t fde_func_1623_0x0df1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df1d4ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x3942a108ULL) ^ 0x1257a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1624 | PC: 0x0df1e8 | FDE: 0x1257c0 | Size: 8 bytes [_ZN11fast_engine3Obj9SelfCacheEPNS_6EngineE]
// Hàm FDE #1624 | Địa chỉ PC: 0x0df1e8 | Địa chỉ FDE: 0x1257c0 | Kích thước: 8 bytes
//   0x0df1e8: 2A1F03E0  mov      w0, wzr
//   0x0df1ec: D65F03C0  ret      
static inline uint64_t fde_func_1624_0x0df1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df1e8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1257c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1625 | PC: 0x0df1f0 | FDE: 0x1257d8 | Size: 28 bytes [_ZN11fast_engine3Obj4CopyEPNS_6EngineE]
// Hàm FDE #1625 | Địa chỉ PC: 0x0df1f0 | Địa chỉ FDE: 0x1257d8 | Kích thước: 28 bytes
//   0x0df1f0: B9402008  ldr      w8, [x0, #0x20]
//   0x0df1f4: 7100091F  cmp      w8, #2
//   0x0df1f8: 54000080  b.eq     #0xdf208
//   0x0df1fc: B9403808  ldr      w8, [x0, #0x38]
static inline uint64_t fde_func_1625_0x0df1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df1f0ULL ^ (static_cast<uint64_t>(0xb9402008ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x1257d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1626 | PC: 0x0df20c | FDE: 0x1257f0 | Size: 12 bytes [_ZN11fast_engine3Obj8DeepCopyEPNS_6EngineE]
// Hàm FDE #1626 | Địa chỉ PC: 0x0df20c | Địa chỉ FDE: 0x1257f0 | Kích thước: 12 bytes
//   0x0df20c: F9400008  ldr      x8, [x0]
//   0x0df210: F9401102  ldr      x2, [x8, #0x20]
//   0x0df214: D61F0040  br       x2
static inline uint64_t fde_func_1626_0x0df20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df20cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401102ULL) ^ 0x1257f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1627 | PC: 0x0df218 | FDE: 0x125808 | Size: 160 bytes [_ZNK11fast_engine3Obj8ToStringEv]
// Hàm FDE #1627 | Địa chỉ PC: 0x0df218 | Địa chỉ FDE: 0x125808 | Kích thước: 160 bytes
//   0x0df218: 90000309  adrp     x9, #0x13f000
//   0x0df21c: F944D129  ldr      x9, [x9, #0x9a0]
//   0x0df220: F9400129  ldr      x9, [x9]
//   0x0df224: EB00013F  cmp      x9, x0
static inline uint64_t fde_func_1627_0x0df218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df218ULL ^ (static_cast<uint64_t>(0x90000309ULL) << 13);
    acc = (acc + a1 + 0xf944d129ULL) ^ 0x125808ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1628 | PC: 0x0df2b8 | FDE: 0x125958 | Size: 256 bytes [_ZN11fast_engine3Obj4ReprEPS0_PNS_6EngineE]
// Hàm FDE #1628 | Địa chỉ PC: 0x0df2b8 | Địa chỉ FDE: 0x125958 | Kích thước: 256 bytes
//   0x0df2b8: D10143FF  sub      sp, sp, #0x50
//   0x0df2bc: F90013F5  str      x21, [sp, #0x20]
//   0x0df2c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0df2c4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1628_0x0df2b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df2b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x125958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1629 | PC: 0x0df498 | FDE: 0x125980 | Size: 212 bytes [_ZN11fast_engine3Obj9ReprEnterEPS0_PNS_6EngineE]
// Hàm FDE #1629 | Địa chỉ PC: 0x0df498 | Địa chỉ FDE: 0x125980 | Kích thước: 212 bytes
//   0x0df498: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0df49c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0df4a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0df4a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1629_0x0df498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df498ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125980ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1630 | PC: 0x0df56c | FDE: 0x125820 | Size: 64 bytes [_ZN11fast_engine3Obj9ReprLeaveEPS0_PNS_6EngineE]
// Hàm FDE #1630 | Địa chỉ PC: 0x0df56c | Địa chỉ FDE: 0x125820 | Kích thước: 64 bytes
//   0x0df56c: AA0003E8  mov      x8, x0
//   0x0df570: F9486C20  ldr      x0, [x1, #0x10d8]
//   0x0df574: AA0103E4  mov      x4, x1
//   0x0df578: F9402409  ldr      x9, [x0, #0x48]
static inline uint64_t fde_func_1630_0x0df56c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df56cULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9486c20ULL) ^ 0x125820ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1631 | PC: 0x0df5ac | FDE: 0x125838 | Size: 28 bytes [_ZN11fast_engine3Obj8SelfIterEPS0_PNS_6EngineE]
// Hàm FDE #1631 | Địa chỉ PC: 0x0df5ac | Địa chỉ FDE: 0x125838 | Kích thước: 28 bytes
//   0x0df5ac: B9402008  ldr      w8, [x0, #0x20]
//   0x0df5b0: 7100091F  cmp      w8, #2
//   0x0df5b4: 54000080  b.eq     #0xdf5c4
//   0x0df5b8: B9403808  ldr      w8, [x0, #0x38]
static inline uint64_t fde_func_1631_0x0df5ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df5acULL ^ (static_cast<uint64_t>(0xb9402008ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x125838ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1632 | PC: 0x0df5c8 | FDE: 0x1259a8 | Size: 256 bytes [_ZN11fast_engine3Obj7GetIterEPS0_PNS_6EngineE]
// Hàm FDE #1632 | Địa chỉ PC: 0x0df5c8 | Địa chỉ FDE: 0x1259a8 | Kích thước: 256 bytes
//   0x0df5c8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0df5cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0df5d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0df5d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1632_0x0df5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df5c8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1259a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1633 | PC: 0x0df708 | FDE: 0x125850 | Size: 80 bytes [_ZN11fast_engine3Obj18NextNotImplementedEPS0_PNS_6EngineE]
// Hàm FDE #1633 | Địa chỉ PC: 0x0df708 | Địa chỉ FDE: 0x125850 | Kích thước: 80 bytes
//   0x0df708: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0df70c: 910003FD  mov      x29, sp
//   0x0df710: F9401409  ldr      x9, [x0, #0x28]
//   0x0df714: 90000308  adrp     x8, #0x13f000
static inline uint64_t fde_func_1633_0x0df708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df708ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125850ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1634 | PC: 0x0df758 | FDE: 0x125870 | Size: 256 bytes [_ZN11fast_engine3Obj10_GetMethodEPS0_S1_PS1_PNS_6EngineE]
// Hàm FDE #1634 | Địa chỉ PC: 0x0df758 | Địa chỉ FDE: 0x125870 | Kích thước: 256 bytes
//   0x0df758: D10203FF  sub      sp, sp, #0x80
//   0x0df75c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0df760: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0df764: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1634_0x0df758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df758ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x125870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1635 | PC: 0x0dfa90 | FDE: 0x125ad8 | Size: 96 bytes [_ZN11fast_engine14AllocRangeTypeEPNS_6EngineE]
// Hàm FDE #1635 | Địa chỉ PC: 0x0dfa90 | Địa chỉ FDE: 0x125ad8 | Kích thước: 96 bytes
//   0x0dfa90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dfa94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dfa98: 910043FD  add      x29, sp, #0x10
//   0x0dfa9c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1635_0x0dfa90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfa90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125ad8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1636 | PC: 0x0dfaf0 | FDE: 0x1259d0 | Size: 92 bytes [_ZN11fast_engine13InitRangeTypeEPNS_6EngineE]
// Hàm FDE #1636 | Địa chỉ PC: 0x0dfaf0 | Địa chỉ FDE: 0x1259d0 | Kích thước: 92 bytes
//   0x0dfaf0: 90000308  adrp     x8, #0x13f000
//   0x0dfaf4: F9454D08  ldr      x8, [x8, #0xa98]
//   0x0dfaf8: 90000009  adrp     x9, #0xdf000
//   0x0dfafc: 912D3129  add      x9, x9, #0xb4c
static inline uint64_t fde_func_1636_0x0dfaf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfaf0ULL ^ (static_cast<uint64_t>(0x90000308ULL) << 13);
    acc = (acc + a1 + 0xf9454d08ULL) ^ 0x1259d0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1637 | PC: 0x0dfb4c | FDE: 0x125b00 | Size: 188 bytes
// Hàm FDE #1637 | Địa chỉ PC: 0x0dfb4c | Địa chỉ FDE: 0x125b00 | Kích thước: 188 bytes
//   0x0dfb4c: D10143FF  sub      sp, sp, #0x50
//   0x0dfb50: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0dfb54: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0dfb58: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1637_0x0dfb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfb4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x125b00ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1638 | PC: 0x0dfc08 | FDE: 0x125b30 | Size: 204 bytes
// Hàm FDE #1638 | Địa chỉ PC: 0x0dfc08 | Địa chỉ FDE: 0x125b30 | Kích thước: 204 bytes
//   0x0dfc08: D10183FF  sub      sp, sp, #0x60
//   0x0dfc0c: F90013F7  str      x23, [sp, #0x20]
//   0x0dfc10: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0dfc14: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1638_0x0dfc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfc08ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x125b30ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1639 | PC: 0x0dfcd4 | FDE: 0x1259e8 | Size: 100 bytes
// Hàm FDE #1639 | Địa chỉ PC: 0x0dfcd4 | Địa chỉ FDE: 0x1259e8 | Kích thước: 100 bytes
//   0x0dfcd4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dfcd8: 910003FD  mov      x29, sp
//   0x0dfcdc: 90000309  adrp     x9, #0x13f000
//   0x0dfce0: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1639_0x0dfcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfcd4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1259e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1640 | PC: 0x0dfd38 | FDE: 0x125b60 | Size: 204 bytes
// Hàm FDE #1640 | Địa chỉ PC: 0x0dfd38 | Địa chỉ FDE: 0x125b60 | Kích thước: 204 bytes
//   0x0dfd38: D10103FF  sub      sp, sp, #0x40
//   0x0dfd3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0dfd40: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0dfd44: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1640_0x0dfd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfd38ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x125b60ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1641 | PC: 0x0dfe04 | FDE: 0x125a08 | Size: 8 bytes
// Hàm FDE #1641 | Địa chỉ PC: 0x0dfe04 | Địa chỉ FDE: 0x125a08 | Kích thước: 8 bytes
//   0x0dfe04: F9402C00  ldr      x0, [x0, #0x58]
//   0x0dfe08: D65F03C0  ret      
static inline uint64_t fde_func_1641_0x0dfe04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfe04ULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x125a08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1642 | PC: 0x0dfe0c | FDE: 0x125b88 | Size: 172 bytes
// Hàm FDE #1642 | Địa chỉ PC: 0x0dfe0c | Địa chỉ FDE: 0x125b88 | Kích thước: 172 bytes
//   0x0dfe0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0dfe10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dfe14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dfe18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1642_0x0dfe0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfe0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125b88ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1643 | PC: 0x0dfeb8 | FDE: 0x125a20 | Size: 84 bytes [_ZN11fast_engine8RangeObjC1EPNS_6EngineE]
// Hàm FDE #1643 | Địa chỉ PC: 0x0dfeb8 | Địa chỉ FDE: 0x125a20 | Kích thước: 84 bytes
//   0x0dfeb8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dfebc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dfec0: 910043FD  add      x29, sp, #0x10
//   0x0dfec4: 90000308  adrp     x8, #0x13f000
static inline uint64_t fde_func_1643_0x0dfeb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfeb8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125a20ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1644 | PC: 0x0dff0c | FDE: 0x125bb0 | Size: 96 bytes [_ZN11fast_engine18AllocRangeIterTypeEPNS_6EngineE]
// Hàm FDE #1644 | Địa chỉ PC: 0x0dff0c | Địa chỉ FDE: 0x125bb0 | Kích thước: 96 bytes
//   0x0dff0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dff10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dff14: 910043FD  add      x29, sp, #0x10
//   0x0dff18: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1644_0x0dff0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dff0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125bb0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1645 | PC: 0x0dff6c | FDE: 0x125a40 | Size: 40 bytes [_ZN11fast_engine17InitRangeIterTypeEPNS_6EngineE]
// Hàm FDE #1645 | Địa chỉ PC: 0x0dff6c | Địa chỉ FDE: 0x125a40 | Kích thước: 40 bytes
//   0x0dff6c: 90000308  adrp     x8, #0x13f000
//   0x0dff70: F946BD08  ldr      x8, [x8, #0xd78]
//   0x0dff74: 90000009  adrp     x9, #0xdf000
//   0x0dff78: B000000A  adrp     x10, #0xe0000
static inline uint64_t fde_func_1645_0x0dff6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dff6cULL ^ (static_cast<uint64_t>(0x90000308ULL) << 13);
    acc = (acc + a1 + 0xf946bd08ULL) ^ 0x125a40ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1646 | PC: 0x0dff94 | FDE: 0x125bd8 | Size: 248 bytes
// Hàm FDE #1646 | Địa chỉ PC: 0x0dff94 | Địa chỉ FDE: 0x125bd8 | Kích thước: 248 bytes
//   0x0dff94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dff98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dff9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dffa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1646_0x0dff94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dff94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125bd8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1647 | PC: 0x0e008c | FDE: 0x125c08 | Size: 256 bytes
// Hàm FDE #1647 | Địa chỉ PC: 0x0e008c | Địa chỉ FDE: 0x125c08 | Kích thước: 256 bytes
//   0x0e008c: D10203FF  sub      sp, sp, #0x80
//   0x0e0090: F90023F7  str      x23, [sp, #0x40]
//   0x0e0094: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0e0098: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1647_0x0e008c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e008cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x125c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1648 | PC: 0x0e0344 | FDE: 0x125a58 | Size: 36 bytes [_ZN11fast_engine8RangeObjD0Ev]
// Hàm FDE #1648 | Địa chỉ PC: 0x0e0344 | Địa chỉ FDE: 0x125a58 | Kích thước: 36 bytes
//   0x0e0344: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e0348: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e034c: 910043FD  add      x29, sp, #0x10
//   0x0e0350: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1648_0x0e0344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0344ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125a58ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1649 | PC: 0x0e0368 | FDE: 0x125c38 | Size: 256 bytes
// Hàm FDE #1649 | Địa chỉ PC: 0x0e0368 | Địa chỉ FDE: 0x125c38 | Kích thước: 256 bytes
//   0x0e0368: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0e036c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e0370: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e0374: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1649_0x0e0368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0368ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x125c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1650 | PC: 0x0e07b0 | FDE: 0x125a78 | Size: 36 bytes [_ZN11fast_engine12RangeIterObjD0Ev]
// Hàm FDE #1650 | Địa chỉ PC: 0x0e07b0 | Địa chỉ FDE: 0x125a78 | Kích thước: 36 bytes
//   0x0e07b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e07b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e07b8: 910043FD  add      x29, sp, #0x10
//   0x0e07bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1650_0x0e07b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e07b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125a78ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1651 | PC: 0x0e07d4 | FDE: 0x125a98 | Size: 80 bytes [_ZN11fast_engine12RangeIterObj5ClearEPNS_6EngineE]
// Hàm FDE #1651 | Địa chỉ PC: 0x0e07d4 | Địa chỉ FDE: 0x125a98 | Kích thước: 80 bytes
//   0x0e07d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e07d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e07dc: 910043FD  add      x29, sp, #0x10
//   0x0e07e0: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1651_0x0e07d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e07d4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125a98ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1652 | PC: 0x0e0824 | FDE: 0x125ab8 | Size: 156 bytes
// Hàm FDE #1652 | Địa chỉ PC: 0x0e0824 | Địa chỉ FDE: 0x125ab8 | Kích thước: 156 bytes
//   0x0e0824: D10443FF  sub      sp, sp, #0x110
//   0x0e0828: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0e082c: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0e0830: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1652_0x0e0824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0824ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x125ab8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1653 | PC: 0x0e08c0 | FDE: 0x125c70 | Size: 256 bytes [_ZN11fast_engine7ListObj4SortEPKS0_PNS_7FuncObjEbPNS_6EngineE]
// Hàm FDE #1653 | Địa chỉ PC: 0x0e08c0 | Địa chỉ FDE: 0x125c70 | Kích thước: 256 bytes
//   0x0e08c0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e08c4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e08c8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e08cc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1653_0x0e08c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e08c0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x125c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1654 | PC: 0x0e0b14 | FDE: 0x125ca0 | Size: 56 bytes [_ZN11fast_engine11SequenceObjC2EPNS_7TypeObjEPNS_6EngineEli]
// Hàm FDE #1654 | Địa chỉ PC: 0x0e0b14 | Địa chỉ FDE: 0x125ca0 | Kích thước: 56 bytes
//   0x0e0b14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e0b18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e0b1c: 910043FD  add      x29, sp, #0x10
//   0x0e0b20: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1654_0x0e0b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0b14ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125ca0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1655 | PC: 0x0e0b4c | FDE: 0x126470 | Size: 96 bytes [_ZN11fast_engine11SequenceObjD0Ev]
// Hàm FDE #1655 | Địa chỉ PC: 0x0e0b4c | Địa chỉ FDE: 0x126470 | Kích thước: 96 bytes
//   0x0e0b4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e0b50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e0b54: 910043FD  add      x29, sp, #0x10
//   0x0e0b58: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1655_0x0e0b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0b4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126470ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1656 | PC: 0x0e0bac | FDE: 0x126498 | Size: 256 bytes [_ZN11fast_engine11SequenceObj10FastCreateEPNS_3ObjEPNS_6EngineEPKc]
// Hàm FDE #1656 | Địa chỉ PC: 0x0e0bac | Địa chỉ FDE: 0x126498 | Kích thước: 256 bytes
//   0x0e0bac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e0bb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e0bb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e0bb8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1656_0x0e0bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0bacULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1657 | PC: 0x0e0d4c | FDE: 0x1264c8 | Size: 252 bytes [_ZN11fast_engine7ListObj11GetOrCreateElPNS_6EngineE]
// Hàm FDE #1657 | Địa chỉ PC: 0x0e0d4c | Địa chỉ FDE: 0x1264c8 | Kích thước: 252 bytes
//   0x0e0d4c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e0d50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e0d54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e0d58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1657_0x0e0d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0d4cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1264c8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1658 | PC: 0x0e0e48 | FDE: 0x125cc0 | Size: 256 bytes [_ZN11fast_engine7ListObj6ExtendEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1658 | Địa chỉ PC: 0x0e0e48 | Địa chỉ FDE: 0x125cc0 | Kích thước: 256 bytes
//   0x0e0e48: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e0e4c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e0e50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e0e54: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1658_0x0e0e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0e48ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x125cc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1659 | PC: 0x0e1170 | FDE: 0x125cf0 | Size: 120 bytes [_ZN11fast_engine11SequenceObj6ResizeEPS0_lPNS_6EngineE]
// Hàm FDE #1659 | Địa chỉ PC: 0x0e1170 | Địa chỉ FDE: 0x125cf0 | Kích thước: 120 bytes
//   0x0e1170: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1174: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1178: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e117c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1659_0x0e1170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1170ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125cf0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1660 | PC: 0x0e11e8 | FDE: 0x125d10 | Size: 140 bytes [_ZN11fast_engine11SequenceObj7ContainEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1660 | Địa chỉ PC: 0x0e11e8 | Địa chỉ FDE: 0x125d10 | Kích thước: 140 bytes
//   0x0e11e8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e11ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e11f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e11f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1660_0x0e11e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e11e8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125d10ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1661 | PC: 0x0e1274 | FDE: 0x125d38 | Size: 140 bytes
// Hàm FDE #1661 | Địa chỉ PC: 0x0e1274 | Địa chỉ FDE: 0x125d38 | Kích thước: 140 bytes
//   0x0e1274: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e1278: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e127c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e1280: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1661_0x0e1274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1274ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125d38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1662 | PC: 0x0e1300 | FDE: 0x125d60 | Size: 64 bytes [_ZN11fast_engine11SequenceObj7GetItemEPS0_lPNS_6EngineE]
// Hàm FDE #1662 | Địa chỉ PC: 0x0e1300 | Địa chỉ FDE: 0x125d60 | Kích thước: 64 bytes
//   0x0e1300: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e1304: 910003FD  mov      x29, sp
//   0x0e1308: F9402408  ldr      x8, [x0, #0x48]
//   0x0e130c: B7F800E1  tbnz     x1, #0x3f, #0xe1328
static inline uint64_t fde_func_1662_0x0e1300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1300ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125d60ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1663 | PC: 0x0e1340 | FDE: 0x125d80 | Size: 68 bytes [_ZN11fast_engine11SequenceObj7SetItemEPS0_lPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1663 | Địa chỉ PC: 0x0e1340 | Địa chỉ FDE: 0x125d80 | Kích thước: 68 bytes
//   0x0e1340: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e1344: 910003FD  mov      x29, sp
//   0x0e1348: AA0203E8  mov      x8, x2
//   0x0e134c: F9402402  ldr      x2, [x0, #0x48]
static inline uint64_t fde_func_1663_0x0e1340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1340ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125d80ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1664 | PC: 0x0e1384 | FDE: 0x125da0 | Size: 224 bytes [_ZN11fast_engine11SequenceObj5ClearEPNS_6EngineE]
// Hàm FDE #1664 | Địa chỉ PC: 0x0e1384 | Địa chỉ FDE: 0x125da0 | Kích thước: 224 bytes
//   0x0e1384: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1388: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e138c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1390: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1664_0x0e1384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1384ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125da0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1665 | PC: 0x0e1464 | FDE: 0x1264f8 | Size: 192 bytes [_ZN11fast_engine8TupleObjC1ElPNS_6EngineE]
// Hàm FDE #1665 | Địa chỉ PC: 0x0e1464 | Địa chỉ FDE: 0x1264f8 | Kích thước: 192 bytes
//   0x0e1464: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1468: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e146c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1470: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1665_0x0e1464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1464ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1264f8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1666 | PC: 0x0e1524 | FDE: 0x125dc0 | Size: 160 bytes [_ZN11fast_engine8TupleObj8GetSliceEPS0_llPNS_6EngineE]
// Hàm FDE #1666 | Địa chỉ PC: 0x0e1524 | Địa chỉ FDE: 0x125dc0 | Kích thước: 160 bytes
//   0x0e1524: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1528: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e152c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1530: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1666_0x0e1524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1524ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125dc0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1667 | PC: 0x0e15c4 | FDE: 0x125de0 | Size: 132 bytes [_ZN11fast_engine8TupleObj8FromListEPNS_7ListObjEPNS_6EngineE]
// Hàm FDE #1667 | Địa chỉ PC: 0x0e15c4 | Địa chỉ FDE: 0x125de0 | Kích thước: 132 bytes
//   0x0e15c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e15c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e15cc: 910043FD  add      x29, sp, #0x10
//   0x0e15d0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1667_0x0e15c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e15c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125de0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1251: return fde_func_1251_0x0c27c4(a0, a1);
        case 1252: return fde_func_1252_0x0c2858(a0, a1);
        case 1253: return fde_func_1253_0x0c28ec(a0, a1);
        case 1254: return fde_func_1254_0x0c29b8(a0, a1);
        case 1255: return fde_func_1255_0x0c2a8c(a0, a1);
        case 1256: return fde_func_1256_0x0c2c7c(a0, a1);
        case 1257: return fde_func_1257_0x0c2f84(a0, a1);
        case 1258: return fde_func_1258_0x0c33cc(a0, a1);
        case 1259: return fde_func_1259_0x0c33e0(a0, a1);
        case 1260: return fde_func_1260_0x0c3444(a0, a1);
        case 1261: return fde_func_1261_0x0c3498(a0, a1);
        case 1262: return fde_func_1262_0x0c34f8(a0, a1);
        case 1263: return fde_func_1263_0x0c3534(a0, a1);
        case 1264: return fde_func_1264_0x0c354c(a0, a1);
        case 1265: return fde_func_1265_0x0c35f4(a0, a1);
        case 1266: return fde_func_1266_0x0c3620(a0, a1);
        case 1267: return fde_func_1267_0x0c37f4(a0, a1);
        case 1268: return fde_func_1268_0x0c3990(a0, a1);
        case 1269: return fde_func_1269_0x0c39f0(a0, a1);
        case 1270: return fde_func_1270_0x0c3a2c(a0, a1);
        case 1271: return fde_func_1271_0x0c3b58(a0, a1);
        case 1272: return fde_func_1272_0x0c3b84(a0, a1);
        case 1273: return fde_func_1273_0x0c3be4(a0, a1);
        case 1274: return fde_func_1274_0x0c3c18(a0, a1);
        case 1275: return fde_func_1275_0x0c3c44(a0, a1);
        case 1276: return fde_func_1276_0x0c3ca4(a0, a1);
        case 1277: return fde_func_1277_0x0c3d74(a0, a1);
        case 1278: return fde_func_1278_0x0c4018(a0, a1);
        case 1279: return fde_func_1279_0x0c410c(a0, a1);
        case 1280: return fde_func_1280_0x0c416c(a0, a1);
        case 1281: return fde_func_1281_0x0c423c(a0, a1);
        case 1282: return fde_func_1282_0x0c43f4(a0, a1);
        case 1283: return fde_func_1283_0x0c4454(a0, a1);
        case 1284: return fde_func_1284_0x0c4524(a0, a1);
        case 1285: return fde_func_1285_0x0c46c4(a0, a1);
        case 1286: return fde_func_1286_0x0c4718(a0, a1);
        case 1287: return fde_func_1287_0x0c4874(a0, a1);
        case 1288: return fde_func_1288_0x0c48e4(a0, a1);
        case 1289: return fde_func_1289_0x0c4abc(a0, a1);
        case 1290: return fde_func_1290_0x0c4c0c(a0, a1);
        case 1291: return fde_func_1291_0x0c4d38(a0, a1);
        case 1292: return fde_func_1292_0x0c4f28(a0, a1);
        case 1293: return fde_func_1293_0x0c6360(a0, a1);
        case 1294: return fde_func_1294_0x0c6448(a0, a1);
        case 1295: return fde_func_1295_0x0c64ec(a0, a1);
        case 1296: return fde_func_1296_0x0c6678(a0, a1);
        case 1297: return fde_func_1297_0x0c67e0(a0, a1);
        case 1298: return fde_func_1298_0x0c67ec(a0, a1);
        case 1299: return fde_func_1299_0x0c69e0(a0, a1);
        case 1300: return fde_func_1300_0x0c6bb8(a0, a1);
        case 1301: return fde_func_1301_0x0c6bbc(a0, a1);
        case 1302: return fde_func_1302_0x0c6bec(a0, a1);
        case 1303: return fde_func_1303_0x0c6c10(a0, a1);
        case 1304: return fde_func_1304_0x0c6c34(a0, a1);
        case 1305: return fde_func_1305_0x0c6dcc(a0, a1);
        case 1306: return fde_func_1306_0x0c6fe8(a0, a1);
        case 1307: return fde_func_1307_0x0c7854(a0, a1);
        case 1308: return fde_func_1308_0x0c79a4(a0, a1);
        case 1309: return fde_func_1309_0x0c7bc0(a0, a1);
        case 1310: return fde_func_1310_0x0c7cd8(a0, a1);
        case 1311: return fde_func_1311_0x0c7cfc(a0, a1);
        case 1312: return fde_func_1312_0x0c7d90(a0, a1);
        case 1313: return fde_func_1313_0x0c7ea8(a0, a1);
        case 1314: return fde_func_1314_0x0c7f08(a0, a1);
        case 1315: return fde_func_1315_0x0c7fe8(a0, a1);
        case 1316: return fde_func_1316_0x0c807c(a0, a1);
        case 1317: return fde_func_1317_0x0c81fc(a0, a1);
        case 1318: return fde_func_1318_0x0c825c(a0, a1);
        case 1319: return fde_func_1319_0x0c834c(a0, a1);
        case 1320: return fde_func_1320_0x0c83ac(a0, a1);
        case 1321: return fde_func_1321_0x0c849c(a0, a1);
        case 1322: return fde_func_1322_0x0c84fc(a0, a1);
        case 1323: return fde_func_1323_0x0c85ec(a0, a1);
        case 1324: return fde_func_1324_0x0c864c(a0, a1);
        case 1325: return fde_func_1325_0x0c873c(a0, a1);
        case 1326: return fde_func_1326_0x0c879c(a0, a1);
        case 1327: return fde_func_1327_0x0c888c(a0, a1);
        case 1328: return fde_func_1328_0x0c88ec(a0, a1);
        case 1329: return fde_func_1329_0x0c89dc(a0, a1);
        case 1330: return fde_func_1330_0x0c8a3c(a0, a1);
        case 1331: return fde_func_1331_0x0c8b2c(a0, a1);
        case 1332: return fde_func_1332_0x0c8b8c(a0, a1);
        case 1333: return fde_func_1333_0x0c8c7c(a0, a1);
        case 1334: return fde_func_1334_0x0c8cdc(a0, a1);
        case 1335: return fde_func_1335_0x0c8dcc(a0, a1);
        case 1336: return fde_func_1336_0x0c8e2c(a0, a1);
        case 1337: return fde_func_1337_0x0c8f1c(a0, a1);
        case 1338: return fde_func_1338_0x0c8f7c(a0, a1);
        case 1339: return fde_func_1339_0x0c906c(a0, a1);
        case 1340: return fde_func_1340_0x0c90cc(a0, a1);
        case 1341: return fde_func_1341_0x0c91bc(a0, a1);
        case 1342: return fde_func_1342_0x0c921c(a0, a1);
        case 1343: return fde_func_1343_0x0c930c(a0, a1);
        case 1344: return fde_func_1344_0x0c936c(a0, a1);
        case 1345: return fde_func_1345_0x0c945c(a0, a1);
        case 1346: return fde_func_1346_0x0c94bc(a0, a1);
        case 1347: return fde_func_1347_0x0c95ac(a0, a1);
        case 1348: return fde_func_1348_0x0c9610(a0, a1);
        case 1349: return fde_func_1349_0x0c9648(a0, a1);
        case 1350: return fde_func_1350_0x0ca0ec(a0, a1);
        case 1351: return fde_func_1351_0x0ca1f8(a0, a1);
        case 1352: return fde_func_1352_0x0ca384(a0, a1);
        case 1353: return fde_func_1353_0x0ca47c(a0, a1);
        case 1354: return fde_func_1354_0x0ca57c(a0, a1);
        case 1355: return fde_func_1355_0x0ca5a0(a0, a1);
        case 1356: return fde_func_1356_0x0ca600(a0, a1);
        case 1357: return fde_func_1357_0x0ca7c0(a0, a1);
        case 1358: return fde_func_1358_0x0ca7ec(a0, a1);
        case 1359: return fde_func_1359_0x0ca818(a0, a1);
        case 1360: return fde_func_1360_0x0ca824(a0, a1);
        case 1361: return fde_func_1361_0x0ca880(a0, a1);
        case 1362: return fde_func_1362_0x0ca89c(a0, a1);
        case 1363: return fde_func_1363_0x0ca8f8(a0, a1);
        case 1364: return fde_func_1364_0x0ca9e8(a0, a1);
        case 1365: return fde_func_1365_0x0caa00(a0, a1);
        case 1366: return fde_func_1366_0x0caa94(a0, a1);
        case 1367: return fde_func_1367_0x0caadc(a0, a1);
        case 1368: return fde_func_1368_0x0caae8(a0, a1);
        case 1369: return fde_func_1369_0x0cab1c(a0, a1);
        case 1370: return fde_func_1370_0x0cab20(a0, a1);
        case 1371: return fde_func_1371_0x0cab2c(a0, a1);
        case 1372: return fde_func_1372_0x0cab8c(a0, a1);
        case 1373: return fde_func_1373_0x0cac88(a0, a1);
        case 1374: return fde_func_1374_0x0cacb4(a0, a1);
        case 1375: return fde_func_1375_0x0cace8(a0, a1);
        case 1376: return fde_func_1376_0x0cacf4(a0, a1);
        case 1377: return fde_func_1377_0x0cad0c(a0, a1);
        case 1378: return fde_func_1378_0x0cad24(a0, a1);
        case 1379: return fde_func_1379_0x0cad3c(a0, a1);
        case 1380: return fde_func_1380_0x0cadd0(a0, a1);
        case 1381: return fde_func_1381_0x0cae18(a0, a1);
        case 1382: return fde_func_1382_0x0cae24(a0, a1);
        case 1383: return fde_func_1383_0x0cae58(a0, a1);
        case 1384: return fde_func_1384_0x0cae5c(a0, a1);
        case 1385: return fde_func_1385_0x0caebc(a0, a1);
        case 1386: return fde_func_1386_0x0caed8(a0, a1);
        case 1387: return fde_func_1387_0x0cb244(a0, a1);
        case 1388: return fde_func_1388_0x0cb2e4(a0, a1);
        case 1389: return fde_func_1389_0x0cb470(a0, a1);
        case 1390: return fde_func_1390_0x0cb490(a0, a1);
        case 1391: return fde_func_1391_0x0cb4e4(a0, a1);
        case 1392: return fde_func_1392_0x0cb540(a0, a1);
        case 1393: return fde_func_1393_0x0cb7e0(a0, a1);
        case 1394: return fde_func_1394_0x0cb8d4(a0, a1);
        case 1395: return fde_func_1395_0x0cba68(a0, a1);
        case 1396: return fde_func_1396_0x0cba88(a0, a1);
        case 1397: return fde_func_1397_0x0cbcd4(a0, a1);
        case 1398: return fde_func_1398_0x0cbd88(a0, a1);
        case 1399: return fde_func_1399_0x0cbe44(a0, a1);
        case 1400: return fde_func_1400_0x0cc00c(a0, a1);
        case 1401: return fde_func_1401_0x0cc1f4(a0, a1);
        case 1402: return fde_func_1402_0x0cc254(a0, a1);
        case 1403: return fde_func_1403_0x0cc2b0(a0, a1);
        case 1404: return fde_func_1404_0x0cc3ac(a0, a1);
        case 1405: return fde_func_1405_0x0cc3fc(a0, a1);
        case 1406: return fde_func_1406_0x0cc4ac(a0, a1);
        case 1407: return fde_func_1407_0x0cc5ac(a0, a1);
        case 1408: return fde_func_1408_0x0cc60c(a0, a1);
        case 1409: return fde_func_1409_0x0cc668(a0, a1);
        case 1410: return fde_func_1410_0x0cc7e0(a0, a1);
        case 1411: return fde_func_1411_0x0cc9a0(a0, a1);
        case 1412: return fde_func_1412_0x0cc9c4(a0, a1);
        case 1413: return fde_func_1413_0x0ccad0(a0, a1);
        case 1414: return fde_func_1414_0x0ccbf4(a0, a1);
        case 1415: return fde_func_1415_0x0ccc88(a0, a1);
        case 1416: return fde_func_1416_0x0ccd38(a0, a1);
        case 1417: return fde_func_1417_0x0ccd98(a0, a1);
        case 1418: return fde_func_1418_0x0ccdf0(a0, a1);
        case 1419: return fde_func_1419_0x0cce2c(a0, a1);
        case 1420: return fde_func_1420_0x0ccee0(a0, a1);
        case 1421: return fde_func_1421_0x0ccfbc(a0, a1);
        case 1422: return fde_func_1422_0x0ccfec(a0, a1);
        case 1423: return fde_func_1423_0x0cd180(a0, a1);
        case 1424: return fde_func_1424_0x0cd1e0(a0, a1);
        case 1425: return fde_func_1425_0x0cd240(a0, a1);
        case 1426: return fde_func_1426_0x0cd25c(a0, a1);
        case 1427: return fde_func_1427_0x0cd2b0(a0, a1);
        case 1428: return fde_func_1428_0x0cd398(a0, a1);
        case 1429: return fde_func_1429_0x0cd45c(a0, a1);
        case 1430: return fde_func_1430_0x0cd500(a0, a1);
        case 1431: return fde_func_1431_0x0cd764(a0, a1);
        case 1432: return fde_func_1432_0x0cd7f8(a0, a1);
        case 1433: return fde_func_1433_0x0cd858(a0, a1);
        case 1434: return fde_func_1434_0x0cd898(a0, a1);
        case 1435: return fde_func_1435_0x0cd954(a0, a1);
        case 1436: return fde_func_1436_0x0cd95c(a0, a1);
        case 1437: return fde_func_1437_0x0cdaa0(a0, a1);
        case 1438: return fde_func_1438_0x0cdb3c(a0, a1);
        case 1439: return fde_func_1439_0x0cdba4(a0, a1);
        case 1440: return fde_func_1440_0x0cdbd8(a0, a1);
        case 1441: return fde_func_1441_0x0cdbfc(a0, a1);
        case 1442: return fde_func_1442_0x0cdc20(a0, a1);
        case 1443: return fde_func_1443_0x0cdc44(a0, a1);
        case 1444: return fde_func_1444_0x0cdc68(a0, a1);
        case 1445: return fde_func_1445_0x0cdc8c(a0, a1);
        case 1446: return fde_func_1446_0x0cdf90(a0, a1);
        case 1447: return fde_func_1447_0x0ce0b8(a0, a1);
        case 1448: return fde_func_1448_0x0ce0dc(a0, a1);
        case 1449: return fde_func_1449_0x0ce178(a0, a1);
        case 1450: return fde_func_1450_0x0ce19c(a0, a1);
        case 1451: return fde_func_1451_0x0ce238(a0, a1);
        case 1452: return fde_func_1452_0x0ce298(a0, a1);
        case 1453: return fde_func_1453_0x0ce2d0(a0, a1);
        case 1454: return fde_func_1454_0x0ce4d4(a0, a1);
        case 1455: return fde_func_1455_0x0ce588(a0, a1);
        case 1456: return fde_func_1456_0x0ce65c(a0, a1);
        case 1457: return fde_func_1457_0x0ce82c(a0, a1);
        case 1458: return fde_func_1458_0x0ce850(a0, a1);
        case 1459: return fde_func_1459_0x0ce8b8(a0, a1);
        case 1460: return fde_func_1460_0x0ce90c(a0, a1);
        case 1461: return fde_func_1461_0x0ce96c(a0, a1);
        case 1462: return fde_func_1462_0x0ce998(a0, a1);
        case 1463: return fde_func_1463_0x0cea94(a0, a1);
        case 1464: return fde_func_1464_0x0ceab8(a0, a1);
        case 1465: return fde_func_1465_0x0ceb4c(a0, a1);
        case 1466: return fde_func_1466_0x0cebe4(a0, a1);
        case 1467: return fde_func_1467_0x0cf734(a0, a1);
        case 1468: return fde_func_1468_0x0cf794(a0, a1);
        case 1469: return fde_func_1469_0x0cf7d0(a0, a1);
        case 1470: return fde_func_1470_0x0cf7d4(a0, a1);
        case 1471: return fde_func_1471_0x0cf93c(a0, a1);
        case 1472: return fde_func_1472_0x0cf9d0(a0, a1);
        case 1473: return fde_func_1473_0x0cfb1c(a0, a1);
        case 1474: return fde_func_1474_0x0cfb2c(a0, a1);
        case 1475: return fde_func_1475_0x0cfd30(a0, a1);
        case 1476: return fde_func_1476_0x0cfe3c(a0, a1);
        case 1477: return fde_func_1477_0x0cfee0(a0, a1);
        case 1478: return fde_func_1478_0x0cff5c(a0, a1);
        case 1479: return fde_func_1479_0x0cff80(a0, a1);
        case 1480: return fde_func_1480_0x0cffec(a0, a1);
        case 1481: return fde_func_1481_0x0d012c(a0, a1);
        case 1482: return fde_func_1482_0x0d01b8(a0, a1);
        case 1483: return fde_func_1483_0x0d03ac(a0, a1);
        case 1484: return fde_func_1484_0x0d04f0(a0, a1);
        case 1485: return fde_func_1485_0x0d05bc(a0, a1);
        case 1486: return fde_func_1486_0x0d05f0(a0, a1);
        case 1487: return fde_func_1487_0x0d0628(a0, a1);
        case 1488: return fde_func_1488_0x0d0688(a0, a1);
        case 1489: return fde_func_1489_0x0d090c(a0, a1);
        case 1490: return fde_func_1490_0x0d0a20(a0, a1);
        case 1491: return fde_func_1491_0x0d0b44(a0, a1);
        case 1492: return fde_func_1492_0x0d0bc0(a0, a1);
        case 1493: return fde_func_1493_0x0d0c4c(a0, a1);
        case 1494: return fde_func_1494_0x0d0cc8(a0, a1);
        case 1495: return fde_func_1495_0x0d0fb4(a0, a1);
        case 1496: return fde_func_1496_0x0d112c(a0, a1);
        case 1497: return fde_func_1497_0x0d122c(a0, a1);
        case 1498: return fde_func_1498_0x0d128c(a0, a1);
        case 1499: return fde_func_1499_0x0d1e64(a0, a1);
        case 1500: return fde_func_1500_0x0d1fcc(a0, a1);
        case 1501: return fde_func_1501_0x0d2278(a0, a1);
        case 1502: return fde_func_1502_0x0d22c8(a0, a1);
        case 1503: return fde_func_1503_0x0d25a8(a0, a1);
        case 1504: return fde_func_1504_0x0d25f8(a0, a1);
        case 1505: return fde_func_1505_0x0d2850(a0, a1);
        case 1506: return fde_func_1506_0x0d2ac0(a0, a1);
        case 1507: return fde_func_1507_0x0d2bc0(a0, a1);
        case 1508: return fde_func_1508_0x0d2c2c(a0, a1);
        case 1509: return fde_func_1509_0x0d2cd8(a0, a1);
        case 1510: return fde_func_1510_0x0d2d98(a0, a1);
        case 1511: return fde_func_1511_0x0d2e34(a0, a1);
        case 1512: return fde_func_1512_0x0d2ec4(a0, a1);
        case 1513: return fde_func_1513_0x0d2f1c(a0, a1);
        case 1514: return fde_func_1514_0x0d2f7c(a0, a1);
        case 1515: return fde_func_1515_0x0d2fdc(a0, a1);
        case 1516: return fde_func_1516_0x0d307c(a0, a1);
        case 1517: return fde_func_1517_0x0d3274(a0, a1);
        case 1518: return fde_func_1518_0x0d3388(a0, a1);
        case 1519: return fde_func_1519_0x0d3540(a0, a1);
        case 1520: return fde_func_1520_0x0d3d48(a0, a1);
        case 1521: return fde_func_1521_0x0d3da4(a0, a1);
        case 1522: return fde_func_1522_0x0d3e9c(a0, a1);
        case 1523: return fde_func_1523_0x0d4328(a0, a1);
        case 1524: return fde_func_1524_0x0d4388(a0, a1);
        case 1525: return fde_func_1525_0x0d44c8(a0, a1);
        case 1526: return fde_func_1526_0x0d45d4(a0, a1);
        case 1527: return fde_func_1527_0x0d46e4(a0, a1);
        case 1528: return fde_func_1528_0x0d4af4(a0, a1);
        case 1529: return fde_func_1529_0x0d4bf4(a0, a1);
        case 1530: return fde_func_1530_0x0d4d10(a0, a1);
        case 1531: return fde_func_1531_0x0d52c4(a0, a1);
        case 1532: return fde_func_1532_0x0d5340(a0, a1);
        case 1533: return fde_func_1533_0x0d5378(a0, a1);
        case 1534: return fde_func_1534_0x0d541c(a0, a1);
        case 1535: return fde_func_1535_0x0d542c(a0, a1);
        case 1536: return fde_func_1536_0x0d554c(a0, a1);
        case 1537: return fde_func_1537_0x0d5608(a0, a1);
        case 1538: return fde_func_1538_0x0d56c4(a0, a1);
        case 1539: return fde_func_1539_0x0d56fc(a0, a1);
        case 1540: return fde_func_1540_0x0d5734(a0, a1);
        case 1541: return fde_func_1541_0x0d576c(a0, a1);
        case 1542: return fde_func_1542_0x0d5840(a0, a1);
        case 1543: return fde_func_1543_0x0d5930(a0, a1);
        case 1544: return fde_func_1544_0x0d61b8(a0, a1);
        case 1545: return fde_func_1545_0x0d64d0(a0, a1);
        case 1546: return fde_func_1546_0x0d6788(a0, a1);
        case 1547: return fde_func_1547_0x0d6fdc(a0, a1);
        case 1548: return fde_func_1548_0x0d71d8(a0, a1);
        case 1549: return fde_func_1549_0x0d728c(a0, a1);
        case 1550: return fde_func_1550_0x0d73e0(a0, a1);
        case 1551: return fde_func_1551_0x0d746c(a0, a1);
        case 1552: return fde_func_1552_0x0d74c4(a0, a1);
        case 1553: return fde_func_1553_0x0d75b4(a0, a1);
        case 1554: return fde_func_1554_0x0d793c(a0, a1);
        case 1555: return fde_func_1555_0x0d818c(a0, a1);
        case 1556: return fde_func_1556_0x0d8354(a0, a1);
        case 1557: return fde_func_1557_0x0d85d0(a0, a1);
        case 1558: return fde_func_1558_0x0d8798(a0, a1);
        case 1559: return fde_func_1559_0x0d87f8(a0, a1);
        case 1560: return fde_func_1560_0x0d88e8(a0, a1);
        case 1561: return fde_func_1561_0x0d8a7c(a0, a1);
        case 1562: return fde_func_1562_0x0d8c10(a0, a1);
        case 1563: return fde_func_1563_0x0d8da4(a0, a1);
        case 1564: return fde_func_1564_0x0d8fc4(a0, a1);
        case 1565: return fde_func_1565_0x0d92ac(a0, a1);
        case 1566: return fde_func_1566_0x0d99a0(a0, a1);
        case 1567: return fde_func_1567_0x0d9a54(a0, a1);
        case 1568: return fde_func_1568_0x0d9b40(a0, a1);
        case 1569: return fde_func_1569_0x0d9bf4(a0, a1);
        case 1570: return fde_func_1570_0x0d9c04(a0, a1);
        case 1571: return fde_func_1571_0x0d9c10(a0, a1);
        case 1572: return fde_func_1572_0x0d9e50(a0, a1);
        case 1573: return fde_func_1573_0x0da010(a0, a1);
        case 1574: return fde_func_1574_0x0da1dc(a0, a1);
        case 1575: return fde_func_1575_0x0da1e4(a0, a1);
        case 1576: return fde_func_1576_0x0da724(a0, a1);
        case 1577: return fde_func_1577_0x0da7b4(a0, a1);
        case 1578: return fde_func_1578_0x0daf18(a0, a1);
        case 1579: return fde_func_1579_0x0daf3c(a0, a1);
        case 1580: return fde_func_1580_0x0db0ec(a0, a1);
        case 1581: return fde_func_1581_0x0db3cc(a0, a1);
        case 1582: return fde_func_1582_0x0dba4c(a0, a1);
        case 1583: return fde_func_1583_0x0dbbac(a0, a1);
        case 1584: return fde_func_1584_0x0dc084(a0, a1);
        case 1585: return fde_func_1585_0x0dc160(a0, a1);
        case 1586: return fde_func_1586_0x0dc99c(a0, a1);
        case 1587: return fde_func_1587_0x0dcc68(a0, a1);
        case 1588: return fde_func_1588_0x0dcdb0(a0, a1);
        case 1589: return fde_func_1589_0x0dcf08(a0, a1);
        case 1590: return fde_func_1590_0x0dcfac(a0, a1);
        case 1591: return fde_func_1591_0x0dd054(a0, a1);
        case 1592: return fde_func_1592_0x0dd140(a0, a1);
        case 1593: return fde_func_1593_0x0dd164(a0, a1);
        case 1594: return fde_func_1594_0x0dd170(a0, a1);
        case 1595: return fde_func_1595_0x0dd254(a0, a1);
        case 1596: return fde_func_1596_0x0dd344(a0, a1);
        case 1597: return fde_func_1597_0x0dd3a4(a0, a1);
        case 1598: return fde_func_1598_0x0dd3f4(a0, a1);
        case 1599: return fde_func_1599_0x0dd4a4(a0, a1);
        case 1600: return fde_func_1600_0x0dd578(a0, a1);
        case 1601: return fde_func_1601_0x0dd5f4(a0, a1);
        case 1602: return fde_func_1602_0x0ddac8(a0, a1);
        case 1603: return fde_func_1603_0x0ddcf4(a0, a1);
        case 1604: return fde_func_1604_0x0dde68(a0, a1);
        case 1605: return fde_func_1605_0x0dde78(a0, a1);
        case 1606: return fde_func_1606_0x0de270(a0, a1);
        case 1607: return fde_func_1607_0x0de368(a0, a1);
        case 1608: return fde_func_1608_0x0de3d8(a0, a1);
        case 1609: return fde_func_1609_0x0de440(a0, a1);
        case 1610: return fde_func_1610_0x0de600(a0, a1);
        case 1611: return fde_func_1611_0x0de65c(a0, a1);
        case 1612: return fde_func_1612_0x0de6b0(a0, a1);
        case 1613: return fde_func_1613_0x0de7f4(a0, a1);
        case 1614: return fde_func_1614_0x0de950(a0, a1);
        case 1615: return fde_func_1615_0x0deaa0(a0, a1);
        case 1616: return fde_func_1616_0x0deb68(a0, a1);
        case 1617: return fde_func_1617_0x0deb80(a0, a1);
        case 1618: return fde_func_1618_0x0ded98(a0, a1);
        case 1619: return fde_func_1619_0x0deea8(a0, a1);
        case 1620: return fde_func_1620_0x0def0c(a0, a1);
        case 1621: return fde_func_1621_0x0def70(a0, a1);
        case 1622: return fde_func_1622_0x0df0d8(a0, a1);
        case 1623: return fde_func_1623_0x0df1d4(a0, a1);
        case 1624: return fde_func_1624_0x0df1e8(a0, a1);
        case 1625: return fde_func_1625_0x0df1f0(a0, a1);
        case 1626: return fde_func_1626_0x0df20c(a0, a1);
        case 1627: return fde_func_1627_0x0df218(a0, a1);
        case 1628: return fde_func_1628_0x0df2b8(a0, a1);
        case 1629: return fde_func_1629_0x0df498(a0, a1);
        case 1630: return fde_func_1630_0x0df56c(a0, a1);
        case 1631: return fde_func_1631_0x0df5ac(a0, a1);
        case 1632: return fde_func_1632_0x0df5c8(a0, a1);
        case 1633: return fde_func_1633_0x0df708(a0, a1);
        case 1634: return fde_func_1634_0x0df758(a0, a1);
        case 1635: return fde_func_1635_0x0dfa90(a0, a1);
        case 1636: return fde_func_1636_0x0dfaf0(a0, a1);
        case 1637: return fde_func_1637_0x0dfb4c(a0, a1);
        case 1638: return fde_func_1638_0x0dfc08(a0, a1);
        case 1639: return fde_func_1639_0x0dfcd4(a0, a1);
        case 1640: return fde_func_1640_0x0dfd38(a0, a1);
        case 1641: return fde_func_1641_0x0dfe04(a0, a1);
        case 1642: return fde_func_1642_0x0dfe0c(a0, a1);
        case 1643: return fde_func_1643_0x0dfeb8(a0, a1);
        case 1644: return fde_func_1644_0x0dff0c(a0, a1);
        case 1645: return fde_func_1645_0x0dff6c(a0, a1);
        case 1646: return fde_func_1646_0x0dff94(a0, a1);
        case 1647: return fde_func_1647_0x0e008c(a0, a1);
        case 1648: return fde_func_1648_0x0e0344(a0, a1);
        case 1649: return fde_func_1649_0x0e0368(a0, a1);
        case 1650: return fde_func_1650_0x0e07b0(a0, a1);
        case 1651: return fde_func_1651_0x0e07d4(a0, a1);
        case 1652: return fde_func_1652_0x0e0824(a0, a1);
        case 1653: return fde_func_1653_0x0e08c0(a0, a1);
        case 1654: return fde_func_1654_0x0e0b14(a0, a1);
        case 1655: return fde_func_1655_0x0e0b4c(a0, a1);
        case 1656: return fde_func_1656_0x0e0bac(a0, a1);
        case 1657: return fde_func_1657_0x0e0d4c(a0, a1);
        case 1658: return fde_func_1658_0x0e0e48(a0, a1);
        case 1659: return fde_func_1659_0x0e1170(a0, a1);
        case 1660: return fde_func_1660_0x0e11e8(a0, a1);
        case 1661: return fde_func_1661_0x0e1274(a0, a1);
        case 1662: return fde_func_1662_0x0e1300(a0, a1);
        case 1663: return fde_func_1663_0x0e1340(a0, a1);
        case 1664: return fde_func_1664_0x0e1384(a0, a1);
        case 1665: return fde_func_1665_0x0e1464(a0, a1);
        case 1666: return fde_func_1666_0x0e1524(a0, a1);
        case 1667: return fde_func_1667_0x0e15c4(a0, a1);
        default: return 0ULL;
    }
}

} // namespace fast_engine