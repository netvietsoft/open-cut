// ============================================================================
// Clean-Room C++17 AArch64 Complementary FDE Shard 4/5 for libpythonA_RelWithDebInfo.so
// Phân mảnh Khung Tháo Gỡ (FDE) Bổ Sung AArch64 C++17 sạch 4/5 cho libpythonA_RelWithDebInfo.so
// Covers FDE indices [3392 .. 3855] out of 4,320 total FDEs
// Bao phủ chỉ số FDE [3392 .. 3855] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_rel_core.h"

// FDE #3392 | PC: 0x158808 | FDE: 0x1ed7e0 | Size: 256 bytes
// Khung tháo gỡ #3392 | Địa chỉ PC: 0x158808 | Địa chỉ FDE: 0x1ed7e0 | Kích thước: 256 bytes
//   0x158808: D10143FF  sub      sp, sp, #0x50
//   0x15880c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x158810: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x158814: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3392_0x158808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158808ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ed7e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3393 | PC: 0x158968 | FDE: 0x1ed808 | Size: 144 bytes
// Khung tháo gỡ #3393 | Địa chỉ PC: 0x158968 | Địa chỉ FDE: 0x1ed808 | Kích thước: 144 bytes
//   0x158968: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x15896c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x158970: 910043FD  add      x29, sp, #0x10
//   0x158974: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3393_0x158968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158968ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed808ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3394 | PC: 0x1589f8 | FDE: 0x1ed828 | Size: 192 bytes [PyNumber_AsOff_t]
// Khung tháo gỡ #3394 | Địa chỉ PC: 0x1589f8 | Địa chỉ FDE: 0x1ed828 | Kích thước: 192 bytes
//   0x1589f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1589fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x158a00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x158a04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3394_0x1589f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1589f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed828ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3395 | PC: 0x158ab8 | FDE: 0x1ed850 | Size: 76 bytes [_PyIO_get_module_state]
// Khung tháo gỡ #3395 | Địa chỉ PC: 0x158ab8 | Địa chỉ FDE: 0x1ed850 | Kích thước: 76 bytes
//   0x158ab8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x158abc: 910003FD  mov      x29, sp
//   0x158ac0: F0000520  adrp     x0, #0x1ff000
//   0x158ac4: F9449C00  ldr      x0, [x0, #0x938]
static inline uint64_t fde_func_3395_0x158ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158ab8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed850ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3396 | PC: 0x158b04 | FDE: 0x1ed870 | Size: 100 bytes
// Khung tháo gỡ #3396 | Địa chỉ PC: 0x158b04 | Địa chỉ FDE: 0x1ed870 | Kích thước: 100 bytes
//   0x158b04: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x158b08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x158b0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x158b10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3396_0x158b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158b04ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed870ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #3397 | PC: 0x158b68 | FDE: 0x1ed890 | Size: 108 bytes
// Khung tháo gỡ #3397 | Địa chỉ PC: 0x158b68 | Địa chỉ FDE: 0x1ed890 | Kích thước: 108 bytes
//   0x158b68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x158b6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x158b70: 910043FD  add      x29, sp, #0x10
//   0x158b74: 97FC04C3  bl       #0x59e80
static inline uint64_t fde_func_3397_0x158b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158b68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed890ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3398 | PC: 0x158bd4 | FDE: 0x1ed8b0 | Size: 120 bytes
// Khung tháo gỡ #3398 | Địa chỉ PC: 0x158bd4 | Địa chỉ FDE: 0x1ed8b0 | Kích thước: 120 bytes
//   0x158bd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x158bd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x158bdc: 910043FD  add      x29, sp, #0x10
//   0x158be0: 97FC04A8  bl       #0x59e80
static inline uint64_t fde_func_3398_0x158bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158bd4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed8b0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3399 | PC: 0x158c4c | FDE: 0x1ed8d0 | Size: 256 bytes [PyInit__io]
// Khung tháo gỡ #3399 | Địa chỉ PC: 0x158c4c | Địa chỉ FDE: 0x1ed8d0 | Kích thước: 256 bytes
//   0x158c4c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x158c50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x158c54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x158c58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3399_0x158c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158c4cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ed8d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3400 | PC: 0x15a2b8 | FDE: 0x1ed8f8 | Size: 256 bytes
// Khung tháo gỡ #3400 | Địa chỉ PC: 0x15a2b8 | Địa chỉ FDE: 0x1ed8f8 | Kích thước: 256 bytes
//   0x15a2b8: D10483FF  sub      sp, sp, #0x120
//   0x15a2bc: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x15a2c0: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x15a2c4: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_3400_0x15a2b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a2b8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1ed8f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3401 | PC: 0x15acfc | FDE: 0x1ed928 | Size: 256 bytes
// Khung tháo gỡ #3401 | Địa chỉ PC: 0x15acfc | Địa chỉ FDE: 0x1ed928 | Kích thước: 256 bytes
//   0x15acfc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15ad00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15ad04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15ad08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3401_0x15acfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15acfcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3402 | PC: 0x15ae04 | FDE: 0x1ed948 | Size: 232 bytes
// Khung tháo gỡ #3402 | Địa chỉ PC: 0x15ae04 | Địa chỉ FDE: 0x1ed948 | Kích thước: 232 bytes
//   0x15ae04: D10103FF  sub      sp, sp, #0x40
//   0x15ae08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15ae0c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x15ae10: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3402_0x15ae04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ae04ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ed948ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3403 | PC: 0x15aeec | FDE: 0x1ed968 | Size: 4 bytes [bd_buffered_close_extern]
// Khung tháo gỡ #3403 | Địa chỉ PC: 0x15aeec | Địa chỉ FDE: 0x1ed968 | Kích thước: 4 bytes
//   0x15aeec: 14000001  b        #0x15aef0
static inline uint64_t fde_func_3403_0x15aeec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15aeecULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x1ed968ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3404 | PC: 0x15aef0 | FDE: 0x1ed980 | Size: 256 bytes
// Khung tháo gỡ #3404 | Địa chỉ PC: 0x15aef0 | Địa chỉ FDE: 0x1ed980 | Kích thước: 256 bytes
//   0x15aef0: D10183FF  sub      sp, sp, #0x60
//   0x15aef4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x15aef8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x15aefc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_3404_0x15aef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15aef0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1ed980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3405 | PC: 0x15b1c8 | FDE: 0x1ed9a8 | Size: 256 bytes [_PyIO_trap_eintr]
// Khung tháo gỡ #3405 | Địa chỉ PC: 0x15b1c8 | Địa chỉ FDE: 0x1ed9a8 | Kích thước: 256 bytes
//   0x15b1c8: D10103FF  sub      sp, sp, #0x40
//   0x15b1cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15b1d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x15b1d4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3405_0x15b1c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b1c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ed9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3406 | PC: 0x15b2dc | FDE: 0x1ed9c8 | Size: 184 bytes
// Khung tháo gỡ #3406 | Địa chỉ PC: 0x15b2dc | Địa chỉ FDE: 0x1ed9c8 | Kích thước: 184 bytes
//   0x15b2dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15b2e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15b2e4: 910043FD  add      x29, sp, #0x10
//   0x15b2e8: 52800028  mov      w8, #1
static inline uint64_t fde_func_3406_0x15b2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b2dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ed9c8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #3407 | PC: 0x15b394 | FDE: 0x1ed9e8 | Size: 256 bytes
// Khung tháo gỡ #3407 | Địa chỉ PC: 0x15b394 | Địa chỉ FDE: 0x1ed9e8 | Kích thước: 256 bytes
//   0x15b394: D10103FF  sub      sp, sp, #0x40
//   0x15b398: F9000BF5  str      x21, [sp, #0x10]
//   0x15b39c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15b3a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3407_0x15b394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b394ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ed9e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3408 | PC: 0x15b4bc | FDE: 0x1eda08 | Size: 88 bytes
// Khung tháo gỡ #3408 | Địa chỉ PC: 0x15b4bc | Địa chỉ FDE: 0x1eda08 | Kích thước: 88 bytes
//   0x15b4bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15b4c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15b4c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15b4c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3408_0x15b4bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b4bcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eda08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3409 | PC: 0x15b514 | FDE: 0x1eda28 | Size: 112 bytes
// Khung tháo gỡ #3409 | Địa chỉ PC: 0x15b514 | Địa chỉ FDE: 0x1eda28 | Kích thước: 112 bytes
//   0x15b514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15b518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15b51c: 910043FD  add      x29, sp, #0x10
//   0x15b520: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3409_0x15b514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b514ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eda28ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3410 | PC: 0x15b584 | FDE: 0x1eda48 | Size: 256 bytes
// Khung tháo gỡ #3410 | Địa chỉ PC: 0x15b584 | Địa chỉ FDE: 0x1eda48 | Kích thước: 256 bytes
//   0x15b584: D10143FF  sub      sp, sp, #0x50
//   0x15b588: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x15b58c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x15b590: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3410_0x15b584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b584ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eda48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3411 | PC: 0x15b9d4 | FDE: 0x1eda70 | Size: 256 bytes
// Khung tháo gỡ #3411 | Địa chỉ PC: 0x15b9d4 | Địa chỉ FDE: 0x1eda70 | Kích thước: 256 bytes
//   0x15b9d4: D10183FF  sub      sp, sp, #0x60
//   0x15b9d8: F90013F7  str      x23, [sp, #0x20]
//   0x15b9dc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x15b9e0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3411_0x15b9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b9d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1eda70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3412 | PC: 0x15bb98 | FDE: 0x1eda98 | Size: 256 bytes
// Khung tháo gỡ #3412 | Địa chỉ PC: 0x15bb98 | Địa chỉ FDE: 0x1eda98 | Kích thước: 256 bytes
//   0x15bb98: D10183FF  sub      sp, sp, #0x60
//   0x15bb9c: F90013F7  str      x23, [sp, #0x20]
//   0x15bba0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x15bba4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3412_0x15bb98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bb98ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1eda98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3413 | PC: 0x15bd64 | FDE: 0x1edac0 | Size: 172 bytes
// Khung tháo gỡ #3413 | Địa chỉ PC: 0x15bd64 | Địa chỉ FDE: 0x1edac0 | Kích thước: 172 bytes
//   0x15bd64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15bd68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15bd6c: 910043FD  add      x29, sp, #0x10
//   0x15bd70: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_3413_0x15bd64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bd64ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1edac0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3414 | PC: 0x15be10 | FDE: 0x1edae0 | Size: 52 bytes
// Khung tháo gỡ #3414 | Địa chỉ PC: 0x15be10 | Địa chỉ FDE: 0x1edae0 | Kích thước: 52 bytes
//   0x15be10: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15be14: 910003FD  mov      x29, sp
//   0x15be18: F9401000  ldr      x0, [x0, #0x20]
//   0x15be1c: B40000E0  cbz      x0, #0x15be38
static inline uint64_t fde_func_3414_0x15be10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15be10ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1edae0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3415 | PC: 0x15be44 | FDE: 0x1edb00 | Size: 148 bytes
// Khung tháo gỡ #3415 | Địa chỉ PC: 0x15be44 | Địa chỉ FDE: 0x1edb00 | Kích thước: 148 bytes
//   0x15be44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15be48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15be4c: 910043FD  add      x29, sp, #0x10
//   0x15be50: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3415_0x15be44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15be44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1edb00ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3416 | PC: 0x15bed8 | FDE: 0x1edb20 | Size: 8 bytes
// Khung tháo gỡ #3416 | Địa chỉ PC: 0x15bed8 | Địa chỉ FDE: 0x1edb20 | Kích thước: 8 bytes
//   0x15bed8: 2A1F03E0  mov      w0, wzr
//   0x15bedc: D65F03C0  ret      
static inline uint64_t fde_func_3416_0x15bed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bed8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1edb20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3417 | PC: 0x15bee0 | FDE: 0x1edb38 | Size: 8 bytes
// Khung tháo gỡ #3417 | Địa chỉ PC: 0x15bee0 | Địa chỉ FDE: 0x1edb38 | Kích thước: 8 bytes
//   0x15bee0: 2A1F03E0  mov      w0, wzr
//   0x15bee4: D65F03C0  ret      
static inline uint64_t fde_func_3417_0x15bee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bee0ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1edb38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3418 | PC: 0x15bee8 | FDE: 0x1edb50 | Size: 240 bytes
// Khung tháo gỡ #3418 | Địa chỉ PC: 0x15bee8 | Địa chỉ FDE: 0x1edb50 | Kích thước: 240 bytes
//   0x15bee8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15beec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15bef0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15bef4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3418_0x15bee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bee8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1edb50ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3419 | PC: 0x15bfd8 | FDE: 0x1edb70 | Size: 188 bytes
// Khung tháo gỡ #3419 | Địa chỉ PC: 0x15bfd8 | Địa chỉ FDE: 0x1edb70 | Kích thước: 188 bytes
//   0x15bfd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15bfdc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15bfe0: 910043FD  add      x29, sp, #0x10
//   0x15bfe4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3419_0x15bfd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bfd8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1edb70ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3420 | PC: 0x15c094 | FDE: 0x1edb90 | Size: 256 bytes
// Khung tháo gỡ #3420 | Địa chỉ PC: 0x15c094 | Địa chỉ FDE: 0x1edb90 | Kích thước: 256 bytes
//   0x15c094: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x15c098: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15c09c: 910043FD  add      x29, sp, #0x10
//   0x15c0a0: B9402408  ldr      w8, [x0, #0x24]
static inline uint64_t fde_func_3420_0x15c094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c094ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1edb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3421 | PC: 0x15c1dc | FDE: 0x1edbb0 | Size: 256 bytes
// Khung tháo gỡ #3421 | Địa chỉ PC: 0x15c1dc | Địa chỉ FDE: 0x1edbb0 | Kích thước: 256 bytes
//   0x15c1dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x15c1e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15c1e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15c1e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3421_0x15c1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c1dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1edbb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3422 | PC: 0x15c30c | FDE: 0x1edbd8 | Size: 256 bytes
// Khung tháo gỡ #3422 | Địa chỉ PC: 0x15c30c | Địa chỉ FDE: 0x1edbd8 | Kích thước: 256 bytes
//   0x15c30c: D10303FF  sub      sp, sp, #0xc0
//   0x15c310: F9003BF9  str      x25, [sp, #0x70]
//   0x15c314: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x15c318: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_3422_0x15c30c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c30cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x1edbd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3423 | PC: 0x15c4ec | FDE: 0x1edc00 | Size: 256 bytes
// Khung tháo gỡ #3423 | Địa chỉ PC: 0x15c4ec | Địa chỉ FDE: 0x1edc00 | Kích thước: 256 bytes
//   0x15c4ec: D102C3FF  sub      sp, sp, #0xb0
//   0x15c4f0: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x15c4f4: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x15c4f8: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_3423_0x15c4ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c4ecULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x1edc00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3424 | PC: 0x15c6e8 | FDE: 0x1edc28 | Size: 164 bytes
// Khung tháo gỡ #3424 | Địa chỉ PC: 0x15c6e8 | Địa chỉ FDE: 0x1edc28 | Kích thước: 164 bytes
//   0x15c6e8: D100C3FF  sub      sp, sp, #0x30
//   0x15c6ec: F9000BF3  str      x19, [sp, #0x10]
//   0x15c6f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15c6f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3424_0x15c6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c6e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1edc28ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #3425 | PC: 0x15c78c | FDE: 0x1edc48 | Size: 256 bytes
// Khung tháo gỡ #3425 | Địa chỉ PC: 0x15c78c | Địa chỉ FDE: 0x1edc48 | Kích thước: 256 bytes
//   0x15c78c: D10243FF  sub      sp, sp, #0x90
//   0x15c790: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x15c794: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x15c798: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3425_0x15c78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c78cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1edc48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3426 | PC: 0x15cfd4 | FDE: 0x1edc78 | Size: 256 bytes
// Khung tháo gỡ #3426 | Địa chỉ PC: 0x15cfd4 | Địa chỉ FDE: 0x1edc78 | Kích thước: 256 bytes
//   0x15cfd4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15cfd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15cfdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15cfe0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3426_0x15cfd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15cfd4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1edc78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3427 | PC: 0x15d20c | FDE: 0x1edc98 | Size: 256 bytes
// Khung tháo gỡ #3427 | Địa chỉ PC: 0x15d20c | Địa chỉ FDE: 0x1edc98 | Kích thước: 256 bytes
//   0x15d20c: D10143FF  sub      sp, sp, #0x50
//   0x15d210: F9000BF7  str      x23, [sp, #0x10]
//   0x15d214: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x15d218: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3427_0x15d20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d20cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1edc98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3428 | PC: 0x15d4d0 | FDE: 0x1edcc0 | Size: 256 bytes
// Khung tháo gỡ #3428 | Địa chỉ PC: 0x15d4d0 | Địa chỉ FDE: 0x1edcc0 | Kích thước: 256 bytes
//   0x15d4d0: D10183FF  sub      sp, sp, #0x60
//   0x15d4d4: F9000BF9  str      x25, [sp, #0x10]
//   0x15d4d8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x15d4dc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3428_0x15d4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d4d0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1edcc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3429 | PC: 0x15d8a4 | FDE: 0x1edce8 | Size: 256 bytes
// Khung tháo gỡ #3429 | Địa chỉ PC: 0x15d8a4 | Địa chỉ FDE: 0x1edce8 | Kích thước: 256 bytes
//   0x15d8a4: D10103FF  sub      sp, sp, #0x40
//   0x15d8a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x15d8ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15d8b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3429_0x15d8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d8a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1edce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3430 | PC: 0x15da34 | FDE: 0x1edd10 | Size: 164 bytes
// Khung tháo gỡ #3430 | Địa chỉ PC: 0x15da34 | Địa chỉ FDE: 0x1edd10 | Kích thước: 164 bytes
//   0x15da34: D100C3FF  sub      sp, sp, #0x30
//   0x15da38: F9000BF3  str      x19, [sp, #0x10]
//   0x15da3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15da40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3430_0x15da34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15da34ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1edd10ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #3431 | PC: 0x15dad8 | FDE: 0x1edd30 | Size: 256 bytes
// Khung tháo gỡ #3431 | Địa chỉ PC: 0x15dad8 | Địa chỉ FDE: 0x1edd30 | Kích thước: 256 bytes
//   0x15dad8: D102C3FF  sub      sp, sp, #0xb0
//   0x15dadc: F9003BF7  str      x23, [sp, #0x70]
//   0x15dae0: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x15dae4: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_3431_0x15dad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15dad8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x1edd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3432 | PC: 0x15e084 | FDE: 0x1edd58 | Size: 256 bytes
// Khung tháo gỡ #3432 | Địa chỉ PC: 0x15e084 | Địa chỉ FDE: 0x1edd58 | Kích thước: 256 bytes
//   0x15e084: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15e088: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15e08c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15e090: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3432_0x15e084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e084ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1edd58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3433 | PC: 0x15e1a0 | FDE: 0x1edd78 | Size: 180 bytes
// Khung tháo gỡ #3433 | Địa chỉ PC: 0x15e1a0 | Địa chỉ FDE: 0x1edd78 | Kích thước: 180 bytes
//   0x15e1a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15e1a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15e1a8: 910043FD  add      x29, sp, #0x10
//   0x15e1ac: F9401C08  ldr      x8, [x0, #0x38]
static inline uint64_t fde_func_3433_0x15e1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e1a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1edd78ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3434 | PC: 0x15e254 | FDE: 0x1edd98 | Size: 52 bytes
// Khung tháo gỡ #3434 | Địa chỉ PC: 0x15e254 | Địa chỉ FDE: 0x1edd98 | Kích thước: 52 bytes
//   0x15e254: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15e258: 910003FD  mov      x29, sp
//   0x15e25c: F9401400  ldr      x0, [x0, #0x28]
//   0x15e260: B40000E0  cbz      x0, #0x15e27c
static inline uint64_t fde_func_3434_0x15e254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e254ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1edd98ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3435 | PC: 0x15e288 | FDE: 0x1eddb8 | Size: 56 bytes
// Khung tháo gỡ #3435 | Địa chỉ PC: 0x15e288 | Địa chỉ FDE: 0x1eddb8 | Kích thước: 56 bytes
//   0x15e288: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15e28c: 910003FD  mov      x29, sp
//   0x15e290: AA0003E8  mov      x8, x0
//   0x15e294: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_3435_0x15e288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e288ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eddb8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3436 | PC: 0x15e2c0 | FDE: 0x1eddd8 | Size: 232 bytes
// Khung tháo gỡ #3436 | Địa chỉ PC: 0x15e2c0 | Địa chỉ FDE: 0x1eddd8 | Kích thước: 232 bytes
//   0x15e2c0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x15e2c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x15e2c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15e2cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3436_0x15e2c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e2c0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eddd8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3437 | PC: 0x15e3a8 | FDE: 0x1ede00 | Size: 256 bytes
// Khung tháo gỡ #3437 | Địa chỉ PC: 0x15e3a8 | Địa chỉ FDE: 0x1ede00 | Kích thước: 256 bytes
//   0x15e3a8: D10143FF  sub      sp, sp, #0x50
//   0x15e3ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x15e3b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x15e3b4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3437_0x15e3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e3a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ede00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3438 | PC: 0x15e530 | FDE: 0x1ede28 | Size: 104 bytes
// Khung tháo gỡ #3438 | Địa chỉ PC: 0x15e530 | Địa chỉ FDE: 0x1ede28 | Kích thước: 104 bytes
//   0x15e530: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15e534: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15e538: 910043FD  add      x29, sp, #0x10
//   0x15e53c: F9409808  ldr      x8, [x0, #0x130]
static inline uint64_t fde_func_3438_0x15e530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e530ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ede28ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3439 | PC: 0x15e598 | FDE: 0x1ede48 | Size: 76 bytes
// Khung tháo gỡ #3439 | Địa chỉ PC: 0x15e598 | Địa chỉ FDE: 0x1ede48 | Kích thước: 76 bytes
//   0x15e598: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15e59c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15e5a0: 910043FD  add      x29, sp, #0x10
//   0x15e5a4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3439_0x15e598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e598ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ede48ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3440 | PC: 0x15e5e4 | FDE: 0x1ede68 | Size: 52 bytes
// Khung tháo gỡ #3440 | Địa chỉ PC: 0x15e5e4 | Địa chỉ FDE: 0x1ede68 | Kích thước: 52 bytes
//   0x15e5e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15e5e8: 910003FD  mov      x29, sp
//   0x15e5ec: F9400800  ldr      x0, [x0, #0x10]
//   0x15e5f0: B40000E0  cbz      x0, #0x15e60c
static inline uint64_t fde_func_3440_0x15e5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e5e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ede68ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3441 | PC: 0x15e618 | FDE: 0x1ede88 | Size: 256 bytes
// Khung tháo gỡ #3441 | Địa chỉ PC: 0x15e618 | Địa chỉ FDE: 0x1ede88 | Kích thước: 256 bytes
//   0x15e618: D10243FF  sub      sp, sp, #0x90
//   0x15e61c: F90033F5  str      x21, [sp, #0x60]
//   0x15e620: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x15e624: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_3441_0x15e618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e618ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1ede88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3442 | PC: 0x15e768 | FDE: 0x1edea8 | Size: 256 bytes
// Khung tháo gỡ #3442 | Địa chỉ PC: 0x15e768 | Địa chỉ FDE: 0x1edea8 | Kích thước: 256 bytes
//   0x15e768: D10283FF  sub      sp, sp, #0xa0
//   0x15e76c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x15e770: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x15e774: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_3442_0x15e768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e768ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1edea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3443 | PC: 0x15e980 | FDE: 0x1eded0 | Size: 12 bytes [_PyFileIO_closed]
// Khung tháo gỡ #3443 | Địa chỉ PC: 0x15e980 | Địa chỉ FDE: 0x1eded0 | Kích thước: 12 bytes
//   0x15e980: B9401008  ldr      w8, [x0, #0x10]
//   0x15e984: 531F7D00  lsr      w0, w8, #0x1f
//   0x15e988: D65F03C0  ret      
static inline uint64_t fde_func_3443_0x15e980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e980ULL ^ (static_cast<uint64_t>(0xb9401008ULL) << 13);
    acc = (acc + a1 + 0x531f7d00ULL) ^ 0x1eded0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3444 | PC: 0x15e98c | FDE: 0x1edee8 | Size: 116 bytes
// Khung tháo gỡ #3444 | Địa chỉ PC: 0x15e98c | Địa chỉ FDE: 0x1edee8 | Kích thước: 116 bytes
//   0x15e98c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15e990: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15e994: 910043FD  add      x29, sp, #0x10
//   0x15e998: 52800028  mov      w8, #1
static inline uint64_t fde_func_3444_0x15e98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e98cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1edee8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3445 | PC: 0x15ea00 | FDE: 0x1edf08 | Size: 256 bytes
// Khung tháo gỡ #3445 | Địa chỉ PC: 0x15ea00 | Địa chỉ FDE: 0x1edf08 | Kích thước: 256 bytes
//   0x15ea00: D10103FF  sub      sp, sp, #0x40
//   0x15ea04: F9000BF5  str      x21, [sp, #0x10]
//   0x15ea08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15ea0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3445_0x15ea00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ea00ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1edf08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3446 | PC: 0x15ec18 | FDE: 0x1edf28 | Size: 52 bytes
// Khung tháo gỡ #3446 | Địa chỉ PC: 0x15ec18 | Địa chỉ FDE: 0x1edf28 | Kích thước: 52 bytes
//   0x15ec18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15ec1c: 910003FD  mov      x29, sp
//   0x15ec20: F9401400  ldr      x0, [x0, #0x28]
//   0x15ec24: B40000E0  cbz      x0, #0x15ec40
static inline uint64_t fde_func_3446_0x15ec18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ec18ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1edf28ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3447 | PC: 0x15ec4c | FDE: 0x1edf48 | Size: 56 bytes
// Khung tháo gỡ #3447 | Địa chỉ PC: 0x15ec4c | Địa chỉ FDE: 0x1edf48 | Kích thước: 56 bytes
//   0x15ec4c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15ec50: 910003FD  mov      x29, sp
//   0x15ec54: AA0003E8  mov      x8, x0
//   0x15ec58: F9401400  ldr      x0, [x0, #0x28]
static inline uint64_t fde_func_3447_0x15ec4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ec4cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1edf48ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3448 | PC: 0x15ec84 | FDE: 0x1edf68 | Size: 256 bytes
// Khung tháo gỡ #3448 | Địa chỉ PC: 0x15ec84 | Địa chỉ FDE: 0x1edf68 | Kích thước: 256 bytes
//   0x15ec84: D10483FF  sub      sp, sp, #0x120
//   0x15ec88: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x15ec8c: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x15ec90: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_3448_0x15ec84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ec84ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1edf68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3449 | PC: 0x15f368 | FDE: 0x1edf98 | Size: 64 bytes
// Khung tháo gỡ #3449 | Địa chỉ PC: 0x15f368 | Địa chỉ FDE: 0x1edf98 | Kích thước: 64 bytes
//   0x15f368: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15f36c: 910003FD  mov      x29, sp
//   0x15f370: F9409808  ldr      x8, [x0, #0x130]
//   0x15f374: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_3449_0x15f368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f368ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1edf98ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3450 | PC: 0x15f3a8 | FDE: 0x1edfb8 | Size: 256 bytes
// Khung tháo gỡ #3450 | Địa chỉ PC: 0x15f3a8 | Địa chỉ FDE: 0x1edfb8 | Kích thước: 256 bytes
//   0x15f3a8: D10383FF  sub      sp, sp, #0xe0
//   0x15f3ac: F90053F7  str      x23, [sp, #0xa0]
//   0x15f3b0: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x15f3b4: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_3450_0x15f3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f3a8ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x1edfb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3451 | PC: 0x15f714 | FDE: 0x1edfe0 | Size: 256 bytes
// Khung tháo gỡ #3451 | Địa chỉ PC: 0x15f714 | Địa chỉ FDE: 0x1edfe0 | Kích thước: 256 bytes
//   0x15f714: D10243FF  sub      sp, sp, #0x90
//   0x15f718: F90033F5  str      x21, [sp, #0x60]
//   0x15f71c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x15f720: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_3451_0x15f714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f714ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1edfe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3452 | PC: 0x15f89c | FDE: 0x1ee000 | Size: 256 bytes
// Khung tháo gỡ #3452 | Địa chỉ PC: 0x15f89c | Địa chỉ FDE: 0x1ee000 | Kích thước: 256 bytes
//   0x15f89c: D10243FF  sub      sp, sp, #0x90
//   0x15f8a0: F90033F5  str      x21, [sp, #0x60]
//   0x15f8a4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x15f8a8: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_3452_0x15f89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f89cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1ee000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3453 | PC: 0x15fa04 | FDE: 0x1ee020 | Size: 256 bytes
// Khung tháo gỡ #3453 | Địa chỉ PC: 0x15fa04 | Địa chỉ FDE: 0x1ee020 | Kích thước: 256 bytes
//   0x15fa04: D10203FF  sub      sp, sp, #0x80
//   0x15fa08: F90023F7  str      x23, [sp, #0x40]
//   0x15fa0c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x15fa10: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_3453_0x15fa04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fa04ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1ee020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3454 | PC: 0x15fbf4 | FDE: 0x1ee048 | Size: 244 bytes
// Khung tháo gỡ #3454 | Địa chỉ PC: 0x15fbf4 | Địa chỉ FDE: 0x1ee048 | Kích thước: 244 bytes
//   0x15fbf4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15fbf8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15fbfc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x15fc00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3454_0x15fbf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fbf4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee048ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #3455 | PC: 0x15fce8 | FDE: 0x1ee068 | Size: 68 bytes
// Khung tháo gỡ #3455 | Địa chỉ PC: 0x15fce8 | Địa chỉ FDE: 0x1ee068 | Kích thước: 68 bytes
//   0x15fce8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15fcec: 910003FD  mov      x29, sp
//   0x15fcf0: B9401008  ldr      w8, [x0, #0x10]
//   0x15fcf4: 37F800A8  tbnz     w8, #0x1f, #0x15fd08
static inline uint64_t fde_func_3455_0x15fce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fce8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee068ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3456 | PC: 0x15fd2c | FDE: 0x1ee088 | Size: 68 bytes
// Khung tháo gỡ #3456 | Địa chỉ PC: 0x15fd2c | Địa chỉ FDE: 0x1ee088 | Kích thước: 68 bytes
//   0x15fd2c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15fd30: 910003FD  mov      x29, sp
//   0x15fd34: B9401008  ldr      w8, [x0, #0x10]
//   0x15fd38: 37F800A8  tbnz     w8, #0x1f, #0x15fd4c
static inline uint64_t fde_func_3456_0x15fd2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fd2cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee088ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3457 | PC: 0x15fd70 | FDE: 0x1ee0a8 | Size: 112 bytes
// Khung tháo gỡ #3457 | Địa chỉ PC: 0x15fd70 | Địa chỉ FDE: 0x1ee0a8 | Kích thước: 112 bytes
//   0x15fd70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x15fd74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15fd78: 910043FD  add      x29, sp, #0x10
//   0x15fd7c: B9401008  ldr      w8, [x0, #0x10]
static inline uint64_t fde_func_3457_0x15fd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fd70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee0a8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3458 | PC: 0x15fde0 | FDE: 0x1ee0c8 | Size: 192 bytes
// Khung tháo gỡ #3458 | Địa chỉ PC: 0x15fde0 | Địa chỉ FDE: 0x1ee0c8 | Kích thước: 192 bytes
//   0x15fde0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x15fde4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x15fde8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15fdec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3458_0x15fde0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fde0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ee0c8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3459 | PC: 0x15fea0 | FDE: 0x1ee0f0 | Size: 12 bytes
// Khung tháo gỡ #3459 | Địa chỉ PC: 0x15fea0 | Địa chỉ FDE: 0x1ee0f0 | Kích thước: 12 bytes
//   0x15fea0: B9401008  ldr      w8, [x0, #0x10]
//   0x15fea4: D35FFD00  lsr      x0, x8, #0x1f
//   0x15fea8: 17FBEADE  b        #0x5aa20
static inline uint64_t fde_func_3459_0x15fea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fea0ULL ^ (static_cast<uint64_t>(0xb9401008ULL) << 13);
    acc = (acc + a1 + 0xd35ffd00ULL) ^ 0x1ee0f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3460 | PC: 0x15feac | FDE: 0x1ee108 | Size: 240 bytes [_PyIOBase_check_closed]
