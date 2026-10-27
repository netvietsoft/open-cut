// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 2/5 for libfast_engine_RelWithDebInfo.so
// Phân mảnh FDE AArch64 C++17 sạch 2/5 cho libfast_engine_RelWithDebInfo.so
// Covers FDE indices [417 .. 833] out of 2,082 total FDEs (.eh_frame_hdr @ 0x1127c8)
// Bao phủ chỉ số FDE [417 .. 833] trên tổng số 2,082 FDE (.eh_frame_hdr @ 0x1127c8)
// ============================================================================
#include "fast_engine_rel_core.h"

namespace fast_engine {

// FDE #0417 | PC: 0x07153c | FDE: 0x11a588 | Size: 108 bytes [_ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev]
// Hàm FDE #0417 | Địa chỉ PC: 0x07153c | Địa chỉ FDE: 0x11a588 | Kích thước: 108 bytes
//   0x07153c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x071540: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071544: 910043FD  add      x29, sp, #0x10
//   0x071548: D0000668  adrp     x8, #0x13f000
static inline uint64_t fde_func_0417_0x07153c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07153cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a588ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0418 | PC: 0x0715a8 | FDE: 0x11a5a8 | Size: 256 bytes
// Hàm FDE #0418 | Địa chỉ PC: 0x0715a8 | Địa chỉ FDE: 0x11a5a8 | Kích thước: 256 bytes
//   0x0715a8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0715ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0715b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0715b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0418_0x0715a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0715a8ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11a5a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0419 | PC: 0x071894 | FDE: 0x11a848 | Size: 96 bytes [_ZN11fast_engine17AllocDateTimeTypeEPNS_6EngineE]
// Hàm FDE #0419 | Địa chỉ PC: 0x071894 | Địa chỉ FDE: 0x11a848 | Kích thước: 96 bytes
//   0x071894: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07189c: 910043FD  add      x29, sp, #0x10
//   0x0718a0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0419_0x071894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071894ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a848ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0420 | PC: 0x0718f4 | FDE: 0x11a5d8 | Size: 256 bytes [_ZN11fast_engine16InitDateTimeTypeEPNS_6EngineE]
// Hàm FDE #0420 | Địa chỉ PC: 0x0718f4 | Địa chỉ FDE: 0x11a5d8 | Kích thước: 256 bytes
//   0x0718f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0718f8: 910003FD  mov      x29, sp
//   0x0718fc: D0000669  adrp     x9, #0x13f000
//   0x071900: F9447529  ldr      x9, [x9, #0x8e8]
static inline uint64_t fde_func_0420_0x0718f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0718f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11a5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0421 | PC: 0x071ab0 | FDE: 0x11a870 | Size: 256 bytes
// Hàm FDE #0421 | Địa chỉ PC: 0x071ab0 | Địa chỉ FDE: 0x11a870 | Kích thước: 256 bytes
//   0x071ab0: D10543FF  sub      sp, sp, #0x150
//   0x071ab4: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x071ab8: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x071abc: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_0421_0x071ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071ab0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x11a870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0422 | PC: 0x071e4c | FDE: 0x11a8a8 | Size: 256 bytes
// Hàm FDE #0422 | Địa chỉ PC: 0x071e4c | Địa chỉ FDE: 0x11a8a8 | Kích thước: 256 bytes
//   0x071e4c: D10203FF  sub      sp, sp, #0x80
//   0x071e50: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x071e54: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x071e58: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0422_0x071e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071e4cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x11a8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0423 | PC: 0x07203c | FDE: 0x11a8d8 | Size: 256 bytes
// Hàm FDE #0423 | Địa chỉ PC: 0x07203c | Địa chỉ FDE: 0x11a8d8 | Kích thước: 256 bytes
//   0x07203c: D10283FF  sub      sp, sp, #0xa0
//   0x072040: F9003BF5  str      x21, [sp, #0x70]
//   0x072044: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x072048: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0423_0x07203c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07203cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x11a8d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0424 | PC: 0x07217c | FDE: 0x11a900 | Size: 256 bytes
// Hàm FDE #0424 | Địa chỉ PC: 0x07217c | Địa chỉ FDE: 0x11a900 | Kích thước: 256 bytes
//   0x07217c: D10243FF  sub      sp, sp, #0x90
//   0x072180: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x072184: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x072188: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0424_0x07217c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07217cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x11a900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0425 | PC: 0x0723bc | FDE: 0x11a930 | Size: 256 bytes
// Hàm FDE #0425 | Địa chỉ PC: 0x0723bc | Địa chỉ FDE: 0x11a930 | Kích thước: 256 bytes
//   0x0723bc: D10303FF  sub      sp, sp, #0xc0
//   0x0723c0: FD004BE8  str      d8, [sp, #0x90]
//   0x0723c4: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0723c8: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0425_0x0723bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0723bcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xfd004be8ULL) ^ 0x11a930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0426 | PC: 0x072568 | FDE: 0x11a958 | Size: 256 bytes
// Hàm FDE #0426 | Địa chỉ PC: 0x072568 | Địa chỉ FDE: 0x11a958 | Kích thước: 256 bytes
//   0x072568: D10543FF  sub      sp, sp, #0x150
//   0x07256c: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x072570: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x072574: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_0426_0x072568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072568ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x11a958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0427 | PC: 0x0727a4 | FDE: 0x11a5f8 | Size: 256 bytes
// Hàm FDE #0427 | Địa chỉ PC: 0x0727a4 | Địa chỉ FDE: 0x11a5f8 | Kích thước: 256 bytes
//   0x0727a4: D10503FF  sub      sp, sp, #0x140
//   0x0727a8: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x0727ac: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0727b0: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0427_0x0727a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0727a4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x11a5f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0428 | PC: 0x072af8 | FDE: 0x11a990 | Size: 256 bytes
// Hàm FDE #0428 | Địa chỉ PC: 0x072af8 | Địa chỉ FDE: 0x11a990 | Kích thước: 256 bytes
//   0x072af8: D10343FF  sub      sp, sp, #0xd0
//   0x072afc: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x072b00: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x072b04: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0428_0x072af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072af8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x11a990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0429 | PC: 0x072e98 | FDE: 0x11a9c8 | Size: 256 bytes
// Hàm FDE #0429 | Địa chỉ PC: 0x072e98 | Địa chỉ FDE: 0x11a9c8 | Kích thước: 256 bytes
//   0x072e98: D10343FF  sub      sp, sp, #0xd0
//   0x072e9c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x072ea0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x072ea4: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0429_0x072e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072e98ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x11a9c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0430 | PC: 0x073238 | FDE: 0x11aa00 | Size: 96 bytes [_ZN11fast_engine18AllocTimeDeltaTypeEPNS_6EngineE]
// Hàm FDE #0430 | Địa chỉ PC: 0x073238 | Địa chỉ FDE: 0x11aa00 | Kích thước: 96 bytes
//   0x073238: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07323c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073240: 910043FD  add      x29, sp, #0x10
//   0x073244: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0430_0x073238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073238ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11aa00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0431 | PC: 0x073298 | FDE: 0x11a620 | Size: 52 bytes [_ZN11fast_engine17InitTimeDeltaTypeEPNS_6EngineE]
// Hàm FDE #0431 | Địa chỉ PC: 0x073298 | Địa chỉ FDE: 0x11a620 | Kích thước: 52 bytes
//   0x073298: 90000668  adrp     x8, #0x13f000
//   0x07329c: F9443508  ldr      x8, [x8, #0x868]
//   0x0732a0: 90000009  adrp     x9, #0x73000
//   0x0732a4: 9000000A  adrp     x10, #0x73000
static inline uint64_t fde_func_0431_0x073298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073298ULL ^ (static_cast<uint64_t>(0x90000668ULL) << 13);
    acc = (acc + a1 + 0xf9443508ULL) ^ 0x11a620ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0432 | PC: 0x0732cc | FDE: 0x11aa28 | Size: 256 bytes
// Hàm FDE #0432 | Địa chỉ PC: 0x0732cc | Địa chỉ FDE: 0x11aa28 | Kích thước: 256 bytes
//   0x0732cc: D102C3FF  sub      sp, sp, #0xb0
//   0x0732d0: F9002BFB  str      x27, [sp, #0x50]
//   0x0732d4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0732d8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0432_0x0732cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0732ccULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x11aa28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0433 | PC: 0x073594 | FDE: 0x11a638 | Size: 256 bytes
// Hàm FDE #0433 | Địa chỉ PC: 0x073594 | Địa chỉ FDE: 0x11a638 | Kích thước: 256 bytes
//   0x073594: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x073598: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07359c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0735a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0433_0x073594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073594ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11a638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0434 | PC: 0x0736c8 | FDE: 0x11aa60 | Size: 252 bytes
// Hàm FDE #0434 | Địa chỉ PC: 0x0736c8 | Địa chỉ FDE: 0x11aa60 | Kích thước: 252 bytes
//   0x0736c8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0736cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0736d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0736d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0434_0x0736c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0736c8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11aa60ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0435 | PC: 0x0737c4 | FDE: 0x11aa90 | Size: 252 bytes
// Hàm FDE #0435 | Địa chỉ PC: 0x0737c4 | Địa chỉ FDE: 0x11aa90 | Kích thước: 252 bytes
//   0x0737c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0737c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0737cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0737d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0435_0x0737c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0737c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11aa90ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0436 | PC: 0x0738c0 | FDE: 0x11a658 | Size: 192 bytes [_ZN11fast_engine9TimeDeltaC1EPNS_6EngineEPNS_7TypeObjExxxxx]
// Hàm FDE #0436 | Địa chỉ PC: 0x0738c0 | Địa chỉ FDE: 0x11a658 | Kích thước: 192 bytes
//   0x0738c0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0738c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0738c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0738cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0436_0x0738c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0738c0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11a658ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0437 | PC: 0x073980 | FDE: 0x11aac0 | Size: 256 bytes [_ZN11fast_engine18InitDatetimeModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0437 | Địa chỉ PC: 0x073980 | Địa chỉ FDE: 0x11aac0 | Kích thước: 256 bytes
//   0x073980: D10183FF  sub      sp, sp, #0x60
//   0x073984: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x073988: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07398c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0437_0x073980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073980ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11aac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0438 | PC: 0x073bf0 | FDE: 0x11a680 | Size: 36 bytes [_ZN11fast_engine8DateTimeD0Ev]
// Hàm FDE #0438 | Địa chỉ PC: 0x073bf0 | Địa chỉ FDE: 0x11a680 | Kích thước: 36 bytes
//   0x073bf0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073bf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073bf8: 910043FD  add      x29, sp, #0x10
//   0x073bfc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0438_0x073bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073bf0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a680ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0439 | PC: 0x073c14 | FDE: 0x11a6a0 | Size: 36 bytes [_ZN11fast_engine9TimeDeltaD0Ev]
// Hàm FDE #0439 | Địa chỉ PC: 0x073c14 | Địa chỉ FDE: 0x11a6a0 | Kích thước: 36 bytes
//   0x073c14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073c18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073c1c: 910043FD  add      x29, sp, #0x10
//   0x073c20: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0439_0x073c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073c14ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a6a0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0440 | PC: 0x073c38 | FDE: 0x11a6c0 | Size: 124 bytes [_ZTv0_n24_NSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev]
// Hàm FDE #0440 | Địa chỉ PC: 0x073c38 | Địa chỉ FDE: 0x11a6c0 | Kích thước: 124 bytes
//   0x073c38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x073c3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073c40: 910043FD  add      x29, sp, #0x10
//   0x073c44: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0440_0x073c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073c38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a6c0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0441 | PC: 0x073cb4 | FDE: 0x11a6e0 | Size: 8 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev]
// Hàm FDE #0441 | Địa chỉ PC: 0x073cb4 | Địa chỉ FDE: 0x11a6e0 | Kích thước: 8 bytes
//   0x073cb4: 91002000  add      x0, x0, #8
//   0x073cb8: 17FF3AD6  b        #0x42810
static inline uint64_t fde_func_0441_0x073cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073cb4ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17ff3ad6ULL) ^ 0x11a6e0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0442 | PC: 0x073cbc | FDE: 0x11a6f8 | Size: 40 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0442 | Địa chỉ PC: 0x073cbc | Địa chỉ FDE: 0x11a6f8 | Kích thước: 40 bytes
//   0x073cbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073cc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073cc4: 910043FD  add      x29, sp, #0x10
//   0x073cc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0442_0x073cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073cbcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a6f8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0443 | PC: 0x073ce4 | FDE: 0x11a718 | Size: 20 bytes [_ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev]
// Hàm FDE #0443 | Địa chỉ PC: 0x073ce4 | Địa chỉ FDE: 0x11a718 | Kích thước: 20 bytes
//   0x073ce4: F9400008  ldr      x8, [x0]
//   0x073ce8: F85E8108  ldur     x8, [x8, #-0x18]
//   0x073cec: 8B080008  add      x8, x0, x8
//   0x073cf0: 91002100  add      x0, x8, #8
static inline uint64_t fde_func_0443_0x073ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073ce4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x11a718ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0444 | PC: 0x073cf8 | FDE: 0x11a730 | Size: 48 bytes [_ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0444 | Địa chỉ PC: 0x073cf8 | Địa chỉ FDE: 0x11a730 | Kích thước: 48 bytes
//   0x073cf8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073cfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073d00: 910043FD  add      x29, sp, #0x10
//   0x073d04: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0444_0x073cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073cf8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a730ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0445 | PC: 0x073d28 | FDE: 0x11a750 | Size: 116 bytes [_ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev]
// Hàm FDE #0445 | Địa chỉ PC: 0x073d28 | Địa chỉ FDE: 0x11a750 | Kích thước: 116 bytes
//   0x073d28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073d2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073d30: 910043FD  add      x29, sp, #0x10
//   0x073d34: 90000668  adrp     x8, #0x13f000
static inline uint64_t fde_func_0445_0x073d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073d28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a750ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0446 | PC: 0x073d9c | FDE: 0x11a770 | Size: 132 bytes [_ZTv0_n24_NSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev]
// Hàm FDE #0446 | Địa chỉ PC: 0x073d9c | Địa chỉ FDE: 0x11a770 | Kích thước: 132 bytes
//   0x073d9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x073da0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073da4: 910043FD  add      x29, sp, #0x10
//   0x073da8: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0446_0x073d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073d9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a770ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0447 | PC: 0x073e20 | FDE: 0x11a790 | Size: 256 bytes
// Hàm FDE #0447 | Địa chỉ PC: 0x073e20 | Địa chỉ FDE: 0x11a790 | Kích thước: 256 bytes
//   0x073e20: 5280D7A9  mov      w9, #0x6bd
//   0x073e24: 51000408  sub      w8, w0, #1
//   0x073e28: 72A72D69  movk     w9, #0x396b, lsl #16
//   0x073e2c: 9B297D09  smull    x9, w8, w9
static inline uint64_t fde_func_0447_0x073e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073e20ULL ^ (static_cast<uint64_t>(0x5280d7a9ULL) << 13);
    acc = (acc + a1 + 0x51000408ULL) ^ 0x11a790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0448 | PC: 0x073ffc | FDE: 0x11ad00 | Size: 256 bytes [_ZN11fast_engine16GetEnumMemberMapEv]
// Hàm FDE #0448 | Địa chỉ PC: 0x073ffc | Địa chỉ FDE: 0x11ad00 | Kích thước: 256 bytes
//   0x073ffc: D10183FF  sub      sp, sp, #0x60
//   0x074000: F90013F7  str      x23, [sp, #0x20]
//   0x074004: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x074008: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0448_0x073ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073ffcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11ad00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0449 | PC: 0x074170 | FDE: 0x11ad30 | Size: 256 bytes [_ZN11fast_engine11GetEnumNameEv]
// Hàm FDE #0449 | Địa chỉ PC: 0x074170 | Địa chỉ FDE: 0x11ad30 | Kích thước: 256 bytes
//   0x074170: D10183FF  sub      sp, sp, #0x60
//   0x074174: F90013F7  str      x23, [sp, #0x20]
//   0x074178: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07417c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0449_0x074170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074170ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11ad30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0450 | PC: 0x0742e4 | FDE: 0x11ad60 | Size: 256 bytes [_ZN11fast_engine12GetEnumValueEv]
// Hàm FDE #0450 | Địa chỉ PC: 0x0742e4 | Địa chỉ FDE: 0x11ad60 | Kích thước: 256 bytes
//   0x0742e4: D10183FF  sub      sp, sp, #0x60
//   0x0742e8: F90013F7  str      x23, [sp, #0x20]
//   0x0742ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0742f0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0450_0x0742e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0742e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11ad60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0451 | PC: 0x074458 | FDE: 0x11ad90 | Size: 96 bytes [_ZN11fast_engine17AllocEnumDictTypeEPNS_6EngineE]
// Hàm FDE #0451 | Địa chỉ PC: 0x074458 | Địa chỉ FDE: 0x11ad90 | Kích thước: 96 bytes
//   0x074458: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07445c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074460: 910043FD  add      x29, sp, #0x10
//   0x074464: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0451_0x074458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074458ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ad90ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0452 | PC: 0x0744b8 | FDE: 0x11aaf0 | Size: 56 bytes [_ZN11fast_engine16InitEnumDictTypeEPNS_6EngineE]
// Hàm FDE #0452 | Địa chỉ PC: 0x0744b8 | Địa chỉ FDE: 0x11aaf0 | Kích thước: 56 bytes
//   0x0744b8: F0000648  adrp     x8, #0x13f000
//   0x0744bc: F9472508  ldr      x8, [x8, #0xe48]
//   0x0744c0: F000064A  adrp     x10, #0x13f000
//   0x0744c4: 90000669  adrp     x9, #0x140000
static inline uint64_t fde_func_0452_0x0744b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0744b8ULL ^ (static_cast<uint64_t>(0xf0000648ULL) << 13);
    acc = (acc + a1 + 0xf9472508ULL) ^ 0x11aaf0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0453 | PC: 0x0744f0 | FDE: 0x11ab08 | Size: 216 bytes
// Hàm FDE #0453 | Địa chỉ PC: 0x0744f0 | Địa chỉ FDE: 0x11ab08 | Kích thước: 216 bytes
//   0x0744f0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0744f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0744f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0744fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0453_0x0744f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0744f0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11ab08ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0454 | PC: 0x0745c8 | FDE: 0x11adb8 | Size: 72 bytes
// Hàm FDE #0454 | Địa chỉ PC: 0x0745c8 | Địa chỉ FDE: 0x11adb8 | Kích thước: 72 bytes
//   0x0745c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0745cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0745d0: 910043FD  add      x29, sp, #0x10
//   0x0745d4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0454_0x0745c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0745c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11adb8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0455 | PC: 0x074610 | FDE: 0x11ade0 | Size: 96 bytes [_ZN11fast_engine20AllocProtoMemberTypeEPNS_6EngineE]
// Hàm FDE #0455 | Địa chỉ PC: 0x074610 | Địa chỉ FDE: 0x11ade0 | Kích thước: 96 bytes
//   0x074610: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074614: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074618: 910043FD  add      x29, sp, #0x10
//   0x07461c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0455_0x074610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074610ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ade0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0456 | PC: 0x074670 | FDE: 0x11ab30 | Size: 196 bytes [_ZN11fast_engine19InitProtoMemberTypeEPNS_6EngineE]
// Hàm FDE #0456 | Địa chỉ PC: 0x074670 | Địa chỉ FDE: 0x11ab30 | Kích thước: 196 bytes
//   0x074670: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x074674: 910003FD  mov      x29, sp
//   0x074678: F0000649  adrp     x9, #0x13f000
//   0x07467c: F945D529  ldr      x9, [x9, #0xba8]
static inline uint64_t fde_func_0456_0x074670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074670ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ab30ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0457 | PC: 0x074734 | FDE: 0x11ab50 | Size: 256 bytes
// Hàm FDE #0457 | Địa chỉ PC: 0x074734 | Địa chỉ FDE: 0x11ab50 | Kích thước: 256 bytes
//   0x074734: D10183FF  sub      sp, sp, #0x60
//   0x074738: F90013F7  str      x23, [sp, #0x20]
//   0x07473c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x074740: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0457_0x074734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074734ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11ab50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0458 | PC: 0x074850 | FDE: 0x11ab78 | Size: 56 bytes
// Hàm FDE #0458 | Địa chỉ PC: 0x074850 | Địa chỉ FDE: 0x11ab78 | Kích thước: 56 bytes
//   0x074850: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x074854: 910003FD  mov      x29, sp
//   0x074858: AA0103E8  mov      x8, x1
//   0x07485c: A9400841  ldp      x1, x2, [x2]
static inline uint64_t fde_func_0458_0x074850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074850ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ab78ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0459 | PC: 0x074888 | FDE: 0x11ae08 | Size: 96 bytes [_ZN11fast_engine17AllocEnumMetaTypeEPNS_6EngineE]
// Hàm FDE #0459 | Địa chỉ PC: 0x074888 | Địa chỉ FDE: 0x11ae08 | Kích thước: 96 bytes
//   0x074888: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07488c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074890: 910043FD  add      x29, sp, #0x10
//   0x074894: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0459_0x074888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074888ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ae08ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0460 | PC: 0x0748e8 | FDE: 0x11ab98 | Size: 220 bytes [_ZN11fast_engine16InitEnumMetaTypeEPNS_6EngineE]
// Hàm FDE #0460 | Địa chỉ PC: 0x0748e8 | Địa chỉ FDE: 0x11ab98 | Kích thước: 220 bytes
//   0x0748e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0748ec: 910003FD  mov      x29, sp
//   0x0748f0: F0000649  adrp     x9, #0x13f000
//   0x0748f4: F947E929  ldr      x9, [x9, #0xfd0]
static inline uint64_t fde_func_0460_0x0748e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0748e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ab98ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0461 | PC: 0x0749c4 | FDE: 0x11ae30 | Size: 256 bytes
// Hàm FDE #0461 | Địa chỉ PC: 0x0749c4 | Địa chỉ FDE: 0x11ae30 | Kích thước: 256 bytes
//   0x0749c4: D10283FF  sub      sp, sp, #0xa0
//   0x0749c8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0749cc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0749d0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0461_0x0749c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0749c4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x11ae30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0462 | PC: 0x074cf0 | FDE: 0x11ae68 | Size: 72 bytes
// Hàm FDE #0462 | Địa chỉ PC: 0x074cf0 | Địa chỉ FDE: 0x11ae68 | Kích thước: 72 bytes
//   0x074cf0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074cf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074cf8: 910043FD  add      x29, sp, #0x10
//   0x074cfc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0462_0x074cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074cf0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ae68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0463 | PC: 0x074d38 | FDE: 0x11ae90 | Size: 176 bytes
// Hàm FDE #0463 | Địa chỉ PC: 0x074d38 | Địa chỉ FDE: 0x11ae90 | Kích thước: 176 bytes
//   0x074d38: D10103FF  sub      sp, sp, #0x40
//   0x074d3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x074d40: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x074d44: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0463_0x074d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074d38ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x11ae90ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0464 | PC: 0x074de8 | FDE: 0x11aeb8 | Size: 96 bytes [_ZN11fast_engine13AllocEnumTypeEPNS_6EngineE]
// Hàm FDE #0464 | Địa chỉ PC: 0x074de8 | Địa chỉ FDE: 0x11aeb8 | Kích thước: 96 bytes
//   0x074de8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074dec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074df0: 910043FD  add      x29, sp, #0x10
//   0x074df4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0464_0x074de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074de8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11aeb8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0465 | PC: 0x074e48 | FDE: 0x11abb8 | Size: 240 bytes [_ZN11fast_engine12InitEnumTypeEPNS_6EngineE]
// Hàm FDE #0465 | Địa chỉ PC: 0x074e48 | Địa chỉ FDE: 0x11abb8 | Kích thước: 240 bytes
//   0x074e48: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x074e4c: 910003FD  mov      x29, sp
//   0x074e50: F0000649  adrp     x9, #0x13f000
//   0x074e54: F9446129  ldr      x9, [x9, #0x8c0]
static inline uint64_t fde_func_0465_0x074e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074e48ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11abb8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0466 | PC: 0x074f38 | FDE: 0x11abd8 | Size: 256 bytes
// Hàm FDE #0466 | Địa chỉ PC: 0x074f38 | Địa chỉ FDE: 0x11abd8 | Kích thước: 256 bytes
//   0x074f38: D10203FF  sub      sp, sp, #0x80
//   0x074f3c: F90013FB  str      x27, [sp, #0x20]
//   0x074f40: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x074f44: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0466_0x074f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074f38ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x11abd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0467 | PC: 0x075208 | FDE: 0x11ac08 | Size: 256 bytes
// Hàm FDE #0467 | Địa chỉ PC: 0x075208 | Địa chỉ FDE: 0x11ac08 | Kích thước: 256 bytes
//   0x075208: D10143FF  sub      sp, sp, #0x50
//   0x07520c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x075210: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x075214: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0467_0x075208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075208ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x11ac08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0468 | PC: 0x075320 | FDE: 0x11aee0 | Size: 256 bytes
// Hàm FDE #0468 | Địa chỉ PC: 0x075320 | Địa chỉ FDE: 0x11aee0 | Kích thước: 256 bytes
//   0x075320: D101C3FF  sub      sp, sp, #0x70
//   0x075324: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x075328: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x07532c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0468_0x075320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075320ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x11aee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0469 | PC: 0x075550 | FDE: 0x11ac30 | Size: 120 bytes
// Hàm FDE #0469 | Địa chỉ PC: 0x075550 | Địa chỉ FDE: 0x11ac30 | Kích thước: 120 bytes
//   0x075550: D10103FF  sub      sp, sp, #0x40
//   0x075554: F9000BF5  str      x21, [sp, #0x10]
//   0x075558: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07555c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0469_0x075550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075550ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x11ac30ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0470 | PC: 0x0755c8 | FDE: 0x11ac50 | Size: 120 bytes
// Hàm FDE #0470 | Địa chỉ PC: 0x0755c8 | Địa chỉ FDE: 0x11ac50 | Kích thước: 120 bytes
//   0x0755c8: D10103FF  sub      sp, sp, #0x40
//   0x0755cc: F9000BF5  str      x21, [sp, #0x10]
//   0x0755d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0755d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0470_0x0755c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0755c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x11ac50ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0471 | PC: 0x075640 | FDE: 0x11ac70 | Size: 16 bytes
// Hàm FDE #0471 | Địa chỉ PC: 0x075640 | Địa chỉ FDE: 0x11ac70 | Kích thước: 16 bytes
//   0x075640: AA0003E8  mov      x8, x0
//   0x075644: AA0103E0  mov      x0, x1
//   0x075648: AA0803E1  mov      x1, x8
//   0x07564c: 17FFFF35  b        #0x75320
static inline uint64_t fde_func_0471_0x075640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075640ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x11ac70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0472 | PC: 0x075650 | FDE: 0x11af18 | Size: 256 bytes [_ZN11fast_engine14InitEnumModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0472 | Địa chỉ PC: 0x075650 | Địa chỉ FDE: 0x11af18 | Kích thước: 256 bytes
//   0x075650: D101C3FF  sub      sp, sp, #0x70
//   0x075654: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x075658: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x07565c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0472_0x075650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075650ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x11af18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0473 | PC: 0x075bbc | FDE: 0x11af50 | Size: 216 bytes [_ZN11fast_engine8EnumDictC2EPNS_6EngineE]
// Hàm FDE #0473 | Địa chỉ PC: 0x075bbc | Địa chỉ FDE: 0x11af50 | Kích thước: 216 bytes
//   0x075bbc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x075bc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x075bc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x075bc8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0473_0x075bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075bbcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11af50ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0474 | PC: 0x075c94 | FDE: 0x11ac88 | Size: 36 bytes [_ZN11fast_engine8EnumDictD0Ev]
// Hàm FDE #0474 | Địa chỉ PC: 0x075c94 | Địa chỉ FDE: 0x11ac88 | Kích thước: 36 bytes
//   0x075c94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x075c98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075c9c: 910043FD  add      x29, sp, #0x10
//   0x075ca0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0474_0x075c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075c94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ac88ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0475 | PC: 0x075cb8 | FDE: 0x11aca8 | Size: 88 bytes [_ZN11fast_engine8EnumDict5ClearEPNS_6EngineE]
// Hàm FDE #0475 | Địa chỉ PC: 0x075cb8 | Địa chỉ FDE: 0x11aca8 | Kích thước: 88 bytes
//   0x075cb8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x075cbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075cc0: 910043FD  add      x29, sp, #0x10
//   0x075cc4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0475_0x075cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075cb8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11aca8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0476 | PC: 0x075d10 | FDE: 0x11acc8 | Size: 36 bytes [_ZN11fast_engine14ProtoMemberObjD0Ev]
// Hàm FDE #0476 | Địa chỉ PC: 0x075d10 | Địa chỉ FDE: 0x11acc8 | Kích thước: 36 bytes
//   0x075d10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x075d14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075d18: 910043FD  add      x29, sp, #0x10
//   0x075d1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0476_0x075d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075d10ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11acc8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0477 | PC: 0x075d34 | FDE: 0x11ace8 | Size: 52 bytes [_ZN11fast_engine14ProtoMemberObj5ClearEPNS_6EngineE]
// Hàm FDE #0477 | Địa chỉ PC: 0x075d34 | Địa chỉ FDE: 0x11ace8 | Kích thước: 52 bytes
//   0x075d34: F9402008  ldr      x8, [x0, #0x40]
//   0x075d38: B9402109  ldr      w9, [x8, #0x20]
//   0x075d3c: 7100093F  cmp      w9, #2
//   0x075d40: 540000C0  b.eq     #0x75d58
static inline uint64_t fde_func_0477_0x075d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075d34ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xb9402109ULL) ^ 0x11ace8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0478 | PC: 0x075d68 | FDE: 0x11b490 | Size: 96 bytes [_ZN11fast_engine24AllocJSONDecodeErrorTypeEPNS_6EngineE]
// Hàm FDE #0478 | Địa chỉ PC: 0x075d68 | Địa chỉ FDE: 0x11b490 | Kích thước: 96 bytes
//   0x075d68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x075d6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075d70: 910043FD  add      x29, sp, #0x10
//   0x075d74: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0478_0x075d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075d68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b490ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0479 | PC: 0x075dc8 | FDE: 0x11af78 | Size: 80 bytes [_ZN11fast_engine23InitJSONDecodeErrorTypeEPNS_6EngineE]
// Hàm FDE #0479 | Địa chỉ PC: 0x075dc8 | Địa chỉ FDE: 0x11af78 | Kích thước: 80 bytes
//   0x075dc8: D0000648  adrp     x8, #0x13f000
//   0x075dcc: F9446508  ldr      x8, [x8, #0x8c8]
//   0x075dd0: D000064B  adrp     x11, #0x13f000
//   0x075dd4: 5280A00A  mov      w10, #0x500
static inline uint64_t fde_func_0479_0x075dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075dc8ULL ^ (static_cast<uint64_t>(0xd0000648ULL) << 13);
    acc = (acc + a1 + 0xf9446508ULL) ^ 0x11af78ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0480 | PC: 0x075e18 | FDE: 0x11b4b8 | Size: 256 bytes [_ZN11fast_engine17JSONSerializationEPNS_3ObjEPNS_6EngineEi]
// Hàm FDE #0480 | Địa chỉ PC: 0x075e18 | Địa chỉ FDE: 0x11b4b8 | Kích thước: 256 bytes
//   0x075e18: D10303FF  sub      sp, sp, #0xc0
//   0x075e1c: F90043F7  str      x23, [sp, #0x80]
//   0x075e20: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x075e24: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0480_0x075e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075e18ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x11b4b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0481 | PC: 0x076014 | FDE: 0x11b4e8 | Size: 256 bytes
// Hàm FDE #0481 | Địa chỉ PC: 0x076014 | Địa chỉ FDE: 0x11b4e8 | Kích thước: 256 bytes
//   0x076014: D10243FF  sub      sp, sp, #0x90
//   0x076018: FD001BE8  str      d8, [sp, #0x30]
//   0x07601c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x076020: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0481_0x076014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076014ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd001be8ULL) ^ 0x11b4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0482 | PC: 0x076354 | FDE: 0x11b520 | Size: 256 bytes
// Hàm FDE #0482 | Địa chỉ PC: 0x076354 | Địa chỉ FDE: 0x11b520 | Kích thước: 256 bytes
//   0x076354: D10243FF  sub      sp, sp, #0x90
//   0x076358: FD001BE8  str      d8, [sp, #0x30]
//   0x07635c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x076360: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0482_0x076354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076354ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd001be8ULL) ^ 0x11b520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0483 | PC: 0x0766a4 | FDE: 0x11b558 | Size: 256 bytes [_ZN11fast_engine19JSONDeserializationERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #0483 | Địa chỉ PC: 0x0766a4 | Địa chỉ FDE: 0x11b558 | Kích thước: 256 bytes
//   0x0766a4: D10303FF  sub      sp, sp, #0xc0
//   0x0766a8: F9004BF5  str      x21, [sp, #0x90]
//   0x0766ac: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0766b0: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0483_0x0766a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0766a4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf5ULL) ^ 0x11b558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0484 | PC: 0x076840 | FDE: 0x11b580 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandlerD2Ev]
// Hàm FDE #0484 | Địa chỉ PC: 0x076840 | Địa chỉ FDE: 0x11b580 | Kích thước: 256 bytes
//   0x076840: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x076844: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x076848: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07684c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0484_0x076840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076840ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0485 | PC: 0x0769f8 | FDE: 0x11af90 | Size: 80 bytes [_ZN11fast_engine23JSONDeserializationDictERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #0485 | Địa chỉ PC: 0x0769f8 | Địa chỉ FDE: 0x11af90 | Kích thước: 80 bytes
//   0x0769f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0769fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x076a00: 910043FD  add      x29, sp, #0x10
//   0x076a04: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0485_0x0769f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0769f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11af90ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0486 | PC: 0x076a48 | FDE: 0x11afb0 | Size: 80 bytes [_ZN11fast_engine23JSONDeserializationListERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #0486 | Địa chỉ PC: 0x076a48 | Địa chỉ FDE: 0x11afb0 | Kích thước: 80 bytes
//   0x076a48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x076a4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x076a50: 910043FD  add      x29, sp, #0x10
//   0x076a54: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0486_0x076a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076a48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11afb0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0487 | PC: 0x076a98 | FDE: 0x11b5b0 | Size: 256 bytes [_ZN11fast_engine14InitJSONModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0487 | Địa chỉ PC: 0x076a98 | Địa chỉ FDE: 0x11b5b0 | Kích thước: 256 bytes
//   0x076a98: D10183FF  sub      sp, sp, #0x60
//   0x076a9c: F90013F7  str      x23, [sp, #0x20]
//   0x076aa0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x076aa4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0487_0x076a98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076a98ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11b5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0488 | PC: 0x076d4c | FDE: 0x11b5e0 | Size: 256 bytes
// Hàm FDE #0488 | Địa chỉ PC: 0x076d4c | Địa chỉ FDE: 0x11b5e0 | Kích thước: 256 bytes
//   0x076d4c: D10203FF  sub      sp, sp, #0x80
//   0x076d50: F90023F7  str      x23, [sp, #0x40]
//   0x076d54: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x076d58: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0488_0x076d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076d4cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x11b5e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0489 | PC: 0x076f00 | FDE: 0x11afd0 | Size: 84 bytes
// Hàm FDE #0489 | Địa chỉ PC: 0x076f00 | Địa chỉ FDE: 0x11afd0 | Kích thước: 84 bytes
//   0x076f00: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076f04: 910003FD  mov      x29, sp
//   0x076f08: AA0003E8  mov      x8, x0
//   0x076f0c: B4000082  cbz      x2, #0x76f1c
static inline uint64_t fde_func_0489_0x076f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076f00ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11afd0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0490 | PC: 0x076f54 | FDE: 0x11aff0 | Size: 144 bytes
// Hàm FDE #0490 | Địa chỉ PC: 0x076f54 | Địa chỉ FDE: 0x11aff0 | Kích thước: 144 bytes
//   0x076f54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x076f58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x076f5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x076f60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0490_0x076f54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076f54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11aff0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0491 | PC: 0x076fe4 | FDE: 0x11b010 | Size: 16 bytes [_ZNK9rapidjson11ParseResult7IsErrorEv]
// Hàm FDE #0491 | Địa chỉ PC: 0x076fe4 | Địa chỉ FDE: 0x11b010 | Kích thước: 16 bytes
//   0x076fe4: B9400008  ldr      w8, [x0]
//   0x076fe8: 7100011F  cmp      w8, #0
//   0x076fec: 1A9F07E0  cset     w0, ne
//   0x076ff0: D65F03C0  ret      
static inline uint64_t fde_func_0491_0x076fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076fe4ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x11b010ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0492 | PC: 0x076ff4 | FDE: 0x11b028 | Size: 208 bytes [_ZN9rapidjson12PrettyWriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE11StartObjectEv]
// Hàm FDE #0492 | Địa chỉ PC: 0x076ff4 | Địa chỉ FDE: 0x11b028 | Kích thước: 208 bytes
//   0x076ff4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x076ff8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x076ffc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077000: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0492_0x076ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076ff4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b028ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0493 | PC: 0x0770c4 | FDE: 0x11b048 | Size: 256 bytes [_ZN9rapidjson12PrettyWriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE9EndObjectEj]
// Hàm FDE #0493 | Địa chỉ PC: 0x0770c4 | Địa chỉ FDE: 0x11b048 | Kích thước: 256 bytes
//   0x0770c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0770c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0770cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0770d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0493_0x0770c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0770c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0494 | PC: 0x07726c | FDE: 0x11b070 | Size: 212 bytes [_ZN9rapidjson12PrettyWriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE10StartArrayEv]
// Hàm FDE #0494 | Địa chỉ PC: 0x07726c | Địa chỉ FDE: 0x11b070 | Kích thước: 212 bytes
//   0x07726c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077270: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077274: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077278: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0494_0x07726c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07726cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b070ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0495 | PC: 0x077340 | FDE: 0x11b090 | Size: 256 bytes [_ZN9rapidjson12PrettyWriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE8EndArrayEj]
// Hàm FDE #0495 | Địa chỉ PC: 0x077340 | Địa chỉ FDE: 0x11b090 | Kích thước: 256 bytes
//   0x077340: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x077344: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x077348: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07734c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0495_0x077340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077340ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0496 | PC: 0x0774ec | FDE: 0x11b0b8 | Size: 256 bytes [_ZN9rapidjson12PrettyWriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE12PrettyPrefixENS_4TypeE]
// Hàm FDE #0496 | Địa chỉ PC: 0x0774ec | Địa chỉ FDE: 0x11b0b8 | Kích thước: 256 bytes
//   0x0774ec: D10143FF  sub      sp, sp, #0x50
//   0x0774f0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0774f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0774f8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0496_0x0774ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0774ecULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11b0b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0497 | PC: 0x077b0c | FDE: 0x11b0e0 | Size: 200 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE16WriteStartObjectEv]
// Hàm FDE #0497 | Địa chỉ PC: 0x077b0c | Địa chỉ FDE: 0x11b0e0 | Kích thước: 200 bytes
//   0x077b0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077b10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077b14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077b18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0497_0x077b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077b0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b0e0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0498 | PC: 0x077bd4 | FDE: 0x11b100 | Size: 200 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE14WriteEndObjectEv]
// Hàm FDE #0498 | Địa chỉ PC: 0x077bd4 | Địa chỉ FDE: 0x11b100 | Kích thước: 200 bytes
//   0x077bd4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077bd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077bdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077be0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0498_0x077bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077bd4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b100ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0499 | PC: 0x077c9c | FDE: 0x11b120 | Size: 200 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE15WriteStartArrayEv]
// Hàm FDE #0499 | Địa chỉ PC: 0x077c9c | Địa chỉ FDE: 0x11b120 | Kích thước: 200 bytes
//   0x077c9c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077ca0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077ca4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077ca8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0499_0x077c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077c9cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b120ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0500 | PC: 0x077d64 | FDE: 0x11b140 | Size: 200 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE13WriteEndArrayEv]
// Hàm FDE #0500 | Địa chỉ PC: 0x077d64 | Địa chỉ FDE: 0x11b140 | Kích thước: 200 bytes
//   0x077d64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077d68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077d6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077d70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0500_0x077d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077d64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b140ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0501 | PC: 0x077e2c | FDE: 0x11b160 | Size: 256 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE9WriteBoolEb]
// Hàm FDE #0501 | Địa chỉ PC: 0x077e2c | Địa chỉ FDE: 0x11b160 | Kích thước: 256 bytes
//   0x077e2c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x077e30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077e34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077e38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0501_0x077e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077e2cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0502 | PC: 0x07801c | FDE: 0x11b188 | Size: 248 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE13WriteRawValueEPKcm]
// Hàm FDE #0502 | Địa chỉ PC: 0x07801c | Địa chỉ FDE: 0x11b188 | Kích thước: 248 bytes
//   0x07801c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x078020: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x078024: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x078028: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0502_0x07801c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07801cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b188ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0503 | PC: 0x078114 | FDE: 0x11b1b0 | Size: 256 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE9WriteNullEv]
// Hàm FDE #0503 | Địa chỉ PC: 0x078114 | Địa chỉ FDE: 0x11b1b0 | Kích thước: 256 bytes
//   0x078114: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x078118: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07811c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x078120: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0503_0x078114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078114ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0504 | PC: 0x078224 | FDE: 0x11b1d8 | Size: 256 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE11WriteDoubleEd]
// Hàm FDE #0504 | Địa chỉ PC: 0x078224 | Địa chỉ FDE: 0x11b1d8 | Kích thước: 256 bytes
//   0x078224: D10183FF  sub      sp, sp, #0x60
//   0x078228: FD000BE8  str      d8, [sp, #0x10]
//   0x07822c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x078230: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0504_0x078224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078224ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x11b1d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0505 | PC: 0x0783c4 | FDE: 0x11b200 | Size: 256 bytes [_ZN9rapidjson8internal6Grisu2EdPcPiS2_]
// Hàm FDE #0505 | Địa chỉ PC: 0x0783c4 | Địa chỉ FDE: 0x11b200 | Kích thước: 256 bytes
//   0x0783c4: D10143FF  sub      sp, sp, #0x50
//   0x0783c8: F9001BF3  str      x19, [sp, #0x30]
//   0x0783cc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0783d0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0505_0x0783c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0783c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x11b200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0506 | PC: 0x0785e0 | FDE: 0x11b220 | Size: 256 bytes [_ZN9rapidjson8internal8PrettifyEPciii]
// Hàm FDE #0506 | Địa chỉ PC: 0x0785e0 | Địa chỉ FDE: 0x11b220 | Kích thước: 256 bytes
//   0x0785e0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0785e4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0785e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0785ec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0506_0x0785e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0785e0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11b220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0507 | PC: 0x07889c | FDE: 0x11b248 | Size: 256 bytes [_ZN9rapidjson8internal8DigitGenERKNS0_5DiyFpES3_mPcPiS5_]
// Hàm FDE #0507 | Địa chỉ PC: 0x07889c | Địa chỉ FDE: 0x11b248 | Kích thước: 256 bytes
//   0x07889c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0788a0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0788a4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0788a8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0507_0x07889c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07889cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11b248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0508 | PC: 0x078c84 | FDE: 0x11b278 | Size: 256 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE11WriteStringEPKcj]
// Hàm FDE #0508 | Địa chỉ PC: 0x078c84 | Địa chỉ FDE: 0x11b278 | Kích thước: 256 bytes
//   0x078c84: D10143FF  sub      sp, sp, #0x50
//   0x078c88: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x078c8c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x078c90: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0508_0x078c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078c84ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11b278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0509 | PC: 0x078e80 | FDE: 0x11b2a0 | Size: 208 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE11StartObjectEv]
// Hàm FDE #0509 | Địa chỉ PC: 0x078e80 | Địa chỉ FDE: 0x11b2a0 | Kích thước: 208 bytes
//   0x078e80: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x078e84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x078e88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x078e8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0509_0x078e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078e80ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b2a0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0510 | PC: 0x078f50 | FDE: 0x11b2c0 | Size: 212 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE10StartArrayEv]
// Hàm FDE #0510 | Địa chỉ PC: 0x078f50 | Địa chỉ FDE: 0x11b2c0 | Kích thước: 212 bytes
//   0x078f50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x078f54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x078f58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x078f5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0510_0x078f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078f50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b2c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0511 | PC: 0x079024 | FDE: 0x11b2e0 | Size: 256 bytes [_ZN9rapidjson6WriterINS_19GenericStringBufferINS_4UTF8IcEENS_12CrtAllocatorEEES3_S3_S4_Lj0EE6PrefixENS_4TypeE]
// Hàm FDE #0511 | Địa chỉ PC: 0x079024 | Địa chỉ FDE: 0x11b2e0 | Kích thước: 256 bytes
//   0x079024: D10103FF  sub      sp, sp, #0x40
//   0x079028: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07902c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x079030: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0511_0x079024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079024ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b2e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0512 | PC: 0x0791c8 | FDE: 0x11b610 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE5ParseILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEENS_11ParseResultERT0_RT1_]
// Hàm FDE #0512 | Địa chỉ PC: 0x0791c8 | Địa chỉ FDE: 0x11b610 | Kích thước: 256 bytes
//   0x0791c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0791cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0791d0: 910043FD  add      x29, sp, #0x10
//   0x0791d4: B900301F  str      wzr, [x0, #0x30]
static inline uint64_t fde_func_0512_0x0791c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0791c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0513 | PC: 0x0792c8 | FDE: 0x11b308 | Size: 84 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE10ParseValueILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0513 | Địa chỉ PC: 0x0792c8 | Địa chỉ FDE: 0x11b308 | Kích thước: 84 bytes
//   0x0792c8: F9400028  ldr      x8, [x1]
//   0x0792cc: 39400109  ldrb     w9, [x8]
//   0x0792d0: 51016D28  sub      w8, w9, #0x5b
//   0x0792d4: 7100811F  cmp      w8, #0x20
static inline uint64_t fde_func_0513_0x0792c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0792c8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x39400109ULL) ^ 0x11b308ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0514 | PC: 0x07931c | FDE: 0x11b320 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE9ParseNullILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0514 | Địa chỉ PC: 0x07931c | Địa chỉ FDE: 0x11b320 | Kích thước: 256 bytes
//   0x07931c: D100C3FF  sub      sp, sp, #0x30
//   0x079320: F9000BF3  str      x19, [sp, #0x10]
//   0x079324: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x079328: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0514_0x07931c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07931cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x11b320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0515 | PC: 0x079424 | FDE: 0x11b340 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE9ParseTrueILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0515 | Địa chỉ PC: 0x079424 | Địa chỉ FDE: 0x11b340 | Kích thước: 256 bytes
//   0x079424: D100C3FF  sub      sp, sp, #0x30
//   0x079428: F9000BF3  str      x19, [sp, #0x10]
//   0x07942c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x079430: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0515_0x079424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079424ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x11b340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0516 | PC: 0x07952c | FDE: 0x11b360 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE10ParseFalseILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0516 | Địa chỉ PC: 0x07952c | Địa chỉ FDE: 0x11b360 | Kích thước: 256 bytes
//   0x07952c: D100C3FF  sub      sp, sp, #0x30
//   0x079530: F9000BF3  str      x19, [sp, #0x10]
//   0x079534: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x079538: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0516_0x07952c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07952cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x11b360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0517 | PC: 0x079648 | FDE: 0x11b638 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE11ParseStringILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_b]
// Hàm FDE #0517 | Địa chỉ PC: 0x079648 | Địa chỉ FDE: 0x11b638 | Kích thước: 256 bytes
//   0x079648: D10283FF  sub      sp, sp, #0xa0
//   0x07964c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x079650: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x079654: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0517_0x079648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079648ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x11b638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0518 | PC: 0x079a74 | FDE: 0x11b380 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE11ParseObjectILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0518 | Địa chỉ PC: 0x079a74 | Địa chỉ FDE: 0x11b380 | Kích thước: 256 bytes
//   0x079a74: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x079a78: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x079a7c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x079a80: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0518_0x079a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079a74ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0519 | PC: 0x079cb4 | FDE: 0x11b3a8 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE10ParseArrayILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0519 | Địa chỉ PC: 0x079cb4 | Địa chỉ FDE: 0x11b3a8 | Kích thước: 256 bytes
//   0x079cb4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x079cb8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x079cbc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x079cc0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0519_0x079cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079cb4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b3a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0520 | PC: 0x079e40 | FDE: 0x11b670 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE11ParseNumberILj0ENS_19GenericStringStreamIS2_EEN11fast_engine21FastEngineJSONHandlerEEEvRT0_RT1_]
// Hàm FDE #0520 | Địa chỉ PC: 0x079e40 | Địa chỉ FDE: 0x11b670 | Kích thước: 256 bytes
//   0x079e40: D10203FF  sub      sp, sp, #0x80
//   0x079e44: F90013FB  str      x27, [sp, #0x20]
//   0x079e48: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x079e4c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0520_0x079e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079e40ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x11b670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0521 | PC: 0x07a8bc | FDE: 0x11b3d0 | Size: 256 bytes [_ZNSt6__ndk16vectorIPN11fast_engine3ObjENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEvOT_]
// Hàm FDE #0521 | Địa chỉ PC: 0x07a8bc | Địa chỉ FDE: 0x11b3d0 | Kích thước: 256 bytes
//   0x07a8bc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x07a8c0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07a8c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07a8c8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0521_0x07a8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a8bcULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11b3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0522 | PC: 0x07a9c8 | FDE: 0x11b6a8 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler3KeyEPKclb]
// Hàm FDE #0522 | Địa chỉ PC: 0x07a9c8 | Địa chỉ FDE: 0x11b6a8 | Kích thước: 256 bytes
//   0x07a9c8: D10183FF  sub      sp, sp, #0x60
//   0x07a9cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07a9d0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x07a9d4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0522_0x07a9c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a9c8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x11b6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0523 | PC: 0x07ab18 | FDE: 0x11b6d8 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler6StringEPKclb]
// Hàm FDE #0523 | Địa chỉ PC: 0x07ab18 | Địa chỉ FDE: 0x11b6d8 | Kích thước: 256 bytes
//   0x07ab18: D10143FF  sub      sp, sp, #0x50
//   0x07ab1c: F90013F5  str      x21, [sp, #0x20]
//   0x07ab20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07ab24: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0523_0x07ab18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ab18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x11b6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0524 | PC: 0x07ac18 | FDE: 0x11b400 | Size: 256 bytes [_ZN9rapidjson13GenericReaderINS_4UTF8IcEES2_NS_12CrtAllocatorEE9ParseHex4INS_19GenericStringStreamIS2_EEEEjRT_m]
// Hàm FDE #0524 | Địa chỉ PC: 0x07ac18 | Địa chỉ FDE: 0x11b400 | Kích thước: 256 bytes
//   0x07ac18: F9400028  ldr      x8, [x1]
//   0x07ac1c: 39400109  ldrb     w9, [x8]
//   0x07ac20: 5100C12A  sub      w10, w9, #0x30
//   0x07ac24: 7100295F  cmp      w10, #0xa
static inline uint64_t fde_func_0524_0x07ac18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ac18ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x39400109ULL) ^ 0x11b400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x07ad64 | FDE: 0x11b418 | Size: 256 bytes [_ZN9rapidjson4UTF8IcE6EncodeINS_13GenericReaderIS1_S1_NS_12CrtAllocatorEE11StackStreamIcEEEEvRT_j]
// Hàm FDE #0525 | Địa chỉ PC: 0x07ad64 | Địa chỉ FDE: 0x11b418 | Kích thước: 256 bytes
//   0x07ad64: D10143FF  sub      sp, sp, #0x50
//   0x07ad68: F9000BF7  str      x23, [sp, #0x10]
//   0x07ad6c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07ad70: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0525_0x07ad64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ad64ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x11b418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0526 | PC: 0x07b51c | FDE: 0x11b700 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler11StartObjectEv]
// Hàm FDE #0526 | Địa chỉ PC: 0x07b51c | Địa chỉ FDE: 0x11b700 | Kích thước: 256 bytes
//   0x07b51c: D10183FF  sub      sp, sp, #0x60
//   0x07b520: F9001BF5  str      x21, [sp, #0x30]
//   0x07b524: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x07b528: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0526_0x07b51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b51cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x11b700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0527 | PC: 0x07b62c | FDE: 0x11b440 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler9EndObjectEl]
// Hàm FDE #0527 | Địa chỉ PC: 0x07b62c | Địa chỉ FDE: 0x11b440 | Kích thước: 256 bytes
//   0x07b62c: D10143FF  sub      sp, sp, #0x50
//   0x07b630: F9000BF7  str      x23, [sp, #0x10]
//   0x07b634: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07b638: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0527_0x07b62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b62cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x11b440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0528 | PC: 0x07b7a4 | FDE: 0x11b728 | Size: 256 bytes [_ZNSt6__ndk16vectorIN11fast_engine21FastEngineJSONHandler9StackItemENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEvOT_]
// Hàm FDE #0528 | Địa chỉ PC: 0x07b7a4 | Địa chỉ FDE: 0x11b728 | Kích thước: 256 bytes
//   0x07b7a4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07b7a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07b7ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07b7b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0528_0x07b7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b7a4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0529 | PC: 0x07b958 | FDE: 0x11b758 | Size: 188 bytes [_ZNSt6__ndk16vectorIPN11fast_engine3ObjENS_9allocatorIS3_EEEC2ERKS6_]
// Hàm FDE #0529 | Địa chỉ PC: 0x07b958 | Địa chỉ FDE: 0x11b758 | Kích thước: 188 bytes
//   0x07b958: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07b95c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07b960: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b964: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0529_0x07b958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b958ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b758ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0530 | PC: 0x07ba14 | FDE: 0x11b788 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler10StartArrayEv]
// Hàm FDE #0530 | Địa chỉ PC: 0x07ba14 | Địa chỉ FDE: 0x11b788 | Kích thước: 256 bytes
//   0x07ba14: D10183FF  sub      sp, sp, #0x60
//   0x07ba18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07ba1c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x07ba20: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0530_0x07ba14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ba14ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x11b788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0531 | PC: 0x07bb94 | FDE: 0x11b468 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler8EndArrayEl]
// Hàm FDE #0531 | Địa chỉ PC: 0x07bb94 | Địa chỉ FDE: 0x11b468 | Kích thước: 256 bytes
//   0x07bb94: D10103FF  sub      sp, sp, #0x40
//   0x07bb98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07bb9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07bba0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0531_0x07bb94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bb94ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11b468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0532 | PC: 0x07bca4 | FDE: 0x11b7b8 | Size: 256 bytes [_ZN11fast_engine21FastEngineJSONHandler6DoubleEd]
// Hàm FDE #0532 | Địa chỉ PC: 0x07bca4 | Địa chỉ FDE: 0x11b7b8 | Kích thước: 256 bytes
//   0x07bca4: D10143FF  sub      sp, sp, #0x50
//   0x07bca8: FD000BE8  str      d8, [sp, #0x10]
//   0x07bcac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07bcb0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0532_0x07bca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bca4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x11b7b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0533 | PC: 0x07bdc0 | FDE: 0x11b910 | Size: 256 bytes [_ZN11fast_engine5CMathEPNS_3ObjEPFddEPKcPNS_6EngineE]
// Hàm FDE #0533 | Địa chỉ PC: 0x07bdc0 | Địa chỉ FDE: 0x11b910 | Kích thước: 256 bytes
//   0x07bdc0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07bdc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07bdc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07bdcc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0533_0x07bdc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bdc0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0534 | PC: 0x07bf74 | FDE: 0x11b940 | Size: 256 bytes [_ZN11fast_engine14InitMathModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0534 | Địa chỉ PC: 0x07bf74 | Địa chỉ FDE: 0x11b940 | Kích thước: 256 bytes
//   0x07bf74: D10183FF  sub      sp, sp, #0x60
//   0x07bf78: F90013F7  str      x23, [sp, #0x20]
//   0x07bf7c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07bf80: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0534_0x07bf74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bf74ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11b940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0535 | PC: 0x07c578 | FDE: 0x11b7e8 | Size: 256 bytes
// Hàm FDE #0535 | Địa chỉ PC: 0x07c578 | Địa chỉ FDE: 0x11b7e8 | Kích thước: 256 bytes
//   0x07c578: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07c57c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07c580: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07c584: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0535_0x07c578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c578ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b7e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0536 | PC: 0x07c6d0 | FDE: 0x11b810 | Size: 24 bytes
// Hàm FDE #0536 | Địa chỉ PC: 0x07c6d0 | Địa chỉ FDE: 0x11b810 | Kích thước: 24 bytes
//   0x07c6d0: 90000001  adrp     x1, #0x7c000
//   0x07c6d4: AA0003E8  mov      x8, x0
//   0x07c6d8: 913CF021  add      x1, x1, #0xf3c
//   0x07c6dc: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_0536_0x07c6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6d0ULL ^ (static_cast<uint64_t>(0x90000001ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11b810ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0537 | PC: 0x07c6e8 | FDE: 0x11b828 | Size: 24 bytes
// Hàm FDE #0537 | Địa chỉ PC: 0x07c6e8 | Địa chỉ FDE: 0x11b828 | Kích thước: 24 bytes
//   0x07c6e8: 90000001  adrp     x1, #0x7c000
//   0x07c6ec: AA0003E8  mov      x8, x0
//   0x07c6f0: 913F5021  add      x1, x1, #0xfd4
//   0x07c6f4: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_0537_0x07c6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6e8ULL ^ (static_cast<uint64_t>(0x90000001ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11b828ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0538 | PC: 0x07c700 | FDE: 0x11b970 | Size: 256 bytes
// Hàm FDE #0538 | Địa chỉ PC: 0x07c700 | Địa chỉ FDE: 0x11b970 | Kích thước: 256 bytes
//   0x07c700: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07c704: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07c708: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07c70c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0538_0x07c700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c700ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0539 | PC: 0x07c8a4 | FDE: 0x11b998 | Size: 256 bytes
// Hàm FDE #0539 | Địa chỉ PC: 0x07c8a4 | Địa chỉ FDE: 0x11b998 | Kích thước: 256 bytes
//   0x07c8a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07c8a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07c8ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07c8b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0539_0x07c8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c8a4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11b998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0540 | PC: 0x07ca48 | FDE: 0x11b840 | Size: 24 bytes
// Hàm FDE #0540 | Địa chỉ PC: 0x07ca48 | Địa chỉ FDE: 0x11b840 | Kích thước: 24 bytes
//   0x07ca48: F0000601  adrp     x1, #0x13f000
//   0x07ca4c: F9449021  ldr      x1, [x1, #0x920]
//   0x07ca50: AA0003E8  mov      x8, x0
//   0x07ca54: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_0540_0x07ca48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ca48ULL ^ (static_cast<uint64_t>(0xf0000601ULL) << 13);
    acc = (acc + a1 + 0xf9449021ULL) ^ 0x11b840ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0541 | PC: 0x07ca60 | FDE: 0x11b858 | Size: 24 bytes
