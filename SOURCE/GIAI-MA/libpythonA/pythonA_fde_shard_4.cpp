// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 4/5 for libpythonA.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 4/5 cho libpythonA.so
// Covers representative FDE indices [1200 .. 1599] out of 4,320 total FDEs
// Bao phủ chỉ số FDE đại diện [1200 .. 1599] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_core.h"

// FDE #1200 | PC: 0x0fe6d4 | FDE: 0x1e44e8 | Size: 256 bytes [PyWeakref_NewRef]
// Khung tháo gỡ #1200 | Địa chỉ PC: 0x0fe6d4 | Địa chỉ FDE: 0x1e44e8 | Kích thước: 256 bytes
//   0x0fe6d4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0fe6d8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fe6dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fe6e0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1200_0x0fe6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe6d4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e44e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1201 | PC: 0x0fe8d0 | FDE: 0x1e4510 | Size: 256 bytes [PyWeakref_NewProxy]
// Khung tháo gỡ #1201 | Địa chỉ PC: 0x0fe8d0 | Địa chỉ FDE: 0x1e4510 | Kích thước: 256 bytes
//   0x0fe8d0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0fe8d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0fe8d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fe8dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1201_0x0fe8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe8d0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1202 | PC: 0x0feb0c | FDE: 0x1e4540 | Size: 152 bytes [PyWeakref_GetObject]
// Khung tháo gỡ #1202 | Địa chỉ PC: 0x0feb0c | Địa chỉ FDE: 0x1e4540 | Kích thước: 152 bytes
//   0x0feb0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0feb10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0feb14: 910043FD  add      x29, sp, #0x10
//   0x0feb18: B4000360  cbz      x0, #0xfeb84
static inline uint64_t fde_func_1202_0x0feb0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feb0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4540ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1203 | PC: 0x0feba4 | FDE: 0x1e4560 | Size: 256 bytes [PyObject_ClearWeakRefs]
// Khung tháo gỡ #1203 | Địa chỉ PC: 0x0feba4 | Địa chỉ FDE: 0x1e4560 | Kích thước: 256 bytes
//   0x0feba4: D101C3FF  sub      sp, sp, #0x70
//   0x0feba8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0febac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0febb0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1203_0x0feba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feba4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1e4560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1204 | PC: 0x101800 | FDE: 0x1e4ae8 | Size: 256 bytes [_PyWarnings_InitState]
// Khung tháo gỡ #1204 | Địa chỉ PC: 0x101800 | Địa chỉ FDE: 0x1e4ae8 | Kích thước: 256 bytes
//   0x101800: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x101804: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x101808: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10180c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1204_0x101800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101800ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1205 | PC: 0x101b88 | FDE: 0x1e4b10 | Size: 256 bytes [PyErr_WarnFormat]
// Khung tháo gỡ #1205 | Địa chỉ PC: 0x101b88 | Địa chỉ FDE: 0x1e4b10 | Kích thước: 256 bytes
//   0x101b88: D10503FF  sub      sp, sp, #0x140
//   0x101b8c: F90083FC  str      x28, [sp, #0x100]
//   0x101b90: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x101b94: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1205_0x101b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101b88ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1e4b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1206 | PC: 0x101ca4 | FDE: 0x1e4b38 | Size: 256 bytes [PyErr_ResourceWarning]
// Khung tháo gỡ #1206 | Địa chỉ PC: 0x101ca4 | Địa chỉ FDE: 0x1e4b38 | Kích thước: 256 bytes
//   0x101ca4: D10503FF  sub      sp, sp, #0x140
//   0x101ca8: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x101cac: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x101cb0: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1206_0x101ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101ca4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x1e4b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1207 | PC: 0x101dcc | FDE: 0x1e4b60 | Size: 160 bytes [PyErr_WarnEx]
// Khung tháo gỡ #1207 | Địa chỉ PC: 0x101dcc | Địa chỉ FDE: 0x1e4b60 | Kích thước: 160 bytes
//   0x101dcc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x101dd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x101dd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x101dd8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1207_0x101dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101dccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4b60ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1208 | PC: 0x101e6c | FDE: 0x1e4b80 | Size: 148 bytes [PyErr_Warn]
// Khung tháo gỡ #1208 | Địa chỉ PC: 0x101e6c | Địa chỉ FDE: 0x1e4b80 | Kích thước: 148 bytes
//   0x101e6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x101e70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x101e74: 910043FD  add      x29, sp, #0x10
//   0x101e78: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1208_0x101e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101e6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4b80ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1209 | PC: 0x101f00 | FDE: 0x1e4ba0 | Size: 256 bytes [PyErr_WarnExplicitObject]
// Khung tháo gỡ #1209 | Địa chỉ PC: 0x101f00 | Địa chỉ FDE: 0x1e4ba0 | Kích thước: 256 bytes
//   0x101f00: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x101f04: 910003FD  mov      x29, sp
//   0x101f08: D00007E8  adrp     x8, #0x1ff000
//   0x101f0c: F9472908  ldr      x8, [x8, #0xe50]
static inline uint64_t fde_func_1209_0x101f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101f00ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e4ba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1210 | PC: 0x102d10 | FDE: 0x1e4bf0 | Size: 256 bytes [PyErr_WarnExplicit]
// Khung tháo gỡ #1210 | Địa chỉ PC: 0x102d10 | Địa chỉ FDE: 0x1e4bf0 | Kích thước: 256 bytes
//   0x102d10: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x102d14: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x102d18: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x102d1c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1210_0x102d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102d10ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e4bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1211 | PC: 0x102e5c | FDE: 0x1e4c20 | Size: 256 bytes [PyErr_WarnExplicitFormat]
// Khung tháo gỡ #1211 | Địa chỉ PC: 0x102e5c | Địa chỉ FDE: 0x1e4c20 | Kích thước: 256 bytes
//   0x102e5c: D104C3FF  sub      sp, sp, #0x130
//   0x102e60: A90E67FC  stp      x28, x25, [sp, #0xe0]
//   0x102e64: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x102e68: A91057F6  stp      x22, x21, [sp, #0x100]
static inline uint64_t fde_func_1211_0x102e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102e5cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90e67fcULL) ^ 0x1e4c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1212 | PC: 0x102ffc | FDE: 0x1e4c50 | Size: 256 bytes [_PyErr_WarnUnawaitedCoroutine]
// Khung tháo gỡ #1212 | Địa chỉ PC: 0x102ffc | Địa chỉ FDE: 0x1e4c50 | Kích thước: 256 bytes
//   0x102ffc: D10183FF  sub      sp, sp, #0x60
//   0x103000: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x103004: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x103008: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1212_0x102ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102ffcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e4c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1213 | PC: 0x103384 | FDE: 0x1e4cc8 | Size: 12 bytes [_PyWarnings_Init]
// Khung tháo gỡ #1213 | Địa chỉ PC: 0x103384 | Địa chỉ FDE: 0x1e4cc8 | Kích thước: 12 bytes
//   0x103384: F0000880  adrp     x0, #0x216000
//   0x103388: 910BE000  add      x0, x0, #0x2f8
//   0x10338c: 17FD55A5  b        #0x58a20
static inline uint64_t fde_func_1213_0x103384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103384ULL ^ (static_cast<uint64_t>(0xf0000880ULL) << 13);
    acc = (acc + a1 + 0x910be000ULL) ^ 0x1e4cc8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1214 | PC: 0x103390 | FDE: 0x1e4ce0 | Size: 256 bytes [_PyWarnings_Fini]
// Khung tháo gỡ #1214 | Địa chỉ PC: 0x103390 | Địa chỉ FDE: 0x1e4ce0 | Kích thước: 256 bytes
//   0x103390: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x103394: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x103398: 910043FD  add      x29, sp, #0x10
//   0x10339c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1214_0x103390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103390ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e4ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1215 | PC: 0x1040dc | FDE: 0x1e4e38 | Size: 152 bytes [_Py_asdl_generic_seq_new]
// Khung tháo gỡ #1215 | Địa chỉ PC: 0x1040dc | Địa chỉ FDE: 0x1e4e38 | Kích thước: 152 bytes
//   0x1040dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1040e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1040e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1040e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1215_0x1040dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1040dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4e38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1216 | PC: 0x104174 | FDE: 0x1e4e58 | Size: 152 bytes [_Py_asdl_identifier_seq_new]
// Khung tháo gỡ #1216 | Địa chỉ PC: 0x104174 | Địa chỉ FDE: 0x1e4e58 | Kích thước: 152 bytes
//   0x104174: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104178: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10417c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104180: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1216_0x104174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104174ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4e58ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1217 | PC: 0x10420c | FDE: 0x1e4e78 | Size: 152 bytes [_Py_asdl_int_seq_new]
// Khung tháo gỡ #1217 | Địa chỉ PC: 0x10420c | Địa chỉ FDE: 0x1e4e78 | Kích thước: 152 bytes
//   0x10420c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104210: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104214: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104218: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1217_0x10420c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10420cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4e78ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1218 | PC: 0x1042a4 | FDE: 0x1e4e98 | Size: 184 bytes [BDPythonVMDispatchCreateSubInterpreters]
// Khung tháo gỡ #1218 | Địa chỉ PC: 0x1042a4 | Địa chỉ FDE: 0x1e4e98 | Kích thước: 184 bytes
//   0x1042a4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1042a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1042ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1042b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1218_0x1042a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1042a4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e4e98ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1219 | PC: 0x10435c | FDE: 0x1e4ec0 | Size: 256 bytes [BDPythonVMDispatchGetInterperter]
// Khung tháo gỡ #1219 | Địa chỉ PC: 0x10435c | Địa chỉ FDE: 0x1e4ec0 | Kích thước: 256 bytes
//   0x10435c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104360: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104364: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104368: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1219_0x10435c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10435cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e4ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1220 | PC: 0x1051f8 | FDE: 0x1e50d8 | Size: 16 bytes [BDPythonVM_get_cprofile_dump_path]
// Khung tháo gỡ #1220 | Địa chỉ PC: 0x1051f8 | Địa chỉ FDE: 0x1e50d8 | Kích thước: 16 bytes
//   0x1051f8: D00007C8  adrp     x8, #0x1ff000
//   0x1051fc: F947F908  ldr      x8, [x8, #0xff0]
//   0x105200: F9400100  ldr      x0, [x8]
//   0x105204: 17FD5CAF  b        #0x5c4c0
static inline uint64_t fde_func_1220_0x1051f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1051f8ULL ^ (static_cast<uint64_t>(0xd00007c8ULL) << 13);
    acc = (acc + a1 + 0xf947f908ULL) ^ 0x1e50d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1221 | PC: 0x105208 | FDE: 0x1e50f0 | Size: 228 bytes [BDPythonVM_dump_stats_to_default_path]
// Khung tháo gỡ #1221 | Địa chỉ PC: 0x105208 | Địa chỉ FDE: 0x1e50f0 | Kích thước: 228 bytes
//   0x105208: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10520c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x105210: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105214: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1221_0x105208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105208ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e50f0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1222 | PC: 0x1052ec | FDE: 0x1e5110 | Size: 24 bytes [bd_empty_func]
// Khung tháo gỡ #1222 | Địa chỉ PC: 0x1052ec | Địa chỉ FDE: 0x1e5110 | Kích thước: 24 bytes
//   0x1052ec: D00007C0  adrp     x0, #0x1ff000
//   0x1052f0: F945F000  ldr      x0, [x0, #0xbe0]
//   0x1052f4: F9400008  ldr      x8, [x0]
//   0x1052f8: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_1222_0x1052ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1052ecULL ^ (static_cast<uint64_t>(0xd00007c0ULL) << 13);
    acc = (acc + a1 + 0xf945f000ULL) ^ 0x1e5110ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1223 | PC: 0x105304 | FDE: 0x1e5128 | Size: 256 bytes [_PyBuiltin_Init]
// Khung tháo gỡ #1223 | Địa chỉ PC: 0x105304 | Địa chỉ FDE: 0x1e5128 | Kích thước: 256 bytes
//   0x105304: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x105308: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10530c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105310: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1223_0x105304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105304ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1224 | PC: 0x108e10 | FDE: 0x1e57a0 | Size: 256 bytes [PyCodec_Register]
// Khung tháo gỡ #1224 | Địa chỉ PC: 0x108e10 | Địa chỉ FDE: 0x1e57a0 | Kích thước: 256 bytes
//   0x108e10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x108e14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x108e18: 910043FD  add      x29, sp, #0x10
//   0x108e1c: F00007A8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1224_0x108e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108e10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e57a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1225 | PC: 0x109018 | FDE: 0x1e57f0 | Size: 140 bytes [PyCodec_Unregister]
// Khung tháo gỡ #1225 | Địa chỉ PC: 0x109018 | Địa chỉ FDE: 0x1e57f0 | Kích thước: 140 bytes
//   0x109018: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10901c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109024: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1225_0x109018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109018ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e57f0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1226 | PC: 0x1090a4 | FDE: 0x1e5810 | Size: 256 bytes [_PyCodec_Lookup]
// Khung tháo gỡ #1226 | Địa chỉ PC: 0x1090a4 | Địa chỉ FDE: 0x1e5810 | Kích thước: 256 bytes
//   0x1090a4: D10203FF  sub      sp, sp, #0x80
//   0x1090a8: F90013FB  str      x27, [sp, #0x20]
//   0x1090ac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1090b0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1226_0x1090a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1090a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e5810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1227 | PC: 0x1093e8 | FDE: 0x1e5840 | Size: 64 bytes [PyCodec_KnownEncoding]
// Khung tháo gỡ #1227 | Địa chỉ PC: 0x1093e8 | Địa chỉ FDE: 0x1e5840 | Kích thước: 64 bytes
//   0x1093e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1093ec: 910003FD  mov      x29, sp
//   0x1093f0: 97FD3DA8  bl       #0x58a90
//   0x1093f4: B4000120  cbz      x0, #0x109418
static inline uint64_t fde_func_1227_0x1093e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1093e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5840ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1228 | PC: 0x109428 | FDE: 0x1e5860 | Size: 224 bytes [_PyCodecInfo_GetIncrementalDecoder]
// Khung tháo gỡ #1228 | Địa chỉ PC: 0x109428 | Địa chỉ FDE: 0x1e5860 | Kích thước: 224 bytes
//   0x109428: D0000562  adrp     x2, #0x1b7000
//   0x10942c: 910ADC42  add      x2, x2, #0x2b7
//   0x109430: 14000001  b        #0x109434
//   0x109434: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_1228_0x109428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109428ULL ^ (static_cast<uint64_t>(0xd0000562ULL) << 13);
    acc = (acc + a1 + 0x910adc42ULL) ^ 0x1e5860ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1229 | PC: 0x109508 | FDE: 0x1e5898 | Size: 12 bytes [_PyCodecInfo_GetIncrementalEncoder]
// Khung tháo gỡ #1229 | Địa chỉ PC: 0x109508 | Địa chỉ FDE: 0x1e5898 | Kích thước: 12 bytes
//   0x109508: D0000562  adrp     x2, #0x1b7000
//   0x10950c: 910B2842  add      x2, x2, #0x2ca
//   0x109510: 17FFFFC9  b        #0x109434
static inline uint64_t fde_func_1229_0x109508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109508ULL ^ (static_cast<uint64_t>(0xd0000562ULL) << 13);
    acc = (acc + a1 + 0x910b2842ULL) ^ 0x1e5898ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1230 | PC: 0x109514 | FDE: 0x1e58b0 | Size: 80 bytes [PyCodec_Encoder]
// Khung tháo gỡ #1230 | Địa chỉ PC: 0x109514 | Địa chỉ FDE: 0x1e58b0 | Kích thước: 80 bytes
//   0x109514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x109518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10951c: 910043FD  add      x29, sp, #0x10
//   0x109520: 97FD3D5C  bl       #0x58a90
static inline uint64_t fde_func_1230_0x109514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109514ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e58b0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1231 | PC: 0x109564 | FDE: 0x1e58d0 | Size: 80 bytes [PyCodec_Decoder]
// Khung tháo gỡ #1231 | Địa chỉ PC: 0x109564 | Địa chỉ FDE: 0x1e58d0 | Kích thước: 80 bytes
//   0x109564: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x109568: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10956c: 910043FD  add      x29, sp, #0x10
//   0x109570: 97FD3D48  bl       #0x58a90
static inline uint64_t fde_func_1231_0x109564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109564ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e58d0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1232 | PC: 0x1095b4 | FDE: 0x1e58f0 | Size: 96 bytes [PyCodec_IncrementalEncoder]
// Khung tháo gỡ #1232 | Địa chỉ PC: 0x1095b4 | Địa chỉ FDE: 0x1e58f0 | Kích thước: 96 bytes
//   0x1095b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1095b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1095bc: 910043FD  add      x29, sp, #0x10
//   0x1095c0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1232_0x1095b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1095b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e58f0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1233 | PC: 0x109614 | FDE: 0x1e5910 | Size: 96 bytes [PyCodec_IncrementalDecoder]
// Khung tháo gỡ #1233 | Địa chỉ PC: 0x109614 | Địa chỉ FDE: 0x1e5910 | Kích thước: 96 bytes
//   0x109614: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x109618: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10961c: 910043FD  add      x29, sp, #0x10
//   0x109620: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1233_0x109614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109614ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5910ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1234 | PC: 0x109674 | FDE: 0x1e5930 | Size: 256 bytes [PyCodec_StreamReader]
// Khung tháo gỡ #1234 | Địa chỉ PC: 0x109674 | Địa chỉ FDE: 0x1e5930 | Kích thước: 256 bytes
//   0x109674: 52800043  mov      w3, #2
//   0x109678: 14000001  b        #0x10967c
//   0x10967c: D10183FF  sub      sp, sp, #0x60
//   0x109680: F90013F7  str      x23, [sp, #0x20]
static inline uint64_t fde_func_1234_0x109674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109674ULL ^ (static_cast<uint64_t>(0x52800043ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e5930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1235 | PC: 0x1097a4 | FDE: 0x1e5970 | Size: 8 bytes [PyCodec_StreamWriter]
// Khung tháo gỡ #1235 | Địa chỉ PC: 0x1097a4 | Địa chỉ FDE: 0x1e5970 | Kích thước: 8 bytes
//   0x1097a4: 52800063  mov      w3, #3
//   0x1097a8: 17FFFFB5  b        #0x10967c
static inline uint64_t fde_func_1235_0x1097a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1097a4ULL ^ (static_cast<uint64_t>(0x52800063ULL) << 13);
    acc = (acc + a1 + 0x17ffffb5ULL) ^ 0x1e5970ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1236 | PC: 0x1097ac | FDE: 0x1e5988 | Size: 256 bytes [PyCodec_Encode]
// Khung tháo gỡ #1236 | Địa chỉ PC: 0x1097ac | Địa chỉ FDE: 0x1e5988 | Kích thước: 256 bytes
//   0x1097ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1097b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1097b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1097b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1236_0x1097ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1097acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1237 | PC: 0x1099b8 | FDE: 0x1e59d8 | Size: 256 bytes [PyCodec_Decode]
// Khung tháo gỡ #1237 | Địa chỉ PC: 0x1099b8 | Địa chỉ FDE: 0x1e59d8 | Kích thước: 256 bytes
//   0x1099b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1099bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1099c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1099c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1237_0x1099b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1099b8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e59d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1238 | PC: 0x109bf8 | FDE: 0x1e5a28 | Size: 256 bytes [_PyCodec_LookupTextEncoding]
// Khung tháo gỡ #1238 | Địa chỉ PC: 0x109bf8 | Địa chỉ FDE: 0x1e5a28 | Kích thước: 256 bytes
//   0x109bf8: D10143FF  sub      sp, sp, #0x50
//   0x109bfc: F9000BF7  str      x23, [sp, #0x10]
//   0x109c00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x109c04: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1238_0x109bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109bf8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1e5a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1239 | PC: 0x109d18 | FDE: 0x1e5a50 | Size: 144 bytes [_PyCodec_EncodeText]
// Khung tháo gỡ #1239 | Địa chỉ PC: 0x109d18 | Địa chỉ FDE: 0x1e5a50 | Kích thước: 144 bytes
//   0x109d18: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x109d1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109d20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109d24: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1239_0x109d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109d18ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5a50ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1240 | PC: 0x109da8 | FDE: 0x1e5a78 | Size: 144 bytes [_PyCodec_DecodeText]
// Khung tháo gỡ #1240 | Địa chỉ PC: 0x109da8 | Địa chỉ FDE: 0x1e5a78 | Kích thước: 144 bytes
//   0x109da8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x109dac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109db0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109db4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1240_0x109da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109da8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5a78ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1241 | PC: 0x109e38 | FDE: 0x1e5aa0 | Size: 152 bytes [PyCodec_RegisterError]
// Khung tháo gỡ #1241 | Địa chỉ PC: 0x109e38 | Địa chỉ FDE: 0x1e5aa0 | Kích thước: 152 bytes
//   0x109e38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x109e3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109e40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109e44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1241_0x109e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109e38ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5aa0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1242 | PC: 0x109ed0 | FDE: 0x1e5ac0 | Size: 160 bytes [PyCodec_LookupError]
// Khung tháo gỡ #1242 | Địa chỉ PC: 0x109ed0 | Địa chỉ FDE: 0x1e5ac0 | Kích thước: 160 bytes
//   0x109ed0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x109ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x109ed8: 910043FD  add      x29, sp, #0x10
//   0x109edc: D00007A8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1242_0x109ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109ed0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5ac0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1243 | PC: 0x109f70 | FDE: 0x1e5ae0 | Size: 68 bytes [PyCodec_StrictErrors]
// Khung tháo gỡ #1243 | Địa chỉ PC: 0x109f70 | Địa chỉ FDE: 0x1e5ae0 | Kích thước: 68 bytes
//   0x109f70: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x109f74: 910003FD  mov      x29, sp
//   0x109f78: AA0003E1  mov      x1, x0
//   0x109f7c: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_1243_0x109f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109f70ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5ae0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1244 | PC: 0x109fb4 | FDE: 0x1e5b00 | Size: 256 bytes [PyCodec_IgnoreErrors]
// Khung tháo gỡ #1244 | Địa chỉ PC: 0x109fb4 | Địa chỉ FDE: 0x1e5b00 | Kích thước: 256 bytes
//   0x109fb4: D100C3FF  sub      sp, sp, #0x30
//   0x109fb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x109fbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x109fc0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1244_0x109fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109fb4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1245 | PC: 0x10a0dc | FDE: 0x1e5b20 | Size: 256 bytes [PyCodec_ReplaceErrors]
// Khung tháo gỡ #1245 | Địa chỉ PC: 0x10a0dc | Địa chỉ FDE: 0x1e5b20 | Kích thước: 256 bytes
//   0x10a0dc: D10143FF  sub      sp, sp, #0x50
//   0x10a0e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10a0e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10a0e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1245_0x10a0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a0dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e5b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1246 | PC: 0x10a33c | FDE: 0x1e5b48 | Size: 256 bytes [PyCodec_XMLCharRefReplaceErrors]
// Khung tháo gỡ #1246 | Địa chỉ PC: 0x10a33c | Địa chỉ FDE: 0x1e5b48 | Kích thước: 256 bytes
//   0x10a33c: D10143FF  sub      sp, sp, #0x50
//   0x10a340: F90013F5  str      x21, [sp, #0x20]
//   0x10a344: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10a348: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1246_0x10a33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a33cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e5b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1247 | PC: 0x10a6fc | FDE: 0x1e5b68 | Size: 256 bytes [PyCodec_BackslashReplaceErrors]
// Khung tháo gỡ #1247 | Địa chỉ PC: 0x10a6fc | Địa chỉ FDE: 0x1e5b68 | Kích thước: 256 bytes
//   0x10a6fc: D10143FF  sub      sp, sp, #0x50
//   0x10a700: F90013F5  str      x21, [sp, #0x20]
//   0x10a704: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10a708: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1247_0x10a6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a6fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e5b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1248 | PC: 0x10abb4 | FDE: 0x1e5b88 | Size: 256 bytes [PyCodec_NameReplaceErrors]
// Khung tháo gỡ #1248 | Địa chỉ PC: 0x10abb4 | Địa chỉ FDE: 0x1e5b88 | Kích thước: 256 bytes
//   0x10abb4: D10643FF  sub      sp, sp, #0x190
//   0x10abb8: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x10abbc: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x10abc0: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_1248_0x10abb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10abb4ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa9136ffcULL) ^ 0x1e5b88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1249 | PC: 0x10b910 | FDE: 0x1e5ca0 | Size: 256 bytes [_Py_Mangle]
// Khung tháo gỡ #1249 | Địa chỉ PC: 0x10b910 | Địa chỉ FDE: 0x1e5ca0 | Kích thước: 256 bytes
//   0x10b910: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x10b914: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10b918: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10b91c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1249_0x10b910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b910ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1250 | PC: 0x10be0c | FDE: 0x1e5cc8 | Size: 228 bytes [_PyErr_Restore]
// Khung tháo gỡ #1250 | Địa chỉ PC: 0x10be0c | Địa chỉ FDE: 0x1e5cc8 | Kích thước: 228 bytes
//   0x10be0c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10be10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10be14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10be18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1250_0x10be0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10be0cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5cc8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1251 | PC: 0x10bef0 | FDE: 0x1e5cf0 | Size: 60 bytes [PyErr_Restore]
// Khung tháo gỡ #1251 | Địa chỉ PC: 0x10bef0 | Địa chỉ FDE: 0x1e5cf0 | Kích thước: 60 bytes
//   0x10bef0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10bef4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10bef8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10befc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1251_0x10bef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bef0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5cf0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1252 | PC: 0x10bf2c | FDE: 0x1e5d10 | Size: 48 bytes [_PyErr_GetTopmostException]
// Khung tháo gỡ #1252 | Địa chỉ PC: 0x10bf2c | Địa chỉ FDE: 0x1e5d10 | Kích thước: 48 bytes
//   0x10bf2c: 900007A8  adrp     x8, #0x1ff000
//   0x10bf30: F9404809  ldr      x9, [x0, #0x90]
//   0x10bf34: F945F108  ldr      x8, [x8, #0xbe0]
//   0x10bf38: 14000003  b        #0x10bf44
static inline uint64_t fde_func_1252_0x10bf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bf2cULL ^ (static_cast<uint64_t>(0x900007a8ULL) << 13);
    acc = (acc + a1 + 0xf9404809ULL) ^ 0x1e5d10ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1253 | PC: 0x10bf5c | FDE: 0x1e5d28 | Size: 256 bytes [_PyErr_SetObject]
// Khung tháo gỡ #1253 | Địa chỉ PC: 0x10bf5c | Địa chỉ FDE: 0x1e5d28 | Kích thước: 256 bytes
//   0x10bf5c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x10bf60: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x10bf64: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10bf68: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1253_0x10bf5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bf5cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e5d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1254 | PC: 0x10c24c | FDE: 0x1e5d58 | Size: 152 bytes [_PyErr_Format]
// Khung tháo gỡ #1254 | Địa chỉ PC: 0x10c24c | Địa chỉ FDE: 0x1e5d58 | Kích thước: 152 bytes
//   0x10c24c: D10483FF  sub      sp, sp, #0x120
//   0x10c250: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x10c254: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x10c258: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1254_0x10c24c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c24cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1e5d58ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1255 | PC: 0x10c2e4 | FDE: 0x1e5d78 | Size: 256 bytes [_PyErr_Clear]
// Khung tháo gỡ #1255 | Địa chỉ PC: 0x10c2e4 | Địa chỉ FDE: 0x1e5d78 | Kích thước: 256 bytes
//   0x10c2e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c2e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c2ec: 910043FD  add      x29, sp, #0x10
//   0x10c2f0: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1255_0x10c2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c2e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1256 | PC: 0x10c518 | FDE: 0x1e5dc0 | Size: 44 bytes [PyErr_SetObject]
// Khung tháo gỡ #1256 | Địa chỉ PC: 0x10c518 | Địa chỉ FDE: 0x1e5dc0 | Kích thước: 44 bytes
//   0x10c518: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c51c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c520: 910043FD  add      x29, sp, #0x10
//   0x10c524: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1256_0x10c518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c518ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5dc0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1257 | PC: 0x10c544 | FDE: 0x1e5de0 | Size: 112 bytes [_PyErr_SetKeyError]
// Khung tháo gỡ #1257 | Địa chỉ PC: 0x10c544 | Địa chỉ FDE: 0x1e5de0 | Kích thước: 112 bytes
//   0x10c544: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c548: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c54c: 910043FD  add      x29, sp, #0x10
//   0x10c550: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1257_0x10c544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c544ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5de0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1258 | PC: 0x10c5b4 | FDE: 0x1e5e00 | Size: 8 bytes [_PyErr_SetNone]
// Khung tháo gỡ #1258 | Địa chỉ PC: 0x10c5b4 | Địa chỉ FDE: 0x1e5e00 | Kích thước: 8 bytes
//   0x10c5b4: AA1F03E2  mov      x2, xzr
//   0x10c5b8: 17FD41DA  b        #0x5cd20
static inline uint64_t fde_func_1258_0x10c5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c5b4ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17fd41daULL) ^ 0x1e5e00ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1259 | PC: 0x10c5bc | FDE: 0x1e5e18 | Size: 40 bytes [PyErr_SetNone]
// Khung tháo gỡ #1259 | Địa chỉ PC: 0x10c5bc | Địa chỉ FDE: 0x1e5e18 | Kích thước: 40 bytes
//   0x10c5bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10c5c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c5c4: 910043FD  add      x29, sp, #0x10
//   0x10c5c8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1259_0x10c5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c5bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5e18ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1260 | PC: 0x10c5e4 | FDE: 0x1e5e38 | Size: 108 bytes [_PyErr_SetString]
// Khung tháo gỡ #1260 | Địa chỉ PC: 0x10c5e4 | Địa chỉ FDE: 0x1e5e38 | Kích thước: 108 bytes
//   0x10c5e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10c5e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10c5ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10c5f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1260_0x10c5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c5e4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5e38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1261 | PC: 0x10c650 | FDE: 0x1e5e58 | Size: 116 bytes [PyErr_SetString]
// Khung tháo gỡ #1261 | Địa chỉ PC: 0x10c650 | Địa chỉ FDE: 0x1e5e58 | Kích thước: 116 bytes
//   0x10c650: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10c654: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10c658: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10c65c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1261_0x10c650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c650ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5e58ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1262 | PC: 0x10c6c4 | FDE: 0x1e5e78 | Size: 24 bytes [PyErr_Occurred]
// Khung tháo gỡ #1262 | Địa chỉ PC: 0x10c6c4 | Địa chỉ FDE: 0x1e5e78 | Kích thước: 24 bytes
//   0x10c6c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10c6c8: 910003FD  mov      x29, sp
//   0x10c6cc: 97FD343D  bl       #0x597c0
//   0x10c6d0: F9402C00  ldr      x0, [x0, #0x58]
static inline uint64_t fde_func_1262_0x10c6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c6c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5e78ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1263 | PC: 0x10c6dc | FDE: 0x1e5e98 | Size: 212 bytes [PyErr_GivenExceptionMatches]
// Khung tháo gỡ #1263 | Địa chỉ PC: 0x10c6dc | Địa chỉ FDE: 0x1e5e98 | Kích thước: 212 bytes
//   0x10c6dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10c6e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10c6e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10c6e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1263_0x10c6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c6dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5e98ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1264 | PC: 0x10c7b0 | FDE: 0x1e5eb8 | Size: 8 bytes [_PyErr_ExceptionMatches]
// Khung tháo gỡ #1264 | Địa chỉ PC: 0x10c7b0 | Địa chỉ FDE: 0x1e5eb8 | Kích thước: 8 bytes
//   0x10c7b0: F9402C00  ldr      x0, [x0, #0x58]
//   0x10c7b4: 17FD34FF  b        #0x59bb0
static inline uint64_t fde_func_1264_0x10c7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c7b0ULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0x17fd34ffULL) ^ 0x1e5eb8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1265 | PC: 0x10c7b8 | FDE: 0x1e5ed0 | Size: 40 bytes [PyErr_ExceptionMatches]
// Khung tháo gỡ #1265 | Địa chỉ PC: 0x10c7b8 | Địa chỉ FDE: 0x1e5ed0 | Kích thước: 40 bytes
//   0x10c7b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10c7bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c7c0: 910043FD  add      x29, sp, #0x10
//   0x10c7c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1265_0x10c7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c7b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5ed0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1266 | PC: 0x10c7e0 | FDE: 0x1e5ef0 | Size: 256 bytes [_PyErr_NormalizeException]
// Khung tháo gỡ #1266 | Địa chỉ PC: 0x10c7e0 | Địa chỉ FDE: 0x1e5ef0 | Kích thước: 256 bytes
//   0x10c7e0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x10c7e4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10c7e8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10c7ec: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1266_0x10c7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c7e0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e5ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1267 | PC: 0x10ca44 | FDE: 0x1e5f20 | Size: 36 bytes [_PyErr_Fetch]
// Khung tháo gỡ #1267 | Địa chỉ PC: 0x10ca44 | Địa chỉ FDE: 0x1e5f20 | Kích thước: 36 bytes
//   0x10ca44: F9402C08  ldr      x8, [x0, #0x58]
//   0x10ca48: F9000028  str      x8, [x1]
//   0x10ca4c: F9403008  ldr      x8, [x0, #0x60]
//   0x10ca50: F9000048  str      x8, [x2]
static inline uint64_t fde_func_1267_0x10ca44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ca44ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9000028ULL) ^ 0x1e5f20ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1268 | PC: 0x10ca68 | FDE: 0x1e5f38 | Size: 60 bytes [PyErr_NormalizeException]
// Khung tháo gỡ #1268 | Địa chỉ PC: 0x10ca68 | Địa chỉ FDE: 0x1e5f38 | Kích thước: 60 bytes
//   0x10ca68: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10ca6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10ca70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10ca74: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1268_0x10ca68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ca68ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5f38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1269 | PC: 0x10caa4 | FDE: 0x1e5f58 | Size: 80 bytes [PyErr_Fetch]
// Khung tháo gỡ #1269 | Địa chỉ PC: 0x10caa4 | Địa chỉ FDE: 0x1e5f58 | Kích thước: 80 bytes
//   0x10caa4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10caa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10caac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10cab0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1269_0x10caa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10caa4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5f58ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1270 | PC: 0x10caf4 | FDE: 0x1e5f78 | Size: 148 bytes [PyErr_Clear]
// Khung tháo gỡ #1270 | Địa chỉ PC: 0x10caf4 | Địa chỉ FDE: 0x1e5f78 | Kích thước: 148 bytes
//   0x10caf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10caf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10cafc: 910043FD  add      x29, sp, #0x10
//   0x10cb00: 97FD3330  bl       #0x597c0
static inline uint64_t fde_func_1270_0x10caf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10caf4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5f78ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1271 | PC: 0x10cb88 | FDE: 0x1e5f98 | Size: 124 bytes [_PyErr_GetExcInfo]
// Khung tháo gỡ #1271 | Địa chỉ PC: 0x10cb88 | Địa chỉ FDE: 0x1e5f98 | Kích thước: 124 bytes
//   0x10cb88: F0000789  adrp     x9, #0x1ff000
//   0x10cb8c: F940480B  ldr      x11, [x0, #0x90]
//   0x10cb90: F945F129  ldr      x9, [x9, #0xbe0]
//   0x10cb94: 14000003  b        #0x10cba0
static inline uint64_t fde_func_1271_0x10cb88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cb88ULL ^ (static_cast<uint64_t>(0xf0000789ULL) << 13);
    acc = (acc + a1 + 0xf940480bULL) ^ 0x1e5f98ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1272 | PC: 0x10cc04 | FDE: 0x1e5fb0 | Size: 168 bytes [PyErr_GetExcInfo]
