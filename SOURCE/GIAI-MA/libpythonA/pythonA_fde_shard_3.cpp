// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 3/5 for libpythonA.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 3/5 cho libpythonA.so
// Covers representative FDE indices [800 .. 1199] out of 4,320 total FDEs
// Bao phủ chỉ số FDE đại diện [800 .. 1199] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_core.h"

// FDE #0800 | PC: 0x0a7d18 | FDE: 0x1db698 | Size: 60 bytes [PyDict_Size]
// Khung tháo gỡ #0800 | Địa chỉ PC: 0x0a7d18 | Địa chỉ FDE: 0x1db698 | Kích thước: 60 bytes
//   0x0a7d18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a7d1c: 910003FD  mov      x29, sp
//   0x0a7d20: B4000080  cbz      x0, #0xa7d30
//   0x0a7d24: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0800_0x0a7d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7d18ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1db698ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0801 | PC: 0x0a7d54 | FDE: 0x1db6b8 | Size: 256 bytes [PyDict_Keys]
// Khung tháo gỡ #0801 | Địa chỉ PC: 0x0a7d54 | Địa chỉ FDE: 0x1db6b8 | Kích thước: 256 bytes
//   0x0a7d54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a7d58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7d5c: 910043FD  add      x29, sp, #0x10
//   0x0a7d60: B40000A0  cbz      x0, #0xa7d74
static inline uint64_t fde_func_0801_0x0a7d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7d54ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db6b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0802 | PC: 0x0a7e7c | FDE: 0x1db6d8 | Size: 256 bytes [PyDict_Values]
// Khung tháo gỡ #0802 | Địa chỉ PC: 0x0a7e7c | Địa chỉ FDE: 0x1db6d8 | Kích thước: 256 bytes
//   0x0a7e7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a7e80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7e84: 910043FD  add      x29, sp, #0x10
//   0x0a7e88: B40000A0  cbz      x0, #0xa7e9c
static inline uint64_t fde_func_0802_0x0a7e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7e7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0803 | PC: 0x0a7f90 | FDE: 0x1db6f8 | Size: 256 bytes [PyDict_Items]
// Khung tháo gỡ #0803 | Địa chỉ PC: 0x0a7f90 | Địa chỉ FDE: 0x1db6f8 | Kích thước: 256 bytes
//   0x0a7f90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a7f94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a7f98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a7f9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0803_0x0a7f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7f90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1db6f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0804 | PC: 0x0a820c | FDE: 0x1db738 | Size: 132 bytes [_PyDict_SizeOf]
// Khung tháo gỡ #0804 | Địa chỉ PC: 0x0a820c | Địa chỉ FDE: 0x1db738 | Kích thước: 132 bytes
//   0x0a820c: A9422808  ldp      x8, x10, [x0, #0x20]
//   0x0a8210: F9400409  ldr      x9, [x0, #8]
//   0x0a8214: B200F3EC  mov      x12, #0x5555555555555555
//   0x0a8218: F28AAACC  movk     x12, #0x5556
static inline uint64_t fde_func_0804_0x0a820c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a820cULL ^ (static_cast<uint64_t>(0xa9422808ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1db738ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0805 | PC: 0x0a8290 | FDE: 0x1db750 | Size: 96 bytes [_PyDict_KeysSize]
// Khung tháo gỡ #0805 | Địa chỉ PC: 0x0a8290 | Địa chỉ FDE: 0x1db750 | Kích thước: 96 bytes
//   0x0a8290: F9400408  ldr      x8, [x0, #8]
//   0x0a8294: F104011F  cmp      x8, #0x100
//   0x0a8298: 5400006A  b.ge     #0xa82a4
//   0x0a829c: 52800029  mov      w9, #1
static inline uint64_t fde_func_0805_0x0a8290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8290ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf104011fULL) ^ 0x1db750ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0806 | PC: 0x0a82f0 | FDE: 0x1db768 | Size: 200 bytes [PyDict_Contains]
// Khung tháo gỡ #0806 | Địa chỉ PC: 0x0a82f0 | Địa chỉ FDE: 0x1db768 | Kích thước: 200 bytes
//   0x0a82f0: D10103FF  sub      sp, sp, #0x40
//   0x0a82f4: F9000BF5  str      x21, [sp, #0x10]
//   0x0a82f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a82fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0806_0x0a82f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a82f0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1db768ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0807 | PC: 0x0a83b8 | FDE: 0x1db788 | Size: 120 bytes [_PyDict_Contains_KnownHash]
// Khung tháo gỡ #0807 | Địa chỉ PC: 0x0a83b8 | Địa chỉ FDE: 0x1db788 | Kích thước: 120 bytes
//   0x0a83b8: D100C3FF  sub      sp, sp, #0x30
//   0x0a83bc: F9000BF3  str      x19, [sp, #0x10]
//   0x0a83c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a83c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0807_0x0a83b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a83b8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1db788ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0808 | PC: 0x0a8430 | FDE: 0x1db7a8 | Size: 256 bytes [_PyDict_ContainsId]
// Khung tháo gỡ #0808 | Địa chỉ PC: 0x0a8430 | Địa chỉ FDE: 0x1db7a8 | Kích thước: 256 bytes
//   0x0a8430: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a8434: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8438: 910043FD  add      x29, sp, #0x10
//   0x0a843c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0808_0x0a8430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8430ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0809 | PC: 0x0a8da8 | FDE: 0x1db8f0 | Size: 100 bytes [PyDict_GetItemString]
// Khung tháo gỡ #0809 | Địa chỉ PC: 0x0a8da8 | Địa chỉ FDE: 0x1db8f0 | Kích thước: 100 bytes
//   0x0a8da8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a8dac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8db0: 910043FD  add      x29, sp, #0x10
//   0x0a8db4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0809_0x0a8da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8da8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db8f0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0810 | PC: 0x0a8e0c | FDE: 0x1db910 | Size: 72 bytes [_PyDict_SetItemId]
// Khung tháo gỡ #0810 | Địa chỉ PC: 0x0a8e0c | Địa chỉ FDE: 0x1db910 | Kích thước: 72 bytes
//   0x0a8e0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a8e10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8e14: 910043FD  add      x29, sp, #0x10
//   0x0a8e18: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0810_0x0a8e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8e0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db910ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0811 | PC: 0x0a8e54 | FDE: 0x1db930 | Size: 160 bytes [PyDict_SetItemString]
// Khung tháo gỡ #0811 | Địa chỉ PC: 0x0a8e54 | Địa chỉ FDE: 0x1db930 | Kích thước: 160 bytes
//   0x0a8e54: D10103FF  sub      sp, sp, #0x40
//   0x0a8e58: F9000BF5  str      x21, [sp, #0x10]
//   0x0a8e5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a8e60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0811_0x0a8e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8e54ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1db930ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0812 | PC: 0x0a8ef4 | FDE: 0x1db950 | Size: 64 bytes [_PyDict_DelItemId]
// Khung tháo gỡ #0812 | Địa chỉ PC: 0x0a8ef4 | Địa chỉ FDE: 0x1db950 | Kích thước: 64 bytes
//   0x0a8ef4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a8ef8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8efc: 910043FD  add      x29, sp, #0x10
//   0x0a8f00: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0812_0x0a8ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8ef4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db950ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0813 | PC: 0x0a8f34 | FDE: 0x1db970 | Size: 256 bytes [PyDict_DelItemString]
// Khung tháo gỡ #0813 | Địa chỉ PC: 0x0a8f34 | Địa chỉ FDE: 0x1db970 | Kích thước: 256 bytes
//   0x0a8f34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a8f38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8f3c: 910043FD  add      x29, sp, #0x10
//   0x0a8f40: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0813_0x0a8f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0814 | PC: 0x0a9780 | FDE: 0x1dba60 | Size: 132 bytes [_PyDictView_New]
// Khung tháo gỡ #0814 | Địa chỉ PC: 0x0a9780 | Địa chỉ FDE: 0x1dba60 | Kích thước: 132 bytes
//   0x0a9780: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a9784: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a9788: 910043FD  add      x29, sp, #0x10
//   0x0a978c: B40001C0  cbz      x0, #0xa97c4
static inline uint64_t fde_func_0814_0x0a9780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9780ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dba60ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0815 | PC: 0x0a9804 | FDE: 0x1dba80 | Size: 256 bytes [_PyDictView_Intersect]
// Khung tháo gỡ #0815 | Địa chỉ PC: 0x0a9804 | Địa chỉ FDE: 0x1dba80 | Kích thước: 256 bytes
//   0x0a9804: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a9808: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a980c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a9810: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0815_0x0a9804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9804ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dba80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0816 | PC: 0x0a9e90 | FDE: 0x1dbbc8 | Size: 64 bytes [_PyDict_NewKeysForClass]
// Khung tháo gỡ #0816 | Địa chỉ PC: 0x0a9e90 | Địa chỉ FDE: 0x1dbbc8 | Kích thước: 64 bytes
//   0x0a9e90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a9e94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a9e98: 910043FD  add      x29, sp, #0x10
//   0x0a9e9c: 52800100  mov      w0, #8
static inline uint64_t fde_func_0816_0x0a9e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9e90ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dbbc8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0817 | PC: 0x0a9ed0 | FDE: 0x1dbbe8 | Size: 256 bytes [PyObject_GenericGetDict]
// Khung tháo gỡ #0817 | Địa chỉ PC: 0x0a9ed0 | Địa chỉ FDE: 0x1dbbe8 | Kích thước: 256 bytes
//   0x0a9ed0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a9ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a9ed8: 910043FD  add      x29, sp, #0x10
//   0x0a9edc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0817_0x0a9ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9ed0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dbbe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0818 | PC: 0x0aa00c | FDE: 0x1dbc30 | Size: 256 bytes [_PyObjectDict_SetItem]
// Khung tháo gỡ #0818 | Địa chỉ PC: 0x0aa00c | Địa chỉ FDE: 0x1dbc30 | Kích thước: 256 bytes
//   0x0aa00c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0aa010: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0aa014: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0aa018: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0818_0x0aa00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa00cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1dbc30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0819 | PC: 0x0aa2c8 | FDE: 0x1dbc60 | Size: 4 bytes [_PyDictKeys_DecRef]
// Khung tháo gỡ #0819 | Địa chỉ PC: 0x0aa2c8 | Địa chỉ FDE: 0x1dbc60 | Kích thước: 4 bytes
//   0x0aa2c8: 17FFF0D4  b        #0xa6618
static inline uint64_t fde_func_0819_0x0aa2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa2c8ULL ^ (static_cast<uint64_t>(0x17fff0d4ULL) << 13);
    acc = (acc + a1 + 0xb9401808ULL) ^ 0x1dbc60ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0820 | PC: 0x0aa2cc | FDE: 0x1dbc78 | Size: 256 bytes [BD_PyDictKeys_GetVersionForCurrentState]
// Khung tháo gỡ #0820 | Địa chỉ PC: 0x0aa2cc | Địa chỉ FDE: 0x1dbc78 | Kích thước: 256 bytes
//   0x0aa2cc: B9401808  ldr      w8, [x0, #0x18]
//   0x0aa2d0: 35000148  cbnz     w8, #0xaa2f8
//   0x0aa2d4: F0000B09  adrp     x9, #0x20d000
//   0x0aa2d8: B94CA928  ldr      w8, [x9, #0xca8]
static inline uint64_t fde_func_0820_0x0aa2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa2ccULL ^ (static_cast<uint64_t>(0xb9401808ULL) << 13);
    acc = (acc + a1 + 0x35000148ULL) ^ 0x1dbc78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0821 | PC: 0x0ab80c | FDE: 0x1dc100 | Size: 256 bytes [PyMemoryView_FromMemory]
// Khung tháo gỡ #0821 | Địa chỉ PC: 0x0ab80c | Địa chỉ FDE: 0x1dc100 | Kích thước: 256 bytes
//   0x0ab80c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ab810: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ab814: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ab818: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0821_0x0ab80c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab80cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dc100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0822 | PC: 0x0abcdc | FDE: 0x1dc150 | Size: 168 bytes [PyMemoryView_FromBuffer]
// Khung tháo gỡ #0822 | Địa chỉ PC: 0x0abcdc | Địa chỉ FDE: 0x1dc150 | Kích thước: 168 bytes
//   0x0abcdc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0abce0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0abce4: 910043FD  add      x29, sp, #0x10
//   0x0abce8: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0822_0x0abcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abcdcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dc150ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0823 | PC: 0x0abd84 | FDE: 0x1dc170 | Size: 256 bytes [PyMemoryView_FromObject]
// Khung tháo gỡ #0823 | Địa chỉ PC: 0x0abd84 | Địa chỉ FDE: 0x1dc170 | Kích thước: 256 bytes
//   0x0abd84: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0abd88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0abd8c: 910043FD  add      x29, sp, #0x10
//   0x0abd90: 90000AA9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0823_0x0abd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abd84ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dc170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0824 | PC: 0x0abeac | FDE: 0x1dc190 | Size: 256 bytes [PyMemoryView_GetContiguous]
// Khung tháo gỡ #0824 | Địa chỉ PC: 0x0abeac | Địa chỉ FDE: 0x1dc190 | Kích thước: 256 bytes
//   0x0abeac: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0abeb0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0abeb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0abeb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0824_0x0abeac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abeacULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dc190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0825 | PC: 0x0ac330 | FDE: 0x1dc1b8 | Size: 256 bytes [PyBuffer_ToContiguous]
// Khung tháo gỡ #0825 | Địa chỉ PC: 0x0ac330 | Địa chỉ FDE: 0x1dc1b8 | Kích thước: 256 bytes
//   0x0ac330: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ac334: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ac338: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ac33c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0825_0x0ac330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac330ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dc1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0826 | PC: 0x0b071c | FDE: 0x1dc8f0 | Size: 12 bytes [PyCFunction_New]
// Khung tháo gỡ #0826 | Địa chỉ PC: 0x0b071c | Địa chỉ FDE: 0x1dc8f0 | Kích thước: 12 bytes
//   0x0b071c: AA1F03E2  mov      x2, xzr
//   0x0b0720: AA1F03E3  mov      x3, xzr
//   0x0b0724: 17FEA4BB  b        #0x59a10
static inline uint64_t fde_func_0826_0x0b071c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b071cULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x1dc8f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0827 | PC: 0x0b0728 | FDE: 0x1dc908 | Size: 8 bytes [PyCFunction_NewEx]
// Khung tháo gỡ #0827 | Địa chỉ PC: 0x0b0728 | Địa chỉ FDE: 0x1dc908 | Kích thước: 8 bytes
//   0x0b0728: AA1F03E3  mov      x3, xzr
//   0x0b072c: 17FEA4B9  b        #0x59a10
static inline uint64_t fde_func_0827_0x0b0728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0728ULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0x17fea4b9ULL) ^ 0x1dc908ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0828 | PC: 0x0b0730 | FDE: 0x1dc920 | Size: 256 bytes [PyCMethod_New]
// Khung tháo gỡ #0828 | Địa chỉ PC: 0x0b0730 | Địa chỉ FDE: 0x1dc920 | Kích thước: 256 bytes
//   0x0b0730: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0b0734: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b0738: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b073c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0828_0x0b0730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0730ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dc920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0829 | PC: 0x0b0dd8 | FDE: 0x1dca10 | Size: 96 bytes [PyCFunction_GetFunction]
// Khung tháo gỡ #0829 | Địa chỉ PC: 0x0b0dd8 | Địa chỉ FDE: 0x1dca10 | Kích thước: 96 bytes
//   0x0b0dd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b0ddc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0de0: 910043FD  add      x29, sp, #0x10
//   0x0b0de4: F0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0829_0x0b0dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0dd8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dca10ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0830 | PC: 0x0b0e38 | FDE: 0x1dca30 | Size: 104 bytes [PyCFunction_GetSelf]
// Khung tháo gỡ #0830 | Địa chỉ PC: 0x0b0e38 | Địa chỉ FDE: 0x1dca30 | Kích thước: 104 bytes
//   0x0b0e38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b0e3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0e40: 910043FD  add      x29, sp, #0x10
//   0x0b0e44: F0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0830_0x0b0e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0e38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dca30ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0831 | PC: 0x0b0ea0 | FDE: 0x1dca50 | Size: 96 bytes [PyCFunction_GetFlags]
// Khung tháo gỡ #0831 | Địa chỉ PC: 0x0b0ea0 | Địa chỉ FDE: 0x1dca50 | Kích thước: 96 bytes
//   0x0b0ea0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b0ea4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0ea8: 910043FD  add      x29, sp, #0x10
//   0x0b0eac: F0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0831_0x0b0ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0ea0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dca50ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0832 | PC: 0x0b0f00 | FDE: 0x1dca70 | Size: 256 bytes [PyCMethod_GetClass]
// Khung tháo gỡ #0832 | Địa chỉ PC: 0x0b0f00 | Địa chỉ FDE: 0x1dca70 | Kích thước: 256 bytes
//   0x0b0f00: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b0f04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0f08: 910043FD  add      x29, sp, #0x10
//   0x0b0f0c: F0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0832_0x0b0f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0f00ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dca70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0833 | PC: 0x0b1540 | FDE: 0x1dcc00 | Size: 92 bytes [_PyModule_IsExtension]
// Khung tháo gỡ #0833 | Địa chỉ PC: 0x0b1540 | Địa chỉ FDE: 0x1dcc00 | Kích thước: 92 bytes
//   0x0b1540: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b1544: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b1548: 910043FD  add      x29, sp, #0x10
//   0x0b154c: D0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0833_0x0b1540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1540ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcc00ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0834 | PC: 0x0b159c | FDE: 0x1dcc20 | Size: 96 bytes [PyModuleDef_Init]
// Khung tháo gỡ #0834 | Địa chỉ PC: 0x0b159c | Địa chỉ FDE: 0x1dcc20 | Kích thước: 96 bytes
//   0x0b159c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b15a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b15a4: 910043FD  add      x29, sp, #0x10
//   0x0b15a8: D0000A74  adrp     x20, #0x1ff000
static inline uint64_t fde_func_0834_0x0b159c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b159cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcc20ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0835 | PC: 0x0b15fc | FDE: 0x1dcc40 | Size: 256 bytes [PyModule_NewObject]
// Khung tháo gỡ #0835 | Địa chỉ PC: 0x0b15fc | Địa chỉ FDE: 0x1dcc40 | Kích thước: 256 bytes
//   0x0b15fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b1600: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b1604: 910043FD  add      x29, sp, #0x10
//   0x0b1608: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0835_0x0b15fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b15fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcc40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0836 | PC: 0x0b17b4 | FDE: 0x1dcc88 | Size: 176 bytes [PyModule_New]
// Khung tháo gỡ #0836 | Địa chỉ PC: 0x0b17b4 | Địa chỉ FDE: 0x1dcc88 | Kích thước: 176 bytes
//   0x0b17b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b17b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b17bc: 910043FD  add      x29, sp, #0x10
//   0x0b17c0: 97FEAB40  bl       #0x5c4c0
static inline uint64_t fde_func_0836_0x0b17b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b17b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcc88ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0837 | PC: 0x0b1864 | FDE: 0x1dcca8 | Size: 112 bytes [PyModule_Create2]
// Khung tháo gỡ #0837 | Địa chỉ PC: 0x0b1864 | Địa chỉ FDE: 0x1dcca8 | Kích thước: 112 bytes
//   0x0b1864: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b1868: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b186c: 910043FD  add      x29, sp, #0x10
//   0x0b1870: D0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0837_0x0b1864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1864ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcca8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0838 | PC: 0x0b18d4 | FDE: 0x1dccc8 | Size: 256 bytes [_PyModule_CreateInitialized]
// Khung tháo gỡ #0838 | Địa chỉ PC: 0x0b18d4 | Địa chỉ FDE: 0x1dccc8 | Kích thước: 256 bytes
//   0x0b18d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b18d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b18dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b18e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0838_0x0b18d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b18d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dccc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0839 | PC: 0x0b1aa0 | FDE: 0x1dcce8 | Size: 244 bytes [PyModule_AddFunctions]
// Khung tháo gỡ #0839 | Địa chỉ PC: 0x0b1aa0 | Địa chỉ FDE: 0x1dcce8 | Kích thước: 244 bytes
//   0x0b1aa0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b1aa4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b1aa8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b1aac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0839_0x0b1aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1aa0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dcce8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0840 | PC: 0x0b1b94 | FDE: 0x1dcd10 | Size: 116 bytes [PyModule_SetDocString]
// Khung tháo gỡ #0840 | Địa chỉ PC: 0x0b1b94 | Địa chỉ FDE: 0x1dcd10 | Kích thước: 116 bytes
//   0x0b1b94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b1b98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b1b9c: 910043FD  add      x29, sp, #0x10
//   0x0b1ba0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0840_0x0b1b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1b94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcd10ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0841 | PC: 0x0b1c08 | FDE: 0x1dcd30 | Size: 256 bytes [PyModule_FromDefAndSpec2]
// Khung tháo gỡ #0841 | Địa chỉ PC: 0x0b1c08 | Địa chỉ FDE: 0x1dcd30 | Kích thước: 256 bytes
//   0x0b1c08: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0b1c0c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b1c10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b1c14: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0841_0x0b1c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1c08ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1dcd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0842 | PC: 0x0b1ffc | FDE: 0x1dcd58 | Size: 256 bytes [PyModule_ExecDef]
// Khung tháo gỡ #0842 | Địa chỉ PC: 0x0b1ffc | Địa chỉ FDE: 0x1dcd58 | Kích thước: 256 bytes
//   0x0b1ffc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b2000: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b2004: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b2008: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0842_0x0b1ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1ffcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dcd58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0843 | PC: 0x0b2140 | FDE: 0x1dcd80 | Size: 76 bytes [PyModule_GetName]
// Khung tháo gỡ #0843 | Địa chỉ PC: 0x0b2140 | Địa chỉ FDE: 0x1dcd80 | Kích thước: 76 bytes
//   0x0b2140: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b2144: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2148: 910043FD  add      x29, sp, #0x10
//   0x0b214c: 97FE9FB5  bl       #0x5a020
static inline uint64_t fde_func_0843_0x0b2140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2140ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcd80ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0844 | PC: 0x0b218c | FDE: 0x1dcda0 | Size: 184 bytes [PyModule_GetNameObject]
// Khung tháo gỡ #0844 | Địa chỉ PC: 0x0b218c | Địa chỉ FDE: 0x1dcda0 | Kích thước: 184 bytes
//   0x0b218c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b2190: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2194: 910043FD  add      x29, sp, #0x10
//   0x0b2198: B0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0844_0x0b218c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b218cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcda0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0845 | PC: 0x0b2244 | FDE: 0x1dcdc0 | Size: 92 bytes [PyModule_GetDict]
// Khung tháo gỡ #0845 | Địa chỉ PC: 0x0b2244 | Địa chỉ FDE: 0x1dcdc0 | Kích thước: 92 bytes
//   0x0b2244: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b2248: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b224c: 910043FD  add      x29, sp, #0x10
//   0x0b2250: B0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0845_0x0b2244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2244ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcdc0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0846 | PC: 0x0b22a0 | FDE: 0x1dcde0 | Size: 172 bytes [PyModule_GetFilenameObject]
// Khung tháo gỡ #0846 | Địa chỉ PC: 0x0b22a0 | Địa chỉ FDE: 0x1dcde0 | Kích thước: 172 bytes
//   0x0b22a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b22a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b22a8: 910043FD  add      x29, sp, #0x10
//   0x0b22ac: B0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0846_0x0b22a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b22a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcde0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0847 | PC: 0x0b234c | FDE: 0x1dce00 | Size: 80 bytes [PyModule_GetFilename]
// Khung tháo gỡ #0847 | Địa chỉ PC: 0x0b234c | Địa chỉ FDE: 0x1dce00 | Kích thước: 80 bytes
//   0x0b234c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2350: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2354: 910043FD  add      x29, sp, #0x10
//   0x0b2358: 97FE9DCA  bl       #0x59a80
static inline uint64_t fde_func_0847_0x0b234c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b234cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dce00ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0848 | PC: 0x0b239c | FDE: 0x1dce20 | Size: 80 bytes [PyModule_GetDef]
// Khung tháo gỡ #0848 | Địa chỉ PC: 0x0b239c | Địa chỉ FDE: 0x1dce20 | Kích thước: 80 bytes
//   0x0b239c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b23a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b23a4: 910043FD  add      x29, sp, #0x10
//   0x0b23a8: B0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0848_0x0b239c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b239cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dce20ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0849 | PC: 0x0b23ec | FDE: 0x1dce40 | Size: 80 bytes [PyModule_GetState]
// Khung tháo gỡ #0849 | Địa chỉ PC: 0x0b23ec | Địa chỉ FDE: 0x1dce40 | Kích thước: 80 bytes
//   0x0b23ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b23f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b23f4: 910043FD  add      x29, sp, #0x10
//   0x0b23f8: B0000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0849_0x0b23ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b23ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dce40ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0850 | PC: 0x0b243c | FDE: 0x1dce60 | Size: 16 bytes [_PyModule_Clear]
// Khung tháo gỡ #0850 | Địa chỉ PC: 0x0b243c | Địa chỉ FDE: 0x1dce60 | Kích thước: 16 bytes
//   0x0b243c: F9400800  ldr      x0, [x0, #0x10]
//   0x0b2440: B4000040  cbz      x0, #0xb2448
//   0x0b2444: 17FEA05B  b        #0x5a5b0
//   0x0b2448: D65F03C0  ret      
static inline uint64_t fde_func_0850_0x0b243c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b243cULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x1dce60ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0851 | PC: 0x0b244c | FDE: 0x1dce78 | Size: 256 bytes [_PyModule_ClearDict]
// Khung tháo gỡ #0851 | Địa chỉ PC: 0x0b244c | Địa chỉ FDE: 0x1dce78 | Kích thước: 256 bytes
//   0x0b244c: D10183FF  sub      sp, sp, #0x60
//   0x0b2450: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b2454: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b2458: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0851_0x0b244c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b244cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1dce78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0852 | PC: 0x0b27c8 | FDE: 0x1dcea0 | Size: 104 bytes [_PyModuleSpec_IsInitializing]
// Khung tháo gỡ #0852 | Địa chỉ PC: 0x0b27c8 | Địa chỉ FDE: 0x1dcea0 | Kích thước: 104 bytes
//   0x0b27c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b27cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b27d0: 910043FD  add      x29, sp, #0x10
//   0x0b27d4: B40001A0  cbz      x0, #0xb2808
static inline uint64_t fde_func_0852_0x0b27c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b27c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dcea0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0853 | PC: 0x0b2830 | FDE: 0x1dcec0 | Size: 256 bytes [module_getattro]
// Khung tháo gỡ #0853 | Địa chỉ PC: 0x0b2830 | Địa chỉ FDE: 0x1dcec0 | Kích thước: 256 bytes
//   0x0b2830: D101C3FF  sub      sp, sp, #0x70
//   0x0b2834: F90013F9  str      x25, [sp, #0x20]
//   0x0b2838: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b283c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0853_0x0b2830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2830ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1dcec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0854 | PC: 0x0b362c | FDE: 0x1dd0e8 | Size: 220 bytes [_PyNamespace_New]
// Khung tháo gỡ #0854 | Địa chỉ PC: 0x0b362c | Địa chỉ FDE: 0x1dd0e8 | Kích thước: 220 bytes
//   0x0b362c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b3630: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3634: 910043FD  add      x29, sp, #0x10
//   0x0b3638: 90000A68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0854_0x0b362c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b362cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd0e8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0855 | PC: 0x0b3708 | FDE: 0x1dd128 | Size: 180 bytes [_PyObject_CheckConsistency]
// Khung tháo gỡ #0855 | Địa chỉ PC: 0x0b3708 | Địa chỉ FDE: 0x1dd128 | Kích thước: 180 bytes
//   0x0b3708: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b370c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3710: 910043FD  add      x29, sp, #0x10
//   0x0b3714: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_0855_0x0b3708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3708ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd128ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0856 | PC: 0x0b37bc | FDE: 0x1dd148 | Size: 140 bytes [_PyObject_IsFreed]
// Khung tháo gỡ #0856 | Địa chỉ PC: 0x0b37bc | Địa chỉ FDE: 0x1dd148 | Kích thước: 140 bytes
//   0x0b37bc: B206DBE8  mov      x8, #-0x202020202020203
//   0x0b37c0: F29FBF88  movk     x8, #0xfdfc
//   0x0b37c4: EB08001F  cmp      x0, x8
//   0x0b37c8: 5400016C  b.gt     #0xb37f4
static inline uint64_t fde_func_0856_0x0b37bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b37bcULL ^ (static_cast<uint64_t>(0xb206dbe8ULL) << 13);
    acc = (acc + a1 + 0xf29fbf88ULL) ^ 0x1dd148ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0857 | PC: 0x0b3848 | FDE: 0x1dd160 | Size: 256 bytes [_PyObject_AssertFailed]