// Hàm FDE #0541 | Địa chỉ PC: 0x07ca60 | Địa chỉ FDE: 0x11b858 | Kích thước: 24 bytes
//   0x07ca60: F0000601  adrp     x1, #0x13f000
//   0x07ca64: F9459C21  ldr      x1, [x1, #0xb38]
//   0x07ca68: AA0003E8  mov      x8, x0
//   0x07ca6c: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_0541_0x07ca60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ca60ULL ^ (static_cast<uint64_t>(0xf0000601ULL) << 13);
    acc = (acc + a1 + 0xf9459c21ULL) ^ 0x11b858ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0542 | PC: 0x07ca78 | FDE: 0x11b870 | Size: 116 bytes
// Hàm FDE #0542 | Địa chỉ PC: 0x07ca78 | Địa chỉ FDE: 0x11b870 | Kích thước: 116 bytes
//   0x07ca78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07ca7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ca80: 910043FD  add      x29, sp, #0x10
//   0x07ca84: F0000609  adrp     x9, #0x13f000
static inline uint64_t fde_func_0542_0x07ca78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ca78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b870ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0543 | PC: 0x07caec | FDE: 0x11b890 | Size: 128 bytes
// Hàm FDE #0543 | Địa chỉ PC: 0x07caec | Địa chỉ FDE: 0x11b890 | Kích thước: 128 bytes
//   0x07caec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07caf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07caf4: 910043FD  add      x29, sp, #0x10
//   0x07caf8: F0000609  adrp     x9, #0x13f000
static inline uint64_t fde_func_0543_0x07caec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07caecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b890ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0544 | PC: 0x07cb6c | FDE: 0x11b9c0 | Size: 256 bytes
// Hàm FDE #0544 | Địa chỉ PC: 0x07cb6c | Địa chỉ FDE: 0x11b9c0 | Kích thước: 256 bytes
//   0x07cb6c: D10143FF  sub      sp, sp, #0x50
//   0x07cb70: FD000BE8  str      d8, [sp, #0x10]
//   0x07cb74: F9000FF7  str      x23, [sp, #0x18]
//   0x07cb78: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_0544_0x07cb6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cb6cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x11b9c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0545 | PC: 0x07cd18 | FDE: 0x11b8b0 | Size: 152 bytes
// Hàm FDE #0545 | Địa chỉ PC: 0x07cd18 | Địa chỉ FDE: 0x11b8b0 | Kích thước: 152 bytes
//   0x07cd18: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x07cd1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cd20: 910043FD  add      x29, sp, #0x10
//   0x07cd24: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_0545_0x07cd18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd18ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b8b0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0546 | PC: 0x07cdb0 | FDE: 0x11b9f0 | Size: 256 bytes
// Hàm FDE #0546 | Địa chỉ PC: 0x07cdb0 | Địa chỉ FDE: 0x11b9f0 | Kích thước: 256 bytes
//   0x07cdb0: 6DBC23E9  stp      d9, d8, [sp, #-0x40]!
//   0x07cdb4: F9000BF5  str      x21, [sp, #0x10]
//   0x07cdb8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07cdbc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0546_0x07cdb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cdb0ULL ^ (static_cast<uint64_t>(0x6dbc23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x11b9f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0547 | PC: 0x07cf3c | FDE: 0x11b8d0 | Size: 152 bytes
// Hàm FDE #0547 | Địa chỉ PC: 0x07cf3c | Địa chỉ FDE: 0x11b8d0 | Kích thước: 152 bytes
//   0x07cf3c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x07cf40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cf44: 910043FD  add      x29, sp, #0x10
//   0x07cf48: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_0547_0x07cf3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cf3cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b8d0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0548 | PC: 0x07cfd4 | FDE: 0x11b8f0 | Size: 152 bytes
// Hàm FDE #0548 | Địa chỉ PC: 0x07cfd4 | Địa chỉ FDE: 0x11b8f0 | Kích thước: 152 bytes
//   0x07cfd4: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x07cfd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cfdc: 910043FD  add      x29, sp, #0x10
//   0x07cfe0: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_0548_0x07cfd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cfd4ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11b8f0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0549 | PC: 0x07d06c | FDE: 0x11bb00 | Size: 96 bytes [_ZN11fast_engine15AllocRandomTypeEPNS_6EngineE]
// Hàm FDE #0549 | Địa chỉ PC: 0x07d06c | Địa chỉ FDE: 0x11bb00 | Kích thước: 96 bytes
//   0x07d06c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d070: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d074: 910043FD  add      x29, sp, #0x10
//   0x07d078: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0549_0x07d06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d06cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bb00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0550 | PC: 0x07d0cc | FDE: 0x11bb28 | Size: 256 bytes [_ZN11fast_engine14InitRandomTypeEPNS_6EngineE]
// Hàm FDE #0550 | Địa chỉ PC: 0x07d0cc | Địa chỉ FDE: 0x11bb28 | Kích thước: 256 bytes
//   0x07d0cc: D10103FF  sub      sp, sp, #0x40
//   0x07d0d0: F90013F3  str      x19, [sp, #0x20]
//   0x07d0d4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07d0d8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0550_0x07d0cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d0ccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11bb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0551 | PC: 0x07d260 | FDE: 0x11bb50 | Size: 72 bytes
// Hàm FDE #0551 | Địa chỉ PC: 0x07d260 | Địa chỉ FDE: 0x11bb50 | Kích thước: 72 bytes
//   0x07d260: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d264: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d268: 910043FD  add      x29, sp, #0x10
//   0x07d26c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0551_0x07d260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d260ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bb50ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0552 | PC: 0x07d2a8 | FDE: 0x11bb78 | Size: 256 bytes
// Hàm FDE #0552 | Địa chỉ PC: 0x07d2a8 | Địa chỉ FDE: 0x11bb78 | Kích thước: 256 bytes
//   0x07d2a8: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x07d2ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07d2b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07d2b4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0552_0x07d2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d2a8ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11bb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0553 | PC: 0x07d4ac | FDE: 0x11bba0 | Size: 256 bytes
// Hàm FDE #0553 | Địa chỉ PC: 0x07d4ac | Địa chỉ FDE: 0x11bba0 | Kích thước: 256 bytes
//   0x07d4ac: D10283FF  sub      sp, sp, #0xa0
//   0x07d4b0: FD002BE8  str      d8, [sp, #0x50]
//   0x07d4b4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x07d4b8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0553_0x07d4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d4acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd002be8ULL) ^ 0x11bba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0554 | PC: 0x07d91c | FDE: 0x11bbd0 | Size: 256 bytes
// Hàm FDE #0554 | Địa chỉ PC: 0x07d91c | Địa chỉ FDE: 0x11bbd0 | Kích thước: 256 bytes
//   0x07d91c: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x07d920: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07d924: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07d928: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0554_0x07d91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d91cULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11bbd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0555 | PC: 0x07dbe8 | FDE: 0x11bc00 | Size: 256 bytes [_ZN11fast_engine9RandomObjC2EPNS_6EngineE]
// Hàm FDE #0555 | Địa chỉ PC: 0x07dbe8 | Địa chỉ FDE: 0x11bc00 | Kích thước: 256 bytes
//   0x07dbe8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07dbec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07dbf0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07dbf4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0555_0x07dbe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dbe8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11bc00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0556 | PC: 0x07dd30 | FDE: 0x11bc28 | Size: 256 bytes [_ZN11fast_engine16InitRandomModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0556 | Địa chỉ PC: 0x07dd30 | Địa chỉ FDE: 0x11bc28 | Kích thước: 256 bytes
//   0x07dd30: D10183FF  sub      sp, sp, #0x60
//   0x07dd34: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07dd38: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07dd3c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0556_0x07dd30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd30ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11bc28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0557 | PC: 0x07def4 | FDE: 0x11ba20 | Size: 104 bytes [_ZN11fast_engine9RandomObjD2Ev]
// Hàm FDE #0557 | Địa chỉ PC: 0x07def4 | Địa chỉ FDE: 0x11ba20 | Kích thước: 104 bytes
//   0x07def4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07def8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07defc: 910043FD  add      x29, sp, #0x10
//   0x07df00: D0000608  adrp     x8, #0x13f000
static inline uint64_t fde_func_0557_0x07def4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07def4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ba20ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0558 | PC: 0x07df5c | FDE: 0x11ba40 | Size: 112 bytes [_ZN11fast_engine9RandomObjD0Ev]
// Hàm FDE #0558 | Địa chỉ PC: 0x07df5c | Địa chỉ FDE: 0x11ba40 | Kích thước: 112 bytes
//   0x07df5c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07df60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07df64: 910043FD  add      x29, sp, #0x10
//   0x07df68: D0000608  adrp     x8, #0x13f000
static inline uint64_t fde_func_0558_0x07df5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df5cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ba40ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0559 | PC: 0x07dfcc | FDE: 0x11ba60 | Size: 256 bytes [_ZNSt6__ndk16vectorIjNS_9allocatorIjEEE21__push_back_slow_pathIjEEvOT_]
// Hàm FDE #0559 | Địa chỉ PC: 0x07dfcc | Địa chỉ FDE: 0x11ba60 | Kích thước: 256 bytes
//   0x07dfcc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x07dfd0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07dfd4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07dfd8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0559_0x07dfcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dfccULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11ba60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0560 | PC: 0x07e0d8 | FDE: 0x11bc58 | Size: 256 bytes [_ZNSt6__ndk110shared_ptrINS_23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEE11make_sharedIJRNS_8seed_seqEEEES3_DpOT_]
// Hàm FDE #0560 | Địa chỉ PC: 0x07e0d8 | Địa chỉ FDE: 0x11bc58 | Kích thước: 256 bytes
//   0x07e0d8: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x07e0dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07e0e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07e0e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0560_0x07e0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e0d8ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11bc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0561 | PC: 0x07e1ec | FDE: 0x11ba90 | Size: 36 bytes [_ZNSt6__ndk120__shared_ptr_emplaceINS_23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEENS_9allocatorIS2_EEED0Ev]
// Hàm FDE #0561 | Địa chỉ PC: 0x07e1ec | Địa chỉ FDE: 0x11ba90 | Kích thước: 36 bytes
//   0x07e1ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07e1f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e1f4: 910043FD  add      x29, sp, #0x10
//   0x07e1f8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0561_0x07e1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e1ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ba90ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0562 | PC: 0x07e210 | FDE: 0x11bab0 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_emplaceINS_23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEENS_9allocatorIS2_EEE16__on_zero_sharedEv]
// Hàm FDE #0562 | Địa chỉ PC: 0x07e210 | Địa chỉ FDE: 0x11bab0 | Kích thước: 4 bytes
//   0x07e210: D65F03C0  ret      
static inline uint64_t fde_func_0562_0x07e210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e210ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ff10f3ULL) ^ 0x11bab0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0563 | PC: 0x07e214 | FDE: 0x11bac8 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_emplaceINS_23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEENS_9allocatorIS2_EEE21__on_zero_shared_weakEv]
// Hàm FDE #0563 | Địa chỉ PC: 0x07e214 | Địa chỉ FDE: 0x11bac8 | Kích thước: 4 bytes
//   0x07e214: 17FF10F3  b        #0x425e0
static inline uint64_t fde_func_0563_0x07e214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e214ULL ^ (static_cast<uint64_t>(0x17ff10f3ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x11bac8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0564 | PC: 0x07e218 | FDE: 0x11bae0 | Size: 256 bytes [_ZNSt6__ndk18seed_seq8generateIPjEEvT_S3_]
// Hàm FDE #0564 | Địa chỉ PC: 0x07e218 | Địa chỉ FDE: 0x11bae0 | Kích thước: 256 bytes
//   0x07e218: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07e21c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07e220: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07e224: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0564_0x07e218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e218ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11bae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0565 | PC: 0x07e4ec | FDE: 0x11dcb0 | Size: 256 bytes [_ZN11fast_engine11regex_checkERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #0565 | Địa chỉ PC: 0x07e4ec | Địa chỉ FDE: 0x11dcb0 | Kích thước: 256 bytes
//   0x07e4ec: D102C3FF  sub      sp, sp, #0xb0
//   0x07e4f0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x07e4f4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x07e4f8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0565_0x07e4ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e4ecULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x11dcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0566 | PC: 0x07e758 | FDE: 0x11dce8 | Size: 96 bytes [_ZN11fast_engine14AllocMatchTypeEPNS_6EngineE]
// Hàm FDE #0566 | Địa chỉ PC: 0x07e758 | Địa chỉ FDE: 0x11dce8 | Kích thước: 96 bytes
//   0x07e758: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07e75c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07e760: 910043FD  add      x29, sp, #0x10
//   0x07e764: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0566_0x07e758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e758ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11dce8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0567 | PC: 0x07e7b8 | FDE: 0x11bc88 | Size: 256 bytes [_ZN11fast_engine13InitMatchTypeEPNS_6EngineE]
// Hàm FDE #0567 | Địa chỉ PC: 0x07e7b8 | Địa chỉ FDE: 0x11bc88 | Kích thước: 256 bytes
//   0x07e7b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07e7bc: 910003FD  mov      x29, sp
//   0x07e7c0: F00006E8  adrp     x8, #0x15d000
//   0x07e7c4: 91298108  add      x8, x8, #0xa60
static inline uint64_t fde_func_0567_0x07e7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e7b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11bc88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0568 | PC: 0x07e914 | FDE: 0x11dd10 | Size: 256 bytes
// Hàm FDE #0568 | Địa chỉ PC: 0x07e914 | Địa chỉ FDE: 0x11dd10 | Kích thước: 256 bytes
//   0x07e914: D10203FF  sub      sp, sp, #0x80
//   0x07e918: F90013FB  str      x27, [sp, #0x20]
//   0x07e91c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x07e920: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0568_0x07e914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e914ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x11dd10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0569 | PC: 0x07ebd8 | FDE: 0x11dd48 | Size: 256 bytes
// Hàm FDE #0569 | Địa chỉ PC: 0x07ebd8 | Địa chỉ FDE: 0x11dd48 | Kích thước: 256 bytes
//   0x07ebd8: D10343FF  sub      sp, sp, #0xd0
//   0x07ebdc: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x07ebe0: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x07ebe4: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_0569_0x07ebd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ebd8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90867faULL) ^ 0x11dd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0570 | PC: 0x07edd0 | FDE: 0x11bca8 | Size: 44 bytes
// Hàm FDE #0570 | Địa chỉ PC: 0x07edd0 | Địa chỉ FDE: 0x11bca8 | Kích thước: 44 bytes
//   0x07edd0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07edd4: 910003FD  mov      x29, sp
//   0x07edd8: B0000608  adrp     x8, #0x13f000
//   0x07eddc: F9471908  ldr      x8, [x8, #0xe30]
static inline uint64_t fde_func_0570_0x07edd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07edd0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11bca8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0571 | PC: 0x07edfc | FDE: 0x11bcc8 | Size: 44 bytes
// Hàm FDE #0571 | Địa chỉ PC: 0x07edfc | Địa chỉ FDE: 0x11bcc8 | Kích thước: 44 bytes
//   0x07edfc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07ee00: 910003FD  mov      x29, sp
//   0x07ee04: B0000608  adrp     x8, #0x13f000
//   0x07ee08: F9471908  ldr      x8, [x8, #0xe30]
static inline uint64_t fde_func_0571_0x07edfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07edfcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11bcc8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0572 | PC: 0x07ee28 | FDE: 0x11bce8 | Size: 44 bytes
// Hàm FDE #0572 | Địa chỉ PC: 0x07ee28 | Địa chỉ FDE: 0x11bce8 | Kích thước: 44 bytes
//   0x07ee28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07ee2c: 910003FD  mov      x29, sp
//   0x07ee30: B0000608  adrp     x8, #0x13f000
//   0x07ee34: F9471908  ldr      x8, [x8, #0xe30]
static inline uint64_t fde_func_0572_0x07ee28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ee28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11bce8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0573 | PC: 0x07ee54 | FDE: 0x11dd80 | Size: 212 bytes [_ZN11fast_engine11MatchObjectC1ENSt6__ndk110unique_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_14default_deleteIS8_EEEENS2_INS_12IMatchResultENS9_ISC_EEEEPNS_6EngineE]
// Hàm FDE #0573 | Địa chỉ PC: 0x07ee54 | Địa chỉ FDE: 0x11dd80 | Kích thước: 212 bytes
//   0x07ee54: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07ee58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07ee5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07ee60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0573_0x07ee54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ee54ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11dd80ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0574 | PC: 0x07ef28 | FDE: 0x11ddb0 | Size: 256 bytes [_ZN11fast_engine15InitRegexModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0574 | Địa chỉ PC: 0x07ef28 | Địa chỉ FDE: 0x11ddb0 | Kích thước: 256 bytes
//   0x07ef28: D10183FF  sub      sp, sp, #0x60
//   0x07ef2c: F90013F7  str      x23, [sp, #0x20]
//   0x07ef30: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07ef34: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0574_0x07ef28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ef28ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11ddb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0575 | PC: 0x07f274 | FDE: 0x11dde0 | Size: 256 bytes
// Hàm FDE #0575 | Địa chỉ PC: 0x07f274 | Địa chỉ FDE: 0x11dde0 | Kích thước: 256 bytes
//   0x07f274: D10703FF  sub      sp, sp, #0x1c0
//   0x07f278: A91767FC  stp      x28, x25, [sp, #0x170]
//   0x07f27c: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x07f280: A91957F6  stp      x22, x21, [sp, #0x190]
static inline uint64_t fde_func_0575_0x07f274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f274ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa91767fcULL) ^ 0x11dde0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0576 | PC: 0x07fb20 | FDE: 0x11de18 | Size: 256 bytes
// Hàm FDE #0576 | Địa chỉ PC: 0x07fb20 | Địa chỉ FDE: 0x11de18 | Kích thước: 256 bytes
//   0x07fb20: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x07fb24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07fb28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07fb2c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0576_0x07fb20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fb20ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11de18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0577 | PC: 0x0803f4 | FDE: 0x11de50 | Size: 256 bytes
// Hàm FDE #0577 | Địa chỉ PC: 0x0803f4 | Địa chỉ FDE: 0x11de50 | Kích thước: 256 bytes
//   0x0803f4: D10703FF  sub      sp, sp, #0x1c0
//   0x0803f8: F900BBFC  str      x28, [sp, #0x170]
//   0x0803fc: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x080400: A91957F6  stp      x22, x21, [sp, #0x190]
static inline uint64_t fde_func_0577_0x0803f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0803f4ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xf900bbfcULL) ^ 0x11de50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0578 | PC: 0x080bf8 | FDE: 0x11de80 | Size: 256 bytes
// Hàm FDE #0578 | Địa chỉ PC: 0x080bf8 | Địa chỉ FDE: 0x11de80 | Kích thước: 256 bytes
//   0x080bf8: D10683FF  sub      sp, sp, #0x1a0
//   0x080bfc: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x080c00: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x080c04: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_0578_0x080bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080bf8ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x11de80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0579 | PC: 0x081588 | FDE: 0x11deb8 | Size: 256 bytes
// Hàm FDE #0579 | Địa chỉ PC: 0x081588 | Địa chỉ FDE: 0x11deb8 | Kích thước: 256 bytes
//   0x081588: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08158c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x081590: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x081594: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0579_0x081588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081588ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11deb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0580 | PC: 0x082404 | FDE: 0x11def0 | Size: 256 bytes
// Hàm FDE #0580 | Địa chỉ PC: 0x082404 | Địa chỉ FDE: 0x11def0 | Kích thước: 256 bytes
//   0x082404: D10743FF  sub      sp, sp, #0x1d0
//   0x082408: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x08240c: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x082410: A9195FF8  stp      x24, x23, [sp, #0x190]
static inline uint64_t fde_func_0580_0x082404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x082404ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa9176ffcULL) ^ 0x11def0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0581 | PC: 0x083290 | FDE: 0x11df28 | Size: 256 bytes
// Hàm FDE #0581 | Địa chỉ PC: 0x083290 | Địa chỉ FDE: 0x11df28 | Kích thước: 256 bytes
//   0x083290: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x083294: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x083298: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08329c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0581_0x083290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083290ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11df28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0582 | PC: 0x0841bc | FDE: 0x11bd08 | Size: 108 bytes [_ZN11fast_engine11MatchObjectD2Ev]
// Hàm FDE #0582 | Địa chỉ PC: 0x0841bc | Địa chỉ FDE: 0x11bd08 | Kích thước: 108 bytes
//   0x0841bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0841c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0841c4: 910043FD  add      x29, sp, #0x10
//   0x0841c8: F00005C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0582_0x0841bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0841bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bd08ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0583 | PC: 0x084228 | FDE: 0x11bd28 | Size: 116 bytes [_ZN11fast_engine11MatchObjectD0Ev]
// Hàm FDE #0583 | Địa chỉ PC: 0x084228 | Địa chỉ FDE: 0x11bd28 | Kích thước: 116 bytes
//   0x084228: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08422c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x084230: 910043FD  add      x29, sp, #0x10
//   0x084234: F00005C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0583_0x084228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084228ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bd28ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0584 | PC: 0x08429c | FDE: 0x11bd48 | Size: 256 bytes
// Hàm FDE #0584 | Địa chỉ PC: 0x08429c | Địa chỉ FDE: 0x11bd48 | Kích thước: 256 bytes
//   0x08429c: D10143FF  sub      sp, sp, #0x50
//   0x0842a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0842a4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0842a8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0584_0x08429c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08429cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x11bd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0585 | PC: 0x0843e0 | FDE: 0x11df60 | Size: 256 bytes
// Hàm FDE #0585 | Địa chỉ PC: 0x0843e0 | Địa chỉ FDE: 0x11df60 | Kích thước: 256 bytes
//   0x0843e0: D10303FF  sub      sp, sp, #0xc0
//   0x0843e4: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0843e8: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0843ec: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0585_0x0843e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0843e0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x11df60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0586 | PC: 0x084904 | FDE: 0x11df98 | Size: 236 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE8positionEm]
// Hàm FDE #0586 | Địa chỉ PC: 0x084904 | Địa chỉ FDE: 0x11df98 | Kích thước: 236 bytes
//   0x084904: D10103FF  sub      sp, sp, #0x40
//   0x084908: F90013F3  str      x19, [sp, #0x20]
//   0x08490c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x084910: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0586_0x084904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084904ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11df98ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0587 | PC: 0x0849f0 | FDE: 0x11dfc0 | Size: 256 bytes
// Hàm FDE #0587 | Địa chỉ PC: 0x0849f0 | Địa chỉ FDE: 0x11dfc0 | Kích thước: 256 bytes
//   0x0849f0: D102C3FF  sub      sp, sp, #0xb0
//   0x0849f4: F90033F9  str      x25, [sp, #0x60]
//   0x0849f8: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0849fc: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0587_0x0849f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0849f0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x11dfc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0588 | PC: 0x084cb4 | FDE: 0x11dff0 | Size: 240 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEEC2INS_11char_traitsIcEENS_9allocatorIcEEEERKNS_12basic_stringIcT_T0_EENS_15regex_constants18syntax_option_typeE]
// Hàm FDE #0588 | Địa chỉ PC: 0x084cb4 | Địa chỉ FDE: 0x11dff0 | Kích thước: 240 bytes
//   0x084cb4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x084cb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x084cbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x084cc0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0588_0x084cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084cb4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11dff0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0589 | PC: 0x084da4 | FDE: 0x11e018 | Size: 256 bytes
// Hàm FDE #0589 | Địa chỉ PC: 0x084da4 | Địa chỉ FDE: 0x11e018 | Kích thước: 256 bytes
//   0x084da4: D10303FF  sub      sp, sp, #0xc0
//   0x084da8: F90043F7  str      x23, [sp, #0x80]
//   0x084dac: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x084db0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0589_0x084da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084da4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x11e018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0590 | PC: 0x084ee4 | FDE: 0x11e048 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm]
// Hàm FDE #0590 | Địa chỉ PC: 0x084ee4 | Địa chỉ FDE: 0x11e048 | Kích thước: 256 bytes
//   0x084ee4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x084ee8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x084eec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x084ef0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0590_0x084ee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084ee4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11e048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0591 | PC: 0x085050 | FDE: 0x11e080 | Size: 256 bytes [_ZN5boost11basic_regexIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9do_assignEPKcS7_j]
// Hàm FDE #0591 | Địa chỉ PC: 0x085050 | Địa chỉ FDE: 0x11e080 | Kích thước: 256 bytes
//   0x085050: D10183FF  sub      sp, sp, #0x60
//   0x085054: F9001BF5  str      x21, [sp, #0x30]
//   0x085058: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x08505c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0591_0x085050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085050ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x11e080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0592 | PC: 0x0851e4 | FDE: 0x11e0a8 | Size: 256 bytes [_ZN5boost6detail20create_implemenationIcjNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEENSt6__ndk110shared_ptrINS_13re_detail_60026basic_regex_implementationIT_T1_EEEEPKSA_SF_T0_NS7_INS_20regex_traits_wrapperISB_EEEE]
// Hàm FDE #0592 | Địa chỉ PC: 0x0851e4 | Địa chỉ FDE: 0x11e0a8 | Kích thước: 256 bytes
//   0x0851e4: D101C3FF  sub      sp, sp, #0x70
//   0x0851e8: F90013F9  str      x25, [sp, #0x20]
//   0x0851ec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0851f0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0592_0x0851e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0851e4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11e0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0593 | PC: 0x08539c | FDE: 0x11e0d8 | Size: 236 bytes [_ZNSt6__ndk110shared_ptrIN5boost13re_detail_60026basic_regex_implementationIcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEEEC2IS8_EEPT_NS_9enable_ifIXsr14is_convertibleISC_PS8_EE5valueENS9_5__natEE4typeE]
// Hàm FDE #0593 | Địa chỉ PC: 0x08539c | Địa chỉ FDE: 0x11e0d8 | Kích thước: 236 bytes
//   0x08539c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0853a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0853a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0853a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0593_0x08539c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08539cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11e0d8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0594 | PC: 0x085488 | FDE: 0x11e100 | Size: 256 bytes [_ZN5boost13re_detail_60026basic_regex_implementationIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE6assignEPKcS8_j]
// Hàm FDE #0594 | Địa chỉ PC: 0x085488 | Địa chỉ FDE: 0x11e100 | Kích thước: 256 bytes
//   0x085488: D10483FF  sub      sp, sp, #0x120
//   0x08548c: A90E5FFC  stp      x28, x23, [sp, #0xe0]
//   0x085490: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x085494: A9104FF4  stp      x20, x19, [sp, #0x100]
static inline uint64_t fde_func_0594_0x085488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085488ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90e5ffcULL) ^ 0x11e100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0595 | PC: 0x0855ac | FDE: 0x11e130 | Size: 256 bytes [_ZN5boost13re_detail_60010regex_dataIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEC2Ev]
// Hàm FDE #0595 | Địa chỉ PC: 0x0855ac | Địa chỉ FDE: 0x11e130 | Kích thước: 256 bytes
//   0x0855ac: D101C3FF  sub      sp, sp, #0x70
//   0x0855b0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0855b4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0855b8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0595_0x0855ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0855acULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x11e130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0596 | PC: 0x085758 | FDE: 0x11e160 | Size: 180 bytes [_ZN5boost13re_detail_60021cpp_regex_traits_baseIcE5imbueERKNSt6__ndk16localeE]
// Hàm FDE #0596 | Địa chỉ PC: 0x085758 | Địa chỉ FDE: 0x11e160 | Kích thước: 180 bytes
//   0x085758: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x08575c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x085760: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x085764: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0596_0x085758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085758ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11e160ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0597 | PC: 0x08580c | FDE: 0x11e188 | Size: 256 bytes [_ZN5boost12object_cacheINS_13re_detail_60021cpp_regex_traits_baseIcEENS1_31cpp_regex_traits_implementationIcEEE6do_getERKS3_m]
// Hàm FDE #0597 | Địa chỉ PC: 0x08580c | Địa chỉ FDE: 0x11e188 | Kích thước: 256 bytes
//   0x08580c: D10283FF  sub      sp, sp, #0xa0
//   0x085810: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x085814: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x085818: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0597_0x08580c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08580cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x11e188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0598 | PC: 0x085db4 | FDE: 0x11e1c0 | Size: 188 bytes [_ZN5boost13re_detail_60031cpp_regex_traits_implementationIcEC2ERKNS0_21cpp_regex_traits_baseIcEE]
// Hàm FDE #0598 | Địa chỉ PC: 0x085db4 | Địa chỉ FDE: 0x11e1c0 | Kích thước: 188 bytes
//   0x085db4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x085db8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x085dbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x085dc0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0598_0x085db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085db4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11e1c0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0599 | PC: 0x085e70 | FDE: 0x11e1f0 | Size: 256 bytes [_ZN5boost13re_detail_60031cpp_regex_traits_implementationIcE4initEv]
// Hàm FDE #0599 | Địa chỉ PC: 0x085e70 | Địa chỉ FDE: 0x11e1f0 | Kích thước: 256 bytes
//   0x085e70: D10343FF  sub      sp, sp, #0xd0
//   0x085e74: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x085e78: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x085e7c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0599_0x085e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085e70ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x11e1f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0600 | PC: 0x0863e4 | FDE: 0x11e228 | Size: 256 bytes [_ZN5boost13re_detail_60027cpp_regex_traits_char_layerIcE4initEv]
// Hàm FDE #0600 | Địa chỉ PC: 0x0863e4 | Địa chỉ FDE: 0x11e228 | Kích thước: 256 bytes
//   0x0863e4: D102C3FF  sub      sp, sp, #0xb0
//   0x0863e8: F90033F9  str      x25, [sp, #0x60]
//   0x0863ec: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0863f0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0600_0x0863e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0863e4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x11e228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0601 | PC: 0x086794 | FDE: 0x11e258 | Size: 256 bytes [_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EERKS9_SB_]
// Hàm FDE #0601 | Địa chỉ PC: 0x086794 | Địa chỉ FDE: 0x11e258 | Kích thước: 256 bytes
//   0x086794: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x086798: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08679c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0867a0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0601_0x086794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086794ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11e258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0602 | PC: 0x0868a4 | FDE: 0x11e290 | Size: 256 bytes [_ZN5boost13re_detail_60016find_sort_syntaxINS0_31cpp_regex_traits_implementationIcEEcEEjPKT_PT0_]
// Hàm FDE #0602 | Địa chỉ PC: 0x0868a4 | Địa chỉ FDE: 0x11e290 | Kích thước: 256 bytes
//   0x0868a4: D10283FF  sub      sp, sp, #0xa0
//   0x0868a8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0868ac: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0868b0: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0602_0x0868a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0868a4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x11e290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0603 | PC: 0x086e5c | FDE: 0x11bd68 | Size: 256 bytes [_ZNSt6__ndk127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_]
// Hàm FDE #0603 | Địa chỉ PC: 0x086e5c | Địa chỉ FDE: 0x11bd68 | Kích thước: 256 bytes
//   0x086e5c: EB00003F  cmp      x1, x0
//   0x086e60: 1A9F17E8  cset     w8, eq
//   0x086e64: 39006028  strb     w8, [x1, #0x18]
//   0x086e68: 54000580  b.eq     #0x86f18
static inline uint64_t fde_func_0603_0x086e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086e5cULL ^ (static_cast<uint64_t>(0xeb00003fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e8ULL) ^ 0x11bd68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0604 | PC: 0x086ffc | FDE: 0x11e2c0 | Size: 240 bytes [_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEjEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSJ_IJEEEEEENS_4pairINS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_]
// Hàm FDE #0604 | Địa chỉ PC: 0x086ffc | Địa chỉ FDE: 0x11e2c0 | Kích thước: 240 bytes
//   0x086ffc: D10143FF  sub      sp, sp, #0x50
//   0x087000: F9000BF7  str      x23, [sp, #0x10]
//   0x087004: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x087008: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0604_0x086ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086ffcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x11e2c0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0605 | PC: 0x0870ec | FDE: 0x11bd80 | Size: 256 bytes [_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEjEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISJ_EERKT_]
// Hàm FDE #0605 | Địa chỉ PC: 0x0870ec | Địa chỉ FDE: 0x11bd80 | Kích thước: 256 bytes
//   0x0870ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0870f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0870f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0870f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0605_0x0870ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0870ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11bd80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0606 | PC: 0x08720c | FDE: 0x11e2f0 | Size: 256 bytes [_ZNK5boost13re_detail_60031cpp_regex_traits_implementationIcE9transformEPKcS4_]
// Hàm FDE #0606 | Địa chỉ PC: 0x08720c | Địa chỉ FDE: 0x11e2f0 | Kích thước: 256 bytes
//   0x08720c: D10203FF  sub      sp, sp, #0x80
//   0x087210: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x087214: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x087218: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0606_0x08720c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08720cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x11e2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0607 | PC: 0x087488 | FDE: 0x11bdb0 | Size: 96 bytes [_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE]
// Hàm FDE #0607 | Địa chỉ PC: 0x087488 | Địa chỉ FDE: 0x11bdb0 | Kích thước: 96 bytes
//   0x087488: B40002E1  cbz      x1, #0x874e4
//   0x08748c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x087490: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087494: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0607_0x087488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087488ULL ^ (static_cast<uint64_t>(0xb40002e1ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x11bdb0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0608 | PC: 0x0874e8 | FDE: 0x11bdd0 | Size: 80 bytes [_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEjEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE]
// Hàm FDE #0608 | Địa chỉ PC: 0x0874e8 | Địa chỉ FDE: 0x11bdd0 | Kích thước: 80 bytes
//   0x0874e8: B4000261  cbz      x1, #0x87534
//   0x0874ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0874f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0874f4: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0608_0x0874e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0874e8ULL ^ (static_cast<uint64_t>(0xb4000261ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x11bdd0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0609 | PC: 0x087538 | FDE: 0x11bdf0 | Size: 80 bytes [_ZNSt6__ndk16__treeINS_12__value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIiS8_NS_4lessIiEELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE]
// Hàm FDE #0609 | Địa chỉ PC: 0x087538 | Địa chỉ FDE: 0x11bdf0 | Kích thước: 80 bytes
//   0x087538: B4000261  cbz      x1, #0x87584
//   0x08753c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x087540: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087544: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0609_0x087538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087538ULL ^ (static_cast<uint64_t>(0xb4000261ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x11bdf0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0610 | PC: 0x087588 | FDE: 0x11be10 | Size: 36 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost13re_detail_60031cpp_regex_traits_implementationIcEENS_14default_deleteIS4_EENS_9allocatorIS4_EEED0Ev]
// Hàm FDE #0610 | Địa chỉ PC: 0x087588 | Địa chỉ FDE: 0x11be10 | Kích thước: 36 bytes
//   0x087588: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08758c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087590: 910043FD  add      x29, sp, #0x10
//   0x087594: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0610_0x087588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087588ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11be10ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0611 | PC: 0x0875ac | FDE: 0x11be30 | Size: 92 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost13re_detail_60031cpp_regex_traits_implementationIcEENS_14default_deleteIS4_EENS_9allocatorIS4_EEE16__on_zero_sharedEv]
// Hàm FDE #0611 | Địa chỉ PC: 0x0875ac | Địa chỉ FDE: 0x11be30 | Kích thước: 92 bytes
//   0x0875ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0875b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0875b4: 910043FD  add      x29, sp, #0x10
//   0x0875b8: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0611_0x0875ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0875acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11be30ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0612 | PC: 0x087608 | FDE: 0x11be50 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost13re_detail_60031cpp_regex_traits_implementationIcEENS_14default_deleteIS4_EENS_9allocatorIS4_EEE21__on_zero_shared_weakEv]
// Hàm FDE #0612 | Địa chỉ PC: 0x087608 | Địa chỉ FDE: 0x11be50 | Kích thước: 4 bytes
//   0x087608: 17FEEBF6  b        #0x425e0
static inline uint64_t fde_func_0612_0x087608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087608ULL ^ (static_cast<uint64_t>(0x17feebf6ULL) << 13);
    acc = (acc + a1 + 0xf81c0ff7ULL) ^ 0x11be50ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0613 | PC: 0x08760c | FDE: 0x11be68 | Size: 256 bytes [_ZNSt6__ndk16__treeINS_12__value_typeIN5boost13re_detail_60021cpp_regex_traits_baseIcEENS_15__list_iteratorINS_4pairINS_10shared_ptrIKNS3_31cpp_regex_traits_implementationIcEEEEPKS5_EEPvEEEENS_19__map_value_compareIS5_SI_NS_4lessIS5_EELb1EEENS_9allocatorISI_EEE25__emplace_unique_key_argsIS5_JNS7_IS5_SH_EEEEENS7_INS_15__tree_iteratorISI_PNS_11__tree_nodeISI_SG_EElEEbEERKT_DpOT0_]
// Hàm FDE #0613 | Địa chỉ PC: 0x08760c | Địa chỉ FDE: 0x11be68 | Kích thước: 256 bytes
//   0x08760c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x087610: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x087614: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x087618: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0613_0x08760c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08760cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11be68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0614 | PC: 0x08775c | FDE: 0x11be90 | Size: 256 bytes [_ZNSt6__ndk16__treeINS_12__value_typeIN5boost13re_detail_60021cpp_regex_traits_baseIcEENS_15__list_iteratorINS_4pairINS_10shared_ptrIKNS3_31cpp_regex_traits_implementationIcEEEEPKS5_EEPvEEEENS_19__map_value_compareIS5_SI_NS_4lessIS5_EELb1EEENS_9allocatorISI_EEE14__erase_uniqueIS5_EEmRKT_]
// Hàm FDE #0614 | Địa chỉ PC: 0x08775c | Địa chỉ FDE: 0x11be90 | Kích thước: 256 bytes
//   0x08775c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x087760: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087764: 910043FD  add      x29, sp, #0x10
//   0x087768: AA0003EB  mov      x11, x0
static inline uint64_t fde_func_0614_0x08775c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08775cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11be90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0615 | PC: 0x08788c | FDE: 0x11beb0 | Size: 256 bytes [_ZNSt6__ndk113__tree_removeIPNS_16__tree_node_baseIPvEEEEvT_S5_]
// Hàm FDE #0615 | Địa chỉ PC: 0x08788c | Địa chỉ FDE: 0x11beb0 | Kích thước: 256 bytes
//   0x08788c: F9400029  ldr      x9, [x1]
//   0x087890: AA0103EA  mov      x10, x1
//   0x087894: B40000C9  cbz      x9, #0x878ac
//   0x087898: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_0615_0x08788c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08788cULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xaa0103eaULL) ^ 0x11beb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0616 | PC: 0x087c3c | FDE: 0x11bec8 | Size: 36 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost20regex_traits_wrapperINS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteIS7_EENS_9allocatorIS7_EEED0Ev]
// Hàm FDE #0616 | Địa chỉ PC: 0x087c3c | Địa chỉ FDE: 0x11bec8 | Kích thước: 36 bytes
//   0x087c3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x087c40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087c44: 910043FD  add      x29, sp, #0x10
//   0x087c48: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0616_0x087c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087c3cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bec8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0617 | PC: 0x087c60 | FDE: 0x11bee8 | Size: 104 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost20regex_traits_wrapperINS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteIS7_EENS_9allocatorIS7_EEE16__on_zero_sharedEv]
// Hàm FDE #0617 | Địa chỉ PC: 0x087c60 | Địa chỉ FDE: 0x11bee8 | Kích thước: 104 bytes
//   0x087c60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x087c64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087c68: 910043FD  add      x29, sp, #0x10
//   0x087c6c: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0617_0x087c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087c60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bee8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0618 | PC: 0x087cc8 | FDE: 0x11bf08 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost20regex_traits_wrapperINS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteIS7_EENS_9allocatorIS7_EEE21__on_zero_shared_weakEv]
// Hàm FDE #0618 | Địa chỉ PC: 0x087cc8 | Địa chỉ FDE: 0x11bf08 | Kích thước: 4 bytes
//   0x087cc8: 17FEEA46  b        #0x425e0
static inline uint64_t fde_func_0618_0x087cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087cc8ULL ^ (static_cast<uint64_t>(0x17feea46ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x11bf08ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0619 | PC: 0x087ccc | FDE: 0x11bf20 | Size: 36 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost13re_detail_60026basic_regex_implementationIcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteIS8_EENS_9allocatorIS8_EEED0Ev]
// Hàm FDE #0619 | Địa chỉ PC: 0x087ccc | Địa chỉ FDE: 0x11bf20 | Kích thước: 36 bytes
//   0x087ccc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x087cd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087cd4: 910043FD  add      x29, sp, #0x10
//   0x087cd8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0619_0x087ccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087cccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bf20ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0620 | PC: 0x087cf0 | FDE: 0x11bf40 | Size: 184 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost13re_detail_60026basic_regex_implementationIcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteIS8_EENS_9allocatorIS8_EEE16__on_zero_sharedEv]
// Hàm FDE #0620 | Địa chỉ PC: 0x087cf0 | Địa chỉ FDE: 0x11bf40 | Kích thước: 184 bytes
//   0x087cf0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x087cf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087cf8: 910043FD  add      x29, sp, #0x10
//   0x087cfc: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0620_0x087cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087cf0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bf40ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0621 | PC: 0x087da8 | FDE: 0x11bf60 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost13re_detail_60026basic_regex_implementationIcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteIS8_EENS_9allocatorIS8_EEE21__on_zero_shared_weakEv]
// Hàm FDE #0621 | Địa chỉ PC: 0x087da8 | Địa chỉ FDE: 0x11bf60 | Kích thước: 4 bytes
//   0x087da8: 17FEEA0E  b        #0x425e0
static inline uint64_t fde_func_0621_0x087da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087da8ULL ^ (static_cast<uint64_t>(0x17feea0eULL) << 13);
    acc = (acc + a1 + 0xd10283ffULL) ^ 0x11bf60ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0622 | PC: 0x087dac | FDE: 0x11e320 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE5parseEPKcS8_j]
// Hàm FDE #0622 | Địa chỉ PC: 0x087dac | Địa chỉ FDE: 0x11e320 | Kích thước: 256 bytes
//   0x087dac: D10283FF  sub      sp, sp, #0xa0
//   0x087db0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x087db4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x087db8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0622_0x087dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087dacULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x11e320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0623 | PC: 0x08824c | FDE: 0x11e358 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEC2EPNS0_10regex_dataIcS5_EE]
// Hàm FDE #0623 | Địa chỉ PC: 0x08824c | Địa chỉ FDE: 0x11e358 | Kích thước: 256 bytes
//   0x08824c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x088250: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x088254: 910043FD  add      x29, sp, #0x10
//   0x088258: F9000001  str      x1, [x0]
static inline uint64_t fde_func_0623_0x08824c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08824cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11e358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0624 | PC: 0x08835c | FDE: 0x11e380 | Size: 256 bytes [_ZNK5boost13re_detail_60031cpp_regex_traits_implementationIcE16lookup_classnameEPKcS4_]
// Hàm FDE #0624 | Địa chỉ PC: 0x08835c | Địa chỉ FDE: 0x11e380 | Kích thước: 256 bytes
//   0x08835c: D10183FF  sub      sp, sp, #0x60
//   0x088360: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x088364: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x088368: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0624_0x08835c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08835cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11e380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0625 | PC: 0x088514 | FDE: 0x11e3b0 | Size: 256 bytes [_ZNK5boost13re_detail_60031cpp_regex_traits_implementationIcE20lookup_classname_impEPKcS4_]
// Hàm FDE #0625 | Địa chỉ PC: 0x088514 | Địa chỉ FDE: 0x11e3b0 | Kích thước: 256 bytes
//   0x088514: D10183FF  sub      sp, sp, #0x60
//   0x088518: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08851c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x088520: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0625_0x088514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088514ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11e3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0626 | PC: 0x08876c | FDE: 0x11bf78 | Size: 256 bytes [_ZNKSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEjEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_]
// Hàm FDE #0626 | Địa chỉ PC: 0x08876c | Địa chỉ FDE: 0x11bf78 | Kích thước: 256 bytes
//   0x08876c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x088770: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x088774: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x088778: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0626_0x08876c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08876cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11bf78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0627 | PC: 0x088880 | FDE: 0x11e3e0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE4failENS_15regex_constants10error_typeEl]
// Hàm FDE #0627 | Địa chỉ PC: 0x088880 | Địa chỉ FDE: 0x11e3e0 | Kích thước: 256 bytes
//   0x088880: D10243FF  sub      sp, sp, #0x90
//   0x088884: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x088888: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x08888c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0627_0x088880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088880ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0628 | PC: 0x088a80 | FDE: 0x11e418 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14parse_extendedEv]
// Hàm FDE #0628 | Địa chỉ PC: 0x088a80 | Địa chỉ FDE: 0x11e418 | Kích thước: 256 bytes
//   0x088a80: D10243FF  sub      sp, sp, #0x90
//   0x088a84: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x088a88: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x088a8c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0628_0x088a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088a80ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0629 | PC: 0x089114 | FDE: 0x11bfa0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE11parse_basicEv]
// Hàm FDE #0629 | Địa chỉ PC: 0x089114 | Địa chỉ FDE: 0x11bfa0 | Kích thước: 256 bytes
//   0x089114: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x089118: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08911c: 910043FD  add      x29, sp, #0x10
//   0x089120: F9404408  ldr      x8, [x0, #0x88]
static inline uint64_t fde_func_0629_0x089114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089114ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bfa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0630 | PC: 0x089380 | FDE: 0x11bfc0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13parse_literalEv]
// Hàm FDE #0630 | Địa chỉ PC: 0x089380 | Địa chỉ FDE: 0x11bfc0 | Kích thước: 256 bytes
//   0x089380: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x089384: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x089388: 910043FD  add      x29, sp, #0x10
//   0x08938c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0630_0x089380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089380ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11bfc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0631 | PC: 0x089490 | FDE: 0x11e450 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9parse_allEv]
// Hàm FDE #0631 | Địa chỉ PC: 0x089490 | Địa chỉ FDE: 0x11e450 | Kích thước: 256 bytes
//   0x089490: D10243FF  sub      sp, sp, #0x90
//   0x089494: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x089498: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x08949c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0631_0x089490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089490ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0632 | PC: 0x089674 | FDE: 0x11e488 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE11unwind_altsEl]
// Hàm FDE #0632 | Địa chỉ PC: 0x089674 | Địa chỉ FDE: 0x11e488 | Kích thước: 256 bytes
//   0x089674: D10243FF  sub      sp, sp, #0x90
//   0x089678: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08967c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x089680: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0632_0x089674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089674ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0633 | PC: 0x089970 | FDE: 0x11bfe0 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE8finalizeEPKcS8_]
// Hàm FDE #0633 | Địa chỉ PC: 0x089970 | Địa chỉ FDE: 0x11bfe0 | Kích thước: 256 bytes
//   0x089970: D10143FF  sub      sp, sp, #0x50
//   0x089974: F9000BF7  str      x23, [sp, #0x10]
//   0x089978: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08997c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0633_0x089970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089970ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x11bfe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0634 | PC: 0x089c2c | FDE: 0x11c008 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16parse_open_parenEv]
// Hàm FDE #0634 | Địa chỉ PC: 0x089c2c | Địa chỉ FDE: 0x11c008 | Kích thước: 256 bytes
//   0x089c2c: D10203FF  sub      sp, sp, #0x80
//   0x089c30: F90013FB  str      x27, [sp, #0x20]
//   0x089c34: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x089c38: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0634_0x089c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089c2cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x11c008ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0635 | PC: 0x089f8c | FDE: 0x11e4c0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE21parse_extended_escapeEv]
// Hàm FDE #0635 | Địa chỉ PC: 0x089f8c | Địa chỉ FDE: 0x11e4c0 | Kích thước: 256 bytes
//   0x089f8c: D10383FF  sub      sp, sp, #0xe0
//   0x089f90: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x089f94: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x089f98: A90B57F6  stp      x22, x21, [sp, #0xb0]
static inline uint64_t fde_func_0635_0x089f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089f8cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90967faULL) ^ 0x11e4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0636 | PC: 0x08b1a4 | FDE: 0x11e4f8 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE12parse_repeatEmm]
// Hàm FDE #0636 | Địa chỉ PC: 0x08b1a4 | Địa chỉ FDE: 0x11e4f8 | Kích thước: 256 bytes
//   0x08b1a4: D10243FF  sub      sp, sp, #0x90
//   0x08b1a8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08b1ac: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x08b1b0: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0636_0x08b1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b1a4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e4f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0637 | PC: 0x08b9ac | FDE: 0x11e530 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18parse_repeat_rangeEb]
// Hàm FDE #0637 | Địa chỉ PC: 0x08b9ac | Địa chỉ FDE: 0x11e530 | Kích thước: 256 bytes
//   0x08b9ac: D10243FF  sub      sp, sp, #0x90
//   0x08b9b0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08b9b4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x08b9b8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0637_0x08b9ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b9acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0638 | PC: 0x08c658 | FDE: 0x11e568 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9parse_altEv]
// Hàm FDE #0638 | Địa chỉ PC: 0x08c658 | Địa chỉ FDE: 0x11e568 | Kích thước: 256 bytes
//   0x08c658: D10243FF  sub      sp, sp, #0x90
//   0x08c65c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08c660: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x08c664: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0638_0x08c658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c658ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0639 | PC: 0x08c960 | FDE: 0x11e5a0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9parse_setEv]
// Hàm FDE #0639 | Địa chỉ PC: 0x08c960 | Địa chỉ FDE: 0x11e5a0 | Kích thước: 256 bytes
//   0x08c960: D10343FF  sub      sp, sp, #0xd0
//   0x08c964: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x08c968: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x08c96c: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_0639_0x08c960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c960ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90867faULL) ^ 0x11e5a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0640 | PC: 0x08cd58 | FDE: 0x11e5d8 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE20parse_perl_extensionEv]
// Hàm FDE #0640 | Địa chỉ PC: 0x08cd58 | Địa chỉ FDE: 0x11e5d8 | Kích thước: 256 bytes
//   0x08cd58: D10303FF  sub      sp, sp, #0xc0
//   0x08cd5c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x08cd60: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x08cd64: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0640_0x08cd58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cd58ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x11e5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0641 | PC: 0x08ed94 | FDE: 0x11c038 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE15parse_perl_verbEv]
// Hàm FDE #0641 | Địa chỉ PC: 0x08ed94 | Địa chỉ FDE: 0x11c038 | Kích thước: 256 bytes
//   0x08ed94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08ed98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ed9c: 910043FD  add      x29, sp, #0x10
//   0x08eda0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0641_0x08ed94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ed94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0642 | PC: 0x08f44c | FDE: 0x11e610 | Size: 256 bytes [_ZNK5boost16cpp_regex_traitsIcE3toiERPKcS3_i]
// Hàm FDE #0642 | Địa chỉ PC: 0x08f44c | Địa chỉ FDE: 0x11e610 | Kích thước: 256 bytes
//   0x08f44c: D10583FF  sub      sp, sp, #0x160
//   0x08f450: F90083FC  str      x28, [sp, #0x100]
//   0x08f454: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x08f458: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_0642_0x08f44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f44cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x11e610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0643 | PC: 0x08f6d4 | FDE: 0x11c058 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13parse_optionsEv]
// Hàm FDE #0643 | Địa chỉ PC: 0x08f6d4 | Địa chỉ FDE: 0x11c058 | Kích thước: 256 bytes
//   0x08f6d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08f6d8: 910003FD  mov      x29, sp
//   0x08f6dc: F9400008  ldr      x8, [x0]
//   0x08f6e0: F9404409  ldr      x9, [x0, #0x88]
static inline uint64_t fde_func_0643_0x08f6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f6d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11c058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0644 | PC: 0x08f868 | FDE: 0x11c078 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE12insert_stateElNS0_19syntax_element_typeEm]
// Hàm FDE #0644 | Địa chỉ PC: 0x08f868 | Địa chỉ FDE: 0x11c078 | Kích thước: 256 bytes
//   0x08f868: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08f86c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x08f870: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08f874: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0644_0x08f868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f868ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11c078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0645 | PC: 0x08f9b0 | FDE: 0x11c0a8 | Size: 52 bytes [_ZN5boost13re_detail_60010parser_bufIcNSt6__ndk111char_traitsIcEEED0Ev]
// Hàm FDE #0645 | Địa chỉ PC: 0x08f9b0 | Địa chỉ FDE: 0x11c0a8 | Kích thước: 52 bytes
//   0x08f9b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f9b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f9b8: 910043FD  add      x29, sp, #0x10
//   0x08f9bc: 90000588  adrp     x8, #0x13f000
static inline uint64_t fde_func_0645_0x08f9b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f9b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c0a8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0646 | PC: 0x08f9e4 | FDE: 0x11c0c8 | Size: 16 bytes [_ZN5boost13re_detail_60010parser_bufIcNSt6__ndk111char_traitsIcEEE6setbufEPcl]
// Hàm FDE #0646 | Địa chỉ PC: 0x08f9e4 | Địa chỉ FDE: 0x11c0c8 | Kích thước: 16 bytes
//   0x08f9e4: 8B020028  add      x8, x1, x2
//   0x08f9e8: A9010401  stp      x1, x1, [x0, #0x10]
//   0x08f9ec: F9001008  str      x8, [x0, #0x20]
//   0x08f9f0: D65F03C0  ret      
static inline uint64_t fde_func_0646_0x08f9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f9e4ULL ^ (static_cast<uint64_t>(0x8b020028ULL) << 13);
    acc = (acc + a1 + 0xa9010401ULL) ^ 0x11c0c8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0647 | PC: 0x08f9f4 | FDE: 0x11c0e0 | Size: 152 bytes [_ZN5boost13re_detail_60010parser_bufIcNSt6__ndk111char_traitsIcEEE7seekoffExNS2_8ios_base7seekdirEj]