// Khung tháo gỡ #1272 | Địa chỉ PC: 0x10cc04 | Địa chỉ FDE: 0x1e5fb0 | Kích thước: 168 bytes
//   0x10cc04: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10cc08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10cc0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10cc10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1272_0x10cc04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cc04ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5fb0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1273 | PC: 0x10ccac | FDE: 0x1e5fd0 | Size: 184 bytes [PyErr_SetExcInfo]
// Khung tháo gỡ #1273 | Địa chỉ PC: 0x10ccac | Địa chỉ FDE: 0x1e5fd0 | Kích thước: 184 bytes
//   0x10ccac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10ccb0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10ccb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10ccb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1273_0x10ccac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ccacULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5fd0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1274 | PC: 0x10cd64 | FDE: 0x1e5ff8 | Size: 256 bytes [_PyErr_ChainExceptions]
// Khung tháo gỡ #1274 | Địa chỉ PC: 0x10cd64 | Địa chỉ FDE: 0x1e5ff8 | Kích thước: 256 bytes
//   0x10cd64: D10183FF  sub      sp, sp, #0x60
//   0x10cd68: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x10cd6c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x10cd70: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1274_0x10cd64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cd64ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e5ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1275 | PC: 0x10cecc | FDE: 0x1e6020 | Size: 256 bytes [_PyErr_ChainStackItem]
// Khung tháo gỡ #1275 | Địa chỉ PC: 0x10cecc | Địa chỉ FDE: 0x1e6020 | Kích thước: 256 bytes
//   0x10cecc: D10183FF  sub      sp, sp, #0x60
//   0x10ced0: F9000BF9  str      x25, [sp, #0x10]
//   0x10ced4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10ced8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1275_0x10cecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ceccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1e6020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1276 | PC: 0x10d008 | FDE: 0x1e6048 | Size: 256 bytes [_PyErr_FormatFromCauseTstate]
// Khung tháo gỡ #1276 | Địa chỉ PC: 0x10d008 | Địa chỉ FDE: 0x1e6048 | Kích thước: 256 bytes
//   0x10d008: D10483FF  sub      sp, sp, #0x120
//   0x10d00c: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x10d010: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x10d014: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1276_0x10d008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d008ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1e6048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1277 | PC: 0x10d1e0 | FDE: 0x1e6090 | Size: 188 bytes [_PyErr_FormatFromCause]
// Khung tháo gỡ #1277 | Địa chỉ PC: 0x10d1e0 | Địa chỉ FDE: 0x1e6090 | Kích thước: 188 bytes
//   0x10d1e0: D10503FF  sub      sp, sp, #0x140
//   0x10d1e4: F90083FC  str      x28, [sp, #0x100]
//   0x10d1e8: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x10d1ec: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1277_0x10d1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d1e0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1e6090ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1278 | PC: 0x10d29c | FDE: 0x1e60b8 | Size: 116 bytes [PyErr_BadArgument]
// Khung tháo gỡ #1278 | Địa chỉ PC: 0x10d29c | Địa chỉ FDE: 0x1e60b8 | Kích thước: 116 bytes
//   0x10d29c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10d2a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10d2a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10d2a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1278_0x10d29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d29cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e60b8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1279 | PC: 0x10d310 | FDE: 0x1e60d8 | Size: 68 bytes [_PyErr_NoMemory]
// Khung tháo gỡ #1279 | Địa chỉ PC: 0x10d310 | Địa chỉ FDE: 0x1e60d8 | Kích thước: 68 bytes
//   0x10d310: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d314: 910003FD  mov      x29, sp
//   0x10d318: D0000788  adrp     x8, #0x1ff000
//   0x10d31c: F9442508  ldr      x8, [x8, #0x848]
static inline uint64_t fde_func_1279_0x10d310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d310ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e60d8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1280 | PC: 0x10d354 | FDE: 0x1e60f8 | Size: 72 bytes [PyErr_NoMemory]
// Khung tháo gỡ #1280 | Địa chỉ PC: 0x10d354 | Địa chỉ FDE: 0x1e60f8 | Kích thước: 72 bytes
//   0x10d354: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d358: 910003FD  mov      x29, sp
//   0x10d35c: 97FD3119  bl       #0x597c0
//   0x10d360: D0000788  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1280_0x10d354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d354ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e60f8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1281 | PC: 0x10d39c | FDE: 0x1e6118 | Size: 28 bytes [PyErr_SetFromErrnoWithFilenameObject]
// Khung tháo gỡ #1281 | Địa chỉ PC: 0x10d39c | Địa chỉ FDE: 0x1e6118 | Kích thước: 28 bytes
//   0x10d39c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d3a0: 910003FD  mov      x29, sp
//   0x10d3a4: AA1F03E2  mov      x2, xzr
//   0x10d3a8: 97FD3A12  bl       #0x5bbf0
static inline uint64_t fde_func_1281_0x10d39c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d39cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6118ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1282 | PC: 0x10d3b8 | FDE: 0x1e6138 | Size: 256 bytes [PyErr_SetFromErrnoWithFilenameObjects]
// Khung tháo gỡ #1282 | Địa chỉ PC: 0x10d3b8 | Địa chỉ FDE: 0x1e6138 | Kích thước: 256 bytes
//   0x10d3b8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x10d3bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10d3c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10d3c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1282_0x10d3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d3b8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1283 | PC: 0x10d51c | FDE: 0x1e6160 | Size: 108 bytes [PyErr_SetFromErrnoWithFilename]
// Khung tháo gỡ #1283 | Địa chỉ PC: 0x10d51c | Địa chỉ FDE: 0x1e6160 | Kích thước: 108 bytes
//   0x10d51c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10d520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10d524: 910043FD  add      x29, sp, #0x10
//   0x10d528: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1283_0x10d51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d51cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6160ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1284 | PC: 0x10d588 | FDE: 0x1e6180 | Size: 32 bytes [PyErr_SetFromErrno]
// Khung tháo gỡ #1284 | Địa chỉ PC: 0x10d588 | Địa chỉ FDE: 0x1e6180 | Kích thước: 32 bytes
//   0x10d588: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d58c: 910003FD  mov      x29, sp
//   0x10d590: AA1F03E1  mov      x1, xzr
//   0x10d594: AA1F03E2  mov      x2, xzr
static inline uint64_t fde_func_1284_0x10d588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d588ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6180ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1285 | PC: 0x10d5a8 | FDE: 0x1e61a0 | Size: 256 bytes [PyErr_SetImportErrorSubclass]
// Khung tháo gỡ #1285 | Địa chỉ PC: 0x10d5a8 | Địa chỉ FDE: 0x1e61a0 | Kích thước: 256 bytes
//   0x10d5a8: D10183FF  sub      sp, sp, #0x60
//   0x10d5ac: F9000BF9  str      x25, [sp, #0x10]
//   0x10d5b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10d5b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1285_0x10d5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d5a8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1e61a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1286 | PC: 0x10d744 | FDE: 0x1e61c8 | Size: 52 bytes [PyErr_SetImportError]
// Khung tháo gỡ #1286 | Địa chỉ PC: 0x10d744 | Địa chỉ FDE: 0x1e61c8 | Kích thước: 52 bytes
//   0x10d744: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d748: 910003FD  mov      x29, sp
//   0x10d74c: D0000788  adrp     x8, #0x1ff000
//   0x10d750: F946E908  ldr      x8, [x8, #0xdd0]
static inline uint64_t fde_func_1286_0x10d744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d744ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e61c8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1287 | PC: 0x10d778 | FDE: 0x1e61e8 | Size: 96 bytes [_PyErr_BadInternalCall]
// Khung tháo gỡ #1287 | Địa chỉ PC: 0x10d778 | Địa chỉ FDE: 0x1e61e8 | Kích thước: 96 bytes
//   0x10d778: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10d77c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10d780: 910043FD  add      x29, sp, #0x10
//   0x10d784: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_1287_0x10d778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d778ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e61e8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1288 | PC: 0x10d7d8 | FDE: 0x1e6208 | Size: 124 bytes [PyErr_BadInternalCall]
// Khung tháo gỡ #1288 | Địa chỉ PC: 0x10d7d8 | Địa chỉ FDE: 0x1e6208 | Kích thước: 124 bytes
//   0x10d7d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10d7dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10d7e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10d7e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1288_0x10d7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d7d8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6208ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1289 | PC: 0x10d854 | FDE: 0x1e6228 | Size: 256 bytes [PyErr_FormatV]
// Khung tháo gỡ #1289 | Địa chỉ PC: 0x10d854 | Địa chỉ FDE: 0x1e6228 | Kích thước: 256 bytes
//   0x10d854: D10143FF  sub      sp, sp, #0x50
//   0x10d858: F90013F5  str      x21, [sp, #0x20]
//   0x10d85c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10d860: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1289_0x10d854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d854ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e6228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1290 | PC: 0x10d9b4 | FDE: 0x1e6270 | Size: 188 bytes [PyErr_Format]
// Khung tháo gỡ #1290 | Địa chỉ PC: 0x10d9b4 | Địa chỉ FDE: 0x1e6270 | Kích thước: 188 bytes
//   0x10d9b4: D10503FF  sub      sp, sp, #0x140
//   0x10d9b8: F90083FC  str      x28, [sp, #0x100]
//   0x10d9bc: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x10d9c0: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1290_0x10d9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d9b4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1e6270ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1291 | PC: 0x10da70 | FDE: 0x1e6298 | Size: 256 bytes [PyErr_NewException]
// Khung tháo gỡ #1291 | Địa chỉ PC: 0x10da70 | Địa chỉ FDE: 0x1e6298 | Kích thước: 256 bytes
//   0x10da70: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10da74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10da78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10da7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1291_0x10da70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10da70ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1292 | PC: 0x10dc4c | FDE: 0x1e62c0 | Size: 236 bytes [PyErr_NewExceptionWithDoc]
// Khung tháo gỡ #1292 | Địa chỉ PC: 0x10dc4c | Địa chỉ FDE: 0x1e62c0 | Kích thước: 236 bytes
//   0x10dc4c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x10dc50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10dc54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10dc58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1292_0x10dc4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dc4cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e62c0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1293 | PC: 0x10dd38 | FDE: 0x1e62e8 | Size: 116 bytes [_PyErr_InitTypes]
// Khung tháo gỡ #1293 | Địa chỉ PC: 0x10dd38 | Địa chỉ FDE: 0x1e62e8 | Kích thước: 116 bytes
//   0x10dd38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10dd3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10dd40: 910043FD  add      x29, sp, #0x10
//   0x10dd44: F00008A9  adrp     x9, #0x224000
static inline uint64_t fde_func_1293_0x10dd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dd38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e62e8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1294 | PC: 0x10ddac | FDE: 0x1e6308 | Size: 256 bytes [_PyErr_WriteUnraisableDefaultHook]
// Khung tháo gỡ #1294 | Địa chỉ PC: 0x10ddac | Địa chỉ FDE: 0x1e6308 | Kích thước: 256 bytes
//   0x10ddac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10ddb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10ddb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10ddb8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1294_0x10ddac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ddacULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1295 | PC: 0x10e3e0 | FDE: 0x1e6358 | Size: 256 bytes [_PyErr_WriteUnraisableMsg]
// Khung tháo gỡ #1295 | Địa chỉ PC: 0x10e3e0 | Địa chỉ FDE: 0x1e6358 | Kích thước: 256 bytes
//   0x10e3e0: D10283FF  sub      sp, sp, #0xa0
//   0x10e3e4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x10e3e8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x10e3ec: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1295_0x10e3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e3e0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e6358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1296 | PC: 0x10e980 | FDE: 0x1e6388 | Size: 12 bytes [PyErr_WriteUnraisable]
// Khung tháo gỡ #1296 | Địa chỉ PC: 0x10e980 | Địa chỉ FDE: 0x1e6388 | Kích thước: 12 bytes
//   0x10e980: AA0003E1  mov      x1, x0
//   0x10e984: AA1F03E0  mov      x0, xzr
//   0x10e988: 17FD326E  b        #0x5b340
static inline uint64_t fde_func_1296_0x10e980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e980ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1e6388ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1297 | PC: 0x10e98c | FDE: 0x1e63a0 | Size: 8 bytes [PyErr_SyntaxLocation]
// Khung tháo gỡ #1297 | Địa chỉ PC: 0x10e98c | Địa chỉ FDE: 0x1e63a0 | Kích thước: 8 bytes
//   0x10e98c: 12800002  mov      w2, #-1
//   0x10e990: 17FD383C  b        #0x5ca80
static inline uint64_t fde_func_1297_0x10e98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e98cULL ^ (static_cast<uint64_t>(0x12800002ULL) << 13);
    acc = (acc + a1 + 0x17fd383cULL) ^ 0x1e63a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1298 | PC: 0x10e994 | FDE: 0x1e63b8 | Size: 256 bytes [PyErr_SyntaxLocationEx]
// Khung tháo gỡ #1298 | Địa chỉ PC: 0x10e994 | Địa chỉ FDE: 0x1e63b8 | Kích thước: 256 bytes
//   0x10e994: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10e998: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10e99c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10e9a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1298_0x10e994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e994ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e63b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1299 | PC: 0x10eaa8 | FDE: 0x1e63e0 | Size: 256 bytes [PyErr_SyntaxLocationObject]
// Khung tháo gỡ #1299 | Địa chỉ PC: 0x10eaa8 | Địa chỉ FDE: 0x1e63e0 | Kích thước: 256 bytes
//   0x10eaa8: 12800004  mov      w4, #-1
//   0x10eaac: 2A0103E3  mov      w3, w1
//   0x10eab0: 14000001  b        #0x10eab4
//   0x10eab4: D10283FF  sub      sp, sp, #0xa0
static inline uint64_t fde_func_1299_0x10eaa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eaa8ULL ^ (static_cast<uint64_t>(0x12800004ULL) << 13);
    acc = (acc + a1 + 0x2a0103e3ULL) ^ 0x1e63e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1300 | PC: 0x10f360 | FDE: 0x1e6428 | Size: 4 bytes [PyErr_RangedSyntaxLocationObject]