// Khung tháo gỡ #0857 | Địa chỉ PC: 0x0b3848 | Địa chỉ FDE: 0x1dd160 | Kích thước: 256 bytes
//   0x0b3848: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b384c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b3850: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b3854: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0857_0x0b3848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3848ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dd160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0858 | PC: 0x0b396c | FDE: 0x1dd188 | Size: 20 bytes [Py_IncRef]
// Khung tháo gỡ #0858 | Địa chỉ PC: 0x0b396c | Địa chỉ FDE: 0x1dd188 | Kích thước: 20 bytes
//   0x0b396c: B4000080  cbz      x0, #0xb397c
//   0x0b3970: F9400008  ldr      x8, [x0]
//   0x0b3974: 91000508  add      x8, x8, #1
//   0x0b3978: F9000008  str      x8, [x0]
static inline uint64_t fde_func_0858_0x0b396c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b396cULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1dd188ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0859 | PC: 0x0b3980 | FDE: 0x1dd1a0 | Size: 36 bytes [Py_DecRef]
// Khung tháo gỡ #0859 | Địa chỉ PC: 0x0b3980 | Địa chỉ FDE: 0x1dd1a0 | Kích thước: 36 bytes
//   0x0b3980: B40000A0  cbz      x0, #0xb3994
//   0x0b3984: F9400008  ldr      x8, [x0]
//   0x0b3988: F1000508  subs     x8, x8, #1
//   0x0b398c: F9000008  str      x8, [x0]
static inline uint64_t fde_func_0859_0x0b3980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3980ULL ^ (static_cast<uint64_t>(0xb40000a0ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1dd1a0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0860 | PC: 0x0b39a4 | FDE: 0x1dd1b8 | Size: 16 bytes [_Py_IncRef]
// Khung tháo gỡ #0860 | Địa chỉ PC: 0x0b39a4 | Địa chỉ FDE: 0x1dd1b8 | Kích thước: 16 bytes
//   0x0b39a4: F9400008  ldr      x8, [x0]
//   0x0b39a8: 91000508  add      x8, x8, #1
//   0x0b39ac: F9000008  str      x8, [x0]
//   0x0b39b0: D65F03C0  ret      
static inline uint64_t fde_func_0860_0x0b39a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b39a4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1dd1b8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0861 | PC: 0x0b39b4 | FDE: 0x1dd1d0 | Size: 32 bytes [_Py_DecRef]
// Khung tháo gỡ #0861 | Địa chỉ PC: 0x0b39b4 | Địa chỉ FDE: 0x1dd1d0 | Kích thước: 32 bytes
//   0x0b39b4: F9400008  ldr      x8, [x0]
//   0x0b39b8: F1000508  subs     x8, x8, #1
//   0x0b39bc: F9000008  str      x8, [x0]
//   0x0b39c0: 54000040  b.eq     #0xb39c8
static inline uint64_t fde_func_0861_0x0b39b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b39b4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf1000508ULL) ^ 0x1dd1d0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0862 | PC: 0x0b39d4 | FDE: 0x1dd1e8 | Size: 44 bytes [PyObject_Init]
// Khung tháo gỡ #0862 | Địa chỉ PC: 0x0b39d4 | Địa chỉ FDE: 0x1dd1e8 | Kích thước: 44 bytes
//   0x0b39d4: B4000140  cbz      x0, #0xb39fc
//   0x0b39d8: F9000401  str      x1, [x0, #8]
//   0x0b39dc: 3942A428  ldrb     w8, [x1, #0xa9]
//   0x0b39e0: 36080088  tbz      w8, #1, #0xb39f0
static inline uint64_t fde_func_0862_0x0b39d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b39d4ULL ^ (static_cast<uint64_t>(0xb4000140ULL) << 13);
    acc = (acc + a1 + 0xf9000401ULL) ^ 0x1dd1e8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0863 | PC: 0x0b3a00 | FDE: 0x1dd200 | Size: 44 bytes [PyObject_InitVar]
// Khung tháo gỡ #0863 | Địa chỉ PC: 0x0b3a00 | Địa chỉ FDE: 0x1dd200 | Kích thước: 44 bytes
//   0x0b3a00: B4000140  cbz      x0, #0xb3a28
//   0x0b3a04: A9008801  stp      x1, x2, [x0, #8]
//   0x0b3a08: 3942A428  ldrb     w8, [x1, #0xa9]
//   0x0b3a0c: 36080088  tbz      w8, #1, #0xb3a1c
static inline uint64_t fde_func_0863_0x0b3a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a00ULL ^ (static_cast<uint64_t>(0xb4000140ULL) << 13);
    acc = (acc + a1 + 0xa9008801ULL) ^ 0x1dd200ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0864 | PC: 0x0b3a2c | FDE: 0x1dd218 | Size: 84 bytes [_PyObject_New]
// Khung tháo gỡ #0864 | Địa chỉ PC: 0x0b3a2c | Địa chỉ FDE: 0x1dd218 | Kích thước: 84 bytes
//   0x0b3a2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b3a30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3a34: 910043FD  add      x29, sp, #0x10
//   0x0b3a38: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0864_0x0b3a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd218ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0865 | PC: 0x0b3a80 | FDE: 0x1dd238 | Size: 100 bytes [_PyObject_NewVar]
// Khung tháo gỡ #0865 | Địa chỉ PC: 0x0b3a80 | Địa chỉ FDE: 0x1dd238 | Kích thước: 100 bytes
//   0x0b3a80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b3a84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3a88: 910043FD  add      x29, sp, #0x10
//   0x0b3a8c: A9422408  ldp      x8, x9, [x0, #0x20]
static inline uint64_t fde_func_0865_0x0b3a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd238ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0866 | PC: 0x0b3ae4 | FDE: 0x1dd258 | Size: 84 bytes [PyObject_CallFinalizer]
// Khung tháo gỡ #0866 | Địa chỉ PC: 0x0b3ae4 | Địa chỉ FDE: 0x1dd258 | Kích thước: 84 bytes
//   0x0b3ae4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b3ae8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3aec: 910043FD  add      x29, sp, #0x10
//   0x0b3af0: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_0866_0x0b3ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3ae4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd258ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0867 | PC: 0x0b3b38 | FDE: 0x1dd278 | Size: 108 bytes [PyObject_CallFinalizerFromDealloc]
// Khung tháo gỡ #0867 | Địa chỉ PC: 0x0b3b38 | Địa chỉ FDE: 0x1dd278 | Kích thước: 108 bytes
//   0x0b3b38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b3b3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3b40: 910043FD  add      x29, sp, #0x10
//   0x0b3b44: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0867_0x0b3b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3b38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd278ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0868 | PC: 0x0b3ba4 | FDE: 0x1dd298 | Size: 12 bytes [_Py_NewReference]
// Khung tháo gỡ #0868 | Địa chỉ PC: 0x0b3ba4 | Địa chỉ FDE: 0x1dd298 | Kích thước: 12 bytes
//   0x0b3ba4: 52800028  mov      w8, #1
//   0x0b3ba8: F9000008  str      x8, [x0]
//   0x0b3bac: D65F03C0  ret      
static inline uint64_t fde_func_0868_0x0b3ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3ba4ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x1dd298ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0869 | PC: 0x0b3bb0 | FDE: 0x1dd2b0 | Size: 20 bytes [BDPyObject_Print]
// Khung tháo gỡ #0869 | Địa chỉ PC: 0x0b3bb0 | Địa chỉ FDE: 0x1dd2b0 | Kích thước: 20 bytes
//   0x0b3bb0: 90000A68  adrp     x8, #0x1ff000
//   0x0b3bb4: F9443508  ldr      x8, [x8, #0x868]
//   0x0b3bb8: 2A1F03E2  mov      w2, wzr
//   0x0b3bbc: 91026101  add      x1, x8, #0x98
static inline uint64_t fde_func_0869_0x0b3bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3bb0ULL ^ (static_cast<uint64_t>(0x90000a68ULL) << 13);
    acc = (acc + a1 + 0xf9443508ULL) ^ 0x1dd2b0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0870 | PC: 0x0b3bc4 | FDE: 0x1dd2c8 | Size: 256 bytes [PyObject_Print]
// Khung tháo gỡ #0870 | Địa chỉ PC: 0x0b3bc4 | Địa chỉ FDE: 0x1dd2c8 | Kích thước: 256 bytes
//   0x0b3bc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b3bc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b3bcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b3bd0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0870_0x0b3bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3bc4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dd2c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0871 | PC: 0x0b3d70 | FDE: 0x1dd2e8 | Size: 256 bytes [PyObject_Str]
// Khung tháo gỡ #0871 | Địa chỉ PC: 0x0b3d70 | Địa chỉ FDE: 0x1dd2e8 | Kích thước: 256 bytes
//   0x0b3d70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b3d74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3d78: 910043FD  add      x29, sp, #0x10
//   0x0b3d7c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0871_0x0b3d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3d70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0872 | PC: 0x0b3ecc | FDE: 0x1dd308 | Size: 256 bytes [PyObject_Repr]
// Khung tháo gỡ #0872 | Địa chỉ PC: 0x0b3ecc | Địa chỉ FDE: 0x1dd308 | Kích thước: 256 bytes
//   0x0b3ecc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b3ed0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3ed4: 910043FD  add      x29, sp, #0x10
//   0x0b3ed8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0872_0x0b3ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3eccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0873 | PC: 0x0b4000 | FDE: 0x1dd328 | Size: 4 bytes [_Py_BreakPoint]
// Khung tháo gỡ #0873 | Địa chỉ PC: 0x0b4000 | Địa chỉ FDE: 0x1dd328 | Kích thước: 4 bytes
//   0x0b4000: D65F03C0  ret      
static inline uint64_t fde_func_0873_0x0b4000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4000ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x1dd328ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0874 | PC: 0x0b4004 | FDE: 0x1dd340 | Size: 256 bytes [_PyObject_Dump]
// Khung tháo gỡ #0874 | Địa chỉ PC: 0x0b4004 | Địa chỉ FDE: 0x1dd340 | Kích thước: 256 bytes
//   0x0b4004: D10143FF  sub      sp, sp, #0x50
//   0x0b4008: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b400c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b4010: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0874_0x0b4004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4004ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1dd340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0875 | PC: 0x0b4160 | FDE: 0x1dd368 | Size: 168 bytes [PyObject_ASCII]
// Khung tháo gỡ #0875 | Địa chỉ PC: 0x0b4160 | Địa chỉ FDE: 0x1dd368 | Kích thước: 168 bytes
//   0x0b4160: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b4164: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4168: 910043FD  add      x29, sp, #0x10
//   0x0b416c: 97FEA1DD  bl       #0x5c8e0
static inline uint64_t fde_func_0875_0x0b4160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4160ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd368ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0876 | PC: 0x0b4208 | FDE: 0x1dd388 | Size: 256 bytes [PyObject_Bytes]
// Khung tháo gỡ #0876 | Địa chỉ PC: 0x0b4208 | Địa chỉ FDE: 0x1dd388 | Kích thước: 256 bytes
//   0x0b4208: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b420c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4210: 910043FD  add      x29, sp, #0x10
//   0x0b4214: B4000400  cbz      x0, #0xb4294
static inline uint64_t fde_func_0876_0x0b4208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4208ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0877 | PC: 0x0b4370 | FDE: 0x1dd3a8 | Size: 256 bytes [_PyObject_FunctionStr]
// Khung tháo gỡ #0877 | Địa chỉ PC: 0x0b4370 | Địa chỉ FDE: 0x1dd3a8 | Kích thước: 256 bytes
//   0x0b4370: D10103FF  sub      sp, sp, #0x40
//   0x0b4374: F9000BF5  str      x21, [sp, #0x10]
//   0x0b4378: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b437c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0877_0x0b4370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4370ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1dd3a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0878 | PC: 0x0b44a4 | FDE: 0x1dd3c8 | Size: 76 bytes [_PyObject_LookupAttrId]
// Khung tháo gỡ #0878 | Địa chỉ PC: 0x0b44a4 | Địa chỉ FDE: 0x1dd3c8 | Kích thước: 76 bytes
//   0x0b44a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b44a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b44ac: 910043FD  add      x29, sp, #0x10
//   0x0b44b0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0878_0x0b44a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b44a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd3c8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0879 | PC: 0x0b44f0 | FDE: 0x1dd3e8 | Size: 172 bytes [PyObject_RichCompareBool]
// Khung tháo gỡ #0879 | Địa chỉ PC: 0x0b44f0 | Địa chỉ FDE: 0x1dd3e8 | Kích thước: 172 bytes
//   0x0b44f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b44f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b44f8: 910043FD  add      x29, sp, #0x10
//   0x0b44fc: EB01001F  cmp      x0, x1
static inline uint64_t fde_func_0879_0x0b44f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b44f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd3e8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0880 | PC: 0x0b459c | FDE: 0x1dd408 | Size: 256 bytes [PyObject_RichCompare]
// Khung tháo gỡ #0880 | Địa chỉ PC: 0x0b459c | Địa chỉ FDE: 0x1dd408 | Kích thước: 256 bytes
//   0x0b459c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0b45a0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b45a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b45a8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0880_0x0b459c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b459cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1dd408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0881 | PC: 0x0b47d4 | FDE: 0x1dd430 | Size: 164 bytes [PyObject_IsTrue]
// Khung tháo gỡ #0881 | Địa chỉ PC: 0x0b47d4 | Địa chỉ FDE: 0x1dd430 | Kích thước: 164 bytes
//   0x0b47d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b47d8: 910003FD  mov      x29, sp
//   0x0b47dc: F0000A48  adrp     x8, #0x1ff000
//   0x0b47e0: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_0881_0x0b47d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b47d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dd430ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0882 | PC: 0x0b4878 | FDE: 0x1dd450 | Size: 52 bytes [PyObject_HashNotImplemented]
// Khung tháo gỡ #0882 | Địa chỉ PC: 0x0b4878 | Địa chỉ FDE: 0x1dd450 | Kích thước: 52 bytes
//   0x0b4878: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b487c: 910003FD  mov      x29, sp
//   0x0b4880: F0000A49  adrp     x9, #0x1ff000
//   0x0b4884: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0882_0x0b4878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4878ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dd450ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0883 | PC: 0x0b48ac | FDE: 0x1dd470 | Size: 124 bytes [PyObject_Hash]
// Khung tháo gỡ #0883 | Địa chỉ PC: 0x0b48ac | Địa chỉ FDE: 0x1dd470 | Kích thước: 124 bytes
//   0x0b48ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b48b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b48b4: 910043FD  add      x29, sp, #0x10
//   0x0b48b8: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0883_0x0b48ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b48acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd470ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0884 | PC: 0x0b4928 | FDE: 0x1dd490 | Size: 132 bytes [PyObject_GetAttrString]
// Khung tháo gỡ #0884 | Địa chỉ PC: 0x0b4928 | Địa chỉ FDE: 0x1dd490 | Kích thước: 132 bytes
//   0x0b4928: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b492c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4930: 910043FD  add      x29, sp, #0x10
//   0x0b4934: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0884_0x0b4928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4928ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd490ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0885 | PC: 0x0b49ac | FDE: 0x1dd4b0 | Size: 200 bytes [PyObject_GetAttr]
// Khung tháo gỡ #0885 | Địa chỉ PC: 0x0b49ac | Địa chỉ FDE: 0x1dd4b0 | Kích thước: 200 bytes
//   0x0b49ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b49b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b49b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b49b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0885_0x0b49ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b49acULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dd4b0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0886 | PC: 0x0b4a74 | FDE: 0x1dd4d0 | Size: 68 bytes [PyObject_HasAttrString]
// Khung tháo gỡ #0886 | Địa chỉ PC: 0x0b4a74 | Địa chỉ FDE: 0x1dd4d0 | Kích thước: 68 bytes
//   0x0b4a74: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b4a78: 910003FD  mov      x29, sp
//   0x0b4a7c: 97FE9101  bl       #0x58e80
//   0x0b4a80: B4000140  cbz      x0, #0xb4aa8
static inline uint64_t fde_func_0886_0x0b4a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4a74ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dd4d0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0887 | PC: 0x0b4ab8 | FDE: 0x1dd4f0 | Size: 156 bytes [PyObject_SetAttrString]
// Khung tháo gỡ #0887 | Địa chỉ PC: 0x0b4ab8 | Địa chỉ FDE: 0x1dd4f0 | Kích thước: 156 bytes
//   0x0b4ab8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b4abc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b4ac0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b4ac4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0887_0x0b4ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4ab8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dd4f0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0888 | PC: 0x0b4b54 | FDE: 0x1dd510 | Size: 256 bytes [PyObject_SetAttr]
// Khung tháo gỡ #0888 | Địa chỉ PC: 0x0b4b54 | Địa chỉ FDE: 0x1dd510 | Kích thước: 256 bytes
//   0x0b4b54: D10103FF  sub      sp, sp, #0x40
//   0x0b4b58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b4b5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b4b60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0888_0x0b4b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4b54ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dd510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0889 | PC: 0x0b4d14 | FDE: 0x1dd538 | Size: 128 bytes [_PyObject_IsAbstract]
// Khung tháo gỡ #0889 | Địa chỉ PC: 0x0b4d14 | Địa chỉ FDE: 0x1dd538 | Kích thước: 128 bytes
//   0x0b4d14: D100C3FF  sub      sp, sp, #0x30
//   0x0b4d18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b4d1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b4d20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0889_0x0b4d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4d14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dd538ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0890 | PC: 0x0b4d94 | FDE: 0x1dd558 | Size: 60 bytes [_PyObject_GetAttrId]
// Khung tháo gỡ #0890 | Địa chỉ PC: 0x0b4d94 | Địa chỉ FDE: 0x1dd558 | Kích thước: 60 bytes
//   0x0b4d94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b4d98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4d9c: 910043FD  add      x29, sp, #0x10
//   0x0b4da0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0890_0x0b4d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4d94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd558ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0891 | PC: 0x0b4dd0 | FDE: 0x1dd578 | Size: 256 bytes [_PyObject_SetAttrId]
// Khung tháo gỡ #0891 | Địa chỉ PC: 0x0b4dd0 | Địa chỉ FDE: 0x1dd578 | Kích thước: 256 bytes
//   0x0b4dd0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b4dd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4dd8: 910043FD  add      x29, sp, #0x10
//   0x0b4ddc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0891_0x0b4dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4dd0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0892 | PC: 0x0b4f0c | FDE: 0x1dd5c0 | Size: 256 bytes [_PyObject_LookupAttr]
// Khung tháo gỡ #0892 | Địa chỉ PC: 0x0b4f0c | Địa chỉ FDE: 0x1dd5c0 | Kích thước: 256 bytes
//   0x0b4f0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b4f10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b4f14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b4f18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0892_0x0b4f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4f0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dd5c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0893 | PC: 0x0b5014 | FDE: 0x1dd5e0 | Size: 12 bytes [PyObject_GenericGetAttr]
// Khung tháo gỡ #0893 | Địa chỉ PC: 0x0b5014 | Địa chỉ FDE: 0x1dd5e0 | Kích thước: 12 bytes
//   0x0b5014: AA1F03E2  mov      x2, xzr
//   0x0b5018: 2A1F03E3  mov      w3, wzr
//   0x0b501c: 17FE9055  b        #0x59170
static inline uint64_t fde_func_0893_0x0b5014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5014ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e3ULL) ^ 0x1dd5e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0894 | PC: 0x0b5020 | FDE: 0x1dd5f8 | Size: 256 bytes [_PyObject_GenericGetAttrWithDict]
// Khung tháo gỡ #0894 | Địa chỉ PC: 0x0b5020 | Địa chỉ FDE: 0x1dd5f8 | Kích thước: 256 bytes
//   0x0b5020: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0b5024: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b5028: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b502c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0894_0x0b5020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5020ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1dd5f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0895 | PC: 0x0b52ac | FDE: 0x1dd628 | Size: 88 bytes [PyObject_HasAttr]
// Khung tháo gỡ #0895 | Địa chỉ PC: 0x0b52ac | Địa chỉ FDE: 0x1dd628 | Kích thước: 88 bytes
//   0x0b52ac: D10083FF  sub      sp, sp, #0x20
//   0x0b52b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b52b4: 910043FD  add      x29, sp, #0x10
//   0x0b52b8: 910023E2  add      x2, sp, #8
static inline uint64_t fde_func_0895_0x0b52ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b52acULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd628ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0896 | PC: 0x0b5304 | FDE: 0x1dd648 | Size: 64 bytes [_PyObject_GetDictPtr]
// Khung tháo gỡ #0896 | Địa chỉ PC: 0x0b5304 | Địa chỉ FDE: 0x1dd648 | Kích thước: 64 bytes
//   0x0b5304: F9400409  ldr      x9, [x0, #8]
//   0x0b5308: F9409128  ldr      x8, [x9, #0x120]
//   0x0b530c: B4000188  cbz      x8, #0xb533c
//   0x0b5310: B6F80128  tbz      x8, #0x3f, #0xb5334
static inline uint64_t fde_func_0896_0x0b5304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5304ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf9409128ULL) ^ 0x1dd648ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0897 | PC: 0x0b5344 | FDE: 0x1dd660 | Size: 16 bytes [PyObject_SelfIter]
// Khung tháo gỡ #0897 | Địa chỉ PC: 0x0b5344 | Địa chỉ FDE: 0x1dd660 | Kích thước: 16 bytes
//   0x0b5344: F9400008  ldr      x8, [x0]
//   0x0b5348: 91000508  add      x8, x8, #1
//   0x0b534c: F9000008  str      x8, [x0]
//   0x0b5350: D65F03C0  ret      
static inline uint64_t fde_func_0897_0x0b5344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5344ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1dd660ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0898 | PC: 0x0b5354 | FDE: 0x1dd678 | Size: 52 bytes [_PyObject_NextNotImplemented]
// Khung tháo gỡ #0898 | Địa chỉ PC: 0x0b5354 | Địa chỉ FDE: 0x1dd678 | Kích thước: 52 bytes
//   0x0b5354: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5358: 910003FD  mov      x29, sp
//   0x0b535c: D0000A49  adrp     x9, #0x1ff000
//   0x0b5360: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0898_0x0b5354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5354ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dd678ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0899 | PC: 0x0b5388 | FDE: 0x1dd698 | Size: 256 bytes [_PyObject_GetMethod]
// Khung tháo gỡ #0899 | Địa chỉ PC: 0x0b5388 | Địa chỉ FDE: 0x1dd698 | Kích thước: 256 bytes
//   0x0b5388: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0b538c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b5390: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b5394: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0899_0x0b5388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5388ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1dd698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0900 | PC: 0x0b558c | FDE: 0x1dd6c8 | Size: 256 bytes [_PyObject_GenericSetAttrWithDict]
// Khung tháo gỡ #0900 | Địa chỉ PC: 0x0b558c | Địa chỉ FDE: 0x1dd6c8 | Kích thước: 256 bytes
//   0x0b558c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b5590: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b5594: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b5598: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0900_0x0b558c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b558cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dd6c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0901 | PC: 0x0b578c | FDE: 0x1dd6f0 | Size: 8 bytes [PyObject_GenericSetAttr]
// Khung tháo gỡ #0901 | Địa chỉ PC: 0x0b578c | Địa chỉ FDE: 0x1dd6f0 | Kích thước: 8 bytes
//   0x0b578c: AA1F03E3  mov      x3, xzr
//   0x0b5790: 17FE9A9C  b        #0x5c200
static inline uint64_t fde_func_0901_0x0b578c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b578cULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0x17fe9a9cULL) ^ 0x1dd6f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0902 | PC: 0x0b5794 | FDE: 0x1dd708 | Size: 196 bytes [PyObject_GenericSetDict]
// Khung tháo gỡ #0902 | Địa chỉ PC: 0x0b5794 | Địa chỉ FDE: 0x1dd708 | Kích thước: 196 bytes
//   0x0b5794: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b5798: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b579c: 910043FD  add      x29, sp, #0x10
//   0x0b57a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0902_0x0b5794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5794ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd708ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0903 | PC: 0x0b5858 | FDE: 0x1dd728 | Size: 32 bytes [PyObject_Not]
// Khung tháo gỡ #0903 | Địa chỉ PC: 0x0b5858 | Địa chỉ FDE: 0x1dd728 | Kích thước: 32 bytes
//   0x0b5858: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b585c: 910003FD  mov      x29, sp
//   0x0b5860: 97FE9848  bl       #0x5b980
//   0x0b5864: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_0903_0x0b5858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5858ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dd728ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0904 | PC: 0x0b5878 | FDE: 0x1dd748 | Size: 24 bytes [PyCallable_Check]
// Khung tháo gỡ #0904 | Địa chỉ PC: 0x0b5878 | Địa chỉ FDE: 0x1dd748 | Kích thước: 24 bytes
//   0x0b5878: B40000A0  cbz      x0, #0xb588c
//   0x0b587c: F9400408  ldr      x8, [x0, #8]
//   0x0b5880: F9404108  ldr      x8, [x8, #0x80]
//   0x0b5884: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0904_0x0b5878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5878ULL ^ (static_cast<uint64_t>(0xb40000a0ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1dd748ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0905 | PC: 0x0b5890 | FDE: 0x1dd760 | Size: 256 bytes [PyObject_Dir]
// Khung tháo gỡ #0905 | Địa chỉ PC: 0x0b5890 | Địa chỉ FDE: 0x1dd760 | Kích thước: 256 bytes
//   0x0b5890: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b5894: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5898: 910043FD  add      x29, sp, #0x10
//   0x0b589c: B4000320  cbz      x0, #0xb5900
static inline uint64_t fde_func_0905_0x0b5890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5890ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0906 | PC: 0x0b5b1c | FDE: 0x1dd830 | Size: 256 bytes [_PyTypes_Init]
// Khung tháo gỡ #0906 | Địa chỉ PC: 0x0b5b1c | Địa chỉ FDE: 0x1dd830 | Kích thước: 256 bytes
//   0x0b5b1c: D10143FF  sub      sp, sp, #0x50
//   0x0b5b20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b5b24: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0b5b28: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0906_0x0b5b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5b1cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1dd830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0907 | PC: 0x0b6894 | FDE: 0x1dd850 | Size: 60 bytes [_PyObject_DebugTypeStats]
// Khung tháo gỡ #0907 | Địa chỉ PC: 0x0b6894 | Địa chỉ FDE: 0x1dd850 | Kích thước: 60 bytes
//   0x0b6894: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b689c: 910043FD  add      x29, sp, #0x10
//   0x0b68a0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0907_0x0b6894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6894ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd850ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0908 | PC: 0x0b68d0 | FDE: 0x1dd870 | Size: 212 bytes [Py_ReprEnter]
// Khung tháo gỡ #0908 | Địa chỉ PC: 0x0b68d0 | Địa chỉ FDE: 0x1dd870 | Kích thước: 212 bytes
//   0x0b68d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b68d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b68d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b68dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0908_0x0b68d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b68d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dd870ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0909 | PC: 0x0b69a4 | FDE: 0x1dd890 | Size: 180 bytes [Py_ReprLeave]
// Khung tháo gỡ #0909 | Địa chỉ PC: 0x0b69a4 | Địa chỉ FDE: 0x1dd890 | Kích thước: 180 bytes
//   0x0b69a4: D10103FF  sub      sp, sp, #0x40
//   0x0b69a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b69ac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b69b0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0909_0x0b69a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b69a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1dd890ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0910 | PC: 0x0b6a58 | FDE: 0x1dd8b0 | Size: 76 bytes [_PyTrash_deposit_object]
// Khung tháo gỡ #0910 | Địa chỉ PC: 0x0b6a58 | Địa chỉ FDE: 0x1dd8b0 | Kích thước: 76 bytes
//   0x0b6a58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6a5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6a60: 910043FD  add      x29, sp, #0x10
//   0x0b6a64: B0000A48  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0910_0x0b6a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6a58ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd8b0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0911 | PC: 0x0b6aa4 | FDE: 0x1dd8d0 | Size: 56 bytes [_PyTrash_thread_deposit_object]
// Khung tháo gỡ #0911 | Địa chỉ PC: 0x0b6aa4 | Địa chỉ FDE: 0x1dd8d0 | Kích thước: 56 bytes
//   0x0b6aa4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6aa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6aac: 910043FD  add      x29, sp, #0x10
//   0x0b6ab0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0911_0x0b6aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6aa4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd8d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0912 | PC: 0x0b6adc | FDE: 0x1dd8f0 | Size: 108 bytes [_PyTrash_destroy_chain]
// Khung tháo gỡ #0912 | Địa chỉ PC: 0x0b6adc | Địa chỉ FDE: 0x1dd8f0 | Kích thước: 108 bytes
//   0x0b6adc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6ae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6ae4: 910043FD  add      x29, sp, #0x10
//   0x0b6ae8: B0000A48  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0912_0x0b6adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6adcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd8f0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0913 | PC: 0x0b6b48 | FDE: 0x1dd910 | Size: 96 bytes [_PyTrash_thread_destroy_chain]
// Khung tháo gỡ #0913 | Địa chỉ PC: 0x0b6b48 | Địa chỉ FDE: 0x1dd910 | Kích thước: 96 bytes
//   0x0b6b48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6b4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6b50: 910043FD  add      x29, sp, #0x10
//   0x0b6b54: 97FE8B1B  bl       #0x597c0
static inline uint64_t fde_func_0913_0x0b6b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6b48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd910ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0914 | PC: 0x0b6ba8 | FDE: 0x1dd930 | Size: 92 bytes [_PyTrash_begin]
// Khung tháo gỡ #0914 | Địa chỉ PC: 0x0b6ba8 | Địa chỉ FDE: 0x1dd930 | Kích thước: 92 bytes
//   0x0b6ba8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6bac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6bb0: 910043FD  add      x29, sp, #0x10
//   0x0b6bb4: B940B809  ldr      w9, [x0, #0xb8]
static inline uint64_t fde_func_0914_0x0b6ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6ba8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1dd930ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0915 | PC: 0x0b6c04 | FDE: 0x1dd950 | Size: 36 bytes [_PyTrash_end]
// Khung tháo gỡ #0915 | Địa chỉ PC: 0x0b6c04 | Địa chỉ FDE: 0x1dd950 | Kích thước: 36 bytes
//   0x0b6c04: B940B808  ldr      w8, [x0, #0xb8]
//   0x0b6c08: 51000508  sub      w8, w8, #1
//   0x0b6c0c: 7100011F  cmp      w8, #0
//   0x0b6c10: B900B808  str      w8, [x0, #0xb8]
static inline uint64_t fde_func_0915_0x0b6c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c04ULL ^ (static_cast<uint64_t>(0xb940b808ULL) << 13);
    acc = (acc + a1 + 0x51000508ULL) ^ 0x1dd950ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0916 | PC: 0x0b6c28 | FDE: 0x1dd968 | Size: 20 bytes [_PyTrash_cond]