// Hàm FDE #0647 | Địa chỉ PC: 0x08f9f4 | Địa chỉ FDE: 0x11c0e0 | Kích thước: 152 bytes
//   0x08f9f4: 37200203  tbnz     w3, #4, #0x8fa34
//   0x08f9f8: F940100B  ldr      x11, [x0, #0x20]
//   0x08f9fc: F9400809  ldr      x9, [x0, #0x10]
//   0x08fa00: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0647_0x08f9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f9f4ULL ^ (static_cast<uint64_t>(0x37200203ULL) << 13);
    acc = (acc + a1 + 0xf940100bULL) ^ 0x11c0e0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0648 | PC: 0x08fa8c | FDE: 0x11c0f8 | Size: 44 bytes [_ZN5boost13re_detail_60010parser_bufIcNSt6__ndk111char_traitsIcEEE7seekposENS2_4fposI9mbstate_tEEj]
// Hàm FDE #0648 | Địa chỉ PC: 0x08fa8c | Địa chỉ FDE: 0x11c0f8 | Kích thước: 44 bytes
//   0x08fa8c: 37200103  tbnz     w3, #4, #0x8faac
//   0x08fa90: F9401009  ldr      x9, [x0, #0x20]
//   0x08fa94: F9400808  ldr      x8, [x0, #0x10]
//   0x08fa98: CB080129  sub      x9, x9, x8
static inline uint64_t fde_func_0648_0x08fa8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fa8cULL ^ (static_cast<uint64_t>(0x37200103ULL) << 13);
    acc = (acc + a1 + 0xf9401009ULL) ^ 0x11c0f8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0649 | PC: 0x08fab8 | FDE: 0x11e648 | Size: 256 bytes
