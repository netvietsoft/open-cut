// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 5/5 for libmetasec_ov.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 5/5 cho libmetasec_ov.so
// Covers representative FDE indices [1600 .. 1999] out of 5,296 total FDEs
// Bao phủ chỉ số FDE đại diện [1600 .. 1999] trên tổng số 5.296 FDE
// ============================================================================
#include "metasec_ov_core.h"

namespace metasec {
namespace ov {

// FDE #1600 | PC: 0x0ef0fc | FDE: 0x1ac950 | Size: 32 bytes
// Khung tháo gỡ #1600 | Địa chỉ PC: 0x0ef0fc | Địa chỉ FDE: 0x1ac950 | Kích thước: 32 bytes
//   0x0ef0fc: 12001C09  and      w9, w0, #0xff
//   0x0ef100: F900011F  str      xzr, [x8]
//   0x0ef104: B9000109  str      w9, [x8]
//   0x0ef108: D65F03C0  ret      
static inline uint64_t fde_func_1600_0x0ef0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef0fcULL ^ (static_cast<uint64_t>(0x12001c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac950ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1601 | PC: 0x0ef11c | FDE: 0x1ac980 | Size: 32 bytes
// Khung tháo gỡ #1601 | Địa chỉ PC: 0x0ef11c | Địa chỉ FDE: 0x1ac980 | Kích thước: 32 bytes
//   0x0ef11c: 13003C09  sxth     w9, w0
//   0x0ef120: F900011F  str      xzr, [x8]
//   0x0ef124: B9000109  str      w9, [x8]
//   0x0ef128: D65F03C0  ret      
static inline uint64_t fde_func_1601_0x0ef11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef11cULL ^ (static_cast<uint64_t>(0x13003c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac980ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1602 | PC: 0x0ef13c | FDE: 0x1ac9b0 | Size: 32 bytes
// Khung tháo gỡ #1602 | Địa chỉ PC: 0x0ef13c | Địa chỉ FDE: 0x1ac9b0 | Kích thước: 32 bytes
//   0x0ef13c: 12003C09  and      w9, w0, #0xffff
//   0x0ef140: F900011F  str      xzr, [x8]
//   0x0ef144: B9000109  str      w9, [x8]
//   0x0ef148: D65F03C0  ret      
static inline uint64_t fde_func_1602_0x0ef13c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef13cULL ^ (static_cast<uint64_t>(0x12003c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac9b0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1603 | PC: 0x0ef15c | FDE: 0x1ac9e0 | Size: 24 bytes
// Khung tháo gỡ #1603 | Địa chỉ PC: 0x0ef15c | Địa chỉ FDE: 0x1ac9e0 | Kích thước: 24 bytes
//   0x0ef15c: F900011F  str      xzr, [x8]
//   0x0ef160: B9000100  str      w0, [x8]
//   0x0ef164: D65F03C0  ret      
//   0x0ef168: F900001F  str      xzr, [x0]
static inline uint64_t fde_func_1603_0x0ef15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef15cULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xb9000100ULL) ^ 0x1ac9e0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1604 | PC: 0x0ef174 | FDE: 0x1aca10 | Size: 24 bytes
// Khung tháo gỡ #1604 | Địa chỉ PC: 0x0ef174 | Địa chỉ FDE: 0x1aca10 | Kích thước: 24 bytes
//   0x0ef174: F900011F  str      xzr, [x8]
//   0x0ef178: B9000100  str      w0, [x8]
//   0x0ef17c: D65F03C0  ret      
//   0x0ef180: F900001F  str      xzr, [x0]
static inline uint64_t fde_func_1604_0x0ef174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef174ULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xb9000100ULL) ^ 0x1aca10ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1605 | PC: 0x0ef18c | FDE: 0x1aca40 | Size: 16 bytes
// Khung tháo gỡ #1605 | Địa chỉ PC: 0x0ef18c | Địa chỉ FDE: 0x1aca40 | Kích thước: 16 bytes
//   0x0ef18c: F9000100  str      x0, [x8]
//   0x0ef190: D65F03C0  ret      
//   0x0ef194: F9000001  str      x1, [x0]
//   0x0ef198: D65F03C0  ret      
static inline uint64_t fde_func_1605_0x0ef18c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef18cULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1aca40ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1606 | PC: 0x0ef19c | FDE: 0x1aca70 | Size: 16 bytes
// Khung tháo gỡ #1606 | Địa chỉ PC: 0x0ef19c | Địa chỉ FDE: 0x1aca70 | Kích thước: 16 bytes
//   0x0ef19c: F9000100  str      x0, [x8]
//   0x0ef1a0: D65F03C0  ret      
//   0x0ef1a4: F9000001  str      x1, [x0]
//   0x0ef1a8: D65F03C0  ret      
static inline uint64_t fde_func_1606_0x0ef19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef19cULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1aca70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1607 | PC: 0x0ef1ac | FDE: 0x1acaa0 | Size: 16 bytes
// Khung tháo gỡ #1607 | Địa chỉ PC: 0x0ef1ac | Địa chỉ FDE: 0x1acaa0 | Kích thước: 16 bytes
//   0x0ef1ac: F9000100  str      x0, [x8]
//   0x0ef1b0: D65F03C0  ret      
//   0x0ef1b4: F9000001  str      x1, [x0]
//   0x0ef1b8: D65F03C0  ret      
static inline uint64_t fde_func_1607_0x0ef1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef1acULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acaa0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1608 | PC: 0x0ef1bc | FDE: 0x1acad0 | Size: 16 bytes
// Khung tháo gỡ #1608 | Địa chỉ PC: 0x0ef1bc | Địa chỉ FDE: 0x1acad0 | Kích thước: 16 bytes
//   0x0ef1bc: F9000100  str      x0, [x8]
//   0x0ef1c0: D65F03C0  ret      
//   0x0ef1c4: F9000001  str      x1, [x0]
//   0x0ef1c8: D65F03C0  ret      
static inline uint64_t fde_func_1608_0x0ef1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef1bcULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acad0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1609 | PC: 0x0ef1cc | FDE: 0x1acb00 | Size: 16 bytes
// Khung tháo gỡ #1609 | Địa chỉ PC: 0x0ef1cc | Địa chỉ FDE: 0x1acb00 | Kích thước: 16 bytes
//   0x0ef1cc: F9000100  str      x0, [x8]
//   0x0ef1d0: D65F03C0  ret      
//   0x0ef1d4: F9000001  str      x1, [x0]
//   0x0ef1d8: D65F03C0  ret      
static inline uint64_t fde_func_1609_0x0ef1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef1ccULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acb00ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1610 | PC: 0x0ef1dc | FDE: 0x1acb30 | Size: 20 bytes
// Khung tháo gỡ #1610 | Địa chỉ PC: 0x0ef1dc | Địa chỉ FDE: 0x1acb30 | Kích thước: 20 bytes
//   0x0ef1dc: F900011F  str      xzr, [x8]
//   0x0ef1e0: D65F03C0  ret      
//   0x0ef1e4: 52800029  mov      w9, #1
//   0x0ef1e8: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1610_0x0ef1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef1dcULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acb30ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1611 | PC: 0x0ef1f0 | FDE: 0x1acb60 | Size: 20 bytes
// Khung tháo gỡ #1611 | Địa chỉ PC: 0x0ef1f0 | Địa chỉ FDE: 0x1acb60 | Kích thước: 20 bytes
//   0x0ef1f0: 52800028  mov      w8, #1
//   0x0ef1f4: F9000008  str      x8, [x0]
//   0x0ef1f8: D65F03C0  ret      
//   0x0ef1fc: F900011F  str      xzr, [x8]
static inline uint64_t fde_func_1611_0x0ef1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef1f0ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x1acb60ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1612 | PC: 0x0ef204 | FDE: 0x1acb90 | Size: 16 bytes
// Khung tháo gỡ #1612 | Địa chỉ PC: 0x0ef204 | Địa chỉ FDE: 0x1acb90 | Kích thước: 16 bytes
//   0x0ef204: F900001F  str      xzr, [x0]
//   0x0ef208: D65F03C0  ret      
//   0x0ef20c: B9400000  ldr      w0, [x0]
//   0x0ef210: D65F03C0  ret      
static inline uint64_t fde_func_1612_0x0ef204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef204ULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acb90ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1613 | PC: 0x0ef214 | FDE: 0x1acbc0 | Size: 16 bytes
// Khung tháo gỡ #1613 | Địa chỉ PC: 0x0ef214 | Địa chỉ FDE: 0x1acbc0 | Kích thước: 16 bytes
//   0x0ef214: B9400000  ldr      w0, [x0]
//   0x0ef218: D65F03C0  ret      
//   0x0ef21c: B9400000  ldr      w0, [x0]
//   0x0ef220: D65F03C0  ret      
static inline uint64_t fde_func_1613_0x0ef214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef214ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acbc0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1614 | PC: 0x0ef224 | FDE: 0x1acbf0 | Size: 16 bytes
// Khung tháo gỡ #1614 | Địa chỉ PC: 0x0ef224 | Địa chỉ FDE: 0x1acbf0 | Kích thước: 16 bytes
//   0x0ef224: B9400000  ldr      w0, [x0]
//   0x0ef228: D65F03C0  ret      
//   0x0ef22c: B9400000  ldr      w0, [x0]
//   0x0ef230: D65F03C0  ret      
static inline uint64_t fde_func_1614_0x0ef224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef224ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acbf0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1615 | PC: 0x0ef234 | FDE: 0x1acc20 | Size: 16 bytes
// Khung tháo gỡ #1615 | Địa chỉ PC: 0x0ef234 | Địa chỉ FDE: 0x1acc20 | Kích thước: 16 bytes
//   0x0ef234: B9400000  ldr      w0, [x0]
//   0x0ef238: D65F03C0  ret      
//   0x0ef23c: F9400000  ldr      x0, [x0]
//   0x0ef240: D65F03C0  ret      
static inline uint64_t fde_func_1615_0x0ef234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef234ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acc20ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1616 | PC: 0x0ef244 | FDE: 0x1acc50 | Size: 16 bytes
// Khung tháo gỡ #1616 | Địa chỉ PC: 0x0ef244 | Địa chỉ FDE: 0x1acc50 | Kích thước: 16 bytes
//   0x0ef244: F9400000  ldr      x0, [x0]
//   0x0ef248: D65F03C0  ret      
//   0x0ef24c: F9400000  ldr      x0, [x0]
//   0x0ef250: D65F03C0  ret      
static inline uint64_t fde_func_1616_0x0ef244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef244ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acc50ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1617 | PC: 0x0ef254 | FDE: 0x1acc80 | Size: 16 bytes
// Khung tháo gỡ #1617 | Địa chỉ PC: 0x0ef254 | Địa chỉ FDE: 0x1acc80 | Kích thước: 16 bytes
//   0x0ef254: F9400000  ldr      x0, [x0]
//   0x0ef258: D65F03C0  ret      
//   0x0ef25c: BD400000  ldr      s0, [x0]
//   0x0ef260: D65F03C0  ret      
static inline uint64_t fde_func_1617_0x0ef254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef254ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acc80ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1618 | PC: 0x0ef264 | FDE: 0x1accb0 | Size: 16 bytes
// Khung tháo gỡ #1618 | Địa chỉ PC: 0x0ef264 | Địa chỉ FDE: 0x1accb0 | Kích thước: 16 bytes
//   0x0ef264: FD400000  ldr      d0, [x0]
//   0x0ef268: D65F03C0  ret      
//   0x0ef26c: B9400000  ldr      w0, [x0]
//   0x0ef270: D65F03C0  ret      
static inline uint64_t fde_func_1618_0x0ef264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef264ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1accb0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1619 | PC: 0x0ef274 | FDE: 0x1acce0 | Size: 16 bytes
// Khung tháo gỡ #1619 | Địa chỉ PC: 0x0ef274 | Địa chỉ FDE: 0x1acce0 | Kích thước: 16 bytes
//   0x0ef274: B9400000  ldr      w0, [x0]
//   0x0ef278: D65F03C0  ret      
//   0x0ef27c: B9400000  ldr      w0, [x0]
//   0x0ef280: D65F03C0  ret      
static inline uint64_t fde_func_1619_0x0ef274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef274ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acce0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1620 | PC: 0x0ef284 | FDE: 0x1acd10 | Size: 16 bytes
// Khung tháo gỡ #1620 | Địa chỉ PC: 0x0ef284 | Địa chỉ FDE: 0x1acd10 | Kích thước: 16 bytes
//   0x0ef284: B9400000  ldr      w0, [x0]
//   0x0ef288: D65F03C0  ret      
//   0x0ef28c: B9400000  ldr      w0, [x0]
//   0x0ef290: D65F03C0  ret      
static inline uint64_t fde_func_1620_0x0ef284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef284ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acd10ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1621 | PC: 0x0ef294 | FDE: 0x1acd40 | Size: 16 bytes
// Khung tháo gỡ #1621 | Địa chỉ PC: 0x0ef294 | Địa chỉ FDE: 0x1acd40 | Kích thước: 16 bytes
//   0x0ef294: B9400000  ldr      w0, [x0]
//   0x0ef298: D65F03C0  ret      
//   0x0ef29c: F9400000  ldr      x0, [x0]
//   0x0ef2a0: D65F03C0  ret      
static inline uint64_t fde_func_1621_0x0ef294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef294ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acd40ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1622 | PC: 0x0ef2a4 | FDE: 0x1acd70 | Size: 16 bytes
// Khung tháo gỡ #1622 | Địa chỉ PC: 0x0ef2a4 | Địa chỉ FDE: 0x1acd70 | Kích thước: 16 bytes
//   0x0ef2a4: F9400000  ldr      x0, [x0]
//   0x0ef2a8: D65F03C0  ret      
//   0x0ef2ac: F9400000  ldr      x0, [x0]
//   0x0ef2b0: D65F03C0  ret      
static inline uint64_t fde_func_1622_0x0ef2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef2a4ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acd70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1623 | PC: 0x0ef2b4 | FDE: 0x1acda0 | Size: 24 bytes
// Khung tháo gỡ #1623 | Địa chỉ PC: 0x0ef2b4 | Địa chỉ FDE: 0x1acda0 | Kích thước: 24 bytes
//   0x0ef2b4: F9400000  ldr      x0, [x0]
//   0x0ef2b8: D65F03C0  ret      
//   0x0ef2bc: F9400008  ldr      x8, [x0]
//   0x0ef2c0: F100011F  cmp      x8, #0
static inline uint64_t fde_func_1623_0x0ef2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef2b4ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acda0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1624 | PC: 0x0ef2cc | FDE: 0x1acdd0 | Size: 20 bytes
// Khung tháo gỡ #1624 | Địa chỉ PC: 0x0ef2cc | Địa chỉ FDE: 0x1acdd0 | Kích thước: 20 bytes
//   0x0ef2cc: F900001F  str      xzr, [x0]
//   0x0ef2d0: D65F03C0  ret      
//   0x0ef2d4: 528041C0  mov      w0, #0x20e
//   0x0ef2d8: 72A00020  movk     w0, #1, lsl #16
static inline uint64_t fde_func_1624_0x0ef2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef2ccULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1acdd0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1625 | PC: 0x0ef2e0 | FDE: 0x1ace00 | Size: 80 bytes
// Khung tháo gỡ #1625 | Địa chỉ PC: 0x0ef2e0 | Địa chỉ FDE: 0x1ace00 | Kích thước: 80 bytes
//   0x0ef2e0: 528002A0  mov      w0, #0x15
//   0x0ef2e4: D65F03C0  ret      
//   0x0ef2e8: D100C3FF  sub      sp, sp, #0x30
//   0x0ef2ec: A9014FF4  stp      x20, x19, [sp, #0x10]
static inline uint64_t fde_func_1625_0x0ef2e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef2e0ULL ^ (static_cast<uint64_t>(0x528002a0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ace00ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1626 | PC: 0x0ef330 | FDE: 0x1ace38 | Size: 144 bytes
// Khung tháo gỡ #1626 | Địa chỉ PC: 0x0ef330 | Địa chỉ FDE: 0x1ace38 | Kích thước: 144 bytes
//   0x0ef330: B40000C0  cbz      x0, #0xef348
//   0x0ef334: F9400008  ldr      x8, [x0]
//   0x0ef338: F9005D01  str      x1, [x8, #0xb8]
//   0x0ef33c: F0000768  adrp     x8, #0x1de000
static inline uint64_t fde_func_1626_0x0ef330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef330ULL ^ (static_cast<uint64_t>(0xb40000c0ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1ace38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1627 | PC: 0x0ef3c0 | FDE: 0x1ace70 | Size: 68 bytes
// Khung tháo gỡ #1627 | Địa chỉ PC: 0x0ef3c0 | Địa chỉ FDE: 0x1ace70 | Kích thước: 68 bytes
//   0x0ef3c0: B4000040  cbz      x0, #0xef3c8
//   0x0ef3c4: 17FFFD6F  b        #0xee980
//   0x0ef3c8: 52800BC0  mov      w0, #0x5e
//   0x0ef3cc: D65F03C0  ret      
static inline uint64_t fde_func_1627_0x0ef3c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef3c0ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0x17fffd6fULL) ^ 0x1ace70ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1628 | PC: 0x0ef404 | FDE: 0x1acea8 | Size: 148 bytes
// Khung tháo gỡ #1628 | Địa chỉ PC: 0x0ef404 | Địa chỉ FDE: 0x1acea8 | Kích thước: 148 bytes
//   0x0ef404: D100C3FF  sub      sp, sp, #0x30
//   0x0ef408: F9000BF3  str      x19, [sp, #0x10]
//   0x0ef40c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ef410: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1628_0x0ef404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef404ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1acea8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1629 | PC: 0x0ef498 | FDE: 0x1acee8 | Size: 256 bytes
// Khung tháo gỡ #1629 | Địa chỉ PC: 0x0ef498 | Địa chỉ FDE: 0x1acee8 | Kích thước: 256 bytes
//   0x0ef498: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0ef49c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0ef4a0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ef4a4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1629_0x0ef498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef498ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1acee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1630 | PC: 0x0ef650 | FDE: 0x1acf40 | Size: 80 bytes
// Khung tháo gỡ #1630 | Địa chỉ PC: 0x0ef650 | Địa chỉ FDE: 0x1acf40 | Kích thước: 80 bytes
//   0x0ef650: B40001C0  cbz      x0, #0xef688
//   0x0ef654: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ef658: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ef65c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1630_0x0ef650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef650ULL ^ (static_cast<uint64_t>(0xb40001c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1acf40ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1631 | PC: 0x0ef6a0 | FDE: 0x1acf78 | Size: 24 bytes
// Khung tháo gỡ #1631 | Địa chỉ PC: 0x0ef6a0 | Địa chỉ FDE: 0x1acf78 | Kích thước: 24 bytes
//   0x0ef6a0: B4000040  cbz      x0, #0xef6a8
//   0x0ef6a4: 17FFFE2A  b        #0xeef4c
//   0x0ef6a8: 52800BC0  mov      w0, #0x5e
//   0x0ef6ac: D65F03C0  ret      
static inline uint64_t fde_func_1631_0x0ef6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef6a0ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0x17fffe2aULL) ^ 0x1acf78ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1632 | PC: 0x0ef6b8 | FDE: 0x1acfa8 | Size: 24 bytes
// Khung tháo gỡ #1632 | Địa chỉ PC: 0x0ef6b8 | Địa chỉ FDE: 0x1acfa8 | Kích thước: 24 bytes
//   0x0ef6b8: 12001C28  and      w8, w1, #0xff
//   0x0ef6bc: F900001F  str      xzr, [x0]
//   0x0ef6c0: B9000008  str      w8, [x0]
//   0x0ef6c4: D65F03C0  ret      
static inline uint64_t fde_func_1632_0x0ef6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef6b8ULL ^ (static_cast<uint64_t>(0x12001c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1acfa8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1633 | PC: 0x0ef6d0 | FDE: 0x1acfd8 | Size: 28 bytes
// Khung tháo gỡ #1633 | Địa chỉ PC: 0x0ef6d0 | Địa chỉ FDE: 0x1acfd8 | Kích thước: 28 bytes
//   0x0ef6d0: 12001C28  and      w8, w1, #0xff
//   0x0ef6d4: F900001F  str      xzr, [x0]
//   0x0ef6d8: B9000008  str      w8, [x0]
//   0x0ef6dc: D65F03C0  ret      
static inline uint64_t fde_func_1633_0x0ef6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef6d0ULL ^ (static_cast<uint64_t>(0x12001c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1acfd8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1634 | PC: 0x0ef6ec | FDE: 0x1ad008 | Size: 24 bytes
// Khung tháo gỡ #1634 | Địa chỉ PC: 0x0ef6ec | Địa chỉ FDE: 0x1ad008 | Kích thước: 24 bytes
//   0x0ef6ec: 13003C28  sxth     w8, w1
//   0x0ef6f0: F900001F  str      xzr, [x0]
//   0x0ef6f4: B9000008  str      w8, [x0]
//   0x0ef6f8: D65F03C0  ret      
static inline uint64_t fde_func_1634_0x0ef6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef6ecULL ^ (static_cast<uint64_t>(0x13003c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1ad008ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1635 | PC: 0x0ef704 | FDE: 0x1ad038 | Size: 24 bytes
// Khung tháo gỡ #1635 | Địa chỉ PC: 0x0ef704 | Địa chỉ FDE: 0x1ad038 | Kích thước: 24 bytes
//   0x0ef704: 12003C28  and      w8, w1, #0xffff
//   0x0ef708: F900001F  str      xzr, [x0]
//   0x0ef70c: B9000008  str      w8, [x0]
//   0x0ef710: D65F03C0  ret      
static inline uint64_t fde_func_1635_0x0ef704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef704ULL ^ (static_cast<uint64_t>(0x12003c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1ad038ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1636 | PC: 0x0ef71c | FDE: 0x1ad068 | Size: 20 bytes
// Khung tháo gỡ #1636 | Địa chỉ PC: 0x0ef71c | Địa chỉ FDE: 0x1ad068 | Kích thước: 20 bytes
//   0x0ef71c: F900001F  str      xzr, [x0]
//   0x0ef720: B9000001  str      w1, [x0]
//   0x0ef724: D65F03C0  ret      
//   0x0ef728: 2A0003E0  mov      w0, w0
static inline uint64_t fde_func_1636_0x0ef71c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef71cULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xb9000001ULL) ^ 0x1ad068ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1637 | PC: 0x0ef730 | FDE: 0x1ad098 | Size: 16 bytes
// Khung tháo gỡ #1637 | Địa chỉ PC: 0x0ef730 | Địa chỉ FDE: 0x1ad098 | Kích thước: 16 bytes
//   0x0ef730: F900001F  str      xzr, [x0]
//   0x0ef734: B9000001  str      w1, [x0]
//   0x0ef738: D65F03C0  ret      
//   0x0ef73c: D65F03C0  ret      
static inline uint64_t fde_func_1637_0x0ef730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef730ULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xb9000001ULL) ^ 0x1ad098ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1638 | PC: 0x0ef740 | FDE: 0x1ad0c8 | Size: 12 bytes
// Khung tháo gỡ #1638 | Địa chỉ PC: 0x0ef740 | Địa chỉ FDE: 0x1ad0c8 | Kích thước: 12 bytes
//   0x0ef740: F9000001  str      x1, [x0]
//   0x0ef744: D65F03C0  ret      
//   0x0ef748: D65F03C0  ret      
static inline uint64_t fde_func_1638_0x0ef740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef740ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad0c8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1639 | PC: 0x0ef74c | FDE: 0x1ad0f8 | Size: 12 bytes
// Khung tháo gỡ #1639 | Địa chỉ PC: 0x0ef74c | Địa chỉ FDE: 0x1ad0f8 | Kích thước: 12 bytes
//   0x0ef74c: F9000001  str      x1, [x0]
//   0x0ef750: D65F03C0  ret      
//   0x0ef754: D65F03C0  ret      
static inline uint64_t fde_func_1639_0x0ef74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef74cULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad0f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1640 | PC: 0x0ef758 | FDE: 0x1ad128 | Size: 12 bytes
// Khung tháo gỡ #1640 | Địa chỉ PC: 0x0ef758 | Địa chỉ FDE: 0x1ad128 | Kích thước: 12 bytes
//   0x0ef758: F9000001  str      x1, [x0]
//   0x0ef75c: D65F03C0  ret      
//   0x0ef760: D65F03C0  ret      
static inline uint64_t fde_func_1640_0x0ef758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef758ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad128ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1641 | PC: 0x0ef764 | FDE: 0x1ad158 | Size: 16 bytes
// Khung tháo gỡ #1641 | Địa chỉ PC: 0x0ef764 | Địa chỉ FDE: 0x1ad158 | Kích thước: 16 bytes
//   0x0ef764: F9000001  str      x1, [x0]
//   0x0ef768: D65F03C0  ret      
//   0x0ef76c: 1E260000  fmov     w0, s0
//   0x0ef770: D65F03C0  ret      
static inline uint64_t fde_func_1641_0x0ef764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef764ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad158ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1642 | PC: 0x0ef774 | FDE: 0x1ad188 | Size: 16 bytes
// Khung tháo gỡ #1642 | Địa chỉ PC: 0x0ef774 | Địa chỉ FDE: 0x1ad188 | Kích thước: 16 bytes
//   0x0ef774: BD000000  str      s0, [x0]
//   0x0ef778: D65F03C0  ret      
//   0x0ef77c: 9E660000  fmov     x0, d0
//   0x0ef780: D65F03C0  ret      
static inline uint64_t fde_func_1642_0x0ef774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef774ULL ^ (static_cast<uint64_t>(0xbd000000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad188ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1643 | PC: 0x0ef784 | FDE: 0x1ad1b8 | Size: 20 bytes
// Khung tháo gỡ #1643 | Địa chỉ PC: 0x0ef784 | Địa chỉ FDE: 0x1ad1b8 | Kích thước: 20 bytes
//   0x0ef784: FD000000  str      d0, [x0]
//   0x0ef788: D65F03C0  ret      
//   0x0ef78c: 93401C08  sxtb     x8, w0
//   0x0ef790: 92407D00  and      x0, x8, #0xffffffff
static inline uint64_t fde_func_1643_0x0ef784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef784ULL ^ (static_cast<uint64_t>(0xfd000000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad1b8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1644 | PC: 0x0ef798 | FDE: 0x1ad1e8 | Size: 24 bytes
// Khung tháo gỡ #1644 | Địa chỉ PC: 0x0ef798 | Địa chỉ FDE: 0x1ad1e8 | Kích thước: 24 bytes
//   0x0ef798: 13001C28  sxtb     w8, w1
//   0x0ef79c: F900001F  str      xzr, [x0]
//   0x0ef7a0: B9000008  str      w8, [x0]
//   0x0ef7a4: D65F03C0  ret      
static inline uint64_t fde_func_1644_0x0ef798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef798ULL ^ (static_cast<uint64_t>(0x13001c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1ad1e8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1645 | PC: 0x0ef7b0 | FDE: 0x1ad218 | Size: 28 bytes
// Khung tháo gỡ #1645 | Địa chỉ PC: 0x0ef7b0 | Địa chỉ FDE: 0x1ad218 | Kích thước: 28 bytes
//   0x0ef7b0: 12001C28  and      w8, w1, #0xff
//   0x0ef7b4: F900001F  str      xzr, [x0]
//   0x0ef7b8: B9000008  str      w8, [x0]
//   0x0ef7bc: D65F03C0  ret      
static inline uint64_t fde_func_1645_0x0ef7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef7b0ULL ^ (static_cast<uint64_t>(0x12001c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1ad218ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1646 | PC: 0x0ef7cc | FDE: 0x1ad248 | Size: 24 bytes
// Khung tháo gỡ #1646 | Địa chỉ PC: 0x0ef7cc | Địa chỉ FDE: 0x1ad248 | Kích thước: 24 bytes
//   0x0ef7cc: 13003C28  sxth     w8, w1
//   0x0ef7d0: F900001F  str      xzr, [x0]
//   0x0ef7d4: B9000008  str      w8, [x0]
//   0x0ef7d8: D65F03C0  ret      
static inline uint64_t fde_func_1646_0x0ef7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef7ccULL ^ (static_cast<uint64_t>(0x13003c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1ad248ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1647 | PC: 0x0ef7e4 | FDE: 0x1ad278 | Size: 24 bytes
// Khung tháo gỡ #1647 | Địa chỉ PC: 0x0ef7e4 | Địa chỉ FDE: 0x1ad278 | Kích thước: 24 bytes
//   0x0ef7e4: 12003C28  and      w8, w1, #0xffff
//   0x0ef7e8: F900001F  str      xzr, [x0]
//   0x0ef7ec: B9000008  str      w8, [x0]
//   0x0ef7f0: D65F03C0  ret      
static inline uint64_t fde_func_1647_0x0ef7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef7e4ULL ^ (static_cast<uint64_t>(0x12003c28ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x1ad278ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1648 | PC: 0x0ef7fc | FDE: 0x1ad2a8 | Size: 20 bytes
// Khung tháo gỡ #1648 | Địa chỉ PC: 0x0ef7fc | Địa chỉ FDE: 0x1ad2a8 | Kích thước: 20 bytes
//   0x0ef7fc: F900001F  str      xzr, [x0]
//   0x0ef800: B9000001  str      w1, [x0]
//   0x0ef804: D65F03C0  ret      
//   0x0ef808: 2A0003E0  mov      w0, w0
static inline uint64_t fde_func_1648_0x0ef7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef7fcULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xb9000001ULL) ^ 0x1ad2a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1649 | PC: 0x0ef810 | FDE: 0x1ad2d8 | Size: 16 bytes
// Khung tháo gỡ #1649 | Địa chỉ PC: 0x0ef810 | Địa chỉ FDE: 0x1ad2d8 | Kích thước: 16 bytes
//   0x0ef810: F900001F  str      xzr, [x0]
//   0x0ef814: B9000001  str      w1, [x0]
//   0x0ef818: D65F03C0  ret      
//   0x0ef81c: D65F03C0  ret      
static inline uint64_t fde_func_1649_0x0ef810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef810ULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xb9000001ULL) ^ 0x1ad2d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1650 | PC: 0x0ef820 | FDE: 0x1ad308 | Size: 12 bytes
// Khung tháo gỡ #1650 | Địa chỉ PC: 0x0ef820 | Địa chỉ FDE: 0x1ad308 | Kích thước: 12 bytes
//   0x0ef820: F9000001  str      x1, [x0]
//   0x0ef824: D65F03C0  ret      
//   0x0ef828: D65F03C0  ret      
static inline uint64_t fde_func_1650_0x0ef820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef820ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad308ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1651 | PC: 0x0ef82c | FDE: 0x1ad338 | Size: 12 bytes
// Khung tháo gỡ #1651 | Địa chỉ PC: 0x0ef82c | Địa chỉ FDE: 0x1ad338 | Kích thước: 12 bytes
//   0x0ef82c: F9000001  str      x1, [x0]
//   0x0ef830: D65F03C0  ret      
//   0x0ef834: D65F03C0  ret      
static inline uint64_t fde_func_1651_0x0ef82c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef82cULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad338ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1652 | PC: 0x0ef838 | FDE: 0x1ad368 | Size: 12 bytes
// Khung tháo gỡ #1652 | Địa chỉ PC: 0x0ef838 | Địa chỉ FDE: 0x1ad368 | Kích thước: 12 bytes
//   0x0ef838: F9000001  str      x1, [x0]
//   0x0ef83c: D65F03C0  ret      
//   0x0ef840: D65F03C0  ret      
static inline uint64_t fde_func_1652_0x0ef838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef838ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad368ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1653 | PC: 0x0ef844 | FDE: 0x1ad398 | Size: 12 bytes
// Khung tháo gỡ #1653 | Địa chỉ PC: 0x0ef844 | Địa chỉ FDE: 0x1ad398 | Kích thước: 12 bytes
//   0x0ef844: F9000001  str      x1, [x0]
//   0x0ef848: D65F03C0  ret      
//   0x0ef84c: D65F03C0  ret      
static inline uint64_t fde_func_1653_0x0ef844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef844ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad398ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1654 | PC: 0x0ef850 | FDE: 0x1ad3c8 | Size: 12 bytes
// Khung tháo gỡ #1654 | Địa chỉ PC: 0x0ef850 | Địa chỉ FDE: 0x1ad3c8 | Kích thước: 12 bytes
//   0x0ef850: F9000001  str      x1, [x0]
//   0x0ef854: D65F03C0  ret      
//   0x0ef858: D65F03C0  ret      
static inline uint64_t fde_func_1654_0x0ef850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef850ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad3c8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1655 | PC: 0x0ef85c | FDE: 0x1ad3f8 | Size: 20 bytes
// Khung tháo gỡ #1655 | Địa chỉ PC: 0x0ef85c | Địa chỉ FDE: 0x1ad3f8 | Kích thước: 20 bytes
//   0x0ef85c: 52800020  mov      w0, #1
//   0x0ef860: D65F03C0  ret      
//   0x0ef864: 52800028  mov      w8, #1
//   0x0ef868: F9000008  str      x8, [x0]
static inline uint64_t fde_func_1655_0x0ef85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef85cULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad3f8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1656 | PC: 0x0ef870 | FDE: 0x1ad428 | Size: 16 bytes
// Khung tháo gỡ #1656 | Địa chỉ PC: 0x0ef870 | Địa chỉ FDE: 0x1ad428 | Kích thước: 16 bytes
//   0x0ef870: AA1F03E0  mov      x0, xzr
//   0x0ef874: D65F03C0  ret      
//   0x0ef878: F900001F  str      xzr, [x0]
//   0x0ef87c: D65F03C0  ret      
static inline uint64_t fde_func_1656_0x0ef870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef870ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad428ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1657 | PC: 0x0ef880 | FDE: 0x1ad458 | Size: 16 bytes
// Khung tháo gỡ #1657 | Địa chỉ PC: 0x0ef880 | Địa chỉ FDE: 0x1ad458 | Kích thước: 16 bytes
//   0x0ef880: B9400000  ldr      w0, [x0]
//   0x0ef884: D65F03C0  ret      
//   0x0ef888: B9400000  ldr      w0, [x0]
//   0x0ef88c: D65F03C0  ret      
static inline uint64_t fde_func_1657_0x0ef880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef880ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad458ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1658 | PC: 0x0ef890 | FDE: 0x1ad488 | Size: 16 bytes
// Khung tháo gỡ #1658 | Địa chỉ PC: 0x0ef890 | Địa chỉ FDE: 0x1ad488 | Kích thước: 16 bytes
//   0x0ef890: B9400000  ldr      w0, [x0]
//   0x0ef894: D65F03C0  ret      
//   0x0ef898: B9400000  ldr      w0, [x0]
//   0x0ef89c: D65F03C0  ret      
static inline uint64_t fde_func_1658_0x0ef890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef890ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad488ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1659 | PC: 0x0ef8a0 | FDE: 0x1ad4b8 | Size: 16 bytes
// Khung tháo gỡ #1659 | Địa chỉ PC: 0x0ef8a0 | Địa chỉ FDE: 0x1ad4b8 | Kích thước: 16 bytes
//   0x0ef8a0: B9400000  ldr      w0, [x0]
//   0x0ef8a4: D65F03C0  ret      
//   0x0ef8a8: B9400000  ldr      w0, [x0]
//   0x0ef8ac: D65F03C0  ret      
static inline uint64_t fde_func_1659_0x0ef8a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef8a0ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad4b8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1660 | PC: 0x0ef8b0 | FDE: 0x1ad4e8 | Size: 16 bytes
// Khung tháo gỡ #1660 | Địa chỉ PC: 0x0ef8b0 | Địa chỉ FDE: 0x1ad4e8 | Kích thước: 16 bytes
//   0x0ef8b0: F9400000  ldr      x0, [x0]
//   0x0ef8b4: D65F03C0  ret      
//   0x0ef8b8: F9400000  ldr      x0, [x0]
//   0x0ef8bc: D65F03C0  ret      
static inline uint64_t fde_func_1660_0x0ef8b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef8b0ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad4e8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1661 | PC: 0x0ef8c0 | FDE: 0x1ad518 | Size: 16 bytes
// Khung tháo gỡ #1661 | Địa chỉ PC: 0x0ef8c0 | Địa chỉ FDE: 0x1ad518 | Kích thước: 16 bytes
//   0x0ef8c0: F9400000  ldr      x0, [x0]
//   0x0ef8c4: D65F03C0  ret      
//   0x0ef8c8: F9400000  ldr      x0, [x0]
//   0x0ef8cc: D65F03C0  ret      
static inline uint64_t fde_func_1661_0x0ef8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef8c0ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad518ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1662 | PC: 0x0ef8d0 | FDE: 0x1ad548 | Size: 16 bytes
// Khung tháo gỡ #1662 | Địa chỉ PC: 0x0ef8d0 | Địa chỉ FDE: 0x1ad548 | Kích thước: 16 bytes
//   0x0ef8d0: BD400000  ldr      s0, [x0]
//   0x0ef8d4: D65F03C0  ret      
//   0x0ef8d8: FD400000  ldr      d0, [x0]
//   0x0ef8dc: D65F03C0  ret      
static inline uint64_t fde_func_1662_0x0ef8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef8d0ULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad548ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1663 | PC: 0x0ef8e0 | FDE: 0x1ad578 | Size: 16 bytes
// Khung tháo gỡ #1663 | Địa chỉ PC: 0x0ef8e0 | Địa chỉ FDE: 0x1ad578 | Kích thước: 16 bytes
//   0x0ef8e0: B9400000  ldr      w0, [x0]
//   0x0ef8e4: D65F03C0  ret      
//   0x0ef8e8: B9400000  ldr      w0, [x0]
//   0x0ef8ec: D65F03C0  ret      
static inline uint64_t fde_func_1663_0x0ef8e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef8e0ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad578ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1664 | PC: 0x0ef8f0 | FDE: 0x1ad5a8 | Size: 16 bytes
// Khung tháo gỡ #1664 | Địa chỉ PC: 0x0ef8f0 | Địa chỉ FDE: 0x1ad5a8 | Kích thước: 16 bytes
//   0x0ef8f0: B9400000  ldr      w0, [x0]
//   0x0ef8f4: D65F03C0  ret      
//   0x0ef8f8: B9400000  ldr      w0, [x0]
//   0x0ef8fc: D65F03C0  ret      
static inline uint64_t fde_func_1664_0x0ef8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef8f0ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad5a8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1665 | PC: 0x0ef900 | FDE: 0x1ad5d8 | Size: 16 bytes
// Khung tháo gỡ #1665 | Địa chỉ PC: 0x0ef900 | Địa chỉ FDE: 0x1ad5d8 | Kích thước: 16 bytes
//   0x0ef900: B9400000  ldr      w0, [x0]
//   0x0ef904: D65F03C0  ret      
//   0x0ef908: B9400000  ldr      w0, [x0]
//   0x0ef90c: D65F03C0  ret      
static inline uint64_t fde_func_1665_0x0ef900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef900ULL ^ (static_cast<uint64_t>(0xb9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad5d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1666 | PC: 0x0ef910 | FDE: 0x1ad608 | Size: 16 bytes
// Khung tháo gỡ #1666 | Địa chỉ PC: 0x0ef910 | Địa chỉ FDE: 0x1ad608 | Kích thước: 16 bytes
//   0x0ef910: F9400000  ldr      x0, [x0]
//   0x0ef914: D65F03C0  ret      
//   0x0ef918: F9400000  ldr      x0, [x0]
//   0x0ef91c: D65F03C0  ret      
static inline uint64_t fde_func_1666_0x0ef910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef910ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad608ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1667 | PC: 0x0ef920 | FDE: 0x1ad638 | Size: 16 bytes
// Khung tháo gỡ #1667 | Địa chỉ PC: 0x0ef920 | Địa chỉ FDE: 0x1ad638 | Kích thước: 16 bytes
//   0x0ef920: F9400000  ldr      x0, [x0]
//   0x0ef924: D65F03C0  ret      
//   0x0ef928: F9400000  ldr      x0, [x0]
//   0x0ef92c: D65F03C0  ret      
static inline uint64_t fde_func_1667_0x0ef920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef920ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad638ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1668 | PC: 0x0ef930 | FDE: 0x1ad668 | Size: 24 bytes
// Khung tháo gỡ #1668 | Địa chỉ PC: 0x0ef930 | Địa chỉ FDE: 0x1ad668 | Kích thước: 24 bytes
//   0x0ef930: F9400008  ldr      x8, [x0]
//   0x0ef934: F100011F  cmp      x8, #0
//   0x0ef938: 1A9F07E0  cset     w0, ne
//   0x0ef93c: D65F03C0  ret      
static inline uint64_t fde_func_1668_0x0ef930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef930ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x1ad668ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1669 | PC: 0x0ef948 | FDE: 0x1ad6c0 | Size: 8 bytes
// Khung tháo gỡ #1669 | Địa chỉ PC: 0x0ef948 | Địa chỉ FDE: 0x1ad6c0 | Kích thước: 8 bytes
//   0x0ef948: 17FCF9BA  b        #0x2e030
//   0x0ef94c: 17FCFA21  b        #0x2e1d0
static inline uint64_t fde_func_1669_0x0ef948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef948ULL ^ (static_cast<uint64_t>(0x17fcf9baULL) << 13);
    acc = (acc + a1 + 0x17fcfa21ULL) ^ 0x1ad6c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1670 | PC: 0x0ef950 | FDE: 0x1ad6f0 | Size: 8 bytes
// Khung tháo gỡ #1670 | Địa chỉ PC: 0x0ef950 | Địa chỉ FDE: 0x1ad6f0 | Kích thước: 8 bytes
//   0x0ef950: 17FCFABC  b        #0x2e440
//   0x0ef954: 17FCFC13  b        #0x2e9a0
static inline uint64_t fde_func_1670_0x0ef950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef950ULL ^ (static_cast<uint64_t>(0x17fcfabcULL) << 13);
    acc = (acc + a1 + 0x17fcfc13ULL) ^ 0x1ad6f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1671 | PC: 0x0ef958 | FDE: 0x1ad720 | Size: 28 bytes
// Khung tháo gỡ #1671 | Địa chỉ PC: 0x0ef958 | Địa chỉ FDE: 0x1ad720 | Kích thước: 28 bytes
//   0x0ef958: 17FCFA72  b        #0x2e320
//   0x0ef95c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ef960: 910003FD  mov      x29, sp
//   0x0ef964: 97FCFB47  bl       #0x2e680
static inline uint64_t fde_func_1671_0x0ef958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef958ULL ^ (static_cast<uint64_t>(0x17fcfa72ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1ad720ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1672 | PC: 0x0ef974 | FDE: 0x1ad758 | Size: 36 bytes
// Khung tháo gỡ #1672 | Địa chỉ PC: 0x0ef974 | Địa chỉ FDE: 0x1ad758 | Kích thước: 36 bytes
//   0x0ef974: F0000461  adrp     x1, #0x17e000
//   0x0ef978: AA0003E2  mov      x2, x0
//   0x0ef97c: 910DF021  add      x1, x1, #0x37c
//   0x0ef980: 52800080  mov      w0, #4
static inline uint64_t fde_func_1672_0x0ef974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef974ULL ^ (static_cast<uint64_t>(0xf0000461ULL) << 13);
    acc = (acc + a1 + 0xaa0003e2ULL) ^ 0x1ad758ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1673 | PC: 0x0ef998 | FDE: 0x1ad788 | Size: 160 bytes
// Khung tháo gỡ #1673 | Địa chỉ PC: 0x0ef998 | Địa chỉ FDE: 0x1ad788 | Kích thước: 160 bytes
//   0x0ef998: F900011F  str      xzr, [x8]
//   0x0ef99c: D65F03C0  ret      
//   0x0ef9a0: D10143FF  sub      sp, sp, #0x50
//   0x0ef9a4: F90013F5  str      x21, [sp, #0x20]
static inline uint64_t fde_func_1673_0x0ef998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef998ULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ad788ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1674 | PC: 0x0efa38 | FDE: 0x1ad7c0 | Size: 212 bytes
// Khung tháo gỡ #1674 | Địa chỉ PC: 0x0efa38 | Địa chỉ FDE: 0x1ad7c0 | Kích thước: 212 bytes
//   0x0efa38: F9400000  ldr      x0, [x0]
//   0x0efa3c: F9400021  ldr      x1, [x1]
//   0x0efa40: 17FCF9F4  b        #0x2e210
//   0x0efa44: D10143FF  sub      sp, sp, #0x50
static inline uint64_t fde_func_1674_0x0efa38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efa38ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xf9400021ULL) ^ 0x1ad7c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1675 | PC: 0x0efb0c | FDE: 0x1ad800 | Size: 96 bytes
// Khung tháo gỡ #1675 | Địa chỉ PC: 0x0efb0c | Địa chỉ FDE: 0x1ad800 | Kích thước: 96 bytes
//   0x0efb0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0efb10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0efb14: 910043FD  add      x29, sp, #0x10
//   0x0efb18: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1675_0x0efb0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efb0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ad800ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1676 | PC: 0x0efb6c | FDE: 0x1ad860 | Size: 180 bytes
// Khung tháo gỡ #1676 | Địa chỉ PC: 0x0efb6c | Địa chỉ FDE: 0x1ad860 | Kích thước: 180 bytes
//   0x0efb6c: D10183FF  sub      sp, sp, #0x60
//   0x0efb70: F90013F7  str      x23, [sp, #0x20]
//   0x0efb74: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0efb78: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1676_0x0efb6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efb6cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1ad860ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1677 | PC: 0x0efc20 | FDE: 0x1ad8a0 | Size: 256 bytes
// Khung tháo gỡ #1677 | Địa chỉ PC: 0x0efc20 | Địa chỉ FDE: 0x1ad8a0 | Kích thước: 256 bytes
//   0x0efc20: B4000261  cbz      x1, #0xefc6c
//   0x0efc24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0efc28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0efc2c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1677_0x0efc20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efc20ULL ^ (static_cast<uint64_t>(0xb4000261ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1ad8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1678 | PC: 0x0eff48 | FDE: 0x1ad8f0 | Size: 256 bytes
// Khung tháo gỡ #1678 | Địa chỉ PC: 0x0eff48 | Địa chỉ FDE: 0x1ad8f0 | Kích thước: 256 bytes
//   0x0eff48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0eff4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eff50: 910043FD  add      x29, sp, #0x10
//   0x0eff54: A9007C7F  stp      xzr, xzr, [x3]
static inline uint64_t fde_func_1678_0x0eff48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eff48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ad8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1679 | PC: 0x0f00c0 | FDE: 0x1ad940 | Size: 256 bytes
// Khung tháo gỡ #1679 | Địa chỉ PC: 0x0f00c0 | Địa chỉ FDE: 0x1ad940 | Kích thước: 256 bytes
//   0x0f00c0: 7107FC1F  cmp      w0, #0x1ff
//   0x0f00c4: 54000069  b.ls     #0xf00d0
//   0x0f00c8: 2A1F03E0  mov      w0, wzr
//   0x0f00cc: D65F03C0  ret      
static inline uint64_t fde_func_1679_0x0f00c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f00c0ULL ^ (static_cast<uint64_t>(0x7107fc1fULL) << 13);
    acc = (acc + a1 + 0x54000069ULL) ^ 0x1ad940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1680 | PC: 0x0f02b4 | FDE: 0x1ad980 | Size: 256 bytes
// Khung tháo gỡ #1680 | Địa chỉ PC: 0x0f02b4 | Địa chỉ FDE: 0x1ad980 | Kích thước: 256 bytes
//   0x0f02b4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f02b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f02bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f02c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1680_0x0f02b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f02b4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ad980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1681 | PC: 0x0f06c4 | FDE: 0x1ad9d8 | Size: 256 bytes
// Khung tháo gỡ #1681 | Địa chỉ PC: 0x0f06c4 | Địa chỉ FDE: 0x1ad9d8 | Kích thước: 256 bytes
//   0x0f06c4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0f06c8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f06cc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f06d0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1681_0x0f06c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f06c4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ad9d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1682 | PC: 0x0f09b4 | FDE: 0x1ada20 | Size: 252 bytes
// Khung tháo gỡ #1682 | Địa chỉ PC: 0x0f09b4 | Địa chỉ FDE: 0x1ada20 | Kích thước: 252 bytes
//   0x0f09b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f09b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f09bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f09c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1682_0x0f09b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f09b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ada20ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1683 | PC: 0x0f0ab0 | FDE: 0x1ada58 | Size: 256 bytes
// Khung tháo gỡ #1683 | Địa chỉ PC: 0x0f0ab0 | Địa chỉ FDE: 0x1ada58 | Kích thước: 256 bytes
//   0x0f0ab0: D10343FF  sub      sp, sp, #0xd0
//   0x0f0ab4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0f0ab8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0f0abc: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1683_0x0f0ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0ab0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x1ada58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1684 | PC: 0x0f17e0 | FDE: 0x1adab8 | Size: 256 bytes
// Khung tháo gỡ #1684 | Địa chỉ PC: 0x0f17e0 | Địa chỉ FDE: 0x1adab8 | Kích thước: 256 bytes
//   0x0f17e0: D103C3FF  sub      sp, sp, #0xf0
//   0x0f17e4: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0f17e8: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0f17ec: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1684_0x0f17e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f17e0ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1adab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1685 | PC: 0x0f1dd4 | FDE: 0x1adb18 | Size: 256 bytes
// Khung tháo gỡ #1685 | Địa chỉ PC: 0x0f1dd4 | Địa chỉ FDE: 0x1adb18 | Kích thước: 256 bytes
//   0x0f1dd4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f1dd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f1ddc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f1de0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1685_0x0f1dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1dd4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1adb18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1686 | PC: 0x0f2228 | FDE: 0x1adb70 | Size: 256 bytes
// Khung tháo gỡ #1686 | Địa chỉ PC: 0x0f2228 | Địa chỉ FDE: 0x1adb70 | Kích thước: 256 bytes
//   0x0f2228: D10283FF  sub      sp, sp, #0xa0
//   0x0f222c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0f2230: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0f2234: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1686_0x0f2228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2228ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1adb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1687 | PC: 0x0f2a34 | FDE: 0x1adbd0 | Size: 256 bytes
// Khung tháo gỡ #1687 | Địa chỉ PC: 0x0f2a34 | Địa chỉ FDE: 0x1adbd0 | Kích thước: 256 bytes
//   0x0f2a34: D10243FF  sub      sp, sp, #0x90
//   0x0f2a38: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0f2a3c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0f2a40: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1687_0x0f2a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2a34ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1adbd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1688 | PC: 0x0f3254 | FDE: 0x1adc30 | Size: 256 bytes
// Khung tháo gỡ #1688 | Địa chỉ PC: 0x0f3254 | Địa chỉ FDE: 0x1adc30 | Kích thước: 256 bytes
//   0x0f3254: F9400029  ldr      x9, [x1]
//   0x0f3258: 3940012C  ldrb     w12, [x9]
//   0x0f325c: 3738006C  tbnz     w12, #7, #0xf3268
//   0x0f3260: 5280002B  mov      w11, #1
static inline uint64_t fde_func_1688_0x0f3254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3254ULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0x3940012cULL) ^ 0x1adc30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1689 | PC: 0x0f33a4 | FDE: 0x1adc70 | Size: 256 bytes
// Khung tháo gỡ #1689 | Địa chỉ PC: 0x0f33a4 | Địa chỉ FDE: 0x1adc70 | Kích thước: 256 bytes
//   0x0f33a4: D10203FF  sub      sp, sp, #0x80
//   0x0f33a8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0f33ac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f33b0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1689_0x0f33a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f33a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1adc70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1690 | PC: 0x0f3df8 | FDE: 0x1adcd0 | Size: 256 bytes
// Khung tháo gỡ #1690 | Địa chỉ PC: 0x0f3df8 | Địa chỉ FDE: 0x1adcd0 | Kích thước: 256 bytes
//   0x0f3df8: F9400029  ldr      x9, [x1]
//   0x0f3dfc: 3940012B  ldrb     w11, [x9]
//   0x0f3e00: 3738006B  tbnz     w11, #7, #0xf3e0c
//   0x0f3e04: 5280002C  mov      w12, #1
static inline uint64_t fde_func_1690_0x0f3df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3df8ULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0x3940012bULL) ^ 0x1adcd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1691 | PC: 0x0f3fa4 | FDE: 0x1add10 | Size: 216 bytes
// Khung tháo gỡ #1691 | Địa chỉ PC: 0x0f3fa4 | Địa chỉ FDE: 0x1add10 | Kích thước: 216 bytes
//   0x0f3fa4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f3fa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f3fac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f3fb0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1691_0x0f3fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3fa4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1add10ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1692 | PC: 0x0f407c | FDE: 0x1add50 | Size: 216 bytes
// Khung tháo gỡ #1692 | Địa chỉ PC: 0x0f407c | Địa chỉ FDE: 0x1add50 | Kích thước: 216 bytes
//   0x0f407c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f4080: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4084: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4088: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1692_0x0f407c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f407cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1add50ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1693 | PC: 0x0f4154 | FDE: 0x1add90 | Size: 64 bytes
// Khung tháo gỡ #1693 | Địa chỉ PC: 0x0f4154 | Địa chỉ FDE: 0x1add90 | Kích thước: 64 bytes
//   0x0f4154: F9400068  ldr      x8, [x3]
//   0x0f4158: CB010042  sub      x2, x2, x1
//   0x0f415c: F100045F  cmp      x2, #1
//   0x0f4160: CB020100  sub      x0, x8, x2
static inline uint64_t fde_func_1693_0x0f4154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4154ULL ^ (static_cast<uint64_t>(0xf9400068ULL) << 13);
    acc = (acc + a1 + 0xcb010042ULL) ^ 0x1add90ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1694 | PC: 0x0f4194 | FDE: 0x1addc0 | Size: 132 bytes
// Khung tháo gỡ #1694 | Địa chỉ PC: 0x0f4194 | Địa chỉ FDE: 0x1addc0 | Kích thước: 132 bytes
//   0x0f4194: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4198: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f419c: 910043FD  add      x29, sp, #0x10
//   0x0f41a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1694_0x0f4194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4194ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1addc0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1695 | PC: 0x0f4218 | FDE: 0x1addf8 | Size: 256 bytes
// Khung tháo gỡ #1695 | Địa chỉ PC: 0x0f4218 | Địa chỉ FDE: 0x1addf8 | Kích thước: 256 bytes
//   0x0f4218: D10143FF  sub      sp, sp, #0x50
//   0x0f421c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f4220: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f4224: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1695_0x0f4218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4218ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1addf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1696 | PC: 0x0f4498 | FDE: 0x1ade40 | Size: 256 bytes
// Khung tháo gỡ #1696 | Địa chỉ PC: 0x0f4498 | Địa chỉ FDE: 0x1ade40 | Kích thước: 256 bytes
//   0x0f4498: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f449c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f44a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f44a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1696_0x0f4498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4498ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ade40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1697 | PC: 0x0f45a8 | FDE: 0x1ade78 | Size: 256 bytes
// Khung tháo gỡ #1697 | Địa chỉ PC: 0x0f45a8 | Địa chỉ FDE: 0x1ade78 | Kích thước: 256 bytes
//   0x0f45a8: F9400029  ldr      x9, [x1]
//   0x0f45ac: 3940012B  ldrb     w11, [x9]
//   0x0f45b0: 373800CB  tbnz     w11, #7, #0xf45c8
//   0x0f45b4: 3219616A  orr      w10, w11, #0xffffff80
static inline uint64_t fde_func_1697_0x0f45a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f45a8ULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0x3940012bULL) ^ 0x1ade78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1698 | PC: 0x0f46cc | FDE: 0x1adea8 | Size: 128 bytes
// Khung tháo gỡ #1698 | Địa chỉ PC: 0x0f46cc | Địa chỉ FDE: 0x1adea8 | Kích thước: 128 bytes
//   0x0f46cc: F9400029  ldr      x9, [x1]
//   0x0f46d0: F940040A  ldr      x10, [x0, #8]
//   0x0f46d4: 9100112B  add      x11, x9, #4
//   0x0f46d8: EB0A017F  cmp      x11, x10
static inline uint64_t fde_func_1698_0x0f46cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f46ccULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xf940040aULL) ^ 0x1adea8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1699 | PC: 0x0f474c | FDE: 0x1aded8 | Size: 256 bytes
// Khung tháo gỡ #1699 | Địa chỉ PC: 0x0f474c | Địa chỉ FDE: 0x1aded8 | Kích thước: 256 bytes
//   0x0f474c: D10183FF  sub      sp, sp, #0x60
//   0x0f4750: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f4754: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0f4758: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1699_0x0f474c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f474cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1aded8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1700 | PC: 0x0f4930 | FDE: 0x1adf28 | Size: 132 bytes
// Khung tháo gỡ #1700 | Địa chỉ PC: 0x0f4930 | Địa chỉ FDE: 0x1adf28 | Kích thước: 132 bytes
//   0x0f4930: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4934: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4938: 910043FD  add      x29, sp, #0x10
//   0x0f493c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1700_0x0f4930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4930ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1adf28ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1701 | PC: 0x0f49b4 | FDE: 0x1adf60 | Size: 256 bytes
// Khung tháo gỡ #1701 | Địa chỉ PC: 0x0f49b4 | Địa chỉ FDE: 0x1adf60 | Kích thước: 256 bytes
//   0x0f49b4: D10143FF  sub      sp, sp, #0x50
//   0x0f49b8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f49bc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f49c0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1701_0x0f49b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f49b4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1adf60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1702 | PC: 0x0f4b68 | FDE: 0x1adfa8 | Size: 256 bytes
// Khung tháo gỡ #1702 | Địa chỉ PC: 0x0f4b68 | Địa chỉ FDE: 0x1adfa8 | Kích thước: 256 bytes
//   0x0f4b68: D10143FF  sub      sp, sp, #0x50
//   0x0f4b6c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f4b70: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f4b74: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1702_0x0f4b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4b68ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1adfa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1703 | PC: 0x0f4c7c | FDE: 0x1adff0 | Size: 156 bytes
// Khung tháo gỡ #1703 | Địa chỉ PC: 0x0f4c7c | Địa chỉ FDE: 0x1adff0 | Kích thước: 156 bytes
//   0x0f4c7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4c80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4c84: 910043FD  add      x29, sp, #0x10
//   0x0f4c88: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1703_0x0f4c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4c7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1adff0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1704 | PC: 0x0f4d18 | FDE: 0x1ae030 | Size: 224 bytes
// Khung tháo gỡ #1704 | Địa chỉ PC: 0x0f4d18 | Địa chỉ FDE: 0x1ae030 | Kích thước: 224 bytes
//   0x0f4d18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4d1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4d20: 910043FD  add      x29, sp, #0x10
//   0x0f4d24: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1704_0x0f4d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4d18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae030ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1705 | PC: 0x0f4df8 | FDE: 0x1ae070 | Size: 128 bytes
// Khung tháo gỡ #1705 | Địa chỉ PC: 0x0f4df8 | Địa chỉ FDE: 0x1ae070 | Kích thước: 128 bytes
//   0x0f4df8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4dfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4e00: 910043FD  add      x29, sp, #0x10
//   0x0f4e04: D37EFC28  lsr      x8, x1, #0x3e
static inline uint64_t fde_func_1705_0x0f4df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4df8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae070ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1706 | PC: 0x0f4e78 | FDE: 0x1ae0b0 | Size: 132 bytes
// Khung tháo gỡ #1706 | Địa chỉ PC: 0x0f4e78 | Địa chỉ FDE: 0x1ae0b0 | Kích thước: 132 bytes
//   0x0f4e78: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4e7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4e80: 910043FD  add      x29, sp, #0x10
//   0x0f4e84: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1706_0x0f4e78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4e78ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae0b0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1707 | PC: 0x0f4efc | FDE: 0x1ae0e8 | Size: 256 bytes
// Khung tháo gỡ #1707 | Địa chỉ PC: 0x0f4efc | Địa chỉ FDE: 0x1ae0e8 | Kích thước: 256 bytes
//   0x0f4efc: D10183FF  sub      sp, sp, #0x60
//   0x0f4f00: F9001BF5  str      x21, [sp, #0x30]
//   0x0f4f04: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0f4f08: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1707_0x0f4efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4efcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1ae0e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1708 | PC: 0x0f5078 | FDE: 0x1ae130 | Size: 256 bytes
// Khung tháo gỡ #1708 | Địa chỉ PC: 0x0f5078 | Địa chỉ FDE: 0x1ae130 | Kích thước: 256 bytes
//   0x0f5078: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0f507c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f5080: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f5084: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1708_0x0f5078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5078ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ae130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1709 | PC: 0x0f51e8 | FDE: 0x1ae180 | Size: 256 bytes
// Khung tháo gỡ #1709 | Địa chỉ PC: 0x0f51e8 | Địa chỉ FDE: 0x1ae180 | Kích thước: 256 bytes
//   0x0f51e8: D10143FF  sub      sp, sp, #0x50
//   0x0f51ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f51f0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f51f4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1709_0x0f51e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f51e8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1ae180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1710 | PC: 0x0f5364 | FDE: 0x1ae1b8 | Size: 256 bytes
// Khung tháo gỡ #1710 | Địa chỉ PC: 0x0f5364 | Địa chỉ FDE: 0x1ae1b8 | Kích thước: 256 bytes
//   0x0f5364: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f5368: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f536c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5370: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1710_0x0f5364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5364ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1711 | PC: 0x0f5478 | FDE: 0x1ae1f0 | Size: 256 bytes
// Khung tháo gỡ #1711 | Địa chỉ PC: 0x0f5478 | Địa chỉ FDE: 0x1ae1f0 | Kích thước: 256 bytes
//   0x0f5478: F940002A  ldr      x10, [x1]
//   0x0f547c: 39C00149  ldrsb    w9, [x10]
//   0x0f5480: 36F80089  tbz      w9, #0x1f, #0xf5490
//   0x0f5484: 92401D2B  and      x11, x9, #0xff
static inline uint64_t fde_func_1711_0x0f5478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5478ULL ^ (static_cast<uint64_t>(0xf940002aULL) << 13);
    acc = (acc + a1 + 0x39c00149ULL) ^ 0x1ae1f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1712 | PC: 0x0f5688 | FDE: 0x1ae228 | Size: 220 bytes
// Khung tháo gỡ #1712 | Địa chỉ PC: 0x0f5688 | Địa chỉ FDE: 0x1ae228 | Kích thước: 220 bytes
//   0x0f5688: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f568c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5690: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5694: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1712_0x0f5688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5688ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae228ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1713 | PC: 0x0f5764 | FDE: 0x1ae268 | Size: 184 bytes
// Khung tháo gỡ #1713 | Địa chỉ PC: 0x0f5764 | Địa chỉ FDE: 0x1ae268 | Kích thước: 184 bytes
//   0x0f5764: F9400068  ldr      x8, [x3]
//   0x0f5768: CB010042  sub      x2, x2, x1
//   0x0f576c: F100045F  cmp      x2, #1
//   0x0f5770: CB020100  sub      x0, x8, x2
static inline uint64_t fde_func_1713_0x0f5764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5764ULL ^ (static_cast<uint64_t>(0xf9400068ULL) << 13);
    acc = (acc + a1 + 0xcb010042ULL) ^ 0x1ae268ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1714 | PC: 0x0f581c | FDE: 0x1ae2a0 | Size: 256 bytes
// Khung tháo gỡ #1714 | Địa chỉ PC: 0x0f581c | Địa chỉ FDE: 0x1ae2a0 | Kích thước: 256 bytes
//   0x0f581c: D10143FF  sub      sp, sp, #0x50
//   0x0f5820: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f5824: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f5828: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1714_0x0f581c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f581cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1ae2a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1715 | PC: 0x0f592c | FDE: 0x1ae2e8 | Size: 156 bytes
// Khung tháo gỡ #1715 | Địa chỉ PC: 0x0f592c | Địa chỉ FDE: 0x1ae2e8 | Kích thước: 156 bytes
//   0x0f592c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f5930: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5934: 910043FD  add      x29, sp, #0x10
//   0x0f5938: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1715_0x0f592c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f592cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae2e8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1716 | PC: 0x0f59c8 | FDE: 0x1ae328 | Size: 216 bytes
// Khung tháo gỡ #1716 | Địa chỉ PC: 0x0f59c8 | Địa chỉ FDE: 0x1ae328 | Kích thước: 216 bytes
//   0x0f59c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f59cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f59d0: 910043FD  add      x29, sp, #0x10
//   0x0f59d4: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1716_0x0f59c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f59c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae328ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1717 | PC: 0x0f5aa0 | FDE: 0x1ae370 | Size: 128 bytes
// Khung tháo gỡ #1717 | Địa chỉ PC: 0x0f5aa0 | Địa chỉ FDE: 0x1ae370 | Kích thước: 128 bytes
//   0x0f5aa0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f5aa4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5aa8: 910043FD  add      x29, sp, #0x10
//   0x0f5aac: D37DFC28  lsr      x8, x1, #0x3d
static inline uint64_t fde_func_1717_0x0f5aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5aa0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae370ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1718 | PC: 0x0f5b20 | FDE: 0x1ae3b0 | Size: 220 bytes
// Khung tháo gỡ #1718 | Địa chỉ PC: 0x0f5b20 | Địa chỉ FDE: 0x1ae3b0 | Kích thước: 220 bytes
//   0x0f5b20: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f5b24: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5b28: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5b2c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1718_0x0f5b20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5b20ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae3b0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1719 | PC: 0x0f5bfc | FDE: 0x1ae3f0 | Size: 184 bytes
// Khung tháo gỡ #1719 | Địa chỉ PC: 0x0f5bfc | Địa chỉ FDE: 0x1ae3f0 | Kích thước: 184 bytes
//   0x0f5bfc: F9400068  ldr      x8, [x3]
//   0x0f5c00: CB010042  sub      x2, x2, x1
//   0x0f5c04: F100045F  cmp      x2, #1
//   0x0f5c08: CB020100  sub      x0, x8, x2
static inline uint64_t fde_func_1719_0x0f5bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5bfcULL ^ (static_cast<uint64_t>(0xf9400068ULL) << 13);
    acc = (acc + a1 + 0xcb010042ULL) ^ 0x1ae3f0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1720 | PC: 0x0f5cb4 | FDE: 0x1ae428 | Size: 256 bytes
// Khung tháo gỡ #1720 | Địa chỉ PC: 0x0f5cb4 | Địa chỉ FDE: 0x1ae428 | Kích thước: 256 bytes
//   0x0f5cb4: D10183FF  sub      sp, sp, #0x60
//   0x0f5cb8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5cbc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0f5cc0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1720_0x0f5cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5cb4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1ae428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1721 | PC: 0x0f5e98 | FDE: 0x1ae478 | Size: 256 bytes
// Khung tháo gỡ #1721 | Địa chỉ PC: 0x0f5e98 | Địa chỉ FDE: 0x1ae478 | Kích thước: 256 bytes
//   0x0f5e98: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f5e9c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5ea0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5ea4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1721_0x0f5e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5e98ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1722 | PC: 0x0f5fb0 | FDE: 0x1ae4b0 | Size: 120 bytes
// Khung tháo gỡ #1722 | Địa chỉ PC: 0x0f5fb0 | Địa chỉ FDE: 0x1ae4b0 | Kích thước: 120 bytes
//   0x0f5fb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f5fb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5fb8: 910043FD  add      x29, sp, #0x10
//   0x0f5fbc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1722_0x0f5fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5fb0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae4b0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1723 | PC: 0x0f6028 | FDE: 0x1ae4f0 | Size: 168 bytes
// Khung tháo gỡ #1723 | Địa chỉ PC: 0x0f6028 | Địa chỉ FDE: 0x1ae4f0 | Kích thước: 168 bytes
//   0x0f6028: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f602c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f6030: 910043FD  add      x29, sp, #0x10
//   0x0f6034: F9400C20  ldr      x0, [x1, #0x18]
static inline uint64_t fde_func_1723_0x0f6028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6028ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae4f0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1724 | PC: 0x0f60d0 | FDE: 0x1ae530 | Size: 132 bytes
// Khung tháo gỡ #1724 | Địa chỉ PC: 0x0f60d0 | Địa chỉ FDE: 0x1ae530 | Kích thước: 132 bytes
//   0x0f60d0: F9400068  ldr      x8, [x3]
//   0x0f60d4: CB010042  sub      x2, x2, x1
//   0x0f60d8: F100045F  cmp      x2, #1
//   0x0f60dc: CB020100  sub      x0, x8, x2
static inline uint64_t fde_func_1724_0x0f60d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f60d0ULL ^ (static_cast<uint64_t>(0xf9400068ULL) << 13);
    acc = (acc + a1 + 0xcb010042ULL) ^ 0x1ae530ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1725 | PC: 0x0f6154 | FDE: 0x1ae568 | Size: 256 bytes
// Khung tháo gỡ #1725 | Địa chỉ PC: 0x0f6154 | Địa chỉ FDE: 0x1ae568 | Kích thước: 256 bytes
//   0x0f6154: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f6158: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f615c: 910043FD  add      x29, sp, #0x10
//   0x0f6160: 9104E002  add      x2, x0, #0x138
static inline uint64_t fde_func_1725_0x0f6154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6154ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1726 | PC: 0x0f6bf0 | FDE: 0x1ae5b8 | Size: 256 bytes
// Khung tháo gỡ #1726 | Địa chỉ PC: 0x0f6bf0 | Địa chỉ FDE: 0x1ae5b8 | Kích thước: 256 bytes
//   0x0f6bf0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f6bf4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f6bf8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f6bfc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1726_0x0f6bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6bf0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae5b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1727 | PC: 0x0f6e64 | FDE: 0x1ae600 | Size: 256 bytes
// Khung tháo gỡ #1727 | Địa chỉ PC: 0x0f6e64 | Địa chỉ FDE: 0x1ae600 | Kích thước: 256 bytes
//   0x0f6e64: D101C3FF  sub      sp, sp, #0x70
//   0x0f6e68: F90013F9  str      x25, [sp, #0x20]
//   0x0f6e6c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f6e70: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1727_0x0f6e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6e64ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1ae600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1728 | PC: 0x0f70c4 | FDE: 0x1ae650 | Size: 256 bytes
// Khung tháo gỡ #1728 | Địa chỉ PC: 0x0f70c4 | Địa chỉ FDE: 0x1ae650 | Kích thước: 256 bytes
//   0x0f70c4: D10143FF  sub      sp, sp, #0x50
//   0x0f70c8: F90013F5  str      x21, [sp, #0x20]
//   0x0f70cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f70d0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1728_0x0f70c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f70c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1ae650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1729 | PC: 0x0f7284 | FDE: 0x1ae690 | Size: 256 bytes
// Khung tháo gỡ #1729 | Địa chỉ PC: 0x0f7284 | Địa chỉ FDE: 0x1ae690 | Kích thước: 256 bytes
//   0x0f7284: D10183FF  sub      sp, sp, #0x60
//   0x0f7288: F9001BF5  str      x21, [sp, #0x30]
//   0x0f728c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0f7290: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1729_0x0f7284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7284ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1ae690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1730 | PC: 0x0f7454 | FDE: 0x1ae6d8 | Size: 256 bytes
// Khung tháo gỡ #1730 | Địa chỉ PC: 0x0f7454 | Địa chỉ FDE: 0x1ae6d8 | Kích thước: 256 bytes
//   0x0f7454: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f7458: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f745c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f7460: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1730_0x0f7454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7454ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1ae6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1731 | PC: 0x0f758c | FDE: 0x1ae720 | Size: 256 bytes
// Khung tháo gỡ #1731 | Địa chỉ PC: 0x0f758c | Địa chỉ FDE: 0x1ae720 | Kích thước: 256 bytes
//   0x0f758c: D10143FF  sub      sp, sp, #0x50
//   0x0f7590: F9000BF7  str      x23, [sp, #0x10]
//   0x0f7594: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f7598: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1731_0x0f758c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f758cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1ae720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1732 | PC: 0x0f7804 | FDE: 0x1ae770 | Size: 136 bytes
// Khung tháo gỡ #1732 | Địa chỉ PC: 0x0f7804 | Địa chỉ FDE: 0x1ae770 | Kích thước: 136 bytes
//   0x0f7804: B4000241  cbz      x1, #0xf784c
//   0x0f7808: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f780c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f7810: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1732_0x0f7804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7804ULL ^ (static_cast<uint64_t>(0xb4000241ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1ae770ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1733 | PC: 0x0f788c | FDE: 0x1ae7b0 | Size: 196 bytes
// Khung tháo gỡ #1733 | Địa chỉ PC: 0x0f788c | Địa chỉ FDE: 0x1ae7b0 | Kích thước: 196 bytes
//   0x0f788c: AA0003E8  mov      x8, x0
//   0x0f7890: F9400800  ldr      x0, [x0, #0x10]
//   0x0f7894: B4000280  cbz      x0, #0xf78e4
//   0x0f7898: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_1733_0x0f788c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f788cULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400800ULL) ^ 0x1ae7b0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1734 | PC: 0x0f7950 | FDE: 0x1ae7f0 | Size: 208 bytes
// Khung tháo gỡ #1734 | Địa chỉ PC: 0x0f7950 | Địa chỉ FDE: 0x1ae7f0 | Kích thước: 208 bytes
//   0x0f7950: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f7954: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f7958: 910043FD  add      x29, sp, #0x10
//   0x0f795c: AA0003E2  mov      x2, x0
static inline uint64_t fde_func_1734_0x0f7950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7950ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae7f0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1735 | PC: 0x0f7a20 | FDE: 0x1ae830 | Size: 256 bytes
// Khung tháo gỡ #1735 | Địa chỉ PC: 0x0f7a20 | Địa chỉ FDE: 0x1ae830 | Kích thước: 256 bytes
//   0x0f7a20: D10103FF  sub      sp, sp, #0x40
//   0x0f7a24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f7a28: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f7a2c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1735_0x0f7a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7a20ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1ae830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1736 | PC: 0x0f7b34 | FDE: 0x1ae878 | Size: 256 bytes
// Khung tháo gỡ #1736 | Địa chỉ PC: 0x0f7b34 | Địa chỉ FDE: 0x1ae878 | Kích thước: 256 bytes
//   0x0f7b34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f7b38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f7b3c: 910043FD  add      x29, sp, #0x10
//   0x0f7b40: A9007C7F  stp      xzr, xzr, [x3]
static inline uint64_t fde_func_1736_0x0f7b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7b34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1737 | PC: 0x0f7d1c | FDE: 0x1ae8c8 | Size: 144 bytes
// Khung tháo gỡ #1737 | Địa chỉ PC: 0x0f7d1c | Địa chỉ FDE: 0x1ae8c8 | Kích thước: 144 bytes
//   0x0f7d1c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f7d20: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f7d24: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f7d28: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1737_0x0f7d1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7d1cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae8c8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1738 | PC: 0x0f7dac | FDE: 0x1ae908 | Size: 160 bytes
// Khung tháo gỡ #1738 | Địa chỉ PC: 0x0f7dac | Địa chỉ FDE: 0x1ae908 | Kích thước: 160 bytes
//   0x0f7dac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f7db0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f7db4: 910043FD  add      x29, sp, #0x10
//   0x0f7db8: B201F3E8  mov      x8, #-0x5555555555555556
static inline uint64_t fde_func_1738_0x0f7dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7dacULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae908ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1739 | PC: 0x0f7e4c | FDE: 0x1ae948 | Size: 256 bytes
// Khung tháo gỡ #1739 | Địa chỉ PC: 0x0f7e4c | Địa chỉ FDE: 0x1ae948 | Kích thước: 256 bytes
//   0x0f7e4c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0f7e50: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f7e54: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f7e58: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1739_0x0f7e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7e4cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1ae948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1740 | PC: 0x0f7fc4 | FDE: 0x1ae998 | Size: 172 bytes
// Khung tháo gỡ #1740 | Địa chỉ PC: 0x0f7fc4 | Địa chỉ FDE: 0x1ae998 | Kích thước: 172 bytes
//   0x0f7fc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f7fc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f7fcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f7fd0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1740_0x0f7fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7fc4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ae998ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1741 | PC: 0x0f8070 | FDE: 0x1ae9d8 | Size: 256 bytes
// Khung tháo gỡ #1741 | Địa chỉ PC: 0x0f8070 | Địa chỉ FDE: 0x1ae9d8 | Kích thước: 256 bytes
//   0x0f8070: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f8074: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8078: 910043FD  add      x29, sp, #0x10
//   0x0f807c: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1741_0x0f8070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8070ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ae9d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1742 | PC: 0x0f8254 | FDE: 0x1aea20 | Size: 256 bytes
// Khung tháo gỡ #1742 | Địa chỉ PC: 0x0f8254 | Địa chỉ FDE: 0x1aea20 | Kích thước: 256 bytes
//   0x0f8254: D10103FF  sub      sp, sp, #0x40
//   0x0f8258: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f825c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f8260: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1742_0x0f8254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8254ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1aea20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1743 | PC: 0x0f83d0 | FDE: 0x1aea60 | Size: 256 bytes
// Khung tháo gỡ #1743 | Địa chỉ PC: 0x0f83d0 | Địa chỉ FDE: 0x1aea60 | Kích thước: 256 bytes
//   0x0f83d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f83d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f83d8: 910043FD  add      x29, sp, #0x10
//   0x0f83dc: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1743_0x0f83d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f83d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aea60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1744 | PC: 0x0f8508 | FDE: 0x1aeaa0 | Size: 256 bytes
// Khung tháo gỡ #1744 | Địa chỉ PC: 0x0f8508 | Địa chỉ FDE: 0x1aeaa0 | Kích thước: 256 bytes
//   0x0f8508: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0f850c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f8510: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f8514: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1744_0x0f8508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8508ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1aeaa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1745 | PC: 0x0f8678 | FDE: 0x1aeaf0 | Size: 256 bytes
// Khung tháo gỡ #1745 | Địa chỉ PC: 0x0f8678 | Địa chỉ FDE: 0x1aeaf0 | Kích thước: 256 bytes
//   0x0f8678: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f867c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f8680: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f8684: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1745_0x0f8678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8678ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1aeaf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1746 | PC: 0x0f8794 | FDE: 0x1aeb38 | Size: 92 bytes
// Khung tháo gỡ #1746 | Địa chỉ PC: 0x0f8794 | Địa chỉ FDE: 0x1aeb38 | Kích thước: 92 bytes
//   0x0f8794: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f8798: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f879c: 910043FD  add      x29, sp, #0x10
//   0x0f87a0: F00006E9  adrp     x9, #0x1d7000
static inline uint64_t fde_func_1746_0x0f8794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8794ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aeb38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1747 | PC: 0x0f87f0 | FDE: 0x1aeb70 | Size: 248 bytes
// Khung tháo gỡ #1747 | Địa chỉ PC: 0x0f87f0 | Địa chỉ FDE: 0x1aeb70 | Kích thước: 248 bytes
//   0x0f87f0: D65F03C0  ret      
//   0x0f87f4: F9402C08  ldr      x8, [x0, #0x58]
//   0x0f87f8: F9401809  ldr      x9, [x0, #0x30]
//   0x0f87fc: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1747_0x0f87f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f87f0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9402c08ULL) ^ 0x1aeb70ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1748 | PC: 0x0f88e8 | FDE: 0x1aeba0 | Size: 28 bytes
// Khung tháo gỡ #1748 | Địa chỉ PC: 0x0f88e8 | Địa chỉ FDE: 0x1aeba0 | Kích thước: 28 bytes
//   0x0f88e8: F9400008  ldr      x8, [x0]
//   0x0f88ec: AA0203E1  mov      x1, x2
//   0x0f88f0: 2A1F03E2  mov      w2, wzr
//   0x0f88f4: F9401104  ldr      x4, [x8, #0x20]
static inline uint64_t fde_func_1748_0x0f88e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f88e8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x1aeba0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1749 | PC: 0x0f8904 | FDE: 0x1aebd0 | Size: 204 bytes
// Khung tháo gỡ #1749 | Địa chỉ PC: 0x0f8904 | Địa chỉ FDE: 0x1aebd0 | Kích thước: 204 bytes
//   0x0f8904: AA1F03E0  mov      x0, xzr
//   0x0f8908: D65F03C0  ret      
//   0x0f890c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f8910: A90157F6  stp      x22, x21, [sp, #0x10]
static inline uint64_t fde_func_1749_0x0f8904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8904ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1aebd0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1750 | PC: 0x0f89d0 | FDE: 0x1aec10 | Size: 144 bytes
// Khung tháo gỡ #1750 | Địa chỉ PC: 0x0f89d0 | Địa chỉ FDE: 0x1aec10 | Kích thước: 144 bytes
//   0x0f89d0: F9402C08  ldr      x8, [x0, #0x58]
//   0x0f89d4: F9401809  ldr      x9, [x0, #0x30]
//   0x0f89d8: EB09011F  cmp      x8, x9
//   0x0f89dc: 54000062  b.hs     #0xf89e8
static inline uint64_t fde_func_1750_0x0f89d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f89d0ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x1aec10ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1751 | PC: 0x0f8a60 | FDE: 0x1aec48 | Size: 256 bytes
// Khung tháo gỡ #1751 | Địa chỉ PC: 0x0f8a60 | Địa chỉ FDE: 0x1aec48 | Kích thước: 256 bytes
//   0x0f8a60: F9402C09  ldr      x9, [x0, #0x58]
//   0x0f8a64: F940180A  ldr      x10, [x0, #0x30]
//   0x0f8a68: AA0003E8  mov      x8, x0
//   0x0f8a6c: 2A0103E0  mov      w0, w1
static inline uint64_t fde_func_1751_0x0f8a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8a60ULL ^ (static_cast<uint64_t>(0xf9402c09ULL) << 13);
    acc = (acc + a1 + 0xf940180aULL) ^ 0x1aec48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1752 | PC: 0x0f8b8c | FDE: 0x1aec88 | Size: 256 bytes
// Khung tháo gỡ #1752 | Địa chỉ PC: 0x0f8b8c | Địa chỉ FDE: 0x1aec88 | Kích thước: 256 bytes
//   0x0f8b8c: D10183FF  sub      sp, sp, #0x60
//   0x0f8b90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f8b94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f8b98: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1752_0x0f8b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8b8cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1aec88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1753 | PC: 0x0f8d20 | FDE: 0x1aecd0 | Size: 64 bytes
// Khung tháo gỡ #1753 | Địa chỉ PC: 0x0f8d20 | Địa chỉ FDE: 0x1aecd0 | Kích thước: 64 bytes
//   0x0f8d20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f8d24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8d28: 910043FD  add      x29, sp, #0x10
//   0x0f8d2c: F00006E8  adrp     x8, #0x1d7000
static inline uint64_t fde_func_1753_0x0f8d20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aecd0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1754 | PC: 0x0f8d60 | FDE: 0x1aed08 | Size: 20 bytes
// Khung tháo gỡ #1754 | Địa chỉ PC: 0x0f8d60 | Địa chỉ FDE: 0x1aed08 | Kích thước: 20 bytes
//   0x0f8d60: 92800001  mov      x1, #-1
//   0x0f8d64: AA1F03E0  mov      x0, xzr
//   0x0f8d68: D65F03C0  ret      
//   0x0f8d6c: 12800000  mov      w0, #-1
static inline uint64_t fde_func_1754_0x0f8d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d60ULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1aed08ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1755 | PC: 0x0f8d74 | FDE: 0x1aed38 | Size: 16 bytes
// Khung tháo gỡ #1755 | Địa chỉ PC: 0x0f8d74 | Địa chỉ FDE: 0x1aed38 | Kích thước: 16 bytes
//   0x0f8d74: 12800000  mov      w0, #-1
//   0x0f8d78: D65F03C0  ret      
//   0x0f8d7c: 12800000  mov      w0, #-1
//   0x0f8d80: D65F03C0  ret      
static inline uint64_t fde_func_1755_0x0f8d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d74ULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1aed38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1756 | PC: 0x0f8d84 | FDE: 0x1aed68 | Size: 232 bytes
// Khung tháo gỡ #1756 | Địa chỉ PC: 0x0f8d84 | Địa chỉ FDE: 0x1aed68 | Kích thước: 232 bytes
//   0x0f8d84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f8d88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8d8c: 910043FD  add      x29, sp, #0x10
//   0x0f8d90: F00006E8  adrp     x8, #0x1d7000
static inline uint64_t fde_func_1756_0x0f8d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d84ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aed68ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1757 | PC: 0x0f8e6c | FDE: 0x1aeda8 | Size: 256 bytes
// Khung tháo gỡ #1757 | Địa chỉ PC: 0x0f8e6c | Địa chỉ FDE: 0x1aeda8 | Kích thước: 256 bytes
//   0x0f8e6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f8e70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f8e74: 910043FD  add      x29, sp, #0x10
//   0x0f8e78: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1757_0x0f8e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8e6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aeda8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1758 | PC: 0x0f8f6c | FDE: 0x1aede8 | Size: 48 bytes
// Khung tháo gỡ #1758 | Địa chỉ PC: 0x0f8f6c | Địa chỉ FDE: 0x1aede8 | Kích thước: 48 bytes
//   0x0f8f6c: 91004000  add      x0, x0, #0x10
//   0x0f8f70: 17FCD460  b        #0x2e0f0
//   0x0f8f74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f8f78: A9017BFD  stp      x29, x30, [sp, #0x10]
static inline uint64_t fde_func_1758_0x0f8f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8f6cULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17fcd460ULL) ^ 0x1aede8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1759 | PC: 0x0f8f9c | FDE: 0x1aee20 | Size: 68 bytes
// Khung tháo gỡ #1759 | Địa chỉ PC: 0x0f8f9c | Địa chỉ FDE: 0x1aee20 | Kích thước: 68 bytes
//   0x0f8f9c: F9400008  ldr      x8, [x0]
//   0x0f8fa0: F85E8108  ldur     x8, [x8, #-0x18]
//   0x0f8fa4: 8B080008  add      x8, x0, x8
//   0x0f8fa8: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_1759_0x0f8f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8f9cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x1aee20ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1760 | PC: 0x0f8fe0 | FDE: 0x1aee58 | Size: 256 bytes
// Khung tháo gỡ #1760 | Địa chỉ PC: 0x0f8fe0 | Địa chỉ FDE: 0x1aee58 | Kích thước: 256 bytes
//   0x0f8fe0: D10203FF  sub      sp, sp, #0x80
//   0x0f8fe4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f8fe8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f8fec: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1760_0x0f8fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8fe0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x1aee58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1761 | PC: 0x0f922c | FDE: 0x1aeea8 | Size: 196 bytes
// Khung tháo gỡ #1761 | Địa chỉ PC: 0x0f922c | Địa chỉ FDE: 0x1aeea8 | Kích thước: 196 bytes
//   0x0f922c: D100C3FF  sub      sp, sp, #0x30
//   0x0f9230: F9000BF3  str      x19, [sp, #0x10]
//   0x0f9234: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f9238: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1761_0x0f922c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f922cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1aeea8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1762 | PC: 0x0f92f0 | FDE: 0x1aeee8 | Size: 256 bytes
// Khung tháo gỡ #1762 | Địa chỉ PC: 0x0f92f0 | Địa chỉ FDE: 0x1aeee8 | Kích thước: 256 bytes
//   0x0f92f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f92f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f92f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f92fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1762_0x0f92f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f92f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1aeee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1763 | PC: 0x0f9470 | FDE: 0x1aef28 | Size: 256 bytes
// Khung tháo gỡ #1763 | Địa chỉ PC: 0x0f9470 | Địa chỉ FDE: 0x1aef28 | Kích thước: 256 bytes
//   0x0f9470: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f9474: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9478: 910043FD  add      x29, sp, #0x10
//   0x0f947c: F940D001  ldr      x1, [x0, #0x1a0]
static inline uint64_t fde_func_1763_0x0f9470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9470ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aef28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1764 | PC: 0x0f95a0 | FDE: 0x1aef68 | Size: 112 bytes
// Khung tháo gỡ #1764 | Địa chỉ PC: 0x0f95a0 | Địa chỉ FDE: 0x1aef68 | Kích thước: 112 bytes
//   0x0f95a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f95a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f95a8: 910043FD  add      x29, sp, #0x10
//   0x0f95ac: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1764_0x0f95a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f95a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1aef68ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1765 | PC: 0x0f9610 | FDE: 0x1aefa8 | Size: 200 bytes
// Khung tháo gỡ #1765 | Địa chỉ PC: 0x0f9610 | Địa chỉ FDE: 0x1aefa8 | Kích thước: 200 bytes
//   0x0f9610: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f9614: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f9618: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f961c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1765_0x0f9610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9610ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1aefa8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1766 | PC: 0x0f96d8 | FDE: 0x1aeff0 | Size: 148 bytes
// Khung tháo gỡ #1766 | Địa chỉ PC: 0x0f96d8 | Địa chỉ FDE: 0x1aeff0 | Kích thước: 148 bytes
//   0x0f96d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f96dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f96e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f96e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1766_0x0f96d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f96d8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1aeff0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1767 | PC: 0x0f976c | FDE: 0x1af030 | Size: 256 bytes
// Khung tháo gỡ #1767 | Địa chỉ PC: 0x0f976c | Địa chỉ FDE: 0x1af030 | Kích thước: 256 bytes
//   0x0f976c: F9400029  ldr      x9, [x1]
//   0x0f9770: F940040A  ldr      x10, [x0, #8]
//   0x0f9774: CB09014B  sub      x11, x10, x9
//   0x0f9778: A9022C09  stp      x9, x11, [x0, #0x20]
static inline uint64_t fde_func_1767_0x0f976c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f976cULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xf940040aULL) ^ 0x1af030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1768 | PC: 0x0f993c | FDE: 0x1af070 | Size: 256 bytes
// Khung tháo gỡ #1768 | Địa chỉ PC: 0x0f993c | Địa chỉ FDE: 0x1af070 | Kích thước: 256 bytes
//   0x0f993c: D10203FF  sub      sp, sp, #0x80
//   0x0f9940: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f9944: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f9948: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1768_0x0f993c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f993cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x1af070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1769 | PC: 0x0f9bf0 | FDE: 0x1af0b0 | Size: 256 bytes
// Khung tháo gỡ #1769 | Địa chỉ PC: 0x0f9bf0 | Địa chỉ FDE: 0x1af0b0 | Kích thước: 256 bytes
//   0x0f9bf0: D10143FF  sub      sp, sp, #0x50
//   0x0f9bf4: F90013F5  str      x21, [sp, #0x20]
//   0x0f9bf8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f9bfc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1769_0x0f9bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9bf0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1af0b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1770 | PC: 0x0fa060 | FDE: 0x1af100 | Size: 256 bytes
// Khung tháo gỡ #1770 | Địa chỉ PC: 0x0fa060 | Địa chỉ FDE: 0x1af100 | Kích thước: 256 bytes
//   0x0fa060: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0fa064: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0fa068: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0fa06c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1770_0x0fa060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa060ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1af100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1771 | PC: 0x0fa3d0 | FDE: 0x1af158 | Size: 256 bytes
// Khung tháo gỡ #1771 | Địa chỉ PC: 0x0fa3d0 | Địa chỉ FDE: 0x1af158 | Kích thước: 256 bytes
//   0x0fa3d0: D10243FF  sub      sp, sp, #0x90
//   0x0fa3d4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0fa3d8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0fa3dc: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1771_0x0fa3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa3d0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x1af158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1772 | PC: 0x0fa654 | FDE: 0x1af1b0 | Size: 256 bytes
// Khung tháo gỡ #1772 | Địa chỉ PC: 0x0fa654 | Địa chỉ FDE: 0x1af1b0 | Kích thước: 256 bytes
//   0x0fa654: D101C3FF  sub      sp, sp, #0x70
//   0x0fa658: F9000BFB  str      x27, [sp, #0x10]
//   0x0fa65c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0fa660: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1772_0x0fa654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa654ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1af1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1773 | PC: 0x0faa78 | FDE: 0x1af210 | Size: 256 bytes
// Khung tháo gỡ #1773 | Địa chỉ PC: 0x0faa78 | Địa chỉ FDE: 0x1af210 | Kích thước: 256 bytes
//   0x0faa78: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0faa7c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0faa80: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0faa84: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1773_0x0faa78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0faa78ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1af210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1774 | PC: 0x0fb06c | FDE: 0x1af270 | Size: 256 bytes
// Khung tháo gỡ #1774 | Địa chỉ PC: 0x0fb06c | Địa chỉ FDE: 0x1af270 | Kích thước: 256 bytes
//   0x0fb06c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0fb070: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0fb074: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0fb078: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1774_0x0fb06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb06cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1af270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1775 | PC: 0x0fb318 | FDE: 0x1af2c0 | Size: 256 bytes
// Khung tháo gỡ #1775 | Địa chỉ PC: 0x0fb318 | Địa chỉ FDE: 0x1af2c0 | Kích thước: 256 bytes
//   0x0fb318: D10143FF  sub      sp, sp, #0x50
//   0x0fb31c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0fb320: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fb324: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1775_0x0fb318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb318ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1af2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1776 | PC: 0x0fb520 | FDE: 0x1af308 | Size: 168 bytes
// Khung tháo gỡ #1776 | Địa chỉ PC: 0x0fb520 | Địa chỉ FDE: 0x1af308 | Kích thước: 168 bytes
//   0x0fb520: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fb524: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fb528: 910043FD  add      x29, sp, #0x10
//   0x0fb52c: 340001C1  cbz      w1, #0xfb564
static inline uint64_t fde_func_1776_0x0fb520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb520ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af308ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1777 | PC: 0x0fb5c8 | FDE: 0x1af348 | Size: 256 bytes
// Khung tháo gỡ #1777 | Địa chỉ PC: 0x0fb5c8 | Địa chỉ FDE: 0x1af348 | Kích thước: 256 bytes
//   0x0fb5c8: F940002A  ldr      x10, [x1]
//   0x0fb5cc: 39C00149  ldrsb    w9, [x10]
//   0x0fb5d0: 36F80089  tbz      w9, #0x1f, #0xfb5e0
//   0x0fb5d4: 92401D2B  and      x11, x9, #0xff
static inline uint64_t fde_func_1777_0x0fb5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb5c8ULL ^ (static_cast<uint64_t>(0xf940002aULL) << 13);
    acc = (acc + a1 + 0x39c00149ULL) ^ 0x1af348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1778 | PC: 0x0fb750 | FDE: 0x1af380 | Size: 168 bytes
// Khung tháo gỡ #1778 | Địa chỉ PC: 0x0fb750 | Địa chỉ FDE: 0x1af380 | Kích thước: 168 bytes
//   0x0fb750: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fb754: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fb758: 910043FD  add      x29, sp, #0x10
//   0x0fb75c: 340001C1  cbz      w1, #0xfb794
static inline uint64_t fde_func_1778_0x0fb750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb750ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af380ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1779 | PC: 0x0fb7f8 | FDE: 0x1af3c0 | Size: 164 bytes
// Khung tháo gỡ #1779 | Địa chỉ PC: 0x0fb7f8 | Địa chỉ FDE: 0x1af3c0 | Kích thước: 164 bytes
//   0x0fb7f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fb7fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fb800: 910043FD  add      x29, sp, #0x10
//   0x0fb804: 340001C1  cbz      w1, #0xfb83c
static inline uint64_t fde_func_1779_0x0fb7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb7f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af3c0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1780 | PC: 0x0fb89c | FDE: 0x1af400 | Size: 256 bytes
// Khung tháo gỡ #1780 | Địa chỉ PC: 0x0fb89c | Địa chỉ FDE: 0x1af400 | Kích thước: 256 bytes
//   0x0fb89c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fb8a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fb8a4: 910043FD  add      x29, sp, #0x10
//   0x0fb8a8: 91038002  add      x2, x0, #0xe0
static inline uint64_t fde_func_1780_0x0fb89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb89cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1781 | PC: 0x0fba94 | FDE: 0x1af448 | Size: 256 bytes
// Khung tháo gỡ #1781 | Địa chỉ PC: 0x0fba94 | Địa chỉ FDE: 0x1af448 | Kích thước: 256 bytes
//   0x0fba94: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0fba98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fba9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fbaa0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1781_0x0fba94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fba94ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1af448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1782 | PC: 0x0fbc4c | FDE: 0x1af490 | Size: 64 bytes
// Khung tháo gỡ #1782 | Địa chỉ PC: 0x0fbc4c | Địa chỉ FDE: 0x1af490 | Kích thước: 64 bytes
//   0x0fbc4c: A9402829  ldp      x9, x10, [x1]
//   0x0fbc50: CB09014B  sub      x11, x10, x9
//   0x0fbc54: A9022809  stp      x9, x10, [x0, #0x20]
//   0x0fbc58: F900180B  str      x11, [x0, #0x30]
static inline uint64_t fde_func_1782_0x0fbc4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbc4cULL ^ (static_cast<uint64_t>(0xa9402829ULL) << 13);
    acc = (acc + a1 + 0xcb09014bULL) ^ 0x1af490ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1783 | PC: 0x0fbc8c | FDE: 0x1af4c0 | Size: 76 bytes
// Khung tháo gỡ #1783 | Địa chỉ PC: 0x0fbc8c | Địa chỉ FDE: 0x1af4c0 | Kích thước: 76 bytes
//   0x0fbc8c: A9402829  ldp      x9, x10, [x1]
//   0x0fbc90: CB09014A  sub      x10, x10, x9
//   0x0fbc94: 9342FD4B  asr      x11, x10, #2
//   0x0fbc98: 927EF54A  and      x10, x10, #0xfffffffffffffffc
static inline uint64_t fde_func_1783_0x0fbc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbc8cULL ^ (static_cast<uint64_t>(0xa9402829ULL) << 13);
    acc = (acc + a1 + 0xcb09014aULL) ^ 0x1af4c0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1784 | PC: 0x0fbcd8 | FDE: 0x1af4f0 | Size: 136 bytes
// Khung tháo gỡ #1784 | Địa chỉ PC: 0x0fbcd8 | Địa chỉ FDE: 0x1af4f0 | Kích thước: 136 bytes
//   0x0fbcd8: A9402829  ldp      x9, x10, [x1]
//   0x0fbcdc: CB09014B  sub      x11, x10, x9
//   0x0fbce0: A903A809  stp      x9, x10, [x0, #0x38]
//   0x0fbce4: F900240B  str      x11, [x0, #0x48]
static inline uint64_t fde_func_1784_0x0fbcd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbcd8ULL ^ (static_cast<uint64_t>(0xa9402829ULL) << 13);
    acc = (acc + a1 + 0xcb09014bULL) ^ 0x1af4f0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1785 | PC: 0x0fbd60 | FDE: 0x1af520 | Size: 256 bytes
// Khung tháo gỡ #1785 | Địa chỉ PC: 0x0fbd60 | Địa chỉ FDE: 0x1af520 | Kích thước: 256 bytes
//   0x0fbd60: F9400409  ldr      x9, [x0, #8]
//   0x0fbd64: 5280002A  mov      w10, #1
//   0x0fbd68: 3940012C  ldrb     w12, [x9]
//   0x0fbd6c: 3738006C  tbnz     w12, #7, #0xfbd78
static inline uint64_t fde_func_1785_0x0fbd60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbd60ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x5280002aULL) ^ 0x1af520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1786 | PC: 0x0fbed8 | FDE: 0x1af558 | Size: 256 bytes
// Khung tháo gỡ #1786 | Địa chỉ PC: 0x0fbed8 | Địa chỉ FDE: 0x1af558 | Kích thước: 256 bytes
//   0x0fbed8: A9402408  ldp      x8, x9, [x0]
//   0x0fbedc: CB080129  sub      x9, x9, x8
//   0x0fbee0: 9342FD29  asr      x9, x9, #2
//   0x0fbee4: EB01013F  cmp      x9, x1
static inline uint64_t fde_func_1786_0x0fbed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbed8ULL ^ (static_cast<uint64_t>(0xa9402408ULL) << 13);
    acc = (acc + a1 + 0xcb080129ULL) ^ 0x1af558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1787 | PC: 0x0fc060 | FDE: 0x1af598 | Size: 132 bytes
// Khung tháo gỡ #1787 | Địa chỉ PC: 0x0fc060 | Địa chỉ FDE: 0x1af598 | Kích thước: 132 bytes
//   0x0fc060: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fc064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fc068: 910043FD  add      x29, sp, #0x10
//   0x0fc06c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1787_0x0fc060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc060ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af598ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1788 | PC: 0x0fc0e4 | FDE: 0x1af5d0 | Size: 256 bytes
// Khung tháo gỡ #1788 | Địa chỉ PC: 0x0fc0e4 | Địa chỉ FDE: 0x1af5d0 | Kích thước: 256 bytes
//   0x0fc0e4: D102C3FF  sub      sp, sp, #0xb0
//   0x0fc0e8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0fc0ec: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0fc0f0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_1788_0x0fc0e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc0e4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x1af5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1789 | PC: 0x0fcd0c | FDE: 0x1af618 | Size: 256 bytes
// Khung tháo gỡ #1789 | Địa chỉ PC: 0x0fcd0c | Địa chỉ FDE: 0x1af618 | Kích thước: 256 bytes
//   0x0fcd0c: D101C3FF  sub      sp, sp, #0x70
//   0x0fcd10: F9001BF7  str      x23, [sp, #0x30]
//   0x0fcd14: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0fcd18: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1789_0x0fcd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcd0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1af618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1790 | PC: 0x0fcf2c | FDE: 0x1af668 | Size: 256 bytes
// Khung tháo gỡ #1790 | Địa chỉ PC: 0x0fcf2c | Địa chỉ FDE: 0x1af668 | Kích thước: 256 bytes
//   0x0fcf2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fcf30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fcf34: 910043FD  add      x29, sp, #0x10
//   0x0fcf38: 340001A1  cbz      w1, #0xfcf6c
static inline uint64_t fde_func_1790_0x0fcf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcf2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1791 | PC: 0x0fd13c | FDE: 0x1af6a8 | Size: 256 bytes
// Khung tháo gỡ #1791 | Địa chỉ PC: 0x0fd13c | Địa chỉ FDE: 0x1af6a8 | Kích thước: 256 bytes
//   0x0fd13c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fd140: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fd144: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fd148: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1791_0x0fd13c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd13cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1af6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1792 | PC: 0x0fd330 | FDE: 0x1af6e8 | Size: 256 bytes
// Khung tháo gỡ #1792 | Địa chỉ PC: 0x0fd330 | Địa chỉ FDE: 0x1af6e8 | Kích thước: 256 bytes
//   0x0fd330: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0fd334: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fd338: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fd33c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1792_0x0fd330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd330ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1af6e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1793 | PC: 0x0fd48c | FDE: 0x1af788 | Size: 224 bytes
// Khung tháo gỡ #1793 | Địa chỉ PC: 0x0fd48c | Địa chỉ FDE: 0x1af788 | Kích thước: 224 bytes
//   0x0fd48c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fd490: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fd494: 910043FD  add      x29, sp, #0x10
//   0x0fd498: F0000648  adrp     x8, #0x1c8000
static inline uint64_t fde_func_1793_0x0fd48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd48cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af788ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1794 | PC: 0x0fd56c | FDE: 0x1af7d0 | Size: 256 bytes
// Khung tháo gỡ #1794 | Địa chỉ PC: 0x0fd56c | Địa chỉ FDE: 0x1af7d0 | Kích thước: 256 bytes
//   0x0fd56c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0fd570: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0fd574: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fd578: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1794_0x0fd56c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd56cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1af7d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1795 | PC: 0x0fd6a4 | FDE: 0x1af8a0 | Size: 256 bytes
// Khung tháo gỡ #1795 | Địa chỉ PC: 0x0fd6a4 | Địa chỉ FDE: 0x1af8a0 | Kích thước: 256 bytes
//   0x0fd6a4: D105C3FF  sub      sp, sp, #0x170
//   0x0fd6a8: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x0fd6ac: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x0fd6b0: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1795_0x0fd6a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd6a4ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x1af8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1796 | PC: 0x0fdad0 | FDE: 0x1af8f0 | Size: 256 bytes
// Khung tháo gỡ #1796 | Địa chỉ PC: 0x0fdad0 | Địa chỉ FDE: 0x1af8f0 | Kích thước: 256 bytes
//   0x0fdad0: D10103FF  sub      sp, sp, #0x40
//   0x0fdad4: F9000BF5  str      x21, [sp, #0x10]
//   0x0fdad8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fdadc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1796_0x0fdad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fdad0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1af8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1797 | PC: 0x0fdf4c | FDE: 0x1af930 | Size: 256 bytes
// Khung tháo gỡ #1797 | Địa chỉ PC: 0x0fdf4c | Địa chỉ FDE: 0x1af930 | Kích thước: 256 bytes
//   0x0fdf4c: D10283FF  sub      sp, sp, #0xa0
//   0x0fdf50: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0fdf54: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0fdf58: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1797_0x0fdf4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fdf4cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1af930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1798 | PC: 0x0fe350 | FDE: 0x1af990 | Size: 256 bytes
// Khung tháo gỡ #1798 | Địa chỉ PC: 0x0fe350 | Địa chỉ FDE: 0x1af990 | Kích thước: 256 bytes
//   0x0fe350: D10443FF  sub      sp, sp, #0x110
//   0x0fe354: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0fe358: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0fe35c: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1798_0x0fe350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe350ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x1af990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1799 | PC: 0x0fe47c | FDE: 0x1af9d0 | Size: 256 bytes
// Khung tháo gỡ #1799 | Địa chỉ PC: 0x0fe47c | Địa chỉ FDE: 0x1af9d0 | Kích thước: 256 bytes
//   0x0fe47c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe480: 910003FD  mov      x29, sp
//   0x0fe484: 90000728  adrp     x8, #0x1e2000
//   0x0fe488: 91344108  add      x8, x8, #0xd10
static inline uint64_t fde_func_1799_0x0fe47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe47cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1af9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1800 | PC: 0x0fe590 | FDE: 0x1afa10 | Size: 256 bytes
// Khung tháo gỡ #1800 | Địa chỉ PC: 0x0fe590 | Địa chỉ FDE: 0x1afa10 | Kích thước: 256 bytes
//   0x0fe590: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe594: 910003FD  mov      x29, sp
//   0x0fe598: 90000728  adrp     x8, #0x1e2000
//   0x0fe59c: 9134C108  add      x8, x8, #0xd30
static inline uint64_t fde_func_1800_0x0fe590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe590ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afa10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1801 | PC: 0x0fe6b0 | FDE: 0x1afa50 | Size: 232 bytes
// Khung tháo gỡ #1801 | Địa chỉ PC: 0x0fe6b0 | Địa chỉ FDE: 0x1afa50 | Kích thước: 232 bytes
//   0x0fe6b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe6b4: 910003FD  mov      x29, sp
//   0x0fe6b8: 90000728  adrp     x8, #0x1e2000
//   0x0fe6bc: 91354108  add      x8, x8, #0xd50
static inline uint64_t fde_func_1801_0x0fe6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe6b0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afa50ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1802 | PC: 0x0fe798 | FDE: 0x1afa90 | Size: 256 bytes
// Khung tháo gỡ #1802 | Địa chỉ PC: 0x0fe798 | Địa chỉ FDE: 0x1afa90 | Kích thước: 256 bytes
//   0x0fe798: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe79c: 910003FD  mov      x29, sp
//   0x0fe7a0: 90000728  adrp     x8, #0x1e2000
//   0x0fe7a4: 9135C108  add      x8, x8, #0xd70
static inline uint64_t fde_func_1802_0x0fe798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe798ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afa90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1803 | PC: 0x0fe8a8 | FDE: 0x1afad0 | Size: 256 bytes
// Khung tháo gỡ #1803 | Địa chỉ PC: 0x0fe8a8 | Địa chỉ FDE: 0x1afad0 | Kích thước: 256 bytes
//   0x0fe8a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe8ac: 910003FD  mov      x29, sp
//   0x0fe8b0: 90000728  adrp     x8, #0x1e2000
//   0x0fe8b4: 91364108  add      x8, x8, #0xd90
static inline uint64_t fde_func_1803_0x0fe8a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe8a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1804 | PC: 0x0fe9c0 | FDE: 0x1afb10 | Size: 256 bytes
// Khung tháo gỡ #1804 | Địa chỉ PC: 0x0fe9c0 | Địa chỉ FDE: 0x1afb10 | Kích thước: 256 bytes
//   0x0fe9c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe9c4: 910003FD  mov      x29, sp
//   0x0fe9c8: 90000728  adrp     x8, #0x1e2000
//   0x0fe9cc: 9136C108  add      x8, x8, #0xdb0
static inline uint64_t fde_func_1804_0x0fe9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe9c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afb10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1805 | PC: 0x0feac0 | FDE: 0x1afb70 | Size: 256 bytes
// Khung tháo gỡ #1805 | Địa chỉ PC: 0x0feac0 | Địa chỉ FDE: 0x1afb70 | Kích thước: 256 bytes
//   0x0feac0: AA1E03E4  mov      x4, x30
//   0x0feac4: 8B000084  add      x4, x4, x0
//   0x0feac8: AA0403FE  mov      x30, x4
//   0x0feacc: D65F03C0  ret      
static inline uint64_t fde_func_1805_0x0feac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feac0ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x8b000084ULL) ^ 0x1afb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1806 | PC: 0x0fedcc | FDE: 0x1afc10 | Size: 256 bytes
// Khung tháo gỡ #1806 | Địa chỉ PC: 0x0fedcc | Địa chỉ FDE: 0x1afc10 | Kích thước: 256 bytes
//   0x0fedcc: D10283FF  sub      sp, sp, #0xa0
//   0x0fedd0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0fedd4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0fedd8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1806_0x0fedcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fedccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x1afc10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1807 | PC: 0x0ff330 | FDE: 0x1afce8 | Size: 256 bytes
// Khung tháo gỡ #1807 | Địa chỉ PC: 0x0ff330 | Địa chỉ FDE: 0x1afce8 | Kích thước: 256 bytes
//   0x0ff330: D10183FF  sub      sp, sp, #0x60
//   0x0ff334: F9001BF5  str      x21, [sp, #0x30]
//   0x0ff338: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0ff33c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1807_0x0ff330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff330ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1afce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1808 | PC: 0x0ff5b4 | FDE: 0x1afd28 | Size: 256 bytes
// Khung tháo gỡ #1808 | Địa chỉ PC: 0x0ff5b4 | Địa chỉ FDE: 0x1afd28 | Kích thước: 256 bytes
//   0x0ff5b4: D10443FF  sub      sp, sp, #0x110
//   0x0ff5b8: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0ff5bc: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0ff5c0: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1808_0x0ff5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff5b4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x1afd28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1809 | PC: 0x0ffcd4 | FDE: 0x1afd78 | Size: 32 bytes
// Khung tháo gỡ #1809 | Địa chỉ PC: 0x0ffcd4 | Địa chỉ FDE: 0x1afd78 | Kích thước: 32 bytes
//   0x0ffcd4: A9402408  ldp      x8, x9, [x0]
//   0x0ffcd8: EB09011F  cmp      x8, x9
//   0x0ffcdc: 1A9F17E0  cset     w0, eq
//   0x0ffce0: D65F03C0  ret      
static inline uint64_t fde_func_1809_0x0ffcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffcd4ULL ^ (static_cast<uint64_t>(0xa9402408ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x1afd78ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1810 | PC: 0x0ffcf4 | FDE: 0x1afda8 | Size: 108 bytes
// Khung tháo gỡ #1810 | Địa chỉ PC: 0x0ffcf4 | Địa chỉ FDE: 0x1afda8 | Kích thước: 108 bytes
//   0x0ffcf4: F9400008  ldr      x8, [x0]
//   0x0ffcf8: 8B011100  add      x0, x8, x1, lsl #4
//   0x0ffcfc: D65F03C0  ret      
//   0x0ffd00: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1810_0x0ffcf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffcf4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x8b011100ULL) ^ 0x1afda8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1811 | PC: 0x0ffd60 | FDE: 0x1afde0 | Size: 256 bytes
// Khung tháo gỡ #1811 | Địa chỉ PC: 0x0ffd60 | Địa chỉ FDE: 0x1afde0 | Kích thước: 256 bytes
//   0x0ffd60: D103C3FF  sub      sp, sp, #0xf0
//   0x0ffd64: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0ffd68: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0ffd6c: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1811_0x0ffd60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffd60ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1afde0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1812 | PC: 0x100044 | FDE: 0x1afe28 | Size: 252 bytes
// Khung tháo gỡ #1812 | Địa chỉ PC: 0x100044 | Địa chỉ FDE: 0x1afe28 | Kích thước: 252 bytes
//   0x100044: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x100048: 910003FD  mov      x29, sp
//   0x10004c: D0000708  adrp     x8, #0x1e2000
//   0x100050: 91396108  add      x8, x8, #0xe58
static inline uint64_t fde_func_1812_0x100044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100044ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afe28ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1813 | PC: 0x100140 | FDE: 0x1afe68 | Size: 248 bytes
// Khung tháo gỡ #1813 | Địa chỉ PC: 0x100140 | Địa chỉ FDE: 0x1afe68 | Kích thước: 248 bytes
//   0x100140: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x100144: 910003FD  mov      x29, sp
//   0x100148: D0000708  adrp     x8, #0x1e2000
//   0x10014c: 9139A108  add      x8, x8, #0xe68
static inline uint64_t fde_func_1813_0x100140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100140ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1afe68ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1814 | PC: 0x100238 | FDE: 0x1afec8 | Size: 48 bytes
// Khung tháo gỡ #1814 | Địa chỉ PC: 0x100238 | Địa chỉ FDE: 0x1afec8 | Kích thước: 48 bytes
//   0x100238: AA1E03E1  mov      x1, x30
//   0x10023c: 8B000021  add      x1, x1, x0
//   0x100240: AA0103FE  mov      x30, x1
//   0x100244: D65F03C0  ret      
static inline uint64_t fde_func_1814_0x100238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100238ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x1afec8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1815 | PC: 0x100268 | FDE: 0x1afef8 | Size: 28 bytes
// Khung tháo gỡ #1815 | Địa chỉ PC: 0x100268 | Địa chỉ FDE: 0x1afef8 | Kích thước: 28 bytes
//   0x100268: A9400001  ldp      x1, x0, [x0]
//   0x10026c: D61F0020  br       x1
//   0x100270: A9402003  ldp      x3, x8, [x0]
//   0x100274: F9400C02  ldr      x2, [x0, #0x18]
static inline uint64_t fde_func_1815_0x100268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100268ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1afef8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1816 | PC: 0x100284 | FDE: 0x1aff28 | Size: 56 bytes
// Khung tháo gỡ #1816 | Địa chỉ PC: 0x100284 | Địa chỉ FDE: 0x1aff28 | Kích thước: 56 bytes
//   0x100284: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x100288: F9400008  ldr      x8, [x0]
//   0x10028c: AA0003F3  mov      x19, x0
//   0x100290: D63F0100  blr      x8
static inline uint64_t fde_func_1816_0x100284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100284ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1aff28ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1817 | PC: 0x1002bc | FDE: 0x1aff58 | Size: 48 bytes
// Khung tháo gỡ #1817 | Địa chỉ PC: 0x1002bc | Địa chỉ FDE: 0x1aff58 | Kích thước: 48 bytes
//   0x1002bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1002c0: AA0003F3  mov      x19, x0
//   0x1002c4: A9400008  ldp      x8, x0, [x0]
//   0x1002c8: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_1817_0x1002bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1002bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1aff58ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1818 | PC: 0x1002ec | FDE: 0x1aff88 | Size: 56 bytes
// Khung tháo gỡ #1818 | Địa chỉ PC: 0x1002ec | Địa chỉ FDE: 0x1aff88 | Kích thước: 56 bytes
//   0x1002ec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1002f0: AA0003F3  mov      x19, x0
//   0x1002f4: A9400008  ldp      x8, x0, [x0]
//   0x1002f8: D63F0100  blr      x8
static inline uint64_t fde_func_1818_0x1002ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1002ecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1aff88ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1819 | PC: 0x100324 | FDE: 0x1affb8 | Size: 40 bytes
// Khung tháo gỡ #1819 | Địa chỉ PC: 0x100324 | Địa chỉ FDE: 0x1affb8 | Kích thước: 40 bytes
//   0x100324: A9400001  ldp      x1, x0, [x0]
//   0x100328: D61F0020  br       x1
//   0x10032c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x100330: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1819_0x100324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100324ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1affb8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1820 | PC: 0x10034c | FDE: 0x1affe8 | Size: 60 bytes
// Khung tháo gỡ #1820 | Địa chỉ PC: 0x10034c | Địa chỉ FDE: 0x1affe8 | Kích thước: 60 bytes
//   0x10034c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x100350: AA0003F3  mov      x19, x0
//   0x100354: A9400008  ldp      x8, x0, [x0]
//   0x100358: D63F0100  blr      x8
static inline uint64_t fde_func_1820_0x10034c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10034cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1affe8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1821 | PC: 0x100388 | FDE: 0x1b0018 | Size: 56 bytes
// Khung tháo gỡ #1821 | Địa chỉ PC: 0x100388 | Địa chỉ FDE: 0x1b0018 | Kích thước: 56 bytes
//   0x100388: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10038c: AA0003F3  mov      x19, x0
//   0x100390: A9400008  ldp      x8, x0, [x0]
//   0x100394: D63F0100  blr      x8
static inline uint64_t fde_func_1821_0x100388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100388ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1b0018ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1822 | PC: 0x1003c0 | FDE: 0x1b0048 | Size: 20 bytes
// Khung tháo gỡ #1822 | Địa chỉ PC: 0x1003c0 | Địa chỉ FDE: 0x1b0048 | Kích thước: 20 bytes
//   0x1003c0: A9400001  ldp      x1, x0, [x0]
//   0x1003c4: D61F0020  br       x1
//   0x1003c8: AA0003E2  mov      x2, x0
//   0x1003cc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1822_0x1003c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1003c0ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1b0048ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1823 | PC: 0x1003d4 | FDE: 0x1b0078 | Size: 256 bytes
// Khung tháo gỡ #1823 | Địa chỉ PC: 0x1003d4 | Địa chỉ FDE: 0x1b0078 | Kích thước: 256 bytes
//   0x1003d4: D10103FF  sub      sp, sp, #0x40
//   0x1003d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1003dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1003e0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1823_0x1003d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1003d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1b0078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1824 | PC: 0x1005c8 | FDE: 0x1b0130 | Size: 256 bytes
// Khung tháo gỡ #1824 | Địa chỉ PC: 0x1005c8 | Địa chỉ FDE: 0x1b0130 | Kích thước: 256 bytes
//   0x1005c8: D10183FF  sub      sp, sp, #0x60
//   0x1005cc: F9001BF5  str      x21, [sp, #0x30]
//   0x1005d0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1005d4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1824_0x1005c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1005c8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1b0130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1825 | PC: 0x1009d0 | FDE: 0x1b0180 | Size: 256 bytes
// Khung tháo gỡ #1825 | Địa chỉ PC: 0x1009d0 | Địa chỉ FDE: 0x1b0180 | Kích thước: 256 bytes
//   0x1009d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1009d4: 910003FD  mov      x29, sp
//   0x1009d8: D0000708  adrp     x8, #0x1e2000
//   0x1009dc: 913B6108  add      x8, x8, #0xed8
static inline uint64_t fde_func_1825_0x1009d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1009d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1826 | PC: 0x100ba4 | FDE: 0x1b01c0 | Size: 116 bytes
// Khung tháo gỡ #1826 | Địa chỉ PC: 0x100ba4 | Địa chỉ FDE: 0x1b01c0 | Kích thước: 116 bytes
//   0x100ba4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x100ba8: 910003FD  mov      x29, sp
//   0x100bac: F9400408  ldr      x8, [x0, #8]
//   0x100bb0: B9400401  ldr      w1, [x0, #4]
static inline uint64_t fde_func_1826_0x100ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100ba4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b01c0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1827 | PC: 0x100c18 | FDE: 0x1b0200 | Size: 156 bytes
// Khung tháo gỡ #1827 | Địa chỉ PC: 0x100c18 | Địa chỉ FDE: 0x1b0200 | Kích thước: 156 bytes
//   0x100c18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x100c1c: 910003FD  mov      x29, sp
//   0x100c20: F000002A  adrp     x10, #0x107000
//   0x100c24: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1827_0x100c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100c18ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0200ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1828 | PC: 0x100cb4 | FDE: 0x1b0240 | Size: 116 bytes
// Khung tháo gỡ #1828 | Địa chỉ PC: 0x100cb4 | Địa chỉ FDE: 0x1b0240 | Kích thước: 116 bytes
//   0x100cb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x100cb8: 910003FD  mov      x29, sp
//   0x100cbc: F9400408  ldr      x8, [x0, #8]
//   0x100cc0: B9400401  ldr      w1, [x0, #4]
static inline uint64_t fde_func_1828_0x100cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100cb4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0240ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1829 | PC: 0x100d28 | FDE: 0x1b0280 | Size: 116 bytes
// Khung tháo gỡ #1829 | Địa chỉ PC: 0x100d28 | Địa chỉ FDE: 0x1b0280 | Kích thước: 116 bytes
//   0x100d28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x100d2c: 910003FD  mov      x29, sp
//   0x100d30: F9400408  ldr      x8, [x0, #8]
//   0x100d34: D10043FF  sub      sp, sp, #0x10
static inline uint64_t fde_func_1829_0x100d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100d28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0280ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1830 | PC: 0x100d9c | FDE: 0x1b02c0 | Size: 256 bytes
// Khung tháo gỡ #1830 | Địa chỉ PC: 0x100d9c | Địa chỉ FDE: 0x1b02c0 | Kích thước: 256 bytes
//   0x100d9c: D10143FF  sub      sp, sp, #0x50
//   0x100da0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x100da4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x100da8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1830_0x100d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100d9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1b02c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1831 | PC: 0x101030 | FDE: 0x1b0310 | Size: 256 bytes
// Khung tháo gỡ #1831 | Địa chỉ PC: 0x101030 | Địa chỉ FDE: 0x1b0310 | Kích thước: 256 bytes
//   0x101030: D10283FF  sub      sp, sp, #0xa0
//   0x101034: F90033F7  str      x23, [sp, #0x60]
//   0x101038: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x10103c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1831_0x101030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101030ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1b0310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1832 | PC: 0x101674 | FDE: 0x1b0360 | Size: 256 bytes
// Khung tháo gỡ #1832 | Địa chỉ PC: 0x101674 | Địa chỉ FDE: 0x1b0360 | Kích thước: 256 bytes
//   0x101674: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x101678: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10167c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x101680: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1832_0x101674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101674ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b0360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1833 | PC: 0x102800 | FDE: 0x1b03b0 | Size: 256 bytes
// Khung tháo gỡ #1833 | Địa chỉ PC: 0x102800 | Địa chỉ FDE: 0x1b03b0 | Kích thước: 256 bytes
//   0x102800: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x102804: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x102808: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10280c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1833_0x102800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102800ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b03b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1834 | PC: 0x1032cc | FDE: 0x1b0408 | Size: 256 bytes
// Khung tháo gỡ #1834 | Địa chỉ PC: 0x1032cc | Địa chỉ FDE: 0x1b0408 | Kích thước: 256 bytes
//   0x1032cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1032d0: 910003FD  mov      x29, sp
//   0x1032d4: F9400009  ldr      x9, [x0]
//   0x1032d8: B9400129  ldr      w9, [x9]
static inline uint64_t fde_func_1834_0x1032cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1032ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1835 | PC: 0x103440 | FDE: 0x1b0450 | Size: 256 bytes
// Khung tháo gỡ #1835 | Địa chỉ PC: 0x103440 | Địa chỉ FDE: 0x1b0450 | Kích thước: 256 bytes
//   0x103440: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x103444: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x103448: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10344c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1835_0x103440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103440ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1b0450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1836 | PC: 0x103f60 | FDE: 0x1b04a8 | Size: 256 bytes
// Khung tháo gỡ #1836 | Địa chỉ PC: 0x103f60 | Địa chỉ FDE: 0x1b04a8 | Kích thước: 256 bytes
//   0x103f60: D10383FF  sub      sp, sp, #0xe0
//   0x103f64: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x103f68: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x103f6c: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_1836_0x103f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103f60ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b57f6ULL) ^ 0x1b04a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1837 | PC: 0x104cf4 | FDE: 0x1b04f8 | Size: 256 bytes
// Khung tháo gỡ #1837 | Địa chỉ PC: 0x104cf4 | Địa chỉ FDE: 0x1b04f8 | Kích thước: 256 bytes
//   0x104cf4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x104cf8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x104cfc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x104d00: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1837_0x104cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104cf4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b04f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1838 | PC: 0x106dac | FDE: 0x1b0550 | Size: 256 bytes
// Khung tháo gỡ #1838 | Địa chỉ PC: 0x106dac | Địa chỉ FDE: 0x1b0550 | Kích thước: 256 bytes
//   0x106dac: D10183FF  sub      sp, sp, #0x60
//   0x106db0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x106db4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x106db8: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1838_0x106dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106dacULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x1b0550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1839 | PC: 0x106f28 | FDE: 0x1b0590 | Size: 256 bytes
// Khung tháo gỡ #1839 | Địa chỉ PC: 0x106f28 | Địa chỉ FDE: 0x1b0590 | Kích thước: 256 bytes
//   0x106f28: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x106f2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x106f30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x106f34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1839_0x106f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106f28ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b0590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1840 | PC: 0x107028 | FDE: 0x1b05e0 | Size: 156 bytes
// Khung tháo gỡ #1840 | Địa chỉ PC: 0x107028 | Địa chỉ FDE: 0x1b05e0 | Kích thước: 156 bytes
//   0x107028: 52800020  mov      w0, #1
//   0x10702c: D65F03C0  ret      
//   0x107030: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x107034: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1840_0x107028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107028ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1b05e0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1841 | PC: 0x1070c4 | FDE: 0x1b0618 | Size: 176 bytes
// Khung tháo gỡ #1841 | Địa chỉ PC: 0x1070c4 | Địa chỉ FDE: 0x1b0618 | Kích thước: 176 bytes
//   0x1070c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1070c8: 910003FD  mov      x29, sp
//   0x1070cc: F00006C8  adrp     x8, #0x1e2000
//   0x1070d0: 913C2108  add      x8, x8, #0xf08
static inline uint64_t fde_func_1841_0x1070c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1070c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0618ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1842 | PC: 0x107174 | FDE: 0x1b0678 | Size: 140 bytes
// Khung tháo gỡ #1842 | Địa chỉ PC: 0x107174 | Địa chỉ FDE: 0x1b0678 | Kích thước: 140 bytes
//   0x107174: AA1E03E1  mov      x1, x30
//   0x107178: 8B000021  add      x1, x1, x0
//   0x10717c: AA0103FE  mov      x30, x1
//   0x107180: D65F03C0  ret      
static inline uint64_t fde_func_1842_0x107174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107174ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x1b0678ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1843 | PC: 0x107200 | FDE: 0x1b0710 | Size: 72 bytes
// Khung tháo gỡ #1843 | Địa chỉ PC: 0x107200 | Địa chỉ FDE: 0x1b0710 | Kích thước: 72 bytes
//   0x107200: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x107204: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x107208: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10720c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1843_0x107200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107200ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b0710ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1844 | PC: 0x107248 | FDE: 0x1b0748 | Size: 256 bytes
// Khung tháo gỡ #1844 | Địa chỉ PC: 0x107248 | Địa chỉ FDE: 0x1b0748 | Kích thước: 256 bytes
//   0x107248: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x10724c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x107250: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x107254: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1844_0x107248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107248ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b0748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1845 | PC: 0x10c1f0 | FDE: 0x1b0790 | Size: 256 bytes
// Khung tháo gỡ #1845 | Địa chỉ PC: 0x10c1f0 | Địa chỉ FDE: 0x1b0790 | Kích thước: 256 bytes
//   0x10c1f0: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x10c1f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c1f8: 910043FD  add      x29, sp, #0x10
//   0x10c1fc: D115C3FF  sub      sp, sp, #0x570
static inline uint64_t fde_func_1845_0x10c1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c1f0ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1846 | PC: 0x10c300 | FDE: 0x1b07d0 | Size: 96 bytes
// Khung tháo gỡ #1846 | Địa chỉ PC: 0x10c300 | Địa chỉ FDE: 0x1b07d0 | Kích thước: 96 bytes
//   0x10c300: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10c304: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c308: 910043FD  add      x29, sp, #0x10
//   0x10c30c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1846_0x10c300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c300ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b07d0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1847 | PC: 0x10c360 | FDE: 0x1b0810 | Size: 172 bytes
// Khung tháo gỡ #1847 | Địa chỉ PC: 0x10c360 | Địa chỉ FDE: 0x1b0810 | Kích thước: 172 bytes
//   0x10c360: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c364: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c368: 910043FD  add      x29, sp, #0x10
//   0x10c36c: F9401814  ldr      x20, [x0, #0x30]
static inline uint64_t fde_func_1847_0x10c360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c360ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0810ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1848 | PC: 0x10c40c | FDE: 0x1b0850 | Size: 256 bytes
// Khung tháo gỡ #1848 | Địa chỉ PC: 0x10c40c | Địa chỉ FDE: 0x1b0850 | Kích thước: 256 bytes
//   0x10c40c: D10383FF  sub      sp, sp, #0xe0
//   0x10c410: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x10c414: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x10c418: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1848_0x10c40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c40cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x1b0850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1849 | PC: 0x10caac | FDE: 0x1b08b0 | Size: 256 bytes
// Khung tháo gỡ #1849 | Địa chỉ PC: 0x10caac | Địa chỉ FDE: 0x1b08b0 | Kích thước: 256 bytes
//   0x10caac: D101C3FF  sub      sp, sp, #0x70
//   0x10cab0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x10cab4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x10cab8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1849_0x10caac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10caacULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1b08b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1850 | PC: 0x10cc64 | FDE: 0x1b08f8 | Size: 16 bytes
// Khung tháo gỡ #1850 | Địa chỉ PC: 0x10cc64 | Địa chỉ FDE: 0x1b08f8 | Kích thước: 16 bytes
//   0x10cc64: F9400800  ldr      x0, [x0, #0x10]
//   0x10cc68: D65F03C0  ret      
//   0x10cc6c: F900001F  str      xzr, [x0]
//   0x10cc70: D65F03C0  ret      
static inline uint64_t fde_func_1850_0x10cc64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cc64ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1b08f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1851 | PC: 0x10cc74 | FDE: 0x1b0928 | Size: 196 bytes
// Khung tháo gỡ #1851 | Địa chỉ PC: 0x10cc74 | Địa chỉ FDE: 0x1b0928 | Kích thước: 196 bytes
//   0x10cc74: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10cc78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10cc7c: 910043FD  add      x29, sp, #0x10
//   0x10cc80: F9400C20  ldr      x0, [x1, #0x18]
static inline uint64_t fde_func_1851_0x10cc74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cc74ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0928ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1852 | PC: 0x10cd38 | FDE: 0x1b0968 | Size: 104 bytes
// Khung tháo gỡ #1852 | Địa chỉ PC: 0x10cd38 | Địa chỉ FDE: 0x1b0968 | Kích thước: 104 bytes
//   0x10cd38: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10cd3c: 910003FD  mov      x29, sp
//   0x10cd40: F9400408  ldr      x8, [x0, #8]
//   0x10cd44: 900005E9  adrp     x9, #0x1c8000
static inline uint64_t fde_func_1852_0x10cd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cd38ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b0968ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1853 | PC: 0x10cda0 | FDE: 0x1b09a8 | Size: 256 bytes
// Khung tháo gỡ #1853 | Địa chỉ PC: 0x10cda0 | Địa chỉ FDE: 0x1b09a8 | Kích thước: 256 bytes
//   0x10cda0: D10183FF  sub      sp, sp, #0x60
//   0x10cda4: F9001BF5  str      x21, [sp, #0x30]
//   0x10cda8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x10cdac: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1853_0x10cda0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cda0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1b09a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1854 | PC: 0x10cee0 | FDE: 0x1b09f0 | Size: 256 bytes
// Khung tháo gỡ #1854 | Địa chỉ PC: 0x10cee0 | Địa chỉ FDE: 0x1b09f0 | Kích thước: 256 bytes
//   0x10cee0: D10183FF  sub      sp, sp, #0x60
//   0x10cee4: F9001BF5  str      x21, [sp, #0x30]
//   0x10cee8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x10ceec: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1854_0x10cee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cee0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1b09f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1855 | PC: 0x10d00c | FDE: 0x1b0a28 | Size: 64 bytes
// Khung tháo gỡ #1855 | Địa chỉ PC: 0x10d00c | Địa chỉ FDE: 0x1b0a28 | Kích thước: 64 bytes
//   0x10d00c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10d010: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10d014: 910043FD  add      x29, sp, #0x10
//   0x10d018: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_1855_0x10d00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d00cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0a28ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1856 | PC: 0x10d04c | FDE: 0x1b0a80 | Size: 28 bytes
// Khung tháo gỡ #1856 | Địa chỉ PC: 0x10d04c | Địa chỉ FDE: 0x1b0a80 | Kích thước: 28 bytes
//   0x10d04c: AA1E03E4  mov      x4, x30
//   0x10d050: 8B000084  add      x4, x4, x0
//   0x10d054: AA0403FE  mov      x30, x4
//   0x10d058: D65F03C0  ret      
static inline uint64_t fde_func_1856_0x10d04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d04cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x8b000084ULL) ^ 0x1b0a80ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1857 | PC: 0x10d068 | FDE: 0x1b0ab0 | Size: 52 bytes
// Khung tháo gỡ #1857 | Địa chỉ PC: 0x10d068 | Địa chỉ FDE: 0x1b0ab0 | Kích thước: 52 bytes
//   0x10d068: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d06c: A9402009  ldp      x9, x8, [x0]
//   0x10d070: F9400800  ldr      x0, [x0, #0x10]
//   0x10d074: D63F0120  blr      x9
static inline uint64_t fde_func_1857_0x10d068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d068ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1b0ab0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1858 | PC: 0x10d09c | FDE: 0x1b0ae0 | Size: 40 bytes
// Khung tháo gỡ #1858 | Địa chỉ PC: 0x10d09c | Địa chỉ FDE: 0x1b0ae0 | Kích thước: 40 bytes
//   0x10d09c: F9400000  ldr      x0, [x0]
//   0x10d0a0: D61F0000  br       x0
//   0x10d0a4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d0a8: A9410409  ldp      x9, x1, [x0, #0x10]
static inline uint64_t fde_func_1858_0x10d09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d09cULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd61f0000ULL) ^ 0x1b0ae0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1859 | PC: 0x10d0c4 | FDE: 0x1b0b10 | Size: 60 bytes
// Khung tháo gỡ #1859 | Địa chỉ PC: 0x10d0c4 | Địa chỉ FDE: 0x1b0b10 | Kích thước: 60 bytes
//   0x10d0c4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10d0c8: AA0003F3  mov      x19, x0
//   0x10d0cc: A9400008  ldp      x8, x0, [x0]
//   0x10d0d0: D63F0100  blr      x8
static inline uint64_t fde_func_1859_0x10d0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d0c4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1b0b10ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1860 | PC: 0x10d100 | FDE: 0x1b0b40 | Size: 48 bytes
// Khung tháo gỡ #1860 | Địa chỉ PC: 0x10d100 | Địa chỉ FDE: 0x1b0b40 | Kích thước: 48 bytes
//   0x10d100: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10d104: AA0003F3  mov      x19, x0
//   0x10d108: A9400008  ldp      x8, x0, [x0]
//   0x10d10c: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_1860_0x10d100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d100ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1b0b40ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1861 | PC: 0x10d130 | FDE: 0x1b0b70 | Size: 24 bytes
// Khung tháo gỡ #1861 | Địa chỉ PC: 0x10d130 | Địa chỉ FDE: 0x1b0b70 | Kích thước: 24 bytes
//   0x10d130: A9400001  ldp      x1, x0, [x0]
//   0x10d134: D61F0020  br       x1
//   0x10d138: A9402002  ldp      x2, x8, [x0]
//   0x10d13c: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_1861_0x10d130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d130ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1b0b70ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1862 | PC: 0x10d148 | FDE: 0x1b0ba0 | Size: 32 bytes
// Khung tháo gỡ #1862 | Địa chỉ PC: 0x10d148 | Địa chỉ FDE: 0x1b0ba0 | Kích thước: 32 bytes
//   0x10d148: A9400001  ldp      x1, x0, [x0]
//   0x10d14c: D61F0020  br       x1
//   0x10d150: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d154: A9402009  ldp      x9, x8, [x0]
static inline uint64_t fde_func_1862_0x10d148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d148ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1b0ba0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1863 | PC: 0x10d168 | FDE: 0x1b0bd0 | Size: 20 bytes
// Khung tháo gỡ #1863 | Địa chỉ PC: 0x10d168 | Địa chỉ FDE: 0x1b0bd0 | Kích thước: 20 bytes
//   0x10d168: A9400001  ldp      x1, x0, [x0]
//   0x10d16c: D61F0020  br       x1
//   0x10d170: AA0003E2  mov      x2, x0
//   0x10d174: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1863_0x10d168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d168ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1b0bd0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1864 | PC: 0x10d17c | FDE: 0x1b0c00 | Size: 52 bytes
// Khung tháo gỡ #1864 | Địa chỉ PC: 0x10d17c | Địa chỉ FDE: 0x1b0c00 | Kích thước: 52 bytes
//   0x10d17c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d180: A9402009  ldp      x9, x8, [x0]
//   0x10d184: F9400800  ldr      x0, [x0, #0x10]
//   0x10d188: D63F0120  blr      x9
static inline uint64_t fde_func_1864_0x10d17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d17cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1b0c00ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1865 | PC: 0x10d1b0 | FDE: 0x1b0c30 | Size: 52 bytes
// Khung tháo gỡ #1865 | Địa chỉ PC: 0x10d1b0 | Địa chỉ FDE: 0x1b0c30 | Kích thước: 52 bytes
//   0x10d1b0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d1b4: A9402009  ldp      x9, x8, [x0]
//   0x10d1b8: F9400800  ldr      x0, [x0, #0x10]
//   0x10d1bc: D63F0120  blr      x9
static inline uint64_t fde_func_1865_0x10d1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d1b0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1b0c30ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1866 | PC: 0x10d1e4 | FDE: 0x1b0c60 | Size: 48 bytes
// Khung tháo gỡ #1866 | Địa chỉ PC: 0x10d1e4 | Địa chỉ FDE: 0x1b0c60 | Kích thước: 48 bytes
//   0x10d1e4: A9402003  ldp      x3, x8, [x0]
//   0x10d1e8: F9400801  ldr      x1, [x0, #0x10]
//   0x10d1ec: B9401802  ldr      w2, [x0, #0x18]
//   0x10d1f0: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1866_0x10d1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d1e4ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1b0c60ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1867 | PC: 0x10d214 | FDE: 0x1b0c90 | Size: 24 bytes
// Khung tháo gỡ #1867 | Địa chỉ PC: 0x10d214 | Địa chỉ FDE: 0x1b0c90 | Kích thước: 24 bytes
//   0x10d214: F9400000  ldr      x0, [x0]
//   0x10d218: D61F0000  br       x0
//   0x10d21c: A9402002  ldp      x2, x8, [x0]
//   0x10d220: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_1867_0x10d214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d214ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd61f0000ULL) ^ 0x1b0c90ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1868 | PC: 0x10d22c | FDE: 0x1b0cc0 | Size: 48 bytes
// Khung tháo gỡ #1868 | Địa chỉ PC: 0x10d22c | Địa chỉ FDE: 0x1b0cc0 | Kích thước: 48 bytes
//   0x10d22c: A9402002  ldp      x2, x8, [x0]
//   0x10d230: F9400801  ldr      x1, [x0, #0x10]
//   0x10d234: AA0803E0  mov      x0, x8
//   0x10d238: D61F0040  br       x2
static inline uint64_t fde_func_1868_0x10d22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d22cULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1b0cc0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1869 | PC: 0x10d25c | FDE: 0x1b0cf0 | Size: 52 bytes
// Khung tháo gỡ #1869 | Địa chỉ PC: 0x10d25c | Địa chỉ FDE: 0x1b0cf0 | Kích thước: 52 bytes
//   0x10d25c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d260: A9402009  ldp      x9, x8, [x0]
//   0x10d264: F9400800  ldr      x0, [x0, #0x10]
//   0x10d268: D63F0120  blr      x9
static inline uint64_t fde_func_1869_0x10d25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d25cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1b0cf0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1870 | PC: 0x10d290 | FDE: 0x1b0d20 | Size: 40 bytes
// Khung tháo gỡ #1870 | Địa chỉ PC: 0x10d290 | Địa chỉ FDE: 0x1b0d20 | Kích thước: 40 bytes
//   0x10d290: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10d294: A9402009  ldp      x9, x8, [x0]
//   0x10d298: D63F0120  blr      x9
//   0x10d29c: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1870_0x10d290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d290ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1b0d20ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1871 | PC: 0x10d2b8 | FDE: 0x1b0d50 | Size: 24 bytes
// Khung tháo gỡ #1871 | Địa chỉ PC: 0x10d2b8 | Địa chỉ FDE: 0x1b0d50 | Kích thước: 24 bytes
//   0x10d2b8: A9402002  ldp      x2, x8, [x0]
//   0x10d2bc: F9400801  ldr      x1, [x0, #0x10]
//   0x10d2c0: AA0803E0  mov      x0, x8
//   0x10d2c4: D61F0040  br       x2
static inline uint64_t fde_func_1871_0x10d2b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d2b8ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1b0d50ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1872 | PC: 0x10d2d0 | FDE: 0x1b0d80 | Size: 124 bytes
// Khung tháo gỡ #1872 | Địa chỉ PC: 0x10d2d0 | Địa chỉ FDE: 0x1b0d80 | Kích thước: 124 bytes
//   0x10d2d0: A9400001  ldp      x1, x0, [x0]
//   0x10d2d4: D61F0020  br       x1
//   0x10d2d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x10d2dc: A9014FF4  stp      x20, x19, [sp, #0x10]
static inline uint64_t fde_func_1872_0x10d2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d2d0ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1b0d80ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1873 | PC: 0x10d34c | FDE: 0x1b0e18 | Size: 256 bytes
// Khung tháo gỡ #1873 | Địa chỉ PC: 0x10d34c | Địa chỉ FDE: 0x1b0e18 | Kích thước: 256 bytes
//   0x10d34c: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x10d350: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10d354: 910043FD  add      x29, sp, #0x10
//   0x10d358: D11603FF  sub      sp, sp, #0x580
static inline uint64_t fde_func_1873_0x10d34c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d34cULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0e18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1874 | PC: 0x10d478 | FDE: 0x1b0e60 | Size: 252 bytes
// Khung tháo gỡ #1874 | Địa chỉ PC: 0x10d478 | Địa chỉ FDE: 0x1b0e60 | Kích thước: 252 bytes
//   0x10d478: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x10d47c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10d480: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10d484: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1874_0x10d478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d478ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b0e60ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1875 | PC: 0x10d574 | FDE: 0x1b0ea8 | Size: 240 bytes
// Khung tháo gỡ #1875 | Địa chỉ PC: 0x10d574 | Địa chỉ FDE: 0x1b0ea8 | Kích thước: 240 bytes
//   0x10d574: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10d578: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10d57c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10d580: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1875_0x10d574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d574ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b0ea8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1876 | PC: 0x10d664 | FDE: 0x1b0ef8 | Size: 236 bytes
// Khung tháo gỡ #1876 | Địa chỉ PC: 0x10d664 | Địa chỉ FDE: 0x1b0ef8 | Kích thước: 236 bytes
//   0x10d664: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x10d668: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10d66c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10d670: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1876_0x10d664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d664ULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b0ef8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1877 | PC: 0x10d750 | FDE: 0x1b0f40 | Size: 184 bytes
// Khung tháo gỡ #1877 | Địa chỉ PC: 0x10d750 | Địa chỉ FDE: 0x1b0f40 | Kích thước: 184 bytes
//   0x10d750: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10d754: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10d758: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10d75c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1877_0x10d750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d750ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b0f40ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1878 | PC: 0x10d808 | FDE: 0x1b0f88 | Size: 256 bytes
// Khung tháo gỡ #1878 | Địa chỉ PC: 0x10d808 | Địa chỉ FDE: 0x1b0f88 | Kích thước: 256 bytes
//   0x10d808: D103C3FF  sub      sp, sp, #0xf0
//   0x10d80c: F9005BF7  str      x23, [sp, #0xb0]
//   0x10d810: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x10d814: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_1878_0x10d808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d808ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf7ULL) ^ 0x1b0f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1879 | PC: 0x10dc1c | FDE: 0x1b0fd0 | Size: 152 bytes
// Khung tháo gỡ #1879 | Địa chỉ PC: 0x10dc1c | Địa chỉ FDE: 0x1b0fd0 | Kích thước: 152 bytes
//   0x10dc1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10dc20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10dc24: 910043FD  add      x29, sp, #0x10
//   0x10dc28: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1879_0x10dc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dc1cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0fd0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1880 | PC: 0x10dcb4 | FDE: 0x1b1030 | Size: 40 bytes
// Khung tháo gỡ #1880 | Địa chỉ PC: 0x10dcb4 | Địa chỉ FDE: 0x1b1030 | Kích thước: 40 bytes
//   0x10dcb4: AA1E03E1  mov      x1, x30
//   0x10dcb8: 8B000021  add      x1, x1, x0
//   0x10dcbc: AA0103FE  mov      x30, x1
//   0x10dcc0: D65F03C0  ret      
static inline uint64_t fde_func_1880_0x10dcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dcb4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x1b1030ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1881 | PC: 0x10dcdc | FDE: 0x1b1060 | Size: 40 bytes
// Khung tháo gỡ #1881 | Địa chỉ PC: 0x10dcdc | Địa chỉ FDE: 0x1b1060 | Kích thước: 40 bytes
//   0x10dcdc: A9400001  ldp      x1, x0, [x0]
//   0x10dce0: D61F0020  br       x1
//   0x10dce4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10dce8: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_1881_0x10dcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dcdcULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1b1060ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1882 | PC: 0x10dd04 | FDE: 0x1b1090 | Size: 52 bytes
// Khung tháo gỡ #1882 | Địa chỉ PC: 0x10dd04 | Địa chỉ FDE: 0x1b1090 | Kích thước: 52 bytes
//   0x10dd04: A9402005  ldp      x5, x8, [x0]
//   0x10dd08: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x10dd0c: A9421003  ldp      x3, x4, [x0, #0x20]
//   0x10dd10: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1882_0x10dd04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dd04ULL ^ (static_cast<uint64_t>(0xa9402005ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x1b1090ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1883 | PC: 0x10dd38 | FDE: 0x1b10c0 | Size: 56 bytes
// Khung tháo gỡ #1883 | Địa chỉ PC: 0x10dd38 | Địa chỉ FDE: 0x1b10c0 | Kích thước: 56 bytes
//   0x10dd38: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10dd3c: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x10dd40: A940200A  ldp      x10, x8, [x0]
//   0x10dd44: AA0903E0  mov      x0, x9
static inline uint64_t fde_func_1883_0x10dd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dd38ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x1b10c0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1884 | PC: 0x10dd70 | FDE: 0x1b10f0 | Size: 60 bytes
// Khung tháo gỡ #1884 | Địa chỉ PC: 0x10dd70 | Địa chỉ FDE: 0x1b10f0 | Kích thước: 60 bytes
//   0x10dd70: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10dd74: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x10dd78: A940200A  ldp      x10, x8, [x0]
//   0x10dd7c: AA0903E0  mov      x0, x9
static inline uint64_t fde_func_1884_0x10dd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dd70ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x1b10f0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1885 | PC: 0x10ddac | FDE: 0x1b1120 | Size: 52 bytes
// Khung tháo gỡ #1885 | Địa chỉ PC: 0x10ddac | Địa chỉ FDE: 0x1b1120 | Kích thước: 52 bytes
//   0x10ddac: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10ddb0: A9402009  ldp      x9, x8, [x0]
//   0x10ddb4: F9400800  ldr      x0, [x0, #0x10]
//   0x10ddb8: D63F0120  blr      x9
static inline uint64_t fde_func_1885_0x10ddac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ddacULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1b1120ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1886 | PC: 0x10dde0 | FDE: 0x1b1150 | Size: 56 bytes
// Khung tháo gỡ #1886 | Địa chỉ PC: 0x10dde0 | Địa chỉ FDE: 0x1b1150 | Kích thước: 56 bytes
//   0x10dde0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10dde4: AA0003F3  mov      x19, x0
//   0x10dde8: A9400008  ldp      x8, x0, [x0]
//   0x10ddec: D63F0100  blr      x8
static inline uint64_t fde_func_1886_0x10dde0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dde0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1b1150ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1887 | PC: 0x10de18 | FDE: 0x1b1180 | Size: 72 bytes
// Khung tháo gỡ #1887 | Địa chỉ PC: 0x10de18 | Địa chỉ FDE: 0x1b1180 | Kích thước: 72 bytes
//   0x10de18: AA0003E2  mov      x2, x0
//   0x10de1c: AA0103E0  mov      x0, x1
//   0x10de20: D61F0040  br       x2
//   0x10de24: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_1887_0x10de18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10de18ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x1b1180ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1888 | PC: 0x10de60 | FDE: 0x1b1210 | Size: 256 bytes
// Khung tháo gỡ #1888 | Địa chỉ PC: 0x10de60 | Địa chỉ FDE: 0x1b1210 | Kích thước: 256 bytes
//   0x10de60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10de64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10de68: 910043FD  add      x29, sp, #0x10
//   0x10de6c: B00005A8  adrp     x8, #0x1c2000
static inline uint64_t fde_func_1888_0x10de60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10de60ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b1210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1889 | PC: 0x10dfc4 | FDE: 0x1b1258 | Size: 256 bytes
// Khung tháo gỡ #1889 | Địa chỉ PC: 0x10dfc4 | Địa chỉ FDE: 0x1b1258 | Kích thước: 256 bytes
//   0x10dfc4: D10203FF  sub      sp, sp, #0x80
//   0x10dfc8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x10dfcc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x10dfd0: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1889_0x10dfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dfc4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1b1258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1890 | PC: 0x10e21c | FDE: 0x1b12a0 | Size: 248 bytes
// Khung tháo gỡ #1890 | Địa chỉ PC: 0x10e21c | Địa chỉ FDE: 0x1b12a0 | Kích thước: 248 bytes
//   0x10e21c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10e220: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10e224: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10e228: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1890_0x10e21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e21cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b12a0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1891 | PC: 0x10e314 | FDE: 0x1b12e8 | Size: 244 bytes
// Khung tháo gỡ #1891 | Địa chỉ PC: 0x10e314 | Địa chỉ FDE: 0x1b12e8 | Kích thước: 244 bytes
//   0x10e314: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x10e318: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10e31c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10e320: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1891_0x10e314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e314ULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b12e8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1892 | PC: 0x10e408 | FDE: 0x1b1338 | Size: 256 bytes
// Khung tháo gỡ #1892 | Địa chỉ PC: 0x10e408 | Địa chỉ FDE: 0x1b1338 | Kích thước: 256 bytes
//   0x10e408: D10203FF  sub      sp, sp, #0x80
//   0x10e40c: F90013FB  str      x27, [sp, #0x20]
//   0x10e410: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x10e414: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1892_0x10e408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e408ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1b1338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1893 | PC: 0x10e760 | FDE: 0x1b1400 | Size: 256 bytes
// Khung tháo gỡ #1893 | Địa chỉ PC: 0x10e760 | Địa chỉ FDE: 0x1b1400 | Kích thước: 256 bytes
//   0x10e760: D10143FF  sub      sp, sp, #0x50
//   0x10e764: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x10e768: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10e76c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1893_0x10e760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e760ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0223e9ULL) ^ 0x1b1400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1894 | PC: 0x10e8cc | FDE: 0x1b1448 | Size: 256 bytes
// Khung tháo gỡ #1894 | Địa chỉ PC: 0x10e8cc | Địa chỉ FDE: 0x1b1448 | Kích thước: 256 bytes
//   0x10e8cc: D101C3FF  sub      sp, sp, #0x70
//   0x10e8d0: F9001BF7  str      x23, [sp, #0x30]
//   0x10e8d4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x10e8d8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1894_0x10e8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e8ccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1b1448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1895 | PC: 0x10eb38 | FDE: 0x1b1498 | Size: 256 bytes
// Khung tháo gỡ #1895 | Địa chỉ PC: 0x10eb38 | Địa chỉ FDE: 0x1b1498 | Kích thước: 256 bytes
//   0x10eb38: D10143FF  sub      sp, sp, #0x50
//   0x10eb3c: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x10eb40: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10eb44: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1895_0x10eb38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eb38ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0223e9ULL) ^ 0x1b1498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1896 | PC: 0x10ec5c | FDE: 0x1b14e0 | Size: 256 bytes
// Khung tháo gỡ #1896 | Địa chỉ PC: 0x10ec5c | Địa chỉ FDE: 0x1b14e0 | Kích thước: 256 bytes
//   0x10ec5c: D10243FF  sub      sp, sp, #0x90
//   0x10ec60: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x10ec64: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x10ec68: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1896_0x10ec5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ec5cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x1b14e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1897 | PC: 0x10ee00 | FDE: 0x1b1540 | Size: 68 bytes
// Khung tháo gỡ #1897 | Địa chỉ PC: 0x10ee00 | Địa chỉ FDE: 0x1b1540 | Kích thước: 68 bytes
//   0x10ee00: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10ee04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10ee08: 910043FD  add      x29, sp, #0x10
//   0x10ee0c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1897_0x10ee00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ee00ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b1540ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1898 | PC: 0x10ee44 | FDE: 0x1b1578 | Size: 256 bytes
// Khung tháo gỡ #1898 | Địa chỉ PC: 0x10ee44 | Địa chỉ FDE: 0x1b1578 | Kích thước: 256 bytes
//   0x10ee44: B00006A8  adrp     x8, #0x1e3000
//   0x10ee48: F9405100  ldr      x0, [x8, #0xa0]
//   0x10ee4c: D65F03C0  ret      
//   0x10ee50: F81C0FF7  str      x23, [sp, #-0x40]!
static inline uint64_t fde_func_1898_0x10ee44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ee44ULL ^ (static_cast<uint64_t>(0xb00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9405100ULL) ^ 0x1b1578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1899 | PC: 0x10f070 | FDE: 0x1b15b8 | Size: 256 bytes
// Khung tháo gỡ #1899 | Địa chỉ PC: 0x10f070 | Địa chỉ FDE: 0x1b15b8 | Kích thước: 256 bytes
//   0x10f070: D10203FF  sub      sp, sp, #0x80
//   0x10f074: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x10f078: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x10f07c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1899_0x10f070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f070ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x1b15b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1900 | PC: 0x10f670 | FDE: 0x1b1608 | Size: 256 bytes
// Khung tháo gỡ #1900 | Địa chỉ PC: 0x10f670 | Địa chỉ FDE: 0x1b1608 | Kích thước: 256 bytes
//   0x10f670: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10f674: 910003FD  mov      x29, sp
//   0x10f678: 900006A8  adrp     x8, #0x1e3000
//   0x10f67c: 91032108  add      x8, x8, #0xc8
static inline uint64_t fde_func_1900_0x10f670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f670ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1901 | PC: 0x10f7a4 | FDE: 0x1b1648 | Size: 256 bytes
// Khung tháo gỡ #1901 | Địa chỉ PC: 0x10f7a4 | Địa chỉ FDE: 0x1b1648 | Kích thước: 256 bytes
//   0x10f7a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10f7a8: 910003FD  mov      x29, sp
//   0x10f7ac: 900006A8  adrp     x8, #0x1e3000
//   0x10f7b0: 91036108  add      x8, x8, #0xd8
static inline uint64_t fde_func_1901_0x10f7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f7a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1902 | PC: 0x10f8c0 | FDE: 0x1b1688 | Size: 256 bytes
// Khung tháo gỡ #1902 | Địa chỉ PC: 0x10f8c0 | Địa chỉ FDE: 0x1b1688 | Kích thước: 256 bytes
//   0x10f8c0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10f8c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10f8c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10f8cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1902_0x10f8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f8c0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b1688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1903 | PC: 0x10fd94 | FDE: 0x1b16e0 | Size: 200 bytes
// Khung tháo gỡ #1903 | Địa chỉ PC: 0x10fd94 | Địa chỉ FDE: 0x1b16e0 | Kích thước: 200 bytes
//   0x10fd94: D10143FF  sub      sp, sp, #0x50
//   0x10fd98: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10fd9c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10fda0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1903_0x10fd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fd94ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1b16e0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1904 | PC: 0x10fe5c | FDE: 0x1b1720 | Size: 76 bytes
// Khung tháo gỡ #1904 | Địa chỉ PC: 0x10fe5c | Địa chỉ FDE: 0x1b1720 | Kích thước: 76 bytes
//   0x10fe5c: 900006A8  adrp     x8, #0x1e3000
//   0x10fe60: F9404D00  ldr      x0, [x8, #0x98]
//   0x10fe64: D65F03C0  ret      
//   0x10fe68: B40001E1  cbz      x1, #0x10fea4
static inline uint64_t fde_func_1904_0x10fe5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fe5cULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf9404d00ULL) ^ 0x1b1720ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1905 | PC: 0x10fea8 | FDE: 0x1b1778 | Size: 40 bytes
// Khung tháo gỡ #1905 | Địa chỉ PC: 0x10fea8 | Địa chỉ FDE: 0x1b1778 | Kích thước: 40 bytes
//   0x10fea8: D65F03C0  ret      
//   0x10feac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10feb0: 910003FD  mov      x29, sp
//   0x10feb4: 90000001  adrp     x1, #0x10f000
static inline uint64_t fde_func_1905_0x10fea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fea8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1b1778ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1906 | PC: 0x10fed0 | FDE: 0x1b17b0 | Size: 256 bytes
// Khung tháo gỡ #1906 | Địa chỉ PC: 0x10fed0 | Địa chỉ FDE: 0x1b17b0 | Kích thước: 256 bytes
//   0x10fed0: B4000161  cbz      x1, #0x10fefc
//   0x10fed4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10fed8: 910003FD  mov      x29, sp
//   0x10fedc: F9400029  ldr      x9, [x1]
static inline uint64_t fde_func_1906_0x10fed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fed0ULL ^ (static_cast<uint64_t>(0xb4000161ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1b17b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1907 | PC: 0x11014c | FDE: 0x1b1818 | Size: 136 bytes
// Khung tháo gỡ #1907 | Địa chỉ PC: 0x11014c | Địa chỉ FDE: 0x1b1818 | Kích thước: 136 bytes
//   0x11014c: D282080B  mov      x11, #0x1040
//   0x110150: D280800A  mov      x10, #0x400
//   0x110154: F2A1404B  movk     x11, #0xa02, lsl #16
//   0x110158: 90000009  adrp     x9, #0x110000
static inline uint64_t fde_func_1907_0x11014c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11014cULL ^ (static_cast<uint64_t>(0xd282080bULL) << 13);
    acc = (acc + a1 + 0xd280800aULL) ^ 0x1b1818ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1908 | PC: 0x1101d4 | FDE: 0x1b1848 | Size: 256 bytes
// Khung tháo gỡ #1908 | Địa chỉ PC: 0x1101d4 | Địa chỉ FDE: 0x1b1848 | Kích thước: 256 bytes
//   0x1101d4: D10743FF  sub      sp, sp, #0x1d0
//   0x1101d8: A91A57FC  stp      x28, x21, [sp, #0x1a0]
//   0x1101dc: A91B4FF4  stp      x20, x19, [sp, #0x1b0]
//   0x1101e0: A91C7BFD  stp      x29, x30, [sp, #0x1c0]
static inline uint64_t fde_func_1908_0x1101d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1101d4ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa91a57fcULL) ^ 0x1b1848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1909 | PC: 0x110524 | FDE: 0x1b1890 | Size: 256 bytes
// Khung tháo gỡ #1909 | Địa chỉ PC: 0x110524 | Địa chỉ FDE: 0x1b1890 | Kích thước: 256 bytes
//   0x110524: AA1F03E0  mov      x0, xzr
//   0x110528: D65F03C0  ret      
//   0x11052c: D101C3FF  sub      sp, sp, #0x70
//   0x110530: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1909_0x110524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110524ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1b1890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1910 | PC: 0x1108fc | FDE: 0x1b18d0 | Size: 256 bytes
// Khung tháo gỡ #1910 | Địa chỉ PC: 0x1108fc | Địa chỉ FDE: 0x1b18d0 | Kích thước: 256 bytes
//   0x1108fc: D10143FF  sub      sp, sp, #0x50
//   0x110900: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x110904: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x110908: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1910_0x1108fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1108fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1b18d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1911 | PC: 0x110e44 | FDE: 0x1b1920 | Size: 256 bytes
// Khung tháo gỡ #1911 | Địa chỉ PC: 0x110e44 | Địa chỉ FDE: 0x1b1920 | Kích thước: 256 bytes
//   0x110e44: D103C3FF  sub      sp, sp, #0xf0
//   0x110e48: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x110e4c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x110e50: A90E7BFD  stp      x29, x30, [sp, #0xe0]
static inline uint64_t fde_func_1911_0x110e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110e44ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90c57f6ULL) ^ 0x1b1920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1912 | PC: 0x111538 | FDE: 0x1b1998 | Size: 256 bytes
// Khung tháo gỡ #1912 | Địa chỉ PC: 0x111538 | Địa chỉ FDE: 0x1b1998 | Kích thước: 256 bytes
//   0x111538: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11153c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x111540: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x111544: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1912_0x111538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111538ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b1998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1913 | PC: 0x111b70 | FDE: 0x1b19f8 | Size: 232 bytes
// Khung tháo gỡ #1913 | Địa chỉ PC: 0x111b70 | Địa chỉ FDE: 0x1b19f8 | Kích thước: 232 bytes
//   0x111b70: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x111b74: 910003FD  mov      x29, sp
//   0x111b78: D0000688  adrp     x8, #0x1e3000
//   0x111b7c: 910B8108  add      x8, x8, #0x2e0
static inline uint64_t fde_func_1913_0x111b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111b70ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b19f8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1914 | PC: 0x111c58 | FDE: 0x1b1a38 | Size: 240 bytes
// Khung tháo gỡ #1914 | Địa chỉ PC: 0x111c58 | Địa chỉ FDE: 0x1b1a38 | Kích thước: 240 bytes
//   0x111c58: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x111c5c: 910003FD  mov      x29, sp
//   0x111c60: D0000688  adrp     x8, #0x1e3000
//   0x111c64: 910C0108  add      x8, x8, #0x300
static inline uint64_t fde_func_1914_0x111c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111c58ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1915 | PC: 0x111d48 | FDE: 0x1b1a78 | Size: 244 bytes
// Khung tháo gỡ #1915 | Địa chỉ PC: 0x111d48 | Địa chỉ FDE: 0x1b1a78 | Kích thước: 244 bytes
//   0x111d48: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x111d4c: 910003FD  mov      x29, sp
//   0x111d50: D0000688  adrp     x8, #0x1e3000
//   0x111d54: 910C8108  add      x8, x8, #0x320
static inline uint64_t fde_func_1915_0x111d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111d48ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1a78ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1916 | PC: 0x111e3c | FDE: 0x1b1b30 | Size: 256 bytes
// Khung tháo gỡ #1916 | Địa chỉ PC: 0x111e3c | Địa chỉ FDE: 0x1b1b30 | Kích thước: 256 bytes
//   0x111e3c: D102C3FF  sub      sp, sp, #0xb0
//   0x111e40: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x111e44: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x111e48: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_1916_0x111e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111e3cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x1b1b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1917 | PC: 0x112050 | FDE: 0x1b1b78 | Size: 256 bytes
// Khung tháo gỡ #1917 | Địa chỉ PC: 0x112050 | Địa chỉ FDE: 0x1b1b78 | Kích thước: 256 bytes
//   0x112050: D10643FF  sub      sp, sp, #0x190
//   0x112054: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x112058: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x11205c: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_1917_0x112050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112050ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa9136ffcULL) ^ 0x1b1b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1918 | PC: 0x1125a4 | FDE: 0x1b1bc8 | Size: 256 bytes
// Khung tháo gỡ #1918 | Địa chỉ PC: 0x1125a4 | Địa chỉ FDE: 0x1b1bc8 | Kích thước: 256 bytes
//   0x1125a4: D101C3FF  sub      sp, sp, #0x70
//   0x1125a8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1125ac: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1125b0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1918_0x1125a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1125a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x1b1bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1919 | PC: 0x1128b0 | FDE: 0x1b1c10 | Size: 256 bytes
// Khung tháo gỡ #1919 | Địa chỉ PC: 0x1128b0 | Địa chỉ FDE: 0x1b1c10 | Kích thước: 256 bytes
//   0x1128b0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1128b4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1128b8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1128bc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1919_0x1128b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1128b0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b1c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1920 | PC: 0x1131bc | FDE: 0x1b1c60 | Size: 256 bytes
// Khung tháo gỡ #1920 | Địa chỉ PC: 0x1131bc | Địa chỉ FDE: 0x1b1c60 | Kích thước: 256 bytes
//   0x1131bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1131c0: 910003FD  mov      x29, sp
//   0x1131c4: 90000688  adrp     x8, #0x1e3000
//   0x1131c8: 9113E108  add      x8, x8, #0x4f8
static inline uint64_t fde_func_1920_0x1131bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1131bcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1921 | PC: 0x1132d0 | FDE: 0x1b1ca0 | Size: 248 bytes
// Khung tháo gỡ #1921 | Địa chỉ PC: 0x1132d0 | Địa chỉ FDE: 0x1b1ca0 | Kích thước: 248 bytes
//   0x1132d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1132d4: 910003FD  mov      x29, sp
//   0x1132d8: 90000688  adrp     x8, #0x1e3000
//   0x1132dc: 91146108  add      x8, x8, #0x518
static inline uint64_t fde_func_1921_0x1132d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1132d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1ca0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1922 | PC: 0x1133c8 | FDE: 0x1b1ce0 | Size: 256 bytes
// Khung tháo gỡ #1922 | Địa chỉ PC: 0x1133c8 | Địa chỉ FDE: 0x1b1ce0 | Kích thước: 256 bytes
//   0x1133c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1133cc: 910003FD  mov      x29, sp
//   0x1133d0: 90000688  adrp     x8, #0x1e3000
//   0x1133d4: 9114E108  add      x8, x8, #0x538
static inline uint64_t fde_func_1922_0x1133c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1133c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1923 | PC: 0x1134d0 | FDE: 0x1b1d20 | Size: 256 bytes
// Khung tháo gỡ #1923 | Địa chỉ PC: 0x1134d0 | Địa chỉ FDE: 0x1b1d20 | Kích thước: 256 bytes
//   0x1134d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1134d4: 910003FD  mov      x29, sp
//   0x1134d8: 90000688  adrp     x8, #0x1e3000
//   0x1134dc: 91156108  add      x8, x8, #0x558
static inline uint64_t fde_func_1923_0x1134d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1134d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1d20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1924 | PC: 0x1138e8 | FDE: 0x1b1d70 | Size: 236 bytes
// Khung tháo gỡ #1924 | Địa chỉ PC: 0x1138e8 | Địa chỉ FDE: 0x1b1d70 | Kích thước: 236 bytes
//   0x1138e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1138ec: 910003FD  mov      x29, sp
//   0x1138f0: 90000688  adrp     x8, #0x1e3000
//   0x1138f4: 9115A108  add      x8, x8, #0x568
static inline uint64_t fde_func_1924_0x1138e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1138e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1d70ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1925 | PC: 0x1139d4 | FDE: 0x1b1db0 | Size: 256 bytes
// Khung tháo gỡ #1925 | Địa chỉ PC: 0x1139d4 | Địa chỉ FDE: 0x1b1db0 | Kích thước: 256 bytes
//   0x1139d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1139d8: 910003FD  mov      x29, sp
//   0x1139dc: 90000688  adrp     x8, #0x1e3000
//   0x1139e0: 91162108  add      x8, x8, #0x588
static inline uint64_t fde_func_1925_0x1139d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1139d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1926 | PC: 0x114e54 | FDE: 0x1b1e00 | Size: 256 bytes
// Khung tháo gỡ #1926 | Địa chỉ PC: 0x114e54 | Địa chỉ FDE: 0x1b1e00 | Kích thước: 256 bytes
//   0x114e54: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x114e58: 910003FD  mov      x29, sp
//   0x114e5c: F0000668  adrp     x8, #0x1e3000
//   0x114e60: 91166108  add      x8, x8, #0x598
static inline uint64_t fde_func_1926_0x114e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114e54ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1927 | PC: 0x114f60 | FDE: 0x1b1e40 | Size: 252 bytes
// Khung tháo gỡ #1927 | Địa chỉ PC: 0x114f60 | Địa chỉ FDE: 0x1b1e40 | Kích thước: 252 bytes
//   0x114f60: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x114f64: 910003FD  mov      x29, sp
//   0x114f68: F0000668  adrp     x8, #0x1e3000
//   0x114f6c: 9116E108  add      x8, x8, #0x5b8
static inline uint64_t fde_func_1927_0x114f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114f60ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1e40ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1928 | PC: 0x11505c | FDE: 0x1b1e80 | Size: 256 bytes
// Khung tháo gỡ #1928 | Địa chỉ PC: 0x11505c | Địa chỉ FDE: 0x1b1e80 | Kích thước: 256 bytes
//   0x11505c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115060: 910003FD  mov      x29, sp
//   0x115064: D0000668  adrp     x8, #0x1e3000
//   0x115068: 91176108  add      x8, x8, #0x5d8
static inline uint64_t fde_func_1928_0x11505c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11505cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1929 | PC: 0x115168 | FDE: 0x1b1ec0 | Size: 256 bytes
// Khung tháo gỡ #1929 | Địa chỉ PC: 0x115168 | Địa chỉ FDE: 0x1b1ec0 | Kích thước: 256 bytes
//   0x115168: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11516c: 910003FD  mov      x29, sp
//   0x115170: D0000668  adrp     x8, #0x1e3000
//   0x115174: 9117E108  add      x8, x8, #0x5f8
static inline uint64_t fde_func_1929_0x115168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115168ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1930 | PC: 0x115270 | FDE: 0x1b1f00 | Size: 256 bytes
// Khung tháo gỡ #1930 | Địa chỉ PC: 0x115270 | Địa chỉ FDE: 0x1b1f00 | Kích thước: 256 bytes
//   0x115270: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115274: 910003FD  mov      x29, sp
//   0x115278: D0000668  adrp     x8, #0x1e3000
//   0x11527c: 91186108  add      x8, x8, #0x618
static inline uint64_t fde_func_1930_0x115270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115270ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1931 | PC: 0x1153a8 | FDE: 0x1b1f40 | Size: 248 bytes
// Khung tháo gỡ #1931 | Địa chỉ PC: 0x1153a8 | Địa chỉ FDE: 0x1b1f40 | Kích thước: 248 bytes
//   0x1153a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1153ac: 910003FD  mov      x29, sp
//   0x1153b0: D0000668  adrp     x8, #0x1e3000
//   0x1153b4: 9118E108  add      x8, x8, #0x638
static inline uint64_t fde_func_1931_0x1153a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1153a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1f40ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1932 | PC: 0x1154a0 | FDE: 0x1b1f80 | Size: 256 bytes
// Khung tháo gỡ #1932 | Địa chỉ PC: 0x1154a0 | Địa chỉ FDE: 0x1b1f80 | Kích thước: 256 bytes
//   0x1154a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1154a4: 910003FD  mov      x29, sp
//   0x1154a8: D0000668  adrp     x8, #0x1e3000
//   0x1154ac: 91196108  add      x8, x8, #0x658
static inline uint64_t fde_func_1932_0x1154a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1154a0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1933 | PC: 0x115d98 | FDE: 0x1b1fd0 | Size: 252 bytes
// Khung tháo gỡ #1933 | Địa chỉ PC: 0x115d98 | Địa chỉ FDE: 0x1b1fd0 | Kích thước: 252 bytes
//   0x115d98: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115d9c: 910003FD  mov      x29, sp
//   0x115da0: D0000668  adrp     x8, #0x1e3000
//   0x115da4: 9119A108  add      x8, x8, #0x668
static inline uint64_t fde_func_1933_0x115d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115d98ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b1fd0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1934 | PC: 0x115e94 | FDE: 0x1b2010 | Size: 252 bytes
// Khung tháo gỡ #1934 | Địa chỉ PC: 0x115e94 | Địa chỉ FDE: 0x1b2010 | Kích thước: 252 bytes
//   0x115e94: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115e98: 910003FD  mov      x29, sp
//   0x115e9c: D0000668  adrp     x8, #0x1e3000
//   0x115ea0: 911A2108  add      x8, x8, #0x688
static inline uint64_t fde_func_1934_0x115e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e94ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2010ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1935 | PC: 0x115f90 | FDE: 0x1b2050 | Size: 256 bytes
// Khung tháo gỡ #1935 | Địa chỉ PC: 0x115f90 | Địa chỉ FDE: 0x1b2050 | Kích thước: 256 bytes
//   0x115f90: D102C3FF  sub      sp, sp, #0xb0
//   0x115f94: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x115f98: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x115f9c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1935_0x115f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115f90ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x1b2050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1936 | PC: 0x116608 | FDE: 0x1b20a0 | Size: 256 bytes
// Khung tháo gỡ #1936 | Địa chỉ PC: 0x116608 | Địa chỉ FDE: 0x1b20a0 | Kích thước: 256 bytes
//   0x116608: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11660c: 910003FD  mov      x29, sp
//   0x116610: B0000668  adrp     x8, #0x1e3000
//   0x116614: 911AE108  add      x8, x8, #0x6b8
static inline uint64_t fde_func_1936_0x116608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116608ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b20a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1937 | PC: 0x116ae8 | FDE: 0x1b20e8 | Size: 256 bytes
// Khung tháo gỡ #1937 | Địa chỉ PC: 0x116ae8 | Địa chỉ FDE: 0x1b20e8 | Kích thước: 256 bytes
//   0x116ae8: D10203FF  sub      sp, sp, #0x80
//   0x116aec: F90013FB  str      x27, [sp, #0x20]
//   0x116af0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x116af4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1937_0x116ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116ae8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1b20e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1938 | PC: 0x116f58 | FDE: 0x1b2138 | Size: 256 bytes
// Khung tháo gỡ #1938 | Địa chỉ PC: 0x116f58 | Địa chỉ FDE: 0x1b2138 | Kích thước: 256 bytes
//   0x116f58: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x116f5c: 910003FD  mov      x29, sp
//   0x116f60: B0000668  adrp     x8, #0x1e3000
//   0x116f64: 911C6108  add      x8, x8, #0x718
static inline uint64_t fde_func_1938_0x116f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116f58ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1939 | PC: 0x11705c | FDE: 0x1b2178 | Size: 256 bytes
// Khung tháo gỡ #1939 | Địa chỉ PC: 0x11705c | Địa chỉ FDE: 0x1b2178 | Kích thước: 256 bytes
//   0x11705c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x117060: 910003FD  mov      x29, sp
//   0x117064: 90000668  adrp     x8, #0x1e3000
//   0x117068: 911CE108  add      x8, x8, #0x738
static inline uint64_t fde_func_1939_0x11705c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11705cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1940 | PC: 0x11717c | FDE: 0x1b21b8 | Size: 252 bytes
// Khung tháo gỡ #1940 | Địa chỉ PC: 0x11717c | Địa chỉ FDE: 0x1b21b8 | Kích thước: 252 bytes
//   0x11717c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x117180: 910003FD  mov      x29, sp
//   0x117184: 90000668  adrp     x8, #0x1e3000
//   0x117188: 911D6108  add      x8, x8, #0x758
static inline uint64_t fde_func_1940_0x11717c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11717cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b21b8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1941 | PC: 0x117278 | FDE: 0x1b21f8 | Size: 256 bytes
// Khung tháo gỡ #1941 | Địa chỉ PC: 0x117278 | Địa chỉ FDE: 0x1b21f8 | Kích thước: 256 bytes
//   0x117278: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11727c: 910003FD  mov      x29, sp
//   0x117280: 90000668  adrp     x8, #0x1e3000
//   0x117284: 911DE108  add      x8, x8, #0x778
static inline uint64_t fde_func_1941_0x117278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117278ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b21f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1942 | PC: 0x117598 | FDE: 0x1b2248 | Size: 256 bytes
// Khung tháo gỡ #1942 | Địa chỉ PC: 0x117598 | Địa chỉ FDE: 0x1b2248 | Kích thước: 256 bytes
//   0x117598: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11759c: 910003FD  mov      x29, sp
//   0x1175a0: 90000668  adrp     x8, #0x1e3000
//   0x1175a4: 911E2108  add      x8, x8, #0x788
static inline uint64_t fde_func_1942_0x117598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117598ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1943 | PC: 0x1176a4 | FDE: 0x1b2288 | Size: 256 bytes
// Khung tháo gỡ #1943 | Địa chỉ PC: 0x1176a4 | Địa chỉ FDE: 0x1b2288 | Kích thước: 256 bytes
//   0x1176a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1176a8: 910003FD  mov      x29, sp
//   0x1176ac: 90000668  adrp     x8, #0x1e3000
//   0x1176b0: 911EA108  add      x8, x8, #0x7a8
static inline uint64_t fde_func_1943_0x1176a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1176a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1944 | PC: 0x1177ac | FDE: 0x1b22c8 | Size: 256 bytes
// Khung tháo gỡ #1944 | Địa chỉ PC: 0x1177ac | Địa chỉ FDE: 0x1b22c8 | Kích thước: 256 bytes
//   0x1177ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1177b0: 910003FD  mov      x29, sp
//   0x1177b4: 90000668  adrp     x8, #0x1e3000
//   0x1177b8: 911F2108  add      x8, x8, #0x7c8
static inline uint64_t fde_func_1944_0x1177ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1177acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b22c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1945 | PC: 0x1178c4 | FDE: 0x1b2308 | Size: 256 bytes
// Khung tháo gỡ #1945 | Địa chỉ PC: 0x1178c4 | Địa chỉ FDE: 0x1b2308 | Kích thước: 256 bytes
//   0x1178c4: D10243FF  sub      sp, sp, #0x90
//   0x1178c8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x1178cc: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x1178d0: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_1945_0x1178c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1178c4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x1b2308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1946 | PC: 0x117ec8 | FDE: 0x1b2358 | Size: 256 bytes
// Khung tháo gỡ #1946 | Địa chỉ PC: 0x117ec8 | Địa chỉ FDE: 0x1b2358 | Kích thước: 256 bytes
//   0x117ec8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x117ecc: 910003FD  mov      x29, sp
//   0x117ed0: 90000668  adrp     x8, #0x1e3000
//   0x117ed4: 91202108  add      x8, x8, #0x808
static inline uint64_t fde_func_1946_0x117ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117ec8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1947 | PC: 0x117fcc | FDE: 0x1b2398 | Size: 256 bytes
// Khung tháo gỡ #1947 | Địa chỉ PC: 0x117fcc | Địa chỉ FDE: 0x1b2398 | Kích thước: 256 bytes
//   0x117fcc: D10503FF  sub      sp, sp, #0x140
//   0x117fd0: F9007BFC  str      x28, [sp, #0xf0]
//   0x117fd4: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x117fd8: A91157F6  stp      x22, x21, [sp, #0x110]
static inline uint64_t fde_func_1947_0x117fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117fccULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x1b2398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1948 | PC: 0x11845c | FDE: 0x1b23d8 | Size: 60 bytes
// Khung tháo gỡ #1948 | Địa chỉ PC: 0x11845c | Địa chỉ FDE: 0x1b23d8 | Kích thước: 60 bytes
//   0x11845c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118460: 910003FD  mov      x29, sp
//   0x118464: 97FC570B  bl       #0x2e090
//   0x118468: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_1948_0x11845c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11845cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b23d8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1949 | PC: 0x118498 | FDE: 0x1b2418 | Size: 256 bytes
// Khung tháo gỡ #1949 | Địa chỉ PC: 0x118498 | Địa chỉ FDE: 0x1b2418 | Kích thước: 256 bytes
//   0x118498: D10283FF  sub      sp, sp, #0xa0
//   0x11849c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1184a0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1184a4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1949_0x118498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118498ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1b2418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1950 | PC: 0x118aac | FDE: 0x1b2468 | Size: 256 bytes
// Khung tháo gỡ #1950 | Địa chỉ PC: 0x118aac | Địa chỉ FDE: 0x1b2468 | Kích thước: 256 bytes
//   0x118aac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118ab0: 910003FD  mov      x29, sp
//   0x118ab4: F0000648  adrp     x8, #0x1e3000
//   0x118ab8: 91264108  add      x8, x8, #0x990
static inline uint64_t fde_func_1950_0x118aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118aacULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1951 | PC: 0x118bb8 | FDE: 0x1b24a8 | Size: 256 bytes
// Khung tháo gỡ #1951 | Địa chỉ PC: 0x118bb8 | Địa chỉ FDE: 0x1b24a8 | Kích thước: 256 bytes
//   0x118bb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118bbc: 910003FD  mov      x29, sp
//   0x118bc0: F0000648  adrp     x8, #0x1e3000
//   0x118bc4: 9126C108  add      x8, x8, #0x9b0
static inline uint64_t fde_func_1951_0x118bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118bb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b24a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1952 | PC: 0x118cc8 | FDE: 0x1b24e8 | Size: 256 bytes
// Khung tháo gỡ #1952 | Địa chỉ PC: 0x118cc8 | Địa chỉ FDE: 0x1b24e8 | Kích thước: 256 bytes
//   0x118cc8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118ccc: 910003FD  mov      x29, sp
//   0x118cd0: F0000648  adrp     x8, #0x1e3000
//   0x118cd4: 91274108  add      x8, x8, #0x9d0
static inline uint64_t fde_func_1952_0x118cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118cc8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b24e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1953 | PC: 0x118dd4 | FDE: 0x1b2528 | Size: 256 bytes
// Khung tháo gỡ #1953 | Địa chỉ PC: 0x118dd4 | Địa chỉ FDE: 0x1b2528 | Kích thước: 256 bytes
//   0x118dd4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118dd8: 910003FD  mov      x29, sp
//   0x118ddc: F0000648  adrp     x8, #0x1e3000
//   0x118de0: 9127C108  add      x8, x8, #0x9f0
static inline uint64_t fde_func_1953_0x118dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118dd4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1954 | PC: 0x118eec | FDE: 0x1b2568 | Size: 240 bytes
// Khung tháo gỡ #1954 | Địa chỉ PC: 0x118eec | Địa chỉ FDE: 0x1b2568 | Kích thước: 240 bytes
//   0x118eec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118ef0: 910003FD  mov      x29, sp
//   0x118ef4: F0000648  adrp     x8, #0x1e3000
//   0x118ef8: 91284108  add      x8, x8, #0xa10
static inline uint64_t fde_func_1954_0x118eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118eecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2568ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1955 | PC: 0x118fdc | FDE: 0x1b25a8 | Size: 232 bytes
// Khung tháo gỡ #1955 | Địa chỉ PC: 0x118fdc | Địa chỉ FDE: 0x1b25a8 | Kích thước: 232 bytes
//   0x118fdc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x118fe0: 910003FD  mov      x29, sp
//   0x118fe4: F0000648  adrp     x8, #0x1e3000
//   0x118fe8: 9128C108  add      x8, x8, #0xa30
static inline uint64_t fde_func_1955_0x118fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118fdcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b25a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1956 | PC: 0x1190c4 | FDE: 0x1b2608 | Size: 204 bytes
// Khung tháo gỡ #1956 | Địa chỉ PC: 0x1190c4 | Địa chỉ FDE: 0x1b2608 | Kích thước: 204 bytes
//   0x1190c4: AA1E03E4  mov      x4, x30
//   0x1190c8: 8B000084  add      x4, x4, x0
//   0x1190cc: AA0403FE  mov      x30, x4
//   0x1190d0: D65F03C0  ret      
static inline uint64_t fde_func_1956_0x1190c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1190c4ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x8b000084ULL) ^ 0x1b2608ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1957 | PC: 0x119190 | FDE: 0x1b2648 | Size: 256 bytes
// Khung tháo gỡ #1957 | Địa chỉ PC: 0x119190 | Địa chỉ FDE: 0x1b2648 | Kích thước: 256 bytes
//   0x119190: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x119194: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x119198: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11919c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1957_0x119190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119190ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1b2648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1958 | PC: 0x119fa8 | FDE: 0x1b26a8 | Size: 256 bytes
// Khung tháo gỡ #1958 | Địa chỉ PC: 0x119fa8 | Địa chỉ FDE: 0x1b26a8 | Kích thước: 256 bytes
//   0x119fa8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x119fac: 910003FD  mov      x29, sp
//   0x119fb0: D0000648  adrp     x8, #0x1e3000
//   0x119fb4: 9129C108  add      x8, x8, #0xa70
static inline uint64_t fde_func_1958_0x119fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119fa8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b26a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1959 | PC: 0x11a0c4 | FDE: 0x1b26f0 | Size: 256 bytes
// Khung tháo gỡ #1959 | Địa chỉ PC: 0x11a0c4 | Địa chỉ FDE: 0x1b26f0 | Kích thước: 256 bytes
//   0x11a0c4: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x11a0c8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11a0cc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11a0d0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1959_0x11a0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a0c4ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b26f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1960 | PC: 0x11a36c | FDE: 0x1b2740 | Size: 256 bytes
// Khung tháo gỡ #1960 | Địa chỉ PC: 0x11a36c | Địa chỉ FDE: 0x1b2740 | Kích thước: 256 bytes
//   0x11a36c: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x11a370: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11a374: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11a378: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1960_0x11a36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a36cULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b2740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1961 | PC: 0x11a570 | FDE: 0x1b27a0 | Size: 256 bytes
// Khung tháo gỡ #1961 | Địa chỉ PC: 0x11a570 | Địa chỉ FDE: 0x1b27a0 | Kích thước: 256 bytes
//   0x11a570: D10303FF  sub      sp, sp, #0xc0
//   0x11a574: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x11a578: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x11a57c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1961_0x11a570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a570ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1b27a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1962 | PC: 0x11b088 | FDE: 0x1b27f8 | Size: 256 bytes
// Khung tháo gỡ #1962 | Địa chỉ PC: 0x11b088 | Địa chỉ FDE: 0x1b27f8 | Kích thước: 256 bytes
//   0x11b088: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11b08c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11b090: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11b094: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1962_0x11b088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b088ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b27f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1963 | PC: 0x11b32c | FDE: 0x1b2838 | Size: 256 bytes
// Khung tháo gỡ #1963 | Địa chỉ PC: 0x11b32c | Địa chỉ FDE: 0x1b2838 | Kích thước: 256 bytes
//   0x11b32c: F00005E8  adrp     x8, #0x1da000
//   0x11b330: B94E2900  ldr      w0, [x8, #0xe28]
//   0x11b334: D65F03C0  ret      
//   0x11b338: D102C3FF  sub      sp, sp, #0xb0
static inline uint64_t fde_func_1963_0x11b32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b32cULL ^ (static_cast<uint64_t>(0xf00005e8ULL) << 13);
    acc = (acc + a1 + 0xb94e2900ULL) ^ 0x1b2838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1964 | PC: 0x11b8c0 | FDE: 0x1b2898 | Size: 256 bytes
// Khung tháo gỡ #1964 | Địa chỉ PC: 0x11b8c0 | Địa chỉ FDE: 0x1b2898 | Kích thước: 256 bytes
//   0x11b8c0: 2A1F03E0  mov      w0, wzr
//   0x11b8c4: B40001C1  cbz      x1, #0x11b8fc
//   0x11b8c8: F00005E8  adrp     x8, #0x1da000
//   0x11b8cc: B94E3908  ldr      w8, [x8, #0xe38]
static inline uint64_t fde_func_1964_0x11b8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b8c0ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb40001c1ULL) ^ 0x1b2898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1965 | PC: 0x11ba14 | FDE: 0x1b28e8 | Size: 256 bytes
// Khung tháo gỡ #1965 | Địa chỉ PC: 0x11ba14 | Địa chỉ FDE: 0x1b28e8 | Kích thước: 256 bytes
//   0x11ba14: 7103FC1F  cmp      w0, #0xff
//   0x11ba18: 54000240  b.eq     #0x11ba60
//   0x11ba1c: 7100041F  cmp      w0, #1
//   0x11ba20: 54000201  b.ne     #0x11ba60
static inline uint64_t fde_func_1965_0x11ba14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ba14ULL ^ (static_cast<uint64_t>(0x7103fc1fULL) << 13);
    acc = (acc + a1 + 0x54000240ULL) ^ 0x1b28e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1966 | PC: 0x11bbe0 | FDE: 0x1b2930 | Size: 252 bytes
// Khung tháo gỡ #1966 | Địa chỉ PC: 0x11bbe0 | Địa chỉ FDE: 0x1b2930 | Kích thước: 252 bytes
//   0x11bbe0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11bbe4: 910003FD  mov      x29, sp
//   0x11bbe8: 90000648  adrp     x8, #0x1e3000
//   0x11bbec: 91328108  add      x8, x8, #0xca0
static inline uint64_t fde_func_1966_0x11bbe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11bbe0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2930ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1967 | PC: 0x11bcdc | FDE: 0x1b2970 | Size: 256 bytes
// Khung tháo gỡ #1967 | Địa chỉ PC: 0x11bcdc | Địa chỉ FDE: 0x1b2970 | Kích thước: 256 bytes
//   0x11bcdc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11bce0: 910003FD  mov      x29, sp
//   0x11bce4: 90000648  adrp     x8, #0x1e3000
//   0x11bce8: 91330108  add      x8, x8, #0xcc0
static inline uint64_t fde_func_1967_0x11bcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11bcdcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1968 | PC: 0x11c2f8 | FDE: 0x1b29b8 | Size: 256 bytes
// Khung tháo gỡ #1968 | Địa chỉ PC: 0x11c2f8 | Địa chỉ FDE: 0x1b29b8 | Kích thước: 256 bytes
//   0x11c2f8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11c2fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11c300: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11c304: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1968_0x11c2f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c2f8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b29b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1969 | PC: 0x11ca94 | FDE: 0x1b2a30 | Size: 256 bytes
// Khung tháo gỡ #1969 | Địa chỉ PC: 0x11ca94 | Địa chỉ FDE: 0x1b2a30 | Kích thước: 256 bytes
//   0x11ca94: D10203FF  sub      sp, sp, #0x80
//   0x11ca98: F9002BF5  str      x21, [sp, #0x50]
//   0x11ca9c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x11caa0: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1969_0x11ca94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ca94ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1b2a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1970 | PC: 0x11cdec | FDE: 0x1b2a70 | Size: 20 bytes
// Khung tháo gỡ #1970 | Địa chỉ PC: 0x11cdec | Địa chỉ FDE: 0x1b2a70 | Kích thước: 20 bytes
//   0x11cdec: F00005E0  adrp     x0, #0x1db000
//   0x11cdf0: 911F4000  add      x0, x0, #0x7d0
//   0x11cdf4: D65F03C0  ret      
//   0x11cdf8: F9000001  str      x1, [x0]
static inline uint64_t fde_func_1970_0x11cdec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11cdecULL ^ (static_cast<uint64_t>(0xf00005e0ULL) << 13);
    acc = (acc + a1 + 0x911f4000ULL) ^ 0x1b2a70ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1971 | PC: 0x11ce00 | FDE: 0x1b2aa0 | Size: 256 bytes
// Khung tháo gỡ #1971 | Địa chỉ PC: 0x11ce00 | Địa chỉ FDE: 0x1b2aa0 | Kích thước: 256 bytes
//   0x11ce00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11ce04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11ce08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11ce0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1971_0x11ce00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ce00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b2aa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1972 | PC: 0x11d308 | FDE: 0x1b2af0 | Size: 256 bytes
// Khung tháo gỡ #1972 | Địa chỉ PC: 0x11d308 | Địa chỉ FDE: 0x1b2af0 | Kích thước: 256 bytes
//   0x11d308: D10303FF  sub      sp, sp, #0xc0
//   0x11d30c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x11d310: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x11d314: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1972_0x11d308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d308ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x1b2af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1973 | PC: 0x11d884 | FDE: 0x1b2b30 | Size: 256 bytes
// Khung tháo gỡ #1973 | Địa chỉ PC: 0x11d884 | Địa chỉ FDE: 0x1b2b30 | Kích thước: 256 bytes
//   0x11d884: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11d888: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11d88c: 910043FD  add      x29, sp, #0x10
//   0x11d890: 94013171  bl       #0x169e54
static inline uint64_t fde_func_1973_0x11d884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d884ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1974 | PC: 0x11d9d8 | FDE: 0x1b2b98 | Size: 56 bytes
// Khung tháo gỡ #1974 | Địa chỉ PC: 0x11d9d8 | Địa chỉ FDE: 0x1b2b98 | Kích thước: 56 bytes
//   0x11d9d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11d9dc: F9400008  ldr      x8, [x0]
//   0x11d9e0: AA0003F3  mov      x19, x0
//   0x11d9e4: D63F0100  blr      x8
static inline uint64_t fde_func_1974_0x11d9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d9d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1b2b98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1975 | PC: 0x11da10 | FDE: 0x1b2bc8 | Size: 28 bytes
// Khung tháo gỡ #1975 | Địa chỉ PC: 0x11da10 | Địa chỉ FDE: 0x1b2bc8 | Kích thước: 28 bytes
//   0x11da10: A9402002  ldp      x2, x8, [x0]
//   0x11da14: F9400801  ldr      x1, [x0, #0x10]
//   0x11da18: AA0803E0  mov      x0, x8
//   0x11da1c: D61F0040  br       x2
static inline uint64_t fde_func_1975_0x11da10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11da10ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1b2bc8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1976 | PC: 0x11da2c | FDE: 0x1b2bf8 | Size: 256 bytes
// Khung tháo gỡ #1976 | Địa chỉ PC: 0x11da2c | Địa chỉ FDE: 0x1b2bf8 | Kích thước: 256 bytes
//   0x11da2c: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x11da30: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11da34: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11da38: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1976_0x11da2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11da2cULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b2bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1977 | PC: 0x11dd7c | FDE: 0x1b2c48 | Size: 256 bytes
// Khung tháo gỡ #1977 | Địa chỉ PC: 0x11dd7c | Địa chỉ FDE: 0x1b2c48 | Kích thước: 256 bytes
//   0x11dd7c: 79407009  ldrh     w9, [x0, #0x38]
//   0x11dd80: B4000169  cbz      x9, #0x11ddac
//   0x11dd84: F9401008  ldr      x8, [x0, #0x20]
//   0x11dd88: 5280070A  mov      w10, #0x38
static inline uint64_t fde_func_1977_0x11dd7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dd7cULL ^ (static_cast<uint64_t>(0x79407009ULL) << 13);
    acc = (acc + a1 + 0xb4000169ULL) ^ 0x1b2c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1978 | PC: 0x11df44 | FDE: 0x1b2c88 | Size: 256 bytes
// Khung tháo gỡ #1978 | Địa chỉ PC: 0x11df44 | Địa chỉ FDE: 0x1b2c88 | Kích thước: 256 bytes
//   0x11df44: D10283FF  sub      sp, sp, #0xa0
//   0x11df48: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x11df4c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x11df50: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1978_0x11df44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11df44ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1b2c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1979 | PC: 0x11ec64 | FDE: 0x1b2d08 | Size: 256 bytes
// Khung tháo gỡ #1979 | Địa chỉ PC: 0x11ec64 | Địa chỉ FDE: 0x1b2d08 | Kích thước: 256 bytes
//   0x11ec64: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x11ec68: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11ec6c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11ec70: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1979_0x11ec64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ec64ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b2d08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1980 | PC: 0x11ed68 | FDE: 0x1b2d70 | Size: 256 bytes
// Khung tháo gỡ #1980 | Địa chỉ PC: 0x11ed68 | Địa chỉ FDE: 0x1b2d70 | Kích thước: 256 bytes
//   0x11ed68: 52801FE8  mov      w8, #0xff
//   0x11ed6c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11ed70: A900FC01  stp      x1, xzr, [x0, #8]
//   0x11ed74: B900181F  str      wzr, [x0, #0x18]
static inline uint64_t fde_func_1980_0x11ed68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ed68ULL ^ (static_cast<uint64_t>(0x52801fe8ULL) << 13);
    acc = (acc + a1 + 0x6f00e400ULL) ^ 0x1b2d70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1981 | PC: 0x11f038 | FDE: 0x1b2db0 | Size: 256 bytes
// Khung tháo gỡ #1981 | Địa chỉ PC: 0x11f038 | Địa chỉ FDE: 0x1b2db0 | Kích thước: 256 bytes
//   0x11f038: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11f03c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11f040: 910043FD  add      x29, sp, #0x10
//   0x11f044: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1981_0x11f038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f038ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1982 | PC: 0x11f1b4 | FDE: 0x1b2df0 | Size: 244 bytes
// Khung tháo gỡ #1982 | Địa chỉ PC: 0x11f1b4 | Địa chỉ FDE: 0x1b2df0 | Kích thước: 244 bytes
//   0x11f1b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11f1b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11f1bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11f1c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1982_0x11f1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f1b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b2df0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1983 | PC: 0x11f2a8 | FDE: 0x1b2e30 | Size: 256 bytes
// Khung tháo gỡ #1983 | Địa chỉ PC: 0x11f2a8 | Địa chỉ FDE: 0x1b2e30 | Kích thước: 256 bytes
//   0x11f2a8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11f2ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11f2b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11f2b4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1983_0x11f2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f2a8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b2e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1984 | PC: 0x11f62c | FDE: 0x1b2e80 | Size: 256 bytes
// Khung tháo gỡ #1984 | Địa chỉ PC: 0x11f62c | Địa chỉ FDE: 0x1b2e80 | Kích thước: 256 bytes
//   0x11f62c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11f630: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11f634: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11f638: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1984_0x11f62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f62cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1b2e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1985 | PC: 0x11f8e8 | FDE: 0x1b2ed8 | Size: 232 bytes
// Khung tháo gỡ #1985 | Địa chỉ PC: 0x11f8e8 | Địa chỉ FDE: 0x1b2ed8 | Kích thước: 232 bytes
//   0x11f8e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11f8ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11f8f0: 910043FD  add      x29, sp, #0x10
//   0x11f8f4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1985_0x11f8e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f8e8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2ed8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1986 | PC: 0x11f9d0 | FDE: 0x1b2f30 | Size: 256 bytes
// Khung tháo gỡ #1986 | Địa chỉ PC: 0x11f9d0 | Địa chỉ FDE: 0x1b2f30 | Kích thước: 256 bytes
//   0x11f9d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11f9d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11f9d8: 910043FD  add      x29, sp, #0x10
//   0x11f9dc: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1986_0x11f9d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f9d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1987 | PC: 0x11fbb4 | FDE: 0x1b2f70 | Size: 256 bytes
// Khung tháo gỡ #1987 | Địa chỉ PC: 0x11fbb4 | Địa chỉ FDE: 0x1b2f70 | Kích thước: 256 bytes
//   0x11fbb4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11fbb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11fbbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11fbc0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1987_0x11fbb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fbb4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b2f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1988 | PC: 0x11fd8c | FDE: 0x1b2fb0 | Size: 256 bytes
// Khung tháo gỡ #1988 | Địa chỉ PC: 0x11fd8c | Địa chỉ FDE: 0x1b2fb0 | Kích thước: 256 bytes
//   0x11fd8c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11fd90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11fd94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11fd98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1988_0x11fd8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fd8cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1b2fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1989 | PC: 0x1200f4 | FDE: 0x1b2fe8 | Size: 256 bytes
// Khung tháo gỡ #1989 | Địa chỉ PC: 0x1200f4 | Địa chỉ FDE: 0x1b2fe8 | Kích thước: 256 bytes
//   0x1200f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1200f8: 910003FD  mov      x29, sp
//   0x1200fc: 3940E009  ldrb     w9, [x0, #0x38]
//   0x120100: 34000169  cbz      w9, #0x12012c
static inline uint64_t fde_func_1989_0x1200f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1200f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1b2fe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1990 | PC: 0x1202f4 | FDE: 0x1b3038 | Size: 256 bytes
// Khung tháo gỡ #1990 | Địa chỉ PC: 0x1202f4 | Địa chỉ FDE: 0x1b3038 | Kích thước: 256 bytes
//   0x1202f4: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x1202f8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1202fc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x120300: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1990_0x1202f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1202f4ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1b3038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1991 | PC: 0x120514 | FDE: 0x1b3080 | Size: 256 bytes
// Khung tháo gỡ #1991 | Địa chỉ PC: 0x120514 | Địa chỉ FDE: 0x1b3080 | Kích thước: 256 bytes
//   0x120514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x120518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12051c: 910043FD  add      x29, sp, #0x10
//   0x120520: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1991_0x120514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120514ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b3080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1992 | PC: 0x120630 | FDE: 0x1b30e0 | Size: 256 bytes
// Khung tháo gỡ #1992 | Địa chỉ PC: 0x120630 | Địa chỉ FDE: 0x1b30e0 | Kích thước: 256 bytes
//   0x120630: D10103FF  sub      sp, sp, #0x40
//   0x120634: F90013F3  str      x19, [sp, #0x20]
//   0x120638: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x12063c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1992_0x120630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120630ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1b30e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1993 | PC: 0x120798 | FDE: 0x1b3120 | Size: 256 bytes
// Khung tháo gỡ #1993 | Địa chỉ PC: 0x120798 | Địa chỉ FDE: 0x1b3120 | Kích thước: 256 bytes
//   0x120798: D10103FF  sub      sp, sp, #0x40
//   0x12079c: F90013F3  str      x19, [sp, #0x20]
//   0x1207a0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1207a4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1993_0x120798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120798ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1b3120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1994 | PC: 0x120bbc | FDE: 0x1b3160 | Size: 256 bytes
// Khung tháo gỡ #1994 | Địa chỉ PC: 0x120bbc | Địa chỉ FDE: 0x1b3160 | Kích thước: 256 bytes
//   0x120bbc: D101C3FF  sub      sp, sp, #0x70
//   0x120bc0: F9001BF7  str      x23, [sp, #0x30]
//   0x120bc4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x120bc8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1994_0x120bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120bbcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1b3160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1995 | PC: 0x12121c | FDE: 0x1b31c8 | Size: 88 bytes
// Khung tháo gỡ #1995 | Địa chỉ PC: 0x12121c | Địa chỉ FDE: 0x1b31c8 | Kích thước: 88 bytes
//   0x12121c: AA1E03E5  mov      x5, x30
//   0x121220: 8B0000A5  add      x5, x5, x0
//   0x121224: AA0503FE  mov      x30, x5
//   0x121228: D65F03C0  ret      
static inline uint64_t fde_func_1995_0x12121c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12121cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x8b0000a5ULL) ^ 0x1b31c8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1996 | PC: 0x121274 | FDE: 0x1b3200 | Size: 108 bytes
// Khung tháo gỡ #1996 | Địa chỉ PC: 0x121274 | Địa chỉ FDE: 0x1b3200 | Kích thước: 108 bytes
//   0x121274: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x121278: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12127c: 910043FD  add      x29, sp, #0x10
//   0x121280: F0000528  adrp     x8, #0x1c8000
static inline uint64_t fde_func_1996_0x121274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121274ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b3200ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1997 | PC: 0x1212e0 | FDE: 0x1b3240 | Size: 44 bytes
// Khung tháo gỡ #1997 | Địa chỉ PC: 0x1212e0 | Địa chỉ FDE: 0x1b3240 | Kích thước: 44 bytes
//   0x1212e0: F0000528  adrp     x8, #0x1c8000
//   0x1212e4: 9133E108  add      x8, x8, #0xcf8
//   0x1212e8: F9000008  str      x8, [x0]
//   0x1212ec: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_1997_0x1212e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1212e0ULL ^ (static_cast<uint64_t>(0xf0000528ULL) << 13);
    acc = (acc + a1 + 0x9133e108ULL) ^ 0x1b3240ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1998 | PC: 0x12130c | FDE: 0x1b3270 | Size: 104 bytes
// Khung tháo gỡ #1998 | Địa chỉ PC: 0x12130c | Địa chỉ FDE: 0x1b3270 | Kích thước: 104 bytes
//   0x12130c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x121310: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x121314: 910043FD  add      x29, sp, #0x10
//   0x121318: F0000528  adrp     x8, #0x1c8000
static inline uint64_t fde_func_1998_0x12130c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12130cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b3270ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1999 | PC: 0x121374 | FDE: 0x1b32b0 | Size: 256 bytes
// Khung tháo gỡ #1999 | Địa chỉ PC: 0x121374 | Địa chỉ FDE: 0x1b32b0 | Kích thước: 256 bytes
//   0x121374: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x121378: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12137c: 910043FD  add      x29, sp, #0x10
//   0x121380: F0000528  adrp     x8, #0x1c8000
static inline uint64_t fde_func_1999_0x121374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121374ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b32b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1600: return fde_func_1600_0x0ef0fc(a0, a1);
        case 1601: return fde_func_1601_0x0ef11c(a0, a1);
        case 1602: return fde_func_1602_0x0ef13c(a0, a1);
        case 1603: return fde_func_1603_0x0ef15c(a0, a1);
        case 1604: return fde_func_1604_0x0ef174(a0, a1);
        case 1605: return fde_func_1605_0x0ef18c(a0, a1);
        case 1606: return fde_func_1606_0x0ef19c(a0, a1);
        case 1607: return fde_func_1607_0x0ef1ac(a0, a1);
        case 1608: return fde_func_1608_0x0ef1bc(a0, a1);
        case 1609: return fde_func_1609_0x0ef1cc(a0, a1);
        case 1610: return fde_func_1610_0x0ef1dc(a0, a1);
        case 1611: return fde_func_1611_0x0ef1f0(a0, a1);
        case 1612: return fde_func_1612_0x0ef204(a0, a1);
        case 1613: return fde_func_1613_0x0ef214(a0, a1);
        case 1614: return fde_func_1614_0x0ef224(a0, a1);
        case 1615: return fde_func_1615_0x0ef234(a0, a1);
        case 1616: return fde_func_1616_0x0ef244(a0, a1);
        case 1617: return fde_func_1617_0x0ef254(a0, a1);
        case 1618: return fde_func_1618_0x0ef264(a0, a1);
        case 1619: return fde_func_1619_0x0ef274(a0, a1);
        case 1620: return fde_func_1620_0x0ef284(a0, a1);
        case 1621: return fde_func_1621_0x0ef294(a0, a1);
        case 1622: return fde_func_1622_0x0ef2a4(a0, a1);
        case 1623: return fde_func_1623_0x0ef2b4(a0, a1);
        case 1624: return fde_func_1624_0x0ef2cc(a0, a1);
        case 1625: return fde_func_1625_0x0ef2e0(a0, a1);
        case 1626: return fde_func_1626_0x0ef330(a0, a1);
        case 1627: return fde_func_1627_0x0ef3c0(a0, a1);
        case 1628: return fde_func_1628_0x0ef404(a0, a1);
        case 1629: return fde_func_1629_0x0ef498(a0, a1);
        case 1630: return fde_func_1630_0x0ef650(a0, a1);
        case 1631: return fde_func_1631_0x0ef6a0(a0, a1);
        case 1632: return fde_func_1632_0x0ef6b8(a0, a1);
        case 1633: return fde_func_1633_0x0ef6d0(a0, a1);
        case 1634: return fde_func_1634_0x0ef6ec(a0, a1);
        case 1635: return fde_func_1635_0x0ef704(a0, a1);
        case 1636: return fde_func_1636_0x0ef71c(a0, a1);
        case 1637: return fde_func_1637_0x0ef730(a0, a1);
        case 1638: return fde_func_1638_0x0ef740(a0, a1);
        case 1639: return fde_func_1639_0x0ef74c(a0, a1);
        case 1640: return fde_func_1640_0x0ef758(a0, a1);
        case 1641: return fde_func_1641_0x0ef764(a0, a1);
        case 1642: return fde_func_1642_0x0ef774(a0, a1);
        case 1643: return fde_func_1643_0x0ef784(a0, a1);
        case 1644: return fde_func_1644_0x0ef798(a0, a1);
        case 1645: return fde_func_1645_0x0ef7b0(a0, a1);
        case 1646: return fde_func_1646_0x0ef7cc(a0, a1);
        case 1647: return fde_func_1647_0x0ef7e4(a0, a1);
        case 1648: return fde_func_1648_0x0ef7fc(a0, a1);
        case 1649: return fde_func_1649_0x0ef810(a0, a1);
        case 1650: return fde_func_1650_0x0ef820(a0, a1);
        case 1651: return fde_func_1651_0x0ef82c(a0, a1);
        case 1652: return fde_func_1652_0x0ef838(a0, a1);
        case 1653: return fde_func_1653_0x0ef844(a0, a1);
        case 1654: return fde_func_1654_0x0ef850(a0, a1);
        case 1655: return fde_func_1655_0x0ef85c(a0, a1);
        case 1656: return fde_func_1656_0x0ef870(a0, a1);
        case 1657: return fde_func_1657_0x0ef880(a0, a1);
        case 1658: return fde_func_1658_0x0ef890(a0, a1);
        case 1659: return fde_func_1659_0x0ef8a0(a0, a1);
        case 1660: return fde_func_1660_0x0ef8b0(a0, a1);
        case 1661: return fde_func_1661_0x0ef8c0(a0, a1);
        case 1662: return fde_func_1662_0x0ef8d0(a0, a1);
        case 1663: return fde_func_1663_0x0ef8e0(a0, a1);
        case 1664: return fde_func_1664_0x0ef8f0(a0, a1);
        case 1665: return fde_func_1665_0x0ef900(a0, a1);
        case 1666: return fde_func_1666_0x0ef910(a0, a1);
        case 1667: return fde_func_1667_0x0ef920(a0, a1);
        case 1668: return fde_func_1668_0x0ef930(a0, a1);
        case 1669: return fde_func_1669_0x0ef948(a0, a1);
        case 1670: return fde_func_1670_0x0ef950(a0, a1);
        case 1671: return fde_func_1671_0x0ef958(a0, a1);
        case 1672: return fde_func_1672_0x0ef974(a0, a1);
        case 1673: return fde_func_1673_0x0ef998(a0, a1);
        case 1674: return fde_func_1674_0x0efa38(a0, a1);
        case 1675: return fde_func_1675_0x0efb0c(a0, a1);
        case 1676: return fde_func_1676_0x0efb6c(a0, a1);
        case 1677: return fde_func_1677_0x0efc20(a0, a1);
        case 1678: return fde_func_1678_0x0eff48(a0, a1);
        case 1679: return fde_func_1679_0x0f00c0(a0, a1);
        case 1680: return fde_func_1680_0x0f02b4(a0, a1);
        case 1681: return fde_func_1681_0x0f06c4(a0, a1);
        case 1682: return fde_func_1682_0x0f09b4(a0, a1);
        case 1683: return fde_func_1683_0x0f0ab0(a0, a1);
        case 1684: return fde_func_1684_0x0f17e0(a0, a1);
        case 1685: return fde_func_1685_0x0f1dd4(a0, a1);
        case 1686: return fde_func_1686_0x0f2228(a0, a1);
        case 1687: return fde_func_1687_0x0f2a34(a0, a1);
        case 1688: return fde_func_1688_0x0f3254(a0, a1);
        case 1689: return fde_func_1689_0x0f33a4(a0, a1);
        case 1690: return fde_func_1690_0x0f3df8(a0, a1);
        case 1691: return fde_func_1691_0x0f3fa4(a0, a1);
        case 1692: return fde_func_1692_0x0f407c(a0, a1);
        case 1693: return fde_func_1693_0x0f4154(a0, a1);
        case 1694: return fde_func_1694_0x0f4194(a0, a1);
        case 1695: return fde_func_1695_0x0f4218(a0, a1);
        case 1696: return fde_func_1696_0x0f4498(a0, a1);
        case 1697: return fde_func_1697_0x0f45a8(a0, a1);
        case 1698: return fde_func_1698_0x0f46cc(a0, a1);
        case 1699: return fde_func_1699_0x0f474c(a0, a1);
        case 1700: return fde_func_1700_0x0f4930(a0, a1);
        case 1701: return fde_func_1701_0x0f49b4(a0, a1);
        case 1702: return fde_func_1702_0x0f4b68(a0, a1);
        case 1703: return fde_func_1703_0x0f4c7c(a0, a1);
        case 1704: return fde_func_1704_0x0f4d18(a0, a1);
        case 1705: return fde_func_1705_0x0f4df8(a0, a1);
        case 1706: return fde_func_1706_0x0f4e78(a0, a1);
        case 1707: return fde_func_1707_0x0f4efc(a0, a1);
        case 1708: return fde_func_1708_0x0f5078(a0, a1);
        case 1709: return fde_func_1709_0x0f51e8(a0, a1);
        case 1710: return fde_func_1710_0x0f5364(a0, a1);
        case 1711: return fde_func_1711_0x0f5478(a0, a1);
        case 1712: return fde_func_1712_0x0f5688(a0, a1);
        case 1713: return fde_func_1713_0x0f5764(a0, a1);
        case 1714: return fde_func_1714_0x0f581c(a0, a1);
        case 1715: return fde_func_1715_0x0f592c(a0, a1);
        case 1716: return fde_func_1716_0x0f59c8(a0, a1);
        case 1717: return fde_func_1717_0x0f5aa0(a0, a1);
        case 1718: return fde_func_1718_0x0f5b20(a0, a1);
        case 1719: return fde_func_1719_0x0f5bfc(a0, a1);
        case 1720: return fde_func_1720_0x0f5cb4(a0, a1);
        case 1721: return fde_func_1721_0x0f5e98(a0, a1);
        case 1722: return fde_func_1722_0x0f5fb0(a0, a1);
        case 1723: return fde_func_1723_0x0f6028(a0, a1);
        case 1724: return fde_func_1724_0x0f60d0(a0, a1);
        case 1725: return fde_func_1725_0x0f6154(a0, a1);
        case 1726: return fde_func_1726_0x0f6bf0(a0, a1);
        case 1727: return fde_func_1727_0x0f6e64(a0, a1);
        case 1728: return fde_func_1728_0x0f70c4(a0, a1);
        case 1729: return fde_func_1729_0x0f7284(a0, a1);
        case 1730: return fde_func_1730_0x0f7454(a0, a1);
        case 1731: return fde_func_1731_0x0f758c(a0, a1);
        case 1732: return fde_func_1732_0x0f7804(a0, a1);
        case 1733: return fde_func_1733_0x0f788c(a0, a1);
        case 1734: return fde_func_1734_0x0f7950(a0, a1);
        case 1735: return fde_func_1735_0x0f7a20(a0, a1);
        case 1736: return fde_func_1736_0x0f7b34(a0, a1);
        case 1737: return fde_func_1737_0x0f7d1c(a0, a1);
        case 1738: return fde_func_1738_0x0f7dac(a0, a1);
        case 1739: return fde_func_1739_0x0f7e4c(a0, a1);
        case 1740: return fde_func_1740_0x0f7fc4(a0, a1);
        case 1741: return fde_func_1741_0x0f8070(a0, a1);
        case 1742: return fde_func_1742_0x0f8254(a0, a1);
        case 1743: return fde_func_1743_0x0f83d0(a0, a1);
        case 1744: return fde_func_1744_0x0f8508(a0, a1);
        case 1745: return fde_func_1745_0x0f8678(a0, a1);
        case 1746: return fde_func_1746_0x0f8794(a0, a1);
        case 1747: return fde_func_1747_0x0f87f0(a0, a1);
        case 1748: return fde_func_1748_0x0f88e8(a0, a1);
        case 1749: return fde_func_1749_0x0f8904(a0, a1);
        case 1750: return fde_func_1750_0x0f89d0(a0, a1);
        case 1751: return fde_func_1751_0x0f8a60(a0, a1);
        case 1752: return fde_func_1752_0x0f8b8c(a0, a1);
        case 1753: return fde_func_1753_0x0f8d20(a0, a1);
        case 1754: return fde_func_1754_0x0f8d60(a0, a1);
        case 1755: return fde_func_1755_0x0f8d74(a0, a1);
        case 1756: return fde_func_1756_0x0f8d84(a0, a1);
        case 1757: return fde_func_1757_0x0f8e6c(a0, a1);
        case 1758: return fde_func_1758_0x0f8f6c(a0, a1);
        case 1759: return fde_func_1759_0x0f8f9c(a0, a1);
        case 1760: return fde_func_1760_0x0f8fe0(a0, a1);
        case 1761: return fde_func_1761_0x0f922c(a0, a1);
        case 1762: return fde_func_1762_0x0f92f0(a0, a1);
        case 1763: return fde_func_1763_0x0f9470(a0, a1);
        case 1764: return fde_func_1764_0x0f95a0(a0, a1);
        case 1765: return fde_func_1765_0x0f9610(a0, a1);
        case 1766: return fde_func_1766_0x0f96d8(a0, a1);
        case 1767: return fde_func_1767_0x0f976c(a0, a1);
        case 1768: return fde_func_1768_0x0f993c(a0, a1);
        case 1769: return fde_func_1769_0x0f9bf0(a0, a1);
        case 1770: return fde_func_1770_0x0fa060(a0, a1);
        case 1771: return fde_func_1771_0x0fa3d0(a0, a1);
        case 1772: return fde_func_1772_0x0fa654(a0, a1);
        case 1773: return fde_func_1773_0x0faa78(a0, a1);
        case 1774: return fde_func_1774_0x0fb06c(a0, a1);
        case 1775: return fde_func_1775_0x0fb318(a0, a1);
        case 1776: return fde_func_1776_0x0fb520(a0, a1);
        case 1777: return fde_func_1777_0x0fb5c8(a0, a1);
        case 1778: return fde_func_1778_0x0fb750(a0, a1);
        case 1779: return fde_func_1779_0x0fb7f8(a0, a1);
        case 1780: return fde_func_1780_0x0fb89c(a0, a1);
        case 1781: return fde_func_1781_0x0fba94(a0, a1);
        case 1782: return fde_func_1782_0x0fbc4c(a0, a1);
        case 1783: return fde_func_1783_0x0fbc8c(a0, a1);
        case 1784: return fde_func_1784_0x0fbcd8(a0, a1);
        case 1785: return fde_func_1785_0x0fbd60(a0, a1);
        case 1786: return fde_func_1786_0x0fbed8(a0, a1);
        case 1787: return fde_func_1787_0x0fc060(a0, a1);
        case 1788: return fde_func_1788_0x0fc0e4(a0, a1);
        case 1789: return fde_func_1789_0x0fcd0c(a0, a1);
        case 1790: return fde_func_1790_0x0fcf2c(a0, a1);
        case 1791: return fde_func_1791_0x0fd13c(a0, a1);
        case 1792: return fde_func_1792_0x0fd330(a0, a1);
        case 1793: return fde_func_1793_0x0fd48c(a0, a1);
        case 1794: return fde_func_1794_0x0fd56c(a0, a1);
        case 1795: return fde_func_1795_0x0fd6a4(a0, a1);
        case 1796: return fde_func_1796_0x0fdad0(a0, a1);
        case 1797: return fde_func_1797_0x0fdf4c(a0, a1);
        case 1798: return fde_func_1798_0x0fe350(a0, a1);
        case 1799: return fde_func_1799_0x0fe47c(a0, a1);
        case 1800: return fde_func_1800_0x0fe590(a0, a1);
        case 1801: return fde_func_1801_0x0fe6b0(a0, a1);
        case 1802: return fde_func_1802_0x0fe798(a0, a1);
        case 1803: return fde_func_1803_0x0fe8a8(a0, a1);
        case 1804: return fde_func_1804_0x0fe9c0(a0, a1);
        case 1805: return fde_func_1805_0x0feac0(a0, a1);
        case 1806: return fde_func_1806_0x0fedcc(a0, a1);
        case 1807: return fde_func_1807_0x0ff330(a0, a1);
        case 1808: return fde_func_1808_0x0ff5b4(a0, a1);
        case 1809: return fde_func_1809_0x0ffcd4(a0, a1);
        case 1810: return fde_func_1810_0x0ffcf4(a0, a1);
        case 1811: return fde_func_1811_0x0ffd60(a0, a1);
        case 1812: return fde_func_1812_0x100044(a0, a1);
        case 1813: return fde_func_1813_0x100140(a0, a1);
        case 1814: return fde_func_1814_0x100238(a0, a1);
        case 1815: return fde_func_1815_0x100268(a0, a1);
        case 1816: return fde_func_1816_0x100284(a0, a1);
        case 1817: return fde_func_1817_0x1002bc(a0, a1);
        case 1818: return fde_func_1818_0x1002ec(a0, a1);
        case 1819: return fde_func_1819_0x100324(a0, a1);
        case 1820: return fde_func_1820_0x10034c(a0, a1);
        case 1821: return fde_func_1821_0x100388(a0, a1);
        case 1822: return fde_func_1822_0x1003c0(a0, a1);
        case 1823: return fde_func_1823_0x1003d4(a0, a1);
        case 1824: return fde_func_1824_0x1005c8(a0, a1);
        case 1825: return fde_func_1825_0x1009d0(a0, a1);
        case 1826: return fde_func_1826_0x100ba4(a0, a1);
        case 1827: return fde_func_1827_0x100c18(a0, a1);
        case 1828: return fde_func_1828_0x100cb4(a0, a1);
        case 1829: return fde_func_1829_0x100d28(a0, a1);
        case 1830: return fde_func_1830_0x100d9c(a0, a1);
        case 1831: return fde_func_1831_0x101030(a0, a1);
        case 1832: return fde_func_1832_0x101674(a0, a1);
        case 1833: return fde_func_1833_0x102800(a0, a1);
        case 1834: return fde_func_1834_0x1032cc(a0, a1);
        case 1835: return fde_func_1835_0x103440(a0, a1);
        case 1836: return fde_func_1836_0x103f60(a0, a1);
        case 1837: return fde_func_1837_0x104cf4(a0, a1);
        case 1838: return fde_func_1838_0x106dac(a0, a1);
        case 1839: return fde_func_1839_0x106f28(a0, a1);
        case 1840: return fde_func_1840_0x107028(a0, a1);
        case 1841: return fde_func_1841_0x1070c4(a0, a1);
        case 1842: return fde_func_1842_0x107174(a0, a1);
        case 1843: return fde_func_1843_0x107200(a0, a1);
        case 1844: return fde_func_1844_0x107248(a0, a1);
        case 1845: return fde_func_1845_0x10c1f0(a0, a1);
        case 1846: return fde_func_1846_0x10c300(a0, a1);
        case 1847: return fde_func_1847_0x10c360(a0, a1);
        case 1848: return fde_func_1848_0x10c40c(a0, a1);
        case 1849: return fde_func_1849_0x10caac(a0, a1);
        case 1850: return fde_func_1850_0x10cc64(a0, a1);
        case 1851: return fde_func_1851_0x10cc74(a0, a1);
        case 1852: return fde_func_1852_0x10cd38(a0, a1);
        case 1853: return fde_func_1853_0x10cda0(a0, a1);
        case 1854: return fde_func_1854_0x10cee0(a0, a1);
        case 1855: return fde_func_1855_0x10d00c(a0, a1);
        case 1856: return fde_func_1856_0x10d04c(a0, a1);
        case 1857: return fde_func_1857_0x10d068(a0, a1);
        case 1858: return fde_func_1858_0x10d09c(a0, a1);
        case 1859: return fde_func_1859_0x10d0c4(a0, a1);
        case 1860: return fde_func_1860_0x10d100(a0, a1);
        case 1861: return fde_func_1861_0x10d130(a0, a1);
        case 1862: return fde_func_1862_0x10d148(a0, a1);
        case 1863: return fde_func_1863_0x10d168(a0, a1);
        case 1864: return fde_func_1864_0x10d17c(a0, a1);
        case 1865: return fde_func_1865_0x10d1b0(a0, a1);
        case 1866: return fde_func_1866_0x10d1e4(a0, a1);
        case 1867: return fde_func_1867_0x10d214(a0, a1);
        case 1868: return fde_func_1868_0x10d22c(a0, a1);
        case 1869: return fde_func_1869_0x10d25c(a0, a1);
        case 1870: return fde_func_1870_0x10d290(a0, a1);
        case 1871: return fde_func_1871_0x10d2b8(a0, a1);
        case 1872: return fde_func_1872_0x10d2d0(a0, a1);
        case 1873: return fde_func_1873_0x10d34c(a0, a1);
        case 1874: return fde_func_1874_0x10d478(a0, a1);
        case 1875: return fde_func_1875_0x10d574(a0, a1);
        case 1876: return fde_func_1876_0x10d664(a0, a1);
        case 1877: return fde_func_1877_0x10d750(a0, a1);
        case 1878: return fde_func_1878_0x10d808(a0, a1);
        case 1879: return fde_func_1879_0x10dc1c(a0, a1);
        case 1880: return fde_func_1880_0x10dcb4(a0, a1);
        case 1881: return fde_func_1881_0x10dcdc(a0, a1);
        case 1882: return fde_func_1882_0x10dd04(a0, a1);
        case 1883: return fde_func_1883_0x10dd38(a0, a1);
        case 1884: return fde_func_1884_0x10dd70(a0, a1);
        case 1885: return fde_func_1885_0x10ddac(a0, a1);
        case 1886: return fde_func_1886_0x10dde0(a0, a1);
        case 1887: return fde_func_1887_0x10de18(a0, a1);
        case 1888: return fde_func_1888_0x10de60(a0, a1);
        case 1889: return fde_func_1889_0x10dfc4(a0, a1);
        case 1890: return fde_func_1890_0x10e21c(a0, a1);
        case 1891: return fde_func_1891_0x10e314(a0, a1);
        case 1892: return fde_func_1892_0x10e408(a0, a1);
        case 1893: return fde_func_1893_0x10e760(a0, a1);
        case 1894: return fde_func_1894_0x10e8cc(a0, a1);
        case 1895: return fde_func_1895_0x10eb38(a0, a1);
        case 1896: return fde_func_1896_0x10ec5c(a0, a1);
        case 1897: return fde_func_1897_0x10ee00(a0, a1);
        case 1898: return fde_func_1898_0x10ee44(a0, a1);
        case 1899: return fde_func_1899_0x10f070(a0, a1);
        case 1900: return fde_func_1900_0x10f670(a0, a1);
        case 1901: return fde_func_1901_0x10f7a4(a0, a1);
        case 1902: return fde_func_1902_0x10f8c0(a0, a1);
        case 1903: return fde_func_1903_0x10fd94(a0, a1);
        case 1904: return fde_func_1904_0x10fe5c(a0, a1);
        case 1905: return fde_func_1905_0x10fea8(a0, a1);
        case 1906: return fde_func_1906_0x10fed0(a0, a1);
        case 1907: return fde_func_1907_0x11014c(a0, a1);
        case 1908: return fde_func_1908_0x1101d4(a0, a1);
        case 1909: return fde_func_1909_0x110524(a0, a1);
        case 1910: return fde_func_1910_0x1108fc(a0, a1);
        case 1911: return fde_func_1911_0x110e44(a0, a1);
        case 1912: return fde_func_1912_0x111538(a0, a1);
        case 1913: return fde_func_1913_0x111b70(a0, a1);
        case 1914: return fde_func_1914_0x111c58(a0, a1);
        case 1915: return fde_func_1915_0x111d48(a0, a1);
        case 1916: return fde_func_1916_0x111e3c(a0, a1);
        case 1917: return fde_func_1917_0x112050(a0, a1);
        case 1918: return fde_func_1918_0x1125a4(a0, a1);
        case 1919: return fde_func_1919_0x1128b0(a0, a1);
        case 1920: return fde_func_1920_0x1131bc(a0, a1);
        case 1921: return fde_func_1921_0x1132d0(a0, a1);
        case 1922: return fde_func_1922_0x1133c8(a0, a1);
        case 1923: return fde_func_1923_0x1134d0(a0, a1);
        case 1924: return fde_func_1924_0x1138e8(a0, a1);
        case 1925: return fde_func_1925_0x1139d4(a0, a1);
        case 1926: return fde_func_1926_0x114e54(a0, a1);
        case 1927: return fde_func_1927_0x114f60(a0, a1);
        case 1928: return fde_func_1928_0x11505c(a0, a1);
        case 1929: return fde_func_1929_0x115168(a0, a1);
        case 1930: return fde_func_1930_0x115270(a0, a1);
        case 1931: return fde_func_1931_0x1153a8(a0, a1);
        case 1932: return fde_func_1932_0x1154a0(a0, a1);
        case 1933: return fde_func_1933_0x115d98(a0, a1);
        case 1934: return fde_func_1934_0x115e94(a0, a1);
        case 1935: return fde_func_1935_0x115f90(a0, a1);
        case 1936: return fde_func_1936_0x116608(a0, a1);
        case 1937: return fde_func_1937_0x116ae8(a0, a1);
        case 1938: return fde_func_1938_0x116f58(a0, a1);
        case 1939: return fde_func_1939_0x11705c(a0, a1);
        case 1940: return fde_func_1940_0x11717c(a0, a1);
        case 1941: return fde_func_1941_0x117278(a0, a1);
        case 1942: return fde_func_1942_0x117598(a0, a1);
        case 1943: return fde_func_1943_0x1176a4(a0, a1);
        case 1944: return fde_func_1944_0x1177ac(a0, a1);
        case 1945: return fde_func_1945_0x1178c4(a0, a1);
        case 1946: return fde_func_1946_0x117ec8(a0, a1);
        case 1947: return fde_func_1947_0x117fcc(a0, a1);
        case 1948: return fde_func_1948_0x11845c(a0, a1);
        case 1949: return fde_func_1949_0x118498(a0, a1);
        case 1950: return fde_func_1950_0x118aac(a0, a1);
        case 1951: return fde_func_1951_0x118bb8(a0, a1);
        case 1952: return fde_func_1952_0x118cc8(a0, a1);
        case 1953: return fde_func_1953_0x118dd4(a0, a1);
        case 1954: return fde_func_1954_0x118eec(a0, a1);
        case 1955: return fde_func_1955_0x118fdc(a0, a1);
        case 1956: return fde_func_1956_0x1190c4(a0, a1);
        case 1957: return fde_func_1957_0x119190(a0, a1);
        case 1958: return fde_func_1958_0x119fa8(a0, a1);
        case 1959: return fde_func_1959_0x11a0c4(a0, a1);
        case 1960: return fde_func_1960_0x11a36c(a0, a1);
        case 1961: return fde_func_1961_0x11a570(a0, a1);
        case 1962: return fde_func_1962_0x11b088(a0, a1);
        case 1963: return fde_func_1963_0x11b32c(a0, a1);
        case 1964: return fde_func_1964_0x11b8c0(a0, a1);
        case 1965: return fde_func_1965_0x11ba14(a0, a1);
        case 1966: return fde_func_1966_0x11bbe0(a0, a1);
        case 1967: return fde_func_1967_0x11bcdc(a0, a1);
        case 1968: return fde_func_1968_0x11c2f8(a0, a1);
        case 1969: return fde_func_1969_0x11ca94(a0, a1);
        case 1970: return fde_func_1970_0x11cdec(a0, a1);
        case 1971: return fde_func_1971_0x11ce00(a0, a1);
        case 1972: return fde_func_1972_0x11d308(a0, a1);
        case 1973: return fde_func_1973_0x11d884(a0, a1);
        case 1974: return fde_func_1974_0x11d9d8(a0, a1);
        case 1975: return fde_func_1975_0x11da10(a0, a1);
        case 1976: return fde_func_1976_0x11da2c(a0, a1);
        case 1977: return fde_func_1977_0x11dd7c(a0, a1);
        case 1978: return fde_func_1978_0x11df44(a0, a1);
        case 1979: return fde_func_1979_0x11ec64(a0, a1);
        case 1980: return fde_func_1980_0x11ed68(a0, a1);
        case 1981: return fde_func_1981_0x11f038(a0, a1);
        case 1982: return fde_func_1982_0x11f1b4(a0, a1);
        case 1983: return fde_func_1983_0x11f2a8(a0, a1);
        case 1984: return fde_func_1984_0x11f62c(a0, a1);
        case 1985: return fde_func_1985_0x11f8e8(a0, a1);
        case 1986: return fde_func_1986_0x11f9d0(a0, a1);
        case 1987: return fde_func_1987_0x11fbb4(a0, a1);
        case 1988: return fde_func_1988_0x11fd8c(a0, a1);
        case 1989: return fde_func_1989_0x1200f4(a0, a1);
        case 1990: return fde_func_1990_0x1202f4(a0, a1);
        case 1991: return fde_func_1991_0x120514(a0, a1);
        case 1992: return fde_func_1992_0x120630(a0, a1);
        case 1993: return fde_func_1993_0x120798(a0, a1);
        case 1994: return fde_func_1994_0x120bbc(a0, a1);
        case 1995: return fde_func_1995_0x12121c(a0, a1);
        case 1996: return fde_func_1996_0x121274(a0, a1);
        case 1997: return fde_func_1997_0x1212e0(a0, a1);
        case 1998: return fde_func_1998_0x12130c(a0, a1);
        case 1999: return fde_func_1999_0x121374(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ov
} // namespace metasec