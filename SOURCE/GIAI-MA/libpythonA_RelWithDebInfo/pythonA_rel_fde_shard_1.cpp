// ============================================================================
// Clean-Room C++17 AArch64 Complementary FDE Shard 1/5 for libpythonA_RelWithDebInfo.so
// Phân mảnh Khung Tháo Gỡ (FDE) Bổ Sung AArch64 C++17 sạch 1/5 cho libpythonA_RelWithDebInfo.so
// Covers FDE indices [2000 .. 2463] out of 4,320 total FDEs
// Bao phủ chỉ số FDE [2000 .. 2463] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_rel_core.h"

// FDE #2000 | PC: 0x0d9174 | FDE: 0x1e1e38 | Size: 256 bytes [PyUnicode_FSDecoder]
// Khung tháo gỡ #2000 | Địa chỉ PC: 0x0d9174 | Địa chỉ FDE: 0x1e1e38 | Kích thước: 256 bytes
//   0x0d9174: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d9178: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d917c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d9180: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2000_0x0d9174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9174ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2001 | PC: 0x0d9444 | FDE: 0x1e1e60 | Size: 256 bytes [PyUnicode_AsUTF8AndSize]
// Khung tháo gỡ #2001 | Địa chỉ PC: 0x0d9444 | Địa chỉ FDE: 0x1e1e60 | Kích thước: 256 bytes
//   0x0d9444: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x0d9448: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d944c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d9450: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2001_0x0d9444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9444ULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e1e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2002 | PC: 0x0d967c | FDE: 0x1e1e88 | Size: 8 bytes [PyUnicode_AsUTF8]
// Khung tháo gỡ #2002 | Địa chỉ PC: 0x0d967c | Địa chỉ FDE: 0x1e1e88 | Kích thước: 8 bytes
//   0x0d967c: AA1F03E1  mov      x1, xzr
//   0x0d9680: 17FE0D2C  b        #0x5cb30
static inline uint64_t fde_func_2002_0x0d967c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d967cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fe0d2cULL) ^ 0x1e1e88ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2003 | PC: 0x0d9684 | FDE: 0x1e1ea0 | Size: 256 bytes [PyUnicode_AsUnicodeAndSize]
// Khung tháo gỡ #2003 | Địa chỉ PC: 0x0d9684 | Địa chỉ FDE: 0x1e1ea0 | Kích thước: 256 bytes
//   0x0d9684: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d9688: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d968c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d9690: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2003_0x0d9684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9684ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e1ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2004 | PC: 0x0d983c | FDE: 0x1e1ec8 | Size: 8 bytes [PyUnicode_AsUnicode]
// Khung tháo gỡ #2004 | Địa chỉ PC: 0x0d983c | Địa chỉ FDE: 0x1e1ec8 | Kích thước: 8 bytes
//   0x0d983c: AA1F03E1  mov      x1, xzr
//   0x0d9840: 17FDFE48  b        #0x59160
static inline uint64_t fde_func_2004_0x0d983c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d983cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fdfe48ULL) ^ 0x1e1ec8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2005 | PC: 0x0d9844 | FDE: 0x1e1ee0 | Size: 112 bytes [PyUnicode_GetSize]
// Khung tháo gỡ #2005 | Địa chỉ PC: 0x0d9844 | Địa chỉ FDE: 0x1e1ee0 | Kích thước: 112 bytes
//   0x0d9844: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d9848: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d984c: 910043FD  add      x29, sp, #0x10
//   0x0d9850: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2005_0x0d9844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9844ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1ee0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2006 | PC: 0x0d98b4 | FDE: 0x1e1f00 | Size: 80 bytes [PyUnicode_GetLength]
// Khung tháo gỡ #2006 | Địa chỉ PC: 0x0d98b4 | Địa chỉ FDE: 0x1e1f00 | Kích thước: 80 bytes
//   0x0d98b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d98b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d98bc: 910043FD  add      x29, sp, #0x10
//   0x0d98c0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2006_0x0d98b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d98b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1f00ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2007 | PC: 0x0d9904 | FDE: 0x1e1f20 | Size: 196 bytes [PyUnicode_ReadChar]
// Khung tháo gỡ #2007 | Địa chỉ PC: 0x0d9904 | Địa chỉ FDE: 0x1e1f20 | Kích thước: 196 bytes
//   0x0d9904: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d9908: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d990c: 910043FD  add      x29, sp, #0x10
//   0x0d9910: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2007_0x0d9904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9904ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1f20ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2008 | PC: 0x0d99c8 | FDE: 0x1e1f40 | Size: 256 bytes [PyUnicode_WriteChar]
// Khung tháo gỡ #2008 | Địa chỉ PC: 0x0d99c8 | Địa chỉ FDE: 0x1e1f40 | Kích thước: 256 bytes
//   0x0d99c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d99cc: 910003FD  mov      x29, sp
//   0x0d99d0: F9400408  ldr      x8, [x0, #8]
//   0x0d99d4: 3942AD09  ldrb     w9, [x8, #0xab]
static inline uint64_t fde_func_2008_0x0d99c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d99c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e1f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2009 | PC: 0x0d9b24 | FDE: 0x1e1f60 | Size: 8 bytes [PyUnicode_DecodeUTF7]
// Khung tháo gỡ #2009 | Địa chỉ PC: 0x0d9b24 | Địa chỉ FDE: 0x1e1f60 | Kích thước: 8 bytes
//   0x0d9b24: AA1F03E0  mov      x0, xzr
//   0x0d9b28: D65F03C0  ret      
static inline uint64_t fde_func_2009_0x0d9b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9b24ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e1f60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2010 | PC: 0x0d9b2c | FDE: 0x1e1f78 | Size: 256 bytes [PyUnicode_DecodeUTF7Stateful]
// Khung tháo gỡ #2010 | Địa chỉ PC: 0x0d9b2c | Địa chỉ FDE: 0x1e1f78 | Kích thước: 256 bytes
//   0x0d9b2c: D104C3FF  sub      sp, sp, #0x130
//   0x0d9b30: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0d9b34: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0d9b38: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_2010_0x0d9b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9b2cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1e1f78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2011 | PC: 0x0da440 | FDE: 0x1e1fa8 | Size: 256 bytes
// Khung tháo gỡ #2011 | Địa chỉ PC: 0x0da440 | Địa chỉ FDE: 0x1e1fa8 | Kích thước: 256 bytes
//   0x0da440: D10203FF  sub      sp, sp, #0x80
//   0x0da444: F90013FB  str      x27, [sp, #0x20]
//   0x0da448: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0da44c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2011_0x0da440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da440ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e1fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2012 | PC: 0x0da818 | FDE: 0x1e1fd8 | Size: 256 bytes [_PyUnicode_EncodeUTF7]
// Khung tháo gỡ #2012 | Địa chỉ PC: 0x0da818 | Địa chỉ FDE: 0x1e1fd8 | Kích thước: 256 bytes
//   0x0da818: D10203FF  sub      sp, sp, #0x80
//   0x0da81c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0da820: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0da824: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2012_0x0da818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da818ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e1fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2013 | PC: 0x0daac8 | FDE: 0x1e2008 | Size: 80 bytes [PyUnicode_EncodeUTF7]
// Khung tháo gỡ #2013 | Địa chỉ PC: 0x0daac8 | Địa chỉ FDE: 0x1e2008 | Kích thước: 80 bytes
//   0x0daac8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0daacc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0daad0: 910043FD  add      x29, sp, #0x10
//   0x0daad4: 97FDF877  bl       #0x58cb0
static inline uint64_t fde_func_2013_0x0daac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daac8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2008ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2014 | PC: 0x0dab18 | FDE: 0x1e2028 | Size: 16 bytes [PyUnicode_DecodeUTF8]
// Khung tháo gỡ #2014 | Địa chỉ PC: 0x0dab18 | Địa chỉ FDE: 0x1e2028 | Kích thước: 16 bytes
//   0x0dab18: AA0203E3  mov      x3, x2
//   0x0dab1c: 2A1F03E2  mov      w2, wzr
//   0x0dab20: AA1F03E4  mov      x4, xzr
//   0x0dab24: 17FFF54C  b        #0xd8054
static inline uint64_t fde_func_2014_0x0dab18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab18ULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x1e2028ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2015 | PC: 0x0dab28 | FDE: 0x1e2040 | Size: 256 bytes [_Py_DecodeUTF8Ex]
// Khung tháo gỡ #2015 | Địa chỉ PC: 0x0dab28 | Địa chỉ FDE: 0x1e2040 | Kích thước: 256 bytes
//   0x0dab28: D101C3FF  sub      sp, sp, #0x70
//   0x0dab2c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0dab30: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dab34: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_2015_0x0dab28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab28ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e2040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2016 | PC: 0x0dad28 | FDE: 0x1e2070 | Size: 256 bytes
// Khung tháo gỡ #2016 | Địa chỉ PC: 0x0dad28 | Địa chỉ FDE: 0x1e2070 | Kích thước: 256 bytes
//   0x0dad28: F940000A  ldr      x10, [x0]
//   0x0dad2c: F9400068  ldr      x8, [x3]
//   0x0dad30: EB01015F  cmp      x10, x1
//   0x0dad34: 8B080849  add      x9, x2, x8, lsl #2
static inline uint64_t fde_func_2016_0x0dad28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dad28ULL ^ (static_cast<uint64_t>(0xf940000aULL) << 13);
    acc = (acc + a1 + 0xf9400068ULL) ^ 0x1e2070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2017 | PC: 0x0db090 | FDE: 0x1e2088 | Size: 224 bytes [_Py_DecodeUTF8_surrogateescape]
// Khung tháo gỡ #2017 | Địa chỉ PC: 0x0db090 | Địa chỉ FDE: 0x1e2088 | Kích thước: 224 bytes
//   0x0db090: D10103FF  sub      sp, sp, #0x40
//   0x0db094: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0db098: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0db09c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2017_0x0db090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db090ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2088ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #2018 | PC: 0x0db170 | FDE: 0x1e20b0 | Size: 256 bytes [_Py_EncodeUTF8Ex]
// Khung tháo gỡ #2018 | Địa chỉ PC: 0x0db170 | Địa chỉ FDE: 0x1e20b0 | Kích thước: 256 bytes
//   0x0db170: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0db174: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0db178: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0db17c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2018_0x0db170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db170ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e20b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2019 | PC: 0x0db3b8 | FDE: 0x1e20e0 | Size: 92 bytes [PyUnicode_EncodeUTF8]
// Khung tháo gỡ #2019 | Địa chỉ PC: 0x0db3b8 | Địa chỉ FDE: 0x1e20e0 | Kích thước: 92 bytes
//   0x0db3b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0db3bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db3c0: 910043FD  add      x29, sp, #0x10
//   0x0db3c4: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_2019_0x0db3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db3b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e20e0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #2020 | PC: 0x0db414 | FDE: 0x1e2100 | Size: 12 bytes [PyUnicode_AsUTF8String]
// Khung tháo gỡ #2020 | Địa chỉ PC: 0x0db414 | Địa chỉ FDE: 0x1e2100 | Kích thước: 12 bytes
//   0x0db414: 2A1F03E1  mov      w1, wzr
//   0x0db418: AA1F03E2  mov      x2, xzr
//   0x0db41c: 17FFF133  b        #0xd78e8
static inline uint64_t fde_func_2020_0x0db414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db414ULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e2ULL) ^ 0x1e2100ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2021 | PC: 0x0db420 | FDE: 0x1e2118 | Size: 8 bytes [PyUnicode_DecodeUTF32]
// Khung tháo gỡ #2021 | Địa chỉ PC: 0x0db420 | Địa chỉ FDE: 0x1e2118 | Kích thước: 8 bytes
//   0x0db420: AA1F03E4  mov      x4, xzr
//   0x0db424: 17FE07FB  b        #0x5d410
static inline uint64_t fde_func_2021_0x0db420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db420ULL ^ (static_cast<uint64_t>(0xaa1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fe07fbULL) ^ 0x1e2118ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2022 | PC: 0x0db428 | FDE: 0x1e2130 | Size: 256 bytes [PyUnicode_DecodeUTF32Stateful]
// Khung tháo gỡ #2022 | Địa chỉ PC: 0x0db428 | Địa chỉ FDE: 0x1e2130 | Kích thước: 256 bytes
//   0x0db428: D10403FF  sub      sp, sp, #0x100
//   0x0db42c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0db430: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0db434: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_2022_0x0db428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db428ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1e2130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2023 | PC: 0x0db998 | FDE: 0x1e2160 | Size: 256 bytes [_PyUnicodeWriter_PrepareInternal]
// Khung tháo gỡ #2023 | Địa chỉ PC: 0x0db998 | Địa chỉ FDE: 0x1e2160 | Kích thước: 256 bytes
//   0x0db998: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0db99c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db9a0: 910043FD  add      x29, sp, #0x10
//   0x0db9a4: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_2023_0x0db998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db998ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2024 | PC: 0x0dbbdc | FDE: 0x1e2180 | Size: 256 bytes [_PyUnicode_EncodeUTF32]
// Khung tháo gỡ #2024 | Địa chỉ PC: 0x0dbbdc | Địa chỉ FDE: 0x1e2180 | Kích thước: 256 bytes
//   0x0dbbdc: D10303FF  sub      sp, sp, #0xc0
//   0x0dbbe0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0dbbe4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0dbbe8: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_2024_0x0dbbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbbdcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1e2180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2025 | PC: 0x0dc43c | FDE: 0x1e21b0 | Size: 256 bytes
// Khung tháo gỡ #2025 | Địa chỉ PC: 0x0dc43c | Địa chỉ FDE: 0x1e21b0 | Kích thước: 256 bytes
//   0x0dc43c: D10203FF  sub      sp, sp, #0x80
//   0x0dc440: F90013FB  str      x27, [sp, #0x20]
//   0x0dc444: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0dc448: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2025_0x0dc43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc43cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e21b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2026 | PC: 0x0dc668 | FDE: 0x1e21e0 | Size: 48 bytes [PyUnicode_EncodeUTF32]
// Khung tháo gỡ #2026 | Địa chỉ PC: 0x0dc668 | Địa chỉ FDE: 0x1e21e0 | Kích thước: 48 bytes
//   0x0dc668: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dc66c: 910003FD  mov      x29, sp
//   0x0dc670: 97FDF190  bl       #0x58cb0
//   0x0dc674: B40000C0  cbz      x0, #0xdc68c
static inline uint64_t fde_func_2026_0x0dc668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc668ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e21e0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2027 | PC: 0x0dc698 | FDE: 0x1e2200 | Size: 8 bytes [PyUnicode_AsUTF32String]
// Khung tháo gỡ #2027 | Địa chỉ PC: 0x0dc698 | Địa chỉ FDE: 0x1e2200 | Kích thước: 8 bytes
//   0x0dc698: AA1F03E0  mov      x0, xzr
//   0x0dc69c: D65F03C0  ret      
static inline uint64_t fde_func_2027_0x0dc698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc698ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e2200ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2028 | PC: 0x0dc6a0 | FDE: 0x1e2218 | Size: 8 bytes [PyUnicode_DecodeUTF16]
// Khung tháo gỡ #2028 | Địa chỉ PC: 0x0dc6a0 | Địa chỉ FDE: 0x1e2218 | Kích thước: 8 bytes
//   0x0dc6a0: AA1F03E0  mov      x0, xzr
//   0x0dc6a4: D65F03C0  ret      
static inline uint64_t fde_func_2028_0x0dc6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc6a0ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e2218ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2029 | PC: 0x0dc6a8 | FDE: 0x1e2230 | Size: 256 bytes [PyUnicode_DecodeUTF16Stateful]
// Khung tháo gỡ #2029 | Địa chỉ PC: 0x0dc6a8 | Địa chỉ FDE: 0x1e2230 | Kích thước: 256 bytes
//   0x0dc6a8: D10403FF  sub      sp, sp, #0x100
//   0x0dc6ac: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0dc6b0: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0dc6b4: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_2029_0x0dc6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc6a8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1e2230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2030 | PC: 0x0dd040 | FDE: 0x1e2260 | Size: 256 bytes [_PyUnicode_EncodeUTF16]
// Khung tháo gỡ #2030 | Địa chỉ PC: 0x0dd040 | Địa chỉ FDE: 0x1e2260 | Kích thước: 256 bytes
//   0x0dd040: D10303FF  sub      sp, sp, #0xc0
//   0x0dd044: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0dd048: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0dd04c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_2030_0x0dd040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd040ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1e2260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2031 | PC: 0x0dda90 | FDE: 0x1e2290 | Size: 48 bytes [PyUnicode_EncodeUTF16]
// Khung tháo gỡ #2031 | Địa chỉ PC: 0x0dda90 | Địa chỉ FDE: 0x1e2290 | Kích thước: 48 bytes
//   0x0dda90: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dda94: 910003FD  mov      x29, sp
//   0x0dda98: 97FDEC86  bl       #0x58cb0
//   0x0dda9c: B40000C0  cbz      x0, #0xddab4
static inline uint64_t fde_func_2031_0x0dda90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dda90ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2290ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2032 | PC: 0x0ddac0 | FDE: 0x1e22b0 | Size: 8 bytes [PyUnicode_AsUTF16String]
// Khung tháo gỡ #2032 | Địa chỉ PC: 0x0ddac0 | Địa chỉ FDE: 0x1e22b0 | Kích thước: 8 bytes
//   0x0ddac0: AA1F03E0  mov      x0, xzr
//   0x0ddac4: D65F03C0  ret      
static inline uint64_t fde_func_2032_0x0ddac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddac0ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e22b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2033 | PC: 0x0ddac8 | FDE: 0x1e22c8 | Size: 256 bytes [_PyUnicode_DecodeUnicodeEscape]
// Khung tháo gỡ #2033 | Địa chỉ PC: 0x0ddac8 | Địa chỉ FDE: 0x1e22c8 | Kích thước: 256 bytes
//   0x0ddac8: D10403FF  sub      sp, sp, #0x100
//   0x0ddacc: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0ddad0: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0ddad4: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_2033_0x0ddac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddac8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1e22c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2034 | PC: 0x0de6e4 | FDE: 0x1e22f8 | Size: 8 bytes [PyUnicode_DecodeUnicodeEscape]
// Khung tháo gỡ #2034 | Địa chỉ PC: 0x0de6e4 | Địa chỉ FDE: 0x1e22f8 | Kích thước: 8 bytes
//   0x0de6e4: AA1F03E0  mov      x0, xzr
//   0x0de6e8: D65F03C0  ret      
static inline uint64_t fde_func_2034_0x0de6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6e4ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e22f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2035 | PC: 0x0de6ec | FDE: 0x1e2310 | Size: 256 bytes [PyUnicode_AsUnicodeEscapeString]
// Khung tháo gỡ #2035 | Địa chỉ PC: 0x0de6ec | Địa chỉ FDE: 0x1e2310 | Kích thước: 256 bytes
//   0x0de6ec: D10103FF  sub      sp, sp, #0x40
//   0x0de6f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0de6f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0de6f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2035_0x0de6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2036 | PC: 0x0de9d4 | FDE: 0x1e2338 | Size: 80 bytes [PyUnicode_EncodeUnicodeEscape]
// Khung tháo gỡ #2036 | Địa chỉ PC: 0x0de9d4 | Địa chỉ FDE: 0x1e2338 | Kích thước: 80 bytes
//   0x0de9d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0de9d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de9dc: 910043FD  add      x29, sp, #0x10
//   0x0de9e0: 97FDE8B4  bl       #0x58cb0
static inline uint64_t fde_func_2036_0x0de9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de9d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2338ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2037 | PC: 0x0dea24 | FDE: 0x1e2358 | Size: 256 bytes [PyUnicode_DecodeRawUnicodeEscape]
// Khung tháo gỡ #2037 | Địa chỉ PC: 0x0dea24 | Địa chỉ FDE: 0x1e2358 | Kích thước: 256 bytes
//   0x0dea24: D103C3FF  sub      sp, sp, #0xf0
//   0x0dea28: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0dea2c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0dea30: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_2037_0x0dea24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dea24ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e2358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2038 | PC: 0x0defa4 | FDE: 0x1e2388 | Size: 256 bytes [PyUnicode_AsRawUnicodeEscapeString]
// Khung tháo gỡ #2038 | Địa chỉ PC: 0x0defa4 | Địa chỉ FDE: 0x1e2388 | Kích thước: 256 bytes
//   0x0defa4: D10103FF  sub      sp, sp, #0x40
//   0x0defa8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0defac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0defb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2038_0x0defa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0defa4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2039 | PC: 0x0df1f4 | FDE: 0x1e23b0 | Size: 48 bytes [PyUnicode_EncodeRawUnicodeEscape]
// Khung tháo gỡ #2039 | Địa chỉ PC: 0x0df1f4 | Địa chỉ FDE: 0x1e23b0 | Kích thước: 48 bytes
//   0x0df1f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0df1f8: 910003FD  mov      x29, sp
//   0x0df1fc: 97FDE6AD  bl       #0x58cb0
//   0x0df200: B40000C0  cbz      x0, #0xdf218
static inline uint64_t fde_func_2039_0x0df1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df1f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e23b0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2040 | PC: 0x0df224 | FDE: 0x1e23d0 | Size: 92 bytes [PyUnicode_EncodeLatin1]
// Khung tháo gỡ #2040 | Địa chỉ PC: 0x0df224 | Địa chỉ FDE: 0x1e23d0 | Kích thước: 92 bytes
//   0x0df224: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0df228: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df22c: 910043FD  add      x29, sp, #0x10
//   0x0df230: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_2040_0x0df224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df224ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e23d0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #2041 | PC: 0x0df280 | FDE: 0x1e23f0 | Size: 256 bytes
// Khung tháo gỡ #2041 | Địa chỉ PC: 0x0df280 | Địa chỉ FDE: 0x1e23f0 | Kích thước: 256 bytes
//   0x0df280: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0df284: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0df288: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0df28c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2041_0x0df280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df280ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e23f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2042 | PC: 0x0df7dc | FDE: 0x1e2420 | Size: 8 bytes [PyUnicode_AsLatin1String]
// Khung tháo gỡ #2042 | Địa chỉ PC: 0x0df7dc | Địa chỉ FDE: 0x1e2420 | Kích thước: 8 bytes
//   0x0df7dc: AA1F03E1  mov      x1, xzr
//   0x0df7e0: 17FDEFE0  b        #0x5b760
static inline uint64_t fde_func_2042_0x0df7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df7dcULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fdefe0ULL) ^ 0x1e2420ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2043 | PC: 0x0df7e4 | FDE: 0x1e2438 | Size: 256 bytes
// Khung tháo gỡ #2043 | Địa chỉ PC: 0x0df7e4 | Địa chỉ FDE: 0x1e2438 | Kích thước: 256 bytes
//   0x0df7e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df7e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df7ec: 910043FD  add      x29, sp, #0x10
//   0x0df7f0: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_2043_0x0df7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df7e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2044 | PC: 0x0df910 | FDE: 0x1e2458 | Size: 52 bytes [_PyUnicodeWriter_PrepareKindInternal]
// Khung tháo gỡ #2044 | Địa chỉ PC: 0x0df910 | Địa chỉ FDE: 0x1e2458 | Kích thước: 52 bytes
//   0x0df910: 7100043F  cmp      w1, #1
//   0x0df914: 540000C0  b.eq     #0xdf92c
//   0x0df918: 7100103F  cmp      w1, #4
//   0x0df91c: 540000E0  b.eq     #0xdf938
static inline uint64_t fde_func_2044_0x0df910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df910ULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0x540000c0ULL) ^ 0x1e2458ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2045 | PC: 0x0df944 | FDE: 0x1e2470 | Size: 92 bytes [PyUnicode_EncodeASCII]
// Khung tháo gỡ #2045 | Địa chỉ PC: 0x0df944 | Địa chỉ FDE: 0x1e2470 | Kích thước: 92 bytes
//   0x0df944: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0df948: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df94c: 910043FD  add      x29, sp, #0x10
//   0x0df950: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_2045_0x0df944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df944ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2470ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #2046 | PC: 0x0df9a0 | FDE: 0x1e2490 | Size: 136 bytes [PyUnicode_AsASCIIString]
// Khung tháo gỡ #2046 | Địa chỉ PC: 0x0df9a0 | Địa chỉ FDE: 0x1e2490 | Kích thước: 136 bytes
//   0x0df9a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df9a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df9a8: 910043FD  add      x29, sp, #0x10
//   0x0df9ac: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2046_0x0df9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df9a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2490ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2047 | PC: 0x0dfa28 | FDE: 0x1e24b0 | Size: 256 bytes [PyUnicode_DecodeCharmap]
// Khung tháo gỡ #2047 | Địa chỉ PC: 0x0dfa28 | Địa chỉ FDE: 0x1e24b0 | Kích thước: 256 bytes
//   0x0dfa28: D103C3FF  sub      sp, sp, #0xf0
//   0x0dfa2c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0dfa30: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0dfa34: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_2047_0x0dfa28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfa28ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e24b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2048 | PC: 0x0e02ec | FDE: 0x1e24e0 | Size: 256 bytes [PyUnicode_BuildEncodingMap]
// Khung tháo gỡ #2048 | Địa chỉ PC: 0x0e02ec | Địa chỉ FDE: 0x1e24e0 | Kích thước: 256 bytes
//   0x0e02ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e02f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e02f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e02f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2048_0x0e02ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e02ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e24e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2049 | PC: 0x0e0748 | FDE: 0x1e2510 | Size: 256 bytes [_PyUnicode_EncodeCharmap]
// Khung tháo gỡ #2049 | Địa chỉ PC: 0x0e0748 | Địa chỉ FDE: 0x1e2510 | Kích thước: 256 bytes
//   0x0e0748: D10443FF  sub      sp, sp, #0x110
//   0x0e074c: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0e0750: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0e0754: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_2049_0x0e0748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0748ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x1e2510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2050 | PC: 0x0e0f40 | FDE: 0x1e2540 | Size: 256 bytes
// Khung tháo gỡ #2050 | Địa chỉ PC: 0x0e0f40 | Địa chỉ FDE: 0x1e2540 | Kích thước: 256 bytes
//   0x0e0f40: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e0f44: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e0f48: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e0f4c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2050_0x0e0f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0f40ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2051 | PC: 0x0e116c | FDE: 0x1e2568 | Size: 48 bytes [PyUnicode_EncodeCharmap]
// Khung tháo gỡ #2051 | Địa chỉ PC: 0x0e116c | Địa chỉ FDE: 0x1e2568 | Kích thước: 48 bytes
//   0x0e116c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e1170: 910003FD  mov      x29, sp
//   0x0e1174: 97FDDECF  bl       #0x58cb0
//   0x0e1178: B40000C0  cbz      x0, #0xe1190
static inline uint64_t fde_func_2051_0x0e116c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e116cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2568ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2052 | PC: 0x0e119c | FDE: 0x1e2588 | Size: 40 bytes [PyUnicode_AsCharmapString]
// Khung tháo gỡ #2052 | Địa chỉ PC: 0x0e119c | Địa chỉ FDE: 0x1e2588 | Kích thước: 40 bytes
//   0x0e119c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e11a0: 910003FD  mov      x29, sp
//   0x0e11a4: B4000081  cbz      x1, #0xe11b4
//   0x0e11a8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2052_0x0e119c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e119cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2588ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2053 | PC: 0x0e11c4 | FDE: 0x1e25a8 | Size: 104 bytes [PyUnicode_TranslateCharmap]
// Khung tháo gỡ #2053 | Địa chỉ PC: 0x0e11c4 | Địa chỉ FDE: 0x1e25a8 | Kích thước: 104 bytes
//   0x0e11c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e11c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e11cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e11d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2053_0x0e11c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e11c4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e25a8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #2054 | PC: 0x0e122c | FDE: 0x1e25c8 | Size: 256 bytes
// Khung tháo gỡ #2054 | Địa chỉ PC: 0x0e122c | Địa chỉ FDE: 0x1e25c8 | Kích thước: 256 bytes
//   0x0e122c: D105C3FF  sub      sp, sp, #0x170
//   0x0e1230: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x0e1234: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x0e1238: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_2054_0x0e122c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e122cULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x1e25c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2055 | PC: 0x0e1c64 | FDE: 0x1e25f8 | Size: 136 bytes [PyUnicode_Translate]
// Khung tháo gỡ #2055 | Địa chỉ PC: 0x0e1c64 | Địa chỉ FDE: 0x1e25f8 | Kích thước: 136 bytes
//   0x0e1c64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1c68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1c6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1c70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2055_0x0e1c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1c64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e25f8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2056 | PC: 0x0e1cec | FDE: 0x1e2618 | Size: 256 bytes [_PyUnicode_TransformDecimalAndSpaceToASCII]
// Khung tháo gỡ #2056 | Địa chỉ PC: 0x0e1cec | Địa chỉ FDE: 0x1e2618 | Kích thước: 256 bytes
//   0x0e1cec: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e1cf0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e1cf4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1cf8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2056_0x0e1cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1cecULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e2618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2057 | PC: 0x0e1e8c | FDE: 0x1e2640 | Size: 256 bytes [PyUnicode_TransformDecimalToASCII]
// Khung tháo gỡ #2057 | Địa chỉ PC: 0x0e1e8c | Địa chỉ FDE: 0x1e2640 | Kích thước: 256 bytes
//   0x0e1e8c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e1e90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e1e94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1e98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2057_0x0e1e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1e8cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e2640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2058 | PC: 0x0e1fd0 | FDE: 0x1e2668 | Size: 256 bytes [PyUnicode_EncodeDecimal]
// Khung tháo gỡ #2058 | Địa chỉ PC: 0x0e1fd0 | Địa chỉ FDE: 0x1e2668 | Kích thước: 256 bytes
//   0x0e1fd0: D10183FF  sub      sp, sp, #0x60
//   0x0e1fd4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e1fd8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e1fdc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2058_0x0e1fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1fd0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2059 | PC: 0x0e2190 | FDE: 0x1e2698 | Size: 256 bytes [_PyUnicode_InsertThousandsGrouping]
// Khung tháo gỡ #2059 | Địa chỉ PC: 0x0e2190 | Địa chỉ FDE: 0x1e2698 | Kích thước: 256 bytes
//   0x0e2190: D10243FF  sub      sp, sp, #0x90
//   0x0e2194: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e2198: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e219c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2059_0x0e2190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2190ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e2698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2060 | PC: 0x0e2380 | FDE: 0x1e26c8 | Size: 256 bytes
// Khung tháo gỡ #2060 | Địa chỉ PC: 0x0e2380 | Địa chỉ FDE: 0x1e26c8 | Kích thước: 256 bytes
//   0x0e2380: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e2384: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e2388: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e238c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2060_0x0e2380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2380ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e26c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2061 | PC: 0x0e251c | FDE: 0x1e26f0 | Size: 256 bytes [PyUnicode_Count]
// Khung tháo gỡ #2061 | Địa chỉ PC: 0x0e251c | Địa chỉ FDE: 0x1e26f0 | Kích thước: 256 bytes
//   0x0e251c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0e2520: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e2524: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e2528: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2061_0x0e251c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e251cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e26f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2062 | PC: 0x0e2790 | FDE: 0x1e2720 | Size: 256 bytes
// Khung tháo gỡ #2062 | Địa chỉ PC: 0x0e2790 | Địa chỉ FDE: 0x1e2720 | Kích thước: 256 bytes
//   0x0e2790: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e2794: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e2798: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e279c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2062_0x0e2790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2790ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2063 | PC: 0x0e298c | FDE: 0x1e2740 | Size: 196 bytes [PyUnicode_Find]
// Khung tháo gỡ #2063 | Địa chỉ PC: 0x0e298c | Địa chỉ FDE: 0x1e2740 | Kích thước: 196 bytes
//   0x0e298c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e2990: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e2994: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e2998: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2063_0x0e298c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e298cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2740ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2064 | PC: 0x0e2a50 | FDE: 0x1e2768 | Size: 256 bytes
// Khung tháo gỡ #2064 | Địa chỉ PC: 0x0e2a50 | Địa chỉ FDE: 0x1e2768 | Kích thước: 256 bytes
//   0x0e2a50: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e2a54: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e2a58: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e2a5c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2064_0x0e2a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2a50ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2065 | PC: 0x0e2f78 | FDE: 0x1e2798 | Size: 256 bytes [PyUnicode_FindChar]
// Khung tháo gỡ #2065 | Địa chỉ PC: 0x0e2f78 | Địa chỉ FDE: 0x1e2798 | Kích thước: 256 bytes
//   0x0e2f78: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e2f7c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e2f80: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e2f84: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2065_0x0e2f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2f78ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2066 | PC: 0x0e32c0 | FDE: 0x1e27c0 | Size: 188 bytes [PyUnicode_Tailmatch]
// Khung tháo gỡ #2066 | Địa chỉ PC: 0x0e32c0 | Địa chỉ FDE: 0x1e27c0 | Kích thước: 188 bytes
//   0x0e32c0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e32c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e32c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e32cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2066_0x0e32c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e32c0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e27c0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2067 | PC: 0x0e337c | FDE: 0x1e27e8 | Size: 256 bytes
// Khung tháo gỡ #2067 | Địa chỉ PC: 0x0e337c | Địa chỉ FDE: 0x1e27e8 | Kích thước: 256 bytes
//   0x0e337c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e3380: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e3384: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e3388: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2067_0x0e337c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e337cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e27e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2068 | PC: 0x0e3640 | FDE: 0x1e2810 | Size: 128 bytes [PyUnicode_Join]
// Khung tháo gỡ #2068 | Địa chỉ PC: 0x0e3640 | Địa chỉ FDE: 0x1e2810 | Kích thước: 128 bytes
//   0x0e3640: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e3644: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e3648: 910043FD  add      x29, sp, #0x10
//   0x0e364c: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_2068_0x0e3640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3640ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2810ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2069 | PC: 0x0e36c0 | FDE: 0x1e2830 | Size: 256 bytes [_PyUnicode_JoinArray]
// Khung tháo gỡ #2069 | Địa chỉ PC: 0x0e36c0 | Địa chỉ FDE: 0x1e2830 | Kích thước: 256 bytes
//   0x0e36c0: D101C3FF  sub      sp, sp, #0x70
//   0x0e36c4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e36c8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e36cc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_2069_0x0e36c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e36c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e2830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2070 | PC: 0x0e3c3c | FDE: 0x1e2860 | Size: 132 bytes [_PyUnicode_FastFill]
// Khung tháo gỡ #2070 | Địa chỉ PC: 0x0e3c3c | Địa chỉ FDE: 0x1e2860 | Kích thước: 132 bytes
//   0x0e3c3c: B9402009  ldr      w9, [x0, #0x20]
//   0x0e3c40: 53021128  ubfx     w8, w9, #2, #3
//   0x0e3c44: 37280129  tbnz     w9, #5, #0xe3c68
//   0x0e3c48: F9402409  ldr      x9, [x0, #0x48]
static inline uint64_t fde_func_2070_0x0e3c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3c3cULL ^ (static_cast<uint64_t>(0xb9402009ULL) << 13);
    acc = (acc + a1 + 0x53021128ULL) ^ 0x1e2860ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2071 | PC: 0x0e3cc0 | FDE: 0x1e2878 | Size: 256 bytes [PyUnicode_Fill]