// Hàm FDE #0649 | Địa chỉ PC: 0x08fab8 | Địa chỉ FDE: 0x11e648 | Kích thước: 256 bytes
//   0x08fab8: D10143FF  sub      sp, sp, #0x50
//   0x08fabc: F90013F5  str      x21, [sp, #0x20]
//   0x08fac0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08fac4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0649_0x08fab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fab8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x11e648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0650 | PC: 0x08fc08 | FDE: 0x11e670 | Size: 256 bytes [_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC2ERS3_b]
// Hàm FDE #0650 | Địa chỉ PC: 0x08fc08 | Địa chỉ FDE: 0x11e670 | Kích thước: 256 bytes
//   0x08fc08: D10143FF  sub      sp, sp, #0x50
//   0x08fc0c: F9000BF7  str      x23, [sp, #0x10]
//   0x08fc10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08fc14: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0650_0x08fc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fc08ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x11e670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0651 | PC: 0x08fdf4 | FDE: 0x11c110 | Size: 256 bytes [_ZNSt6__ndk16vectorIN5boost13re_detail_60020named_subexpressions4nameENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEvOT_]
// Hàm FDE #0651 | Địa chỉ PC: 0x08fdf4 | Địa chỉ FDE: 0x11c110 | Kích thước: 256 bytes
//   0x08fdf4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x08fdf8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08fdfc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08fe00: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0651_0x08fdf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fdf4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0652 | PC: 0x08ff00 | FDE: 0x11c140 | Size: 212 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10match_verbEPKc]
// Hàm FDE #0652 | Địa chỉ PC: 0x08ff00 | Địa chỉ FDE: 0x11c140 | Kích thước: 212 bytes
//   0x08ff00: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08ff04: 910003FD  mov      x29, sp
//   0x08ff08: 3940002A  ldrb     w10, [x1]
//   0x08ff0c: 340001CA  cbz      w10, #0x8ff44
static inline uint64_t fde_func_0652_0x08ff00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ff00ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11c140ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0653 | PC: 0x08ffd4 | FDE: 0x11c160 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_4pairImmEENS_9allocatorIS2_EEE21__push_back_slow_pathIS2_EEvOT_]
// Hàm FDE #0653 | Địa chỉ PC: 0x08ffd4 | Địa chỉ FDE: 0x11c160 | Kích thước: 256 bytes
//   0x08ffd4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x08ffd8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08ffdc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08ffe0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0653_0x08ffd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ffd4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0654 | PC: 0x0900e4 | FDE: 0x11c190 | Size: 20 bytes [_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_out_of_rangeEv]
// Hàm FDE #0654 | Địa chỉ PC: 0x0900e4 | Địa chỉ FDE: 0x11c190 | Kích thước: 20 bytes
//   0x0900e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0900e8: 910003FD  mov      x29, sp
//   0x0900ec: B00003C0  adrp     x0, #0x109000
//   0x0900f0: 912D4800  add      x0, x0, #0xb52
static inline uint64_t fde_func_0654_0x0900e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0900e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11c190ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0655 | PC: 0x0900f8 | FDE: 0x11c1b0 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14append_literalEc]
// Hàm FDE #0655 | Địa chỉ PC: 0x0900f8 | Địa chỉ FDE: 0x11c1b0 | Kích thước: 256 bytes
//   0x0900f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0900fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x090100: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x090104: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0655_0x0900f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0900f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0656 | PC: 0x090220 | FDE: 0x11e6a0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18unescape_characterEv]
// Hàm FDE #0656 | Địa chỉ PC: 0x090220 | Địa chỉ FDE: 0x11e6a0 | Kích thước: 256 bytes
//   0x090220: D10243FF  sub      sp, sp, #0x90
//   0x090224: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x090228: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x09022c: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0656_0x090220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090220ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e6a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0657 | PC: 0x090d78 | FDE: 0x11c1d8 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13parse_backrefEv]
// Hàm FDE #0657 | Địa chỉ PC: 0x090d78 | Địa chỉ FDE: 0x11c1d8 | Kích thước: 256 bytes
//   0x090d78: D10103FF  sub      sp, sp, #0x40
//   0x090d7c: F9000BF5  str      x21, [sp, #0x10]
//   0x090d80: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x090d84: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0657_0x090d78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090d78ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x11c1d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0658 | PC: 0x090eec | FDE: 0x11e6d8 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE8parse_QEEv]
// Hàm FDE #0658 | Địa chỉ PC: 0x090eec | Địa chỉ FDE: 0x11e6d8 | Kích thước: 256 bytes
//   0x090eec: D10243FF  sub      sp, sp, #0x90
//   0x090ef0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x090ef4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x090ef8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0658_0x090eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090eecULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0659 | PC: 0x091118 | FDE: 0x11e710 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10append_setERKNS0_14basic_char_setIcS5_EEPNSt6__ndk117integral_constantIbLb0EEE]
// Hàm FDE #0659 | Địa chỉ PC: 0x091118 | Địa chỉ FDE: 0x11e710 | Kích thước: 256 bytes
//   0x091118: D10483FF  sub      sp, sp, #0x120
//   0x09111c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x091120: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x091124: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0659_0x091118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091118ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x11e710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0660 | PC: 0x091bd0 | FDE: 0x11e748 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10append_setERKNS0_14basic_char_setIcS5_EEPNSt6__ndk117integral_constantIbLb1EEE]
// Hàm FDE #0660 | Địa chỉ PC: 0x091bd0 | Địa chỉ FDE: 0x11e748 | Kích thước: 256 bytes
//   0x091bd0: D103C3FF  sub      sp, sp, #0xf0
//   0x091bd4: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x091bd8: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x091bdc: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0660_0x091bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091bd0ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x11e748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0661 | PC: 0x092590 | FDE: 0x11c1f8 | Size: 192 bytes [_ZN5boost13re_detail_60011raw_storage6extendEm]
// Hàm FDE #0661 | Địa chỉ PC: 0x092590 | Địa chỉ FDE: 0x11c1f8 | Kích thước: 192 bytes
//   0x092590: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x092594: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x092598: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09259c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0661_0x092590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092590ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11c1f8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0662 | PC: 0x092650 | FDE: 0x11c220 | Size: 240 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertENS_11__wrap_iterIPKcEEc]
// Hàm FDE #0662 | Địa chỉ PC: 0x092650 | Địa chỉ FDE: 0x11c220 | Kích thước: 240 bytes
//   0x092650: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x092654: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x092658: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09265c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0662_0x092650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092650ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11c220ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0663 | PC: 0x092740 | FDE: 0x11e780 | Size: 256 bytes [_ZNK5boost13re_detail_60031cpp_regex_traits_implementationIcE17transform_primaryEPKcS4_]
// Hàm FDE #0663 | Địa chỉ PC: 0x092740 | Địa chỉ FDE: 0x11e780 | Kích thước: 256 bytes
//   0x092740: D10183FF  sub      sp, sp, #0x60
//   0x092744: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x092748: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09274c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0663_0x092740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092740ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11e780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0664 | PC: 0x092c08 | FDE: 0x11c248 | Size: 64 bytes [_ZNSt6__ndk16__treeIN5boost13re_detail_6007digraphIcEENS_4lessIS4_EENS_9allocatorIS4_EEE7destroyEPNS_11__tree_nodeIS4_PvEE]
// Hàm FDE #0664 | Địa chỉ PC: 0x092c08 | Địa chỉ FDE: 0x11c248 | Kích thước: 64 bytes
//   0x092c08: B40001E1  cbz      x1, #0x92c44
//   0x092c0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x092c10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092c14: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0664_0x092c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092c08ULL ^ (static_cast<uint64_t>(0xb40001e1ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x11c248ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0665 | PC: 0x092c48 | FDE: 0x11e7b0 | Size: 256 bytes [_ZNK5boost13re_detail_60031cpp_regex_traits_implementationIcE18lookup_collatenameEPKcS4_]
// Hàm FDE #0665 | Địa chỉ PC: 0x092c48 | Địa chỉ FDE: 0x11e7b0 | Kích thước: 256 bytes
//   0x092c48: D10243FF  sub      sp, sp, #0x90
//   0x092c4c: F90023F9  str      x25, [sp, #0x40]
//   0x092c50: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x092c54: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0665_0x092c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092c48ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x11e7b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0666 | PC: 0x093048 | FDE: 0x11e7e0 | Size: 256 bytes [_ZN5boost13re_detail_60027lookup_default_collate_nameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0666 | Địa chỉ PC: 0x093048 | Địa chỉ FDE: 0x11e7e0 | Kích thước: 256 bytes
//   0x093048: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x09304c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x093050: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x093054: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0666_0x093048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093048ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11e7e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0667 | PC: 0x0931c4 | FDE: 0x11c268 | Size: 256 bytes [_ZNKSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_]
// Hàm FDE #0667 | Địa chỉ PC: 0x0931c4 | Địa chỉ FDE: 0x11c268 | Kích thước: 256 bytes
//   0x0931c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0931c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0931cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0931d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0667_0x0931c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0931c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11c268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0668 | PC: 0x0932d8 | FDE: 0x11c290 | Size: 256 bytes [_ZNSt6__ndk16vectorIlNS_9allocatorIlEEE21__push_back_slow_pathIRKlEEvOT_]
// Hàm FDE #0668 | Địa chỉ PC: 0x0932d8 | Địa chỉ FDE: 0x11c290 | Kích thước: 256 bytes
//   0x0932d8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0932dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0932e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0932e4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0668_0x0932d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0932d8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0669 | PC: 0x0933e4 | FDE: 0x11c2c0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE17parse_set_literalERNS0_14basic_char_setIcS5_EE]
// Hàm FDE #0669 | Địa chỉ PC: 0x0933e4 | Địa chỉ FDE: 0x11c2c0 | Kích thước: 256 bytes
//   0x0933e4: D10143FF  sub      sp, sp, #0x50
//   0x0933e8: F90013F5  str      x21, [sp, #0x20]
//   0x0933ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0933f0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0669_0x0933e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0933e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x11c2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0670 | PC: 0x093558 | FDE: 0x11e810 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE15parse_inner_setERNS0_14basic_char_setIcS5_EE]
// Hàm FDE #0670 | Địa chỉ PC: 0x093558 | Địa chỉ FDE: 0x11e810 | Kích thước: 256 bytes
//   0x093558: D10243FF  sub      sp, sp, #0x90
//   0x09355c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x093560: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x093564: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0670_0x093558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093558ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11e810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0671 | PC: 0x094124 | FDE: 0x11e848 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE20get_next_set_literalERNS0_14basic_char_setIcS5_EE]
// Hàm FDE #0671 | Địa chỉ PC: 0x094124 | Địa chỉ FDE: 0x11e848 | Kích thước: 256 bytes
//   0x094124: D10183FF  sub      sp, sp, #0x60
//   0x094128: F90013F7  str      x23, [sp, #0x20]
//   0x09412c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x094130: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0671_0x094124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094124ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11e848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0672 | PC: 0x0943ec | FDE: 0x11c2e0 | Size: 256 bytes [_ZN5boost13re_detail_60014basic_char_setIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9add_rangeERKNS0_7digraphIcEESA_]
// Hàm FDE #0672 | Địa chỉ PC: 0x0943ec | Địa chỉ FDE: 0x11c2e0 | Kích thước: 256 bytes
//   0x0943ec: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0943f0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0943f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0943f8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0672_0x0943ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0943ecULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c2e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0673 | PC: 0x094680 | FDE: 0x11c310 | Size: 256 bytes [_ZNSt6__ndk16__treeIN5boost13re_detail_6007digraphIcEENS_4lessIS4_EENS_9allocatorIS4_EEE25__emplace_unique_key_argsIS4_JRKS4_EEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_]
// Hàm FDE #0673 | Địa chỉ PC: 0x094680 | Địa chỉ FDE: 0x11c310 | Kích thước: 256 bytes
//   0x094680: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x094684: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x094688: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09468c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0673_0x094680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094680ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11c310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0674 | PC: 0x094798 | FDE: 0x11e878 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18parse_basic_escapeEv]
// Hàm FDE #0674 | Địa chỉ PC: 0x094798 | Địa chỉ FDE: 0x11e878 | Kích thước: 256 bytes
//   0x094798: D10343FF  sub      sp, sp, #0xd0
//   0x09479c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0947a0: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0947a4: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_0674_0x094798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094798ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90867faULL) ^ 0x11e878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x094eb8 | FDE: 0x11e8b0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14add_emacs_codeEb]
// Hàm FDE #0675 | Địa chỉ PC: 0x094eb8 | Địa chỉ FDE: 0x11e8b0 | Kích thước: 256 bytes
//   0x094eb8: D10283FF  sub      sp, sp, #0xa0
//   0x094ebc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x094ec0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x094ec4: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0675_0x094eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094eb8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x11e8b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0676 | PC: 0x095d70 | FDE: 0x11e8e0 | Size: 256 bytes [_ZN5boost13re_detail_60018basic_regex_parserIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE4failENS_15regex_constants10error_typeElNSt6__ndk112basic_stringIcNS9_11char_traitsIcEENS9_9allocatorIcEEEEl]
// Hàm FDE #0676 | Địa chỉ PC: 0x095d70 | Địa chỉ FDE: 0x11e8e0 | Kích thước: 256 bytes
//   0x095d70: D10283FF  sub      sp, sp, #0xa0
//   0x095d74: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x095d78: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x095d7c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0676_0x095d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095d70ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x11e8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0677 | PC: 0x096160 | FDE: 0x11c338 | Size: 36 bytes [_ZN5boost11regex_errorD0Ev]
// Hàm FDE #0677 | Địa chỉ PC: 0x096160 | Địa chỉ FDE: 0x11c338 | Kích thước: 36 bytes
//   0x096160: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096164: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096168: 910043FD  add      x29, sp, #0x10
//   0x09616c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0677_0x096160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096160ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c338ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0678 | PC: 0x096184 | FDE: 0x11c358 | Size: 196 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14fixup_pointersEPNS0_14re_syntax_baseE]
// Hàm FDE #0678 | Địa chỉ PC: 0x096184 | Địa chỉ FDE: 0x11c358 | Kích thước: 196 bytes
//   0x096184: B4000601  cbz      x1, #0x96244
//   0x096188: F00003A8  adrp     x8, #0x10d000
//   0x09618c: 91235108  add      x8, x8, #0x8d4
//   0x096190: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_0678_0x096184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096184ULL ^ (static_cast<uint64_t>(0xb4000601ULL) << 13);
    acc = (acc + a1 + 0xf00003a8ULL) ^ 0x11c358ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0679 | PC: 0x096248 | FDE: 0x11e918 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16fixup_recursionsEPNS0_14re_syntax_baseE]