// Khung tháo gỡ #3460 | Địa chỉ PC: 0x15feac | Địa chỉ FDE: 0x1ee108 | Kích thước: 240 bytes
//   0x15feac: D10103FF  sub      sp, sp, #0x40
//   0x15feb0: F9000BF5  str      x21, [sp, #0x10]
//   0x15feb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15feb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3460_0x15feac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15feacULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee108ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3461 | PC: 0x15ff9c | FDE: 0x1ee128 | Size: 40 bytes [_PyIOBase_finalize]
// Khung tháo gỡ #3461 | Địa chỉ PC: 0x15ff9c | Địa chỉ FDE: 0x1ee128 | Kích thước: 40 bytes
//   0x15ff9c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15ffa0: 910003FD  mov      x29, sp
//   0x15ffa4: F9400008  ldr      x8, [x0]
//   0x15ffa8: B40000A8  cbz      x8, #0x15ffbc
static inline uint64_t fde_func_3461_0x15ff9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ff9cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee128ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3462 | PC: 0x15ffc4 | FDE: 0x1ee148 | Size: 240 bytes [_PyIOBase_check_seekable]
// Khung tháo gỡ #3462 | Địa chỉ PC: 0x15ffc4 | Địa chỉ FDE: 0x1ee148 | Kích thước: 240 bytes
//   0x15ffc4: D10103FF  sub      sp, sp, #0x40
//   0x15ffc8: F9000BF5  str      x21, [sp, #0x10]
//   0x15ffcc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15ffd0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3462_0x15ffc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ffc4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee148ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3463 | PC: 0x1600b4 | FDE: 0x1ee168 | Size: 240 bytes [_PyIOBase_check_readable]
// Khung tháo gỡ #3463 | Địa chỉ PC: 0x1600b4 | Địa chỉ FDE: 0x1ee168 | Kích thước: 240 bytes
//   0x1600b4: D10103FF  sub      sp, sp, #0x40
//   0x1600b8: F9000BF5  str      x21, [sp, #0x10]
//   0x1600bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1600c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3463_0x1600b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1600b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee168ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3464 | PC: 0x1601a4 | FDE: 0x1ee188 | Size: 240 bytes [_PyIOBase_check_writable]
// Khung tháo gỡ #3464 | Địa chỉ PC: 0x1601a4 | Địa chỉ FDE: 0x1ee188 | Kích thước: 240 bytes
//   0x1601a4: D10103FF  sub      sp, sp, #0x40
//   0x1601a8: F9000BF5  str      x21, [sp, #0x10]
//   0x1601ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1601b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3464_0x1601a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1601a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee188ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3465 | PC: 0x160294 | FDE: 0x1ee1a8 | Size: 164 bytes
// Khung tháo gỡ #3465 | Địa chỉ PC: 0x160294 | Địa chỉ FDE: 0x1ee1a8 | Kích thước: 164 bytes
//   0x160294: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x160298: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16029c: 910043FD  add      x29, sp, #0x10
//   0x1602a0: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_3465_0x160294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160294ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee1a8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #3466 | PC: 0x160338 | FDE: 0x1ee1c8 | Size: 52 bytes
// Khung tháo gỡ #3466 | Địa chỉ PC: 0x160338 | Địa chỉ FDE: 0x1ee1c8 | Kích thước: 52 bytes
//   0x160338: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16033c: 910003FD  mov      x29, sp
//   0x160340: F9400800  ldr      x0, [x0, #0x10]
//   0x160344: B40000E0  cbz      x0, #0x160360
static inline uint64_t fde_func_3466_0x160338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160338ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee1c8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3467 | PC: 0x16036c | FDE: 0x1ee1e8 | Size: 56 bytes
// Khung tháo gỡ #3467 | Địa chỉ PC: 0x16036c | Địa chỉ FDE: 0x1ee1e8 | Kích thước: 56 bytes
//   0x16036c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x160370: 910003FD  mov      x29, sp
//   0x160374: AA0003E8  mov      x8, x0
//   0x160378: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_3467_0x16036c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16036cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee1e8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3468 | PC: 0x1603a4 | FDE: 0x1ee208 | Size: 220 bytes
// Khung tháo gỡ #3468 | Địa chỉ PC: 0x1603a4 | Địa chỉ FDE: 0x1ee208 | Kích thước: 220 bytes
//   0x1603a4: D10103FF  sub      sp, sp, #0x40
//   0x1603a8: F9000BF5  str      x21, [sp, #0x10]
//   0x1603ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1603b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3468_0x1603a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1603a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee208ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #3469 | PC: 0x160480 | FDE: 0x1ee228 | Size: 156 bytes
// Khung tháo gỡ #3469 | Địa chỉ PC: 0x160480 | Địa chỉ FDE: 0x1ee228 | Kích thước: 156 bytes
//   0x160480: D100C3FF  sub      sp, sp, #0x30
//   0x160484: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x160488: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16048c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3469_0x160480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160480ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee228ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #3470 | PC: 0x16051c | FDE: 0x1ee248 | Size: 256 bytes
// Khung tháo gỡ #3470 | Địa chỉ PC: 0x16051c | Địa chỉ FDE: 0x1ee248 | Kích thước: 256 bytes
//   0x16051c: D10183FF  sub      sp, sp, #0x60
//   0x160520: F9001BF5  str      x21, [sp, #0x30]
//   0x160524: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x160528: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_3470_0x16051c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16051cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1ee248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3471 | PC: 0x160654 | FDE: 0x1ee268 | Size: 184 bytes
// Khung tháo gỡ #3471 | Địa chỉ PC: 0x160654 | Địa chỉ FDE: 0x1ee268 | Kích thước: 184 bytes
//   0x160654: D100C3FF  sub      sp, sp, #0x30
//   0x160658: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16065c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x160660: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3471_0x160654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160654ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee268ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #3472 | PC: 0x16070c | FDE: 0x1ee288 | Size: 256 bytes
// Khung tháo gỡ #3472 | Địa chỉ PC: 0x16070c | Địa chỉ FDE: 0x1ee288 | Kích thước: 256 bytes
//   0x16070c: D10143FF  sub      sp, sp, #0x50
//   0x160710: F90013F5  str      x21, [sp, #0x20]
//   0x160714: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x160718: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3472_0x16070c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16070cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ee288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3473 | PC: 0x160858 | FDE: 0x1ee2a8 | Size: 24 bytes
// Khung tháo gỡ #3473 | Địa chỉ PC: 0x160858 | Địa chỉ FDE: 0x1ee2a8 | Kích thước: 24 bytes
//   0x160858: F00004E0  adrp     x0, #0x1ff000
//   0x16085c: F9456000  ldr      x0, [x0, #0xac0]
//   0x160860: F9400008  ldr      x8, [x0]
//   0x160864: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_3473_0x160858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160858ULL ^ (static_cast<uint64_t>(0xf00004e0ULL) << 13);
    acc = (acc + a1 + 0xf9456000ULL) ^ 0x1ee2a8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3474 | PC: 0x160870 | FDE: 0x1ee2c0 | Size: 24 bytes
// Khung tháo gỡ #3474 | Địa chỉ PC: 0x160870 | Địa chỉ FDE: 0x1ee2c0 | Kích thước: 24 bytes
//   0x160870: F00004E0  adrp     x0, #0x1ff000
//   0x160874: F9456000  ldr      x0, [x0, #0xac0]
//   0x160878: F9400008  ldr      x8, [x0]
//   0x16087c: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_3474_0x160870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160870ULL ^ (static_cast<uint64_t>(0xf00004e0ULL) << 13);
    acc = (acc + a1 + 0xf9456000ULL) ^ 0x1ee2c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3475 | PC: 0x160888 | FDE: 0x1ee2d8 | Size: 24 bytes
// Khung tháo gỡ #3475 | Địa chỉ PC: 0x160888 | Địa chỉ FDE: 0x1ee2d8 | Kích thước: 24 bytes
//   0x160888: F00004E0  adrp     x0, #0x1ff000
//   0x16088c: F9456000  ldr      x0, [x0, #0xac0]
//   0x160890: F9400008  ldr      x8, [x0]
//   0x160894: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_3475_0x160888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160888ULL ^ (static_cast<uint64_t>(0xf00004e0ULL) << 13);
    acc = (acc + a1 + 0xf9456000ULL) ^ 0x1ee2d8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3476 | PC: 0x1608a0 | FDE: 0x1ee2f0 | Size: 220 bytes
// Khung tháo gỡ #3476 | Địa chỉ PC: 0x1608a0 | Địa chỉ FDE: 0x1ee2f0 | Kích thước: 220 bytes
//   0x1608a0: D10103FF  sub      sp, sp, #0x40
//   0x1608a4: F9000BF5  str      x21, [sp, #0x10]
//   0x1608a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1608ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3476_0x1608a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1608a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee2f0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #3477 | PC: 0x16097c | FDE: 0x1ee310 | Size: 100 bytes
// Khung tháo gỡ #3477 | Địa chỉ PC: 0x16097c | Địa chỉ FDE: 0x1ee310 | Kích thước: 100 bytes
//   0x16097c: D100C3FF  sub      sp, sp, #0x30
//   0x160980: F9000BF3  str      x19, [sp, #0x10]
//   0x160984: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x160988: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3477_0x16097c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16097cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1ee310ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #3478 | PC: 0x1609e0 | FDE: 0x1ee330 | Size: 256 bytes
// Khung tháo gỡ #3478 | Địa chỉ PC: 0x1609e0 | Địa chỉ FDE: 0x1ee330 | Kích thước: 256 bytes
//   0x1609e0: D10243FF  sub      sp, sp, #0x90
//   0x1609e4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1609e8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1609ec: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3478_0x1609e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1609e0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1ee330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3479 | PC: 0x160e0c | FDE: 0x1ee360 | Size: 256 bytes
// Khung tháo gỡ #3479 | Địa chỉ PC: 0x160e0c | Địa chỉ FDE: 0x1ee360 | Kích thước: 256 bytes
//   0x160e0c: D10183FF  sub      sp, sp, #0x60
//   0x160e10: F9000BF9  str      x25, [sp, #0x10]
//   0x160e14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x160e18: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3479_0x160e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160e0cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1ee360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3480 | PC: 0x160fec | FDE: 0x1ee388 | Size: 252 bytes
// Khung tháo gỡ #3480 | Địa chỉ PC: 0x160fec | Địa chỉ FDE: 0x1ee388 | Kích thước: 252 bytes
//   0x160fec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x160ff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x160ff4: 910043FD  add      x29, sp, #0x10
//   0x160ff8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3480_0x160fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160fecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee388ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #3481 | PC: 0x1610e8 | FDE: 0x1ee3a8 | Size: 52 bytes
// Khung tháo gỡ #3481 | Địa chỉ PC: 0x1610e8 | Địa chỉ FDE: 0x1ee3a8 | Kích thước: 52 bytes
//   0x1610e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1610ec: 910003FD  mov      x29, sp
//   0x1610f0: F9403400  ldr      x0, [x0, #0x68]
//   0x1610f4: B40000E0  cbz      x0, #0x161110
static inline uint64_t fde_func_3481_0x1610e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1610e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee3a8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3482 | PC: 0x16111c | FDE: 0x1ee3c8 | Size: 56 bytes
// Khung tháo gỡ #3482 | Địa chỉ PC: 0x16111c | Địa chỉ FDE: 0x1ee3c8 | Kích thước: 56 bytes
//   0x16111c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x161120: 910003FD  mov      x29, sp
//   0x161124: AA0003E8  mov      x8, x0
//   0x161128: F9403400  ldr      x0, [x0, #0x68]
static inline uint64_t fde_func_3482_0x16111c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16111cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee3c8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3483 | PC: 0x161154 | FDE: 0x1ee3e8 | Size: 256 bytes
// Khung tháo gỡ #3483 | Địa chỉ PC: 0x161154 | Địa chỉ FDE: 0x1ee3e8 | Kích thước: 256 bytes
//   0x161154: D10143FF  sub      sp, sp, #0x50
//   0x161158: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x16115c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x161160: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3483_0x161154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161154ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ee3e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3484 | PC: 0x161414 | FDE: 0x1ee410 | Size: 256 bytes
// Khung tháo gỡ #3484 | Địa chỉ PC: 0x161414 | Địa chỉ FDE: 0x1ee410 | Kích thước: 256 bytes
//   0x161414: D101C3FF  sub      sp, sp, #0x70
//   0x161418: F90013F9  str      x25, [sp, #0x20]
//   0x16141c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x161420: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3484_0x161414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161414ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1ee410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3485 | PC: 0x1617ec | FDE: 0x1ee438 | Size: 100 bytes
// Khung tháo gỡ #3485 | Địa chỉ PC: 0x1617ec | Địa chỉ FDE: 0x1ee438 | Kích thước: 100 bytes
//   0x1617ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1617f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1617f4: 910043FD  add      x29, sp, #0x10
//   0x1617f8: F9409808  ldr      x8, [x0, #0x130]
static inline uint64_t fde_func_3485_0x1617ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1617ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee438ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #3486 | PC: 0x161850 | FDE: 0x1ee458 | Size: 256 bytes
// Khung tháo gỡ #3486 | Địa chỉ PC: 0x161850 | Địa chỉ FDE: 0x1ee458 | Kích thước: 256 bytes
//   0x161850: D10143FF  sub      sp, sp, #0x50
//   0x161854: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x161858: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x16185c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3486_0x161850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161850ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ee458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3487 | PC: 0x161b30 | FDE: 0x1ee480 | Size: 240 bytes
// Khung tháo gỡ #3487 | Địa chỉ PC: 0x161b30 | Địa chỉ FDE: 0x1ee480 | Kích thước: 240 bytes
//   0x161b30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x161b34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x161b38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x161b3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3487_0x161b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161b30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee480ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3488 | PC: 0x161c20 | FDE: 0x1ee4a0 | Size: 216 bytes
// Khung tháo gỡ #3488 | Địa chỉ PC: 0x161c20 | Địa chỉ FDE: 0x1ee4a0 | Kích thước: 216 bytes
//   0x161c20: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x161c24: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x161c28: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x161c2c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3488_0x161c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161c20ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee4a0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #3489 | PC: 0x161cf8 | FDE: 0x1ee4c0 | Size: 256 bytes
// Khung tháo gỡ #3489 | Địa chỉ PC: 0x161cf8 | Địa chỉ FDE: 0x1ee4c0 | Kích thước: 256 bytes
//   0x161cf8: FC1B0FE8  str      d8, [sp, #-0x50]!
//   0x161cfc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x161d00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x161d04: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3489_0x161cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161cf8ULL ^ (static_cast<uint64_t>(0xfc1b0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ee4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3490 | PC: 0x16206c | FDE: 0x1ee4e8 | Size: 256 bytes [_PyIncrementalNewlineDecoder_decode]
// Khung tháo gỡ #3490 | Địa chỉ PC: 0x16206c | Địa chỉ FDE: 0x1ee4e8 | Kích thước: 256 bytes
//   0x16206c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x162070: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x162074: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x162078: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3490_0x16206c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16206cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ee4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3491 | PC: 0x1627fc | FDE: 0x1ee518 | Size: 256 bytes [_PyIO_find_line_ending]
// Khung tháo gỡ #3491 | Địa chỉ PC: 0x1627fc | Địa chỉ FDE: 0x1ee518 | Kích thước: 256 bytes
//   0x1627fc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x162800: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x162804: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x162808: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3491_0x1627fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1627fcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ee518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3492 | PC: 0x162bf0 | FDE: 0x1ee548 | Size: 116 bytes
// Khung tháo gỡ #3492 | Địa chỉ PC: 0x162bf0 | Địa chỉ FDE: 0x1ee548 | Kích thước: 116 bytes
//   0x162bf0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x162bf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x162bf8: 910043FD  add      x29, sp, #0x10
//   0x162bfc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3492_0x162bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162bf0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee548ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3493 | PC: 0x162c64 | FDE: 0x1ee568 | Size: 256 bytes
// Khung tháo gỡ #3493 | Địa chỉ PC: 0x162c64 | Địa chỉ FDE: 0x1ee568 | Kích thước: 256 bytes
//   0x162c64: D101C3FF  sub      sp, sp, #0x70
//   0x162c68: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x162c6c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x162c70: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_3493_0x162c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162c64ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1ee568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3494 | PC: 0x162db4 | FDE: 0x1ee590 | Size: 96 bytes
// Khung tháo gỡ #3494 | Địa chỉ PC: 0x162db4 | Địa chỉ FDE: 0x1ee590 | Kích thước: 96 bytes
//   0x162db4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x162db8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x162dbc: 910043FD  add      x29, sp, #0x10
//   0x162dc0: 52800028  mov      w8, #1
static inline uint64_t fde_func_3494_0x162db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162db4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee590ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #3495 | PC: 0x162e14 | FDE: 0x1ee5b0 | Size: 256 bytes
// Khung tháo gỡ #3495 | Địa chỉ PC: 0x162e14 | Địa chỉ FDE: 0x1ee5b0 | Kích thước: 256 bytes
//   0x162e14: D10143FF  sub      sp, sp, #0x50
//   0x162e18: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x162e1c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x162e20: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3495_0x162e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162e14ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ee5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3496 | PC: 0x163030 | FDE: 0x1ee5d8 | Size: 256 bytes
// Khung tháo gỡ #3496 | Địa chỉ PC: 0x163030 | Địa chỉ FDE: 0x1ee5d8 | Kích thước: 256 bytes
//   0x163030: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x163034: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x163038: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16303c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3496_0x163030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x163030ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3497 | PC: 0x16313c | FDE: 0x1ee5f8 | Size: 256 bytes
// Khung tháo gỡ #3497 | Địa chỉ PC: 0x16313c | Địa chỉ FDE: 0x1ee5f8 | Kích thước: 256 bytes
//   0x16313c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x163140: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x163144: 910043FD  add      x29, sp, #0x10
//   0x163148: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3497_0x16313c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16313cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee5f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3498 | PC: 0x163324 | FDE: 0x1ee618 | Size: 256 bytes
// Khung tháo gỡ #3498 | Địa chỉ PC: 0x163324 | Địa chỉ FDE: 0x1ee618 | Kích thước: 256 bytes
//   0x163324: D10383FF  sub      sp, sp, #0xe0
//   0x163328: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x16332c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x163330: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_3498_0x163324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x163324ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1ee618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3499 | PC: 0x163cf4 | FDE: 0x1ee648 | Size: 256 bytes
// Khung tháo gỡ #3499 | Địa chỉ PC: 0x163cf4 | Địa chỉ FDE: 0x1ee648 | Kích thước: 256 bytes
//   0x163cf4: D10303FF  sub      sp, sp, #0xc0
//   0x163cf8: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x163cfc: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x163d00: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_3499_0x163cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x163cf4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1ee648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3500 | PC: 0x164a1c | FDE: 0x1ee678 | Size: 248 bytes
// Khung tháo gỡ #3500 | Địa chỉ PC: 0x164a1c | Địa chỉ FDE: 0x1ee678 | Kích thước: 248 bytes
//   0x164a1c: D10143FF  sub      sp, sp, #0x50
//   0x164a20: F90013F5  str      x21, [sp, #0x20]
//   0x164a24: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x164a28: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3500_0x164a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164a1cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ee678ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3501 | PC: 0x164b14 | FDE: 0x1ee698 | Size: 256 bytes
// Khung tháo gỡ #3501 | Địa chỉ PC: 0x164b14 | Địa chỉ FDE: 0x1ee698 | Kích thước: 256 bytes
//   0x164b14: D101C3FF  sub      sp, sp, #0x70
//   0x164b18: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x164b1c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x164b20: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3501_0x164b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164b14ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1ee698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3502 | PC: 0x164d20 | FDE: 0x1ee6c8 | Size: 256 bytes
// Khung tháo gỡ #3502 | Địa chỉ PC: 0x164d20 | Địa chỉ FDE: 0x1ee6c8 | Kích thước: 256 bytes
//   0x164d20: D101C3FF  sub      sp, sp, #0x70
//   0x164d24: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x164d28: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x164d2c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3502_0x164d20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164d20ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1ee6c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3503 | PC: 0x16528c | FDE: 0x1ee6f8 | Size: 256 bytes
// Khung tháo gỡ #3503 | Địa chỉ PC: 0x16528c | Địa chỉ FDE: 0x1ee6f8 | Kích thước: 256 bytes
//   0x16528c: D10103FF  sub      sp, sp, #0x40
//   0x165290: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x165294: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x165298: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3503_0x16528c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16528cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ee6f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3504 | PC: 0x1653f8 | FDE: 0x1ee720 | Size: 44 bytes
// Khung tháo gỡ #3504 | Địa chỉ PC: 0x1653f8 | Địa chỉ FDE: 0x1ee720 | Kích thước: 44 bytes
//   0x1653f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1653fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x165400: 910043FD  add      x29, sp, #0x10
//   0x165404: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_3504_0x1653f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1653f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee720ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3505 | PC: 0x165424 | FDE: 0x1ee740 | Size: 44 bytes
// Khung tháo gỡ #3505 | Địa chỉ PC: 0x165424 | Địa chỉ FDE: 0x1ee740 | Kích thước: 44 bytes
//   0x165424: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x165428: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16542c: 910043FD  add      x29, sp, #0x10
//   0x165430: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_3505_0x165424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165424ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee740ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3506 | PC: 0x165450 | FDE: 0x1ee760 | Size: 44 bytes
// Khung tháo gỡ #3506 | Địa chỉ PC: 0x165450 | Địa chỉ FDE: 0x1ee760 | Kích thước: 44 bytes
//   0x165450: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x165454: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x165458: 910043FD  add      x29, sp, #0x10
//   0x16545c: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_3506_0x165450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165450ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee760ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3507 | PC: 0x16547c | FDE: 0x1ee780 | Size: 8 bytes
// Khung tháo gỡ #3507 | Địa chỉ PC: 0x16547c | Địa chỉ FDE: 0x1ee780 | Kích thước: 8 bytes
//   0x16547c: AA1F03E0  mov      x0, xzr
//   0x165480: D65F03C0  ret      
static inline uint64_t fde_func_3507_0x16547c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16547cULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ee780ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3508 | PC: 0x165484 | FDE: 0x1ee798 | Size: 8 bytes
// Khung tháo gỡ #3508 | Địa chỉ PC: 0x165484 | Địa chỉ FDE: 0x1ee798 | Kích thước: 8 bytes
//   0x165484: AA1F03E0  mov      x0, xzr
//   0x165488: D65F03C0  ret      
static inline uint64_t fde_func_3508_0x165484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165484ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ee798ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3509 | PC: 0x16548c | FDE: 0x1ee7b0 | Size: 8 bytes
// Khung tháo gỡ #3509 | Địa chỉ PC: 0x16548c | Địa chỉ FDE: 0x1ee7b0 | Kích thước: 8 bytes
//   0x16548c: AA1F03E0  mov      x0, xzr
//   0x165490: D65F03C0  ret      
static inline uint64_t fde_func_3509_0x16548c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16548cULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ee7b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3510 | PC: 0x165494 | FDE: 0x1ee7c8 | Size: 8 bytes
// Khung tháo gỡ #3510 | Địa chỉ PC: 0x165494 | Địa chỉ FDE: 0x1ee7c8 | Kích thước: 8 bytes
//   0x165494: AA1F03E0  mov      x0, xzr
//   0x165498: D65F03C0  ret      
static inline uint64_t fde_func_3510_0x165494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165494ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ee7c8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3511 | PC: 0x16549c | FDE: 0x1ee7e0 | Size: 8 bytes
// Khung tháo gỡ #3511 | Địa chỉ PC: 0x16549c | Địa chỉ FDE: 0x1ee7e0 | Kích thước: 8 bytes
//   0x16549c: AA1F03E0  mov      x0, xzr
//   0x1654a0: D65F03C0  ret      
static inline uint64_t fde_func_3511_0x16549c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16549cULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ee7e0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3512 | PC: 0x1654a4 | FDE: 0x1ee7f8 | Size: 8 bytes
// Khung tháo gỡ #3512 | Địa chỉ PC: 0x1654a4 | Địa chỉ FDE: 0x1ee7f8 | Kích thước: 8 bytes
//   0x1654a4: AA1F03E0  mov      x0, xzr
//   0x1654a8: D65F03C0  ret      
static inline uint64_t fde_func_3512_0x1654a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1654a4ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ee7f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3513 | PC: 0x1654ac | FDE: 0x1ee810 | Size: 12 bytes [PyInit__json]
// Khung tháo gỡ #3513 | Địa chỉ PC: 0x1654ac | Địa chỉ FDE: 0x1ee810 | Kích thước: 12 bytes
//   0x1654ac: F00005A0  adrp     x0, #0x21c000
//   0x1654b0: 91352000  add      x0, x0, #0xd48
//   0x1654b4: 17FBCD5B  b        #0x58a20
static inline uint64_t fde_func_3513_0x1654ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1654acULL ^ (static_cast<uint64_t>(0xf00005a0ULL) << 13);
    acc = (acc + a1 + 0x91352000ULL) ^ 0x1ee810ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3514 | PC: 0x1654b8 | FDE: 0x1ee828 | Size: 92 bytes