// Khung tháo gỡ #2071 | Địa chỉ PC: 0x0e3cc0 | Địa chỉ FDE: 0x1e2878 | Kích thước: 256 bytes
//   0x0e3cc0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e3cc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e3cc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e3ccc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2071_0x0e3cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3cc0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2072 | PC: 0x0e3e94 | FDE: 0x1e28a0 | Size: 256 bytes [PyUnicode_Splitlines]
// Khung tháo gỡ #2072 | Địa chỉ PC: 0x0e3e94 | Địa chỉ FDE: 0x1e28a0 | Kích thước: 256 bytes
//   0x0e3e94: D10243FF  sub      sp, sp, #0x90
//   0x0e3e98: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e3e9c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e3ea0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2072_0x0e3e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3e94ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e28a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2073 | PC: 0x0e45a0 | FDE: 0x1e28d0 | Size: 176 bytes [PyUnicode_Compare]
// Khung tháo gỡ #2073 | Địa chỉ PC: 0x0e45a0 | Địa chỉ FDE: 0x1e28d0 | Kích thước: 176 bytes
//   0x0e45a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e45a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e45a8: 910043FD  add      x29, sp, #0x10
//   0x0e45ac: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2073_0x0e45a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e45a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e28d0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #2074 | PC: 0x0e4650 | FDE: 0x1e28f0 | Size: 256 bytes
// Khung tháo gỡ #2074 | Địa chỉ PC: 0x0e4650 | Địa chỉ FDE: 0x1e28f0 | Kích thước: 256 bytes
//   0x0e4650: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e4654: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4658: 910043FD  add      x29, sp, #0x10
//   0x0e465c: B940200B  ldr      w11, [x0, #0x20]
static inline uint64_t fde_func_2074_0x0e4650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4650ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e28f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2075 | PC: 0x0e4888 | FDE: 0x1e2910 | Size: 256 bytes [PyUnicode_CompareWithASCIIString]
// Khung tháo gỡ #2075 | Địa chỉ PC: 0x0e4888 | Địa chỉ FDE: 0x1e2910 | Kích thước: 256 bytes
//   0x0e4888: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e488c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4894: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2075_0x0e4888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4888ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2076 | PC: 0x0e49f4 | FDE: 0x1e2938 | Size: 240 bytes [_PyUnicode_EqualToASCIIString]
// Khung tháo gỡ #2076 | Địa chỉ PC: 0x0e49f4 | Địa chỉ FDE: 0x1e2938 | Kích thước: 240 bytes
//   0x0e49f4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e49f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e49fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4a00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2076_0x0e49f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e49f4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2938ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #2077 | PC: 0x0e4ae4 | FDE: 0x1e2958 | Size: 256 bytes [_PyUnicode_EqualToASCIIId]
// Khung tháo gỡ #2077 | Địa chỉ PC: 0x0e4ae4 | Địa chỉ FDE: 0x1e2958 | Kích thước: 256 bytes
//   0x0e4ae4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e4ae8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4aec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4af0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2077_0x0e4ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ae4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2078 | PC: 0x0e4c54 | FDE: 0x1e2978 | Size: 256 bytes [PyUnicode_RichCompare]
// Khung tháo gỡ #2078 | Địa chỉ PC: 0x0e4c54 | Địa chỉ FDE: 0x1e2978 | Kích thước: 256 bytes
//   0x0e4c54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e4c58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4c5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4c60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2078_0x0e4c54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4c54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2079 | PC: 0x0e4e28 | FDE: 0x1e2998 | Size: 156 bytes [_PyUnicode_EQ]
// Khung tháo gỡ #2079 | Địa chỉ PC: 0x0e4e28 | Địa chỉ FDE: 0x1e2998 | Kích thước: 156 bytes
//   0x0e4e28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e4e2c: 910003FD  mov      x29, sp
//   0x0e4e30: F9400808  ldr      x8, [x0, #0x10]
//   0x0e4e34: F9400829  ldr      x9, [x1, #0x10]
static inline uint64_t fde_func_2079_0x0e4e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4e28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2998ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2080 | PC: 0x0e4ec4 | FDE: 0x1e29b8 | Size: 256 bytes [PyUnicode_Contains]
// Khung tháo gỡ #2080 | Địa chỉ PC: 0x0e4ec4 | Địa chỉ FDE: 0x1e29b8 | Kích thước: 256 bytes
//   0x0e4ec4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e4ec8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4ecc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e4ed0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2080_0x0e4ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ec4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e29b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2081 | PC: 0x0e5184 | FDE: 0x1e29e0 | Size: 256 bytes [PyUnicode_Concat]
// Khung tháo gỡ #2081 | Địa chỉ PC: 0x0e5184 | Địa chỉ FDE: 0x1e29e0 | Kích thước: 256 bytes
//   0x0e5184: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e5188: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e518c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e5190: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2081_0x0e5184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5184ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e29e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2082 | PC: 0x0e5418 | FDE: 0x1e2a08 | Size: 256 bytes [PyUnicode_Append]
// Khung tháo gỡ #2082 | Địa chỉ PC: 0x0e5418 | Địa chỉ FDE: 0x1e2a08 | Kích thước: 256 bytes
//   0x0e5418: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e541c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e5420: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e5424: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2082_0x0e5418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5418ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2083 | PC: 0x0e5724 | FDE: 0x1e2a30 | Size: 68 bytes [PyUnicode_AppendAndDel]
// Khung tháo gỡ #2083 | Địa chỉ PC: 0x0e5724 | Địa chỉ FDE: 0x1e2a30 | Kích thước: 68 bytes
//   0x0e5724: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e5728: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e572c: 910043FD  add      x29, sp, #0x10
//   0x0e5730: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2083_0x0e5724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5724ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2a30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2084 | PC: 0x0e5768 | FDE: 0x1e2a50 | Size: 256 bytes [_PyUnicode_ScanIdentifier]
// Khung tháo gỡ #2084 | Địa chỉ PC: 0x0e5768 | Địa chỉ FDE: 0x1e2a50 | Kích thước: 256 bytes
//   0x0e5768: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e576c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5770: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5774: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2084_0x0e5768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5768ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2085 | PC: 0x0e587c | FDE: 0x1e2a78 | Size: 208 bytes [PyUnicode_IsIdentifier]
// Khung tháo gỡ #2085 | Địa chỉ PC: 0x0e587c | Địa chỉ FDE: 0x1e2a78 | Kích thước: 208 bytes
//   0x0e587c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e5880: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5884: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5888: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2085_0x0e587c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e587cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2a78ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2086 | PC: 0x0e594c | FDE: 0x1e2a98 | Size: 256 bytes [_PyUnicode_XStrip]
// Khung tháo gỡ #2086 | Địa chỉ PC: 0x0e594c | Địa chỉ FDE: 0x1e2a98 | Kích thước: 256 bytes
//   0x0e594c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e5950: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e5954: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e5958: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2086_0x0e594c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e594cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2087 | PC: 0x0e5d50 | FDE: 0x1e2ac8 | Size: 256 bytes [PyUnicode_Substring]
// Khung tháo gỡ #2087 | Địa chỉ PC: 0x0e5d50 | Địa chỉ FDE: 0x1e2ac8 | Kích thước: 256 bytes
//   0x0e5d50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e5d54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5d58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5d5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2087_0x0e5d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2088 | PC: 0x0e5fa4 | FDE: 0x1e2ae8 | Size: 208 bytes [PyUnicode_Replace]
// Khung tháo gỡ #2088 | Địa chỉ PC: 0x0e5fa4 | Địa chỉ FDE: 0x1e2ae8 | Kích thước: 208 bytes
//   0x0e5fa4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e5fa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5fac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5fb0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2088_0x0e5fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5fa4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2ae8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2089 | PC: 0x0e6074 | FDE: 0x1e2b10 | Size: 256 bytes
// Khung tháo gỡ #2089 | Địa chỉ PC: 0x0e6074 | Địa chỉ FDE: 0x1e2b10 | Kích thước: 256 bytes
//   0x0e6074: D10303FF  sub      sp, sp, #0xc0
//   0x0e6078: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0e607c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0e6080: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_2089_0x0e6074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6074ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1e2b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2090 | PC: 0x0e766c | FDE: 0x1e2b40 | Size: 172 bytes [PyUnicode_Split]
// Khung tháo gỡ #2090 | Địa chỉ PC: 0x0e766c | Địa chỉ FDE: 0x1e2b40 | Kích thước: 172 bytes
//   0x0e766c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e7670: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e7674: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e7678: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2090_0x0e766c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e766cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2b40ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2091 | PC: 0x0e7718 | FDE: 0x1e2b60 | Size: 256 bytes
// Khung tháo gỡ #2091 | Địa chỉ PC: 0x0e7718 | Địa chỉ FDE: 0x1e2b60 | Kích thước: 256 bytes
//   0x0e7718: D10203FF  sub      sp, sp, #0x80
//   0x0e771c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0e7720: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e7724: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2091_0x0e7718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7718ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e2b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2092 | PC: 0x0e8c1c | FDE: 0x1e2b90 | Size: 256 bytes [PyUnicode_Partition]
// Khung tháo gỡ #2092 | Địa chỉ PC: 0x0e8c1c | Địa chỉ FDE: 0x1e2b90 | Kích thước: 256 bytes
//   0x0e8c1c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e8c20: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e8c24: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e8c28: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2092_0x0e8c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8c1cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2093 | PC: 0x0e8ff8 | FDE: 0x1e2bc0 | Size: 256 bytes [PyUnicode_RPartition]
// Khung tháo gỡ #2093 | Địa chỉ PC: 0x0e8ff8 | Địa chỉ FDE: 0x1e2bc0 | Kích thước: 256 bytes
//   0x0e8ff8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e8ffc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e9000: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e9004: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2093_0x0e8ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8ff8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2094 | PC: 0x0e93d4 | FDE: 0x1e2bf0 | Size: 172 bytes [PyUnicode_RSplit]
// Khung tháo gỡ #2094 | Địa chỉ PC: 0x0e93d4 | Địa chỉ FDE: 0x1e2bf0 | Kích thước: 172 bytes
//   0x0e93d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e93d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e93dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e93e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2094_0x0e93d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e93d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2bf0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2095 | PC: 0x0e9480 | FDE: 0x1e2c10 | Size: 256 bytes
// Khung tháo gỡ #2095 | Địa chỉ PC: 0x0e9480 | Địa chỉ FDE: 0x1e2c10 | Kích thước: 256 bytes
//   0x0e9480: D101C3FF  sub      sp, sp, #0x70
//   0x0e9484: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e9488: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e948c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_2095_0x0e9480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9480ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e2c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2096 | PC: 0x0ea85c | FDE: 0x1e2c40 | Size: 256 bytes
// Khung tháo gỡ #2096 | Địa chỉ PC: 0x0ea85c | Địa chỉ FDE: 0x1e2c40 | Kích thước: 256 bytes
//   0x0ea85c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ea860: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ea864: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ea868: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2096_0x0ea85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea85cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2097 | PC: 0x0eaa94 | FDE: 0x1e2c68 | Size: 168 bytes [_PyUnicodeWriter_WriteChar]
// Khung tháo gỡ #2097 | Địa chỉ PC: 0x0eaa94 | Địa chỉ FDE: 0x1e2c68 | Kích thước: 168 bytes
//   0x0eaa94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eaa98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eaa9c: 910043FD  add      x29, sp, #0x10
//   0x0eaaa0: B9401408  ldr      w8, [x0, #0x14]
static inline uint64_t fde_func_2097_0x0eaa94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2c68ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2098 | PC: 0x0eab3c | FDE: 0x1e2c88 | Size: 256 bytes [_PyUnicodeWriter_WriteStr]
// Khung tháo gỡ #2098 | Địa chỉ PC: 0x0eab3c | Địa chỉ FDE: 0x1e2c88 | Kích thước: 256 bytes
//   0x0eab3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0eab40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eab44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eab48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2098_0x0eab3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eab3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2099 | PC: 0x0eacb8 | FDE: 0x1e2ca8 | Size: 256 bytes [_PyUnicodeWriter_WriteSubstring]
// Khung tháo gỡ #2099 | Địa chỉ PC: 0x0eacb8 | Địa chỉ FDE: 0x1e2ca8 | Kích thước: 256 bytes
//   0x0eacb8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0eacbc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0eacc0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0eacc4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2099_0x0eacb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eacb8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2100 | PC: 0x0eae08 | FDE: 0x1e2cd0 | Size: 256 bytes [_PyUnicodeWriter_WriteLatin1String]
// Khung tháo gỡ #2100 | Địa chỉ PC: 0x0eae08 | Địa chỉ FDE: 0x1e2cd0 | Kích thước: 256 bytes
//   0x0eae08: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0eae0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eae10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eae14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2100_0x0eae08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae08ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2101 | PC: 0x0eafe4 | FDE: 0x1e2cf8 | Size: 256 bytes
// Khung tháo gỡ #2101 | Địa chỉ PC: 0x0eafe4 | Địa chỉ FDE: 0x1e2cf8 | Kích thước: 256 bytes
//   0x0eafe4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eafe8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eafec: 910043FD  add      x29, sp, #0x10
//   0x0eaff0: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_2101_0x0eafe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eafe4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2cf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2102 | PC: 0x0eb0f8 | FDE: 0x1e2d18 | Size: 256 bytes [_PyUnicode_FormatLong]
// Khung tháo gỡ #2102 | Địa chỉ PC: 0x0eb0f8 | Địa chỉ FDE: 0x1e2d18 | Kích thước: 256 bytes
//   0x0eb0f8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0eb0fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0eb100: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0eb104: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2102_0x0eb0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb0f8ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2103 | PC: 0x0eb6cc | FDE: 0x1e2d48 | Size: 256 bytes [PyUnicode_Format]
// Khung tháo gỡ #2103 | Địa chỉ PC: 0x0eb6cc | Địa chỉ FDE: 0x1e2d48 | Kích thước: 256 bytes
//   0x0eb6cc: D10543FF  sub      sp, sp, #0x150
//   0x0eb6d0: FD0073E8  str      d8, [sp, #0xe0]
//   0x0eb6d4: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0eb6d8: A91067FA  stp      x26, x25, [sp, #0x100]
static inline uint64_t fde_func_2103_0x0eb6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb6ccULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xfd0073e8ULL) ^ 0x1e2d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2104 | PC: 0x0ece44 | FDE: 0x1e2d78 | Size: 256 bytes
// Khung tháo gỡ #2104 | Địa chỉ PC: 0x0ece44 | Địa chỉ FDE: 0x1e2d78 | Kích thước: 256 bytes
//   0x0ece44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ece48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ece4c: 910043FD  add      x29, sp, #0x10
//   0x0ece50: B9402008  ldr      w8, [x0, #0x20]
static inline uint64_t fde_func_2104_0x0ece44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ece44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2105 | PC: 0x0ecf84 | FDE: 0x1e2d98 | Size: 256 bytes
// Khung tháo gỡ #2105 | Địa chỉ PC: 0x0ecf84 | Địa chỉ FDE: 0x1e2d98 | Kích thước: 256 bytes
//   0x0ecf84: D10243FF  sub      sp, sp, #0x90
//   0x0ecf88: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x0ecf8c: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x0ecf90: A9036FFC  stp      x28, x27, [sp, #0x30]
static inline uint64_t fde_func_2105_0x0ecf84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecf84ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x1e2d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2106 | PC: 0x0ed8b8 | FDE: 0x1e2dd8 | Size: 124 bytes
// Khung tháo gỡ #2106 | Địa chỉ PC: 0x0ed8b8 | Địa chỉ FDE: 0x1e2dd8 | Kích thước: 124 bytes
//   0x0ed8b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ed8bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ed8c0: 910043FD  add      x29, sp, #0x10
//   0x0ed8c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2106_0x0ed8b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed8b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2dd8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2107 | PC: 0x0ed934 | FDE: 0x1e2df8 | Size: 112 bytes
// Khung tháo gỡ #2107 | Địa chỉ PC: 0x0ed934 | Địa chỉ FDE: 0x1e2df8 | Kích thước: 112 bytes
//   0x0ed934: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ed938: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ed93c: 910043FD  add      x29, sp, #0x10
//   0x0ed940: D0000889  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2107_0x0ed934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed934ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2df8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2108 | PC: 0x0ed9a4 | FDE: 0x1e2e18 | Size: 124 bytes
// Khung tháo gỡ #2108 | Địa chỉ PC: 0x0ed9a4 | Địa chỉ FDE: 0x1e2e18 | Kích thước: 124 bytes
//   0x0ed9a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ed9a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ed9ac: 910043FD  add      x29, sp, #0x10
//   0x0ed9b0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2108_0x0ed9a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed9a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2e18ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2109 | PC: 0x0eda20 | FDE: 0x1e2e38 | Size: 256 bytes
// Khung tháo gỡ #2109 | Địa chỉ PC: 0x0eda20 | Địa chỉ FDE: 0x1e2e38 | Kích thước: 256 bytes
//   0x0eda20: D10243FF  sub      sp, sp, #0x90
//   0x0eda24: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0eda28: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0eda2c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_2109_0x0eda20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eda20ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x1e2e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2110 | PC: 0x0ede3c | FDE: 0x1e2e68 | Size: 256 bytes [_PyUnicode_Init]
// Khung tháo gỡ #2110 | Địa chỉ PC: 0x0ede3c | Địa chỉ FDE: 0x1e2e68 | Kích thước: 256 bytes
//   0x0ede3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ede40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ede44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ede48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2110_0x0ede3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ede3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2e68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2111 | PC: 0x0edf50 | FDE: 0x1e2e88 | Size: 228 bytes [_PyUnicode_InitTypes]
// Khung tháo gỡ #2111 | Địa chỉ PC: 0x0edf50 | Địa chỉ FDE: 0x1e2e88 | Kích thước: 228 bytes
//   0x0edf50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0edf54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0edf58: 910043FD  add      x29, sp, #0x10
//   0x0edf5c: D0000880  adrp     x0, #0x1ff000
static inline uint64_t fde_func_2111_0x0edf50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0edf50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2e88ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #2112 | PC: 0x0ee034 | FDE: 0x1e2ea8 | Size: 128 bytes [PyUnicode_InternImmortal]
// Khung tháo gỡ #2112 | Địa chỉ PC: 0x0ee034 | Địa chỉ FDE: 0x1e2ea8 | Kích thước: 128 bytes
//   0x0ee034: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee038: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee03c: 910043FD  add      x29, sp, #0x10
//   0x0ee040: B0000888  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2112_0x0ee034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee034ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2ea8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2113 | PC: 0x0ee0b4 | FDE: 0x1e2ec8 | Size: 116 bytes [PyUnicode_InternFromString]
// Khung tháo gỡ #2113 | Địa chỉ PC: 0x0ee0b4 | Địa chỉ FDE: 0x1e2ec8 | Kích thước: 116 bytes
//   0x0ee0b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee0b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee0bc: 910043FD  add      x29, sp, #0x10
//   0x0ee0c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2113_0x0ee0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee0b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2ec8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2114 | PC: 0x0ee128 | FDE: 0x1e2ee8 | Size: 216 bytes [_PyUnicode_ClearInterned]
// Khung tháo gỡ #2114 | Địa chỉ PC: 0x0ee128 | Địa chỉ FDE: 0x1e2ee8 | Kích thước: 216 bytes
//   0x0ee128: D10143FF  sub      sp, sp, #0x50
//   0x0ee12c: F90013F5  str      x21, [sp, #0x20]
//   0x0ee130: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ee134: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2114_0x0ee128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee128ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e2ee8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #2115 | PC: 0x0ee200 | FDE: 0x1e2f08 | Size: 60 bytes
// Khung tháo gỡ #2115 | Địa chỉ PC: 0x0ee200 | Địa chỉ FDE: 0x1e2f08 | Kích thước: 60 bytes
//   0x0ee200: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee204: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee208: 910043FD  add      x29, sp, #0x10
//   0x0ee20c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2115_0x0ee200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee200ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2f08ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2116 | PC: 0x0ee23c | FDE: 0x1e2f28 | Size: 52 bytes
// Khung tháo gỡ #2116 | Địa chỉ PC: 0x0ee23c | Địa chỉ FDE: 0x1e2f28 | Kích thước: 52 bytes
//   0x0ee23c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ee240: 910003FD  mov      x29, sp
//   0x0ee244: F9400C00  ldr      x0, [x0, #0x18]
//   0x0ee248: B40000E0  cbz      x0, #0xee264
static inline uint64_t fde_func_2116_0x0ee23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee23cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2f28ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2117 | PC: 0x0ee270 | FDE: 0x1e2f48 | Size: 192 bytes
// Khung tháo gỡ #2117 | Địa chỉ PC: 0x0ee270 | Địa chỉ FDE: 0x1e2f48 | Kích thước: 192 bytes
//   0x0ee270: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee274: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee278: 910043FD  add      x29, sp, #0x10
//   0x0ee27c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2117_0x0ee270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee270ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2f48ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2118 | PC: 0x0ee330 | FDE: 0x1e2f68 | Size: 256 bytes [_PyUnicode_InitEncodings]
// Khung tháo gỡ #2118 | Địa chỉ PC: 0x0ee330 | Địa chỉ FDE: 0x1e2f68 | Kích thước: 256 bytes
//   0x0ee330: D10143FF  sub      sp, sp, #0x50
//   0x0ee334: F9000BF7  str      x23, [sp, #0x10]
//   0x0ee338: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ee33c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2118_0x0ee330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee330ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1e2f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2119 | PC: 0x0ee548 | FDE: 0x1e2f90 | Size: 256 bytes [_PyUnicode_Fini]
// Khung tháo gỡ #2119 | Địa chỉ PC: 0x0ee548 | Địa chỉ FDE: 0x1e2f90 | Kích thước: 256 bytes
//   0x0ee548: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ee54c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ee550: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ee554: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2119_0x0ee548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee548ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2120 | PC: 0x0ee650 | FDE: 0x1e2fb0 | Size: 12 bytes [PyInit__string]
// Khung tháo gỡ #2120 | Địa chỉ PC: 0x0ee650 | Địa chỉ FDE: 0x1e2fb0 | Kích thước: 12 bytes
//   0x0ee650: F0000920  adrp     x0, #0x215000
//   0x0ee654: 91134000  add      x0, x0, #0x4d0
//   0x0ee658: 17FDA8F2  b        #0x58a20
static inline uint64_t fde_func_2120_0x0ee650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee650ULL ^ (static_cast<uint64_t>(0xf0000920ULL) << 13);
    acc = (acc + a1 + 0x91134000ULL) ^ 0x1e2fb0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2121 | PC: 0x0ee65c | FDE: 0x1e2fc8 | Size: 164 bytes
// Khung tháo gỡ #2121 | Địa chỉ PC: 0x0ee65c | Địa chỉ FDE: 0x1e2fc8 | Kích thước: 164 bytes
//   0x0ee65c: D10483FF  sub      sp, sp, #0x120
//   0x0ee660: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x0ee664: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x0ee668: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_2121_0x0ee65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee65cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1e2fc8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2122 | PC: 0x0ee700 | FDE: 0x1e2fe8 | Size: 204 bytes
// Khung tháo gỡ #2122 | Địa chỉ PC: 0x0ee700 | Địa chỉ FDE: 0x1e2fe8 | Kích thước: 204 bytes
//   0x0ee700: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ee704: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ee708: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ee70c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2122_0x0ee700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee700ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2fe8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2123 | PC: 0x0ee7cc | FDE: 0x1e3008 | Size: 256 bytes
// Khung tháo gỡ #2123 | Địa chỉ PC: 0x0ee7cc | Địa chỉ FDE: 0x1e3008 | Kích thước: 256 bytes
//   0x0ee7cc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0ee7d0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ee7d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ee7d8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2123_0x0ee7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee7ccULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3008ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2124 | PC: 0x0ee968 | FDE: 0x1e3030 | Size: 256 bytes
// Khung tháo gỡ #2124 | Địa chỉ PC: 0x0ee968 | Địa chỉ FDE: 0x1e3030 | Kích thước: 256 bytes
//   0x0ee968: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ee96c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ee970: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ee974: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2124_0x0ee968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee968ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2125 | PC: 0x0eed58 | FDE: 0x1e3058 | Size: 256 bytes
// Khung tháo gỡ #2125 | Địa chỉ PC: 0x0eed58 | Địa chỉ FDE: 0x1e3058 | Kích thước: 256 bytes
//   0x0eed58: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0eed5c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0eed60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0eed64: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2125_0x0eed58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eed58ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2126 | PC: 0x0ef148 | FDE: 0x1e3080 | Size: 256 bytes
// Khung tháo gỡ #2126 | Địa chỉ PC: 0x0ef148 | Địa chỉ FDE: 0x1e3080 | Kích thước: 256 bytes
//   0x0ef148: D10343FF  sub      sp, sp, #0xd0
//   0x0ef14c: FD002BEA  str      d10, [sp, #0x50]
//   0x0ef150: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x0ef154: A9076FFC  stp      x28, x27, [sp, #0x70]
static inline uint64_t fde_func_2126_0x0ef148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef148ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xfd002beaULL) ^ 0x1e3080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2127 | PC: 0x0ef79c | FDE: 0x1e30b8 | Size: 256 bytes
// Khung tháo gỡ #2127 | Địa chỉ PC: 0x0ef79c | Địa chỉ FDE: 0x1e30b8 | Kích thước: 256 bytes
//   0x0ef79c: D10283FF  sub      sp, sp, #0xa0
//   0x0ef7a0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0ef7a4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0ef7a8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_2127_0x0ef79c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef79cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e30b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2128 | PC: 0x0efc60 | FDE: 0x1e30e8 | Size: 256 bytes
// Khung tháo gỡ #2128 | Địa chỉ PC: 0x0efc60 | Địa chỉ FDE: 0x1e30e8 | Kích thước: 256 bytes
//   0x0efc60: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0efc64: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0efc68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0efc6c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2128_0x0efc60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efc60ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e30e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2129 | PC: 0x0efe70 | FDE: 0x1e3110 | Size: 256 bytes
// Khung tháo gỡ #2129 | Địa chỉ PC: 0x0efe70 | Địa chỉ FDE: 0x1e3110 | Kích thước: 256 bytes
//   0x0efe70: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0efe74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0efe78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0efe7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2129_0x0efe70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efe70ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2130 | PC: 0x0f0014 | FDE: 0x1e3138 | Size: 188 bytes
// Khung tháo gỡ #2130 | Địa chỉ PC: 0x0f0014 | Địa chỉ FDE: 0x1e3138 | Kích thước: 188 bytes
//   0x0f0014: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f0018: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f001c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f0020: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2130_0x0f0014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0014ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3138ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2131 | PC: 0x0f00d0 | FDE: 0x1e3158 | Size: 28 bytes
// Khung tháo gỡ #2131 | Địa chỉ PC: 0x0f00d0 | Địa chỉ FDE: 0x1e3158 | Kích thước: 28 bytes
//   0x0f00d0: 29462408  ldp      w8, w9, [x0, #0x30]
//   0x0f00d4: 531C6D08  lsl      w8, w8, #4
//   0x0f00d8: 93407D08  sxtw     x8, w8
//   0x0f00dc: 53196129  lsl      w9, w9, #7
static inline uint64_t fde_func_2131_0x0f00d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f00d0ULL ^ (static_cast<uint64_t>(0x29462408ULL) << 13);
    acc = (acc + a1 + 0x531c6d08ULL) ^ 0x1e3158ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2132 | PC: 0x0f00ec | FDE: 0x1e3170 | Size: 256 bytes
