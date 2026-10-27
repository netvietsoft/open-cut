// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 2/5 for libavmdlv2.so
// Phân mảnh Hàm AArch64 C++17 sạch 2/5 cho libavmdlv2.so
// Covers .text function indices [380 .. 759] out of 1900 total functions
// Bao phủ chỉ số hàm .text [380 .. 759] trên tổng số 1900 hàm
// ============================================================================
#include "avmdlv2_core.h"

namespace com {
namespace ss {
namespace ttmio {

// Func #0380 | PC: 0x05cdc8 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0380 | Địa chỉ PC: 0x05cdc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x05cdc8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05cdcc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05cdd0: 910043FD  add      x29, sp, #0x10
//   0x05cdd4: F00007E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0380_0x05cdc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cdc8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0381 | PC: 0x05ce54 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #0381 | Địa chỉ PC: 0x05ce54 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x05ce54: D10143FF  sub      sp, sp, #0x50
//   0x05ce58: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05ce5c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x05ce60: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0381_0x05ce54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ce54ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #0382 | PC: 0x05cee8 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0382 | Địa chỉ PC: 0x05cee8 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x05cee8: D10143FF  sub      sp, sp, #0x50
//   0x05ceec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05cef0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05cef4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0382_0x05cee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cee8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0383 | PC: 0x05cf6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0383 | Địa chỉ PC: 0x05cf6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05cf6c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05cf70: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05cf74: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05cf78: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0383_0x05cf6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cf6cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0384 | PC: 0x05d240 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0384 | Địa chỉ PC: 0x05d240 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05d240: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05d244: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05d248: 910043FD  add      x29, sp, #0x10
//   0x05d24c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0384_0x05d240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d240ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0385 | PC: 0x05d660 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0385 | Địa chỉ PC: 0x05d660 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05d660: D10303FF  sub      sp, sp, #0xc0
//   0x05d664: F9003BF9  str      x25, [sp, #0x70]
//   0x05d668: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x05d66c: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0385_0x05d660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d660ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0386 | PC: 0x05da28 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0386 | Địa chỉ PC: 0x05da28 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x05da28: D10103FF  sub      sp, sp, #0x40
//   0x05da2c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05da30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05da34: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0386_0x05da28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05da28ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0387 | PC: 0x05dacc | FDE: 0x148a38 | Size: 56 bytes [_ZN3com2ss5ttmio10MDLMessageC2Ev]
// Hàm #0387 | Địa chỉ PC: 0x05dacc | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x05dacc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05dad0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05dad4: 910043FD  add      x29, sp, #0x10
//   0x05dad8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0387_0x05dacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05daccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0388 | PC: 0x05db04 | FDE: 0x148a38 | Size: 148 bytes [_ZN3com2ss5ttmio10MDLMessageC2ERKS2_]
// Hàm #0388 | Địa chỉ PC: 0x05db04 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x05db04: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05db08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05db0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05db10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0388_0x05db04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05db04ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #0389 | PC: 0x05db98 | FDE: 0x148a38 | Size: 124 bytes [_ZN3com2ss5ttmio10MDLMessageaSERKS2_]
// Hàm #0389 | Địa chỉ PC: 0x05db98 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x05db98: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05db9c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05dba0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05dba4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0389_0x05db98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05db98ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0390 | PC: 0x05dc14 | FDE: 0x148a38 | Size: 104 bytes [_ZN3com2ss5ttmio10MDLMessageD2Ev]
// Hàm #0390 | Địa chỉ PC: 0x05dc14 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x05dc14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05dc18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05dc1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05dc20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0390_0x05dc14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dc14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0391 | PC: 0x05dc7c | FDE: 0x148a38 | Size: 128 bytes [_ZNK3com2ss5ttmio10MDLMessage12findIntValueEPKcRi]
// Hàm #0391 | Địa chỉ PC: 0x05dc7c | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x05dc7c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05dc80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05dc84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05dc88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0391_0x05dc7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dc7cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0392 | PC: 0x05dcfc | FDE: 0x148a38 | Size: 128 bytes [_ZNK3com2ss5ttmio10MDLMessage13findLongValueEPKcRl]
// Hàm #0392 | Địa chỉ PC: 0x05dcfc | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x05dcfc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05dd00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05dd04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05dd08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0392_0x05dcfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dcfcULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0393 | PC: 0x05dd7c | FDE: 0x148a38 | Size: 132 bytes [_ZNK3com2ss5ttmio10MDLMessage16findCStringValueEPKcRPc]
// Hàm #0393 | Địa chỉ PC: 0x05dd7c | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x05dd7c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05dd80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05dd84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05dd88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0393_0x05dd7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dd7cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0394 | PC: 0x05de00 | FDE: 0x148a38 | Size: 128 bytes [_ZNK3com2ss5ttmio10MDLMessage13findPairValueEPKcRNS1_12MIOPairValueE]
// Hàm #0394 | Địa chỉ PC: 0x05de00 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x05de00: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05de04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05de08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05de0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0394_0x05de00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05de00ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0395 | PC: 0x05de80 | FDE: 0x148a38 | Size: 128 bytes [_ZNK3com2ss5ttmio10MDLMessage15findObjectValueEPKcRPNS1_9MIOObjectE]
// Hàm #0395 | Địa chỉ PC: 0x05de80 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x05de80: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05de84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05de88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05de8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0395_0x05de80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05de80ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0396 | PC: 0x05df00 | FDE: 0x148a38 | Size: 128 bytes [_ZNK3com2ss5ttmio10MDLMessage15findUInt64ValueEPKcRm]
// Hàm #0396 | Địa chỉ PC: 0x05df00 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x05df00: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05df04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05df08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05df0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0396_0x05df00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05df00ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0397 | PC: 0x05df80 | FDE: 0x148a38 | Size: 208 bytes [_ZN3com2ss5ttmio10MDLMessage8setInt32EPKci]
// Hàm #0397 | Địa chỉ PC: 0x05df80 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x05df80: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05df84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05df88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05df8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0397_0x05df80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05df80ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0398 | PC: 0x05e050 | FDE: 0x148a38 | Size: 208 bytes [_ZN3com2ss5ttmio10MDLMessage8setInt64EPKcl]
// Hàm #0398 | Địa chỉ PC: 0x05e050 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x05e050: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05e054: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05e058: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05e05c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0398_0x05e050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e050ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0399 | PC: 0x05e120 | FDE: 0x148a38 | Size: 208 bytes [_ZN3com2ss5ttmio10MDLMessage9setStringEPKcS4_]
// Hàm #0399 | Địa chỉ PC: 0x05e120 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x05e120: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05e124: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05e128: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05e12c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0399_0x05e120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e120ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0400 | PC: 0x05e1f0 | FDE: 0x148a38 | Size: 216 bytes [_ZN3com2ss5ttmio10MDLMessage7setPairEPKcNS1_12MIOPairValueE]
// Hàm #0400 | Địa chỉ PC: 0x05e1f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x05e1f0: D10143FF  sub      sp, sp, #0x50
//   0x05e1f4: A900DFE3  stp      x3, x23, [sp, #8]
//   0x05e1f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05e1fc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0400_0x05e1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e1f0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa900dfe3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #0401 | PC: 0x05e2c8 | FDE: 0x148a38 | Size: 208 bytes [_ZN3com2ss5ttmio10MDLMessage9setObjectEPKcPNS1_9MIOObjectE]
// Hàm #0401 | Địa chỉ PC: 0x05e2c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x05e2c8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05e2cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05e2d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05e2d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0401_0x05e2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e2c8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0402 | PC: 0x05e398 | FDE: 0x148a38 | Size: 208 bytes [_ZN3com2ss5ttmio10MDLMessage9setUInt64EPKcm]
// Hàm #0402 | Địa chỉ PC: 0x05e398 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x05e398: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05e39c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05e3a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05e3a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0402_0x05e398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e398ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0403 | PC: 0x05e468 | FDE: 0x148a38 | Size: 100 bytes [_ZN3com2ss5ttmio10MDLMessage8isMemberEPKc]
// Hàm #0403 | Địa chỉ PC: 0x05e468 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x05e468: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e46c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e470: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e474: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0403_0x05e468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e468ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0404 | PC: 0x05e4cc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLSingletonsHolderC2Ev]
// Hàm #0404 | Địa chỉ PC: 0x05e4cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05e4cc: D100C3FF  sub      sp, sp, #0x30
//   0x05e4d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e4d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e4d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0404_0x05e4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e4ccULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0405 | PC: 0x05e6c8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLSingletonsHolderD2Ev]
// Hàm #0405 | Địa chỉ PC: 0x05e6c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05e6c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05e6cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e6d0: 910043FD  add      x29, sp, #0x10
//   0x05e6d4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0405_0x05e6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e6c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0406 | PC: 0x05e848 | FDE: 0x148a38 | Size: 168 bytes [_ZN3com2ss5ttmio19MDLSingletonsHolder11getInstanceEv]
// Hàm #0406 | Địa chỉ PC: 0x05e848 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x05e848: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05e84c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e850: 910043FD  add      x29, sp, #0x10
//   0x05e854: D00007F4  adrp     x20, #0x15c000
static inline uint64_t fde_func_0406_0x05e848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e848ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0407 | PC: 0x05e8f0 | FDE: 0x148a38 | Size: 144 bytes [_ZN3com2ss5ttmio19MDLSingletonsHolder4initEv]
// Hàm #0407 | Địa chỉ PC: 0x05e8f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x05e8f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05e8f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e8f8: 910043FD  add      x29, sp, #0x10
//   0x05e8fc: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_0407_0x05e8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e8f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #0408 | PC: 0x05e980 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder18getStrategyFactoryEv]
// Hàm #0408 | Địa chỉ PC: 0x05e980 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e980: F9400000  ldr      x0, [x0]
//   0x05e984: D65F03C0  ret      
static inline uint64_t fde_func_0408_0x05e980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e980ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0409 | PC: 0x05e988 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder20getDownloaderFactoryEv]
// Hàm #0409 | Địa chỉ PC: 0x05e988 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e988: F9400400  ldr      x0, [x0, #8]
//   0x05e98c: D65F03C0  ret      
static inline uint64_t fde_func_0409_0x05e988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e988ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0410 | PC: 0x05e990 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder14getTaskFactoryEv]
// Hàm #0410 | Địa chỉ PC: 0x05e990 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e990: F9400800  ldr      x0, [x0, #0x10]
//   0x05e994: D65F03C0  ret      
static inline uint64_t fde_func_0410_0x05e990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e990ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0411 | PC: 0x05e998 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder17getNetWorkManagerEv]
// Hàm #0411 | Địa chỉ PC: 0x05e998 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e998: F9401000  ldr      x0, [x0, #0x20]
//   0x05e99c: D65F03C0  ret      
static inline uint64_t fde_func_0411_0x05e998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e998ULL ^ (static_cast<uint64_t>(0xf9401000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0412 | PC: 0x05e9a0 | FDE: 0x148a38 | Size: 44 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder20getNetWorkManagerPtrEv]
// Hàm #0412 | Địa chỉ PC: 0x05e9a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x05e9a0: F9401009  ldr      x9, [x0, #0x20]
//   0x05e9a4: F9000109  str      x9, [x8]
//   0x05e9a8: F9401409  ldr      x9, [x0, #0x28]
//   0x05e9ac: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_0412_0x05e9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9a0ULL ^ (static_cast<uint64_t>(0xf9401009ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #0413 | PC: 0x05e9cc | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder14getFileManagerEv]
// Hàm #0413 | Địa chỉ PC: 0x05e9cc | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9cc: F9401800  ldr      x0, [x0, #0x30]
//   0x05e9d0: D65F03C0  ret      
static inline uint64_t fde_func_0413_0x05e9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9ccULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0414 | PC: 0x05e9d4 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder15getConfigCenterEv]
// Hàm #0414 | Địa chỉ PC: 0x05e9d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9d4: F9400C00  ldr      x0, [x0, #0x18]
//   0x05e9d8: D65F03C0  ret      
static inline uint64_t fde_func_0414_0x05e9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9d4ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0415 | PC: 0x05e9dc | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder16getPlayInfoCacheEv]
// Hàm #0415 | Địa chỉ PC: 0x05e9dc | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9dc: F9401C00  ldr      x0, [x0, #0x38]
//   0x05e9e0: D65F03C0  ret      
static inline uint64_t fde_func_0415_0x05e9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9dcULL ^ (static_cast<uint64_t>(0xf9401c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0416 | PC: 0x05e9e4 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder13getThreadPoolEv]
// Hàm #0416 | Địa chỉ PC: 0x05e9e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9e4: F9402000  ldr      x0, [x0, #0x40]
//   0x05e9e8: D65F03C0  ret      
static inline uint64_t fde_func_0416_0x05e9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9e4ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0417 | PC: 0x05e9ec | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder13getBufferPoolEv]
// Hàm #0417 | Địa chỉ PC: 0x05e9ec | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9ec: F9402400  ldr      x0, [x0, #0x48]
//   0x05e9f0: D65F03C0  ret      
static inline uint64_t fde_func_0417_0x05e9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9ecULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0418 | PC: 0x05e9f4 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder13getLogManagerEv]
// Hàm #0418 | Địa chỉ PC: 0x05e9f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9f4: F9402800  ldr      x0, [x0, #0x50]
//   0x05e9f8: D65F03C0  ret      
static inline uint64_t fde_func_0418_0x05e9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9f4ULL ^ (static_cast<uint64_t>(0xf9402800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0419 | PC: 0x05e9fc | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder17getPreloadManagerEv]
// Hàm #0419 | Địa chỉ PC: 0x05e9fc | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05e9fc: F9402C00  ldr      x0, [x0, #0x58]
//   0x05ea00: D65F03C0  ret      
static inline uint64_t fde_func_0419_0x05e9fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9fcULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0420 | PC: 0x05ea04 | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder23getSocketTrainingCenterEv]
// Hàm #0420 | Địa chỉ PC: 0x05ea04 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05ea04: F9403000  ldr      x0, [x0, #0x60]
//   0x05ea08: D65F03C0  ret      
static inline uint64_t fde_func_0420_0x05ea04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ea04ULL ^ (static_cast<uint64_t>(0xf9403000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0421 | PC: 0x05ea0c | FDE: 0x148a38 | Size: 8 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder17getNetSpeedEngineEv]
// Hàm #0421 | Địa chỉ PC: 0x05ea0c | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05ea0c: F9403400  ldr      x0, [x0, #0x68]
//   0x05ea10: D65F03C0  ret      
static inline uint64_t fde_func_0421_0x05ea0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ea0cULL ^ (static_cast<uint64_t>(0xf9403400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0422 | PC: 0x05ea14 | FDE: 0x148a38 | Size: 256 bytes [_ZNK3com2ss5ttmio19MDLSingletonsHolder20getEventQueueFactoryEv]
// Hàm #0422 | Địa chỉ PC: 0x05ea14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05ea14: F9403800  ldr      x0, [x0, #0x70]
//   0x05ea18: D65F03C0  ret      
//   0x05ea1c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05ea20: A9014FF4  stp      x20, x19, [sp, #0x10]
static inline uint64_t fde_func_0422_0x05ea14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ea14ULL ^ (static_cast<uint64_t>(0xf9403800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0423 | PC: 0x05ebac | FDE: 0x148a38 | Size: 68 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactoryC2Ev]
// Hàm #0423 | Địa chỉ PC: 0x05ebac | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x05ebac: 528001A8  mov      w8, #0xd
//   0x05ebb0: B9000808  str      w8, [x0, #8]
//   0x05ebb4: 9100E008  add      x8, x0, #0x38
//   0x05ebb8: A903A008  stp      x8, x8, [x0, #0x38]
static inline uint64_t fde_func_0423_0x05ebac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ebacULL ^ (static_cast<uint64_t>(0x528001a8ULL) << 13);
    acc = (acc + a1 + 0xb9000808ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #0424 | PC: 0x05ebf0 | FDE: 0x148a38 | Size: 244 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactory24registerInnerDownloadersEv]
// Hàm #0424 | Địa chỉ PC: 0x05ebf0 | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x05ebf0: D10143FF  sub      sp, sp, #0x50
//   0x05ebf4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x05ebf8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05ebfc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0424_0x05ebf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ebf0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0425 | PC: 0x05ece4 | FDE: 0x148a38 | Size: 240 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactoryD2Ev]
// Hàm #0425 | Địa chỉ PC: 0x05ece4 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x05ece4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05ece8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05ecec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05ecf0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0425_0x05ece4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ece4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #0426 | PC: 0x05edd4 | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactoryD0Ev]
// Hàm #0426 | Địa chỉ PC: 0x05edd4 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x05edd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05edd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05eddc: 910043FD  add      x29, sp, #0x10
//   0x05ede0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0426_0x05edd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05edd4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #0427 | PC: 0x05edf8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactory18registerDownloaderEiRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEPFNS3_10shared_ptrINS1_16MIOVodNetAdapterEEEmEPFvPSD_E]
// Hàm #0427 | Địa chỉ PC: 0x05edf8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05edf8: D101C3FF  sub      sp, sp, #0x70
//   0x05edfc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x05ee00: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x05ee04: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0427_0x05edf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05edf8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0428 | PC: 0x05efb8 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactory20unregisterDownloaderEi]
// Hàm #0428 | Địa chỉ PC: 0x05efb8 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x05efb8: 7100303F  cmp      w1, #0xc
//   0x05efbc: 54000CEB  b.lt     #0x5f158
static inline uint64_t fde_func_0428_0x05efb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05efb8ULL ^ (static_cast<uint64_t>(0x7100303fULL) << 13);
    acc = (acc + a1 + 0x54000cebULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0429 | PC: 0x05efc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0429 | Địa chỉ PC: 0x05efc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05efc0: D10183FF  sub      sp, sp, #0x60
//   0x05efc4: F90013F7  str      x23, [sp, #0x20]
//   0x05efc8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05efcc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0429_0x05efc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05efc0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0430 | PC: 0x05f15c | FDE: 0x148a38 | Size: 84 bytes
// Hàm #0430 | Địa chỉ PC: 0x05f15c | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x05f15c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05f160: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f164: 910043FD  add      x29, sp, #0x10
//   0x05f168: A9405028  ldp      x8, x20, [x1]
static inline uint64_t fde_func_0430_0x05f15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f15cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #0431 | PC: 0x05f1b0 | FDE: 0x148a38 | Size: 132 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactory13hasRegisteredEi]
// Hàm #0431 | Địa chỉ PC: 0x05f1b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x05f1b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05f1b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05f1b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05f1bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0431_0x05f1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f1b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0432 | PC: 0x05f234 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactory16obtainDownloaderEiim]
// Hàm #0432 | Địa chỉ PC: 0x05f234 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05f234: D10183FF  sub      sp, sp, #0x60
//   0x05f238: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05f23c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05f240: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0432_0x05f234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f234ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0433 | PC: 0x05f33c | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio20MDLDownloaderFactory18givebackDownloaderEiNSt6__ndk110shared_ptrINS1_16MIOVodNetAdapterEEE]
// Hàm #0433 | Địa chỉ PC: 0x05f33c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05f33c: D65F03C0  ret      
//   0x05f340: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05f344: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f348: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0433_0x05f33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f33cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0434 | PC: 0x05f45c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0434 | Địa chỉ PC: 0x05f45c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05f45c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05f460: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f464: 910043FD  add      x29, sp, #0x10
//   0x05f468: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0434_0x05f45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f45cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0435 | PC: 0x05f640 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0435 | Địa chỉ PC: 0x05f640 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05f640: D10103FF  sub      sp, sp, #0x40
//   0x05f644: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05f648: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05f64c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0435_0x05f640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f640ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0436 | PC: 0x05fca8 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #0436 | Địa chỉ PC: 0x05fca8 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x05fca8: D100C3FF  sub      sp, sp, #0x30
//   0x05fcac: F9000BF3  str      x19, [sp, #0x10]
//   0x05fcb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05fcb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0436_0x05fca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fca8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #0437 | PC: 0x05fce4 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio17MDLHttpDownloader6DeleteEPNS1_16MIOVodNetAdapterE]
// Hàm #0437 | Địa chỉ PC: 0x05fce4 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x05fce4: B4000080  cbz      x0, #0x5fcf4
//   0x05fce8: F9400008  ldr      x8, [x0]
//   0x05fcec: F9400501  ldr      x1, [x8, #8]
//   0x05fcf0: D61F0020  br       x1
static inline uint64_t fde_func_0437_0x05fce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fce4ULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #0438 | PC: 0x05fcf8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0438 | Địa chỉ PC: 0x05fcf8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05fcf8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05fcfc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05fd00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05fd04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0438_0x05fcf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fcf8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0439 | PC: 0x05fe1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0439 | Địa chỉ PC: 0x05fe1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05fe1c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05fe20: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05fe24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05fe28: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0439_0x05fe1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fe1cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0440 | PC: 0x060010 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0440 | Địa chỉ PC: 0x060010 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x060010: D101C3FF  sub      sp, sp, #0x70
//   0x060014: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x060018: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06001c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0440_0x060010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060010ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0441 | PC: 0x0600e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0441 | Địa chỉ PC: 0x0600e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0600e4: D10103FF  sub      sp, sp, #0x40
//   0x0600e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0600ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0600f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0441_0x0600e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0600e4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0442 | PC: 0x060250 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #0442 | Địa chỉ PC: 0x060250 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x060250: D100C3FF  sub      sp, sp, #0x30
//   0x060254: F9000BF3  str      x19, [sp, #0x10]
//   0x060258: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06025c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0442_0x060250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060250ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0443 | PC: 0x060314 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0443 | Địa chỉ PC: 0x060314 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x060314: D102C3FF  sub      sp, sp, #0xb0
//   0x060318: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x06031c: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x060320: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0443_0x060314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060314ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0444 | PC: 0x060754 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0444 | Địa chỉ PC: 0x060754 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x060754: D10243FF  sub      sp, sp, #0x90
//   0x060758: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x06075c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x060760: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0444_0x060754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060754ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0445 | PC: 0x060a34 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0445 | Địa chỉ PC: 0x060a34 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x060a34: D10543FF  sub      sp, sp, #0x150
//   0x060a38: F9008BFC  str      x28, [sp, #0x110]
//   0x060a3c: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x060a40: A9134FF4  stp      x20, x19, [sp, #0x130]
static inline uint64_t fde_func_0445_0x060a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060a34ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0446 | PC: 0x060ae0 | FDE: 0x148a38 | Size: 252 bytes
// Hàm #0446 | Địa chỉ PC: 0x060ae0 | Địa chỉ FDE: 0x148a38 | Kích thước: 252 bytes
//   0x060ae0: D10103FF  sub      sp, sp, #0x40
//   0x060ae4: F9000BF5  str      x21, [sp, #0x10]
//   0x060ae8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x060aec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0446_0x060ae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060ae0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Func #0447 | PC: 0x060bdc | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0447 | Địa chỉ PC: 0x060bdc | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x060bdc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x060be0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x060be4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x060be8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0447_0x060bdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060bdcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0448 | PC: 0x060bf8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0448 | Địa chỉ PC: 0x060bf8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x060bf8: D106C3FF  sub      sp, sp, #0x1b0
//   0x060bfc: AA0003F3  mov      x19, x0
//   0x060c00: A9432009  ldp      x9, x8, [x0, #0x30]
//   0x060c04: F9405C00  ldr      x0, [x0, #0xb8]
static inline uint64_t fde_func_0448_0x060bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060bf8ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0449 | PC: 0x0611bc | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0449 | Địa chỉ PC: 0x0611bc | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x0611bc: D100C3FF  sub      sp, sp, #0x30
//   0x0611c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0611c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0611c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0449_0x0611bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0611bcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0450 | PC: 0x061270 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio17MDLHttpDownloader22convertIpListToAddressEPc]
// Hàm #0450 | Địa chỉ PC: 0x061270 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x061270: D10383FF  sub      sp, sp, #0xe0
//   0x061274: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x061278: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x06127c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0450_0x061270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061270ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0451 | PC: 0x0617c0 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0451 | Địa chỉ PC: 0x0617c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x0617c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0617c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0617c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0617cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0451_0x0617c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0617c0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0452 | PC: 0x061858 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0452 | Địa chỉ PC: 0x061858 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x061858: D10183FF  sub      sp, sp, #0x60
//   0x06185c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x061860: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x061864: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0452_0x061858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061858ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0453 | PC: 0x061bac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0453 | Địa chỉ PC: 0x061bac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x061bac: D10243FF  sub      sp, sp, #0x90
//   0x061bb0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x061bb4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x061bb8: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0453_0x061bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061bacULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0454 | PC: 0x0620ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0454 | Địa chỉ PC: 0x0620ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0620ac: D10243FF  sub      sp, sp, #0x90
//   0x0620b0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0620b4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0620b8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0454_0x0620ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0620acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0455 | PC: 0x0623e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0455 | Địa chỉ PC: 0x0623e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0623e4: D10743FF  sub      sp, sp, #0x1d0
//   0x0623e8: AA0403F5  mov      x21, x4
//   0x0623ec: AA0303F3  mov      x19, x3
//   0x0623f0: 7100445F  cmp      w2, #0x11
static inline uint64_t fde_func_0455_0x0623e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0623e4ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xaa0403f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0456 | PC: 0x0630f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0456 | Địa chỉ PC: 0x0630f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0630f8: D10283FF  sub      sp, sp, #0xa0
//   0x0630fc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x063100: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x063104: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0456_0x0630f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0630f8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0457 | PC: 0x06364c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0457 | Địa chỉ PC: 0x06364c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06364c: D10583FF  sub      sp, sp, #0x160
//   0x063650: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x063654: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x063658: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_0457_0x06364c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06364cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0458 | PC: 0x063dfc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0458 | Địa chỉ PC: 0x063dfc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x063dfc: D10303FF  sub      sp, sp, #0xc0
//   0x063e00: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x063e04: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x063e08: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0458_0x063dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063dfcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0459 | PC: 0x064238 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0459 | Địa chỉ PC: 0x064238 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x064238: D10303FF  sub      sp, sp, #0xc0
//   0x06423c: F90043F7  str      x23, [sp, #0x80]
//   0x064240: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x064244: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0459_0x064238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064238ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0460 | PC: 0x064668 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0460 | Địa chỉ PC: 0x064668 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x064668: D10103FF  sub      sp, sp, #0x40
//   0x06466c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x064670: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x064674: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0460_0x064668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064668ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0461 | PC: 0x06470c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0461 | Địa chỉ PC: 0x06470c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06470c: D10203FF  sub      sp, sp, #0x80
//   0x064710: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x064714: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x064718: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0461_0x06470c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06470cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0462 | PC: 0x064948 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0462 | Địa chỉ PC: 0x064948 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x064948: D101C3FF  sub      sp, sp, #0x70
//   0x06494c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x064950: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x064954: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0462_0x064948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064948ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0463 | PC: 0x064a78 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0463 | Địa chỉ PC: 0x064a78 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x064a78: D10543FF  sub      sp, sp, #0x150
//   0x064a7c: A9115FFC  stp      x28, x23, [sp, #0x110]
//   0x064a80: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x064a84: A9134FF4  stp      x20, x19, [sp, #0x130]
static inline uint64_t fde_func_0463_0x064a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064a78ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9115ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0464 | PC: 0x064c40 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0464 | Địa chỉ PC: 0x064c40 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x064c40: D10183FF  sub      sp, sp, #0x60
//   0x064c44: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x064c48: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x064c4c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0464_0x064c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064c40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0465 | PC: 0x064e20 | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0465 | Địa chỉ PC: 0x064e20 | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x064e20: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x064e24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x064e28: 910043FD  add      x29, sp, #0x10
//   0x064e2c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0465_0x064e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064e20ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0466 | PC: 0x064f14 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0466 | Địa chỉ PC: 0x064f14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x064f14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x064f18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x064f1c: 910043FD  add      x29, sp, #0x10
//   0x064f20: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0466_0x064f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064f14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0467 | PC: 0x065088 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0467 | Địa chỉ PC: 0x065088 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x065088: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06508c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065090: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x065094: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0467_0x065088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065088ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0468 | PC: 0x06552c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0468 | Địa chỉ PC: 0x06552c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06552c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x065530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065534: 910043FD  add      x29, sp, #0x10
//   0x065538: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0468_0x06552c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06552cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0469 | PC: 0x0657cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0469 | Địa chỉ PC: 0x0657cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0657cc: D10103FF  sub      sp, sp, #0x40
//   0x0657d0: F9000BF5  str      x21, [sp, #0x10]
//   0x0657d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0657d8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0469_0x0657cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0657ccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0470 | PC: 0x0659fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0470 | Địa chỉ PC: 0x0659fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0659fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x065a00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065a04: 910043FD  add      x29, sp, #0x10
//   0x065a08: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_0470_0x0659fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0659fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0471 | PC: 0x065b00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0471 | Địa chỉ PC: 0x065b00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x065b00: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x065b04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x065b08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x065b0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0471_0x065b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065b00ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0472 | PC: 0x065c14 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0472 | Địa chỉ PC: 0x065c14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x065c14: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x065c18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065c1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x065c20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0472_0x065c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065c14ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0473 | PC: 0x065ec8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0473 | Địa chỉ PC: 0x065ec8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x065ec8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x065ecc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065ed0: 910043FD  add      x29, sp, #0x10
//   0x065ed4: D00007A9  adrp     x9, #0x15b000
static inline uint64_t fde_func_0473_0x065ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065ec8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0474 | PC: 0x06609c | FDE: 0x148a38 | Size: 60 bytes
// Hàm #0474 | Địa chỉ PC: 0x06609c | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x06609c: D100C3FF  sub      sp, sp, #0x30
//   0x0660a0: F9000BF3  str      x19, [sp, #0x10]
//   0x0660a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0660a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0474_0x06609c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06609cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #0475 | PC: 0x0660d8 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio18MDLVcnDownloaderV26DeleteEPNS1_16MIOVodNetAdapterE]
// Hàm #0475 | Địa chỉ PC: 0x0660d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0660d8: B4000080  cbz      x0, #0x660e8
//   0x0660dc: F9400008  ldr      x8, [x0]
//   0x0660e0: F9400501  ldr      x1, [x8, #8]
//   0x0660e4: D61F0020  br       x1
static inline uint64_t fde_func_0475_0x0660d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0660d8ULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #0476 | PC: 0x0660ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0476 | Địa chỉ PC: 0x0660ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0660ec: D10143FF  sub      sp, sp, #0x50
//   0x0660f0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0660f4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0660f8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0476_0x0660ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0660ecULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0477 | PC: 0x066238 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0477 | Địa chỉ PC: 0x066238 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x066238: D10183FF  sub      sp, sp, #0x60
//   0x06623c: F90023F3  str      x19, [sp, #0x40]
//   0x066240: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x066244: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0477_0x066238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066238ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0478 | PC: 0x066318 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0478 | Địa chỉ PC: 0x066318 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x066318: D10103FF  sub      sp, sp, #0x40
//   0x06631c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x066320: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x066324: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0478_0x066318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066318ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0479 | PC: 0x066484 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0479 | Địa chỉ PC: 0x066484 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x066484: D101C3FF  sub      sp, sp, #0x70
//   0x066488: F9001BF7  str      x23, [sp, #0x30]
//   0x06648c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x066490: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0479_0x066484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066484ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0480 | PC: 0x066798 | FDE: 0x148a38 | Size: 208 bytes
// Hàm #0480 | Địa chỉ PC: 0x066798 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x066798: D10183FF  sub      sp, sp, #0x60
//   0x06679c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0667a0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0667a4: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0480_0x066798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066798ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0481 | PC: 0x066868 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0481 | Địa chỉ PC: 0x066868 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x066868: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06686c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x066870: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x066874: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0481_0x066868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066868ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0482 | PC: 0x066884 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0482 | Địa chỉ PC: 0x066884 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x066884: D114C3FF  sub      sp, sp, #0x530
//   0x066888: D53BD05A  mrs      x26, tpidr_el0
//   0x06688c: F9401749  ldr      x9, [x26, #0x28]
//   0x066890: 1284E268  mov      w8, #-0x2714
static inline uint64_t fde_func_0482_0x066884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066884ULL ^ (static_cast<uint64_t>(0xd114c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0483 | PC: 0x067154 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0483 | Địa chỉ PC: 0x067154 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x067154: D10403FF  sub      sp, sp, #0x100
//   0x067158: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x06715c: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x067160: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0483_0x067154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067154ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0484 | PC: 0x067814 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0484 | Địa chỉ PC: 0x067814 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x067814: D10543FF  sub      sp, sp, #0x150
//   0x067818: A9115FFC  stp      x28, x23, [sp, #0x110]
//   0x06781c: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x067820: A9134FF4  stp      x20, x19, [sp, #0x130]
static inline uint64_t fde_func_0484_0x067814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067814ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9115ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0485 | PC: 0x0679dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0485 | Địa chỉ PC: 0x0679dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0679dc: D10183FF  sub      sp, sp, #0x60
//   0x0679e0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0679e4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0679e8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0485_0x0679dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0679dcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0486 | PC: 0x067b30 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0486 | Địa chỉ PC: 0x067b30 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x067b30: D10583FF  sub      sp, sp, #0x160
//   0x067b34: A9125FFC  stp      x28, x23, [sp, #0x120]
//   0x067b38: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x067b3c: A9144FF4  stp      x20, x19, [sp, #0x140]
static inline uint64_t fde_func_0486_0x067b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067b30ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9125ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0487 | PC: 0x0683f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0487 | Địa chỉ PC: 0x0683f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0683f4: D10503FF  sub      sp, sp, #0x140
//   0x0683f8: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0683fc: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x068400: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_0487_0x0683f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0683f4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0488 | PC: 0x068b9c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0488 | Địa chỉ PC: 0x068b9c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x068b9c: D10503FF  sub      sp, sp, #0x140
//   0x068ba0: A90F67FC  stp      x28, x25, [sp, #0xf0]
//   0x068ba4: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x068ba8: A91157F6  stp      x22, x21, [sp, #0x110]
static inline uint64_t fde_func_0488_0x068b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068b9cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90f67fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0489 | PC: 0x069488 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0489 | Địa chỉ PC: 0x069488 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x069488: D104C3FF  sub      sp, sp, #0x130
//   0x06948c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x069490: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x069494: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0489_0x069488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069488ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0490 | PC: 0x069cd0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0490 | Địa chỉ PC: 0x069cd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x069cd0: D102C3FF  sub      sp, sp, #0xb0
//   0x069cd4: F9003BF7  str      x23, [sp, #0x70]
//   0x069cd8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x069cdc: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0490_0x069cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069cd0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0491 | PC: 0x069fe8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0491 | Địa chỉ PC: 0x069fe8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x069fe8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x069fec: 910003FD  mov      x29, sp
//   0x069ff0: D1004000  sub      x0, x0, #0x10
//   0x069ff4: 97FFF900  bl       #0x683f4
static inline uint64_t fde_func_0491_0x069fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069fe8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0492 | PC: 0x06a004 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0492 | Địa chỉ PC: 0x06a004 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06a004: D10403FF  sub      sp, sp, #0x100
//   0x06a008: F9005BF9  str      x25, [sp, #0xb0]
//   0x06a00c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x06a010: A90D57F6  stp      x22, x21, [sp, #0xd0]
static inline uint64_t fde_func_0492_0x06a004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a004ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0493 | PC: 0x06a444 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0493 | Địa chỉ PC: 0x06a444 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06a444: D10203FF  sub      sp, sp, #0x80
//   0x06a448: F9002BF5  str      x21, [sp, #0x50]
//   0x06a44c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x06a450: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0493_0x06a444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a444ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0494 | PC: 0x06a738 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapterC2Em]
// Hàm #0494 | Địa chỉ PC: 0x06a738 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x06a738: B0000788  adrp     x8, #0x15b000
//   0x06a73c: F9455D08  ldr      x8, [x8, #0xab8]
//   0x06a740: 91004108  add      x8, x8, #0x10
//   0x06a744: A9000408  stp      x8, x1, [x0]
static inline uint64_t fde_func_0494_0x06a738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a738ULL ^ (static_cast<uint64_t>(0xb0000788ULL) << 13);
    acc = (acc + a1 + 0xf9455d08ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #0495 | PC: 0x06a74c | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapterD2Ev]
// Hàm #0495 | Địa chỉ PC: 0x06a74c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x06a74c: D65F03C0  ret      
static inline uint64_t fde_func_0495_0x06a74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a74cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd4200020ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0496 | PC: 0x06a750 | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapterD0Ev]
// Hàm #0496 | Địa chỉ PC: 0x06a750 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x06a750: D4200020  brk      #1
static inline uint64_t fde_func_0496_0x06a750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a750ULL ^ (static_cast<uint64_t>(0xd4200020ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0497 | PC: 0x06a754 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapter5writeEPhi]
// Hàm #0497 | Địa chỉ PC: 0x06a754 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x06a754: 2A1F03E0  mov      w0, wzr
//   0x06a758: D65F03C0  ret      
static inline uint64_t fde_func_0497_0x06a754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a754ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0498 | PC: 0x06a75c | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapter15isDataAvailableEv]
// Hàm #0498 | Địa chỉ PC: 0x06a75c | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x06a75c: 2A1F03E0  mov      w0, wzr
//   0x06a760: D65F03C0  ret      
static inline uint64_t fde_func_0498_0x06a75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a75cULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0499 | PC: 0x06a764 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapter4readEPhil]
// Hàm #0499 | Địa chỉ PC: 0x06a764 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x06a764: 2A1F03E0  mov      w0, wzr
//   0x06a768: D65F03C0  ret      
static inline uint64_t fde_func_0499_0x06a764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a764ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0500 | PC: 0x06a76c | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapter11setListenerENSt6__ndk18weak_ptrINS1_13MIOIoListenerEEE]
// Hàm #0500 | Địa chỉ PC: 0x06a76c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x06a76c: D65F03C0  ret      
static inline uint64_t fde_func_0500_0x06a76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a76cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0501 | PC: 0x06a770 | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio16MIOVodNetAdapter9setWorkerENSt6__ndk110shared_ptrINS1_30MIOEventWorkerWrapperInterfaceEEE]
// Hàm #0501 | Địa chỉ PC: 0x06a770 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x06a770: D65F03C0  ret      
static inline uint64_t fde_func_0501_0x06a770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a770ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0502 | PC: 0x06a774 | FDE: 0x148a38 | Size: 80 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenterC1ERNS1_29MDLSocketTrainingCenterConfigE]
// Hàm #0502 | Địa chỉ PC: 0x06a774 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x06a774: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06a778: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a77c: 910043FD  add      x29, sp, #0x10
//   0x06a780: D28000A8  mov      x8, #5
static inline uint64_t fde_func_0502_0x06a774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a774ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0503 | PC: 0x06a7c4 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter21resetInProgressConfigEv]
// Hàm #0503 | Địa chỉ PC: 0x06a7c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x06a7c4: F900081F  str      xzr, [x0, #0x10]
//   0x06a7c8: D65F03C0  ret      
static inline uint64_t fde_func_0503_0x06a7c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a7c4ULL ^ (static_cast<uint64_t>(0xf900081fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0504 | PC: 0x06a7cc | FDE: 0x148a38 | Size: 80 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenterC2Ev]
// Hàm #0504 | Địa chỉ PC: 0x06a7cc | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x06a7cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06a7d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a7d4: 910043FD  add      x29, sp, #0x10
//   0x06a7d8: D28000A8  mov      x8, #5
static inline uint64_t fde_func_0504_0x06a7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a7ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0505 | PC: 0x06a81c | FDE: 0x148a38 | Size: 40 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenterD2Ev]
// Hàm #0505 | Địa chỉ PC: 0x06a81c | Địa chỉ FDE: 0x148a38 | Kích thước: 40 bytes
//   0x06a81c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06a820: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a824: 910043FD  add      x29, sp, #0x10
//   0x06a828: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0505_0x06a81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a81cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// Func #0506 | PC: 0x06a844 | FDE: 0x148a38 | Size: 16 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter14onTrainingDataENS1_16TrainingDataTypeEi]
// Hàm #0506 | Địa chỉ PC: 0x06a844 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x06a844: B9404808  ldr      w8, [x0, #0x48]
//   0x06a848: 34000048  cbz      w8, #0x6a850
//   0x06a84c: 17FF220D  b        #0x33080
//   0x06a850: D65F03C0  ret      
static inline uint64_t fde_func_0506_0x06a844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a844ULL ^ (static_cast<uint64_t>(0xb9404808ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #0507 | PC: 0x06a854 | FDE: 0x148a38 | Size: 196 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter13trainingByMaxENS1_16TrainingDataTypeEi]
// Hàm #0507 | Địa chỉ PC: 0x06a854 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x06a854: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06a858: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06a85c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06a860: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0507_0x06a854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a854ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0508 | PC: 0x06a918 | FDE: 0x148a38 | Size: 72 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter17calibrateConfigerERNS2_14SocketTrainSetE]
// Hàm #0508 | Địa chỉ PC: 0x06a918 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x06a918: B9401808  ldr      w8, [x0, #0x18]
//   0x06a91c: 29402829  ldp      w9, w10, [x1]
//   0x06a920: 6B08013F  cmp      w9, w8
//   0x06a924: 1A89B108  csel     w8, w8, w9, lt
static inline uint64_t fde_func_0508_0x06a918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a918ULL ^ (static_cast<uint64_t>(0xb9401808ULL) << 13);
    acc = (acc + a1 + 0x29402829ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #0509 | PC: 0x06a960 | FDE: 0x148a38 | Size: 184 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter18getRecommendConfigERNS2_14SocketTrainSetE]
// Hàm #0509 | Địa chỉ PC: 0x06a960 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x06a960: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06a964: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06a968: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06a96c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0509_0x06a960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a960ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0510 | PC: 0x06aa18 | FDE: 0x148a38 | Size: 172 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter5startEv]
// Hàm #0510 | Địa chỉ PC: 0x06aa18 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x06aa18: D10103FF  sub      sp, sp, #0x40
//   0x06aa1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06aa20: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x06aa24: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0510_0x06aa18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06aa18ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0511 | PC: 0x06aac4 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio23MDLSocketTrainingCenter23getSocketTrainingConfigEv]
// Hàm #0511 | Địa chỉ PC: 0x06aac4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x06aac4: 91006000  add      x0, x0, #0x18
//   0x06aac8: D65F03C0  ret      
static inline uint64_t fde_func_0511_0x06aac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06aac4ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #0512 | PC: 0x06aacc | FDE: 0x148a38 | Size: 92 bytes [_ZNK3com2ss5ttmio23MDLSocketTrainingCenter9isEnabledEv]
// Hàm #0512 | Địa chỉ PC: 0x06aacc | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x06aacc: B9404808  ldr      w8, [x0, #0x48]
//   0x06aad0: 7100011F  cmp      w8, #0
//   0x06aad4: 1A9F07E0  cset     w0, ne
//   0x06aad8: D65F03C0  ret      
static inline uint64_t fde_func_0512_0x06aacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06aaccULL ^ (static_cast<uint64_t>(0xb9404808ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0513 | PC: 0x06ab28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0513 | Địa chỉ PC: 0x06ab28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06ab28: D10483FF  sub      sp, sp, #0x120
//   0x06ab2c: F9007BFC  str      x28, [sp, #0xf0]
//   0x06ab30: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x06ab34: A9117BFD  stp      x29, x30, [sp, #0x110]
static inline uint64_t fde_func_0513_0x06ab28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab28ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0514 | PC: 0x06ae1c | FDE: 0x148a38 | Size: 20 bytes
// Hàm #0514 | Địa chỉ PC: 0x06ae1c | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x06ae1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06ae20: 910003FD  mov      x29, sp
//   0x06ae24: 97FF1EBF  bl       #0x32920
//   0x06ae28: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0514_0x06ae1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ae1cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #0515 | PC: 0x06ae30 | FDE: 0x148a38 | Size: 220 bytes [_ZN3com2ss5ttmio21MDLDNSParserImplementC2EPNS1_20MDLDNSParserCallbackE]
// Hàm #0515 | Địa chỉ PC: 0x06ae30 | Địa chỉ FDE: 0x148a38 | Kích thước: 220 bytes
//   0x06ae30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ae34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ae38: 910043FD  add      x29, sp, #0x10
//   0x06ae3c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0515_0x06ae30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ae30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// Func #0516 | PC: 0x06af0c | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0516 | Địa chỉ PC: 0x06af0c | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x06af0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06af10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06af14: 910043FD  add      x29, sp, #0x10
//   0x06af18: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0516_0x06af0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06af0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0517 | PC: 0x06afe0 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #0517 | Địa chỉ PC: 0x06afe0 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x06afe0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06afe4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06afe8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06afec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0517_0x06afe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06afe0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0518 | PC: 0x06b060 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0518 | Địa chỉ PC: 0x06b060 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06b060: D10183FF  sub      sp, sp, #0x60
//   0x06b064: F9001BF5  str      x21, [sp, #0x30]
//   0x06b068: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x06b06c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0518_0x06b060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b060ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0519 | PC: 0x06b234 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0519 | Địa chỉ PC: 0x06b234 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06b234: D102C3FF  sub      sp, sp, #0xb0
//   0x06b238: F9002BFB  str      x27, [sp, #0x50]
//   0x06b23c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x06b240: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0519_0x06b234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b234ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0520 | PC: 0x06b714 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0520 | Địa chỉ PC: 0x06b714 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06b714: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06b718: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06b71c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06b720: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0520_0x06b714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b714ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0521 | PC: 0x06b8d4 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MIODNSParserManager11getInstanceEv]
// Hàm #0521 | Địa chỉ PC: 0x06b8d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06b8d4: D10103FF  sub      sp, sp, #0x40
//   0x06b8d8: F9000BF5  str      x21, [sp, #0x10]
//   0x06b8dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06b8e0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0521_0x06b8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b8d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0522 | PC: 0x06ba64 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MIODNSParserManagerC1Ev]
// Hàm #0522 | Địa chỉ PC: 0x06ba64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06ba64: D10143FF  sub      sp, sp, #0x50
//   0x06ba68: F90013F5  str      x21, [sp, #0x20]
//   0x06ba6c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06ba70: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0522_0x06ba64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ba64ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0523 | PC: 0x06bc0c | FDE: 0x148a38 | Size: 168 bytes
// Hàm #0523 | Địa chỉ PC: 0x06bc0c | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x06bc0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06bc10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06bc14: 910043FD  add      x29, sp, #0x10
//   0x06bc18: 91024014  add      x20, x0, #0x90
static inline uint64_t fde_func_0523_0x06bc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bc0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0524 | PC: 0x06bcb4 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0524 | Địa chỉ PC: 0x06bcb4 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x06bcb4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06bcb8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06bcbc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06bcc0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0524_0x06bcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bcb4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0525 | PC: 0x06bcd0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0525 | Địa chỉ PC: 0x06bcd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06bcd0: D10743FF  sub      sp, sp, #0x1d0
//   0x06bcd4: D53BD05B  mrs      x27, tpidr_el0
//   0x06bcd8: F9401768  ldr      x8, [x27, #0x28]
//   0x06bcdc: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_0525_0x06bcd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bcd0ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05bULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0526 | PC: 0x06c1f0 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0526 | Địa chỉ PC: 0x06c1f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x06c1f0: D10203FF  sub      sp, sp, #0x80
//   0x06c1f4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x06c1f8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x06c1fc: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0526_0x06c1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c1f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0527 | PC: 0x06c2d0 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0527 | Địa chỉ PC: 0x06c2d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x06c2d0: D10143FF  sub      sp, sp, #0x50
//   0x06c2d4: F90013F5  str      x21, [sp, #0x20]
//   0x06c2d8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06c2dc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0527_0x06c2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c2d0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0528 | PC: 0x06c390 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0528 | Địa chỉ PC: 0x06c390 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06c390: D10643FF  sub      sp, sp, #0x190
//   0x06c394: F900ABFC  str      x28, [sp, #0x150]
//   0x06c398: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x06c39c: A9174FF4  stp      x20, x19, [sp, #0x170]
static inline uint64_t fde_func_0528_0x06c390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c390ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0529 | PC: 0x06c748 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0529 | Địa chỉ PC: 0x06c748 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x06c748: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06c74c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c750: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c754: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0529_0x06c748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c748ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0530 | PC: 0x06c7d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0530 | Địa chỉ PC: 0x06c7d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06c7d0: D100C3FF  sub      sp, sp, #0x30
//   0x06c7d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c7d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c7dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0530_0x06c7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c7d0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0531 | PC: 0x06c9d4 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0531 | Địa chỉ PC: 0x06c9d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x06c9d4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06c9d8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06c9dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06c9e0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0531_0x06c9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c9d4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0532 | PC: 0x06c9f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0532 | Địa chỉ PC: 0x06c9f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06c9f0: D10903FF  sub      sp, sp, #0x240
//   0x06c9f4: D53BD053  mrs      x19, tpidr_el0
//   0x06c9f8: F9401668  ldr      x8, [x19, #0x28]
//   0x06c9fc: AA0403F9  mov      x25, x4
static inline uint64_t fde_func_0532_0x06c9f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c9f0ULL ^ (static_cast<uint64_t>(0xd10903ffULL) << 13);
    acc = (acc + a1 + 0xd53bd053ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0533 | PC: 0x06d30c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0533 | Địa chỉ PC: 0x06d30c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06d30c: D10743FF  sub      sp, sp, #0x1d0
//   0x06d310: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x06d314: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x06d318: A9195FF8  stp      x24, x23, [sp, #0x190]
static inline uint64_t fde_func_0533_0x06d30c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d30cULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa9176ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0534 | PC: 0x06d804 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0534 | Địa chỉ PC: 0x06d804 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06d804: D10643FF  sub      sp, sp, #0x190
//   0x06d808: F900ABFC  str      x28, [sp, #0x150]
//   0x06d80c: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x06d810: A9174FF4  stp      x20, x19, [sp, #0x170]
static inline uint64_t fde_func_0534_0x06d804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d804ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0535 | PC: 0x06db38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0535 | Địa chỉ PC: 0x06db38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06db38: D10643FF  sub      sp, sp, #0x190
//   0x06db3c: F900ABFC  str      x28, [sp, #0x150]
//   0x06db40: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x06db44: A9174FF4  stp      x20, x19, [sp, #0x170]
static inline uint64_t fde_func_0535_0x06db38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06db38ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0536 | PC: 0x06de70 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0536 | Địa chỉ PC: 0x06de70 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06de70: D10183FF  sub      sp, sp, #0x60
//   0x06de74: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06de78: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06de7c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0536_0x06de70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06de70ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0537 | PC: 0x06df70 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0537 | Địa chỉ PC: 0x06df70 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06df70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06df74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06df78: 910043FD  add      x29, sp, #0x10
//   0x06df7c: B4000141  cbz      x1, #0x6dfa4
static inline uint64_t fde_func_0537_0x06df70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06df70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0538 | PC: 0x06e330 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0538 | Địa chỉ PC: 0x06e330 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06e330: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e334: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e338: 910043FD  add      x29, sp, #0x10
//   0x06e33c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0538_0x06e330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e330ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0539 | PC: 0x06e4a0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0539 | Địa chỉ PC: 0x06e4a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06e4a0: D10103FF  sub      sp, sp, #0x40
//   0x06e4a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06e4a8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x06e4ac: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0539_0x06e4a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e4a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0540 | PC: 0x06e744 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #0540 | Địa chỉ PC: 0x06e744 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x06e744: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e748: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e74c: 910043FD  add      x29, sp, #0x10
//   0x06e750: B4000161  cbz      x1, #0x6e77c
static inline uint64_t fde_func_0540_0x06e744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e744ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0541 | PC: 0x06e7c4 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #0541 | Địa chỉ PC: 0x06e7c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x06e7c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e7c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e7cc: 910043FD  add      x29, sp, #0x10
//   0x06e7d0: B40001E1  cbz      x1, #0x6e80c
static inline uint64_t fde_func_0541_0x06e7c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e7c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #0542 | PC: 0x06e854 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0542 | Địa chỉ PC: 0x06e854 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06e854: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e858: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e85c: 910043FD  add      x29, sp, #0x10
//   0x06e860: B4000161  cbz      x1, #0x6e88c
static inline uint64_t fde_func_0542_0x06e854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e854ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0543 | PC: 0x06e980 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0543 | Địa chỉ PC: 0x06e980 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x06e980: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06e984: 910003FD  mov      x29, sp
//   0x06e988: 97FF1592  bl       #0x33fd0
//   0x06e98c: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_0543_0x06e980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e980ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0544 | PC: 0x06ea60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0544 | Địa chỉ PC: 0x06ea60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06ea60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ea64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ea68: 910043FD  add      x29, sp, #0x10
//   0x06ea6c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0544_0x06ea60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ea60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0545 | PC: 0x06ed50 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0545 | Địa chỉ PC: 0x06ed50 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x06ed50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ed54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ed58: 910043FD  add      x29, sp, #0x10
//   0x06ed5c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0545_0x06ed50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ed50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0546 | PC: 0x06eda0 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0546 | Địa chỉ PC: 0x06eda0 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x06eda0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06eda4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06eda8: 910043FD  add      x29, sp, #0x10
//   0x06edac: 90000728  adrp     x8, #0x152000
static inline uint64_t fde_func_0546_0x06eda0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eda0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0547 | PC: 0x06ee2c | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0547 | Địa chỉ PC: 0x06ee2c | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x06ee2c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06ee30: 910003FD  mov      x29, sp
//   0x06ee34: AA0003E8  mov      x8, x0
//   0x06ee38: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_0547_0x06ee2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ee2cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0548 | PC: 0x06eea0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0548 | Địa chỉ PC: 0x06eea0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06eea0: D10203FF  sub      sp, sp, #0x80
//   0x06eea4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x06eea8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06eeac: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0548_0x06eea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eea0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0549 | PC: 0x06f718 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0549 | Địa chỉ PC: 0x06f718 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06f718: D101C3FF  sub      sp, sp, #0x70
//   0x06f71c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x06f720: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06f724: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0549_0x06f718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f718ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0550 | PC: 0x06f9a0 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0550 | Địa chỉ PC: 0x06f9a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x06f9a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06f9a4: 910003FD  mov      x29, sp
//   0x06f9a8: F9400400  ldr      x0, [x0, #8]
//   0x06f9ac: B9402808  ldr      w8, [x0, #0x28]
static inline uint64_t fde_func_0550_0x06f9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f9a0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0551 | PC: 0x06fa04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0551 | Địa chỉ PC: 0x06fa04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06fa04: D10183FF  sub      sp, sp, #0x60
//   0x06fa08: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06fa0c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06fa10: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0551_0x06fa04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fa04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0552 | PC: 0x06fca8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0552 | Địa chỉ PC: 0x06fca8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06fca8: D101C3FF  sub      sp, sp, #0x70
//   0x06fcac: F90013F9  str      x25, [sp, #0x20]
//   0x06fcb0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06fcb4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0552_0x06fca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fca8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0553 | PC: 0x06fec8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0553 | Địa chỉ PC: 0x06fec8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x06fec8: D10203FF  sub      sp, sp, #0x80
//   0x06fecc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x06fed0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06fed4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0553_0x06fec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fec8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0554 | PC: 0x070298 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0554 | Địa chỉ PC: 0x070298 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x070298: D10203FF  sub      sp, sp, #0x80
//   0x07029c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0702a0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0702a4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0554_0x070298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070298ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0555 | PC: 0x0704ec | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0555 | Địa chỉ PC: 0x0704ec | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0704ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0704f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0704f4: 910043FD  add      x29, sp, #0x10
//   0x0704f8: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0555_0x0704ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0704ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0556 | PC: 0x07054c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0556 | Địa chỉ PC: 0x07054c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07054c: D101C3FF  sub      sp, sp, #0x70
//   0x070550: F90013F9  str      x25, [sp, #0x20]
//   0x070554: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x070558: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0556_0x07054c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07054cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0557 | PC: 0x070854 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0557 | Địa chỉ PC: 0x070854 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x070854: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x070858: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07085c: 910043FD  add      x29, sp, #0x10
//   0x070860: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0557_0x070854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070854ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0558 | PC: 0x070a90 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0558 | Địa chỉ PC: 0x070a90 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x070a90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x070a94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070a98: 910043FD  add      x29, sp, #0x10
//   0x070a9c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0558_0x070a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070a90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0559 | PC: 0x070b1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0559 | Địa chỉ PC: 0x070b1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x070b1c: D10183FF  sub      sp, sp, #0x60
//   0x070b20: F90013F7  str      x23, [sp, #0x20]
//   0x070b24: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x070b28: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0559_0x070b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070b1cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0560 | PC: 0x070c44 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0560 | Địa chỉ PC: 0x070c44 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x070c44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x070c48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070c4c: 910043FD  add      x29, sp, #0x10
//   0x070c50: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0560_0x070c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070c44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0561 | PC: 0x070dc8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0561 | Địa chỉ PC: 0x070dc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x070dc8: D10103FF  sub      sp, sp, #0x40
//   0x070dcc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x070dd0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x070dd4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0561_0x070dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070dc8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0562 | PC: 0x070fcc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0562 | Địa chỉ PC: 0x070fcc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x070fcc: D10103FF  sub      sp, sp, #0x40
//   0x070fd0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x070fd4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x070fd8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0562_0x070fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070fccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0563 | PC: 0x071248 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0563 | Địa chỉ PC: 0x071248 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x071248: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07124c: 910003FD  mov      x29, sp
//   0x071250: F9400408  ldr      x8, [x0, #8]
//   0x071254: B9402908  ldr      w8, [x8, #0x28]
static inline uint64_t fde_func_0563_0x071248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071248ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0564 | PC: 0x071304 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0564 | Địa chỉ PC: 0x071304 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x071304: D10183FF  sub      sp, sp, #0x60
//   0x071308: F90013F7  str      x23, [sp, #0x20]
//   0x07130c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x071310: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0564_0x071304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071304ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0565 | PC: 0x071584 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0565 | Địa chỉ PC: 0x071584 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x071584: D10103FF  sub      sp, sp, #0x40
//   0x071588: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07158c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x071590: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0565_0x071584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071584ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0566 | PC: 0x07175c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0566 | Địa chỉ PC: 0x07175c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07175c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071760: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071764: 910043FD  add      x29, sp, #0x10
//   0x071768: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0566_0x07175c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07175cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0567 | PC: 0x071880 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0567 | Địa chỉ PC: 0x071880 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x071880: D10103FF  sub      sp, sp, #0x40
//   0x071884: F9000BF5  str      x21, [sp, #0x10]
//   0x071888: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07188c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0567_0x071880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071880ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0568 | PC: 0x0719b0 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0568 | Địa chỉ PC: 0x0719b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0719b0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0719b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0719b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0719bc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0568_0x0719b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0719b0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0569 | PC: 0x071a50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0569 | Địa chỉ PC: 0x071a50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x071a50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071a54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071a58: 910043FD  add      x29, sp, #0x10
//   0x071a5c: D0000748  adrp     x8, #0x15b000
static inline uint64_t fde_func_0569_0x071a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071a50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0570 | PC: 0x071f08 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0570 | Địa chỉ PC: 0x071f08 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x071f08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071f0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071f10: 910043FD  add      x29, sp, #0x10
//   0x071f14: F940D808  ldr      x8, [x0, #0x1b0]
static inline uint64_t fde_func_0570_0x071f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071f08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0571 | PC: 0x071f6c | FDE: 0x148a38 | Size: 176 bytes
// Hàm #0571 | Địa chỉ PC: 0x071f6c | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x071f6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071f70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071f74: 910043FD  add      x29, sp, #0x10
//   0x071f78: F9406808  ldr      x8, [x0, #0xd0]
static inline uint64_t fde_func_0571_0x071f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071f6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #0572 | PC: 0x07201c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0572 | Địa chỉ PC: 0x07201c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07201c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x072020: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x072024: 910043FD  add      x29, sp, #0x10
//   0x072028: F9400828  ldr      x8, [x1, #0x10]
static inline uint64_t fde_func_0572_0x07201c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07201cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0573 | PC: 0x072194 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0573 | Địa chỉ PC: 0x072194 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x072194: D10403FF  sub      sp, sp, #0x100
//   0x072198: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x07219c: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x0721a0: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0573_0x072194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072194ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0574 | PC: 0x0722e0 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0574 | Địa chỉ PC: 0x0722e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0722e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0722e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0722e8: 910043FD  add      x29, sp, #0x10
//   0x0722ec: 9103C014  add      x20, x0, #0xf0
static inline uint64_t fde_func_0574_0x0722e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0722e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0575 | PC: 0x072340 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0575 | Địa chỉ PC: 0x072340 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x072340: D10603FF  sub      sp, sp, #0x180
//   0x072344: F9009BFC  str      x28, [sp, #0x130]
//   0x072348: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x07234c: A91557F6  stp      x22, x21, [sp, #0x150]
static inline uint64_t fde_func_0575_0x072340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072340ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0576 | PC: 0x0729d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0576 | Địa chỉ PC: 0x0729d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0729d0: D101C3FF  sub      sp, sp, #0x70
//   0x0729d4: F90023F5  str      x21, [sp, #0x40]
//   0x0729d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0729dc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0576_0x0729d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0729d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0577 | PC: 0x072b60 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0577 | Địa chỉ PC: 0x072b60 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x072b60: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x072b64: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x072b68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x072b6c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0577_0x072b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072b60ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0578 | PC: 0x072be8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0578 | Địa chỉ PC: 0x072be8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x072be8: D10203FF  sub      sp, sp, #0x80
//   0x072bec: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x072bf0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x072bf4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0578_0x072be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072be8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0579 | PC: 0x072e5c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0579 | Địa chỉ PC: 0x072e5c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x072e5c: D104C3FF  sub      sp, sp, #0x130
//   0x072e60: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x072e64: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x072e68: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0579_0x072e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072e5cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0580 | PC: 0x073190 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0580 | Địa chỉ PC: 0x073190 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x073190: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x073194: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x073198: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07319c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0580_0x073190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073190ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0581 | PC: 0x0731ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0581 | Địa chỉ PC: 0x0731ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0731ac: D11103FF  sub      sp, sp, #0x440
//   0x0731b0: D53BD05A  mrs      x26, tpidr_el0
//   0x0731b4: F9401748  ldr      x8, [x26, #0x28]
//   0x0731b8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0581_0x0731ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0731acULL ^ (static_cast<uint64_t>(0xd11103ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0582 | PC: 0x07342c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0582 | Địa chỉ PC: 0x07342c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07342c: D10183FF  sub      sp, sp, #0x60
//   0x073430: F90023F3  str      x19, [sp, #0x40]
//   0x073434: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x073438: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0582_0x07342c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07342cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0583 | PC: 0x073650 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0583 | Địa chỉ PC: 0x073650 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x073650: D102C3FF  sub      sp, sp, #0xb0
//   0x073654: F9003BF7  str      x23, [sp, #0x70]
//   0x073658: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x07365c: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0583_0x073650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073650ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0584 | PC: 0x073760 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0584 | Địa chỉ PC: 0x073760 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x073760: D10343FF  sub      sp, sp, #0xd0
//   0x073764: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x073768: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x07376c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0584_0x073760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073760ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0585 | PC: 0x073974 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0585 | Địa chỉ PC: 0x073974 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x073974: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x073978: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07397c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x073980: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0585_0x073974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073974ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0586 | PC: 0x073ae0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0586 | Địa chỉ PC: 0x073ae0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x073ae0: D10783FF  sub      sp, sp, #0x1e0
//   0x073ae4: 910103F6  add      x22, sp, #0x40
//   0x073ae8: AA0003F3  mov      x19, x0
//   0x073aec: 910422DA  add      x26, x22, #0x108
static inline uint64_t fde_func_0586_0x073ae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073ae0ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0x910103f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0587 | PC: 0x073db0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0587 | Địa chỉ PC: 0x073db0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x073db0: D10843FF  sub      sp, sp, #0x210
//   0x073db4: AA0003F3  mov      x19, x0
//   0x073db8: 97FEFADA  bl       #0x32920
//   0x073dbc: 97FEFAF1  bl       #0x32980
static inline uint64_t fde_func_0587_0x073db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073db0ULL ^ (static_cast<uint64_t>(0xd10843ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0588 | PC: 0x07413c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0588 | Địa chỉ PC: 0x07413c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x07413c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x074140: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x074144: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x074148: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0588_0x07413c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07413cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0589 | PC: 0x074158 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0589 | Địa chỉ PC: 0x074158 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x074158: D11283FF  sub      sp, sp, #0x4a0
//   0x07415c: D53BD053  mrs      x19, tpidr_el0
//   0x074160: F9401668  ldr      x8, [x19, #0x28]
//   0x074164: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_0589_0x074158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074158ULL ^ (static_cast<uint64_t>(0xd11283ffULL) << 13);
    acc = (acc + a1 + 0xd53bd053ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0590 | PC: 0x0746c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0590 | Địa chỉ PC: 0x0746c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0746c0: D101C3FF  sub      sp, sp, #0x70
//   0x0746c4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0746c8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0746cc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0590_0x0746c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0746c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0591 | PC: 0x074940 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0591 | Địa chỉ PC: 0x074940 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x074940: D101C3FF  sub      sp, sp, #0x70
//   0x074944: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x074948: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x07494c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0591_0x074940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074940ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0592 | PC: 0x074d3c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0592 | Địa chỉ PC: 0x074d3c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x074d3c: D10403FF  sub      sp, sp, #0x100
//   0x074d40: F90063F7  str      x23, [sp, #0xc0]
//   0x074d44: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x074d48: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_0592_0x074d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074d3cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90063f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0593 | PC: 0x074fa4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0593 | Địa chỉ PC: 0x074fa4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x074fa4: D107C3FF  sub      sp, sp, #0x1f0
//   0x074fa8: 6D1633ED  stp      d13, d12, [sp, #0x160]
//   0x074fac: 6D172BEB  stp      d11, d10, [sp, #0x170]
//   0x074fb0: 6D1823E9  stp      d9, d8, [sp, #0x180]
static inline uint64_t fde_func_0593_0x074fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074fa4ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0x6d1633edULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0594 | PC: 0x075b00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0594 | Địa chỉ PC: 0x075b00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x075b00: D104C3FF  sub      sp, sp, #0x130
//   0x075b04: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x075b08: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x075b0c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0594_0x075b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075b00ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0595 | PC: 0x075e7c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0595 | Địa chỉ PC: 0x075e7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x075e7c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x075e80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x075e84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x075e88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0595_0x075e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075e7cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0596 | PC: 0x076118 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0596 | Địa chỉ PC: 0x076118 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x076118: D10143FF  sub      sp, sp, #0x50
//   0x07611c: A901D7FF  stp      xzr, x21, [sp, #0x18]
//   0x076120: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x076124: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0596_0x076118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076118ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa901d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0597 | PC: 0x0761d8 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0597 | Địa chỉ PC: 0x0761d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x0761d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0761dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0761e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0761e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0597_0x0761d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0761d8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0598 | PC: 0x07623c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0598 | Địa chỉ PC: 0x07623c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07623c: D101C3FF  sub      sp, sp, #0x70
//   0x076240: F90013F9  str      x25, [sp, #0x20]
//   0x076244: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x076248: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0598_0x07623c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07623cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0599 | PC: 0x076470 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0599 | Địa chỉ PC: 0x076470 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x076470: D10203FF  sub      sp, sp, #0x80
//   0x076474: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x076478: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x07647c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0599_0x076470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076470ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0600 | PC: 0x0767dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0600 | Địa chỉ PC: 0x0767dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0767dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0767e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0767e4: 910043FD  add      x29, sp, #0x10
//   0x0767e8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0600_0x0767dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0767dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0601 | PC: 0x076a58 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0601 | Địa chỉ PC: 0x076a58 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x076a58: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x076a5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x076a60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x076a64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0601_0x076a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076a58ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0602 | PC: 0x076bac | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0602 | Địa chỉ PC: 0x076bac | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x076bac: D10143FF  sub      sp, sp, #0x50
//   0x076bb0: A901D7FF  stp      xzr, x21, [sp, #0x18]
//   0x076bb4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x076bb8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0602_0x076bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076bacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa901d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0603 | PC: 0x076c6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0603 | Địa chỉ PC: 0x076c6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x076c6c: D10143FF  sub      sp, sp, #0x50
//   0x076c70: F90013F5  str      x21, [sp, #0x20]
//   0x076c74: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x076c78: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0603_0x076c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076c6cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0604 | PC: 0x076d80 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0604 | Địa chỉ PC: 0x076d80 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x076d80: D10243FF  sub      sp, sp, #0x90
//   0x076d84: F90033F5  str      x21, [sp, #0x60]
//   0x076d88: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x076d8c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0604_0x076d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076d80ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0605 | PC: 0x076e60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0605 | Địa chỉ PC: 0x076e60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x076e60: D101C3FF  sub      sp, sp, #0x70
//   0x076e64: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x076e68: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x076e6c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0605_0x076e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076e60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0606 | PC: 0x076ff8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0606 | Địa chỉ PC: 0x076ff8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x076ff8: D10143FF  sub      sp, sp, #0x50
//   0x076ffc: F90013F5  str      x21, [sp, #0x20]
//   0x077000: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x077004: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0606_0x076ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076ff8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0607 | PC: 0x077144 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0607 | Địa chỉ PC: 0x077144 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x077144: D10403FF  sub      sp, sp, #0x100
//   0x077148: F90053FB  str      x27, [sp, #0xa0]
//   0x07714c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x077150: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0607_0x077144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077144ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90053fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0608 | PC: 0x077380 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0608 | Địa chỉ PC: 0x077380 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x077380: D10283FF  sub      sp, sp, #0xa0
//   0x077384: F9002BF9  str      x25, [sp, #0x50]
//   0x077388: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x07738c: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0608_0x077380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077380ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0609 | PC: 0x0776f8 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #0609 | Địa chỉ PC: 0x0776f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x0776f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0776fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077700: 910043FD  add      x29, sp, #0x10
//   0x077704: F9400020  ldr      x0, [x1]
static inline uint64_t fde_func_0609_0x0776f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0776f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0610 | PC: 0x0777a0 | FDE: 0x148a38 | Size: 252 bytes
// Hàm #0610 | Địa chỉ PC: 0x0777a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 252 bytes
//   0x0777a0: D10443FF  sub      sp, sp, #0x110
//   0x0777a4: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0777a8: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0777ac: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0610_0x0777a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0777a0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Func #0611 | PC: 0x07789c | FDE: 0x148a38 | Size: 248 bytes
// Hàm #0611 | Địa chỉ PC: 0x07789c | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x07789c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0778a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0778a4: 910043FD  add      x29, sp, #0x10
//   0x0778a8: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_0611_0x07789c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07789cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #0612 | PC: 0x077994 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0612 | Địa chỉ PC: 0x077994 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x077994: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x077998: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07799c: 910043FD  add      x29, sp, #0x10
//   0x0779a0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0612_0x077994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077994ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0613 | PC: 0x077aa4 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0613 | Địa chỉ PC: 0x077aa4 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x077aa4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x077aa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077aac: 910043FD  add      x29, sp, #0x10
//   0x077ab0: 91025014  add      x20, x0, #0x94
static inline uint64_t fde_func_0613_0x077aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077aa4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0614 | PC: 0x077b18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0614 | Địa chỉ PC: 0x077b18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x077b18: D11083FF  sub      sp, sp, #0x420
//   0x077b1c: D53BD055  mrs      x21, tpidr_el0
//   0x077b20: F94016A8  ldr      x8, [x21, #0x28]
//   0x077b24: F81C83A8  stur     x8, [x29, #-0x38]
static inline uint64_t fde_func_0614_0x077b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077b18ULL ^ (static_cast<uint64_t>(0xd11083ffULL) << 13);
    acc = (acc + a1 + 0xd53bd055ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0615 | PC: 0x077c90 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0615 | Địa chỉ PC: 0x077c90 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x077c90: D100C3FF  sub      sp, sp, #0x30
//   0x077c94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077c98: 910083FD  add      x29, sp, #0x20
//   0x077c9c: B0000728  adrp     x8, #0x15c000
static inline uint64_t fde_func_0615_0x077c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077c90ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0616 | PC: 0x077d5c | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0616 | Địa chỉ PC: 0x077d5c | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x077d5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x077d60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077d64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077d68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0616_0x077d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077d5cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0617 | PC: 0x077e50 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0617 | Địa chỉ PC: 0x077e50 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x077e50: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x077e54: 910003FD  mov      x29, sp
//   0x077e58: 52938848  mov      w8, #0x9c42
//   0x077e5c: 6B08003F  cmp      w1, w8
static inline uint64_t fde_func_0617_0x077e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077e50ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0618 | PC: 0x077eb0 | FDE: 0x148a38 | Size: 124 bytes [_ZN3com2ss5ttmio17MDLNetWorkManager21isSwitchToCellularNetERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE]
// Hàm #0618 | Địa chỉ PC: 0x077eb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x077eb0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x077eb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077eb8: 910043FD  add      x29, sp, #0x10
//   0x077ebc: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0618_0x077eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077eb0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0619 | PC: 0x077f2c | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0619 | Địa chỉ PC: 0x077f2c | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x077f2c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x077f30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077f34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077f38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0619_0x077f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077f2cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0620 | PC: 0x077fd8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0620 | Địa chỉ PC: 0x077fd8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x077fd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x077fdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x077fe0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x077fe4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0620_0x077fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077fd8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0621 | PC: 0x0780d8 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0621 | Địa chỉ PC: 0x0780d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0780d8: D100C3FF  sub      sp, sp, #0x30
//   0x0780dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0780e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0780e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0621_0x0780d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0780d8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0622 | PC: 0x078198 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0622 | Địa chỉ PC: 0x078198 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x078198: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07819c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0781a0: 910043FD  add      x29, sp, #0x10
//   0x0781a4: 91094014  add      x20, x0, #0x250
static inline uint64_t fde_func_0622_0x078198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078198ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0623 | PC: 0x0781d0 | FDE: 0x148a38 | Size: 236 bytes
// Hàm #0623 | Địa chỉ PC: 0x0781d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 236 bytes
//   0x0781d0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0781d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0781d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0781dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0623_0x0781d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0781d0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// Func #0624 | PC: 0x0782bc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0624 | Địa chỉ PC: 0x0782bc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0782bc: D10403FF  sub      sp, sp, #0x100
//   0x0782c0: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x0782c4: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x0782c8: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0624_0x0782bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0782bcULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0625 | PC: 0x07843c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0625 | Địa chỉ PC: 0x07843c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07843c: D10403FF  sub      sp, sp, #0x100
//   0x078440: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x078444: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x078448: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0625_0x07843c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07843cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0626 | PC: 0x0786b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0626 | Địa chỉ PC: 0x0786b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0786b0: D10383FF  sub      sp, sp, #0xe0
//   0x0786b4: F90053F7  str      x23, [sp, #0xa0]
//   0x0786b8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0786bc: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0626_0x0786b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0786b0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0627 | PC: 0x078824 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0627 | Địa chỉ PC: 0x078824 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x078824: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x078828: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07882c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x078830: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0627_0x078824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078824ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0628 | PC: 0x078840 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0628 | Địa chỉ PC: 0x078840 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x078840: D11443FF  sub      sp, sp, #0x510
//   0x078844: D53BD048  mrs      x8, tpidr_el0
//   0x078848: F90007E8  str      x8, [sp, #8]
//   0x07884c: F9401508  ldr      x8, [x8, #0x28]
static inline uint64_t fde_func_0628_0x078840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078840ULL ^ (static_cast<uint64_t>(0xd11443ffULL) << 13);
    acc = (acc + a1 + 0xd53bd048ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0629 | PC: 0x079198 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0629 | Địa chỉ PC: 0x079198 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x079198: D105C3FF  sub      sp, sp, #0x170
//   0x07919c: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x0791a0: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x0791a4: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_0629_0x079198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079198ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0630 | PC: 0x079554 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0630 | Địa chỉ PC: 0x079554 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x079554: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x079558: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07955c: 910043FD  add      x29, sp, #0x10
//   0x079560: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0630_0x079554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079554ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0631 | PC: 0x0795f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0631 | Địa chỉ PC: 0x0795f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0795f4: D10183FF  sub      sp, sp, #0x60
//   0x0795f8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0795fc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x079600: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0631_0x0795f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0795f4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0632 | PC: 0x079768 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0632 | Địa chỉ PC: 0x079768 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x079768: D105C3FF  sub      sp, sp, #0x170
//   0x07976c: F90093FC  str      x28, [sp, #0x120]
//   0x079770: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x079774: A91457F6  stp      x22, x21, [sp, #0x140]
static inline uint64_t fde_func_0632_0x079768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079768ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf90093fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0633 | PC: 0x0799fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0633 | Địa chỉ PC: 0x0799fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0799fc: D10583FF  sub      sp, sp, #0x160
//   0x079a00: A91167FC  stp      x28, x25, [sp, #0x110]
//   0x079a04: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x079a08: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0633_0x0799fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0799fcULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa91167fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0634 | PC: 0x079c30 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0634 | Địa chỉ PC: 0x079c30 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x079c30: D10203FF  sub      sp, sp, #0x80
//   0x079c34: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x079c38: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x079c3c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0634_0x079c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079c30ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0635 | PC: 0x079d10 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0635 | Địa chỉ PC: 0x079d10 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x079d10: D10183FF  sub      sp, sp, #0x60
//   0x079d14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x079d18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x079d1c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0635_0x079d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079d10ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0636 | PC: 0x079ec0 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0636 | Địa chỉ PC: 0x079ec0 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x079ec0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x079ec4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x079ec8: 910043FD  add      x29, sp, #0x10
//   0x079ecc: A9405028  ldp      x8, x20, [x1]
static inline uint64_t fde_func_0636_0x079ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079ec0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0637 | PC: 0x079f18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0637 | Địa chỉ PC: 0x079f18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x079f18: D102C3FF  sub      sp, sp, #0xb0
//   0x079f1c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x079f20: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x079f24: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0637_0x079f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079f18ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0638 | PC: 0x07a050 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0638 | Địa chỉ PC: 0x07a050 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x07a050: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a054: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a058: 910043FD  add      x29, sp, #0x10
//   0x07a05c: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0638_0x07a050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a050ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0639 | PC: 0x07a0ac | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0639 | Địa chỉ PC: 0x07a0ac | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x07a0ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a0b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a0b4: 910043FD  add      x29, sp, #0x10
//   0x07a0b8: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0639_0x07a0ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a0acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0640 | PC: 0x07a108 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0640 | Địa chỉ PC: 0x07a108 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x07a108: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a10c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a110: 910043FD  add      x29, sp, #0x10
//   0x07a114: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0640_0x07a108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a108ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0641 | PC: 0x07a1dc | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0641 | Địa chỉ PC: 0x07a1dc | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x07a1dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07a1e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07a1e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07a1e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0641_0x07a1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a1dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0642 | PC: 0x07a260 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0642 | Địa chỉ PC: 0x07a260 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x07a260: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a264: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a268: 910043FD  add      x29, sp, #0x10
//   0x07a26c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0642_0x07a260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a260ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0643 | PC: 0x07a2a0 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0643 | Địa chỉ PC: 0x07a2a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x07a2a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a2a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a2a8: 910043FD  add      x29, sp, #0x10
//   0x07a2ac: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0643_0x07a2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a2a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0644 | PC: 0x07a31c | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0644 | Địa chỉ PC: 0x07a31c | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x07a31c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a320: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a324: 910043FD  add      x29, sp, #0x10
//   0x07a328: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0644_0x07a31c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a31cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0645 | PC: 0x07a3a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0645 | Địa chỉ PC: 0x07a3a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07a3a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a3a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a3ac: 910043FD  add      x29, sp, #0x10
//   0x07a3b0: B4000221  cbz      x1, #0x7a3f4
static inline uint64_t fde_func_0645_0x07a3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a3a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0646 | PC: 0x07a528 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0646 | Địa chỉ PC: 0x07a528 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x07a528: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07a52c: 910003FD  mov      x29, sp
//   0x07a530: F9400400  ldr      x0, [x0, #8]
//   0x07a534: 97FFDF18  bl       #0x72194
static inline uint64_t fde_func_0646_0x07a528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a528ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0647 | PC: 0x07a5c8 | FDE: 0x148a38 | Size: 252 bytes
// Hàm #0647 | Địa chỉ PC: 0x07a5c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 252 bytes
//   0x07a5c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07a5cc: 910003FD  mov      x29, sp
//   0x07a5d0: F9400400  ldr      x0, [x0, #8]
//   0x07a5d4: 97FFDEF0  bl       #0x72194
static inline uint64_t fde_func_0647_0x07a5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a5c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Func #0648 | PC: 0x07a6c4 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0648 | Địa chỉ PC: 0x07a6c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x07a6c4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07a6c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07a6cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07a6d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0648_0x07a6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a6c4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0649 | PC: 0x07a734 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0649 | Địa chỉ PC: 0x07a734 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x07a734: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a738: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a73c: 910043FD  add      x29, sp, #0x10
//   0x07a740: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0649_0x07a734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a734ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0650 | PC: 0x07a78c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0650 | Địa chỉ PC: 0x07a78c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07a78c: D10103FF  sub      sp, sp, #0x40
//   0x07a790: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07a794: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07a798: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0650_0x07a78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a78cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0651 | PC: 0x07a914 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #0651 | Địa chỉ PC: 0x07a914 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x07a914: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a918: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a91c: 910043FD  add      x29, sp, #0x10
//   0x07a920: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0651_0x07a914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a914ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #0652 | PC: 0x07a950 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0652 | Địa chỉ PC: 0x07a950 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07a950: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07a954: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07a958: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07a95c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0652_0x07a950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a950ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0653 | PC: 0x07ab48 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0653 | Địa chỉ PC: 0x07ab48 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x07ab48: D10103FF  sub      sp, sp, #0x40
//   0x07ab4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07ab50: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07ab54: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0653_0x07ab48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ab48ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0654 | PC: 0x07abd0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0654 | Địa chỉ PC: 0x07abd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07abd0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07abd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07abd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07abdc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0654_0x07abd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07abd0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0655 | PC: 0x07b004 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0655 | Địa chỉ PC: 0x07b004 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x07b004: D10103FF  sub      sp, sp, #0x40
//   0x07b008: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07b00c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07b010: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0655_0x07b004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b004ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0656 | PC: 0x07b088 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0656 | Địa chỉ PC: 0x07b088 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x07b088: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b08c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b090: 910043FD  add      x29, sp, #0x10
//   0x07b094: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0656_0x07b088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b088ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0657 | PC: 0x07b0d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0657 | Địa chỉ PC: 0x07b0d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07b0d8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07b0dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07b0e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07b0e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0657_0x07b0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b0d8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0658 | PC: 0x07b620 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0658 | Địa chỉ PC: 0x07b620 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x07b620: D10103FF  sub      sp, sp, #0x40
//   0x07b624: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07b628: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07b62c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0658_0x07b620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b620ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0659 | PC: 0x07b6ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0659 | Địa chỉ PC: 0x07b6ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07b6ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b6b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b6b4: 910043FD  add      x29, sp, #0x10
//   0x07b6b8: 39400009  ldrb     w9, [x0]
static inline uint64_t fde_func_0659_0x07b6ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b6acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0660 | PC: 0x07b938 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0660 | Địa chỉ PC: 0x07b938 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07b938: D10203FF  sub      sp, sp, #0x80
//   0x07b93c: F90013FB  str      x27, [sp, #0x20]
//   0x07b940: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x07b944: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0660_0x07b938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b938ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0661 | PC: 0x07bd44 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0661 | Địa chỉ PC: 0x07bd44 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07bd44: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07bd48: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07bd4c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07bd50: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0661_0x07bd44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bd44ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0662 | PC: 0x07bf60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0662 | Địa chỉ PC: 0x07bf60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07bf60: D10103FF  sub      sp, sp, #0x40
//   0x07bf64: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07bf68: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07bf6c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0662_0x07bf60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bf60ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0663 | PC: 0x07c1f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0663 | Địa chỉ PC: 0x07c1f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07c1f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07c1f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c1f8: 910043FD  add      x29, sp, #0x10
//   0x07c1fc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0663_0x07c1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c1f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0664 | PC: 0x07c610 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0664 | Địa chỉ PC: 0x07c610 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x07c610: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07c614: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07c618: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07c61c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0664_0x07c610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c610ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0665 | PC: 0x07c62c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0665 | Địa chỉ PC: 0x07c62c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07c62c: D10A43FF  sub      sp, sp, #0x290
//   0x07c630: F9400414  ldr      x20, [x0, #8]
//   0x07c634: B9423E88  ldr      w8, [x20, #0x23c]
//   0x07c638: 7100051F  cmp      w8, #1
static inline uint64_t fde_func_0665_0x07c62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c62cULL ^ (static_cast<uint64_t>(0xd10a43ffULL) << 13);
    acc = (acc + a1 + 0xf9400414ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0666 | PC: 0x07cd00 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0666 | Địa chỉ PC: 0x07cd00 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x07cd00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07cd04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cd08: 910043FD  add      x29, sp, #0x10
//   0x07cd0c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0666_0x07cd00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0667 | PC: 0x07cd8c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0667 | Địa chỉ PC: 0x07cd8c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x07cd8c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07cd90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07cd94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07cd98: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0667_0x07cd8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd8cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0668 | PC: 0x07cda8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0668 | Địa chỉ PC: 0x07cda8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07cda8: D10A43FF  sub      sp, sp, #0x290
//   0x07cdac: F9400414  ldr      x20, [x0, #8]
//   0x07cdb0: B9423E88  ldr      w8, [x20, #0x23c]
//   0x07cdb4: 7100051F  cmp      w8, #1
static inline uint64_t fde_func_0668_0x07cda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cda8ULL ^ (static_cast<uint64_t>(0xd10a43ffULL) << 13);
    acc = (acc + a1 + 0xf9400414ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0669 | PC: 0x07d588 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0669 | Địa chỉ PC: 0x07d588 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07d588: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07d58c: 910003FD  mov      x29, sp
//   0x07d590: F9400408  ldr      x8, [x0, #8]
//   0x07d594: B9423D08  ldr      w8, [x8, #0x23c]
static inline uint64_t fde_func_0669_0x07d588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d588ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0670 | PC: 0x07d6d4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0670 | Địa chỉ PC: 0x07d6d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07d6d4: D10203FF  sub      sp, sp, #0x80
//   0x07d6d8: F90013FB  str      x27, [sp, #0x20]
//   0x07d6dc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x07d6e0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0670_0x07d6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d6d4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0671 | PC: 0x07da2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0671 | Địa chỉ PC: 0x07da2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07da2c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07da30: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07da34: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07da38: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0671_0x07da2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07da2cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0672 | PC: 0x07dc28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0672 | Địa chỉ PC: 0x07dc28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07dc28: D10103FF  sub      sp, sp, #0x40
//   0x07dc2c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07dc30: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07dc34: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0672_0x07dc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dc28ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0673 | PC: 0x07dda4 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #0673 | Địa chỉ PC: 0x07dda4 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x07dda4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07dda8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ddac: 910043FD  add      x29, sp, #0x10
//   0x07ddb0: D00006E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0673_0x07dda4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dda4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #0674 | PC: 0x07de38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0674 | Địa chỉ PC: 0x07de38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07de38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07de3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07de40: 910043FD  add      x29, sp, #0x10
//   0x07de44: D00006E9  adrp     x9, #0x15b000
static inline uint64_t fde_func_0674_0x07de38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07de38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0675 | PC: 0x07df8c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0675 | Địa chỉ PC: 0x07df8c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07df8c: D10243FF  sub      sp, sp, #0x90
//   0x07df90: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x07df94: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x07df98: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0675_0x07df8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df8cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0676 | PC: 0x07e320 | FDE: 0x148a38 | Size: 176 bytes
// Hàm #0676 | Địa chỉ PC: 0x07e320 | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x07e320: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07e324: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07e328: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07e32c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0676_0x07e320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e320ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #0677 | PC: 0x07e3d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0677 | Địa chỉ PC: 0x07e3d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07e3d0: D101C3FF  sub      sp, sp, #0x70
//   0x07e3d4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x07e3d8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x07e3dc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0677_0x07e3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e3d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0678 | PC: 0x07e53c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0678 | Địa chỉ PC: 0x07e53c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07e53c: D101C3FF  sub      sp, sp, #0x70
//   0x07e540: F90023F5  str      x21, [sp, #0x40]
//   0x07e544: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x07e548: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0678_0x07e53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e53cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0679 | PC: 0x07e664 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0679 | Địa chỉ PC: 0x07e664 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07e664: D10183FF  sub      sp, sp, #0x60
//   0x07e668: F90013F7  str      x23, [sp, #0x20]
//   0x07e66c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07e670: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0679_0x07e664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e664ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0680 | PC: 0x07e828 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0680 | Địa chỉ PC: 0x07e828 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x07e828: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07e82c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e830: 910043FD  add      x29, sp, #0x10
//   0x07e834: 91018014  add      x20, x0, #0x60
static inline uint64_t fde_func_0680_0x07e828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e828ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0681 | PC: 0x07e868 | FDE: 0x148a38 | Size: 208 bytes
// Hàm #0681 | Địa chỉ PC: 0x07e868 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x07e868: D10103FF  sub      sp, sp, #0x40
//   0x07e86c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e870: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e874: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0681_0x07e868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e868ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0682 | PC: 0x07e938 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0682 | Địa chỉ PC: 0x07e938 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x07e938: D10143FF  sub      sp, sp, #0x50
//   0x07e93c: A901D7FF  stp      xzr, x21, [sp, #0x18]
//   0x07e940: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07e944: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0682_0x07e938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e938ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa901d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0683 | PC: 0x07e9f8 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0683 | Địa chỉ PC: 0x07e9f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x07e9f8: D100C3FF  sub      sp, sp, #0x30
//   0x07e9fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07ea00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07ea04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0683_0x07e9f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e9f8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0684 | PC: 0x07ea90 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0684 | Địa chỉ PC: 0x07ea90 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x07ea90: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07ea94: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07ea98: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07ea9c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0684_0x07ea90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ea90ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0685 | PC: 0x07eaac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0685 | Địa chỉ PC: 0x07eaac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07eaac: D110C3FF  sub      sp, sp, #0x430
//   0x07eab0: D53BD05B  mrs      x27, tpidr_el0
//   0x07eab4: F9401768  ldr      x8, [x27, #0x28]
//   0x07eab8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0685_0x07eaac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07eaacULL ^ (static_cast<uint64_t>(0xd110c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05bULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0686 | PC: 0x07ed00 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0686 | Địa chỉ PC: 0x07ed00 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x07ed00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07ed04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ed08: 910043FD  add      x29, sp, #0x10
//   0x07ed0c: B9408C08  ldr      w8, [x0, #0x8c]
static inline uint64_t fde_func_0686_0x07ed00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ed00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0687 | PC: 0x07ed60 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0687 | Địa chỉ PC: 0x07ed60 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x07ed60: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07ed64: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07ed68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07ed6c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0687_0x07ed60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ed60ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0688 | PC: 0x07ede4 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0688 | Địa chỉ PC: 0x07ede4 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x07ede4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07ede8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07edec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07edf0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0688_0x07ede4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ede4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0689 | PC: 0x07ee7c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0689 | Địa chỉ PC: 0x07ee7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07ee7c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07ee80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07ee84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07ee88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0689_0x07ee7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ee7cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0690 | PC: 0x07ef90 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0690 | Địa chỉ PC: 0x07ef90 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07ef90: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07ef94: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07ef98: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07ef9c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0690_0x07ef90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ef90ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0691 | PC: 0x07f098 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0691 | Địa chỉ PC: 0x07f098 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x07f098: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f09c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f0a0: 910043FD  add      x29, sp, #0x10
//   0x07f0a4: B40001A2  cbz      x2, #0x7f0d8
static inline uint64_t fde_func_0691_0x07f098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f098ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0692 | PC: 0x07f100 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0692 | Địa chỉ PC: 0x07f100 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07f100: D10303FF  sub      sp, sp, #0xc0
//   0x07f104: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x07f108: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x07f10c: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0692_0x07f100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f100ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0693 | PC: 0x07f3a0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0693 | Địa chỉ PC: 0x07f3a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07f3a0: D10303FF  sub      sp, sp, #0xc0
//   0x07f3a4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x07f3a8: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x07f3ac: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0693_0x07f3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f3a0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0694 | PC: 0x07f640 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0694 | Địa chỉ PC: 0x07f640 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x07f640: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f644: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f648: 910043FD  add      x29, sp, #0x10
//   0x07f64c: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0694_0x07f640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f640ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0695 | PC: 0x07f6a0 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0695 | Địa chỉ PC: 0x07f6a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x07f6a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f6a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f6a8: 910043FD  add      x29, sp, #0x10
//   0x07f6ac: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0695_0x07f6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f6a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0696 | PC: 0x07f754 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0696 | Địa chỉ PC: 0x07f754 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x07f754: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f758: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f75c: 910043FD  add      x29, sp, #0x10
//   0x07f760: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0696_0x07f754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f754ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0697 | PC: 0x07f7a4 | FDE: 0x148a38 | Size: 248 bytes
// Hàm #0697 | Địa chỉ PC: 0x07f7a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x07f7a4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07f7a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f7ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f7b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0697_0x07f7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f7a4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #0698 | PC: 0x07f89c | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0698 | Địa chỉ PC: 0x07f89c | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x07f89c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07f8a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f8a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f8a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0698_0x07f89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f89cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0699 | PC: 0x07f904 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0699 | Địa chỉ PC: 0x07f904 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07f904: D10103FF  sub      sp, sp, #0x40
//   0x07f908: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07f90c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07f910: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0699_0x07f904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f904ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0700 | PC: 0x07fa80 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0700 | Địa chỉ PC: 0x07fa80 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07fa80: D10103FF  sub      sp, sp, #0x40
//   0x07fa84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07fa88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07fa8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0700_0x07fa80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fa80ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0701 | PC: 0x07fbbc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0701 | Địa chỉ PC: 0x07fbbc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x07fbbc: D10483FF  sub      sp, sp, #0x120
//   0x07fbc0: F9007BFC  str      x28, [sp, #0xf0]
//   0x07fbc4: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x07fbc8: A9117BFD  stp      x29, x30, [sp, #0x110]
static inline uint64_t fde_func_0701_0x07fbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fbbcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0702 | PC: 0x0801b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0702 | Địa chỉ PC: 0x0801b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0801b0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0801b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0801b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0801bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0702_0x0801b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0801b0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0703 | PC: 0x0806f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0703 | Địa chỉ PC: 0x0806f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0806f4: D10703FF  sub      sp, sp, #0x1c0
//   0x0806f8: A91957FC  stp      x28, x21, [sp, #0x190]
//   0x0806fc: A91A4FF4  stp      x20, x19, [sp, #0x1a0]
//   0x080700: A91B7BFD  stp      x29, x30, [sp, #0x1b0]
static inline uint64_t fde_func_0703_0x0806f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0806f4ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa91957fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0704 | PC: 0x08091c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0704 | Địa chỉ PC: 0x08091c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08091c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x080920: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x080924: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x080928: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0704_0x08091c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08091cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0705 | PC: 0x080a48 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0705 | Địa chỉ PC: 0x080a48 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x080a48: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x080a4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x080a50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x080a54: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0705_0x080a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080a48ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0706 | PC: 0x080bb0 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0706 | Địa chỉ PC: 0x080bb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x080bb0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x080bb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x080bb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x080bbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0706_0x080bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080bb0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0707 | PC: 0x080c20 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0707 | Địa chỉ PC: 0x080c20 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x080c20: D10443FF  sub      sp, sp, #0x110
//   0x080c24: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x080c28: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x080c2c: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0707_0x080c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080c20ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0708 | PC: 0x080d38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0708 | Địa chỉ PC: 0x080d38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x080d38: D10303FF  sub      sp, sp, #0xc0
//   0x080d3c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x080d40: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x080d44: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0708_0x080d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080d38ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0709 | PC: 0x08107c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0709 | Địa chỉ PC: 0x08107c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08107c: D10183FF  sub      sp, sp, #0x60
//   0x081080: F9001BF5  str      x21, [sp, #0x30]
//   0x081084: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x081088: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0709_0x08107c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08107cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0710 | PC: 0x08121c | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0710 | Địa chỉ PC: 0x08121c | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x08121c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x081220: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x081224: 910043FD  add      x29, sp, #0x10
//   0x081228: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0710_0x08121c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08121cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0711 | PC: 0x081280 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0711 | Địa chỉ PC: 0x081280 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x081280: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x081284: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x081288: 910043FD  add      x29, sp, #0x10
//   0x08128c: A940A014  ldp      x20, x8, [x0, #8]
static inline uint64_t fde_func_0711_0x081280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081280ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0712 | PC: 0x08166c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0712 | Địa chỉ PC: 0x08166c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08166c: D101C3FF  sub      sp, sp, #0x70
//   0x081670: F9001BF7  str      x23, [sp, #0x30]
//   0x081674: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x081678: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0712_0x08166c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08166cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0713 | PC: 0x0817b4 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0713 | Địa chỉ PC: 0x0817b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0817b4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0817b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0817bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0817c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0713_0x0817b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0817b4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0714 | PC: 0x081814 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0714 | Địa chỉ PC: 0x081814 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x081814: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x081818: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08181c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x081820: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0714_0x081814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081814ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0715 | PC: 0x081920 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0715 | Địa chỉ PC: 0x081920 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x081920: D10103FF  sub      sp, sp, #0x40
//   0x081924: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x081928: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08192c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0715_0x081920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081920ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0716 | PC: 0x0819b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0716 | Địa chỉ PC: 0x0819b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0819b8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0819bc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0819c0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0819c4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0716_0x0819b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0819b8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0717 | PC: 0x081b30 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #0717 | Địa chỉ PC: 0x081b30 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x081b30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x081b34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x081b38: 910043FD  add      x29, sp, #0x10
//   0x081b3c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0717_0x081b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081b30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0718 | PC: 0x081bf4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0718 | Địa chỉ PC: 0x081bf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x081bf4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x081bf8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x081bfc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x081c00: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0718_0x081bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081bf4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0719 | PC: 0x082268 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0719 | Địa chỉ PC: 0x082268 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x082268: D10483FF  sub      sp, sp, #0x120
//   0x08226c: A90D67FC  stp      x28, x25, [sp, #0xd0]
//   0x082270: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x082274: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_0719_0x082268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082268ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90d67fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0720 | PC: 0x0828dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0720 | Địa chỉ PC: 0x0828dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0828dc: D10383FF  sub      sp, sp, #0xe0
//   0x0828e0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0828e4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0828e8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0720_0x0828dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0828dcULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0721 | PC: 0x082c10 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0721 | Địa chỉ PC: 0x082c10 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x082c10: D10203FF  sub      sp, sp, #0x80
//   0x082c14: F9001BF9  str      x25, [sp, #0x30]
//   0x082c18: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x082c1c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0721_0x082c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082c10ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0722 | PC: 0x082d18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0722 | Địa chỉ PC: 0x082d18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x082d18: D10143FF  sub      sp, sp, #0x50
//   0x082d1c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x082d20: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x082d24: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0722_0x082d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082d18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0723 | PC: 0x082ef8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0723 | Địa chỉ PC: 0x082ef8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x082ef8: D101C3FF  sub      sp, sp, #0x70
//   0x082efc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x082f00: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x082f04: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0723_0x082ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082ef8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0724 | PC: 0x08321c | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0724 | Địa chỉ PC: 0x08321c | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x08321c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x083220: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x083224: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x083228: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0724_0x08321c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08321cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0725 | PC: 0x0832d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0725 | Địa chỉ PC: 0x0832d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0832d8: D10443FF  sub      sp, sp, #0x110
//   0x0832dc: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0832e0: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0832e4: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0725_0x0832d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0832d8ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0726 | PC: 0x083c40 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0726 | Địa chỉ PC: 0x083c40 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x083c40: D10403FF  sub      sp, sp, #0x100
//   0x083c44: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x083c48: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x083c4c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0726_0x083c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083c40ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0727 | PC: 0x084598 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #0727 | Địa chỉ PC: 0x084598 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x084598: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x08459c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0845a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0845a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0727_0x084598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084598ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0728 | PC: 0x08465c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0728 | Địa chỉ PC: 0x08465c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08465c: D10143FF  sub      sp, sp, #0x50
//   0x084660: F90013F5  str      x21, [sp, #0x20]
//   0x084664: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x084668: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0728_0x08465c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08465cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0729 | PC: 0x0847fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0729 | Địa chỉ PC: 0x0847fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0847fc: D10243FF  sub      sp, sp, #0x90
//   0x084800: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x084804: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x084808: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0729_0x0847fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0847fcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0730 | PC: 0x084b18 | FDE: 0x148a38 | Size: 20 bytes
// Hàm #0730 | Địa chỉ PC: 0x084b18 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x084b18: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x084b1c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x084b20: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x084b24: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0730_0x084b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084b18ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #0731 | PC: 0x084b2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0731 | Địa chỉ PC: 0x084b2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x084b2c: D11083FF  sub      sp, sp, #0x420
//   0x084b30: D53BD057  mrs      x23, tpidr_el0
//   0x084b34: F94016E8  ldr      x8, [x23, #0x28]
//   0x084b38: F81C83A8  stur     x8, [x29, #-0x38]
static inline uint64_t fde_func_0731_0x084b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084b2cULL ^ (static_cast<uint64_t>(0xd11083ffULL) << 13);
    acc = (acc + a1 + 0xd53bd057ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0732 | PC: 0x084d7c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0732 | Địa chỉ PC: 0x084d7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x084d7c: D10103FF  sub      sp, sp, #0x40
//   0x084d80: F9000BF5  str      x21, [sp, #0x10]
//   0x084d84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x084d88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0732_0x084d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084d7cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0733 | PC: 0x084f18 | FDE: 0x148a38 | Size: 252 bytes
// Hàm #0733 | Địa chỉ PC: 0x084f18 | Địa chỉ FDE: 0x148a38 | Kích thước: 252 bytes
//   0x084f18: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x084f1c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x084f20: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x084f24: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0733_0x084f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084f18ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Func #0734 | PC: 0x085014 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0734 | Địa chỉ PC: 0x085014 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085014: D10183FF  sub      sp, sp, #0x60
//   0x085018: F90013F7  str      x23, [sp, #0x20]
//   0x08501c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x085020: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0734_0x085014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085014ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0735 | PC: 0x08525c | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0735 | Địa chỉ PC: 0x08525c | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x08525c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x085260: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x085264: 910043FD  add      x29, sp, #0x10
//   0x085268: 9100C014  add      x20, x0, #0x30
static inline uint64_t fde_func_0735_0x08525c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08525cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0736 | PC: 0x08529c | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0736 | Địa chỉ PC: 0x08529c | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x08529c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0852a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0852a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0852a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0736_0x08529c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08529cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0737 | PC: 0x085370 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0737 | Địa chỉ PC: 0x085370 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085370: D101C3FF  sub      sp, sp, #0x70
//   0x085374: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x085378: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x08537c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0737_0x085370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085370ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0738 | PC: 0x08559c | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0738 | Địa chỉ PC: 0x08559c | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x08559c: D101C3FF  sub      sp, sp, #0x70
//   0x0855a0: F90023F5  str      x21, [sp, #0x40]
//   0x0855a4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0855a8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0738_0x08559c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08559cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0739 | PC: 0x085690 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0739 | Địa chỉ PC: 0x085690 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085690: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x085694: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x085698: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08569c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0739_0x085690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085690ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0740 | PC: 0x085800 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0740 | Địa chỉ PC: 0x085800 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085800: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x085804: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x085808: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08580c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0740_0x085800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085800ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0741 | PC: 0x085988 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0741 | Địa chỉ PC: 0x085988 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085988: D101C3FF  sub      sp, sp, #0x70
//   0x08598c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x085990: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x085994: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0741_0x085988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085988ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0742 | PC: 0x085b1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0742 | Địa chỉ PC: 0x085b1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085b1c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x085b20: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x085b24: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x085b28: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0742_0x085b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085b1cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0743 | PC: 0x085c50 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0743 | Địa chỉ PC: 0x085c50 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x085c50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x085c54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x085c58: 910043FD  add      x29, sp, #0x10
//   0x085c5c: 9100C014  add      x20, x0, #0x30
static inline uint64_t fde_func_0743_0x085c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085c50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0744 | PC: 0x085cc4 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0744 | Địa chỉ PC: 0x085cc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x085cc4: D101C3FF  sub      sp, sp, #0x70
//   0x085cc8: F90023F5  str      x21, [sp, #0x40]
//   0x085ccc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x085cd0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0744_0x085cc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085cc4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0745 | PC: 0x085d8c | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0745 | Địa chỉ PC: 0x085d8c | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x085d8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x085d90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x085d94: 910043FD  add      x29, sp, #0x10
//   0x085d98: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0745_0x085d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085d8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0746 | PC: 0x085e30 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0746 | Địa chỉ PC: 0x085e30 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x085e30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x085e34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x085e38: 910043FD  add      x29, sp, #0x10
//   0x085e3c: B4000521  cbz      x1, #0x85ee0
static inline uint64_t fde_func_0746_0x085e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085e30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0747 | PC: 0x085eec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0747 | Địa chỉ PC: 0x085eec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x085eec: D10283FF  sub      sp, sp, #0xa0
//   0x085ef0: F9002BF9  str      x25, [sp, #0x50]
//   0x085ef4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x085ef8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0747_0x085eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085eecULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0748 | PC: 0x086110 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0748 | Địa chỉ PC: 0x086110 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x086110: D10103FF  sub      sp, sp, #0x40
//   0x086114: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x086118: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x08611c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0748_0x086110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086110ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0749 | PC: 0x0861cc | FDE: 0x148a38 | Size: 228 bytes
// Hàm #0749 | Địa chỉ PC: 0x0861cc | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0861cc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0861d0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0861d4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0861d8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0749_0x0861cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0861ccULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #0750 | PC: 0x0862b0 | FDE: 0x148a38 | Size: 220 bytes
// Hàm #0750 | Địa chỉ PC: 0x0862b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 220 bytes
//   0x0862b0: D10243FF  sub      sp, sp, #0x90
//   0x0862b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0862b8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0862bc: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0750_0x0862b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0862b0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// Func #0751 | PC: 0x08638c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0751 | Địa chỉ PC: 0x08638c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08638c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x086390: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x086394: 910043FD  add      x29, sp, #0x10
//   0x086398: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0751_0x08638c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08638cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0752 | PC: 0x0864d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0752 | Địa chỉ PC: 0x0864d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0864d8: D10243FF  sub      sp, sp, #0x90
//   0x0864dc: F90023F9  str      x25, [sp, #0x40]
//   0x0864e0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0864e4: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0752_0x0864d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0864d8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0753 | PC: 0x0866e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0753 | Địa chỉ PC: 0x0866e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0866e4: D102C3FF  sub      sp, sp, #0xb0
//   0x0866e8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0866ec: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0866f0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0753_0x0866e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0866e4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0754 | PC: 0x0868ec | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0754 | Địa chỉ PC: 0x0868ec | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0868ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0868f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0868f4: 910043FD  add      x29, sp, #0x10
//   0x0868f8: 9100C013  add      x19, x0, #0x30
static inline uint64_t fde_func_0754_0x0868ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0868ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0755 | PC: 0x086944 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0755 | Địa chỉ PC: 0x086944 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x086944: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x086948: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08694c: 910043FD  add      x29, sp, #0x10
//   0x086950: 3947C408  ldrb     w8, [x0, #0x1f1]
static inline uint64_t fde_func_0755_0x086944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086944ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0756 | PC: 0x0869a0 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #0756 | Địa chỉ PC: 0x0869a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0869a0: D10183FF  sub      sp, sp, #0x60
//   0x0869a4: F9001BF5  str      x21, [sp, #0x30]
//   0x0869a8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0869ac: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0756_0x0869a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0869a0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #0757 | PC: 0x086a88 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0757 | Địa chỉ PC: 0x086a88 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x086a88: D10183FF  sub      sp, sp, #0x60
//   0x086a8c: F90013F7  str      x23, [sp, #0x20]
//   0x086a90: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x086a94: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0757_0x086a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086a88ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0758 | PC: 0x086cb0 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #0758 | Địa chỉ PC: 0x086cb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x086cb0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x086cb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x086cb8: 910043FD  add      x29, sp, #0x10
//   0x086cbc: B4000281  cbz      x1, #0x86d0c
static inline uint64_t fde_func_0758_0x086cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086cb0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0759 | PC: 0x086d58 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0759 | Địa chỉ PC: 0x086d58 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x086d58: D10103FF  sub      sp, sp, #0x40
//   0x086d5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x086d60: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x086d64: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0759_0x086d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086d58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 380: return fde_func_0380_0x05cdc8(a0, a1);
        case 381: return fde_func_0381_0x05ce54(a0, a1);
        case 382: return fde_func_0382_0x05cee8(a0, a1);
        case 383: return fde_func_0383_0x05cf6c(a0, a1);
        case 384: return fde_func_0384_0x05d240(a0, a1);
        case 385: return fde_func_0385_0x05d660(a0, a1);
        case 386: return fde_func_0386_0x05da28(a0, a1);
        case 387: return fde_func_0387_0x05dacc(a0, a1);
        case 388: return fde_func_0388_0x05db04(a0, a1);
        case 389: return fde_func_0389_0x05db98(a0, a1);
        case 390: return fde_func_0390_0x05dc14(a0, a1);
        case 391: return fde_func_0391_0x05dc7c(a0, a1);
        case 392: return fde_func_0392_0x05dcfc(a0, a1);
        case 393: return fde_func_0393_0x05dd7c(a0, a1);
        case 394: return fde_func_0394_0x05de00(a0, a1);
        case 395: return fde_func_0395_0x05de80(a0, a1);
        case 396: return fde_func_0396_0x05df00(a0, a1);
        case 397: return fde_func_0397_0x05df80(a0, a1);
        case 398: return fde_func_0398_0x05e050(a0, a1);
        case 399: return fde_func_0399_0x05e120(a0, a1);
        case 400: return fde_func_0400_0x05e1f0(a0, a1);
        case 401: return fde_func_0401_0x05e2c8(a0, a1);
        case 402: return fde_func_0402_0x05e398(a0, a1);
        case 403: return fde_func_0403_0x05e468(a0, a1);
        case 404: return fde_func_0404_0x05e4cc(a0, a1);
        case 405: return fde_func_0405_0x05e6c8(a0, a1);
        case 406: return fde_func_0406_0x05e848(a0, a1);
        case 407: return fde_func_0407_0x05e8f0(a0, a1);
        case 408: return fde_func_0408_0x05e980(a0, a1);
        case 409: return fde_func_0409_0x05e988(a0, a1);
        case 410: return fde_func_0410_0x05e990(a0, a1);
        case 411: return fde_func_0411_0x05e998(a0, a1);
        case 412: return fde_func_0412_0x05e9a0(a0, a1);
        case 413: return fde_func_0413_0x05e9cc(a0, a1);
        case 414: return fde_func_0414_0x05e9d4(a0, a1);
        case 415: return fde_func_0415_0x05e9dc(a0, a1);
        case 416: return fde_func_0416_0x05e9e4(a0, a1);
        case 417: return fde_func_0417_0x05e9ec(a0, a1);
        case 418: return fde_func_0418_0x05e9f4(a0, a1);
        case 419: return fde_func_0419_0x05e9fc(a0, a1);
        case 420: return fde_func_0420_0x05ea04(a0, a1);
        case 421: return fde_func_0421_0x05ea0c(a0, a1);
        case 422: return fde_func_0422_0x05ea14(a0, a1);
        case 423: return fde_func_0423_0x05ebac(a0, a1);
        case 424: return fde_func_0424_0x05ebf0(a0, a1);
        case 425: return fde_func_0425_0x05ece4(a0, a1);
        case 426: return fde_func_0426_0x05edd4(a0, a1);
        case 427: return fde_func_0427_0x05edf8(a0, a1);
        case 428: return fde_func_0428_0x05efb8(a0, a1);
        case 429: return fde_func_0429_0x05efc0(a0, a1);
        case 430: return fde_func_0430_0x05f15c(a0, a1);
        case 431: return fde_func_0431_0x05f1b0(a0, a1);
        case 432: return fde_func_0432_0x05f234(a0, a1);
        case 433: return fde_func_0433_0x05f33c(a0, a1);
        case 434: return fde_func_0434_0x05f45c(a0, a1);
        case 435: return fde_func_0435_0x05f640(a0, a1);
        case 436: return fde_func_0436_0x05fca8(a0, a1);
        case 437: return fde_func_0437_0x05fce4(a0, a1);
        case 438: return fde_func_0438_0x05fcf8(a0, a1);
        case 439: return fde_func_0439_0x05fe1c(a0, a1);
        case 440: return fde_func_0440_0x060010(a0, a1);
        case 441: return fde_func_0441_0x0600e4(a0, a1);
        case 442: return fde_func_0442_0x060250(a0, a1);
        case 443: return fde_func_0443_0x060314(a0, a1);
        case 444: return fde_func_0444_0x060754(a0, a1);
        case 445: return fde_func_0445_0x060a34(a0, a1);
        case 446: return fde_func_0446_0x060ae0(a0, a1);
        case 447: return fde_func_0447_0x060bdc(a0, a1);
        case 448: return fde_func_0448_0x060bf8(a0, a1);
        case 449: return fde_func_0449_0x0611bc(a0, a1);
        case 450: return fde_func_0450_0x061270(a0, a1);
        case 451: return fde_func_0451_0x0617c0(a0, a1);
        case 452: return fde_func_0452_0x061858(a0, a1);
        case 453: return fde_func_0453_0x061bac(a0, a1);
        case 454: return fde_func_0454_0x0620ac(a0, a1);
        case 455: return fde_func_0455_0x0623e4(a0, a1);
        case 456: return fde_func_0456_0x0630f8(a0, a1);
        case 457: return fde_func_0457_0x06364c(a0, a1);
        case 458: return fde_func_0458_0x063dfc(a0, a1);
        case 459: return fde_func_0459_0x064238(a0, a1);
        case 460: return fde_func_0460_0x064668(a0, a1);
        case 461: return fde_func_0461_0x06470c(a0, a1);
        case 462: return fde_func_0462_0x064948(a0, a1);
        case 463: return fde_func_0463_0x064a78(a0, a1);
        case 464: return fde_func_0464_0x064c40(a0, a1);
        case 465: return fde_func_0465_0x064e20(a0, a1);
        case 466: return fde_func_0466_0x064f14(a0, a1);
        case 467: return fde_func_0467_0x065088(a0, a1);
        case 468: return fde_func_0468_0x06552c(a0, a1);
        case 469: return fde_func_0469_0x0657cc(a0, a1);
        case 470: return fde_func_0470_0x0659fc(a0, a1);
        case 471: return fde_func_0471_0x065b00(a0, a1);
        case 472: return fde_func_0472_0x065c14(a0, a1);
        case 473: return fde_func_0473_0x065ec8(a0, a1);
        case 474: return fde_func_0474_0x06609c(a0, a1);
        case 475: return fde_func_0475_0x0660d8(a0, a1);
        case 476: return fde_func_0476_0x0660ec(a0, a1);
        case 477: return fde_func_0477_0x066238(a0, a1);
        case 478: return fde_func_0478_0x066318(a0, a1);
        case 479: return fde_func_0479_0x066484(a0, a1);
        case 480: return fde_func_0480_0x066798(a0, a1);
        case 481: return fde_func_0481_0x066868(a0, a1);
        case 482: return fde_func_0482_0x066884(a0, a1);
        case 483: return fde_func_0483_0x067154(a0, a1);
        case 484: return fde_func_0484_0x067814(a0, a1);
        case 485: return fde_func_0485_0x0679dc(a0, a1);
        case 486: return fde_func_0486_0x067b30(a0, a1);
        case 487: return fde_func_0487_0x0683f4(a0, a1);
        case 488: return fde_func_0488_0x068b9c(a0, a1);
        case 489: return fde_func_0489_0x069488(a0, a1);
        case 490: return fde_func_0490_0x069cd0(a0, a1);
        case 491: return fde_func_0491_0x069fe8(a0, a1);
        case 492: return fde_func_0492_0x06a004(a0, a1);
        case 493: return fde_func_0493_0x06a444(a0, a1);
        case 494: return fde_func_0494_0x06a738(a0, a1);
        case 495: return fde_func_0495_0x06a74c(a0, a1);
        case 496: return fde_func_0496_0x06a750(a0, a1);
        case 497: return fde_func_0497_0x06a754(a0, a1);
        case 498: return fde_func_0498_0x06a75c(a0, a1);
        case 499: return fde_func_0499_0x06a764(a0, a1);
        case 500: return fde_func_0500_0x06a76c(a0, a1);
        case 501: return fde_func_0501_0x06a770(a0, a1);
        case 502: return fde_func_0502_0x06a774(a0, a1);
        case 503: return fde_func_0503_0x06a7c4(a0, a1);
        case 504: return fde_func_0504_0x06a7cc(a0, a1);
        case 505: return fde_func_0505_0x06a81c(a0, a1);
        case 506: return fde_func_0506_0x06a844(a0, a1);
        case 507: return fde_func_0507_0x06a854(a0, a1);
        case 508: return fde_func_0508_0x06a918(a0, a1);
        case 509: return fde_func_0509_0x06a960(a0, a1);
        case 510: return fde_func_0510_0x06aa18(a0, a1);
        case 511: return fde_func_0511_0x06aac4(a0, a1);
        case 512: return fde_func_0512_0x06aacc(a0, a1);
        case 513: return fde_func_0513_0x06ab28(a0, a1);
        case 514: return fde_func_0514_0x06ae1c(a0, a1);
        case 515: return fde_func_0515_0x06ae30(a0, a1);
        case 516: return fde_func_0516_0x06af0c(a0, a1);
        case 517: return fde_func_0517_0x06afe0(a0, a1);
        case 518: return fde_func_0518_0x06b060(a0, a1);
        case 519: return fde_func_0519_0x06b234(a0, a1);
        case 520: return fde_func_0520_0x06b714(a0, a1);
        case 521: return fde_func_0521_0x06b8d4(a0, a1);
        case 522: return fde_func_0522_0x06ba64(a0, a1);
        case 523: return fde_func_0523_0x06bc0c(a0, a1);
        case 524: return fde_func_0524_0x06bcb4(a0, a1);
        case 525: return fde_func_0525_0x06bcd0(a0, a1);
        case 526: return fde_func_0526_0x06c1f0(a0, a1);
        case 527: return fde_func_0527_0x06c2d0(a0, a1);
        case 528: return fde_func_0528_0x06c390(a0, a1);
        case 529: return fde_func_0529_0x06c748(a0, a1);
        case 530: return fde_func_0530_0x06c7d0(a0, a1);
        case 531: return fde_func_0531_0x06c9d4(a0, a1);
        case 532: return fde_func_0532_0x06c9f0(a0, a1);
        case 533: return fde_func_0533_0x06d30c(a0, a1);
        case 534: return fde_func_0534_0x06d804(a0, a1);
        case 535: return fde_func_0535_0x06db38(a0, a1);
        case 536: return fde_func_0536_0x06de70(a0, a1);
        case 537: return fde_func_0537_0x06df70(a0, a1);
        case 538: return fde_func_0538_0x06e330(a0, a1);
        case 539: return fde_func_0539_0x06e4a0(a0, a1);
        case 540: return fde_func_0540_0x06e744(a0, a1);
        case 541: return fde_func_0541_0x06e7c4(a0, a1);
        case 542: return fde_func_0542_0x06e854(a0, a1);
        case 543: return fde_func_0543_0x06e980(a0, a1);
        case 544: return fde_func_0544_0x06ea60(a0, a1);
        case 545: return fde_func_0545_0x06ed50(a0, a1);
        case 546: return fde_func_0546_0x06eda0(a0, a1);
        case 547: return fde_func_0547_0x06ee2c(a0, a1);
        case 548: return fde_func_0548_0x06eea0(a0, a1);
        case 549: return fde_func_0549_0x06f718(a0, a1);
        case 550: return fde_func_0550_0x06f9a0(a0, a1);
        case 551: return fde_func_0551_0x06fa04(a0, a1);
        case 552: return fde_func_0552_0x06fca8(a0, a1);
        case 553: return fde_func_0553_0x06fec8(a0, a1);
        case 554: return fde_func_0554_0x070298(a0, a1);
        case 555: return fde_func_0555_0x0704ec(a0, a1);
        case 556: return fde_func_0556_0x07054c(a0, a1);
        case 557: return fde_func_0557_0x070854(a0, a1);
        case 558: return fde_func_0558_0x070a90(a0, a1);
        case 559: return fde_func_0559_0x070b1c(a0, a1);
        case 560: return fde_func_0560_0x070c44(a0, a1);
        case 561: return fde_func_0561_0x070dc8(a0, a1);
        case 562: return fde_func_0562_0x070fcc(a0, a1);
        case 563: return fde_func_0563_0x071248(a0, a1);
        case 564: return fde_func_0564_0x071304(a0, a1);
        case 565: return fde_func_0565_0x071584(a0, a1);
        case 566: return fde_func_0566_0x07175c(a0, a1);
        case 567: return fde_func_0567_0x071880(a0, a1);
        case 568: return fde_func_0568_0x0719b0(a0, a1);
        case 569: return fde_func_0569_0x071a50(a0, a1);
        case 570: return fde_func_0570_0x071f08(a0, a1);
        case 571: return fde_func_0571_0x071f6c(a0, a1);
        case 572: return fde_func_0572_0x07201c(a0, a1);
        case 573: return fde_func_0573_0x072194(a0, a1);
        case 574: return fde_func_0574_0x0722e0(a0, a1);
        case 575: return fde_func_0575_0x072340(a0, a1);
        case 576: return fde_func_0576_0x0729d0(a0, a1);
        case 577: return fde_func_0577_0x072b60(a0, a1);
        case 578: return fde_func_0578_0x072be8(a0, a1);
        case 579: return fde_func_0579_0x072e5c(a0, a1);
        case 580: return fde_func_0580_0x073190(a0, a1);
        case 581: return fde_func_0581_0x0731ac(a0, a1);
        case 582: return fde_func_0582_0x07342c(a0, a1);
        case 583: return fde_func_0583_0x073650(a0, a1);
        case 584: return fde_func_0584_0x073760(a0, a1);
        case 585: return fde_func_0585_0x073974(a0, a1);
        case 586: return fde_func_0586_0x073ae0(a0, a1);
        case 587: return fde_func_0587_0x073db0(a0, a1);
        case 588: return fde_func_0588_0x07413c(a0, a1);
        case 589: return fde_func_0589_0x074158(a0, a1);
        case 590: return fde_func_0590_0x0746c0(a0, a1);
        case 591: return fde_func_0591_0x074940(a0, a1);
        case 592: return fde_func_0592_0x074d3c(a0, a1);
        case 593: return fde_func_0593_0x074fa4(a0, a1);
        case 594: return fde_func_0594_0x075b00(a0, a1);
        case 595: return fde_func_0595_0x075e7c(a0, a1);
        case 596: return fde_func_0596_0x076118(a0, a1);
        case 597: return fde_func_0597_0x0761d8(a0, a1);
        case 598: return fde_func_0598_0x07623c(a0, a1);
        case 599: return fde_func_0599_0x076470(a0, a1);
        case 600: return fde_func_0600_0x0767dc(a0, a1);
        case 601: return fde_func_0601_0x076a58(a0, a1);
        case 602: return fde_func_0602_0x076bac(a0, a1);
        case 603: return fde_func_0603_0x076c6c(a0, a1);
        case 604: return fde_func_0604_0x076d80(a0, a1);
        case 605: return fde_func_0605_0x076e60(a0, a1);
        case 606: return fde_func_0606_0x076ff8(a0, a1);
        case 607: return fde_func_0607_0x077144(a0, a1);
        case 608: return fde_func_0608_0x077380(a0, a1);
        case 609: return fde_func_0609_0x0776f8(a0, a1);
        case 610: return fde_func_0610_0x0777a0(a0, a1);
        case 611: return fde_func_0611_0x07789c(a0, a1);
        case 612: return fde_func_0612_0x077994(a0, a1);
        case 613: return fde_func_0613_0x077aa4(a0, a1);
        case 614: return fde_func_0614_0x077b18(a0, a1);
        case 615: return fde_func_0615_0x077c90(a0, a1);
        case 616: return fde_func_0616_0x077d5c(a0, a1);
        case 617: return fde_func_0617_0x077e50(a0, a1);
        case 618: return fde_func_0618_0x077eb0(a0, a1);
        case 619: return fde_func_0619_0x077f2c(a0, a1);
        case 620: return fde_func_0620_0x077fd8(a0, a1);
        case 621: return fde_func_0621_0x0780d8(a0, a1);
        case 622: return fde_func_0622_0x078198(a0, a1);
        case 623: return fde_func_0623_0x0781d0(a0, a1);
        case 624: return fde_func_0624_0x0782bc(a0, a1);
        case 625: return fde_func_0625_0x07843c(a0, a1);
        case 626: return fde_func_0626_0x0786b0(a0, a1);
        case 627: return fde_func_0627_0x078824(a0, a1);
        case 628: return fde_func_0628_0x078840(a0, a1);
        case 629: return fde_func_0629_0x079198(a0, a1);
        case 630: return fde_func_0630_0x079554(a0, a1);
        case 631: return fde_func_0631_0x0795f4(a0, a1);
        case 632: return fde_func_0632_0x079768(a0, a1);
        case 633: return fde_func_0633_0x0799fc(a0, a1);
        case 634: return fde_func_0634_0x079c30(a0, a1);
        case 635: return fde_func_0635_0x079d10(a0, a1);
        case 636: return fde_func_0636_0x079ec0(a0, a1);
        case 637: return fde_func_0637_0x079f18(a0, a1);
        case 638: return fde_func_0638_0x07a050(a0, a1);
        case 639: return fde_func_0639_0x07a0ac(a0, a1);
        case 640: return fde_func_0640_0x07a108(a0, a1);
        case 641: return fde_func_0641_0x07a1dc(a0, a1);
        case 642: return fde_func_0642_0x07a260(a0, a1);
        case 643: return fde_func_0643_0x07a2a0(a0, a1);
        case 644: return fde_func_0644_0x07a31c(a0, a1);
        case 645: return fde_func_0645_0x07a3a4(a0, a1);
        case 646: return fde_func_0646_0x07a528(a0, a1);
        case 647: return fde_func_0647_0x07a5c8(a0, a1);
        case 648: return fde_func_0648_0x07a6c4(a0, a1);
        case 649: return fde_func_0649_0x07a734(a0, a1);
        case 650: return fde_func_0650_0x07a78c(a0, a1);
        case 651: return fde_func_0651_0x07a914(a0, a1);
        case 652: return fde_func_0652_0x07a950(a0, a1);
        case 653: return fde_func_0653_0x07ab48(a0, a1);
        case 654: return fde_func_0654_0x07abd0(a0, a1);
        case 655: return fde_func_0655_0x07b004(a0, a1);
        case 656: return fde_func_0656_0x07b088(a0, a1);
        case 657: return fde_func_0657_0x07b0d8(a0, a1);
        case 658: return fde_func_0658_0x07b620(a0, a1);
        case 659: return fde_func_0659_0x07b6ac(a0, a1);
        case 660: return fde_func_0660_0x07b938(a0, a1);
        case 661: return fde_func_0661_0x07bd44(a0, a1);
        case 662: return fde_func_0662_0x07bf60(a0, a1);
        case 663: return fde_func_0663_0x07c1f0(a0, a1);
        case 664: return fde_func_0664_0x07c610(a0, a1);
        case 665: return fde_func_0665_0x07c62c(a0, a1);
        case 666: return fde_func_0666_0x07cd00(a0, a1);
        case 667: return fde_func_0667_0x07cd8c(a0, a1);
        case 668: return fde_func_0668_0x07cda8(a0, a1);
        case 669: return fde_func_0669_0x07d588(a0, a1);
        case 670: return fde_func_0670_0x07d6d4(a0, a1);
        case 671: return fde_func_0671_0x07da2c(a0, a1);
        case 672: return fde_func_0672_0x07dc28(a0, a1);
        case 673: return fde_func_0673_0x07dda4(a0, a1);
        case 674: return fde_func_0674_0x07de38(a0, a1);
        case 675: return fde_func_0675_0x07df8c(a0, a1);
        case 676: return fde_func_0676_0x07e320(a0, a1);
        case 677: return fde_func_0677_0x07e3d0(a0, a1);
        case 678: return fde_func_0678_0x07e53c(a0, a1);
        case 679: return fde_func_0679_0x07e664(a0, a1);
        case 680: return fde_func_0680_0x07e828(a0, a1);
        case 681: return fde_func_0681_0x07e868(a0, a1);
        case 682: return fde_func_0682_0x07e938(a0, a1);
        case 683: return fde_func_0683_0x07e9f8(a0, a1);
        case 684: return fde_func_0684_0x07ea90(a0, a1);
        case 685: return fde_func_0685_0x07eaac(a0, a1);
        case 686: return fde_func_0686_0x07ed00(a0, a1);
        case 687: return fde_func_0687_0x07ed60(a0, a1);
        case 688: return fde_func_0688_0x07ede4(a0, a1);
        case 689: return fde_func_0689_0x07ee7c(a0, a1);
        case 690: return fde_func_0690_0x07ef90(a0, a1);
        case 691: return fde_func_0691_0x07f098(a0, a1);
        case 692: return fde_func_0692_0x07f100(a0, a1);
        case 693: return fde_func_0693_0x07f3a0(a0, a1);
        case 694: return fde_func_0694_0x07f640(a0, a1);
        case 695: return fde_func_0695_0x07f6a0(a0, a1);
        case 696: return fde_func_0696_0x07f754(a0, a1);
        case 697: return fde_func_0697_0x07f7a4(a0, a1);
        case 698: return fde_func_0698_0x07f89c(a0, a1);
        case 699: return fde_func_0699_0x07f904(a0, a1);
        case 700: return fde_func_0700_0x07fa80(a0, a1);
        case 701: return fde_func_0701_0x07fbbc(a0, a1);
        case 702: return fde_func_0702_0x0801b0(a0, a1);
        case 703: return fde_func_0703_0x0806f4(a0, a1);
        case 704: return fde_func_0704_0x08091c(a0, a1);
        case 705: return fde_func_0705_0x080a48(a0, a1);
        case 706: return fde_func_0706_0x080bb0(a0, a1);
        case 707: return fde_func_0707_0x080c20(a0, a1);
        case 708: return fde_func_0708_0x080d38(a0, a1);
        case 709: return fde_func_0709_0x08107c(a0, a1);
        case 710: return fde_func_0710_0x08121c(a0, a1);
        case 711: return fde_func_0711_0x081280(a0, a1);
        case 712: return fde_func_0712_0x08166c(a0, a1);
        case 713: return fde_func_0713_0x0817b4(a0, a1);
        case 714: return fde_func_0714_0x081814(a0, a1);
        case 715: return fde_func_0715_0x081920(a0, a1);
        case 716: return fde_func_0716_0x0819b8(a0, a1);
        case 717: return fde_func_0717_0x081b30(a0, a1);
        case 718: return fde_func_0718_0x081bf4(a0, a1);
        case 719: return fde_func_0719_0x082268(a0, a1);
        case 720: return fde_func_0720_0x0828dc(a0, a1);
        case 721: return fde_func_0721_0x082c10(a0, a1);
        case 722: return fde_func_0722_0x082d18(a0, a1);
        case 723: return fde_func_0723_0x082ef8(a0, a1);
        case 724: return fde_func_0724_0x08321c(a0, a1);
        case 725: return fde_func_0725_0x0832d8(a0, a1);
        case 726: return fde_func_0726_0x083c40(a0, a1);
        case 727: return fde_func_0727_0x084598(a0, a1);
        case 728: return fde_func_0728_0x08465c(a0, a1);
        case 729: return fde_func_0729_0x0847fc(a0, a1);
        case 730: return fde_func_0730_0x084b18(a0, a1);
        case 731: return fde_func_0731_0x084b2c(a0, a1);
        case 732: return fde_func_0732_0x084d7c(a0, a1);
        case 733: return fde_func_0733_0x084f18(a0, a1);
        case 734: return fde_func_0734_0x085014(a0, a1);
        case 735: return fde_func_0735_0x08525c(a0, a1);
        case 736: return fde_func_0736_0x08529c(a0, a1);
        case 737: return fde_func_0737_0x085370(a0, a1);
        case 738: return fde_func_0738_0x08559c(a0, a1);
        case 739: return fde_func_0739_0x085690(a0, a1);
        case 740: return fde_func_0740_0x085800(a0, a1);
        case 741: return fde_func_0741_0x085988(a0, a1);
        case 742: return fde_func_0742_0x085b1c(a0, a1);
        case 743: return fde_func_0743_0x085c50(a0, a1);
        case 744: return fde_func_0744_0x085cc4(a0, a1);
        case 745: return fde_func_0745_0x085d8c(a0, a1);
        case 746: return fde_func_0746_0x085e30(a0, a1);
        case 747: return fde_func_0747_0x085eec(a0, a1);
        case 748: return fde_func_0748_0x086110(a0, a1);
        case 749: return fde_func_0749_0x0861cc(a0, a1);
        case 750: return fde_func_0750_0x0862b0(a0, a1);
        case 751: return fde_func_0751_0x08638c(a0, a1);
        case 752: return fde_func_0752_0x0864d8(a0, a1);
        case 753: return fde_func_0753_0x0866e4(a0, a1);
        case 754: return fde_func_0754_0x0868ec(a0, a1);
        case 755: return fde_func_0755_0x086944(a0, a1);
        case 756: return fde_func_0756_0x0869a0(a0, a1);
        case 757: return fde_func_0757_0x086a88(a0, a1);
        case 758: return fde_func_0758_0x086cb0(a0, a1);
        case 759: return fde_func_0759_0x086d58(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com