// Khung tháo gỡ #1300 | Địa chỉ PC: 0x10f360 | Địa chỉ FDE: 0x1e6428 | Kích thước: 4 bytes
//   0x10f360: 17FFFDD5  b        #0x10eab4
static inline uint64_t fde_func_1300_0x10f360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f360ULL ^ (static_cast<uint64_t>(0x17fffdd5ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1e6428ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1301 | PC: 0x10f364 | FDE: 0x1e6440 | Size: 96 bytes [PyErr_ProgramText]
// Khung tháo gỡ #1301 | Địa chỉ PC: 0x10f364 | Địa chỉ FDE: 0x1e6440 | Kích thước: 96 bytes
//   0x10f364: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10f368: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10f36c: 910043FD  add      x29, sp, #0x10
//   0x10f370: B4000200  cbz      x0, #0x10f3b0
static inline uint64_t fde_func_1301_0x10f364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f364ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6440ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1302 | PC: 0x10f3c4 | FDE: 0x1e6460 | Size: 256 bytes [PyErr_ProgramTextObject]
// Khung tháo gỡ #1302 | Địa chỉ PC: 0x10f3c4 | Địa chỉ FDE: 0x1e6460 | Kích thước: 256 bytes
//   0x10f3c4: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x10f3c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10f3cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10f3d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1302_0x10f3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f3c4ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1303 | PC: 0x10f514 | FDE: 0x1e6488 | Size: 96 bytes [_BDPythonVM_PyErr_UnExpected]
// Khung tháo gỡ #1303 | Địa chỉ PC: 0x10f514 | Địa chỉ FDE: 0x1e6488 | Kích thước: 96 bytes
//   0x10f514: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10f518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10f51c: 910043FD  add      x29, sp, #0x10
//   0x10f520: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_1303_0x10f514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f514ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6488ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1304 | PC: 0x10f574 | FDE: 0x1e64a8 | Size: 256 bytes [Py_FrozenMain]
// Khung tháo gỡ #1304 | Địa chỉ PC: 0x10f574 | Địa chỉ FDE: 0x1e64a8 | Kích thước: 256 bytes
//   0x10f574: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x10f578: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10f57c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10f580: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1304_0x10f574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f574ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e64a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1305 | PC: 0x10f94c | FDE: 0x1e64d8 | Size: 156 bytes [PyArg_Parse]
// Khung tháo gỡ #1305 | Địa chỉ PC: 0x10f94c | Địa chỉ FDE: 0x1e64d8 | Kích thước: 156 bytes
//   0x10f94c: D10403FF  sub      sp, sp, #0x100
//   0x10f950: F90073F3  str      x19, [sp, #0xe0]
//   0x10f954: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10f958: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_1305_0x10f94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f94cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e64d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1306 | PC: 0x10f9e8 | FDE: 0x1e64f8 | Size: 156 bytes [_PyArg_Parse_SizeT]
// Khung tháo gỡ #1306 | Địa chỉ PC: 0x10f9e8 | Địa chỉ FDE: 0x1e64f8 | Kích thước: 156 bytes
//   0x10f9e8: D10403FF  sub      sp, sp, #0x100
//   0x10f9ec: F90073F3  str      x19, [sp, #0xe0]
//   0x10f9f0: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10f9f4: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_1306_0x10f9e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f9e8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e64f8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1307 | PC: 0x10fa84 | FDE: 0x1e6518 | Size: 196 bytes [PyArg_ParseTuple]
// Khung tháo gỡ #1307 | Địa chỉ PC: 0x10fa84 | Địa chỉ FDE: 0x1e6518 | Kích thước: 196 bytes
//   0x10fa84: D10403FF  sub      sp, sp, #0x100
//   0x10fa88: F90073F3  str      x19, [sp, #0xe0]
//   0x10fa8c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10fa90: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_1307_0x10fa84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fa84ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e6518ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1308 | PC: 0x10fb48 | FDE: 0x1e6538 | Size: 196 bytes [_PyArg_ParseTuple_SizeT]
// Khung tháo gỡ #1308 | Địa chỉ PC: 0x10fb48 | Địa chỉ FDE: 0x1e6538 | Kích thước: 196 bytes
//   0x10fb48: D10403FF  sub      sp, sp, #0x100
//   0x10fb4c: F90073F3  str      x19, [sp, #0xe0]
//   0x10fb50: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10fb54: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_1308_0x10fb48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fb48ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e6538ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1309 | PC: 0x10fc0c | FDE: 0x1e6558 | Size: 256 bytes [_PyArg_ParseStack]
// Khung tháo gỡ #1309 | Địa chỉ PC: 0x10fc0c | Địa chỉ FDE: 0x1e6558 | Kích thước: 256 bytes
//   0x10fc0c: D103C3FF  sub      sp, sp, #0xf0
//   0x10fc10: F9006BF3  str      x19, [sp, #0xd0]
//   0x10fc14: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x10fc18: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1309_0x10fc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fc0cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1310 | PC: 0x110290 | FDE: 0x1e65a8 | Size: 160 bytes [_PyArg_ParseStack_SizeT]
// Khung tháo gỡ #1310 | Địa chỉ PC: 0x110290 | Địa chỉ FDE: 0x1e65a8 | Kích thước: 160 bytes
//   0x110290: D103C3FF  sub      sp, sp, #0xf0
//   0x110294: F9006BF3  str      x19, [sp, #0xd0]
//   0x110298: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x11029c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1310_0x110290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110290ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e65a8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1311 | PC: 0x110330 | FDE: 0x1e65c8 | Size: 140 bytes [PyArg_VaParse]
// Khung tháo gỡ #1311 | Địa chỉ PC: 0x110330 | Địa chỉ FDE: 0x1e65c8 | Kích thước: 140 bytes
//   0x110330: D10143FF  sub      sp, sp, #0x50
//   0x110334: F9001BF3  str      x19, [sp, #0x30]
//   0x110338: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x11033c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1311_0x110330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110330ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e65c8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1312 | PC: 0x1103bc | FDE: 0x1e65e8 | Size: 140 bytes [_PyArg_VaParse_SizeT]
// Khung tháo gỡ #1312 | Địa chỉ PC: 0x1103bc | Địa chỉ FDE: 0x1e65e8 | Kích thước: 140 bytes
//   0x1103bc: D10143FF  sub      sp, sp, #0x50
//   0x1103c0: F9001BF3  str      x19, [sp, #0x30]
//   0x1103c4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1103c8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1312_0x1103bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1103bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e65e8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1313 | PC: 0x110448 | FDE: 0x1e6608 | Size: 80 bytes [_PyArg_BadArgument]
// Khung tháo gỡ #1313 | Địa chỉ PC: 0x110448 | Địa chỉ FDE: 0x1e6608 | Kích thước: 80 bytes
//   0x110448: F0000768  adrp     x8, #0x1ff000
//   0x11044c: F9447908  ldr      x8, [x8, #0x8f0]
//   0x110450: F000076A  adrp     x10, #0x1ff000
//   0x110454: AA0203E4  mov      x4, x2
static inline uint64_t fde_func_1313_0x110448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110448ULL ^ (static_cast<uint64_t>(0xf0000768ULL) << 13);
    acc = (acc + a1 + 0xf9447908ULL) ^ 0x1e6608ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1314 | PC: 0x110498 | FDE: 0x1e6620 | Size: 256 bytes [PyArg_ParseTupleAndKeywords]
// Khung tháo gỡ #1314 | Địa chỉ PC: 0x110498 | Địa chỉ FDE: 0x1e6620 | Kích thước: 256 bytes
//   0x110498: D103C3FF  sub      sp, sp, #0xf0
//   0x11049c: F9006BF3  str      x19, [sp, #0xd0]
//   0x1104a0: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x1104a4: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1314_0x110498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110498ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1315 | PC: 0x111170 | FDE: 0x1e6670 | Size: 200 bytes [_PyArg_ParseTupleAndKeywords_SizeT]
// Khung tháo gỡ #1315 | Địa chỉ PC: 0x111170 | Địa chỉ FDE: 0x1e6670 | Kích thước: 200 bytes
//   0x111170: D103C3FF  sub      sp, sp, #0xf0
//   0x111174: F9006BF3  str      x19, [sp, #0xd0]
//   0x111178: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x11117c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1315_0x111170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111170ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6670ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1316 | PC: 0x111238 | FDE: 0x1e6690 | Size: 148 bytes [PyArg_VaParseTupleAndKeywords]
// Khung tháo gỡ #1316 | Địa chỉ PC: 0x111238 | Địa chỉ FDE: 0x1e6690 | Kích thước: 148 bytes
//   0x111238: D10143FF  sub      sp, sp, #0x50
//   0x11123c: F9001BF3  str      x19, [sp, #0x30]
//   0x111240: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x111244: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1316_0x111238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111238ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e6690ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1317 | PC: 0x1112cc | FDE: 0x1e66b0 | Size: 148 bytes [_PyArg_VaParseTupleAndKeywords_SizeT]
// Khung tháo gỡ #1317 | Địa chỉ PC: 0x1112cc | Địa chỉ FDE: 0x1e66b0 | Kích thước: 148 bytes
//   0x1112cc: D10143FF  sub      sp, sp, #0x50
//   0x1112d0: F9001BF3  str      x19, [sp, #0x30]
//   0x1112d4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1112d8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1317_0x1112cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1112ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e66b0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1318 | PC: 0x111360 | FDE: 0x1e66d0 | Size: 220 bytes [_PyArg_ParseTupleAndKeywordsFast]
// Khung tháo gỡ #1318 | Địa chỉ PC: 0x111360 | Địa chỉ FDE: 0x1e66d0 | Kích thước: 220 bytes
//   0x111360: D103C3FF  sub      sp, sp, #0xf0
//   0x111364: F9006BF3  str      x19, [sp, #0xd0]
//   0x111368: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x11136c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1318_0x111360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111360ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e66d0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1319 | PC: 0x11143c | FDE: 0x1e66f0 | Size: 220 bytes [_PyArg_ParseTupleAndKeywordsFast_SizeT]
// Khung tháo gỡ #1319 | Địa chỉ PC: 0x11143c | Địa chỉ FDE: 0x1e66f0 | Kích thước: 220 bytes
//   0x11143c: D103C3FF  sub      sp, sp, #0xf0
//   0x111440: F9006BF3  str      x19, [sp, #0xd0]
//   0x111444: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x111448: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1319_0x11143c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11143cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e66f0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1320 | PC: 0x111518 | FDE: 0x1e6710 | Size: 256 bytes [_PyArg_ParseStackAndKeywords]
// Khung tháo gỡ #1320 | Địa chỉ PC: 0x111518 | Địa chỉ FDE: 0x1e6710 | Kích thước: 256 bytes
//   0x111518: D103C3FF  sub      sp, sp, #0xf0
//   0x11151c: F9006BF3  str      x19, [sp, #0xd0]
//   0x111520: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x111524: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1320_0x111518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111518ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1321 | PC: 0x111e80 | FDE: 0x1e6760 | Size: 152 bytes [_PyArg_ParseStackAndKeywords_SizeT]
// Khung tháo gỡ #1321 | Địa chỉ PC: 0x111e80 | Địa chỉ FDE: 0x1e6760 | Kích thước: 152 bytes
//   0x111e80: D103C3FF  sub      sp, sp, #0xf0
//   0x111e84: F9006BF3  str      x19, [sp, #0xd0]
//   0x111e88: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x111e8c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_1321_0x111e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111e80ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6760ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1322 | PC: 0x111f18 | FDE: 0x1e6780 | Size: 160 bytes [_PyArg_VaParseTupleAndKeywordsFast]
// Khung tháo gỡ #1322 | Địa chỉ PC: 0x111f18 | Địa chỉ FDE: 0x1e6780 | Kích thước: 160 bytes
//   0x111f18: D10143FF  sub      sp, sp, #0x50
//   0x111f1c: F9001BF3  str      x19, [sp, #0x30]
//   0x111f20: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x111f24: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1322_0x111f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111f18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e6780ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1323 | PC: 0x111fb8 | FDE: 0x1e67a0 | Size: 160 bytes [_PyArg_VaParseTupleAndKeywordsFast_SizeT]
// Khung tháo gỡ #1323 | Địa chỉ PC: 0x111fb8 | Địa chỉ FDE: 0x1e67a0 | Kích thước: 160 bytes
//   0x111fb8: D10143FF  sub      sp, sp, #0x50
//   0x111fbc: F9001BF3  str      x19, [sp, #0x30]
//   0x111fc0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x111fc4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1323_0x111fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111fb8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e67a0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1324 | PC: 0x112058 | FDE: 0x1e67c0 | Size: 96 bytes [PyArg_ValidateKeywordArguments]
// Khung tháo gỡ #1324 | Địa chỉ PC: 0x112058 | Địa chỉ FDE: 0x1e67c0 | Kích thước: 96 bytes
//   0x112058: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11205c: 910003FD  mov      x29, sp
//   0x112060: F9400408  ldr      x8, [x0, #8]
//   0x112064: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_1324_0x112058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112058ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e67c0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1325 | PC: 0x1120b8 | FDE: 0x1e67e0 | Size: 256 bytes [_PyArg_UnpackKeywords]
// Khung tháo gỡ #1325 | Địa chỉ PC: 0x1120b8 | Địa chỉ FDE: 0x1e67e0 | Kích thước: 256 bytes
//   0x1120b8: D10343FF  sub      sp, sp, #0xd0
//   0x1120bc: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x1120c0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x1120c4: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1325_0x1120b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1120b8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x1e67e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1326 | PC: 0x112b1c | FDE: 0x1e6840 | Size: 256 bytes [_PyArg_CheckPositional]
// Khung tháo gỡ #1326 | Địa chỉ PC: 0x112b1c | Địa chỉ FDE: 0x1e6840 | Kích thước: 256 bytes
//   0x112b1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112b20: 910003FD  mov      x29, sp
//   0x112b24: AA0303E4  mov      x4, x3
//   0x112b28: AA0203E8  mov      x8, x2
static inline uint64_t fde_func_1326_0x112b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112b1cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1327 | PC: 0x112c1c | FDE: 0x1e6860 | Size: 256 bytes [PyArg_UnpackTuple]
// Khung tháo gỡ #1327 | Địa chỉ PC: 0x112c1c | Địa chỉ FDE: 0x1e6860 | Kích thước: 256 bytes
//   0x112c1c: D10443FF  sub      sp, sp, #0x110
//   0x112c20: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x112c24: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x112c28: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_1327_0x112c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112c1cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x1e6860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1328 | PC: 0x112d48 | FDE: 0x1e6888 | Size: 256 bytes [_PyArg_UnpackStack]
// Khung tháo gỡ #1328 | Địa chỉ PC: 0x112d48 | Địa chỉ FDE: 0x1e6888 | Kích thước: 256 bytes
//   0x112d48: D10403FF  sub      sp, sp, #0x100
//   0x112d4c: F90063F7  str      x23, [sp, #0xc0]
//   0x112d50: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x112d54: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_1328_0x112d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112d48ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90063f7ULL) ^ 0x1e6888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1329 | PC: 0x112e48 | FDE: 0x1e68b0 | Size: 112 bytes [_PyArg_NoKeywords]
// Khung tháo gỡ #1329 | Địa chỉ PC: 0x112e48 | Địa chỉ FDE: 0x1e68b0 | Kích thước: 112 bytes
//   0x112e48: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112e4c: 910003FD  mov      x29, sp
//   0x112e50: B40002E1  cbz      x1, #0x112eac
//   0x112e54: B0000769  adrp     x9, #0x1ff000
static inline uint64_t fde_func_1329_0x112e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112e48ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e68b0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1330 | PC: 0x112eb8 | FDE: 0x1e68d0 | Size: 112 bytes [_PyArg_NoPositional]
// Khung tháo gỡ #1330 | Địa chỉ PC: 0x112eb8 | Địa chỉ FDE: 0x1e68d0 | Kích thước: 112 bytes
//   0x112eb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112ebc: 910003FD  mov      x29, sp
//   0x112ec0: B40002E1  cbz      x1, #0x112f1c
//   0x112ec4: B0000769  adrp     x9, #0x1ff000
static inline uint64_t fde_func_1330_0x112eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112eb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e68d0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1331 | PC: 0x112f28 | FDE: 0x1e68f0 | Size: 72 bytes [_PyArg_NoKwnames]
// Khung tháo gỡ #1331 | Địa chỉ PC: 0x112f28 | Địa chỉ FDE: 0x1e68f0 | Kích thước: 72 bytes
//   0x112f28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112f2c: 910003FD  mov      x29, sp
//   0x112f30: B40001A1  cbz      x1, #0x112f64
//   0x112f34: F9400828  ldr      x8, [x1, #0x10]
static inline uint64_t fde_func_1331_0x112f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112f28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e68f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1332 | PC: 0x112f70 | FDE: 0x1e6910 | Size: 256 bytes [_PyArg_Fini]
// Khung tháo gỡ #1332 | Địa chỉ PC: 0x112f70 | Địa chỉ FDE: 0x1e6910 | Kích thước: 256 bytes
//   0x112f70: D65F03C0  ret      
//   0x112f74: D103C3FF  sub      sp, sp, #0xf0
//   0x112f78: 6D0823E9  stp      d9, d8, [sp, #0x80]
//   0x112f7c: A9096FFC  stp      x28, x27, [sp, #0x90]
static inline uint64_t fde_func_1332_0x112f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112f70ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd103c3ffULL) ^ 0x1e6910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1333 | PC: 0x1150ac | FDE: 0x1e69f8 | Size: 12 bytes [Py_GetCompiler]
// Khung tháo gỡ #1333 | Địa chỉ PC: 0x1150ac | Địa chỉ FDE: 0x1e69f8 | Kích thước: 12 bytes
//   0x1150ac: F0000500  adrp     x0, #0x1b8000
//   0x1150b0: 91146800  add      x0, x0, #0x51a
//   0x1150b4: D65F03C0  ret      
static inline uint64_t fde_func_1333_0x1150ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150acULL ^ (static_cast<uint64_t>(0xf0000500ULL) << 13);
    acc = (acc + a1 + 0x91146800ULL) ^ 0x1e69f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1334 | PC: 0x1150b8 | FDE: 0x1e6a10 | Size: 12 bytes [Py_GetCopyright]
// Khung tháo gỡ #1334 | Địa chỉ PC: 0x1150b8 | Địa chỉ FDE: 0x1e6a10 | Kích thước: 12 bytes
//   0x1150b8: F0000500  adrp     x0, #0x1b8000
//   0x1150bc: 91162C00  add      x0, x0, #0x58b
//   0x1150c0: D65F03C0  ret      
static inline uint64_t fde_func_1334_0x1150b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150b8ULL ^ (static_cast<uint64_t>(0xf0000500ULL) << 13);
    acc = (acc + a1 + 0x91162c00ULL) ^ 0x1e6a10ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1335 | PC: 0x1150c4 | FDE: 0x1e6a28 | Size: 12 bytes [Py_GetPlatform]
// Khung tháo gỡ #1335 | Địa chỉ PC: 0x1150c4 | Địa chỉ FDE: 0x1e6a28 | Kích thước: 12 bytes
//   0x1150c4: D0000540  adrp     x0, #0x1bf000
//   0x1150c8: 910E4800  add      x0, x0, #0x392
//   0x1150cc: D65F03C0  ret      
static inline uint64_t fde_func_1335_0x1150c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150c4ULL ^ (static_cast<uint64_t>(0xd0000540ULL) << 13);
    acc = (acc + a1 + 0x910e4800ULL) ^ 0x1e6a28ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1336 | PC: 0x1150d0 | FDE: 0x1e6a40 | Size: 84 bytes [Py_GetVersion]
// Khung tháo gỡ #1336 | Địa chỉ PC: 0x1150d0 | Địa chỉ FDE: 0x1e6a40 | Kích thước: 84 bytes
//   0x1150d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1150d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1150d8: 910043FD  add      x29, sp, #0x10
//   0x1150dc: 97FD0CAD  bl       #0x58390
static inline uint64_t fde_func_1336_0x1150d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6a40ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1337 | PC: 0x115124 | FDE: 0x1e6a60 | Size: 4 bytes [_Py_hashtable_hash_ptr]
// Khung tháo gỡ #1337 | Địa chỉ PC: 0x115124 | Địa chỉ FDE: 0x1e6a60 | Kích thước: 4 bytes
//   0x115124: 17FD1F53  b        #0x5ce70
static inline uint64_t fde_func_1337_0x115124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115124ULL ^ (static_cast<uint64_t>(0x17fd1f53ULL) << 13);
    acc = (acc + a1 + 0xeb01001fULL) ^ 0x1e6a60ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1338 | PC: 0x115128 | FDE: 0x1e6a78 | Size: 12 bytes [_Py_hashtable_compare_direct]
// Khung tháo gỡ #1338 | Địa chỉ PC: 0x115128 | Địa chỉ FDE: 0x1e6a78 | Kích thước: 12 bytes
//   0x115128: EB01001F  cmp      x0, x1
//   0x11512c: 1A9F17E0  cset     w0, eq
//   0x115130: D65F03C0  ret      
static inline uint64_t fde_func_1338_0x115128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115128ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e0ULL) ^ 0x1e6a78ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1339 | PC: 0x115134 | FDE: 0x1e6a90 | Size: 20 bytes [_Py_hashtable_size]
// Khung tháo gỡ #1339 | Địa chỉ PC: 0x115134 | Địa chỉ FDE: 0x1e6a90 | Kích thước: 20 bytes
//   0x115134: A9402009  ldp      x9, x8, [x0]
//   0x115138: D37DF108  lsl      x8, x8, #3
//   0x11513c: 8B091508  add      x8, x8, x9, lsl #5
//   0x115140: 91014100  add      x0, x8, #0x50
static inline uint64_t fde_func_1339_0x115134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115134ULL ^ (static_cast<uint64_t>(0xa9402009ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1e6a90ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1340 | PC: 0x115148 | FDE: 0x1e6aa8 | Size: 124 bytes [_Py_hashtable_get_entry_generic]
// Khung tháo gỡ #1340 | Địa chỉ PC: 0x115148 | Địa chỉ FDE: 0x1e6aa8 | Kích thước: 124 bytes
//   0x115148: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11514c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115150: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115154: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1340_0x115148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115148ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6aa8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1341 | PC: 0x1151c4 | FDE: 0x1e6ad0 | Size: 256 bytes [_Py_hashtable_steal]
// Khung tháo gỡ #1341 | Địa chỉ PC: 0x1151c4 | Địa chỉ FDE: 0x1e6ad0 | Kích thước: 256 bytes
//   0x1151c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1151c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1151cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1151d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1341_0x1151c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1151c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1342 | PC: 0x1153c8 | FDE: 0x1e6b20 | Size: 208 bytes [_Py_hashtable_set]
// Khung tháo gỡ #1342 | Địa chỉ PC: 0x1153c8 | Địa chỉ FDE: 0x1e6b20 | Kích thước: 208 bytes
//   0x1153c8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1153cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1153d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1153d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1342_0x1153c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1153c8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6b20ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1343 | PC: 0x115498 | FDE: 0x1e6b48 | Size: 32 bytes [_Py_hashtable_get]
// Khung tháo gỡ #1343 | Địa chỉ PC: 0x115498 | Địa chỉ FDE: 0x1e6b48 | Kích thước: 32 bytes
//   0x115498: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11549c: 910003FD  mov      x29, sp
//   0x1154a0: F9400C08  ldr      x8, [x0, #0x18]
//   0x1154a4: D63F0100  blr      x8
static inline uint64_t fde_func_1343_0x115498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115498ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6b48ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1344 | PC: 0x1154b8 | FDE: 0x1e6b68 | Size: 132 bytes [_Py_hashtable_foreach]
// Khung tháo gỡ #1344 | Địa chỉ PC: 0x1154b8 | Địa chỉ FDE: 0x1e6b68 | Kích thước: 132 bytes
//   0x1154b8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1154bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1154c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1154c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1344_0x1154b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1154b8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6b68ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1345 | PC: 0x11553c | FDE: 0x1e6b90 | Size: 256 bytes [_Py_hashtable_new_full]
// Khung tháo gỡ #1345 | Địa chỉ PC: 0x11553c | Địa chỉ FDE: 0x1e6b90 | Kích thước: 256 bytes
//   0x11553c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x115540: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x115544: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x115548: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1345_0x11553c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11553cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e6b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1346 | PC: 0x115680 | FDE: 0x1e6bd8 | Size: 208 bytes [_Py_hashtable_new]
// Khung tháo gỡ #1346 | Địa chỉ PC: 0x115680 | Địa chỉ FDE: 0x1e6bd8 | Kích thước: 208 bytes
//   0x115680: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115684: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115688: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11568c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1346_0x115680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115680ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6bd8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1347 | PC: 0x115750 | FDE: 0x1e6bf8 | Size: 164 bytes [_Py_hashtable_clear]
// Khung tháo gỡ #1347 | Địa chỉ PC: 0x115750 | Địa chỉ FDE: 0x1e6bf8 | Kích thước: 164 bytes
//   0x115750: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x115754: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115758: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11575c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1347_0x115750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115750ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6bf8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1348 | PC: 0x1157f4 | FDE: 0x1e6c20 | Size: 164 bytes [_Py_hashtable_destroy]
// Khung tháo gỡ #1348 | Địa chỉ PC: 0x1157f4 | Địa chỉ FDE: 0x1e6c20 | Kích thước: 164 bytes
//   0x1157f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1157f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1157fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115800: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1348_0x1157f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1157f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6c20ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1349 | PC: 0x115898 | FDE: 0x1e6c48 | Size: 28 bytes [get_import_state]
// Khung tháo gỡ #1349 | Địa chỉ PC: 0x115898 | Địa chỉ FDE: 0x1e6c48 | Kích thước: 28 bytes
//   0x115898: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11589c: 910003FD  mov      x29, sp
//   0x1158a0: 97FD1C34  bl       #0x5c970
//   0x1158a4: 52869D08  mov      w8, #0x34e8
static inline uint64_t fde_func_1349_0x115898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115898ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6c48ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1350 | PC: 0x1158b4 | FDE: 0x1e6c68 | Size: 256 bytes [_PyImportZip_Init]
// Khung tháo gỡ #1350 | Địa chỉ PC: 0x1158b4 | Địa chỉ FDE: 0x1e6c68 | Kích thước: 256 bytes
//   0x1158b4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1158b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1158bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1158c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1350_0x1158b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1158b4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1351 | PC: 0x115a8c | FDE: 0x1e6c90 | Size: 132 bytes [PyImport_ImportModule]
// Khung tháo gỡ #1351 | Địa chỉ PC: 0x115a8c | Địa chỉ FDE: 0x1e6c90 | Kích thước: 132 bytes
//   0x115a8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115a90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115a94: 910043FD  add      x29, sp, #0x10
//   0x115a98: 97FD1A8A  bl       #0x5c4c0
static inline uint64_t fde_func_1351_0x115a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115a8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6c90ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1352 | PC: 0x115b10 | FDE: 0x1e6cb0 | Size: 164 bytes [_PyImport_AcquireLock]
// Khung tháo gỡ #1352 | Địa chỉ PC: 0x115b10 | Địa chỉ FDE: 0x1e6cb0 | Kích thước: 164 bytes
//   0x115b10: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115b14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115b18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115b1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1352_0x115b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115b10ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6cb0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1353 | PC: 0x115bb4 | FDE: 0x1e6cd0 | Size: 116 bytes [_PyImport_ReleaseLock]
// Khung tháo gỡ #1353 | Địa chỉ PC: 0x115bb4 | Địa chỉ FDE: 0x1e6cd0 | Kích thước: 116 bytes
//   0x115bb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115bb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115bbc: 910043FD  add      x29, sp, #0x10
//   0x115bc0: 97FD1B6C  bl       #0x5c970
static inline uint64_t fde_func_1353_0x115bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115bb4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6cd0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1354 | PC: 0x115c28 | FDE: 0x1e6cf0 | Size: 184 bytes [_PyImport_ReInitLock]
// Khung tháo gỡ #1354 | Địa chỉ PC: 0x115c28 | Địa chỉ FDE: 0x1e6cf0 | Kích thước: 184 bytes
//   0x115c28: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115c2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115c30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115c34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1354_0x115c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115c28ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6cf0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1355 | PC: 0x115ce0 | FDE: 0x1e6d10 | Size: 100 bytes [_PyImport_Fini]
// Khung tháo gỡ #1355 | Địa chỉ PC: 0x115ce0 | Địa chỉ FDE: 0x1e6d10 | Kích thước: 100 bytes
//   0x115ce0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115ce4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115ce8: 910043FD  add      x29, sp, #0x10
//   0x115cec: 97FD1B21  bl       #0x5c970
static inline uint64_t fde_func_1355_0x115ce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115ce0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6d10ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1356 | PC: 0x115d44 | FDE: 0x1e6d30 | Size: 124 bytes [_PyImport_Fini2]
// Khung tháo gỡ #1356 | Địa chỉ PC: 0x115d44 | Địa chỉ FDE: 0x1e6d30 | Kích thước: 124 bytes
//   0x115d44: D10143FF  sub      sp, sp, #0x50
//   0x115d48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x115d4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x115d50: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1356_0x115d44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115d44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e6d30ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1357 | PC: 0x115dc0 | FDE: 0x1e6d50 | Size: 64 bytes [PyImport_GetModuleDict]
// Khung tháo gỡ #1357 | Địa chỉ PC: 0x115dc0 | Địa chỉ FDE: 0x1e6d50 | Kích thước: 64 bytes
//   0x115dc0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115dc4: 910003FD  mov      x29, sp
//   0x115dc8: D0000748  adrp     x8, #0x1ff000
//   0x115dcc: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1357_0x115dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115dc0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6d50ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1358 | PC: 0x115e00 | FDE: 0x1e6d70 | Size: 16 bytes [_PyImport_IsInitialized]
// Khung tháo gỡ #1358 | Địa chỉ PC: 0x115e00 | Địa chỉ FDE: 0x1e6d70 | Kích thước: 16 bytes
//   0x115e00: F9421408  ldr      x8, [x0, #0x428]
//   0x115e04: F100011F  cmp      x8, #0
//   0x115e08: 1A9F07E0  cset     w0, ne
//   0x115e0c: D65F03C0  ret      
static inline uint64_t fde_func_1358_0x115e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e00ULL ^ (static_cast<uint64_t>(0xf9421408ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x1e6d70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1359 | PC: 0x115e10 | FDE: 0x1e6d88 | Size: 32 bytes [_PyImport_GetModuleId]
// Khung tháo gỡ #1359 | Địa chỉ PC: 0x115e10 | Địa chỉ FDE: 0x1e6d88 | Kích thước: 32 bytes
//   0x115e10: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115e14: 910003FD  mov      x29, sp
//   0x115e18: 97FD110A  bl       #0x5a240
//   0x115e1c: B4000060  cbz      x0, #0x115e28
static inline uint64_t fde_func_1359_0x115e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e10ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6d88ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1360 | PC: 0x115e30 | FDE: 0x1e6da8 | Size: 256 bytes [PyImport_GetModule]
// Khung tháo gỡ #1360 | Địa chỉ PC: 0x115e30 | Địa chỉ FDE: 0x1e6da8 | Kích thước: 256 bytes
//   0x115e30: D101C3FF  sub      sp, sp, #0x70
//   0x115e34: F90013F9  str      x25, [sp, #0x20]
//   0x115e38: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x115e3c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1360_0x115e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1e6da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1361 | PC: 0x115f64 | FDE: 0x1e6dd0 | Size: 68 bytes [_PyImport_SetModule]
// Khung tháo gỡ #1361 | Địa chỉ PC: 0x115f64 | Địa chỉ FDE: 0x1e6dd0 | Kích thước: 68 bytes
//   0x115f64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115f68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115f6c: 910043FD  add      x29, sp, #0x10
//   0x115f70: D0000748  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1361_0x115f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115f64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6dd0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1362 | PC: 0x115fa8 | FDE: 0x1e6df0 | Size: 68 bytes [_PyImport_SetModuleString]
// Khung tháo gỡ #1362 | Địa chỉ PC: 0x115fa8 | Địa chỉ FDE: 0x1e6df0 | Kích thước: 68 bytes
//   0x115fa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115fac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115fb0: 910043FD  add      x29, sp, #0x10
//   0x115fb4: D0000748  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1362_0x115fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115fa8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6df0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1363 | PC: 0x115fec | FDE: 0x1e6e10 | Size: 256 bytes [PyImport_GetMagicNumber]
// Khung tháo gỡ #1363 | Địa chỉ PC: 0x115fec | Địa chỉ FDE: 0x1e6e10 | Kích thước: 256 bytes
//   0x115fec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115ff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115ff4: 910043FD  add      x29, sp, #0x10
//   0x115ff8: 10748048  adr      x8, #0x1ff000
static inline uint64_t fde_func_1363_0x115fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115fecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1364 | PC: 0x117090 | FDE: 0x1e6e30 | Size: 16 bytes [PyImport_GetMagicTag]
// Khung tháo gỡ #1364 | Địa chỉ PC: 0x117090 | Địa chỉ FDE: 0x1e6e30 | Kích thước: 16 bytes
//   0x117090: 90000748  adrp     x8, #0x1ff000
//   0x117094: F946D108  ldr      x8, [x8, #0xda0]
//   0x117098: F9400100  ldr      x0, [x8]
//   0x11709c: D65F03C0  ret      
static inline uint64_t fde_func_1364_0x117090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117090ULL ^ (static_cast<uint64_t>(0x90000748ULL) << 13);
    acc = (acc + a1 + 0xf946d108ULL) ^ 0x1e6e30ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1365 | PC: 0x1170a0 | FDE: 0x1e6e48 | Size: 256 bytes [_PyImport_FixupExtensionObject]
// Khung tháo gỡ #1365 | Địa chỉ PC: 0x1170a0 | Địa chỉ FDE: 0x1e6e48 | Kích thước: 256 bytes
//   0x1170a0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1170a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1170a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1170ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1365_0x1170a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1170a0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1366 | PC: 0x117240 | FDE: 0x1e6e70 | Size: 116 bytes [_PyImport_FixupBuiltin]
// Khung tháo gỡ #1366 | Địa chỉ PC: 0x117240 | Địa chỉ FDE: 0x1e6e70 | Kích thước: 116 bytes
//   0x117240: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x117244: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x117248: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11724c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1366_0x117240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117240ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6e70ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1367 | PC: 0x1172b4 | FDE: 0x1e6e90 | Size: 256 bytes [PyImport_AddModuleObject]
// Khung tháo gỡ #1367 | Địa chỉ PC: 0x1172b4 | Địa chỉ FDE: 0x1e6e90 | Kích thước: 256 bytes
//   0x1172b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1172b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1172bc: 910043FD  add      x29, sp, #0x10
//   0x1172c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1367_0x1172b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1172b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1368 | PC: 0x11748c | FDE: 0x1e6ed8 | Size: 80 bytes [PyImport_AddModule]
// Khung tháo gỡ #1368 | Địa chỉ PC: 0x11748c | Địa chỉ FDE: 0x1e6ed8 | Kích thước: 80 bytes
//   0x11748c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117490: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117494: 910043FD  add      x29, sp, #0x10
//   0x117498: 97FD140A  bl       #0x5c4c0
static inline uint64_t fde_func_1368_0x11748c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11748cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6ed8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1369 | PC: 0x1174dc | FDE: 0x1e6ef8 | Size: 96 bytes [PyImport_ExecCodeModule]
// Khung tháo gỡ #1369 | Địa chỉ PC: 0x1174dc | Địa chỉ FDE: 0x1e6ef8 | Kích thước: 96 bytes
//   0x1174dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1174e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1174e4: 910043FD  add      x29, sp, #0x10
//   0x1174e8: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1369_0x1174dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1174dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6ef8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1370 | PC: 0x11753c | FDE: 0x1e6f18 | Size: 256 bytes [PyImport_ExecCodeModuleWithPathnames]
// Khung tháo gỡ #1370 | Địa chỉ PC: 0x11753c | Địa chỉ FDE: 0x1e6f18 | Kích thước: 256 bytes
//   0x11753c: D10183FF  sub      sp, sp, #0x60
//   0x117540: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x117544: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x117548: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1370_0x11753c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11753cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e6f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1371 | PC: 0x1176f4 | FDE: 0x1e6f40 | Size: 8 bytes [PyImport_ExecCodeModuleEx]
// Khung tháo gỡ #1371 | Địa chỉ PC: 0x1176f4 | Địa chỉ FDE: 0x1e6f40 | Kích thước: 8 bytes
//   0x1176f4: AA1F03E3  mov      x3, xzr
//   0x1176f8: 17FD0712  b        #0x59340
static inline uint64_t fde_func_1371_0x1176f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1176f4ULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0x17fd0712ULL) ^ 0x1e6f40ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1372 | PC: 0x1176fc | FDE: 0x1e6f58 | Size: 256 bytes [PyImport_ExecCodeModuleObject]
// Khung tháo gỡ #1372 | Địa chỉ PC: 0x1176fc | Địa chỉ FDE: 0x1e6f58 | Kích thước: 256 bytes
//   0x1176fc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x117700: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x117704: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x117708: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1372_0x1176fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1176fcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e6f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1373 | PC: 0x117980 | FDE: 0x1e6fc8 | Size: 256 bytes [PyImport_GetImporter]
// Khung tháo gỡ #1373 | Địa chỉ PC: 0x117980 | Địa chỉ FDE: 0x1e6fc8 | Kích thước: 256 bytes
//   0x117980: D10203FF  sub      sp, sp, #0x80
//   0x117984: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x117988: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x11798c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1373_0x117980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117980ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e6fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1374 | PC: 0x117b7c | FDE: 0x1e6ff8 | Size: 256 bytes [PyImport_ImportFrozenModuleObject]
// Khung tháo gỡ #1374 | Địa chỉ PC: 0x117b7c | Địa chỉ FDE: 0x1e6ff8 | Kích thước: 256 bytes
//   0x117b7c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x117b80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x117b84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x117b88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1374_0x117b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117b7cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1375 | PC: 0x117dac | FDE: 0x1e7020 | Size: 80 bytes [PyImport_ImportFrozenModule]
// Khung tháo gỡ #1375 | Địa chỉ PC: 0x117dac | Địa chỉ FDE: 0x1e7020 | Kích thước: 80 bytes
//   0x117dac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117db0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117db4: 910043FD  add      x29, sp, #0x10
//   0x117db8: 97FD120E  bl       #0x5c5f0
static inline uint64_t fde_func_1375_0x117dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117dacULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7020ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1376 | PC: 0x117dfc | FDE: 0x1e7040 | Size: 92 bytes [PyImport_Import]
// Khung tháo gỡ #1376 | Địa chỉ PC: 0x117dfc | Địa chỉ FDE: 0x1e7040 | Kích thước: 92 bytes
//   0x117dfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117e00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117e04: 910043FD  add      x29, sp, #0x10
//   0x117e08: 90000754  adrp     x20, #0x1ff000
static inline uint64_t fde_func_1376_0x117dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117dfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7040ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1377 | PC: 0x117e58 | FDE: 0x1e7060 | Size: 256 bytes [PyImport_ImportModuleNoBlock]
// Khung tháo gỡ #1377 | Địa chỉ PC: 0x117e58 | Địa chỉ FDE: 0x1e7060 | Kích thước: 256 bytes
//   0x117e58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117e5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117e60: 910043FD  add      x29, sp, #0x10
//   0x117e64: 97FD1197  bl       #0x5c4c0
static inline uint64_t fde_func_1377_0x117e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117e58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1378 | PC: 0x118164 | FDE: 0x1e70d0 | Size: 256 bytes [PyImport_ImportModuleLevelObject]
// Khung tháo gỡ #1378 | Địa chỉ PC: 0x118164 | Địa chỉ FDE: 0x1e70d0 | Kích thước: 256 bytes
//   0x118164: D10243FF  sub      sp, sp, #0x90
//   0x118168: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x11816c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x118170: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1378_0x118164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118164ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e70d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1379 | PC: 0x118aa8 | FDE: 0x1e7100 | Size: 112 bytes [PyImport_ImportModuleLevel]
// Khung tháo gỡ #1379 | Địa chỉ PC: 0x118aa8 | Địa chỉ FDE: 0x1e7100 | Kích thước: 112 bytes
//   0x118aa8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x118aac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x118ab0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x118ab4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1379_0x118aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118aa8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7100ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1380 | PC: 0x118b18 | FDE: 0x1e7128 | Size: 256 bytes [PyImport_ReloadModule]
// Khung tháo gỡ #1380 | Địa chỉ PC: 0x118b18 | Địa chỉ FDE: 0x1e7128 | Kích thước: 256 bytes
//   0x118b18: D10143FF  sub      sp, sp, #0x50
//   0x118b1c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x118b20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x118b24: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1380_0x118b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118b18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e7128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1381 | PC: 0x118c58 | FDE: 0x1e7150 | Size: 256 bytes [_PyImport_Import]
// Khung tháo gỡ #1381 | Địa chỉ PC: 0x118c58 | Địa chỉ FDE: 0x1e7150 | Kích thước: 256 bytes
//   0x118c58: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x118c5c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x118c60: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x118c64: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1381_0x118c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118c58ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1382 | PC: 0x118eb4 | FDE: 0x1e7178 | Size: 12 bytes [PyInit__imp]
// Khung tháo gỡ #1382 | Địa chỉ PC: 0x118eb4 | Địa chỉ FDE: 0x1e7178 | Kích thước: 12 bytes
//   0x118eb4: F00007E0  adrp     x0, #0x217000
//   0x118eb8: 911E2000  add      x0, x0, #0x788
//   0x118ebc: 17FCFED9  b        #0x58a20
static inline uint64_t fde_func_1382_0x118eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118eb4ULL ^ (static_cast<uint64_t>(0xf00007e0ULL) << 13);
    acc = (acc + a1 + 0x911e2000ULL) ^ 0x1e7178ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1383 | PC: 0x118ec0 | FDE: 0x1e7190 | Size: 256 bytes [_PyImport_BootstrapImp]
// Khung tháo gỡ #1383 | Địa chỉ PC: 0x118ec0 | Địa chỉ FDE: 0x1e7190 | Kích thước: 256 bytes
//   0x118ec0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x118ec4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x118ec8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x118ecc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1383_0x118ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118ec0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1384 | PC: 0x119150 | FDE: 0x1e71e0 | Size: 256 bytes [PyImport_ExtendInittab]
// Khung tháo gỡ #1384 | Địa chỉ PC: 0x119150 | Địa chỉ FDE: 0x1e71e0 | Kích thước: 256 bytes
//   0x119150: D10203FF  sub      sp, sp, #0x80
//   0x119154: F9001BF9  str      x25, [sp, #0x30]
//   0x119158: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x11915c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1384_0x119150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119150ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1e71e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1385 | PC: 0x119284 | FDE: 0x1e7208 | Size: 80 bytes [PyImport_AppendInittab]
// Khung tháo gỡ #1385 | Địa chỉ PC: 0x119284 | Địa chỉ FDE: 0x1e7208 | Kích thước: 80 bytes
//   0x119284: D10143FF  sub      sp, sp, #0x50
//   0x119288: F9001BF3  str      x19, [sp, #0x30]
//   0x11928c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x119290: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1385_0x119284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119284ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e7208ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1386 | PC: 0x1192d4 | FDE: 0x1e7228 | Size: 256 bytes [BDPythonImportEncryptName]
// Khung tháo gỡ #1386 | Địa chỉ PC: 0x1192d4 | Địa chỉ FDE: 0x1e7228 | Kích thước: 256 bytes
//   0x1192d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1192d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1192dc: 910043FD  add      x29, sp, #0x10
//   0x1192e0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1386_0x1192d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1192d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1387 | PC: 0x11a3d4 | FDE: 0x1e74d0 | Size: 256 bytes [_PyImport_LoadDynamicModuleWithSpec]
// Khung tháo gỡ #1387 | Địa chỉ PC: 0x11a3d4 | Địa chỉ FDE: 0x1e74d0 | Kích thước: 256 bytes
//   0x11a3d4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11a3d8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11a3dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11a3e0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1387_0x11a3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a3d4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e74d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1388 | PC: 0x11a968 | FDE: 0x1e7500 | Size: 256 bytes [_PyImport_FindSharedFuncptr]
// Khung tháo gỡ #1388 | Địa chỉ PC: 0x11a968 | Địa chỉ FDE: 0x1e7500 | Kích thước: 256 bytes
//   0x11a968: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x11a96c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11a970: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11a974: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1388_0x11a968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a968ULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1389 | PC: 0x11abf4 | FDE: 0x1e7528 | Size: 12 bytes [PyStatus_Ok]
// Khung tháo gỡ #1389 | Địa chỉ PC: 0x11abf4 | Địa chỉ FDE: 0x1e7528 | Kích thước: 12 bytes
//   0x11abf4: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11abf8: AD000100  stp      q0, q0, [x8]
//   0x11abfc: D65F03C0  ret      
static inline uint64_t fde_func_1389_0x11abf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11abf4ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad000100ULL) ^ 0x1e7528ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1390 | PC: 0x11ac00 | FDE: 0x1e7540 | Size: 20 bytes [PyStatus_Error]
// Khung tháo gỡ #1390 | Địa chỉ PC: 0x11ac00 | Địa chỉ FDE: 0x1e7540 | Kích thước: 20 bytes
//   0x11ac00: 52800029  mov      w9, #1
//   0x11ac04: A900811F  stp      xzr, x0, [x8, #8]
//   0x11ac08: B9000109  str      w9, [x8]
//   0x11ac0c: B900191F  str      wzr, [x8, #0x18]
static inline uint64_t fde_func_1390_0x11ac00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac00ULL ^ (static_cast<uint64_t>(0x52800029ULL) << 13);
    acc = (acc + a1 + 0xa900811fULL) ^ 0x1e7540ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1391 | PC: 0x11ac14 | FDE: 0x1e7558 | Size: 36 bytes [PyStatus_NoMemory]
// Khung tháo gỡ #1391 | Địa chỉ PC: 0x11ac14 | Địa chỉ FDE: 0x1e7558 | Kích thước: 36 bytes
//   0x11ac14: B000044A  adrp     x10, #0x1a3000
//   0x11ac18: 913CB14A  add      x10, x10, #0xf2c
//   0x11ac1c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11ac20: 52800029  mov      w9, #1
static inline uint64_t fde_func_1391_0x11ac14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac14ULL ^ (static_cast<uint64_t>(0xb000044aULL) << 13);
    acc = (acc + a1 + 0x913cb14aULL) ^ 0x1e7558ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1392 | PC: 0x11ac38 | FDE: 0x1e7570 | Size: 24 bytes [PyStatus_Exit]
// Khung tháo gỡ #1392 | Địa chỉ PC: 0x11ac38 | Địa chỉ FDE: 0x1e7570 | Kích thước: 24 bytes
//   0x11ac38: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11ac3c: 52800049  mov      w9, #2
//   0x11ac40: AD000100  stp      q0, q0, [x8]
//   0x11ac44: B9000109  str      w9, [x8]
static inline uint64_t fde_func_1392_0x11ac38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac38ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0x52800049ULL) ^ 0x1e7570ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1393 | PC: 0x11ac50 | FDE: 0x1e7588 | Size: 16 bytes [PyStatus_IsError]
// Khung tháo gỡ #1393 | Địa chỉ PC: 0x11ac50 | Địa chỉ FDE: 0x1e7588 | Kích thước: 16 bytes
//   0x11ac50: B9400008  ldr      w8, [x0]
//   0x11ac54: 7100051F  cmp      w8, #1
//   0x11ac58: 1A9F17E0  cset     w0, eq
//   0x11ac5c: D65F03C0  ret      
static inline uint64_t fde_func_1393_0x11ac50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac50ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x1e7588ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1394 | PC: 0x11ac60 | FDE: 0x1e75a0 | Size: 16 bytes [PyStatus_IsExit]
// Khung tháo gỡ #1394 | Địa chỉ PC: 0x11ac60 | Địa chỉ FDE: 0x1e75a0 | Kích thước: 16 bytes
//   0x11ac60: B9400008  ldr      w8, [x0]
//   0x11ac64: 7100091F  cmp      w8, #2
//   0x11ac68: 1A9F17E0  cset     w0, eq
//   0x11ac6c: D65F03C0  ret      
static inline uint64_t fde_func_1394_0x11ac60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac60ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x1e75a0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1395 | PC: 0x11ac70 | FDE: 0x1e75b8 | Size: 16 bytes [PyStatus_Exception]
// Khung tháo gỡ #1395 | Địa chỉ PC: 0x11ac70 | Địa chỉ FDE: 0x1e75b8 | Kích thước: 16 bytes
//   0x11ac70: B9400008  ldr      w8, [x0]
//   0x11ac74: 7100011F  cmp      w8, #0
//   0x11ac78: 1A9F07E0  cset     w0, ne
//   0x11ac7c: D65F03C0  ret      
static inline uint64_t fde_func_1395_0x11ac70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac70ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x1e75b8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1396 | PC: 0x11ac80 | FDE: 0x1e75d0 | Size: 120 bytes [_PyErr_SetFromPyStatus]
// Khung tháo gỡ #1396 | Địa chỉ PC: 0x11ac80 | Địa chỉ FDE: 0x1e75d0 | Kích thước: 120 bytes
//   0x11ac80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11ac84: 910003FD  mov      x29, sp
//   0x11ac88: B9400009  ldr      w9, [x0]
//   0x11ac8c: 7100053F  cmp      w9, #1
static inline uint64_t fde_func_1396_0x11ac80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac80ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e75d0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1397 | PC: 0x11acf8 | FDE: 0x1e75f0 | Size: 84 bytes [_PyWideStringList_Clear]
// Khung tháo gỡ #1397 | Địa chỉ PC: 0x11acf8 | Địa chỉ FDE: 0x1e75f0 | Kích thước: 84 bytes
//   0x11acf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11acfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11ad00: 910043FD  add      x29, sp, #0x10
//   0x11ad04: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1397_0x11acf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11acf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e75f0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1398 | PC: 0x11ad4c | FDE: 0x1e7610 | Size: 256 bytes [_PyWideStringList_Copy]
// Khung tháo gỡ #1398 | Địa chỉ PC: 0x11ad4c | Địa chỉ FDE: 0x1e7610 | Kích thước: 256 bytes
//   0x11ad4c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11ad50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11ad54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11ad58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1398_0x11ad4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ad4cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1399 | PC: 0x11ae70 | FDE: 0x1e7638 | Size: 256 bytes [PyWideStringList_Insert]
// Khung tháo gỡ #1399 | Địa chỉ PC: 0x11ae70 | Địa chỉ FDE: 0x1e7638 | Kích thước: 256 bytes
//   0x11ae70: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x11ae74: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11ae78: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11ae7c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1399_0x11ae70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ae70ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1400 | PC: 0x11af74 | FDE: 0x1e7660 | Size: 12 bytes [PyWideStringList_Append]
// Khung tháo gỡ #1400 | Địa chỉ PC: 0x11af74 | Địa chỉ FDE: 0x1e7660 | Kích thước: 12 bytes
//   0x11af74: AA0103E2  mov      x2, x1
//   0x11af78: F9400001  ldr      x1, [x0]
//   0x11af7c: 17FCF51D  b        #0x583f0
static inline uint64_t fde_func_1400_0x11af74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11af74ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x1e7660ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1401 | PC: 0x11af80 | FDE: 0x1e7678 | Size: 116 bytes [_PyWideStringList_Extend]
// Khung tháo gỡ #1401 | Địa chỉ PC: 0x11af80 | Địa chỉ FDE: 0x1e7678 | Kích thước: 116 bytes
//   0x11af80: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11af84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11af88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11af8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1401_0x11af80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11af80ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7678ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1402 | PC: 0x11aff4 | FDE: 0x1e76a0 | Size: 148 bytes [_PyWideStringList_AsList]
// Khung tháo gỡ #1402 | Địa chỉ PC: 0x11aff4 | Địa chỉ FDE: 0x1e76a0 | Kích thước: 148 bytes
//   0x11aff4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11aff8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11affc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11b000: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1402_0x11aff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11aff4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e76a0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1403 | PC: 0x11b088 | FDE: 0x1e76c0 | Size: 216 bytes [Py_SetStandardStreamEncoding]
// Khung tháo gỡ #1403 | Địa chỉ PC: 0x11b088 | Địa chỉ FDE: 0x1e76c0 | Kích thước: 216 bytes
//   0x11b088: D10183FF  sub      sp, sp, #0x60
//   0x11b08c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b090: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b094: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1403_0x11b088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b088ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e76c0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1404 | PC: 0x11b160 | FDE: 0x1e76e8 | Size: 128 bytes [_Py_ClearStandardStreamEncoding]
// Khung tháo gỡ #1404 | Địa chỉ PC: 0x11b160 | Địa chỉ FDE: 0x1e76e8 | Kích thước: 128 bytes
//   0x11b160: D10143FF  sub      sp, sp, #0x50
//   0x11b164: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x11b168: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x11b16c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1404_0x11b160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b160ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e76e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1405 | PC: 0x11b1e0 | FDE: 0x1e7708 | Size: 164 bytes [_Py_ClearArgcArgv]
// Khung tháo gỡ #1405 | Địa chỉ PC: 0x11b1e0 | Địa chỉ FDE: 0x1e7708 | Kích thước: 164 bytes
//   0x11b1e0: D10183FF  sub      sp, sp, #0x60
//   0x11b1e4: F9001BF5  str      x21, [sp, #0x30]
//   0x11b1e8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b1ec: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1405_0x11b1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b1e0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e7708ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1406 | PC: 0x11b284 | FDE: 0x1e7728 | Size: 28 bytes [Py_GetArgcArgv]
// Khung tháo gỡ #1406 | Địa chỉ PC: 0x11b284 | Địa chỉ FDE: 0x1e7728 | Kích thước: 28 bytes
//   0x11b284: D0000848  adrp     x8, #0x225000
//   0x11b288: 910C4108  add      x8, x8, #0x310
//   0x11b28c: F9400109  ldr      x9, [x8]
//   0x11b290: B9000009  str      w9, [x0]
static inline uint64_t fde_func_1406_0x11b284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b284ULL ^ (static_cast<uint64_t>(0xd0000848ULL) << 13);
    acc = (acc + a1 + 0x910c4108ULL) ^ 0x1e7728ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1407 | PC: 0x11b2a0 | FDE: 0x1e7740 | Size: 256 bytes [PyConfig_Clear]
// Khung tháo gỡ #1407 | Địa chỉ PC: 0x11b2a0 | Địa chỉ FDE: 0x1e7740 | Kích thước: 256 bytes
//   0x11b2a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11b2a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11b2a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11b2ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1407_0x11b2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b2a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1408 | PC: 0x11b4d8 | FDE: 0x1e7760 | Size: 156 bytes [_PyConfig_InitCompatConfig]
// Khung tháo gỡ #1408 | Địa chỉ PC: 0x11b4d8 | Địa chỉ FDE: 0x1e7760 | Kích thước: 156 bytes
//   0x11b4d8: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11b4dc: AD0B0000  stp      q0, q0, [x0, #0x160]
//   0x11b4e0: AD0A0000  stp      q0, q0, [x0, #0x140]
//   0x11b4e4: AD090000  stp      q0, q0, [x0, #0x120]
static inline uint64_t fde_func_1408_0x11b4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b4d8ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad0b0000ULL) ^ 0x1e7760ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1409 | PC: 0x11b574 | FDE: 0x1e7778 | Size: 172 bytes [PyConfig_InitPythonConfig]
// Khung tháo gỡ #1409 | Địa chỉ PC: 0x11b574 | Địa chỉ FDE: 0x1e7778 | Kích thước: 172 bytes
//   0x11b574: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11b578: AD0B0000  stp      q0, q0, [x0, #0x160]
//   0x11b57c: AD0A0000  stp      q0, q0, [x0, #0x140]
//   0x11b580: AD090000  stp      q0, q0, [x0, #0x120]
static inline uint64_t fde_func_1409_0x11b574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b574ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad0b0000ULL) ^ 0x1e7778ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1410 | PC: 0x11b620 | FDE: 0x1e7790 | Size: 148 bytes [PyConfig_InitIsolatedConfig]
// Khung tháo gỡ #1410 | Địa chỉ PC: 0x11b620 | Địa chỉ FDE: 0x1e7790 | Kích thước: 148 bytes
//   0x11b620: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11b624: D2C00028  mov      x8, #0x100000000
//   0x11b628: AD0B0000  stp      q0, q0, [x0, #0x160]
//   0x11b62c: AD0A0000  stp      q0, q0, [x0, #0x140]
static inline uint64_t fde_func_1410_0x11b620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b620ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xd2c00028ULL) ^ 0x1e7790ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1411 | PC: 0x11b6b4 | FDE: 0x1e77a8 | Size: 204 bytes [PyConfig_SetString]
// Khung tháo gỡ #1411 | Địa chỉ PC: 0x11b6b4 | Địa chỉ FDE: 0x1e77a8 | Kích thước: 204 bytes
//   0x11b6b4: D10183FF  sub      sp, sp, #0x60
//   0x11b6b8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b6bc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b6c0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1411_0x11b6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b6b4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e77a8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1412 | PC: 0x11b780 | FDE: 0x1e77d0 | Size: 228 bytes [PyConfig_SetBytesString]
// Khung tháo gỡ #1412 | Địa chỉ PC: 0x11b780 | Địa chỉ FDE: 0x1e77d0 | Kích thước: 228 bytes
//   0x11b780: D10183FF  sub      sp, sp, #0x60
//   0x11b784: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b788: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b78c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1412_0x11b780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b780ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e77d0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1413 | PC: 0x11b864 | FDE: 0x1e77f8 | Size: 256 bytes [_PyConfig_Copy]
// Khung tháo gỡ #1413 | Địa chỉ PC: 0x11b864 | Địa chỉ FDE: 0x1e77f8 | Kích thước: 256 bytes
//   0x11b864: D10203FF  sub      sp, sp, #0x80
//   0x11b868: F9001BF9  str      x25, [sp, #0x30]
//   0x11b86c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x11b870: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1413_0x11b864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b864ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1e77f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1414 | PC: 0x11be8c | FDE: 0x1e7820 | Size: 256 bytes [_PyConfig_AsDict]
// Khung tháo gỡ #1414 | Địa chỉ PC: 0x11be8c | Địa chỉ FDE: 0x1e7820 | Kích thước: 256 bytes
//   0x11be8c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11be90: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11be94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11be98: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1414_0x11be8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11be8cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1415 | PC: 0x11d190 | FDE: 0x1e7848 | Size: 256 bytes [_PyConfig_FromDict]
// Khung tháo gỡ #1415 | Địa chỉ PC: 0x11d190 | Địa chỉ FDE: 0x1e7848 | Kích thước: 256 bytes
//   0x11d190: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11d194: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11d198: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11d19c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1415_0x11d190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d190ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1416 | PC: 0x11e2ec | FDE: 0x1e78d8 | Size: 256 bytes [_PyConfig_Write]
// Khung tháo gỡ #1416 | Địa chỉ PC: 0x11e2ec | Địa chỉ FDE: 0x1e78d8 | Kích thước: 256 bytes
//   0x11e2ec: D10203FF  sub      sp, sp, #0x80
//   0x11e2f0: F90023F7  str      x23, [sp, #0x40]
//   0x11e2f4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x11e2f8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1416_0x11e2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e2ecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1e78d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1417 | PC: 0x11e5ec | FDE: 0x1e7900 | Size: 132 bytes [_PyConfig_SetPyArgv]
// Khung tháo gỡ #1417 | Địa chỉ PC: 0x11e5ec | Địa chỉ FDE: 0x1e7900 | Kích thước: 132 bytes
//   0x11e5ec: D10183FF  sub      sp, sp, #0x60
//   0x11e5f0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11e5f4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11e5f8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1417_0x11e5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e5ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e7900ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1418 | PC: 0x11e670 | FDE: 0x1e7928 | Size: 148 bytes [PyConfig_SetBytesArgv]
// Khung tháo gỡ #1418 | Địa chỉ PC: 0x11e670 | Địa chỉ FDE: 0x1e7928 | Kích thước: 148 bytes
//   0x11e670: D10203FF  sub      sp, sp, #0x80
//   0x11e674: F9002BF5  str      x21, [sp, #0x50]
//   0x11e678: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x11e67c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1418_0x11e670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e670ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1e7928ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1419 | PC: 0x11e704 | FDE: 0x1e7948 | Size: 144 bytes [PyConfig_SetArgv]
// Khung tháo gỡ #1419 | Địa chỉ PC: 0x11e704 | Địa chỉ FDE: 0x1e7948 | Kích thước: 144 bytes
//   0x11e704: D10203FF  sub      sp, sp, #0x80
//   0x11e708: F9002BF5  str      x21, [sp, #0x50]
//   0x11e70c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x11e710: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1419_0x11e704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e704ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1e7948ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1420 | PC: 0x11e794 | FDE: 0x1e7968 | Size: 208 bytes [PyConfig_SetWideStringList]
// Khung tháo gỡ #1420 | Địa chỉ PC: 0x11e794 | Địa chỉ FDE: 0x1e7968 | Kích thước: 208 bytes
//   0x11e794: D10203FF  sub      sp, sp, #0x80
//   0x11e798: F90023F7  str      x23, [sp, #0x40]
//   0x11e79c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x11e7a0: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1420_0x11e794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e794ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1e7968ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1421 | PC: 0x11e864 | FDE: 0x1e7990 | Size: 256 bytes [_PyConfig_Read]
// Khung tháo gỡ #1421 | Địa chỉ PC: 0x11e864 | Địa chỉ FDE: 0x1e7990 | Kích thước: 256 bytes
//   0x11e864: D105C3FF  sub      sp, sp, #0x170
//   0x11e868: FD0083E8  str      d8, [sp, #0x100]
//   0x11e86c: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x11e870: A91267FA  stp      x26, x25, [sp, #0x120]
static inline uint64_t fde_func_1421_0x11e864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e864ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0083e8ULL) ^ 0x1e7990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1422 | PC: 0x120828 | FDE: 0x1e79c0 | Size: 8 bytes [PyConfig_Read]
// Khung tháo gỡ #1422 | Địa chỉ PC: 0x120828 | Địa chỉ FDE: 0x1e79c0 | Kích thước: 8 bytes
//   0x120828: 52800021  mov      w1, #1
//   0x12082c: 17FCDFE1  b        #0x587b0
static inline uint64_t fde_func_1422_0x120828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120828ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x17fcdfe1ULL) ^ 0x1e79c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1423 | PC: 0x120830 | FDE: 0x1e79d8 | Size: 256 bytes [_Py_GetConfigsAsDict]
// Khung tháo gỡ #1423 | Địa chỉ PC: 0x120830 | Địa chỉ FDE: 0x1e79d8 | Kích thước: 256 bytes
//   0x120830: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x120834: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x120838: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12083c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1423_0x120830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120830ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e79d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1424 | PC: 0x121000 | FDE: 0x1e7a00 | Size: 256 bytes [_Py_DumpPathConfig]
// Khung tháo gỡ #1424 | Địa chỉ PC: 0x121000 | Địa chỉ FDE: 0x1e7a00 | Kích thước: 256 bytes
//   0x121000: D10183FF  sub      sp, sp, #0x60
//   0x121004: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x121008: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12100c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1424_0x121000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121000ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e7a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1425 | PC: 0x1214bc | FDE: 0x1e7a50 | Size: 184 bytes [bd_marshal_dump_impl_extern]
// Khung tháo gỡ #1425 | Địa chỉ PC: 0x1214bc | Địa chỉ FDE: 0x1e7a50 | Kích thước: 184 bytes
//   0x1214bc: D10143FF  sub      sp, sp, #0x50
//   0x1214c0: F90013F5  str      x21, [sp, #0x20]
//   0x1214c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1214c8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1425_0x1214bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1214bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e7a50ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1426 | PC: 0x121574 | FDE: 0x1e7a70 | Size: 256 bytes [PyMarshal_WriteLongToFile]
// Khung tháo gỡ #1426 | Địa chỉ PC: 0x121574 | Địa chỉ FDE: 0x1e7a70 | Kích thước: 256 bytes
//   0x121574: D101C3FF  sub      sp, sp, #0x70
//   0x121578: F9002BF3  str      x19, [sp, #0x50]
//   0x12157c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x121580: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1426_0x121574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121574ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x1e7a70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1427 | PC: 0x12197c | FDE: 0x1e7ab8 | Size: 256 bytes [PyMarshal_WriteObjectToFile]
// Khung tháo gỡ #1427 | Địa chỉ PC: 0x12197c | Địa chỉ FDE: 0x1e7ab8 | Kích thước: 256 bytes
//   0x12197c: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x121980: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x121984: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x121988: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1427_0x12197c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12197cULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1428 | PC: 0x123f48 | FDE: 0x1e7b10 | Size: 128 bytes [PyMarshal_ReadShortFromFile]
// Khung tháo gỡ #1428 | Địa chỉ PC: 0x123f48 | Địa chỉ FDE: 0x1e7b10 | Kích thước: 128 bytes
//   0x123f48: D10183FF  sub      sp, sp, #0x60
//   0x123f4c: F90023F3  str      x19, [sp, #0x40]
//   0x123f50: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x123f54: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1428_0x123f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123f48ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x1e7b10ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1429 | PC: 0x123fc8 | FDE: 0x1e7b30 | Size: 136 bytes [PyMarshal_ReadLongFromFile]
// Khung tháo gỡ #1429 | Địa chỉ PC: 0x123fc8 | Địa chỉ FDE: 0x1e7b30 | Kích thước: 136 bytes
//   0x123fc8: D10183FF  sub      sp, sp, #0x60
//   0x123fcc: F90023F3  str      x19, [sp, #0x40]
//   0x123fd0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x123fd4: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1429_0x123fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123fc8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x1e7b30ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1430 | PC: 0x124050 | FDE: 0x1e7b50 | Size: 256 bytes [PyMarshal_ReadLastObjectFromFile]
// Khung tháo gỡ #1430 | Địa chỉ PC: 0x124050 | Địa chỉ FDE: 0x1e7b50 | Kích thước: 256 bytes
//   0x124050: D10303FF  sub      sp, sp, #0xc0
//   0x124054: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x124058: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x12405c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1430_0x124050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124050ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x1e7b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1431 | PC: 0x1241a4 | FDE: 0x1e7b78 | Size: 160 bytes [PyMarshal_ReadObjectFromString]
// Khung tháo gỡ #1431 | Địa chỉ PC: 0x1241a4 | Địa chỉ FDE: 0x1e7b78 | Kích thước: 160 bytes
//   0x1241a4: D101C3FF  sub      sp, sp, #0x70
//   0x1241a8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1241ac: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1241b0: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1431_0x1241a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1241a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e7b78ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1432 | PC: 0x124244 | FDE: 0x1e7b98 | Size: 256 bytes [PyMarshal_ReadObjectFromFile]
// Khung tháo gỡ #1432 | Địa chỉ PC: 0x124244 | Địa chỉ FDE: 0x1e7b98 | Kích thước: 256 bytes
//   0x124244: D101C3FF  sub      sp, sp, #0x70
//   0x124248: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12424c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x124250: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1432_0x124244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124244ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e7b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1433 | PC: 0x1243b0 | FDE: 0x1e7bd8 | Size: 256 bytes [PyMarshal_WriteObjectToString]
// Khung tháo gỡ #1433 | Địa chỉ PC: 0x1243b0 | Địa chỉ FDE: 0x1e7bd8 | Kích thước: 256 bytes
//   0x1243b0: D10203FF  sub      sp, sp, #0x80
//   0x1243b4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1243b8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1243bc: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1433_0x1243b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1243b0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1e7bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1434 | PC: 0x124570 | FDE: 0x1e7c00 | Size: 256 bytes [PyMarshal_Init]
// Khung tháo gỡ #1434 | Địa chỉ PC: 0x124570 | Địa chỉ FDE: 0x1e7c00 | Kích thước: 256 bytes
//   0x124570: F0000780  adrp     x0, #0x217000
//   0x124574: 912BE000  add      x0, x0, #0xaf8
//   0x124578: 17FCD12A  b        #0x58a20
//   0x12457c: B40000A0  cbz      x0, #0x124590
static inline uint64_t fde_func_1434_0x124570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124570ULL ^ (static_cast<uint64_t>(0xf0000780ULL) << 13);
    acc = (acc + a1 + 0x912be000ULL) ^ 0x1e7c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1435 | PC: 0x1268f4 | FDE: 0x1e7db8 | Size: 148 bytes [_Py_convert_optional_to_ssize_t]