// Khung tháo gỡ #2132 | Địa chỉ PC: 0x0f00ec | Địa chỉ FDE: 0x1e3170 | Kích thước: 256 bytes
//   0x0f00ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f00f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f00f4: 910043FD  add      x29, sp, #0x10
//   0x0f00f8: 2A0003E0  mov      w0, w0
static inline uint64_t fde_func_2132_0x0f00ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f00ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2133 | PC: 0x0f0208 | FDE: 0x1e3190 | Size: 256 bytes
// Khung tháo gỡ #2133 | Địa chỉ PC: 0x0f0208 | Địa chỉ FDE: 0x1e3190 | Kích thước: 256 bytes
//   0x0f0208: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f020c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f0210: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f0214: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2133_0x0f0208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0208ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2134 | PC: 0x0f0330 | FDE: 0x1e31b0 | Size: 256 bytes
// Khung tháo gỡ #2134 | Địa chỉ PC: 0x0f0330 | Địa chỉ FDE: 0x1e31b0 | Kích thước: 256 bytes
//   0x0f0330: D10343FF  sub      sp, sp, #0xd0
//   0x0f0334: F9003BFB  str      x27, [sp, #0x70]
//   0x0f0338: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0f033c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_2134_0x0f0330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0330ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1e31b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2135 | PC: 0x0f08dc | FDE: 0x1e31e0 | Size: 256 bytes
// Khung tháo gỡ #2135 | Địa chỉ PC: 0x0f08dc | Địa chỉ FDE: 0x1e31e0 | Kích thước: 256 bytes
//   0x0f08dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f08e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f08e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f08e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2135_0x0f08dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f08dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e31e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2136 | PC: 0x0f0aa0 | FDE: 0x1e3208 | Size: 256 bytes
// Khung tháo gỡ #2136 | Địa chỉ PC: 0x0f0aa0 | Địa chỉ FDE: 0x1e3208 | Kích thước: 256 bytes
//   0x0f0aa0: A9402448  ldp      x8, x9, [x2]
//   0x0f0aa4: B940204D  ldr      w13, [x2, #0x20]
//   0x0f0aa8: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x0f0aac: 8B01000C  add      x12, x0, x1
static inline uint64_t fde_func_2136_0x0f0aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0aa0ULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1e3208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2137 | PC: 0x0f0c64 | FDE: 0x1e3220 | Size: 256 bytes
// Khung tháo gỡ #2137 | Địa chỉ PC: 0x0f0c64 | Địa chỉ FDE: 0x1e3220 | Kích thước: 256 bytes
//   0x0f0c64: D10343FF  sub      sp, sp, #0xd0
//   0x0f0c68: F9003BFB  str      x27, [sp, #0x70]
//   0x0f0c6c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0f0c70: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_2137_0x0f0c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0c64ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1e3220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2138 | PC: 0x0f1210 | FDE: 0x1e3250 | Size: 256 bytes
// Khung tháo gỡ #2138 | Địa chỉ PC: 0x0f1210 | Địa chỉ FDE: 0x1e3250 | Kích thước: 256 bytes
//   0x0f1210: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f1214: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f1218: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f121c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2138_0x0f1210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1210ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2139 | PC: 0x0f13d4 | FDE: 0x1e3278 | Size: 256 bytes
// Khung tháo gỡ #2139 | Địa chỉ PC: 0x0f13d4 | Địa chỉ FDE: 0x1e3278 | Kích thước: 256 bytes
//   0x0f13d4: A9402448  ldp      x8, x9, [x2]
//   0x0f13d8: B940204D  ldr      w13, [x2, #0x20]
//   0x0f13dc: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x0f13e0: 8B01000C  add      x12, x0, x1
static inline uint64_t fde_func_2139_0x0f13d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f13d4ULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1e3278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2140 | PC: 0x0f1598 | FDE: 0x1e3290 | Size: 256 bytes
// Khung tháo gỡ #2140 | Địa chỉ PC: 0x0f1598 | Địa chỉ FDE: 0x1e3290 | Kích thước: 256 bytes
//   0x0f1598: D10343FF  sub      sp, sp, #0xd0
//   0x0f159c: F9003BFB  str      x27, [sp, #0x70]
//   0x0f15a0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0f15a4: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_2140_0x0f1598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1598ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1e3290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2141 | PC: 0x0f1b90 | FDE: 0x1e32c0 | Size: 256 bytes
// Khung tháo gỡ #2141 | Địa chỉ PC: 0x0f1b90 | Địa chỉ FDE: 0x1e32c0 | Kích thước: 256 bytes
//   0x0f1b90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f1b94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f1b98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f1b9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2141_0x0f1b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1b90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e32c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2142 | PC: 0x0f1d54 | FDE: 0x1e32e8 | Size: 256 bytes
// Khung tháo gỡ #2142 | Địa chỉ PC: 0x0f1d54 | Địa chỉ FDE: 0x1e32e8 | Kích thước: 256 bytes
//   0x0f1d54: A9402448  ldp      x8, x9, [x2]
//   0x0f1d58: B940204D  ldr      w13, [x2, #0x20]
//   0x0f1d5c: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x0f1d60: 8B01040C  add      x12, x0, x1, lsl #1
static inline uint64_t fde_func_2142_0x0f1d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1d54ULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1e32e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2143 | PC: 0x0f1f2c | FDE: 0x1e3300 | Size: 256 bytes
// Khung tháo gỡ #2143 | Địa chỉ PC: 0x0f1f2c | Địa chỉ FDE: 0x1e3300 | Kích thước: 256 bytes
//   0x0f1f2c: D10343FF  sub      sp, sp, #0xd0
//   0x0f1f30: F9003BFB  str      x27, [sp, #0x70]
//   0x0f1f34: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0f1f38: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_2143_0x0f1f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1f2cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1e3300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2144 | PC: 0x0f2524 | FDE: 0x1e3330 | Size: 256 bytes
// Khung tháo gỡ #2144 | Địa chỉ PC: 0x0f2524 | Địa chỉ FDE: 0x1e3330 | Kích thước: 256 bytes
//   0x0f2524: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f2528: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f252c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f2530: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2144_0x0f2524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2524ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2145 | PC: 0x0f26e8 | FDE: 0x1e3358 | Size: 256 bytes
// Khung tháo gỡ #2145 | Địa chỉ PC: 0x0f26e8 | Địa chỉ FDE: 0x1e3358 | Kích thước: 256 bytes
//   0x0f26e8: A9402448  ldp      x8, x9, [x2]
//   0x0f26ec: B940204D  ldr      w13, [x2, #0x20]
//   0x0f26f0: A9412C4A  ldp      x10, x11, [x2, #0x10]
//   0x0f26f4: 8B01080C  add      x12, x0, x1, lsl #2
static inline uint64_t fde_func_2145_0x0f26e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f26e8ULL ^ (static_cast<uint64_t>(0xa9402448ULL) << 13);
    acc = (acc + a1 + 0xb940204dULL) ^ 0x1e3358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2146 | PC: 0x0f28c0 | FDE: 0x1e3370 | Size: 216 bytes
// Khung tháo gỡ #2146 | Địa chỉ PC: 0x0f28c0 | Địa chỉ FDE: 0x1e3370 | Kích thước: 216 bytes
//   0x0f28c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f28c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f28c8: 910043FD  add      x29, sp, #0x10
//   0x0f28cc: AA0703F3  mov      x19, x7
static inline uint64_t fde_func_2146_0x0f28c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f28c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3370ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #2147 | PC: 0x0f2998 | FDE: 0x1e3390 | Size: 200 bytes
// Khung tháo gỡ #2147 | Địa chỉ PC: 0x0f2998 | Địa chỉ FDE: 0x1e3390 | Kích thước: 200 bytes
//   0x0f2998: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0f299c: F90007F5  str      x21, [sp, #8]
//   0x0f29a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f29a4: A9027BFD  stp      x29, x30, [sp, #0x20]
static inline uint64_t fde_func_2147_0x0f2998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2998ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f5ULL) ^ 0x1e3390ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #2148 | PC: 0x0f2a60 | FDE: 0x1e33b8 | Size: 40 bytes
// Khung tháo gỡ #2148 | Địa chỉ PC: 0x0f2a60 | Địa chỉ FDE: 0x1e33b8 | Kích thước: 40 bytes
//   0x0f2a60: F9400408  ldr      x8, [x0, #8]
//   0x0f2a64: 3942AD08  ldrb     w8, [x8, #0xab]
//   0x0f2a68: 372000E8  tbnz     w8, #4, #0xf2a84
//   0x0f2a6c: B0000860  adrp     x0, #0x1ff000
static inline uint64_t fde_func_2148_0x0f2a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2a60ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x3942ad08ULL) ^ 0x1e33b8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2149 | PC: 0x0f2a88 | FDE: 0x1e33d0 | Size: 64 bytes
// Khung tháo gỡ #2149 | Địa chỉ PC: 0x0f2a88 | Địa chỉ FDE: 0x1e33d0 | Kích thước: 64 bytes
//   0x0f2a88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f2a8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2a90: 910043FD  add      x29, sp, #0x10
//   0x0f2a94: 39408008  ldrb     w8, [x0, #0x20]
static inline uint64_t fde_func_2149_0x0f2a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2a88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e33d0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2150 | PC: 0x0f2ac8 | FDE: 0x1e33f0 | Size: 256 bytes
// Khung tháo gỡ #2150 | Địa chỉ PC: 0x0f2ac8 | Địa chỉ FDE: 0x1e33f0 | Kích thước: 256 bytes
//   0x0f2ac8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f2acc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f2ad0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f2ad4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2150_0x0f2ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2ac8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e33f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2151 | PC: 0x0f2ed0 | FDE: 0x1e3418 | Size: 256 bytes
// Khung tháo gỡ #2151 | Địa chỉ PC: 0x0f2ed0 | Địa chỉ FDE: 0x1e3418 | Kích thước: 256 bytes
//   0x0f2ed0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f2ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2ed8: 910043FD  add      x29, sp, #0x10
//   0x0f2edc: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2151_0x0f2ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2ed0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2152 | PC: 0x0f3098 | FDE: 0x1e3438 | Size: 256 bytes
// Khung tháo gỡ #2152 | Địa chỉ PC: 0x0f3098 | Địa chỉ FDE: 0x1e3438 | Kích thước: 256 bytes
//   0x0f3098: D10183FF  sub      sp, sp, #0x60
//   0x0f309c: F90013F7  str      x23, [sp, #0x20]
//   0x0f30a0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f30a4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2152_0x0f3098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3098ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e3438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2153 | PC: 0x0f34bc | FDE: 0x1e3460 | Size: 256 bytes
// Khung tháo gỡ #2153 | Địa chỉ PC: 0x0f34bc | Địa chỉ FDE: 0x1e3460 | Kích thước: 256 bytes
//   0x0f34bc: D101C3FF  sub      sp, sp, #0x70
//   0x0f34c0: F9001BF7  str      x23, [sp, #0x30]
//   0x0f34c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0f34c8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2153_0x0f34bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f34bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e3460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2154 | PC: 0x0f3660 | FDE: 0x1e3488 | Size: 256 bytes
// Khung tháo gỡ #2154 | Địa chỉ PC: 0x0f3660 | Địa chỉ FDE: 0x1e3488 | Kích thước: 256 bytes
//   0x0f3660: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f3664: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f3668: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f366c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2154_0x0f3660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3660ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2155 | PC: 0x0f37f0 | FDE: 0x1e34b0 | Size: 256 bytes
// Khung tháo gỡ #2155 | Địa chỉ PC: 0x0f37f0 | Địa chỉ FDE: 0x1e34b0 | Kích thước: 256 bytes
//   0x0f37f0: D10183FF  sub      sp, sp, #0x60
//   0x0f37f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f37f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f37fc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2155_0x0f37f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f37f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e34b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2156 | PC: 0x0f3978 | FDE: 0x1e34d8 | Size: 256 bytes
// Khung tháo gỡ #2156 | Địa chỉ PC: 0x0f3978 | Địa chỉ FDE: 0x1e34d8 | Kích thước: 256 bytes
//   0x0f3978: D10183FF  sub      sp, sp, #0x60
//   0x0f397c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f3980: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f3984: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2156_0x0f3978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3978ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e34d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2157 | PC: 0x0f3b00 | FDE: 0x1e3500 | Size: 128 bytes
// Khung tháo gỡ #2157 | Địa chỉ PC: 0x0f3b00 | Địa chỉ FDE: 0x1e3500 | Kích thước: 128 bytes
//   0x0f3b00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f3b04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3b08: 910043FD  add      x29, sp, #0x10
//   0x0f3b0c: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_2157_0x0f3b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3b00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3500ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2158 | PC: 0x0f3b80 | FDE: 0x1e3520 | Size: 168 bytes
// Khung tháo gỡ #2158 | Địa chỉ PC: 0x0f3b80 | Địa chỉ FDE: 0x1e3520 | Kích thước: 168 bytes
//   0x0f3b80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f3b84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3b88: 910043FD  add      x29, sp, #0x10
//   0x0f3b8c: 39408008  ldrb     w8, [x0, #0x20]
static inline uint64_t fde_func_2158_0x0f3b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3b80ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3520ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2159 | PC: 0x0f3c28 | FDE: 0x1e3540 | Size: 256 bytes
// Khung tháo gỡ #2159 | Địa chỉ PC: 0x0f3c28 | Địa chỉ FDE: 0x1e3540 | Kích thước: 256 bytes
//   0x0f3c28: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f3c2c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f3c30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f3c34: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2159_0x0f3c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3c28ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2160 | PC: 0x0f3dac | FDE: 0x1e3568 | Size: 256 bytes
// Khung tháo gỡ #2160 | Địa chỉ PC: 0x0f3dac | Địa chỉ FDE: 0x1e3568 | Kích thước: 256 bytes
//   0x0f3dac: D101C3FF  sub      sp, sp, #0x70
//   0x0f3db0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0f3db4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f3db8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2160_0x0f3dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3dacULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1e3568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2161 | PC: 0x0f3ff8 | FDE: 0x1e3598 | Size: 256 bytes
// Khung tháo gỡ #2161 | Địa chỉ PC: 0x0f3ff8 | Địa chỉ FDE: 0x1e3598 | Kích thước: 256 bytes
//   0x0f3ff8: D10243FF  sub      sp, sp, #0x90
//   0x0f3ffc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0f4000: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0f4004: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2161_0x0f3ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3ff8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e3598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2162 | PC: 0x0f4434 | FDE: 0x1e35c8 | Size: 204 bytes
// Khung tháo gỡ #2162 | Địa chỉ PC: 0x0f4434 | Địa chỉ FDE: 0x1e35c8 | Kích thước: 204 bytes
//   0x0f4434: D10103FF  sub      sp, sp, #0x40
//   0x0f4438: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f443c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f4440: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2162_0x0f4434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4434ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1e35c8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2163 | PC: 0x0f4500 | FDE: 0x1e35e8 | Size: 4 bytes
// Khung tháo gỡ #2163 | Địa chỉ PC: 0x0f4500 | Địa chỉ FDE: 0x1e35e8 | Kích thước: 4 bytes
//   0x0f4500: 17FD9848  b        #0x5a620
static inline uint64_t fde_func_2163_0x0f4500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4500ULL ^ (static_cast<uint64_t>(0x17fd9848ULL) << 13);
    acc = (acc + a1 + 0xd10103ffULL) ^ 0x1e35e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2164 | PC: 0x0f4504 | FDE: 0x1e3600 | Size: 232 bytes
