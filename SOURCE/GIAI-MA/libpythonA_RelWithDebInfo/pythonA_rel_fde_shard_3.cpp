// ============================================================================
// Clean-Room C++17 AArch64 Complementary FDE Shard 3/5 for libpythonA_RelWithDebInfo.so
// Phân mảnh Khung Tháo Gỡ (FDE) Bổ Sung AArch64 C++17 sạch 3/5 cho libpythonA_RelWithDebInfo.so
// Covers FDE indices [2928 .. 3391] out of 4,320 total FDEs
// Bao phủ chỉ số FDE [2928 .. 3391] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_rel_core.h"

// FDE #2928 | PC: 0x132cd4 | FDE: 0x1e9aa0 | Size: 120 bytes [PyRun_SimpleFileExFlags]
// Khung tháo gỡ #2928 | Địa chỉ PC: 0x132cd4 | Địa chỉ FDE: 0x1e9aa0 | Kích thước: 120 bytes
//   0x132cd4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x132cd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132cdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132ce0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2928_0x132cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132cd4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9aa0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2929 | PC: 0x132d4c | FDE: 0x1e9ac8 | Size: 256 bytes [_Py_HandleSystemExit]
// Khung tháo gỡ #2929 | Địa chỉ PC: 0x132d4c | Địa chỉ FDE: 0x1e9ac8 | Kích thước: 256 bytes
//   0x132d4c: D10183FF  sub      sp, sp, #0x60
//   0x132d50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x132d54: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x132d58: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2929_0x132d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132d4cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e9ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2930 | PC: 0x132eec | FDE: 0x1e9af0 | Size: 8 bytes [_PyErr_Print]
// Khung tháo gỡ #2930 | Địa chỉ PC: 0x132eec | Địa chỉ FDE: 0x1e9af0 | Kích thước: 8 bytes
//   0x132eec: 52800021  mov      w1, #1
//   0x132ef0: 14000001  b        #0x132ef4
static inline uint64_t fde_func_2930_0x132eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132eecULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e9af0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2931 | PC: 0x132ef4 | FDE: 0x1e9b08 | Size: 256 bytes
// Khung tháo gỡ #2931 | Địa chỉ PC: 0x132ef4 | Địa chỉ FDE: 0x1e9b08 | Kích thước: 256 bytes
//   0x132ef4: D10243FF  sub      sp, sp, #0x90
//   0x132ef8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x132efc: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x132f00: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_2931_0x132ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132ef4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x1e9b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2932 | PC: 0x1333c4 | FDE: 0x1e9b30 | Size: 36 bytes [PyErr_PrintEx]
// Khung tháo gỡ #2932 | Địa chỉ PC: 0x1333c4 | Địa chỉ FDE: 0x1e9b30 | Kích thước: 36 bytes
//   0x1333c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1333c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1333cc: 910043FD  add      x29, sp, #0x10
//   0x1333d0: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_2932_0x1333c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1333c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9b30ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2933 | PC: 0x1333e8 | FDE: 0x1e9b50 | Size: 256 bytes [_PyErr_Display]
// Khung tháo gỡ #2933 | Địa chỉ PC: 0x1333e8 | Địa chỉ FDE: 0x1e9b50 | Kích thước: 256 bytes
//   0x1333e8: D10103FF  sub      sp, sp, #0x40
//   0x1333ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1333f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1333f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2933_0x1333e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1333e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2934 | PC: 0x133528 | FDE: 0x1e9b78 | Size: 256 bytes
// Khung tháo gỡ #2934 | Địa chỉ PC: 0x133528 | Địa chỉ FDE: 0x1e9b78 | Kích thước: 256 bytes
//   0x133528: D10283FF  sub      sp, sp, #0xa0
//   0x13352c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x133530: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x133534: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_2934_0x133528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133528ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e9b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2935 | PC: 0x134050 | FDE: 0x1e9ba8 | Size: 192 bytes [PyErr_Display]
// Khung tháo gỡ #2935 | Địa chỉ PC: 0x134050 | Địa chỉ FDE: 0x1e9ba8 | Kích thước: 192 bytes
//   0x134050: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x134054: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134058: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13405c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2935_0x134050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134050ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9ba8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2936 | PC: 0x134110 | FDE: 0x1e9bc8 | Size: 256 bytes [_Py_SourceAsString]
// Khung tháo gỡ #2936 | Địa chỉ PC: 0x134110 | Địa chỉ FDE: 0x1e9bc8 | Kích thước: 256 bytes
//   0x134110: D10283FF  sub      sp, sp, #0xa0
//   0x134114: F90033F7  str      x23, [sp, #0x60]
//   0x134118: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x13411c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_2936_0x134110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134110ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1e9bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2937 | PC: 0x1342b0 | FDE: 0x1e9bf0 | Size: 24 bytes [_PyTime_MulDiv]
// Khung tháo gỡ #2937 | Địa chỉ PC: 0x1342b0 | Địa chỉ FDE: 0x1e9bf0 | Kích thước: 24 bytes
//   0x1342b0: 9AC20C08  sdiv     x8, x0, x2
//   0x1342b4: 9B028109  msub     x9, x8, x2, x0
//   0x1342b8: 9B017D29  mul      x9, x9, x1
//   0x1342bc: 9AC20D29  sdiv     x9, x9, x2
static inline uint64_t fde_func_2937_0x1342b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1342b0ULL ^ (static_cast<uint64_t>(0x9ac20c08ULL) << 13);
    acc = (acc + a1 + 0x9b028109ULL) ^ 0x1e9bf0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2938 | PC: 0x1342c8 | FDE: 0x1e9c08 | Size: 88 bytes [_PyLong_AsTime_t]
// Khung tháo gỡ #2938 | Địa chỉ PC: 0x1342c8 | Địa chỉ FDE: 0x1e9c08 | Kích thước: 88 bytes
//   0x1342c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1342cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1342d0: 910043FD  add      x29, sp, #0x10
//   0x1342d4: 97FCA1BB  bl       #0x5c9c0
static inline uint64_t fde_func_2938_0x1342c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1342c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9c08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2939 | PC: 0x134320 | FDE: 0x1e9c28 | Size: 4 bytes [_PyLong_FromTime_t]
// Khung tháo gỡ #2939 | Địa chỉ PC: 0x134320 | Địa chỉ FDE: 0x1e9c28 | Kích thước: 4 bytes
//   0x134320: 17FCA300  b        #0x5cf20
static inline uint64_t fde_func_2939_0x134320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134320ULL ^ (static_cast<uint64_t>(0x17fca300ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x1e9c28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2940 | PC: 0x134324 | FDE: 0x1e9c40 | Size: 256 bytes [_PyTime_ObjectToTime_t]
// Khung tháo gỡ #2940 | Địa chỉ PC: 0x134324 | Địa chỉ FDE: 0x1e9c40 | Kích thước: 256 bytes
//   0x134324: D10143FF  sub      sp, sp, #0x50
//   0x134328: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13432c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x134330: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2940_0x134324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134324ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e9c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2941 | PC: 0x1344fc | FDE: 0x1e9c68 | Size: 16 bytes [_PyTime_ObjectToTimespec]
// Khung tháo gỡ #2941 | Địa chỉ PC: 0x1344fc | Địa chỉ FDE: 0x1e9c68 | Kích thước: 16 bytes
//   0x1344fc: 2A0303E4  mov      w4, w3
//   0x134500: 52994003  mov      w3, #0xca00
//   0x134504: 72A77343  movk     w3, #0x3b9a, lsl #16
//   0x134508: 14000001  b        #0x13450c
static inline uint64_t fde_func_2941_0x1344fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1344fcULL ^ (static_cast<uint64_t>(0x2a0303e4ULL) << 13);
    acc = (acc + a1 + 0x52994003ULL) ^ 0x1e9c68ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2942 | PC: 0x13450c | FDE: 0x1e9c80 | Size: 256 bytes
// Khung tháo gỡ #2942 | Địa chỉ PC: 0x13450c | Địa chỉ FDE: 0x1e9c80 | Kích thước: 256 bytes
//   0x13450c: D101C3FF  sub      sp, sp, #0x70
//   0x134510: FD0013E8  str      d8, [sp, #0x20]
//   0x134514: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x134518: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2942_0x13450c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13450cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x1e9c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2943 | PC: 0x134770 | FDE: 0x1e9ca8 | Size: 16 bytes [_PyTime_ObjectToTimeval]
// Khung tháo gỡ #2943 | Địa chỉ PC: 0x134770 | Địa chỉ FDE: 0x1e9ca8 | Kích thước: 16 bytes
//   0x134770: 2A0303E4  mov      w4, w3
//   0x134774: 52884803  mov      w3, #0x4240
//   0x134778: 72A001E3  movk     w3, #0xf, lsl #16
//   0x13477c: 17FFFF64  b        #0x13450c
static inline uint64_t fde_func_2943_0x134770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134770ULL ^ (static_cast<uint64_t>(0x2a0303e4ULL) << 13);
    acc = (acc + a1 + 0x52884803ULL) ^ 0x1e9ca8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2944 | PC: 0x134780 | FDE: 0x1e9cc0 | Size: 16 bytes [_PyTime_FromSeconds]
// Khung tháo gỡ #2944 | Địa chỉ PC: 0x134780 | Địa chỉ FDE: 0x1e9cc0 | Kích thước: 16 bytes
//   0x134780: 52994008  mov      w8, #0xca00
//   0x134784: 72A77348  movk     w8, #0x3b9a, lsl #16
//   0x134788: 9B287C00  smull    x0, w0, w8
//   0x13478c: D65F03C0  ret      
static inline uint64_t fde_func_2944_0x134780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134780ULL ^ (static_cast<uint64_t>(0x52994008ULL) << 13);
    acc = (acc + a1 + 0x72a77348ULL) ^ 0x1e9cc0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2945 | PC: 0x134790 | FDE: 0x1e9cd8 | Size: 4 bytes [_PyTime_FromNanoseconds]
// Khung tháo gỡ #2945 | Địa chỉ PC: 0x134790 | Địa chỉ FDE: 0x1e9cd8 | Kích thước: 4 bytes
//   0x134790: D65F03C0  ret      
static inline uint64_t fde_func_2945_0x134790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134790ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1e9cd8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2946 | PC: 0x134794 | FDE: 0x1e9cf0 | Size: 156 bytes [_PyTime_FromNanosecondsObject]
// Khung tháo gỡ #2946 | Địa chỉ PC: 0x134794 | Địa chỉ FDE: 0x1e9cf0 | Kích thước: 156 bytes
//   0x134794: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x134798: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13479c: 910043FD  add      x29, sp, #0x10
//   0x1347a0: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2946_0x134794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134794ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9cf0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2947 | PC: 0x134830 | FDE: 0x1e9d10 | Size: 196 bytes [_PyTime_FromTimespec]
// Khung tháo gỡ #2947 | Địa chỉ PC: 0x134830 | Địa chỉ FDE: 0x1e9d10 | Kích thước: 196 bytes
//   0x134830: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x134834: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134838: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13483c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2947_0x134830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134830ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9d10ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2948 | PC: 0x1348f4 | FDE: 0x1e9d38 | Size: 204 bytes [_PyTime_FromTimeval]
// Khung tháo gỡ #2948 | Địa chỉ PC: 0x1348f4 | Địa chỉ FDE: 0x1e9d38 | Kích thước: 204 bytes
//   0x1348f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1348f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1348fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x134900: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2948_0x1348f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1348f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9d38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2949 | PC: 0x1349c0 | FDE: 0x1e9d60 | Size: 12 bytes [_PyTime_FromSecondsObject]
// Khung tháo gỡ #2949 | Địa chỉ PC: 0x1349c0 | Địa chỉ FDE: 0x1e9d60 | Kích thước: 12 bytes
//   0x1349c0: 52994003  mov      w3, #0xca00
//   0x1349c4: 72A77343  movk     w3, #0x3b9a, lsl #16
//   0x1349c8: 14000001  b        #0x1349cc
static inline uint64_t fde_func_2949_0x1349c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1349c0ULL ^ (static_cast<uint64_t>(0x52994003ULL) << 13);
    acc = (acc + a1 + 0x72a77343ULL) ^ 0x1e9d60ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2950 | PC: 0x1349cc | FDE: 0x1e9d78 | Size: 256 bytes
// Khung tháo gỡ #2950 | Địa chỉ PC: 0x1349cc | Địa chỉ FDE: 0x1e9d78 | Kích thước: 256 bytes
//   0x1349cc: D10183FF  sub      sp, sp, #0x60
//   0x1349d0: F90013F7  str      x23, [sp, #0x20]
//   0x1349d4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1349d8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2950_0x1349cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1349ccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e9d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2951 | PC: 0x134bc8 | FDE: 0x1e9da0 | Size: 12 bytes [_PyTime_FromMillisecondsObject]
// Khung tháo gỡ #2951 | Địa chỉ PC: 0x134bc8 | Địa chỉ FDE: 0x1e9da0 | Kích thước: 12 bytes
//   0x134bc8: 52884803  mov      w3, #0x4240
//   0x134bcc: 72A001E3  movk     w3, #0xf, lsl #16
//   0x134bd0: 17FFFF7F  b        #0x1349cc
static inline uint64_t fde_func_2951_0x134bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134bc8ULL ^ (static_cast<uint64_t>(0x52884803ULL) << 13);
    acc = (acc + a1 + 0x72a001e3ULL) ^ 0x1e9da0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2952 | PC: 0x134bd4 | FDE: 0x1e9db8 | Size: 144 bytes [_PyTime_AsSecondsDouble]
// Khung tháo gỡ #2952 | Địa chỉ PC: 0x134bd4 | Địa chỉ FDE: 0x1e9db8 | Kích thước: 144 bytes
//   0x134bd4: D10083FF  sub      sp, sp, #0x20
//   0x134bd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x134bdc: 910043FD  add      x29, sp, #0x10
//   0x134be0: D2929669  mov      x9, #0x94b3
static inline uint64_t fde_func_2952_0x134bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134bd4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9db8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2953 | PC: 0x134c64 | FDE: 0x1e9dd8 | Size: 4 bytes [_PyTime_AsNanosecondsObject]
// Khung tháo gỡ #2953 | Địa chỉ PC: 0x134c64 | Địa chỉ FDE: 0x1e9dd8 | Kích thước: 4 bytes
//   0x134c64: 17FCA0AF  b        #0x5cf20
static inline uint64_t fde_func_2953_0x134c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134c64ULL ^ (static_cast<uint64_t>(0x17fca0afULL) << 13);
    acc = (acc + a1 + 0x7100043fULL) ^ 0x1e9dd8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2954 | PC: 0x134c68 | FDE: 0x1e9df0 | Size: 196 bytes [_PyTime_AsMilliseconds]
// Khung tháo gỡ #2954 | Địa chỉ PC: 0x134c68 | Địa chỉ FDE: 0x1e9df0 | Kích thước: 196 bytes
//   0x134c68: 7100043F  cmp      w1, #1
//   0x134c6c: AA0003E8  mov      x8, x0
//   0x134c70: 54000340  b.eq     #0x134cd8
//   0x134c74: 7100083F  cmp      w1, #2
static inline uint64_t fde_func_2954_0x134c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134c68ULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1e9df0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2955 | PC: 0x134d2c | FDE: 0x1e9e08 | Size: 204 bytes [_PyTime_AsMicroseconds]
// Khung tháo gỡ #2955 | Địa chỉ PC: 0x134d2c | Địa chỉ FDE: 0x1e9e08 | Kích thước: 204 bytes
//   0x134d2c: 7100043F  cmp      w1, #1
//   0x134d30: AA0003E8  mov      x8, x0
//   0x134d34: 540002E0  b.eq     #0x134d90
//   0x134d38: 7100083F  cmp      w1, #2
static inline uint64_t fde_func_2955_0x134d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134d2cULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1e9e08ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2956 | PC: 0x134df8 | FDE: 0x1e9e20 | Size: 256 bytes [_PyTime_AsTimeval]
// Khung tháo gỡ #2956 | Địa chỉ PC: 0x134df8 | Địa chỉ FDE: 0x1e9e20 | Kích thước: 256 bytes
//   0x134df8: D2929668  mov      x8, #0x94b3
//   0x134dfc: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x134e00: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x134e04: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_2956_0x134df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134df8ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2957 | PC: 0x134f34 | FDE: 0x1e9e38 | Size: 256 bytes [_PyTime_AsTimeval_noraise]
// Khung tháo gỡ #2957 | Địa chỉ PC: 0x134f34 | Địa chỉ FDE: 0x1e9e38 | Kích thước: 256 bytes
//   0x134f34: D2929668  mov      x8, #0x94b3
//   0x134f38: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x134f3c: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x134f40: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_2957_0x134f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134f34ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2958 | PC: 0x135070 | FDE: 0x1e9e50 | Size: 256 bytes [_PyTime_AsTimevalTime_t]
// Khung tháo gỡ #2958 | Địa chỉ PC: 0x135070 | Địa chỉ FDE: 0x1e9e50 | Kích thước: 256 bytes
//   0x135070: D2929668  mov      x8, #0x94b3
//   0x135074: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x135078: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x13507c: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_2958_0x135070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135070ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2959 | PC: 0x1351a0 | FDE: 0x1e9e68 | Size: 68 bytes [_PyTime_AsTimespec]
// Khung tháo gỡ #2959 | Địa chỉ PC: 0x1351a0 | Địa chỉ FDE: 0x1e9e68 | Kích thước: 68 bytes
//   0x1351a0: D2929668  mov      x8, #0x94b3
//   0x1351a4: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x1351a8: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x1351ac: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_2959_0x1351a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1351a0ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e68ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2960 | PC: 0x1351e4 | FDE: 0x1e9e80 | Size: 168 bytes [_PyTime_GetSystemClock]
// Khung tháo gỡ #2960 | Địa chỉ PC: 0x1351e4 | Địa chỉ FDE: 0x1e9e80 | Kích thước: 168 bytes
//   0x1351e4: D10103FF  sub      sp, sp, #0x40
//   0x1351e8: F90013F3  str      x19, [sp, #0x20]
//   0x1351ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1351f0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2960_0x1351e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1351e4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e9e80ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2961 | PC: 0x13528c | FDE: 0x1e9ea0 | Size: 256 bytes [_PyTime_GetSystemClockWithInfo]
// Khung tháo gỡ #2961 | Địa chỉ PC: 0x13528c | Địa chỉ FDE: 0x1e9ea0 | Kích thước: 256 bytes
//   0x13528c: D101C3FF  sub      sp, sp, #0x70
//   0x135290: F9001BF7  str      x23, [sp, #0x30]
//   0x135294: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x135298: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2961_0x13528c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13528cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e9ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2962 | PC: 0x135414 | FDE: 0x1e9ec8 | Size: 168 bytes [_PyTime_GetMonotonicClock]
// Khung tháo gỡ #2962 | Địa chỉ PC: 0x135414 | Địa chỉ FDE: 0x1e9ec8 | Kích thước: 168 bytes
//   0x135414: D10103FF  sub      sp, sp, #0x40
//   0x135418: F90013F3  str      x19, [sp, #0x20]
//   0x13541c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x135420: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2962_0x135414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135414ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e9ec8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2963 | PC: 0x1354bc | FDE: 0x1e9ee8 | Size: 256 bytes
// Khung tháo gỡ #2963 | Địa chỉ PC: 0x1354bc | Địa chỉ FDE: 0x1e9ee8 | Kích thước: 256 bytes
//   0x1354bc: D101C3FF  sub      sp, sp, #0x70
//   0x1354c0: F9001BF7  str      x23, [sp, #0x30]
//   0x1354c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1354c8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2963_0x1354bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1354bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e9ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2964 | PC: 0x135648 | FDE: 0x1e9f10 | Size: 8 bytes [_PyTime_GetMonotonicClockWithInfo]
// Khung tháo gỡ #2964 | Địa chỉ PC: 0x135648 | Địa chỉ FDE: 0x1e9f10 | Kích thước: 8 bytes
//   0x135648: 52800022  mov      w2, #1
//   0x13564c: 17FFFF9C  b        #0x1354bc
static inline uint64_t fde_func_2964_0x135648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135648ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x17ffff9cULL) ^ 0x1e9f10ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2965 | PC: 0x135650 | FDE: 0x1e9f28 | Size: 8 bytes [_PyTime_GetPerfCounterWithInfo]
// Khung tháo gỡ #2965 | Địa chỉ PC: 0x135650 | Địa chỉ FDE: 0x1e9f28 | Kích thước: 8 bytes
//   0x135650: 52800022  mov      w2, #1
//   0x135654: 17FFFF9A  b        #0x1354bc
static inline uint64_t fde_func_2965_0x135650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135650ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x17ffff9aULL) ^ 0x1e9f28ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2966 | PC: 0x135658 | FDE: 0x1e9f40 | Size: 168 bytes [_PyTime_GetPerfCounter]
// Khung tháo gỡ #2966 | Địa chỉ PC: 0x135658 | Địa chỉ FDE: 0x1e9f40 | Kích thước: 168 bytes
//   0x135658: D10103FF  sub      sp, sp, #0x40
//   0x13565c: F90013F3  str      x19, [sp, #0x20]
//   0x135660: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x135664: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2966_0x135658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135658ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e9f40ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2967 | PC: 0x135700 | FDE: 0x1e9f60 | Size: 152 bytes [_PyTime_localtime]
// Khung tháo gỡ #2967 | Địa chỉ PC: 0x135700 | Địa chỉ FDE: 0x1e9f60 | Kích thước: 152 bytes
//   0x135700: D10103FF  sub      sp, sp, #0x40
//   0x135704: F9000BF5  str      x21, [sp, #0x10]
//   0x135708: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13570c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2967_0x135700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135700ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e9f60ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2968 | PC: 0x135798 | FDE: 0x1e9f80 | Size: 128 bytes [_PyTime_gmtime]
// Khung tháo gỡ #2968 | Địa chỉ PC: 0x135798 | Địa chỉ FDE: 0x1e9f80 | Kích thước: 128 bytes
//   0x135798: D100C3FF  sub      sp, sp, #0x30
//   0x13579c: F9000BF3  str      x19, [sp, #0x10]
//   0x1357a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1357a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2968_0x135798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135798ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1e9f80ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2969 | PC: 0x135818 | FDE: 0x1e9fa0 | Size: 12 bytes [_PyOS_URandom]
// Khung tháo gỡ #2969 | Địa chỉ PC: 0x135818 | Địa chỉ FDE: 0x1e9fa0 | Kích thước: 12 bytes
//   0x135818: 52800022  mov      w2, #1
//   0x13581c: 52800023  mov      w3, #1
//   0x135820: 14000001  b        #0x135824
static inline uint64_t fde_func_2969_0x135818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135818ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x52800023ULL) ^ 0x1e9fa0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2970 | PC: 0x135824 | FDE: 0x1e9fb8 | Size: 256 bytes
// Khung tháo gỡ #2970 | Địa chỉ PC: 0x135824 | Địa chỉ FDE: 0x1e9fb8 | Kích thước: 256 bytes
//   0x135824: D103C3FF  sub      sp, sp, #0xf0
//   0x135828: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x13582c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x135830: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_2970_0x135824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135824ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e9fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2971 | PC: 0x135b98 | FDE: 0x1e9fe8 | Size: 12 bytes [_PyOS_URandomNonblock]
// Khung tháo gỡ #2971 | Địa chỉ PC: 0x135b98 | Địa chỉ FDE: 0x1e9fe8 | Kích thước: 12 bytes
//   0x135b98: 52800023  mov      w3, #1
//   0x135b9c: 2A1F03E2  mov      w2, wzr
//   0x135ba0: 17FFFF21  b        #0x135824
static inline uint64_t fde_func_2971_0x135b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135b98ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x1e9fe8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2972 | PC: 0x135ba4 | FDE: 0x1ea000 | Size: 256 bytes [_Py_HashRandomization_Init]
// Khung tháo gỡ #2972 | Địa chỉ PC: 0x135ba4 | Địa chỉ FDE: 0x1ea000 | Kích thước: 256 bytes
//   0x135ba4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x135ba8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x135bac: 910043FD  add      x29, sp, #0x10
//   0x135bb0: 90000789  adrp     x9, #0x225000
static inline uint64_t fde_func_2972_0x135ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135ba4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2973 | PC: 0x135d84 | FDE: 0x1ea020 | Size: 48 bytes [_Py_HashRandomization_Fini]
// Khung tháo gỡ #2973 | Địa chỉ PC: 0x135d84 | Địa chỉ FDE: 0x1ea020 | Kích thước: 48 bytes
//   0x135d84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x135d88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x135d8c: 910043FD  add      x29, sp, #0x10
//   0x135d90: D0000713  adrp     x19, #0x217000
static inline uint64_t fde_func_2973_0x135d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135d84ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea020ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2974 | PC: 0x135db4 | FDE: 0x1ea040 | Size: 256 bytes [PyMember_GetOne]
// Khung tháo gỡ #2974 | Địa chỉ PC: 0x135db4 | Địa chỉ FDE: 0x1ea040 | Kích thước: 256 bytes
//   0x135db4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x135db8: 910003FD  mov      x29, sp
//   0x135dbc: B9400829  ldr      w9, [x1, #8]
//   0x135dc0: 7100513F  cmp      w9, #0x14
static inline uint64_t fde_func_2974_0x135db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135db4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2975 | PC: 0x135f40 | FDE: 0x1ea060 | Size: 256 bytes [PyMember_SetOne]
// Khung tháo gỡ #2975 | Địa chỉ PC: 0x135f40 | Địa chỉ FDE: 0x1ea060 | Kích thước: 256 bytes
//   0x135f40: D10143FF  sub      sp, sp, #0x50
//   0x135f44: FD000BE8  str      d8, [sp, #0x10]
//   0x135f48: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x135f4c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2975_0x135f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135f40ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1ea060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2976 | PC: 0x1363f4 | FDE: 0x1ea088 | Size: 156 bytes [_PySys_GetObjectId]
// Khung tháo gỡ #2976 | Địa chỉ PC: 0x1363f4 | Địa chỉ FDE: 0x1ea088 | Kích thước: 156 bytes
//   0x1363f4: D10143FF  sub      sp, sp, #0x50
//   0x1363f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1363fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x136400: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2976_0x1363f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1363f4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ea088ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2977 | PC: 0x136490 | FDE: 0x1ea0b0 | Size: 152 bytes [PySys_GetObject]
// Khung tháo gỡ #2977 | Địa chỉ PC: 0x136490 | Địa chỉ FDE: 0x1ea0b0 | Kích thước: 152 bytes
//   0x136490: D10143FF  sub      sp, sp, #0x50
//   0x136494: F90013F5  str      x21, [sp, #0x20]
//   0x136498: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13649c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2977_0x136490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136490ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea0b0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2978 | PC: 0x136528 | FDE: 0x1ea0d0 | Size: 156 bytes [_PySys_SetObjectId]
// Khung tháo gỡ #2978 | Địa chỉ PC: 0x136528 | Địa chỉ FDE: 0x1ea0d0 | Kích thước: 156 bytes
//   0x136528: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x13652c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x136530: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x136534: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2978_0x136528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136528ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea0d0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2979 | PC: 0x1365c4 | FDE: 0x1ea0f0 | Size: 64 bytes [PySys_SetObject]
// Khung tháo gỡ #2979 | Địa chỉ PC: 0x1365c4 | Địa chỉ FDE: 0x1ea0f0 | Kích thước: 64 bytes
//   0x1365c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1365c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1365cc: 910043FD  add      x29, sp, #0x10
//   0x1365d0: B0000648  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2979_0x1365c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1365c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea0f0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2980 | PC: 0x136604 | FDE: 0x1ea110 | Size: 196 bytes
// Khung tháo gỡ #2980 | Địa chỉ PC: 0x136604 | Địa chỉ FDE: 0x1ea110 | Kích thước: 196 bytes
//   0x136604: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x136608: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13660c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x136610: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2980_0x136604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136604ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea110ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2981 | PC: 0x1366c8 | FDE: 0x1ea130 | Size: 148 bytes [_PySys_Audit]
// Khung tháo gỡ #2981 | Địa chỉ PC: 0x1366c8 | Địa chỉ FDE: 0x1ea130 | Kích thước: 148 bytes
//   0x1366c8: D10483FF  sub      sp, sp, #0x120
//   0x1366cc: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x1366d0: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x1366d4: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_2981_0x1366c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1366c8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1ea130ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2982 | PC: 0x13675c | FDE: 0x1ea150 | Size: 256 bytes
// Khung tháo gỡ #2982 | Địa chỉ PC: 0x13675c | Địa chỉ FDE: 0x1ea150 | Kích thước: 256 bytes
//   0x13675c: D102C3FF  sub      sp, sp, #0xb0
//   0x136760: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x136764: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x136768: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_2982_0x13675c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13675cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x1ea150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2983 | PC: 0x136b8c | FDE: 0x1ea180 | Size: 184 bytes [PySys_Audit]
// Khung tháo gỡ #2983 | Địa chỉ PC: 0x136b8c | Địa chỉ FDE: 0x1ea180 | Kích thước: 184 bytes
//   0x136b8c: D10503FF  sub      sp, sp, #0x140
//   0x136b90: F90083FC  str      x28, [sp, #0x100]
//   0x136b94: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x136b98: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_2983_0x136b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136b8cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1ea180ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2984 | PC: 0x136c44 | FDE: 0x1ea1a8 | Size: 132 bytes [_PySys_ClearAuditHooks]
// Khung tháo gỡ #2984 | Địa chỉ PC: 0x136c44 | Địa chỉ FDE: 0x1ea1a8 | Kích thước: 132 bytes
//   0x136c44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x136c48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x136c4c: 910043FD  add      x29, sp, #0x10
//   0x136c50: B4000360  cbz      x0, #0x136cbc
static inline uint64_t fde_func_2984_0x136c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136c44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea1a8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2985 | PC: 0x136cc8 | FDE: 0x1ea1c8 | Size: 180 bytes [PySys_WriteStderr]
// Khung tháo gỡ #2985 | Địa chỉ PC: 0x136cc8 | Địa chỉ FDE: 0x1ea1c8 | Kích thước: 180 bytes
//   0x136cc8: D104C3FF  sub      sp, sp, #0x130
//   0x136ccc: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x136cd0: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x136cd4: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_2985_0x136cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136cc8ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea1c8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #2986 | PC: 0x136d7c | FDE: 0x1ea1e8 | Size: 256 bytes [PySys_AddAuditHook]
// Khung tháo gỡ #2986 | Địa chỉ PC: 0x136d7c | Địa chỉ FDE: 0x1ea1e8 | Kích thước: 256 bytes
//   0x136d7c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x136d80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x136d84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x136d88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2986_0x136d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136d7cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ea1e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2987 | PC: 0x136e90 | FDE: 0x1ea210 | Size: 256 bytes [_PySys_GetSizeOf]
// Khung tháo gỡ #2987 | Địa chỉ PC: 0x136e90 | Địa chỉ FDE: 0x1ea210 | Kích thước: 256 bytes
//   0x136e90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x136e94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x136e98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x136e9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2987_0x136e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136e90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2988 | PC: 0x13702c | FDE: 0x1ea238 | Size: 24 bytes
// Khung tháo gỡ #2988 | Địa chỉ PC: 0x13702c | Địa chỉ FDE: 0x1ea238 | Kích thước: 24 bytes
//   0x13702c: F9400008  ldr      x8, [x0]
//   0x137030: F1000508  subs     x8, x8, #1
//   0x137034: F9000008  str      x8, [x0]
//   0x137038: 54000040  b.eq     #0x137040
static inline uint64_t fde_func_2988_0x13702c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13702cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf1000508ULL) ^ 0x1ea238ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2989 | PC: 0x137044 | FDE: 0x1ea250 | Size: 256 bytes [_PySys_ReadPreinitWarnOptions]
// Khung tháo gỡ #2989 | Địa chỉ PC: 0x137044 | Địa chỉ FDE: 0x1ea250 | Kích thước: 256 bytes
//   0x137044: D10283FF  sub      sp, sp, #0xa0
//   0x137048: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x13704c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x137050: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_2989_0x137044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137044ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1ea250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2990 | PC: 0x137144 | FDE: 0x1ea278 | Size: 256 bytes [_PySys_ReadPreinitXOptions]
// Khung tháo gỡ #2990 | Địa chỉ PC: 0x137144 | Địa chỉ FDE: 0x1ea278 | Kích thước: 256 bytes
//   0x137144: D10283FF  sub      sp, sp, #0xa0
//   0x137148: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x13714c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x137150: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_2990_0x137144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137144ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1ea278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2991 | PC: 0x137244 | FDE: 0x1ea2a0 | Size: 252 bytes [PySys_ResetWarnOptions]
// Khung tháo gỡ #2991 | Địa chỉ PC: 0x137244 | Địa chỉ FDE: 0x1ea2a0 | Kích thước: 252 bytes
//   0x137244: D101C3FF  sub      sp, sp, #0x70
//   0x137248: F90023F5  str      x21, [sp, #0x40]
//   0x13724c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x137250: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_2991_0x137244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137244ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1ea2a0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #2992 | PC: 0x137340 | FDE: 0x1ea2c0 | Size: 256 bytes [PySys_AddWarnOptionUnicode]
// Khung tháo gỡ #2992 | Địa chỉ PC: 0x137340 | Địa chỉ FDE: 0x1ea2c0 | Kích thước: 256 bytes
//   0x137340: D10183FF  sub      sp, sp, #0x60
//   0x137344: F90013F7  str      x23, [sp, #0x20]
//   0x137348: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13734c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2992_0x137340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137340ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1ea2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2993 | PC: 0x137484 | FDE: 0x1ea2e8 | Size: 116 bytes [PySys_AddWarnOption]
// Khung tháo gỡ #2993 | Địa chỉ PC: 0x137484 | Địa chỉ FDE: 0x1ea2e8 | Kích thước: 116 bytes
//   0x137484: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x137488: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13748c: 910043FD  add      x29, sp, #0x10
//   0x137490: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2993_0x137484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137484ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea2e8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2994 | PC: 0x1374f8 | FDE: 0x1ea308 | Size: 192 bytes
// Khung tháo gỡ #2994 | Địa chỉ PC: 0x1374f8 | Địa chỉ FDE: 0x1ea308 | Kích thước: 192 bytes
//   0x1374f8: D10183FF  sub      sp, sp, #0x60
//   0x1374fc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x137500: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x137504: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2994_0x1374f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1374f8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1ea308ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2995 | PC: 0x1375b8 | FDE: 0x1ea330 | Size: 180 bytes [PySys_HasWarnOptions]
// Khung tháo gỡ #2995 | Địa chỉ PC: 0x1375b8 | Địa chỉ FDE: 0x1ea330 | Kích thước: 180 bytes
//   0x1375b8: D10143FF  sub      sp, sp, #0x50
//   0x1375bc: F90013F5  str      x21, [sp, #0x20]
//   0x1375c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1375c4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2995_0x1375b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1375b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea330ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #2996 | PC: 0x13766c | FDE: 0x1ea350 | Size: 256 bytes [PySys_AddXOption]
// Khung tháo gỡ #2996 | Địa chỉ PC: 0x13766c | Địa chỉ FDE: 0x1ea350 | Kích thước: 256 bytes
//   0x13766c: D10183FF  sub      sp, sp, #0x60
//   0x137670: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x137674: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x137678: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2996_0x13766c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13766cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1ea350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2997 | PC: 0x137890 | FDE: 0x1ea378 | Size: 256 bytes [PySys_GetXOptions]
// Khung tháo gỡ #2997 | Địa chỉ PC: 0x137890 | Địa chỉ FDE: 0x1ea378 | Kích thước: 256 bytes
//   0x137890: D10143FF  sub      sp, sp, #0x50
//   0x137894: F90013F5  str      x21, [sp, #0x20]
//   0x137898: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13789c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2997_0x137890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137890ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2998 | PC: 0x1379a0 | FDE: 0x1ea398 | Size: 256 bytes [_PySys_UpdateConfig]
// Khung tháo gỡ #2998 | Địa chỉ PC: 0x1379a0 | Địa chỉ FDE: 0x1ea398 | Kích thước: 256 bytes
//   0x1379a0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1379a4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1379a8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1379ac: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2998_0x1379a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1379a0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ea398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2999 | PC: 0x137f94 | FDE: 0x1ea3c8 | Size: 256 bytes
// Khung tháo gỡ #2999 | Địa chỉ PC: 0x137f94 | Địa chỉ FDE: 0x1ea3c8 | Kích thước: 256 bytes
//   0x137f94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x137f98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x137f9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x137fa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2999_0x137f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137f94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea3c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3000 | PC: 0x138310 | FDE: 0x1ea3f0 | Size: 256 bytes [_PySys_Create]
// Khung tháo gỡ #3000 | Địa chỉ PC: 0x138310 | Địa chỉ FDE: 0x1ea3f0 | Kích thước: 256 bytes
//   0x138310: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x138314: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x138318: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13831c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3000_0x138310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x138310ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ea3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3001 | PC: 0x139214 | FDE: 0x1ea420 | Size: 256 bytes [PySys_SetPath]
// Khung tháo gỡ #3001 | Địa chỉ PC: 0x139214 | Địa chỉ FDE: 0x1ea420 | Kích thước: 256 bytes
//   0x139214: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x139218: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13921c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x139220: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3001_0x139214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139214ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3002 | PC: 0x13936c | FDE: 0x1ea448 | Size: 256 bytes [PySys_SetArgvEx]
// Khung tháo gỡ #3002 | Địa chỉ PC: 0x13936c | Địa chỉ FDE: 0x1ea448 | Kích thước: 256 bytes
//   0x13936c: D10243FF  sub      sp, sp, #0x90
//   0x139370: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x139374: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x139378: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_3002_0x13936c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13936cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x1ea448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3003 | PC: 0x1395bc | FDE: 0x1ea478 | Size: 24 bytes [PySys_SetArgv]
// Khung tháo gỡ #3003 | Địa chỉ PC: 0x1395bc | Địa chỉ FDE: 0x1ea478 | Kích thước: 24 bytes
//   0x1395bc: D0000628  adrp     x8, #0x1ff000
//   0x1395c0: F9430D08  ldr      x8, [x8, #0x618]
//   0x1395c4: B9400108  ldr      w8, [x8]
//   0x1395c8: 7100011F  cmp      w8, #0
static inline uint64_t fde_func_3003_0x1395bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1395bcULL ^ (static_cast<uint64_t>(0xd0000628ULL) << 13);
    acc = (acc + a1 + 0xf9430d08ULL) ^ 0x1ea478ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3004 | PC: 0x1395d4 | FDE: 0x1ea490 | Size: 180 bytes [PySys_WriteStdout]
