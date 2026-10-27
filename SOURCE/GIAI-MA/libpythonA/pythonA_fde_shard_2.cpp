// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 2/5 for libpythonA.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 2/5 cho libpythonA.so
// Covers representative FDE indices [400 .. 799] out of 4,320 total FDEs
// Bao phủ chỉ số FDE đại diện [400 .. 799] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_core.h"

// FDE #0400 | PC: 0x076320 | FDE: 0x1d4f38 | Size: 256 bytes [_PyObject_CallMethodId]
// Khung tháo gỡ #0400 | Địa chỉ PC: 0x076320 | Địa chỉ FDE: 0x1d4f38 | Kích thước: 256 bytes
//   0x076320: D10503FF  sub      sp, sp, #0x140
//   0x076324: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x076328: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x07632c: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0400_0x076320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076320ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1d4f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0401 | PC: 0x076450 | FDE: 0x1d4f60 | Size: 256 bytes [_PyObject_CallMethod_SizeT]
// Khung tháo gỡ #0401 | Địa chỉ PC: 0x076450 | Địa chỉ FDE: 0x1d4f60 | Kích thước: 256 bytes
//   0x076450: D10503FF  sub      sp, sp, #0x140
//   0x076454: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x076458: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x07645c: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0401_0x076450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076450ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1d4f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0402 | PC: 0x076580 | FDE: 0x1d4f88 | Size: 256 bytes [_PyObject_CallMethodId_SizeT]
// Khung tháo gỡ #0402 | Địa chỉ PC: 0x076580 | Địa chỉ FDE: 0x1d4f88 | Kích thước: 256 bytes
//   0x076580: D10503FF  sub      sp, sp, #0x140
//   0x076584: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x076588: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x07658c: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0402_0x076580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076580ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1d4f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0403 | PC: 0x0766b0 | FDE: 0x1d4fb0 | Size: 256 bytes [PyObject_VectorcallMethod]
// Khung tháo gỡ #0403 | Địa chỉ PC: 0x0766b0 | Địa chỉ FDE: 0x1d4fb0 | Kích thước: 256 bytes
//   0x0766b0: D10143FF  sub      sp, sp, #0x50
//   0x0766b4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0766b8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0766bc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0403_0x0766b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0766b0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d4fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0404 | PC: 0x0767d0 | FDE: 0x1d4fd8 | Size: 256 bytes [PyObject_CallMethodObjArgs]
// Khung tháo gỡ #0404 | Địa chỉ PC: 0x0767d0 | Địa chỉ FDE: 0x1d4fd8 | Kích thước: 256 bytes
//   0x0767d0: D10503FF  sub      sp, sp, #0x140
//   0x0767d4: F90083FC  str      x28, [sp, #0x100]
//   0x0767d8: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0767dc: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0404_0x0767d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0767d0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1d4fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0405 | PC: 0x076900 | FDE: 0x1d5000 | Size: 256 bytes
// Khung tháo gỡ #0405 | Địa chỉ PC: 0x076900 | Địa chỉ FDE: 0x1d5000 | Kích thước: 256 bytes
//   0x076900: D102C3FF  sub      sp, sp, #0xb0
//   0x076904: F9002BFB  str      x27, [sp, #0x50]
//   0x076908: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x07690c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0405_0x076900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076900ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x1d5000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0406 | PC: 0x076b3c | FDE: 0x1d5030 | Size: 256 bytes [_PyObject_CallMethodIdObjArgs]
// Khung tháo gỡ #0406 | Địa chỉ PC: 0x076b3c | Địa chỉ FDE: 0x1d5030 | Kích thước: 256 bytes
//   0x076b3c: D10503FF  sub      sp, sp, #0x140
//   0x076b40: F90083FC  str      x28, [sp, #0x100]
//   0x076b44: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x076b48: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0406_0x076b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076b3cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1d5030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0407 | PC: 0x076c78 | FDE: 0x1d5058 | Size: 176 bytes [PyObject_CallFunctionObjArgs]
// Khung tháo gỡ #0407 | Địa chỉ PC: 0x076c78 | Địa chỉ FDE: 0x1d5058 | Kích thước: 176 bytes
//   0x076c78: D10503FF  sub      sp, sp, #0x140
//   0x076c7c: A91157FC  stp      x28, x21, [sp, #0x110]
//   0x076c80: A9124FF4  stp      x20, x19, [sp, #0x120]
//   0x076c84: A9137BFD  stp      x29, x30, [sp, #0x130]
static inline uint64_t fde_func_0407_0x076c78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076c78ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91157fcULL) ^ 0x1d5058ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0408 | PC: 0x076d28 | FDE: 0x1d5080 | Size: 104 bytes [PyCapsule_New]
// Khung tháo gỡ #0408 | Địa chỉ PC: 0x076d28 | Địa chỉ FDE: 0x1d5080 | Kích thước: 104 bytes
//   0x076d28: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x076d2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x076d30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x076d34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0408_0x076d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076d28ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5080ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0409 | PC: 0x076d90 | FDE: 0x1d50a0 | Size: 92 bytes [PyCapsule_IsValid]
// Khung tháo gỡ #0409 | Địa chỉ PC: 0x076d90 | Địa chỉ FDE: 0x1d50a0 | Kích thước: 92 bytes
//   0x076d90: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076d94: 910003FD  mov      x29, sp
//   0x076d98: B4000260  cbz      x0, #0x76de4
//   0x076d9c: B0000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0409_0x076d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076d90ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d50a0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0410 | PC: 0x076dec | FDE: 0x1d50c0 | Size: 148 bytes [PyCapsule_GetPointer]
// Khung tháo gỡ #0410 | Địa chỉ PC: 0x076dec | Địa chỉ FDE: 0x1d50c0 | Kích thước: 148 bytes
//   0x076dec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x076df0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x076df4: 910043FD  add      x29, sp, #0x10
//   0x076df8: B40000C0  cbz      x0, #0x76e10
static inline uint64_t fde_func_0410_0x076dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076decULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d50c0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0411 | PC: 0x076e80 | FDE: 0x1d50e0 | Size: 88 bytes [PyCapsule_GetName]
// Khung tháo gỡ #0411 | Địa chỉ PC: 0x076e80 | Địa chỉ FDE: 0x1d50e0 | Kích thước: 88 bytes
//   0x076e80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076e84: 910003FD  mov      x29, sp
//   0x076e88: B40000C0  cbz      x0, #0x76ea0
//   0x076e8c: B0000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0411_0x076e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076e80ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d50e0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0412 | PC: 0x076ed8 | FDE: 0x1d5100 | Size: 88 bytes [PyCapsule_GetDestructor]
// Khung tháo gỡ #0412 | Địa chỉ PC: 0x076ed8 | Địa chỉ FDE: 0x1d5100 | Kích thước: 88 bytes
//   0x076ed8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076edc: 910003FD  mov      x29, sp
//   0x076ee0: B40000C0  cbz      x0, #0x76ef8
//   0x076ee4: B0000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0412_0x076ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076ed8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5100ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0413 | PC: 0x076f30 | FDE: 0x1d5120 | Size: 88 bytes [PyCapsule_GetContext]
// Khung tháo gỡ #0413 | Địa chỉ PC: 0x076f30 | Địa chỉ FDE: 0x1d5120 | Kích thước: 88 bytes
//   0x076f30: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076f34: 910003FD  mov      x29, sp
//   0x076f38: B40000C0  cbz      x0, #0x76f50
//   0x076f3c: B0000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0413_0x076f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076f30ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5120ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0414 | PC: 0x076f88 | FDE: 0x1d5140 | Size: 116 bytes [PyCapsule_SetPointer]
// Khung tháo gỡ #0414 | Địa chỉ PC: 0x076f88 | Địa chỉ FDE: 0x1d5140 | Kích thước: 116 bytes
//   0x076f88: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076f8c: 910003FD  mov      x29, sp
//   0x076f90: B4000181  cbz      x1, #0x76fc0
//   0x076f94: B40000C0  cbz      x0, #0x76fac
static inline uint64_t fde_func_0414_0x076f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076f88ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5140ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0415 | PC: 0x076ffc | FDE: 0x1d5160 | Size: 92 bytes [PyCapsule_SetName]
// Khung tháo gỡ #0415 | Địa chỉ PC: 0x076ffc | Địa chỉ FDE: 0x1d5160 | Kích thước: 92 bytes
//   0x076ffc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x077000: 910003FD  mov      x29, sp
//   0x077004: B40000C0  cbz      x0, #0x7701c
//   0x077008: 90000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0415_0x076ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076ffcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5160ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0416 | PC: 0x077058 | FDE: 0x1d5180 | Size: 92 bytes [PyCapsule_SetDestructor]
// Khung tháo gỡ #0416 | Địa chỉ PC: 0x077058 | Địa chỉ FDE: 0x1d5180 | Kích thước: 92 bytes
//   0x077058: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07705c: 910003FD  mov      x29, sp
//   0x077060: B40000C0  cbz      x0, #0x77078
//   0x077064: 90000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0416_0x077058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077058ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5180ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0417 | PC: 0x0770b4 | FDE: 0x1d51a0 | Size: 92 bytes [PyCapsule_SetContext]
// Khung tháo gỡ #0417 | Địa chỉ PC: 0x0770b4 | Địa chỉ FDE: 0x1d51a0 | Kích thước: 92 bytes
//   0x0770b4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0770b8: 910003FD  mov      x29, sp
//   0x0770bc: B40000C0  cbz      x0, #0x770d4
//   0x0770c0: 90000C49  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0417_0x0770b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0770b4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d51a0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0418 | PC: 0x077110 | FDE: 0x1d51c0 | Size: 256 bytes [PyCapsule_Import]
// Khung tháo gỡ #0418 | Địa chỉ PC: 0x077110 | Địa chỉ FDE: 0x1d51c0 | Kích thước: 256 bytes
//   0x077110: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x077114: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x077118: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07711c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0418_0x077110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077110ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d51c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0419 | PC: 0x0772d8 | FDE: 0x1d51e8 | Size: 48 bytes
// Khung tháo gỡ #0419 | Địa chỉ PC: 0x0772d8 | Địa chỉ FDE: 0x1d51e8 | Kích thước: 48 bytes
//   0x0772d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0772dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0772e0: 910043FD  add      x29, sp, #0x10
//   0x0772e4: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_0419_0x0772d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0772d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d51e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0420 | PC: 0x077308 | FDE: 0x1d5208 | Size: 60 bytes
// Khung tháo gỡ #0420 | Địa chỉ PC: 0x077308 | Địa chỉ FDE: 0x1d5208 | Kích thước: 60 bytes
//   0x077308: F9400C08  ldr      x8, [x0, #0x18]
//   0x07730c: B0000A8A  adrp     x10, #0x1c8000
//   0x077310: B000096B  adrp     x11, #0x1a4000
//   0x077314: B0000989  adrp     x9, #0x1a8000
static inline uint64_t fde_func_0420_0x077308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077308ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb0000a8aULL) ^ 0x1d5208ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0421 | PC: 0x077344 | FDE: 0x1d5220 | Size: 64 bytes [PyCell_New]
// Khung tháo gỡ #0421 | Địa chỉ PC: 0x077344 | Địa chỉ FDE: 0x1d5220 | Kích thước: 64 bytes
//   0x077344: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077348: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07734c: 910043FD  add      x29, sp, #0x10
//   0x077350: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0421_0x077344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077344ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5220ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0422 | PC: 0x077384 | FDE: 0x1d5240 | Size: 84 bytes [PyCell_Get]
// Khung tháo gỡ #0422 | Địa chỉ PC: 0x077384 | Địa chỉ FDE: 0x1d5240 | Kích thước: 84 bytes
//   0x077384: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x077388: 910003FD  mov      x29, sp
//   0x07738c: 90000C49  adrp     x9, #0x1ff000
//   0x077390: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0422_0x077384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077384ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5240ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0423 | PC: 0x0773d8 | FDE: 0x1d5260 | Size: 120 bytes [PyCell_Set]
// Khung tháo gỡ #0423 | Địa chỉ PC: 0x0773d8 | Địa chỉ FDE: 0x1d5260 | Kích thước: 120 bytes
//   0x0773d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0773dc: 910003FD  mov      x29, sp
//   0x0773e0: 90000C4A  adrp     x10, #0x1ff000
//   0x0773e4: F9400409  ldr      x9, [x0, #8]
static inline uint64_t fde_func_0423_0x0773d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0773d8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5260ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0424 | PC: 0x077450 | FDE: 0x1d5280 | Size: 60 bytes
// Khung tháo gỡ #0424 | Địa chỉ PC: 0x077450 | Địa chỉ FDE: 0x1d5280 | Kích thước: 60 bytes
//   0x077450: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077454: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077458: 910043FD  add      x29, sp, #0x10
//   0x07745c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0424_0x077450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077450ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5280ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0425 | PC: 0x07748c | FDE: 0x1d52a0 | Size: 44 bytes
// Khung tháo gỡ #0425 | Địa chỉ PC: 0x07748c | Địa chỉ FDE: 0x1d52a0 | Kích thước: 44 bytes
//   0x07748c: F9400803  ldr      x3, [x0, #0x10]
//   0x077490: AA0003E1  mov      x1, x0
//   0x077494: B40000C3  cbz      x3, #0x774ac
//   0x077498: F9400468  ldr      x8, [x3, #8]
static inline uint64_t fde_func_0425_0x07748c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07748cULL ^ (static_cast<uint64_t>(0xf9400803ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x1d52a0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0426 | PC: 0x0774b8 | FDE: 0x1d52b8 | Size: 52 bytes
// Khung tháo gỡ #0426 | Địa chỉ PC: 0x0774b8 | Địa chỉ FDE: 0x1d52b8 | Kích thước: 52 bytes
//   0x0774b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0774bc: 910003FD  mov      x29, sp
//   0x0774c0: F9400800  ldr      x0, [x0, #0x10]
//   0x0774c4: B40000E0  cbz      x0, #0x774e0
static inline uint64_t fde_func_0426_0x0774b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0774b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d52b8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0427 | PC: 0x0774ec | FDE: 0x1d52d8 | Size: 56 bytes
// Khung tháo gỡ #0427 | Địa chỉ PC: 0x0774ec | Địa chỉ FDE: 0x1d52d8 | Kích thước: 56 bytes
//   0x0774ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0774f0: 910003FD  mov      x29, sp
//   0x0774f4: AA0003E8  mov      x8, x0
//   0x0774f8: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0427_0x0774ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0774ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d52d8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0428 | PC: 0x077524 | FDE: 0x1d52f8 | Size: 204 bytes
// Khung tháo gỡ #0428 | Địa chỉ PC: 0x077524 | Địa chỉ FDE: 0x1d52f8 | Kích thước: 204 bytes
//   0x077524: 90000C48  adrp     x8, #0x1ff000
//   0x077528: F9400409  ldr      x9, [x0, #8]
//   0x07752c: F943B508  ldr      x8, [x8, #0x768]
//   0x077530: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_0428_0x077524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077524ULL ^ (static_cast<uint64_t>(0x90000c48ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1d52f8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0429 | PC: 0x0775f0 | FDE: 0x1d5310 | Size: 176 bytes
// Khung tháo gỡ #0429 | Địa chỉ PC: 0x0775f0 | Địa chỉ FDE: 0x1d5310 | Kích thước: 176 bytes
//   0x0775f0: D100C3FF  sub      sp, sp, #0x30
//   0x0775f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0775f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0775fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0429_0x0775f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0775f0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5310ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0430 | PC: 0x0776a0 | FDE: 0x1d5330 | Size: 76 bytes
// Khung tháo gỡ #0430 | Địa chỉ PC: 0x0776a0 | Địa chỉ FDE: 0x1d5330 | Kích thước: 76 bytes
//   0x0776a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0776a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0776a8: 910043FD  add      x29, sp, #0x10
//   0x0776ac: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_0430_0x0776a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0776a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5330ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0431 | PC: 0x0776ec | FDE: 0x1d5350 | Size: 72 bytes
// Khung tháo gỡ #0431 | Địa chỉ PC: 0x0776ec | Địa chỉ FDE: 0x1d5350 | Kích thước: 72 bytes
//   0x0776ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0776f0: 910003FD  mov      x29, sp
//   0x0776f4: AA0003E8  mov      x8, x0
//   0x0776f8: B4000081  cbz      x1, #0x77708
static inline uint64_t fde_func_0431_0x0776ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0776ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5350ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0432 | PC: 0x077734 | FDE: 0x1d5370 | Size: 68 bytes [PyMethod_Function]
// Khung tháo gỡ #0432 | Địa chỉ PC: 0x077734 | Địa chỉ FDE: 0x1d5370 | Kích thước: 68 bytes
//   0x077734: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x077738: 910003FD  mov      x29, sp
//   0x07773c: 90000C49  adrp     x9, #0x1ff000
//   0x077740: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0432_0x077734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077734ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5370ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0433 | PC: 0x077778 | FDE: 0x1d5390 | Size: 68 bytes [PyMethod_Self]
// Khung tháo gỡ #0433 | Địa chỉ PC: 0x077778 | Địa chỉ FDE: 0x1d5390 | Kích thước: 68 bytes
//   0x077778: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07777c: 910003FD  mov      x29, sp
//   0x077780: 90000C49  adrp     x9, #0x1ff000
//   0x077784: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0433_0x077778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077778ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5390ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0434 | PC: 0x0777bc | FDE: 0x1d53b0 | Size: 124 bytes [PyMethod_New]
// Khung tháo gỡ #0434 | Địa chỉ PC: 0x0777bc | Địa chỉ FDE: 0x1d53b0 | Kích thước: 124 bytes
//   0x0777bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0777c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0777c4: 910043FD  add      x29, sp, #0x10
//   0x0777c8: B4000281  cbz      x1, #0x77818
static inline uint64_t fde_func_0434_0x0777bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0777bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d53b0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0435 | PC: 0x077838 | FDE: 0x1d53d0 | Size: 256 bytes
// Khung tháo gỡ #0435 | Địa chỉ PC: 0x077838 | Địa chỉ FDE: 0x1d53d0 | Kích thước: 256 bytes
//   0x077838: D10283FF  sub      sp, sp, #0xa0
//   0x07783c: F90023FB  str      x27, [sp, #0x40]
//   0x077840: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x077844: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0435_0x077838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077838ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x1d53d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0436 | PC: 0x077a78 | FDE: 0x1d5400 | Size: 112 bytes
// Khung tháo gỡ #0436 | Địa chỉ PC: 0x077a78 | Địa chỉ FDE: 0x1d5400 | Kích thước: 112 bytes
//   0x077a78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077a7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077a80: 910043FD  add      x29, sp, #0x10
//   0x077a84: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_0436_0x077a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077a78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5400ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0437 | PC: 0x077ae8 | FDE: 0x1d5420 | Size: 256 bytes
// Khung tháo gỡ #0437 | Địa chỉ PC: 0x077ae8 | Địa chỉ FDE: 0x1d5420 | Kích thước: 256 bytes
//   0x077ae8: D10103FF  sub      sp, sp, #0x40
//   0x077aec: F9000BF5  str      x21, [sp, #0x10]
//   0x077af0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x077af4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0437_0x077ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077ae8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1d5420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0438 | PC: 0x077bec | FDE: 0x1d5440 | Size: 76 bytes
// Khung tháo gỡ #0438 | Địa chỉ PC: 0x077bec | Địa chỉ FDE: 0x1d5440 | Kích thước: 76 bytes
//   0x077bec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077bf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077bf4: 910043FD  add      x29, sp, #0x10
//   0x077bf8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0438_0x077bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077becULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5440ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0439 | PC: 0x077c38 | FDE: 0x1d5460 | Size: 160 bytes
// Khung tháo gỡ #0439 | Địa chỉ PC: 0x077c38 | Địa chỉ FDE: 0x1d5460 | Kích thước: 160 bytes
//   0x077c38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077c3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077c40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077c44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0439_0x077c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077c38ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5460ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0440 | PC: 0x077cd8 | FDE: 0x1d5480 | Size: 88 bytes
// Khung tháo gỡ #0440 | Địa chỉ PC: 0x077cd8 | Địa chỉ FDE: 0x1d5480 | Kích thước: 88 bytes
//   0x077cd8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077cdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077ce0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077ce4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0440_0x077cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077cd8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5480ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0441 | PC: 0x077d30 | FDE: 0x1d54a0 | Size: 204 bytes
// Khung tháo gỡ #0441 | Địa chỉ PC: 0x077d30 | Địa chỉ FDE: 0x1d54a0 | Kích thước: 204 bytes
//   0x077d30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077d34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077d38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077d3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0441_0x077d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077d30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d54a0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0442 | PC: 0x077dfc | FDE: 0x1d54c0 | Size: 16 bytes
// Khung tháo gỡ #0442 | Địa chỉ PC: 0x077dfc | Địa chỉ FDE: 0x1d54c0 | Kích thước: 16 bytes
//   0x077dfc: F9400008  ldr      x8, [x0]
//   0x077e00: 91000508  add      x8, x8, #1
//   0x077e04: F9000008  str      x8, [x0]
//   0x077e08: D65F03C0  ret      
static inline uint64_t fde_func_0442_0x077dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077dfcULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1d54c0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0443 | PC: 0x077e0c | FDE: 0x1d54d8 | Size: 256 bytes
// Khung tháo gỡ #0443 | Địa chỉ PC: 0x077e0c | Địa chỉ FDE: 0x1d54d8 | Kích thước: 256 bytes
//   0x077e0c: D10143FF  sub      sp, sp, #0x50
//   0x077e10: F90013F5  str      x21, [sp, #0x20]
//   0x077e14: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x077e18: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0443_0x077e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077e0cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1d54d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0444 | PC: 0x077f30 | FDE: 0x1d54f8 | Size: 60 bytes [PyInstanceMethod_New]
// Khung tháo gỡ #0444 | Địa chỉ PC: 0x077f30 | Địa chỉ FDE: 0x1d54f8 | Kích thước: 60 bytes
//   0x077f30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077f34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077f38: 910043FD  add      x29, sp, #0x10
//   0x077f3c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0444_0x077f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077f30ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d54f8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0445 | PC: 0x077f6c | FDE: 0x1d5518 | Size: 68 bytes [PyInstanceMethod_Function]
// Khung tháo gỡ #0445 | Địa chỉ PC: 0x077f6c | Địa chỉ FDE: 0x1d5518 | Kích thước: 68 bytes
//   0x077f6c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x077f70: 910003FD  mov      x29, sp
//   0x077f74: 90000C49  adrp     x9, #0x1ff000
//   0x077f78: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0445_0x077f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077f6cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5518ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0446 | PC: 0x077fb0 | FDE: 0x1d5538 | Size: 56 bytes
// Khung tháo gỡ #0446 | Địa chỉ PC: 0x077fb0 | Địa chỉ FDE: 0x1d5538 | Kích thước: 56 bytes
//   0x077fb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077fb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077fb8: 910043FD  add      x29, sp, #0x10
//   0x077fbc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0446_0x077fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077fb0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5538ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0447 | PC: 0x077fe8 | FDE: 0x1d5558 | Size: 256 bytes
// Khung tháo gỡ #0447 | Địa chỉ PC: 0x077fe8 | Địa chỉ FDE: 0x1d5558 | Kích thước: 256 bytes
//   0x077fe8: D100C3FF  sub      sp, sp, #0x30
//   0x077fec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077ff0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077ff4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0447_0x077fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077fe8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0448 | PC: 0x0780f8 | FDE: 0x1d5578 | Size: 8 bytes
// Khung tháo gỡ #0448 | Địa chỉ PC: 0x0780f8 | Địa chỉ FDE: 0x1d5578 | Kích thước: 8 bytes
//   0x0780f8: F9400800  ldr      x0, [x0, #0x10]
//   0x0780fc: 17FF9211  b        #0x5c940
static inline uint64_t fde_func_0448_0x0780f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0780f8ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17ff9211ULL) ^ 0x1d5578ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0449 | PC: 0x078100 | FDE: 0x1d5590 | Size: 160 bytes
// Khung tháo gỡ #0449 | Địa chỉ PC: 0x078100 | Địa chỉ FDE: 0x1d5590 | Kích thước: 160 bytes
//   0x078100: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x078104: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x078108: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07810c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0449_0x078100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078100ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5590ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0450 | PC: 0x0781a0 | FDE: 0x1d55b0 | Size: 52 bytes
// Khung tháo gỡ #0450 | Địa chỉ PC: 0x0781a0 | Địa chỉ FDE: 0x1d55b0 | Kích thước: 52 bytes
//   0x0781a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0781a4: 910003FD  mov      x29, sp
//   0x0781a8: F9400800  ldr      x0, [x0, #0x10]
//   0x0781ac: B40000E0  cbz      x0, #0x781c8
static inline uint64_t fde_func_0450_0x0781a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0781a0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d55b0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0451 | PC: 0x0781d4 | FDE: 0x1d55d0 | Size: 160 bytes
// Khung tháo gỡ #0451 | Địa chỉ PC: 0x0781d4 | Địa chỉ FDE: 0x1d55d0 | Kích thước: 160 bytes
//   0x0781d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0781d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0781dc: 910043FD  add      x29, sp, #0x10
//   0x0781e0: 32000048  orr      w8, w2, #1
static inline uint64_t fde_func_0451_0x0781d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0781d4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d55d0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0452 | PC: 0x078274 | FDE: 0x1d55f0 | Size: 132 bytes
// Khung tháo gỡ #0452 | Địa chỉ PC: 0x078274 | Địa chỉ FDE: 0x1d55f0 | Kích thước: 132 bytes
//   0x078274: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x078278: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07827c: 910043FD  add      x29, sp, #0x10
//   0x078280: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_0452_0x078274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078274ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d55f0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0453 | PC: 0x0782f8 | FDE: 0x1d5610 | Size: 204 bytes
// Khung tháo gỡ #0453 | Địa chỉ PC: 0x0782f8 | Địa chỉ FDE: 0x1d5610 | Kích thước: 204 bytes
//   0x0782f8: D100C3FF  sub      sp, sp, #0x30
//   0x0782fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x078300: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x078304: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0453_0x0782f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0782f8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5610ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0454 | PC: 0x0783c4 | FDE: 0x1d5630 | Size: 100 bytes
// Khung tháo gỡ #0454 | Địa chỉ PC: 0x0783c4 | Địa chỉ FDE: 0x1d5630 | Kích thước: 100 bytes
//   0x0783c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0783c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0783cc: 910043FD  add      x29, sp, #0x10
//   0x0783d0: A9414C08  ldp      x8, x19, [x0, #0x10]
static inline uint64_t fde_func_0454_0x0783c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0783c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5630ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0455 | PC: 0x078428 | FDE: 0x1d5650 | Size: 64 bytes
// Khung tháo gỡ #0455 | Địa chỉ PC: 0x078428 | Địa chỉ FDE: 0x1d5650 | Kích thước: 64 bytes
//   0x078428: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07842c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x078430: 910043FD  add      x29, sp, #0x10
//   0x078434: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0455_0x078428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078428ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5650ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0456 | PC: 0x078468 | FDE: 0x1d5670 | Size: 64 bytes
// Khung tháo gỡ #0456 | Địa chỉ PC: 0x078468 | Địa chỉ FDE: 0x1d5670 | Kích thước: 64 bytes
//   0x078468: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07846c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x078470: 910043FD  add      x29, sp, #0x10
//   0x078474: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0456_0x078468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078468ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5670ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0457 | PC: 0x0784a8 | FDE: 0x1d5690 | Size: 256 bytes [PyCode_NewWithPosOnlyArgs]
// Khung tháo gỡ #0457 | Địa chỉ PC: 0x0784a8 | Địa chỉ FDE: 0x1d5690 | Kích thước: 256 bytes
//   0x0784a8: D10383FF  sub      sp, sp, #0xe0
//   0x0784ac: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0784b0: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0784b4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0457_0x0784a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0784a8ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1d5690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0458 | PC: 0x078a58 | FDE: 0x1d56c0 | Size: 256 bytes
// Khung tháo gỡ #0458 | Địa chỉ PC: 0x078a58 | Địa chỉ FDE: 0x1d56c0 | Kích thước: 256 bytes
//   0x078a58: D10203FF  sub      sp, sp, #0x80
//   0x078a5c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x078a60: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x078a64: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0458_0x078a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078a58ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1d56c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0459 | PC: 0x078c6c | FDE: 0x1d56f0 | Size: 100 bytes [PyCode_New]
// Khung tháo gỡ #0459 | Địa chỉ PC: 0x078c6c | Địa chỉ FDE: 0x1d56f0 | Kích thước: 100 bytes
//   0x078c6c: D10143FF  sub      sp, sp, #0x50
//   0x078c70: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x078c74: 910103FD  add      x29, sp, #0x40
//   0x078c78: AD4087A0  ldp      q0, q1, [x29, #0x10]
static inline uint64_t fde_func_0459_0x078c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078c6cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9047bfdULL) ^ 0x1d56f0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0460 | PC: 0x078cd0 | FDE: 0x1d5710 | Size: 256 bytes [_PyCode_InitOpcache]
// Khung tháo gỡ #0460 | Địa chỉ PC: 0x078cd0 | Địa chỉ FDE: 0x1d5710 | Kích thước: 256 bytes
//   0x078cd0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x078cd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x078cd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x078cdc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0460_0x078cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078cd0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0461 | PC: 0x078dd4 | FDE: 0x1d5738 | Size: 256 bytes [PyCode_NewEmpty]
// Khung tháo gỡ #0461 | Địa chỉ PC: 0x078dd4 | Địa chỉ FDE: 0x1d5738 | Kích thước: 256 bytes
//   0x078dd4: D10203FF  sub      sp, sp, #0x80
//   0x078dd8: F90023F7  str      x23, [sp, #0x40]
//   0x078ddc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x078de0: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0461_0x078dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078dd4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1d5738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0462 | PC: 0x078f14 | FDE: 0x1d5760 | Size: 256 bytes [_PyCode_ConstantKey]
// Khung tháo gỡ #0462 | Địa chỉ PC: 0x078f14 | Địa chỉ FDE: 0x1d5760 | Kích thước: 256 bytes
//   0x078f14: D10183FF  sub      sp, sp, #0x60
//   0x078f18: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x078f1c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x078f20: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0462_0x078f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078f14ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1d5760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0463 | PC: 0x079278 | FDE: 0x1d5788 | Size: 168 bytes [PyLineTable_PreviousAddressRange]
// Khung tháo gỡ #0463 | Địa chỉ PC: 0x079278 | Địa chỉ FDE: 0x1d5788 | Kích thước: 168 bytes
//   0x079278: B9400008  ldr      w8, [x0]
//   0x07927c: 7100051F  cmp      w8, #1
//   0x079280: 540004CB  b.lt     #0x79318
//   0x079284: F9400C0A  ldr      x10, [x0, #0x18]
static inline uint64_t fde_func_0463_0x079278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079278ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x1d5788ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0464 | PC: 0x079320 | FDE: 0x1d57a0 | Size: 152 bytes [PyLineTable_NextAddressRange]
// Khung tháo gỡ #0464 | Địa chỉ PC: 0x079320 | Địa chỉ FDE: 0x1d57a0 | Kích thước: 152 bytes
//   0x079320: A941A009  ldp      x9, x8, [x0, #0x18]
//   0x079324: EB08013F  cmp      x9, x8
//   0x079328: 540001E2  b.hs     #0x79364
//   0x07932c: B9400408  ldr      w8, [x0, #4]
static inline uint64_t fde_func_0464_0x079320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079320ULL ^ (static_cast<uint64_t>(0xa941a009ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x1d57a0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0465 | PC: 0x0793b8 | FDE: 0x1d57b8 | Size: 256 bytes
// Khung tháo gỡ #0465 | Địa chỉ PC: 0x0793b8 | Địa chỉ FDE: 0x1d57b8 | Kích thước: 256 bytes
//   0x0793b8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0793bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0793c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0793c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0465_0x0793b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0793b8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d57b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0466 | PC: 0x0795f4 | FDE: 0x1d57e0 | Size: 72 bytes
// Khung tháo gỡ #0466 | Địa chỉ PC: 0x0795f4 | Địa chỉ FDE: 0x1d57e0 | Kích thước: 72 bytes
//   0x0795f4: B9402808  ldr      w8, [x0, #0x28]
//   0x0795f8: F9403403  ldr      x3, [x0, #0x68]
//   0x0795fc: AA0003E2  mov      x2, x0
//   0x079600: 7100011F  cmp      w8, #0
static inline uint64_t fde_func_0466_0x0795f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0795f4ULL ^ (static_cast<uint64_t>(0xb9402808ULL) << 13);
    acc = (acc + a1 + 0xf9403403ULL) ^ 0x1d57e0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0467 | PC: 0x07963c | FDE: 0x1d57f8 | Size: 256 bytes
// Khung tháo gỡ #0467 | Địa chỉ PC: 0x07963c | Địa chỉ FDE: 0x1d57f8 | Kích thước: 256 bytes
//   0x07963c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x079640: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x079644: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x079648: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0467_0x07963c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07963cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d57f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0468 | PC: 0x07973c | FDE: 0x1d5820 | Size: 256 bytes
// Khung tháo gỡ #0468 | Địa chỉ PC: 0x07973c | Địa chỉ FDE: 0x1d5820 | Kích thước: 256 bytes
//   0x07973c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x079740: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x079744: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x079748: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0468_0x07973c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07973cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d5820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0469 | PC: 0x07995c | FDE: 0x1d5848 | Size: 256 bytes
// Khung tháo gỡ #0469 | Địa chỉ PC: 0x07995c | Địa chỉ FDE: 0x1d5848 | Kích thước: 256 bytes
//   0x07995c: D10383FF  sub      sp, sp, #0xe0
//   0x079960: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x079964: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x079968: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0469_0x07995c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07995cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1d5848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0470 | PC: 0x079ee8 | FDE: 0x1d5878 | Size: 256 bytes [PyCode_Addr2Line]
// Khung tháo gỡ #0470 | Địa chỉ PC: 0x079ee8 | Địa chỉ FDE: 0x1d5878 | Kích thước: 256 bytes
//   0x079ee8: 37F80821  tbnz     w1, #0x1f, #0x79fec
//   0x079eec: F9403C09  ldr      x9, [x0, #0x78]
//   0x079ef0: B9402808  ldr      w8, [x0, #0x28]
//   0x079ef4: 2A1F03EC  mov      w12, wzr
static inline uint64_t fde_func_0470_0x079ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079ee8ULL ^ (static_cast<uint64_t>(0x37f80821ULL) << 13);
    acc = (acc + a1 + 0xf9403c09ULL) ^ 0x1d5878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0471 | PC: 0x079ff4 | FDE: 0x1d5890 | Size: 52 bytes [_PyCode_InitAddressRange]
// Khung tháo gỡ #0471 | Địa chỉ PC: 0x079ff4 | Địa chỉ FDE: 0x1d5890 | Kích thước: 52 bytes
//   0x079ff4: F9403C08  ldr      x8, [x0, #0x78]
//   0x079ff8: B9402809  ldr      w9, [x0, #0x28]
//   0x079ffc: 2F00E5E0  movi     d0, #0x000000ffffffff
//   0x07a000: 1280000A  mov      w10, #-1
static inline uint64_t fde_func_0471_0x079ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079ff4ULL ^ (static_cast<uint64_t>(0xf9403c08ULL) << 13);
    acc = (acc + a1 + 0xb9402809ULL) ^ 0x1d5890ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0472 | PC: 0x07a028 | FDE: 0x1d58a8 | Size: 256 bytes [_PyCode_CheckLineNumber]
// Khung tháo gỡ #0472 | Địa chỉ PC: 0x07a028 | Địa chỉ FDE: 0x1d58a8 | Kích thước: 256 bytes
//   0x07a028: B9400428  ldr      w8, [x1, #4]
//   0x07a02c: 6B00011F  cmp      w8, w0
//   0x07a030: 5400006D  b.le     #0x7a03c
//   0x07a034: B940002B  ldr      w11, [x1]
static inline uint64_t fde_func_0472_0x07a028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a028ULL ^ (static_cast<uint64_t>(0xb9400428ULL) << 13);
    acc = (acc + a1 + 0x6b00011fULL) ^ 0x1d58a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0473 | PC: 0x07a1a8 | FDE: 0x1d58c0 | Size: 32 bytes [PyLineTable_InitAddressRange]
// Khung tháo gỡ #0473 | Địa chỉ PC: 0x07a1a8 | Địa chỉ FDE: 0x1d58c0 | Kích thước: 32 bytes
//   0x07a1a8: 8B010008  add      x8, x0, x1
//   0x07a1ac: 2F00E5E0  movi     d0, #0x000000ffffffff
//   0x07a1b0: 12800009  mov      w9, #-1
//   0x07a1b4: B9001062  str      w2, [x3, #0x10]
static inline uint64_t fde_func_0473_0x07a1a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a1a8ULL ^ (static_cast<uint64_t>(0x8b010008ULL) << 13);
    acc = (acc + a1 + 0x2f00e5e0ULL) ^ 0x1d58c0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0474 | PC: 0x07a1c8 | FDE: 0x1d58d8 | Size: 116 bytes [_PyCode_GetExtra]
// Khung tháo gỡ #0474 | Địa chỉ PC: 0x07a1c8 | Địa chỉ FDE: 0x1d58d8 | Kích thước: 116 bytes
//   0x07a1c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07a1cc: 910003FD  mov      x29, sp
//   0x07a1d0: B0000C29  adrp     x9, #0x1ff000
//   0x07a1d4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0474_0x07a1c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a1c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d58d8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0475 | PC: 0x07a23c | FDE: 0x1d58f8 | Size: 256 bytes [_PyCode_SetExtra]
// Khung tháo gỡ #0475 | Địa chỉ PC: 0x07a23c | Địa chỉ FDE: 0x1d58f8 | Kích thước: 256 bytes
//   0x07a23c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x07a240: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07a244: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07a248: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0475_0x07a23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a23cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d58f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0476 | PC: 0x07a360 | FDE: 0x1d5920 | Size: 88 bytes
// Khung tháo gỡ #0476 | Địa chỉ PC: 0x07a360 | Địa chỉ FDE: 0x1d5920 | Kích thước: 88 bytes
//   0x07a360: F9400409  ldr      x9, [x0, #8]
//   0x07a364: AA0003E8  mov      x8, x0
//   0x07a368: F940300A  ldr      x10, [x0, #0x60]
//   0x07a36c: F9401120  ldr      x0, [x9, #0x20]
static inline uint64_t fde_func_0476_0x07a360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a360ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1d5920ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0477 | PC: 0x07a3b8 | FDE: 0x1d5938 | Size: 108 bytes
// Khung tháo gỡ #0477 | Địa chỉ PC: 0x07a3b8 | Địa chỉ FDE: 0x1d5938 | Kích thước: 108 bytes
//   0x07a3b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07a3bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a3c0: 910043FD  add      x29, sp, #0x10
//   0x07a3c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0477_0x07a3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a3b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5938ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0478 | PC: 0x07a424 | FDE: 0x1d5958 | Size: 256 bytes
// Khung tháo gỡ #0478 | Địa chỉ PC: 0x07a424 | Địa chỉ FDE: 0x1d5958 | Kích thước: 256 bytes
//   0x07a424: D105C3FF  sub      sp, sp, #0x170
//   0x07a428: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x07a42c: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x07a430: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_0478_0x07a424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a424ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x1d5958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0479 | PC: 0x07ab18 | FDE: 0x1d5988 | Size: 64 bytes
// Khung tháo gỡ #0479 | Địa chỉ PC: 0x07ab18 | Địa chỉ FDE: 0x1d5988 | Kích thước: 64 bytes
//   0x07ab18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07ab1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ab20: 910043FD  add      x29, sp, #0x10
//   0x07ab24: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0479_0x07ab18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ab18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5988ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0480 | PC: 0x07ab58 | FDE: 0x1d59a8 | Size: 256 bytes
// Khung tháo gỡ #0480 | Địa chỉ PC: 0x07ab58 | Địa chỉ FDE: 0x1d59a8 | Kích thước: 256 bytes
//   0x07ab58: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07ab5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07ab60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07ab64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0480_0x07ab58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ab58ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d59a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0481 | PC: 0x07acf4 | FDE: 0x1d59d0 | Size: 256 bytes
// Khung tháo gỡ #0481 | Địa chỉ PC: 0x07acf4 | Địa chỉ FDE: 0x1d59d0 | Kích thước: 256 bytes
//   0x07acf4: D10203FF  sub      sp, sp, #0x80
//   0x07acf8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x07acfc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x07ad00: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0481_0x07acf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07acf4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1d59d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0482 | PC: 0x07af64 | FDE: 0x1d5a00 | Size: 220 bytes
// Khung tháo gỡ #0482 | Địa chỉ PC: 0x07af64 | Địa chỉ FDE: 0x1d5a00 | Kích thước: 220 bytes
//   0x07af64: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07af68: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07af6c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07af70: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0482_0x07af64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07af64ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d5a00ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0483 | PC: 0x07b040 | FDE: 0x1d5a28 | Size: 12 bytes [_Py_c_sum]
// Khung tháo gỡ #0483 | Địa chỉ PC: 0x07b040 | Địa chỉ FDE: 0x1d5a28 | Kích thước: 12 bytes
//   0x07b040: 1E622800  fadd     d0, d0, d2
//   0x07b044: 1E632821  fadd     d1, d1, d3
//   0x07b048: D65F03C0  ret      
static inline uint64_t fde_func_0483_0x07b040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b040ULL ^ (static_cast<uint64_t>(0x1e622800ULL) << 13);
    acc = (acc + a1 + 0x1e632821ULL) ^ 0x1d5a28ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0484 | PC: 0x07b04c | FDE: 0x1d5a40 | Size: 12 bytes [_Py_c_diff]
// Khung tháo gỡ #0484 | Địa chỉ PC: 0x07b04c | Địa chỉ FDE: 0x1d5a40 | Kích thước: 12 bytes
//   0x07b04c: 1E623800  fsub     d0, d0, d2
//   0x07b050: 1E633821  fsub     d1, d1, d3
//   0x07b054: D65F03C0  ret      
static inline uint64_t fde_func_0484_0x07b04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b04cULL ^ (static_cast<uint64_t>(0x1e623800ULL) << 13);
    acc = (acc + a1 + 0x1e633821ULL) ^ 0x1d5a40ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0485 | PC: 0x07b058 | FDE: 0x1d5a58 | Size: 12 bytes [_Py_c_neg]
// Khung tháo gỡ #0485 | Địa chỉ PC: 0x07b058 | Địa chỉ FDE: 0x1d5a58 | Kích thước: 12 bytes
//   0x07b058: 1E614000  fneg     d0, d0
//   0x07b05c: 1E614021  fneg     d1, d1
//   0x07b060: D65F03C0  ret      
static inline uint64_t fde_func_0485_0x07b058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b058ULL ^ (static_cast<uint64_t>(0x1e614000ULL) << 13);
    acc = (acc + a1 + 0x1e614021ULL) ^ 0x1d5a58ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0486 | PC: 0x07b064 | FDE: 0x1d5a70 | Size: 28 bytes [_Py_c_prod]
// Khung tháo gỡ #0486 | Địa chỉ PC: 0x07b064 | Địa chỉ FDE: 0x1d5a70 | Kích thước: 28 bytes
//   0x07b064: 1E620804  fmul     d4, d0, d2
//   0x07b068: 1E630825  fmul     d5, d1, d3
//   0x07b06c: 1E630803  fmul     d3, d0, d3
//   0x07b070: 1E620821  fmul     d1, d1, d2
static inline uint64_t fde_func_0486_0x07b064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b064ULL ^ (static_cast<uint64_t>(0x1e620804ULL) << 13);
    acc = (acc + a1 + 0x1e630825ULL) ^ 0x1d5a70ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0487 | PC: 0x07b080 | FDE: 0x1d5a88 | Size: 180 bytes [_Py_c_quot]
// Khung tháo gỡ #0487 | Địa chỉ PC: 0x07b080 | Địa chỉ FDE: 0x1d5a88 | Kích thước: 180 bytes
//   0x07b080: 1E614044  fneg     d4, d2
//   0x07b084: 1E602048  fcmp     d2, #0.0
//   0x07b088: 1E614065  fneg     d5, d3
//   0x07b08c: 1E624C84  fcsel    d4, d4, d2, mi
static inline uint64_t fde_func_0487_0x07b080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b080ULL ^ (static_cast<uint64_t>(0x1e614044ULL) << 13);
    acc = (acc + a1 + 0x1e602048ULL) ^ 0x1d5a88ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0488 | PC: 0x07b134 | FDE: 0x1d5aa8 | Size: 256 bytes [_Py_c_pow]
// Khung tháo gỡ #0488 | Địa chỉ PC: 0x07b134 | Địa chỉ FDE: 0x1d5aa8 | Kích thước: 256 bytes
//   0x07b134: D10143FF  sub      sp, sp, #0x50
//   0x07b138: 6D0133ED  stp      d13, d12, [sp, #0x10]
//   0x07b13c: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x07b140: 6D0323E9  stp      d9, d8, [sp, #0x30]
static inline uint64_t fde_func_0488_0x07b134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b134ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0133edULL) ^ 0x1d5aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0489 | PC: 0x07b238 | FDE: 0x1d5ad8 | Size: 188 bytes [_Py_c_abs]
// Khung tháo gỡ #0489 | Địa chỉ PC: 0x07b238 | Địa chỉ FDE: 0x1d5ad8 | Kích thước: 188 bytes
//   0x07b238: 6DBE23E9  stp      d9, d8, [sp, #-0x20]!
//   0x07b23c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b240: 910043FD  add      x29, sp, #0x10
//   0x07b244: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_0489_0x07b238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b238ULL ^ (static_cast<uint64_t>(0x6dbe23e9ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5ad8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0490 | PC: 0x07b2f4 | FDE: 0x1d5af8 | Size: 120 bytes [PyComplex_FromCComplex]
// Khung tháo gỡ #0490 | Địa chỉ PC: 0x07b2f4 | Địa chỉ FDE: 0x1d5af8 | Kích thước: 120 bytes
//   0x07b2f4: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x07b2f8: F9000BF3  str      x19, [sp, #0x10]
//   0x07b2fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b300: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0490_0x07b2f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b2f4ULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1d5af8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0491 | PC: 0x07b36c | FDE: 0x1d5b20 | Size: 120 bytes [PyComplex_FromDoubles]
// Khung tháo gỡ #0491 | Địa chỉ PC: 0x07b36c | Địa chỉ FDE: 0x1d5b20 | Kích thước: 120 bytes
//   0x07b36c: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x07b370: F9000BF3  str      x19, [sp, #0x10]
//   0x07b374: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b378: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0491_0x07b36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b36cULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1d5b20ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0492 | PC: 0x07b3e4 | FDE: 0x1d5b48 | Size: 84 bytes [PyComplex_RealAsDouble]
// Khung tháo gỡ #0492 | Địa chỉ PC: 0x07b3e4 | Địa chỉ FDE: 0x1d5b48 | Kích thước: 84 bytes
//   0x07b3e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07b3e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b3ec: 910043FD  add      x29, sp, #0x10
//   0x07b3f0: 90000C28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0492_0x07b3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b3e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5b48ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0493 | PC: 0x07b438 | FDE: 0x1d5b68 | Size: 76 bytes [PyComplex_ImagAsDouble]
// Khung tháo gỡ #0493 | Địa chỉ PC: 0x07b438 | Địa chỉ FDE: 0x1d5b68 | Kích thước: 76 bytes
//   0x07b438: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07b43c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b440: 910043FD  add      x29, sp, #0x10
//   0x07b444: 90000C28  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0493_0x07b438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b438ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5b68ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0494 | PC: 0x07b484 | FDE: 0x1d5b88 | Size: 160 bytes [PyComplex_AsCComplex]
// Khung tháo gỡ #0494 | Địa chỉ PC: 0x07b484 | Địa chỉ FDE: 0x1d5b88 | Kích thước: 160 bytes
//   0x07b484: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x07b488: F9000BF3  str      x19, [sp, #0x10]
//   0x07b48c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b490: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0494_0x07b484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b484ULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1d5b88ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0495 | PC: 0x07b524 | FDE: 0x1d5bb0 | Size: 256 bytes
// Khung tháo gỡ #0495 | Địa chỉ PC: 0x07b524 | Địa chỉ FDE: 0x1d5bb0 | Kích thước: 256 bytes
//   0x07b524: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b528: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b52c: 910043FD  add      x29, sp, #0x10
//   0x07b530: 90000C41  adrp     x1, #0x203000
static inline uint64_t fde_func_0495_0x07b524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b524ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0496 | PC: 0x07b664 | FDE: 0x1d5bd0 | Size: 256 bytes
// Khung tháo gỡ #0496 | Địa chỉ PC: 0x07b664 | Địa chỉ FDE: 0x1d5bd0 | Kích thước: 256 bytes
//   0x07b664: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07b668: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07b66c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b670: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0496_0x07b664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b664ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0497 | PC: 0x07b78c | FDE: 0x1d5bf0 | Size: 92 bytes
// Khung tháo gỡ #0497 | Địa chỉ PC: 0x07b78c | Địa chỉ FDE: 0x1d5bf0 | Kích thước: 92 bytes
//   0x07b78c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b790: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b794: 910043FD  add      x29, sp, #0x10
//   0x07b798: FD400800  ldr      d0, [x0, #0x10]
static inline uint64_t fde_func_0497_0x07b78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b78cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5bf0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0498 | PC: 0x07b7e8 | FDE: 0x1d5c10 | Size: 256 bytes
// Khung tháo gỡ #0498 | Địa chỉ PC: 0x07b7e8 | Địa chỉ FDE: 0x1d5c10 | Kích thước: 256 bytes
//   0x07b7e8: 6DBA2BEB  stp      d11, d10, [sp, #-0x60]!
//   0x07b7ec: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x07b7f0: F90013F7  str      x23, [sp, #0x20]
//   0x07b7f4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0498_0x07b7e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b7e8ULL ^ (static_cast<uint64_t>(0x6dba2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1d5c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0499 | PC: 0x07ba64 | FDE: 0x1d5c40 | Size: 256 bytes
// Khung tháo gỡ #0499 | Địa chỉ PC: 0x07ba64 | Địa chỉ FDE: 0x1d5c40 | Kích thước: 256 bytes
//   0x07ba64: D10243FF  sub      sp, sp, #0x90
//   0x07ba68: FD001BEA  str      d10, [sp, #0x30]
//   0x07ba6c: 6D03A3E9  stp      d9, d8, [sp, #0x38]
//   0x07ba70: F90027F9  str      x25, [sp, #0x48]
static inline uint64_t fde_func_0499_0x07ba64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ba64ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd001beaULL) ^ 0x1d5c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0500 | PC: 0x07be78 | FDE: 0x1d5c70 | Size: 256 bytes
// Khung tháo gỡ #0500 | Địa chỉ PC: 0x07be78 | Địa chỉ FDE: 0x1d5c70 | Kích thước: 256 bytes
//   0x07be78: 6DBB2BEB  stp      d11, d10, [sp, #-0x50]!
//   0x07be7c: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x07be80: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07be84: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0500_0x07be78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07be78ULL ^ (static_cast<uint64_t>(0x6dbb2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1d5c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0501 | PC: 0x07c03c | FDE: 0x1d5ca0 | Size: 256 bytes
// Khung tháo gỡ #0501 | Địa chỉ PC: 0x07c03c | Địa chỉ FDE: 0x1d5ca0 | Kích thước: 256 bytes
//   0x07c03c: 6DBB2BEB  stp      d11, d10, [sp, #-0x50]!
//   0x07c040: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x07c044: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07c048: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0501_0x07c03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c03cULL ^ (static_cast<uint64_t>(0x6dbb2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1d5ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0502 | PC: 0x07c200 | FDE: 0x1d5cd0 | Size: 256 bytes
// Khung tháo gỡ #0502 | Địa chỉ PC: 0x07c200 | Địa chỉ FDE: 0x1d5cd0 | Kích thước: 256 bytes
//   0x07c200: FC1A0FEC  str      d12, [sp, #-0x60]!
//   0x07c204: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x07c208: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x07c20c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0502_0x07c200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c200ULL ^ (static_cast<uint64_t>(0xfc1a0fecULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x1d5cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0503 | PC: 0x07c3e0 | FDE: 0x1d5d00 | Size: 256 bytes
// Khung tháo gỡ #0503 | Địa chỉ PC: 0x07c3e0 | Địa chỉ FDE: 0x1d5d00 | Kích thước: 256 bytes
//   0x07c3e0: 6DBA2BEB  stp      d11, d10, [sp, #-0x60]!
//   0x07c3e4: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x07c3e8: F90013F7  str      x23, [sp, #0x20]
//   0x07c3ec: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0503_0x07c3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c3e0ULL ^ (static_cast<uint64_t>(0x6dba2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1d5d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0504 | PC: 0x07c854 | FDE: 0x1d5d30 | Size: 136 bytes
// Khung tháo gỡ #0504 | Địa chỉ PC: 0x07c854 | Địa chỉ FDE: 0x1d5d30 | Kích thước: 136 bytes
//   0x07c854: FC1D0FEA  str      d10, [sp, #-0x30]!
//   0x07c858: 6D00A3E9  stp      d9, d8, [sp, #8]
//   0x07c85c: F9000FF3  str      x19, [sp, #0x18]
//   0x07c860: A9027BFD  stp      x29, x30, [sp, #0x20]
static inline uint64_t fde_func_0504_0x07c854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c854ULL ^ (static_cast<uint64_t>(0xfc1d0feaULL) << 13);
    acc = (acc + a1 + 0x6d00a3e9ULL) ^ 0x1d5d30ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0505 | PC: 0x07c8dc | FDE: 0x1d5d58 | Size: 148 bytes