// Khung tháo gỡ #2164 | Địa chỉ PC: 0x0f4504 | Địa chỉ FDE: 0x1e3600 | Kích thước: 232 bytes
//   0x0f4504: D10103FF  sub      sp, sp, #0x40
//   0x0f4508: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f450c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f4510: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2164_0x0f4504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4504ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1e3600ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #2165 | PC: 0x0f45ec | FDE: 0x1e3620 | Size: 256 bytes
// Khung tháo gỡ #2165 | Địa chỉ PC: 0x0f45ec | Địa chỉ FDE: 0x1e3620 | Kích thước: 256 bytes
//   0x0f45ec: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f45f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f45f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f45f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2165_0x0f45ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f45ecULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2166 | PC: 0x0f475c | FDE: 0x1e3648 | Size: 192 bytes
// Khung tháo gỡ #2166 | Địa chỉ PC: 0x0f475c | Địa chỉ FDE: 0x1e3648 | Kích thước: 192 bytes
//   0x0f475c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f4760: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4764: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4768: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2166_0x0f475c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f475cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3648ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2167 | PC: 0x0f481c | FDE: 0x1e3668 | Size: 132 bytes
// Khung tháo gỡ #2167 | Địa chỉ PC: 0x0f481c | Địa chỉ FDE: 0x1e3668 | Kích thước: 132 bytes
//   0x0f481c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f4820: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4824: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4828: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2167_0x0f481c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f481cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3668ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2168 | PC: 0x0f48a0 | FDE: 0x1e3688 | Size: 204 bytes
// Khung tháo gỡ #2168 | Địa chỉ PC: 0x0f48a0 | Địa chỉ FDE: 0x1e3688 | Kích thước: 204 bytes
//   0x0f48a0: D10103FF  sub      sp, sp, #0x40
//   0x0f48a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f48a8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f48ac: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2168_0x0f48a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f48a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1e3688ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2169 | PC: 0x0f496c | FDE: 0x1e36a8 | Size: 232 bytes
// Khung tháo gỡ #2169 | Địa chỉ PC: 0x0f496c | Địa chỉ FDE: 0x1e36a8 | Kích thước: 232 bytes
//   0x0f496c: D10103FF  sub      sp, sp, #0x40
//   0x0f4970: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f4974: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f4978: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2169_0x0f496c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f496cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1e36a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #2170 | PC: 0x0f4a54 | FDE: 0x1e36c8 | Size: 256 bytes
// Khung tháo gỡ #2170 | Địa chỉ PC: 0x0f4a54 | Địa chỉ FDE: 0x1e36c8 | Kích thước: 256 bytes
//   0x0f4a54: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f4a58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f4a5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f4a60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2170_0x0f4a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4a54ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e36c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2171 | PC: 0x0f4bc4 | FDE: 0x1e36f0 | Size: 132 bytes
// Khung tháo gỡ #2171 | Địa chỉ PC: 0x0f4bc4 | Địa chỉ FDE: 0x1e36f0 | Kích thước: 132 bytes
//   0x0f4bc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f4bc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4bcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4bd0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2171_0x0f4bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4bc4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e36f0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2172 | PC: 0x0f4c48 | FDE: 0x1e3710 | Size: 4 bytes
// Khung tháo gỡ #2172 | Địa chỉ PC: 0x0f4c48 | Địa chỉ FDE: 0x1e3710 | Kích thước: 4 bytes
//   0x0f4c48: 17FD9B7E  b        #0x5ba40
static inline uint64_t fde_func_2172_0x0f4c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4c48ULL ^ (static_cast<uint64_t>(0x17fd9b7eULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x1e3710ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2173 | PC: 0x0f4c4c | FDE: 0x1e3728 | Size: 228 bytes
// Khung tháo gỡ #2173 | Địa chỉ PC: 0x0f4c4c | Địa chỉ FDE: 0x1e3728 | Kích thước: 228 bytes
//   0x0f4c4c: D10143FF  sub      sp, sp, #0x50
//   0x0f4c50: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f4c54: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f4c58: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2173_0x0f4c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4c4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e3728ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #2174 | PC: 0x0f4d30 | FDE: 0x1e3750 | Size: 132 bytes
// Khung tháo gỡ #2174 | Địa chỉ PC: 0x0f4d30 | Địa chỉ FDE: 0x1e3750 | Kích thước: 132 bytes
//   0x0f4d30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f4d34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4d38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4d3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2174_0x0f4d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4d30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3750ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2175 | PC: 0x0f4db4 | FDE: 0x1e3770 | Size: 12 bytes
// Khung tháo gỡ #2175 | Địa chỉ PC: 0x0f4db4 | Địa chỉ FDE: 0x1e3770 | Kích thước: 12 bytes
//   0x0f4db4: F0000562  adrp     x2, #0x1a3000
//   0x0f4db8: 91382042  add      x2, x2, #0xe08
//   0x0f4dbc: 17FFB11C  b        #0xe122c
static inline uint64_t fde_func_2175_0x0f4db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4db4ULL ^ (static_cast<uint64_t>(0xf0000562ULL) << 13);
    acc = (acc + a1 + 0x91382042ULL) ^ 0x1e3770ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2176 | PC: 0x0f4dc0 | FDE: 0x1e3788 | Size: 192 bytes
// Khung tháo gỡ #2176 | Địa chỉ PC: 0x0f4dc0 | Địa chỉ FDE: 0x1e3788 | Kích thước: 192 bytes
//   0x0f4dc0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f4dc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4dc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4dcc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2176_0x0f4dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4dc0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3788ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2177 | PC: 0x0f4e80 | FDE: 0x1e37a8 | Size: 256 bytes
// Khung tháo gỡ #2177 | Địa chỉ PC: 0x0f4e80 | Địa chỉ FDE: 0x1e37a8 | Kích thước: 256 bytes
//   0x0f4e80: D10183FF  sub      sp, sp, #0x60
//   0x0f4e84: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f4e88: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f4e8c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2177_0x0f4e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4e80ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e37a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2178 | PC: 0x0f4fc8 | FDE: 0x1e37d0 | Size: 256 bytes
// Khung tháo gỡ #2178 | Địa chỉ PC: 0x0f4fc8 | Địa chỉ FDE: 0x1e37d0 | Kích thước: 256 bytes
//   0x0f4fc8: D10183FF  sub      sp, sp, #0x60
//   0x0f4fcc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f4fd0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f4fd4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2178_0x0f4fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4fc8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e37d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2179 | PC: 0x0f5110 | FDE: 0x1e37f8 | Size: 248 bytes
// Khung tháo gỡ #2179 | Địa chỉ PC: 0x0f5110 | Địa chỉ FDE: 0x1e37f8 | Kích thước: 248 bytes
//   0x0f5110: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f5114: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5118: 910043FD  add      x29, sp, #0x10
//   0x0f511c: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2179_0x0f5110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5110ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e37f8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2180 | PC: 0x0f5208 | FDE: 0x1e3818 | Size: 256 bytes
// Khung tháo gỡ #2180 | Địa chỉ PC: 0x0f5208 | Địa chỉ FDE: 0x1e3818 | Kích thước: 256 bytes
//   0x0f5208: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f520c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5210: 910043FD  add      x29, sp, #0x10
//   0x0f5214: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2180_0x0f5208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5208ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2181 | PC: 0x0f5308 | FDE: 0x1e3838 | Size: 72 bytes
// Khung tháo gỡ #2181 | Địa chỉ PC: 0x0f5308 | Địa chỉ FDE: 0x1e3838 | Kích thước: 72 bytes
//   0x0f5308: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f530c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5310: 910043FD  add      x29, sp, #0x10
//   0x0f5314: B9402008  ldr      w8, [x0, #0x20]
static inline uint64_t fde_func_2181_0x0f5308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5308ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3838ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2182 | PC: 0x0f5350 | FDE: 0x1e3858 | Size: 256 bytes
// Khung tháo gỡ #2182 | Địa chỉ PC: 0x0f5350 | Địa chỉ FDE: 0x1e3858 | Kích thước: 256 bytes
//   0x0f5350: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f5354: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f5358: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f535c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2182_0x0f5350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5350ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2183 | PC: 0x0f54a8 | FDE: 0x1e3880 | Size: 256 bytes
// Khung tháo gỡ #2183 | Địa chỉ PC: 0x0f54a8 | Địa chỉ FDE: 0x1e3880 | Kích thước: 256 bytes
//   0x0f54a8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f54ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f54b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f54b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2183_0x0f54a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f54a8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2184 | PC: 0x0f5604 | FDE: 0x1e38a8 | Size: 256 bytes
// Khung tháo gỡ #2184 | Địa chỉ PC: 0x0f5604 | Địa chỉ FDE: 0x1e38a8 | Kích thước: 256 bytes
//   0x0f5604: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0f5608: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f560c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f5610: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2184_0x0f5604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5604ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e38a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2185 | PC: 0x0f5794 | FDE: 0x1e38d0 | Size: 256 bytes
// Khung tháo gỡ #2185 | Địa chỉ PC: 0x0f5794 | Địa chỉ FDE: 0x1e38d0 | Kích thước: 256 bytes
//   0x0f5794: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f5798: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f579c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f57a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2185_0x0f5794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5794ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e38d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2186 | PC: 0x0f595c | FDE: 0x1e38f8 | Size: 256 bytes
// Khung tháo gỡ #2186 | Địa chỉ PC: 0x0f595c | Địa chỉ FDE: 0x1e38f8 | Kích thước: 256 bytes
//   0x0f595c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f5960: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5964: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5968: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2186_0x0f595c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f595cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e38f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2187 | PC: 0x0f5a84 | FDE: 0x1e3920 | Size: 256 bytes
// Khung tháo gỡ #2187 | Địa chỉ PC: 0x0f5a84 | Địa chỉ FDE: 0x1e3920 | Kích thước: 256 bytes
//   0x0f5a84: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f5a88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5a8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5a90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2187_0x0f5a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5a84ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2188 | PC: 0x0f5bac | FDE: 0x1e3948 | Size: 256 bytes
// Khung tháo gỡ #2188 | Địa chỉ PC: 0x0f5bac | Địa chỉ FDE: 0x1e3948 | Kích thước: 256 bytes
//   0x0f5bac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f5bb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5bb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5bb8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2188_0x0f5bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5bacULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2189 | PC: 0x0f5cd4 | FDE: 0x1e3970 | Size: 256 bytes
// Khung tháo gỡ #2189 | Địa chỉ PC: 0x0f5cd4 | Địa chỉ FDE: 0x1e3970 | Kích thước: 256 bytes
//   0x0f5cd4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f5cd8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f5cdc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f5ce0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2189_0x0f5cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5cd4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2190 | PC: 0x0f5e64 | FDE: 0x1e3998 | Size: 24 bytes
// Khung tháo gỡ #2190 | Địa chỉ PC: 0x0f5e64 | Địa chỉ FDE: 0x1e3998 | Kích thước: 24 bytes
//   0x0f5e64: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0f5e68: 910003FD  mov      x29, sp
//   0x0f5e6c: 97FD90B5  bl       #0x5a140
//   0x0f5e70: 93407C00  sxtw     x0, w0
static inline uint64_t fde_func_2190_0x0f5e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5e64ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e3998ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2191 | PC: 0x0f5e7c | FDE: 0x1e39b8 | Size: 256 bytes
// Khung tháo gỡ #2191 | Địa chỉ PC: 0x0f5e7c | Địa chỉ FDE: 0x1e39b8 | Kích thước: 256 bytes
//   0x0f5e7c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f5e80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5e84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5e88: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2191_0x0f5e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5e7cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e39b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2192 | PC: 0x0f5f9c | FDE: 0x1e39e0 | Size: 156 bytes
// Khung tháo gỡ #2192 | Địa chỉ PC: 0x0f5f9c | Địa chỉ FDE: 0x1e39e0 | Kích thước: 156 bytes
//   0x0f5f9c: D10183FF  sub      sp, sp, #0x60
//   0x0f5fa0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5fa4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0f5fa8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2192_0x0f5f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5f9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e39e0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2193 | PC: 0x0f6038 | FDE: 0x1e3a08 | Size: 152 bytes
// Khung tháo gỡ #2193 | Địa chỉ PC: 0x0f6038 | Địa chỉ FDE: 0x1e3a08 | Kích thước: 152 bytes
//   0x0f6038: D10183FF  sub      sp, sp, #0x60
//   0x0f603c: F9001BF5  str      x21, [sp, #0x30]
//   0x0f6040: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0f6044: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2193_0x0f6038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6038ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e3a08ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2194 | PC: 0x0f60d0 | FDE: 0x1e3a28 | Size: 256 bytes
// Khung tháo gỡ #2194 | Địa chỉ PC: 0x0f60d0 | Địa chỉ FDE: 0x1e3a28 | Kích thước: 256 bytes
//   0x0f60d0: D101C3FF  sub      sp, sp, #0x70
//   0x0f60d4: F90023F5  str      x21, [sp, #0x40]
//   0x0f60d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0f60dc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_2194_0x0f60d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f60d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1e3a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2195 | PC: 0x0f61f0 | FDE: 0x1e3a48 | Size: 256 bytes
// Khung tháo gỡ #2195 | Địa chỉ PC: 0x0f61f0 | Địa chỉ FDE: 0x1e3a48 | Kích thước: 256 bytes
//   0x0f61f0: B9402009  ldr      w9, [x0, #0x20]
//   0x0f61f4: 121B052A  and      w10, w9, #0x60
//   0x0f61f8: 7101815F  cmp      w10, #0x60
//   0x0f61fc: 54000180  b.eq     #0xf622c
static inline uint64_t fde_func_2195_0x0f61f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f61f0ULL ^ (static_cast<uint64_t>(0xb9402009ULL) << 13);
    acc = (acc + a1 + 0x121b052aULL) ^ 0x1e3a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2196 | PC: 0x0f6308 | FDE: 0x1e3a60 | Size: 44 bytes
// Khung tháo gỡ #2196 | Địa chỉ PC: 0x0f6308 | Địa chỉ FDE: 0x1e3a60 | Kích thước: 44 bytes
//   0x0f6308: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0f630c: 910003FD  mov      x29, sp
//   0x0f6310: 97FD8A4C  bl       #0x58c40
//   0x0f6314: B40000C0  cbz      x0, #0xf632c
static inline uint64_t fde_func_2196_0x0f6308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6308ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e3a60ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #2197 | PC: 0x0f6334 | FDE: 0x1e3a80 | Size: 256 bytes
// Khung tháo gỡ #2197 | Địa chỉ PC: 0x0f6334 | Địa chỉ FDE: 0x1e3a80 | Kích thước: 256 bytes
//   0x0f6334: D10143FF  sub      sp, sp, #0x50
//   0x0f6338: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f633c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f6340: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2197_0x0f6334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6334ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e3a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2198 | PC: 0x0f651c | FDE: 0x1e3aa8 | Size: 256 bytes
// Khung tháo gỡ #2198 | Địa chỉ PC: 0x0f651c | Địa chỉ FDE: 0x1e3aa8 | Kích thước: 256 bytes
//   0x0f651c: D101C3FF  sub      sp, sp, #0x70
//   0x0f6520: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0f6524: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f6528: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2198_0x0f651c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f651cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1e3aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2199 | PC: 0x0f66a0 | FDE: 0x1e3ad8 | Size: 256 bytes
// Khung tháo gỡ #2199 | Địa chỉ PC: 0x0f66a0 | Địa chỉ FDE: 0x1e3ad8 | Kích thước: 256 bytes
//   0x0f66a0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0f66a4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f66a8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f66ac: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2199_0x0f66a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f66a0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e3ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2200 | PC: 0x0f67d0 | FDE: 0x1e3b00 | Size: 256 bytes
// Khung tháo gỡ #2200 | Địa chỉ PC: 0x0f67d0 | Địa chỉ FDE: 0x1e3b00 | Kích thước: 256 bytes
//   0x0f67d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f67d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f67d8: 910043FD  add      x29, sp, #0x10
//   0x0f67dc: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_2200_0x0f67d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f67d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2201 | PC: 0x0f68f8 | FDE: 0x1e3b20 | Size: 256 bytes
// Khung tháo gỡ #2201 | Địa chỉ PC: 0x0f68f8 | Địa chỉ FDE: 0x1e3b20 | Kích thước: 256 bytes
//   0x0f68f8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0f68fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f6900: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f6904: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2201_0x0f68f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f68f8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e3b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2202 | PC: 0x0f6b58 | FDE: 0x1e3b50 | Size: 256 bytes
// Khung tháo gỡ #2202 | Địa chỉ PC: 0x0f6b58 | Địa chỉ FDE: 0x1e3b50 | Kích thước: 256 bytes
//   0x0f6b58: D10303FF  sub      sp, sp, #0xc0
//   0x0f6b5c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0f6b60: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0f6b64: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_2202_0x0f6b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6b58ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x1e3b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2203 | PC: 0x0f6c90 | FDE: 0x1e3b80 | Size: 256 bytes
// Khung tháo gỡ #2203 | Địa chỉ PC: 0x0f6c90 | Địa chỉ FDE: 0x1e3b80 | Kích thước: 256 bytes
//   0x0f6c90: D101C3FF  sub      sp, sp, #0x70
//   0x0f6c94: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0f6c98: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f6c9c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2203_0x0f6c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6c90ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1e3b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2204 | PC: 0x0f6da8 | FDE: 0x1e3bb0 | Size: 256 bytes
// Khung tháo gỡ #2204 | Địa chỉ PC: 0x0f6da8 | Địa chỉ FDE: 0x1e3bb0 | Kích thước: 256 bytes
//   0x0f6da8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0f6dac: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f6db0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f6db4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2204_0x0f6da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6da8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e3bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2205 | PC: 0x0f704c | FDE: 0x1e3bd8 | Size: 256 bytes
// Khung tháo gỡ #2205 | Địa chỉ PC: 0x0f704c | Địa chỉ FDE: 0x1e3bd8 | Kích thước: 256 bytes
//   0x0f704c: D101C3FF  sub      sp, sp, #0x70
//   0x0f7050: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0f7054: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f7058: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2205_0x0f704c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f704cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1e3bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2206 | PC: 0x0f7154 | FDE: 0x1e3c08 | Size: 256 bytes
// Khung tháo gỡ #2206 | Địa chỉ PC: 0x0f7154 | Địa chỉ FDE: 0x1e3c08 | Kích thước: 256 bytes
//   0x0f7154: D10403FF  sub      sp, sp, #0x100
//   0x0f7158: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x0f715c: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x0f7160: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_2206_0x0f7154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7154ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90c5ff8ULL) ^ 0x1e3c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2207 | PC: 0x0f7304 | FDE: 0x1e3c30 | Size: 256 bytes
// Khung tháo gỡ #2207 | Địa chỉ PC: 0x0f7304 | Địa chỉ FDE: 0x1e3c30 | Kích thước: 256 bytes
//   0x0f7304: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0f7308: 910003FD  mov      x29, sp
//   0x0f730c: A9007C3F  stp      xzr, xzr, [x1]
//   0x0f7310: F900083F  str      xzr, [x1, #0x10]
static inline uint64_t fde_func_2207_0x0f7304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7304ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e3c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2208 | PC: 0x0f7a30 | FDE: 0x1e3c50 | Size: 256 bytes
// Khung tháo gỡ #2208 | Địa chỉ PC: 0x0f7a30 | Địa chỉ FDE: 0x1e3c50 | Kích thước: 256 bytes
//   0x0f7a30: D10383FF  sub      sp, sp, #0xe0
//   0x0f7a34: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0f7a38: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0f7a3c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_2208_0x0f7a30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7a30ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1e3c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2209 | PC: 0x0f7fb0 | FDE: 0x1e3c80 | Size: 256 bytes
// Khung tháo gỡ #2209 | Địa chỉ PC: 0x0f7fb0 | Địa chỉ FDE: 0x1e3c80 | Kích thước: 256 bytes
//   0x0f7fb0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f7fb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f7fb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f7fbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2209_0x0f7fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7fb0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e3c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2210 | PC: 0x0f8174 | FDE: 0x1e3ca0 | Size: 44 bytes
// Khung tháo gỡ #2210 | Địa chỉ PC: 0x0f8174 | Địa chỉ FDE: 0x1e3ca0 | Kích thước: 44 bytes
//   0x0f8174: F9400008  ldr      x8, [x0]
//   0x0f8178: B4000088  cbz      x8, #0xf8188
//   0x0f817c: A9408801  ldp      x1, x2, [x0, #8]
//   0x0f8180: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_2210_0x0f8174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8174ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb4000088ULL) ^ 0x1e3ca0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #2211 | PC: 0x0f81a0 | FDE: 0x1e3cb8 | Size: 256 bytes
// Khung tháo gỡ #2211 | Địa chỉ PC: 0x0f81a0 | Địa chỉ FDE: 0x1e3cb8 | Kích thước: 256 bytes
//   0x0f81a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f81a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f81a8: 910043FD  add      x29, sp, #0x10
//   0x0f81ac: A9412C08  ldp      x8, x11, [x0, #0x10]
static inline uint64_t fde_func_2211_0x0f81a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f81a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2212 | PC: 0x0f84a8 | FDE: 0x1e3cd8 | Size: 256 bytes
// Khung tháo gỡ #2212 | Địa chỉ PC: 0x0f84a8 | Địa chỉ FDE: 0x1e3cd8 | Kích thước: 256 bytes
//   0x0f84a8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f84ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f84b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f84b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2212_0x0f84a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f84a8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2213 | PC: 0x0f85e4 | FDE: 0x1e3d00 | Size: 60 bytes
// Khung tháo gỡ #2213 | Địa chỉ PC: 0x0f85e4 | Địa chỉ FDE: 0x1e3d00 | Kích thước: 60 bytes
//   0x0f85e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f85e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f85ec: 910043FD  add      x29, sp, #0x10
//   0x0f85f0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2213_0x0f85e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f85e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3d00ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2214 | PC: 0x0f8620 | FDE: 0x1e3d20 | Size: 248 bytes
// Khung tháo gỡ #2214 | Địa chỉ PC: 0x0f8620 | Địa chỉ FDE: 0x1e3d20 | Kích thước: 248 bytes
//   0x0f8620: D10143FF  sub      sp, sp, #0x50
//   0x0f8624: F90013F5  str      x21, [sp, #0x20]
//   0x0f8628: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f862c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2214_0x0f8620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8620ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e3d20ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2215 | PC: 0x0f8718 | FDE: 0x1e3d40 | Size: 60 bytes
// Khung tháo gỡ #2215 | Địa chỉ PC: 0x0f8718 | Địa chỉ FDE: 0x1e3d40 | Kích thước: 60 bytes
//   0x0f8718: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f871c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8720: 910043FD  add      x29, sp, #0x10
//   0x0f8724: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2215_0x0f8718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8718ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3d40ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2216 | PC: 0x0f8754 | FDE: 0x1e3d60 | Size: 256 bytes
// Khung tháo gỡ #2216 | Địa chỉ PC: 0x0f8754 | Địa chỉ FDE: 0x1e3d60 | Kích thước: 256 bytes
//   0x0f8754: D10283FF  sub      sp, sp, #0xa0
//   0x0f8758: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0f875c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0f8760: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_2216_0x0f8754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8754ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1e3d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2217 | PC: 0x0f892c | FDE: 0x1e3d88 | Size: 32 bytes
// Khung tháo gỡ #2217 | Địa chỉ PC: 0x0f892c | Địa chỉ FDE: 0x1e3d88 | Kích thước: 32 bytes
//   0x0f892c: F9400008  ldr      x8, [x0]
//   0x0f8930: B4000088  cbz      x8, #0xf8940
//   0x0f8934: A9408801  ldp      x1, x2, [x0, #8]
//   0x0f8938: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_2217_0x0f892c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f892cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb4000088ULL) ^ 0x1e3d88ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2218 | PC: 0x0f894c | FDE: 0x1e3da0 | Size: 32 bytes
// Khung tháo gỡ #2218 | Địa chỉ PC: 0x0f894c | Địa chỉ FDE: 0x1e3da0 | Kích thước: 32 bytes
//   0x0f894c: F9400C08  ldr      x8, [x0, #0x18]
//   0x0f8950: B40000A8  cbz      x8, #0xf8964
//   0x0f8954: F9400908  ldr      x8, [x8, #0x10]
//   0x0f8958: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_2218_0x0f894c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f894cULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000a8ULL) ^ 0x1e3da0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2219 | PC: 0x0f896c | FDE: 0x1e3db8 | Size: 140 bytes
// Khung tháo gỡ #2219 | Địa chỉ PC: 0x0f896c | Địa chỉ FDE: 0x1e3db8 | Kích thước: 140 bytes
//   0x0f896c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f8970: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8974: 910043FD  add      x29, sp, #0x10
//   0x0f8978: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_2219_0x0f896c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f896cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3db8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2220 | PC: 0x0f89f8 | FDE: 0x1e3dd8 | Size: 120 bytes
// Khung tháo gỡ #2220 | Địa chỉ PC: 0x0f89f8 | Địa chỉ FDE: 0x1e3dd8 | Kích thước: 120 bytes
//   0x0f89f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f89fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8a00: 910043FD  add      x29, sp, #0x10
//   0x0f8a04: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2220_0x0f89f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f89f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3dd8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2221 | PC: 0x0f8a70 | FDE: 0x1e3df8 | Size: 256 bytes
// Khung tháo gỡ #2221 | Địa chỉ PC: 0x0f8a70 | Địa chỉ FDE: 0x1e3df8 | Kích thước: 256 bytes
//   0x0f8a70: D10103FF  sub      sp, sp, #0x40
//   0x0f8a74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f8a78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f8a7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2221_0x0f8a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8a70ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e3df8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2222 | PC: 0x0f8bc4 | FDE: 0x1e3e20 | Size: 256 bytes
// Khung tháo gỡ #2222 | Địa chỉ PC: 0x0f8bc4 | Địa chỉ FDE: 0x1e3e20 | Kích thước: 256 bytes
//   0x0f8bc4: D10143FF  sub      sp, sp, #0x50
//   0x0f8bc8: F90013F5  str      x21, [sp, #0x20]
//   0x0f8bcc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f8bd0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2222_0x0f8bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8bc4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e3e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2223 | PC: 0x0f8d2c | FDE: 0x1e3e40 | Size: 144 bytes
// Khung tháo gỡ #2223 | Địa chỉ PC: 0x0f8d2c | Địa chỉ FDE: 0x1e3e40 | Kích thước: 144 bytes
//   0x0f8d2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f8d30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8d34: 910043FD  add      x29, sp, #0x10
//   0x0f8d38: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2223_0x0f8d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e3e40ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2224 | PC: 0x0f8dbc | FDE: 0x1e3e60 | Size: 256 bytes [_PyUnicode_ToNumeric]
// Khung tháo gỡ #2224 | Địa chỉ PC: 0x0f8dbc | Địa chỉ FDE: 0x1e3e60 | Kích thước: 256 bytes
//   0x0f8dbc: 52810AE8  mov      w8, #0x857
//   0x0f8dc0: 72A00028  movk     w8, #1, lsl #16
//   0x0f8dc4: 6B08001F  cmp      w0, w8
//   0x0f8dc8: 540002EC  b.gt     #0xf8e24
static inline uint64_t fde_func_2224_0x0f8dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8dbcULL ^ (static_cast<uint64_t>(0x52810ae8ULL) << 13);
    acc = (acc + a1 + 0x72a00028ULL) ^ 0x1e3e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2225 | PC: 0x0f9de4 | FDE: 0x1e3e78 | Size: 144 bytes [_PyUnicode_IsWhitespace]
// Khung tháo gỡ #2225 | Địa chỉ PC: 0x0f9de4 | Địa chỉ FDE: 0x1e3e78 | Kích thước: 144 bytes
//   0x0f9de4: 5282CFE9  mov      w9, #0x167f
//   0x0f9de8: 2A0003E8  mov      w8, w0
//   0x0f9dec: 6B09001F  cmp      w0, w9
//   0x0f9df0: 52800020  mov      w0, #1
static inline uint64_t fde_func_2225_0x0f9de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9de4ULL ^ (static_cast<uint64_t>(0x5282cfe9ULL) << 13);
    acc = (acc + a1 + 0x2a0003e8ULL) ^ 0x1e3e78ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2226 | PC: 0x0f9e74 | FDE: 0x1e3e90 | Size: 72 bytes [_PyUnicode_IsLinebreak]
// Khung tháo gỡ #2226 | Địa chỉ PC: 0x0f9e74 | Địa chỉ FDE: 0x1e3e90 | Kích thước: 72 bytes
//   0x0f9e74: 2A0003E8  mov      w8, w0
//   0x0f9e78: 7100781F  cmp      w0, #0x1e
//   0x0f9e7c: 52800020  mov      w0, #1
//   0x0f9e80: 540000C8  b.hi     #0xf9e98
static inline uint64_t fde_func_2226_0x0f9e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9e74ULL ^ (static_cast<uint64_t>(0x2a0003e8ULL) << 13);
    acc = (acc + a1 + 0x7100781fULL) ^ 0x1e3e90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2227 | PC: 0x0f9ebc | FDE: 0x1e3ea8 | Size: 124 bytes [_PyUnicode_ToTitlecase]
// Khung tháo gỡ #2227 | Địa chỉ PC: 0x0f9ebc | Địa chỉ FDE: 0x1e3ea8 | Kích thước: 124 bytes
//   0x0f9ebc: 53107C08  lsr      w8, w0, #0x10
//   0x0f9ec0: 7100411F  cmp      w8, #0x10
//   0x0f9ec4: 54000069  b.ls     #0xf9ed0
//   0x0f9ec8: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2227_0x0f9ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9ebcULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ea8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2228 | PC: 0x0f9f38 | FDE: 0x1e3ec0 | Size: 88 bytes [_PyUnicode_IsTitlecase]
// Khung tháo gỡ #2228 | Địa chỉ PC: 0x0f9f38 | Địa chỉ FDE: 0x1e3ec0 | Kích thước: 88 bytes
//   0x0f9f38: 53107C08  lsr      w8, w0, #0x10
//   0x0f9f3c: 7100411F  cmp      w8, #0x10
//   0x0f9f40: 54000069  b.ls     #0xf9f4c
//   0x0f9f44: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2228_0x0f9f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9f38ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ec0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2229 | PC: 0x0f9f90 | FDE: 0x1e3ed8 | Size: 88 bytes [_PyUnicode_IsXidStart]
// Khung tháo gỡ #2229 | Địa chỉ PC: 0x0f9f90 | Địa chỉ FDE: 0x1e3ed8 | Kích thước: 88 bytes
//   0x0f9f90: 53107C08  lsr      w8, w0, #0x10
//   0x0f9f94: 7100411F  cmp      w8, #0x10
//   0x0f9f98: 54000069  b.ls     #0xf9fa4
//   0x0f9f9c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2229_0x0f9f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9f90ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ed8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2230 | PC: 0x0f9fe8 | FDE: 0x1e3ef0 | Size: 256 bytes [_PyUnicode_IsXidContinue]
// Khung tháo gỡ #2230 | Địa chỉ PC: 0x0f9fe8 | Địa chỉ FDE: 0x1e3ef0 | Kích thước: 256 bytes
//   0x0f9fe8: 53107C08  lsr      w8, w0, #0x10
//   0x0f9fec: 7100411F  cmp      w8, #0x10
//   0x0f9ff0: 54000069  b.ls     #0xf9ffc
//   0x0f9ff4: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2230_0x0f9fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9fe8ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2231 | PC: 0x0fb040 | FDE: 0x1e3f08 | Size: 100 bytes [_PyUnicode_ToDecimalDigit]
// Khung tháo gỡ #2231 | Địa chỉ PC: 0x0fb040 | Địa chỉ FDE: 0x1e3f08 | Kích thước: 100 bytes
//   0x0fb040: 53107C08  lsr      w8, w0, #0x10
//   0x0fb044: 7100411F  cmp      w8, #0x10
//   0x0fb048: 54000069  b.ls     #0xfb054
//   0x0fb04c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2231_0x0fb040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb040ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f08ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2232 | PC: 0x0fb0a4 | FDE: 0x1e3f20 | Size: 88 bytes [_PyUnicode_IsDecimalDigit]
// Khung tháo gỡ #2232 | Địa chỉ PC: 0x0fb0a4 | Địa chỉ FDE: 0x1e3f20 | Kích thước: 88 bytes
//   0x0fb0a4: 53107C08  lsr      w8, w0, #0x10
//   0x0fb0a8: 7100411F  cmp      w8, #0x10
//   0x0fb0ac: 54000069  b.ls     #0xfb0b8
//   0x0fb0b0: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2232_0x0fb0a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb0a4ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f20ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2233 | PC: 0x0fb0fc | FDE: 0x1e3f38 | Size: 100 bytes [_PyUnicode_ToDigit]
// Khung tháo gỡ #2233 | Địa chỉ PC: 0x0fb0fc | Địa chỉ FDE: 0x1e3f38 | Kích thước: 100 bytes
//   0x0fb0fc: 53107C08  lsr      w8, w0, #0x10
//   0x0fb100: 7100411F  cmp      w8, #0x10
//   0x0fb104: 54000069  b.ls     #0xfb110
//   0x0fb108: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2233_0x0fb0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb0fcULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2234 | PC: 0x0fb160 | FDE: 0x1e3f50 | Size: 88 bytes [_PyUnicode_IsDigit]
// Khung tháo gỡ #2234 | Địa chỉ PC: 0x0fb160 | Địa chỉ FDE: 0x1e3f50 | Kích thước: 88 bytes
//   0x0fb160: 53107C08  lsr      w8, w0, #0x10
//   0x0fb164: 7100411F  cmp      w8, #0x10
//   0x0fb168: 54000069  b.ls     #0xfb174
//   0x0fb16c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2234_0x0fb160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb160ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f50ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2235 | PC: 0x0fb1b8 | FDE: 0x1e3f68 | Size: 88 bytes [_PyUnicode_IsNumeric]
// Khung tháo gỡ #2235 | Địa chỉ PC: 0x0fb1b8 | Địa chỉ FDE: 0x1e3f68 | Kích thước: 88 bytes
//   0x0fb1b8: 53107C08  lsr      w8, w0, #0x10
//   0x0fb1bc: 7100411F  cmp      w8, #0x10
//   0x0fb1c0: 54000069  b.ls     #0xfb1cc
//   0x0fb1c4: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2235_0x0fb1b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb1b8ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f68ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2236 | PC: 0x0fb210 | FDE: 0x1e3f80 | Size: 88 bytes [_PyUnicode_IsPrintable]
// Khung tháo gỡ #2236 | Địa chỉ PC: 0x0fb210 | Địa chỉ FDE: 0x1e3f80 | Kích thước: 88 bytes
//   0x0fb210: 53107C08  lsr      w8, w0, #0x10
//   0x0fb214: 7100411F  cmp      w8, #0x10
//   0x0fb218: 54000069  b.ls     #0xfb224
//   0x0fb21c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2236_0x0fb210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb210ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f80ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2237 | PC: 0x0fb268 | FDE: 0x1e3f98 | Size: 88 bytes [_PyUnicode_IsLowercase]
// Khung tháo gỡ #2237 | Địa chỉ PC: 0x0fb268 | Địa chỉ FDE: 0x1e3f98 | Kích thước: 88 bytes
//   0x0fb268: 53107C08  lsr      w8, w0, #0x10
//   0x0fb26c: 7100411F  cmp      w8, #0x10
//   0x0fb270: 54000069  b.ls     #0xfb27c
//   0x0fb274: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2237_0x0fb268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb268ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f98ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2238 | PC: 0x0fb2c0 | FDE: 0x1e3fb0 | Size: 88 bytes [_PyUnicode_IsUppercase]
// Khung tháo gỡ #2238 | Địa chỉ PC: 0x0fb2c0 | Địa chỉ FDE: 0x1e3fb0 | Kích thước: 88 bytes
//   0x0fb2c0: 53107C08  lsr      w8, w0, #0x10
//   0x0fb2c4: 7100411F  cmp      w8, #0x10
//   0x0fb2c8: 54000069  b.ls     #0xfb2d4
//   0x0fb2cc: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2238_0x0fb2c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb2c0ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3fb0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2239 | PC: 0x0fb318 | FDE: 0x1e3fc8 | Size: 124 bytes [_PyUnicode_ToUppercase]
// Khung tháo gỡ #2239 | Địa chỉ PC: 0x0fb318 | Địa chỉ FDE: 0x1e3fc8 | Kích thước: 124 bytes
//   0x0fb318: 53107C08  lsr      w8, w0, #0x10
//   0x0fb31c: 7100411F  cmp      w8, #0x10
//   0x0fb320: 54000069  b.ls     #0xfb32c
//   0x0fb324: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2239_0x0fb318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb318ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3fc8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2240 | PC: 0x0fb394 | FDE: 0x1e3fe0 | Size: 124 bytes [_PyUnicode_ToLowercase]
// Khung tháo gỡ #2240 | Địa chỉ PC: 0x0fb394 | Địa chỉ FDE: 0x1e3fe0 | Kích thước: 124 bytes
//   0x0fb394: 53107C08  lsr      w8, w0, #0x10
//   0x0fb398: 7100411F  cmp      w8, #0x10
//   0x0fb39c: 54000069  b.ls     #0xfb3a8
//   0x0fb3a0: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2240_0x0fb394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb394ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3fe0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2241 | PC: 0x0fb410 | FDE: 0x1e3ff8 | Size: 256 bytes [_PyUnicode_ToLowerFull]
// Khung tháo gỡ #2241 | Địa chỉ PC: 0x0fb410 | Địa chỉ FDE: 0x1e3ff8 | Kích thước: 256 bytes
//   0x0fb410: 53107C08  lsr      w8, w0, #0x10
//   0x0fb414: 7100411F  cmp      w8, #0x10
//   0x0fb418: 54000069  b.ls     #0xfb424
//   0x0fb41c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2241_0x0fb410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb410ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2242 | PC: 0x0fb530 | FDE: 0x1e4010 | Size: 256 bytes [_PyUnicode_ToTitleFull]
// Khung tháo gỡ #2242 | Địa chỉ PC: 0x0fb530 | Địa chỉ FDE: 0x1e4010 | Kích thước: 256 bytes
//   0x0fb530: 53107C08  lsr      w8, w0, #0x10
//   0x0fb534: 7100411F  cmp      w8, #0x10
//   0x0fb538: 54000069  b.ls     #0xfb544
//   0x0fb53c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2242_0x0fb530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb530ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2243 | PC: 0x0fb650 | FDE: 0x1e4028 | Size: 256 bytes [_PyUnicode_ToUpperFull]
// Khung tháo gỡ #2243 | Địa chỉ PC: 0x0fb650 | Địa chỉ FDE: 0x1e4028 | Kích thước: 256 bytes
//   0x0fb650: 53107C08  lsr      w8, w0, #0x10
//   0x0fb654: 7100411F  cmp      w8, #0x10
//   0x0fb658: 54000069  b.ls     #0xfb664
//   0x0fb65c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2243_0x0fb650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb650ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2244 | PC: 0x0fb770 | FDE: 0x1e4040 | Size: 256 bytes [_PyUnicode_ToFoldedFull]
// Khung tháo gỡ #2244 | Địa chỉ PC: 0x0fb770 | Địa chỉ FDE: 0x1e4040 | Kích thước: 256 bytes
//   0x0fb770: 90000829  adrp     x9, #0x1ff000
//   0x0fb774: 9000082B  adrp     x11, #0x1ff000
//   0x0fb778: F9449129  ldr      x9, [x9, #0x920]
//   0x0fb77c: F947156B  ldr      x11, [x11, #0xe28]
static inline uint64_t fde_func_2244_0x0fb770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb770ULL ^ (static_cast<uint64_t>(0x90000829ULL) << 13);
    acc = (acc + a1 + 0x9000082bULL) ^ 0x1e4040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2245 | PC: 0x0fb904 | FDE: 0x1e4058 | Size: 88 bytes [_PyUnicode_IsCased]
// Khung tháo gỡ #2245 | Địa chỉ PC: 0x0fb904 | Địa chỉ FDE: 0x1e4058 | Kích thước: 88 bytes
//   0x0fb904: 53107C08  lsr      w8, w0, #0x10
//   0x0fb908: 7100411F  cmp      w8, #0x10
//   0x0fb90c: 54000069  b.ls     #0xfb918
//   0x0fb910: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2245_0x0fb904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb904ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4058ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2246 | PC: 0x0fb95c | FDE: 0x1e4070 | Size: 88 bytes [_PyUnicode_IsCaseIgnorable]
// Khung tháo gỡ #2246 | Địa chỉ PC: 0x0fb95c | Địa chỉ FDE: 0x1e4070 | Kích thước: 88 bytes
//   0x0fb95c: 53107C08  lsr      w8, w0, #0x10
//   0x0fb960: 7100411F  cmp      w8, #0x10
//   0x0fb964: 54000069  b.ls     #0xfb970
//   0x0fb968: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2246_0x0fb95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb95cULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4070ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2247 | PC: 0x0fb9b4 | FDE: 0x1e4088 | Size: 88 bytes [_PyUnicode_IsAlpha]
// Khung tháo gỡ #2247 | Địa chỉ PC: 0x0fb9b4 | Địa chỉ FDE: 0x1e4088 | Kích thước: 88 bytes
//   0x0fb9b4: 53107C08  lsr      w8, w0, #0x10
//   0x0fb9b8: 7100411F  cmp      w8, #0x10
//   0x0fb9bc: 54000069  b.ls     #0xfb9c8
//   0x0fb9c0: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_2247_0x0fb9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb9b4ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4088ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2248 | PC: 0x0fba0c | FDE: 0x1e40a0 | Size: 256 bytes [_Py_union_type_or]
// Khung tháo gỡ #2248 | Địa chỉ PC: 0x0fba0c | Địa chỉ FDE: 0x1e40a0 | Kích thước: 256 bytes
//   0x0fba0c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fba10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fba14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fba18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2248_0x0fba0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fba0cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e40a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2249 | PC: 0x0fbb20 | FDE: 0x1e40c8 | Size: 256 bytes
// Khung tháo gỡ #2249 | Địa chỉ PC: 0x0fbb20 | Địa chỉ FDE: 0x1e40c8 | Kích thước: 256 bytes
//   0x0fbb20: D10203FF  sub      sp, sp, #0x80
//   0x0fbb24: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0fbb28: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fbb2c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2249_0x0fbb20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbb20ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e40c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2250 | PC: 0x0fbf1c | FDE: 0x1e40f8 | Size: 108 bytes
// Khung tháo gỡ #2250 | Địa chỉ PC: 0x0fbf1c | Địa chỉ FDE: 0x1e40f8 | Kích thước: 108 bytes
//   0x0fbf1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fbf20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fbf24: 910043FD  add      x29, sp, #0x10
//   0x0fbf28: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2250_0x0fbf1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbf1cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e40f8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #2251 | PC: 0x0fbf88 | FDE: 0x1e4118 | Size: 256 bytes
// Khung tháo gỡ #2251 | Địa chỉ PC: 0x0fbf88 | Địa chỉ FDE: 0x1e4118 | Kích thước: 256 bytes
//   0x0fbf88: D10303FF  sub      sp, sp, #0xc0
//   0x0fbf8c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0fbf90: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0fbf94: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_2251_0x0fbf88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbf88ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1e4118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2252 | PC: 0x0fc238 | FDE: 0x1e4148 | Size: 84 bytes
// Khung tháo gỡ #2252 | Địa chỉ PC: 0x0fc238 | Địa chỉ FDE: 0x1e4148 | Kích thước: 84 bytes
//   0x0fc238: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fc23c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fc240: 910043FD  add      x29, sp, #0x10
//   0x0fc244: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_2252_0x0fc238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc238ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4148ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2253 | PC: 0x0fc28c | FDE: 0x1e4168 | Size: 92 bytes
// Khung tháo gỡ #2253 | Địa chỉ PC: 0x0fc28c | Địa chỉ FDE: 0x1e4168 | Kích thước: 92 bytes
//   0x0fc28c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fc290: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fc294: 910043FD  add      x29, sp, #0x10
//   0x0fc298: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2253_0x0fc28c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc28cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4168ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #2254 | PC: 0x0fc2e8 | FDE: 0x1e4188 | Size: 88 bytes
// Khung tháo gỡ #2254 | Địa chỉ PC: 0x0fc2e8 | Địa chỉ FDE: 0x1e4188 | Kích thước: 88 bytes
//   0x0fc2e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fc2ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fc2f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fc2f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2254_0x0fc2e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc2e8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4188ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2255 | PC: 0x0fc340 | FDE: 0x1e41a8 | Size: 232 bytes
// Khung tháo gỡ #2255 | Địa chỉ PC: 0x0fc340 | Địa chỉ FDE: 0x1e41a8 | Kích thước: 232 bytes
//   0x0fc340: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fc344: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fc348: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fc34c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2255_0x0fc340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc340ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e41a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #2256 | PC: 0x0fc428 | FDE: 0x1e41c8 | Size: 256 bytes
// Khung tháo gỡ #2256 | Địa chỉ PC: 0x0fc428 | Địa chỉ FDE: 0x1e41c8 | Kích thước: 256 bytes
//   0x0fc428: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fc42c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fc430: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fc434: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2256_0x0fc428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc428ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e41c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2257 | PC: 0x0fc52c | FDE: 0x1e41f0 | Size: 252 bytes
// Khung tháo gỡ #2257 | Địa chỉ PC: 0x0fc52c | Địa chỉ FDE: 0x1e41f0 | Kích thước: 252 bytes
//   0x0fc52c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0fc530: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fc534: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fc538: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2257_0x0fc52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc52cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e41f0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #2258 | PC: 0x0fc628 | FDE: 0x1e4218 | Size: 256 bytes
// Khung tháo gỡ #2258 | Địa chỉ PC: 0x0fc628 | Địa chỉ FDE: 0x1e4218 | Kích thước: 256 bytes
//   0x0fc628: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fc62c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fc630: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fc634: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2258_0x0fc628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc628ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2259 | PC: 0x0fc748 | FDE: 0x1e4240 | Size: 64 bytes
// Khung tháo gỡ #2259 | Địa chỉ PC: 0x0fc748 | Địa chỉ FDE: 0x1e4240 | Kích thước: 64 bytes
//   0x0fc748: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fc74c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fc750: 910043FD  add      x29, sp, #0x10
//   0x0fc754: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2259_0x0fc748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc748ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4240ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2260 | PC: 0x0fc788 | FDE: 0x1e4260 | Size: 28 bytes [_PyWeakref_GetWeakrefCount]
// Khung tháo gỡ #2260 | Địa chỉ PC: 0x0fc788 | Địa chỉ FDE: 0x1e4260 | Kích thước: 28 bytes
//   0x0fc788: AA1F03E8  mov      x8, xzr
//   0x0fc78c: B4000080  cbz      x0, #0xfc79c
//   0x0fc790: F9401800  ldr      x0, [x0, #0x30]
//   0x0fc794: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_2260_0x0fc788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc788ULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1e4260ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2261 | PC: 0x0fc7a4 | FDE: 0x1e4278 | Size: 100 bytes [_PyWeakref_ClearRef]
// Khung tháo gỡ #2261 | Địa chỉ PC: 0x0fc7a4 | Địa chỉ FDE: 0x1e4278 | Kích thước: 100 bytes
//   0x0fc7a4: F000080A  adrp     x10, #0x1ff000
//   0x0fc7a8: A9412009  ldp      x9, x8, [x0, #0x10]
//   0x0fc7ac: F945F14A  ldr      x10, [x10, #0xbe0]
//   0x0fc7b0: F9000C1F  str      xzr, [x0, #0x18]
static inline uint64_t fde_func_2261_0x0fc7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc7a4ULL ^ (static_cast<uint64_t>(0xf000080aULL) << 13);
    acc = (acc + a1 + 0xa9412009ULL) ^ 0x1e4278ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2262 | PC: 0x0fc808 | FDE: 0x1e4290 | Size: 160 bytes
// Khung tháo gỡ #2262 | Địa chỉ PC: 0x0fc808 | Địa chỉ FDE: 0x1e4290 | Kích thước: 160 bytes
//   0x0fc808: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fc80c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fc810: 910043FD  add      x29, sp, #0x10
//   0x0fc814: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2262_0x0fc808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc808ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4290ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2263 | PC: 0x0fc8a8 | FDE: 0x1e42b0 | Size: 256 bytes
// Khung tháo gỡ #2263 | Địa chỉ PC: 0x0fc8a8 | Địa chỉ FDE: 0x1e42b0 | Kích thước: 256 bytes
//   0x0fc8a8: D10103FF  sub      sp, sp, #0x40
//   0x0fc8ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fc8b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fc8b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2263_0x0fc8a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc8a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e42b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2264 | PC: 0x0fca20 | FDE: 0x1e42d8 | Size: 152 bytes
// Khung tháo gỡ #2264 | Địa chỉ PC: 0x0fca20 | Địa chỉ FDE: 0x1e42d8 | Kích thước: 152 bytes
//   0x0fca20: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fca24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fca28: 910043FD  add      x29, sp, #0x10
//   0x0fca2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2264_0x0fca20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fca20ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e42d8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2265 | PC: 0x0fcab8 | FDE: 0x1e42f8 | Size: 108 bytes
// Khung tháo gỡ #2265 | Địa chỉ PC: 0x0fcab8 | Địa chỉ FDE: 0x1e42f8 | Kích thước: 108 bytes
//   0x0fcab8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fcabc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fcac0: 910043FD  add      x29, sp, #0x10
//   0x0fcac4: AA0203E8  mov      x8, x2
static inline uint64_t fde_func_2265_0x0fcab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcab8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e42f8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #2266 | PC: 0x0fcb24 | FDE: 0x1e4318 | Size: 52 bytes
// Khung tháo gỡ #2266 | Địa chỉ PC: 0x0fcb24 | Địa chỉ FDE: 0x1e4318 | Kích thước: 52 bytes
//   0x0fcb24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fcb28: 910003FD  mov      x29, sp
//   0x0fcb2c: F9400C00  ldr      x0, [x0, #0x18]
//   0x0fcb30: B40000E0  cbz      x0, #0xfcb4c
static inline uint64_t fde_func_2266_0x0fcb24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcb24ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e4318ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2267 | PC: 0x0fcb58 | FDE: 0x1e4338 | Size: 148 bytes
// Khung tháo gỡ #2267 | Địa chỉ PC: 0x0fcb58 | Địa chỉ FDE: 0x1e4338 | Kích thước: 148 bytes
//   0x0fcb58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fcb5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fcb60: 910043FD  add      x29, sp, #0x10
//   0x0fcb64: F0000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2267_0x0fcb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcb58ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4338ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2268 | PC: 0x0fcbec | FDE: 0x1e4358 | Size: 256 bytes
// Khung tháo gỡ #2268 | Địa chỉ PC: 0x0fcbec | Địa chỉ FDE: 0x1e4358 | Kích thước: 256 bytes
//   0x0fcbec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0fcbf0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fcbf4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fcbf8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2268_0x0fcbec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcbecULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2269 | PC: 0x0fcd84 | FDE: 0x1e4380 | Size: 140 bytes
// Khung tháo gỡ #2269 | Địa chỉ PC: 0x0fcd84 | Địa chỉ FDE: 0x1e4380 | Kích thước: 140 bytes
//   0x0fcd84: D100C3FF  sub      sp, sp, #0x30
//   0x0fcd88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fcd8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fcd90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2269_0x0fcd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcd84ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4380ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2270 | PC: 0x0fce10 | FDE: 0x1e43a0 | Size: 256 bytes
// Khung tháo gỡ #2270 | Địa chỉ PC: 0x0fce10 | Địa chỉ FDE: 0x1e43a0 | Kích thước: 256 bytes
//   0x0fce10: D10183FF  sub      sp, sp, #0x60
//   0x0fce14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0fce18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0fce1c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2270_0x0fce10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fce10ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e43a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2271 | PC: 0x0fe040 | FDE: 0x1e43c8 | Size: 176 bytes
// Khung tháo gỡ #2271 | Địa chỉ PC: 0x0fe040 | Địa chỉ FDE: 0x1e43c8 | Kích thước: 176 bytes
//   0x0fe040: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fe044: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fe048: 910043FD  add      x29, sp, #0x10
//   0x0fe04c: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_2271_0x0fe040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe040ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e43c8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #2272 | PC: 0x0fe0f0 | FDE: 0x1e43e8 | Size: 48 bytes
// Khung tháo gỡ #2272 | Địa chỉ PC: 0x0fe0f0 | Địa chỉ FDE: 0x1e43e8 | Kích thước: 48 bytes
//   0x0fe0f0: F9400808  ldr      x8, [x0, #0x10]
//   0x0fe0f4: B000080A  adrp     x10, #0x1ff000
//   0x0fe0f8: AA0003E1  mov      x1, x0
//   0x0fe0fc: 900005C0  adrp     x0, #0x1b6000
static inline uint64_t fde_func_2272_0x0fe0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe0f0ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb000080aULL) ^ 0x1e43e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2273 | PC: 0x0fe120 | FDE: 0x1e4400 | Size: 184 bytes
// Khung tháo gỡ #2273 | Địa chỉ PC: 0x0fe120 | Địa chỉ FDE: 0x1e4400 | Kích thước: 184 bytes
//   0x0fe120: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fe124: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fe128: 910043FD  add      x29, sp, #0x10
//   0x0fe12c: B0000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2273_0x0fe120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe120ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4400ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2274 | PC: 0x0fe1d8 | FDE: 0x1e4420 | Size: 256 bytes
// Khung tháo gỡ #2274 | Địa chỉ PC: 0x0fe1d8 | Địa chỉ FDE: 0x1e4420 | Kích thước: 256 bytes
//   0x0fe1d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fe1dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fe1e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fe1e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2274_0x0fe1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe1d8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2275 | PC: 0x0fe2ec | FDE: 0x1e4440 | Size: 136 bytes
// Khung tháo gỡ #2275 | Địa chỉ PC: 0x0fe2ec | Địa chỉ FDE: 0x1e4440 | Kích thước: 136 bytes
//   0x0fe2ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fe2f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fe2f4: 910043FD  add      x29, sp, #0x10
//   0x0fe2f8: B0000808  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2275_0x0fe2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe2ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4440ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2276 | PC: 0x0fe374 | FDE: 0x1e4460 | Size: 164 bytes
// Khung tháo gỡ #2276 | Địa chỉ PC: 0x0fe374 | Địa chỉ FDE: 0x1e4460 | Kích thước: 164 bytes
//   0x0fe374: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe378: 910003FD  mov      x29, sp
//   0x0fe37c: B000080A  adrp     x10, #0x1ff000
//   0x0fe380: F940040B  ldr      x11, [x0, #8]
static inline uint64_t fde_func_2276_0x0fe374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe374ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e4460ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2277 | PC: 0x0fe418 | FDE: 0x1e4480 | Size: 136 bytes
// Khung tháo gỡ #2277 | Địa chỉ PC: 0x0fe418 | Địa chỉ FDE: 0x1e4480 | Kích thước: 136 bytes
//   0x0fe418: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fe41c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fe420: 910043FD  add      x29, sp, #0x10
//   0x0fe424: B0000808  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2277_0x0fe418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe418ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4480ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2278 | PC: 0x0fe4a0 | FDE: 0x1e44a0 | Size: 188 bytes
// Khung tháo gỡ #2278 | Địa chỉ PC: 0x0fe4a0 | Địa chỉ FDE: 0x1e44a0 | Kích thước: 188 bytes
//   0x0fe4a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fe4a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fe4a8: 910043FD  add      x29, sp, #0x10
//   0x0fe4ac: B0000808  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2278_0x0fe4a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe4a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e44a0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2279 | PC: 0x0fe55c | FDE: 0x1e44c0 | Size: 256 bytes
// Khung tháo gỡ #2279 | Địa chỉ PC: 0x0fe55c | Địa chỉ FDE: 0x1e44c0 | Kích thước: 256 bytes
//   0x0fe55c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0fe560: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fe564: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fe568: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2279_0x0fe55c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe55cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e44c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2280 | PC: 0x0fe6d4 | FDE: 0x1e44e8 | Size: 256 bytes [PyWeakref_NewRef]
// Khung tháo gỡ #2280 | Địa chỉ PC: 0x0fe6d4 | Địa chỉ FDE: 0x1e44e8 | Kích thước: 256 bytes
//   0x0fe6d4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0fe6d8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fe6dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fe6e0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2280_0x0fe6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe6d4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e44e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2281 | PC: 0x0fe8d0 | FDE: 0x1e4510 | Size: 256 bytes [PyWeakref_NewProxy]
// Khung tháo gỡ #2281 | Địa chỉ PC: 0x0fe8d0 | Địa chỉ FDE: 0x1e4510 | Kích thước: 256 bytes
//   0x0fe8d0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0fe8d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0fe8d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fe8dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2281_0x0fe8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe8d0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2282 | PC: 0x0feb0c | FDE: 0x1e4540 | Size: 152 bytes [PyWeakref_GetObject]
// Khung tháo gỡ #2282 | Địa chỉ PC: 0x0feb0c | Địa chỉ FDE: 0x1e4540 | Kích thước: 152 bytes
//   0x0feb0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0feb10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0feb14: 910043FD  add      x29, sp, #0x10
//   0x0feb18: B4000360  cbz      x0, #0xfeb84
static inline uint64_t fde_func_2282_0x0feb0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feb0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4540ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2283 | PC: 0x0feba4 | FDE: 0x1e4560 | Size: 256 bytes [PyObject_ClearWeakRefs]
// Khung tháo gỡ #2283 | Địa chỉ PC: 0x0feba4 | Địa chỉ FDE: 0x1e4560 | Kích thước: 256 bytes
//   0x0feba4: D101C3FF  sub      sp, sp, #0x70
//   0x0feba8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0febac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0febb0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2283_0x0feba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feba4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1e4560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2284 | PC: 0x0feedc | FDE: 0x1e4590 | Size: 224 bytes
// Khung tháo gỡ #2284 | Địa chỉ PC: 0x0feedc | Địa chỉ FDE: 0x1e4590 | Kích thước: 224 bytes
//   0x0feedc: D10143FF  sub      sp, sp, #0x50
//   0x0feee0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0feee4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0feee8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2284_0x0feedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feedcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e4590ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #2285 | PC: 0x0fefbc | FDE: 0x1e45b8 | Size: 256 bytes
// Khung tháo gỡ #2285 | Địa chỉ PC: 0x0fefbc | Địa chỉ FDE: 0x1e45b8 | Kích thước: 256 bytes
//   0x0fefbc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fefc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fefc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fefc8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2285_0x0fefbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fefbcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e45b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2286 | PC: 0x0ff0d0 | FDE: 0x1e45d8 | Size: 256 bytes
// Khung tháo gỡ #2286 | Địa chỉ PC: 0x0ff0d0 | Địa chỉ FDE: 0x1e45d8 | Kích thước: 256 bytes
//   0x0ff0d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ff0d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ff0d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ff0dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2286_0x0ff0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff0d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e45d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2287 | PC: 0x0ff1e4 | FDE: 0x1e45f8 | Size: 256 bytes
// Khung tháo gỡ #2287 | Địa chỉ PC: 0x0ff1e4 | Địa chỉ FDE: 0x1e45f8 | Kích thước: 256 bytes
//   0x0ff1e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ff1e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ff1ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ff1f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2287_0x0ff1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff1e4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e45f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2288 | PC: 0x0ff2f8 | FDE: 0x1e4618 | Size: 256 bytes
// Khung tháo gỡ #2288 | Địa chỉ PC: 0x0ff2f8 | Địa chỉ FDE: 0x1e4618 | Kích thước: 256 bytes
//   0x0ff2f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ff2fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ff300: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ff304: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2288_0x0ff2f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff2f8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2289 | PC: 0x0ff40c | FDE: 0x1e4638 | Size: 256 bytes
// Khung tháo gỡ #2289 | Địa chỉ PC: 0x0ff40c | Địa chỉ FDE: 0x1e4638 | Kích thước: 256 bytes
//   0x0ff40c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ff410: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ff414: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ff418: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2289_0x0ff40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff40cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2290 | PC: 0x0ff520 | FDE: 0x1e4658 | Size: 256 bytes
// Khung tháo gỡ #2290 | Địa chỉ PC: 0x0ff520 | Địa chỉ FDE: 0x1e4658 | Kích thước: 256 bytes
//   0x0ff520: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ff524: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ff528: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ff52c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2290_0x0ff520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff520ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2291 | PC: 0x0ff698 | FDE: 0x1e4680 | Size: 184 bytes
// Khung tháo gỡ #2291 | Địa chỉ PC: 0x0ff698 | Địa chỉ FDE: 0x1e4680 | Kích thước: 184 bytes
//   0x0ff698: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ff69c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff6a0: 910043FD  add      x29, sp, #0x10
//   0x0ff6a4: 90000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2291_0x0ff698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff698ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4680ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2292 | PC: 0x0ff750 | FDE: 0x1e46a0 | Size: 184 bytes
// Khung tháo gỡ #2292 | Địa chỉ PC: 0x0ff750 | Địa chỉ FDE: 0x1e46a0 | Kích thước: 184 bytes
//   0x0ff750: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ff754: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff758: 910043FD  add      x29, sp, #0x10
//   0x0ff75c: 90000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2292_0x0ff750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff750ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e46a0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2293 | PC: 0x0ff808 | FDE: 0x1e46c0 | Size: 184 bytes
// Khung tháo gỡ #2293 | Địa chỉ PC: 0x0ff808 | Địa chỉ FDE: 0x1e46c0 | Kích thước: 184 bytes
//   0x0ff808: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ff80c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff810: 910043FD  add      x29, sp, #0x10
//   0x0ff814: 90000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2293_0x0ff808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff808ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e46c0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2294 | PC: 0x0ff8c0 | FDE: 0x1e46e0 | Size: 136 bytes
// Khung tháo gỡ #2294 | Địa chỉ PC: 0x0ff8c0 | Địa chỉ FDE: 0x1e46e0 | Kích thước: 136 bytes
//   0x0ff8c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ff8c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff8c8: 910043FD  add      x29, sp, #0x10
//   0x0ff8cc: 90000808  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2294_0x0ff8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff8c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e46e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2295 | PC: 0x0ff948 | FDE: 0x1e4700 | Size: 184 bytes
// Khung tháo gỡ #2295 | Địa chỉ PC: 0x0ff948 | Địa chỉ FDE: 0x1e4700 | Kích thước: 184 bytes
//   0x0ff948: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ff94c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff950: 910043FD  add      x29, sp, #0x10
//   0x0ff954: 90000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2295_0x0ff948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff948ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4700ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2296 | PC: 0x0ffa00 | FDE: 0x1e4720 | Size: 256 bytes
// Khung tháo gỡ #2296 | Địa chỉ PC: 0x0ffa00 | Địa chỉ FDE: 0x1e4720 | Kích thước: 256 bytes
//   0x0ffa00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ffa04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ffa08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ffa0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2296_0x0ffa00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffa00ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2297 | PC: 0x0ffb14 | FDE: 0x1e4740 | Size: 256 bytes
// Khung tháo gỡ #2297 | Địa chỉ PC: 0x0ffb14 | Địa chỉ FDE: 0x1e4740 | Kích thước: 256 bytes
//   0x0ffb14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ffb18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ffb1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ffb20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2297_0x0ffb14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffb14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2298 | PC: 0x0ffc28 | FDE: 0x1e4760 | Size: 256 bytes
// Khung tháo gỡ #2298 | Địa chỉ PC: 0x0ffc28 | Địa chỉ FDE: 0x1e4760 | Kích thước: 256 bytes
//   0x0ffc28: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ffc2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ffc30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ffc34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2298_0x0ffc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffc28ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2299 | PC: 0x0ffd3c | FDE: 0x1e4780 | Size: 256 bytes
// Khung tháo gỡ #2299 | Địa chỉ PC: 0x0ffd3c | Địa chỉ FDE: 0x1e4780 | Kích thước: 256 bytes
//   0x0ffd3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ffd40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ffd44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ffd48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2299_0x0ffd3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffd3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2300 | PC: 0x0ffe50 | FDE: 0x1e47a0 | Size: 256 bytes
// Khung tháo gỡ #2300 | Địa chỉ PC: 0x0ffe50 | Địa chỉ FDE: 0x1e47a0 | Kích thước: 256 bytes
//   0x0ffe50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ffe54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ffe58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ffe5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2300_0x0ffe50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffe50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e47a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2301 | PC: 0x0fff64 | FDE: 0x1e47c0 | Size: 184 bytes
// Khung tháo gỡ #2301 | Địa chỉ PC: 0x0fff64 | Địa chỉ FDE: 0x1e47c0 | Kích thước: 184 bytes
//   0x0fff64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fff68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fff6c: 910043FD  add      x29, sp, #0x10
//   0x0fff70: 90000809  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2301_0x0fff64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fff64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e47c0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2302 | PC: 0x10001c | FDE: 0x1e47e0 | Size: 184 bytes
// Khung tháo gỡ #2302 | Địa chỉ PC: 0x10001c | Địa chỉ FDE: 0x1e47e0 | Kích thước: 184 bytes
//   0x10001c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x100020: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x100024: 910043FD  add      x29, sp, #0x10
//   0x100028: F00007E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2302_0x10001c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10001cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e47e0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2303 | PC: 0x1000d4 | FDE: 0x1e4800 | Size: 256 bytes
// Khung tháo gỡ #2303 | Địa chỉ PC: 0x1000d4 | Địa chỉ FDE: 0x1e4800 | Kích thước: 256 bytes
//   0x1000d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1000d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1000dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1000e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2303_0x1000d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1000d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2304 | PC: 0x1001e8 | FDE: 0x1e4820 | Size: 256 bytes
// Khung tháo gỡ #2304 | Địa chỉ PC: 0x1001e8 | Địa chỉ FDE: 0x1e4820 | Kích thước: 256 bytes
//   0x1001e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1001ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1001f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1001f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2304_0x1001e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1001e8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2305 | PC: 0x1002fc | FDE: 0x1e4840 | Size: 256 bytes
// Khung tháo gỡ #2305 | Địa chỉ PC: 0x1002fc | Địa chỉ FDE: 0x1e4840 | Kích thước: 256 bytes
//   0x1002fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100300: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100304: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100308: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2305_0x1002fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1002fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2306 | PC: 0x100410 | FDE: 0x1e4860 | Size: 256 bytes
// Khung tháo gỡ #2306 | Địa chỉ PC: 0x100410 | Địa chỉ FDE: 0x1e4860 | Kích thước: 256 bytes
//   0x100410: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100414: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100418: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10041c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2306_0x100410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100410ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2307 | PC: 0x100524 | FDE: 0x1e4880 | Size: 256 bytes
// Khung tháo gỡ #2307 | Địa chỉ PC: 0x100524 | Địa chỉ FDE: 0x1e4880 | Kích thước: 256 bytes
//   0x100524: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x100528: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10052c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100530: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2307_0x100524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100524ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2308 | PC: 0x10069c | FDE: 0x1e48a8 | Size: 256 bytes
// Khung tháo gỡ #2308 | Địa chỉ PC: 0x10069c | Địa chỉ FDE: 0x1e48a8 | Kích thước: 256 bytes
//   0x10069c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1006a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1006a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1006a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2308_0x10069c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10069cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e48a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2309 | PC: 0x1007b0 | FDE: 0x1e48c8 | Size: 256 bytes
// Khung tháo gỡ #2309 | Địa chỉ PC: 0x1007b0 | Địa chỉ FDE: 0x1e48c8 | Kích thước: 256 bytes
//   0x1007b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1007b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1007b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1007bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2309_0x1007b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1007b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e48c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2310 | PC: 0x1008c4 | FDE: 0x1e48e8 | Size: 256 bytes
// Khung tháo gỡ #2310 | Địa chỉ PC: 0x1008c4 | Địa chỉ FDE: 0x1e48e8 | Kích thước: 256 bytes
//   0x1008c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1008c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1008cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1008d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2310_0x1008c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1008c4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e48e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2311 | PC: 0x1009d8 | FDE: 0x1e4908 | Size: 256 bytes
// Khung tháo gỡ #2311 | Địa chỉ PC: 0x1009d8 | Địa chỉ FDE: 0x1e4908 | Kích thước: 256 bytes
//   0x1009d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1009dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1009e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1009e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2311_0x1009d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1009d8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2312 | PC: 0x100aec | FDE: 0x1e4928 | Size: 256 bytes
// Khung tháo gỡ #2312 | Địa chỉ PC: 0x100aec | Địa chỉ FDE: 0x1e4928 | Kích thước: 256 bytes
//   0x100aec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100af0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100af4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100af8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2312_0x100aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100aecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2313 | PC: 0x100c00 | FDE: 0x1e4948 | Size: 256 bytes
// Khung tháo gỡ #2313 | Địa chỉ PC: 0x100c00 | Địa chỉ FDE: 0x1e4948 | Kích thước: 256 bytes
//   0x100c00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100c04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100c08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100c0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2313_0x100c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100c00ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2314 | PC: 0x100d14 | FDE: 0x1e4968 | Size: 256 bytes
// Khung tháo gỡ #2314 | Địa chỉ PC: 0x100d14 | Địa chỉ FDE: 0x1e4968 | Kích thước: 256 bytes
//   0x100d14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100d18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100d1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100d20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2314_0x100d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100d14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2315 | PC: 0x100e28 | FDE: 0x1e4988 | Size: 256 bytes
// Khung tháo gỡ #2315 | Địa chỉ PC: 0x100e28 | Địa chỉ FDE: 0x1e4988 | Kích thước: 256 bytes
//   0x100e28: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100e2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100e30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100e34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2315_0x100e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100e28ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2316 | PC: 0x100f3c | FDE: 0x1e49a8 | Size: 256 bytes
// Khung tháo gỡ #2316 | Địa chỉ PC: 0x100f3c | Địa chỉ FDE: 0x1e49a8 | Kích thước: 256 bytes
//   0x100f3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x100f40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x100f44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x100f48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2316_0x100f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100f3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e49a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2317 | PC: 0x101050 | FDE: 0x1e49c8 | Size: 184 bytes
// Khung tháo gỡ #2317 | Địa chỉ PC: 0x101050 | Địa chỉ FDE: 0x1e49c8 | Kích thước: 184 bytes
//   0x101050: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x101054: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x101058: 910043FD  add      x29, sp, #0x10
//   0x10105c: D00007E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2317_0x101050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101050ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e49c8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2318 | PC: 0x101108 | FDE: 0x1e49e8 | Size: 256 bytes
// Khung tháo gỡ #2318 | Địa chỉ PC: 0x101108 | Địa chỉ FDE: 0x1e49e8 | Kích thước: 256 bytes
//   0x101108: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10110c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x101110: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x101114: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2318_0x101108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101108ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e49e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2319 | PC: 0x10121c | FDE: 0x1e4a08 | Size: 256 bytes
// Khung tháo gỡ #2319 | Địa chỉ PC: 0x10121c | Địa chỉ FDE: 0x1e4a08 | Kích thước: 256 bytes
//   0x10121c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x101220: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x101224: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x101228: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2319_0x10121c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10121cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2320 | PC: 0x101330 | FDE: 0x1e4a28 | Size: 136 bytes
// Khung tháo gỡ #2320 | Địa chỉ PC: 0x101330 | Địa chỉ FDE: 0x1e4a28 | Kích thước: 136 bytes
//   0x101330: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x101334: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x101338: 910043FD  add      x29, sp, #0x10
//   0x10133c: D00007E8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2320_0x101330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101330ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4a28ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2321 | PC: 0x1013b8 | FDE: 0x1e4a48 | Size: 136 bytes
// Khung tháo gỡ #2321 | Địa chỉ PC: 0x1013b8 | Địa chỉ FDE: 0x1e4a48 | Kích thước: 136 bytes
//   0x1013b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1013bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1013c0: 910043FD  add      x29, sp, #0x10
//   0x1013c4: D00007E8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2321_0x1013b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1013b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4a48ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2322 | PC: 0x101440 | FDE: 0x1e4a68 | Size: 256 bytes
// Khung tháo gỡ #2322 | Địa chỉ PC: 0x101440 | Địa chỉ FDE: 0x1e4a68 | Kích thước: 256 bytes
//   0x101440: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x101444: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x101448: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10144c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2322_0x101440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101440ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2323 | PC: 0x101554 | FDE: 0x1e4a88 | Size: 148 bytes
// Khung tháo gỡ #2323 | Địa chỉ PC: 0x101554 | Địa chỉ FDE: 0x1e4a88 | Kích thước: 148 bytes
//   0x101554: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x101558: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10155c: 910043FD  add      x29, sp, #0x10
//   0x101560: D00007E8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2323_0x101554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101554ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4a88ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2324 | PC: 0x1015e8 | FDE: 0x1e4aa8 | Size: 256 bytes
// Khung tháo gỡ #2324 | Địa chỉ PC: 0x1015e8 | Địa chỉ FDE: 0x1e4aa8 | Kích thước: 256 bytes
//   0x1015e8: D10103FF  sub      sp, sp, #0x40
//   0x1015ec: F9000BF5  str      x21, [sp, #0x10]
//   0x1015f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1015f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2324_0x1015e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1015e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e4aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2325 | PC: 0x1016f4 | FDE: 0x1e4ac8 | Size: 256 bytes
// Khung tháo gỡ #2325 | Địa chỉ PC: 0x1016f4 | Địa chỉ FDE: 0x1e4ac8 | Kích thước: 256 bytes
//   0x1016f4: D10103FF  sub      sp, sp, #0x40
//   0x1016f8: F9000BF5  str      x21, [sp, #0x10]
//   0x1016fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x101700: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2325_0x1016f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1016f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e4ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2326 | PC: 0x101800 | FDE: 0x1e4ae8 | Size: 256 bytes [_PyWarnings_InitState]
// Khung tháo gỡ #2326 | Địa chỉ PC: 0x101800 | Địa chỉ FDE: 0x1e4ae8 | Kích thước: 256 bytes
//   0x101800: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x101804: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x101808: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10180c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2326_0x101800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101800ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2327 | PC: 0x101b88 | FDE: 0x1e4b10 | Size: 256 bytes [PyErr_WarnFormat]
// Khung tháo gỡ #2327 | Địa chỉ PC: 0x101b88 | Địa chỉ FDE: 0x1e4b10 | Kích thước: 256 bytes
//   0x101b88: D10503FF  sub      sp, sp, #0x140
//   0x101b8c: F90083FC  str      x28, [sp, #0x100]
//   0x101b90: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x101b94: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_2327_0x101b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101b88ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1e4b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2328 | PC: 0x101ca4 | FDE: 0x1e4b38 | Size: 256 bytes [PyErr_ResourceWarning]
// Khung tháo gỡ #2328 | Địa chỉ PC: 0x101ca4 | Địa chỉ FDE: 0x1e4b38 | Kích thước: 256 bytes
//   0x101ca4: D10503FF  sub      sp, sp, #0x140
//   0x101ca8: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x101cac: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x101cb0: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_2328_0x101ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101ca4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1e4b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2329 | PC: 0x101dcc | FDE: 0x1e4b60 | Size: 160 bytes [PyErr_WarnEx]
// Khung tháo gỡ #2329 | Địa chỉ PC: 0x101dcc | Địa chỉ FDE: 0x1e4b60 | Kích thước: 160 bytes
//   0x101dcc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x101dd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x101dd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x101dd8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2329_0x101dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101dccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4b60ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2330 | PC: 0x101e6c | FDE: 0x1e4b80 | Size: 148 bytes [PyErr_Warn]
// Khung tháo gỡ #2330 | Địa chỉ PC: 0x101e6c | Địa chỉ FDE: 0x1e4b80 | Kích thước: 148 bytes
//   0x101e6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x101e70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x101e74: 910043FD  add      x29, sp, #0x10
//   0x101e78: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2330_0x101e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101e6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4b80ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2331 | PC: 0x101f00 | FDE: 0x1e4ba0 | Size: 88 bytes [PyErr_WarnExplicitObject]
// Khung tháo gỡ #2331 | Địa chỉ PC: 0x101f00 | Địa chỉ FDE: 0x1e4ba0 | Kích thước: 88 bytes
//   0x101f00: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x101f04: 910003FD  mov      x29, sp
//   0x101f08: D00007E8  adrp     x8, #0x1ff000
//   0x101f0c: F9472908  ldr      x8, [x8, #0xe50]
static inline uint64_t fde_func_2331_0x101f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101f00ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e4ba0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2332 | PC: 0x101f58 | FDE: 0x1e4bc0 | Size: 256 bytes
// Khung tháo gỡ #2332 | Địa chỉ PC: 0x101f58 | Địa chỉ FDE: 0x1e4bc0 | Kích thước: 256 bytes
//   0x101f58: D105C3FF  sub      sp, sp, #0x170
//   0x101f5c: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x101f60: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x101f64: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_2332_0x101f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101f58ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x1e4bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2333 | PC: 0x102d10 | FDE: 0x1e4bf0 | Size: 256 bytes [PyErr_WarnExplicit]
// Khung tháo gỡ #2333 | Địa chỉ PC: 0x102d10 | Địa chỉ FDE: 0x1e4bf0 | Kích thước: 256 bytes
//   0x102d10: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x102d14: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x102d18: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x102d1c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2333_0x102d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102d10ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2334 | PC: 0x102e5c | FDE: 0x1e4c20 | Size: 256 bytes [PyErr_WarnExplicitFormat]
// Khung tháo gỡ #2334 | Địa chỉ PC: 0x102e5c | Địa chỉ FDE: 0x1e4c20 | Kích thước: 256 bytes
//   0x102e5c: D104C3FF  sub      sp, sp, #0x130
//   0x102e60: A90E67FC  stp      x28, x25, [sp, #0xe0]
//   0x102e64: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x102e68: A91057F6  stp      x22, x21, [sp, #0x100]
static inline uint64_t fde_func_2334_0x102e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102e5cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90e67fcULL) ^ 0x1e4c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2335 | PC: 0x102ffc | FDE: 0x1e4c50 | Size: 256 bytes [_PyErr_WarnUnawaitedCoroutine]
// Khung tháo gỡ #2335 | Địa chỉ PC: 0x102ffc | Địa chỉ FDE: 0x1e4c50 | Kích thước: 256 bytes
//   0x102ffc: D10183FF  sub      sp, sp, #0x60
//   0x103000: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x103004: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x103008: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2335_0x102ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102ffcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e4c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2336 | PC: 0x10316c | FDE: 0x1e4c78 | Size: 252 bytes
// Khung tháo gỡ #2336 | Địa chỉ PC: 0x10316c | Địa chỉ FDE: 0x1e4c78 | Kích thước: 252 bytes
//   0x10316c: D10103FF  sub      sp, sp, #0x40
//   0x103170: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x103174: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x103178: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2336_0x10316c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10316cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4c78ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #2337 | PC: 0x103268 | FDE: 0x1e4ca0 | Size: 256 bytes
// Khung tháo gỡ #2337 | Địa chỉ PC: 0x103268 | Địa chỉ FDE: 0x1e4ca0 | Kích thước: 256 bytes
//   0x103268: D104C3FF  sub      sp, sp, #0x130
//   0x10326c: F9007BFC  str      x28, [sp, #0xf0]
//   0x103270: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x103274: A9114FF4  stp      x20, x19, [sp, #0x110]
static inline uint64_t fde_func_2337_0x103268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103268ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x1e4ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2338 | PC: 0x103384 | FDE: 0x1e4cc8 | Size: 12 bytes [_PyWarnings_Init]
// Khung tháo gỡ #2338 | Địa chỉ PC: 0x103384 | Địa chỉ FDE: 0x1e4cc8 | Kích thước: 12 bytes
//   0x103384: F0000880  adrp     x0, #0x216000
//   0x103388: 910BE000  add      x0, x0, #0x2f8
//   0x10338c: 17FD55A5  b        #0x58a20
static inline uint64_t fde_func_2338_0x103384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103384ULL ^ (static_cast<uint64_t>(0xf0000880ULL) << 13);
    acc = (acc + a1 + 0x910be000ULL) ^ 0x1e4cc8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2339 | PC: 0x103390 | FDE: 0x1e4ce0 | Size: 152 bytes [_PyWarnings_Fini]