// Khung tháo gỡ #0916 | Địa chỉ PC: 0x0b6c28 | Địa chỉ FDE: 0x1dd968 | Kích thước: 20 bytes
//   0x0b6c28: F9400408  ldr      x8, [x0, #8]
//   0x0b6c2c: F9401908  ldr      x8, [x8, #0x30]
//   0x0b6c30: EB01011F  cmp      x8, x1
//   0x0b6c34: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_0916_0x0b6c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c28ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9401908ULL) ^ 0x1dd968ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0917 | PC: 0x0b6c3c | FDE: 0x1dd980 | Size: 12 bytes [_Py_Dealloc]
// Khung tháo gỡ #0917 | Địa chỉ PC: 0x0b6c3c | Địa chỉ FDE: 0x1dd980 | Kích thước: 12 bytes
//   0x0b6c3c: F9400408  ldr      x8, [x0, #8]
//   0x0b6c40: F9401901  ldr      x1, [x8, #0x30]
//   0x0b6c44: D61F0020  br       x1
static inline uint64_t fde_func_0917_0x0b6c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c3cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9401901ULL) ^ 0x1dd980ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0918 | PC: 0x0b6c48 | FDE: 0x1dd998 | Size: 16 bytes [PyObject_GET_WEAKREFS_LISTPTR]
// Khung tháo gỡ #0918 | Địa chỉ PC: 0x0b6c48 | Địa chỉ FDE: 0x1dd998 | Kích thước: 16 bytes
//   0x0b6c48: F9400408  ldr      x8, [x0, #8]
//   0x0b6c4c: F9406908  ldr      x8, [x8, #0xd0]
//   0x0b6c50: 8B080000  add      x0, x0, x8
//   0x0b6c54: D65F03C0  ret      
static inline uint64_t fde_func_0918_0x0b6c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c48ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9406908ULL) ^ 0x1dd998ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0919 | PC: 0x0b6c58 | FDE: 0x1dd9b0 | Size: 16 bytes [Py_NewRef]
// Khung tháo gỡ #0919 | Địa chỉ PC: 0x0b6c58 | Địa chỉ FDE: 0x1dd9b0 | Kích thước: 16 bytes
//   0x0b6c58: F9400008  ldr      x8, [x0]
//   0x0b6c5c: 91000508  add      x8, x8, #1
//   0x0b6c60: F9000008  str      x8, [x0]
//   0x0b6c64: D65F03C0  ret      
static inline uint64_t fde_func_0919_0x0b6c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c58ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1dd9b0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0920 | PC: 0x0b6c68 | FDE: 0x1dd9c8 | Size: 20 bytes [Py_XNewRef]
// Khung tháo gỡ #0920 | Địa chỉ PC: 0x0b6c68 | Địa chỉ FDE: 0x1dd9c8 | Kích thước: 20 bytes
//   0x0b6c68: B4000080  cbz      x0, #0xb6c78
//   0x0b6c6c: F9400008  ldr      x8, [x0]
//   0x0b6c70: 91000508  add      x8, x8, #1
//   0x0b6c74: F9000008  str      x8, [x0]
static inline uint64_t fde_func_0920_0x0b6c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c68ULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1dd9c8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0921 | PC: 0x0b6c7c | FDE: 0x1dd9e0 | Size: 12 bytes [Py_Is]
// Khung tháo gỡ #0921 | Địa chỉ PC: 0x0b6c7c | Địa chỉ FDE: 0x1dd9e0 | Kích thước: 12 bytes
//   0x0b6c7c: EB01001F  cmp      x0, x1
//   0x0b6c80: 1A9F17E0  cset     w0, eq
//   0x0b6c84: D65F03C0  ret      
static inline uint64_t fde_func_0921_0x0b6c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c7cULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e0ULL) ^ 0x1dd9e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0922 | PC: 0x0b6c88 | FDE: 0x1dd9f8 | Size: 20 bytes [Py_IsNone]
// Khung tháo gỡ #0922 | Địa chỉ PC: 0x0b6c88 | Địa chỉ FDE: 0x1dd9f8 | Kích thước: 20 bytes
//   0x0b6c88: B0000A48  adrp     x8, #0x1ff000
//   0x0b6c8c: F945F108  ldr      x8, [x8, #0xbe0]
//   0x0b6c90: EB08001F  cmp      x0, x8
//   0x0b6c94: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_0922_0x0b6c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c88ULL ^ (static_cast<uint64_t>(0xb0000a48ULL) << 13);
    acc = (acc + a1 + 0xf945f108ULL) ^ 0x1dd9f8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0923 | PC: 0x0b6c9c | FDE: 0x1dda10 | Size: 20 bytes [Py_IsTrue]
// Khung tháo gỡ #0923 | Địa chỉ PC: 0x0b6c9c | Địa chỉ FDE: 0x1dda10 | Kích thước: 20 bytes
//   0x0b6c9c: B0000A48  adrp     x8, #0x1ff000
//   0x0b6ca0: F9465908  ldr      x8, [x8, #0xcb0]
//   0x0b6ca4: EB08001F  cmp      x0, x8
//   0x0b6ca8: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_0923_0x0b6c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6c9cULL ^ (static_cast<uint64_t>(0xb0000a48ULL) << 13);
    acc = (acc + a1 + 0xf9465908ULL) ^ 0x1dda10ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0924 | PC: 0x0b6cb0 | FDE: 0x1dda28 | Size: 96 bytes [Py_IsFalse]
// Khung tháo gỡ #0924 | Địa chỉ PC: 0x0b6cb0 | Địa chỉ FDE: 0x1dda28 | Kích thước: 96 bytes
//   0x0b6cb0: B0000A48  adrp     x8, #0x1ff000
//   0x0b6cb4: F9456108  ldr      x8, [x8, #0xac0]
//   0x0b6cb8: EB08001F  cmp      x0, x8
//   0x0b6cbc: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_0924_0x0b6cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6cb0ULL ^ (static_cast<uint64_t>(0xb0000a48ULL) << 13);
    acc = (acc + a1 + 0xf9456108ULL) ^ 0x1dda28ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0925 | PC: 0x0b6d10 | FDE: 0x1dda90 | Size: 256 bytes [_PyMem_SetDefaultAllocator]
// Khung tháo gỡ #0925 | Địa chỉ PC: 0x0b6d10 | Địa chỉ FDE: 0x1dda90 | Kích thước: 256 bytes
//   0x0b6d10: AA0103E2  mov      x2, x1
//   0x0b6d14: 2A1F03E1  mov      w1, wzr
//   0x0b6d18: 14000001  b        #0xb6d1c
//   0x0b6d1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0925_0x0b6d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6d10ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e1ULL) ^ 0x1dda90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0926 | PC: 0x0b6e1c | FDE: 0x1ddac8 | Size: 168 bytes [_PyMem_GetAllocatorName]
// Khung tháo gỡ #0926 | Địa chỉ PC: 0x0b6e1c | Địa chỉ FDE: 0x1ddac8 | Kích thước: 168 bytes
//   0x0b6e1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b6e20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6e24: 910043FD  add      x29, sp, #0x10
//   0x0b6e28: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0926_0x0b6e1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6e1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ddac8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0927 | PC: 0x0b6ec4 | FDE: 0x1ddae8 | Size: 256 bytes [_PyMem_SetupAllocators]
// Khung tháo gỡ #0927 | Địa chỉ PC: 0x0b6ec4 | Địa chỉ FDE: 0x1ddae8 | Kích thước: 256 bytes
//   0x0b6ec4: 7100101F  cmp      w0, #4
//   0x0b6ec8: 540003C8  b.hi     #0xb6f40
//   0x0b6ecc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b6ed0: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0927_0x0b6ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6ec4ULL ^ (static_cast<uint64_t>(0x7100101fULL) << 13);
    acc = (acc + a1 + 0x540003c8ULL) ^ 0x1ddae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0928 | PC: 0x0b70fc | FDE: 0x1ddb68 | Size: 88 bytes [PyMem_SetAllocator]
// Khung tháo gỡ #0928 | Địa chỉ PC: 0x0b70fc | Địa chỉ FDE: 0x1ddb68 | Kích thước: 88 bytes
//   0x0b70fc: 7100081F  cmp      w0, #2
//   0x0b7100: 54000120  b.eq     #0xb7124
//   0x0b7104: 7100041F  cmp      w0, #1
//   0x0b7108: 54000180  b.eq     #0xb7138
static inline uint64_t fde_func_0928_0x0b70fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b70fcULL ^ (static_cast<uint64_t>(0x7100081fULL) << 13);
    acc = (acc + a1 + 0x54000120ULL) ^ 0x1ddb68ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0929 | PC: 0x0b7154 | FDE: 0x1ddb80 | Size: 256 bytes [PyMem_SetupDebugHooks]
// Khung tháo gỡ #0929 | Địa chỉ PC: 0x0b7154 | Địa chỉ FDE: 0x1ddb80 | Kích thước: 256 bytes
//   0x0b7154: 90000AC8  adrp     x8, #0x20f000
//   0x0b7158: F944A109  ldr      x9, [x8, #0x940]
//   0x0b715c: 90000008  adrp     x8, #0xb7000
//   0x0b7160: 910E0108  add      x8, x8, #0x380
static inline uint64_t fde_func_0929_0x0b7154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7154ULL ^ (static_cast<uint64_t>(0x90000ac8ULL) << 13);
    acc = (acc + a1 + 0xf944a109ULL) ^ 0x1ddb80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0930 | PC: 0x0b7258 | FDE: 0x1ddb98 | Size: 256 bytes [_PyMem_GetCurrentAllocatorName]
// Khung tháo gỡ #0930 | Địa chỉ PC: 0x0b7258 | Địa chỉ FDE: 0x1ddb98 | Kích thước: 256 bytes
//   0x0b7258: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b725c: 910003FD  mov      x29, sp
//   0x0b7260: 90000AC0  adrp     x0, #0x20f000
//   0x0b7264: F0000A01  adrp     x1, #0x1fa000
static inline uint64_t fde_func_0930_0x0b7258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7258ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ddb98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0931 | PC: 0x0b7884 | FDE: 0x1ddcc8 | Size: 88 bytes [PyMem_GetAllocator]
// Khung tháo gỡ #0931 | Địa chỉ PC: 0x0b7884 | Địa chỉ FDE: 0x1ddcc8 | Kích thước: 88 bytes
//   0x0b7884: 7100081F  cmp      w0, #2
//   0x0b7888: 540000E0  b.eq     #0xb78a4
//   0x0b788c: 7100041F  cmp      w0, #1
//   0x0b7890: 54000100  b.eq     #0xb78b0
static inline uint64_t fde_func_0931_0x0b7884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7884ULL ^ (static_cast<uint64_t>(0x7100081fULL) << 13);
    acc = (acc + a1 + 0x540000e0ULL) ^ 0x1ddcc8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0932 | PC: 0x0b78dc | FDE: 0x1ddce0 | Size: 28 bytes [PyObject_GetArenaAllocator]
// Khung tháo gỡ #0932 | Địa chỉ PC: 0x0b78dc | Địa chỉ FDE: 0x1ddce0 | Kích thước: 28 bytes
//   0x0b78dc: 90000AC8  adrp     x8, #0x20f000
//   0x0b78e0: 91290108  add      x8, x8, #0xa40
//   0x0b78e4: F9400909  ldr      x9, [x8, #0x10]
//   0x0b78e8: 3DC00100  ldr      q0, [x8]
static inline uint64_t fde_func_0932_0x0b78dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b78dcULL ^ (static_cast<uint64_t>(0x90000ac8ULL) << 13);
    acc = (acc + a1 + 0x91290108ULL) ^ 0x1ddce0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0933 | PC: 0x0b78f8 | FDE: 0x1ddcf8 | Size: 28 bytes [PyObject_SetArenaAllocator]
// Khung tháo gỡ #0933 | Địa chỉ PC: 0x0b78f8 | Địa chỉ FDE: 0x1ddcf8 | Kích thước: 28 bytes
//   0x0b78f8: F9400808  ldr      x8, [x0, #0x10]
//   0x0b78fc: 3DC00000  ldr      q0, [x0]
//   0x0b7900: 90000AC9  adrp     x9, #0x20f000
//   0x0b7904: 91290129  add      x9, x9, #0xa40
static inline uint64_t fde_func_0933_0x0b78f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b78f8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x3dc00000ULL) ^ 0x1ddcf8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0934 | PC: 0x0b7914 | FDE: 0x1ddd10 | Size: 32 bytes [PyMem_RawMalloc]
// Khung tháo gỡ #0934 | Địa chỉ PC: 0x0b7914 | Địa chỉ FDE: 0x1ddd10 | Kích thước: 32 bytes
//   0x0b7914: B7F800C0  tbnz     x0, #0x3f, #0xb792c
//   0x0b7918: 90000AC8  adrp     x8, #0x20f000
//   0x0b791c: 9124E108  add      x8, x8, #0x938
//   0x0b7920: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_0934_0x0b7914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7914ULL ^ (static_cast<uint64_t>(0xb7f800c0ULL) << 13);
    acc = (acc + a1 + 0x90000ac8ULL) ^ 0x1ddd10ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0935 | PC: 0x0b7934 | FDE: 0x1ddd28 | Size: 56 bytes [PyMem_RawCalloc]
// Khung tháo gỡ #0935 | Địa chỉ PC: 0x0b7934 | Địa chỉ FDE: 0x1ddd28 | Kích thước: 56 bytes
//   0x0b7934: AA0103E2  mov      x2, x1
//   0x0b7938: AA0003E1  mov      x1, x0
//   0x0b793c: B40000E2  cbz      x2, #0xb7958
//   0x0b7940: 92F00008  mov      x8, #0x7fffffffffffffff
static inline uint64_t fde_func_0935_0x0b7934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7934ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x1ddd28ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0936 | PC: 0x0b796c | FDE: 0x1ddd40 | Size: 40 bytes [PyMem_RawRealloc]
// Khung tháo gỡ #0936 | Địa chỉ PC: 0x0b796c | Địa chỉ FDE: 0x1ddd40 | Kích thước: 40 bytes
//   0x0b796c: AA0103E2  mov      x2, x1
//   0x0b7970: B7F800E1  tbnz     x1, #0x3f, #0xb798c
//   0x0b7974: 90000AC8  adrp     x8, #0x20f000
//   0x0b7978: 9124E108  add      x8, x8, #0x938
static inline uint64_t fde_func_0936_0x0b796c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b796cULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xb7f800e1ULL) ^ 0x1ddd40ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0937 | PC: 0x0b7994 | FDE: 0x1ddd58 | Size: 28 bytes [PyMem_RawFree]
// Khung tháo gỡ #0937 | Địa chỉ PC: 0x0b7994 | Địa chỉ FDE: 0x1ddd58 | Kích thước: 28 bytes
//   0x0b7994: 90000AC8  adrp     x8, #0x20f000
//   0x0b7998: 9124E108  add      x8, x8, #0x938
//   0x0b799c: F9401102  ldr      x2, [x8, #0x20]
//   0x0b79a0: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0937_0x0b7994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7994ULL ^ (static_cast<uint64_t>(0x90000ac8ULL) << 13);
    acc = (acc + a1 + 0x9124e108ULL) ^ 0x1ddd58ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0938 | PC: 0x0b79b0 | FDE: 0x1ddd70 | Size: 32 bytes [PyMem_Malloc]
// Khung tháo gỡ #0938 | Địa chỉ PC: 0x0b79b0 | Địa chỉ FDE: 0x1ddd70 | Kích thước: 32 bytes
//   0x0b79b0: B7F800C0  tbnz     x0, #0x3f, #0xb79c8
//   0x0b79b4: 90000AC8  adrp     x8, #0x20f000
//   0x0b79b8: 91258108  add      x8, x8, #0x960
//   0x0b79bc: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_0938_0x0b79b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b79b0ULL ^ (static_cast<uint64_t>(0xb7f800c0ULL) << 13);
    acc = (acc + a1 + 0x90000ac8ULL) ^ 0x1ddd70ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0939 | PC: 0x0b79d0 | FDE: 0x1ddd88 | Size: 56 bytes [PyMem_Calloc]
// Khung tháo gỡ #0939 | Địa chỉ PC: 0x0b79d0 | Địa chỉ FDE: 0x1ddd88 | Kích thước: 56 bytes
//   0x0b79d0: AA0103E2  mov      x2, x1
//   0x0b79d4: AA0003E1  mov      x1, x0
//   0x0b79d8: B40000E2  cbz      x2, #0xb79f4
//   0x0b79dc: 92F00008  mov      x8, #0x7fffffffffffffff
static inline uint64_t fde_func_0939_0x0b79d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b79d0ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x1ddd88ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0940 | PC: 0x0b7a08 | FDE: 0x1ddda0 | Size: 40 bytes [PyMem_Realloc]
// Khung tháo gỡ #0940 | Địa chỉ PC: 0x0b7a08 | Địa chỉ FDE: 0x1ddda0 | Kích thước: 40 bytes
//   0x0b7a08: AA0103E2  mov      x2, x1
//   0x0b7a0c: B7F800E1  tbnz     x1, #0x3f, #0xb7a28
//   0x0b7a10: 90000AC8  adrp     x8, #0x20f000
//   0x0b7a14: 91258108  add      x8, x8, #0x960
static inline uint64_t fde_func_0940_0x0b7a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7a08ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xb7f800e1ULL) ^ 0x1ddda0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0941 | PC: 0x0b7a30 | FDE: 0x1dddb8 | Size: 28 bytes [PyMem_Free]
// Khung tháo gỡ #0941 | Địa chỉ PC: 0x0b7a30 | Địa chỉ FDE: 0x1dddb8 | Kích thước: 28 bytes
//   0x0b7a30: 90000AC8  adrp     x8, #0x20f000
//   0x0b7a34: 91258108  add      x8, x8, #0x960
//   0x0b7a38: F9401102  ldr      x2, [x8, #0x20]
//   0x0b7a3c: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0941_0x0b7a30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7a30ULL ^ (static_cast<uint64_t>(0x90000ac8ULL) << 13);
    acc = (acc + a1 + 0x91258108ULL) ^ 0x1dddb8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0942 | PC: 0x0b7a4c | FDE: 0x1dddd0 | Size: 120 bytes [_PyMem_RawWcsdup]
// Khung tháo gỡ #0942 | Địa chỉ PC: 0x0b7a4c | Địa chỉ FDE: 0x1dddd0 | Kích thước: 120 bytes
//   0x0b7a4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b7a50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b7a54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b7a58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0942_0x0b7a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7a4cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dddd0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0943 | PC: 0x0b7ac4 | FDE: 0x1dddf0 | Size: 104 bytes [_PyMem_RawStrdup]
// Khung tháo gỡ #0943 | Địa chỉ PC: 0x0b7ac4 | Địa chỉ FDE: 0x1dddf0 | Kích thước: 104 bytes
//   0x0b7ac4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b7ac8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b7acc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b7ad0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0943_0x0b7ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7ac4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dddf0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0944 | PC: 0x0b7b2c | FDE: 0x1dde10 | Size: 104 bytes [_PyMem_Strdup]
// Khung tháo gỡ #0944 | Địa chỉ PC: 0x0b7b2c | Địa chỉ FDE: 0x1dde10 | Kích thước: 104 bytes
//   0x0b7b2c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b7b30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b7b34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b7b38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0944_0x0b7b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7b2cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dde10ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0945 | PC: 0x0b7b94 | FDE: 0x1dde30 | Size: 32 bytes [PyObject_Malloc]
// Khung tháo gỡ #0945 | Địa chỉ PC: 0x0b7b94 | Địa chỉ FDE: 0x1dde30 | Kích thước: 32 bytes
//   0x0b7b94: B7F800C0  tbnz     x0, #0x3f, #0xb7bac
//   0x0b7b98: 90000AC8  adrp     x8, #0x20f000
//   0x0b7b9c: 91262108  add      x8, x8, #0x988
//   0x0b7ba0: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_0945_0x0b7b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7b94ULL ^ (static_cast<uint64_t>(0xb7f800c0ULL) << 13);
    acc = (acc + a1 + 0x90000ac8ULL) ^ 0x1dde30ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0946 | PC: 0x0b7bb4 | FDE: 0x1dde48 | Size: 56 bytes [PyObject_Calloc]
// Khung tháo gỡ #0946 | Địa chỉ PC: 0x0b7bb4 | Địa chỉ FDE: 0x1dde48 | Kích thước: 56 bytes
//   0x0b7bb4: AA0103E2  mov      x2, x1
//   0x0b7bb8: AA0003E1  mov      x1, x0
//   0x0b7bbc: B40000E2  cbz      x2, #0xb7bd8
//   0x0b7bc0: 92F00008  mov      x8, #0x7fffffffffffffff
static inline uint64_t fde_func_0946_0x0b7bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7bb4ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x1dde48ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0947 | PC: 0x0b7bec | FDE: 0x1dde60 | Size: 40 bytes [PyObject_Realloc]
// Khung tháo gỡ #0947 | Địa chỉ PC: 0x0b7bec | Địa chỉ FDE: 0x1dde60 | Kích thước: 40 bytes
//   0x0b7bec: AA0103E2  mov      x2, x1
//   0x0b7bf0: B7F800E1  tbnz     x1, #0x3f, #0xb7c0c
//   0x0b7bf4: 90000AC8  adrp     x8, #0x20f000
//   0x0b7bf8: 91262108  add      x8, x8, #0x988
static inline uint64_t fde_func_0947_0x0b7bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7becULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xb7f800e1ULL) ^ 0x1dde60ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0948 | PC: 0x0b7c14 | FDE: 0x1dde78 | Size: 28 bytes [PyObject_Free]
// Khung tháo gỡ #0948 | Địa chỉ PC: 0x0b7c14 | Địa chỉ FDE: 0x1dde78 | Kích thước: 28 bytes
//   0x0b7c14: 90000AC8  adrp     x8, #0x20f000
//   0x0b7c18: 91262108  add      x8, x8, #0x988
//   0x0b7c1c: F9401102  ldr      x2, [x8, #0x20]
//   0x0b7c20: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0948_0x0b7c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7c14ULL ^ (static_cast<uint64_t>(0x90000ac8ULL) << 13);
    acc = (acc + a1 + 0x91262108ULL) ^ 0x1dde78ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0949 | PC: 0x0b7c30 | FDE: 0x1dde90 | Size: 8 bytes [_Py_GetAllocatedBlocks]
// Khung tháo gỡ #0949 | Địa chỉ PC: 0x0b7c30 | Địa chỉ FDE: 0x1dde90 | Kích thước: 8 bytes
//   0x0b7c30: AA1F03E0  mov      x0, xzr
//   0x0b7c34: D65F03C0  ret      
static inline uint64_t fde_func_0949_0x0b7c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7c30ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1dde90ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0950 | PC: 0x0b7c38 | FDE: 0x1ddea8 | Size: 256 bytes [_PyDebugAllocatorStats]
// Khung tháo gỡ #0950 | Địa chỉ PC: 0x0b7c38 | Địa chỉ FDE: 0x1ddea8 | Kích thước: 256 bytes
//   0x0b7c38: D106C3FF  sub      sp, sp, #0x1b0
//   0x0b7c3c: A9175FFC  stp      x28, x23, [sp, #0x170]
//   0x0b7c40: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x0b7c44: A9194FF4  stp      x20, x19, [sp, #0x190]
static inline uint64_t fde_func_0950_0x0b7c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7c38ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9175ffcULL) ^ 0x1ddea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0951 | PC: 0x0b82a4 | FDE: 0x1ddf70 | Size: 120 bytes [PyPickleBuffer_FromObject]
// Khung tháo gỡ #0951 | Địa chỉ PC: 0x0b82a4 | Địa chỉ FDE: 0x1ddf70 | Kích thước: 120 bytes
//   0x0b82a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b82a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b82ac: 910043FD  add      x29, sp, #0x10
//   0x0b82b0: F0000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0951_0x0b82a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b82a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ddf70ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0952 | PC: 0x0b831c | FDE: 0x1ddf90 | Size: 116 bytes [PyPickleBuffer_GetBuffer]
// Khung tháo gỡ #0952 | Địa chỉ PC: 0x0b831c | Địa chỉ FDE: 0x1ddf90 | Kích thước: 116 bytes
//   0x0b831c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b8320: 910003FD  mov      x29, sp
//   0x0b8324: F0000A29  adrp     x9, #0x1ff000
//   0x0b8328: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0952_0x0b831c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b831cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ddf90ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0953 | PC: 0x0b8390 | FDE: 0x1ddfb0 | Size: 256 bytes [PyPickleBuffer_Release]
// Khung tháo gỡ #0953 | Địa chỉ PC: 0x0b8390 | Địa chỉ FDE: 0x1ddfb0 | Kích thước: 256 bytes
//   0x0b8390: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b8394: 910003FD  mov      x29, sp
//   0x0b8398: F0000A29  adrp     x9, #0x1ff000
//   0x0b839c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0953_0x0b8390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8390ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ddfb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0954 | PC: 0x0badf8 | FDE: 0x1de688 | Size: 144 bytes [PySet_New]
// Khung tháo gỡ #0954 | Địa chỉ PC: 0x0badf8 | Địa chỉ FDE: 0x1de688 | Kích thước: 144 bytes
//   0x0badf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0badfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bae00: 910043FD  add      x29, sp, #0x10
//   0x0bae04: B0000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0954_0x0badf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0badf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de688ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0955 | PC: 0x0bae88 | FDE: 0x1de6a8 | Size: 144 bytes [PyFrozenSet_New]
// Khung tháo gỡ #0955 | Địa chỉ PC: 0x0bae88 | Địa chỉ FDE: 0x1de6a8 | Kích thước: 144 bytes
//   0x0bae88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bae8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bae90: 910043FD  add      x29, sp, #0x10
//   0x0bae94: B0000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0955_0x0bae88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bae88ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de6a8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0956 | PC: 0x0baf18 | FDE: 0x1de6c8 | Size: 128 bytes [PySet_Size]
// Khung tháo gỡ #0956 | Địa chỉ PC: 0x0baf18 | Địa chỉ FDE: 0x1de6c8 | Kích thước: 128 bytes
//   0x0baf18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0baf1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0baf20: 910043FD  add      x29, sp, #0x10
//   0x0baf24: B0000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0956_0x0baf18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baf18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de6c8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0957 | PC: 0x0baf98 | FDE: 0x1de6e8 | Size: 100 bytes [PySet_Clear]
// Khung tháo gỡ #0957 | Địa chỉ PC: 0x0baf98 | Địa chỉ FDE: 0x1de6e8 | Kích thước: 100 bytes
//   0x0baf98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0baf9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bafa0: 910043FD  add      x29, sp, #0x10
//   0x0bafa4: B0000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0957_0x0baf98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baf98ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de6e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0958 | PC: 0x0baffc | FDE: 0x1de708 | Size: 212 bytes [PySet_Contains]
// Khung tháo gỡ #0958 | Địa chỉ PC: 0x0baffc | Địa chỉ FDE: 0x1de708 | Kích thước: 212 bytes
//   0x0baffc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb000: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb004: 910043FD  add      x29, sp, #0x10
//   0x0bb008: 90000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0958_0x0baffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baffcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de708ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0959 | PC: 0x0bb0d0 | FDE: 0x1de728 | Size: 228 bytes [PySet_Discard]
// Khung tháo gỡ #0959 | Địa chỉ PC: 0x0bb0d0 | Địa chỉ FDE: 0x1de728 | Kích thước: 228 bytes
//   0x0bb0d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb0d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb0d8: 910043FD  add      x29, sp, #0x10
//   0x0bb0dc: 90000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0959_0x0bb0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb0d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de728ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0960 | PC: 0x0bb1b4 | FDE: 0x1de748 | Size: 212 bytes [PySet_Add]
// Khung tháo gỡ #0960 | Địa chỉ PC: 0x0bb1b4 | Địa chỉ FDE: 0x1de748 | Kích thước: 212 bytes
//   0x0bb1b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb1b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb1bc: 910043FD  add      x29, sp, #0x10
//   0x0bb1c0: 90000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0960_0x0bb1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb1b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de748ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0961 | PC: 0x0bb288 | FDE: 0x1de768 | Size: 256 bytes [_PySet_NextEntry]
// Khung tháo gỡ #0961 | Địa chỉ PC: 0x0bb288 | Địa chỉ FDE: 0x1de768 | Kích thước: 256 bytes
//   0x0bb288: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bb28c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bb290: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bb294: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0961_0x0bb288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb288ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1de768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0962 | PC: 0x0bb38c | FDE: 0x1de790 | Size: 256 bytes [PySet_Pop]
// Khung tháo gỡ #0962 | Địa chỉ PC: 0x0bb38c | Địa chỉ FDE: 0x1de790 | Kích thước: 256 bytes
//   0x0bb38c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bb390: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb394: 910043FD  add      x29, sp, #0x10
//   0x0bb398: 90000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0962_0x0bb38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb38cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0963 | PC: 0x0bb518 | FDE: 0x1de7d0 | Size: 256 bytes [_PySet_Update]
// Khung tháo gỡ #0963 | Địa chỉ PC: 0x0bb518 | Địa chỉ FDE: 0x1de7d0 | Kích thước: 256 bytes
//   0x0bb518: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb51c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb520: 910043FD  add      x29, sp, #0x10
//   0x0bb524: 90000A28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0963_0x0bb518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb518ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1de7d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0964 | PC: 0x0beaa4 | FDE: 0x1dee20 | Size: 24 bytes [_PySlice_Fini]
// Khung tháo gỡ #0964 | Địa chỉ PC: 0x0beaa4 | Địa chỉ FDE: 0x1dee20 | Kích thước: 24 bytes
//   0x0beaa4: AA0003E8  mov      x8, x0
//   0x0beaa8: F9538800  ldr      x0, [x0, #0x2710]
//   0x0beaac: B4000060  cbz      x0, #0xbeab8
//   0x0beab0: F913891F  str      xzr, [x8, #0x2710]
static inline uint64_t fde_func_0964_0x0beaa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beaa4ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9538800ULL) ^ 0x1dee20ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0965 | PC: 0x0beabc | FDE: 0x1dee38 | Size: 184 bytes [PySlice_New]
// Khung tháo gỡ #0965 | Địa chỉ PC: 0x0beabc | Địa chỉ FDE: 0x1dee38 | Kích thước: 184 bytes
//   0x0beabc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0beac0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0beac4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0beac8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0965_0x0beabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beabcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dee38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0966 | PC: 0x0beb74 | FDE: 0x1dee60 | Size: 256 bytes [_PySlice_FromIndices]
// Khung tháo gỡ #0966 | Địa chỉ PC: 0x0beb74 | Địa chỉ FDE: 0x1dee60 | Kích thước: 256 bytes
//   0x0beb74: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0beb78: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0beb7c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0beb80: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0966_0x0beb74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beb74ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dee60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0967 | PC: 0x0bec80 | FDE: 0x1dee80 | Size: 256 bytes [PySlice_GetIndices]
// Khung tháo gỡ #0967 | Địa chỉ PC: 0x0bec80 | Địa chỉ FDE: 0x1dee80 | Kích thước: 256 bytes
//   0x0bec80: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0bec84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bec88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bec8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0967_0x0bec80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bec80ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1dee80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0968 | PC: 0x0bed98 | FDE: 0x1deea8 | Size: 248 bytes [PySlice_Unpack]
// Khung tháo gỡ #0968 | Địa chỉ PC: 0x0bed98 | Địa chỉ FDE: 0x1deea8 | Kích thước: 248 bytes
//   0x0bed98: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bed9c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0beda0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0beda4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0968_0x0bed98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bed98ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1deea8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0969 | PC: 0x0bee90 | FDE: 0x1deed0 | Size: 204 bytes [PySlice_AdjustIndices]
// Khung tháo gỡ #0969 | Địa chỉ PC: 0x0bee90 | Địa chỉ FDE: 0x1deed0 | Kích thước: 204 bytes
//   0x0bee90: F9400028  ldr      x8, [x1]
//   0x0bee94: 937FFC69  asr      x9, x3, #0x3f
//   0x0bee98: B7F801E8  tbnz     x8, #0x3f, #0xbeed4
//   0x0bee9c: EB00011F  cmp      x8, x0
static inline uint64_t fde_func_0969_0x0bee90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bee90ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x937ffc69ULL) ^ 0x1deed0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0970 | PC: 0x0bef5c | FDE: 0x1deee8 | Size: 256 bytes [PySlice_GetIndicesEx]
// Khung tháo gỡ #0970 | Địa chỉ PC: 0x0bef5c | Địa chỉ FDE: 0x1deee8 | Kích thước: 256 bytes
//   0x0bef5c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bef60: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bef64: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bef68: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0970_0x0bef5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bef5cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1deee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0971 | PC: 0x0bf080 | FDE: 0x1def10 | Size: 256 bytes [_PySlice_GetLongIndices]
// Khung tháo gỡ #0971 | Địa chỉ PC: 0x0bf080 | Địa chỉ FDE: 0x1def10 | Kích thước: 256 bytes
//   0x0bf080: D10203FF  sub      sp, sp, #0x80
//   0x0bf084: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0bf088: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0bf08c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0971_0x0bf080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf080ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1def10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0972 | PC: 0x0bfa28 | FDE: 0x1df030 | Size: 256 bytes [PyStructSequence_New]
// Khung tháo gỡ #0972 | Địa chỉ PC: 0x0bfa28 | Địa chỉ FDE: 0x1df030 | Kích thước: 256 bytes
//   0x0bfa28: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bfa2c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bfa30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bfa34: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0972_0x0bfa28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfa28ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1df030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0973 | PC: 0x0bfb48 | FDE: 0x1df058 | Size: 12 bytes [PyStructSequence_SetItem]
// Khung tháo gỡ #0973 | Địa chỉ PC: 0x0bfb48 | Địa chỉ FDE: 0x1df058 | Kích thước: 12 bytes
//   0x0bfb48: 8B010C08  add      x8, x0, x1, lsl #3
//   0x0bfb4c: F9000D02  str      x2, [x8, #0x18]
//   0x0bfb50: D65F03C0  ret      
static inline uint64_t fde_func_0973_0x0bfb48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfb48ULL ^ (static_cast<uint64_t>(0x8b010c08ULL) << 13);
    acc = (acc + a1 + 0xf9000d02ULL) ^ 0x1df058ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0974 | PC: 0x0bfb54 | FDE: 0x1df070 | Size: 12 bytes [PyStructSequence_GetItem]