// Hàm FDE #0679 | Địa chỉ PC: 0x096248 | Địa chỉ FDE: 0x11e918 | Kích thước: 256 bytes
//   0x096248: D10183FF  sub      sp, sp, #0x60
//   0x09624c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x096250: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x096254: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0679_0x096248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096248ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x11e918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0680 | PC: 0x096588 | FDE: 0x11e940 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16create_startmapsEPNS0_14re_syntax_baseE]
// Hàm FDE #0680 | Địa chỉ PC: 0x096588 | Địa chỉ FDE: 0x11e940 | Kích thước: 256 bytes
//   0x096588: D102C3FF  sub      sp, sp, #0xb0
//   0x09658c: F90033F9  str      x25, [sp, #0x60]
//   0x096590: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x096594: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0680_0x096588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096588ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x11e940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0681 | PC: 0x0968e0 | FDE: 0x11c370 | Size: 256 bytes [_ZNSt6__ndk16vectorIhNS_9allocatorIhEEE6assignEmRKh]
// Hàm FDE #0681 | Địa chỉ PC: 0x0968e0 | Địa chỉ FDE: 0x11c370 | Kích thước: 256 bytes
//   0x0968e0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0968e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0968e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0968ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0681_0x0968e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0968e0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0682 | PC: 0x096b0c | FDE: 0x11e970 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE15create_startmapEPNS0_14re_syntax_baseEPhPjhj]
// Hàm FDE #0682 | Địa chỉ PC: 0x096b0c | Địa chỉ FDE: 0x11e970 | Kích thước: 256 bytes
//   0x096b0c: D104C3FF  sub      sp, sp, #0x130
//   0x096b10: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x096b14: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x096b18: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0682_0x096b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096b0cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x11e970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0683 | PC: 0x097f88 | FDE: 0x11e9a8 | Size: 256 bytes [_ZN5boost13re_detail_60019basic_regex_creatorIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18calculate_backstepEPNS0_14re_syntax_baseE]
// Hàm FDE #0683 | Địa chỉ PC: 0x097f88 | Địa chỉ FDE: 0x11e9a8 | Kích thước: 256 bytes
//   0x097f88: D10243FF  sub      sp, sp, #0x90
//   0x097f8c: F9001BFB  str      x27, [sp, #0x30]
//   0x097f90: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x097f94: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0683_0x097f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097f88ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x11e9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0684 | PC: 0x09824c | FDE: 0x11c398 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_4pairIbPN5boost13re_detail_60014re_syntax_baseEEENS_9allocatorIS6_EEE21__push_back_slow_pathIS6_EEvOT_]
// Hàm FDE #0684 | Địa chỉ PC: 0x09824c | Địa chỉ FDE: 0x11c398 | Kích thước: 256 bytes
//   0x09824c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x098250: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x098254: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x098258: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0684_0x09824c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09824cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0685 | PC: 0x09835c | FDE: 0x11c3c8 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_5tupleIJiPN5boost13re_detail_60014re_syntax_baseEEEENS_9allocatorIS6_EEE21__push_back_slow_pathIS6_EEvOT_]
// Hàm FDE #0685 | Địa chỉ PC: 0x09835c | Địa chỉ FDE: 0x11c3c8 | Kích thước: 256 bytes
//   0x09835c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x098360: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x098364: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x098368: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0685_0x09835c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09835cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c3c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0686 | PC: 0x09846c | FDE: 0x11e9e0 | Size: 256 bytes [_ZN5boost13re_detail_60016re_is_set_memberIPccNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEjEET_S7_S7_PKNS0_11re_set_longIT2_EERKNS0_10regex_dataIT0_T1_EEb]
// Hàm FDE #0686 | Địa chỉ PC: 0x09846c | Địa chỉ FDE: 0x11e9e0 | Kích thước: 256 bytes
//   0x09846c: D102C3FF  sub      sp, sp, #0xb0
//   0x098470: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x098474: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x098478: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0686_0x09846c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09846cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x11e9e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0687 | PC: 0x098b24 | FDE: 0x11ea18 | Size: 164 bytes [_ZNSt6__ndk16vectorIhNS_9allocatorIhEEEC2ERKS3_]
// Hàm FDE #0687 | Địa chỉ PC: 0x098b24 | Địa chỉ FDE: 0x11ea18 | Kích thước: 164 bytes
//   0x098b24: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x098b28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x098b2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x098b30: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0687_0x098b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098b24ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11ea18ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0688 | PC: 0x098bc8 | FDE: 0x11c3f8 | Size: 208 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEmc]
// Hàm FDE #0688 | Địa chỉ PC: 0x098bc8 | Địa chỉ FDE: 0x11c3f8 | Kích thước: 208 bytes
//   0x098bc8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x098bcc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x098bd0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x098bd4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0688_0x098bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098bc8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c3f8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0689 | PC: 0x098c98 | FDE: 0x11ea48 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEC2ES6_S6_RNS_13match_resultsIS6_SA_EERKNS_11basic_regexIcSE_EENS_15regex_constants12_match_flagsES6_]
// Hàm FDE #0689 | Địa chỉ PC: 0x098c98 | Địa chỉ FDE: 0x11ea48 | Kích thước: 256 bytes
//   0x098c98: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x098c9c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x098ca0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x098ca4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0689_0x098c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098c98ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11ea48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0690 | PC: 0x098e5c | FDE: 0x11c420 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEED2Ev]
// Hàm FDE #0690 | Địa chỉ PC: 0x098e5c | Địa chỉ FDE: 0x11c420 | Kích thước: 256 bytes
//   0x098e5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x098e60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x098e64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x098e68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0690_0x098e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098e5cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0691 | PC: 0x098fa4 | FDE: 0x11ea78 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14construct_initERKNS_11basic_regexIcSE_EENS_15regex_constants12_match_flagsE]
// Hàm FDE #0691 | Địa chỉ PC: 0x098fa4 | Địa chỉ FDE: 0x11ea78 | Kích thước: 256 bytes
//   0x098fa4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x098fa8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x098fac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x098fb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0691_0x098fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098fa4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11ea78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0692 | PC: 0x099270 | FDE: 0x11c448 | Size: 48 bytes
// Hàm FDE #0692 | Địa chỉ PC: 0x099270 | Địa chỉ FDE: 0x11c448 | Kích thước: 48 bytes
//   0x099270: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x099274: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099278: 910043FD  add      x29, sp, #0x10
//   0x09927c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0692_0x099270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099270ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c448ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0693 | PC: 0x0992a0 | FDE: 0x11eaa8 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE8find_impEv]
// Hàm FDE #0693 | Địa chỉ PC: 0x0992a0 | Địa chỉ FDE: 0x11eaa8 | Kích thước: 256 bytes
//   0x0992a0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0992a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0992a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0992ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0693_0x0992a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0992a0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11eaa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0694 | PC: 0x0995e0 | FDE: 0x11c468 | Size: 176 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16find_restart_anyEv]
// Hàm FDE #0694 | Địa chỉ PC: 0x0995e0 | Địa chỉ FDE: 0x11c468 | Kích thước: 176 bytes
//   0x0995e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0995e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0995e8: 910043FD  add      x29, sp, #0x10
//   0x0995ec: A9422408  ldp      x8, x9, [x0, #0x20]
static inline uint64_t fde_func_0694_0x0995e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0995e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c468ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0695 | PC: 0x099690 | FDE: 0x11c488 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE17find_restart_wordEv]
// Hàm FDE #0695 | Địa chỉ PC: 0x099690 | Địa chỉ FDE: 0x11c488 | Kích thước: 256 bytes
//   0x099690: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x099694: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x099698: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09969c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0695_0x099690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099690ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x0998dc | FDE: 0x11c4b0 | Size: 248 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE17find_restart_lineEv]
// Hàm FDE #0696 | Địa chỉ PC: 0x0998dc | Địa chỉ FDE: 0x11c4b0 | Kích thước: 248 bytes
//   0x0998dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0998e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0998e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0998e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0696_0x0998dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0998dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c4b0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0697 | PC: 0x0999d4 | FDE: 0x11c4d8 | Size: 36 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16find_restart_bufEv]
// Hàm FDE #0697 | Địa chỉ PC: 0x0999d4 | Địa chỉ FDE: 0x11c4d8 | Kích thước: 36 bytes
//   0x0999d4: F9401408  ldr      x8, [x0, #0x28]
//   0x0999d8: F9400C09  ldr      x9, [x0, #0x18]
//   0x0999dc: EB09011F  cmp      x8, x9
//   0x0999e0: 54000081  b.ne     #0x999f0
static inline uint64_t fde_func_0697_0x0999d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0999d4ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9400c09ULL) ^ 0x11c4d8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0698 | PC: 0x0999f8 | FDE: 0x11c4f0 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE12match_prefixEv]
// Hàm FDE #0698 | Địa chỉ PC: 0x0999f8 | Địa chỉ FDE: 0x11c4f0 | Kích thước: 256 bytes
//   0x0999f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0999fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099a00: 910043FD  add      x29, sp, #0x10
//   0x099a04: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_0698_0x0999f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0999f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c4f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0699 | PC: 0x099b68 | FDE: 0x11c510 | Size: 8 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16find_restart_litEv]
// Hàm FDE #0699 | Địa chỉ PC: 0x099b68 | Địa chỉ FDE: 0x11c510 | Kích thước: 8 bytes
//   0x099b68: 2A1F03E0  mov      w0, wzr
//   0x099b6c: D65F03C0  ret      
static inline uint64_t fde_func_0699_0x099b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099b68ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x11c510ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0700 | PC: 0x099b70 | FDE: 0x11c528 | Size: 256 bytes [_ZN5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE8set_sizeEmS5_S5_]
// Hàm FDE #0700 | Địa chỉ PC: 0x099b70 | Địa chỉ FDE: 0x11c528 | Kích thước: 256 bytes
//   0x099b70: D10143FF  sub      sp, sp, #0x50
//   0x099b74: F90013F5  str      x21, [sp, #0x20]
//   0x099b78: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x099b7c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0700_0x099b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099b70ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x11c528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0701 | PC: 0x099d40 | FDE: 0x11ead8 | Size: 148 bytes [_ZN5boost13re_detail_60014verify_optionsEjNS_15regex_constants12_match_flagsE]
// Hàm FDE #0701 | Địa chỉ PC: 0x099d40 | Địa chỉ FDE: 0x11ead8 | Kích thước: 148 bytes
//   0x099d40: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099d44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099d48: 910043FD  add      x29, sp, #0x10
//   0x099d4c: 2A2103E8  mvn      w8, w1
static inline uint64_t fde_func_0701_0x099d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099d40ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ead8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0702 | PC: 0x099dd4 | FDE: 0x11eb00 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16match_all_statesEv]
// Hàm FDE #0702 | Địa chỉ PC: 0x099dd4 | Địa chỉ FDE: 0x11eb00 | Kích thước: 256 bytes
//   0x099dd4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x099dd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x099ddc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x099de0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0702_0x099dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099dd4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11eb00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0703 | PC: 0x09a014 | FDE: 0x11c548 | Size: 256 bytes [_ZN5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE12maybe_assignERKSA_]
// Hàm FDE #0703 | Địa chỉ PC: 0x09a014 | Địa chỉ FDE: 0x11c548 | Kích thước: 256 bytes
//   0x09a014: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x09a018: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09a01c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09a020: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0703_0x09a014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a014ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11c548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0704 | PC: 0x09a334 | FDE: 0x11eb30 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE15match_startmarkEv]
// Hàm FDE #0704 | Địa chỉ PC: 0x09a334 | Địa chỉ FDE: 0x11eb30 | Kích thước: 256 bytes
//   0x09a334: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x09a338: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09a33c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09a340: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0704_0x09a334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a334ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11eb30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0705 | PC: 0x09a830 | FDE: 0x11c570 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13match_endmarkEv]
// Hàm FDE #0705 | Địa chỉ PC: 0x09a830 | Địa chỉ FDE: 0x11c570 | Kích thước: 256 bytes
//   0x09a830: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x09a834: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09a838: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09a83c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0705_0x09a830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a830ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11c570ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0706 | PC: 0x09aae0 | FDE: 0x11c598 | Size: 168 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13match_literalEv]
// Hàm FDE #0706 | Địa chỉ PC: 0x09aae0 | Địa chỉ FDE: 0x11c598 | Kích thước: 168 bytes
//   0x09aae0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09aae4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09aae8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09aaec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0706_0x09aae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09aae0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c598ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0707 | PC: 0x09ab88 | FDE: 0x11c5b8 | Size: 140 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16match_start_lineEv]
// Hàm FDE #0707 | Địa chỉ PC: 0x09ab88 | Địa chỉ FDE: 0x11c5b8 | Kích thước: 140 bytes
//   0x09ab88: F9401408  ldr      x8, [x0, #0x28]
//   0x09ab8c: F940200A  ldr      x10, [x0, #0x40]
//   0x09ab90: B9406009  ldr      w9, [x0, #0x60]
//   0x09ab94: EB0A011F  cmp      x8, x10
static inline uint64_t fde_func_0707_0x09ab88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ab88ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf940200aULL) ^ 0x11c5b8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0708 | PC: 0x09ac14 | FDE: 0x11c5d0 | Size: 128 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14match_end_lineEv]
// Hàm FDE #0708 | Địa chỉ PC: 0x09ac14 | Địa chỉ FDE: 0x11c5d0 | Kích thước: 128 bytes
//   0x09ac14: A9422408  ldp      x8, x9, [x0, #0x20]
//   0x09ac18: B940600A  ldr      w10, [x0, #0x60]
//   0x09ac1c: EB08013F  cmp      x9, x8
//   0x09ac20: 540002C0  b.eq     #0x9ac78
static inline uint64_t fde_func_0708_0x09ac14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ac14ULL ^ (static_cast<uint64_t>(0xa9422408ULL) << 13);
    acc = (acc + a1 + 0xb940600aULL) ^ 0x11c5d0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0709 | PC: 0x09ac94 | FDE: 0x11c5e8 | Size: 104 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10match_wildEv]
// Hàm FDE #0709 | Địa chỉ PC: 0x09ac94 | Địa chỉ FDE: 0x11c5e8 | Kích thước: 104 bytes
//   0x09ac94: A9422009  ldp      x9, x8, [x0, #0x20]
//   0x09ac98: EB09011F  cmp      x8, x9
//   0x09ac9c: 540002C0  b.eq     #0x9acf4
//   0x09aca0: 39400109  ldrb     w9, [x8]
static inline uint64_t fde_func_0709_0x09ac94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ac94ULL ^ (static_cast<uint64_t>(0xa9422009ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x11c5e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0710 | PC: 0x09acfc | FDE: 0x11c600 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE11match_matchEv]
// Hàm FDE #0710 | Địa chỉ PC: 0x09acfc | Địa chỉ FDE: 0x11c600 | Kích thước: 256 bytes
//   0x09acfc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x09ad00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09ad04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09ad08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0710_0x09acfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09acfcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11c600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0711 | PC: 0x09afc4 | FDE: 0x11c628 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE19match_word_boundaryEv]
// Hàm FDE #0711 | Địa chỉ PC: 0x09afc4 | Địa chỉ FDE: 0x11c628 | Kích thước: 256 bytes
//   0x09afc4: A9422408  ldp      x8, x9, [x0, #0x20]
//   0x09afc8: EB08013F  cmp      x9, x8
//   0x09afcc: 540004E0  b.eq     #0x9b068
//   0x09afd0: 39C0012A  ldrsb    w10, [x9]
static inline uint64_t fde_func_0711_0x09afc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09afc4ULL ^ (static_cast<uint64_t>(0xa9422408ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x11c628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0712 | PC: 0x09b1e4 | FDE: 0x11c640 | Size: 56 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE17match_within_wordEv]
// Hàm FDE #0712 | Địa chỉ PC: 0x09b1e4 | Địa chỉ FDE: 0x11c640 | Kích thước: 56 bytes
//   0x09b1e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b1e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b1ec: 910043FD  add      x29, sp, #0x10
//   0x09b1f0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0712_0x09b1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b1e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c640ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0713 | PC: 0x09b21c | FDE: 0x11c660 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16match_word_startEv]
// Hàm FDE #0713 | Địa chỉ PC: 0x09b21c | Địa chỉ FDE: 0x11c660 | Kích thước: 256 bytes
//   0x09b21c: A9423008  ldp      x8, x12, [x0, #0x20]
//   0x09b220: EB08019F  cmp      x12, x8
//   0x09b224: 540009C0  b.eq     #0x9b35c
//   0x09b228: 39C00188  ldrsb    w8, [x12]
static inline uint64_t fde_func_0713_0x09b21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b21cULL ^ (static_cast<uint64_t>(0xa9423008ULL) << 13);
    acc = (acc + a1 + 0xeb08019fULL) ^ 0x11c660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0714 | PC: 0x09b3e0 | FDE: 0x11c678 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14match_word_endEv]
// Hàm FDE #0714 | Địa chỉ PC: 0x09b3e0 | Địa chỉ FDE: 0x11c678 | Kích thước: 256 bytes
//   0x09b3e0: F940140B  ldr      x11, [x0, #0x28]
//   0x09b3e4: F9402008  ldr      x8, [x0, #0x40]
//   0x09b3e8: EB08017F  cmp      x11, x8
//   0x09b3ec: 54000061  b.ne     #0x9b3f8
static inline uint64_t fde_func_0714_0x09b3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b3e0ULL ^ (static_cast<uint64_t>(0xf940140bULL) << 13);
    acc = (acc + a1 + 0xf9402008ULL) ^ 0x11c678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0715 | PC: 0x09b5a8 | FDE: 0x11c690 | Size: 52 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18match_buffer_startEv]
