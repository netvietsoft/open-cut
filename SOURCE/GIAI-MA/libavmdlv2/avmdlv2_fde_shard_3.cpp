// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 3/5 for libavmdlv2.so
// Phân mảnh Hàm AArch64 C++17 sạch 3/5 cho libavmdlv2.so
// Covers .text function indices [760 .. 1139] out of 1900 total functions
// Bao phủ chỉ số hàm .text [760 .. 1139] trên tổng số 1900 hàm
// ============================================================================
#include "avmdlv2_core.h"

namespace com {
namespace ss {
namespace ttmio {

// Func #0760 | PC: 0x086dcc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0760 | Địa chỉ PC: 0x086dcc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x086dcc: D10283FF  sub      sp, sp, #0xa0
//   0x086dd0: F9002BF9  str      x25, [sp, #0x50]
//   0x086dd4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x086dd8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0760_0x086dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086dccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0761 | PC: 0x087250 | FDE: 0x148a38 | Size: 16 bytes
// Hàm #0761 | Địa chỉ PC: 0x087250 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x087250: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x087254: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x087258: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08725c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0761_0x087250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087250ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #0762 | PC: 0x087260 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0762 | Địa chỉ PC: 0x087260 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x087260: D11083FF  sub      sp, sp, #0x420
//   0x087264: D53BD055  mrs      x21, tpidr_el0
//   0x087268: F94016A8  ldr      x8, [x21, #0x28]
//   0x08726c: F81D83A8  stur     x8, [x29, #-0x28]
static inline uint64_t fde_func_0762_0x087260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087260ULL ^ (static_cast<uint64_t>(0xd11083ffULL) << 13);
    acc = (acc + a1 + 0xd53bd055ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0763 | PC: 0x0873f0 | FDE: 0x148a38 | Size: 236 bytes
// Hàm #0763 | Địa chỉ PC: 0x0873f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 236 bytes
//   0x0873f0: D101C3FF  sub      sp, sp, #0x70
//   0x0873f4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0873f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0873fc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0763_0x0873f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0873f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// Func #0764 | PC: 0x0874dc | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0764 | Địa chỉ PC: 0x0874dc | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0874dc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0874e0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0874e4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0874e8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0764_0x0874dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0874dcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0765 | PC: 0x0874f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0765 | Địa chỉ PC: 0x0874f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0874f8: D11243FF  sub      sp, sp, #0x490
//   0x0874fc: D53BD05C  mrs      x28, tpidr_el0
//   0x087500: F9401788  ldr      x8, [x28, #0x28]
//   0x087504: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_0765_0x0874f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0874f8ULL ^ (static_cast<uint64_t>(0xd11243ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05cULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0766 | PC: 0x0877d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0766 | Địa chỉ PC: 0x0877d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0877d0: D10103FF  sub      sp, sp, #0x40
//   0x0877d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0877d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0877dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0766_0x0877d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0877d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0767 | PC: 0x0878e4 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0767 | Địa chỉ PC: 0x0878e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0878e4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0878e8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0878ec: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0878f0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0767_0x0878e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0878e4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0768 | PC: 0x087900 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0768 | Địa chỉ PC: 0x087900 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x087900: D11103FF  sub      sp, sp, #0x440
//   0x087904: D53BD05C  mrs      x28, tpidr_el0
//   0x087908: F9401788  ldr      x8, [x28, #0x28]
//   0x08790c: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_0768_0x087900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087900ULL ^ (static_cast<uint64_t>(0xd11103ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05cULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0769 | PC: 0x087d64 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #0769 | Địa chỉ PC: 0x087d64 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x087d64: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x087d68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x087d6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x087d70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0769_0x087d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087d64ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #0770 | PC: 0x087e48 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0770 | Địa chỉ PC: 0x087e48 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x087e48: D10103FF  sub      sp, sp, #0x40
//   0x087e4c: F90013F3  str      x19, [sp, #0x20]
//   0x087e50: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x087e54: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0770_0x087e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087e48ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0771 | PC: 0x087efc | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0771 | Địa chỉ PC: 0x087efc | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x087efc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x087f00: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x087f04: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x087f08: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0771_0x087efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087efcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0772 | PC: 0x087f18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0772 | Địa chỉ PC: 0x087f18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x087f18: D11103FF  sub      sp, sp, #0x440
//   0x087f1c: D53BD05C  mrs      x28, tpidr_el0
//   0x087f20: F9401788  ldr      x8, [x28, #0x28]
//   0x087f24: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_0772_0x087f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087f18ULL ^ (static_cast<uint64_t>(0xd11103ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05cULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0773 | PC: 0x088240 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0773 | Địa chỉ PC: 0x088240 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x088240: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x088244: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x088248: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08824c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0773_0x088240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088240ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0774 | PC: 0x08825c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0774 | Địa chỉ PC: 0x08825c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08825c: D110C3FF  sub      sp, sp, #0x430
//   0x088260: D53BD059  mrs      x25, tpidr_el0
//   0x088264: F9401728  ldr      x8, [x25, #0x28]
//   0x088268: 2A0303F3  mov      w19, w3
static inline uint64_t fde_func_0774_0x08825c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08825cULL ^ (static_cast<uint64_t>(0xd110c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd059ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0775 | PC: 0x088528 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0775 | Địa chỉ PC: 0x088528 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x088528: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08852c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x088530: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x088534: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0775_0x088528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088528ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0776 | PC: 0x088544 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0776 | Địa chỉ PC: 0x088544 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x088544: D120C3FF  sub      sp, sp, #0x830
//   0x088548: D53BD05A  mrs      x26, tpidr_el0
//   0x08854c: F9401748  ldr      x8, [x26, #0x28]
//   0x088550: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_0776_0x088544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088544ULL ^ (static_cast<uint64_t>(0xd120c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0777 | PC: 0x088788 | FDE: 0x148a38 | Size: 248 bytes
// Hàm #0777 | Địa chỉ PC: 0x088788 | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x088788: D10143FF  sub      sp, sp, #0x50
//   0x08878c: F90013F5  str      x21, [sp, #0x20]
//   0x088790: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x088794: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0777_0x088788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088788ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #0778 | PC: 0x088880 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0778 | Địa chỉ PC: 0x088880 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x088880: D10203FF  sub      sp, sp, #0x80
//   0x088884: F90023F7  str      x23, [sp, #0x40]
//   0x088888: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x08888c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0778_0x088880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088880ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0779 | PC: 0x088abc | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0779 | Địa chỉ PC: 0x088abc | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x088abc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x088ac0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x088ac4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x088ac8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0779_0x088abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088abcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0780 | PC: 0x088ad8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0780 | Địa chỉ PC: 0x088ad8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x088ad8: D11203FF  sub      sp, sp, #0x480
//   0x088adc: D53BD05C  mrs      x28, tpidr_el0
//   0x088ae0: F9401788  ldr      x8, [x28, #0x28]
//   0x088ae4: 9100C013  add      x19, x0, #0x30
static inline uint64_t fde_func_0780_0x088ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088ad8ULL ^ (static_cast<uint64_t>(0xd11203ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05cULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0781 | PC: 0x088de8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0781 | Địa chỉ PC: 0x088de8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x088de8: D10203FF  sub      sp, sp, #0x80
//   0x088dec: F9002BF5  str      x21, [sp, #0x50]
//   0x088df0: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x088df4: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0781_0x088de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088de8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0782 | PC: 0x088fa0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0782 | Địa chỉ PC: 0x088fa0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x088fa0: D10283FF  sub      sp, sp, #0xa0
//   0x088fa4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x088fa8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x088fac: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0782_0x088fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088fa0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0783 | PC: 0x0891f0 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0783 | Địa chỉ PC: 0x0891f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0891f0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0891f4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0891f8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0891fc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0783_0x0891f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0891f0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0784 | PC: 0x08920c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0784 | Địa chỉ PC: 0x08920c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08920c: D12183FF  sub      sp, sp, #0x860
//   0x089210: B9001FFF  str      wzr, [sp, #0x1c]
//   0x089214: D53BD049  mrs      x9, tpidr_el0
//   0x089218: F90013E9  str      x9, [sp, #0x20]
static inline uint64_t fde_func_0784_0x08920c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08920cULL ^ (static_cast<uint64_t>(0xd12183ffULL) << 13);
    acc = (acc + a1 + 0xb9001fffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0785 | PC: 0x0894c4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0785 | Địa chỉ PC: 0x0894c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0894c4: D10103FF  sub      sp, sp, #0x40
//   0x0894c8: F9000BF5  str      x21, [sp, #0x10]
//   0x0894cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0894d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0785_0x0894c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0894c4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0786 | PC: 0x089660 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0786 | Địa chỉ PC: 0x089660 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x089660: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x089664: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x089668: 910043FD  add      x29, sp, #0x10
//   0x08966c: B9402408  ldr      w8, [x0, #0x24]
static inline uint64_t fde_func_0786_0x089660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089660ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0787 | PC: 0x089704 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0787 | Địa chỉ PC: 0x089704 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x089704: D10283FF  sub      sp, sp, #0xa0
//   0x089708: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x08970c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x089710: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0787_0x089704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089704ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0788 | PC: 0x089b94 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0788 | Địa chỉ PC: 0x089b94 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x089b94: D102C3FF  sub      sp, sp, #0xb0
//   0x089b98: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x089b9c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x089ba0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0788_0x089b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089b94ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0789 | PC: 0x089f9c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0789 | Địa chỉ PC: 0x089f9c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x089f9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x089fa0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x089fa4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x089fa8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0789_0x089f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089f9cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0790 | PC: 0x08a114 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0790 | Địa chỉ PC: 0x08a114 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08a114: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x08a118: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08a11c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08a120: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0790_0x08a114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a114ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0791 | PC: 0x08a314 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #0791 | Địa chỉ PC: 0x08a314 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x08a314: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a318: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a31c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a320: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0791_0x08a314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a314ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0792 | PC: 0x08a3bc | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0792 | Địa chỉ PC: 0x08a3bc | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x08a3bc: D102C3FF  sub      sp, sp, #0xb0
//   0x08a3c0: F9003BF7  str      x23, [sp, #0x70]
//   0x08a3c4: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x08a3c8: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0792_0x08a3bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a3bcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0793 | PC: 0x08a488 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0793 | Địa chỉ PC: 0x08a488 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x08a488: D102C3FF  sub      sp, sp, #0xb0
//   0x08a48c: F9003BF7  str      x23, [sp, #0x70]
//   0x08a490: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x08a494: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0793_0x08a488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a488ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0794 | PC: 0x08a55c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0794 | Địa chỉ PC: 0x08a55c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08a55c: D10143FF  sub      sp, sp, #0x50
//   0x08a560: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08a564: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08a568: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0794_0x08a55c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a55cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0795 | PC: 0x08a67c | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0795 | Địa chỉ PC: 0x08a67c | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x08a67c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a680: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a684: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a688: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0795_0x08a67c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a67cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0796 | PC: 0x08a6e8 | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0796 | Địa chỉ PC: 0x08a6e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x08a6e8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a6ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a6f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a6f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0796_0x08a6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a6e8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0797 | PC: 0x08a7dc | FDE: 0x148a38 | Size: 232 bytes
// Hàm #0797 | Địa chỉ PC: 0x08a7dc | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x08a7dc: D10143FF  sub      sp, sp, #0x50
//   0x08a7e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08a7e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08a7e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0797_0x08a7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a7dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #0798 | PC: 0x08a8c4 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0798 | Địa chỉ PC: 0x08a8c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x08a8c4: D10183FF  sub      sp, sp, #0x60
//   0x08a8c8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x08a8cc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x08a8d0: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0798_0x08a8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a8c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0799 | PC: 0x08a92c | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0799 | Địa chỉ PC: 0x08a92c | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x08a92c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a930: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a934: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a938: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0799_0x08a92c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a92cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0800 | PC: 0x08a9e8 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0800 | Địa chỉ PC: 0x08a9e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x08a9e8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a9ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a9f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a9f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0800_0x08a9e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a9e8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0801 | PC: 0x08aa88 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0801 | Địa chỉ PC: 0x08aa88 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x08aa88: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08aa8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08aa90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08aa94: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0801_0x08aa88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08aa88ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0802 | PC: 0x08ab34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0802 | Địa chỉ PC: 0x08ab34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08ab34: D10183FF  sub      sp, sp, #0x60
//   0x08ab38: F9001BF5  str      x21, [sp, #0x30]
//   0x08ab3c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x08ab40: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0802_0x08ab34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ab34ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0803 | PC: 0x08ac50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0803 | Địa chỉ PC: 0x08ac50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08ac50: D10203FF  sub      sp, sp, #0x80
//   0x08ac54: F9002BF5  str      x21, [sp, #0x50]
//   0x08ac58: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x08ac5c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0803_0x08ac50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ac50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0804 | PC: 0x08aef8 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0804 | Địa chỉ PC: 0x08aef8 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x08aef8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08aefc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08af00: 910043FD  add      x29, sp, #0x10
//   0x08af04: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0804_0x08aef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08aef8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0805 | PC: 0x08af58 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0805 | Địa chỉ PC: 0x08af58 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x08af58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08af5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08af60: 910043FD  add      x29, sp, #0x10
//   0x08af64: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0805_0x08af58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08af58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0806 | PC: 0x08af98 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #0806 | Địa chỉ PC: 0x08af98 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x08af98: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08af9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08afa0: 910043FD  add      x29, sp, #0x10
//   0x08afa4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0806_0x08af98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08af98ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0807 | PC: 0x08b050 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0807 | Địa chỉ PC: 0x08b050 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x08b050: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08b054: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08b058: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08b05c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0807_0x08b050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b050ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0808 | PC: 0x08b0b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0808 | Địa chỉ PC: 0x08b0b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08b0b8: D10103FF  sub      sp, sp, #0x40
//   0x08b0bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08b0c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08b0c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0808_0x08b0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b0b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0809 | PC: 0x08b234 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0809 | Địa chỉ PC: 0x08b234 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x08b234: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08b238: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08b23c: 910043FD  add      x29, sp, #0x10
//   0x08b240: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0809_0x08b234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b234ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0810 | PC: 0x08b284 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0810 | Địa chỉ PC: 0x08b284 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08b284: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08b288: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08b28c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08b290: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0810_0x08b284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b284ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0811 | PC: 0x08b5ac | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0811 | Địa chỉ PC: 0x08b5ac | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x08b5ac: D10103FF  sub      sp, sp, #0x40
//   0x08b5b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08b5b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08b5b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0811_0x08b5ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b5acULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0812 | PC: 0x08b630 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0812 | Địa chỉ PC: 0x08b630 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08b630: D10143FF  sub      sp, sp, #0x50
//   0x08b634: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08b638: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x08b63c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0812_0x08b630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b630ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0813 | PC: 0x08b9d0 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #0813 | Địa chỉ PC: 0x08b9d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x08b9d0: D10103FF  sub      sp, sp, #0x40
//   0x08b9d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08b9d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08b9dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0813_0x08b9d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b9d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #0814 | PC: 0x08bab4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0814 | Địa chỉ PC: 0x08bab4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08bab4: D10283FF  sub      sp, sp, #0xa0
//   0x08bab8: F90023FB  str      x27, [sp, #0x40]
//   0x08babc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x08bac0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0814_0x08bab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bab4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0815 | PC: 0x08bd18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0815 | Địa chỉ PC: 0x08bd18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08bd18: D10403FF  sub      sp, sp, #0x100
//   0x08bd1c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x08bd20: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x08bd24: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0815_0x08bd18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bd18ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0816 | PC: 0x08c970 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0816 | Địa chỉ PC: 0x08c970 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08c970: D10403FF  sub      sp, sp, #0x100
//   0x08c974: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x08c978: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x08c97c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0816_0x08c970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c970ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0817 | PC: 0x08d5f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0817 | Địa chỉ PC: 0x08d5f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08d5f0: D10103FF  sub      sp, sp, #0x40
//   0x08d5f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08d5f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08d5fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0817_0x08d5f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d5f0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0818 | PC: 0x08d734 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0818 | Địa chỉ PC: 0x08d734 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08d734: D101C3FF  sub      sp, sp, #0x70
//   0x08d738: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x08d73c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x08d740: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0818_0x08d734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d734ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0819 | PC: 0x08da60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0819 | Địa chỉ PC: 0x08da60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08da60: D10343FF  sub      sp, sp, #0xd0
//   0x08da64: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x08da68: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x08da6c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0819_0x08da60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08da60ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0820 | PC: 0x08e114 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0820 | Địa chỉ PC: 0x08e114 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08e114: D10343FF  sub      sp, sp, #0xd0
//   0x08e118: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x08e11c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x08e120: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0820_0x08e114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e114ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0821 | PC: 0x08e81c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0821 | Địa chỉ PC: 0x08e81c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08e81c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08e820: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08e824: 910043FD  add      x29, sp, #0x10
//   0x08e828: B40001C1  cbz      x1, #0x8e860
static inline uint64_t fde_func_0821_0x08e81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e81cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0822 | PC: 0x08e94c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0822 | Địa chỉ PC: 0x08e94c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08e94c: D10183FF  sub      sp, sp, #0x60
//   0x08e950: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x08e954: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08e958: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0822_0x08e94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e94cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0823 | PC: 0x08eaec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0823 | Địa chỉ PC: 0x08eaec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08eaec: D10143FF  sub      sp, sp, #0x50
//   0x08eaf0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08eaf4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08eaf8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0823_0x08eaec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08eaecULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0824 | PC: 0x08ee54 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0824 | Địa chỉ PC: 0x08ee54 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08ee54: D10243FF  sub      sp, sp, #0x90
//   0x08ee58: F90023F9  str      x25, [sp, #0x40]
//   0x08ee5c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x08ee60: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0824_0x08ee54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ee54ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0825 | PC: 0x08f184 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0825 | Địa chỉ PC: 0x08f184 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08f184: D101C3FF  sub      sp, sp, #0x70
//   0x08f188: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x08f18c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x08f190: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0825_0x08f184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f184ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0826 | PC: 0x08f410 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0826 | Địa chỉ PC: 0x08f410 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08f410: D10183FF  sub      sp, sp, #0x60
//   0x08f414: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08f418: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x08f41c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0826_0x08f410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f410ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0827 | PC: 0x08f5f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0827 | Địa chỉ PC: 0x08f5f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08f5f0: D10203FF  sub      sp, sp, #0x80
//   0x08f5f4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x08f5f8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x08f5fc: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0827_0x08f5f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f5f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0828 | PC: 0x08f748 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0828 | Địa chỉ PC: 0x08f748 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08f748: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08f74c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08f750: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08f754: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0828_0x08f748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f748ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0829 | PC: 0x08f888 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0829 | Địa chỉ PC: 0x08f888 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08f888: D10243FF  sub      sp, sp, #0x90
//   0x08f88c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x08f890: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08f894: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0829_0x08f888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f888ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0830 | PC: 0x08fdf4 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0830 | Địa chỉ PC: 0x08fdf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x08fdf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08fdf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08fdfc: 910043FD  add      x29, sp, #0x10
//   0x08fe00: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0830_0x08fdf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fdf4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0831 | PC: 0x08fec8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0831 | Địa chỉ PC: 0x08fec8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x08fec8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x08fecc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08fed0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08fed4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0831_0x08fec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fec8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0832 | PC: 0x09005c | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0832 | Địa chỉ PC: 0x09005c | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x09005c: D10103FF  sub      sp, sp, #0x40
//   0x090060: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x090064: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x090068: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0832_0x09005c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09005cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0833 | PC: 0x090124 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0833 | Địa chỉ PC: 0x090124 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x090124: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x090128: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09012c: 910043FD  add      x29, sp, #0x10
//   0x090130: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0833_0x090124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090124ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0834 | PC: 0x0901d8 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #0834 | Địa chỉ PC: 0x0901d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x0901d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0901dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0901e0: 910043FD  add      x29, sp, #0x10
//   0x0901e4: 9100C014  add      x20, x0, #0x30
static inline uint64_t fde_func_0834_0x0901d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0901d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #0835 | PC: 0x090214 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0835 | Địa chỉ PC: 0x090214 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x090214: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x090218: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09021c: 910043FD  add      x29, sp, #0x10
//   0x090220: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_0835_0x090214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090214ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0836 | PC: 0x09035c | FDE: 0x148a38 | Size: 176 bytes
// Hàm #0836 | Địa chỉ PC: 0x09035c | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x09035c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x090360: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x090364: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x090368: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0836_0x09035c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09035cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #0837 | PC: 0x09040c | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0837 | Địa chỉ PC: 0x09040c | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x09040c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x090410: 910003FD  mov      x29, sp
//   0x090414: 91022000  add      x0, x0, #0x88
//   0x090418: 94018723  bl       #0xf20a4
static inline uint64_t fde_func_0837_0x09040c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09040cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0838 | PC: 0x090494 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0838 | Địa chỉ PC: 0x090494 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x090494: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x090498: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09049c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0904a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0838_0x090494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090494ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0839 | PC: 0x090550 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0839 | Địa chỉ PC: 0x090550 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x090550: D10183FF  sub      sp, sp, #0x60
//   0x090554: F9000BF9  str      x25, [sp, #0x10]
//   0x090558: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09055c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0839_0x090550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090550ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0840 | PC: 0x090740 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0840 | Địa chỉ PC: 0x090740 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x090740: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x090744: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x090748: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09074c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0840_0x090740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090740ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0841 | PC: 0x0909dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0841 | Địa chỉ PC: 0x0909dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0909dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0909e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0909e4: 910043FD  add      x29, sp, #0x10
//   0x0909e8: B940D008  ldr      w8, [x0, #0xd0]
static inline uint64_t fde_func_0841_0x0909dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0909dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0842 | PC: 0x090b64 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0842 | Địa chỉ PC: 0x090b64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x090b64: D10343FF  sub      sp, sp, #0xd0
//   0x090b68: F9004BF7  str      x23, [sp, #0x90]
//   0x090b6c: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x090b70: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0842_0x090b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090b64ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0843 | PC: 0x090d8c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0843 | Địa chỉ PC: 0x090d8c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x090d8c: D10483FF  sub      sp, sp, #0x120
//   0x090d90: F9006BFC  str      x28, [sp, #0xd0]
//   0x090d94: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x090d98: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_0843_0x090d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090d8cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0844 | PC: 0x091224 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0844 | Địa chỉ PC: 0x091224 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x091224: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x091228: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09122c: 910043FD  add      x29, sp, #0x10
//   0x091230: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0844_0x091224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091224ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0845 | PC: 0x0915f8 | FDE: 0x148a38 | Size: 216 bytes
// Hàm #0845 | Địa chỉ PC: 0x0915f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x0915f8: D10103FF  sub      sp, sp, #0x40
//   0x0915fc: F9000BF5  str      x21, [sp, #0x10]
//   0x091600: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x091604: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0845_0x0915f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0915f8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #0846 | PC: 0x0916d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0846 | Địa chỉ PC: 0x0916d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0916d0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0916d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0916d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0916dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0846_0x0916d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0916d0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0847 | PC: 0x091820 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0847 | Địa chỉ PC: 0x091820 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x091820: D10183FF  sub      sp, sp, #0x60
//   0x091824: A902D7FF  stp      xzr, x21, [sp, #0x28]
//   0x091828: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09182c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0847_0x091820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091820ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa902d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0848 | PC: 0x0919a8 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #0848 | Địa chỉ PC: 0x0919a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x0919a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0919ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0919b0: 910043FD  add      x29, sp, #0x10
//   0x0919b4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0848_0x0919a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0919a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #0849 | PC: 0x0919e4 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #0849 | Địa chỉ PC: 0x0919e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0919e4: D10143FF  sub      sp, sp, #0x50
//   0x0919e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0919ec: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0919f0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0849_0x0919e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0919e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #0850 | PC: 0x091acc | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0850 | Địa chỉ PC: 0x091acc | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x091acc: D10103FF  sub      sp, sp, #0x40
//   0x091ad0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x091ad4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x091ad8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0850_0x091acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091accULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0851 | PC: 0x091bc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0851 | Địa chỉ PC: 0x091bc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x091bc0: D10103FF  sub      sp, sp, #0x40
//   0x091bc4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x091bc8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x091bcc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0851_0x091bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091bc0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0852 | PC: 0x091cdc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0852 | Địa chỉ PC: 0x091cdc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x091cdc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x091ce0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x091ce4: 910043FD  add      x29, sp, #0x10
//   0x091ce8: A940A014  ldp      x20, x8, [x0, #8]
static inline uint64_t fde_func_0852_0x091cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091cdcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0853 | PC: 0x091fec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0853 | Địa chỉ PC: 0x091fec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x091fec: D10183FF  sub      sp, sp, #0x60
//   0x091ff0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x091ff4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x091ff8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0853_0x091fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091fecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0854 | PC: 0x092184 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0854 | Địa chỉ PC: 0x092184 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x092184: D10203FF  sub      sp, sp, #0x80
//   0x092188: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x09218c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x092190: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0854_0x092184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092184ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0855 | PC: 0x092540 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0855 | Địa chỉ PC: 0x092540 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x092540: D10203FF  sub      sp, sp, #0x80
//   0x092544: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x092548: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x09254c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0855_0x092540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092540ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0856 | PC: 0x09280c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0856 | Địa chỉ PC: 0x09280c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09280c: D10103FF  sub      sp, sp, #0x40
//   0x092810: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x092814: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x092818: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0856_0x09280c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09280cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0857 | PC: 0x0929cc | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0857 | Địa chỉ PC: 0x0929cc | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x0929cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0929d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0929d4: 910043FD  add      x29, sp, #0x10
//   0x0929d8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0857_0x0929cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0929ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0858 | PC: 0x092a38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0858 | Địa chỉ PC: 0x092a38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x092a38: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x092a3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x092a40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x092a44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0858_0x092a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092a38ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0859 | PC: 0x092bdc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0859 | Địa chỉ PC: 0x092bdc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x092bdc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x092be0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092be4: 910043FD  add      x29, sp, #0x10
//   0x092be8: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_0859_0x092bdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092bdcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0860 | PC: 0x0930c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0860 | Địa chỉ PC: 0x0930c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0930c0: D10243FF  sub      sp, sp, #0x90
//   0x0930c4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0930c8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0930cc: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0860_0x0930c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0930c0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0861 | PC: 0x0933d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0861 | Địa chỉ PC: 0x0933d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0933d8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0933dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0933e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0933e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0861_0x0933d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0933d8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0862 | PC: 0x09395c | FDE: 0x148a38 | Size: 248 bytes
// Hàm #0862 | Địa chỉ PC: 0x09395c | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x09395c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x093960: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093964: 910043FD  add      x29, sp, #0x10
//   0x093968: 90000648  adrp     x8, #0x15b000
static inline uint64_t fde_func_0862_0x09395c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09395cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #0863 | PC: 0x093a54 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0863 | Địa chỉ PC: 0x093a54 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x093a54: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x093a58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x093a5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x093a60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0863_0x093a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093a54ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0864 | PC: 0x093cb0 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0864 | Địa chỉ PC: 0x093cb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x093cb0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x093cb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093cb8: 910043FD  add      x29, sp, #0x10
//   0x093cbc: B9414C08  ldr      w8, [x0, #0x14c]
static inline uint64_t fde_func_0864_0x093cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093cb0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0865 | PC: 0x093d48 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0865 | Địa chỉ PC: 0x093d48 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x093d48: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x093d4c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x093d50: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x093d54: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0865_0x093d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093d48ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0866 | PC: 0x094038 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0866 | Địa chỉ PC: 0x094038 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x094038: D10243FF  sub      sp, sp, #0x90
//   0x09403c: F90023F9  str      x25, [sp, #0x40]
//   0x094040: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x094044: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0866_0x094038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094038ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0867 | PC: 0x094790 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0867 | Địa chỉ PC: 0x094790 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x094790: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094794: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094798: 910043FD  add      x29, sp, #0x10
//   0x09479c: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0867_0x094790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094790ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0868 | PC: 0x09489c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0868 | Địa chỉ PC: 0x09489c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09489c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0948a0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0948a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0948a8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0868_0x09489c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09489cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0869 | PC: 0x0949f8 | FDE: 0x148a38 | Size: 216 bytes
// Hàm #0869 | Địa chỉ PC: 0x0949f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x0949f8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0949fc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x094a00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x094a04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0869_0x0949f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0949f8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #0870 | PC: 0x094ad0 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0870 | Địa chỉ PC: 0x094ad0 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x094ad0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x094ad4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x094ad8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x094adc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0870_0x094ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094ad0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0871 | PC: 0x094b9c | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0871 | Địa chỉ PC: 0x094b9c | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x094b9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x094ba0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x094ba4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x094ba8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0871_0x094b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094b9cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0872 | PC: 0x094be8 | FDE: 0x148a38 | Size: 48 bytes
// Hàm #0872 | Địa chỉ PC: 0x094be8 | Địa chỉ FDE: 0x148a38 | Kích thước: 48 bytes
//   0x094be8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094bec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094bf0: 910043FD  add      x29, sp, #0x10
//   0x094bf4: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0872_0x094be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094be8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// Func #0873 | PC: 0x094c18 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0873 | Địa chỉ PC: 0x094c18 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x094c18: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x094c1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x094c20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x094c24: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0873_0x094c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094c18ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0874 | PC: 0x094c90 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0874 | Địa chỉ PC: 0x094c90 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x094c90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094c94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094c98: 910043FD  add      x29, sp, #0x10
//   0x094c9c: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0874_0x094c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094c90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0875 | PC: 0x094d0c | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0875 | Địa chỉ PC: 0x094d0c | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x094d0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094d10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094d14: 910043FD  add      x29, sp, #0x10
//   0x094d18: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_0875_0x094d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094d0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0876 | PC: 0x094d70 | FDE: 0x148a38 | Size: 176 bytes
// Hàm #0876 | Địa chỉ PC: 0x094d70 | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x094d70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094d74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094d78: 910043FD  add      x29, sp, #0x10
//   0x094d7c: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_0876_0x094d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094d70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #0877 | PC: 0x094e20 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0877 | Địa chỉ PC: 0x094e20 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x094e20: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x094e24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x094e28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x094e2c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0877_0x094e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094e20ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0878 | PC: 0x095200 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0878 | Địa chỉ PC: 0x095200 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x095200: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x095204: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x095208: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09520c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0878_0x095200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095200ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0879 | PC: 0x0954e4 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0879 | Địa chỉ PC: 0x0954e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0954e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0954e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0954ec: 910043FD  add      x29, sp, #0x10
//   0x0954f0: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_0879_0x0954e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0954e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0880 | PC: 0x095540 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0880 | Địa chỉ PC: 0x095540 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x095540: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095544: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095548: 910043FD  add      x29, sp, #0x10
//   0x09554c: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_0880_0x095540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095540ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0881 | PC: 0x095844 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0881 | Địa chỉ PC: 0x095844 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x095844: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095848: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09584c: 910043FD  add      x29, sp, #0x10
//   0x095850: B940FC09  ldr      w9, [x0, #0xfc]
static inline uint64_t fde_func_0881_0x095844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095844ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0882 | PC: 0x0958cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0882 | Địa chỉ PC: 0x0958cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0958cc: D101C3FF  sub      sp, sp, #0x70
//   0x0958d0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0958d4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0958d8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0882_0x0958cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0958ccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0883 | PC: 0x095b04 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0883 | Địa chỉ PC: 0x095b04 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x095b04: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x095b08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x095b0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x095b10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0883_0x095b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095b04ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0884 | PC: 0x095b5c | FDE: 0x148a38 | Size: 232 bytes
// Hàm #0884 | Địa chỉ PC: 0x095b5c | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x095b5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x095b60: 910003FD  mov      x29, sp
//   0x095b64: B9408008  ldr      w8, [x0, #0x80]
//   0x095b68: 121F7908  and      w8, w8, #0xfffffffe
static inline uint64_t fde_func_0884_0x095b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095b5cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #0885 | PC: 0x095c44 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0885 | Địa chỉ PC: 0x095c44 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x095c44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095c48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095c4c: 910043FD  add      x29, sp, #0x10
//   0x095c50: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0885_0x095c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0886 | PC: 0x095c7c | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0886 | Địa chỉ PC: 0x095c7c | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x095c7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095c80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095c84: 910043FD  add      x29, sp, #0x10
//   0x095c88: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0886_0x095c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0887 | PC: 0x095cb4 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0887 | Địa chỉ PC: 0x095cb4 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x095cb4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095cb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095cbc: 910043FD  add      x29, sp, #0x10
//   0x095cc0: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_0887_0x095cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095cb4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0888 | PC: 0x095d60 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0888 | Địa chỉ PC: 0x095d60 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x095d60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095d64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095d68: 910043FD  add      x29, sp, #0x10
//   0x095d6c: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0888_0x095d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095d60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0889 | PC: 0x095ddc | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0889 | Địa chỉ PC: 0x095ddc | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x095ddc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095de0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095de4: 910043FD  add      x29, sp, #0x10
//   0x095de8: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0889_0x095ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095ddcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0890 | PC: 0x095e14 | FDE: 0x148a38 | Size: 240 bytes
// Hàm #0890 | Địa chỉ PC: 0x095e14 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x095e14: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x095e18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x095e1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x095e20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0890_0x095e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095e14ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #0891 | PC: 0x095f04 | FDE: 0x148a38 | Size: 208 bytes
// Hàm #0891 | Địa chỉ PC: 0x095f04 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x095f04: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x095f08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x095f0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x095f10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0891_0x095f04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095f04ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0892 | PC: 0x095fd4 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0892 | Địa chỉ PC: 0x095fd4 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x095fd4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095fd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095fdc: 910043FD  add      x29, sp, #0x10
//   0x095fe0: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0892_0x095fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095fd4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0893 | PC: 0x096014 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0893 | Địa chỉ PC: 0x096014 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x096014: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x096018: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09601c: 910043FD  add      x29, sp, #0x10
//   0x096020: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_0893_0x096014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096014ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0894 | PC: 0x096150 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0894 | Địa chỉ PC: 0x096150 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x096150: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x096154: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096158: 910043FD  add      x29, sp, #0x10
//   0x09615c: F9404401  ldr      x1, [x0, #0x88]
static inline uint64_t fde_func_0894_0x096150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096150ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0895 | PC: 0x096268 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0895 | Địa chỉ PC: 0x096268 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x096268: D10243FF  sub      sp, sp, #0x90
//   0x09626c: F90023F9  str      x25, [sp, #0x40]
//   0x096270: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x096274: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0895_0x096268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096268ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0896 | PC: 0x096920 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0896 | Địa chỉ PC: 0x096920 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x096920: D10243FF  sub      sp, sp, #0x90
//   0x096924: A9037FFB  stp      x27, xzr, [sp, #0x30]
//   0x096928: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x09692c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0896_0x096920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096920ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9037ffbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0897 | PC: 0x096e64 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0897 | Địa chỉ PC: 0x096e64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x096e64: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x096e68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x096e6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x096e70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0897_0x096e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096e64ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0898 | PC: 0x0970b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0898 | Địa chỉ PC: 0x0970b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0970b4: D10283FF  sub      sp, sp, #0xa0
//   0x0970b8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0970bc: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0970c0: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0898_0x0970b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0970b4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0899 | PC: 0x097244 | FDE: 0x148a38 | Size: 4 bytes
// Hàm #0899 | Địa chỉ PC: 0x097244 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x097244: D14023FF  sub      sp, sp, #8, lsl #12
static inline uint64_t fde_func_0899_0x097244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097244ULL ^ (static_cast<uint64_t>(0xd14023ffULL) << 13);
    acc = (acc + a1 + 0xd10043ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0900 | PC: 0x097248 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0900 | Địa chỉ PC: 0x097248 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x097248: D10043FF  sub      sp, sp, #0x10
//   0x09724c: D53BD057  mrs      x23, tpidr_el0
//   0x097250: F94016E8  ldr      x8, [x23, #0x28]
//   0x097254: F81B83A8  stur     x8, [x29, #-0x48]
static inline uint64_t fde_func_0900_0x097248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097248ULL ^ (static_cast<uint64_t>(0xd10043ffULL) << 13);
    acc = (acc + a1 + 0xd53bd057ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0901 | PC: 0x097370 | FDE: 0x148a38 | Size: 68 bytes
// Hàm #0901 | Địa chỉ PC: 0x097370 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x097370: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x097374: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097378: 910043FD  add      x29, sp, #0x10
//   0x09737c: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0901_0x097370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097370ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #0902 | PC: 0x0973b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0902 | Địa chỉ PC: 0x0973b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0973b4: D10103FF  sub      sp, sp, #0x40
//   0x0973b8: F90013F3  str      x19, [sp, #0x20]
//   0x0973bc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0973c0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0902_0x0973b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0973b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0903 | PC: 0x09752c | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0903 | Địa chỉ PC: 0x09752c | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x09752c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x097530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097534: 910043FD  add      x29, sp, #0x10
//   0x097538: F9401814  ldr      x20, [x0, #0x30]
static inline uint64_t fde_func_0903_0x09752c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09752cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0904 | PC: 0x0975d8 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0904 | Địa chỉ PC: 0x0975d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x0975d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0975dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0975e0: 910043FD  add      x29, sp, #0x10
//   0x0975e4: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0904_0x0975d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0975d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0905 | PC: 0x097610 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0905 | Địa chỉ PC: 0x097610 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x097610: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x097614: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097618: 910043FD  add      x29, sp, #0x10
//   0x09761c: 9102E014  add      x20, x0, #0xb8
static inline uint64_t fde_func_0905_0x097610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097610ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0906 | PC: 0x0978dc | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0906 | Địa chỉ PC: 0x0978dc | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x0978dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0978e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0978e4: 910043FD  add      x29, sp, #0x10
//   0x0978e8: 90000628  adrp     x8, #0x15b000
static inline uint64_t fde_func_0906_0x0978dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0978dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0907 | PC: 0x0979bc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0907 | Địa chỉ PC: 0x0979bc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0979bc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0979c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0979c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0979c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0907_0x0979bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0979bcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0908 | PC: 0x097b38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0908 | Địa chỉ PC: 0x097b38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x097b38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x097b3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097b40: 910043FD  add      x29, sp, #0x10
//   0x097b44: 91089008  add      x8, x0, #0x224
static inline uint64_t fde_func_0908_0x097b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097b38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0909 | PC: 0x097ea8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0909 | Địa chỉ PC: 0x097ea8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x097ea8: D100C3FF  sub      sp, sp, #0x30
//   0x097eac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x097eb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x097eb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0909_0x097ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097ea8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0910 | PC: 0x098028 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0910 | Địa chỉ PC: 0x098028 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x098028: D10143FF  sub      sp, sp, #0x50
//   0x09802c: F90013F5  str      x21, [sp, #0x20]
//   0x098030: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x098034: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0910_0x098028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098028ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0911 | PC: 0x098374 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0911 | Địa chỉ PC: 0x098374 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x098374: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098378: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09837c: 910043FD  add      x29, sp, #0x10
//   0x098380: F9413C08  ldr      x8, [x0, #0x278]
static inline uint64_t fde_func_0911_0x098374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098374ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0912 | PC: 0x0983c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0912 | Địa chỉ PC: 0x0983c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0983c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0983c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0983c8: 910043FD  add      x29, sp, #0x10
//   0x0983cc: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_0912_0x0983c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0983c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0913 | PC: 0x098578 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0913 | Địa chỉ PC: 0x098578 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x098578: D10183FF  sub      sp, sp, #0x60
//   0x09857c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x098580: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x098584: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0913_0x098578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098578ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0914 | PC: 0x09874c | FDE: 0x148a38 | Size: 184 bytes
// Hàm #0914 | Địa chỉ PC: 0x09874c | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x09874c: D10283FF  sub      sp, sp, #0xa0
//   0x098750: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x098754: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x098758: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0914_0x09874c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09874cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0915 | PC: 0x098804 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0915 | Địa chỉ PC: 0x098804 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x098804: D10143FF  sub      sp, sp, #0x50
//   0x098808: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09880c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x098810: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0915_0x098804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098804ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0916 | PC: 0x0989f4 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0916 | Địa chỉ PC: 0x0989f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0989f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0989f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0989fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x098a00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0916_0x0989f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0989f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0917 | PC: 0x098a40 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0917 | Địa chỉ PC: 0x098a40 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x098a40: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098a44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098a48: 910043FD  add      x29, sp, #0x10
//   0x098a4c: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0917_0x098a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098a40ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0918 | PC: 0x098a78 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0918 | Địa chỉ PC: 0x098a78 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x098a78: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x098a7c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x098a80: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x098a84: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0918_0x098a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098a78ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0919 | PC: 0x098b18 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0919 | Địa chỉ PC: 0x098b18 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x098b18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098b1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098b20: 910043FD  add      x29, sp, #0x10
//   0x098b24: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0919_0x098b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098b18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0920 | PC: 0x098b94 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #0920 | Địa chỉ PC: 0x098b94 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x098b94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098b98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098b9c: 910043FD  add      x29, sp, #0x10
//   0x098ba0: 9106C013  add      x19, x0, #0x1b0
static inline uint64_t fde_func_0920_0x098b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098b94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0921 | PC: 0x098c4c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0921 | Địa chỉ PC: 0x098c4c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x098c4c: D10143FF  sub      sp, sp, #0x50
//   0x098c50: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x098c54: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x098c58: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0921_0x098c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098c4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0922 | PC: 0x098fc4 | FDE: 0x148a38 | Size: 252 bytes
// Hàm #0922 | Địa chỉ PC: 0x098fc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 252 bytes
//   0x098fc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098fc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098fcc: 910043FD  add      x29, sp, #0x10
//   0x098fd0: 9106C013  add      x19, x0, #0x1b0
static inline uint64_t fde_func_0922_0x098fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098fc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Func #0923 | PC: 0x0990c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0923 | Địa chỉ PC: 0x0990c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0990c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0990c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0990c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0990cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0923_0x0990c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0990c0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0924 | PC: 0x0991c4 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0924 | Địa chỉ PC: 0x0991c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x0991c4: D10083FF  sub      sp, sp, #0x20
//   0x0991c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0991cc: 910043FD  add      x29, sp, #0x10
//   0x0991d0: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0924_0x0991c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0991c4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0925 | PC: 0x099228 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0925 | Địa chỉ PC: 0x099228 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x099228: D10183FF  sub      sp, sp, #0x60
//   0x09922c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x099230: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x099234: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0925_0x099228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099228ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0926 | PC: 0x099598 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0926 | Địa chỉ PC: 0x099598 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x099598: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09959c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0995a0: 910043FD  add      x29, sp, #0x10
//   0x0995a4: B941F409  ldr      w9, [x0, #0x1f4]
static inline uint64_t fde_func_0926_0x099598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099598ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0927 | PC: 0x099620 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0927 | Địa chỉ PC: 0x099620 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x099620: D10203FF  sub      sp, sp, #0x80
//   0x099624: F9001BF9  str      x25, [sp, #0x30]
//   0x099628: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x09962c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0927_0x099620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099620ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0928 | PC: 0x099894 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0928 | Địa chỉ PC: 0x099894 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x099894: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x099898: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09989c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0998a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0928_0x099894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099894ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0929 | PC: 0x0998ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0929 | Địa chỉ PC: 0x0998ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0998ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0998f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0998f4: 910043FD  add      x29, sp, #0x10
//   0x0998f8: B941A008  ldr      w8, [x0, #0x1a0]
static inline uint64_t fde_func_0929_0x0998ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0998ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0930 | PC: 0x0999f4 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0930 | Địa chỉ PC: 0x0999f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x0999f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0999f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0999fc: 910043FD  add      x29, sp, #0x10
//   0x099a00: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0930_0x0999f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0999f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0931 | PC: 0x099a2c | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0931 | Địa chỉ PC: 0x099a2c | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x099a2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099a30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099a34: 910043FD  add      x29, sp, #0x10
//   0x099a38: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0931_0x099a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099a2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0932 | PC: 0x099a64 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #0932 | Địa chỉ PC: 0x099a64 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x099a64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099a68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099a6c: 910043FD  add      x29, sp, #0x10
//   0x099a70: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0932_0x099a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099a64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #0933 | PC: 0x099a9c | FDE: 0x148a38 | Size: 208 bytes
// Hàm #0933 | Địa chỉ PC: 0x099a9c | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x099a9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x099aa0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x099aa4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x099aa8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0933_0x099a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099a9cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0934 | PC: 0x099b6c | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0934 | Địa chỉ PC: 0x099b6c | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x099b6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099b70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099b74: 910043FD  add      x29, sp, #0x10
//   0x099b78: 9106C013  add      x19, x0, #0x1b0
static inline uint64_t fde_func_0934_0x099b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099b6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0935 | PC: 0x099c08 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0935 | Địa chỉ PC: 0x099c08 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x099c08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099c0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099c10: 910043FD  add      x29, sp, #0x10
//   0x099c14: 9106C013  add      x19, x0, #0x1b0
static inline uint64_t fde_func_0935_0x099c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099c08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0936 | PC: 0x099c54 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #0936 | Địa chỉ PC: 0x099c54 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x099c54: D10103FF  sub      sp, sp, #0x40
//   0x099c58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x099c5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x099c60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0936_0x099c54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099c54ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #0937 | PC: 0x099d3c | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0937 | Địa chỉ PC: 0x099d3c | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x099d3c: D100C3FF  sub      sp, sp, #0x30
//   0x099d40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x099d44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x099d48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0937_0x099d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099d3cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0938 | PC: 0x099d8c | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0938 | Địa chỉ PC: 0x099d8c | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x099d8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099d90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099d94: 910043FD  add      x29, sp, #0x10
//   0x099d98: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0938_0x099d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099d8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0939 | PC: 0x099dcc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0939 | Địa chỉ PC: 0x099dcc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x099dcc: D10183FF  sub      sp, sp, #0x60
//   0x099dd0: A901DFFF  stp      xzr, x23, [sp, #0x18]
//   0x099dd4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x099dd8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0939_0x099dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099dccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa901dfffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0940 | PC: 0x099efc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0940 | Địa chỉ PC: 0x099efc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x099efc: D100C3FF  sub      sp, sp, #0x30
//   0x099f00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x099f04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x099f08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0940_0x099efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099efcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0941 | PC: 0x09a0b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0941 | Địa chỉ PC: 0x09a0b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09a0b8: D10143FF  sub      sp, sp, #0x50
//   0x09a0bc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09a0c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09a0c4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0941_0x09a0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a0b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0942 | PC: 0x09a22c | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0942 | Địa chỉ PC: 0x09a22c | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x09a22c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09a230: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09a234: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09a238: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0942_0x09a22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a22cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0943 | PC: 0x09a2f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0943 | Địa chỉ PC: 0x09a2f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09a2f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09a2f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09a2fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09a300: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0943_0x09a2f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a2f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0944 | PC: 0x09a590 | FDE: 0x148a38 | Size: 4 bytes
// Hàm #0944 | Địa chỉ PC: 0x09a590 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x09a590: D14023FF  sub      sp, sp, #8, lsl #12
static inline uint64_t fde_func_0944_0x09a590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a590ULL ^ (static_cast<uint64_t>(0xd14023ffULL) << 13);
    acc = (acc + a1 + 0xd10043ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0945 | PC: 0x09a594 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0945 | Địa chỉ PC: 0x09a594 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09a594: D10043FF  sub      sp, sp, #0x10
//   0x09a598: D53BD057  mrs      x23, tpidr_el0
//   0x09a59c: F94016E8  ldr      x8, [x23, #0x28]
//   0x09a5a0: F81B83A8  stur     x8, [x29, #-0x48]
static inline uint64_t fde_func_0945_0x09a594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a594ULL ^ (static_cast<uint64_t>(0xd10043ffULL) << 13);
    acc = (acc + a1 + 0xd53bd057ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0946 | PC: 0x09a6e8 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0946 | Địa chỉ PC: 0x09a6e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x09a6e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09a6ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09a6f0: 910043FD  add      x29, sp, #0x10
//   0x09a6f4: 9106C014  add      x20, x0, #0x1b0
static inline uint64_t fde_func_0946_0x09a6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a6e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0947 | PC: 0x09a760 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0947 | Địa chỉ PC: 0x09a760 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09a760: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x09a764: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09a768: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09a76c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0947_0x09a760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a760ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0948 | PC: 0x09a8f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0948 | Địa chỉ PC: 0x09a8f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09a8f8: D10343FF  sub      sp, sp, #0xd0
//   0x09a8fc: F9003BFB  str      x27, [sp, #0x70]
//   0x09a900: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x09a904: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0948_0x09a8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a8f8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0949 | PC: 0x09af1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0949 | Địa chỉ PC: 0x09af1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09af1c: D11103FF  sub      sp, sp, #0x440
//   0x09af20: AA0003F4  mov      x20, x0
//   0x09af24: D10123A0  sub      x0, x29, #0x48
//   0x09af28: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_0949_0x09af1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09af1cULL ^ (static_cast<uint64_t>(0xd11103ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0950 | PC: 0x09b530 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0950 | Địa chỉ PC: 0x09b530 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x09b530: D10183FF  sub      sp, sp, #0x60
//   0x09b534: F9001BF5  str      x21, [sp, #0x30]
//   0x09b538: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09b53c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0950_0x09b530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b530ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0951 | PC: 0x09b5f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0951 | Địa chỉ PC: 0x09b5f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09b5f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09b5fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b600: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b604: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0951_0x09b5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b5f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0952 | PC: 0x09b76c | FDE: 0x148a38 | Size: 216 bytes
// Hàm #0952 | Địa chỉ PC: 0x09b76c | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x09b76c: D10183FF  sub      sp, sp, #0x60
//   0x09b770: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09b774: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09b778: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0952_0x09b76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b76cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #0953 | PC: 0x09b844 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0953 | Địa chỉ PC: 0x09b844 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x09b844: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x09b848: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09b84c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09b850: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0953_0x09b844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b844ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0954 | PC: 0x09b860 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0954 | Địa chỉ PC: 0x09b860 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09b860: D11803FF  sub      sp, sp, #0x600
//   0x09b864: A9008BE0  stp      x0, x2, [sp, #8]
//   0x09b868: AA0103F3  mov      x19, x1
//   0x09b86c: D10203A0  sub      x0, x29, #0x80
static inline uint64_t fde_func_0954_0x09b860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b860ULL ^ (static_cast<uint64_t>(0xd11803ffULL) << 13);
    acc = (acc + a1 + 0xa9008be0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0955 | PC: 0x09c014 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0955 | Địa chỉ PC: 0x09c014 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09c014: D10103FF  sub      sp, sp, #0x40
//   0x09c018: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09c01c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09c020: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0955_0x09c014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c014ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0956 | PC: 0x09c1e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0956 | Địa chỉ PC: 0x09c1e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09c1e0: D10203FF  sub      sp, sp, #0x80
//   0x09c1e4: F90013FB  str      x27, [sp, #0x20]
//   0x09c1e8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x09c1ec: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0956_0x09c1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c1e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0957 | PC: 0x09c36c | FDE: 0x148a38 | Size: 248 bytes
// Hàm #0957 | Địa chỉ PC: 0x09c36c | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x09c36c: D10283FF  sub      sp, sp, #0xa0
//   0x09c370: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x09c374: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x09c378: 910243FD  add      x29, sp, #0x90
static inline uint64_t fde_func_0957_0x09c36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c36cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9084ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #0958 | PC: 0x09c464 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0958 | Địa chỉ PC: 0x09c464 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09c464: D10143FF  sub      sp, sp, #0x50
//   0x09c468: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09c46c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x09c470: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0958_0x09c464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c464ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0959 | PC: 0x09c648 | FDE: 0x148a38 | Size: 84 bytes
// Hàm #0959 | Địa chỉ PC: 0x09c648 | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x09c648: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c64c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c650: 910043FD  add      x29, sp, #0x10
//   0x09c654: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0959_0x09c648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c648ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #0960 | PC: 0x09c69c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0960 | Địa chỉ PC: 0x09c69c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09c69c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c6a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c6a4: 910043FD  add      x29, sp, #0x10
//   0x09c6a8: 90000614  adrp     x20, #0x15c000
static inline uint64_t fde_func_0960_0x09c69c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c69cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0961 | PC: 0x09c874 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0961 | Địa chỉ PC: 0x09c874 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09c874: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c878: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c87c: 910043FD  add      x29, sp, #0x10
//   0x09c880: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0961_0x09c874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c874ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0962 | PC: 0x09ca28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0962 | Địa chỉ PC: 0x09ca28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09ca28: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x09ca2c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09ca30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09ca34: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0962_0x09ca28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ca28ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0963 | PC: 0x09cbc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0963 | Địa chỉ PC: 0x09cbc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09cbc0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09cbc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09cbc8: 910043FD  add      x29, sp, #0x10
//   0x09cbcc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0963_0x09cbc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cbc0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0964 | PC: 0x09cd10 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0964 | Địa chỉ PC: 0x09cd10 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09cd10: D101C3FF  sub      sp, sp, #0x70
//   0x09cd14: F9001BF7  str      x23, [sp, #0x30]
//   0x09cd18: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09cd1c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0964_0x09cd10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cd10ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0965 | PC: 0x09cef0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0965 | Địa chỉ PC: 0x09cef0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09cef0: D10183FF  sub      sp, sp, #0x60
//   0x09cef4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09cef8: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x09cefc: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0965_0x09cef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cef0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0966 | PC: 0x09d100 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0966 | Địa chỉ PC: 0x09d100 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x09d100: D10183FF  sub      sp, sp, #0x60
//   0x09d104: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09d108: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x09d10c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0966_0x09d100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d100ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0967 | PC: 0x09d1c8 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #0967 | Địa chỉ PC: 0x09d1c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x09d1c8: D101C3FF  sub      sp, sp, #0x70
//   0x09d1cc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09d1d0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09d1d4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0967_0x09d1c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d1c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #0968 | PC: 0x09d2ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0968 | Địa chỉ PC: 0x09d2ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09d2ac: D10243FF  sub      sp, sp, #0x90
//   0x09d2b0: F90023F9  str      x25, [sp, #0x40]
//   0x09d2b4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x09d2b8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0968_0x09d2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d2acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0969 | PC: 0x09d588 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0969 | Địa chỉ PC: 0x09d588 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09d588: D102C3FF  sub      sp, sp, #0xb0
//   0x09d58c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x09d590: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x09d594: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0969_0x09d588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d588ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0970 | PC: 0x09d838 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0970 | Địa chỉ PC: 0x09d838 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09d838: D10203FF  sub      sp, sp, #0x80
//   0x09d83c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x09d840: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x09d844: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0970_0x09d838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d838ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0971 | PC: 0x09da40 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0971 | Địa chỉ PC: 0x09da40 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09da40: D104C3FF  sub      sp, sp, #0x130
//   0x09da44: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x09da48: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x09da4c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0971_0x09da40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09da40ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0972 | PC: 0x09e080 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0972 | Địa chỉ PC: 0x09e080 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09e080: D10143FF  sub      sp, sp, #0x50
//   0x09e084: F9000BF7  str      x23, [sp, #0x10]
//   0x09e088: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09e08c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0972_0x09e080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e080ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0973 | PC: 0x09e1a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0973 | Địa chỉ PC: 0x09e1a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09e1a8: D10143FF  sub      sp, sp, #0x50
//   0x09e1ac: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09e1b0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09e1b4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0973_0x09e1a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e1a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0974 | PC: 0x09e5a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0974 | Địa chỉ PC: 0x09e5a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09e5a8: D10683FF  sub      sp, sp, #0x1a0
//   0x09e5ac: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x09e5b0: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x09e5b4: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_0974_0x09e5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e5a8ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0975 | PC: 0x09eb54 | FDE: 0x148a38 | Size: 240 bytes
// Hàm #0975 | Địa chỉ PC: 0x09eb54 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x09eb54: D10143FF  sub      sp, sp, #0x50
//   0x09eb58: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09eb5c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09eb60: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0975_0x09eb54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09eb54ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #0976 | PC: 0x09ec44 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0976 | Địa chỉ PC: 0x09ec44 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09ec44: D10283FF  sub      sp, sp, #0xa0
//   0x09ec48: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x09ec4c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x09ec50: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0976_0x09ec44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ec44ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0977 | PC: 0x09f300 | FDE: 0x148a38 | Size: 248 bytes
// Hàm #0977 | Địa chỉ PC: 0x09f300 | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x09f300: D101C3FF  sub      sp, sp, #0x70
//   0x09f304: F90023F5  str      x21, [sp, #0x40]
//   0x09f308: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09f30c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0977_0x09f300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f300ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #0978 | PC: 0x09f3f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0978 | Địa chỉ PC: 0x09f3f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09f3f8: D10183FF  sub      sp, sp, #0x60
//   0x09f3fc: F9000BF9  str      x25, [sp, #0x10]
//   0x09f400: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09f404: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0978_0x09f3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f3f8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0979 | PC: 0x09f58c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0979 | Địa chỉ PC: 0x09f58c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09f58c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09f590: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09f594: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09f598: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0979_0x09f58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f58cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0980 | PC: 0x09f68c | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0980 | Địa chỉ PC: 0x09f68c | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x09f68c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09f690: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09f694: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09f698: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0980_0x09f68c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f68cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0981 | PC: 0x09f760 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0981 | Địa chỉ PC: 0x09f760 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x09f760: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09f764: 910003FD  mov      x29, sp
//   0x09f768: 97FE4C6E  bl       #0x32920
//   0x09f76c: 97FE4C85  bl       #0x32980
static inline uint64_t fde_func_0981_0x09f760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f760ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0982 | PC: 0x09f7d0 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0982 | Địa chỉ PC: 0x09f7d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x09f7d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09f7d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09f7d8: 910043FD  add      x29, sp, #0x10
//   0x09f7dc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0982_0x09f7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f7d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0983 | PC: 0x09f81c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0983 | Địa chỉ PC: 0x09f81c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09f81c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09f820: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09f824: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09f828: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0983_0x09f81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f81cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0984 | PC: 0x09fa98 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0984 | Địa chỉ PC: 0x09fa98 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x09fa98: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fa9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09faa0: 910043FD  add      x29, sp, #0x10
//   0x09faa4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0984_0x09fa98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fa98ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0985 | PC: 0x09fae4 | FDE: 0x148a38 | Size: 48 bytes
// Hàm #0985 | Địa chỉ PC: 0x09fae4 | Địa chỉ FDE: 0x148a38 | Kích thước: 48 bytes
//   0x09fae4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09fae8: 910003FD  mov      x29, sp
//   0x09faec: 97FE4B8D  bl       #0x32920
//   0x09faf0: 97FE4BA4  bl       #0x32980
static inline uint64_t fde_func_0985_0x09fae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fae4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// Func #0986 | PC: 0x09fb14 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0986 | Địa chỉ PC: 0x09fb14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09fb14: D100C3FF  sub      sp, sp, #0x30
//   0x09fb18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09fb1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09fb20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0986_0x09fb14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fb14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0987 | PC: 0x09fc24 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0987 | Địa chỉ PC: 0x09fc24 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x09fc24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fc28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09fc2c: 910043FD  add      x29, sp, #0x10
//   0x09fc30: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0987_0x09fc24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fc24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0988 | PC: 0x09fc80 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0988 | Địa chỉ PC: 0x09fc80 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09fc80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fc84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09fc88: 910043FD  add      x29, sp, #0x10
//   0x09fc8c: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0988_0x09fc80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fc80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0989 | PC: 0x09fe24 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0989 | Địa chỉ PC: 0x09fe24 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x09fe24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fe28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09fe2c: 910043FD  add      x29, sp, #0x10
//   0x09fe30: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0989_0x09fe24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fe24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0990 | PC: 0x09feb0 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0990 | Địa chỉ PC: 0x09feb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x09feb0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09feb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09feb8: 910043FD  add      x29, sp, #0x10
//   0x09febc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0990_0x09feb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09feb0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0991 | PC: 0x09fefc | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0991 | Địa chỉ PC: 0x09fefc | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x09fefc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09ff00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09ff04: 910043FD  add      x29, sp, #0x10
//   0x09ff08: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0991_0x09fefc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fefcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0992 | PC: 0x09ff80 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0992 | Địa chỉ PC: 0x09ff80 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x09ff80: D10183FF  sub      sp, sp, #0x60
//   0x09ff84: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09ff88: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09ff8c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0992_0x09ff80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ff80ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0993 | PC: 0x0a02cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0993 | Địa chỉ PC: 0x0a02cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a02cc: D101C3FF  sub      sp, sp, #0x70
//   0x0a02d0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a02d4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a02d8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0993_0x0a02cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a02ccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0994 | PC: 0x0a03cc | FDE: 0x148a38 | Size: 128 bytes
// Hàm #0994 | Địa chỉ PC: 0x0a03cc | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0a03cc: D10183FF  sub      sp, sp, #0x60
//   0x0a03d0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a03d4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0a03d8: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0994_0x0a03cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a03ccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0995 | PC: 0x0a044c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0995 | Địa chỉ PC: 0x0a044c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a044c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a0450: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a0454: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0458: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0995_0x0a044c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a044cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0996 | PC: 0x0a078c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0996 | Địa chỉ PC: 0x0a078c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a078c: D10103FF  sub      sp, sp, #0x40
//   0x0a0790: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0794: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a0798: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0996_0x0a078c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a078cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0997 | PC: 0x0a089c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0997 | Địa chỉ PC: 0x0a089c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a089c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a08a0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a08a4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a08a8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0997_0x0a089c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a089cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0998 | PC: 0x0a0adc | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0998 | Địa chỉ PC: 0x0a0adc | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0a0adc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a0ae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0ae4: 910043FD  add      x29, sp, #0x10
//   0x0a0ae8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0998_0x0a0adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0adcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0999 | PC: 0x0a0b54 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0999 | Địa chỉ PC: 0x0a0b54 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0a0b54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a0b58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0b5c: 910043FD  add      x29, sp, #0x10
//   0x0a0b60: F0000588  adrp     x8, #0x153000
static inline uint64_t fde_func_0999_0x0a0b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0b54ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1000 | PC: 0x0a0bf4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1000 | Địa chỉ PC: 0x0a0bf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a0bf4: D10183FF  sub      sp, sp, #0x60
//   0x0a0bf8: F9001BF5  str      x21, [sp, #0x30]
//   0x0a0bfc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a0c00: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1000_0x0a0bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0bf4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1001 | PC: 0x0a0d1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1001 | Địa chỉ PC: 0x0a0d1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a0d1c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a0d20: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a0d24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0d28: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1001_0x0a0d1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0d1cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1002 | PC: 0x0a0e28 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #1002 | Địa chỉ PC: 0x0a0e28 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x0a0e28: D10143FF  sub      sp, sp, #0x50
//   0x0a0e2c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a0e30: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a0e34: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1002_0x0a0e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0e28ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #1003 | PC: 0x0a0eac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1003 | Địa chỉ PC: 0x0a0eac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a0eac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a0eb0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a0eb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a0eb8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1003_0x0a0eac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0eacULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1004 | PC: 0x0a1258 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1004 | Địa chỉ PC: 0x0a1258 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a1258: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a125c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a1260: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a1264: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1004_0x0a1258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1258ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1005 | PC: 0x0a13d0 | FDE: 0x148a38 | Size: 208 bytes
// Hàm #1005 | Địa chỉ PC: 0x0a13d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x0a13d0: D10103FF  sub      sp, sp, #0x40
//   0x0a13d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a13d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a13dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1005_0x0a13d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a13d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #1006 | PC: 0x0a14a0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1006 | Địa chỉ PC: 0x0a14a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a14a0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a14a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a14a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a14ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1006_0x0a14a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a14a0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1007 | PC: 0x0a1718 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLRingBufferC1Emm]
// Hàm #1007 | Địa chỉ PC: 0x0a1718 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a1718: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a171c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a1720: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1724: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1007_0x0a1718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1718ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1008 | PC: 0x0a18a8 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #1008 | Địa chỉ PC: 0x0a18a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x0a18a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a18ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a18b0: 910043FD  add      x29, sp, #0x10
//   0x0a18b4: 9101C014  add      x20, x0, #0x70
static inline uint64_t fde_func_1008_0x0a18a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #1009 | PC: 0x0a1938 | FDE: 0x148a38 | Size: 236 bytes
// Hàm #1009 | Địa chỉ PC: 0x0a1938 | Địa chỉ FDE: 0x148a38 | Kích thước: 236 bytes
//   0x0a1938: D10103FF  sub      sp, sp, #0x40
//   0x0a193c: F9000BF5  str      x21, [sp, #0x10]
//   0x0a1940: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a1944: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1009_0x0a1938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1938ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// Func #1010 | PC: 0x0a1a24 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1010 | Địa chỉ PC: 0x0a1a24 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a1a24: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a1a28: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a1a2c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a1a30: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1010_0x0a1a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1a24ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1011 | PC: 0x0a1bfc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1011 | Địa chỉ PC: 0x0a1bfc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a1bfc: D10143FF  sub      sp, sp, #0x50
//   0x0a1c00: F9000BF7  str      x23, [sp, #0x10]
//   0x0a1c04: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a1c08: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1011_0x0a1bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1bfcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1012 | PC: 0x0a1dec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1012 | Địa chỉ PC: 0x0a1dec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a1dec: D10143FF  sub      sp, sp, #0x50
//   0x0a1df0: F9000BF7  str      x23, [sp, #0x10]
//   0x0a1df4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a1df8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1012_0x0a1dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1decULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1013 | PC: 0x0a20dc | FDE: 0x148a38 | Size: 248 bytes
// Hàm #1013 | Địa chỉ PC: 0x0a20dc | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x0a20dc: D101C3FF  sub      sp, sp, #0x70
//   0x0a20e0: F9000BFB  str      x27, [sp, #0x10]
//   0x0a20e4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0a20e8: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1013_0x0a20dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a20dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1014 | PC: 0x0a21d4 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio17MDLRingBufferPool13getRingBufferEi]
// Hàm #1014 | Địa chỉ PC: 0x0a21d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a21d4: D10183FF  sub      sp, sp, #0x60
//   0x0a21d8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a21dc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a21e0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1014_0x0a21d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a21d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1015 | PC: 0x0a232c | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio17MDLRingBufferPool17releaseRingBufferEPNS1_13MDLRingBufferE]
// Hàm #1015 | Địa chỉ PC: 0x0a232c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x0a232c: B4000E01  cbz      x1, #0xa24ec
static inline uint64_t fde_func_1015_0x0a232c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a232cULL ^ (static_cast<uint64_t>(0xb4000e01ULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1016 | PC: 0x0a2330 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1016 | Địa chỉ PC: 0x0a2330 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a2330: D10183FF  sub      sp, sp, #0x60
//   0x0a2334: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a2338: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a233c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1016_0x0a2330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2330ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1017 | PC: 0x0a24f4 | FDE: 0x148a38 | Size: 68 bytes
// Hàm #1017 | Địa chỉ PC: 0x0a24f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x0a24f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a24f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a24fc: 910043FD  add      x29, sp, #0x10
//   0x0a2500: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1017_0x0a24f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a24f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #1018 | PC: 0x0a2538 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #1018 | Địa chỉ PC: 0x0a2538 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0a2538: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a253c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2540: 910043FD  add      x29, sp, #0x10
//   0x0a2544: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1018_0x0a2538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2538ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1019 | PC: 0x0a2594 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1019 | Địa chỉ PC: 0x0a2594 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a2594: D10183FF  sub      sp, sp, #0x60
//   0x0a2598: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a259c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a25a0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1019_0x0a2594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2594ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1020 | PC: 0x0a272c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1020 | Địa chỉ PC: 0x0a272c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a272c: D10183FF  sub      sp, sp, #0x60
//   0x0a2730: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a2734: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a2738: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1020_0x0a272c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a272cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1021 | PC: 0x0a2a84 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #1021 | Địa chỉ PC: 0x0a2a84 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0a2a84: D10143FF  sub      sp, sp, #0x50
//   0x0a2a88: F9000BF7  str      x23, [sp, #0x10]
//   0x0a2a8c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a2a90: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1021_0x0a2a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2a84ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1022 | PC: 0x0a2b6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1022 | Địa chỉ PC: 0x0a2b6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a2b6c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0a2b70: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a2b74: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a2b78: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1022_0x0a2b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2b6cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1023 | PC: 0x0a2e5c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1023 | Địa chỉ PC: 0x0a2e5c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a2e5c: D10183FF  sub      sp, sp, #0x60
//   0x0a2e60: F9000BF9  str      x25, [sp, #0x10]
//   0x0a2e64: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a2e68: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1023_0x0a2e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2e5cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1024 | PC: 0x0a33b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1024 | Địa chỉ PC: 0x0a33b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a33b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a33bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a33c0: 910043FD  add      x29, sp, #0x10
//   0x0a33c4: 7100103F  cmp      w1, #4
static inline uint64_t fde_func_1024_0x0a33b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a33b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1025 | PC: 0x0a3534 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1025 | Địa chỉ PC: 0x0a3534 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a3534: D10103FF  sub      sp, sp, #0x40
//   0x0a3538: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a353c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a3540: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1025_0x0a3534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3534ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1026 | PC: 0x0a3718 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1026 | Địa chỉ PC: 0x0a3718 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a3718: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a371c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3720: 910043FD  add      x29, sp, #0x10
//   0x0a3724: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1026_0x0a3718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3718ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1027 | PC: 0x0a395c | FDE: 0x148a38 | Size: 212 bytes
// Hàm #1027 | Địa chỉ PC: 0x0a395c | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x0a395c: D10103FF  sub      sp, sp, #0x40
//   0x0a3960: F90013F3  str      x19, [sp, #0x20]
//   0x0a3964: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a3968: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1027_0x0a395c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a395cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1028 | PC: 0x0a3a30 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1028 | Địa chỉ PC: 0x0a3a30 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0a3a30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3a34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3a38: 910043FD  add      x29, sp, #0x10
//   0x0a3a3c: F9403C08  ldr      x8, [x0, #0x78]
static inline uint64_t fde_func_1028_0x0a3a30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3a30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1029 | PC: 0x0a3aa8 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #1029 | Địa chỉ PC: 0x0a3aa8 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x0a3aa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3aac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3ab0: 910043FD  add      x29, sp, #0x10
//   0x0a3ab4: 91002013  add      x19, x0, #8
static inline uint64_t fde_func_1029_0x0a3aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3aa8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #1030 | PC: 0x0a3b60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1030 | Địa chỉ PC: 0x0a3b60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a3b60: D10183FF  sub      sp, sp, #0x60
//   0x0a3b64: F90013F7  str      x23, [sp, #0x20]
//   0x0a3b68: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a3b6c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1030_0x0a3b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3b60ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1031 | PC: 0x0a3e28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1031 | Địa chỉ PC: 0x0a3e28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a3e28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3e2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3e30: 910043FD  add      x29, sp, #0x10
//   0x0a3e34: 3944A008  ldrb     w8, [x0, #0x128]
static inline uint64_t fde_func_1031_0x0a3e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3e28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1032 | PC: 0x0a3f34 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #1032 | Địa chỉ PC: 0x0a3f34 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x0a3f34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3f38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3f3c: 910043FD  add      x29, sp, #0x10
//   0x0a3f40: A9402428  ldp      x8, x9, [x1]
static inline uint64_t fde_func_1032_0x0a3f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3f34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1033 | PC: 0x0a3fbc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1033 | Địa chỉ PC: 0x0a3fbc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a3fbc: D10183FF  sub      sp, sp, #0x60
//   0x0a3fc0: F90013F7  str      x23, [sp, #0x20]
//   0x0a3fc4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a3fc8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1033_0x0a3fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3fbcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1034 | PC: 0x0a40e8 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #1034 | Địa chỉ PC: 0x0a40e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x0a40e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a40ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a40f0: 910043FD  add      x29, sp, #0x10
//   0x0a40f4: F9403C08  ldr      x8, [x0, #0x78]
static inline uint64_t fde_func_1034_0x0a40e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a40e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #1035 | PC: 0x0a41b4 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #1035 | Địa chỉ PC: 0x0a41b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x0a41b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a41b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a41bc: 910043FD  add      x29, sp, #0x10
//   0x0a41c0: 91002014  add      x20, x0, #8
static inline uint64_t fde_func_1035_0x0a41b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a41b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #1036 | PC: 0x0a4280 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1036 | Địa chỉ PC: 0x0a4280 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a4280: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a4284: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a4288: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a428c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1036_0x0a4280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4280ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1037 | PC: 0x0a4438 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1037 | Địa chỉ PC: 0x0a4438 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a4438: D10103FF  sub      sp, sp, #0x40
//   0x0a443c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a4440: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a4444: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1037_0x0a4438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4438ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1038 | PC: 0x0a4654 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1038 | Địa chỉ PC: 0x0a4654 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0a4654: D10143FF  sub      sp, sp, #0x50
//   0x0a4658: F9000BF7  str      x23, [sp, #0x10]
//   0x0a465c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a4660: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1038_0x0a4654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4654ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1039 | PC: 0x0a4738 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1039 | Địa chỉ PC: 0x0a4738 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a4738: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a473c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a4740: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a4744: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1039_0x0a4738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4738ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1040 | PC: 0x0a484c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1040 | Địa chỉ PC: 0x0a484c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a484c: D101C3FF  sub      sp, sp, #0x70
//   0x0a4850: F9000BFB  str      x27, [sp, #0x10]
//   0x0a4854: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0a4858: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1040_0x0a484c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a484cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1041 | PC: 0x0a49fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1041 | Địa chỉ PC: 0x0a49fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a49fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a4a00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a4a04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a4a08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1041_0x0a49fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a49fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1042 | PC: 0x0a4c4c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1042 | Địa chỉ PC: 0x0a4c4c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a4c4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a4c50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4c54: 910043FD  add      x29, sp, #0x10
//   0x0a4c58: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1042_0x0a4c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4c4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1043 | PC: 0x0a4dac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1043 | Địa chỉ PC: 0x0a4dac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a4dac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a4db0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a4db4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a4db8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1043_0x0a4dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4dacULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1044 | PC: 0x0a52ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1044 | Địa chỉ PC: 0x0a52ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a52ac: D10603FF  sub      sp, sp, #0x180
//   0x0a52b0: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x0a52b4: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x0a52b8: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_1044_0x0a52ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52acULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1045 | PC: 0x0a55ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1045 | Địa chỉ PC: 0x0a55ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a55ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a55b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a55b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a55b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1045_0x0a55ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a55acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1046 | PC: 0x0a59b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1046 | Địa chỉ PC: 0x0a59b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a59b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a59b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a59b8: 910043FD  add      x29, sp, #0x10
//   0x0a59bc: D00005A8  adrp     x8, #0x15b000
static inline uint64_t fde_func_1046_0x0a59b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a59b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1047 | PC: 0x0a5c18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1047 | Địa chỉ PC: 0x0a5c18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a5c18: D10403FF  sub      sp, sp, #0x100
//   0x0a5c1c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x0a5c20: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x0a5c24: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_1047_0x0a5c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5c18ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90c5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1048 | PC: 0x0a6154 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1048 | Địa chỉ PC: 0x0a6154 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a6154: D10683FF  sub      sp, sp, #0x1a0
//   0x0a6158: A9165FFC  stp      x28, x23, [sp, #0x160]
//   0x0a615c: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x0a6160: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1048_0x0a6154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6154ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9165ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1049 | PC: 0x0a6594 | FDE: 0x148a38 | Size: 20 bytes
// Hàm #1049 | Địa chỉ PC: 0x0a6594 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0a6594: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x0a6598: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a659c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a65a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1049_0x0a6594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6594ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1050 | PC: 0x0a65a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1050 | Địa chỉ PC: 0x0a65a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a65a8: D13183FF  sub      sp, sp, #0xc60
//   0x0a65ac: AA0003F3  mov      x19, x0
//   0x0a65b0: 528000C0  mov      w0, #6
//   0x0a65b4: AA0203F5  mov      x21, x2
static inline uint64_t fde_func_1050_0x0a65a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a65a8ULL ^ (static_cast<uint64_t>(0xd13183ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1051 | PC: 0x0a6a20 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1051 | Địa chỉ PC: 0x0a6a20 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a6a20: D104C3FF  sub      sp, sp, #0x130
//   0x0a6a24: F9007BFC  str      x28, [sp, #0xf0]
//   0x0a6a28: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x0a6a2c: A9114FF4  stp      x20, x19, [sp, #0x110]
static inline uint64_t fde_func_1051_0x0a6a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6a20ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1052 | PC: 0x0a6c8c | FDE: 0x148a38 | Size: 52 bytes
// Hàm #1052 | Địa chỉ PC: 0x0a6c8c | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0a6c8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a6c90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a6c94: 910043FD  add      x29, sp, #0x10
//   0x0a6c98: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1052_0x0a6c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6c8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1053 | PC: 0x0a6cc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1053 | Địa chỉ PC: 0x0a6cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a6cc0: D10503FF  sub      sp, sp, #0x140
//   0x0a6cc4: F90083FC  str      x28, [sp, #0x100]
//   0x0a6cc8: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0a6ccc: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1053_0x0a6cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6cc0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1054 | PC: 0x0a6f5c | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1054 | Địa chỉ PC: 0x0a6f5c | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0a6f5c: D10103FF  sub      sp, sp, #0x40
//   0x0a6f60: F9000BF5  str      x21, [sp, #0x10]
//   0x0a6f64: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a6f68: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1054_0x0a6f5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6f5cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1055 | PC: 0x0a7040 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1055 | Địa chỉ PC: 0x0a7040 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a7040: D103C3FF  sub      sp, sp, #0xf0
//   0x0a7044: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x0a7048: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x0a704c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_1055_0x0a7040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7040ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90b5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1056 | PC: 0x0a7408 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1056 | Địa chỉ PC: 0x0a7408 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a7408: D10643FF  sub      sp, sp, #0x190
//   0x0a740c: A91467FC  stp      x28, x25, [sp, #0x140]
//   0x0a7410: A9155FF8  stp      x24, x23, [sp, #0x150]
//   0x0a7414: A91657F6  stp      x22, x21, [sp, #0x160]
static inline uint64_t fde_func_1056_0x0a7408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7408ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa91467fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1057 | PC: 0x0a7800 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1057 | Địa chỉ PC: 0x0a7800 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a7800: D10743FF  sub      sp, sp, #0x1d0
//   0x0a7804: F900C3FC  str      x28, [sp, #0x180]
//   0x0a7808: A9195FF8  stp      x24, x23, [sp, #0x190]
//   0x0a780c: A91A57F6  stp      x22, x21, [sp, #0x1a0]
static inline uint64_t fde_func_1057_0x0a7800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7800ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xf900c3fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1058 | PC: 0x0a7cd4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1058 | Địa chỉ PC: 0x0a7cd4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a7cd4: D10283FF  sub      sp, sp, #0xa0
//   0x0a7cd8: F9002BF9  str      x25, [sp, #0x50]
//   0x0a7cdc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0a7ce0: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1058_0x0a7cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7cd4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1059 | PC: 0x0a7ecc | FDE: 0x148a38 | Size: 232 bytes
// Hàm #1059 | Địa chỉ PC: 0x0a7ecc | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0a7ecc: D101C3FF  sub      sp, sp, #0x70
//   0x0a7ed0: F90023F5  str      x21, [sp, #0x40]
//   0x0a7ed4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a7ed8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1059_0x0a7ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7eccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1060 | PC: 0x0a7fb4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1060 | Địa chỉ PC: 0x0a7fb4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a7fb4: D10143FF  sub      sp, sp, #0x50
//   0x0a7fb8: F90013F5  str      x21, [sp, #0x20]
//   0x0a7fbc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a7fc0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1060_0x0a7fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7fb4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1061 | PC: 0x0a816c | FDE: 0x148a38 | Size: 124 bytes
// Hàm #1061 | Địa chỉ PC: 0x0a816c | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x0a816c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a8170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8174: 910043FD  add      x29, sp, #0x10
//   0x0a8178: 5282EE28  mov      w8, #0x1771
static inline uint64_t fde_func_1061_0x0a816c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a816cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #1062 | PC: 0x0a81e8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1062 | Địa chỉ PC: 0x0a81e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a81e8: D101C3FF  sub      sp, sp, #0x70
//   0x0a81ec: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a81f0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a81f4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1062_0x0a81e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a81e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1063 | PC: 0x0a8338 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #1063 | Địa chỉ PC: 0x0a8338 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0a8338: D101C3FF  sub      sp, sp, #0x70
//   0x0a833c: F90023F5  str      x21, [sp, #0x40]
//   0x0a8340: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a8344: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1063_0x0a8338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8338ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1064 | PC: 0x0a8420 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1064 | Địa chỉ PC: 0x0a8420 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a8420: D10343FF  sub      sp, sp, #0xd0
//   0x0a8424: F9004BF7  str      x23, [sp, #0x90]
//   0x0a8428: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0a842c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_1064_0x0a8420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8420ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1065 | PC: 0x0a85cc | FDE: 0x148a38 | Size: 44 bytes
// Hàm #1065 | Địa chỉ PC: 0x0a85cc | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x0a85cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a85d0: 910003FD  mov      x29, sp
//   0x0a85d4: F9400008  ldr      x8, [x0]
//   0x0a85d8: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_1065_0x0a85cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a85ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #1066 | PC: 0x0a85f8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1066 | Địa chỉ PC: 0x0a85f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0a85f8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a85fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a8600: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a8604: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1066_0x0a85f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a85f8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1067 | PC: 0x0a8614 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1067 | Địa chỉ PC: 0x0a8614 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a8614: D132C3FF  sub      sp, sp, #0xcb0
//   0x0a8618: D53BD059  mrs      x25, tpidr_el0
//   0x0a861c: F9401728  ldr      x8, [x25, #0x28]
//   0x0a8620: AA0303F4  mov      x20, x3
static inline uint64_t fde_func_1067_0x0a8614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8614ULL ^ (static_cast<uint64_t>(0xd132c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd059ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1068 | PC: 0x0a89f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1068 | Địa chỉ PC: 0x0a89f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a89f4: D13083FF  sub      sp, sp, #0xc20
//   0x0a89f8: AA0003F3  mov      x19, x0
//   0x0a89fc: F9408000  ldr      x0, [x0, #0x100]
//   0x0a8a00: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1068_0x0a89f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a89f4ULL ^ (static_cast<uint64_t>(0xd13083ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1069 | PC: 0x0a8b50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1069 | Địa chỉ PC: 0x0a8b50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a8b50: D10303FF  sub      sp, sp, #0xc0
//   0x0a8b54: F9003BF9  str      x25, [sp, #0x70]
//   0x0a8b58: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0a8b5c: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_1069_0x0a8b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8b50ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1070 | PC: 0x0a8cf4 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #1070 | Địa chỉ PC: 0x0a8cf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x0a8cf4: D10183FF  sub      sp, sp, #0x60
//   0x0a8cf8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a8cfc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0a8d00: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1070_0x0a8cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8cf4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #1071 | PC: 0x0a8d84 | FDE: 0x148a38 | Size: 240 bytes
// Hàm #1071 | Địa chỉ PC: 0x0a8d84 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x0a8d84: D10203FF  sub      sp, sp, #0x80
//   0x0a8d88: F90023F7  str      x23, [sp, #0x40]
//   0x0a8d8c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0a8d90: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1071_0x0a8d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8d84ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #1072 | PC: 0x0a8e74 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1072 | Địa chỉ PC: 0x0a8e74 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a8e74: D10283FF  sub      sp, sp, #0xa0
//   0x0a8e78: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0a8e7c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0a8e80: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1072_0x0a8e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8e74ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1073 | PC: 0x0a8f74 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1073 | Địa chỉ PC: 0x0a8f74 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a8f74: D10283FF  sub      sp, sp, #0xa0
//   0x0a8f78: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0a8f7c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0a8f80: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1073_0x0a8f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f74ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1074 | PC: 0x0a909c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1074 | Địa chỉ PC: 0x0a909c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a909c: D10303FF  sub      sp, sp, #0xc0
//   0x0a90a0: F90043F7  str      x23, [sp, #0x80]
//   0x0a90a4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0a90a8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1074_0x0a909c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a909cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1075 | PC: 0x0a9220 | FDE: 0x148a38 | Size: 248 bytes
// Hàm #1075 | Địa chỉ PC: 0x0a9220 | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x0a9220: D102C3FF  sub      sp, sp, #0xb0
//   0x0a9224: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0a9228: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x0a922c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1075_0x0a9220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9220ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1076 | PC: 0x0a9318 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1076 | Địa chỉ PC: 0x0a9318 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0a9318: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a931c: 910003FD  mov      x29, sp
//   0x0a9320: D1002000  sub      x0, x0, #8
//   0x0a9324: 97FFFFBF  bl       #0xa9220
static inline uint64_t fde_func_1076_0x0a9318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9318ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1077 | PC: 0x0a9334 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1077 | Địa chỉ PC: 0x0a9334 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a9334: D10303FF  sub      sp, sp, #0xc0
//   0x0a9338: F90043F7  str      x23, [sp, #0x80]
//   0x0a933c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0a9340: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1077_0x0a9334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9334ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1078 | PC: 0x0a9448 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1078 | Địa chỉ PC: 0x0a9448 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a9448: D10303FF  sub      sp, sp, #0xc0
//   0x0a944c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0a9450: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0a9454: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1078_0x0a9448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9448ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1079 | PC: 0x0a9564 | FDE: 0x148a38 | Size: 248 bytes
// Hàm #1079 | Địa chỉ PC: 0x0a9564 | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x0a9564: D10283FF  sub      sp, sp, #0xa0
//   0x0a9568: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0a956c: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0a9570: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1079_0x0a9564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9564ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1080 | PC: 0x0a965c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1080 | Địa chỉ PC: 0x0a965c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a965c: D102C3FF  sub      sp, sp, #0xb0
//   0x0a9660: F9003BF7  str      x23, [sp, #0x70]
//   0x0a9664: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0a9668: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_1080_0x0a965c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a965cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1081 | PC: 0x0a9760 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1081 | Địa chỉ PC: 0x0a9760 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a9760: D105C3FF  sub      sp, sp, #0x170
//   0x0a9764: A9135FFC  stp      x28, x23, [sp, #0x130]
//   0x0a9768: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x0a976c: A9154FF4  stp      x20, x19, [sp, #0x150]
static inline uint64_t fde_func_1081_0x0a9760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9760ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9135ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1082 | PC: 0x0a9984 | FDE: 0x148a38 | Size: 36 bytes
// Hàm #1082 | Địa chỉ PC: 0x0a9984 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x0a9984: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a9988: 910003FD  mov      x29, sp
//   0x0a998c: F9408400  ldr      x0, [x0, #0x108]
//   0x0a9990: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1082_0x0a9984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9984ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1083 | PC: 0x0a99a8 | FDE: 0x148a38 | Size: 36 bytes
// Hàm #1083 | Địa chỉ PC: 0x0a99a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x0a99a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a99ac: 910003FD  mov      x29, sp
//   0x0a99b0: F9408000  ldr      x0, [x0, #0x100]
//   0x0a99b4: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1083_0x0a99a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a99a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1084 | PC: 0x0a99cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1084 | Địa chỉ PC: 0x0a99cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a99cc: D10303FF  sub      sp, sp, #0xc0
//   0x0a99d0: F90043F7  str      x23, [sp, #0x80]
//   0x0a99d4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0a99d8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1084_0x0a99cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a99ccULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1085 | PC: 0x0a9ad0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1085 | Địa chỉ PC: 0x0a9ad0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a9ad0: D10503FF  sub      sp, sp, #0x140
//   0x0a9ad4: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x0a9ad8: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0a9adc: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1085_0x0a9ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9ad0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1086 | PC: 0x0a9d48 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1086 | Địa chỉ PC: 0x0a9d48 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a9d48: D10303FF  sub      sp, sp, #0xc0
//   0x0a9d4c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0a9d50: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0a9d54: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1086_0x0a9d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9d48ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1087 | PC: 0x0a9e58 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1087 | Địa chỉ PC: 0x0a9e58 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0a9e58: D10383FF  sub      sp, sp, #0xe0
//   0x0a9e5c: F9004BF9  str      x25, [sp, #0x90]
//   0x0a9e60: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x0a9e64: A90B57F6  stp      x22, x21, [sp, #0xb0]
static inline uint64_t fde_func_1087_0x0a9e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9e58ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1088 | PC: 0x0a9fe0 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #1088 | Địa chỉ PC: 0x0a9fe0 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x0a9fe0: D100C3FF  sub      sp, sp, #0x30
//   0x0a9fe4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a9fe8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a9fec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1088_0x0a9fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9fe0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #1089 | PC: 0x0aa084 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #1089 | Địa chỉ PC: 0x0aa084 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x0aa084: D10203FF  sub      sp, sp, #0x80
//   0x0aa088: F90023F7  str      x23, [sp, #0x40]
//   0x0aa08c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0aa090: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1089_0x0aa084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa084ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #1090 | PC: 0x0aa148 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #1090 | Địa chỉ PC: 0x0aa148 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x0aa148: D10183FF  sub      sp, sp, #0x60
//   0x0aa14c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0aa150: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0aa154: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1090_0x0aa148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa148ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #1091 | PC: 0x0aa1ec | FDE: 0x148a38 | Size: 196 bytes
// Hàm #1091 | Địa chỉ PC: 0x0aa1ec | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x0aa1ec: D10203FF  sub      sp, sp, #0x80
//   0x0aa1f0: F90023F7  str      x23, [sp, #0x40]
//   0x0aa1f4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0aa1f8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1091_0x0aa1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa1ecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #1092 | PC: 0x0aa2b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1092 | Địa chỉ PC: 0x0aa2b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aa2b0: D10403FF  sub      sp, sp, #0x100
//   0x0aa2b4: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x0aa2b8: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x0aa2bc: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_1092_0x0aa2b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa2b0ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90c5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1093 | PC: 0x0aa674 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1093 | Địa chỉ PC: 0x0aa674 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aa674: D130C3FF  sub      sp, sp, #0xc30
//   0x0aa678: 2A0103F6  mov      w22, w1
//   0x0aa67c: AA0003F3  mov      x19, x0
//   0x0aa680: 97FE24B4  bl       #0x33950
static inline uint64_t fde_func_1093_0x0aa674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa674ULL ^ (static_cast<uint64_t>(0xd130c3ffULL) << 13);
    acc = (acc + a1 + 0x2a0103f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1094 | PC: 0x0aa78c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1094 | Địa chỉ PC: 0x0aa78c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aa78c: D10303FF  sub      sp, sp, #0xc0
//   0x0aa790: F90043F7  str      x23, [sp, #0x80]
//   0x0aa794: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0aa798: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1094_0x0aa78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa78cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1095 | PC: 0x0aac20 | FDE: 0x148a38 | Size: 24 bytes
// Hàm #1095 | Địa chỉ PC: 0x0aac20 | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x0aac20: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x0aac24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0aac28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0aac2c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1095_0x0aac20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aac20ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1096 | PC: 0x0aac38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1096 | Địa chỉ PC: 0x0aac38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aac38: D13183FF  sub      sp, sp, #0xc60
//   0x0aac3c: AA0003F4  mov      x20, x0
//   0x0aac40: 528000C0  mov      w0, #6
//   0x0aac44: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_1096_0x0aac38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aac38ULL ^ (static_cast<uint64_t>(0xd13183ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1097 | PC: 0x0ab0c4 | FDE: 0x148a38 | Size: 16 bytes
// Hàm #1097 | Địa chỉ PC: 0x0ab0c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x0ab0c4: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x0ab0c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ab0cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ab0d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1097_0x0ab0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab0c4ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1098 | PC: 0x0ab0d4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1098 | Địa chỉ PC: 0x0ab0d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ab0d4: D13103FF  sub      sp, sp, #0xc40
//   0x0ab0d8: 9104C008  add      x8, x0, #0x130
//   0x0ab0dc: C8DFFD08  ldar     x8, [x8]
//   0x0ab0e0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1098_0x0ab0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab0d4ULL ^ (static_cast<uint64_t>(0xd13103ffULL) << 13);
    acc = (acc + a1 + 0x9104c008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1099 | PC: 0x0ab380 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1099 | Địa chỉ PC: 0x0ab380 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ab380: D10143FF  sub      sp, sp, #0x50
//   0x0ab384: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ab388: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0ab38c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1099_0x0ab380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab380ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1100 | PC: 0x0ab5b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1100 | Địa chỉ PC: 0x0ab5b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ab5b0: D101C3FF  sub      sp, sp, #0x70
//   0x0ab5b4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0ab5b8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ab5bc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1100_0x0ab5b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab5b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1101 | PC: 0x0ab8c8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1101 | Địa chỉ PC: 0x0ab8c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ab8c8: D130C3FF  sub      sp, sp, #0xc30
//   0x0ab8cc: 52800C81  mov      w1, #0x64
//   0x0ab8d0: AA0003F3  mov      x19, x0
//   0x0ab8d4: 97FFEDA2  bl       #0xa6f5c
static inline uint64_t fde_func_1101_0x0ab8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab8c8ULL ^ (static_cast<uint64_t>(0xd130c3ffULL) << 13);
    acc = (acc + a1 + 0x52800c81ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1102 | PC: 0x0aba74 | FDE: 0x148a38 | Size: 216 bytes
// Hàm #1102 | Địa chỉ PC: 0x0aba74 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x0aba74: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0aba78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0aba7c: 910043FD  add      x29, sp, #0x10
//   0x0aba80: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1102_0x0aba74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aba74ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #1103 | PC: 0x0abb4c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1103 | Địa chỉ PC: 0x0abb4c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0abb4c: D10303FF  sub      sp, sp, #0xc0
//   0x0abb50: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0abb54: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0abb58: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1103_0x0abb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abb4cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1104 | PC: 0x0ac008 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1104 | Địa chỉ PC: 0x0ac008 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ac008: D10183FF  sub      sp, sp, #0x60
//   0x0ac00c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ac010: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0ac014: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1104_0x0ac008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac008ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1105 | PC: 0x0ac220 | FDE: 0x148a38 | Size: 20 bytes
// Hàm #1105 | Địa chỉ PC: 0x0ac220 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0ac220: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x0ac224: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ac228: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ac22c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1105_0x0ac220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac220ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1106 | PC: 0x0ac234 | FDE: 0x148a38 | Size: 4 bytes
// Hàm #1106 | Địa chỉ PC: 0x0ac234 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x0ac234: D14007FF  sub      sp, sp, #1, lsl #12
static inline uint64_t fde_func_1106_0x0ac234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac234ULL ^ (static_cast<uint64_t>(0xd14007ffULL) << 13);
    acc = (acc + a1 + 0xd12183ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1107 | PC: 0x0ac238 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1107 | Địa chỉ PC: 0x0ac238 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ac238: D12183FF  sub      sp, sp, #0x860
//   0x0ac23c: 9104C008  add      x8, x0, #0x130
//   0x0ac240: C8DFFD08  ldar     x8, [x8]
//   0x0ac244: EB02011F  cmp      x8, x2
static inline uint64_t fde_func_1107_0x0ac238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac238ULL ^ (static_cast<uint64_t>(0xd12183ffULL) << 13);
    acc = (acc + a1 + 0x9104c008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1108 | PC: 0x0ac898 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1108 | Địa chỉ PC: 0x0ac898 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ac898: D10143FF  sub      sp, sp, #0x50
//   0x0ac89c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0ac8a0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ac8a4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1108_0x0ac898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac898ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1109 | PC: 0x0ac9c4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1109 | Địa chỉ PC: 0x0ac9c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ac9c4: D13143FF  sub      sp, sp, #0xc50
//   0x0ac9c8: AA0003F3  mov      x19, x0
//   0x0ac9cc: 528000C0  mov      w0, #6
//   0x0ac9d0: 97FE1AD8  bl       #0x33530
static inline uint64_t fde_func_1109_0x0ac9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac9c4ULL ^ (static_cast<uint64_t>(0xd13143ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1110 | PC: 0x0aceac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1110 | Địa chỉ PC: 0x0aceac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aceac: D10243FF  sub      sp, sp, #0x90
//   0x0aceb0: F90023F9  str      x25, [sp, #0x40]
//   0x0aceb4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0aceb8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1110_0x0aceac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aceacULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1111 | PC: 0x0ad318 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1111 | Địa chỉ PC: 0x0ad318 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ad318: D106C3FF  sub      sp, sp, #0x1b0
//   0x0ad31c: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0ad320: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0ad324: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_1111_0x0ad318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad318ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9156ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1112 | PC: 0x0ad514 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1112 | Địa chỉ PC: 0x0ad514 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ad514: D10143FF  sub      sp, sp, #0x50
//   0x0ad518: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ad51c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ad520: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1112_0x0ad514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad514ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1113 | PC: 0x0ad77c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1113 | Địa chỉ PC: 0x0ad77c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ad77c: D10183FF  sub      sp, sp, #0x60
//   0x0ad780: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0ad784: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0ad788: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1113_0x0ad77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad77cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1114 | PC: 0x0adbc8 | FDE: 0x148a38 | Size: 216 bytes
// Hàm #1114 | Địa chỉ PC: 0x0adbc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x0adbc8: D10103FF  sub      sp, sp, #0x40
//   0x0adbcc: F90013F3  str      x19, [sp, #0x20]
//   0x0adbd0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0adbd4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1114_0x0adbc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adbc8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #1115 | PC: 0x0adca0 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #1115 | Địa chỉ PC: 0x0adca0 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0adca0: D10103FF  sub      sp, sp, #0x40
//   0x0adca4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0adca8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0adcac: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1115_0x0adca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adca0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1116 | PC: 0x0add00 | FDE: 0x148a38 | Size: 20 bytes
// Hàm #1116 | Địa chỉ PC: 0x0add00 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0add00: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x0add04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0add08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0add0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1116_0x0add00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0add00ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1117 | PC: 0x0add14 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1117 | Địa chỉ PC: 0x0add14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0add14: D13083FF  sub      sp, sp, #0xc20
//   0x0add18: 91022008  add      x8, x0, #0x88
//   0x0add1c: 88DFFD08  ldar     w8, [x8]
//   0x0add20: 34002448  cbz      w8, #0xae1a8
static inline uint64_t fde_func_1117_0x0add14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0add14ULL ^ (static_cast<uint64_t>(0xd13083ffULL) << 13);
    acc = (acc + a1 + 0x91022008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1118 | PC: 0x0ae1c0 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #1118 | Địa chỉ PC: 0x0ae1c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x0ae1c0: D10143FF  sub      sp, sp, #0x50
//   0x0ae1c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ae1c8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ae1cc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1118_0x0ae1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae1c0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #1119 | PC: 0x0ae264 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1119 | Địa chỉ PC: 0x0ae264 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ae264: D10183FF  sub      sp, sp, #0x60
//   0x0ae268: F9000BF9  str      x25, [sp, #0x10]
//   0x0ae26c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ae270: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1119_0x0ae264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae264ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1120 | PC: 0x0ae550 | FDE: 0x148a38 | Size: 20 bytes
// Hàm #1120 | Địa chỉ PC: 0x0ae550 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0ae550: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x0ae554: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ae558: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ae55c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1120_0x0ae550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae550ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1121 | PC: 0x0ae564 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1121 | Địa chỉ PC: 0x0ae564 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ae564: D13103FF  sub      sp, sp, #0xc40
//   0x0ae568: AA0003F3  mov      x19, x0
//   0x0ae56c: 528000C0  mov      w0, #6
//   0x0ae570: 2A0403F5  mov      w21, w4
static inline uint64_t fde_func_1121_0x0ae564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae564ULL ^ (static_cast<uint64_t>(0xd13103ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1122 | PC: 0x0ae844 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1122 | Địa chỉ PC: 0x0ae844 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0ae844: D100C3FF  sub      sp, sp, #0x30
//   0x0ae848: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ae84c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ae850: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1122_0x0ae844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae844ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1123 | PC: 0x0ae8c4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1123 | Địa chỉ PC: 0x0ae8c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ae8c4: D10183FF  sub      sp, sp, #0x60
//   0x0ae8c8: F90013F7  str      x23, [sp, #0x20]
//   0x0ae8cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ae8d0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1123_0x0ae8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae8c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1124 | PC: 0x0aeaa4 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #1124 | Địa chỉ PC: 0x0aeaa4 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0aeaa4: D10103FF  sub      sp, sp, #0x40
//   0x0aeaa8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0aeaac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0aeab0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1124_0x0aeaa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeaa4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1125 | PC: 0x0aeb04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1125 | Địa chỉ PC: 0x0aeb04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aeb04: D10183FF  sub      sp, sp, #0x60
//   0x0aeb08: F90013F7  str      x23, [sp, #0x20]
//   0x0aeb0c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0aeb10: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1125_0x0aeb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeb04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1126 | PC: 0x0aecb8 | FDE: 0x148a38 | Size: 24 bytes
// Hàm #1126 | Địa chỉ PC: 0x0aecb8 | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x0aecb8: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x0aecbc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0aecc0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0aecc4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1126_0x0aecb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aecb8ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1127 | PC: 0x0aecd0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1127 | Địa chỉ PC: 0x0aecd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aecd0: D13043FF  sub      sp, sp, #0xc10
//   0x0aecd4: F9400028  ldr      x8, [x1]
//   0x0aecd8: B9403909  ldr      w9, [x8, #0x38]
//   0x0aecdc: 35000F29  cbnz     w9, #0xaeec0
static inline uint64_t fde_func_1127_0x0aecd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aecd0ULL ^ (static_cast<uint64_t>(0xd13043ffULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1128 | PC: 0x0aeedc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1128 | Địa chỉ PC: 0x0aeedc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0aeedc: D10203FF  sub      sp, sp, #0x80
//   0x0aeee0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0aeee4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0aeee8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1128_0x0aeedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeedcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1129 | PC: 0x0af1dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1129 | Địa chỉ PC: 0x0af1dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0af1dc: D10203FF  sub      sp, sp, #0x80
//   0x0af1e0: F9001BF9  str      x25, [sp, #0x30]
//   0x0af1e4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0af1e8: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1129_0x0af1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af1dcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1130 | PC: 0x0af430 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1130 | Địa chỉ PC: 0x0af430 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0af430: D100C3FF  sub      sp, sp, #0x30
//   0x0af434: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0af438: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0af43c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1130_0x0af430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af430ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1131 | PC: 0x0af620 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1131 | Địa chỉ PC: 0x0af620 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0af620: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0af624: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0af628: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0af62c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1131_0x0af620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af620ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1132 | PC: 0x0af63c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1132 | Địa chỉ PC: 0x0af63c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0af63c: D13583FF  sub      sp, sp, #0xd60
//   0x0af640: D53BD05A  mrs      x26, tpidr_el0
//   0x0af644: F9401748  ldr      x8, [x26, #0x28]
//   0x0af648: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1132_0x0af63c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af63cULL ^ (static_cast<uint64_t>(0xd13583ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1133 | PC: 0x0b0164 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1133 | Địa chỉ PC: 0x0b0164 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b0164: D10203FF  sub      sp, sp, #0x80
//   0x0b0168: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0b016c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0b0170: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1133_0x0b0164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0164ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1134 | PC: 0x0b0588 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1134 | Địa chỉ PC: 0x0b0588 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b0588: D10183FF  sub      sp, sp, #0x60
//   0x0b058c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b0590: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0b0594: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1134_0x0b0588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0588ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1135 | PC: 0x0b08a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1135 | Địa chỉ PC: 0x0b08a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b08a4: D10103FF  sub      sp, sp, #0x40
//   0x0b08a8: F9000BF5  str      x21, [sp, #0x10]
//   0x0b08ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b08b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1135_0x0b08a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1136 | PC: 0x0b09b0 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #1136 | Địa chỉ PC: 0x0b09b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x0b09b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b09b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b09b8: 910043FD  add      x29, sp, #0x10
//   0x0b09bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1136_0x0b09b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b09b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #1137 | PC: 0x0b0a20 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #1137 | Địa chỉ PC: 0x0b0a20 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x0b0a20: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b0a24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0a28: 910043FD  add      x29, sp, #0x10
//   0x0b0a2c: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_1137_0x0b0a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0a20ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #1138 | PC: 0x0b0ad4 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #1138 | Địa chỉ PC: 0x0b0ad4 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x0b0ad4: D10203FF  sub      sp, sp, #0x80
//   0x0b0ad8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0b0adc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0b0ae0: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1138_0x0b0ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0ad4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #1139 | PC: 0x0b0bb4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1139 | Địa chỉ PC: 0x0b0bb4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b0bb4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b0bb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0bbc: 910043FD  add      x29, sp, #0x10
//   0x0b0bc0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1139_0x0b0bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0bb4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 760: return fde_func_0760_0x086dcc(a0, a1);
        case 761: return fde_func_0761_0x087250(a0, a1);
        case 762: return fde_func_0762_0x087260(a0, a1);
        case 763: return fde_func_0763_0x0873f0(a0, a1);
        case 764: return fde_func_0764_0x0874dc(a0, a1);
        case 765: return fde_func_0765_0x0874f8(a0, a1);
        case 766: return fde_func_0766_0x0877d0(a0, a1);
        case 767: return fde_func_0767_0x0878e4(a0, a1);
        case 768: return fde_func_0768_0x087900(a0, a1);
        case 769: return fde_func_0769_0x087d64(a0, a1);
        case 770: return fde_func_0770_0x087e48(a0, a1);
        case 771: return fde_func_0771_0x087efc(a0, a1);
        case 772: return fde_func_0772_0x087f18(a0, a1);
        case 773: return fde_func_0773_0x088240(a0, a1);
        case 774: return fde_func_0774_0x08825c(a0, a1);
        case 775: return fde_func_0775_0x088528(a0, a1);
        case 776: return fde_func_0776_0x088544(a0, a1);
        case 777: return fde_func_0777_0x088788(a0, a1);
        case 778: return fde_func_0778_0x088880(a0, a1);
        case 779: return fde_func_0779_0x088abc(a0, a1);
        case 780: return fde_func_0780_0x088ad8(a0, a1);
        case 781: return fde_func_0781_0x088de8(a0, a1);
        case 782: return fde_func_0782_0x088fa0(a0, a1);
        case 783: return fde_func_0783_0x0891f0(a0, a1);
        case 784: return fde_func_0784_0x08920c(a0, a1);
        case 785: return fde_func_0785_0x0894c4(a0, a1);
        case 786: return fde_func_0786_0x089660(a0, a1);
        case 787: return fde_func_0787_0x089704(a0, a1);
        case 788: return fde_func_0788_0x089b94(a0, a1);
        case 789: return fde_func_0789_0x089f9c(a0, a1);
        case 790: return fde_func_0790_0x08a114(a0, a1);
        case 791: return fde_func_0791_0x08a314(a0, a1);
        case 792: return fde_func_0792_0x08a3bc(a0, a1);
        case 793: return fde_func_0793_0x08a488(a0, a1);
        case 794: return fde_func_0794_0x08a55c(a0, a1);
        case 795: return fde_func_0795_0x08a67c(a0, a1);
        case 796: return fde_func_0796_0x08a6e8(a0, a1);
        case 797: return fde_func_0797_0x08a7dc(a0, a1);
        case 798: return fde_func_0798_0x08a8c4(a0, a1);
        case 799: return fde_func_0799_0x08a92c(a0, a1);
        case 800: return fde_func_0800_0x08a9e8(a0, a1);
        case 801: return fde_func_0801_0x08aa88(a0, a1);
        case 802: return fde_func_0802_0x08ab34(a0, a1);
        case 803: return fde_func_0803_0x08ac50(a0, a1);
        case 804: return fde_func_0804_0x08aef8(a0, a1);
        case 805: return fde_func_0805_0x08af58(a0, a1);
        case 806: return fde_func_0806_0x08af98(a0, a1);
        case 807: return fde_func_0807_0x08b050(a0, a1);
        case 808: return fde_func_0808_0x08b0b8(a0, a1);
        case 809: return fde_func_0809_0x08b234(a0, a1);
        case 810: return fde_func_0810_0x08b284(a0, a1);
        case 811: return fde_func_0811_0x08b5ac(a0, a1);
        case 812: return fde_func_0812_0x08b630(a0, a1);
        case 813: return fde_func_0813_0x08b9d0(a0, a1);
        case 814: return fde_func_0814_0x08bab4(a0, a1);
        case 815: return fde_func_0815_0x08bd18(a0, a1);
        case 816: return fde_func_0816_0x08c970(a0, a1);
        case 817: return fde_func_0817_0x08d5f0(a0, a1);
        case 818: return fde_func_0818_0x08d734(a0, a1);
        case 819: return fde_func_0819_0x08da60(a0, a1);
        case 820: return fde_func_0820_0x08e114(a0, a1);
        case 821: return fde_func_0821_0x08e81c(a0, a1);
        case 822: return fde_func_0822_0x08e94c(a0, a1);
        case 823: return fde_func_0823_0x08eaec(a0, a1);
        case 824: return fde_func_0824_0x08ee54(a0, a1);
        case 825: return fde_func_0825_0x08f184(a0, a1);
        case 826: return fde_func_0826_0x08f410(a0, a1);
        case 827: return fde_func_0827_0x08f5f0(a0, a1);
        case 828: return fde_func_0828_0x08f748(a0, a1);
        case 829: return fde_func_0829_0x08f888(a0, a1);
        case 830: return fde_func_0830_0x08fdf4(a0, a1);
        case 831: return fde_func_0831_0x08fec8(a0, a1);
        case 832: return fde_func_0832_0x09005c(a0, a1);
        case 833: return fde_func_0833_0x090124(a0, a1);
        case 834: return fde_func_0834_0x0901d8(a0, a1);
        case 835: return fde_func_0835_0x090214(a0, a1);
        case 836: return fde_func_0836_0x09035c(a0, a1);
        case 837: return fde_func_0837_0x09040c(a0, a1);
        case 838: return fde_func_0838_0x090494(a0, a1);
        case 839: return fde_func_0839_0x090550(a0, a1);
        case 840: return fde_func_0840_0x090740(a0, a1);
        case 841: return fde_func_0841_0x0909dc(a0, a1);
        case 842: return fde_func_0842_0x090b64(a0, a1);
        case 843: return fde_func_0843_0x090d8c(a0, a1);
        case 844: return fde_func_0844_0x091224(a0, a1);
        case 845: return fde_func_0845_0x0915f8(a0, a1);
        case 846: return fde_func_0846_0x0916d0(a0, a1);
        case 847: return fde_func_0847_0x091820(a0, a1);
        case 848: return fde_func_0848_0x0919a8(a0, a1);
        case 849: return fde_func_0849_0x0919e4(a0, a1);
        case 850: return fde_func_0850_0x091acc(a0, a1);
        case 851: return fde_func_0851_0x091bc0(a0, a1);
        case 852: return fde_func_0852_0x091cdc(a0, a1);
        case 853: return fde_func_0853_0x091fec(a0, a1);
        case 854: return fde_func_0854_0x092184(a0, a1);
        case 855: return fde_func_0855_0x092540(a0, a1);
        case 856: return fde_func_0856_0x09280c(a0, a1);
        case 857: return fde_func_0857_0x0929cc(a0, a1);
        case 858: return fde_func_0858_0x092a38(a0, a1);
        case 859: return fde_func_0859_0x092bdc(a0, a1);
        case 860: return fde_func_0860_0x0930c0(a0, a1);
        case 861: return fde_func_0861_0x0933d8(a0, a1);
        case 862: return fde_func_0862_0x09395c(a0, a1);
        case 863: return fde_func_0863_0x093a54(a0, a1);
        case 864: return fde_func_0864_0x093cb0(a0, a1);
        case 865: return fde_func_0865_0x093d48(a0, a1);
        case 866: return fde_func_0866_0x094038(a0, a1);
        case 867: return fde_func_0867_0x094790(a0, a1);
        case 868: return fde_func_0868_0x09489c(a0, a1);
        case 869: return fde_func_0869_0x0949f8(a0, a1);
        case 870: return fde_func_0870_0x094ad0(a0, a1);
        case 871: return fde_func_0871_0x094b9c(a0, a1);
        case 872: return fde_func_0872_0x094be8(a0, a1);
        case 873: return fde_func_0873_0x094c18(a0, a1);
        case 874: return fde_func_0874_0x094c90(a0, a1);
        case 875: return fde_func_0875_0x094d0c(a0, a1);
        case 876: return fde_func_0876_0x094d70(a0, a1);
        case 877: return fde_func_0877_0x094e20(a0, a1);
        case 878: return fde_func_0878_0x095200(a0, a1);
        case 879: return fde_func_0879_0x0954e4(a0, a1);
        case 880: return fde_func_0880_0x095540(a0, a1);
        case 881: return fde_func_0881_0x095844(a0, a1);
        case 882: return fde_func_0882_0x0958cc(a0, a1);
        case 883: return fde_func_0883_0x095b04(a0, a1);
        case 884: return fde_func_0884_0x095b5c(a0, a1);
        case 885: return fde_func_0885_0x095c44(a0, a1);
        case 886: return fde_func_0886_0x095c7c(a0, a1);
        case 887: return fde_func_0887_0x095cb4(a0, a1);
        case 888: return fde_func_0888_0x095d60(a0, a1);
        case 889: return fde_func_0889_0x095ddc(a0, a1);
        case 890: return fde_func_0890_0x095e14(a0, a1);
        case 891: return fde_func_0891_0x095f04(a0, a1);
        case 892: return fde_func_0892_0x095fd4(a0, a1);
        case 893: return fde_func_0893_0x096014(a0, a1);
        case 894: return fde_func_0894_0x096150(a0, a1);
        case 895: return fde_func_0895_0x096268(a0, a1);
        case 896: return fde_func_0896_0x096920(a0, a1);
        case 897: return fde_func_0897_0x096e64(a0, a1);
        case 898: return fde_func_0898_0x0970b4(a0, a1);
        case 899: return fde_func_0899_0x097244(a0, a1);
        case 900: return fde_func_0900_0x097248(a0, a1);
        case 901: return fde_func_0901_0x097370(a0, a1);
        case 902: return fde_func_0902_0x0973b4(a0, a1);
        case 903: return fde_func_0903_0x09752c(a0, a1);
        case 904: return fde_func_0904_0x0975d8(a0, a1);
        case 905: return fde_func_0905_0x097610(a0, a1);
        case 906: return fde_func_0906_0x0978dc(a0, a1);
        case 907: return fde_func_0907_0x0979bc(a0, a1);
        case 908: return fde_func_0908_0x097b38(a0, a1);
        case 909: return fde_func_0909_0x097ea8(a0, a1);
        case 910: return fde_func_0910_0x098028(a0, a1);
        case 911: return fde_func_0911_0x098374(a0, a1);
        case 912: return fde_func_0912_0x0983c0(a0, a1);
        case 913: return fde_func_0913_0x098578(a0, a1);
        case 914: return fde_func_0914_0x09874c(a0, a1);
        case 915: return fde_func_0915_0x098804(a0, a1);
        case 916: return fde_func_0916_0x0989f4(a0, a1);
        case 917: return fde_func_0917_0x098a40(a0, a1);
        case 918: return fde_func_0918_0x098a78(a0, a1);
        case 919: return fde_func_0919_0x098b18(a0, a1);
        case 920: return fde_func_0920_0x098b94(a0, a1);
        case 921: return fde_func_0921_0x098c4c(a0, a1);
        case 922: return fde_func_0922_0x098fc4(a0, a1);
        case 923: return fde_func_0923_0x0990c0(a0, a1);
        case 924: return fde_func_0924_0x0991c4(a0, a1);
        case 925: return fde_func_0925_0x099228(a0, a1);
        case 926: return fde_func_0926_0x099598(a0, a1);
        case 927: return fde_func_0927_0x099620(a0, a1);
        case 928: return fde_func_0928_0x099894(a0, a1);
        case 929: return fde_func_0929_0x0998ec(a0, a1);
        case 930: return fde_func_0930_0x0999f4(a0, a1);
        case 931: return fde_func_0931_0x099a2c(a0, a1);
        case 932: return fde_func_0932_0x099a64(a0, a1);
        case 933: return fde_func_0933_0x099a9c(a0, a1);
        case 934: return fde_func_0934_0x099b6c(a0, a1);
        case 935: return fde_func_0935_0x099c08(a0, a1);
        case 936: return fde_func_0936_0x099c54(a0, a1);
        case 937: return fde_func_0937_0x099d3c(a0, a1);
        case 938: return fde_func_0938_0x099d8c(a0, a1);
        case 939: return fde_func_0939_0x099dcc(a0, a1);
        case 940: return fde_func_0940_0x099efc(a0, a1);
        case 941: return fde_func_0941_0x09a0b8(a0, a1);
        case 942: return fde_func_0942_0x09a22c(a0, a1);
        case 943: return fde_func_0943_0x09a2f4(a0, a1);
        case 944: return fde_func_0944_0x09a590(a0, a1);
        case 945: return fde_func_0945_0x09a594(a0, a1);
        case 946: return fde_func_0946_0x09a6e8(a0, a1);
        case 947: return fde_func_0947_0x09a760(a0, a1);
        case 948: return fde_func_0948_0x09a8f8(a0, a1);
        case 949: return fde_func_0949_0x09af1c(a0, a1);
        case 950: return fde_func_0950_0x09b530(a0, a1);
        case 951: return fde_func_0951_0x09b5f8(a0, a1);
        case 952: return fde_func_0952_0x09b76c(a0, a1);
        case 953: return fde_func_0953_0x09b844(a0, a1);
        case 954: return fde_func_0954_0x09b860(a0, a1);
        case 955: return fde_func_0955_0x09c014(a0, a1);
        case 956: return fde_func_0956_0x09c1e0(a0, a1);
        case 957: return fde_func_0957_0x09c36c(a0, a1);
        case 958: return fde_func_0958_0x09c464(a0, a1);
        case 959: return fde_func_0959_0x09c648(a0, a1);
        case 960: return fde_func_0960_0x09c69c(a0, a1);
        case 961: return fde_func_0961_0x09c874(a0, a1);
        case 962: return fde_func_0962_0x09ca28(a0, a1);
        case 963: return fde_func_0963_0x09cbc0(a0, a1);
        case 964: return fde_func_0964_0x09cd10(a0, a1);
        case 965: return fde_func_0965_0x09cef0(a0, a1);
        case 966: return fde_func_0966_0x09d100(a0, a1);
        case 967: return fde_func_0967_0x09d1c8(a0, a1);
        case 968: return fde_func_0968_0x09d2ac(a0, a1);
        case 969: return fde_func_0969_0x09d588(a0, a1);
        case 970: return fde_func_0970_0x09d838(a0, a1);
        case 971: return fde_func_0971_0x09da40(a0, a1);
        case 972: return fde_func_0972_0x09e080(a0, a1);
        case 973: return fde_func_0973_0x09e1a8(a0, a1);
        case 974: return fde_func_0974_0x09e5a8(a0, a1);
        case 975: return fde_func_0975_0x09eb54(a0, a1);
        case 976: return fde_func_0976_0x09ec44(a0, a1);
        case 977: return fde_func_0977_0x09f300(a0, a1);
        case 978: return fde_func_0978_0x09f3f8(a0, a1);
        case 979: return fde_func_0979_0x09f58c(a0, a1);
        case 980: return fde_func_0980_0x09f68c(a0, a1);
        case 981: return fde_func_0981_0x09f760(a0, a1);
        case 982: return fde_func_0982_0x09f7d0(a0, a1);
        case 983: return fde_func_0983_0x09f81c(a0, a1);
        case 984: return fde_func_0984_0x09fa98(a0, a1);
        case 985: return fde_func_0985_0x09fae4(a0, a1);
        case 986: return fde_func_0986_0x09fb14(a0, a1);
        case 987: return fde_func_0987_0x09fc24(a0, a1);
        case 988: return fde_func_0988_0x09fc80(a0, a1);
        case 989: return fde_func_0989_0x09fe24(a0, a1);
        case 990: return fde_func_0990_0x09feb0(a0, a1);
        case 991: return fde_func_0991_0x09fefc(a0, a1);
        case 992: return fde_func_0992_0x09ff80(a0, a1);
        case 993: return fde_func_0993_0x0a02cc(a0, a1);
        case 994: return fde_func_0994_0x0a03cc(a0, a1);
        case 995: return fde_func_0995_0x0a044c(a0, a1);
        case 996: return fde_func_0996_0x0a078c(a0, a1);
        case 997: return fde_func_0997_0x0a089c(a0, a1);
        case 998: return fde_func_0998_0x0a0adc(a0, a1);
        case 999: return fde_func_0999_0x0a0b54(a0, a1);
        case 1000: return fde_func_1000_0x0a0bf4(a0, a1);
        case 1001: return fde_func_1001_0x0a0d1c(a0, a1);
        case 1002: return fde_func_1002_0x0a0e28(a0, a1);
        case 1003: return fde_func_1003_0x0a0eac(a0, a1);
        case 1004: return fde_func_1004_0x0a1258(a0, a1);
        case 1005: return fde_func_1005_0x0a13d0(a0, a1);
        case 1006: return fde_func_1006_0x0a14a0(a0, a1);
        case 1007: return fde_func_1007_0x0a1718(a0, a1);
        case 1008: return fde_func_1008_0x0a18a8(a0, a1);
        case 1009: return fde_func_1009_0x0a1938(a0, a1);
        case 1010: return fde_func_1010_0x0a1a24(a0, a1);
        case 1011: return fde_func_1011_0x0a1bfc(a0, a1);
        case 1012: return fde_func_1012_0x0a1dec(a0, a1);
        case 1013: return fde_func_1013_0x0a20dc(a0, a1);
        case 1014: return fde_func_1014_0x0a21d4(a0, a1);
        case 1015: return fde_func_1015_0x0a232c(a0, a1);
        case 1016: return fde_func_1016_0x0a2330(a0, a1);
        case 1017: return fde_func_1017_0x0a24f4(a0, a1);
        case 1018: return fde_func_1018_0x0a2538(a0, a1);
        case 1019: return fde_func_1019_0x0a2594(a0, a1);
        case 1020: return fde_func_1020_0x0a272c(a0, a1);
        case 1021: return fde_func_1021_0x0a2a84(a0, a1);
        case 1022: return fde_func_1022_0x0a2b6c(a0, a1);
        case 1023: return fde_func_1023_0x0a2e5c(a0, a1);
        case 1024: return fde_func_1024_0x0a33b8(a0, a1);
        case 1025: return fde_func_1025_0x0a3534(a0, a1);
        case 1026: return fde_func_1026_0x0a3718(a0, a1);
        case 1027: return fde_func_1027_0x0a395c(a0, a1);
        case 1028: return fde_func_1028_0x0a3a30(a0, a1);
        case 1029: return fde_func_1029_0x0a3aa8(a0, a1);
        case 1030: return fde_func_1030_0x0a3b60(a0, a1);
        case 1031: return fde_func_1031_0x0a3e28(a0, a1);
        case 1032: return fde_func_1032_0x0a3f34(a0, a1);
        case 1033: return fde_func_1033_0x0a3fbc(a0, a1);
        case 1034: return fde_func_1034_0x0a40e8(a0, a1);
        case 1035: return fde_func_1035_0x0a41b4(a0, a1);
        case 1036: return fde_func_1036_0x0a4280(a0, a1);
        case 1037: return fde_func_1037_0x0a4438(a0, a1);
        case 1038: return fde_func_1038_0x0a4654(a0, a1);
        case 1039: return fde_func_1039_0x0a4738(a0, a1);
        case 1040: return fde_func_1040_0x0a484c(a0, a1);
        case 1041: return fde_func_1041_0x0a49fc(a0, a1);
        case 1042: return fde_func_1042_0x0a4c4c(a0, a1);
        case 1043: return fde_func_1043_0x0a4dac(a0, a1);
        case 1044: return fde_func_1044_0x0a52ac(a0, a1);
        case 1045: return fde_func_1045_0x0a55ac(a0, a1);
        case 1046: return fde_func_1046_0x0a59b0(a0, a1);
        case 1047: return fde_func_1047_0x0a5c18(a0, a1);
        case 1048: return fde_func_1048_0x0a6154(a0, a1);
        case 1049: return fde_func_1049_0x0a6594(a0, a1);
        case 1050: return fde_func_1050_0x0a65a8(a0, a1);
        case 1051: return fde_func_1051_0x0a6a20(a0, a1);
        case 1052: return fde_func_1052_0x0a6c8c(a0, a1);
        case 1053: return fde_func_1053_0x0a6cc0(a0, a1);
        case 1054: return fde_func_1054_0x0a6f5c(a0, a1);
        case 1055: return fde_func_1055_0x0a7040(a0, a1);
        case 1056: return fde_func_1056_0x0a7408(a0, a1);
        case 1057: return fde_func_1057_0x0a7800(a0, a1);
        case 1058: return fde_func_1058_0x0a7cd4(a0, a1);
        case 1059: return fde_func_1059_0x0a7ecc(a0, a1);
        case 1060: return fde_func_1060_0x0a7fb4(a0, a1);
        case 1061: return fde_func_1061_0x0a816c(a0, a1);
        case 1062: return fde_func_1062_0x0a81e8(a0, a1);
        case 1063: return fde_func_1063_0x0a8338(a0, a1);
        case 1064: return fde_func_1064_0x0a8420(a0, a1);
        case 1065: return fde_func_1065_0x0a85cc(a0, a1);
        case 1066: return fde_func_1066_0x0a85f8(a0, a1);
        case 1067: return fde_func_1067_0x0a8614(a0, a1);
        case 1068: return fde_func_1068_0x0a89f4(a0, a1);
        case 1069: return fde_func_1069_0x0a8b50(a0, a1);
        case 1070: return fde_func_1070_0x0a8cf4(a0, a1);
        case 1071: return fde_func_1071_0x0a8d84(a0, a1);
        case 1072: return fde_func_1072_0x0a8e74(a0, a1);
        case 1073: return fde_func_1073_0x0a8f74(a0, a1);
        case 1074: return fde_func_1074_0x0a909c(a0, a1);
        case 1075: return fde_func_1075_0x0a9220(a0, a1);
        case 1076: return fde_func_1076_0x0a9318(a0, a1);
        case 1077: return fde_func_1077_0x0a9334(a0, a1);
        case 1078: return fde_func_1078_0x0a9448(a0, a1);
        case 1079: return fde_func_1079_0x0a9564(a0, a1);
        case 1080: return fde_func_1080_0x0a965c(a0, a1);
        case 1081: return fde_func_1081_0x0a9760(a0, a1);
        case 1082: return fde_func_1082_0x0a9984(a0, a1);
        case 1083: return fde_func_1083_0x0a99a8(a0, a1);
        case 1084: return fde_func_1084_0x0a99cc(a0, a1);
        case 1085: return fde_func_1085_0x0a9ad0(a0, a1);
        case 1086: return fde_func_1086_0x0a9d48(a0, a1);
        case 1087: return fde_func_1087_0x0a9e58(a0, a1);
        case 1088: return fde_func_1088_0x0a9fe0(a0, a1);
        case 1089: return fde_func_1089_0x0aa084(a0, a1);
        case 1090: return fde_func_1090_0x0aa148(a0, a1);
        case 1091: return fde_func_1091_0x0aa1ec(a0, a1);
        case 1092: return fde_func_1092_0x0aa2b0(a0, a1);
        case 1093: return fde_func_1093_0x0aa674(a0, a1);
        case 1094: return fde_func_1094_0x0aa78c(a0, a1);
        case 1095: return fde_func_1095_0x0aac20(a0, a1);
        case 1096: return fde_func_1096_0x0aac38(a0, a1);
        case 1097: return fde_func_1097_0x0ab0c4(a0, a1);
        case 1098: return fde_func_1098_0x0ab0d4(a0, a1);
        case 1099: return fde_func_1099_0x0ab380(a0, a1);
        case 1100: return fde_func_1100_0x0ab5b0(a0, a1);
        case 1101: return fde_func_1101_0x0ab8c8(a0, a1);
        case 1102: return fde_func_1102_0x0aba74(a0, a1);
        case 1103: return fde_func_1103_0x0abb4c(a0, a1);
        case 1104: return fde_func_1104_0x0ac008(a0, a1);
        case 1105: return fde_func_1105_0x0ac220(a0, a1);
        case 1106: return fde_func_1106_0x0ac234(a0, a1);
        case 1107: return fde_func_1107_0x0ac238(a0, a1);
        case 1108: return fde_func_1108_0x0ac898(a0, a1);
        case 1109: return fde_func_1109_0x0ac9c4(a0, a1);
        case 1110: return fde_func_1110_0x0aceac(a0, a1);
        case 1111: return fde_func_1111_0x0ad318(a0, a1);
        case 1112: return fde_func_1112_0x0ad514(a0, a1);
        case 1113: return fde_func_1113_0x0ad77c(a0, a1);
        case 1114: return fde_func_1114_0x0adbc8(a0, a1);
        case 1115: return fde_func_1115_0x0adca0(a0, a1);
        case 1116: return fde_func_1116_0x0add00(a0, a1);
        case 1117: return fde_func_1117_0x0add14(a0, a1);
        case 1118: return fde_func_1118_0x0ae1c0(a0, a1);
        case 1119: return fde_func_1119_0x0ae264(a0, a1);
        case 1120: return fde_func_1120_0x0ae550(a0, a1);
        case 1121: return fde_func_1121_0x0ae564(a0, a1);
        case 1122: return fde_func_1122_0x0ae844(a0, a1);
        case 1123: return fde_func_1123_0x0ae8c4(a0, a1);
        case 1124: return fde_func_1124_0x0aeaa4(a0, a1);
        case 1125: return fde_func_1125_0x0aeb04(a0, a1);
        case 1126: return fde_func_1126_0x0aecb8(a0, a1);
        case 1127: return fde_func_1127_0x0aecd0(a0, a1);
        case 1128: return fde_func_1128_0x0aeedc(a0, a1);
        case 1129: return fde_func_1129_0x0af1dc(a0, a1);
        case 1130: return fde_func_1130_0x0af430(a0, a1);
        case 1131: return fde_func_1131_0x0af620(a0, a1);
        case 1132: return fde_func_1132_0x0af63c(a0, a1);
        case 1133: return fde_func_1133_0x0b0164(a0, a1);
        case 1134: return fde_func_1134_0x0b0588(a0, a1);
        case 1135: return fde_func_1135_0x0b08a4(a0, a1);
        case 1136: return fde_func_1136_0x0b09b0(a0, a1);
        case 1137: return fde_func_1137_0x0b0a20(a0, a1);
        case 1138: return fde_func_1138_0x0b0ad4(a0, a1);
        case 1139: return fde_func_1139_0x0b0bb4(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com