// Khung tháo gỡ #0974 | Địa chỉ PC: 0x0bfb54 | Địa chỉ FDE: 0x1df070 | Kích thước: 12 bytes
//   0x0bfb54: 8B010C08  add      x8, x0, x1, lsl #3
//   0x0bfb58: F9400D00  ldr      x0, [x8, #0x18]
//   0x0bfb5c: D65F03C0  ret      
static inline uint64_t fde_func_0974_0x0bfb54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfb54ULL ^ (static_cast<uint64_t>(0x8b010c08ULL) << 13);
    acc = (acc + a1 + 0xf9400d00ULL) ^ 0x1df070ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0975 | PC: 0x0bfb60 | FDE: 0x1df088 | Size: 256 bytes [_PyStructSequence_InitType]
// Khung tháo gỡ #0975 | Địa chỉ PC: 0x0bfb60 | Địa chỉ FDE: 0x1df088 | Kích thước: 256 bytes
//   0x0bfb60: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0bfb64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bfb68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bfb6c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0975_0x0bfb60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfb60ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1df088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0976 | PC: 0x0c0770 | FDE: 0x1df188 | Size: 8 bytes [PyStructSequence_InitType2]
// Khung tháo gỡ #0976 | Địa chỉ PC: 0x0c0770 | Địa chỉ FDE: 0x1df188 | Kích thước: 8 bytes
//   0x0c0770: AA1F03E2  mov      x2, xzr
//   0x0c0774: 17FE61DF  b        #0x58ef0
static inline uint64_t fde_func_0976_0x0c0770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0770ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17fe61dfULL) ^ 0x1df188ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0977 | PC: 0x0c0778 | FDE: 0x1df1a0 | Size: 8 bytes [PyStructSequence_InitType]
// Khung tháo gỡ #0977 | Địa chỉ PC: 0x0c0778 | Địa chỉ FDE: 0x1df1a0 | Kích thước: 8 bytes
//   0x0c0778: AA1F03E2  mov      x2, xzr
//   0x0c077c: 17FE61DD  b        #0x58ef0
static inline uint64_t fde_func_0977_0x0c0778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0778ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17fe61ddULL) ^ 0x1df1a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0978 | PC: 0x0c0780 | FDE: 0x1df1b8 | Size: 256 bytes [PyStructSequence_NewType]
// Khung tháo gỡ #0978 | Địa chỉ PC: 0x0c0780 | Địa chỉ FDE: 0x1df1b8 | Kích thước: 256 bytes
//   0x0c0780: D103C3FF  sub      sp, sp, #0xf0
//   0x0c0784: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x0c0788: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x0c078c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_0978_0x0c0780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0780ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90b5ff8ULL) ^ 0x1df1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0979 | PC: 0x0c09cc | FDE: 0x1df1e0 | Size: 256 bytes [_PyStructSequence_Init]
// Khung tháo gỡ #0979 | Địa chỉ PC: 0x0c09cc | Địa chỉ FDE: 0x1df1e0 | Kích thước: 256 bytes
//   0x0c09cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c09d0: 910003FD  mov      x29, sp
//   0x0c09d4: B0000A80  adrp     x0, #0x211000
//   0x0c09d8: 911DE000  add      x0, x0, #0x778
static inline uint64_t fde_func_0979_0x0c09cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c09ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1df1e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0980 | PC: 0x0c0c0c | FDE: 0x1df228 | Size: 212 bytes [_PyTuple_DebugMallocStats]
// Khung tháo gỡ #0980 | Địa chỉ PC: 0x0c0c0c | Địa chỉ FDE: 0x1df228 | Kích thước: 212 bytes
//   0x0c0c0c: D10383FF  sub      sp, sp, #0xe0
//   0x0c0c10: F9004BF9  str      x25, [sp, #0x90]
//   0x0c0c14: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x0c0c18: A90B57F6  stp      x22, x21, [sp, #0xb0]
static inline uint64_t fde_func_0980_0x0c0c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0c0cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf9ULL) ^ 0x1df228ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0981 | PC: 0x0c0ce0 | FDE: 0x1df250 | Size: 256 bytes [PyTuple_New]
// Khung tháo gỡ #0981 | Địa chỉ PC: 0x0c0ce0 | Địa chỉ FDE: 0x1df250 | Kích thước: 256 bytes
//   0x0c0ce0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c0ce4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c0ce8: 910043FD  add      x29, sp, #0x10
//   0x0c0cec: B4000180  cbz      x0, #0xc0d1c
static inline uint64_t fde_func_0981_0x0c0ce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0ce0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0982 | PC: 0x0c0e10 | FDE: 0x1df290 | Size: 60 bytes [PyTuple_Size]
// Khung tháo gỡ #0982 | Địa chỉ PC: 0x0c0e10 | Địa chỉ FDE: 0x1df290 | Kích thước: 60 bytes
//   0x0c0e10: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c0e14: 910003FD  mov      x29, sp
//   0x0c0e18: F9400408  ldr      x8, [x0, #8]
//   0x0c0e1c: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0982_0x0c0e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0e10ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1df290ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0983 | PC: 0x0c0e4c | FDE: 0x1df2b0 | Size: 108 bytes [PyTuple_GetItem]
// Khung tháo gỡ #0983 | Địa chỉ PC: 0x0c0e4c | Địa chỉ FDE: 0x1df2b0 | Kích thước: 108 bytes
//   0x0c0e4c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c0e50: 910003FD  mov      x29, sp
//   0x0c0e54: F9400408  ldr      x8, [x0, #8]
//   0x0c0e58: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0983_0x0c0e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0e4cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1df2b0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0984 | PC: 0x0c0eb8 | FDE: 0x1df2d0 | Size: 208 bytes [PyTuple_SetItem]
// Khung tháo gỡ #0984 | Địa chỉ PC: 0x0c0eb8 | Địa chỉ FDE: 0x1df2d0 | Kích thước: 208 bytes
//   0x0c0eb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c0ebc: 910003FD  mov      x29, sp
//   0x0c0ec0: F9400408  ldr      x8, [x0, #8]
//   0x0c0ec4: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0984_0x0c0eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0eb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1df2d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0985 | PC: 0x0c0f88 | FDE: 0x1df2f0 | Size: 144 bytes [_PyTuple_MaybeUntrack]
// Khung tháo gỡ #0985 | Địa chỉ PC: 0x0c0f88 | Địa chỉ FDE: 0x1df2f0 | Kích thước: 144 bytes
//   0x0c0f88: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c0f8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c0f90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c0f94: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0985_0x0c0f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0f88ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df2f0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0986 | PC: 0x0c1018 | FDE: 0x1df318 | Size: 256 bytes [PyTuple_Pack]
// Khung tháo gỡ #0986 | Địa chỉ PC: 0x0c1018 | Địa chỉ FDE: 0x1df318 | Kích thước: 256 bytes
//   0x0c1018: D10403FF  sub      sp, sp, #0x100
//   0x0c101c: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x0c1020: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x0c1024: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_0986_0x0c1018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1018ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90e4ff4ULL) ^ 0x1df318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0987 | PC: 0x0c1130 | FDE: 0x1df338 | Size: 128 bytes [_PyTuple_FromArray]
// Khung tháo gỡ #0987 | Địa chỉ PC: 0x0c1130 | Địa chỉ FDE: 0x1df338 | Kích thước: 128 bytes
//   0x0c1130: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c1134: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c1138: 910043FD  add      x29, sp, #0x10
//   0x0c113c: B4000221  cbz      x1, #0xc1180
static inline uint64_t fde_func_0987_0x0c1130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1130ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df338ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0988 | PC: 0x0c11b0 | FDE: 0x1df358 | Size: 256 bytes [PyTuple_GetSlice]
// Khung tháo gỡ #0988 | Địa chỉ PC: 0x0c11b0 | Địa chỉ FDE: 0x1df358 | Kích thước: 256 bytes
//   0x0c11b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c11b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c11b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c11bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0988_0x0c11b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c11b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0989 | PC: 0x0c19d0 | FDE: 0x1df4a8 | Size: 256 bytes [_PyTuple_Resize]
// Khung tháo gỡ #0989 | Địa chỉ PC: 0x0c19d0 | Địa chỉ FDE: 0x1df4a8 | Kích thước: 256 bytes
//   0x0c19d0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c19d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c19d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c19dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0989_0x0c19d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c19d0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1df4a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x0c1b94 | FDE: 0x1df4d0 | Size: 104 bytes [_PyTuple_ClearFreeList]
// Khung tháo gỡ #0990 | Địa chỉ PC: 0x0c1b94 | Địa chỉ FDE: 0x1df4d0 | Kích thước: 104 bytes
//   0x0c1b94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c1b98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c1b9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c1ba0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0990_0x0c1b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1b94ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df4d0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0991 | PC: 0x0c1bfc | FDE: 0x1df4f0 | Size: 132 bytes [_PyTuple_Init]
// Khung tháo gỡ #0991 | Địa chỉ PC: 0x0c1bfc | Địa chỉ FDE: 0x1df4f0 | Kích thước: 132 bytes
//   0x0c1bfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c1c00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c1c04: 910043FD  add      x29, sp, #0x10
//   0x0c1c08: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0991_0x0c1bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1bfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df4f0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0992 | PC: 0x0c1c80 | FDE: 0x1df510 | Size: 256 bytes [_PyTuple_Fini]
// Khung tháo gỡ #0992 | Địa chỉ PC: 0x0c1c80 | Địa chỉ FDE: 0x1df510 | Kích thước: 256 bytes
//   0x0c1c80: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c1c84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c1c88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c1c8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0992_0x0c1c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1c80ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0993 | PC: 0x0c27b4 | FDE: 0x1df740 | Size: 96 bytes [PyType_InitLock]
// Khung tháo gỡ #0993 | Địa chỉ PC: 0x0c27b4 | Địa chỉ FDE: 0x1df740 | Kích thước: 96 bytes
//   0x0c27b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c27b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c27bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c27c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0993_0x0c27b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c27b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df740ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0994 | PC: 0x0c2814 | FDE: 0x1df760 | Size: 256 bytes [_PyType_CheckConsistency]
// Khung tháo gỡ #0994 | Địa chỉ PC: 0x0c2814 | Địa chỉ FDE: 0x1df760 | Kích thước: 256 bytes
//   0x0c2814: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2818: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c281c: 910043FD  add      x29, sp, #0x10
//   0x0c2820: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0994_0x0c2814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2814ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0995 | PC: 0x0c296c | FDE: 0x1df780 | Size: 108 bytes [_PyType_GetDocFromInternalDoc]
// Khung tháo gỡ #0995 | Địa chỉ PC: 0x0c296c | Địa chỉ FDE: 0x1df780 | Kích thước: 108 bytes
//   0x0c296c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c2970: 910003FD  mov      x29, sp
//   0x0c2974: 9400000D  bl       #0xc29a8
//   0x0c2978: B40000A0  cbz      x0, #0xc298c
static inline uint64_t fde_func_0995_0x0c296c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c296cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1df780ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0996 | PC: 0x0c29d8 | FDE: 0x1df7c0 | Size: 256 bytes [_PyType_GetTextSignatureFromInternalDoc]
// Khung tháo gỡ #0996 | Địa chỉ PC: 0x0c29d8 | Địa chỉ FDE: 0x1df7c0 | Kích thước: 256 bytes
//   0x0c29d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c29dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c29e0: 910043FD  add      x29, sp, #0x10
//   0x0c29e4: 94000013  bl       #0xc2a30
static inline uint64_t fde_func_0996_0x0c29d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c29d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df7c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0997 | PC: 0x0c2b1c | FDE: 0x1df820 | Size: 60 bytes [_PyType_InitCache]
// Khung tháo gỡ #0997 | Địa chỉ PC: 0x0c2b1c | Địa chỉ FDE: 0x1df820 | Kích thước: 60 bytes
//   0x0c2b1c: B00009E8  adrp     x8, #0x1ff000
//   0x0c2b20: F945F108  ldr      x8, [x8, #0xbe0]
//   0x0c2b24: 5286A10A  mov      w10, #0x3508
//   0x0c2b28: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_0997_0x0c2b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2b1cULL ^ (static_cast<uint64_t>(0xb00009e8ULL) << 13);
    acc = (acc + a1 + 0xf945f108ULL) ^ 0x1df820ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0998 | PC: 0x0c2b58 | FDE: 0x1df838 | Size: 92 bytes [PyType_ClearCache]
