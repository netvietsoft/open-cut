// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 1/5 for libpythonA.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 1/5 cho libpythonA.so
// Covers representative FDE indices [0 .. 399] out of 4,320 total FDEs
// Bao phủ chỉ số FDE đại diện [0 .. 399] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_core.h"

// FDE #0000 | PC: 0x05d8f0 | FDE: 0x1f3a48 | Size: 256 bytes
// Khung tháo gỡ #0000 | Địa chỉ PC: 0x05d8f0 | Địa chỉ FDE: 0x1f3a48 | Kích thước: 256 bytes
//   0x05d8f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05d8f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05d8f8: 910043FD  add      x29, sp, #0x10
//   0x05d8fc: D0000D13  adrp     x19, #0x1ff000
static inline uint64_t fde_func_0000_0x05d8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d8f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0001 | PC: 0x05da70 | FDE: 0x1f3ba8 | Size: 172 bytes
// Khung tháo gỡ #0001 | Địa chỉ PC: 0x05da70 | Địa chỉ FDE: 0x1f3ba8 | Kích thước: 172 bytes
//   0x05da70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05da74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05da78: 910043FD  add      x29, sp, #0x10
//   0x05da7c: D0000D00  adrp     x0, #0x1ff000
static inline uint64_t fde_func_0001_0x05da70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05da70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3ba8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0002 | PC: 0x05db1c | FDE: 0x1d1c78 | Size: 224 bytes [PyToken_OneChar]
// Khung tháo gỡ #0002 | Địa chỉ PC: 0x05db1c | Địa chỉ FDE: 0x1d1c78 | Kích thước: 224 bytes
//   0x05db1c: 51009408  sub      w8, w0, #0x25
//   0x05db20: 7101651F  cmp      w8, #0x59
//   0x05db24: 54000148  b.hi     #0x5db4c
//   0x05db28: B0000A29  adrp     x9, #0x1a2000
static inline uint64_t fde_func_0002_0x05db1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05db1cULL ^ (static_cast<uint64_t>(0x51009408ULL) << 13);
    acc = (acc + a1 + 0x7101651fULL) ^ 0x1d1c78ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0003 | PC: 0x05dbfc | FDE: 0x1d1c90 | Size: 256 bytes [PyToken_TwoChars]
// Khung tháo gỡ #0003 | Địa chỉ PC: 0x05dbfc | Địa chỉ FDE: 0x1d1c90 | Kích thước: 256 bytes
//   0x05dbfc: 51008408  sub      w8, w0, #0x21
//   0x05dc00: 71016D1F  cmp      w8, #0x5b
//   0x05dc04: 54000A28  b.hi     #0x5dd48
//   0x05dc08: B0000A29  adrp     x9, #0x1a2000
static inline uint64_t fde_func_0003_0x05dbfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dbfcULL ^ (static_cast<uint64_t>(0x51008408ULL) << 13);
    acc = (acc + a1 + 0x71016d1fULL) ^ 0x1d1c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0004 | PC: 0x05dd50 | FDE: 0x1d1ca8 | Size: 164 bytes [PyToken_ThreeChars]
// Khung tháo gỡ #0004 | Địa chỉ PC: 0x05dd50 | Địa chỉ FDE: 0x1d1ca8 | Kích thước: 164 bytes
//   0x05dd50: 5100A808  sub      w8, w0, #0x2a
//   0x05dd54: 7100511F  cmp      w8, #0x14
//   0x05dd58: 540004A8  b.hi     #0x5ddec
//   0x05dd5c: B0000A29  adrp     x9, #0x1a2000
static inline uint64_t fde_func_0004_0x05dd50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dd50ULL ^ (static_cast<uint64_t>(0x5100a808ULL) << 13);
    acc = (acc + a1 + 0x7100511fULL) ^ 0x1d1ca8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0005 | PC: 0x05ddf4 | FDE: 0x1d1cc0 | Size: 256 bytes [PyOS_StdioReadline]
// Khung tháo gỡ #0005 | Địa chỉ PC: 0x05ddf4 | Địa chỉ FDE: 0x1d1cc0 | Kích thước: 256 bytes
//   0x05ddf4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05ddf8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05ddfc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05de00: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0005_0x05ddf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ddf4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d1cc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0006 | PC: 0x05dfb0 | FDE: 0x1d1cf0 | Size: 256 bytes [PyOS_Readline]
// Khung tháo gỡ #0006 | Địa chỉ PC: 0x05dfb0 | Địa chỉ FDE: 0x1d1cf0 | Kích thước: 256 bytes
//   0x05dfb0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x05dfb4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x05dfb8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05dfbc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0006_0x05dfb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dfb0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d1cf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0007 | PC: 0x05e130 | FDE: 0x1d1d18 | Size: 48 bytes [PyObject_Type]
// Khung tháo gỡ #0007 | Địa chỉ PC: 0x05e130 | Địa chỉ FDE: 0x1d1d18 | Kích thước: 48 bytes
//   0x05e130: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05e134: 910003FD  mov      x29, sp
//   0x05e138: B40000C0  cbz      x0, #0x5e150
//   0x05e13c: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_0007_0x05e130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e130ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d1d18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0008 | PC: 0x05e160 | FDE: 0x1d1d38 | Size: 56 bytes
// Khung tháo gỡ #0008 | Địa chỉ PC: 0x05e160 | Địa chỉ FDE: 0x1d1d38 | Kích thước: 56 bytes
//   0x05e160: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05e164: 910003FD  mov      x29, sp
//   0x05e168: 97FFED96  bl       #0x597c0
//   0x05e16c: F9402C08  ldr      x8, [x0, #0x58]
static inline uint64_t fde_func_0008_0x05e160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e160ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d1d38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0009 | PC: 0x05e198 | FDE: 0x1d1d58 | Size: 64 bytes [PyObject_Size]
// Khung tháo gỡ #0009 | Địa chỉ PC: 0x05e198 | Địa chỉ FDE: 0x1d1d58 | Kích thước: 64 bytes
//   0x05e198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05e19c: 910003FD  mov      x29, sp
//   0x05e1a0: B4000100  cbz      x0, #0x5e1c0
//   0x05e1a4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0009_0x05e198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d1d58ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0010 | PC: 0x05e1d8 | FDE: 0x1d1d78 | Size: 128 bytes [PyMapping_Size]
// Khung tháo gỡ #0010 | Địa chỉ PC: 0x05e1d8 | Địa chỉ FDE: 0x1d1d78 | Kích thước: 128 bytes
//   0x05e1d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05e1dc: 910003FD  mov      x29, sp
//   0x05e1e0: B4000100  cbz      x0, #0x5e200
//   0x05e1e4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0010_0x05e1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e1d8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d1d78ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0011 | PC: 0x05e258 | FDE: 0x1d1d98 | Size: 4 bytes [PyObject_Length]
// Khung tháo gỡ #0011 | Địa chỉ PC: 0x05e258 | Địa chỉ FDE: 0x1d1d98 | Kích thước: 4 bytes
//   0x05e258: 17FFF4DE  b        #0x5b5d0
static inline uint64_t fde_func_0011_0x05e258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e258ULL ^ (static_cast<uint64_t>(0x17fff4deULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1d1d98ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0012 | PC: 0x05e25c | FDE: 0x1d1db0 | Size: 60 bytes [_PyObject_HasLen]
// Khung tháo gỡ #0012 | Địa chỉ PC: 0x05e25c | Địa chỉ FDE: 0x1d1db0 | Kích thước: 60 bytes
//   0x05e25c: F9400408  ldr      x8, [x0, #8]
//   0x05e260: F9403509  ldr      x9, [x8, #0x68]
//   0x05e264: B40000A9  cbz      x9, #0x5e278
//   0x05e268: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_0012_0x05e25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e25cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9403509ULL) ^ 0x1d1db0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0013 | PC: 0x05e298 | FDE: 0x1d1dc8 | Size: 256 bytes [PyObject_LengthHint]
// Khung tháo gỡ #0013 | Địa chỉ PC: 0x05e298 | Địa chỉ FDE: 0x1d1dc8 | Kích thước: 256 bytes
//   0x05e298: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e29c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e2a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e2a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0013_0x05e298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e298ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d1dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0014 | PC: 0x05e4a8 | FDE: 0x1d1df0 | Size: 256 bytes [PyObject_GetItem]
// Khung tháo gỡ #0014 | Địa chỉ PC: 0x05e4a8 | Địa chỉ FDE: 0x1d1df0 | Kích thước: 256 bytes
//   0x05e4a8: D10143FF  sub      sp, sp, #0x50
//   0x05e4ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05e4b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05e4b4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0014_0x05e4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e4a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d1df0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0015 | PC: 0x05e6c0 | FDE: 0x1d1e18 | Size: 208 bytes [PyNumber_AsSsize_t]
// Khung tháo gỡ #0015 | Địa chỉ PC: 0x05e6c0 | Địa chỉ FDE: 0x1d1e18 | Kích thước: 208 bytes
//   0x05e6c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e6c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e6c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e6cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0015_0x05e6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e6c0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d1e18ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0016 | PC: 0x05e790 | FDE: 0x1d1e40 | Size: 200 bytes [PySequence_GetItem]
// Khung tháo gỡ #0016 | Địa chỉ PC: 0x05e790 | Địa chỉ FDE: 0x1d1e40 | Kích thước: 200 bytes
//   0x05e790: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05e794: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e798: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e79c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0016_0x05e790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e790ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d1e40ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0017 | PC: 0x05e858 | FDE: 0x1d1e60 | Size: 256 bytes [PyObject_SetItem]
// Khung tháo gỡ #0017 | Địa chỉ PC: 0x05e858 | Địa chỉ FDE: 0x1d1e60 | Kích thước: 256 bytes
//   0x05e858: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05e85c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e860: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e864: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0017_0x05e858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e858ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d1e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0018 | PC: 0x05e96c | FDE: 0x1d1e80 | Size: 208 bytes [PySequence_SetItem]
// Khung tháo gỡ #0018 | Địa chỉ PC: 0x05e96c | Địa chỉ FDE: 0x1d1e80 | Kích thước: 208 bytes
//   0x05e96c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e970: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e974: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e978: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0018_0x05e96c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e96cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d1e80ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0019 | PC: 0x05ea3c | FDE: 0x1d1ea8 | Size: 244 bytes [PyObject_DelItem]
// Khung tháo gỡ #0019 | Địa chỉ PC: 0x05ea3c | Địa chỉ FDE: 0x1d1ea8 | Kích thước: 244 bytes
//   0x05ea3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05ea40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05ea44: 910043FD  add      x29, sp, #0x10
//   0x05ea48: B40001A0  cbz      x0, #0x5ea7c
static inline uint64_t fde_func_0019_0x05ea3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ea3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d1ea8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0020 | PC: 0x05eb30 | FDE: 0x1d1ec8 | Size: 204 bytes [PySequence_DelItem]
// Khung tháo gỡ #0020 | Địa chỉ PC: 0x05eb30 | Địa chỉ FDE: 0x1d1ec8 | Kích thước: 204 bytes
//   0x05eb30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05eb34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05eb38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05eb3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0020_0x05eb30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05eb30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d1ec8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0021 | PC: 0x05ebfc | FDE: 0x1d1ee8 | Size: 108 bytes [PyObject_DelItemString]
// Khung tháo gỡ #0021 | Địa chỉ PC: 0x05ebfc | Địa chỉ FDE: 0x1d1ee8 | Kích thước: 108 bytes
//   0x05ebfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05ec00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05ec04: 910043FD  add      x29, sp, #0x10
//   0x05ec08: B4000240  cbz      x0, #0x5ec50
static inline uint64_t fde_func_0021_0x05ebfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ebfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d1ee8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0022 | PC: 0x05ec68 | FDE: 0x1d1f08 | Size: 36 bytes [PyObject_CheckBuffer]
// Khung tháo gỡ #0022 | Địa chỉ PC: 0x05ec68 | Địa chỉ FDE: 0x1d1f08 | Kích thước: 36 bytes
//   0x05ec68: F9400408  ldr      x8, [x0, #8]
//   0x05ec6c: F9405108  ldr      x8, [x8, #0xa0]
//   0x05ec70: B40000A8  cbz      x8, #0x5ec84
//   0x05ec74: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0022_0x05ec68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ec68ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9405108ULL) ^ 0x1d1f08ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0023 | PC: 0x05ec8c | FDE: 0x1d1f20 | Size: 128 bytes [PyObject_CheckReadBuffer]
// Khung tháo gỡ #0023 | Địa chỉ PC: 0x05ec8c | Địa chỉ FDE: 0x1d1f20 | Kích thước: 128 bytes
//   0x05ec8c: D10203FF  sub      sp, sp, #0x80
//   0x05ec90: F90033F3  str      x19, [sp, #0x60]
//   0x05ec94: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x05ec98: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_0023_0x05ec8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ec8cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f3ULL) ^ 0x1d1f20ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0024 | PC: 0x05ed0c | FDE: 0x1d1f40 | Size: 104 bytes [PyBuffer_Release]
// Khung tháo gỡ #0024 | Địa chỉ PC: 0x05ed0c | Địa chỉ FDE: 0x1d1f40 | Kích thước: 104 bytes
//   0x05ed0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05ed10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05ed14: 910043FD  add      x29, sp, #0x10
//   0x05ed18: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0024_0x05ed0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ed0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d1f40ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0025 | PC: 0x05ed74 | FDE: 0x1d1f60 | Size: 4 bytes [PyObject_AsCharBuffer]
// Khung tháo gỡ #0025 | Địa chỉ PC: 0x05ed74 | Địa chỉ FDE: 0x1d1f60 | Kích thước: 4 bytes
//   0x05ed74: 14000001  b        #0x5ed78
static inline uint64_t fde_func_0025_0x05ed74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ed74ULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xd10243ffULL) ^ 0x1d1f60ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0026 | PC: 0x05ed78 | FDE: 0x1d1f78 | Size: 148 bytes
// Khung tháo gỡ #0026 | Địa chỉ PC: 0x05ed78 | Địa chỉ FDE: 0x1d1f78 | Kích thước: 148 bytes
//   0x05ed78: D10243FF  sub      sp, sp, #0x90
//   0x05ed7c: F90033F5  str      x21, [sp, #0x60]
//   0x05ed80: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x05ed84: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0026_0x05ed78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ed78ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1d1f78ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0027 | PC: 0x05ee0c | FDE: 0x1d1f98 | Size: 4 bytes [PyObject_AsReadBuffer]
// Khung tháo gỡ #0027 | Địa chỉ PC: 0x05ee0c | Địa chỉ FDE: 0x1d1f98 | Kích thước: 4 bytes
//   0x05ee0c: 17FFFFDB  b        #0x5ed78
static inline uint64_t fde_func_0027_0x05ee0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ee0cULL ^ (static_cast<uint64_t>(0x17ffffdbULL) << 13);
    acc = (acc + a1 + 0xd10243ffULL) ^ 0x1d1f98ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0028 | PC: 0x05ee10 | FDE: 0x1d1fb0 | Size: 196 bytes [PyObject_AsWriteBuffer]
// Khung tháo gỡ #0028 | Địa chỉ PC: 0x05ee10 | Địa chỉ FDE: 0x1d1fb0 | Kích thước: 196 bytes
//   0x05ee10: D10243FF  sub      sp, sp, #0x90
//   0x05ee14: F90033F5  str      x21, [sp, #0x60]
//   0x05ee18: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x05ee1c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0028_0x05ee10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ee10ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1d1fb0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0029 | PC: 0x05eed4 | FDE: 0x1d1fd0 | Size: 76 bytes [PyObject_GetBuffer]
// Khung tháo gỡ #0029 | Địa chỉ PC: 0x05eed4 | Địa chỉ FDE: 0x1d1fd0 | Kích thước: 76 bytes
//   0x05eed4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05eed8: 910003FD  mov      x29, sp
//   0x05eedc: F9400408  ldr      x8, [x0, #8]
//   0x05eee0: F9405109  ldr      x9, [x8, #0xa0]
static inline uint64_t fde_func_0029_0x05eed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05eed4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d1fd0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0030 | PC: 0x05ef20 | FDE: 0x1d1ff0 | Size: 140 bytes [PyBuffer_IsContiguous]
// Khung tháo gỡ #0030 | Địa chỉ PC: 0x05ef20 | Địa chỉ FDE: 0x1d1ff0 | Kích thước: 140 bytes
//   0x05ef20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05ef24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05ef28: 910043FD  add      x29, sp, #0x10
//   0x05ef2c: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_0030_0x05ef20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ef20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d1ff0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0031 | PC: 0x05efac | FDE: 0x1d2010 | Size: 92 bytes
// Khung tháo gỡ #0031 | Địa chỉ PC: 0x05efac | Địa chỉ FDE: 0x1d2010 | Kích thước: 92 bytes
//   0x05efac: F9400808  ldr      x8, [x0, #0x10]
//   0x05efb0: B4000248  cbz      x8, #0x5eff8
//   0x05efb4: F9401C08  ldr      x8, [x0, #0x38]
//   0x05efb8: B4000208  cbz      x8, #0x5eff8
static inline uint64_t fde_func_0031_0x05efac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05efacULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb4000248ULL) ^ 0x1d2010ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0032 | PC: 0x05f008 | FDE: 0x1d2028 | Size: 152 bytes
// Khung tháo gỡ #0032 | Địa chỉ PC: 0x05f008 | Địa chỉ FDE: 0x1d2028 | Kích thước: 152 bytes
//   0x05f008: F9400808  ldr      x8, [x0, #0x10]
//   0x05f00c: B40002E8  cbz      x8, #0x5f068
//   0x05f010: B940240A  ldr      w10, [x0, #0x24]
//   0x05f014: F9401C09  ldr      x9, [x0, #0x38]
static inline uint64_t fde_func_0032_0x05f008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f008ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb40002e8ULL) ^ 0x1d2028ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0033 | PC: 0x05f0a0 | FDE: 0x1d2040 | Size: 80 bytes [PyBuffer_GetPointer]
// Khung tháo gỡ #0033 | Địa chỉ PC: 0x05f0a0 | Địa chỉ FDE: 0x1d2040 | Kích thước: 80 bytes
//   0x05f0a0: B9802409  ldrsw    x9, [x0, #0x24]
//   0x05f0a4: AA0003E8  mov      x8, x0
//   0x05f0a8: F9400000  ldr      x0, [x0]
//   0x05f0ac: 7100053F  cmp      w9, #1
static inline uint64_t fde_func_0033_0x05f0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f0a0ULL ^ (static_cast<uint64_t>(0xb9802409ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d2040ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0034 | PC: 0x05f0f0 | FDE: 0x1d2058 | Size: 64 bytes [_Py_add_one_to_index_F]
// Khung tháo gỡ #0034 | Địa chỉ PC: 0x05f0f0 | Địa chỉ FDE: 0x1d2058 | Kích thước: 64 bytes
//   0x05f0f0: 7100041F  cmp      w0, #1
//   0x05f0f4: 5400016B  b.lt     #0x5f120
//   0x05f0f8: 2A0003E8  mov      w8, w0
//   0x05f0fc: F940004A  ldr      x10, [x2]
static inline uint64_t fde_func_0034_0x05f0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f0f0ULL ^ (static_cast<uint64_t>(0x7100041fULL) << 13);
    acc = (acc + a1 + 0x5400016bULL) ^ 0x1d2058ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0035 | PC: 0x05f130 | FDE: 0x1d2070 | Size: 60 bytes [_Py_add_one_to_index_C]
// Khung tháo gỡ #0035 | Địa chỉ PC: 0x05f130 | Địa chỉ FDE: 0x1d2070 | Kích thước: 60 bytes
//   0x05f130: 71000408  subs     w8, w0, #1
//   0x05f134: 54000144  b.mi     #0x5f15c
//   0x05f138: F868D849  ldr      x9, [x2, w8, sxtw #3]
//   0x05f13c: F868D82A  ldr      x10, [x1, w8, sxtw #3]
static inline uint64_t fde_func_0035_0x05f130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f130ULL ^ (static_cast<uint64_t>(0x71000408ULL) << 13);
    acc = (acc + a1 + 0x54000144ULL) ^ 0x1d2070ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0036 | PC: 0x05f16c | FDE: 0x1d2088 | Size: 256 bytes [PyBuffer_SizeFromFormat]
// Khung tháo gỡ #0036 | Địa chỉ PC: 0x05f16c | Địa chỉ FDE: 0x1d2088 | Kích thước: 256 bytes
//   0x05f16c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05f170: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05f174: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05f178: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0036_0x05f16c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f16cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0037 | PC: 0x05f284 | FDE: 0x1d20b0 | Size: 256 bytes [PyBuffer_FromContiguous]
// Khung tháo gỡ #0037 | Địa chỉ PC: 0x05f284 | Địa chỉ FDE: 0x1d20b0 | Kích thước: 256 bytes
//   0x05f284: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x05f288: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x05f28c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05f290: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0037_0x05f284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f284ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d20b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0038 | PC: 0x05f3a0 | FDE: 0x1d20d8 | Size: 256 bytes [PyObject_CopyData]
// Khung tháo gỡ #0038 | Địa chỉ PC: 0x05f3a0 | Địa chỉ FDE: 0x1d20d8 | Kích thước: 256 bytes
//   0x05f3a0: D10383FF  sub      sp, sp, #0xe0
//   0x05f3a4: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x05f3a8: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x05f3ac: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0038_0x05f3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f3a0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b57f6ULL) ^ 0x1d20d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0039 | PC: 0x05f668 | FDE: 0x1d2100 | Size: 96 bytes [PyBuffer_FillContiguousStrides]
// Khung tháo gỡ #0039 | Địa chỉ PC: 0x05f668 | Địa chỉ FDE: 0x1d2100 | Kích thước: 96 bytes
//   0x05f668: 12001C88  and      w8, w4, #0xff
//   0x05f66c: 7101191F  cmp      w8, #0x46
//   0x05f670: 93407C68  sxtw     x8, w3
//   0x05f674: 54000141  b.ne     #0x5f69c
static inline uint64_t fde_func_0039_0x05f668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f668ULL ^ (static_cast<uint64_t>(0x12001c88ULL) << 13);
    acc = (acc + a1 + 0x7101191fULL) ^ 0x1d2100ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0040 | PC: 0x05f6c8 | FDE: 0x1d2118 | Size: 188 bytes [PyBuffer_FillInfo]
// Khung tháo gỡ #0040 | Địa chỉ PC: 0x05f6c8 | Địa chỉ FDE: 0x1d2118 | Kích thước: 188 bytes
//   0x05f6c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05f6cc: 910003FD  mov      x29, sp
//   0x05f6d0: B4000120  cbz      x0, #0x5f6f4
//   0x05f6d4: 7100049F  cmp      w4, #1
static inline uint64_t fde_func_0040_0x05f6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f6c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2118ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0041 | PC: 0x05f784 | FDE: 0x1d2138 | Size: 256 bytes [PyObject_Format]
// Khung tháo gỡ #0041 | Địa chỉ PC: 0x05f784 | Địa chỉ FDE: 0x1d2138 | Kích thước: 256 bytes
//   0x05f784: D10183FF  sub      sp, sp, #0x60
//   0x05f788: F90013F7  str      x23, [sp, #0x20]
//   0x05f78c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05f790: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0041_0x05f784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f784ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1d2138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0042 | PC: 0x05f9c0 | FDE: 0x1d2160 | Size: 116 bytes [PyNumber_Check]
// Khung tháo gỡ #0042 | Địa chỉ PC: 0x05f9c0 | Địa chỉ FDE: 0x1d2160 | Kích thước: 116 bytes
//   0x05f9c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05f9c4: 910003FD  mov      x29, sp
//   0x05f9c8: B4000160  cbz      x0, #0x5f9f4
//   0x05f9cc: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0042_0x05f9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f9c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2160ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0043 | PC: 0x05fa34 | FDE: 0x1d2180 | Size: 16 bytes [PyNumber_Or]
// Khung tháo gỡ #0043 | Địa chỉ PC: 0x05fa34 | Địa chỉ FDE: 0x1d2180 | Kích thước: 16 bytes
//   0x05fa34: F0000A03  adrp     x3, #0x1a2000
//   0x05fa38: 9119E463  add      x3, x3, #0x679
//   0x05fa3c: 52800F02  mov      w2, #0x78
//   0x05fa40: 14000001  b        #0x5fa44
static inline uint64_t fde_func_0043_0x05fa34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fa34ULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0x9119e463ULL) ^ 0x1d2180ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0044 | PC: 0x05fa44 | FDE: 0x1d2198 | Size: 248 bytes
// Khung tháo gỡ #0044 | Địa chỉ PC: 0x05fa44 | Địa chỉ FDE: 0x1d2198 | Kích thước: 248 bytes
//   0x05fa44: D10103FF  sub      sp, sp, #0x40
//   0x05fa48: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05fa4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05fa50: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0044_0x05fa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fa44ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2198ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0045 | PC: 0x05fb3c | FDE: 0x1d21c0 | Size: 16 bytes [PyNumber_Xor]
// Khung tháo gỡ #0045 | Địa chỉ PC: 0x05fb3c | Địa chỉ FDE: 0x1d21c0 | Kích thước: 16 bytes
//   0x05fb3c: F0000A03  adrp     x3, #0x1a2000
//   0x05fb40: 9119EC63  add      x3, x3, #0x67b
//   0x05fb44: 52800E02  mov      w2, #0x70
//   0x05fb48: 17FFFFBF  b        #0x5fa44
static inline uint64_t fde_func_0045_0x05fb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb3cULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0x9119ec63ULL) ^ 0x1d21c0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0046 | PC: 0x05fb4c | FDE: 0x1d21d8 | Size: 16 bytes [PyNumber_And]
// Khung tháo gỡ #0046 | Địa chỉ PC: 0x05fb4c | Địa chỉ FDE: 0x1d21d8 | Kích thước: 16 bytes
//   0x05fb4c: F0000A03  adrp     x3, #0x1a2000
//   0x05fb50: 9119F463  add      x3, x3, #0x67d
//   0x05fb54: 52800D02  mov      w2, #0x68
//   0x05fb58: 17FFFFBB  b        #0x5fa44
static inline uint64_t fde_func_0046_0x05fb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb4cULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0x9119f463ULL) ^ 0x1d21d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0047 | PC: 0x05fb5c | FDE: 0x1d21f0 | Size: 16 bytes [PyNumber_Lshift]
// Khung tháo gỡ #0047 | Địa chỉ PC: 0x05fb5c | Địa chỉ FDE: 0x1d21f0 | Kích thước: 16 bytes
//   0x05fb5c: F0000A03  adrp     x3, #0x1a2000
//   0x05fb60: 9119FC63  add      x3, x3, #0x67f
//   0x05fb64: 52800B02  mov      w2, #0x58
//   0x05fb68: 17FFFFB7  b        #0x5fa44
static inline uint64_t fde_func_0047_0x05fb5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb5cULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0x9119fc63ULL) ^ 0x1d21f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0048 | PC: 0x05fb6c | FDE: 0x1d2208 | Size: 16 bytes [PyNumber_Rshift]
// Khung tháo gỡ #0048 | Địa chỉ PC: 0x05fb6c | Địa chỉ FDE: 0x1d2208 | Kích thước: 16 bytes
//   0x05fb6c: B0000A63  adrp     x3, #0x1ac000
//   0x05fb70: 913A1863  add      x3, x3, #0xe86
//   0x05fb74: 52800C02  mov      w2, #0x60
//   0x05fb78: 17FFFFB3  b        #0x5fa44
static inline uint64_t fde_func_0048_0x05fb6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb6cULL ^ (static_cast<uint64_t>(0xb0000a63ULL) << 13);
    acc = (acc + a1 + 0x913a1863ULL) ^ 0x1d2208ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0049 | PC: 0x05fb7c | FDE: 0x1d2220 | Size: 16 bytes [PyNumber_Subtract]
// Khung tháo gỡ #0049 | Địa chỉ PC: 0x05fb7c | Địa chỉ FDE: 0x1d2220 | Kích thước: 16 bytes
//   0x05fb7c: F0000AA3  adrp     x3, #0x1b6000
//   0x05fb80: 9121E863  add      x3, x3, #0x87a
//   0x05fb84: 52800102  mov      w2, #8
//   0x05fb88: 17FFFFAF  b        #0x5fa44
static inline uint64_t fde_func_0049_0x05fb7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb7cULL ^ (static_cast<uint64_t>(0xf0000aa3ULL) << 13);
    acc = (acc + a1 + 0x9121e863ULL) ^ 0x1d2220ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0050 | PC: 0x05fb8c | FDE: 0x1d2238 | Size: 16 bytes [PyNumber_Divmod]