// Khung tháo gỡ #3514 | Địa chỉ PC: 0x1654b8 | Địa chỉ FDE: 0x1ee828 | Kích thước: 92 bytes
//   0x1654b8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1654bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1654c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1654c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3514_0x1654b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1654b8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee828ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3515 | PC: 0x165514 | FDE: 0x1ee848 | Size: 112 bytes
// Khung tháo gỡ #3515 | Địa chỉ PC: 0x165514 | Địa chỉ FDE: 0x1ee848 | Kích thước: 112 bytes
//   0x165514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x165518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16551c: 910043FD  add      x29, sp, #0x10
//   0x165520: 97FBD258  bl       #0x59e80
static inline uint64_t fde_func_3515_0x165514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165514ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee848ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3516 | PC: 0x165584 | FDE: 0x1ee868 | Size: 112 bytes
// Khung tháo gỡ #3516 | Địa chỉ PC: 0x165584 | Địa chỉ FDE: 0x1ee868 | Kích thước: 112 bytes
//   0x165584: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x165588: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16558c: 910043FD  add      x29, sp, #0x10
//   0x165590: 97FBD23C  bl       #0x59e80
static inline uint64_t fde_func_3516_0x165584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165584ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee868ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3517 | PC: 0x1655f4 | FDE: 0x1ee888 | Size: 256 bytes
// Khung tháo gỡ #3517 | Địa chỉ PC: 0x1655f4 | Địa chỉ FDE: 0x1ee888 | Kích thước: 256 bytes
//   0x1655f4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1655f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1655fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x165600: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3517_0x1655f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1655f4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3518 | PC: 0x16597c | FDE: 0x1ee8a8 | Size: 256 bytes
// Khung tháo gỡ #3518 | Địa chỉ PC: 0x16597c | Địa chỉ FDE: 0x1ee8a8 | Kích thước: 256 bytes
//   0x16597c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x165980: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x165984: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x165988: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3518_0x16597c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16597cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3519 | PC: 0x165efc | FDE: 0x1ee8d0 | Size: 188 bytes
// Khung tháo gỡ #3519 | Địa chỉ PC: 0x165efc | Địa chỉ FDE: 0x1ee8d0 | Kích thước: 188 bytes
//   0x165efc: D10143FF  sub      sp, sp, #0x50
//   0x165f00: F9001BF3  str      x19, [sp, #0x30]
//   0x165f04: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x165f08: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_3519_0x165efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165efcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1ee8d0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3520 | PC: 0x165fb8 | FDE: 0x1ee8f0 | Size: 256 bytes
// Khung tháo gỡ #3520 | Địa chỉ PC: 0x165fb8 | Địa chỉ FDE: 0x1ee8f0 | Kích thước: 256 bytes
//   0x165fb8: D103C3FF  sub      sp, sp, #0xf0
//   0x165fbc: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x165fc0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x165fc4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_3520_0x165fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165fb8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1ee8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3521 | PC: 0x166700 | FDE: 0x1ee920 | Size: 120 bytes
// Khung tháo gỡ #3521 | Địa chỉ PC: 0x166700 | Địa chỉ FDE: 0x1ee920 | Kích thước: 120 bytes
//   0x166700: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x166704: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x166708: 910043FD  add      x29, sp, #0x10
//   0x16670c: B4000300  cbz      x0, #0x16676c
static inline uint64_t fde_func_3521_0x166700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166700ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee920ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3522 | PC: 0x166778 | FDE: 0x1ee940 | Size: 244 bytes
// Khung tháo gỡ #3522 | Địa chỉ PC: 0x166778 | Địa chỉ FDE: 0x1ee940 | Kích thước: 244 bytes
//   0x166778: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x16677c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x166780: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x166784: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3522_0x166778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166778ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ee940ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #3523 | PC: 0x16686c | FDE: 0x1ee968 | Size: 192 bytes
// Khung tháo gỡ #3523 | Địa chỉ PC: 0x16686c | Địa chỉ FDE: 0x1ee968 | Kích thước: 192 bytes
//   0x16686c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x166870: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x166874: 910043FD  add      x29, sp, #0x10
//   0x166878: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3523_0x16686c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16686cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee968ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3524 | PC: 0x16692c | FDE: 0x1ee988 | Size: 88 bytes
// Khung tháo gỡ #3524 | Địa chỉ PC: 0x16692c | Địa chỉ FDE: 0x1ee988 | Kích thước: 88 bytes
//   0x16692c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x166930: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x166934: 910043FD  add      x29, sp, #0x10
//   0x166938: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3524_0x16692c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16692cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee988ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3525 | PC: 0x166984 | FDE: 0x1ee9a8 | Size: 224 bytes
// Khung tháo gỡ #3525 | Địa chỉ PC: 0x166984 | Địa chỉ FDE: 0x1ee9a8 | Kích thước: 224 bytes
//   0x166984: D10103FF  sub      sp, sp, #0x40
//   0x166988: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16698c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x166990: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3525_0x166984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166984ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ee9a8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #3526 | PC: 0x166a64 | FDE: 0x1ee9c8 | Size: 188 bytes
// Khung tháo gỡ #3526 | Địa chỉ PC: 0x166a64 | Địa chỉ FDE: 0x1ee9c8 | Kích thước: 188 bytes
//   0x166a64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x166a68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x166a6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x166a70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3526_0x166a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166a64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ee9c8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3527 | PC: 0x166b20 | FDE: 0x1ee9e8 | Size: 256 bytes
// Khung tháo gỡ #3527 | Địa chỉ PC: 0x166b20 | Địa chỉ FDE: 0x1ee9e8 | Kích thước: 256 bytes
//   0x166b20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x166b24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x166b28: 910043FD  add      x29, sp, #0x10
//   0x166b2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3527_0x166b20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166b20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ee9e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3528 | PC: 0x166c34 | FDE: 0x1eea08 | Size: 256 bytes
// Khung tháo gỡ #3528 | Địa chỉ PC: 0x166c34 | Địa chỉ FDE: 0x1eea08 | Kích thước: 256 bytes
//   0x166c34: D10103FF  sub      sp, sp, #0x40
//   0x166c38: F9000BF5  str      x21, [sp, #0x10]
//   0x166c3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x166c40: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3528_0x166c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166c34ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1eea08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3529 | PC: 0x166db4 | FDE: 0x1eea28 | Size: 256 bytes
// Khung tháo gỡ #3529 | Địa chỉ PC: 0x166db4 | Địa chỉ FDE: 0x1eea28 | Kích thước: 256 bytes
//   0x166db4: D10283FF  sub      sp, sp, #0xa0
//   0x166db8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x166dbc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x166dc0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_3529_0x166db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166db4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1eea28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3530 | PC: 0x168d68 | FDE: 0x1eea58 | Size: 88 bytes
// Khung tháo gỡ #3530 | Địa chỉ PC: 0x168d68 | Địa chỉ FDE: 0x1eea58 | Kích thước: 88 bytes
//   0x168d68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x168d6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x168d70: 910043FD  add      x29, sp, #0x10
//   0x168d74: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3530_0x168d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168d68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eea58ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3531 | PC: 0x168dc0 | FDE: 0x1eea78 | Size: 176 bytes
// Khung tháo gỡ #3531 | Địa chỉ PC: 0x168dc0 | Địa chỉ FDE: 0x1eea78 | Kích thước: 176 bytes
//   0x168dc0: D10143FF  sub      sp, sp, #0x50
//   0x168dc4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x168dc8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x168dcc: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_3531_0x168dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168dc0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1eea78ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3532 | PC: 0x168e70 | FDE: 0x1eea98 | Size: 188 bytes
// Khung tháo gỡ #3532 | Địa chỉ PC: 0x168e70 | Địa chỉ FDE: 0x1eea98 | Kích thước: 188 bytes
//   0x168e70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x168e74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x168e78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x168e7c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3532_0x168e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168e70ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eea98ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3533 | PC: 0x168f2c | FDE: 0x1eeab8 | Size: 256 bytes
// Khung tháo gỡ #3533 | Địa chỉ PC: 0x168f2c | Địa chỉ FDE: 0x1eeab8 | Kích thước: 256 bytes
//   0x168f2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x168f30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x168f34: 910043FD  add      x29, sp, #0x10
//   0x168f38: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3533_0x168f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168f2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eeab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3534 | PC: 0x169040 | FDE: 0x1eead8 | Size: 256 bytes
// Khung tháo gỡ #3534 | Địa chỉ PC: 0x169040 | Địa chỉ FDE: 0x1eead8 | Kích thước: 256 bytes
//   0x169040: D10243FF  sub      sp, sp, #0x90
//   0x169044: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x169048: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x16904c: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_3534_0x169040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169040ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x1eead8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3535 | PC: 0x169230 | FDE: 0x1eeaf8 | Size: 256 bytes
// Khung tháo gỡ #3535 | Địa chỉ PC: 0x169230 | Địa chỉ FDE: 0x1eeaf8 | Kích thước: 256 bytes
//   0x169230: D102C3FF  sub      sp, sp, #0xb0
//   0x169234: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x169238: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x16923c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_3535_0x169230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169230ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x1eeaf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3536 | PC: 0x169f0c | FDE: 0x1eeb28 | Size: 12 bytes [PyInit__locale]
// Khung tháo gỡ #3536 | Địa chỉ PC: 0x169f0c | Địa chỉ FDE: 0x1eeb28 | Kích thước: 12 bytes
//   0x169f0c: 900005A0  adrp     x0, #0x21d000
//   0x169f10: 910D4000  add      x0, x0, #0x350
//   0x169f14: 17FBBAC3  b        #0x58a20
static inline uint64_t fde_func_3536_0x169f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169f0cULL ^ (static_cast<uint64_t>(0x900005a0ULL) << 13);
    acc = (acc + a1 + 0x910d4000ULL) ^ 0x1eeb28ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3537 | PC: 0x169f18 | FDE: 0x1eeb40 | Size: 60 bytes
// Khung tháo gỡ #3537 | Địa chỉ PC: 0x169f18 | Địa chỉ FDE: 0x1eeb40 | Kích thước: 60 bytes
//   0x169f18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x169f1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x169f20: 910043FD  add      x29, sp, #0x10
//   0x169f24: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_3537_0x169f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169f18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eeb40ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3538 | PC: 0x169f54 | FDE: 0x1eeb60 | Size: 60 bytes
// Khung tháo gỡ #3538 | Địa chỉ PC: 0x169f54 | Địa chỉ FDE: 0x1eeb60 | Kích thước: 60 bytes
//   0x169f54: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x169f58: 910003FD  mov      x29, sp
//   0x169f5c: 97FBBFC9  bl       #0x59e80
//   0x169f60: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_3538_0x169f54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169f54ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eeb60ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3539 | PC: 0x169f90 | FDE: 0x1eeb80 | Size: 60 bytes
// Khung tháo gỡ #3539 | Địa chỉ PC: 0x169f90 | Địa chỉ FDE: 0x1eeb80 | Kích thước: 60 bytes
//   0x169f90: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x169f94: 910003FD  mov      x29, sp
//   0x169f98: 97FBBFBA  bl       #0x59e80
//   0x169f9c: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_3539_0x169f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169f90ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eeb80ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3540 | PC: 0x169fcc | FDE: 0x1eeba0 | Size: 256 bytes
// Khung tháo gỡ #3540 | Địa chỉ PC: 0x169fcc | Địa chỉ FDE: 0x1eeba0 | Kích thước: 256 bytes
//   0x169fcc: D10143FF  sub      sp, sp, #0x50
//   0x169fd0: F9000BF7  str      x23, [sp, #0x10]
//   0x169fd4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x169fd8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3540_0x169fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169fccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1eeba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3541 | PC: 0x16a154 | FDE: 0x1eebc8 | Size: 256 bytes
// Khung tháo gỡ #3541 | Địa chỉ PC: 0x16a154 | Địa chỉ FDE: 0x1eebc8 | Kích thước: 256 bytes
//   0x16a154: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16a158: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16a15c: 910043FD  add      x29, sp, #0x10
//   0x16a160: D0000281  adrp     x1, #0x1bc000
static inline uint64_t fde_func_3541_0x16a154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a154ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eebc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3542 | PC: 0x16a2c0 | FDE: 0x1eebe8 | Size: 12 bytes [PyInit__lsprof]
// Khung tháo gỡ #3542 | Địa chỉ PC: 0x16a2c0 | Địa chỉ FDE: 0x1eebe8 | Kích thước: 12 bytes
//   0x16a2c0: F0000580  adrp     x0, #0x21d000
//   0x16a2c4: 91106000  add      x0, x0, #0x418
//   0x16a2c8: 17FBB9D6  b        #0x58a20
static inline uint64_t fde_func_3542_0x16a2c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a2c0ULL ^ (static_cast<uint64_t>(0xf0000580ULL) << 13);
    acc = (acc + a1 + 0x91106000ULL) ^ 0x1eebe8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3543 | PC: 0x16a2cc | FDE: 0x1eec00 | Size: 112 bytes
// Khung tháo gỡ #3543 | Địa chỉ PC: 0x16a2cc | Địa chỉ FDE: 0x1eec00 | Kích thước: 112 bytes
//   0x16a2cc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16a2d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16a2d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16a2d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3543_0x16a2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a2ccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eec00ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3544 | PC: 0x16a33c | FDE: 0x1eec20 | Size: 152 bytes
// Khung tháo gỡ #3544 | Địa chỉ PC: 0x16a33c | Địa chỉ FDE: 0x1eec20 | Kích thước: 152 bytes
//   0x16a33c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16a340: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16a344: 910043FD  add      x29, sp, #0x10
//   0x16a348: 97FBBECE  bl       #0x59e80
static inline uint64_t fde_func_3544_0x16a33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a33cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eec20ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3545 | PC: 0x16a3d4 | FDE: 0x1eec40 | Size: 4 bytes
// Khung tháo gỡ #3545 | Địa chỉ PC: 0x16a3d4 | Địa chỉ FDE: 0x1eec40 | Kích thước: 4 bytes
//   0x16a3d4: 17FFFFDA  b        #0x16a33c
static inline uint64_t fde_func_3545_0x16a3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a3d4ULL ^ (static_cast<uint64_t>(0x17ffffdaULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1eec40ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3546 | PC: 0x16a3d8 | FDE: 0x1eec58 | Size: 160 bytes
// Khung tháo gỡ #3546 | Địa chỉ PC: 0x16a3d8 | Địa chỉ FDE: 0x1eec58 | Kích thước: 160 bytes
//   0x16a3d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16a3dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16a3e0: 910043FD  add      x29, sp, #0x10
//   0x16a3e4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3546_0x16a3d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a3d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eec58ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3547 | PC: 0x16a478 | FDE: 0x1eec78 | Size: 256 bytes
// Khung tháo gỡ #3547 | Địa chỉ PC: 0x16a478 | Địa chỉ FDE: 0x1eec78 | Kích thước: 256 bytes
//   0x16a478: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16a47c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16a480: 910043FD  add      x29, sp, #0x10
//   0x16a484: 3940A008  ldrb     w8, [x0, #0x28]
static inline uint64_t fde_func_3547_0x16a478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a478ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eec78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3548 | PC: 0x16a584 | FDE: 0x1eec98 | Size: 256 bytes
// Khung tháo gỡ #3548 | Địa chỉ PC: 0x16a584 | Địa chỉ FDE: 0x1eec98 | Kích thước: 256 bytes
//   0x16a584: D10103FF  sub      sp, sp, #0x40
//   0x16a588: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16a58c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x16a590: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3548_0x16a584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a584ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1eec98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3549 | PC: 0x16a6a0 | FDE: 0x1eecb8 | Size: 52 bytes
// Khung tháo gỡ #3549 | Địa chỉ PC: 0x16a6a0 | Địa chỉ FDE: 0x1eecb8 | Kích thước: 52 bytes
//   0x16a6a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16a6a4: 910003FD  mov      x29, sp
//   0x16a6a8: F9400400  ldr      x0, [x0, #8]
//   0x16a6ac: B40000E0  cbz      x0, #0x16a6c8
static inline uint64_t fde_func_3549_0x16a6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a6a0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eecb8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3550 | PC: 0x16a6d4 | FDE: 0x1eecd8 | Size: 256 bytes
// Khung tháo gỡ #3550 | Địa chỉ PC: 0x16a6d4 | Địa chỉ FDE: 0x1eecd8 | Kích thước: 256 bytes
//   0x16a6d4: D10183FF  sub      sp, sp, #0x60
//   0x16a6d8: F9001BF5  str      x21, [sp, #0x30]
//   0x16a6dc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x16a6e0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_3550_0x16a6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a6d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1eecd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3551 | PC: 0x16a7f4 | FDE: 0x1eecf8 | Size: 256 bytes
// Khung tháo gỡ #3551 | Địa chỉ PC: 0x16a7f4 | Địa chỉ FDE: 0x1eecf8 | Kích thước: 256 bytes
//   0x16a7f4: D100C3FF  sub      sp, sp, #0x30
//   0x16a7f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16a7fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16a800: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3551_0x16a7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a7f4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eecf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3552 | PC: 0x16a8fc | FDE: 0x1eed18 | Size: 188 bytes
// Khung tháo gỡ #3552 | Địa chỉ PC: 0x16a8fc | Địa chỉ FDE: 0x1eed18 | Kích thước: 188 bytes
//   0x16a8fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16a900: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16a904: 910043FD  add      x29, sp, #0x10
//   0x16a908: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3552_0x16a8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a8fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eed18ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3553 | PC: 0x16a9b8 | FDE: 0x1eed38 | Size: 116 bytes
// Khung tháo gỡ #3553 | Địa chỉ PC: 0x16a9b8 | Địa chỉ FDE: 0x1eed38 | Kích thước: 116 bytes
//   0x16a9b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16a9bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16a9c0: 910043FD  add      x29, sp, #0x10
//   0x16a9c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3553_0x16a9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a9b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eed38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3554 | PC: 0x16aa2c | FDE: 0x1eed58 | Size: 256 bytes
// Khung tháo gỡ #3554 | Địa chỉ PC: 0x16aa2c | Địa chỉ FDE: 0x1eed58 | Kích thước: 256 bytes
//   0x16aa2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16aa30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16aa34: 910043FD  add      x29, sp, #0x10
//   0x16aa38: F9401803  ldr      x3, [x0, #0x30]
static inline uint64_t fde_func_3554_0x16aa2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16aa2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eed58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3555 | PC: 0x16ab58 | FDE: 0x1eed78 | Size: 144 bytes
// Khung tháo gỡ #3555 | Địa chỉ PC: 0x16ab58 | Địa chỉ FDE: 0x1eed78 | Kích thước: 144 bytes
//   0x16ab58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16ab5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16ab60: 910043FD  add      x29, sp, #0x10
//   0x16ab64: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_3555_0x16ab58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ab58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eed78ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3556 | PC: 0x16abe8 | FDE: 0x1eed98 | Size: 256 bytes
// Khung tháo gỡ #3556 | Địa chỉ PC: 0x16abe8 | Địa chỉ FDE: 0x1eed98 | Kích thước: 256 bytes
//   0x16abe8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16abec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16abf0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16abf4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3556_0x16abe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16abe8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eed98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3557 | PC: 0x16ad6c | FDE: 0x1eedb8 | Size: 256 bytes
// Khung tháo gỡ #3557 | Địa chỉ PC: 0x16ad6c | Địa chỉ FDE: 0x1eedb8 | Kích thước: 256 bytes
//   0x16ad6c: D10203FF  sub      sp, sp, #0x80
//   0x16ad70: F90013FB  str      x27, [sp, #0x20]
//   0x16ad74: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x16ad78: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3557_0x16ad6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ad6cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1eedb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3558 | PC: 0x16b0f8 | FDE: 0x1eede8 | Size: 256 bytes
// Khung tháo gỡ #3558 | Địa chỉ PC: 0x16b0f8 | Địa chỉ FDE: 0x1eede8 | Kích thước: 256 bytes
//   0x16b0f8: D10103FF  sub      sp, sp, #0x40
//   0x16b0fc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x16b100: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16b104: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3558_0x16b0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b0f8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eede8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3559 | PC: 0x16b224 | FDE: 0x1eee10 | Size: 228 bytes
// Khung tháo gỡ #3559 | Địa chỉ PC: 0x16b224 | Địa chỉ FDE: 0x1eee10 | Kích thước: 228 bytes
//   0x16b224: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x16b228: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16b22c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16b230: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3559_0x16b224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b224ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eee10ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #3560 | PC: 0x16b308 | FDE: 0x1eee38 | Size: 84 bytes
// Khung tháo gỡ #3560 | Địa chỉ PC: 0x16b308 | Địa chỉ FDE: 0x1eee38 | Kích thước: 84 bytes
//   0x16b308: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b30c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b310: 910043FD  add      x29, sp, #0x10
//   0x16b314: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3560_0x16b308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b308ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eee38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3561 | PC: 0x16b35c | FDE: 0x1eee58 | Size: 24 bytes
// Khung tháo gỡ #3561 | Địa chỉ PC: 0x16b35c | Địa chỉ FDE: 0x1eee58 | Kích thước: 24 bytes
//   0x16b35c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16b360: 910003FD  mov      x29, sp
//   0x16b364: 97FBB627  bl       #0x58c00
//   0x16b368: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_3561_0x16b35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b35cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eee58ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3562 | PC: 0x16b374 | FDE: 0x1eee78 | Size: 16 bytes [_Py_log1p]
// Khung tháo gỡ #3562 | Địa chỉ PC: 0x16b374 | Địa chỉ FDE: 0x1eee78 | Kích thước: 16 bytes
//   0x16b374: 1E602008  fcmp     d0, #0.0
//   0x16b378: 54000041  b.ne     #0x16b380
//   0x16b37c: D65F03C0  ret      
//   0x16b380: 17FBB968  b        #0x59920
static inline uint64_t fde_func_3562_0x16b374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b374ULL ^ (static_cast<uint64_t>(0x1e602008ULL) << 13);
    acc = (acc + a1 + 0x54000041ULL) ^ 0x1eee78ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3563 | PC: 0x16b384 | FDE: 0x1eee90 | Size: 12 bytes [PyInit__operator]
// Khung tháo gỡ #3563 | Địa chỉ PC: 0x16b384 | Địa chỉ FDE: 0x1eee90 | Kích thước: 12 bytes
//   0x16b384: D0000580  adrp     x0, #0x21d000
//   0x16b388: 911D4000  add      x0, x0, #0x750
//   0x16b38c: 17FBB5A5  b        #0x58a20
static inline uint64_t fde_func_3563_0x16b384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b384ULL ^ (static_cast<uint64_t>(0xd0000580ULL) << 13);
    acc = (acc + a1 + 0x911d4000ULL) ^ 0x1eee90ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3564 | PC: 0x16b390 | FDE: 0x1eeea8 | Size: 108 bytes
// Khung tháo gỡ #3564 | Địa chỉ PC: 0x16b390 | Địa chỉ FDE: 0x1eeea8 | Kích thước: 108 bytes
//   0x16b390: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16b394: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16b398: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16b39c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3564_0x16b390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b390ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eeea8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3565 | PC: 0x16b3fc | FDE: 0x1eeec8 | Size: 148 bytes
// Khung tháo gỡ #3565 | Địa chỉ PC: 0x16b3fc | Địa chỉ FDE: 0x1eeec8 | Kích thước: 148 bytes
//   0x16b3fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b400: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b404: 910043FD  add      x29, sp, #0x10
//   0x16b408: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3565_0x16b3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b3fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eeec8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3566 | PC: 0x16b490 | FDE: 0x1eeee8 | Size: 152 bytes
// Khung tháo gỡ #3566 | Địa chỉ PC: 0x16b490 | Địa chỉ FDE: 0x1eeee8 | Kích thước: 152 bytes
//   0x16b490: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b494: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b498: 910043FD  add      x29, sp, #0x10
//   0x16b49c: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3566_0x16b490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b490ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eeee8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3567 | PC: 0x16b528 | FDE: 0x1eef08 | Size: 72 bytes
// Khung tháo gỡ #3567 | Địa chỉ PC: 0x16b528 | Địa chỉ FDE: 0x1eef08 | Kích thước: 72 bytes
//   0x16b528: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b52c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b530: 910043FD  add      x29, sp, #0x10
//   0x16b534: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3567_0x16b528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b528ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eef08ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3568 | PC: 0x16b570 | FDE: 0x1eef28 | Size: 116 bytes
// Khung tháo gỡ #3568 | Địa chỉ PC: 0x16b570 | Địa chỉ FDE: 0x1eef28 | Kích thước: 116 bytes
//   0x16b570: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b574: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b578: 910043FD  add      x29, sp, #0x10
//   0x16b57c: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3568_0x16b570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b570ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eef28ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3569 | PC: 0x16b5e4 | FDE: 0x1eef48 | Size: 116 bytes
// Khung tháo gỡ #3569 | Địa chỉ PC: 0x16b5e4 | Địa chỉ FDE: 0x1eef48 | Kích thước: 116 bytes
//   0x16b5e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b5e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b5ec: 910043FD  add      x29, sp, #0x10
//   0x16b5f0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3569_0x16b5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b5e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eef48ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3570 | PC: 0x16b658 | FDE: 0x1eef68 | Size: 116 bytes
// Khung tháo gỡ #3570 | Địa chỉ PC: 0x16b658 | Địa chỉ FDE: 0x1eef68 | Kích thước: 116 bytes
//   0x16b658: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b65c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b660: 910043FD  add      x29, sp, #0x10
//   0x16b664: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3570_0x16b658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b658ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eef68ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3571 | PC: 0x16b6cc | FDE: 0x1eef88 | Size: 116 bytes
// Khung tháo gỡ #3571 | Địa chỉ PC: 0x16b6cc | Địa chỉ FDE: 0x1eef88 | Kích thước: 116 bytes
//   0x16b6cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b6d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b6d4: 910043FD  add      x29, sp, #0x10
//   0x16b6d8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3571_0x16b6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b6ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eef88ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3572 | PC: 0x16b740 | FDE: 0x1eefa8 | Size: 116 bytes
// Khung tháo gỡ #3572 | Địa chỉ PC: 0x16b740 | Địa chỉ FDE: 0x1eefa8 | Kích thước: 116 bytes
//   0x16b740: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b744: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b748: 910043FD  add      x29, sp, #0x10
//   0x16b74c: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3572_0x16b740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b740ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eefa8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3573 | PC: 0x16b7b4 | FDE: 0x1eefc8 | Size: 8 bytes
// Khung tháo gỡ #3573 | Địa chỉ PC: 0x16b7b4 | Địa chỉ FDE: 0x1eefc8 | Kích thước: 8 bytes
//   0x16b7b4: AA0103E0  mov      x0, x1
//   0x16b7b8: 17FBC602  b        #0x5cfc0
static inline uint64_t fde_func_3573_0x16b7b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b7b4ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fbc602ULL) ^ 0x1eefc8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3574 | PC: 0x16b7bc | FDE: 0x1eefe0 | Size: 88 bytes
// Khung tháo gỡ #3574 | Địa chỉ PC: 0x16b7bc | Địa chỉ FDE: 0x1eefe0 | Kích thước: 88 bytes
//   0x16b7bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b7c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b7c4: 910043FD  add      x29, sp, #0x10
//   0x16b7c8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3574_0x16b7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b7bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eefe0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3575 | PC: 0x16b814 | FDE: 0x1ef000 | Size: 88 bytes
// Khung tháo gỡ #3575 | Địa chỉ PC: 0x16b814 | Địa chỉ FDE: 0x1ef000 | Kích thước: 88 bytes
//   0x16b814: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b818: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b81c: 910043FD  add      x29, sp, #0x10
//   0x16b820: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3575_0x16b814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b814ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef000ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3576 | PC: 0x16b86c | FDE: 0x1ef020 | Size: 88 bytes
// Khung tháo gỡ #3576 | Địa chỉ PC: 0x16b86c | Địa chỉ FDE: 0x1ef020 | Kích thước: 88 bytes
//   0x16b86c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b870: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b874: 910043FD  add      x29, sp, #0x10
//   0x16b878: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3576_0x16b86c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b86cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef020ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3577 | PC: 0x16b8c4 | FDE: 0x1ef040 | Size: 88 bytes
// Khung tháo gỡ #3577 | Địa chỉ PC: 0x16b8c4 | Địa chỉ FDE: 0x1ef040 | Kích thước: 88 bytes
//   0x16b8c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b8c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b8cc: 910043FD  add      x29, sp, #0x10
//   0x16b8d0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3577_0x16b8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b8c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef040ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3578 | PC: 0x16b91c | FDE: 0x1ef060 | Size: 88 bytes
// Khung tháo gỡ #3578 | Địa chỉ PC: 0x16b91c | Địa chỉ FDE: 0x1ef060 | Kích thước: 88 bytes
//   0x16b91c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b920: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b924: 910043FD  add      x29, sp, #0x10
//   0x16b928: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3578_0x16b91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b91cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef060ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3579 | PC: 0x16b974 | FDE: 0x1ef080 | Size: 88 bytes
// Khung tháo gỡ #3579 | Địa chỉ PC: 0x16b974 | Địa chỉ FDE: 0x1ef080 | Kích thước: 88 bytes
//   0x16b974: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b978: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b97c: 910043FD  add      x29, sp, #0x10
//   0x16b980: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3579_0x16b974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b974ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef080ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3580 | PC: 0x16b9cc | FDE: 0x1ef0a0 | Size: 88 bytes
// Khung tháo gỡ #3580 | Địa chỉ PC: 0x16b9cc | Địa chỉ FDE: 0x1ef0a0 | Kích thước: 88 bytes
//   0x16b9cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16b9d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16b9d4: 910043FD  add      x29, sp, #0x10
//   0x16b9d8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3580_0x16b9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b9ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef0a0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3581 | PC: 0x16ba24 | FDE: 0x1ef0c0 | Size: 8 bytes
// Khung tháo gỡ #3581 | Địa chỉ PC: 0x16ba24 | Địa chỉ FDE: 0x1ef0c0 | Kích thước: 8 bytes
//   0x16ba24: AA0103E0  mov      x0, x1
//   0x16ba28: 17FBB232  b        #0x582f0
static inline uint64_t fde_func_3581_0x16ba24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ba24ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fbb232ULL) ^ 0x1ef0c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3582 | PC: 0x16ba2c | FDE: 0x1ef0d8 | Size: 8 bytes
// Khung tháo gỡ #3582 | Địa chỉ PC: 0x16ba2c | Địa chỉ FDE: 0x1ef0d8 | Kích thước: 8 bytes
//   0x16ba2c: AA0103E0  mov      x0, x1
//   0x16ba30: 17FBC464  b        #0x5cbc0
static inline uint64_t fde_func_3582_0x16ba2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ba2cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fbc464ULL) ^ 0x1ef0d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3583 | PC: 0x16ba34 | FDE: 0x1ef0f0 | Size: 8 bytes
// Khung tháo gỡ #3583 | Địa chỉ PC: 0x16ba34 | Địa chỉ FDE: 0x1ef0f0 | Kích thước: 8 bytes
//   0x16ba34: AA0103E0  mov      x0, x1
//   0x16ba38: 17FBB6D6  b        #0x59590
static inline uint64_t fde_func_3583_0x16ba34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ba34ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fbb6d6ULL) ^ 0x1ef0f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3584 | PC: 0x16ba3c | FDE: 0x1ef108 | Size: 8 bytes
// Khung tháo gỡ #3584 | Địa chỉ PC: 0x16ba3c | Địa chỉ FDE: 0x1ef108 | Kích thước: 8 bytes
//   0x16ba3c: AA0103E0  mov      x0, x1
//   0x16ba40: 17FBC5B0  b        #0x5d100
static inline uint64_t fde_func_3584_0x16ba3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ba3cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fbc5b0ULL) ^ 0x1ef108ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3585 | PC: 0x16ba44 | FDE: 0x1ef120 | Size: 8 bytes
// Khung tháo gỡ #3585 | Địa chỉ PC: 0x16ba44 | Địa chỉ FDE: 0x1ef120 | Kích thước: 8 bytes
//   0x16ba44: AA0103E0  mov      x0, x1
//   0x16ba48: 17FBC5AE  b        #0x5d100
static inline uint64_t fde_func_3585_0x16ba44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ba44ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fbc5aeULL) ^ 0x1ef120ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3586 | PC: 0x16ba4c | FDE: 0x1ef138 | Size: 88 bytes
// Khung tháo gỡ #3586 | Địa chỉ PC: 0x16ba4c | Địa chỉ FDE: 0x1ef138 | Kích thước: 88 bytes
//   0x16ba4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16ba50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16ba54: 910043FD  add      x29, sp, #0x10
//   0x16ba58: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3586_0x16ba4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ba4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef138ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3587 | PC: 0x16baa4 | FDE: 0x1ef158 | Size: 88 bytes
// Khung tháo gỡ #3587 | Địa chỉ PC: 0x16baa4 | Địa chỉ FDE: 0x1ef158 | Kích thước: 88 bytes
//   0x16baa4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16baa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16baac: 910043FD  add      x29, sp, #0x10
//   0x16bab0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3587_0x16baa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16baa4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef158ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3588 | PC: 0x16bafc | FDE: 0x1ef178 | Size: 72 bytes
// Khung tháo gỡ #3588 | Địa chỉ PC: 0x16bafc | Địa chỉ FDE: 0x1ef178 | Kích thước: 72 bytes
//   0x16bafc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bb00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bb04: 910043FD  add      x29, sp, #0x10
//   0x16bb08: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3588_0x16bafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bafcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef178ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3589 | PC: 0x16bb44 | FDE: 0x1ef198 | Size: 88 bytes
// Khung tháo gỡ #3589 | Địa chỉ PC: 0x16bb44 | Địa chỉ FDE: 0x1ef198 | Kích thước: 88 bytes
//   0x16bb44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bb48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bb4c: 910043FD  add      x29, sp, #0x10
//   0x16bb50: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3589_0x16bb44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bb44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef198ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3590 | PC: 0x16bb9c | FDE: 0x1ef1b8 | Size: 88 bytes
// Khung tháo gỡ #3590 | Địa chỉ PC: 0x16bb9c | Địa chỉ FDE: 0x1ef1b8 | Kích thước: 88 bytes
//   0x16bb9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bba0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bba4: 910043FD  add      x29, sp, #0x10
//   0x16bba8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3590_0x16bb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bb9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef1b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3591 | PC: 0x16bbf4 | FDE: 0x1ef1d8 | Size: 88 bytes
// Khung tháo gỡ #3591 | Địa chỉ PC: 0x16bbf4 | Địa chỉ FDE: 0x1ef1d8 | Kích thước: 88 bytes
//   0x16bbf4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bbf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bbfc: 910043FD  add      x29, sp, #0x10
//   0x16bc00: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3591_0x16bbf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bbf4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef1d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3592 | PC: 0x16bc4c | FDE: 0x1ef1f8 | Size: 88 bytes
// Khung tháo gỡ #3592 | Địa chỉ PC: 0x16bc4c | Địa chỉ FDE: 0x1ef1f8 | Kích thước: 88 bytes
//   0x16bc4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bc50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bc54: 910043FD  add      x29, sp, #0x10
//   0x16bc58: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3592_0x16bc4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bc4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef1f8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3593 | PC: 0x16bca4 | FDE: 0x1ef218 | Size: 88 bytes
// Khung tháo gỡ #3593 | Địa chỉ PC: 0x16bca4 | Địa chỉ FDE: 0x1ef218 | Kích thước: 88 bytes
//   0x16bca4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bca8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bcac: 910043FD  add      x29, sp, #0x10
//   0x16bcb0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3593_0x16bca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bca4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef218ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3594 | PC: 0x16bcfc | FDE: 0x1ef238 | Size: 88 bytes
// Khung tháo gỡ #3594 | Địa chỉ PC: 0x16bcfc | Địa chỉ FDE: 0x1ef238 | Kích thước: 88 bytes
//   0x16bcfc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bd00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bd04: 910043FD  add      x29, sp, #0x10
//   0x16bd08: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3594_0x16bcfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bcfcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef238ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3595 | PC: 0x16bd54 | FDE: 0x1ef258 | Size: 88 bytes
// Khung tháo gỡ #3595 | Địa chỉ PC: 0x16bd54 | Địa chỉ FDE: 0x1ef258 | Kích thước: 88 bytes
//   0x16bd54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bd58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bd5c: 910043FD  add      x29, sp, #0x10
//   0x16bd60: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3595_0x16bd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bd54ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef258ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3596 | PC: 0x16bdac | FDE: 0x1ef278 | Size: 88 bytes
// Khung tháo gỡ #3596 | Địa chỉ PC: 0x16bdac | Địa chỉ FDE: 0x1ef278 | Kích thước: 88 bytes
//   0x16bdac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bdb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bdb4: 910043FD  add      x29, sp, #0x10
//   0x16bdb8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3596_0x16bdac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bdacULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef278ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3597 | PC: 0x16be04 | FDE: 0x1ef298 | Size: 88 bytes
// Khung tháo gỡ #3597 | Địa chỉ PC: 0x16be04 | Địa chỉ FDE: 0x1ef298 | Kích thước: 88 bytes
//   0x16be04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16be08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16be0c: 910043FD  add      x29, sp, #0x10
//   0x16be10: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3597_0x16be04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16be04ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef298ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3598 | PC: 0x16be5c | FDE: 0x1ef2b8 | Size: 88 bytes
// Khung tháo gỡ #3598 | Địa chỉ PC: 0x16be5c | Địa chỉ FDE: 0x1ef2b8 | Kích thước: 88 bytes
//   0x16be5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16be60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16be64: 910043FD  add      x29, sp, #0x10
//   0x16be68: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3598_0x16be5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16be5cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef2b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3599 | PC: 0x16beb4 | FDE: 0x1ef2d8 | Size: 88 bytes
// Khung tháo gỡ #3599 | Địa chỉ PC: 0x16beb4 | Địa chỉ FDE: 0x1ef2d8 | Kích thước: 88 bytes
//   0x16beb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16beb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bebc: 910043FD  add      x29, sp, #0x10
//   0x16bec0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3599_0x16beb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16beb4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef2d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3600 | PC: 0x16bf0c | FDE: 0x1ef2f8 | Size: 88 bytes
// Khung tháo gỡ #3600 | Địa chỉ PC: 0x16bf0c | Địa chỉ FDE: 0x1ef2f8 | Kích thước: 88 bytes
//   0x16bf0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bf10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bf14: 910043FD  add      x29, sp, #0x10
//   0x16bf18: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3600_0x16bf0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bf0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef2f8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3601 | PC: 0x16bf64 | FDE: 0x1ef318 | Size: 88 bytes
// Khung tháo gỡ #3601 | Địa chỉ PC: 0x16bf64 | Địa chỉ FDE: 0x1ef318 | Kích thước: 88 bytes
//   0x16bf64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bf68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bf6c: 910043FD  add      x29, sp, #0x10
//   0x16bf70: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3601_0x16bf64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bf64ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef318ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3602 | PC: 0x16bfbc | FDE: 0x1ef338 | Size: 88 bytes
// Khung tháo gỡ #3602 | Địa chỉ PC: 0x16bfbc | Địa chỉ FDE: 0x1ef338 | Kích thước: 88 bytes
//   0x16bfbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16bfc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16bfc4: 910043FD  add      x29, sp, #0x10
//   0x16bfc8: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3602_0x16bfbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bfbcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef338ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3603 | PC: 0x16c014 | FDE: 0x1ef358 | Size: 88 bytes
// Khung tháo gỡ #3603 | Địa chỉ PC: 0x16c014 | Địa chỉ FDE: 0x1ef358 | Kích thước: 88 bytes
//   0x16c014: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c018: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c01c: 910043FD  add      x29, sp, #0x10
//   0x16c020: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3603_0x16c014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c014ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef358ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3604 | PC: 0x16c06c | FDE: 0x1ef378 | Size: 88 bytes
// Khung tháo gỡ #3604 | Địa chỉ PC: 0x16c06c | Địa chỉ FDE: 0x1ef378 | Kích thước: 88 bytes
//   0x16c06c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c070: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c074: 910043FD  add      x29, sp, #0x10
//   0x16c078: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3604_0x16c06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c06cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef378ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3605 | PC: 0x16c0c4 | FDE: 0x1ef398 | Size: 88 bytes
// Khung tháo gỡ #3605 | Địa chỉ PC: 0x16c0c4 | Địa chỉ FDE: 0x1ef398 | Kích thước: 88 bytes
//   0x16c0c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c0c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c0cc: 910043FD  add      x29, sp, #0x10
//   0x16c0d0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3605_0x16c0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c0c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef398ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3606 | PC: 0x16c11c | FDE: 0x1ef3b8 | Size: 88 bytes
// Khung tháo gỡ #3606 | Địa chỉ PC: 0x16c11c | Địa chỉ FDE: 0x1ef3b8 | Kích thước: 88 bytes
//   0x16c11c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c120: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c124: 910043FD  add      x29, sp, #0x10
//   0x16c128: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3606_0x16c11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c11cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef3b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3607 | PC: 0x16c174 | FDE: 0x1ef3d8 | Size: 116 bytes
// Khung tháo gỡ #3607 | Địa chỉ PC: 0x16c174 | Địa chỉ FDE: 0x1ef3d8 | Kích thước: 116 bytes
//   0x16c174: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c178: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c17c: 910043FD  add      x29, sp, #0x10
//   0x16c180: F1000C5F  cmp      x2, #3
static inline uint64_t fde_func_3607_0x16c174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c174ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef3d8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3608 | PC: 0x16c1e8 | FDE: 0x1ef3f8 | Size: 112 bytes
// Khung tháo gỡ #3608 | Địa chỉ PC: 0x16c1e8 | Địa chỉ FDE: 0x1ef3f8 | Kích thước: 112 bytes
//   0x16c1e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c1ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c1f0: 910043FD  add      x29, sp, #0x10
//   0x16c1f4: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3608_0x16c1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c1e8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef3f8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3609 | PC: 0x16c258 | FDE: 0x1ef418 | Size: 96 bytes
// Khung tháo gỡ #3609 | Địa chỉ PC: 0x16c258 | Địa chỉ FDE: 0x1ef418 | Kích thước: 96 bytes
//   0x16c258: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c25c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c260: 910043FD  add      x29, sp, #0x10
//   0x16c264: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3609_0x16c258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c258ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef418ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #3610 | PC: 0x16c2b8 | FDE: 0x1ef438 | Size: 96 bytes
// Khung tháo gỡ #3610 | Địa chỉ PC: 0x16c2b8 | Địa chỉ FDE: 0x1ef438 | Kích thước: 96 bytes
//   0x16c2b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c2bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c2c0: 910043FD  add      x29, sp, #0x10
//   0x16c2c4: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3610_0x16c2b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c2b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef438ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #3611 | PC: 0x16c318 | FDE: 0x1ef458 | Size: 92 bytes
// Khung tháo gỡ #3611 | Địa chỉ PC: 0x16c318 | Địa chỉ FDE: 0x1ef458 | Kích thước: 92 bytes
//   0x16c318: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c31c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c320: 910043FD  add      x29, sp, #0x10
//   0x16c324: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3611_0x16c318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c318ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef458ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3612 | PC: 0x16c374 | FDE: 0x1ef478 | Size: 92 bytes
// Khung tháo gỡ #3612 | Địa chỉ PC: 0x16c374 | Địa chỉ FDE: 0x1ef478 | Kích thước: 92 bytes
//   0x16c374: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c378: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c37c: 910043FD  add      x29, sp, #0x10
//   0x16c380: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3612_0x16c374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c374ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef478ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3613 | PC: 0x16c3d0 | FDE: 0x1ef498 | Size: 92 bytes
// Khung tháo gỡ #3613 | Địa chỉ PC: 0x16c3d0 | Địa chỉ FDE: 0x1ef498 | Kích thước: 92 bytes
//   0x16c3d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c3d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c3d8: 910043FD  add      x29, sp, #0x10
//   0x16c3dc: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3613_0x16c3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c3d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef498ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3614 | PC: 0x16c42c | FDE: 0x1ef4b8 | Size: 92 bytes
// Khung tháo gỡ #3614 | Địa chỉ PC: 0x16c42c | Địa chỉ FDE: 0x1ef4b8 | Kích thước: 92 bytes
//   0x16c42c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c434: 910043FD  add      x29, sp, #0x10
//   0x16c438: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3614_0x16c42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c42cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef4b8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3615 | PC: 0x16c488 | FDE: 0x1ef4d8 | Size: 92 bytes
// Khung tháo gỡ #3615 | Địa chỉ PC: 0x16c488 | Địa chỉ FDE: 0x1ef4d8 | Kích thước: 92 bytes
//   0x16c488: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c48c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c490: 910043FD  add      x29, sp, #0x10
//   0x16c494: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3615_0x16c488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c488ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef4d8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3616 | PC: 0x16c4e4 | FDE: 0x1ef4f8 | Size: 92 bytes
// Khung tháo gỡ #3616 | Địa chỉ PC: 0x16c4e4 | Địa chỉ FDE: 0x1ef4f8 | Kích thước: 92 bytes
//   0x16c4e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16c4e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c4ec: 910043FD  add      x29, sp, #0x10
//   0x16c4f0: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3616_0x16c4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c4e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef4f8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3617 | PC: 0x16c540 | FDE: 0x1ef518 | Size: 256 bytes
// Khung tháo gỡ #3617 | Địa chỉ PC: 0x16c540 | Địa chỉ FDE: 0x1ef518 | Kích thước: 256 bytes
//   0x16c540: D103C3FF  sub      sp, sp, #0xf0
//   0x16c544: F90063F5  str      x21, [sp, #0xc0]
//   0x16c548: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x16c54c: A90E7BFD  stp      x29, x30, [sp, #0xe0]
static inline uint64_t fde_func_3617_0x16c540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c540ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf90063f5ULL) ^ 0x1ef518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3618 | PC: 0x16c844 | FDE: 0x1ef538 | Size: 236 bytes
// Khung tháo gỡ #3618 | Địa chỉ PC: 0x16c844 | Địa chỉ FDE: 0x1ef538 | Kích thước: 236 bytes
//   0x16c844: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16c848: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16c84c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16c850: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3618_0x16c844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c844ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef538ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3619 | PC: 0x16c930 | FDE: 0x1ef558 | Size: 168 bytes
// Khung tháo gỡ #3619 | Địa chỉ PC: 0x16c930 | Địa chỉ FDE: 0x1ef558 | Kích thước: 168 bytes
//   0x16c930: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16c934: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c938: 910043FD  add      x29, sp, #0x10
//   0x16c93c: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_3619_0x16c930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c930ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef558ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #3620 | PC: 0x16c9d8 | FDE: 0x1ef578 | Size: 112 bytes
// Khung tháo gỡ #3620 | Địa chỉ PC: 0x16c9d8 | Địa chỉ FDE: 0x1ef578 | Kích thước: 112 bytes
//   0x16c9d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16c9dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16c9e0: 910043FD  add      x29, sp, #0x10
//   0x16c9e4: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3620_0x16c9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c9d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef578ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3621 | PC: 0x16ca48 | FDE: 0x1ef598 | Size: 256 bytes
// Khung tháo gỡ #3621 | Địa chỉ PC: 0x16ca48 | Địa chỉ FDE: 0x1ef598 | Kích thước: 256 bytes
//   0x16ca48: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x16ca4c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x16ca50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x16ca54: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3621_0x16ca48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ca48ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ef598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3622 | PC: 0x16cc50 | FDE: 0x1ef5c8 | Size: 88 bytes
// Khung tháo gỡ #3622 | Địa chỉ PC: 0x16cc50 | Địa chỉ FDE: 0x1ef5c8 | Kích thước: 88 bytes
//   0x16cc50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16cc54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16cc58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16cc5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3622_0x16cc50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16cc50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef5c8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3623 | PC: 0x16cca8 | FDE: 0x1ef5e8 | Size: 56 bytes
// Khung tháo gỡ #3623 | Địa chỉ PC: 0x16cca8 | Địa chỉ FDE: 0x1ef5e8 | Kích thước: 56 bytes
//   0x16cca8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16ccac: 910003FD  mov      x29, sp
//   0x16ccb0: AA0003E8  mov      x8, x0
//   0x16ccb4: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_3623_0x16cca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16cca8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ef5e8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3624 | PC: 0x16cce0 | FDE: 0x1ef608 | Size: 256 bytes
// Khung tháo gỡ #3624 | Địa chỉ PC: 0x16cce0 | Địa chỉ FDE: 0x1ef608 | Kích thước: 256 bytes
//   0x16cce0: D10283FF  sub      sp, sp, #0xa0
//   0x16cce4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x16cce8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x16ccec: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_3624_0x16cce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16cce0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1ef608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3625 | PC: 0x16d02c | FDE: 0x1ef638 | Size: 256 bytes
// Khung tháo gỡ #3625 | Địa chỉ PC: 0x16d02c | Địa chỉ FDE: 0x1ef638 | Kích thước: 256 bytes
//   0x16d02c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x16d030: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16d034: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16d038: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3625_0x16d02c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d02cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3626 | PC: 0x16d180 | FDE: 0x1ef660 | Size: 64 bytes
// Khung tháo gỡ #3626 | Địa chỉ PC: 0x16d180 | Địa chỉ FDE: 0x1ef660 | Kích thước: 64 bytes
//   0x16d180: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16d184: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16d188: 910043FD  add      x29, sp, #0x10
//   0x16d18c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3626_0x16d180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d180ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef660ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3627 | PC: 0x16d1c0 | FDE: 0x1ef680 | Size: 256 bytes
// Khung tháo gỡ #3627 | Địa chỉ PC: 0x16d1c0 | Địa chỉ FDE: 0x1ef680 | Kích thước: 256 bytes
//   0x16d1c0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x16d1c4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x16d1c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x16d1cc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3627_0x16d1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d1c0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ef680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3628 | PC: 0x16d2ec | FDE: 0x1ef6a8 | Size: 112 bytes
// Khung tháo gỡ #3628 | Địa chỉ PC: 0x16d2ec | Địa chỉ FDE: 0x1ef6a8 | Kích thước: 112 bytes
//   0x16d2ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16d2f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16d2f4: 910043FD  add      x29, sp, #0x10
//   0x16d2f8: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3628_0x16d2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d2ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef6a8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3629 | PC: 0x16d35c | FDE: 0x1ef6c8 | Size: 256 bytes
// Khung tháo gỡ #3629 | Địa chỉ PC: 0x16d35c | Địa chỉ FDE: 0x1ef6c8 | Kích thước: 256 bytes
//   0x16d35c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x16d360: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x16d364: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16d368: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3629_0x16d35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d35cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ef6c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3630 | PC: 0x16d4a0 | FDE: 0x1ef6f0 | Size: 88 bytes
// Khung tháo gỡ #3630 | Địa chỉ PC: 0x16d4a0 | Địa chỉ FDE: 0x1ef6f0 | Kích thước: 88 bytes
//   0x16d4a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16d4a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16d4a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16d4ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3630_0x16d4a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d4a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef6f0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3631 | PC: 0x16d4f8 | FDE: 0x1ef710 | Size: 56 bytes
// Khung tháo gỡ #3631 | Địa chỉ PC: 0x16d4f8 | Địa chỉ FDE: 0x1ef710 | Kích thước: 56 bytes
//   0x16d4f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16d4fc: 910003FD  mov      x29, sp
//   0x16d500: AA0003E8  mov      x8, x0
//   0x16d504: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_3631_0x16d4f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d4f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ef710ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3632 | PC: 0x16d530 | FDE: 0x1ef730 | Size: 256 bytes
// Khung tháo gỡ #3632 | Địa chỉ PC: 0x16d530 | Địa chỉ FDE: 0x1ef730 | Kích thước: 256 bytes
//   0x16d530: D10103FF  sub      sp, sp, #0x40
//   0x16d534: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x16d538: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16d53c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3632_0x16d530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d530ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ef730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3633 | PC: 0x16d638 | FDE: 0x1ef758 | Size: 132 bytes
// Khung tháo gỡ #3633 | Địa chỉ PC: 0x16d638 | Địa chỉ FDE: 0x1ef758 | Kích thước: 132 bytes
//   0x16d638: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16d63c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16d640: 910043FD  add      x29, sp, #0x10
//   0x16d644: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3633_0x16d638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d638ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef758ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #3634 | PC: 0x16d6bc | FDE: 0x1ef778 | Size: 36 bytes
// Khung tháo gỡ #3634 | Địa chỉ PC: 0x16d6bc | Địa chỉ FDE: 0x1ef778 | Kích thước: 36 bytes
//   0x16d6bc: A940A001  ldp      x1, x8, [x0, #8]
//   0x16d6c0: F9400C02  ldr      x2, [x0, #0x18]
//   0x16d6c4: F100051F  cmp      x8, #1
//   0x16d6c8: 54000081  b.ne     #0x16d6d8
static inline uint64_t fde_func_3634_0x16d6bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d6bcULL ^ (static_cast<uint64_t>(0xa940a001ULL) << 13);
    acc = (acc + a1 + 0xf9400c02ULL) ^ 0x1ef778ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3635 | PC: 0x16d6e0 | FDE: 0x1ef790 | Size: 196 bytes