// Khung tháo gỡ #2339 | Địa chỉ PC: 0x103390 | Địa chỉ FDE: 0x1e4ce0 | Kích thước: 152 bytes
//   0x103390: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x103394: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x103398: 910043FD  add      x29, sp, #0x10
//   0x10339c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2339_0x103390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103390ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4ce0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2340 | PC: 0x103428 | FDE: 0x1e4d00 | Size: 256 bytes
// Khung tháo gỡ #2340 | Địa chỉ PC: 0x103428 | Địa chỉ FDE: 0x1e4d00 | Kích thước: 256 bytes
//   0x103428: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x10342c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x103430: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x103434: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2340_0x103428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103428ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2341 | PC: 0x103738 | FDE: 0x1e4d30 | Size: 244 bytes
// Khung tháo gỡ #2341 | Địa chỉ PC: 0x103738 | Địa chỉ FDE: 0x1e4d30 | Kích thước: 244 bytes
//   0x103738: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x10373c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x103740: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x103744: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2341_0x103738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103738ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4d30ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2342 | PC: 0x10382c | FDE: 0x1e4d58 | Size: 256 bytes
// Khung tháo gỡ #2342 | Địa chỉ PC: 0x10382c | Địa chỉ FDE: 0x1e4d58 | Kích thước: 256 bytes
//   0x10382c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x103830: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x103834: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x103838: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2342_0x10382c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10382cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4d58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2343 | PC: 0x10397c | FDE: 0x1e4d80 | Size: 244 bytes
// Khung tháo gỡ #2343 | Địa chỉ PC: 0x10397c | Địa chỉ FDE: 0x1e4d80 | Kích thước: 244 bytes
//   0x10397c: D10143FF  sub      sp, sp, #0x50
//   0x103980: F90013F5  str      x21, [sp, #0x20]
//   0x103984: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x103988: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2343_0x10397c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10397cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e4d80ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2344 | PC: 0x103a70 | FDE: 0x1e4da0 | Size: 256 bytes
// Khung tháo gỡ #2344 | Địa chỉ PC: 0x103a70 | Địa chỉ FDE: 0x1e4da0 | Kích thước: 256 bytes
//   0x103a70: D10203FF  sub      sp, sp, #0x80
//   0x103a74: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x103a78: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x103a7c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_2344_0x103a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103a70ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x1e4da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2345 | PC: 0x103c9c | FDE: 0x1e4dd0 | Size: 256 bytes
// Khung tháo gỡ #2345 | Địa chỉ PC: 0x103c9c | Địa chỉ FDE: 0x1e4dd0 | Kích thước: 256 bytes
//   0x103c9c: D10343FF  sub      sp, sp, #0xd0
//   0x103ca0: F90043F9  str      x25, [sp, #0x80]
//   0x103ca4: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x103ca8: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_2345_0x103c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103c9cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90043f9ULL) ^ 0x1e4dd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2346 | PC: 0x103fd0 | FDE: 0x1e4df8 | Size: 108 bytes
// Khung tháo gỡ #2346 | Địa chỉ PC: 0x103fd0 | Địa chỉ FDE: 0x1e4df8 | Kích thước: 108 bytes
//   0x103fd0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x103fd4: 910003FD  mov      x29, sp
//   0x103fd8: 900007E8  adrp     x8, #0x1ff000
//   0x103fdc: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2346_0x103fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103fd0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e4df8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #2347 | PC: 0x10403c | FDE: 0x1e4e18 | Size: 160 bytes
// Khung tháo gỡ #2347 | Địa chỉ PC: 0x10403c | Địa chỉ FDE: 0x1e4e18 | Kích thước: 160 bytes
//   0x10403c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x104040: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x104044: 910043FD  add      x29, sp, #0x10
//   0x104048: F00007C8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2347_0x10403c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10403cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4e18ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2348 | PC: 0x1040dc | FDE: 0x1e4e38 | Size: 152 bytes [_Py_asdl_generic_seq_new]
// Khung tháo gỡ #2348 | Địa chỉ PC: 0x1040dc | Địa chỉ FDE: 0x1e4e38 | Kích thước: 152 bytes
//   0x1040dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1040e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1040e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1040e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2348_0x1040dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1040dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4e38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2349 | PC: 0x104174 | FDE: 0x1e4e58 | Size: 152 bytes [_Py_asdl_identifier_seq_new]
// Khung tháo gỡ #2349 | Địa chỉ PC: 0x104174 | Địa chỉ FDE: 0x1e4e58 | Kích thước: 152 bytes
//   0x104174: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104178: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10417c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104180: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2349_0x104174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104174ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4e58ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2350 | PC: 0x10420c | FDE: 0x1e4e78 | Size: 152 bytes [_Py_asdl_int_seq_new]
// Khung tháo gỡ #2350 | Địa chỉ PC: 0x10420c | Địa chỉ FDE: 0x1e4e78 | Kích thước: 152 bytes
//   0x10420c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104210: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104214: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104218: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2350_0x10420c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10420cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4e78ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2351 | PC: 0x1042a4 | FDE: 0x1e4e98 | Size: 184 bytes [BDPythonVMDispatchCreateSubInterpreters]
// Khung tháo gỡ #2351 | Địa chỉ PC: 0x1042a4 | Địa chỉ FDE: 0x1e4e98 | Kích thước: 184 bytes
//   0x1042a4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1042a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1042ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1042b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2351_0x1042a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1042a4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4e98ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2352 | PC: 0x10435c | FDE: 0x1e4ec0 | Size: 212 bytes [BDPythonVMDispatchGetInterperter]
// Khung tháo gỡ #2352 | Địa chỉ PC: 0x10435c | Địa chỉ FDE: 0x1e4ec0 | Kích thước: 212 bytes
//   0x10435c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104360: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104364: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104368: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2352_0x10435c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10435cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4ec0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #2353 | PC: 0x104430 | FDE: 0x1e4ee0 | Size: 112 bytes
// Khung tháo gỡ #2353 | Địa chỉ PC: 0x104430 | Địa chỉ FDE: 0x1e4ee0 | Kích thước: 112 bytes
//   0x104430: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x104434: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x104438: 910043FD  add      x29, sp, #0x10
//   0x10443c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2353_0x104430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104430ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4ee0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2354 | PC: 0x1044a0 | FDE: 0x1e4f00 | Size: 88 bytes
// Khung tháo gỡ #2354 | Địa chỉ PC: 0x1044a0 | Địa chỉ FDE: 0x1e4f00 | Kích thước: 88 bytes
//   0x1044a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1044a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1044a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1044ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2354_0x1044a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1044a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4f00ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2355 | PC: 0x1044f8 | FDE: 0x1e4f20 | Size: 256 bytes
// Khung tháo gỡ #2355 | Địa chỉ PC: 0x1044f8 | Địa chỉ FDE: 0x1e4f20 | Kích thước: 256 bytes
//   0x1044f8: D10203FF  sub      sp, sp, #0x80
//   0x1044fc: F90013FB  str      x27, [sp, #0x20]
//   0x104500: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x104504: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2355_0x1044f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1044f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e4f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2356 | PC: 0x1046ac | FDE: 0x1e4f50 | Size: 244 bytes
// Khung tháo gỡ #2356 | Địa chỉ PC: 0x1046ac | Địa chỉ FDE: 0x1e4f50 | Kích thước: 244 bytes
//   0x1046ac: D10143FF  sub      sp, sp, #0x50
//   0x1046b0: F90013F5  str      x21, [sp, #0x20]
//   0x1046b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1046b8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2356_0x1046ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1046acULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e4f50ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2357 | PC: 0x1047a0 | FDE: 0x1e4f70 | Size: 208 bytes
// Khung tháo gỡ #2357 | Địa chỉ PC: 0x1047a0 | Địa chỉ FDE: 0x1e4f70 | Kích thước: 208 bytes
//   0x1047a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1047a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1047a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1047ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2357_0x1047a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1047a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4f70ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2358 | PC: 0x104870 | FDE: 0x1e4f90 | Size: 112 bytes
// Khung tháo gỡ #2358 | Địa chỉ PC: 0x104870 | Địa chỉ FDE: 0x1e4f90 | Kích thước: 112 bytes
//   0x104870: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x104874: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x104878: 910043FD  add      x29, sp, #0x10
//   0x10487c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2358_0x104870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104870ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4f90ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2359 | PC: 0x1048e0 | FDE: 0x1e4fb0 | Size: 88 bytes
// Khung tháo gỡ #2359 | Địa chỉ PC: 0x1048e0 | Địa chỉ FDE: 0x1e4fb0 | Kích thước: 88 bytes
//   0x1048e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1048e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1048e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1048ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2359_0x1048e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1048e0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4fb0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2360 | PC: 0x104938 | FDE: 0x1e4fd0 | Size: 256 bytes
// Khung tháo gỡ #2360 | Địa chỉ PC: 0x104938 | Địa chỉ FDE: 0x1e4fd0 | Kích thước: 256 bytes
//   0x104938: D101C3FF  sub      sp, sp, #0x70
//   0x10493c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x104940: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x104944: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2360_0x104938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104938ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1e4fd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2361 | PC: 0x104ad0 | FDE: 0x1e4ff8 | Size: 256 bytes
// Khung tháo gỡ #2361 | Địa chỉ PC: 0x104ad0 | Địa chỉ FDE: 0x1e4ff8 | Kích thước: 256 bytes
//   0x104ad0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x104ad4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x104ad8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x104adc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2361_0x104ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104ad0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2362 | PC: 0x104bd8 | FDE: 0x1e5020 | Size: 256 bytes
// Khung tháo gỡ #2362 | Địa chỉ PC: 0x104bd8 | Địa chỉ FDE: 0x1e5020 | Kích thước: 256 bytes
//   0x104bd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x104bdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x104be0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x104be4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2362_0x104bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104bd8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2363 | PC: 0x104ce4 | FDE: 0x1e5048 | Size: 112 bytes
// Khung tháo gỡ #2363 | Địa chỉ PC: 0x104ce4 | Địa chỉ FDE: 0x1e5048 | Kích thước: 112 bytes
//   0x104ce4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x104ce8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x104cec: 910043FD  add      x29, sp, #0x10
//   0x104cf0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2363_0x104ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104ce4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5048ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2364 | PC: 0x104d54 | FDE: 0x1e5068 | Size: 88 bytes
// Khung tháo gỡ #2364 | Địa chỉ PC: 0x104d54 | Địa chỉ FDE: 0x1e5068 | Kích thước: 88 bytes
//   0x104d54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104d58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104d5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104d60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2364_0x104d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104d54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5068ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2365 | PC: 0x104dac | FDE: 0x1e5088 | Size: 256 bytes
// Khung tháo gỡ #2365 | Địa chỉ PC: 0x104dac | Địa chỉ FDE: 0x1e5088 | Kích thước: 256 bytes
//   0x104dac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x104db0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x104db4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x104db8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2365_0x104dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104dacULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2366 | PC: 0x10500c | FDE: 0x1e50b0 | Size: 256 bytes
// Khung tháo gỡ #2366 | Địa chỉ PC: 0x10500c | Địa chỉ FDE: 0x1e50b0 | Kích thước: 256 bytes
//   0x10500c: D10143FF  sub      sp, sp, #0x50
//   0x105010: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x105014: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x105018: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2366_0x10500c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10500cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e50b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2367 | PC: 0x1051f8 | FDE: 0x1e50d8 | Size: 16 bytes [BDPythonVM_get_cprofile_dump_path]
// Khung tháo gỡ #2367 | Địa chỉ PC: 0x1051f8 | Địa chỉ FDE: 0x1e50d8 | Kích thước: 16 bytes
//   0x1051f8: D00007C8  adrp     x8, #0x1ff000
//   0x1051fc: F947F908  ldr      x8, [x8, #0xff0]
//   0x105200: F9400100  ldr      x0, [x8]
//   0x105204: 17FD5CAF  b        #0x5c4c0
static inline uint64_t fde_func_2367_0x1051f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1051f8ULL ^ (static_cast<uint64_t>(0xd00007c8ULL) << 13);
    acc = (acc + a1 + 0xf947f908ULL) ^ 0x1e50d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2368 | PC: 0x105208 | FDE: 0x1e50f0 | Size: 228 bytes [BDPythonVM_dump_stats_to_default_path]