// Khung tháo gỡ #0998 | Địa chỉ PC: 0x0c2b58 | Địa chỉ FDE: 0x1df838 | Kích thước: 92 bytes
//   0x0c2b58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2b5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2b60: 910043FD  add      x29, sp, #0x10
//   0x0c2b64: B00009F3  adrp     x19, #0x1ff000
static inline uint64_t fde_func_0998_0x0c2b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2b58ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df838ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0999 | PC: 0x0c2bb4 | FDE: 0x1df858 | Size: 156 bytes [_PyType_Fini]
// Khung tháo gỡ #0999 | Địa chỉ PC: 0x0c2bb4 | Địa chỉ FDE: 0x1df858 | Kích thước: 156 bytes
//   0x0c2bb4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c2bb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2bbc: 910043FD  add      x29, sp, #0x10
//   0x0c2bc0: B00009F4  adrp     x20, #0x1ff000
static inline uint64_t fde_func_0999_0x0c2bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2bb4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df858ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1000 | PC: 0x0c2c50 | FDE: 0x1df878 | Size: 248 bytes [_PyType_Modified]
// Khung tháo gỡ #1000 | Địa chỉ PC: 0x0c2c50 | Địa chỉ FDE: 0x1df878 | Kích thước: 248 bytes
//   0x0c2c50: D10183FF  sub      sp, sp, #0x60
//   0x0c2c54: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c2c58: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c2c5c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1000_0x0c2c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2c50ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1df878ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1001 | PC: 0x0c2d48 | FDE: 0x1df8a0 | Size: 56 bytes [PyType_Modified]
// Khung tháo gỡ #1001 | Địa chỉ PC: 0x0c2d48 | Địa chỉ FDE: 0x1df8a0 | Kích thước: 56 bytes
//   0x0c2d48: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c2d4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2d50: 910043FD  add      x29, sp, #0x10
//   0x0c2d54: B00009F4  adrp     x20, #0x1ff000
static inline uint64_t fde_func_1001_0x0c2d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2d48ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df8a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1002 | PC: 0x0c2d80 | FDE: 0x1df8c0 | Size: 56 bytes [_PyType_Name]
// Khung tháo gỡ #1002 | Địa chỉ PC: 0x0c2d80 | Địa chỉ FDE: 0x1df8c0 | Kích thước: 56 bytes
//   0x0c2d80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2d84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2d88: 910043FD  add      x29, sp, #0x10
//   0x0c2d8c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1002_0x0c2d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2d80ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df8c0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1003 | PC: 0x0c2db8 | FDE: 0x1df8e0 | Size: 176 bytes [PyType_GenericAlloc]
// Khung tháo gỡ #1003 | Địa chỉ PC: 0x0c2db8 | Địa chỉ FDE: 0x1df8e0 | Kích thước: 176 bytes
//   0x0c2db8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c2dbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c2dc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c2dc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1003_0x0c2db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2db8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df8e0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1004 | PC: 0x0c2e68 | FDE: 0x1df908 | Size: 12 bytes [PyType_GenericNew]
// Khung tháo gỡ #1004 | Địa chỉ PC: 0x0c2e68 | Địa chỉ FDE: 0x1df908 | Kích thước: 12 bytes
//   0x0c2e68: F9409802  ldr      x2, [x0, #0x130]
//   0x0c2e6c: AA1F03E1  mov      x1, xzr
//   0x0c2e70: D61F0040  br       x2
static inline uint64_t fde_func_1004_0x0c2e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2e68ULL ^ (static_cast<uint64_t>(0xf9409802ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1df908ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1005 | PC: 0x0c2e74 | FDE: 0x1df920 | Size: 100 bytes [_PyType_IsSubtype]
// Khung tháo gỡ #1005 | Địa chỉ PC: 0x0c2e74 | Địa chỉ FDE: 0x1df920 | Kích thước: 100 bytes
//   0x0c2e74: F940AC09  ldr      x9, [x0, #0x158]
//   0x0c2e78: B40001E9  cbz      x9, #0xc2eb4
//   0x0c2e7c: F9400928  ldr      x8, [x9, #0x10]
//   0x0c2e80: F100051F  cmp      x8, #1
static inline uint64_t fde_func_1005_0x0c2e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2e74ULL ^ (static_cast<uint64_t>(0xf940ac09ULL) << 13);
    acc = (acc + a1 + 0xb40001e9ULL) ^ 0x1df920ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1006 | PC: 0x0c2ed8 | FDE: 0x1df938 | Size: 84 bytes [PyType_IsSubtype]
// Khung tháo gỡ #1006 | Địa chỉ PC: 0x0c2ed8 | Địa chỉ FDE: 0x1df938 | Kích thước: 84 bytes
//   0x0c2ed8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c2edc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c2ee0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c2ee4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1006_0x0c2ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2ed8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df938ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1007 | PC: 0x0c2f2c | FDE: 0x1df958 | Size: 104 bytes [_PyObject_LookupSpecial]
// Khung tháo gỡ #1007 | Địa chỉ PC: 0x0c2f2c | Địa chỉ FDE: 0x1df958 | Kích thước: 104 bytes
//   0x0c2f2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c2f30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2f34: 910043FD  add      x29, sp, #0x10
//   0x0c2f38: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1007_0x0c2f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2f2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df958ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1008 | PC: 0x0c2f94 | FDE: 0x1df978 | Size: 60 bytes [_PyType_LookupId]
// Khung tháo gỡ #1008 | Địa chỉ PC: 0x0c2f94 | Địa chỉ FDE: 0x1df978 | Kích thước: 60 bytes
//   0x0c2f94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2f98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2f9c: 910043FD  add      x29, sp, #0x10
//   0x0c2fa0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1008_0x0c2f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2f94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1df978ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1009 | PC: 0x0c2fd0 | FDE: 0x1df998 | Size: 8 bytes [PyType_GetFlags]
// Khung tháo gỡ #1009 | Địa chỉ PC: 0x0c2fd0 | Địa chỉ FDE: 0x1df998 | Kích thước: 8 bytes
//   0x0c2fd0: F9405400  ldr      x0, [x0, #0xa8]
//   0x0c2fd4: D65F03C0  ret      
static inline uint64_t fde_func_1009_0x0c2fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2fd0ULL ^ (static_cast<uint64_t>(0xf9405400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1df998ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1010 | PC: 0x0c2fd8 | FDE: 0x1df9b0 | Size: 200 bytes [_PyType_CalculateMetaclass]
// Khung tháo gỡ #1010 | Địa chỉ PC: 0x0c2fd8 | Địa chỉ FDE: 0x1df9b0 | Kích thước: 200 bytes
//   0x0c2fd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c2fdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c2fe0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c2fe4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1010_0x0c2fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2fd8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1df9b0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1011 | PC: 0x0c30a0 | FDE: 0x1df9d8 | Size: 88 bytes [PyType_FromSpecWithBases]
// Khung tháo gỡ #1011 | Địa chỉ PC: 0x0c30a0 | Địa chỉ FDE: 0x1df9d8 | Kích thước: 88 bytes
//   0x0c30a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c30a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c30a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c30ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1011_0x0c30a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c30a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1df9d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1012 | PC: 0x0c30f8 | FDE: 0x1df9f8 | Size: 256 bytes [PyType_FromModuleAndSpec]
// Khung tháo gỡ #1012 | Địa chỉ PC: 0x0c30f8 | Địa chỉ FDE: 0x1df9f8 | Kích thước: 256 bytes
//   0x0c30f8: D10203FF  sub      sp, sp, #0x80
//   0x0c30fc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0c3100: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0c3104: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1012_0x0c30f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c30f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1df9f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1013 | PC: 0x0c3a40 | FDE: 0x1dfa80 | Size: 92 bytes [PyType_Ready]
// Khung tháo gỡ #1013 | Địa chỉ PC: 0x0c3a40 | Địa chỉ FDE: 0x1dfa80 | Kích thước: 92 bytes
//   0x0c3a40: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c3a44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c3a48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c3a4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1013_0x0c3a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3a40ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dfa80ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1014 | PC: 0x0c3a9c | FDE: 0x1dfaa0 | Size: 8 bytes [PyType_FromSpec]
// Khung tháo gỡ #1014 | Địa chỉ PC: 0x0c3a9c | Địa chỉ FDE: 0x1dfaa0 | Kích thước: 8 bytes
//   0x0c3a9c: AA1F03E1  mov      x1, xzr
//   0x0c3aa0: 17FE6590  b        #0x5d0e0
static inline uint64_t fde_func_1014_0x0c3a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3a9cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fe6590ULL) ^ 0x1dfaa0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1015 | PC: 0x0c3aa4 | FDE: 0x1dfab8 | Size: 60 bytes [_PyType_GetQualName]
// Khung tháo gỡ #1015 | Địa chỉ PC: 0x0c3aa4 | Địa chỉ FDE: 0x1dfab8 | Kích thước: 60 bytes
//   0x0c3aa4: AA1F03E1  mov      x1, xzr
//   0x0c3aa8: 14000001  b        #0xc3aac
//   0x0c3aac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c3ab0: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1015_0x0c3aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3aa4ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1dfab8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1016 | PC: 0x0c3ae0 | FDE: 0x1dfaf0 | Size: 100 bytes [PyType_GetSlot]
// Khung tháo gỡ #1016 | Địa chỉ PC: 0x0c3ae0 | Địa chỉ FDE: 0x1dfaf0 | Kích thước: 100 bytes
//   0x0c3ae0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c3ae4: 910003FD  mov      x29, sp
//   0x0c3ae8: 51000428  sub      w8, w1, #1
//   0x0c3aec: 7101451F  cmp      w8, #0x51
static inline uint64_t fde_func_1016_0x0c3ae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3ae0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dfaf0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1017 | PC: 0x0c3b44 | FDE: 0x1dfb10 | Size: 84 bytes [PyType_GetModule]
// Khung tháo gỡ #1017 | Địa chỉ PC: 0x0c3b44 | Địa chỉ FDE: 0x1dfb10 | Kích thước: 84 bytes
//   0x0c3b44: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c3b48: 910003FD  mov      x29, sp
//   0x0c3b4c: 3942A408  ldrb     w8, [x0, #0xa9]
//   0x0c3b50: 37080088  tbnz     w8, #1, #0xc3b60
static inline uint64_t fde_func_1017_0x0c3b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3b44ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dfb10ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1018 | PC: 0x0c3b98 | FDE: 0x1dfb30 | Size: 28 bytes [PyType_GetModuleState]
// Khung tháo gỡ #1018 | Địa chỉ PC: 0x0c3b98 | Địa chỉ FDE: 0x1dfb30 | Kích thước: 28 bytes
//   0x0c3b98: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c3b9c: 910003FD  mov      x29, sp
//   0x0c3ba0: 97FE5C84  bl       #0x5adb0
//   0x0c3ba4: B4000040  cbz      x0, #0xc3bac
static inline uint64_t fde_func_1018_0x0c3b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3b98ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dfb30ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1019 | PC: 0x0c3bb4 | FDE: 0x1dfb50 | Size: 108 bytes [_PyType_GetModuleByDef]
// Khung tháo gỡ #1019 | Địa chỉ PC: 0x0c3bb4 | Địa chỉ FDE: 0x1dfb50 | Kích thước: 108 bytes
//   0x0c3bb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c3bb8: 910003FD  mov      x29, sp
//   0x0c3bbc: F940AC0A  ldr      x10, [x0, #0x158]
//   0x0c3bc0: AA1F03E9  mov      x9, xzr
static inline uint64_t fde_func_1019_0x0c3bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3bb4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1dfb50ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1020 | PC: 0x0c3c20 | FDE: 0x1dfb70 | Size: 256 bytes [_PyType_Lookup]
// Khung tháo gỡ #1020 | Địa chỉ PC: 0x0c3c20 | Địa chỉ FDE: 0x1dfb70 | Kích thước: 256 bytes
//   0x0c3c20: D10143FF  sub      sp, sp, #0x50
//   0x0c3c24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c3c28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c3c2c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1020_0x0c3c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3c20ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1dfb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1021 | PC: 0x0c5d84 | FDE: 0x1dfe38 | Size: 256 bytes [_PyType_Ready]
// Khung tháo gỡ #1021 | Địa chỉ PC: 0x0c5d84 | Địa chỉ FDE: 0x1dfe38 | Kích thước: 256 bytes
//   0x0c5d84: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c5d88: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c5d8c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c5d90: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1021_0x0c5d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5d84ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1dfe38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1022 | PC: 0x0c7544 | FDE: 0x1dfe68 | Size: 256 bytes [_PyTypes_InitSlotDefs]
// Khung tháo gỡ #1022 | Địa chỉ PC: 0x0c7544 | Địa chỉ FDE: 0x1dfe68 | Kích thước: 256 bytes
//   0x0c7544: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c7548: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c754c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c7550: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1022_0x0c7544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7544ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1dfe68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1023 | PC: 0x0d1340 | FDE: 0x1e1578 | Size: 224 bytes [_Py_GetErrorHandler]
// Khung tháo gỡ #1023 | Địa chỉ PC: 0x0d1340 | Địa chỉ FDE: 0x1e1578 | Kích thước: 224 bytes
//   0x0d1340: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d1344: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d1348: 910043FD  add      x29, sp, #0x10
//   0x0d134c: B40004E0  cbz      x0, #0xd13e8
static inline uint64_t fde_func_1023_0x0d1340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1340ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1578ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1024 | PC: 0x0d1420 | FDE: 0x1e1598 | Size: 256 bytes [_PyUnicode_CheckConsistency]
// Khung tháo gỡ #1024 | Địa chỉ PC: 0x0d1420 | Địa chỉ FDE: 0x1e1598 | Kích thước: 256 bytes
//   0x0d1420: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d1424: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d1428: 910043FD  add      x29, sp, #0x10
//   0x0d142c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1024_0x0d1420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1420ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1025 | PC: 0x0d1c04 | FDE: 0x1e15b8 | Size: 256 bytes [PyUnicode_New]
// Khung tháo gỡ #1025 | Địa chỉ PC: 0x0d1c04 | Địa chỉ FDE: 0x1e15b8 | Kích thước: 256 bytes
//   0x0d1c04: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d1c08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d1c0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d1c10: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1025_0x0d1c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1c04ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e15b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1026 | PC: 0x0d1eb0 | FDE: 0x1e15e0 | Size: 256 bytes [_PyUnicode_FastCopyCharacters]
// Khung tháo gỡ #1026 | Địa chỉ PC: 0x0d1eb0 | Địa chỉ FDE: 0x1e15e0 | Kích thước: 256 bytes
//   0x0d1eb0: 2A1F03E5  mov      w5, wzr
//   0x0d1eb4: 14000001  b        #0xd1eb8
//   0x0d1eb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d1ebc: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1026_0x0d1eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1eb0ULL ^ (static_cast<uint64_t>(0x2a1f03e5ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e15e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1027 | PC: 0x0d24d4 | FDE: 0x1e1618 | Size: 256 bytes [PyUnicode_CopyCharacters]
// Khung tháo gỡ #1027 | Địa chỉ PC: 0x0d24d4 | Địa chỉ FDE: 0x1e1618 | Kích thước: 256 bytes
//   0x0d24d4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d24d8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d24dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d24e0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1027_0x0d24d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d24d4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e1618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1028 | PC: 0x0d2834 | FDE: 0x1e1640 | Size: 256 bytes [_PyUnicode_Ready]
// Khung tháo gỡ #1028 | Địa chỉ PC: 0x0d2834 | Địa chỉ FDE: 0x1e1640 | Kích thước: 256 bytes
//   0x0d2834: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d2838: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d283c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2840: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1028_0x0d2834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2834ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1029 | PC: 0x0d2b08 | FDE: 0x1e1668 | Size: 256 bytes [PyUnicode_Resize]
// Khung tháo gỡ #1029 | Địa chỉ PC: 0x0d2b08 | Địa chỉ FDE: 0x1e1668 | Kích thước: 256 bytes
//   0x0d2b08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d2b0c: 910003FD  mov      x29, sp
//   0x0d2b10: B40001A0  cbz      x0, #0xd2b44
//   0x0d2b14: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1029_0x0d2b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2b08ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e1668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1030 | PC: 0x0d2eb4 | FDE: 0x1e16b0 | Size: 256 bytes [PyUnicode_FromUnicode]
// Khung tháo gỡ #1030 | Địa chỉ PC: 0x0d2eb4 | Địa chỉ FDE: 0x1e16b0 | Kích thước: 256 bytes
//   0x0d2eb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d2eb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d2ebc: 910043FD  add      x29, sp, #0x10
//   0x0d2ec0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1030_0x0d2eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2eb4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e16b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1031 | PC: 0x0d30d0 | FDE: 0x1e16f0 | Size: 256 bytes [PyUnicode_FromWideChar]
// Khung tháo gỡ #1031 | Địa chỉ PC: 0x0d30d0 | Địa chỉ FDE: 0x1e16f0 | Kích thước: 256 bytes
//   0x0d30d0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d30d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d30d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d30dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1031_0x0d30d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d30d0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e16f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1032 | PC: 0x0d3640 | FDE: 0x1e1738 | Size: 148 bytes [PyUnicode_FromStringAndSize]
// Khung tháo gỡ #1032 | Địa chỉ PC: 0x0d3640 | Địa chỉ FDE: 0x1e1738 | Kích thước: 148 bytes
//   0x0d3640: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d3644: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d3648: 910043FD  add      x29, sp, #0x10
//   0x0d364c: B7F80141  tbnz     x1, #0x3f, #0xd3674
static inline uint64_t fde_func_1032_0x0d3640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3640ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1738ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1033 | PC: 0x0d36d4 | FDE: 0x1e1758 | Size: 16 bytes [PyUnicode_DecodeUTF8Stateful]
// Khung tháo gỡ #1033 | Địa chỉ PC: 0x0d36d4 | Địa chỉ FDE: 0x1e1758 | Kích thước: 16 bytes
//   0x0d36d4: AA0303E4  mov      x4, x3
//   0x0d36d8: AA0203E3  mov      x3, x2
//   0x0d36dc: 2A1F03E2  mov      w2, wzr
//   0x0d36e0: 1400125D  b        #0xd8054
static inline uint64_t fde_func_1033_0x0d36d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d36d4ULL ^ (static_cast<uint64_t>(0xaa0303e4ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x1e1758ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1034 | PC: 0x0d36e4 | FDE: 0x1e1770 | Size: 96 bytes [PyUnicode_FromString]
// Khung tháo gỡ #1034 | Địa chỉ PC: 0x0d36e4 | Địa chỉ FDE: 0x1e1770 | Kích thước: 96 bytes
//   0x0d36e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d36e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d36ec: 910043FD  add      x29, sp, #0x10
//   0x0d36f0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1034_0x0d36e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d36e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1770ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1035 | PC: 0x0d3744 | FDE: 0x1e1790 | Size: 256 bytes [_PyUnicode_FromId]
// Khung tháo gỡ #1035 | Địa chỉ PC: 0x0d3744 | Địa chỉ FDE: 0x1e1790 | Kích thước: 256 bytes
//   0x0d3744: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d3748: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d374c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d3750: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1035_0x0d3744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3744ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e1790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1036 | PC: 0x0d3884 | FDE: 0x1e17b8 | Size: 256 bytes [PyUnicode_InternInPlace]
// Khung tháo gỡ #1036 | Địa chỉ PC: 0x0d3884 | Địa chỉ FDE: 0x1e17b8 | Kích thước: 256 bytes
//   0x0d3884: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d3888: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d388c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d3890: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1036_0x0d3884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3884ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e17b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1037 | PC: 0x0d3994 | FDE: 0x1e17d8 | Size: 256 bytes [_PyUnicode_FromASCII]
// Khung tháo gỡ #1037 | Địa chỉ PC: 0x0d3994 | Địa chỉ FDE: 0x1e17d8 | Kích thước: 256 bytes
//   0x0d3994: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d3998: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d399c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d39a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1037_0x0d3994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3994ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e17d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1038 | PC: 0x0d3a98 | FDE: 0x1e17f8 | Size: 256 bytes [PyUnicode_FromKindAndData]
// Khung tháo gỡ #1038 | Địa chỉ PC: 0x0d3a98 | Địa chỉ FDE: 0x1e17f8 | Kích thước: 256 bytes
//   0x0d3a98: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d3a9c: 910003FD  mov      x29, sp
//   0x0d3aa0: B7F80162  tbnz     x2, #0x3f, #0xd3acc
//   0x0d3aa4: 7100101F  cmp      w0, #4
static inline uint64_t fde_func_1038_0x0d3a98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3a98ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e17f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1039 | PC: 0x0d4500 | FDE: 0x1e1888 | Size: 256 bytes [_PyUnicode_FindMaxChar]
// Khung tháo gỡ #1039 | Địa chỉ PC: 0x0d4500 | Địa chỉ FDE: 0x1e1888 | Kích thước: 256 bytes
//   0x0d4500: B50001C1  cbnz     x1, #0xd4538
//   0x0d4504: F9400808  ldr      x8, [x0, #0x10]
//   0x0d4508: EB02011F  cmp      x8, x2
//   0x0d450c: 54000161  b.ne     #0xd4538
static inline uint64_t fde_func_1039_0x0d4500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4500ULL ^ (static_cast<uint64_t>(0xb50001c1ULL) << 13);
    acc = (acc + a1 + 0xf9400808ULL) ^ 0x1e1888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1040 | PC: 0x0d47b4 | FDE: 0x1e18a0 | Size: 256 bytes [_PyUnicode_Copy]
// Khung tháo gỡ #1040 | Địa chỉ PC: 0x0d47b4 | Địa chỉ FDE: 0x1e18a0 | Kích thước: 256 bytes
//   0x0d47b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d47b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d47bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d47c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1040_0x0d47b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d47b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e18a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1041 | PC: 0x0d48b8 | FDE: 0x1e18c0 | Size: 256 bytes [PyUnicode_AsUCS4]
// Khung tháo gỡ #1041 | Địa chỉ PC: 0x0d48b8 | Địa chỉ FDE: 0x1e18c0 | Kích thước: 256 bytes
//   0x0d48b8: B4000061  cbz      x1, #0xd48c4
//   0x0d48bc: B7F80042  tbnz     x2, #0x3f, #0xd48c4
//   0x0d48c0: 1400000A  b        #0xd48e8
//   0x0d48c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1041_0x0d48b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d48b8ULL ^ (static_cast<uint64_t>(0xb4000061ULL) << 13);
    acc = (acc + a1 + 0xb7f80042ULL) ^ 0x1e18c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1042 | PC: 0x0d4ab8 | FDE: 0x1e1908 | Size: 16 bytes [PyUnicode_AsUCS4Copy]
// Khung tháo gỡ #1042 | Địa chỉ PC: 0x0d4ab8 | Địa chỉ FDE: 0x1e1908 | Kích thước: 16 bytes
//   0x0d4ab8: 52800023  mov      w3, #1
//   0x0d4abc: AA1F03E1  mov      x1, xzr
//   0x0d4ac0: AA1F03E2  mov      x2, xzr
//   0x0d4ac4: 17FFFF89  b        #0xd48e8
static inline uint64_t fde_func_1042_0x0d4ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4ab8ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1e1908ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1043 | PC: 0x0d4ac8 | FDE: 0x1e1920 | Size: 256 bytes [PyUnicode_FromFormatV]
// Khung tháo gỡ #1043 | Địa chỉ PC: 0x0d4ac8 | Địa chỉ FDE: 0x1e1920 | Kích thước: 256 bytes
//   0x0d4ac8: D103C3FF  sub      sp, sp, #0xf0
//   0x0d4acc: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0d4ad0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0d4ad4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1043_0x0d4ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4ac8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e1920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1044 | PC: 0x0d566c | FDE: 0x1e1950 | Size: 28 bytes [_PyUnicodeWriter_Init]
// Khung tháo gỡ #1044 | Địa chỉ PC: 0x0d566c | Địa chỉ FDE: 0x1e1950 | Kích thước: 28 bytes
//   0x0d566c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0d5670: 52800FE8  mov      w8, #0x7f
//   0x0d5674: AD000000  stp      q0, q0, [x0]
//   0x0d5678: 3D800800  str      q0, [x0, #0x20]
static inline uint64_t fde_func_1044_0x0d566c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d566cULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0x52800fe8ULL) ^ 0x1e1950ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1045 | PC: 0x0d5688 | FDE: 0x1e1968 | Size: 256 bytes [_PyUnicodeWriter_WriteASCIIString]
// Khung tháo gỡ #1045 | Địa chỉ PC: 0x0d5688 | Địa chỉ FDE: 0x1e1968 | Kích thước: 256 bytes
//   0x0d5688: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d568c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5690: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5694: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1045_0x0d5688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5688ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1046 | PC: 0x0d593c | FDE: 0x1e1988 | Size: 256 bytes [_PyUnicodeWriter_Finish]
// Khung tháo gỡ #1046 | Địa chỉ PC: 0x0d593c | Địa chỉ FDE: 0x1e1988 | Kích thước: 256 bytes
//   0x0d593c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d5940: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5944: 910043FD  add      x29, sp, #0x10
//   0x0d5948: F9401001  ldr      x1, [x0, #0x20]
static inline uint64_t fde_func_1046_0x0d593c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d593cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1047 | PC: 0x0d5aac | FDE: 0x1e19a8 | Size: 40 bytes [_PyUnicodeWriter_Dealloc]
// Khung tháo gỡ #1047 | Địa chỉ PC: 0x0d5aac | Địa chỉ FDE: 0x1e19a8 | Kích thước: 40 bytes
//   0x0d5aac: AA0003E8  mov      x8, x0
//   0x0d5ab0: F9400000  ldr      x0, [x0]
//   0x0d5ab4: B40000C0  cbz      x0, #0xd5acc
//   0x0d5ab8: F900011F  str      xzr, [x8]
static inline uint64_t fde_func_1047_0x0d5aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5aacULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x1e19a8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1048 | PC: 0x0d5ad4 | FDE: 0x1e19c0 | Size: 152 bytes [PyUnicode_FromFormat]
// Khung tháo gỡ #1048 | Địa chỉ PC: 0x0d5ad4 | Địa chỉ FDE: 0x1e19c0 | Kích thước: 152 bytes
//   0x0d5ad4: D104C3FF  sub      sp, sp, #0x130
//   0x0d5ad8: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x0d5adc: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x0d5ae0: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_1048_0x0d5ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5ad4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1e19c0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1049 | PC: 0x0d5b6c | FDE: 0x1e19e0 | Size: 256 bytes [PyUnicode_AsWideChar]
// Khung tháo gỡ #1049 | Địa chỉ PC: 0x0d5b6c | Địa chỉ FDE: 0x1e19e0 | Kích thước: 256 bytes
//   0x0d5b6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d5b70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5b74: 910043FD  add      x29, sp, #0x10
//   0x0d5b78: B40000E0  cbz      x0, #0xd5b94
static inline uint64_t fde_func_1049_0x0d5b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5b6cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e19e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1050 | PC: 0x0d5cf0 | FDE: 0x1e1a00 | Size: 256 bytes [PyUnicode_AsWideCharString]
// Khung tháo gỡ #1050 | Địa chỉ PC: 0x0d5cf0 | Địa chỉ FDE: 0x1e1a00 | Kích thước: 256 bytes
//   0x0d5cf0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d5cf4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d5cf8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d5cfc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1050_0x0d5cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5cf0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e1a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1051 | PC: 0x0d5ed8 | FDE: 0x1e1a28 | Size: 216 bytes [_PyUnicode_WideCharString_Converter]
// Khung tháo gỡ #1051 | Địa chỉ PC: 0x0d5ed8 | Địa chỉ FDE: 0x1e1a28 | Kích thước: 216 bytes
//   0x0d5ed8: D10103FF  sub      sp, sp, #0x40
//   0x0d5edc: F9000BF5  str      x21, [sp, #0x10]
//   0x0d5ee0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d5ee4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1051_0x0d5ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5ed8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e1a28ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1052 | PC: 0x0d5fb0 | FDE: 0x1e1a48 | Size: 132 bytes [_PyUnicode_AsUnicode]
// Khung tháo gỡ #1052 | Địa chỉ PC: 0x0d5fb0 | Địa chỉ FDE: 0x1e1a48 | Kích thước: 132 bytes
//   0x0d5fb0: D100C3FF  sub      sp, sp, #0x30
//   0x0d5fb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5fb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5fbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1052_0x0d5fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5fb0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1a48ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1053 | PC: 0x0d6034 | FDE: 0x1e1a68 | Size: 232 bytes [_PyUnicode_WideCharString_Opt_Converter]
// Khung tháo gỡ #1053 | Địa chỉ PC: 0x0d6034 | Địa chỉ FDE: 0x1e1a68 | Kích thước: 232 bytes
//   0x0d6034: D10103FF  sub      sp, sp, #0x40
//   0x0d6038: F9000BF5  str      x21, [sp, #0x10]
//   0x0d603c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d6040: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1053_0x0d6034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6034ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e1a68ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1054 | PC: 0x0d611c | FDE: 0x1e1a88 | Size: 256 bytes [PyUnicode_FromOrdinal]
// Khung tháo gỡ #1054 | Địa chỉ PC: 0x0d611c | Địa chỉ FDE: 0x1e1a88 | Kích thước: 256 bytes
//   0x0d611c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6120: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6124: 910043FD  add      x29, sp, #0x10
//   0x0d6128: 7144401F  cmp      w0, #0x110, lsl #12
static inline uint64_t fde_func_1054_0x0d611c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d611cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1a88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1055 | PC: 0x0d6258 | FDE: 0x1e1aa8 | Size: 152 bytes [PyUnicode_FromObject]
// Khung tháo gỡ #1055 | Địa chỉ PC: 0x0d6258 | Địa chỉ FDE: 0x1e1aa8 | Kích thước: 152 bytes
//   0x0d6258: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d625c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6260: 910043FD  add      x29, sp, #0x10
//   0x0d6264: B0000949  adrp     x9, #0x1ff000
static inline uint64_t fde_func_1055_0x0d6258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6258ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1aa8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1056 | PC: 0x0d62f0 | FDE: 0x1e1ac8 | Size: 256 bytes [PyUnicode_FromEncodedObject]
// Khung tháo gỡ #1056 | Địa chỉ PC: 0x0d62f0 | Địa chỉ FDE: 0x1e1ac8 | Kích thước: 256 bytes
//   0x0d62f0: D10283FF  sub      sp, sp, #0xa0
//   0x0d62f4: F90033F7  str      x23, [sp, #0x60]
//   0x0d62f8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0d62fc: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1056_0x0d62f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d62f0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1e1ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1057 | PC: 0x0d661c | FDE: 0x1e1af0 | Size: 256 bytes [PyUnicode_Decode]
// Khung tháo gỡ #1057 | Địa chỉ PC: 0x0d661c | Địa chỉ FDE: 0x1e1af0 | Kích thước: 256 bytes
//   0x0d661c: D10303FF  sub      sp, sp, #0xc0
//   0x0d6620: F9003BF9  str      x25, [sp, #0x70]
//   0x0d6624: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0d6628: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_1057_0x0d661c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d661cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x1e1af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1058 | PC: 0x0d6aa0 | FDE: 0x1e1b18 | Size: 172 bytes [_Py_normalize_encoding]
// Khung tháo gỡ #1058 | Địa chỉ PC: 0x0d6aa0 | Địa chỉ FDE: 0x1e1b18 | Kích thước: 172 bytes
//   0x0d6aa0: 3940000F  ldrb     w15, [x0]
//   0x0d6aa4: 3400048F  cbz      w15, #0xd6b34
//   0x0d6aa8: B0000949  adrp     x9, #0x1ff000
//   0x0d6aac: B000094B  adrp     x11, #0x1ff000
static inline uint64_t fde_func_1058_0x0d6aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6aa0ULL ^ (static_cast<uint64_t>(0x3940000fULL) << 13);
    acc = (acc + a1 + 0x3400048fULL) ^ 0x1e1b18ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1059 | PC: 0x0d6b4c | FDE: 0x1e1b30 | Size: 256 bytes [PyUnicode_DecodeASCII]
// Khung tháo gỡ #1059 | Địa chỉ PC: 0x0d6b4c | Địa chỉ FDE: 0x1e1b30 | Kích thước: 256 bytes
//   0x0d6b4c: D103C3FF  sub      sp, sp, #0xf0
//   0x0d6b50: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0d6b54: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0d6b58: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1059_0x0d6b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6b4cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e1b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1060 | PC: 0x0d7068 | FDE: 0x1e1b60 | Size: 4 bytes [PyUnicode_DecodeLatin1]
// Khung tháo gỡ #1060 | Địa chỉ PC: 0x0d7068 | Địa chỉ FDE: 0x1e1b60 | Kích thước: 4 bytes
//   0x0d7068: 17FFF2AF  b        #0xd3b24
static inline uint64_t fde_func_1060_0x0d7068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7068ULL ^ (static_cast<uint64_t>(0x17fff2afULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x1e1b60ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1061 | PC: 0x0d706c | FDE: 0x1e1b78 | Size: 140 bytes [PyUnicode_AsDecodedObject]
// Khung tháo gỡ #1061 | Địa chỉ PC: 0x0d706c | Địa chỉ FDE: 0x1e1b78 | Kích thước: 140 bytes
//   0x0d706c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d7070: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d7074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d7078: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1061_0x0d706c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d706cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1b78ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1062 | PC: 0x0d70f8 | FDE: 0x1e1b98 | Size: 12 bytes [PyUnicode_GetDefaultEncoding]
// Khung tháo gỡ #1062 | Địa chỉ PC: 0x0d70f8 | Địa chỉ FDE: 0x1e1b98 | Kích thước: 12 bytes
//   0x0d70f8: D0000680  adrp     x0, #0x1a9000
//   0x0d70fc: 912FA800  add      x0, x0, #0xbea
//   0x0d7100: D65F03C0  ret      
static inline uint64_t fde_func_1062_0x0d70f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d70f8ULL ^ (static_cast<uint64_t>(0xd0000680ULL) << 13);
    acc = (acc + a1 + 0x912fa800ULL) ^ 0x1e1b98ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1063 | PC: 0x0d7104 | FDE: 0x1e1bb0 | Size: 232 bytes [PyUnicode_AsDecodedUnicode]
// Khung tháo gỡ #1063 | Địa chỉ PC: 0x0d7104 | Địa chỉ FDE: 0x1e1bb0 | Kích thước: 232 bytes
//   0x0d7104: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d7108: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d710c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d7110: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1063_0x0d7104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7104ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1bb0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1064 | PC: 0x0d71ec | FDE: 0x1e1bd0 | Size: 104 bytes [PyUnicode_Encode]
// Khung tháo gỡ #1064 | Địa chỉ PC: 0x0d71ec | Địa chỉ FDE: 0x1e1bd0 | Kích thước: 104 bytes
//   0x0d71ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d71f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d71f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d71f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1064_0x0d71ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d71ecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1bd0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1065 | PC: 0x0d7254 | FDE: 0x1e1bf0 | Size: 256 bytes [PyUnicode_AsEncodedString]
// Khung tháo gỡ #1065 | Địa chỉ PC: 0x0d7254 | Địa chỉ FDE: 0x1e1bf0 | Kích thước: 256 bytes
//   0x0d7254: D10183FF  sub      sp, sp, #0x60
//   0x0d7258: F90013F7  str      x23, [sp, #0x20]
//   0x0d725c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d7260: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1065_0x0d7254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7254ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e1bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1066 | PC: 0x0d7680 | FDE: 0x1e1c18 | Size: 132 bytes [PyUnicode_AsEncodedObject]
// Khung tháo gỡ #1066 | Địa chỉ PC: 0x0d7680 | Địa chỉ FDE: 0x1e1c18 | Kích thước: 132 bytes
//   0x0d7680: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d7684: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d7688: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d768c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1066_0x0d7680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7680ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1c18ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1067 | PC: 0x0d7704 | FDE: 0x1e1c38 | Size: 256 bytes [PyUnicode_EncodeLocale]
// Khung tháo gỡ #1067 | Địa chỉ PC: 0x0d7704 | Địa chỉ FDE: 0x1e1c38 | Kích thước: 256 bytes
//   0x0d7704: D101C3FF  sub      sp, sp, #0x70
//   0x0d7708: F9001BF7  str      x23, [sp, #0x30]
//   0x0d770c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0d7710: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1067_0x0d7704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7704ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e1c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1068 | PC: 0x0d7884 | FDE: 0x1e1c60 | Size: 256 bytes [PyUnicode_EncodeFSDefault]
// Khung tháo gỡ #1068 | Địa chỉ PC: 0x0d7884 | Địa chỉ FDE: 0x1e1c60 | Kích thước: 256 bytes
//   0x0d7884: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d7888: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d788c: 910043FD  add      x29, sp, #0x10
//   0x0d7890: 90000948  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1068_0x0d7884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7884ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1069 | PC: 0x0d7b98 | FDE: 0x1e1cc8 | Size: 12 bytes [_PyUnicode_AsUTF8String]
// Khung tháo gỡ #1069 | Địa chỉ PC: 0x0d7b98 | Địa chỉ FDE: 0x1e1cc8 | Kích thước: 12 bytes
//   0x0d7b98: AA0103E2  mov      x2, x1
//   0x0d7b9c: 2A1F03E1  mov      w1, wzr
//   0x0d7ba0: 17FFFF52  b        #0xd78e8
static inline uint64_t fde_func_1069_0x0d7b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7b98ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e1ULL) ^ 0x1e1cc8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1070 | PC: 0x0d7ba4 | FDE: 0x1e1ce0 | Size: 140 bytes [_PyUnicode_AsASCIIString]
// Khung tháo gỡ #1070 | Địa chỉ PC: 0x0d7ba4 | Địa chỉ FDE: 0x1e1ce0 | Kích thước: 140 bytes
//   0x0d7ba4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7ba8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d7bac: 910043FD  add      x29, sp, #0x10
//   0x0d7bb0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1070_0x0d7ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7ba4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1ce0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1071 | PC: 0x0d7c30 | FDE: 0x1e1d00 | Size: 160 bytes [_PyUnicode_AsLatin1String]
// Khung tháo gỡ #1071 | Địa chỉ PC: 0x0d7c30 | Địa chỉ FDE: 0x1e1d00 | Kích thước: 160 bytes
//   0x0d7c30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7c34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d7c38: 910043FD  add      x29, sp, #0x10
//   0x0d7c3c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1071_0x0d7c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7c30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1d00ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1072 | PC: 0x0d7cd0 | FDE: 0x1e1d20 | Size: 212 bytes [PyUnicode_AsEncodedUnicode]
// Khung tháo gỡ #1072 | Địa chỉ PC: 0x0d7cd0 | Địa chỉ FDE: 0x1e1d20 | Kích thước: 212 bytes
//   0x0d7cd0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d7cd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d7cd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d7cdc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1072_0x0d7cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7cd0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1d20ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1073 | PC: 0x0d7da4 | FDE: 0x1e1d40 | Size: 256 bytes [PyUnicode_DecodeLocaleAndSize]
// Khung tháo gỡ #1073 | Địa chỉ PC: 0x0d7da4 | Địa chỉ FDE: 0x1e1d40 | Kích thước: 256 bytes
//   0x0d7da4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7da8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d7dac: 910043FD  add      x29, sp, #0x10
//   0x0d7db0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1073_0x0d7da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7da4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1074 | PC: 0x0d7f24 | FDE: 0x1e1d88 | Size: 68 bytes [PyUnicode_DecodeLocale]
// Khung tháo gỡ #1074 | Địa chỉ PC: 0x0d7f24 | Địa chỉ FDE: 0x1e1d88 | Kích thước: 68 bytes
//   0x0d7f24: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d7f28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d7f2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d7f30: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1074_0x0d7f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7f24ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1d88ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1075 | PC: 0x0d7f68 | FDE: 0x1e1da8 | Size: 120 bytes [PyUnicode_DecodeFSDefault]
// Khung tháo gỡ #1075 | Địa chỉ PC: 0x0d7f68 | Địa chỉ FDE: 0x1e1da8 | Kích thước: 120 bytes
//   0x0d7f68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7f6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d7f70: 910043FD  add      x29, sp, #0x10
//   0x0d7f74: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1075_0x0d7f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7f68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1da8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1076 | PC: 0x0d7fe0 | FDE: 0x1e1dc8 | Size: 256 bytes [PyUnicode_DecodeFSDefaultAndSize]
// Khung tháo gỡ #1076 | Địa chỉ PC: 0x0d7fe0 | Địa chỉ FDE: 0x1e1dc8 | Kích thước: 256 bytes
//   0x0d7fe0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7fe4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d7fe8: 910043FD  add      x29, sp, #0x10
//   0x0d7fec: 90000948  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1076_0x0d7fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7fe0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1077 | PC: 0x0d9044 | FDE: 0x1e1e18 | Size: 256 bytes [PyUnicode_FSConverter]
// Khung tháo gỡ #1077 | Địa chỉ PC: 0x0d9044 | Địa chỉ FDE: 0x1e1e18 | Kích thước: 256 bytes
//   0x0d9044: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d9048: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d904c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d9050: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1077_0x0d9044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9044ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1e18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1078 | PC: 0x0d9174 | FDE: 0x1e1e38 | Size: 256 bytes [PyUnicode_FSDecoder]
// Khung tháo gỡ #1078 | Địa chỉ PC: 0x0d9174 | Địa chỉ FDE: 0x1e1e38 | Kích thước: 256 bytes
//   0x0d9174: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d9178: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d917c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d9180: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1078_0x0d9174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9174ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e1e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1079 | PC: 0x0d9444 | FDE: 0x1e1e60 | Size: 256 bytes [PyUnicode_AsUTF8AndSize]
// Khung tháo gỡ #1079 | Địa chỉ PC: 0x0d9444 | Địa chỉ FDE: 0x1e1e60 | Kích thước: 256 bytes
//   0x0d9444: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x0d9448: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d944c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d9450: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1079_0x0d9444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9444ULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e1e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1080 | PC: 0x0d967c | FDE: 0x1e1e88 | Size: 8 bytes [PyUnicode_AsUTF8]
// Khung tháo gỡ #1080 | Địa chỉ PC: 0x0d967c | Địa chỉ FDE: 0x1e1e88 | Kích thước: 8 bytes
//   0x0d967c: AA1F03E1  mov      x1, xzr
//   0x0d9680: 17FE0D2C  b        #0x5cb30
static inline uint64_t fde_func_1080_0x0d967c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d967cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fe0d2cULL) ^ 0x1e1e88ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1081 | PC: 0x0d9684 | FDE: 0x1e1ea0 | Size: 256 bytes [PyUnicode_AsUnicodeAndSize]
// Khung tháo gỡ #1081 | Địa chỉ PC: 0x0d9684 | Địa chỉ FDE: 0x1e1ea0 | Kích thước: 256 bytes
//   0x0d9684: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d9688: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d968c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d9690: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1081_0x0d9684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9684ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e1ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1082 | PC: 0x0d983c | FDE: 0x1e1ec8 | Size: 8 bytes [PyUnicode_AsUnicode]
// Khung tháo gỡ #1082 | Địa chỉ PC: 0x0d983c | Địa chỉ FDE: 0x1e1ec8 | Kích thước: 8 bytes
//   0x0d983c: AA1F03E1  mov      x1, xzr
//   0x0d9840: 17FDFE48  b        #0x59160
static inline uint64_t fde_func_1082_0x0d983c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d983cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fdfe48ULL) ^ 0x1e1ec8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1083 | PC: 0x0d9844 | FDE: 0x1e1ee0 | Size: 112 bytes [PyUnicode_GetSize]
// Khung tháo gỡ #1083 | Địa chỉ PC: 0x0d9844 | Địa chỉ FDE: 0x1e1ee0 | Kích thước: 112 bytes
//   0x0d9844: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d9848: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d984c: 910043FD  add      x29, sp, #0x10
//   0x0d9850: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1083_0x0d9844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9844ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1ee0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1084 | PC: 0x0d98b4 | FDE: 0x1e1f00 | Size: 80 bytes [PyUnicode_GetLength]
// Khung tháo gỡ #1084 | Địa chỉ PC: 0x0d98b4 | Địa chỉ FDE: 0x1e1f00 | Kích thước: 80 bytes
//   0x0d98b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d98b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d98bc: 910043FD  add      x29, sp, #0x10
//   0x0d98c0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1084_0x0d98b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d98b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1f00ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1085 | PC: 0x0d9904 | FDE: 0x1e1f20 | Size: 196 bytes [PyUnicode_ReadChar]
// Khung tháo gỡ #1085 | Địa chỉ PC: 0x0d9904 | Địa chỉ FDE: 0x1e1f20 | Kích thước: 196 bytes
//   0x0d9904: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d9908: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d990c: 910043FD  add      x29, sp, #0x10
//   0x0d9910: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1085_0x0d9904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9904ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e1f20ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1086 | PC: 0x0d99c8 | FDE: 0x1e1f40 | Size: 256 bytes [PyUnicode_WriteChar]
// Khung tháo gỡ #1086 | Địa chỉ PC: 0x0d99c8 | Địa chỉ FDE: 0x1e1f40 | Kích thước: 256 bytes
//   0x0d99c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d99cc: 910003FD  mov      x29, sp
//   0x0d99d0: F9400408  ldr      x8, [x0, #8]
//   0x0d99d4: 3942AD09  ldrb     w9, [x8, #0xab]
static inline uint64_t fde_func_1086_0x0d99c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d99c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e1f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1087 | PC: 0x0d9b24 | FDE: 0x1e1f60 | Size: 8 bytes [PyUnicode_DecodeUTF7]
// Khung tháo gỡ #1087 | Địa chỉ PC: 0x0d9b24 | Địa chỉ FDE: 0x1e1f60 | Kích thước: 8 bytes
//   0x0d9b24: AA1F03E0  mov      x0, xzr
//   0x0d9b28: D65F03C0  ret      
static inline uint64_t fde_func_1087_0x0d9b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9b24ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e1f60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1088 | PC: 0x0d9b2c | FDE: 0x1e1f78 | Size: 256 bytes [PyUnicode_DecodeUTF7Stateful]
// Khung tháo gỡ #1088 | Địa chỉ PC: 0x0d9b2c | Địa chỉ FDE: 0x1e1f78 | Kích thước: 256 bytes
//   0x0d9b2c: D104C3FF  sub      sp, sp, #0x130
//   0x0d9b30: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0d9b34: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0d9b38: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1088_0x0d9b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9b2cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1e1f78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1089 | PC: 0x0da818 | FDE: 0x1e1fd8 | Size: 256 bytes [_PyUnicode_EncodeUTF7]
// Khung tháo gỡ #1089 | Địa chỉ PC: 0x0da818 | Địa chỉ FDE: 0x1e1fd8 | Kích thước: 256 bytes
//   0x0da818: D10203FF  sub      sp, sp, #0x80
//   0x0da81c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0da820: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0da824: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1089_0x0da818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da818ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e1fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1090 | PC: 0x0daac8 | FDE: 0x1e2008 | Size: 80 bytes [PyUnicode_EncodeUTF7]
// Khung tháo gỡ #1090 | Địa chỉ PC: 0x0daac8 | Địa chỉ FDE: 0x1e2008 | Kích thước: 80 bytes
//   0x0daac8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0daacc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0daad0: 910043FD  add      x29, sp, #0x10
//   0x0daad4: 97FDF877  bl       #0x58cb0
static inline uint64_t fde_func_1090_0x0daac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daac8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2008ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1091 | PC: 0x0dab18 | FDE: 0x1e2028 | Size: 16 bytes [PyUnicode_DecodeUTF8]
// Khung tháo gỡ #1091 | Địa chỉ PC: 0x0dab18 | Địa chỉ FDE: 0x1e2028 | Kích thước: 16 bytes
//   0x0dab18: AA0203E3  mov      x3, x2
//   0x0dab1c: 2A1F03E2  mov      w2, wzr
//   0x0dab20: AA1F03E4  mov      x4, xzr
//   0x0dab24: 17FFF54C  b        #0xd8054
static inline uint64_t fde_func_1091_0x0dab18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab18ULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x1e2028ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1092 | PC: 0x0dab28 | FDE: 0x1e2040 | Size: 256 bytes [_Py_DecodeUTF8Ex]
// Khung tháo gỡ #1092 | Địa chỉ PC: 0x0dab28 | Địa chỉ FDE: 0x1e2040 | Kích thước: 256 bytes
//   0x0dab28: D101C3FF  sub      sp, sp, #0x70
//   0x0dab2c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0dab30: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dab34: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1092_0x0dab28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab28ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e2040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1093 | PC: 0x0db090 | FDE: 0x1e2088 | Size: 224 bytes [_Py_DecodeUTF8_surrogateescape]
// Khung tháo gỡ #1093 | Địa chỉ PC: 0x0db090 | Địa chỉ FDE: 0x1e2088 | Kích thước: 224 bytes
//   0x0db090: D10103FF  sub      sp, sp, #0x40
//   0x0db094: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0db098: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0db09c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1093_0x0db090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db090ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2088ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1094 | PC: 0x0db170 | FDE: 0x1e20b0 | Size: 256 bytes [_Py_EncodeUTF8Ex]
// Khung tháo gỡ #1094 | Địa chỉ PC: 0x0db170 | Địa chỉ FDE: 0x1e20b0 | Kích thước: 256 bytes
//   0x0db170: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0db174: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0db178: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0db17c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1094_0x0db170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db170ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e20b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1095 | PC: 0x0db3b8 | FDE: 0x1e20e0 | Size: 92 bytes [PyUnicode_EncodeUTF8]
// Khung tháo gỡ #1095 | Địa chỉ PC: 0x0db3b8 | Địa chỉ FDE: 0x1e20e0 | Kích thước: 92 bytes
//   0x0db3b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0db3bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db3c0: 910043FD  add      x29, sp, #0x10
//   0x0db3c4: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1095_0x0db3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db3b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e20e0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1096 | PC: 0x0db414 | FDE: 0x1e2100 | Size: 12 bytes [PyUnicode_AsUTF8String]
// Khung tháo gỡ #1096 | Địa chỉ PC: 0x0db414 | Địa chỉ FDE: 0x1e2100 | Kích thước: 12 bytes
//   0x0db414: 2A1F03E1  mov      w1, wzr
//   0x0db418: AA1F03E2  mov      x2, xzr
//   0x0db41c: 17FFF133  b        #0xd78e8
static inline uint64_t fde_func_1096_0x0db414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db414ULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e2ULL) ^ 0x1e2100ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1097 | PC: 0x0db420 | FDE: 0x1e2118 | Size: 8 bytes [PyUnicode_DecodeUTF32]
// Khung tháo gỡ #1097 | Địa chỉ PC: 0x0db420 | Địa chỉ FDE: 0x1e2118 | Kích thước: 8 bytes
//   0x0db420: AA1F03E4  mov      x4, xzr
//   0x0db424: 17FE07FB  b        #0x5d410
static inline uint64_t fde_func_1097_0x0db420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db420ULL ^ (static_cast<uint64_t>(0xaa1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fe07fbULL) ^ 0x1e2118ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1098 | PC: 0x0db428 | FDE: 0x1e2130 | Size: 256 bytes [PyUnicode_DecodeUTF32Stateful]
// Khung tháo gỡ #1098 | Địa chỉ PC: 0x0db428 | Địa chỉ FDE: 0x1e2130 | Kích thước: 256 bytes
//   0x0db428: D10403FF  sub      sp, sp, #0x100
//   0x0db42c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0db430: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0db434: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1098_0x0db428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db428ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1e2130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1099 | PC: 0x0db998 | FDE: 0x1e2160 | Size: 256 bytes [_PyUnicodeWriter_PrepareInternal]
// Khung tháo gỡ #1099 | Địa chỉ PC: 0x0db998 | Địa chỉ FDE: 0x1e2160 | Kích thước: 256 bytes
//   0x0db998: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0db99c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db9a0: 910043FD  add      x29, sp, #0x10
//   0x0db9a4: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_1099_0x0db998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db998ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1100 | PC: 0x0dbbdc | FDE: 0x1e2180 | Size: 256 bytes [_PyUnicode_EncodeUTF32]
// Khung tháo gỡ #1100 | Địa chỉ PC: 0x0dbbdc | Địa chỉ FDE: 0x1e2180 | Kích thước: 256 bytes
//   0x0dbbdc: D10303FF  sub      sp, sp, #0xc0
//   0x0dbbe0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0dbbe4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0dbbe8: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1100_0x0dbbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbbdcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1e2180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1101 | PC: 0x0dc668 | FDE: 0x1e21e0 | Size: 48 bytes [PyUnicode_EncodeUTF32]
// Khung tháo gỡ #1101 | Địa chỉ PC: 0x0dc668 | Địa chỉ FDE: 0x1e21e0 | Kích thước: 48 bytes
//   0x0dc668: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dc66c: 910003FD  mov      x29, sp
//   0x0dc670: 97FDF190  bl       #0x58cb0
//   0x0dc674: B40000C0  cbz      x0, #0xdc68c
static inline uint64_t fde_func_1101_0x0dc668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc668ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e21e0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1102 | PC: 0x0dc698 | FDE: 0x1e2200 | Size: 8 bytes [PyUnicode_AsUTF32String]
// Khung tháo gỡ #1102 | Địa chỉ PC: 0x0dc698 | Địa chỉ FDE: 0x1e2200 | Kích thước: 8 bytes
//   0x0dc698: AA1F03E0  mov      x0, xzr
//   0x0dc69c: D65F03C0  ret      
static inline uint64_t fde_func_1102_0x0dc698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc698ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e2200ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1103 | PC: 0x0dc6a0 | FDE: 0x1e2218 | Size: 8 bytes [PyUnicode_DecodeUTF16]
// Khung tháo gỡ #1103 | Địa chỉ PC: 0x0dc6a0 | Địa chỉ FDE: 0x1e2218 | Kích thước: 8 bytes
//   0x0dc6a0: AA1F03E0  mov      x0, xzr
//   0x0dc6a4: D65F03C0  ret      
static inline uint64_t fde_func_1103_0x0dc6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc6a0ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e2218ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1104 | PC: 0x0dc6a8 | FDE: 0x1e2230 | Size: 256 bytes [PyUnicode_DecodeUTF16Stateful]
// Khung tháo gỡ #1104 | Địa chỉ PC: 0x0dc6a8 | Địa chỉ FDE: 0x1e2230 | Kích thước: 256 bytes
//   0x0dc6a8: D10403FF  sub      sp, sp, #0x100
//   0x0dc6ac: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0dc6b0: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0dc6b4: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1104_0x0dc6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc6a8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1e2230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1105 | PC: 0x0dd040 | FDE: 0x1e2260 | Size: 256 bytes [_PyUnicode_EncodeUTF16]
// Khung tháo gỡ #1105 | Địa chỉ PC: 0x0dd040 | Địa chỉ FDE: 0x1e2260 | Kích thước: 256 bytes
//   0x0dd040: D10303FF  sub      sp, sp, #0xc0
//   0x0dd044: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0dd048: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0dd04c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1105_0x0dd040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd040ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1e2260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1106 | PC: 0x0dda90 | FDE: 0x1e2290 | Size: 48 bytes [PyUnicode_EncodeUTF16]
// Khung tháo gỡ #1106 | Địa chỉ PC: 0x0dda90 | Địa chỉ FDE: 0x1e2290 | Kích thước: 48 bytes
//   0x0dda90: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dda94: 910003FD  mov      x29, sp
//   0x0dda98: 97FDEC86  bl       #0x58cb0
//   0x0dda9c: B40000C0  cbz      x0, #0xddab4
static inline uint64_t fde_func_1106_0x0dda90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dda90ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2290ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1107 | PC: 0x0ddac0 | FDE: 0x1e22b0 | Size: 8 bytes [PyUnicode_AsUTF16String]
// Khung tháo gỡ #1107 | Địa chỉ PC: 0x0ddac0 | Địa chỉ FDE: 0x1e22b0 | Kích thước: 8 bytes
//   0x0ddac0: AA1F03E0  mov      x0, xzr
//   0x0ddac4: D65F03C0  ret      
static inline uint64_t fde_func_1107_0x0ddac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddac0ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e22b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1108 | PC: 0x0ddac8 | FDE: 0x1e22c8 | Size: 256 bytes [_PyUnicode_DecodeUnicodeEscape]
// Khung tháo gỡ #1108 | Địa chỉ PC: 0x0ddac8 | Địa chỉ FDE: 0x1e22c8 | Kích thước: 256 bytes
//   0x0ddac8: D10403FF  sub      sp, sp, #0x100
//   0x0ddacc: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0ddad0: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0ddad4: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1108_0x0ddac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddac8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1e22c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1109 | PC: 0x0de6e4 | FDE: 0x1e22f8 | Size: 8 bytes [PyUnicode_DecodeUnicodeEscape]
// Khung tháo gỡ #1109 | Địa chỉ PC: 0x0de6e4 | Địa chỉ FDE: 0x1e22f8 | Kích thước: 8 bytes
//   0x0de6e4: AA1F03E0  mov      x0, xzr
//   0x0de6e8: D65F03C0  ret      
static inline uint64_t fde_func_1109_0x0de6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6e4ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e22f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1110 | PC: 0x0de6ec | FDE: 0x1e2310 | Size: 256 bytes [PyUnicode_AsUnicodeEscapeString]
// Khung tháo gỡ #1110 | Địa chỉ PC: 0x0de6ec | Địa chỉ FDE: 0x1e2310 | Kích thước: 256 bytes
//   0x0de6ec: D10103FF  sub      sp, sp, #0x40
//   0x0de6f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0de6f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0de6f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1110_0x0de6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x0de9d4 | FDE: 0x1e2338 | Size: 80 bytes [PyUnicode_EncodeUnicodeEscape]
// Khung tháo gỡ #1111 | Địa chỉ PC: 0x0de9d4 | Địa chỉ FDE: 0x1e2338 | Kích thước: 80 bytes
//   0x0de9d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0de9d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de9dc: 910043FD  add      x29, sp, #0x10
//   0x0de9e0: 97FDE8B4  bl       #0x58cb0
static inline uint64_t fde_func_1111_0x0de9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de9d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2338ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1112 | PC: 0x0dea24 | FDE: 0x1e2358 | Size: 256 bytes [PyUnicode_DecodeRawUnicodeEscape]
// Khung tháo gỡ #1112 | Địa chỉ PC: 0x0dea24 | Địa chỉ FDE: 0x1e2358 | Kích thước: 256 bytes
//   0x0dea24: D103C3FF  sub      sp, sp, #0xf0
//   0x0dea28: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0dea2c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0dea30: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1112_0x0dea24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dea24ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e2358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1113 | PC: 0x0defa4 | FDE: 0x1e2388 | Size: 256 bytes [PyUnicode_AsRawUnicodeEscapeString]
// Khung tháo gỡ #1113 | Địa chỉ PC: 0x0defa4 | Địa chỉ FDE: 0x1e2388 | Kích thước: 256 bytes
//   0x0defa4: D10103FF  sub      sp, sp, #0x40
//   0x0defa8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0defac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0defb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1113_0x0defa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0defa4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1114 | PC: 0x0df1f4 | FDE: 0x1e23b0 | Size: 48 bytes [PyUnicode_EncodeRawUnicodeEscape]
// Khung tháo gỡ #1114 | Địa chỉ PC: 0x0df1f4 | Địa chỉ FDE: 0x1e23b0 | Kích thước: 48 bytes
//   0x0df1f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0df1f8: 910003FD  mov      x29, sp
//   0x0df1fc: 97FDE6AD  bl       #0x58cb0
//   0x0df200: B40000C0  cbz      x0, #0xdf218
static inline uint64_t fde_func_1114_0x0df1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df1f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e23b0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1115 | PC: 0x0df224 | FDE: 0x1e23d0 | Size: 256 bytes [PyUnicode_EncodeLatin1]
// Khung tháo gỡ #1115 | Địa chỉ PC: 0x0df224 | Địa chỉ FDE: 0x1e23d0 | Kích thước: 256 bytes
//   0x0df224: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0df228: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df22c: 910043FD  add      x29, sp, #0x10
//   0x0df230: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1115_0x0df224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df224ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e23d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1116 | PC: 0x0df7dc | FDE: 0x1e2420 | Size: 256 bytes [PyUnicode_AsLatin1String]
// Khung tháo gỡ #1116 | Địa chỉ PC: 0x0df7dc | Địa chỉ FDE: 0x1e2420 | Kích thước: 256 bytes
//   0x0df7dc: AA1F03E1  mov      x1, xzr
//   0x0df7e0: 17FDEFE0  b        #0x5b760
//   0x0df7e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df7e8: A9017BFD  stp      x29, x30, [sp, #0x10]
static inline uint64_t fde_func_1116_0x0df7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df7dcULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fdefe0ULL) ^ 0x1e2420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1117 | PC: 0x0df910 | FDE: 0x1e2458 | Size: 52 bytes [_PyUnicodeWriter_PrepareKindInternal]
// Khung tháo gỡ #1117 | Địa chỉ PC: 0x0df910 | Địa chỉ FDE: 0x1e2458 | Kích thước: 52 bytes
//   0x0df910: 7100043F  cmp      w1, #1
//   0x0df914: 540000C0  b.eq     #0xdf92c
//   0x0df918: 7100103F  cmp      w1, #4
//   0x0df91c: 540000E0  b.eq     #0xdf938
static inline uint64_t fde_func_1117_0x0df910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df910ULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0x540000c0ULL) ^ 0x1e2458ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1118 | PC: 0x0df944 | FDE: 0x1e2470 | Size: 92 bytes [PyUnicode_EncodeASCII]
// Khung tháo gỡ #1118 | Địa chỉ PC: 0x0df944 | Địa chỉ FDE: 0x1e2470 | Kích thước: 92 bytes
//   0x0df944: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0df948: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df94c: 910043FD  add      x29, sp, #0x10
//   0x0df950: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1118_0x0df944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df944ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2470ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1119 | PC: 0x0df9a0 | FDE: 0x1e2490 | Size: 136 bytes [PyUnicode_AsASCIIString]
// Khung tháo gỡ #1119 | Địa chỉ PC: 0x0df9a0 | Địa chỉ FDE: 0x1e2490 | Kích thước: 136 bytes
//   0x0df9a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df9a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df9a8: 910043FD  add      x29, sp, #0x10
//   0x0df9ac: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1119_0x0df9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df9a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2490ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1120 | PC: 0x0dfa28 | FDE: 0x1e24b0 | Size: 256 bytes [PyUnicode_DecodeCharmap]
// Khung tháo gỡ #1120 | Địa chỉ PC: 0x0dfa28 | Địa chỉ FDE: 0x1e24b0 | Kích thước: 256 bytes
//   0x0dfa28: D103C3FF  sub      sp, sp, #0xf0
//   0x0dfa2c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0dfa30: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0dfa34: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1120_0x0dfa28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfa28ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1e24b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1121 | PC: 0x0e02ec | FDE: 0x1e24e0 | Size: 256 bytes [PyUnicode_BuildEncodingMap]
// Khung tháo gỡ #1121 | Địa chỉ PC: 0x0e02ec | Địa chỉ FDE: 0x1e24e0 | Kích thước: 256 bytes
//   0x0e02ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e02f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e02f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e02f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1121_0x0e02ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e02ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e24e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1122 | PC: 0x0e0748 | FDE: 0x1e2510 | Size: 256 bytes [_PyUnicode_EncodeCharmap]
// Khung tháo gỡ #1122 | Địa chỉ PC: 0x0e0748 | Địa chỉ FDE: 0x1e2510 | Kích thước: 256 bytes
//   0x0e0748: D10443FF  sub      sp, sp, #0x110
//   0x0e074c: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0e0750: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0e0754: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1122_0x0e0748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0748ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x1e2510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1123 | PC: 0x0e116c | FDE: 0x1e2568 | Size: 48 bytes [PyUnicode_EncodeCharmap]
// Khung tháo gỡ #1123 | Địa chỉ PC: 0x0e116c | Địa chỉ FDE: 0x1e2568 | Kích thước: 48 bytes
//   0x0e116c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e1170: 910003FD  mov      x29, sp
//   0x0e1174: 97FDDECF  bl       #0x58cb0
//   0x0e1178: B40000C0  cbz      x0, #0xe1190
static inline uint64_t fde_func_1123_0x0e116c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e116cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2568ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1124 | PC: 0x0e119c | FDE: 0x1e2588 | Size: 40 bytes [PyUnicode_AsCharmapString]
// Khung tháo gỡ #1124 | Địa chỉ PC: 0x0e119c | Địa chỉ FDE: 0x1e2588 | Kích thước: 40 bytes
//   0x0e119c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e11a0: 910003FD  mov      x29, sp
//   0x0e11a4: B4000081  cbz      x1, #0xe11b4
//   0x0e11a8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1124_0x0e119c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e119cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2588ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1125 | PC: 0x0e11c4 | FDE: 0x1e25a8 | Size: 256 bytes [PyUnicode_TranslateCharmap]
// Khung tháo gỡ #1125 | Địa chỉ PC: 0x0e11c4 | Địa chỉ FDE: 0x1e25a8 | Kích thước: 256 bytes
//   0x0e11c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e11c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e11cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e11d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1125_0x0e11c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e11c4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e25a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1126 | PC: 0x0e1c64 | FDE: 0x1e25f8 | Size: 136 bytes [PyUnicode_Translate]
// Khung tháo gỡ #1126 | Địa chỉ PC: 0x0e1c64 | Địa chỉ FDE: 0x1e25f8 | Kích thước: 136 bytes
//   0x0e1c64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1c68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1c6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1c70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1126_0x0e1c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1c64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e25f8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1127 | PC: 0x0e1cec | FDE: 0x1e2618 | Size: 256 bytes [_PyUnicode_TransformDecimalAndSpaceToASCII]
// Khung tháo gỡ #1127 | Địa chỉ PC: 0x0e1cec | Địa chỉ FDE: 0x1e2618 | Kích thước: 256 bytes
//   0x0e1cec: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e1cf0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e1cf4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1cf8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1127_0x0e1cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1cecULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e2618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1128 | PC: 0x0e1e8c | FDE: 0x1e2640 | Size: 256 bytes [PyUnicode_TransformDecimalToASCII]
// Khung tháo gỡ #1128 | Địa chỉ PC: 0x0e1e8c | Địa chỉ FDE: 0x1e2640 | Kích thước: 256 bytes
//   0x0e1e8c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e1e90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e1e94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1e98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1128_0x0e1e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1e8cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e2640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1129 | PC: 0x0e1fd0 | FDE: 0x1e2668 | Size: 256 bytes [PyUnicode_EncodeDecimal]
// Khung tháo gỡ #1129 | Địa chỉ PC: 0x0e1fd0 | Địa chỉ FDE: 0x1e2668 | Kích thước: 256 bytes
//   0x0e1fd0: D10183FF  sub      sp, sp, #0x60
//   0x0e1fd4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e1fd8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e1fdc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1129_0x0e1fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1fd0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1130 | PC: 0x0e2190 | FDE: 0x1e2698 | Size: 256 bytes [_PyUnicode_InsertThousandsGrouping]
// Khung tháo gỡ #1130 | Địa chỉ PC: 0x0e2190 | Địa chỉ FDE: 0x1e2698 | Kích thước: 256 bytes
//   0x0e2190: D10243FF  sub      sp, sp, #0x90
//   0x0e2194: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e2198: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e219c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1130_0x0e2190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2190ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e2698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1131 | PC: 0x0e251c | FDE: 0x1e26f0 | Size: 256 bytes [PyUnicode_Count]
// Khung tháo gỡ #1131 | Địa chỉ PC: 0x0e251c | Địa chỉ FDE: 0x1e26f0 | Kích thước: 256 bytes
//   0x0e251c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0e2520: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e2524: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e2528: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1131_0x0e251c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e251cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e26f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1132 | PC: 0x0e298c | FDE: 0x1e2740 | Size: 256 bytes [PyUnicode_Find]
// Khung tháo gỡ #1132 | Địa chỉ PC: 0x0e298c | Địa chỉ FDE: 0x1e2740 | Kích thước: 256 bytes
//   0x0e298c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e2990: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e2994: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e2998: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1132_0x0e298c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e298cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1133 | PC: 0x0e2f78 | FDE: 0x1e2798 | Size: 256 bytes [PyUnicode_FindChar]
// Khung tháo gỡ #1133 | Địa chỉ PC: 0x0e2f78 | Địa chỉ FDE: 0x1e2798 | Kích thước: 256 bytes
//   0x0e2f78: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e2f7c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e2f80: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e2f84: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1133_0x0e2f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2f78ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1134 | PC: 0x0e32c0 | FDE: 0x1e27c0 | Size: 256 bytes [PyUnicode_Tailmatch]
// Khung tháo gỡ #1134 | Địa chỉ PC: 0x0e32c0 | Địa chỉ FDE: 0x1e27c0 | Kích thước: 256 bytes
//   0x0e32c0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e32c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e32c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e32cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1134_0x0e32c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e32c0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e27c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1135 | PC: 0x0e3640 | FDE: 0x1e2810 | Size: 128 bytes [PyUnicode_Join]
// Khung tháo gỡ #1135 | Địa chỉ PC: 0x0e3640 | Địa chỉ FDE: 0x1e2810 | Kích thước: 128 bytes
//   0x0e3640: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e3644: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e3648: 910043FD  add      x29, sp, #0x10
//   0x0e364c: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_1135_0x0e3640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3640ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2810ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1136 | PC: 0x0e36c0 | FDE: 0x1e2830 | Size: 256 bytes [_PyUnicode_JoinArray]
// Khung tháo gỡ #1136 | Địa chỉ PC: 0x0e36c0 | Địa chỉ FDE: 0x1e2830 | Kích thước: 256 bytes
//   0x0e36c0: D101C3FF  sub      sp, sp, #0x70
//   0x0e36c4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e36c8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e36cc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1136_0x0e36c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e36c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e2830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1137 | PC: 0x0e3c3c | FDE: 0x1e2860 | Size: 132 bytes [_PyUnicode_FastFill]
// Khung tháo gỡ #1137 | Địa chỉ PC: 0x0e3c3c | Địa chỉ FDE: 0x1e2860 | Kích thước: 132 bytes
//   0x0e3c3c: B9402009  ldr      w9, [x0, #0x20]
//   0x0e3c40: 53021128  ubfx     w8, w9, #2, #3
//   0x0e3c44: 37280129  tbnz     w9, #5, #0xe3c68
//   0x0e3c48: F9402409  ldr      x9, [x0, #0x48]
static inline uint64_t fde_func_1137_0x0e3c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3c3cULL ^ (static_cast<uint64_t>(0xb9402009ULL) << 13);
    acc = (acc + a1 + 0x53021128ULL) ^ 0x1e2860ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1138 | PC: 0x0e3cc0 | FDE: 0x1e2878 | Size: 256 bytes [PyUnicode_Fill]
// Khung tháo gỡ #1138 | Địa chỉ PC: 0x0e3cc0 | Địa chỉ FDE: 0x1e2878 | Kích thước: 256 bytes
//   0x0e3cc0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e3cc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e3cc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e3ccc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1138_0x0e3cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3cc0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1139 | PC: 0x0e3e94 | FDE: 0x1e28a0 | Size: 256 bytes [PyUnicode_Splitlines]
// Khung tháo gỡ #1139 | Địa chỉ PC: 0x0e3e94 | Địa chỉ FDE: 0x1e28a0 | Kích thước: 256 bytes
//   0x0e3e94: D10243FF  sub      sp, sp, #0x90
//   0x0e3e98: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e3e9c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e3ea0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1139_0x0e3e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3e94ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e28a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1140 | PC: 0x0e45a0 | FDE: 0x1e28d0 | Size: 256 bytes [PyUnicode_Compare]
// Khung tháo gỡ #1140 | Địa chỉ PC: 0x0e45a0 | Địa chỉ FDE: 0x1e28d0 | Kích thước: 256 bytes
//   0x0e45a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e45a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e45a8: 910043FD  add      x29, sp, #0x10
//   0x0e45ac: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1140_0x0e45a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e45a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e28d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1141 | PC: 0x0e4888 | FDE: 0x1e2910 | Size: 256 bytes [PyUnicode_CompareWithASCIIString]
// Khung tháo gỡ #1141 | Địa chỉ PC: 0x0e4888 | Địa chỉ FDE: 0x1e2910 | Kích thước: 256 bytes
//   0x0e4888: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e488c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4894: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1141_0x0e4888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4888ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1142 | PC: 0x0e49f4 | FDE: 0x1e2938 | Size: 240 bytes [_PyUnicode_EqualToASCIIString]
// Khung tháo gỡ #1142 | Địa chỉ PC: 0x0e49f4 | Địa chỉ FDE: 0x1e2938 | Kích thước: 240 bytes
//   0x0e49f4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e49f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e49fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4a00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1142_0x0e49f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e49f4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2938ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1143 | PC: 0x0e4ae4 | FDE: 0x1e2958 | Size: 256 bytes [_PyUnicode_EqualToASCIIId]
// Khung tháo gỡ #1143 | Địa chỉ PC: 0x0e4ae4 | Địa chỉ FDE: 0x1e2958 | Kích thước: 256 bytes
//   0x0e4ae4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e4ae8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4aec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4af0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1143_0x0e4ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ae4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1144 | PC: 0x0e4c54 | FDE: 0x1e2978 | Size: 256 bytes [PyUnicode_RichCompare]
// Khung tháo gỡ #1144 | Địa chỉ PC: 0x0e4c54 | Địa chỉ FDE: 0x1e2978 | Kích thước: 256 bytes
//   0x0e4c54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e4c58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4c5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4c60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1144_0x0e4c54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4c54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1145 | PC: 0x0e4e28 | FDE: 0x1e2998 | Size: 156 bytes [_PyUnicode_EQ]
// Khung tháo gỡ #1145 | Địa chỉ PC: 0x0e4e28 | Địa chỉ FDE: 0x1e2998 | Kích thước: 156 bytes
//   0x0e4e28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e4e2c: 910003FD  mov      x29, sp
//   0x0e4e30: F9400808  ldr      x8, [x0, #0x10]
//   0x0e4e34: F9400829  ldr      x9, [x1, #0x10]
static inline uint64_t fde_func_1145_0x0e4e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4e28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e2998ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1146 | PC: 0x0e4ec4 | FDE: 0x1e29b8 | Size: 256 bytes [PyUnicode_Contains]
// Khung tháo gỡ #1146 | Địa chỉ PC: 0x0e4ec4 | Địa chỉ FDE: 0x1e29b8 | Kích thước: 256 bytes
//   0x0e4ec4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e4ec8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4ecc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e4ed0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1146_0x0e4ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ec4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e29b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1147 | PC: 0x0e5184 | FDE: 0x1e29e0 | Size: 256 bytes [PyUnicode_Concat]
// Khung tháo gỡ #1147 | Địa chỉ PC: 0x0e5184 | Địa chỉ FDE: 0x1e29e0 | Kích thước: 256 bytes
//   0x0e5184: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e5188: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e518c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e5190: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1147_0x0e5184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5184ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e29e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x0e5418 | FDE: 0x1e2a08 | Size: 256 bytes [PyUnicode_Append]
// Khung tháo gỡ #1148 | Địa chỉ PC: 0x0e5418 | Địa chỉ FDE: 0x1e2a08 | Kích thước: 256 bytes
//   0x0e5418: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e541c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e5420: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e5424: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1148_0x0e5418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5418ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1149 | PC: 0x0e5724 | FDE: 0x1e2a30 | Size: 68 bytes [PyUnicode_AppendAndDel]
// Khung tháo gỡ #1149 | Địa chỉ PC: 0x0e5724 | Địa chỉ FDE: 0x1e2a30 | Kích thước: 68 bytes
//   0x0e5724: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e5728: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e572c: 910043FD  add      x29, sp, #0x10
//   0x0e5730: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1149_0x0e5724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5724ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2a30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1150 | PC: 0x0e5768 | FDE: 0x1e2a50 | Size: 256 bytes [_PyUnicode_ScanIdentifier]
// Khung tháo gỡ #1150 | Địa chỉ PC: 0x0e5768 | Địa chỉ FDE: 0x1e2a50 | Kích thước: 256 bytes
//   0x0e5768: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e576c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5770: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5774: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1150_0x0e5768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5768ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1151 | PC: 0x0e587c | FDE: 0x1e2a78 | Size: 208 bytes [PyUnicode_IsIdentifier]
// Khung tháo gỡ #1151 | Địa chỉ PC: 0x0e587c | Địa chỉ FDE: 0x1e2a78 | Kích thước: 208 bytes
//   0x0e587c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e5880: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5884: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5888: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1151_0x0e587c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e587cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2a78ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1152 | PC: 0x0e594c | FDE: 0x1e2a98 | Size: 256 bytes [_PyUnicode_XStrip]
// Khung tháo gỡ #1152 | Địa chỉ PC: 0x0e594c | Địa chỉ FDE: 0x1e2a98 | Kích thước: 256 bytes
//   0x0e594c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e5950: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e5954: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e5958: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1152_0x0e594c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e594cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1153 | PC: 0x0e5d50 | FDE: 0x1e2ac8 | Size: 256 bytes [PyUnicode_Substring]
// Khung tháo gỡ #1153 | Địa chỉ PC: 0x0e5d50 | Địa chỉ FDE: 0x1e2ac8 | Kích thước: 256 bytes
//   0x0e5d50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e5d54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5d58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5d5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1153_0x0e5d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1154 | PC: 0x0e5fa4 | FDE: 0x1e2ae8 | Size: 256 bytes [PyUnicode_Replace]
// Khung tháo gỡ #1154 | Địa chỉ PC: 0x0e5fa4 | Địa chỉ FDE: 0x1e2ae8 | Kích thước: 256 bytes
//   0x0e5fa4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e5fa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5fac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5fb0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1154_0x0e5fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5fa4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1155 | PC: 0x0e766c | FDE: 0x1e2b40 | Size: 256 bytes [PyUnicode_Split]
// Khung tháo gỡ #1155 | Địa chỉ PC: 0x0e766c | Địa chỉ FDE: 0x1e2b40 | Kích thước: 256 bytes
//   0x0e766c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e7670: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e7674: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e7678: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1155_0x0e766c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e766cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2b40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1156 | PC: 0x0e8c1c | FDE: 0x1e2b90 | Size: 256 bytes [PyUnicode_Partition]
// Khung tháo gỡ #1156 | Địa chỉ PC: 0x0e8c1c | Địa chỉ FDE: 0x1e2b90 | Kích thước: 256 bytes
//   0x0e8c1c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e8c20: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e8c24: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e8c28: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1156_0x0e8c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8c1cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1157 | PC: 0x0e8ff8 | FDE: 0x1e2bc0 | Size: 256 bytes [PyUnicode_RPartition]
// Khung tháo gỡ #1157 | Địa chỉ PC: 0x0e8ff8 | Địa chỉ FDE: 0x1e2bc0 | Kích thước: 256 bytes
//   0x0e8ff8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e8ffc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e9000: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e9004: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1157_0x0e8ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8ff8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1158 | PC: 0x0e93d4 | FDE: 0x1e2bf0 | Size: 256 bytes [PyUnicode_RSplit]
// Khung tháo gỡ #1158 | Địa chỉ PC: 0x0e93d4 | Địa chỉ FDE: 0x1e2bf0 | Kích thước: 256 bytes
//   0x0e93d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e93d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e93dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e93e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1158_0x0e93d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e93d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1159 | PC: 0x0eaa94 | FDE: 0x1e2c68 | Size: 168 bytes [_PyUnicodeWriter_WriteChar]
// Khung tháo gỡ #1159 | Địa chỉ PC: 0x0eaa94 | Địa chỉ FDE: 0x1e2c68 | Kích thước: 168 bytes
//   0x0eaa94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eaa98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eaa9c: 910043FD  add      x29, sp, #0x10
//   0x0eaaa0: B9401408  ldr      w8, [x0, #0x14]
static inline uint64_t fde_func_1159_0x0eaa94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2c68ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1160 | PC: 0x0eab3c | FDE: 0x1e2c88 | Size: 256 bytes [_PyUnicodeWriter_WriteStr]
// Khung tháo gỡ #1160 | Địa chỉ PC: 0x0eab3c | Địa chỉ FDE: 0x1e2c88 | Kích thước: 256 bytes
//   0x0eab3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0eab40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eab44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eab48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1160_0x0eab3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eab3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1161 | PC: 0x0eacb8 | FDE: 0x1e2ca8 | Size: 256 bytes [_PyUnicodeWriter_WriteSubstring]
// Khung tháo gỡ #1161 | Địa chỉ PC: 0x0eacb8 | Địa chỉ FDE: 0x1e2ca8 | Kích thước: 256 bytes
//   0x0eacb8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0eacbc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0eacc0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0eacc4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1161_0x0eacb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eacb8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e2ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1162 | PC: 0x0eae08 | FDE: 0x1e2cd0 | Size: 256 bytes [_PyUnicodeWriter_WriteLatin1String]
// Khung tháo gỡ #1162 | Địa chỉ PC: 0x0eae08 | Địa chỉ FDE: 0x1e2cd0 | Kích thước: 256 bytes
//   0x0eae08: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0eae0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eae10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eae14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1162_0x0eae08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae08ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1163 | PC: 0x0eb0f8 | FDE: 0x1e2d18 | Size: 256 bytes [_PyUnicode_FormatLong]
// Khung tháo gỡ #1163 | Địa chỉ PC: 0x0eb0f8 | Địa chỉ FDE: 0x1e2d18 | Kích thước: 256 bytes
//   0x0eb0f8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0eb0fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0eb100: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0eb104: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1163_0x0eb0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb0f8ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e2d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1164 | PC: 0x0eb6cc | FDE: 0x1e2d48 | Size: 256 bytes [PyUnicode_Format]
// Khung tháo gỡ #1164 | Địa chỉ PC: 0x0eb6cc | Địa chỉ FDE: 0x1e2d48 | Kích thước: 256 bytes
//   0x0eb6cc: D10543FF  sub      sp, sp, #0x150
//   0x0eb6d0: FD0073E8  str      d8, [sp, #0xe0]
//   0x0eb6d4: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0eb6d8: A91067FA  stp      x26, x25, [sp, #0x100]
static inline uint64_t fde_func_1164_0x0eb6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb6ccULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xfd0073e8ULL) ^ 0x1e2d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1165 | PC: 0x0ede3c | FDE: 0x1e2e68 | Size: 256 bytes [_PyUnicode_Init]
// Khung tháo gỡ #1165 | Địa chỉ PC: 0x0ede3c | Địa chỉ FDE: 0x1e2e68 | Kích thước: 256 bytes
//   0x0ede3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ede40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ede44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ede48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1165_0x0ede3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ede3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2e68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1166 | PC: 0x0edf50 | FDE: 0x1e2e88 | Size: 228 bytes [_PyUnicode_InitTypes]
// Khung tháo gỡ #1166 | Địa chỉ PC: 0x0edf50 | Địa chỉ FDE: 0x1e2e88 | Kích thước: 228 bytes
//   0x0edf50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0edf54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0edf58: 910043FD  add      x29, sp, #0x10
//   0x0edf5c: D0000880  adrp     x0, #0x1ff000
static inline uint64_t fde_func_1166_0x0edf50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0edf50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2e88ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1167 | PC: 0x0ee034 | FDE: 0x1e2ea8 | Size: 128 bytes [PyUnicode_InternImmortal]
// Khung tháo gỡ #1167 | Địa chỉ PC: 0x0ee034 | Địa chỉ FDE: 0x1e2ea8 | Kích thước: 128 bytes
//   0x0ee034: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee038: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee03c: 910043FD  add      x29, sp, #0x10
//   0x0ee040: B0000888  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1167_0x0ee034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee034ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2ea8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1168 | PC: 0x0ee0b4 | FDE: 0x1e2ec8 | Size: 116 bytes [PyUnicode_InternFromString]
// Khung tháo gỡ #1168 | Địa chỉ PC: 0x0ee0b4 | Địa chỉ FDE: 0x1e2ec8 | Kích thước: 116 bytes
//   0x0ee0b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee0b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee0bc: 910043FD  add      x29, sp, #0x10
//   0x0ee0c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1168_0x0ee0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee0b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e2ec8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1169 | PC: 0x0ee128 | FDE: 0x1e2ee8 | Size: 256 bytes [_PyUnicode_ClearInterned]
// Khung tháo gỡ #1169 | Địa chỉ PC: 0x0ee128 | Địa chỉ FDE: 0x1e2ee8 | Kích thước: 256 bytes
//   0x0ee128: D10143FF  sub      sp, sp, #0x50
//   0x0ee12c: F90013F5  str      x21, [sp, #0x20]
//   0x0ee130: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ee134: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1169_0x0ee128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee128ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e2ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1170 | PC: 0x0ee330 | FDE: 0x1e2f68 | Size: 256 bytes [_PyUnicode_InitEncodings]
// Khung tháo gỡ #1170 | Địa chỉ PC: 0x0ee330 | Địa chỉ FDE: 0x1e2f68 | Kích thước: 256 bytes
//   0x0ee330: D10143FF  sub      sp, sp, #0x50
//   0x0ee334: F9000BF7  str      x23, [sp, #0x10]
//   0x0ee338: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ee33c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1170_0x0ee330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee330ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1e2f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x0ee548 | FDE: 0x1e2f90 | Size: 256 bytes [_PyUnicode_Fini]
// Khung tháo gỡ #1171 | Địa chỉ PC: 0x0ee548 | Địa chỉ FDE: 0x1e2f90 | Kích thước: 256 bytes
//   0x0ee548: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ee54c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ee550: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ee554: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1171_0x0ee548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee548ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e2f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1172 | PC: 0x0ee650 | FDE: 0x1e2fb0 | Size: 256 bytes [PyInit__string]
// Khung tháo gỡ #1172 | Địa chỉ PC: 0x0ee650 | Địa chỉ FDE: 0x1e2fb0 | Kích thước: 256 bytes
//   0x0ee650: F0000920  adrp     x0, #0x215000
//   0x0ee654: 91134000  add      x0, x0, #0x4d0
//   0x0ee658: 17FDA8F2  b        #0x58a20
//   0x0ee65c: D10483FF  sub      sp, sp, #0x120
static inline uint64_t fde_func_1172_0x0ee650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee650ULL ^ (static_cast<uint64_t>(0xf0000920ULL) << 13);
    acc = (acc + a1 + 0x91134000ULL) ^ 0x1e2fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1173 | PC: 0x0f8dbc | FDE: 0x1e3e60 | Size: 256 bytes [_PyUnicode_ToNumeric]