// Khung tháo gỡ #3635 | Địa chỉ PC: 0x16d6e0 | Địa chỉ FDE: 0x1ef790 | Kích thước: 196 bytes
//   0x16d6e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16d6e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16d6e8: 910043FD  add      x29, sp, #0x10
//   0x16d6ec: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3635_0x16d6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d6e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef790ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3636 | PC: 0x16d7a4 | FDE: 0x1ef7b0 | Size: 160 bytes
// Khung tháo gỡ #3636 | Địa chỉ PC: 0x16d7a4 | Địa chỉ FDE: 0x1ef7b0 | Kích thước: 160 bytes
//   0x16d7a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16d7a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16d7ac: 910043FD  add      x29, sp, #0x10
//   0x16d7b0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_3636_0x16d7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d7a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef7b0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3637 | PC: 0x16d844 | FDE: 0x1ef7d0 | Size: 128 bytes
// Khung tháo gỡ #3637 | Địa chỉ PC: 0x16d844 | Địa chỉ FDE: 0x1ef7d0 | Kích thước: 128 bytes
//   0x16d844: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16d848: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16d84c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16d850: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3637_0x16d844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d844ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef7d0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3638 | PC: 0x16d8c4 | FDE: 0x1ef7f0 | Size: 148 bytes
// Khung tháo gỡ #3638 | Địa chỉ PC: 0x16d8c4 | Địa chỉ FDE: 0x1ef7f0 | Kích thước: 148 bytes
//   0x16d8c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16d8c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16d8cc: 910043FD  add      x29, sp, #0x10
//   0x16d8d0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3638_0x16d8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d8c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef7f0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3639 | PC: 0x16d958 | FDE: 0x1ef810 | Size: 256 bytes
// Khung tháo gỡ #3639 | Địa chỉ PC: 0x16d958 | Địa chỉ FDE: 0x1ef810 | Kích thước: 256 bytes
//   0x16d958: D10103FF  sub      sp, sp, #0x40
//   0x16d95c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x16d960: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16d964: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3639_0x16d958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d958ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ef810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3640 | PC: 0x16da88 | FDE: 0x1ef838 | Size: 256 bytes
// Khung tháo gỡ #3640 | Địa chỉ PC: 0x16da88 | Địa chỉ FDE: 0x1ef838 | Kích thước: 256 bytes
//   0x16da88: D101C3FF  sub      sp, sp, #0x70
//   0x16da8c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x16da90: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x16da94: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3640_0x16da88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16da88ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1ef838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3641 | PC: 0x16dd2c | FDE: 0x1ef868 | Size: 256 bytes
// Khung tháo gỡ #3641 | Địa chỉ PC: 0x16dd2c | Địa chỉ FDE: 0x1ef868 | Kích thước: 256 bytes
//   0x16dd2c: D10143FF  sub      sp, sp, #0x50
//   0x16dd30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x16dd34: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x16dd38: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3641_0x16dd2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16dd2cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ef868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3642 | PC: 0x16de98 | FDE: 0x1ef890 | Size: 12 bytes [PyInit__random]
// Khung tháo gỡ #3642 | Địa chỉ PC: 0x16de98 | Địa chỉ FDE: 0x1ef890 | Kích thước: 12 bytes
//   0x16de98: B0000580  adrp     x0, #0x21e000
//   0x16de9c: 91062000  add      x0, x0, #0x188
//   0x16dea0: 17FBAAE0  b        #0x58a20
static inline uint64_t fde_func_3642_0x16de98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16de98ULL ^ (static_cast<uint64_t>(0xb0000580ULL) << 13);
    acc = (acc + a1 + 0x91062000ULL) ^ 0x1ef890ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3643 | PC: 0x16dea4 | FDE: 0x1ef8a8 | Size: 56 bytes
// Khung tháo gỡ #3643 | Địa chỉ PC: 0x16dea4 | Địa chỉ FDE: 0x1ef8a8 | Kích thước: 56 bytes
//   0x16dea4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16dea8: 910003FD  mov      x29, sp
//   0x16deac: F9401008  ldr      x8, [x0, #0x20]
//   0x16deb0: F9400100  ldr      x0, [x8]
static inline uint64_t fde_func_3643_0x16dea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16dea4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ef8a8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #3644 | PC: 0x16dedc | FDE: 0x1ef8c8 | Size: 116 bytes
// Khung tháo gỡ #3644 | Địa chỉ PC: 0x16dedc | Địa chỉ FDE: 0x1ef8c8 | Kích thước: 116 bytes
//   0x16dedc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16dee0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16dee4: 910043FD  add      x29, sp, #0x10
//   0x16dee8: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_3644_0x16dedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16dedcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef8c8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3645 | PC: 0x16df50 | FDE: 0x1ef8e8 | Size: 116 bytes
// Khung tháo gỡ #3645 | Địa chỉ PC: 0x16df50 | Địa chỉ FDE: 0x1ef8e8 | Kích thước: 116 bytes
//   0x16df50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16df54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16df58: 910043FD  add      x29, sp, #0x10
//   0x16df5c: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_3645_0x16df50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16df50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef8e8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3646 | PC: 0x16dfc4 | FDE: 0x1ef908 | Size: 200 bytes
// Khung tháo gỡ #3646 | Địa chỉ PC: 0x16dfc4 | Địa chỉ FDE: 0x1ef908 | Kích thước: 200 bytes
//   0x16dfc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16dfc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16dfcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16dfd0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3646_0x16dfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16dfc4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef908ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #3647 | PC: 0x16e08c | FDE: 0x1ef928 | Size: 244 bytes
// Khung tháo gỡ #3647 | Địa chỉ PC: 0x16e08c | Địa chỉ FDE: 0x1ef928 | Kích thước: 244 bytes
//   0x16e08c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16e090: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16e094: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16e098: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3647_0x16e08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e08cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef928ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #3648 | PC: 0x16e180 | FDE: 0x1ef948 | Size: 84 bytes
// Khung tháo gỡ #3648 | Địa chỉ PC: 0x16e180 | Địa chỉ FDE: 0x1ef948 | Kích thước: 84 bytes
//   0x16e180: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16e184: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16e188: 910043FD  add      x29, sp, #0x10
//   0x16e18c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3648_0x16e180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e180ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ef948ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3649 | PC: 0x16e1d4 | FDE: 0x1ef968 | Size: 128 bytes
// Khung tháo gỡ #3649 | Địa chỉ PC: 0x16e1d4 | Địa chỉ FDE: 0x1ef968 | Kích thước: 128 bytes
//   0x16e1d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16e1d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16e1dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16e1e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3649_0x16e1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e1d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef968ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3650 | PC: 0x16e254 | FDE: 0x1ef988 | Size: 144 bytes
// Khung tháo gỡ #3650 | Địa chỉ PC: 0x16e254 | Địa chỉ FDE: 0x1ef988 | Kích thước: 144 bytes
//   0x16e254: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x16e258: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16e25c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16e260: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3650_0x16e254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e254ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ef988ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3651 | PC: 0x16e2e4 | FDE: 0x1ef9b0 | Size: 256 bytes
// Khung tháo gỡ #3651 | Địa chỉ PC: 0x16e2e4 | Địa chỉ FDE: 0x1ef9b0 | Kích thước: 256 bytes
//   0x16e2e4: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x16e2e8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x16e2ec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x16e2f0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3651_0x16e2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e2e4ULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ef9b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3652 | PC: 0x16e430 | FDE: 0x1ef9d8 | Size: 256 bytes
// Khung tháo gỡ #3652 | Địa chỉ PC: 0x16e430 | Địa chỉ FDE: 0x1ef9d8 | Kích thước: 256 bytes
//   0x16e430: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x16e434: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x16e438: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x16e43c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3652_0x16e430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e430ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ef9d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3653 | PC: 0x16e5a0 | FDE: 0x1efa08 | Size: 256 bytes
// Khung tháo gỡ #3653 | Địa chỉ PC: 0x16e5a0 | Địa chỉ FDE: 0x1efa08 | Kích thước: 256 bytes
//   0x16e5a0: B9401009  ldr      w9, [x0, #0x10]
//   0x16e5a4: 7109C13F  cmp      w9, #0x270
//   0x16e5a8: 5400060B  b.lt     #0x16e668
//   0x16e5ac: B940140A  ldr      w10, [x0, #0x14]
static inline uint64_t fde_func_3653_0x16e5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e5a0ULL ^ (static_cast<uint64_t>(0xb9401009ULL) << 13);
    acc = (acc + a1 + 0x7109c13fULL) ^ 0x1efa08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3654 | PC: 0x16e6a0 | FDE: 0x1efa20 | Size: 256 bytes
// Khung tháo gỡ #3654 | Địa chỉ PC: 0x16e6a0 | Địa chỉ FDE: 0x1efa20 | Kích thước: 256 bytes
//   0x16e6a0: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x16e6a4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x16e6a8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x16e6ac: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3654_0x16e6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e6a0ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1efa20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3655 | PC: 0x16e920 | FDE: 0x1efa50 | Size: 256 bytes
// Khung tháo gỡ #3655 | Địa chỉ PC: 0x16e920 | Địa chỉ FDE: 0x1efa50 | Kích thước: 256 bytes
//   0x16e920: 529AD548  mov      w8, #0xd6aa
//   0x16e924: 52912CAB  mov      w11, #0x8965
//   0x16e928: 72A02568  movk     w8, #0x12b, lsl #16
//   0x16e92c: 52800029  mov      w9, #1
static inline uint64_t fde_func_3655_0x16e920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e920ULL ^ (static_cast<uint64_t>(0x529ad548ULL) << 13);
    acc = (acc + a1 + 0x52912cabULL) ^ 0x1efa50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3656 | PC: 0x16ea38 | FDE: 0x1efa68 | Size: 64 bytes [unpackiter_new]
// Khung tháo gỡ #3656 | Địa chỉ PC: 0x16ea38 | Địa chỉ FDE: 0x1efa68 | Kích thước: 64 bytes
//   0x16ea38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16ea3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16ea40: 910043FD  add      x29, sp, #0x10
//   0x16ea44: B0000488  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3656_0x16ea38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ea38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1efa68ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3657 | PC: 0x16ea78 | FDE: 0x1efa88 | Size: 12 bytes [PyInit__struct]
// Khung tháo gỡ #3657 | Địa chỉ PC: 0x16ea78 | Địa chỉ FDE: 0x1efa88 | Kích thước: 12 bytes
//   0x16ea78: 90000580  adrp     x0, #0x21e000
//   0x16ea7c: 910D0000  add      x0, x0, #0x340
//   0x16ea80: 17FBA7E8  b        #0x58a20
static inline uint64_t fde_func_3657_0x16ea78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ea78ULL ^ (static_cast<uint64_t>(0x90000580ULL) << 13);
    acc = (acc + a1 + 0x910d0000ULL) ^ 0x1efa88ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3658 | PC: 0x16ea84 | FDE: 0x1efaa0 | Size: 132 bytes