// Khung tháo gỡ #3004 | Địa chỉ PC: 0x1395d4 | Địa chỉ FDE: 0x1ea490 | Kích thước: 180 bytes
//   0x1395d4: D104C3FF  sub      sp, sp, #0x130
//   0x1395d8: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x1395dc: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x1395e0: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_3004_0x1395d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1395d4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea490ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3005 | PC: 0x139688 | FDE: 0x1ea4b0 | Size: 256 bytes
// Khung tháo gỡ #3005 | Địa chỉ PC: 0x139688 | Địa chỉ FDE: 0x1ea4b0 | Kích thước: 256 bytes
//   0x139688: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x13968c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x139690: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x139694: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3005_0x139688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139688ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ea4b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3006 | PC: 0x1398b0 | FDE: 0x1ea4e0 | Size: 180 bytes [PySys_FormatStdout]
// Khung tháo gỡ #3006 | Địa chỉ PC: 0x1398b0 | Địa chỉ FDE: 0x1ea4e0 | Kích thước: 180 bytes
//   0x1398b0: D104C3FF  sub      sp, sp, #0x130
//   0x1398b4: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x1398b8: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x1398bc: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_3006_0x1398b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1398b0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea4e0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3007 | PC: 0x139964 | FDE: 0x1ea500 | Size: 256 bytes
// Khung tháo gỡ #3007 | Địa chỉ PC: 0x139964 | Địa chỉ FDE: 0x1ea500 | Kích thước: 256 bytes
//   0x139964: D102C3FF  sub      sp, sp, #0xb0
//   0x139968: F90033F9  str      x25, [sp, #0x60]
//   0x13996c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x139970: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_3007_0x139964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139964ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x1ea500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3008 | PC: 0x139ad4 | FDE: 0x1ea528 | Size: 180 bytes [PySys_FormatStderr]
// Khung tháo gỡ #3008 | Địa chỉ PC: 0x139ad4 | Địa chỉ FDE: 0x1ea528 | Kích thước: 180 bytes
//   0x139ad4: D104C3FF  sub      sp, sp, #0x130
//   0x139ad8: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x139adc: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x139ae0: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_3008_0x139ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139ad4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea528ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3009 | PC: 0x139b88 | FDE: 0x1ea548 | Size: 256 bytes
// Khung tháo gỡ #3009 | Địa chỉ PC: 0x139b88 | Địa chỉ FDE: 0x1ea548 | Kích thước: 256 bytes
//   0x139b88: D10143FF  sub      sp, sp, #0x50
//   0x139b8c: F90013F5  str      x21, [sp, #0x20]
//   0x139b90: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x139b94: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3009_0x139b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139b88ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3010 | PC: 0x139c94 | FDE: 0x1ea568 | Size: 256 bytes
// Khung tháo gỡ #3010 | Địa chỉ PC: 0x139c94 | Địa chỉ FDE: 0x1ea568 | Kích thước: 256 bytes
//   0x139c94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x139c98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x139c9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x139ca0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3010_0x139c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139c94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3011 | PC: 0x139ddc | FDE: 0x1ea590 | Size: 256 bytes
// Khung tháo gỡ #3011 | Địa chỉ PC: 0x139ddc | Địa chỉ FDE: 0x1ea590 | Kích thước: 256 bytes
//   0x139ddc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x139de0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x139de4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x139de8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3011_0x139ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139ddcULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ea590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3012 | PC: 0x13b03c | FDE: 0x1ea5c0 | Size: 40 bytes
// Khung tháo gỡ #3012 | Địa chỉ PC: 0x13b03c | Địa chỉ FDE: 0x1ea5c0 | Kích thước: 40 bytes
//   0x13b03c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b040: 910003FD  mov      x29, sp
//   0x13b044: 97FC7757  bl       #0x58da0
//   0x13b048: 90000620  adrp     x0, #0x1ff000
static inline uint64_t fde_func_3012_0x13b03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b03cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea5c0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3013 | PC: 0x13b064 | FDE: 0x1ea5e0 | Size: 4 bytes
// Khung tháo gỡ #3013 | Địa chỉ PC: 0x13b064 | Địa chỉ FDE: 0x1ea5e0 | Kích thước: 4 bytes
//   0x13b064: 17FC7867  b        #0x59200
static inline uint64_t fde_func_3013_0x13b064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b064ULL ^ (static_cast<uint64_t>(0x17fc7867ULL) << 13);
    acc = (acc + a1 + 0x17fc7f62ULL) ^ 0x1ea5e0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3014 | PC: 0x13b068 | FDE: 0x1ea5f8 | Size: 4 bytes
// Khung tháo gỡ #3014 | Địa chỉ PC: 0x13b068 | Địa chỉ FDE: 0x1ea5f8 | Kích thước: 4 bytes
//   0x13b068: 17FC7F62  b        #0x5adf0
static inline uint64_t fde_func_3014_0x13b068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b068ULL ^ (static_cast<uint64_t>(0x17fc7f62ULL) << 13);
    acc = (acc + a1 + 0xd10243ffULL) ^ 0x1ea5f8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3015 | PC: 0x13b06c | FDE: 0x1ea610 | Size: 256 bytes
// Khung tháo gỡ #3015 | Địa chỉ PC: 0x13b06c | Địa chỉ FDE: 0x1ea610 | Kích thước: 256 bytes
//   0x13b06c: D10243FF  sub      sp, sp, #0x90
//   0x13b070: F9001BFB  str      x27, [sp, #0x30]
//   0x13b074: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x13b078: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3015_0x13b06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b06cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x1ea610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3016 | PC: 0x13b3f4 | FDE: 0x1ea640 | Size: 72 bytes
// Khung tháo gỡ #3016 | Địa chỉ PC: 0x13b3f4 | Địa chỉ FDE: 0x1ea640 | Kích thước: 72 bytes
//   0x13b3f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b3f8: 910003FD  mov      x29, sp
//   0x13b3fc: 97FC78F1  bl       #0x597c0
//   0x13b400: 97FC7674  bl       #0x58dd0
static inline uint64_t fde_func_3016_0x13b3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b3f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea640ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3017 | PC: 0x13b43c | FDE: 0x1ea660 | Size: 108 bytes
// Khung tháo gỡ #3017 | Địa chỉ PC: 0x13b43c | Địa chỉ FDE: 0x1ea660 | Kích thước: 108 bytes
//   0x13b43c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13b440: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13b444: 910043FD  add      x29, sp, #0x10
//   0x13b448: F1000C5F  cmp      x2, #3
static inline uint64_t fde_func_3017_0x13b43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b43cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea660ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3018 | PC: 0x13b4a8 | FDE: 0x1ea680 | Size: 112 bytes
// Khung tháo gỡ #3018 | Địa chỉ PC: 0x13b4a8 | Địa chỉ FDE: 0x1ea680 | Kích thước: 112 bytes
//   0x13b4a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13b4ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13b4b0: 910043FD  add      x29, sp, #0x10
//   0x13b4b4: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_3018_0x13b4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b4a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea680ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3019 | PC: 0x13b518 | FDE: 0x1ea6a0 | Size: 20 bytes
// Khung tháo gỡ #3019 | Địa chỉ PC: 0x13b518 | Địa chỉ FDE: 0x1ea6a0 | Kích thước: 20 bytes
//   0x13b518: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b51c: 910003FD  mov      x29, sp
//   0x13b520: 97FC77DC  bl       #0x59490
//   0x13b524: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_3019_0x13b518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b518ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea6a0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #3020 | PC: 0x13b52c | FDE: 0x1ea6c0 | Size: 40 bytes
// Khung tháo gỡ #3020 | Địa chỉ PC: 0x13b52c | Địa chỉ FDE: 0x1ea6c0 | Kích thước: 40 bytes
//   0x13b52c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b530: 910003FD  mov      x29, sp
//   0x13b534: 90000628  adrp     x8, #0x1ff000
//   0x13b538: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3020_0x13b52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b52cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea6c0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3021 | PC: 0x13b554 | FDE: 0x1ea6e0 | Size: 68 bytes
// Khung tháo gỡ #3021 | Địa chỉ PC: 0x13b554 | Địa chỉ FDE: 0x1ea6e0 | Kích thước: 68 bytes
//   0x13b554: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13b558: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13b55c: 910043FD  add      x29, sp, #0x10
//   0x13b560: 97FC8038  bl       #0x5b640
static inline uint64_t fde_func_3021_0x13b554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b554ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea6e0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3022 | PC: 0x13b598 | FDE: 0x1ea700 | Size: 48 bytes
// Khung tháo gỡ #3022 | Địa chỉ PC: 0x13b598 | Địa chỉ FDE: 0x1ea700 | Kích thước: 48 bytes
//   0x13b598: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b59c: 910003FD  mov      x29, sp
//   0x13b5a0: 90000628  adrp     x8, #0x1ff000
//   0x13b5a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3022_0x13b598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b598ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea700ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3023 | PC: 0x13b5c8 | FDE: 0x1ea720 | Size: 48 bytes
// Khung tháo gỡ #3023 | Địa chỉ PC: 0x13b5c8 | Địa chỉ FDE: 0x1ea720 | Kích thước: 48 bytes
//   0x13b5c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b5cc: 910003FD  mov      x29, sp
//   0x13b5d0: 90000628  adrp     x8, #0x1ff000
//   0x13b5d4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3023_0x13b5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b5c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea720ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3024 | PC: 0x13b5f8 | FDE: 0x1ea740 | Size: 64 bytes
// Khung tháo gỡ #3024 | Địa chỉ PC: 0x13b5f8 | Địa chỉ FDE: 0x1ea740 | Kích thước: 64 bytes
//   0x13b5f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13b5fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13b600: 910043FD  add      x29, sp, #0x10
//   0x13b604: F9400033  ldr      x19, [x1]
static inline uint64_t fde_func_3024_0x13b5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b5f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea740ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3025 | PC: 0x13b638 | FDE: 0x1ea760 | Size: 24 bytes
// Khung tháo gỡ #3025 | Địa chỉ PC: 0x13b638 | Địa chỉ FDE: 0x1ea760 | Kích thước: 24 bytes
//   0x13b638: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b63c: 910003FD  mov      x29, sp
//   0x13b640: 97FC7BC8  bl       #0x5a560
//   0x13b644: 93407C00  sxtw     x0, w0
static inline uint64_t fde_func_3025_0x13b638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b638ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea760ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3026 | PC: 0x13b650 | FDE: 0x1ea780 | Size: 228 bytes
// Khung tháo gỡ #3026 | Địa chỉ PC: 0x13b650 | Địa chỉ FDE: 0x1ea780 | Kích thước: 228 bytes
//   0x13b650: D10143FF  sub      sp, sp, #0x50
//   0x13b654: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13b658: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13b65c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3026_0x13b650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b650ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ea780ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #3027 | PC: 0x13b734 | FDE: 0x1ea7a8 | Size: 256 bytes
// Khung tháo gỡ #3027 | Địa chỉ PC: 0x13b734 | Địa chỉ FDE: 0x1ea7a8 | Kích thước: 256 bytes
//   0x13b734: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13b738: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13b73c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13b740: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3027_0x13b734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b734ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3028 | PC: 0x13b870 | FDE: 0x1ea7d0 | Size: 224 bytes
// Khung tháo gỡ #3028 | Địa chỉ PC: 0x13b870 | Địa chỉ FDE: 0x1ea7d0 | Kích thước: 224 bytes
//   0x13b870: D100C3FF  sub      sp, sp, #0x30
//   0x13b874: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13b878: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13b87c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3028_0x13b870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b870ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea7d0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #3029 | PC: 0x13b950 | FDE: 0x1ea7f0 | Size: 24 bytes
// Khung tháo gỡ #3029 | Địa chỉ PC: 0x13b950 | Địa chỉ FDE: 0x1ea7f0 | Kích thước: 24 bytes
//   0x13b950: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b954: 910003FD  mov      x29, sp
//   0x13b958: 97FC7CBE  bl       #0x5ac50
//   0x13b95c: 93407C00  sxtw     x0, w0
static inline uint64_t fde_func_3029_0x13b950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b950ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea7f0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3030 | PC: 0x13b968 | FDE: 0x1ea810 | Size: 160 bytes
// Khung tháo gỡ #3030 | Địa chỉ PC: 0x13b968 | Địa chỉ FDE: 0x1ea810 | Kích thước: 160 bytes
//   0x13b968: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13b96c: 910003FD  mov      x29, sp
//   0x13b970: 90000629  adrp     x9, #0x1ff000
//   0x13b974: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_3030_0x13b968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b968ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea810ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3031 | PC: 0x13ba08 | FDE: 0x1ea830 | Size: 36 bytes
// Khung tháo gỡ #3031 | Địa chỉ PC: 0x13ba08 | Địa chỉ FDE: 0x1ea830 | Kích thước: 36 bytes
//   0x13ba08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13ba0c: 910003FD  mov      x29, sp
//   0x13ba10: 97FC7788  bl       #0x59830
//   0x13ba14: F0000408  adrp     x8, #0x1be000
static inline uint64_t fde_func_3031_0x13ba08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ba08ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea830ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3032 | PC: 0x13ba2c | FDE: 0x1ea850 | Size: 104 bytes
// Khung tháo gỡ #3032 | Địa chỉ PC: 0x13ba2c | Địa chỉ FDE: 0x1ea850 | Kích thước: 104 bytes
//   0x13ba2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13ba30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13ba34: 910043FD  add      x29, sp, #0x10
//   0x13ba38: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3032_0x13ba2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ba2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea850ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3033 | PC: 0x13ba94 | FDE: 0x1ea870 | Size: 120 bytes
// Khung tháo gỡ #3033 | Địa chỉ PC: 0x13ba94 | Địa chỉ FDE: 0x1ea870 | Kích thước: 120 bytes
//   0x13ba94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13ba98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13ba9c: 910043FD  add      x29, sp, #0x10
//   0x13baa0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_3033_0x13ba94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ba94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea870ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3034 | PC: 0x13bb0c | FDE: 0x1ea890 | Size: 52 bytes
// Khung tháo gỡ #3034 | Địa chỉ PC: 0x13bb0c | Địa chỉ FDE: 0x1ea890 | Kích thước: 52 bytes
//   0x13bb0c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13bb10: 910003FD  mov      x29, sp
//   0x13bb14: 97FC772B  bl       #0x597c0
//   0x13bb18: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_3034_0x13bb0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bb0cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea890ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3035 | PC: 0x13bb40 | FDE: 0x1ea8b0 | Size: 172 bytes
// Khung tháo gỡ #3035 | Địa chỉ PC: 0x13bb40 | Địa chỉ FDE: 0x1ea8b0 | Kích thước: 172 bytes
//   0x13bb40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13bb44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13bb48: 910043FD  add      x29, sp, #0x10
//   0x13bb4c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3035_0x13bb40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bb40ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea8b0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3036 | PC: 0x13bbec | FDE: 0x1ea8d0 | Size: 120 bytes
// Khung tháo gỡ #3036 | Địa chỉ PC: 0x13bbec | Địa chỉ FDE: 0x1ea8d0 | Kích thước: 120 bytes
//   0x13bbec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13bbf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13bbf4: 910043FD  add      x29, sp, #0x10
//   0x13bbf8: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_3036_0x13bbec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bbecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea8d0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3037 | PC: 0x13bc64 | FDE: 0x1ea8f0 | Size: 52 bytes
// Khung tháo gỡ #3037 | Địa chỉ PC: 0x13bc64 | Địa chỉ FDE: 0x1ea8f0 | Kích thước: 52 bytes
//   0x13bc64: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13bc68: 910003FD  mov      x29, sp
//   0x13bc6c: 97FC76D5  bl       #0x597c0
//   0x13bc70: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_3037_0x13bc64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bc64ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea8f0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3038 | PC: 0x13bc98 | FDE: 0x1ea910 | Size: 136 bytes
// Khung tháo gỡ #3038 | Địa chỉ PC: 0x13bc98 | Địa chỉ FDE: 0x1ea910 | Kích thước: 136 bytes
//   0x13bc98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13bc9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13bca0: 910043FD  add      x29, sp, #0x10
//   0x13bca4: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3038_0x13bc98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bc98ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea910ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #3039 | PC: 0x13bd20 | FDE: 0x1ea930 | Size: 52 bytes
// Khung tháo gỡ #3039 | Địa chỉ PC: 0x13bd20 | Địa chỉ FDE: 0x1ea930 | Kích thước: 52 bytes
//   0x13bd20: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13bd24: 910003FD  mov      x29, sp
//   0x13bd28: 90000628  adrp     x8, #0x1ff000
//   0x13bd2c: F9443508  ldr      x8, [x8, #0x868]
static inline uint64_t fde_func_3039_0x13bd20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bd20ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea930ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3040 | PC: 0x13bd54 | FDE: 0x1ea950 | Size: 228 bytes
// Khung tháo gỡ #3040 | Địa chỉ PC: 0x13bd54 | Địa chỉ FDE: 0x1ea950 | Kích thước: 228 bytes
//   0x13bd54: D10103FF  sub      sp, sp, #0x40
//   0x13bd58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13bd5c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x13bd60: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3040_0x13bd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bd54ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ea950ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #3041 | PC: 0x13be38 | FDE: 0x1ea970 | Size: 68 bytes
// Khung tháo gỡ #3041 | Địa chỉ PC: 0x13be38 | Địa chỉ FDE: 0x1ea970 | Kích thước: 68 bytes
//   0x13be38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13be3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13be40: 910043FD  add      x29, sp, #0x10
//   0x13be44: 97FC84F7  bl       #0x5d220
static inline uint64_t fde_func_3041_0x13be38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13be38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea970ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3042 | PC: 0x13be7c | FDE: 0x1ea990 | Size: 256 bytes
// Khung tháo gỡ #3042 | Địa chỉ PC: 0x13be7c | Địa chỉ FDE: 0x1ea990 | Kích thước: 256 bytes
//   0x13be7c: D10103FF  sub      sp, sp, #0x40
//   0x13be80: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13be84: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x13be88: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3042_0x13be7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13be7cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ea990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3043 | PC: 0x13bfbc | FDE: 0x1ea9b0 | Size: 112 bytes
// Khung tháo gỡ #3043 | Địa chỉ PC: 0x13bfbc | Địa chỉ FDE: 0x1ea9b0 | Kích thước: 112 bytes
//   0x13bfbc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13bfc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13bfc4: 910043FD  add      x29, sp, #0x10
//   0x13bfc8: 97FC83EE  bl       #0x5cf80
static inline uint64_t fde_func_3043_0x13bfbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bfbcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea9b0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3044 | PC: 0x13c02c | FDE: 0x1ea9d0 | Size: 8 bytes
// Khung tháo gỡ #3044 | Địa chỉ PC: 0x13c02c | Địa chỉ FDE: 0x1ea9d0 | Kích thước: 8 bytes
//   0x13c02c: 52800240  mov      w0, #0x12
//   0x13c030: 17FC79D0  b        #0x5a770
static inline uint64_t fde_func_3044_0x13c02c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c02cULL ^ (static_cast<uint64_t>(0x52800240ULL) << 13);
    acc = (acc + a1 + 0x17fc79d0ULL) ^ 0x1ea9d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3045 | PC: 0x13c034 | FDE: 0x1ea9e8 | Size: 8 bytes
// Khung tháo gỡ #3045 | Địa chỉ PC: 0x13c034 | Địa chỉ FDE: 0x1ea9e8 | Kích thước: 8 bytes
//   0x13c034: AA0103E0  mov      x0, x1
//   0x13c038: 17FC745E  b        #0x591b0
static inline uint64_t fde_func_3045_0x13c034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c034ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fc745eULL) ^ 0x1ea9e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3046 | PC: 0x13c03c | FDE: 0x1eaa00 | Size: 40 bytes
// Khung tháo gỡ #3046 | Địa chỉ PC: 0x13c03c | Địa chỉ FDE: 0x1eaa00 | Kích thước: 40 bytes
//   0x13c03c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13c040: 910003FD  mov      x29, sp
//   0x13c044: 97FC77EF  bl       #0x5a000
//   0x13c048: F0000600  adrp     x0, #0x1ff000
static inline uint64_t fde_func_3046_0x13c03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c03cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eaa00ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3047 | PC: 0x13c064 | FDE: 0x1eaa20 | Size: 256 bytes
// Khung tháo gỡ #3047 | Địa chỉ PC: 0x13c064 | Địa chỉ FDE: 0x1eaa20 | Kích thước: 256 bytes
//   0x13c064: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13c068: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13c06c: 910043FD  add      x29, sp, #0x10
//   0x13c070: B0000753  adrp     x19, #0x225000
static inline uint64_t fde_func_3047_0x13c064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c064ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eaa20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3048 | PC: 0x13c194 | FDE: 0x1eaa40 | Size: 148 bytes
// Khung tháo gỡ #3048 | Địa chỉ PC: 0x13c194 | Địa chỉ FDE: 0x1eaa40 | Kích thước: 148 bytes
//   0x13c194: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x13c198: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x13c19c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13c1a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3048_0x13c194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c194ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eaa40ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3049 | PC: 0x13c228 | FDE: 0x1eaa68 | Size: 256 bytes
// Khung tháo gỡ #3049 | Địa chỉ PC: 0x13c228 | Địa chỉ FDE: 0x1eaa68 | Kích thước: 256 bytes
//   0x13c228: D10183FF  sub      sp, sp, #0x60
//   0x13c22c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13c230: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13c234: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3049_0x13c228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c228ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1eaa68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3050 | PC: 0x13c340 | FDE: 0x1eaa90 | Size: 248 bytes
// Khung tháo gỡ #3050 | Địa chỉ PC: 0x13c340 | Địa chỉ FDE: 0x1eaa90 | Kích thước: 248 bytes
//   0x13c340: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x13c344: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x13c348: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13c34c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3050_0x13c340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c340ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eaa90ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3051 | PC: 0x13c438 | FDE: 0x1eaab8 | Size: 256 bytes [_Py_Offer_Suggestions]
// Khung tháo gỡ #3051 | Địa chỉ PC: 0x13c438 | Địa chỉ FDE: 0x1eaab8 | Kích thước: 256 bytes
//   0x13c438: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13c43c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13c440: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13c444: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3051_0x13c438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c438ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eaab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3052 | PC: 0x13c5a4 | FDE: 0x1eaae0 | Size: 160 bytes [_Py_UTF8_Edit_Cost]
// Khung tháo gỡ #3052 | Địa chỉ PC: 0x13c5a4 | Địa chỉ FDE: 0x1eaae0 | Kích thước: 160 bytes
//   0x13c5a4: D10143FF  sub      sp, sp, #0x50
//   0x13c5a8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13c5ac: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13c5b0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3052_0x13c5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c5a4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1eaae0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3053 | PC: 0x13c644 | FDE: 0x1eab08 | Size: 256 bytes
// Khung tháo gỡ #3053 | Địa chỉ PC: 0x13c644 | Địa chỉ FDE: 0x1eab08 | Kích thước: 256 bytes
//   0x13c644: EB02001F  cmp      x0, x2
//   0x13c648: 54001360  b.eq     #0x13c8b4
//   0x13c64c: B4000323  cbz      x3, #0x13c6b0
//   0x13c650: B4000301  cbz      x1, #0x13c6b0
static inline uint64_t fde_func_3053_0x13c644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c644ULL ^ (static_cast<uint64_t>(0xeb02001fULL) << 13);
    acc = (acc + a1 + 0x54001360ULL) ^ 0x1eab08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3054 | PC: 0x13c8c4 | FDE: 0x1eab20 | Size: 256 bytes
// Khung tháo gỡ #3054 | Địa chỉ PC: 0x13c8c4 | Địa chỉ FDE: 0x1eab20 | Kích thước: 256 bytes
//   0x13c8c4: D10203FF  sub      sp, sp, #0x80
//   0x13c8c8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x13c8cc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x13c8d0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3054_0x13c8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c8c4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1eab20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3055 | PC: 0x13ca40 | FDE: 0x1eab50 | Size: 24 bytes [PyThread_init_thread]
// Khung tháo gỡ #3055 | Địa chỉ PC: 0x13ca40 | Địa chỉ FDE: 0x1eab50 | Kích thước: 24 bytes
//   0x13ca40: B0000748  adrp     x8, #0x225000
//   0x13ca44: 39760109  ldrb     w9, [x8, #0xd80]
//   0x13ca48: 37000069  tbnz     w9, #0, #0x13ca54
//   0x13ca4c: 52800029  mov      w9, #1
static inline uint64_t fde_func_3055_0x13ca40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca40ULL ^ (static_cast<uint64_t>(0xb0000748ULL) << 13);
    acc = (acc + a1 + 0x39760109ULL) ^ 0x1eab50ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3056 | PC: 0x13ca58 | FDE: 0x1eab68 | Size: 4 bytes [_PyThread_debug_deprecation]