// Khung tháo gỡ #1173 | Địa chỉ PC: 0x0f8dbc | Địa chỉ FDE: 0x1e3e60 | Kích thước: 256 bytes
//   0x0f8dbc: 52810AE8  mov      w8, #0x857
//   0x0f8dc0: 72A00028  movk     w8, #1, lsl #16
//   0x0f8dc4: 6B08001F  cmp      w0, w8
//   0x0f8dc8: 540002EC  b.gt     #0xf8e24
static inline uint64_t fde_func_1173_0x0f8dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8dbcULL ^ (static_cast<uint64_t>(0x52810ae8ULL) << 13);
    acc = (acc + a1 + 0x72a00028ULL) ^ 0x1e3e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1174 | PC: 0x0f9de4 | FDE: 0x1e3e78 | Size: 144 bytes [_PyUnicode_IsWhitespace]
// Khung tháo gỡ #1174 | Địa chỉ PC: 0x0f9de4 | Địa chỉ FDE: 0x1e3e78 | Kích thước: 144 bytes
//   0x0f9de4: 5282CFE9  mov      w9, #0x167f
//   0x0f9de8: 2A0003E8  mov      w8, w0
//   0x0f9dec: 6B09001F  cmp      w0, w9
//   0x0f9df0: 52800020  mov      w0, #1
static inline uint64_t fde_func_1174_0x0f9de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9de4ULL ^ (static_cast<uint64_t>(0x5282cfe9ULL) << 13);
    acc = (acc + a1 + 0x2a0003e8ULL) ^ 0x1e3e78ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1175 | PC: 0x0f9e74 | FDE: 0x1e3e90 | Size: 72 bytes [_PyUnicode_IsLinebreak]