// Khung tháo gỡ #3658 | Địa chỉ PC: 0x16ea84 | Địa chỉ FDE: 0x1efaa0 | Kích thước: 132 bytes
//   0x16ea84: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16ea88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16ea8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16ea90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3658_0x16ea84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ea84ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efaa0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #3659 | PC: 0x16eb08 | FDE: 0x1efac0 | Size: 164 bytes
// Khung tháo gỡ #3659 | Địa chỉ PC: 0x16eb08 | Địa chỉ FDE: 0x1efac0 | Kích thước: 164 bytes
//   0x16eb08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16eb0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16eb10: 910043FD  add      x29, sp, #0x10
//   0x16eb14: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3659_0x16eb08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16eb08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1efac0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #3660 | PC: 0x16ebac | FDE: 0x1efae0 | Size: 4 bytes
// Khung tháo gỡ #3660 | Địa chỉ PC: 0x16ebac | Địa chỉ FDE: 0x1efae0 | Kích thước: 4 bytes
//   0x16ebac: 17FFFFD7  b        #0x16eb08
static inline uint64_t fde_func_3660_0x16ebac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ebacULL ^ (static_cast<uint64_t>(0x17ffffd7ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1efae0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3661 | PC: 0x16ebb0 | FDE: 0x1efaf8 | Size: 72 bytes
// Khung tháo gỡ #3661 | Địa chỉ PC: 0x16ebb0 | Địa chỉ FDE: 0x1efaf8 | Kích thước: 72 bytes
//   0x16ebb0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x16ebb4: 910003FD  mov      x29, sp
//   0x16ebb8: F9401008  ldr      x8, [x0, #0x20]
//   0x16ebbc: F9400100  ldr      x0, [x8]
static inline uint64_t fde_func_3661_0x16ebb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ebb0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1efaf8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3662 | PC: 0x16ebf8 | FDE: 0x1efb18 | Size: 144 bytes
// Khung tháo gỡ #3662 | Địa chỉ PC: 0x16ebf8 | Địa chỉ FDE: 0x1efb18 | Kích thước: 144 bytes
//   0x16ebf8: D100C3FF  sub      sp, sp, #0x30
//   0x16ebfc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16ec00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16ec04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3662_0x16ebf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ebf8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efb18ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3663 | PC: 0x16ec88 | FDE: 0x1efb38 | Size: 180 bytes
// Khung tháo gỡ #3663 | Địa chỉ PC: 0x16ec88 | Địa chỉ FDE: 0x1efb38 | Kích thước: 180 bytes
//   0x16ec88: D100C3FF  sub      sp, sp, #0x30
//   0x16ec8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16ec90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16ec94: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3663_0x16ec88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ec88ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efb38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3664 | PC: 0x16ed3c | FDE: 0x1efb58 | Size: 152 bytes
// Khung tháo gỡ #3664 | Địa chỉ PC: 0x16ed3c | Địa chỉ FDE: 0x1efb58 | Kích thước: 152 bytes
//   0x16ed3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16ed40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16ed44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16ed48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3664_0x16ed3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ed3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efb58ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3665 | PC: 0x16edd4 | FDE: 0x1efb78 | Size: 152 bytes
// Khung tháo gỡ #3665 | Địa chỉ PC: 0x16edd4 | Địa chỉ FDE: 0x1efb78 | Kích thước: 152 bytes
//   0x16edd4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16edd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16eddc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16ede0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3665_0x16edd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16edd4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efb78ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3666 | PC: 0x16ee6c | FDE: 0x1efb98 | Size: 256 bytes
// Khung tháo gỡ #3666 | Địa chỉ PC: 0x16ee6c | Địa chỉ FDE: 0x1efb98 | Kích thước: 256 bytes
//   0x16ee6c: D10283FF  sub      sp, sp, #0xa0
//   0x16ee70: F9003BF5  str      x21, [sp, #0x70]
//   0x16ee74: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x16ee78: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3666_0x16ee6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ee6cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1efb98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3667 | PC: 0x16efe4 | FDE: 0x1efbb8 | Size: 256 bytes
// Khung tháo gỡ #3667 | Địa chỉ PC: 0x16efe4 | Địa chỉ FDE: 0x1efbb8 | Kích thước: 256 bytes
//   0x16efe4: D10303FF  sub      sp, sp, #0xc0
//   0x16efe8: F90043F7  str      x23, [sp, #0x80]
//   0x16efec: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x16eff0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3667_0x16efe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16efe4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1efbb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3668 | PC: 0x16f1c4 | FDE: 0x1efbe0 | Size: 256 bytes
// Khung tháo gỡ #3668 | Địa chỉ PC: 0x16f1c4 | Địa chỉ FDE: 0x1efbe0 | Kích thước: 256 bytes
//   0x16f1c4: D101C3FF  sub      sp, sp, #0x70
//   0x16f1c8: F90013F9  str      x25, [sp, #0x20]
//   0x16f1cc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x16f1d0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3668_0x16f1c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f1c4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1efbe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3669 | PC: 0x16f350 | FDE: 0x1efc08 | Size: 236 bytes
// Khung tháo gỡ #3669 | Địa chỉ PC: 0x16f350 | Địa chỉ FDE: 0x1efc08 | Kích thước: 236 bytes
//   0x16f350: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x16f354: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x16f358: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16f35c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3669_0x16f350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f350ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1efc08ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3670 | PC: 0x16f43c | FDE: 0x1efc30 | Size: 236 bytes
// Khung tháo gỡ #3670 | Địa chỉ PC: 0x16f43c | Địa chỉ FDE: 0x1efc30 | Kích thước: 236 bytes
//   0x16f43c: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x16f440: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x16f444: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x16f448: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3670_0x16f43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f43cULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1efc30ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3671 | PC: 0x16f528 | FDE: 0x1efc58 | Size: 256 bytes
// Khung tháo gỡ #3671 | Địa chỉ PC: 0x16f528 | Địa chỉ FDE: 0x1efc58 | Kích thước: 256 bytes
//   0x16f528: D101C3FF  sub      sp, sp, #0x70
//   0x16f52c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x16f530: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x16f534: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3671_0x16f528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f528ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1efc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3672 | PC: 0x16f750 | FDE: 0x1efc88 | Size: 256 bytes
// Khung tháo gỡ #3672 | Địa chỉ PC: 0x16f750 | Địa chỉ FDE: 0x1efc88 | Kích thước: 256 bytes
//   0x16f750: D10283FF  sub      sp, sp, #0xa0
//   0x16f754: F90033F7  str      x23, [sp, #0x60]
//   0x16f758: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x16f75c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_3672_0x16f750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f750ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1efc88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3673 | PC: 0x16f92c | FDE: 0x1efcb0 | Size: 256 bytes
// Khung tháo gỡ #3673 | Địa chỉ PC: 0x16f92c | Địa chỉ FDE: 0x1efcb0 | Kích thước: 256 bytes
//   0x16f92c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x16f930: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x16f934: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x16f938: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3673_0x16f92c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f92cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1efcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3674 | PC: 0x16fa54 | FDE: 0x1efce0 | Size: 232 bytes
// Khung tháo gỡ #3674 | Địa chỉ PC: 0x16fa54 | Địa chỉ FDE: 0x1efce0 | Kích thước: 232 bytes
//   0x16fa54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x16fa58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x16fa5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x16fa60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3674_0x16fa54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fa54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efce0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3675 | PC: 0x16fb3c | FDE: 0x1efd00 | Size: 256 bytes
// Khung tháo gỡ #3675 | Địa chỉ PC: 0x16fb3c | Địa chỉ FDE: 0x1efd00 | Kích thước: 256 bytes
//   0x16fb3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16fb40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16fb44: 910043FD  add      x29, sp, #0x10
//   0x16fb48: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_3675_0x16fb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fb3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1efd00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3676 | PC: 0x16fc90 | FDE: 0x1efd20 | Size: 144 bytes
// Khung tháo gỡ #3676 | Địa chỉ PC: 0x16fc90 | Địa chỉ FDE: 0x1efd20 | Kích thước: 144 bytes
//   0x16fc90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x16fc94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16fc98: 910043FD  add      x29, sp, #0x10
//   0x16fc9c: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_3676_0x16fc90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fc90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1efd20ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3677 | PC: 0x16fd20 | FDE: 0x1efd40 | Size: 256 bytes
// Khung tháo gỡ #3677 | Địa chỉ PC: 0x16fd20 | Địa chỉ FDE: 0x1efd40 | Kích thước: 256 bytes
//   0x16fd20: D10203FF  sub      sp, sp, #0x80
//   0x16fd24: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x16fd28: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x16fd2c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3677_0x16fd20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fd20ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1efd40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3678 | PC: 0x170204 | FDE: 0x1efd70 | Size: 88 bytes
// Khung tháo gỡ #3678 | Địa chỉ PC: 0x170204 | Địa chỉ FDE: 0x1efd70 | Kích thước: 88 bytes
//   0x170204: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x170208: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17020c: 910043FD  add      x29, sp, #0x10
//   0x170210: 528005E1  mov      w1, #0x2f
static inline uint64_t fde_func_3678_0x170204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170204ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1efd70ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3679 | PC: 0x17025c | FDE: 0x1efd90 | Size: 256 bytes
// Khung tháo gỡ #3679 | Địa chỉ PC: 0x17025c | Địa chỉ FDE: 0x1efd90 | Kích thước: 256 bytes
//   0x17025c: D10243FF  sub      sp, sp, #0x90
//   0x170260: F90033F5  str      x21, [sp, #0x60]
//   0x170264: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x170268: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_3679_0x17025c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17025cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1efd90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3680 | PC: 0x170374 | FDE: 0x1efdb0 | Size: 256 bytes
// Khung tháo gỡ #3680 | Địa chỉ PC: 0x170374 | Địa chỉ FDE: 0x1efdb0 | Kích thước: 256 bytes
//   0x170374: D10303FF  sub      sp, sp, #0xc0
//   0x170378: F90043F7  str      x23, [sp, #0x80]
//   0x17037c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x170380: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3680_0x170374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170374ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1efdb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3681 | PC: 0x170510 | FDE: 0x1efdd8 | Size: 32 bytes
// Khung tháo gỡ #3681 | Địa chỉ PC: 0x170510 | Địa chỉ FDE: 0x1efdd8 | Kích thước: 32 bytes
//   0x170510: F9400409  ldr      x9, [x0, #8]
//   0x170514: AA0003E8  mov      x8, x0
//   0x170518: F9401108  ldr      x8, [x8, #0x20]
//   0x17051c: F9401120  ldr      x0, [x9, #0x20]
static inline uint64_t fde_func_3681_0x170510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170510ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1efdd8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3682 | PC: 0x170530 | FDE: 0x1efdf0 | Size: 16 bytes
// Khung tháo gỡ #3682 | Địa chỉ PC: 0x170530 | Địa chỉ FDE: 0x1efdf0 | Kích thước: 16 bytes
//   0x170530: F9401408  ldr      x8, [x0, #0x28]
//   0x170534: F9400901  ldr      x1, [x8, #0x10]
//   0x170538: 91008100  add      x0, x8, #0x20
//   0x17053c: 17FBB225  b        #0x5cdd0
static inline uint64_t fde_func_3682_0x170530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170530ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400901ULL) ^ 0x1efdf0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3683 | PC: 0x170540 | FDE: 0x1efe08 | Size: 8 bytes
// Khung tháo gỡ #3683 | Địa chỉ PC: 0x170540 | Địa chỉ FDE: 0x1efe08 | Kích thước: 8 bytes
//   0x170540: F9400800  ldr      x0, [x0, #0x10]
//   0x170544: 17FBA84F  b        #0x5a680
static inline uint64_t fde_func_3683_0x170540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170540ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17fba84fULL) ^ 0x1efe08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3684 | PC: 0x170548 | FDE: 0x1efe20 | Size: 8 bytes
// Khung tháo gỡ #3684 | Địa chỉ PC: 0x170548 | Địa chỉ FDE: 0x1efe20 | Kích thước: 8 bytes
//   0x170548: 39800020  ldrsb    x0, [x1]
//   0x17054c: 17FBA889  b        #0x5a770
static inline uint64_t fde_func_3684_0x170548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170548ULL ^ (static_cast<uint64_t>(0x39800020ULL) << 13);
    acc = (acc + a1 + 0x17fba889ULL) ^ 0x1efe20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3685 | PC: 0x170550 | FDE: 0x1efe38 | Size: 252 bytes
// Khung tháo gỡ #3685 | Địa chỉ PC: 0x170550 | Địa chỉ FDE: 0x1efe38 | Kích thước: 252 bytes
//   0x170550: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x170554: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170558: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17055c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3685_0x170550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170550ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efe38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #3686 | PC: 0x17064c | FDE: 0x1efe60 | Size: 8 bytes
// Khung tháo gỡ #3686 | Địa chỉ PC: 0x17064c | Địa chỉ FDE: 0x1efe60 | Kích thước: 8 bytes
//   0x17064c: 39400020  ldrb     w0, [x1]
//   0x170650: 17FBA848  b        #0x5a770
static inline uint64_t fde_func_3686_0x17064c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17064cULL ^ (static_cast<uint64_t>(0x39400020ULL) << 13);
    acc = (acc + a1 + 0x17fba848ULL) ^ 0x1efe60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3687 | PC: 0x170654 | FDE: 0x1efe78 | Size: 252 bytes
// Khung tháo gỡ #3687 | Địa chỉ PC: 0x170654 | Địa chỉ FDE: 0x1efe78 | Kích thước: 252 bytes
//   0x170654: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x170658: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17065c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170660: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3687_0x170654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170654ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efe78ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #3688 | PC: 0x170750 | FDE: 0x1efea0 | Size: 12 bytes
// Khung tháo gỡ #3688 | Địa chỉ PC: 0x170750 | Địa chỉ FDE: 0x1efea0 | Kích thước: 12 bytes
//   0x170750: AA0103E0  mov      x0, x1
//   0x170754: 52800021  mov      w1, #1
//   0x170758: 17FBA272  b        #0x59120
static inline uint64_t fde_func_3688_0x170750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170750ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x52800021ULL) ^ 0x1efea0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3689 | PC: 0x17075c | FDE: 0x1efeb8 | Size: 108 bytes
// Khung tháo gỡ #3689 | Địa chỉ PC: 0x17075c | Địa chỉ FDE: 0x1efeb8 | Kích thước: 108 bytes
//   0x17075c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x170760: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170764: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170768: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3689_0x17075c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17075cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1efeb8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3690 | PC: 0x1707c8 | FDE: 0x1efed8 | Size: 76 bytes
// Khung tháo gỡ #3690 | Địa chỉ PC: 0x1707c8 | Địa chỉ FDE: 0x1efed8 | Kích thước: 76 bytes
//   0x1707c8: F9400448  ldr      x8, [x2, #8]
//   0x1707cc: AA1F03E0  mov      x0, xzr
//   0x1707d0: AA0803E9  mov      x9, x8
//   0x1707d4: AA0003EA  mov      x10, x0
static inline uint64_t fde_func_3690_0x1707c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1707c8ULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1efed8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3691 | PC: 0x170814 | FDE: 0x1efef0 | Size: 256 bytes
// Khung tháo gỡ #3691 | Địa chỉ PC: 0x170814 | Địa chỉ FDE: 0x1efef0 | Kích thước: 256 bytes
//   0x170814: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x170818: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17081c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x170820: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3691_0x170814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170814ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1efef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3692 | PC: 0x170984 | FDE: 0x1eff18 | Size: 36 bytes
// Khung tháo gỡ #3692 | Địa chỉ PC: 0x170984 | Địa chỉ FDE: 0x1eff18 | Kích thước: 36 bytes
//   0x170984: F9400448  ldr      x8, [x2, #8]
//   0x170988: AA1F03E0  mov      x0, xzr
//   0x17098c: 38401429  ldrb     w9, [x1], #1
//   0x170990: D1000508  sub      x8, x8, #1
static inline uint64_t fde_func_3692_0x170984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170984ULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1eff18ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3693 | PC: 0x1709a8 | FDE: 0x1eff30 | Size: 256 bytes
// Khung tháo gỡ #3693 | Địa chỉ PC: 0x1709a8 | Địa chỉ FDE: 0x1eff30 | Kích thước: 256 bytes
//   0x1709a8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1709ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1709b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1709b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3693_0x1709a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1709a8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eff30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3694 | PC: 0x170ae8 | FDE: 0x1eff58 | Size: 76 bytes
// Khung tháo gỡ #3694 | Địa chỉ PC: 0x170ae8 | Địa chỉ FDE: 0x1eff58 | Kích thước: 76 bytes
//   0x170ae8: F9400448  ldr      x8, [x2, #8]
//   0x170aec: AA1F03E0  mov      x0, xzr
//   0x170af0: AA0803E9  mov      x9, x8
//   0x170af4: AA0003EA  mov      x10, x0
static inline uint64_t fde_func_3694_0x170ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170ae8ULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1eff58ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3695 | PC: 0x170b34 | FDE: 0x1eff70 | Size: 180 bytes
// Khung tháo gỡ #3695 | Địa chỉ PC: 0x170b34 | Địa chỉ FDE: 0x1eff70 | Kích thước: 180 bytes
//   0x170b34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x170b38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170b3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170b40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3695_0x170b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170b34ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eff70ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3696 | PC: 0x170be8 | FDE: 0x1eff90 | Size: 36 bytes
// Khung tháo gỡ #3696 | Địa chỉ PC: 0x170be8 | Địa chỉ FDE: 0x1eff90 | Kích thước: 36 bytes
//   0x170be8: F9400448  ldr      x8, [x2, #8]
//   0x170bec: AA1F03E0  mov      x0, xzr
//   0x170bf0: 38401429  ldrb     w9, [x1], #1
//   0x170bf4: D1000508  sub      x8, x8, #1
static inline uint64_t fde_func_3696_0x170be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170be8ULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1eff90ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #3697 | PC: 0x170c0c | FDE: 0x1effa8 | Size: 180 bytes
// Khung tháo gỡ #3697 | Địa chỉ PC: 0x170c0c | Địa chỉ FDE: 0x1effa8 | Kích thước: 180 bytes
//   0x170c0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x170c10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170c14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170c18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3697_0x170c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170c0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1effa8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3698 | PC: 0x170cc0 | FDE: 0x1effc8 | Size: 16 bytes
// Khung tháo gỡ #3698 | Địa chỉ PC: 0x170cc0 | Địa chỉ FDE: 0x1effc8 | Kích thước: 16 bytes
//   0x170cc0: 39400028  ldrb     w8, [x1]
//   0x170cc4: 7100011F  cmp      w8, #0
//   0x170cc8: 1A9F07E0  cset     w0, ne
//   0x170ccc: 17FBA755  b        #0x5aa20
static inline uint64_t fde_func_3698_0x170cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170cc0ULL ^ (static_cast<uint64_t>(0x39400028ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x1effc8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3699 | PC: 0x170cd0 | FDE: 0x1effe0 | Size: 60 bytes
// Khung tháo gỡ #3699 | Địa chỉ PC: 0x170cd0 | Địa chỉ FDE: 0x1effe0 | Kích thước: 60 bytes
//   0x170cd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x170cd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170cd8: 910043FD  add      x29, sp, #0x10
//   0x170cdc: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_3699_0x170cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170cd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1effe0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3700 | PC: 0x170d0c | FDE: 0x1f0000 | Size: 80 bytes
// Khung tháo gỡ #3700 | Địa chỉ PC: 0x170d0c | Địa chỉ FDE: 0x1f0000 | Kích thước: 80 bytes
//   0x170d0c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x170d10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170d14: 910043FD  add      x29, sp, #0x10
//   0x170d18: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3700_0x170d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170d0cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0000ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3701 | PC: 0x170d5c | FDE: 0x1f0020 | Size: 120 bytes
// Khung tháo gỡ #3701 | Địa chỉ PC: 0x170d5c | Địa chỉ FDE: 0x1f0020 | Kích thước: 120 bytes
//   0x170d5c: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x170d60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170d64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170d68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3701_0x170d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170d5cULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0020ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3702 | PC: 0x170dd4 | FDE: 0x1f0040 | Size: 80 bytes
// Khung tháo gỡ #3702 | Địa chỉ PC: 0x170dd4 | Địa chỉ FDE: 0x1f0040 | Kích thước: 80 bytes
//   0x170dd4: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x170dd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170ddc: 910043FD  add      x29, sp, #0x10
//   0x170de0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3702_0x170dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170dd4ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0040ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3703 | PC: 0x170e24 | FDE: 0x1f0060 | Size: 120 bytes
// Khung tháo gỡ #3703 | Địa chỉ PC: 0x170e24 | Địa chỉ FDE: 0x1f0060 | Kích thước: 120 bytes
//   0x170e24: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x170e28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170e2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170e30: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3703_0x170e24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170e24ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0060ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3704 | PC: 0x170e9c | FDE: 0x1f0080 | Size: 80 bytes
// Khung tháo gỡ #3704 | Địa chỉ PC: 0x170e9c | Địa chỉ FDE: 0x1f0080 | Kích thước: 80 bytes
//   0x170e9c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x170ea0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170ea4: 910043FD  add      x29, sp, #0x10
//   0x170ea8: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3704_0x170e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170e9cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0080ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3705 | PC: 0x170eec | FDE: 0x1f00a0 | Size: 120 bytes
// Khung tháo gỡ #3705 | Địa chỉ PC: 0x170eec | Địa chỉ FDE: 0x1f00a0 | Kích thước: 120 bytes
//   0x170eec: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x170ef0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170ef4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170ef8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3705_0x170eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170eecULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f00a0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3706 | PC: 0x170f64 | FDE: 0x1f00c0 | Size: 112 bytes
// Khung tháo gỡ #3706 | Địa chỉ PC: 0x170f64 | Địa chỉ FDE: 0x1f00c0 | Kích thước: 112 bytes
//   0x170f64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x170f68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170f6c: 910043FD  add      x29, sp, #0x10
//   0x170f70: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_3706_0x170f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170f64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f00c0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3707 | PC: 0x170fd4 | FDE: 0x1f00e0 | Size: 108 bytes
// Khung tháo gỡ #3707 | Địa chỉ PC: 0x170fd4 | Địa chỉ FDE: 0x1f00e0 | Kích thước: 108 bytes
//   0x170fd4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x170fd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x170fdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x170fe0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3707_0x170fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170fd4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f00e0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3708 | PC: 0x171040 | FDE: 0x1f0100 | Size: 148 bytes
// Khung tháo gỡ #3708 | Địa chỉ PC: 0x171040 | Địa chỉ FDE: 0x1f0100 | Kích thước: 148 bytes
//   0x171040: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x171044: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x171048: 910043FD  add      x29, sp, #0x10
//   0x17104c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3708_0x171040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171040ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0100ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3709 | PC: 0x1710d4 | FDE: 0x1f0120 | Size: 40 bytes
// Khung tháo gỡ #3709 | Địa chỉ PC: 0x1710d4 | Địa chỉ FDE: 0x1f0120 | Kích thước: 40 bytes
//   0x1710d4: F9400808  ldr      x8, [x0, #0x10]
//   0x1710d8: B40000E8  cbz      x8, #0x1710f4
//   0x1710dc: F9401409  ldr      x9, [x0, #0x28]
//   0x1710e0: F940340A  ldr      x10, [x0, #0x68]
static inline uint64_t fde_func_3709_0x1710d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1710d4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb40000e8ULL) ^ 0x1f0120ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3710 | PC: 0x1710fc | FDE: 0x1f0138 | Size: 8 bytes
// Khung tháo gỡ #3710 | Địa chỉ PC: 0x1710fc | Địa chỉ FDE: 0x1f0138 | Kích thước: 8 bytes
//   0x1710fc: 79800020  ldrsh    x0, [x1]
//   0x171100: 17FBA59C  b        #0x5a770
static inline uint64_t fde_func_3710_0x1710fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1710fcULL ^ (static_cast<uint64_t>(0x79800020ULL) << 13);
    acc = (acc + a1 + 0x17fba59cULL) ^ 0x1f0138ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3711 | PC: 0x171104 | FDE: 0x1f0150 | Size: 256 bytes
// Khung tháo gỡ #3711 | Địa chỉ PC: 0x171104 | Địa chỉ FDE: 0x1f0150 | Kích thước: 256 bytes
//   0x171104: D10103FF  sub      sp, sp, #0x40
//   0x171108: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17110c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171110: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3711_0x171104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171104ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3712 | PC: 0x17120c | FDE: 0x1f0178 | Size: 8 bytes
// Khung tháo gỡ #3712 | Địa chỉ PC: 0x17120c | Địa chỉ FDE: 0x1f0178 | Kích thước: 8 bytes
//   0x17120c: 79400020  ldrh     w0, [x1]
//   0x171210: 17FBA558  b        #0x5a770
static inline uint64_t fde_func_3712_0x17120c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17120cULL ^ (static_cast<uint64_t>(0x79400020ULL) << 13);
    acc = (acc + a1 + 0x17fba558ULL) ^ 0x1f0178ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3713 | PC: 0x171214 | FDE: 0x1f0190 | Size: 256 bytes
// Khung tháo gỡ #3713 | Địa chỉ PC: 0x171214 | Địa chỉ FDE: 0x1f0190 | Kích thước: 256 bytes
//   0x171214: D10103FF  sub      sp, sp, #0x40
//   0x171218: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17121c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171220: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3713_0x171214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171214ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3714 | PC: 0x17131c | FDE: 0x1f01b8 | Size: 8 bytes
// Khung tháo gỡ #3714 | Địa chỉ PC: 0x17131c | Địa chỉ FDE: 0x1f01b8 | Kích thước: 8 bytes
//   0x17131c: B9800020  ldrsw    x0, [x1]
//   0x171320: 17FBA514  b        #0x5a770
static inline uint64_t fde_func_3714_0x17131c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17131cULL ^ (static_cast<uint64_t>(0xb9800020ULL) << 13);
    acc = (acc + a1 + 0x17fba514ULL) ^ 0x1f01b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3715 | PC: 0x171324 | FDE: 0x1f01d0 | Size: 256 bytes
// Khung tháo gỡ #3715 | Địa chỉ PC: 0x171324 | Địa chỉ FDE: 0x1f01d0 | Kích thước: 256 bytes
//   0x171324: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x171328: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17132c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171330: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3715_0x171324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171324ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f01d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3716 | PC: 0x171454 | FDE: 0x1f01f8 | Size: 8 bytes
// Khung tháo gỡ #3716 | Địa chỉ PC: 0x171454 | Địa chỉ FDE: 0x1f01f8 | Kích thước: 8 bytes
//   0x171454: B9400020  ldr      w0, [x1]
//   0x171458: 17FBAB2E  b        #0x5c110
static inline uint64_t fde_func_3716_0x171454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171454ULL ^ (static_cast<uint64_t>(0xb9400020ULL) << 13);
    acc = (acc + a1 + 0x17fbab2eULL) ^ 0x1f01f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3717 | PC: 0x17145c | FDE: 0x1f0210 | Size: 256 bytes
// Khung tháo gỡ #3717 | Địa chỉ PC: 0x17145c | Địa chỉ FDE: 0x1f0210 | Kích thước: 256 bytes
//   0x17145c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x171460: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x171464: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171468: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3717_0x17145c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17145cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3718 | PC: 0x17158c | FDE: 0x1f0238 | Size: 8 bytes
// Khung tháo gỡ #3718 | Địa chỉ PC: 0x17158c | Địa chỉ FDE: 0x1f0238 | Kích thước: 8 bytes
//   0x17158c: F9400020  ldr      x0, [x1]
//   0x171590: 17FBA478  b        #0x5a770
static inline uint64_t fde_func_3718_0x17158c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17158cULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fba478ULL) ^ 0x1f0238ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3719 | PC: 0x171594 | FDE: 0x1f0250 | Size: 240 bytes
// Khung tháo gỡ #3719 | Địa chỉ PC: 0x171594 | Địa chỉ FDE: 0x1f0250 | Kích thước: 240 bytes
//   0x171594: D10103FF  sub      sp, sp, #0x40
//   0x171598: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17159c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1715a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3719_0x171594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171594ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0250ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3720 | PC: 0x171684 | FDE: 0x1f0278 | Size: 8 bytes
// Khung tháo gỡ #3720 | Địa chỉ PC: 0x171684 | Địa chỉ FDE: 0x1f0278 | Kích thước: 8 bytes
//   0x171684: F9400020  ldr      x0, [x1]
//   0x171688: 17FBAAA2  b        #0x5c110
static inline uint64_t fde_func_3720_0x171684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171684ULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fbaaa2ULL) ^ 0x1f0278ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3721 | PC: 0x17168c | FDE: 0x1f0290 | Size: 240 bytes
// Khung tháo gỡ #3721 | Địa chỉ PC: 0x17168c | Địa chỉ FDE: 0x1f0290 | Kích thước: 240 bytes
//   0x17168c: D10103FF  sub      sp, sp, #0x40
//   0x171690: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x171694: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171698: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3721_0x17168c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17168cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0290ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3722 | PC: 0x17177c | FDE: 0x1f02b8 | Size: 8 bytes
// Khung tháo gỡ #3722 | Địa chỉ PC: 0x17177c | Địa chỉ FDE: 0x1f02b8 | Kích thước: 8 bytes
//   0x17177c: F9400020  ldr      x0, [x1]
//   0x171780: 17FBA3C0  b        #0x5a680
static inline uint64_t fde_func_3722_0x17177c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17177cULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fba3c0ULL) ^ 0x1f02b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3723 | PC: 0x171784 | FDE: 0x1f02d0 | Size: 240 bytes
// Khung tháo gỡ #3723 | Địa chỉ PC: 0x171784 | Địa chỉ FDE: 0x1f02d0 | Kích thước: 240 bytes
//   0x171784: D10103FF  sub      sp, sp, #0x40
//   0x171788: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17178c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171790: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3723_0x171784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171784ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f02d0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3724 | PC: 0x171874 | FDE: 0x1f02f8 | Size: 8 bytes
// Khung tháo gỡ #3724 | Địa chỉ PC: 0x171874 | Địa chỉ FDE: 0x1f02f8 | Kích thước: 8 bytes
//   0x171874: F9400020  ldr      x0, [x1]
//   0x171878: 17FB9F72  b        #0x59640
static inline uint64_t fde_func_3724_0x171874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171874ULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fb9f72ULL) ^ 0x1f02f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3725 | PC: 0x17187c | FDE: 0x1f0310 | Size: 240 bytes
// Khung tháo gỡ #3725 | Địa chỉ PC: 0x17187c | Địa chỉ FDE: 0x1f0310 | Kích thước: 240 bytes
//   0x17187c: D10103FF  sub      sp, sp, #0x40
//   0x171880: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x171884: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171888: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3725_0x17187c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17187cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0310ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3726 | PC: 0x17196c | FDE: 0x1f0338 | Size: 8 bytes
// Khung tháo gỡ #3726 | Địa chỉ PC: 0x17196c | Địa chỉ FDE: 0x1f0338 | Kích thước: 8 bytes
//   0x17196c: F9400020  ldr      x0, [x1]
//   0x171970: 17FBAD6C  b        #0x5cf20
static inline uint64_t fde_func_3726_0x17196c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17196cULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fbad6cULL) ^ 0x1f0338ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3727 | PC: 0x171974 | FDE: 0x1f0350 | Size: 240 bytes
// Khung tháo gỡ #3727 | Địa chỉ PC: 0x171974 | Địa chỉ FDE: 0x1f0350 | Kích thước: 240 bytes
//   0x171974: D10103FF  sub      sp, sp, #0x40
//   0x171978: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17197c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171980: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3727_0x171974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171974ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0350ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3728 | PC: 0x171a64 | FDE: 0x1f0378 | Size: 8 bytes
// Khung tháo gỡ #3728 | Địa chỉ PC: 0x171a64 | Địa chỉ FDE: 0x1f0378 | Kích thước: 8 bytes
//   0x171a64: F9400020  ldr      x0, [x1]
//   0x171a68: 17FB9CBA  b        #0x58d50
static inline uint64_t fde_func_3728_0x171a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171a64ULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fb9cbaULL) ^ 0x1f0378ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3729 | PC: 0x171a6c | FDE: 0x1f0390 | Size: 240 bytes
// Khung tháo gỡ #3729 | Địa chỉ PC: 0x171a6c | Địa chỉ FDE: 0x1f0390 | Kích thước: 240 bytes
//   0x171a6c: D10103FF  sub      sp, sp, #0x40
//   0x171a70: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x171a74: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171a78: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3729_0x171a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171a6cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0390ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #3730 | PC: 0x171b5c | FDE: 0x1f03b8 | Size: 8 bytes
// Khung tháo gỡ #3730 | Địa chỉ PC: 0x171b5c | Địa chỉ FDE: 0x1f03b8 | Kích thước: 8 bytes
//   0x171b5c: 39400020  ldrb     w0, [x1]
//   0x171b60: 17FBA3B0  b        #0x5aa20
static inline uint64_t fde_func_3730_0x171b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171b5cULL ^ (static_cast<uint64_t>(0x39400020ULL) << 13);
    acc = (acc + a1 + 0x17fba3b0ULL) ^ 0x1f03b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3731 | PC: 0x171b64 | FDE: 0x1f03d0 | Size: 72 bytes