// Khung tháo gỡ #2368 | Địa chỉ PC: 0x105208 | Địa chỉ FDE: 0x1e50f0 | Kích thước: 228 bytes
//   0x105208: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10520c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x105210: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105214: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2368_0x105208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105208ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e50f0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #2369 | PC: 0x1052ec | FDE: 0x1e5110 | Size: 24 bytes [bd_empty_func]
// Khung tháo gỡ #2369 | Địa chỉ PC: 0x1052ec | Địa chỉ FDE: 0x1e5110 | Kích thước: 24 bytes
//   0x1052ec: D00007C0  adrp     x0, #0x1ff000
//   0x1052f0: F945F000  ldr      x0, [x0, #0xbe0]
//   0x1052f4: F9400008  ldr      x8, [x0]
//   0x1052f8: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_2369_0x1052ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1052ecULL ^ (static_cast<uint64_t>(0xd00007c0ULL) << 13);
    acc = (acc + a1 + 0xf945f000ULL) ^ 0x1e5110ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2370 | PC: 0x105304 | FDE: 0x1e5128 | Size: 256 bytes [_PyBuiltin_Init]
// Khung tháo gỡ #2370 | Địa chỉ PC: 0x105304 | Địa chỉ FDE: 0x1e5128 | Kích thước: 256 bytes
//   0x105304: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x105308: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10530c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105310: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2370_0x105304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105304ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2371 | PC: 0x105730 | FDE: 0x1e5148 | Size: 20 bytes
// Khung tháo gỡ #2371 | Địa chỉ PC: 0x105730 | Địa chỉ FDE: 0x1e5148 | Kích thước: 20 bytes
//   0x105730: A9408801  ldp      x1, x2, [x0, #8]
//   0x105734: F9400C03  ldr      x3, [x0, #0x18]
//   0x105738: 90000500  adrp     x0, #0x1a5000
//   0x10573c: 91192000  add      x0, x0, #0x648
static inline uint64_t fde_func_2371_0x105730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105730ULL ^ (static_cast<uint64_t>(0xa9408801ULL) << 13);
    acc = (acc + a1 + 0xf9400c03ULL) ^ 0x1e5148ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2372 | PC: 0x105744 | FDE: 0x1e5160 | Size: 156 bytes
// Khung tháo gỡ #2372 | Địa chỉ PC: 0x105744 | Địa chỉ FDE: 0x1e5160 | Kích thước: 156 bytes
//   0x105744: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x105748: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10574c: 910043FD  add      x29, sp, #0x10
//   0x105750: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_2372_0x105744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105744ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5160ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2373 | PC: 0x1057e0 | FDE: 0x1e5180 | Size: 40 bytes
// Khung tháo gỡ #2373 | Địa chỉ PC: 0x1057e0 | Địa chỉ FDE: 0x1e5180 | Kích thước: 40 bytes
//   0x1057e0: B9402808  ldr      w8, [x0, #0x28]
//   0x1057e4: F9400401  ldr      x1, [x0, #8]
//   0x1057e8: F9400C02  ldr      x2, [x0, #0x18]
//   0x1057ec: 340000A8  cbz      w8, #0x105800
static inline uint64_t fde_func_2373_0x1057e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1057e0ULL ^ (static_cast<uint64_t>(0xb9402808ULL) << 13);
    acc = (acc + a1 + 0xf9400401ULL) ^ 0x1e5180ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2374 | PC: 0x105808 | FDE: 0x1e5198 | Size: 72 bytes
// Khung tháo gỡ #2374 | Địa chỉ PC: 0x105808 | Địa chỉ FDE: 0x1e5198 | Kích thước: 72 bytes
//   0x105808: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10580c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x105810: 910043FD  add      x29, sp, #0x10
//   0x105814: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2374_0x105808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105808ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5198ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2375 | PC: 0x105850 | FDE: 0x1e51b8 | Size: 256 bytes
// Khung tháo gỡ #2375 | Địa chỉ PC: 0x105850 | Địa chỉ FDE: 0x1e51b8 | Kích thước: 256 bytes
//   0x105850: D102C3FF  sub      sp, sp, #0xb0
//   0x105854: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x105858: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x10585c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_2375_0x105850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105850ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x1e51b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2376 | PC: 0x105f30 | FDE: 0x1e51e8 | Size: 164 bytes
// Khung tháo gỡ #2376 | Địa chỉ PC: 0x105f30 | Địa chỉ FDE: 0x1e51e8 | Kích thước: 164 bytes
//   0x105f30: D10183FF  sub      sp, sp, #0x60
//   0x105f34: F90023F3  str      x19, [sp, #0x40]
//   0x105f38: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x105f3c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_2376_0x105f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105f30ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x1e51e8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2377 | PC: 0x105fd4 | FDE: 0x1e5208 | Size: 8 bytes
// Khung tháo gỡ #2377 | Địa chỉ PC: 0x105fd4 | Địa chỉ FDE: 0x1e5208 | Kích thước: 8 bytes
//   0x105fd4: AA0103E0  mov      x0, x1
//   0x105fd8: 17FD4D6E  b        #0x59590
static inline uint64_t fde_func_2377_0x105fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105fd4ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd4d6eULL) ^ 0x1e5208ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2378 | PC: 0x105fdc | FDE: 0x1e5220 | Size: 256 bytes
// Khung tháo gỡ #2378 | Địa chỉ PC: 0x105fdc | Địa chỉ FDE: 0x1e5220 | Kích thước: 256 bytes
//   0x105fdc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x105fe0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x105fe4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105fe8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2378_0x105fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105fdcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2379 | PC: 0x1060ec | FDE: 0x1e5248 | Size: 256 bytes
// Khung tháo gỡ #2379 | Địa chỉ PC: 0x1060ec | Địa chỉ FDE: 0x1e5248 | Kích thước: 256 bytes
//   0x1060ec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1060f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1060f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1060f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2379_0x1060ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1060ecULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2380 | PC: 0x1061fc | FDE: 0x1e5270 | Size: 8 bytes
// Khung tháo gỡ #2380 | Địa chỉ PC: 0x1061fc | Địa chỉ FDE: 0x1e5270 | Kích thước: 8 bytes
//   0x1061fc: AA0103E0  mov      x0, x1
//   0x106200: 17FD5388  b        #0x5b020
static inline uint64_t fde_func_2380_0x1061fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1061fcULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd5388ULL) ^ 0x1e5270ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2381 | PC: 0x106204 | FDE: 0x1e5288 | Size: 12 bytes
// Khung tháo gỡ #2381 | Địa chỉ PC: 0x106204 | Địa chỉ FDE: 0x1e5288 | Kích thước: 12 bytes
//   0x106204: AA0103E0  mov      x0, x1
//   0x106208: 52800041  mov      w1, #2
//   0x10620c: 17FD569D  b        #0x5bc80
static inline uint64_t fde_func_2381_0x106204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106204ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x52800041ULL) ^ 0x1e5288ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2382 | PC: 0x106210 | FDE: 0x1e52a0 | Size: 256 bytes
// Khung tháo gỡ #2382 | Địa chỉ PC: 0x106210 | Địa chỉ FDE: 0x1e52a0 | Kích thước: 256 bytes
//   0x106210: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x106214: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x106218: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10621c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2382_0x106210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106210ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e52a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2383 | PC: 0x106324 | FDE: 0x1e52c8 | Size: 28 bytes
// Khung tháo gỡ #2383 | Địa chỉ PC: 0x106324 | Địa chỉ FDE: 0x1e52c8 | Kích thước: 28 bytes
//   0x106324: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x106328: 910003FD  mov      x29, sp
//   0x10632c: AA0103E0  mov      x0, x1
//   0x106330: 97FD5730  bl       #0x5bff0
static inline uint64_t fde_func_2383_0x106324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106324ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e52c8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2384 | PC: 0x106340 | FDE: 0x1e52e8 | Size: 72 bytes
// Khung tháo gỡ #2384 | Địa chỉ PC: 0x106340 | Địa chỉ FDE: 0x1e52e8 | Kích thước: 72 bytes
//   0x106340: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x106344: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x106348: 910043FD  add      x29, sp, #0x10
//   0x10634c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_2384_0x106340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106340ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e52e8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2385 | PC: 0x106388 | FDE: 0x1e5308 | Size: 256 bytes
// Khung tháo gỡ #2385 | Địa chỉ PC: 0x106388 | Địa chỉ FDE: 0x1e5308 | Kích thước: 256 bytes
//   0x106388: D102C3FF  sub      sp, sp, #0xb0
//   0x10638c: F90033F9  str      x25, [sp, #0x60]
//   0x106390: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x106394: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_2385_0x106388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106388ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x1e5308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2386 | PC: 0x1066cc | FDE: 0x1e5330 | Size: 120 bytes
// Khung tháo gỡ #2386 | Địa chỉ PC: 0x1066cc | Địa chỉ FDE: 0x1e5330 | Kích thước: 120 bytes
//   0x1066cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1066d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1066d4: 910043FD  add      x29, sp, #0x10
//   0x1066d8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_2386_0x1066cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1066ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5330ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2387 | PC: 0x106744 | FDE: 0x1e5350 | Size: 116 bytes
// Khung tháo gỡ #2387 | Địa chỉ PC: 0x106744 | Địa chỉ FDE: 0x1e5350 | Kích thước: 116 bytes
//   0x106744: D100C3FF  sub      sp, sp, #0x30
//   0x106748: F9000BF3  str      x19, [sp, #0x10]
//   0x10674c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x106750: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2387_0x106744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106744ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1e5350ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2388 | PC: 0x1067b8 | FDE: 0x1e5370 | Size: 88 bytes
// Khung tháo gỡ #2388 | Địa chỉ PC: 0x1067b8 | Địa chỉ FDE: 0x1e5370 | Kích thước: 88 bytes
//   0x1067b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1067bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1067c0: 910043FD  add      x29, sp, #0x10
//   0x1067c4: F100085F  cmp      x2, #2
static inline uint64_t fde_func_2388_0x1067b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1067b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5370ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2389 | PC: 0x106810 | FDE: 0x1e5390 | Size: 256 bytes
// Khung tháo gỡ #2389 | Địa chỉ PC: 0x106810 | Địa chỉ FDE: 0x1e5390 | Kích thước: 256 bytes
//   0x106810: D101C3FF  sub      sp, sp, #0x70
//   0x106814: F90013F9  str      x25, [sp, #0x20]
//   0x106818: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x10681c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2389_0x106810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106810ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1e5390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2390 | PC: 0x106ad8 | FDE: 0x1e53b8 | Size: 256 bytes
// Khung tháo gỡ #2390 | Địa chỉ PC: 0x106ad8 | Địa chỉ FDE: 0x1e53b8 | Kích thước: 256 bytes
//   0x106ad8: D10183FF  sub      sp, sp, #0x60
//   0x106adc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x106ae0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x106ae4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2390_0x106ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106ad8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e53b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2391 | PC: 0x106d74 | FDE: 0x1e53e0 | Size: 200 bytes
// Khung tháo gỡ #2391 | Địa chỉ PC: 0x106d74 | Địa chỉ FDE: 0x1e53e0 | Kích thước: 200 bytes
//   0x106d74: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x106d78: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x106d7c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x106d80: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2391_0x106d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106d74ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e53e0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #2392 | PC: 0x106e3c | FDE: 0x1e5400 | Size: 236 bytes
// Khung tháo gỡ #2392 | Địa chỉ PC: 0x106e3c | Địa chỉ FDE: 0x1e5400 | Kích thước: 236 bytes
//   0x106e3c: D10103FF  sub      sp, sp, #0x40
//   0x106e40: F9000BF5  str      x21, [sp, #0x10]
//   0x106e44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x106e48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2392_0x106e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106e3cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e5400ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #2393 | PC: 0x106f28 | FDE: 0x1e5420 | Size: 36 bytes
// Khung tháo gỡ #2393 | Địa chỉ PC: 0x106f28 | Địa chỉ FDE: 0x1e5420 | Kích thước: 36 bytes
//   0x106f28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x106f2c: 910003FD  mov      x29, sp
//   0x106f30: 97FD5134  bl       #0x5b400
//   0x106f34: B4000080  cbz      x0, #0x106f44
static inline uint64_t fde_func_2393_0x106f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106f28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5420ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2394 | PC: 0x106f4c | FDE: 0x1e5440 | Size: 240 bytes
// Khung tháo gỡ #2394 | Địa chỉ PC: 0x106f4c | Địa chỉ FDE: 0x1e5440 | Kích thước: 240 bytes
//   0x106f4c: D100C3FF  sub      sp, sp, #0x30
//   0x106f50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x106f54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x106f58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2394_0x106f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106f4cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5440ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #2395 | PC: 0x10703c | FDE: 0x1e5460 | Size: 44 bytes
// Khung tháo gỡ #2395 | Địa chỉ PC: 0x10703c | Địa chỉ FDE: 0x1e5460 | Kích thước: 44 bytes
//   0x10703c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x107040: 910003FD  mov      x29, sp
//   0x107044: AA0103E0  mov      x0, x1
//   0x107048: 97FD529E  bl       #0x5bac0
static inline uint64_t fde_func_2395_0x10703c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10703cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5460ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #2396 | PC: 0x107068 | FDE: 0x1e5480 | Size: 12 bytes
// Khung tháo gỡ #2396 | Địa chỉ PC: 0x107068 | Địa chỉ FDE: 0x1e5480 | Kích thước: 12 bytes
//   0x107068: AA0103E0  mov      x0, x1
//   0x10706c: 52800201  mov      w1, #0x10
//   0x107070: 17FD5304  b        #0x5bc80
static inline uint64_t fde_func_2396_0x107068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107068ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x52800201ULL) ^ 0x1e5480ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2397 | PC: 0x107074 | FDE: 0x1e5498 | Size: 100 bytes
// Khung tháo gỡ #2397 | Địa chỉ PC: 0x107074 | Địa chỉ FDE: 0x1e5498 | Kích thước: 100 bytes
//   0x107074: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x107078: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10707c: 910043FD  add      x29, sp, #0x10
//   0x107080: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_2397_0x107074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107074ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5498ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2398 | PC: 0x1070d8 | FDE: 0x1e54b8 | Size: 256 bytes
// Khung tháo gỡ #2398 | Địa chỉ PC: 0x1070d8 | Địa chỉ FDE: 0x1e54b8 | Kích thước: 256 bytes
//   0x1070d8: D10243FF  sub      sp, sp, #0x90
//   0x1070dc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1070e0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1070e4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2398_0x1070d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1070d8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e54b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2399 | PC: 0x1077b4 | FDE: 0x1e54e8 | Size: 100 bytes
// Khung tháo gỡ #2399 | Địa chỉ PC: 0x1077b4 | Địa chỉ FDE: 0x1e54e8 | Kích thước: 100 bytes
//   0x1077b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1077b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1077bc: 910043FD  add      x29, sp, #0x10
//   0x1077c0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_2399_0x1077b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1077b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e54e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2400 | PC: 0x107818 | FDE: 0x1e5508 | Size: 100 bytes
// Khung tháo gỡ #2400 | Địa chỉ PC: 0x107818 | Địa chỉ FDE: 0x1e5508 | Kích thước: 100 bytes
//   0x107818: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10781c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x107820: 910043FD  add      x29, sp, #0x10
//   0x107824: F100085F  cmp      x2, #2
static inline uint64_t fde_func_2400_0x107818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107818ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5508ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2401 | PC: 0x10787c | FDE: 0x1e5528 | Size: 164 bytes
// Khung tháo gỡ #2401 | Địa chỉ PC: 0x10787c | Địa chỉ FDE: 0x1e5528 | Kích thước: 164 bytes
//   0x10787c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x107880: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x107884: 910043FD  add      x29, sp, #0x10
//   0x107888: D1000449  sub      x9, x2, #1
static inline uint64_t fde_func_2401_0x10787c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10787cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5528ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2402 | PC: 0x107920 | FDE: 0x1e5548 | Size: 8 bytes
// Khung tháo gỡ #2402 | Địa chỉ PC: 0x107920 | Địa chỉ FDE: 0x1e5548 | Kích thước: 8 bytes
//   0x107920: AA0103E0  mov      x0, x1
//   0x107924: 17FD53C3  b        #0x5c830
static inline uint64_t fde_func_2402_0x107920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107920ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd53c3ULL) ^ 0x1e5548ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2403 | PC: 0x107928 | FDE: 0x1e5560 | Size: 40 bytes
// Khung tháo gỡ #2403 | Địa chỉ PC: 0x107928 | Địa chỉ FDE: 0x1e5560 | Kích thước: 40 bytes
//   0x107928: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10792c: 910003FD  mov      x29, sp
//   0x107930: AA0103E0  mov      x0, x1
//   0x107934: 97FD4F27  bl       #0x5b5d0
static inline uint64_t fde_func_2403_0x107928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107928ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5560ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2404 | PC: 0x107950 | FDE: 0x1e5580 | Size: 36 bytes
// Khung tháo gỡ #2404 | Địa chỉ PC: 0x107950 | Địa chỉ FDE: 0x1e5580 | Kích thước: 36 bytes
//   0x107950: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x107954: 910003FD  mov      x29, sp
//   0x107958: 97FD43FE  bl       #0x58950
//   0x10795c: B4000080  cbz      x0, #0x10796c
static inline uint64_t fde_func_2404_0x107950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107950ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5580ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2405 | PC: 0x107974 | FDE: 0x1e55a0 | Size: 20 bytes
// Khung tháo gỡ #2405 | Địa chỉ PC: 0x107974 | Địa chỉ FDE: 0x1e55a0 | Kích thước: 20 bytes
//   0x107974: AA0203E8  mov      x8, x2
//   0x107978: 52800082  mov      w2, #4
//   0x10797c: AA0103E0  mov      x0, x1
//   0x107980: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_2405_0x107974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107974ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0x52800082ULL) ^ 0x1e55a0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2406 | PC: 0x107988 | FDE: 0x1e55b8 | Size: 16 bytes
// Khung tháo gỡ #2406 | Địa chỉ PC: 0x107988 | Địa chỉ FDE: 0x1e55b8 | Kích thước: 16 bytes
//   0x107988: AA0103E0  mov      x0, x1
//   0x10798c: AA0203E1  mov      x1, x2
//   0x107990: 2A1F03E2  mov      w2, wzr
//   0x107994: 14000417  b        #0x1089f0
static inline uint64_t fde_func_2406_0x107988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107988ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x1e55b8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2407 | PC: 0x107998 | FDE: 0x1e55d0 | Size: 248 bytes
// Khung tháo gỡ #2407 | Địa chỉ PC: 0x107998 | Địa chỉ FDE: 0x1e55d0 | Kích thước: 248 bytes
//   0x107998: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10799c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1079a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1079a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2407_0x107998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107998ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e55d0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2408 | PC: 0x107a90 | FDE: 0x1e55f0 | Size: 216 bytes
// Khung tháo gỡ #2408 | Địa chỉ PC: 0x107a90 | Địa chỉ FDE: 0x1e55f0 | Kích thước: 216 bytes
//   0x107a90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x107a94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x107a98: 910043FD  add      x29, sp, #0x10
//   0x107a9c: D1000448  sub      x8, x2, #1
static inline uint64_t fde_func_2408_0x107a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107a90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e55f0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #2409 | PC: 0x107b68 | FDE: 0x1e5610 | Size: 12 bytes
// Khung tháo gỡ #2409 | Địa chỉ PC: 0x107b68 | Địa chỉ FDE: 0x1e5610 | Kích thước: 12 bytes
//   0x107b68: AA0103E0  mov      x0, x1
//   0x107b6c: 52800101  mov      w1, #8
//   0x107b70: 17FD5044  b        #0x5bc80
static inline uint64_t fde_func_2409_0x107b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107b68ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x52800101ULL) ^ 0x1e5610ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2410 | PC: 0x107b74 | FDE: 0x1e5628 | Size: 256 bytes
// Khung tháo gỡ #2410 | Địa chỉ PC: 0x107b74 | Địa chỉ FDE: 0x1e5628 | Kích thước: 256 bytes
//   0x107b74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x107b78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x107b7c: 910043FD  add      x29, sp, #0x10
//   0x107b80: F9400420  ldr      x0, [x1, #8]
static inline uint64_t fde_func_2410_0x107b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107b74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2411 | PC: 0x107ce4 | FDE: 0x1e5648 | Size: 192 bytes
// Khung tháo gỡ #2411 | Địa chỉ PC: 0x107ce4 | Địa chỉ FDE: 0x1e5648 | Kích thước: 192 bytes
//   0x107ce4: D10143FF  sub      sp, sp, #0x50
//   0x107ce8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x107cec: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x107cf0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2411_0x107ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107ce4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e5648ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2412 | PC: 0x107da4 | FDE: 0x1e5668 | Size: 256 bytes
// Khung tháo gỡ #2412 | Địa chỉ PC: 0x107da4 | Địa chỉ FDE: 0x1e5668 | Kích thước: 256 bytes
//   0x107da4: D101C3FF  sub      sp, sp, #0x70
//   0x107da8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x107dac: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x107db0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2412_0x107da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107da4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1e5668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2413 | PC: 0x108000 | FDE: 0x1e5690 | Size: 8 bytes
// Khung tháo gỡ #2413 | Địa chỉ PC: 0x108000 | Địa chỉ FDE: 0x1e5690 | Kích thước: 8 bytes
//   0x108000: AA0103E0  mov      x0, x1
//   0x108004: 17FD5237  b        #0x5c8e0
static inline uint64_t fde_func_2413_0x108000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108000ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd5237ULL) ^ 0x1e5690ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2414 | PC: 0x108008 | FDE: 0x1e56a8 | Size: 256 bytes
// Khung tháo gỡ #2414 | Địa chỉ PC: 0x108008 | Địa chỉ FDE: 0x1e56a8 | Kích thước: 256 bytes
//   0x108008: D101C3FF  sub      sp, sp, #0x70
//   0x10800c: F9001BF7  str      x23, [sp, #0x30]
//   0x108010: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x108014: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2414_0x108008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108008ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e56a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2415 | PC: 0x108218 | FDE: 0x1e56d0 | Size: 112 bytes
// Khung tháo gỡ #2415 | Địa chỉ PC: 0x108218 | Địa chỉ FDE: 0x1e56d0 | Kích thước: 112 bytes
//   0x108218: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10821c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x108220: 910043FD  add      x29, sp, #0x10
//   0x108224: F1000C5F  cmp      x2, #3
static inline uint64_t fde_func_2415_0x108218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108218ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e56d0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2416 | PC: 0x108288 | FDE: 0x1e56f0 | Size: 256 bytes
// Khung tháo gỡ #2416 | Địa chỉ PC: 0x108288 | Địa chỉ FDE: 0x1e56f0 | Kích thước: 256 bytes
//   0x108288: D10183FF  sub      sp, sp, #0x60
//   0x10828c: F9000BF9  str      x25, [sp, #0x10]
//   0x108290: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x108294: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2416_0x108288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108288ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1e56f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2417 | PC: 0x108404 | FDE: 0x1e5718 | Size: 256 bytes
// Khung tháo gỡ #2417 | Địa chỉ PC: 0x108404 | Địa chỉ FDE: 0x1e5718 | Kích thước: 256 bytes
//   0x108404: D10283FF  sub      sp, sp, #0xa0
//   0x108408: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x10840c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x108410: A90567FA  stp      x26, x25, [sp, #0x50]
static inline uint64_t fde_func_2417_0x108404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108404ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0x6d0323e9ULL) ^ 0x1e5718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2418 | PC: 0x108930 | FDE: 0x1e5750 | Size: 192 bytes
// Khung tháo gỡ #2418 | Địa chỉ PC: 0x108930 | Địa chỉ FDE: 0x1e5750 | Kích thước: 192 bytes
//   0x108930: D10103FF  sub      sp, sp, #0x40
//   0x108934: F90013F3  str      x19, [sp, #0x20]
//   0x108938: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x10893c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2418_0x108930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108930ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e5750ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2419 | PC: 0x1089f0 | FDE: 0x1e5770 | Size: 256 bytes
// Khung tháo gỡ #2419 | Địa chỉ PC: 0x1089f0 | Địa chỉ FDE: 0x1e5770 | Kích thước: 256 bytes
//   0x1089f0: D10243FF  sub      sp, sp, #0x90
//   0x1089f4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1089f8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1089fc: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2419_0x1089f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1089f0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e5770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2420 | PC: 0x108e10 | FDE: 0x1e57a0 | Size: 144 bytes [PyCodec_Register]
// Khung tháo gỡ #2420 | Địa chỉ PC: 0x108e10 | Địa chỉ FDE: 0x1e57a0 | Kích thước: 144 bytes
//   0x108e10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x108e14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x108e18: 910043FD  add      x29, sp, #0x10
//   0x108e1c: F00007A8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2420_0x108e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108e10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e57a0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2421 | PC: 0x108ea0 | FDE: 0x1e57c0 | Size: 256 bytes
// Khung tháo gỡ #2421 | Địa chỉ PC: 0x108ea0 | Địa chỉ FDE: 0x1e57c0 | Kích thước: 256 bytes
//   0x108ea0: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x108ea4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x108ea8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x108eac: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2421_0x108ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108ea0ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e57c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2422 | PC: 0x109018 | FDE: 0x1e57f0 | Size: 140 bytes [PyCodec_Unregister]
// Khung tháo gỡ #2422 | Địa chỉ PC: 0x109018 | Địa chỉ FDE: 0x1e57f0 | Kích thước: 140 bytes
//   0x109018: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10901c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109024: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2422_0x109018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109018ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e57f0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2423 | PC: 0x1090a4 | FDE: 0x1e5810 | Size: 256 bytes [_PyCodec_Lookup]
// Khung tháo gỡ #2423 | Địa chỉ PC: 0x1090a4 | Địa chỉ FDE: 0x1e5810 | Kích thước: 256 bytes
//   0x1090a4: D10203FF  sub      sp, sp, #0x80
//   0x1090a8: F90013FB  str      x27, [sp, #0x20]
//   0x1090ac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1090b0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2423_0x1090a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1090a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e5810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2424 | PC: 0x1093e8 | FDE: 0x1e5840 | Size: 64 bytes [PyCodec_KnownEncoding]
// Khung tháo gỡ #2424 | Địa chỉ PC: 0x1093e8 | Địa chỉ FDE: 0x1e5840 | Kích thước: 64 bytes
//   0x1093e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1093ec: 910003FD  mov      x29, sp
//   0x1093f0: 97FD3DA8  bl       #0x58a90
//   0x1093f4: B4000120  cbz      x0, #0x109418
static inline uint64_t fde_func_2424_0x1093e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1093e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5840ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2425 | PC: 0x109428 | FDE: 0x1e5860 | Size: 12 bytes [_PyCodecInfo_GetIncrementalDecoder]
// Khung tháo gỡ #2425 | Địa chỉ PC: 0x109428 | Địa chỉ FDE: 0x1e5860 | Kích thước: 12 bytes
//   0x109428: D0000562  adrp     x2, #0x1b7000
//   0x10942c: 910ADC42  add      x2, x2, #0x2b7
//   0x109430: 14000001  b        #0x109434
static inline uint64_t fde_func_2425_0x109428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109428ULL ^ (static_cast<uint64_t>(0xd0000562ULL) << 13);
    acc = (acc + a1 + 0x910adc42ULL) ^ 0x1e5860ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2426 | PC: 0x109434 | FDE: 0x1e5878 | Size: 212 bytes