// Khung tháo gỡ #0050 | Địa chỉ PC: 0x05fb8c | Địa chỉ FDE: 0x1d2238 | Kích thước: 16 bytes
//   0x05fb8c: F0000A23  adrp     x3, #0x1a6000
//   0x05fb90: 912AEC63  add      x3, x3, #0xabb
//   0x05fb94: 52800402  mov      w2, #0x20
//   0x05fb98: 17FFFFAB  b        #0x5fa44
static inline uint64_t fde_func_0050_0x05fb8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb8cULL ^ (static_cast<uint64_t>(0xf0000a23ULL) << 13);
    acc = (acc + a1 + 0x912aec63ULL) ^ 0x1d2238ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0051 | PC: 0x05fb9c | FDE: 0x1d2250 | Size: 20 bytes [Drogon_PyNumber_Or]
// Khung tháo gỡ #0051 | Địa chỉ PC: 0x05fb9c | Địa chỉ FDE: 0x1d2250 | Kích thước: 20 bytes
//   0x05fb9c: F0000A03  adrp     x3, #0x1a2000
//   0x05fba0: AA0203E4  mov      x4, x2
//   0x05fba4: 9119E463  add      x3, x3, #0x679
//   0x05fba8: 52800F02  mov      w2, #0x78
static inline uint64_t fde_func_0051_0x05fb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb9cULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d2250ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0052 | PC: 0x05fbb0 | FDE: 0x1d2268 | Size: 240 bytes
// Khung tháo gỡ #0052 | Địa chỉ PC: 0x05fbb0 | Địa chỉ FDE: 0x1d2268 | Kích thước: 240 bytes
//   0x05fbb0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05fbb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05fbb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05fbbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0052_0x05fbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fbb0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2268ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0053 | PC: 0x05fca0 | FDE: 0x1d2290 | Size: 20 bytes [Drogon_PyNumber_Xor]
// Khung tháo gỡ #0053 | Địa chỉ PC: 0x05fca0 | Địa chỉ FDE: 0x1d2290 | Kích thước: 20 bytes
//   0x05fca0: F0000A03  adrp     x3, #0x1a2000
//   0x05fca4: AA0203E4  mov      x4, x2
//   0x05fca8: 9119EC63  add      x3, x3, #0x67b
//   0x05fcac: 52800E02  mov      w2, #0x70
static inline uint64_t fde_func_0053_0x05fca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fca0ULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d2290ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0054 | PC: 0x05fcb4 | FDE: 0x1d22a8 | Size: 20 bytes [Drogon_PyNumber_And]
// Khung tháo gỡ #0054 | Địa chỉ PC: 0x05fcb4 | Địa chỉ FDE: 0x1d22a8 | Kích thước: 20 bytes
//   0x05fcb4: F0000A03  adrp     x3, #0x1a2000
//   0x05fcb8: AA0203E4  mov      x4, x2
//   0x05fcbc: 9119F463  add      x3, x3, #0x67d
//   0x05fcc0: 52800D02  mov      w2, #0x68
static inline uint64_t fde_func_0054_0x05fcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fcb4ULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d22a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0055 | PC: 0x05fcc8 | FDE: 0x1d22c0 | Size: 20 bytes [Drogon_PyNumber_Lshift]
// Khung tháo gỡ #0055 | Địa chỉ PC: 0x05fcc8 | Địa chỉ FDE: 0x1d22c0 | Kích thước: 20 bytes
//   0x05fcc8: F0000A03  adrp     x3, #0x1a2000
//   0x05fccc: AA0203E4  mov      x4, x2
//   0x05fcd0: 9119FC63  add      x3, x3, #0x67f
//   0x05fcd4: 52800B02  mov      w2, #0x58
static inline uint64_t fde_func_0055_0x05fcc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fcc8ULL ^ (static_cast<uint64_t>(0xf0000a03ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d22c0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0056 | PC: 0x05fcdc | FDE: 0x1d22d8 | Size: 20 bytes [Drogon_PyNumber_Rshift]
// Khung tháo gỡ #0056 | Địa chỉ PC: 0x05fcdc | Địa chỉ FDE: 0x1d22d8 | Kích thước: 20 bytes
//   0x05fcdc: B0000A63  adrp     x3, #0x1ac000
//   0x05fce0: AA0203E4  mov      x4, x2
//   0x05fce4: 913A1863  add      x3, x3, #0xe86
//   0x05fce8: 52800C02  mov      w2, #0x60
static inline uint64_t fde_func_0056_0x05fcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fcdcULL ^ (static_cast<uint64_t>(0xb0000a63ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d22d8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0057 | PC: 0x05fcf0 | FDE: 0x1d22f0 | Size: 20 bytes [Drogon_PyNumber_Subtract]
// Khung tháo gỡ #0057 | Địa chỉ PC: 0x05fcf0 | Địa chỉ FDE: 0x1d22f0 | Kích thước: 20 bytes
//   0x05fcf0: F0000AA3  adrp     x3, #0x1b6000
//   0x05fcf4: AA0203E4  mov      x4, x2
//   0x05fcf8: 9121E863  add      x3, x3, #0x87a
//   0x05fcfc: 52800102  mov      w2, #8
static inline uint64_t fde_func_0057_0x05fcf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fcf0ULL ^ (static_cast<uint64_t>(0xf0000aa3ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d22f0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0058 | PC: 0x05fd04 | FDE: 0x1d2308 | Size: 20 bytes [Drogon_PyNumber_Divmod]
// Khung tháo gỡ #0058 | Địa chỉ PC: 0x05fd04 | Địa chỉ FDE: 0x1d2308 | Kích thước: 20 bytes
//   0x05fd04: F0000A23  adrp     x3, #0x1a6000
//   0x05fd08: AA0203E4  mov      x4, x2
//   0x05fd0c: 912AEC63  add      x3, x3, #0xabb
//   0x05fd10: 52800402  mov      w2, #0x20
static inline uint64_t fde_func_0058_0x05fd04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fd04ULL ^ (static_cast<uint64_t>(0xf0000a23ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d2308ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0059 | PC: 0x05fd18 | FDE: 0x1d2320 | Size: 180 bytes [PyNumber_Add]
// Khung tháo gỡ #0059 | Địa chỉ PC: 0x05fd18 | Địa chỉ FDE: 0x1d2320 | Kích thước: 180 bytes
//   0x05fd18: D100C3FF  sub      sp, sp, #0x30
//   0x05fd1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05fd20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05fd24: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0059_0x05fd18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fd18ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2320ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0060 | PC: 0x05fdcc | FDE: 0x1d2340 | Size: 256 bytes
// Khung tháo gỡ #0060 | Địa chỉ PC: 0x05fdcc | Địa chỉ FDE: 0x1d2340 | Kích thước: 256 bytes
//   0x05fdcc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05fdd0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05fdd4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05fdd8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0060_0x05fdcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fdccULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0061 | PC: 0x05ff20 | FDE: 0x1d2368 | Size: 208 bytes [Drogon_PyNumber_Add]
// Khung tháo gỡ #0061 | Địa chỉ PC: 0x05ff20 | Địa chỉ FDE: 0x1d2368 | Kích thước: 208 bytes
//   0x05ff20: D10103FF  sub      sp, sp, #0x40
//   0x05ff24: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05ff28: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05ff2c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0061_0x05ff20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ff20ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2368ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0062 | PC: 0x05fff0 | FDE: 0x1d2390 | Size: 232 bytes [PyNumber_Multiply]
// Khung tháo gỡ #0062 | Địa chỉ PC: 0x05fff0 | Địa chỉ FDE: 0x1d2390 | Kích thước: 232 bytes
//   0x05fff0: D10103FF  sub      sp, sp, #0x40
//   0x05fff4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05fff8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05fffc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0062_0x05fff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fff0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2390ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0063 | PC: 0x0600d8 | FDE: 0x1d23b8 | Size: 160 bytes
// Khung tháo gỡ #0063 | Địa chỉ PC: 0x0600d8 | Địa chỉ FDE: 0x1d23b8 | Kích thước: 160 bytes
//   0x0600d8: D100C3FF  sub      sp, sp, #0x30
//   0x0600dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0600e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0600e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0063_0x0600d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0600d8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d23b8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0064 | PC: 0x060178 | FDE: 0x1d23d8 | Size: 236 bytes [Drogon_PyNumber_Multiply]
// Khung tháo gỡ #0064 | Địa chỉ PC: 0x060178 | Địa chỉ FDE: 0x1d23d8 | Kích thước: 236 bytes
//   0x060178: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06017c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x060180: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x060184: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0064_0x060178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060178ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d23d8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0065 | PC: 0x060264 | FDE: 0x1d2400 | Size: 16 bytes [PyNumber_MatrixMultiply]
// Khung tháo gỡ #0065 | Địa chỉ PC: 0x060264 | Địa chỉ FDE: 0x1d2400 | Kích thước: 16 bytes
//   0x060264: D0000A03  adrp     x3, #0x1a2000
//   0x060268: 911A0863  add      x3, x3, #0x682
//   0x06026c: 52802202  mov      w2, #0x110
//   0x060270: 17FFFDF5  b        #0x5fa44
static inline uint64_t fde_func_0065_0x060264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060264ULL ^ (static_cast<uint64_t>(0xd0000a03ULL) << 13);
    acc = (acc + a1 + 0x911a0863ULL) ^ 0x1d2400ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0066 | PC: 0x060274 | FDE: 0x1d2418 | Size: 16 bytes [PyNumber_FloorDivide]
// Khung tháo gỡ #0066 | Địa chỉ PC: 0x060274 | Địa chỉ FDE: 0x1d2418 | Kích thước: 16 bytes
//   0x060274: D0000A03  adrp     x3, #0x1a2000
//   0x060278: 911A1063  add      x3, x3, #0x684
//   0x06027c: 52801D02  mov      w2, #0xe8
//   0x060280: 17FFFDF1  b        #0x5fa44
static inline uint64_t fde_func_0066_0x060274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060274ULL ^ (static_cast<uint64_t>(0xd0000a03ULL) << 13);
    acc = (acc + a1 + 0x911a1063ULL) ^ 0x1d2418ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0067 | PC: 0x060284 | FDE: 0x1d2430 | Size: 16 bytes [PyNumber_TrueDivide]
// Khung tháo gỡ #0067 | Địa chỉ PC: 0x060284 | Địa chỉ FDE: 0x1d2430 | Kích thước: 16 bytes
//   0x060284: D0000A03  adrp     x3, #0x1a2000
//   0x060288: 911A1463  add      x3, x3, #0x685
//   0x06028c: 52801E02  mov      w2, #0xf0
//   0x060290: 17FFFDED  b        #0x5fa44
static inline uint64_t fde_func_0067_0x060284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060284ULL ^ (static_cast<uint64_t>(0xd0000a03ULL) << 13);
    acc = (acc + a1 + 0x911a1463ULL) ^ 0x1d2430ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0068 | PC: 0x060294 | FDE: 0x1d2448 | Size: 20 bytes [Drogon_PyNumber_TrueDivide]
// Khung tháo gỡ #0068 | Địa chỉ PC: 0x060294 | Địa chỉ FDE: 0x1d2448 | Kích thước: 20 bytes
//   0x060294: D0000A03  adrp     x3, #0x1a2000
//   0x060298: AA0203E4  mov      x4, x2
//   0x06029c: 911A1463  add      x3, x3, #0x685
//   0x0602a0: 52801E02  mov      w2, #0xf0
static inline uint64_t fde_func_0068_0x060294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060294ULL ^ (static_cast<uint64_t>(0xd0000a03ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x1d2448ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0069 | PC: 0x0602a8 | FDE: 0x1d2460 | Size: 16 bytes [PyNumber_Remainder]
// Khung tháo gỡ #0069 | Địa chỉ PC: 0x0602a8 | Địa chỉ FDE: 0x1d2460 | Kích thước: 16 bytes
//   0x0602a8: F0000AE3  adrp     x3, #0x1bf000
//   0x0602ac: 91337463  add      x3, x3, #0xcdd
//   0x0602b0: 52800302  mov      w2, #0x18
//   0x0602b4: 17FFFDE4  b        #0x5fa44
static inline uint64_t fde_func_0069_0x0602a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0602a8ULL ^ (static_cast<uint64_t>(0xf0000ae3ULL) << 13);
    acc = (acc + a1 + 0x91337463ULL) ^ 0x1d2460ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0070 | PC: 0x0602b8 | FDE: 0x1d2478 | Size: 12 bytes [PyNumber_Power]
// Khung tháo gỡ #0070 | Địa chỉ PC: 0x0602b8 | Địa chỉ FDE: 0x1d2478 | Kích thước: 12 bytes
//   0x0602b8: D0000A03  adrp     x3, #0x1a2000
//   0x0602bc: 911A1C63  add      x3, x3, #0x687
//   0x0602c0: 14000001  b        #0x602c4
static inline uint64_t fde_func_0070_0x0602b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0602b8ULL ^ (static_cast<uint64_t>(0xd0000a03ULL) << 13);
    acc = (acc + a1 + 0x911a1c63ULL) ^ 0x1d2478ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0071 | PC: 0x0602c4 | FDE: 0x1d2490 | Size: 256 bytes
// Khung tháo gỡ #0071 | Địa chỉ PC: 0x0602c4 | Địa chỉ FDE: 0x1d2490 | Kích thước: 256 bytes
//   0x0602c4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0602c8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0602cc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0602d0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0071_0x0602c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0602c4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d2490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0072 | PC: 0x0604b8 | FDE: 0x1d24b8 | Size: 20 bytes [PyNumber_InPlaceOr]
// Khung tháo gỡ #0072 | Địa chỉ PC: 0x0604b8 | Địa chỉ FDE: 0x1d24b8 | Kích thước: 20 bytes
//   0x0604b8: D0000A04  adrp     x4, #0x1a2000
//   0x0604bc: 911A4C84  add      x4, x4, #0x693
//   0x0604c0: 52801C02  mov      w2, #0xe0
//   0x0604c4: 52800F03  mov      w3, #0x78
static inline uint64_t fde_func_0072_0x0604b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0604b8ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a4c84ULL) ^ 0x1d24b8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0073 | PC: 0x0604cc | FDE: 0x1d24d0 | Size: 140 bytes
// Khung tháo gỡ #0073 | Địa chỉ PC: 0x0604cc | Địa chỉ FDE: 0x1d24d0 | Kích thước: 140 bytes
//   0x0604cc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0604d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0604d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0604d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0073_0x0604cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0604ccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d24d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0074 | PC: 0x060558 | FDE: 0x1d24f0 | Size: 20 bytes [PyNumber_InPlaceXor]
// Khung tháo gỡ #0074 | Địa chỉ PC: 0x060558 | Địa chỉ FDE: 0x1d24f0 | Kích thước: 20 bytes
//   0x060558: D0000A04  adrp     x4, #0x1a2000
//   0x06055c: 911A5884  add      x4, x4, #0x696
//   0x060560: 52801B02  mov      w2, #0xd8
//   0x060564: 52800E03  mov      w3, #0x70
static inline uint64_t fde_func_0074_0x060558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060558ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a5884ULL) ^ 0x1d24f0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0075 | PC: 0x06056c | FDE: 0x1d2508 | Size: 20 bytes [PyNumber_InPlaceAnd]
// Khung tháo gỡ #0075 | Địa chỉ PC: 0x06056c | Địa chỉ FDE: 0x1d2508 | Kích thước: 20 bytes
//   0x06056c: D0000A04  adrp     x4, #0x1a2000
//   0x060570: 911A6484  add      x4, x4, #0x699
//   0x060574: 52801A02  mov      w2, #0xd0
//   0x060578: 52800D03  mov      w3, #0x68
static inline uint64_t fde_func_0075_0x06056c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06056cULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a6484ULL) ^ 0x1d2508ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0076 | PC: 0x060580 | FDE: 0x1d2520 | Size: 20 bytes [PyNumber_InPlaceLshift]
// Khung tháo gỡ #0076 | Địa chỉ PC: 0x060580 | Địa chỉ FDE: 0x1d2520 | Kích thước: 20 bytes
//   0x060580: D0000A04  adrp     x4, #0x1a2000
//   0x060584: 911A7084  add      x4, x4, #0x69c
//   0x060588: 52801802  mov      w2, #0xc0
//   0x06058c: 52800B03  mov      w3, #0x58
static inline uint64_t fde_func_0076_0x060580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060580ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a7084ULL) ^ 0x1d2520ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0077 | PC: 0x060594 | FDE: 0x1d2538 | Size: 20 bytes [PyNumber_InPlaceRshift]
// Khung tháo gỡ #0077 | Địa chỉ PC: 0x060594 | Địa chỉ FDE: 0x1d2538 | Kích thước: 20 bytes
//   0x060594: D0000A04  adrp     x4, #0x1a2000
//   0x060598: 911A8084  add      x4, x4, #0x6a0
//   0x06059c: 52801902  mov      w2, #0xc8
//   0x0605a0: 52800C03  mov      w3, #0x60
static inline uint64_t fde_func_0077_0x060594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060594ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a8084ULL) ^ 0x1d2538ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0078 | PC: 0x0605a8 | FDE: 0x1d2550 | Size: 20 bytes [PyNumber_InPlaceSubtract]
// Khung tháo gỡ #0078 | Địa chỉ PC: 0x0605a8 | Địa chỉ FDE: 0x1d2550 | Kích thước: 20 bytes
//   0x0605a8: D0000A04  adrp     x4, #0x1a2000
//   0x0605ac: 911A9084  add      x4, x4, #0x6a4
//   0x0605b0: 52801402  mov      w2, #0xa0
//   0x0605b4: 52800103  mov      w3, #8
static inline uint64_t fde_func_0078_0x0605a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0605a8ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a9084ULL) ^ 0x1d2550ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0079 | PC: 0x0605bc | FDE: 0x1d2568 | Size: 20 bytes [PyNumber_InMatrixMultiply]
// Khung tháo gỡ #0079 | Địa chỉ PC: 0x0605bc | Địa chỉ FDE: 0x1d2568 | Kích thước: 20 bytes
//   0x0605bc: D0000A04  adrp     x4, #0x1a2000
//   0x0605c0: 911A9C84  add      x4, x4, #0x6a7
//   0x0605c4: 52802302  mov      w2, #0x118
//   0x0605c8: 52802203  mov      w3, #0x110
static inline uint64_t fde_func_0079_0x0605bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0605bcULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a9c84ULL) ^ 0x1d2568ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0080 | PC: 0x0605d0 | FDE: 0x1d2580 | Size: 20 bytes [PyNumber_InPlaceFloorDivide]
// Khung tháo gỡ #0080 | Địa chỉ PC: 0x0605d0 | Địa chỉ FDE: 0x1d2580 | Kích thước: 20 bytes
//   0x0605d0: D0000A04  adrp     x4, #0x1a2000
//   0x0605d4: 911AA884  add      x4, x4, #0x6aa
//   0x0605d8: 52801F02  mov      w2, #0xf8
//   0x0605dc: 52801D03  mov      w3, #0xe8
static inline uint64_t fde_func_0080_0x0605d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0605d0ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911aa884ULL) ^ 0x1d2580ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0081 | PC: 0x0605e4 | FDE: 0x1d2598 | Size: 20 bytes [PyNumber_InPlaceTrueDivide]
// Khung tháo gỡ #0081 | Địa chỉ PC: 0x0605e4 | Địa chỉ FDE: 0x1d2598 | Kích thước: 20 bytes
//   0x0605e4: D0000A04  adrp     x4, #0x1a2000
//   0x0605e8: 911AAC84  add      x4, x4, #0x6ab
//   0x0605ec: 52802002  mov      w2, #0x100
//   0x0605f0: 52801E03  mov      w3, #0xf0
static inline uint64_t fde_func_0081_0x0605e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0605e4ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911aac84ULL) ^ 0x1d2598ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0082 | PC: 0x0605f8 | FDE: 0x1d25b0 | Size: 208 bytes [PyNumber_InPlaceAdd]
// Khung tháo gỡ #0082 | Địa chỉ PC: 0x0605f8 | Địa chỉ FDE: 0x1d25b0 | Kích thước: 208 bytes
//   0x0605f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0605fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x060600: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x060604: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0082_0x0605f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0605f8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d25b0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0083 | PC: 0x0606c8 | FDE: 0x1d25d0 | Size: 140 bytes
// Khung tháo gỡ #0083 | Địa chỉ PC: 0x0606c8 | Địa chỉ FDE: 0x1d25d0 | Kích thước: 140 bytes
//   0x0606c8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0606cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0606d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0606d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0083_0x0606c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0606c8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d25d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0084 | PC: 0x060754 | FDE: 0x1d25f0 | Size: 240 bytes [PyNumber_InPlaceMultiply]
// Khung tháo gỡ #0084 | Địa chỉ PC: 0x060754 | Địa chỉ FDE: 0x1d25f0 | Kích thước: 240 bytes
//   0x060754: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x060758: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06075c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x060760: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0084_0x060754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060754ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d25f0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0085 | PC: 0x060844 | FDE: 0x1d2618 | Size: 20 bytes [PyNumber_InPlaceMatrixMultiply]
// Khung tháo gỡ #0085 | Địa chỉ PC: 0x060844 | Địa chỉ FDE: 0x1d2618 | Kích thước: 20 bytes
//   0x060844: D0000A04  adrp     x4, #0x1a2000
//   0x060848: 911A9C84  add      x4, x4, #0x6a7
//   0x06084c: 52802302  mov      w2, #0x118
//   0x060850: 52802203  mov      w3, #0x110
static inline uint64_t fde_func_0085_0x060844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060844ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911a9c84ULL) ^ 0x1d2618ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0086 | PC: 0x060858 | FDE: 0x1d2630 | Size: 20 bytes [PyNumber_InPlaceRemainder]
// Khung tháo gỡ #0086 | Địa chỉ PC: 0x060858 | Địa chỉ FDE: 0x1d2630 | Kích thước: 20 bytes
//   0x060858: D0000A04  adrp     x4, #0x1a2000
//   0x06085c: 911AC484  add      x4, x4, #0x6b1
//   0x060860: 52801602  mov      w2, #0xb0
//   0x060864: 52800303  mov      w3, #0x18
static inline uint64_t fde_func_0086_0x060858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060858ULL ^ (static_cast<uint64_t>(0xd0000a04ULL) << 13);
    acc = (acc + a1 + 0x911ac484ULL) ^ 0x1d2630ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0087 | PC: 0x06086c | FDE: 0x1d2648 | Size: 160 bytes [PyNumber_InPlacePower]