// Khung tháo gỡ #1435 | Địa chỉ PC: 0x1268f4 | Địa chỉ FDE: 0x1e7db8 | Kích thước: 148 bytes
//   0x1268f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1268f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1268fc: 910043FD  add      x29, sp, #0x10
//   0x126900: B00006C8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1435_0x1268f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1268f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7db8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1436 | PC: 0x126988 | FDE: 0x1e7dd8 | Size: 240 bytes [Py_BuildValue]
// Khung tháo gỡ #1436 | Địa chỉ PC: 0x126988 | Địa chỉ FDE: 0x1e7dd8 | Kích thước: 240 bytes
//   0x126988: D10543FF  sub      sp, sp, #0x150
//   0x12698c: A9134FFC  stp      x28, x19, [sp, #0x130]
//   0x126990: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x126994: 910503FD  add      x29, sp, #0x140
static inline uint64_t fde_func_1436_0x126988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126988ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9134ffcULL) ^ 0x1e7dd8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1437 | PC: 0x126a78 | FDE: 0x1e7df8 | Size: 244 bytes [_Py_BuildValue_SizeT]
// Khung tháo gỡ #1437 | Địa chỉ PC: 0x126a78 | Địa chỉ FDE: 0x1e7df8 | Kích thước: 244 bytes
//   0x126a78: D10543FF  sub      sp, sp, #0x150
//   0x126a7c: A9134FFC  stp      x28, x19, [sp, #0x130]
//   0x126a80: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x126a84: 910503FD  add      x29, sp, #0x140
static inline uint64_t fde_func_1437_0x126a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126a78ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9134ffcULL) ^ 0x1e7df8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1438 | PC: 0x126b6c | FDE: 0x1e7e18 | Size: 172 bytes [Py_VaBuildValue]
// Khung tháo gỡ #1438 | Địa chỉ PC: 0x126b6c | Địa chỉ FDE: 0x1e7e18 | Kích thước: 172 bytes
//   0x126b6c: D101C3FF  sub      sp, sp, #0x70
//   0x126b70: F9002BF3  str      x19, [sp, #0x50]
//   0x126b74: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x126b78: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1438_0x126b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126b6cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x1e7e18ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1439 | PC: 0x126c18 | FDE: 0x1e7e38 | Size: 176 bytes [_Py_VaBuildValue_SizeT]
// Khung tháo gỡ #1439 | Địa chỉ PC: 0x126c18 | Địa chỉ FDE: 0x1e7e38 | Kích thước: 176 bytes
//   0x126c18: D101C3FF  sub      sp, sp, #0x70
//   0x126c1c: F9002BF3  str      x19, [sp, #0x50]
//   0x126c20: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x126c24: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1439_0x126c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126c18ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x1e7e38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1440 | PC: 0x126cc8 | FDE: 0x1e7e58 | Size: 256 bytes [_Py_VaBuildStack]
// Khung tháo gỡ #1440 | Địa chỉ PC: 0x126cc8 | Địa chỉ FDE: 0x1e7e58 | Kích thước: 256 bytes
//   0x126cc8: D10143FF  sub      sp, sp, #0x50
//   0x126ccc: F9001BF3  str      x19, [sp, #0x30]
//   0x126cd0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x126cd4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1440_0x126cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126cc8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e7e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1441 | PC: 0x126ebc | FDE: 0x1e7ea8 | Size: 88 bytes [_Py_VaBuildStack_SizeT]
// Khung tháo gỡ #1441 | Địa chỉ PC: 0x126ebc | Địa chỉ FDE: 0x1e7ea8 | Kích thước: 88 bytes
//   0x126ebc: D10143FF  sub      sp, sp, #0x50
//   0x126ec0: F9001BF3  str      x19, [sp, #0x30]
//   0x126ec4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x126ec8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1441_0x126ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126ebcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e7ea8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1442 | PC: 0x126f14 | FDE: 0x1e7ec8 | Size: 220 bytes [PyModule_AddObjectRef]
// Khung tháo gỡ #1442 | Địa chỉ PC: 0x126f14 | Địa chỉ FDE: 0x1e7ec8 | Kích thước: 220 bytes
//   0x126f14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x126f18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x126f1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x126f20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1442_0x126f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126f14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7ec8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1443 | PC: 0x126ff0 | FDE: 0x1e7ee8 | Size: 68 bytes [PyModule_AddObject]
// Khung tháo gỡ #1443 | Địa chỉ PC: 0x126ff0 | Địa chỉ FDE: 0x1e7ee8 | Kích thước: 68 bytes
//   0x126ff0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x126ff4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x126ff8: 910043FD  add      x29, sp, #0x10
//   0x126ffc: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_1443_0x126ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126ff0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7ee8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1444 | PC: 0x127034 | FDE: 0x1e7f08 | Size: 112 bytes [PyModule_AddIntConstant]
// Khung tháo gỡ #1444 | Địa chỉ PC: 0x127034 | Địa chỉ FDE: 0x1e7f08 | Kích thước: 112 bytes
//   0x127034: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x127038: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12703c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x127040: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1444_0x127034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127034ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7f08ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1445 | PC: 0x1270a4 | FDE: 0x1e7f28 | Size: 112 bytes [PyModule_AddStringConstant]
// Khung tháo gỡ #1445 | Địa chỉ PC: 0x1270a4 | Địa chỉ FDE: 0x1e7f28 | Kích thước: 112 bytes
//   0x1270a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1270a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1270ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1270b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1445_0x1270a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1270a4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7f28ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1446 | PC: 0x127114 | FDE: 0x1e7f48 | Size: 256 bytes [PyModule_AddType]
// Khung tháo gỡ #1446 | Địa chỉ PC: 0x127114 | Địa chỉ FDE: 0x1e7f48 | Kích thước: 256 bytes
//   0x127114: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x127118: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12711c: 910043FD  add      x29, sp, #0x10
//   0x127120: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1446_0x127114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127114ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7f48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1447 | PC: 0x127e30 | FDE: 0x1e8010 | Size: 208 bytes [PyOS_snprintf]
// Khung tháo gỡ #1447 | Địa chỉ PC: 0x127e30 | Địa chỉ FDE: 0x1e8010 | Kích thước: 208 bytes
//   0x127e30: D10543FF  sub      sp, sp, #0x150
//   0x127e34: A91257FC  stp      x28, x21, [sp, #0x120]
//   0x127e38: A9134FF4  stp      x20, x19, [sp, #0x130]
//   0x127e3c: A9147BFD  stp      x29, x30, [sp, #0x140]
static inline uint64_t fde_func_1447_0x127e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127e30ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91257fcULL) ^ 0x1e8010ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1448 | PC: 0x127f00 | FDE: 0x1e8038 | Size: 136 bytes [PyOS_vsnprintf]
// Khung tháo gỡ #1448 | Địa chỉ PC: 0x127f00 | Địa chỉ FDE: 0x1e8038 | Kích thước: 136 bytes
//   0x127f00: D10183FF  sub      sp, sp, #0x60
//   0x127f04: F9001BF5  str      x21, [sp, #0x30]
//   0x127f08: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x127f0c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1448_0x127f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127f00ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e8038ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1449 | PC: 0x127f88 | FDE: 0x1e8058 | Size: 256 bytes [PyOS_strtoul]
// Khung tháo gỡ #1449 | Địa chỉ PC: 0x127f88 | Địa chỉ FDE: 0x1e8058 | Kích thước: 256 bytes
//   0x127f88: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x127f8c: 910003FD  mov      x29, sp
//   0x127f90: 900006C8  adrp     x8, #0x1ff000
//   0x127f94: 3940000A  ldrb     w10, [x0]
static inline uint64_t fde_func_1449_0x127f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127f88ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1450 | PC: 0x128248 | FDE: 0x1e8078 | Size: 152 bytes [PyOS_strtol]
// Khung tháo gỡ #1450 | Địa chỉ PC: 0x128248 | Địa chỉ FDE: 0x1e8078 | Kích thước: 152 bytes
//   0x128248: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12824c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x128250: 910043FD  add      x29, sp, #0x10
//   0x128254: 39400013  ldrb     w19, [x0]
static inline uint64_t fde_func_1450_0x128248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128248ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8078ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1451 | PC: 0x1282e0 | FDE: 0x1e8098 | Size: 192 bytes [_PyPathConfig_ClearGlobal]
// Khung tháo gỡ #1451 | Địa chỉ PC: 0x1282e0 | Địa chỉ FDE: 0x1e8098 | Kích thước: 192 bytes
//   0x1282e0: D10203FF  sub      sp, sp, #0x80
//   0x1282e4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1282e8: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x1282ec: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_1451_0x1282e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1282e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9064ff4ULL) ^ 0x1e8098ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1452 | PC: 0x1283a0 | FDE: 0x1e80b8 | Size: 256 bytes [_PyPathConfig_AsDict]
// Khung tháo gỡ #1452 | Địa chỉ PC: 0x1283a0 | Địa chỉ FDE: 0x1e80b8 | Kích thước: 256 bytes
//   0x1283a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1283a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1283a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1283ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1452_0x1283a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1283a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e80b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1453 | PC: 0x128650 | FDE: 0x1e80e0 | Size: 256 bytes [_PyConfig_WritePathConfig]
// Khung tháo gỡ #1453 | Địa chỉ PC: 0x128650 | Địa chỉ FDE: 0x1e80e0 | Kích thước: 256 bytes
//   0x128650: AA0003E1  mov      x1, x0
//   0x128654: F00006A0  adrp     x0, #0x1ff000
//   0x128658: F9444400  ldr      x0, [x0, #0x888]
//   0x12865c: 14000001  b        #0x128660
static inline uint64_t fde_func_1453_0x128650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128650ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xf00006a0ULL) ^ 0x1e80e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1454 | PC: 0x1288fc | FDE: 0x1e8128 | Size: 256 bytes [_PyConfig_InitPathConfig]
// Khung tháo gỡ #1454 | Địa chỉ PC: 0x1288fc | Địa chỉ FDE: 0x1e8128 | Kích thước: 256 bytes
//   0x1288fc: D10483FF  sub      sp, sp, #0x120
//   0x128900: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x128904: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x128908: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1454_0x1288fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1288fcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1e8128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1455 | PC: 0x128da0 | FDE: 0x1e8158 | Size: 256 bytes [Py_SetPath]
// Khung tháo gỡ #1455 | Địa chỉ PC: 0x128da0 | Địa chỉ FDE: 0x1e8158 | Kích thước: 256 bytes
//   0x128da0: D10183FF  sub      sp, sp, #0x60
//   0x128da4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x128da8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x128dac: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1455_0x128da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128da0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e8158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1456 | PC: 0x128ef0 | FDE: 0x1e81a0 | Size: 152 bytes [Py_SetPythonHome]
// Khung tháo gỡ #1456 | Địa chỉ PC: 0x128ef0 | Địa chỉ FDE: 0x1e81a0 | Kích thước: 152 bytes
//   0x128ef0: D10183FF  sub      sp, sp, #0x60
//   0x128ef4: F9001BF5  str      x21, [sp, #0x30]
//   0x128ef8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x128efc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1456_0x128ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128ef0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e81a0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1457 | PC: 0x128f88 | FDE: 0x1e81c0 | Size: 160 bytes [Py_SetProgramName]
// Khung tháo gỡ #1457 | Địa chỉ PC: 0x128f88 | Địa chỉ FDE: 0x1e81c0 | Kích thước: 160 bytes
//   0x128f88: D10183FF  sub      sp, sp, #0x60
//   0x128f8c: F9001BF5  str      x21, [sp, #0x30]
//   0x128f90: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x128f94: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1457_0x128f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128f88ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e81c0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1458 | PC: 0x129028 | FDE: 0x1e81e0 | Size: 160 bytes [_Py_SetProgramFullPath]
// Khung tháo gỡ #1458 | Địa chỉ PC: 0x129028 | Địa chỉ FDE: 0x1e81e0 | Kích thước: 160 bytes
//   0x129028: D10183FF  sub      sp, sp, #0x60
//   0x12902c: F9001BF5  str      x21, [sp, #0x30]
//   0x129030: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x129034: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1458_0x129028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129028ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e81e0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1459 | PC: 0x1290c8 | FDE: 0x1e8200 | Size: 16 bytes [Py_GetPath]
// Khung tháo gỡ #1459 | Địa chỉ PC: 0x1290c8 | Địa chỉ FDE: 0x1e8200 | Kích thước: 16 bytes
//   0x1290c8: D00006A8  adrp     x8, #0x1ff000
//   0x1290cc: F9444508  ldr      x8, [x8, #0x888]
//   0x1290d0: F9400D00  ldr      x0, [x8, #0x18]
//   0x1290d4: D65F03C0  ret      
static inline uint64_t fde_func_1459_0x1290c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290c8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8200ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1460 | PC: 0x1290d8 | FDE: 0x1e8218 | Size: 16 bytes [Py_GetPrefix]
// Khung tháo gỡ #1460 | Địa chỉ PC: 0x1290d8 | Địa chỉ FDE: 0x1e8218 | Kích thước: 16 bytes
//   0x1290d8: D00006A8  adrp     x8, #0x1ff000
//   0x1290dc: F9444508  ldr      x8, [x8, #0x888]
//   0x1290e0: F9400500  ldr      x0, [x8, #8]
//   0x1290e4: D65F03C0  ret      
static inline uint64_t fde_func_1460_0x1290d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290d8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8218ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1461 | PC: 0x1290e8 | FDE: 0x1e8230 | Size: 16 bytes [Py_GetExecPrefix]
// Khung tháo gỡ #1461 | Địa chỉ PC: 0x1290e8 | Địa chỉ FDE: 0x1e8230 | Kích thước: 16 bytes
//   0x1290e8: D00006A8  adrp     x8, #0x1ff000
//   0x1290ec: F9444508  ldr      x8, [x8, #0x888]
//   0x1290f0: F9400900  ldr      x0, [x8, #0x10]
//   0x1290f4: D65F03C0  ret      
static inline uint64_t fde_func_1461_0x1290e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290e8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8230ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1462 | PC: 0x1290f8 | FDE: 0x1e8248 | Size: 16 bytes [Py_GetProgramFullPath]
// Khung tháo gỡ #1462 | Địa chỉ PC: 0x1290f8 | Địa chỉ FDE: 0x1e8248 | Kích thước: 16 bytes
//   0x1290f8: D00006A8  adrp     x8, #0x1ff000
//   0x1290fc: F9444508  ldr      x8, [x8, #0x888]
//   0x129100: F9400100  ldr      x0, [x8]
//   0x129104: D65F03C0  ret      
static inline uint64_t fde_func_1462_0x1290f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290f8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8248ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1463 | PC: 0x129108 | FDE: 0x1e8260 | Size: 16 bytes [Py_GetPythonHome]
// Khung tháo gỡ #1463 | Địa chỉ PC: 0x129108 | Địa chỉ FDE: 0x1e8260 | Kích thước: 16 bytes
//   0x129108: D00006A8  adrp     x8, #0x1ff000
//   0x12910c: F9444508  ldr      x8, [x8, #0x888]
//   0x129110: F9401500  ldr      x0, [x8, #0x28]
//   0x129114: D65F03C0  ret      
static inline uint64_t fde_func_1463_0x129108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129108ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8260ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1464 | PC: 0x129118 | FDE: 0x1e8278 | Size: 16 bytes [Py_GetProgramName]
// Khung tháo gỡ #1464 | Địa chỉ PC: 0x129118 | Địa chỉ FDE: 0x1e8278 | Kích thước: 16 bytes
//   0x129118: D00006A8  adrp     x8, #0x1ff000
//   0x12911c: F9444508  ldr      x8, [x8, #0x888]
//   0x129120: F9401100  ldr      x0, [x8, #0x20]
//   0x129124: D65F03C0  ret      
static inline uint64_t fde_func_1464_0x129118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129118ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8278ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1465 | PC: 0x129128 | FDE: 0x1e8290 | Size: 256 bytes [_PyPathConfig_ComputeSysPath0]
// Khung tháo gỡ #1465 | Địa chỉ PC: 0x129128 | Địa chỉ FDE: 0x1e8290 | Kích thước: 256 bytes
//   0x129128: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x12912c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x129130: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x129134: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1465_0x129128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129128ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1466 | PC: 0x129318 | FDE: 0x1e82b8 | Size: 256 bytes [_Py_FindEnvConfigValue]
// Khung tháo gỡ #1466 | Địa chỉ PC: 0x129318 | Địa chỉ FDE: 0x1e82b8 | Kích thước: 256 bytes
//   0x129318: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x12931c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x129320: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x129324: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1466_0x129318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129318ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e82b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1467 | PC: 0x1294dc | FDE: 0x1e82e8 | Size: 104 bytes [_Py_ClearFileSystemEncoding]
// Khung tháo gỡ #1467 | Địa chỉ PC: 0x1294dc | Địa chỉ FDE: 0x1e82e8 | Kích thước: 104 bytes
//   0x1294dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1294e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1294e4: 910043FD  add      x29, sp, #0x10
//   0x1294e8: D00006A8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1467_0x1294dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1294dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e82e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1468 | PC: 0x129544 | FDE: 0x1e8308 | Size: 188 bytes [_Py_SetFileSystemEncoding]
// Khung tháo gỡ #1468 | Địa chỉ PC: 0x129544 | Địa chỉ FDE: 0x1e8308 | Kích thước: 188 bytes
//   0x129544: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x129548: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12954c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x129550: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1468_0x129544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129544ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8308ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1469 | PC: 0x129600 | FDE: 0x1e8330 | Size: 256 bytes [_PyArgv_AsWstrList]
// Khung tháo gỡ #1469 | Địa chỉ PC: 0x129600 | Địa chỉ FDE: 0x1e8330 | Kích thước: 256 bytes
//   0x129600: D10183FF  sub      sp, sp, #0x60
//   0x129604: F90013F7  str      x23, [sp, #0x20]
//   0x129608: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12960c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1469_0x129600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129600ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e8330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1470 | PC: 0x129760 | FDE: 0x1e8358 | Size: 36 bytes [_PyPreCmdline_Clear]
// Khung tháo gỡ #1470 | Địa chỉ PC: 0x129760 | Địa chỉ FDE: 0x1e8358 | Kích thước: 36 bytes
//   0x129760: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x129764: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x129768: 910043FD  add      x29, sp, #0x10
//   0x12976c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1470_0x129760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129760ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8358ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1471 | PC: 0x129784 | FDE: 0x1e8378 | Size: 16 bytes [_PyPreCmdline_SetArgv]
// Khung tháo gỡ #1471 | Địa chỉ PC: 0x129784 | Địa chỉ FDE: 0x1e8378 | Kích thước: 16 bytes
//   0x129784: AA0003E9  mov      x9, x0
//   0x129788: AA0103E0  mov      x0, x1
//   0x12978c: AA0903E1  mov      x1, x9
//   0x129790: 17FCC684  b        #0x5b1a0
static inline uint64_t fde_func_1471_0x129784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129784ULL ^ (static_cast<uint64_t>(0xaa0003e9ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x1e8378ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1472 | PC: 0x129794 | FDE: 0x1e8390 | Size: 156 bytes [_PyPreCmdline_SetConfig]
// Khung tháo gỡ #1472 | Địa chỉ PC: 0x129794 | Địa chỉ FDE: 0x1e8390 | Kích thước: 156 bytes
//   0x129794: D10183FF  sub      sp, sp, #0x60
//   0x129798: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12979c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1297a0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1472_0x129794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129794ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e8390ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1473 | PC: 0x129830 | FDE: 0x1e83b8 | Size: 256 bytes [_PyPreCmdline_Read]
// Khung tháo gỡ #1473 | Địa chỉ PC: 0x129830 | Địa chỉ FDE: 0x1e83b8 | Kích thước: 256 bytes
//   0x129830: D10183FF  sub      sp, sp, #0x60
//   0x129834: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x129838: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x12983c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1473_0x129830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129830ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e83b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1474 | PC: 0x129af8 | FDE: 0x1e83e8 | Size: 172 bytes [_Py_get_xoption]
// Khung tháo gỡ #1474 | Địa chỉ PC: 0x129af8 | Địa chỉ FDE: 0x1e83e8 | Kích thước: 172 bytes
//   0x129af8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x129afc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x129b00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x129b04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1474_0x129af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129af8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e83e8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1475 | PC: 0x129ba4 | FDE: 0x1e8410 | Size: 52 bytes [_Py_GetEnv]
// Khung tháo gỡ #1475 | Địa chỉ PC: 0x129ba4 | Địa chỉ FDE: 0x1e8410 | Kích thước: 52 bytes
//   0x129ba4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x129ba8: 910003FD  mov      x29, sp
//   0x129bac: 34000100  cbz      w0, #0x129bcc
//   0x129bb0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1475_0x129ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129ba4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8410ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1476 | PC: 0x129bd8 | FDE: 0x1e8430 | Size: 32 bytes [_PyPreConfig_InitCompatConfig]
// Khung tháo gỡ #1476 | Địa chỉ PC: 0x129bd8 | Địa chỉ FDE: 0x1e8430 | Kích thước: 32 bytes
//   0x129bd8: 90000428  adrp     x8, #0x1ad000
//   0x129bdc: D0000489  adrp     x9, #0x1bb000
//   0x129be0: 3DC06100  ldr      q0, [x8, #0x180]
//   0x129be4: 3DC3D521  ldr      q1, [x9, #0xf50]
static inline uint64_t fde_func_1476_0x129bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129bd8ULL ^ (static_cast<uint64_t>(0x90000428ULL) << 13);
    acc = (acc + a1 + 0xd0000489ULL) ^ 0x1e8430ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1477 | PC: 0x129bf8 | FDE: 0x1e8448 | Size: 32 bytes [PyPreConfig_InitPythonConfig]
// Khung tháo gỡ #1477 | Địa chỉ PC: 0x129bf8 | Địa chỉ FDE: 0x1e8448 | Kích thước: 32 bytes
//   0x129bf8: D0000488  adrp     x8, #0x1bb000
//   0x129bfc: F0000469  adrp     x9, #0x1b8000
//   0x129c00: 3DC3D900  ldr      q0, [x8, #0xf60]
//   0x129c04: 3DC3F121  ldr      q1, [x9, #0xfc0]
static inline uint64_t fde_func_1477_0x129bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129bf8ULL ^ (static_cast<uint64_t>(0xd0000488ULL) << 13);
    acc = (acc + a1 + 0xf0000469ULL) ^ 0x1e8448ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1478 | PC: 0x129c18 | FDE: 0x1e8460 | Size: 36 bytes [PyPreConfig_InitIsolatedConfig]
// Khung tháo gỡ #1478 | Địa chỉ PC: 0x129c18 | Địa chỉ FDE: 0x1e8460 | Kích thước: 36 bytes
//   0x129c18: D0000488  adrp     x8, #0x1bb000
//   0x129c1c: 3DC3DD00  ldr      q0, [x8, #0xf70]
//   0x129c20: D2C00068  mov      x8, #0x300000000
//   0x129c24: A9017C1F  stp      xzr, xzr, [x0, #0x10]
static inline uint64_t fde_func_1478_0x129c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c18ULL ^ (static_cast<uint64_t>(0xd0000488ULL) << 13);
    acc = (acc + a1 + 0x3dc3dd00ULL) ^ 0x1e8460ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1479 | PC: 0x129c3c | FDE: 0x1e8478 | Size: 88 bytes [_PyPreConfig_InitFromPreConfig]
// Khung tháo gỡ #1479 | Địa chỉ PC: 0x129c3c | Địa chỉ FDE: 0x1e8478 | Kích thước: 88 bytes
//   0x129c3c: D0000489  adrp     x9, #0x1bb000
//   0x129c40: 3DC3D920  ldr      q0, [x9, #0xf60]
//   0x129c44: F0000469  adrp     x9, #0x1b8000
//   0x129c48: 3DC3F121  ldr      q1, [x9, #0xfc0]
static inline uint64_t fde_func_1479_0x129c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c3cULL ^ (static_cast<uint64_t>(0xd0000489ULL) << 13);
    acc = (acc + a1 + 0x3dc3d920ULL) ^ 0x1e8478ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1480 | PC: 0x129c94 | FDE: 0x1e8490 | Size: 180 bytes [_PyPreConfig_InitFromConfig]
// Khung tháo gỡ #1480 | Địa chỉ PC: 0x129c94 | Địa chỉ FDE: 0x1e8490 | Kích thước: 180 bytes
//   0x129c94: B9400028  ldr      w8, [x1]
//   0x129c98: 71000D1F  cmp      w8, #3
//   0x129c9c: 54000160  b.eq     #0x129cc8
//   0x129ca0: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_1480_0x129c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c94ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x71000d1fULL) ^ 0x1e8490ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1481 | PC: 0x129d48 | FDE: 0x1e84a8 | Size: 68 bytes [_PyPreConfig_GetConfig]
// Khung tháo gỡ #1481 | Địa chỉ PC: 0x129d48 | Địa chỉ FDE: 0x1e84a8 | Kích thước: 68 bytes
//   0x129d48: B9405028  ldr      w8, [x1, #0x50]
//   0x129d4c: 3100051F  cmn      w8, #1
//   0x129d50: 54000040  b.eq     #0x129d58
//   0x129d54: B9000408  str      w8, [x0, #4]
static inline uint64_t fde_func_1481_0x129d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129d48ULL ^ (static_cast<uint64_t>(0xb9405028ULL) << 13);
    acc = (acc + a1 + 0x3100051fULL) ^ 0x1e84a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1482 | PC: 0x129d8c | FDE: 0x1e84c0 | Size: 256 bytes [_PyPreConfig_AsDict]
// Khung tháo gỡ #1482 | Địa chỉ PC: 0x129d8c | Địa chỉ FDE: 0x1e84c0 | Kích thước: 256 bytes
//   0x129d8c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x129d90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x129d94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x129d98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1482_0x129d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129d8cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e84c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1483 | PC: 0x12a094 | FDE: 0x1e84e8 | Size: 128 bytes [_Py_str_to_int]
// Khung tháo gỡ #1483 | Địa chỉ PC: 0x12a094 | Địa chỉ FDE: 0x1e84e8 | Kích thước: 128 bytes
//   0x12a094: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12a098: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12a09c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12a0a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1483_0x12a094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a094ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e84e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1484 | PC: 0x12a114 | FDE: 0x1e8508 | Size: 172 bytes [_Py_get_env_flag]
// Khung tháo gỡ #1484 | Địa chỉ PC: 0x12a114 | Địa chỉ FDE: 0x1e8508 | Kích thước: 172 bytes
//   0x12a114: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12a118: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12a11c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12a120: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1484_0x12a114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a114ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8508ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1485 | PC: 0x12a1c0 | FDE: 0x1e8528 | Size: 256 bytes [_PyPreConfig_Read]
// Khung tháo gỡ #1485 | Địa chỉ PC: 0x12a1c0 | Địa chỉ FDE: 0x1e8528 | Kích thước: 256 bytes
//   0x12a1c0: D10443FF  sub      sp, sp, #0x110
//   0x12a1c4: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x12a1c8: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x12a1cc: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1485_0x12a1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a1c0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x1e8528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1486 | PC: 0x12a870 | FDE: 0x1e8558 | Size: 256 bytes [_PyPreConfig_Write]
// Khung tháo gỡ #1486 | Địa chỉ PC: 0x12a870 | Địa chỉ FDE: 0x1e8558 | Kích thước: 256 bytes
//   0x12a870: D101C3FF  sub      sp, sp, #0x70
//   0x12a874: F9000BFB  str      x27, [sp, #0x10]
//   0x12a878: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x12a87c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1486_0x12a870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a870ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1e8558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1487 | PC: 0x12a9b4 | FDE: 0x1e8588 | Size: 156 bytes [_PyArena_New]
// Khung tháo gỡ #1487 | Địa chỉ PC: 0x12a9b4 | Địa chỉ FDE: 0x1e8588 | Kích thước: 156 bytes
//   0x12a9b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12a9b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12a9bc: 910043FD  add      x29, sp, #0x10
//   0x12a9c0: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1487_0x12a9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a9b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8588ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1488 | PC: 0x12aa50 | FDE: 0x1e85a8 | Size: 80 bytes [_PyArena_Free]
// Khung tháo gỡ #1488 | Địa chỉ PC: 0x12aa50 | Địa chỉ FDE: 0x1e85a8 | Kích thước: 80 bytes
//   0x12aa50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12aa54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12aa58: 910043FD  add      x29, sp, #0x10
//   0x12aa5c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1488_0x12aa50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12aa50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e85a8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1489 | PC: 0x12aaa0 | FDE: 0x1e85c8 | Size: 172 bytes [_PyArena_Malloc]
// Khung tháo gỡ #1489 | Địa chỉ PC: 0x12aaa0 | Địa chỉ FDE: 0x1e85c8 | Kích thước: 172 bytes
//   0x12aaa0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x12aaa4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12aaa8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12aaac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1489_0x12aaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12aaa0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e85c8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1490 | PC: 0x12ab4c | FDE: 0x1e85f0 | Size: 72 bytes [_PyArena_AddPyObject]
// Khung tháo gỡ #1490 | Địa chỉ PC: 0x12ab4c | Địa chỉ FDE: 0x1e85f0 | Kích thước: 72 bytes
//   0x12ab4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12ab50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12ab54: 910043FD  add      x29, sp, #0x10
//   0x12ab58: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_1490_0x12ab4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e85f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1491 | PC: 0x12ab94 | FDE: 0x1e8610 | Size: 8 bytes [PyFPE_dummy]
// Khung tháo gỡ #1491 | Địa chỉ PC: 0x12ab94 | Địa chỉ FDE: 0x1e8610 | Kích thước: 8 bytes
//   0x12ab94: 1E6E1000  fmov     d0, #1.00000000
//   0x12ab98: D65F03C0  ret      
static inline uint64_t fde_func_1491_0x12ab94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab94ULL ^ (static_cast<uint64_t>(0x1e6e1000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e8610ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1492 | PC: 0x12ab9c | FDE: 0x1e8628 | Size: 256 bytes [_Py_HashDouble]
// Khung tháo gỡ #1492 | Địa chỉ PC: 0x12ab9c | Địa chỉ FDE: 0x1e8628 | Kích thước: 256 bytes
//   0x12ab9c: D2EFFE08  mov      x8, #0x7ff0000000000000
//   0x12aba0: 1E60C001  fabs     d1, d0
//   0x12aba4: 9E670102  fmov     d2, x8
//   0x12aba8: 1E622020  fcmp     d1, d2
static inline uint64_t fde_func_1492_0x12ab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab9cULL ^ (static_cast<uint64_t>(0xd2effe08ULL) << 13);
    acc = (acc + a1 + 0x1e60c001ULL) ^ 0x1e8628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1493 | PC: 0x12acfc | FDE: 0x1e8648 | Size: 20 bytes [_Py_HashPointer]
// Khung tháo gỡ #1493 | Địa chỉ PC: 0x12acfc | Địa chỉ FDE: 0x1e8648 | Kích thước: 20 bytes
//   0x12acfc: 93C01008  ror      x8, x0, #4
//   0x12ad00: B100051F  cmn      x8, #1
//   0x12ad04: 92800029  mov      x9, #-2
//   0x12ad08: 9A880120  csel     x0, x9, x8, eq
static inline uint64_t fde_func_1493_0x12acfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12acfcULL ^ (static_cast<uint64_t>(0x93c01008ULL) << 13);
    acc = (acc + a1 + 0xb100051fULL) ^ 0x1e8648ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1494 | PC: 0x12ad10 | FDE: 0x1e8660 | Size: 8 bytes [_Py_HashPointerRaw]
// Khung tháo gỡ #1494 | Địa chỉ PC: 0x12ad10 | Địa chỉ FDE: 0x1e8660 | Kích thước: 8 bytes
//   0x12ad10: 93C01000  ror      x0, x0, #4
//   0x12ad14: D65F03C0  ret      
static inline uint64_t fde_func_1494_0x12ad10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad10ULL ^ (static_cast<uint64_t>(0x93c01000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e8660ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1495 | PC: 0x12ad18 | FDE: 0x1e8678 | Size: 52 bytes [_Py_HashBytes]
// Khung tháo gỡ #1495 | Địa chỉ PC: 0x12ad18 | Địa chỉ FDE: 0x1e8678 | Kích thước: 52 bytes
//   0x12ad18: B4000161  cbz      x1, #0x12ad44
//   0x12ad1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12ad20: 910003FD  mov      x29, sp
//   0x12ad24: B0000768  adrp     x8, #0x217000
static inline uint64_t fde_func_1495_0x12ad18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad18ULL ^ (static_cast<uint64_t>(0xb4000161ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1e8678ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1496 | PC: 0x12ad4c | FDE: 0x1e8698 | Size: 4 bytes [_PyHash_Fini]
// Khung tháo gỡ #1496 | Địa chỉ PC: 0x12ad4c | Địa chỉ FDE: 0x1e8698 | Kích thước: 4 bytes
//   0x12ad4c: D65F03C0  ret      
static inline uint64_t fde_func_1496_0x12ad4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad4cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xb0000760ULL) ^ 0x1e8698ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1497 | PC: 0x12ad50 | FDE: 0x1e86b0 | Size: 12 bytes [PyHash_GetFuncDef]
// Khung tháo gỡ #1497 | Địa chỉ PC: 0x12ad50 | Địa chỉ FDE: 0x1e86b0 | Kích thước: 12 bytes
//   0x12ad50: B0000760  adrp     x0, #0x217000
//   0x12ad54: 91314000  add      x0, x0, #0xc50
//   0x12ad58: D65F03C0  ret      
static inline uint64_t fde_func_1497_0x12ad50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad50ULL ^ (static_cast<uint64_t>(0xb0000760ULL) << 13);
    acc = (acc + a1 + 0x91314000ULL) ^ 0x1e86b0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1498 | PC: 0x12ad5c | FDE: 0x1e86c8 | Size: 256 bytes [_Py_KeyedHash]
// Khung tháo gỡ #1498 | Địa chỉ PC: 0x12ad5c | Địa chỉ FDE: 0x1e86c8 | Kích thước: 256 bytes
//   0x12ad5c: D28CAEA9  mov      x9, #0x6575
//   0x12ad60: D28E4C2D  mov      x13, #0x7261
//   0x12ad64: D28CAE68  mov      x8, #0x6573
//   0x12ad68: D28DEDAA  mov      x10, #0x6f6d
static inline uint64_t fde_func_1498_0x12ad5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad5cULL ^ (static_cast<uint64_t>(0xd28caea9ULL) << 13);
    acc = (acc + a1 + 0xd28e4c2dULL) ^ 0x1e86c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1499 | PC: 0x12b090 | FDE: 0x1e86f8 | Size: 16 bytes [BDPythonVMIsExit]
// Khung tháo gỡ #1499 | Địa chỉ PC: 0x12b090 | Địa chỉ FDE: 0x1e86f8 | Kích thước: 16 bytes
//   0x12b090: 900006A8  adrp     x8, #0x1ff000
//   0x12b094: F9457108  ldr      x8, [x8, #0xae0]
//   0x12b098: B9400100  ldr      w0, [x8]
//   0x12b09c: D65F03C0  ret      
static inline uint64_t fde_func_1499_0x12b090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b090ULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf9457108ULL) ^ 0x1e86f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1500 | PC: 0x12b0a0 | FDE: 0x1e8710 | Size: 48 bytes [_PyRuntime_Initialize]
// Khung tháo gỡ #1500 | Địa chỉ PC: 0x12b0a0 | Địa chỉ FDE: 0x1e8710 | Kích thước: 48 bytes
//   0x12b0a0: D00007C9  adrp     x9, #0x225000
//   0x12b0a4: 394E612A  ldrb     w10, [x9, #0x398]
//   0x12b0a8: 7100055F  cmp      w10, #1
//   0x12b0ac: 54000081  b.ne     #0x12b0bc
static inline uint64_t fde_func_1500_0x12b0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b0a0ULL ^ (static_cast<uint64_t>(0xd00007c9ULL) << 13);
    acc = (acc + a1 + 0x394e612aULL) ^ 0x1e8710ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1501 | PC: 0x12b0d0 | FDE: 0x1e8728 | Size: 36 bytes [_PyRuntime_Finalize]
// Khung tháo gỡ #1501 | Địa chỉ PC: 0x12b0d0 | Địa chỉ FDE: 0x1e8728 | Kích thước: 36 bytes
//   0x12b0d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12b0d4: 910003FD  mov      x29, sp
//   0x12b0d8: 900006A0  adrp     x0, #0x1ff000
//   0x12b0dc: F943B800  ldr      x0, [x0, #0x770]
static inline uint64_t fde_func_1501_0x12b0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b0d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8728ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1502 | PC: 0x12b0f4 | FDE: 0x1e8748 | Size: 24 bytes [_Py_IsFinalizing]
// Khung tháo gỡ #1502 | Địa chỉ PC: 0x12b0f4 | Địa chỉ FDE: 0x1e8748 | Kích thước: 24 bytes
//   0x12b0f4: 900006A8  adrp     x8, #0x1ff000
//   0x12b0f8: F943B908  ldr      x8, [x8, #0x770]
//   0x12b0fc: F9400908  ldr      x8, [x8, #0x10]
//   0x12b100: F100011F  cmp      x8, #0
static inline uint64_t fde_func_1502_0x12b0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b0f4ULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e8748ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1503 | PC: 0x12b10c | FDE: 0x1e8760 | Size: 16 bytes [_Py_IsCoreInitialized]
// Khung tháo gỡ #1503 | Địa chỉ PC: 0x12b10c | Địa chỉ FDE: 0x1e8760 | Kích thước: 16 bytes
//   0x12b10c: 900006A8  adrp     x8, #0x1ff000
//   0x12b110: F943B908  ldr      x8, [x8, #0x770]
//   0x12b114: B9400900  ldr      w0, [x8, #8]
//   0x12b118: D65F03C0  ret      
static inline uint64_t fde_func_1503_0x12b10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b10cULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e8760ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1504 | PC: 0x12b11c | FDE: 0x1e8778 | Size: 16 bytes [Py_IsInitialized]
// Khung tháo gỡ #1504 | Địa chỉ PC: 0x12b11c | Địa chỉ FDE: 0x1e8778 | Kích thước: 16 bytes
//   0x12b11c: 900006A8  adrp     x8, #0x1ff000
//   0x12b120: F943B908  ldr      x8, [x8, #0x770]
//   0x12b124: B9400D00  ldr      w0, [x8, #0xc]
//   0x12b128: D65F03C0  ret      
static inline uint64_t fde_func_1504_0x12b11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b11cULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e8778ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1505 | PC: 0x12b12c | FDE: 0x1e8790 | Size: 92 bytes [_Py_LegacyLocaleDetected]
// Khung tháo gỡ #1505 | Địa chỉ PC: 0x12b12c | Địa chỉ FDE: 0x1e8790 | Kích thước: 92 bytes
//   0x12b12c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12b130: 910003FD  mov      x29, sp
//   0x12b134: 34000180  cbz      w0, #0x12b164
//   0x12b138: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_1505_0x12b12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b12cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8790ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1506 | PC: 0x12b188 | FDE: 0x1e87b0 | Size: 96 bytes [_Py_IsLocaleCoercionTarget]
// Khung tháo gỡ #1506 | Địa chỉ PC: 0x12b188 | Địa chỉ FDE: 0x1e87b0 | Kích thước: 96 bytes
//   0x12b188: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12b18c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12b190: 910043FD  add      x29, sp, #0x10
//   0x12b194: B0000481  adrp     x1, #0x1bc000
static inline uint64_t fde_func_1506_0x12b188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b188ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e87b0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1507 | PC: 0x12b1e8 | FDE: 0x1e87d0 | Size: 8 bytes [_Py_CoerceLegacyLocale]
// Khung tháo gỡ #1507 | Địa chỉ PC: 0x12b1e8 | Địa chỉ FDE: 0x1e87d0 | Kích thước: 8 bytes
//   0x12b1e8: 2A1F03E0  mov      w0, wzr
//   0x12b1ec: D65F03C0  ret      
static inline uint64_t fde_func_1507_0x12b1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b1e8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e87d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1508 | PC: 0x12b1f0 | FDE: 0x1e87e8 | Size: 248 bytes [_Py_SetLocaleFromEnv]
// Khung tháo gỡ #1508 | Địa chỉ PC: 0x12b1f0 | Địa chỉ FDE: 0x1e87e8 | Kích thước: 248 bytes
//   0x12b1f0: D10183FF  sub      sp, sp, #0x60
//   0x12b1f4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12b1f8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x12b1fc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1508_0x12b1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b1f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e87e8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1509 | PC: 0x12b2e8 | FDE: 0x1e8810 | Size: 256 bytes [_PyInterpreterState_SetConfig]
// Khung tháo gỡ #1509 | Địa chỉ PC: 0x12b2e8 | Địa chỉ FDE: 0x1e8810 | Kích thước: 256 bytes
//   0x12b2e8: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x12b2ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12b2f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12b2f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1509_0x12b2e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b2e8ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1510 | PC: 0x12b4cc | FDE: 0x1e8858 | Size: 256 bytes [_Py_PreInitializeFromPyArgv]
// Khung tháo gỡ #1510 | Địa chỉ PC: 0x12b4cc | Địa chỉ FDE: 0x1e8858 | Kích thước: 256 bytes
//   0x12b4cc: D10303FF  sub      sp, sp, #0xc0
//   0x12b4d0: F90043F7  str      x23, [sp, #0x80]
//   0x12b4d4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x12b4d8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1510_0x12b4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b4ccULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1e8858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1511 | PC: 0x12b678 | FDE: 0x1e8880 | Size: 88 bytes [Py_PreInitializeFromBytesArgs]
// Khung tháo gỡ #1511 | Địa chỉ PC: 0x12b678 | Địa chỉ FDE: 0x1e8880 | Kích thước: 88 bytes
//   0x12b678: D10143FF  sub      sp, sp, #0x50
//   0x12b67c: F9001BF3  str      x19, [sp, #0x30]
//   0x12b680: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12b684: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1511_0x12b678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b678ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e8880ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1512 | PC: 0x12b6d0 | FDE: 0x1e88a0 | Size: 84 bytes [Py_PreInitializeFromArgs]
// Khung tháo gỡ #1512 | Địa chỉ PC: 0x12b6d0 | Địa chỉ FDE: 0x1e88a0 | Kích thước: 84 bytes
//   0x12b6d0: D10143FF  sub      sp, sp, #0x50
//   0x12b6d4: F9001BF3  str      x19, [sp, #0x30]
//   0x12b6d8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12b6dc: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1512_0x12b6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b6d0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e88a0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1513 | PC: 0x12b724 | FDE: 0x1e88c0 | Size: 8 bytes [Py_PreInitialize]
// Khung tháo gỡ #1513 | Địa chỉ PC: 0x12b724 | Địa chỉ FDE: 0x1e88c0 | Kích thước: 8 bytes
//   0x12b724: AA1F03E1  mov      x1, xzr
//   0x12b728: 17FCBDF2  b        #0x5aef0
static inline uint64_t fde_func_1513_0x12b724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b724ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fcbdf2ULL) ^ 0x1e88c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1514 | PC: 0x12b72c | FDE: 0x1e88d8 | Size: 256 bytes [_Py_PreInitializeFromConfig]
// Khung tháo gỡ #1514 | Địa chỉ PC: 0x12b72c | Địa chỉ FDE: 0x1e88d8 | Kích thước: 256 bytes
//   0x12b72c: D102C3FF  sub      sp, sp, #0xb0
//   0x12b730: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x12b734: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12b738: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1514_0x12b72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b72cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1e88d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1515 | PC: 0x12b840 | FDE: 0x1e8900 | Size: 256 bytes [Py_InitializeFromConfig]
// Khung tháo gỡ #1515 | Địa chỉ PC: 0x12b840 | Địa chỉ FDE: 0x1e8900 | Kích thước: 256 bytes
//   0x12b840: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x12b844: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12b848: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12b84c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1515_0x12b840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b840ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1516 | PC: 0x12bd38 | FDE: 0x1e8928 | Size: 256 bytes [Py_InitializeEx]
// Khung tháo gỡ #1516 | Địa chỉ PC: 0x12bd38 | Địa chỉ FDE: 0x1e8928 | Kích thước: 256 bytes
//   0x12bd38: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x12bd3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12bd40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12bd44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1516_0x12bd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12bd38ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1517 | PC: 0x12be5c | FDE: 0x1e8950 | Size: 84 bytes [Py_ExitStatusException]
// Khung tháo gỡ #1517 | Địa chỉ PC: 0x12be5c | Địa chỉ FDE: 0x1e8950 | Kích thước: 84 bytes
//   0x12be5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12be60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12be64: 910043FD  add      x29, sp, #0x10
//   0x12be68: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_1517_0x12be5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12be5cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8950ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1518 | PC: 0x12beb0 | FDE: 0x1e8970 | Size: 8 bytes [Py_Initialize]
// Khung tháo gỡ #1518 | Địa chỉ PC: 0x12beb0 | Địa chỉ FDE: 0x1e8970 | Kích thước: 8 bytes
//   0x12beb0: 52800020  mov      w0, #1
//   0x12beb4: 17FCB6FB  b        #0x59aa0
static inline uint64_t fde_func_1518_0x12beb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12beb0ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0x17fcb6fbULL) ^ 0x1e8970ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1519 | PC: 0x12beb8 | FDE: 0x1e8988 | Size: 256 bytes [_Py_InitializeMain]
// Khung tháo gỡ #1519 | Địa chỉ PC: 0x12beb8 | Địa chỉ FDE: 0x1e8988 | Kích thước: 256 bytes
//   0x12beb8: D101C3FF  sub      sp, sp, #0x70
//   0x12bebc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12bec0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x12bec4: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1519_0x12beb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12beb8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e8988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1520 | PC: 0x12bff8 | FDE: 0x1e89a8 | Size: 256 bytes [Py_FinalizeEx]
// Khung tháo gỡ #1520 | Địa chỉ PC: 0x12bff8 | Địa chỉ FDE: 0x1e89a8 | Kích thước: 256 bytes
//   0x12bff8: D10183FF  sub      sp, sp, #0x60
//   0x12bffc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x12c000: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x12c004: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1520_0x12bff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12bff8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e89a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1521 | PC: 0x12cc30 | FDE: 0x1e8a50 | Size: 156 bytes [BDPythonVMDeallocSizeOptimizeFiles]
// Khung tháo gỡ #1521 | Địa chỉ PC: 0x12cc30 | Địa chỉ FDE: 0x1e8a50 | Kích thước: 156 bytes
//   0x12cc30: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x12cc34: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12cc38: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12cc3c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1521_0x12cc30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cc30ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8a50ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1522 | PC: 0x12cccc | FDE: 0x1e8a78 | Size: 4 bytes [Py_Finalize]
// Khung tháo gỡ #1522 | Địa chỉ PC: 0x12cccc | Địa chỉ FDE: 0x1e8a78 | Kích thước: 4 bytes
//   0x12cccc: 17FCC099  b        #0x5cf30
static inline uint64_t fde_func_1522_0x12cccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ccccULL ^ (static_cast<uint64_t>(0x17fcc099ULL) << 13);
    acc = (acc + a1 + 0xd10303ffULL) ^ 0x1e8a78ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1523 | PC: 0x12ccd0 | FDE: 0x1e8a90 | Size: 256 bytes [_Py_NewInterpreter]
// Khung tháo gỡ #1523 | Địa chỉ PC: 0x12ccd0 | Địa chỉ FDE: 0x1e8a90 | Kích thước: 256 bytes
//   0x12ccd0: D10303FF  sub      sp, sp, #0xc0
//   0x12ccd4: F90043F7  str      x23, [sp, #0x80]
//   0x12ccd8: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x12ccdc: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1523_0x12ccd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ccd0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1e8a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1524 | PC: 0x12ced8 | FDE: 0x1e8ab8 | Size: 8 bytes [Py_NewInterpreter]
// Khung tháo gỡ #1524 | Địa chỉ PC: 0x12ced8 | Địa chỉ FDE: 0x1e8ab8 | Kích thước: 8 bytes
//   0x12ced8: 2A1F03E0  mov      w0, wzr
//   0x12cedc: 17FCAE39  b        #0x587c0
static inline uint64_t fde_func_1524_0x12ced8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ced8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0x17fcae39ULL) ^ 0x1e8ab8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1525 | PC: 0x12cee0 | FDE: 0x1e8ad0 | Size: 256 bytes [Py_EndInterpreter]
// Khung tháo gỡ #1525 | Địa chỉ PC: 0x12cee0 | Địa chỉ FDE: 0x1e8ad0 | Kích thước: 256 bytes
//   0x12cee0: D10103FF  sub      sp, sp, #0x40
//   0x12cee4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12cee8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12ceec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1525_0x12cee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cee0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1526 | PC: 0x12d064 | FDE: 0x1e8af8 | Size: 56 bytes [_Py_FatalErrorFunc]
// Khung tháo gỡ #1526 | Địa chỉ PC: 0x12d064 | Địa chỉ FDE: 0x1e8af8 | Kích thước: 56 bytes
//   0x12d064: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12d068: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12d06c: 910043FD  add      x29, sp, #0x10
//   0x12d070: D0000688  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1526_0x12d064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d064ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8af8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1527 | PC: 0x12d09c | FDE: 0x1e8b18 | Size: 256 bytes [_Py_DumpExtensionModules]
// Khung tháo gỡ #1527 | Địa chỉ PC: 0x12d09c | Địa chỉ FDE: 0x1e8b18 | Kích thước: 256 bytes
//   0x12d09c: D10243FF  sub      sp, sp, #0x90
//   0x12d0a0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x12d0a4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x12d0a8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1527_0x12d09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d09cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x1e8b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1528 | PC: 0x12d334 | FDE: 0x1e8b48 | Size: 256 bytes [Py_FatalError]
// Khung tháo gỡ #1528 | Địa chỉ PC: 0x12d334 | Địa chỉ FDE: 0x1e8b48 | Kích thước: 256 bytes
//   0x12d334: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12d338: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12d33c: 910043FD  add      x29, sp, #0x10
//   0x12d340: D0000688  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1528_0x12d334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d334ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1529 | PC: 0x12d844 | FDE: 0x1e8b98 | Size: 256 bytes [_Py_FatalErrorFormat]
// Khung tháo gỡ #1529 | Địa chỉ PC: 0x12d844 | Địa chỉ FDE: 0x1e8b98 | Kích thước: 256 bytes
//   0x12d844: D104C3FF  sub      sp, sp, #0x130
//   0x12d848: A90F5FFC  stp      x28, x23, [sp, #0xf0]
//   0x12d84c: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x12d850: A9114FF4  stp      x20, x19, [sp, #0x110]
static inline uint64_t fde_func_1529_0x12d844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d844ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90f5ffcULL) ^ 0x1e8b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1530 | PC: 0x12d9cc | FDE: 0x1e8c00 | Size: 56 bytes [Py_AtExit]
// Khung tháo gỡ #1530 | Địa chỉ PC: 0x12d9cc | Địa chỉ FDE: 0x1e8c00 | Kích thước: 56 bytes
//   0x12d9cc: D0000689  adrp     x9, #0x1ff000
//   0x12d9d0: F943B929  ldr      x9, [x9, #0x770]
//   0x12d9d4: B981512A  ldrsw    x10, [x9, #0x150]
//   0x12d9d8: 71007D5F  cmp      w10, #0x1f
static inline uint64_t fde_func_1530_0x12d9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d9ccULL ^ (static_cast<uint64_t>(0xd0000689ULL) << 13);
    acc = (acc + a1 + 0xf943b929ULL) ^ 0x1e8c00ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1531 | PC: 0x12da04 | FDE: 0x1e8c18 | Size: 16 bytes [Py_Exit]
// Khung tháo gỡ #1531 | Địa chỉ PC: 0x12da04 | Địa chỉ FDE: 0x1e8c18 | Kích thước: 16 bytes
//   0x12da04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12da08: 910003FD  mov      x29, sp
//   0x12da0c: 97FCBD49  bl       #0x5cf30
//   0x12da10: 97FFFFE2  bl       #0x12d998
static inline uint64_t fde_func_1531_0x12da04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12da04ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8c18ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1532 | PC: 0x12da14 | FDE: 0x1e8c38 | Size: 120 bytes [Py_FdIsInteractive]
// Khung tháo gỡ #1532 | Địa chỉ PC: 0x12da14 | Địa chỉ FDE: 0x1e8c38 | Kích thước: 120 bytes
//   0x12da14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12da18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12da1c: 910043FD  add      x29, sp, #0x10
//   0x12da20: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1532_0x12da14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12da14ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8c38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1533 | PC: 0x12da8c | FDE: 0x1e8c58 | Size: 120 bytes [_Py_FdIsInteractive]
// Khung tháo gỡ #1533 | Địa chỉ PC: 0x12da8c | Địa chỉ FDE: 0x1e8c58 | Kích thước: 120 bytes
//   0x12da8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12da90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12da94: 910043FD  add      x29, sp, #0x10
//   0x12da98: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1533_0x12da8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12da8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8c58ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1534 | PC: 0x12db04 | FDE: 0x1e8c78 | Size: 88 bytes [PyOS_getsig]
// Khung tháo gỡ #1534 | Địa chỉ PC: 0x12db04 | Địa chỉ FDE: 0x1e8c78 | Kích thước: 88 bytes
//   0x12db04: D10143FF  sub      sp, sp, #0x50
//   0x12db08: F9001BF3  str      x19, [sp, #0x30]
//   0x12db0c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12db10: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1534_0x12db04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12db04ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e8c78ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1535 | PC: 0x12db5c | FDE: 0x1e8c98 | Size: 120 bytes [PyOS_setsig]
// Khung tháo gỡ #1535 | Địa chỉ PC: 0x12db5c | Địa chỉ FDE: 0x1e8c98 | Kích thước: 120 bytes
//   0x12db5c: D101C3FF  sub      sp, sp, #0x70
//   0x12db60: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12db64: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x12db68: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1535_0x12db5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12db5cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e8c98ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1536 | PC: 0x12dbd4 | FDE: 0x1e8cb8 | Size: 72 bytes [BDPythonVMDeallocFrozenImportModules]
// Khung tháo gỡ #1536 | Địa chỉ PC: 0x12dbd4 | Địa chỉ FDE: 0x1e8cb8 | Kích thước: 72 bytes
//   0x12dbd4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12dbd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12dbdc: 910043FD  add      x29, sp, #0x10
//   0x12dbe0: 900007D3  adrp     x19, #0x225000
static inline uint64_t fde_func_1536_0x12dbd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dbd4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8cb8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1537 | PC: 0x12dc1c | FDE: 0x1e8cd8 | Size: 256 bytes [BDPythonVMSetupFrozenImportModules]
// Khung tháo gỡ #1537 | Địa chỉ PC: 0x12dc1c | Địa chỉ FDE: 0x1e8cd8 | Kích thước: 256 bytes
//   0x12dc1c: D10343FF  sub      sp, sp, #0xd0
//   0x12dc20: F90043F9  str      x25, [sp, #0x80]
//   0x12dc24: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x12dc28: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_1537_0x12dc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dc1cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90043f9ULL) ^ 0x1e8cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1538 | PC: 0x12ddb8 | FDE: 0x1e8d00 | Size: 188 bytes [BDPythonVMSetIndexFile1]
// Khung tháo gỡ #1538 | Địa chỉ PC: 0x12ddb8 | Địa chỉ FDE: 0x1e8d00 | Kích thước: 188 bytes
//   0x12ddb8: D102C3FF  sub      sp, sp, #0xb0
//   0x12ddbc: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x12ddc0: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12ddc4: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1538_0x12ddb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ddb8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1e8d00ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1539 | PC: 0x12de74 | FDE: 0x1e8d28 | Size: 188 bytes [BDPythonVMSetIndexFile2]
// Khung tháo gỡ #1539 | Địa chỉ PC: 0x12de74 | Địa chỉ FDE: 0x1e8d28 | Kích thước: 188 bytes
//   0x12de74: D102C3FF  sub      sp, sp, #0xb0
//   0x12de78: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x12de7c: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12de80: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1539_0x12de74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12de74ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1e8d28ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1540 | PC: 0x12df30 | FDE: 0x1e8d50 | Size: 112 bytes [BDPythonVMSetupUnicodeIndex]
// Khung tháo gỡ #1540 | Địa chỉ PC: 0x12df30 | Địa chỉ FDE: 0x1e8d50 | Kích thước: 112 bytes
//   0x12df30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12df34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12df38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12df3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1540_0x12df30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12df30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8d50ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1541 | PC: 0x12dfa0 | FDE: 0x1e8d70 | Size: 192 bytes [BDPythonVMSetUnicodeTypeRecords]
// Khung tháo gỡ #1541 | Địa chỉ PC: 0x12dfa0 | Địa chỉ FDE: 0x1e8d70 | Kích thước: 192 bytes
//   0x12dfa0: D102C3FF  sub      sp, sp, #0xb0
//   0x12dfa4: F90043F5  str      x21, [sp, #0x80]
//   0x12dfa8: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12dfac: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1541_0x12dfa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dfa0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f5ULL) ^ 0x1e8d70ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1542 | PC: 0x12e060 | FDE: 0x1e8d90 | Size: 76 bytes [BDPythonVMSetupUnicodeTypeRecords]
// Khung tháo gỡ #1542 | Địa chỉ PC: 0x12e060 | Địa chỉ FDE: 0x1e8d90 | Kích thước: 76 bytes
//   0x12e060: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12e064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12e068: 910043FD  add      x29, sp, #0x10
//   0x12e06c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1542_0x12e060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e060ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8d90ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1543 | PC: 0x12e0ac | FDE: 0x1e8db0 | Size: 184 bytes [BDPythonVMSetUnicodeExtendedCase]
// Khung tháo gỡ #1543 | Địa chỉ PC: 0x12e0ac | Địa chỉ FDE: 0x1e8db0 | Kích thước: 184 bytes
//   0x12e0ac: D102C3FF  sub      sp, sp, #0xb0
//   0x12e0b0: F90043F5  str      x21, [sp, #0x80]
//   0x12e0b4: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12e0b8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1543_0x12e0ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e0acULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f5ULL) ^ 0x1e8db0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1544 | PC: 0x12e164 | FDE: 0x1e8dd0 | Size: 76 bytes [BDPythonVMSetupUnicodeExtendedCase]
// Khung tháo gỡ #1544 | Địa chỉ PC: 0x12e164 | Địa chỉ FDE: 0x1e8dd0 | Kích thước: 76 bytes
//   0x12e164: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12e168: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12e16c: 910043FD  add      x29, sp, #0x10
//   0x12e170: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1544_0x12e164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e164ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8dd0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1545 | PC: 0x12e1b0 | FDE: 0x1e8df0 | Size: 256 bytes [BDPythonVMSetupSizeOptimizeFiles]
// Khung tháo gỡ #1545 | Địa chỉ PC: 0x12e1b0 | Địa chỉ FDE: 0x1e8df0 | Kích thước: 256 bytes
//   0x12e1b0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x12e1b4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x12e1b8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x12e1bc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1545_0x12e1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e1b0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e8df0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1546 | PC: 0x12f8d8 | FDE: 0x1e8ef0 | Size: 256 bytes [_PyRuntimeState_Init]
// Khung tháo gỡ #1546 | Địa chỉ PC: 0x12f8d8 | Địa chỉ FDE: 0x1e8ef0 | Kích thước: 256 bytes
//   0x12f8d8: D101C3FF  sub      sp, sp, #0x70
//   0x12f8dc: F9001BF7  str      x23, [sp, #0x30]
//   0x12f8e0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x12f8e4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1546_0x12f8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12f8d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e8ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1547 | PC: 0x12fa44 | FDE: 0x1e8f18 | Size: 140 bytes [_PyRuntimeState_Fini]
// Khung tháo gỡ #1547 | Địa chỉ PC: 0x12fa44 | Địa chỉ FDE: 0x1e8f18 | Kích thước: 140 bytes
//   0x12fa44: D10143FF  sub      sp, sp, #0x50
//   0x12fa48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x12fa4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12fa50: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1547_0x12fa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fa44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e8f18ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1548 | PC: 0x12fad0 | FDE: 0x1e8f38 | Size: 244 bytes [_PyRuntimeState_ReInitThreads]
// Khung tháo gỡ #1548 | Địa chỉ PC: 0x12fad0 | Địa chỉ FDE: 0x1e8f38 | Kích thước: 244 bytes
//   0x12fad0: D101C3FF  sub      sp, sp, #0x70
//   0x12fad4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x12fad8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x12fadc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1548_0x12fad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fad0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1e8f38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1549 | PC: 0x12fbc4 | FDE: 0x1e8f60 | Size: 184 bytes [_PyInterpreterState_Enable]
// Khung tháo gỡ #1549 | Địa chỉ PC: 0x12fbc4 | Địa chỉ FDE: 0x1e8f60 | Kích thước: 184 bytes
//   0x12fbc4: D10183FF  sub      sp, sp, #0x60
//   0x12fbc8: F9001BF5  str      x21, [sp, #0x30]
//   0x12fbcc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x12fbd0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1549_0x12fbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fbc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e8f60ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1550 | PC: 0x12fc7c | FDE: 0x1e8f80 | Size: 256 bytes [PyInterpreterState_New]
// Khung tháo gỡ #1550 | Địa chỉ PC: 0x12fc7c | Địa chỉ FDE: 0x1e8f80 | Kích thước: 256 bytes
//   0x12fc7c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12fc80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12fc84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12fc88: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1550_0x12fc7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fc7cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1551 | PC: 0x12fdcc | FDE: 0x1e8fa0 | Size: 256 bytes [PyInterpreterState_Clear]
// Khung tháo gỡ #1551 | Địa chỉ PC: 0x12fdcc | Địa chỉ FDE: 0x1e8fa0 | Kích thước: 256 bytes
//   0x12fdcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12fdd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12fdd4: 910043FD  add      x29, sp, #0x10
//   0x12fdd8: 90000688  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1551_0x12fdcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fdccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1552 | PC: 0x130114 | FDE: 0x1e8fe8 | Size: 12 bytes [_PyInterpreterState_Clear]
// Khung tháo gỡ #1552 | Địa chỉ PC: 0x130114 | Địa chỉ FDE: 0x1e8fe8 | Kích thước: 12 bytes
//   0x130114: AA0003E1  mov      x1, x0
//   0x130118: F9400800  ldr      x0, [x0, #0x10]
//   0x13011c: 17FFFF39  b        #0x12fe00
static inline uint64_t fde_func_1552_0x130114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130114ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xf9400800ULL) ^ 0x1e8fe8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1553 | PC: 0x130120 | FDE: 0x1e9000 | Size: 256 bytes [PyInterpreterState_Delete]
// Khung tháo gỡ #1553 | Địa chỉ PC: 0x130120 | Địa chỉ FDE: 0x1e9000 | Kích thước: 256 bytes
//   0x130120: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x130124: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130128: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13012c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1553_0x130120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130120ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1554 | PC: 0x130240 | FDE: 0x1e9020 | Size: 80 bytes [_PyThreadState_Swap]
// Khung tháo gỡ #1554 | Địa chỉ PC: 0x130240 | Địa chỉ FDE: 0x1e9020 | Kích thước: 80 bytes
//   0x130240: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x130244: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130248: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13024c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1554_0x130240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130240ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9020ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1555 | PC: 0x130290 | FDE: 0x1e9040 | Size: 256 bytes [_PyInterpreterState_DeleteExceptMain]
// Khung tháo gỡ #1555 | Địa chỉ PC: 0x130290 | Địa chỉ FDE: 0x1e9040 | Kích thước: 256 bytes
//   0x130290: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x130294: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x130298: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13029c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1555_0x130290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130290ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e9040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1556 | PC: 0x130434 | FDE: 0x1e9070 | Size: 76 bytes [PyInterpreterState_Get]
// Khung tháo gỡ #1556 | Địa chỉ PC: 0x130434 | Địa chỉ FDE: 0x1e9070 | Kích thước: 76 bytes
//   0x130434: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x130438: 910003FD  mov      x29, sp
//   0x13043c: F0000668  adrp     x8, #0x1ff000
//   0x130440: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1556_0x130434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130434ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9070ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1557 | PC: 0x130480 | FDE: 0x1e9090 | Size: 60 bytes [PyInterpreterState_GetID]
// Khung tháo gỡ #1557 | Địa chỉ PC: 0x130480 | Địa chỉ FDE: 0x1e9090 | Kích thước: 60 bytes
//   0x130480: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x130484: 910003FD  mov      x29, sp
//   0x130488: B4000080  cbz      x0, #0x130498
//   0x13048c: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_1557_0x130480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130480ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9090ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1558 | PC: 0x1304bc | FDE: 0x1e90b0 | Size: 156 bytes [_PyInterpreterState_LookUpID]
// Khung tháo gỡ #1558 | Địa chỉ PC: 0x1304bc | Địa chỉ FDE: 0x1e90b0 | Kích thước: 156 bytes
//   0x1304bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1304c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1304c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1304c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1558_0x1304bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1304bcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e90b0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1559 | PC: 0x130558 | FDE: 0x1e90d0 | Size: 96 bytes [_PyInterpreterState_IDInitref]
// Khung tháo gỡ #1559 | Địa chỉ PC: 0x130558 | Địa chỉ FDE: 0x1e90d0 | Kích thước: 96 bytes
//   0x130558: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13055c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130560: 910043FD  add      x29, sp, #0x10
//   0x130564: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_1559_0x130558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130558ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e90d0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1560 | PC: 0x1305b8 | FDE: 0x1e90f0 | Size: 116 bytes [_PyInterpreterState_IDIncref]
// Khung tháo gỡ #1560 | Địa chỉ PC: 0x1305b8 | Địa chỉ FDE: 0x1e90f0 | Kích thước: 116 bytes
//   0x1305b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1305bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1305c0: 910043FD  add      x29, sp, #0x10
//   0x1305c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1560_0x1305b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1305b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e90f0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1561 | PC: 0x13062c | FDE: 0x1e9110 | Size: 168 bytes [_PyInterpreterState_IDDecref]
// Khung tháo gỡ #1561 | Địa chỉ PC: 0x13062c | Địa chỉ FDE: 0x1e9110 | Kích thước: 168 bytes
//   0x13062c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130630: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130634: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130638: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1561_0x13062c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13062cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9110ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1562 | PC: 0x1306d4 | FDE: 0x1e9138 | Size: 8 bytes [PyInterpreterState_ThreadHead]
// Khung tháo gỡ #1562 | Địa chỉ PC: 0x1306d4 | Địa chỉ FDE: 0x1e9138 | Kích thước: 8 bytes
//   0x1306d4: F9400400  ldr      x0, [x0, #8]
//   0x1306d8: D65F03C0  ret      
static inline uint64_t fde_func_1562_0x1306d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306d4ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9138ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1563 | PC: 0x1306dc | FDE: 0x1e9150 | Size: 8 bytes [_PyInterpreterState_RequiresIDRef]
// Khung tháo gỡ #1563 | Địa chỉ PC: 0x1306dc | Địa chỉ FDE: 0x1e9150 | Kích thước: 8 bytes
//   0x1306dc: B9402800  ldr      w0, [x0, #0x28]
//   0x1306e0: D65F03C0  ret      
static inline uint64_t fde_func_1563_0x1306dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306dcULL ^ (static_cast<uint64_t>(0xb9402800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9150ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1564 | PC: 0x1306e4 | FDE: 0x1e9168 | Size: 16 bytes [_PyInterpreterState_RequireIDRef]
// Khung tháo gỡ #1564 | Địa chỉ PC: 0x1306e4 | Địa chỉ FDE: 0x1e9168 | Kích thước: 16 bytes
//   0x1306e4: 7100003F  cmp      w1, #0
//   0x1306e8: 1A9F07E8  cset     w8, ne
//   0x1306ec: B9002808  str      w8, [x0, #0x28]
//   0x1306f0: D65F03C0  ret      
static inline uint64_t fde_func_1564_0x1306e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306e4ULL ^ (static_cast<uint64_t>(0x7100003fULL) << 13);
    acc = (acc + a1 + 0x1a9f07e8ULL) ^ 0x1e9168ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1565 | PC: 0x1306f4 | FDE: 0x1e9180 | Size: 68 bytes [_PyInterpreterState_GetMainModule]
// Khung tháo gỡ #1565 | Địa chỉ PC: 0x1306f4 | Địa chỉ FDE: 0x1e9180 | Kích thước: 68 bytes
//   0x1306f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1306f8: 910003FD  mov      x29, sp
//   0x1306fc: F9421400  ldr      x0, [x0, #0x428]
//   0x130700: B40000A0  cbz      x0, #0x130714
static inline uint64_t fde_func_1565_0x1306f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9180ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1566 | PC: 0x130738 | FDE: 0x1e91a0 | Size: 56 bytes [PyInterpreterState_GetDict]
// Khung tháo gỡ #1566 | Địa chỉ PC: 0x130738 | Địa chỉ FDE: 0x1e91a0 | Kích thước: 56 bytes
//   0x130738: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13073c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130740: 910043FD  add      x29, sp, #0x10
//   0x130744: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1566_0x130738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130738ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e91a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1567 | PC: 0x130770 | FDE: 0x1e91c0 | Size: 256 bytes [PyThreadState_New]
// Khung tháo gỡ #1567 | Địa chỉ PC: 0x130770 | Địa chỉ FDE: 0x1e91c0 | Kích thước: 256 bytes
//   0x130770: 52800021  mov      w1, #1
//   0x130774: 14000001  b        #0x130778
//   0x130778: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13077c: A9014FF4  stp      x20, x19, [sp, #0x10]
static inline uint64_t fde_func_1567_0x130770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130770ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e91c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1568 | PC: 0x1308ac | FDE: 0x1e9200 | Size: 8 bytes [_PyThreadState_Prealloc]
// Khung tháo gỡ #1568 | Địa chỉ PC: 0x1308ac | Địa chỉ FDE: 0x1e9200 | Kích thước: 8 bytes
//   0x1308ac: 2A1F03E1  mov      w1, wzr
//   0x1308b0: 17FFFFB2  b        #0x130778
static inline uint64_t fde_func_1568_0x1308ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1308acULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17ffffb2ULL) ^ 0x1e9200ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1569 | PC: 0x1308b4 | FDE: 0x1e9218 | Size: 104 bytes [_PyThreadState_Init]
// Khung tháo gỡ #1569 | Địa chỉ PC: 0x1308b4 | Địa chỉ FDE: 0x1e9218 | Kích thước: 104 bytes
//   0x1308b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1308b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1308bc: 910043FD  add      x29, sp, #0x10
//   0x1308c0: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1569_0x1308b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1308b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9218ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1570 | PC: 0x13091c | FDE: 0x1e9238 | Size: 124 bytes [PyState_FindModule]
// Khung tháo gỡ #1570 | Địa chỉ PC: 0x13091c | Địa chỉ FDE: 0x1e9238 | Kích thước: 124 bytes
//   0x13091c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x130920: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130924: 910043FD  add      x29, sp, #0x10
//   0x130928: F0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1570_0x13091c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13091cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9238ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1571 | PC: 0x130998 | FDE: 0x1e9258 | Size: 192 bytes [_PyState_AddModule]
// Khung tháo gỡ #1571 | Địa chỉ PC: 0x130998 | Địa chỉ FDE: 0x1e9258 | Kích thước: 192 bytes
//   0x130998: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13099c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1309a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1309a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1571_0x130998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130998ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9258ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1572 | PC: 0x130a58 | FDE: 0x1e9280 | Size: 148 bytes [PyState_AddModule]
// Khung tháo gỡ #1572 | Địa chỉ PC: 0x130a58 | Địa chỉ FDE: 0x1e9280 | Kích thước: 148 bytes
//   0x130a58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x130a5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130a60: 910043FD  add      x29, sp, #0x10
//   0x130a64: B40002E1  cbz      x1, #0x130ac0
static inline uint64_t fde_func_1572_0x130a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130a58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9280ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1573 | PC: 0x130aec | FDE: 0x1e92a0 | Size: 204 bytes [PyState_RemoveModule]
// Khung tháo gỡ #1573 | Địa chỉ PC: 0x130aec | Địa chỉ FDE: 0x1e92a0 | Kích thước: 204 bytes
//   0x130aec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x130af0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130af4: 910043FD  add      x29, sp, #0x10
//   0x130af8: F0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1573_0x130aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130aecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e92a0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1574 | PC: 0x130bb8 | FDE: 0x1e92c0 | Size: 212 bytes [_PyInterpreterState_ClearModules]
// Khung tháo gỡ #1574 | Địa chỉ PC: 0x130bb8 | Địa chỉ FDE: 0x1e92c0 | Kích thước: 212 bytes
//   0x130bb8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130bbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130bc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130bc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1574_0x130bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130bb8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e92c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1575 | PC: 0x130c8c | FDE: 0x1e92e8 | Size: 256 bytes [PyThreadState_Clear]
// Khung tháo gỡ #1575 | Địa chỉ PC: 0x130c8c | Địa chỉ FDE: 0x1e92e8 | Kích thước: 256 bytes
//   0x130c8c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130c90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130c94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130c98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1575_0x130c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130c8cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e92e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1576 | PC: 0x130f44 | FDE: 0x1e9310 | Size: 8 bytes [_PyInterpreterState_GetConfig]
// Khung tháo gỡ #1576 | Địa chỉ PC: 0x130f44 | Địa chỉ FDE: 0x1e9310 | Kích thước: 8 bytes
//   0x130f44: 91120000  add      x0, x0, #0x480
//   0x130f48: D65F03C0  ret      
static inline uint64_t fde_func_1576_0x130f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130f44ULL ^ (static_cast<uint64_t>(0x91120000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9310ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1577 | PC: 0x130f4c | FDE: 0x1e9328 | Size: 88 bytes [PyThreadState_Delete]
// Khung tháo gỡ #1577 | Địa chỉ PC: 0x130f4c | Địa chỉ FDE: 0x1e9328 | Kích thước: 88 bytes
//   0x130f4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x130f50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130f54: 910043FD  add      x29, sp, #0x10
//   0x130f58: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1577_0x130f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130f4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9328ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1578 | PC: 0x130fa4 | FDE: 0x1e9348 | Size: 256 bytes [_PyThreadState_DeleteCurrent]
// Khung tháo gỡ #1578 | Địa chỉ PC: 0x130fa4 | Địa chỉ FDE: 0x1e9348 | Kích thước: 256 bytes
//   0x130fa4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x130fa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130fac: 910043FD  add      x29, sp, #0x10
//   0x130fb0: B40001A0  cbz      x0, #0x130fe4
static inline uint64_t fde_func_1578_0x130fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130fa4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1579 | PC: 0x1310b4 | FDE: 0x1e9390 | Size: 88 bytes [PyThreadState_DeleteCurrent]
// Khung tháo gỡ #1579 | Địa chỉ PC: 0x1310b4 | Địa chỉ FDE: 0x1e9390 | Kích thước: 88 bytes
//   0x1310b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1310b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1310bc: 910043FD  add      x29, sp, #0x10
//   0x1310c0: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1579_0x1310b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1310b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9390ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1580 | PC: 0x13110c | FDE: 0x1e93b0 | Size: 160 bytes [_PyThreadState_DeleteExcept]
// Khung tháo gỡ #1580 | Địa chỉ PC: 0x13110c | Địa chỉ FDE: 0x1e93b0 | Kích thước: 160 bytes
//   0x13110c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131110: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131114: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131118: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1580_0x13110c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13110cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e93b0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1581 | PC: 0x1311ac | FDE: 0x1e93d8 | Size: 16 bytes [_PyThreadState_GetTSS]
// Khung tháo gỡ #1581 | Địa chỉ PC: 0x1311ac | Địa chỉ FDE: 0x1e93d8 | Kích thước: 16 bytes
//   0x1311ac: D0000668  adrp     x8, #0x1ff000
//   0x1311b0: F943B908  ldr      x8, [x8, #0x770]
//   0x1311b4: 9105C100  add      x0, x8, #0x170
//   0x1311b8: 17FCAF92  b        #0x5d000
static inline uint64_t fde_func_1581_0x1311ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311acULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e93d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1582 | PC: 0x1311bc | FDE: 0x1e93f0 | Size: 16 bytes [_PyThreadState_UncheckedGet]
// Khung tháo gỡ #1582 | Địa chỉ PC: 0x1311bc | Địa chỉ FDE: 0x1e93f0 | Kích thước: 16 bytes
//   0x1311bc: D0000668  adrp     x8, #0x1ff000
//   0x1311c0: F943B908  ldr      x8, [x8, #0x770]
//   0x1311c4: 9105C100  add      x0, x8, #0x170
//   0x1311c8: 17FCAF8E  b        #0x5d000
static inline uint64_t fde_func_1582_0x1311bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311bcULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e93f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1583 | PC: 0x1311cc | FDE: 0x1e9408 | Size: 48 bytes [PyThreadState_Get]
// Khung tháo gỡ #1583 | Địa chỉ PC: 0x1311cc | Địa chỉ FDE: 0x1e9408 | Kích thước: 48 bytes
//   0x1311cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1311d0: 910003FD  mov      x29, sp
//   0x1311d4: D0000668  adrp     x8, #0x1ff000
//   0x1311d8: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1583_0x1311cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9408ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1584 | PC: 0x1311fc | FDE: 0x1e9428 | Size: 80 bytes [PyThreadState_Swap]
// Khung tháo gỡ #1584 | Địa chỉ PC: 0x1311fc | Địa chỉ FDE: 0x1e9428 | Kích thước: 80 bytes
//   0x1311fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131200: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131204: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131208: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1584_0x1311fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9428ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1585 | PC: 0x13124c | FDE: 0x1e9450 | Size: 60 bytes [_PyThreadState_GetDict]
// Khung tháo gỡ #1585 | Địa chỉ PC: 0x13124c | Địa chỉ FDE: 0x1e9450 | Kích thước: 60 bytes
//   0x13124c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131250: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131254: 910043FD  add      x29, sp, #0x10
//   0x131258: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1585_0x13124c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13124cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9450ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1586 | PC: 0x131288 | FDE: 0x1e9470 | Size: 80 bytes [PyThreadState_GetDict]
// Khung tháo gỡ #1586 | Địa chỉ PC: 0x131288 | Địa chỉ FDE: 0x1e9470 | Kích thước: 80 bytes
//   0x131288: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13128c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131290: 910043FD  add      x29, sp, #0x10
//   0x131294: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1586_0x131288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131288ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9470ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1587 | PC: 0x1312d8 | FDE: 0x1e9490 | Size: 8 bytes [PyThreadState_GetInterpreter]
// Khung tháo gỡ #1587 | Địa chỉ PC: 0x1312d8 | Địa chỉ FDE: 0x1e9490 | Kích thước: 8 bytes
//   0x1312d8: F9400800  ldr      x0, [x0, #0x10]
//   0x1312dc: D65F03C0  ret      
static inline uint64_t fde_func_1587_0x1312d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1312d8ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9490ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1588 | PC: 0x1312e0 | FDE: 0x1e94a8 | Size: 24 bytes [PyThreadState_GetFrame]
// Khung tháo gỡ #1588 | Địa chỉ PC: 0x1312e0 | Địa chỉ FDE: 0x1e94a8 | Kích thước: 24 bytes
//   0x1312e0: F9400C00  ldr      x0, [x0, #0x18]
//   0x1312e4: B4000080  cbz      x0, #0x1312f4
//   0x1312e8: F9400008  ldr      x8, [x0]
//   0x1312ec: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_1588_0x1312e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1312e0ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1e94a8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1589 | PC: 0x1312f8 | FDE: 0x1e94c0 | Size: 8 bytes [PyThreadState_GetID]
// Khung tháo gỡ #1589 | Địa chỉ PC: 0x1312f8 | Địa chỉ FDE: 0x1e94c0 | Kích thước: 8 bytes
//   0x1312f8: F9408000  ldr      x0, [x0, #0x100]
//   0x1312fc: D65F03C0  ret      
static inline uint64_t fde_func_1589_0x1312f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1312f8ULL ^ (static_cast<uint64_t>(0xf9408000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e94c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1590 | PC: 0x131300 | FDE: 0x1e94d8 | Size: 180 bytes [PyThreadState_SetAsyncExc]
// Khung tháo gỡ #1590 | Địa chỉ PC: 0x131300 | Địa chỉ FDE: 0x1e94d8 | Kích thước: 180 bytes
//   0x131300: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131304: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131308: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13130c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1590_0x131300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131300ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e94d8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1591 | PC: 0x1313b4 | FDE: 0x1e9500 | Size: 16 bytes [PyInterpreterState_Head]
// Khung tháo gỡ #1591 | Địa chỉ PC: 0x1313b4 | Địa chỉ FDE: 0x1e9500 | Kích thước: 16 bytes
//   0x1313b4: D0000668  adrp     x8, #0x1ff000
//   0x1313b8: F943B908  ldr      x8, [x8, #0x770]
//   0x1313bc: F9401100  ldr      x0, [x8, #0x20]
//   0x1313c0: D65F03C0  ret      
static inline uint64_t fde_func_1591_0x1313b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313b4ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e9500ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1592 | PC: 0x1313c4 | FDE: 0x1e9518 | Size: 16 bytes [PyInterpreterState_Main]
// Khung tháo gỡ #1592 | Địa chỉ PC: 0x1313c4 | Địa chỉ FDE: 0x1e9518 | Kích thước: 16 bytes
//   0x1313c4: D0000668  adrp     x8, #0x1ff000
//   0x1313c8: F943B908  ldr      x8, [x8, #0x770]
//   0x1313cc: F9401500  ldr      x0, [x8, #0x28]
//   0x1313d0: D65F03C0  ret      
static inline uint64_t fde_func_1592_0x1313c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313c4ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e9518ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1593 | PC: 0x1313d4 | FDE: 0x1e9530 | Size: 8 bytes [PyInterpreterState_Next]
// Khung tháo gỡ #1593 | Địa chỉ PC: 0x1313d4 | Địa chỉ FDE: 0x1e9530 | Kích thước: 8 bytes
//   0x1313d4: F9400000  ldr      x0, [x0]
//   0x1313d8: D65F03C0  ret      
static inline uint64_t fde_func_1593_0x1313d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313d4ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9530ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1594 | PC: 0x1313dc | FDE: 0x1e9548 | Size: 8 bytes [PyThreadState_Next]
// Khung tháo gỡ #1594 | Địa chỉ PC: 0x1313dc | Địa chỉ FDE: 0x1e9548 | Kích thước: 8 bytes
//   0x1313dc: F9400400  ldr      x0, [x0, #8]
//   0x1313e0: D65F03C0  ret      
static inline uint64_t fde_func_1594_0x1313dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313dcULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9548ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1595 | PC: 0x1313e4 | FDE: 0x1e9560 | Size: 256 bytes [_PyThread_CurrentFrames]
// Khung tháo gỡ #1595 | Địa chỉ PC: 0x1313e4 | Địa chỉ FDE: 0x1e9560 | Kích thước: 256 bytes
//   0x1313e4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1313e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1313ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1313f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1595_0x1313e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313e4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1596 | PC: 0x1314f8 | FDE: 0x1e9588 | Size: 256 bytes [_PyThread_CurrentExceptions]
// Khung tháo gỡ #1596 | Địa chỉ PC: 0x1314f8 | Địa chỉ FDE: 0x1e9588 | Kích thước: 256 bytes
//   0x1314f8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1314fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x131500: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x131504: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1596_0x1314f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1314f8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e9588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1597 | PC: 0x131690 | FDE: 0x1e95b8 | Size: 96 bytes [_PyGILState_Init]
// Khung tháo gỡ #1597 | Địa chỉ PC: 0x131690 | Địa chỉ FDE: 0x1e95b8 | Kích thước: 96 bytes
//   0x131690: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131694: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131698: 910043FD  add      x29, sp, #0x10
//   0x13169c: 9105C000  add      x0, x0, #0x170
static inline uint64_t fde_func_1597_0x131690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131690ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e95b8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1598 | PC: 0x1316f0 | FDE: 0x1e95d8 | Size: 144 bytes [_PyGILState_SetTstate]
// Khung tháo gỡ #1598 | Địa chỉ PC: 0x1316f0 | Địa chỉ FDE: 0x1e95d8 | Kích thước: 144 bytes
//   0x1316f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1316f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1316f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1316fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1598_0x1316f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1316f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e95d8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1599 | PC: 0x131780 | FDE: 0x1e95f8 | Size: 16 bytes [_PyGILState_GetInterpreterStateUnsafe]
// Khung tháo gỡ #1599 | Địa chỉ PC: 0x131780 | Địa chỉ FDE: 0x1e95f8 | Kích thước: 16 bytes
//   0x131780: D0000668  adrp     x8, #0x1ff000
//   0x131784: F943B908  ldr      x8, [x8, #0x770]
//   0x131788: F940B500  ldr      x0, [x8, #0x168]
//   0x13178c: D65F03C0  ret      
static inline uint64_t fde_func_1599_0x131780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131780ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e95f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1200: return fde_func_1200_0x0fe6d4(a0, a1);
        case 1201: return fde_func_1201_0x0fe8d0(a0, a1);
        case 1202: return fde_func_1202_0x0feb0c(a0, a1);
        case 1203: return fde_func_1203_0x0feba4(a0, a1);
        case 1204: return fde_func_1204_0x101800(a0, a1);
        case 1205: return fde_func_1205_0x101b88(a0, a1);
        case 1206: return fde_func_1206_0x101ca4(a0, a1);
        case 1207: return fde_func_1207_0x101dcc(a0, a1);
        case 1208: return fde_func_1208_0x101e6c(a0, a1);
        case 1209: return fde_func_1209_0x101f00(a0, a1);
        case 1210: return fde_func_1210_0x102d10(a0, a1);
        case 1211: return fde_func_1211_0x102e5c(a0, a1);
        case 1212: return fde_func_1212_0x102ffc(a0, a1);
        case 1213: return fde_func_1213_0x103384(a0, a1);
        case 1214: return fde_func_1214_0x103390(a0, a1);
        case 1215: return fde_func_1215_0x1040dc(a0, a1);
        case 1216: return fde_func_1216_0x104174(a0, a1);
        case 1217: return fde_func_1217_0x10420c(a0, a1);
        case 1218: return fde_func_1218_0x1042a4(a0, a1);
        case 1219: return fde_func_1219_0x10435c(a0, a1);
        case 1220: return fde_func_1220_0x1051f8(a0, a1);
        case 1221: return fde_func_1221_0x105208(a0, a1);
        case 1222: return fde_func_1222_0x1052ec(a0, a1);
        case 1223: return fde_func_1223_0x105304(a0, a1);
        case 1224: return fde_func_1224_0x108e10(a0, a1);
        case 1225: return fde_func_1225_0x109018(a0, a1);
        case 1226: return fde_func_1226_0x1090a4(a0, a1);
        case 1227: return fde_func_1227_0x1093e8(a0, a1);
        case 1228: return fde_func_1228_0x109428(a0, a1);
        case 1229: return fde_func_1229_0x109508(a0, a1);
        case 1230: return fde_func_1230_0x109514(a0, a1);
        case 1231: return fde_func_1231_0x109564(a0, a1);
        case 1232: return fde_func_1232_0x1095b4(a0, a1);
        case 1233: return fde_func_1233_0x109614(a0, a1);
        case 1234: return fde_func_1234_0x109674(a0, a1);
        case 1235: return fde_func_1235_0x1097a4(a0, a1);
        case 1236: return fde_func_1236_0x1097ac(a0, a1);
        case 1237: return fde_func_1237_0x1099b8(a0, a1);
        case 1238: return fde_func_1238_0x109bf8(a0, a1);
        case 1239: return fde_func_1239_0x109d18(a0, a1);
        case 1240: return fde_func_1240_0x109da8(a0, a1);
        case 1241: return fde_func_1241_0x109e38(a0, a1);
        case 1242: return fde_func_1242_0x109ed0(a0, a1);
        case 1243: return fde_func_1243_0x109f70(a0, a1);
        case 1244: return fde_func_1244_0x109fb4(a0, a1);
        case 1245: return fde_func_1245_0x10a0dc(a0, a1);
        case 1246: return fde_func_1246_0x10a33c(a0, a1);
        case 1247: return fde_func_1247_0x10a6fc(a0, a1);
        case 1248: return fde_func_1248_0x10abb4(a0, a1);
        case 1249: return fde_func_1249_0x10b910(a0, a1);
        case 1250: return fde_func_1250_0x10be0c(a0, a1);
        case 1251: return fde_func_1251_0x10bef0(a0, a1);
        case 1252: return fde_func_1252_0x10bf2c(a0, a1);
        case 1253: return fde_func_1253_0x10bf5c(a0, a1);
        case 1254: return fde_func_1254_0x10c24c(a0, a1);
        case 1255: return fde_func_1255_0x10c2e4(a0, a1);
        case 1256: return fde_func_1256_0x10c518(a0, a1);
        case 1257: return fde_func_1257_0x10c544(a0, a1);
        case 1258: return fde_func_1258_0x10c5b4(a0, a1);
        case 1259: return fde_func_1259_0x10c5bc(a0, a1);
        case 1260: return fde_func_1260_0x10c5e4(a0, a1);
        case 1261: return fde_func_1261_0x10c650(a0, a1);
        case 1262: return fde_func_1262_0x10c6c4(a0, a1);
        case 1263: return fde_func_1263_0x10c6dc(a0, a1);
        case 1264: return fde_func_1264_0x10c7b0(a0, a1);
        case 1265: return fde_func_1265_0x10c7b8(a0, a1);
        case 1266: return fde_func_1266_0x10c7e0(a0, a1);
        case 1267: return fde_func_1267_0x10ca44(a0, a1);
        case 1268: return fde_func_1268_0x10ca68(a0, a1);
        case 1269: return fde_func_1269_0x10caa4(a0, a1);
        case 1270: return fde_func_1270_0x10caf4(a0, a1);
        case 1271: return fde_func_1271_0x10cb88(a0, a1);
        case 1272: return fde_func_1272_0x10cc04(a0, a1);
        case 1273: return fde_func_1273_0x10ccac(a0, a1);
        case 1274: return fde_func_1274_0x10cd64(a0, a1);
        case 1275: return fde_func_1275_0x10cecc(a0, a1);
        case 1276: return fde_func_1276_0x10d008(a0, a1);
        case 1277: return fde_func_1277_0x10d1e0(a0, a1);
        case 1278: return fde_func_1278_0x10d29c(a0, a1);
        case 1279: return fde_func_1279_0x10d310(a0, a1);
        case 1280: return fde_func_1280_0x10d354(a0, a1);
        case 1281: return fde_func_1281_0x10d39c(a0, a1);
        case 1282: return fde_func_1282_0x10d3b8(a0, a1);
        case 1283: return fde_func_1283_0x10d51c(a0, a1);
        case 1284: return fde_func_1284_0x10d588(a0, a1);
        case 1285: return fde_func_1285_0x10d5a8(a0, a1);
        case 1286: return fde_func_1286_0x10d744(a0, a1);
        case 1287: return fde_func_1287_0x10d778(a0, a1);
        case 1288: return fde_func_1288_0x10d7d8(a0, a1);
        case 1289: return fde_func_1289_0x10d854(a0, a1);
        case 1290: return fde_func_1290_0x10d9b4(a0, a1);
        case 1291: return fde_func_1291_0x10da70(a0, a1);
        case 1292: return fde_func_1292_0x10dc4c(a0, a1);
        case 1293: return fde_func_1293_0x10dd38(a0, a1);
        case 1294: return fde_func_1294_0x10ddac(a0, a1);
        case 1295: return fde_func_1295_0x10e3e0(a0, a1);
        case 1296: return fde_func_1296_0x10e980(a0, a1);
        case 1297: return fde_func_1297_0x10e98c(a0, a1);
        case 1298: return fde_func_1298_0x10e994(a0, a1);
        case 1299: return fde_func_1299_0x10eaa8(a0, a1);
        case 1300: return fde_func_1300_0x10f360(a0, a1);
        case 1301: return fde_func_1301_0x10f364(a0, a1);
        case 1302: return fde_func_1302_0x10f3c4(a0, a1);
        case 1303: return fde_func_1303_0x10f514(a0, a1);
        case 1304: return fde_func_1304_0x10f574(a0, a1);
        case 1305: return fde_func_1305_0x10f94c(a0, a1);
        case 1306: return fde_func_1306_0x10f9e8(a0, a1);
        case 1307: return fde_func_1307_0x10fa84(a0, a1);
        case 1308: return fde_func_1308_0x10fb48(a0, a1);
        case 1309: return fde_func_1309_0x10fc0c(a0, a1);
        case 1310: return fde_func_1310_0x110290(a0, a1);
        case 1311: return fde_func_1311_0x110330(a0, a1);
        case 1312: return fde_func_1312_0x1103bc(a0, a1);
        case 1313: return fde_func_1313_0x110448(a0, a1);
        case 1314: return fde_func_1314_0x110498(a0, a1);
        case 1315: return fde_func_1315_0x111170(a0, a1);
        case 1316: return fde_func_1316_0x111238(a0, a1);
        case 1317: return fde_func_1317_0x1112cc(a0, a1);
        case 1318: return fde_func_1318_0x111360(a0, a1);
        case 1319: return fde_func_1319_0x11143c(a0, a1);
        case 1320: return fde_func_1320_0x111518(a0, a1);
        case 1321: return fde_func_1321_0x111e80(a0, a1);
        case 1322: return fde_func_1322_0x111f18(a0, a1);
        case 1323: return fde_func_1323_0x111fb8(a0, a1);
        case 1324: return fde_func_1324_0x112058(a0, a1);
        case 1325: return fde_func_1325_0x1120b8(a0, a1);
        case 1326: return fde_func_1326_0x112b1c(a0, a1);
        case 1327: return fde_func_1327_0x112c1c(a0, a1);
        case 1328: return fde_func_1328_0x112d48(a0, a1);
        case 1329: return fde_func_1329_0x112e48(a0, a1);
        case 1330: return fde_func_1330_0x112eb8(a0, a1);
        case 1331: return fde_func_1331_0x112f28(a0, a1);
        case 1332: return fde_func_1332_0x112f70(a0, a1);
        case 1333: return fde_func_1333_0x1150ac(a0, a1);
        case 1334: return fde_func_1334_0x1150b8(a0, a1);
        case 1335: return fde_func_1335_0x1150c4(a0, a1);
        case 1336: return fde_func_1336_0x1150d0(a0, a1);
        case 1337: return fde_func_1337_0x115124(a0, a1);
        case 1338: return fde_func_1338_0x115128(a0, a1);
        case 1339: return fde_func_1339_0x115134(a0, a1);
        case 1340: return fde_func_1340_0x115148(a0, a1);
        case 1341: return fde_func_1341_0x1151c4(a0, a1);
        case 1342: return fde_func_1342_0x1153c8(a0, a1);
        case 1343: return fde_func_1343_0x115498(a0, a1);
        case 1344: return fde_func_1344_0x1154b8(a0, a1);
        case 1345: return fde_func_1345_0x11553c(a0, a1);
        case 1346: return fde_func_1346_0x115680(a0, a1);
        case 1347: return fde_func_1347_0x115750(a0, a1);
        case 1348: return fde_func_1348_0x1157f4(a0, a1);
        case 1349: return fde_func_1349_0x115898(a0, a1);
        case 1350: return fde_func_1350_0x1158b4(a0, a1);
        case 1351: return fde_func_1351_0x115a8c(a0, a1);
        case 1352: return fde_func_1352_0x115b10(a0, a1);
        case 1353: return fde_func_1353_0x115bb4(a0, a1);
        case 1354: return fde_func_1354_0x115c28(a0, a1);
        case 1355: return fde_func_1355_0x115ce0(a0, a1);
        case 1356: return fde_func_1356_0x115d44(a0, a1);
        case 1357: return fde_func_1357_0x115dc0(a0, a1);
        case 1358: return fde_func_1358_0x115e00(a0, a1);
        case 1359: return fde_func_1359_0x115e10(a0, a1);
        case 1360: return fde_func_1360_0x115e30(a0, a1);
        case 1361: return fde_func_1361_0x115f64(a0, a1);
        case 1362: return fde_func_1362_0x115fa8(a0, a1);
        case 1363: return fde_func_1363_0x115fec(a0, a1);
        case 1364: return fde_func_1364_0x117090(a0, a1);
        case 1365: return fde_func_1365_0x1170a0(a0, a1);
        case 1366: return fde_func_1366_0x117240(a0, a1);
        case 1367: return fde_func_1367_0x1172b4(a0, a1);
        case 1368: return fde_func_1368_0x11748c(a0, a1);
        case 1369: return fde_func_1369_0x1174dc(a0, a1);
        case 1370: return fde_func_1370_0x11753c(a0, a1);
        case 1371: return fde_func_1371_0x1176f4(a0, a1);
        case 1372: return fde_func_1372_0x1176fc(a0, a1);
        case 1373: return fde_func_1373_0x117980(a0, a1);
        case 1374: return fde_func_1374_0x117b7c(a0, a1);
        case 1375: return fde_func_1375_0x117dac(a0, a1);
        case 1376: return fde_func_1376_0x117dfc(a0, a1);
        case 1377: return fde_func_1377_0x117e58(a0, a1);
        case 1378: return fde_func_1378_0x118164(a0, a1);
        case 1379: return fde_func_1379_0x118aa8(a0, a1);
        case 1380: return fde_func_1380_0x118b18(a0, a1);
        case 1381: return fde_func_1381_0x118c58(a0, a1);
        case 1382: return fde_func_1382_0x118eb4(a0, a1);
        case 1383: return fde_func_1383_0x118ec0(a0, a1);
        case 1384: return fde_func_1384_0x119150(a0, a1);
        case 1385: return fde_func_1385_0x119284(a0, a1);
        case 1386: return fde_func_1386_0x1192d4(a0, a1);
        case 1387: return fde_func_1387_0x11a3d4(a0, a1);
        case 1388: return fde_func_1388_0x11a968(a0, a1);
        case 1389: return fde_func_1389_0x11abf4(a0, a1);
        case 1390: return fde_func_1390_0x11ac00(a0, a1);
        case 1391: return fde_func_1391_0x11ac14(a0, a1);
        case 1392: return fde_func_1392_0x11ac38(a0, a1);
        case 1393: return fde_func_1393_0x11ac50(a0, a1);
        case 1394: return fde_func_1394_0x11ac60(a0, a1);
        case 1395: return fde_func_1395_0x11ac70(a0, a1);
        case 1396: return fde_func_1396_0x11ac80(a0, a1);
        case 1397: return fde_func_1397_0x11acf8(a0, a1);
        case 1398: return fde_func_1398_0x11ad4c(a0, a1);
        case 1399: return fde_func_1399_0x11ae70(a0, a1);
        case 1400: return fde_func_1400_0x11af74(a0, a1);
        case 1401: return fde_func_1401_0x11af80(a0, a1);
        case 1402: return fde_func_1402_0x11aff4(a0, a1);
        case 1403: return fde_func_1403_0x11b088(a0, a1);
        case 1404: return fde_func_1404_0x11b160(a0, a1);
        case 1405: return fde_func_1405_0x11b1e0(a0, a1);
        case 1406: return fde_func_1406_0x11b284(a0, a1);
        case 1407: return fde_func_1407_0x11b2a0(a0, a1);
        case 1408: return fde_func_1408_0x11b4d8(a0, a1);
        case 1409: return fde_func_1409_0x11b574(a0, a1);
        case 1410: return fde_func_1410_0x11b620(a0, a1);
        case 1411: return fde_func_1411_0x11b6b4(a0, a1);
        case 1412: return fde_func_1412_0x11b780(a0, a1);
        case 1413: return fde_func_1413_0x11b864(a0, a1);
        case 1414: return fde_func_1414_0x11be8c(a0, a1);
        case 1415: return fde_func_1415_0x11d190(a0, a1);
        case 1416: return fde_func_1416_0x11e2ec(a0, a1);
        case 1417: return fde_func_1417_0x11e5ec(a0, a1);
        case 1418: return fde_func_1418_0x11e670(a0, a1);
        case 1419: return fde_func_1419_0x11e704(a0, a1);
        case 1420: return fde_func_1420_0x11e794(a0, a1);
        case 1421: return fde_func_1421_0x11e864(a0, a1);
        case 1422: return fde_func_1422_0x120828(a0, a1);
        case 1423: return fde_func_1423_0x120830(a0, a1);
        case 1424: return fde_func_1424_0x121000(a0, a1);
        case 1425: return fde_func_1425_0x1214bc(a0, a1);
        case 1426: return fde_func_1426_0x121574(a0, a1);
        case 1427: return fde_func_1427_0x12197c(a0, a1);
        case 1428: return fde_func_1428_0x123f48(a0, a1);
        case 1429: return fde_func_1429_0x123fc8(a0, a1);
        case 1430: return fde_func_1430_0x124050(a0, a1);
        case 1431: return fde_func_1431_0x1241a4(a0, a1);
        case 1432: return fde_func_1432_0x124244(a0, a1);
        case 1433: return fde_func_1433_0x1243b0(a0, a1);
        case 1434: return fde_func_1434_0x124570(a0, a1);
        case 1435: return fde_func_1435_0x1268f4(a0, a1);
        case 1436: return fde_func_1436_0x126988(a0, a1);
        case 1437: return fde_func_1437_0x126a78(a0, a1);
        case 1438: return fde_func_1438_0x126b6c(a0, a1);
        case 1439: return fde_func_1439_0x126c18(a0, a1);
        case 1440: return fde_func_1440_0x126cc8(a0, a1);
        case 1441: return fde_func_1441_0x126ebc(a0, a1);
        case 1442: return fde_func_1442_0x126f14(a0, a1);
        case 1443: return fde_func_1443_0x126ff0(a0, a1);
        case 1444: return fde_func_1444_0x127034(a0, a1);
        case 1445: return fde_func_1445_0x1270a4(a0, a1);
        case 1446: return fde_func_1446_0x127114(a0, a1);
        case 1447: return fde_func_1447_0x127e30(a0, a1);
        case 1448: return fde_func_1448_0x127f00(a0, a1);
        case 1449: return fde_func_1449_0x127f88(a0, a1);
        case 1450: return fde_func_1450_0x128248(a0, a1);
        case 1451: return fde_func_1451_0x1282e0(a0, a1);
        case 1452: return fde_func_1452_0x1283a0(a0, a1);
        case 1453: return fde_func_1453_0x128650(a0, a1);
        case 1454: return fde_func_1454_0x1288fc(a0, a1);
        case 1455: return fde_func_1455_0x128da0(a0, a1);
        case 1456: return fde_func_1456_0x128ef0(a0, a1);
        case 1457: return fde_func_1457_0x128f88(a0, a1);
        case 1458: return fde_func_1458_0x129028(a0, a1);
        case 1459: return fde_func_1459_0x1290c8(a0, a1);
        case 1460: return fde_func_1460_0x1290d8(a0, a1);
        case 1461: return fde_func_1461_0x1290e8(a0, a1);
        case 1462: return fde_func_1462_0x1290f8(a0, a1);
        case 1463: return fde_func_1463_0x129108(a0, a1);
        case 1464: return fde_func_1464_0x129118(a0, a1);
        case 1465: return fde_func_1465_0x129128(a0, a1);
        case 1466: return fde_func_1466_0x129318(a0, a1);
        case 1467: return fde_func_1467_0x1294dc(a0, a1);
        case 1468: return fde_func_1468_0x129544(a0, a1);
        case 1469: return fde_func_1469_0x129600(a0, a1);
        case 1470: return fde_func_1470_0x129760(a0, a1);
        case 1471: return fde_func_1471_0x129784(a0, a1);
        case 1472: return fde_func_1472_0x129794(a0, a1);
        case 1473: return fde_func_1473_0x129830(a0, a1);
        case 1474: return fde_func_1474_0x129af8(a0, a1);
        case 1475: return fde_func_1475_0x129ba4(a0, a1);
        case 1476: return fde_func_1476_0x129bd8(a0, a1);
        case 1477: return fde_func_1477_0x129bf8(a0, a1);
        case 1478: return fde_func_1478_0x129c18(a0, a1);
        case 1479: return fde_func_1479_0x129c3c(a0, a1);
        case 1480: return fde_func_1480_0x129c94(a0, a1);
        case 1481: return fde_func_1481_0x129d48(a0, a1);
        case 1482: return fde_func_1482_0x129d8c(a0, a1);
        case 1483: return fde_func_1483_0x12a094(a0, a1);
        case 1484: return fde_func_1484_0x12a114(a0, a1);
        case 1485: return fde_func_1485_0x12a1c0(a0, a1);
        case 1486: return fde_func_1486_0x12a870(a0, a1);
        case 1487: return fde_func_1487_0x12a9b4(a0, a1);
        case 1488: return fde_func_1488_0x12aa50(a0, a1);
        case 1489: return fde_func_1489_0x12aaa0(a0, a1);
        case 1490: return fde_func_1490_0x12ab4c(a0, a1);
        case 1491: return fde_func_1491_0x12ab94(a0, a1);
        case 1492: return fde_func_1492_0x12ab9c(a0, a1);
        case 1493: return fde_func_1493_0x12acfc(a0, a1);
        case 1494: return fde_func_1494_0x12ad10(a0, a1);
        case 1495: return fde_func_1495_0x12ad18(a0, a1);
        case 1496: return fde_func_1496_0x12ad4c(a0, a1);
        case 1497: return fde_func_1497_0x12ad50(a0, a1);
        case 1498: return fde_func_1498_0x12ad5c(a0, a1);
        case 1499: return fde_func_1499_0x12b090(a0, a1);
        case 1500: return fde_func_1500_0x12b0a0(a0, a1);
        case 1501: return fde_func_1501_0x12b0d0(a0, a1);
        case 1502: return fde_func_1502_0x12b0f4(a0, a1);
        case 1503: return fde_func_1503_0x12b10c(a0, a1);
        case 1504: return fde_func_1504_0x12b11c(a0, a1);
        case 1505: return fde_func_1505_0x12b12c(a0, a1);
        case 1506: return fde_func_1506_0x12b188(a0, a1);
        case 1507: return fde_func_1507_0x12b1e8(a0, a1);
        case 1508: return fde_func_1508_0x12b1f0(a0, a1);
        case 1509: return fde_func_1509_0x12b2e8(a0, a1);
        case 1510: return fde_func_1510_0x12b4cc(a0, a1);
        case 1511: return fde_func_1511_0x12b678(a0, a1);
        case 1512: return fde_func_1512_0x12b6d0(a0, a1);
        case 1513: return fde_func_1513_0x12b724(a0, a1);
        case 1514: return fde_func_1514_0x12b72c(a0, a1);
        case 1515: return fde_func_1515_0x12b840(a0, a1);
        case 1516: return fde_func_1516_0x12bd38(a0, a1);
        case 1517: return fde_func_1517_0x12be5c(a0, a1);
        case 1518: return fde_func_1518_0x12beb0(a0, a1);
        case 1519: return fde_func_1519_0x12beb8(a0, a1);
        case 1520: return fde_func_1520_0x12bff8(a0, a1);
        case 1521: return fde_func_1521_0x12cc30(a0, a1);
        case 1522: return fde_func_1522_0x12cccc(a0, a1);
        case 1523: return fde_func_1523_0x12ccd0(a0, a1);
        case 1524: return fde_func_1524_0x12ced8(a0, a1);
        case 1525: return fde_func_1525_0x12cee0(a0, a1);
        case 1526: return fde_func_1526_0x12d064(a0, a1);
        case 1527: return fde_func_1527_0x12d09c(a0, a1);
        case 1528: return fde_func_1528_0x12d334(a0, a1);
        case 1529: return fde_func_1529_0x12d844(a0, a1);
        case 1530: return fde_func_1530_0x12d9cc(a0, a1);
        case 1531: return fde_func_1531_0x12da04(a0, a1);
        case 1532: return fde_func_1532_0x12da14(a0, a1);
        case 1533: return fde_func_1533_0x12da8c(a0, a1);
        case 1534: return fde_func_1534_0x12db04(a0, a1);
        case 1535: return fde_func_1535_0x12db5c(a0, a1);
        case 1536: return fde_func_1536_0x12dbd4(a0, a1);
        case 1537: return fde_func_1537_0x12dc1c(a0, a1);
        case 1538: return fde_func_1538_0x12ddb8(a0, a1);
        case 1539: return fde_func_1539_0x12de74(a0, a1);
        case 1540: return fde_func_1540_0x12df30(a0, a1);
        case 1541: return fde_func_1541_0x12dfa0(a0, a1);
        case 1542: return fde_func_1542_0x12e060(a0, a1);
        case 1543: return fde_func_1543_0x12e0ac(a0, a1);
        case 1544: return fde_func_1544_0x12e164(a0, a1);
        case 1545: return fde_func_1545_0x12e1b0(a0, a1);
        case 1546: return fde_func_1546_0x12f8d8(a0, a1);
        case 1547: return fde_func_1547_0x12fa44(a0, a1);
        case 1548: return fde_func_1548_0x12fad0(a0, a1);
        case 1549: return fde_func_1549_0x12fbc4(a0, a1);
        case 1550: return fde_func_1550_0x12fc7c(a0, a1);
        case 1551: return fde_func_1551_0x12fdcc(a0, a1);
        case 1552: return fde_func_1552_0x130114(a0, a1);
        case 1553: return fde_func_1553_0x130120(a0, a1);
        case 1554: return fde_func_1554_0x130240(a0, a1);
        case 1555: return fde_func_1555_0x130290(a0, a1);
        case 1556: return fde_func_1556_0x130434(a0, a1);
        case 1557: return fde_func_1557_0x130480(a0, a1);
        case 1558: return fde_func_1558_0x1304bc(a0, a1);
        case 1559: return fde_func_1559_0x130558(a0, a1);
        case 1560: return fde_func_1560_0x1305b8(a0, a1);
        case 1561: return fde_func_1561_0x13062c(a0, a1);
        case 1562: return fde_func_1562_0x1306d4(a0, a1);
        case 1563: return fde_func_1563_0x1306dc(a0, a1);
        case 1564: return fde_func_1564_0x1306e4(a0, a1);
        case 1565: return fde_func_1565_0x1306f4(a0, a1);
        case 1566: return fde_func_1566_0x130738(a0, a1);
        case 1567: return fde_func_1567_0x130770(a0, a1);
        case 1568: return fde_func_1568_0x1308ac(a0, a1);
        case 1569: return fde_func_1569_0x1308b4(a0, a1);
        case 1570: return fde_func_1570_0x13091c(a0, a1);
        case 1571: return fde_func_1571_0x130998(a0, a1);
        case 1572: return fde_func_1572_0x130a58(a0, a1);
        case 1573: return fde_func_1573_0x130aec(a0, a1);
        case 1574: return fde_func_1574_0x130bb8(a0, a1);
        case 1575: return fde_func_1575_0x130c8c(a0, a1);
        case 1576: return fde_func_1576_0x130f44(a0, a1);
        case 1577: return fde_func_1577_0x130f4c(a0, a1);
        case 1578: return fde_func_1578_0x130fa4(a0, a1);
        case 1579: return fde_func_1579_0x1310b4(a0, a1);
        case 1580: return fde_func_1580_0x13110c(a0, a1);
        case 1581: return fde_func_1581_0x1311ac(a0, a1);
        case 1582: return fde_func_1582_0x1311bc(a0, a1);
        case 1583: return fde_func_1583_0x1311cc(a0, a1);
        case 1584: return fde_func_1584_0x1311fc(a0, a1);
        case 1585: return fde_func_1585_0x13124c(a0, a1);
        case 1586: return fde_func_1586_0x131288(a0, a1);
        case 1587: return fde_func_1587_0x1312d8(a0, a1);
        case 1588: return fde_func_1588_0x1312e0(a0, a1);
        case 1589: return fde_func_1589_0x1312f8(a0, a1);
        case 1590: return fde_func_1590_0x131300(a0, a1);
        case 1591: return fde_func_1591_0x1313b4(a0, a1);
        case 1592: return fde_func_1592_0x1313c4(a0, a1);
        case 1593: return fde_func_1593_0x1313d4(a0, a1);
        case 1594: return fde_func_1594_0x1313dc(a0, a1);
        case 1595: return fde_func_1595_0x1313e4(a0, a1);
        case 1596: return fde_func_1596_0x1314f8(a0, a1);
        case 1597: return fde_func_1597_0x131690(a0, a1);
        case 1598: return fde_func_1598_0x1316f0(a0, a1);
        case 1599: return fde_func_1599_0x131780(a0, a1);
        default: return 0ULL;
    }
}