// Khung tháo gỡ #1175 | Địa chỉ PC: 0x0f9e74 | Địa chỉ FDE: 0x1e3e90 | Kích thước: 72 bytes
//   0x0f9e74: 2A0003E8  mov      w8, w0
//   0x0f9e78: 7100781F  cmp      w0, #0x1e
//   0x0f9e7c: 52800020  mov      w0, #1
//   0x0f9e80: 540000C8  b.hi     #0xf9e98
static inline uint64_t fde_func_1175_0x0f9e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9e74ULL ^ (static_cast<uint64_t>(0x2a0003e8ULL) << 13);
    acc = (acc + a1 + 0x7100781fULL) ^ 0x1e3e90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1176 | PC: 0x0f9ebc | FDE: 0x1e3ea8 | Size: 124 bytes [_PyUnicode_ToTitlecase]
// Khung tháo gỡ #1176 | Địa chỉ PC: 0x0f9ebc | Địa chỉ FDE: 0x1e3ea8 | Kích thước: 124 bytes
//   0x0f9ebc: 53107C08  lsr      w8, w0, #0x10
//   0x0f9ec0: 7100411F  cmp      w8, #0x10
//   0x0f9ec4: 54000069  b.ls     #0xf9ed0
//   0x0f9ec8: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1176_0x0f9ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9ebcULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ea8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1177 | PC: 0x0f9f38 | FDE: 0x1e3ec0 | Size: 88 bytes [_PyUnicode_IsTitlecase]
// Khung tháo gỡ #1177 | Địa chỉ PC: 0x0f9f38 | Địa chỉ FDE: 0x1e3ec0 | Kích thước: 88 bytes
//   0x0f9f38: 53107C08  lsr      w8, w0, #0x10
//   0x0f9f3c: 7100411F  cmp      w8, #0x10
//   0x0f9f40: 54000069  b.ls     #0xf9f4c
//   0x0f9f44: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1177_0x0f9f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9f38ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ec0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1178 | PC: 0x0f9f90 | FDE: 0x1e3ed8 | Size: 88 bytes [_PyUnicode_IsXidStart]
// Khung tháo gỡ #1178 | Địa chỉ PC: 0x0f9f90 | Địa chỉ FDE: 0x1e3ed8 | Kích thước: 88 bytes
//   0x0f9f90: 53107C08  lsr      w8, w0, #0x10
//   0x0f9f94: 7100411F  cmp      w8, #0x10
//   0x0f9f98: 54000069  b.ls     #0xf9fa4
//   0x0f9f9c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1178_0x0f9f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9f90ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ed8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1179 | PC: 0x0f9fe8 | FDE: 0x1e3ef0 | Size: 256 bytes [_PyUnicode_IsXidContinue]
// Khung tháo gỡ #1179 | Địa chỉ PC: 0x0f9fe8 | Địa chỉ FDE: 0x1e3ef0 | Kích thước: 256 bytes
//   0x0f9fe8: 53107C08  lsr      w8, w0, #0x10
//   0x0f9fec: 7100411F  cmp      w8, #0x10
//   0x0f9ff0: 54000069  b.ls     #0xf9ffc
//   0x0f9ff4: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1179_0x0f9fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9fe8ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1180 | PC: 0x0fb040 | FDE: 0x1e3f08 | Size: 100 bytes [_PyUnicode_ToDecimalDigit]
// Khung tháo gỡ #1180 | Địa chỉ PC: 0x0fb040 | Địa chỉ FDE: 0x1e3f08 | Kích thước: 100 bytes
//   0x0fb040: 53107C08  lsr      w8, w0, #0x10
//   0x0fb044: 7100411F  cmp      w8, #0x10
//   0x0fb048: 54000069  b.ls     #0xfb054
//   0x0fb04c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1180_0x0fb040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb040ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f08ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1181 | PC: 0x0fb0a4 | FDE: 0x1e3f20 | Size: 88 bytes [_PyUnicode_IsDecimalDigit]
// Khung tháo gỡ #1181 | Địa chỉ PC: 0x0fb0a4 | Địa chỉ FDE: 0x1e3f20 | Kích thước: 88 bytes
//   0x0fb0a4: 53107C08  lsr      w8, w0, #0x10
//   0x0fb0a8: 7100411F  cmp      w8, #0x10
//   0x0fb0ac: 54000069  b.ls     #0xfb0b8
//   0x0fb0b0: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1181_0x0fb0a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb0a4ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f20ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1182 | PC: 0x0fb0fc | FDE: 0x1e3f38 | Size: 100 bytes [_PyUnicode_ToDigit]
// Khung tháo gỡ #1182 | Địa chỉ PC: 0x0fb0fc | Địa chỉ FDE: 0x1e3f38 | Kích thước: 100 bytes
//   0x0fb0fc: 53107C08  lsr      w8, w0, #0x10
//   0x0fb100: 7100411F  cmp      w8, #0x10
//   0x0fb104: 54000069  b.ls     #0xfb110
//   0x0fb108: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1182_0x0fb0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb0fcULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1183 | PC: 0x0fb160 | FDE: 0x1e3f50 | Size: 88 bytes [_PyUnicode_IsDigit]
// Khung tháo gỡ #1183 | Địa chỉ PC: 0x0fb160 | Địa chỉ FDE: 0x1e3f50 | Kích thước: 88 bytes
//   0x0fb160: 53107C08  lsr      w8, w0, #0x10
//   0x0fb164: 7100411F  cmp      w8, #0x10
//   0x0fb168: 54000069  b.ls     #0xfb174
//   0x0fb16c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1183_0x0fb160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb160ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f50ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1184 | PC: 0x0fb1b8 | FDE: 0x1e3f68 | Size: 88 bytes [_PyUnicode_IsNumeric]
// Khung tháo gỡ #1184 | Địa chỉ PC: 0x0fb1b8 | Địa chỉ FDE: 0x1e3f68 | Kích thước: 88 bytes
//   0x0fb1b8: 53107C08  lsr      w8, w0, #0x10
//   0x0fb1bc: 7100411F  cmp      w8, #0x10
//   0x0fb1c0: 54000069  b.ls     #0xfb1cc
//   0x0fb1c4: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1184_0x0fb1b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb1b8ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f68ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1185 | PC: 0x0fb210 | FDE: 0x1e3f80 | Size: 88 bytes [_PyUnicode_IsPrintable]
// Khung tháo gỡ #1185 | Địa chỉ PC: 0x0fb210 | Địa chỉ FDE: 0x1e3f80 | Kích thước: 88 bytes
//   0x0fb210: 53107C08  lsr      w8, w0, #0x10
//   0x0fb214: 7100411F  cmp      w8, #0x10
//   0x0fb218: 54000069  b.ls     #0xfb224
//   0x0fb21c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1185_0x0fb210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb210ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f80ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1186 | PC: 0x0fb268 | FDE: 0x1e3f98 | Size: 88 bytes [_PyUnicode_IsLowercase]
// Khung tháo gỡ #1186 | Địa chỉ PC: 0x0fb268 | Địa chỉ FDE: 0x1e3f98 | Kích thước: 88 bytes
//   0x0fb268: 53107C08  lsr      w8, w0, #0x10
//   0x0fb26c: 7100411F  cmp      w8, #0x10
//   0x0fb270: 54000069  b.ls     #0xfb27c
//   0x0fb274: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1186_0x0fb268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb268ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3f98ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1187 | PC: 0x0fb2c0 | FDE: 0x1e3fb0 | Size: 88 bytes [_PyUnicode_IsUppercase]
// Khung tháo gỡ #1187 | Địa chỉ PC: 0x0fb2c0 | Địa chỉ FDE: 0x1e3fb0 | Kích thước: 88 bytes
//   0x0fb2c0: 53107C08  lsr      w8, w0, #0x10
//   0x0fb2c4: 7100411F  cmp      w8, #0x10
//   0x0fb2c8: 54000069  b.ls     #0xfb2d4
//   0x0fb2cc: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1187_0x0fb2c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb2c0ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3fb0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1188 | PC: 0x0fb318 | FDE: 0x1e3fc8 | Size: 124 bytes [_PyUnicode_ToUppercase]
// Khung tháo gỡ #1188 | Địa chỉ PC: 0x0fb318 | Địa chỉ FDE: 0x1e3fc8 | Kích thước: 124 bytes
//   0x0fb318: 53107C08  lsr      w8, w0, #0x10
//   0x0fb31c: 7100411F  cmp      w8, #0x10
//   0x0fb320: 54000069  b.ls     #0xfb32c
//   0x0fb324: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1188_0x0fb318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb318ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3fc8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1189 | PC: 0x0fb394 | FDE: 0x1e3fe0 | Size: 124 bytes [_PyUnicode_ToLowercase]
// Khung tháo gỡ #1189 | Địa chỉ PC: 0x0fb394 | Địa chỉ FDE: 0x1e3fe0 | Kích thước: 124 bytes
//   0x0fb394: 53107C08  lsr      w8, w0, #0x10
//   0x0fb398: 7100411F  cmp      w8, #0x10
//   0x0fb39c: 54000069  b.ls     #0xfb3a8
//   0x0fb3a0: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1189_0x0fb394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb394ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3fe0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1190 | PC: 0x0fb410 | FDE: 0x1e3ff8 | Size: 256 bytes [_PyUnicode_ToLowerFull]
// Khung tháo gỡ #1190 | Địa chỉ PC: 0x0fb410 | Địa chỉ FDE: 0x1e3ff8 | Kích thước: 256 bytes
//   0x0fb410: 53107C08  lsr      w8, w0, #0x10
//   0x0fb414: 7100411F  cmp      w8, #0x10
//   0x0fb418: 54000069  b.ls     #0xfb424
//   0x0fb41c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1190_0x0fb410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb410ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e3ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1191 | PC: 0x0fb530 | FDE: 0x1e4010 | Size: 256 bytes [_PyUnicode_ToTitleFull]
// Khung tháo gỡ #1191 | Địa chỉ PC: 0x0fb530 | Địa chỉ FDE: 0x1e4010 | Kích thước: 256 bytes
//   0x0fb530: 53107C08  lsr      w8, w0, #0x10
//   0x0fb534: 7100411F  cmp      w8, #0x10
//   0x0fb538: 54000069  b.ls     #0xfb544
//   0x0fb53c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1191_0x0fb530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb530ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1192 | PC: 0x0fb650 | FDE: 0x1e4028 | Size: 256 bytes [_PyUnicode_ToUpperFull]
// Khung tháo gỡ #1192 | Địa chỉ PC: 0x0fb650 | Địa chỉ FDE: 0x1e4028 | Kích thước: 256 bytes
//   0x0fb650: 53107C08  lsr      w8, w0, #0x10
//   0x0fb654: 7100411F  cmp      w8, #0x10
//   0x0fb658: 54000069  b.ls     #0xfb664
//   0x0fb65c: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1192_0x0fb650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb650ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1193 | PC: 0x0fb770 | FDE: 0x1e4040 | Size: 256 bytes [_PyUnicode_ToFoldedFull]
// Khung tháo gỡ #1193 | Địa chỉ PC: 0x0fb770 | Địa chỉ FDE: 0x1e4040 | Kích thước: 256 bytes
//   0x0fb770: 90000829  adrp     x9, #0x1ff000
//   0x0fb774: 9000082B  adrp     x11, #0x1ff000
//   0x0fb778: F9449129  ldr      x9, [x9, #0x920]
//   0x0fb77c: F947156B  ldr      x11, [x11, #0xe28]
static inline uint64_t fde_func_1193_0x0fb770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb770ULL ^ (static_cast<uint64_t>(0x90000829ULL) << 13);
    acc = (acc + a1 + 0x9000082bULL) ^ 0x1e4040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1194 | PC: 0x0fb904 | FDE: 0x1e4058 | Size: 88 bytes [_PyUnicode_IsCased]
// Khung tháo gỡ #1194 | Địa chỉ PC: 0x0fb904 | Địa chỉ FDE: 0x1e4058 | Kích thước: 88 bytes
//   0x0fb904: 53107C08  lsr      w8, w0, #0x10
//   0x0fb908: 7100411F  cmp      w8, #0x10
//   0x0fb90c: 54000069  b.ls     #0xfb918
//   0x0fb910: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1194_0x0fb904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb904ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4058ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1195 | PC: 0x0fb95c | FDE: 0x1e4070 | Size: 88 bytes [_PyUnicode_IsCaseIgnorable]
// Khung tháo gỡ #1195 | Địa chỉ PC: 0x0fb95c | Địa chỉ FDE: 0x1e4070 | Kích thước: 88 bytes
//   0x0fb95c: 53107C08  lsr      w8, w0, #0x10
//   0x0fb960: 7100411F  cmp      w8, #0x10
//   0x0fb964: 54000069  b.ls     #0xfb970
//   0x0fb968: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1195_0x0fb95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb95cULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4070ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1196 | PC: 0x0fb9b4 | FDE: 0x1e4088 | Size: 88 bytes [_PyUnicode_IsAlpha]
// Khung tháo gỡ #1196 | Địa chỉ PC: 0x0fb9b4 | Địa chỉ FDE: 0x1e4088 | Kích thước: 88 bytes
//   0x0fb9b4: 53107C08  lsr      w8, w0, #0x10
//   0x0fb9b8: 7100411F  cmp      w8, #0x10
//   0x0fb9bc: 54000069  b.ls     #0xfb9c8
//   0x0fb9c0: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1196_0x0fb9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb9b4ULL ^ (static_cast<uint64_t>(0x53107c08ULL) << 13);
    acc = (acc + a1 + 0x7100411fULL) ^ 0x1e4088ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1197 | PC: 0x0fba0c | FDE: 0x1e40a0 | Size: 256 bytes [_Py_union_type_or]