// Khung tháo gỡ #0505 | Địa chỉ PC: 0x07c8dc | Địa chỉ FDE: 0x1d5d58 | Kích thước: 148 bytes
//   0x07c8dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07c8e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07c8e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07c8e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0505_0x07c8dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c8dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5d58ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0506 | PC: 0x07c970 | FDE: 0x1d5d80 | Size: 256 bytes
// Khung tháo gỡ #0506 | Địa chỉ PC: 0x07c970 | Địa chỉ FDE: 0x1d5d80 | Kích thước: 256 bytes
//   0x07c970: 6DBE23E9  stp      d9, d8, [sp, #-0x20]!
//   0x07c974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c978: 910043FD  add      x29, sp, #0x10
//   0x07c97c: 6D410400  ldp      d0, d1, [x0, #0x10]
static inline uint64_t fde_func_0506_0x07c970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c970ULL ^ (static_cast<uint64_t>(0x6dbe23e9ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5d80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0507 | PC: 0x07ca74 | FDE: 0x1d5da0 | Size: 36 bytes
// Khung tháo gỡ #0507 | Địa chỉ PC: 0x07ca74 | Địa chỉ FDE: 0x1d5da0 | Kích thước: 36 bytes
//   0x07ca74: FD400800  ldr      d0, [x0, #0x10]
//   0x07ca78: 1E602008  fcmp     d0, #0.0
//   0x07ca7c: 54000060  b.eq     #0x7ca88
//   0x07ca80: 52800020  mov      w0, #1
static inline uint64_t fde_func_0507_0x07ca74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ca74ULL ^ (static_cast<uint64_t>(0xfd400800ULL) << 13);
    acc = (acc + a1 + 0x1e602008ULL) ^ 0x1d5da0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0508 | PC: 0x07ca98 | FDE: 0x1d5db8 | Size: 256 bytes
// Khung tháo gỡ #0508 | Địa chỉ PC: 0x07ca98 | Địa chỉ FDE: 0x1d5db8 | Kích thước: 256 bytes
//   0x07ca98: 6DBB2BEB  stp      d11, d10, [sp, #-0x50]!
//   0x07ca9c: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x07caa0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07caa4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0508_0x07ca98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ca98ULL ^ (static_cast<uint64_t>(0x6dbb2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1d5db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0509 | PC: 0x07cd04 | FDE: 0x1d5de8 | Size: 128 bytes
// Khung tháo gỡ #0509 | Địa chỉ PC: 0x07cd04 | Địa chỉ FDE: 0x1d5de8 | Kích thước: 128 bytes
//   0x07cd04: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x07cd08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07cd0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07cd10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0509_0x07cd04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd04ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5de8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0510 | PC: 0x07cd84 | FDE: 0x1d5e08 | Size: 16 bytes
// Khung tháo gỡ #0510 | Địa chỉ PC: 0x07cd84 | Địa chỉ FDE: 0x1d5e08 | Kích thước: 16 bytes
//   0x07cd84: 6D410400  ldp      d0, d1, [x0, #0x10]
//   0x07cd88: 90000940  adrp     x0, #0x1a4000
//   0x07cd8c: 913A8000  add      x0, x0, #0xea0
//   0x07cd90: 17FF78CC  b        #0x5b0c0
static inline uint64_t fde_func_0510_0x07cd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd84ULL ^ (static_cast<uint64_t>(0x6d410400ULL) << 13);
    acc = (acc + a1 + 0x90000940ULL) ^ 0x1d5e08ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0511 | PC: 0x07cd94 | FDE: 0x1d5e20 | Size: 216 bytes
// Khung tháo gỡ #0511 | Địa chỉ PC: 0x07cd94 | Địa chỉ FDE: 0x1d5e20 | Kích thước: 216 bytes
//   0x07cd94: D101C3FF  sub      sp, sp, #0x70
//   0x07cd98: F90023F5  str      x21, [sp, #0x40]
//   0x07cd9c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x07cda0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0511_0x07cd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd94ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1d5e20ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0512 | PC: 0x07ce6c | FDE: 0x1d5e40 | Size: 256 bytes
// Khung tháo gỡ #0512 | Địa chỉ PC: 0x07ce6c | Địa chỉ FDE: 0x1d5e40 | Kích thước: 256 bytes
//   0x07ce6c: D10203FF  sub      sp, sp, #0x80
//   0x07ce70: FD000BEA  str      d10, [sp, #0x10]
//   0x07ce74: 6D01A3E9  stp      d9, d8, [sp, #0x18]
//   0x07ce78: F90017FB  str      x27, [sp, #0x28]
static inline uint64_t fde_func_0512_0x07ce6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ce6cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xfd000beaULL) ^ 0x1d5e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0513 | PC: 0x07d0c4 | FDE: 0x1d5e78 | Size: 136 bytes
// Khung tháo gỡ #0513 | Địa chỉ PC: 0x07d0c4 | Địa chỉ FDE: 0x1d5e78 | Kích thước: 136 bytes
//   0x07d0c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07d0c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d0cc: 910043FD  add      x29, sp, #0x10
//   0x07d0d0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0513_0x07d0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d0c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5e78ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0514 | PC: 0x07d14c | FDE: 0x1d5e98 | Size: 60 bytes
// Khung tháo gỡ #0514 | Địa chỉ PC: 0x07d14c | Địa chỉ FDE: 0x1d5e98 | Kích thước: 60 bytes
//   0x07d14c: F9400C08  ldr      x8, [x0, #0x18]
//   0x07d150: B40000C8  cbz      x8, #0x7d168
//   0x07d154: F9400509  ldr      x9, [x8, #8]
//   0x07d158: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_0514_0x07d14c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d14cULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x1d5e98ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0515 | PC: 0x07d188 | FDE: 0x1d5eb0 | Size: 52 bytes
// Khung tháo gỡ #0515 | Địa chỉ PC: 0x07d188 | Địa chỉ FDE: 0x1d5eb0 | Kích thước: 52 bytes
//   0x07d188: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07d18c: 910003FD  mov      x29, sp
//   0x07d190: F9400800  ldr      x0, [x0, #0x10]
//   0x07d194: B40000E0  cbz      x0, #0x7d1b0
static inline uint64_t fde_func_0515_0x07d188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d188ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d5eb0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0516 | PC: 0x07d1bc | FDE: 0x1d5ed0 | Size: 256 bytes
// Khung tháo gỡ #0516 | Địa chỉ PC: 0x07d1bc | Địa chỉ FDE: 0x1d5ed0 | Kích thước: 256 bytes
//   0x07d1bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07d1c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07d1c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07d1c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0516_0x07d1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d1bcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5ed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0517 | PC: 0x07d2f0 | FDE: 0x1d5ef0 | Size: 204 bytes
// Khung tháo gỡ #0517 | Địa chỉ PC: 0x07d2f0 | Địa chỉ FDE: 0x1d5ef0 | Kích thước: 204 bytes
//   0x07d2f0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07d2f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07d2f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07d2fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0517_0x07d2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d2f0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5ef0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0518 | PC: 0x07d3bc | FDE: 0x1d5f18 | Size: 256 bytes
// Khung tháo gỡ #0518 | Địa chỉ PC: 0x07d3bc | Địa chỉ FDE: 0x1d5f18 | Kích thước: 256 bytes
//   0x07d3bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d3c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d3c4: 910043FD  add      x29, sp, #0x10
//   0x07d3c8: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0518_0x07d3bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d3bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0519 | PC: 0x07d510 | FDE: 0x1d5f38 | Size: 60 bytes
// Khung tháo gỡ #0519 | Địa chỉ PC: 0x07d510 | Địa chỉ FDE: 0x1d5f38 | Kích thước: 60 bytes
//   0x07d510: F9400C08  ldr      x8, [x0, #0x18]
//   0x07d514: B40000C8  cbz      x8, #0x7d52c
//   0x07d518: F9400509  ldr      x9, [x8, #8]
//   0x07d51c: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_0519_0x07d510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d510ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x1d5f38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0520 | PC: 0x07d54c | FDE: 0x1d5f50 | Size: 228 bytes
// Khung tháo gỡ #0520 | Địa chỉ PC: 0x07d54c | Địa chỉ FDE: 0x1d5f50 | Kích thước: 228 bytes
//   0x07d54c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d550: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d554: 910043FD  add      x29, sp, #0x10
//   0x07d558: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0520_0x07d54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d54cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5f50ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0521 | PC: 0x07d630 | FDE: 0x1d5f70 | Size: 180 bytes
// Khung tháo gỡ #0521 | Địa chỉ PC: 0x07d630 | Địa chỉ FDE: 0x1d5f70 | Kích thước: 180 bytes
//   0x07d630: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07d634: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07d638: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07d63c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0521_0x07d630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d630ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5f70ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0522 | PC: 0x07d6e4 | FDE: 0x1d5f90 | Size: 60 bytes
// Khung tháo gỡ #0522 | Địa chỉ PC: 0x07d6e4 | Địa chỉ FDE: 0x1d5f90 | Kích thước: 60 bytes
//   0x07d6e4: F9400C08  ldr      x8, [x0, #0x18]
//   0x07d6e8: B40000C8  cbz      x8, #0x7d700
//   0x07d6ec: F9400509  ldr      x9, [x8, #8]
//   0x07d6f0: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_0522_0x07d6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d6e4ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x1d5f90ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0523 | PC: 0x07d720 | FDE: 0x1d5fa8 | Size: 256 bytes
// Khung tháo gỡ #0523 | Địa chỉ PC: 0x07d720 | Địa chỉ FDE: 0x1d5fa8 | Kích thước: 256 bytes
//   0x07d720: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d724: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d728: 910043FD  add      x29, sp, #0x10
//   0x07d72c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0523_0x07d720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d720ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d5fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0524 | PC: 0x07d830 | FDE: 0x1d5fc8 | Size: 256 bytes
// Khung tháo gỡ #0524 | Địa chỉ PC: 0x07d830 | Địa chỉ FDE: 0x1d5fc8 | Kích thước: 256 bytes
//   0x07d830: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07d834: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07d838: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07d83c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0524_0x07d830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d830ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d5fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x07d93c | FDE: 0x1d5fe8 | Size: 60 bytes
// Khung tháo gỡ #0525 | Địa chỉ PC: 0x07d93c | Địa chỉ FDE: 0x1d5fe8 | Kích thước: 60 bytes
//   0x07d93c: F9400C08  ldr      x8, [x0, #0x18]
//   0x07d940: B40000C8  cbz      x8, #0x7d958
//   0x07d944: F9400509  ldr      x9, [x8, #8]
//   0x07d948: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_0525_0x07d93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d93cULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x1d5fe8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0526 | PC: 0x07d978 | FDE: 0x1d6000 | Size: 256 bytes
// Khung tháo gỡ #0526 | Địa chỉ PC: 0x07d978 | Địa chỉ FDE: 0x1d6000 | Kích thước: 256 bytes
//   0x07d978: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07d97c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07d980: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07d984: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0526_0x07d978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d978ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0527 | PC: 0x07db28 | FDE: 0x1d6028 | Size: 220 bytes
// Khung tháo gỡ #0527 | Địa chỉ PC: 0x07db28 | Địa chỉ FDE: 0x1d6028 | Kích thước: 220 bytes
//   0x07db28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07db2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07db30: 910043FD  add      x29, sp, #0x10
//   0x07db34: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0527_0x07db28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07db28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6028ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0528 | PC: 0x07dc04 | FDE: 0x1d6048 | Size: 256 bytes [PyDescr_NewMethod]
// Khung tháo gỡ #0528 | Địa chỉ PC: 0x07dc04 | Địa chỉ FDE: 0x1d6048 | Kích thước: 256 bytes
//   0x07dc04: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07dc08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07dc0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07dc10: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0528_0x07dc04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dc04ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0529 | PC: 0x07dd50 | FDE: 0x1d6070 | Size: 256 bytes
// Khung tháo gỡ #0529 | Địa chỉ PC: 0x07dd50 | Địa chỉ FDE: 0x1d6070 | Kích thước: 256 bytes
//   0x07dd50: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07dd54: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07dd58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07dd5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0529_0x07dd50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd50ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0530 | PC: 0x07de58 | FDE: 0x1d6098 | Size: 256 bytes
// Khung tháo gỡ #0530 | Địa chỉ PC: 0x07de58 | Địa chỉ FDE: 0x1d6098 | Kích thước: 256 bytes
//   0x07de58: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x07de5c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07de60: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07de64: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0530_0x07de58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07de58ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d6098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0531 | PC: 0x07dfa8 | FDE: 0x1d60c0 | Size: 188 bytes
// Khung tháo gỡ #0531 | Địa chỉ PC: 0x07dfa8 | Địa chỉ FDE: 0x1d60c0 | Kích thước: 188 bytes
//   0x07dfa8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07dfac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07dfb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07dfb4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0531_0x07dfa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dfa8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d60c0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0532 | PC: 0x07e064 | FDE: 0x1d60e8 | Size: 192 bytes
// Khung tháo gỡ #0532 | Địa chỉ PC: 0x07e064 | Địa chỉ FDE: 0x1d60e8 | Kích thước: 192 bytes
//   0x07e064: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07e068: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e06c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e070: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0532_0x07e064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e064ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d60e8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0533 | PC: 0x07e124 | FDE: 0x1d6110 | Size: 256 bytes
// Khung tháo gỡ #0533 | Địa chỉ PC: 0x07e124 | Địa chỉ FDE: 0x1d6110 | Kích thước: 256 bytes
//   0x07e124: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07e128: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e12c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e130: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0533_0x07e124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e124ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0534 | PC: 0x07e230 | FDE: 0x1d6138 | Size: 256 bytes
// Khung tháo gỡ #0534 | Địa chỉ PC: 0x07e230 | Địa chỉ FDE: 0x1d6138 | Kích thước: 256 bytes
//   0x07e230: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07e234: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e238: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e23c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0534_0x07e230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e230ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0535 | PC: 0x07e338 | FDE: 0x1d6160 | Size: 208 bytes
// Khung tháo gỡ #0535 | Địa chỉ PC: 0x07e338 | Địa chỉ FDE: 0x1d6160 | Kích thước: 208 bytes
//   0x07e338: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07e33c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e340: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e344: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0535_0x07e338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e338ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6160ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0536 | PC: 0x07e408 | FDE: 0x1d6188 | Size: 132 bytes [PyDescr_NewClassMethod]
// Khung tháo gỡ #0536 | Địa chỉ PC: 0x07e408 | Địa chỉ FDE: 0x1d6188 | Kích thước: 132 bytes
//   0x07e408: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07e40c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07e410: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07e414: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0536_0x07e408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e408ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6188ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0537 | PC: 0x07e48c | FDE: 0x1d61b0 | Size: 132 bytes [PyDescr_NewMember]
// Khung tháo gỡ #0537 | Địa chỉ PC: 0x07e48c | Địa chỉ FDE: 0x1d61b0 | Kích thước: 132 bytes
//   0x07e48c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07e490: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07e494: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07e498: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0537_0x07e48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e48cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d61b0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0538 | PC: 0x07e510 | FDE: 0x1d61d8 | Size: 132 bytes [PyDescr_NewGetSet]
// Khung tháo gỡ #0538 | Địa chỉ PC: 0x07e510 | Địa chỉ FDE: 0x1d61d8 | Kích thước: 132 bytes
//   0x07e510: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07e514: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07e518: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07e51c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0538_0x07e510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e510ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d61d8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0539 | PC: 0x07e594 | FDE: 0x1d6200 | Size: 144 bytes [PyDescr_NewWrapper]
// Khung tháo gỡ #0539 | Địa chỉ PC: 0x07e594 | Địa chỉ FDE: 0x1d6200 | Kích thước: 144 bytes
//   0x07e594: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07e598: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e59c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e5a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0539_0x07e594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e594ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d6200ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0540 | PC: 0x07e624 | FDE: 0x1d6228 | Size: 20 bytes [PyDescr_IsData]
// Khung tháo gỡ #0540 | Địa chỉ PC: 0x07e624 | Địa chỉ FDE: 0x1d6228 | Kích thước: 20 bytes
//   0x07e624: F9400408  ldr      x8, [x0, #8]
//   0x07e628: F9408D08  ldr      x8, [x8, #0x118]
//   0x07e62c: F100011F  cmp      x8, #0
//   0x07e630: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_0540_0x07e624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e624ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9408d08ULL) ^ 0x1d6228ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0541 | PC: 0x07e638 | FDE: 0x1d6240 | Size: 120 bytes [PyDictProxy_New]
// Khung tháo gỡ #0541 | Địa chỉ PC: 0x07e638 | Địa chỉ FDE: 0x1d6240 | Kích thước: 120 bytes
//   0x07e638: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07e63c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e640: 910043FD  add      x29, sp, #0x10
//   0x07e644: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0541_0x07e638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e638ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6240ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0542 | PC: 0x07e6b0 | FDE: 0x1d6260 | Size: 172 bytes
// Khung tháo gỡ #0542 | Địa chỉ PC: 0x07e6b0 | Địa chỉ FDE: 0x1d6260 | Kích thước: 172 bytes
//   0x07e6b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07e6b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e6b8: 910043FD  add      x29, sp, #0x10
//   0x07e6bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0542_0x07e6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e6b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6260ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0543 | PC: 0x07e75c | FDE: 0x1d6280 | Size: 32 bytes
// Khung tháo gỡ #0543 | Địa chỉ PC: 0x07e75c | Địa chỉ FDE: 0x1d6280 | Kích thước: 32 bytes
//   0x07e75c: A9410C08  ldp      x8, x3, [x0, #0x10]
//   0x07e760: F0000920  adrp     x0, #0x1a5000
//   0x07e764: 9112A000  add      x0, x0, #0x4a8
//   0x07e768: F9401508  ldr      x8, [x8, #0x28]
static inline uint64_t fde_func_0543_0x07e75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e75cULL ^ (static_cast<uint64_t>(0xa9410c08ULL) << 13);
    acc = (acc + a1 + 0xf0000920ULL) ^ 0x1d6280ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0544 | PC: 0x07e77c | FDE: 0x1d6298 | Size: 68 bytes
// Khung tháo gỡ #0544 | Địa chỉ PC: 0x07e77c | Địa chỉ FDE: 0x1d6298 | Kích thước: 68 bytes
//   0x07e77c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07e780: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e784: 910043FD  add      x29, sp, #0x10
//   0x07e788: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0544_0x07e77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e77cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6298ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0545 | PC: 0x07e7c0 | FDE: 0x1d62b8 | Size: 120 bytes
// Khung tháo gỡ #0545 | Địa chỉ PC: 0x07e7c0 | Địa chỉ FDE: 0x1d62b8 | Kích thước: 120 bytes
//   0x07e7c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07e7c4: 910003FD  mov      x29, sp
//   0x07e7c8: A9410008  ldp      x8, x0, [x0, #0x10]
//   0x07e7cc: AA0203E3  mov      x3, x2
static inline uint64_t fde_func_0545_0x07e7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e7c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d62b8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0546 | PC: 0x07e838 | FDE: 0x1d62d8 | Size: 88 bytes
// Khung tháo gỡ #0546 | Địa chỉ PC: 0x07e838 | Địa chỉ FDE: 0x1d62d8 | Kích thước: 88 bytes
//   0x07e838: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07e83c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07e840: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07e844: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0546_0x07e838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e838ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d62d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0547 | PC: 0x07e890 | FDE: 0x1d62f8 | Size: 144 bytes
// Khung tháo gỡ #0547 | Địa chỉ PC: 0x07e890 | Địa chỉ FDE: 0x1d62f8 | Kích thước: 144 bytes
//   0x07e890: 32000048  orr      w8, w2, #1
//   0x07e894: 71000D1F  cmp      w8, #3
//   0x07e898: 54000121  b.ne     #0x7e8bc
//   0x07e89c: B0000C08  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0547_0x07e890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e890ULL ^ (static_cast<uint64_t>(0x32000048ULL) << 13);
    acc = (acc + a1 + 0x71000d1fULL) ^ 0x1d62f8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0548 | PC: 0x07e920 | FDE: 0x1d6310 | Size: 80 bytes [PyWrapper_New]
// Khung tháo gỡ #0548 | Địa chỉ PC: 0x07e920 | Địa chỉ FDE: 0x1d6310 | Kích thước: 80 bytes
//   0x07e920: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07e924: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e928: 910043FD  add      x29, sp, #0x10
//   0x07e92c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0548_0x07e920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e920ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6310ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0549 | PC: 0x07e970 | FDE: 0x1d6330 | Size: 56 bytes
// Khung tháo gỡ #0549 | Địa chỉ PC: 0x07e970 | Địa chỉ FDE: 0x1d6330 | Kích thước: 56 bytes
//   0x07e970: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07e974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e978: 910043FD  add      x29, sp, #0x10
//   0x07e97c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0549_0x07e970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e970ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6330ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0550 | PC: 0x07e9a8 | FDE: 0x1d6350 | Size: 16 bytes
// Khung tháo gỡ #0550 | Địa chỉ PC: 0x07e9a8 | Địa chỉ FDE: 0x1d6350 | Kích thước: 16 bytes
//   0x07e9a8: F9400801  ldr      x1, [x0, #0x10]
//   0x07e9ac: F0000920  adrp     x0, #0x1a5000
//   0x07e9b0: 91134400  add      x0, x0, #0x4d1
//   0x07e9b4: 17FF663F  b        #0x582b0
static inline uint64_t fde_func_0550_0x07e9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e9a8ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xf0000920ULL) ^ 0x1d6350ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0551 | PC: 0x07e9b8 | FDE: 0x1d6368 | Size: 8 bytes
// Khung tháo gỡ #0551 | Địa chỉ PC: 0x07e9b8 | Địa chỉ FDE: 0x1d6368 | Kích thước: 8 bytes
//   0x07e9b8: F9400800  ldr      x0, [x0, #0x10]
//   0x07e9bc: 17FF6B55  b        #0x59710
static inline uint64_t fde_func_0551_0x07e9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e9b8ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17ff6b55ULL) ^ 0x1d6368ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0552 | PC: 0x07e9c0 | FDE: 0x1d6380 | Size: 52 bytes
// Khung tháo gỡ #0552 | Địa chỉ PC: 0x07e9c0 | Địa chỉ FDE: 0x1d6380 | Kích thước: 52 bytes
//   0x07e9c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07e9c4: 910003FD  mov      x29, sp
//   0x07e9c8: F9400800  ldr      x0, [x0, #0x10]
//   0x07e9cc: B40000E0  cbz      x0, #0x7e9e8
static inline uint64_t fde_func_0552_0x07e9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e9c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6380ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0553 | PC: 0x07e9f4 | FDE: 0x1d63a0 | Size: 8 bytes
// Khung tháo gỡ #0553 | Địa chỉ PC: 0x07e9f4 | Địa chỉ FDE: 0x1d63a0 | Kích thước: 8 bytes
//   0x07e9f4: F9400800  ldr      x0, [x0, #0x10]
//   0x07e9f8: 17FF6BAA  b        #0x598a0
static inline uint64_t fde_func_0553_0x07e9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e9f4ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17ff6baaULL) ^ 0x1d63a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0554 | PC: 0x07e9fc | FDE: 0x1d63b8 | Size: 8 bytes
// Khung tháo gỡ #0554 | Địa chỉ PC: 0x07e9fc | Địa chỉ FDE: 0x1d63b8 | Kích thước: 8 bytes
//   0x07e9fc: F9400800  ldr      x0, [x0, #0x10]
//   0x07ea00: 17FF76E4  b        #0x5c590
static inline uint64_t fde_func_0554_0x07e9fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e9fcULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17ff76e4ULL) ^ 0x1d63b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0555 | PC: 0x07ea04 | FDE: 0x1d63d0 | Size: 228 bytes
// Khung tháo gỡ #0555 | Địa chỉ PC: 0x07ea04 | Địa chỉ FDE: 0x1d63d0 | Kích thước: 228 bytes
//   0x07ea04: D10103FF  sub      sp, sp, #0x40
//   0x07ea08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07ea0c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07ea10: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0555_0x07ea04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ea04ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1d63d0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0556 | PC: 0x07eae8 | FDE: 0x1d63f0 | Size: 220 bytes
// Khung tháo gỡ #0556 | Địa chỉ PC: 0x07eae8 | Địa chỉ FDE: 0x1d63f0 | Kích thước: 220 bytes
//   0x07eae8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07eaec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07eaf0: 910043FD  add      x29, sp, #0x10
//   0x07eaf4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0556_0x07eae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07eae8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d63f0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0557 | PC: 0x07ebc4 | FDE: 0x1d6410 | Size: 148 bytes
// Khung tháo gỡ #0557 | Địa chỉ PC: 0x07ebc4 | Địa chỉ FDE: 0x1d6410 | Kích thước: 148 bytes
//   0x07ebc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07ebc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07ebcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07ebd0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0557_0x07ebc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ebc4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6410ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0558 | PC: 0x07ec58 | FDE: 0x1d6430 | Size: 56 bytes
// Khung tháo gỡ #0558 | Địa chỉ PC: 0x07ec58 | Địa chỉ FDE: 0x1d6430 | Kích thước: 56 bytes
//   0x07ec58: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07ec5c: 910003FD  mov      x29, sp
//   0x07ec60: AA0003E8  mov      x8, x0
//   0x07ec64: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_0558_0x07ec58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ec58ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6430ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0559 | PC: 0x07ec90 | FDE: 0x1d6450 | Size: 256 bytes
// Khung tháo gỡ #0559 | Địa chỉ PC: 0x07ec90 | Địa chỉ FDE: 0x1d6450 | Kích thước: 256 bytes
//   0x07ec90: D10143FF  sub      sp, sp, #0x50
//   0x07ec94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07ec98: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07ec9c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0559_0x07ec90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ec90ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d6450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0560 | PC: 0x07edac | FDE: 0x1d6478 | Size: 256 bytes
// Khung tháo gỡ #0560 | Địa chỉ PC: 0x07edac | Địa chỉ FDE: 0x1d6478 | Kích thước: 256 bytes
//   0x07edac: D10143FF  sub      sp, sp, #0x50
//   0x07edb0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07edb4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07edb8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0560_0x07edac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07edacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d6478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0561 | PC: 0x07ef10 | FDE: 0x1d64a0 | Size: 256 bytes
// Khung tháo gỡ #0561 | Địa chỉ PC: 0x07ef10 | Địa chỉ FDE: 0x1d64a0 | Kích thước: 256 bytes
//   0x07ef10: D10243FF  sub      sp, sp, #0x90
//   0x07ef14: F90023F9  str      x25, [sp, #0x40]
//   0x07ef18: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x07ef1c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0561_0x07ef10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ef10ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x1d64a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0562 | PC: 0x07f1dc | FDE: 0x1d64c8 | Size: 24 bytes
// Khung tháo gỡ #0562 | Địa chỉ PC: 0x07f1dc | Địa chỉ FDE: 0x1d64c8 | Kích thước: 24 bytes
//   0x07f1dc: F9400008  ldr      x8, [x0]
//   0x07f1e0: F1000508  subs     x8, x8, #1
//   0x07f1e4: F9000008  str      x8, [x0]
//   0x07f1e8: 54000040  b.eq     #0x7f1f0
static inline uint64_t fde_func_0562_0x07f1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f1dcULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf1000508ULL) ^ 0x1d64c8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0563 | PC: 0x07f1f4 | FDE: 0x1d64e0 | Size: 60 bytes
// Khung tháo gỡ #0563 | Địa chỉ PC: 0x07f1f4 | Địa chỉ FDE: 0x1d64e0 | Kích thước: 60 bytes
//   0x07f1f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07f1f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f1fc: 910043FD  add      x29, sp, #0x10
//   0x07f200: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0563_0x07f1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f1f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d64e0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0564 | PC: 0x07f230 | FDE: 0x1d6500 | Size: 16 bytes
// Khung tháo gỡ #0564 | Địa chỉ PC: 0x07f230 | Địa chỉ FDE: 0x1d6500 | Kích thước: 16 bytes
//   0x07f230: F9401408  ldr      x8, [x0, #0x28]
//   0x07f234: F9400100  ldr      x0, [x8]
//   0x07f238: F9400D01  ldr      x1, [x8, #0x18]
//   0x07f23c: 17FF67D1  b        #0x59180
static inline uint64_t fde_func_0564_0x07f230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f230ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x1d6500ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0565 | PC: 0x07f240 | FDE: 0x1d6518 | Size: 256 bytes
// Khung tháo gỡ #0565 | Địa chỉ PC: 0x07f240 | Địa chỉ FDE: 0x1d6518 | Kích thước: 256 bytes
//   0x07f240: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07f244: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f248: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f24c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0565_0x07f240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f240ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0566 | PC: 0x07f348 | FDE: 0x1d6538 | Size: 16 bytes
// Khung tháo gỡ #0566 | Địa chỉ PC: 0x07f348 | Địa chỉ FDE: 0x1d6538 | Kích thước: 16 bytes
//   0x07f348: F9401408  ldr      x8, [x0, #0x28]
//   0x07f34c: F9400100  ldr      x0, [x8]
//   0x07f350: F9400D01  ldr      x1, [x8, #0x18]
//   0x07f354: 17FF7857  b        #0x5d4b0
static inline uint64_t fde_func_0566_0x07f348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f348ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x1d6538ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0567 | PC: 0x07f358 | FDE: 0x1d6550 | Size: 40 bytes
// Khung tháo gỡ #0567 | Địa chỉ PC: 0x07f358 | Địa chỉ FDE: 0x1d6550 | Kích thước: 40 bytes
//   0x07f358: F9401408  ldr      x8, [x0, #0x28]
//   0x07f35c: F9401100  ldr      x0, [x8, #0x20]
//   0x07f360: B4000040  cbz      x0, #0x7f368
//   0x07f364: 17FF7457  b        #0x5c4c0
static inline uint64_t fde_func_0567_0x07f358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f358ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9401100ULL) ^ 0x1d6550ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0568 | PC: 0x07f380 | FDE: 0x1d6568 | Size: 40 bytes
// Khung tháo gỡ #0568 | Địa chỉ PC: 0x07f380 | Địa chỉ FDE: 0x1d6568 | Kích thước: 40 bytes
//   0x07f380: F9401408  ldr      x8, [x0, #0x28]
//   0x07f384: F9400D00  ldr      x0, [x8, #0x18]
//   0x07f388: B4000040  cbz      x0, #0x7f390
//   0x07f38c: 17FF744D  b        #0x5c4c0
static inline uint64_t fde_func_0568_0x07f380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f380ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400d00ULL) ^ 0x1d6568ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0569 | PC: 0x07f3a8 | FDE: 0x1d6580 | Size: 16 bytes
// Khung tháo gỡ #0569 | Địa chỉ PC: 0x07f3a8 | Địa chỉ FDE: 0x1d6580 | Kích thước: 16 bytes
//   0x07f3a8: F9401408  ldr      x8, [x0, #0x28]
//   0x07f3ac: F9400100  ldr      x0, [x8]
//   0x07f3b0: F9401101  ldr      x1, [x8, #0x20]
//   0x07f3b4: 17FF6773  b        #0x59180
static inline uint64_t fde_func_0569_0x07f3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f3a8ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x1d6580ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0570 | PC: 0x07f3b8 | FDE: 0x1d6598 | Size: 16 bytes
// Khung tháo gỡ #0570 | Địa chỉ PC: 0x07f3b8 | Địa chỉ FDE: 0x1d6598 | Kích thước: 16 bytes
//   0x07f3b8: F9401408  ldr      x8, [x0, #0x28]
//   0x07f3bc: F9400100  ldr      x0, [x8]
//   0x07f3c0: F9401101  ldr      x1, [x8, #0x20]
//   0x07f3c4: 17FF783B  b        #0x5d4b0
static inline uint64_t fde_func_0570_0x07f3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f3b8ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x1d6598ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0571 | PC: 0x07f3c8 | FDE: 0x1d65b0 | Size: 256 bytes
// Khung tháo gỡ #0571 | Địa chỉ PC: 0x07f3c8 | Địa chỉ FDE: 0x1d65b0 | Kích thước: 256 bytes
//   0x07f3c8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07f3cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f3d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f3d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0571_0x07f3c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f3c8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d65b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0572 | PC: 0x07f4fc | FDE: 0x1d65d0 | Size: 64 bytes
// Khung tháo gỡ #0572 | Địa chỉ PC: 0x07f4fc | Địa chỉ FDE: 0x1d65d0 | Kích thước: 64 bytes
//   0x07f4fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07f500: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f504: 910043FD  add      x29, sp, #0x10
//   0x07f508: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0572_0x07f4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f4fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d65d0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0573 | PC: 0x07f53c | FDE: 0x1d65f0 | Size: 24 bytes
// Khung tháo gỡ #0573 | Địa chỉ PC: 0x07f53c | Địa chỉ FDE: 0x1d65f0 | Kích thước: 24 bytes
//   0x07f53c: F9400808  ldr      x8, [x0, #0x10]
//   0x07f540: F9400900  ldr      x0, [x8, #0x10]
//   0x07f544: F9400008  ldr      x8, [x0]
//   0x07f548: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_0573_0x07f53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f53cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400900ULL) ^ 0x1d65f0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0574 | PC: 0x07f554 | FDE: 0x1d6608 | Size: 16 bytes
// Khung tháo gỡ #0574 | Địa chỉ PC: 0x07f554 | Địa chỉ FDE: 0x1d6608 | Kích thước: 16 bytes
//   0x07f554: F9400808  ldr      x8, [x0, #0x10]
//   0x07f558: F9401508  ldr      x8, [x8, #0x28]
//   0x07f55c: F9400100  ldr      x0, [x8]
//   0x07f560: 17FF73D8  b        #0x5c4c0
static inline uint64_t fde_func_0574_0x07f554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f554ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9401508ULL) ^ 0x1d6608ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0575 | PC: 0x07f564 | FDE: 0x1d6620 | Size: 12 bytes
// Khung tháo gỡ #0575 | Địa chỉ PC: 0x07f564 | Địa chỉ FDE: 0x1d6620 | Kích thước: 12 bytes
//   0x07f564: F9400800  ldr      x0, [x0, #0x10]
//   0x07f568: AA1F03E1  mov      x1, xzr
//   0x07f56c: 17FFFF35  b        #0x7f240
static inline uint64_t fde_func_0575_0x07f564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f564ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1d6620ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0576 | PC: 0x07f570 | FDE: 0x1d6638 | Size: 20 bytes
// Khung tháo gỡ #0576 | Địa chỉ PC: 0x07f570 | Địa chỉ FDE: 0x1d6638 | Kích thước: 20 bytes
//   0x07f570: F9400808  ldr      x8, [x0, #0x10]
//   0x07f574: F9401508  ldr      x8, [x8, #0x28]
//   0x07f578: F9400100  ldr      x0, [x8]
//   0x07f57c: F9401101  ldr      x1, [x8, #0x20]
static inline uint64_t fde_func_0576_0x07f570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f570ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9401508ULL) ^ 0x1d6638ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0577 | PC: 0x07f584 | FDE: 0x1d6650 | Size: 20 bytes
// Khung tháo gỡ #0577 | Địa chỉ PC: 0x07f584 | Địa chỉ FDE: 0x1d6650 | Kích thước: 20 bytes
//   0x07f584: F9400808  ldr      x8, [x0, #0x10]
//   0x07f588: F9401508  ldr      x8, [x8, #0x28]
//   0x07f58c: F9400100  ldr      x0, [x8]
//   0x07f590: F9401101  ldr      x1, [x8, #0x20]
static inline uint64_t fde_func_0577_0x07f584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f584ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9401508ULL) ^ 0x1d6650ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0578 | PC: 0x07f598 | FDE: 0x1d6668 | Size: 120 bytes
// Khung tháo gỡ #0578 | Địa chỉ PC: 0x07f598 | Địa chỉ FDE: 0x1d6668 | Kích thước: 120 bytes
//   0x07f598: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07f59c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f5a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f5a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0578_0x07f598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f598ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6668ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0579 | PC: 0x07f610 | FDE: 0x1d6688 | Size: 32 bytes
// Khung tháo gỡ #0579 | Địa chỉ PC: 0x07f610 | Địa chỉ FDE: 0x1d6688 | Kích thước: 32 bytes
//   0x07f610: 90000C09  adrp     x9, #0x1ff000
//   0x07f614: F9400408  ldr      x8, [x0, #8]
//   0x07f618: F9447929  ldr      x9, [x9, #0x8f0]
//   0x07f61c: D0000921  adrp     x1, #0x1a5000
static inline uint64_t fde_func_0579_0x07f610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f610ULL ^ (static_cast<uint64_t>(0x90000c09ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1d6688ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0580 | PC: 0x07f630 | FDE: 0x1d66a0 | Size: 32 bytes
// Khung tháo gỡ #0580 | Địa chỉ PC: 0x07f630 | Địa chỉ FDE: 0x1d66a0 | Kích thước: 32 bytes
//   0x07f630: F9400800  ldr      x0, [x0, #0x10]
//   0x07f634: 90000C09  adrp     x9, #0x1ff000
//   0x07f638: F9400408  ldr      x8, [x0, #8]
//   0x07f63c: F9468529  ldr      x9, [x9, #0xd08]
static inline uint64_t fde_func_0580_0x07f630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f630ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x90000c09ULL) ^ 0x1d66a0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0581 | PC: 0x07f650 | FDE: 0x1d66b8 | Size: 256 bytes
// Khung tháo gỡ #0581 | Địa chỉ PC: 0x07f650 | Địa chỉ FDE: 0x1d66b8 | Kích thước: 256 bytes
//   0x07f650: F9400800  ldr      x0, [x0, #0x10]
//   0x07f654: 17FF6FDF  b        #0x5b5d0
//   0x07f658: F9400800  ldr      x0, [x0, #0x10]
//   0x07f65c: 17FF69C9  b        #0x59d80
static inline uint64_t fde_func_0581_0x07f650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f650ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17ff6fdfULL) ^ 0x1d66b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0582 | PC: 0x080474 | FDE: 0x1d6a18 | Size: 256 bytes [BDPythonVMSimpleExtendsExceptionInitImpl]
// Khung tháo gỡ #0582 | Địa chỉ PC: 0x080474 | Địa chỉ FDE: 0x1d6a18 | Kích thước: 256 bytes
//   0x080474: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x080478: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08047c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x080480: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0582_0x080474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080474ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6a18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0583 | PC: 0x080818 | FDE: 0x1d6ae0 | Size: 256 bytes [BDPythonVMMiddlingExtendsExceptionStoreOSErrorImpl]
// Khung tháo gỡ #0583 | Địa chỉ PC: 0x080818 | Địa chỉ FDE: 0x1d6ae0 | Kích thước: 256 bytes
//   0x080818: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08081c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x080820: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x080824: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0583_0x080818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080818ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0584 | PC: 0x080ba4 | FDE: 0x1d6b88 | Size: 76 bytes [BDPythonVMPreInit]
// Khung tháo gỡ #0584 | Địa chỉ PC: 0x080ba4 | Địa chỉ FDE: 0x1d6b88 | Kích thước: 76 bytes
//   0x080ba4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x080ba8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x080bac: 910043FD  add      x29, sp, #0x10
//   0x080bb0: 3942A408  ldrb     w8, [x0, #0xa9]
static inline uint64_t fde_func_0584_0x080ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080ba4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6b88ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0585 | PC: 0x080bf0 | FDE: 0x1d6ba8 | Size: 24 bytes [PyException_GetTraceback]
// Khung tháo gỡ #0585 | Địa chỉ PC: 0x080bf0 | Địa chỉ FDE: 0x1d6ba8 | Kích thước: 24 bytes
//   0x080bf0: F9401000  ldr      x0, [x0, #0x20]
//   0x080bf4: B4000080  cbz      x0, #0x80c04
//   0x080bf8: F9400008  ldr      x8, [x0]
//   0x080bfc: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_0585_0x080bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080bf0ULL ^ (static_cast<uint64_t>(0xf9401000ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1d6ba8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0586 | PC: 0x080c08 | FDE: 0x1d6bc0 | Size: 256 bytes [PyException_SetTraceback]
// Khung tháo gỡ #0586 | Địa chỉ PC: 0x080c08 | Địa chỉ FDE: 0x1d6bc0 | Kích thước: 256 bytes
//   0x080c08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x080c0c: 910003FD  mov      x29, sp
//   0x080c10: B40003C1  cbz      x1, #0x80c88
//   0x080c14: F0000BE8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0586_0x080c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080c08ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0587 | PC: 0x080d50 | FDE: 0x1d6c00 | Size: 24 bytes [PyException_GetCause]
// Khung tháo gỡ #0587 | Địa chỉ PC: 0x080d50 | Địa chỉ FDE: 0x1d6c00 | Kích thước: 24 bytes
//   0x080d50: F9401800  ldr      x0, [x0, #0x30]
//   0x080d54: B4000080  cbz      x0, #0x80d64
//   0x080d58: F9400008  ldr      x8, [x0]
//   0x080d5c: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_0587_0x080d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080d50ULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1d6c00ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0588 | PC: 0x080d68 | FDE: 0x1d6c18 | Size: 48 bytes [PyException_SetCause]
// Khung tháo gỡ #0588 | Địa chỉ PC: 0x080d68 | Địa chỉ FDE: 0x1d6c18 | Kích thước: 48 bytes
//   0x080d68: AA0003E8  mov      x8, x0
//   0x080d6c: F9401800  ldr      x0, [x0, #0x30]
//   0x080d70: 52800029  mov      w9, #1
//   0x080d74: 3900E109  strb     w9, [x8, #0x38]
static inline uint64_t fde_func_0588_0x080d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080d68ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9401800ULL) ^ 0x1d6c18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0589 | PC: 0x080d98 | FDE: 0x1d6c30 | Size: 24 bytes [PyException_GetContext]
// Khung tháo gỡ #0589 | Địa chỉ PC: 0x080d98 | Địa chỉ FDE: 0x1d6c30 | Kích thước: 24 bytes
//   0x080d98: F9401400  ldr      x0, [x0, #0x28]
//   0x080d9c: B4000080  cbz      x0, #0x80dac
//   0x080da0: F9400008  ldr      x8, [x0]
//   0x080da4: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_0589_0x080d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080d98ULL ^ (static_cast<uint64_t>(0xf9401400ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1d6c30ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0590 | PC: 0x080db0 | FDE: 0x1d6c48 | Size: 40 bytes [PyException_SetContext]
// Khung tháo gỡ #0590 | Địa chỉ PC: 0x080db0 | Địa chỉ FDE: 0x1d6c48 | Kích thước: 40 bytes
//   0x080db0: AA0003E8  mov      x8, x0
//   0x080db4: F9401400  ldr      x0, [x0, #0x28]
//   0x080db8: F9001501  str      x1, [x8, #0x28]
//   0x080dbc: B40000A0  cbz      x0, #0x80dd0
static inline uint64_t fde_func_0590_0x080db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080db0ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9401400ULL) ^ 0x1d6c48ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0591 | PC: 0x080dd8 | FDE: 0x1d6c60 | Size: 8 bytes [PyExceptionClass_Name]
// Khung tháo gỡ #0591 | Địa chỉ PC: 0x080dd8 | Địa chỉ FDE: 0x1d6c60 | Kích thước: 8 bytes
//   0x080dd8: F9400C00  ldr      x0, [x0, #0x18]
//   0x080ddc: D65F03C0  ret      
static inline uint64_t fde_func_0591_0x080dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080dd8ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1d6c60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0592 | PC: 0x080de0 | FDE: 0x1d6c78 | Size: 112 bytes [PyUnicodeEncodeError_GetEncoding]
// Khung tháo gỡ #0592 | Địa chỉ PC: 0x080de0 | Địa chỉ FDE: 0x1d6c78 | Kích thước: 112 bytes
//   0x080de0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x080de4: 910003FD  mov      x29, sp
//   0x080de8: F9402000  ldr      x0, [x0, #0x40]
//   0x080dec: B4000120  cbz      x0, #0x80e10
static inline uint64_t fde_func_0592_0x080de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080de0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6c78ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0593 | PC: 0x080e50 | FDE: 0x1d6c98 | Size: 112 bytes [PyUnicodeDecodeError_GetEncoding]
// Khung tháo gỡ #0593 | Địa chỉ PC: 0x080e50 | Địa chỉ FDE: 0x1d6c98 | Kích thước: 112 bytes
//   0x080e50: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x080e54: 910003FD  mov      x29, sp
//   0x080e58: F9402000  ldr      x0, [x0, #0x40]
//   0x080e5c: B4000120  cbz      x0, #0x80e80
static inline uint64_t fde_func_0593_0x080e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080e50ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6c98ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0594 | PC: 0x080ec0 | FDE: 0x1d6cb8 | Size: 112 bytes [PyUnicodeEncodeError_GetObject]
// Khung tháo gỡ #0594 | Địa chỉ PC: 0x080ec0 | Địa chỉ FDE: 0x1d6cb8 | Kích thước: 112 bytes
//   0x080ec0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x080ec4: 910003FD  mov      x29, sp
//   0x080ec8: F9402400  ldr      x0, [x0, #0x48]
//   0x080ecc: B4000120  cbz      x0, #0x80ef0
static inline uint64_t fde_func_0594_0x080ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080ec0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6cb8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0595 | PC: 0x080f30 | FDE: 0x1d6cd8 | Size: 112 bytes [PyUnicodeDecodeError_GetObject]
// Khung tháo gỡ #0595 | Địa chỉ PC: 0x080f30 | Địa chỉ FDE: 0x1d6cd8 | Kích thước: 112 bytes
//   0x080f30: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x080f34: 910003FD  mov      x29, sp
//   0x080f38: F9402400  ldr      x0, [x0, #0x48]
//   0x080f3c: B4000120  cbz      x0, #0x80f60
static inline uint64_t fde_func_0595_0x080f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080f30ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6cd8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0596 | PC: 0x080fa0 | FDE: 0x1d6cf8 | Size: 112 bytes [PyUnicodeTranslateError_GetObject]
// Khung tháo gỡ #0596 | Địa chỉ PC: 0x080fa0 | Địa chỉ FDE: 0x1d6cf8 | Kích thước: 112 bytes
//   0x080fa0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x080fa4: 910003FD  mov      x29, sp
//   0x080fa8: F9402400  ldr      x0, [x0, #0x48]
//   0x080fac: B4000120  cbz      x0, #0x80fd0
static inline uint64_t fde_func_0596_0x080fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080fa0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6cf8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0597 | PC: 0x081010 | FDE: 0x1d6d18 | Size: 172 bytes [PyUnicodeEncodeError_GetStart]
// Khung tháo gỡ #0597 | Địa chỉ PC: 0x081010 | Địa chỉ FDE: 0x1d6d18 | Kích thước: 172 bytes
//   0x081010: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x081014: 910003FD  mov      x29, sp
//   0x081018: AA0003E8  mov      x8, x0
//   0x08101c: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0597_0x081010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081010ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6d18ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0598 | PC: 0x0810bc | FDE: 0x1d6d38 | Size: 168 bytes [PyUnicodeDecodeError_GetStart]
// Khung tháo gỡ #0598 | Địa chỉ PC: 0x0810bc | Địa chỉ FDE: 0x1d6d38 | Kích thước: 168 bytes
//   0x0810bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0810c0: 910003FD  mov      x29, sp
//   0x0810c4: AA0003E8  mov      x8, x0
//   0x0810c8: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0598_0x0810bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0810bcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6d38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0599 | PC: 0x081164 | FDE: 0x1d6d58 | Size: 172 bytes [PyUnicodeTranslateError_GetStart]
// Khung tháo gỡ #0599 | Địa chỉ PC: 0x081164 | Địa chỉ FDE: 0x1d6d58 | Kích thước: 172 bytes
//   0x081164: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x081168: 910003FD  mov      x29, sp
//   0x08116c: AA0003E8  mov      x8, x0
//   0x081170: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0599_0x081164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081164ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6d58ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0600 | PC: 0x081210 | FDE: 0x1d6d78 | Size: 12 bytes [PyUnicodeEncodeError_SetStart]
// Khung tháo gỡ #0600 | Địa chỉ PC: 0x081210 | Địa chỉ FDE: 0x1d6d78 | Kích thước: 12 bytes
//   0x081210: F9002801  str      x1, [x0, #0x50]
//   0x081214: 2A1F03E0  mov      w0, wzr
//   0x081218: D65F03C0  ret      
static inline uint64_t fde_func_0600_0x081210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081210ULL ^ (static_cast<uint64_t>(0xf9002801ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1d6d78ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0601 | PC: 0x08121c | FDE: 0x1d6d90 | Size: 12 bytes [PyUnicodeDecodeError_SetStart]
// Khung tháo gỡ #0601 | Địa chỉ PC: 0x08121c | Địa chỉ FDE: 0x1d6d90 | Kích thước: 12 bytes
//   0x08121c: F9002801  str      x1, [x0, #0x50]
//   0x081220: 2A1F03E0  mov      w0, wzr
//   0x081224: D65F03C0  ret      
static inline uint64_t fde_func_0601_0x08121c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08121cULL ^ (static_cast<uint64_t>(0xf9002801ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1d6d90ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0602 | PC: 0x081228 | FDE: 0x1d6da8 | Size: 12 bytes [PyUnicodeTranslateError_SetStart]
// Khung tháo gỡ #0602 | Địa chỉ PC: 0x081228 | Địa chỉ FDE: 0x1d6da8 | Kích thước: 12 bytes
//   0x081228: F9002801  str      x1, [x0, #0x50]
//   0x08122c: 2A1F03E0  mov      w0, wzr
//   0x081230: D65F03C0  ret      
static inline uint64_t fde_func_0602_0x081228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081228ULL ^ (static_cast<uint64_t>(0xf9002801ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1d6da8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0603 | PC: 0x081234 | FDE: 0x1d6dc0 | Size: 172 bytes [PyUnicodeEncodeError_GetEnd]
// Khung tháo gỡ #0603 | Địa chỉ PC: 0x081234 | Địa chỉ FDE: 0x1d6dc0 | Kích thước: 172 bytes
//   0x081234: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x081238: 910003FD  mov      x29, sp
//   0x08123c: AA0003E8  mov      x8, x0
//   0x081240: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0603_0x081234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081234ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6dc0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0604 | PC: 0x0812e0 | FDE: 0x1d6de0 | Size: 168 bytes [PyUnicodeDecodeError_GetEnd]
// Khung tháo gỡ #0604 | Địa chỉ PC: 0x0812e0 | Địa chỉ FDE: 0x1d6de0 | Kích thước: 168 bytes
//   0x0812e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0812e4: 910003FD  mov      x29, sp
//   0x0812e8: AA0003E8  mov      x8, x0
//   0x0812ec: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0604_0x0812e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0812e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6de0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0605 | PC: 0x081388 | FDE: 0x1d6e00 | Size: 172 bytes [PyUnicodeTranslateError_GetEnd]
// Khung tháo gỡ #0605 | Địa chỉ PC: 0x081388 | Địa chỉ FDE: 0x1d6e00 | Kích thước: 172 bytes
//   0x081388: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08138c: 910003FD  mov      x29, sp
//   0x081390: AA0003E8  mov      x8, x0
//   0x081394: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0605_0x081388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081388ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6e00ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0606 | PC: 0x081434 | FDE: 0x1d6e20 | Size: 12 bytes [PyUnicodeEncodeError_SetEnd]
// Khung tháo gỡ #0606 | Địa chỉ PC: 0x081434 | Địa chỉ FDE: 0x1d6e20 | Kích thước: 12 bytes
//   0x081434: F9002C01  str      x1, [x0, #0x58]
//   0x081438: 2A1F03E0  mov      w0, wzr
//   0x08143c: D65F03C0  ret      
static inline uint64_t fde_func_0606_0x081434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081434ULL ^ (static_cast<uint64_t>(0xf9002c01ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1d6e20ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0607 | PC: 0x081440 | FDE: 0x1d6e38 | Size: 12 bytes [PyUnicodeDecodeError_SetEnd]
// Khung tháo gỡ #0607 | Địa chỉ PC: 0x081440 | Địa chỉ FDE: 0x1d6e38 | Kích thước: 12 bytes
//   0x081440: F9002C01  str      x1, [x0, #0x58]
//   0x081444: 2A1F03E0  mov      w0, wzr
//   0x081448: D65F03C0  ret      
static inline uint64_t fde_func_0607_0x081440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081440ULL ^ (static_cast<uint64_t>(0xf9002c01ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1d6e38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0608 | PC: 0x08144c | FDE: 0x1d6e50 | Size: 12 bytes [PyUnicodeTranslateError_SetEnd]
// Khung tháo gỡ #0608 | Địa chỉ PC: 0x08144c | Địa chỉ FDE: 0x1d6e50 | Kích thước: 12 bytes
//   0x08144c: F9002C01  str      x1, [x0, #0x58]
//   0x081450: 2A1F03E0  mov      w0, wzr
//   0x081454: D65F03C0  ret      
static inline uint64_t fde_func_0608_0x08144c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08144cULL ^ (static_cast<uint64_t>(0xf9002c01ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1d6e50ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0609 | PC: 0x081458 | FDE: 0x1d6e68 | Size: 112 bytes [PyUnicodeEncodeError_GetReason]
// Khung tháo gỡ #0609 | Địa chỉ PC: 0x081458 | Địa chỉ FDE: 0x1d6e68 | Kích thước: 112 bytes
//   0x081458: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08145c: 910003FD  mov      x29, sp
//   0x081460: F9403000  ldr      x0, [x0, #0x60]
//   0x081464: B4000120  cbz      x0, #0x81488
static inline uint64_t fde_func_0609_0x081458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081458ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6e68ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0610 | PC: 0x0814c8 | FDE: 0x1d6e88 | Size: 112 bytes [PyUnicodeDecodeError_GetReason]
// Khung tháo gỡ #0610 | Địa chỉ PC: 0x0814c8 | Địa chỉ FDE: 0x1d6e88 | Kích thước: 112 bytes
//   0x0814c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0814cc: 910003FD  mov      x29, sp
//   0x0814d0: F9403000  ldr      x0, [x0, #0x60]
//   0x0814d4: B4000120  cbz      x0, #0x814f8
static inline uint64_t fde_func_0610_0x0814c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0814c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6e88ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0611 | PC: 0x081538 | FDE: 0x1d6ea8 | Size: 112 bytes [PyUnicodeTranslateError_GetReason]
// Khung tháo gỡ #0611 | Địa chỉ PC: 0x081538 | Địa chỉ FDE: 0x1d6ea8 | Kích thước: 112 bytes
//   0x081538: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08153c: 910003FD  mov      x29, sp
//   0x081540: F9403000  ldr      x0, [x0, #0x60]
//   0x081544: B4000120  cbz      x0, #0x81568
static inline uint64_t fde_func_0611_0x081538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081538ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d6ea8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0612 | PC: 0x0815a8 | FDE: 0x1d6ec8 | Size: 88 bytes [PyUnicodeEncodeError_SetReason]
// Khung tháo gỡ #0612 | Địa chỉ PC: 0x0815a8 | Địa chỉ FDE: 0x1d6ec8 | Kích thước: 88 bytes
//   0x0815a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0815ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0815b0: 910043FD  add      x29, sp, #0x10
//   0x0815b4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0612_0x0815a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0815a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6ec8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0613 | PC: 0x081600 | FDE: 0x1d6ee8 | Size: 88 bytes [PyUnicodeDecodeError_SetReason]
// Khung tháo gỡ #0613 | Địa chỉ PC: 0x081600 | Địa chỉ FDE: 0x1d6ee8 | Kích thước: 88 bytes
//   0x081600: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x081604: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x081608: 910043FD  add      x29, sp, #0x10
//   0x08160c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0613_0x081600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081600ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6ee8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0614 | PC: 0x081658 | FDE: 0x1d6f08 | Size: 88 bytes [PyUnicodeTranslateError_SetReason]
// Khung tháo gỡ #0614 | Địa chỉ PC: 0x081658 | Địa chỉ FDE: 0x1d6f08 | Kích thước: 88 bytes
//   0x081658: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08165c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x081660: 910043FD  add      x29, sp, #0x10
//   0x081664: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0614_0x081658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081658ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6f08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0615 | PC: 0x0816b0 | FDE: 0x1d6f28 | Size: 52 bytes [PyUnicodeEncodeError_Create]
// Khung tháo gỡ #0615 | Địa chỉ PC: 0x0816b0 | Địa chỉ FDE: 0x1d6f28 | Kích thước: 52 bytes
//   0x0816b0: D0000BE8  adrp     x8, #0x1ff000
//   0x0816b4: F9462D08  ldr      x8, [x8, #0xc58]
//   0x0816b8: AA0503E7  mov      x7, x5
//   0x0816bc: AA0303E5  mov      x5, x3
static inline uint64_t fde_func_0615_0x0816b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0816b0ULL ^ (static_cast<uint64_t>(0xd0000be8ULL) << 13);
    acc = (acc + a1 + 0xf9462d08ULL) ^ 0x1d6f28ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0616 | PC: 0x0816e4 | FDE: 0x1d6f40 | Size: 52 bytes [PyUnicodeDecodeError_Create]
// Khung tháo gỡ #0616 | Địa chỉ PC: 0x0816e4 | Địa chỉ FDE: 0x1d6f40 | Kích thước: 52 bytes
//   0x0816e4: D0000BE8  adrp     x8, #0x1ff000
//   0x0816e8: F945DD08  ldr      x8, [x8, #0xbb8]
//   0x0816ec: AA0503E7  mov      x7, x5
//   0x0816f0: AA0303E5  mov      x5, x3
static inline uint64_t fde_func_0616_0x0816e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0816e4ULL ^ (static_cast<uint64_t>(0xd0000be8ULL) << 13);
    acc = (acc + a1 + 0xf945dd08ULL) ^ 0x1d6f40ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0617 | PC: 0x081718 | FDE: 0x1d6f58 | Size: 48 bytes [PyUnicodeTranslateError_Create]
// Khung tháo gỡ #0617 | Địa chỉ PC: 0x081718 | Địa chỉ FDE: 0x1d6f58 | Kích thước: 48 bytes
//   0x081718: D0000BE8  adrp     x8, #0x1ff000
//   0x08171c: F9432108  ldr      x8, [x8, #0x640]
//   0x081720: AA0303E5  mov      x5, x3
//   0x081724: AA0103E3  mov      x3, x1
static inline uint64_t fde_func_0617_0x081718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081718ULL ^ (static_cast<uint64_t>(0xd0000be8ULL) << 13);
    acc = (acc + a1 + 0xf9432108ULL) ^ 0x1d6f58ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0618 | PC: 0x081748 | FDE: 0x1d6f70 | Size: 44 bytes [_PyUnicodeTranslateError_Create]
// Khung tháo gỡ #0618 | Địa chỉ PC: 0x081748 | Địa chỉ FDE: 0x1d6f70 | Kích thước: 44 bytes
//   0x081748: D0000BE8  adrp     x8, #0x1ff000
//   0x08174c: F9432108  ldr      x8, [x8, #0x640]
//   0x081750: AA0303E5  mov      x5, x3
//   0x081754: AA0103E3  mov      x3, x1
static inline uint64_t fde_func_0618_0x081748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081748ULL ^ (static_cast<uint64_t>(0xd0000be8ULL) << 13);
    acc = (acc + a1 + 0xf9432108ULL) ^ 0x1d6f70ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0619 | PC: 0x081774 | FDE: 0x1d6f88 | Size: 256 bytes [_PyExc_Init]
// Khung tháo gỡ #0619 | Địa chỉ PC: 0x081774 | Địa chỉ FDE: 0x1d6f88 | Kích thước: 256 bytes
//   0x081774: D103C3FF  sub      sp, sp, #0xf0
//   0x081778: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x08177c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x081780: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0619_0x081774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081774ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1d6f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0620 | PC: 0x085404 | FDE: 0x1d6fb8 | Size: 256 bytes [_PyBuiltins_AddExceptions]
// Khung tháo gỡ #0620 | Địa chỉ PC: 0x085404 | Địa chỉ FDE: 0x1d6fb8 | Kích thước: 256 bytes
//   0x085404: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x085408: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08540c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x085410: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0620_0x085404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085404ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d6fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0621 | PC: 0x085d3c | FDE: 0x1d6fe0 | Size: 104 bytes [_PyExc_Fini]
// Khung tháo gỡ #0621 | Địa chỉ PC: 0x085d3c | Địa chỉ FDE: 0x1d6fe0 | Kích thước: 104 bytes
//   0x085d3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x085d40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x085d44: 910043FD  add      x29, sp, #0x10
//   0x085d48: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0621_0x085d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085d3cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d6fe0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0622 | PC: 0x085da4 | FDE: 0x1d7000 | Size: 256 bytes [_PyErr_TrySetFromCause]
// Khung tháo gỡ #0622 | Địa chỉ PC: 0x085da4 | Địa chỉ FDE: 0x1d7000 | Kích thước: 256 bytes
//   0x085da4: D105C3FF  sub      sp, sp, #0x170
//   0x085da8: A91457FC  stp      x28, x21, [sp, #0x140]
//   0x085dac: A9154FF4  stp      x20, x19, [sp, #0x150]
//   0x085db0: A9167BFD  stp      x29, x30, [sp, #0x160]
static inline uint64_t fde_func_0622_0x085da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085da4ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa91457fcULL) ^ 0x1d7000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0623 | PC: 0x088b98 | FDE: 0x1d7760 | Size: 256 bytes [_Py_make_parameters]
// Khung tháo gỡ #0623 | Địa chỉ PC: 0x088b98 | Địa chỉ FDE: 0x1d7760 | Kích thước: 256 bytes
//   0x088b98: D10203FF  sub      sp, sp, #0x80
//   0x088b9c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x088ba0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x088ba4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0623_0x088b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088b98ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1d7760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0624 | PC: 0x088ebc | FDE: 0x1d7790 | Size: 256 bytes [_Py_subs_parameters]
// Khung tháo gỡ #0624 | Địa chỉ PC: 0x088ebc | Địa chỉ FDE: 0x1d7790 | Kích thước: 256 bytes
//   0x088ebc: D10283FF  sub      sp, sp, #0xa0
//   0x088ec0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x088ec4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x088ec8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0624_0x088ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088ebcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1d7790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0625 | PC: 0x089848 | FDE: 0x1d78d0 | Size: 256 bytes [Py_GenericAlias]
// Khung tháo gỡ #0625 | Địa chỉ PC: 0x089848 | Địa chỉ FDE: 0x1d78d0 | Kích thước: 256 bytes
//   0x089848: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x08984c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x089850: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x089854: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0625_0x089848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089848ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d78d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0626 | PC: 0x089d88 | FDE: 0x1d79e0 | Size: 256 bytes [_PyGen_Finalize]
// Khung tháo gỡ #0626 | Địa chỉ PC: 0x089d88 | Địa chỉ FDE: 0x1d79e0 | Kích thước: 256 bytes
//   0x089d88: D101C3FF  sub      sp, sp, #0x70
//   0x089d8c: F9001BF7  str      x23, [sp, #0x30]
//   0x089d90: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x089d94: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0626_0x089d88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089d88ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1d79e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0627 | PC: 0x08a0a4 | FDE: 0x1d7a30 | Size: 84 bytes [_PyGen_yf]
// Khung tháo gỡ #0627 | Địa chỉ PC: 0x08a0a4 | Địa chỉ FDE: 0x1d7a30 | Kích thước: 84 bytes
//   0x08a0a4: F9400808  ldr      x8, [x0, #0x10]
//   0x08a0a8: B4000248  cbz      x8, #0x8a0f0
//   0x08a0ac: B9406109  ldr      w9, [x8, #0x60]
//   0x08a0b0: 37F80209  tbnz     w9, #0x1f, #0x8a0f0
static inline uint64_t fde_func_0627_0x08a0a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a0a4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb4000248ULL) ^ 0x1d7a30ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0628 | PC: 0x08a0f8 | FDE: 0x1d7a48 | Size: 256 bytes [_PyGen_SetStopIterationValue]
// Khung tháo gỡ #0628 | Địa chỉ PC: 0x08a0f8 | Địa chỉ FDE: 0x1d7a48 | Kích thước: 256 bytes
//   0x08a0f8: D10183FF  sub      sp, sp, #0x60
//   0x08a0fc: F90013F7  str      x23, [sp, #0x20]
//   0x08a100: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x08a104: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0628_0x08a0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a0f8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1d7a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0629 | PC: 0x08a22c | FDE: 0x1d7a70 | Size: 256 bytes [_PyGen_FetchStopIterationValue]
// Khung tháo gỡ #0629 | Địa chỉ PC: 0x08a22c | Địa chỉ FDE: 0x1d7a70 | Kích thước: 256 bytes
//   0x08a22c: D10143FF  sub      sp, sp, #0x50
//   0x08a230: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08a234: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08a238: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0629_0x08a22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a22cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1d7a70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0630 | PC: 0x08a6c0 | FDE: 0x1d7b10 | Size: 188 bytes [PyGen_NewWithQualName]
// Khung tháo gỡ #0630 | Địa chỉ PC: 0x08a6c0 | Địa chỉ FDE: 0x1d7b10 | Kích thước: 188 bytes
//   0x08a6c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a6c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a6c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a6cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0630_0x08a6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a6c0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d7b10ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0631 | PC: 0x08a77c | FDE: 0x1d7b38 | Size: 140 bytes [PyGen_New]
// Khung tháo gỡ #0631 | Địa chỉ PC: 0x08a77c | Địa chỉ FDE: 0x1d7b38 | Kích thước: 140 bytes
//   0x08a77c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08a780: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08a784: 910043FD  add      x29, sp, #0x10
//   0x08a788: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0631_0x08a77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a77cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d7b38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0632 | PC: 0x08a808 | FDE: 0x1d7b58 | Size: 256 bytes [_PyCoro_GetAwaitableIter]
// Khung tháo gỡ #0632 | Địa chỉ PC: 0x08a808 | Địa chỉ FDE: 0x1d7b58 | Kích thước: 256 bytes
//   0x08a808: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x08a80c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a810: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a814: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0632_0x08a808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a808ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d7b58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0633 | PC: 0x08aa3c | FDE: 0x1d7bf0 | Size: 256 bytes [PyCoro_New]
// Khung tháo gỡ #0633 | Địa chỉ PC: 0x08aa3c | Địa chỉ FDE: 0x1d7bf0 | Kích thước: 256 bytes
//   0x08aa3c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x08aa40: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08aa44: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08aa48: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0633_0x08aa3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08aa3cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d7bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0634 | PC: 0x08ac68 | FDE: 0x1d7c58 | Size: 196 bytes [PyAsyncGen_New]
// Khung tháo gỡ #0634 | Địa chỉ PC: 0x08ac68 | Địa chỉ FDE: 0x1d7c58 | Kích thước: 196 bytes
//   0x08ac68: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08ac6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08ac70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08ac74: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0634_0x08ac68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ac68ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d7c58ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0635 | PC: 0x08ad2c | FDE: 0x1d7c80 | Size: 96 bytes [_PyAsyncGen_ClearFreeLists]
// Khung tháo gỡ #0635 | Địa chỉ PC: 0x08ad2c | Địa chỉ FDE: 0x1d7c80 | Kích thước: 96 bytes
//   0x08ad2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ad30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ad34: 910043FD  add      x29, sp, #0x10
//   0x08ad38: B9723008  ldr      w8, [x0, #0x3230]
static inline uint64_t fde_func_0635_0x08ad2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ad2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d7c80ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0636 | PC: 0x08ad8c | FDE: 0x1d7ca0 | Size: 256 bytes [_PyAsyncGen_Fini]
// Khung tháo gỡ #0636 | Địa chỉ PC: 0x08ad8c | Địa chỉ FDE: 0x1d7ca0 | Kích thước: 256 bytes
//   0x08ad8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ad90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ad94: 910043FD  add      x29, sp, #0x10
//   0x08ad98: B9723008  ldr      w8, [x0, #0x3230]
static inline uint64_t fde_func_0636_0x08ad8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ad8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d7ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0637 | PC: 0x08afa4 | FDE: 0x1d7d58 | Size: 256 bytes [_PyAsyncGenValueWrapperNew]
// Khung tháo gỡ #0637 | Địa chỉ PC: 0x08afa4 | Địa chỉ FDE: 0x1d7d58 | Kích thước: 256 bytes
//   0x08afa4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08afa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08afac: 910043FD  add      x29, sp, #0x10
//   0x08afb0: B0000BA8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0637_0x08afa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08afa4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d7d58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0638 | PC: 0x08c8f8 | FDE: 0x1d8180 | Size: 212 bytes [PyFile_FromFd]
// Khung tháo gỡ #0638 | Địa chỉ PC: 0x08c8f8 | Địa chỉ FDE: 0x1d8180 | Kích thước: 212 bytes
//   0x08c8f8: D10183FF  sub      sp, sp, #0x60
//   0x08c8fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x08c900: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08c904: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0638_0x08c8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c8f8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1d8180ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0639 | PC: 0x08c9cc | FDE: 0x1d81b0 | Size: 256 bytes [PyFile_GetLine]
// Khung tháo gỡ #0639 | Địa chỉ PC: 0x08c9cc | Địa chỉ FDE: 0x1d81b0 | Kích thước: 256 bytes
//   0x08c9cc: D10103FF  sub      sp, sp, #0x40
//   0x08c9d0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08c9d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08c9d8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0639_0x08c9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c9ccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d81b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0640 | PC: 0x08ccac | FDE: 0x1d81d8 | Size: 256 bytes [PyFile_WriteObject]
// Khung tháo gỡ #0640 | Địa chỉ PC: 0x08ccac | Địa chỉ FDE: 0x1d81d8 | Kích thước: 256 bytes
//   0x08ccac: D10183FF  sub      sp, sp, #0x60
//   0x08ccb0: F90013F7  str      x23, [sp, #0x20]
//   0x08ccb4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x08ccb8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0640_0x08ccac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ccacULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1d81d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0641 | PC: 0x08ce4c | FDE: 0x1d8200 | Size: 140 bytes [PyFile_WriteString]
// Khung tháo gỡ #0641 | Địa chỉ PC: 0x08ce4c | Địa chỉ FDE: 0x1d8200 | Kích thước: 140 bytes
//   0x08ce4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08ce50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ce54: 910043FD  add      x29, sp, #0x10
//   0x08ce58: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0641_0x08ce4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8200ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0642 | PC: 0x08ced8 | FDE: 0x1d8220 | Size: 256 bytes [PyObject_AsFileDescriptor]
// Khung tháo gỡ #0642 | Địa chỉ PC: 0x08ced8 | Địa chỉ FDE: 0x1d8220 | Kích thước: 256 bytes
//   0x08ced8: D10103FF  sub      sp, sp, #0x40
//   0x08cedc: F9000BF5  str      x21, [sp, #0x10]
//   0x08cee0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08cee4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0642_0x08ced8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ced8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1d8220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0643 | PC: 0x08d0a0 | FDE: 0x1d8240 | Size: 56 bytes [_PyLong_FileDescriptor_Converter]
// Khung tháo gỡ #0643 | Địa chỉ PC: 0x08d0a0 | Địa chỉ FDE: 0x1d8240 | Kích thước: 56 bytes
//   0x08d0a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08d0a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d0a8: 910043FD  add      x29, sp, #0x10
//   0x08d0ac: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0643_0x08d0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d0a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8240ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0644 | PC: 0x08d0d8 | FDE: 0x1d8260 | Size: 232 bytes [Py_UniversalNewlineFgets]
// Khung tháo gỡ #0644 | Địa chỉ PC: 0x08d0d8 | Địa chỉ FDE: 0x1d8260 | Kích thước: 232 bytes
//   0x08d0d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08d0dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08d0e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08d0e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0644_0x08d0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d0d8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d8260ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0645 | PC: 0x08d1c0 | FDE: 0x1d8288 | Size: 100 bytes [PyFile_NewStdPrinter]
// Khung tháo gỡ #0645 | Địa chỉ PC: 0x08d1c0 | Địa chỉ FDE: 0x1d8288 | Kích thước: 100 bytes
//   0x08d1c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08d1c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d1c8: 910043FD  add      x29, sp, #0x10
//   0x08d1cc: D0000B94  adrp     x20, #0x1ff000
static inline uint64_t fde_func_0645_0x08d1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d1c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8288ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0646 | PC: 0x08d224 | FDE: 0x1d82c0 | Size: 124 bytes [PyFile_SetOpenCodeHook]
// Khung tháo gỡ #0646 | Địa chỉ PC: 0x08d224 | Địa chỉ FDE: 0x1d82c0 | Kích thước: 124 bytes
//   0x08d224: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08d228: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d22c: 910043FD  add      x29, sp, #0x10
//   0x08d230: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0646_0x08d224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d224ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d82c0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0647 | PC: 0x08d2a0 | FDE: 0x1d82e0 | Size: 196 bytes [PyFile_OpenCodeObject]
// Khung tháo gỡ #0647 | Địa chỉ PC: 0x08d2a0 | Địa chỉ FDE: 0x1d82e0 | Kích thước: 196 bytes
//   0x08d2a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08d2a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d2a8: 910043FD  add      x29, sp, #0x10
//   0x08d2ac: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0647_0x08d2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d2a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d82e0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0648 | PC: 0x08d364 | FDE: 0x1d8300 | Size: 256 bytes [PyFile_OpenCode]
// Khung tháo gỡ #0648 | Địa chỉ PC: 0x08d364 | Địa chỉ FDE: 0x1d8300 | Kích thước: 256 bytes
//   0x08d364: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08d368: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d36c: 910043FD  add      x29, sp, #0x10
//   0x08d370: 97FF3C54  bl       #0x5c4c0
static inline uint64_t fde_func_0648_0x08d364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d364ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0649 | PC: 0x08d5a4 | FDE: 0x1d83e0 | Size: 12 bytes [PyFloat_GetMax]
// Khung tháo gỡ #0649 | Địa chỉ PC: 0x08d5a4 | Địa chỉ FDE: 0x1d83e0 | Kích thước: 12 bytes
//   0x08d5a4: 92F00208  mov      x8, #0x7fefffffffffffff
//   0x08d5a8: 9E670100  fmov     d0, x8
//   0x08d5ac: D65F03C0  ret      
static inline uint64_t fde_func_0649_0x08d5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d5a4ULL ^ (static_cast<uint64_t>(0x92f00208ULL) << 13);
    acc = (acc + a1 + 0x9e670100ULL) ^ 0x1d83e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0650 | PC: 0x08d5b0 | FDE: 0x1d83f8 | Size: 12 bytes [PyFloat_GetMin]
// Khung tháo gỡ #0650 | Địa chỉ PC: 0x08d5b0 | Địa chỉ FDE: 0x1d83f8 | Kích thước: 12 bytes
//   0x08d5b0: D2E00208  mov      x8, #0x10000000000000
//   0x08d5b4: 9E670100  fmov     d0, x8
//   0x08d5b8: D65F03C0  ret      
static inline uint64_t fde_func_0650_0x08d5b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d5b0ULL ^ (static_cast<uint64_t>(0xd2e00208ULL) << 13);
    acc = (acc + a1 + 0x9e670100ULL) ^ 0x1d83f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0651 | PC: 0x08d5bc | FDE: 0x1d8410 | Size: 256 bytes [PyFloat_GetInfo]
// Khung tháo gỡ #0651 | Địa chỉ PC: 0x08d5bc | Địa chỉ FDE: 0x1d8410 | Kích thước: 256 bytes
//   0x08d5bc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08d5c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08d5c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08d5c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0651_0x08d5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d5bcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d8410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0652 | PC: 0x08d7ec | FDE: 0x1d8438 | Size: 168 bytes [PyFloat_FromDouble]
// Khung tháo gỡ #0652 | Địa chỉ PC: 0x08d7ec | Địa chỉ FDE: 0x1d8438 | Kích thước: 168 bytes
//   0x08d7ec: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x08d7f0: F90007F3  str      x19, [sp, #8]
//   0x08d7f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d7f8: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0652_0x08d7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d7ecULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f3ULL) ^ 0x1d8438ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0653 | PC: 0x08d894 | FDE: 0x1d8458 | Size: 256 bytes [PyFloat_FromString]
// Khung tháo gỡ #0653 | Địa chỉ PC: 0x08d894 | Địa chỉ FDE: 0x1d8458 | Kích thước: 256 bytes
//   0x08d894: D10243FF  sub      sp, sp, #0x90
//   0x08d898: F90033F5  str      x21, [sp, #0x60]
//   0x08d89c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x08d8a0: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0653_0x08d894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d894ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1d8458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0654 | PC: 0x08dba8 | FDE: 0x1d84a0 | Size: 256 bytes [PyFloat_AsDouble]
// Khung tháo gỡ #0654 | Địa chỉ PC: 0x08dba8 | Địa chỉ FDE: 0x1d84a0 | Kích thước: 256 bytes
//   0x08dba8: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x08dbac: F90007F5  str      x21, [sp, #8]
//   0x08dbb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08dbb4: A9027BFD  stp      x29, x30, [sp, #0x20]
static inline uint64_t fde_func_0654_0x08dba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08dba8ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f5ULL) ^ 0x1d84a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0655 | PC: 0x08e2cc | FDE: 0x1d8588 | Size: 40 bytes [_PyFloat_Init]
// Khung tháo gỡ #0655 | Địa chỉ PC: 0x08e2cc | Địa chỉ FDE: 0x1d8588 | Kích thước: 40 bytes
//   0x08e2cc: B0000CA8  adrp     x8, #0x223000
//   0x08e2d0: 52800049  mov      w9, #2
//   0x08e2d4: B0000CAA  adrp     x10, #0x223000
//   0x08e2d8: B0000CAB  adrp     x11, #0x223000
static inline uint64_t fde_func_0655_0x08e2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e2ccULL ^ (static_cast<uint64_t>(0xb0000ca8ULL) << 13);
    acc = (acc + a1 + 0x52800049ULL) ^ 0x1d8588ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0656 | PC: 0x08e2f4 | FDE: 0x1d85a0 | Size: 68 bytes [_PyFloat_InitTypes]
// Khung tháo gỡ #0656 | Địa chỉ PC: 0x08e2f4 | Địa chỉ FDE: 0x1d85a0 | Kích thước: 68 bytes
//   0x08e2f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08e2f8: 910003FD  mov      x29, sp
//   0x08e2fc: B0000CA8  adrp     x8, #0x223000
//   0x08e300: F9466D08  ldr      x8, [x8, #0xcd8]
static inline uint64_t fde_func_0656_0x08e2f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e2f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d85a0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0657 | PC: 0x08e338 | FDE: 0x1d85c0 | Size: 60 bytes [_PyFloat_ClearFreeList]
// Khung tháo gỡ #0657 | Địa chỉ PC: 0x08e338 | Địa chỉ FDE: 0x1d85c0 | Kích thước: 60 bytes
//   0x08e338: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08e33c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08e340: 910043FD  add      x29, sp, #0x10
//   0x08e344: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0657_0x08e338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e338ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d85c0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0658 | PC: 0x08e374 | FDE: 0x1d85e0 | Size: 60 bytes [_PyFloat_Fini]
// Khung tháo gỡ #0658 | Địa chỉ PC: 0x08e374 | Địa chỉ FDE: 0x1d85e0 | Kích thước: 60 bytes
//   0x08e374: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08e378: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08e37c: 910043FD  add      x29, sp, #0x10
//   0x08e380: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0658_0x08e374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e374ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d85e0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0659 | PC: 0x08e3b0 | FDE: 0x1d8600 | Size: 72 bytes [_PyFloat_DebugMallocStats]
// Khung tháo gỡ #0659 | Địa chỉ PC: 0x08e3b0 | Địa chỉ FDE: 0x1d8600 | Kích thước: 72 bytes
//   0x08e3b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08e3b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08e3b8: 910043FD  add      x29, sp, #0x10
//   0x08e3bc: B0000B88  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0659_0x08e3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e3b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8600ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0660 | PC: 0x08e3f8 | FDE: 0x1d8620 | Size: 256 bytes [_PyFloat_Pack2]
// Khung tháo gỡ #0660 | Địa chỉ PC: 0x08e3f8 | Địa chỉ FDE: 0x1d8620 | Kích thước: 256 bytes
//   0x08e3f8: D10103FF  sub      sp, sp, #0x40
//   0x08e3fc: FD000BE8  str      d8, [sp, #0x10]
//   0x08e400: F9000FF5  str      x21, [sp, #0x18]
//   0x08e404: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_0660_0x08e3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e3f8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1d8620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0661 | PC: 0x08e5fc | FDE: 0x1d8648 | Size: 256 bytes [_PyFloat_Pack4]
// Khung tháo gỡ #0661 | Địa chỉ PC: 0x08e5fc | Địa chỉ FDE: 0x1d8648 | Kích thước: 256 bytes
//   0x08e5fc: D10103FF  sub      sp, sp, #0x40
//   0x08e600: FD000BE8  str      d8, [sp, #0x10]
//   0x08e604: F9000FF5  str      x21, [sp, #0x18]
//   0x08e608: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_0661_0x08e5fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e5fcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1d8648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0662 | PC: 0x08e818 | FDE: 0x1d8670 | Size: 256 bytes [_PyFloat_Pack8]
// Khung tháo gỡ #0662 | Địa chỉ PC: 0x08e818 | Địa chỉ FDE: 0x1d8670 | Kích thước: 256 bytes
//   0x08e818: D10103FF  sub      sp, sp, #0x40
//   0x08e81c: FD000BE8  str      d8, [sp, #0x10]
//   0x08e820: F9000FF5  str      x21, [sp, #0x18]
//   0x08e824: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_0662_0x08e818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e818ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1d8670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0663 | PC: 0x08ea8c | FDE: 0x1d8698 | Size: 172 bytes [_PyFloat_Unpack2]
// Khung tháo gỡ #0663 | Địa chỉ PC: 0x08ea8c | Địa chỉ FDE: 0x1d8698 | Kích thước: 172 bytes
//   0x08ea8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ea90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ea94: 910043FD  add      x29, sp, #0x10
//   0x08ea98: 7100003F  cmp      w1, #0
static inline uint64_t fde_func_0663_0x08ea8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ea8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8698ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0664 | PC: 0x08eb38 | FDE: 0x1d86b8 | Size: 256 bytes [_PyFloat_Unpack4]
// Khung tháo gỡ #0664 | Địa chỉ PC: 0x08eb38 | Địa chỉ FDE: 0x1d86b8 | Kích thước: 256 bytes
//   0x08eb38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08eb3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08eb40: 910043FD  add      x29, sp, #0x10
//   0x08eb44: B0000CA8  adrp     x8, #0x223000
static inline uint64_t fde_func_0664_0x08eb38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08eb38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d86b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0665 | PC: 0x08ec5c | FDE: 0x1d86d8 | Size: 256 bytes [_PyFloat_Unpack8]
// Khung tháo gỡ #0665 | Địa chỉ PC: 0x08ec5c | Địa chỉ FDE: 0x1d86d8 | Kích thước: 256 bytes
//   0x08ec5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ec60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ec64: 910043FD  add      x29, sp, #0x10
//   0x08ec68: B0000CA8  adrp     x8, #0x223000
static inline uint64_t fde_func_0665_0x08ec5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ec5cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d86d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0666 | PC: 0x091a0c | FDE: 0x1d8af0 | Size: 256 bytes [PyFrame_GetLineNumber]
// Khung tháo gỡ #0666 | Địa chỉ PC: 0x091a0c | Địa chỉ FDE: 0x1d8af0 | Kích thước: 256 bytes
//   0x091a0c: B9406408  ldr      w8, [x0, #0x64]
//   0x091a10: 34000068  cbz      w8, #0x91a1c
//   0x091a14: 2A0803E0  mov      w0, w8
//   0x091a18: D65F03C0  ret      
static inline uint64_t fde_func_0666_0x091a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091a0cULL ^ (static_cast<uint64_t>(0xb9406408ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x1d8af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0667 | PC: 0x091e7c | FDE: 0x1d8b98 | Size: 256 bytes [_PyFrame_New_NoTrack]
// Khung tháo gỡ #0667 | Địa chỉ PC: 0x091e7c | Địa chỉ FDE: 0x1d8b98 | Kích thước: 256 bytes
//   0x091e7c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x091e80: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x091e84: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x091e88: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0667_0x091e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091e7cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d8b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0668 | PC: 0x092038 | FDE: 0x1d8bc0 | Size: 104 bytes [PyFrame_New]
// Khung tháo gỡ #0668 | Địa chỉ PC: 0x092038 | Địa chỉ FDE: 0x1d8bc0 | Kích thước: 104 bytes
//   0x092038: D101C3FF  sub      sp, sp, #0x70
//   0x09203c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x092040: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x092044: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0668_0x092038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092038ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x1d8bc0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0669 | PC: 0x0920a0 | FDE: 0x1d8be8 | Size: 132 bytes [_PyEval_BuiltinsFromGlobals]
// Khung tháo gỡ #0669 | Địa chỉ PC: 0x0920a0 | Địa chỉ FDE: 0x1d8be8 | Kích thước: 132 bytes
//   0x0920a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0920a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0920a8: 910043FD  add      x29, sp, #0x10
//   0x0920ac: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0669_0x0920a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0920a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8be8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0670 | PC: 0x092124 | FDE: 0x1d8c08 | Size: 72 bytes [PyFrame_BlockSetup]
// Khung tháo gỡ #0670 | Địa chỉ PC: 0x092124 | Địa chỉ FDE: 0x1d8c08 | Kích thước: 72 bytes
//   0x092124: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x092128: 910003FD  mov      x29, sp
//   0x09212c: B9806808  ldrsw    x8, [x0, #0x68]
//   0x092130: 7100511F  cmp      w8, #0x14
static inline uint64_t fde_func_0670_0x092124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092124ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8c08ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0671 | PC: 0x09216c | FDE: 0x1d8c28 | Size: 72 bytes [PyFrame_BlockPop]
// Khung tháo gỡ #0671 | Địa chỉ PC: 0x09216c | Địa chỉ FDE: 0x1d8c28 | Kích thước: 72 bytes
//   0x09216c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x092170: 910003FD  mov      x29, sp
//   0x092174: B9406808  ldr      w8, [x0, #0x68]
//   0x092178: 7100011F  cmp      w8, #0
static inline uint64_t fde_func_0671_0x09216c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09216cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8c28ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0672 | PC: 0x0921b4 | FDE: 0x1d8c48 | Size: 256 bytes [PyFrame_FastToLocalsWithError]
// Khung tháo gỡ #0672 | Địa chỉ PC: 0x0921b4 | Địa chỉ FDE: 0x1d8c48 | Kích thước: 256 bytes
//   0x0921b4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0921b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0921bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0921c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0672_0x0921b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0921b4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d8c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0673 | PC: 0x092380 | FDE: 0x1d8c98 | Size: 32 bytes [PyFrame_FastToLocals]
// Khung tháo gỡ #0673 | Địa chỉ PC: 0x092380 | Địa chỉ FDE: 0x1d8c98 | Kích thước: 32 bytes
//   0x092380: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x092384: 910003FD  mov      x29, sp
//   0x092388: 97FF2C12  bl       #0x5d3d0
//   0x09238c: 37F80060  tbnz     w0, #0x1f, #0x92398
static inline uint64_t fde_func_0673_0x092380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092380ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8c98ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0674 | PC: 0x0923a0 | FDE: 0x1d8cb8 | Size: 256 bytes [PyFrame_LocalsToFast]
// Khung tháo gỡ #0674 | Địa chỉ PC: 0x0923a0 | Địa chỉ FDE: 0x1d8cb8 | Kích thước: 256 bytes
//   0x0923a0: D101C3FF  sub      sp, sp, #0x70
//   0x0923a4: F90013F9  str      x25, [sp, #0x20]
//   0x0923a8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0923ac: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0674_0x0923a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0923a0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1d8cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x0925d0 | FDE: 0x1d8d08 | Size: 68 bytes [_PyFrame_ClearFreeList]
// Khung tháo gỡ #0675 | Địa chỉ PC: 0x0925d0 | Địa chỉ FDE: 0x1d8d08 | Kích thước: 68 bytes
//   0x0925d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0925d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0925d8: 910043FD  add      x29, sp, #0x10
//   0x0925dc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0675_0x0925d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0925d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8d08ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0676 | PC: 0x092614 | FDE: 0x1d8d28 | Size: 4 bytes [_PyFrame_Fini]
// Khung tháo gỡ #0676 | Địa chỉ PC: 0x092614 | Địa chỉ FDE: 0x1d8d28 | Kích thước: 4 bytes
//   0x092614: 17FF234F  b        #0x5b350
static inline uint64_t fde_func_0676_0x092614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092614ULL ^ (static_cast<uint64_t>(0x17ff234fULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1d8d28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0677 | PC: 0x092618 | FDE: 0x1d8d40 | Size: 72 bytes [_PyFrame_DebugMallocStats]
// Khung tháo gỡ #0677 | Địa chỉ PC: 0x092618 | Địa chỉ FDE: 0x1d8d40 | Kích thước: 72 bytes
//   0x092618: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09261c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092620: 910043FD  add      x29, sp, #0x10
//   0x092624: B0000B68  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0677_0x092618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092618ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8d40ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0678 | PC: 0x092660 | FDE: 0x1d8d60 | Size: 20 bytes [PyFrame_GetCode]
// Khung tháo gỡ #0678 | Địa chỉ PC: 0x092660 | Địa chỉ FDE: 0x1d8d60 | Kích thước: 20 bytes
//   0x092660: F9401000  ldr      x0, [x0, #0x20]
//   0x092664: F9400008  ldr      x8, [x0]
//   0x092668: 91000508  add      x8, x8, #1
//   0x09266c: F9000008  str      x8, [x0]
static inline uint64_t fde_func_0678_0x092660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092660ULL ^ (static_cast<uint64_t>(0xf9401000ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1d8d60ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0679 | PC: 0x092674 | FDE: 0x1d8d78 | Size: 24 bytes [PyFrame_GetBack]
// Khung tháo gỡ #0679 | Địa chỉ PC: 0x092674 | Địa chỉ FDE: 0x1d8d78 | Kích thước: 24 bytes
//   0x092674: F9400C00  ldr      x0, [x0, #0x18]
//   0x092678: B4000080  cbz      x0, #0x92688
//   0x09267c: F9400008  ldr      x8, [x0]
//   0x092680: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_0679_0x092674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092674ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1d8d78ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0680 | PC: 0x09268c | FDE: 0x1d8d90 | Size: 256 bytes [PyFrame_DebugDump]
// Khung tháo gỡ #0680 | Địa chỉ PC: 0x09268c | Địa chỉ FDE: 0x1d8d90 | Kích thước: 256 bytes
//   0x09268c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x092690: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092694: 910043FD  add      x29, sp, #0x10
//   0x092698: B9406403  ldr      w3, [x0, #0x64]
static inline uint64_t fde_func_0680_0x09268c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09268cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d8d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0681 | PC: 0x092fac | FDE: 0x1d8ef8 | Size: 256 bytes [PyFunction_NewWithQualName]
// Khung tháo gỡ #0681 | Địa chỉ PC: 0x092fac | Địa chỉ FDE: 0x1d8ef8 | Kích thước: 256 bytes
//   0x092fac: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x092fb0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x092fb4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x092fb8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0681_0x092fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092facULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1d8ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0682 | PC: 0x0931bc | FDE: 0x1d8f20 | Size: 8 bytes [PyFunction_New]
// Khung tháo gỡ #0682 | Địa chỉ PC: 0x0931bc | Địa chỉ FDE: 0x1d8f20 | Kích thước: 8 bytes
//   0x0931bc: AA1F03E2  mov      x2, xzr
//   0x0931c0: 17FF1540  b        #0x586c0
static inline uint64_t fde_func_0682_0x0931bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0931bcULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17ff1540ULL) ^ 0x1d8f20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0683 | PC: 0x0931c4 | FDE: 0x1d8f38 | Size: 68 bytes [PyFunction_GetCode]
// Khung tháo gỡ #0683 | Địa chỉ PC: 0x0931c4 | Địa chỉ FDE: 0x1d8f38 | Kích thước: 68 bytes
//   0x0931c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0931c8: 910003FD  mov      x29, sp
//   0x0931cc: 90000B69  adrp     x9, #0x1ff000
//   0x0931d0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0683_0x0931c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0931c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8f38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0684 | PC: 0x093208 | FDE: 0x1d8f58 | Size: 68 bytes [PyFunction_GetGlobals]
// Khung tháo gỡ #0684 | Địa chỉ PC: 0x093208 | Địa chỉ FDE: 0x1d8f58 | Kích thước: 68 bytes
//   0x093208: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09320c: 910003FD  mov      x29, sp
//   0x093210: 90000B69  adrp     x9, #0x1ff000
//   0x093214: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0684_0x093208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093208ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8f58ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0685 | PC: 0x09324c | FDE: 0x1d8f78 | Size: 68 bytes [PyFunction_GetModule]
// Khung tháo gỡ #0685 | Địa chỉ PC: 0x09324c | Địa chỉ FDE: 0x1d8f78 | Kích thước: 68 bytes
//   0x09324c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x093250: 910003FD  mov      x29, sp
//   0x093254: 90000B69  adrp     x9, #0x1ff000
//   0x093258: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0685_0x09324c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09324cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8f78ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0686 | PC: 0x093290 | FDE: 0x1d8f98 | Size: 68 bytes [PyFunction_GetDefaults]
// Khung tháo gỡ #0686 | Địa chỉ PC: 0x093290 | Địa chỉ FDE: 0x1d8f98 | Kích thước: 68 bytes
//   0x093290: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x093294: 910003FD  mov      x29, sp
//   0x093298: 90000B69  adrp     x9, #0x1ff000
//   0x09329c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0686_0x093290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093290ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8f98ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0687 | PC: 0x0932d4 | FDE: 0x1d8fb8 | Size: 184 bytes [PyFunction_SetDefaults]
// Khung tháo gỡ #0687 | Địa chỉ PC: 0x0932d4 | Địa chỉ FDE: 0x1d8fb8 | Kích thước: 184 bytes
//   0x0932d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0932d8: 910003FD  mov      x29, sp
//   0x0932dc: 90000B69  adrp     x9, #0x1ff000
//   0x0932e0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0687_0x0932d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0932d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8fb8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0688 | PC: 0x09338c | FDE: 0x1d8fd8 | Size: 68 bytes [PyFunction_GetKwDefaults]
// Khung tháo gỡ #0688 | Địa chỉ PC: 0x09338c | Địa chỉ FDE: 0x1d8fd8 | Kích thước: 68 bytes
//   0x09338c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x093390: 910003FD  mov      x29, sp
//   0x093394: 90000B69  adrp     x9, #0x1ff000
//   0x093398: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0688_0x09338c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09338cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8fd8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0689 | PC: 0x0933d0 | FDE: 0x1d8ff8 | Size: 184 bytes [PyFunction_SetKwDefaults]
// Khung tháo gỡ #0689 | Địa chỉ PC: 0x0933d0 | Địa chỉ FDE: 0x1d8ff8 | Kích thước: 184 bytes
//   0x0933d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0933d4: 910003FD  mov      x29, sp
//   0x0933d8: 90000B69  adrp     x9, #0x1ff000
//   0x0933dc: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0689_0x0933d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0933d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d8ff8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0690 | PC: 0x093488 | FDE: 0x1d9018 | Size: 68 bytes [PyFunction_GetClosure]
// Khung tháo gỡ #0690 | Địa chỉ PC: 0x093488 | Địa chỉ FDE: 0x1d9018 | Kích thước: 68 bytes
//   0x093488: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09348c: 910003FD  mov      x29, sp
//   0x093490: 90000B69  adrp     x9, #0x1ff000
//   0x093494: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0690_0x093488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093488ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9018ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0691 | PC: 0x0934cc | FDE: 0x1d9038 | Size: 184 bytes [PyFunction_SetClosure]
// Khung tháo gỡ #0691 | Địa chỉ PC: 0x0934cc | Địa chỉ FDE: 0x1d9038 | Kích thước: 184 bytes
//   0x0934cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0934d0: 910003FD  mov      x29, sp
//   0x0934d4: 90000B69  adrp     x9, #0x1ff000
//   0x0934d8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0691_0x0934cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0934ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9038ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0692 | PC: 0x093584 | FDE: 0x1d9058 | Size: 68 bytes [PyFunction_GetAnnotations]
// Khung tháo gỡ #0692 | Địa chỉ PC: 0x093584 | Địa chỉ FDE: 0x1d9058 | Kích thước: 68 bytes
//   0x093584: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x093588: 910003FD  mov      x29, sp
//   0x09358c: 90000B69  adrp     x9, #0x1ff000
//   0x093590: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0692_0x093584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093584ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9058ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0693 | PC: 0x0935c8 | FDE: 0x1d9078 | Size: 256 bytes [PyFunction_SetAnnotations]
// Khung tháo gỡ #0693 | Địa chỉ PC: 0x0935c8 | Địa chỉ FDE: 0x1d9078 | Kích thước: 256 bytes
//   0x0935c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0935cc: 910003FD  mov      x29, sp
//   0x0935d0: 90000B69  adrp     x9, #0x1ff000
//   0x0935d4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0693_0x0935c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0935c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0694 | PC: 0x094050 | FDE: 0x1d9210 | Size: 256 bytes [PyClassMethod_New]
// Khung tháo gỡ #0694 | Địa chỉ PC: 0x094050 | Địa chỉ FDE: 0x1d9210 | Kích thước: 256 bytes
//   0x094050: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094054: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094058: 910043FD  add      x29, sp, #0x10
//   0x09405c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0694_0x094050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094050ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0695 | PC: 0x0942f4 | FDE: 0x1d9300 | Size: 256 bytes [PyStaticMethod_New]
// Khung tháo gỡ #0695 | Địa chỉ PC: 0x0942f4 | Địa chỉ FDE: 0x1d9300 | Kích thước: 256 bytes
//   0x0942f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0942f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0942fc: 910043FD  add      x29, sp, #0x10
//   0x094300: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0695_0x0942f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0942f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x095010 | FDE: 0x1d95c8 | Size: 84 bytes [_PyInterpreterID_New]
// Khung tháo gỡ #0696 | Địa chỉ PC: 0x095010 | Địa chỉ FDE: 0x1d95c8 | Kích thước: 84 bytes
//   0x095010: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095014: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095018: 910043FD  add      x29, sp, #0x10
//   0x09501c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0696_0x095010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095010ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d95c8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0697 | PC: 0x095064 | FDE: 0x1d95e8 | Size: 112 bytes [_PyInterpreterState_GetIDObject]
// Khung tháo gỡ #0697 | Địa chỉ PC: 0x095064 | Địa chỉ FDE: 0x1d95e8 | Kích thước: 112 bytes
//   0x095064: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095068: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09506c: 910043FD  add      x29, sp, #0x10
//   0x095070: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0697_0x095064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095064ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d95e8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0698 | PC: 0x0950d4 | FDE: 0x1d9608 | Size: 256 bytes [_PyInterpreterID_LookUp]
// Khung tháo gỡ #0698 | Địa chỉ PC: 0x0950d4 | Địa chỉ FDE: 0x1d9608 | Kích thước: 256 bytes
//   0x0950d4: D10083FF  sub      sp, sp, #0x20
//   0x0950d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0950dc: 910043FD  add      x29, sp, #0x10
//   0x0950e0: 910023E1  add      x1, sp, #8
static inline uint64_t fde_func_0698_0x0950d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0950d4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0699 | PC: 0x0951dc | FDE: 0x1d9660 | Size: 256 bytes [PySeqIter_New]
// Khung tháo gỡ #0699 | Địa chỉ PC: 0x0951dc | Địa chỉ FDE: 0x1d9660 | Kích thước: 256 bytes
//   0x0951dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0951e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0951e4: 910043FD  add      x29, sp, #0x10
//   0x0951e8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0699_0x0951dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0951dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0700 | PC: 0x09536c | FDE: 0x1d96e0 | Size: 256 bytes [PyCallIter_New]
// Khung tháo gỡ #0700 | Địa chỉ PC: 0x09536c | Địa chỉ FDE: 0x1d96e0 | Kích thước: 256 bytes
//   0x09536c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095370: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095374: 910043FD  add      x29, sp, #0x10
//   0x095378: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0700_0x09536c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09536cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d96e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0701 | PC: 0x09570c | FDE: 0x1d97c0 | Size: 256 bytes [PyAnextAwaitable_New]
// Khung tháo gỡ #0701 | Địa chỉ PC: 0x09570c | Địa chỉ FDE: 0x1d97c0 | Kích thước: 256 bytes
//   0x09570c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095710: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095714: 910043FD  add      x29, sp, #0x10
//   0x095718: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0701_0x09570c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09570cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d97c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0702 | PC: 0x095b88 | FDE: 0x1d98e0 | Size: 64 bytes [_PyList_ClearFreeList]
// Khung tháo gỡ #0702 | Địa chỉ PC: 0x095b88 | Địa chỉ FDE: 0x1d98e0 | Kích thước: 64 bytes
//   0x095b88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095b8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095b90: 910043FD  add      x29, sp, #0x10
//   0x095b94: B96A8808  ldr      w8, [x0, #0x2a88]
static inline uint64_t fde_func_0702_0x095b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095b88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d98e0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0703 | PC: 0x095bc8 | FDE: 0x1d9900 | Size: 64 bytes [_PyList_Fini]
// Khung tháo gỡ #0703 | Địa chỉ PC: 0x095bc8 | Địa chỉ FDE: 0x1d9900 | Kích thước: 64 bytes
//   0x095bc8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095bcc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095bd0: 910043FD  add      x29, sp, #0x10
//   0x095bd4: B96A8808  ldr      w8, [x0, #0x2a88]
static inline uint64_t fde_func_0703_0x095bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095bc8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9900ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0704 | PC: 0x095c08 | FDE: 0x1d9920 | Size: 72 bytes [_PyList_DebugMallocStats]
// Khung tháo gỡ #0704 | Địa chỉ PC: 0x095c08 | Địa chỉ FDE: 0x1d9920 | Kích thước: 72 bytes
//   0x095c08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095c0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095c10: 910043FD  add      x29, sp, #0x10
//   0x095c14: D0000B48  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0704_0x095c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9920ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0705 | PC: 0x095c50 | FDE: 0x1d9940 | Size: 220 bytes [PyList_New]
// Khung tháo gỡ #0705 | Địa chỉ PC: 0x095c50 | Địa chỉ FDE: 0x1d9940 | Kích thước: 220 bytes
//   0x095c50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095c54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095c58: 910043FD  add      x29, sp, #0x10
//   0x095c5c: B7F80240  tbnz     x0, #0x3f, #0x95ca4
static inline uint64_t fde_func_0705_0x095c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1d9940ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0706 | PC: 0x095d2c | FDE: 0x1d9960 | Size: 60 bytes [PyList_Size]
// Khung tháo gỡ #0706 | Địa chỉ PC: 0x095d2c | Địa chỉ FDE: 0x1d9960 | Kích thước: 60 bytes
//   0x095d2c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x095d30: 910003FD  mov      x29, sp
//   0x095d34: F9400408  ldr      x8, [x0, #8]
//   0x095d38: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0706_0x095d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095d2cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9960ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0707 | PC: 0x095d68 | FDE: 0x1d9980 | Size: 120 bytes [PyList_GetItem]
// Khung tháo gỡ #0707 | Địa chỉ PC: 0x095d68 | Địa chỉ FDE: 0x1d9980 | Kích thước: 120 bytes
//   0x095d68: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x095d6c: 910003FD  mov      x29, sp
//   0x095d70: F9400408  ldr      x8, [x0, #8]
//   0x095d74: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0707_0x095d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095d68ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9980ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0708 | PC: 0x095de0 | FDE: 0x1d99a0 | Size: 196 bytes [PyList_SetItem]
// Khung tháo gỡ #0708 | Địa chỉ PC: 0x095de0 | Địa chỉ FDE: 0x1d99a0 | Kích thước: 196 bytes
//   0x095de0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x095de4: 910003FD  mov      x29, sp
//   0x095de8: F9400408  ldr      x8, [x0, #8]
//   0x095dec: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0708_0x095de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095de0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d99a0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0709 | PC: 0x095ea4 | FDE: 0x1d99c0 | Size: 256 bytes [PyList_Insert]
// Khung tháo gỡ #0709 | Địa chỉ PC: 0x095ea4 | Địa chỉ FDE: 0x1d99c0 | Kích thước: 256 bytes
//   0x095ea4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x095ea8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x095eac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x095eb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0709_0x095ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095ea4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d99c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0710 | PC: 0x095fd8 | FDE: 0x1d99e8 | Size: 228 bytes [PyList_Append]
// Khung tháo gỡ #0710 | Địa chỉ PC: 0x095fd8 | Địa chỉ FDE: 0x1d99e8 | Kích thước: 228 bytes
//   0x095fd8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x095fdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x095fe0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x095fe4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0710_0x095fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095fd8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1d99e8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0711 | PC: 0x0960bc | FDE: 0x1d9a10 | Size: 256 bytes [PyList_GetSlice]
// Khung tháo gỡ #0711 | Địa chỉ PC: 0x0960bc | Địa chỉ FDE: 0x1d9a10 | Kích thước: 256 bytes
//   0x0960bc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0960c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0960c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0960c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0711_0x0960bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0960bcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1d9a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0712 | PC: 0x096258 | FDE: 0x1d9a38 | Size: 256 bytes [PyList_SetSlice]
// Khung tháo gỡ #0712 | Địa chỉ PC: 0x096258 | Địa chỉ FDE: 0x1d9a38 | Kích thước: 256 bytes
//   0x096258: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09625c: 910003FD  mov      x29, sp
//   0x096260: F9400408  ldr      x8, [x0, #8]
//   0x096264: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0712_0x096258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096258ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0713 | PC: 0x0967fc | FDE: 0x1d9a88 | Size: 256 bytes [_PyList_Extend]
// Khung tháo gỡ #0713 | Địa chỉ PC: 0x0967fc | Địa chỉ FDE: 0x1d9a88 | Kích thước: 256 bytes
//   0x0967fc: 14000001  b        #0x96800
//   0x096800: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x096804: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x096808: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_0713_0x0967fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0967fcULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xf81b0ff9ULL) ^ 0x1d9a88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0714 | PC: 0x096b94 | FDE: 0x1d9ac8 | Size: 256 bytes [PyList_Sort]
// Khung tháo gỡ #0714 | Địa chỉ PC: 0x096b94 | Địa chỉ FDE: 0x1d9ac8 | Kích thước: 256 bytes
//   0x096b94: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x096b98: 910003FD  mov      x29, sp
//   0x096b9c: B4000080  cbz      x0, #0x96bac
//   0x096ba0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0714_0x096b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096b94ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0715 | PC: 0x0975c4 | FDE: 0x1d9b18 | Size: 128 bytes [PyList_Reverse]
// Khung tháo gỡ #0715 | Địa chỉ PC: 0x0975c4 | Địa chỉ FDE: 0x1d9b18 | Kích thước: 128 bytes
//   0x0975c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0975c8: 910003FD  mov      x29, sp
//   0x0975cc: B4000080  cbz      x0, #0x975dc
//   0x0975d0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0715_0x0975c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0975c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9b18ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0716 | PC: 0x097644 | FDE: 0x1d9b38 | Size: 256 bytes [PyList_AsTuple]
// Khung tháo gỡ #0716 | Địa chỉ PC: 0x097644 | Địa chỉ FDE: 0x1d9b38 | Kích thước: 256 bytes
//   0x097644: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x097648: 910003FD  mov      x29, sp
//   0x09764c: B4000080  cbz      x0, #0x9765c
//   0x097650: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0716_0x097644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097644ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1d9b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0717 | PC: 0x09b1e0 | FDE: 0x1da230 | Size: 148 bytes [_PyLong_New]
// Khung tháo gỡ #0717 | Địa chỉ PC: 0x09b1e0 | Địa chỉ FDE: 0x1da230 | Kích thước: 148 bytes
//   0x09b1e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09b1e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b1e8: 910043FD  add      x29, sp, #0x10
//   0x09b1ec: 928000A8  mov      x8, #-6
static inline uint64_t fde_func_0717_0x09b1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b1e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da230ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0718 | PC: 0x09b274 | FDE: 0x1da250 | Size: 196 bytes [_PyLong_Copy]
// Khung tháo gỡ #0718 | Địa chỉ PC: 0x09b274 | Địa chỉ FDE: 0x1da250 | Kích thước: 196 bytes
//   0x09b274: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09b278: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b27c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b280: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0718_0x09b274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b274ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1da250ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0719 | PC: 0x09b338 | FDE: 0x1da270 | Size: 220 bytes [PyLong_FromLong]
// Khung tháo gỡ #0719 | Địa chỉ PC: 0x09b338 | Địa chỉ FDE: 0x1da270 | Kích thước: 220 bytes
//   0x09b338: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09b33c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b340: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b344: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0719_0x09b338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b338ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1da270ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0720 | PC: 0x09b414 | FDE: 0x1da290 | Size: 140 bytes [PyLong_FromUnsignedLong]
// Khung tháo gỡ #0720 | Địa chỉ PC: 0x09b414 | Địa chỉ FDE: 0x1da290 | Kích thước: 140 bytes
//   0x09b414: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b418: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b41c: 910043FD  add      x29, sp, #0x10
//   0x09b420: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0720_0x09b414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b414ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da290ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0721 | PC: 0x09b4a0 | FDE: 0x1da2b0 | Size: 140 bytes [PyLong_FromUnsignedLongLong]
// Khung tháo gỡ #0721 | Địa chỉ PC: 0x09b4a0 | Địa chỉ FDE: 0x1da2b0 | Kích thước: 140 bytes
//   0x09b4a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b4a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b4a8: 910043FD  add      x29, sp, #0x10
//   0x09b4ac: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0721_0x09b4a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b4a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da2b0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0722 | PC: 0x09b52c | FDE: 0x1da2d0 | Size: 140 bytes [PyLong_FromSize_t]
// Khung tháo gỡ #0722 | Địa chỉ PC: 0x09b52c | Địa chỉ FDE: 0x1da2d0 | Kích thước: 140 bytes
//   0x09b52c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b534: 910043FD  add      x29, sp, #0x10
//   0x09b538: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0722_0x09b52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b52cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da2d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0723 | PC: 0x09b5b8 | FDE: 0x1da2f0 | Size: 256 bytes [PyLong_FromDouble]
// Khung tháo gỡ #0723 | Địa chỉ PC: 0x09b5b8 | Địa chỉ FDE: 0x1da2f0 | Kích thước: 256 bytes
//   0x09b5b8: 6DBC23E9  stp      d9, d8, [sp, #-0x40]!
//   0x09b5bc: F9000BF5  str      x21, [sp, #0x10]
//   0x09b5c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09b5c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0723_0x09b5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b5b8ULL ^ (static_cast<uint64_t>(0x6dbc23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1da2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0724 | PC: 0x09b71c | FDE: 0x1da318 | Size: 256 bytes [PyLong_AsLongAndOverflow]
// Khung tháo gỡ #0724 | Địa chỉ PC: 0x09b71c | Địa chỉ FDE: 0x1da318 | Kích thước: 256 bytes
//   0x09b71c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09b720: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b724: 910043FD  add      x29, sp, #0x10
//   0x09b728: B900003F  str      wzr, [x1]
static inline uint64_t fde_func_0724_0x09b71c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b71cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0725 | PC: 0x09b838 | FDE: 0x1da338 | Size: 72 bytes [PyLong_AsLong]
// Khung tháo gỡ #0725 | Địa chỉ PC: 0x09b838 | Địa chỉ FDE: 0x1da338 | Kích thước: 72 bytes
//   0x09b838: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b83c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b840: 910043FD  add      x29, sp, #0x10
//   0x09b844: D10013A1  sub      x1, x29, #4
static inline uint64_t fde_func_0725_0x09b838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b838ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da338ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0726 | PC: 0x09b880 | FDE: 0x1da358 | Size: 76 bytes [_PyLong_AsInt]
// Khung tháo gỡ #0726 | Địa chỉ PC: 0x09b880 | Địa chỉ FDE: 0x1da358 | Kích thước: 76 bytes
//   0x09b880: D10083FF  sub      sp, sp, #0x20
//   0x09b884: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b888: 910043FD  add      x29, sp, #0x10
//   0x09b88c: D10013A1  sub      x1, x29, #4
static inline uint64_t fde_func_0726_0x09b880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b880ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da358ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0727 | PC: 0x09b8cc | FDE: 0x1da378 | Size: 244 bytes [PyLong_AsSsize_t]
// Khung tháo gỡ #0727 | Địa chỉ PC: 0x09b8cc | Địa chỉ FDE: 0x1da378 | Kích thước: 244 bytes
//   0x09b8cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09b8d0: 910003FD  mov      x29, sp
//   0x09b8d4: B4000180  cbz      x0, #0x9b904
//   0x09b8d8: F9400409  ldr      x9, [x0, #8]
static inline uint64_t fde_func_0727_0x09b8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b8ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da378ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0728 | PC: 0x09b9c0 | FDE: 0x1da398 | Size: 200 bytes [PyLong_AsUnsignedLong]
// Khung tháo gỡ #0728 | Địa chỉ PC: 0x09b9c0 | Địa chỉ FDE: 0x1da398 | Kích thước: 200 bytes
//   0x09b9c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09b9c4: 910003FD  mov      x29, sp
//   0x09b9c8: B4000140  cbz      x0, #0x9b9f0
//   0x09b9cc: F9400409  ldr      x9, [x0, #8]
static inline uint64_t fde_func_0728_0x09b9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b9c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da398ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0729 | PC: 0x09ba88 | FDE: 0x1da3b8 | Size: 200 bytes [PyLong_AsSize_t]
// Khung tháo gỡ #0729 | Địa chỉ PC: 0x09ba88 | Địa chỉ FDE: 0x1da3b8 | Kích thước: 200 bytes
//   0x09ba88: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09ba8c: 910003FD  mov      x29, sp
//   0x09ba90: B4000140  cbz      x0, #0x9bab8
//   0x09ba94: F9400409  ldr      x9, [x0, #8]
static inline uint64_t fde_func_0729_0x09ba88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ba88ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da3b8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0730 | PC: 0x09bb50 | FDE: 0x1da3d8 | Size: 256 bytes [PyLong_AsUnsignedLongMask]
// Khung tháo gỡ #0730 | Địa chỉ PC: 0x09bb50 | Địa chỉ FDE: 0x1da3d8 | Kích thước: 256 bytes
//   0x09bb50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09bb54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09bb58: 910043FD  add      x29, sp, #0x10
//   0x09bb5c: B4000200  cbz      x0, #0x9bb9c
static inline uint64_t fde_func_0730_0x09bb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bb50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da3d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0731 | PC: 0x09bc60 | FDE: 0x1da418 | Size: 24 bytes [_PyLong_Sign]
// Khung tháo gỡ #0731 | Địa chỉ PC: 0x09bc60 | Địa chỉ FDE: 0x1da418 | Kích thước: 24 bytes
//   0x09bc60: F9400808  ldr      x8, [x0, #0x10]
//   0x09bc64: F100011F  cmp      x8, #0
//   0x09bc68: 12800008  mov      w8, #-1
//   0x09bc6c: 5A88B508  cneg     w8, w8, ge
static inline uint64_t fde_func_0731_0x09bc60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bc60ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x1da418ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0732 | PC: 0x09bc78 | FDE: 0x1da430 | Size: 144 bytes [_PyLong_NumBits]
// Khung tháo gỡ #0732 | Địa chỉ PC: 0x09bc78 | Địa chỉ FDE: 0x1da430 | Kích thước: 144 bytes
//   0x09bc78: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09bc7c: 910003FD  mov      x29, sp
//   0x09bc80: F9400808  ldr      x8, [x0, #0x10]
//   0x09bc84: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0732_0x09bc78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bc78ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da430ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0733 | PC: 0x09bd08 | FDE: 0x1da450 | Size: 256 bytes [_PyLong_FromByteArray]
// Khung tháo gỡ #0733 | Địa chỉ PC: 0x09bd08 | Địa chỉ FDE: 0x1da450 | Kích thước: 256 bytes
//   0x09bd08: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09bd0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09bd10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09bd14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0733_0x09bd08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bd08ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1da450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0734 | PC: 0x09bef0 | FDE: 0x1da478 | Size: 256 bytes [_PyLong_AsByteArray]
// Khung tháo gỡ #0734 | Địa chỉ PC: 0x09bef0 | Địa chỉ FDE: 0x1da478 | Kích thước: 256 bytes
//   0x09bef0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09bef4: 910003FD  mov      x29, sp
//   0x09bef8: F940080C  ldr      x12, [x0, #0x10]
//   0x09befc: B7F8006C  tbnz     x12, #0x3f, #0x9bf08
static inline uint64_t fde_func_0734_0x09bef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bef0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0735 | PC: 0x09c094 | FDE: 0x1da498 | Size: 4 bytes [PyLong_FromVoidPtr]
// Khung tháo gỡ #0735 | Địa chỉ PC: 0x09c094 | Địa chỉ FDE: 0x1da498 | Kích thước: 4 bytes
//   0x09c094: 17FF001F  b        #0x5c110
static inline uint64_t fde_func_0735_0x09c094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c094ULL ^ (static_cast<uint64_t>(0x17ff001fULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1da498ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0736 | PC: 0x09c098 | FDE: 0x1da4b0 | Size: 84 bytes [PyLong_AsVoidPtr]
// Khung tháo gỡ #0736 | Địa chỉ PC: 0x09c098 | Địa chỉ FDE: 0x1da4b0 | Kích thước: 84 bytes
//   0x09c098: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09c09c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c0a0: 910043FD  add      x29, sp, #0x10
//   0x09c0a4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0736_0x09c098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c098ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da4b0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0737 | PC: 0x09c0ec | FDE: 0x1da4d0 | Size: 184 bytes [PyLong_FromLongLong]
// Khung tháo gỡ #0737 | Địa chỉ PC: 0x09c0ec | Địa chỉ FDE: 0x1da4d0 | Kích thước: 184 bytes
//   0x09c0ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09c0f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09c0f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09c0f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0737_0x09c0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c0ecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1da4d0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0738 | PC: 0x09c1a4 | FDE: 0x1da4f0 | Size: 184 bytes [PyLong_FromSsize_t]
// Khung tháo gỡ #0738 | Địa chỉ PC: 0x09c1a4 | Địa chỉ FDE: 0x1da4f0 | Kích thước: 184 bytes
//   0x09c1a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09c1a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09c1ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09c1b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0738_0x09c1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c1a4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1da4f0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0739 | PC: 0x09c25c | FDE: 0x1da510 | Size: 252 bytes [PyLong_AsLongLong]
// Khung tháo gỡ #0739 | Địa chỉ PC: 0x09c25c | Địa chỉ FDE: 0x1da510 | Kích thước: 252 bytes
//   0x09c25c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09c260: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09c264: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09c268: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0739_0x09c25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c25cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1da510ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0740 | PC: 0x09c358 | FDE: 0x1da530 | Size: 160 bytes [PyLong_AsUnsignedLongLong]
// Khung tháo gỡ #0740 | Địa chỉ PC: 0x09c358 | Địa chỉ FDE: 0x1da530 | Kích thước: 160 bytes
//   0x09c358: D10083FF  sub      sp, sp, #0x20
//   0x09c35c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c360: 910043FD  add      x29, sp, #0x10
//   0x09c364: B4000180  cbz      x0, #0x9c394
static inline uint64_t fde_func_0740_0x09c358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c358ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da530ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0741 | PC: 0x09c3f8 | FDE: 0x1da550 | Size: 256 bytes [PyLong_AsUnsignedLongLongMask]
// Khung tháo gỡ #0741 | Địa chỉ PC: 0x09c3f8 | Địa chỉ FDE: 0x1da550 | Kích thước: 256 bytes
//   0x09c3f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c3fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c400: 910043FD  add      x29, sp, #0x10
//   0x09c404: B4000200  cbz      x0, #0x9c444
static inline uint64_t fde_func_0741_0x09c3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c3f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0742 | PC: 0x09c508 | FDE: 0x1da590 | Size: 256 bytes [PyLong_AsLongLongAndOverflow]
// Khung tháo gỡ #0742 | Địa chỉ PC: 0x09c508 | Địa chỉ FDE: 0x1da590 | Kích thước: 256 bytes
//   0x09c508: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c50c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c510: 910043FD  add      x29, sp, #0x10
//   0x09c514: B900003F  str      wzr, [x1]
static inline uint64_t fde_func_0742_0x09c508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c508ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0743 | PC: 0x09c624 | FDE: 0x1da5b0 | Size: 136 bytes [_PyLong_UnsignedShort_Converter]
// Khung tháo gỡ #0743 | Địa chỉ PC: 0x09c624 | Địa chỉ FDE: 0x1da5b0 | Kích thước: 136 bytes
//   0x09c624: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09c628: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c62c: 910043FD  add      x29, sp, #0x10
//   0x09c630: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0743_0x09c624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c624ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da5b0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0744 | PC: 0x09c6ac | FDE: 0x1da5d0 | Size: 136 bytes [_PyLong_UnsignedInt_Converter]
// Khung tháo gỡ #0744 | Địa chỉ PC: 0x09c6ac | Địa chỉ FDE: 0x1da5d0 | Kích thước: 136 bytes
//   0x09c6ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09c6b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c6b4: 910043FD  add      x29, sp, #0x10
//   0x09c6b8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0744_0x09c6ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c6acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da5d0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0745 | PC: 0x09c734 | FDE: 0x1da5f0 | Size: 116 bytes [_PyLong_UnsignedLong_Converter]
// Khung tháo gỡ #0745 | Địa chỉ PC: 0x09c734 | Địa chỉ FDE: 0x1da5f0 | Kích thước: 116 bytes
//   0x09c734: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c738: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c73c: 910043FD  add      x29, sp, #0x10
//   0x09c740: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0745_0x09c734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c734ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da5f0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0746 | PC: 0x09c7a8 | FDE: 0x1da610 | Size: 116 bytes [_PyLong_UnsignedLongLong_Converter]
// Khung tháo gỡ #0746 | Địa chỉ PC: 0x09c7a8 | Địa chỉ FDE: 0x1da610 | Kích thước: 116 bytes
//   0x09c7a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c7ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c7b0: 910043FD  add      x29, sp, #0x10
//   0x09c7b4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0746_0x09c7a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c7a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da610ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0747 | PC: 0x09c81c | FDE: 0x1da630 | Size: 116 bytes [_PyLong_Size_t_Converter]
// Khung tháo gỡ #0747 | Địa chỉ PC: 0x09c81c | Địa chỉ FDE: 0x1da630 | Kích thước: 116 bytes
//   0x09c81c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c820: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c824: 910043FD  add      x29, sp, #0x10
//   0x09c828: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0747_0x09c81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c81cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da630ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0748 | PC: 0x09c890 | FDE: 0x1da650 | Size: 256 bytes [_PyLong_Format]
// Khung tháo gỡ #0748 | Địa chỉ PC: 0x09c890 | Địa chỉ FDE: 0x1da650 | Kích thước: 256 bytes
//   0x09c890: D10083FF  sub      sp, sp, #0x20
//   0x09c894: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c898: 910043FD  add      x29, sp, #0x10
//   0x09c89c: 7100283F  cmp      w1, #0xa
static inline uint64_t fde_func_0748_0x09c890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c890ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x09d658 | FDE: 0x1da6d0 | Size: 60 bytes [_PyLong_FormatWriter]
// Khung tháo gỡ #0749 | Địa chỉ PC: 0x09d658 | Địa chỉ FDE: 0x1da6d0 | Kích thước: 60 bytes
//   0x09d658: 7100285F  cmp      w2, #0xa
//   0x09d65c: AA0003E4  mov      x4, x0
//   0x09d660: AA0103E0  mov      x0, x1
//   0x09d664: 540000C1  b.ne     #0x9d67c
static inline uint64_t fde_func_0749_0x09d658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d658ULL ^ (static_cast<uint64_t>(0x7100285fULL) << 13);
    acc = (acc + a1 + 0xaa0003e4ULL) ^ 0x1da6d0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0750 | PC: 0x09d694 | FDE: 0x1da6e8 | Size: 108 bytes [_PyLong_FormatBytesWriter]
// Khung tháo gỡ #0750 | Địa chỉ PC: 0x09d694 | Địa chỉ FDE: 0x1da6e8 | Kích thước: 108 bytes
//   0x09d694: D10083FF  sub      sp, sp, #0x20
//   0x09d698: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d69c: 910043FD  add      x29, sp, #0x10
//   0x09d6a0: AA0003E5  mov      x5, x0
static inline uint64_t fde_func_0750_0x09d694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d694ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1da6e8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0751 | PC: 0x09d700 | FDE: 0x1da708 | Size: 256 bytes [PyLong_FromString]
// Khung tháo gỡ #0751 | Địa chỉ PC: 0x09d700 | Địa chỉ FDE: 0x1da708 | Kích thước: 256 bytes
//   0x09d700: D10283FF  sub      sp, sp, #0xa0
//   0x09d704: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x09d708: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x09d70c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0751_0x09d700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d700ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1da708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0752 | PC: 0x09dfa4 | FDE: 0x1da758 | Size: 232 bytes [_PyLong_FromBytes]
// Khung tháo gỡ #0752 | Địa chỉ PC: 0x09dfa4 | Địa chỉ FDE: 0x1da758 | Kích thước: 232 bytes
//   0x09dfa4: D10103FF  sub      sp, sp, #0x40
//   0x09dfa8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09dfac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09dfb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0752_0x09dfa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09dfa4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1da758ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0753 | PC: 0x09e08c | FDE: 0x1da780 | Size: 256 bytes [PyLong_FromUnicodeObject]
// Khung tháo gỡ #0753 | Địa chỉ PC: 0x09e08c | Địa chỉ FDE: 0x1da780 | Kích thước: 256 bytes
//   0x09e08c: D10183FF  sub      sp, sp, #0x60
//   0x09e090: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09e094: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09e098: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0753_0x09e08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e08cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1da780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0754 | PC: 0x09e1a4 | FDE: 0x1da7a8 | Size: 256 bytes [_PyLong_Frexp]
// Khung tháo gỡ #0754 | Địa chỉ PC: 0x09e1a4 | Địa chỉ FDE: 0x1da7a8 | Kích thước: 256 bytes
//   0x09e1a4: D10103FF  sub      sp, sp, #0x40
//   0x09e1a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09e1ac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09e1b0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0754_0x09e1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e1a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1da7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0755 | PC: 0x09e450 | FDE: 0x1da7c8 | Size: 240 bytes [PyLong_AsDouble]
// Khung tháo gỡ #0755 | Địa chỉ PC: 0x09e450 | Địa chỉ FDE: 0x1da7c8 | Kích thước: 240 bytes
//   0x09e450: D100C3FF  sub      sp, sp, #0x30
//   0x09e454: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x09e458: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09e45c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0755_0x09e450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e450ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1da7c8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0756 | PC: 0x09e540 | FDE: 0x1da7e8 | Size: 256 bytes [_PyLong_Rshift]
// Khung tháo gỡ #0756 | Địa chỉ PC: 0x09e540 | Địa chỉ FDE: 0x1da7e8 | Kích thước: 256 bytes
//   0x09e540: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09e544: 910003FD  mov      x29, sp
//   0x09e548: F9400808  ldr      x8, [x0, #0x10]
//   0x09e54c: B4000148  cbz      x8, #0x9e574
static inline uint64_t fde_func_0756_0x09e540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e540ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da7e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0757 | PC: 0x09e734 | FDE: 0x1da830 | Size: 256 bytes [_PyLong_Lshift]
// Khung tháo gỡ #0757 | Địa chỉ PC: 0x09e734 | Địa chỉ FDE: 0x1da830 | Kích thước: 256 bytes
//   0x09e734: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09e738: 910003FD  mov      x29, sp
//   0x09e73c: F9400808  ldr      x8, [x0, #0x10]
//   0x09e740: B4000148  cbz      x8, #0x9e768
static inline uint64_t fde_func_0757_0x09e734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e734ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1da830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0758 | PC: 0x09e8c8 | FDE: 0x1da878 | Size: 256 bytes [_PyLong_GCD]
// Khung tháo gỡ #0758 | Địa chỉ PC: 0x09e8c8 | Địa chỉ FDE: 0x1da878 | Kích thước: 256 bytes
//   0x09e8c8: D10243FF  sub      sp, sp, #0x90
//   0x09e8cc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x09e8d0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x09e8d4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0758_0x09e8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e8c8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1da878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0759 | PC: 0x09f294 | FDE: 0x1da900 | Size: 256 bytes [_PyLong_DivmodNear]
// Khung tháo gỡ #0759 | Địa chỉ PC: 0x09f294 | Địa chỉ FDE: 0x1da900 | Kích thước: 256 bytes
//   0x09f294: D10183FF  sub      sp, sp, #0x60
//   0x09f298: A9017FF9  stp      x25, xzr, [sp, #0x10]
//   0x09f29c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09f2a0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0759_0x09f294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f294ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9017ff9ULL) ^ 0x1da900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0760 | PC: 0x09fd80 | FDE: 0x1daa50 | Size: 156 bytes [PyLong_GetInfo]
// Khung tháo gỡ #0760 | Địa chỉ PC: 0x09fd80 | Địa chỉ FDE: 0x1daa50 | Kích thước: 156 bytes
//   0x09fd80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fd84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09fd88: 910043FD  add      x29, sp, #0x10
//   0x09fd8c: B0000C20  adrp     x0, #0x224000
static inline uint64_t fde_func_0760_0x09fd80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fd80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1daa50ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0761 | PC: 0x09fe1c | FDE: 0x1daa70 | Size: 120 bytes [_PyLong_Init]
// Khung tháo gỡ #0761 | Địa chỉ PC: 0x09fe1c | Địa chỉ FDE: 0x1daa70 | Kích thước: 120 bytes
//   0x09fe1c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09fe20: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09fe24: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09fe28: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0761_0x09fe1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fe1cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1daa70ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0762 | PC: 0x09fe94 | FDE: 0x1daa98 | Size: 64 bytes [_PyLong_InitTypes]
// Khung tháo gỡ #0762 | Địa chỉ PC: 0x09fe94 | Địa chỉ FDE: 0x1daa98 | Kích thước: 64 bytes
//   0x09fe94: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09fe98: 910003FD  mov      x29, sp
//   0x09fe9c: B0000C28  adrp     x8, #0x224000
//   0x09fea0: F940B508  ldr      x8, [x8, #0x168]
static inline uint64_t fde_func_0762_0x09fe94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fe94ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1daa98ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0763 | PC: 0x09fed4 | FDE: 0x1daab8 | Size: 256 bytes [_PyLong_Fini]
// Khung tháo gỡ #0763 | Địa chỉ PC: 0x09fed4 | Địa chỉ FDE: 0x1daab8 | Kích thước: 256 bytes
//   0x09fed4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fed8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09fedc: 910043FD  add      x29, sp, #0x10
//   0x09fee0: AA1F03F3  mov      x19, xzr
static inline uint64_t fde_func_0763_0x09fed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fed4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1daab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0764 | PC: 0x0a3b6c | FDE: 0x1daff8 | Size: 96 bytes [_PyDict_ClearFreeList]
// Khung tháo gỡ #0764 | Địa chỉ PC: 0x0a3b6c | Địa chỉ FDE: 0x1daff8 | Kích thước: 96 bytes
//   0x0a3b6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a3b70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3b74: 910043FD  add      x29, sp, #0x10
//   0x0a3b78: B96D1008  ldr      w8, [x0, #0x2d10]
static inline uint64_t fde_func_0764_0x0a3b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3b6cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1daff8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0765 | PC: 0x0a3bcc | FDE: 0x1db018 | Size: 4 bytes [_PyDict_Fini]
// Khung tháo gỡ #0765 | Địa chỉ PC: 0x0a3bcc | Địa chỉ FDE: 0x1db018 | Kích thước: 4 bytes
//   0x0a3bcc: 17FEE669  b        #0x5d570
static inline uint64_t fde_func_0765_0x0a3bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3bccULL ^ (static_cast<uint64_t>(0x17fee669ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1db018ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0766 | PC: 0x0a3bd0 | FDE: 0x1db030 | Size: 72 bytes [_PyDict_DebugMallocStats]
// Khung tháo gỡ #0766 | Địa chỉ PC: 0x0a3bd0 | Địa chỉ FDE: 0x1db030 | Kích thước: 72 bytes
//   0x0a3bd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a3bd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3bd8: 910043FD  add      x29, sp, #0x10
//   0x0a3bdc: 90000AE8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_0766_0x0a3bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3bd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db030ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0767 | PC: 0x0a3c18 | FDE: 0x1db050 | Size: 256 bytes [_PyDict_CheckConsistency]
// Khung tháo gỡ #0767 | Địa chỉ PC: 0x0a3c18 | Địa chỉ FDE: 0x1db050 | Kích thước: 256 bytes
//   0x0a3c18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a3c1c: 910003FD  mov      x29, sp
//   0x0a3c20: F9400408  ldr      x8, [x0, #8]
//   0x0a3c24: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_0767_0x0a3c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3c18ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1db050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0768 | PC: 0x0a3fb4 | FDE: 0x1db070 | Size: 228 bytes [PyDict_New]
// Khung tháo gỡ #0768 | Địa chỉ PC: 0x0a3fb4 | Địa chỉ FDE: 0x1db070 | Kích thước: 228 bytes
//   0x0a3fb4: D0000B40  adrp     x0, #0x20d000
//   0x0a3fb8: 9132C000  add      x0, x0, #0xcb0
//   0x0a3fbc: F9400008  ldr      x8, [x0]
//   0x0a3fc0: B0000C01  adrp     x1, #0x224000
static inline uint64_t fde_func_0768_0x0a3fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3fb4ULL ^ (static_cast<uint64_t>(0xd0000b40ULL) << 13);
    acc = (acc + a1 + 0x9132c000ULL) ^ 0x1db070ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0769 | PC: 0x0a4098 | FDE: 0x1db0a8 | Size: 256 bytes [lookdict_unicode]
// Khung tháo gỡ #0769 | Địa chỉ PC: 0x0a4098 | Địa chỉ FDE: 0x1db0a8 | Kích thước: 256 bytes
//   0x0a4098: D10203FF  sub      sp, sp, #0x80
//   0x0a409c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0a40a0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a40a4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0769_0x0a4098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4098ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1db0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0770 | PC: 0x0a4464 | FDE: 0x1db108 | Size: 256 bytes [lookdict_unicode_nodummy]
// Khung tháo gỡ #0770 | Địa chỉ PC: 0x0a4464 | Địa chỉ FDE: 0x1db108 | Kích thước: 256 bytes
//   0x0a4464: D10203FF  sub      sp, sp, #0x80
//   0x0a4468: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0a446c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a4470: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0770_0x0a4464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4464ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1db108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0771 | PC: 0x0a466c | FDE: 0x1db138 | Size: 256 bytes [lookdict_split]
// Khung tháo gỡ #0771 | Địa chỉ PC: 0x0a466c | Địa chỉ FDE: 0x1db138 | Kích thước: 256 bytes
//   0x0a466c: D10243FF  sub      sp, sp, #0x90
//   0x0a4670: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0a4674: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0a4678: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0771_0x0a466c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a466cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1db138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0772 | PC: 0x0a4884 | FDE: 0x1db168 | Size: 152 bytes [_PyDict_HasOnlyStringKeys]
// Khung tháo gỡ #0772 | Địa chỉ PC: 0x0a4884 | Địa chỉ FDE: 0x1db168 | Kích thước: 152 bytes
//   0x0a4884: D10103FF  sub      sp, sp, #0x40
//   0x0a4888: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a488c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a4890: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0772_0x0a4884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4884ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1db168ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0773 | PC: 0x0a491c | FDE: 0x1db188 | Size: 8 bytes [PyDict_Next]
// Khung tháo gỡ #0773 | Địa chỉ PC: 0x0a491c | Địa chỉ FDE: 0x1db188 | Kích thước: 8 bytes
//   0x0a491c: AA1F03E4  mov      x4, xzr
//   0x0a4920: 17FED650  b        #0x5a260
static inline uint64_t fde_func_0773_0x0a491c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a491cULL ^ (static_cast<uint64_t>(0xaa1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fed650ULL) ^ 0x1db188ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0774 | PC: 0x0a4924 | FDE: 0x1db1a0 | Size: 256 bytes [_PyDict_MaybeUntrack]
// Khung tháo gỡ #0774 | Địa chỉ PC: 0x0a4924 | Địa chỉ FDE: 0x1db1a0 | Kích thước: 256 bytes
//   0x0a4924: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a4928: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a492c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a4930: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0774_0x0a4924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4924ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1db1a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0775 | PC: 0x0a4a7c | FDE: 0x1db1c8 | Size: 256 bytes [_PyDict_NewPresized]
// Khung tháo gỡ #0775 | Địa chỉ PC: 0x0a4a7c | Địa chỉ FDE: 0x1db1c8 | Kích thước: 256 bytes
//   0x0a4a7c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a4a80: 910003FD  mov      x29, sp
//   0x0a4a84: F100141F  cmp      x0, #5
//   0x0a4a88: 5400012C  b.gt     #0xa4aac
static inline uint64_t fde_func_0775_0x0a4a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4a7cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1db1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0776 | PC: 0x0a4c5c | FDE: 0x1db210 | Size: 248 bytes [PyDict_GetItem]
// Khung tháo gỡ #0776 | Địa chỉ PC: 0x0a4c5c | Địa chỉ FDE: 0x1db210 | Kích thước: 248 bytes
//   0x0a4c5c: D101C3FF  sub      sp, sp, #0x70
//   0x0a4c60: F9001BF7  str      x23, [sp, #0x30]
//   0x0a4c64: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a4c68: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0776_0x0a4c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4c5cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1db210ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0777 | PC: 0x0a4d54 | FDE: 0x1db238 | Size: 256 bytes [_PyDict_GetItemHint]
// Khung tháo gỡ #0777 | Địa chỉ PC: 0x0a4d54 | Địa chỉ FDE: 0x1db238 | Kích thước: 256 bytes
//   0x0a4d54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a4d58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a4d5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a4d60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0777_0x0a4d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4d54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1db238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0778 | PC: 0x0a4e68 | FDE: 0x1db258 | Size: 128 bytes [_PyDict_GetItem_KnownHash]
// Khung tháo gỡ #0778 | Địa chỉ PC: 0x0a4e68 | Địa chỉ FDE: 0x1db258 | Kích thước: 128 bytes
//   0x0a4e68: D100C3FF  sub      sp, sp, #0x30
//   0x0a4e6c: F9000BF3  str      x19, [sp, #0x10]
//   0x0a4e70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a4e74: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0778_0x0a4e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4e68ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1db258ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0779 | PC: 0x0a4ee8 | FDE: 0x1db278 | Size: 208 bytes [PyDict_GetItemWithError]
// Khung tháo gỡ #0779 | Địa chỉ PC: 0x0a4ee8 | Địa chỉ FDE: 0x1db278 | Kích thước: 208 bytes
//   0x0a4ee8: D10103FF  sub      sp, sp, #0x40
//   0x0a4eec: F9000BF5  str      x21, [sp, #0x10]
//   0x0a4ef0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a4ef4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0779_0x0a4ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4ee8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1db278ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0780 | PC: 0x0a4fb8 | FDE: 0x1db298 | Size: 64 bytes [_PyDict_GetItemIdWithError]
// Khung tháo gỡ #0780 | Địa chỉ PC: 0x0a4fb8 | Địa chỉ FDE: 0x1db298 | Kích thước: 64 bytes
//   0x0a4fb8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4fbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4fc0: 910043FD  add      x29, sp, #0x10
//   0x0a4fc4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0780_0x0a4fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4fb8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db298ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0781 | PC: 0x0a4ff8 | FDE: 0x1db2b8 | Size: 96 bytes [_PyDict_GetItemStringWithError]
// Khung tháo gỡ #0781 | Địa chỉ PC: 0x0a4ff8 | Địa chỉ FDE: 0x1db2b8 | Kích thước: 96 bytes
//   0x0a4ff8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a4ffc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a5000: 910043FD  add      x29, sp, #0x10
//   0x0a5004: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0781_0x0a4ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4ff8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db2b8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0782 | PC: 0x0a5058 | FDE: 0x1db2d8 | Size: 248 bytes [_PyDict_LoadGlobal]
// Khung tháo gỡ #0782 | Địa chỉ PC: 0x0a5058 | Địa chỉ FDE: 0x1db2d8 | Kích thước: 248 bytes
//   0x0a5058: D10143FF  sub      sp, sp, #0x50
//   0x0a505c: F9000BF7  str      x23, [sp, #0x10]
//   0x0a5060: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a5064: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0782_0x0a5058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5058ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1db2d8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0783 | PC: 0x0a5150 | FDE: 0x1db300 | Size: 256 bytes [BD_PyDict_SetItem_Take2]
// Khung tháo gỡ #0783 | Địa chỉ PC: 0x0a5150 | Địa chỉ FDE: 0x1db300 | Kích thước: 256 bytes
//   0x0a5150: D10183FF  sub      sp, sp, #0x60
//   0x0a5154: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a5158: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a515c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0783_0x0a5150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5150ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1db300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x0a56cc | FDE: 0x1db330 | Size: 256 bytes [PyDict_SetItem]
// Khung tháo gỡ #0784 | Địa chỉ PC: 0x0a56cc | Địa chỉ FDE: 0x1db330 | Kích thước: 256 bytes
//   0x0a56cc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a56d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a56d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a56d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0784_0x0a56cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a56ccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1db330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0785 | PC: 0x0a5d64 | FDE: 0x1db3a0 | Size: 96 bytes [_PyDict_SetItem_KnownHash]
// Khung tháo gỡ #0785 | Địa chỉ PC: 0x0a5d64 | Địa chỉ FDE: 0x1db3a0 | Kích thước: 96 bytes
//   0x0a5d64: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a5d68: 910003FD  mov      x29, sp
//   0x0a5d6c: F9400409  ldr      x9, [x0, #8]
//   0x0a5d70: 3942AD29  ldrb     w9, [x9, #0xab]
static inline uint64_t fde_func_0785_0x0a5d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5d64ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1db3a0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0786 | PC: 0x0a5dc4 | FDE: 0x1db3c0 | Size: 104 bytes [PyDict_DelItem]
// Khung tháo gỡ #0786 | Địa chỉ PC: 0x0a5dc4 | Địa chỉ FDE: 0x1db3c0 | Kích thước: 104 bytes
//   0x0a5dc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a5dc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a5dcc: 910043FD  add      x29, sp, #0x10
//   0x0a5dd0: D0000AC9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_0786_0x0a5dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5dc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1db3c0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0787 | PC: 0x0a5e2c | FDE: 0x1db3e0 | Size: 256 bytes [_PyDict_DelItem_KnownHash]
// Khung tháo gỡ #0787 | Địa chỉ PC: 0x0a5e2c | Địa chỉ FDE: 0x1db3e0 | Kích thước: 256 bytes
//   0x0a5e2c: D10103FF  sub      sp, sp, #0x40
//   0x0a5e30: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a5e34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a5e38: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0787_0x0a5e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5e2cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1db3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0788 | PC: 0x0a6370 | FDE: 0x1db458 | Size: 256 bytes [_PyDict_DelItemIf]
// Khung tháo gỡ #0788 | Địa chỉ PC: 0x0a6370 | Địa chỉ FDE: 0x1db458 | Kích thước: 256 bytes
//   0x0a6370: D10143FF  sub      sp, sp, #0x50
//   0x0a6374: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a6378: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a637c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0788_0x0a6370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6370ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1db458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0789 | PC: 0x0a6548 | FDE: 0x1db498 | Size: 256 bytes [PyDict_Clear]
// Khung tháo gỡ #0789 | Địa chỉ PC: 0x0a6548 | Địa chỉ FDE: 0x1db498 | Kích thước: 256 bytes
//   0x0a6548: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a654c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a6550: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a6554: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0789_0x0a6548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6548ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1db498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x0a6734 | FDE: 0x1db4e0 | Size: 256 bytes [_PyDict_Next]
// Khung tháo gỡ #0790 | Địa chỉ PC: 0x0a6734 | Địa chỉ FDE: 0x1db4e0 | Kích thước: 256 bytes
//   0x0a6734: F9400409  ldr      x9, [x0, #8]
//   0x0a6738: 3942AD29  ldrb     w9, [x9, #0xab]
//   0x0a673c: 37280069  tbnz     w9, #5, #0xa6748
//   0x0a6740: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_0790_0x0a6734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6734ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x3942ad29ULL) ^ 0x1db4e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0791 | PC: 0x0a6870 | FDE: 0x1db4f8 | Size: 256 bytes [_PyDict_Pop_KnownHash]
// Khung tháo gỡ #0791 | Địa chỉ PC: 0x0a6870 | Địa chỉ FDE: 0x1db4f8 | Kích thước: 256 bytes
//   0x0a6870: D10143FF  sub      sp, sp, #0x50
//   0x0a6874: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a6878: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a687c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0791_0x0a6870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6870ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1db4f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0792 | PC: 0x0a6a8c | FDE: 0x1db520 | Size: 172 bytes [_PyDict_Pop]
// Khung tháo gỡ #0792 | Địa chỉ PC: 0x0a6a8c | Địa chỉ FDE: 0x1db520 | Kích thước: 172 bytes
//   0x0a6a8c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a6a90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a6a94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a6a98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0792_0x0a6a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6a8cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1db520ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0793 | PC: 0x0a6b38 | FDE: 0x1db540 | Size: 256 bytes [_PyDict_FromKeys]
// Khung tháo gỡ #0793 | Địa chỉ PC: 0x0a6b38 | Địa chỉ FDE: 0x1db540 | Kích thước: 256 bytes
//   0x0a6b38: D101C3FF  sub      sp, sp, #0x70
//   0x0a6b3c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a6b40: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a6b44: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0793_0x0a6b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6b38ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1db540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0794 | PC: 0x0a6e48 | FDE: 0x1db568 | Size: 256 bytes [PyDict_MergeFromSeq2]
// Khung tháo gỡ #0794 | Địa chỉ PC: 0x0a6e48 | Địa chỉ FDE: 0x1db568 | Kích thước: 256 bytes
//   0x0a6e48: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0a6e4c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a6e50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a6e54: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0794_0x0a6e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6e48ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1db568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0795 | PC: 0x0a7088 | FDE: 0x1db598 | Size: 256 bytes [PyDict_SetDefault]
// Khung tháo gỡ #0795 | Địa chỉ PC: 0x0a7088 | Địa chỉ FDE: 0x1db598 | Kích thước: 256 bytes
//   0x0a7088: D10183FF  sub      sp, sp, #0x60
//   0x0a708c: F9000BF9  str      x25, [sp, #0x10]
//   0x0a7090: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a7094: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0795_0x0a7088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7088ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1db598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0796 | PC: 0x0a749c | FDE: 0x1db5c0 | Size: 256 bytes [PyDict_Update]
// Khung tháo gỡ #0796 | Địa chỉ PC: 0x0a749c | Địa chỉ FDE: 0x1db5c0 | Kích thước: 256 bytes
//   0x0a749c: 52800022  mov      w2, #1
//   0x0a74a0: 14000001  b        #0xa74a4
//   0x0a74a4: D10203FF  sub      sp, sp, #0x80
//   0x0a74a8: A9026FFC  stp      x28, x27, [sp, #0x20]
static inline uint64_t fde_func_0796_0x0a749c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a749cULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1db5c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0797 | PC: 0x0a79a0 | FDE: 0x1db608 | Size: 12 bytes [PyDict_Merge]
// Khung tháo gỡ #0797 | Địa chỉ PC: 0x0a79a0 | Địa chỉ FDE: 0x1db608 | Kích thước: 12 bytes
//   0x0a79a0: 7100005F  cmp      w2, #0
//   0x0a79a4: 1A9F07E2  cset     w2, ne
//   0x0a79a8: 17FFFEBF  b        #0xa74a4
static inline uint64_t fde_func_0797_0x0a79a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a79a0ULL ^ (static_cast<uint64_t>(0x7100005fULL) << 13);
    acc = (acc + a1 + 0x1a9f07e2ULL) ^ 0x1db608ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0798 | PC: 0x0a79ac | FDE: 0x1db620 | Size: 4 bytes [_PyDict_MergeEx]
// Khung tháo gỡ #0798 | Địa chỉ PC: 0x0a79ac | Địa chỉ FDE: 0x1db620 | Kích thước: 4 bytes
//   0x0a79ac: 17FFFEBE  b        #0xa74a4
static inline uint64_t fde_func_0798_0x0a79ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a79acULL ^ (static_cast<uint64_t>(0x17fffebeULL) << 13);
    acc = (acc + a1 + 0xf81c0ff7ULL) ^ 0x1db620ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0799 | PC: 0x0a79b0 | FDE: 0x1db638 | Size: 256 bytes [PyDict_Copy]
// Khung tháo gỡ #0799 | Địa chỉ PC: 0x0a79b0 | Địa chỉ FDE: 0x1db638 | Kích thước: 256 bytes
//   0x0a79b0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a79b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a79b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a79bc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0799_0x0a79b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a79b0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1db638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 400: return fde_func_0400_0x076320(a0, a1);
        case 401: return fde_func_0401_0x076450(a0, a1);
        case 402: return fde_func_0402_0x076580(a0, a1);
        case 403: return fde_func_0403_0x0766b0(a0, a1);
        case 404: return fde_func_0404_0x0767d0(a0, a1);
        case 405: return fde_func_0405_0x076900(a0, a1);
        case 406: return fde_func_0406_0x076b3c(a0, a1);
        case 407: return fde_func_0407_0x076c78(a0, a1);
        case 408: return fde_func_0408_0x076d28(a0, a1);
        case 409: return fde_func_0409_0x076d90(a0, a1);
        case 410: return fde_func_0410_0x076dec(a0, a1);
        case 411: return fde_func_0411_0x076e80(a0, a1);
        case 412: return fde_func_0412_0x076ed8(a0, a1);
        case 413: return fde_func_0413_0x076f30(a0, a1);
        case 414: return fde_func_0414_0x076f88(a0, a1);
        case 415: return fde_func_0415_0x076ffc(a0, a1);
        case 416: return fde_func_0416_0x077058(a0, a1);
        case 417: return fde_func_0417_0x0770b4(a0, a1);
        case 418: return fde_func_0418_0x077110(a0, a1);
        case 419: return fde_func_0419_0x0772d8(a0, a1);
        case 420: return fde_func_0420_0x077308(a0, a1);
        case 421: return fde_func_0421_0x077344(a0, a1);
        case 422: return fde_func_0422_0x077384(a0, a1);
        case 423: return fde_func_0423_0x0773d8(a0, a1);
        case 424: return fde_func_0424_0x077450(a0, a1);
        case 425: return fde_func_0425_0x07748c(a0, a1);
        case 426: return fde_func_0426_0x0774b8(a0, a1);
        case 427: return fde_func_0427_0x0774ec(a0, a1);
        case 428: return fde_func_0428_0x077524(a0, a1);
        case 429: return fde_func_0429_0x0775f0(a0, a1);
        case 430: return fde_func_0430_0x0776a0(a0, a1);
        case 431: return fde_func_0431_0x0776ec(a0, a1);
        case 432: return fde_func_0432_0x077734(a0, a1);
        case 433: return fde_func_0433_0x077778(a0, a1);
        case 434: return fde_func_0434_0x0777bc(a0, a1);
        case 435: return fde_func_0435_0x077838(a0, a1);
        case 436: return fde_func_0436_0x077a78(a0, a1);
        case 437: return fde_func_0437_0x077ae8(a0, a1);
        case 438: return fde_func_0438_0x077bec(a0, a1);
        case 439: return fde_func_0439_0x077c38(a0, a1);
        case 440: return fde_func_0440_0x077cd8(a0, a1);
        case 441: return fde_func_0441_0x077d30(a0, a1);
        case 442: return fde_func_0442_0x077dfc(a0, a1);
        case 443: return fde_func_0443_0x077e0c(a0, a1);
        case 444: return fde_func_0444_0x077f30(a0, a1);
        case 445: return fde_func_0445_0x077f6c(a0, a1);
        case 446: return fde_func_0446_0x077fb0(a0, a1);
        case 447: return fde_func_0447_0x077fe8(a0, a1);
        case 448: return fde_func_0448_0x0780f8(a0, a1);
        case 449: return fde_func_0449_0x078100(a0, a1);
        case 450: return fde_func_0450_0x0781a0(a0, a1);
        case 451: return fde_func_0451_0x0781d4(a0, a1);
        case 452: return fde_func_0452_0x078274(a0, a1);
        case 453: return fde_func_0453_0x0782f8(a0, a1);
        case 454: return fde_func_0454_0x0783c4(a0, a1);
        case 455: return fde_func_0455_0x078428(a0, a1);
        case 456: return fde_func_0456_0x078468(a0, a1);
        case 457: return fde_func_0457_0x0784a8(a0, a1);
        case 458: return fde_func_0458_0x078a58(a0, a1);
        case 459: return fde_func_0459_0x078c6c(a0, a1);
        case 460: return fde_func_0460_0x078cd0(a0, a1);
        case 461: return fde_func_0461_0x078dd4(a0, a1);
        case 462: return fde_func_0462_0x078f14(a0, a1);
        case 463: return fde_func_0463_0x079278(a0, a1);
        case 464: return fde_func_0464_0x079320(a0, a1);
        case 465: return fde_func_0465_0x0793b8(a0, a1);
        case 466: return fde_func_0466_0x0795f4(a0, a1);
        case 467: return fde_func_0467_0x07963c(a0, a1);
        case 468: return fde_func_0468_0x07973c(a0, a1);
        case 469: return fde_func_0469_0x07995c(a0, a1);
        case 470: return fde_func_0470_0x079ee8(a0, a1);
        case 471: return fde_func_0471_0x079ff4(a0, a1);
        case 472: return fde_func_0472_0x07a028(a0, a1);
        case 473: return fde_func_0473_0x07a1a8(a0, a1);
        case 474: return fde_func_0474_0x07a1c8(a0, a1);
        case 475: return fde_func_0475_0x07a23c(a0, a1);
        case 476: return fde_func_0476_0x07a360(a0, a1);
        case 477: return fde_func_0477_0x07a3b8(a0, a1);
        case 478: return fde_func_0478_0x07a424(a0, a1);
        case 479: return fde_func_0479_0x07ab18(a0, a1);
        case 480: return fde_func_0480_0x07ab58(a0, a1);
        case 481: return fde_func_0481_0x07acf4(a0, a1);
        case 482: return fde_func_0482_0x07af64(a0, a1);
        case 483: return fde_func_0483_0x07b040(a0, a1);
        case 484: return fde_func_0484_0x07b04c(a0, a1);
        case 485: return fde_func_0485_0x07b058(a0, a1);
        case 486: return fde_func_0486_0x07b064(a0, a1);
        case 487: return fde_func_0487_0x07b080(a0, a1);
        case 488: return fde_func_0488_0x07b134(a0, a1);
        case 489: return fde_func_0489_0x07b238(a0, a1);
        case 490: return fde_func_0490_0x07b2f4(a0, a1);
        case 491: return fde_func_0491_0x07b36c(a0, a1);
        case 492: return fde_func_0492_0x07b3e4(a0, a1);
        case 493: return fde_func_0493_0x07b438(a0, a1);
        case 494: return fde_func_0494_0x07b484(a0, a1);
        case 495: return fde_func_0495_0x07b524(a0, a1);
        case 496: return fde_func_0496_0x07b664(a0, a1);
        case 497: return fde_func_0497_0x07b78c(a0, a1);
        case 498: return fde_func_0498_0x07b7e8(a0, a1);
        case 499: return fde_func_0499_0x07ba64(a0, a1);
        case 500: return fde_func_0500_0x07be78(a0, a1);
        case 501: return fde_func_0501_0x07c03c(a0, a1);
        case 502: return fde_func_0502_0x07c200(a0, a1);
        case 503: return fde_func_0503_0x07c3e0(a0, a1);
        case 504: return fde_func_0504_0x07c854(a0, a1);
        case 505: return fde_func_0505_0x07c8dc(a0, a1);
        case 506: return fde_func_0506_0x07c970(a0, a1);
        case 507: return fde_func_0507_0x07ca74(a0, a1);
        case 508: return fde_func_0508_0x07ca98(a0, a1);
        case 509: return fde_func_0509_0x07cd04(a0, a1);
        case 510: return fde_func_0510_0x07cd84(a0, a1);
        case 511: return fde_func_0511_0x07cd94(a0, a1);
        case 512: return fde_func_0512_0x07ce6c(a0, a1);
        case 513: return fde_func_0513_0x07d0c4(a0, a1);
        case 514: return fde_func_0514_0x07d14c(a0, a1);
        case 515: return fde_func_0515_0x07d188(a0, a1);
        case 516: return fde_func_0516_0x07d1bc(a0, a1);
        case 517: return fde_func_0517_0x07d2f0(a0, a1);
        case 518: return fde_func_0518_0x07d3bc(a0, a1);
        case 519: return fde_func_0519_0x07d510(a0, a1);
        case 520: return fde_func_0520_0x07d54c(a0, a1);
        case 521: return fde_func_0521_0x07d630(a0, a1);
        case 522: return fde_func_0522_0x07d6e4(a0, a1);
        case 523: return fde_func_0523_0x07d720(a0, a1);
        case 524: return fde_func_0524_0x07d830(a0, a1);
        case 525: return fde_func_0525_0x07d93c(a0, a1);
        case 526: return fde_func_0526_0x07d978(a0, a1);
        case 527: return fde_func_0527_0x07db28(a0, a1);
        case 528: return fde_func_0528_0x07dc04(a0, a1);
        case 529: return fde_func_0529_0x07dd50(a0, a1);
        case 530: return fde_func_0530_0x07de58(a0, a1);
        case 531: return fde_func_0531_0x07dfa8(a0, a1);
        case 532: return fde_func_0532_0x07e064(a0, a1);
        case 533: return fde_func_0533_0x07e124(a0, a1);
        case 534: return fde_func_0534_0x07e230(a0, a1);
        case 535: return fde_func_0535_0x07e338(a0, a1);
        case 536: return fde_func_0536_0x07e408(a0, a1);
        case 537: return fde_func_0537_0x07e48c(a0, a1);
        case 538: return fde_func_0538_0x07e510(a0, a1);
        case 539: return fde_func_0539_0x07e594(a0, a1);
        case 540: return fde_func_0540_0x07e624(a0, a1);
        case 541: return fde_func_0541_0x07e638(a0, a1);
        case 542: return fde_func_0542_0x07e6b0(a0, a1);
        case 543: return fde_func_0543_0x07e75c(a0, a1);
        case 544: return fde_func_0544_0x07e77c(a0, a1);
        case 545: return fde_func_0545_0x07e7c0(a0, a1);
        case 546: return fde_func_0546_0x07e838(a0, a1);
        case 547: return fde_func_0547_0x07e890(a0, a1);
        case 548: return fde_func_0548_0x07e920(a0, a1);
        case 549: return fde_func_0549_0x07e970(a0, a1);
        case 550: return fde_func_0550_0x07e9a8(a0, a1);
        case 551: return fde_func_0551_0x07e9b8(a0, a1);
        case 552: return fde_func_0552_0x07e9c0(a0, a1);
        case 553: return fde_func_0553_0x07e9f4(a0, a1);
        case 554: return fde_func_0554_0x07e9fc(a0, a1);
        case 555: return fde_func_0555_0x07ea04(a0, a1);
        case 556: return fde_func_0556_0x07eae8(a0, a1);
        case 557: return fde_func_0557_0x07ebc4(a0, a1);
        case 558: return fde_func_0558_0x07ec58(a0, a1);
        case 559: return fde_func_0559_0x07ec90(a0, a1);
        case 560: return fde_func_0560_0x07edac(a0, a1);
        case 561: return fde_func_0561_0x07ef10(a0, a1);
        case 562: return fde_func_0562_0x07f1dc(a0, a1);
        case 563: return fde_func_0563_0x07f1f4(a0, a1);
        case 564: return fde_func_0564_0x07f230(a0, a1);
        case 565: return fde_func_0565_0x07f240(a0, a1);
        case 566: return fde_func_0566_0x07f348(a0, a1);
        case 567: return fde_func_0567_0x07f358(a0, a1);
        case 568: return fde_func_0568_0x07f380(a0, a1);
        case 569: return fde_func_0569_0x07f3a8(a0, a1);
        case 570: return fde_func_0570_0x07f3b8(a0, a1);
        case 571: return fde_func_0571_0x07f3c8(a0, a1);
        case 572: return fde_func_0572_0x07f4fc(a0, a1);
        case 573: return fde_func_0573_0x07f53c(a0, a1);
        case 574: return fde_func_0574_0x07f554(a0, a1);
        case 575: return fde_func_0575_0x07f564(a0, a1);
        case 576: return fde_func_0576_0x07f570(a0, a1);
        case 577: return fde_func_0577_0x07f584(a0, a1);
        case 578: return fde_func_0578_0x07f598(a0, a1);
        case 579: return fde_func_0579_0x07f610(a0, a1);
        case 580: return fde_func_0580_0x07f630(a0, a1);
        case 581: return fde_func_0581_0x07f650(a0, a1);
        case 582: return fde_func_0582_0x080474(a0, a1);
        case 583: return fde_func_0583_0x080818(a0, a1);
        case 584: return fde_func_0584_0x080ba4(a0, a1);
        case 585: return fde_func_0585_0x080bf0(a0, a1);
        case 586: return fde_func_0586_0x080c08(a0, a1);
        case 587: return fde_func_0587_0x080d50(a0, a1);
        case 588: return fde_func_0588_0x080d68(a0, a1);
        case 589: return fde_func_0589_0x080d98(a0, a1);
        case 590: return fde_func_0590_0x080db0(a0, a1);
        case 591: return fde_func_0591_0x080dd8(a0, a1);
        case 592: return fde_func_0592_0x080de0(a0, a1);
        case 593: return fde_func_0593_0x080e50(a0, a1);
        case 594: return fde_func_0594_0x080ec0(a0, a1);
        case 595: return fde_func_0595_0x080f30(a0, a1);
        case 596: return fde_func_0596_0x080fa0(a0, a1);
        case 597: return fde_func_0597_0x081010(a0, a1);
        case 598: return fde_func_0598_0x0810bc(a0, a1);
        case 599: return fde_func_0599_0x081164(a0, a1);
        case 600: return fde_func_0600_0x081210(a0, a1);
        case 601: return fde_func_0601_0x08121c(a0, a1);
        case 602: return fde_func_0602_0x081228(a0, a1);
        case 603: return fde_func_0603_0x081234(a0, a1);
        case 604: return fde_func_0604_0x0812e0(a0, a1);
        case 605: return fde_func_0605_0x081388(a0, a1);
        case 606: return fde_func_0606_0x081434(a0, a1);
        case 607: return fde_func_0607_0x081440(a0, a1);
        case 608: return fde_func_0608_0x08144c(a0, a1);
        case 609: return fde_func_0609_0x081458(a0, a1);
        case 610: return fde_func_0610_0x0814c8(a0, a1);
        case 611: return fde_func_0611_0x081538(a0, a1);
        case 612: return fde_func_0612_0x0815a8(a0, a1);
        case 613: return fde_func_0613_0x081600(a0, a1);
        case 614: return fde_func_0614_0x081658(a0, a1);
        case 615: return fde_func_0615_0x0816b0(a0, a1);
        case 616: return fde_func_0616_0x0816e4(a0, a1);
        case 617: return fde_func_0617_0x081718(a0, a1);
        case 618: return fde_func_0618_0x081748(a0, a1);
        case 619: return fde_func_0619_0x081774(a0, a1);
        case 620: return fde_func_0620_0x085404(a0, a1);
        case 621: return fde_func_0621_0x085d3c(a0, a1);
        case 622: return fde_func_0622_0x085da4(a0, a1);
        case 623: return fde_func_0623_0x088b98(a0, a1);
        case 624: return fde_func_0624_0x088ebc(a0, a1);
        case 625: return fde_func_0625_0x089848(a0, a1);
        case 626: return fde_func_0626_0x089d88(a0, a1);
        case 627: return fde_func_0627_0x08a0a4(a0, a1);
        case 628: return fde_func_0628_0x08a0f8(a0, a1);
        case 629: return fde_func_0629_0x08a22c(a0, a1);
        case 630: return fde_func_0630_0x08a6c0(a0, a1);
        case 631: return fde_func_0631_0x08a77c(a0, a1);
        case 632: return fde_func_0632_0x08a808(a0, a1);
        case 633: return fde_func_0633_0x08aa3c(a0, a1);
        case 634: return fde_func_0634_0x08ac68(a0, a1);
        case 635: return fde_func_0635_0x08ad2c(a0, a1);
        case 636: return fde_func_0636_0x08ad8c(a0, a1);
        case 637: return fde_func_0637_0x08afa4(a0, a1);
        case 638: return fde_func_0638_0x08c8f8(a0, a1);
        case 639: return fde_func_0639_0x08c9cc(a0, a1);
        case 640: return fde_func_0640_0x08ccac(a0, a1);
        case 641: return fde_func_0641_0x08ce4c(a0, a1);
        case 642: return fde_func_0642_0x08ced8(a0, a1);
        case 643: return fde_func_0643_0x08d0a0(a0, a1);
        case 644: return fde_func_0644_0x08d0d8(a0, a1);
        case 645: return fde_func_0645_0x08d1c0(a0, a1);
        case 646: return fde_func_0646_0x08d224(a0, a1);
        case 647: return fde_func_0647_0x08d2a0(a0, a1);
        case 648: return fde_func_0648_0x08d364(a0, a1);
        case 649: return fde_func_0649_0x08d5a4(a0, a1);
        case 650: return fde_func_0650_0x08d5b0(a0, a1);
        case 651: return fde_func_0651_0x08d5bc(a0, a1);
        case 652: return fde_func_0652_0x08d7ec(a0, a1);
        case 653: return fde_func_0653_0x08d894(a0, a1);
        case 654: return fde_func_0654_0x08dba8(a0, a1);
        case 655: return fde_func_0655_0x08e2cc(a0, a1);
        case 656: return fde_func_0656_0x08e2f4(a0, a1);
        case 657: return fde_func_0657_0x08e338(a0, a1);
        case 658: return fde_func_0658_0x08e374(a0, a1);
        case 659: return fde_func_0659_0x08e3b0(a0, a1);
        case 660: return fde_func_0660_0x08e3f8(a0, a1);
        case 661: return fde_func_0661_0x08e5fc(a0, a1);
        case 662: return fde_func_0662_0x08e818(a0, a1);
        case 663: return fde_func_0663_0x08ea8c(a0, a1);
        case 664: return fde_func_0664_0x08eb38(a0, a1);
        case 665: return fde_func_0665_0x08ec5c(a0, a1);
        case 666: return fde_func_0666_0x091a0c(a0, a1);
        case 667: return fde_func_0667_0x091e7c(a0, a1);
        case 668: return fde_func_0668_0x092038(a0, a1);
        case 669: return fde_func_0669_0x0920a0(a0, a1);
        case 670: return fde_func_0670_0x092124(a0, a1);
        case 671: return fde_func_0671_0x09216c(a0, a1);
        case 672: return fde_func_0672_0x0921b4(a0, a1);
        case 673: return fde_func_0673_0x092380(a0, a1);
        case 674: return fde_func_0674_0x0923a0(a0, a1);
        case 675: return fde_func_0675_0x0925d0(a0, a1);
        case 676: return fde_func_0676_0x092614(a0, a1);
        case 677: return fde_func_0677_0x092618(a0, a1);
        case 678: return fde_func_0678_0x092660(a0, a1);
        case 679: return fde_func_0679_0x092674(a0, a1);
        case 680: return fde_func_0680_0x09268c(a0, a1);
        case 681: return fde_func_0681_0x092fac(a0, a1);
        case 682: return fde_func_0682_0x0931bc(a0, a1);
        case 683: return fde_func_0683_0x0931c4(a0, a1);
        case 684: return fde_func_0684_0x093208(a0, a1);
        case 685: return fde_func_0685_0x09324c(a0, a1);
        case 686: return fde_func_0686_0x093290(a0, a1);
        case 687: return fde_func_0687_0x0932d4(a0, a1);
        case 688: return fde_func_0688_0x09338c(a0, a1);
        case 689: return fde_func_0689_0x0933d0(a0, a1);
        case 690: return fde_func_0690_0x093488(a0, a1);
        case 691: return fde_func_0691_0x0934cc(a0, a1);
        case 692: return fde_func_0692_0x093584(a0, a1);
        case 693: return fde_func_0693_0x0935c8(a0, a1);
        case 694: return fde_func_0694_0x094050(a0, a1);
        case 695: return fde_func_0695_0x0942f4(a0, a1);
        case 696: return fde_func_0696_0x095010(a0, a1);
        case 697: return fde_func_0697_0x095064(a0, a1);
        case 698: return fde_func_0698_0x0950d4(a0, a1);
        case 699: return fde_func_0699_0x0951dc(a0, a1);
        case 700: return fde_func_0700_0x09536c(a0, a1);
        case 701: return fde_func_0701_0x09570c(a0, a1);
        case 702: return fde_func_0702_0x095b88(a0, a1);
        case 703: return fde_func_0703_0x095bc8(a0, a1);
        case 704: return fde_func_0704_0x095c08(a0, a1);
        case 705: return fde_func_0705_0x095c50(a0, a1);
        case 706: return fde_func_0706_0x095d2c(a0, a1);
        case 707: return fde_func_0707_0x095d68(a0, a1);
        case 708: return fde_func_0708_0x095de0(a0, a1);
        case 709: return fde_func_0709_0x095ea4(a0, a1);
        case 710: return fde_func_0710_0x095fd8(a0, a1);
        case 711: return fde_func_0711_0x0960bc(a0, a1);
        case 712: return fde_func_0712_0x096258(a0, a1);
        case 713: return fde_func_0713_0x0967fc(a0, a1);
        case 714: return fde_func_0714_0x096b94(a0, a1);
        case 715: return fde_func_0715_0x0975c4(a0, a1);
        case 716: return fde_func_0716_0x097644(a0, a1);
        case 717: return fde_func_0717_0x09b1e0(a0, a1);
        case 718: return fde_func_0718_0x09b274(a0, a1);
        case 719: return fde_func_0719_0x09b338(a0, a1);
        case 720: return fde_func_0720_0x09b414(a0, a1);
        case 721: return fde_func_0721_0x09b4a0(a0, a1);
        case 722: return fde_func_0722_0x09b52c(a0, a1);
        case 723: return fde_func_0723_0x09b5b8(a0, a1);
        case 724: return fde_func_0724_0x09b71c(a0, a1);
        case 725: return fde_func_0725_0x09b838(a0, a1);
        case 726: return fde_func_0726_0x09b880(a0, a1);
        case 727: return fde_func_0727_0x09b8cc(a0, a1);
        case 728: return fde_func_0728_0x09b9c0(a0, a1);
        case 729: return fde_func_0729_0x09ba88(a0, a1);
        case 730: return fde_func_0730_0x09bb50(a0, a1);
        case 731: return fde_func_0731_0x09bc60(a0, a1);
        case 732: return fde_func_0732_0x09bc78(a0, a1);
        case 733: return fde_func_0733_0x09bd08(a0, a1);
        case 734: return fde_func_0734_0x09bef0(a0, a1);
        case 735: return fde_func_0735_0x09c094(a0, a1);
        case 736: return fde_func_0736_0x09c098(a0, a1);
        case 737: return fde_func_0737_0x09c0ec(a0, a1);
        case 738: return fde_func_0738_0x09c1a4(a0, a1);
        case 739: return fde_func_0739_0x09c25c(a0, a1);
        case 740: return fde_func_0740_0x09c358(a0, a1);
        case 741: return fde_func_0741_0x09c3f8(a0, a1);
        case 742: return fde_func_0742_0x09c508(a0, a1);
        case 743: return fde_func_0743_0x09c624(a0, a1);
        case 744: return fde_func_0744_0x09c6ac(a0, a1);
        case 745: return fde_func_0745_0x09c734(a0, a1);
        case 746: return fde_func_0746_0x09c7a8(a0, a1);
        case 747: return fde_func_0747_0x09c81c(a0, a1);
        case 748: return fde_func_0748_0x09c890(a0, a1);
        case 749: return fde_func_0749_0x09d658(a0, a1);
        case 750: return fde_func_0750_0x09d694(a0, a1);
        case 751: return fde_func_0751_0x09d700(a0, a1);
        case 752: return fde_func_0752_0x09dfa4(a0, a1);
        case 753: return fde_func_0753_0x09e08c(a0, a1);
        case 754: return fde_func_0754_0x09e1a4(a0, a1);
        case 755: return fde_func_0755_0x09e450(a0, a1);
        case 756: return fde_func_0756_0x09e540(a0, a1);
        case 757: return fde_func_0757_0x09e734(a0, a1);
        case 758: return fde_func_0758_0x09e8c8(a0, a1);
        case 759: return fde_func_0759_0x09f294(a0, a1);
        case 760: return fde_func_0760_0x09fd80(a0, a1);
        case 761: return fde_func_0761_0x09fe1c(a0, a1);
        case 762: return fde_func_0762_0x09fe94(a0, a1);
        case 763: return fde_func_0763_0x09fed4(a0, a1);
        case 764: return fde_func_0764_0x0a3b6c(a0, a1);
        case 765: return fde_func_0765_0x0a3bcc(a0, a1);
        case 766: return fde_func_0766_0x0a3bd0(a0, a1);
        case 767: return fde_func_0767_0x0a3c18(a0, a1);
        case 768: return fde_func_0768_0x0a3fb4(a0, a1);
        case 769: return fde_func_0769_0x0a4098(a0, a1);
        case 770: return fde_func_0770_0x0a4464(a0, a1);
        case 771: return fde_func_0771_0x0a466c(a0, a1);
        case 772: return fde_func_0772_0x0a4884(a0, a1);
        case 773: return fde_func_0773_0x0a491c(a0, a1);
        case 774: return fde_func_0774_0x0a4924(a0, a1);
        case 775: return fde_func_0775_0x0a4a7c(a0, a1);
        case 776: return fde_func_0776_0x0a4c5c(a0, a1);
        case 777: return fde_func_0777_0x0a4d54(a0, a1);
        case 778: return fde_func_0778_0x0a4e68(a0, a1);
        case 779: return fde_func_0779_0x0a4ee8(a0, a1);
        case 780: return fde_func_0780_0x0a4fb8(a0, a1);
        case 781: return fde_func_0781_0x0a4ff8(a0, a1);
        case 782: return fde_func_0782_0x0a5058(a0, a1);
        case 783: return fde_func_0783_0x0a5150(a0, a1);
        case 784: return fde_func_0784_0x0a56cc(a0, a1);
        case 785: return fde_func_0785_0x0a5d64(a0, a1);
        case 786: return fde_func_0786_0x0a5dc4(a0, a1);
        case 787: return fde_func_0787_0x0a5e2c(a0, a1);
        case 788: return fde_func_0788_0x0a6370(a0, a1);
        case 789: return fde_func_0789_0x0a6548(a0, a1);
        case 790: return fde_func_0790_0x0a6734(a0, a1);
        case 791: return fde_func_0791_0x0a6870(a0, a1);
        case 792: return fde_func_0792_0x0a6a8c(a0, a1);
        case 793: return fde_func_0793_0x0a6b38(a0, a1);
        case 794: return fde_func_0794_0x0a6e48(a0, a1);
        case 795: return fde_func_0795_0x0a7088(a0, a1);
        case 796: return fde_func_0796_0x0a749c(a0, a1);
        case 797: return fde_func_0797_0x0a79a0(a0, a1);
        case 798: return fde_func_0798_0x0a79ac(a0, a1);
        case 799: return fde_func_0799_0x0a79b0(a0, a1);
        default: return 0ULL;
    }
}