// Khung tháo gỡ #2426 | Địa chỉ PC: 0x109434 | Địa chỉ FDE: 0x1e5878 | Kích thước: 212 bytes
//   0x109434: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x109438: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10943c: 910043FD  add      x29, sp, #0x10
//   0x109440: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_2426_0x109434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109434ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5878ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #2427 | PC: 0x109508 | FDE: 0x1e5898 | Size: 12 bytes [_PyCodecInfo_GetIncrementalEncoder]
// Khung tháo gỡ #2427 | Địa chỉ PC: 0x109508 | Địa chỉ FDE: 0x1e5898 | Kích thước: 12 bytes
//   0x109508: D0000562  adrp     x2, #0x1b7000
//   0x10950c: 910B2842  add      x2, x2, #0x2ca
//   0x109510: 17FFFFC9  b        #0x109434
static inline uint64_t fde_func_2427_0x109508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109508ULL ^ (static_cast<uint64_t>(0xd0000562ULL) << 13);
    acc = (acc + a1 + 0x910b2842ULL) ^ 0x1e5898ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2428 | PC: 0x109514 | FDE: 0x1e58b0 | Size: 80 bytes [PyCodec_Encoder]
// Khung tháo gỡ #2428 | Địa chỉ PC: 0x109514 | Địa chỉ FDE: 0x1e58b0 | Kích thước: 80 bytes
//   0x109514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x109518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10951c: 910043FD  add      x29, sp, #0x10
//   0x109520: 97FD3D5C  bl       #0x58a90
static inline uint64_t fde_func_2428_0x109514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109514ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e58b0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2429 | PC: 0x109564 | FDE: 0x1e58d0 | Size: 80 bytes [PyCodec_Decoder]
// Khung tháo gỡ #2429 | Địa chỉ PC: 0x109564 | Địa chỉ FDE: 0x1e58d0 | Kích thước: 80 bytes
//   0x109564: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x109568: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10956c: 910043FD  add      x29, sp, #0x10
//   0x109570: 97FD3D48  bl       #0x58a90
static inline uint64_t fde_func_2429_0x109564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109564ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e58d0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2430 | PC: 0x1095b4 | FDE: 0x1e58f0 | Size: 96 bytes [PyCodec_IncrementalEncoder]
// Khung tháo gỡ #2430 | Địa chỉ PC: 0x1095b4 | Địa chỉ FDE: 0x1e58f0 | Kích thước: 96 bytes
//   0x1095b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1095b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1095bc: 910043FD  add      x29, sp, #0x10
//   0x1095c0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_2430_0x1095b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1095b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e58f0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2431 | PC: 0x109614 | FDE: 0x1e5910 | Size: 96 bytes [PyCodec_IncrementalDecoder]
// Khung tháo gỡ #2431 | Địa chỉ PC: 0x109614 | Địa chỉ FDE: 0x1e5910 | Kích thước: 96 bytes
//   0x109614: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x109618: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10961c: 910043FD  add      x29, sp, #0x10
//   0x109620: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_2431_0x109614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109614ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5910ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2432 | PC: 0x109674 | FDE: 0x1e5930 | Size: 8 bytes [PyCodec_StreamReader]
// Khung tháo gỡ #2432 | Địa chỉ PC: 0x109674 | Địa chỉ FDE: 0x1e5930 | Kích thước: 8 bytes
//   0x109674: 52800043  mov      w3, #2
//   0x109678: 14000001  b        #0x10967c
static inline uint64_t fde_func_2432_0x109674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109674ULL ^ (static_cast<uint64_t>(0x52800043ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e5930ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2433 | PC: 0x10967c | FDE: 0x1e5948 | Size: 256 bytes
// Khung tháo gỡ #2433 | Địa chỉ PC: 0x10967c | Địa chỉ FDE: 0x1e5948 | Kích thước: 256 bytes
//   0x10967c: D10183FF  sub      sp, sp, #0x60
//   0x109680: F90013F7  str      x23, [sp, #0x20]
//   0x109684: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x109688: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2433_0x10967c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10967cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e5948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2434 | PC: 0x1097a4 | FDE: 0x1e5970 | Size: 8 bytes [PyCodec_StreamWriter]
// Khung tháo gỡ #2434 | Địa chỉ PC: 0x1097a4 | Địa chỉ FDE: 0x1e5970 | Kích thước: 8 bytes
//   0x1097a4: 52800063  mov      w3, #3
//   0x1097a8: 17FFFFB5  b        #0x10967c
static inline uint64_t fde_func_2434_0x1097a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1097a4ULL ^ (static_cast<uint64_t>(0x52800063ULL) << 13);
    acc = (acc + a1 + 0x17ffffb5ULL) ^ 0x1e5970ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2435 | PC: 0x1097ac | FDE: 0x1e5988 | Size: 132 bytes [PyCodec_Encode]
// Khung tháo gỡ #2435 | Địa chỉ PC: 0x1097ac | Địa chỉ FDE: 0x1e5988 | Kích thước: 132 bytes
//   0x1097ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1097b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1097b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1097b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2435_0x1097ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1097acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5988ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2436 | PC: 0x109830 | FDE: 0x1e59b0 | Size: 256 bytes
// Khung tháo gỡ #2436 | Địa chỉ PC: 0x109830 | Địa chỉ FDE: 0x1e59b0 | Kích thước: 256 bytes
//   0x109830: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x109834: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x109838: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10983c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2436_0x109830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109830ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e59b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2437 | PC: 0x1099b8 | FDE: 0x1e59d8 | Size: 132 bytes [PyCodec_Decode]
// Khung tháo gỡ #2437 | Địa chỉ PC: 0x1099b8 | Địa chỉ FDE: 0x1e59d8 | Kích thước: 132 bytes
//   0x1099b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1099bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1099c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1099c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2437_0x1099b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1099b8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e59d8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2438 | PC: 0x109a3c | FDE: 0x1e5a00 | Size: 256 bytes
// Khung tháo gỡ #2438 | Địa chỉ PC: 0x109a3c | Địa chỉ FDE: 0x1e5a00 | Kích thước: 256 bytes
//   0x109a3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x109a40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x109a44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x109a48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2438_0x109a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109a3cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2439 | PC: 0x109bf8 | FDE: 0x1e5a28 | Size: 256 bytes [_PyCodec_LookupTextEncoding]
// Khung tháo gỡ #2439 | Địa chỉ PC: 0x109bf8 | Địa chỉ FDE: 0x1e5a28 | Kích thước: 256 bytes
//   0x109bf8: D10143FF  sub      sp, sp, #0x50
//   0x109bfc: F9000BF7  str      x23, [sp, #0x10]
//   0x109c00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x109c04: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2439_0x109bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109bf8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1e5a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2440 | PC: 0x109d18 | FDE: 0x1e5a50 | Size: 144 bytes [_PyCodec_EncodeText]
// Khung tháo gỡ #2440 | Địa chỉ PC: 0x109d18 | Địa chỉ FDE: 0x1e5a50 | Kích thước: 144 bytes
//   0x109d18: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x109d1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109d20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109d24: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2440_0x109d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109d18ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5a50ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2441 | PC: 0x109da8 | FDE: 0x1e5a78 | Size: 144 bytes [_PyCodec_DecodeText]
// Khung tháo gỡ #2441 | Địa chỉ PC: 0x109da8 | Địa chỉ FDE: 0x1e5a78 | Kích thước: 144 bytes
//   0x109da8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x109dac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109db0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109db4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2441_0x109da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109da8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5a78ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2442 | PC: 0x109e38 | FDE: 0x1e5aa0 | Size: 152 bytes [PyCodec_RegisterError]
// Khung tháo gỡ #2442 | Địa chỉ PC: 0x109e38 | Địa chỉ FDE: 0x1e5aa0 | Kích thước: 152 bytes
//   0x109e38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x109e3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109e40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109e44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2442_0x109e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109e38ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5aa0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2443 | PC: 0x109ed0 | FDE: 0x1e5ac0 | Size: 160 bytes [PyCodec_LookupError]
// Khung tháo gỡ #2443 | Địa chỉ PC: 0x109ed0 | Địa chỉ FDE: 0x1e5ac0 | Kích thước: 160 bytes
//   0x109ed0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x109ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x109ed8: 910043FD  add      x29, sp, #0x10
//   0x109edc: D00007A8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2443_0x109ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109ed0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5ac0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2444 | PC: 0x109f70 | FDE: 0x1e5ae0 | Size: 68 bytes [PyCodec_StrictErrors]
// Khung tháo gỡ #2444 | Địa chỉ PC: 0x109f70 | Địa chỉ FDE: 0x1e5ae0 | Kích thước: 68 bytes
//   0x109f70: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x109f74: 910003FD  mov      x29, sp
//   0x109f78: AA0003E1  mov      x1, x0
//   0x109f7c: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_2444_0x109f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109f70ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5ae0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2445 | PC: 0x109fb4 | FDE: 0x1e5b00 | Size: 256 bytes [PyCodec_IgnoreErrors]
// Khung tháo gỡ #2445 | Địa chỉ PC: 0x109fb4 | Địa chỉ FDE: 0x1e5b00 | Kích thước: 256 bytes
//   0x109fb4: D100C3FF  sub      sp, sp, #0x30
//   0x109fb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109fbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109fc0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2445_0x109fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109fb4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2446 | PC: 0x10a0dc | FDE: 0x1e5b20 | Size: 256 bytes [PyCodec_ReplaceErrors]
// Khung tháo gỡ #2446 | Địa chỉ PC: 0x10a0dc | Địa chỉ FDE: 0x1e5b20 | Kích thước: 256 bytes
//   0x10a0dc: D10143FF  sub      sp, sp, #0x50
//   0x10a0e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10a0e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10a0e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2446_0x10a0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a0dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e5b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2447 | PC: 0x10a33c | FDE: 0x1e5b48 | Size: 256 bytes [PyCodec_XMLCharRefReplaceErrors]
// Khung tháo gỡ #2447 | Địa chỉ PC: 0x10a33c | Địa chỉ FDE: 0x1e5b48 | Kích thước: 256 bytes
//   0x10a33c: D10143FF  sub      sp, sp, #0x50
//   0x10a340: F90013F5  str      x21, [sp, #0x20]
//   0x10a344: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10a348: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2447_0x10a33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a33cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e5b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2448 | PC: 0x10a6fc | FDE: 0x1e5b68 | Size: 256 bytes [PyCodec_BackslashReplaceErrors]
// Khung tháo gỡ #2448 | Địa chỉ PC: 0x10a6fc | Địa chỉ FDE: 0x1e5b68 | Kích thước: 256 bytes
//   0x10a6fc: D10143FF  sub      sp, sp, #0x50
//   0x10a700: F90013F5  str      x21, [sp, #0x20]
//   0x10a704: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10a708: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2448_0x10a6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a6fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e5b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2449 | PC: 0x10abb4 | FDE: 0x1e5b88 | Size: 256 bytes [PyCodec_NameReplaceErrors]
// Khung tháo gỡ #2449 | Địa chỉ PC: 0x10abb4 | Địa chỉ FDE: 0x1e5b88 | Kích thước: 256 bytes
//   0x10abb4: D10643FF  sub      sp, sp, #0x190
//   0x10abb8: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x10abbc: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x10abc0: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_2449_0x10abb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10abb4ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa9136ffcULL) ^ 0x1e5b88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2450 | PC: 0x10affc | FDE: 0x1e5bb8 | Size: 64 bytes
// Khung tháo gỡ #2450 | Địa chỉ PC: 0x10affc | Địa chỉ FDE: 0x1e5bb8 | Kích thước: 64 bytes
//   0x10affc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10b000: 910003FD  mov      x29, sp
//   0x10b004: F9400420  ldr      x0, [x1, #8]
//   0x10b008: 3942AC08  ldrb     w8, [x0, #0xab]
static inline uint64_t fde_func_2450_0x10affc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10affcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5bb8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2451 | PC: 0x10b03c | FDE: 0x1e5bd8 | Size: 8 bytes
// Khung tháo gỡ #2451 | Địa chỉ PC: 0x10b03c | Địa chỉ FDE: 0x1e5bd8 | Kích thước: 8 bytes
//   0x10b03c: AA0103E0  mov      x0, x1
//   0x10b040: 17FD49B0  b        #0x5d700
static inline uint64_t fde_func_2451_0x10b03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b03cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd49b0ULL) ^ 0x1e5bd8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2452 | PC: 0x10b044 | FDE: 0x1e5bf0 | Size: 8 bytes
// Khung tháo gỡ #2452 | Địa chỉ PC: 0x10b044 | Địa chỉ FDE: 0x1e5bf0 | Kích thước: 8 bytes
//   0x10b044: AA0103E0  mov      x0, x1
//   0x10b048: 17FD42D6  b        #0x5bba0
static inline uint64_t fde_func_2452_0x10b044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b044ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd42d6ULL) ^ 0x1e5bf0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2453 | PC: 0x10b04c | FDE: 0x1e5c08 | Size: 8 bytes
// Khung tháo gỡ #2453 | Địa chỉ PC: 0x10b04c | Địa chỉ FDE: 0x1e5c08 | Kích thước: 8 bytes
//   0x10b04c: AA0103E0  mov      x0, x1
//   0x10b050: 17FD3A2C  b        #0x59900
static inline uint64_t fde_func_2453_0x10b04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b04cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd3a2cULL) ^ 0x1e5c08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2454 | PC: 0x10b054 | FDE: 0x1e5c20 | Size: 8 bytes
// Khung tháo gỡ #2454 | Địa chỉ PC: 0x10b054 | Địa chỉ FDE: 0x1e5c20 | Kích thước: 8 bytes
//   0x10b054: AA0103E0  mov      x0, x1
//   0x10b058: 17FD3B1E  b        #0x59cd0
static inline uint64_t fde_func_2454_0x10b054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b054ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd3b1eULL) ^ 0x1e5c20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2455 | PC: 0x10b05c | FDE: 0x1e5c38 | Size: 8 bytes
// Khung tháo gỡ #2455 | Địa chỉ PC: 0x10b05c | Địa chỉ FDE: 0x1e5c38 | Kích thước: 8 bytes
//   0x10b05c: AA0103E0  mov      x0, x1
//   0x10b060: 17FD3C14  b        #0x5a0b0
static inline uint64_t fde_func_2455_0x10b05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b05cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd3c14ULL) ^ 0x1e5c38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2456 | PC: 0x10b064 | FDE: 0x1e5c50 | Size: 256 bytes
// Khung tháo gỡ #2456 | Địa chỉ PC: 0x10b064 | Địa chỉ FDE: 0x1e5c50 | Kích thước: 256 bytes
//   0x10b064: D10183FF  sub      sp, sp, #0x60
//   0x10b068: F90013F7  str      x23, [sp, #0x20]
//   0x10b06c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x10b070: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2456_0x10b064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b064ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e5c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2457 | PC: 0x10b5a0 | FDE: 0x1e5c78 | Size: 256 bytes
// Khung tháo gỡ #2457 | Địa chỉ PC: 0x10b5a0 | Địa chỉ FDE: 0x1e5c78 | Kích thước: 256 bytes
//   0x10b5a0: D10143FF  sub      sp, sp, #0x50
//   0x10b5a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10b5a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10b5ac: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2457_0x10b5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b5a0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e5c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2458 | PC: 0x10b910 | FDE: 0x1e5ca0 | Size: 256 bytes [_Py_Mangle]
// Khung tháo gỡ #2458 | Địa chỉ PC: 0x10b910 | Địa chỉ FDE: 0x1e5ca0 | Kích thước: 256 bytes
//   0x10b910: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x10b914: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10b918: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10b91c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2458_0x10b910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b910ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2459 | PC: 0x10be0c | FDE: 0x1e5cc8 | Size: 228 bytes [_PyErr_Restore]
// Khung tháo gỡ #2459 | Địa chỉ PC: 0x10be0c | Địa chỉ FDE: 0x1e5cc8 | Kích thước: 228 bytes
//   0x10be0c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10be10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10be14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10be18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2459_0x10be0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10be0cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5cc8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #2460 | PC: 0x10bef0 | FDE: 0x1e5cf0 | Size: 60 bytes [PyErr_Restore]
// Khung tháo gỡ #2460 | Địa chỉ PC: 0x10bef0 | Địa chỉ FDE: 0x1e5cf0 | Kích thước: 60 bytes
//   0x10bef0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10bef4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10bef8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10befc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2460_0x10bef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bef0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5cf0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2461 | PC: 0x10bf2c | FDE: 0x1e5d10 | Size: 48 bytes [_PyErr_GetTopmostException]
// Khung tháo gỡ #2461 | Địa chỉ PC: 0x10bf2c | Địa chỉ FDE: 0x1e5d10 | Kích thước: 48 bytes
//   0x10bf2c: 900007A8  adrp     x8, #0x1ff000
//   0x10bf30: F9404809  ldr      x9, [x0, #0x90]
//   0x10bf34: F945F108  ldr      x8, [x8, #0xbe0]
//   0x10bf38: 14000003  b        #0x10bf44
static inline uint64_t fde_func_2461_0x10bf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bf2cULL ^ (static_cast<uint64_t>(0x900007a8ULL) << 13);
    acc = (acc + a1 + 0xf9404809ULL) ^ 0x1e5d10ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2462 | PC: 0x10bf5c | FDE: 0x1e5d28 | Size: 256 bytes [_PyErr_SetObject]
