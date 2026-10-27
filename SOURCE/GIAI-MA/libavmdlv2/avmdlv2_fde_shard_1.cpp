// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 1/5 for libavmdlv2.so
// Phân mảnh Hàm AArch64 C++17 sạch 1/5 cho libavmdlv2.so
// Covers .text function indices [0 .. 379] out of 1900 total functions
// Bao phủ chỉ số hàm .text [0 .. 379] trên tổng số 1900 hàm
// ============================================================================
#include "avmdlv2_core.h"

namespace com {
namespace ss {
namespace ttmio {

// Func #0000 | PC: 0x034c9c | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0000 | Địa chỉ PC: 0x034c9c | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x034c9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x034ca0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x034ca4: 910043FD  add      x29, sp, #0x10
//   0x034ca8: 90000954  adrp     x20, #0x15c000
static inline uint64_t fde_func_0000_0x034c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034c9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0001 | PC: 0x034cfc | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0001 | Địa chỉ PC: 0x034cfc | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x034cfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x034d00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x034d04: 910043FD  add      x29, sp, #0x10
//   0x034d08: 90000954  adrp     x20, #0x15c000
static inline uint64_t fde_func_0001_0x034cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034cfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0002 | PC: 0x034dd0 | FDE: 0x148a38 | Size: 184 bytes [registerTTKMediaNetDownloader]
// Hàm #0002 | Địa chỉ PC: 0x034dd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x034dd0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x034dd4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x034dd8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x034ddc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0002_0x034dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034dd0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0003 | PC: 0x034e88 | FDE: 0x148a38 | Size: 184 bytes [registerTTKMediaNetStrategy]
// Hàm #0003 | Địa chỉ PC: 0x034e88 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x034e88: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x034e8c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x034e90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x034e94: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0003_0x034e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034e88ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0004 | PC: 0x034f40 | FDE: 0x148a38 | Size: 184 bytes [registerIoCtrlDownloader]
// Hàm #0004 | Địa chỉ PC: 0x034f40 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x034f40: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x034f44: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x034f48: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x034f4c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0004_0x034f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034f40ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0005 | PC: 0x034ff8 | FDE: 0x148a38 | Size: 184 bytes [registerIoCtrlStrategy]
// Hàm #0005 | Địa chỉ PC: 0x034ff8 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x034ff8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x034ffc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x035000: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x035004: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0005_0x034ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034ff8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0006 | PC: 0x0350b0 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0006 | Địa chỉ PC: 0x0350b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0350b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0350b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0350b8: 910043FD  add      x29, sp, #0x10
//   0x0350bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0006_0x0350b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0350b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0007 | PC: 0x035128 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0007 | Địa chỉ PC: 0x035128 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x035128: D10103FF  sub      sp, sp, #0x40
//   0x03512c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x035130: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x035134: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0007_0x035128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035128ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0008 | PC: 0x035178 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0008 | Địa chỉ PC: 0x035178 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x035178: D10103FF  sub      sp, sp, #0x40
//   0x03517c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x035180: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x035184: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0008_0x035178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035178ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0009 | PC: 0x0351d4 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0009 | Địa chỉ PC: 0x0351d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0351d4: D10103FF  sub      sp, sp, #0x40
//   0x0351d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0351dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0351e0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0009_0x0351d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0351d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #0010 | PC: 0x035220 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0010 | Địa chỉ PC: 0x035220 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x035220: D10103FF  sub      sp, sp, #0x40
//   0x035224: F90013F3  str      x19, [sp, #0x20]
//   0x035228: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03522c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0010_0x035220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035220ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0011 | PC: 0x03529c | FDE: 0x148a38 | Size: 148 bytes
// Hàm #0011 | Địa chỉ PC: 0x03529c | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x03529c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0352a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0352a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0352a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0011_0x03529c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03529cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #0012 | PC: 0x035330 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0012 | Địa chỉ PC: 0x035330 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x035330: D10103FF  sub      sp, sp, #0x40
//   0x035334: F90013F3  str      x19, [sp, #0x20]
//   0x035338: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03533c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0012_0x035330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035330ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0013 | PC: 0x0353ac | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0013 | Địa chỉ PC: 0x0353ac | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x0353ac: D10103FF  sub      sp, sp, #0x40
//   0x0353b0: F90013F3  str      x19, [sp, #0x20]
//   0x0353b4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0353b8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0013_0x0353ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0353acULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0014 | PC: 0x035428 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0014 | Địa chỉ PC: 0x035428 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x035428: D10103FF  sub      sp, sp, #0x40
//   0x03542c: F90013F3  str      x19, [sp, #0x20]
//   0x035430: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x035434: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0014_0x035428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035428ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0015 | PC: 0x035628 | FDE: 0x148a38 | Size: 24 bytes
// Hàm #0015 | Địa chỉ PC: 0x035628 | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x035628: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x03562c: 910003FD  mov      x29, sp
//   0x035630: 940026F7  bl       #0x3f20c
//   0x035634: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0015_0x035628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035628ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #0016 | PC: 0x035640 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0016 | Địa chỉ PC: 0x035640 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x035640: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x035644: 910003FD  mov      x29, sp
//   0x035648: 940026F2  bl       #0x3f210
//   0x03564c: 93407C00  sxtw     x0, w0
static inline uint64_t fde_func_0016_0x035640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035640ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0017 | PC: 0x03578c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0017 | Địa chỉ PC: 0x03578c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03578c: D10103FF  sub      sp, sp, #0x40
//   0x035790: F90013F3  str      x19, [sp, #0x20]
//   0x035794: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x035798: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0017_0x03578c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03578cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0018 | PC: 0x035900 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0018 | Địa chỉ PC: 0x035900 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x035900: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x035904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x035908: 910043FD  add      x29, sp, #0x10
//   0x03590c: D0000928  adrp     x8, #0x15b000
static inline uint64_t fde_func_0018_0x035900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035900ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0019 | PC: 0x0359a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0019 | Địa chỉ PC: 0x0359a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0359a4: D10103FF  sub      sp, sp, #0x40
//   0x0359a8: F9000BF5  str      x21, [sp, #0x10]
//   0x0359ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0359b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0019_0x0359a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0359a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0020 | PC: 0x035adc | FDE: 0x148a38 | Size: 236 bytes
// Hàm #0020 | Địa chỉ PC: 0x035adc | Địa chỉ FDE: 0x148a38 | Kích thước: 236 bytes
//   0x035adc: D10103FF  sub      sp, sp, #0x40
//   0x035ae0: F9000BF5  str      x21, [sp, #0x10]
//   0x035ae4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x035ae8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0020_0x035adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035adcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// Func #0021 | PC: 0x035bc8 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0021 | Địa chỉ PC: 0x035bc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x035bc8: D10403FF  sub      sp, sp, #0x100
//   0x035bcc: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x035bd0: 9103C3FD  add      x29, sp, #0xf0
//   0x035bd4: 928004E8  mov      x8, #-0x28
static inline uint64_t fde_func_0021_0x035bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035bc8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90f7bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0022 | PC: 0x035c38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0022 | Địa chỉ PC: 0x035c38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x035c38: D10183FF  sub      sp, sp, #0x60
//   0x035c3c: F9000BF9  str      x25, [sp, #0x10]
//   0x035c40: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x035c44: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0022_0x035c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035c38ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0023 | PC: 0x035e04 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0023 | Địa chỉ PC: 0x035e04 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x035e04: D10403FF  sub      sp, sp, #0x100
//   0x035e08: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x035e0c: 9103C3FD  add      x29, sp, #0xf0
//   0x035e10: 928004E8  mov      x8, #-0x28
static inline uint64_t fde_func_0023_0x035e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035e04ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90f7bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0024 | PC: 0x035e74 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0024 | Địa chỉ PC: 0x035e74 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x035e74: D10143FF  sub      sp, sp, #0x50
//   0x035e78: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x035e7c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x035e80: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0024_0x035e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035e74ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0025 | PC: 0x035fd4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0025 | Địa chỉ PC: 0x035fd4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x035fd4: D10103FF  sub      sp, sp, #0x40
//   0x035fd8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x035fdc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x035fe0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0025_0x035fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035fd4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0026 | PC: 0x036148 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0026 | Địa chỉ PC: 0x036148 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x036148: D10403FF  sub      sp, sp, #0x100
//   0x03614c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x036150: 9103C3FD  add      x29, sp, #0xf0
//   0x036154: 928004E8  mov      x8, #-0x28
static inline uint64_t fde_func_0026_0x036148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x036148ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90f7bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0027 | PC: 0x036a64 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0027 | Địa chỉ PC: 0x036a64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x036a64: D11243FF  sub      sp, sp, #0x490
//   0x036a68: AA0103F4  mov      x20, x1
//   0x036a6c: AA0003F5  mov      x21, x0
//   0x036a70: 97FFF11C  bl       #0x32ee0
static inline uint64_t fde_func_0027_0x036a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x036a64ULL ^ (static_cast<uint64_t>(0xd11243ffULL) << 13);
    acc = (acc + a1 + 0xaa0103f4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0028 | PC: 0x0374e8 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #0028 | Địa chỉ PC: 0x0374e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x0374e8: D100C3FF  sub      sp, sp, #0x30
//   0x0374ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0374f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0374f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0028_0x0374e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0374e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #0029 | PC: 0x037578 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0029 | Địa chỉ PC: 0x037578 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x037578: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03757c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037580: 910043FD  add      x29, sp, #0x10
//   0x037584: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0029_0x037578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037578ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0030 | PC: 0x03761c | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0030 | Địa chỉ PC: 0x03761c | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x03761c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x037620: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037624: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037628: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0030_0x03761c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03761cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0031 | PC: 0x0376e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0031 | Địa chỉ PC: 0x0376e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0376e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0376e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0376ec: 910043FD  add      x29, sp, #0x10
//   0x0376f0: 710FCC7F  cmp      w3, #0x3f3
static inline uint64_t fde_func_0031_0x0376e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0376e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0032 | PC: 0x0377f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0032 | Địa chỉ PC: 0x0377f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0377f8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0377fc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x037800: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x037804: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0032_0x0377f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0377f8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0033 | PC: 0x037988 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0033 | Địa chỉ PC: 0x037988 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x037988: D10143FF  sub      sp, sp, #0x50
//   0x03798c: F9000BF7  str      x23, [sp, #0x10]
//   0x037990: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x037994: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0033_0x037988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037988ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0034 | PC: 0x037c24 | FDE: 0x148a38 | Size: 36 bytes
// Hàm #0034 | Địa chỉ PC: 0x037c24 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x037c24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x037c28: 910003FD  mov      x29, sp
//   0x037c2c: 94002581  bl       #0x41230
//   0x037c30: 94002593  bl       #0x4127c
static inline uint64_t fde_func_0034_0x037c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037c24ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #0035 | PC: 0x037c48 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0035 | Địa chỉ PC: 0x037c48 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x037c48: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x037c4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037c50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037c54: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0035_0x037c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037c48ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0036 | PC: 0x037d28 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0036 | Địa chỉ PC: 0x037d28 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x037d28: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x037d2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037d30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037d34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0036_0x037d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037d28ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0037 | PC: 0x037ddc | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0037 | Địa chỉ PC: 0x037ddc | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x037ddc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x037de0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037de4: 910043FD  add      x29, sp, #0x10
//   0x037de8: 5283A108  mov      w8, #0x1d08
static inline uint64_t fde_func_0037_0x037ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037ddcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0038 | PC: 0x037e48 | FDE: 0x148a38 | Size: 72 bytes
// Hàm #0038 | Địa chỉ PC: 0x037e48 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x037e48: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x037e4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037e50: 910043FD  add      x29, sp, #0x10
//   0x037e54: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0038_0x037e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037e48ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #0039 | PC: 0x037e90 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0039 | Địa chỉ PC: 0x037e90 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x037e90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x037e94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037e98: 910043FD  add      x29, sp, #0x10
//   0x037e9c: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0039_0x037e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037e90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0040 | PC: 0x037f34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0040 | Địa chỉ PC: 0x037f34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x037f34: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x037f38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037f3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037f40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0040_0x037f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037f34ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0041 | PC: 0x038400 | FDE: 0x148a38 | Size: 72 bytes
// Hàm #0041 | Địa chỉ PC: 0x038400 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x038400: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x038404: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038408: 910043FD  add      x29, sp, #0x10
//   0x03840c: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0041_0x038400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038400ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #0042 | PC: 0x038448 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #0042 | Địa chỉ PC: 0x038448 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x038448: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03844c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038450: 910043FD  add      x29, sp, #0x10
//   0x038454: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0042_0x038448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038448ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #0043 | PC: 0x03852c | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0043 | Địa chỉ PC: 0x03852c | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x03852c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x038530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038534: 910043FD  add      x29, sp, #0x10
//   0x038538: 528000C0  mov      w0, #6
static inline uint64_t fde_func_0043_0x03852c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03852cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0044 | PC: 0x0385f8 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #0044 | Địa chỉ PC: 0x0385f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0385f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0385fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038600: 910043FD  add      x29, sp, #0x10
//   0x038604: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0044_0x0385f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0385f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0045 | PC: 0x038678 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0045 | Địa chỉ PC: 0x038678 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x038678: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x03867c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x038680: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x038684: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0045_0x038678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038678ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0046 | PC: 0x0387ac | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0046 | Địa chỉ PC: 0x0387ac | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0387ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0387b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0387b4: 910043FD  add      x29, sp, #0x10
//   0x0387b8: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0046_0x0387ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0387acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0047 | PC: 0x038804 | FDE: 0x148a38 | Size: 72 bytes
// Hàm #0047 | Địa chỉ PC: 0x038804 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x038804: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x038808: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03880c: 910043FD  add      x29, sp, #0x10
//   0x038810: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_0047_0x038804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038804ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #0048 | PC: 0x03884c | FDE: 0x148a38 | Size: 208 bytes
// Hàm #0048 | Địa chỉ PC: 0x03884c | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x03884c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x038850: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x038854: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x038858: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0048_0x03884c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03884cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #0049 | PC: 0x03891c | FDE: 0x148a38 | Size: 220 bytes
// Hàm #0049 | Địa chỉ PC: 0x03891c | Địa chỉ FDE: 0x148a38 | Kích thước: 220 bytes
//   0x03891c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x038920: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x038924: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x038928: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0049_0x03891c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03891cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// Func #0050 | PC: 0x0389f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0050 | Địa chỉ PC: 0x0389f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0389f8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0389fc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x038a00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x038a04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0050_0x0389f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0389f8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0051 | PC: 0x038b34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0051 | Địa chỉ PC: 0x038b34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x038b34: D101C3FF  sub      sp, sp, #0x70
//   0x038b38: F9000BFB  str      x27, [sp, #0x10]
//   0x038b3c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x038b40: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0051_0x038b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038b34ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0052 | PC: 0x038d58 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0052 | Địa chỉ PC: 0x038d58 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x038d58: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x038d5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x038d60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x038d64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0052_0x038d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038d58ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0053 | PC: 0x038e04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0053 | Địa chỉ PC: 0x038e04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x038e04: D10243FF  sub      sp, sp, #0x90
//   0x038e08: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x038e0c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x038e10: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0053_0x038e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038e04ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0054 | PC: 0x038ff4 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0054 | Địa chỉ PC: 0x038ff4 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x038ff4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x038ff8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x038ffc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x039000: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0054_0x038ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038ff4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0055 | PC: 0x03906c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0055 | Địa chỉ PC: 0x03906c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03906c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x039070: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x039074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x039078: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0055_0x03906c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03906cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0056 | PC: 0x0391f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0056 | Địa chỉ PC: 0x0391f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0391f0: D101C3FF  sub      sp, sp, #0x70
//   0x0391f4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0391f8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0391fc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0056_0x0391f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0391f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0057 | PC: 0x039324 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0057 | Địa chỉ PC: 0x039324 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x039324: D10643FF  sub      sp, sp, #0x190
//   0x039328: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x03932c: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x039330: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_0057_0x039324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039324ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa9136ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0058 | PC: 0x0395d4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0058 | Địa chỉ PC: 0x0395d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0395d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0395d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0395dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0395e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0058_0x0395d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0395d4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0059 | PC: 0x039720 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0059 | Địa chỉ PC: 0x039720 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x039720: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x039724: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x039728: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03972c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0059_0x039720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039720ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0060 | PC: 0x039868 | FDE: 0x148a38 | Size: 256 bytes [JNI_OnLoad]
// Hàm #0060 | Địa chỉ PC: 0x039868 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x039868: D10103FF  sub      sp, sp, #0x40
//   0x03986c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x039870: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x039874: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0060_0x039868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039868ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0061 | PC: 0x039978 | FDE: 0x148a38 | Size: 72 bytes [JNI_OnUnload]
// Hàm #0061 | Địa chỉ PC: 0x039978 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x039978: D10083FF  sub      sp, sp, #0x20
//   0x03997c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x039980: 910043FD  add      x29, sp, #0x10
//   0x039984: F90007FF  str      xzr, [sp, #8]
static inline uint64_t fde_func_0061_0x039978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039978ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #0062 | PC: 0x0399c0 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #0062 | Địa chỉ PC: 0x0399c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0399c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0399c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0399c8: 910043FD  add      x29, sp, #0x10
//   0x0399cc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0062_0x0399c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0399c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #0063 | PC: 0x039aa8 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #0063 | Địa chỉ PC: 0x039aa8 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x039aa8: D10183FF  sub      sp, sp, #0x60
//   0x039aac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x039ab0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x039ab4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0063_0x039aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039aa8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0064 | PC: 0x039b50 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0064 | Địa chỉ PC: 0x039b50 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x039b50: D101C3FF  sub      sp, sp, #0x70
//   0x039b54: F9001BF7  str      x23, [sp, #0x30]
//   0x039b58: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x039b5c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0064_0x039b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039b50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0065 | PC: 0x039c18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0065 | Địa chỉ PC: 0x039c18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x039c18: D10103FF  sub      sp, sp, #0x40
//   0x039c1c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x039c20: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x039c24: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0065_0x039c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039c18ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0066 | PC: 0x039fe0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0066 | Địa chỉ PC: 0x039fe0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x039fe0: D10583FF  sub      sp, sp, #0x160
//   0x039fe4: F9008BFC  str      x28, [sp, #0x110]
//   0x039fe8: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x039fec: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0066_0x039fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039fe0ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0067 | PC: 0x03a2cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0067 | Địa chỉ PC: 0x03a2cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03a2cc: D10403FF  sub      sp, sp, #0x100
//   0x03a2d0: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x03a2d4: 9103C3FD  add      x29, sp, #0xf0
//   0x03a2d8: 928004E8  mov      x8, #-0x28
static inline uint64_t fde_func_0067_0x03a2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a2ccULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90f7bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0068 | PC: 0x03a40c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0068 | Địa chỉ PC: 0x03a40c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03a40c: D10583FF  sub      sp, sp, #0x160
//   0x03a410: A91167FC  stp      x28, x25, [sp, #0x110]
//   0x03a414: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x03a418: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0068_0x03a40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a40cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa91167fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0069 | PC: 0x03a7c4 | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0069 | Địa chỉ PC: 0x03a7c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x03a7c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03a7c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03a7cc: 910043FD  add      x29, sp, #0x10
//   0x03a7d0: 9100A014  add      x20, x0, #0x28
static inline uint64_t fde_func_0069_0x03a7c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a7c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0070 | PC: 0x03a830 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0070 | Địa chỉ PC: 0x03a830 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03a830: D10583FF  sub      sp, sp, #0x160
//   0x03a834: F9008BFC  str      x28, [sp, #0x110]
//   0x03a838: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x03a83c: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0070_0x03a830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a830ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0071 | PC: 0x03aba4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0071 | Địa chỉ PC: 0x03aba4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03aba4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x03aba8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x03abac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03abb0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0071_0x03aba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03aba4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0072 | PC: 0x03ad20 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0072 | Địa chỉ PC: 0x03ad20 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03ad20: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03ad24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ad28: 910043FD  add      x29, sp, #0x10
//   0x03ad2c: B0000908  adrp     x8, #0x15b000
static inline uint64_t fde_func_0072_0x03ad20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ad20ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0073 | PC: 0x03ae2c | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0073 | Địa chỉ PC: 0x03ae2c | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x03ae2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03ae30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ae34: 910043FD  add      x29, sp, #0x10
//   0x03ae38: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0073_0x03ae2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ae2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0074 | PC: 0x03ae8c | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0074 | Địa chỉ PC: 0x03ae8c | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x03ae8c: D101C3FF  sub      sp, sp, #0x70
//   0x03ae90: F9001BF7  str      x23, [sp, #0x30]
//   0x03ae94: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x03ae98: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0074_0x03ae8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ae8cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0075 | PC: 0x03af2c | FDE: 0x148a38 | Size: 196 bytes
// Hàm #0075 | Địa chỉ PC: 0x03af2c | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x03af2c: D10243FF  sub      sp, sp, #0x90
//   0x03af30: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x03af34: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x03af38: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0075_0x03af2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03af2cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0076 | PC: 0x03aff0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0076 | Địa chỉ PC: 0x03aff0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03aff0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x03aff4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03aff8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03affc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0076_0x03aff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03aff0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0077 | PC: 0x03b3f0 | FDE: 0x148a38 | Size: 72 bytes
// Hàm #0077 | Địa chỉ PC: 0x03b3f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x03b3f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03b3f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03b3f8: 910043FD  add      x29, sp, #0x10
//   0x03b3fc: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0077_0x03b3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b3f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #0078 | PC: 0x03b438 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0078 | Địa chỉ PC: 0x03b438 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x03b438: D10403FF  sub      sp, sp, #0x100
//   0x03b43c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x03b440: 9103C3FD  add      x29, sp, #0xf0
//   0x03b444: 928004E8  mov      x8, #-0x28
static inline uint64_t fde_func_0078_0x03b438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b438ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90f7bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0079 | PC: 0x03b4a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0079 | Địa chỉ PC: 0x03b4a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03b4a8: D10143FF  sub      sp, sp, #0x50
//   0x03b4ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03b4b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03b4b4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0079_0x03b4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b4a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0080 | PC: 0x03b780 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0080 | Địa chỉ PC: 0x03b780 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03b780: D10103FF  sub      sp, sp, #0x40
//   0x03b784: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03b788: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03b78c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0080_0x03b780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b780ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0081 | PC: 0x03b908 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0081 | Địa chỉ PC: 0x03b908 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03b908: D10103FF  sub      sp, sp, #0x40
//   0x03b90c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03b910: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03b914: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0081_0x03b908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b908ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0082 | PC: 0x03bb74 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0082 | Địa chỉ PC: 0x03bb74 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03bb74: D10203FF  sub      sp, sp, #0x80
//   0x03bb78: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x03bb7c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x03bb80: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0082_0x03bb74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03bb74ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0083 | PC: 0x03c0f8 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0083 | Địa chỉ PC: 0x03c0f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x03c0f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03c0fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03c100: 910043FD  add      x29, sp, #0x10
//   0x03c104: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0083_0x03c0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c0f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0084 | PC: 0x03c1a4 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0084 | Địa chỉ PC: 0x03c1a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x03c1a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03c1a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03c1ac: 910043FD  add      x29, sp, #0x10
//   0x03c1b0: 97FFE0A0  bl       #0x34430
static inline uint64_t fde_func_0084_0x03c1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c1a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0085 | PC: 0x03c218 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0085 | Địa chỉ PC: 0x03c218 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03c218: D10543FF  sub      sp, sp, #0x150
//   0x03c21c: A9115FFC  stp      x28, x23, [sp, #0x110]
//   0x03c220: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x03c224: A9134FF4  stp      x20, x19, [sp, #0x130]
static inline uint64_t fde_func_0085_0x03c218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c218ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9115ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0086 | PC: 0x03c35c | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0086 | Địa chỉ PC: 0x03c35c | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x03c35c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03c360: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03c364: 910043FD  add      x29, sp, #0x10
//   0x03c368: B40001E1  cbz      x1, #0x3c3a4
static inline uint64_t fde_func_0086_0x03c35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c35cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0087 | PC: 0x03c450 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0087 | Địa chỉ PC: 0x03c450 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x03c450: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x03c454: 910003FD  mov      x29, sp
//   0x03c458: B4000180  cbz      x0, #0x3c488
//   0x03c45c: 7100085F  cmp      w2, #2
static inline uint64_t fde_func_0087_0x03c450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c450ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0088 | PC: 0x03c51c | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0088 | Địa chỉ PC: 0x03c51c | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x03c51c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03c520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03c524: 910043FD  add      x29, sp, #0x10
//   0x03c528: F00008E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0088_0x03c51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c51cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0089 | PC: 0x03c5b8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0089 | Địa chỉ PC: 0x03c5b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x03c5b8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x03c5bc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x03c5c0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03c5c4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0089_0x03c5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c5b8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0090 | PC: 0x03c5d4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0090 | Địa chỉ PC: 0x03c5d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03c5d4: D10BC3FF  sub      sp, sp, #0x2f0
//   0x03c5d8: AA1F03F8  mov      x24, xzr
//   0x03c5dc: B4003E40  cbz      x0, #0x3cda4
//   0x03c5e0: 2A0103F5  mov      w21, w1
static inline uint64_t fde_func_0090_0x03c5d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c5d4ULL ^ (static_cast<uint64_t>(0xd10bc3ffULL) << 13);
    acc = (acc + a1 + 0xaa1f03f8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0091 | PC: 0x03ceb8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0091 | Địa chỉ PC: 0x03ceb8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03ceb8: D10283FF  sub      sp, sp, #0xa0
//   0x03cebc: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03cec0: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x03cec4: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0091_0x03ceb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ceb8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0092 | PC: 0x03d114 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0092 | Địa chỉ PC: 0x03d114 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03d114: D10183FF  sub      sp, sp, #0x60
//   0x03d118: F90013F7  str      x23, [sp, #0x20]
//   0x03d11c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03d120: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0092_0x03d114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d114ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0093 | PC: 0x03d268 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0093 | Địa chỉ PC: 0x03d268 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03d268: D10183FF  sub      sp, sp, #0x60
//   0x03d26c: F90013F7  str      x23, [sp, #0x20]
//   0x03d270: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03d274: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0093_0x03d268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d268ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0094 | PC: 0x03d5d4 | FDE: 0x148a38 | Size: 172 bytes [_ZN3com2ss5ttmio10MDLManager24registerIoCtrlDownloaderERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEPFNS3_10shared_ptrINS1_16MIOVodNetAdapterEEEmEPFvPSD_E]
// Hàm #0094 | Địa chỉ PC: 0x03d5d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x03d5d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03d5d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03d5dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03d5e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0094_0x03d5d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d5d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0095 | PC: 0x03d680 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0095 | Địa chỉ PC: 0x03d680 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03d680: D10703FF  sub      sp, sp, #0x1c0
//   0x03d684: F900BBFC  str      x28, [sp, #0x170]
//   0x03d688: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x03d68c: A91957F6  stp      x22, x21, [sp, #0x190]
static inline uint64_t fde_func_0095_0x03d680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d680ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xf900bbfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0096 | PC: 0x03d950 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0096 | Địa chỉ PC: 0x03d950 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03d950: D10283FF  sub      sp, sp, #0xa0
//   0x03d954: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x03d958: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03d95c: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0096_0x03d950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d950ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0097 | PC: 0x03df50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0097 | Địa chỉ PC: 0x03df50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03df50: D10203FF  sub      sp, sp, #0x80
//   0x03df54: F90033F3  str      x19, [sp, #0x60]
//   0x03df58: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x03df5c: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_0097_0x03df50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03df50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0098 | PC: 0x03e15c | FDE: 0x148a38 | Size: 172 bytes [_ZN3com2ss5ttmio10MDLManager29registerTTKMediaNetDownloaderERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEPFNS3_10shared_ptrINS1_16MIOVodNetAdapterEEEmEPFvPSD_E]
// Hàm #0098 | Địa chỉ PC: 0x03e15c | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x03e15c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03e160: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03e164: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03e168: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0098_0x03e15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e15cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0099 | PC: 0x03e208 | FDE: 0x148a38 | Size: 120 bytes [_ZN3com2ss5ttmio10MDLManager36registerTTKMediaNetDownloaderFactoryEPNS1_31MDLTTKMediaNetDownloaderFactoryE]
// Hàm #0099 | Địa chỉ PC: 0x03e208 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x03e208: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03e20c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e210: 910043FD  add      x29, sp, #0x10
//   0x03e214: B00008E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0099_0x03e208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e208ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0100 | PC: 0x03e280 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio10MDLManager21registerIoCtrlFactoryEPNS1_20MDLIoTaskCtrlFactoryE]
// Hàm #0100 | Địa chỉ PC: 0x03e280 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03e280: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03e284: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e288: 910043FD  add      x29, sp, #0x10
//   0x03e28c: B00008E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0100_0x03e280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e280ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0101 | PC: 0x03e3ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0101 | Địa chỉ PC: 0x03e3ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03e3ac: D10243FF  sub      sp, sp, #0x90
//   0x03e3b0: F9002BF7  str      x23, [sp, #0x50]
//   0x03e3b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x03e3b8: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0101_0x03e3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e3acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0102 | PC: 0x03e5ec | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0102 | Địa chỉ PC: 0x03e5ec | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x03e5ec: D10103FF  sub      sp, sp, #0x40
//   0x03e5f0: F90013F3  str      x19, [sp, #0x20]
//   0x03e5f4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03e5f8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0102_0x03e5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e5ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0103 | PC: 0x03e6a0 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #0103 | Địa chỉ PC: 0x03e6a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x03e6a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03e6a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e6a8: 910043FD  add      x29, sp, #0x10
//   0x03e6ac: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_0103_0x03e6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e6a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0104 | PC: 0x03e758 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0104 | Địa chỉ PC: 0x03e758 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03e758: D10103FF  sub      sp, sp, #0x40
//   0x03e75c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03e760: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03e764: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0104_0x03e758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e758ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0105 | PC: 0x03e8a4 | FDE: 0x148a38 | Size: 36 bytes
// Hàm #0105 | Địa chỉ PC: 0x03e8a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x03e8a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x03e8a8: 910003FD  mov      x29, sp
//   0x03e8ac: F9402400  ldr      x0, [x0, #0x48]
//   0x03e8b0: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0105_0x03e8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e8a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #0106 | PC: 0x03e8c8 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0106 | Địa chỉ PC: 0x03e8c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x03e8c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03e8cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e8d0: 910043FD  add      x29, sp, #0x10
//   0x03e8d4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0106_0x03e8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e8c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0107 | PC: 0x03e93c | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0107 | Địa chỉ PC: 0x03e93c | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x03e93c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03e940: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e944: 910043FD  add      x29, sp, #0x10
//   0x03e948: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0107_0x03e93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e93cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0108 | PC: 0x03e9a8 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0108 | Địa chỉ PC: 0x03e9a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x03e9a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03e9ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e9b0: 910043FD  add      x29, sp, #0x10
//   0x03e9b4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0108_0x03e9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e9a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0109 | PC: 0x03ea04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0109 | Địa chỉ PC: 0x03ea04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03ea04: D10183FF  sub      sp, sp, #0x60
//   0x03ea08: F9001BF5  str      x21, [sp, #0x30]
//   0x03ea0c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03ea10: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0109_0x03ea04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ea04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0110 | PC: 0x03ebac | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0110 | Địa chỉ PC: 0x03ebac | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x03ebac: D10143FF  sub      sp, sp, #0x50
//   0x03ebb0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03ebb4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03ebb8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0110_0x03ebac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ebacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0111 | PC: 0x03ec24 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0111 | Địa chỉ PC: 0x03ec24 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x03ec24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03ec28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ec2c: 910043FD  add      x29, sp, #0x10
//   0x03ec30: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0111_0x03ec24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ec24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0112 | PC: 0x03ec7c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0112 | Địa chỉ PC: 0x03ec7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03ec7c: D10183FF  sub      sp, sp, #0x60
//   0x03ec80: F9001BF5  str      x21, [sp, #0x30]
//   0x03ec84: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03ec88: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0112_0x03ec7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ec7cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0113 | PC: 0x03ede8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0113 | Địa chỉ PC: 0x03ede8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03ede8: D10683FF  sub      sp, sp, #0x1a0
//   0x03edec: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x03edf0: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x03edf4: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_0113_0x03ede8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ede8ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0114 | PC: 0x03f220 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0114 | Địa chỉ PC: 0x03f220 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03f220: D10183FF  sub      sp, sp, #0x60
//   0x03f224: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03f228: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03f22c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0114_0x03f220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f220ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0115 | PC: 0x03f35c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0115 | Địa chỉ PC: 0x03f35c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03f35c: D10183FF  sub      sp, sp, #0x60
//   0x03f360: A900E7E0  stp      x0, x25, [sp, #8]
//   0x03f364: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03f368: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0115_0x03f35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f35cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa900e7e0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0116 | PC: 0x03f4bc | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0116 | Địa chỉ PC: 0x03f4bc | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x03f4bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03f4c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03f4c4: 910043FD  add      x29, sp, #0x10
//   0x03f4c8: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0116_0x03f4bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f4bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0117 | PC: 0x03f4fc | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0117 | Địa chỉ PC: 0x03f4fc | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x03f4fc: D10103FF  sub      sp, sp, #0x40
//   0x03f500: F90013F3  str      x19, [sp, #0x20]
//   0x03f504: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03f508: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0117_0x03f4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f4fcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0118 | PC: 0x03f564 | FDE: 0x148a38 | Size: 216 bytes
// Hàm #0118 | Địa chỉ PC: 0x03f564 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x03f564: D10183FF  sub      sp, sp, #0x60
//   0x03f568: F9001BF5  str      x21, [sp, #0x30]
//   0x03f56c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03f570: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0118_0x03f564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f564ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #0119 | PC: 0x03f63c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0119 | Địa chỉ PC: 0x03f63c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x03f63c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x03f640: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x03f644: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03f648: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0119_0x03f63c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f63cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0120 | PC: 0x03f658 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0120 | Địa chỉ PC: 0x03f658 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03f658: D10AC3FF  sub      sp, sp, #0x2b0
//   0x03f65c: B90037E6  str      w6, [sp, #0x34]
//   0x03f660: F90017E5  str      x5, [sp, #0x28]
//   0x03f664: A90087E0  stp      x0, x1, [sp, #8]
static inline uint64_t fde_func_0120_0x03f658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f658ULL ^ (static_cast<uint64_t>(0xd10ac3ffULL) << 13);
    acc = (acc + a1 + 0xb90037e6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0121 | PC: 0x03fc28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0121 | Địa chỉ PC: 0x03fc28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x03fc28: D10383FF  sub      sp, sp, #0xe0
//   0x03fc2c: F90043FB  str      x27, [sp, #0x80]
//   0x03fc30: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x03fc34: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0121_0x03fc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03fc28ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90043fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0122 | PC: 0x03ff6c | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0122 | Địa chỉ PC: 0x03ff6c | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x03ff6c: D10103FF  sub      sp, sp, #0x40
//   0x03ff70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03ff74: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03ff78: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0122_0x03ff6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ff6cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0123 | PC: 0x03ffe0 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0123 | Địa chỉ PC: 0x03ffe0 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x03ffe0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03ffe4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ffe8: 910043FD  add      x29, sp, #0x10
//   0x03ffec: 900008E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0123_0x03ffe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ffe0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0124 | PC: 0x040058 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0124 | Địa chỉ PC: 0x040058 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040058: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04005c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x040060: 910043FD  add      x29, sp, #0x10
//   0x040064: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0124_0x040058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040058ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0125 | PC: 0x0401c8 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #0125 | Địa chỉ PC: 0x0401c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0401c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0401cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0401d0: 910043FD  add      x29, sp, #0x10
//   0x0401d4: F00008C8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0125_0x0401c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0401c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #0126 | PC: 0x040248 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0126 | Địa chỉ PC: 0x040248 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040248: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04024c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x040250: 910043FD  add      x29, sp, #0x10
//   0x040254: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0126_0x040248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040248ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0127 | PC: 0x040498 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0127 | Địa chỉ PC: 0x040498 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040498: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04049c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0404a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0404a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0127_0x040498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040498ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0128 | PC: 0x040718 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0128 | Địa chỉ PC: 0x040718 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040718: D10183FF  sub      sp, sp, #0x60
//   0x04071c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x040720: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x040724: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0128_0x040718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040718ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0129 | PC: 0x040ac4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0129 | Địa chỉ PC: 0x040ac4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040ac4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x040ac8: 910003FD  mov      x29, sp
//   0x040acc: 39400008  ldrb     w8, [x0]
//   0x040ad0: 37000068  tbnz     w8, #0, #0x40adc
static inline uint64_t fde_func_0129_0x040ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040ac4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0130 | PC: 0x040bec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0130 | Địa chỉ PC: 0x040bec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040bec: D10183FF  sub      sp, sp, #0x60
//   0x040bf0: A900E7E0  stp      x0, x25, [sp, #8]
//   0x040bf4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x040bf8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0130_0x040bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040becULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa900e7e0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0131 | PC: 0x040d60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0131 | Địa chỉ PC: 0x040d60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040d60: D101C3FF  sub      sp, sp, #0x70
//   0x040d64: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x040d68: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x040d6c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0131_0x040d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040d60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0132 | PC: 0x040f60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0132 | Địa chỉ PC: 0x040f60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x040f60: D100C3FF  sub      sp, sp, #0x30
//   0x040f64: F9000BF3  str      x19, [sp, #0x10]
//   0x040f68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x040f6c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0132_0x040f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040f60ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0133 | PC: 0x04128c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0133 | Địa chỉ PC: 0x04128c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04128c: D101C3FF  sub      sp, sp, #0x70
//   0x041290: F90013F9  str      x25, [sp, #0x20]
//   0x041294: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x041298: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0133_0x04128c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04128cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0134 | PC: 0x0416b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0134 | Địa chỉ PC: 0x0416b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0416b8: D10203FF  sub      sp, sp, #0x80
//   0x0416bc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0416c0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0416c4: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0134_0x0416b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0416b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0135 | PC: 0x041a5c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0135 | Địa chỉ PC: 0x041a5c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x041a5c: D10483FF  sub      sp, sp, #0x120
//   0x041a60: F9007BFC  str      x28, [sp, #0xf0]
//   0x041a64: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x041a68: A9117BFD  stp      x29, x30, [sp, #0x110]
static inline uint64_t fde_func_0135_0x041a5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041a5cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0136 | PC: 0x0420a0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0136 | Địa chỉ PC: 0x0420a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0420a0: D101C3FF  sub      sp, sp, #0x70
//   0x0420a4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0420a8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0420ac: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0136_0x0420a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0420a0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0137 | PC: 0x042220 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0137 | Địa chỉ PC: 0x042220 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x042220: D10183FF  sub      sp, sp, #0x60
//   0x042224: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x042228: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x04222c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0137_0x042220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042220ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0138 | PC: 0x0422ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0138 | Địa chỉ PC: 0x0422ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0422ec: D10243FF  sub      sp, sp, #0x90
//   0x0422f0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0422f4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0422f8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0138_0x0422ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0422ecULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0139 | PC: 0x042564 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0139 | Địa chỉ PC: 0x042564 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x042564: D10183FF  sub      sp, sp, #0x60
//   0x042568: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04256c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x042570: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0139_0x042564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042564ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0140 | PC: 0x0428f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0140 | Địa chỉ PC: 0x0428f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0428f8: D10283FF  sub      sp, sp, #0xa0
//   0x0428fc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x042900: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x042904: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0140_0x0428f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0428f8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0141 | PC: 0x042c64 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0141 | Địa chỉ PC: 0x042c64 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x042c64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x042c68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x042c6c: 910043FD  add      x29, sp, #0x10
//   0x042c70: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0141_0x042c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042c64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0142 | PC: 0x042d2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0142 | Địa chỉ PC: 0x042d2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x042d2c: D10243FF  sub      sp, sp, #0x90
//   0x042d30: F90023F9  str      x25, [sp, #0x40]
//   0x042d34: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x042d38: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0142_0x042d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042d2cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0143 | PC: 0x0430e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0143 | Địa chỉ PC: 0x0430e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0430e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0430e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0430e8: 910043FD  add      x29, sp, #0x10
//   0x0430ec: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0143_0x0430e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0430e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0144 | PC: 0x04330c | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0144 | Địa chỉ PC: 0x04330c | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x04330c: D10103FF  sub      sp, sp, #0x40
//   0x043310: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x043314: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x043318: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0144_0x04330c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04330cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0145 | PC: 0x0433a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0145 | Địa chỉ PC: 0x0433a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0433a8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0433ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0433b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0433b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0145_0x0433a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0433a8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0146 | PC: 0x0436b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0146 | Địa chỉ PC: 0x0436b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0436b8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0436bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0436c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0436c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0146_0x0436b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0436b8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0147 | PC: 0x043f68 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0147 | Địa chỉ PC: 0x043f68 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x043f68: D10143FF  sub      sp, sp, #0x50
//   0x043f6c: F90013F5  str      x21, [sp, #0x20]
//   0x043f70: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x043f74: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0147_0x043f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043f68ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0148 | PC: 0x044114 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0148 | Địa chỉ PC: 0x044114 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x044114: D10143FF  sub      sp, sp, #0x50
//   0x044118: F9001BF3  str      x19, [sp, #0x30]
//   0x04411c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x044120: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0148_0x044114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044114ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0149 | PC: 0x0441d0 | FDE: 0x148a38 | Size: 176 bytes
// Hàm #0149 | Địa chỉ PC: 0x0441d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x0441d0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0441d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0441d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0441dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0149_0x0441d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0441d0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #0150 | PC: 0x044280 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #0150 | Địa chỉ PC: 0x044280 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x044280: D10143FF  sub      sp, sp, #0x50
//   0x044284: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x044288: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x04428c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0150_0x044280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044280ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0151 | PC: 0x044338 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0151 | Địa chỉ PC: 0x044338 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x044338: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04433c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x044340: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x044344: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0151_0x044338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044338ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0152 | PC: 0x044354 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0152 | Địa chỉ PC: 0x044354 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x044354: D13603FF  sub      sp, sp, #0xd80
//   0x044358: D53BD05A  mrs      x26, tpidr_el0
//   0x04435c: F9401748  ldr      x8, [x26, #0x28]
//   0x044360: AA0103F6  mov      x22, x1
static inline uint64_t fde_func_0152_0x044354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044354ULL ^ (static_cast<uint64_t>(0xd13603ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0153 | PC: 0x044ff0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0153 | Địa chỉ PC: 0x044ff0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x044ff0: D10183FF  sub      sp, sp, #0x60
//   0x044ff4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x044ff8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x044ffc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0153_0x044ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044ff0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0154 | PC: 0x045498 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0154 | Địa chỉ PC: 0x045498 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x045498: D10243FF  sub      sp, sp, #0x90
//   0x04549c: F90033F5  str      x21, [sp, #0x60]
//   0x0454a0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0454a4: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0154_0x045498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045498ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0155 | PC: 0x0455c8 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0155 | Địa chỉ PC: 0x0455c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0455c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0455cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0455d0: 910043FD  add      x29, sp, #0x10
//   0x0455d4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0155_0x0455c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0455c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0156 | PC: 0x045690 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0156 | Địa chỉ PC: 0x045690 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x045690: D10583FF  sub      sp, sp, #0x160
//   0x045694: F9008BFC  str      x28, [sp, #0x110]
//   0x045698: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x04569c: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0156_0x045690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045690ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0157 | PC: 0x045c38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0157 | Địa chỉ PC: 0x045c38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x045c38: D10543FF  sub      sp, sp, #0x150
//   0x045c3c: F9008BFC  str      x28, [sp, #0x110]
//   0x045c40: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x045c44: A9134FF4  stp      x20, x19, [sp, #0x130]
static inline uint64_t fde_func_0157_0x045c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045c38ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0158 | PC: 0x045e50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0158 | Địa chỉ PC: 0x045e50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x045e50: D10403FF  sub      sp, sp, #0x100
//   0x045e54: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x045e58: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x045e5c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0158_0x045e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045e50ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0159 | PC: 0x04613c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0159 | Địa chỉ PC: 0x04613c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04613c: D10403FF  sub      sp, sp, #0x100
//   0x046140: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x046144: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x046148: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0159_0x04613c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04613cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0160 | PC: 0x046330 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0160 | Địa chỉ PC: 0x046330 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x046330: D105C3FF  sub      sp, sp, #0x170
//   0x046334: F9009BFC  str      x28, [sp, #0x130]
//   0x046338: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x04633c: A9154FF4  stp      x20, x19, [sp, #0x150]
static inline uint64_t fde_func_0160_0x046330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046330ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0161 | PC: 0x046594 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0161 | Địa chỉ PC: 0x046594 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x046594: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x046598: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04659c: 910043FD  add      x29, sp, #0x10
//   0x0465a0: 394A2008  ldrb     w8, [x0, #0x288]
static inline uint64_t fde_func_0161_0x046594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046594ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0162 | PC: 0x0465fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0162 | Địa chỉ PC: 0x0465fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0465fc: D10383FF  sub      sp, sp, #0xe0
//   0x046600: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x046604: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x046608: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0162_0x0465fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0465fcULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90a5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0163 | PC: 0x04695c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0163 | Địa chỉ PC: 0x04695c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04695c: D10143FF  sub      sp, sp, #0x50
//   0x046960: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x046964: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x046968: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0163_0x04695c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04695cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0164 | PC: 0x046abc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0164 | Địa chỉ PC: 0x046abc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x046abc: D103C3FF  sub      sp, sp, #0xf0
//   0x046ac0: F9004BFB  str      x27, [sp, #0x90]
//   0x046ac4: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x046ac8: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0164_0x046abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046abcULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9004bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0165 | PC: 0x046f18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0165 | Địa chỉ PC: 0x046f18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x046f18: D107C3FF  sub      sp, sp, #0x1f0
//   0x046f1c: A91B5FFC  stp      x28, x23, [sp, #0x1b0]
//   0x046f20: A91C57F6  stp      x22, x21, [sp, #0x1c0]
//   0x046f24: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
static inline uint64_t fde_func_0165_0x046f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046f18ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91b5ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0166 | PC: 0x047724 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0166 | Địa chỉ PC: 0x047724 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x047724: D10743FF  sub      sp, sp, #0x1d0
//   0x047728: A91867FC  stp      x28, x25, [sp, #0x180]
//   0x04772c: A9195FF8  stp      x24, x23, [sp, #0x190]
//   0x047730: A91A57F6  stp      x22, x21, [sp, #0x1a0]
static inline uint64_t fde_func_0166_0x047724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047724ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa91867fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0167 | PC: 0x047a9c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0167 | Địa chỉ PC: 0x047a9c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x047a9c: D10243FF  sub      sp, sp, #0x90
//   0x047aa0: F9001BFB  str      x27, [sp, #0x30]
//   0x047aa4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x047aa8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0167_0x047a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047a9cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0168 | PC: 0x047e50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0168 | Địa chỉ PC: 0x047e50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x047e50: D10283FF  sub      sp, sp, #0xa0
//   0x047e54: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x047e58: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x047e5c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0168_0x047e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047e50ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0169 | PC: 0x048968 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0169 | Địa chỉ PC: 0x048968 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x048968: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04896c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x048970: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x048974: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0169_0x048968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048968ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0170 | PC: 0x048b00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0170 | Địa chỉ PC: 0x048b00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x048b00: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x048b04: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x048b08: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x048b0c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0170_0x048b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048b00ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0171 | PC: 0x048cac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0171 | Địa chỉ PC: 0x048cac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x048cac: D10203FF  sub      sp, sp, #0x80
//   0x048cb0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x048cb4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x048cb8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0171_0x048cac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048cacULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0172 | PC: 0x048fc8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0172 | Địa chỉ PC: 0x048fc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x048fc8: D101C3FF  sub      sp, sp, #0x70
//   0x048fcc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x048fd0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x048fd4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0172_0x048fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048fc8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0173 | PC: 0x04925c | FDE: 0x148a38 | Size: 52 bytes
// Hàm #0173 | Địa chỉ PC: 0x04925c | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x04925c: D10083FF  sub      sp, sp, #0x20
//   0x049260: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049264: 910043FD  add      x29, sp, #0x10
//   0x049268: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_0173_0x04925c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04925cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #0174 | PC: 0x049290 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0174 | Địa chỉ PC: 0x049290 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x049290: D10143FF  sub      sp, sp, #0x50
//   0x049294: F9000BF7  str      x23, [sp, #0x10]
//   0x049298: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04929c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0174_0x049290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049290ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0175 | PC: 0x049690 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0175 | Địa chỉ PC: 0x049690 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x049690: D101C3FF  sub      sp, sp, #0x70
//   0x049694: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x049698: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04969c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0175_0x049690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049690ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0176 | PC: 0x049918 | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0176 | Địa chỉ PC: 0x049918 | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x049918: D10143FF  sub      sp, sp, #0x50
//   0x04991c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x049920: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x049924: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0176_0x049918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049918ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0177 | PC: 0x049a0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0177 | Địa chỉ PC: 0x049a0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x049a0c: D10303FF  sub      sp, sp, #0xc0
//   0x049a10: F9003BF9  str      x25, [sp, #0x70]
//   0x049a14: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x049a18: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0177_0x049a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049a0cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0178 | PC: 0x049b64 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0178 | Địa chỉ PC: 0x049b64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x049b64: D10103FF  sub      sp, sp, #0x40
//   0x049b68: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x049b6c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x049b70: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0178_0x049b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049b64ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0179 | PC: 0x049cc0 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0179 | Địa chỉ PC: 0x049cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x049cc0: D10083FF  sub      sp, sp, #0x20
//   0x049cc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049cc8: 910043FD  add      x29, sp, #0x10
//   0x049ccc: F9403008  ldr      x8, [x0, #0x60]
static inline uint64_t fde_func_0179_0x049cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049cc0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0180 | PC: 0x049d24 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #0180 | Địa chỉ PC: 0x049d24 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x049d24: D10083FF  sub      sp, sp, #0x20
//   0x049d28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049d2c: 910043FD  add      x29, sp, #0x10
//   0x049d30: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_0180_0x049d24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049d24ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #0181 | PC: 0x049d84 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0181 | Địa chỉ PC: 0x049d84 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x049d84: D10083FF  sub      sp, sp, #0x20
//   0x049d88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049d8c: 910043FD  add      x29, sp, #0x10
//   0x049d90: 781FC3A1  sturh    w1, [x29, #-4]
static inline uint64_t fde_func_0181_0x049d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049d84ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0182 | PC: 0x049dc4 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #0182 | Địa chỉ PC: 0x049dc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x049dc4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x049dc8: 910003FD  mov      x29, sp
//   0x049dcc: 97FFA881  bl       #0x33fd0
//   0x049dd0: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_0182_0x049dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049dc4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #0183 | PC: 0x049e2c | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0183 | Địa chỉ PC: 0x049e2c | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x049e2c: D10083FF  sub      sp, sp, #0x20
//   0x049e30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049e34: 910043FD  add      x29, sp, #0x10
//   0x049e38: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0183_0x049e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049e2cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0184 | PC: 0x049ed0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0184 | Địa chỉ PC: 0x049ed0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x049ed0: D10143FF  sub      sp, sp, #0x50
//   0x049ed4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x049ed8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x049edc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0184_0x049ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049ed0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0185 | PC: 0x04a260 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0185 | Địa chỉ PC: 0x04a260 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x04a260: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04a264: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04a268: 910043FD  add      x29, sp, #0x10
//   0x04a26c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0185_0x04a260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a260ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0186 | PC: 0x04a2ec | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0186 | Địa chỉ PC: 0x04a2ec | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x04a2ec: D10103FF  sub      sp, sp, #0x40
//   0x04a2f0: F90013F3  str      x19, [sp, #0x20]
//   0x04a2f4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x04a2f8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0186_0x04a2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a2ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0187 | PC: 0x04a344 | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0187 | Địa chỉ PC: 0x04a344 | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x04a344: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04a348: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04a34c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04a350: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0187_0x04a344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a344ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0188 | PC: 0x04a3b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0188 | Địa chỉ PC: 0x04a3b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04a3b0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04a3b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04a3b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04a3bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0188_0x04a3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a3b0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0189 | PC: 0x04a4c8 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0189 | Địa chỉ PC: 0x04a4c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x04a4c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04a4cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04a4d0: 910043FD  add      x29, sp, #0x10
//   0x04a4d4: D37CFC28  lsr      x8, x1, #0x3c
static inline uint64_t fde_func_0189_0x04a4c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a4c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0190 | PC: 0x04a508 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0190 | Địa chỉ PC: 0x04a508 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04a508: D10183FF  sub      sp, sp, #0x60
//   0x04a50c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x04a510: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04a514: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0190_0x04a508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a508ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0191 | PC: 0x04a700 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0191 | Địa chỉ PC: 0x04a700 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04a700: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04a704: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04a708: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04a70c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0191_0x04a700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a700ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0192 | PC: 0x04a8ec | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0192 | Địa chỉ PC: 0x04a8ec | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x04a8ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04a8f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04a8f4: 910043FD  add      x29, sp, #0x10
//   0x04a8f8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0192_0x04a8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a8ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0193 | PC: 0x04a958 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0193 | Địa chỉ PC: 0x04a958 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x04a958: D10103FF  sub      sp, sp, #0x40
//   0x04a95c: F90013F3  str      x19, [sp, #0x20]
//   0x04a960: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x04a964: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0193_0x04a958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a958ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0194 | PC: 0x04a9b0 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0194 | Địa chỉ PC: 0x04a9b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x04a9b0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04a9b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04a9b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04a9bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0194_0x04a9b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a9b0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0195 | PC: 0x04aa90 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0195 | Địa chỉ PC: 0x04aa90 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x04aa90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04aa94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04aa98: 910043FD  add      x29, sp, #0x10
//   0x04aa9c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0195_0x04aa90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04aa90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0196 | PC: 0x04ab18 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #0196 | Địa chỉ PC: 0x04ab18 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x04ab18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04ab1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04ab20: 910043FD  add      x29, sp, #0x10
//   0x04ab24: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0196_0x04ab18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ab18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #0197 | PC: 0x04ab68 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #0197 | Địa chỉ PC: 0x04ab68 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x04ab68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04ab6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04ab70: 910043FD  add      x29, sp, #0x10
//   0x04ab74: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0197_0x04ab68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ab68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #0198 | PC: 0x04abf8 | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0198 | Địa chỉ PC: 0x04abf8 | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x04abf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04abfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04ac00: 910043FD  add      x29, sp, #0x10
//   0x04ac04: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0198_0x04abf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04abf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0199 | PC: 0x04ac64 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0199 | Địa chỉ PC: 0x04ac64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04ac64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04ac68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04ac6c: 910043FD  add      x29, sp, #0x10
//   0x04ac70: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0199_0x04ac64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ac64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0200 | PC: 0x04ae1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0200 | Địa chỉ PC: 0x04ae1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04ae1c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04ae20: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ae24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ae28: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0200_0x04ae1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ae1cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0201 | PC: 0x04b050 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0201 | Địa chỉ PC: 0x04b050 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04b050: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04b054: 910003FD  mov      x29, sp
//   0x04b058: F9400400  ldr      x0, [x0, #8]
//   0x04b05c: 97FFE7E5  bl       #0x44ff0
static inline uint64_t fde_func_0201_0x04b050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b050ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0202 | PC: 0x04b0f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0202 | Địa chỉ PC: 0x04b0f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04b0f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04b0f4: 910003FD  mov      x29, sp
//   0x04b0f8: F9400400  ldr      x0, [x0, #8]
//   0x04b0fc: 97FFE7BD  bl       #0x44ff0
static inline uint64_t fde_func_0202_0x04b0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b0f0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0203 | PC: 0x04b2dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0203 | Địa chỉ PC: 0x04b2dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04b2dc: D10083FF  sub      sp, sp, #0x20
//   0x04b2e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04b2e4: 910043FD  add      x29, sp, #0x10
//   0x04b2e8: F9400048  ldr      x8, [x2]
static inline uint64_t fde_func_0203_0x04b2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b2dcULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0204 | PC: 0x04b4cc | FDE: 0x148a38 | Size: 200 bytes
// Hàm #0204 | Địa chỉ PC: 0x04b4cc | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x04b4cc: D10083FF  sub      sp, sp, #0x20
//   0x04b4d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04b4d4: 910043FD  add      x29, sp, #0x10
//   0x04b4d8: F9400048  ldr      x8, [x2]
static inline uint64_t fde_func_0204_0x04b4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b4ccULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #0205 | PC: 0x04b594 | FDE: 0x148a38 | Size: 240 bytes
// Hàm #0205 | Địa chỉ PC: 0x04b594 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x04b594: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04b598: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04b59c: 910043FD  add      x29, sp, #0x10
//   0x04b5a0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0205_0x04b594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b594ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #0206 | PC: 0x04b684 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0206 | Địa chỉ PC: 0x04b684 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04b684: D10183FF  sub      sp, sp, #0x60
//   0x04b688: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04b68c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04b690: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0206_0x04b684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b684ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0207 | PC: 0x04ba10 | FDE: 0x148a38 | Size: 240 bytes
// Hàm #0207 | Địa chỉ PC: 0x04ba10 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x04ba10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04ba14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04ba18: 910043FD  add      x29, sp, #0x10
//   0x04ba1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0207_0x04ba10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ba10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #0208 | PC: 0x04bb00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0208 | Địa chỉ PC: 0x04bb00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04bb00: D10183FF  sub      sp, sp, #0x60
//   0x04bb04: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04bb08: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04bb0c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0208_0x04bb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04bb00ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0209 | PC: 0x04be10 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0209 | Địa chỉ PC: 0x04be10 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x04be10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04be14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04be18: 910043FD  add      x29, sp, #0x10
//   0x04be1c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0209_0x04be10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04be10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0210 | PC: 0x04be94 | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0210 | Địa chỉ PC: 0x04be94 | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x04be94: D10103FF  sub      sp, sp, #0x40
//   0x04be98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04be9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04bea0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0210_0x04be94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04be94ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0211 | PC: 0x04bf30 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0211 | Địa chỉ PC: 0x04bf30 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04bf30: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04bf34: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04bf38: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04bf3c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0211_0x04bf30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04bf30ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0212 | PC: 0x04c0a8 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0212 | Địa chỉ PC: 0x04c0a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x04c0a8: D10103FF  sub      sp, sp, #0x40
//   0x04c0ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04c0b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04c0b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0212_0x04c0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c0a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0213 | PC: 0x04c130 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0213 | Địa chỉ PC: 0x04c130 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04c130: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04c134: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04c138: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04c13c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0213_0x04c130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c130ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0214 | PC: 0x04c3a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0214 | Địa chỉ PC: 0x04c3a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04c3a8: D101C3FF  sub      sp, sp, #0x70
//   0x04c3ac: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04c3b0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04c3b4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0214_0x04c3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c3a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0215 | PC: 0x04c6b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0215 | Địa chỉ PC: 0x04c6b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04c6b4: D101C3FF  sub      sp, sp, #0x70
//   0x04c6b8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04c6bc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04c6c0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0215_0x04c6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c6b4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0216 | PC: 0x04c9f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0216 | Địa chỉ PC: 0x04c9f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04c9f4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04c9f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04c9fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ca00: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0216_0x04c9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c9f4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0217 | PC: 0x04cc28 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0217 | Địa chỉ PC: 0x04cc28 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x04cc28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04cc2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04cc30: 910043FD  add      x29, sp, #0x10
//   0x04cc34: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0217_0x04cc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cc28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0218 | PC: 0x04ccdc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0218 | Địa chỉ PC: 0x04ccdc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04ccdc: D10183FF  sub      sp, sp, #0x60
//   0x04cce0: F90013F7  str      x23, [sp, #0x20]
//   0x04cce4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x04cce8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0218_0x04ccdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ccdcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0219 | PC: 0x04cf10 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0219 | Địa chỉ PC: 0x04cf10 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x04cf10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04cf14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04cf18: 910043FD  add      x29, sp, #0x10
//   0x04cf1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0219_0x04cf10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cf10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0220 | PC: 0x04cfc4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0220 | Địa chỉ PC: 0x04cfc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04cfc4: D10183FF  sub      sp, sp, #0x60
//   0x04cfc8: F90013F7  str      x23, [sp, #0x20]
//   0x04cfcc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x04cfd0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0220_0x04cfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cfc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0221 | PC: 0x04d1f8 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0221 | Địa chỉ PC: 0x04d1f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04d1f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d1fc: 910003FD  mov      x29, sp
//   0x04d200: F9400400  ldr      x0, [x0, #8]
//   0x04d204: 97FFE390  bl       #0x46044
static inline uint64_t fde_func_0221_0x04d1f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d1f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0222 | PC: 0x04d298 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0222 | Địa chỉ PC: 0x04d298 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04d298: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d29c: 910003FD  mov      x29, sp
//   0x04d2a0: F9400400  ldr      x0, [x0, #8]
//   0x04d2a4: 97FFE368  bl       #0x46044
static inline uint64_t fde_func_0222_0x04d298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d298ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0223 | PC: 0x04d338 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0223 | Địa chỉ PC: 0x04d338 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x04d338: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d33c: 910003FD  mov      x29, sp
//   0x04d340: F9400400  ldr      x0, [x0, #8]
//   0x04d344: 52800021  mov      w1, #1
static inline uint64_t fde_func_0223_0x04d338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d338ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0224 | PC: 0x04d3dc | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0224 | Địa chỉ PC: 0x04d3dc | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x04d3dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d3e0: 910003FD  mov      x29, sp
//   0x04d3e4: F9400400  ldr      x0, [x0, #8]
//   0x04d3e8: 52800021  mov      w1, #1
static inline uint64_t fde_func_0224_0x04d3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d3dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0225 | PC: 0x04d480 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0225 | Địa chỉ PC: 0x04d480 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x04d480: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04d484: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04d488: 910043FD  add      x29, sp, #0x10
//   0x04d48c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0225_0x04d480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d480ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0226 | PC: 0x04d534 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0226 | Địa chỉ PC: 0x04d534 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x04d534: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d538: 910003FD  mov      x29, sp
//   0x04d53c: F9400408  ldr      x8, [x0, #8]
//   0x04d540: 91004001  add      x1, x0, #0x10
static inline uint64_t fde_func_0226_0x04d534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d534ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0227 | PC: 0x04d5e0 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #0227 | Địa chỉ PC: 0x04d5e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x04d5e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04d5e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04d5e8: 910043FD  add      x29, sp, #0x10
//   0x04d5ec: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0227_0x04d5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d5e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #0228 | PC: 0x04d694 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #0228 | Địa chỉ PC: 0x04d694 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x04d694: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d698: 910003FD  mov      x29, sp
//   0x04d69c: F9400408  ldr      x8, [x0, #8]
//   0x04d6a0: 91004001  add      x1, x0, #0x10
static inline uint64_t fde_func_0228_0x04d694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d694ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #0229 | PC: 0x04d740 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0229 | Địa chỉ PC: 0x04d740 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04d740: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d744: 910003FD  mov      x29, sp
//   0x04d748: F9400400  ldr      x0, [x0, #8]
//   0x04d74c: 97FFDE29  bl       #0x44ff0
static inline uint64_t fde_func_0229_0x04d740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d740ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0230 | PC: 0x04d7e0 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0230 | Địa chỉ PC: 0x04d7e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04d7e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d7e4: 910003FD  mov      x29, sp
//   0x04d7e8: F9400400  ldr      x0, [x0, #8]
//   0x04d7ec: 97FFDE01  bl       #0x44ff0
static inline uint64_t fde_func_0230_0x04d7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d7e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0231 | PC: 0x04d880 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0231 | Địa chỉ PC: 0x04d880 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04d880: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d884: 910003FD  mov      x29, sp
//   0x04d888: F9400400  ldr      x0, [x0, #8]
//   0x04d88c: 97FFDDD9  bl       #0x44ff0
static inline uint64_t fde_func_0231_0x04d880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d880ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0232 | PC: 0x04d920 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0232 | Địa chỉ PC: 0x04d920 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04d920: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04d924: 910003FD  mov      x29, sp
//   0x04d928: F9400400  ldr      x0, [x0, #8]
//   0x04d92c: 97FFDDB1  bl       #0x44ff0
static inline uint64_t fde_func_0232_0x04d920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d920ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0233 | PC: 0x04d9c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0233 | Địa chỉ PC: 0x04d9c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04d9c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04d9c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04d9c8: 910043FD  add      x29, sp, #0x10
//   0x04d9cc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0233_0x04d9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d9c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0234 | PC: 0x04dcac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0234 | Địa chỉ PC: 0x04dcac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04dcac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04dcb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04dcb4: 910043FD  add      x29, sp, #0x10
//   0x04dcb8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0234_0x04dcac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dcacULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0235 | PC: 0x04df98 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0235 | Địa chỉ PC: 0x04df98 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x04df98: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04df9c: 910003FD  mov      x29, sp
//   0x04dfa0: F9400400  ldr      x0, [x0, #8]
//   0x04dfa4: 97FFEDBB  bl       #0x49690
static inline uint64_t fde_func_0235_0x04df98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04df98ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0236 | PC: 0x04e038 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0236 | Địa chỉ PC: 0x04e038 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x04e038: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04e03c: 910003FD  mov      x29, sp
//   0x04e040: F9400400  ldr      x0, [x0, #8]
//   0x04e044: 97FFED93  bl       #0x49690
static inline uint64_t fde_func_0236_0x04e038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e038ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0237 | PC: 0x04e118 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0237 | Địa chỉ PC: 0x04e118 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x04e118: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04e11c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e120: 910043FD  add      x29, sp, #0x10
//   0x04e124: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0237_0x04e118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e118ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0238 | PC: 0x04e17c | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0238 | Địa chỉ PC: 0x04e17c | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x04e17c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04e180: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e184: 910043FD  add      x29, sp, #0x10
//   0x04e188: D0000808  adrp     x8, #0x150000
static inline uint64_t fde_func_0238_0x04e17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e17cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0239 | PC: 0x04e25c | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0239 | Địa chỉ PC: 0x04e25c | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x04e25c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04e260: 910003FD  mov      x29, sp
//   0x04e264: F9400408  ldr      x8, [x0, #8]
//   0x04e268: B9402802  ldr      w2, [x0, #0x28]
static inline uint64_t fde_func_0239_0x04e25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e25cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0240 | PC: 0x04e350 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #0240 | Địa chỉ PC: 0x04e350 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x04e350: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04e354: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e358: 910043FD  add      x29, sp, #0x10
//   0x04e35c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0240_0x04e350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e350ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #0241 | PC: 0x04e3b4 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0241 | Địa chỉ PC: 0x04e3b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x04e3b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04e3b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e3bc: 910043FD  add      x29, sp, #0x10
//   0x04e3c0: D0000808  adrp     x8, #0x150000
static inline uint64_t fde_func_0241_0x04e3b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e3b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0242 | PC: 0x04e494 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0242 | Địa chỉ PC: 0x04e494 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04e494: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04e498: 910003FD  mov      x29, sp
//   0x04e49c: F9400408  ldr      x8, [x0, #8]
//   0x04e4a0: B9402802  ldr      w2, [x0, #0x28]
static inline uint64_t fde_func_0242_0x04e494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e494ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0243 | PC: 0x04e5dc | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0243 | Địa chỉ PC: 0x04e5dc | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x04e5dc: D10103FF  sub      sp, sp, #0x40
//   0x04e5e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04e5e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04e5e8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0243_0x04e5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e5dcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0244 | PC: 0x04e660 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0244 | Địa chỉ PC: 0x04e660 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04e660: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04e664: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04e668: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04e66c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0244_0x04e660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e660ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0245 | PC: 0x04e81c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0245 | Địa chỉ PC: 0x04e81c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04e81c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04e820: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04e824: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04e828: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0245_0x04e81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e81cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0246 | PC: 0x04e928 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #0246 | Địa chỉ PC: 0x04e928 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x04e928: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04e92c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e930: 910043FD  add      x29, sp, #0x10
//   0x04e934: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0246_0x04e928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e928ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0247 | PC: 0x04e9ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0247 | Địa chỉ PC: 0x04e9ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04e9ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04e9f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04e9f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04e9f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0247_0x04e9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e9ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0248 | PC: 0x04eb10 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0248 | Địa chỉ PC: 0x04eb10 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04eb10: D10103FF  sub      sp, sp, #0x40
//   0x04eb14: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04eb18: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04eb1c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0248_0x04eb10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04eb10ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0249 | PC: 0x04ed88 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0249 | Địa chỉ PC: 0x04ed88 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04ed88: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04ed8c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04ed90: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04ed94: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0249_0x04ed88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ed88ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0250 | PC: 0x04ef00 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #0250 | Địa chỉ PC: 0x04ef00 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x04ef00: D10103FF  sub      sp, sp, #0x40
//   0x04ef04: F90013F3  str      x19, [sp, #0x20]
//   0x04ef08: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x04ef0c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0250_0x04ef00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ef00ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #0251 | PC: 0x04efa8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0251 | Địa chỉ PC: 0x04efa8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04efa8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04efac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04efb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04efb4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0251_0x04efa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04efa8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0252 | PC: 0x04f270 | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0252 | Địa chỉ PC: 0x04f270 | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x04f270: D10103FF  sub      sp, sp, #0x40
//   0x04f274: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04f278: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04f27c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0252_0x04f270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f270ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0253 | PC: 0x04f30c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0253 | Địa chỉ PC: 0x04f30c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04f30c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04f310: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04f314: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04f318: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0253_0x04f30c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f30cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0254 | PC: 0x04f574 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0254 | Địa chỉ PC: 0x04f574 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x04f574: D10103FF  sub      sp, sp, #0x40
//   0x04f578: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04f57c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04f580: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0254_0x04f574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f574ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0255 | PC: 0x04f60c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0255 | Địa chỉ PC: 0x04f60c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04f60c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04f610: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04f614: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04f618: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0255_0x04f60c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f60cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0256 | PC: 0x04f774 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0256 | Địa chỉ PC: 0x04f774 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04f774: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04f778: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04f77c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04f780: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0256_0x04f774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f774ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0257 | PC: 0x04f880 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0257 | Địa chỉ PC: 0x04f880 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x04f880: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04f884: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04f888: 910043FD  add      x29, sp, #0x10
//   0x04f88c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0257_0x04f880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f880ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0258 | PC: 0x04f960 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0258 | Địa chỉ PC: 0x04f960 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04f960: D10143FF  sub      sp, sp, #0x50
//   0x04f964: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04f968: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x04f96c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0258_0x04f960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f960ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0259 | PC: 0x04fbd8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0259 | Địa chỉ PC: 0x04fbd8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04fbd8: D10103FF  sub      sp, sp, #0x40
//   0x04fbdc: F9000BF5  str      x21, [sp, #0x10]
//   0x04fbe0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04fbe4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0259_0x04fbd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04fbd8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0260 | PC: 0x04fd84 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0260 | Địa chỉ PC: 0x04fd84 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x04fd84: D102C3FF  sub      sp, sp, #0xb0
//   0x04fd88: F9003BF7  str      x23, [sp, #0x70]
//   0x04fd8c: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x04fd90: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0260_0x04fd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04fd84ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0261 | PC: 0x0503f4 | FDE: 0x148a38 | Size: 52 bytes
// Hàm #0261 | Địa chỉ PC: 0x0503f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0503f4: D10083FF  sub      sp, sp, #0x20
//   0x0503f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0503fc: 910043FD  add      x29, sp, #0x10
//   0x050400: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_0261_0x0503f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0503f4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #0262 | PC: 0x050428 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0262 | Địa chỉ PC: 0x050428 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x050428: D10243FF  sub      sp, sp, #0x90
//   0x05042c: F9002BF7  str      x23, [sp, #0x50]
//   0x050430: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x050434: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0262_0x050428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050428ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0263 | PC: 0x050638 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0263 | Địa chỉ PC: 0x050638 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x050638: D10103FF  sub      sp, sp, #0x40
//   0x05063c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x050640: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x050644: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0263_0x050638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050638ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0264 | PC: 0x050690 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0264 | Địa chỉ PC: 0x050690 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x050690: D10103FF  sub      sp, sp, #0x40
//   0x050694: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x050698: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x05069c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0264_0x050690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050690ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0265 | PC: 0x0506e8 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0265 | Địa chỉ PC: 0x0506e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0506e8: D10103FF  sub      sp, sp, #0x40
//   0x0506ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0506f0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0506f4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0265_0x0506e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0506e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0266 | PC: 0x050744 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0266 | Địa chỉ PC: 0x050744 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x050744: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x050748: 910003FD  mov      x29, sp
//   0x05074c: D1024000  sub      x0, x0, #0x90
//   0x050750: 97FFFFE6  bl       #0x506e8
static inline uint64_t fde_func_0266_0x050744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050744ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0267 | PC: 0x050760 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0267 | Địa chỉ PC: 0x050760 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x050760: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x050764: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x050768: 910043FD  add      x29, sp, #0x10
//   0x05076c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0267_0x050760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050760ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0268 | PC: 0x050938 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0268 | Địa chỉ PC: 0x050938 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x050938: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05093c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x050940: 910043FD  add      x29, sp, #0x10
//   0x050944: 39400028  ldrb     w8, [x1]
static inline uint64_t fde_func_0268_0x050938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050938ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0269 | PC: 0x050b28 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #0269 | Địa chỉ PC: 0x050b28 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x050b28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x050b2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x050b30: 910043FD  add      x29, sp, #0x10
//   0x050b34: F0000848  adrp     x8, #0x15b000
static inline uint64_t fde_func_0269_0x050b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050b28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #0270 | PC: 0x050b68 | FDE: 0x148a38 | Size: 252 bytes
// Hàm #0270 | Địa chỉ PC: 0x050b68 | Địa chỉ FDE: 0x148a38 | Kích thước: 252 bytes
//   0x050b68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x050b6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x050b70: 910043FD  add      x29, sp, #0x10
//   0x050b74: 91004013  add      x19, x0, #0x10
static inline uint64_t fde_func_0270_0x050b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050b68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Func #0271 | PC: 0x050c64 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0271 | Địa chỉ PC: 0x050c64 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x050c64: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x050c68: 910003FD  mov      x29, sp
//   0x050c6c: 90000868  adrp     x8, #0x15c000
//   0x050c70: 91058108  add      x8, x8, #0x160
static inline uint64_t fde_func_0271_0x050c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050c64ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0272 | PC: 0x050cc0 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #0272 | Địa chỉ PC: 0x050cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x050cc0: D10143FF  sub      sp, sp, #0x50
//   0x050cc4: F90013F5  str      x21, [sp, #0x20]
//   0x050cc8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x050ccc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0272_0x050cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050cc0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #0273 | PC: 0x050d34 | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0273 | Địa chỉ PC: 0x050d34 | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x050d34: D10183FF  sub      sp, sp, #0x60
//   0x050d38: F90023F3  str      x19, [sp, #0x40]
//   0x050d3c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x050d40: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0273_0x050d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050d34ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0274 | PC: 0x050dd0 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0274 | Địa chỉ PC: 0x050dd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x050dd0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x050dd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x050dd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x050ddc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0274_0x050dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050dd0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0275 | PC: 0x050e40 | FDE: 0x148a38 | Size: 176 bytes
// Hàm #0275 | Địa chỉ PC: 0x050e40 | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x050e40: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x050e44: 910003FD  mov      x29, sp
//   0x050e48: F9400428  ldr      x8, [x1, #8]
//   0x050e4c: F100151F  cmp      x8, #5
static inline uint64_t fde_func_0275_0x050e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050e40ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #0276 | PC: 0x050ef0 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0276 | Địa chỉ PC: 0x050ef0 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x050ef0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x050ef4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x050ef8: 910043FD  add      x29, sp, #0x10
//   0x050efc: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0276_0x050ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050ef0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0277 | PC: 0x050f4c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0277 | Địa chỉ PC: 0x050f4c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x050f4c: D10103FF  sub      sp, sp, #0x40
//   0x050f50: F9000BF5  str      x21, [sp, #0x10]
//   0x050f54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x050f58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0277_0x050f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050f4cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0278 | PC: 0x051194 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0278 | Địa chỉ PC: 0x051194 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x051194: D10103FF  sub      sp, sp, #0x40
//   0x051198: F9000BF5  str      x21, [sp, #0x10]
//   0x05119c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0511a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0278_0x051194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051194ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0279 | PC: 0x051334 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0279 | Địa chỉ PC: 0x051334 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x051334: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x051338: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05133c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x051340: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0279_0x051334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051334ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0280 | PC: 0x0513f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0280 | Địa chỉ PC: 0x0513f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0513f0: D10743FF  sub      sp, sp, #0x1d0
//   0x0513f4: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x0513f8: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x0513fc: A9195FF8  stp      x24, x23, [sp, #0x190]
static inline uint64_t fde_func_0280_0x0513f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0513f0ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa9176ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0281 | PC: 0x051ab4 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0281 | Địa chỉ PC: 0x051ab4 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x051ab4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051ab8: 910003FD  mov      x29, sp
//   0x051abc: D1002000  sub      x0, x0, #8
//   0x051ac0: 97FFFE1D  bl       #0x51334
static inline uint64_t fde_func_0281_0x051ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051ab4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0282 | PC: 0x051ad0 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #0282 | Địa chỉ PC: 0x051ad0 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x051ad0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x051ad4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x051ad8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x051adc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0282_0x051ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051ad0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #0283 | PC: 0x051b8c | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0283 | Địa chỉ PC: 0x051b8c | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x051b8c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051b90: 910003FD  mov      x29, sp
//   0x051b94: D1002000  sub      x0, x0, #8
//   0x051b98: 97FFFFCE  bl       #0x51ad0
static inline uint64_t fde_func_0283_0x051b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051b8cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0284 | PC: 0x051c14 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0284 | Địa chỉ PC: 0x051c14 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x051c14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051c18: 910003FD  mov      x29, sp
//   0x051c1c: D1002000  sub      x0, x0, #8
//   0x051c20: 97FFFFE2  bl       #0x51ba8
static inline uint64_t fde_func_0284_0x051c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051c14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0285 | PC: 0x051c30 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #0285 | Địa chỉ PC: 0x051c30 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x051c30: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x051c34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x051c38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x051c3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0285_0x051c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051c30ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #0286 | PC: 0x051cf4 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #0286 | Địa chỉ PC: 0x051cf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x051cf4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051cf8: 910003FD  mov      x29, sp
//   0x051cfc: D1002000  sub      x0, x0, #8
//   0x051d00: 97FFFFCC  bl       #0x51c30
static inline uint64_t fde_func_0286_0x051cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051cf4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #0287 | PC: 0x051d6c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0287 | Địa chỉ PC: 0x051d6c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x051d6c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051d70: 910003FD  mov      x29, sp
//   0x051d74: D1002000  sub      x0, x0, #8
//   0x051d78: 97FFFFE6  bl       #0x51d10
static inline uint64_t fde_func_0287_0x051d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051d6cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0288 | PC: 0x051d88 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0288 | Địa chỉ PC: 0x051d88 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x051d88: D103C3FF  sub      sp, sp, #0xf0
//   0x051d8c: F90053F9  str      x25, [sp, #0xa0]
//   0x051d90: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x051d94: A90C57F6  stp      x22, x21, [sp, #0xc0]
static inline uint64_t fde_func_0288_0x051d88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051d88ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf90053f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0289 | PC: 0x0528e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0289 | Địa chỉ PC: 0x0528e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0528e4: D101C3FF  sub      sp, sp, #0x70
//   0x0528e8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0528ec: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0528f0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0289_0x0528e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0528e4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0290 | PC: 0x052a88 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0290 | Địa chỉ PC: 0x052a88 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x052a88: D10183FF  sub      sp, sp, #0x60
//   0x052a8c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x052a90: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x052a94: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0290_0x052a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x052a88ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0291 | PC: 0x052bc4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0291 | Địa chỉ PC: 0x052bc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x052bc4: D104C3FF  sub      sp, sp, #0x130
//   0x052bc8: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x052bcc: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x052bd0: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0291_0x052bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x052bc4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0292 | PC: 0x053338 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0292 | Địa chỉ PC: 0x053338 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x053338: D10303FF  sub      sp, sp, #0xc0
//   0x05333c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x053340: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x053344: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0292_0x053338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053338ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0293 | PC: 0x053770 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0293 | Địa chỉ PC: 0x053770 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x053770: D10143FF  sub      sp, sp, #0x50
//   0x053774: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x053778: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x05377c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0293_0x053770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053770ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0294 | PC: 0x053c28 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0294 | Địa chỉ PC: 0x053c28 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x053c28: D10143FF  sub      sp, sp, #0x50
//   0x053c2c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x053c30: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x053c34: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0294_0x053c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053c28ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0295 | PC: 0x053cf4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0295 | Địa chỉ PC: 0x053cf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x053cf4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x053cf8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x053cfc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x053d00: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0295_0x053cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053cf4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0296 | PC: 0x053f7c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0296 | Địa chỉ PC: 0x053f7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x053f7c: D10183FF  sub      sp, sp, #0x60
//   0x053f80: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x053f84: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x053f88: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0296_0x053f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053f7cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0297 | PC: 0x05407c | FDE: 0x148a38 | Size: 224 bytes
// Hàm #0297 | Địa chỉ PC: 0x05407c | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x05407c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x054080: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x054084: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x054088: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0297_0x05407c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05407cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #0298 | PC: 0x05415c | FDE: 0x148a38 | Size: 160 bytes
// Hàm #0298 | Địa chỉ PC: 0x05415c | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x05415c: D10103FF  sub      sp, sp, #0x40
//   0x054160: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x054164: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x054168: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0298_0x05415c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05415cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #0299 | PC: 0x0541fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0299 | Địa chỉ PC: 0x0541fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0541fc: D10343FF  sub      sp, sp, #0xd0
//   0x054200: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x054204: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x054208: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0299_0x0541fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0541fcULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0300 | PC: 0x054414 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #0300 | Địa chỉ PC: 0x054414 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x054414: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x054418: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05441c: 910043FD  add      x29, sp, #0x10
//   0x054420: 91018014  add      x20, x0, #0x60
static inline uint64_t fde_func_0300_0x054414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054414ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #0301 | PC: 0x0544e8 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #0301 | Địa chỉ PC: 0x0544e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0544e8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0544ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0544f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0544f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0301_0x0544e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0544e8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #0302 | PC: 0x05457c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0302 | Địa chỉ PC: 0x05457c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05457c: D10143FF  sub      sp, sp, #0x50
//   0x054580: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x054584: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x054588: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0302_0x05457c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05457cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0303 | PC: 0x0546b4 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #0303 | Địa chỉ PC: 0x0546b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0546b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0546b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0546bc: 910043FD  add      x29, sp, #0x10
//   0x0546c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0303_0x0546b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0546b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #0304 | PC: 0x054748 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0304 | Địa chỉ PC: 0x054748 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x054748: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05474c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x054750: 910043FD  add      x29, sp, #0x10
//   0x054754: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0304_0x054748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054748ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0305 | PC: 0x0547a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0305 | Địa chỉ PC: 0x0547a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0547a4: D10103FF  sub      sp, sp, #0x40
//   0x0547a8: F9000BF5  str      x21, [sp, #0x10]
//   0x0547ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0547b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0305_0x0547a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0547a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0306 | PC: 0x054a04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0306 | Địa chỉ PC: 0x054a04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x054a04: D10103FF  sub      sp, sp, #0x40
//   0x054a08: F9000BF5  str      x21, [sp, #0x10]
//   0x054a0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x054a10: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0306_0x054a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054a04ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0307 | PC: 0x054b9c | FDE: 0x148a38 | Size: 144 bytes
// Hàm #0307 | Địa chỉ PC: 0x054b9c | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x054b9c: D10183FF  sub      sp, sp, #0x60
//   0x054ba0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x054ba4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x054ba8: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0307_0x054b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054b9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #0308 | PC: 0x054c2c | FDE: 0x148a38 | Size: 112 bytes
// Hàm #0308 | Địa chỉ PC: 0x054c2c | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x054c2c: D10183FF  sub      sp, sp, #0x60
//   0x054c30: F90023F3  str      x19, [sp, #0x40]
//   0x054c34: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x054c38: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0308_0x054c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054c2cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #0309 | PC: 0x054c9c | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0309 | Địa chỉ PC: 0x054c9c | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x054c9c: D10183FF  sub      sp, sp, #0x60
//   0x054ca0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x054ca4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x054ca8: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0309_0x054c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054c9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0310 | PC: 0x054d5c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0310 | Địa chỉ PC: 0x054d5c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x054d5c: D10243FF  sub      sp, sp, #0x90
//   0x054d60: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x054d64: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x054d68: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0310_0x054d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054d5cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0311 | PC: 0x0550d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0311 | Địa chỉ PC: 0x0550d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0550d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0550dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0550e0: 910043FD  add      x29, sp, #0x10
//   0x0550e4: 2A0203E8  mov      w8, w2
static inline uint64_t fde_func_0311_0x0550d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0550d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0312 | PC: 0x055220 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0312 | Địa chỉ PC: 0x055220 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x055220: D103C3FF  sub      sp, sp, #0xf0
//   0x055224: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x055228: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x05522c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_0312_0x055220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055220ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90b5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0313 | PC: 0x055c8c | FDE: 0x148a38 | Size: 4 bytes
// Hàm #0313 | Địa chỉ PC: 0x055c8c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x055c8c: D1400BFF  sub      sp, sp, #2, lsl #12
static inline uint64_t fde_func_0313_0x055c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055c8cULL ^ (static_cast<uint64_t>(0xd1400bffULL) << 13);
    acc = (acc + a1 + 0xd10103ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #0314 | PC: 0x055c90 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0314 | Địa chỉ PC: 0x055c90 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x055c90: D10103FF  sub      sp, sp, #0x40
//   0x055c94: D53BD056  mrs      x22, tpidr_el0
//   0x055c98: F94016C8  ldr      x8, [x22, #0x28]
//   0x055c9c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0314_0x055c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055c90ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xd53bd056ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0315 | PC: 0x0561f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0315 | Địa chỉ PC: 0x0561f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0561f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0561f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0561f8: 910043FD  add      x29, sp, #0x10
//   0x0561fc: 91008008  add      x8, x0, #0x20
static inline uint64_t fde_func_0315_0x0561f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0561f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0316 | PC: 0x056380 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0316 | Địa chỉ PC: 0x056380 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x056380: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x056384: 910003FD  mov      x29, sp
//   0x056388: D1002000  sub      x0, x0, #8
//   0x05638c: 97FFFA74  bl       #0x54d5c
static inline uint64_t fde_func_0316_0x056380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056380ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0317 | PC: 0x05639c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0317 | Địa chỉ PC: 0x05639c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05639c: D10203FF  sub      sp, sp, #0x80
//   0x0563a0: F90023F7  str      x23, [sp, #0x40]
//   0x0563a4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0563a8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0317_0x05639c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05639cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0318 | PC: 0x05660c | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0318 | Địa chỉ PC: 0x05660c | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x05660c: D10143FF  sub      sp, sp, #0x50
//   0x056610: F9001BF3  str      x19, [sp, #0x30]
//   0x056614: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x056618: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0318_0x05660c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05660cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0319 | PC: 0x056688 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0319 | Địa chỉ PC: 0x056688 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x056688: D10183FF  sub      sp, sp, #0x60
//   0x05668c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x056690: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x056694: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0319_0x056688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056688ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0320 | PC: 0x0567ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0320 | Địa chỉ PC: 0x0567ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0567ac: D10183FF  sub      sp, sp, #0x60
//   0x0567b0: F90023F3  str      x19, [sp, #0x40]
//   0x0567b4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0567b8: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0320_0x0567ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0567acULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0321 | PC: 0x056920 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0321 | Địa chỉ PC: 0x056920 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x056920: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x056924: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x056928: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05692c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0321_0x056920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056920ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0322 | PC: 0x056d9c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0322 | Địa chỉ PC: 0x056d9c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x056d9c: D100C3FF  sub      sp, sp, #0x30
//   0x056da0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x056da4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x056da8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0322_0x056d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056d9cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0323 | PC: 0x056ef0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0323 | Địa chỉ PC: 0x056ef0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x056ef0: D10183FF  sub      sp, sp, #0x60
//   0x056ef4: A90107F9  stp      x25, x1, [sp, #0x10]
//   0x056ef8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x056efc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0323_0x056ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056ef0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90107f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0324 | PC: 0x057108 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0324 | Địa chỉ PC: 0x057108 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x057108: D10443FF  sub      sp, sp, #0x110
//   0x05710c: A90E57FC  stp      x28, x21, [sp, #0xe0]
//   0x057110: A90F4FF4  stp      x20, x19, [sp, #0xf0]
//   0x057114: A9107BFD  stp      x29, x30, [sp, #0x100]
static inline uint64_t fde_func_0324_0x057108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057108ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90e57fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0325 | PC: 0x0572b0 | FDE: 0x148a38 | Size: 108 bytes
// Hàm #0325 | Địa chỉ PC: 0x0572b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x0572b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0572b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0572b8: 910043FD  add      x29, sp, #0x10
//   0x0572bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0325_0x0572b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0572b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #0326 | PC: 0x05731c | FDE: 0x148a38 | Size: 216 bytes
// Hàm #0326 | Địa chỉ PC: 0x05731c | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x05731c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x057320: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x057324: 910043FD  add      x29, sp, #0x10
//   0x057328: 90000828  adrp     x8, #0x15b000
static inline uint64_t fde_func_0326_0x05731c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05731cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #0327 | PC: 0x0573f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0327 | Địa chỉ PC: 0x0573f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0573f4: D10203FF  sub      sp, sp, #0x80
//   0x0573f8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0573fc: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x057400: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0327_0x0573f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0573f4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0328 | PC: 0x0575c4 | FDE: 0x148a38 | Size: 244 bytes
// Hàm #0328 | Địa chỉ PC: 0x0575c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x0575c4: D101C3FF  sub      sp, sp, #0x70
//   0x0575c8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0575cc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0575d0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0328_0x0575c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0575c4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #0329 | PC: 0x0576b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0329 | Địa chỉ PC: 0x0576b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0576b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0576bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0576c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0576c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0329_0x0576b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0576b8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0330 | PC: 0x057820 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0330 | Địa chỉ PC: 0x057820 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x057820: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x057824: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x057828: 910043FD  add      x29, sp, #0x10
//   0x05782c: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_0330_0x057820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057820ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0331 | PC: 0x0578e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0331 | Địa chỉ PC: 0x0578e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0578e0: D10143FF  sub      sp, sp, #0x50
//   0x0578e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0578e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0578ec: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0331_0x0578e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0578e0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0332 | PC: 0x057b0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0332 | Địa chỉ PC: 0x057b0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x057b0c: D10103FF  sub      sp, sp, #0x40
//   0x057b10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x057b14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x057b18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0332_0x057b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057b0cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0333 | PC: 0x057c6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0333 | Địa chỉ PC: 0x057c6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x057c6c: D10203FF  sub      sp, sp, #0x80
//   0x057c70: F90023F7  str      x23, [sp, #0x40]
//   0x057c74: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x057c78: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0333_0x057c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057c6cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0334 | PC: 0x058000 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0334 | Địa chỉ PC: 0x058000 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x058000: D101C3FF  sub      sp, sp, #0x70
//   0x058004: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x058008: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05800c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0334_0x058000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058000ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0335 | PC: 0x058228 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0335 | Địa chỉ PC: 0x058228 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x058228: D10143FF  sub      sp, sp, #0x50
//   0x05822c: F90013F5  str      x21, [sp, #0x20]
//   0x058230: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x058234: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0335_0x058228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058228ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0336 | PC: 0x0582e8 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #0336 | Địa chỉ PC: 0x0582e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x0582e8: D100C3FF  sub      sp, sp, #0x30
//   0x0582ec: F9000BF3  str      x19, [sp, #0x10]
//   0x0582f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0582f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0336_0x0582e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0582e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #0337 | PC: 0x05838c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0337 | Địa chỉ PC: 0x05838c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05838c: D10103FF  sub      sp, sp, #0x40
//   0x058390: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058394: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x058398: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0337_0x05838c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05838cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0338 | PC: 0x058520 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0338 | Địa chỉ PC: 0x058520 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x058520: D10103FF  sub      sp, sp, #0x40
//   0x058524: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058528: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x05852c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0338_0x058520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058520ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0339 | PC: 0x058578 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0339 | Địa chỉ PC: 0x058578 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x058578: D10103FF  sub      sp, sp, #0x40
//   0x05857c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058580: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x058584: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0339_0x058578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058578ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0340 | PC: 0x0585d0 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #0340 | Địa chỉ PC: 0x0585d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x0585d0: D10143FF  sub      sp, sp, #0x50
//   0x0585d4: F90013F5  str      x21, [sp, #0x20]
//   0x0585d8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0585dc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0340_0x0585d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0585d0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #0341 | PC: 0x058688 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0341 | Địa chỉ PC: 0x058688 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x058688: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05868c: 910003FD  mov      x29, sp
//   0x058690: D1024000  sub      x0, x0, #0x90
//   0x058694: 97FFFFCF  bl       #0x585d0
static inline uint64_t fde_func_0341_0x058688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058688ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0342 | PC: 0x0586a4 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0342 | Địa chỉ PC: 0x0586a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0586a4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0586a8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0586ac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0586b0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0342_0x0586a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0586a4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0343 | PC: 0x0586c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0343 | Địa chỉ PC: 0x0586c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0586c0: D10683FF  sub      sp, sp, #0x1a0
//   0x0586c4: AA0003F3  mov      x19, x0
//   0x0586c8: 97FF6896  bl       #0x32920
//   0x0586cc: 97FF6D1D  bl       #0x33b40
static inline uint64_t fde_func_0343_0x0586c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0586c0ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0344 | PC: 0x058c24 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #0344 | Địa chỉ PC: 0x058c24 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x058c24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x058c28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x058c2c: 910043FD  add      x29, sp, #0x10
//   0x058c30: F0000808  adrp     x8, #0x15b000
static inline uint64_t fde_func_0344_0x058c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058c24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #0345 | PC: 0x058c80 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0345 | Địa chỉ PC: 0x058c80 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x058c80: D10103FF  sub      sp, sp, #0x40
//   0x058c84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058c88: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x058c8c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0345_0x058c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058c80ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0346 | PC: 0x058d40 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #0346 | Địa chỉ PC: 0x058d40 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x058d40: D10103FF  sub      sp, sp, #0x40
//   0x058d44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058d48: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x058d4c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0346_0x058d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058d40ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #0347 | PC: 0x058dcc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0347 | Địa chỉ PC: 0x058dcc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x058dcc: D10183FF  sub      sp, sp, #0x60
//   0x058dd0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x058dd4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x058dd8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0347_0x058dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058dccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0348 | PC: 0x058f9c | FDE: 0x148a38 | Size: 156 bytes
// Hàm #0348 | Địa chỉ PC: 0x058f9c | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x058f9c: D100C3FF  sub      sp, sp, #0x30
//   0x058fa0: F9000BF3  str      x19, [sp, #0x10]
//   0x058fa4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x058fa8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0348_0x058f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058f9cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #0349 | PC: 0x059038 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0349 | Địa chỉ PC: 0x059038 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x059038: D10183FF  sub      sp, sp, #0x60
//   0x05903c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x059040: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x059044: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0349_0x059038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059038ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0350 | PC: 0x059154 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #0350 | Địa chỉ PC: 0x059154 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x059154: D100C3FF  sub      sp, sp, #0x30
//   0x059158: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05915c: 910083FD  add      x29, sp, #0x20
//   0x059160: F9400828  ldr      x8, [x1, #0x10]
static inline uint64_t fde_func_0350_0x059154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059154ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #0351 | PC: 0x059220 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0351 | Địa chỉ PC: 0x059220 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x059220: D101C3FF  sub      sp, sp, #0x70
//   0x059224: F9001BF7  str      x23, [sp, #0x30]
//   0x059228: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05922c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0351_0x059220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059220ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0352 | PC: 0x0594c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0352 | Địa chỉ PC: 0x0594c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0594c0: D10183FF  sub      sp, sp, #0x60
//   0x0594c4: F90013F7  str      x23, [sp, #0x20]
//   0x0594c8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0594cc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0352_0x0594c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0594c0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0353 | PC: 0x0597c4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0353 | Địa chỉ PC: 0x0597c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0597c4: D10183FF  sub      sp, sp, #0x60
//   0x0597c8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0597cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0597d0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0353_0x0597c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0597c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0354 | PC: 0x059a34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0354 | Địa chỉ PC: 0x059a34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x059a34: D10443FF  sub      sp, sp, #0x110
//   0x059a38: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x059a3c: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x059a40: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_0354_0x059a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059a34ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0355 | PC: 0x059d68 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0355 | Địa chỉ PC: 0x059d68 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x059d68: D10243FF  sub      sp, sp, #0x90
//   0x059d6c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x059d70: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x059d74: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0355_0x059d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059d68ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0356 | PC: 0x05a15c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0356 | Địa chỉ PC: 0x05a15c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05a15c: D10643FF  sub      sp, sp, #0x190
//   0x05a160: F9009BFC  str      x28, [sp, #0x130]
//   0x05a164: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x05a168: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_0356_0x05a15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a15cULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0357 | PC: 0x05a508 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0357 | Địa chỉ PC: 0x05a508 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05a508: D10403FF  sub      sp, sp, #0x100
//   0x05a50c: F90053FB  str      x27, [sp, #0xa0]
//   0x05a510: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x05a514: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0357_0x05a508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a508ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90053fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0358 | PC: 0x05abc8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #0358 | Địa chỉ PC: 0x05abc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x05abc8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05abcc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05abd0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05abd4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0358_0x05abc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05abc8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #0359 | PC: 0x05abe4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0359 | Địa chỉ PC: 0x05abe4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05abe4: D10683FF  sub      sp, sp, #0x1a0
//   0x05abe8: AA0003F7  mov      x23, x0
//   0x05abec: 52806200  mov      w0, #0x310
//   0x05abf0: AA0103F6  mov      x22, x1
static inline uint64_t fde_func_0359_0x05abe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05abe4ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0360 | PC: 0x05b778 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0360 | Địa chỉ PC: 0x05b778 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05b778: D10143FF  sub      sp, sp, #0x50
//   0x05b77c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05b780: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05b784: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0360_0x05b778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b778ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0361 | PC: 0x05b888 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0361 | Địa chỉ PC: 0x05b888 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05b888: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05b88c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05b890: 910043FD  add      x29, sp, #0x10
//   0x05b894: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0361_0x05b888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b888ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0362 | PC: 0x05b9dc | FDE: 0x148a38 | Size: 192 bytes
// Hàm #0362 | Địa chỉ PC: 0x05b9dc | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x05b9dc: D10143FF  sub      sp, sp, #0x50
//   0x05b9e0: A901D7FF  stp      xzr, x21, [sp, #0x18]
//   0x05b9e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05b9e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0362_0x05b9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b9dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa901d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #0363 | PC: 0x05ba9c | FDE: 0x148a38 | Size: 144 bytes
// Hàm #0363 | Địa chỉ PC: 0x05ba9c | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x05ba9c: D100C3FF  sub      sp, sp, #0x30
//   0x05baa0: F9000BF3  str      x19, [sp, #0x10]
//   0x05baa4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05baa8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0363_0x05ba9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ba9cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #0364 | PC: 0x05bb2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0364 | Địa chỉ PC: 0x05bb2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05bb2c: D10203FF  sub      sp, sp, #0x80
//   0x05bb30: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x05bb34: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x05bb38: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0364_0x05bb2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05bb2cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0365 | PC: 0x05bda8 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0365 | Địa chỉ PC: 0x05bda8 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x05bda8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05bdac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05bdb0: 910043FD  add      x29, sp, #0x10
//   0x05bdb4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0365_0x05bda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05bda8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0366 | PC: 0x05be30 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #0366 | Địa chỉ PC: 0x05be30 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x05be30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05be34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05be38: 910043FD  add      x29, sp, #0x10
//   0x05be3c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0366_0x05be30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05be30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #0367 | PC: 0x05beb4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0367 | Địa chỉ PC: 0x05beb4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05beb4: D10183FF  sub      sp, sp, #0x60
//   0x05beb8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05bebc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x05bec0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0367_0x05beb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05beb4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0368 | PC: 0x05c0ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0368 | Địa chỉ PC: 0x05c0ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05c0ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05c0b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05c0b4: 910043FD  add      x29, sp, #0x10
//   0x05c0b8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0368_0x05c0ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c0acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0369 | PC: 0x05c2b8 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #0369 | Địa chỉ PC: 0x05c2b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x05c2b8: D10103FF  sub      sp, sp, #0x40
//   0x05c2bc: F90013F3  str      x19, [sp, #0x20]
//   0x05c2c0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x05c2c4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0369_0x05c2b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c2b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #0370 | PC: 0x05c310 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #0370 | Địa chỉ PC: 0x05c310 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x05c310: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05c314: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05c318: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05c31c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0370_0x05c310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c310ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #0371 | PC: 0x05c38c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0371 | Địa chỉ PC: 0x05c38c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05c38c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05c390: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c394: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c398: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0371_0x05c38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c38cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0372 | PC: 0x05c62c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0372 | Địa chỉ PC: 0x05c62c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05c62c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05c630: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05c634: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05c638: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0372_0x05c62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c62cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0373 | PC: 0x05c750 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #0373 | Địa chỉ PC: 0x05c750 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x05c750: D10103FF  sub      sp, sp, #0x40
//   0x05c754: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c758: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c75c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0373_0x05c750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c750ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #0374 | PC: 0x05c7d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0374 | Địa chỉ PC: 0x05c7d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05c7d8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05c7dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c7e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c7e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0374_0x05c7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c7d8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0375 | PC: 0x05c8e4 | FDE: 0x148a38 | Size: 84 bytes
// Hàm #0375 | Địa chỉ PC: 0x05c8e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x05c8e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05c8e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05c8ec: 910043FD  add      x29, sp, #0x10
//   0x05c8f0: 91006014  add      x20, x0, #0x18
static inline uint64_t fde_func_0375_0x05c8e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c8e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #0376 | PC: 0x05c938 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0376 | Địa chỉ PC: 0x05c938 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05c938: D10243FF  sub      sp, sp, #0x90
//   0x05c93c: F90023F9  str      x25, [sp, #0x40]
//   0x05c940: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x05c944: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0376_0x05c938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c938ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0377 | PC: 0x05ca9c | FDE: 0x148a38 | Size: 152 bytes
// Hàm #0377 | Địa chỉ PC: 0x05ca9c | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x05ca9c: D10143FF  sub      sp, sp, #0x50
//   0x05caa0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05caa4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05caa8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0377_0x05ca9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ca9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #0378 | PC: 0x05cb34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #0378 | Địa chỉ PC: 0x05cb34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x05cb34: D10103FF  sub      sp, sp, #0x40
//   0x05cb38: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05cb3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05cb40: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0378_0x05cb34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cb34ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #0379 | PC: 0x05cd7c | FDE: 0x148a38 | Size: 76 bytes
// Hàm #0379 | Địa chỉ PC: 0x05cd7c | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x05cd7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05cd80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05cd84: 910043FD  add      x29, sp, #0x10
//   0x05cd88: F00007E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_0379_0x05cd7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cd7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x034c9c(a0, a1);
        case 1: return fde_func_0001_0x034cfc(a0, a1);
        case 2: return fde_func_0002_0x034dd0(a0, a1);
        case 3: return fde_func_0003_0x034e88(a0, a1);
        case 4: return fde_func_0004_0x034f40(a0, a1);
        case 5: return fde_func_0005_0x034ff8(a0, a1);
        case 6: return fde_func_0006_0x0350b0(a0, a1);
        case 7: return fde_func_0007_0x035128(a0, a1);
        case 8: return fde_func_0008_0x035178(a0, a1);
        case 9: return fde_func_0009_0x0351d4(a0, a1);
        case 10: return fde_func_0010_0x035220(a0, a1);
        case 11: return fde_func_0011_0x03529c(a0, a1);
        case 12: return fde_func_0012_0x035330(a0, a1);
        case 13: return fde_func_0013_0x0353ac(a0, a1);
        case 14: return fde_func_0014_0x035428(a0, a1);
        case 15: return fde_func_0015_0x035628(a0, a1);
        case 16: return fde_func_0016_0x035640(a0, a1);
        case 17: return fde_func_0017_0x03578c(a0, a1);
        case 18: return fde_func_0018_0x035900(a0, a1);
        case 19: return fde_func_0019_0x0359a4(a0, a1);
        case 20: return fde_func_0020_0x035adc(a0, a1);
        case 21: return fde_func_0021_0x035bc8(a0, a1);
        case 22: return fde_func_0022_0x035c38(a0, a1);
        case 23: return fde_func_0023_0x035e04(a0, a1);
        case 24: return fde_func_0024_0x035e74(a0, a1);
        case 25: return fde_func_0025_0x035fd4(a0, a1);
        case 26: return fde_func_0026_0x036148(a0, a1);
        case 27: return fde_func_0027_0x036a64(a0, a1);
        case 28: return fde_func_0028_0x0374e8(a0, a1);
        case 29: return fde_func_0029_0x037578(a0, a1);
        case 30: return fde_func_0030_0x03761c(a0, a1);
        case 31: return fde_func_0031_0x0376e4(a0, a1);
        case 32: return fde_func_0032_0x0377f8(a0, a1);
        case 33: return fde_func_0033_0x037988(a0, a1);
        case 34: return fde_func_0034_0x037c24(a0, a1);
        case 35: return fde_func_0035_0x037c48(a0, a1);
        case 36: return fde_func_0036_0x037d28(a0, a1);
        case 37: return fde_func_0037_0x037ddc(a0, a1);
        case 38: return fde_func_0038_0x037e48(a0, a1);
        case 39: return fde_func_0039_0x037e90(a0, a1);
        case 40: return fde_func_0040_0x037f34(a0, a1);
        case 41: return fde_func_0041_0x038400(a0, a1);
        case 42: return fde_func_0042_0x038448(a0, a1);
        case 43: return fde_func_0043_0x03852c(a0, a1);
        case 44: return fde_func_0044_0x0385f8(a0, a1);
        case 45: return fde_func_0045_0x038678(a0, a1);
        case 46: return fde_func_0046_0x0387ac(a0, a1);
        case 47: return fde_func_0047_0x038804(a0, a1);
        case 48: return fde_func_0048_0x03884c(a0, a1);
        case 49: return fde_func_0049_0x03891c(a0, a1);
        case 50: return fde_func_0050_0x0389f8(a0, a1);
        case 51: return fde_func_0051_0x038b34(a0, a1);
        case 52: return fde_func_0052_0x038d58(a0, a1);
        case 53: return fde_func_0053_0x038e04(a0, a1);
        case 54: return fde_func_0054_0x038ff4(a0, a1);
        case 55: return fde_func_0055_0x03906c(a0, a1);
        case 56: return fde_func_0056_0x0391f0(a0, a1);
        case 57: return fde_func_0057_0x039324(a0, a1);
        case 58: return fde_func_0058_0x0395d4(a0, a1);
        case 59: return fde_func_0059_0x039720(a0, a1);
        case 60: return fde_func_0060_0x039868(a0, a1);
        case 61: return fde_func_0061_0x039978(a0, a1);
        case 62: return fde_func_0062_0x0399c0(a0, a1);
        case 63: return fde_func_0063_0x039aa8(a0, a1);
        case 64: return fde_func_0064_0x039b50(a0, a1);
        case 65: return fde_func_0065_0x039c18(a0, a1);
        case 66: return fde_func_0066_0x039fe0(a0, a1);
        case 67: return fde_func_0067_0x03a2cc(a0, a1);
        case 68: return fde_func_0068_0x03a40c(a0, a1);
        case 69: return fde_func_0069_0x03a7c4(a0, a1);
        case 70: return fde_func_0070_0x03a830(a0, a1);
        case 71: return fde_func_0071_0x03aba4(a0, a1);
        case 72: return fde_func_0072_0x03ad20(a0, a1);
        case 73: return fde_func_0073_0x03ae2c(a0, a1);
        case 74: return fde_func_0074_0x03ae8c(a0, a1);
        case 75: return fde_func_0075_0x03af2c(a0, a1);
        case 76: return fde_func_0076_0x03aff0(a0, a1);
        case 77: return fde_func_0077_0x03b3f0(a0, a1);
        case 78: return fde_func_0078_0x03b438(a0, a1);
        case 79: return fde_func_0079_0x03b4a8(a0, a1);
        case 80: return fde_func_0080_0x03b780(a0, a1);
        case 81: return fde_func_0081_0x03b908(a0, a1);
        case 82: return fde_func_0082_0x03bb74(a0, a1);
        case 83: return fde_func_0083_0x03c0f8(a0, a1);
        case 84: return fde_func_0084_0x03c1a4(a0, a1);
        case 85: return fde_func_0085_0x03c218(a0, a1);
        case 86: return fde_func_0086_0x03c35c(a0, a1);
        case 87: return fde_func_0087_0x03c450(a0, a1);
        case 88: return fde_func_0088_0x03c51c(a0, a1);
        case 89: return fde_func_0089_0x03c5b8(a0, a1);
        case 90: return fde_func_0090_0x03c5d4(a0, a1);
        case 91: return fde_func_0091_0x03ceb8(a0, a1);
        case 92: return fde_func_0092_0x03d114(a0, a1);
        case 93: return fde_func_0093_0x03d268(a0, a1);
        case 94: return fde_func_0094_0x03d5d4(a0, a1);
        case 95: return fde_func_0095_0x03d680(a0, a1);
        case 96: return fde_func_0096_0x03d950(a0, a1);
        case 97: return fde_func_0097_0x03df50(a0, a1);
        case 98: return fde_func_0098_0x03e15c(a0, a1);
        case 99: return fde_func_0099_0x03e208(a0, a1);
        case 100: return fde_func_0100_0x03e280(a0, a1);
        case 101: return fde_func_0101_0x03e3ac(a0, a1);
        case 102: return fde_func_0102_0x03e5ec(a0, a1);
        case 103: return fde_func_0103_0x03e6a0(a0, a1);
        case 104: return fde_func_0104_0x03e758(a0, a1);
        case 105: return fde_func_0105_0x03e8a4(a0, a1);
        case 106: return fde_func_0106_0x03e8c8(a0, a1);
        case 107: return fde_func_0107_0x03e93c(a0, a1);
        case 108: return fde_func_0108_0x03e9a8(a0, a1);
        case 109: return fde_func_0109_0x03ea04(a0, a1);
        case 110: return fde_func_0110_0x03ebac(a0, a1);
        case 111: return fde_func_0111_0x03ec24(a0, a1);
        case 112: return fde_func_0112_0x03ec7c(a0, a1);
        case 113: return fde_func_0113_0x03ede8(a0, a1);
        case 114: return fde_func_0114_0x03f220(a0, a1);
        case 115: return fde_func_0115_0x03f35c(a0, a1);
        case 116: return fde_func_0116_0x03f4bc(a0, a1);
        case 117: return fde_func_0117_0x03f4fc(a0, a1);
        case 118: return fde_func_0118_0x03f564(a0, a1);
        case 119: return fde_func_0119_0x03f63c(a0, a1);
        case 120: return fde_func_0120_0x03f658(a0, a1);
        case 121: return fde_func_0121_0x03fc28(a0, a1);
        case 122: return fde_func_0122_0x03ff6c(a0, a1);
        case 123: return fde_func_0123_0x03ffe0(a0, a1);
        case 124: return fde_func_0124_0x040058(a0, a1);
        case 125: return fde_func_0125_0x0401c8(a0, a1);
        case 126: return fde_func_0126_0x040248(a0, a1);
        case 127: return fde_func_0127_0x040498(a0, a1);
        case 128: return fde_func_0128_0x040718(a0, a1);
        case 129: return fde_func_0129_0x040ac4(a0, a1);
        case 130: return fde_func_0130_0x040bec(a0, a1);
        case 131: return fde_func_0131_0x040d60(a0, a1);
        case 132: return fde_func_0132_0x040f60(a0, a1);
        case 133: return fde_func_0133_0x04128c(a0, a1);
        case 134: return fde_func_0134_0x0416b8(a0, a1);
        case 135: return fde_func_0135_0x041a5c(a0, a1);
        case 136: return fde_func_0136_0x0420a0(a0, a1);
        case 137: return fde_func_0137_0x042220(a0, a1);
        case 138: return fde_func_0138_0x0422ec(a0, a1);
        case 139: return fde_func_0139_0x042564(a0, a1);
        case 140: return fde_func_0140_0x0428f8(a0, a1);
        case 141: return fde_func_0141_0x042c64(a0, a1);
        case 142: return fde_func_0142_0x042d2c(a0, a1);
        case 143: return fde_func_0143_0x0430e0(a0, a1);
        case 144: return fde_func_0144_0x04330c(a0, a1);
        case 145: return fde_func_0145_0x0433a8(a0, a1);
        case 146: return fde_func_0146_0x0436b8(a0, a1);
        case 147: return fde_func_0147_0x043f68(a0, a1);
        case 148: return fde_func_0148_0x044114(a0, a1);
        case 149: return fde_func_0149_0x0441d0(a0, a1);
        case 150: return fde_func_0150_0x044280(a0, a1);
        case 151: return fde_func_0151_0x044338(a0, a1);
        case 152: return fde_func_0152_0x044354(a0, a1);
        case 153: return fde_func_0153_0x044ff0(a0, a1);
        case 154: return fde_func_0154_0x045498(a0, a1);
        case 155: return fde_func_0155_0x0455c8(a0, a1);
        case 156: return fde_func_0156_0x045690(a0, a1);
        case 157: return fde_func_0157_0x045c38(a0, a1);
        case 158: return fde_func_0158_0x045e50(a0, a1);
        case 159: return fde_func_0159_0x04613c(a0, a1);
        case 160: return fde_func_0160_0x046330(a0, a1);
        case 161: return fde_func_0161_0x046594(a0, a1);
        case 162: return fde_func_0162_0x0465fc(a0, a1);
        case 163: return fde_func_0163_0x04695c(a0, a1);
        case 164: return fde_func_0164_0x046abc(a0, a1);
        case 165: return fde_func_0165_0x046f18(a0, a1);
        case 166: return fde_func_0166_0x047724(a0, a1);
        case 167: return fde_func_0167_0x047a9c(a0, a1);
        case 168: return fde_func_0168_0x047e50(a0, a1);
        case 169: return fde_func_0169_0x048968(a0, a1);
        case 170: return fde_func_0170_0x048b00(a0, a1);
        case 171: return fde_func_0171_0x048cac(a0, a1);
        case 172: return fde_func_0172_0x048fc8(a0, a1);
        case 173: return fde_func_0173_0x04925c(a0, a1);
        case 174: return fde_func_0174_0x049290(a0, a1);
        case 175: return fde_func_0175_0x049690(a0, a1);
        case 176: return fde_func_0176_0x049918(a0, a1);
        case 177: return fde_func_0177_0x049a0c(a0, a1);
        case 178: return fde_func_0178_0x049b64(a0, a1);
        case 179: return fde_func_0179_0x049cc0(a0, a1);
        case 180: return fde_func_0180_0x049d24(a0, a1);
        case 181: return fde_func_0181_0x049d84(a0, a1);
        case 182: return fde_func_0182_0x049dc4(a0, a1);
        case 183: return fde_func_0183_0x049e2c(a0, a1);
        case 184: return fde_func_0184_0x049ed0(a0, a1);
        case 185: return fde_func_0185_0x04a260(a0, a1);
        case 186: return fde_func_0186_0x04a2ec(a0, a1);
        case 187: return fde_func_0187_0x04a344(a0, a1);
        case 188: return fde_func_0188_0x04a3b0(a0, a1);
        case 189: return fde_func_0189_0x04a4c8(a0, a1);
        case 190: return fde_func_0190_0x04a508(a0, a1);
        case 191: return fde_func_0191_0x04a700(a0, a1);
        case 192: return fde_func_0192_0x04a8ec(a0, a1);
        case 193: return fde_func_0193_0x04a958(a0, a1);
        case 194: return fde_func_0194_0x04a9b0(a0, a1);
        case 195: return fde_func_0195_0x04aa90(a0, a1);
        case 196: return fde_func_0196_0x04ab18(a0, a1);
        case 197: return fde_func_0197_0x04ab68(a0, a1);
        case 198: return fde_func_0198_0x04abf8(a0, a1);
        case 199: return fde_func_0199_0x04ac64(a0, a1);
        case 200: return fde_func_0200_0x04ae1c(a0, a1);
        case 201: return fde_func_0201_0x04b050(a0, a1);
        case 202: return fde_func_0202_0x04b0f0(a0, a1);
        case 203: return fde_func_0203_0x04b2dc(a0, a1);
        case 204: return fde_func_0204_0x04b4cc(a0, a1);
        case 205: return fde_func_0205_0x04b594(a0, a1);
        case 206: return fde_func_0206_0x04b684(a0, a1);
        case 207: return fde_func_0207_0x04ba10(a0, a1);
        case 208: return fde_func_0208_0x04bb00(a0, a1);
        case 209: return fde_func_0209_0x04be10(a0, a1);
        case 210: return fde_func_0210_0x04be94(a0, a1);
        case 211: return fde_func_0211_0x04bf30(a0, a1);
        case 212: return fde_func_0212_0x04c0a8(a0, a1);
        case 213: return fde_func_0213_0x04c130(a0, a1);
        case 214: return fde_func_0214_0x04c3a8(a0, a1);
        case 215: return fde_func_0215_0x04c6b4(a0, a1);
        case 216: return fde_func_0216_0x04c9f4(a0, a1);
        case 217: return fde_func_0217_0x04cc28(a0, a1);
        case 218: return fde_func_0218_0x04ccdc(a0, a1);
        case 219: return fde_func_0219_0x04cf10(a0, a1);
        case 220: return fde_func_0220_0x04cfc4(a0, a1);
        case 221: return fde_func_0221_0x04d1f8(a0, a1);
        case 222: return fde_func_0222_0x04d298(a0, a1);
        case 223: return fde_func_0223_0x04d338(a0, a1);
        case 224: return fde_func_0224_0x04d3dc(a0, a1);
        case 225: return fde_func_0225_0x04d480(a0, a1);
        case 226: return fde_func_0226_0x04d534(a0, a1);
        case 227: return fde_func_0227_0x04d5e0(a0, a1);
        case 228: return fde_func_0228_0x04d694(a0, a1);
        case 229: return fde_func_0229_0x04d740(a0, a1);
        case 230: return fde_func_0230_0x04d7e0(a0, a1);
        case 231: return fde_func_0231_0x04d880(a0, a1);
        case 232: return fde_func_0232_0x04d920(a0, a1);
        case 233: return fde_func_0233_0x04d9c0(a0, a1);
        case 234: return fde_func_0234_0x04dcac(a0, a1);
        case 235: return fde_func_0235_0x04df98(a0, a1);
        case 236: return fde_func_0236_0x04e038(a0, a1);
        case 237: return fde_func_0237_0x04e118(a0, a1);
        case 238: return fde_func_0238_0x04e17c(a0, a1);
        case 239: return fde_func_0239_0x04e25c(a0, a1);
        case 240: return fde_func_0240_0x04e350(a0, a1);
        case 241: return fde_func_0241_0x04e3b4(a0, a1);
        case 242: return fde_func_0242_0x04e494(a0, a1);
        case 243: return fde_func_0243_0x04e5dc(a0, a1);
        case 244: return fde_func_0244_0x04e660(a0, a1);
        case 245: return fde_func_0245_0x04e81c(a0, a1);
        case 246: return fde_func_0246_0x04e928(a0, a1);
        case 247: return fde_func_0247_0x04e9ec(a0, a1);
        case 248: return fde_func_0248_0x04eb10(a0, a1);
        case 249: return fde_func_0249_0x04ed88(a0, a1);
        case 250: return fde_func_0250_0x04ef00(a0, a1);
        case 251: return fde_func_0251_0x04efa8(a0, a1);
        case 252: return fde_func_0252_0x04f270(a0, a1);
        case 253: return fde_func_0253_0x04f30c(a0, a1);
        case 254: return fde_func_0254_0x04f574(a0, a1);
        case 255: return fde_func_0255_0x04f60c(a0, a1);
        case 256: return fde_func_0256_0x04f774(a0, a1);
        case 257: return fde_func_0257_0x04f880(a0, a1);
        case 258: return fde_func_0258_0x04f960(a0, a1);
        case 259: return fde_func_0259_0x04fbd8(a0, a1);
        case 260: return fde_func_0260_0x04fd84(a0, a1);
        case 261: return fde_func_0261_0x0503f4(a0, a1);
        case 262: return fde_func_0262_0x050428(a0, a1);
        case 263: return fde_func_0263_0x050638(a0, a1);
        case 264: return fde_func_0264_0x050690(a0, a1);
        case 265: return fde_func_0265_0x0506e8(a0, a1);
        case 266: return fde_func_0266_0x050744(a0, a1);
        case 267: return fde_func_0267_0x050760(a0, a1);
        case 268: return fde_func_0268_0x050938(a0, a1);
        case 269: return fde_func_0269_0x050b28(a0, a1);
        case 270: return fde_func_0270_0x050b68(a0, a1);
        case 271: return fde_func_0271_0x050c64(a0, a1);
        case 272: return fde_func_0272_0x050cc0(a0, a1);
        case 273: return fde_func_0273_0x050d34(a0, a1);
        case 274: return fde_func_0274_0x050dd0(a0, a1);
        case 275: return fde_func_0275_0x050e40(a0, a1);
        case 276: return fde_func_0276_0x050ef0(a0, a1);
        case 277: return fde_func_0277_0x050f4c(a0, a1);
        case 278: return fde_func_0278_0x051194(a0, a1);
        case 279: return fde_func_0279_0x051334(a0, a1);
        case 280: return fde_func_0280_0x0513f0(a0, a1);
        case 281: return fde_func_0281_0x051ab4(a0, a1);
        case 282: return fde_func_0282_0x051ad0(a0, a1);
        case 283: return fde_func_0283_0x051b8c(a0, a1);
        case 284: return fde_func_0284_0x051c14(a0, a1);
        case 285: return fde_func_0285_0x051c30(a0, a1);
        case 286: return fde_func_0286_0x051cf4(a0, a1);
        case 287: return fde_func_0287_0x051d6c(a0, a1);
        case 288: return fde_func_0288_0x051d88(a0, a1);
        case 289: return fde_func_0289_0x0528e4(a0, a1);
        case 290: return fde_func_0290_0x052a88(a0, a1);
        case 291: return fde_func_0291_0x052bc4(a0, a1);
        case 292: return fde_func_0292_0x053338(a0, a1);
        case 293: return fde_func_0293_0x053770(a0, a1);
        case 294: return fde_func_0294_0x053c28(a0, a1);
        case 295: return fde_func_0295_0x053cf4(a0, a1);
        case 296: return fde_func_0296_0x053f7c(a0, a1);
        case 297: return fde_func_0297_0x05407c(a0, a1);
        case 298: return fde_func_0298_0x05415c(a0, a1);
        case 299: return fde_func_0299_0x0541fc(a0, a1);
        case 300: return fde_func_0300_0x054414(a0, a1);
        case 301: return fde_func_0301_0x0544e8(a0, a1);
        case 302: return fde_func_0302_0x05457c(a0, a1);
        case 303: return fde_func_0303_0x0546b4(a0, a1);
        case 304: return fde_func_0304_0x054748(a0, a1);
        case 305: return fde_func_0305_0x0547a4(a0, a1);
        case 306: return fde_func_0306_0x054a04(a0, a1);
        case 307: return fde_func_0307_0x054b9c(a0, a1);
        case 308: return fde_func_0308_0x054c2c(a0, a1);
        case 309: return fde_func_0309_0x054c9c(a0, a1);
        case 310: return fde_func_0310_0x054d5c(a0, a1);
        case 311: return fde_func_0311_0x0550d8(a0, a1);
        case 312: return fde_func_0312_0x055220(a0, a1);
        case 313: return fde_func_0313_0x055c8c(a0, a1);
        case 314: return fde_func_0314_0x055c90(a0, a1);
        case 315: return fde_func_0315_0x0561f0(a0, a1);
        case 316: return fde_func_0316_0x056380(a0, a1);
        case 317: return fde_func_0317_0x05639c(a0, a1);
        case 318: return fde_func_0318_0x05660c(a0, a1);
        case 319: return fde_func_0319_0x056688(a0, a1);
        case 320: return fde_func_0320_0x0567ac(a0, a1);
        case 321: return fde_func_0321_0x056920(a0, a1);
        case 322: return fde_func_0322_0x056d9c(a0, a1);
        case 323: return fde_func_0323_0x056ef0(a0, a1);
        case 324: return fde_func_0324_0x057108(a0, a1);
        case 325: return fde_func_0325_0x0572b0(a0, a1);
        case 326: return fde_func_0326_0x05731c(a0, a1);
        case 327: return fde_func_0327_0x0573f4(a0, a1);
        case 328: return fde_func_0328_0x0575c4(a0, a1);
        case 329: return fde_func_0329_0x0576b8(a0, a1);
        case 330: return fde_func_0330_0x057820(a0, a1);
        case 331: return fde_func_0331_0x0578e0(a0, a1);
        case 332: return fde_func_0332_0x057b0c(a0, a1);
        case 333: return fde_func_0333_0x057c6c(a0, a1);
        case 334: return fde_func_0334_0x058000(a0, a1);
        case 335: return fde_func_0335_0x058228(a0, a1);
        case 336: return fde_func_0336_0x0582e8(a0, a1);
        case 337: return fde_func_0337_0x05838c(a0, a1);
        case 338: return fde_func_0338_0x058520(a0, a1);
        case 339: return fde_func_0339_0x058578(a0, a1);
        case 340: return fde_func_0340_0x0585d0(a0, a1);
        case 341: return fde_func_0341_0x058688(a0, a1);
        case 342: return fde_func_0342_0x0586a4(a0, a1);
        case 343: return fde_func_0343_0x0586c0(a0, a1);
        case 344: return fde_func_0344_0x058c24(a0, a1);
        case 345: return fde_func_0345_0x058c80(a0, a1);
        case 346: return fde_func_0346_0x058d40(a0, a1);
        case 347: return fde_func_0347_0x058dcc(a0, a1);
        case 348: return fde_func_0348_0x058f9c(a0, a1);
        case 349: return fde_func_0349_0x059038(a0, a1);
        case 350: return fde_func_0350_0x059154(a0, a1);
        case 351: return fde_func_0351_0x059220(a0, a1);
        case 352: return fde_func_0352_0x0594c0(a0, a1);
        case 353: return fde_func_0353_0x0597c4(a0, a1);
        case 354: return fde_func_0354_0x059a34(a0, a1);
        case 355: return fde_func_0355_0x059d68(a0, a1);
        case 356: return fde_func_0356_0x05a15c(a0, a1);
        case 357: return fde_func_0357_0x05a508(a0, a1);
        case 358: return fde_func_0358_0x05abc8(a0, a1);
        case 359: return fde_func_0359_0x05abe4(a0, a1);
        case 360: return fde_func_0360_0x05b778(a0, a1);
        case 361: return fde_func_0361_0x05b888(a0, a1);
        case 362: return fde_func_0362_0x05b9dc(a0, a1);
        case 363: return fde_func_0363_0x05ba9c(a0, a1);
        case 364: return fde_func_0364_0x05bb2c(a0, a1);
        case 365: return fde_func_0365_0x05bda8(a0, a1);
        case 366: return fde_func_0366_0x05be30(a0, a1);
        case 367: return fde_func_0367_0x05beb4(a0, a1);
        case 368: return fde_func_0368_0x05c0ac(a0, a1);
        case 369: return fde_func_0369_0x05c2b8(a0, a1);
        case 370: return fde_func_0370_0x05c310(a0, a1);
        case 371: return fde_func_0371_0x05c38c(a0, a1);
        case 372: return fde_func_0372_0x05c62c(a0, a1);
        case 373: return fde_func_0373_0x05c750(a0, a1);
        case 374: return fde_func_0374_0x05c7d8(a0, a1);
        case 375: return fde_func_0375_0x05c8e4(a0, a1);
        case 376: return fde_func_0376_0x05c938(a0, a1);
        case 377: return fde_func_0377_0x05ca9c(a0, a1);
        case 378: return fde_func_0378_0x05cb34(a0, a1);
        case 379: return fde_func_0379_0x05cd7c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com