// Hàm FDE #0715 | Địa chỉ PC: 0x09b5a8 | Địa chỉ FDE: 0x11c690 | Kích thước: 52 bytes
//   0x09b5a8: F9401408  ldr      x8, [x0, #0x28]
//   0x09b5ac: F9402009  ldr      x9, [x0, #0x40]
//   0x09b5b0: EB09011F  cmp      x8, x9
//   0x09b5b4: 54000101  b.ne     #0x9b5d4
static inline uint64_t fde_func_0715_0x09b5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b5a8ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9402009ULL) ^ 0x11c690ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0716 | PC: 0x09b5dc | FDE: 0x11c6a8 | Size: 48 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16match_buffer_endEv]
// Hàm FDE #0716 | Địa chỉ PC: 0x09b5dc | Địa chỉ FDE: 0x11c6a8 | Kích thước: 48 bytes
//   0x09b5dc: A9422408  ldp      x8, x9, [x0, #0x20]
//   0x09b5e0: EB08013F  cmp      x9, x8
//   0x09b5e4: 54000101  b.ne     #0x9b604
//   0x09b5e8: 39418008  ldrb     w8, [x0, #0x60]
static inline uint64_t fde_func_0716_0x09b5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b5dcULL ^ (static_cast<uint64_t>(0xa9422408ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x11c6a8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0717 | PC: 0x09b60c | FDE: 0x11c6c0 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13match_backrefEv]
// Hàm FDE #0717 | Địa chỉ PC: 0x09b60c | Địa chỉ FDE: 0x11c6c0 | Kích thước: 256 bytes
//   0x09b60c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09b610: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b614: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b618: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0717_0x09b60c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b60cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c6c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0718 | PC: 0x09b828 | FDE: 0x11c6e8 | Size: 100 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14match_long_setEv]
// Hàm FDE #0718 | Địa chỉ PC: 0x09b828 | Địa chỉ FDE: 0x11c6e8 | Kích thước: 100 bytes
//   0x09b828: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b82c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b830: 910043FD  add      x29, sp, #0x10
//   0x09b834: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0718_0x09b828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b828ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c6e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0719 | PC: 0x09b88c | FDE: 0x11c708 | Size: 132 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9match_setEv]
// Hàm FDE #0719 | Địa chỉ PC: 0x09b88c | Địa chỉ FDE: 0x11c708 | Kích thước: 132 bytes
//   0x09b88c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09b890: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b894: 910043FD  add      x29, sp, #0x10
//   0x09b898: A9422009  ldp      x9, x8, [x0, #0x20]
static inline uint64_t fde_func_0719_0x09b88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b88cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c708ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0720 | PC: 0x09b910 | FDE: 0x11c728 | Size: 24 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10match_jumpEv]
// Hàm FDE #0720 | Địa chỉ PC: 0x09b910 | Địa chỉ FDE: 0x11c728 | Kích thước: 24 bytes
//   0x09b910: F9402C09  ldr      x9, [x0, #0x58]
//   0x09b914: AA0003E8  mov      x8, x0
//   0x09b918: 52800020  mov      w0, #1
//   0x09b91c: F9400929  ldr      x9, [x9, #0x10]
static inline uint64_t fde_func_0720_0x09b910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b910ULL ^ (static_cast<uint64_t>(0xf9402c09ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11c728ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0721 | PC: 0x09b928 | FDE: 0x11c740 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9match_altEv]
// Hàm FDE #0721 | Địa chỉ PC: 0x09b928 | Địa chỉ FDE: 0x11c740 | Kích thước: 256 bytes
//   0x09b928: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09b92c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b930: 910043FD  add      x29, sp, #0x10
//   0x09b934: A942200A  ldp      x10, x8, [x0, #0x20]
static inline uint64_t fde_func_0721_0x09b928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b928ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0722 | PC: 0x09ba44 | FDE: 0x11c760 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9match_repEv]
// Hàm FDE #0722 | Địa chỉ PC: 0x09ba44 | Địa chỉ FDE: 0x11c760 | Kích thước: 256 bytes
//   0x09ba44: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09ba48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09ba4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09ba50: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0722_0x09ba44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ba44ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0723 | PC: 0x09bd08 | FDE: 0x11c788 | Size: 156 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE15match_combiningEv]
// Hàm FDE #0723 | Địa chỉ PC: 0x09bd08 | Địa chỉ FDE: 0x11c788 | Kích thước: 156 bytes
//   0x09bd08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09bd0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09bd10: 910043FD  add      x29, sp, #0x10
//   0x09bd14: A9422009  ldp      x9, x8, [x0, #0x20]
static inline uint64_t fde_func_0723_0x09bd08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bd08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c788ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0724 | PC: 0x09bda4 | FDE: 0x11c7a8 | Size: 184 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE21match_soft_buffer_endEv]
// Hàm FDE #0724 | Địa chỉ PC: 0x09bda4 | Địa chỉ FDE: 0x11c7a8 | Kích thước: 184 bytes
//   0x09bda4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09bda8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09bdac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09bdb0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0724_0x09bda4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bda4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c7a8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0725 | PC: 0x09be5c | FDE: 0x11c7d0 | Size: 44 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE22match_restart_continueEv]
// Hàm FDE #0725 | Địa chỉ PC: 0x09be5c | Địa chỉ FDE: 0x11c7d0 | Kích thước: 44 bytes
//   0x09be5c: F9401408  ldr      x8, [x0, #0x28]
//   0x09be60: F9401C09  ldr      x9, [x0, #0x38]
//   0x09be64: EB09011F  cmp      x8, x9
//   0x09be68: 54000060  b.eq     #0x9be74
static inline uint64_t fde_func_0725_0x09be5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09be5cULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9401c09ULL) ^ 0x11c7d0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0726 | PC: 0x09be88 | FDE: 0x11c7e8 | Size: 4 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE25match_dot_repeat_dispatchEv]
// Hàm FDE #0726 | Địa chỉ PC: 0x09be88 | Địa chỉ FDE: 0x11c7e8 | Kích thước: 4 bytes
//   0x09be88: 17FEA626  b        #0x45720
static inline uint64_t fde_func_0726_0x09be88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09be88ULL ^ (static_cast<uint64_t>(0x17fea626ULL) << 13);
    acc = (acc + a1 + 0xf81a0ffbULL) ^ 0x11c7e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0727 | PC: 0x09be8c | FDE: 0x11c800 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE17match_char_repeatEv]