// Khung tháo gỡ #2462 | Địa chỉ PC: 0x10bf5c | Địa chỉ FDE: 0x1e5d28 | Kích thước: 256 bytes
//   0x10bf5c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x10bf60: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x10bf64: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10bf68: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2462_0x10bf5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bf5cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e5d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2463 | PC: 0x10c24c | FDE: 0x1e5d58 | Size: 152 bytes [_PyErr_Format]
// Khung tháo gỡ #2463 | Địa chỉ PC: 0x10c24c | Địa chỉ FDE: 0x1e5d58 | Kích thước: 152 bytes
//   0x10c24c: D10483FF  sub      sp, sp, #0x120
//   0x10c250: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x10c254: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x10c258: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_2463_0x10c24c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c24cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1e5d58ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 2000: return fde_func_2000_0x0d9174(a0, a1);
        case 2001: return fde_func_2001_0x0d9444(a0, a1);
        case 2002: return fde_func_2002_0x0d967c(a0, a1);
        case 2003: return fde_func_2003_0x0d9684(a0, a1);
        case 2004: return fde_func_2004_0x0d983c(a0, a1);
        case 2005: return fde_func_2005_0x0d9844(a0, a1);
        case 2006: return fde_func_2006_0x0d98b4(a0, a1);
        case 2007: return fde_func_2007_0x0d9904(a0, a1);
        case 2008: return fde_func_2008_0x0d99c8(a0, a1);
        case 2009: return fde_func_2009_0x0d9b24(a0, a1);
        case 2010: return fde_func_2010_0x0d9b2c(a0, a1);
        case 2011: return fde_func_2011_0x0da440(a0, a1);
        case 2012: return fde_func_2012_0x0da818(a0, a1);
        case 2013: return fde_func_2013_0x0daac8(a0, a1);
        case 2014: return fde_func_2014_0x0dab18(a0, a1);
        case 2015: return fde_func_2015_0x0dab28(a0, a1);
        case 2016: return fde_func_2016_0x0dad28(a0, a1);
        case 2017: return fde_func_2017_0x0db090(a0, a1);
        case 2018: return fde_func_2018_0x0db170(a0, a1);
        case 2019: return fde_func_2019_0x0db3b8(a0, a1);
        case 2020: return fde_func_2020_0x0db414(a0, a1);
        case 2021: return fde_func_2021_0x0db420(a0, a1);
        case 2022: return fde_func_2022_0x0db428(a0, a1);
        case 2023: return fde_func_2023_0x0db998(a0, a1);
        case 2024: return fde_func_2024_0x0dbbdc(a0, a1);
        case 2025: return fde_func_2025_0x0dc43c(a0, a1);
        case 2026: return fde_func_2026_0x0dc668(a0, a1);
        case 2027: return fde_func_2027_0x0dc698(a0, a1);
        case 2028: return fde_func_2028_0x0dc6a0(a0, a1);
        case 2029: return fde_func_2029_0x0dc6a8(a0, a1);
        case 2030: return fde_func_2030_0x0dd040(a0, a1);
        case 2031: return fde_func_2031_0x0dda90(a0, a1);
        case 2032: return fde_func_2032_0x0ddac0(a0, a1);
        case 2033: return fde_func_2033_0x0ddac8(a0, a1);
        case 2034: return fde_func_2034_0x0de6e4(a0, a1);
        case 2035: return fde_func_2035_0x0de6ec(a0, a1);
        case 2036: return fde_func_2036_0x0de9d4(a0, a1);
        case 2037: return fde_func_2037_0x0dea24(a0, a1);
        case 2038: return fde_func_2038_0x0defa4(a0, a1);
        case 2039: return fde_func_2039_0x0df1f4(a0, a1);
        case 2040: return fde_func_2040_0x0df224(a0, a1);
        case 2041: return fde_func_2041_0x0df280(a0, a1);
        case 2042: return fde_func_2042_0x0df7dc(a0, a1);
        case 2043: return fde_func_2043_0x0df7e4(a0, a1);
        case 2044: return fde_func_2044_0x0df910(a0, a1);
        case 2045: return fde_func_2045_0x0df944(a0, a1);
        case 2046: return fde_func_2046_0x0df9a0(a0, a1);
        case 2047: return fde_func_2047_0x0dfa28(a0, a1);
        case 2048: return fde_func_2048_0x0e02ec(a0, a1);
        case 2049: return fde_func_2049_0x0e0748(a0, a1);
        case 2050: return fde_func_2050_0x0e0f40(a0, a1);
        case 2051: return fde_func_2051_0x0e116c(a0, a1);
        case 2052: return fde_func_2052_0x0e119c(a0, a1);
        case 2053: return fde_func_2053_0x0e11c4(a0, a1);
        case 2054: return fde_func_2054_0x0e122c(a0, a1);
        case 2055: return fde_func_2055_0x0e1c64(a0, a1);
        case 2056: return fde_func_2056_0x0e1cec(a0, a1);
        case 2057: return fde_func_2057_0x0e1e8c(a0, a1);
        case 2058: return fde_func_2058_0x0e1fd0(a0, a1);
        case 2059: return fde_func_2059_0x0e2190(a0, a1);
        case 2060: return fde_func_2060_0x0e2380(a0, a1);
        case 2061: return fde_func_2061_0x0e251c(a0, a1);
        case 2062: return fde_func_2062_0x0e2790(a0, a1);
        case 2063: return fde_func_2063_0x0e298c(a0, a1);
        case 2064: return fde_func_2064_0x0e2a50(a0, a1);
        case 2065: return fde_func_2065_0x0e2f78(a0, a1);
        case 2066: return fde_func_2066_0x0e32c0(a0, a1);
        case 2067: return fde_func_2067_0x0e337c(a0, a1);
        case 2068: return fde_func_2068_0x0e3640(a0, a1);
        case 2069: return fde_func_2069_0x0e36c0(a0, a1);
        case 2070: return fde_func_2070_0x0e3c3c(a0, a1);
        case 2071: return fde_func_2071_0x0e3cc0(a0, a1);
        case 2072: return fde_func_2072_0x0e3e94(a0, a1);
        case 2073: return fde_func_2073_0x0e45a0(a0, a1);
        case 2074: return fde_func_2074_0x0e4650(a0, a1);
        case 2075: return fde_func_2075_0x0e4888(a0, a1);
        case 2076: return fde_func_2076_0x0e49f4(a0, a1);
        case 2077: return fde_func_2077_0x0e4ae4(a0, a1);
        case 2078: return fde_func_2078_0x0e4c54(a0, a1);
        case 2079: return fde_func_2079_0x0e4e28(a0, a1);
        case 2080: return fde_func_2080_0x0e4ec4(a0, a1);
        case 2081: return fde_func_2081_0x0e5184(a0, a1);
        case 2082: return fde_func_2082_0x0e5418(a0, a1);
        case 2083: return fde_func_2083_0x0e5724(a0, a1);
        case 2084: return fde_func_2084_0x0e5768(a0, a1);
        case 2085: return fde_func_2085_0x0e587c(a0, a1);
        case 2086: return fde_func_2086_0x0e594c(a0, a1);
        case 2087: return fde_func_2087_0x0e5d50(a0, a1);
        case 2088: return fde_func_2088_0x0e5fa4(a0, a1);
        case 2089: return fde_func_2089_0x0e6074(a0, a1);
        case 2090: return fde_func_2090_0x0e766c(a0, a1);
        case 2091: return fde_func_2091_0x0e7718(a0, a1);
        case 2092: return fde_func_2092_0x0e8c1c(a0, a1);
        case 2093: return fde_func_2093_0x0e8ff8(a0, a1);
        case 2094: return fde_func_2094_0x0e93d4(a0, a1);
        case 2095: return fde_func_2095_0x0e9480(a0, a1);
        case 2096: return fde_func_2096_0x0ea85c(a0, a1);
        case 2097: return fde_func_2097_0x0eaa94(a0, a1);
        case 2098: return fde_func_2098_0x0eab3c(a0, a1);
        case 2099: return fde_func_2099_0x0eacb8(a0, a1);
        case 2100: return fde_func_2100_0x0eae08(a0, a1);
        case 2101: return fde_func_2101_0x0eafe4(a0, a1);
        case 2102: return fde_func_2102_0x0eb0f8(a0, a1);
        case 2103: return fde_func_2103_0x0eb6cc(a0, a1);
        case 2104: return fde_func_2104_0x0ece44(a0, a1);
        case 2105: return fde_func_2105_0x0ecf84(a0, a1);
        case 2106: return fde_func_2106_0x0ed8b8(a0, a1);
        case 2107: return fde_func_2107_0x0ed934(a0, a1);
        case 2108: return fde_func_2108_0x0ed9a4(a0, a1);
        case 2109: return fde_func_2109_0x0eda20(a0, a1);
        case 2110: return fde_func_2110_0x0ede3c(a0, a1);
        case 2111: return fde_func_2111_0x0edf50(a0, a1);
        case 2112: return fde_func_2112_0x0ee034(a0, a1);
        case 2113: return fde_func_2113_0x0ee0b4(a0, a1);
        case 2114: return fde_func_2114_0x0ee128(a0, a1);
        case 2115: return fde_func_2115_0x0ee200(a0, a1);
        case 2116: return fde_func_2116_0x0ee23c(a0, a1);
        case 2117: return fde_func_2117_0x0ee270(a0, a1);
        case 2118: return fde_func_2118_0x0ee330(a0, a1);
        case 2119: return fde_func_2119_0x0ee548(a0, a1);
        case 2120: return fde_func_2120_0x0ee650(a0, a1);
        case 2121: return fde_func_2121_0x0ee65c(a0, a1);
        case 2122: return fde_func_2122_0x0ee700(a0, a1);
        case 2123: return fde_func_2123_0x0ee7cc(a0, a1);
        case 2124: return fde_func_2124_0x0ee968(a0, a1);
        case 2125: return fde_func_2125_0x0eed58(a0, a1);
        case 2126: return fde_func_2126_0x0ef148(a0, a1);
        case 2127: return fde_func_2127_0x0ef79c(a0, a1);
        case 2128: return fde_func_2128_0x0efc60(a0, a1);
        case 2129: return fde_func_2129_0x0efe70(a0, a1);
        case 2130: return fde_func_2130_0x0f0014(a0, a1);
        case 2131: return fde_func_2131_0x0f00d0(a0, a1);
        case 2132: return fde_func_2132_0x0f00ec(a0, a1);
        case 2133: return fde_func_2133_0x0f0208(a0, a1);
        case 2134: return fde_func_2134_0x0f0330(a0, a1);
        case 2135: return fde_func_2135_0x0f08dc(a0, a1);
        case 2136: return fde_func_2136_0x0f0aa0(a0, a1);
        case 2137: return fde_func_2137_0x0f0c64(a0, a1);
        case 2138: return fde_func_2138_0x0f1210(a0, a1);
        case 2139: return fde_func_2139_0x0f13d4(a0, a1);
        case 2140: return fde_func_2140_0x0f1598(a0, a1);
        case 2141: return fde_func_2141_0x0f1b90(a0, a1);
        case 2142: return fde_func_2142_0x0f1d54(a0, a1);
        case 2143: return fde_func_2143_0x0f1f2c(a0, a1);
        case 2144: return fde_func_2144_0x0f2524(a0, a1);
        case 2145: return fde_func_2145_0x0f26e8(a0, a1);
        case 2146: return fde_func_2146_0x0f28c0(a0, a1);
        case 2147: return fde_func_2147_0x0f2998(a0, a1);
        case 2148: return fde_func_2148_0x0f2a60(a0, a1);
        case 2149: return fde_func_2149_0x0f2a88(a0, a1);
        case 2150: return fde_func_2150_0x0f2ac8(a0, a1);
        case 2151: return fde_func_2151_0x0f2ed0(a0, a1);
        case 2152: return fde_func_2152_0x0f3098(a0, a1);
        case 2153: return fde_func_2153_0x0f34bc(a0, a1);
        case 2154: return fde_func_2154_0x0f3660(a0, a1);
        case 2155: return fde_func_2155_0x0f37f0(a0, a1);
        case 2156: return fde_func_2156_0x0f3978(a0, a1);
        case 2157: return fde_func_2157_0x0f3b00(a0, a1);
        case 2158: return fde_func_2158_0x0f3b80(a0, a1);
        case 2159: return fde_func_2159_0x0f3c28(a0, a1);
        case 2160: return fde_func_2160_0x0f3dac(a0, a1);
        case 2161: return fde_func_2161_0x0f3ff8(a0, a1);
        case 2162: return fde_func_2162_0x0f4434(a0, a1);
        case 2163: return fde_func_2163_0x0f4500(a0, a1);
        case 2164: return fde_func_2164_0x0f4504(a0, a1);
        case 2165: return fde_func_2165_0x0f45ec(a0, a1);
        case 2166: return fde_func_2166_0x0f475c(a0, a1);
        case 2167: return fde_func_2167_0x0f481c(a0, a1);
        case 2168: return fde_func_2168_0x0f48a0(a0, a1);
        case 2169: return fde_func_2169_0x0f496c(a0, a1);
        case 2170: return fde_func_2170_0x0f4a54(a0, a1);
        case 2171: return fde_func_2171_0x0f4bc4(a0, a1);
        case 2172: return fde_func_2172_0x0f4c48(a0, a1);
        case 2173: return fde_func_2173_0x0f4c4c(a0, a1);
        case 2174: return fde_func_2174_0x0f4d30(a0, a1);
        case 2175: return fde_func_2175_0x0f4db4(a0, a1);
        case 2176: return fde_func_2176_0x0f4dc0(a0, a1);
        case 2177: return fde_func_2177_0x0f4e80(a0, a1);
        case 2178: return fde_func_2178_0x0f4fc8(a0, a1);
        case 2179: return fde_func_2179_0x0f5110(a0, a1);
        case 2180: return fde_func_2180_0x0f5208(a0, a1);
        case 2181: return fde_func_2181_0x0f5308(a0, a1);
        case 2182: return fde_func_2182_0x0f5350(a0, a1);
        case 2183: return fde_func_2183_0x0f54a8(a0, a1);
        case 2184: return fde_func_2184_0x0f5604(a0, a1);
        case 2185: return fde_func_2185_0x0f5794(a0, a1);
        case 2186: return fde_func_2186_0x0f595c(a0, a1);
        case 2187: return fde_func_2187_0x0f5a84(a0, a1);
        case 2188: return fde_func_2188_0x0f5bac(a0, a1);
        case 2189: return fde_func_2189_0x0f5cd4(a0, a1);
        case 2190: return fde_func_2190_0x0f5e64(a0, a1);
        case 2191: return fde_func_2191_0x0f5e7c(a0, a1);
        case 2192: return fde_func_2192_0x0f5f9c(a0, a1);
        case 2193: return fde_func_2193_0x0f6038(a0, a1);
        case 2194: return fde_func_2194_0x0f60d0(a0, a1);
        case 2195: return fde_func_2195_0x0f61f0(a0, a1);
        case 2196: return fde_func_2196_0x0f6308(a0, a1);
        case 2197: return fde_func_2197_0x0f6334(a0, a1);
        case 2198: return fde_func_2198_0x0f651c(a0, a1);
        case 2199: return fde_func_2199_0x0f66a0(a0, a1);
        case 2200: return fde_func_2200_0x0f67d0(a0, a1);
        case 2201: return fde_func_2201_0x0f68f8(a0, a1);
        case 2202: return fde_func_2202_0x0f6b58(a0, a1);
        case 2203: return fde_func_2203_0x0f6c90(a0, a1);
        case 2204: return fde_func_2204_0x0f6da8(a0, a1);
        case 2205: return fde_func_2205_0x0f704c(a0, a1);
        case 2206: return fde_func_2206_0x0f7154(a0, a1);
        case 2207: return fde_func_2207_0x0f7304(a0, a1);
        case 2208: return fde_func_2208_0x0f7a30(a0, a1);
        case 2209: return fde_func_2209_0x0f7fb0(a0, a1);
        case 2210: return fde_func_2210_0x0f8174(a0, a1);
        case 2211: return fde_func_2211_0x0f81a0(a0, a1);
        case 2212: return fde_func_2212_0x0f84a8(a0, a1);
        case 2213: return fde_func_2213_0x0f85e4(a0, a1);
        case 2214: return fde_func_2214_0x0f8620(a0, a1);
        case 2215: return fde_func_2215_0x0f8718(a0, a1);
        case 2216: return fde_func_2216_0x0f8754(a0, a1);
        case 2217: return fde_func_2217_0x0f892c(a0, a1);
        case 2218: return fde_func_2218_0x0f894c(a0, a1);
        case 2219: return fde_func_2219_0x0f896c(a0, a1);
        case 2220: return fde_func_2220_0x0f89f8(a0, a1);
        case 2221: return fde_func_2221_0x0f8a70(a0, a1);
        case 2222: return fde_func_2222_0x0f8bc4(a0, a1);
        case 2223: return fde_func_2223_0x0f8d2c(a0, a1);
        case 2224: return fde_func_2224_0x0f8dbc(a0, a1);
        case 2225: return fde_func_2225_0x0f9de4(a0, a1);
        case 2226: return fde_func_2226_0x0f9e74(a0, a1);
        case 2227: return fde_func_2227_0x0f9ebc(a0, a1);
        case 2228: return fde_func_2228_0x0f9f38(a0, a1);
        case 2229: return fde_func_2229_0x0f9f90(a0, a1);
        case 2230: return fde_func_2230_0x0f9fe8(a0, a1);
        case 2231: return fde_func_2231_0x0fb040(a0, a1);
        case 2232: return fde_func_2232_0x0fb0a4(a0, a1);
        case 2233: return fde_func_2233_0x0fb0fc(a0, a1);
        case 2234: return fde_func_2234_0x0fb160(a0, a1);
        case 2235: return fde_func_2235_0x0fb1b8(a0, a1);
        case 2236: return fde_func_2236_0x0fb210(a0, a1);
        case 2237: return fde_func_2237_0x0fb268(a0, a1);
        case 2238: return fde_func_2238_0x0fb2c0(a0, a1);
        case 2239: return fde_func_2239_0x0fb318(a0, a1);
        case 2240: return fde_func_2240_0x0fb394(a0, a1);
        case 2241: return fde_func_2241_0x0fb410(a0, a1);
        case 2242: return fde_func_2242_0x0fb530(a0, a1);
        case 2243: return fde_func_2243_0x0fb650(a0, a1);
        case 2244: return fde_func_2244_0x0fb770(a0, a1);
        case 2245: return fde_func_2245_0x0fb904(a0, a1);
        case 2246: return fde_func_2246_0x0fb95c(a0, a1);
        case 2247: return fde_func_2247_0x0fb9b4(a0, a1);
        case 2248: return fde_func_2248_0x0fba0c(a0, a1);
        case 2249: return fde_func_2249_0x0fbb20(a0, a1);
        case 2250: return fde_func_2250_0x0fbf1c(a0, a1);
        case 2251: return fde_func_2251_0x0fbf88(a0, a1);
        case 2252: return fde_func_2252_0x0fc238(a0, a1);
        case 2253: return fde_func_2253_0x0fc28c(a0, a1);
        case 2254: return fde_func_2254_0x0fc2e8(a0, a1);
        case 2255: return fde_func_2255_0x0fc340(a0, a1);
        case 2256: return fde_func_2256_0x0fc428(a0, a1);
        case 2257: return fde_func_2257_0x0fc52c(a0, a1);
        case 2258: return fde_func_2258_0x0fc628(a0, a1);
        case 2259: return fde_func_2259_0x0fc748(a0, a1);
        case 2260: return fde_func_2260_0x0fc788(a0, a1);
        case 2261: return fde_func_2261_0x0fc7a4(a0, a1);
        case 2262: return fde_func_2262_0x0fc808(a0, a1);
        case 2263: return fde_func_2263_0x0fc8a8(a0, a1);
        case 2264: return fde_func_2264_0x0fca20(a0, a1);
        case 2265: return fde_func_2265_0x0fcab8(a0, a1);
        case 2266: return fde_func_2266_0x0fcb24(a0, a1);
        case 2267: return fde_func_2267_0x0fcb58(a0, a1);
        case 2268: return fde_func_2268_0x0fcbec(a0, a1);
        case 2269: return fde_func_2269_0x0fcd84(a0, a1);
        case 2270: return fde_func_2270_0x0fce10(a0, a1);
        case 2271: return fde_func_2271_0x0fe040(a0, a1);
        case 2272: return fde_func_2272_0x0fe0f0(a0, a1);
        case 2273: return fde_func_2273_0x0fe120(a0, a1);
        case 2274: return fde_func_2274_0x0fe1d8(a0, a1);
        case 2275: return fde_func_2275_0x0fe2ec(a0, a1);
        case 2276: return fde_func_2276_0x0fe374(a0, a1);
        case 2277: return fde_func_2277_0x0fe418(a0, a1);
        case 2278: return fde_func_2278_0x0fe4a0(a0, a1);
        case 2279: return fde_func_2279_0x0fe55c(a0, a1);
        case 2280: return fde_func_2280_0x0fe6d4(a0, a1);
        case 2281: return fde_func_2281_0x0fe8d0(a0, a1);
        case 2282: return fde_func_2282_0x0feb0c(a0, a1);
        case 2283: return fde_func_2283_0x0feba4(a0, a1);
        case 2284: return fde_func_2284_0x0feedc(a0, a1);
        case 2285: return fde_func_2285_0x0fefbc(a0, a1);
        case 2286: return fde_func_2286_0x0ff0d0(a0, a1);
        case 2287: return fde_func_2287_0x0ff1e4(a0, a1);
        case 2288: return fde_func_2288_0x0ff2f8(a0, a1);
        case 2289: return fde_func_2289_0x0ff40c(a0, a1);
        case 2290: return fde_func_2290_0x0ff520(a0, a1);
        case 2291: return fde_func_2291_0x0ff698(a0, a1);
        case 2292: return fde_func_2292_0x0ff750(a0, a1);
        case 2293: return fde_func_2293_0x0ff808(a0, a1);
        case 2294: return fde_func_2294_0x0ff8c0(a0, a1);
        case 2295: return fde_func_2295_0x0ff948(a0, a1);
        case 2296: return fde_func_2296_0x0ffa00(a0, a1);
        case 2297: return fde_func_2297_0x0ffb14(a0, a1);
        case 2298: return fde_func_2298_0x0ffc28(a0, a1);
        case 2299: return fde_func_2299_0x0ffd3c(a0, a1);
        case 2300: return fde_func_2300_0x0ffe50(a0, a1);
        case 2301: return fde_func_2301_0x0fff64(a0, a1);
        case 2302: return fde_func_2302_0x10001c(a0, a1);
        case 2303: return fde_func_2303_0x1000d4(a0, a1);
        case 2304: return fde_func_2304_0x1001e8(a0, a1);
        case 2305: return fde_func_2305_0x1002fc(a0, a1);
        case 2306: return fde_func_2306_0x100410(a0, a1);
        case 2307: return fde_func_2307_0x100524(a0, a1);
        case 2308: return fde_func_2308_0x10069c(a0, a1);
        case 2309: return fde_func_2309_0x1007b0(a0, a1);
        case 2310: return fde_func_2310_0x1008c4(a0, a1);
        case 2311: return fde_func_2311_0x1009d8(a0, a1);
        case 2312: return fde_func_2312_0x100aec(a0, a1);
        case 2313: return fde_func_2313_0x100c00(a0, a1);
        case 2314: return fde_func_2314_0x100d14(a0, a1);
        case 2315: return fde_func_2315_0x100e28(a0, a1);
        case 2316: return fde_func_2316_0x100f3c(a0, a1);
        case 2317: return fde_func_2317_0x101050(a0, a1);
        case 2318: return fde_func_2318_0x101108(a0, a1);
        case 2319: return fde_func_2319_0x10121c(a0, a1);
        case 2320: return fde_func_2320_0x101330(a0, a1);
        case 2321: return fde_func_2321_0x1013b8(a0, a1);
        case 2322: return fde_func_2322_0x101440(a0, a1);
        case 2323: return fde_func_2323_0x101554(a0, a1);
        case 2324: return fde_func_2324_0x1015e8(a0, a1);
        case 2325: return fde_func_2325_0x1016f4(a0, a1);
        case 2326: return fde_func_2326_0x101800(a0, a1);
        case 2327: return fde_func_2327_0x101b88(a0, a1);
        case 2328: return fde_func_2328_0x101ca4(a0, a1);
        case 2329: return fde_func_2329_0x101dcc(a0, a1);
        case 2330: return fde_func_2330_0x101e6c(a0, a1);
        case 2331: return fde_func_2331_0x101f00(a0, a1);
        case 2332: return fde_func_2332_0x101f58(a0, a1);
        case 2333: return fde_func_2333_0x102d10(a0, a1);
        case 2334: return fde_func_2334_0x102e5c(a0, a1);
        case 2335: return fde_func_2335_0x102ffc(a0, a1);
        case 2336: return fde_func_2336_0x10316c(a0, a1);
        case 2337: return fde_func_2337_0x103268(a0, a1);
        case 2338: return fde_func_2338_0x103384(a0, a1);
        case 2339: return fde_func_2339_0x103390(a0, a1);
        case 2340: return fde_func_2340_0x103428(a0, a1);
        case 2341: return fde_func_2341_0x103738(a0, a1);
        case 2342: return fde_func_2342_0x10382c(a0, a1);
        case 2343: return fde_func_2343_0x10397c(a0, a1);
        case 2344: return fde_func_2344_0x103a70(a0, a1);
        case 2345: return fde_func_2345_0x103c9c(a0, a1);
        case 2346: return fde_func_2346_0x103fd0(a0, a1);
        case 2347: return fde_func_2347_0x10403c(a0, a1);
        case 2348: return fde_func_2348_0x1040dc(a0, a1);
        case 2349: return fde_func_2349_0x104174(a0, a1);
        case 2350: return fde_func_2350_0x10420c(a0, a1);
        case 2351: return fde_func_2351_0x1042a4(a0, a1);
        case 2352: return fde_func_2352_0x10435c(a0, a1);
        case 2353: return fde_func_2353_0x104430(a0, a1);
        case 2354: return fde_func_2354_0x1044a0(a0, a1);
        case 2355: return fde_func_2355_0x1044f8(a0, a1);
        case 2356: return fde_func_2356_0x1046ac(a0, a1);
        case 2357: return fde_func_2357_0x1047a0(a0, a1);
        case 2358: return fde_func_2358_0x104870(a0, a1);
        case 2359: return fde_func_2359_0x1048e0(a0, a1);
        case 2360: return fde_func_2360_0x104938(a0, a1);
        case 2361: return fde_func_2361_0x104ad0(a0, a1);
        case 2362: return fde_func_2362_0x104bd8(a0, a1);
        case 2363: return fde_func_2363_0x104ce4(a0, a1);
        case 2364: return fde_func_2364_0x104d54(a0, a1);
        case 2365: return fde_func_2365_0x104dac(a0, a1);
        case 2366: return fde_func_2366_0x10500c(a0, a1);
        case 2367: return fde_func_2367_0x1051f8(a0, a1);
        case 2368: return fde_func_2368_0x105208(a0, a1);
        case 2369: return fde_func_2369_0x1052ec(a0, a1);
        case 2370: return fde_func_2370_0x105304(a0, a1);
        case 2371: return fde_func_2371_0x105730(a0, a1);
        case 2372: return fde_func_2372_0x105744(a0, a1);
        case 2373: return fde_func_2373_0x1057e0(a0, a1);
        case 2374: return fde_func_2374_0x105808(a0, a1);
        case 2375: return fde_func_2375_0x105850(a0, a1);
        case 2376: return fde_func_2376_0x105f30(a0, a1);
        case 2377: return fde_func_2377_0x105fd4(a0, a1);
        case 2378: return fde_func_2378_0x105fdc(a0, a1);
        case 2379: return fde_func_2379_0x1060ec(a0, a1);
        case 2380: return fde_func_2380_0x1061fc(a0, a1);
        case 2381: return fde_func_2381_0x106204(a0, a1);
        case 2382: return fde_func_2382_0x106210(a0, a1);
        case 2383: return fde_func_2383_0x106324(a0, a1);
        case 2384: return fde_func_2384_0x106340(a0, a1);
        case 2385: return fde_func_2385_0x106388(a0, a1);
        case 2386: return fde_func_2386_0x1066cc(a0, a1);
        case 2387: return fde_func_2387_0x106744(a0, a1);
        case 2388: return fde_func_2388_0x1067b8(a0, a1);
        case 2389: return fde_func_2389_0x106810(a0, a1);
        case 2390: return fde_func_2390_0x106ad8(a0, a1);
        case 2391: return fde_func_2391_0x106d74(a0, a1);
        case 2392: return fde_func_2392_0x106e3c(a0, a1);
        case 2393: return fde_func_2393_0x106f28(a0, a1);
        case 2394: return fde_func_2394_0x106f4c(a0, a1);
        case 2395: return fde_func_2395_0x10703c(a0, a1);
        case 2396: return fde_func_2396_0x107068(a0, a1);
        case 2397: return fde_func_2397_0x107074(a0, a1);
        case 2398: return fde_func_2398_0x1070d8(a0, a1);
        case 2399: return fde_func_2399_0x1077b4(a0, a1);
        case 2400: return fde_func_2400_0x107818(a0, a1);
        case 2401: return fde_func_2401_0x10787c(a0, a1);
        case 2402: return fde_func_2402_0x107920(a0, a1);
        case 2403: return fde_func_2403_0x107928(a0, a1);
        case 2404: return fde_func_2404_0x107950(a0, a1);
        case 2405: return fde_func_2405_0x107974(a0, a1);
        case 2406: return fde_func_2406_0x107988(a0, a1);
        case 2407: return fde_func_2407_0x107998(a0, a1);
        case 2408: return fde_func_2408_0x107a90(a0, a1);
        case 2409: return fde_func_2409_0x107b68(a0, a1);
        case 2410: return fde_func_2410_0x107b74(a0, a1);
        case 2411: return fde_func_2411_0x107ce4(a0, a1);
        case 2412: return fde_func_2412_0x107da4(a0, a1);
        case 2413: return fde_func_2413_0x108000(a0, a1);
        case 2414: return fde_func_2414_0x108008(a0, a1);
        case 2415: return fde_func_2415_0x108218(a0, a1);
        case 2416: return fde_func_2416_0x108288(a0, a1);
        case 2417: return fde_func_2417_0x108404(a0, a1);
        case 2418: return fde_func_2418_0x108930(a0, a1);
        case 2419: return fde_func_2419_0x1089f0(a0, a1);
        case 2420: return fde_func_2420_0x108e10(a0, a1);
        case 2421: return fde_func_2421_0x108ea0(a0, a1);
        case 2422: return fde_func_2422_0x109018(a0, a1);
        case 2423: return fde_func_2423_0x1090a4(a0, a1);
        case 2424: return fde_func_2424_0x1093e8(a0, a1);
        case 2425: return fde_func_2425_0x109428(a0, a1);
        case 2426: return fde_func_2426_0x109434(a0, a1);
        case 2427: return fde_func_2427_0x109508(a0, a1);
        case 2428: return fde_func_2428_0x109514(a0, a1);
        case 2429: return fde_func_2429_0x109564(a0, a1);
        case 2430: return fde_func_2430_0x1095b4(a0, a1);
        case 2431: return fde_func_2431_0x109614(a0, a1);
        case 2432: return fde_func_2432_0x109674(a0, a1);
        case 2433: return fde_func_2433_0x10967c(a0, a1);
        case 2434: return fde_func_2434_0x1097a4(a0, a1);
        case 2435: return fde_func_2435_0x1097ac(a0, a1);
        case 2436: return fde_func_2436_0x109830(a0, a1);
        case 2437: return fde_func_2437_0x1099b8(a0, a1);
        case 2438: return fde_func_2438_0x109a3c(a0, a1);
        case 2439: return fde_func_2439_0x109bf8(a0, a1);
        case 2440: return fde_func_2440_0x109d18(a0, a1);
        case 2441: return fde_func_2441_0x109da8(a0, a1);
        case 2442: return fde_func_2442_0x109e38(a0, a1);
        case 2443: return fde_func_2443_0x109ed0(a0, a1);
        case 2444: return fde_func_2444_0x109f70(a0, a1);
        case 2445: return fde_func_2445_0x109fb4(a0, a1);
        case 2446: return fde_func_2446_0x10a0dc(a0, a1);
        case 2447: return fde_func_2447_0x10a33c(a0, a1);
        case 2448: return fde_func_2448_0x10a6fc(a0, a1);
        case 2449: return fde_func_2449_0x10abb4(a0, a1);
        case 2450: return fde_func_2450_0x10affc(a0, a1);
        case 2451: return fde_func_2451_0x10b03c(a0, a1);
        case 2452: return fde_func_2452_0x10b044(a0, a1);
        case 2453: return fde_func_2453_0x10b04c(a0, a1);
        case 2454: return fde_func_2454_0x10b054(a0, a1);
        case 2455: return fde_func_2455_0x10b05c(a0, a1);
        case 2456: return fde_func_2456_0x10b064(a0, a1);
        case 2457: return fde_func_2457_0x10b5a0(a0, a1);
        case 2458: return fde_func_2458_0x10b910(a0, a1);
        case 2459: return fde_func_2459_0x10be0c(a0, a1);
        case 2460: return fde_func_2460_0x10bef0(a0, a1);
        case 2461: return fde_func_2461_0x10bf2c(a0, a1);
        case 2462: return fde_func_2462_0x10bf5c(a0, a1);
        case 2463: return fde_func_2463_0x10c24c(a0, a1);
        default: return 0ULL;
    }
}