// Khung tháo gỡ #0087 | Địa chỉ PC: 0x06086c | Địa chỉ FDE: 0x1d2648 | Kích thước: 160 bytes
//   0x06086c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x060870: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x060874: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x060878: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0087_0x06086c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06086cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2648ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0088 | PC: 0x06090c | FDE: 0x1d2668 | Size: 88 bytes [PyNumber_Negative]
// Khung tháo gỡ #0088 | Địa chỉ PC: 0x06090c | Địa chỉ FDE: 0x1d2668 | Kích thước: 88 bytes
//   0x06090c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x060910: 910003FD  mov      x29, sp
//   0x060914: B4000100  cbz      x0, #0x60934
//   0x060918: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0088_0x06090c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06090cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2668ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0089 | PC: 0x060964 | FDE: 0x1d2688 | Size: 88 bytes [PyNumber_Positive]
// Khung tháo gỡ #0089 | Địa chỉ PC: 0x060964 | Địa chỉ FDE: 0x1d2688 | Kích thước: 88 bytes
//   0x060964: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x060968: 910003FD  mov      x29, sp
//   0x06096c: B4000100  cbz      x0, #0x6098c
//   0x060970: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0089_0x060964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060964ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2688ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0090 | PC: 0x0609bc | FDE: 0x1d26a8 | Size: 88 bytes [PyNumber_Invert]
// Khung tháo gỡ #0090 | Địa chỉ PC: 0x0609bc | Địa chỉ FDE: 0x1d26a8 | Kích thước: 88 bytes
//   0x0609bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0609c0: 910003FD  mov      x29, sp
//   0x0609c4: B4000100  cbz      x0, #0x609e4
//   0x0609c8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0090_0x0609bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0609bcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d26a8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0091 | PC: 0x060a14 | FDE: 0x1d26c8 | Size: 88 bytes [PyNumber_Absolute]
// Khung tháo gỡ #0091 | Địa chỉ PC: 0x060a14 | Địa chỉ FDE: 0x1d26c8 | Kích thước: 88 bytes
//   0x060a14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x060a18: 910003FD  mov      x29, sp
//   0x060a1c: B4000100  cbz      x0, #0x60a3c
//   0x060a20: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0091_0x060a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060a14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d26c8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0092 | PC: 0x060a6c | FDE: 0x1d26e8 | Size: 36 bytes [PyIndex_Check]
// Khung tháo gỡ #0092 | Địa chỉ PC: 0x060a6c | Địa chỉ FDE: 0x1d26e8 | Kích thước: 36 bytes
//   0x060a6c: F9400408  ldr      x8, [x0, #8]
//   0x060a70: F9403108  ldr      x8, [x8, #0x60]
//   0x060a74: B40000A8  cbz      x8, #0x60a88
//   0x060a78: F9408508  ldr      x8, [x8, #0x108]
static inline uint64_t fde_func_0092_0x060a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060a6cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9403108ULL) ^ 0x1d26e8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0093 | PC: 0x060a90 | FDE: 0x1d2700 | Size: 256 bytes [_PyNumber_Index]
// Khung tháo gỡ #0093 | Địa chỉ PC: 0x060a90 | Địa chỉ FDE: 0x1d2700 | Kích thước: 256 bytes
//   0x060a90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x060a94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x060a98: 910043FD  add      x29, sp, #0x10
//   0x060a9c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0093_0x060a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060a90ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0094 | PC: 0x060b94 | FDE: 0x1d2720 | Size: 112 bytes [PyNumber_Index]
// Khung tháo gỡ #0094 | Địa chỉ PC: 0x060b94 | Địa chỉ FDE: 0x1d2720 | Kích thước: 112 bytes
//   0x060b94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x060b98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x060b9c: 910043FD  add      x29, sp, #0x10
//   0x060ba0: 97FFF314  bl       #0x5d7f0
static inline uint64_t fde_func_0094_0x060b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060b94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2720ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0095 | PC: 0x060c04 | FDE: 0x1d2740 | Size: 256 bytes [PyNumber_Long]
// Khung tháo gỡ #0095 | Địa chỉ PC: 0x060c04 | Địa chỉ FDE: 0x1d2740 | Kích thước: 256 bytes
//   0x060c04: D10283FF  sub      sp, sp, #0xa0
//   0x060c08: F90033F7  str      x23, [sp, #0x60]
//   0x060c0c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x060c10: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0095_0x060c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060c04ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1d2740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0096 | PC: 0x060f50 | FDE: 0x1d2768 | Size: 256 bytes [PyNumber_Float]
// Khung tháo gỡ #0096 | Địa chỉ PC: 0x060f50 | Địa chỉ FDE: 0x1d2768 | Kích thước: 256 bytes
//   0x060f50: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x060f54: F90007F5  str      x21, [sp, #8]
//   0x060f58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x060f5c: A9027BFD  stp      x29, x30, [sp, #0x20]
static inline uint64_t fde_func_0096_0x060f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060f50ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f5ULL) ^ 0x1d2768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0097 | PC: 0x061120 | FDE: 0x1d2790 | Size: 148 bytes [PyNumber_ToBase]
// Khung tháo gỡ #0097 | Địa chỉ PC: 0x061120 | Địa chỉ FDE: 0x1d2790 | Kích thước: 148 bytes
//   0x061120: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061124: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061128: 910043FD  add      x29, sp, #0x10
//   0x06112c: 51000828  sub      w8, w1, #2
static inline uint64_t fde_func_0097_0x061120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061120ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2790ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0098 | PC: 0x0611b4 | FDE: 0x1d27b0 | Size: 44 bytes [PySequence_Check]
// Khung tháo gỡ #0098 | Địa chỉ PC: 0x0611b4 | Địa chỉ FDE: 0x1d27b0 | Kích thước: 44 bytes
//   0x0611b4: F9400408  ldr      x8, [x0, #8]
//   0x0611b8: 3942AD09  ldrb     w9, [x8, #0xab]
//   0x0611bc: 372800E9  tbnz     w9, #5, #0x611d8
//   0x0611c0: F9403508  ldr      x8, [x8, #0x68]
static inline uint64_t fde_func_0098_0x0611b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0611b4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x3942ad09ULL) ^ 0x1d27b0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0099 | PC: 0x0611e0 | FDE: 0x1d27c8 | Size: 128 bytes [PySequence_Size]
// Khung tháo gỡ #0099 | Địa chỉ PC: 0x0611e0 | Địa chỉ FDE: 0x1d27c8 | Kích thước: 128 bytes
//   0x0611e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0611e4: 910003FD  mov      x29, sp
//   0x0611e8: B4000100  cbz      x0, #0x61208
//   0x0611ec: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0099_0x0611e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0611e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d27c8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0100 | PC: 0x061260 | FDE: 0x1d27e8 | Size: 4 bytes [PySequence_Length]
// Khung tháo gỡ #0100 | Địa chỉ PC: 0x061260 | Địa chỉ FDE: 0x1d27e8 | Kích thước: 4 bytes
//   0x061260: 17FFE5B8  b        #0x5a940
static inline uint64_t fde_func_0100_0x061260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061260ULL ^ (static_cast<uint64_t>(0x17ffe5b8ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1d27e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0101 | PC: 0x061264 | FDE: 0x1d2800 | Size: 224 bytes [PySequence_Concat]
// Khung tháo gỡ #0101 | Địa chỉ PC: 0x061264 | Địa chỉ FDE: 0x1d2800 | Kích thước: 224 bytes
//   0x061264: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061268: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06126c: 910043FD  add      x29, sp, #0x10
//   0x061270: B4000180  cbz      x0, #0x612a0
static inline uint64_t fde_func_0101_0x061264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061264ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2800ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0102 | PC: 0x061344 | FDE: 0x1d2820 | Size: 256 bytes [PySequence_Repeat]
// Khung tháo gỡ #0102 | Địa chỉ PC: 0x061344 | Địa chỉ FDE: 0x1d2820 | Kích thước: 256 bytes
//   0x061344: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061348: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06134c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061350: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0102_0x061344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061344ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0103 | PC: 0x061444 | FDE: 0x1d2840 | Size: 232 bytes [PySequence_InPlaceConcat]
// Khung tháo gỡ #0103 | Địa chỉ PC: 0x061444 | Địa chỉ FDE: 0x1d2840 | Kích thước: 232 bytes
//   0x061444: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061448: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06144c: 910043FD  add      x29, sp, #0x10
//   0x061450: B40001C0  cbz      x0, #0x61488
static inline uint64_t fde_func_0103_0x061444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061444ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2840ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0104 | PC: 0x06152c | FDE: 0x1d2860 | Size: 256 bytes [PySequence_InPlaceRepeat]
// Khung tháo gỡ #0104 | Địa chỉ PC: 0x06152c | Địa chỉ FDE: 0x1d2860 | Kích thước: 256 bytes
//   0x06152c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061530: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x061534: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061538: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0104_0x06152c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06152cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0105 | PC: 0x061634 | FDE: 0x1d2880 | Size: 172 bytes [PySequence_GetSlice]
// Khung tháo gỡ #0105 | Địa chỉ PC: 0x061634 | Địa chỉ FDE: 0x1d2880 | Kích thước: 172 bytes
//   0x061634: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061638: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06163c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061640: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0105_0x061634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061634ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2880ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0106 | PC: 0x0616e0 | FDE: 0x1d28a0 | Size: 180 bytes [PySequence_SetSlice]
// Khung tháo gỡ #0106 | Địa chỉ PC: 0x0616e0 | Địa chỉ FDE: 0x1d28a0 | Kích thước: 180 bytes
//   0x0616e0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0616e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0616e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0616ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0106_0x0616e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0616e0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d28a0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0107 | PC: 0x061794 | FDE: 0x1d28c8 | Size: 176 bytes [PySequence_DelSlice]
// Khung tháo gỡ #0107 | Địa chỉ PC: 0x061794 | Địa chỉ FDE: 0x1d28c8 | Kích thước: 176 bytes
//   0x061794: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061798: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06179c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0617a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0107_0x061794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061794ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d28c8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0108 | PC: 0x061844 | FDE: 0x1d28e8 | Size: 256 bytes [PySequence_Tuple]
// Khung tháo gỡ #0108 | Địa chỉ PC: 0x061844 | Địa chỉ FDE: 0x1d28e8 | Kích thước: 256 bytes
//   0x061844: D10143FF  sub      sp, sp, #0x50
//   0x061848: F9000BF7  str      x23, [sp, #0x10]
//   0x06184c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x061850: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0108_0x061844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061844ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1d28e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0109 | PC: 0x061a18 | FDE: 0x1d2910 | Size: 204 bytes [PyObject_GetIter]
// Khung tháo gỡ #0109 | Địa chỉ PC: 0x061a18 | Địa chỉ FDE: 0x1d2910 | Kích thước: 204 bytes
//   0x061a18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061a20: 910043FD  add      x29, sp, #0x10
//   0x061a24: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0109_0x061a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061a18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2910ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0110 | PC: 0x061ae4 | FDE: 0x1d2930 | Size: 92 bytes [PyIter_Next]
// Khung tháo gỡ #0110 | Địa chỉ PC: 0x061ae4 | Địa chỉ FDE: 0x1d2930 | Kích thước: 92 bytes
//   0x061ae4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061ae8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061aec: 910043FD  add      x29, sp, #0x10
//   0x061af0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0110_0x061ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061ae4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2930ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0111 | PC: 0x061b40 | FDE: 0x1d2950 | Size: 128 bytes [PySequence_List]
// Khung tháo gỡ #0111 | Địa chỉ PC: 0x061b40 | Địa chỉ FDE: 0x1d2950 | Kích thước: 128 bytes
//   0x061b40: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061b44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061b48: 910043FD  add      x29, sp, #0x10
//   0x061b4c: B4000200  cbz      x0, #0x61b8c
static inline uint64_t fde_func_0111_0x061b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061b40ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2950ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0112 | PC: 0x061bc0 | FDE: 0x1d2970 | Size: 208 bytes [PySequence_Fast]
// Khung tháo gỡ #0112 | Địa chỉ PC: 0x061bc0 | Địa chỉ FDE: 0x1d2970 | Kích thước: 208 bytes
//   0x061bc0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061bc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x061bc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061bcc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0112_0x061bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061bc0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2970ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0113 | PC: 0x061c90 | FDE: 0x1d2990 | Size: 256 bytes [_PySequence_IterSearch]
// Khung tháo gỡ #0113 | Địa chỉ PC: 0x061c90 | Địa chỉ FDE: 0x1d2990 | Kích thước: 256 bytes
//   0x061c90: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x061c94: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x061c98: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x061c9c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0113_0x061c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061c90ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d2990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0114 | PC: 0x061e2c | FDE: 0x1d29c0 | Size: 8 bytes [PySequence_Count]
// Khung tháo gỡ #0114 | Địa chỉ PC: 0x061e2c | Địa chỉ FDE: 0x1d29c0 | Kích thước: 8 bytes
//   0x061e2c: 52800022  mov      w2, #1
//   0x061e30: 17FFE48C  b        #0x5b060
static inline uint64_t fde_func_0114_0x061e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e2cULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x17ffe48cULL) ^ 0x1d29c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0115 | PC: 0x061e34 | FDE: 0x1d29d8 | Size: 52 bytes [PySequence_Contains]
// Khung tháo gỡ #0115 | Địa chỉ PC: 0x061e34 | Địa chỉ FDE: 0x1d29d8 | Kích thước: 52 bytes
//   0x061e34: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x061e38: 910003FD  mov      x29, sp
//   0x061e3c: F9400408  ldr      x8, [x0, #8]
//   0x061e40: F9403508  ldr      x8, [x8, #0x68]
static inline uint64_t fde_func_0115_0x061e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e34ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d29d8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0116 | PC: 0x061e68 | FDE: 0x1d29f8 | Size: 4 bytes [PySequence_In]
// Khung tháo gỡ #0116 | Địa chỉ PC: 0x061e68 | Địa chỉ FDE: 0x1d29f8 | Kích thước: 4 bytes
//   0x061e68: 17FFE0A2  b        #0x5a0f0
static inline uint64_t fde_func_0116_0x061e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e68ULL ^ (static_cast<uint64_t>(0x17ffe0a2ULL) << 13);
    acc = (acc + a1 + 0x52800042ULL) ^ 0x1d29f8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0117 | PC: 0x061e6c | FDE: 0x1d2a10 | Size: 8 bytes [PySequence_Index]
// Khung tháo gỡ #0117 | Địa chỉ PC: 0x061e6c | Địa chỉ FDE: 0x1d2a10 | Kích thước: 8 bytes
//   0x061e6c: 52800042  mov      w2, #2
//   0x061e70: 17FFE47C  b        #0x5b060
static inline uint64_t fde_func_0117_0x061e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e6cULL ^ (static_cast<uint64_t>(0x52800042ULL) << 13);
    acc = (acc + a1 + 0x17ffe47cULL) ^ 0x1d2a10ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0118 | PC: 0x061e74 | FDE: 0x1d2a28 | Size: 40 bytes [PyMapping_Check]
// Khung tháo gỡ #0118 | Địa chỉ PC: 0x061e74 | Địa chỉ FDE: 0x1d2a28 | Kích thước: 40 bytes
//   0x061e74: B40000E0  cbz      x0, #0x61e90
//   0x061e78: F9400408  ldr      x8, [x0, #8]
//   0x061e7c: F9403908  ldr      x8, [x8, #0x70]
//   0x061e80: B40000A8  cbz      x8, #0x61e94
static inline uint64_t fde_func_0118_0x061e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e74ULL ^ (static_cast<uint64_t>(0xb40000e0ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1d2a28ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0119 | PC: 0x061e9c | FDE: 0x1d2a40 | Size: 4 bytes [PyMapping_Length]
// Khung tháo gỡ #0119 | Địa chỉ PC: 0x061e9c | Địa chỉ FDE: 0x1d2a40 | Kích thước: 4 bytes
//   0x061e9c: 17FFE961  b        #0x5c420
static inline uint64_t fde_func_0119_0x061e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e9cULL ^ (static_cast<uint64_t>(0x17ffe961ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1d2a40ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0120 | PC: 0x061ea0 | FDE: 0x1d2a58 | Size: 104 bytes [PyMapping_GetItemString]
// Khung tháo gỡ #0120 | Địa chỉ PC: 0x061ea0 | Địa chỉ FDE: 0x1d2a58 | Kích thước: 104 bytes
//   0x061ea0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061ea4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061ea8: 910043FD  add      x29, sp, #0x10
//   0x061eac: B4000221  cbz      x1, #0x61ef0
static inline uint64_t fde_func_0120_0x061ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061ea0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2a58ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0121 | PC: 0x061f08 | FDE: 0x1d2a78 | Size: 120 bytes [PyMapping_SetItemString]
// Khung tháo gỡ #0121 | Địa chỉ PC: 0x061f08 | Địa chỉ FDE: 0x1d2a78 | Kích thước: 120 bytes
//   0x061f08: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061f0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x061f10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061f14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0121_0x061f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061f08ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2a78ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0122 | PC: 0x061f80 | FDE: 0x1d2a98 | Size: 60 bytes [PyMapping_HasKeyString]
// Khung tháo gỡ #0122 | Địa chỉ PC: 0x061f80 | Địa chỉ FDE: 0x1d2a98 | Kích thước: 60 bytes
//   0x061f80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x061f84: 910003FD  mov      x29, sp
//   0x061f88: 97FFDF6A  bl       #0x59d30
//   0x061f8c: B4000100  cbz      x0, #0x61fac
static inline uint64_t fde_func_0122_0x061f80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061f80ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2a98ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0123 | PC: 0x061fbc | FDE: 0x1d2ab8 | Size: 60 bytes [PyMapping_HasKey]
// Khung tháo gỡ #0123 | Địa chỉ PC: 0x061fbc | Địa chỉ FDE: 0x1d2ab8 | Kích thước: 60 bytes
//   0x061fbc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x061fc0: 910003FD  mov      x29, sp
//   0x061fc4: 97FFDF6F  bl       #0x59d80
//   0x061fc8: B4000100  cbz      x0, #0x61fe8
static inline uint64_t fde_func_0123_0x061fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061fbcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2ab8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0124 | PC: 0x061ff8 | FDE: 0x1d2ad8 | Size: 72 bytes [PyMapping_Keys]
// Khung tháo gỡ #0124 | Địa chỉ PC: 0x061ff8 | Địa chỉ FDE: 0x1d2ad8 | Kích thước: 72 bytes
//   0x061ff8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x061ffc: 910003FD  mov      x29, sp
//   0x062000: B4000140  cbz      x0, #0x62028
//   0x062004: B0000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0124_0x061ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061ff8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2ad8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0125 | PC: 0x062040 | FDE: 0x1d2af8 | Size: 256 bytes
// Khung tháo gỡ #0125 | Địa chỉ PC: 0x062040 | Địa chỉ FDE: 0x1d2af8 | Kích thước: 256 bytes
//   0x062040: D10143FF  sub      sp, sp, #0x50
//   0x062044: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x062048: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06204c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0125_0x062040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062040ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d2af8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0126 | PC: 0x062198 | FDE: 0x1d2b20 | Size: 72 bytes [PyMapping_Items]
// Khung tháo gỡ #0126 | Địa chỉ PC: 0x062198 | Địa chỉ FDE: 0x1d2b20 | Kích thước: 72 bytes
//   0x062198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06219c: 910003FD  mov      x29, sp
//   0x0621a0: B4000140  cbz      x0, #0x621c8
//   0x0621a4: B0000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0126_0x062198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2b20ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0127 | PC: 0x0621e0 | FDE: 0x1d2b40 | Size: 72 bytes [PyMapping_Values]
// Khung tháo gỡ #0127 | Địa chỉ PC: 0x0621e0 | Địa chỉ FDE: 0x1d2b40 | Kích thước: 72 bytes
//   0x0621e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0621e4: 910003FD  mov      x29, sp
//   0x0621e8: B4000140  cbz      x0, #0x62210
//   0x0621ec: B0000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0127_0x0621e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0621e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2b40ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0128 | PC: 0x062228 | FDE: 0x1d2b60 | Size: 44 bytes [PyObject_IsInstance]
// Khung tháo gỡ #0128 | Địa chỉ PC: 0x062228 | Địa chỉ FDE: 0x1d2b60 | Kích thước: 44 bytes
//   0x062228: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06222c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062230: 910043FD  add      x29, sp, #0x10
//   0x062234: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0128_0x062228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062228ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2b60ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0129 | PC: 0x062254 | FDE: 0x1d2b80 | Size: 256 bytes
// Khung tháo gỡ #0129 | Địa chỉ PC: 0x062254 | Địa chỉ FDE: 0x1d2b80 | Kích thước: 256 bytes
//   0x062254: D101C3FF  sub      sp, sp, #0x70
//   0x062258: F90013F9  str      x25, [sp, #0x20]
//   0x06225c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x062260: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0129_0x062254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062254ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1d2b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0130 | PC: 0x0624c0 | FDE: 0x1d2ba8 | Size: 44 bytes [PyObject_IsSubclass]
// Khung tháo gỡ #0130 | Địa chỉ PC: 0x0624c0 | Địa chỉ FDE: 0x1d2ba8 | Kích thước: 44 bytes
//   0x0624c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0624c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0624c8: 910043FD  add      x29, sp, #0x10
//   0x0624cc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0130_0x0624c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0624c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2ba8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0131 | PC: 0x0624ec | FDE: 0x1d2bc8 | Size: 256 bytes
// Khung tháo gỡ #0131 | Địa chỉ PC: 0x0624ec | Địa chỉ FDE: 0x1d2bc8 | Kích thước: 256 bytes
//   0x0624ec: D101C3FF  sub      sp, sp, #0x70
//   0x0624f0: F90013F9  str      x25, [sp, #0x20]
//   0x0624f4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0624f8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0131_0x0624ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0624ecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1d2bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0132 | PC: 0x06275c | FDE: 0x1d2bf0 | Size: 4 bytes [_PyObject_RealIsInstance]
// Khung tháo gỡ #0132 | Địa chỉ PC: 0x06275c | Địa chỉ FDE: 0x1d2bf0 | Kích thước: 4 bytes
//   0x06275c: 14000001  b        #0x62760
static inline uint64_t fde_func_0132_0x06275c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06275cULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xd10103ffULL) ^ 0x1d2bf0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0133 | PC: 0x062760 | FDE: 0x1d2c08 | Size: 256 bytes
// Khung tháo gỡ #0133 | Địa chỉ PC: 0x062760 | Địa chỉ FDE: 0x1d2c08 | Kích thước: 256 bytes
//   0x062760: D10103FF  sub      sp, sp, #0x40
//   0x062764: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x062768: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06276c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0133_0x062760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062760ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0134 | PC: 0x0628b0 | FDE: 0x1d2c30 | Size: 4 bytes [_PyObject_RealIsSubclass]
// Khung tháo gỡ #0134 | Địa chỉ PC: 0x0628b0 | Địa chỉ FDE: 0x1d2c30 | Kích thước: 4 bytes
//   0x0628b0: 14000001  b        #0x628b4
static inline uint64_t fde_func_0134_0x0628b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0628b0ULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1d2c30ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0135 | PC: 0x0628b4 | FDE: 0x1d2c48 | Size: 160 bytes
// Khung tháo gỡ #0135 | Địa chỉ PC: 0x0628b4 | Địa chỉ FDE: 0x1d2c48 | Kích thước: 160 bytes
//   0x0628b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0628b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0628bc: 910043FD  add      x29, sp, #0x10
//   0x0628c0: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_0135_0x0628b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0628b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2c48ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0136 | PC: 0x062954 | FDE: 0x1d2c68 | Size: 40 bytes [PyIter_Check]
// Khung tháo gỡ #0136 | Địa chỉ PC: 0x062954 | Địa chỉ FDE: 0x1d2c68 | Kích thước: 40 bytes
//   0x062954: F9400408  ldr      x8, [x0, #8]
//   0x062958: B0000CE9  adrp     x9, #0x1ff000
//   0x06295c: F9407108  ldr      x8, [x8, #0xe0]
//   0x062960: F9469929  ldr      x9, [x9, #0xd30]
static inline uint64_t fde_func_0136_0x062954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062954ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb0000ce9ULL) ^ 0x1d2c68ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0137 | PC: 0x06297c | FDE: 0x1d2c80 | Size: 184 bytes [PyObject_GetAIter]
// Khung tháo gỡ #0137 | Địa chỉ PC: 0x06297c | Địa chỉ FDE: 0x1d2c80 | Kích thước: 184 bytes
//   0x06297c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x062980: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062984: 910043FD  add      x29, sp, #0x10
//   0x062988: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0137_0x06297c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06297cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2c80ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0138 | PC: 0x062a34 | FDE: 0x1d2ca0 | Size: 48 bytes [PyAIter_Check]
// Khung tháo gỡ #0138 | Địa chỉ PC: 0x062a34 | Địa chỉ FDE: 0x1d2ca0 | Kích thước: 48 bytes
//   0x062a34: F9400408  ldr      x8, [x0, #8]
//   0x062a38: F9402908  ldr      x8, [x8, #0x50]
//   0x062a3c: B4000108  cbz      x8, #0x62a5c
//   0x062a40: F9400908  ldr      x8, [x8, #0x10]
static inline uint64_t fde_func_0138_0x062a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062a34ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9402908ULL) ^ 0x1d2ca0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0139 | PC: 0x062a64 | FDE: 0x1d2cb8 | Size: 220 bytes [PyIter_Send]
// Khung tháo gỡ #0139 | Địa chỉ PC: 0x062a64 | Địa chỉ FDE: 0x1d2cb8 | Kích thước: 220 bytes
//   0x062a64: D10103FF  sub      sp, sp, #0x40
//   0x062a68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x062a6c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x062a70: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0139_0x062a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062a64ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1d2cb8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0140 | PC: 0x062b40 | FDE: 0x1d2cd8 | Size: 256 bytes [_PySequence_BytesToCharpArray]
// Khung tháo gỡ #0140 | Địa chỉ PC: 0x062b40 | Địa chỉ FDE: 0x1d2cd8 | Kích thước: 256 bytes
//   0x062b40: D10183FF  sub      sp, sp, #0x60
//   0x062b44: F9000BF9  str      x25, [sp, #0x10]
//   0x062b48: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x062b4c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0140_0x062b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062b40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1d2cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0141 | PC: 0x062c98 | FDE: 0x1d2d00 | Size: 56 bytes [_Py_FreeCharPArray]
// Khung tháo gỡ #0141 | Địa chỉ PC: 0x062c98 | Địa chỉ FDE: 0x1d2d00 | Kích thước: 56 bytes
//   0x062c98: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x062c9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062ca0: 910043FD  add      x29, sp, #0x10
//   0x062ca4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0141_0x062c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062c98ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2d00ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0142 | PC: 0x062cd0 | FDE: 0x1d2d20 | Size: 100 bytes
// Khung tháo gỡ #0142 | Địa chỉ PC: 0x062cd0 | Địa chỉ FDE: 0x1d2d20 | Kích thước: 100 bytes
//   0x062cd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x062cd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062cd8: 910043FD  add      x29, sp, #0x10
//   0x062cdc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0142_0x062cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062cd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2d20ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0143 | PC: 0x062d34 | FDE: 0x1d2d40 | Size: 256 bytes
// Khung tháo gỡ #0143 | Địa chỉ PC: 0x062d34 | Địa chỉ FDE: 0x1d2d40 | Kích thước: 256 bytes
//   0x062d34: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x062d38: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x062d3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x062d40: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0143_0x062d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062d34ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d2d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0144 | PC: 0x062e54 | FDE: 0x1d2d68 | Size: 124 bytes
// Khung tháo gỡ #0144 | Địa chỉ PC: 0x062e54 | Địa chỉ FDE: 0x1d2d68 | Kích thước: 124 bytes
//   0x062e54: D100C3FF  sub      sp, sp, #0x30
//   0x062e58: F9000BF3  str      x19, [sp, #0x10]
//   0x062e5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x062e60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0144_0x062e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062e54ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1d2d68ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0145 | PC: 0x062ed0 | FDE: 0x1d2d88 | Size: 56 bytes [_PyAccu_Init]
// Khung tháo gỡ #0145 | Địa chỉ PC: 0x062ed0 | Địa chỉ FDE: 0x1d2d88 | Kích thước: 56 bytes
//   0x062ed0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x062ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062ed8: 910043FD  add      x29, sp, #0x10
//   0x062edc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0145_0x062ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062ed0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2d88ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0146 | PC: 0x062f08 | FDE: 0x1d2da8 | Size: 92 bytes [_PyAccu_Accumulate]
// Khung tháo gỡ #0146 | Địa chỉ PC: 0x062f08 | Địa chỉ FDE: 0x1d2da8 | Kích thước: 92 bytes
//   0x062f08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x062f0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062f10: 910043FD  add      x29, sp, #0x10
//   0x062f14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0146_0x062f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062f08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2da8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0147 | PC: 0x062f64 | FDE: 0x1d2dc8 | Size: 252 bytes
// Khung tháo gỡ #0147 | Địa chỉ PC: 0x062f64 | Địa chỉ FDE: 0x1d2dc8 | Kích thước: 252 bytes
//   0x062f64: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x062f68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x062f6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x062f70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0147_0x062f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062f64ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2dc8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0148 | PC: 0x063060 | FDE: 0x1d2df0 | Size: 140 bytes [_PyAccu_FinishAsList]
// Khung tháo gỡ #0148 | Địa chỉ PC: 0x063060 | Địa chỉ FDE: 0x1d2df0 | Kích thước: 140 bytes
//   0x063060: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x063064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063068: 910043FD  add      x29, sp, #0x10
//   0x06306c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0148_0x063060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063060ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2df0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0149 | PC: 0x0630ec | FDE: 0x1d2e10 | Size: 256 bytes [_PyAccu_Finish]
// Khung tháo gỡ #0149 | Địa chỉ PC: 0x0630ec | Địa chỉ FDE: 0x1d2e10 | Kích thước: 256 bytes
//   0x0630ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0630f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0630f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0630f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0149_0x0630ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0630ecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d2e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0150 | PC: 0x0631f0 | FDE: 0x1d2e30 | Size: 108 bytes [_PyAccu_Destroy]
// Khung tháo gỡ #0150 | Địa chỉ PC: 0x0631f0 | Địa chỉ FDE: 0x1d2e30 | Kích thước: 108 bytes
//   0x0631f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0631f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0631f8: 910043FD  add      x29, sp, #0x10
//   0x0631fc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0150_0x0631f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0631f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2e30ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0151 | PC: 0x06325c | FDE: 0x1d2e50 | Size: 40 bytes [PyBool_FromLong]
// Khung tháo gỡ #0151 | Địa chỉ PC: 0x06325c | Địa chỉ FDE: 0x1d2e50 | Kích thước: 40 bytes
//   0x06325c: 90000CE8  adrp     x8, #0x1ff000
//   0x063260: 90000CE9  adrp     x9, #0x1ff000
//   0x063264: F9465908  ldr      x8, [x8, #0xcb0]
//   0x063268: F9456129  ldr      x9, [x9, #0xac0]
static inline uint64_t fde_func_0151_0x06325c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06325cULL ^ (static_cast<uint64_t>(0x90000ce8ULL) << 13);
    acc = (acc + a1 + 0x90000ce9ULL) ^ 0x1d2e50ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0152 | PC: 0x063284 | FDE: 0x1d2e68 | Size: 68 bytes
// Khung tháo gỡ #0152 | Địa chỉ PC: 0x063284 | Địa chỉ FDE: 0x1d2e68 | Kích thước: 68 bytes
//   0x063284: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x063288: 910003FD  mov      x29, sp
//   0x06328c: 90000CE8  adrp     x8, #0x1ff000
//   0x063290: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_0152_0x063284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063284ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d2e68ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0153 | PC: 0x0632c8 | FDE: 0x1d2e88 | Size: 192 bytes
// Khung tháo gỡ #0153 | Địa chỉ PC: 0x0632c8 | Địa chỉ FDE: 0x1d2e88 | Kích thước: 192 bytes
//   0x0632c8: D10103FF  sub      sp, sp, #0x40
//   0x0632cc: F9000BF5  str      x21, [sp, #0x10]
//   0x0632d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0632d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0153_0x0632c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0632c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1d2e88ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0154 | PC: 0x063388 | FDE: 0x1d2ea8 | Size: 156 bytes
// Khung tháo gỡ #0154 | Địa chỉ PC: 0x063388 | Địa chỉ FDE: 0x1d2ea8 | Kích thước: 156 bytes
//   0x063388: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06338c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063390: 910043FD  add      x29, sp, #0x10
//   0x063394: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0154_0x063388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063388ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d2ea8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0155 | PC: 0x063424 | FDE: 0x1d2ec8 | Size: 96 bytes
// Khung tháo gỡ #0155 | Địa chỉ PC: 0x063424 | Địa chỉ FDE: 0x1d2ec8 | Kích thước: 96 bytes
//   0x063424: 90000CE8  adrp     x8, #0x1ff000
//   0x063428: F9400409  ldr      x9, [x0, #8]
//   0x06342c: F9467D08  ldr      x8, [x8, #0xcf8]
//   0x063430: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_0155_0x063424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063424ULL ^ (static_cast<uint64_t>(0x90000ce8ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1d2ec8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0156 | PC: 0x063484 | FDE: 0x1d2ee0 | Size: 112 bytes
// Khung tháo gỡ #0156 | Địa chỉ PC: 0x063484 | Địa chỉ FDE: 0x1d2ee0 | Kích thước: 112 bytes
//   0x063484: 90000CE8  adrp     x8, #0x1ff000
//   0x063488: F9400409  ldr      x9, [x0, #8]
//   0x06348c: F9467D08  ldr      x8, [x8, #0xcf8]
//   0x063490: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_0156_0x063484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063484ULL ^ (static_cast<uint64_t>(0x90000ce8ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1d2ee0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0157 | PC: 0x0634f4 | FDE: 0x1d2ef8 | Size: 96 bytes
// Khung tháo gỡ #0157 | Địa chỉ PC: 0x0634f4 | Địa chỉ FDE: 0x1d2ef8 | Kích thước: 96 bytes
//   0x0634f4: 90000CE8  adrp     x8, #0x1ff000
//   0x0634f8: F9400409  ldr      x9, [x0, #8]
//   0x0634fc: F9467D08  ldr      x8, [x8, #0xcf8]
//   0x063500: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_0157_0x0634f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0634f4ULL ^ (static_cast<uint64_t>(0x90000ce8ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1d2ef8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0158 | PC: 0x063554 | FDE: 0x1d2f10 | Size: 140 bytes [_Py_bytes_isspace]
// Khung tháo gỡ #0158 | Địa chỉ PC: 0x063554 | Địa chỉ FDE: 0x1d2f10 | Kích thước: 140 bytes
//   0x063554: B4000361  cbz      x1, #0x635c0
//   0x063558: AA0003E8  mov      x8, x0
//   0x06355c: F100043F  cmp      x1, #1
//   0x063560: 540000C1  b.ne     #0x63578
static inline uint64_t fde_func_0158_0x063554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063554ULL ^ (static_cast<uint64_t>(0xb4000361ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d2f10ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0159 | PC: 0x0635e0 | FDE: 0x1d2f28 | Size: 148 bytes [_Py_bytes_isalpha]
// Khung tháo gỡ #0159 | Địa chỉ PC: 0x0635e0 | Địa chỉ FDE: 0x1d2f28 | Kích thước: 148 bytes
//   0x0635e0: B40003A1  cbz      x1, #0x63654
//   0x0635e4: AA0003E8  mov      x8, x0
//   0x0635e8: F100043F  cmp      x1, #1
//   0x0635ec: 540000E1  b.ne     #0x63608
static inline uint64_t fde_func_0159_0x0635e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0635e0ULL ^ (static_cast<uint64_t>(0xb40003a1ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d2f28ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0160 | PC: 0x063674 | FDE: 0x1d2f40 | Size: 148 bytes [_Py_bytes_isalnum]
// Khung tháo gỡ #0160 | Địa chỉ PC: 0x063674 | Địa chỉ FDE: 0x1d2f40 | Kích thước: 148 bytes
//   0x063674: B40003A1  cbz      x1, #0x636e8
//   0x063678: AA0003E8  mov      x8, x0
//   0x06367c: F100043F  cmp      x1, #1
//   0x063680: 540000E1  b.ne     #0x6369c
static inline uint64_t fde_func_0160_0x063674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063674ULL ^ (static_cast<uint64_t>(0xb40003a1ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d2f40ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0161 | PC: 0x063708 | FDE: 0x1d2f58 | Size: 132 bytes [_Py_bytes_isascii]
// Khung tháo gỡ #0161 | Địa chỉ PC: 0x063708 | Địa chỉ FDE: 0x1d2f58 | Kích thước: 132 bytes
//   0x063708: 8B010009  add      x9, x0, x1
//   0x06370c: EB00013F  cmp      x9, x0
//   0x063710: 540002E9  b.ls     #0x6376c
//   0x063714: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0161_0x063708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063708ULL ^ (static_cast<uint64_t>(0x8b010009ULL) << 13);
    acc = (acc + a1 + 0xeb00013fULL) ^ 0x1d2f58ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0162 | PC: 0x06378c | FDE: 0x1d2f70 | Size: 140 bytes [_Py_bytes_isdigit]
// Khung tháo gỡ #0162 | Địa chỉ PC: 0x06378c | Địa chỉ FDE: 0x1d2f70 | Kích thước: 140 bytes
//   0x06378c: B4000361  cbz      x1, #0x637f8
//   0x063790: AA0003E8  mov      x8, x0
//   0x063794: F100043F  cmp      x1, #1
//   0x063798: 540000C1  b.ne     #0x637b0
static inline uint64_t fde_func_0162_0x06378c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06378cULL ^ (static_cast<uint64_t>(0xb4000361ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d2f70ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0163 | PC: 0x063818 | FDE: 0x1d2f88 | Size: 144 bytes [_Py_bytes_islower]
// Khung tháo gỡ #0163 | Địa chỉ PC: 0x063818 | Địa chỉ FDE: 0x1d2f88 | Kích thước: 144 bytes
//   0x063818: B4000341  cbz      x1, #0x63880
//   0x06381c: F100043F  cmp      x1, #1
//   0x063820: 540000E1  b.ne     #0x6383c
//   0x063824: 90000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0163_0x063818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063818ULL ^ (static_cast<uint64_t>(0xb4000341ULL) << 13);
    acc = (acc + a1 + 0xf100043fULL) ^ 0x1d2f88ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0164 | PC: 0x0638a8 | FDE: 0x1d2fa0 | Size: 144 bytes [_Py_bytes_isupper]
// Khung tháo gỡ #0164 | Địa chỉ PC: 0x0638a8 | Địa chỉ FDE: 0x1d2fa0 | Kích thước: 144 bytes
//   0x0638a8: B4000341  cbz      x1, #0x63910
//   0x0638ac: F100043F  cmp      x1, #1
//   0x0638b0: 540000E1  b.ne     #0x638cc
//   0x0638b4: 90000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0164_0x0638a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0638a8ULL ^ (static_cast<uint64_t>(0xb4000341ULL) << 13);
    acc = (acc + a1 + 0xf100043fULL) ^ 0x1d2fa0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0165 | PC: 0x063938 | FDE: 0x1d2fb8 | Size: 168 bytes [_Py_bytes_istitle]
// Khung tháo gỡ #0165 | Địa chỉ PC: 0x063938 | Địa chỉ FDE: 0x1d2fb8 | Kích thước: 168 bytes
//   0x063938: B40003E1  cbz      x1, #0x639b4
//   0x06393c: F100043F  cmp      x1, #1
//   0x063940: 540000E1  b.ne     #0x6395c
//   0x063944: 90000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0165_0x063938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063938ULL ^ (static_cast<uint64_t>(0xb40003e1ULL) << 13);
    acc = (acc + a1 + 0xf100043fULL) ^ 0x1d2fb8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0166 | PC: 0x0639e0 | FDE: 0x1d2fd0 | Size: 40 bytes [_Py_bytes_lower]
// Khung tháo gỡ #0166 | Địa chỉ PC: 0x0639e0 | Địa chỉ FDE: 0x1d2fd0 | Kích thước: 40 bytes
//   0x0639e0: F100045F  cmp      x2, #1
//   0x0639e4: 5400010B  b.lt     #0x63a04
//   0x0639e8: 90000CE8  adrp     x8, #0x1ff000
//   0x0639ec: F947D508  ldr      x8, [x8, #0xfa8]
static inline uint64_t fde_func_0166_0x0639e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0639e0ULL ^ (static_cast<uint64_t>(0xf100045fULL) << 13);
    acc = (acc + a1 + 0x5400010bULL) ^ 0x1d2fd0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0167 | PC: 0x063a08 | FDE: 0x1d2fe8 | Size: 40 bytes [_Py_bytes_upper]
// Khung tháo gỡ #0167 | Địa chỉ PC: 0x063a08 | Địa chỉ FDE: 0x1d2fe8 | Kích thước: 40 bytes
//   0x063a08: F100045F  cmp      x2, #1
//   0x063a0c: 5400010B  b.lt     #0x63a2c
//   0x063a10: 90000CE8  adrp     x8, #0x1ff000
//   0x063a14: F947F508  ldr      x8, [x8, #0xfe8]
static inline uint64_t fde_func_0167_0x063a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063a08ULL ^ (static_cast<uint64_t>(0xf100045fULL) << 13);
    acc = (acc + a1 + 0x5400010bULL) ^ 0x1d2fe8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0168 | PC: 0x063a30 | FDE: 0x1d3000 | Size: 108 bytes [_Py_bytes_title]
// Khung tháo gỡ #0168 | Địa chỉ PC: 0x063a30 | Địa chỉ FDE: 0x1d3000 | Kích thước: 108 bytes
//   0x063a30: F100045F  cmp      x2, #1
//   0x063a34: 5400032B  b.lt     #0x63a98
//   0x063a38: 90000CE8  adrp     x8, #0x1ff000
//   0x063a3c: 90000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0168_0x063a30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063a30ULL ^ (static_cast<uint64_t>(0xf100045fULL) << 13);
    acc = (acc + a1 + 0x5400032bULL) ^ 0x1d3000ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0169 | PC: 0x063a9c | FDE: 0x1d3018 | Size: 68 bytes [_Py_bytes_capitalize]
// Khung tháo gỡ #0169 | Địa chỉ PC: 0x063a9c | Địa chỉ FDE: 0x1d3018 | Kích thước: 68 bytes
//   0x063a9c: F1000448  subs     x8, x2, #1
//   0x063aa0: 540001EB  b.lt     #0x63adc
//   0x063aa4: 90000CEA  adrp     x10, #0x1ff000
//   0x063aa8: 38401429  ldrb     w9, [x1], #1
static inline uint64_t fde_func_0169_0x063a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063a9cULL ^ (static_cast<uint64_t>(0xf1000448ULL) << 13);
    acc = (acc + a1 + 0x540001ebULL) ^ 0x1d3018ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0170 | PC: 0x063ae0 | FDE: 0x1d3030 | Size: 84 bytes [_Py_bytes_swapcase]
// Khung tháo gỡ #0170 | Địa chỉ PC: 0x063ae0 | Địa chỉ FDE: 0x1d3030 | Kích thước: 84 bytes
//   0x063ae0: F100045F  cmp      x2, #1
//   0x063ae4: 5400026B  b.lt     #0x63b30
//   0x063ae8: 90000CE8  adrp     x8, #0x1ff000
//   0x063aec: 90000CE9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0170_0x063ae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063ae0ULL ^ (static_cast<uint64_t>(0xf100045fULL) << 13);
    acc = (acc + a1 + 0x5400026bULL) ^ 0x1d3030ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0171 | PC: 0x063b34 | FDE: 0x1d3048 | Size: 256 bytes [_Py_bytes_maketrans]
// Khung tháo gỡ #0171 | Địa chỉ PC: 0x063b34 | Địa chỉ FDE: 0x1d3048 | Kích thước: 256 bytes
//   0x063b34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x063b38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063b3c: 910043FD  add      x29, sp, #0x10
//   0x063b40: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0171_0x063b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063b34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0172 | PC: 0x063c70 | FDE: 0x1d3068 | Size: 56 bytes [_Py_bytes_find]
// Khung tháo gỡ #0172 | Địa chỉ PC: 0x063c70 | Địa chỉ FDE: 0x1d3068 | Kích thước: 56 bytes
//   0x063c70: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x063c74: 910003FD  mov      x29, sp
//   0x063c78: AA0203E3  mov      x3, x2
//   0x063c7c: 90000A02  adrp     x2, #0x1a3000
static inline uint64_t fde_func_0172_0x063c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063c70ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d3068ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0173 | PC: 0x063ca8 | FDE: 0x1d3088 | Size: 256 bytes
// Khung tháo gỡ #0173 | Địa chỉ PC: 0x063ca8 | Địa chỉ FDE: 0x1d3088 | Kích thước: 256 bytes
//   0x063ca8: D10303FF  sub      sp, sp, #0xc0
//   0x063cac: F9003BF9  str      x25, [sp, #0x70]
//   0x063cb0: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x063cb4: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0173_0x063ca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063ca8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x1d3088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0174 | PC: 0x063f5c | FDE: 0x1d30b0 | Size: 88 bytes [_Py_bytes_index]
// Khung tháo gỡ #0174 | Địa chỉ PC: 0x063f5c | Địa chỉ FDE: 0x1d30b0 | Kích thước: 88 bytes
//   0x063f5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x063f60: 910003FD  mov      x29, sp
//   0x063f64: AA0203E3  mov      x3, x2
//   0x063f68: D0000AC2  adrp     x2, #0x1bd000
static inline uint64_t fde_func_0174_0x063f5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063f5cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d30b0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0175 | PC: 0x063fb4 | FDE: 0x1d30d0 | Size: 56 bytes [_Py_bytes_rfind]
// Khung tháo gỡ #0175 | Địa chỉ PC: 0x063fb4 | Địa chỉ FDE: 0x1d30d0 | Kích thước: 56 bytes
//   0x063fb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x063fb8: 910003FD  mov      x29, sp
//   0x063fbc: AA0203E3  mov      x3, x2
//   0x063fc0: 90000A02  adrp     x2, #0x1a3000
static inline uint64_t fde_func_0175_0x063fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063fb4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d30d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0176 | PC: 0x063fec | FDE: 0x1d30f0 | Size: 88 bytes [_Py_bytes_rindex]
// Khung tháo gỡ #0176 | Địa chỉ PC: 0x063fec | Địa chỉ FDE: 0x1d30f0 | Kích thước: 88 bytes
//   0x063fec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x063ff0: 910003FD  mov      x29, sp
//   0x063ff4: AA0203E3  mov      x3, x2
//   0x063ff8: 90000A02  adrp     x2, #0x1a3000
static inline uint64_t fde_func_0176_0x063fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063fecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d30f0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0177 | PC: 0x064044 | FDE: 0x1d3110 | Size: 256 bytes [_Py_bytes_count]
// Khung tháo gỡ #0177 | Địa chỉ PC: 0x064044 | Địa chỉ FDE: 0x1d3110 | Kích thước: 256 bytes
//   0x064044: D10283FF  sub      sp, sp, #0xa0
//   0x064048: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x06404c: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x064050: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0177_0x064044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064044ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x1d3110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0178 | PC: 0x064224 | FDE: 0x1d3138 | Size: 256 bytes [_Py_bytes_contains]
// Khung tháo gỡ #0178 | Địa chỉ PC: 0x064224 | Địa chỉ FDE: 0x1d3138 | Kích thước: 256 bytes
//   0x064224: D10243FF  sub      sp, sp, #0x90
//   0x064228: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x06422c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x064230: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0178_0x064224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064224ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x1d3138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0179 | PC: 0x06432c | FDE: 0x1d3160 | Size: 20 bytes [_Py_bytes_startswith]
// Khung tháo gỡ #0179 | Địa chỉ PC: 0x06432c | Địa chỉ FDE: 0x1d3160 | Kích thước: 20 bytes
//   0x06432c: AA0203E3  mov      x3, x2
//   0x064330: F00009E2  adrp     x2, #0x1a3000
//   0x064334: 9109D842  add      x2, x2, #0x276
//   0x064338: 12800004  mov      w4, #-1
static inline uint64_t fde_func_0179_0x06432c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06432cULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0xf00009e2ULL) ^ 0x1d3160ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0180 | PC: 0x064340 | FDE: 0x1d3178 | Size: 256 bytes
// Khung tháo gỡ #0180 | Địa chỉ PC: 0x064340 | Địa chỉ FDE: 0x1d3178 | Kích thước: 256 bytes
//   0x064340: D101C3FF  sub      sp, sp, #0x70
//   0x064344: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x064348: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06434c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0180_0x064340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064340ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1d3178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0181 | PC: 0x064498 | FDE: 0x1d31a8 | Size: 20 bytes [_Py_bytes_endswith]
// Khung tháo gỡ #0181 | Địa chỉ PC: 0x064498 | Địa chỉ FDE: 0x1d31a8 | Kích thước: 20 bytes
//   0x064498: AA0203E3  mov      x3, x2
//   0x06449c: F00009E2  adrp     x2, #0x1a3000
//   0x0644a0: 910A0442  add      x2, x2, #0x281
//   0x0644a4: 52800024  mov      w4, #1
static inline uint64_t fde_func_0181_0x064498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064498ULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0xf00009e2ULL) ^ 0x1d31a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0182 | PC: 0x0644ac | FDE: 0x1d31c0 | Size: 256 bytes
// Khung tháo gỡ #0182 | Địa chỉ PC: 0x0644ac | Địa chỉ FDE: 0x1d31c0 | Kích thước: 256 bytes
//   0x0644ac: D10343FF  sub      sp, sp, #0xd0
//   0x0644b0: F9003BFB  str      x27, [sp, #0x70]
//   0x0644b4: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0644b8: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0182_0x0644ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0644acULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1d31c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0183 | PC: 0x064a54 | FDE: 0x1d31f0 | Size: 256 bytes
// Khung tháo gỡ #0183 | Địa chỉ PC: 0x064a54 | Địa chỉ FDE: 0x1d31f0 | Kích thước: 256 bytes
//   0x064a54: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x064a58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x064a5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x064a60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0183_0x064a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064a54ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d31f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0184 | PC: 0x064c18 | FDE: 0x1d3218 | Size: 256 bytes
// Khung tháo gỡ #0184 | Địa chỉ PC: 0x064c18 | Địa chỉ FDE: 0x1d3218 | Kích thước: 256 bytes
//   0x064c18: A9402448  ldp      x8, x9, [x2]
//   0x064c1c: B940204D  ldr      w13, [x2, #0x20]
//   0x064c20: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x064c24: 8B01000C  add      x12, x0, x1
static inline uint64_t fde_func_0184_0x064c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064c18ULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1d3218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0185 | PC: 0x064ddc | FDE: 0x1d3230 | Size: 256 bytes
// Khung tháo gỡ #0185 | Địa chỉ PC: 0x064ddc | Địa chỉ FDE: 0x1d3230 | Kích thước: 256 bytes
//   0x064ddc: D10303FF  sub      sp, sp, #0xc0
//   0x064de0: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x064de4: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x064de8: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0185_0x064ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064ddcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x1d3230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0186 | PC: 0x064f14 | FDE: 0x1d3260 | Size: 256 bytes
// Khung tháo gỡ #0186 | Địa chỉ PC: 0x064f14 | Địa chỉ FDE: 0x1d3260 | Kích thước: 256 bytes
//   0x064f14: D102C3FF  sub      sp, sp, #0xb0
//   0x064f18: F90033F9  str      x25, [sp, #0x60]
//   0x064f1c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x064f20: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0186_0x064f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064f14ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x1d3260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0187 | PC: 0x065070 | FDE: 0x1d3288 | Size: 204 bytes [PyByteArray_FromObject]
// Khung tháo gỡ #0187 | Địa chỉ PC: 0x065070 | Địa chỉ FDE: 0x1d3288 | Kích thước: 204 bytes
//   0x065070: D10143FF  sub      sp, sp, #0x50
//   0x065074: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x065078: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06507c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0187_0x065070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065070ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d3288ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0188 | PC: 0x06513c | FDE: 0x1d32b0 | Size: 232 bytes [PyByteArray_FromStringAndSize]
// Khung tháo gỡ #0188 | Địa chỉ PC: 0x06513c | Địa chỉ FDE: 0x1d32b0 | Kích thước: 232 bytes
//   0x06513c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x065140: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065144: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x065148: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0188_0x06513c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06513cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d32b0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0189 | PC: 0x065224 | FDE: 0x1d32d8 | Size: 8 bytes [PyByteArray_Size]
// Khung tháo gỡ #0189 | Địa chỉ PC: 0x065224 | Địa chỉ FDE: 0x1d32d8 | Kích thước: 8 bytes
//   0x065224: F9400800  ldr      x0, [x0, #0x10]
//   0x065228: D65F03C0  ret      
static inline uint64_t fde_func_0189_0x065224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065224ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1d32d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0190 | PC: 0x06522c | FDE: 0x1d32f0 | Size: 28 bytes [PyByteArray_AsString]
// Khung tháo gỡ #0190 | Địa chỉ PC: 0x06522c | Địa chỉ FDE: 0x1d32f0 | Kích thước: 28 bytes
//   0x06522c: F9400808  ldr      x8, [x0, #0x10]
//   0x065230: B4000068  cbz      x8, #0x6523c
//   0x065234: F9401400  ldr      x0, [x0, #0x28]
//   0x065238: D65F03C0  ret      
static inline uint64_t fde_func_0190_0x06522c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06522cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x1d32f0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0191 | PC: 0x065248 | FDE: 0x1d3308 | Size: 256 bytes [PyByteArray_Resize]
// Khung tháo gỡ #0191 | Địa chỉ PC: 0x065248 | Địa chỉ FDE: 0x1d3308 | Kích thước: 256 bytes
//   0x065248: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06524c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065250: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x065254: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0191_0x065248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065248ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0192 | PC: 0x0653a0 | FDE: 0x1d3330 | Size: 256 bytes [PyByteArray_Concat]
// Khung tháo gỡ #0192 | Địa chỉ PC: 0x0653a0 | Địa chỉ FDE: 0x1d3330 | Kích thước: 256 bytes
//   0x0653a0: D10383FF  sub      sp, sp, #0xe0
//   0x0653a4: F9005BF5  str      x21, [sp, #0xb0]
//   0x0653a8: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x0653ac: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0192_0x0653a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0653a0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf5ULL) ^ 0x1d3330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0193 | PC: 0x0654dc | FDE: 0x1d3350 | Size: 92 bytes
// Khung tháo gỡ #0193 | Địa chỉ PC: 0x0654dc | Địa chỉ FDE: 0x1d3350 | Kích thước: 92 bytes
//   0x0654dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0654e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0654e4: 910043FD  add      x29, sp, #0x10
//   0x0654e8: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_0193_0x0654dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0654dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3350ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0194 | PC: 0x065538 | FDE: 0x1d3370 | Size: 256 bytes
// Khung tháo gỡ #0194 | Địa chỉ PC: 0x065538 | Địa chỉ FDE: 0x1d3370 | Kích thước: 256 bytes
//   0x065538: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06553c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065540: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x065544: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0194_0x065538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065538ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0195 | PC: 0x065784 | FDE: 0x1d3398 | Size: 92 bytes
// Khung tháo gỡ #0195 | Địa chỉ PC: 0x065784 | Địa chỉ FDE: 0x1d3398 | Kích thước: 92 bytes
//   0x065784: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065788: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06578c: 910043FD  add      x29, sp, #0x10
//   0x065790: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0195_0x065784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065784ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3398ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0196 | PC: 0x0657e0 | FDE: 0x1d33b8 | Size: 256 bytes
// Khung tháo gỡ #0196 | Địa chỉ PC: 0x0657e0 | Địa chỉ FDE: 0x1d33b8 | Kích thước: 256 bytes
//   0x0657e0: D103C3FF  sub      sp, sp, #0xf0
//   0x0657e4: F9005BF7  str      x23, [sp, #0xb0]
//   0x0657e8: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x0657ec: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_0196_0x0657e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0657e0ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf7ULL) ^ 0x1d33b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0197 | PC: 0x065a18 | FDE: 0x1d33e0 | Size: 124 bytes
// Khung tháo gỡ #0197 | Địa chỉ PC: 0x065a18 | Địa chỉ FDE: 0x1d33e0 | Kích thước: 124 bytes
//   0x065a18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065a20: 910043FD  add      x29, sp, #0x10
//   0x065a24: D0000CC8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0197_0x065a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065a18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d33e0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0198 | PC: 0x065a94 | FDE: 0x1d3400 | Size: 256 bytes
// Khung tháo gỡ #0198 | Địa chỉ PC: 0x065a94 | Địa chỉ FDE: 0x1d3400 | Kích thước: 256 bytes
//   0x065a94: D10383FF  sub      sp, sp, #0xe0
//   0x065a98: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x065a9c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x065aa0: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0198_0x065a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065a94ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1d3400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0199 | PC: 0x065fd0 | FDE: 0x1d3430 | Size: 60 bytes
// Khung tháo gỡ #0199 | Địa chỉ PC: 0x065fd0 | Địa chỉ FDE: 0x1d3430 | Kích thước: 60 bytes
//   0x065fd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065fd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065fd8: 910043FD  add      x29, sp, #0x10
//   0x065fdc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0199_0x065fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065fd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3430ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0200 | PC: 0x06600c | FDE: 0x1d3450 | Size: 52 bytes
// Khung tháo gỡ #0200 | Địa chỉ PC: 0x06600c | Địa chỉ FDE: 0x1d3450 | Kích thước: 52 bytes
//   0x06600c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x066010: 910003FD  mov      x29, sp
//   0x066014: F9400C00  ldr      x0, [x0, #0x18]
//   0x066018: B40000E0  cbz      x0, #0x66034
static inline uint64_t fde_func_0200_0x06600c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06600cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d3450ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0201 | PC: 0x066040 | FDE: 0x1d3470 | Size: 140 bytes
// Khung tháo gỡ #0201 | Địa chỉ PC: 0x066040 | Địa chỉ FDE: 0x1d3470 | Kích thước: 140 bytes
//   0x066040: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x066044: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x066048: 910043FD  add      x29, sp, #0x10
//   0x06604c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0201_0x066040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066040ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3470ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0202 | PC: 0x0660cc | FDE: 0x1d3490 | Size: 132 bytes
// Khung tháo gỡ #0202 | Địa chỉ PC: 0x0660cc | Địa chỉ FDE: 0x1d3490 | Kích thước: 132 bytes
//   0x0660cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0660d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0660d4: 910043FD  add      x29, sp, #0x10
//   0x0660d8: B0000CC8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0202_0x0660cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0660ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3490ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0203 | PC: 0x066150 | FDE: 0x1d34b0 | Size: 8 bytes
// Khung tháo gỡ #0203 | Địa chỉ PC: 0x066150 | Địa chỉ FDE: 0x1d34b0 | Kích thước: 8 bytes
//   0x066150: F9400800  ldr      x0, [x0, #0x10]
//   0x066154: D65F03C0  ret      
static inline uint64_t fde_func_0203_0x066150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066150ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1d34b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0204 | PC: 0x066158 | FDE: 0x1d34c8 | Size: 240 bytes
// Khung tháo gỡ #0204 | Địa chỉ PC: 0x066158 | Địa chỉ FDE: 0x1d34c8 | Kích thước: 240 bytes
//   0x066158: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06615c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x066160: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x066164: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0204_0x066158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066158ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d34c8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0205 | PC: 0x066248 | FDE: 0x1d34f0 | Size: 92 bytes
// Khung tháo gỡ #0205 | Địa chỉ PC: 0x066248 | Địa chỉ FDE: 0x1d34f0 | Kích thước: 92 bytes
//   0x066248: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06624c: 910003FD  mov      x29, sp
//   0x066250: B7F800E1  tbnz     x1, #0x3f, #0x6626c
//   0x066254: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0205_0x066248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066248ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d34f0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0206 | PC: 0x0662a4 | FDE: 0x1d3510 | Size: 256 bytes
// Khung tháo gỡ #0206 | Địa chỉ PC: 0x0662a4 | Địa chỉ FDE: 0x1d3510 | Kích thước: 256 bytes
//   0x0662a4: D10103FF  sub      sp, sp, #0x40
//   0x0662a8: F9000BF5  str      x21, [sp, #0x10]
//   0x0662ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0662b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0206_0x0662a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0662a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1d3510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0207 | PC: 0x0663c0 | FDE: 0x1d3530 | Size: 40 bytes
// Khung tháo gỡ #0207 | Địa chỉ PC: 0x0663c0 | Địa chỉ FDE: 0x1d3530 | Kích thước: 40 bytes
//   0x0663c0: F9400808  ldr      x8, [x0, #0x10]
//   0x0663c4: AA0103E2  mov      x2, x1
//   0x0663c8: B4000088  cbz      x8, #0x663d8
//   0x0663cc: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0207_0x0663c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0663c0ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3530ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0208 | PC: 0x0663e8 | FDE: 0x1d3548 | Size: 256 bytes
// Khung tháo gỡ #0208 | Địa chỉ PC: 0x0663e8 | Địa chỉ FDE: 0x1d3548 | Kích thước: 256 bytes
//   0x0663e8: D10243FF  sub      sp, sp, #0x90
//   0x0663ec: F90033F5  str      x21, [sp, #0x60]
//   0x0663f0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0663f4: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0208_0x0663e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0663e8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1d3548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0209 | PC: 0x066508 | FDE: 0x1d3568 | Size: 244 bytes
// Khung tháo gỡ #0209 | Địa chỉ PC: 0x066508 | Địa chỉ FDE: 0x1d3568 | Kích thước: 244 bytes
//   0x066508: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06650c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x066510: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x066514: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0209_0x066508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066508ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3568ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0210 | PC: 0x0665fc | FDE: 0x1d3590 | Size: 256 bytes
// Khung tháo gỡ #0210 | Địa chỉ PC: 0x0665fc | Địa chỉ FDE: 0x1d3590 | Kích thước: 256 bytes
//   0x0665fc: D10283FF  sub      sp, sp, #0xa0
//   0x066600: F90033F7  str      x23, [sp, #0x60]
//   0x066604: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x066608: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0210_0x0665fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0665fcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1d3590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0211 | PC: 0x06675c | FDE: 0x1d35b8 | Size: 256 bytes
// Khung tháo gỡ #0211 | Địa chỉ PC: 0x06675c | Địa chỉ FDE: 0x1d35b8 | Kích thước: 256 bytes
//   0x06675c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x066760: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x066764: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x066768: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0211_0x06675c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06675cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d35b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0212 | PC: 0x066910 | FDE: 0x1d35e0 | Size: 256 bytes
// Khung tháo gỡ #0212 | Địa chỉ PC: 0x066910 | Địa chỉ FDE: 0x1d35e0 | Kích thước: 256 bytes
//   0x066910: D10143FF  sub      sp, sp, #0x50
//   0x066914: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x066918: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06691c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0212_0x066910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066910ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d35e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0213 | PC: 0x066b18 | FDE: 0x1d3608 | Size: 256 bytes
// Khung tháo gỡ #0213 | Địa chỉ PC: 0x066b18 | Địa chỉ FDE: 0x1d3608 | Kích thước: 256 bytes
//   0x066b18: D10203FF  sub      sp, sp, #0x80
//   0x066b1c: F9001BF9  str      x25, [sp, #0x30]
//   0x066b20: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x066b24: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0213_0x066b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066b18ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1d3608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0214 | PC: 0x066fa4 | FDE: 0x1d3630 | Size: 124 bytes
// Khung tháo gỡ #0214 | Địa chỉ PC: 0x066fa4 | Địa chỉ FDE: 0x1d3630 | Kích thước: 124 bytes
//   0x066fa4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x066fa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x066fac: 910043FD  add      x29, sp, #0x10
//   0x066fb0: B40000E1  cbz      x1, #0x66fcc
static inline uint64_t fde_func_0214_0x066fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066fa4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3630ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0215 | PC: 0x067020 | FDE: 0x1d3650 | Size: 16 bytes
// Khung tháo gỡ #0215 | Địa chỉ PC: 0x067020 | Địa chỉ FDE: 0x1d3650 | Kích thước: 16 bytes
//   0x067020: F9401808  ldr      x8, [x0, #0x30]
//   0x067024: D1000508  sub      x8, x8, #1
//   0x067028: F9001808  str      x8, [x0, #0x30]
//   0x06702c: D65F03C0  ret      
static inline uint64_t fde_func_0215_0x067020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067020ULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0xd1000508ULL) ^ 0x1d3650ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0216 | PC: 0x067030 | FDE: 0x1d3668 | Size: 8 bytes
// Khung tháo gỡ #0216 | Địa chỉ PC: 0x067030 | Địa chỉ FDE: 0x1d3668 | Kích thước: 8 bytes
//   0x067030: F9400C00  ldr      x0, [x0, #0x18]
//   0x067034: 17FFCD93  b        #0x5a680
static inline uint64_t fde_func_0216_0x067030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067030ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0x17ffcd93ULL) ^ 0x1d3668ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0217 | PC: 0x067038 | FDE: 0x1d3680 | Size: 8 bytes
// Khung tháo gỡ #0217 | Địa chỉ PC: 0x067038 | Địa chỉ FDE: 0x1d3680 | Kích thước: 8 bytes
//   0x067038: 52800041  mov      w1, #2
//   0x06703c: 14001125  b        #0x6b4d0
static inline uint64_t fde_func_0217_0x067038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067038ULL ^ (static_cast<uint64_t>(0x52800041ULL) << 13);
    acc = (acc + a1 + 0x14001125ULL) ^ 0x1d3680ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0218 | PC: 0x067040 | FDE: 0x1d3698 | Size: 152 bytes
// Khung tháo gỡ #0218 | Địa chỉ PC: 0x067040 | Địa chỉ FDE: 0x1d3698 | Kích thước: 152 bytes
//   0x067040: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x067044: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x067048: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06704c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0218_0x067040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067040ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3698ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0219 | PC: 0x0670d8 | FDE: 0x1d36b8 | Size: 20 bytes
// Khung tháo gỡ #0219 | Địa chỉ PC: 0x0670d8 | Địa chỉ FDE: 0x1d36b8 | Kích thước: 20 bytes
//   0x0670d8: F9400408  ldr      x8, [x0, #8]
//   0x0670dc: F9400C09  ldr      x9, [x0, #0x18]
//   0x0670e0: F9401108  ldr      x8, [x8, #0x20]
//   0x0670e4: 8B080120  add      x0, x9, x8
static inline uint64_t fde_func_0219_0x0670d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0670d8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9400c09ULL) ^ 0x1d36b8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0220 | PC: 0x0670ec | FDE: 0x1d36d0 | Size: 252 bytes
// Khung tháo gỡ #0220 | Địa chỉ PC: 0x0670ec | Địa chỉ FDE: 0x1d36d0 | Kích thước: 252 bytes
//   0x0670ec: D10103FF  sub      sp, sp, #0x40
//   0x0670f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0670f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0670f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0220_0x0670ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0670ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d36d0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0221 | PC: 0x0671e8 | FDE: 0x1d36f8 | Size: 108 bytes
// Khung tháo gỡ #0221 | Địa chỉ PC: 0x0671e8 | Địa chỉ FDE: 0x1d36f8 | Kích thước: 108 bytes
//   0x0671e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0671ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0671f0: 910043FD  add      x29, sp, #0x10
//   0x0671f4: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0221_0x0671e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0671e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d36f8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0222 | PC: 0x067254 | FDE: 0x1d3718 | Size: 256 bytes
// Khung tháo gỡ #0222 | Địa chỉ PC: 0x067254 | Địa chỉ FDE: 0x1d3718 | Kích thước: 256 bytes
//   0x067254: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x067258: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06725c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x067260: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0222_0x067254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067254ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0223 | PC: 0x0673f4 | FDE: 0x1d3740 | Size: 60 bytes
// Khung tháo gỡ #0223 | Địa chỉ PC: 0x0673f4 | Địa chỉ FDE: 0x1d3740 | Kích thước: 60 bytes
//   0x0673f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0673f8: 910003FD  mov      x29, sp
//   0x0673fc: AA1F03E1  mov      x1, xzr
//   0x067400: 97FFC508  bl       #0x58820
static inline uint64_t fde_func_0223_0x0673f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0673f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d3740ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0224 | PC: 0x067430 | FDE: 0x1d3760 | Size: 28 bytes
// Khung tháo gỡ #0224 | Địa chỉ PC: 0x067430 | Địa chỉ FDE: 0x1d3760 | Kích thước: 28 bytes
//   0x067430: F9400801  ldr      x1, [x0, #0x10]
//   0x067434: B4000061  cbz      x1, #0x67440
//   0x067438: F9401400  ldr      x0, [x0, #0x28]
//   0x06743c: 17FFD225  b        #0x5bcd0
static inline uint64_t fde_func_0224_0x067430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067430ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3760ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0225 | PC: 0x06744c | FDE: 0x1d3778 | Size: 40 bytes
// Khung tháo gỡ #0225 | Địa chỉ PC: 0x06744c | Địa chỉ FDE: 0x1d3778 | Kích thước: 40 bytes
//   0x06744c: F9400808  ldr      x8, [x0, #0x10]
//   0x067450: AA0103E2  mov      x2, x1
//   0x067454: B4000088  cbz      x8, #0x67464
//   0x067458: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0225_0x06744c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06744cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3778ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0226 | PC: 0x067474 | FDE: 0x1d3790 | Size: 256 bytes
// Khung tháo gỡ #0226 | Địa chỉ PC: 0x067474 | Địa chỉ FDE: 0x1d3790 | Kích thước: 256 bytes
//   0x067474: D101C3FF  sub      sp, sp, #0x70
//   0x067478: F9001BF7  str      x23, [sp, #0x30]
//   0x06747c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x067480: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0226_0x067474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067474ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1d3790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0227 | PC: 0x067628 | FDE: 0x1d37b8 | Size: 40 bytes
// Khung tháo gỡ #0227 | Địa chỉ PC: 0x067628 | Địa chỉ FDE: 0x1d37b8 | Kích thước: 40 bytes
//   0x067628: F9400808  ldr      x8, [x0, #0x10]
//   0x06762c: AA0103E2  mov      x2, x1
//   0x067630: B4000088  cbz      x8, #0x67640
//   0x067634: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0227_0x067628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067628ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d37b8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0228 | PC: 0x067650 | FDE: 0x1d37d0 | Size: 256 bytes
// Khung tháo gỡ #0228 | Địa chỉ PC: 0x067650 | Địa chỉ FDE: 0x1d37d0 | Kích thước: 256 bytes
//   0x067650: D10203FF  sub      sp, sp, #0x80
//   0x067654: F90013FB  str      x27, [sp, #0x20]
//   0x067658: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06765c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0228_0x067650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067650ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1d37d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0229 | PC: 0x067910 | FDE: 0x1d3800 | Size: 256 bytes
// Khung tháo gỡ #0229 | Địa chỉ PC: 0x067910 | Địa chỉ FDE: 0x1d3800 | Kích thước: 256 bytes
//   0x067910: D10203FF  sub      sp, sp, #0x80
//   0x067914: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x067918: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06791c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0229_0x067910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067910ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1d3800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0230 | PC: 0x067c7c | FDE: 0x1d3830 | Size: 40 bytes
// Khung tháo gỡ #0230 | Địa chỉ PC: 0x067c7c | Địa chỉ FDE: 0x1d3830 | Kích thước: 40 bytes
//   0x067c7c: F9400808  ldr      x8, [x0, #0x10]
//   0x067c80: AA0103E2  mov      x2, x1
//   0x067c84: B4000088  cbz      x8, #0x67c94
//   0x067c88: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0230_0x067c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067c7cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3830ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0231 | PC: 0x067ca4 | FDE: 0x1d3848 | Size: 256 bytes
// Khung tháo gỡ #0231 | Địa chỉ PC: 0x067ca4 | Địa chỉ FDE: 0x1d3848 | Kích thước: 256 bytes
//   0x067ca4: D10183FF  sub      sp, sp, #0x60
//   0x067ca8: F90013F7  str      x23, [sp, #0x20]
//   0x067cac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x067cb0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0231_0x067ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067ca4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1d3848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0232 | PC: 0x067e08 | FDE: 0x1d3870 | Size: 256 bytes
// Khung tháo gỡ #0232 | Địa chỉ PC: 0x067e08 | Địa chỉ FDE: 0x1d3870 | Kích thước: 256 bytes
//   0x067e08: D10143FF  sub      sp, sp, #0x50
//   0x067e0c: F90013F5  str      x21, [sp, #0x20]
//   0x067e10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x067e14: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0232_0x067e08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067e08ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1d3870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0233 | PC: 0x067f28 | FDE: 0x1d3890 | Size: 40 bytes
// Khung tháo gỡ #0233 | Địa chỉ PC: 0x067f28 | Địa chỉ FDE: 0x1d3890 | Kích thước: 40 bytes
//   0x067f28: F9400808  ldr      x8, [x0, #0x10]
//   0x067f2c: AA0103E2  mov      x2, x1
//   0x067f30: B4000088  cbz      x8, #0x67f40
//   0x067f34: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0233_0x067f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067f28ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3890ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0234 | PC: 0x067f50 | FDE: 0x1d38a8 | Size: 256 bytes
// Khung tháo gỡ #0234 | Địa chỉ PC: 0x067f50 | Địa chỉ FDE: 0x1d38a8 | Kích thước: 256 bytes
//   0x067f50: D10143FF  sub      sp, sp, #0x50
//   0x067f54: F9000BF7  str      x23, [sp, #0x10]
//   0x067f58: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x067f5c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0234_0x067f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067f50ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1d38a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0235 | PC: 0x0680f8 | FDE: 0x1d38d0 | Size: 28 bytes
// Khung tháo gỡ #0235 | Địa chỉ PC: 0x0680f8 | Địa chỉ FDE: 0x1d38d0 | Kích thước: 28 bytes
//   0x0680f8: F9400801  ldr      x1, [x0, #0x10]
//   0x0680fc: B4000061  cbz      x1, #0x68108
//   0x068100: F9401400  ldr      x0, [x0, #0x28]
//   0x068104: 17FFD1FB  b        #0x5c8f0
static inline uint64_t fde_func_0235_0x0680f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0680f8ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d38d0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0236 | PC: 0x068114 | FDE: 0x1d38e8 | Size: 28 bytes
// Khung tháo gỡ #0236 | Địa chỉ PC: 0x068114 | Địa chỉ FDE: 0x1d38e8 | Kích thước: 28 bytes
//   0x068114: F9400801  ldr      x1, [x0, #0x10]
//   0x068118: B4000061  cbz      x1, #0x68124
//   0x06811c: F9401400  ldr      x0, [x0, #0x28]
//   0x068120: 17FFCAE8  b        #0x5acc0
static inline uint64_t fde_func_0236_0x068114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068114ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d38e8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0237 | PC: 0x068130 | FDE: 0x1d3900 | Size: 28 bytes
// Khung tháo gỡ #0237 | Địa chỉ PC: 0x068130 | Địa chỉ FDE: 0x1d3900 | Kích thước: 28 bytes
//   0x068130: F9400801  ldr      x1, [x0, #0x10]
//   0x068134: B4000061  cbz      x1, #0x68140
//   0x068138: F9401400  ldr      x0, [x0, #0x28]
//   0x06813c: 17FFC235  b        #0x58a10
static inline uint64_t fde_func_0237_0x068130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068130ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3900ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0238 | PC: 0x06814c | FDE: 0x1d3918 | Size: 28 bytes
// Khung tháo gỡ #0238 | Địa chỉ PC: 0x06814c | Địa chỉ FDE: 0x1d3918 | Kích thước: 28 bytes
//   0x06814c: F9400801  ldr      x1, [x0, #0x10]
//   0x068150: B4000061  cbz      x1, #0x6815c
//   0x068154: F9401400  ldr      x0, [x0, #0x28]
//   0x068158: 17FFCE9A  b        #0x5bbc0
static inline uint64_t fde_func_0238_0x06814c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06814cULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3918ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0239 | PC: 0x068168 | FDE: 0x1d3930 | Size: 28 bytes
// Khung tháo gỡ #0239 | Địa chỉ PC: 0x068168 | Địa chỉ FDE: 0x1d3930 | Kích thước: 28 bytes
//   0x068168: F9400801  ldr      x1, [x0, #0x10]
//   0x06816c: B4000061  cbz      x1, #0x68178
//   0x068170: F9401400  ldr      x0, [x0, #0x28]
//   0x068174: 17FFC137  b        #0x58650
static inline uint64_t fde_func_0239_0x068168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068168ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3930ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0240 | PC: 0x068184 | FDE: 0x1d3948 | Size: 28 bytes
// Khung tháo gỡ #0240 | Địa chỉ PC: 0x068184 | Địa chỉ FDE: 0x1d3948 | Kích thước: 28 bytes
//   0x068184: F9400801  ldr      x1, [x0, #0x10]
//   0x068188: B4000061  cbz      x1, #0x68194
//   0x06818c: F9401400  ldr      x0, [x0, #0x28]
//   0x068190: 17FFC1C4  b        #0x588a0
static inline uint64_t fde_func_0240_0x068184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068184ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3948ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0241 | PC: 0x0681a0 | FDE: 0x1d3960 | Size: 28 bytes
// Khung tháo gỡ #0241 | Địa chỉ PC: 0x0681a0 | Địa chỉ FDE: 0x1d3960 | Kích thước: 28 bytes
//   0x0681a0: F9400801  ldr      x1, [x0, #0x10]
//   0x0681a4: B4000061  cbz      x1, #0x681b0
//   0x0681a8: F9401400  ldr      x0, [x0, #0x28]
//   0x0681ac: 17FFD0A5  b        #0x5c440
static inline uint64_t fde_func_0241_0x0681a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0681a0ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3960ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0242 | PC: 0x0681bc | FDE: 0x1d3978 | Size: 28 bytes
// Khung tháo gỡ #0242 | Địa chỉ PC: 0x0681bc | Địa chỉ FDE: 0x1d3978 | Kích thước: 28 bytes
//   0x0681bc: F9400801  ldr      x1, [x0, #0x10]
//   0x0681c0: B4000061  cbz      x1, #0x681cc
//   0x0681c4: F9401400  ldr      x0, [x0, #0x28]
//   0x0681c8: 17FFC84E  b        #0x5a300
static inline uint64_t fde_func_0242_0x0681bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0681bcULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xb4000061ULL) ^ 0x1d3978ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0243 | PC: 0x0681d8 | FDE: 0x1d3990 | Size: 256 bytes
// Khung tháo gỡ #0243 | Địa chỉ PC: 0x0681d8 | Địa chỉ FDE: 0x1d3990 | Kích thước: 256 bytes
//   0x0681d8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0681dc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0681e0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0681e4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0243_0x0681d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0681d8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d3990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0244 | PC: 0x0685ec | FDE: 0x1d39c0 | Size: 256 bytes
// Khung tháo gỡ #0244 | Địa chỉ PC: 0x0685ec | Địa chỉ FDE: 0x1d39c0 | Kích thước: 256 bytes
//   0x0685ec: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0685f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0685f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0685f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0244_0x0685ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0685ecULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d39c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0245 | PC: 0x068778 | FDE: 0x1d39e8 | Size: 108 bytes
// Khung tháo gỡ #0245 | Địa chỉ PC: 0x068778 | Địa chỉ FDE: 0x1d39e8 | Kích thước: 108 bytes
//   0x068778: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06877c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x068780: 910043FD  add      x29, sp, #0x10
//   0x068784: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0245_0x068778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068778ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d39e8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0246 | PC: 0x0687e4 | FDE: 0x1d3a08 | Size: 256 bytes
// Khung tháo gỡ #0246 | Địa chỉ PC: 0x0687e4 | Địa chỉ FDE: 0x1d3a08 | Kích thước: 256 bytes
//   0x0687e4: D102C3FF  sub      sp, sp, #0xb0
//   0x0687e8: F90033F9  str      x25, [sp, #0x60]
//   0x0687ec: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0687f0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0246_0x0687e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0687e4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x1d3a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0247 | PC: 0x068938 | FDE: 0x1d3a30 | Size: 256 bytes
// Khung tháo gỡ #0247 | Địa chỉ PC: 0x068938 | Địa chỉ FDE: 0x1d3a30 | Kích thước: 256 bytes
//   0x068938: D10343FF  sub      sp, sp, #0xd0
//   0x06893c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x068940: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x068944: 910303FD  add      x29, sp, #0xc0
static inline uint64_t fde_func_0247_0x068938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068938ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90b4ff4ULL) ^ 0x1d3a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0248 | PC: 0x068a80 | FDE: 0x1d3a50 | Size: 256 bytes
// Khung tháo gỡ #0248 | Địa chỉ PC: 0x068a80 | Địa chỉ FDE: 0x1d3a50 | Kích thước: 256 bytes
//   0x068a80: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x068a84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x068a88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x068a8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0248_0x068a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a80ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0249 | PC: 0x068c00 | FDE: 0x1d3a78 | Size: 256 bytes
// Khung tháo gỡ #0249 | Địa chỉ PC: 0x068c00 | Địa chỉ FDE: 0x1d3a78 | Kích thước: 256 bytes
//   0x068c00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x068c04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x068c08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x068c0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0249_0x068c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c00ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0250 | PC: 0x068d50 | FDE: 0x1d3a98 | Size: 256 bytes
// Khung tháo gỡ #0250 | Địa chỉ PC: 0x068d50 | Địa chỉ FDE: 0x1d3a98 | Kích thước: 256 bytes
//   0x068d50: D10103FF  sub      sp, sp, #0x40
//   0x068d54: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x068d58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x068d5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0250_0x068d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068d50ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0251 | PC: 0x068ebc | FDE: 0x1d3ac0 | Size: 256 bytes
// Khung tháo gỡ #0251 | Địa chỉ PC: 0x068ebc | Địa chỉ FDE: 0x1d3ac0 | Kích thước: 256 bytes
//   0x068ebc: D10483FF  sub      sp, sp, #0x120
//   0x068ec0: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x068ec4: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x068ec8: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0251_0x068ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068ebcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1d3ac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0252 | PC: 0x069824 | FDE: 0x1d3af0 | Size: 256 bytes
// Khung tháo gỡ #0252 | Địa chỉ PC: 0x069824 | Địa chỉ FDE: 0x1d3af0 | Kích thước: 256 bytes
//   0x069824: D10283FF  sub      sp, sp, #0xa0
//   0x069828: F90033F7  str      x23, [sp, #0x60]
//   0x06982c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x069830: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0252_0x069824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069824ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1d3af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0253 | PC: 0x06994c | FDE: 0x1d3b18 | Size: 256 bytes
// Khung tháo gỡ #0253 | Địa chỉ PC: 0x06994c | Địa chỉ FDE: 0x1d3b18 | Kích thước: 256 bytes
//   0x06994c: D10243FF  sub      sp, sp, #0x90
//   0x069950: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x069954: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x069958: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0253_0x06994c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06994cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x1d3b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0254 | PC: 0x069a6c | FDE: 0x1d3b40 | Size: 88 bytes
// Khung tháo gỡ #0254 | Địa chỉ PC: 0x069a6c | Địa chỉ FDE: 0x1d3b40 | Kích thước: 88 bytes
//   0x069a6c: F940080A  ldr      x10, [x0, #0x10]
//   0x069a70: F100015F  cmp      x10, #0
//   0x069a74: 9A8AA549  cinc     x9, x10, lt
//   0x069a78: B40001AA  cbz      x10, #0x69aac
static inline uint64_t fde_func_0254_0x069a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069a6cULL ^ (static_cast<uint64_t>(0xf940080aULL) << 13);
    acc = (acc + a1 + 0xf100015fULL) ^ 0x1d3b40ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0255 | PC: 0x069ac4 | FDE: 0x1d3b58 | Size: 40 bytes
// Khung tháo gỡ #0255 | Địa chỉ PC: 0x069ac4 | Địa chỉ FDE: 0x1d3b58 | Kích thước: 40 bytes
//   0x069ac4: F9400808  ldr      x8, [x0, #0x10]
//   0x069ac8: AA0103E2  mov      x2, x1
//   0x069acc: B4000088  cbz      x8, #0x69adc
//   0x069ad0: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0255_0x069ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069ac4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3b58ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0256 | PC: 0x069aec | FDE: 0x1d3b70 | Size: 40 bytes
// Khung tháo gỡ #0256 | Địa chỉ PC: 0x069aec | Địa chỉ FDE: 0x1d3b70 | Kích thước: 40 bytes
//   0x069aec: F9400808  ldr      x8, [x0, #0x10]
//   0x069af0: AA0103E2  mov      x2, x1
//   0x069af4: B4000088  cbz      x8, #0x69b04
//   0x069af8: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0256_0x069aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069aecULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3b70ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0257 | PC: 0x069b14 | FDE: 0x1d3b88 | Size: 256 bytes
// Khung tháo gỡ #0257 | Địa chỉ PC: 0x069b14 | Địa chỉ FDE: 0x1d3b88 | Kích thước: 256 bytes
//   0x069b14: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x069b18: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x069b1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x069b20: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0257_0x069b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069b14ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3b88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0258 | PC: 0x069ca4 | FDE: 0x1d3bb0 | Size: 256 bytes
// Khung tháo gỡ #0258 | Địa chỉ PC: 0x069ca4 | Địa chỉ FDE: 0x1d3bb0 | Kích thước: 256 bytes
//   0x069ca4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x069ca8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x069cac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x069cb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0258_0x069ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069ca4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0259 | PC: 0x069e20 | FDE: 0x1d3bd8 | Size: 256 bytes
// Khung tháo gỡ #0259 | Địa chỉ PC: 0x069e20 | Địa chỉ FDE: 0x1d3bd8 | Kích thước: 256 bytes
//   0x069e20: D10383FF  sub      sp, sp, #0xe0
//   0x069e24: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x069e28: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x069e2c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0259_0x069e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069e20ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1d3bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0260 | PC: 0x06a420 | FDE: 0x1d3c08 | Size: 256 bytes
// Khung tháo gỡ #0260 | Địa chỉ PC: 0x06a420 | Địa chỉ FDE: 0x1d3c08 | Kích thước: 256 bytes
//   0x06a420: D10283FF  sub      sp, sp, #0xa0
//   0x06a424: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x06a428: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x06a42c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0260_0x06a420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a420ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1d3c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0261 | PC: 0x06a550 | FDE: 0x1d3c30 | Size: 256 bytes
// Khung tháo gỡ #0261 | Địa chỉ PC: 0x06a550 | Địa chỉ FDE: 0x1d3c30 | Kích thước: 256 bytes
//   0x06a550: D10383FF  sub      sp, sp, #0xe0
//   0x06a554: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x06a558: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x06a55c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0261_0x06a550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a550ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1d3c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0262 | PC: 0x06ab9c | FDE: 0x1d3c60 | Size: 256 bytes
// Khung tháo gỡ #0262 | Địa chỉ PC: 0x06ab9c | Địa chỉ FDE: 0x1d3c60 | Kích thước: 256 bytes
//   0x06ab9c: D101C3FF  sub      sp, sp, #0x70
//   0x06aba0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06aba4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06aba8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0262_0x06ab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab9cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1d3c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0263 | PC: 0x06ad94 | FDE: 0x1d3c90 | Size: 40 bytes
// Khung tháo gỡ #0263 | Địa chỉ PC: 0x06ad94 | Địa chỉ FDE: 0x1d3c90 | Kích thước: 40 bytes
//   0x06ad94: F9400808  ldr      x8, [x0, #0x10]
//   0x06ad98: AA0103E2  mov      x2, x1
//   0x06ad9c: B4000088  cbz      x8, #0x6adac
//   0x06ada0: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0263_0x06ad94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ad94ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x1d3c90ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0264 | PC: 0x06adbc | FDE: 0x1d3ca8 | Size: 256 bytes
// Khung tháo gỡ #0264 | Địa chỉ PC: 0x06adbc | Địa chỉ FDE: 0x1d3ca8 | Kích thước: 256 bytes
//   0x06adbc: D102C3FF  sub      sp, sp, #0xb0
//   0x06adc0: F90033F9  str      x25, [sp, #0x60]
//   0x06adc4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x06adc8: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0264_0x06adbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06adbcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x1d3ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0265 | PC: 0x06af44 | FDE: 0x1d3cd0 | Size: 108 bytes
// Khung tháo gỡ #0265 | Địa chỉ PC: 0x06af44 | Địa chỉ FDE: 0x1d3cd0 | Kích thước: 108 bytes
//   0x06af44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06af48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06af4c: 910043FD  add      x29, sp, #0x10
//   0x06af50: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0265_0x06af44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06af44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3cd0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0266 | PC: 0x06afb0 | FDE: 0x1d3cf0 | Size: 108 bytes
// Khung tháo gỡ #0266 | Địa chỉ PC: 0x06afb0 | Địa chỉ FDE: 0x1d3cf0 | Kích thước: 108 bytes
//   0x06afb0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06afb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06afb8: 910043FD  add      x29, sp, #0x10
//   0x06afbc: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0266_0x06afb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06afb0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3cf0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0267 | PC: 0x06b01c | FDE: 0x1d3d10 | Size: 256 bytes
// Khung tháo gỡ #0267 | Địa chỉ PC: 0x06b01c | Địa chỉ FDE: 0x1d3d10 | Kích thước: 256 bytes
//   0x06b01c: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x06b020: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06b024: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06b028: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0267_0x06b01c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b01cULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d3d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0268 | PC: 0x06b368 | FDE: 0x1d3d40 | Size: 108 bytes
// Khung tháo gỡ #0268 | Địa chỉ PC: 0x06b368 | Địa chỉ FDE: 0x1d3d40 | Kích thước: 108 bytes
//   0x06b368: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06b36c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06b370: 910043FD  add      x29, sp, #0x10
//   0x06b374: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0268_0x06b368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b368ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3d40ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0269 | PC: 0x06b3d4 | FDE: 0x1d3d60 | Size: 252 bytes
// Khung tháo gỡ #0269 | Địa chỉ PC: 0x06b3d4 | Địa chỉ FDE: 0x1d3d60 | Kích thước: 252 bytes
//   0x06b3d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06b3d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06b3dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06b3e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0269_0x06b3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b3d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3d60ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0270 | PC: 0x06b4d0 | FDE: 0x1d3d80 | Size: 256 bytes
// Khung tháo gỡ #0270 | Địa chỉ PC: 0x06b4d0 | Địa chỉ FDE: 0x1d3d80 | Kích thước: 256 bytes
//   0x06b4d0: D10103FF  sub      sp, sp, #0x40
//   0x06b4d4: F9000BF5  str      x21, [sp, #0x10]
//   0x06b4d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06b4dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0270_0x06b4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b4d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1d3d80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0271 | PC: 0x06b5f8 | FDE: 0x1d3da0 | Size: 256 bytes
// Khung tháo gỡ #0271 | Địa chỉ PC: 0x06b5f8 | Địa chỉ FDE: 0x1d3da0 | Kích thước: 256 bytes
//   0x06b5f8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x06b5fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06b600: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06b604: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0271_0x06b5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b5f8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d3da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0272 | PC: 0x06b730 | FDE: 0x1d3dc8 | Size: 192 bytes
// Khung tháo gỡ #0272 | Địa chỉ PC: 0x06b730 | Địa chỉ FDE: 0x1d3dc8 | Kích thước: 192 bytes
//   0x06b730: D10203FF  sub      sp, sp, #0x80
//   0x06b734: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x06b738: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x06b73c: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_0272_0x06b730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b730ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9064ff4ULL) ^ 0x1d3dc8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0273 | PC: 0x06b7f0 | FDE: 0x1d3de8 | Size: 256 bytes
// Khung tháo gỡ #0273 | Địa chỉ PC: 0x06b7f0 | Địa chỉ FDE: 0x1d3de8 | Kích thước: 256 bytes
//   0x06b7f0: D10343FF  sub      sp, sp, #0xd0
//   0x06b7f4: F9003BFB  str      x27, [sp, #0x70]
//   0x06b7f8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x06b7fc: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0273_0x06b7f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b7f0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1d3de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0274 | PC: 0x06bd9c | FDE: 0x1d3e18 | Size: 256 bytes
// Khung tháo gỡ #0274 | Địa chỉ PC: 0x06bd9c | Địa chỉ FDE: 0x1d3e18 | Kích thước: 256 bytes
//   0x06bd9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06bda0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06bda4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06bda8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0274_0x06bd9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bd9cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3e18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0275 | PC: 0x06bf60 | FDE: 0x1d3e40 | Size: 256 bytes
// Khung tháo gỡ #0275 | Địa chỉ PC: 0x06bf60 | Địa chỉ FDE: 0x1d3e40 | Kích thước: 256 bytes
//   0x06bf60: A9402448  ldp      x8, x9, [x2]
//   0x06bf64: B940204D  ldr      w13, [x2, #0x20]
//   0x06bf68: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x06bf6c: 8B01000C  add      x12, x0, x1
static inline uint64_t fde_func_0275_0x06bf60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bf60ULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1d3e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0276 | PC: 0x06c124 | FDE: 0x1d3e58 | Size: 36 bytes
// Khung tháo gỡ #0276 | Địa chỉ PC: 0x06c124 | Địa chỉ FDE: 0x1d3e58 | Kích thước: 36 bytes
//   0x06c124: F9400C08  ldr      x8, [x0, #0x18]
//   0x06c128: B40000C8  cbz      x8, #0x6c140
//   0x06c12c: F9400908  ldr      x8, [x8, #0x10]
//   0x06c130: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_0276_0x06c124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c124ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x1d3e58ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0277 | PC: 0x06c148 | FDE: 0x1d3e70 | Size: 84 bytes
// Khung tháo gỡ #0277 | Địa chỉ PC: 0x06c148 | Địa chỉ FDE: 0x1d3e70 | Kích thước: 84 bytes
//   0x06c148: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06c14c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06c150: 910043FD  add      x29, sp, #0x10
//   0x06c154: F9400C14  ldr      x20, [x0, #0x18]
static inline uint64_t fde_func_0277_0x06c148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c148ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3e70ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0278 | PC: 0x06c19c | FDE: 0x1d3e90 | Size: 120 bytes
// Khung tháo gỡ #0278 | Địa chỉ PC: 0x06c19c | Địa chỉ FDE: 0x1d3e90 | Kích thước: 120 bytes
//   0x06c19c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06c1a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06c1a4: 910043FD  add      x29, sp, #0x10
//   0x06c1a8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0278_0x06c19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c19cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3e90ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0279 | PC: 0x06c214 | FDE: 0x1d3eb0 | Size: 256 bytes [PyBytes_FromStringAndSize]
// Khung tháo gỡ #0279 | Địa chỉ PC: 0x06c214 | Địa chỉ FDE: 0x1d3eb0 | Kích thước: 256 bytes
//   0x06c214: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06c218: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c21c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c220: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0279_0x06c214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c214ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0280 | PC: 0x06c38c | FDE: 0x1d3ed0 | Size: 256 bytes [PyBytes_FromString]
// Khung tháo gỡ #0280 | Địa chỉ PC: 0x06c38c | Địa chỉ FDE: 0x1d3ed0 | Kích thước: 256 bytes
//   0x06c38c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06c390: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c394: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c398: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0280_0x06c38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c38cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d3ed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0281 | PC: 0x06c4c0 | FDE: 0x1d3ef8 | Size: 256 bytes [PyBytes_FromFormatV]
// Khung tháo gỡ #0281 | Địa chỉ PC: 0x06c4c0 | Địa chỉ FDE: 0x1d3ef8 | Kích thước: 256 bytes
//   0x06c4c0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06c4c4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06c4c8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06c4cc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0281_0x06c4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c4c0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d3ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0282 | PC: 0x06cb58 | FDE: 0x1d3f28 | Size: 16 bytes [_PyBytesWriter_Init]
// Khung tháo gỡ #0282 | Địa chỉ PC: 0x06cb58 | Địa chỉ FDE: 0x1d3f28 | Kích thước: 16 bytes
//   0x06cb58: 6F00E400  movi     v0.2d, #0000000000000000
//   0x06cb5c: B900201F  str      wzr, [x0, #0x20]
//   0x06cb60: AD000000  stp      q0, q0, [x0]
//   0x06cb64: D65F03C0  ret      
static inline uint64_t fde_func_0282_0x06cb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cb58ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xb900201fULL) ^ 0x1d3f28ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0283 | PC: 0x06cb68 | FDE: 0x1d3f40 | Size: 160 bytes [_PyBytesWriter_Alloc]
// Khung tháo gỡ #0283 | Địa chỉ PC: 0x06cb68 | Địa chỉ FDE: 0x1d3f40 | Kích thước: 160 bytes
//   0x06cb68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06cb6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06cb70: 910043FD  add      x29, sp, #0x10
//   0x06cb74: 52800028  mov      w8, #1
static inline uint64_t fde_func_0283_0x06cb68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cb68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3f40ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0284 | PC: 0x06cc08 | FDE: 0x1d3f60 | Size: 164 bytes
// Khung tháo gỡ #0284 | Địa chỉ PC: 0x06cc08 | Địa chỉ FDE: 0x1d3f60 | Kích thước: 164 bytes
//   0x06cc08: D10483FF  sub      sp, sp, #0x120
//   0x06cc0c: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x06cc10: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x06cc14: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_0284_0x06cc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cc08ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1d3f60ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0285 | PC: 0x06ccac | FDE: 0x1d3f80 | Size: 200 bytes [_PyBytesWriter_WriteBytes]
// Khung tháo gỡ #0285 | Địa chỉ PC: 0x06ccac | Địa chỉ FDE: 0x1d3f80 | Kích thước: 200 bytes
//   0x06ccac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x06ccb0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06ccb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06ccb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0285_0x06ccac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ccacULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d3f80ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0286 | PC: 0x06cd74 | FDE: 0x1d3fa8 | Size: 256 bytes [_PyBytesWriter_Finish]
// Khung tháo gỡ #0286 | Địa chỉ PC: 0x06cd74 | Địa chỉ FDE: 0x1d3fa8 | Kích thước: 256 bytes
//   0x06cd74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06cd78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06cd7c: 910043FD  add      x29, sp, #0x10
//   0x06cd80: B9402008  ldr      w8, [x0, #0x20]
static inline uint64_t fde_func_0286_0x06cd74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cd74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d3fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0287 | PC: 0x06cecc | FDE: 0x1d3fc8 | Size: 40 bytes [_PyBytesWriter_Dealloc]
// Khung tháo gỡ #0287 | Địa chỉ PC: 0x06cecc | Địa chỉ FDE: 0x1d3fc8 | Kích thước: 40 bytes
//   0x06cecc: AA0003E8  mov      x8, x0
//   0x06ced0: F9400000  ldr      x0, [x0]
//   0x06ced4: B40000C0  cbz      x0, #0x6ceec
//   0x06ced8: F900011F  str      xzr, [x8]
static inline uint64_t fde_func_0287_0x06cecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ceccULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x1d3fc8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0288 | PC: 0x06cef4 | FDE: 0x1d3fe0 | Size: 152 bytes [PyBytes_FromFormat]
// Khung tháo gỡ #0288 | Địa chỉ PC: 0x06cef4 | Địa chỉ FDE: 0x1d3fe0 | Kích thước: 152 bytes
//   0x06cef4: D104C3FF  sub      sp, sp, #0x130
//   0x06cef8: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x06cefc: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x06cf00: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_0288_0x06cef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cef4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1d3fe0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0289 | PC: 0x06cf8c | FDE: 0x1d4000 | Size: 256 bytes [_PyBytes_FormatEx]
// Khung tháo gỡ #0289 | Địa chỉ PC: 0x06cf8c | Địa chỉ FDE: 0x1d4000 | Kích thước: 256 bytes
//   0x06cf8c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06cf90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06cf94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06cf98: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0289_0x06cf8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cf8cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d4000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0290 | PC: 0x06df88 | FDE: 0x1d4030 | Size: 256 bytes
// Khung tháo gỡ #0290 | Địa chỉ PC: 0x06df88 | Địa chỉ FDE: 0x1d4030 | Kích thước: 256 bytes
//   0x06df88: FC1B0FE8  str      d8, [sp, #-0x50]!
//   0x06df8c: F90007F9  str      x25, [sp, #8]
//   0x06df90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06df94: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_0290_0x06df88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06df88ULL ^ (static_cast<uint64_t>(0xfc1b0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f9ULL) ^ 0x1d4030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0291 | PC: 0x06e110 | FDE: 0x1d4060 | Size: 140 bytes [_PyBytesWriter_Prepare]
// Khung tháo gỡ #0291 | Địa chỉ PC: 0x06e110 | Địa chỉ FDE: 0x1d4060 | Kích thước: 140 bytes
//   0x06e110: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e114: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e118: 910043FD  add      x29, sp, #0x10
//   0x06e11c: B4000382  cbz      x2, #0x6e18c
static inline uint64_t fde_func_0291_0x06e110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e110ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4060ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0292 | PC: 0x06e19c | FDE: 0x1d4080 | Size: 256 bytes [_PyBytes_DecodeEscape]
// Khung tháo gỡ #0292 | Địa chỉ PC: 0x06e19c | Địa chỉ FDE: 0x1d4080 | Kích thước: 256 bytes
//   0x06e19c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06e1a0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06e1a4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06e1a8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0292_0x06e19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e19cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d4080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0293 | PC: 0x06e584 | FDE: 0x1d40b0 | Size: 116 bytes [PyBytes_DecodeEscape]
// Khung tháo gỡ #0293 | Địa chỉ PC: 0x06e584 | Địa chỉ FDE: 0x1d40b0 | Kích thước: 116 bytes
//   0x06e584: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06e588: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e58c: 910043FD  add      x29, sp, #0x10
//   0x06e590: 910023E3  add      x3, sp, #8
static inline uint64_t fde_func_0293_0x06e584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e584ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d40b0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0294 | PC: 0x06e5f8 | FDE: 0x1d40d0 | Size: 72 bytes [PyBytes_Size]
// Khung tháo gỡ #0294 | Địa chỉ PC: 0x06e5f8 | Địa chỉ FDE: 0x1d40d0 | Kích thước: 72 bytes
//   0x06e5f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06e5fc: 910003FD  mov      x29, sp
//   0x06e600: F9400408  ldr      x8, [x0, #8]
//   0x06e604: 3942AD09  ldrb     w9, [x8, #0xab]
static inline uint64_t fde_func_0294_0x06e5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e5f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d40d0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0295 | PC: 0x06e640 | FDE: 0x1d40f0 | Size: 72 bytes [PyBytes_AsString]
// Khung tháo gỡ #0295 | Địa chỉ PC: 0x06e640 | Địa chỉ FDE: 0x1d40f0 | Kích thước: 72 bytes
//   0x06e640: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06e644: 910003FD  mov      x29, sp
//   0x06e648: F9400408  ldr      x8, [x0, #8]
//   0x06e64c: 3942AD09  ldrb     w9, [x8, #0xab]
static inline uint64_t fde_func_0295_0x06e640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e640ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d40f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0296 | PC: 0x06e688 | FDE: 0x1d4110 | Size: 176 bytes [PyBytes_AsStringAndSize]
// Khung tháo gỡ #0296 | Địa chỉ PC: 0x06e688 | Địa chỉ FDE: 0x1d4110 | Kích thước: 176 bytes
//   0x06e688: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06e68c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e690: 910043FD  add      x29, sp, #0x10
//   0x06e694: B40001A1  cbz      x1, #0x6e6c8
static inline uint64_t fde_func_0296_0x06e688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e688ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4110ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0297 | PC: 0x06e738 | FDE: 0x1d4130 | Size: 256 bytes [PyBytes_Repr]
// Khung tháo gỡ #0297 | Địa chỉ PC: 0x06e738 | Địa chỉ FDE: 0x1d4130 | Kích thước: 256 bytes
//   0x06e738: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06e73c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06e740: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06e744: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0297_0x06e738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e738ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0298 | PC: 0x06e978 | FDE: 0x1d4150 | Size: 4 bytes [_PyBytes_Join]
// Khung tháo gỡ #0298 | Địa chỉ PC: 0x06e978 | Địa chỉ FDE: 0x1d4150 | Kích thước: 4 bytes
//   0x06e978: 14000001  b        #0x6e97c
static inline uint64_t fde_func_0298_0x06e978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e978ULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xa9ba6ffcULL) ^ 0x1d4150ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0299 | PC: 0x06e97c | FDE: 0x1d4168 | Size: 256 bytes
// Khung tháo gỡ #0299 | Địa chỉ PC: 0x06e97c | Địa chỉ FDE: 0x1d4168 | Kích thước: 256 bytes
//   0x06e97c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06e980: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06e984: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06e988: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0299_0x06e97c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e97cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d4168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0300 | PC: 0x06edcc | FDE: 0x1d4198 | Size: 256 bytes [_PyBytes_FromHex]
// Khung tháo gỡ #0300 | Địa chỉ PC: 0x06edcc | Địa chỉ FDE: 0x1d4198 | Kích thước: 256 bytes
//   0x06edcc: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x06edd0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06edd4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06edd8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0300_0x06edcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06edccULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0301 | PC: 0x06f058 | FDE: 0x1d41c0 | Size: 256 bytes [PyBytes_FromObject]
// Khung tháo gỡ #0301 | Địa chỉ PC: 0x06f058 | Địa chỉ FDE: 0x1d41c0 | Kích thước: 256 bytes
//   0x06f058: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x06f05c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06f060: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06f064: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0301_0x06f058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f058ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d41c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0302 | PC: 0x06f53c | FDE: 0x1d41f0 | Size: 172 bytes
// Khung tháo gỡ #0302 | Địa chỉ PC: 0x06f53c | Địa chỉ FDE: 0x1d41f0 | Kích thước: 172 bytes
//   0x06f53c: D10203FF  sub      sp, sp, #0x80
//   0x06f540: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x06f544: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x06f548: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_0302_0x06f53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f53cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9064ff4ULL) ^ 0x1d41f0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0303 | PC: 0x06f5e8 | FDE: 0x1d4210 | Size: 8 bytes
// Khung tháo gỡ #0303 | Địa chỉ PC: 0x06f5e8 | Địa chỉ FDE: 0x1d4210 | Kích thước: 8 bytes
//   0x06f5e8: 52800021  mov      w1, #1
//   0x06f5ec: 17FFA539  b        #0x58ad0
static inline uint64_t fde_func_0303_0x06f5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f5e8ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x17ffa539ULL) ^ 0x1d4210ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0304 | PC: 0x06f5f0 | FDE: 0x1d4228 | Size: 56 bytes
// Khung tháo gỡ #0304 | Địa chỉ PC: 0x06f5f0 | Địa chỉ FDE: 0x1d4228 | Kích thước: 56 bytes
//   0x06f5f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f5f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f5f8: 910043FD  add      x29, sp, #0x10
//   0x06f5fc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0304_0x06f5f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f5f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4228ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0305 | PC: 0x06f628 | FDE: 0x1d4248 | Size: 96 bytes
// Khung tháo gỡ #0305 | Địa chỉ PC: 0x06f628 | Địa chỉ FDE: 0x1d4248 | Kích thước: 96 bytes
//   0x06f628: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f62c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f630: 910043FD  add      x29, sp, #0x10
//   0x06f634: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0305_0x06f628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f628ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4248ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0306 | PC: 0x06f688 | FDE: 0x1d4268 | Size: 256 bytes
// Khung tháo gỡ #0306 | Địa chỉ PC: 0x06f688 | Địa chỉ FDE: 0x1d4268 | Kích thước: 256 bytes
//   0x06f688: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x06f68c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06f690: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06f694: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0306_0x06f688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f688ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0307 | PC: 0x06f8fc | FDE: 0x1d4290 | Size: 100 bytes
// Khung tháo gỡ #0307 | Địa chỉ PC: 0x06f8fc | Địa chỉ FDE: 0x1d4290 | Kích thước: 100 bytes
//   0x06f8fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f900: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f904: 910043FD  add      x29, sp, #0x10
//   0x06f908: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0307_0x06f8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f8fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4290ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0308 | PC: 0x06f960 | FDE: 0x1d42b0 | Size: 256 bytes
// Khung tháo gỡ #0308 | Địa chỉ PC: 0x06f960 | Địa chỉ FDE: 0x1d42b0 | Kích thước: 256 bytes
//   0x06f960: D10243FF  sub      sp, sp, #0x90
//   0x06f964: F90023F9  str      x25, [sp, #0x40]
//   0x06f968: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x06f96c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0308_0x06f960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f960ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x1d42b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0309 | PC: 0x06fe74 | FDE: 0x1d42d8 | Size: 256 bytes [PyBytes_Concat]
// Khung tháo gỡ #0309 | Địa chỉ PC: 0x06fe74 | Địa chỉ FDE: 0x1d42d8 | Kích thước: 256 bytes
//   0x06fe74: D10243FF  sub      sp, sp, #0x90
//   0x06fe78: F90033F5  str      x21, [sp, #0x60]
//   0x06fe7c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x06fe80: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0309_0x06fe74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fe74ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1d42d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0310 | PC: 0x06ffdc | FDE: 0x1d42f8 | Size: 256 bytes [_PyBytes_Resize]
// Khung tháo gỡ #0310 | Địa chỉ PC: 0x06ffdc | Địa chỉ FDE: 0x1d42f8 | Kích thước: 256 bytes
//   0x06ffdc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06ffe0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06ffe4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06ffe8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0310_0x06ffdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ffdcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d42f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0311 | PC: 0x0701b4 | FDE: 0x1d4320 | Size: 256 bytes
// Khung tháo gỡ #0311 | Địa chỉ PC: 0x0701b4 | Địa chỉ FDE: 0x1d4320 | Kích thước: 256 bytes
//   0x0701b4: D10383FF  sub      sp, sp, #0xe0
//   0x0701b8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0701bc: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x0701c0: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0311_0x0701b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0701b4ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b57f6ULL) ^ 0x1d4320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0312 | PC: 0x070338 | FDE: 0x1d4348 | Size: 68 bytes [PyBytes_ConcatAndDel]
// Khung tháo gỡ #0312 | Địa chỉ PC: 0x070338 | Địa chỉ FDE: 0x1d4348 | Kích thước: 68 bytes
//   0x070338: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07033c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070340: 910043FD  add      x29, sp, #0x10
//   0x070344: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0312_0x070338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070338ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4348ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0313 | PC: 0x07037c | FDE: 0x1d4368 | Size: 172 bytes [_PyBytes_Init]
// Khung tháo gỡ #0313 | Địa chỉ PC: 0x07037c | Địa chỉ FDE: 0x1d4368 | Kích thước: 172 bytes
//   0x07037c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x070380: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x070384: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x070388: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0313_0x07037c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07037cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4368ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0314 | PC: 0x070428 | FDE: 0x1d4388 | Size: 148 bytes [_PyBytes_Fini]
// Khung tháo gỡ #0314 | Địa chỉ PC: 0x070428 | Địa chỉ FDE: 0x1d4388 | Kích thước: 148 bytes
//   0x070428: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07042c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x070430: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x070434: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0314_0x070428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070428ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4388ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0315 | PC: 0x0704bc | FDE: 0x1d43a8 | Size: 60 bytes
// Khung tháo gỡ #0315 | Địa chỉ PC: 0x0704bc | Địa chỉ FDE: 0x1d43a8 | Kích thước: 60 bytes
//   0x0704bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0704c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0704c4: 910043FD  add      x29, sp, #0x10
//   0x0704c8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0315_0x0704bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0704bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d43a8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0316 | PC: 0x0704f8 | FDE: 0x1d43c8 | Size: 52 bytes
// Khung tháo gỡ #0316 | Địa chỉ PC: 0x0704f8 | Địa chỉ FDE: 0x1d43c8 | Kích thước: 52 bytes
//   0x0704f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0704fc: 910003FD  mov      x29, sp
//   0x070500: F9400C00  ldr      x0, [x0, #0x18]
//   0x070504: B40000E0  cbz      x0, #0x70520
static inline uint64_t fde_func_0316_0x0704f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0704f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d43c8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0317 | PC: 0x07052c | FDE: 0x1d43e8 | Size: 96 bytes
// Khung tháo gỡ #0317 | Địa chỉ PC: 0x07052c | Địa chỉ FDE: 0x1d43e8 | Kích thước: 96 bytes
//   0x07052c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x070530: 910003FD  mov      x29, sp
//   0x070534: AA0003E8  mov      x8, x0
//   0x070538: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_0317_0x07052c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07052cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d43e8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0318 | PC: 0x07058c | FDE: 0x1d4408 | Size: 256 bytes [_PyBytesWriter_Resize]
// Khung tháo gỡ #0318 | Địa chỉ PC: 0x07058c | Địa chỉ FDE: 0x1d4408 | Kích thước: 256 bytes
//   0x07058c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x070590: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x070594: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x070598: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0318_0x07058c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07058cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0319 | PC: 0x070734 | FDE: 0x1d4430 | Size: 56 bytes
// Khung tháo gỡ #0319 | Địa chỉ PC: 0x070734 | Địa chỉ FDE: 0x1d4430 | Kích thước: 56 bytes
//   0x070734: F9400408  ldr      x8, [x0, #8]
//   0x070738: 3942AD08  ldrb     w8, [x8, #0xab]
//   0x07073c: 371800E8  tbnz     w8, #3, #0x70758
//   0x070740: F0000C60  adrp     x0, #0x1ff000
static inline uint64_t fde_func_0319_0x070734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070734ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x3942ad08ULL) ^ 0x1d4430ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0320 | PC: 0x07076c | FDE: 0x1d4448 | Size: 8 bytes
// Khung tháo gỡ #0320 | Địa chỉ PC: 0x07076c | Địa chỉ FDE: 0x1d4448 | Kích thước: 8 bytes
//   0x07076c: F9400800  ldr      x0, [x0, #0x10]
//   0x070770: D65F03C0  ret      
static inline uint64_t fde_func_0320_0x07076c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07076cULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1d4448ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0321 | PC: 0x070774 | FDE: 0x1d4460 | Size: 256 bytes
// Khung tháo gỡ #0321 | Địa chỉ PC: 0x070774 | Địa chỉ FDE: 0x1d4460 | Kích thước: 256 bytes
//   0x070774: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x070778: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07077c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x070780: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0321_0x070774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070774ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0322 | PC: 0x0708e8 | FDE: 0x1d4488 | Size: 76 bytes
// Khung tháo gỡ #0322 | Địa chỉ PC: 0x0708e8 | Địa chỉ FDE: 0x1d4488 | Kích thước: 76 bytes
//   0x0708e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0708ec: 910003FD  mov      x29, sp
//   0x0708f0: B7F80101  tbnz     x1, #0x3f, #0x70910
//   0x0708f4: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0322_0x0708e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0708e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d4488ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0323 | PC: 0x070934 | FDE: 0x1d44a8 | Size: 20 bytes
// Khung tháo gỡ #0323 | Địa chỉ PC: 0x070934 | Địa chỉ FDE: 0x1d44a8 | Kích thước: 20 bytes
//   0x070934: F9400808  ldr      x8, [x0, #0x10]
//   0x070938: 91008000  add      x0, x0, #0x20
//   0x07093c: AA0103E2  mov      x2, x1
//   0x070940: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0323_0x070934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070934ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d44a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0324 | PC: 0x070948 | FDE: 0x1d44c0 | Size: 256 bytes
// Khung tháo gỡ #0324 | Địa chỉ PC: 0x070948 | Địa chỉ FDE: 0x1d44c0 | Kích thước: 256 bytes
//   0x070948: D10143FF  sub      sp, sp, #0x50
//   0x07094c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x070950: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x070954: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0324_0x070948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070948ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d44c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0325 | PC: 0x070b58 | FDE: 0x1d44e8 | Size: 32 bytes
// Khung tháo gỡ #0325 | Địa chỉ PC: 0x070b58 | Địa chỉ FDE: 0x1d44e8 | Kích thước: 32 bytes
//   0x070b58: F9400803  ldr      x3, [x0, #0x10]
//   0x070b5c: AA0003E8  mov      x8, x0
//   0x070b60: 2A0203E5  mov      w5, w2
//   0x070b64: 91008002  add      x2, x0, #0x20
static inline uint64_t fde_func_0325_0x070b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070b58ULL ^ (static_cast<uint64_t>(0xf9400803ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d44e8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0326 | PC: 0x070b78 | FDE: 0x1d4500 | Size: 20 bytes
// Khung tháo gỡ #0326 | Địa chỉ PC: 0x070b78 | Địa chỉ FDE: 0x1d4500 | Kích thước: 20 bytes
//   0x070b78: F9400802  ldr      x2, [x0, #0x10]
//   0x070b7c: 91008001  add      x1, x0, #0x20
//   0x070b80: 900009A0  adrp     x0, #0x1a4000
//   0x070b84: 91069800  add      x0, x0, #0x1a6
static inline uint64_t fde_func_0326_0x070b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070b78ULL ^ (static_cast<uint64_t>(0xf9400802ULL) << 13);
    acc = (acc + a1 + 0x91008001ULL) ^ 0x1d4500ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0327 | PC: 0x070b8c | FDE: 0x1d4518 | Size: 68 bytes
// Khung tháo gỡ #0327 | Địa chỉ PC: 0x070b8c | Địa chỉ FDE: 0x1d4518 | Kích thước: 68 bytes
//   0x070b8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x070b90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070b94: 910043FD  add      x29, sp, #0x10
//   0x070b98: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0327_0x070b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070b8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4518ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0328 | PC: 0x070bd0 | FDE: 0x1d4538 | Size: 256 bytes
// Khung tháo gỡ #0328 | Địa chỉ PC: 0x070bd0 | Địa chỉ FDE: 0x1d4538 | Kích thước: 256 bytes
//   0x070bd0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x070bd4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x070bd8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x070bdc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0328_0x070bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070bd0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0329 | PC: 0x070d88 | FDE: 0x1d4560 | Size: 20 bytes
// Khung tháo gỡ #0329 | Địa chỉ PC: 0x070d88 | Địa chỉ FDE: 0x1d4560 | Kích thước: 20 bytes
//   0x070d88: F9400808  ldr      x8, [x0, #0x10]
//   0x070d8c: 91008000  add      x0, x0, #0x20
//   0x070d90: AA0103E2  mov      x2, x1
//   0x070d94: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0329_0x070d88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070d88ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4560ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0330 | PC: 0x070d9c | FDE: 0x1d4578 | Size: 256 bytes
// Khung tháo gỡ #0330 | Địa chỉ PC: 0x070d9c | Địa chỉ FDE: 0x1d4578 | Kích thước: 256 bytes
//   0x070d9c: D101C3FF  sub      sp, sp, #0x70
//   0x070da0: F9001BF7  str      x23, [sp, #0x30]
//   0x070da4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x070da8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0330_0x070d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070d9cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1d4578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0331 | PC: 0x070f40 | FDE: 0x1d45a0 | Size: 20 bytes
// Khung tháo gỡ #0331 | Địa chỉ PC: 0x070f40 | Địa chỉ FDE: 0x1d45a0 | Kích thước: 20 bytes
//   0x070f40: F9400808  ldr      x8, [x0, #0x10]
//   0x070f44: 91008000  add      x0, x0, #0x20
//   0x070f48: AA0103E2  mov      x2, x1
//   0x070f4c: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0331_0x070f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070f40ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d45a0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0332 | PC: 0x070f54 | FDE: 0x1d45b8 | Size: 256 bytes
// Khung tháo gỡ #0332 | Địa chỉ PC: 0x070f54 | Địa chỉ FDE: 0x1d45b8 | Kích thước: 256 bytes
//   0x070f54: D10203FF  sub      sp, sp, #0x80
//   0x070f58: F90013FB  str      x27, [sp, #0x20]
//   0x070f5c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x070f60: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0332_0x070f54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070f54ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1d45b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0333 | PC: 0x0711c8 | FDE: 0x1d45e8 | Size: 20 bytes
// Khung tháo gỡ #0333 | Địa chỉ PC: 0x0711c8 | Địa chỉ FDE: 0x1d45e8 | Kích thước: 20 bytes
//   0x0711c8: F9400808  ldr      x8, [x0, #0x10]
//   0x0711cc: 91008000  add      x0, x0, #0x20
//   0x0711d0: AA0103E2  mov      x2, x1
//   0x0711d4: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0333_0x0711c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0711c8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d45e8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0334 | PC: 0x0711dc | FDE: 0x1d4600 | Size: 256 bytes
// Khung tháo gỡ #0334 | Địa chỉ PC: 0x0711dc | Địa chỉ FDE: 0x1d4600 | Kích thước: 256 bytes
//   0x0711dc: D10183FF  sub      sp, sp, #0x60
//   0x0711e0: F90013F7  str      x23, [sp, #0x20]
//   0x0711e4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0711e8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0334_0x0711dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0711dcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1d4600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0335 | PC: 0x07133c | FDE: 0x1d4628 | Size: 256 bytes
// Khung tháo gỡ #0335 | Địa chỉ PC: 0x07133c | Địa chỉ FDE: 0x1d4628 | Kích thước: 256 bytes
//   0x07133c: D10143FF  sub      sp, sp, #0x50
//   0x071340: F90013F5  str      x21, [sp, #0x20]
//   0x071344: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x071348: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0335_0x07133c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07133cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1d4628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0336 | PC: 0x071448 | FDE: 0x1d4648 | Size: 20 bytes
// Khung tháo gỡ #0336 | Địa chỉ PC: 0x071448 | Địa chỉ FDE: 0x1d4648 | Kích thước: 20 bytes
//   0x071448: F9400808  ldr      x8, [x0, #0x10]
//   0x07144c: 91008000  add      x0, x0, #0x20
//   0x071450: AA0103E2  mov      x2, x1
//   0x071454: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0336_0x071448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071448ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4648ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0337 | PC: 0x07145c | FDE: 0x1d4660 | Size: 12 bytes
// Khung tháo gỡ #0337 | Địa chỉ PC: 0x07145c | Địa chỉ FDE: 0x1d4660 | Kích thước: 12 bytes
//   0x07145c: F9400801  ldr      x1, [x0, #0x10]
//   0x071460: 91008000  add      x0, x0, #0x20
//   0x071464: 17FFAD23  b        #0x5c8f0
static inline uint64_t fde_func_0337_0x07145c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07145cULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4660ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0338 | PC: 0x071468 | FDE: 0x1d4678 | Size: 12 bytes
// Khung tháo gỡ #0338 | Địa chỉ PC: 0x071468 | Địa chỉ FDE: 0x1d4678 | Kích thước: 12 bytes
//   0x071468: F9400801  ldr      x1, [x0, #0x10]
//   0x07146c: 91008000  add      x0, x0, #0x20
//   0x071470: 17FFA614  b        #0x5acc0
static inline uint64_t fde_func_0338_0x071468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071468ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4678ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0339 | PC: 0x071474 | FDE: 0x1d4690 | Size: 12 bytes
// Khung tháo gỡ #0339 | Địa chỉ PC: 0x071474 | Địa chỉ FDE: 0x1d4690 | Kích thước: 12 bytes
//   0x071474: F9400801  ldr      x1, [x0, #0x10]
//   0x071478: 91008000  add      x0, x0, #0x20
//   0x07147c: 17FF9D65  b        #0x58a10
static inline uint64_t fde_func_0339_0x071474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071474ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4690ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0340 | PC: 0x071480 | FDE: 0x1d46a8 | Size: 12 bytes
// Khung tháo gỡ #0340 | Địa chỉ PC: 0x071480 | Địa chỉ FDE: 0x1d46a8 | Kích thước: 12 bytes
//   0x071480: F9400801  ldr      x1, [x0, #0x10]
//   0x071484: 91008000  add      x0, x0, #0x20
//   0x071488: 17FFA9CE  b        #0x5bbc0
static inline uint64_t fde_func_0340_0x071480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071480ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d46a8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0341 | PC: 0x07148c | FDE: 0x1d46c0 | Size: 12 bytes
// Khung tháo gỡ #0341 | Địa chỉ PC: 0x07148c | Địa chỉ FDE: 0x1d46c0 | Kích thước: 12 bytes
//   0x07148c: F9400801  ldr      x1, [x0, #0x10]
//   0x071490: 91008000  add      x0, x0, #0x20
//   0x071494: 17FF9C6F  b        #0x58650
static inline uint64_t fde_func_0341_0x07148c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07148cULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d46c0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0342 | PC: 0x071498 | FDE: 0x1d46d8 | Size: 12 bytes
// Khung tháo gỡ #0342 | Địa chỉ PC: 0x071498 | Địa chỉ FDE: 0x1d46d8 | Kích thước: 12 bytes
//   0x071498: F9400801  ldr      x1, [x0, #0x10]
//   0x07149c: 91008000  add      x0, x0, #0x20
//   0x0714a0: 17FF9D00  b        #0x588a0
static inline uint64_t fde_func_0342_0x071498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071498ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d46d8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0343 | PC: 0x0714a4 | FDE: 0x1d46f0 | Size: 12 bytes
// Khung tháo gỡ #0343 | Địa chỉ PC: 0x0714a4 | Địa chỉ FDE: 0x1d46f0 | Kích thước: 12 bytes
//   0x0714a4: F9400801  ldr      x1, [x0, #0x10]
//   0x0714a8: 91008000  add      x0, x0, #0x20
//   0x0714ac: 17FFABE5  b        #0x5c440
static inline uint64_t fde_func_0343_0x0714a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0714a4ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d46f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0344 | PC: 0x0714b0 | FDE: 0x1d4708 | Size: 12 bytes
// Khung tháo gỡ #0344 | Địa chỉ PC: 0x0714b0 | Địa chỉ FDE: 0x1d4708 | Kích thước: 12 bytes
//   0x0714b0: F9400801  ldr      x1, [x0, #0x10]
//   0x0714b4: 91008000  add      x0, x0, #0x20
//   0x0714b8: 17FFA392  b        #0x5a300
static inline uint64_t fde_func_0344_0x0714b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0714b0ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4708ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0345 | PC: 0x0714bc | FDE: 0x1d4720 | Size: 256 bytes
// Khung tháo gỡ #0345 | Địa chỉ PC: 0x0714bc | Địa chỉ FDE: 0x1d4720 | Kích thước: 256 bytes
//   0x0714bc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0714c0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0714c4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0714c8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0345_0x0714bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0714bcULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0346 | PC: 0x071690 | FDE: 0x1d4748 | Size: 68 bytes
// Khung tháo gỡ #0346 | Địa chỉ PC: 0x071690 | Địa chỉ FDE: 0x1d4748 | Kích thước: 68 bytes
//   0x071690: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071694: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071698: 910043FD  add      x29, sp, #0x10
//   0x07169c: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0346_0x071690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071690ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4748ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0347 | PC: 0x0716d4 | FDE: 0x1d4768 | Size: 132 bytes
// Khung tháo gỡ #0347 | Địa chỉ PC: 0x0716d4 | Địa chỉ FDE: 0x1d4768 | Kích thước: 132 bytes
//   0x0716d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0716d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0716dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0716e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0347_0x0716d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0716d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4768ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0348 | PC: 0x071758 | FDE: 0x1d4788 | Size: 256 bytes
// Khung tháo gỡ #0348 | Địa chỉ PC: 0x071758 | Địa chỉ FDE: 0x1d4788 | Kích thước: 256 bytes
//   0x071758: D10343FF  sub      sp, sp, #0xd0
//   0x07175c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x071760: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x071764: 910303FD  add      x29, sp, #0xc0
static inline uint64_t fde_func_0348_0x071758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071758ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90b4ff4ULL) ^ 0x1d4788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0349 | PC: 0x0718a0 | FDE: 0x1d47a8 | Size: 256 bytes
// Khung tháo gỡ #0349 | Địa chỉ PC: 0x0718a0 | Địa chỉ FDE: 0x1d47a8 | Kích thước: 256 bytes
//   0x0718a0: D102C3FF  sub      sp, sp, #0xb0
//   0x0718a4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0718a8: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0718ac: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0349_0x0718a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0718a0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x1d47a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0350 | PC: 0x071a78 | FDE: 0x1d47d8 | Size: 256 bytes
// Khung tháo gỡ #0350 | Địa chỉ PC: 0x071a78 | Địa chỉ FDE: 0x1d47d8 | Kích thước: 256 bytes
//   0x071a78: D10483FF  sub      sp, sp, #0x120
//   0x071a7c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x071a80: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x071a84: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0350_0x071a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071a78ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1d47d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0351 | PC: 0x072378 | FDE: 0x1d4808 | Size: 256 bytes
// Khung tháo gỡ #0351 | Địa chỉ PC: 0x072378 | Địa chỉ FDE: 0x1d4808 | Kích thước: 256 bytes
//   0x072378: D10283FF  sub      sp, sp, #0xa0
//   0x07237c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x072380: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x072384: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0351_0x072378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072378ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1d4808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0352 | PC: 0x0724c8 | FDE: 0x1d4830 | Size: 256 bytes
// Khung tháo gỡ #0352 | Địa chỉ PC: 0x0724c8 | Địa chỉ FDE: 0x1d4830 | Kích thước: 256 bytes
//   0x0724c8: D10283FF  sub      sp, sp, #0xa0
//   0x0724cc: F90033F7  str      x23, [sp, #0x60]
//   0x0724d0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0724d4: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0352_0x0724c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0724c8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1d4830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0353 | PC: 0x072618 | FDE: 0x1d4858 | Size: 20 bytes
// Khung tháo gỡ #0353 | Địa chỉ PC: 0x072618 | Địa chỉ FDE: 0x1d4858 | Kích thước: 20 bytes
//   0x072618: F9400808  ldr      x8, [x0, #0x10]
//   0x07261c: 91008000  add      x0, x0, #0x20
//   0x072620: AA0103E2  mov      x2, x1
//   0x072624: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0353_0x072618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072618ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4858ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0354 | PC: 0x07262c | FDE: 0x1d4870 | Size: 20 bytes
// Khung tháo gỡ #0354 | Địa chỉ PC: 0x07262c | Địa chỉ FDE: 0x1d4870 | Kích thước: 20 bytes
//   0x07262c: F9400808  ldr      x8, [x0, #0x10]
//   0x072630: 91008000  add      x0, x0, #0x20
//   0x072634: AA0103E2  mov      x2, x1
//   0x072638: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0354_0x07262c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07262cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4870ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0355 | PC: 0x072640 | FDE: 0x1d4888 | Size: 256 bytes
// Khung tháo gỡ #0355 | Địa chỉ PC: 0x072640 | Địa chỉ FDE: 0x1d4888 | Kích thước: 256 bytes
//   0x072640: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x072644: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x072648: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07264c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0355_0x072640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072640ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0356 | PC: 0x072810 | FDE: 0x1d48b0 | Size: 256 bytes
// Khung tháo gỡ #0356 | Địa chỉ PC: 0x072810 | Địa chỉ FDE: 0x1d48b0 | Kích thước: 256 bytes
//   0x072810: D102C3FF  sub      sp, sp, #0xb0
//   0x072814: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x072818: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x07281c: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0356_0x072810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072810ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x1d48b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0357 | PC: 0x0729e8 | FDE: 0x1d48e0 | Size: 256 bytes
// Khung tháo gỡ #0357 | Địa chỉ PC: 0x0729e8 | Địa chỉ FDE: 0x1d48e0 | Kích thước: 256 bytes
//   0x0729e8: D103C3FF  sub      sp, sp, #0xf0
//   0x0729ec: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0729f0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0729f4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0357_0x0729e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0729e8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1d48e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0358 | PC: 0x073094 | FDE: 0x1d4910 | Size: 132 bytes
// Khung tháo gỡ #0358 | Địa chỉ PC: 0x073094 | Địa chỉ FDE: 0x1d4910 | Kích thước: 132 bytes
//   0x073094: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x073098: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07309c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0730a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0358_0x073094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073094ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4910ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0359 | PC: 0x073118 | FDE: 0x1d4930 | Size: 256 bytes
// Khung tháo gỡ #0359 | Địa chỉ PC: 0x073118 | Địa chỉ FDE: 0x1d4930 | Kích thước: 256 bytes
//   0x073118: D10403FF  sub      sp, sp, #0x100
//   0x07311c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x073120: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x073124: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0359_0x073118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073118ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1d4930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0360 | PC: 0x073854 | FDE: 0x1d4960 | Size: 256 bytes
// Khung tháo gỡ #0360 | Địa chỉ PC: 0x073854 | Địa chỉ FDE: 0x1d4960 | Kích thước: 256 bytes
//   0x073854: D10203FF  sub      sp, sp, #0x80
//   0x073858: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x07385c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x073860: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0360_0x073854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073854ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1d4960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0361 | PC: 0x073a8c | FDE: 0x1d4990 | Size: 20 bytes
// Khung tháo gỡ #0361 | Địa chỉ PC: 0x073a8c | Địa chỉ FDE: 0x1d4990 | Kích thước: 20 bytes
//   0x073a8c: F9400808  ldr      x8, [x0, #0x10]
//   0x073a90: 91008000  add      x0, x0, #0x20
//   0x073a94: AA0103E2  mov      x2, x1
//   0x073a98: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_0361_0x073a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073a8cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008000ULL) ^ 0x1d4990ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0362 | PC: 0x073aa0 | FDE: 0x1d49a8 | Size: 132 bytes
// Khung tháo gỡ #0362 | Địa chỉ PC: 0x073aa0 | Địa chỉ FDE: 0x1d49a8 | Kích thước: 132 bytes
//   0x073aa0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x073aa4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x073aa8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x073aac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0362_0x073aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073aa0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d49a8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0363 | PC: 0x073b24 | FDE: 0x1d49c8 | Size: 68 bytes
// Khung tháo gỡ #0363 | Địa chỉ PC: 0x073b24 | Địa chỉ FDE: 0x1d49c8 | Kích thước: 68 bytes
//   0x073b24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x073b28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073b2c: 910043FD  add      x29, sp, #0x10
//   0x073b30: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0363_0x073b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073b24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d49c8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0364 | PC: 0x073b68 | FDE: 0x1d49e8 | Size: 68 bytes
// Khung tháo gỡ #0364 | Địa chỉ PC: 0x073b68 | Địa chỉ FDE: 0x1d49e8 | Kích thước: 68 bytes
//   0x073b68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x073b6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073b70: 910043FD  add      x29, sp, #0x10
//   0x073b74: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0364_0x073b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073b68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d49e8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0365 | PC: 0x073bac | FDE: 0x1d4a08 | Size: 256 bytes
// Khung tháo gỡ #0365 | Địa chỉ PC: 0x073bac | Địa chỉ FDE: 0x1d4a08 | Kích thước: 256 bytes
//   0x073bac: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x073bb0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x073bb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x073bb8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0365_0x073bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073bacULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d4a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0366 | PC: 0x073f64 | FDE: 0x1d4a38 | Size: 68 bytes
// Khung tháo gỡ #0366 | Địa chỉ PC: 0x073f64 | Địa chỉ FDE: 0x1d4a38 | Kích thước: 68 bytes
//   0x073f64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x073f68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073f6c: 910043FD  add      x29, sp, #0x10
//   0x073f70: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0366_0x073f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073f64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0367 | PC: 0x073fa8 | FDE: 0x1d4a58 | Size: 256 bytes
// Khung tháo gỡ #0367 | Địa chỉ PC: 0x073fa8 | Địa chỉ FDE: 0x1d4a58 | Kích thước: 256 bytes
//   0x073fa8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x073fac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x073fb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x073fb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0367_0x073fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073fa8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4a58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0368 | PC: 0x07410c | FDE: 0x1d4a80 | Size: 256 bytes
// Khung tháo gỡ #0368 | Địa chỉ PC: 0x07410c | Địa chỉ FDE: 0x1d4a80 | Kích thước: 256 bytes
//   0x07410c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x074110: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x074114: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x074118: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0368_0x07410c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07410cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d4a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0369 | PC: 0x074218 | FDE: 0x1d4aa8 | Size: 256 bytes
// Khung tháo gỡ #0369 | Địa chỉ PC: 0x074218 | Địa chỉ FDE: 0x1d4aa8 | Kích thước: 256 bytes
//   0x074218: D10303FF  sub      sp, sp, #0xc0
//   0x07421c: F90033FB  str      x27, [sp, #0x60]
//   0x074220: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x074224: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0369_0x074218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074218ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fbULL) ^ 0x1d4aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0370 | PC: 0x07443c | FDE: 0x1d4ad8 | Size: 256 bytes
// Khung tháo gỡ #0370 | Địa chỉ PC: 0x07443c | Địa chỉ FDE: 0x1d4ad8 | Kích thước: 256 bytes
//   0x07443c: D10343FF  sub      sp, sp, #0xd0
//   0x074440: F9003BFB  str      x27, [sp, #0x70]
//   0x074444: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x074448: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0370_0x07443c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07443cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1d4ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0371 | PC: 0x0749e8 | FDE: 0x1d4b08 | Size: 256 bytes
// Khung tháo gỡ #0371 | Địa chỉ PC: 0x0749e8 | Địa chỉ FDE: 0x1d4b08 | Kích thước: 256 bytes
//   0x0749e8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0749ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0749f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0749f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0371_0x0749e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0749e8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0372 | PC: 0x074bac | FDE: 0x1d4b30 | Size: 256 bytes
// Khung tháo gỡ #0372 | Địa chỉ PC: 0x074bac | Địa chỉ FDE: 0x1d4b30 | Kích thước: 256 bytes
//   0x074bac: A9402448  ldp      x8, x9, [x2]
//   0x074bb0: B940204D  ldr      w13, [x2, #0x20]
//   0x074bb4: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x074bb8: 8B01000C  add      x12, x0, x1
static inline uint64_t fde_func_0372_0x074bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074bacULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1d4b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0373 | PC: 0x074d70 | FDE: 0x1d4b48 | Size: 32 bytes
// Khung tháo gỡ #0373 | Địa chỉ PC: 0x074d70 | Địa chỉ FDE: 0x1d4b48 | Kích thước: 32 bytes
//   0x074d70: F9400C08  ldr      x8, [x0, #0x18]
//   0x074d74: B40000A8  cbz      x8, #0x74d88
//   0x074d78: F9400908  ldr      x8, [x8, #0x10]
//   0x074d7c: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_0373_0x074d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074d70ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000a8ULL) ^ 0x1d4b48ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0374 | PC: 0x074d90 | FDE: 0x1d4b60 | Size: 84 bytes
// Khung tháo gỡ #0374 | Địa chỉ PC: 0x074d90 | Địa chỉ FDE: 0x1d4b60 | Kích thước: 84 bytes
//   0x074d90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074d94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074d98: 910043FD  add      x29, sp, #0x10
//   0x074d9c: F9400C14  ldr      x20, [x0, #0x18]
static inline uint64_t fde_func_0374_0x074d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074d90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4b60ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0375 | PC: 0x074de4 | FDE: 0x1d4b80 | Size: 120 bytes
// Khung tháo gỡ #0375 | Địa chỉ PC: 0x074de4 | Địa chỉ FDE: 0x1d4b80 | Kích thước: 120 bytes
//   0x074de4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074de8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074dec: 910043FD  add      x29, sp, #0x10
//   0x074df0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0375_0x074de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074de4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4b80ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0376 | PC: 0x074e5c | FDE: 0x1d4ba0 | Size: 208 bytes [_Py_CheckFunctionResult]
// Khung tháo gỡ #0376 | Địa chỉ PC: 0x074e5c | Địa chỉ FDE: 0x1d4ba0 | Kích thước: 208 bytes
//   0x074e5c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x074e60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x074e64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x074e68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0376_0x074e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074e5cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4ba0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0377 | PC: 0x074f2c | FDE: 0x1d4bc0 | Size: 128 bytes [_Py_CheckSlotResult]
// Khung tháo gỡ #0377 | Địa chỉ PC: 0x074f2c | Địa chỉ FDE: 0x1d4bc0 | Kích thước: 128 bytes
//   0x074f2c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x074f30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x074f34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x074f38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0377_0x074f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074f2cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4bc0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0378 | PC: 0x074fac | FDE: 0x1d4be0 | Size: 128 bytes [PyObject_CallNoArgs]
// Khung tháo gỡ #0378 | Địa chỉ PC: 0x074fac | Địa chỉ FDE: 0x1d4be0 | Kích thước: 128 bytes
//   0x074fac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074fb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074fb4: 910043FD  add      x29, sp, #0x10
//   0x074fb8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0378_0x074fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074facULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d4be0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0379 | PC: 0x07502c | FDE: 0x1d4c00 | Size: 256 bytes [_PyObject_FastCallDictTstate]
// Khung tháo gỡ #0379 | Địa chỉ PC: 0x07502c | Địa chỉ FDE: 0x1d4c00 | Kích thước: 256 bytes
//   0x07502c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x075030: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x075034: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x075038: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0379_0x07502c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07502cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d4c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0380 | PC: 0x07514c | FDE: 0x1d4c28 | Size: 256 bytes [_PyObject_MakeTpCall]
// Khung tháo gỡ #0380 | Địa chỉ PC: 0x07514c | Địa chỉ FDE: 0x1d4c28 | Kích thước: 256 bytes
//   0x07514c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x075150: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x075154: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x075158: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0380_0x07514c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07514cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d4c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0381 | PC: 0x0752e4 | FDE: 0x1d4c50 | Size: 256 bytes
// Khung tháo gỡ #0381 | Địa chỉ PC: 0x0752e4 | Địa chỉ FDE: 0x1d4c50 | Kích thước: 256 bytes
//   0x0752e4: D10203FF  sub      sp, sp, #0x80
//   0x0752e8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0752ec: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0752f0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0381_0x0752e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0752e4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1d4c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0382 | PC: 0x07549c | FDE: 0x1d4c80 | Size: 140 bytes
// Khung tháo gỡ #0382 | Địa chỉ PC: 0x07549c | Địa chỉ FDE: 0x1d4c80 | Kích thước: 140 bytes
//   0x07549c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0754a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0754a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0754a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0382_0x07549c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07549cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4c80ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0383 | PC: 0x075528 | FDE: 0x1d4ca8 | Size: 68 bytes [PyObject_VectorcallDict]
// Khung tháo gỡ #0383 | Địa chỉ PC: 0x075528 | Địa chỉ FDE: 0x1d4ca8 | Kích thước: 68 bytes
//   0x075528: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07552c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x075530: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x075534: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0383_0x075528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075528ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4ca8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0384 | PC: 0x07556c | FDE: 0x1d4cd0 | Size: 144 bytes [_PyStack_AsDict]
// Khung tháo gỡ #0384 | Địa chỉ PC: 0x07556c | Địa chỉ FDE: 0x1d4cd0 | Kích thước: 144 bytes
//   0x07556c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x075570: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x075574: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x075578: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0384_0x07556c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07556cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4cd0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0385 | PC: 0x0755fc | FDE: 0x1d4cf8 | Size: 256 bytes [PyVectorcall_Call]
// Khung tháo gỡ #0385 | Địa chỉ PC: 0x0755fc | Địa chỉ FDE: 0x1d4cf8 | Kích thước: 256 bytes
//   0x0755fc: D10143FF  sub      sp, sp, #0x50
//   0x075600: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x075604: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x075608: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0385_0x0755fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0755fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d4cf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0386 | PC: 0x07571c | FDE: 0x1d4d20 | Size: 256 bytes [_PyObject_Call]
// Khung tháo gỡ #0386 | Địa chỉ PC: 0x07571c | Địa chỉ FDE: 0x1d4d20 | Kích thước: 256 bytes
//   0x07571c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x075720: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x075724: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x075728: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0386_0x07571c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07571cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4d20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0387 | PC: 0x075828 | FDE: 0x1d4d48 | Size: 60 bytes [PyObject_Call]
// Khung tháo gỡ #0387 | Địa chỉ PC: 0x075828 | Địa chỉ FDE: 0x1d4d48 | Kích thước: 60 bytes
//   0x075828: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07582c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x075830: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x075834: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0387_0x075828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075828ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4d48ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0388 | PC: 0x075864 | FDE: 0x1d4d68 | Size: 60 bytes [PyCFunction_Call]
// Khung tháo gỡ #0388 | Địa chỉ PC: 0x075864 | Địa chỉ FDE: 0x1d4d68 | Kích thước: 60 bytes
//   0x075864: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x075868: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07586c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x075870: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0388_0x075864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075864ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4d68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0389 | PC: 0x0758a0 | FDE: 0x1d4d88 | Size: 104 bytes [_PyFunction_Vectorcall]
// Khung tháo gỡ #0389 | Địa chỉ PC: 0x0758a0 | Địa chỉ FDE: 0x1d4d88 | Kích thước: 104 bytes
//   0x0758a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0758a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0758a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0758ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0389_0x0758a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0758a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d4d88ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0390 | PC: 0x075908 | FDE: 0x1d4db0 | Size: 188 bytes [PyEval_CallObjectWithKeywords]
// Khung tháo gỡ #0390 | Địa chỉ PC: 0x075908 | Địa chỉ FDE: 0x1d4db0 | Kích thước: 188 bytes
//   0x075908: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07590c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x075910: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x075914: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0390_0x075908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075908ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4db0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0391 | PC: 0x0759c4 | FDE: 0x1d4dd0 | Size: 240 bytes [PyObject_CallObject]
// Khung tháo gỡ #0391 | Địa chỉ PC: 0x0759c4 | Địa chỉ FDE: 0x1d4dd0 | Kích thước: 240 bytes
//   0x0759c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0759c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0759cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0759d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0391_0x0759c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0759c4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d4dd0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0392 | PC: 0x075ab4 | FDE: 0x1d4df0 | Size: 240 bytes [_PyObject_Call_Prepend]
// Khung tháo gỡ #0392 | Địa chỉ PC: 0x075ab4 | Địa chỉ FDE: 0x1d4df0 | Kích thước: 240 bytes
//   0x075ab4: D10243FF  sub      sp, sp, #0x90
//   0x075ab8: F9001BFB  str      x27, [sp, #0x30]
//   0x075abc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x075ac0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0392_0x075ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075ab4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x1d4df0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0393 | PC: 0x075ba4 | FDE: 0x1d4e20 | Size: 188 bytes [PyObject_CallFunction]
// Khung tháo gỡ #0393 | Địa chỉ PC: 0x075ba4 | Địa chỉ FDE: 0x1d4e20 | Kích thước: 188 bytes
//   0x075ba4: D10503FF  sub      sp, sp, #0x140
//   0x075ba8: F90083FC  str      x28, [sp, #0x100]
//   0x075bac: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x075bb0: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0393_0x075ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075ba4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1d4e20ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0394 | PC: 0x075c60 | FDE: 0x1d4e48 | Size: 256 bytes
// Khung tháo gỡ #0394 | Địa chỉ PC: 0x075c60 | Địa chỉ FDE: 0x1d4e48 | Kích thước: 256 bytes
//   0x075c60: D102C3FF  sub      sp, sp, #0xb0
//   0x075c64: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x075c68: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x075c6c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0394_0x075c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075c60ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1d4e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0395 | PC: 0x075eac | FDE: 0x1d4e70 | Size: 188 bytes [PyEval_CallFunction]
// Khung tháo gỡ #0395 | Địa chỉ PC: 0x075eac | Địa chỉ FDE: 0x1d4e70 | Kích thước: 188 bytes
//   0x075eac: D10503FF  sub      sp, sp, #0x140
//   0x075eb0: F90083FC  str      x28, [sp, #0x100]
//   0x075eb4: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x075eb8: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0395_0x075eac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075eacULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1d4e70ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0396 | PC: 0x075f68 | FDE: 0x1d4e98 | Size: 188 bytes [_PyObject_CallFunction_SizeT]
// Khung tháo gỡ #0396 | Địa chỉ PC: 0x075f68 | Địa chỉ FDE: 0x1d4e98 | Kích thước: 188 bytes
//   0x075f68: D10503FF  sub      sp, sp, #0x140
//   0x075f6c: F90083FC  str      x28, [sp, #0x100]
//   0x075f70: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x075f74: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0396_0x075f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075f68ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1d4e98ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0397 | PC: 0x076024 | FDE: 0x1d4ec0 | Size: 256 bytes [PyObject_CallMethod]
// Khung tháo gỡ #0397 | Địa chỉ PC: 0x076024 | Địa chỉ FDE: 0x1d4ec0 | Kích thước: 256 bytes
//   0x076024: D10503FF  sub      sp, sp, #0x140
//   0x076028: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x07602c: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x076030: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0397_0x076024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076024ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1d4ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0398 | PC: 0x076154 | FDE: 0x1d4ee8 | Size: 156 bytes
// Khung tháo gỡ #0398 | Địa chỉ PC: 0x076154 | Địa chỉ FDE: 0x1d4ee8 | Kích thước: 156 bytes
//   0x076154: D10183FF  sub      sp, sp, #0x60
//   0x076158: F90013F7  str      x23, [sp, #0x20]
//   0x07615c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x076160: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0398_0x076154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076154ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1d4ee8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0399 | PC: 0x0761f0 | FDE: 0x1d4f10 | Size: 256 bytes [PyEval_CallMethod]
// Khung tháo gỡ #0399 | Địa chỉ PC: 0x0761f0 | Địa chỉ FDE: 0x1d4f10 | Kích thước: 256 bytes
//   0x0761f0: D10503FF  sub      sp, sp, #0x140
//   0x0761f4: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x0761f8: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0761fc: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0399_0x0761f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0761f0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1d4f10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x05d8f0(a0, a1);
        case 1: return fde_func_0001_0x05da70(a0, a1);
        case 2: return fde_func_0002_0x05db1c(a0, a1);
        case 3: return fde_func_0003_0x05dbfc(a0, a1);
        case 4: return fde_func_0004_0x05dd50(a0, a1);
        case 5: return fde_func_0005_0x05ddf4(a0, a1);
        case 6: return fde_func_0006_0x05dfb0(a0, a1);
        case 7: return fde_func_0007_0x05e130(a0, a1);
        case 8: return fde_func_0008_0x05e160(a0, a1);
        case 9: return fde_func_0009_0x05e198(a0, a1);
        case 10: return fde_func_0010_0x05e1d8(a0, a1);
        case 11: return fde_func_0011_0x05e258(a0, a1);
        case 12: return fde_func_0012_0x05e25c(a0, a1);
        case 13: return fde_func_0013_0x05e298(a0, a1);
        case 14: return fde_func_0014_0x05e4a8(a0, a1);
        case 15: return fde_func_0015_0x05e6c0(a0, a1);
        case 16: return fde_func_0016_0x05e790(a0, a1);
        case 17: return fde_func_0017_0x05e858(a0, a1);
        case 18: return fde_func_0018_0x05e96c(a0, a1);
        case 19: return fde_func_0019_0x05ea3c(a0, a1);
        case 20: return fde_func_0020_0x05eb30(a0, a1);
        case 21: return fde_func_0021_0x05ebfc(a0, a1);
        case 22: return fde_func_0022_0x05ec68(a0, a1);
        case 23: return fde_func_0023_0x05ec8c(a0, a1);
        case 24: return fde_func_0024_0x05ed0c(a0, a1);
        case 25: return fde_func_0025_0x05ed74(a0, a1);
        case 26: return fde_func_0026_0x05ed78(a0, a1);
        case 27: return fde_func_0027_0x05ee0c(a0, a1);
        case 28: return fde_func_0028_0x05ee10(a0, a1);
        case 29: return fde_func_0029_0x05eed4(a0, a1);
        case 30: return fde_func_0030_0x05ef20(a0, a1);
        case 31: return fde_func_0031_0x05efac(a0, a1);
        case 32: return fde_func_0032_0x05f008(a0, a1);
        case 33: return fde_func_0033_0x05f0a0(a0, a1);
        case 34: return fde_func_0034_0x05f0f0(a0, a1);
        case 35: return fde_func_0035_0x05f130(a0, a1);
        case 36: return fde_func_0036_0x05f16c(a0, a1);
        case 37: return fde_func_0037_0x05f284(a0, a1);
        case 38: return fde_func_0038_0x05f3a0(a0, a1);
        case 39: return fde_func_0039_0x05f668(a0, a1);
        case 40: return fde_func_0040_0x05f6c8(a0, a1);
        case 41: return fde_func_0041_0x05f784(a0, a1);
        case 42: return fde_func_0042_0x05f9c0(a0, a1);
        case 43: return fde_func_0043_0x05fa34(a0, a1);
        case 44: return fde_func_0044_0x05fa44(a0, a1);
        case 45: return fde_func_0045_0x05fb3c(a0, a1);
        case 46: return fde_func_0046_0x05fb4c(a0, a1);
        case 47: return fde_func_0047_0x05fb5c(a0, a1);
        case 48: return fde_func_0048_0x05fb6c(a0, a1);
        case 49: return fde_func_0049_0x05fb7c(a0, a1);
        case 50: return fde_func_0050_0x05fb8c(a0, a1);
        case 51: return fde_func_0051_0x05fb9c(a0, a1);
        case 52: return fde_func_0052_0x05fbb0(a0, a1);
        case 53: return fde_func_0053_0x05fca0(a0, a1);
        case 54: return fde_func_0054_0x05fcb4(a0, a1);
        case 55: return fde_func_0055_0x05fcc8(a0, a1);
        case 56: return fde_func_0056_0x05fcdc(a0, a1);
        case 57: return fde_func_0057_0x05fcf0(a0, a1);
        case 58: return fde_func_0058_0x05fd04(a0, a1);
        case 59: return fde_func_0059_0x05fd18(a0, a1);
        case 60: return fde_func_0060_0x05fdcc(a0, a1);
        case 61: return fde_func_0061_0x05ff20(a0, a1);
        case 62: return fde_func_0062_0x05fff0(a0, a1);
        case 63: return fde_func_0063_0x0600d8(a0, a1);
        case 64: return fde_func_0064_0x060178(a0, a1);
        case 65: return fde_func_0065_0x060264(a0, a1);
        case 66: return fde_func_0066_0x060274(a0, a1);
        case 67: return fde_func_0067_0x060284(a0, a1);
        case 68: return fde_func_0068_0x060294(a0, a1);
        case 69: return fde_func_0069_0x0602a8(a0, a1);
        case 70: return fde_func_0070_0x0602b8(a0, a1);
        case 71: return fde_func_0071_0x0602c4(a0, a1);
        case 72: return fde_func_0072_0x0604b8(a0, a1);
        case 73: return fde_func_0073_0x0604cc(a0, a1);
        case 74: return fde_func_0074_0x060558(a0, a1);
        case 75: return fde_func_0075_0x06056c(a0, a1);
        case 76: return fde_func_0076_0x060580(a0, a1);
        case 77: return fde_func_0077_0x060594(a0, a1);
        case 78: return fde_func_0078_0x0605a8(a0, a1);
        case 79: return fde_func_0079_0x0605bc(a0, a1);
        case 80: return fde_func_0080_0x0605d0(a0, a1);
        case 81: return fde_func_0081_0x0605e4(a0, a1);
        case 82: return fde_func_0082_0x0605f8(a0, a1);
        case 83: return fde_func_0083_0x0606c8(a0, a1);
        case 84: return fde_func_0084_0x060754(a0, a1);
        case 85: return fde_func_0085_0x060844(a0, a1);
        case 86: return fde_func_0086_0x060858(a0, a1);
        case 87: return fde_func_0087_0x06086c(a0, a1);
        case 88: return fde_func_0088_0x06090c(a0, a1);
        case 89: return fde_func_0089_0x060964(a0, a1);
        case 90: return fde_func_0090_0x0609bc(a0, a1);
        case 91: return fde_func_0091_0x060a14(a0, a1);
        case 92: return fde_func_0092_0x060a6c(a0, a1);
        case 93: return fde_func_0093_0x060a90(a0, a1);
        case 94: return fde_func_0094_0x060b94(a0, a1);
        case 95: return fde_func_0095_0x060c04(a0, a1);
        case 96: return fde_func_0096_0x060f50(a0, a1);
        case 97: return fde_func_0097_0x061120(a0, a1);
        case 98: return fde_func_0098_0x0611b4(a0, a1);
        case 99: return fde_func_0099_0x0611e0(a0, a1);
        case 100: return fde_func_0100_0x061260(a0, a1);
        case 101: return fde_func_0101_0x061264(a0, a1);
        case 102: return fde_func_0102_0x061344(a0, a1);
        case 103: return fde_func_0103_0x061444(a0, a1);
        case 104: return fde_func_0104_0x06152c(a0, a1);
        case 105: return fde_func_0105_0x061634(a0, a1);
        case 106: return fde_func_0106_0x0616e0(a0, a1);
        case 107: return fde_func_0107_0x061794(a0, a1);
        case 108: return fde_func_0108_0x061844(a0, a1);
        case 109: return fde_func_0109_0x061a18(a0, a1);
        case 110: return fde_func_0110_0x061ae4(a0, a1);
        case 111: return fde_func_0111_0x061b40(a0, a1);
        case 112: return fde_func_0112_0x061bc0(a0, a1);
        case 113: return fde_func_0113_0x061c90(a0, a1);
        case 114: return fde_func_0114_0x061e2c(a0, a1);
        case 115: return fde_func_0115_0x061e34(a0, a1);
        case 116: return fde_func_0116_0x061e68(a0, a1);
        case 117: return fde_func_0117_0x061e6c(a0, a1);
        case 118: return fde_func_0118_0x061e74(a0, a1);
        case 119: return fde_func_0119_0x061e9c(a0, a1);
        case 120: return fde_func_0120_0x061ea0(a0, a1);
        case 121: return fde_func_0121_0x061f08(a0, a1);
        case 122: return fde_func_0122_0x061f80(a0, a1);
        case 123: return fde_func_0123_0x061fbc(a0, a1);
        case 124: return fde_func_0124_0x061ff8(a0, a1);
        case 125: return fde_func_0125_0x062040(a0, a1);
        case 126: return fde_func_0126_0x062198(a0, a1);
        case 127: return fde_func_0127_0x0621e0(a0, a1);
        case 128: return fde_func_0128_0x062228(a0, a1);
        case 129: return fde_func_0129_0x062254(a0, a1);
        case 130: return fde_func_0130_0x0624c0(a0, a1);
        case 131: return fde_func_0131_0x0624ec(a0, a1);
        case 132: return fde_func_0132_0x06275c(a0, a1);
        case 133: return fde_func_0133_0x062760(a0, a1);
        case 134: return fde_func_0134_0x0628b0(a0, a1);
        case 135: return fde_func_0135_0x0628b4(a0, a1);
        case 136: return fde_func_0136_0x062954(a0, a1);
        case 137: return fde_func_0137_0x06297c(a0, a1);
        case 138: return fde_func_0138_0x062a34(a0, a1);
        case 139: return fde_func_0139_0x062a64(a0, a1);
        case 140: return fde_func_0140_0x062b40(a0, a1);
        case 141: return fde_func_0141_0x062c98(a0, a1);
        case 142: return fde_func_0142_0x062cd0(a0, a1);
        case 143: return fde_func_0143_0x062d34(a0, a1);
        case 144: return fde_func_0144_0x062e54(a0, a1);
        case 145: return fde_func_0145_0x062ed0(a0, a1);
        case 146: return fde_func_0146_0x062f08(a0, a1);
        case 147: return fde_func_0147_0x062f64(a0, a1);
        case 148: return fde_func_0148_0x063060(a0, a1);
        case 149: return fde_func_0149_0x0630ec(a0, a1);
        case 150: return fde_func_0150_0x0631f0(a0, a1);
        case 151: return fde_func_0151_0x06325c(a0, a1);
        case 152: return fde_func_0152_0x063284(a0, a1);
        case 153: return fde_func_0153_0x0632c8(a0, a1);
        case 154: return fde_func_0154_0x063388(a0, a1);
        case 155: return fde_func_0155_0x063424(a0, a1);
        case 156: return fde_func_0156_0x063484(a0, a1);
        case 157: return fde_func_0157_0x0634f4(a0, a1);
        case 158: return fde_func_0158_0x063554(a0, a1);
        case 159: return fde_func_0159_0x0635e0(a0, a1);
        case 160: return fde_func_0160_0x063674(a0, a1);
        case 161: return fde_func_0161_0x063708(a0, a1);
        case 162: return fde_func_0162_0x06378c(a0, a1);
        case 163: return fde_func_0163_0x063818(a0, a1);
        case 164: return fde_func_0164_0x0638a8(a0, a1);
        case 165: return fde_func_0165_0x063938(a0, a1);
        case 166: return fde_func_0166_0x0639e0(a0, a1);
        case 167: return fde_func_0167_0x063a08(a0, a1);
        case 168: return fde_func_0168_0x063a30(a0, a1);
        case 169: return fde_func_0169_0x063a9c(a0, a1);
        case 170: return fde_func_0170_0x063ae0(a0, a1);
        case 171: return fde_func_0171_0x063b34(a0, a1);
        case 172: return fde_func_0172_0x063c70(a0, a1);
        case 173: return fde_func_0173_0x063ca8(a0, a1);
        case 174: return fde_func_0174_0x063f5c(a0, a1);
        case 175: return fde_func_0175_0x063fb4(a0, a1);
        case 176: return fde_func_0176_0x063fec(a0, a1);
        case 177: return fde_func_0177_0x064044(a0, a1);
        case 178: return fde_func_0178_0x064224(a0, a1);
        case 179: return fde_func_0179_0x06432c(a0, a1);
        case 180: return fde_func_0180_0x064340(a0, a1);
        case 181: return fde_func_0181_0x064498(a0, a1);
        case 182: return fde_func_0182_0x0644ac(a0, a1);
        case 183: return fde_func_0183_0x064a54(a0, a1);
        case 184: return fde_func_0184_0x064c18(a0, a1);
        case 185: return fde_func_0185_0x064ddc(a0, a1);
        case 186: return fde_func_0186_0x064f14(a0, a1);
        case 187: return fde_func_0187_0x065070(a0, a1);
        case 188: return fde_func_0188_0x06513c(a0, a1);
        case 189: return fde_func_0189_0x065224(a0, a1);
        case 190: return fde_func_0190_0x06522c(a0, a1);
        case 191: return fde_func_0191_0x065248(a0, a1);
        case 192: return fde_func_0192_0x0653a0(a0, a1);
        case 193: return fde_func_0193_0x0654dc(a0, a1);
        case 194: return fde_func_0194_0x065538(a0, a1);
        case 195: return fde_func_0195_0x065784(a0, a1);
        case 196: return fde_func_0196_0x0657e0(a0, a1);
        case 197: return fde_func_0197_0x065a18(a0, a1);
        case 198: return fde_func_0198_0x065a94(a0, a1);
        case 199: return fde_func_0199_0x065fd0(a0, a1);
        case 200: return fde_func_0200_0x06600c(a0, a1);
        case 201: return fde_func_0201_0x066040(a0, a1);
        case 202: return fde_func_0202_0x0660cc(a0, a1);
        case 203: return fde_func_0203_0x066150(a0, a1);
        case 204: return fde_func_0204_0x066158(a0, a1);
        case 205: return fde_func_0205_0x066248(a0, a1);
        case 206: return fde_func_0206_0x0662a4(a0, a1);
        case 207: return fde_func_0207_0x0663c0(a0, a1);
        case 208: return fde_func_0208_0x0663e8(a0, a1);
        case 209: return fde_func_0209_0x066508(a0, a1);
        case 210: return fde_func_0210_0x0665fc(a0, a1);
        case 211: return fde_func_0211_0x06675c(a0, a1);
        case 212: return fde_func_0212_0x066910(a0, a1);
        case 213: return fde_func_0213_0x066b18(a0, a1);
        case 214: return fde_func_0214_0x066fa4(a0, a1);
        case 215: return fde_func_0215_0x067020(a0, a1);
        case 216: return fde_func_0216_0x067030(a0, a1);
        case 217: return fde_func_0217_0x067038(a0, a1);
        case 218: return fde_func_0218_0x067040(a0, a1);
        case 219: return fde_func_0219_0x0670d8(a0, a1);
        case 220: return fde_func_0220_0x0670ec(a0, a1);
        case 221: return fde_func_0221_0x0671e8(a0, a1);
        case 222: return fde_func_0222_0x067254(a0, a1);
        case 223: return fde_func_0223_0x0673f4(a0, a1);
        case 224: return fde_func_0224_0x067430(a0, a1);
        case 225: return fde_func_0225_0x06744c(a0, a1);
        case 226: return fde_func_0226_0x067474(a0, a1);
        case 227: return fde_func_0227_0x067628(a0, a1);
        case 228: return fde_func_0228_0x067650(a0, a1);
        case 229: return fde_func_0229_0x067910(a0, a1);
        case 230: return fde_func_0230_0x067c7c(a0, a1);
        case 231: return fde_func_0231_0x067ca4(a0, a1);
        case 232: return fde_func_0232_0x067e08(a0, a1);
        case 233: return fde_func_0233_0x067f28(a0, a1);
        case 234: return fde_func_0234_0x067f50(a0, a1);
        case 235: return fde_func_0235_0x0680f8(a0, a1);
        case 236: return fde_func_0236_0x068114(a0, a1);
        case 237: return fde_func_0237_0x068130(a0, a1);
        case 238: return fde_func_0238_0x06814c(a0, a1);
        case 239: return fde_func_0239_0x068168(a0, a1);
        case 240: return fde_func_0240_0x068184(a0, a1);
        case 241: return fde_func_0241_0x0681a0(a0, a1);
        case 242: return fde_func_0242_0x0681bc(a0, a1);
        case 243: return fde_func_0243_0x0681d8(a0, a1);
        case 244: return fde_func_0244_0x0685ec(a0, a1);
        case 245: return fde_func_0245_0x068778(a0, a1);
        case 246: return fde_func_0246_0x0687e4(a0, a1);
        case 247: return fde_func_0247_0x068938(a0, a1);
        case 248: return fde_func_0248_0x068a80(a0, a1);
        case 249: return fde_func_0249_0x068c00(a0, a1);
        case 250: return fde_func_0250_0x068d50(a0, a1);
        case 251: return fde_func_0251_0x068ebc(a0, a1);
        case 252: return fde_func_0252_0x069824(a0, a1);
        case 253: return fde_func_0253_0x06994c(a0, a1);
        case 254: return fde_func_0254_0x069a6c(a0, a1);
        case 255: return fde_func_0255_0x069ac4(a0, a1);
        case 256: return fde_func_0256_0x069aec(a0, a1);
        case 257: return fde_func_0257_0x069b14(a0, a1);
        case 258: return fde_func_0258_0x069ca4(a0, a1);
        case 259: return fde_func_0259_0x069e20(a0, a1);
        case 260: return fde_func_0260_0x06a420(a0, a1);
        case 261: return fde_func_0261_0x06a550(a0, a1);
        case 262: return fde_func_0262_0x06ab9c(a0, a1);
        case 263: return fde_func_0263_0x06ad94(a0, a1);
        case 264: return fde_func_0264_0x06adbc(a0, a1);
        case 265: return fde_func_0265_0x06af44(a0, a1);
        case 266: return fde_func_0266_0x06afb0(a0, a1);
        case 267: return fde_func_0267_0x06b01c(a0, a1);
        case 268: return fde_func_0268_0x06b368(a0, a1);
        case 269: return fde_func_0269_0x06b3d4(a0, a1);
        case 270: return fde_func_0270_0x06b4d0(a0, a1);
        case 271: return fde_func_0271_0x06b5f8(a0, a1);
        case 272: return fde_func_0272_0x06b730(a0, a1);
        case 273: return fde_func_0273_0x06b7f0(a0, a1);
        case 274: return fde_func_0274_0x06bd9c(a0, a1);
        case 275: return fde_func_0275_0x06bf60(a0, a1);
        case 276: return fde_func_0276_0x06c124(a0, a1);
        case 277: return fde_func_0277_0x06c148(a0, a1);
        case 278: return fde_func_0278_0x06c19c(a0, a1);
        case 279: return fde_func_0279_0x06c214(a0, a1);
        case 280: return fde_func_0280_0x06c38c(a0, a1);
        case 281: return fde_func_0281_0x06c4c0(a0, a1);
        case 282: return fde_func_0282_0x06cb58(a0, a1);
        case 283: return fde_func_0283_0x06cb68(a0, a1);
        case 284: return fde_func_0284_0x06cc08(a0, a1);
        case 285: return fde_func_0285_0x06ccac(a0, a1);
        case 286: return fde_func_0286_0x06cd74(a0, a1);
        case 287: return fde_func_0287_0x06cecc(a0, a1);
        case 288: return fde_func_0288_0x06cef4(a0, a1);
        case 289: return fde_func_0289_0x06cf8c(a0, a1);
        case 290: return fde_func_0290_0x06df88(a0, a1);
        case 291: return fde_func_0291_0x06e110(a0, a1);
        case 292: return fde_func_0292_0x06e19c(a0, a1);
        case 293: return fde_func_0293_0x06e584(a0, a1);
        case 294: return fde_func_0294_0x06e5f8(a0, a1);
        case 295: return fde_func_0295_0x06e640(a0, a1);
        case 296: return fde_func_0296_0x06e688(a0, a1);
        case 297: return fde_func_0297_0x06e738(a0, a1);
        case 298: return fde_func_0298_0x06e978(a0, a1);
        case 299: return fde_func_0299_0x06e97c(a0, a1);
        case 300: return fde_func_0300_0x06edcc(a0, a1);
        case 301: return fde_func_0301_0x06f058(a0, a1);
        case 302: return fde_func_0302_0x06f53c(a0, a1);
        case 303: return fde_func_0303_0x06f5e8(a0, a1);
        case 304: return fde_func_0304_0x06f5f0(a0, a1);
        case 305: return fde_func_0305_0x06f628(a0, a1);
        case 306: return fde_func_0306_0x06f688(a0, a1);
        case 307: return fde_func_0307_0x06f8fc(a0, a1);
        case 308: return fde_func_0308_0x06f960(a0, a1);
        case 309: return fde_func_0309_0x06fe74(a0, a1);
        case 310: return fde_func_0310_0x06ffdc(a0, a1);
        case 311: return fde_func_0311_0x0701b4(a0, a1);
        case 312: return fde_func_0312_0x070338(a0, a1);
        case 313: return fde_func_0313_0x07037c(a0, a1);
        case 314: return fde_func_0314_0x070428(a0, a1);
        case 315: return fde_func_0315_0x0704bc(a0, a1);
        case 316: return fde_func_0316_0x0704f8(a0, a1);
        case 317: return fde_func_0317_0x07052c(a0, a1);
        case 318: return fde_func_0318_0x07058c(a0, a1);
        case 319: return fde_func_0319_0x070734(a0, a1);
        case 320: return fde_func_0320_0x07076c(a0, a1);
        case 321: return fde_func_0321_0x070774(a0, a1);
        case 322: return fde_func_0322_0x0708e8(a0, a1);
        case 323: return fde_func_0323_0x070934(a0, a1);
        case 324: return fde_func_0324_0x070948(a0, a1);
        case 325: return fde_func_0325_0x070b58(a0, a1);
        case 326: return fde_func_0326_0x070b78(a0, a1);
        case 327: return fde_func_0327_0x070b8c(a0, a1);
        case 328: return fde_func_0328_0x070bd0(a0, a1);
        case 329: return fde_func_0329_0x070d88(a0, a1);
        case 330: return fde_func_0330_0x070d9c(a0, a1);
        case 331: return fde_func_0331_0x070f40(a0, a1);
        case 332: return fde_func_0332_0x070f54(a0, a1);
        case 333: return fde_func_0333_0x0711c8(a0, a1);
        case 334: return fde_func_0334_0x0711dc(a0, a1);
        case 335: return fde_func_0335_0x07133c(a0, a1);
        case 336: return fde_func_0336_0x071448(a0, a1);
        case 337: return fde_func_0337_0x07145c(a0, a1);
        case 338: return fde_func_0338_0x071468(a0, a1);
        case 339: return fde_func_0339_0x071474(a0, a1);
        case 340: return fde_func_0340_0x071480(a0, a1);
        case 341: return fde_func_0341_0x07148c(a0, a1);
        case 342: return fde_func_0342_0x071498(a0, a1);
        case 343: return fde_func_0343_0x0714a4(a0, a1);
        case 344: return fde_func_0344_0x0714b0(a0, a1);
        case 345: return fde_func_0345_0x0714bc(a0, a1);
        case 346: return fde_func_0346_0x071690(a0, a1);
        case 347: return fde_func_0347_0x0716d4(a0, a1);
        case 348: return fde_func_0348_0x071758(a0, a1);
        case 349: return fde_func_0349_0x0718a0(a0, a1);
        case 350: return fde_func_0350_0x071a78(a0, a1);
        case 351: return fde_func_0351_0x072378(a0, a1);
        case 352: return fde_func_0352_0x0724c8(a0, a1);
        case 353: return fde_func_0353_0x072618(a0, a1);
        case 354: return fde_func_0354_0x07262c(a0, a1);
        case 355: return fde_func_0355_0x072640(a0, a1);
        case 356: return fde_func_0356_0x072810(a0, a1);
        case 357: return fde_func_0357_0x0729e8(a0, a1);
        case 358: return fde_func_0358_0x073094(a0, a1);
        case 359: return fde_func_0359_0x073118(a0, a1);
        case 360: return fde_func_0360_0x073854(a0, a1);
        case 361: return fde_func_0361_0x073a8c(a0, a1);
        case 362: return fde_func_0362_0x073aa0(a0, a1);
        case 363: return fde_func_0363_0x073b24(a0, a1);
        case 364: return fde_func_0364_0x073b68(a0, a1);
        case 365: return fde_func_0365_0x073bac(a0, a1);
        case 366: return fde_func_0366_0x073f64(a0, a1);
        case 367: return fde_func_0367_0x073fa8(a0, a1);
        case 368: return fde_func_0368_0x07410c(a0, a1);
        case 369: return fde_func_0369_0x074218(a0, a1);
        case 370: return fde_func_0370_0x07443c(a0, a1);
        case 371: return fde_func_0371_0x0749e8(a0, a1);
        case 372: return fde_func_0372_0x074bac(a0, a1);
        case 373: return fde_func_0373_0x074d70(a0, a1);
        case 374: return fde_func_0374_0x074d90(a0, a1);
        case 375: return fde_func_0375_0x074de4(a0, a1);
        case 376: return fde_func_0376_0x074e5c(a0, a1);
        case 377: return fde_func_0377_0x074f2c(a0, a1);
        case 378: return fde_func_0378_0x074fac(a0, a1);
        case 379: return fde_func_0379_0x07502c(a0, a1);
        case 380: return fde_func_0380_0x07514c(a0, a1);
        case 381: return fde_func_0381_0x0752e4(a0, a1);
        case 382: return fde_func_0382_0x07549c(a0, a1);
        case 383: return fde_func_0383_0x075528(a0, a1);
        case 384: return fde_func_0384_0x07556c(a0, a1);
        case 385: return fde_func_0385_0x0755fc(a0, a1);
        case 386: return fde_func_0386_0x07571c(a0, a1);
        case 387: return fde_func_0387_0x075828(a0, a1);
        case 388: return fde_func_0388_0x075864(a0, a1);
        case 389: return fde_func_0389_0x0758a0(a0, a1);
        case 390: return fde_func_0390_0x075908(a0, a1);
        case 391: return fde_func_0391_0x0759c4(a0, a1);
        case 392: return fde_func_0392_0x075ab4(a0, a1);
        case 393: return fde_func_0393_0x075ba4(a0, a1);
        case 394: return fde_func_0394_0x075c60(a0, a1);
        case 395: return fde_func_0395_0x075eac(a0, a1);
        case 396: return fde_func_0396_0x075f68(a0, a1);
        case 397: return fde_func_0397_0x076024(a0, a1);
        case 398: return fde_func_0398_0x076154(a0, a1);
        case 399: return fde_func_0399_0x0761f0(a0, a1);
        default: return 0ULL;
    }
}