// Khung tháo gỡ #3056 | Địa chỉ PC: 0x13ca58 | Địa chỉ FDE: 0x1eab68 | Kích thước: 4 bytes
//   0x13ca58: D65F03C0  ret      
static inline uint64_t fde_func_3056_0x13ca58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca58ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1eab68ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3057 | PC: 0x13ca5c | FDE: 0x1eab80 | Size: 8 bytes [_PyThread_cond_init]
// Khung tháo gỡ #3057 | Địa chỉ PC: 0x13ca5c | Địa chỉ FDE: 0x1eab80 | Kích thước: 8 bytes
//   0x13ca5c: AA1F03E1  mov      x1, xzr
//   0x13ca60: 17FC81C8  b        #0x5d180
static inline uint64_t fde_func_3057_0x13ca5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca5cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fc81c8ULL) ^ 0x1eab80ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3058 | PC: 0x13ca64 | FDE: 0x1eab98 | Size: 136 bytes [_PyThread_cond_after]
// Khung tháo gỡ #3058 | Địa chỉ PC: 0x13ca64 | Địa chỉ FDE: 0x1eab98 | Kích thước: 136 bytes
//   0x13ca64: D100C3FF  sub      sp, sp, #0x30
//   0x13ca68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13ca6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13ca70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3058_0x13ca64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca64ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eab98ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #3059 | PC: 0x13caec | FDE: 0x1eabb8 | Size: 248 bytes [PyThread_start_new_thread]
// Khung tháo gỡ #3059 | Địa chỉ PC: 0x13caec | Địa chỉ FDE: 0x1eabb8 | Kích thước: 248 bytes
//   0x13caec: D10203FF  sub      sp, sp, #0x80
//   0x13caf0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x13caf4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x13caf8: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_3059_0x13caec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13caecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1eabb8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3060 | PC: 0x13cbe4 | FDE: 0x1eabe0 | Size: 44 bytes
// Khung tháo gỡ #3060 | Địa chỉ PC: 0x13cbe4 | Địa chỉ FDE: 0x1eabe0 | Kích thước: 44 bytes
//   0x13cbe4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13cbe8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13cbec: 910043FD  add      x29, sp, #0x10
//   0x13cbf0: A9404C14  ldp      x20, x19, [x0]
static inline uint64_t fde_func_3060_0x13cbe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cbe4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eabe0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3061 | PC: 0x13cc10 | FDE: 0x1eac00 | Size: 96 bytes [PyThread_get_thread_ident]
// Khung tháo gỡ #3061 | Địa chỉ PC: 0x13cc10 | Địa chỉ FDE: 0x1eac00 | Kích thước: 96 bytes
//   0x13cc10: D100C3FF  sub      sp, sp, #0x30
//   0x13cc14: F9000BF3  str      x19, [sp, #0x10]
//   0x13cc18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13cc1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3061_0x13cc10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cc10ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1eac00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #3062 | PC: 0x13cc70 | FDE: 0x1eac20 | Size: 48 bytes [PyThread_get_thread_native_id]
// Khung tháo gỡ #3062 | Địa chỉ PC: 0x13cc70 | Địa chỉ FDE: 0x1eac20 | Kích thước: 48 bytes
//   0x13cc70: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13cc74: 910003FD  mov      x29, sp
//   0x13cc78: B0000748  adrp     x8, #0x225000
//   0x13cc7c: 39760109  ldrb     w9, [x8, #0xd80]
static inline uint64_t fde_func_3062_0x13cc70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cc70ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eac20ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3063 | PC: 0x13cca0 | FDE: 0x1eac40 | Size: 68 bytes [PyThread_exit_thread]
// Khung tháo gỡ #3063 | Địa chỉ PC: 0x13cca0 | Địa chỉ FDE: 0x1eac40 | Kích thước: 68 bytes
//   0x13cca0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13cca4: 910003FD  mov      x29, sp
//   0x13cca8: B0000748  adrp     x8, #0x225000
//   0x13ccac: 39760108  ldrb     w8, [x8, #0xd80]
static inline uint64_t fde_func_3063_0x13cca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cca0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eac40ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3064 | PC: 0x13cce4 | FDE: 0x1eac60 | Size: 112 bytes [PyThread_allocate_lock]
// Khung tháo gỡ #3064 | Địa chỉ PC: 0x13cce4 | Địa chỉ FDE: 0x1eac60 | Kích thước: 112 bytes
//   0x13cce4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13cce8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13ccec: 910043FD  add      x29, sp, #0x10
//   0x13ccf0: B0000748  adrp     x8, #0x225000
static inline uint64_t fde_func_3064_0x13cce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cce4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eac60ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3065 | PC: 0x13cd54 | FDE: 0x1eac80 | Size: 64 bytes [PyThread_free_lock]
// Khung tháo gỡ #3065 | Địa chỉ PC: 0x13cd54 | Địa chỉ FDE: 0x1eac80 | Kích thước: 64 bytes
//   0x13cd54: B4000160  cbz      x0, #0x13cd80
//   0x13cd58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13cd5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13cd60: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_3065_0x13cd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cd54ULL ^ (static_cast<uint64_t>(0xb4000160ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1eac80ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3066 | PC: 0x13cd94 | FDE: 0x1eaca0 | Size: 256 bytes [PyThread_acquire_lock_timed]
// Khung tháo gỡ #3066 | Địa chỉ PC: 0x13cd94 | Địa chỉ FDE: 0x1eaca0 | Kích thước: 256 bytes
//   0x13cd94: D101C3FF  sub      sp, sp, #0x70
//   0x13cd98: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x13cd9c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x13cda0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_3066_0x13cd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cd94ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1eaca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3067 | PC: 0x13cfc4 | FDE: 0x1eacc8 | Size: 40 bytes [PyThread_release_lock]
// Khung tháo gỡ #3067 | Địa chỉ PC: 0x13cfc4 | Địa chỉ FDE: 0x1eacc8 | Kích thước: 40 bytes
//   0x13cfc4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13cfc8: 910003FD  mov      x29, sp
//   0x13cfcc: 97FC72C9  bl       #0x59af0
//   0x13cfd0: 340000A0  cbz      w0, #0x13cfe4
static inline uint64_t fde_func_3067_0x13cfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cfc4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eacc8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3068 | PC: 0x13cfec | FDE: 0x1eace8 | Size: 112 bytes [_PyThread_at_fork_reinit]
// Khung tháo gỡ #3068 | Địa chỉ PC: 0x13cfec | Địa chỉ FDE: 0x1eace8 | Kích thước: 112 bytes
//   0x13cfec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13cff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13cff4: 910043FD  add      x29, sp, #0x10
//   0x13cff8: B0000748  adrp     x8, #0x225000
static inline uint64_t fde_func_3068_0x13cfec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cfecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eace8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3069 | PC: 0x13d05c | FDE: 0x1ead08 | Size: 16 bytes [PyThread_acquire_lock]
// Khung tháo gỡ #3069 | Địa chỉ PC: 0x13d05c | Địa chỉ FDE: 0x1ead08 | Kích thước: 16 bytes
//   0x13d05c: 7100003F  cmp      w1, #0
//   0x13d060: DA9F03E1  csetm    x1, ne
//   0x13d064: 2A1F03E2  mov      w2, wzr
//   0x13d068: 17FC73B6  b        #0x59f40
static inline uint64_t fde_func_3069_0x13d05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d05cULL ^ (static_cast<uint64_t>(0x7100003fULL) << 13);
    acc = (acc + a1 + 0xda9f03e1ULL) ^ 0x1ead08ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3070 | PC: 0x13d06c | FDE: 0x1ead20 | Size: 88 bytes [PyThread_create_key]
// Khung tháo gỡ #3070 | Địa chỉ PC: 0x13d06c | Địa chỉ FDE: 0x1ead20 | Kích thước: 88 bytes
//   0x13d06c: D100C3FF  sub      sp, sp, #0x30
//   0x13d070: F9000BF3  str      x19, [sp, #0x10]
//   0x13d074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13d078: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3070_0x13d06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d06cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1ead20ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3071 | PC: 0x13d0c4 | FDE: 0x1ead40 | Size: 4 bytes [PyThread_delete_key]
// Khung tháo gỡ #3071 | Địa chỉ PC: 0x13d0c4 | Địa chỉ FDE: 0x1ead40 | Kích thước: 4 bytes
//   0x13d0c4: 17FC719F  b        #0x59740
static inline uint64_t fde_func_3071_0x13d0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0c4ULL ^ (static_cast<uint64_t>(0x17fc719fULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1ead40ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3072 | PC: 0x13d0c8 | FDE: 0x1ead58 | Size: 8 bytes [PyThread_delete_key_value]
// Khung tháo gỡ #3072 | Địa chỉ PC: 0x13d0c8 | Địa chỉ FDE: 0x1ead58 | Kích thước: 8 bytes
//   0x13d0c8: AA1F03E1  mov      x1, xzr
//   0x13d0cc: 17FC72C1  b        #0x59bd0
static inline uint64_t fde_func_3072_0x13d0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0c8ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fc72c1ULL) ^ 0x1ead58ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3073 | PC: 0x13d0d0 | FDE: 0x1ead70 | Size: 28 bytes [PyThread_set_key_value]
// Khung tháo gỡ #3073 | Địa chỉ PC: 0x13d0d0 | Địa chỉ FDE: 0x1ead70 | Kích thước: 28 bytes
//   0x13d0d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d0d4: 910003FD  mov      x29, sp
//   0x13d0d8: 97FC72BE  bl       #0x59bd0
//   0x13d0dc: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_3073_0x13d0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ead70ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #3074 | PC: 0x13d0ec | FDE: 0x1ead90 | Size: 4 bytes [PyThread_get_key_value]
// Khung tháo gỡ #3074 | Địa chỉ PC: 0x13d0ec | Địa chỉ FDE: 0x1ead90 | Kích thước: 4 bytes
//   0x13d0ec: 17FC7AB9  b        #0x5bbd0
static inline uint64_t fde_func_3074_0x13d0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0ecULL ^ (static_cast<uint64_t>(0x17fc7ab9ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ead90ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3075 | PC: 0x13d0f0 | FDE: 0x1eada8 | Size: 4 bytes [PyThread_ReInitTLS]
// Khung tháo gỡ #3075 | Địa chỉ PC: 0x13d0f0 | Địa chỉ FDE: 0x1eada8 | Kích thước: 4 bytes
//   0x13d0f0: D65F03C0  ret      
static inline uint64_t fde_func_3075_0x13d0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0f0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1eada8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3076 | PC: 0x13d0f4 | FDE: 0x1eadc0 | Size: 76 bytes [PyThread_tss_create]
// Khung tháo gỡ #3076 | Địa chỉ PC: 0x13d0f4 | Địa chỉ FDE: 0x1eadc0 | Kích thước: 76 bytes
//   0x13d0f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d0f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d0fc: 910043FD  add      x29, sp, #0x10
//   0x13d100: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_3076_0x13d0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eadc0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3077 | PC: 0x13d140 | FDE: 0x1eade0 | Size: 48 bytes [PyThread_tss_delete]
// Khung tháo gỡ #3077 | Địa chỉ PC: 0x13d140 | Địa chỉ FDE: 0x1eade0 | Kích thước: 48 bytes
//   0x13d140: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d144: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d148: 910043FD  add      x29, sp, #0x10
//   0x13d14c: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_3077_0x13d140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d140ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eade0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3078 | PC: 0x13d170 | FDE: 0x1eae00 | Size: 32 bytes [PyThread_tss_set]
// Khung tháo gỡ #3078 | Địa chỉ PC: 0x13d170 | Địa chỉ FDE: 0x1eae00 | Kích thước: 32 bytes
//   0x13d170: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d174: 910003FD  mov      x29, sp
//   0x13d178: B9400400  ldr      w0, [x0, #4]
//   0x13d17c: 97FC7295  bl       #0x59bd0
static inline uint64_t fde_func_3078_0x13d170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d170ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eae00ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3079 | PC: 0x13d190 | FDE: 0x1eae20 | Size: 8 bytes [PyThread_tss_get]
// Khung tháo gỡ #3079 | Địa chỉ PC: 0x13d190 | Địa chỉ FDE: 0x1eae20 | Kích thước: 8 bytes
//   0x13d190: B9400400  ldr      w0, [x0, #4]
//   0x13d194: 17FC7A8F  b        #0x5bbd0
static inline uint64_t fde_func_3079_0x13d190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d190ULL ^ (static_cast<uint64_t>(0xb9400400ULL) << 13);
    acc = (acc + a1 + 0x17fc7a8fULL) ^ 0x1eae20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3080 | PC: 0x13d198 | FDE: 0x1eae38 | Size: 40 bytes [PyThread_get_stacksize]
// Khung tháo gỡ #3080 | Địa chỉ PC: 0x13d198 | Địa chỉ FDE: 0x1eae38 | Kích thước: 40 bytes
//   0x13d198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d19c: 910003FD  mov      x29, sp
//   0x13d1a0: D0000608  adrp     x8, #0x1ff000
//   0x13d1a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3080_0x13d198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eae38ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3081 | PC: 0x13d1c0 | FDE: 0x1eae58 | Size: 204 bytes [PyThread_set_stacksize]
// Khung tháo gỡ #3081 | Địa chỉ PC: 0x13d1c0 | Địa chỉ FDE: 0x1eae58 | Kích thước: 204 bytes
//   0x13d1c0: D101C3FF  sub      sp, sp, #0x70
//   0x13d1c4: F90023F5  str      x21, [sp, #0x40]
//   0x13d1c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x13d1cc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_3081_0x13d1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d1c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1eae58ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #3082 | PC: 0x13d28c | FDE: 0x1eae78 | Size: 32 bytes [PyThread_tss_alloc]
// Khung tháo gỡ #3082 | Địa chỉ PC: 0x13d28c | Địa chỉ FDE: 0x1eae78 | Kích thước: 32 bytes
//   0x13d28c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d290: 910003FD  mov      x29, sp
//   0x13d294: 52800100  mov      w0, #8
//   0x13d298: 97FC6F06  bl       #0x58eb0
static inline uint64_t fde_func_3082_0x13d28c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d28cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eae78ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3083 | PC: 0x13d2ac | FDE: 0x1eae98 | Size: 60 bytes [PyThread_tss_free]
// Khung tháo gỡ #3083 | Địa chỉ PC: 0x13d2ac | Địa chỉ FDE: 0x1eae98 | Kích thước: 60 bytes
//   0x13d2ac: B40001C0  cbz      x0, #0x13d2e4
//   0x13d2b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d2b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d2b8: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_3083_0x13d2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d2acULL ^ (static_cast<uint64_t>(0xb40001c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1eae98ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3084 | PC: 0x13d2e8 | FDE: 0x1eaeb8 | Size: 8 bytes [PyThread_tss_is_created]
// Khung tháo gỡ #3084 | Địa chỉ PC: 0x13d2e8 | Địa chỉ FDE: 0x1eaeb8 | Kích thước: 8 bytes
//   0x13d2e8: B9400000  ldr      w0, [x0]
//   0x13d2ec: D65F03C0  ret      
static inline uint64_t fde_func_3084_0x13d2e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d2e8ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1eaeb8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3085 | PC: 0x13d2f0 | FDE: 0x1eaed0 | Size: 180 bytes [PyThread_GetInfo]
// Khung tháo gỡ #3085 | Địa chỉ PC: 0x13d2f0 | Địa chỉ FDE: 0x1eaed0 | Kích thước: 180 bytes
//   0x13d2f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d2f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d2f8: 910043FD  add      x29, sp, #0x10
//   0x13d2fc: 90000748  adrp     x8, #0x225000
static inline uint64_t fde_func_3085_0x13d2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d2f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eaed0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3086 | PC: 0x13d3a4 | FDE: 0x1eaef0 | Size: 172 bytes
// Khung tháo gỡ #3086 | Địa chỉ PC: 0x13d3a4 | Địa chỉ FDE: 0x1eaef0 | Kích thước: 172 bytes
//   0x13d3a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13d3a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d3ac: 910043FD  add      x29, sp, #0x10
//   0x13d3b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3086_0x13d3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d3a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eaef0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3087 | PC: 0x13d450 | FDE: 0x1eaf10 | Size: 88 bytes
// Khung tháo gỡ #3087 | Địa chỉ PC: 0x13d450 | Địa chỉ FDE: 0x1eaf10 | Kích thước: 88 bytes
//   0x13d450: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x13d454: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13d458: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13d45c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3087_0x13d450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d450ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eaf10ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3088 | PC: 0x13d4a8 | FDE: 0x1eaf30 | Size: 108 bytes
// Khung tháo gỡ #3088 | Địa chỉ PC: 0x13d4a8 | Địa chỉ FDE: 0x1eaf30 | Kích thước: 108 bytes
//   0x13d4a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d4ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d4b0: 910043FD  add      x29, sp, #0x10
//   0x13d4b4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3088_0x13d4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d4a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eaf30ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3089 | PC: 0x13d514 | FDE: 0x1eaf50 | Size: 256 bytes
// Khung tháo gỡ #3089 | Địa chỉ PC: 0x13d514 | Địa chỉ FDE: 0x1eaf50 | Kích thước: 256 bytes
//   0x13d514: D10203FF  sub      sp, sp, #0x80
//   0x13d518: F9001BF9  str      x25, [sp, #0x30]
//   0x13d51c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x13d520: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_3089_0x13d514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d514ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1eaf50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3090 | PC: 0x13d714 | FDE: 0x1eaf78 | Size: 208 bytes [_PyTraceBack_FromFrame]
// Khung tháo gỡ #3090 | Địa chỉ PC: 0x13d714 | Địa chỉ FDE: 0x1eaf78 | Kích thước: 208 bytes
//   0x13d714: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x13d718: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x13d71c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13d720: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3090_0x13d714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d714ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eaf78ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #3091 | PC: 0x13d7e4 | FDE: 0x1eafa0 | Size: 256 bytes [PyTraceBack_Here]
// Khung tháo gỡ #3091 | Địa chỉ PC: 0x13d7e4 | Địa chỉ FDE: 0x1eafa0 | Kích thước: 256 bytes
//   0x13d7e4: D10183FF  sub      sp, sp, #0x60
//   0x13d7e8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13d7ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13d7f0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3091_0x13d7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d7e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1eafa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3092 | PC: 0x13d920 | FDE: 0x1eafc8 | Size: 256 bytes [_PyTraceback_Add]
// Khung tháo gỡ #3092 | Địa chỉ PC: 0x13d920 | Địa chỉ FDE: 0x1eafc8 | Kích thước: 256 bytes
//   0x13d920: D10183FF  sub      sp, sp, #0x60
//   0x13d924: F90013F7  str      x23, [sp, #0x20]
//   0x13d928: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13d92c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3092_0x13d920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d920ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1eafc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3093 | PC: 0x13da60 | FDE: 0x1eaff0 | Size: 256 bytes [_Py_DisplaySourceLine]
// Khung tháo gỡ #3093 | Địa chỉ PC: 0x13da60 | Địa chỉ FDE: 0x1eaff0 | Kích thước: 256 bytes
//   0x13da60: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x13da64: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x13da68: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13da6c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3093_0x13da60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13da60ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1eaff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3094 | PC: 0x13e108 | FDE: 0x1eb020 | Size: 256 bytes [PyTraceBack_Print]
// Khung tháo gỡ #3094 | Địa chỉ PC: 0x13e108 | Địa chỉ FDE: 0x1eb020 | Kích thước: 256 bytes
//   0x13e108: D10203FF  sub      sp, sp, #0x80
//   0x13e10c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x13e110: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x13e114: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3094_0x13e108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e108ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1eb020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3095 | PC: 0x13e4d0 | FDE: 0x1eb050 | Size: 136 bytes [_Py_DumpDecimal]
// Khung tháo gỡ #3095 | Địa chỉ PC: 0x13e4d0 | Địa chỉ FDE: 0x1eb050 | Kích thước: 136 bytes
//   0x13e4d0: D10103FF  sub      sp, sp, #0x40
//   0x13e4d4: F90013F3  str      x19, [sp, #0x20]
//   0x13e4d8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x13e4dc: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3095_0x13e4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e4d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1eb050ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #3096 | PC: 0x13e558 | FDE: 0x1eb070 | Size: 144 bytes [_Py_DumpHexadecimal]
// Khung tháo gỡ #3096 | Địa chỉ PC: 0x13e558 | Địa chỉ FDE: 0x1eb070 | Kích thước: 144 bytes
//   0x13e558: D10103FF  sub      sp, sp, #0x40
//   0x13e55c: F90013F3  str      x19, [sp, #0x20]
//   0x13e560: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x13e564: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3096_0x13e558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e558ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1eb070ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3097 | PC: 0x13e5e8 | FDE: 0x1eb090 | Size: 256 bytes [_Py_DumpASCII]
// Khung tháo gỡ #3097 | Địa chỉ PC: 0x13e5e8 | Địa chỉ FDE: 0x1eb090 | Kích thước: 256 bytes
//   0x13e5e8: D10283FF  sub      sp, sp, #0xa0
//   0x13e5ec: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x13e5f0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x13e5f4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_3097_0x13e5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e5e8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1eb090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3098 | PC: 0x13e894 | FDE: 0x1eb0c0 | Size: 8 bytes [_Py_DumpTraceback]
// Khung tháo gỡ #3098 | Địa chỉ PC: 0x13e894 | Địa chỉ FDE: 0x1eb0c0 | Kích thước: 8 bytes
//   0x13e894: 52800022  mov      w2, #1
//   0x13e898: 14000001  b        #0x13e89c
static inline uint64_t fde_func_3098_0x13e894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e894ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1eb0c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3099 | PC: 0x13e89c | FDE: 0x1eb0d8 | Size: 256 bytes
// Khung tháo gỡ #3099 | Địa chỉ PC: 0x13e89c | Địa chỉ FDE: 0x1eb0d8 | Kích thước: 256 bytes
//   0x13e89c: D10243FF  sub      sp, sp, #0x90
//   0x13e8a0: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x13e8a4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x13e8a8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3099_0x13e89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e89cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1eb0d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3100 | PC: 0x13ec38 | FDE: 0x1eb108 | Size: 56 bytes [BD_Py_DumpTraceback]
// Khung tháo gỡ #3100 | Địa chỉ PC: 0x13ec38 | Địa chỉ FDE: 0x1eb108 | Kích thước: 56 bytes
//   0x13ec38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13ec3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13ec40: 910043FD  add      x29, sp, #0x10
//   0x13ec44: 97FC70A3  bl       #0x5aed0
static inline uint64_t fde_func_3100_0x13ec38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ec38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb108ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3101 | PC: 0x13ec70 | FDE: 0x1eb128 | Size: 256 bytes [_Py_DumpTracebackThreads]
// Khung tháo gỡ #3101 | Địa chỉ PC: 0x13ec70 | Địa chỉ FDE: 0x1eb128 | Kích thước: 256 bytes
//   0x13ec70: D10243FF  sub      sp, sp, #0x90
//   0x13ec74: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x13ec78: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x13ec7c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3101_0x13ec70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ec70ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1eb128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3102 | PC: 0x13eeb8 | FDE: 0x1eb158 | Size: 44 bytes
// Khung tháo gỡ #3102 | Địa chỉ PC: 0x13eeb8 | Địa chỉ FDE: 0x1eb158 | Kích thước: 44 bytes
//   0x13eeb8: B0000400  adrp     x0, #0x1bf000
//   0x13eebc: B0000401  adrp     x1, #0x1bf000
//   0x13eec0: B0000402  adrp     x2, #0x1bf000
//   0x13eec4: B0000403  adrp     x3, #0x1bf000
static inline uint64_t fde_func_3102_0x13eeb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13eeb8ULL ^ (static_cast<uint64_t>(0xb0000400ULL) << 13);
    acc = (acc + a1 + 0xb0000401ULL) ^ 0x1eb158ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3103 | PC: 0x13eee4 | FDE: 0x1eb170 | Size: 36 bytes
// Khung tháo gỡ #3103 | Địa chỉ PC: 0x13eee4 | Địa chỉ FDE: 0x1eb170 | Kích thước: 36 bytes
//   0x13eee4: F9400808  ldr      x8, [x0, #0x10]
//   0x13eee8: B0000609  adrp     x9, #0x1ff000
//   0x13eeec: F945F129  ldr      x9, [x9, #0xbe0]
//   0x13eef0: F100011F  cmp      x8, #0
static inline uint64_t fde_func_3103_0x13eee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13eee4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb0000609ULL) ^ 0x1eb170ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3104 | PC: 0x13ef08 | FDE: 0x1eb188 | Size: 236 bytes
// Khung tháo gỡ #3104 | Địa chỉ PC: 0x13ef08 | Địa chỉ FDE: 0x1eb188 | Kích thước: 236 bytes
//   0x13ef08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13ef0c: 910003FD  mov      x29, sp
//   0x13ef10: B4000241  cbz      x1, #0x13ef58
//   0x13ef14: B0000608  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3104_0x13ef08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ef08ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eb188ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3105 | PC: 0x13eff4 | FDE: 0x1eb1a8 | Size: 256 bytes [_PyOS_ResetGetOpt]
// Khung tháo gỡ #3105 | Địa chỉ PC: 0x13eff4 | Địa chỉ FDE: 0x1eb1a8 | Kích thước: 256 bytes
//   0x13eff4: B0000608  adrp     x8, #0x1ff000
//   0x13eff8: B000060A  adrp     x10, #0x1ff000
//   0x13effc: 1060002B  adr      x11, #0x1ff000
//   0x13f000: F9434108  ldr      x8, [x8, #0x680]
static inline uint64_t fde_func_3105_0x13eff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13eff4ULL ^ (static_cast<uint64_t>(0xb0000608ULL) << 13);
    acc = (acc + a1 + 0xb000060aULL) ^ 0x1eb1a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3106 | PC: 0x140030 | FDE: 0x1eb1c0 | Size: 256 bytes [_PyOS_GetOpt]
// Khung tháo gỡ #3106 | Địa chỉ PC: 0x140030 | Địa chỉ FDE: 0x1eb1c0 | Kích thước: 256 bytes
//   0x140030: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x140034: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x140038: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14003c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3106_0x140030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140030ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb1c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3107 | PC: 0x140380 | FDE: 0x1eb1e8 | Size: 160 bytes [PyOS_mystrnicmp]
// Khung tháo gỡ #3107 | Địa chỉ PC: 0x140380 | Địa chỉ FDE: 0x1eb1e8 | Kích thước: 160 bytes
//   0x140380: B40004C2  cbz      x2, #0x140418
//   0x140384: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x140388: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x14038c: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_3107_0x140380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140380ULL ^ (static_cast<uint64_t>(0xb40004c2ULL) << 13);
    acc = (acc + a1 + 0xf81c0ff7ULL) ^ 0x1eb1e8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3108 | PC: 0x140420 | FDE: 0x1eb210 | Size: 140 bytes [PyOS_mystricmp]
// Khung tháo gỡ #3108 | Địa chỉ PC: 0x140420 | Địa chỉ FDE: 0x1eb210 | Kích thước: 140 bytes
//   0x140420: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x140424: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x140428: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14042c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3108_0x140420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140420ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb210ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #3109 | PC: 0x1404ac | FDE: 0x1eb238 | Size: 256 bytes [_Py_parse_inf_or_nan]
// Khung tháo gỡ #3109 | Địa chỉ PC: 0x1404ac | Địa chỉ FDE: 0x1eb238 | Kích thước: 256 bytes
//   0x1404ac: 39400008  ldrb     w8, [x0]
//   0x1404b0: 7100AD1F  cmp      w8, #0x2b
//   0x1404b4: 540000C0  b.eq     #0x1404cc
//   0x1404b8: 7100B51F  cmp      w8, #0x2d
static inline uint64_t fde_func_3109_0x1404ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1404acULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x7100ad1fULL) ^ 0x1eb238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3110 | PC: 0x1405cc | FDE: 0x1eb250 | Size: 256 bytes [PyOS_string_to_double]
// Khung tháo gỡ #3110 | Địa chỉ PC: 0x1405cc | Địa chỉ FDE: 0x1eb250 | Kích thước: 256 bytes
//   0x1405cc: D10243FF  sub      sp, sp, #0x90
//   0x1405d0: FD0013E8  str      d8, [sp, #0x20]
//   0x1405d4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1405d8: A90467FA  stp      x26, x25, [sp, #0x40]
static inline uint64_t fde_func_3110_0x1405cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1405ccULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x1eb250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3111 | PC: 0x14096c | FDE: 0x1eb280 | Size: 256 bytes [_Py_string_to_number_with_underscores]
// Khung tháo gỡ #3111 | Địa chỉ PC: 0x14096c | Địa chỉ FDE: 0x1eb280 | Kích thước: 256 bytes
//   0x14096c: D10143FF  sub      sp, sp, #0x50
//   0x140970: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x140974: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x140978: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3111_0x14096c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14096cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3112 | PC: 0x140ad4 | FDE: 0x1eb2a8 | Size: 256 bytes [PyOS_double_to_string]
// Khung tháo gỡ #3112 | Địa chỉ PC: 0x140ad4 | Địa chỉ FDE: 0x1eb2a8 | Kích thước: 256 bytes
//   0x140ad4: D10503FF  sub      sp, sp, #0x140
//   0x140ad8: FD006BE8  str      d8, [sp, #0xd0]
//   0x140adc: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x140ae0: A90F67FA  stp      x26, x25, [sp, #0xf0]
static inline uint64_t fde_func_3112_0x140ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140ad4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xfd006be8ULL) ^ 0x1eb2a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3113 | PC: 0x141030 | FDE: 0x1eb2d8 | Size: 196 bytes
// Khung tháo gỡ #3113 | Địa chỉ PC: 0x141030 | Địa chỉ FDE: 0x1eb2d8 | Kích thước: 196 bytes
//   0x141030: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x141034: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x141038: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14103c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3113_0x141030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141030ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb2d8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3114 | PC: 0x1410f4 | FDE: 0x1eb2f8 | Size: 256 bytes
// Khung tháo gỡ #3114 | Địa chỉ PC: 0x1410f4 | Địa chỉ FDE: 0x1eb2f8 | Kích thước: 256 bytes
//   0x1410f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1410f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1410fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x141100: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3114_0x1410f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1410f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb2f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3115 | PC: 0x141234 | FDE: 0x1eb320 | Size: 168 bytes [_Py_strhex]
// Khung tháo gỡ #3115 | Địa chỉ PC: 0x141234 | Địa chỉ FDE: 0x1eb320 | Kích thước: 168 bytes
//   0x141234: 92F80008  mov      x8, #0x3fffffffffffffff
//   0x141238: EB08003F  cmp      x1, x8
//   0x14123c: 5400020A  b.ge     #0x14127c
//   0x141240: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_3115_0x141234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141234ULL ^ (static_cast<uint64_t>(0x92f80008ULL) << 13);
    acc = (acc + a1 + 0xeb08003fULL) ^ 0x1eb320ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #3116 | PC: 0x1412dc | FDE: 0x1eb340 | Size: 256 bytes
// Khung tháo gỡ #3116 | Địa chỉ PC: 0x1412dc | Địa chỉ FDE: 0x1eb340 | Kích thước: 256 bytes
//   0x1412dc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1412e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1412e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1412e8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3116_0x1412dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1412dcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3117 | PC: 0x141694 | FDE: 0x1eb368 | Size: 128 bytes [_Py_strhex_bytes]
// Khung tháo gỡ #3117 | Địa chỉ PC: 0x141694 | Địa chỉ FDE: 0x1eb368 | Kích thước: 128 bytes
//   0x141694: 92F80008  mov      x8, #0x3fffffffffffffff
//   0x141698: EB08003F  cmp      x1, x8
//   0x14169c: 540003AA  b.ge     #0x141710
//   0x1416a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_3117_0x141694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141694ULL ^ (static_cast<uint64_t>(0x92f80008ULL) << 13);
    acc = (acc + a1 + 0xeb08003fULL) ^ 0x1eb368ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3118 | PC: 0x141714 | FDE: 0x1eb388 | Size: 8 bytes [_Py_strhex_with_sep]