// Khung tháo gỡ #3731 | Địa chỉ PC: 0x171b64 | Địa chỉ FDE: 0x1f03d0 | Kích thước: 72 bytes
//   0x171b64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x171b68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x171b6c: 910043FD  add      x29, sp, #0x10
//   0x171b70: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_3731_0x171b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171b64ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f03d0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3732 | PC: 0x171bac | FDE: 0x1f03f0 | Size: 80 bytes
// Khung tháo gỡ #3732 | Địa chỉ PC: 0x171bac | Địa chỉ FDE: 0x1f03f0 | Kích thước: 80 bytes
//   0x171bac: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x171bb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x171bb4: 910043FD  add      x29, sp, #0x10
//   0x171bb8: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3732_0x171bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171bacULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f03f0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3733 | PC: 0x171bfc | FDE: 0x1f0410 | Size: 120 bytes
// Khung tháo gỡ #3733 | Địa chỉ PC: 0x171bfc | Địa chỉ FDE: 0x1f0410 | Kích thước: 120 bytes
//   0x171bfc: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x171c00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x171c04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x171c08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3733_0x171bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171bfcULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0410ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3734 | PC: 0x171c74 | FDE: 0x1f0430 | Size: 12 bytes
// Khung tháo gỡ #3734 | Địa chỉ PC: 0x171c74 | Địa chỉ FDE: 0x1f0430 | Kích thước: 12 bytes
//   0x171c74: BD400020  ldr      s0, [x1]
//   0x171c78: 1E22C000  fcvt     d0, s0
//   0x171c7c: 17FBA285  b        #0x5a690
static inline uint64_t fde_func_3734_0x171c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171c74ULL ^ (static_cast<uint64_t>(0xbd400020ULL) << 13);
    acc = (acc + a1 + 0x1e22c000ULL) ^ 0x1f0430ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3735 | PC: 0x171c80 | FDE: 0x1f0448 | Size: 108 bytes
// Khung tháo gỡ #3735 | Địa chỉ PC: 0x171c80 | Địa chỉ FDE: 0x1f0448 | Kích thước: 108 bytes
//   0x171c80: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x171c84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x171c88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x171c8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3735_0x171c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171c80ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0448ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3736 | PC: 0x171cec | FDE: 0x1f0468 | Size: 8 bytes
// Khung tháo gỡ #3736 | Địa chỉ PC: 0x171cec | Địa chỉ FDE: 0x1f0468 | Kích thước: 8 bytes
//   0x171cec: FD400020  ldr      d0, [x1]
//   0x171cf0: 17FBA268  b        #0x5a690
static inline uint64_t fde_func_3736_0x171cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171cecULL ^ (static_cast<uint64_t>(0xfd400020ULL) << 13);
    acc = (acc + a1 + 0x17fba268ULL) ^ 0x1f0468ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3737 | PC: 0x171cf4 | FDE: 0x1f0480 | Size: 108 bytes
