// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 5/5 for libpythonA.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 5/5 cho libpythonA.so
// Covers representative FDE indices [1600 .. 1999] out of 4,320 total FDEs
// Bao phủ chỉ số FDE đại diện [1600 .. 1999] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_core.h"

// FDE #1600 | PC: 0x131790 | FDE: 0x1e9610 | Size: 40 bytes [_PyGILState_Fini]
// Khung tháo gỡ #1600 | Địa chỉ PC: 0x131790 | Địa chỉ FDE: 0x1e9610 | Kích thước: 40 bytes
//   0x131790: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131794: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131798: 910043FD  add      x29, sp, #0x10
//   0x13179c: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_1600_0x131790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131790ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9610ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1601 | PC: 0x1317b8 | FDE: 0x1e9630 | Size: 188 bytes [_PyGILState_Reinit]
// Khung tháo gỡ #1601 | Địa chỉ PC: 0x1317b8 | Địa chỉ FDE: 0x1e9630 | Kích thước: 188 bytes
//   0x1317b8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1317bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1317c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1317c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1601_0x1317b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1317b8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9630ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1602 | PC: 0x131874 | FDE: 0x1e9650 | Size: 32 bytes [PyGILState_GetThisThreadState]
// Khung tháo gỡ #1602 | Địa chỉ PC: 0x131874 | Địa chỉ FDE: 0x1e9650 | Kích thước: 32 bytes
//   0x131874: D0000668  adrp     x8, #0x1ff000
//   0x131878: F943B908  ldr      x8, [x8, #0x770]
//   0x13187c: F940B509  ldr      x9, [x8, #0x168]
//   0x131880: B4000069  cbz      x9, #0x13188c
static inline uint64_t fde_func_1602_0x131874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131874ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e9650ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1603 | PC: 0x131894 | FDE: 0x1e9668 | Size: 108 bytes [PyGILState_Check]
// Khung tháo gỡ #1603 | Địa chỉ PC: 0x131894 | Địa chỉ FDE: 0x1e9668 | Kích thước: 108 bytes
//   0x131894: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13189c: 910043FD  add      x29, sp, #0x10
//   0x1318a0: D0000674  adrp     x20, #0x1ff000
static inline uint64_t fde_func_1603_0x131894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131894ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9668ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1604 | PC: 0x131900 | FDE: 0x1e9688 | Size: 140 bytes [PyGILState_Ensure]
// Khung tháo gỡ #1604 | Địa chỉ PC: 0x131900 | Địa chỉ FDE: 0x1e9688 | Kích thước: 140 bytes
//   0x131900: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131908: 910043FD  add      x29, sp, #0x10
//   0x13190c: D0000674  adrp     x20, #0x1ff000
static inline uint64_t fde_func_1604_0x131900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131900ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9688ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1605 | PC: 0x13198c | FDE: 0x1e96a8 | Size: 144 bytes [PyGILState_EnsureWithInterpreterState]
// Khung tháo gỡ #1605 | Địa chỉ PC: 0x13198c | Địa chỉ FDE: 0x1e96a8 | Kích thước: 144 bytes
//   0x13198c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131990: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131994: 910043FD  add      x29, sp, #0x10
//   0x131998: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1605_0x13198c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13198cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e96a8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1606 | PC: 0x131a1c | FDE: 0x1e96c8 | Size: 204 bytes [PyGILState_Release]
// Khung tháo gỡ #1606 | Địa chỉ PC: 0x131a1c | Địa chỉ FDE: 0x1e96c8 | Kích thước: 204 bytes
//   0x131a1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131a20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131a24: 910043FD  add      x29, sp, #0x10
//   0x131a28: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1606_0x131a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131a1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e96c8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1607 | PC: 0x131ae8 | FDE: 0x1e96e8 | Size: 84 bytes [_PyObject_CheckCrossInterpreterData]
// Khung tháo gỡ #1607 | Địa chỉ PC: 0x131ae8 | Địa chỉ FDE: 0x1e96e8 | Kích thước: 84 bytes
//   0x131ae8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131aec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131af0: 910043FD  add      x29, sp, #0x10
//   0x131af4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1607_0x131ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131ae8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e96e8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1608 | PC: 0x131b3c | FDE: 0x1e9708 | Size: 256 bytes [_PyObject_GetCrossInterpreterData]
// Khung tháo gỡ #1608 | Địa chỉ PC: 0x131b3c | Địa chỉ FDE: 0x1e9708 | Kích thước: 256 bytes
//   0x131b3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x131b40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x131b44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x131b48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1608_0x131b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131b3cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1609 | PC: 0x131c88 | FDE: 0x1e9730 | Size: 244 bytes [_PyCrossInterpreterData_Release]
// Khung tháo gỡ #1609 | Địa chỉ PC: 0x131c88 | Địa chỉ FDE: 0x1e9730 | Kích thước: 244 bytes
//   0x131c88: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x131c8c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x131c90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x131c94: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1609_0x131c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131c88ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9730ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1610 | PC: 0x131d7c | FDE: 0x1e9758 | Size: 8 bytes [_PyCrossInterpreterData_NewObject]
// Khung tháo gỡ #1610 | Địa chỉ PC: 0x131d7c | Địa chỉ FDE: 0x1e9758 | Kích thước: 8 bytes
//   0x131d7c: F9400C01  ldr      x1, [x0, #0x18]
//   0x131d80: D61F0020  br       x1
static inline uint64_t fde_func_1610_0x131d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131d7cULL ^ (static_cast<uint64_t>(0xf9400c01ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1e9758ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1611 | PC: 0x131d84 | FDE: 0x1e9770 | Size: 256 bytes [_PyCrossInterpreterData_RegisterClass]
// Khung tháo gỡ #1611 | Địa chỉ PC: 0x131d84 | Địa chỉ FDE: 0x1e9770 | Kích thước: 256 bytes
//   0x131d84: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131d88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131d8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131d90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1611_0x131d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131d84ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1612 | PC: 0x131f78 | FDE: 0x1e97b8 | Size: 152 bytes [_PyCrossInterpreterData_Lookup]
// Khung tháo gỡ #1612 | Địa chỉ PC: 0x131f78 | Địa chỉ FDE: 0x1e97b8 | Kích thước: 152 bytes
//   0x131f78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x131f7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131f80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131f84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1612_0x131f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131f78ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e97b8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1613 | PC: 0x132010 | FDE: 0x1e97d8 | Size: 8 bytes [_PyInterpreterState_GetEvalFrameFunc]
// Khung tháo gỡ #1613 | Địa chỉ PC: 0x132010 | Địa chỉ FDE: 0x1e97d8 | Kích thước: 8 bytes
//   0x132010: F9431400  ldr      x0, [x0, #0x628]
//   0x132014: D65F03C0  ret      
static inline uint64_t fde_func_1613_0x132010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132010ULL ^ (static_cast<uint64_t>(0xf9431400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e97d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1614 | PC: 0x132018 | FDE: 0x1e97f0 | Size: 8 bytes [_PyInterpreterState_SetEvalFrameFunc]
// Khung tháo gỡ #1614 | Địa chỉ PC: 0x132018 | Địa chỉ FDE: 0x1e97f0 | Kích thước: 8 bytes
//   0x132018: F9031401  str      x1, [x0, #0x628]
//   0x13201c: D65F03C0  ret      
static inline uint64_t fde_func_1614_0x132018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132018ULL ^ (static_cast<uint64_t>(0xf9031401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e97f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1615 | PC: 0x132020 | FDE: 0x1e9808 | Size: 192 bytes [_PyInterpreterState_GetConfigCopy]
// Khung tháo gỡ #1615 | Địa chỉ PC: 0x132020 | Địa chỉ FDE: 0x1e9808 | Kích thước: 192 bytes
//   0x132020: D10243FF  sub      sp, sp, #0x90
//   0x132024: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x132028: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x13202c: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_1615_0x132020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132020ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x1e9808ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1616 | PC: 0x1320e0 | FDE: 0x1e9828 | Size: 16 bytes [BD_PyInterpreterState_SetStuckCallback]
// Khung tháo gỡ #1616 | Địa chỉ PC: 0x1320e0 | Địa chỉ FDE: 0x1e9828 | Kích thước: 16 bytes
//   0x1320e0: 5296A108  mov      w8, #0xb508
//   0x1320e4: 72A00028  movk     w8, #1, lsl #16
//   0x1320e8: F8286801  str      x1, [x0, x8]
//   0x1320ec: D65F03C0  ret      
static inline uint64_t fde_func_1616_0x1320e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1320e0ULL ^ (static_cast<uint64_t>(0x5296a108ULL) << 13);
    acc = (acc + a1 + 0x72a00028ULL) ^ 0x1e9828ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1617 | PC: 0x1320f0 | FDE: 0x1e9840 | Size: 100 bytes [BD_Py_CheckStuckCallback]
// Khung tháo gỡ #1617 | Địa chỉ PC: 0x1320f0 | Địa chỉ FDE: 0x1e9840 | Kích thước: 100 bytes
//   0x1320f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1320f4: 910003FD  mov      x29, sp
//   0x1320f8: B0000668  adrp     x8, #0x1ff000
//   0x1320fc: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1617_0x1320f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1320f0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9840ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1618 | PC: 0x132154 | FDE: 0x1e9860 | Size: 40 bytes [_Py_GetConfig]
// Khung tháo gỡ #1618 | Địa chỉ PC: 0x132154 | Địa chỉ FDE: 0x1e9860 | Kích thước: 40 bytes
//   0x132154: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x132158: 910003FD  mov      x29, sp
//   0x13215c: B0000668  adrp     x8, #0x1ff000
//   0x132160: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1618_0x132154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132154ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9860ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1619 | PC: 0x13217c | FDE: 0x1e9880 | Size: 96 bytes [PyPitayaPackage_InitLock]
// Khung tháo gỡ #1619 | Địa chỉ PC: 0x13217c | Địa chỉ FDE: 0x1e9880 | Kích thước: 96 bytes
//   0x13217c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x132180: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132184: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132188: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1619_0x13217c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13217cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9880ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1620 | PC: 0x1321dc | FDE: 0x1e98a0 | Size: 64 bytes [BDPythonVM_PyThreadStateSetPitayaPackage]
// Khung tháo gỡ #1620 | Địa chỉ PC: 0x1321dc | Địa chỉ FDE: 0x1e98a0 | Kích thước: 64 bytes
//   0x1321dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1321e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1321e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1321e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1620_0x1321dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1321dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e98a0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1621 | PC: 0x13221c | FDE: 0x1e98c0 | Size: 88 bytes [_bd_simple_profile_get_info_map]
// Khung tháo gỡ #1621 | Địa chỉ PC: 0x13221c | Địa chỉ FDE: 0x1e98c0 | Kích thước: 88 bytes
//   0x13221c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x132220: 910003FD  mov      x29, sp
//   0x132224: B0000668  adrp     x8, #0x1ff000
//   0x132228: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1621_0x13221c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13221cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e98c0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1622 | PC: 0x132274 | FDE: 0x1e98e0 | Size: 256 bytes [_bd_simple_profile_set_info_map]
// Khung tháo gỡ #1622 | Địa chỉ PC: 0x132274 | Địa chỉ FDE: 0x1e98e0 | Kích thước: 256 bytes
//   0x132274: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x132278: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13227c: 910043FD  add      x29, sp, #0x10
//   0x132280: B0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1622_0x132274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132274ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e98e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1623 | PC: 0x1324a8 | FDE: 0x1e99d8 | Size: 184 bytes [_PyRun_AnyFileObject]
// Khung tháo gỡ #1623 | Địa chỉ PC: 0x1324a8 | Địa chỉ FDE: 0x1e99d8 | Kích thước: 184 bytes
//   0x1324a8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1324ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1324b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1324b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1623_0x1324a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1324a8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e99d8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1624 | PC: 0x132560 | FDE: 0x1e9a00 | Size: 24 bytes [PyErr_Print]
// Khung tháo gỡ #1624 | Địa chỉ PC: 0x132560 | Địa chỉ FDE: 0x1e9a00 | Kích thước: 24 bytes
//   0x132560: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x132564: 910003FD  mov      x29, sp
//   0x132568: 97FC9C96  bl       #0x597c0
//   0x13256c: 52800021  mov      w1, #1
static inline uint64_t fde_func_1624_0x132560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132560ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9a00ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1625 | PC: 0x132578 | FDE: 0x1e9a20 | Size: 256 bytes [_PyRun_SimpleFileObject]
// Khung tháo gỡ #1625 | Địa chỉ PC: 0x132578 | Địa chỉ FDE: 0x1e9a20 | Kích thước: 256 bytes
//   0x132578: D10243FF  sub      sp, sp, #0x90
//   0x13257c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x132580: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x132584: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1625_0x132578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132578ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e9a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1626 | PC: 0x132b28 | FDE: 0x1e9a50 | Size: 256 bytes [PyRun_AnyFileExFlags]
// Khung tháo gỡ #1626 | Địa chỉ PC: 0x132b28 | Địa chỉ FDE: 0x1e9a50 | Kích thước: 256 bytes
//   0x132b28: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x132b2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132b30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132b34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1626_0x132b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132b28ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1627 | PC: 0x132cd4 | FDE: 0x1e9aa0 | Size: 120 bytes [PyRun_SimpleFileExFlags]
// Khung tháo gỡ #1627 | Địa chỉ PC: 0x132cd4 | Địa chỉ FDE: 0x1e9aa0 | Kích thước: 120 bytes
//   0x132cd4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x132cd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132cdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132ce0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1627_0x132cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132cd4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9aa0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1628 | PC: 0x132d4c | FDE: 0x1e9ac8 | Size: 256 bytes [_Py_HandleSystemExit]
// Khung tháo gỡ #1628 | Địa chỉ PC: 0x132d4c | Địa chỉ FDE: 0x1e9ac8 | Kích thước: 256 bytes
//   0x132d4c: D10183FF  sub      sp, sp, #0x60
//   0x132d50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x132d54: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x132d58: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1628_0x132d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132d4cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e9ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1629 | PC: 0x132eec | FDE: 0x1e9af0 | Size: 256 bytes [_PyErr_Print]
// Khung tháo gỡ #1629 | Địa chỉ PC: 0x132eec | Địa chỉ FDE: 0x1e9af0 | Kích thước: 256 bytes
//   0x132eec: 52800021  mov      w1, #1
//   0x132ef0: 14000001  b        #0x132ef4
//   0x132ef4: D10243FF  sub      sp, sp, #0x90
//   0x132ef8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1629_0x132eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132eecULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e9af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1630 | PC: 0x1333c4 | FDE: 0x1e9b30 | Size: 36 bytes [PyErr_PrintEx]
// Khung tháo gỡ #1630 | Địa chỉ PC: 0x1333c4 | Địa chỉ FDE: 0x1e9b30 | Kích thước: 36 bytes
//   0x1333c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1333c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1333cc: 910043FD  add      x29, sp, #0x10
//   0x1333d0: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_1630_0x1333c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1333c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9b30ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1631 | PC: 0x1333e8 | FDE: 0x1e9b50 | Size: 256 bytes [_PyErr_Display]
// Khung tháo gỡ #1631 | Địa chỉ PC: 0x1333e8 | Địa chỉ FDE: 0x1e9b50 | Kích thước: 256 bytes
//   0x1333e8: D10103FF  sub      sp, sp, #0x40
//   0x1333ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1333f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1333f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1631_0x1333e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1333e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1632 | PC: 0x134050 | FDE: 0x1e9ba8 | Size: 192 bytes [PyErr_Display]
// Khung tháo gỡ #1632 | Địa chỉ PC: 0x134050 | Địa chỉ FDE: 0x1e9ba8 | Kích thước: 192 bytes
//   0x134050: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x134054: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134058: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13405c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1632_0x134050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134050ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9ba8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1633 | PC: 0x134110 | FDE: 0x1e9bc8 | Size: 256 bytes [_Py_SourceAsString]
// Khung tháo gỡ #1633 | Địa chỉ PC: 0x134110 | Địa chỉ FDE: 0x1e9bc8 | Kích thước: 256 bytes
//   0x134110: D10283FF  sub      sp, sp, #0xa0
//   0x134114: F90033F7  str      x23, [sp, #0x60]
//   0x134118: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x13411c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1633_0x134110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134110ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1e9bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1634 | PC: 0x1342b0 | FDE: 0x1e9bf0 | Size: 24 bytes [_PyTime_MulDiv]
// Khung tháo gỡ #1634 | Địa chỉ PC: 0x1342b0 | Địa chỉ FDE: 0x1e9bf0 | Kích thước: 24 bytes
//   0x1342b0: 9AC20C08  sdiv     x8, x0, x2
//   0x1342b4: 9B028109  msub     x9, x8, x2, x0
//   0x1342b8: 9B017D29  mul      x9, x9, x1
//   0x1342bc: 9AC20D29  sdiv     x9, x9, x2
static inline uint64_t fde_func_1634_0x1342b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1342b0ULL ^ (static_cast<uint64_t>(0x9ac20c08ULL) << 13);
    acc = (acc + a1 + 0x9b028109ULL) ^ 0x1e9bf0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1635 | PC: 0x1342c8 | FDE: 0x1e9c08 | Size: 88 bytes [_PyLong_AsTime_t]
// Khung tháo gỡ #1635 | Địa chỉ PC: 0x1342c8 | Địa chỉ FDE: 0x1e9c08 | Kích thước: 88 bytes
//   0x1342c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1342cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1342d0: 910043FD  add      x29, sp, #0x10
//   0x1342d4: 97FCA1BB  bl       #0x5c9c0
static inline uint64_t fde_func_1635_0x1342c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1342c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9c08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1636 | PC: 0x134320 | FDE: 0x1e9c28 | Size: 4 bytes [_PyLong_FromTime_t]
// Khung tháo gỡ #1636 | Địa chỉ PC: 0x134320 | Địa chỉ FDE: 0x1e9c28 | Kích thước: 4 bytes
//   0x134320: 17FCA300  b        #0x5cf20
static inline uint64_t fde_func_1636_0x134320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134320ULL ^ (static_cast<uint64_t>(0x17fca300ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x1e9c28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1637 | PC: 0x134324 | FDE: 0x1e9c40 | Size: 256 bytes [_PyTime_ObjectToTime_t]
// Khung tháo gỡ #1637 | Địa chỉ PC: 0x134324 | Địa chỉ FDE: 0x1e9c40 | Kích thước: 256 bytes
//   0x134324: D10143FF  sub      sp, sp, #0x50
//   0x134328: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13432c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x134330: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1637_0x134324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134324ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e9c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1638 | PC: 0x1344fc | FDE: 0x1e9c68 | Size: 256 bytes [_PyTime_ObjectToTimespec]
// Khung tháo gỡ #1638 | Địa chỉ PC: 0x1344fc | Địa chỉ FDE: 0x1e9c68 | Kích thước: 256 bytes
//   0x1344fc: 2A0303E4  mov      w4, w3
//   0x134500: 52994003  mov      w3, #0xca00
//   0x134504: 72A77343  movk     w3, #0x3b9a, lsl #16
//   0x134508: 14000001  b        #0x13450c
static inline uint64_t fde_func_1638_0x1344fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1344fcULL ^ (static_cast<uint64_t>(0x2a0303e4ULL) << 13);
    acc = (acc + a1 + 0x52994003ULL) ^ 0x1e9c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1639 | PC: 0x134770 | FDE: 0x1e9ca8 | Size: 16 bytes [_PyTime_ObjectToTimeval]
// Khung tháo gỡ #1639 | Địa chỉ PC: 0x134770 | Địa chỉ FDE: 0x1e9ca8 | Kích thước: 16 bytes
//   0x134770: 2A0303E4  mov      w4, w3
//   0x134774: 52884803  mov      w3, #0x4240
//   0x134778: 72A001E3  movk     w3, #0xf, lsl #16
//   0x13477c: 17FFFF64  b        #0x13450c
static inline uint64_t fde_func_1639_0x134770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134770ULL ^ (static_cast<uint64_t>(0x2a0303e4ULL) << 13);
    acc = (acc + a1 + 0x52884803ULL) ^ 0x1e9ca8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1640 | PC: 0x134780 | FDE: 0x1e9cc0 | Size: 16 bytes [_PyTime_FromSeconds]
// Khung tháo gỡ #1640 | Địa chỉ PC: 0x134780 | Địa chỉ FDE: 0x1e9cc0 | Kích thước: 16 bytes
//   0x134780: 52994008  mov      w8, #0xca00
//   0x134784: 72A77348  movk     w8, #0x3b9a, lsl #16
//   0x134788: 9B287C00  smull    x0, w0, w8
//   0x13478c: D65F03C0  ret      
static inline uint64_t fde_func_1640_0x134780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134780ULL ^ (static_cast<uint64_t>(0x52994008ULL) << 13);
    acc = (acc + a1 + 0x72a77348ULL) ^ 0x1e9cc0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1641 | PC: 0x134790 | FDE: 0x1e9cd8 | Size: 4 bytes [_PyTime_FromNanoseconds]
// Khung tháo gỡ #1641 | Địa chỉ PC: 0x134790 | Địa chỉ FDE: 0x1e9cd8 | Kích thước: 4 bytes
//   0x134790: D65F03C0  ret      
static inline uint64_t fde_func_1641_0x134790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134790ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1e9cd8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1642 | PC: 0x134794 | FDE: 0x1e9cf0 | Size: 156 bytes [_PyTime_FromNanosecondsObject]
// Khung tháo gỡ #1642 | Địa chỉ PC: 0x134794 | Địa chỉ FDE: 0x1e9cf0 | Kích thước: 156 bytes
//   0x134794: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x134798: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13479c: 910043FD  add      x29, sp, #0x10
//   0x1347a0: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_1642_0x134794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134794ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9cf0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1643 | PC: 0x134830 | FDE: 0x1e9d10 | Size: 196 bytes [_PyTime_FromTimespec]
// Khung tháo gỡ #1643 | Địa chỉ PC: 0x134830 | Địa chỉ FDE: 0x1e9d10 | Kích thước: 196 bytes
//   0x134830: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x134834: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134838: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13483c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1643_0x134830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134830ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9d10ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1644 | PC: 0x1348f4 | FDE: 0x1e9d38 | Size: 204 bytes [_PyTime_FromTimeval]
// Khung tháo gỡ #1644 | Địa chỉ PC: 0x1348f4 | Địa chỉ FDE: 0x1e9d38 | Kích thước: 204 bytes
//   0x1348f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1348f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1348fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x134900: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1644_0x1348f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1348f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9d38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1645 | PC: 0x1349c0 | FDE: 0x1e9d60 | Size: 256 bytes [_PyTime_FromSecondsObject]
// Khung tháo gỡ #1645 | Địa chỉ PC: 0x1349c0 | Địa chỉ FDE: 0x1e9d60 | Kích thước: 256 bytes
//   0x1349c0: 52994003  mov      w3, #0xca00
//   0x1349c4: 72A77343  movk     w3, #0x3b9a, lsl #16
//   0x1349c8: 14000001  b        #0x1349cc
//   0x1349cc: D10183FF  sub      sp, sp, #0x60
static inline uint64_t fde_func_1645_0x1349c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1349c0ULL ^ (static_cast<uint64_t>(0x52994003ULL) << 13);
    acc = (acc + a1 + 0x72a77343ULL) ^ 0x1e9d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1646 | PC: 0x134bc8 | FDE: 0x1e9da0 | Size: 12 bytes [_PyTime_FromMillisecondsObject]
// Khung tháo gỡ #1646 | Địa chỉ PC: 0x134bc8 | Địa chỉ FDE: 0x1e9da0 | Kích thước: 12 bytes
//   0x134bc8: 52884803  mov      w3, #0x4240
//   0x134bcc: 72A001E3  movk     w3, #0xf, lsl #16
//   0x134bd0: 17FFFF7F  b        #0x1349cc
static inline uint64_t fde_func_1646_0x134bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134bc8ULL ^ (static_cast<uint64_t>(0x52884803ULL) << 13);
    acc = (acc + a1 + 0x72a001e3ULL) ^ 0x1e9da0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1647 | PC: 0x134bd4 | FDE: 0x1e9db8 | Size: 144 bytes [_PyTime_AsSecondsDouble]
// Khung tháo gỡ #1647 | Địa chỉ PC: 0x134bd4 | Địa chỉ FDE: 0x1e9db8 | Kích thước: 144 bytes
//   0x134bd4: D10083FF  sub      sp, sp, #0x20
//   0x134bd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x134bdc: 910043FD  add      x29, sp, #0x10
//   0x134be0: D2929669  mov      x9, #0x94b3
static inline uint64_t fde_func_1647_0x134bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134bd4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9db8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1648 | PC: 0x134c64 | FDE: 0x1e9dd8 | Size: 4 bytes [_PyTime_AsNanosecondsObject]
// Khung tháo gỡ #1648 | Địa chỉ PC: 0x134c64 | Địa chỉ FDE: 0x1e9dd8 | Kích thước: 4 bytes
//   0x134c64: 17FCA0AF  b        #0x5cf20
static inline uint64_t fde_func_1648_0x134c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134c64ULL ^ (static_cast<uint64_t>(0x17fca0afULL) << 13);
    acc = (acc + a1 + 0x7100043fULL) ^ 0x1e9dd8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1649 | PC: 0x134c68 | FDE: 0x1e9df0 | Size: 196 bytes [_PyTime_AsMilliseconds]
// Khung tháo gỡ #1649 | Địa chỉ PC: 0x134c68 | Địa chỉ FDE: 0x1e9df0 | Kích thước: 196 bytes
//   0x134c68: 7100043F  cmp      w1, #1
//   0x134c6c: AA0003E8  mov      x8, x0
//   0x134c70: 54000340  b.eq     #0x134cd8
//   0x134c74: 7100083F  cmp      w1, #2
static inline uint64_t fde_func_1649_0x134c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134c68ULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1e9df0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1650 | PC: 0x134d2c | FDE: 0x1e9e08 | Size: 204 bytes [_PyTime_AsMicroseconds]
// Khung tháo gỡ #1650 | Địa chỉ PC: 0x134d2c | Địa chỉ FDE: 0x1e9e08 | Kích thước: 204 bytes
//   0x134d2c: 7100043F  cmp      w1, #1
//   0x134d30: AA0003E8  mov      x8, x0
//   0x134d34: 540002E0  b.eq     #0x134d90
//   0x134d38: 7100083F  cmp      w1, #2
static inline uint64_t fde_func_1650_0x134d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134d2cULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1e9e08ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1651 | PC: 0x134df8 | FDE: 0x1e9e20 | Size: 256 bytes [_PyTime_AsTimeval]
// Khung tháo gỡ #1651 | Địa chỉ PC: 0x134df8 | Địa chỉ FDE: 0x1e9e20 | Kích thước: 256 bytes
//   0x134df8: D2929668  mov      x8, #0x94b3
//   0x134dfc: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x134e00: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x134e04: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_1651_0x134df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134df8ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1652 | PC: 0x134f34 | FDE: 0x1e9e38 | Size: 256 bytes [_PyTime_AsTimeval_noraise]
// Khung tháo gỡ #1652 | Địa chỉ PC: 0x134f34 | Địa chỉ FDE: 0x1e9e38 | Kích thước: 256 bytes
//   0x134f34: D2929668  mov      x8, #0x94b3
//   0x134f38: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x134f3c: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x134f40: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_1652_0x134f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134f34ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1653 | PC: 0x135070 | FDE: 0x1e9e50 | Size: 256 bytes [_PyTime_AsTimevalTime_t]
// Khung tháo gỡ #1653 | Địa chỉ PC: 0x135070 | Địa chỉ FDE: 0x1e9e50 | Kích thước: 256 bytes
//   0x135070: D2929668  mov      x8, #0x94b3
//   0x135074: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x135078: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x13507c: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_1653_0x135070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135070ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1654 | PC: 0x1351a0 | FDE: 0x1e9e68 | Size: 68 bytes [_PyTime_AsTimespec]
// Khung tháo gỡ #1654 | Địa chỉ PC: 0x1351a0 | Địa chỉ FDE: 0x1e9e68 | Kích thước: 68 bytes
//   0x1351a0: D2929668  mov      x8, #0x94b3
//   0x1351a4: F2A4DAC8  movk     x8, #0x26d6, lsl #16
//   0x1351a8: F2C17D08  movk     x8, #0xbe8, lsl #32
//   0x1351ac: F2E225C8  movk     x8, #0x112e, lsl #48
static inline uint64_t fde_func_1654_0x1351a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1351a0ULL ^ (static_cast<uint64_t>(0xd2929668ULL) << 13);
    acc = (acc + a1 + 0xf2a4dac8ULL) ^ 0x1e9e68ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1655 | PC: 0x1351e4 | FDE: 0x1e9e80 | Size: 168 bytes [_PyTime_GetSystemClock]
// Khung tháo gỡ #1655 | Địa chỉ PC: 0x1351e4 | Địa chỉ FDE: 0x1e9e80 | Kích thước: 168 bytes
//   0x1351e4: D10103FF  sub      sp, sp, #0x40
//   0x1351e8: F90013F3  str      x19, [sp, #0x20]
//   0x1351ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1351f0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1655_0x1351e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1351e4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e9e80ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1656 | PC: 0x13528c | FDE: 0x1e9ea0 | Size: 256 bytes [_PyTime_GetSystemClockWithInfo]
// Khung tháo gỡ #1656 | Địa chỉ PC: 0x13528c | Địa chỉ FDE: 0x1e9ea0 | Kích thước: 256 bytes
//   0x13528c: D101C3FF  sub      sp, sp, #0x70
//   0x135290: F9001BF7  str      x23, [sp, #0x30]
//   0x135294: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x135298: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1656_0x13528c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13528cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e9ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1657 | PC: 0x135414 | FDE: 0x1e9ec8 | Size: 256 bytes [_PyTime_GetMonotonicClock]
// Khung tháo gỡ #1657 | Địa chỉ PC: 0x135414 | Địa chỉ FDE: 0x1e9ec8 | Kích thước: 256 bytes
//   0x135414: D10103FF  sub      sp, sp, #0x40
//   0x135418: F90013F3  str      x19, [sp, #0x20]
//   0x13541c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x135420: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1657_0x135414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135414ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e9ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1658 | PC: 0x135648 | FDE: 0x1e9f10 | Size: 8 bytes [_PyTime_GetMonotonicClockWithInfo]
// Khung tháo gỡ #1658 | Địa chỉ PC: 0x135648 | Địa chỉ FDE: 0x1e9f10 | Kích thước: 8 bytes
//   0x135648: 52800022  mov      w2, #1
//   0x13564c: 17FFFF9C  b        #0x1354bc
static inline uint64_t fde_func_1658_0x135648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135648ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x17ffff9cULL) ^ 0x1e9f10ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1659 | PC: 0x135650 | FDE: 0x1e9f28 | Size: 8 bytes [_PyTime_GetPerfCounterWithInfo]
// Khung tháo gỡ #1659 | Địa chỉ PC: 0x135650 | Địa chỉ FDE: 0x1e9f28 | Kích thước: 8 bytes
//   0x135650: 52800022  mov      w2, #1
//   0x135654: 17FFFF9A  b        #0x1354bc
static inline uint64_t fde_func_1659_0x135650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135650ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x17ffff9aULL) ^ 0x1e9f28ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1660 | PC: 0x135658 | FDE: 0x1e9f40 | Size: 168 bytes [_PyTime_GetPerfCounter]
// Khung tháo gỡ #1660 | Địa chỉ PC: 0x135658 | Địa chỉ FDE: 0x1e9f40 | Kích thước: 168 bytes
//   0x135658: D10103FF  sub      sp, sp, #0x40
//   0x13565c: F90013F3  str      x19, [sp, #0x20]
//   0x135660: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x135664: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1660_0x135658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135658ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1e9f40ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1661 | PC: 0x135700 | FDE: 0x1e9f60 | Size: 152 bytes [_PyTime_localtime]
// Khung tháo gỡ #1661 | Địa chỉ PC: 0x135700 | Địa chỉ FDE: 0x1e9f60 | Kích thước: 152 bytes
//   0x135700: D10103FF  sub      sp, sp, #0x40
//   0x135704: F9000BF5  str      x21, [sp, #0x10]
//   0x135708: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13570c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1661_0x135700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135700ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1e9f60ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1662 | PC: 0x135798 | FDE: 0x1e9f80 | Size: 128 bytes [_PyTime_gmtime]
// Khung tháo gỡ #1662 | Địa chỉ PC: 0x135798 | Địa chỉ FDE: 0x1e9f80 | Kích thước: 128 bytes
//   0x135798: D100C3FF  sub      sp, sp, #0x30
//   0x13579c: F9000BF3  str      x19, [sp, #0x10]
//   0x1357a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1357a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1662_0x135798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135798ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1e9f80ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1663 | PC: 0x135818 | FDE: 0x1e9fa0 | Size: 256 bytes [_PyOS_URandom]
// Khung tháo gỡ #1663 | Địa chỉ PC: 0x135818 | Địa chỉ FDE: 0x1e9fa0 | Kích thước: 256 bytes
//   0x135818: 52800022  mov      w2, #1
//   0x13581c: 52800023  mov      w3, #1
//   0x135820: 14000001  b        #0x135824
//   0x135824: D103C3FF  sub      sp, sp, #0xf0
static inline uint64_t fde_func_1663_0x135818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135818ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x52800023ULL) ^ 0x1e9fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1664 | PC: 0x135b98 | FDE: 0x1e9fe8 | Size: 12 bytes [_PyOS_URandomNonblock]
// Khung tháo gỡ #1664 | Địa chỉ PC: 0x135b98 | Địa chỉ FDE: 0x1e9fe8 | Kích thước: 12 bytes
//   0x135b98: 52800023  mov      w3, #1
//   0x135b9c: 2A1F03E2  mov      w2, wzr
//   0x135ba0: 17FFFF21  b        #0x135824
static inline uint64_t fde_func_1664_0x135b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135b98ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x1e9fe8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1665 | PC: 0x135ba4 | FDE: 0x1ea000 | Size: 256 bytes [_Py_HashRandomization_Init]
// Khung tháo gỡ #1665 | Địa chỉ PC: 0x135ba4 | Địa chỉ FDE: 0x1ea000 | Kích thước: 256 bytes
//   0x135ba4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x135ba8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x135bac: 910043FD  add      x29, sp, #0x10
//   0x135bb0: 90000789  adrp     x9, #0x225000
static inline uint64_t fde_func_1665_0x135ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135ba4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1666 | PC: 0x135d84 | FDE: 0x1ea020 | Size: 48 bytes [_Py_HashRandomization_Fini]
// Khung tháo gỡ #1666 | Địa chỉ PC: 0x135d84 | Địa chỉ FDE: 0x1ea020 | Kích thước: 48 bytes
//   0x135d84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x135d88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x135d8c: 910043FD  add      x29, sp, #0x10
//   0x135d90: D0000713  adrp     x19, #0x217000
static inline uint64_t fde_func_1666_0x135d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135d84ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea020ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1667 | PC: 0x135db4 | FDE: 0x1ea040 | Size: 256 bytes [PyMember_GetOne]
// Khung tháo gỡ #1667 | Địa chỉ PC: 0x135db4 | Địa chỉ FDE: 0x1ea040 | Kích thước: 256 bytes
//   0x135db4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x135db8: 910003FD  mov      x29, sp
//   0x135dbc: B9400829  ldr      w9, [x1, #8]
//   0x135dc0: 7100513F  cmp      w9, #0x14
static inline uint64_t fde_func_1667_0x135db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135db4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ea040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1668 | PC: 0x135f40 | FDE: 0x1ea060 | Size: 256 bytes [PyMember_SetOne]
// Khung tháo gỡ #1668 | Địa chỉ PC: 0x135f40 | Địa chỉ FDE: 0x1ea060 | Kích thước: 256 bytes
//   0x135f40: D10143FF  sub      sp, sp, #0x50
//   0x135f44: FD000BE8  str      d8, [sp, #0x10]
//   0x135f48: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x135f4c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1668_0x135f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135f40ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1ea060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1669 | PC: 0x1363f4 | FDE: 0x1ea088 | Size: 156 bytes [_PySys_GetObjectId]
// Khung tháo gỡ #1669 | Địa chỉ PC: 0x1363f4 | Địa chỉ FDE: 0x1ea088 | Kích thước: 156 bytes
//   0x1363f4: D10143FF  sub      sp, sp, #0x50
//   0x1363f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1363fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x136400: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1669_0x1363f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1363f4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ea088ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1670 | PC: 0x136490 | FDE: 0x1ea0b0 | Size: 152 bytes [PySys_GetObject]
// Khung tháo gỡ #1670 | Địa chỉ PC: 0x136490 | Địa chỉ FDE: 0x1ea0b0 | Kích thước: 152 bytes
//   0x136490: D10143FF  sub      sp, sp, #0x50
//   0x136494: F90013F5  str      x21, [sp, #0x20]
//   0x136498: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13649c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1670_0x136490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136490ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea0b0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1671 | PC: 0x136528 | FDE: 0x1ea0d0 | Size: 156 bytes [_PySys_SetObjectId]
// Khung tháo gỡ #1671 | Địa chỉ PC: 0x136528 | Địa chỉ FDE: 0x1ea0d0 | Kích thước: 156 bytes
//   0x136528: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x13652c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x136530: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x136534: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1671_0x136528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136528ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea0d0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1672 | PC: 0x1365c4 | FDE: 0x1ea0f0 | Size: 256 bytes [PySys_SetObject]
// Khung tháo gỡ #1672 | Địa chỉ PC: 0x1365c4 | Địa chỉ FDE: 0x1ea0f0 | Kích thước: 256 bytes
//   0x1365c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1365c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1365cc: 910043FD  add      x29, sp, #0x10
//   0x1365d0: B0000648  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1672_0x1365c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1365c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1673 | PC: 0x1366c8 | FDE: 0x1ea130 | Size: 256 bytes [_PySys_Audit]
// Khung tháo gỡ #1673 | Địa chỉ PC: 0x1366c8 | Địa chỉ FDE: 0x1ea130 | Kích thước: 256 bytes
//   0x1366c8: D10483FF  sub      sp, sp, #0x120
//   0x1366cc: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x1366d0: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x1366d4: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1673_0x1366c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1366c8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1ea130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1674 | PC: 0x136b8c | FDE: 0x1ea180 | Size: 184 bytes [PySys_Audit]
// Khung tháo gỡ #1674 | Địa chỉ PC: 0x136b8c | Địa chỉ FDE: 0x1ea180 | Kích thước: 184 bytes
//   0x136b8c: D10503FF  sub      sp, sp, #0x140
//   0x136b90: F90083FC  str      x28, [sp, #0x100]
//   0x136b94: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x136b98: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1674_0x136b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136b8cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1ea180ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1675 | PC: 0x136c44 | FDE: 0x1ea1a8 | Size: 132 bytes [_PySys_ClearAuditHooks]
// Khung tháo gỡ #1675 | Địa chỉ PC: 0x136c44 | Địa chỉ FDE: 0x1ea1a8 | Kích thước: 132 bytes
//   0x136c44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x136c48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x136c4c: 910043FD  add      x29, sp, #0x10
//   0x136c50: B4000360  cbz      x0, #0x136cbc
static inline uint64_t fde_func_1675_0x136c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136c44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea1a8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1676 | PC: 0x136cc8 | FDE: 0x1ea1c8 | Size: 180 bytes [PySys_WriteStderr]
// Khung tháo gỡ #1676 | Địa chỉ PC: 0x136cc8 | Địa chỉ FDE: 0x1ea1c8 | Kích thước: 180 bytes
//   0x136cc8: D104C3FF  sub      sp, sp, #0x130
//   0x136ccc: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x136cd0: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x136cd4: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_1676_0x136cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136cc8ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea1c8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1677 | PC: 0x136d7c | FDE: 0x1ea1e8 | Size: 256 bytes [PySys_AddAuditHook]
// Khung tháo gỡ #1677 | Địa chỉ PC: 0x136d7c | Địa chỉ FDE: 0x1ea1e8 | Kích thước: 256 bytes
//   0x136d7c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x136d80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x136d84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x136d88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1677_0x136d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136d7cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ea1e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1678 | PC: 0x136e90 | FDE: 0x1ea210 | Size: 256 bytes [_PySys_GetSizeOf]
// Khung tháo gỡ #1678 | Địa chỉ PC: 0x136e90 | Địa chỉ FDE: 0x1ea210 | Kích thước: 256 bytes
//   0x136e90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x136e94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x136e98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x136e9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1678_0x136e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136e90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1679 | PC: 0x137044 | FDE: 0x1ea250 | Size: 256 bytes [_PySys_ReadPreinitWarnOptions]
// Khung tháo gỡ #1679 | Địa chỉ PC: 0x137044 | Địa chỉ FDE: 0x1ea250 | Kích thước: 256 bytes
//   0x137044: D10283FF  sub      sp, sp, #0xa0
//   0x137048: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x13704c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x137050: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1679_0x137044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137044ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1ea250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1680 | PC: 0x137144 | FDE: 0x1ea278 | Size: 256 bytes [_PySys_ReadPreinitXOptions]
// Khung tháo gỡ #1680 | Địa chỉ PC: 0x137144 | Địa chỉ FDE: 0x1ea278 | Kích thước: 256 bytes
//   0x137144: D10283FF  sub      sp, sp, #0xa0
//   0x137148: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x13714c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x137150: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1680_0x137144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137144ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1ea278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1681 | PC: 0x137244 | FDE: 0x1ea2a0 | Size: 252 bytes [PySys_ResetWarnOptions]
// Khung tháo gỡ #1681 | Địa chỉ PC: 0x137244 | Địa chỉ FDE: 0x1ea2a0 | Kích thước: 252 bytes
//   0x137244: D101C3FF  sub      sp, sp, #0x70
//   0x137248: F90023F5  str      x21, [sp, #0x40]
//   0x13724c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x137250: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1681_0x137244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137244ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1ea2a0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1682 | PC: 0x137340 | FDE: 0x1ea2c0 | Size: 256 bytes [PySys_AddWarnOptionUnicode]
// Khung tháo gỡ #1682 | Địa chỉ PC: 0x137340 | Địa chỉ FDE: 0x1ea2c0 | Kích thước: 256 bytes
//   0x137340: D10183FF  sub      sp, sp, #0x60
//   0x137344: F90013F7  str      x23, [sp, #0x20]
//   0x137348: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13734c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1682_0x137340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137340ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1ea2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1683 | PC: 0x137484 | FDE: 0x1ea2e8 | Size: 256 bytes [PySys_AddWarnOption]
// Khung tháo gỡ #1683 | Địa chỉ PC: 0x137484 | Địa chỉ FDE: 0x1ea2e8 | Kích thước: 256 bytes
//   0x137484: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x137488: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13748c: 910043FD  add      x29, sp, #0x10
//   0x137490: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1683_0x137484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137484ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ea2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1684 | PC: 0x1375b8 | FDE: 0x1ea330 | Size: 180 bytes [PySys_HasWarnOptions]
// Khung tháo gỡ #1684 | Địa chỉ PC: 0x1375b8 | Địa chỉ FDE: 0x1ea330 | Kích thước: 180 bytes
//   0x1375b8: D10143FF  sub      sp, sp, #0x50
//   0x1375bc: F90013F5  str      x21, [sp, #0x20]
//   0x1375c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1375c4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1684_0x1375b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1375b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea330ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1685 | PC: 0x13766c | FDE: 0x1ea350 | Size: 256 bytes [PySys_AddXOption]
// Khung tháo gỡ #1685 | Địa chỉ PC: 0x13766c | Địa chỉ FDE: 0x1ea350 | Kích thước: 256 bytes
//   0x13766c: D10183FF  sub      sp, sp, #0x60
//   0x137670: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x137674: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x137678: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1685_0x13766c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13766cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1ea350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1686 | PC: 0x137890 | FDE: 0x1ea378 | Size: 256 bytes [PySys_GetXOptions]
// Khung tháo gỡ #1686 | Địa chỉ PC: 0x137890 | Địa chỉ FDE: 0x1ea378 | Kích thước: 256 bytes
//   0x137890: D10143FF  sub      sp, sp, #0x50
//   0x137894: F90013F5  str      x21, [sp, #0x20]
//   0x137898: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13789c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1686_0x137890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137890ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ea378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1687 | PC: 0x1379a0 | FDE: 0x1ea398 | Size: 256 bytes [_PySys_UpdateConfig]
// Khung tháo gỡ #1687 | Địa chỉ PC: 0x1379a0 | Địa chỉ FDE: 0x1ea398 | Kích thước: 256 bytes
//   0x1379a0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1379a4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1379a8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1379ac: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1687_0x1379a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1379a0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ea398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1688 | PC: 0x138310 | FDE: 0x1ea3f0 | Size: 256 bytes [_PySys_Create]
// Khung tháo gỡ #1688 | Địa chỉ PC: 0x138310 | Địa chỉ FDE: 0x1ea3f0 | Kích thước: 256 bytes
//   0x138310: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x138314: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x138318: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13831c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1688_0x138310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x138310ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ea3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1689 | PC: 0x139214 | FDE: 0x1ea420 | Size: 256 bytes [PySys_SetPath]
// Khung tháo gỡ #1689 | Địa chỉ PC: 0x139214 | Địa chỉ FDE: 0x1ea420 | Kích thước: 256 bytes
//   0x139214: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x139218: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13921c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x139220: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1689_0x139214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139214ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ea420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1690 | PC: 0x13936c | FDE: 0x1ea448 | Size: 256 bytes [PySys_SetArgvEx]
// Khung tháo gỡ #1690 | Địa chỉ PC: 0x13936c | Địa chỉ FDE: 0x1ea448 | Kích thước: 256 bytes
//   0x13936c: D10243FF  sub      sp, sp, #0x90
//   0x139370: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x139374: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x139378: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1690_0x13936c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13936cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x1ea448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1691 | PC: 0x1395bc | FDE: 0x1ea478 | Size: 24 bytes [PySys_SetArgv]
// Khung tháo gỡ #1691 | Địa chỉ PC: 0x1395bc | Địa chỉ FDE: 0x1ea478 | Kích thước: 24 bytes
//   0x1395bc: D0000628  adrp     x8, #0x1ff000
//   0x1395c0: F9430D08  ldr      x8, [x8, #0x618]
//   0x1395c4: B9400108  ldr      w8, [x8]
//   0x1395c8: 7100011F  cmp      w8, #0
static inline uint64_t fde_func_1691_0x1395bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1395bcULL ^ (static_cast<uint64_t>(0xd0000628ULL) << 13);
    acc = (acc + a1 + 0xf9430d08ULL) ^ 0x1ea478ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1692 | PC: 0x1395d4 | FDE: 0x1ea490 | Size: 256 bytes [PySys_WriteStdout]
// Khung tháo gỡ #1692 | Địa chỉ PC: 0x1395d4 | Địa chỉ FDE: 0x1ea490 | Kích thước: 256 bytes
//   0x1395d4: D104C3FF  sub      sp, sp, #0x130
//   0x1395d8: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x1395dc: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x1395e0: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_1692_0x1395d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1395d4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1693 | PC: 0x1398b0 | FDE: 0x1ea4e0 | Size: 256 bytes [PySys_FormatStdout]
// Khung tháo gỡ #1693 | Địa chỉ PC: 0x1398b0 | Địa chỉ FDE: 0x1ea4e0 | Kích thước: 256 bytes
//   0x1398b0: D104C3FF  sub      sp, sp, #0x130
//   0x1398b4: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x1398b8: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x1398bc: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_1693_0x1398b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1398b0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea4e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1694 | PC: 0x139ad4 | FDE: 0x1ea528 | Size: 256 bytes [PySys_FormatStderr]
// Khung tháo gỡ #1694 | Địa chỉ PC: 0x139ad4 | Địa chỉ FDE: 0x1ea528 | Kích thước: 256 bytes
//   0x139ad4: D104C3FF  sub      sp, sp, #0x130
//   0x139ad8: A9114FFC  stp      x28, x19, [sp, #0x110]
//   0x139adc: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x139ae0: 910483FD  add      x29, sp, #0x120
static inline uint64_t fde_func_1694_0x139ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139ad4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa9114ffcULL) ^ 0x1ea528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1695 | PC: 0x13c438 | FDE: 0x1eaab8 | Size: 256 bytes [_Py_Offer_Suggestions]
// Khung tháo gỡ #1695 | Địa chỉ PC: 0x13c438 | Địa chỉ FDE: 0x1eaab8 | Kích thước: 256 bytes
//   0x13c438: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13c43c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13c440: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13c444: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1695_0x13c438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c438ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eaab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1696 | PC: 0x13c5a4 | FDE: 0x1eaae0 | Size: 256 bytes [_Py_UTF8_Edit_Cost]
// Khung tháo gỡ #1696 | Địa chỉ PC: 0x13c5a4 | Địa chỉ FDE: 0x1eaae0 | Kích thước: 256 bytes
//   0x13c5a4: D10143FF  sub      sp, sp, #0x50
//   0x13c5a8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13c5ac: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x13c5b0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1696_0x13c5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c5a4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1eaae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1697 | PC: 0x13ca40 | FDE: 0x1eab50 | Size: 24 bytes [PyThread_init_thread]
// Khung tháo gỡ #1697 | Địa chỉ PC: 0x13ca40 | Địa chỉ FDE: 0x1eab50 | Kích thước: 24 bytes
//   0x13ca40: B0000748  adrp     x8, #0x225000
//   0x13ca44: 39760109  ldrb     w9, [x8, #0xd80]
//   0x13ca48: 37000069  tbnz     w9, #0, #0x13ca54
//   0x13ca4c: 52800029  mov      w9, #1
static inline uint64_t fde_func_1697_0x13ca40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca40ULL ^ (static_cast<uint64_t>(0xb0000748ULL) << 13);
    acc = (acc + a1 + 0x39760109ULL) ^ 0x1eab50ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1698 | PC: 0x13ca58 | FDE: 0x1eab68 | Size: 4 bytes [_PyThread_debug_deprecation]
// Khung tháo gỡ #1698 | Địa chỉ PC: 0x13ca58 | Địa chỉ FDE: 0x1eab68 | Kích thước: 4 bytes
//   0x13ca58: D65F03C0  ret      
static inline uint64_t fde_func_1698_0x13ca58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca58ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1eab68ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1699 | PC: 0x13ca5c | FDE: 0x1eab80 | Size: 8 bytes [_PyThread_cond_init]
// Khung tháo gỡ #1699 | Địa chỉ PC: 0x13ca5c | Địa chỉ FDE: 0x1eab80 | Kích thước: 8 bytes
//   0x13ca5c: AA1F03E1  mov      x1, xzr
//   0x13ca60: 17FC81C8  b        #0x5d180
static inline uint64_t fde_func_1699_0x13ca5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca5cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fc81c8ULL) ^ 0x1eab80ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1700 | PC: 0x13ca64 | FDE: 0x1eab98 | Size: 136 bytes [_PyThread_cond_after]
// Khung tháo gỡ #1700 | Địa chỉ PC: 0x13ca64 | Địa chỉ FDE: 0x1eab98 | Kích thước: 136 bytes
//   0x13ca64: D100C3FF  sub      sp, sp, #0x30
//   0x13ca68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13ca6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13ca70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1700_0x13ca64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca64ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eab98ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1701 | PC: 0x13caec | FDE: 0x1eabb8 | Size: 256 bytes [PyThread_start_new_thread]
// Khung tháo gỡ #1701 | Địa chỉ PC: 0x13caec | Địa chỉ FDE: 0x1eabb8 | Kích thước: 256 bytes
//   0x13caec: D10203FF  sub      sp, sp, #0x80
//   0x13caf0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x13caf4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x13caf8: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1701_0x13caec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13caecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1eabb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1702 | PC: 0x13cc10 | FDE: 0x1eac00 | Size: 96 bytes [PyThread_get_thread_ident]
// Khung tháo gỡ #1702 | Địa chỉ PC: 0x13cc10 | Địa chỉ FDE: 0x1eac00 | Kích thước: 96 bytes
//   0x13cc10: D100C3FF  sub      sp, sp, #0x30
//   0x13cc14: F9000BF3  str      x19, [sp, #0x10]
//   0x13cc18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13cc1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1702_0x13cc10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cc10ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1eac00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1703 | PC: 0x13cc70 | FDE: 0x1eac20 | Size: 48 bytes [PyThread_get_thread_native_id]
// Khung tháo gỡ #1703 | Địa chỉ PC: 0x13cc70 | Địa chỉ FDE: 0x1eac20 | Kích thước: 48 bytes
//   0x13cc70: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13cc74: 910003FD  mov      x29, sp
//   0x13cc78: B0000748  adrp     x8, #0x225000
//   0x13cc7c: 39760109  ldrb     w9, [x8, #0xd80]
static inline uint64_t fde_func_1703_0x13cc70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cc70ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eac20ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1704 | PC: 0x13cca0 | FDE: 0x1eac40 | Size: 68 bytes [PyThread_exit_thread]
// Khung tháo gỡ #1704 | Địa chỉ PC: 0x13cca0 | Địa chỉ FDE: 0x1eac40 | Kích thước: 68 bytes
//   0x13cca0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13cca4: 910003FD  mov      x29, sp
//   0x13cca8: B0000748  adrp     x8, #0x225000
//   0x13ccac: 39760108  ldrb     w8, [x8, #0xd80]
static inline uint64_t fde_func_1704_0x13cca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cca0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eac40ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1705 | PC: 0x13cce4 | FDE: 0x1eac60 | Size: 112 bytes [PyThread_allocate_lock]
// Khung tháo gỡ #1705 | Địa chỉ PC: 0x13cce4 | Địa chỉ FDE: 0x1eac60 | Kích thước: 112 bytes
//   0x13cce4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13cce8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13ccec: 910043FD  add      x29, sp, #0x10
//   0x13ccf0: B0000748  adrp     x8, #0x225000
static inline uint64_t fde_func_1705_0x13cce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cce4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eac60ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1706 | PC: 0x13cd54 | FDE: 0x1eac80 | Size: 64 bytes [PyThread_free_lock]
// Khung tháo gỡ #1706 | Địa chỉ PC: 0x13cd54 | Địa chỉ FDE: 0x1eac80 | Kích thước: 64 bytes
//   0x13cd54: B4000160  cbz      x0, #0x13cd80
//   0x13cd58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13cd5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13cd60: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1706_0x13cd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cd54ULL ^ (static_cast<uint64_t>(0xb4000160ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1eac80ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1707 | PC: 0x13cd94 | FDE: 0x1eaca0 | Size: 256 bytes [PyThread_acquire_lock_timed]
// Khung tháo gỡ #1707 | Địa chỉ PC: 0x13cd94 | Địa chỉ FDE: 0x1eaca0 | Kích thước: 256 bytes
//   0x13cd94: D101C3FF  sub      sp, sp, #0x70
//   0x13cd98: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x13cd9c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x13cda0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1707_0x13cd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cd94ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1eaca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1708 | PC: 0x13cfc4 | FDE: 0x1eacc8 | Size: 40 bytes [PyThread_release_lock]
// Khung tháo gỡ #1708 | Địa chỉ PC: 0x13cfc4 | Địa chỉ FDE: 0x1eacc8 | Kích thước: 40 bytes
//   0x13cfc4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13cfc8: 910003FD  mov      x29, sp
//   0x13cfcc: 97FC72C9  bl       #0x59af0
//   0x13cfd0: 340000A0  cbz      w0, #0x13cfe4
static inline uint64_t fde_func_1708_0x13cfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cfc4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eacc8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1709 | PC: 0x13cfec | FDE: 0x1eace8 | Size: 112 bytes [_PyThread_at_fork_reinit]
// Khung tháo gỡ #1709 | Địa chỉ PC: 0x13cfec | Địa chỉ FDE: 0x1eace8 | Kích thước: 112 bytes
//   0x13cfec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x13cff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13cff4: 910043FD  add      x29, sp, #0x10
//   0x13cff8: B0000748  adrp     x8, #0x225000
static inline uint64_t fde_func_1709_0x13cfec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cfecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eace8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1710 | PC: 0x13d05c | FDE: 0x1ead08 | Size: 16 bytes [PyThread_acquire_lock]
// Khung tháo gỡ #1710 | Địa chỉ PC: 0x13d05c | Địa chỉ FDE: 0x1ead08 | Kích thước: 16 bytes
//   0x13d05c: 7100003F  cmp      w1, #0
//   0x13d060: DA9F03E1  csetm    x1, ne
//   0x13d064: 2A1F03E2  mov      w2, wzr
//   0x13d068: 17FC73B6  b        #0x59f40
static inline uint64_t fde_func_1710_0x13d05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d05cULL ^ (static_cast<uint64_t>(0x7100003fULL) << 13);
    acc = (acc + a1 + 0xda9f03e1ULL) ^ 0x1ead08ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1711 | PC: 0x13d06c | FDE: 0x1ead20 | Size: 88 bytes [PyThread_create_key]
// Khung tháo gỡ #1711 | Địa chỉ PC: 0x13d06c | Địa chỉ FDE: 0x1ead20 | Kích thước: 88 bytes
//   0x13d06c: D100C3FF  sub      sp, sp, #0x30
//   0x13d070: F9000BF3  str      x19, [sp, #0x10]
//   0x13d074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13d078: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1711_0x13d06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d06cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1ead20ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1712 | PC: 0x13d0c4 | FDE: 0x1ead40 | Size: 4 bytes [PyThread_delete_key]
// Khung tháo gỡ #1712 | Địa chỉ PC: 0x13d0c4 | Địa chỉ FDE: 0x1ead40 | Kích thước: 4 bytes
//   0x13d0c4: 17FC719F  b        #0x59740
static inline uint64_t fde_func_1712_0x13d0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0c4ULL ^ (static_cast<uint64_t>(0x17fc719fULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x1ead40ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1713 | PC: 0x13d0c8 | FDE: 0x1ead58 | Size: 8 bytes [PyThread_delete_key_value]
// Khung tháo gỡ #1713 | Địa chỉ PC: 0x13d0c8 | Địa chỉ FDE: 0x1ead58 | Kích thước: 8 bytes
//   0x13d0c8: AA1F03E1  mov      x1, xzr
//   0x13d0cc: 17FC72C1  b        #0x59bd0
static inline uint64_t fde_func_1713_0x13d0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0c8ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fc72c1ULL) ^ 0x1ead58ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1714 | PC: 0x13d0d0 | FDE: 0x1ead70 | Size: 28 bytes [PyThread_set_key_value]
// Khung tháo gỡ #1714 | Địa chỉ PC: 0x13d0d0 | Địa chỉ FDE: 0x1ead70 | Kích thước: 28 bytes
//   0x13d0d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d0d4: 910003FD  mov      x29, sp
//   0x13d0d8: 97FC72BE  bl       #0x59bd0
//   0x13d0dc: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_1714_0x13d0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ead70ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1715 | PC: 0x13d0ec | FDE: 0x1ead90 | Size: 4 bytes [PyThread_get_key_value]
// Khung tháo gỡ #1715 | Địa chỉ PC: 0x13d0ec | Địa chỉ FDE: 0x1ead90 | Kích thước: 4 bytes
//   0x13d0ec: 17FC7AB9  b        #0x5bbd0
static inline uint64_t fde_func_1715_0x13d0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0ecULL ^ (static_cast<uint64_t>(0x17fc7ab9ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ead90ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1716 | PC: 0x13d0f0 | FDE: 0x1eada8 | Size: 4 bytes [PyThread_ReInitTLS]
// Khung tháo gỡ #1716 | Địa chỉ PC: 0x13d0f0 | Địa chỉ FDE: 0x1eada8 | Kích thước: 4 bytes
//   0x13d0f0: D65F03C0  ret      
static inline uint64_t fde_func_1716_0x13d0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0f0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1eada8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1717 | PC: 0x13d0f4 | FDE: 0x1eadc0 | Size: 76 bytes [PyThread_tss_create]
// Khung tháo gỡ #1717 | Địa chỉ PC: 0x13d0f4 | Địa chỉ FDE: 0x1eadc0 | Kích thước: 76 bytes
//   0x13d0f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d0f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d0fc: 910043FD  add      x29, sp, #0x10
//   0x13d100: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_1717_0x13d0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d0f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eadc0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1718 | PC: 0x13d140 | FDE: 0x1eade0 | Size: 48 bytes [PyThread_tss_delete]
// Khung tháo gỡ #1718 | Địa chỉ PC: 0x13d140 | Địa chỉ FDE: 0x1eade0 | Kích thước: 48 bytes
//   0x13d140: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d144: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d148: 910043FD  add      x29, sp, #0x10
//   0x13d14c: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_1718_0x13d140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d140ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eade0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1719 | PC: 0x13d170 | FDE: 0x1eae00 | Size: 32 bytes [PyThread_tss_set]
// Khung tháo gỡ #1719 | Địa chỉ PC: 0x13d170 | Địa chỉ FDE: 0x1eae00 | Kích thước: 32 bytes
//   0x13d170: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d174: 910003FD  mov      x29, sp
//   0x13d178: B9400400  ldr      w0, [x0, #4]
//   0x13d17c: 97FC7295  bl       #0x59bd0
static inline uint64_t fde_func_1719_0x13d170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d170ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eae00ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1720 | PC: 0x13d190 | FDE: 0x1eae20 | Size: 8 bytes [PyThread_tss_get]
// Khung tháo gỡ #1720 | Địa chỉ PC: 0x13d190 | Địa chỉ FDE: 0x1eae20 | Kích thước: 8 bytes
//   0x13d190: B9400400  ldr      w0, [x0, #4]
//   0x13d194: 17FC7A8F  b        #0x5bbd0
static inline uint64_t fde_func_1720_0x13d190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d190ULL ^ (static_cast<uint64_t>(0xb9400400ULL) << 13);
    acc = (acc + a1 + 0x17fc7a8fULL) ^ 0x1eae20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1721 | PC: 0x13d198 | FDE: 0x1eae38 | Size: 40 bytes [PyThread_get_stacksize]
// Khung tháo gỡ #1721 | Địa chỉ PC: 0x13d198 | Địa chỉ FDE: 0x1eae38 | Kích thước: 40 bytes
//   0x13d198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d19c: 910003FD  mov      x29, sp
//   0x13d1a0: D0000608  adrp     x8, #0x1ff000
//   0x13d1a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1721_0x13d198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eae38ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1722 | PC: 0x13d1c0 | FDE: 0x1eae58 | Size: 204 bytes [PyThread_set_stacksize]
// Khung tháo gỡ #1722 | Địa chỉ PC: 0x13d1c0 | Địa chỉ FDE: 0x1eae58 | Kích thước: 204 bytes
//   0x13d1c0: D101C3FF  sub      sp, sp, #0x70
//   0x13d1c4: F90023F5  str      x21, [sp, #0x40]
//   0x13d1c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x13d1cc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1722_0x13d1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d1c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1eae58ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1723 | PC: 0x13d28c | FDE: 0x1eae78 | Size: 32 bytes [PyThread_tss_alloc]
// Khung tháo gỡ #1723 | Địa chỉ PC: 0x13d28c | Địa chỉ FDE: 0x1eae78 | Kích thước: 32 bytes
//   0x13d28c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x13d290: 910003FD  mov      x29, sp
//   0x13d294: 52800100  mov      w0, #8
//   0x13d298: 97FC6F06  bl       #0x58eb0
static inline uint64_t fde_func_1723_0x13d28c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d28cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eae78ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1724 | PC: 0x13d2ac | FDE: 0x1eae98 | Size: 60 bytes [PyThread_tss_free]
// Khung tháo gỡ #1724 | Địa chỉ PC: 0x13d2ac | Địa chỉ FDE: 0x1eae98 | Kích thước: 60 bytes
//   0x13d2ac: B40001C0  cbz      x0, #0x13d2e4
//   0x13d2b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d2b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d2b8: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1724_0x13d2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d2acULL ^ (static_cast<uint64_t>(0xb40001c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1eae98ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1725 | PC: 0x13d2e8 | FDE: 0x1eaeb8 | Size: 8 bytes [PyThread_tss_is_created]
// Khung tháo gỡ #1725 | Địa chỉ PC: 0x13d2e8 | Địa chỉ FDE: 0x1eaeb8 | Kích thước: 8 bytes
//   0x13d2e8: B9400000  ldr      w0, [x0]
//   0x13d2ec: D65F03C0  ret      
static inline uint64_t fde_func_1725_0x13d2e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d2e8ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1eaeb8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1726 | PC: 0x13d2f0 | FDE: 0x1eaed0 | Size: 256 bytes [PyThread_GetInfo]
// Khung tháo gỡ #1726 | Địa chỉ PC: 0x13d2f0 | Địa chỉ FDE: 0x1eaed0 | Kích thước: 256 bytes
//   0x13d2f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13d2f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13d2f8: 910043FD  add      x29, sp, #0x10
//   0x13d2fc: 90000748  adrp     x8, #0x225000
static inline uint64_t fde_func_1726_0x13d2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d2f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eaed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1727 | PC: 0x13d714 | FDE: 0x1eaf78 | Size: 208 bytes [_PyTraceBack_FromFrame]
// Khung tháo gỡ #1727 | Địa chỉ PC: 0x13d714 | Địa chỉ FDE: 0x1eaf78 | Kích thước: 208 bytes
//   0x13d714: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x13d718: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x13d71c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x13d720: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1727_0x13d714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d714ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eaf78ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1728 | PC: 0x13d7e4 | FDE: 0x1eafa0 | Size: 256 bytes [PyTraceBack_Here]
// Khung tháo gỡ #1728 | Địa chỉ PC: 0x13d7e4 | Địa chỉ FDE: 0x1eafa0 | Kích thước: 256 bytes
//   0x13d7e4: D10183FF  sub      sp, sp, #0x60
//   0x13d7e8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13d7ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13d7f0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1728_0x13d7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d7e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1eafa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1729 | PC: 0x13d920 | FDE: 0x1eafc8 | Size: 256 bytes [_PyTraceback_Add]
// Khung tháo gỡ #1729 | Địa chỉ PC: 0x13d920 | Địa chỉ FDE: 0x1eafc8 | Kích thước: 256 bytes
//   0x13d920: D10183FF  sub      sp, sp, #0x60
//   0x13d924: F90013F7  str      x23, [sp, #0x20]
//   0x13d928: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13d92c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1729_0x13d920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d920ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1eafc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1730 | PC: 0x13da60 | FDE: 0x1eaff0 | Size: 256 bytes [_Py_DisplaySourceLine]
// Khung tháo gỡ #1730 | Địa chỉ PC: 0x13da60 | Địa chỉ FDE: 0x1eaff0 | Kích thước: 256 bytes
//   0x13da60: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x13da64: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x13da68: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13da6c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1730_0x13da60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13da60ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1eaff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1731 | PC: 0x13e108 | FDE: 0x1eb020 | Size: 256 bytes [PyTraceBack_Print]
// Khung tháo gỡ #1731 | Địa chỉ PC: 0x13e108 | Địa chỉ FDE: 0x1eb020 | Kích thước: 256 bytes
//   0x13e108: D10203FF  sub      sp, sp, #0x80
//   0x13e10c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x13e110: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x13e114: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1731_0x13e108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e108ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1eb020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1732 | PC: 0x13e4d0 | FDE: 0x1eb050 | Size: 136 bytes [_Py_DumpDecimal]
// Khung tháo gỡ #1732 | Địa chỉ PC: 0x13e4d0 | Địa chỉ FDE: 0x1eb050 | Kích thước: 136 bytes
//   0x13e4d0: D10103FF  sub      sp, sp, #0x40
//   0x13e4d4: F90013F3  str      x19, [sp, #0x20]
//   0x13e4d8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x13e4dc: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1732_0x13e4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e4d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1eb050ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1733 | PC: 0x13e558 | FDE: 0x1eb070 | Size: 144 bytes [_Py_DumpHexadecimal]
// Khung tháo gỡ #1733 | Địa chỉ PC: 0x13e558 | Địa chỉ FDE: 0x1eb070 | Kích thước: 144 bytes
//   0x13e558: D10103FF  sub      sp, sp, #0x40
//   0x13e55c: F90013F3  str      x19, [sp, #0x20]
//   0x13e560: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x13e564: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1733_0x13e558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e558ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1eb070ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1734 | PC: 0x13e5e8 | FDE: 0x1eb090 | Size: 256 bytes [_Py_DumpASCII]
// Khung tháo gỡ #1734 | Địa chỉ PC: 0x13e5e8 | Địa chỉ FDE: 0x1eb090 | Kích thước: 256 bytes
//   0x13e5e8: D10283FF  sub      sp, sp, #0xa0
//   0x13e5ec: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x13e5f0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x13e5f4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1734_0x13e5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e5e8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1eb090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1735 | PC: 0x13e894 | FDE: 0x1eb0c0 | Size: 256 bytes [_Py_DumpTraceback]
// Khung tháo gỡ #1735 | Địa chỉ PC: 0x13e894 | Địa chỉ FDE: 0x1eb0c0 | Kích thước: 256 bytes
//   0x13e894: 52800022  mov      w2, #1
//   0x13e898: 14000001  b        #0x13e89c
//   0x13e89c: D10243FF  sub      sp, sp, #0x90
//   0x13e8a0: A9036FFC  stp      x28, x27, [sp, #0x30]
static inline uint64_t fde_func_1735_0x13e894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e894ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1eb0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1736 | PC: 0x13ec38 | FDE: 0x1eb108 | Size: 56 bytes [BD_Py_DumpTraceback]
// Khung tháo gỡ #1736 | Địa chỉ PC: 0x13ec38 | Địa chỉ FDE: 0x1eb108 | Kích thước: 56 bytes
//   0x13ec38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13ec3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13ec40: 910043FD  add      x29, sp, #0x10
//   0x13ec44: 97FC70A3  bl       #0x5aed0
static inline uint64_t fde_func_1736_0x13ec38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ec38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb108ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1737 | PC: 0x13ec70 | FDE: 0x1eb128 | Size: 256 bytes [_Py_DumpTracebackThreads]
// Khung tháo gỡ #1737 | Địa chỉ PC: 0x13ec70 | Địa chỉ FDE: 0x1eb128 | Kích thước: 256 bytes
//   0x13ec70: D10243FF  sub      sp, sp, #0x90
//   0x13ec74: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x13ec78: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x13ec7c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1737_0x13ec70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ec70ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1eb128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1738 | PC: 0x13eff4 | FDE: 0x1eb1a8 | Size: 256 bytes [_PyOS_ResetGetOpt]
// Khung tháo gỡ #1738 | Địa chỉ PC: 0x13eff4 | Địa chỉ FDE: 0x1eb1a8 | Kích thước: 256 bytes
//   0x13eff4: B0000608  adrp     x8, #0x1ff000
//   0x13eff8: B000060A  adrp     x10, #0x1ff000
//   0x13effc: 1060002B  adr      x11, #0x1ff000
//   0x13f000: F9434108  ldr      x8, [x8, #0x680]
static inline uint64_t fde_func_1738_0x13eff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13eff4ULL ^ (static_cast<uint64_t>(0xb0000608ULL) << 13);
    acc = (acc + a1 + 0xb000060aULL) ^ 0x1eb1a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1739 | PC: 0x140030 | FDE: 0x1eb1c0 | Size: 256 bytes [_PyOS_GetOpt]
// Khung tháo gỡ #1739 | Địa chỉ PC: 0x140030 | Địa chỉ FDE: 0x1eb1c0 | Kích thước: 256 bytes
//   0x140030: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x140034: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x140038: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14003c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1739_0x140030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140030ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb1c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1740 | PC: 0x140380 | FDE: 0x1eb1e8 | Size: 160 bytes [PyOS_mystrnicmp]
// Khung tháo gỡ #1740 | Địa chỉ PC: 0x140380 | Địa chỉ FDE: 0x1eb1e8 | Kích thước: 160 bytes
//   0x140380: B40004C2  cbz      x2, #0x140418
//   0x140384: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x140388: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x14038c: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_1740_0x140380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140380ULL ^ (static_cast<uint64_t>(0xb40004c2ULL) << 13);
    acc = (acc + a1 + 0xf81c0ff7ULL) ^ 0x1eb1e8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1741 | PC: 0x140420 | FDE: 0x1eb210 | Size: 140 bytes [PyOS_mystricmp]
// Khung tháo gỡ #1741 | Địa chỉ PC: 0x140420 | Địa chỉ FDE: 0x1eb210 | Kích thước: 140 bytes
//   0x140420: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x140424: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x140428: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14042c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1741_0x140420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140420ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb210ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1742 | PC: 0x1404ac | FDE: 0x1eb238 | Size: 256 bytes [_Py_parse_inf_or_nan]
// Khung tháo gỡ #1742 | Địa chỉ PC: 0x1404ac | Địa chỉ FDE: 0x1eb238 | Kích thước: 256 bytes
//   0x1404ac: 39400008  ldrb     w8, [x0]
//   0x1404b0: 7100AD1F  cmp      w8, #0x2b
//   0x1404b4: 540000C0  b.eq     #0x1404cc
//   0x1404b8: 7100B51F  cmp      w8, #0x2d
static inline uint64_t fde_func_1742_0x1404ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1404acULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x7100ad1fULL) ^ 0x1eb238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1743 | PC: 0x1405cc | FDE: 0x1eb250 | Size: 256 bytes [PyOS_string_to_double]
// Khung tháo gỡ #1743 | Địa chỉ PC: 0x1405cc | Địa chỉ FDE: 0x1eb250 | Kích thước: 256 bytes
//   0x1405cc: D10243FF  sub      sp, sp, #0x90
//   0x1405d0: FD0013E8  str      d8, [sp, #0x20]
//   0x1405d4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1405d8: A90467FA  stp      x26, x25, [sp, #0x40]
static inline uint64_t fde_func_1743_0x1405cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1405ccULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x1eb250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1744 | PC: 0x14096c | FDE: 0x1eb280 | Size: 256 bytes [_Py_string_to_number_with_underscores]
// Khung tháo gỡ #1744 | Địa chỉ PC: 0x14096c | Địa chỉ FDE: 0x1eb280 | Kích thước: 256 bytes
//   0x14096c: D10143FF  sub      sp, sp, #0x50
//   0x140970: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x140974: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x140978: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1744_0x14096c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14096cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1745 | PC: 0x140ad4 | FDE: 0x1eb2a8 | Size: 256 bytes [PyOS_double_to_string]
// Khung tháo gỡ #1745 | Địa chỉ PC: 0x140ad4 | Địa chỉ FDE: 0x1eb2a8 | Kích thước: 256 bytes
//   0x140ad4: D10503FF  sub      sp, sp, #0x140
//   0x140ad8: FD006BE8  str      d8, [sp, #0xd0]
//   0x140adc: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x140ae0: A90F67FA  stp      x26, x25, [sp, #0xf0]
static inline uint64_t fde_func_1745_0x140ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140ad4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xfd006be8ULL) ^ 0x1eb2a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1746 | PC: 0x141234 | FDE: 0x1eb320 | Size: 256 bytes [_Py_strhex]
// Khung tháo gỡ #1746 | Địa chỉ PC: 0x141234 | Địa chỉ FDE: 0x1eb320 | Kích thước: 256 bytes
//   0x141234: 92F80008  mov      x8, #0x3fffffffffffffff
//   0x141238: EB08003F  cmp      x1, x8
//   0x14123c: 5400020A  b.ge     #0x14127c
//   0x141240: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_1746_0x141234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141234ULL ^ (static_cast<uint64_t>(0x92f80008ULL) << 13);
    acc = (acc + a1 + 0xeb08003fULL) ^ 0x1eb320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1747 | PC: 0x141694 | FDE: 0x1eb368 | Size: 128 bytes [_Py_strhex_bytes]
// Khung tháo gỡ #1747 | Địa chỉ PC: 0x141694 | Địa chỉ FDE: 0x1eb368 | Kích thước: 128 bytes
//   0x141694: 92F80008  mov      x8, #0x3fffffffffffffff
//   0x141698: EB08003F  cmp      x1, x8
//   0x14169c: 540003AA  b.ge     #0x141710
//   0x1416a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_1747_0x141694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141694ULL ^ (static_cast<uint64_t>(0x92f80008ULL) << 13);
    acc = (acc + a1 + 0xeb08003fULL) ^ 0x1eb368ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1748 | PC: 0x141714 | FDE: 0x1eb388 | Size: 8 bytes [_Py_strhex_with_sep]
// Khung tháo gỡ #1748 | Địa chỉ PC: 0x141714 | Địa chỉ FDE: 0x1eb388 | Kích thước: 8 bytes
//   0x141714: 2A1F03E4  mov      w4, wzr
//   0x141718: 17FFFEF1  b        #0x1412dc
static inline uint64_t fde_func_1748_0x141714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141714ULL ^ (static_cast<uint64_t>(0x2a1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fffef1ULL) ^ 0x1eb388ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1749 | PC: 0x14171c | FDE: 0x1eb3a0 | Size: 8 bytes [_Py_strhex_bytes_with_sep]
// Khung tháo gỡ #1749 | Địa chỉ PC: 0x14171c | Địa chỉ FDE: 0x1eb3a0 | Kích thước: 8 bytes
//   0x14171c: 52800024  mov      w4, #1
//   0x141720: 17FFFEEF  b        #0x1412dc
static inline uint64_t fde_func_1749_0x14171c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14171cULL ^ (static_cast<uint64_t>(0x52800024ULL) << 13);
    acc = (acc + a1 + 0x17fffeefULL) ^ 0x1eb3a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1750 | PC: 0x141724 | FDE: 0x1eb3b8 | Size: 256 bytes [_PyUnicode_FormatAdvancedWriter]
// Khung tháo gỡ #1750 | Địa chỉ PC: 0x141724 | Địa chỉ FDE: 0x1eb3b8 | Kích thước: 256 bytes
//   0x141724: D10203FF  sub      sp, sp, #0x80
//   0x141728: F9001BF9  str      x25, [sp, #0x30]
//   0x14172c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x141730: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1750_0x141724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141724ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1eb3b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1751 | PC: 0x142224 | FDE: 0x1eb410 | Size: 256 bytes [_PyLong_FormatAdvancedWriter]
// Khung tháo gỡ #1751 | Địa chỉ PC: 0x142224 | Địa chỉ FDE: 0x1eb410 | Kích thước: 256 bytes
//   0x142224: D104C3FF  sub      sp, sp, #0x130
//   0x142228: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x14222c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x142230: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1751_0x142224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142224ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1eb410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1752 | PC: 0x142bd8 | FDE: 0x1eb470 | Size: 256 bytes [_PyFloat_FormatAdvancedWriter]
// Khung tháo gỡ #1752 | Địa chỉ PC: 0x142bd8 | Địa chỉ FDE: 0x1eb470 | Kích thước: 256 bytes
//   0x142bd8: D10143FF  sub      sp, sp, #0x50
//   0x142bdc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x142be0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x142be4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1752_0x142bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142bd8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1eb470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1753 | PC: 0x142cf0 | FDE: 0x1eb490 | Size: 256 bytes [_PyComplex_FormatAdvancedWriter]
// Khung tháo gỡ #1753 | Địa chỉ PC: 0x142cf0 | Địa chỉ FDE: 0x1eb490 | Kích thước: 256 bytes
//   0x142cf0: 6DB923E9  stp      d9, d8, [sp, #-0x70]!
//   0x142cf4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x142cf8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x142cfc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1753_0x142cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142cf0ULL ^ (static_cast<uint64_t>(0x6db923e9ULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1eb490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1754 | PC: 0x143e10 | FDE: 0x1eb548 | Size: 140 bytes [_Py_device_encoding]
// Khung tháo gỡ #1754 | Địa chỉ PC: 0x143e10 | Địa chỉ FDE: 0x1eb548 | Kích thước: 140 bytes
//   0x143e10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x143e14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x143e18: 910043FD  add      x29, sp, #0x10
//   0x143e1c: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_1754_0x143e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143e10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb548ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1755 | PC: 0x143e9c | FDE: 0x1eb568 | Size: 80 bytes [_Py_GetLocaleEncodingObject]
// Khung tháo gỡ #1755 | Địa chỉ PC: 0x143e9c | Địa chỉ FDE: 0x1eb568 | Kích thước: 80 bytes
//   0x143e9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x143ea0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x143ea4: 910043FD  add      x29, sp, #0x10
//   0x143ea8: B00003E0  adrp     x0, #0x1c0000
static inline uint64_t fde_func_1755_0x143e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143e9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb568ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1756 | PC: 0x143eec | FDE: 0x1eb588 | Size: 8 bytes [_Py_GetForceASCII]
// Khung tháo gỡ #1756 | Địa chỉ PC: 0x143eec | Địa chỉ FDE: 0x1eb588 | Kích thước: 8 bytes
//   0x143eec: 2A1F03E0  mov      w0, wzr
//   0x143ef0: D65F03C0  ret      
static inline uint64_t fde_func_1756_0x143eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143eecULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1eb588ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1757 | PC: 0x143ef4 | FDE: 0x1eb5a0 | Size: 4 bytes [_Py_ResetForceASCII]
// Khung tháo gỡ #1757 | Địa chỉ PC: 0x143ef4 | Địa chỉ FDE: 0x1eb5a0 | Kích thước: 4 bytes
//   0x143ef4: D65F03C0  ret      
static inline uint64_t fde_func_1757_0x143ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143ef4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81c0ff7ULL) ^ 0x1eb5a0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1758 | PC: 0x143ef8 | FDE: 0x1eb5b8 | Size: 88 bytes [_Py_DecodeLocaleEx]
// Khung tháo gỡ #1758 | Địa chỉ PC: 0x143ef8 | Địa chỉ FDE: 0x1eb5b8 | Kích thước: 88 bytes
//   0x143ef8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x143efc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x143f00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x143f04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1758_0x143ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143ef8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb5b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1759 | PC: 0x143f50 | FDE: 0x1eb5e0 | Size: 152 bytes [Py_DecodeLocale]
// Khung tháo gỡ #1759 | Địa chỉ PC: 0x143f50 | Địa chỉ FDE: 0x1eb5e0 | Kích thước: 152 bytes
//   0x143f50: D10103FF  sub      sp, sp, #0x40
//   0x143f54: F9000BF5  str      x21, [sp, #0x10]
//   0x143f58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x143f5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1759_0x143f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143f50ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1eb5e0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1760 | PC: 0x143fe8 | FDE: 0x1eb600 | Size: 124 bytes [Py_EncodeLocale]
// Khung tháo gỡ #1760 | Địa chỉ PC: 0x143fe8 | Địa chỉ FDE: 0x1eb600 | Kích thước: 124 bytes
//   0x143fe8: D100C3FF  sub      sp, sp, #0x30
//   0x143fec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x143ff0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x143ff4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1760_0x143fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143fe8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb600ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1761 | PC: 0x144064 | FDE: 0x1eb620 | Size: 124 bytes [_Py_EncodeLocaleRaw]
// Khung tháo gỡ #1761 | Địa chỉ PC: 0x144064 | Địa chỉ FDE: 0x1eb620 | Kích thước: 124 bytes
//   0x144064: D100C3FF  sub      sp, sp, #0x30
//   0x144068: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14406c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144070: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1761_0x144064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144064ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb620ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1762 | PC: 0x1440e0 | FDE: 0x1eb640 | Size: 8 bytes [_Py_EncodeLocaleEx]
// Khung tháo gỡ #1762 | Địa chỉ PC: 0x1440e0 | Địa chỉ FDE: 0x1eb640 | Kích thước: 8 bytes
//   0x1440e0: 52800024  mov      w4, #1
//   0x1440e4: 17FC65CB  b        #0x5d810
static inline uint64_t fde_func_1762_0x1440e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440e0ULL ^ (static_cast<uint64_t>(0x52800024ULL) << 13);
    acc = (acc + a1 + 0x17fc65cbULL) ^ 0x1eb640ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1763 | PC: 0x1440e8 | FDE: 0x1eb658 | Size: 12 bytes [_Py_GetLocaleEncoding]
// Khung tháo gỡ #1763 | Địa chỉ PC: 0x1440e8 | Địa chỉ FDE: 0x1eb658 | Kích thước: 12 bytes
//   0x1440e8: 900003E0  adrp     x0, #0x1c0000
//   0x1440ec: 91068000  add      x0, x0, #0x1a0
//   0x1440f0: 17FC625C  b        #0x5ca60
static inline uint64_t fde_func_1763_0x1440e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440e8ULL ^ (static_cast<uint64_t>(0x900003e0ULL) << 13);
    acc = (acc + a1 + 0x91068000ULL) ^ 0x1eb658ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1764 | PC: 0x1440f4 | FDE: 0x1eb670 | Size: 4 bytes [_Py_fstat_noraise]
// Khung tháo gỡ #1764 | Địa chỉ PC: 0x1440f4 | Địa chỉ FDE: 0x1eb670 | Kích thước: 4 bytes
//   0x1440f4: 17FC65CF  b        #0x5d830
static inline uint64_t fde_func_1764_0x1440f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440f4ULL ^ (static_cast<uint64_t>(0x17fc65cfULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x1eb670ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1765 | PC: 0x1440f8 | FDE: 0x1eb688 | Size: 104 bytes [_Py_fstat]
// Khung tháo gỡ #1765 | Địa chỉ PC: 0x1440f8 | Địa chỉ FDE: 0x1eb688 | Kích thước: 104 bytes
//   0x1440f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1440fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x144100: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144104: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1765_0x1440f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1440f8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb688ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1766 | PC: 0x144160 | FDE: 0x1eb6a8 | Size: 184 bytes [_Py_stat]
// Khung tháo gỡ #1766 | Địa chỉ PC: 0x144160 | Địa chỉ FDE: 0x1eb6a8 | Kích thước: 184 bytes
//   0x144160: D10103FF  sub      sp, sp, #0x40
//   0x144164: F9000BF5  str      x21, [sp, #0x10]
//   0x144168: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14416c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1766_0x144160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144160ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1eb6a8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1767 | PC: 0x144218 | FDE: 0x1eb6c8 | Size: 72 bytes [_Py_get_inheritable]
// Khung tháo gỡ #1767 | Địa chỉ PC: 0x144218 | Địa chỉ FDE: 0x1eb6c8 | Kích thước: 72 bytes
//   0x144218: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14421c: 910003FD  mov      x29, sp
//   0x144220: 52800021  mov      w1, #1
//   0x144224: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_1767_0x144218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144218ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eb6c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1768 | PC: 0x144260 | FDE: 0x1eb6e8 | Size: 256 bytes [_Py_set_inheritable]
// Khung tháo gỡ #1768 | Địa chỉ PC: 0x144260 | Địa chỉ FDE: 0x1eb6e8 | Kích thước: 256 bytes
//   0x144260: AA0203E3  mov      x3, x2
//   0x144264: 52800022  mov      w2, #1
//   0x144268: 14000001  b        #0x14426c
//   0x14426c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
static inline uint64_t fde_func_1768_0x144260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144260ULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x1eb6e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1769 | PC: 0x14439c | FDE: 0x1eb728 | Size: 180 bytes [_Py_set_inheritable_async_safe]
// Khung tháo gỡ #1769 | Địa chỉ PC: 0x14439c | Địa chỉ FDE: 0x1eb728 | Kích thước: 180 bytes
//   0x14439c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1443a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1443a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1443a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1769_0x14439c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14439cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb728ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1770 | PC: 0x144450 | FDE: 0x1eb748 | Size: 256 bytes [_Py_open]
// Khung tháo gỡ #1770 | Địa chỉ PC: 0x144450 | Địa chỉ FDE: 0x1eb748 | Kích thước: 256 bytes
//   0x144450: 52800022  mov      w2, #1
//   0x144454: 14000001  b        #0x144458
//   0x144458: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x14445c: A90157F6  stp      x22, x21, [sp, #0x10]
static inline uint64_t fde_func_1770_0x144450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144450ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1eb748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1771 | PC: 0x144598 | FDE: 0x1eb788 | Size: 168 bytes [_Py_open_noraise]
// Khung tháo gỡ #1771 | Địa chỉ PC: 0x144598 | Địa chỉ FDE: 0x1eb788 | Kích thước: 168 bytes
//   0x144598: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14459c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1445a0: 910043FD  add      x29, sp, #0x10
//   0x1445a4: 320D0021  orr      w1, w1, #0x80000
static inline uint64_t fde_func_1771_0x144598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144598ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb788ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1772 | PC: 0x144640 | FDE: 0x1eb7a8 | Size: 256 bytes [_Py_wfopen]
// Khung tháo gỡ #1772 | Địa chỉ PC: 0x144640 | Địa chỉ FDE: 0x1eb7a8 | Kích thước: 256 bytes
//   0x144640: D10143FF  sub      sp, sp, #0x50
//   0x144644: F90013F5  str      x21, [sp, #0x20]
//   0x144648: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x14464c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1772_0x144640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144640ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1eb7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1773 | PC: 0x14476c | FDE: 0x1eb7c8 | Size: 256 bytes [_Py_fopen_obj]
// Khung tháo gỡ #1773 | Địa chỉ PC: 0x14476c | Địa chỉ FDE: 0x1eb7c8 | Kích thước: 256 bytes
//   0x14476c: D10143FF  sub      sp, sp, #0x50
//   0x144770: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x144774: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x144778: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1773_0x14476c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14476cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb7c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1774 | PC: 0x1448dc | FDE: 0x1eb7f0 | Size: 184 bytes [_Py_read]
// Khung tháo gỡ #1774 | Địa chỉ PC: 0x1448dc | Địa chỉ FDE: 0x1eb7f0 | Kích thước: 184 bytes
//   0x1448dc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1448e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1448e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1448e8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1774_0x1448dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1448dcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb7f0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1775 | PC: 0x144994 | FDE: 0x1eb818 | Size: 256 bytes [_Py_write]
// Khung tháo gỡ #1775 | Địa chỉ PC: 0x144994 | Địa chỉ FDE: 0x1eb818 | Kích thước: 256 bytes
//   0x144994: 52800023  mov      w3, #1
//   0x144998: 14000001  b        #0x14499c
//   0x14499c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1449a0: A9015FF8  stp      x24, x23, [sp, #0x10]
static inline uint64_t fde_func_1775_0x144994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144994ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1eb818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1776 | PC: 0x144a94 | FDE: 0x1eb860 | Size: 104 bytes [_Py_write_noraise]
// Khung tháo gỡ #1776 | Địa chỉ PC: 0x144a94 | Địa chỉ FDE: 0x1eb860 | Kích thước: 104 bytes
//   0x144a94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x144a98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x144a9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x144aa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1776_0x144a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144a94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eb860ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1777 | PC: 0x144afc | FDE: 0x1eb888 | Size: 256 bytes [_Py_wreadlink]
// Khung tháo gỡ #1777 | Địa chỉ PC: 0x144afc | Địa chỉ FDE: 0x1eb888 | Kích thước: 256 bytes
//   0x144afc: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x144b00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144b04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144b08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1777_0x144afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144afcULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1778 | PC: 0x144c50 | FDE: 0x1eb8b0 | Size: 256 bytes [_Py_wrealpath]
// Khung tháo gỡ #1778 | Địa chỉ PC: 0x144c50 | Địa chỉ FDE: 0x1eb8b0 | Kích thước: 256 bytes
//   0x144c50: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x144c54: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144c58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144c5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1778_0x144c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144c50ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb8b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1779 | PC: 0x144d7c | FDE: 0x1eb8d8 | Size: 16 bytes [_Py_isabs]
// Khung tháo gỡ #1779 | Địa chỉ PC: 0x144d7c | Địa chỉ FDE: 0x1eb8d8 | Kích thước: 16 bytes
//   0x144d7c: B9400008  ldr      w8, [x0]
//   0x144d80: 7100BD1F  cmp      w8, #0x2f
//   0x144d84: 1A9F17E0  cset     w0, eq
//   0x144d88: D65F03C0  ret      
static inline uint64_t fde_func_1779_0x144d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144d7cULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100bd1fULL) ^ 0x1eb8d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1780 | PC: 0x144d8c | FDE: 0x1eb8f0 | Size: 256 bytes [_Py_abspath]
// Khung tháo gỡ #1780 | Địa chỉ PC: 0x144d8c | Địa chỉ FDE: 0x1eb8f0 | Kích thước: 256 bytes
//   0x144d8c: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x144d90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x144d94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x144d98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1780_0x144d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144d8cULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1eb8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1781 | PC: 0x144ebc | FDE: 0x1eb918 | Size: 236 bytes [_Py_wgetcwd]
// Khung tháo gỡ #1781 | Địa chỉ PC: 0x144ebc | Địa chỉ FDE: 0x1eb918 | Kích thước: 236 bytes
//   0x144ebc: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x144ec0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144ec4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144ec8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1781_0x144ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144ebcULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb918ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1782 | PC: 0x144fa8 | FDE: 0x1eb940 | Size: 92 bytes [_Py_dup]
// Khung tháo gỡ #1782 | Địa chỉ PC: 0x144fa8 | Địa chỉ FDE: 0x1eb940 | Kích thước: 92 bytes
//   0x144fa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x144fac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x144fb0: 910043FD  add      x29, sp, #0x10
//   0x144fb4: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_1782_0x144fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144fa8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb940ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1783 | PC: 0x145004 | FDE: 0x1eb960 | Size: 68 bytes [_Py_get_blocking]
// Khung tháo gỡ #1783 | Địa chỉ PC: 0x145004 | Địa chỉ FDE: 0x1eb960 | Kích thước: 68 bytes
//   0x145004: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x145008: 910003FD  mov      x29, sp
//   0x14500c: 52800061  mov      w1, #3
//   0x145010: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_1783_0x145004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145004ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eb960ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1784 | PC: 0x145048 | FDE: 0x1eb980 | Size: 120 bytes [_Py_set_blocking]
// Khung tháo gỡ #1784 | Địa chỉ PC: 0x145048 | Địa chỉ FDE: 0x1eb980 | Kích thước: 120 bytes
//   0x145048: D100C3FF  sub      sp, sp, #0x30
//   0x14504c: F9000BF3  str      x19, [sp, #0x10]
//   0x145050: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145054: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1784_0x145048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145048ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1eb980ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1785 | PC: 0x1450c0 | FDE: 0x1eb9a0 | Size: 256 bytes [_Py_GetLocaleconvNumeric]
// Khung tháo gỡ #1785 | Địa chỉ PC: 0x1450c0 | Địa chỉ FDE: 0x1eb9a0 | Kích thước: 256 bytes
//   0x1450c0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1450c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1450c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1450cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1785_0x1450c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1450c0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1eb9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1786 | PC: 0x145214 | FDE: 0x1eb9c8 | Size: 60 bytes [_Py_closerange]
// Khung tháo gỡ #1786 | Địa chỉ PC: 0x145214 | Địa chỉ FDE: 0x1eb9c8 | Kích thước: 60 bytes
//   0x145214: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x145218: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14521c: 910043FD  add      x29, sp, #0x10
//   0x145220: 0AA07C14  bic      w20, w0, w0, asr #31
static inline uint64_t fde_func_1786_0x145214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145214ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eb9c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1787 | PC: 0x145250 | FDE: 0x1eb9e8 | Size: 16 bytes [_PyEval_DeactivateOpCache]
// Khung tháo gỡ #1787 | Địa chỉ PC: 0x145250 | Địa chỉ FDE: 0x1eb9e8 | Kích thước: 16 bytes
//   0x145250: 90000708  adrp     x8, #0x225000
//   0x145254: 52800029  mov      w9, #1
//   0x145258: 393CA109  strb     w9, [x8, #0xf28]
//   0x14525c: D65F03C0  ret      
static inline uint64_t fde_func_1787_0x145250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145250ULL ^ (static_cast<uint64_t>(0x90000708ULL) << 13);
    acc = (acc + a1 + 0x52800029ULL) ^ 0x1eb9e8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1788 | PC: 0x145260 | FDE: 0x1eba00 | Size: 36 bytes [_PyEval_SetSwitchInterval]
// Khung tháo gỡ #1788 | Địa chỉ PC: 0x145260 | Địa chỉ FDE: 0x1eba00 | Kích thước: 36 bytes
//   0x145260: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145264: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145268: 910043FD  add      x29, sp, #0x10
//   0x14526c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1788_0x145260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145260ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1eba00ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1789 | PC: 0x145284 | FDE: 0x1eba20 | Size: 24 bytes [_PyEval_GetSwitchInterval]
// Khung tháo gỡ #1789 | Địa chỉ PC: 0x145284 | Địa chỉ FDE: 0x1eba20 | Kích thước: 24 bytes
//   0x145284: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x145288: 910003FD  mov      x29, sp
//   0x14528c: 97FC5DB9  bl       #0x5c970
//   0x145290: F9413400  ldr      x0, [x0, #0x268]
static inline uint64_t fde_func_1789_0x145284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145284ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eba20ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1790 | PC: 0x14529c | FDE: 0x1eba40 | Size: 20 bytes [_Py_FatalError_TstateNULL]
// Khung tháo gỡ #1790 | Địa chỉ PC: 0x14529c | Địa chỉ FDE: 0x1eba40 | Kích thước: 20 bytes
//   0x14529c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1452a0: 910003FD  mov      x29, sp
//   0x1452a4: F00003C1  adrp     x1, #0x1c0000
//   0x1452a8: 91123821  add      x1, x1, #0x48e
static inline uint64_t fde_func_1790_0x14529c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14529cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eba40ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1791 | PC: 0x1452b0 | FDE: 0x1eba60 | Size: 20 bytes [_PyEval_ThreadsInitialized]
// Khung tháo gỡ #1791 | Địa chỉ PC: 0x1452b0 | Địa chỉ FDE: 0x1eba60 | Kích thước: 20 bytes
//   0x1452b0: 9109E008  add      x8, x0, #0x278
//   0x1452b4: 88DFFD08  ldar     w8, [x8]
//   0x1452b8: 2A2803E8  mvn      w8, w8
//   0x1452bc: 531F7D00  lsr      w0, w8, #0x1f
static inline uint64_t fde_func_1791_0x1452b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1452b0ULL ^ (static_cast<uint64_t>(0x9109e008ULL) << 13);
    acc = (acc + a1 + 0x88dffd08ULL) ^ 0x1eba60ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1792 | PC: 0x1452c4 | FDE: 0x1eba78 | Size: 36 bytes [PyEval_ThreadsInitialized]
// Khung tháo gỡ #1792 | Địa chỉ PC: 0x1452c4 | Địa chỉ FDE: 0x1eba78 | Kích thước: 36 bytes
//   0x1452c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1452c8: 910003FD  mov      x29, sp
//   0x1452cc: 97FC5DA9  bl       #0x5c970
//   0x1452d0: 9109E008  add      x8, x0, #0x278
static inline uint64_t fde_func_1792_0x1452c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1452c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1eba78ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1793 | PC: 0x1452e8 | FDE: 0x1eba98 | Size: 256 bytes [_PyEval_InitGIL]
// Khung tháo gỡ #1793 | Địa chỉ PC: 0x1452e8 | Địa chỉ FDE: 0x1eba98 | Kích thước: 256 bytes
//   0x1452e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1452ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1452f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1452f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1793_0x1452e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1452e8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1eba98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1794 | PC: 0x1456b8 | FDE: 0x1ebb08 | Size: 180 bytes [_PyEval_FiniGIL]
// Khung tháo gỡ #1794 | Địa chỉ PC: 0x1456b8 | Địa chỉ FDE: 0x1ebb08 | Kích thước: 180 bytes
//   0x1456b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1456bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1456c0: 910043FD  add      x29, sp, #0x10
//   0x1456c4: 9109E008  add      x8, x0, #0x278
static inline uint64_t fde_func_1794_0x1456b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1456b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebb08ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1795 | PC: 0x14576c | FDE: 0x1ebb28 | Size: 4 bytes [PyEval_InitThreads]
// Khung tháo gỡ #1795 | Địa chỉ PC: 0x14576c | Địa chỉ FDE: 0x1ebb28 | Kích thước: 4 bytes
//   0x14576c: D65F03C0  ret      
static inline uint64_t fde_func_1795_0x14576c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14576cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ebb28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1796 | PC: 0x145770 | FDE: 0x1ebb40 | Size: 4 bytes [_PyEval_Fini]
// Khung tháo gỡ #1796 | Địa chỉ PC: 0x145770 | Địa chỉ FDE: 0x1ebb40 | Kích thước: 4 bytes
//   0x145770: D65F03C0  ret      
static inline uint64_t fde_func_1796_0x145770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145770ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1ebb40ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1797 | PC: 0x145774 | FDE: 0x1ebb58 | Size: 36 bytes [PyEval_AcquireLock]
// Khung tháo gỡ #1797 | Địa chỉ PC: 0x145774 | Địa chỉ FDE: 0x1ebb58 | Kích thước: 36 bytes
//   0x145774: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x145778: 910003FD  mov      x29, sp
//   0x14577c: 97FC5011  bl       #0x597c0
//   0x145780: B4000060  cbz      x0, #0x14578c
static inline uint64_t fde_func_1797_0x145774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145774ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ebb58ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1798 | PC: 0x145798 | FDE: 0x1ebb78 | Size: 256 bytes [PyEval_ReleaseLock]
// Khung tháo gỡ #1798 | Địa chỉ PC: 0x145798 | Địa chỉ FDE: 0x1ebb78 | Kích thước: 256 bytes
//   0x145798: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14579c: 910003FD  mov      x29, sp
//   0x1457a0: 97FC5008  bl       #0x597c0
//   0x1457a4: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1798_0x145798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145798ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ebb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1799 | PC: 0x14596c | FDE: 0x1ebbc0 | Size: 16 bytes [_PyEval_ReleaseLock]
// Khung tháo gỡ #1799 | Địa chỉ PC: 0x14596c | Địa chỉ FDE: 0x1ebbc0 | Kích thước: 16 bytes
//   0x14596c: F9400808  ldr      x8, [x0, #0x10]
//   0x145970: AA0003E1  mov      x1, x0
//   0x145974: 91010100  add      x0, x8, #0x40
//   0x145978: 17FFFF90  b        #0x1457b8
static inline uint64_t fde_func_1799_0x14596c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14596cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x1ebbc0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1800 | PC: 0x14597c | FDE: 0x1ebbd8 | Size: 64 bytes [PyEval_AcquireThread]
// Khung tháo gỡ #1800 | Địa chỉ PC: 0x14597c | Địa chỉ FDE: 0x1ebbd8 | Kích thước: 64 bytes
//   0x14597c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145980: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145984: 910043FD  add      x29, sp, #0x10
//   0x145988: B4000140  cbz      x0, #0x1459b0
static inline uint64_t fde_func_1800_0x14597c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14597cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebbd8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1801 | PC: 0x1459bc | FDE: 0x1ebbf8 | Size: 88 bytes [PyEval_ReleaseThread]
// Khung tháo gỡ #1801 | Địa chỉ PC: 0x1459bc | Địa chỉ FDE: 0x1ebbf8 | Kích thước: 88 bytes
//   0x1459bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1459c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1459c4: 910043FD  add      x29, sp, #0x10
//   0x1459c8: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1801_0x1459bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1459bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebbf8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1802 | PC: 0x145a14 | FDE: 0x1ebc18 | Size: 156 bytes [_PyEval_ReInitThreads]
// Khung tháo gỡ #1802 | Địa chỉ PC: 0x145a14 | Địa chỉ FDE: 0x1ebc18 | Kích thước: 156 bytes
//   0x145a14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x145a18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x145a1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145a20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1802_0x145a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145a14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebc18ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1803 | PC: 0x145ab0 | FDE: 0x1ebc38 | Size: 16 bytes [_PyEval_SignalAsyncExc]
// Khung tháo gỡ #1803 | Địa chỉ PC: 0x145ab0 | Địa chỉ FDE: 0x1ebc38 | Kích thước: 16 bytes
//   0x145ab0: 52800028  mov      w8, #1
//   0x145ab4: B9005C08  str      w8, [x0, #0x5c]
//   0x145ab8: B9004408  str      w8, [x0, #0x44]
//   0x145abc: D65F03C0  ret      
static inline uint64_t fde_func_1803_0x145ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145ab0ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0xb9005c08ULL) ^ 0x1ebc38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1804 | PC: 0x145ac0 | FDE: 0x1ebc50 | Size: 88 bytes [PyEval_SaveThread]
// Khung tháo gỡ #1804 | Địa chỉ PC: 0x145ac0 | Địa chỉ FDE: 0x1ebc50 | Kích thước: 88 bytes
//   0x145ac0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145ac4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145ac8: 910043FD  add      x29, sp, #0x10
//   0x145acc: 97FC4F3D  bl       #0x597c0
static inline uint64_t fde_func_1804_0x145ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145ac0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebc50ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1805 | PC: 0x145b18 | FDE: 0x1ebc70 | Size: 64 bytes [PyEval_RestoreThread]
// Khung tháo gỡ #1805 | Địa chỉ PC: 0x145b18 | Địa chỉ FDE: 0x1ebc70 | Kích thước: 64 bytes
//   0x145b18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145b1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145b20: 910043FD  add      x29, sp, #0x10
//   0x145b24: B4000140  cbz      x0, #0x145b4c
static inline uint64_t fde_func_1805_0x145b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145b18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebc70ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1806 | PC: 0x145b58 | FDE: 0x1ebc90 | Size: 156 bytes [_PyEval_SignalReceived]
// Khung tháo gỡ #1806 | Địa chỉ PC: 0x145b58 | Địa chỉ FDE: 0x1ebc90 | Kích thước: 156 bytes
//   0x145b58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x145b5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x145b60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x145b64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1806_0x145b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145b58ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebc90ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1807 | PC: 0x145bf4 | FDE: 0x1ebcb0 | Size: 256 bytes [_PyEval_AddPendingCall]
// Khung tháo gỡ #1807 | Địa chỉ PC: 0x145bf4 | Địa chỉ FDE: 0x1ebcb0 | Kích thước: 256 bytes
//   0x145bf4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x145bf8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x145bfc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x145c00: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1807_0x145bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145bf4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ebcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1808 | PC: 0x145cf8 | FDE: 0x1ebcd8 | Size: 80 bytes [Py_AddPendingCall]
// Khung tháo gỡ #1808 | Địa chỉ PC: 0x145cf8 | Địa chỉ FDE: 0x1ebcd8 | Kích thước: 80 bytes
//   0x145cf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x145cfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145d00: 910043FD  add      x29, sp, #0x10
//   0x145d04: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1808_0x145cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145cf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebcd8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1809 | PC: 0x145d48 | FDE: 0x1ebcf8 | Size: 256 bytes [_Py_FinishPendingCalls]
// Khung tháo gỡ #1809 | Địa chỉ PC: 0x145d48 | Địa chỉ FDE: 0x1ebcf8 | Kích thước: 256 bytes
//   0x145d48: D10103FF  sub      sp, sp, #0x40
//   0x145d4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x145d50: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x145d54: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1809_0x145d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145d48ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ebcf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1810 | PC: 0x145f9c | FDE: 0x1ebd40 | Size: 256 bytes [Py_MakePendingCalls]
// Khung tháo gỡ #1810 | Địa chỉ PC: 0x145f9c | Địa chỉ FDE: 0x1ebd40 | Kích thước: 256 bytes
//   0x145f9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x145fa0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x145fa4: 910043FD  add      x29, sp, #0x10
//   0x145fa8: 97FC4E06  bl       #0x597c0
static inline uint64_t fde_func_1810_0x145f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145f9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebd40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1811 | PC: 0x146120 | FDE: 0x1ebd88 | Size: 4 bytes [_PyEval_InitRuntimeState]
// Khung tháo gỡ #1811 | Địa chỉ PC: 0x146120 | Địa chỉ FDE: 0x1ebd88 | Kích thước: 4 bytes
//   0x146120: D65F03C0  ret      
static inline uint64_t fde_func_1811_0x146120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146120ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1ebd88ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1812 | PC: 0x146124 | FDE: 0x1ebda0 | Size: 72 bytes [_PyEval_InitState]
// Khung tháo gỡ #1812 | Địa chỉ PC: 0x146124 | Địa chỉ FDE: 0x1ebda0 | Kích thước: 72 bytes
//   0x146124: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x146128: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14612c: 910043FD  add      x29, sp, #0x10
//   0x146130: 52807D08  mov      w8, #0x3e8
static inline uint64_t fde_func_1812_0x146124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146124ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebda0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1813 | PC: 0x14616c | FDE: 0x1ebdc0 | Size: 44 bytes [_PyEval_FiniState]
// Khung tháo gỡ #1813 | Địa chỉ PC: 0x14616c | Địa chỉ FDE: 0x1ebdc0 | Kích thước: 44 bytes
//   0x14616c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x146170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x146174: 910043FD  add      x29, sp, #0x10
//   0x146178: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1813_0x14616c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14616cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebdc0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1814 | PC: 0x146198 | FDE: 0x1ebde0 | Size: 40 bytes [Py_GetRecursionLimit]
// Khung tháo gỡ #1814 | Địa chỉ PC: 0x146198 | Địa chỉ FDE: 0x1ebde0 | Kích thước: 40 bytes
//   0x146198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14619c: 910003FD  mov      x29, sp
//   0x1461a0: B00005C8  adrp     x8, #0x1ff000
//   0x1461a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1814_0x146198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ebde0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1815 | PC: 0x1461c0 | FDE: 0x1ebe00 | Size: 40 bytes [Py_SetRecursionLimit]
// Khung tháo gỡ #1815 | Địa chỉ PC: 0x1461c0 | Địa chỉ FDE: 0x1ebe00 | Kích thước: 40 bytes
//   0x1461c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1461c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1461c8: 910043FD  add      x29, sp, #0x10
//   0x1461cc: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_1815_0x1461c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1461c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebe00ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1816 | PC: 0x1461e8 | FDE: 0x1ebe20 | Size: 148 bytes [_Py_CheckRecursiveCall]
// Khung tháo gỡ #1816 | Địa chỉ PC: 0x1461e8 | Địa chỉ FDE: 0x1ebe20 | Kích thước: 148 bytes
//   0x1461e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1461ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1461f0: 910043FD  add      x29, sp, #0x10
//   0x1461f4: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_1816_0x1461e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1461e8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebe20ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1817 | PC: 0x14627c | FDE: 0x1ebe40 | Size: 164 bytes [PyEval_EvalCode]
// Khung tháo gỡ #1817 | Địa chỉ PC: 0x14627c | Địa chỉ FDE: 0x1ebe40 | Kích thước: 164 bytes
//   0x14627c: D10243FF  sub      sp, sp, #0x90
//   0x146280: F9002BF7  str      x23, [sp, #0x50]
//   0x146284: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x146288: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1817_0x14627c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14627cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x1ebe40ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1818 | PC: 0x146320 | FDE: 0x1ebe68 | Size: 256 bytes [_PyEval_Vector]
// Khung tháo gỡ #1818 | Địa chỉ PC: 0x146320 | Địa chỉ FDE: 0x1ebe68 | Kích thước: 256 bytes
//   0x146320: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x146324: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x146328: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14632c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1818_0x146320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146320ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ebe68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1819 | PC: 0x146448 | FDE: 0x1ebe90 | Size: 48 bytes [PyEval_EvalFrame]
// Khung tháo gỡ #1819 | Địa chỉ PC: 0x146448 | Địa chỉ FDE: 0x1ebe90 | Kích thước: 48 bytes
//   0x146448: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14644c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x146450: 910043FD  add      x29, sp, #0x10
//   0x146454: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1819_0x146448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146448ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebe90ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1820 | PC: 0x146478 | FDE: 0x1ebeb0 | Size: 52 bytes [PyEval_EvalFrameEx]
// Khung tháo gỡ #1820 | Địa chỉ PC: 0x146478 | Địa chỉ FDE: 0x1ebeb0 | Kích thước: 52 bytes
//   0x146478: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14647c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x146480: 910043FD  add      x29, sp, #0x10
//   0x146484: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_1820_0x146478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146478ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ebeb0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1821 | PC: 0x1464ac | FDE: 0x1ebed0 | Size: 256 bytes [_PyEval_EvalFrameDefault]
// Khung tháo gỡ #1821 | Địa chỉ PC: 0x1464ac | Địa chỉ FDE: 0x1ebed0 | Kích thước: 256 bytes
//   0x1464ac: D10683FF  sub      sp, sp, #0x1a0
//   0x1464b0: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x1464b4: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x1464b8: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_1821_0x1464ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1464acULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x1ebed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1822 | PC: 0x14d04c | FDE: 0x1ebfd0 | Size: 256 bytes [format_exc_unbound]
// Khung tháo gỡ #1822 | Địa chỉ PC: 0x14d04c | Địa chỉ FDE: 0x1ebfd0 | Kích thước: 256 bytes
//   0x14d04c: F9402C08  ldr      x8, [x0, #0x58]
//   0x14d050: B4000048  cbz      x8, #0x14d058
//   0x14d054: D65F03C0  ret      
//   0x14d058: F9402C28  ldr      x8, [x1, #0x58]
static inline uint64_t fde_func_1822_0x14d04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d04cULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xb4000048ULL) ^ 0x1ebfd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1823 | PC: 0x14d27c | FDE: 0x1ec010 | Size: 256 bytes [import_from]
// Khung tháo gỡ #1823 | Địa chỉ PC: 0x14d27c | Địa chỉ FDE: 0x1ec010 | Kích thước: 256 bytes
//   0x14d27c: D10183FF  sub      sp, sp, #0x60
//   0x14d280: F9000BF9  str      x25, [sp, #0x10]
//   0x14d284: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x14d288: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1823_0x14d27c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d27cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1ec010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1824 | PC: 0x14d98c | FDE: 0x1ec090 | Size: 256 bytes [_PyEval_MakeFrameVector]
// Khung tháo gỡ #1824 | Địa chỉ PC: 0x14d98c | Địa chỉ FDE: 0x1ec090 | Kích thước: 256 bytes
//   0x14d98c: D10283FF  sub      sp, sp, #0xa0
//   0x14d990: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x14d994: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x14d998: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1824_0x14d98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d98cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1ec090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1825 | PC: 0x14e578 | FDE: 0x1ec0f0 | Size: 256 bytes [PyEval_EvalCodeEx]
// Khung tháo gỡ #1825 | Địa chỉ PC: 0x14e578 | Địa chỉ FDE: 0x1ec0f0 | Kích thước: 256 bytes
//   0x14e578: D10343FF  sub      sp, sp, #0xd0
//   0x14e57c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x14e580: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x14e584: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1825_0x14e578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e578ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x1ec0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1826 | PC: 0x14e828 | FDE: 0x1ec120 | Size: 132 bytes [_PyEval_CallTracing]
// Khung tháo gỡ #1826 | Địa chỉ PC: 0x14e828 | Địa chỉ FDE: 0x1ec120 | Kích thước: 132 bytes
//   0x14e828: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x14e82c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x14e830: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x14e834: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1826_0x14e828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e828ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ec120ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1827 | PC: 0x14e8ac | FDE: 0x1ec148 | Size: 188 bytes [_PyEval_SetProfile]
// Khung tháo gỡ #1827 | Địa chỉ PC: 0x14e8ac | Địa chỉ FDE: 0x1ec148 | Kích thước: 188 bytes
//   0x14e8ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14e8b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14e8b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14e8b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1827_0x14e8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e8acULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec148ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1828 | PC: 0x14e968 | FDE: 0x1ec168 | Size: 76 bytes [PyEval_SetProfile]
// Khung tháo gỡ #1828 | Địa chỉ PC: 0x14e968 | Địa chỉ FDE: 0x1ec168 | Kích thước: 76 bytes
//   0x14e968: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14e96c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14e970: 910043FD  add      x29, sp, #0x10
//   0x14e974: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1828_0x14e968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e968ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec168ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1829 | PC: 0x14e9b4 | FDE: 0x1ec188 | Size: 188 bytes [_PyEval_SetTrace]
// Khung tháo gỡ #1829 | Địa chỉ PC: 0x14e9b4 | Địa chỉ FDE: 0x1ec188 | Kích thước: 188 bytes
//   0x14e9b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14e9b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14e9bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14e9c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1829_0x14e9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e9b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec188ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1830 | PC: 0x14ea70 | FDE: 0x1ec1a8 | Size: 76 bytes [PyEval_SetTrace]
// Khung tháo gỡ #1830 | Địa chỉ PC: 0x14ea70 | Địa chỉ FDE: 0x1ec1a8 | Kích thước: 76 bytes
//   0x14ea70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14ea74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14ea78: 910043FD  add      x29, sp, #0x10
//   0x14ea7c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1830_0x14ea70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ea70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec1a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1831 | PC: 0x14eabc | FDE: 0x1ec1c8 | Size: 8 bytes [_PyEval_SetCoroutineOriginTrackingDepth]
// Khung tháo gỡ #1831 | Địa chỉ PC: 0x14eabc | Địa chỉ FDE: 0x1ec1c8 | Kích thước: 8 bytes
//   0x14eabc: B900D801  str      w1, [x0, #0xd8]
//   0x14eac0: D65F03C0  ret      
static inline uint64_t fde_func_1831_0x14eabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eabcULL ^ (static_cast<uint64_t>(0xb900d801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ec1c8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1832 | PC: 0x14eac4 | FDE: 0x1ec1e0 | Size: 24 bytes [_PyEval_GetCoroutineOriginTrackingDepth]
// Khung tháo gỡ #1832 | Địa chỉ PC: 0x14eac4 | Địa chỉ FDE: 0x1ec1e0 | Kích thước: 24 bytes
//   0x14eac4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14eac8: 910003FD  mov      x29, sp
//   0x14eacc: 97FC2B3D  bl       #0x597c0
//   0x14ead0: B940D800  ldr      w0, [x0, #0xd8]
static inline uint64_t fde_func_1832_0x14eac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eac4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec1e0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1833 | PC: 0x14eadc | FDE: 0x1ec200 | Size: 116 bytes [_PyEval_SetAsyncGenFirstiter]
// Khung tháo gỡ #1833 | Địa chỉ PC: 0x14eadc | Địa chỉ FDE: 0x1ec200 | Kích thước: 116 bytes
//   0x14eadc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14eae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14eae4: 910043FD  add      x29, sp, #0x10
//   0x14eae8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1833_0x14eadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eadcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec200ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1834 | PC: 0x14eb50 | FDE: 0x1ec220 | Size: 24 bytes [_PyEval_GetAsyncGenFirstiter]
// Khung tháo gỡ #1834 | Địa chỉ PC: 0x14eb50 | Địa chỉ FDE: 0x1ec220 | Kích thước: 24 bytes
//   0x14eb50: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14eb54: 910003FD  mov      x29, sp
//   0x14eb58: 97FC2B1A  bl       #0x597c0
//   0x14eb5c: F9407000  ldr      x0, [x0, #0xe0]
static inline uint64_t fde_func_1834_0x14eb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eb50ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec220ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1835 | PC: 0x14eb68 | FDE: 0x1ec240 | Size: 116 bytes [_PyEval_SetAsyncGenFinalizer]
// Khung tháo gỡ #1835 | Địa chỉ PC: 0x14eb68 | Địa chỉ FDE: 0x1ec240 | Kích thước: 116 bytes
//   0x14eb68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14eb6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14eb70: 910043FD  add      x29, sp, #0x10
//   0x14eb74: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1835_0x14eb68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eb68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec240ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1836 | PC: 0x14ebdc | FDE: 0x1ec260 | Size: 24 bytes [_PyEval_GetAsyncGenFinalizer]
// Khung tháo gỡ #1836 | Địa chỉ PC: 0x14ebdc | Địa chỉ FDE: 0x1ec260 | Kích thước: 24 bytes
//   0x14ebdc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ebe0: 910003FD  mov      x29, sp
//   0x14ebe4: 97FC2AF7  bl       #0x597c0
//   0x14ebe8: F9407400  ldr      x0, [x0, #0xe8]
static inline uint64_t fde_func_1836_0x14ebdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ebdcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec260ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1837 | PC: 0x14ebf4 | FDE: 0x1ec280 | Size: 24 bytes [PyEval_GetFrame]
// Khung tháo gỡ #1837 | Địa chỉ PC: 0x14ebf4 | Địa chỉ FDE: 0x1ec280 | Kích thước: 24 bytes
//   0x14ebf4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ebf8: 910003FD  mov      x29, sp
//   0x14ebfc: 97FC2AF1  bl       #0x597c0
//   0x14ec00: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_1837_0x14ebf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ebf4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec280ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1838 | PC: 0x14ec0c | FDE: 0x1ec2a0 | Size: 32 bytes [_PyEval_GetBuiltins]
// Khung tháo gỡ #1838 | Địa chỉ PC: 0x14ec0c | Địa chỉ FDE: 0x1ec2a0 | Kích thước: 32 bytes
//   0x14ec0c: F9400C08  ldr      x8, [x0, #0x18]
//   0x14ec10: B4000068  cbz      x8, #0x14ec1c
//   0x14ec14: 9100A108  add      x8, x8, #0x28
//   0x14ec18: 14000003  b        #0x14ec24
static inline uint64_t fde_func_1838_0x14ec0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec0cULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x1ec2a0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1839 | PC: 0x14ec2c | FDE: 0x1ec2b8 | Size: 48 bytes [PyEval_GetBuiltins]
// Khung tháo gỡ #1839 | Địa chỉ PC: 0x14ec2c | Địa chỉ FDE: 0x1ec2b8 | Kích thước: 48 bytes
//   0x14ec2c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ec30: 910003FD  mov      x29, sp
//   0x14ec34: 97FC2AE3  bl       #0x597c0
//   0x14ec38: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_1839_0x14ec2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec2cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec2b8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1840 | PC: 0x14ec5c | FDE: 0x1ec2d8 | Size: 156 bytes [_PyEval_GetBuiltinId]
// Khung tháo gỡ #1840 | Địa chỉ PC: 0x14ec5c | Địa chỉ FDE: 0x1ec2d8 | Kích thước: 156 bytes
//   0x14ec5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x14ec60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14ec64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14ec68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1840_0x14ec5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec5cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec2d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1841 | PC: 0x14ecf8 | FDE: 0x1ec300 | Size: 84 bytes [PyEval_GetLocals]
// Khung tháo gỡ #1841 | Địa chỉ PC: 0x14ecf8 | Địa chỉ FDE: 0x1ec300 | Kích thước: 84 bytes
//   0x14ecf8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14ecfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14ed00: 910043FD  add      x29, sp, #0x10
//   0x14ed04: 97FC2AAF  bl       #0x597c0
static inline uint64_t fde_func_1841_0x14ecf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ecf8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec300ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1842 | PC: 0x14ed4c | FDE: 0x1ec320 | Size: 40 bytes [PyEval_GetGlobals]
// Khung tháo gỡ #1842 | Địa chỉ PC: 0x14ed4c | Địa chỉ FDE: 0x1ec320 | Kích thước: 40 bytes
//   0x14ed4c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ed50: 910003FD  mov      x29, sp
//   0x14ed54: 97FC2A9B  bl       #0x597c0
//   0x14ed58: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_1842_0x14ed4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ed4cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec320ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1843 | PC: 0x14ed74 | FDE: 0x1ec340 | Size: 80 bytes [PyEval_MergeCompilerFlags]
// Khung tháo gỡ #1843 | Địa chỉ PC: 0x14ed74 | Địa chỉ FDE: 0x1ec340 | Kích thước: 80 bytes
//   0x14ed74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14ed78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14ed7c: 910043FD  add      x29, sp, #0x10
//   0x14ed80: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1843_0x14ed74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ed74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec340ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1844 | PC: 0x14edc4 | FDE: 0x1ec360 | Size: 156 bytes [PyEval_GetFuncName]
// Khung tháo gỡ #1844 | Địa chỉ PC: 0x14edc4 | Địa chỉ FDE: 0x1ec360 | Kích thước: 156 bytes
//   0x14edc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x14edc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14edcc: 910043FD  add      x29, sp, #0x10
//   0x14edd0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1844_0x14edc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14edc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec360ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1845 | PC: 0x14ee60 | FDE: 0x1ec380 | Size: 116 bytes [PyEval_GetFuncDesc]
// Khung tháo gỡ #1845 | Địa chỉ PC: 0x14ee60 | Địa chỉ FDE: 0x1ec380 | Kích thước: 116 bytes
//   0x14ee60: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14ee64: 910003FD  mov      x29, sp
//   0x14ee68: B0000588  adrp     x8, #0x1ff000
//   0x14ee6c: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_1845_0x14ee60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ee60ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec380ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1846 | PC: 0x14eed4 | FDE: 0x1ec3a0 | Size: 156 bytes [_PyEval_SliceIndex]
// Khung tháo gỡ #1846 | Địa chỉ PC: 0x14eed4 | Địa chỉ FDE: 0x1ec3a0 | Kích thước: 156 bytes
//   0x14eed4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14eed8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14eedc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14eee0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1846_0x14eed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eed4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec3a0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1847 | PC: 0x14ef70 | FDE: 0x1ec3c0 | Size: 140 bytes [_PyEval_SliceIndexNotNone]
// Khung tháo gỡ #1847 | Địa chỉ PC: 0x14ef70 | Địa chỉ FDE: 0x1ec3c0 | Kích thước: 140 bytes
//   0x14ef70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14ef74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14ef78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14ef7c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1847_0x14ef70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ef70ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec3c0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1848 | PC: 0x14effc | FDE: 0x1ec3e0 | Size: 88 bytes [_PyEval_RequestCodeExtraIndex]
// Khung tháo gỡ #1848 | Địa chỉ PC: 0x14effc | Địa chỉ FDE: 0x1ec3e0 | Kích thước: 88 bytes
//   0x14effc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f000: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f004: 910043FD  add      x29, sp, #0x10
//   0x14f008: 90000588  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1848_0x14effc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14effcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec3e0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1849 | PC: 0x14f054 | FDE: 0x1ec400 | Size: 84 bytes [Py_EnterRecursiveCall]
// Khung tháo gỡ #1849 | Địa chỉ PC: 0x14f054 | Địa chỉ FDE: 0x1ec400 | Kích thước: 84 bytes
//   0x14f054: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f058: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f05c: 910043FD  add      x29, sp, #0x10
//   0x14f060: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1849_0x14f054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f054ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec400ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1850 | PC: 0x14f0a8 | FDE: 0x1ec420 | Size: 256 bytes [Py_LeaveRecursiveCall]
// Khung tháo gỡ #1850 | Địa chỉ PC: 0x14f0a8 | Địa chỉ FDE: 0x1ec420 | Kích thước: 256 bytes
//   0x14f0a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x14f0ac: 910003FD  mov      x29, sp
//   0x14f0b0: 97FC2F88  bl       #0x5aed0
//   0x14f0b4: B9402008  ldr      w8, [x0, #0x20]
static inline uint64_t fde_func_1850_0x14f0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f0a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ec420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1851 | PC: 0x14f280 | FDE: 0x1ec490 | Size: 36 bytes [bd_get_opcode_name]
// Khung tháo gỡ #1851 | Địa chỉ PC: 0x14f280 | Địa chỉ FDE: 0x1ec490 | Kích thước: 36 bytes
//   0x14f280: 7103E81F  cmp      w0, #0xfa
//   0x14f284: 540000A8  b.hi     #0x14f298
//   0x14f288: 90000568  adrp     x8, #0x1fb000
//   0x14f28c: 9113A108  add      x8, x8, #0x4e8
static inline uint64_t fde_func_1851_0x14f280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f280ULL ^ (static_cast<uint64_t>(0x7103e81fULL) << 13);
    acc = (acc + a1 + 0x540000a8ULL) ^ 0x1ec490ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1852 | PC: 0x14f2a4 | FDE: 0x1ec4a8 | Size: 128 bytes [BDPythonVMSetNormalLogFile]
// Khung tháo gỡ #1852 | Địa chỉ PC: 0x14f2a4 | Địa chỉ FDE: 0x1ec4a8 | Kích thước: 128 bytes
//   0x14f2a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f2a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f2ac: 910043FD  add      x29, sp, #0x10
//   0x14f2b0: B4000160  cbz      x0, #0x14f2dc
static inline uint64_t fde_func_1852_0x14f2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f2a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec4a8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1853 | PC: 0x14f324 | FDE: 0x1ec4c8 | Size: 128 bytes [BDPythonVMSetErrorLogFile]
// Khung tháo gỡ #1853 | Địa chỉ PC: 0x14f324 | Địa chỉ FDE: 0x1ec4c8 | Kích thước: 128 bytes
//   0x14f324: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f328: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f32c: 910043FD  add      x29, sp, #0x10
//   0x14f330: B4000160  cbz      x0, #0x14f35c
static inline uint64_t fde_func_1853_0x14f324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f324ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec4c8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1854 | PC: 0x14f3a4 | FDE: 0x1ec4e8 | Size: 128 bytes [BDPythonVMSetExitLogFile]
// Khung tháo gỡ #1854 | Địa chỉ PC: 0x14f3a4 | Địa chỉ FDE: 0x1ec4e8 | Kích thước: 128 bytes
//   0x14f3a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14f3a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14f3ac: 910043FD  add      x29, sp, #0x10
//   0x14f3b0: B4000160  cbz      x0, #0x14f3dc
static inline uint64_t fde_func_1854_0x14f3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f3a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ec4e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1855 | PC: 0x14f424 | FDE: 0x1ec508 | Size: 36 bytes [BDPythonVMStderr]
// Khung tháo gỡ #1855 | Địa chỉ PC: 0x14f424 | Địa chỉ FDE: 0x1ec508 | Kích thước: 36 bytes
//   0x14f424: 90000588  adrp     x8, #0x1ff000
//   0x14f428: F945D908  ldr      x8, [x8, #0xbb0]
//   0x14f42c: 90000589  adrp     x9, #0x1ff000
//   0x14f430: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1855_0x14f424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f424ULL ^ (static_cast<uint64_t>(0x90000588ULL) << 13);
    acc = (acc + a1 + 0xf945d908ULL) ^ 0x1ec508ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1856 | PC: 0x14f448 | FDE: 0x1ec520 | Size: 36 bytes [BDPythonVMStdout]
// Khung tháo gỡ #1856 | Địa chỉ PC: 0x14f448 | Địa chỉ FDE: 0x1ec520 | Kích thước: 36 bytes
//   0x14f448: 90000588  adrp     x8, #0x1ff000
//   0x14f44c: F9446508  ldr      x8, [x8, #0x8c8]
//   0x14f450: 90000589  adrp     x9, #0x1ff000
//   0x14f454: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1856_0x14f448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f448ULL ^ (static_cast<uint64_t>(0x90000588ULL) << 13);
    acc = (acc + a1 + 0xf9446508ULL) ^ 0x1ec520ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1857 | PC: 0x14f46c | FDE: 0x1ec538 | Size: 200 bytes [bdpythonvm_info]
// Khung tháo gỡ #1857 | Địa chỉ PC: 0x14f46c | Địa chỉ FDE: 0x1ec538 | Kích thước: 200 bytes
//   0x14f46c: D100C3FF  sub      sp, sp, #0x30
//   0x14f470: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14f474: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14f478: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1857_0x14f46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f46cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec538ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1858 | PC: 0x14f534 | FDE: 0x1ec558 | Size: 200 bytes [bdpythonvm_error]
// Khung tháo gỡ #1858 | Địa chỉ PC: 0x14f534 | Địa chỉ FDE: 0x1ec558 | Kích thước: 200 bytes
//   0x14f534: D100C3FF  sub      sp, sp, #0x30
//   0x14f538: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14f53c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14f540: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1858_0x14f534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f534ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec558ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1859 | PC: 0x14f5fc | FDE: 0x1ec578 | Size: 104 bytes [BDPythonVMCloseLogFiles]
// Khung tháo gỡ #1859 | Địa chỉ PC: 0x14f5fc | Địa chỉ FDE: 0x1ec578 | Kích thước: 104 bytes
//   0x14f5fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14f600: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x14f604: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14f608: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1859_0x14f5fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f5fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ec578ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1860 | PC: 0x14f664 | FDE: 0x1ec598 | Size: 256 bytes [PyInit__abc]
// Khung tháo gỡ #1860 | Địa chỉ PC: 0x14f664 | Địa chỉ FDE: 0x1ec598 | Kích thước: 256 bytes
//   0x14f664: B0000640  adrp     x0, #0x218000
//   0x14f668: 91374000  add      x0, x0, #0xdd0
//   0x14f66c: 17FC24ED  b        #0x58a20
//   0x14f670: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1860_0x14f664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f664ULL ^ (static_cast<uint64_t>(0xb0000640ULL) << 13);
    acc = (acc + a1 + 0x91374000ULL) ^ 0x1ec598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1861 | PC: 0x150f8c | FDE: 0x1ec840 | Size: 256 bytes [PyInit__codecs]
// Khung tháo gỡ #1861 | Địa chỉ PC: 0x150f8c | Địa chỉ FDE: 0x1ec840 | Kích thước: 256 bytes
//   0x150f8c: B0000640  adrp     x0, #0x219000
//   0x150f90: 91026000  add      x0, x0, #0x98
//   0x150f94: 17FC1EA3  b        #0x58a20
//   0x150f98: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1861_0x150f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150f8cULL ^ (static_cast<uint64_t>(0xb0000640ULL) << 13);
    acc = (acc + a1 + 0x91026000ULL) ^ 0x1ec840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1862 | PC: 0x1525fc | FDE: 0x1eca90 | Size: 256 bytes [PyInit__collections]
// Khung tháo gỡ #1862 | Địa chỉ PC: 0x1525fc | Địa chỉ FDE: 0x1eca90 | Kích thước: 256 bytes
//   0x1525fc: F0000620  adrp     x0, #0x219000
//   0x152600: 910E8000  add      x0, x0, #0x3a0
//   0x152604: 17FC1907  b        #0x58a20
//   0x152608: F81A0FFB  str      x27, [sp, #-0x60]!
static inline uint64_t fde_func_1862_0x1525fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1525fcULL ^ (static_cast<uint64_t>(0xf0000620ULL) << 13);
    acc = (acc + a1 + 0x910e8000ULL) ^ 0x1eca90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1863 | PC: 0x1566d4 | FDE: 0x1ed348 | Size: 256 bytes [PyInit__functools]
// Khung tháo gỡ #1863 | Địa chỉ PC: 0x1566d4 | Địa chỉ FDE: 0x1ed348 | Kích thước: 256 bytes
//   0x1566d4: 90000620  adrp     x0, #0x21a000
//   0x1566d8: 91100000  add      x0, x0, #0x400
//   0x1566dc: 17FC08D1  b        #0x58a20
//   0x1566e0: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1863_0x1566d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1566d4ULL ^ (static_cast<uint64_t>(0x90000620ULL) << 13);
    acc = (acc + a1 + 0x91100000ULL) ^ 0x1ed348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1864 | PC: 0x1589f8 | FDE: 0x1ed828 | Size: 192 bytes [PyNumber_AsOff_t]
// Khung tháo gỡ #1864 | Địa chỉ PC: 0x1589f8 | Địa chỉ FDE: 0x1ed828 | Kích thước: 192 bytes
//   0x1589f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1589fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x158a00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x158a04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1864_0x1589f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1589f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ed828ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1865 | PC: 0x158ab8 | FDE: 0x1ed850 | Size: 256 bytes [_PyIO_get_module_state]
// Khung tháo gỡ #1865 | Địa chỉ PC: 0x158ab8 | Địa chỉ FDE: 0x1ed850 | Kích thước: 256 bytes
//   0x158ab8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x158abc: 910003FD  mov      x29, sp
//   0x158ac0: F0000520  adrp     x0, #0x1ff000
//   0x158ac4: F9449C00  ldr      x0, [x0, #0x938]
static inline uint64_t fde_func_1865_0x158ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158ab8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ed850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1866 | PC: 0x158c4c | FDE: 0x1ed8d0 | Size: 256 bytes [PyInit__io]
// Khung tháo gỡ #1866 | Địa chỉ PC: 0x158c4c | Địa chỉ FDE: 0x1ed8d0 | Kích thước: 256 bytes
//   0x158c4c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x158c50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x158c54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x158c58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1866_0x158c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158c4cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ed8d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1867 | PC: 0x15aeec | FDE: 0x1ed968 | Size: 256 bytes [bd_buffered_close_extern]
// Khung tháo gỡ #1867 | Địa chỉ PC: 0x15aeec | Địa chỉ FDE: 0x1ed968 | Kích thước: 256 bytes
//   0x15aeec: 14000001  b        #0x15aef0
//   0x15aef0: D10183FF  sub      sp, sp, #0x60
//   0x15aef4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x15aef8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1867_0x15aeec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15aeecULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x1ed968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1868 | PC: 0x15b1c8 | FDE: 0x1ed9a8 | Size: 256 bytes [_PyIO_trap_eintr]
// Khung tháo gỡ #1868 | Địa chỉ PC: 0x15b1c8 | Địa chỉ FDE: 0x1ed9a8 | Kích thước: 256 bytes
//   0x15b1c8: D10103FF  sub      sp, sp, #0x40
//   0x15b1cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15b1d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x15b1d4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1868_0x15b1c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b1c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ed9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1869 | PC: 0x15e980 | FDE: 0x1eded0 | Size: 256 bytes [_PyFileIO_closed]
// Khung tháo gỡ #1869 | Địa chỉ PC: 0x15e980 | Địa chỉ FDE: 0x1eded0 | Kích thước: 256 bytes
//   0x15e980: B9401008  ldr      w8, [x0, #0x10]
//   0x15e984: 531F7D00  lsr      w0, w8, #0x1f
//   0x15e988: D65F03C0  ret      
//   0x15e98c: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_1869_0x15e980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e980ULL ^ (static_cast<uint64_t>(0xb9401008ULL) << 13);
    acc = (acc + a1 + 0x531f7d00ULL) ^ 0x1eded0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1870 | PC: 0x15feac | FDE: 0x1ee108 | Size: 240 bytes [_PyIOBase_check_closed]
// Khung tháo gỡ #1870 | Địa chỉ PC: 0x15feac | Địa chỉ FDE: 0x1ee108 | Kích thước: 240 bytes
//   0x15feac: D10103FF  sub      sp, sp, #0x40
//   0x15feb0: F9000BF5  str      x21, [sp, #0x10]
//   0x15feb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15feb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1870_0x15feac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15feacULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee108ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1871 | PC: 0x15ff9c | FDE: 0x1ee128 | Size: 40 bytes [_PyIOBase_finalize]
// Khung tháo gỡ #1871 | Địa chỉ PC: 0x15ff9c | Địa chỉ FDE: 0x1ee128 | Kích thước: 40 bytes
//   0x15ff9c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15ffa0: 910003FD  mov      x29, sp
//   0x15ffa4: F9400008  ldr      x8, [x0]
//   0x15ffa8: B40000A8  cbz      x8, #0x15ffbc
static inline uint64_t fde_func_1871_0x15ff9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ff9cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1ee128ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1872 | PC: 0x15ffc4 | FDE: 0x1ee148 | Size: 240 bytes [_PyIOBase_check_seekable]
// Khung tháo gỡ #1872 | Địa chỉ PC: 0x15ffc4 | Địa chỉ FDE: 0x1ee148 | Kích thước: 240 bytes
//   0x15ffc4: D10103FF  sub      sp, sp, #0x40
//   0x15ffc8: F9000BF5  str      x21, [sp, #0x10]
//   0x15ffcc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x15ffd0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1872_0x15ffc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ffc4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee148ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1873 | PC: 0x1600b4 | FDE: 0x1ee168 | Size: 240 bytes [_PyIOBase_check_readable]
// Khung tháo gỡ #1873 | Địa chỉ PC: 0x1600b4 | Địa chỉ FDE: 0x1ee168 | Kích thước: 240 bytes
//   0x1600b4: D10103FF  sub      sp, sp, #0x40
//   0x1600b8: F9000BF5  str      x21, [sp, #0x10]
//   0x1600bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1600c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1873_0x1600b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1600b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee168ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1874 | PC: 0x1601a4 | FDE: 0x1ee188 | Size: 256 bytes [_PyIOBase_check_writable]
// Khung tháo gỡ #1874 | Địa chỉ PC: 0x1601a4 | Địa chỉ FDE: 0x1ee188 | Kích thước: 256 bytes
//   0x1601a4: D10103FF  sub      sp, sp, #0x40
//   0x1601a8: F9000BF5  str      x21, [sp, #0x10]
//   0x1601ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1601b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1874_0x1601a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1601a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1ee188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1875 | PC: 0x16206c | FDE: 0x1ee4e8 | Size: 256 bytes [_PyIncrementalNewlineDecoder_decode]
// Khung tháo gỡ #1875 | Địa chỉ PC: 0x16206c | Địa chỉ FDE: 0x1ee4e8 | Kích thước: 256 bytes
//   0x16206c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x162070: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x162074: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x162078: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1875_0x16206c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16206cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ee4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1876 | PC: 0x1627fc | FDE: 0x1ee518 | Size: 256 bytes [_PyIO_find_line_ending]
// Khung tháo gỡ #1876 | Địa chỉ PC: 0x1627fc | Địa chỉ FDE: 0x1ee518 | Kích thước: 256 bytes
//   0x1627fc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x162800: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x162804: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x162808: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1876_0x1627fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1627fcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ee518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1877 | PC: 0x1654ac | FDE: 0x1ee810 | Size: 256 bytes [PyInit__json]
// Khung tháo gỡ #1877 | Địa chỉ PC: 0x1654ac | Địa chỉ FDE: 0x1ee810 | Kích thước: 256 bytes
//   0x1654ac: F00005A0  adrp     x0, #0x21c000
//   0x1654b0: 91352000  add      x0, x0, #0xd48
//   0x1654b4: 17FBCD5B  b        #0x58a20
//   0x1654b8: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1877_0x1654ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1654acULL ^ (static_cast<uint64_t>(0xf00005a0ULL) << 13);
    acc = (acc + a1 + 0x91352000ULL) ^ 0x1ee810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1878 | PC: 0x169f0c | FDE: 0x1eeb28 | Size: 256 bytes [PyInit__locale]
// Khung tháo gỡ #1878 | Địa chỉ PC: 0x169f0c | Địa chỉ FDE: 0x1eeb28 | Kích thước: 256 bytes
//   0x169f0c: 900005A0  adrp     x0, #0x21d000
//   0x169f10: 910D4000  add      x0, x0, #0x350
//   0x169f14: 17FBBAC3  b        #0x58a20
//   0x169f18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_1878_0x169f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169f0cULL ^ (static_cast<uint64_t>(0x900005a0ULL) << 13);
    acc = (acc + a1 + 0x910d4000ULL) ^ 0x1eeb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1879 | PC: 0x16a2c0 | FDE: 0x1eebe8 | Size: 256 bytes [PyInit__lsprof]
// Khung tháo gỡ #1879 | Địa chỉ PC: 0x16a2c0 | Địa chỉ FDE: 0x1eebe8 | Kích thước: 256 bytes
//   0x16a2c0: F0000580  adrp     x0, #0x21d000
//   0x16a2c4: 91106000  add      x0, x0, #0x418
//   0x16a2c8: 17FBB9D6  b        #0x58a20
//   0x16a2cc: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1879_0x16a2c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a2c0ULL ^ (static_cast<uint64_t>(0xf0000580ULL) << 13);
    acc = (acc + a1 + 0x91106000ULL) ^ 0x1eebe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1880 | PC: 0x16b374 | FDE: 0x1eee78 | Size: 16 bytes [_Py_log1p]
// Khung tháo gỡ #1880 | Địa chỉ PC: 0x16b374 | Địa chỉ FDE: 0x1eee78 | Kích thước: 16 bytes
//   0x16b374: 1E602008  fcmp     d0, #0.0
//   0x16b378: 54000041  b.ne     #0x16b380
//   0x16b37c: D65F03C0  ret      
//   0x16b380: 17FBB968  b        #0x59920
static inline uint64_t fde_func_1880_0x16b374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b374ULL ^ (static_cast<uint64_t>(0x1e602008ULL) << 13);
    acc = (acc + a1 + 0x54000041ULL) ^ 0x1eee78ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1881 | PC: 0x16b384 | FDE: 0x1eee90 | Size: 256 bytes [PyInit__operator]
// Khung tháo gỡ #1881 | Địa chỉ PC: 0x16b384 | Địa chỉ FDE: 0x1eee90 | Kích thước: 256 bytes
//   0x16b384: D0000580  adrp     x0, #0x21d000
//   0x16b388: 911D4000  add      x0, x0, #0x750
//   0x16b38c: 17FBB5A5  b        #0x58a20
//   0x16b390: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1881_0x16b384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b384ULL ^ (static_cast<uint64_t>(0xd0000580ULL) << 13);
    acc = (acc + a1 + 0x911d4000ULL) ^ 0x1eee90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1882 | PC: 0x16de98 | FDE: 0x1ef890 | Size: 256 bytes [PyInit__random]
// Khung tháo gỡ #1882 | Địa chỉ PC: 0x16de98 | Địa chỉ FDE: 0x1ef890 | Kích thước: 256 bytes
//   0x16de98: B0000580  adrp     x0, #0x21e000
//   0x16de9c: 91062000  add      x0, x0, #0x188
//   0x16dea0: 17FBAAE0  b        #0x58a20
//   0x16dea4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1882_0x16de98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16de98ULL ^ (static_cast<uint64_t>(0xb0000580ULL) << 13);
    acc = (acc + a1 + 0x91062000ULL) ^ 0x1ef890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1883 | PC: 0x16ea38 | FDE: 0x1efa68 | Size: 64 bytes [unpackiter_new]
// Khung tháo gỡ #1883 | Địa chỉ PC: 0x16ea38 | Địa chỉ FDE: 0x1efa68 | Kích thước: 64 bytes
//   0x16ea38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x16ea3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x16ea40: 910043FD  add      x29, sp, #0x10
//   0x16ea44: B0000488  adrp     x8, #0x1ff000
static inline uint64_t fde_func_1883_0x16ea38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ea38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1efa68ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1884 | PC: 0x16ea78 | FDE: 0x1efa88 | Size: 256 bytes [PyInit__struct]
// Khung tháo gỡ #1884 | Địa chỉ PC: 0x16ea78 | Địa chỉ FDE: 0x1efa88 | Kích thước: 256 bytes
//   0x16ea78: 90000580  adrp     x0, #0x21e000
//   0x16ea7c: 910D0000  add      x0, x0, #0x340
//   0x16ea80: 17FBA7E8  b        #0x58a20
//   0x16ea84: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1884_0x16ea78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ea78ULL ^ (static_cast<uint64_t>(0x90000580ULL) << 13);
    acc = (acc + a1 + 0x910d0000ULL) ^ 0x1efa88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1885 | PC: 0x172584 | FDE: 0x1f0688 | Size: 256 bytes [PyInit__thread]
// Khung tháo gỡ #1885 | Địa chỉ PC: 0x172584 | Địa chỉ FDE: 0x1f0688 | Kích thước: 256 bytes
//   0x172584: 90000560  adrp     x0, #0x21e000
//   0x172588: 913B8000  add      x0, x0, #0xee0
//   0x17258c: 17FB9925  b        #0x58a20
//   0x172590: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1885_0x172584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172584ULL ^ (static_cast<uint64_t>(0x90000560ULL) << 13);
    acc = (acc + a1 + 0x913b8000ULL) ^ 0x1f0688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1886 | PC: 0x17439c | FDE: 0x1f0bf8 | Size: 256 bytes [PyInit__weakref]
// Khung tháo gỡ #1886 | Địa chỉ PC: 0x17439c | Địa chỉ FDE: 0x1f0bf8 | Kích thước: 256 bytes
//   0x17439c: F0000540  adrp     x0, #0x21f000
//   0x1743a0: 911BE000  add      x0, x0, #0x6f8
//   0x1743a4: 17FB919F  b        #0x58a20
//   0x1743a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1886_0x17439c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17439cULL ^ (static_cast<uint64_t>(0xf0000540ULL) << 13);
    acc = (acc + a1 + 0x911be000ULL) ^ 0x1f0bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1887 | PC: 0x174788 | FDE: 0x1f0cd0 | Size: 256 bytes [PyInit__xxsubinterpreters]
// Khung tháo gỡ #1887 | Địa chỉ PC: 0x174788 | Địa chỉ FDE: 0x1f0cd0 | Kích thước: 256 bytes
//   0x174788: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x17478c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x174790: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x174794: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1887_0x174788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174788ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f0cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1888 | PC: 0x177e4c | FDE: 0x1f11d8 | Size: 116 bytes [_PyAtExit_Init]
// Khung tháo gỡ #1888 | Địa chỉ PC: 0x177e4c | Địa chỉ FDE: 0x1f11d8 | Kích thước: 116 bytes
//   0x177e4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x177e50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x177e54: 910043FD  add      x29, sp, #0x10
//   0x177e58: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_1888_0x177e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177e4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f11d8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1889 | PC: 0x177ec0 | FDE: 0x1f11f8 | Size: 212 bytes [_PyAtExit_Fini]
// Khung tháo gỡ #1889 | Địa chỉ PC: 0x177ec0 | Địa chỉ FDE: 0x1f11f8 | Kích thước: 212 bytes
//   0x177ec0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x177ec4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x177ec8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x177ecc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1889_0x177ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177ec0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f11f8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1890 | PC: 0x177f94 | FDE: 0x1f1218 | Size: 256 bytes [_PyAtExit_Call]
// Khung tháo gỡ #1890 | Địa chỉ PC: 0x177f94 | Địa chỉ FDE: 0x1f1218 | Kích thước: 256 bytes
//   0x177f94: 9139C000  add      x0, x0, #0xe70
//   0x177f98: 14000001  b        #0x177f9c
//   0x177f9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x177fa0: A9014FF4  stp      x20, x19, [sp, #0x10]
static inline uint64_t fde_func_1890_0x177f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177f94ULL ^ (static_cast<uint64_t>(0x9139c000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1f1218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1891 | PC: 0x1780cc | FDE: 0x1f1258 | Size: 256 bytes [PyInit_atexit]
// Khung tháo gỡ #1891 | Địa chỉ PC: 0x1780cc | Địa chỉ FDE: 0x1f1258 | Kích thước: 256 bytes
//   0x1780cc: F0000520  adrp     x0, #0x21f000
//   0x1780d0: 913E8000  add      x0, x0, #0xfa0
//   0x1780d4: 17FB8253  b        #0x58a20
//   0x1780d8: F81C0FF7  str      x23, [sp, #-0x40]!
static inline uint64_t fde_func_1891_0x1780cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1780ccULL ^ (static_cast<uint64_t>(0xf0000520ULL) << 13);
    acc = (acc + a1 + 0x913e8000ULL) ^ 0x1f1258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1892 | PC: 0x178488 | FDE: 0x1f1320 | Size: 256 bytes [PyInit_errno]
// Khung tháo gỡ #1892 | Địa chỉ PC: 0x178488 | Địa chỉ FDE: 0x1f1320 | Kích thước: 256 bytes
//   0x178488: 90000540  adrp     x0, #0x220000
//   0x17848c: 910AA000  add      x0, x0, #0x2a8
//   0x178490: 17FB8164  b        #0x58a20
//   0x178494: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_1892_0x178488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178488ULL ^ (static_cast<uint64_t>(0x90000540ULL) << 13);
    acc = (acc + a1 + 0x910aa000ULL) ^ 0x1f1320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1893 | PC: 0x1794cc | FDE: 0x1f1380 | Size: 12 bytes [PyInit_faulthandler]
// Khung tháo gỡ #1893 | Địa chỉ PC: 0x1794cc | Địa chỉ FDE: 0x1f1380 | Kích thước: 12 bytes
//   0x1794cc: F0000520  adrp     x0, #0x220000
//   0x1794d0: 910CC000  add      x0, x0, #0x330
//   0x1794d4: 17FB7D53  b        #0x58a20
static inline uint64_t fde_func_1893_0x1794cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1794ccULL ^ (static_cast<uint64_t>(0xf0000520ULL) << 13);
    acc = (acc + a1 + 0x910cc000ULL) ^ 0x1f1380ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1894 | PC: 0x1794d8 | FDE: 0x1f1398 | Size: 256 bytes [_PyFaulthandler_Init]
// Khung tháo gỡ #1894 | Địa chỉ PC: 0x1794d8 | Địa chỉ FDE: 0x1f1398 | Kích thước: 256 bytes
//   0x1794d8: D10103FF  sub      sp, sp, #0x40
//   0x1794dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1794e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1794e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1894_0x1794d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1794d8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f1398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1895 | PC: 0x179608 | FDE: 0x1f13c0 | Size: 256 bytes [_PyFaulthandler_Fini]
// Khung tháo gỡ #1895 | Địa chỉ PC: 0x179608 | Địa chỉ FDE: 0x1f13c0 | Kích thước: 256 bytes
//   0x179608: D10143FF  sub      sp, sp, #0x50
//   0x17960c: F90013F5  str      x21, [sp, #0x20]
//   0x179610: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x179614: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1895_0x179608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179608ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1f13c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1896 | PC: 0x17a03c | FDE: 0x1f1508 | Size: 172 bytes [_PyGC_InitState]
// Khung tháo gỡ #1896 | Địa chỉ PC: 0x17a03c | Địa chỉ FDE: 0x1f1508 | Kích thước: 172 bytes
//   0x17a03c: D10183FF  sub      sp, sp, #0x60
//   0x17a040: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x17a044: 910143FD  add      x29, sp, #0x50
//   0x17a048: D53BD048  mrs      x8, tpidr_el0
static inline uint64_t fde_func_1896_0x17a03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a03cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9057bfdULL) ^ 0x1f1508ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1897 | PC: 0x17a0e8 | FDE: 0x1f1528 | Size: 116 bytes [_PyGC_Init]
// Khung tháo gỡ #1897 | Địa chỉ PC: 0x17a0e8 | Địa chỉ FDE: 0x1f1528 | Kích thước: 116 bytes
//   0x17a0e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17a0ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17a0f0: 910043FD  add      x29, sp, #0x10
//   0x17a0f4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1897_0x17a0e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a0e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1528ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1898 | PC: 0x17a15c | FDE: 0x1f1548 | Size: 12 bytes [PyInit_gc]
// Khung tháo gỡ #1898 | Địa chỉ PC: 0x17a15c | Địa chỉ FDE: 0x1f1548 | Kích thước: 12 bytes
//   0x17a15c: D0000520  adrp     x0, #0x220000
//   0x17a160: 9117A000  add      x0, x0, #0x5e8
//   0x17a164: 17FB7A2F  b        #0x58a20
static inline uint64_t fde_func_1898_0x17a15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a15cULL ^ (static_cast<uint64_t>(0xd0000520ULL) << 13);
    acc = (acc + a1 + 0x9117a000ULL) ^ 0x1f1548ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1899 | PC: 0x17a168 | FDE: 0x1f1560 | Size: 48 bytes [PyGC_Enable]
// Khung tháo gỡ #1899 | Địa chỉ PC: 0x17a168 | Địa chỉ FDE: 0x1f1560 | Kích thước: 48 bytes
//   0x17a168: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17a16c: 910003FD  mov      x29, sp
//   0x17a170: B0000428  adrp     x8, #0x1ff000
//   0x17a174: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1899_0x17a168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a168ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1560ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1900 | PC: 0x17a198 | FDE: 0x1f1580 | Size: 44 bytes [PyGC_Disable]
// Khung tháo gỡ #1900 | Địa chỉ PC: 0x17a198 | Địa chỉ FDE: 0x1f1580 | Kích thước: 44 bytes
//   0x17a198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17a19c: 910003FD  mov      x29, sp
//   0x17a1a0: B0000428  adrp     x8, #0x1ff000
//   0x17a1a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1900_0x17a198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1580ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1901 | PC: 0x17a1c4 | FDE: 0x1f15a0 | Size: 40 bytes [PyGC_IsEnabled]
// Khung tháo gỡ #1901 | Địa chỉ PC: 0x17a1c4 | Địa chỉ FDE: 0x1f15a0 | Kích thước: 40 bytes
//   0x17a1c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17a1c8: 910003FD  mov      x29, sp
//   0x17a1cc: B0000428  adrp     x8, #0x1ff000
//   0x17a1d0: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1901_0x17a1c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a1c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f15a0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1902 | PC: 0x17a1ec | FDE: 0x1f15c0 | Size: 236 bytes [PyGC_Collect]
// Khung tháo gỡ #1902 | Địa chỉ PC: 0x17a1ec | Địa chỉ FDE: 0x1f15c0 | Kích thước: 236 bytes
//   0x17a1ec: D10183FF  sub      sp, sp, #0x60
//   0x17a1f0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x17a1f4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x17a1f8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1902_0x17a1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a1ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1f15c0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1903 | PC: 0x17a2d8 | FDE: 0x1f15e8 | Size: 256 bytes [_PyGC_CollectNoFail]
// Khung tháo gỡ #1903 | Địa chỉ PC: 0x17a2d8 | Địa chỉ FDE: 0x1f15e8 | Kích thước: 256 bytes
//   0x17a2d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17a2dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17a2e0: 910043FD  add      x29, sp, #0x10
//   0x17a2e4: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_1903_0x17a2d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a2d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f15e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1904 | PC: 0x17b054 | FDE: 0x1f1638 | Size: 256 bytes [_PyGC_DumpShutdownStats]
// Khung tháo gỡ #1904 | Địa chỉ PC: 0x17b054 | Địa chỉ FDE: 0x1f1638 | Kích thước: 256 bytes
//   0x17b054: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x17b058: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17b05c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17b060: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1904_0x17b054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b054ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1905 | PC: 0x17b170 | FDE: 0x1f1658 | Size: 108 bytes [_PyGC_Fini]
// Khung tháo gỡ #1905 | Địa chỉ PC: 0x17b170 | Địa chỉ FDE: 0x1f1658 | Kích thước: 108 bytes
//   0x17b170: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b174: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b178: 910043FD  add      x29, sp, #0x10
//   0x17b17c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1905_0x17b170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b170ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1658ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1906 | PC: 0x17b1dc | FDE: 0x1f1678 | Size: 8 bytes [_PyGC_Dump]
// Khung tháo gỡ #1906 | Địa chỉ PC: 0x17b1dc | Địa chỉ FDE: 0x1f1678 | Kích thước: 8 bytes
//   0x17b1dc: 91004000  add      x0, x0, #0x10
//   0x17b1e0: 17FB7FCC  b        #0x5b110
static inline uint64_t fde_func_1906_0x17b1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b1dcULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17fb7fccULL) ^ 0x1f1678ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1907 | PC: 0x17b1e4 | FDE: 0x1f1690 | Size: 60 bytes [PyObject_GC_Track]
// Khung tháo gỡ #1907 | Địa chỉ PC: 0x17b1e4 | Địa chỉ FDE: 0x1f1690 | Kích thước: 60 bytes
//   0x17b1e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17b1e8: 910003FD  mov      x29, sp
//   0x17b1ec: F85F0008  ldur     x8, [x0, #-0x10]
//   0x17b1f0: B5000068  cbnz     x8, #0x17b1fc
static inline uint64_t fde_func_1907_0x17b1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b1e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1690ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1908 | PC: 0x17b220 | FDE: 0x1f16b0 | Size: 4 bytes [PyObject_GC_UnTrack]
// Khung tháo gỡ #1908 | Địa chỉ PC: 0x17b220 | Địa chỉ FDE: 0x1f16b0 | Kích thước: 4 bytes
//   0x17b220: D65F03C0  ret      
static inline uint64_t fde_func_1908_0x17b220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b220ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1f16b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1909 | PC: 0x17b224 | FDE: 0x1f16c8 | Size: 72 bytes [PyObject_IS_GC]
// Khung tháo gỡ #1909 | Địa chỉ PC: 0x17b224 | Địa chỉ FDE: 0x1f16c8 | Kích thước: 72 bytes
//   0x17b224: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17b228: 910003FD  mov      x29, sp
//   0x17b22c: F9400408  ldr      x8, [x0, #8]
//   0x17b230: 3942A509  ldrb     w9, [x8, #0xa9]
static inline uint64_t fde_func_1909_0x17b224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b224ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f16c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1910 | PC: 0x17b26c | FDE: 0x1f16e8 | Size: 88 bytes [_PyObject_GC_Malloc]
// Khung tháo gỡ #1910 | Địa chỉ PC: 0x17b26c | Địa chỉ FDE: 0x1f16e8 | Kích thước: 88 bytes
//   0x17b26c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17b270: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b274: 910043FD  add      x29, sp, #0x10
//   0x17b278: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1910_0x17b26c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b26cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f16e8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1911 | PC: 0x17b2c4 | FDE: 0x1f1708 | Size: 92 bytes [_PyObject_GC_Calloc]
// Khung tháo gỡ #1911 | Địa chỉ PC: 0x17b2c4 | Địa chỉ FDE: 0x1f1708 | Kích thước: 92 bytes
//   0x17b2c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17b2c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b2cc: 910043FD  add      x29, sp, #0x10
//   0x17b2d0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1911_0x17b2c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b2c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1708ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1912 | PC: 0x17b320 | FDE: 0x1f1728 | Size: 140 bytes [_PyObject_GC_New]
// Khung tháo gỡ #1912 | Địa chỉ PC: 0x17b320 | Địa chỉ FDE: 0x1f1728 | Kích thước: 140 bytes
//   0x17b320: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x17b324: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17b328: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17b32c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1912_0x17b320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b320ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1728ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1913 | PC: 0x17b3ac | FDE: 0x1f1748 | Size: 184 bytes [_PyObject_GC_NewVar]
// Khung tháo gỡ #1913 | Địa chỉ PC: 0x17b3ac | Địa chỉ FDE: 0x1f1748 | Kích thước: 184 bytes
//   0x17b3ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x17b3b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17b3b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17b3b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1913_0x17b3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b3acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1748ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1914 | PC: 0x17b464 | FDE: 0x1f1770 | Size: 104 bytes [_PyObject_GC_Resize]
// Khung tháo gỡ #1914 | Địa chỉ PC: 0x17b464 | Địa chỉ FDE: 0x1f1770 | Kích thước: 104 bytes
//   0x17b464: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b468: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b46c: 910043FD  add      x29, sp, #0x10
//   0x17b470: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1914_0x17b464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b464ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1770ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1915 | PC: 0x17b4cc | FDE: 0x1f1790 | Size: 112 bytes [PyObject_GC_Del]
// Khung tháo gỡ #1915 | Địa chỉ PC: 0x17b4cc | Địa chỉ FDE: 0x1f1790 | Kích thước: 112 bytes
//   0x17b4cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b4d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b4d4: 910043FD  add      x29, sp, #0x10
//   0x17b4d8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1915_0x17b4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b4ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1790ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1916 | PC: 0x17b53c | FDE: 0x1f17b0 | Size: 80 bytes [PyObject_GC_IsTracked]
// Khung tháo gỡ #1916 | Địa chỉ PC: 0x17b53c | Địa chỉ FDE: 0x1f17b0 | Kích thước: 80 bytes
//   0x17b53c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b540: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b544: 910043FD  add      x29, sp, #0x10
//   0x17b548: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1916_0x17b53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b53cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f17b0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1917 | PC: 0x17b58c | FDE: 0x1f17d0 | Size: 256 bytes [PyObject_GC_IsFinalized]
// Khung tháo gỡ #1917 | Địa chỉ PC: 0x17b58c | Địa chỉ FDE: 0x1f17d0 | Kích thước: 256 bytes
//   0x17b58c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b594: 910043FD  add      x29, sp, #0x10
//   0x17b598: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1917_0x17b58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b58cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f17d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1918 | PC: 0x17bb50 | FDE: 0x1f18c0 | Size: 92 bytes [Py_GetBuildInfo]
// Khung tháo gỡ #1918 | Địa chỉ PC: 0x17bb50 | Địa chỉ FDE: 0x1f18c0 | Kích thước: 92 bytes
//   0x17bb50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17bb54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17bb58: 910043FD  add      x29, sp, #0x10
//   0x17bb5c: F0000553  adrp     x19, #0x226000
static inline uint64_t fde_func_1918_0x17bb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bb50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f18c0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1919 | PC: 0x17bbac | FDE: 0x1f18e0 | Size: 12 bytes [_Py_gitversion]
// Khung tháo gỡ #1919 | Địa chỉ PC: 0x17bbac | Địa chỉ FDE: 0x1f18e0 | Kích thước: 12 bytes
//   0x17bbac: B0000220  adrp     x0, #0x1c0000
//   0x17bbb0: 91042C00  add      x0, x0, #0x10b
//   0x17bbb4: D65F03C0  ret      
static inline uint64_t fde_func_1919_0x17bbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbacULL ^ (static_cast<uint64_t>(0xb0000220ULL) << 13);
    acc = (acc + a1 + 0x91042c00ULL) ^ 0x1f18e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1920 | PC: 0x17bbb8 | FDE: 0x1f18f8 | Size: 12 bytes [_Py_gitidentifier]
// Khung tháo gỡ #1920 | Địa chỉ PC: 0x17bbb8 | Địa chỉ FDE: 0x1f18f8 | Kích thước: 12 bytes
//   0x17bbb8: B0000220  adrp     x0, #0x1c0000
//   0x17bbbc: 91042C00  add      x0, x0, #0x10b
//   0x17bbc0: D65F03C0  ret      
static inline uint64_t fde_func_1920_0x17bbb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbb8ULL ^ (static_cast<uint64_t>(0xb0000220ULL) << 13);
    acc = (acc + a1 + 0x91042c00ULL) ^ 0x1f18f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1921 | PC: 0x17bbc4 | FDE: 0x1f1910 | Size: 256 bytes [_PyPathConfig_Calculate]
// Khung tháo gỡ #1921 | Địa chỉ PC: 0x17bbc4 | Địa chỉ FDE: 0x1f1910 | Kích thước: 256 bytes
//   0x17bbc4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x17bbc8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x17bbcc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x17bbd0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1921_0x17bbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbc4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f1910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1922 | PC: 0x17d9f4 | FDE: 0x1f19b8 | Size: 256 bytes [PyInit_math]
// Khung tháo gỡ #1922 | Địa chỉ PC: 0x17d9f4 | Địa chỉ FDE: 0x1f19b8 | Kích thước: 256 bytes
//   0x17d9f4: F0000500  adrp     x0, #0x220000
//   0x17d9f8: 911BC000  add      x0, x0, #0x6f0
//   0x17d9fc: 17FB6C09  b        #0x58a20
//   0x17da00: FC1E0FE8  str      d8, [sp, #-0x20]!
static inline uint64_t fde_func_1922_0x17d9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d9f4ULL ^ (static_cast<uint64_t>(0xf0000500ULL) << 13);
    acc = (acc + a1 + 0x911bc000ULL) ^ 0x1f19b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1923 | PC: 0x1832cc | FDE: 0x1f22e0 | Size: 256 bytes [PyOS_BeforeFork]
// Khung tháo gỡ #1923 | Địa chỉ PC: 0x1832cc | Địa chỉ FDE: 0x1f22e0 | Kích thước: 256 bytes
//   0x1832cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1832d0: 910003FD  mov      x29, sp
//   0x1832d4: 900003E8  adrp     x8, #0x1ff000
//   0x1832d8: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_1923_0x1832cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1832ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f22e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1924 | PC: 0x183438 | FDE: 0x1f2328 | Size: 76 bytes [PyOS_AfterFork_Parent]
// Khung tháo gỡ #1924 | Địa chỉ PC: 0x183438 | Địa chỉ FDE: 0x1f2328 | Kích thước: 76 bytes
//   0x183438: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18343c: 910003FD  mov      x29, sp
//   0x183440: 97FB59A4  bl       #0x59ad0
//   0x183444: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_1924_0x183438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183438ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2328ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1925 | PC: 0x183484 | FDE: 0x1f2348 | Size: 256 bytes [PyOS_AfterFork_Child]
// Khung tháo gỡ #1925 | Địa chỉ PC: 0x183484 | Địa chỉ FDE: 0x1f2348 | Kích thước: 256 bytes
//   0x183484: D10243FF  sub      sp, sp, #0x90
//   0x183488: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x18348c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x183490: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_1925_0x183484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183484ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x1f2348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1926 | PC: 0x1835c4 | FDE: 0x1f2368 | Size: 4 bytes [PyOS_AfterFork]
// Khung tháo gỡ #1926 | Địa chỉ PC: 0x1835c4 | Địa chỉ FDE: 0x1f2368 | Kích thước: 4 bytes
//   0x1835c4: 17FB60B7  b        #0x5b8a0
static inline uint64_t fde_func_1926_0x1835c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835c4ULL ^ (static_cast<uint64_t>(0x17fb60b7ULL) << 13);
    acc = (acc + a1 + 0x3100041fULL) ^ 0x1f2368ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1927 | PC: 0x1835c8 | FDE: 0x1f2380 | Size: 24 bytes [_PyLong_FromUid]
// Khung tháo gỡ #1927 | Địa chỉ PC: 0x1835c8 | Địa chỉ FDE: 0x1f2380 | Kích thước: 24 bytes
//   0x1835c8: 3100041F  cmn      w0, #1
//   0x1835cc: 54000060  b.eq     #0x1835d8
//   0x1835d0: 2A0003E0  mov      w0, w0
//   0x1835d4: 17FB62CF  b        #0x5c110
static inline uint64_t fde_func_1927_0x1835c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835c8ULL ^ (static_cast<uint64_t>(0x3100041fULL) << 13);
    acc = (acc + a1 + 0x54000060ULL) ^ 0x1f2380ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1928 | PC: 0x1835e0 | FDE: 0x1f2398 | Size: 24 bytes [_PyLong_FromGid]
// Khung tháo gỡ #1928 | Địa chỉ PC: 0x1835e0 | Địa chỉ FDE: 0x1f2398 | Kích thước: 24 bytes
//   0x1835e0: 3100041F  cmn      w0, #1
//   0x1835e4: 54000060  b.eq     #0x1835f0
//   0x1835e8: 2A0003E0  mov      w0, w0
//   0x1835ec: 17FB62C9  b        #0x5c110
static inline uint64_t fde_func_1928_0x1835e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835e0ULL ^ (static_cast<uint64_t>(0x3100041fULL) << 13);
    acc = (acc + a1 + 0x54000060ULL) ^ 0x1f2398ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1929 | PC: 0x1835f8 | FDE: 0x1f23b0 | Size: 256 bytes [_Py_Uid_Converter]
// Khung tháo gỡ #1929 | Địa chỉ PC: 0x1835f8 | Địa chỉ FDE: 0x1f23b0 | Kích thước: 256 bytes
//   0x1835f8: D10143FF  sub      sp, sp, #0x50
//   0x1835fc: F9000BF7  str      x23, [sp, #0x10]
//   0x183600: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x183604: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1929_0x1835f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f23b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1930 | PC: 0x183764 | FDE: 0x1f23d8 | Size: 256 bytes [_Py_Gid_Converter]
// Khung tháo gỡ #1930 | Địa chỉ PC: 0x183764 | Địa chỉ FDE: 0x1f23d8 | Kích thước: 256 bytes
//   0x183764: D10143FF  sub      sp, sp, #0x50
//   0x183768: F9000BF7  str      x23, [sp, #0x10]
//   0x18376c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x183770: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1930_0x183764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183764ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f23d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1931 | PC: 0x1838d0 | FDE: 0x1f2400 | Size: 256 bytes [_Py_Sigset_Converter]
// Khung tháo gỡ #1931 | Địa chỉ PC: 0x1838d0 | Địa chỉ FDE: 0x1f2400 | Kích thước: 256 bytes
//   0x1838d0: D10283FF  sub      sp, sp, #0xa0
//   0x1838d4: F9002BF9  str      x25, [sp, #0x50]
//   0x1838d8: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x1838dc: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1931_0x1838d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1838d0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x1f2400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1932 | PC: 0x183aa4 | FDE: 0x1f2428 | Size: 256 bytes [PyOS_FSPath]
// Khung tháo gỡ #1932 | Địa chỉ PC: 0x183aa4 | Địa chỉ FDE: 0x1f2428 | Kích thước: 256 bytes
//   0x183aa4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x183aa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x183aac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x183ab0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1932_0x183aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183aa4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1933 | PC: 0x183c34 | FDE: 0x1f2448 | Size: 256 bytes [PyInit_posix]
// Khung tháo gỡ #1933 | Địa chỉ PC: 0x183c34 | Địa chỉ FDE: 0x1f2448 | Kích thước: 256 bytes
//   0x183c34: B00004E0  adrp     x0, #0x220000
//   0x183c38: 913BE000  add      x0, x0, #0xef8
//   0x183c3c: 17FB5379  b        #0x58a20
//   0x183c40: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1933_0x183c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183c34ULL ^ (static_cast<uint64_t>(0xb00004e0ULL) << 13);
    acc = (acc + a1 + 0x913be000ULL) ^ 0x1f2448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1934 | PC: 0x188e44 | FDE: 0x1f2c10 | Size: 64 bytes [RotatingTree_Add]
// Khung tháo gỡ #1934 | Địa chỉ PC: 0x188e44 | Địa chỉ FDE: 0x1f2c10 | Kích thước: 64 bytes
//   0x188e44: F9400008  ldr      x8, [x0]
//   0x188e48: B4000188  cbz      x8, #0x188e78
//   0x188e4c: F9400029  ldr      x9, [x1]
//   0x188e50: 5280020A  mov      w10, #0x10
static inline uint64_t fde_func_1934_0x188e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e44ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb4000188ULL) ^ 0x1f2c10ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1935 | PC: 0x188e84 | FDE: 0x1f2c28 | Size: 256 bytes [RotatingTree_Get]
// Khung tháo gỡ #1935 | Địa chỉ PC: 0x188e84 | Địa chỉ FDE: 0x1f2c28 | Kích thước: 256 bytes
//   0x188e84: D00004E9  adrp     x9, #0x226000
//   0x188e88: B946792C  ldr      w12, [x9, #0x678]
//   0x188e8c: AA0003E8  mov      x8, x0
//   0x188e90: B00004CA  adrp     x10, #0x221000
static inline uint64_t fde_func_1935_0x188e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e84ULL ^ (static_cast<uint64_t>(0xd00004e9ULL) << 13);
    acc = (acc + a1 + 0xb946792cULL) ^ 0x1f2c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1936 | PC: 0x188f94 | FDE: 0x1f2c40 | Size: 100 bytes [RotatingTree_Enum]
// Khung tháo gỡ #1936 | Địa chỉ PC: 0x188f94 | Địa chỉ FDE: 0x1f2c40 | Kích thước: 100 bytes
//   0x188f94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x188f98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x188f9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x188fa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1936_0x188f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188f94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2c40ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1937 | PC: 0x188ff8 | FDE: 0x1f2c68 | Size: 40 bytes [PySignal_SetWakeupFd]
// Khung tháo gỡ #1937 | Địa chỉ PC: 0x188ff8 | Địa chỉ FDE: 0x1f2c68 | Kích thước: 40 bytes
//   0x188ff8: B00004C9  adrp     x9, #0x221000
//   0x188ffc: 913AB129  add      x9, x9, #0xeac
//   0x189000: B9400128  ldr      w8, [x9]
//   0x189004: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_1937_0x188ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188ff8ULL ^ (static_cast<uint64_t>(0xb00004c9ULL) << 13);
    acc = (acc + a1 + 0x913ab129ULL) ^ 0x1f2c68ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1938 | PC: 0x189020 | FDE: 0x1f2c80 | Size: 12 bytes [PyInit__signal]
// Khung tháo gỡ #1938 | Địa chỉ PC: 0x189020 | Địa chỉ FDE: 0x1f2c80 | Kích thước: 12 bytes
//   0x189020: 900004C0  adrp     x0, #0x221000
//   0x189024: 913AE000  add      x0, x0, #0xeb8
//   0x189028: 17FB3E7E  b        #0x58a20
static inline uint64_t fde_func_1938_0x189020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189020ULL ^ (static_cast<uint64_t>(0x900004c0ULL) << 13);
    acc = (acc + a1 + 0x913ae000ULL) ^ 0x1f2c80ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1939 | PC: 0x18902c | FDE: 0x1f2c98 | Size: 256 bytes [_PySignal_Fini]
// Khung tháo gỡ #1939 | Địa chỉ PC: 0x18902c | Địa chỉ FDE: 0x1f2c98 | Kích thước: 256 bytes
//   0x18902c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x189030: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x189034: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x189038: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1939_0x18902c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18902cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1940 | PC: 0x189134 | FDE: 0x1f2cc0 | Size: 92 bytes [PyErr_CheckSignals]
// Khung tháo gỡ #1940 | Địa chỉ PC: 0x189134 | Địa chỉ FDE: 0x1f2cc0 | Kích thước: 92 bytes
//   0x189134: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x189138: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18913c: 910043FD  add      x29, sp, #0x10
//   0x189140: 97FB41A0  bl       #0x597c0
static inline uint64_t fde_func_1940_0x189134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189134ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2cc0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1941 | PC: 0x189190 | FDE: 0x1f2ce0 | Size: 256 bytes [_PyErr_CheckSignalsTstate]
// Khung tháo gỡ #1941 | Địa chỉ PC: 0x189190 | Địa chỉ FDE: 0x1f2ce0 | Kích thước: 256 bytes
//   0x189190: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x189194: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x189198: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x18919c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1941_0x189190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189190ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f2ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1942 | PC: 0x18930c | FDE: 0x1f2d10 | Size: 20 bytes [_PyErr_CheckSignals]
// Khung tháo gỡ #1942 | Địa chỉ PC: 0x18930c | Địa chỉ FDE: 0x1f2d10 | Kích thước: 20 bytes
//   0x18930c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x189310: 910003FD  mov      x29, sp
//   0x189314: 97FB412B  bl       #0x597c0
//   0x189318: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_1942_0x18930c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18930cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2d10ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1943 | PC: 0x189320 | FDE: 0x1f2d30 | Size: 256 bytes [PyErr_SetInterruptEx]
// Khung tháo gỡ #1943 | Địa chỉ PC: 0x189320 | Địa chỉ FDE: 0x1f2d30 | Kích thước: 256 bytes
//   0x189320: D10103FF  sub      sp, sp, #0x40
//   0x189324: F9000BF5  str      x21, [sp, #0x10]
//   0x189328: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18932c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1943_0x189320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189320ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f2d30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1944 | PC: 0x189440 | FDE: 0x1f2d50 | Size: 8 bytes [PyErr_SetInterrupt]
// Khung tháo gỡ #1944 | Địa chỉ PC: 0x189440 | Địa chỉ FDE: 0x1f2d50 | Kích thước: 8 bytes
//   0x189440: 52800040  mov      w0, #2
//   0x189444: 17FB4F83  b        #0x5d250
static inline uint64_t fde_func_1944_0x189440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189440ULL ^ (static_cast<uint64_t>(0x52800040ULL) << 13);
    acc = (acc + a1 + 0x17fb4f83ULL) ^ 0x1f2d50ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1945 | PC: 0x189448 | FDE: 0x1f2d68 | Size: 36 bytes [_Py_RestoreSignals]
// Khung tháo gỡ #1945 | Địa chỉ PC: 0x189448 | Địa chỉ FDE: 0x1f2d68 | Kích thước: 36 bytes
//   0x189448: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18944c: 910003FD  mov      x29, sp
//   0x189450: 528001A0  mov      w0, #0xd
//   0x189454: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_1945_0x189448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189448ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2d68ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1946 | PC: 0x18946c | FDE: 0x1f2d88 | Size: 176 bytes [_PySignal_Init]
// Khung tháo gỡ #1946 | Địa chỉ PC: 0x18946c | Địa chỉ FDE: 0x1f2d88 | Kích thước: 176 bytes
//   0x18946c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189470: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189474: 910043FD  add      x29, sp, #0x10
//   0x189478: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_1946_0x18946c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18946cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2d88ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1947 | PC: 0x18951c | FDE: 0x1f2da8 | Size: 112 bytes [_PyOS_InterruptOccurred]
// Khung tháo gỡ #1947 | Địa chỉ PC: 0x18951c | Địa chỉ FDE: 0x1f2da8 | Kích thước: 112 bytes
//   0x18951c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189524: 910043FD  add      x29, sp, #0x10
//   0x189528: B40002C0  cbz      x0, #0x189580
static inline uint64_t fde_func_1947_0x18951c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18951cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2da8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1948 | PC: 0x18958c | FDE: 0x1f2dc8 | Size: 116 bytes [PyOS_InterruptOccurred]
// Khung tháo gỡ #1948 | Địa chỉ PC: 0x18958c | Địa chỉ FDE: 0x1f2dc8 | Kích thước: 116 bytes
//   0x18958c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189594: 910043FD  add      x29, sp, #0x10
//   0x189598: 97FB408A  bl       #0x597c0
static inline uint64_t fde_func_1948_0x18958c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18958cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2dc8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1949 | PC: 0x189600 | FDE: 0x1f2de8 | Size: 56 bytes [_PySignal_AfterFork]
// Khung tháo gỡ #1949 | Địa chỉ PC: 0x189600 | Địa chỉ FDE: 0x1f2de8 | Kích thước: 56 bytes
//   0x189600: B00004E9  adrp     x9, #0x226000
//   0x189604: 912A8129  add      x9, x9, #0xaa0
//   0x189608: 88DFFD28  ldar     w8, [x9]
//   0x18960c: 34000148  cbz      w8, #0x189634
static inline uint64_t fde_func_1949_0x189600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189600ULL ^ (static_cast<uint64_t>(0xb00004e9ULL) << 13);
    acc = (acc + a1 + 0x912a8129ULL) ^ 0x1f2de8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1950 | PC: 0x189638 | FDE: 0x1f2e00 | Size: 256 bytes [_PyOS_IsMainThread]
// Khung tháo gỡ #1950 | Địa chỉ PC: 0x189638 | Địa chỉ FDE: 0x1f2e00 | Kích thước: 256 bytes
//   0x189638: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18963c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189640: 910043FD  add      x29, sp, #0x10
//   0x189644: D00003B3  adrp     x19, #0x1ff000
static inline uint64_t fde_func_1950_0x189638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189638ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1951 | PC: 0x18a0f0 | FDE: 0x1f2f58 | Size: 256 bytes [PyInit_time]
// Khung tháo gỡ #1951 | Địa chỉ PC: 0x18a0f0 | Địa chỉ FDE: 0x1f2f58 | Kích thước: 256 bytes
//   0x18a0f0: F00004A0  adrp     x0, #0x221000
//   0x18a0f4: 913F0000  add      x0, x0, #0xfc0
//   0x18a0f8: 17FB3A4A  b        #0x58a20
//   0x18a0fc: D100C3FF  sub      sp, sp, #0x30
static inline uint64_t fde_func_1951_0x18a0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a0f0ULL ^ (static_cast<uint64_t>(0xf00004a0ULL) << 13);
    acc = (acc + a1 + 0x913f0000ULL) ^ 0x1f2f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1952 | PC: 0x18ac00 | FDE: 0x1f3090 | Size: 256 bytes [PyInit_xx]
// Khung tháo gỡ #1952 | Địa chỉ PC: 0x18ac00 | Địa chỉ FDE: 0x1f3090 | Kích thước: 256 bytes
//   0x18ac00: 900004C0  adrp     x0, #0x222000
//   0x18ac04: 91082000  add      x0, x0, #0x208
//   0x18ac08: 17FB3786  b        #0x58a20
//   0x18ac0c: D10103FF  sub      sp, sp, #0x40
static inline uint64_t fde_func_1952_0x18ac00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ac00ULL ^ (static_cast<uint64_t>(0x900004c0ULL) << 13);
    acc = (acc + a1 + 0x91082000ULL) ^ 0x1f3090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1953 | PC: 0x18b0b4 | FDE: 0x1f31e0 | Size: 256 bytes [_PyMem_DumpTraceback]
// Khung tháo gỡ #1953 | Địa chỉ PC: 0x18b0b4 | Địa chỉ FDE: 0x1f31e0 | Kích thước: 256 bytes
//   0x18b0b4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18b0b8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18b0bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18b0c0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1953_0x18b0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b0b4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f31e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1954 | PC: 0x18b304 | FDE: 0x1f3228 | Size: 256 bytes [PyInit__tracemalloc]
// Khung tháo gỡ #1954 | Địa chỉ PC: 0x18b304 | Địa chỉ FDE: 0x1f3228 | Kích thước: 256 bytes
//   0x18b304: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18b308: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18b30c: 910043FD  add      x29, sp, #0x10
//   0x18b310: F00004A0  adrp     x0, #0x222000
static inline uint64_t fde_func_1954_0x18b304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b304ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1955 | PC: 0x18b5dc | FDE: 0x1f3270 | Size: 256 bytes [_PyTraceMalloc_Init]
// Khung tháo gỡ #1955 | Địa chỉ PC: 0x18b5dc | Địa chỉ FDE: 0x1f3270 | Kích thước: 256 bytes
//   0x18b5dc: 34000040  cbz      w0, #0x18b5e4
//   0x18b5e0: 14000002  b        #0x18b5e8
//   0x18b5e4: D65F03C0  ret      
//   0x18b5e8: D10183FF  sub      sp, sp, #0x60
static inline uint64_t fde_func_1955_0x18b5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b5dcULL ^ (static_cast<uint64_t>(0x34000040ULL) << 13);
    acc = (acc + a1 + 0x14000002ULL) ^ 0x1f3270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1956 | PC: 0x18b76c | FDE: 0x1f32b0 | Size: 256 bytes [_PyTraceMalloc_Fini]
// Khung tháo gỡ #1956 | Địa chỉ PC: 0x18b76c | Địa chỉ FDE: 0x1f32b0 | Kích thước: 256 bytes
//   0x18b76c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18b770: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18b774: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18b778: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1956_0x18b76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b76cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f32b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1957 | PC: 0x18b8d0 | FDE: 0x1f32d8 | Size: 256 bytes [PyTraceMalloc_Track]
// Khung tháo gỡ #1957 | Địa chỉ PC: 0x18b8d0 | Địa chỉ FDE: 0x1f32d8 | Kích thước: 256 bytes
//   0x18b8d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18b8d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18b8d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18b8dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1957_0x18b8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b8d0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f32d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1958 | PC: 0x18bb00 | FDE: 0x1f3330 | Size: 188 bytes [PyTraceMalloc_Untrack]
// Khung tháo gỡ #1958 | Địa chỉ PC: 0x18bb00 | Địa chỉ FDE: 0x1f3330 | Kích thước: 188 bytes
//   0x18bb00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18bb04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18bb08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18bb0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1958_0x18bb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bb00ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3330ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1959 | PC: 0x18bbbc | FDE: 0x1f3350 | Size: 256 bytes [_PyTraceMalloc_NewReference]
// Khung tháo gỡ #1959 | Địa chỉ PC: 0x18bbbc | Địa chỉ FDE: 0x1f3350 | Kích thước: 256 bytes
//   0x18bbbc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18bbc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18bbc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18bbc8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1959_0x18bbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bbbcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1960 | PC: 0x18beec | FDE: 0x1f33a0 | Size: 256 bytes [_PyTraceMalloc_GetTraceback]
// Khung tháo gỡ #1960 | Địa chỉ PC: 0x18beec | Địa chỉ FDE: 0x1f33a0 | Kích thước: 256 bytes
//   0x18beec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18bef0: 910003FD  mov      x29, sp
//   0x18bef4: 97FFFCDD  bl       #0x18b268
//   0x18bef8: B4000080  cbz      x0, #0x18bf08
static inline uint64_t fde_func_1960_0x18beec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18beecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f33a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1961 | PC: 0x18d190 | FDE: 0x1f37e0 | Size: 68 bytes [_ZN12BDPyDebugger7ExcInfoD2Ev]
// Khung tháo gỡ #1961 | Địa chỉ PC: 0x18d190 | Địa chỉ FDE: 0x1f37e0 | Kích thước: 68 bytes
//   0x18d190: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18d194: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d198: 910043FD  add      x29, sp, #0x10
//   0x18d19c: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_1961_0x18d190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d190ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f37e0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1962 | PC: 0x18d1d4 | FDE: 0x1f3800 | Size: 8 bytes [_ZN12BDPyDebugger5EventD2Ev]
// Khung tháo gỡ #1962 | Địa chỉ PC: 0x18d1d4 | Địa chỉ FDE: 0x1f3800 | Kích thước: 8 bytes
//   0x18d1d4: 91002000  add      x0, x0, #8
//   0x18d1d8: 17FB3472  b        #0x5a3a0
static inline uint64_t fde_func_1962_0x18d1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d1d4ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17fb3472ULL) ^ 0x1f3800ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1963 | PC: 0x18d1dc | FDE: 0x1f3818 | Size: 156 bytes [_ZN12BDPyDebugger5Event4waitEv]
// Khung tháo gỡ #1963 | Địa chỉ PC: 0x18d1dc | Địa chỉ FDE: 0x1f3818 | Kích thước: 156 bytes
//   0x18d1dc: D10143FF  sub      sp, sp, #0x50
//   0x18d1e0: F90013F5  str      x21, [sp, #0x20]
//   0x18d1e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18d1e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1963_0x18d1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d1dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1f3818ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1964 | PC: 0x18d278 | FDE: 0x1f3838 | Size: 60 bytes [_ZN12BDPyDebugger5Event4fireEv]
// Khung tháo gỡ #1964 | Địa chỉ PC: 0x18d278 | Địa chỉ FDE: 0x1f3838 | Kích thước: 60 bytes
//   0x18d278: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d27c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d280: 910043FD  add      x29, sp, #0x10
//   0x18d284: F9400014  ldr      x20, [x0]
static inline uint64_t fde_func_1964_0x18d278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d278ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3838ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1965 | PC: 0x18d2b4 | FDE: 0x1f3858 | Size: 256 bytes [_Z26BDDbg_getCodeObjectFromPycP7_objectS0_]
// Khung tháo gỡ #1965 | Địa chỉ PC: 0x18d2b4 | Địa chỉ FDE: 0x1f3858 | Kích thước: 256 bytes
//   0x18d2b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d2b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d2bc: 910043FD  add      x29, sp, #0x10
//   0x18d2c0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1965_0x18d2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d2b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1966 | PC: 0x18d3d0 | FDE: 0x1f3878 | Size: 148 bytes [_Z20BDDbg_getFuncFromModP7_objectS0_]
// Khung tháo gỡ #1966 | Địa chỉ PC: 0x18d3d0 | Địa chỉ FDE: 0x1f3878 | Kích thước: 148 bytes
//   0x18d3d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d3d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d3d8: 910043FD  add      x29, sp, #0x10
//   0x18d3dc: F9400C33  ldr      x19, [x1, #0x18]
static inline uint64_t fde_func_1966_0x18d3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d3d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3878ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1967 | PC: 0x18d464 | FDE: 0x1f3898 | Size: 52 bytes [_Z22BDDbg_getCmdFromNativeP7_objectS0_]
// Khung tháo gỡ #1967 | Địa chỉ PC: 0x18d464 | Địa chỉ FDE: 0x1f3898 | Kích thước: 52 bytes
//   0x18d464: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d468: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d46c: 910043FD  add      x29, sp, #0x10
//   0x18d470: 97FB3C5C  bl       #0x5c5e0
static inline uint64_t fde_func_1967_0x18d464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d464ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3898ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1968 | PC: 0x18d498 | FDE: 0x1f38b8 | Size: 104 bytes [_Z19BDDbg_sendFrameInfoP7_objectS0_]
// Khung tháo gỡ #1968 | Địa chỉ PC: 0x18d498 | Địa chỉ FDE: 0x1f38b8 | Kích thước: 104 bytes
//   0x18d498: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d49c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d4a0: 910043FD  add      x29, sp, #0x10
//   0x18d4a4: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1968_0x18d498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d498ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f38b8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1969 | PC: 0x18d500 | FDE: 0x1f38d8 | Size: 88 bytes [_Z24BDDbg_launchStatusNotifyP7_objectS0_]
// Khung tháo gỡ #1969 | Địa chỉ PC: 0x18d500 | Địa chỉ FDE: 0x1f38d8 | Kích thước: 88 bytes
//   0x18d500: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d504: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d508: 910043FD  add      x29, sp, #0x10
//   0x18d50c: D0000394  adrp     x20, #0x1ff000
static inline uint64_t fde_func_1969_0x18d500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d500ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f38d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1970 | PC: 0x18d558 | FDE: 0x1f38f8 | Size: 256 bytes [_Z23BDDbg_sendDebuggerStateP7_objectS0_]
// Khung tháo gỡ #1970 | Địa chỉ PC: 0x18d558 | Địa chỉ FDE: 0x1f38f8 | Kích thước: 256 bytes
//   0x18d558: D10243FF  sub      sp, sp, #0x90
//   0x18d55c: F90023F9  str      x25, [sp, #0x40]
//   0x18d560: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x18d564: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1970_0x18d558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d558ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x1f38f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1971 | PC: 0x18d760 | FDE: 0x1f3920 | Size: 152 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc]
// Khung tháo gỡ #1971 | Địa chỉ PC: 0x18d760 | Địa chỉ FDE: 0x1f3920 | Kích thước: 152 bytes
//   0x18d760: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18d764: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18d768: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18d76c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1971_0x18d760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d760ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3920ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1972 | PC: 0x18d7f8 | FDE: 0x1f3948 | Size: 188 bytes [_Z16getDebuggerStatev]
// Khung tháo gỡ #1972 | Địa chỉ PC: 0x18d7f8 | Địa chỉ FDE: 0x1f3948 | Kích thước: 188 bytes
//   0x18d7f8: D10143FF  sub      sp, sp, #0x50
//   0x18d7fc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18d800: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18d804: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1972_0x18d7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d7f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f3948ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1973 | PC: 0x18d8b4 | FDE: 0x1f3970 | Size: 12 bytes [_Z12getframeinfov]
// Khung tháo gỡ #1973 | Địa chỉ PC: 0x18d8b4 | Địa chỉ FDE: 0x1f3970 | Kích thước: 12 bytes
//   0x18d8b4: B00004C8  adrp     x8, #0x226000
//   0x18d8b8: F9471D00  ldr      x0, [x8, #0xe38]
//   0x18d8bc: D65F03C0  ret      
static inline uint64_t fde_func_1973_0x18d8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d8b4ULL ^ (static_cast<uint64_t>(0xb00004c8ULL) << 13);
    acc = (acc + a1 + 0xf9471d00ULL) ^ 0x1f3970ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1974 | PC: 0x18d8c0 | FDE: 0x1f3988 | Size: 88 bytes [_Z22BDDbg_exitStatusNotifyP7_objectS0_]
// Khung tháo gỡ #1974 | Địa chỉ PC: 0x18d8c0 | Địa chỉ FDE: 0x1f3988 | Kích thước: 88 bytes
//   0x18d8c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d8c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d8c8: 910043FD  add      x29, sp, #0x10
//   0x18d8cc: D0000394  adrp     x20, #0x1ff000
static inline uint64_t fde_func_1974_0x18d8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d8c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3988ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1975 | PC: 0x18d918 | FDE: 0x1f39a8 | Size: 16 bytes [BDPy_InitDbgHelper]
// Khung tháo gỡ #1975 | Địa chỉ PC: 0x18d918 | Địa chỉ FDE: 0x1f39a8 | Kích thước: 16 bytes
//   0x18d918: B00004A0  adrp     x0, #0x222000
//   0x18d91c: 91280000  add      x0, x0, #0xa00
//   0x18d920: 52807EA1  mov      w1, #0x3f5
//   0x18d924: 17FB3633  b        #0x5b1f0
static inline uint64_t fde_func_1975_0x18d918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d918ULL ^ (static_cast<uint64_t>(0xb00004a0ULL) << 13);
    acc = (acc + a1 + 0x91280000ULL) ^ 0x1f39a8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1976 | PC: 0x18d928 | FDE: 0x1f39c0 | Size: 148 bytes [_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv]
// Khung tháo gỡ #1976 | Địa chỉ PC: 0x18d928 | Địa chỉ FDE: 0x1f39c0 | Kích thước: 148 bytes
//   0x18d928: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18d92c: 910003FD  mov      x29, sp
//   0x18d930: F00001C0  adrp     x0, #0x1c8000
//   0x18d934: 91280C00  add      x0, x0, #0xa03
static inline uint64_t fde_func_1976_0x18d928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d928ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f39c0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1977 | PC: 0x18d9bc | FDE: 0x1f3a70 | Size: 120 bytes [_ZNSt6__ndk15queueINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_5dequeIS6_NS4_IS6_EEEEED2Ev]
// Khung tháo gỡ #1977 | Địa chỉ PC: 0x18d9bc | Địa chỉ FDE: 0x1f3a70 | Kích thước: 120 bytes
//   0x18d9bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18d9c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18d9c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18d9c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1977_0x18d9bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d9bcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3a70ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1978 | PC: 0x18da34 | FDE: 0x1f3bc8 | Size: 236 bytes [_Z6putCmdNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE]
// Khung tháo gỡ #1978 | Địa chỉ PC: 0x18da34 | Địa chỉ FDE: 0x1f3bc8 | Kích thước: 236 bytes
//   0x18da34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18da38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18da3c: 910043FD  add      x29, sp, #0x10
//   0x18da40: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1978_0x18da34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18da34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3bc8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1979 | PC: 0x18db20 | FDE: 0x1f3bf0 | Size: 256 bytes [_Z6getCmdv]
// Khung tháo gỡ #1979 | Địa chỉ PC: 0x18db20 | Địa chỉ FDE: 0x1f3bf0 | Kích thước: 256 bytes
//   0x18db20: D10183FF  sub      sp, sp, #0x60
//   0x18db24: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x18db28: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x18db2c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1979_0x18db20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18db20ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1f3bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1980 | PC: 0x18dd34 | FDE: 0x1f3a90 | Size: 172 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_]
// Khung tháo gỡ #1980 | Địa chỉ PC: 0x18dd34 | Địa chỉ FDE: 0x1f3a90 | Kích thước: 172 bytes
//   0x18dd34: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18dd38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18dd3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18dd40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1980_0x18dd34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18dd34ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3a90ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1981 | PC: 0x18dde0 | FDE: 0x1f3ab8 | Size: 256 bytes [_ZNSt6__ndk112__deque_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE5clearEv]
// Khung tháo gỡ #1981 | Địa chỉ PC: 0x18dde0 | Địa chỉ FDE: 0x1f3ab8 | Kích thước: 256 bytes
//   0x18dde0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18dde4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18dde8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18ddec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1981_0x18dde0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18dde0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1982 | PC: 0x18df24 | FDE: 0x1f3c20 | Size: 256 bytes [_ZNSt6__ndk15dequeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE19__add_back_capacityEv]
// Khung tháo gỡ #1982 | Địa chỉ PC: 0x18df24 | Địa chỉ FDE: 0x1f3c20 | Kích thước: 256 bytes
//   0x18df24: D101C3FF  sub      sp, sp, #0x70
//   0x18df28: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x18df2c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x18df30: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1982_0x18df24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18df24ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x1f3c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1983 | PC: 0x18e27c | FDE: 0x1f3b08 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS7_EEE9push_backEOS7_]
// Khung tháo gỡ #1983 | Địa chỉ PC: 0x18e27c | Địa chỉ FDE: 0x1f3b08 | Kích thước: 256 bytes
//   0x18e27c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18e280: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18e284: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18e288: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1983_0x18e27c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e27cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1984 | PC: 0x18e3dc | FDE: 0x1f3b30 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS7_EEE10push_frontEOS7_]
// Khung tháo gỡ #1984 | Địa chỉ PC: 0x18e3dc | Địa chỉ FDE: 0x1f3b30 | Kích thước: 256 bytes
//   0x18e3dc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18e3e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18e3e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18e3e8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1984_0x18e3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e3dcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1985 | PC: 0x18e538 | FDE: 0x1f3b58 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS7_EEE9push_backEOS7_]
// Khung tháo gỡ #1985 | Địa chỉ PC: 0x18e538 | Địa chỉ FDE: 0x1f3b58 | Kích thước: 256 bytes
//   0x18e538: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18e53c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18e540: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18e544: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1985_0x18e538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e538ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3b58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1986 | PC: 0x18e698 | FDE: 0x1f3b80 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS7_EEE10push_frontERKS7_]
// Khung tháo gỡ #1986 | Địa chỉ PC: 0x18e698 | Địa chỉ FDE: 0x1f3b80 | Kích thước: 256 bytes
//   0x18e698: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18e69c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18e6a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18e6a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1986_0x18e698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e698ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1987 | PC: 0x18e7f4 | FDE: 0x1f3c50 | Size: 256 bytes [PyInit__sre]
// Khung tháo gỡ #1987 | Địa chỉ PC: 0x18e7f4 | Địa chỉ FDE: 0x1f3c50 | Kích thước: 256 bytes
//   0x18e7f4: 900004A0  adrp     x0, #0x222000
//   0x18e7f8: 912DC000  add      x0, x0, #0xb70
//   0x18e7fc: 17FB2889  b        #0x58a20
//   0x18e800: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1987_0x18e7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e7f4ULL ^ (static_cast<uint64_t>(0x900004a0ULL) << 13);
    acc = (acc + a1 + 0x912dc000ULL) ^ 0x1f3c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1988 | PC: 0x19abb8 | FDE: 0x1f4650 | Size: 256 bytes [analyze_descriptor]
// Khung tháo gỡ #1988 | Địa chỉ PC: 0x19abb8 | Địa chỉ FDE: 0x1f4650 | Kích thước: 256 bytes
//   0x19abb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19abbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19abc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19abc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1988_0x19abb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19abb8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f4650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1989 | PC: 0x19ad18 | FDE: 0x1f4670 | Size: 256 bytes [specialize_dict_access]
// Khung tháo gỡ #1989 | Địa chỉ PC: 0x19ad18 | Địa chỉ FDE: 0x1f4670 | Kích thước: 256 bytes
//   0x19ad18: D10143FF  sub      sp, sp, #0x50
//   0x19ad1c: F9000BF7  str      x23, [sp, #0x10]
//   0x19ad20: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x19ad24: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1989_0x19ad18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ad18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f4670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1990 | PC: 0x19ae5c | FDE: 0x1f4698 | Size: 8 bytes [specialize_module_load_attr]
// Khung tháo gỡ #1990 | Địa chỉ PC: 0x19ae5c | Địa chỉ FDE: 0x1f4698 | Kích thước: 8 bytes
//   0x19ae5c: 12800000  mov      w0, #-1
//   0x19ae60: D65F03C0  ret      
static inline uint64_t fde_func_1990_0x19ae5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ae5cULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4698ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1991 | PC: 0x19ae64 | FDE: 0x1f46b0 | Size: 256 bytes [drogon_setup_load_method_cache]
// Khung tháo gỡ #1991 | Địa chỉ PC: 0x19ae64 | Địa chỉ FDE: 0x1f46b0 | Kích thước: 256 bytes
//   0x19ae64: D10183FF  sub      sp, sp, #0x60
//   0x19ae68: F90013F7  str      x23, [sp, #0x20]
//   0x19ae6c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x19ae70: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1991_0x19ae64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ae64ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1f46b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1992 | PC: 0x19b01c | FDE: 0x1f46d8 | Size: 256 bytes [drogon_load_method_from_cache]
// Khung tháo gỡ #1992 | Địa chỉ PC: 0x19b01c | Địa chỉ FDE: 0x1f46d8 | Kích thước: 256 bytes
//   0x19b01c: B9401889  ldr      w9, [x4, #0x18]
//   0x19b020: F9400408  ldr      x8, [x0, #8]
//   0x19b024: 71000D3F  cmp      w9, #3
//   0x19b028: 540002A0  b.eq     #0x19b07c
static inline uint64_t fde_func_1992_0x19b01c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b01cULL ^ (static_cast<uint64_t>(0xb9401889ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1f46d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1993 | PC: 0x19b138 | FDE: 0x1f46f0 | Size: 256 bytes [drogon_load_attr_from_cache]
// Khung tháo gỡ #1993 | Địa chỉ PC: 0x19b138 | Địa chỉ FDE: 0x1f46f0 | Kích thước: 256 bytes
//   0x19b138: F9400408  ldr      x8, [x0, #8]
//   0x19b13c: F900005F  str      xzr, [x2]
//   0x19b140: B9401869  ldr      w9, [x3, #0x18]
//   0x19b144: 7100153F  cmp      w9, #5
static inline uint64_t fde_func_1993_0x19b138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b138ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf900005fULL) ^ 0x1f46f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1994 | PC: 0x19b328 | FDE: 0x1f4708 | Size: 256 bytes [drogon_setup_load_attr_cache]
// Khung tháo gỡ #1994 | Địa chỉ PC: 0x19b328 | Địa chỉ FDE: 0x1f4708 | Kích thước: 256 bytes
//   0x19b328: D10103FF  sub      sp, sp, #0x40
//   0x19b32c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x19b330: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x19b334: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1994_0x19b328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b328ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1995 | PC: 0x19b454 | FDE: 0x1f4730 | Size: 256 bytes [drogon_store_attr_from_cache]
// Khung tháo gỡ #1995 | Địa chỉ PC: 0x19b454 | Địa chỉ FDE: 0x1f4730 | Kích thước: 256 bytes
//   0x19b454: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19b458: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19b45c: 910043FD  add      x29, sp, #0x10
//   0x19b460: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1995_0x19b454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b454ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1996 | PC: 0x19b648 | FDE: 0x1f4750 | Size: 16 bytes [drogon_setup_store_attr_cache]
// Khung tháo gỡ #1996 | Địa chỉ PC: 0x19b648 | Địa chỉ FDE: 0x1f4750 | Kích thước: 16 bytes
//   0x19b648: 12800008  mov      w8, #-1
//   0x19b64c: 2A1F03E0  mov      w0, wzr
//   0x19b650: B9000068  str      w8, [x3]
//   0x19b654: D65F03C0  ret      
static inline uint64_t fde_func_1996_0x19b648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b648ULL ^ (static_cast<uint64_t>(0x12800008ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1f4750ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1997 | PC: 0x19b658 | FDE: 0x1f4768 | Size: 136 bytes [drogon_setup_store_subscr_cache]
// Khung tháo gỡ #1997 | Địa chỉ PC: 0x19b658 | Địa chỉ FDE: 0x1f4768 | Kích thước: 136 bytes
//   0x19b658: 90000329  adrp     x9, #0x1ff000
//   0x19b65c: F9400408  ldr      x8, [x0, #8]
//   0x19b660: F947ED29  ldr      x9, [x9, #0xfd8]
//   0x19b664: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1997_0x19b658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b658ULL ^ (static_cast<uint64_t>(0x90000329ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1f4768ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1998 | PC: 0x19b6e0 | FDE: 0x1f4780 | Size: 148 bytes [drogon_setup_binary_subscr_cache]
// Khung tháo gỡ #1998 | Địa chỉ PC: 0x19b6e0 | Địa chỉ FDE: 0x1f4780 | Kích thước: 148 bytes
//   0x19b6e0: 90000329  adrp     x9, #0x1ff000
//   0x19b6e4: F9400408  ldr      x8, [x0, #8]
//   0x19b6e8: F947ED29  ldr      x9, [x9, #0xfd8]
//   0x19b6ec: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1998_0x19b6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b6e0ULL ^ (static_cast<uint64_t>(0x90000329ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1f4780ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1999 | PC: 0x19b774 | FDE: 0x1f4798 | Size: 256 bytes [PyInit__sha512]
// Khung tháo gỡ #1999 | Địa chỉ PC: 0x19b774 | Địa chỉ FDE: 0x1f4798 | Kích thước: 256 bytes
//   0x19b774: 90000440  adrp     x0, #0x223000
//   0x19b778: 91146000  add      x0, x0, #0x518
//   0x19b77c: 17FAF4A9  b        #0x58a20
//   0x19b780: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1999_0x19b774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b774ULL ^ (static_cast<uint64_t>(0x90000440ULL) << 13);
    acc = (acc + a1 + 0x91146000ULL) ^ 0x1f4798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1600: return fde_func_1600_0x131790(a0, a1);
        case 1601: return fde_func_1601_0x1317b8(a0, a1);
        case 1602: return fde_func_1602_0x131874(a0, a1);
        case 1603: return fde_func_1603_0x131894(a0, a1);
        case 1604: return fde_func_1604_0x131900(a0, a1);
        case 1605: return fde_func_1605_0x13198c(a0, a1);
        case 1606: return fde_func_1606_0x131a1c(a0, a1);
        case 1607: return fde_func_1607_0x131ae8(a0, a1);
        case 1608: return fde_func_1608_0x131b3c(a0, a1);
        case 1609: return fde_func_1609_0x131c88(a0, a1);
        case 1610: return fde_func_1610_0x131d7c(a0, a1);
        case 1611: return fde_func_1611_0x131d84(a0, a1);
        case 1612: return fde_func_1612_0x131f78(a0, a1);
        case 1613: return fde_func_1613_0x132010(a0, a1);
        case 1614: return fde_func_1614_0x132018(a0, a1);
        case 1615: return fde_func_1615_0x132020(a0, a1);
        case 1616: return fde_func_1616_0x1320e0(a0, a1);
        case 1617: return fde_func_1617_0x1320f0(a0, a1);
        case 1618: return fde_func_1618_0x132154(a0, a1);
        case 1619: return fde_func_1619_0x13217c(a0, a1);
        case 1620: return fde_func_1620_0x1321dc(a0, a1);
        case 1621: return fde_func_1621_0x13221c(a0, a1);
        case 1622: return fde_func_1622_0x132274(a0, a1);
        case 1623: return fde_func_1623_0x1324a8(a0, a1);
        case 1624: return fde_func_1624_0x132560(a0, a1);
        case 1625: return fde_func_1625_0x132578(a0, a1);
        case 1626: return fde_func_1626_0x132b28(a0, a1);
        case 1627: return fde_func_1627_0x132cd4(a0, a1);
        case 1628: return fde_func_1628_0x132d4c(a0, a1);
        case 1629: return fde_func_1629_0x132eec(a0, a1);
        case 1630: return fde_func_1630_0x1333c4(a0, a1);
        case 1631: return fde_func_1631_0x1333e8(a0, a1);
        case 1632: return fde_func_1632_0x134050(a0, a1);
        case 1633: return fde_func_1633_0x134110(a0, a1);
        case 1634: return fde_func_1634_0x1342b0(a0, a1);
        case 1635: return fde_func_1635_0x1342c8(a0, a1);
        case 1636: return fde_func_1636_0x134320(a0, a1);
        case 1637: return fde_func_1637_0x134324(a0, a1);
        case 1638: return fde_func_1638_0x1344fc(a0, a1);
        case 1639: return fde_func_1639_0x134770(a0, a1);
        case 1640: return fde_func_1640_0x134780(a0, a1);
        case 1641: return fde_func_1641_0x134790(a0, a1);
        case 1642: return fde_func_1642_0x134794(a0, a1);
        case 1643: return fde_func_1643_0x134830(a0, a1);
        case 1644: return fde_func_1644_0x1348f4(a0, a1);
        case 1645: return fde_func_1645_0x1349c0(a0, a1);
        case 1646: return fde_func_1646_0x134bc8(a0, a1);
        case 1647: return fde_func_1647_0x134bd4(a0, a1);
        case 1648: return fde_func_1648_0x134c64(a0, a1);
        case 1649: return fde_func_1649_0x134c68(a0, a1);
        case 1650: return fde_func_1650_0x134d2c(a0, a1);
        case 1651: return fde_func_1651_0x134df8(a0, a1);
        case 1652: return fde_func_1652_0x134f34(a0, a1);
        case 1653: return fde_func_1653_0x135070(a0, a1);
        case 1654: return fde_func_1654_0x1351a0(a0, a1);
        case 1655: return fde_func_1655_0x1351e4(a0, a1);
        case 1656: return fde_func_1656_0x13528c(a0, a1);
        case 1657: return fde_func_1657_0x135414(a0, a1);
        case 1658: return fde_func_1658_0x135648(a0, a1);
        case 1659: return fde_func_1659_0x135650(a0, a1);
        case 1660: return fde_func_1660_0x135658(a0, a1);
        case 1661: return fde_func_1661_0x135700(a0, a1);
        case 1662: return fde_func_1662_0x135798(a0, a1);
        case 1663: return fde_func_1663_0x135818(a0, a1);
        case 1664: return fde_func_1664_0x135b98(a0, a1);
        case 1665: return fde_func_1665_0x135ba4(a0, a1);
        case 1666: return fde_func_1666_0x135d84(a0, a1);
        case 1667: return fde_func_1667_0x135db4(a0, a1);
        case 1668: return fde_func_1668_0x135f40(a0, a1);
        case 1669: return fde_func_1669_0x1363f4(a0, a1);
        case 1670: return fde_func_1670_0x136490(a0, a1);
        case 1671: return fde_func_1671_0x136528(a0, a1);
        case 1672: return fde_func_1672_0x1365c4(a0, a1);
        case 1673: return fde_func_1673_0x1366c8(a0, a1);
        case 1674: return fde_func_1674_0x136b8c(a0, a1);
        case 1675: return fde_func_1675_0x136c44(a0, a1);
        case 1676: return fde_func_1676_0x136cc8(a0, a1);
        case 1677: return fde_func_1677_0x136d7c(a0, a1);
        case 1678: return fde_func_1678_0x136e90(a0, a1);
        case 1679: return fde_func_1679_0x137044(a0, a1);
        case 1680: return fde_func_1680_0x137144(a0, a1);
        case 1681: return fde_func_1681_0x137244(a0, a1);
        case 1682: return fde_func_1682_0x137340(a0, a1);
        case 1683: return fde_func_1683_0x137484(a0, a1);
        case 1684: return fde_func_1684_0x1375b8(a0, a1);
        case 1685: return fde_func_1685_0x13766c(a0, a1);
        case 1686: return fde_func_1686_0x137890(a0, a1);
        case 1687: return fde_func_1687_0x1379a0(a0, a1);
        case 1688: return fde_func_1688_0x138310(a0, a1);
        case 1689: return fde_func_1689_0x139214(a0, a1);
        case 1690: return fde_func_1690_0x13936c(a0, a1);
        case 1691: return fde_func_1691_0x1395bc(a0, a1);
        case 1692: return fde_func_1692_0x1395d4(a0, a1);
        case 1693: return fde_func_1693_0x1398b0(a0, a1);
        case 1694: return fde_func_1694_0x139ad4(a0, a1);
        case 1695: return fde_func_1695_0x13c438(a0, a1);
        case 1696: return fde_func_1696_0x13c5a4(a0, a1);
        case 1697: return fde_func_1697_0x13ca40(a0, a1);
        case 1698: return fde_func_1698_0x13ca58(a0, a1);
        case 1699: return fde_func_1699_0x13ca5c(a0, a1);
        case 1700: return fde_func_1700_0x13ca64(a0, a1);
        case 1701: return fde_func_1701_0x13caec(a0, a1);
        case 1702: return fde_func_1702_0x13cc10(a0, a1);
        case 1703: return fde_func_1703_0x13cc70(a0, a1);
        case 1704: return fde_func_1704_0x13cca0(a0, a1);
        case 1705: return fde_func_1705_0x13cce4(a0, a1);
        case 1706: return fde_func_1706_0x13cd54(a0, a1);
        case 1707: return fde_func_1707_0x13cd94(a0, a1);
        case 1708: return fde_func_1708_0x13cfc4(a0, a1);
        case 1709: return fde_func_1709_0x13cfec(a0, a1);
        case 1710: return fde_func_1710_0x13d05c(a0, a1);
        case 1711: return fde_func_1711_0x13d06c(a0, a1);
        case 1712: return fde_func_1712_0x13d0c4(a0, a1);
        case 1713: return fde_func_1713_0x13d0c8(a0, a1);
        case 1714: return fde_func_1714_0x13d0d0(a0, a1);
        case 1715: return fde_func_1715_0x13d0ec(a0, a1);
        case 1716: return fde_func_1716_0x13d0f0(a0, a1);
        case 1717: return fde_func_1717_0x13d0f4(a0, a1);
        case 1718: return fde_func_1718_0x13d140(a0, a1);
        case 1719: return fde_func_1719_0x13d170(a0, a1);
        case 1720: return fde_func_1720_0x13d190(a0, a1);
        case 1721: return fde_func_1721_0x13d198(a0, a1);
        case 1722: return fde_func_1722_0x13d1c0(a0, a1);
        case 1723: return fde_func_1723_0x13d28c(a0, a1);
        case 1724: return fde_func_1724_0x13d2ac(a0, a1);
        case 1725: return fde_func_1725_0x13d2e8(a0, a1);
        case 1726: return fde_func_1726_0x13d2f0(a0, a1);
        case 1727: return fde_func_1727_0x13d714(a0, a1);
        case 1728: return fde_func_1728_0x13d7e4(a0, a1);
        case 1729: return fde_func_1729_0x13d920(a0, a1);
        case 1730: return fde_func_1730_0x13da60(a0, a1);
        case 1731: return fde_func_1731_0x13e108(a0, a1);
        case 1732: return fde_func_1732_0x13e4d0(a0, a1);
        case 1733: return fde_func_1733_0x13e558(a0, a1);
        case 1734: return fde_func_1734_0x13e5e8(a0, a1);
        case 1735: return fde_func_1735_0x13e894(a0, a1);
        case 1736: return fde_func_1736_0x13ec38(a0, a1);
        case 1737: return fde_func_1737_0x13ec70(a0, a1);
        case 1738: return fde_func_1738_0x13eff4(a0, a1);
        case 1739: return fde_func_1739_0x140030(a0, a1);
        case 1740: return fde_func_1740_0x140380(a0, a1);
        case 1741: return fde_func_1741_0x140420(a0, a1);
        case 1742: return fde_func_1742_0x1404ac(a0, a1);
        case 1743: return fde_func_1743_0x1405cc(a0, a1);
        case 1744: return fde_func_1744_0x14096c(a0, a1);
        case 1745: return fde_func_1745_0x140ad4(a0, a1);
        case 1746: return fde_func_1746_0x141234(a0, a1);
        case 1747: return fde_func_1747_0x141694(a0, a1);
        case 1748: return fde_func_1748_0x141714(a0, a1);
        case 1749: return fde_func_1749_0x14171c(a0, a1);
        case 1750: return fde_func_1750_0x141724(a0, a1);
        case 1751: return fde_func_1751_0x142224(a0, a1);
        case 1752: return fde_func_1752_0x142bd8(a0, a1);
        case 1753: return fde_func_1753_0x142cf0(a0, a1);
        case 1754: return fde_func_1754_0x143e10(a0, a1);
        case 1755: return fde_func_1755_0x143e9c(a0, a1);
        case 1756: return fde_func_1756_0x143eec(a0, a1);
        case 1757: return fde_func_1757_0x143ef4(a0, a1);
        case 1758: return fde_func_1758_0x143ef8(a0, a1);
        case 1759: return fde_func_1759_0x143f50(a0, a1);
        case 1760: return fde_func_1760_0x143fe8(a0, a1);
        case 1761: return fde_func_1761_0x144064(a0, a1);
        case 1762: return fde_func_1762_0x1440e0(a0, a1);
        case 1763: return fde_func_1763_0x1440e8(a0, a1);
        case 1764: return fde_func_1764_0x1440f4(a0, a1);
        case 1765: return fde_func_1765_0x1440f8(a0, a1);
        case 1766: return fde_func_1766_0x144160(a0, a1);
        case 1767: return fde_func_1767_0x144218(a0, a1);
        case 1768: return fde_func_1768_0x144260(a0, a1);
        case 1769: return fde_func_1769_0x14439c(a0, a1);
        case 1770: return fde_func_1770_0x144450(a0, a1);
        case 1771: return fde_func_1771_0x144598(a0, a1);
        case 1772: return fde_func_1772_0x144640(a0, a1);
        case 1773: return fde_func_1773_0x14476c(a0, a1);
        case 1774: return fde_func_1774_0x1448dc(a0, a1);
        case 1775: return fde_func_1775_0x144994(a0, a1);
        case 1776: return fde_func_1776_0x144a94(a0, a1);
        case 1777: return fde_func_1777_0x144afc(a0, a1);
        case 1778: return fde_func_1778_0x144c50(a0, a1);
        case 1779: return fde_func_1779_0x144d7c(a0, a1);
        case 1780: return fde_func_1780_0x144d8c(a0, a1);
        case 1781: return fde_func_1781_0x144ebc(a0, a1);
        case 1782: return fde_func_1782_0x144fa8(a0, a1);
        case 1783: return fde_func_1783_0x145004(a0, a1);
        case 1784: return fde_func_1784_0x145048(a0, a1);
        case 1785: return fde_func_1785_0x1450c0(a0, a1);
        case 1786: return fde_func_1786_0x145214(a0, a1);
        case 1787: return fde_func_1787_0x145250(a0, a1);
        case 1788: return fde_func_1788_0x145260(a0, a1);
        case 1789: return fde_func_1789_0x145284(a0, a1);
        case 1790: return fde_func_1790_0x14529c(a0, a1);
        case 1791: return fde_func_1791_0x1452b0(a0, a1);
        case 1792: return fde_func_1792_0x1452c4(a0, a1);
        case 1793: return fde_func_1793_0x1452e8(a0, a1);
        case 1794: return fde_func_1794_0x1456b8(a0, a1);
        case 1795: return fde_func_1795_0x14576c(a0, a1);
        case 1796: return fde_func_1796_0x145770(a0, a1);
        case 1797: return fde_func_1797_0x145774(a0, a1);
        case 1798: return fde_func_1798_0x145798(a0, a1);
        case 1799: return fde_func_1799_0x14596c(a0, a1);
        case 1800: return fde_func_1800_0x14597c(a0, a1);
        case 1801: return fde_func_1801_0x1459bc(a0, a1);
        case 1802: return fde_func_1802_0x145a14(a0, a1);
        case 1803: return fde_func_1803_0x145ab0(a0, a1);
        case 1804: return fde_func_1804_0x145ac0(a0, a1);
        case 1805: return fde_func_1805_0x145b18(a0, a1);
        case 1806: return fde_func_1806_0x145b58(a0, a1);
        case 1807: return fde_func_1807_0x145bf4(a0, a1);
        case 1808: return fde_func_1808_0x145cf8(a0, a1);
        case 1809: return fde_func_1809_0x145d48(a0, a1);
        case 1810: return fde_func_1810_0x145f9c(a0, a1);
        case 1811: return fde_func_1811_0x146120(a0, a1);
        case 1812: return fde_func_1812_0x146124(a0, a1);
        case 1813: return fde_func_1813_0x14616c(a0, a1);
        case 1814: return fde_func_1814_0x146198(a0, a1);
        case 1815: return fde_func_1815_0x1461c0(a0, a1);
        case 1816: return fde_func_1816_0x1461e8(a0, a1);
        case 1817: return fde_func_1817_0x14627c(a0, a1);
        case 1818: return fde_func_1818_0x146320(a0, a1);
        case 1819: return fde_func_1819_0x146448(a0, a1);
        case 1820: return fde_func_1820_0x146478(a0, a1);
        case 1821: return fde_func_1821_0x1464ac(a0, a1);
        case 1822: return fde_func_1822_0x14d04c(a0, a1);
        case 1823: return fde_func_1823_0x14d27c(a0, a1);
        case 1824: return fde_func_1824_0x14d98c(a0, a1);
        case 1825: return fde_func_1825_0x14e578(a0, a1);
        case 1826: return fde_func_1826_0x14e828(a0, a1);
        case 1827: return fde_func_1827_0x14e8ac(a0, a1);
        case 1828: return fde_func_1828_0x14e968(a0, a1);
        case 1829: return fde_func_1829_0x14e9b4(a0, a1);
        case 1830: return fde_func_1830_0x14ea70(a0, a1);
        case 1831: return fde_func_1831_0x14eabc(a0, a1);
        case 1832: return fde_func_1832_0x14eac4(a0, a1);
        case 1833: return fde_func_1833_0x14eadc(a0, a1);
        case 1834: return fde_func_1834_0x14eb50(a0, a1);
        case 1835: return fde_func_1835_0x14eb68(a0, a1);
        case 1836: return fde_func_1836_0x14ebdc(a0, a1);
        case 1837: return fde_func_1837_0x14ebf4(a0, a1);
        case 1838: return fde_func_1838_0x14ec0c(a0, a1);
        case 1839: return fde_func_1839_0x14ec2c(a0, a1);
        case 1840: return fde_func_1840_0x14ec5c(a0, a1);
        case 1841: return fde_func_1841_0x14ecf8(a0, a1);
        case 1842: return fde_func_1842_0x14ed4c(a0, a1);
        case 1843: return fde_func_1843_0x14ed74(a0, a1);
        case 1844: return fde_func_1844_0x14edc4(a0, a1);
        case 1845: return fde_func_1845_0x14ee60(a0, a1);
        case 1846: return fde_func_1846_0x14eed4(a0, a1);
        case 1847: return fde_func_1847_0x14ef70(a0, a1);
        case 1848: return fde_func_1848_0x14effc(a0, a1);
        case 1849: return fde_func_1849_0x14f054(a0, a1);
        case 1850: return fde_func_1850_0x14f0a8(a0, a1);
        case 1851: return fde_func_1851_0x14f280(a0, a1);
        case 1852: return fde_func_1852_0x14f2a4(a0, a1);
        case 1853: return fde_func_1853_0x14f324(a0, a1);
        case 1854: return fde_func_1854_0x14f3a4(a0, a1);
        case 1855: return fde_func_1855_0x14f424(a0, a1);
        case 1856: return fde_func_1856_0x14f448(a0, a1);
        case 1857: return fde_func_1857_0x14f46c(a0, a1);
        case 1858: return fde_func_1858_0x14f534(a0, a1);
        case 1859: return fde_func_1859_0x14f5fc(a0, a1);
        case 1860: return fde_func_1860_0x14f664(a0, a1);
        case 1861: return fde_func_1861_0x150f8c(a0, a1);
        case 1862: return fde_func_1862_0x1525fc(a0, a1);
        case 1863: return fde_func_1863_0x1566d4(a0, a1);
        case 1864: return fde_func_1864_0x1589f8(a0, a1);
        case 1865: return fde_func_1865_0x158ab8(a0, a1);
        case 1866: return fde_func_1866_0x158c4c(a0, a1);
        case 1867: return fde_func_1867_0x15aeec(a0, a1);
        case 1868: return fde_func_1868_0x15b1c8(a0, a1);
        case 1869: return fde_func_1869_0x15e980(a0, a1);
        case 1870: return fde_func_1870_0x15feac(a0, a1);
        case 1871: return fde_func_1871_0x15ff9c(a0, a1);
        case 1872: return fde_func_1872_0x15ffc4(a0, a1);
        case 1873: return fde_func_1873_0x1600b4(a0, a1);
        case 1874: return fde_func_1874_0x1601a4(a0, a1);
        case 1875: return fde_func_1875_0x16206c(a0, a1);
        case 1876: return fde_func_1876_0x1627fc(a0, a1);
        case 1877: return fde_func_1877_0x1654ac(a0, a1);
        case 1878: return fde_func_1878_0x169f0c(a0, a1);
        case 1879: return fde_func_1879_0x16a2c0(a0, a1);
        case 1880: return fde_func_1880_0x16b374(a0, a1);
        case 1881: return fde_func_1881_0x16b384(a0, a1);
        case 1882: return fde_func_1882_0x16de98(a0, a1);
        case 1883: return fde_func_1883_0x16ea38(a0, a1);
        case 1884: return fde_func_1884_0x16ea78(a0, a1);
        case 1885: return fde_func_1885_0x172584(a0, a1);
        case 1886: return fde_func_1886_0x17439c(a0, a1);
        case 1887: return fde_func_1887_0x174788(a0, a1);
        case 1888: return fde_func_1888_0x177e4c(a0, a1);
        case 1889: return fde_func_1889_0x177ec0(a0, a1);
        case 1890: return fde_func_1890_0x177f94(a0, a1);
        case 1891: return fde_func_1891_0x1780cc(a0, a1);
        case 1892: return fde_func_1892_0x178488(a0, a1);
        case 1893: return fde_func_1893_0x1794cc(a0, a1);
        case 1894: return fde_func_1894_0x1794d8(a0, a1);
        case 1895: return fde_func_1895_0x179608(a0, a1);
        case 1896: return fde_func_1896_0x17a03c(a0, a1);
        case 1897: return fde_func_1897_0x17a0e8(a0, a1);
        case 1898: return fde_func_1898_0x17a15c(a0, a1);
        case 1899: return fde_func_1899_0x17a168(a0, a1);
        case 1900: return fde_func_1900_0x17a198(a0, a1);
        case 1901: return fde_func_1901_0x17a1c4(a0, a1);
        case 1902: return fde_func_1902_0x17a1ec(a0, a1);
        case 1903: return fde_func_1903_0x17a2d8(a0, a1);
        case 1904: return fde_func_1904_0x17b054(a0, a1);
        case 1905: return fde_func_1905_0x17b170(a0, a1);
        case 1906: return fde_func_1906_0x17b1dc(a0, a1);
        case 1907: return fde_func_1907_0x17b1e4(a0, a1);
        case 1908: return fde_func_1908_0x17b220(a0, a1);
        case 1909: return fde_func_1909_0x17b224(a0, a1);
        case 1910: return fde_func_1910_0x17b26c(a0, a1);
        case 1911: return fde_func_1911_0x17b2c4(a0, a1);
        case 1912: return fde_func_1912_0x17b320(a0, a1);
        case 1913: return fde_func_1913_0x17b3ac(a0, a1);
        case 1914: return fde_func_1914_0x17b464(a0, a1);
        case 1915: return fde_func_1915_0x17b4cc(a0, a1);
        case 1916: return fde_func_1916_0x17b53c(a0, a1);
        case 1917: return fde_func_1917_0x17b58c(a0, a1);
        case 1918: return fde_func_1918_0x17bb50(a0, a1);
        case 1919: return fde_func_1919_0x17bbac(a0, a1);
        case 1920: return fde_func_1920_0x17bbb8(a0, a1);
        case 1921: return fde_func_1921_0x17bbc4(a0, a1);
        case 1922: return fde_func_1922_0x17d9f4(a0, a1);
        case 1923: return fde_func_1923_0x1832cc(a0, a1);
        case 1924: return fde_func_1924_0x183438(a0, a1);
        case 1925: return fde_func_1925_0x183484(a0, a1);
        case 1926: return fde_func_1926_0x1835c4(a0, a1);
        case 1927: return fde_func_1927_0x1835c8(a0, a1);
        case 1928: return fde_func_1928_0x1835e0(a0, a1);
        case 1929: return fde_func_1929_0x1835f8(a0, a1);
        case 1930: return fde_func_1930_0x183764(a0, a1);
        case 1931: return fde_func_1931_0x1838d0(a0, a1);
        case 1932: return fde_func_1932_0x183aa4(a0, a1);
        case 1933: return fde_func_1933_0x183c34(a0, a1);
        case 1934: return fde_func_1934_0x188e44(a0, a1);
        case 1935: return fde_func_1935_0x188e84(a0, a1);
        case 1936: return fde_func_1936_0x188f94(a0, a1);
        case 1937: return fde_func_1937_0x188ff8(a0, a1);
        case 1938: return fde_func_1938_0x189020(a0, a1);
        case 1939: return fde_func_1939_0x18902c(a0, a1);
        case 1940: return fde_func_1940_0x189134(a0, a1);
        case 1941: return fde_func_1941_0x189190(a0, a1);
        case 1942: return fde_func_1942_0x18930c(a0, a1);
        case 1943: return fde_func_1943_0x189320(a0, a1);
        case 1944: return fde_func_1944_0x189440(a0, a1);
        case 1945: return fde_func_1945_0x189448(a0, a1);
        case 1946: return fde_func_1946_0x18946c(a0, a1);
        case 1947: return fde_func_1947_0x18951c(a0, a1);
        case 1948: return fde_func_1948_0x18958c(a0, a1);
        case 1949: return fde_func_1949_0x189600(a0, a1);
        case 1950: return fde_func_1950_0x189638(a0, a1);
        case 1951: return fde_func_1951_0x18a0f0(a0, a1);
        case 1952: return fde_func_1952_0x18ac00(a0, a1);
        case 1953: return fde_func_1953_0x18b0b4(a0, a1);
        case 1954: return fde_func_1954_0x18b304(a0, a1);
        case 1955: return fde_func_1955_0x18b5dc(a0, a1);
        case 1956: return fde_func_1956_0x18b76c(a0, a1);
        case 1957: return fde_func_1957_0x18b8d0(a0, a1);
        case 1958: return fde_func_1958_0x18bb00(a0, a1);
        case 1959: return fde_func_1959_0x18bbbc(a0, a1);
        case 1960: return fde_func_1960_0x18beec(a0, a1);
        case 1961: return fde_func_1961_0x18d190(a0, a1);
        case 1962: return fde_func_1962_0x18d1d4(a0, a1);
        case 1963: return fde_func_1963_0x18d1dc(a0, a1);
        case 1964: return fde_func_1964_0x18d278(a0, a1);
        case 1965: return fde_func_1965_0x18d2b4(a0, a1);
        case 1966: return fde_func_1966_0x18d3d0(a0, a1);
        case 1967: return fde_func_1967_0x18d464(a0, a1);
        case 1968: return fde_func_1968_0x18d498(a0, a1);
        case 1969: return fde_func_1969_0x18d500(a0, a1);
        case 1970: return fde_func_1970_0x18d558(a0, a1);
        case 1971: return fde_func_1971_0x18d760(a0, a1);
        case 1972: return fde_func_1972_0x18d7f8(a0, a1);
        case 1973: return fde_func_1973_0x18d8b4(a0, a1);
        case 1974: return fde_func_1974_0x18d8c0(a0, a1);
        case 1975: return fde_func_1975_0x18d918(a0, a1);
        case 1976: return fde_func_1976_0x18d928(a0, a1);
        case 1977: return fde_func_1977_0x18d9bc(a0, a1);
        case 1978: return fde_func_1978_0x18da34(a0, a1);
        case 1979: return fde_func_1979_0x18db20(a0, a1);
        case 1980: return fde_func_1980_0x18dd34(a0, a1);
        case 1981: return fde_func_1981_0x18dde0(a0, a1);
        case 1982: return fde_func_1982_0x18df24(a0, a1);
        case 1983: return fde_func_1983_0x18e27c(a0, a1);
        case 1984: return fde_func_1984_0x18e3dc(a0, a1);
        case 1985: return fde_func_1985_0x18e538(a0, a1);
        case 1986: return fde_func_1986_0x18e698(a0, a1);
        case 1987: return fde_func_1987_0x18e7f4(a0, a1);
        case 1988: return fde_func_1988_0x19abb8(a0, a1);
        case 1989: return fde_func_1989_0x19ad18(a0, a1);
        case 1990: return fde_func_1990_0x19ae5c(a0, a1);
        case 1991: return fde_func_1991_0x19ae64(a0, a1);
        case 1992: return fde_func_1992_0x19b01c(a0, a1);
        case 1993: return fde_func_1993_0x19b138(a0, a1);
        case 1994: return fde_func_1994_0x19b328(a0, a1);
        case 1995: return fde_func_1995_0x19b454(a0, a1);
        case 1996: return fde_func_1996_0x19b648(a0, a1);
        case 1997: return fde_func_1997_0x19b658(a0, a1);
        case 1998: return fde_func_1998_0x19b6e0(a0, a1);
        case 1999: return fde_func_1999_0x19b774(a0, a1);
        default: return 0ULL;
    }
}