// Khung tháo gỡ #1197 | Địa chỉ PC: 0x0fba0c | Địa chỉ FDE: 0x1e40a0 | Kích thước: 256 bytes
//   0x0fba0c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fba10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fba14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fba18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1197_0x0fba0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fba0cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e40a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1198 | PC: 0x0fc788 | FDE: 0x1e4260 | Size: 28 bytes [_PyWeakref_GetWeakrefCount]
// Khung tháo gỡ #1198 | Địa chỉ PC: 0x0fc788 | Địa chỉ FDE: 0x1e4260 | Kích thước: 28 bytes
//   0x0fc788: AA1F03E8  mov      x8, xzr
//   0x0fc78c: B4000080  cbz      x0, #0xfc79c
//   0x0fc790: F9401800  ldr      x0, [x0, #0x30]
//   0x0fc794: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_1198_0x0fc788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc788ULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1e4260ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1199 | PC: 0x0fc7a4 | FDE: 0x1e4278 | Size: 256 bytes [_PyWeakref_ClearRef]
// Khung tháo gỡ #1199 | Địa chỉ PC: 0x0fc7a4 | Địa chỉ FDE: 0x1e4278 | Kích thước: 256 bytes
//   0x0fc7a4: F000080A  adrp     x10, #0x1ff000
//   0x0fc7a8: A9412009  ldp      x9, x8, [x0, #0x10]
//   0x0fc7ac: F945F14A  ldr      x10, [x10, #0xbe0]
//   0x0fc7b0: F9000C1F  str      xzr, [x0, #0x18]
static inline uint64_t fde_func_1199_0x0fc7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc7a4ULL ^ (static_cast<uint64_t>(0xf000080aULL) << 13);
    acc = (acc + a1 + 0xa9412009ULL) ^ 0x1e4278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 800: return fde_func_0800_0x0a7d18(a0, a1);
        case 801: return fde_func_0801_0x0a7d54(a0, a1);
        case 802: return fde_func_0802_0x0a7e7c(a0, a1);
        case 803: return fde_func_0803_0x0a7f90(a0, a1);
        case 804: return fde_func_0804_0x0a820c(a0, a1);
        case 805: return fde_func_0805_0x0a8290(a0, a1);
        case 806: return fde_func_0806_0x0a82f0(a0, a1);
        case 807: return fde_func_0807_0x0a83b8(a0, a1);
        case 808: return fde_func_0808_0x0a8430(a0, a1);
        case 809: return fde_func_0809_0x0a8da8(a0, a1);
        case 810: return fde_func_0810_0x0a8e0c(a0, a1);
        case 811: return fde_func_0811_0x0a8e54(a0, a1);
        case 812: return fde_func_0812_0x0a8ef4(a0, a1);
        case 813: return fde_func_0813_0x0a8f34(a0, a1);
        case 814: return fde_func_0814_0x0a9780(a0, a1);
        case 815: return fde_func_0815_0x0a9804(a0, a1);
        case 816: return fde_func_0816_0x0a9e90(a0, a1);
        case 817: return fde_func_0817_0x0a9ed0(a0, a1);
        case 818: return fde_func_0818_0x0aa00c(a0, a1);
        case 819: return fde_func_0819_0x0aa2c8(a0, a1);
        case 820: return fde_func_0820_0x0aa2cc(a0, a1);
        case 821: return fde_func_0821_0x0ab80c(a0, a1);
        case 822: return fde_func_0822_0x0abcdc(a0, a1);
        case 823: return fde_func_0823_0x0abd84(a0, a1);
        case 824: return fde_func_0824_0x0abeac(a0, a1);
        case 825: return fde_func_0825_0x0ac330(a0, a1);
        case 826: return fde_func_0826_0x0b071c(a0, a1);
        case 827: return fde_func_0827_0x0b0728(a0, a1);
        case 828: return fde_func_0828_0x0b0730(a0, a1);
        case 829: return fde_func_0829_0x0b0dd8(a0, a1);
        case 830: return fde_func_0830_0x0b0e38(a0, a1);
        case 831: return fde_func_0831_0x0b0ea0(a0, a1);
        case 832: return fde_func_0832_0x0b0f00(a0, a1);
        case 833: return fde_func_0833_0x0b1540(a0, a1);
        case 834: return fde_func_0834_0x0b159c(a0, a1);
        case 835: return fde_func_0835_0x0b15fc(a0, a1);
        case 836: return fde_func_0836_0x0b17b4(a0, a1);
        case 837: return fde_func_0837_0x0b1864(a0, a1);
        case 838: return fde_func_0838_0x0b18d4(a0, a1);
        case 839: return fde_func_0839_0x0b1aa0(a0, a1);
        case 840: return fde_func_0840_0x0b1b94(a0, a1);
        case 841: return fde_func_0841_0x0b1c08(a0, a1);
        case 842: return fde_func_0842_0x0b1ffc(a0, a1);
        case 843: return fde_func_0843_0x0b2140(a0, a1);
        case 844: return fde_func_0844_0x0b218c(a0, a1);
        case 845: return fde_func_0845_0x0b2244(a0, a1);
        case 846: return fde_func_0846_0x0b22a0(a0, a1);
        case 847: return fde_func_0847_0x0b234c(a0, a1);
        case 848: return fde_func_0848_0x0b239c(a0, a1);
        case 849: return fde_func_0849_0x0b23ec(a0, a1);
        case 850: return fde_func_0850_0x0b243c(a0, a1);
        case 851: return fde_func_0851_0x0b244c(a0, a1);
        case 852: return fde_func_0852_0x0b27c8(a0, a1);
        case 853: return fde_func_0853_0x0b2830(a0, a1);
        case 854: return fde_func_0854_0x0b362c(a0, a1);
        case 855: return fde_func_0855_0x0b3708(a0, a1);
        case 856: return fde_func_0856_0x0b37bc(a0, a1);
        case 857: return fde_func_0857_0x0b3848(a0, a1);
        case 858: return fde_func_0858_0x0b396c(a0, a1);
        case 859: return fde_func_0859_0x0b3980(a0, a1);
        case 860: return fde_func_0860_0x0b39a4(a0, a1);
        case 861: return fde_func_0861_0x0b39b4(a0, a1);
        case 862: return fde_func_0862_0x0b39d4(a0, a1);
        case 863: return fde_func_0863_0x0b3a00(a0, a1);
        case 864: return fde_func_0864_0x0b3a2c(a0, a1);
        case 865: return fde_func_0865_0x0b3a80(a0, a1);
        case 866: return fde_func_0866_0x0b3ae4(a0, a1);
        case 867: return fde_func_0867_0x0b3b38(a0, a1);
        case 868: return fde_func_0868_0x0b3ba4(a0, a1);
        case 869: return fde_func_0869_0x0b3bb0(a0, a1);
        case 870: return fde_func_0870_0x0b3bc4(a0, a1);
        case 871: return fde_func_0871_0x0b3d70(a0, a1);
        case 872: return fde_func_0872_0x0b3ecc(a0, a1);
        case 873: return fde_func_0873_0x0b4000(a0, a1);
        case 874: return fde_func_0874_0x0b4004(a0, a1);
        case 875: return fde_func_0875_0x0b4160(a0, a1);
        case 876: return fde_func_0876_0x0b4208(a0, a1);
        case 877: return fde_func_0877_0x0b4370(a0, a1);
        case 878: return fde_func_0878_0x0b44a4(a0, a1);
        case 879: return fde_func_0879_0x0b44f0(a0, a1);
        case 880: return fde_func_0880_0x0b459c(a0, a1);
        case 881: return fde_func_0881_0x0b47d4(a0, a1);
        case 882: return fde_func_0882_0x0b4878(a0, a1);
        case 883: return fde_func_0883_0x0b48ac(a0, a1);
        case 884: return fde_func_0884_0x0b4928(a0, a1);
        case 885: return fde_func_0885_0x0b49ac(a0, a1);
        case 886: return fde_func_0886_0x0b4a74(a0, a1);
        case 887: return fde_func_0887_0x0b4ab8(a0, a1);
        case 888: return fde_func_0888_0x0b4b54(a0, a1);
        case 889: return fde_func_0889_0x0b4d14(a0, a1);
        case 890: return fde_func_0890_0x0b4d94(a0, a1);
        case 891: return fde_func_0891_0x0b4dd0(a0, a1);
        case 892: return fde_func_0892_0x0b4f0c(a0, a1);
        case 893: return fde_func_0893_0x0b5014(a0, a1);
        case 894: return fde_func_0894_0x0b5020(a0, a1);
        case 895: return fde_func_0895_0x0b52ac(a0, a1);
        case 896: return fde_func_0896_0x0b5304(a0, a1);
        case 897: return fde_func_0897_0x0b5344(a0, a1);
        case 898: return fde_func_0898_0x0b5354(a0, a1);
        case 899: return fde_func_0899_0x0b5388(a0, a1);
        case 900: return fde_func_0900_0x0b558c(a0, a1);
        case 901: return fde_func_0901_0x0b578c(a0, a1);
        case 902: return fde_func_0902_0x0b5794(a0, a1);
        case 903: return fde_func_0903_0x0b5858(a0, a1);
        case 904: return fde_func_0904_0x0b5878(a0, a1);
        case 905: return fde_func_0905_0x0b5890(a0, a1);
        case 906: return fde_func_0906_0x0b5b1c(a0, a1);
        case 907: return fde_func_0907_0x0b6894(a0, a1);
        case 908: return fde_func_0908_0x0b68d0(a0, a1);
        case 909: return fde_func_0909_0x0b69a4(a0, a1);
        case 910: return fde_func_0910_0x0b6a58(a0, a1);
        case 911: return fde_func_0911_0x0b6aa4(a0, a1);
        case 912: return fde_func_0912_0x0b6adc(a0, a1);
        case 913: return fde_func_0913_0x0b6b48(a0, a1);
        case 914: return fde_func_0914_0x0b6ba8(a0, a1);
        case 915: return fde_func_0915_0x0b6c04(a0, a1);
        case 916: return fde_func_0916_0x0b6c28(a0, a1);
        case 917: return fde_func_0917_0x0b6c3c(a0, a1);
        case 918: return fde_func_0918_0x0b6c48(a0, a1);
        case 919: return fde_func_0919_0x0b6c58(a0, a1);
        case 920: return fde_func_0920_0x0b6c68(a0, a1);
        case 921: return fde_func_0921_0x0b6c7c(a0, a1);
        case 922: return fde_func_0922_0x0b6c88(a0, a1);
        case 923: return fde_func_0923_0x0b6c9c(a0, a1);
        case 924: return fde_func_0924_0x0b6cb0(a0, a1);
        case 925: return fde_func_0925_0x0b6d10(a0, a1);
        case 926: return fde_func_0926_0x0b6e1c(a0, a1);
        case 927: return fde_func_0927_0x0b6ec4(a0, a1);
        case 928: return fde_func_0928_0x0b70fc(a0, a1);
        case 929: return fde_func_0929_0x0b7154(a0, a1);
        case 930: return fde_func_0930_0x0b7258(a0, a1);
        case 931: return fde_func_0931_0x0b7884(a0, a1);
        case 932: return fde_func_0932_0x0b78dc(a0, a1);
        case 933: return fde_func_0933_0x0b78f8(a0, a1);
        case 934: return fde_func_0934_0x0b7914(a0, a1);
        case 935: return fde_func_0935_0x0b7934(a0, a1);
        case 936: return fde_func_0936_0x0b796c(a0, a1);
        case 937: return fde_func_0937_0x0b7994(a0, a1);
        case 938: return fde_func_0938_0x0b79b0(a0, a1);
        case 939: return fde_func_0939_0x0b79d0(a0, a1);
        case 940: return fde_func_0940_0x0b7a08(a0, a1);
        case 941: return fde_func_0941_0x0b7a30(a0, a1);
        case 942: return fde_func_0942_0x0b7a4c(a0, a1);
        case 943: return fde_func_0943_0x0b7ac4(a0, a1);
        case 944: return fde_func_0944_0x0b7b2c(a0, a1);
        case 945: return fde_func_0945_0x0b7b94(a0, a1);
        case 946: return fde_func_0946_0x0b7bb4(a0, a1);
        case 947: return fde_func_0947_0x0b7bec(a0, a1);
        case 948: return fde_func_0948_0x0b7c14(a0, a1);
        case 949: return fde_func_0949_0x0b7c30(a0, a1);
        case 950: return fde_func_0950_0x0b7c38(a0, a1);
        case 951: return fde_func_0951_0x0b82a4(a0, a1);
        case 952: return fde_func_0952_0x0b831c(a0, a1);
        case 953: return fde_func_0953_0x0b8390(a0, a1);
        case 954: return fde_func_0954_0x0badf8(a0, a1);
        case 955: return fde_func_0955_0x0bae88(a0, a1);
        case 956: return fde_func_0956_0x0baf18(a0, a1);
        case 957: return fde_func_0957_0x0baf98(a0, a1);
        case 958: return fde_func_0958_0x0baffc(a0, a1);
        case 959: return fde_func_0959_0x0bb0d0(a0, a1);
        case 960: return fde_func_0960_0x0bb1b4(a0, a1);
        case 961: return fde_func_0961_0x0bb288(a0, a1);
        case 962: return fde_func_0962_0x0bb38c(a0, a1);
        case 963: return fde_func_0963_0x0bb518(a0, a1);
        case 964: return fde_func_0964_0x0beaa4(a0, a1);
        case 965: return fde_func_0965_0x0beabc(a0, a1);
        case 966: return fde_func_0966_0x0beb74(a0, a1);
        case 967: return fde_func_0967_0x0bec80(a0, a1);
        case 968: return fde_func_0968_0x0bed98(a0, a1);
        case 969: return fde_func_0969_0x0bee90(a0, a1);
        case 970: return fde_func_0970_0x0bef5c(a0, a1);
        case 971: return fde_func_0971_0x0bf080(a0, a1);
        case 972: return fde_func_0972_0x0bfa28(a0, a1);
        case 973: return fde_func_0973_0x0bfb48(a0, a1);
        case 974: return fde_func_0974_0x0bfb54(a0, a1);
        case 975: return fde_func_0975_0x0bfb60(a0, a1);
        case 976: return fde_func_0976_0x0c0770(a0, a1);
        case 977: return fde_func_0977_0x0c0778(a0, a1);
        case 978: return fde_func_0978_0x0c0780(a0, a1);
        case 979: return fde_func_0979_0x0c09cc(a0, a1);
        case 980: return fde_func_0980_0x0c0c0c(a0, a1);
        case 981: return fde_func_0981_0x0c0ce0(a0, a1);
        case 982: return fde_func_0982_0x0c0e10(a0, a1);
        case 983: return fde_func_0983_0x0c0e4c(a0, a1);
        case 984: return fde_func_0984_0x0c0eb8(a0, a1);
        case 985: return fde_func_0985_0x0c0f88(a0, a1);
        case 986: return fde_func_0986_0x0c1018(a0, a1);
        case 987: return fde_func_0987_0x0c1130(a0, a1);
        case 988: return fde_func_0988_0x0c11b0(a0, a1);
        case 989: return fde_func_0989_0x0c19d0(a0, a1);
        case 990: return fde_func_0990_0x0c1b94(a0, a1);
        case 991: return fde_func_0991_0x0c1bfc(a0, a1);
        case 992: return fde_func_0992_0x0c1c80(a0, a1);
        case 993: return fde_func_0993_0x0c27b4(a0, a1);
        case 994: return fde_func_0994_0x0c2814(a0, a1);
        case 995: return fde_func_0995_0x0c296c(a0, a1);
        case 996: return fde_func_0996_0x0c29d8(a0, a1);
        case 997: return fde_func_0997_0x0c2b1c(a0, a1);
        case 998: return fde_func_0998_0x0c2b58(a0, a1);
        case 999: return fde_func_0999_0x0c2bb4(a0, a1);
        case 1000: return fde_func_1000_0x0c2c50(a0, a1);
        case 1001: return fde_func_1001_0x0c2d48(a0, a1);
        case 1002: return fde_func_1002_0x0c2d80(a0, a1);
        case 1003: return fde_func_1003_0x0c2db8(a0, a1);
        case 1004: return fde_func_1004_0x0c2e68(a0, a1);
        case 1005: return fde_func_1005_0x0c2e74(a0, a1);
        case 1006: return fde_func_1006_0x0c2ed8(a0, a1);
        case 1007: return fde_func_1007_0x0c2f2c(a0, a1);
        case 1008: return fde_func_1008_0x0c2f94(a0, a1);
        case 1009: return fde_func_1009_0x0c2fd0(a0, a1);
        case 1010: return fde_func_1010_0x0c2fd8(a0, a1);
        case 1011: return fde_func_1011_0x0c30a0(a0, a1);
        case 1012: return fde_func_1012_0x0c30f8(a0, a1);
        case 1013: return fde_func_1013_0x0c3a40(a0, a1);
        case 1014: return fde_func_1014_0x0c3a9c(a0, a1);
        case 1015: return fde_func_1015_0x0c3aa4(a0, a1);
        case 1016: return fde_func_1016_0x0c3ae0(a0, a1);
        case 1017: return fde_func_1017_0x0c3b44(a0, a1);
        case 1018: return fde_func_1018_0x0c3b98(a0, a1);
        case 1019: return fde_func_1019_0x0c3bb4(a0, a1);
        case 1020: return fde_func_1020_0x0c3c20(a0, a1);
        case 1021: return fde_func_1021_0x0c5d84(a0, a1);
        case 1022: return fde_func_1022_0x0c7544(a0, a1);
        case 1023: return fde_func_1023_0x0d1340(a0, a1);
        case 1024: return fde_func_1024_0x0d1420(a0, a1);
        case 1025: return fde_func_1025_0x0d1c04(a0, a1);
        case 1026: return fde_func_1026_0x0d1eb0(a0, a1);
        case 1027: return fde_func_1027_0x0d24d4(a0, a1);
        case 1028: return fde_func_1028_0x0d2834(a0, a1);
        case 1029: return fde_func_1029_0x0d2b08(a0, a1);
        case 1030: return fde_func_1030_0x0d2eb4(a0, a1);
        case 1031: return fde_func_1031_0x0d30d0(a0, a1);
        case 1032: return fde_func_1032_0x0d3640(a0, a1);
        case 1033: return fde_func_1033_0x0d36d4(a0, a1);
        case 1034: return fde_func_1034_0x0d36e4(a0, a1);
        case 1035: return fde_func_1035_0x0d3744(a0, a1);
        case 1036: return fde_func_1036_0x0d3884(a0, a1);
        case 1037: return fde_func_1037_0x0d3994(a0, a1);
        case 1038: return fde_func_1038_0x0d3a98(a0, a1);
        case 1039: return fde_func_1039_0x0d4500(a0, a1);
        case 1040: return fde_func_1040_0x0d47b4(a0, a1);
        case 1041: return fde_func_1041_0x0d48b8(a0, a1);
        case 1042: return fde_func_1042_0x0d4ab8(a0, a1);
        case 1043: return fde_func_1043_0x0d4ac8(a0, a1);
        case 1044: return fde_func_1044_0x0d566c(a0, a1);
        case 1045: return fde_func_1045_0x0d5688(a0, a1);
        case 1046: return fde_func_1046_0x0d593c(a0, a1);
        case 1047: return fde_func_1047_0x0d5aac(a0, a1);
        case 1048: return fde_func_1048_0x0d5ad4(a0, a1);
        case 1049: return fde_func_1049_0x0d5b6c(a0, a1);
        case 1050: return fde_func_1050_0x0d5cf0(a0, a1);
        case 1051: return fde_func_1051_0x0d5ed8(a0, a1);
        case 1052: return fde_func_1052_0x0d5fb0(a0, a1);
        case 1053: return fde_func_1053_0x0d6034(a0, a1);
        case 1054: return fde_func_1054_0x0d611c(a0, a1);
        case 1055: return fde_func_1055_0x0d6258(a0, a1);
        case 1056: return fde_func_1056_0x0d62f0(a0, a1);
        case 1057: return fde_func_1057_0x0d661c(a0, a1);
        case 1058: return fde_func_1058_0x0d6aa0(a0, a1);
        case 1059: return fde_func_1059_0x0d6b4c(a0, a1);
        case 1060: return fde_func_1060_0x0d7068(a0, a1);
        case 1061: return fde_func_1061_0x0d706c(a0, a1);
        case 1062: return fde_func_1062_0x0d70f8(a0, a1);
        case 1063: return fde_func_1063_0x0d7104(a0, a1);
        case 1064: return fde_func_1064_0x0d71ec(a0, a1);
        case 1065: return fde_func_1065_0x0d7254(a0, a1);
        case 1066: return fde_func_1066_0x0d7680(a0, a1);
        case 1067: return fde_func_1067_0x0d7704(a0, a1);
        case 1068: return fde_func_1068_0x0d7884(a0, a1);
        case 1069: return fde_func_1069_0x0d7b98(a0, a1);
        case 1070: return fde_func_1070_0x0d7ba4(a0, a1);
        case 1071: return fde_func_1071_0x0d7c30(a0, a1);
        case 1072: return fde_func_1072_0x0d7cd0(a0, a1);
        case 1073: return fde_func_1073_0x0d7da4(a0, a1);
        case 1074: return fde_func_1074_0x0d7f24(a0, a1);
        case 1075: return fde_func_1075_0x0d7f68(a0, a1);
        case 1076: return fde_func_1076_0x0d7fe0(a0, a1);
        case 1077: return fde_func_1077_0x0d9044(a0, a1);
        case 1078: return fde_func_1078_0x0d9174(a0, a1);
        case 1079: return fde_func_1079_0x0d9444(a0, a1);
        case 1080: return fde_func_1080_0x0d967c(a0, a1);
        case 1081: return fde_func_1081_0x0d9684(a0, a1);
        case 1082: return fde_func_1082_0x0d983c(a0, a1);
        case 1083: return fde_func_1083_0x0d9844(a0, a1);
        case 1084: return fde_func_1084_0x0d98b4(a0, a1);
        case 1085: return fde_func_1085_0x0d9904(a0, a1);
        case 1086: return fde_func_1086_0x0d99c8(a0, a1);
        case 1087: return fde_func_1087_0x0d9b24(a0, a1);
        case 1088: return fde_func_1088_0x0d9b2c(a0, a1);
        case 1089: return fde_func_1089_0x0da818(a0, a1);
        case 1090: return fde_func_1090_0x0daac8(a0, a1);
        case 1091: return fde_func_1091_0x0dab18(a0, a1);
        case 1092: return fde_func_1092_0x0dab28(a0, a1);
        case 1093: return fde_func_1093_0x0db090(a0, a1);
        case 1094: return fde_func_1094_0x0db170(a0, a1);
        case 1095: return fde_func_1095_0x0db3b8(a0, a1);
        case 1096: return fde_func_1096_0x0db414(a0, a1);
        case 1097: return fde_func_1097_0x0db420(a0, a1);
        case 1098: return fde_func_1098_0x0db428(a0, a1);
        case 1099: return fde_func_1099_0x0db998(a0, a1);
        case 1100: return fde_func_1100_0x0dbbdc(a0, a1);
        case 1101: return fde_func_1101_0x0dc668(a0, a1);
        case 1102: return fde_func_1102_0x0dc698(a0, a1);
        case 1103: return fde_func_1103_0x0dc6a0(a0, a1);
        case 1104: return fde_func_1104_0x0dc6a8(a0, a1);
        case 1105: return fde_func_1105_0x0dd040(a0, a1);
        case 1106: return fde_func_1106_0x0dda90(a0, a1);
        case 1107: return fde_func_1107_0x0ddac0(a0, a1);
        case 1108: return fde_func_1108_0x0ddac8(a0, a1);
        case 1109: return fde_func_1109_0x0de6e4(a0, a1);
        case 1110: return fde_func_1110_0x0de6ec(a0, a1);
        case 1111: return fde_func_1111_0x0de9d4(a0, a1);
        case 1112: return fde_func_1112_0x0dea24(a0, a1);
        case 1113: return fde_func_1113_0x0defa4(a0, a1);
        case 1114: return fde_func_1114_0x0df1f4(a0, a1);
        case 1115: return fde_func_1115_0x0df224(a0, a1);
        case 1116: return fde_func_1116_0x0df7dc(a0, a1);
        case 1117: return fde_func_1117_0x0df910(a0, a1);
        case 1118: return fde_func_1118_0x0df944(a0, a1);
        case 1119: return fde_func_1119_0x0df9a0(a0, a1);
        case 1120: return fde_func_1120_0x0dfa28(a0, a1);
        case 1121: return fde_func_1121_0x0e02ec(a0, a1);
        case 1122: return fde_func_1122_0x0e0748(a0, a1);
        case 1123: return fde_func_1123_0x0e116c(a0, a1);
        case 1124: return fde_func_1124_0x0e119c(a0, a1);
        case 1125: return fde_func_1125_0x0e11c4(a0, a1);
        case 1126: return fde_func_1126_0x0e1c64(a0, a1);
        case 1127: return fde_func_1127_0x0e1cec(a0, a1);
        case 1128: return fde_func_1128_0x0e1e8c(a0, a1);
        case 1129: return fde_func_1129_0x0e1fd0(a0, a1);
        case 1130: return fde_func_1130_0x0e2190(a0, a1);
        case 1131: return fde_func_1131_0x0e251c(a0, a1);
        case 1132: return fde_func_1132_0x0e298c(a0, a1);
        case 1133: return fde_func_1133_0x0e2f78(a0, a1);
        case 1134: return fde_func_1134_0x0e32c0(a0, a1);
        case 1135: return fde_func_1135_0x0e3640(a0, a1);
        case 1136: return fde_func_1136_0x0e36c0(a0, a1);
        case 1137: return fde_func_1137_0x0e3c3c(a0, a1);
        case 1138: return fde_func_1138_0x0e3cc0(a0, a1);
        case 1139: return fde_func_1139_0x0e3e94(a0, a1);
        case 1140: return fde_func_1140_0x0e45a0(a0, a1);
        case 1141: return fde_func_1141_0x0e4888(a0, a1);
        case 1142: return fde_func_1142_0x0e49f4(a0, a1);
        case 1143: return fde_func_1143_0x0e4ae4(a0, a1);
        case 1144: return fde_func_1144_0x0e4c54(a0, a1);
        case 1145: return fde_func_1145_0x0e4e28(a0, a1);
        case 1146: return fde_func_1146_0x0e4ec4(a0, a1);
        case 1147: return fde_func_1147_0x0e5184(a0, a1);
        case 1148: return fde_func_1148_0x0e5418(a0, a1);
        case 1149: return fde_func_1149_0x0e5724(a0, a1);
        case 1150: return fde_func_1150_0x0e5768(a0, a1);
        case 1151: return fde_func_1151_0x0e587c(a0, a1);
        case 1152: return fde_func_1152_0x0e594c(a0, a1);
        case 1153: return fde_func_1153_0x0e5d50(a0, a1);
        case 1154: return fde_func_1154_0x0e5fa4(a0, a1);
        case 1155: return fde_func_1155_0x0e766c(a0, a1);
        case 1156: return fde_func_1156_0x0e8c1c(a0, a1);
        case 1157: return fde_func_1157_0x0e8ff8(a0, a1);
        case 1158: return fde_func_1158_0x0e93d4(a0, a1);
        case 1159: return fde_func_1159_0x0eaa94(a0, a1);
        case 1160: return fde_func_1160_0x0eab3c(a0, a1);
        case 1161: return fde_func_1161_0x0eacb8(a0, a1);
        case 1162: return fde_func_1162_0x0eae08(a0, a1);
        case 1163: return fde_func_1163_0x0eb0f8(a0, a1);
        case 1164: return fde_func_1164_0x0eb6cc(a0, a1);
        case 1165: return fde_func_1165_0x0ede3c(a0, a1);
        case 1166: return fde_func_1166_0x0edf50(a0, a1);
        case 1167: return fde_func_1167_0x0ee034(a0, a1);
        case 1168: return fde_func_1168_0x0ee0b4(a0, a1);
        case 1169: return fde_func_1169_0x0ee128(a0, a1);
        case 1170: return fde_func_1170_0x0ee330(a0, a1);
        case 1171: return fde_func_1171_0x0ee548(a0, a1);
        case 1172: return fde_func_1172_0x0ee650(a0, a1);
        case 1173: return fde_func_1173_0x0f8dbc(a0, a1);
        case 1174: return fde_func_1174_0x0f9de4(a0, a1);
        case 1175: return fde_func_1175_0x0f9e74(a0, a1);
        case 1176: return fde_func_1176_0x0f9ebc(a0, a1);
        case 1177: return fde_func_1177_0x0f9f38(a0, a1);
        case 1178: return fde_func_1178_0x0f9f90(a0, a1);
        case 1179: return fde_func_1179_0x0f9fe8(a0, a1);
        case 1180: return fde_func_1180_0x0fb040(a0, a1);
        case 1181: return fde_func_1181_0x0fb0a4(a0, a1);
        case 1182: return fde_func_1182_0x0fb0fc(a0, a1);
        case 1183: return fde_func_1183_0x0fb160(a0, a1);
        case 1184: return fde_func_1184_0x0fb1b8(a0, a1);
        case 1185: return fde_func_1185_0x0fb210(a0, a1);
        case 1186: return fde_func_1186_0x0fb268(a0, a1);
        case 1187: return fde_func_1187_0x0fb2c0(a0, a1);
        case 1188: return fde_func_1188_0x0fb318(a0, a1);
        case 1189: return fde_func_1189_0x0fb394(a0, a1);
        case 1190: return fde_func_1190_0x0fb410(a0, a1);
        case 1191: return fde_func_1191_0x0fb530(a0, a1);
        case 1192: return fde_func_1192_0x0fb650(a0, a1);
        case 1193: return fde_func_1193_0x0fb770(a0, a1);
        case 1194: return fde_func_1194_0x0fb904(a0, a1);
        case 1195: return fde_func_1195_0x0fb95c(a0, a1);
        case 1196: return fde_func_1196_0x0fb9b4(a0, a1);
        case 1197: return fde_func_1197_0x0fba0c(a0, a1);
        case 1198: return fde_func_1198_0x0fc788(a0, a1);
        case 1199: return fde_func_1199_0x0fc7a4(a0, a1);
        default: return 0ULL;
    }
}