// Khung tháo gỡ #3118 | Địa chỉ PC: 0x141714 | Địa chỉ FDE: 0x1eb388 | Kích thước: 8 bytes
//   0x141714: 2A1F03E4  mov      w4, wzr
//   0x141718: 17FFFEF1  b        #0x1412dc
static inline uint64_t fde_func_3118_0x141714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141714ULL ^ (static_cast<uint64_t>(0x2a1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fffef1ULL) ^ 0x1eb388ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3119 | PC: 0x14171c | FDE: 0x1eb3a0 | Size: 8 bytes [_Py_strhex_bytes_with_sep]
// Khung tháo gỡ #3119 | Địa chỉ PC: 0x14171c | Địa chỉ FDE: 0x1eb3a0 | Kích thước: 8 bytes
//   0x14171c: 52800024  mov      w4, #1
//   0x141720: 17FFFEEF  b        #0x1412dc
static inline uint64_t fde_func_3119_0x14171c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14171cULL ^ (static_cast<uint64_t>(0x52800024ULL) << 13);
    acc = (acc + a1 + 0x17fffeefULL) ^ 0x1eb3a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3120 | PC: 0x141724 | FDE: 0x1eb3b8 | Size: 256 bytes [_PyUnicode_FormatAdvancedWriter]
// Khung tháo gỡ #3120 | Địa chỉ PC: 0x141724 | Địa chỉ FDE: 0x1eb3b8 | Kích thước: 256 bytes
//   0x141724: D10203FF  sub      sp, sp, #0x80
//   0x141728: F9001BF9  str      x25, [sp, #0x30]
//   0x14172c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x141730: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_3120_0x141724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141724ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1eb3b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3121 | PC: 0x141a78 | FDE: 0x1eb3e0 | Size: 256 bytes
// Khung tháo gỡ #3121 | Địa chỉ PC: 0x141a78 | Địa chỉ FDE: 0x1eb3e0 | Kích thước: 256 bytes
//   0x141a78: D10243FF  sub      sp, sp, #0x90
//   0x141a7c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x141a80: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x141a84: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3121_0x141a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141a78ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1eb3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3122 | PC: 0x142224 | FDE: 0x1eb410 | Size: 256 bytes [_PyLong_FormatAdvancedWriter]
// Khung tháo gỡ #3122 | Địa chỉ PC: 0x142224 | Địa chỉ FDE: 0x1eb410 | Kích thước: 256 bytes
//   0x142224: D104C3FF  sub      sp, sp, #0x130
//   0x142228: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x14222c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x142230: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_3122_0x142224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142224ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1eb410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3123 | PC: 0x142770 | FDE: 0x1eb440 | Size: 256 bytes
// Khung tháo gỡ #3123 | Địa chỉ PC: 0x142770 | Địa chỉ FDE: 0x1eb440 | Kích thước: 256 bytes
//   0x142770: D10403FF  sub      sp, sp, #0x100
//   0x142774: FD0053E8  str      d8, [sp, #0xa0]
//   0x142778: F90057FB  str      x27, [sp, #0xa8]
//   0x14277c: A90B67FA  stp      x26, x25, [sp, #0xb0]
static inline uint64_t fde_func_3123_0x142770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142770ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xfd0053e8ULL) ^ 0x1eb440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3124 | PC: 0x142bd8 | FDE: 0x1eb470 | Size: 256 bytes [_PyFloat_FormatAdvancedWriter]
// Khung tháo gỡ #3124 | Địa chỉ PC: 0x142bd8 | Địa chỉ FDE: 0x1eb470 | Kích thước: 256 bytes
//   0x142bd8: D10143FF  sub      sp, sp, #0x50
//   0x142bdc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x142be0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x142be4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_3124_0x142bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142bd8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1eb470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3125 | PC: 0x142cf0 | FDE: 0x1eb490 | Size: 256 bytes [_PyComplex_FormatAdvancedWriter]
// Khung tháo gỡ #3125 | Địa chỉ PC: 0x142cf0 | Địa chỉ FDE: 0x1eb490 | Kích thước: 256 bytes
//   0x142cf0: 6DB923E9  stp      d9, d8, [sp, #-0x70]!
//   0x142cf4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x142cf8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x142cfc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3125_0x142cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142cf0ULL ^ (static_cast<uint64_t>(0x6db923e9ULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1eb490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3126 | PC: 0x143694 | FDE: 0x1eb4c8 | Size: 256 bytes
// Khung tháo gỡ #3126 | Địa chỉ PC: 0x143694 | Địa chỉ FDE: 0x1eb4c8 | Kích thước: 256 bytes
//   0x143694: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x143698: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14369c: 910043FD  add      x29, sp, #0x10
//   0x1436a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_3126_0x143694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143694ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3127 | PC: 0x1437c4 | FDE: 0x1eb4e8 | Size: 256 bytes
// Khung tháo gỡ #3127 | Địa chỉ PC: 0x1437c4 | Địa chỉ FDE: 0x1eb4e8 | Kích thước: 256 bytes
//   0x1437c4: D101C3FF  sub      sp, sp, #0x70
//   0x1437c8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1437cc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1437d0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3127_0x1437c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1437c4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1eb4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3128 | PC: 0x143aa4 | FDE: 0x1eb518 | Size: 256 bytes
// Khung tháo gỡ #3128 | Địa chỉ PC: 0x143aa4 | Địa chỉ FDE: 0x1eb518 | Kích thước: 256 bytes
//   0x143aa4: D10203FF  sub      sp, sp, #0x80
//   0x143aa8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x143aac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x143ab0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3128_0x143aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143aa4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1eb518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3129 | PC: 0x143e10 | FDE: 0x1eb548 | Size: 140 bytes [_Py_device_encoding]
// Khung tháo gỡ #3129 | Địa chỉ PC: 0x143e10 | Địa chỉ FDE: 0x1eb548 | Kích thước: 140 bytes
//   0x143e10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x143e14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x143e18: 910043FD  add      x29, sp, #0x10
//   0x143e1c: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_3129_0x143e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143e10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb548ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #3130 | PC: 0x143e9c | FDE: 0x1eb568 | Size: 80 bytes [_Py_GetLocaleEncodingObject]
// Khung tháo gỡ #3130 | Địa chỉ PC: 0x143e9c | Địa chỉ FDE: 0x1eb568 | Kích thước: 80 bytes
//   0x143e9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x143ea0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x143ea4: 910043FD  add      x29, sp, #0x10
//   0x143ea8: B00003E0  adrp     x0, #0x1c0000
static inline uint64_t fde_func_3130_0x143e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143e9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb568ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3131 | PC: 0x143eec | FDE: 0x1eb588 | Size: 8 bytes [_Py_GetForceASCII]
// Khung tháo gỡ #3131 | Địa chỉ PC: 0x143eec | Địa chỉ FDE: 0x1eb588 | Kích thước: 8 bytes
//   0x143eec: 2A1F03E0  mov      w0, wzr
//   0x143ef0: D65F03C0  ret      
static inline uint64_t fde_func_3131_0x143eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143eecULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1eb588ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3132 | PC: 0x143ef4 | FDE: 0x1eb5a0 | Size: 4 bytes [_Py_ResetForceASCII]
// Khung tháo gỡ #3132 | Địa chỉ PC: 0x143ef4 | Địa chỉ FDE: 0x1eb5a0 | Kích thước: 4 bytes
//   0x143ef4: D65F03C0  ret      
static inline uint64_t fde_func_3132_0x143ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143ef4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81c0ff7ULL) ^ 0x1eb5a0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3133 | PC: 0x143ef8 | FDE: 0x1eb5b8 | Size: 88 bytes [_Py_DecodeLocaleEx]
// Khung tháo gỡ #3133 | Địa chỉ PC: 0x143ef8 | Địa chỉ FDE: 0x1eb5b8 | Kích thước: 88 bytes
//   0x143ef8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x143efc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x143f00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x143f04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3133_0x143ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143ef8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb5b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3134 | PC: 0x143f50 | FDE: 0x1eb5e0 | Size: 152 bytes [Py_DecodeLocale]
// Khung tháo gỡ #3134 | Địa chỉ PC: 0x143f50 | Địa chỉ FDE: 0x1eb5e0 | Kích thước: 152 bytes
//   0x143f50: D10103FF  sub      sp, sp, #0x40
//   0x143f54: F9000BF5  str      x21, [sp, #0x10]
//   0x143f58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x143f5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3134_0x143f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143f50ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1eb5e0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3135 | PC: 0x143fe8 | FDE: 0x1eb600 | Size: 124 bytes [Py_EncodeLocale]
// Khung tháo gỡ #3135 | Địa chỉ PC: 0x143fe8 | Địa chỉ FDE: 0x1eb600 | Kích thước: 124 bytes
//   0x143fe8: D100C3FF  sub      sp, sp, #0x30
//   0x143fec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x143ff0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x143ff4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3135_0x143fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143fe8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb600ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #3136 | PC: 0x144064 | FDE: 0x1eb620 | Size: 124 bytes [_Py_EncodeLocaleRaw]
// Khung tháo gỡ #3136 | Địa chỉ PC: 0x144064 | Địa chỉ FDE: 0x1eb620 | Kích thước: 124 bytes
//   0x144064: D100C3FF  sub      sp, sp, #0x30
//   0x144068: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14406c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144070: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3136_0x144064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144064ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb620ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #3137 | PC: 0x1440e0 | FDE: 0x1eb640 | Size: 8 bytes [_Py_EncodeLocaleEx]
// Khung tháo gỡ #3137 | Địa chỉ PC: 0x1440e0 | Địa chỉ FDE: 0x1eb640 | Kích thước: 8 bytes
//   0x1440e0: 52800024  mov      w4, #1
//   0x1440e4: 17FC65CB  b        #0x5d810
static inline uint64_t fde_func_3137_0x1440e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440e0ULL ^ (static_cast<uint64_t>(0x52800024ULL) << 13);
    acc = (acc + a1 + 0x17fc65cbULL) ^ 0x1eb640ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3138 | PC: 0x1440e8 | FDE: 0x1eb658 | Size: 12 bytes [_Py_GetLocaleEncoding]
// Khung tháo gỡ #3138 | Địa chỉ PC: 0x1440e8 | Địa chỉ FDE: 0x1eb658 | Kích thước: 12 bytes
//   0x1440e8: 900003E0  adrp     x0, #0x1c0000
//   0x1440ec: 91068000  add      x0, x0, #0x1a0
//   0x1440f0: 17FC625C  b        #0x5ca60
static inline uint64_t fde_func_3138_0x1440e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440e8ULL ^ (static_cast<uint64_t>(0x900003e0ULL) << 13);
    acc = (acc + a1 + 0x91068000ULL) ^ 0x1eb658ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3139 | PC: 0x1440f4 | FDE: 0x1eb670 | Size: 4 bytes [_Py_fstat_noraise]