// Hàm FDE #0727 | Địa chỉ PC: 0x09be8c | Địa chỉ FDE: 0x11c800 | Kích thước: 256 bytes
//   0x09be8c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x09be90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09be94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09be98: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0727_0x09be8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09be8cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11c800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0728 | PC: 0x09c17c | FDE: 0x11c830 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16match_set_repeatEv]
// Hàm FDE #0728 | Địa chỉ PC: 0x09c17c | Địa chỉ FDE: 0x11c830 | Kích thước: 256 bytes
//   0x09c17c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x09c180: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09c184: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09c188: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0728_0x09c17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c17cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11c830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0729 | PC: 0x09c46c | FDE: 0x11c860 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE21match_long_set_repeatEv]
// Hàm FDE #0729 | Địa chỉ PC: 0x09c46c | Địa chỉ FDE: 0x11c860 | Kích thước: 256 bytes
//   0x09c46c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x09c470: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09c474: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09c478: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0729_0x09c46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c46cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11c860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0730 | PC: 0x09c76c | FDE: 0x11c890 | Size: 64 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE14match_backstepEv]
// Hàm FDE #0730 | Địa chỉ PC: 0x09c76c | Địa chỉ FDE: 0x11c890 | Kích thước: 64 bytes
//   0x09c76c: F9402C08  ldr      x8, [x0, #0x58]
//   0x09c770: F940200B  ldr      x11, [x0, #0x40]
//   0x09c774: F9401409  ldr      x9, [x0, #0x28]
//   0x09c778: B980110A  ldrsw    x10, [x8, #0x10]
static inline uint64_t fde_func_0730_0x09c76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c76cULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf940200bULL) ^ 0x11c890ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0731 | PC: 0x09c7ac | FDE: 0x11c8a8 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE20match_assert_backrefEv]
// Hàm FDE #0731 | Địa chỉ PC: 0x09c7ac | Địa chỉ FDE: 0x11c8a8 | Kích thước: 256 bytes
//   0x09c7ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09c7b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09c7b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09c7b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0731_0x09c7ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c7acULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0732 | PC: 0x09ca88 | FDE: 0x11c8c8 | Size: 212 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE17match_toggle_caseEv]
// Hàm FDE #0732 | Địa chỉ PC: 0x09ca88 | Địa chỉ FDE: 0x11c8c8 | Kích thước: 212 bytes
//   0x09ca88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09ca8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09ca90: 910043FD  add      x29, sp, #0x10
//   0x09ca94: A94D2009  ldp      x9, x8, [x0, #0xd0]
static inline uint64_t fde_func_0732_0x09ca88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ca88ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c8c8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0733 | PC: 0x09cb5c | FDE: 0x11eb60 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE15match_recursionEv]
// Hàm FDE #0733 | Địa chỉ PC: 0x09cb5c | Địa chỉ FDE: 0x11eb60 | Kích thước: 256 bytes
//   0x09cb5c: D10303FF  sub      sp, sp, #0xc0
//   0x09cb60: F90043F7  str      x23, [sp, #0x80]
//   0x09cb64: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x09cb68: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0733_0x09cb5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cb5cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x11eb60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0734 | PC: 0x09cfe8 | FDE: 0x11c8e8 | Size: 8 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10match_failEv]
// Hàm FDE #0734 | Địa chỉ PC: 0x09cfe8 | Địa chỉ FDE: 0x11c8e8 | Kích thước: 8 bytes
//   0x09cfe8: 2A1F03E0  mov      w0, wzr
//   0x09cfec: D65F03C0  ret      
static inline uint64_t fde_func_0734_0x09cfe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cfe8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x11c8e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0735 | PC: 0x09cff0 | FDE: 0x11c900 | Size: 36 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE12match_acceptEv]
// Hàm FDE #0735 | Địa chỉ PC: 0x09cff0 | Địa chỉ FDE: 0x11c900 | Kích thước: 36 bytes
//   0x09cff0: A94BA009  ldp      x9, x8, [x0, #0xb8]
//   0x09cff4: EB08013F  cmp      x9, x8
//   0x09cff8: 54000080  b.eq     #0x9d008
//   0x09cffc: B8590101  ldur     w1, [x8, #-0x70]
static inline uint64_t fde_func_0735_0x09cff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cff0ULL ^ (static_cast<uint64_t>(0xa94ba009ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x11c900ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0736 | PC: 0x09d014 | FDE: 0x11c918 | Size: 252 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE12match_commitEv]
// Hàm FDE #0736 | Địa chỉ PC: 0x09d014 | Địa chỉ FDE: 0x11c918 | Kích thước: 252 bytes
//   0x09d014: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09d018: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d01c: 910043FD  add      x29, sp, #0x10
//   0x09d020: F9402C08  ldr      x8, [x0, #0x58]
static inline uint64_t fde_func_0736_0x09d014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d014ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c918ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0737 | PC: 0x09d110 | FDE: 0x11c938 | Size: 196 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10match_thenEv]
// Hàm FDE #0737 | Địa chỉ PC: 0x09d110 | Địa chỉ FDE: 0x11c938 | Kích thước: 196 bytes
//   0x09d110: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09d114: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d118: 910043FD  add      x29, sp, #0x10
//   0x09d11c: A94D2009  ldp      x9, x8, [x0, #0xd0]
static inline uint64_t fde_func_0737_0x09d110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d110ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11c938ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0738 | PC: 0x09d1d4 | FDE: 0x11eb90 | Size: 256 bytes [_ZN5boost13re_detail_60011raise_errorINS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEEEEvRKT_NS_15regex_constants10error_typeE]
// Hàm FDE #0738 | Địa chỉ PC: 0x09d1d4 | Địa chỉ FDE: 0x11eb90 | Kích thước: 256 bytes
//   0x09d1d4: D101C3FF  sub      sp, sp, #0x70
//   0x09d1d8: F90023F5  str      x21, [sp, #0x40]
//   0x09d1dc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09d1e0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0738_0x09d1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d1d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x11eb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0739 | PC: 0x09d318 | FDE: 0x11c958 | Size: 256 bytes [_ZN5boost13re_detail_60015mem_block_cache3getEv]
// Hàm FDE #0739 | Địa chỉ PC: 0x09d318 | Địa chỉ FDE: 0x11c958 | Kích thước: 256 bytes
//   0x09d318: AA0003E8  mov      x8, x0
//   0x09d31c: C8DFFC00  ldar     x0, [x0]
//   0x09d320: B4000100  cbz      x0, #0x9d340
//   0x09d324: C85FFD09  ldaxr    x9, [x8]
static inline uint64_t fde_func_0739_0x09d318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d318ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xc8dffc00ULL) ^ 0x11c958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0740 | PC: 0x09d5a0 | FDE: 0x11c970 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE19push_repeater_countEiPPNS0_14repeater_countIS6_EE]
// Hàm FDE #0740 | Địa chỉ PC: 0x09d5a0 | Địa chỉ FDE: 0x11c970 | Kích thước: 256 bytes
//   0x09d5a0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09d5a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09d5a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09d5ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0740_0x09d5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d5a0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0741 | PC: 0x09d6cc | FDE: 0x11c998 | Size: 256 bytes [_ZNSt6__ndk16vectorIN5boost9sub_matchINS_11__wrap_iterIPKcEEEENS_9allocatorIS7_EEE6assignIPS7_EENS_9enable_ifIXaasr21__is_forward_iteratorIT_EE5valuesr16is_constructibleIS7_NS_15iterator_traitsISE_E9referenceEEE5valueEvE4typeESE_SE_]
// Hàm FDE #0741 | Địa chỉ PC: 0x09d6cc | Địa chỉ FDE: 0x11c998 | Kích thước: 256 bytes
//   0x09d6cc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09d6d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09d6d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09d6d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0741_0x09d6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d6ccULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0742 | PC: 0x09d884 | FDE: 0x11ebb8 | Size: 256 bytes [_ZN5boost13re_detail_60015saved_recursionINS_13match_resultsINSt6__ndk111__wrap_iterIPKcEENS3_9allocatorINS_9sub_matchIS7_EEEEEEEC2EiPKNS0_14re_syntax_baseEPSC_SH_]
// Hàm FDE #0742 | Địa chỉ PC: 0x09d884 | Địa chỉ FDE: 0x11ebb8 | Kích thước: 256 bytes
//   0x09d884: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09d888: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09d88c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09d890: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0742_0x09d884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d884ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11ebb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0743 | PC: 0x09da14 | FDE: 0x11ebe8 | Size: 224 bytes [_ZNSt6__ndk16vectorIN5boost9sub_matchINS_11__wrap_iterIPKcEEEENS_9allocatorIS7_EEEC2ERKSA_]
// Hàm FDE #0743 | Địa chỉ PC: 0x09da14 | Địa chỉ FDE: 0x11ebe8 | Kích thước: 224 bytes
//   0x09da14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09da18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09da1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09da20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0743_0x09da14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09da14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11ebe8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0744 | PC: 0x09daf4 | FDE: 0x11c9c0 | Size: 132 bytes [_ZN5boost13re_detail_60014repeater_countINSt6__ndk111__wrap_iterIPKcEEE12unwind_untilEiPS7_i]
// Hàm FDE #0744 | Địa chỉ PC: 0x09daf4 | Địa chỉ FDE: 0x11c9c0 | Kích thước: 132 bytes
//   0x09daf4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09daf8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09dafc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09db00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0744_0x09daf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09daf4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c9c0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0745 | PC: 0x09db78 | FDE: 0x11ec10 | Size: 256 bytes [_ZN5boost13re_detail_60016re_is_set_memberINSt6__ndk111__wrap_iterIPKcEEcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEjEET_SB_SB_PKNS0_11re_set_longIT2_EERKNS0_10regex_dataIT0_T1_EEb]
// Hàm FDE #0745 | Địa chỉ PC: 0x09db78 | Địa chỉ FDE: 0x11ec10 | Kích thước: 256 bytes
//   0x09db78: D102C3FF  sub      sp, sp, #0xb0
//   0x09db7c: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x09db80: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x09db84: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0745_0x09db78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09db78ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x11ec10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0746 | PC: 0x09e214 | FDE: 0x11c9e8 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE21match_dot_repeat_fastEv]
// Hàm FDE #0746 | Địa chỉ PC: 0x09e214 | Địa chỉ FDE: 0x11c9e8 | Kích thước: 256 bytes
//   0x09e214: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09e218: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09e21c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09e220: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0746_0x09e214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e214ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11c9e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0747 | PC: 0x09e488 | FDE: 0x11ca10 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE21match_dot_repeat_slowEv]
// Hàm FDE #0747 | Địa chỉ PC: 0x09e488 | Địa chỉ FDE: 0x11ca10 | Kích thước: 256 bytes
//   0x09e488: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09e48c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09e490: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09e494: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0747_0x09e488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e488ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11ca10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0748 | PC: 0x09e774 | FDE: 0x11ec48 | Size: 256 bytes [_ZNSt6__ndk16vectorIN5boost13re_detail_60014recursion_infoINS1_13match_resultsINS_11__wrap_iterIPKcEENS_9allocatorINS1_9sub_matchIS8_EEEEEEEENS9_ISE_EEE7reserveEm]
// Hàm FDE #0748 | Địa chỉ PC: 0x09e774 | Địa chỉ FDE: 0x11ec48 | Kích thước: 256 bytes
//   0x09e774: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x09e778: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09e77c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09e780: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0748_0x09e774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e774ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11ec48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x09e9f8 | FDE: 0x11ec78 | Size: 256 bytes [_ZNSt6__ndk16vectorIN5boost13re_detail_60014recursion_infoINS1_13match_resultsINS_11__wrap_iterIPKcEENS_9allocatorINS1_9sub_matchIS8_EEEEEEEENS9_ISE_EEE21__push_back_slow_pathISE_EEvOT_]
// Hàm FDE #0749 | Địa chỉ PC: 0x09e9f8 | Địa chỉ FDE: 0x11ec78 | Kích thước: 256 bytes
//   0x09e9f8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x09e9fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09ea00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09ea04: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0749_0x09e9f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e9f8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11ec78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0750 | PC: 0x09ed70 | FDE: 0x11ca38 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16skip_until_parenEib]
// Hàm FDE #0750 | Địa chỉ PC: 0x09ed70 | Địa chỉ FDE: 0x11ca38 | Kích thước: 256 bytes
//   0x09ed70: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x09ed74: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09ed78: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09ed7c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0750_0x09ed70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ed70ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11ca38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0751 | PC: 0x09eec8 | FDE: 0x11ecb0 | Size: 160 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE6suffixEv]
// Hàm FDE #0751 | Địa chỉ PC: 0x09eec8 | Địa chỉ FDE: 0x11ecb0 | Kích thước: 160 bytes
//   0x09eec8: D10103FF  sub      sp, sp, #0x40
//   0x09eecc: F90013F3  str      x19, [sp, #0x20]
//   0x09eed0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09eed4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0751_0x09eec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09eec8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11ecb0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0752 | PC: 0x09ef68 | FDE: 0x11ecd8 | Size: 160 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE6prefixEv]
// Hàm FDE #0752 | Địa chỉ PC: 0x09ef68 | Địa chỉ FDE: 0x11ecd8 | Kích thước: 160 bytes
//   0x09ef68: D10103FF  sub      sp, sp, #0x40
//   0x09ef6c: F90013F3  str      x19, [sp, #0x20]
//   0x09ef70: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09ef74: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0752_0x09ef68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ef68ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11ecd8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0753 | PC: 0x09f008 | FDE: 0x11ca60 | Size: 256 bytes [_ZNSt6__ndk16vectorIN5boost9sub_matchINS_11__wrap_iterIPKcEEEENS_9allocatorIS7_EEE6insertENS3_IPKS7_EEmRSB_]
// Hàm FDE #0753 | Địa chỉ PC: 0x09f008 | Địa chỉ FDE: 0x11ca60 | Kích thước: 256 bytes
//   0x09f008: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x09f00c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09f010: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09f014: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0753_0x09f008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f008ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11ca60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0754 | PC: 0x09f364 | FDE: 0x11ed00 | Size: 236 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE6get_atEi]
// Hàm FDE #0754 | Địa chỉ PC: 0x09f364 | Địa chỉ FDE: 0x11ed00 | Kích thước: 236 bytes
//   0x09f364: D10103FF  sub      sp, sp, #0x40
//   0x09f368: F90013F3  str      x19, [sp, #0x20]
//   0x09f36c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09f370: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0754_0x09f364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f364ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11ed00ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0755 | PC: 0x09f450 | FDE: 0x11ed28 | Size: 248 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE13do_get_lengthEi]
// Hàm FDE #0755 | Địa chỉ PC: 0x09f450 | Địa chỉ FDE: 0x11ed28 | Kích thước: 248 bytes
//   0x09f450: D10103FF  sub      sp, sp, #0x40
//   0x09f454: F90013F3  str      x19, [sp, #0x20]
//   0x09f458: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09f45c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0755_0x09f450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f450ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11ed28ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0756 | PC: 0x09f548 | FDE: 0x11ca88 | Size: 12 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10unwind_endEb]
// Hàm FDE #0756 | Địa chỉ PC: 0x09f548 | Địa chỉ FDE: 0x11ca88 | Kích thước: 12 bytes
//   0x09f548: F9002C1F  str      xzr, [x0, #0x58]
//   0x09f54c: 2A1F03E0  mov      w0, wzr
//   0x09f550: D65F03C0  ret      
static inline uint64_t fde_func_0756_0x09f548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f548ULL ^ (static_cast<uint64_t>(0xf9002c1fULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x11ca88ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0757 | PC: 0x09f554 | FDE: 0x11caa0 | Size: 156 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE12unwind_parenEb]
// Hàm FDE #0757 | Địa chỉ PC: 0x09f554 | Địa chỉ FDE: 0x11caa0 | Kích thước: 156 bytes
//   0x09f554: F9406C09  ldr      x9, [x0, #0xd8]
//   0x09f558: AA0003E8  mov      x8, x0
//   0x09f55c: 37000421  tbnz     w1, #0, #0x9f5e0
//   0x09f560: F940090A  ldr      x10, [x8, #0x10]
static inline uint64_t fde_func_0757_0x09f554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f554ULL ^ (static_cast<uint64_t>(0xf9406c09ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11caa0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0758 | PC: 0x09f5f0 | FDE: 0x11cab8 | Size: 24 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE24unwind_recursion_stopperEb]
// Hàm FDE #0758 | Địa chỉ PC: 0x09f5f0 | Địa chỉ FDE: 0x11cab8 | Kích thước: 24 bytes
//   0x09f5f0: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09f5f4: F9002C1F  str      xzr, [x0, #0x58]
//   0x09f5f8: 91002108  add      x8, x8, #8
//   0x09f5fc: F9006C08  str      x8, [x0, #0xd8]
static inline uint64_t fde_func_0758_0x09f5f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f5f0ULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0xf9002c1fULL) ^ 0x11cab8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0759 | PC: 0x09f608 | FDE: 0x11cad0 | Size: 80 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16unwind_assertionEb]
// Hàm FDE #0759 | Địa chỉ PC: 0x09f608 | Địa chỉ FDE: 0x11cad0 | Kích thước: 80 bytes
//   0x09f608: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09f60c: 1200002A  and      w10, w1, #1
//   0x09f610: 5280002B  mov      w11, #1
//   0x09f614: F9400509  ldr      x9, [x8, #8]
static inline uint64_t fde_func_0759_0x09f608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f608ULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0x1200002aULL) ^ 0x11cad0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0760 | PC: 0x09f658 | FDE: 0x11cae8 | Size: 56 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE10unwind_altEb]
// Hàm FDE #0760 | Địa chỉ PC: 0x09f658 | Địa chỉ FDE: 0x11cae8 | Kích thước: 56 bytes
//   0x09f658: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09f65c: 370000A1  tbnz     w1, #0, #0x9f670
//   0x09f660: F9400509  ldr      x9, [x8, #8]
//   0x09f664: F9002C09  str      x9, [x0, #0x58]
static inline uint64_t fde_func_0760_0x09f658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f658ULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0x370000a1ULL) ^ 0x11cae8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0761 | PC: 0x09f690 | FDE: 0x11cb00 | Size: 40 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE23unwind_repeater_counterEb]
// Hàm FDE #0761 | Địa chỉ PC: 0x09f690 | Địa chỉ FDE: 0x11cb00 | Kích thước: 40 bytes
//   0x09f690: F9406C09  ldr      x9, [x0, #0xd8]
//   0x09f694: AA0003E8  mov      x8, x0
//   0x09f698: F940092A  ldr      x10, [x9, #0x10]
//   0x09f69c: B400006A  cbz      x10, #0x9f6a8
static inline uint64_t fde_func_0761_0x09f690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f690ULL ^ (static_cast<uint64_t>(0xf9406c09ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11cb00ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0762 | PC: 0x09f6b8 | FDE: 0x11cb18 | Size: 124 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18unwind_extra_blockEb]
// Hàm FDE #0762 | Địa chỉ PC: 0x09f6b8 | Địa chỉ FDE: 0x11cb18 | Kích thước: 124 bytes
//   0x09f6b8: D10083FF  sub      sp, sp, #0x20
//   0x09f6bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09f6c0: 910043FD  add      x29, sp, #0x10
//   0x09f6c4: B940E008  ldr      w8, [x0, #0xe0]
static inline uint64_t fde_func_0762_0x09f6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f6b8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11cb18ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0763 | PC: 0x09f734 | FDE: 0x11cb38 | Size: 184 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE27unwind_greedy_single_repeatEb]
// Hàm FDE #0763 | Địa chỉ PC: 0x09f734 | Địa chỉ FDE: 0x11cb38 | Kích thước: 184 bytes
//   0x09f734: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09f738: 360000C1  tbz      w1, #0, #0x9f750
//   0x09f73c: 91008108  add      x8, x8, #0x20
//   0x09f740: F9006C08  str      x8, [x0, #0xd8]
static inline uint64_t fde_func_0763_0x09f734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f734ULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0x360000c1ULL) ^ 0x11cb38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0764 | PC: 0x09f7ec | FDE: 0x11cb50 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE22unwind_slow_dot_repeatEb]
// Hàm FDE #0764 | Địa chỉ PC: 0x09f7ec | Địa chỉ FDE: 0x11cb50 | Kích thước: 256 bytes
//   0x09f7ec: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09f7f0: 360000C1  tbz      w1, #0, #0x9f808
//   0x09f7f4: 91008108  add      x8, x8, #0x20
//   0x09f7f8: F9006C08  str      x8, [x0, #0xd8]
static inline uint64_t fde_func_0764_0x09f7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f7ecULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0x360000c1ULL) ^ 0x11cb50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0765 | PC: 0x09f940 | FDE: 0x11cb68 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE22unwind_fast_dot_repeatEb]
// Hàm FDE #0765 | Địa chỉ PC: 0x09f940 | Địa chỉ FDE: 0x11cb68 | Kích thước: 256 bytes
//   0x09f940: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09f944: 360000C1  tbz      w1, #0, #0x9f95c
//   0x09f948: 91008108  add      x8, x8, #0x20
//   0x09f94c: F9006C08  str      x8, [x0, #0xd8]
static inline uint64_t fde_func_0765_0x09f940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f940ULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0x360000c1ULL) ^ 0x11cb68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0766 | PC: 0x09fa54 | FDE: 0x11cb80 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE18unwind_char_repeatEb]
// Hàm FDE #0766 | Địa chỉ PC: 0x09fa54 | Địa chỉ FDE: 0x11cb80 | Kích thước: 256 bytes
//   0x09fa54: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x09fa58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09fa5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09fa60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0766_0x09fa54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fa54ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cb80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0767 | PC: 0x09fbe8 | FDE: 0x11cba8 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE23unwind_short_set_repeatEb]
// Hàm FDE #0767 | Địa chỉ PC: 0x09fbe8 | Địa chỉ FDE: 0x11cba8 | Kích thước: 256 bytes
//   0x09fbe8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x09fbec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09fbf0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09fbf4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0767_0x09fbe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fbe8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0768 | PC: 0x09fd80 | FDE: 0x11cbd0 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE22unwind_long_set_repeatEb]
// Hàm FDE #0768 | Địa chỉ PC: 0x09fd80 | Địa chỉ FDE: 0x11cbd0 | Kích thước: 256 bytes
//   0x09fd80: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x09fd84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09fd88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09fd8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0768_0x09fd80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fd80ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cbd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0769 | PC: 0x09fefc | FDE: 0x11cbf8 | Size: 60 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE24unwind_non_greedy_repeatEb]
// Hàm FDE #0769 | Địa chỉ PC: 0x09fefc | Địa chỉ FDE: 0x11cbf8 | Kích thước: 60 bytes
//   0x09fefc: F9406C08  ldr      x8, [x0, #0xd8]
//   0x09ff00: 37000121  tbnz     w1, #0, #0x9ff24
//   0x09ff04: F9400909  ldr      x9, [x8, #0x10]
//   0x09ff08: F940400A  ldr      x10, [x0, #0x80]
static inline uint64_t fde_func_0769_0x09fefc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fefcULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0x37000121ULL) ^ 0x11cbf8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0770 | PC: 0x09ff38 | FDE: 0x11ed50 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE16unwind_recursionEb]
// Hàm FDE #0770 | Địa chỉ PC: 0x09ff38 | Địa chỉ FDE: 0x11ed50 | Kích thước: 256 bytes
//   0x09ff38: D10303FF  sub      sp, sp, #0xc0
//   0x09ff3c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x09ff40: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x09ff44: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0770_0x09ff38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ff38ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x11ed50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0771 | PC: 0x0a040c | FDE: 0x11cc10 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE20unwind_recursion_popEb]
// Hàm FDE #0771 | Địa chỉ PC: 0x0a040c | Địa chỉ FDE: 0x11cc10 | Kích thước: 256 bytes
//   0x0a040c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a0410: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a0414: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0418: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0771_0x0a040c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a040cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cc10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0772 | PC: 0x0a0570 | FDE: 0x11cc38 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE13unwind_commitEb]
// Hàm FDE #0772 | Địa chỉ PC: 0x0a0570 | Địa chỉ FDE: 0x11cc38 | Kích thước: 256 bytes
//   0x0a0570: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a0574: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a0578: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a057c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0772_0x0a0570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0570ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11cc38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0773 | PC: 0x0a06ac | FDE: 0x11cc58 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE11unwind_thenEb]
// Hàm FDE #0773 | Địa chỉ PC: 0x0a06ac | Địa chỉ FDE: 0x11cc58 | Kích thước: 256 bytes
//   0x0a06ac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a06b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a06b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a06b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0773_0x0a06ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a06acULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0774 | PC: 0x0a07d0 | FDE: 0x11cc80 | Size: 32 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE11unwind_caseEb]
// Hàm FDE #0774 | Địa chỉ PC: 0x0a07d0 | Địa chỉ FDE: 0x11cc80 | Kích thước: 32 bytes
//   0x0a07d0: F9406C09  ldr      x9, [x0, #0xd8]
//   0x0a07d4: AA0003E8  mov      x8, x0
//   0x0a07d8: 3940212A  ldrb     w10, [x9, #8]
//   0x0a07dc: 91004129  add      x9, x9, #0x10
static inline uint64_t fde_func_0774_0x0a07d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a07d0ULL ^ (static_cast<uint64_t>(0xf9406c09ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11cc80ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0775 | PC: 0x0a07f0 | FDE: 0x11cc98 | Size: 256 bytes [_ZN5boost13re_detail_60015mem_block_cache3putEPv]
// Hàm FDE #0775 | Địa chỉ PC: 0x0a07f0 | Địa chỉ FDE: 0x11cc98 | Kích thước: 256 bytes
//   0x0a07f0: C8DFFC08  ldar     x8, [x0]
//   0x0a07f4: B50000E8  cbnz     x8, #0xa0810
//   0x0a07f8: 14000003  b        #0xa0804
//   0x0a07fc: C808FC01  stlxr    w8, x1, [x0]
static inline uint64_t fde_func_0775_0x0a07f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a07f0ULL ^ (static_cast<uint64_t>(0xc8dffc08ULL) << 13);
    acc = (acc + a1 + 0xb50000e8ULL) ^ 0x11cc98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0776 | PC: 0x0a0a3c | FDE: 0x11ccb0 | Size: 152 bytes [_ZN11fast_engine16BoostMatchResultD2Ev]
// Hàm FDE #0776 | Địa chỉ PC: 0x0a0a3c | Địa chỉ FDE: 0x11ccb0 | Kích thước: 152 bytes
//   0x0a0a3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a0a40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0a44: 910043FD  add      x29, sp, #0x10
//   0x0a0a48: F00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0776_0x0a0a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0a3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ccb0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0777 | PC: 0x0a0ad4 | FDE: 0x11ccd0 | Size: 152 bytes [_ZN11fast_engine16BoostMatchResultD0Ev]
// Hàm FDE #0777 | Địa chỉ PC: 0x0a0ad4 | Địa chỉ FDE: 0x11ccd0 | Kích thước: 152 bytes
//   0x0a0ad4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a0ad8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0adc: 910043FD  add      x29, sp, #0x10
//   0x0a0ae0: F00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0777_0x0a0ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0ad4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ccd0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0778 | PC: 0x0a0b6c | FDE: 0x11ccf0 | Size: 36 bytes [_ZNK11fast_engine16BoostMatchResult4sizeEv]
// Hàm FDE #0778 | Địa chỉ PC: 0x0a0b6c | Địa chỉ FDE: 0x11ccf0 | Kích thước: 36 bytes
//   0x0a0b6c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0a0b70: CB080128  sub      x8, x9, x8
//   0x0a0b74: B201F3E9  mov      x9, #-0x5555555555555556
//   0x0a0b78: 9343FD08  asr      x8, x8, #3
static inline uint64_t fde_func_0778_0x0a0b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0b6cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xcb080128ULL) ^ 0x11ccf0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0779 | PC: 0x0a0b90 | FDE: 0x11cd08 | Size: 8 bytes [_ZNK11fast_engine16BoostMatchResult3strEm]
// Hàm FDE #0779 | Địa chỉ PC: 0x0a0b90 | Địa chỉ FDE: 0x11cd08 | Kích thước: 8 bytes
//   0x0a0b90: 91002000  add      x0, x0, #8
//   0x0a0b94: 17FE8A8B  b        #0x435c0
static inline uint64_t fde_func_0779_0x0a0b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0b90ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17fe8a8bULL) ^ 0x11cd08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0780 | PC: 0x0a0b98 | FDE: 0x11cd20 | Size: 8 bytes [_ZNK11fast_engine16BoostMatchResult8positionEm]
// Hàm FDE #0780 | Địa chỉ PC: 0x0a0b98 | Địa chỉ FDE: 0x11cd20 | Kích thước: 8 bytes
//   0x0a0b98: 91002000  add      x0, x0, #8
//   0x0a0b9c: 17FE864D  b        #0x424d0
static inline uint64_t fde_func_0780_0x0a0b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0b98ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17fe864dULL) ^ 0x11cd20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0781 | PC: 0x0a0ba0 | FDE: 0x11cd38 | Size: 8 bytes [_ZNK11fast_engine16BoostMatchResult6lengthEm]
// Hàm FDE #0781 | Địa chỉ PC: 0x0a0ba0 | Địa chỉ FDE: 0x11cd38 | Kích thước: 8 bytes
//   0x0a0ba0: 91002000  add      x0, x0, #8
//   0x0a0ba4: 17FE8FF3  b        #0x44b70
static inline uint64_t fde_func_0781_0x0a0ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0ba0ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17fe8ff3ULL) ^ 0x11cd38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0782 | PC: 0x0a0ba8 | FDE: 0x11cd50 | Size: 28 bytes [_ZNK11fast_engine16BoostMatchResult7matchedEm]
// Hàm FDE #0782 | Địa chỉ PC: 0x0a0ba8 | Địa chỉ FDE: 0x11cd50 | Kích thước: 28 bytes
//   0x0a0ba8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a0bac: 910003FD  mov      x29, sp
//   0x0a0bb0: 91002000  add      x0, x0, #8
//   0x0a0bb4: 97FE9167  bl       #0x45150
static inline uint64_t fde_func_0782_0x0a0ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0ba8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11cd50ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0783 | PC: 0x0a0bc4 | FDE: 0x11ed80 | Size: 256 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE13do_get_stringEi]
// Hàm FDE #0783 | Địa chỉ PC: 0x0a0bc4 | Địa chỉ FDE: 0x11ed80 | Kích thước: 256 bytes
//   0x0a0bc4: D10103FF  sub      sp, sp, #0x40
//   0x0a0bc8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0bcc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a0bd0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0783_0x0a0bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0bc4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x11ed80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x0a0ccc | FDE: 0x11eda8 | Size: 148 bytes [_ZNK5boost9sub_matchINSt6__ndk111__wrap_iterIPKcEEE3strEv]
// Hàm FDE #0784 | Địa chỉ PC: 0x0a0ccc | Địa chỉ FDE: 0x11eda8 | Kích thước: 148 bytes
//   0x0a0ccc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a0cd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a0cd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a0cd8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0784_0x0a0ccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0cccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11eda8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0785 | PC: 0x0a0d60 | FDE: 0x11edd0 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE7__parseINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0785 | Địa chỉ PC: 0x0a0d60 | Địa chỉ FDE: 0x11edd0 | Kích thước: 256 bytes
//   0x0a0d60: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a0d64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a0d68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0d6c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0785_0x0a0d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0d60ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11edd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0786 | PC: 0x0a0f3c | FDE: 0x11cd70 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE16__parse_ecma_expINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0786 | Địa chỉ PC: 0x0a0f3c | Địa chỉ FDE: 0x11cd70 | Kích thước: 256 bytes
//   0x0a0f3c: D101C3FF  sub      sp, sp, #0x70
//   0x0a0f40: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0a0f44: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0a0f48: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0786_0x0a0f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0f3cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x11cd70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0787 | PC: 0x0a1198 | FDE: 0x11cda0 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE21__parse_basic_reg_expINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0787 | Địa chỉ PC: 0x0a1198 | Địa chỉ FDE: 0x11cda0 | Kích thước: 256 bytes
//   0x0a1198: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a119c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a11a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a11a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0787_0x0a1198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1198ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cda0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0788 | PC: 0x0a12ec | FDE: 0x11cdc8 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE24__parse_extended_reg_expINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0788 | Địa chỉ PC: 0x0a12ec | Địa chỉ FDE: 0x11cdc8 | Kích thước: 256 bytes
//   0x0a12ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a12f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a12f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a12f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0788_0x0a12ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a12ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11cdc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0789 | PC: 0x0a146c | FDE: 0x11cdf8 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE12__parse_grepINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0789 | Địa chỉ PC: 0x0a146c | Địa chỉ FDE: 0x11cdf8 | Kích thước: 256 bytes
//   0x0a146c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a1470: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a1474: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a1478: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0789_0x0a146c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a146cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11cdf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x0a1670 | FDE: 0x11ce28 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE13__parse_egrepINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0790 | Địa chỉ PC: 0x0a1670 | Địa chỉ FDE: 0x11ce28 | Kích thước: 256 bytes
//   0x0a1670: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a1674: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a1678: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a167c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0790_0x0a1670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1670ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11ce28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0791 | PC: 0x0a1874 | FDE: 0x11ee00 | Size: 76 bytes
// Hàm FDE #0791 | Địa chỉ PC: 0x0a1874 | Địa chỉ FDE: 0x11ee00 | Kích thước: 76 bytes
//   0x0a1874: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a1878: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a187c: 910043FD  add      x29, sp, #0x10
//   0x0a1880: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0791_0x0a1874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1874ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ee00ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0792 | PC: 0x0a18c0 | FDE: 0x11ce58 | Size: 4 bytes [_ZNSt6__ndk111__end_stateIcED0Ev]
// Hàm FDE #0792 | Địa chỉ PC: 0x0a18c0 | Địa chỉ FDE: 0x11ce58 | Kích thước: 4 bytes
//   0x0a18c0: 17FE8348  b        #0x425e0
static inline uint64_t fde_func_0792_0x0a18c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18c0ULL ^ (static_cast<uint64_t>(0x17fe8348ULL) << 13);
    acc = (acc + a1 + 0x12807ce8ULL) ^ 0x11ce58ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0793 | PC: 0x0a18c4 | FDE: 0x11ce70 | Size: 12 bytes [_ZNKSt6__ndk111__end_stateIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0793 | Địa chỉ PC: 0x0a18c4 | Địa chỉ FDE: 0x11ce70 | Kích thước: 12 bytes
//   0x0a18c4: 12807CE8  mov      w8, #-0x3e8
//   0x0a18c8: B9000028  str      w8, [x1]
//   0x0a18cc: D65F03C0  ret      
static inline uint64_t fde_func_0793_0x0a18c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18c4ULL ^ (static_cast<uint64_t>(0x12807ce8ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11ce70ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0794 | PC: 0x0a18d0 | FDE: 0x11ce88 | Size: 4 bytes
// Hàm FDE #0794 | Địa chỉ PC: 0x0a18d0 | Địa chỉ FDE: 0x11ce88 | Kích thước: 4 bytes
//   0x0a18d0: D65F03C0  ret      
static inline uint64_t fde_func_0794_0x0a18d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18d0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x11ce88ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0795 | PC: 0x0a18d4 | FDE: 0x11cea0 | Size: 4 bytes
// Hàm FDE #0795 | Địa chỉ PC: 0x0a18d4 | Địa chỉ FDE: 0x11cea0 | Kích thước: 4 bytes
//   0x0a18d4: D65F03C0  ret      
static inline uint64_t fde_func_0795_0x0a18d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18d4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x11cea0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0796 | PC: 0x0a18d8 | FDE: 0x11ceb8 | Size: 36 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPNS_13__empty_stateIcEENS_14default_deleteIS2_EENS_9allocatorIS2_EEED0Ev]
// Hàm FDE #0796 | Địa chỉ PC: 0x0a18d8 | Địa chỉ FDE: 0x11ceb8 | Kích thước: 36 bytes
//   0x0a18d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a18dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a18e0: 910043FD  add      x29, sp, #0x10
//   0x0a18e4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0796_0x0a18d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ceb8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0797 | PC: 0x0a18fc | FDE: 0x11ced8 | Size: 24 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPNS_13__empty_stateIcEENS_14default_deleteIS2_EENS_9allocatorIS2_EEE16__on_zero_sharedEv]
// Hàm FDE #0797 | Địa chỉ PC: 0x0a18fc | Địa chỉ FDE: 0x11ced8 | Kích thước: 24 bytes
//   0x0a18fc: F9400C00  ldr      x0, [x0, #0x18]
//   0x0a1900: B4000080  cbz      x0, #0xa1910
//   0x0a1904: F9400008  ldr      x8, [x0]
//   0x0a1908: F9400501  ldr      x1, [x8, #8]
static inline uint64_t fde_func_0797_0x0a18fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a18fcULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x11ced8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0798 | PC: 0x0a1914 | FDE: 0x11cef0 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPNS_13__empty_stateIcEENS_14default_deleteIS2_EENS_9allocatorIS2_EEE21__on_zero_shared_weakEv]
// Hàm FDE #0798 | Địa chỉ PC: 0x0a1914 | Địa chỉ FDE: 0x11cef0 | Kích thước: 4 bytes
//   0x0a1914: 17FE8333  b        #0x425e0
static inline uint64_t fde_func_0798_0x0a1914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1914ULL ^ (static_cast<uint64_t>(0x17fe8333ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x11cef0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0799 | PC: 0x0a1918 | FDE: 0x11cf08 | Size: 68 bytes [_ZNSt6__ndk113__empty_stateIcED0Ev]
// Hàm FDE #0799 | Địa chỉ PC: 0x0a1918 | Địa chỉ FDE: 0x11cf08 | Kích thước: 68 bytes
//   0x0a1918: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a191c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a1920: 910043FD  add      x29, sp, #0x10
//   0x0a1924: D00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0799_0x0a1918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1918ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11cf08ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0800 | PC: 0x0a195c | FDE: 0x11cf28 | Size: 20 bytes [_ZNKSt6__ndk113__empty_stateIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0800 | Địa chỉ PC: 0x0a195c | Địa chỉ FDE: 0x11cf28 | Kích thước: 20 bytes
//   0x0a195c: 12807C28  mov      w8, #-0x3e2
//   0x0a1960: B9000028  str      w8, [x1]
//   0x0a1964: F9400408  ldr      x8, [x0, #8]
//   0x0a1968: F9002828  str      x8, [x1, #0x50]
static inline uint64_t fde_func_0800_0x0a195c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a195cULL ^ (static_cast<uint64_t>(0x12807c28ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11cf28ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0801 | PC: 0x0a1970 | FDE: 0x11cf40 | Size: 68 bytes [_ZNSt6__ndk116__owns_one_stateIcED0Ev]
// Hàm FDE #0801 | Địa chỉ PC: 0x0a1970 | Địa chỉ FDE: 0x11cf40 | Kích thước: 68 bytes
//   0x0a1970: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a1974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a1978: 910043FD  add      x29, sp, #0x10
//   0x0a197c: D00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0801_0x0a1970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1970ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11cf40ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0802 | PC: 0x0a19b4 | FDE: 0x11ee28 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE17__parse_assertionINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0802 | Địa chỉ PC: 0x0a19b4 | Địa chỉ FDE: 0x11ee28 | Kích thước: 256 bytes
//   0x0a19b4: D102C3FF  sub      sp, sp, #0xb0
//   0x0a19b8: F9002BFB  str      x27, [sp, #0x50]
//   0x0a19bc: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0a19c0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0802_0x0a19b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a19b4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x11ee28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0803 | PC: 0x0a1ea8 | FDE: 0x11cf60 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE12__parse_atomINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0803 | Địa chỉ PC: 0x0a1ea8 | Địa chỉ FDE: 0x11cf60 | Kích thước: 256 bytes
//   0x0a1ea8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a1eac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a1eb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a1eb4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0803_0x0a1ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1ea8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11cf60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0804 | PC: 0x0a213c | FDE: 0x11cf88 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE23__parse_ERE_dupl_symbolINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_16__owns_one_stateIcEEjj]
// Hàm FDE #0804 | Địa chỉ PC: 0x0a213c | Địa chỉ FDE: 0x11cf88 | Kích thước: 256 bytes
//   0x0a213c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a2140: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2144: 910043FD  add      x29, sp, #0x10
//   0x0a2148: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0804_0x0a213c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a213cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11cf88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0805 | PC: 0x0a24e0 | FDE: 0x11ee60 | Size: 76 bytes
// Hàm FDE #0805 | Địa chỉ PC: 0x0a24e0 | Địa chỉ FDE: 0x11ee60 | Kích thước: 76 bytes
//   0x0a24e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a24e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a24e8: 910043FD  add      x29, sp, #0x10
//   0x0a24ec: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0805_0x0a24e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a24e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ee60ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0806 | PC: 0x0a252c | FDE: 0x11cfa8 | Size: 68 bytes [_ZNSt6__ndk110__l_anchorIcED0Ev]
// Hàm FDE #0806 | Địa chỉ PC: 0x0a252c | Địa chỉ FDE: 0x11cfa8 | Kích thước: 68 bytes
//   0x0a252c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a2530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2534: 910043FD  add      x29, sp, #0x10
//   0x0a2538: B00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0806_0x0a252c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a252cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11cfa8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0807 | PC: 0x0a2570 | FDE: 0x11cfc8 | Size: 64 bytes [_ZNKSt6__ndk110__l_anchorIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0807 | Địa chỉ PC: 0x0a2570 | Địa chỉ FDE: 0x11cfc8 | Kích thước: 64 bytes
//   0x0a2570: 39417028  ldrb     w8, [x1, #0x5c]
//   0x0a2574: 34000168  cbz      w8, #0xa25a0
//   0x0a2578: A940A428  ldp      x8, x9, [x1, #8]
//   0x0a257c: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_0807_0x0a2570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2570ULL ^ (static_cast<uint64_t>(0x39417028ULL) << 13);
    acc = (acc + a1 + 0x34000168ULL) ^ 0x11cfc8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0808 | PC: 0x0a25b0 | FDE: 0x11cfe0 | Size: 68 bytes [_ZNSt6__ndk110__r_anchorIcED0Ev]
// Hàm FDE #0808 | Địa chỉ PC: 0x0a25b0 | Địa chỉ FDE: 0x11cfe0 | Kích thước: 68 bytes
//   0x0a25b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a25b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a25b8: 910043FD  add      x29, sp, #0x10
//   0x0a25bc: B00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0808_0x0a25b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a25b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11cfe0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0809 | PC: 0x0a25f4 | FDE: 0x11d000 | Size: 56 bytes [_ZNKSt6__ndk110__r_anchorIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0809 | Địa chỉ PC: 0x0a25f4 | Địa chỉ FDE: 0x11d000 | Kích thước: 56 bytes
//   0x0a25f4: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x0a25f8: EB09011F  cmp      x8, x9
//   0x0a25fc: 54000101  b.ne     #0xa261c
//   0x0a2600: 39416028  ldrb     w8, [x1, #0x58]
static inline uint64_t fde_func_0809_0x0a25f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a25f4ULL ^ (static_cast<uint64_t>(0xa9412428ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x11d000ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0810 | PC: 0x0a262c | FDE: 0x11d018 | Size: 92 bytes [_ZNSt6__ndk115__word_boundaryIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0810 | Địa chỉ PC: 0x0a262c | Địa chỉ FDE: 0x11d018 | Kích thước: 92 bytes
//   0x0a262c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a2630: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2634: 910043FD  add      x29, sp, #0x10
//   0x0a2638: B00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0810_0x0a262c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a262cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d018ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0811 | PC: 0x0a2688 | FDE: 0x11d038 | Size: 88 bytes [_ZNSt6__ndk115__word_boundaryIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0811 | Địa chỉ PC: 0x0a2688 | Địa chỉ FDE: 0x11d038 | Kích thước: 88 bytes
//   0x0a2688: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a268c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2690: 910043FD  add      x29, sp, #0x10
//   0x0a2694: B00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0811_0x0a2688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2688ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d038ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0812 | PC: 0x0a26e0 | FDE: 0x11d058 | Size: 256 bytes [_ZNKSt6__ndk115__word_boundaryIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0812 | Địa chỉ PC: 0x0a26e0 | Địa chỉ FDE: 0x11d058 | Kích thước: 256 bytes
//   0x0a26e0: F9400428  ldr      x8, [x1, #8]
//   0x0a26e4: F9400C2A  ldr      x10, [x1, #0x18]
//   0x0a26e8: EB0A011F  cmp      x8, x10
//   0x0a26ec: 54000640  b.eq     #0xa27b4
static inline uint64_t fde_func_0812_0x0a26e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a26e0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xf9400c2aULL) ^ 0x11d058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0813 | PC: 0x0a2800 | FDE: 0x11d070 | Size: 152 bytes [_ZNSt6__ndk111__lookaheadIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0813 | Địa chỉ PC: 0x0a2800 | Địa chỉ FDE: 0x11d070 | Kích thước: 152 bytes
//   0x0a2800: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a2804: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2808: 910043FD  add      x29, sp, #0x10
//   0x0a280c: B00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0813_0x0a2800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2800ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d070ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0814 | PC: 0x0a2898 | FDE: 0x11d090 | Size: 148 bytes [_ZNSt6__ndk111__lookaheadIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0814 | Địa chỉ PC: 0x0a2898 | Địa chỉ FDE: 0x11d090 | Kích thước: 148 bytes
//   0x0a2898: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a289c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a28a0: 910043FD  add      x29, sp, #0x10
//   0x0a28a4: B00004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0814_0x0a2898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2898ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d090ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0815 | PC: 0x0a292c | FDE: 0x11ee88 | Size: 256 bytes [_ZNKSt6__ndk111__lookaheadIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0815 | Địa chỉ PC: 0x0a292c | Địa chỉ FDE: 0x11ee88 | Kích thước: 256 bytes
//   0x0a292c: D102C3FF  sub      sp, sp, #0xb0
//   0x0a2930: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0a2934: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x0a2938: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0815_0x0a292c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a292cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x11ee88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0816 | PC: 0x0a2b0c | FDE: 0x11eeb8 | Size: 256 bytes [_ZNKSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE21__match_at_start_ecmaINS_9allocatorINS_9sub_matchIPKcEEEEEEbS8_S8_RNS_13match_resultsIS8_T_EENS_15regex_constants15match_flag_typeEb]
// Hàm FDE #0816 | Địa chỉ PC: 0x0a2b0c | Địa chỉ FDE: 0x11eeb8 | Kích thước: 256 bytes
//   0x0a2b0c: D104C3FF  sub      sp, sp, #0x130
//   0x0a2b10: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0a2b14: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0a2b18: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0816_0x0a2b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2b0cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x11eeb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0817 | PC: 0x0a3240 | FDE: 0x11d0b0 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_9sub_matchIPKcEENS_9allocatorIS4_EEE6assignEmRKS4_]
// Hàm FDE #0817 | Địa chỉ PC: 0x0a3240 | Địa chỉ FDE: 0x11d0b0 | Kích thước: 256 bytes
//   0x0a3240: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a3244: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a3248: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a324c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0817_0x0a3240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3240ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d0b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0818 | PC: 0x0a3414 | FDE: 0x11eef0 | Size: 76 bytes
// Hàm FDE #0818 | Địa chỉ PC: 0x0a3414 | Địa chỉ FDE: 0x11eef0 | Kích thước: 76 bytes
//   0x0a3414: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3418: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a341c: 910043FD  add      x29, sp, #0x10
//   0x0a3420: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0818_0x0a3414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3414ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11eef0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0819 | PC: 0x0a3460 | FDE: 0x11ef18 | Size: 76 bytes
// Hàm FDE #0819 | Địa chỉ PC: 0x0a3460 | Địa chỉ FDE: 0x11ef18 | Kích thước: 76 bytes
//   0x0a3460: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3464: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3468: 910043FD  add      x29, sp, #0x10
//   0x0a346c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0819_0x0a3460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3460ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ef18ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0820 | PC: 0x0a34ac | FDE: 0x11d0d8 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_7__stateIcEENS_9allocatorIS2_EEE21__push_back_slow_pathIS2_EEvOT_]
// Hàm FDE #0820 | Địa chỉ PC: 0x0a34ac | Địa chỉ FDE: 0x11d0d8 | Kích thước: 256 bytes
//   0x0a34ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a34b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a34b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a34b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0820_0x0a34ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a34acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d0d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0821 | PC: 0x0a36c4 | FDE: 0x11d100 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_9sub_matchIPKcEENS_9allocatorIS4_EEE8__appendEmRKS4_]
// Hàm FDE #0821 | Địa chỉ PC: 0x0a36c4 | Địa chỉ FDE: 0x11d100 | Kích thước: 256 bytes
//   0x0a36c4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a36c8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a36cc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a36d0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0821_0x0a36c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a36c4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0822 | PC: 0x0a3888 | FDE: 0x11d128 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_4pairImPKcEENS_9allocatorIS4_EEE8__appendEm]
// Hàm FDE #0822 | Địa chỉ PC: 0x0a3888 | Địa chỉ FDE: 0x11d128 | Kích thước: 256 bytes
//   0x0a3888: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a388c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a3890: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a3894: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0822_0x0a3888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3888ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0823 | PC: 0x0a39f0 | FDE: 0x11ef40 | Size: 232 bytes [_ZNSt6__ndk16vectorINS_9sub_matchIPKcEENS_9allocatorIS4_EEEC2ERKS7_]
// Hàm FDE #0823 | Địa chỉ PC: 0x0a39f0 | Địa chỉ FDE: 0x11ef40 | Kích thước: 232 bytes
//   0x0a39f0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a39f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a39f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a39fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0823_0x0a39f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a39f0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11ef40ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0824 | PC: 0x0a3ad8 | FDE: 0x11ef70 | Size: 188 bytes [_ZNSt6__ndk16vectorINS_4pairImPKcEENS_9allocatorIS4_EEEC2ERKS7_]
// Hàm FDE #0824 | Địa chỉ PC: 0x0a3ad8 | Địa chỉ FDE: 0x11ef70 | Kích thước: 188 bytes
//   0x0a3ad8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a3adc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a3ae0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a3ae4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0824_0x0a3ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3ad8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11ef70ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0825 | PC: 0x0a3b94 | FDE: 0x11efa0 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE26__parse_bracket_expressionINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0825 | Địa chỉ PC: 0x0a3b94 | Địa chỉ FDE: 0x11efa0 | Kích thước: 256 bytes
//   0x0a3b94: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a3b98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a3b9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a3ba0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0825_0x0a3b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3b94ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11efa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0826 | PC: 0x0a3ce8 | FDE: 0x11efd0 | Size: 76 bytes
// Hàm FDE #0826 | Địa chỉ PC: 0x0a3ce8 | Địa chỉ FDE: 0x11efd0 | Kích thước: 76 bytes
//   0x0a3ce8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3cec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3cf0: 910043FD  add      x29, sp, #0x10
//   0x0a3cf4: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0826_0x0a3ce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3ce8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11efd0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0827 | PC: 0x0a3d34 | FDE: 0x11d150 | Size: 92 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE25__parse_pattern_characterINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0827 | Địa chỉ PC: 0x0a3d34 | Địa chỉ FDE: 0x11d150 | Kích thước: 92 bytes
//   0x0a3d34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a3d38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3d3c: 910043FD  add      x29, sp, #0x10
//   0x0a3d40: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0827_0x0a3d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3d34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d150ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0828 | PC: 0x0a3d90 | FDE: 0x11d170 | Size: 68 bytes [_ZNSt6__ndk123__match_any_but_newlineIcED0Ev]
// Hàm FDE #0828 | Địa chỉ PC: 0x0a3d90 | Địa chỉ FDE: 0x11d170 | Kích thước: 68 bytes
//   0x0a3d90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a3d94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3d98: 910043FD  add      x29, sp, #0x10
//   0x0a3d9c: 900004E8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0828_0x0a3d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3d90ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d170ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0829 | PC: 0x0a3dd4 | FDE: 0x11eff8 | Size: 76 bytes
// Hàm FDE #0829 | Địa chỉ PC: 0x0a3dd4 | Địa chỉ FDE: 0x11eff8 | Kích thước: 76 bytes
//   0x0a3dd4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3dd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3ddc: 910043FD  add      x29, sp, #0x10
//   0x0a3de0: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0829_0x0a3dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3dd4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11eff8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0830 | PC: 0x0a3e20 | FDE: 0x11d190 | Size: 220 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE22__parse_decimal_escapeINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0830 | Địa chỉ PC: 0x0a3e20 | Địa chỉ FDE: 0x11d190 | Kích thước: 220 bytes
//   0x0a3e20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a3e24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3e28: 910043FD  add      x29, sp, #0x10
//   0x0a3e2c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0830_0x0a3e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3e20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d190ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0831 | PC: 0x0a3efc | FDE: 0x11f020 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE30__parse_character_class_escapeINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0831 | Địa chỉ PC: 0x0a3efc | Địa chỉ FDE: 0x11f020 | Kích thước: 256 bytes
//   0x0a3efc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a3f00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a3f04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a3f08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0831_0x0a3efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3efcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11f020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0832 | PC: 0x0a40f0 | FDE: 0x11d1b0 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE24__parse_character_escapeINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE]
// Hàm FDE #0832 | Địa chỉ PC: 0x0a40f0 | Địa chỉ FDE: 0x11d1b0 | Kích thước: 256 bytes
//   0x0a40f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a40f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a40f8: 910043FD  add      x29, sp, #0x10
//   0x0a40fc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0832_0x0a40f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a40f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0833 | PC: 0x0a44f8 | FDE: 0x11f048 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE11__push_charEc]
// Hàm FDE #0833 | Địa chỉ PC: 0x0a44f8 | Địa chỉ FDE: 0x11f048 | Kích thước: 256 bytes
//   0x0a44f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a44fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a4500: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a4504: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0833_0x0a44f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a44f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11f048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 417: return fde_func_0417_0x07153c(a0, a1);
        case 418: return fde_func_0418_0x0715a8(a0, a1);
        case 419: return fde_func_0419_0x071894(a0, a1);
        case 420: return fde_func_0420_0x0718f4(a0, a1);
        case 421: return fde_func_0421_0x071ab0(a0, a1);
        case 422: return fde_func_0422_0x071e4c(a0, a1);
        case 423: return fde_func_0423_0x07203c(a0, a1);
        case 424: return fde_func_0424_0x07217c(a0, a1);
        case 425: return fde_func_0425_0x0723bc(a0, a1);
        case 426: return fde_func_0426_0x072568(a0, a1);
        case 427: return fde_func_0427_0x0727a4(a0, a1);
        case 428: return fde_func_0428_0x072af8(a0, a1);
        case 429: return fde_func_0429_0x072e98(a0, a1);
        case 430: return fde_func_0430_0x073238(a0, a1);
        case 431: return fde_func_0431_0x073298(a0, a1);
        case 432: return fde_func_0432_0x0732cc(a0, a1);
        case 433: return fde_func_0433_0x073594(a0, a1);
        case 434: return fde_func_0434_0x0736c8(a0, a1);
        case 435: return fde_func_0435_0x0737c4(a0, a1);
        case 436: return fde_func_0436_0x0738c0(a0, a1);
        case 437: return fde_func_0437_0x073980(a0, a1);
        case 438: return fde_func_0438_0x073bf0(a0, a1);
        case 439: return fde_func_0439_0x073c14(a0, a1);
        case 440: return fde_func_0440_0x073c38(a0, a1);
        case 441: return fde_func_0441_0x073cb4(a0, a1);
        case 442: return fde_func_0442_0x073cbc(a0, a1);
        case 443: return fde_func_0443_0x073ce4(a0, a1);
        case 444: return fde_func_0444_0x073cf8(a0, a1);
        case 445: return fde_func_0445_0x073d28(a0, a1);
        case 446: return fde_func_0446_0x073d9c(a0, a1);
        case 447: return fde_func_0447_0x073e20(a0, a1);
        case 448: return fde_func_0448_0x073ffc(a0, a1);
        case 449: return fde_func_0449_0x074170(a0, a1);
        case 450: return fde_func_0450_0x0742e4(a0, a1);
        case 451: return fde_func_0451_0x074458(a0, a1);
        case 452: return fde_func_0452_0x0744b8(a0, a1);
        case 453: return fde_func_0453_0x0744f0(a0, a1);
        case 454: return fde_func_0454_0x0745c8(a0, a1);
        case 455: return fde_func_0455_0x074610(a0, a1);
        case 456: return fde_func_0456_0x074670(a0, a1);
        case 457: return fde_func_0457_0x074734(a0, a1);
        case 458: return fde_func_0458_0x074850(a0, a1);
        case 459: return fde_func_0459_0x074888(a0, a1);
        case 460: return fde_func_0460_0x0748e8(a0, a1);
        case 461: return fde_func_0461_0x0749c4(a0, a1);
        case 462: return fde_func_0462_0x074cf0(a0, a1);
        case 463: return fde_func_0463_0x074d38(a0, a1);
        case 464: return fde_func_0464_0x074de8(a0, a1);
        case 465: return fde_func_0465_0x074e48(a0, a1);
        case 466: return fde_func_0466_0x074f38(a0, a1);
        case 467: return fde_func_0467_0x075208(a0, a1);
        case 468: return fde_func_0468_0x075320(a0, a1);
        case 469: return fde_func_0469_0x075550(a0, a1);
        case 470: return fde_func_0470_0x0755c8(a0, a1);
        case 471: return fde_func_0471_0x075640(a0, a1);
        case 472: return fde_func_0472_0x075650(a0, a1);
        case 473: return fde_func_0473_0x075bbc(a0, a1);
        case 474: return fde_func_0474_0x075c94(a0, a1);
        case 475: return fde_func_0475_0x075cb8(a0, a1);
        case 476: return fde_func_0476_0x075d10(a0, a1);
        case 477: return fde_func_0477_0x075d34(a0, a1);
        case 478: return fde_func_0478_0x075d68(a0, a1);
        case 479: return fde_func_0479_0x075dc8(a0, a1);
        case 480: return fde_func_0480_0x075e18(a0, a1);
        case 481: return fde_func_0481_0x076014(a0, a1);
        case 482: return fde_func_0482_0x076354(a0, a1);
        case 483: return fde_func_0483_0x0766a4(a0, a1);
        case 484: return fde_func_0484_0x076840(a0, a1);
        case 485: return fde_func_0485_0x0769f8(a0, a1);
        case 486: return fde_func_0486_0x076a48(a0, a1);
        case 487: return fde_func_0487_0x076a98(a0, a1);
        case 488: return fde_func_0488_0x076d4c(a0, a1);
        case 489: return fde_func_0489_0x076f00(a0, a1);
        case 490: return fde_func_0490_0x076f54(a0, a1);
        case 491: return fde_func_0491_0x076fe4(a0, a1);
        case 492: return fde_func_0492_0x076ff4(a0, a1);
        case 493: return fde_func_0493_0x0770c4(a0, a1);
        case 494: return fde_func_0494_0x07726c(a0, a1);
        case 495: return fde_func_0495_0x077340(a0, a1);
        case 496: return fde_func_0496_0x0774ec(a0, a1);
        case 497: return fde_func_0497_0x077b0c(a0, a1);
        case 498: return fde_func_0498_0x077bd4(a0, a1);
        case 499: return fde_func_0499_0x077c9c(a0, a1);
        case 500: return fde_func_0500_0x077d64(a0, a1);
        case 501: return fde_func_0501_0x077e2c(a0, a1);
        case 502: return fde_func_0502_0x07801c(a0, a1);
        case 503: return fde_func_0503_0x078114(a0, a1);
        case 504: return fde_func_0504_0x078224(a0, a1);
        case 505: return fde_func_0505_0x0783c4(a0, a1);
        case 506: return fde_func_0506_0x0785e0(a0, a1);
        case 507: return fde_func_0507_0x07889c(a0, a1);
        case 508: return fde_func_0508_0x078c84(a0, a1);
        case 509: return fde_func_0509_0x078e80(a0, a1);
        case 510: return fde_func_0510_0x078f50(a0, a1);
        case 511: return fde_func_0511_0x079024(a0, a1);
        case 512: return fde_func_0512_0x0791c8(a0, a1);
        case 513: return fde_func_0513_0x0792c8(a0, a1);
        case 514: return fde_func_0514_0x07931c(a0, a1);
        case 515: return fde_func_0515_0x079424(a0, a1);
        case 516: return fde_func_0516_0x07952c(a0, a1);
        case 517: return fde_func_0517_0x079648(a0, a1);
        case 518: return fde_func_0518_0x079a74(a0, a1);
        case 519: return fde_func_0519_0x079cb4(a0, a1);
        case 520: return fde_func_0520_0x079e40(a0, a1);
        case 521: return fde_func_0521_0x07a8bc(a0, a1);
        case 522: return fde_func_0522_0x07a9c8(a0, a1);
        case 523: return fde_func_0523_0x07ab18(a0, a1);
        case 524: return fde_func_0524_0x07ac18(a0, a1);
        case 525: return fde_func_0525_0x07ad64(a0, a1);
        case 526: return fde_func_0526_0x07b51c(a0, a1);
        case 527: return fde_func_0527_0x07b62c(a0, a1);
        case 528: return fde_func_0528_0x07b7a4(a0, a1);
        case 529: return fde_func_0529_0x07b958(a0, a1);
        case 530: return fde_func_0530_0x07ba14(a0, a1);
        case 531: return fde_func_0531_0x07bb94(a0, a1);
        case 532: return fde_func_0532_0x07bca4(a0, a1);
        case 533: return fde_func_0533_0x07bdc0(a0, a1);
        case 534: return fde_func_0534_0x07bf74(a0, a1);
        case 535: return fde_func_0535_0x07c578(a0, a1);
        case 536: return fde_func_0536_0x07c6d0(a0, a1);
        case 537: return fde_func_0537_0x07c6e8(a0, a1);
        case 538: return fde_func_0538_0x07c700(a0, a1);
        case 539: return fde_func_0539_0x07c8a4(a0, a1);
        case 540: return fde_func_0540_0x07ca48(a0, a1);
        case 541: return fde_func_0541_0x07ca60(a0, a1);
        case 542: return fde_func_0542_0x07ca78(a0, a1);
        case 543: return fde_func_0543_0x07caec(a0, a1);
        case 544: return fde_func_0544_0x07cb6c(a0, a1);
        case 545: return fde_func_0545_0x07cd18(a0, a1);
        case 546: return fde_func_0546_0x07cdb0(a0, a1);
        case 547: return fde_func_0547_0x07cf3c(a0, a1);
        case 548: return fde_func_0548_0x07cfd4(a0, a1);
        case 549: return fde_func_0549_0x07d06c(a0, a1);
        case 550: return fde_func_0550_0x07d0cc(a0, a1);
        case 551: return fde_func_0551_0x07d260(a0, a1);
        case 552: return fde_func_0552_0x07d2a8(a0, a1);
        case 553: return fde_func_0553_0x07d4ac(a0, a1);
        case 554: return fde_func_0554_0x07d91c(a0, a1);
        case 555: return fde_func_0555_0x07dbe8(a0, a1);
        case 556: return fde_func_0556_0x07dd30(a0, a1);
        case 557: return fde_func_0557_0x07def4(a0, a1);
        case 558: return fde_func_0558_0x07df5c(a0, a1);
        case 559: return fde_func_0559_0x07dfcc(a0, a1);
        case 560: return fde_func_0560_0x07e0d8(a0, a1);
        case 561: return fde_func_0561_0x07e1ec(a0, a1);
        case 562: return fde_func_0562_0x07e210(a0, a1);
        case 563: return fde_func_0563_0x07e214(a0, a1);
        case 564: return fde_func_0564_0x07e218(a0, a1);
        case 565: return fde_func_0565_0x07e4ec(a0, a1);
        case 566: return fde_func_0566_0x07e758(a0, a1);
        case 567: return fde_func_0567_0x07e7b8(a0, a1);
        case 568: return fde_func_0568_0x07e914(a0, a1);
        case 569: return fde_func_0569_0x07ebd8(a0, a1);
        case 570: return fde_func_0570_0x07edd0(a0, a1);
        case 571: return fde_func_0571_0x07edfc(a0, a1);
        case 572: return fde_func_0572_0x07ee28(a0, a1);
        case 573: return fde_func_0573_0x07ee54(a0, a1);
        case 574: return fde_func_0574_0x07ef28(a0, a1);
        case 575: return fde_func_0575_0x07f274(a0, a1);
        case 576: return fde_func_0576_0x07fb20(a0, a1);
        case 577: return fde_func_0577_0x0803f4(a0, a1);
        case 578: return fde_func_0578_0x080bf8(a0, a1);
        case 579: return fde_func_0579_0x081588(a0, a1);
        case 580: return fde_func_0580_0x082404(a0, a1);
        case 581: return fde_func_0581_0x083290(a0, a1);
        case 582: return fde_func_0582_0x0841bc(a0, a1);
        case 583: return fde_func_0583_0x084228(a0, a1);
        case 584: return fde_func_0584_0x08429c(a0, a1);
        case 585: return fde_func_0585_0x0843e0(a0, a1);
        case 586: return fde_func_0586_0x084904(a0, a1);
        case 587: return fde_func_0587_0x0849f0(a0, a1);
        case 588: return fde_func_0588_0x084cb4(a0, a1);
        case 589: return fde_func_0589_0x084da4(a0, a1);
        case 590: return fde_func_0590_0x084ee4(a0, a1);
        case 591: return fde_func_0591_0x085050(a0, a1);
        case 592: return fde_func_0592_0x0851e4(a0, a1);
        case 593: return fde_func_0593_0x08539c(a0, a1);
        case 594: return fde_func_0594_0x085488(a0, a1);
        case 595: return fde_func_0595_0x0855ac(a0, a1);
        case 596: return fde_func_0596_0x085758(a0, a1);
        case 597: return fde_func_0597_0x08580c(a0, a1);
        case 598: return fde_func_0598_0x085db4(a0, a1);
        case 599: return fde_func_0599_0x085e70(a0, a1);
        case 600: return fde_func_0600_0x0863e4(a0, a1);
        case 601: return fde_func_0601_0x086794(a0, a1);
        case 602: return fde_func_0602_0x0868a4(a0, a1);
        case 603: return fde_func_0603_0x086e5c(a0, a1);
        case 604: return fde_func_0604_0x086ffc(a0, a1);
        case 605: return fde_func_0605_0x0870ec(a0, a1);
        case 606: return fde_func_0606_0x08720c(a0, a1);
        case 607: return fde_func_0607_0x087488(a0, a1);
        case 608: return fde_func_0608_0x0874e8(a0, a1);
        case 609: return fde_func_0609_0x087538(a0, a1);
        case 610: return fde_func_0610_0x087588(a0, a1);
        case 611: return fde_func_0611_0x0875ac(a0, a1);
        case 612: return fde_func_0612_0x087608(a0, a1);
        case 613: return fde_func_0613_0x08760c(a0, a1);
        case 614: return fde_func_0614_0x08775c(a0, a1);
        case 615: return fde_func_0615_0x08788c(a0, a1);
        case 616: return fde_func_0616_0x087c3c(a0, a1);
        case 617: return fde_func_0617_0x087c60(a0, a1);
        case 618: return fde_func_0618_0x087cc8(a0, a1);
        case 619: return fde_func_0619_0x087ccc(a0, a1);
        case 620: return fde_func_0620_0x087cf0(a0, a1);
        case 621: return fde_func_0621_0x087da8(a0, a1);
        case 622: return fde_func_0622_0x087dac(a0, a1);
        case 623: return fde_func_0623_0x08824c(a0, a1);
        case 624: return fde_func_0624_0x08835c(a0, a1);
        case 625: return fde_func_0625_0x088514(a0, a1);
        case 626: return fde_func_0626_0x08876c(a0, a1);
        case 627: return fde_func_0627_0x088880(a0, a1);
        case 628: return fde_func_0628_0x088a80(a0, a1);
        case 629: return fde_func_0629_0x089114(a0, a1);
        case 630: return fde_func_0630_0x089380(a0, a1);
        case 631: return fde_func_0631_0x089490(a0, a1);
        case 632: return fde_func_0632_0x089674(a0, a1);
        case 633: return fde_func_0633_0x089970(a0, a1);
        case 634: return fde_func_0634_0x089c2c(a0, a1);
        case 635: return fde_func_0635_0x089f8c(a0, a1);
        case 636: return fde_func_0636_0x08b1a4(a0, a1);
        case 637: return fde_func_0637_0x08b9ac(a0, a1);
        case 638: return fde_func_0638_0x08c658(a0, a1);
        case 639: return fde_func_0639_0x08c960(a0, a1);
        case 640: return fde_func_0640_0x08cd58(a0, a1);
        case 641: return fde_func_0641_0x08ed94(a0, a1);
        case 642: return fde_func_0642_0x08f44c(a0, a1);
        case 643: return fde_func_0643_0x08f6d4(a0, a1);
        case 644: return fde_func_0644_0x08f868(a0, a1);
        case 645: return fde_func_0645_0x08f9b0(a0, a1);
        case 646: return fde_func_0646_0x08f9e4(a0, a1);
        case 647: return fde_func_0647_0x08f9f4(a0, a1);
        case 648: return fde_func_0648_0x08fa8c(a0, a1);
        case 649: return fde_func_0649_0x08fab8(a0, a1);
        case 650: return fde_func_0650_0x08fc08(a0, a1);
        case 651: return fde_func_0651_0x08fdf4(a0, a1);
        case 652: return fde_func_0652_0x08ff00(a0, a1);
        case 653: return fde_func_0653_0x08ffd4(a0, a1);
        case 654: return fde_func_0654_0x0900e4(a0, a1);
        case 655: return fde_func_0655_0x0900f8(a0, a1);
        case 656: return fde_func_0656_0x090220(a0, a1);
        case 657: return fde_func_0657_0x090d78(a0, a1);
        case 658: return fde_func_0658_0x090eec(a0, a1);
        case 659: return fde_func_0659_0x091118(a0, a1);
        case 660: return fde_func_0660_0x091bd0(a0, a1);
        case 661: return fde_func_0661_0x092590(a0, a1);
        case 662: return fde_func_0662_0x092650(a0, a1);
        case 663: return fde_func_0663_0x092740(a0, a1);
        case 664: return fde_func_0664_0x092c08(a0, a1);
        case 665: return fde_func_0665_0x092c48(a0, a1);
        case 666: return fde_func_0666_0x093048(a0, a1);
        case 667: return fde_func_0667_0x0931c4(a0, a1);
        case 668: return fde_func_0668_0x0932d8(a0, a1);
        case 669: return fde_func_0669_0x0933e4(a0, a1);
        case 670: return fde_func_0670_0x093558(a0, a1);
        case 671: return fde_func_0671_0x094124(a0, a1);
        case 672: return fde_func_0672_0x0943ec(a0, a1);
        case 673: return fde_func_0673_0x094680(a0, a1);
        case 674: return fde_func_0674_0x094798(a0, a1);
        case 675: return fde_func_0675_0x094eb8(a0, a1);
        case 676: return fde_func_0676_0x095d70(a0, a1);
        case 677: return fde_func_0677_0x096160(a0, a1);
        case 678: return fde_func_0678_0x096184(a0, a1);
        case 679: return fde_func_0679_0x096248(a0, a1);
        case 680: return fde_func_0680_0x096588(a0, a1);
        case 681: return fde_func_0681_0x0968e0(a0, a1);
        case 682: return fde_func_0682_0x096b0c(a0, a1);
        case 683: return fde_func_0683_0x097f88(a0, a1);
        case 684: return fde_func_0684_0x09824c(a0, a1);
        case 685: return fde_func_0685_0x09835c(a0, a1);
        case 686: return fde_func_0686_0x09846c(a0, a1);
        case 687: return fde_func_0687_0x098b24(a0, a1);
        case 688: return fde_func_0688_0x098bc8(a0, a1);
        case 689: return fde_func_0689_0x098c98(a0, a1);
        case 690: return fde_func_0690_0x098e5c(a0, a1);
        case 691: return fde_func_0691_0x098fa4(a0, a1);
        case 692: return fde_func_0692_0x099270(a0, a1);
        case 693: return fde_func_0693_0x0992a0(a0, a1);
        case 694: return fde_func_0694_0x0995e0(a0, a1);
        case 695: return fde_func_0695_0x099690(a0, a1);
        case 696: return fde_func_0696_0x0998dc(a0, a1);
        case 697: return fde_func_0697_0x0999d4(a0, a1);
        case 698: return fde_func_0698_0x0999f8(a0, a1);
        case 699: return fde_func_0699_0x099b68(a0, a1);
        case 700: return fde_func_0700_0x099b70(a0, a1);
        case 701: return fde_func_0701_0x099d40(a0, a1);
        case 702: return fde_func_0702_0x099dd4(a0, a1);
        case 703: return fde_func_0703_0x09a014(a0, a1);
        case 704: return fde_func_0704_0x09a334(a0, a1);
        case 705: return fde_func_0705_0x09a830(a0, a1);
        case 706: return fde_func_0706_0x09aae0(a0, a1);
        case 707: return fde_func_0707_0x09ab88(a0, a1);
        case 708: return fde_func_0708_0x09ac14(a0, a1);
        case 709: return fde_func_0709_0x09ac94(a0, a1);
        case 710: return fde_func_0710_0x09acfc(a0, a1);
        case 711: return fde_func_0711_0x09afc4(a0, a1);
        case 712: return fde_func_0712_0x09b1e4(a0, a1);
        case 713: return fde_func_0713_0x09b21c(a0, a1);
        case 714: return fde_func_0714_0x09b3e0(a0, a1);
        case 715: return fde_func_0715_0x09b5a8(a0, a1);
        case 716: return fde_func_0716_0x09b5dc(a0, a1);
        case 717: return fde_func_0717_0x09b60c(a0, a1);
        case 718: return fde_func_0718_0x09b828(a0, a1);
        case 719: return fde_func_0719_0x09b88c(a0, a1);
        case 720: return fde_func_0720_0x09b910(a0, a1);
        case 721: return fde_func_0721_0x09b928(a0, a1);
        case 722: return fde_func_0722_0x09ba44(a0, a1);
        case 723: return fde_func_0723_0x09bd08(a0, a1);
        case 724: return fde_func_0724_0x09bda4(a0, a1);
        case 725: return fde_func_0725_0x09be5c(a0, a1);
        case 726: return fde_func_0726_0x09be88(a0, a1);
        case 727: return fde_func_0727_0x09be8c(a0, a1);
        case 728: return fde_func_0728_0x09c17c(a0, a1);
        case 729: return fde_func_0729_0x09c46c(a0, a1);
        case 730: return fde_func_0730_0x09c76c(a0, a1);
        case 731: return fde_func_0731_0x09c7ac(a0, a1);
        case 732: return fde_func_0732_0x09ca88(a0, a1);
        case 733: return fde_func_0733_0x09cb5c(a0, a1);
        case 734: return fde_func_0734_0x09cfe8(a0, a1);
        case 735: return fde_func_0735_0x09cff0(a0, a1);
        case 736: return fde_func_0736_0x09d014(a0, a1);
        case 737: return fde_func_0737_0x09d110(a0, a1);
        case 738: return fde_func_0738_0x09d1d4(a0, a1);
        case 739: return fde_func_0739_0x09d318(a0, a1);
        case 740: return fde_func_0740_0x09d5a0(a0, a1);
        case 741: return fde_func_0741_0x09d6cc(a0, a1);
        case 742: return fde_func_0742_0x09d884(a0, a1);
        case 743: return fde_func_0743_0x09da14(a0, a1);
        case 744: return fde_func_0744_0x09daf4(a0, a1);
        case 745: return fde_func_0745_0x09db78(a0, a1);
        case 746: return fde_func_0746_0x09e214(a0, a1);
        case 747: return fde_func_0747_0x09e488(a0, a1);
        case 748: return fde_func_0748_0x09e774(a0, a1);
        case 749: return fde_func_0749_0x09e9f8(a0, a1);
        case 750: return fde_func_0750_0x09ed70(a0, a1);
        case 751: return fde_func_0751_0x09eec8(a0, a1);
        case 752: return fde_func_0752_0x09ef68(a0, a1);
        case 753: return fde_func_0753_0x09f008(a0, a1);
        case 754: return fde_func_0754_0x09f364(a0, a1);
        case 755: return fde_func_0755_0x09f450(a0, a1);
        case 756: return fde_func_0756_0x09f548(a0, a1);
        case 757: return fde_func_0757_0x09f554(a0, a1);
        case 758: return fde_func_0758_0x09f5f0(a0, a1);
        case 759: return fde_func_0759_0x09f608(a0, a1);
        case 760: return fde_func_0760_0x09f658(a0, a1);
        case 761: return fde_func_0761_0x09f690(a0, a1);
        case 762: return fde_func_0762_0x09f6b8(a0, a1);
        case 763: return fde_func_0763_0x09f734(a0, a1);
        case 764: return fde_func_0764_0x09f7ec(a0, a1);
        case 765: return fde_func_0765_0x09f940(a0, a1);
        case 766: return fde_func_0766_0x09fa54(a0, a1);
        case 767: return fde_func_0767_0x09fbe8(a0, a1);
        case 768: return fde_func_0768_0x09fd80(a0, a1);
        case 769: return fde_func_0769_0x09fefc(a0, a1);
        case 770: return fde_func_0770_0x09ff38(a0, a1);
        case 771: return fde_func_0771_0x0a040c(a0, a1);
        case 772: return fde_func_0772_0x0a0570(a0, a1);
        case 773: return fde_func_0773_0x0a06ac(a0, a1);
        case 774: return fde_func_0774_0x0a07d0(a0, a1);
        case 775: return fde_func_0775_0x0a07f0(a0, a1);
        case 776: return fde_func_0776_0x0a0a3c(a0, a1);
        case 777: return fde_func_0777_0x0a0ad4(a0, a1);
        case 778: return fde_func_0778_0x0a0b6c(a0, a1);
        case 779: return fde_func_0779_0x0a0b90(a0, a1);
        case 780: return fde_func_0780_0x0a0b98(a0, a1);
        case 781: return fde_func_0781_0x0a0ba0(a0, a1);
        case 782: return fde_func_0782_0x0a0ba8(a0, a1);
        case 783: return fde_func_0783_0x0a0bc4(a0, a1);
        case 784: return fde_func_0784_0x0a0ccc(a0, a1);
        case 785: return fde_func_0785_0x0a0d60(a0, a1);
        case 786: return fde_func_0786_0x0a0f3c(a0, a1);
        case 787: return fde_func_0787_0x0a1198(a0, a1);
        case 788: return fde_func_0788_0x0a12ec(a0, a1);
        case 789: return fde_func_0789_0x0a146c(a0, a1);
        case 790: return fde_func_0790_0x0a1670(a0, a1);
        case 791: return fde_func_0791_0x0a1874(a0, a1);
        case 792: return fde_func_0792_0x0a18c0(a0, a1);
        case 793: return fde_func_0793_0x0a18c4(a0, a1);
        case 794: return fde_func_0794_0x0a18d0(a0, a1);
        case 795: return fde_func_0795_0x0a18d4(a0, a1);
        case 796: return fde_func_0796_0x0a18d8(a0, a1);
        case 797: return fde_func_0797_0x0a18fc(a0, a1);
        case 798: return fde_func_0798_0x0a1914(a0, a1);
        case 799: return fde_func_0799_0x0a1918(a0, a1);
        case 800: return fde_func_0800_0x0a195c(a0, a1);
        case 801: return fde_func_0801_0x0a1970(a0, a1);
        case 802: return fde_func_0802_0x0a19b4(a0, a1);
        case 803: return fde_func_0803_0x0a1ea8(a0, a1);
        case 804: return fde_func_0804_0x0a213c(a0, a1);
        case 805: return fde_func_0805_0x0a24e0(a0, a1);
        case 806: return fde_func_0806_0x0a252c(a0, a1);
        case 807: return fde_func_0807_0x0a2570(a0, a1);
        case 808: return fde_func_0808_0x0a25b0(a0, a1);
        case 809: return fde_func_0809_0x0a25f4(a0, a1);
        case 810: return fde_func_0810_0x0a262c(a0, a1);
        case 811: return fde_func_0811_0x0a2688(a0, a1);
        case 812: return fde_func_0812_0x0a26e0(a0, a1);
        case 813: return fde_func_0813_0x0a2800(a0, a1);
        case 814: return fde_func_0814_0x0a2898(a0, a1);
        case 815: return fde_func_0815_0x0a292c(a0, a1);
        case 816: return fde_func_0816_0x0a2b0c(a0, a1);
        case 817: return fde_func_0817_0x0a3240(a0, a1);
        case 818: return fde_func_0818_0x0a3414(a0, a1);
        case 819: return fde_func_0819_0x0a3460(a0, a1);
        case 820: return fde_func_0820_0x0a34ac(a0, a1);
        case 821: return fde_func_0821_0x0a36c4(a0, a1);
        case 822: return fde_func_0822_0x0a3888(a0, a1);
        case 823: return fde_func_0823_0x0a39f0(a0, a1);
        case 824: return fde_func_0824_0x0a3ad8(a0, a1);
        case 825: return fde_func_0825_0x0a3b94(a0, a1);
        case 826: return fde_func_0826_0x0a3ce8(a0, a1);
        case 827: return fde_func_0827_0x0a3d34(a0, a1);
        case 828: return fde_func_0828_0x0a3d90(a0, a1);
        case 829: return fde_func_0829_0x0a3dd4(a0, a1);
        case 830: return fde_func_0830_0x0a3e20(a0, a1);
        case 831: return fde_func_0831_0x0a3efc(a0, a1);
        case 832: return fde_func_0832_0x0a40f0(a0, a1);
        case 833: return fde_func_0833_0x0a44f8(a0, a1);
        default: return 0ULL;
    }
}

} // namespace fast_engine