// Khung tháo gỡ #3737 | Địa chỉ PC: 0x171cf4 | Địa chỉ FDE: 0x1f0480 | Kích thước: 108 bytes
//   0x171cf4: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x171cf8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x171cfc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x171d00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3737_0x171cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171cf4ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0480ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3738 | PC: 0x171d60 | FDE: 0x1f04a0 | Size: 8 bytes
// Khung tháo gỡ #3738 | Địa chỉ PC: 0x171d60 | Địa chỉ FDE: 0x1f04a0 | Kích thước: 8 bytes
//   0x171d60: F9400020  ldr      x0, [x1]
//   0x171d64: 17FBA2EB  b        #0x5a910
static inline uint64_t fde_func_3738_0x171d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171d60ULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x17fba2ebULL) ^ 0x1f04a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3739 | PC: 0x171d68 | FDE: 0x1f04b8 | Size: 196 bytes
// Khung tháo gỡ #3739 | Địa chỉ PC: 0x171d68 | Địa chỉ FDE: 0x1f04b8 | Kích thước: 196 bytes
//   0x171d68: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x171d6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x171d70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x171d74: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3739_0x171d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171d68ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f04b8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3740 | PC: 0x171e2c | FDE: 0x1f04d8 | Size: 80 bytes
// Khung tháo gỡ #3740 | Địa chỉ PC: 0x171e2c | Địa chỉ FDE: 0x1f04d8 | Kích thước: 80 bytes
//   0x171e2c: F9400448  ldr      x8, [x2, #8]
//   0x171e30: AA1F03E0  mov      x0, xzr
//   0x171e34: D1000429  sub      x9, x1, #1
//   0x171e38: AA0803EA  mov      x10, x8
static inline uint64_t fde_func_3740_0x171e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171e2cULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1f04d8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3741 | PC: 0x171e7c | FDE: 0x1f04f0 | Size: 256 bytes
// Khung tháo gỡ #3741 | Địa chỉ PC: 0x171e7c | Địa chỉ FDE: 0x1f04f0 | Kích thước: 256 bytes
//   0x171e7c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x171e80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x171e84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x171e88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3741_0x171e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171e7cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f04f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3742 | PC: 0x171fe8 | FDE: 0x1f0518 | Size: 40 bytes
// Khung tháo gỡ #3742 | Địa chỉ PC: 0x171fe8 | Địa chỉ FDE: 0x1f0518 | Kích thước: 40 bytes
//   0x171fe8: F9400449  ldr      x9, [x2, #8]
//   0x171fec: AA1F03E0  mov      x0, xzr
//   0x171ff0: D1000428  sub      x8, x1, #1
//   0x171ff4: 3869690A  ldrb     w10, [x8, x9]
static inline uint64_t fde_func_3742_0x171fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171fe8ULL ^ (static_cast<uint64_t>(0xf9400449ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1f0518ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3743 | PC: 0x172010 | FDE: 0x1f0530 | Size: 256 bytes
// Khung tháo gỡ #3743 | Địa chỉ PC: 0x172010 | Địa chỉ FDE: 0x1f0530 | Kích thước: 256 bytes
//   0x172010: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x172014: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x172018: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x17201c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3743_0x172010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172010ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3744 | PC: 0x17214c | FDE: 0x1f0558 | Size: 80 bytes
// Khung tháo gỡ #3744 | Địa chỉ PC: 0x17214c | Địa chỉ FDE: 0x1f0558 | Kích thước: 80 bytes
//   0x17214c: F9400448  ldr      x8, [x2, #8]
//   0x172150: AA1F03E0  mov      x0, xzr
//   0x172154: D1000429  sub      x9, x1, #1
//   0x172158: AA0803EA  mov      x10, x8
static inline uint64_t fde_func_3744_0x17214c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17214cULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1f0558ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3745 | PC: 0x17219c | FDE: 0x1f0570 | Size: 180 bytes
// Khung tháo gỡ #3745 | Địa chỉ PC: 0x17219c | Địa chỉ FDE: 0x1f0570 | Kích thước: 180 bytes
//   0x17219c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1721a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1721a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1721a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3745_0x17219c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17219cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0570ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3746 | PC: 0x172250 | FDE: 0x1f0590 | Size: 40 bytes
// Khung tháo gỡ #3746 | Địa chỉ PC: 0x172250 | Địa chỉ FDE: 0x1f0590 | Kích thước: 40 bytes
//   0x172250: F9400449  ldr      x9, [x2, #8]
//   0x172254: AA1F03E0  mov      x0, xzr
//   0x172258: D1000428  sub      x8, x1, #1
//   0x17225c: 3869690A  ldrb     w10, [x8, x9]
static inline uint64_t fde_func_3746_0x172250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172250ULL ^ (static_cast<uint64_t>(0xf9400449ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1f0590ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3747 | PC: 0x172278 | FDE: 0x1f05a8 | Size: 180 bytes
// Khung tháo gỡ #3747 | Địa chỉ PC: 0x172278 | Địa chỉ FDE: 0x1f05a8 | Kích thước: 180 bytes
//   0x172278: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x17227c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x172280: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x172284: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3747_0x172278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172278ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f05a8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3748 | PC: 0x17232c | FDE: 0x1f05c8 | Size: 80 bytes
// Khung tháo gỡ #3748 | Địa chỉ PC: 0x17232c | Địa chỉ FDE: 0x1f05c8 | Kích thước: 80 bytes
//   0x17232c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x172330: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172334: 910043FD  add      x29, sp, #0x10
//   0x172338: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3748_0x17232c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17232cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f05c8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3749 | PC: 0x17237c | FDE: 0x1f05e8 | Size: 120 bytes
// Khung tháo gỡ #3749 | Địa chỉ PC: 0x17237c | Địa chỉ FDE: 0x1f05e8 | Kích thước: 120 bytes
//   0x17237c: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x172380: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x172384: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x172388: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3749_0x17237c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17237cULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f05e8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3750 | PC: 0x1723f4 | FDE: 0x1f0608 | Size: 80 bytes
// Khung tháo gỡ #3750 | Địa chỉ PC: 0x1723f4 | Địa chỉ FDE: 0x1f0608 | Kích thước: 80 bytes
//   0x1723f4: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x1723f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1723fc: 910043FD  add      x29, sp, #0x10
//   0x172400: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3750_0x1723f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1723f4ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0608ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3751 | PC: 0x172444 | FDE: 0x1f0628 | Size: 120 bytes
// Khung tháo gỡ #3751 | Địa chỉ PC: 0x172444 | Địa chỉ FDE: 0x1f0628 | Kích thước: 120 bytes
//   0x172444: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x172448: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17244c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x172450: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3751_0x172444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172444ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0628ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3752 | PC: 0x1724bc | FDE: 0x1f0648 | Size: 80 bytes
// Khung tháo gỡ #3752 | Địa chỉ PC: 0x1724bc | Địa chỉ FDE: 0x1f0648 | Kích thước: 80 bytes
//   0x1724bc: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x1724c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1724c4: 910043FD  add      x29, sp, #0x10
//   0x1724c8: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3752_0x1724bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1724bcULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0648ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3753 | PC: 0x17250c | FDE: 0x1f0668 | Size: 120 bytes
// Khung tháo gỡ #3753 | Địa chỉ PC: 0x17250c | Địa chỉ FDE: 0x1f0668 | Kích thước: 120 bytes
//   0x17250c: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x172510: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x172514: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x172518: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3753_0x17250c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17250cULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0668ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3754 | PC: 0x172584 | FDE: 0x1f0688 | Size: 12 bytes [PyInit__thread]
// Khung tháo gỡ #3754 | Địa chỉ PC: 0x172584 | Địa chỉ FDE: 0x1f0688 | Kích thước: 12 bytes
//   0x172584: 90000560  adrp     x0, #0x21e000
//   0x172588: 913B8000  add      x0, x0, #0xee0
//   0x17258c: 17FB9925  b        #0x58a20
static inline uint64_t fde_func_3754_0x172584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172584ULL ^ (static_cast<uint64_t>(0x90000560ULL) << 13);
    acc = (acc + a1 + 0x913b8000ULL) ^ 0x1f0688ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3755 | PC: 0x172590 | FDE: 0x1f06a0 | Size: 108 bytes
// Khung tháo gỡ #3755 | Địa chỉ PC: 0x172590 | Địa chỉ FDE: 0x1f06a0 | Kích thước: 108 bytes
//   0x172590: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x172594: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x172598: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17259c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3755_0x172590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172590ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f06a0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3756 | PC: 0x1725fc | FDE: 0x1f06c0 | Size: 148 bytes
// Khung tháo gỡ #3756 | Địa chỉ PC: 0x1725fc | Địa chỉ FDE: 0x1f06c0 | Kích thước: 148 bytes
//   0x1725fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x172600: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172604: 910043FD  add      x29, sp, #0x10
//   0x172608: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3756_0x1725fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1725fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f06c0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3757 | PC: 0x172690 | FDE: 0x1f06e0 | Size: 152 bytes
// Khung tháo gỡ #3757 | Địa chỉ PC: 0x172690 | Địa chỉ FDE: 0x1f06e0 | Kích thước: 152 bytes
//   0x172690: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x172694: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172698: 910043FD  add      x29, sp, #0x10
//   0x17269c: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3757_0x172690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172690ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f06e0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3758 | PC: 0x172728 | FDE: 0x1f0700 | Size: 256 bytes
// Khung tháo gỡ #3758 | Địa chỉ PC: 0x172728 | Địa chỉ FDE: 0x1f0700 | Kích thước: 256 bytes
//   0x172728: D10143FF  sub      sp, sp, #0x50
//   0x17272c: F90013F5  str      x21, [sp, #0x20]
//   0x172730: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x172734: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3758_0x172728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172728ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1f0700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3759 | PC: 0x172960 | FDE: 0x1f0720 | Size: 124 bytes
// Khung tháo gỡ #3759 | Địa chỉ PC: 0x172960 | Địa chỉ FDE: 0x1f0720 | Kích thước: 124 bytes
//   0x172960: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x172964: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172968: 910043FD  add      x29, sp, #0x10
//   0x17296c: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_3759_0x172960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172960ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0720ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #3760 | PC: 0x1729dc | FDE: 0x1f0740 | Size: 64 bytes
// Khung tháo gỡ #3760 | Địa chỉ PC: 0x1729dc | Địa chỉ FDE: 0x1f0740 | Kích thước: 64 bytes
//   0x1729dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1729e0: 910003FD  mov      x29, sp
//   0x1729e4: 97FB996B  bl       #0x58f90
//   0x1729e8: B100041F  cmn      x0, #1
static inline uint64_t fde_func_3760_0x1729dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1729dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f0740ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3761 | PC: 0x172a1c | FDE: 0x1f0760 | Size: 228 bytes
// Khung tháo gỡ #3761 | Địa chỉ PC: 0x172a1c | Địa chỉ FDE: 0x1f0760 | Kích thước: 228 bytes
//   0x172a1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x172a20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172a24: 910043FD  add      x29, sp, #0x10
//   0x172a28: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3761_0x172a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172a1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0760ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #3762 | PC: 0x172b00 | FDE: 0x1f0780 | Size: 256 bytes
// Khung tháo gỡ #3762 | Địa chỉ PC: 0x172b00 | Địa chỉ FDE: 0x1f0780 | Kích thước: 256 bytes
//   0x172b00: D101C3FF  sub      sp, sp, #0x70
//   0x172b04: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x172b08: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x172b0c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3762_0x172b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172b00ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1f0780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3763 | PC: 0x172d90 | FDE: 0x1f07b0 | Size: 232 bytes
// Khung tháo gỡ #3763 | Địa chỉ PC: 0x172d90 | Địa chỉ FDE: 0x1f07b0 | Kích thước: 232 bytes
//   0x172d90: D100C3FF  sub      sp, sp, #0x30
//   0x172d94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x172d98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x172d9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3763_0x172d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172d90ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f07b0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3764 | PC: 0x172e78 | FDE: 0x1f07d0 | Size: 256 bytes
// Khung tháo gỡ #3764 | Địa chỉ PC: 0x172e78 | Địa chỉ FDE: 0x1f07d0 | Kích thước: 256 bytes
//   0x172e78: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x172e7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172e80: 910043FD  add      x29, sp, #0x10
//   0x172e84: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3764_0x172e78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172e78ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f07d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3765 | PC: 0x172f84 | FDE: 0x1f07f0 | Size: 112 bytes
// Khung tháo gỡ #3765 | Địa chỉ PC: 0x172f84 | Địa chỉ FDE: 0x1f07f0 | Kích thước: 112 bytes
//   0x172f84: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x172f88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x172f8c: 910043FD  add      x29, sp, #0x10
//   0x172f90: B0000468  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3765_0x172f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172f84ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f07f0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3766 | PC: 0x172ff4 | FDE: 0x1f0810 | Size: 256 bytes
// Khung tháo gỡ #3766 | Địa chỉ PC: 0x172ff4 | Địa chỉ FDE: 0x1f0810 | Kích thước: 256 bytes
//   0x172ff4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x172ff8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x172ffc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x173000: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3766_0x172ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172ff4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3767 | PC: 0x173178 | FDE: 0x1f0838 | Size: 120 bytes
// Khung tháo gỡ #3767 | Địa chỉ PC: 0x173178 | Địa chỉ FDE: 0x1f0838 | Kích thước: 120 bytes
//   0x173178: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17317c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173180: 910043FD  add      x29, sp, #0x10
//   0x173184: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_3767_0x173178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173178ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0838ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3768 | PC: 0x1731f0 | FDE: 0x1f0858 | Size: 52 bytes
// Khung tháo gỡ #3768 | Địa chỉ PC: 0x1731f0 | Địa chỉ FDE: 0x1f0858 | Kích thước: 52 bytes
//   0x1731f0: F9400408  ldr      x8, [x0, #8]
//   0x1731f4: 39408009  ldrb     w9, [x0, #0x20]
//   0x1731f8: B000026A  adrp     x10, #0x1c0000
//   0x1731fc: B000028B  adrp     x11, #0x1c4000
static inline uint64_t fde_func_3768_0x1731f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1731f0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x39408009ULL) ^ 0x1f0858ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3769 | PC: 0x173224 | FDE: 0x1f0870 | Size: 52 bytes
// Khung tháo gỡ #3769 | Địa chỉ PC: 0x173224 | Địa chỉ FDE: 0x1f0870 | Kích thước: 52 bytes
//   0x173224: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x173228: 910003FD  mov      x29, sp
//   0x17322c: F9400400  ldr      x0, [x0, #8]
//   0x173230: B40000E0  cbz      x0, #0x17324c
static inline uint64_t fde_func_3769_0x173224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173224ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f0870ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3770 | PC: 0x173258 | FDE: 0x1f0890 | Size: 148 bytes
// Khung tháo gỡ #3770 | Địa chỉ PC: 0x173258 | Địa chỉ FDE: 0x1f0890 | Kích thước: 148 bytes
//   0x173258: D100C3FF  sub      sp, sp, #0x30
//   0x17325c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x173260: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x173264: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3770_0x173258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173258ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0890ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #3771 | PC: 0x1732ec | FDE: 0x1f08b0 | Size: 100 bytes
// Khung tháo gỡ #3771 | Địa chỉ PC: 0x1732ec | Địa chỉ FDE: 0x1f08b0 | Kích thước: 100 bytes
//   0x1732ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1732f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1732f4: 910043FD  add      x29, sp, #0x10
//   0x1732f8: 39408008  ldrb     w8, [x0, #0x20]
static inline uint64_t fde_func_3771_0x1732ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1732ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f08b0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #3772 | PC: 0x173350 | FDE: 0x1f08d0 | Size: 8 bytes
// Khung tháo gỡ #3772 | Địa chỉ PC: 0x173350 | Địa chỉ FDE: 0x1f08d0 | Kích thước: 8 bytes
//   0x173350: 39408000  ldrb     w0, [x0, #0x20]
//   0x173354: 17FB9DB3  b        #0x5aa20
static inline uint64_t fde_func_3772_0x173350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173350ULL ^ (static_cast<uint64_t>(0x39408000ULL) << 13);
    acc = (acc + a1 + 0x17fb9db3ULL) ^ 0x1f08d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3773 | PC: 0x173358 | FDE: 0x1f08e8 | Size: 96 bytes
// Khung tháo gỡ #3773 | Địa chỉ PC: 0x173358 | Địa chỉ FDE: 0x1f08e8 | Kích thước: 96 bytes
//   0x173358: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17335c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173360: 910043FD  add      x29, sp, #0x10
//   0x173364: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3773_0x173358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173358ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f08e8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #3774 | PC: 0x1733b8 | FDE: 0x1f0908 | Size: 256 bytes
// Khung tháo gỡ #3774 | Địa chỉ PC: 0x1733b8 | Địa chỉ FDE: 0x1f0908 | Kích thước: 256 bytes
//   0x1733b8: D101C3FF  sub      sp, sp, #0x70
//   0x1733bc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1733c0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1733c4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_3774_0x1733b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1733b8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1f0908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3775 | PC: 0x17352c | FDE: 0x1f0930 | Size: 204 bytes
// Khung tháo gỡ #3775 | Địa chỉ PC: 0x17352c | Địa chỉ FDE: 0x1f0930 | Kích thước: 204 bytes
//   0x17352c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x173530: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x173534: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x173538: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3775_0x17352c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17352cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0930ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #3776 | PC: 0x1735f8 | FDE: 0x1f0958 | Size: 120 bytes
// Khung tháo gỡ #3776 | Địa chỉ PC: 0x1735f8 | Địa chỉ FDE: 0x1f0958 | Kích thước: 120 bytes
//   0x1735f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1735fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173600: 910043FD  add      x29, sp, #0x10
//   0x173604: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_3776_0x1735f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1735f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0958ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3777 | PC: 0x173670 | FDE: 0x1f0978 | Size: 52 bytes
// Khung tháo gỡ #3777 | Địa chỉ PC: 0x173670 | Địa chỉ FDE: 0x1f0978 | Kích thước: 52 bytes
//   0x173670: F9400408  ldr      x8, [x0, #8]
//   0x173674: A9419003  ldp      x3, x4, [x0, #0x18]
//   0x173678: B0000269  adrp     x9, #0x1c0000
//   0x17367c: B000028A  adrp     x10, #0x1c4000
static inline uint64_t fde_func_3777_0x173670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173670ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xa9419003ULL) ^ 0x1f0978ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3778 | PC: 0x1736a4 | FDE: 0x1f0990 | Size: 120 bytes
// Khung tháo gỡ #3778 | Địa chỉ PC: 0x1736a4 | Địa chỉ FDE: 0x1f0990 | Kích thước: 120 bytes
//   0x1736a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1736a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1736ac: 910043FD  add      x29, sp, #0x10
//   0x1736b0: F9409808  ldr      x8, [x0, #0x130]
static inline uint64_t fde_func_3778_0x1736a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1736a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0990ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3779 | PC: 0x17371c | FDE: 0x1f09b0 | Size: 52 bytes
// Khung tháo gỡ #3779 | Địa chỉ PC: 0x17371c | Địa chỉ FDE: 0x1f09b0 | Kích thước: 52 bytes
//   0x17371c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x173720: 910003FD  mov      x29, sp
//   0x173724: F9400400  ldr      x0, [x0, #8]
//   0x173728: B40000E0  cbz      x0, #0x173744
static inline uint64_t fde_func_3779_0x17371c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17371cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f09b0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #3780 | PC: 0x173750 | FDE: 0x1f09d0 | Size: 252 bytes
// Khung tháo gỡ #3780 | Địa chỉ PC: 0x173750 | Địa chỉ FDE: 0x1f09d0 | Kích thước: 252 bytes
//   0x173750: D10103FF  sub      sp, sp, #0x40
//   0x173754: F9000BF5  str      x21, [sp, #0x10]
//   0x173758: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x17375c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3780_0x173750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173750ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f09d0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #3781 | PC: 0x17384c | FDE: 0x1f09f0 | Size: 128 bytes
// Khung tháo gỡ #3781 | Địa chỉ PC: 0x17384c | Địa chỉ FDE: 0x1f09f0 | Kích thước: 128 bytes
//   0x17384c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x173850: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173854: 910043FD  add      x29, sp, #0x10
//   0x173858: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3781_0x17384c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17384cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f09f0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3782 | PC: 0x1738cc | FDE: 0x1f0a10 | Size: 84 bytes
// Khung tháo gỡ #3782 | Địa chỉ PC: 0x1738cc | Địa chỉ FDE: 0x1f0a10 | Kích thước: 84 bytes
//   0x1738cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1738d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1738d4: 910043FD  add      x29, sp, #0x10
//   0x1738d8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3782_0x1738cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1738ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0a10ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3783 | PC: 0x173920 | FDE: 0x1f0a30 | Size: 232 bytes
// Khung tháo gỡ #3783 | Địa chỉ PC: 0x173920 | Địa chỉ FDE: 0x1f0a30 | Kích thước: 232 bytes
//   0x173920: D10143FF  sub      sp, sp, #0x50
//   0x173924: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x173928: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x17392c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3783_0x173920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173920ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f0a30ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3784 | PC: 0x173a08 | FDE: 0x1f0a58 | Size: 104 bytes
// Khung tháo gỡ #3784 | Địa chỉ PC: 0x173a08 | Địa chỉ FDE: 0x1f0a58 | Kích thước: 104 bytes
//   0x173a08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x173a0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173a10: 910043FD  add      x29, sp, #0x10
//   0x173a14: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3784_0x173a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173a08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0a58ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3785 | PC: 0x173a70 | FDE: 0x1f0a78 | Size: 96 bytes
// Khung tháo gỡ #3785 | Địa chỉ PC: 0x173a70 | Địa chỉ FDE: 0x1f0a78 | Kích thước: 96 bytes
//   0x173a70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x173a74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173a78: 910043FD  add      x29, sp, #0x10
//   0x173a7c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3785_0x173a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173a70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0a78ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #3786 | PC: 0x173ad0 | FDE: 0x1f0a98 | Size: 92 bytes
// Khung tháo gỡ #3786 | Địa chỉ PC: 0x173ad0 | Địa chỉ FDE: 0x1f0a98 | Kích thước: 92 bytes
//   0x173ad0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x173ad4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173ad8: 910043FD  add      x29, sp, #0x10
//   0x173adc: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_3786_0x173ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173ad0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0a98ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3787 | PC: 0x173b2c | FDE: 0x1f0ab8 | Size: 136 bytes
// Khung tháo gỡ #3787 | Địa chỉ PC: 0x173b2c | Địa chỉ FDE: 0x1f0ab8 | Kích thước: 136 bytes
//   0x173b2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x173b30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x173b34: 910043FD  add      x29, sp, #0x10
//   0x173b38: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_3787_0x173b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173b2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0ab8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #3788 | PC: 0x173bb4 | FDE: 0x1f0ad8 | Size: 244 bytes
// Khung tháo gỡ #3788 | Địa chỉ PC: 0x173bb4 | Địa chỉ FDE: 0x1f0ad8 | Kích thước: 244 bytes
//   0x173bb4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x173bb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x173bbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x173bc0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3788_0x173bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173bb4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0ad8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #3789 | PC: 0x173ca8 | FDE: 0x1f0b00 | Size: 200 bytes
// Khung tháo gỡ #3789 | Địa chỉ PC: 0x173ca8 | Địa chỉ FDE: 0x1f0b00 | Kích thước: 200 bytes
//   0x173ca8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x173cac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x173cb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x173cb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3789_0x173ca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173ca8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0b00ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #3790 | PC: 0x173d70 | FDE: 0x1f0b28 | Size: 128 bytes
// Khung tháo gỡ #3790 | Địa chỉ PC: 0x173d70 | Địa chỉ FDE: 0x1f0b28 | Kích thước: 128 bytes
//   0x173d70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x173d74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x173d78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x173d7c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3790_0x173d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173d70ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0b28ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3791 | PC: 0x173df0 | FDE: 0x1f0b48 | Size: 256 bytes
// Khung tháo gỡ #3791 | Địa chỉ PC: 0x173df0 | Địa chỉ FDE: 0x1f0b48 | Kích thước: 256 bytes
//   0x173df0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x173df4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x173df8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x173dfc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3791_0x173df0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173df0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3792 | PC: 0x173f40 | FDE: 0x1f0b68 | Size: 256 bytes
// Khung tháo gỡ #3792 | Địa chỉ PC: 0x173f40 | Địa chỉ FDE: 0x1f0b68 | Kích thước: 256 bytes
//   0x173f40: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x173f44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x173f48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x173f4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3792_0x173f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173f40ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3793 | PC: 0x1740d4 | FDE: 0x1f0b90 | Size: 196 bytes
// Khung tháo gỡ #3793 | Địa chỉ PC: 0x1740d4 | Địa chỉ FDE: 0x1f0b90 | Kích thước: 196 bytes
//   0x1740d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1740d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1740dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1740e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3793_0x1740d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1740d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0b90ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3794 | PC: 0x174198 | FDE: 0x1f0bb0 | Size: 256 bytes
// Khung tháo gỡ #3794 | Địa chỉ PC: 0x174198 | Địa chỉ FDE: 0x1f0bb0 | Kích thước: 256 bytes
//   0x174198: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x17419c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1741a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1741a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3794_0x174198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174198ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3795 | PC: 0x1742fc | FDE: 0x1f0bd8 | Size: 160 bytes
// Khung tháo gỡ #3795 | Địa chỉ PC: 0x1742fc | Địa chỉ FDE: 0x1f0bd8 | Kích thước: 160 bytes
//   0x1742fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x174300: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x174304: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x174308: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3795_0x1742fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1742fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0bd8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3796 | PC: 0x17439c | FDE: 0x1f0bf8 | Size: 12 bytes [PyInit__weakref]
// Khung tháo gỡ #3796 | Địa chỉ PC: 0x17439c | Địa chỉ FDE: 0x1f0bf8 | Kích thước: 12 bytes
//   0x17439c: F0000540  adrp     x0, #0x21f000
//   0x1743a0: 911BE000  add      x0, x0, #0x6f8
//   0x1743a4: 17FB919F  b        #0x58a20
static inline uint64_t fde_func_3796_0x17439c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17439cULL ^ (static_cast<uint64_t>(0xf0000540ULL) << 13);
    acc = (acc + a1 + 0x911be000ULL) ^ 0x1f0bf8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3797 | PC: 0x1743a8 | FDE: 0x1f0c10 | Size: 92 bytes
// Khung tháo gỡ #3797 | Địa chỉ PC: 0x1743a8 | Địa chỉ FDE: 0x1f0c10 | Kích thước: 92 bytes
//   0x1743a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1743ac: 910003FD  mov      x29, sp
//   0x1743b0: F9400428  ldr      x8, [x1, #8]
//   0x1743b4: F9406908  ldr      x8, [x8, #0xd0]
static inline uint64_t fde_func_3797_0x1743a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1743a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f0c10ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3798 | PC: 0x174404 | FDE: 0x1f0c30 | Size: 188 bytes
// Khung tháo gỡ #3798 | Địa chỉ PC: 0x174404 | Địa chỉ FDE: 0x1f0c30 | Kích thước: 188 bytes
//   0x174404: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x174408: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17440c: 910043FD  add      x29, sp, #0x10
//   0x174410: F100085F  cmp      x2, #2
static inline uint64_t fde_func_3798_0x174404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174404ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0c30ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #3799 | PC: 0x1744c0 | FDE: 0x1f0c50 | Size: 128 bytes
// Khung tháo gỡ #3799 | Địa chỉ PC: 0x1744c0 | Địa chỉ FDE: 0x1f0c50 | Kích thước: 128 bytes
//   0x1744c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1744c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1744c8: 910043FD  add      x29, sp, #0x10
//   0x1744cc: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_3799_0x1744c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1744c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0c50ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #3800 | PC: 0x174540 | FDE: 0x1f0c70 | Size: 120 bytes
// Khung tháo gỡ #3800 | Địa chỉ PC: 0x174540 | Địa chỉ FDE: 0x1f0c70 | Kích thước: 120 bytes
//   0x174540: D10103FF  sub      sp, sp, #0x40
//   0x174544: F90013F3  str      x19, [sp, #0x20]
//   0x174548: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x17454c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3800_0x174540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174540ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1f0c70ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3801 | PC: 0x1745b8 | FDE: 0x1f0c90 | Size: 172 bytes
// Khung tháo gỡ #3801 | Địa chỉ PC: 0x1745b8 | Địa chỉ FDE: 0x1f0c90 | Kích thước: 172 bytes
//   0x1745b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1745bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1745c0: 910043FD  add      x29, sp, #0x10
//   0x1745c4: F0000448  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3801_0x1745b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1745b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0c90ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3802 | PC: 0x174664 | FDE: 0x1f0cb0 | Size: 256 bytes
// Khung tháo gỡ #3802 | Địa chỉ PC: 0x174664 | Địa chỉ FDE: 0x1f0cb0 | Kích thước: 256 bytes
//   0x174664: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x174668: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17466c: 910043FD  add      x29, sp, #0x10
//   0x174670: F0000454  adrp     x20, #0x1ff000
static inline uint64_t fde_func_3802_0x174664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174664ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0cb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3803 | PC: 0x174788 | FDE: 0x1f0cd0 | Size: 256 bytes [PyInit__xxsubinterpreters]
// Khung tháo gỡ #3803 | Địa chỉ PC: 0x174788 | Địa chỉ FDE: 0x1f0cd0 | Kích thước: 256 bytes
//   0x174788: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x17478c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x174790: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x174794: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3803_0x174788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174788ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3804 | PC: 0x1749fc | FDE: 0x1f0cf8 | Size: 116 bytes
// Khung tháo gỡ #3804 | Địa chỉ PC: 0x1749fc | Địa chỉ FDE: 0x1f0cf8 | Kích thước: 116 bytes
//   0x1749fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x174a00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x174a04: 910043FD  add      x29, sp, #0x10
//   0x174a08: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3804_0x1749fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1749fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0cf8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3805 | PC: 0x174a70 | FDE: 0x1f0d18 | Size: 248 bytes
// Khung tháo gỡ #3805 | Địa chỉ PC: 0x174a70 | Địa chỉ FDE: 0x1f0d18 | Kích thước: 248 bytes
//   0x174a70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x174a74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x174a78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x174a7c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3805_0x174a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174a70ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0d18ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #3806 | PC: 0x174b68 | FDE: 0x1f0d38 | Size: 92 bytes
// Khung tháo gỡ #3806 | Địa chỉ PC: 0x174b68 | Địa chỉ FDE: 0x1f0d38 | Kích thước: 92 bytes
//   0x174b68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x174b6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x174b70: 910043FD  add      x29, sp, #0x10
//   0x174b74: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3806_0x174b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174b68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0d38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3807 | PC: 0x174bc4 | FDE: 0x1f0d58 | Size: 84 bytes
// Khung tháo gỡ #3807 | Địa chỉ PC: 0x174bc4 | Địa chỉ FDE: 0x1f0d58 | Kích thước: 84 bytes
//   0x174bc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x174bc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x174bcc: 910043FD  add      x29, sp, #0x10
//   0x174bd0: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_3807_0x174bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174bc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f0d58ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3808 | PC: 0x174c18 | FDE: 0x1f0d78 | Size: 16 bytes
// Khung tháo gỡ #3808 | Địa chỉ PC: 0x174c18 | Địa chỉ FDE: 0x1f0d78 | Kích thước: 16 bytes
//   0x174c18: F9400801  ldr      x1, [x0, #0x10]
//   0x174c1c: D0000280  adrp     x0, #0x1c6000
//   0x174c20: 91237C00  add      x0, x0, #0x8df
//   0x174c24: 17FB8DA3  b        #0x582b0
static inline uint64_t fde_func_3808_0x174c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174c18ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xd0000280ULL) ^ 0x1f0d78ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #3809 | PC: 0x174c28 | FDE: 0x1f0d90 | Size: 256 bytes
// Khung tháo gỡ #3809 | Địa chỉ PC: 0x174c28 | Địa chỉ FDE: 0x1f0d90 | Kích thước: 256 bytes
//   0x174c28: D10143FF  sub      sp, sp, #0x50
//   0x174c2c: F9000BF7  str      x23, [sp, #0x10]
//   0x174c30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x174c34: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3809_0x174c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174c28ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f0d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3810 | PC: 0x174dec | FDE: 0x1f0db8 | Size: 256 bytes
// Khung tháo gỡ #3810 | Địa chỉ PC: 0x174dec | Địa chỉ FDE: 0x1f0db8 | Kích thước: 256 bytes
//   0x174dec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x174df0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x174df4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x174df8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3810_0x174dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174decULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3811 | PC: 0x174ef0 | FDE: 0x1f0de0 | Size: 8 bytes
// Khung tháo gỡ #3811 | Địa chỉ PC: 0x174ef0 | Địa chỉ FDE: 0x1f0de0 | Kích thước: 8 bytes
//   0x174ef0: F9400800  ldr      x0, [x0, #0x10]
//   0x174ef4: 17FBA00B  b        #0x5cf20
static inline uint64_t fde_func_3811_0x174ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174ef0ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17fba00bULL) ^ 0x1f0de0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3812 | PC: 0x174ef8 | FDE: 0x1f0df8 | Size: 92 bytes
// Khung tháo gỡ #3812 | Địa chỉ PC: 0x174ef8 | Địa chỉ FDE: 0x1f0df8 | Kích thước: 92 bytes
//   0x174ef8: B4000121  cbz      x1, #0x174f1c
//   0x174efc: A940A408  ldp      x8, x9, [x0, #8]
//   0x174f00: B9400022  ldr      w2, [x1]
//   0x174f04: F9401003  ldr      x3, [x0, #0x20]
static inline uint64_t fde_func_3812_0x174ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174ef8ULL ^ (static_cast<uint64_t>(0xb4000121ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1f0df8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3813 | PC: 0x174f54 | FDE: 0x1f0e10 | Size: 236 bytes
// Khung tháo gỡ #3813 | Địa chỉ PC: 0x174f54 | Địa chỉ FDE: 0x1f0e10 | Kích thước: 236 bytes
//   0x174f54: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x174f58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x174f5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x174f60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3813_0x174f54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174f54ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0e10ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3814 | PC: 0x175040 | FDE: 0x1f0e38 | Size: 256 bytes
// Khung tháo gỡ #3814 | Địa chỉ PC: 0x175040 | Địa chỉ FDE: 0x1f0e38 | Kích thước: 256 bytes
//   0x175040: D10103FF  sub      sp, sp, #0x40
//   0x175044: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x175048: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x17504c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3814_0x175040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175040ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3815 | PC: 0x175144 | FDE: 0x1f0e60 | Size: 256 bytes
// Khung tháo gỡ #3815 | Địa chỉ PC: 0x175144 | Địa chỉ FDE: 0x1f0e60 | Kích thước: 256 bytes
//   0x175144: D10103FF  sub      sp, sp, #0x40
//   0x175148: F9000BF5  str      x21, [sp, #0x10]
//   0x17514c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x175150: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3815_0x175144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175144ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f0e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3816 | PC: 0x175298 | FDE: 0x1f0e80 | Size: 176 bytes
// Khung tháo gỡ #3816 | Địa chỉ PC: 0x175298 | Địa chỉ FDE: 0x1f0e80 | Kích thước: 176 bytes
//   0x175298: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x17529c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1752a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1752a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3816_0x175298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175298ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0e80ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3817 | PC: 0x175348 | FDE: 0x1f0ea8 | Size: 32 bytes
// Khung tháo gỡ #3817 | Địa chỉ PC: 0x175348 | Địa chỉ FDE: 0x1f0ea8 | Kích thước: 32 bytes
//   0x175348: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17534c: 910003FD  mov      x29, sp
//   0x175350: 97FB9D88  bl       #0x5c970
//   0x175354: B4000060  cbz      x0, #0x175360
static inline uint64_t fde_func_3817_0x175348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175348ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f0ea8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3818 | PC: 0x175368 | FDE: 0x1f0ec8 | Size: 8 bytes
// Khung tháo gỡ #3818 | Địa chỉ PC: 0x175368 | Địa chỉ FDE: 0x1f0ec8 | Kích thước: 8 bytes
//   0x175368: AA1F03E0  mov      x0, xzr
//   0x17536c: 17FB9C25  b        #0x5c400
static inline uint64_t fde_func_3818_0x175368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175368ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0x17fb9c25ULL) ^ 0x1f0ec8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3819 | PC: 0x175370 | FDE: 0x1f0ee0 | Size: 236 bytes
// Khung tháo gỡ #3819 | Địa chỉ PC: 0x175370 | Địa chỉ FDE: 0x1f0ee0 | Kích thước: 236 bytes
//   0x175370: D100C3FF  sub      sp, sp, #0x30
//   0x175374: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x175378: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17537c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3819_0x175370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175370ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0ee0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3820 | PC: 0x17545c | FDE: 0x1f0f00 | Size: 256 bytes
// Khung tháo gỡ #3820 | Địa chỉ PC: 0x17545c | Địa chỉ FDE: 0x1f0f00 | Kích thước: 256 bytes
//   0x17545c: D10283FF  sub      sp, sp, #0xa0
//   0x175460: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x175464: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x175468: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_3820_0x17545c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17545cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1f0f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3821 | PC: 0x1759fc | FDE: 0x1f0f30 | Size: 256 bytes
// Khung tháo gỡ #3821 | Địa chỉ PC: 0x1759fc | Địa chỉ FDE: 0x1f0f30 | Kích thước: 256 bytes
//   0x1759fc: D102C3FF  sub      sp, sp, #0xb0
//   0x175a00: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x175a04: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x175a08: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_3821_0x1759fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1759fcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x1f0f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3822 | PC: 0x176218 | FDE: 0x1f0f60 | Size: 256 bytes
// Khung tháo gỡ #3822 | Địa chỉ PC: 0x176218 | Địa chỉ FDE: 0x1f0f60 | Kích thước: 256 bytes
//   0x176218: D10203FF  sub      sp, sp, #0x80
//   0x17621c: F90013FB  str      x27, [sp, #0x20]
//   0x176220: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x176224: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3822_0x176218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176218ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1f0f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3823 | PC: 0x17670c | FDE: 0x1f0f90 | Size: 160 bytes
// Khung tháo gỡ #3823 | Địa chỉ PC: 0x17670c | Địa chỉ FDE: 0x1f0f90 | Kích thước: 160 bytes
//   0x17670c: D100C3FF  sub      sp, sp, #0x30
//   0x176710: F9000BF3  str      x19, [sp, #0x10]
//   0x176714: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x176718: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3823_0x17670c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17670cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1f0f90ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #3824 | PC: 0x1767ac | FDE: 0x1f0fb0 | Size: 256 bytes
// Khung tháo gỡ #3824 | Địa chỉ PC: 0x1767ac | Địa chỉ FDE: 0x1f0fb0 | Kích thước: 256 bytes
//   0x1767ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1767b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1767b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1767b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3824_0x1767ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1767acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f0fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3825 | PC: 0x176964 | FDE: 0x1f0fd8 | Size: 152 bytes
// Khung tháo gỡ #3825 | Địa chỉ PC: 0x176964 | Địa chỉ FDE: 0x1f0fd8 | Kích thước: 152 bytes
//   0x176964: D100C3FF  sub      sp, sp, #0x30
//   0x176968: F9000BF3  str      x19, [sp, #0x10]
//   0x17696c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x176970: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3825_0x176964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176964ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1f0fd8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3826 | PC: 0x1769fc | FDE: 0x1f0ff8 | Size: 256 bytes
// Khung tháo gỡ #3826 | Địa chỉ PC: 0x1769fc | Địa chỉ FDE: 0x1f0ff8 | Kích thước: 256 bytes
//   0x1769fc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x176a00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x176a04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x176a08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3826_0x1769fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1769fcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3827 | PC: 0x176b30 | FDE: 0x1f1020 | Size: 256 bytes
// Khung tháo gỡ #3827 | Địa chỉ PC: 0x176b30 | Địa chỉ FDE: 0x1f1020 | Kích thước: 256 bytes
//   0x176b30: D10203FF  sub      sp, sp, #0x80
//   0x176b34: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x176b38: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x176b3c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_3827_0x176b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176b30ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1f1020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3828 | PC: 0x176d60 | FDE: 0x1f1050 | Size: 256 bytes
// Khung tháo gỡ #3828 | Địa chỉ PC: 0x176d60 | Địa chỉ FDE: 0x1f1050 | Kích thước: 256 bytes
//   0x176d60: D101C3FF  sub      sp, sp, #0x70
//   0x176d64: F90013F9  str      x25, [sp, #0x20]
//   0x176d68: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x176d6c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_3828_0x176d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176d60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1f1050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3829 | PC: 0x176fb8 | FDE: 0x1f1078 | Size: 256 bytes
// Khung tháo gỡ #3829 | Địa chỉ PC: 0x176fb8 | Địa chỉ FDE: 0x1f1078 | Kích thước: 256 bytes
//   0x176fb8: D10183FF  sub      sp, sp, #0x60
//   0x176fbc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x176fc0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x176fc4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_3829_0x176fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176fb8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1f1078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3830 | PC: 0x177288 | FDE: 0x1f10a0 | Size: 256 bytes
// Khung tháo gỡ #3830 | Địa chỉ PC: 0x177288 | Địa chỉ FDE: 0x1f10a0 | Kích thước: 256 bytes
//   0x177288: D101C3FF  sub      sp, sp, #0x70
//   0x17728c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x177290: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x177294: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_3830_0x177288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177288ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1f10a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3831 | PC: 0x177518 | FDE: 0x1f10c8 | Size: 256 bytes
// Khung tháo gỡ #3831 | Địa chỉ PC: 0x177518 | Địa chỉ FDE: 0x1f10c8 | Kích thước: 256 bytes
//   0x177518: D10203FF  sub      sp, sp, #0x80
//   0x17751c: F9001BF9  str      x25, [sp, #0x30]
//   0x177520: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x177524: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_3831_0x177518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177518ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1f10c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3832 | PC: 0x1777a4 | FDE: 0x1f10f0 | Size: 256 bytes
// Khung tháo gỡ #3832 | Địa chỉ PC: 0x1777a4 | Địa chỉ FDE: 0x1f10f0 | Kích thước: 256 bytes
//   0x1777a4: D10143FF  sub      sp, sp, #0x50
//   0x1777a8: F9001BF3  str      x19, [sp, #0x30]
//   0x1777ac: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1777b0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_3832_0x1777a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1777a4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1f10f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3833 | PC: 0x1778a4 | FDE: 0x1f1110 | Size: 72 bytes
// Khung tháo gỡ #3833 | Địa chỉ PC: 0x1778a4 | Địa chỉ FDE: 0x1f1110 | Kích thước: 72 bytes
//   0x1778a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1778a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1778ac: 910043FD  add      x29, sp, #0x10
//   0x1778b0: 97FB923C  bl       #0x5c1a0
static inline uint64_t fde_func_3833_0x1778a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1778a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1110ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3834 | PC: 0x1778ec | FDE: 0x1f1130 | Size: 256 bytes
// Khung tháo gỡ #3834 | Địa chỉ PC: 0x1778ec | Địa chỉ FDE: 0x1f1130 | Kích thước: 256 bytes
//   0x1778ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1778f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1778f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1778f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3834_0x1778ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1778ecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3835 | PC: 0x177a38 | FDE: 0x1f1150 | Size: 256 bytes
// Khung tháo gỡ #3835 | Địa chỉ PC: 0x177a38 | Địa chỉ FDE: 0x1f1150 | Kích thước: 256 bytes
//   0x177a38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x177a3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x177a40: 910043FD  add      x29, sp, #0x10
//   0x177a44: F0000573  adrp     x19, #0x226000
static inline uint64_t fde_func_3835_0x177a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177a38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3836 | PC: 0x177b64 | FDE: 0x1f1170 | Size: 200 bytes
// Khung tháo gỡ #3836 | Địa chỉ PC: 0x177b64 | Địa chỉ FDE: 0x1f1170 | Kích thước: 200 bytes
//   0x177b64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x177b68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x177b6c: 910043FD  add      x29, sp, #0x10
//   0x177b70: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3836_0x177b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177b64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1170ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #3837 | PC: 0x177c2c | FDE: 0x1f1190 | Size: 244 bytes
// Khung tháo gỡ #3837 | Địa chỉ PC: 0x177c2c | Địa chỉ FDE: 0x1f1190 | Kích thước: 244 bytes
//   0x177c2c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x177c30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x177c34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x177c38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3837_0x177c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177c2cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1190ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #3838 | PC: 0x177d20 | FDE: 0x1f11b8 | Size: 256 bytes
// Khung tháo gỡ #3838 | Địa chỉ PC: 0x177d20 | Địa chỉ FDE: 0x1f11b8 | Kích thước: 256 bytes
//   0x177d20: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x177d24: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x177d28: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x177d2c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3838_0x177d20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177d20ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f11b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3839 | PC: 0x177e4c | FDE: 0x1f11d8 | Size: 116 bytes [_PyAtExit_Init]
// Khung tháo gỡ #3839 | Địa chỉ PC: 0x177e4c | Địa chỉ FDE: 0x1f11d8 | Kích thước: 116 bytes
//   0x177e4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x177e50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x177e54: 910043FD  add      x29, sp, #0x10
//   0x177e58: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_3839_0x177e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177e4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f11d8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3840 | PC: 0x177ec0 | FDE: 0x1f11f8 | Size: 212 bytes [_PyAtExit_Fini]
// Khung tháo gỡ #3840 | Địa chỉ PC: 0x177ec0 | Địa chỉ FDE: 0x1f11f8 | Kích thước: 212 bytes
//   0x177ec0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x177ec4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x177ec8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x177ecc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3840_0x177ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177ec0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f11f8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #3841 | PC: 0x177f94 | FDE: 0x1f1218 | Size: 8 bytes [_PyAtExit_Call]
// Khung tháo gỡ #3841 | Địa chỉ PC: 0x177f94 | Địa chỉ FDE: 0x1f1218 | Kích thước: 8 bytes
//   0x177f94: 9139C000  add      x0, x0, #0xe70
//   0x177f98: 14000001  b        #0x177f9c
static inline uint64_t fde_func_3841_0x177f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177f94ULL ^ (static_cast<uint64_t>(0x9139c000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1f1218ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3842 | PC: 0x177f9c | FDE: 0x1f1230 | Size: 256 bytes
// Khung tháo gỡ #3842 | Địa chỉ PC: 0x177f9c | Địa chỉ FDE: 0x1f1230 | Kích thước: 256 bytes
//   0x177f9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x177fa0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x177fa4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x177fa8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3842_0x177f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177f9cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3843 | PC: 0x1780cc | FDE: 0x1f1258 | Size: 12 bytes [PyInit_atexit]
// Khung tháo gỡ #3843 | Địa chỉ PC: 0x1780cc | Địa chỉ FDE: 0x1f1258 | Kích thước: 12 bytes
//   0x1780cc: F0000520  adrp     x0, #0x21f000
//   0x1780d0: 913E8000  add      x0, x0, #0xfa0
//   0x1780d4: 17FB8253  b        #0x58a20
static inline uint64_t fde_func_3843_0x1780cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1780ccULL ^ (static_cast<uint64_t>(0xf0000520ULL) << 13);
    acc = (acc + a1 + 0x913e8000ULL) ^ 0x1f1258ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3844 | PC: 0x1780d8 | FDE: 0x1f1270 | Size: 256 bytes
// Khung tháo gỡ #3844 | Địa chỉ PC: 0x1780d8 | Địa chỉ FDE: 0x1f1270 | Kích thước: 256 bytes
//   0x1780d8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1780dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1780e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1780e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3844_0x1780d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1780d8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f1270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3845 | PC: 0x178224 | FDE: 0x1f1298 | Size: 236 bytes
// Khung tháo gỡ #3845 | Địa chỉ PC: 0x178224 | Địa chỉ FDE: 0x1f1298 | Kích thước: 236 bytes
//   0x178224: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x178228: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17822c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x178230: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3845_0x178224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178224ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1298ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3846 | PC: 0x178310 | FDE: 0x1f12b8 | Size: 256 bytes
// Khung tháo gỡ #3846 | Địa chỉ PC: 0x178310 | Địa chỉ FDE: 0x1f12b8 | Kích thước: 256 bytes
//   0x178310: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x178314: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x178318: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17831c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3846_0x178310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178310ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f12b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3847 | PC: 0x178420 | FDE: 0x1f12e0 | Size: 64 bytes
// Khung tháo gỡ #3847 | Địa chỉ PC: 0x178420 | Địa chỉ FDE: 0x1f12e0 | Kích thước: 64 bytes
//   0x178420: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x178424: 910003FD  mov      x29, sp
//   0x178428: F0000428  adrp     x8, #0x1ff000
//   0x17842c: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3847_0x178420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178420ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f12e0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #3848 | PC: 0x178460 | FDE: 0x1f1300 | Size: 40 bytes
// Khung tháo gỡ #3848 | Địa chỉ PC: 0x178460 | Địa chỉ FDE: 0x1f1300 | Kích thước: 40 bytes
//   0x178460: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x178464: 910003FD  mov      x29, sp
//   0x178468: F0000428  adrp     x8, #0x1ff000
//   0x17846c: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3848_0x178460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178460ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1300ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3849 | PC: 0x178488 | FDE: 0x1f1320 | Size: 12 bytes [PyInit_errno]
// Khung tháo gỡ #3849 | Địa chỉ PC: 0x178488 | Địa chỉ FDE: 0x1f1320 | Kích thước: 12 bytes
//   0x178488: 90000540  adrp     x0, #0x220000
//   0x17848c: 910AA000  add      x0, x0, #0x2a8
//   0x178490: 17FB8164  b        #0x58a20
static inline uint64_t fde_func_3849_0x178488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178488ULL ^ (static_cast<uint64_t>(0x90000540ULL) << 13);
    acc = (acc + a1 + 0x910aa000ULL) ^ 0x1f1320ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3850 | PC: 0x178494 | FDE: 0x1f1338 | Size: 256 bytes
// Khung tháo gỡ #3850 | Địa chỉ PC: 0x178494 | Địa chỉ FDE: 0x1f1338 | Kích thước: 256 bytes
//   0x178494: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x178498: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17849c: 910043FD  add      x29, sp, #0x10
//   0x1784a0: 97FB9268  bl       #0x5ce40
static inline uint64_t fde_func_3850_0x178494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178494ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3851 | PC: 0x1793fc | FDE: 0x1f1358 | Size: 208 bytes
// Khung tháo gỡ #3851 | Địa chỉ PC: 0x1793fc | Địa chỉ FDE: 0x1f1358 | Kích thước: 208 bytes
//   0x1793fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x179400: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x179404: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x179408: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3851_0x1793fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1793fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1358ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #3852 | PC: 0x1794cc | FDE: 0x1f1380 | Size: 12 bytes [PyInit_faulthandler]
// Khung tháo gỡ #3852 | Địa chỉ PC: 0x1794cc | Địa chỉ FDE: 0x1f1380 | Kích thước: 12 bytes
//   0x1794cc: F0000520  adrp     x0, #0x220000
//   0x1794d0: 910CC000  add      x0, x0, #0x330
//   0x1794d4: 17FB7D53  b        #0x58a20
static inline uint64_t fde_func_3852_0x1794cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1794ccULL ^ (static_cast<uint64_t>(0xf0000520ULL) << 13);
    acc = (acc + a1 + 0x910cc000ULL) ^ 0x1f1380ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3853 | PC: 0x1794d8 | FDE: 0x1f1398 | Size: 256 bytes [_PyFaulthandler_Init]
// Khung tháo gỡ #3853 | Địa chỉ PC: 0x1794d8 | Địa chỉ FDE: 0x1f1398 | Kích thước: 256 bytes
//   0x1794d8: D10103FF  sub      sp, sp, #0x40
//   0x1794dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1794e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1794e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3853_0x1794d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1794d8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f1398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3854 | PC: 0x179608 | FDE: 0x1f13c0 | Size: 256 bytes [_PyFaulthandler_Fini]
// Khung tháo gỡ #3854 | Địa chỉ PC: 0x179608 | Địa chỉ FDE: 0x1f13c0 | Kích thước: 256 bytes
//   0x179608: D10143FF  sub      sp, sp, #0x50
//   0x17960c: F90013F5  str      x21, [sp, #0x20]
//   0x179610: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x179614: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3854_0x179608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179608ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1f13c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3855 | PC: 0x17973c | FDE: 0x1f13e0 | Size: 256 bytes
// Khung tháo gỡ #3855 | Địa chỉ PC: 0x17973c | Địa chỉ FDE: 0x1f13e0 | Kích thước: 256 bytes
//   0x17973c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x179740: 910003FD  mov      x29, sp
//   0x179744: B0000568  adrp     x8, #0x226000
//   0x179748: 39586109  ldrb     w9, [x8, #0x618]
static inline uint64_t fde_func_3855_0x17973c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17973cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f13e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 3392: return fde_func_3392_0x158808(a0, a1);
        case 3393: return fde_func_3393_0x158968(a0, a1);
        case 3394: return fde_func_3394_0x1589f8(a0, a1);
        case 3395: return fde_func_3395_0x158ab8(a0, a1);
        case 3396: return fde_func_3396_0x158b04(a0, a1);
        case 3397: return fde_func_3397_0x158b68(a0, a1);
        case 3398: return fde_func_3398_0x158bd4(a0, a1);
        case 3399: return fde_func_3399_0x158c4c(a0, a1);
        case 3400: return fde_func_3400_0x15a2b8(a0, a1);
        case 3401: return fde_func_3401_0x15acfc(a0, a1);
        case 3402: return fde_func_3402_0x15ae04(a0, a1);
        case 3403: return fde_func_3403_0x15aeec(a0, a1);
        case 3404: return fde_func_3404_0x15aef0(a0, a1);
        case 3405: return fde_func_3405_0x15b1c8(a0, a1);
        case 3406: return fde_func_3406_0x15b2dc(a0, a1);
        case 3407: return fde_func_3407_0x15b394(a0, a1);
        case 3408: return fde_func_3408_0x15b4bc(a0, a1);
        case 3409: return fde_func_3409_0x15b514(a0, a1);
        case 3410: return fde_func_3410_0x15b584(a0, a1);
        case 3411: return fde_func_3411_0x15b9d4(a0, a1);
        case 3412: return fde_func_3412_0x15bb98(a0, a1);
        case 3413: return fde_func_3413_0x15bd64(a0, a1);
        case 3414: return fde_func_3414_0x15be10(a0, a1);
        case 3415: return fde_func_3415_0x15be44(a0, a1);
        case 3416: return fde_func_3416_0x15bed8(a0, a1);
        case 3417: return fde_func_3417_0x15bee0(a0, a1);
        case 3418: return fde_func_3418_0x15bee8(a0, a1);
        case 3419: return fde_func_3419_0x15bfd8(a0, a1);
        case 3420: return fde_func_3420_0x15c094(a0, a1);
        case 3421: return fde_func_3421_0x15c1dc(a0, a1);
        case 3422: return fde_func_3422_0x15c30c(a0, a1);
        case 3423: return fde_func_3423_0x15c4ec(a0, a1);
        case 3424: return fde_func_3424_0x15c6e8(a0, a1);
        case 3425: return fde_func_3425_0x15c78c(a0, a1);
        case 3426: return fde_func_3426_0x15cfd4(a0, a1);
        case 3427: return fde_func_3427_0x15d20c(a0, a1);
        case 3428: return fde_func_3428_0x15d4d0(a0, a1);
        case 3429: return fde_func_3429_0x15d8a4(a0, a1);
        case 3430: return fde_func_3430_0x15da34(a0, a1);
        case 3431: return fde_func_3431_0x15dad8(a0, a1);
        case 3432: return fde_func_3432_0x15e084(a0, a1);
        case 3433: return fde_func_3433_0x15e1a0(a0, a1);
        case 3434: return fde_func_3434_0x15e254(a0, a1);
        case 3435: return fde_func_3435_0x15e288(a0, a1);
        case 3436: return fde_func_3436_0x15e2c0(a0, a1);
        case 3437: return fde_func_3437_0x15e3a8(a0, a1);
        case 3438: return fde_func_3438_0x15e530(a0, a1);
        case 3439: return fde_func_3439_0x15e598(a0, a1);
        case 3440: return fde_func_3440_0x15e5e4(a0, a1);
        case 3441: return fde_func_3441_0x15e618(a0, a1);
        case 3442: return fde_func_3442_0x15e768(a0, a1);
        case 3443: return fde_func_3443_0x15e980(a0, a1);
        case 3444: return fde_func_3444_0x15e98c(a0, a1);
        case 3445: return fde_func_3445_0x15ea00(a0, a1);
        case 3446: return fde_func_3446_0x15ec18(a0, a1);
        case 3447: return fde_func_3447_0x15ec4c(a0, a1);
        case 3448: return fde_func_3448_0x15ec84(a0, a1);
        case 3449: return fde_func_3449_0x15f368(a0, a1);
        case 3450: return fde_func_3450_0x15f3a8(a0, a1);
        case 3451: return fde_func_3451_0x15f714(a0, a1);
        case 3452: return fde_func_3452_0x15f89c(a0, a1);
        case 3453: return fde_func_3453_0x15fa04(a0, a1);
        case 3454: return fde_func_3454_0x15fbf4(a0, a1);
        case 3455: return fde_func_3455_0x15fce8(a0, a1);
        case 3456: return fde_func_3456_0x15fd2c(a0, a1);
        case 3457: return fde_func_3457_0x15fd70(a0, a1);
        case 3458: return fde_func_3458_0x15fde0(a0, a1);
        case 3459: return fde_func_3459_0x15fea0(a0, a1);
        case 3460: return fde_func_3460_0x15feac(a0, a1);
        case 3461: return fde_func_3461_0x15ff9c(a0, a1);
        case 3462: return fde_func_3462_0x15ffc4(a0, a1);
        case 3463: return fde_func_3463_0x1600b4(a0, a1);
        case 3464: return fde_func_3464_0x1601a4(a0, a1);
        case 3465: return fde_func_3465_0x160294(a0, a1);
        case 3466: return fde_func_3466_0x160338(a0, a1);
        case 3467: return fde_func_3467_0x16036c(a0, a1);
        case 3468: return fde_func_3468_0x1603a4(a0, a1);
        case 3469: return fde_func_3469_0x160480(a0, a1);
        case 3470: return fde_func_3470_0x16051c(a0, a1);
        case 3471: return fde_func_3471_0x160654(a0, a1);
        case 3472: return fde_func_3472_0x16070c(a0, a1);
        case 3473: return fde_func_3473_0x160858(a0, a1);
        case 3474: return fde_func_3474_0x160870(a0, a1);
        case 3475: return fde_func_3475_0x160888(a0, a1);
        case 3476: return fde_func_3476_0x1608a0(a0, a1);
        case 3477: return fde_func_3477_0x16097c(a0, a1);
        case 3478: return fde_func_3478_0x1609e0(a0, a1);
        case 3479: return fde_func_3479_0x160e0c(a0, a1);
        case 3480: return fde_func_3480_0x160fec(a0, a1);
        case 3481: return fde_func_3481_0x1610e8(a0, a1);
        case 3482: return fde_func_3482_0x16111c(a0, a1);
        case 3483: return fde_func_3483_0x161154(a0, a1);
        case 3484: return fde_func_3484_0x161414(a0, a1);
        case 3485: return fde_func_3485_0x1617ec(a0, a1);
        case 3486: return fde_func_3486_0x161850(a0, a1);
        case 3487: return fde_func_3487_0x161b30(a0, a1);
        case 3488: return fde_func_3488_0x161c20(a0, a1);
        case 3489: return fde_func_3489_0x161cf8(a0, a1);
        case 3490: return fde_func_3490_0x16206c(a0, a1);
        case 3491: return fde_func_3491_0x1627fc(a0, a1);
        case 3492: return fde_func_3492_0x162bf0(a0, a1);
        case 3493: return fde_func_3493_0x162c64(a0, a1);
        case 3494: return fde_func_3494_0x162db4(a0, a1);
        case 3495: return fde_func_3495_0x162e14(a0, a1);
        case 3496: return fde_func_3496_0x163030(a0, a1);
        case 3497: return fde_func_3497_0x16313c(a0, a1);
        case 3498: return fde_func_3498_0x163324(a0, a1);
        case 3499: return fde_func_3499_0x163cf4(a0, a1);
        case 3500: return fde_func_3500_0x164a1c(a0, a1);
        case 3501: return fde_func_3501_0x164b14(a0, a1);
        case 3502: return fde_func_3502_0x164d20(a0, a1);
        case 3503: return fde_func_3503_0x16528c(a0, a1);
        case 3504: return fde_func_3504_0x1653f8(a0, a1);
        case 3505: return fde_func_3505_0x165424(a0, a1);
        case 3506: return fde_func_3506_0x165450(a0, a1);
        case 3507: return fde_func_3507_0x16547c(a0, a1);
        case 3508: return fde_func_3508_0x165484(a0, a1);
        case 3509: return fde_func_3509_0x16548c(a0, a1);
        case 3510: return fde_func_3510_0x165494(a0, a1);
        case 3511: return fde_func_3511_0x16549c(a0, a1);
        case 3512: return fde_func_3512_0x1654a4(a0, a1);
        case 3513: return fde_func_3513_0x1654ac(a0, a1);
        case 3514: return fde_func_3514_0x1654b8(a0, a1);
        case 3515: return fde_func_3515_0x165514(a0, a1);
        case 3516: return fde_func_3516_0x165584(a0, a1);
        case 3517: return fde_func_3517_0x1655f4(a0, a1);
        case 3518: return fde_func_3518_0x16597c(a0, a1);
        case 3519: return fde_func_3519_0x165efc(a0, a1);
        case 3520: return fde_func_3520_0x165fb8(a0, a1);
        case 3521: return fde_func_3521_0x166700(a0, a1);
        case 3522: return fde_func_3522_0x166778(a0, a1);
        case 3523: return fde_func_3523_0x16686c(a0, a1);
        case 3524: return fde_func_3524_0x16692c(a0, a1);
        case 3525: return fde_func_3525_0x166984(a0, a1);
        case 3526: return fde_func_3526_0x166a64(a0, a1);
        case 3527: return fde_func_3527_0x166b20(a0, a1);
        case 3528: return fde_func_3528_0x166c34(a0, a1);
        case 3529: return fde_func_3529_0x166db4(a0, a1);
        case 3530: return fde_func_3530_0x168d68(a0, a1);
        case 3531: return fde_func_3531_0x168dc0(a0, a1);
        case 3532: return fde_func_3532_0x168e70(a0, a1);
        case 3533: return fde_func_3533_0x168f2c(a0, a1);
        case 3534: return fde_func_3534_0x169040(a0, a1);
        case 3535: return fde_func_3535_0x169230(a0, a1);
        case 3536: return fde_func_3536_0x169f0c(a0, a1);
        case 3537: return fde_func_3537_0x169f18(a0, a1);
        case 3538: return fde_func_3538_0x169f54(a0, a1);
        case 3539: return fde_func_3539_0x169f90(a0, a1);
        case 3540: return fde_func_3540_0x169fcc(a0, a1);
        case 3541: return fde_func_3541_0x16a154(a0, a1);
        case 3542: return fde_func_3542_0x16a2c0(a0, a1);
        case 3543: return fde_func_3543_0x16a2cc(a0, a1);
        case 3544: return fde_func_3544_0x16a33c(a0, a1);
        case 3545: return fde_func_3545_0x16a3d4(a0, a1);
        case 3546: return fde_func_3546_0x16a3d8(a0, a1);
        case 3547: return fde_func_3547_0x16a478(a0, a1);
        case 3548: return fde_func_3548_0x16a584(a0, a1);
        case 3549: return fde_func_3549_0x16a6a0(a0, a1);
        case 3550: return fde_func_3550_0x16a6d4(a0, a1);
        case 3551: return fde_func_3551_0x16a7f4(a0, a1);
        case 3552: return fde_func_3552_0x16a8fc(a0, a1);
        case 3553: return fde_func_3553_0x16a9b8(a0, a1);
        case 3554: return fde_func_3554_0x16aa2c(a0, a1);
        case 3555: return fde_func_3555_0x16ab58(a0, a1);
        case 3556: return fde_func_3556_0x16abe8(a0, a1);
        case 3557: return fde_func_3557_0x16ad6c(a0, a1);
        case 3558: return fde_func_3558_0x16b0f8(a0, a1);
        case 3559: return fde_func_3559_0x16b224(a0, a1);
        case 3560: return fde_func_3560_0x16b308(a0, a1);
        case 3561: return fde_func_3561_0x16b35c(a0, a1);
        case 3562: return fde_func_3562_0x16b374(a0, a1);
        case 3563: return fde_func_3563_0x16b384(a0, a1);
        case 3564: return fde_func_3564_0x16b390(a0, a1);
        case 3565: return fde_func_3565_0x16b3fc(a0, a1);
        case 3566: return fde_func_3566_0x16b490(a0, a1);
        case 3567: return fde_func_3567_0x16b528(a0, a1);
        case 3568: return fde_func_3568_0x16b570(a0, a1);
        case 3569: return fde_func_3569_0x16b5e4(a0, a1);
        case 3570: return fde_func_3570_0x16b658(a0, a1);
        case 3571: return fde_func_3571_0x16b6cc(a0, a1);
        case 3572: return fde_func_3572_0x16b740(a0, a1);
        case 3573: return fde_func_3573_0x16b7b4(a0, a1);
        case 3574: return fde_func_3574_0x16b7bc(a0, a1);
        case 3575: return fde_func_3575_0x16b814(a0, a1);
        case 3576: return fde_func_3576_0x16b86c(a0, a1);
        case 3577: return fde_func_3577_0x16b8c4(a0, a1);
        case 3578: return fde_func_3578_0x16b91c(a0, a1);
        case 3579: return fde_func_3579_0x16b974(a0, a1);
        case 3580: return fde_func_3580_0x16b9cc(a0, a1);
        case 3581: return fde_func_3581_0x16ba24(a0, a1);
        case 3582: return fde_func_3582_0x16ba2c(a0, a1);
        case 3583: return fde_func_3583_0x16ba34(a0, a1);
        case 3584: return fde_func_3584_0x16ba3c(a0, a1);
        case 3585: return fde_func_3585_0x16ba44(a0, a1);
        case 3586: return fde_func_3586_0x16ba4c(a0, a1);
        case 3587: return fde_func_3587_0x16baa4(a0, a1);
        case 3588: return fde_func_3588_0x16bafc(a0, a1);
        case 3589: return fde_func_3589_0x16bb44(a0, a1);
        case 3590: return fde_func_3590_0x16bb9c(a0, a1);
        case 3591: return fde_func_3591_0x16bbf4(a0, a1);
        case 3592: return fde_func_3592_0x16bc4c(a0, a1);
        case 3593: return fde_func_3593_0x16bca4(a0, a1);
        case 3594: return fde_func_3594_0x16bcfc(a0, a1);
        case 3595: return fde_func_3595_0x16bd54(a0, a1);
        case 3596: return fde_func_3596_0x16bdac(a0, a1);
        case 3597: return fde_func_3597_0x16be04(a0, a1);
        case 3598: return fde_func_3598_0x16be5c(a0, a1);
        case 3599: return fde_func_3599_0x16beb4(a0, a1);
        case 3600: return fde_func_3600_0x16bf0c(a0, a1);
        case 3601: return fde_func_3601_0x16bf64(a0, a1);
        case 3602: return fde_func_3602_0x16bfbc(a0, a1);
        case 3603: return fde_func_3603_0x16c014(a0, a1);
        case 3604: return fde_func_3604_0x16c06c(a0, a1);
        case 3605: return fde_func_3605_0x16c0c4(a0, a1);
        case 3606: return fde_func_3606_0x16c11c(a0, a1);
        case 3607: return fde_func_3607_0x16c174(a0, a1);
        case 3608: return fde_func_3608_0x16c1e8(a0, a1);
        case 3609: return fde_func_3609_0x16c258(a0, a1);
        case 3610: return fde_func_3610_0x16c2b8(a0, a1);
        case 3611: return fde_func_3611_0x16c318(a0, a1);
        case 3612: return fde_func_3612_0x16c374(a0, a1);
        case 3613: return fde_func_3613_0x16c3d0(a0, a1);
        case 3614: return fde_func_3614_0x16c42c(a0, a1);
        case 3615: return fde_func_3615_0x16c488(a0, a1);
        case 3616: return fde_func_3616_0x16c4e4(a0, a1);
        case 3617: return fde_func_3617_0x16c540(a0, a1);
        case 3618: return fde_func_3618_0x16c844(a0, a1);
        case 3619: return fde_func_3619_0x16c930(a0, a1);
        case 3620: return fde_func_3620_0x16c9d8(a0, a1);
        case 3621: return fde_func_3621_0x16ca48(a0, a1);
        case 3622: return fde_func_3622_0x16cc50(a0, a1);
        case 3623: return fde_func_3623_0x16cca8(a0, a1);
        case 3624: return fde_func_3624_0x16cce0(a0, a1);
        case 3625: return fde_func_3625_0x16d02c(a0, a1);
        case 3626: return fde_func_3626_0x16d180(a0, a1);
        case 3627: return fde_func_3627_0x16d1c0(a0, a1);
        case 3628: return fde_func_3628_0x16d2ec(a0, a1);
        case 3629: return fde_func_3629_0x16d35c(a0, a1);
        case 3630: return fde_func_3630_0x16d4a0(a0, a1);
        case 3631: return fde_func_3631_0x16d4f8(a0, a1);
        case 3632: return fde_func_3632_0x16d530(a0, a1);
        case 3633: return fde_func_3633_0x16d638(a0, a1);
        case 3634: return fde_func_3634_0x16d6bc(a0, a1);
        case 3635: return fde_func_3635_0x16d6e0(a0, a1);
        case 3636: return fde_func_3636_0x16d7a4(a0, a1);
        case 3637: return fde_func_3637_0x16d844(a0, a1);
        case 3638: return fde_func_3638_0x16d8c4(a0, a1);
        case 3639: return fde_func_3639_0x16d958(a0, a1);
        case 3640: return fde_func_3640_0x16da88(a0, a1);
        case 3641: return fde_func_3641_0x16dd2c(a0, a1);
        case 3642: return fde_func_3642_0x16de98(a0, a1);
        case 3643: return fde_func_3643_0x16dea4(a0, a1);
        case 3644: return fde_func_3644_0x16dedc(a0, a1);
        case 3645: return fde_func_3645_0x16df50(a0, a1);
        case 3646: return fde_func_3646_0x16dfc4(a0, a1);
        case 3647: return fde_func_3647_0x16e08c(a0, a1);
        case 3648: return fde_func_3648_0x16e180(a0, a1);
        case 3649: return fde_func_3649_0x16e1d4(a0, a1);
        case 3650: return fde_func_3650_0x16e254(a0, a1);
        case 3651: return fde_func_3651_0x16e2e4(a0, a1);
        case 3652: return fde_func_3652_0x16e430(a0, a1);
        case 3653: return fde_func_3653_0x16e5a0(a0, a1);
        case 3654: return fde_func_3654_0x16e6a0(a0, a1);
        case 3655: return fde_func_3655_0x16e920(a0, a1);
        case 3656: return fde_func_3656_0x16ea38(a0, a1);
        case 3657: return fde_func_3657_0x16ea78(a0, a1);
        case 3658: return fde_func_3658_0x16ea84(a0, a1);
        case 3659: return fde_func_3659_0x16eb08(a0, a1);
        case 3660: return fde_func_3660_0x16ebac(a0, a1);
        case 3661: return fde_func_3661_0x16ebb0(a0, a1);
        case 3662: return fde_func_3662_0x16ebf8(a0, a1);
        case 3663: return fde_func_3663_0x16ec88(a0, a1);
        case 3664: return fde_func_3664_0x16ed3c(a0, a1);
        case 3665: return fde_func_3665_0x16edd4(a0, a1);
        case 3666: return fde_func_3666_0x16ee6c(a0, a1);
        case 3667: return fde_func_3667_0x16efe4(a0, a1);
        case 3668: return fde_func_3668_0x16f1c4(a0, a1);
        case 3669: return fde_func_3669_0x16f350(a0, a1);
        case 3670: return fde_func_3670_0x16f43c(a0, a1);
        case 3671: return fde_func_3671_0x16f528(a0, a1);
        case 3672: return fde_func_3672_0x16f750(a0, a1);
        case 3673: return fde_func_3673_0x16f92c(a0, a1);
        case 3674: return fde_func_3674_0x16fa54(a0, a1);
        case 3675: return fde_func_3675_0x16fb3c(a0, a1);
        case 3676: return fde_func_3676_0x16fc90(a0, a1);
        case 3677: return fde_func_3677_0x16fd20(a0, a1);
        case 3678: return fde_func_3678_0x170204(a0, a1);
        case 3679: return fde_func_3679_0x17025c(a0, a1);
        case 3680: return fde_func_3680_0x170374(a0, a1);
        case 3681: return fde_func_3681_0x170510(a0, a1);
        case 3682: return fde_func_3682_0x170530(a0, a1);
        case 3683: return fde_func_3683_0x170540(a0, a1);
        case 3684: return fde_func_3684_0x170548(a0, a1);
        case 3685: return fde_func_3685_0x170550(a0, a1);
        case 3686: return fde_func_3686_0x17064c(a0, a1);
        case 3687: return fde_func_3687_0x170654(a0, a1);
        case 3688: return fde_func_3688_0x170750(a0, a1);
        case 3689: return fde_func_3689_0x17075c(a0, a1);
        case 3690: return fde_func_3690_0x1707c8(a0, a1);
        case 3691: return fde_func_3691_0x170814(a0, a1);
        case 3692: return fde_func_3692_0x170984(a0, a1);
        case 3693: return fde_func_3693_0x1709a8(a0, a1);
        case 3694: return fde_func_3694_0x170ae8(a0, a1);
        case 3695: return fde_func_3695_0x170b34(a0, a1);
        case 3696: return fde_func_3696_0x170be8(a0, a1);
        case 3697: return fde_func_3697_0x170c0c(a0, a1);
        case 3698: return fde_func_3698_0x170cc0(a0, a1);
        case 3699: return fde_func_3699_0x170cd0(a0, a1);
        case 3700: return fde_func_3700_0x170d0c(a0, a1);
        case 3701: return fde_func_3701_0x170d5c(a0, a1);
        case 3702: return fde_func_3702_0x170dd4(a0, a1);
        case 3703: return fde_func_3703_0x170e24(a0, a1);
        case 3704: return fde_func_3704_0x170e9c(a0, a1);
        case 3705: return fde_func_3705_0x170eec(a0, a1);
        case 3706: return fde_func_3706_0x170f64(a0, a1);
        case 3707: return fde_func_3707_0x170fd4(a0, a1);
        case 3708: return fde_func_3708_0x171040(a0, a1);
        case 3709: return fde_func_3709_0x1710d4(a0, a1);
        case 3710: return fde_func_3710_0x1710fc(a0, a1);
        case 3711: return fde_func_3711_0x171104(a0, a1);
        case 3712: return fde_func_3712_0x17120c(a0, a1);
        case 3713: return fde_func_3713_0x171214(a0, a1);
        case 3714: return fde_func_3714_0x17131c(a0, a1);
        case 3715: return fde_func_3715_0x171324(a0, a1);
        case 3716: return fde_func_3716_0x171454(a0, a1);
        case 3717: return fde_func_3717_0x17145c(a0, a1);
        case 3718: return fde_func_3718_0x17158c(a0, a1);
        case 3719: return fde_func_3719_0x171594(a0, a1);
        case 3720: return fde_func_3720_0x171684(a0, a1);
        case 3721: return fde_func_3721_0x17168c(a0, a1);
        case 3722: return fde_func_3722_0x17177c(a0, a1);
        case 3723: return fde_func_3723_0x171784(a0, a1);
        case 3724: return fde_func_3724_0x171874(a0, a1);
        case 3725: return fde_func_3725_0x17187c(a0, a1);
        case 3726: return fde_func_3726_0x17196c(a0, a1);
        case 3727: return fde_func_3727_0x171974(a0, a1);
        case 3728: return fde_func_3728_0x171a64(a0, a1);
        case 3729: return fde_func_3729_0x171a6c(a0, a1);
        case 3730: return fde_func_3730_0x171b5c(a0, a1);
        case 3731: return fde_func_3731_0x171b64(a0, a1);
        case 3732: return fde_func_3732_0x171bac(a0, a1);
        case 3733: return fde_func_3733_0x171bfc(a0, a1);
        case 3734: return fde_func_3734_0x171c74(a0, a1);
        case 3735: return fde_func_3735_0x171c80(a0, a1);
        case 3736: return fde_func_3736_0x171cec(a0, a1);
        case 3737: return fde_func_3737_0x171cf4(a0, a1);
        case 3738: return fde_func_3738_0x171d60(a0, a1);
        case 3739: return fde_func_3739_0x171d68(a0, a1);
        case 3740: return fde_func_3740_0x171e2c(a0, a1);
        case 3741: return fde_func_3741_0x171e7c(a0, a1);
        case 3742: return fde_func_3742_0x171fe8(a0, a1);
        case 3743: return fde_func_3743_0x172010(a0, a1);
        case 3744: return fde_func_3744_0x17214c(a0, a1);
        case 3745: return fde_func_3745_0x17219c(a0, a1);
        case 3746: return fde_func_3746_0x172250(a0, a1);
        case 3747: return fde_func_3747_0x172278(a0, a1);
        case 3748: return fde_func_3748_0x17232c(a0, a1);
        case 3749: return fde_func_3749_0x17237c(a0, a1);
        case 3750: return fde_func_3750_0x1723f4(a0, a1);
        case 3751: return fde_func_3751_0x172444(a0, a1);
        case 3752: return fde_func_3752_0x1724bc(a0, a1);
        case 3753: return fde_func_3753_0x17250c(a0, a1);
        case 3754: return fde_func_3754_0x172584(a0, a1);
        case 3755: return fde_func_3755_0x172590(a0, a1);
        case 3756: return fde_func_3756_0x1725fc(a0, a1);
        case 3757: return fde_func_3757_0x172690(a0, a1);
        case 3758: return fde_func_3758_0x172728(a0, a1);
        case 3759: return fde_func_3759_0x172960(a0, a1);
        case 3760: return fde_func_3760_0x1729dc(a0, a1);
        case 3761: return fde_func_3761_0x172a1c(a0, a1);
        case 3762: return fde_func_3762_0x172b00(a0, a1);
        case 3763: return fde_func_3763_0x172d90(a0, a1);
        case 3764: return fde_func_3764_0x172e78(a0, a1);
        case 3765: return fde_func_3765_0x172f84(a0, a1);
        case 3766: return fde_func_3766_0x172ff4(a0, a1);
        case 3767: return fde_func_3767_0x173178(a0, a1);
        case 3768: return fde_func_3768_0x1731f0(a0, a1);
        case 3769: return fde_func_3769_0x173224(a0, a1);
        case 3770: return fde_func_3770_0x173258(a0, a1);
        case 3771: return fde_func_3771_0x1732ec(a0, a1);
        case 3772: return fde_func_3772_0x173350(a0, a1);
        case 3773: return fde_func_3773_0x173358(a0, a1);
        case 3774: return fde_func_3774_0x1733b8(a0, a1);
        case 3775: return fde_func_3775_0x17352c(a0, a1);
        case 3776: return fde_func_3776_0x1735f8(a0, a1);
        case 3777: return fde_func_3777_0x173670(a0, a1);
        case 3778: return fde_func_3778_0x1736a4(a0, a1);
        case 3779: return fde_func_3779_0x17371c(a0, a1);
        case 3780: return fde_func_3780_0x173750(a0, a1);
        case 3781: return fde_func_3781_0x17384c(a0, a1);
        case 3782: return fde_func_3782_0x1738cc(a0, a1);
        case 3783: return fde_func_3783_0x173920(a0, a1);
        case 3784: return fde_func_3784_0x173a08(a0, a1);
        case 3785: return fde_func_3785_0x173a70(a0, a1);
        case 3786: return fde_func_3786_0x173ad0(a0, a1);
        case 3787: return fde_func_3787_0x173b2c(a0, a1);
        case 3788: return fde_func_3788_0x173bb4(a0, a1);
        case 3789: return fde_func_3789_0x173ca8(a0, a1);
        case 3790: return fde_func_3790_0x173d70(a0, a1);
        case 3791: return fde_func_3791_0x173df0(a0, a1);
        case 3792: return fde_func_3792_0x173f40(a0, a1);
        case 3793: return fde_func_3793_0x1740d4(a0, a1);
        case 3794: return fde_func_3794_0x174198(a0, a1);
        case 3795: return fde_func_3795_0x1742fc(a0, a1);
        case 3796: return fde_func_3796_0x17439c(a0, a1);
        case 3797: return fde_func_3797_0x1743a8(a0, a1);
        case 3798: return fde_func_3798_0x174404(a0, a1);
        case 3799: return fde_func_3799_0x1744c0(a0, a1);
        case 3800: return fde_func_3800_0x174540(a0, a1);
        case 3801: return fde_func_3801_0x1745b8(a0, a1);
        case 3802: return fde_func_3802_0x174664(a0, a1);
        case 3803: return fde_func_3803_0x174788(a0, a1);
        case 3804: return fde_func_3804_0x1749fc(a0, a1);
        case 3805: return fde_func_3805_0x174a70(a0, a1);
        case 3806: return fde_func_3806_0x174b68(a0, a1);
        case 3807: return fde_func_3807_0x174bc4(a0, a1);
        case 3808: return fde_func_3808_0x174c18(a0, a1);
        case 3809: return fde_func_3809_0x174c28(a0, a1);
        case 3810: return fde_func_3810_0x174dec(a0, a1);
        case 3811: return fde_func_3811_0x174ef0(a0, a1);
        case 3812: return fde_func_3812_0x174ef8(a0, a1);
        case 3813: return fde_func_3813_0x174f54(a0, a1);
        case 3814: return fde_func_3814_0x175040(a0, a1);
        case 3815: return fde_func_3815_0x175144(a0, a1);
        case 3816: return fde_func_3816_0x175298(a0, a1);
        case 3817: return fde_func_3817_0x175348(a0, a1);
        case 3818: return fde_func_3818_0x175368(a0, a1);
        case 3819: return fde_func_3819_0x175370(a0, a1);
        case 3820: return fde_func_3820_0x17545c(a0, a1);
        case 3821: return fde_func_3821_0x1759fc(a0, a1);
        case 3822: return fde_func_3822_0x176218(a0, a1);
        case 3823: return fde_func_3823_0x17670c(a0, a1);
        case 3824: return fde_func_3824_0x1767ac(a0, a1);
        case 3825: return fde_func_3825_0x176964(a0, a1);
        case 3826: return fde_func_3826_0x1769fc(a0, a1);
        case 3827: return fde_func_3827_0x176b30(a0, a1);
        case 3828: return fde_func_3828_0x176d60(a0, a1);
        case 3829: return fde_func_3829_0x176fb8(a0, a1);
        case 3830: return fde_func_3830_0x177288(a0, a1);
        case 3831: return fde_func_3831_0x177518(a0, a1);
        case 3832: return fde_func_3832_0x1777a4(a0, a1);
        case 3833: return fde_func_3833_0x1778a4(a0, a1);
        case 3834: return fde_func_3834_0x1778ec(a0, a1);
        case 3835: return fde_func_3835_0x177a38(a0, a1);
        case 3836: return fde_func_3836_0x177b64(a0, a1);
        case 3837: return fde_func_3837_0x177c2c(a0, a1);
        case 3838: return fde_func_3838_0x177d20(a0, a1);
        case 3839: return fde_func_3839_0x177e4c(a0, a1);
        case 3840: return fde_func_3840_0x177ec0(a0, a1);
        case 3841: return fde_func_3841_0x177f94(a0, a1);
        case 3842: return fde_func_3842_0x177f9c(a0, a1);
        case 3843: return fde_func_3843_0x1780cc(a0, a1);
        case 3844: return fde_func_3844_0x1780d8(a0, a1);
        case 3845: return fde_func_3845_0x178224(a0, a1);
        case 3846: return fde_func_3846_0x178310(a0, a1);
        case 3847: return fde_func_3847_0x178420(a0, a1);
        case 3848: return fde_func_3848_0x178460(a0, a1);
        case 3849: return fde_func_3849_0x178488(a0, a1);
        case 3850: return fde_func_3850_0x178494(a0, a1);
        case 3851: return fde_func_3851_0x1793fc(a0, a1);
        case 3852: return fde_func_3852_0x1794cc(a0, a1);
        case 3853: return fde_func_3853_0x1794d8(a0, a1);
        case 3854: return fde_func_3854_0x179608(a0, a1);
        case 3855: return fde_func_3855_0x17973c(a0, a1);
        default: return 0ULL;
    }
}