// Khung tháo gỡ #3139 | Địa chỉ PC: 0x1440f4 | Địa chỉ FDE: 0x1eb670 | Kích thước: 4 bytes
//   0x1440f4: 17FC65CF  b        #0x5d830
static inline uint64_t fde_func_3139_0x1440f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440f4ULL ^ (static_cast<uint64_t>(0x17fc65cfULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x1eb670ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3140 | PC: 0x1440f8 | FDE: 0x1eb688 | Size: 104 bytes [_Py_fstat]
// Khung tháo gỡ #3140 | Địa chỉ PC: 0x1440f8 | Địa chỉ FDE: 0x1eb688 | Kích thước: 104 bytes
//   0x1440f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1440fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x144100: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144104: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3140_0x1440f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440f8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb688ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3141 | PC: 0x144160 | FDE: 0x1eb6a8 | Size: 184 bytes [_Py_stat]
// Khung tháo gỡ #3141 | Địa chỉ PC: 0x144160 | Địa chỉ FDE: 0x1eb6a8 | Kích thước: 184 bytes
//   0x144160: D10103FF  sub      sp, sp, #0x40
//   0x144164: F9000BF5  str      x21, [sp, #0x10]
//   0x144168: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14416c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3141_0x144160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144160ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1eb6a8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #3142 | PC: 0x144218 | FDE: 0x1eb6c8 | Size: 72 bytes [_Py_get_inheritable]
// Khung tháo gỡ #3142 | Địa chỉ PC: 0x144218 | Địa chỉ FDE: 0x1eb6c8 | Kích thước: 72 bytes
//   0x144218: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14421c: 910003FD  mov      x29, sp
//   0x144220: 52800021  mov      w1, #1
//   0x144224: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_3142_0x144218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144218ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eb6c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3143 | PC: 0x144260 | FDE: 0x1eb6e8 | Size: 12 bytes [_Py_set_inheritable]
// Khung tháo gỡ #3143 | Địa chỉ PC: 0x144260 | Địa chỉ FDE: 0x1eb6e8 | Kích thước: 12 bytes
//   0x144260: AA0203E3  mov      x3, x2
//   0x144264: 52800022  mov      w2, #1
//   0x144268: 14000001  b        #0x14426c
static inline uint64_t fde_func_3143_0x144260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144260ULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x1eb6e8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3144 | PC: 0x14426c | FDE: 0x1eb700 | Size: 256 bytes
// Khung tháo gỡ #3144 | Địa chỉ PC: 0x14426c | Địa chỉ FDE: 0x1eb700 | Kích thước: 256 bytes
//   0x14426c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x144270: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x144274: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144278: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3144_0x14426c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14426cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3145 | PC: 0x14439c | FDE: 0x1eb728 | Size: 180 bytes [_Py_set_inheritable_async_safe]
// Khung tháo gỡ #3145 | Địa chỉ PC: 0x14439c | Địa chỉ FDE: 0x1eb728 | Kích thước: 180 bytes
//   0x14439c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1443a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1443a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1443a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3145_0x14439c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14439cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb728ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3146 | PC: 0x144450 | FDE: 0x1eb748 | Size: 8 bytes [_Py_open]
// Khung tháo gỡ #3146 | Địa chỉ PC: 0x144450 | Địa chỉ FDE: 0x1eb748 | Kích thước: 8 bytes
//   0x144450: 52800022  mov      w2, #1
//   0x144454: 14000001  b        #0x144458
static inline uint64_t fde_func_3146_0x144450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144450ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1eb748ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3147 | PC: 0x144458 | FDE: 0x1eb760 | Size: 256 bytes
// Khung tháo gỡ #3147 | Địa chỉ PC: 0x144458 | Địa chỉ FDE: 0x1eb760 | Kích thước: 256 bytes
//   0x144458: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x14445c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144460: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144464: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3147_0x144458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144458ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3148 | PC: 0x144598 | FDE: 0x1eb788 | Size: 168 bytes [_Py_open_noraise]
// Khung tháo gỡ #3148 | Địa chỉ PC: 0x144598 | Địa chỉ FDE: 0x1eb788 | Kích thước: 168 bytes
//   0x144598: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14459c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1445a0: 910043FD  add      x29, sp, #0x10
//   0x1445a4: 320D0021  orr      w1, w1, #0x80000
static inline uint64_t fde_func_3148_0x144598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144598ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb788ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #3149 | PC: 0x144640 | FDE: 0x1eb7a8 | Size: 256 bytes [_Py_wfopen]
// Khung tháo gỡ #3149 | Địa chỉ PC: 0x144640 | Địa chỉ FDE: 0x1eb7a8 | Kích thước: 256 bytes
//   0x144640: D10143FF  sub      sp, sp, #0x50
//   0x144644: F90013F5  str      x21, [sp, #0x20]
//   0x144648: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x14464c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3149_0x144640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144640ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1eb7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3150 | PC: 0x14476c | FDE: 0x1eb7c8 | Size: 256 bytes [_Py_fopen_obj]
// Khung tháo gỡ #3150 | Địa chỉ PC: 0x14476c | Địa chỉ FDE: 0x1eb7c8 | Kích thước: 256 bytes
//   0x14476c: D10143FF  sub      sp, sp, #0x50
//   0x144770: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x144774: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x144778: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3150_0x14476c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14476cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb7c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3151 | PC: 0x1448dc | FDE: 0x1eb7f0 | Size: 184 bytes [_Py_read]
// Khung tháo gỡ #3151 | Địa chỉ PC: 0x1448dc | Địa chỉ FDE: 0x1eb7f0 | Kích thước: 184 bytes
//   0x1448dc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1448e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1448e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1448e8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3151_0x1448dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1448dcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb7f0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #3152 | PC: 0x144994 | FDE: 0x1eb818 | Size: 8 bytes [_Py_write]
// Khung tháo gỡ #3152 | Địa chỉ PC: 0x144994 | Địa chỉ FDE: 0x1eb818 | Kích thước: 8 bytes
//   0x144994: 52800023  mov      w3, #1
//   0x144998: 14000001  b        #0x14499c
static inline uint64_t fde_func_3152_0x144994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144994ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1eb818ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3153 | PC: 0x14499c | FDE: 0x1eb830 | Size: 248 bytes
// Khung tháo gỡ #3153 | Địa chỉ PC: 0x14499c | Địa chỉ FDE: 0x1eb830 | Kích thước: 248 bytes
//   0x14499c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1449a0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1449a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1449a8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3153_0x14499c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14499cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb830ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3154 | PC: 0x144a94 | FDE: 0x1eb860 | Size: 104 bytes [_Py_write_noraise]
// Khung tháo gỡ #3154 | Địa chỉ PC: 0x144a94 | Địa chỉ FDE: 0x1eb860 | Kích thước: 104 bytes
//   0x144a94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x144a98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x144a9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144aa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3154_0x144a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144a94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb860ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3155 | PC: 0x144afc | FDE: 0x1eb888 | Size: 256 bytes [_Py_wreadlink]
// Khung tháo gỡ #3155 | Địa chỉ PC: 0x144afc | Địa chỉ FDE: 0x1eb888 | Kích thước: 256 bytes
//   0x144afc: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x144b00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144b04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144b08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3155_0x144afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144afcULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3156 | PC: 0x144c50 | FDE: 0x1eb8b0 | Size: 256 bytes [_Py_wrealpath]
// Khung tháo gỡ #3156 | Địa chỉ PC: 0x144c50 | Địa chỉ FDE: 0x1eb8b0 | Kích thước: 256 bytes
//   0x144c50: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x144c54: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144c58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144c5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3156_0x144c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144c50ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb8b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3157 | PC: 0x144d7c | FDE: 0x1eb8d8 | Size: 16 bytes [_Py_isabs]
// Khung tháo gỡ #3157 | Địa chỉ PC: 0x144d7c | Địa chỉ FDE: 0x1eb8d8 | Kích thước: 16 bytes
//   0x144d7c: B9400008  ldr      w8, [x0]
//   0x144d80: 7100BD1F  cmp      w8, #0x2f
//   0x144d84: 1A9F17E0  cset     w0, eq
//   0x144d88: D65F03C0  ret      
static inline uint64_t fde_func_3157_0x144d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144d7cULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100bd1fULL) ^ 0x1eb8d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3158 | PC: 0x144d8c | FDE: 0x1eb8f0 | Size: 256 bytes [_Py_abspath]
// Khung tháo gỡ #3158 | Địa chỉ PC: 0x144d8c | Địa chỉ FDE: 0x1eb8f0 | Kích thước: 256 bytes
//   0x144d8c: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x144d90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x144d94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x144d98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3158_0x144d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144d8cULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3159 | PC: 0x144ebc | FDE: 0x1eb918 | Size: 236 bytes [_Py_wgetcwd]
// Khung tháo gỡ #3159 | Địa chỉ PC: 0x144ebc | Địa chỉ FDE: 0x1eb918 | Kích thước: 236 bytes
//   0x144ebc: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x144ec0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144ec4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144ec8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3159_0x144ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144ebcULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb918ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3160 | PC: 0x144fa8 | FDE: 0x1eb940 | Size: 92 bytes [_Py_dup]
// Khung tháo gỡ #3160 | Địa chỉ PC: 0x144fa8 | Địa chỉ FDE: 0x1eb940 | Kích thước: 92 bytes
//   0x144fa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x144fac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x144fb0: 910043FD  add      x29, sp, #0x10
//   0x144fb4: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_3160_0x144fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144fa8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb940ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3161 | PC: 0x145004 | FDE: 0x1eb960 | Size: 68 bytes [_Py_get_blocking]
// Khung tháo gỡ #3161 | Địa chỉ PC: 0x145004 | Địa chỉ FDE: 0x1eb960 | Kích thước: 68 bytes
//   0x145004: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x145008: 910003FD  mov      x29, sp
//   0x14500c: 52800061  mov      w1, #3
//   0x145010: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_3161_0x145004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145004ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eb960ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3162 | PC: 0x145048 | FDE: 0x1eb980 | Size: 120 bytes [_Py_set_blocking]
// Khung tháo gỡ #3162 | Địa chỉ PC: 0x145048 | Địa chỉ FDE: 0x1eb980 | Kích thước: 120 bytes
//   0x145048: D100C3FF  sub      sp, sp, #0x30
//   0x14504c: F9000BF3  str      x19, [sp, #0x10]
//   0x145050: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145054: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3162_0x145048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145048ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1eb980ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3163 | PC: 0x1450c0 | FDE: 0x1eb9a0 | Size: 256 bytes [_Py_GetLocaleconvNumeric]
// Khung tháo gỡ #3163 | Địa chỉ PC: 0x1450c0 | Địa chỉ FDE: 0x1eb9a0 | Kích thước: 256 bytes
//   0x1450c0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1450c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1450c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1450cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3163_0x1450c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1450c0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3164 | PC: 0x145214 | FDE: 0x1eb9c8 | Size: 60 bytes [_Py_closerange]
// Khung tháo gỡ #3164 | Địa chỉ PC: 0x145214 | Địa chỉ FDE: 0x1eb9c8 | Kích thước: 60 bytes
//   0x145214: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x145218: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14521c: 910043FD  add      x29, sp, #0x10
//   0x145220: 0AA07C14  bic      w20, w0, w0, asr #31
static inline uint64_t fde_func_3164_0x145214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145214ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb9c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3165 | PC: 0x145250 | FDE: 0x1eb9e8 | Size: 16 bytes [_PyEval_DeactivateOpCache]
// Khung tháo gỡ #3165 | Địa chỉ PC: 0x145250 | Địa chỉ FDE: 0x1eb9e8 | Kích thước: 16 bytes
//   0x145250: 90000708  adrp     x8, #0x225000
//   0x145254: 52800029  mov      w9, #1
//   0x145258: 393CA109  strb     w9, [x8, #0xf28]
//   0x14525c: D65F03C0  ret      
static inline uint64_t fde_func_3165_0x145250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145250ULL ^ (static_cast<uint64_t>(0x90000708ULL) << 13);
    acc = (acc + a1 + 0x52800029ULL) ^ 0x1eb9e8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3166 | PC: 0x145260 | FDE: 0x1eba00 | Size: 36 bytes [_PyEval_SetSwitchInterval]
// Khung tháo gỡ #3166 | Địa chỉ PC: 0x145260 | Địa chỉ FDE: 0x1eba00 | Kích thước: 36 bytes
//   0x145260: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145264: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145268: 910043FD  add      x29, sp, #0x10
//   0x14526c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3166_0x145260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145260ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eba00ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3167 | PC: 0x145284 | FDE: 0x1eba20 | Size: 24 bytes [_PyEval_GetSwitchInterval]
// Khung tháo gỡ #3167 | Địa chỉ PC: 0x145284 | Địa chỉ FDE: 0x1eba20 | Kích thước: 24 bytes
//   0x145284: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x145288: 910003FD  mov      x29, sp
//   0x14528c: 97FC5DB9  bl       #0x5c970
//   0x145290: F9413400  ldr      x0, [x0, #0x268]
static inline uint64_t fde_func_3167_0x145284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145284ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eba20ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3168 | PC: 0x14529c | FDE: 0x1eba40 | Size: 20 bytes [_Py_FatalError_TstateNULL]
// Khung tháo gỡ #3168 | Địa chỉ PC: 0x14529c | Địa chỉ FDE: 0x1eba40 | Kích thước: 20 bytes
//   0x14529c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1452a0: 910003FD  mov      x29, sp
//   0x1452a4: F00003C1  adrp     x1, #0x1c0000
//   0x1452a8: 91123821  add      x1, x1, #0x48e
static inline uint64_t fde_func_3168_0x14529c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14529cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eba40ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #3169 | PC: 0x1452b0 | FDE: 0x1eba60 | Size: 20 bytes [_PyEval_ThreadsInitialized]
// Khung tháo gỡ #3169 | Địa chỉ PC: 0x1452b0 | Địa chỉ FDE: 0x1eba60 | Kích thước: 20 bytes
//   0x1452b0: 9109E008  add      x8, x0, #0x278
//   0x1452b4: 88DFFD08  ldar     w8, [x8]
//   0x1452b8: 2A2803E8  mvn      w8, w8
//   0x1452bc: 531F7D00  lsr      w0, w8, #0x1f
static inline uint64_t fde_func_3169_0x1452b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1452b0ULL ^ (static_cast<uint64_t>(0x9109e008ULL) << 13);
    acc = (acc + a1 + 0x88dffd08ULL) ^ 0x1eba60ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #3170 | PC: 0x1452c4 | FDE: 0x1eba78 | Size: 36 bytes [PyEval_ThreadsInitialized]
// Khung tháo gỡ #3170 | Địa chỉ PC: 0x1452c4 | Địa chỉ FDE: 0x1eba78 | Kích thước: 36 bytes
//   0x1452c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1452c8: 910003FD  mov      x29, sp
//   0x1452cc: 97FC5DA9  bl       #0x5c970
//   0x1452d0: 9109E008  add      x8, x0, #0x278
static inline uint64_t fde_func_3170_0x1452c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1452c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eba78ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3171 | PC: 0x1452e8 | FDE: 0x1eba98 | Size: 76 bytes [_PyEval_InitGIL]
// Khung tháo gỡ #3171 | Địa chỉ PC: 0x1452e8 | Địa chỉ FDE: 0x1eba98 | Kích thước: 76 bytes
//   0x1452e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1452ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1452f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1452f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3171_0x1452e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1452e8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eba98ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3172 | PC: 0x145334 | FDE: 0x1ebab8 | Size: 176 bytes
// Khung tháo gỡ #3172 | Địa chỉ PC: 0x145334 | Địa chỉ FDE: 0x1ebab8 | Kích thước: 176 bytes
//   0x145334: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145338: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14533c: 910043FD  add      x29, sp, #0x10
//   0x145340: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3172_0x145334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145334ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebab8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3173 | PC: 0x1453e4 | FDE: 0x1ebad8 | Size: 256 bytes
// Khung tháo gỡ #3173 | Địa chỉ PC: 0x1453e4 | Địa chỉ FDE: 0x1ebad8 | Kích thước: 256 bytes
//   0x1453e4: D10203FF  sub      sp, sp, #0x80
//   0x1453e8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1453ec: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1453f0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3173_0x1453e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1453e4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1ebad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3174 | PC: 0x1456b8 | FDE: 0x1ebb08 | Size: 180 bytes [_PyEval_FiniGIL]
// Khung tháo gỡ #3174 | Địa chỉ PC: 0x1456b8 | Địa chỉ FDE: 0x1ebb08 | Kích thước: 180 bytes
//   0x1456b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1456bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1456c0: 910043FD  add      x29, sp, #0x10
//   0x1456c4: 9109E008  add      x8, x0, #0x278
static inline uint64_t fde_func_3174_0x1456b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1456b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebb08ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3175 | PC: 0x14576c | FDE: 0x1ebb28 | Size: 4 bytes [PyEval_InitThreads]
// Khung tháo gỡ #3175 | Địa chỉ PC: 0x14576c | Địa chỉ FDE: 0x1ebb28 | Kích thước: 4 bytes
//   0x14576c: D65F03C0  ret      
static inline uint64_t fde_func_3175_0x14576c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14576cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ebb28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3176 | PC: 0x145770 | FDE: 0x1ebb40 | Size: 4 bytes [_PyEval_Fini]
// Khung tháo gỡ #3176 | Địa chỉ PC: 0x145770 | Địa chỉ FDE: 0x1ebb40 | Kích thước: 4 bytes
//   0x145770: D65F03C0  ret      
static inline uint64_t fde_func_3176_0x145770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145770ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1ebb40ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3177 | PC: 0x145774 | FDE: 0x1ebb58 | Size: 36 bytes [PyEval_AcquireLock]
// Khung tháo gỡ #3177 | Địa chỉ PC: 0x145774 | Địa chỉ FDE: 0x1ebb58 | Kích thước: 36 bytes
//   0x145774: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x145778: 910003FD  mov      x29, sp
//   0x14577c: 97FC5011  bl       #0x597c0
//   0x145780: B4000060  cbz      x0, #0x14578c
static inline uint64_t fde_func_3177_0x145774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145774ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ebb58ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3178 | PC: 0x145798 | FDE: 0x1ebb78 | Size: 32 bytes [PyEval_ReleaseLock]
// Khung tháo gỡ #3178 | Địa chỉ PC: 0x145798 | Địa chỉ FDE: 0x1ebb78 | Kích thước: 32 bytes
//   0x145798: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14579c: 910003FD  mov      x29, sp
//   0x1457a0: 97FC5008  bl       #0x597c0
//   0x1457a4: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_3178_0x145798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145798ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ebb78ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3179 | PC: 0x1457b8 | FDE: 0x1ebb98 | Size: 256 bytes
// Khung tháo gỡ #3179 | Địa chỉ PC: 0x1457b8 | Địa chỉ FDE: 0x1ebb98 | Kích thước: 256 bytes
//   0x1457b8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1457bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1457c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1457c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3179_0x1457b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1457b8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ebb98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3180 | PC: 0x14596c | FDE: 0x1ebbc0 | Size: 16 bytes [_PyEval_ReleaseLock]
// Khung tháo gỡ #3180 | Địa chỉ PC: 0x14596c | Địa chỉ FDE: 0x1ebbc0 | Kích thước: 16 bytes
//   0x14596c: F9400808  ldr      x8, [x0, #0x10]
//   0x145970: AA0003E1  mov      x1, x0
//   0x145974: 91010100  add      x0, x8, #0x40
//   0x145978: 17FFFF90  b        #0x1457b8
static inline uint64_t fde_func_3180_0x14596c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14596cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x1ebbc0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3181 | PC: 0x14597c | FDE: 0x1ebbd8 | Size: 64 bytes [PyEval_AcquireThread]
// Khung tháo gỡ #3181 | Địa chỉ PC: 0x14597c | Địa chỉ FDE: 0x1ebbd8 | Kích thước: 64 bytes
//   0x14597c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145980: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145984: 910043FD  add      x29, sp, #0x10
//   0x145988: B4000140  cbz      x0, #0x1459b0
static inline uint64_t fde_func_3181_0x14597c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14597cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebbd8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3182 | PC: 0x1459bc | FDE: 0x1ebbf8 | Size: 88 bytes [PyEval_ReleaseThread]
// Khung tháo gỡ #3182 | Địa chỉ PC: 0x1459bc | Địa chỉ FDE: 0x1ebbf8 | Kích thước: 88 bytes
//   0x1459bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1459c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1459c4: 910043FD  add      x29, sp, #0x10
//   0x1459c8: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_3182_0x1459bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1459bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebbf8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3183 | PC: 0x145a14 | FDE: 0x1ebc18 | Size: 156 bytes [_PyEval_ReInitThreads]
// Khung tháo gỡ #3183 | Địa chỉ PC: 0x145a14 | Địa chỉ FDE: 0x1ebc18 | Kích thước: 156 bytes
//   0x145a14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x145a18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x145a1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145a20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3183_0x145a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145a14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebc18ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3184 | PC: 0x145ab0 | FDE: 0x1ebc38 | Size: 16 bytes [_PyEval_SignalAsyncExc]
// Khung tháo gỡ #3184 | Địa chỉ PC: 0x145ab0 | Địa chỉ FDE: 0x1ebc38 | Kích thước: 16 bytes
//   0x145ab0: 52800028  mov      w8, #1
//   0x145ab4: B9005C08  str      w8, [x0, #0x5c]
//   0x145ab8: B9004408  str      w8, [x0, #0x44]
//   0x145abc: D65F03C0  ret      
static inline uint64_t fde_func_3184_0x145ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145ab0ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0xb9005c08ULL) ^ 0x1ebc38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3185 | PC: 0x145ac0 | FDE: 0x1ebc50 | Size: 88 bytes [PyEval_SaveThread]
// Khung tháo gỡ #3185 | Địa chỉ PC: 0x145ac0 | Địa chỉ FDE: 0x1ebc50 | Kích thước: 88 bytes
//   0x145ac0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145ac4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145ac8: 910043FD  add      x29, sp, #0x10
//   0x145acc: 97FC4F3D  bl       #0x597c0
static inline uint64_t fde_func_3185_0x145ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145ac0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebc50ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3186 | PC: 0x145b18 | FDE: 0x1ebc70 | Size: 64 bytes [PyEval_RestoreThread]
// Khung tháo gỡ #3186 | Địa chỉ PC: 0x145b18 | Địa chỉ FDE: 0x1ebc70 | Kích thước: 64 bytes
//   0x145b18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145b1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145b20: 910043FD  add      x29, sp, #0x10
//   0x145b24: B4000140  cbz      x0, #0x145b4c
static inline uint64_t fde_func_3186_0x145b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145b18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebc70ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3187 | PC: 0x145b58 | FDE: 0x1ebc90 | Size: 156 bytes [_PyEval_SignalReceived]
// Khung tháo gỡ #3187 | Địa chỉ PC: 0x145b58 | Địa chỉ FDE: 0x1ebc90 | Kích thước: 156 bytes
//   0x145b58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x145b5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x145b60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145b64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3187_0x145b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145b58ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebc90ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3188 | PC: 0x145bf4 | FDE: 0x1ebcb0 | Size: 256 bytes [_PyEval_AddPendingCall]
// Khung tháo gỡ #3188 | Địa chỉ PC: 0x145bf4 | Địa chỉ FDE: 0x1ebcb0 | Kích thước: 256 bytes
//   0x145bf4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x145bf8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x145bfc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x145c00: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3188_0x145bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145bf4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ebcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3189 | PC: 0x145cf8 | FDE: 0x1ebcd8 | Size: 80 bytes [Py_AddPendingCall]
// Khung tháo gỡ #3189 | Địa chỉ PC: 0x145cf8 | Địa chỉ FDE: 0x1ebcd8 | Kích thước: 80 bytes
//   0x145cf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x145cfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145d00: 910043FD  add      x29, sp, #0x10
//   0x145d04: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_3189_0x145cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145cf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebcd8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3190 | PC: 0x145d48 | FDE: 0x1ebcf8 | Size: 144 bytes [_Py_FinishPendingCalls]
// Khung tháo gỡ #3190 | Địa chỉ PC: 0x145d48 | Địa chỉ FDE: 0x1ebcf8 | Kích thước: 144 bytes
//   0x145d48: D10103FF  sub      sp, sp, #0x40
//   0x145d4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x145d50: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x145d54: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3190_0x145d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145d48ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ebcf8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3191 | PC: 0x145dd8 | FDE: 0x1ebd18 | Size: 256 bytes
// Khung tháo gỡ #3191 | Địa chỉ PC: 0x145dd8 | Địa chỉ FDE: 0x1ebd18 | Kích thước: 256 bytes
//   0x145dd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x145ddc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x145de0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x145de4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3191_0x145dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145dd8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ebd18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3192 | PC: 0x145f9c | FDE: 0x1ebd40 | Size: 56 bytes [Py_MakePendingCalls]
// Khung tháo gỡ #3192 | Địa chỉ PC: 0x145f9c | Địa chỉ FDE: 0x1ebd40 | Kích thước: 56 bytes
//   0x145f9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145fa0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145fa4: 910043FD  add      x29, sp, #0x10
//   0x145fa8: 97FC4E06  bl       #0x597c0
static inline uint64_t fde_func_3192_0x145f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145f9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebd40ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3193 | PC: 0x145fd4 | FDE: 0x1ebd60 | Size: 256 bytes
// Khung tháo gỡ #3193 | Địa chỉ PC: 0x145fd4 | Địa chỉ FDE: 0x1ebd60 | Kích thước: 256 bytes
//   0x145fd4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x145fd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x145fdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145fe0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3193_0x145fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145fd4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebd60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3194 | PC: 0x146120 | FDE: 0x1ebd88 | Size: 4 bytes [_PyEval_InitRuntimeState]
// Khung tháo gỡ #3194 | Địa chỉ PC: 0x146120 | Địa chỉ FDE: 0x1ebd88 | Kích thước: 4 bytes
//   0x146120: D65F03C0  ret      
static inline uint64_t fde_func_3194_0x146120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146120ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1ebd88ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3195 | PC: 0x146124 | FDE: 0x1ebda0 | Size: 72 bytes [_PyEval_InitState]
// Khung tháo gỡ #3195 | Địa chỉ PC: 0x146124 | Địa chỉ FDE: 0x1ebda0 | Kích thước: 72 bytes
//   0x146124: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x146128: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14612c: 910043FD  add      x29, sp, #0x10
//   0x146130: 52807D08  mov      w8, #0x3e8
static inline uint64_t fde_func_3195_0x146124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146124ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebda0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3196 | PC: 0x14616c | FDE: 0x1ebdc0 | Size: 44 bytes [_PyEval_FiniState]
// Khung tháo gỡ #3196 | Địa chỉ PC: 0x14616c | Địa chỉ FDE: 0x1ebdc0 | Kích thước: 44 bytes
//   0x14616c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x146170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x146174: 910043FD  add      x29, sp, #0x10
//   0x146178: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3196_0x14616c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14616cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebdc0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3197 | PC: 0x146198 | FDE: 0x1ebde0 | Size: 40 bytes [Py_GetRecursionLimit]
// Khung tháo gỡ #3197 | Địa chỉ PC: 0x146198 | Địa chỉ FDE: 0x1ebde0 | Kích thước: 40 bytes
//   0x146198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14619c: 910003FD  mov      x29, sp
//   0x1461a0: B00005C8  adrp     x8, #0x1ff000
//   0x1461a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3197_0x146198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ebde0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3198 | PC: 0x1461c0 | FDE: 0x1ebe00 | Size: 40 bytes [Py_SetRecursionLimit]
// Khung tháo gỡ #3198 | Địa chỉ PC: 0x1461c0 | Địa chỉ FDE: 0x1ebe00 | Kích thước: 40 bytes
//   0x1461c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1461c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1461c8: 910043FD  add      x29, sp, #0x10
//   0x1461cc: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_3198_0x1461c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1461c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebe00ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3199 | PC: 0x1461e8 | FDE: 0x1ebe20 | Size: 148 bytes [_Py_CheckRecursiveCall]
// Khung tháo gỡ #3199 | Địa chỉ PC: 0x1461e8 | Địa chỉ FDE: 0x1ebe20 | Kích thước: 148 bytes
//   0x1461e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1461ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1461f0: 910043FD  add      x29, sp, #0x10
//   0x1461f4: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_3199_0x1461e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1461e8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebe20ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3200 | PC: 0x14627c | FDE: 0x1ebe40 | Size: 164 bytes [PyEval_EvalCode]
// Khung tháo gỡ #3200 | Địa chỉ PC: 0x14627c | Địa chỉ FDE: 0x1ebe40 | Kích thước: 164 bytes
//   0x14627c: D10243FF  sub      sp, sp, #0x90
//   0x146280: F9002BF7  str      x23, [sp, #0x50]
//   0x146284: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x146288: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_3200_0x14627c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14627cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x1ebe40ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #3201 | PC: 0x146320 | FDE: 0x1ebe68 | Size: 256 bytes [_PyEval_Vector]
// Khung tháo gỡ #3201 | Địa chỉ PC: 0x146320 | Địa chỉ FDE: 0x1ebe68 | Kích thước: 256 bytes
//   0x146320: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x146324: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x146328: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14632c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3201_0x146320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146320ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebe68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3202 | PC: 0x146448 | FDE: 0x1ebe90 | Size: 48 bytes [PyEval_EvalFrame]
// Khung tháo gỡ #3202 | Địa chỉ PC: 0x146448 | Địa chỉ FDE: 0x1ebe90 | Kích thước: 48 bytes
//   0x146448: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14644c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x146450: 910043FD  add      x29, sp, #0x10
//   0x146454: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3202_0x146448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146448ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebe90ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3203 | PC: 0x146478 | FDE: 0x1ebeb0 | Size: 52 bytes [PyEval_EvalFrameEx]
// Khung tháo gỡ #3203 | Địa chỉ PC: 0x146478 | Địa chỉ FDE: 0x1ebeb0 | Kích thước: 52 bytes
//   0x146478: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14647c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x146480: 910043FD  add      x29, sp, #0x10
//   0x146484: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_3203_0x146478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146478ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebeb0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3204 | PC: 0x1464ac | FDE: 0x1ebed0 | Size: 256 bytes [_PyEval_EvalFrameDefault]
// Khung tháo gỡ #3204 | Địa chỉ PC: 0x1464ac | Địa chỉ FDE: 0x1ebed0 | Kích thước: 256 bytes
//   0x1464ac: D10683FF  sub      sp, sp, #0x1a0
//   0x1464b0: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x1464b4: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x1464b8: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_3204_0x1464ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1464acULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x1ebed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3205 | PC: 0x14c8d8 | FDE: 0x1ebf00 | Size: 256 bytes
// Khung tháo gỡ #3205 | Địa chỉ PC: 0x14c8d8 | Địa chỉ FDE: 0x1ebf00 | Kích thước: 256 bytes
//   0x14c8d8: D101C3FF  sub      sp, sp, #0x70
//   0x14c8dc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x14c8e0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x14c8e4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3205_0x14c8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c8d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1ebf00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3206 | PC: 0x14c9f4 | FDE: 0x1ebf30 | Size: 232 bytes
// Khung tháo gỡ #3206 | Địa chỉ PC: 0x14c9f4 | Địa chỉ FDE: 0x1ebf30 | Kích thước: 232 bytes
//   0x14c9f4: D10183FF  sub      sp, sp, #0x60
//   0x14c9f8: F90013F7  str      x23, [sp, #0x20]
//   0x14c9fc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x14ca00: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3206_0x14c9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c9f4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1ebf30ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3207 | PC: 0x14cadc | FDE: 0x1ebf58 | Size: 256 bytes
// Khung tháo gỡ #3207 | Địa chỉ PC: 0x14cadc | Địa chỉ FDE: 0x1ebf58 | Kích thước: 256 bytes
//   0x14cadc: D10183FF  sub      sp, sp, #0x60
//   0x14cae0: F9000BF9  str      x25, [sp, #0x10]
//   0x14cae4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x14cae8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3207_0x14cadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14cadcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1ebf58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3208 | PC: 0x14cc5c | FDE: 0x1ebf80 | Size: 256 bytes
// Khung tháo gỡ #3208 | Địa chỉ PC: 0x14cc5c | Địa chỉ FDE: 0x1ebf80 | Kích thước: 256 bytes
//   0x14cc5c: D101C3FF  sub      sp, sp, #0x70
//   0x14cc60: F90013F9  str      x25, [sp, #0x20]
//   0x14cc64: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x14cc68: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3208_0x14cc5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14cc5cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1ebf80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3209 | PC: 0x14cddc | FDE: 0x1ebfa8 | Size: 256 bytes
// Khung tháo gỡ #3209 | Địa chỉ PC: 0x14cddc | Địa chỉ FDE: 0x1ebfa8 | Kích thước: 256 bytes
//   0x14cddc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x14cde0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x14cde4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14cde8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3209_0x14cddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14cddcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ebfa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3210 | PC: 0x14d04c | FDE: 0x1ebfd0 | Size: 100 bytes [format_exc_unbound]
// Khung tháo gỡ #3210 | Địa chỉ PC: 0x14d04c | Địa chỉ FDE: 0x1ebfd0 | Kích thước: 100 bytes
//   0x14d04c: F9402C08  ldr      x8, [x0, #0x58]
//   0x14d050: B4000048  cbz      x8, #0x14d058
//   0x14d054: D65F03C0  ret      
//   0x14d058: F9402C28  ldr      x8, [x1, #0x58]
static inline uint64_t fde_func_3210_0x14d04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d04cULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xb4000048ULL) ^ 0x1ebfd0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #3211 | PC: 0x14d0b0 | FDE: 0x1ebfe8 | Size: 256 bytes
// Khung tháo gỡ #3211 | Địa chỉ PC: 0x14d0b0 | Địa chỉ FDE: 0x1ebfe8 | Kích thước: 256 bytes
//   0x14d0b0: D10143FF  sub      sp, sp, #0x50
//   0x14d0b4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14d0b8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x14d0bc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3211_0x14d0b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d0b0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ebfe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3212 | PC: 0x14d27c | FDE: 0x1ec010 | Size: 256 bytes [import_from]
// Khung tháo gỡ #3212 | Địa chỉ PC: 0x14d27c | Địa chỉ FDE: 0x1ec010 | Kích thước: 256 bytes
//   0x14d27c: D10183FF  sub      sp, sp, #0x60
//   0x14d280: F9000BF9  str      x25, [sp, #0x10]
//   0x14d284: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x14d288: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3212_0x14d27c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d27cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1ec010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3213 | PC: 0x14d4f4 | FDE: 0x1ec038 | Size: 108 bytes
// Khung tháo gỡ #3213 | Địa chỉ PC: 0x14d4f4 | Địa chỉ FDE: 0x1ec038 | Kích thước: 108 bytes
//   0x14d4f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x14d4f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14d4fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14d500: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3213_0x14d4f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d4f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec038ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3214 | PC: 0x14d560 | FDE: 0x1ec060 | Size: 256 bytes
// Khung tháo gỡ #3214 | Địa chỉ PC: 0x14d560 | Địa chỉ FDE: 0x1ec060 | Kích thước: 256 bytes
//   0x14d560: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x14d564: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x14d568: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x14d56c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3214_0x14d560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d560ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ec060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3215 | PC: 0x14d98c | FDE: 0x1ec090 | Size: 256 bytes [_PyEval_MakeFrameVector]
// Khung tháo gỡ #3215 | Địa chỉ PC: 0x14d98c | Địa chỉ FDE: 0x1ec090 | Kích thước: 256 bytes
//   0x14d98c: D10283FF  sub      sp, sp, #0xa0
//   0x14d990: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x14d994: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x14d998: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_3215_0x14d98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d98cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1ec090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3216 | PC: 0x14e2ec | FDE: 0x1ec0c0 | Size: 256 bytes
// Khung tháo gỡ #3216 | Địa chỉ PC: 0x14e2ec | Địa chỉ FDE: 0x1ec0c0 | Kích thước: 256 bytes
//   0x14e2ec: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x14e2f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x14e2f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x14e2f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3216_0x14e2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e2ecULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ec0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3217 | PC: 0x14e578 | FDE: 0x1ec0f0 | Size: 256 bytes [PyEval_EvalCodeEx]
// Khung tháo gỡ #3217 | Địa chỉ PC: 0x14e578 | Địa chỉ FDE: 0x1ec0f0 | Kích thước: 256 bytes
//   0x14e578: D10343FF  sub      sp, sp, #0xd0
//   0x14e57c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x14e580: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x14e584: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_3217_0x14e578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e578ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x1ec0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3218 | PC: 0x14e828 | FDE: 0x1ec120 | Size: 132 bytes [_PyEval_CallTracing]
// Khung tháo gỡ #3218 | Địa chỉ PC: 0x14e828 | Địa chỉ FDE: 0x1ec120 | Kích thước: 132 bytes
//   0x14e828: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x14e82c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x14e830: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14e834: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3218_0x14e828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e828ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec120ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #3219 | PC: 0x14e8ac | FDE: 0x1ec148 | Size: 188 bytes [_PyEval_SetProfile]
// Khung tháo gỡ #3219 | Địa chỉ PC: 0x14e8ac | Địa chỉ FDE: 0x1ec148 | Kích thước: 188 bytes
//   0x14e8ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14e8b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14e8b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14e8b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3219_0x14e8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e8acULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec148ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3220 | PC: 0x14e968 | FDE: 0x1ec168 | Size: 76 bytes [PyEval_SetProfile]
// Khung tháo gỡ #3220 | Địa chỉ PC: 0x14e968 | Địa chỉ FDE: 0x1ec168 | Kích thước: 76 bytes
//   0x14e968: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14e96c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14e970: 910043FD  add      x29, sp, #0x10
//   0x14e974: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_3220_0x14e968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e968ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec168ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3221 | PC: 0x14e9b4 | FDE: 0x1ec188 | Size: 188 bytes [_PyEval_SetTrace]
// Khung tháo gỡ #3221 | Địa chỉ PC: 0x14e9b4 | Địa chỉ FDE: 0x1ec188 | Kích thước: 188 bytes
//   0x14e9b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14e9b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14e9bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14e9c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3221_0x14e9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e9b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec188ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3222 | PC: 0x14ea70 | FDE: 0x1ec1a8 | Size: 76 bytes [PyEval_SetTrace]
// Khung tháo gỡ #3222 | Địa chỉ PC: 0x14ea70 | Địa chỉ FDE: 0x1ec1a8 | Kích thước: 76 bytes
//   0x14ea70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14ea74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14ea78: 910043FD  add      x29, sp, #0x10
//   0x14ea7c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_3222_0x14ea70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ea70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec1a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3223 | PC: 0x14eabc | FDE: 0x1ec1c8 | Size: 8 bytes [_PyEval_SetCoroutineOriginTrackingDepth]
// Khung tháo gỡ #3223 | Địa chỉ PC: 0x14eabc | Địa chỉ FDE: 0x1ec1c8 | Kích thước: 8 bytes
//   0x14eabc: B900D801  str      w1, [x0, #0xd8]
//   0x14eac0: D65F03C0  ret      
static inline uint64_t fde_func_3223_0x14eabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eabcULL ^ (static_cast<uint64_t>(0xb900d801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ec1c8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3224 | PC: 0x14eac4 | FDE: 0x1ec1e0 | Size: 24 bytes [_PyEval_GetCoroutineOriginTrackingDepth]
// Khung tháo gỡ #3224 | Địa chỉ PC: 0x14eac4 | Địa chỉ FDE: 0x1ec1e0 | Kích thước: 24 bytes
//   0x14eac4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14eac8: 910003FD  mov      x29, sp
//   0x14eacc: 97FC2B3D  bl       #0x597c0
//   0x14ead0: B940D800  ldr      w0, [x0, #0xd8]
static inline uint64_t fde_func_3224_0x14eac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eac4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec1e0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3225 | PC: 0x14eadc | FDE: 0x1ec200 | Size: 116 bytes [_PyEval_SetAsyncGenFirstiter]
// Khung tháo gỡ #3225 | Địa chỉ PC: 0x14eadc | Địa chỉ FDE: 0x1ec200 | Kích thước: 116 bytes
//   0x14eadc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14eae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14eae4: 910043FD  add      x29, sp, #0x10
//   0x14eae8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3225_0x14eadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eadcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec200ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3226 | PC: 0x14eb50 | FDE: 0x1ec220 | Size: 24 bytes [_PyEval_GetAsyncGenFirstiter]
// Khung tháo gỡ #3226 | Địa chỉ PC: 0x14eb50 | Địa chỉ FDE: 0x1ec220 | Kích thước: 24 bytes
//   0x14eb50: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14eb54: 910003FD  mov      x29, sp
//   0x14eb58: 97FC2B1A  bl       #0x597c0
//   0x14eb5c: F9407000  ldr      x0, [x0, #0xe0]
static inline uint64_t fde_func_3226_0x14eb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eb50ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec220ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3227 | PC: 0x14eb68 | FDE: 0x1ec240 | Size: 116 bytes [_PyEval_SetAsyncGenFinalizer]
// Khung tháo gỡ #3227 | Địa chỉ PC: 0x14eb68 | Địa chỉ FDE: 0x1ec240 | Kích thước: 116 bytes
//   0x14eb68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14eb6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14eb70: 910043FD  add      x29, sp, #0x10
//   0x14eb74: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3227_0x14eb68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eb68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec240ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3228 | PC: 0x14ebdc | FDE: 0x1ec260 | Size: 24 bytes [_PyEval_GetAsyncGenFinalizer]
// Khung tháo gỡ #3228 | Địa chỉ PC: 0x14ebdc | Địa chỉ FDE: 0x1ec260 | Kích thước: 24 bytes
//   0x14ebdc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ebe0: 910003FD  mov      x29, sp
//   0x14ebe4: 97FC2AF7  bl       #0x597c0
//   0x14ebe8: F9407400  ldr      x0, [x0, #0xe8]
static inline uint64_t fde_func_3228_0x14ebdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ebdcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec260ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3229 | PC: 0x14ebf4 | FDE: 0x1ec280 | Size: 24 bytes [PyEval_GetFrame]
// Khung tháo gỡ #3229 | Địa chỉ PC: 0x14ebf4 | Địa chỉ FDE: 0x1ec280 | Kích thước: 24 bytes
//   0x14ebf4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ebf8: 910003FD  mov      x29, sp
//   0x14ebfc: 97FC2AF1  bl       #0x597c0
//   0x14ec00: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_3229_0x14ebf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ebf4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec280ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3230 | PC: 0x14ec0c | FDE: 0x1ec2a0 | Size: 32 bytes [_PyEval_GetBuiltins]
// Khung tháo gỡ #3230 | Địa chỉ PC: 0x14ec0c | Địa chỉ FDE: 0x1ec2a0 | Kích thước: 32 bytes
//   0x14ec0c: F9400C08  ldr      x8, [x0, #0x18]
//   0x14ec10: B4000068  cbz      x8, #0x14ec1c
//   0x14ec14: 9100A108  add      x8, x8, #0x28
//   0x14ec18: 14000003  b        #0x14ec24
static inline uint64_t fde_func_3230_0x14ec0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec0cULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x1ec2a0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3231 | PC: 0x14ec2c | FDE: 0x1ec2b8 | Size: 48 bytes [PyEval_GetBuiltins]
// Khung tháo gỡ #3231 | Địa chỉ PC: 0x14ec2c | Địa chỉ FDE: 0x1ec2b8 | Kích thước: 48 bytes
//   0x14ec2c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ec30: 910003FD  mov      x29, sp
//   0x14ec34: 97FC2AE3  bl       #0x597c0
//   0x14ec38: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_3231_0x14ec2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec2cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec2b8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3232 | PC: 0x14ec5c | FDE: 0x1ec2d8 | Size: 156 bytes [_PyEval_GetBuiltinId]
// Khung tháo gỡ #3232 | Địa chỉ PC: 0x14ec5c | Địa chỉ FDE: 0x1ec2d8 | Kích thước: 156 bytes
//   0x14ec5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x14ec60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14ec64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14ec68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3232_0x14ec5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec5cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec2d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3233 | PC: 0x14ecf8 | FDE: 0x1ec300 | Size: 84 bytes [PyEval_GetLocals]
// Khung tháo gỡ #3233 | Địa chỉ PC: 0x14ecf8 | Địa chỉ FDE: 0x1ec300 | Kích thước: 84 bytes
//   0x14ecf8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14ecfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14ed00: 910043FD  add      x29, sp, #0x10
//   0x14ed04: 97FC2AAF  bl       #0x597c0
static inline uint64_t fde_func_3233_0x14ecf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ecf8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec300ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3234 | PC: 0x14ed4c | FDE: 0x1ec320 | Size: 40 bytes [PyEval_GetGlobals]
// Khung tháo gỡ #3234 | Địa chỉ PC: 0x14ed4c | Địa chỉ FDE: 0x1ec320 | Kích thước: 40 bytes
//   0x14ed4c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ed50: 910003FD  mov      x29, sp
//   0x14ed54: 97FC2A9B  bl       #0x597c0
//   0x14ed58: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_3234_0x14ed4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ed4cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec320ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3235 | PC: 0x14ed74 | FDE: 0x1ec340 | Size: 80 bytes [PyEval_MergeCompilerFlags]
// Khung tháo gỡ #3235 | Địa chỉ PC: 0x14ed74 | Địa chỉ FDE: 0x1ec340 | Kích thước: 80 bytes
//   0x14ed74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14ed78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14ed7c: 910043FD  add      x29, sp, #0x10
//   0x14ed80: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3235_0x14ed74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ed74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec340ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3236 | PC: 0x14edc4 | FDE: 0x1ec360 | Size: 156 bytes [PyEval_GetFuncName]
// Khung tháo gỡ #3236 | Địa chỉ PC: 0x14edc4 | Địa chỉ FDE: 0x1ec360 | Kích thước: 156 bytes
//   0x14edc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14edc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14edcc: 910043FD  add      x29, sp, #0x10
//   0x14edd0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3236_0x14edc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14edc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec360ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3237 | PC: 0x14ee60 | FDE: 0x1ec380 | Size: 116 bytes [PyEval_GetFuncDesc]
// Khung tháo gỡ #3237 | Địa chỉ PC: 0x14ee60 | Địa chỉ FDE: 0x1ec380 | Kích thước: 116 bytes
//   0x14ee60: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ee64: 910003FD  mov      x29, sp
//   0x14ee68: B0000588  adrp     x8, #0x1ff000
//   0x14ee6c: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_3237_0x14ee60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ee60ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec380ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3238 | PC: 0x14eed4 | FDE: 0x1ec3a0 | Size: 156 bytes [_PyEval_SliceIndex]
// Khung tháo gỡ #3238 | Địa chỉ PC: 0x14eed4 | Địa chỉ FDE: 0x1ec3a0 | Kích thước: 156 bytes
//   0x14eed4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14eed8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14eedc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14eee0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3238_0x14eed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eed4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec3a0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3239 | PC: 0x14ef70 | FDE: 0x1ec3c0 | Size: 140 bytes [_PyEval_SliceIndexNotNone]
// Khung tháo gỡ #3239 | Địa chỉ PC: 0x14ef70 | Địa chỉ FDE: 0x1ec3c0 | Kích thước: 140 bytes
//   0x14ef70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14ef74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14ef78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14ef7c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3239_0x14ef70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ef70ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec3c0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #3240 | PC: 0x14effc | FDE: 0x1ec3e0 | Size: 88 bytes [_PyEval_RequestCodeExtraIndex]
// Khung tháo gỡ #3240 | Địa chỉ PC: 0x14effc | Địa chỉ FDE: 0x1ec3e0 | Kích thước: 88 bytes
//   0x14effc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f000: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f004: 910043FD  add      x29, sp, #0x10
//   0x14f008: 90000588  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3240_0x14effc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14effcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec3e0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3241 | PC: 0x14f054 | FDE: 0x1ec400 | Size: 84 bytes [Py_EnterRecursiveCall]
// Khung tháo gỡ #3241 | Địa chỉ PC: 0x14f054 | Địa chỉ FDE: 0x1ec400 | Kích thước: 84 bytes
//   0x14f054: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f058: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f05c: 910043FD  add      x29, sp, #0x10
//   0x14f060: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3241_0x14f054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f054ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec400ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3242 | PC: 0x14f0a8 | FDE: 0x1ec420 | Size: 32 bytes [Py_LeaveRecursiveCall]
// Khung tháo gỡ #3242 | Địa chỉ PC: 0x14f0a8 | Địa chỉ FDE: 0x1ec420 | Kích thước: 32 bytes
//   0x14f0a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14f0ac: 910003FD  mov      x29, sp
//   0x14f0b0: 97FC2F88  bl       #0x5aed0
//   0x14f0b4: B9402008  ldr      w8, [x0, #0x20]
static inline uint64_t fde_func_3242_0x14f0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f0a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec420ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3243 | PC: 0x14f0c8 | FDE: 0x1ec440 | Size: 192 bytes
// Khung tháo gỡ #3243 | Địa chỉ PC: 0x14f0c8 | Địa chỉ FDE: 0x1ec440 | Kích thước: 192 bytes
//   0x14f0c8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x14f0cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x14f0d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14f0d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3243_0x14f0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f0c8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec440ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3244 | PC: 0x14f188 | FDE: 0x1ec468 | Size: 248 bytes
// Khung tháo gỡ #3244 | Địa chỉ PC: 0x14f188 | Địa chỉ FDE: 0x1ec468 | Kích thước: 248 bytes
//   0x14f188: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x14f18c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x14f190: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14f194: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3244_0x14f188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f188ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ec468ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3245 | PC: 0x14f280 | FDE: 0x1ec490 | Size: 36 bytes [bd_get_opcode_name]
// Khung tháo gỡ #3245 | Địa chỉ PC: 0x14f280 | Địa chỉ FDE: 0x1ec490 | Kích thước: 36 bytes
//   0x14f280: 7103E81F  cmp      w0, #0xfa
//   0x14f284: 540000A8  b.hi     #0x14f298
//   0x14f288: 90000568  adrp     x8, #0x1fb000
//   0x14f28c: 9113A108  add      x8, x8, #0x4e8
static inline uint64_t fde_func_3245_0x14f280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f280ULL ^ (static_cast<uint64_t>(0x7103e81fULL) << 13);
    acc = (acc + a1 + 0x540000a8ULL) ^ 0x1ec490ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3246 | PC: 0x14f2a4 | FDE: 0x1ec4a8 | Size: 128 bytes [BDPythonVMSetNormalLogFile]
// Khung tháo gỡ #3246 | Địa chỉ PC: 0x14f2a4 | Địa chỉ FDE: 0x1ec4a8 | Kích thước: 128 bytes
//   0x14f2a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f2a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f2ac: 910043FD  add      x29, sp, #0x10
//   0x14f2b0: B4000160  cbz      x0, #0x14f2dc
static inline uint64_t fde_func_3246_0x14f2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f2a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec4a8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3247 | PC: 0x14f324 | FDE: 0x1ec4c8 | Size: 128 bytes [BDPythonVMSetErrorLogFile]
// Khung tháo gỡ #3247 | Địa chỉ PC: 0x14f324 | Địa chỉ FDE: 0x1ec4c8 | Kích thước: 128 bytes
//   0x14f324: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f328: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f32c: 910043FD  add      x29, sp, #0x10
//   0x14f330: B4000160  cbz      x0, #0x14f35c
static inline uint64_t fde_func_3247_0x14f324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f324ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec4c8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3248 | PC: 0x14f3a4 | FDE: 0x1ec4e8 | Size: 128 bytes [BDPythonVMSetExitLogFile]
// Khung tháo gỡ #3248 | Địa chỉ PC: 0x14f3a4 | Địa chỉ FDE: 0x1ec4e8 | Kích thước: 128 bytes
//   0x14f3a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f3a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f3ac: 910043FD  add      x29, sp, #0x10
//   0x14f3b0: B4000160  cbz      x0, #0x14f3dc
static inline uint64_t fde_func_3248_0x14f3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f3a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec4e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3249 | PC: 0x14f424 | FDE: 0x1ec508 | Size: 36 bytes [BDPythonVMStderr]
// Khung tháo gỡ #3249 | Địa chỉ PC: 0x14f424 | Địa chỉ FDE: 0x1ec508 | Kích thước: 36 bytes
//   0x14f424: 90000588  adrp     x8, #0x1ff000
//   0x14f428: F945D908  ldr      x8, [x8, #0xbb0]
//   0x14f42c: 90000589  adrp     x9, #0x1ff000
//   0x14f430: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_3249_0x14f424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f424ULL ^ (static_cast<uint64_t>(0x90000588ULL) << 13);
    acc = (acc + a1 + 0xf945d908ULL) ^ 0x1ec508ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3250 | PC: 0x14f448 | FDE: 0x1ec520 | Size: 36 bytes [BDPythonVMStdout]
// Khung tháo gỡ #3250 | Địa chỉ PC: 0x14f448 | Địa chỉ FDE: 0x1ec520 | Kích thước: 36 bytes
//   0x14f448: 90000588  adrp     x8, #0x1ff000
//   0x14f44c: F9446508  ldr      x8, [x8, #0x8c8]
//   0x14f450: 90000589  adrp     x9, #0x1ff000
//   0x14f454: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_3250_0x14f448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f448ULL ^ (static_cast<uint64_t>(0x90000588ULL) << 13);
    acc = (acc + a1 + 0xf9446508ULL) ^ 0x1ec520ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3251 | PC: 0x14f46c | FDE: 0x1ec538 | Size: 200 bytes [bdpythonvm_info]
// Khung tháo gỡ #3251 | Địa chỉ PC: 0x14f46c | Địa chỉ FDE: 0x1ec538 | Kích thước: 200 bytes
//   0x14f46c: D100C3FF  sub      sp, sp, #0x30
//   0x14f470: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14f474: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14f478: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3251_0x14f46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f46cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec538ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #3252 | PC: 0x14f534 | FDE: 0x1ec558 | Size: 200 bytes [bdpythonvm_error]
// Khung tháo gỡ #3252 | Địa chỉ PC: 0x14f534 | Địa chỉ FDE: 0x1ec558 | Kích thước: 200 bytes
//   0x14f534: D100C3FF  sub      sp, sp, #0x30
//   0x14f538: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14f53c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14f540: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3252_0x14f534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f534ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec558ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #3253 | PC: 0x14f5fc | FDE: 0x1ec578 | Size: 104 bytes [BDPythonVMCloseLogFiles]
// Khung tháo gỡ #3253 | Địa chỉ PC: 0x14f5fc | Địa chỉ FDE: 0x1ec578 | Kích thước: 104 bytes
//   0x14f5fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14f600: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14f604: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14f608: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3253_0x14f5fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f5fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec578ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3254 | PC: 0x14f664 | FDE: 0x1ec598 | Size: 12 bytes [PyInit__abc]
// Khung tháo gỡ #3254 | Địa chỉ PC: 0x14f664 | Địa chỉ FDE: 0x1ec598 | Kích thước: 12 bytes
//   0x14f664: B0000640  adrp     x0, #0x218000
//   0x14f668: 91374000  add      x0, x0, #0xdd0
//   0x14f66c: 17FC24ED  b        #0x58a20
static inline uint64_t fde_func_3254_0x14f664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f664ULL ^ (static_cast<uint64_t>(0xb0000640ULL) << 13);
    acc = (acc + a1 + 0x91374000ULL) ^ 0x1ec598ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3255 | PC: 0x14f670 | FDE: 0x1ec5b0 | Size: 56 bytes
// Khung tháo gỡ #3255 | Địa chỉ PC: 0x14f670 | Địa chỉ FDE: 0x1ec5b0 | Kích thước: 56 bytes
//   0x14f670: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14f674: 910003FD  mov      x29, sp
//   0x14f678: F9401008  ldr      x8, [x0, #0x20]
//   0x14f67c: F9400100  ldr      x0, [x8]
static inline uint64_t fde_func_3255_0x14f670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f670ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec5b0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3256 | PC: 0x14f6a8 | FDE: 0x1ec5d0 | Size: 56 bytes
// Khung tháo gỡ #3256 | Địa chỉ PC: 0x14f6a8 | Địa chỉ FDE: 0x1ec5d0 | Kích thước: 56 bytes
//   0x14f6a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14f6ac: 910003FD  mov      x29, sp
//   0x14f6b0: F9401008  ldr      x8, [x0, #0x20]
//   0x14f6b4: F9400100  ldr      x0, [x8]
static inline uint64_t fde_func_3256_0x14f6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f6a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec5d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3257 | PC: 0x14f6e0 | FDE: 0x1ec5f0 | Size: 40 bytes
// Khung tháo gỡ #3257 | Địa chỉ PC: 0x14f6e0 | Địa chỉ FDE: 0x1ec5f0 | Kích thước: 40 bytes
//   0x14f6e0: F9401008  ldr      x8, [x0, #0x20]
//   0x14f6e4: F9400100  ldr      x0, [x8]
//   0x14f6e8: B40000C0  cbz      x0, #0x14f700
//   0x14f6ec: F900011F  str      xzr, [x8]
static inline uint64_t fde_func_3257_0x14f6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f6e0ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x1ec5f0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3258 | PC: 0x14f708 | FDE: 0x1ec608 | Size: 12 bytes
// Khung tháo gỡ #3258 | Địa chỉ PC: 0x14f708 | Địa chỉ FDE: 0x1ec608 | Kích thước: 12 bytes
//   0x14f708: F9401008  ldr      x8, [x0, #0x20]
//   0x14f70c: F9400500  ldr      x0, [x8, #8]
//   0x14f710: 17FC2590  b        #0x58d50
static inline uint64_t fde_func_3258_0x14f708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f708ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xf9400500ULL) ^ 0x1ec608ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3259 | PC: 0x14f714 | FDE: 0x1ec620 | Size: 256 bytes
// Khung tháo gỡ #3259 | Địa chỉ PC: 0x14f714 | Địa chỉ FDE: 0x1ec620 | Kích thước: 256 bytes
//   0x14f714: D10243FF  sub      sp, sp, #0x90
//   0x14f718: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x14f71c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x14f720: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3259_0x14f714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f714ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1ec620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3260 | PC: 0x14fcc8 | FDE: 0x1ec650 | Size: 184 bytes
// Khung tháo gỡ #3260 | Địa chỉ PC: 0x14fcc8 | Địa chỉ FDE: 0x1ec650 | Kích thước: 184 bytes
//   0x14fcc8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14fccc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14fcd0: 910043FD  add      x29, sp, #0x10
//   0x14fcd4: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_3260_0x14fcc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fcc8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec650ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #3261 | PC: 0x14fd80 | FDE: 0x1ec670 | Size: 200 bytes
// Khung tháo gỡ #3261 | Địa chỉ PC: 0x14fd80 | Địa chỉ FDE: 0x1ec670 | Kích thước: 200 bytes
//   0x14fd80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14fd84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14fd88: 910043FD  add      x29, sp, #0x10
//   0x14fd8c: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_3261_0x14fd80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fd80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec670ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #3262 | PC: 0x14fe48 | FDE: 0x1ec690 | Size: 232 bytes
// Khung tháo gỡ #3262 | Địa chỉ PC: 0x14fe48 | Địa chỉ FDE: 0x1ec690 | Kích thước: 232 bytes
//   0x14fe48: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14fe4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14fe50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14fe54: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3262_0x14fe48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fe48ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec690ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3263 | PC: 0x14ff30 | FDE: 0x1ec6b0 | Size: 256 bytes
// Khung tháo gỡ #3263 | Địa chỉ PC: 0x14ff30 | Địa chỉ FDE: 0x1ec6b0 | Kích thước: 256 bytes
//   0x14ff30: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x14ff34: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x14ff38: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14ff3c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3263_0x14ff30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ff30ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec6b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3264 | PC: 0x1500d0 | FDE: 0x1ec6d8 | Size: 256 bytes
// Khung tháo gỡ #3264 | Địa chỉ PC: 0x1500d0 | Địa chỉ FDE: 0x1ec6d8 | Kích thước: 256 bytes
//   0x1500d0: D10203FF  sub      sp, sp, #0x80
//   0x1500d4: F90013FB  str      x27, [sp, #0x20]
//   0x1500d8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1500dc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3264_0x1500d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1500d0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1ec6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3265 | PC: 0x1503ec | FDE: 0x1ec708 | Size: 256 bytes
// Khung tháo gỡ #3265 | Địa chỉ PC: 0x1503ec | Địa chỉ FDE: 0x1ec708 | Kích thước: 256 bytes
//   0x1503ec: D10283FF  sub      sp, sp, #0xa0
//   0x1503f0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1503f4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1503f8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_3265_0x1503ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1503ecULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1ec708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3266 | PC: 0x150a84 | FDE: 0x1ec738 | Size: 112 bytes
// Khung tháo gỡ #3266 | Địa chỉ PC: 0x150a84 | Địa chỉ FDE: 0x1ec738 | Kích thước: 112 bytes
//   0x150a84: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x150a88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x150a8c: 910043FD  add      x29, sp, #0x10
//   0x150a90: F9409808  ldr      x8, [x0, #0x130]
static inline uint64_t fde_func_3266_0x150a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150a84ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec738ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3267 | PC: 0x150af4 | FDE: 0x1ec758 | Size: 256 bytes
// Khung tháo gỡ #3267 | Địa chỉ PC: 0x150af4 | Địa chỉ FDE: 0x1ec758 | Kích thước: 256 bytes
//   0x150af4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x150af8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x150afc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x150b00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3267_0x150af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150af4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3268 | PC: 0x150c00 | FDE: 0x1ec780 | Size: 236 bytes
// Khung tháo gỡ #3268 | Địa chỉ PC: 0x150c00 | Địa chỉ FDE: 0x1ec780 | Kích thước: 236 bytes
//   0x150c00: D10143FF  sub      sp, sp, #0x50
//   0x150c04: F90013F5  str      x21, [sp, #0x20]
//   0x150c08: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x150c0c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3268_0x150c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150c00ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ec780ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3269 | PC: 0x150cec | FDE: 0x1ec7a0 | Size: 140 bytes
// Khung tháo gỡ #3269 | Địa chỉ PC: 0x150cec | Địa chỉ FDE: 0x1ec7a0 | Kích thước: 140 bytes
//   0x150cec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x150cf0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x150cf4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x150cf8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3269_0x150cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150cecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec7a0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #3270 | PC: 0x150d78 | FDE: 0x1ec7c0 | Size: 64 bytes
// Khung tháo gỡ #3270 | Địa chỉ PC: 0x150d78 | Địa chỉ FDE: 0x1ec7c0 | Kích thước: 64 bytes
//   0x150d78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x150d7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x150d80: 910043FD  add      x29, sp, #0x10
//   0x150d84: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3270_0x150d78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150d78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec7c0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3271 | PC: 0x150db8 | FDE: 0x1ec7e0 | Size: 192 bytes
// Khung tháo gỡ #3271 | Địa chỉ PC: 0x150db8 | Địa chỉ FDE: 0x1ec7e0 | Kích thước: 192 bytes
//   0x150db8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x150dbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x150dc0: 910043FD  add      x29, sp, #0x10
//   0x150dc4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3271_0x150db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150db8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec7e0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3272 | PC: 0x150e78 | FDE: 0x1ec800 | Size: 128 bytes
// Khung tháo gỡ #3272 | Địa chỉ PC: 0x150e78 | Địa chỉ FDE: 0x1ec800 | Kích thước: 128 bytes
//   0x150e78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x150e7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x150e80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x150e84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3272_0x150e78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150e78ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec800ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3273 | PC: 0x150ef8 | FDE: 0x1ec820 | Size: 148 bytes
// Khung tháo gỡ #3273 | Địa chỉ PC: 0x150ef8 | Địa chỉ FDE: 0x1ec820 | Kích thước: 148 bytes
//   0x150ef8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x150efc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x150f00: 910043FD  add      x29, sp, #0x10
//   0x150f04: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3273_0x150ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150ef8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec820ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3274 | PC: 0x150f8c | FDE: 0x1ec840 | Size: 12 bytes [PyInit__codecs]
// Khung tháo gỡ #3274 | Địa chỉ PC: 0x150f8c | Địa chỉ FDE: 0x1ec840 | Kích thước: 12 bytes
//   0x150f8c: B0000640  adrp     x0, #0x219000
//   0x150f90: 91026000  add      x0, x0, #0x98
//   0x150f94: 17FC1EA3  b        #0x58a20
static inline uint64_t fde_func_3274_0x150f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150f8cULL ^ (static_cast<uint64_t>(0xb0000640ULL) << 13);
    acc = (acc + a1 + 0x91026000ULL) ^ 0x1ec840ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3275 | PC: 0x150f98 | FDE: 0x1ec858 | Size: 60 bytes
// Khung tháo gỡ #3275 | Địa chỉ PC: 0x150f98 | Địa chỉ FDE: 0x1ec858 | Kích thước: 60 bytes
//   0x150f98: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x150f9c: 910003FD  mov      x29, sp
//   0x150fa0: AA0103E0  mov      x0, x1
//   0x150fa4: 97FC1F1F  bl       #0x58c20
static inline uint64_t fde_func_3275_0x150f98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150f98ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec858ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3276 | PC: 0x150fd4 | FDE: 0x1ec878 | Size: 60 bytes
// Khung tháo gỡ #3276 | Địa chỉ PC: 0x150fd4 | Địa chỉ FDE: 0x1ec878 | Kích thước: 60 bytes
//   0x150fd4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x150fd8: 910003FD  mov      x29, sp
//   0x150fdc: AA0103E0  mov      x0, x1
//   0x150fe0: 97FC30B8  bl       #0x5d2c0
static inline uint64_t fde_func_3276_0x150fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150fd4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec878ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3277 | PC: 0x151010 | FDE: 0x1ec898 | Size: 188 bytes
// Khung tháo gỡ #3277 | Địa chỉ PC: 0x151010 | Địa chỉ FDE: 0x1ec898 | Kích thước: 188 bytes
//   0x151010: D100C3FF  sub      sp, sp, #0x30
//   0x151014: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x151018: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15101c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3277_0x151010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151010ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec898ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3278 | PC: 0x1510cc | FDE: 0x1ec8b8 | Size: 256 bytes
// Khung tháo gỡ #3278 | Địa chỉ PC: 0x1510cc | Địa chỉ FDE: 0x1ec8b8 | Kích thước: 256 bytes
//   0x1510cc: D10203FF  sub      sp, sp, #0x80
//   0x1510d0: F90023F7  str      x23, [sp, #0x40]
//   0x1510d4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1510d8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_3278_0x1510cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1510ccULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1ec8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3279 | PC: 0x151288 | FDE: 0x1ec8e0 | Size: 256 bytes
// Khung tháo gỡ #3279 | Địa chỉ PC: 0x151288 | Địa chỉ FDE: 0x1ec8e0 | Kích thước: 256 bytes
//   0x151288: D10203FF  sub      sp, sp, #0x80
//   0x15128c: F90023F7  str      x23, [sp, #0x40]
//   0x151290: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x151294: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_3279_0x151288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151288ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1ec8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3280 | PC: 0x151444 | FDE: 0x1ec908 | Size: 256 bytes
// Khung tháo gỡ #3280 | Địa chỉ PC: 0x151444 | Địa chỉ FDE: 0x1ec908 | Kích thước: 256 bytes
//   0x151444: D10103FF  sub      sp, sp, #0x40
//   0x151448: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x15144c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x151450: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3280_0x151444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151444ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3281 | PC: 0x1516c0 | FDE: 0x1ec930 | Size: 256 bytes
// Khung tháo gỡ #3281 | Địa chỉ PC: 0x1516c0 | Địa chỉ FDE: 0x1ec930 | Kích thước: 256 bytes
//   0x1516c0: D10283FF  sub      sp, sp, #0xa0
//   0x1516c4: F9003BF5  str      x21, [sp, #0x70]
//   0x1516c8: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x1516cc: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3281_0x1516c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1516c0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1ec930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3282 | PC: 0x1518ac | FDE: 0x1ec950 | Size: 256 bytes
// Khung tháo gỡ #3282 | Địa chỉ PC: 0x1518ac | Địa chỉ FDE: 0x1ec950 | Kích thước: 256 bytes
//   0x1518ac: D10103FF  sub      sp, sp, #0x40
//   0x1518b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1518b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1518b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3282_0x1518ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1518acULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3283 | PC: 0x151a24 | FDE: 0x1ec978 | Size: 256 bytes
// Khung tháo gỡ #3283 | Địa chỉ PC: 0x151a24 | Địa chỉ FDE: 0x1ec978 | Kích thước: 256 bytes
//   0x151a24: D10243FF  sub      sp, sp, #0x90
//   0x151a28: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x151a2c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x151a30: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_3283_0x151a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151a24ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x1ec978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3284 | PC: 0x151c18 | FDE: 0x1ec9a0 | Size: 256 bytes
// Khung tháo gỡ #3284 | Địa chỉ PC: 0x151c18 | Địa chỉ FDE: 0x1ec9a0 | Kích thước: 256 bytes
//   0x151c18: D10103FF  sub      sp, sp, #0x40
//   0x151c1c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x151c20: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x151c24: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3284_0x151c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151c18ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3285 | PC: 0x151d90 | FDE: 0x1ec9c8 | Size: 256 bytes
// Khung tháo gỡ #3285 | Địa chỉ PC: 0x151d90 | Địa chỉ FDE: 0x1ec9c8 | Kích thước: 256 bytes
//   0x151d90: D10283FF  sub      sp, sp, #0xa0
//   0x151d94: F9003BF5  str      x21, [sp, #0x70]
//   0x151d98: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x151d9c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3285_0x151d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151d90ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1ec9c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3286 | PC: 0x151f34 | FDE: 0x1ec9e8 | Size: 256 bytes
// Khung tháo gỡ #3286 | Địa chỉ PC: 0x151f34 | Địa chỉ FDE: 0x1ec9e8 | Kích thước: 256 bytes
//   0x151f34: D10103FF  sub      sp, sp, #0x40
//   0x151f38: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x151f3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x151f40: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3286_0x151f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151f34ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec9e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3287 | PC: 0x1520ac | FDE: 0x1eca10 | Size: 256 bytes
// Khung tháo gỡ #3287 | Địa chỉ PC: 0x1520ac | Địa chỉ FDE: 0x1eca10 | Kích thước: 256 bytes
//   0x1520ac: D10283FF  sub      sp, sp, #0xa0
//   0x1520b0: F9003BF5  str      x21, [sp, #0x70]
//   0x1520b4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x1520b8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3287_0x1520ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1520acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1eca10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3288 | PC: 0x152250 | FDE: 0x1eca30 | Size: 256 bytes
// Khung tháo gỡ #3288 | Địa chỉ PC: 0x152250 | Địa chỉ FDE: 0x1eca30 | Kích thước: 256 bytes
//   0x152250: D10283FF  sub      sp, sp, #0xa0
//   0x152254: F9003BF5  str      x21, [sp, #0x70]
//   0x152258: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x15225c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3288_0x152250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152250ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1eca30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3289 | PC: 0x152428 | FDE: 0x1eca50 | Size: 256 bytes
// Khung tháo gỡ #3289 | Địa chỉ PC: 0x152428 | Địa chỉ FDE: 0x1eca50 | Kích thước: 256 bytes
//   0x152428: D10103FF  sub      sp, sp, #0x40
//   0x15242c: F9000BF5  str      x21, [sp, #0x10]
//   0x152430: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x152434: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3289_0x152428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152428ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1eca50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3290 | PC: 0x152540 | FDE: 0x1eca70 | Size: 188 bytes
// Khung tháo gỡ #3290 | Địa chỉ PC: 0x152540 | Địa chỉ FDE: 0x1eca70 | Kích thước: 188 bytes
//   0x152540: D100C3FF  sub      sp, sp, #0x30
//   0x152544: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x152548: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15254c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3290_0x152540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152540ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eca70ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3291 | PC: 0x1525fc | FDE: 0x1eca90 | Size: 12 bytes [PyInit__collections]
// Khung tháo gỡ #3291 | Địa chỉ PC: 0x1525fc | Địa chỉ FDE: 0x1eca90 | Kích thước: 12 bytes
//   0x1525fc: F0000620  adrp     x0, #0x219000
//   0x152600: 910E8000  add      x0, x0, #0x3a0
//   0x152604: 17FC1907  b        #0x58a20
static inline uint64_t fde_func_3291_0x1525fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1525fcULL ^ (static_cast<uint64_t>(0xf0000620ULL) << 13);
    acc = (acc + a1 + 0x910e8000ULL) ^ 0x1eca90ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3292 | PC: 0x152608 | FDE: 0x1ecaa8 | Size: 256 bytes
// Khung tháo gỡ #3292 | Địa chỉ PC: 0x152608 | Địa chỉ FDE: 0x1ecaa8 | Kích thước: 256 bytes
//   0x152608: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x15260c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x152610: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x152614: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3292_0x152608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152608ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ecaa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3293 | PC: 0x1529a0 | FDE: 0x1ecad8 | Size: 148 bytes
// Khung tháo gỡ #3293 | Địa chỉ PC: 0x1529a0 | Địa chỉ FDE: 0x1ecad8 | Kích thước: 148 bytes
//   0x1529a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1529a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1529a8: 910043FD  add      x29, sp, #0x10
//   0x1529ac: B0000569  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3293_0x1529a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1529a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecad8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3294 | PC: 0x152a34 | FDE: 0x1ecaf8 | Size: 132 bytes
// Khung tháo gỡ #3294 | Địa chỉ PC: 0x152a34 | Địa chỉ FDE: 0x1ecaf8 | Kích thước: 132 bytes
//   0x152a34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x152a38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x152a3c: 910043FD  add      x29, sp, #0x10
//   0x152a40: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3294_0x152a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152a34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecaf8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #3295 | PC: 0x152ab8 | FDE: 0x1ecb18 | Size: 212 bytes
// Khung tháo gỡ #3295 | Địa chỉ PC: 0x152ab8 | Địa chỉ FDE: 0x1ecb18 | Kích thước: 212 bytes
//   0x152ab8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x152abc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x152ac0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x152ac4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3295_0x152ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152ab8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ecb18ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #3296 | PC: 0x152b8c | FDE: 0x1ecb38 | Size: 216 bytes
// Khung tháo gỡ #3296 | Địa chỉ PC: 0x152b8c | Địa chỉ FDE: 0x1ecb38 | Kích thước: 216 bytes
//   0x152b8c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x152b90: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x152b94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x152b98: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3296_0x152b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152b8cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ecb38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #3297 | PC: 0x152c64 | FDE: 0x1ecb60 | Size: 256 bytes
// Khung tháo gỡ #3297 | Địa chỉ PC: 0x152c64 | Địa chỉ FDE: 0x1ecb60 | Kích thước: 256 bytes
//   0x152c64: D10183FF  sub      sp, sp, #0x60
//   0x152c68: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x152c6c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x152c70: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3297_0x152c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152c64ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ecb60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3298 | PC: 0x152e80 | FDE: 0x1ecb90 | Size: 256 bytes
// Khung tháo gỡ #3298 | Địa chỉ PC: 0x152e80 | Địa chỉ FDE: 0x1ecb90 | Kích thước: 256 bytes
//   0x152e80: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x152e84: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x152e88: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x152e8c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3298_0x152e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152e80ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ecb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3299 | PC: 0x153160 | FDE: 0x1ecbb8 | Size: 108 bytes
// Khung tháo gỡ #3299 | Địa chỉ PC: 0x153160 | Địa chỉ FDE: 0x1ecbb8 | Kích thước: 108 bytes
//   0x153160: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x153164: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x153168: 910043FD  add      x29, sp, #0x10
//   0x15316c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3299_0x153160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153160ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecbb8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3300 | PC: 0x1531cc | FDE: 0x1ecbd8 | Size: 256 bytes
// Khung tháo gỡ #3300 | Địa chỉ PC: 0x1531cc | Địa chỉ FDE: 0x1ecbd8 | Kích thước: 256 bytes
//   0x1531cc: D10143FF  sub      sp, sp, #0x50
//   0x1531d0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1531d4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1531d8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_3300_0x1531cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1531ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1ecbd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3301 | PC: 0x153334 | FDE: 0x1ecbf8 | Size: 176 bytes
// Khung tháo gỡ #3301 | Địa chỉ PC: 0x153334 | Địa chỉ FDE: 0x1ecbf8 | Kích thước: 176 bytes
//   0x153334: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x153338: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15333c: 910043FD  add      x29, sp, #0x10
//   0x153340: F9409808  ldr      x8, [x0, #0x130]
static inline uint64_t fde_func_3301_0x153334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153334ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecbf8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3302 | PC: 0x1533e4 | FDE: 0x1ecc18 | Size: 16 bytes
// Khung tháo gỡ #3302 | Địa chỉ PC: 0x1533e4 | Địa chỉ FDE: 0x1ecc18 | Kích thước: 16 bytes
//   0x1533e4: F9400808  ldr      x8, [x0, #0x10]
//   0x1533e8: F100011F  cmp      x8, #0
//   0x1533ec: 1A9F07E0  cset     w0, ne
//   0x1533f0: D65F03C0  ret      
static inline uint64_t fde_func_3302_0x1533e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1533e4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x1ecc18ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3303 | PC: 0x1533f4 | FDE: 0x1ecc30 | Size: 8 bytes
// Khung tháo gỡ #3303 | Địa chỉ PC: 0x1533f4 | Địa chỉ FDE: 0x1ecc30 | Kích thước: 8 bytes
//   0x1533f4: F9400800  ldr      x0, [x0, #0x10]
//   0x1533f8: D65F03C0  ret      
static inline uint64_t fde_func_3303_0x1533f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1533f4ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ecc30ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3304 | PC: 0x1533fc | FDE: 0x1ecc48 | Size: 188 bytes
// Khung tháo gỡ #3304 | Địa chỉ PC: 0x1533fc | Địa chỉ FDE: 0x1ecc48 | Kích thước: 188 bytes
//   0x1533fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x153400: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x153404: 910043FD  add      x29, sp, #0x10
//   0x153408: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_3304_0x1533fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1533fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecc48ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3305 | PC: 0x1534b8 | FDE: 0x1ecc68 | Size: 92 bytes
// Khung tháo gỡ #3305 | Địa chỉ PC: 0x1534b8 | Địa chỉ FDE: 0x1ecc68 | Kích thước: 92 bytes
//   0x1534b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1534bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1534c0: 910043FD  add      x29, sp, #0x10
//   0x1534c4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_3305_0x1534b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1534b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecc68ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3306 | PC: 0x153514 | FDE: 0x1ecc88 | Size: 216 bytes
// Khung tháo gỡ #3306 | Địa chỉ PC: 0x153514 | Địa chỉ FDE: 0x1ecc88 | Kích thước: 216 bytes
//   0x153514: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x153518: 910003FD  mov      x29, sp
//   0x15351c: F9400808  ldr      x8, [x0, #0x10]
//   0x153520: EB01011F  cmp      x8, x1
static inline uint64_t fde_func_3306_0x153514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153514ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ecc88ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #3307 | PC: 0x1535ec | FDE: 0x1ecca8 | Size: 256 bytes
// Khung tháo gỡ #3307 | Địa chỉ PC: 0x1535ec | Địa chỉ FDE: 0x1ecca8 | Kích thước: 256 bytes
//   0x1535ec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1535f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1535f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1535f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3307_0x1535ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1535ecULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ecca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3308 | PC: 0x1537cc | FDE: 0x1eccd0 | Size: 236 bytes
// Khung tháo gỡ #3308 | Địa chỉ PC: 0x1537cc | Địa chỉ FDE: 0x1eccd0 | Kích thước: 236 bytes
//   0x1537cc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1537d0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1537d4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1537d8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3308_0x1537cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1537ccULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eccd0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3309 | PC: 0x1538b8 | FDE: 0x1ecd00 | Size: 80 bytes
// Khung tháo gỡ #3309 | Địa chỉ PC: 0x1538b8 | Địa chỉ FDE: 0x1ecd00 | Kích thước: 80 bytes
//   0x1538b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1538bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1538c0: 910043FD  add      x29, sp, #0x10
//   0x1538c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3309_0x1538b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1538b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecd00ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3310 | PC: 0x153908 | FDE: 0x1ecd20 | Size: 256 bytes
// Khung tháo gỡ #3310 | Địa chỉ PC: 0x153908 | Địa chỉ FDE: 0x1ecd20 | Kích thước: 256 bytes
//   0x153908: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x15390c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x153910: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x153914: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3310_0x153908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153908ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ecd20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3311 | PC: 0x153b90 | FDE: 0x1ecd48 | Size: 256 bytes
// Khung tháo gỡ #3311 | Địa chỉ PC: 0x153b90 | Địa chỉ FDE: 0x1ecd48 | Kích thước: 256 bytes
//   0x153b90: D10183FF  sub      sp, sp, #0x60
//   0x153b94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x153b98: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x153b9c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3311_0x153b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153b90ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1ecd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3312 | PC: 0x153de0 | FDE: 0x1ecd70 | Size: 256 bytes
// Khung tháo gỡ #3312 | Địa chỉ PC: 0x153de0 | Địa chỉ FDE: 0x1ecd70 | Kích thước: 256 bytes
//   0x153de0: D101C3FF  sub      sp, sp, #0x70
//   0x153de4: F9000BFB  str      x27, [sp, #0x10]
//   0x153de8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x153dec: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3312_0x153de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153de0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1ecd70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3313 | PC: 0x1540a4 | FDE: 0x1ecda0 | Size: 256 bytes
// Khung tháo gỡ #3313 | Địa chỉ PC: 0x1540a4 | Địa chỉ FDE: 0x1ecda0 | Kích thước: 256 bytes
//   0x1540a4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1540a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1540ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1540b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3313_0x1540a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1540a4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ecda0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3314 | PC: 0x154228 | FDE: 0x1ecdc8 | Size: 208 bytes
// Khung tháo gỡ #3314 | Địa chỉ PC: 0x154228 | Địa chỉ FDE: 0x1ecdc8 | Kích thước: 208 bytes
//   0x154228: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15422c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x154230: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x154234: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3314_0x154228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154228ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ecdc8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #3315 | PC: 0x1542f8 | FDE: 0x1ecde8 | Size: 256 bytes
// Khung tháo gỡ #3315 | Địa chỉ PC: 0x1542f8 | Địa chỉ FDE: 0x1ecde8 | Kích thước: 256 bytes
//   0x1542f8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1542fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x154300: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x154304: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3315_0x1542f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1542f8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ecde8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3316 | PC: 0x154708 | FDE: 0x1ece18 | Size: 212 bytes
// Khung tháo gỡ #3316 | Địa chỉ PC: 0x154708 | Địa chỉ FDE: 0x1ece18 | Kích thước: 212 bytes
//   0x154708: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15470c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x154710: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x154714: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3316_0x154708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154708ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ece18ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #3317 | PC: 0x1547dc | FDE: 0x1ece38 | Size: 68 bytes
// Khung tháo gỡ #3317 | Địa chỉ PC: 0x1547dc | Địa chỉ FDE: 0x1ece38 | Kích thước: 68 bytes
//   0x1547dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1547e0: 910003FD  mov      x29, sp
//   0x1547e4: F9400028  ldr      x8, [x1]
//   0x1547e8: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_3317_0x1547dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1547dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ece38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3318 | PC: 0x154820 | FDE: 0x1ece58 | Size: 40 bytes
// Khung tháo gỡ #3318 | Địa chỉ PC: 0x154820 | Địa chỉ FDE: 0x1ece58 | Kích thước: 40 bytes
//   0x154820: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x154824: 910003FD  mov      x29, sp
//   0x154828: 97FFF90F  bl       #0x152c64
//   0x15482c: F0000540  adrp     x0, #0x1ff000
static inline uint64_t fde_func_3318_0x154820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154820ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ece58ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3319 | PC: 0x154848 | FDE: 0x1ece78 | Size: 256 bytes
// Khung tháo gỡ #3319 | Địa chỉ PC: 0x154848 | Địa chỉ FDE: 0x1ece78 | Kích thước: 256 bytes
//   0x154848: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x15484c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x154850: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x154854: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3319_0x154848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154848ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ece78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3320 | PC: 0x15495c | FDE: 0x1ecea8 | Size: 256 bytes
// Khung tháo gỡ #3320 | Địa chỉ PC: 0x15495c | Địa chỉ FDE: 0x1ecea8 | Kích thước: 256 bytes
//   0x15495c: D101C3FF  sub      sp, sp, #0x70
//   0x154960: F9000BFB  str      x27, [sp, #0x10]
//   0x154964: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x154968: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3320_0x15495c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15495cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1ecea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3321 | PC: 0x154c2c | FDE: 0x1eced8 | Size: 256 bytes
// Khung tháo gỡ #3321 | Địa chỉ PC: 0x154c2c | Địa chỉ FDE: 0x1eced8 | Kích thước: 256 bytes
//   0x154c2c: D10183FF  sub      sp, sp, #0x60
//   0x154c30: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x154c34: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x154c38: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3321_0x154c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154c2cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1eced8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3322 | PC: 0x154e54 | FDE: 0x1ecf00 | Size: 256 bytes
// Khung tháo gỡ #3322 | Địa chỉ PC: 0x154e54 | Địa chỉ FDE: 0x1ecf00 | Kích thước: 256 bytes
//   0x154e54: D101C3FF  sub      sp, sp, #0x70
//   0x154e58: F90013F9  str      x25, [sp, #0x20]
//   0x154e5c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x154e60: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3322_0x154e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154e54ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1ecf00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3323 | PC: 0x155238 | FDE: 0x1ecf28 | Size: 220 bytes
// Khung tháo gỡ #3323 | Địa chỉ PC: 0x155238 | Địa chỉ FDE: 0x1ecf28 | Kích thước: 220 bytes
//   0x155238: D100C3FF  sub      sp, sp, #0x30
//   0x15523c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x155240: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x155244: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3323_0x155238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155238ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ecf28ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #3324 | PC: 0x155314 | FDE: 0x1ecf48 | Size: 256 bytes
// Khung tháo gỡ #3324 | Địa chỉ PC: 0x155314 | Địa chỉ FDE: 0x1ecf48 | Kích thước: 256 bytes
//   0x155314: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x155318: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x15531c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x155320: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3324_0x155314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155314ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ecf48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3325 | PC: 0x155540 | FDE: 0x1ecf78 | Size: 108 bytes
// Khung tháo gỡ #3325 | Địa chỉ PC: 0x155540 | Địa chỉ FDE: 0x1ecf78 | Kích thước: 108 bytes
//   0x155540: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x155544: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155548: 910043FD  add      x29, sp, #0x10
//   0x15554c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3325_0x155540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155540ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecf78ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3326 | PC: 0x1555ac | FDE: 0x1ecf98 | Size: 140 bytes
// Khung tháo gỡ #3326 | Địa chỉ PC: 0x1555ac | Địa chỉ FDE: 0x1ecf98 | Kích thước: 140 bytes
//   0x1555ac: F940080B  ldr      x11, [x0, #0x10]
//   0x1555b0: F100097F  cmp      x11, #2
//   0x1555b4: 5400036B  b.lt     #0x155620
//   0x1555b8: A942B00A  ldp      x10, x12, [x0, #0x28]
static inline uint64_t fde_func_3326_0x1555ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1555acULL ^ (static_cast<uint64_t>(0xf940080bULL) << 13);
    acc = (acc + a1 + 0xf100097fULL) ^ 0x1ecf98ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #3327 | PC: 0x155638 | FDE: 0x1ecfb0 | Size: 212 bytes
// Khung tháo gỡ #3327 | Địa chỉ PC: 0x155638 | Địa chỉ FDE: 0x1ecfb0 | Kích thước: 212 bytes
//   0x155638: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15563c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x155640: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x155644: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3327_0x155638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155638ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ecfb0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #3328 | PC: 0x15570c | FDE: 0x1ecfd0 | Size: 36 bytes
// Khung tháo gỡ #3328 | Địa chỉ PC: 0x15570c | Địa chỉ FDE: 0x1ecfd0 | Kích thước: 36 bytes
//   0x15570c: A940A809  ldp      x9, x10, [x0, #8]
//   0x155710: F9401408  ldr      x8, [x0, #0x28]
//   0x155714: F9401129  ldr      x9, [x9, #0x20]
//   0x155718: 8B0A0108  add      x8, x8, x10
static inline uint64_t fde_func_3328_0x15570c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15570cULL ^ (static_cast<uint64_t>(0xa940a809ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x1ecfd0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3329 | PC: 0x155730 | FDE: 0x1ecfe8 | Size: 248 bytes
// Khung tháo gỡ #3329 | Địa chỉ PC: 0x155730 | Địa chỉ FDE: 0x1ecfe8 | Kích thước: 248 bytes
//   0x155730: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x155734: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155738: 910043FD  add      x29, sp, #0x10
//   0x15573c: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_3329_0x155730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155730ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ecfe8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3330 | PC: 0x155828 | FDE: 0x1ed008 | Size: 36 bytes
// Khung tháo gỡ #3330 | Địa chỉ PC: 0x155828 | Địa chỉ FDE: 0x1ed008 | Kích thước: 36 bytes
//   0x155828: F9402000  ldr      x0, [x0, #0x40]
//   0x15582c: B7F80040  tbnz     x0, #0x3f, #0x155834
//   0x155830: 17FC1394  b        #0x5a680
//   0x155834: D0000540  adrp     x0, #0x1ff000
static inline uint64_t fde_func_3330_0x155828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155828ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb7f80040ULL) ^ 0x1ed008ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3331 | PC: 0x15584c | FDE: 0x1ed020 | Size: 80 bytes
// Khung tháo gỡ #3331 | Địa chỉ PC: 0x15584c | Địa chỉ FDE: 0x1ed020 | Kích thước: 80 bytes
//   0x15584c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x155850: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155854: 910043FD  add      x29, sp, #0x10
//   0x155858: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3331_0x15584c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15584cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed020ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3332 | PC: 0x15589c | FDE: 0x1ed040 | Size: 256 bytes
// Khung tháo gỡ #3332 | Địa chỉ PC: 0x15589c | Địa chỉ FDE: 0x1ed040 | Kích thước: 256 bytes
//   0x15589c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1558a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1558a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1558a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3332_0x15589c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15589cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3333 | PC: 0x1559a0 | FDE: 0x1ed060 | Size: 104 bytes
// Khung tháo gỡ #3333 | Địa chỉ PC: 0x1559a0 | Địa chỉ FDE: 0x1ed060 | Kích thước: 104 bytes
//   0x1559a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1559a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1559a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1559ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3333_0x1559a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1559a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed060ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3334 | PC: 0x155a08 | FDE: 0x1ed080 | Size: 76 bytes
// Khung tháo gỡ #3334 | Địa chỉ PC: 0x155a08 | Địa chỉ FDE: 0x1ed080 | Kích thước: 76 bytes
//   0x155a08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x155a0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155a10: 910043FD  add      x29, sp, #0x10
//   0x155a14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3334_0x155a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155a08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed080ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3335 | PC: 0x155a54 | FDE: 0x1ed0a0 | Size: 256 bytes
// Khung tháo gỡ #3335 | Địa chỉ PC: 0x155a54 | Địa chỉ FDE: 0x1ed0a0 | Kích thước: 256 bytes
//   0x155a54: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x155a58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x155a5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x155a60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3335_0x155a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155a54ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ed0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3336 | PC: 0x155b88 | FDE: 0x1ed0c8 | Size: 212 bytes
// Khung tháo gỡ #3336 | Địa chỉ PC: 0x155b88 | Địa chỉ FDE: 0x1ed0c8 | Kích thước: 212 bytes
//   0x155b88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x155b8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155b90: 910043FD  add      x29, sp, #0x10
//   0x155b94: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3336_0x155b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155b88ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed0c8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #3337 | PC: 0x155c5c | FDE: 0x1ed0e8 | Size: 256 bytes
// Khung tháo gỡ #3337 | Địa chỉ PC: 0x155c5c | Địa chỉ FDE: 0x1ed0e8 | Kích thước: 256 bytes
//   0x155c5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x155c60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x155c64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x155c68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3337_0x155c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155c5cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed0e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3338 | PC: 0x155d84 | FDE: 0x1ed110 | Size: 36 bytes
// Khung tháo gỡ #3338 | Địa chỉ PC: 0x155d84 | Địa chỉ FDE: 0x1ed110 | Kích thước: 36 bytes
//   0x155d84: F9401808  ldr      x8, [x0, #0x30]
//   0x155d88: D0000549  adrp     x9, #0x1ff000
//   0x155d8c: AA0003E2  mov      x2, x0
//   0x155d90: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_3338_0x155d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155d84ULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0xd0000549ULL) ^ 0x1ed110ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3339 | PC: 0x155da8 | FDE: 0x1ed128 | Size: 256 bytes
// Khung tháo gỡ #3339 | Địa chỉ PC: 0x155da8 | Địa chỉ FDE: 0x1ed128 | Kích thước: 256 bytes
//   0x155da8: D10143FF  sub      sp, sp, #0x50
//   0x155dac: F9000BF7  str      x23, [sp, #0x10]
//   0x155db0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x155db4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3339_0x155da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155da8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1ed128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3340 | PC: 0x155f18 | FDE: 0x1ed150 | Size: 64 bytes
// Khung tháo gỡ #3340 | Địa chỉ PC: 0x155f18 | Địa chỉ FDE: 0x1ed150 | Kích thước: 64 bytes
//   0x155f18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x155f1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155f20: 910043FD  add      x29, sp, #0x10
//   0x155f24: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3340_0x155f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155f18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed150ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3341 | PC: 0x155f58 | FDE: 0x1ed170 | Size: 52 bytes
// Khung tháo gỡ #3341 | Địa chỉ PC: 0x155f58 | Địa chỉ FDE: 0x1ed170 | Kích thước: 52 bytes
//   0x155f58: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x155f5c: 910003FD  mov      x29, sp
//   0x155f60: F9401000  ldr      x0, [x0, #0x20]
//   0x155f64: B40000E0  cbz      x0, #0x155f80
static inline uint64_t fde_func_3341_0x155f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155f58ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed170ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3342 | PC: 0x155f8c | FDE: 0x1ed190 | Size: 144 bytes
// Khung tháo gỡ #3342 | Địa chỉ PC: 0x155f8c | Địa chỉ FDE: 0x1ed190 | Kích thước: 144 bytes
//   0x155f8c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x155f90: 910003FD  mov      x29, sp
//   0x155f94: A9422408  ldp      x8, x9, [x0, #0x20]
//   0x155f98: F9401D08  ldr      x8, [x8, #0x38]
static inline uint64_t fde_func_3342_0x155f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155f8cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed190ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3343 | PC: 0x15601c | FDE: 0x1ed1b0 | Size: 256 bytes
// Khung tháo gỡ #3343 | Địa chỉ PC: 0x15601c | Địa chỉ FDE: 0x1ed1b0 | Kích thước: 256 bytes
//   0x15601c: D10143FF  sub      sp, sp, #0x50
//   0x156020: F90013F5  str      x21, [sp, #0x20]
//   0x156024: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x156028: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3343_0x15601c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15601cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ed1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3344 | PC: 0x1561b0 | FDE: 0x1ed1d0 | Size: 8 bytes
// Khung tháo gỡ #3344 | Địa chỉ PC: 0x1561b0 | Địa chỉ FDE: 0x1ed1d0 | Kích thước: 8 bytes
//   0x1561b0: F9401800  ldr      x0, [x0, #0x30]
//   0x1561b4: 17FC1133  b        #0x5a680
static inline uint64_t fde_func_3344_0x1561b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1561b0ULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0x17fc1133ULL) ^ 0x1ed1d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3345 | PC: 0x1561b8 | FDE: 0x1ed1e8 | Size: 32 bytes
// Khung tháo gỡ #3345 | Địa chỉ PC: 0x1561b8 | Địa chỉ FDE: 0x1ed1e8 | Kích thước: 32 bytes
//   0x1561b8: F9401002  ldr      x2, [x0, #0x20]
//   0x1561bc: F9401808  ldr      x8, [x0, #0x30]
//   0x1561c0: F9400401  ldr      x1, [x0, #8]
//   0x1561c4: F0000260  adrp     x0, #0x1a5000
static inline uint64_t fde_func_3345_0x1561b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1561b8ULL ^ (static_cast<uint64_t>(0xf9401002ULL) << 13);
    acc = (acc + a1 + 0xf9401808ULL) ^ 0x1ed1e8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3346 | PC: 0x1561d8 | FDE: 0x1ed200 | Size: 144 bytes
// Khung tháo gỡ #3346 | Địa chỉ PC: 0x1561d8 | Địa chỉ FDE: 0x1ed200 | Kích thước: 144 bytes
//   0x1561d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1561dc: 910003FD  mov      x29, sp
//   0x1561e0: F940180A  ldr      x10, [x0, #0x30]
//   0x1561e4: B40003AA  cbz      x10, #0x156258
static inline uint64_t fde_func_3346_0x1561d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1561d8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed200ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3347 | PC: 0x156268 | FDE: 0x1ed220 | Size: 256 bytes
// Khung tháo gỡ #3347 | Địa chỉ PC: 0x156268 | Địa chỉ FDE: 0x1ed220 | Kích thước: 256 bytes
//   0x156268: D10143FF  sub      sp, sp, #0x50
//   0x15626c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x156270: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x156274: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3347_0x156268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156268ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ed220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3348 | PC: 0x156404 | FDE: 0x1ed248 | Size: 76 bytes
// Khung tháo gỡ #3348 | Địa chỉ PC: 0x156404 | Địa chỉ FDE: 0x1ed248 | Kích thước: 76 bytes
//   0x156404: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x156408: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15640c: 910043FD  add      x29, sp, #0x10
//   0x156410: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3348_0x156404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156404ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed248ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3349 | PC: 0x156450 | FDE: 0x1ed268 | Size: 56 bytes
// Khung tháo gỡ #3349 | Địa chỉ PC: 0x156450 | Địa chỉ FDE: 0x1ed268 | Kích thước: 56 bytes
//   0x156450: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x156454: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x156458: 910043FD  add      x29, sp, #0x10
//   0x15645c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3349_0x156450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156450ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed268ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3350 | PC: 0x156488 | FDE: 0x1ed288 | Size: 52 bytes
// Khung tháo gỡ #3350 | Địa chỉ PC: 0x156488 | Địa chỉ FDE: 0x1ed288 | Kích thước: 52 bytes
//   0x156488: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15648c: 910003FD  mov      x29, sp
//   0x156490: F9400C00  ldr      x0, [x0, #0x18]
//   0x156494: B40000E0  cbz      x0, #0x1564b0
static inline uint64_t fde_func_3350_0x156488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156488ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed288ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3351 | PC: 0x1564bc | FDE: 0x1ed2a8 | Size: 56 bytes
// Khung tháo gỡ #3351 | Địa chỉ PC: 0x1564bc | Địa chỉ FDE: 0x1ed2a8 | Kích thước: 56 bytes
//   0x1564bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1564c0: 910003FD  mov      x29, sp
//   0x1564c4: AA0003E8  mov      x8, x0
//   0x1564c8: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_3351_0x1564bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1564bcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed2a8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3352 | PC: 0x1564f4 | FDE: 0x1ed2c8 | Size: 152 bytes
// Khung tháo gỡ #3352 | Địa chỉ PC: 0x1564f4 | Địa chỉ FDE: 0x1ed2c8 | Kích thước: 152 bytes
//   0x1564f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1564f8: 910003FD  mov      x29, sp
//   0x1564fc: B40002C1  cbz      x1, #0x156554
//   0x156500: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_3352_0x1564f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1564f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed2c8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3353 | PC: 0x15658c | FDE: 0x1ed2e8 | Size: 60 bytes
// Khung tháo gỡ #3353 | Địa chỉ PC: 0x15658c | Địa chỉ FDE: 0x1ed2e8 | Kích thước: 60 bytes
//   0x15658c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x156590: 910003FD  mov      x29, sp
//   0x156594: B0000548  adrp     x8, #0x1ff000
//   0x156598: F9470108  ldr      x8, [x8, #0xe00]
static inline uint64_t fde_func_3353_0x15658c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15658cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed2e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3354 | PC: 0x1565c8 | FDE: 0x1ed308 | Size: 248 bytes
// Khung tháo gỡ #3354 | Địa chỉ PC: 0x1565c8 | Địa chỉ FDE: 0x1ed308 | Kích thước: 248 bytes
//   0x1565c8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1565cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1565d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1565d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3354_0x1565c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1565c8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed308ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3355 | PC: 0x1566c0 | FDE: 0x1ed330 | Size: 20 bytes
// Khung tháo gỡ #3355 | Địa chỉ PC: 0x1566c0 | Địa chỉ FDE: 0x1ed330 | Kích thước: 20 bytes
//   0x1566c0: A9408801  ldp      x1, x2, [x0, #8]
//   0x1566c4: F9400C03  ldr      x3, [x0, #0x18]
//   0x1566c8: 90000360  adrp     x0, #0x1c2000
//   0x1566cc: 910AE000  add      x0, x0, #0x2b8
static inline uint64_t fde_func_3355_0x1566c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1566c0ULL ^ (static_cast<uint64_t>(0xa9408801ULL) << 13);
    acc = (acc + a1 + 0xf9400c03ULL) ^ 0x1ed330ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #3356 | PC: 0x1566d4 | FDE: 0x1ed348 | Size: 12 bytes [PyInit__functools]
// Khung tháo gỡ #3356 | Địa chỉ PC: 0x1566d4 | Địa chỉ FDE: 0x1ed348 | Kích thước: 12 bytes
//   0x1566d4: 90000620  adrp     x0, #0x21a000
//   0x1566d8: 91100000  add      x0, x0, #0x400
//   0x1566dc: 17FC08D1  b        #0x58a20
static inline uint64_t fde_func_3356_0x1566d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1566d4ULL ^ (static_cast<uint64_t>(0x90000620ULL) << 13);
    acc = (acc + a1 + 0x91100000ULL) ^ 0x1ed348ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3357 | PC: 0x1566e0 | FDE: 0x1ed360 | Size: 128 bytes
// Khung tháo gỡ #3357 | Địa chỉ PC: 0x1566e0 | Địa chỉ FDE: 0x1ed360 | Kích thước: 128 bytes
//   0x1566e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1566e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1566e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1566ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3357_0x1566e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1566e0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed360ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3358 | PC: 0x156760 | FDE: 0x1ed380 | Size: 192 bytes
// Khung tháo gỡ #3358 | Địa chỉ PC: 0x156760 | Địa chỉ FDE: 0x1ed380 | Kích thước: 192 bytes
//   0x156760: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x156764: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x156768: 910043FD  add      x29, sp, #0x10
//   0x15676c: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3358_0x156760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156760ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed380ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3359 | PC: 0x156820 | FDE: 0x1ed3a0 | Size: 4 bytes
// Khung tháo gỡ #3359 | Địa chỉ PC: 0x156820 | Địa chỉ FDE: 0x1ed3a0 | Kích thước: 4 bytes
//   0x156820: 17FFFFD0  b        #0x156760
static inline uint64_t fde_func_3359_0x156820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156820ULL ^ (static_cast<uint64_t>(0x17ffffd0ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x1ed3a0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3360 | PC: 0x156824 | FDE: 0x1ed3b8 | Size: 256 bytes
// Khung tháo gỡ #3360 | Địa chỉ PC: 0x156824 | Địa chỉ FDE: 0x1ed3b8 | Kích thước: 256 bytes
//   0x156824: D10143FF  sub      sp, sp, #0x50
//   0x156828: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x15682c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x156830: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3360_0x156824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156824ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ed3b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3361 | PC: 0x156a64 | FDE: 0x1ed3e0 | Size: 168 bytes
// Khung tháo gỡ #3361 | Địa chỉ PC: 0x156a64 | Địa chỉ FDE: 0x1ed3e0 | Kích thước: 168 bytes
//   0x156a64: D100C3FF  sub      sp, sp, #0x30
//   0x156a68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x156a6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x156a70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3361_0x156a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156a64ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed3e0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #3362 | PC: 0x156b0c | FDE: 0x1ed400 | Size: 256 bytes
// Khung tháo gỡ #3362 | Địa chỉ PC: 0x156b0c | Địa chỉ FDE: 0x1ed400 | Kích thước: 256 bytes
//   0x156b0c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x156b10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x156b14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x156b18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3362_0x156b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156b0cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3363 | PC: 0x156c8c | FDE: 0x1ed428 | Size: 104 bytes
// Khung tháo gỡ #3363 | Địa chỉ PC: 0x156c8c | Địa chỉ FDE: 0x1ed428 | Kích thước: 104 bytes
//   0x156c8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x156c90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x156c94: 910043FD  add      x29, sp, #0x10
//   0x156c98: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3363_0x156c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156c8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed428ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3364 | PC: 0x156cf4 | FDE: 0x1ed448 | Size: 256 bytes
// Khung tháo gỡ #3364 | Địa chỉ PC: 0x156cf4 | Địa chỉ FDE: 0x1ed448 | Kích thước: 256 bytes
//   0x156cf4: D10183FF  sub      sp, sp, #0x60
//   0x156cf8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x156cfc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x156d00: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3364_0x156cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156cf4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1ed448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3365 | PC: 0x156ecc | FDE: 0x1ed470 | Size: 256 bytes
// Khung tháo gỡ #3365 | Địa chỉ PC: 0x156ecc | Địa chỉ FDE: 0x1ed470 | Kích thước: 256 bytes
//   0x156ecc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x156ed0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x156ed4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x156ed8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3365_0x156ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156eccULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3366 | PC: 0x156fdc | FDE: 0x1ed498 | Size: 148 bytes
// Khung tháo gỡ #3366 | Địa chỉ PC: 0x156fdc | Địa chỉ FDE: 0x1ed498 | Kích thước: 148 bytes
//   0x156fdc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x156fe0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x156fe4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x156fe8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3366_0x156fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156fdcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed498ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3367 | PC: 0x157070 | FDE: 0x1ed4b8 | Size: 192 bytes
// Khung tháo gỡ #3367 | Địa chỉ PC: 0x157070 | Địa chỉ FDE: 0x1ed4b8 | Kích thước: 192 bytes
//   0x157070: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x157074: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x157078: 910043FD  add      x29, sp, #0x10
//   0x15707c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3367_0x157070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157070ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed4b8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3368 | PC: 0x157130 | FDE: 0x1ed4d8 | Size: 256 bytes
// Khung tháo gỡ #3368 | Địa chỉ PC: 0x157130 | Địa chỉ FDE: 0x1ed4d8 | Kích thước: 256 bytes
//   0x157130: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x157134: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x157138: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15713c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3368_0x157130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157130ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ed4d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3369 | PC: 0x15732c | FDE: 0x1ed500 | Size: 44 bytes
// Khung tháo gỡ #3369 | Địa chỉ PC: 0x15732c | Địa chỉ FDE: 0x1ed500 | Kích thước: 44 bytes
//   0x15732c: A9422005  ldp      x5, x8, [x0, #0x20]
//   0x157330: 90000549  adrp     x9, #0x1ff000
//   0x157334: A9408801  ldp      x1, x2, [x0, #8]
//   0x157338: F9400C04  ldr      x4, [x0, #0x18]
static inline uint64_t fde_func_3369_0x15732c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15732cULL ^ (static_cast<uint64_t>(0xa9422005ULL) << 13);
    acc = (acc + a1 + 0x90000549ULL) ^ 0x1ed500ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3370 | PC: 0x157358 | FDE: 0x1ed518 | Size: 256 bytes
// Khung tháo gỡ #3370 | Địa chỉ PC: 0x157358 | Địa chỉ FDE: 0x1ed518 | Kích thước: 256 bytes
//   0x157358: D10183FF  sub      sp, sp, #0x60
//   0x15735c: F9001BF5  str      x21, [sp, #0x30]
//   0x157360: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x157364: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_3370_0x157358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157358ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1ed518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3371 | PC: 0x1575bc | FDE: 0x1ed538 | Size: 256 bytes
// Khung tháo gỡ #3371 | Địa chỉ PC: 0x1575bc | Địa chỉ FDE: 0x1ed538 | Kích thước: 256 bytes
//   0x1575bc: D10243FF  sub      sp, sp, #0x90
//   0x1575c0: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1575c4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1575c8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3371_0x1575bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1575bcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1ed538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3372 | PC: 0x15784c | FDE: 0x1ed568 | Size: 12 bytes
// Khung tháo gỡ #3372 | Địa chỉ PC: 0x15784c | Địa chỉ FDE: 0x1ed568 | Kích thước: 12 bytes
//   0x15784c: 9240F863  and      x3, x3, #0x7fffffffffffffff
//   0x157850: F9001C3F  str      xzr, [x1, #0x38]
//   0x157854: 17FC15D7  b        #0x5cfb0
static inline uint64_t fde_func_3372_0x15784c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15784cULL ^ (static_cast<uint64_t>(0x9240f863ULL) << 13);
    acc = (acc + a1 + 0xf9001c3fULL) ^ 0x1ed568ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3373 | PC: 0x157858 | FDE: 0x1ed580 | Size: 104 bytes
// Khung tháo gỡ #3373 | Địa chỉ PC: 0x157858 | Địa chỉ FDE: 0x1ed580 | Kích thước: 104 bytes
//   0x157858: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x15785c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x157860: 910043FD  add      x29, sp, #0x10
//   0x157864: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3373_0x157858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157858ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed580ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3374 | PC: 0x1578c0 | FDE: 0x1ed5a0 | Size: 8 bytes
// Khung tháo gỡ #3374 | Địa chỉ PC: 0x1578c0 | Địa chỉ FDE: 0x1ed5a0 | Kích thước: 8 bytes
//   0x1578c0: F9401C03  ldr      x3, [x0, #0x38]
//   0x1578c4: D61F0060  br       x3
static inline uint64_t fde_func_3374_0x1578c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1578c0ULL ^ (static_cast<uint64_t>(0xf9401c03ULL) << 13);
    acc = (acc + a1 + 0xd61f0060ULL) ^ 0x1ed5a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3375 | PC: 0x1578c8 | FDE: 0x1ed5b8 | Size: 256 bytes
// Khung tháo gỡ #3375 | Địa chỉ PC: 0x1578c8 | Địa chỉ FDE: 0x1ed5b8 | Kích thước: 256 bytes
//   0x1578c8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1578cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1578d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1578d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3375_0x1578c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1578c8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ed5b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3376 | PC: 0x1579e8 | FDE: 0x1ed5e0 | Size: 256 bytes
// Khung tháo gỡ #3376 | Địa chỉ PC: 0x1579e8 | Địa chỉ FDE: 0x1ed5e0 | Kích thước: 256 bytes
//   0x1579e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1579ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1579f0: 910043FD  add      x29, sp, #0x10
//   0x1579f4: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_3376_0x1579e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1579e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed5e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3377 | PC: 0x157b58 | FDE: 0x1ed600 | Size: 40 bytes
// Khung tháo gỡ #3377 | Địa chỉ PC: 0x157b58 | Địa chỉ FDE: 0x1ed600 | Kích thước: 40 bytes
//   0x157b58: 90000548  adrp     x8, #0x1ff000
//   0x157b5c: F945F108  ldr      x8, [x8, #0xbe0]
//   0x157b60: EB08003F  cmp      x1, x8
//   0x157b64: 54000060  b.eq     #0x157b70
static inline uint64_t fde_func_3377_0x157b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157b58ULL ^ (static_cast<uint64_t>(0x90000548ULL) << 13);
    acc = (acc + a1 + 0xf945f108ULL) ^ 0x1ed600ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3378 | PC: 0x157b80 | FDE: 0x1ed618 | Size: 256 bytes
// Khung tháo gỡ #3378 | Địa chỉ PC: 0x157b80 | Địa chỉ FDE: 0x1ed618 | Kích thước: 256 bytes
//   0x157b80: D101C3FF  sub      sp, sp, #0x70
//   0x157b84: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x157b88: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x157b8c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_3378_0x157b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157b80ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1ed618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3379 | PC: 0x157d88 | FDE: 0x1ed640 | Size: 60 bytes
// Khung tháo gỡ #3379 | Địa chỉ PC: 0x157d88 | Địa chỉ FDE: 0x1ed640 | Kích thước: 60 bytes
//   0x157d88: AA0003E8  mov      x8, x0
//   0x157d8c: A9448909  ldp      x9, x2, [x8, #0x48]
//   0x157d90: A9460D04  ldp      x4, x3, [x8, #0x60]
//   0x157d94: F9404000  ldr      x0, [x0, #0x80]
static inline uint64_t fde_func_3379_0x157d88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157d88ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xa9448909ULL) ^ 0x1ed640ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3380 | PC: 0x157dc4 | FDE: 0x1ed658 | Size: 144 bytes
// Khung tháo gỡ #3380 | Địa chỉ PC: 0x157dc4 | Địa chỉ FDE: 0x1ed658 | Kích thước: 144 bytes
//   0x157dc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x157dc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x157dcc: 910043FD  add      x29, sp, #0x10
//   0x157dd0: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_3380_0x157dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157dc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed658ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3381 | PC: 0x157e54 | FDE: 0x1ed678 | Size: 12 bytes
// Khung tháo gỡ #3381 | Địa chỉ PC: 0x157e54 | Địa chỉ FDE: 0x1ed678 | Kích thước: 12 bytes
//   0x157e54: B0000261  adrp     x1, #0x1a4000
//   0x157e58: 911DB021  add      x1, x1, #0x76c
//   0x157e5c: 17FC0409  b        #0x58e80
static inline uint64_t fde_func_3381_0x157e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157e54ULL ^ (static_cast<uint64_t>(0xb0000261ULL) << 13);
    acc = (acc + a1 + 0x911db021ULL) ^ 0x1ed678ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3382 | PC: 0x157e60 | FDE: 0x1ed690 | Size: 16 bytes
// Khung tháo gỡ #3382 | Địa chỉ PC: 0x157e60 | Địa chỉ FDE: 0x1ed690 | Kích thước: 16 bytes
//   0x157e60: F9400008  ldr      x8, [x0]
//   0x157e64: 91000508  add      x8, x8, #1
//   0x157e68: F9000008  str      x8, [x0]
//   0x157e6c: D65F03C0  ret      
static inline uint64_t fde_func_3382_0x157e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157e60ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1ed690ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3383 | PC: 0x157e70 | FDE: 0x1ed6a8 | Size: 16 bytes
// Khung tháo gỡ #3383 | Địa chỉ PC: 0x157e70 | Địa chỉ FDE: 0x1ed6a8 | Kích thước: 16 bytes
//   0x157e70: F9400008  ldr      x8, [x0]
//   0x157e74: 91000508  add      x8, x8, #1
//   0x157e78: F9000008  str      x8, [x0]
//   0x157e7c: D65F03C0  ret      
static inline uint64_t fde_func_3383_0x157e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157e70ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1ed6a8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3384 | PC: 0x157e80 | FDE: 0x1ed6c0 | Size: 256 bytes
// Khung tháo gỡ #3384 | Địa chỉ PC: 0x157e80 | Địa chỉ FDE: 0x1ed6c0 | Kích thước: 256 bytes
//   0x157e80: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x157e84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x157e88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x157e8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3384_0x157e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157e80ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ed6c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3385 | PC: 0x157fa4 | FDE: 0x1ed6e8 | Size: 24 bytes
// Khung tháo gỡ #3385 | Địa chỉ PC: 0x157fa4 | Địa chỉ FDE: 0x1ed6e8 | Kích thước: 24 bytes
//   0x157fa4: F9403409  ldr      x9, [x0, #0x68]
//   0x157fa8: F9402C08  ldr      x8, [x0, #0x58]
//   0x157fac: 91000529  add      x9, x9, #1
//   0x157fb0: F9003409  str      x9, [x0, #0x68]
static inline uint64_t fde_func_3385_0x157fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157fa4ULL ^ (static_cast<uint64_t>(0xf9403409ULL) << 13);
    acc = (acc + a1 + 0xf9402c08ULL) ^ 0x1ed6e8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3386 | PC: 0x157fbc | FDE: 0x1ed700 | Size: 256 bytes
// Khung tháo gỡ #3386 | Địa chỉ PC: 0x157fbc | Địa chỉ FDE: 0x1ed700 | Kích thước: 256 bytes
//   0x157fbc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x157fc0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x157fc4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x157fc8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3386_0x157fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157fbcULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ed700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3387 | PC: 0x158308 | FDE: 0x1ed730 | Size: 256 bytes
// Khung tháo gỡ #3387 | Địa chỉ PC: 0x158308 | Địa chỉ FDE: 0x1ed730 | Kích thước: 256 bytes
//   0x158308: D101C3FF  sub      sp, sp, #0x70
//   0x15830c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x158310: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x158314: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3387_0x158308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158308ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1ed730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3388 | PC: 0x1585d4 | FDE: 0x1ed760 | Size: 156 bytes
// Khung tháo gỡ #3388 | Địa chỉ PC: 0x1585d4 | Địa chỉ FDE: 0x1ed760 | Kích thước: 156 bytes
//   0x1585d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1585d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1585dc: 910043FD  add      x29, sp, #0x10
//   0x1585e0: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3388_0x1585d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1585d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed760ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3389 | PC: 0x158670 | FDE: 0x1ed780 | Size: 192 bytes
// Khung tháo gỡ #3389 | Địa chỉ PC: 0x158670 | Địa chỉ FDE: 0x1ed780 | Kích thước: 192 bytes
//   0x158670: D10103FF  sub      sp, sp, #0x40
//   0x158674: F9000BF5  str      x21, [sp, #0x10]
//   0x158678: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15867c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3389_0x158670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158670ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ed780ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3390 | PC: 0x158730 | FDE: 0x1ed7a0 | Size: 108 bytes
// Khung tháo gỡ #3390 | Địa chỉ PC: 0x158730 | Địa chỉ FDE: 0x1ed7a0 | Kích thước: 108 bytes
//   0x158730: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x158734: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x158738: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15873c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3390_0x158730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158730ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed7a0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3391 | PC: 0x15879c | FDE: 0x1ed7c0 | Size: 108 bytes
// Khung tháo gỡ #3391 | Địa chỉ PC: 0x15879c | Địa chỉ FDE: 0x1ed7c0 | Kích thước: 108 bytes
//   0x15879c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1587a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1587a4: 910043FD  add      x29, sp, #0x10
//   0x1587a8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3391_0x15879c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15879cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed7c0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 2928: return fde_func_2928_0x132cd4(a0, a1);
        case 2929: return fde_func_2929_0x132d4c(a0, a1);
        case 2930: return fde_func_2930_0x132eec(a0, a1);
        case 2931: return fde_func_2931_0x132ef4(a0, a1);
        case 2932: return fde_func_2932_0x1333c4(a0, a1);
        case 2933: return fde_func_2933_0x1333e8(a0, a1);
        case 2934: return fde_func_2934_0x133528(a0, a1);
        case 2935: return fde_func_2935_0x134050(a0, a1);
        case 2936: return fde_func_2936_0x134110(a0, a1);
        case 2937: return fde_func_2937_0x1342b0(a0, a1);
        case 2938: return fde_func_2938_0x1342c8(a0, a1);
        case 2939: return fde_func_2939_0x134320(a0, a1);
        case 2940: return fde_func_2940_0x134324(a0, a1);
        case 2941: return fde_func_2941_0x1344fc(a0, a1);
        case 2942: return fde_func_2942_0x13450c(a0, a1);
        case 2943: return fde_func_2943_0x134770(a0, a1);
        case 2944: return fde_func_2944_0x134780(a0, a1);
        case 2945: return fde_func_2945_0x134790(a0, a1);
        case 2946: return fde_func_2946_0x134794(a0, a1);
        case 2947: return fde_func_2947_0x134830(a0, a1);
        case 2948: return fde_func_2948_0x1348f4(a0, a1);
        case 2949: return fde_func_2949_0x1349c0(a0, a1);
        case 2950: return fde_func_2950_0x1349cc(a0, a1);
        case 2951: return fde_func_2951_0x134bc8(a0, a1);
        case 2952: return fde_func_2952_0x134bd4(a0, a1);
        case 2953: return fde_func_2953_0x134c64(a0, a1);
        case 2954: return fde_func_2954_0x134c68(a0, a1);
        case 2955: return fde_func_2955_0x134d2c(a0, a1);
        case 2956: return fde_func_2956_0x134df8(a0, a1);
        case 2957: return fde_func_2957_0x134f34(a0, a1);
        case 2958: return fde_func_2958_0x135070(a0, a1);
        case 2959: return fde_func_2959_0x1351a0(a0, a1);
        case 2960: return fde_func_2960_0x1351e4(a0, a1);
        case 2961: return fde_func_2961_0x13528c(a0, a1);
        case 2962: return fde_func_2962_0x135414(a0, a1);
        case 2963: return fde_func_2963_0x1354bc(a0, a1);
        case 2964: return fde_func_2964_0x135648(a0, a1);
        case 2965: return fde_func_2965_0x135650(a0, a1);
        case 2966: return fde_func_2966_0x135658(a0, a1);
        case 2967: return fde_func_2967_0x135700(a0, a1);
        case 2968: return fde_func_2968_0x135798(a0, a1);
        case 2969: return fde_func_2969_0x135818(a0, a1);
        case 2970: return fde_func_2970_0x135824(a0, a1);
        case 2971: return fde_func_2971_0x135b98(a0, a1);
        case 2972: return fde_func_2972_0x135ba4(a0, a1);
        case 2973: return fde_func_2973_0x135d84(a0, a1);
        case 2974: return fde_func_2974_0x135db4(a0, a1);
        case 2975: return fde_func_2975_0x135f40(a0, a1);
        case 2976: return fde_func_2976_0x1363f4(a0, a1);
        case 2977: return fde_func_2977_0x136490(a0, a1);
        case 2978: return fde_func_2978_0x136528(a0, a1);
        case 2979: return fde_func_2979_0x1365c4(a0, a1);
        case 2980: return fde_func_2980_0x136604(a0, a1);
        case 2981: return fde_func_2981_0x1366c8(a0, a1);
        case 2982: return fde_func_2982_0x13675c(a0, a1);
        case 2983: return fde_func_2983_0x136b8c(a0, a1);
        case 2984: return fde_func_2984_0x136c44(a0, a1);
        case 2985: return fde_func_2985_0x136cc8(a0, a1);
        case 2986: return fde_func_2986_0x136d7c(a0, a1);
        case 2987: return fde_func_2987_0x136e90(a0, a1);
        case 2988: return fde_func_2988_0x13702c(a0, a1);
        case 2989: return fde_func_2989_0x137044(a0, a1);
        case 2990: return fde_func_2990_0x137144(a0, a1);
        case 2991: return fde_func_2991_0x137244(a0, a1);
        case 2992: return fde_func_2992_0x137340(a0, a1);
        case 2993: return fde_func_2993_0x137484(a0, a1);
        case 2994: return fde_func_2994_0x1374f8(a0, a1);
        case 2995: return fde_func_2995_0x1375b8(a0, a1);
        case 2996: return fde_func_2996_0x13766c(a0, a1);
        case 2997: return fde_func_2997_0x137890(a0, a1);
        case 2998: return fde_func_2998_0x1379a0(a0, a1);
        case 2999: return fde_func_2999_0x137f94(a0, a1);
        case 3000: return fde_func_3000_0x138310(a0, a1);
        case 3001: return fde_func_3001_0x139214(a0, a1);
        case 3002: return fde_func_3002_0x13936c(a0, a1);
        case 3003: return fde_func_3003_0x1395bc(a0, a1);
        case 3004: return fde_func_3004_0x1395d4(a0, a1);
        case 3005: return fde_func_3005_0x139688(a0, a1);
        case 3006: return fde_func_3006_0x1398b0(a0, a1);
        case 3007: return fde_func_3007_0x139964(a0, a1);
        case 3008: return fde_func_3008_0x139ad4(a0, a1);
        case 3009: return fde_func_3009_0x139b88(a0, a1);
        case 3010: return fde_func_3010_0x139c94(a0, a1);
        case 3011: return fde_func_3011_0x139ddc(a0, a1);
        case 3012: return fde_func_3012_0x13b03c(a0, a1);
        case 3013: return fde_func_3013_0x13b064(a0, a1);
        case 3014: return fde_func_3014_0x13b068(a0, a1);
        case 3015: return fde_func_3015_0x13b06c(a0, a1);
        case 3016: return fde_func_3016_0x13b3f4(a0, a1);
        case 3017: return fde_func_3017_0x13b43c(a0, a1);
        case 3018: return fde_func_3018_0x13b4a8(a0, a1);
        case 3019: return fde_func_3019_0x13b518(a0, a1);
        case 3020: return fde_func_3020_0x13b52c(a0, a1);
        case 3021: return fde_func_3021_0x13b554(a0, a1);
        case 3022: return fde_func_3022_0x13b598(a0, a1);
        case 3023: return fde_func_3023_0x13b5c8(a0, a1);
        case 3024: return fde_func_3024_0x13b5f8(a0, a1);
        case 3025: return fde_func_3025_0x13b638(a0, a1);
        case 3026: return fde_func_3026_0x13b650(a0, a1);
        case 3027: return fde_func_3027_0x13b734(a0, a1);
        case 3028: return fde_func_3028_0x13b870(a0, a1);
        case 3029: return fde_func_3029_0x13b950(a0, a1);
        case 3030: return fde_func_3030_0x13b968(a0, a1);
        case 3031: return fde_func_3031_0x13ba08(a0, a1);
        case 3032: return fde_func_3032_0x13ba2c(a0, a1);
        case 3033: return fde_func_3033_0x13ba94(a0, a1);
        case 3034: return fde_func_3034_0x13bb0c(a0, a1);
        case 3035: return fde_func_3035_0x13bb40(a0, a1);
        case 3036: return fde_func_3036_0x13bbec(a0, a1);
        case 3037: return fde_func_3037_0x13bc64(a0, a1);
        case 3038: return fde_func_3038_0x13bc98(a0, a1);
        case 3039: return fde_func_3039_0x13bd20(a0, a1);
        case 3040: return fde_func_3040_0x13bd54(a0, a1);
        case 3041: return fde_func_3041_0x13be38(a0, a1);
        case 3042: return fde_func_3042_0x13be7c(a0, a1);
        case 3043: return fde_func_3043_0x13bfbc(a0, a1);
        case 3044: return fde_func_3044_0x13c02c(a0, a1);
        case 3045: return fde_func_3045_0x13c034(a0, a1);
        case 3046: return fde_func_3046_0x13c03c(a0, a1);
        case 3047: return fde_func_3047_0x13c064(a0, a1);
        case 3048: return fde_func_3048_0x13c194(a0, a1);
        case 3049: return fde_func_3049_0x13c228(a0, a1);
        case 3050: return fde_func_3050_0x13c340(a0, a1);
        case 3051: return fde_func_3051_0x13c438(a0, a1);
        case 3052: return fde_func_3052_0x13c5a4(a0, a1);
        case 3053: return fde_func_3053_0x13c644(a0, a1);
        case 3054: return fde_func_3054_0x13c8c4(a0, a1);
        case 3055: return fde_func_3055_0x13ca40(a0, a1);
        case 3056: return fde_func_3056_0x13ca58(a0, a1);
        case 3057: return fde_func_3057_0x13ca5c(a0, a1);
        case 3058: return fde_func_3058_0x13ca64(a0, a1);
        case 3059: return fde_func_3059_0x13caec(a0, a1);
        case 3060: return fde_func_3060_0x13cbe4(a0, a1);
        case 3061: return fde_func_3061_0x13cc10(a0, a1);
        case 3062: return fde_func_3062_0x13cc70(a0, a1);
        case 3063: return fde_func_3063_0x13cca0(a0, a1);
        case 3064: return fde_func_3064_0x13cce4(a0, a1);
        case 3065: return fde_func_3065_0x13cd54(a0, a1);
        case 3066: return fde_func_3066_0x13cd94(a0, a1);
        case 3067: return fde_func_3067_0x13cfc4(a0, a1);
        case 3068: return fde_func_3068_0x13cfec(a0, a1);
        case 3069: return fde_func_3069_0x13d05c(a0, a1);
        case 3070: return fde_func_3070_0x13d06c(a0, a1);
        case 3071: return fde_func_3071_0x13d0c4(a0, a1);
        case 3072: return fde_func_3072_0x13d0c8(a0, a1);
        case 3073: return fde_func_3073_0x13d0d0(a0, a1);
        case 3074: return fde_func_3074_0x13d0ec(a0, a1);
        case 3075: return fde_func_3075_0x13d0f0(a0, a1);
        case 3076: return fde_func_3076_0x13d0f4(a0, a1);
        case 3077: return fde_func_3077_0x13d140(a0, a1);
        case 3078: return fde_func_3078_0x13d170(a0, a1);
        case 3079: return fde_func_3079_0x13d190(a0, a1);
        case 3080: return fde_func_3080_0x13d198(a0, a1);
        case 3081: return fde_func_3081_0x13d1c0(a0, a1);
        case 3082: return fde_func_3082_0x13d28c(a0, a1);
        case 3083: return fde_func_3083_0x13d2ac(a0, a1);
        case 3084: return fde_func_3084_0x13d2e8(a0, a1);
        case 3085: return fde_func_3085_0x13d2f0(a0, a1);
        case 3086: return fde_func_3086_0x13d3a4(a0, a1);
        case 3087: return fde_func_3087_0x13d450(a0, a1);
        case 3088: return fde_func_3088_0x13d4a8(a0, a1);
        case 3089: return fde_func_3089_0x13d514(a0, a1);
        case 3090: return fde_func_3090_0x13d714(a0, a1);
        case 3091: return fde_func_3091_0x13d7e4(a0, a1);
        case 3092: return fde_func_3092_0x13d920(a0, a1);
        case 3093: return fde_func_3093_0x13da60(a0, a1);
        case 3094: return fde_func_3094_0x13e108(a0, a1);
        case 3095: return fde_func_3095_0x13e4d0(a0, a1);
        case 3096: return fde_func_3096_0x13e558(a0, a1);
        case 3097: return fde_func_3097_0x13e5e8(a0, a1);
        case 3098: return fde_func_3098_0x13e894(a0, a1);
        case 3099: return fde_func_3099_0x13e89c(a0, a1);
        case 3100: return fde_func_3100_0x13ec38(a0, a1);
        case 3101: return fde_func_3101_0x13ec70(a0, a1);
        case 3102: return fde_func_3102_0x13eeb8(a0, a1);
        case 3103: return fde_func_3103_0x13eee4(a0, a1);
        case 3104: return fde_func_3104_0x13ef08(a0, a1);
        case 3105: return fde_func_3105_0x13eff4(a0, a1);
        case 3106: return fde_func_3106_0x140030(a0, a1);
        case 3107: return fde_func_3107_0x140380(a0, a1);
        case 3108: return fde_func_3108_0x140420(a0, a1);
        case 3109: return fde_func_3109_0x1404ac(a0, a1);
        case 3110: return fde_func_3110_0x1405cc(a0, a1);
        case 3111: return fde_func_3111_0x14096c(a0, a1);
        case 3112: return fde_func_3112_0x140ad4(a0, a1);
        case 3113: return fde_func_3113_0x141030(a0, a1);
        case 3114: return fde_func_3114_0x1410f4(a0, a1);
        case 3115: return fde_func_3115_0x141234(a0, a1);
        case 3116: return fde_func_3116_0x1412dc(a0, a1);
        case 3117: return fde_func_3117_0x141694(a0, a1);
        case 3118: return fde_func_3118_0x141714(a0, a1);
        case 3119: return fde_func_3119_0x14171c(a0, a1);
        case 3120: return fde_func_3120_0x141724(a0, a1);
        case 3121: return fde_func_3121_0x141a78(a0, a1);
        case 3122: return fde_func_3122_0x142224(a0, a1);
        case 3123: return fde_func_3123_0x142770(a0, a1);
        case 3124: return fde_func_3124_0x142bd8(a0, a1);
        case 3125: return fde_func_3125_0x142cf0(a0, a1);
        case 3126: return fde_func_3126_0x143694(a0, a1);
        case 3127: return fde_func_3127_0x1437c4(a0, a1);
        case 3128: return fde_func_3128_0x143aa4(a0, a1);
        case 3129: return fde_func_3129_0x143e10(a0, a1);
        case 3130: return fde_func_3130_0x143e9c(a0, a1);
        case 3131: return fde_func_3131_0x143eec(a0, a1);
        case 3132: return fde_func_3132_0x143ef4(a0, a1);
        case 3133: return fde_func_3133_0x143ef8(a0, a1);
        case 3134: return fde_func_3134_0x143f50(a0, a1);
        case 3135: return fde_func_3135_0x143fe8(a0, a1);
        case 3136: return fde_func_3136_0x144064(a0, a1);
        case 3137: return fde_func_3137_0x1440e0(a0, a1);
        case 3138: return fde_func_3138_0x1440e8(a0, a1);
        case 3139: return fde_func_3139_0x1440f4(a0, a1);
        case 3140: return fde_func_3140_0x1440f8(a0, a1);
        case 3141: return fde_func_3141_0x144160(a0, a1);
        case 3142: return fde_func_3142_0x144218(a0, a1);
        case 3143: return fde_func_3143_0x144260(a0, a1);
        case 3144: return fde_func_3144_0x14426c(a0, a1);
        case 3145: return fde_func_3145_0x14439c(a0, a1);
        case 3146: return fde_func_3146_0x144450(a0, a1);
        case 3147: return fde_func_3147_0x144458(a0, a1);
        case 3148: return fde_func_3148_0x144598(a0, a1);
        case 3149: return fde_func_3149_0x144640(a0, a1);
        case 3150: return fde_func_3150_0x14476c(a0, a1);
        case 3151: return fde_func_3151_0x1448dc(a0, a1);
        case 3152: return fde_func_3152_0x144994(a0, a1);
        case 3153: return fde_func_3153_0x14499c(a0, a1);
        case 3154: return fde_func_3154_0x144a94(a0, a1);
        case 3155: return fde_func_3155_0x144afc(a0, a1);
        case 3156: return fde_func_3156_0x144c50(a0, a1);
        case 3157: return fde_func_3157_0x144d7c(a0, a1);
        case 3158: return fde_func_3158_0x144d8c(a0, a1);
        case 3159: return fde_func_3159_0x144ebc(a0, a1);
        case 3160: return fde_func_3160_0x144fa8(a0, a1);
        case 3161: return fde_func_3161_0x145004(a0, a1);
        case 3162: return fde_func_3162_0x145048(a0, a1);
        case 3163: return fde_func_3163_0x1450c0(a0, a1);
        case 3164: return fde_func_3164_0x145214(a0, a1);
        case 3165: return fde_func_3165_0x145250(a0, a1);
        case 3166: return fde_func_3166_0x145260(a0, a1);
        case 3167: return fde_func_3167_0x145284(a0, a1);
        case 3168: return fde_func_3168_0x14529c(a0, a1);
        case 3169: return fde_func_3169_0x1452b0(a0, a1);
        case 3170: return fde_func_3170_0x1452c4(a0, a1);
        case 3171: return fde_func_3171_0x1452e8(a0, a1);
        case 3172: return fde_func_3172_0x145334(a0, a1);
        case 3173: return fde_func_3173_0x1453e4(a0, a1);
        case 3174: return fde_func_3174_0x1456b8(a0, a1);
        case 3175: return fde_func_3175_0x14576c(a0, a1);
        case 3176: return fde_func_3176_0x145770(a0, a1);
        case 3177: return fde_func_3177_0x145774(a0, a1);
        case 3178: return fde_func_3178_0x145798(a0, a1);
        case 3179: return fde_func_3179_0x1457b8(a0, a1);
        case 3180: return fde_func_3180_0x14596c(a0, a1);
        case 3181: return fde_func_3181_0x14597c(a0, a1);
        case 3182: return fde_func_3182_0x1459bc(a0, a1);
        case 3183: return fde_func_3183_0x145a14(a0, a1);
        case 3184: return fde_func_3184_0x145ab0(a0, a1);
        case 3185: return fde_func_3185_0x145ac0(a0, a1);
        case 3186: return fde_func_3186_0x145b18(a0, a1);
        case 3187: return fde_func_3187_0x145b58(a0, a1);
        case 3188: return fde_func_3188_0x145bf4(a0, a1);
        case 3189: return fde_func_3189_0x145cf8(a0, a1);
        case 3190: return fde_func_3190_0x145d48(a0, a1);
        case 3191: return fde_func_3191_0x145dd8(a0, a1);
        case 3192: return fde_func_3192_0x145f9c(a0, a1);
        case 3193: return fde_func_3193_0x145fd4(a0, a1);
        case 3194: return fde_func_3194_0x146120(a0, a1);
        case 3195: return fde_func_3195_0x146124(a0, a1);
        case 3196: return fde_func_3196_0x14616c(a0, a1);
        case 3197: return fde_func_3197_0x146198(a0, a1);
        case 3198: return fde_func_3198_0x1461c0(a0, a1);
        case 3199: return fde_func_3199_0x1461e8(a0, a1);
        case 3200: return fde_func_3200_0x14627c(a0, a1);
        case 3201: return fde_func_3201_0x146320(a0, a1);
        case 3202: return fde_func_3202_0x146448(a0, a1);
        case 3203: return fde_func_3203_0x146478(a0, a1);
        case 3204: return fde_func_3204_0x1464ac(a0, a1);
        case 3205: return fde_func_3205_0x14c8d8(a0, a1);
        case 3206: return fde_func_3206_0x14c9f4(a0, a1);
        case 3207: return fde_func_3207_0x14cadc(a0, a1);
        case 3208: return fde_func_3208_0x14cc5c(a0, a1);
        case 3209: return fde_func_3209_0x14cddc(a0, a1);
        case 3210: return fde_func_3210_0x14d04c(a0, a1);
        case 3211: return fde_func_3211_0x14d0b0(a0, a1);
        case 3212: return fde_func_3212_0x14d27c(a0, a1);
        case 3213: return fde_func_3213_0x14d4f4(a0, a1);
        case 3214: return fde_func_3214_0x14d560(a0, a1);
        case 3215: return fde_func_3215_0x14d98c(a0, a1);
        case 3216: return fde_func_3216_0x14e2ec(a0, a1);
        case 3217: return fde_func_3217_0x14e578(a0, a1);
        case 3218: return fde_func_3218_0x14e828(a0, a1);
        case 3219: return fde_func_3219_0x14e8ac(a0, a1);
        case 3220: return fde_func_3220_0x14e968(a0, a1);
        case 3221: return fde_func_3221_0x14e9b4(a0, a1);
        case 3222: return fde_func_3222_0x14ea70(a0, a1);
        case 3223: return fde_func_3223_0x14eabc(a0, a1);
        case 3224: return fde_func_3224_0x14eac4(a0, a1);
        case 3225: return fde_func_3225_0x14eadc(a0, a1);
        case 3226: return fde_func_3226_0x14eb50(a0, a1);
        case 3227: return fde_func_3227_0x14eb68(a0, a1);
        case 3228: return fde_func_3228_0x14ebdc(a0, a1);
        case 3229: return fde_func_3229_0x14ebf4(a0, a1);
        case 3230: return fde_func_3230_0x14ec0c(a0, a1);
        case 3231: return fde_func_3231_0x14ec2c(a0, a1);
        case 3232: return fde_func_3232_0x14ec5c(a0, a1);
        case 3233: return fde_func_3233_0x14ecf8(a0, a1);
        case 3234: return fde_func_3234_0x14ed4c(a0, a1);
        case 3235: return fde_func_3235_0x14ed74(a0, a1);
        case 3236: return fde_func_3236_0x14edc4(a0, a1);
        case 3237: return fde_func_3237_0x14ee60(a0, a1);
        case 3238: return fde_func_3238_0x14eed4(a0, a1);
        case 3239: return fde_func_3239_0x14ef70(a0, a1);
        case 3240: return fde_func_3240_0x14effc(a0, a1);
        case 3241: return fde_func_3241_0x14f054(a0, a1);
        case 3242: return fde_func_3242_0x14f0a8(a0, a1);
        case 3243: return fde_func_3243_0x14f0c8(a0, a1);
        case 3244: return fde_func_3244_0x14f188(a0, a1);
        case 3245: return fde_func_3245_0x14f280(a0, a1);
        case 3246: return fde_func_3246_0x14f2a4(a0, a1);
        case 3247: return fde_func_3247_0x14f324(a0, a1);
        case 3248: return fde_func_3248_0x14f3a4(a0, a1);
        case 3249: return fde_func_3249_0x14f424(a0, a1);
        case 3250: return fde_func_3250_0x14f448(a0, a1);
        case 3251: return fde_func_3251_0x14f46c(a0, a1);
        case 3252: return fde_func_3252_0x14f534(a0, a1);
        case 3253: return fde_func_3253_0x14f5fc(a0, a1);
        case 3254: return fde_func_3254_0x14f664(a0, a1);
        case 3255: return fde_func_3255_0x14f670(a0, a1);
        case 3256: return fde_func_3256_0x14f6a8(a0, a1);
        case 3257: return fde_func_3257_0x14f6e0(a0, a1);
        case 3258: return fde_func_3258_0x14f708(a0, a1);
        case 3259: return fde_func_3259_0x14f714(a0, a1);
        case 3260: return fde_func_3260_0x14fcc8(a0, a1);
        case 3261: return fde_func_3261_0x14fd80(a0, a1);
        case 3262: return fde_func_3262_0x14fe48(a0, a1);
        case 3263: return fde_func_3263_0x14ff30(a0, a1);
        case 3264: return fde_func_3264_0x1500d0(a0, a1);
        case 3265: return fde_func_3265_0x1503ec(a0, a1);
        case 3266: return fde_func_3266_0x150a84(a0, a1);
        case 3267: return fde_func_3267_0x150af4(a0, a1);
        case 3268: return fde_func_3268_0x150c00(a0, a1);
        case 3269: return fde_func_3269_0x150cec(a0, a1);
        case 3270: return fde_func_3270_0x150d78(a0, a1);
        case 3271: return fde_func_3271_0x150db8(a0, a1);
        case 3272: return fde_func_3272_0x150e78(a0, a1);
        case 3273: return fde_func_3273_0x150ef8(a0, a1);
        case 3274: return fde_func_3274_0x150f8c(a0, a1);
        case 3275: return fde_func_3275_0x150f98(a0, a1);
        case 3276: return fde_func_3276_0x150fd4(a0, a1);
        case 3277: return fde_func_3277_0x151010(a0, a1);
        case 3278: return fde_func_3278_0x1510cc(a0, a1);
        case 3279: return fde_func_3279_0x151288(a0, a1);
        case 3280: return fde_func_3280_0x151444(a0, a1);
        case 3281: return fde_func_3281_0x1516c0(a0, a1);
        case 3282: return fde_func_3282_0x1518ac(a0, a1);
        case 3283: return fde_func_3283_0x151a24(a0, a1);
        case 3284: return fde_func_3284_0x151c18(a0, a1);
        case 3285: return fde_func_3285_0x151d90(a0, a1);
        case 3286: return fde_func_3286_0x151f34(a0, a1);
        case 3287: return fde_func_3287_0x1520ac(a0, a1);
        case 3288: return fde_func_3288_0x152250(a0, a1);
        case 3289: return fde_func_3289_0x152428(a0, a1);
        case 3290: return fde_func_3290_0x152540(a0, a1);
        case 3291: return fde_func_3291_0x1525fc(a0, a1);
        case 3292: return fde_func_3292_0x152608(a0, a1);
        case 3293: return fde_func_3293_0x1529a0(a0, a1);
        case 3294: return fde_func_3294_0x152a34(a0, a1);
        case 3295: return fde_func_3295_0x152ab8(a0, a1);
        case 3296: return fde_func_3296_0x152b8c(a0, a1);
        case 3297: return fde_func_3297_0x152c64(a0, a1);
        case 3298: return fde_func_3298_0x152e80(a0, a1);
        case 3299: return fde_func_3299_0x153160(a0, a1);
        case 3300: return fde_func_3300_0x1531cc(a0, a1);
        case 3301: return fde_func_3301_0x153334(a0, a1);
        case 3302: return fde_func_3302_0x1533e4(a0, a1);
        case 3303: return fde_func_3303_0x1533f4(a0, a1);
        case 3304: return fde_func_3304_0x1533fc(a0, a1);
        case 3305: return fde_func_3305_0x1534b8(a0, a1);
        case 3306: return fde_func_3306_0x153514(a0, a1);
        case 3307: return fde_func_3307_0x1535ec(a0, a1);
        case 3308: return fde_func_3308_0x1537cc(a0, a1);
        case 3309: return fde_func_3309_0x1538b8(a0, a1);
        case 3310: return fde_func_3310_0x153908(a0, a1);
        case 3311: return fde_func_3311_0x153b90(a0, a1);
        case 3312: return fde_func_3312_0x153de0(a0, a1);
        case 3313: return fde_func_3313_0x1540a4(a0, a1);
        case 3314: return fde_func_3314_0x154228(a0, a1);
        case 3315: return fde_func_3315_0x1542f8(a0, a1);
        case 3316: return fde_func_3316_0x154708(a0, a1);
        case 3317: return fde_func_3317_0x1547dc(a0, a1);
        case 3318: return fde_func_3318_0x154820(a0, a1);
        case 3319: return fde_func_3319_0x154848(a0, a1);
        case 3320: return fde_func_3320_0x15495c(a0, a1);
        case 3321: return fde_func_3321_0x154c2c(a0, a1);
        case 3322: return fde_func_3322_0x154e54(a0, a1);
        case 3323: return fde_func_3323_0x155238(a0, a1);
        case 3324: return fde_func_3324_0x155314(a0, a1);
        case 3325: return fde_func_3325_0x155540(a0, a1);
        case 3326: return fde_func_3326_0x1555ac(a0, a1);
        case 3327: return fde_func_3327_0x155638(a0, a1);
        case 3328: return fde_func_3328_0x15570c(a0, a1);
        case 3329: return fde_func_3329_0x155730(a0, a1);
        case 3330: return fde_func_3330_0x155828(a0, a1);
        case 3331: return fde_func_3331_0x15584c(a0, a1);
        case 3332: return fde_func_3332_0x15589c(a0, a1);
        case 3333: return fde_func_3333_0x1559a0(a0, a1);
        case 3334: return fde_func_3334_0x155a08(a0, a1);
        case 3335: return fde_func_3335_0x155a54(a0, a1);
        case 3336: return fde_func_3336_0x155b88(a0, a1);
        case 3337: return fde_func_3337_0x155c5c(a0, a1);
        case 3338: return fde_func_3338_0x155d84(a0, a1);
        case 3339: return fde_func_3339_0x155da8(a0, a1);
        case 3340: return fde_func_3340_0x155f18(a0, a1);
        case 3341: return fde_func_3341_0x155f58(a0, a1);
        case 3342: return fde_func_3342_0x155f8c(a0, a1);
        case 3343: return fde_func_3343_0x15601c(a0, a1);
        case 3344: return fde_func_3344_0x1561b0(a0, a1);
        case 3345: return fde_func_3345_0x1561b8(a0, a1);
        case 3346: return fde_func_3346_0x1561d8(a0, a1);
        case 3347: return fde_func_3347_0x156268(a0, a1);
        case 3348: return fde_func_3348_0x156404(a0, a1);
        case 3349: return fde_func_3349_0x156450(a0, a1);
        case 3350: return fde_func_3350_0x156488(a0, a1);
        case 3351: return fde_func_3351_0x1564bc(a0, a1);
        case 3352: return fde_func_3352_0x1564f4(a0, a1);
        case 3353: return fde_func_3353_0x15658c(a0, a1);
        case 3354: return fde_func_3354_0x1565c8(a0, a1);
        case 3355: return fde_func_3355_0x1566c0(a0, a1);
        case 3356: return fde_func_3356_0x1566d4(a0, a1);
        case 3357: return fde_func_3357_0x1566e0(a0, a1);
        case 3358: return fde_func_3358_0x156760(a0, a1);
        case 3359: return fde_func_3359_0x156820(a0, a1);
        case 3360: return fde_func_3360_0x156824(a0, a1);
        case 3361: return fde_func_3361_0x156a64(a0, a1);
        case 3362: return fde_func_3362_0x156b0c(a0, a1);
        case 3363: return fde_func_3363_0x156c8c(a0, a1);
        case 3364: return fde_func_3364_0x156cf4(a0, a1);
        case 3365: return fde_func_3365_0x156ecc(a0, a1);
        case 3366: return fde_func_3366_0x156fdc(a0, a1);
        case 3367: return fde_func_3367_0x157070(a0, a1);
        case 3368: return fde_func_3368_0x157130(a0, a1);
        case 3369: return fde_func_3369_0x15732c(a0, a1);
        case 3370: return fde_func_3370_0x157358(a0, a1);
        case 3371: return fde_func_3371_0x1575bc(a0, a1);
        case 3372: return fde_func_3372_0x15784c(a0, a1);
        case 3373: return fde_func_3373_0x157858(a0, a1);
        case 3374: return fde_func_3374_0x1578c0(a0, a1);
        case 3375: return fde_func_3375_0x1578c8(a0, a1);
        case 3376: return fde_func_3376_0x1579e8(a0, a1);
        case 3377: return fde_func_3377_0x157b58(a0, a1);
        case 3378: return fde_func_3378_0x157b80(a0, a1);
        case 3379: return fde_func_3379_0x157d88(a0, a1);
        case 3380: return fde_func_3380_0x157dc4(a0, a1);
        case 3381: return fde_func_3381_0x157e54(a0, a1);
        case 3382: return fde_func_3382_0x157e60(a0, a1);
        case 3383: return fde_func_3383_0x157e70(a0, a1);
        case 3384: return fde_func_3384_0x157e80(a0, a1);
        case 3385: return fde_func_3385_0x157fa4(a0, a1);
        case 3386: return fde_func_3386_0x157fbc(a0, a1);
        case 3387: return fde_func_3387_0x158308(a0, a1);
        case 3388: return fde_func_3388_0x1585d4(a0, a1);
        case 3389: return fde_func_3389_0x158670(a0, a1);
        case 3390: return fde_func_3390_0x158730(a0, a1);
        case 3391: return fde_func_3391_0x15879c(a0, a1);
        default: return 0ULL;
    }
}