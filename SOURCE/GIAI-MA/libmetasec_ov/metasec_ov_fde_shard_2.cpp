// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 2/5 for libmetasec_ov.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 2/5 cho libmetasec_ov.so
// Covers representative FDE indices [400 .. 799] out of 5,296 total FDEs
// Bao phủ chỉ số FDE đại diện [400 .. 799] trên tổng số 5.296 FDE
// ============================================================================
#include "metasec_ov_core.h"

namespace metasec {
namespace ov {

// FDE #0400 | PC: 0x0727a4 | FDE: 0x1995e8 | Size: 256 bytes
// Khung tháo gỡ #0400 | Địa chỉ PC: 0x0727a4 | Địa chỉ FDE: 0x1995e8 | Kích thước: 256 bytes
//   0x0727a4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0727a8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0727ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0727b0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0400_0x0727a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0727a4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1995e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0401 | PC: 0x072be0 | FDE: 0x199648 | Size: 220 bytes
// Khung tháo gỡ #0401 | Địa chỉ PC: 0x072be0 | Địa chỉ FDE: 0x199648 | Kích thước: 220 bytes
//   0x072be0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x072be4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x072be8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x072bec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0401_0x072be0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072be0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x199648ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0402 | PC: 0x072cbc | FDE: 0x199700 | Size: 120 bytes
// Khung tháo gỡ #0402 | Địa chỉ PC: 0x072cbc | Địa chỉ FDE: 0x199700 | Kích thước: 120 bytes
//   0x072cbc: B0000A88  adrp     x8, #0x1c3000
//   0x072cc0: 9114A108  add      x8, x8, #0x528
//   0x072cc4: 6F00E400  movi     v0.2d, #0000000000000000
//   0x072cc8: 3900401F  strb     wzr, [x0, #0x10]
static inline uint64_t fde_func_0402_0x072cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072cbcULL ^ (static_cast<uint64_t>(0xb0000a88ULL) << 13);
    acc = (acc + a1 + 0x9114a108ULL) ^ 0x199700ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0403 | PC: 0x072d34 | FDE: 0x199738 | Size: 96 bytes
// Khung tháo gỡ #0403 | Địa chỉ PC: 0x072d34 | Địa chỉ FDE: 0x199738 | Kích thước: 96 bytes
//   0x072d34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x072d38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x072d3c: 910043FD  add      x29, sp, #0x10
//   0x072d40: B0000A88  adrp     x8, #0x1c3000
static inline uint64_t fde_func_0403_0x072d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072d34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199738ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0404 | PC: 0x072d94 | FDE: 0x199778 | Size: 256 bytes
// Khung tháo gỡ #0404 | Địa chỉ PC: 0x072d94 | Địa chỉ FDE: 0x199778 | Kích thước: 256 bytes
//   0x072d94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x072d98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x072d9c: 910043FD  add      x29, sp, #0x10
//   0x072da0: D10083FF  sub      sp, sp, #0x20
static inline uint64_t fde_func_0404_0x072d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072d94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0405 | PC: 0x0731fc | FDE: 0x1997b8 | Size: 48 bytes
// Khung tháo gỡ #0405 | Địa chỉ PC: 0x0731fc | Địa chỉ FDE: 0x1997b8 | Kích thước: 48 bytes
//   0x0731fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x073200: 910003FD  mov      x29, sp
//   0x073204: 97FFFF5B  bl       #0x72f70
//   0x073208: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0405_0x0731fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0731fcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1997b8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0406 | PC: 0x07322c | FDE: 0x1997f8 | Size: 256 bytes
// Khung tháo gỡ #0406 | Địa chỉ PC: 0x07322c | Địa chỉ FDE: 0x1997f8 | Kích thước: 256 bytes
//   0x07322c: D10143FF  sub      sp, sp, #0x50
//   0x073230: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x073234: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x073238: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0406_0x07322c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07322cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1997f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0407 | PC: 0x073a54 | FDE: 0x199850 | Size: 256 bytes
// Khung tháo gỡ #0407 | Địa chỉ PC: 0x073a54 | Địa chỉ FDE: 0x199850 | Kích thước: 256 bytes
//   0x073a54: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x073a58: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x073a5c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x073a60: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0407_0x073a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073a54ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x199850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0408 | PC: 0x074838 | FDE: 0x1998a0 | Size: 256 bytes
// Khung tháo gỡ #0408 | Địa chỉ PC: 0x074838 | Địa chỉ FDE: 0x1998a0 | Kích thước: 256 bytes
//   0x074838: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07483c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x074840: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x074844: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0408_0x074838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074838ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1998a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0409 | PC: 0x0753a8 | FDE: 0x1998f8 | Size: 112 bytes
// Khung tháo gỡ #0409 | Địa chỉ PC: 0x0753a8 | Địa chỉ FDE: 0x1998f8 | Kích thước: 112 bytes
//   0x0753a8: D10103FF  sub      sp, sp, #0x40
//   0x0753ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0753b0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0753b4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0409_0x0753a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0753a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1998f8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0410 | PC: 0x075418 | FDE: 0x199930 | Size: 24 bytes
// Khung tháo gỡ #0410 | Địa chỉ PC: 0x075418 | Địa chỉ FDE: 0x199930 | Kích thước: 24 bytes
//   0x075418: 3900011F  strb     wzr, [x8]
//   0x07541c: 3900611F  strb     wzr, [x8, #0x18]
//   0x075420: D65F03C0  ret      
//   0x075424: 3900011F  strb     wzr, [x8]
static inline uint64_t fde_func_0410_0x075418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075418ULL ^ (static_cast<uint64_t>(0x3900011fULL) << 13);
    acc = (acc + a1 + 0x3900611fULL) ^ 0x199930ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0411 | PC: 0x075430 | FDE: 0x199960 | Size: 16 bytes
// Khung tháo gỡ #0411 | Địa chỉ PC: 0x075430 | Địa chỉ FDE: 0x199960 | Kích thước: 16 bytes
//   0x075430: AA1F03E0  mov      x0, xzr
//   0x075434: D65F03C0  ret      
//   0x075438: AA1F03E0  mov      x0, xzr
//   0x07543c: D65F03C0  ret      
static inline uint64_t fde_func_0411_0x075430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075430ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x199960ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0412 | PC: 0x075440 | FDE: 0x199990 | Size: 28 bytes
// Khung tháo gỡ #0412 | Địa chỉ PC: 0x075440 | Địa chỉ FDE: 0x199990 | Kích thước: 28 bytes
//   0x075440: 52800020  mov      w0, #1
//   0x075444: D65F03C0  ret      
//   0x075448: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07544c: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0412_0x075440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075440ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x199990ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0413 | PC: 0x07545c | FDE: 0x1999c8 | Size: 80 bytes
// Khung tháo gỡ #0413 | Địa chỉ PC: 0x07545c | Địa chỉ FDE: 0x1999c8 | Kích thước: 80 bytes
//   0x07545c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x075460: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075464: 910043FD  add      x29, sp, #0x10
//   0x075468: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0413_0x07545c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07545cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1999c8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0414 | PC: 0x0754ac | FDE: 0x199a00 | Size: 24 bytes
// Khung tháo gỡ #0414 | Địa chỉ PC: 0x0754ac | Địa chỉ FDE: 0x199a00 | Kích thước: 24 bytes
//   0x0754ac: D65F03C0  ret      
//   0x0754b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0754b4: 910003FD  mov      x29, sp
//   0x0754b8: 97FEE2F6  bl       #0x2e090
static inline uint64_t fde_func_0414_0x0754ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0754acULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x199a00ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0415 | PC: 0x0754c4 | FDE: 0x199a38 | Size: 192 bytes
// Khung tháo gỡ #0415 | Địa chỉ PC: 0x0754c4 | Địa chỉ FDE: 0x199a38 | Kích thước: 192 bytes
//   0x0754c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0754c8: 910003FD  mov      x29, sp
//   0x0754cc: F9400400  ldr      x0, [x0, #8]
//   0x0754d0: 97FFF7A2  bl       #0x73358
static inline uint64_t fde_func_0415_0x0754c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0754c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x199a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0416 | PC: 0x075584 | FDE: 0x199a78 | Size: 64 bytes
// Khung tháo gỡ #0416 | Địa chỉ PC: 0x075584 | Địa chỉ FDE: 0x199a78 | Kích thước: 64 bytes
//   0x075584: F9400008  ldr      x8, [x0]
//   0x075588: F9400108  ldr      x8, [x8]
//   0x07558c: 39400108  ldrb     w8, [x8]
//   0x075590: 521D7908  eor      w8, w8, #0xfffffffb
static inline uint64_t fde_func_0416_0x075584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075584ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x199a78ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0417 | PC: 0x0755c4 | FDE: 0x199aa8 | Size: 72 bytes
// Khung tháo gỡ #0417 | Địa chỉ PC: 0x0755c4 | Địa chỉ FDE: 0x199aa8 | Kích thước: 72 bytes
//   0x0755c4: F9400008  ldr      x8, [x0]
//   0x0755c8: F9400108  ldr      x8, [x8]
//   0x0755cc: 39400108  ldrb     w8, [x8]
//   0x0755d0: 53067D09  lsr      w9, w8, #6
static inline uint64_t fde_func_0417_0x0755c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0755c4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x199aa8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0418 | PC: 0x07560c | FDE: 0x199ad8 | Size: 64 bytes
// Khung tháo gỡ #0418 | Địa chỉ PC: 0x07560c | Địa chỉ FDE: 0x199ad8 | Kích thước: 64 bytes
//   0x07560c: F9400008  ldr      x8, [x0]
//   0x075610: F9400108  ldr      x8, [x8]
//   0x075614: 39400108  ldrb     w8, [x8]
//   0x075618: 521D7908  eor      w8, w8, #0xfffffffb
static inline uint64_t fde_func_0418_0x07560c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07560cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x199ad8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0419 | PC: 0x07564c | FDE: 0x199b08 | Size: 64 bytes
// Khung tháo gỡ #0419 | Địa chỉ PC: 0x07564c | Địa chỉ FDE: 0x199b08 | Kích thước: 64 bytes
//   0x07564c: F9400008  ldr      x8, [x0]
//   0x075650: F9400108  ldr      x8, [x8]
//   0x075654: 39400108  ldrb     w8, [x8]
//   0x075658: 53027D09  lsr      w9, w8, #2
static inline uint64_t fde_func_0419_0x07564c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07564cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x199b08ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0420 | PC: 0x07568c | FDE: 0x199b38 | Size: 192 bytes
// Khung tháo gỡ #0420 | Địa chỉ PC: 0x07568c | Địa chỉ FDE: 0x199b38 | Kích thước: 192 bytes
//   0x07568c: D10143FF  sub      sp, sp, #0x50
//   0x075690: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x075694: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x075698: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0420_0x07568c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07568cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x199b38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0421 | PC: 0x07574c | FDE: 0x199be8 | Size: 256 bytes
// Khung tháo gỡ #0421 | Địa chỉ PC: 0x07574c | Địa chỉ FDE: 0x199be8 | Kích thước: 256 bytes
//   0x07574c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x075750: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x075754: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x075758: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0421_0x07574c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07574cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x199be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0422 | PC: 0x076b0c | FDE: 0x199c38 | Size: 256 bytes
// Khung tháo gỡ #0422 | Địa chỉ PC: 0x076b0c | Địa chỉ FDE: 0x199c38 | Kích thước: 256 bytes
//   0x076b0c: D104C3FF  sub      sp, sp, #0x130
//   0x076b10: F9006BFC  str      x28, [sp, #0xd0]
//   0x076b14: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x076b18: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0422_0x076b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076b0cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x199c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0423 | PC: 0x076ec4 | FDE: 0x199c88 | Size: 168 bytes
// Khung tháo gỡ #0423 | Địa chỉ PC: 0x076ec4 | Địa chỉ FDE: 0x199c88 | Kích thước: 168 bytes
//   0x076ec4: D10443FF  sub      sp, sp, #0x110
//   0x076ec8: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x076ecc: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x076ed0: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0423_0x076ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076ec4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x199c88ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0424 | PC: 0x076f6c | FDE: 0x199cc0 | Size: 52 bytes
// Khung tháo gỡ #0424 | Địa chỉ PC: 0x076f6c | Địa chỉ FDE: 0x199cc0 | Kích thước: 52 bytes
//   0x076f6c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x076f70: 910003FD  mov      x29, sp
//   0x076f74: 97FEDC47  bl       #0x2e090
//   0x076f78: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0424_0x076f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076f6cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x199cc0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0425 | PC: 0x076fa0 | FDE: 0x199d00 | Size: 72 bytes
// Khung tháo gỡ #0425 | Địa chỉ PC: 0x076fa0 | Địa chỉ FDE: 0x199d00 | Kích thước: 72 bytes
//   0x076fa0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x076fa4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x076fa8: 910043FD  add      x29, sp, #0x10
//   0x076fac: B0000A68  adrp     x8, #0x1c3000
static inline uint64_t fde_func_0425_0x076fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076fa0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199d00ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0426 | PC: 0x076fe8 | FDE: 0x199db0 | Size: 256 bytes
// Khung tháo gỡ #0426 | Địa chỉ PC: 0x076fe8 | Địa chỉ FDE: 0x199db0 | Kích thước: 256 bytes
//   0x076fe8: D107C3FF  sub      sp, sp, #0x1f0
//   0x076fec: A91C57FC  stp      x28, x21, [sp, #0x1c0]
//   0x076ff0: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
//   0x076ff4: A91E7BFD  stp      x29, x30, [sp, #0x1e0]
static inline uint64_t fde_func_0426_0x076fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076fe8ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91c57fcULL) ^ 0x199db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0427 | PC: 0x07721c | FDE: 0x199df8 | Size: 232 bytes
// Khung tháo gỡ #0427 | Địa chỉ PC: 0x07721c | Địa chỉ FDE: 0x199df8 | Kích thước: 232 bytes
//   0x07721c: AA1F03E0  mov      x0, xzr
//   0x077220: D65F03C0  ret      
//   0x077224: D10183FF  sub      sp, sp, #0x60
//   0x077228: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0427_0x07721c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07721cULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x199df8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0428 | PC: 0x077304 | FDE: 0x199e30 | Size: 256 bytes
// Khung tháo gỡ #0428 | Địa chỉ PC: 0x077304 | Địa chỉ FDE: 0x199e30 | Kích thước: 256 bytes
//   0x077304: D105C3FF  sub      sp, sp, #0x170
//   0x077308: A91267FC  stp      x28, x25, [sp, #0x120]
//   0x07730c: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x077310: A91457F6  stp      x22, x21, [sp, #0x140]
static inline uint64_t fde_func_0428_0x077304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077304ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa91267fcULL) ^ 0x199e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0429 | PC: 0x07762c | FDE: 0x199e88 | Size: 256 bytes
// Khung tháo gỡ #0429 | Địa chỉ PC: 0x07762c | Địa chỉ FDE: 0x199e88 | Kích thước: 256 bytes
//   0x07762c: D10643FF  sub      sp, sp, #0x190
//   0x077630: F900A3FC  str      x28, [sp, #0x140]
//   0x077634: A9155FF8  stp      x24, x23, [sp, #0x150]
//   0x077638: A91657F6  stp      x22, x21, [sp, #0x160]
static inline uint64_t fde_func_0429_0x07762c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07762cULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900a3fcULL) ^ 0x199e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0430 | PC: 0x0779bc | FDE: 0x199ed0 | Size: 256 bytes
// Khung tháo gỡ #0430 | Địa chỉ PC: 0x0779bc | Địa chỉ FDE: 0x199ed0 | Kích thước: 256 bytes
//   0x0779bc: D10603FF  sub      sp, sp, #0x180
//   0x0779c0: F9009BFC  str      x28, [sp, #0x130]
//   0x0779c4: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x0779c8: A91557F6  stp      x22, x21, [sp, #0x150]
static inline uint64_t fde_func_0430_0x0779bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0779bcULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x199ed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0431 | PC: 0x077c1c | FDE: 0x199f90 | Size: 256 bytes
// Khung tháo gỡ #0431 | Địa chỉ PC: 0x077c1c | Địa chỉ FDE: 0x199f90 | Kích thước: 256 bytes
//   0x077c1c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x077c20: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x077c24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x077c28: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0431_0x077c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077c1cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x199f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0432 | PC: 0x077d84 | FDE: 0x199fd8 | Size: 256 bytes
// Khung tháo gỡ #0432 | Địa chỉ PC: 0x077d84 | Địa chỉ FDE: 0x199fd8 | Kích thước: 256 bytes
//   0x077d84: D10303FF  sub      sp, sp, #0xc0
//   0x077d88: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x077d8c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x077d90: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0432_0x077d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077d84ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x199fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0433 | PC: 0x078370 | FDE: 0x19a028 | Size: 224 bytes
// Khung tháo gỡ #0433 | Địa chỉ PC: 0x078370 | Địa chỉ FDE: 0x19a028 | Kích thước: 224 bytes
//   0x078370: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x078374: 910003FD  mov      x29, sp
//   0x078378: 90000B28  adrp     x8, #0x1dc000
//   0x07837c: 91030108  add      x8, x8, #0xc0
static inline uint64_t fde_func_0433_0x078370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078370ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a028ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0434 | PC: 0x078450 | FDE: 0x19a068 | Size: 256 bytes
// Khung tháo gỡ #0434 | Địa chỉ PC: 0x078450 | Địa chỉ FDE: 0x19a068 | Kích thước: 256 bytes
//   0x078450: D10103FF  sub      sp, sp, #0x40
//   0x078454: F90013F3  str      x19, [sp, #0x20]
//   0x078458: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07845c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0434_0x078450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078450ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x19a068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0435 | PC: 0x07860c | FDE: 0x19a0a8 | Size: 256 bytes
// Khung tháo gỡ #0435 | Địa chỉ PC: 0x07860c | Địa chỉ FDE: 0x19a0a8 | Kích thước: 256 bytes
//   0x07860c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x078610: 910003FD  mov      x29, sp
//   0x078614: 97FFFDDC  bl       #0x77d84
//   0x078618: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0435_0x07860c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07860cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0436 | PC: 0x0787c8 | FDE: 0x19a0f0 | Size: 256 bytes
// Khung tháo gỡ #0436 | Địa chỉ PC: 0x0787c8 | Địa chỉ FDE: 0x19a0f0 | Kích thước: 256 bytes
//   0x0787c8: D10343FF  sub      sp, sp, #0xd0
//   0x0787cc: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0787d0: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0787d4: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0436_0x0787c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0787c8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x19a0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0437 | PC: 0x079160 | FDE: 0x19a148 | Size: 256 bytes
// Khung tháo gỡ #0437 | Địa chỉ PC: 0x079160 | Địa chỉ FDE: 0x19a148 | Kích thước: 256 bytes
//   0x079160: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x079164: 910003FD  mov      x29, sp
//   0x079168: F0000B08  adrp     x8, #0x1dc000
//   0x07916c: 91038108  add      x8, x8, #0xe0
static inline uint64_t fde_func_0437_0x079160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079160ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0438 | PC: 0x0796c8 | FDE: 0x19a198 | Size: 256 bytes
// Khung tháo gỡ #0438 | Địa chỉ PC: 0x0796c8 | Địa chỉ FDE: 0x19a198 | Kích thước: 256 bytes
//   0x0796c8: D10483FF  sub      sp, sp, #0x120
//   0x0796cc: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x0796d0: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x0796d4: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_0438_0x0796c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0796c8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x19a198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0439 | PC: 0x0797e4 | FDE: 0x19a1d8 | Size: 228 bytes
// Khung tháo gỡ #0439 | Địa chỉ PC: 0x0797e4 | Địa chỉ FDE: 0x19a1d8 | Kích thước: 228 bytes
//   0x0797e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0797e8: 910003FD  mov      x29, sp
//   0x0797ec: F0000B08  adrp     x8, #0x1dc000
//   0x0797f0: 91040108  add      x8, x8, #0x100
static inline uint64_t fde_func_0439_0x0797e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0797e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a1d8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0440 | PC: 0x0798c8 | FDE: 0x19a218 | Size: 256 bytes
// Khung tháo gỡ #0440 | Địa chỉ PC: 0x0798c8 | Địa chỉ FDE: 0x19a218 | Kích thước: 256 bytes
//   0x0798c8: D10303FF  sub      sp, sp, #0xc0
//   0x0798cc: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0798d0: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0798d4: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0440_0x0798c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0798c8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x19a218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0441 | PC: 0x07a2c8 | FDE: 0x19a278 | Size: 256 bytes
// Khung tháo gỡ #0441 | Địa chỉ PC: 0x07a2c8 | Địa chỉ FDE: 0x19a278 | Kích thước: 256 bytes
//   0x07a2c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07a2cc: 910003FD  mov      x29, sp
//   0x07a2d0: D0000B08  adrp     x8, #0x1dc000
//   0x07a2d4: 91048108  add      x8, x8, #0x120
static inline uint64_t fde_func_0441_0x07a2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a2c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0442 | PC: 0x07a56c | FDE: 0x19a2c0 | Size: 256 bytes
// Khung tháo gỡ #0442 | Địa chỉ PC: 0x07a56c | Địa chỉ FDE: 0x19a2c0 | Kích thước: 256 bytes
//   0x07a56c: D10483FF  sub      sp, sp, #0x120
//   0x07a570: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x07a574: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x07a578: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0442_0x07a56c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a56cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x19a2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0443 | PC: 0x07aad8 | FDE: 0x19a310 | Size: 256 bytes
// Khung tháo gỡ #0443 | Địa chỉ PC: 0x07aad8 | Địa chỉ FDE: 0x19a310 | Kích thước: 256 bytes
//   0x07aad8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07aadc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07aae0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07aae4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0443_0x07aad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07aad8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19a310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0444 | PC: 0x07afb0 | FDE: 0x19a360 | Size: 256 bytes
// Khung tháo gỡ #0444 | Địa chỉ PC: 0x07afb0 | Địa chỉ FDE: 0x19a360 | Kích thước: 256 bytes
//   0x07afb0: F8418C09  ldr      x9, [x0, #0x18]!
//   0x07afb4: B40001A9  cbz      x9, #0x7afe8
//   0x07afb8: AA0003E8  mov      x8, x0
//   0x07afbc: F940112A  ldr      x10, [x9, #0x20]
static inline uint64_t fde_func_0444_0x07afb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07afb0ULL ^ (static_cast<uint64_t>(0xf8418c09ULL) << 13);
    acc = (acc + a1 + 0xb40001a9ULL) ^ 0x19a360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0445 | PC: 0x07b1e4 | FDE: 0x19a398 | Size: 256 bytes
// Khung tháo gỡ #0445 | Địa chỉ PC: 0x07b1e4 | Địa chỉ FDE: 0x19a398 | Kích thước: 256 bytes
//   0x07b1e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b1e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b1ec: 910043FD  add      x29, sp, #0x10
//   0x07b1f0: B0000B08  adrp     x8, #0x1dc000
static inline uint64_t fde_func_0445_0x07b1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b1e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0446 | PC: 0x07b378 | FDE: 0x19a3d8 | Size: 28 bytes
// Khung tháo gỡ #0446 | Địa chỉ PC: 0x07b378 | Địa chỉ FDE: 0x19a3d8 | Kích thước: 28 bytes
//   0x07b378: 52800060  mov      w0, #3
//   0x07b37c: D65F03C0  ret      
//   0x07b380: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07b384: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0446_0x07b378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b378ULL ^ (static_cast<uint64_t>(0x52800060ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19a3d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0447 | PC: 0x07b394 | FDE: 0x19a410 | Size: 80 bytes
// Khung tháo gỡ #0447 | Địa chỉ PC: 0x07b394 | Địa chỉ FDE: 0x19a410 | Kích thước: 80 bytes
//   0x07b394: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07b398: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b39c: 910043FD  add      x29, sp, #0x10
//   0x07b3a0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0447_0x07b394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b394ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a410ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0448 | PC: 0x07b3e4 | FDE: 0x19a448 | Size: 24 bytes
// Khung tháo gỡ #0448 | Địa chỉ PC: 0x07b3e4 | Địa chỉ FDE: 0x19a448 | Kích thước: 24 bytes
//   0x07b3e4: D65F03C0  ret      
//   0x07b3e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07b3ec: 910003FD  mov      x29, sp
//   0x07b3f0: 97FECB28  bl       #0x2e090
static inline uint64_t fde_func_0448_0x07b3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b3e4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x19a448ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0449 | PC: 0x07b3fc | FDE: 0x19a480 | Size: 48 bytes
// Khung tháo gỡ #0449 | Địa chỉ PC: 0x07b3fc | Địa chỉ FDE: 0x19a480 | Kích thước: 48 bytes
//   0x07b3fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07b400: 910003FD  mov      x29, sp
//   0x07b404: F9400400  ldr      x0, [x0, #8]
//   0x07b408: 97FFF25F  bl       #0x77d84
static inline uint64_t fde_func_0449_0x07b3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b3fcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a480ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0450 | PC: 0x07b42c | FDE: 0x19a4c0 | Size: 80 bytes
// Khung tháo gỡ #0450 | Địa chỉ PC: 0x07b42c | Địa chỉ FDE: 0x19a4c0 | Kích thước: 80 bytes
//   0x07b42c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07b430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b434: 910043FD  add      x29, sp, #0x10
//   0x07b438: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0450_0x07b42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b42cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a4c0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0451 | PC: 0x07b47c | FDE: 0x19a4f8 | Size: 24 bytes
// Khung tháo gỡ #0451 | Địa chỉ PC: 0x07b47c | Địa chỉ FDE: 0x19a4f8 | Kích thước: 24 bytes
//   0x07b47c: D65F03C0  ret      
//   0x07b480: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07b484: 910003FD  mov      x29, sp
//   0x07b488: 97FECB02  bl       #0x2e090
static inline uint64_t fde_func_0451_0x07b47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b47cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x19a4f8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0452 | PC: 0x07b494 | FDE: 0x19a530 | Size: 104 bytes
// Khung tháo gỡ #0452 | Địa chỉ PC: 0x07b494 | Địa chỉ FDE: 0x19a530 | Kích thước: 104 bytes
//   0x07b494: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07b498: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b49c: 910043FD  add      x29, sp, #0x10
//   0x07b4a0: A940CC08  ldp      x8, x19, [x0, #8]
static inline uint64_t fde_func_0452_0x07b494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b494ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a530ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0453 | PC: 0x07b4fc | FDE: 0x19a570 | Size: 212 bytes
// Khung tháo gỡ #0453 | Địa chỉ PC: 0x07b4fc | Địa chỉ FDE: 0x19a570 | Kích thước: 212 bytes
//   0x07b4fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b500: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b504: 910043FD  add      x29, sp, #0x10
//   0x07b508: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0453_0x07b4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b4fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a570ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0454 | PC: 0x07b5d0 | FDE: 0x19a5b0 | Size: 72 bytes
// Khung tháo gỡ #0454 | Địa chỉ PC: 0x07b5d0 | Địa chỉ FDE: 0x19a5b0 | Kích thước: 72 bytes
//   0x07b5d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07b5d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b5d8: 910043FD  add      x29, sp, #0x10
//   0x07b5dc: 90000A48  adrp     x8, #0x1c3000
static inline uint64_t fde_func_0454_0x07b5d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b5d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a5b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0455 | PC: 0x07b618 | FDE: 0x19a660 | Size: 256 bytes
// Khung tháo gỡ #0455 | Địa chỉ PC: 0x07b618 | Địa chỉ FDE: 0x19a660 | Kích thước: 256 bytes
//   0x07b618: D10143FF  sub      sp, sp, #0x50
//   0x07b61c: F90013F5  str      x21, [sp, #0x20]
//   0x07b620: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07b624: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0455_0x07b618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b618ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x19a660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0456 | PC: 0x07b7c4 | FDE: 0x19a698 | Size: 160 bytes
// Khung tháo gỡ #0456 | Địa chỉ PC: 0x07b7c4 | Địa chỉ FDE: 0x19a698 | Kích thước: 160 bytes
//   0x07b7c4: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x07b7c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b7cc: 910043FD  add      x29, sp, #0x10
//   0x07b7d0: D112C3FF  sub      sp, sp, #0x4b0
static inline uint64_t fde_func_0456_0x07b7c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b7c4ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a698ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0457 | PC: 0x07b864 | FDE: 0x19a6d8 | Size: 144 bytes
// Khung tháo gỡ #0457 | Địa chỉ PC: 0x07b864 | Địa chỉ FDE: 0x19a6d8 | Kích thước: 144 bytes
//   0x07b864: B9400400  ldr      w0, [x0, #4]
//   0x07b868: D65F03C0  ret      
//   0x07b86c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07b870: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0457_0x07b864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b864ULL ^ (static_cast<uint64_t>(0xb9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19a6d8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0458 | PC: 0x07b8f4 | FDE: 0x19a710 | Size: 256 bytes
// Khung tháo gỡ #0458 | Địa chỉ PC: 0x07b8f4 | Địa chỉ FDE: 0x19a710 | Kích thước: 256 bytes
//   0x07b8f4: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x07b8f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b8fc: 910043FD  add      x29, sp, #0x10
//   0x07b900: D10F83FF  sub      sp, sp, #0x3e0
static inline uint64_t fde_func_0458_0x07b8f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b8f4ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0459 | PC: 0x07b9f8 | FDE: 0x19a750 | Size: 256 bytes
// Khung tháo gỡ #0459 | Địa chỉ PC: 0x07b9f8 | Địa chỉ FDE: 0x19a750 | Kích thước: 256 bytes
//   0x07b9f8: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x07b9fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ba00: 910043FD  add      x29, sp, #0x10
//   0x07ba04: D11883FF  sub      sp, sp, #0x620
static inline uint64_t fde_func_0459_0x07b9f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b9f8ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0460 | PC: 0x07bb04 | FDE: 0x19a790 | Size: 256 bytes
// Khung tháo gỡ #0460 | Địa chỉ PC: 0x07bb04 | Địa chỉ FDE: 0x19a790 | Kích thước: 256 bytes
//   0x07bb04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07bb08: 910003FD  mov      x29, sp
//   0x07bb0c: B0000B08  adrp     x8, #0x1dc000
//   0x07bb10: 910B6108  add      x8, x8, #0x2d8
static inline uint64_t fde_func_0460_0x07bb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bb04ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19a790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0461 | PC: 0x07bc20 | FDE: 0x19a7d0 | Size: 76 bytes
// Khung tháo gỡ #0461 | Địa chỉ PC: 0x07bc20 | Địa chỉ FDE: 0x19a7d0 | Kích thước: 76 bytes
//   0x07bc20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07bc24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07bc28: 910043FD  add      x29, sp, #0x10
//   0x07bc2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0461_0x07bc20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bc20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a7d0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0462 | PC: 0x07bc6c | FDE: 0x19a828 | Size: 52 bytes
// Khung tháo gỡ #0462 | Địa chỉ PC: 0x07bc6c | Địa chỉ FDE: 0x19a828 | Kích thước: 52 bytes
//   0x07bc6c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07bc70: A9402009  ldp      x9, x8, [x0]
//   0x07bc74: F9400800  ldr      x0, [x0, #0x10]
//   0x07bc78: D63F0120  blr      x9
static inline uint64_t fde_func_0462_0x07bc6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bc6cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x19a828ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0463 | PC: 0x07bca0 | FDE: 0x19a858 | Size: 48 bytes
// Khung tháo gỡ #0463 | Địa chỉ PC: 0x07bca0 | Địa chỉ FDE: 0x19a858 | Kích thước: 48 bytes
//   0x07bca0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bca4: AA0003F3  mov      x19, x0
//   0x07bca8: A9400008  ldp      x8, x0, [x0]
//   0x07bcac: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0463_0x07bca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bca0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a858ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0464 | PC: 0x07bcd0 | FDE: 0x19a888 | Size: 44 bytes
// Khung tháo gỡ #0464 | Địa chỉ PC: 0x07bcd0 | Địa chỉ FDE: 0x19a888 | Kích thước: 44 bytes
//   0x07bcd0: A9402002  ldp      x2, x8, [x0]
//   0x07bcd4: F9400801  ldr      x1, [x0, #0x10]
//   0x07bcd8: AA0803E0  mov      x0, x8
//   0x07bcdc: D61F0040  br       x2
static inline uint64_t fde_func_0464_0x07bcd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bcd0ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19a888ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0465 | PC: 0x07bcfc | FDE: 0x19a8b8 | Size: 48 bytes
// Khung tháo gỡ #0465 | Địa chỉ PC: 0x07bcfc | Địa chỉ FDE: 0x19a8b8 | Kích thước: 48 bytes
//   0x07bcfc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bd00: AA0003F3  mov      x19, x0
//   0x07bd04: A9400008  ldp      x8, x0, [x0]
//   0x07bd08: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0465_0x07bcfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bcfcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a8b8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0466 | PC: 0x07bd2c | FDE: 0x19a8e8 | Size: 48 bytes
// Khung tháo gỡ #0466 | Địa chỉ PC: 0x07bd2c | Địa chỉ FDE: 0x19a8e8 | Kích thước: 48 bytes
//   0x07bd2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bd30: AA0003F3  mov      x19, x0
//   0x07bd34: A9400008  ldp      x8, x0, [x0]
//   0x07bd38: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0466_0x07bd2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bd2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a8e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0467 | PC: 0x07bd5c | FDE: 0x19a918 | Size: 60 bytes
// Khung tháo gỡ #0467 | Địa chỉ PC: 0x07bd5c | Địa chỉ FDE: 0x19a918 | Kích thước: 60 bytes
//   0x07bd5c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bd60: AA0003F3  mov      x19, x0
//   0x07bd64: A9400008  ldp      x8, x0, [x0]
//   0x07bd68: D63F0100  blr      x8
static inline uint64_t fde_func_0467_0x07bd5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bd5cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a918ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0468 | PC: 0x07bd98 | FDE: 0x19a948 | Size: 16 bytes
// Khung tháo gỡ #0468 | Địa chỉ PC: 0x07bd98 | Địa chỉ FDE: 0x19a948 | Kích thước: 16 bytes
//   0x07bd98: A9400001  ldp      x1, x0, [x0]
//   0x07bd9c: D61F0020  br       x1
//   0x07bda0: A9400001  ldp      x1, x0, [x0]
//   0x07bda4: D61F0020  br       x1
static inline uint64_t fde_func_0468_0x07bd98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bd98ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x19a948ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0469 | PC: 0x07bda8 | FDE: 0x19a978 | Size: 64 bytes
// Khung tháo gỡ #0469 | Địa chỉ PC: 0x07bda8 | Địa chỉ FDE: 0x19a978 | Kích thước: 64 bytes
//   0x07bda8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bdac: AA0003F3  mov      x19, x0
//   0x07bdb0: A9400008  ldp      x8, x0, [x0]
//   0x07bdb4: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0469_0x07bda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bda8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a978ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0470 | PC: 0x07bde8 | FDE: 0x19a9a8 | Size: 72 bytes
// Khung tháo gỡ #0470 | Địa chỉ PC: 0x07bde8 | Địa chỉ FDE: 0x19a9a8 | Kích thước: 72 bytes
//   0x07bde8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bdec: AA0003F3  mov      x19, x0
//   0x07bdf0: A9400008  ldp      x8, x0, [x0]
//   0x07bdf4: D63F0100  blr      x8
static inline uint64_t fde_func_0470_0x07bde8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bde8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a9a8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0471 | PC: 0x07be30 | FDE: 0x19a9d8 | Size: 48 bytes
// Khung tháo gỡ #0471 | Địa chỉ PC: 0x07be30 | Địa chỉ FDE: 0x19a9d8 | Kích thước: 48 bytes
//   0x07be30: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07be34: AA0003F3  mov      x19, x0
//   0x07be38: A9400008  ldp      x8, x0, [x0]
//   0x07be3c: D63F0100  blr      x8
static inline uint64_t fde_func_0471_0x07be30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07be30ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19a9d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0472 | PC: 0x07be60 | FDE: 0x19aa08 | Size: 40 bytes
// Khung tháo gỡ #0472 | Địa chỉ PC: 0x07be60 | Địa chỉ FDE: 0x19aa08 | Kích thước: 40 bytes
//   0x07be60: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07be64: AA0003F3  mov      x19, x0
//   0x07be68: A9400008  ldp      x8, x0, [x0]
//   0x07be6c: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0472_0x07be60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07be60ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19aa08ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0473 | PC: 0x07be88 | FDE: 0x19aa38 | Size: 44 bytes
// Khung tháo gỡ #0473 | Địa chỉ PC: 0x07be88 | Địa chỉ FDE: 0x19aa38 | Kích thước: 44 bytes
//   0x07be88: A9402002  ldp      x2, x8, [x0]
//   0x07be8c: F9400801  ldr      x1, [x0, #0x10]
//   0x07be90: AA0803E0  mov      x0, x8
//   0x07be94: D61F0040  br       x2
static inline uint64_t fde_func_0473_0x07be88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07be88ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19aa38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0474 | PC: 0x07beb4 | FDE: 0x19aa68 | Size: 60 bytes
// Khung tháo gỡ #0474 | Địa chỉ PC: 0x07beb4 | Địa chỉ FDE: 0x19aa68 | Kích thước: 60 bytes
//   0x07beb4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07beb8: AA0003F3  mov      x19, x0
//   0x07bebc: A9400008  ldp      x8, x0, [x0]
//   0x07bec0: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0474_0x07beb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07beb4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19aa68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0475 | PC: 0x07bef0 | FDE: 0x19aa98 | Size: 68 bytes
// Khung tháo gỡ #0475 | Địa chỉ PC: 0x07bef0 | Địa chỉ FDE: 0x19aa98 | Kích thước: 68 bytes
//   0x07bef0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bef4: AA0003F3  mov      x19, x0
//   0x07bef8: A9400008  ldp      x8, x0, [x0]
//   0x07befc: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0475_0x07bef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bef0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19aa98ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0476 | PC: 0x07bf34 | FDE: 0x19aac8 | Size: 164 bytes
// Khung tháo gỡ #0476 | Địa chỉ PC: 0x07bf34 | Địa chỉ FDE: 0x19aac8 | Kích thước: 164 bytes
//   0x07bf34: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07bf38: AA0003F3  mov      x19, x0
//   0x07bf3c: A9400008  ldp      x8, x0, [x0]
//   0x07bf40: D63F0100  blr      x8
static inline uint64_t fde_func_0476_0x07bf34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bf34ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19aac8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0477 | PC: 0x07bfd8 | FDE: 0x19ab58 | Size: 28 bytes
// Khung tháo gỡ #0477 | Địa chỉ PC: 0x07bfd8 | Địa chỉ FDE: 0x19ab58 | Kích thước: 28 bytes
//   0x07bfd8: A9000000  stp      x0, x0, [x0]
//   0x07bfdc: F900081F  str      xzr, [x0, #0x10]
//   0x07bfe0: D65F03C0  ret      
//   0x07bfe4: 9103D408  add      x8, x0, #0xf5
static inline uint64_t fde_func_0477_0x07bfd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bfd8ULL ^ (static_cast<uint64_t>(0xa9000000ULL) << 13);
    acc = (acc + a1 + 0xf900081fULL) ^ 0x19ab58ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0478 | PC: 0x07bff4 | FDE: 0x19ab88 | Size: 52 bytes
// Khung tháo gỡ #0478 | Địa chỉ PC: 0x07bff4 | Địa chỉ FDE: 0x19ab88 | Kích thước: 52 bytes
//   0x07bff4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07bff8: 910003FD  mov      x29, sp
//   0x07bffc: 52800028  mov      w8, #1
//   0x07c000: F9000001  str      x1, [x0]
static inline uint64_t fde_func_0478_0x07bff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bff4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19ab88ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0479 | PC: 0x07c028 | FDE: 0x19abc0 | Size: 148 bytes
// Khung tháo gỡ #0479 | Địa chỉ PC: 0x07c028 | Địa chỉ FDE: 0x19abc0 | Kích thước: 148 bytes
//   0x07c028: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07c02c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07c030: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07c034: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0479_0x07c028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c028ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19abc0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0480 | PC: 0x07c0bc | FDE: 0x19ac00 | Size: 256 bytes
// Khung tháo gỡ #0480 | Địa chỉ PC: 0x07c0bc | Địa chỉ FDE: 0x19ac00 | Kích thước: 256 bytes
//   0x07c0bc: 91002000  add      x0, x0, #8
//   0x07c0c0: D65F03C0  ret      
//   0x07c0c4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x07c0c8: A9015FF8  stp      x24, x23, [sp, #0x10]
static inline uint64_t fde_func_0480_0x07c0bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c0bcULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19ac00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0481 | PC: 0x07c218 | FDE: 0x19ac40 | Size: 16 bytes
// Khung tháo gỡ #0481 | Địa chỉ PC: 0x07c218 | Địa chỉ FDE: 0x19ac40 | Kích thước: 16 bytes
//   0x07c218: D65F03C0  ret      
//   0x07c21c: F9400028  ldr      x8, [x1]
//   0x07c220: F9000008  str      x8, [x0]
//   0x07c224: D65F03C0  ret      
static inline uint64_t fde_func_0481_0x07c218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c218ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x19ac40ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0482 | PC: 0x07c228 | FDE: 0x19ac70 | Size: 20 bytes
// Khung tháo gỡ #0482 | Địa chỉ PC: 0x07c228 | Địa chỉ FDE: 0x19ac70 | Kích thước: 20 bytes
//   0x07c228: F9400008  ldr      x8, [x0]
//   0x07c22c: 91008100  add      x0, x8, #0x20
//   0x07c230: D65F03C0  ret      
//   0x07c234: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0482_0x07c228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c228ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91008100ULL) ^ 0x19ac70ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0483 | PC: 0x07c23c | FDE: 0x19aca0 | Size: 120 bytes
// Khung tháo gỡ #0483 | Địa chỉ PC: 0x07c23c | Địa chỉ FDE: 0x19aca0 | Kích thước: 120 bytes
//   0x07c23c: 91002000  add      x0, x0, #8
//   0x07c240: D65F03C0  ret      
//   0x07c244: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07c248: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0483_0x07c23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c23cULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19aca0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0484 | PC: 0x07c2b4 | FDE: 0x19acd8 | Size: 24 bytes
// Khung tháo gỡ #0484 | Địa chỉ PC: 0x07c2b4 | Địa chỉ FDE: 0x19acd8 | Kích thước: 24 bytes
//   0x07c2b4: F9400808  ldr      x8, [x0, #0x10]
//   0x07c2b8: F100011F  cmp      x8, #0
//   0x07c2bc: 1A9F17E0  cset     w0, eq
//   0x07c2c0: D65F03C0  ret      
static inline uint64_t fde_func_0484_0x07c2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c2b4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x19acd8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0485 | PC: 0x07c2cc | FDE: 0x19ad08 | Size: 32 bytes
// Khung tháo gỡ #0485 | Địa chỉ PC: 0x07c2cc | Địa chỉ FDE: 0x19ad08 | Kích thước: 32 bytes
//   0x07c2cc: F9400008  ldr      x8, [x0]
//   0x07c2d0: F9400029  ldr      x9, [x1]
//   0x07c2d4: EB09011F  cmp      x8, x9
//   0x07c2d8: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_0485_0x07c2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c2ccULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400029ULL) ^ 0x19ad08ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0486 | PC: 0x07c2ec | FDE: 0x19ad38 | Size: 256 bytes
// Khung tháo gỡ #0486 | Địa chỉ PC: 0x07c2ec | Địa chỉ FDE: 0x19ad38 | Kích thước: 256 bytes
//   0x07c2ec: B9403000  ldr      w0, [x0, #0x30]
//   0x07c2f0: D65F03C0  ret      
//   0x07c2f4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07c2f8: A90157F6  stp      x22, x21, [sp, #0x10]
static inline uint64_t fde_func_0486_0x07c2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c2ecULL ^ (static_cast<uint64_t>(0xb9403000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19ad38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0487 | PC: 0x07c538 | FDE: 0x19ad78 | Size: 256 bytes
// Khung tháo gỡ #0487 | Địa chỉ PC: 0x07c538 | Địa chỉ FDE: 0x19ad78 | Kích thước: 256 bytes
//   0x07c538: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c53c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c540: 910043FD  add      x29, sp, #0x10
//   0x07c544: F9400020  ldr      x0, [x1]
static inline uint64_t fde_func_0487_0x07c538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c538ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19ad78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0488 | PC: 0x07c668 | FDE: 0x19adc0 | Size: 52 bytes
// Khung tháo gỡ #0488 | Địa chỉ PC: 0x07c668 | Địa chỉ FDE: 0x19adc0 | Kích thước: 52 bytes
//   0x07c668: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07c66c: 910003FD  mov      x29, sp
//   0x07c670: B8008401  str      w1, [x0], #8
//   0x07c674: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_0488_0x07c668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c668ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19adc0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0489 | PC: 0x07c69c | FDE: 0x19ae00 | Size: 48 bytes
// Khung tháo gỡ #0489 | Địa chỉ PC: 0x07c69c | Địa chỉ FDE: 0x19ae00 | Kích thước: 48 bytes
//   0x07c69c: F9400008  ldr      x8, [x0]
//   0x07c6a0: F9400508  ldr      x8, [x8, #8]
//   0x07c6a4: F9000008  str      x8, [x0]
//   0x07c6a8: D65F03C0  ret      
static inline uint64_t fde_func_0489_0x07c69c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c69cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400508ULL) ^ 0x19ae00ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0490 | PC: 0x07c6cc | FDE: 0x19ae38 | Size: 256 bytes
// Khung tháo gỡ #0490 | Địa chỉ PC: 0x07c6cc | Địa chỉ FDE: 0x19ae38 | Kích thước: 256 bytes
//   0x07c6cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07c6d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c6d4: 910043FD  add      x29, sp, #0x10
//   0x07c6d8: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0490_0x07c6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19ae38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0491 | PC: 0x07cbd8 | FDE: 0x19ae80 | Size: 256 bytes
// Khung tháo gỡ #0491 | Địa chỉ PC: 0x07cbd8 | Địa chỉ FDE: 0x19ae80 | Kích thước: 256 bytes
//   0x07cbd8: D10183FF  sub      sp, sp, #0x60
//   0x07cbdc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07cbe0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07cbe4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0491_0x07cbd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cbd8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x19ae80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0492 | PC: 0x07d11c | FDE: 0x19aed8 | Size: 256 bytes
// Khung tháo gỡ #0492 | Địa chỉ PC: 0x07d11c | Địa chỉ FDE: 0x19aed8 | Kích thước: 256 bytes
//   0x07d11c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07d120: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07d124: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07d128: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0492_0x07d11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d11cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19aed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0493 | PC: 0x07d438 | FDE: 0x19af28 | Size: 256 bytes
// Khung tháo gỡ #0493 | Địa chỉ PC: 0x07d438 | Địa chỉ FDE: 0x19af28 | Kích thước: 256 bytes
//   0x07d438: D10183FF  sub      sp, sp, #0x60
//   0x07d43c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07d440: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07d444: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0493_0x07d438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d438ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x19af28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0494 | PC: 0x07d644 | FDE: 0x19af78 | Size: 136 bytes
// Khung tháo gỡ #0494 | Địa chỉ PC: 0x07d644 | Địa chỉ FDE: 0x19af78 | Kích thước: 136 bytes
//   0x07d644: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07d648: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d64c: 910043FD  add      x29, sp, #0x10
//   0x07d650: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0494_0x07d644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d644ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19af78ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0495 | PC: 0x07d6cc | FDE: 0x19afb8 | Size: 136 bytes
// Khung tháo gỡ #0495 | Địa chỉ PC: 0x07d6cc | Địa chỉ FDE: 0x19afb8 | Kích thước: 136 bytes
//   0x07d6cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d6d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d6d4: 910043FD  add      x29, sp, #0x10
//   0x07d6d8: 9102F014  add      x20, x0, #0xbc
static inline uint64_t fde_func_0495_0x07d6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d6ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19afb8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0496 | PC: 0x07d754 | FDE: 0x19b000 | Size: 72 bytes
// Khung tháo gỡ #0496 | Địa chỉ PC: 0x07d754 | Địa chỉ FDE: 0x19b000 | Kích thước: 72 bytes
//   0x07d754: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d758: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d75c: 910043FD  add      x29, sp, #0x10
//   0x07d760: 9102F014  add      x20, x0, #0xbc
static inline uint64_t fde_func_0496_0x07d754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d754ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19b000ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0497 | PC: 0x07d79c | FDE: 0x19b038 | Size: 32 bytes
// Khung tháo gỡ #0497 | Địa chỉ PC: 0x07d79c | Địa chỉ FDE: 0x19b038 | Kích thước: 32 bytes
//   0x07d79c: 9103D008  add      x8, x0, #0xf4
//   0x07d7a0: 08DFFD08  ldarb    w8, [x8]
//   0x07d7a4: 12000100  and      w0, w8, #1
//   0x07d7a8: D65F03C0  ret      
static inline uint64_t fde_func_0497_0x07d79c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d79cULL ^ (static_cast<uint64_t>(0x9103d008ULL) << 13);
    acc = (acc + a1 + 0x08dffd08ULL) ^ 0x19b038ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0498 | PC: 0x07d7bc | FDE: 0x19b068 | Size: 256 bytes
// Khung tháo gỡ #0498 | Địa chỉ PC: 0x07d7bc | Địa chỉ FDE: 0x19b068 | Kích thước: 256 bytes
//   0x07d7bc: 91002008  add      x8, x0, #8
//   0x07d7c0: EB01011F  cmp      x8, x1
//   0x07d7c4: 540000E0  b.eq     #0x7d7e0
//   0x07d7c8: F9400089  ldr      x9, [x4]
static inline uint64_t fde_func_0498_0x07d7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d7bcULL ^ (static_cast<uint64_t>(0x91002008ULL) << 13);
    acc = (acc + a1 + 0xeb01011fULL) ^ 0x19b068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0499 | PC: 0x07d9f8 | FDE: 0x19b0a0 | Size: 256 bytes
// Khung tháo gỡ #0499 | Địa chỉ PC: 0x07d9f8 | Địa chỉ FDE: 0x19b0a0 | Kích thước: 256 bytes
//   0x07d9f8: B40001E1  cbz      x1, #0x7da34
//   0x07d9fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07da00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07da04: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0499_0x07d9f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d9f8ULL ^ (static_cast<uint64_t>(0xb40001e1ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x19b0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0500 | PC: 0x07db78 | FDE: 0x19b108 | Size: 28 bytes
// Khung tháo gỡ #0500 | Địa chỉ PC: 0x07db78 | Địa chỉ FDE: 0x19b108 | Kích thước: 28 bytes
//   0x07db78: AA1E03E1  mov      x1, x30
//   0x07db7c: 8B000021  add      x1, x1, x0
//   0x07db80: AA0103FE  mov      x30, x1
//   0x07db84: D65F03C0  ret      
static inline uint64_t fde_func_0500_0x07db78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07db78ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x19b108ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0501 | PC: 0x07db94 | FDE: 0x19b138 | Size: 32 bytes
// Khung tháo gỡ #0501 | Địa chỉ PC: 0x07db94 | Địa chỉ FDE: 0x19b138 | Kích thước: 32 bytes
//   0x07db94: A9402002  ldp      x2, x8, [x0]
//   0x07db98: 39404001  ldrb     w1, [x0, #0x10]
//   0x07db9c: AA0803E0  mov      x0, x8
//   0x07dba0: D61F0040  br       x2
static inline uint64_t fde_func_0501_0x07db94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07db94ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0x39404001ULL) ^ 0x19b138ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0502 | PC: 0x07dbb4 | FDE: 0x19b168 | Size: 40 bytes
// Khung tháo gỡ #0502 | Địa chỉ PC: 0x07dbb4 | Địa chỉ FDE: 0x19b168 | Kích thước: 40 bytes
//   0x07dbb4: A9400001  ldp      x1, x0, [x0]
//   0x07dbb8: D61F0020  br       x1
//   0x07dbbc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dbc0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0502_0x07dbb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dbb4ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x19b168ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0503 | PC: 0x07dbdc | FDE: 0x19b198 | Size: 48 bytes
// Khung tháo gỡ #0503 | Địa chỉ PC: 0x07dbdc | Địa chỉ FDE: 0x19b198 | Kích thước: 48 bytes
//   0x07dbdc: A9402002  ldp      x2, x8, [x0]
//   0x07dbe0: F9400801  ldr      x1, [x0, #0x10]
//   0x07dbe4: AA0803E0  mov      x0, x8
//   0x07dbe8: D61F0040  br       x2
static inline uint64_t fde_func_0503_0x07dbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dbdcULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19b198ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0504 | PC: 0x07dc0c | FDE: 0x19b1c8 | Size: 60 bytes
// Khung tháo gỡ #0504 | Địa chỉ PC: 0x07dc0c | Địa chỉ FDE: 0x19b1c8 | Kích thước: 60 bytes
//   0x07dc0c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dc10: AA0003F3  mov      x19, x0
//   0x07dc14: A9400008  ldp      x8, x0, [x0]
//   0x07dc18: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0504_0x07dc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dc0cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b1c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0505 | PC: 0x07dc48 | FDE: 0x19b1f8 | Size: 64 bytes
// Khung tháo gỡ #0505 | Địa chỉ PC: 0x07dc48 | Địa chỉ FDE: 0x19b1f8 | Kích thước: 64 bytes
//   0x07dc48: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dc4c: AA0003F3  mov      x19, x0
//   0x07dc50: A9400008  ldp      x8, x0, [x0]
//   0x07dc54: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0505_0x07dc48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dc48ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b1f8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0506 | PC: 0x07dc88 | FDE: 0x19b228 | Size: 44 bytes
// Khung tháo gỡ #0506 | Địa chỉ PC: 0x07dc88 | Địa chỉ FDE: 0x19b228 | Kích thước: 44 bytes
//   0x07dc88: A9402002  ldp      x2, x8, [x0]
//   0x07dc8c: F9400801  ldr      x1, [x0, #0x10]
//   0x07dc90: AA0803E0  mov      x0, x8
//   0x07dc94: D61F0040  br       x2
static inline uint64_t fde_func_0506_0x07dc88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dc88ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19b228ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0507 | PC: 0x07dcb4 | FDE: 0x19b258 | Size: 64 bytes
// Khung tháo gỡ #0507 | Địa chỉ PC: 0x07dcb4 | Địa chỉ FDE: 0x19b258 | Kích thước: 64 bytes
//   0x07dcb4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dcb8: AA0003F3  mov      x19, x0
//   0x07dcbc: A9400008  ldp      x8, x0, [x0]
//   0x07dcc0: D63F0100  blr      x8
static inline uint64_t fde_func_0507_0x07dcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dcb4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b258ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0508 | PC: 0x07dcf4 | FDE: 0x19b288 | Size: 44 bytes
// Khung tháo gỡ #0508 | Địa chỉ PC: 0x07dcf4 | Địa chỉ FDE: 0x19b288 | Kích thước: 44 bytes
//   0x07dcf4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dcf8: AA0003F3  mov      x19, x0
//   0x07dcfc: A9400008  ldp      x8, x0, [x0]
//   0x07dd00: D63F0100  blr      x8
static inline uint64_t fde_func_0508_0x07dcf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dcf4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b288ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0509 | PC: 0x07dd20 | FDE: 0x19b2b8 | Size: 68 bytes
// Khung tháo gỡ #0509 | Địa chỉ PC: 0x07dd20 | Địa chỉ FDE: 0x19b2b8 | Kích thước: 68 bytes
//   0x07dd20: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dd24: AA0003F3  mov      x19, x0
//   0x07dd28: A9400008  ldp      x8, x0, [x0]
//   0x07dd2c: D63F0100  blr      x8
static inline uint64_t fde_func_0509_0x07dd20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd20ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b2b8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0510 | PC: 0x07dd64 | FDE: 0x19b2e8 | Size: 56 bytes
// Khung tháo gỡ #0510 | Địa chỉ PC: 0x07dd64 | Địa chỉ FDE: 0x19b2e8 | Kích thước: 56 bytes
//   0x07dd64: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dd68: AA0003F3  mov      x19, x0
//   0x07dd6c: A9400008  ldp      x8, x0, [x0]
//   0x07dd70: D63F0100  blr      x8
static inline uint64_t fde_func_0510_0x07dd64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd64ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b2e8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0511 | PC: 0x07dd9c | FDE: 0x19b318 | Size: 56 bytes
// Khung tháo gỡ #0511 | Địa chỉ PC: 0x07dd9c | Địa chỉ FDE: 0x19b318 | Kích thước: 56 bytes
//   0x07dd9c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07dda0: AA0003F3  mov      x19, x0
//   0x07dda4: A9400008  ldp      x8, x0, [x0]
//   0x07dda8: D63F0100  blr      x8
static inline uint64_t fde_func_0511_0x07dd9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd9cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b318ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0512 | PC: 0x07ddd4 | FDE: 0x19b348 | Size: 36 bytes
// Khung tháo gỡ #0512 | Địa chỉ PC: 0x07ddd4 | Địa chỉ FDE: 0x19b348 | Kích thước: 36 bytes
//   0x07ddd4: A9402003  ldp      x3, x8, [x0]
//   0x07ddd8: F9400C02  ldr      x2, [x0, #0x18]
//   0x07dddc: 39404001  ldrb     w1, [x0, #0x10]
//   0x07dde0: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0512_0x07ddd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ddd4ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400c02ULL) ^ 0x19b348ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0513 | PC: 0x07ddf8 | FDE: 0x19b378 | Size: 52 bytes
// Khung tháo gỡ #0513 | Địa chỉ PC: 0x07ddf8 | Địa chỉ FDE: 0x19b378 | Kích thước: 52 bytes
//   0x07ddf8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07ddfc: F9400809  ldr      x9, [x0, #0x10]
//   0x07de00: A940200A  ldp      x10, x8, [x0]
//   0x07de04: B9401801  ldr      w1, [x0, #0x18]
static inline uint64_t fde_func_0513_0x07ddf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ddf8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x19b378ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0514 | PC: 0x07de2c | FDE: 0x19b3a8 | Size: 48 bytes
// Khung tháo gỡ #0514 | Địa chỉ PC: 0x07de2c | Địa chỉ FDE: 0x19b3a8 | Kích thước: 48 bytes
//   0x07de2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07de30: AA0003F3  mov      x19, x0
//   0x07de34: A9400008  ldp      x8, x0, [x0]
//   0x07de38: D63F0100  blr      x8
static inline uint64_t fde_func_0514_0x07de2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07de2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b3a8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0515 | PC: 0x07de5c | FDE: 0x19b3d8 | Size: 40 bytes
// Khung tháo gỡ #0515 | Địa chỉ PC: 0x07de5c | Địa chỉ FDE: 0x19b3d8 | Kích thước: 40 bytes
//   0x07de5c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07de60: AA0003F3  mov      x19, x0
//   0x07de64: A9400008  ldp      x8, x0, [x0]
//   0x07de68: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0515_0x07de5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07de5cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b3d8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0516 | PC: 0x07de84 | FDE: 0x19b408 | Size: 36 bytes
// Khung tháo gỡ #0516 | Địa chỉ PC: 0x07de84 | Địa chỉ FDE: 0x19b408 | Kích thước: 36 bytes
//   0x07de84: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x07de88: AA0003F3  mov      x19, x0
//   0x07de8c: A9400008  ldp      x8, x0, [x0]
//   0x07de90: D63F0100  blr      x8
static inline uint64_t fde_func_0516_0x07de84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07de84ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19b408ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0517 | PC: 0x07dea8 | FDE: 0x19b438 | Size: 212 bytes
// Khung tháo gỡ #0517 | Địa chỉ PC: 0x07dea8 | Địa chỉ FDE: 0x19b438 | Kích thước: 212 bytes
//   0x07dea8: AA0003E2  mov      x2, x0
//   0x07deac: AA0103E0  mov      x0, x1
//   0x07deb0: D61F0040  br       x2
//   0x07deb4: D10183FF  sub      sp, sp, #0x60
static inline uint64_t fde_func_0517_0x07dea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dea8ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x19b438ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0518 | PC: 0x07df7c | FDE: 0x19b4c8 | Size: 256 bytes
// Khung tháo gỡ #0518 | Địa chỉ PC: 0x07df7c | Địa chỉ FDE: 0x19b4c8 | Kích thước: 256 bytes
//   0x07df7c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07df80: 910003FD  mov      x29, sp
//   0x07df84: D10043FF  sub      sp, sp, #0x10
//   0x07df88: A9007BE9  stp      x9, x30, [sp]
static inline uint64_t fde_func_0518_0x07df7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df7cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19b4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0519 | PC: 0x07e1d8 | FDE: 0x19b508 | Size: 256 bytes
// Khung tháo gỡ #0519 | Địa chỉ PC: 0x07e1d8 | Địa chỉ FDE: 0x19b508 | Kích thước: 256 bytes
//   0x07e1d8: D10143FF  sub      sp, sp, #0x50
//   0x07e1dc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07e1e0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x07e1e4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0519_0x07e1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e1d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19b508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0520 | PC: 0x07e6fc | FDE: 0x19b558 | Size: 256 bytes
// Khung tháo gỡ #0520 | Địa chỉ PC: 0x07e6fc | Địa chỉ FDE: 0x19b558 | Kích thước: 256 bytes
//   0x07e6fc: 52800040  mov      w0, #2
//   0x07e700: D65F03C0  ret      
//   0x07e704: D10183FF  sub      sp, sp, #0x60
//   0x07e708: A9025FF8  stp      x24, x23, [sp, #0x20]
static inline uint64_t fde_func_0520_0x07e6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e6fcULL ^ (static_cast<uint64_t>(0x52800040ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19b558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0521 | PC: 0x07e880 | FDE: 0x19b598 | Size: 256 bytes
// Khung tháo gỡ #0521 | Địa chỉ PC: 0x07e880 | Địa chỉ FDE: 0x19b598 | Kích thước: 256 bytes
//   0x07e880: D10343FF  sub      sp, sp, #0xd0
//   0x07e884: F9003BFB  str      x27, [sp, #0x70]
//   0x07e888: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x07e88c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0521_0x07e880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e880ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x19b598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0522 | PC: 0x07ef60 | FDE: 0x19b5f8 | Size: 184 bytes
// Khung tháo gỡ #0522 | Địa chỉ PC: 0x07ef60 | Địa chỉ FDE: 0x19b5f8 | Kích thước: 184 bytes
//   0x07ef60: D10483FF  sub      sp, sp, #0x120
//   0x07ef64: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x07ef68: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x07ef6c: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_0522_0x07ef60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ef60ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x19b5f8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0523 | PC: 0x07f018 | FDE: 0x19b6a8 | Size: 232 bytes
// Khung tháo gỡ #0523 | Địa chỉ PC: 0x07f018 | Địa chỉ FDE: 0x19b6a8 | Kích thước: 232 bytes
//   0x07f018: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07f01c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f024: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0523_0x07f018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f018ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19b6a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0524 | PC: 0x07f100 | FDE: 0x19b6f0 | Size: 256 bytes
// Khung tháo gỡ #0524 | Địa chỉ PC: 0x07f100 | Địa chỉ FDE: 0x19b6f0 | Kích thước: 256 bytes
//   0x07f100: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f104: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f108: 910043FD  add      x29, sp, #0x10
//   0x07f10c: 90000008  adrp     x8, #0x7f000
static inline uint64_t fde_func_0524_0x07f100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f100ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19b6f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x07f2d0 | FDE: 0x19b730 | Size: 256 bytes
// Khung tháo gỡ #0525 | Địa chỉ PC: 0x07f2d0 | Địa chỉ FDE: 0x19b730 | Kích thước: 256 bytes
//   0x07f2d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07f2d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f2d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f2dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0525_0x07f2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f2d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19b730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0526 | PC: 0x07f3dc | FDE: 0x19b770 | Size: 36 bytes
// Khung tháo gỡ #0526 | Địa chỉ PC: 0x07f3dc | Địa chỉ FDE: 0x19b770 | Kích thước: 36 bytes
//   0x07f3dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07f3e0: 910003FD  mov      x29, sp
//   0x07f3e4: 91012001  add      x1, x0, #0x48
//   0x07f3e8: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0526_0x07f3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f3dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19b770ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0527 | PC: 0x07f400 | FDE: 0x19b7a8 | Size: 16 bytes
// Khung tháo gỡ #0527 | Địa chỉ PC: 0x07f400 | Địa chỉ FDE: 0x19b7a8 | Kích thước: 16 bytes
//   0x07f400: B9406000  ldr      w0, [x0, #0x60]
//   0x07f404: D65F03C0  ret      
//   0x07f408: F9002C01  str      x1, [x0, #0x58]
//   0x07f40c: D65F03C0  ret      
static inline uint64_t fde_func_0527_0x07f400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f400ULL ^ (static_cast<uint64_t>(0xb9406000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19b7a8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0528 | PC: 0x07f410 | FDE: 0x19b7d8 | Size: 28 bytes
// Khung tháo gỡ #0528 | Địa chỉ PC: 0x07f410 | Địa chỉ FDE: 0x19b7d8 | Kích thước: 28 bytes
//   0x07f410: F9402C00  ldr      x0, [x0, #0x58]
//   0x07f414: D65F03C0  ret      
//   0x07f418: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07f41c: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0528_0x07f410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f410ULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19b7d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0529 | PC: 0x07f42c | FDE: 0x19b810 | Size: 256 bytes
// Khung tháo gỡ #0529 | Địa chỉ PC: 0x07f42c | Địa chỉ FDE: 0x19b810 | Kích thước: 256 bytes
//   0x07f42c: D101C3FF  sub      sp, sp, #0x70
//   0x07f430: F90023F5  str      x21, [sp, #0x40]
//   0x07f434: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x07f438: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0529_0x07f42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f42cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x19b810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0530 | PC: 0x07f74c | FDE: 0x19b860 | Size: 80 bytes
// Khung tháo gỡ #0530 | Địa chỉ PC: 0x07f74c | Địa chỉ FDE: 0x19b860 | Kích thước: 80 bytes
//   0x07f74c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07f750: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f754: 910043FD  add      x29, sp, #0x10
//   0x07f758: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0530_0x07f74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f74cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19b860ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0531 | PC: 0x07f79c | FDE: 0x19b8a0 | Size: 28 bytes
// Khung tháo gỡ #0531 | Địa chỉ PC: 0x07f79c | Địa chỉ FDE: 0x19b8a0 | Kích thước: 28 bytes
//   0x07f79c: B9404000  ldr      w0, [x0, #0x40]
//   0x07f7a0: D65F03C0  ret      
//   0x07f7a4: AA1E03E4  mov      x4, x30
//   0x07f7a8: 8B000084  add      x4, x4, x0
static inline uint64_t fde_func_0531_0x07f79c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f79cULL ^ (static_cast<uint64_t>(0xb9404000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19b8a0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0532 | PC: 0x07f7b8 | FDE: 0x19b948 | Size: 184 bytes
// Khung tháo gỡ #0532 | Địa chỉ PC: 0x07f7b8 | Địa chỉ FDE: 0x19b948 | Kích thước: 184 bytes
//   0x07f7b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07f7bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f7c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f7c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0532_0x07f7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f7b8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19b948ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0533 | PC: 0x07f870 | FDE: 0x19b990 | Size: 148 bytes
// Khung tháo gỡ #0533 | Địa chỉ PC: 0x07f870 | Địa chỉ FDE: 0x19b990 | Kích thước: 148 bytes
//   0x07f870: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f874: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f878: 910043FD  add      x29, sp, #0x10
//   0x07f87c: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0533_0x07f870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f870ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19b990ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0534 | PC: 0x07f904 | FDE: 0x19b9d0 | Size: 256 bytes
// Khung tháo gỡ #0534 | Địa chỉ PC: 0x07f904 | Địa chỉ FDE: 0x19b9d0 | Kích thước: 256 bytes
//   0x07f904: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x07f908: 910003FD  mov      x29, sp
//   0x07f90c: 94000003  bl       #0x7f918
//   0x07f910: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0534_0x07f904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f904ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19b9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0535 | PC: 0x07fb50 | FDE: 0x19ba10 | Size: 256 bytes
// Khung tháo gỡ #0535 | Địa chỉ PC: 0x07fb50 | Địa chỉ FDE: 0x19ba10 | Kích thước: 256 bytes
//   0x07fb50: D10243FF  sub      sp, sp, #0x90
//   0x07fb54: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x07fb58: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x07fb5c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0535_0x07fb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fb50ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x19ba10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0536 | PC: 0x07fcc4 | FDE: 0x19ba78 | Size: 52 bytes
// Khung tháo gỡ #0536 | Địa chỉ PC: 0x07fcc4 | Địa chỉ FDE: 0x19ba78 | Kích thước: 52 bytes
//   0x07fcc4: AA1E03E1  mov      x1, x30
//   0x07fcc8: 8B000021  add      x1, x1, x0
//   0x07fccc: AA0103FE  mov      x30, x1
//   0x07fcd0: D65F03C0  ret      
static inline uint64_t fde_func_0536_0x07fcc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fcc4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x19ba78ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0537 | PC: 0x07fcf8 | FDE: 0x19bb08 | Size: 256 bytes
// Khung tháo gỡ #0537 | Địa chỉ PC: 0x07fcf8 | Địa chỉ FDE: 0x19bb08 | Kích thước: 256 bytes
//   0x07fcf8: D105C3FF  sub      sp, sp, #0x170
//   0x07fcfc: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x07fd00: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x07fd04: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_0537_0x07fcf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fcf8ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x19bb08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0538 | PC: 0x0809f0 | FDE: 0x19bbc8 | Size: 220 bytes
// Khung tháo gỡ #0538 | Địa chỉ PC: 0x0809f0 | Địa chỉ FDE: 0x19bbc8 | Kích thước: 220 bytes
//   0x0809f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0809f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0809f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0809fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0538_0x0809f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0809f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19bbc8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0539 | PC: 0x080acc | FDE: 0x19bc08 | Size: 256 bytes
// Khung tháo gỡ #0539 | Địa chỉ PC: 0x080acc | Địa chỉ FDE: 0x19bc08 | Kích thước: 256 bytes
//   0x080acc: D10283FF  sub      sp, sp, #0xa0
//   0x080ad0: FD0033E8  str      d8, [sp, #0x60]
//   0x080ad4: F90037F7  str      x23, [sp, #0x68]
//   0x080ad8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0539_0x080acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080accULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd0033e8ULL) ^ 0x19bc08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0540 | PC: 0x080e74 | FDE: 0x19bc58 | Size: 256 bytes
// Khung tháo gỡ #0540 | Địa chỉ PC: 0x080e74 | Địa chỉ FDE: 0x19bc58 | Kích thước: 256 bytes
//   0x080e74: D10383FF  sub      sp, sp, #0xe0
//   0x080e78: F90053F7  str      x23, [sp, #0xa0]
//   0x080e7c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x080e80: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0540_0x080e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080e74ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x19bc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0541 | PC: 0x081688 | FDE: 0x19bcb0 | Size: 256 bytes
// Khung tháo gỡ #0541 | Địa chỉ PC: 0x081688 | Địa chỉ FDE: 0x19bcb0 | Kích thước: 256 bytes
//   0x081688: D10383FF  sub      sp, sp, #0xe0
//   0x08168c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x081690: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x081694: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0541_0x081688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081688ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b57f6ULL) ^ 0x19bcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0542 | PC: 0x081968 | FDE: 0x19bcf0 | Size: 256 bytes
// Khung tháo gỡ #0542 | Địa chỉ PC: 0x081968 | Địa chỉ FDE: 0x19bcf0 | Kích thước: 256 bytes
//   0x081968: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08196c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x081970: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x081974: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0542_0x081968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081968ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19bcf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0543 | PC: 0x0832ac | FDE: 0x19bd48 | Size: 256 bytes
// Khung tháo gỡ #0543 | Địa chỉ PC: 0x0832ac | Địa chỉ FDE: 0x19bd48 | Kích thước: 256 bytes
//   0x0832ac: D10143FF  sub      sp, sp, #0x50
//   0x0832b0: F90013F5  str      x21, [sp, #0x20]
//   0x0832b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0832b8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0543_0x0832ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0832acULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x19bd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0544 | PC: 0x087c4c | FDE: 0x19bd98 | Size: 256 bytes
// Khung tháo gỡ #0544 | Địa chỉ PC: 0x087c4c | Địa chỉ FDE: 0x19bd98 | Kích thước: 256 bytes
//   0x087c4c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x087c50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x087c54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x087c58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0544_0x087c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087c4cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19bd98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0545 | PC: 0x087e60 | FDE: 0x19bde0 | Size: 256 bytes
// Khung tháo gỡ #0545 | Địa chỉ PC: 0x087e60 | Địa chỉ FDE: 0x19bde0 | Kích thước: 256 bytes
//   0x087e60: D103C3FF  sub      sp, sp, #0xf0
//   0x087e64: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x087e68: 910383FD  add      x29, sp, #0xe0
//   0x087e6c: A93A8FA2  stp      x2, x3, [x29, #-0x58]
static inline uint64_t fde_func_0545_0x087e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087e60ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90e7bfdULL) ^ 0x19bde0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0546 | PC: 0x087f80 | FDE: 0x19be20 | Size: 256 bytes
// Khung tháo gỡ #0546 | Địa chỉ PC: 0x087f80 | Địa chỉ FDE: 0x19be20 | Kích thước: 256 bytes
//   0x087f80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x087f84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087f88: 910043FD  add      x29, sp, #0x10
//   0x087f8c: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0546_0x087f80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087f80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19be20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0547 | PC: 0x088188 | FDE: 0x19be68 | Size: 176 bytes
// Khung tháo gỡ #0547 | Địa chỉ PC: 0x088188 | Địa chỉ FDE: 0x19be68 | Kích thước: 176 bytes
//   0x088188: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08818c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x088190: 910043FD  add      x29, sp, #0x10
//   0x088194: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0547_0x088188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088188ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19be68ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0548 | PC: 0x088238 | FDE: 0x19bea8 | Size: 256 bytes
// Khung tháo gỡ #0548 | Địa chỉ PC: 0x088238 | Địa chỉ FDE: 0x19bea8 | Kích thước: 256 bytes
//   0x088238: D106C3FF  sub      sp, sp, #0x1b0
//   0x08823c: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x088240: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x088244: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_0548_0x088238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088238ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9156ffcULL) ^ 0x19bea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0549 | PC: 0x08b070 | FDE: 0x19bf08 | Size: 256 bytes
// Khung tháo gỡ #0549 | Địa chỉ PC: 0x08b070 | Địa chỉ FDE: 0x19bf08 | Kích thước: 256 bytes
//   0x08b070: D10543FF  sub      sp, sp, #0x150
//   0x08b074: F90093FC  str      x28, [sp, #0x120]
//   0x08b078: A9134FF4  stp      x20, x19, [sp, #0x130]
//   0x08b07c: A9147BFD  stp      x29, x30, [sp, #0x140]
static inline uint64_t fde_func_0549_0x08b070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b070ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf90093fcULL) ^ 0x19bf08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0550 | PC: 0x08b230 | FDE: 0x19bf48 | Size: 256 bytes
// Khung tháo gỡ #0550 | Địa chỉ PC: 0x08b230 | Địa chỉ FDE: 0x19bf48 | Kích thước: 256 bytes
//   0x08b230: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08b234: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x08b238: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08b23c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0550_0x08b230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b230ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19bf48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0551 | PC: 0x08c518 | FDE: 0x19bf90 | Size: 256 bytes
// Khung tháo gỡ #0551 | Địa chỉ PC: 0x08c518 | Địa chỉ FDE: 0x19bf90 | Kích thước: 256 bytes
//   0x08c518: D10343FF  sub      sp, sp, #0xd0
//   0x08c51c: F90053F5  str      x21, [sp, #0xa0]
//   0x08c520: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x08c524: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0551_0x08c518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c518ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90053f5ULL) ^ 0x19bf90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0552 | PC: 0x08c774 | FDE: 0x19bfd0 | Size: 92 bytes
// Khung tháo gỡ #0552 | Địa chỉ PC: 0x08c774 | Địa chỉ FDE: 0x19bfd0 | Kích thước: 92 bytes
//   0x08c774: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08c778: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08c77c: 910043FD  add      x29, sp, #0x10
//   0x08c780: F00009A8  adrp     x8, #0x1c3000
static inline uint64_t fde_func_0552_0x08c774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c774ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19bfd0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0553 | PC: 0x08c7d0 | FDE: 0x19c008 | Size: 76 bytes
// Khung tháo gỡ #0553 | Địa chỉ PC: 0x08c7d0 | Địa chỉ FDE: 0x19c008 | Kích thước: 76 bytes
//   0x08c7d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08c7d4: 910003FD  mov      x29, sp
//   0x08c7d8: 97FE862E  bl       #0x2e090
//   0x08c7dc: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0553_0x08c7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c7d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c008ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0554 | PC: 0x08c81c | FDE: 0x19c048 | Size: 28 bytes
// Khung tháo gỡ #0554 | Địa chỉ PC: 0x08c81c | Địa chỉ FDE: 0x19c048 | Kích thước: 28 bytes
//   0x08c81c: F00009A8  adrp     x8, #0x1c3000
//   0x08c820: 912D2108  add      x8, x8, #0xb48
//   0x08c824: F9000028  str      x8, [x1]
//   0x08c828: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0554_0x08c81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c81cULL ^ (static_cast<uint64_t>(0xf00009a8ULL) << 13);
    acc = (acc + a1 + 0x912d2108ULL) ^ 0x19c048ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0555 | PC: 0x08c838 | FDE: 0x19c078 | Size: 48 bytes
// Khung tháo gỡ #0555 | Địa chỉ PC: 0x08c838 | Địa chỉ FDE: 0x19c078 | Kích thước: 48 bytes
//   0x08c838: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08c83c: 910003FD  mov      x29, sp
//   0x08c840: 97FE8614  bl       #0x2e090
//   0x08c844: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0555_0x08c838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c838ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c078ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0556 | PC: 0x08c868 | FDE: 0x19c0b8 | Size: 76 bytes
// Khung tháo gỡ #0556 | Địa chỉ PC: 0x08c868 | Địa chỉ FDE: 0x19c0b8 | Kích thước: 76 bytes
//   0x08c868: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08c86c: 910003FD  mov      x29, sp
//   0x08c870: 97FE8608  bl       #0x2e090
//   0x08c874: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0556_0x08c868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c868ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c0b8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0557 | PC: 0x08c8b4 | FDE: 0x19c0f8 | Size: 28 bytes
// Khung tháo gỡ #0557 | Địa chỉ PC: 0x08c8b4 | Địa chỉ FDE: 0x19c0f8 | Kích thước: 28 bytes
//   0x08c8b4: F00009A8  adrp     x8, #0x1c3000
//   0x08c8b8: 912E4108  add      x8, x8, #0xb90
//   0x08c8bc: F9000028  str      x8, [x1]
//   0x08c8c0: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0557_0x08c8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c8b4ULL ^ (static_cast<uint64_t>(0xf00009a8ULL) << 13);
    acc = (acc + a1 + 0x912e4108ULL) ^ 0x19c0f8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0558 | PC: 0x08c8d0 | FDE: 0x19c128 | Size: 60 bytes
// Khung tháo gỡ #0558 | Địa chỉ PC: 0x08c8d0 | Địa chỉ FDE: 0x19c128 | Kích thước: 60 bytes
//   0x08c8d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08c8d4: 910003FD  mov      x29, sp
//   0x08c8d8: 97FE85EE  bl       #0x2e090
//   0x08c8dc: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0558_0x08c8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c8d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c128ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0559 | PC: 0x08c90c | FDE: 0x19c168 | Size: 176 bytes
// Khung tháo gỡ #0559 | Địa chỉ PC: 0x08c90c | Địa chỉ FDE: 0x19c168 | Kích thước: 176 bytes
//   0x08c90c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08c910: 910003FD  mov      x29, sp
//   0x08c914: 97FE872F  bl       #0x2e5d0
//   0x08c918: D10443FF  sub      sp, sp, #0x110
static inline uint64_t fde_func_0559_0x08c90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c90cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c168ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0560 | PC: 0x08c9bc | FDE: 0x19c1a8 | Size: 76 bytes
// Khung tháo gỡ #0560 | Địa chỉ PC: 0x08c9bc | Địa chỉ FDE: 0x19c1a8 | Kích thước: 76 bytes
//   0x08c9bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08c9c0: 910003FD  mov      x29, sp
//   0x08c9c4: 97FE85B3  bl       #0x2e090
//   0x08c9c8: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0560_0x08c9bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c9bcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c1a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0561 | PC: 0x08ca08 | FDE: 0x19c1e8 | Size: 28 bytes
// Khung tháo gỡ #0561 | Địa chỉ PC: 0x08ca08 | Địa chỉ FDE: 0x19c1e8 | Kích thước: 28 bytes
//   0x08ca08: F00009A8  adrp     x8, #0x1c3000
//   0x08ca0c: 912F6108  add      x8, x8, #0xbd8
//   0x08ca10: F9000028  str      x8, [x1]
//   0x08ca14: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0561_0x08ca08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ca08ULL ^ (static_cast<uint64_t>(0xf00009a8ULL) << 13);
    acc = (acc + a1 + 0x912f6108ULL) ^ 0x19c1e8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0562 | PC: 0x08ca24 | FDE: 0x19c218 | Size: 48 bytes
// Khung tháo gỡ #0562 | Địa chỉ PC: 0x08ca24 | Địa chỉ FDE: 0x19c218 | Kích thước: 48 bytes
//   0x08ca24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08ca28: 910003FD  mov      x29, sp
//   0x08ca2c: 97FE8599  bl       #0x2e090
//   0x08ca30: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0562_0x08ca24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ca24ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19c218ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0563 | PC: 0x08ca54 | FDE: 0x19c258 | Size: 256 bytes
// Khung tháo gỡ #0563 | Địa chỉ PC: 0x08ca54 | Địa chỉ FDE: 0x19c258 | Kích thước: 256 bytes
//   0x08ca54: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x08ca58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08ca5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08ca60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0563_0x08ca54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ca54ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19c258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0564 | PC: 0x08cb7c | FDE: 0x19c310 | Size: 256 bytes
// Khung tháo gỡ #0564 | Địa chỉ PC: 0x08cb7c | Địa chỉ FDE: 0x19c310 | Kích thước: 256 bytes
//   0x08cb7c: D10143FF  sub      sp, sp, #0x50
//   0x08cb80: F9000BF7  str      x23, [sp, #0x10]
//   0x08cb84: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08cb88: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0564_0x08cb7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cb7cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x19c310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0565 | PC: 0x08d37c | FDE: 0x19c368 | Size: 256 bytes
// Khung tháo gỡ #0565 | Địa chỉ PC: 0x08d37c | Địa chỉ FDE: 0x19c368 | Kích thước: 256 bytes
//   0x08d37c: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x08d380: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d384: 910043FD  add      x29, sp, #0x10
//   0x08d388: D10C03FF  sub      sp, sp, #0x300
static inline uint64_t fde_func_0565_0x08d37c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d37cULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19c368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0566 | PC: 0x08d534 | FDE: 0x19c3a8 | Size: 256 bytes
// Khung tháo gỡ #0566 | Địa chỉ PC: 0x08d534 | Địa chỉ FDE: 0x19c3a8 | Kích thước: 256 bytes
//   0x08d534: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x08d538: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d53c: 910043FD  add      x29, sp, #0x10
//   0x08d540: D11BC3FF  sub      sp, sp, #0x6f0
static inline uint64_t fde_func_0566_0x08d534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d534ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19c3a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0567 | PC: 0x08de74 | FDE: 0x19c3f8 | Size: 256 bytes
// Khung tháo gỡ #0567 | Địa chỉ PC: 0x08de74 | Địa chỉ FDE: 0x19c3f8 | Kích thước: 256 bytes
//   0x08de74: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x08de78: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08de7c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08de80: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0567_0x08de74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08de74ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x19c3f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0568 | PC: 0x08eb8c | FDE: 0x19c448 | Size: 256 bytes
// Khung tháo gỡ #0568 | Địa chỉ PC: 0x08eb8c | Địa chỉ FDE: 0x19c448 | Kích thước: 256 bytes
//   0x08eb8c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x08eb90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x08eb94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x08eb98: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0568_0x08eb8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08eb8cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19c448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0569 | PC: 0x08f340 | FDE: 0x19c498 | Size: 256 bytes
// Khung tháo gỡ #0569 | Địa chỉ PC: 0x08f340 | Địa chỉ FDE: 0x19c498 | Kích thước: 256 bytes
//   0x08f340: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x08f344: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08f348: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08f34c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0569_0x08f340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f340ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x19c498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0570 | PC: 0x08fd98 | FDE: 0x19c4e8 | Size: 64 bytes
// Khung tháo gỡ #0570 | Địa chỉ PC: 0x08fd98 | Địa chỉ FDE: 0x19c4e8 | Kích thước: 64 bytes
//   0x08fd98: F9400000  ldr      x0, [x0]
//   0x08fd9c: D65F03C0  ret      
//   0x08fda0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x08fda4: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0570_0x08fd98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fd98ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19c4e8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0571 | PC: 0x08fdd8 | FDE: 0x19c520 | Size: 236 bytes
// Khung tháo gỡ #0571 | Địa chỉ PC: 0x08fdd8 | Địa chỉ FDE: 0x19c520 | Kích thước: 236 bytes
//   0x08fdd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08fddc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08fde0: 910043FD  add      x29, sp, #0x10
//   0x08fde4: 90000A68  adrp     x8, #0x1db000
static inline uint64_t fde_func_0571_0x08fdd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fdd8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19c520ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0572 | PC: 0x08fec4 | FDE: 0x19c560 | Size: 64 bytes
// Khung tháo gỡ #0572 | Địa chỉ PC: 0x08fec4 | Địa chỉ FDE: 0x19c560 | Kích thước: 64 bytes
//   0x08fec4: 900006E0  adrp     x0, #0x16b000
//   0x08fec8: 91339000  add      x0, x0, #0xce4
//   0x08fecc: D65F03C0  ret      
//   0x08fed0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0572_0x08fec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fec4ULL ^ (static_cast<uint64_t>(0x900006e0ULL) << 13);
    acc = (acc + a1 + 0x91339000ULL) ^ 0x19c560ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0573 | PC: 0x08ff04 | FDE: 0x19c598 | Size: 156 bytes
// Khung tháo gỡ #0573 | Địa chỉ PC: 0x08ff04 | Địa chỉ FDE: 0x19c598 | Kích thước: 156 bytes
//   0x08ff04: F900001F  str      xzr, [x0]
//   0x08ff08: D65F03C0  ret      
//   0x08ff0c: D10183FF  sub      sp, sp, #0x60
//   0x08ff10: F90013F7  str      x23, [sp, #0x20]
static inline uint64_t fde_func_0573_0x08ff04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ff04ULL ^ (static_cast<uint64_t>(0xf900001fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19c598ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0574 | PC: 0x08ffa0 | FDE: 0x19c5d8 | Size: 120 bytes
// Khung tháo gỡ #0574 | Địa chỉ PC: 0x08ffa0 | Địa chỉ FDE: 0x19c5d8 | Kích thước: 120 bytes
//   0x08ffa0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08ffa4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ffa8: 910043FD  add      x29, sp, #0x10
//   0x08ffac: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0574_0x08ffa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ffa0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19c5d8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0575 | PC: 0x090018 | FDE: 0x19c618 | Size: 20 bytes
// Khung tháo gỡ #0575 | Địa chỉ PC: 0x090018 | Địa chỉ FDE: 0x19c618 | Kích thước: 20 bytes
//   0x090018: A9000000  stp      x0, x0, [x0]
//   0x09001c: F900081F  str      xzr, [x0, #0x10]
//   0x090020: D65F03C0  ret      
//   0x090024: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_0575_0x090018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090018ULL ^ (static_cast<uint64_t>(0xa9000000ULL) << 13);
    acc = (acc + a1 + 0xf900081fULL) ^ 0x19c618ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0576 | PC: 0x09002c | FDE: 0x19c648 | Size: 140 bytes
// Khung tháo gỡ #0576 | Địa chỉ PC: 0x09002c | Địa chỉ FDE: 0x19c648 | Kích thước: 140 bytes
//   0x09002c: D10103FF  sub      sp, sp, #0x40
//   0x090030: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x090034: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x090038: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0576_0x09002c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09002cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x19c648ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0577 | PC: 0x0900b8 | FDE: 0x19c680 | Size: 24 bytes
// Khung tháo gỡ #0577 | Địa chỉ PC: 0x0900b8 | Địa chỉ FDE: 0x19c680 | Kích thước: 24 bytes
//   0x0900b8: F9400800  ldr      x0, [x0, #0x10]
//   0x0900bc: D65F03C0  ret      
//   0x0900c0: F9400008  ldr      x8, [x0]
//   0x0900c4: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0577_0x0900b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0900b8ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19c680ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0578 | PC: 0x0900d0 | FDE: 0x19c6b0 | Size: 16 bytes
// Khung tháo gỡ #0578 | Địa chỉ PC: 0x0900d0 | Địa chỉ FDE: 0x19c6b0 | Kích thước: 16 bytes
//   0x0900d0: F9400000  ldr      x0, [x0]
//   0x0900d4: D65F03C0  ret      
//   0x0900d8: F9400400  ldr      x0, [x0, #8]
//   0x0900dc: D65F03C0  ret      
static inline uint64_t fde_func_0578_0x0900d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0900d0ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19c6b0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0579 | PC: 0x0900e0 | FDE: 0x19c6e0 | Size: 24 bytes
// Khung tháo gỡ #0579 | Địa chỉ PC: 0x0900e0 | Địa chỉ FDE: 0x19c6e0 | Kích thước: 24 bytes
//   0x0900e0: D65F03C0  ret      
//   0x0900e4: F9400008  ldr      x8, [x0]
//   0x0900e8: F9400029  ldr      x9, [x1]
//   0x0900ec: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_0579_0x0900e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0900e0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x19c6e0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0580 | PC: 0x0900f8 | FDE: 0x19c710 | Size: 28 bytes
// Khung tháo gỡ #0580 | Địa chỉ PC: 0x0900f8 | Địa chỉ FDE: 0x19c710 | Kích thước: 28 bytes
//   0x0900f8: F9400008  ldr      x8, [x0]
//   0x0900fc: 91004100  add      x0, x8, #0x10
//   0x090100: D65F03C0  ret      
//   0x090104: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0580_0x0900f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0900f8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91004100ULL) ^ 0x19c710ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0581 | PC: 0x090114 | FDE: 0x19c740 | Size: 92 bytes
// Khung tháo gỡ #0581 | Địa chỉ PC: 0x090114 | Địa chỉ FDE: 0x19c740 | Kích thước: 92 bytes
//   0x090114: 52800040  mov      w0, #2
//   0x090118: D65F03C0  ret      
//   0x09011c: D100C3FF  sub      sp, sp, #0x30
//   0x090120: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_0581_0x090114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090114ULL ^ (static_cast<uint64_t>(0x52800040ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19c740ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0582 | PC: 0x090170 | FDE: 0x19c778 | Size: 256 bytes
// Khung tháo gỡ #0582 | Địa chỉ PC: 0x090170 | Địa chỉ FDE: 0x19c778 | Kích thước: 256 bytes
//   0x090170: D101C3FF  sub      sp, sp, #0x70
//   0x090174: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x090178: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09017c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0582_0x090170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090170ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x19c778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0583 | PC: 0x090438 | FDE: 0x19c7c0 | Size: 196 bytes
// Khung tháo gỡ #0583 | Địa chỉ PC: 0x090438 | Địa chỉ FDE: 0x19c7c0 | Kích thước: 196 bytes
//   0x090438: D100C3FF  sub      sp, sp, #0x30
//   0x09043c: F9000BF3  str      x19, [sp, #0x10]
//   0x090440: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x090444: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0583_0x090438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090438ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x19c7c0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0584 | PC: 0x0904fc | FDE: 0x19c800 | Size: 256 bytes
// Khung tháo gỡ #0584 | Địa chỉ PC: 0x0904fc | Địa chỉ FDE: 0x19c800 | Kích thước: 256 bytes
//   0x0904fc: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x090500: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x090504: 910043FD  add      x29, sp, #0x10
//   0x090508: D11903FF  sub      sp, sp, #0x640
static inline uint64_t fde_func_0584_0x0904fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0904fcULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19c800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0585 | PC: 0x0909d0 | FDE: 0x19c848 | Size: 256 bytes
// Khung tháo gỡ #0585 | Địa chỉ PC: 0x0909d0 | Địa chỉ FDE: 0x19c848 | Kích thước: 256 bytes
//   0x0909d0: D10443FF  sub      sp, sp, #0x110
//   0x0909d4: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x0909d8: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x0909dc: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_0585_0x0909d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0909d0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x19c848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0586 | PC: 0x093080 | FDE: 0x19c8a0 | Size: 256 bytes
// Khung tháo gỡ #0586 | Địa chỉ PC: 0x093080 | Địa chỉ FDE: 0x19c8a0 | Kích thước: 256 bytes
//   0x093080: D10343FF  sub      sp, sp, #0xd0
//   0x093084: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x093088: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x09308c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0586_0x093080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093080ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x19c8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0587 | PC: 0x0936ac | FDE: 0x19c8e0 | Size: 256 bytes
// Khung tháo gỡ #0587 | Địa chỉ PC: 0x0936ac | Địa chỉ FDE: 0x19c8e0 | Kích thước: 256 bytes
//   0x0936ac: D106C3FF  sub      sp, sp, #0x1b0
//   0x0936b0: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0936b4: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0936b8: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_0587_0x0936ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0936acULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9156ffcULL) ^ 0x19c8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0588 | PC: 0x0944d4 | FDE: 0x19c938 | Size: 256 bytes
// Khung tháo gỡ #0588 | Địa chỉ PC: 0x0944d4 | Địa chỉ FDE: 0x19c938 | Kích thước: 256 bytes
//   0x0944d4: D10183FF  sub      sp, sp, #0x60
//   0x0944d8: F90013F7  str      x23, [sp, #0x20]
//   0x0944dc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0944e0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0588_0x0944d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0944d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x19c938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0589 | PC: 0x0946a0 | FDE: 0x19c980 | Size: 256 bytes
// Khung tháo gỡ #0589 | Địa chỉ PC: 0x0946a0 | Địa chỉ FDE: 0x19c980 | Kích thước: 256 bytes
//   0x0946a0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0946a4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0946a8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0946ac: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0589_0x0946a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0946a0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19c980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0590 | PC: 0x0950e4 | FDE: 0x19c9d0 | Size: 256 bytes
// Khung tháo gỡ #0590 | Địa chỉ PC: 0x0950e4 | Địa chỉ FDE: 0x19c9d0 | Kích thước: 256 bytes
//   0x0950e4: D10503FF  sub      sp, sp, #0x140
//   0x0950e8: F9007BFC  str      x28, [sp, #0xf0]
//   0x0950ec: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x0950f0: A91157F6  stp      x22, x21, [sp, #0x110]
static inline uint64_t fde_func_0590_0x0950e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0950e4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x19c9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0591 | PC: 0x095290 | FDE: 0x19ca18 | Size: 256 bytes
// Khung tháo gỡ #0591 | Địa chỉ PC: 0x095290 | Địa chỉ FDE: 0x19ca18 | Kích thước: 256 bytes
//   0x095290: D10443FF  sub      sp, sp, #0x110
//   0x095294: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x095298: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x09529c: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0591_0x095290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095290ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x19ca18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0592 | PC: 0x095634 | FDE: 0x19ca68 | Size: 256 bytes
// Khung tháo gỡ #0592 | Địa chỉ PC: 0x095634 | Địa chỉ FDE: 0x19ca68 | Kích thước: 256 bytes
//   0x095634: D101C3FF  sub      sp, sp, #0x70
//   0x095638: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09563c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x095640: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0592_0x095634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095634ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x19ca68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0593 | PC: 0x0958e8 | FDE: 0x19cab0 | Size: 256 bytes
// Khung tháo gỡ #0593 | Địa chỉ PC: 0x0958e8 | Địa chỉ FDE: 0x19cab0 | Kích thước: 256 bytes
//   0x0958e8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0958ec: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0958f0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0958f4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0593_0x0958e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0958e8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19cab0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0594 | PC: 0x096478 | FDE: 0x19cb10 | Size: 140 bytes
// Khung tháo gỡ #0594 | Địa chỉ PC: 0x096478 | Địa chỉ FDE: 0x19cb10 | Kích thước: 140 bytes
//   0x096478: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x09647c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096480: 910043FD  add      x29, sp, #0x10
//   0x096484: D10C43FF  sub      sp, sp, #0x310
static inline uint64_t fde_func_0594_0x096478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096478ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19cb10ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0595 | PC: 0x096504 | FDE: 0x19cb68 | Size: 28 bytes
// Khung tháo gỡ #0595 | Địa chỉ PC: 0x096504 | Địa chỉ FDE: 0x19cb68 | Kích thước: 28 bytes
//   0x096504: AA0003E2  mov      x2, x0
//   0x096508: AA0103E0  mov      x0, x1
//   0x09650c: D61F0040  br       x2
//   0x096510: A9402003  ldp      x3, x8, [x0]
static inline uint64_t fde_func_0595_0x096504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096504ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x19cb68ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0596 | PC: 0x096520 | FDE: 0x19cb98 | Size: 40 bytes
// Khung tháo gỡ #0596 | Địa chỉ PC: 0x096520 | Địa chỉ FDE: 0x19cb98 | Kích thước: 40 bytes
//   0x096520: A9402003  ldp      x3, x8, [x0]
//   0x096524: F9400C02  ldr      x2, [x0, #0x18]
//   0x096528: 39404001  ldrb     w1, [x0, #0x10]
//   0x09652c: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0596_0x096520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096520ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400c02ULL) ^ 0x19cb98ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0597 | PC: 0x096548 | FDE: 0x19cbc8 | Size: 28 bytes
// Khung tháo gỡ #0597 | Địa chỉ PC: 0x096548 | Địa chỉ FDE: 0x19cbc8 | Kích thước: 28 bytes
//   0x096548: A9402003  ldp      x3, x8, [x0]
//   0x09654c: F9400801  ldr      x1, [x0, #0x10]
//   0x096550: B9401802  ldr      w2, [x0, #0x18]
//   0x096554: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0597_0x096548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096548ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19cbc8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0598 | PC: 0x096564 | FDE: 0x19cbf8 | Size: 68 bytes
// Khung tháo gỡ #0598 | Địa chỉ PC: 0x096564 | Địa chỉ FDE: 0x19cbf8 | Kích thước: 68 bytes
//   0x096564: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096568: F9400809  ldr      x9, [x0, #0x10]
//   0x09656c: A940200A  ldp      x10, x8, [x0]
//   0x096570: 39406001  ldrb     w1, [x0, #0x18]
static inline uint64_t fde_func_0598_0x096564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096564ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x19cbf8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0599 | PC: 0x0965a8 | FDE: 0x19cc28 | Size: 64 bytes
// Khung tháo gỡ #0599 | Địa chỉ PC: 0x0965a8 | Địa chỉ FDE: 0x19cc28 | Kích thước: 64 bytes
//   0x0965a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0965ac: AA0003F3  mov      x19, x0
//   0x0965b0: A9400008  ldp      x8, x0, [x0]
//   0x0965b4: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0599_0x0965a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0965a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19cc28ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0600 | PC: 0x0965e8 | FDE: 0x19cc58 | Size: 56 bytes
// Khung tháo gỡ #0600 | Địa chỉ PC: 0x0965e8 | Địa chỉ FDE: 0x19cc58 | Kích thước: 56 bytes
//   0x0965e8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0965ec: A9402009  ldp      x9, x8, [x0]
//   0x0965f0: F9400800  ldr      x0, [x0, #0x10]
//   0x0965f4: D63F0120  blr      x9
static inline uint64_t fde_func_0600_0x0965e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0965e8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x19cc58ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0601 | PC: 0x096620 | FDE: 0x19cc88 | Size: 64 bytes
// Khung tháo gỡ #0601 | Địa chỉ PC: 0x096620 | Địa chỉ FDE: 0x19cc88 | Kích thước: 64 bytes
//   0x096620: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096624: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x096628: A940200A  ldp      x10, x8, [x0]
//   0x09662c: A9420C02  ldp      x2, x3, [x0, #0x20]
static inline uint64_t fde_func_0601_0x096620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096620ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x19cc88ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0602 | PC: 0x096660 | FDE: 0x19ccb8 | Size: 56 bytes
// Khung tháo gỡ #0602 | Địa chỉ PC: 0x096660 | Địa chỉ FDE: 0x19ccb8 | Kích thước: 56 bytes
//   0x096660: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096664: AA0003F3  mov      x19, x0
//   0x096668: A9400008  ldp      x8, x0, [x0]
//   0x09666c: D63F0100  blr      x8
static inline uint64_t fde_func_0602_0x096660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096660ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19ccb8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0603 | PC: 0x096698 | FDE: 0x19cce8 | Size: 36 bytes
// Khung tháo gỡ #0603 | Địa chỉ PC: 0x096698 | Địa chỉ FDE: 0x19cce8 | Kích thước: 36 bytes
//   0x096698: A9402002  ldp      x2, x8, [x0]
//   0x09669c: F9400801  ldr      x1, [x0, #0x10]
//   0x0966a0: AA0803E0  mov      x0, x8
//   0x0966a4: D61F0040  br       x2
static inline uint64_t fde_func_0603_0x096698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096698ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19cce8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0604 | PC: 0x0966bc | FDE: 0x19cd18 | Size: 64 bytes
// Khung tháo gỡ #0604 | Địa chỉ PC: 0x0966bc | Địa chỉ FDE: 0x19cd18 | Kích thước: 64 bytes
//   0x0966bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0966c0: AA0003F3  mov      x19, x0
//   0x0966c4: A9400008  ldp      x8, x0, [x0]
//   0x0966c8: D63F0100  blr      x8
static inline uint64_t fde_func_0604_0x0966bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0966bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19cd18ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0605 | PC: 0x0966fc | FDE: 0x19cd48 | Size: 36 bytes
// Khung tháo gỡ #0605 | Địa chỉ PC: 0x0966fc | Địa chỉ FDE: 0x19cd48 | Kích thước: 36 bytes
//   0x0966fc: A9402003  ldp      x3, x8, [x0]
//   0x096700: F9400801  ldr      x1, [x0, #0x10]
//   0x096704: B9401802  ldr      w2, [x0, #0x18]
//   0x096708: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0605_0x0966fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0966fcULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19cd48ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0606 | PC: 0x096720 | FDE: 0x19cd78 | Size: 40 bytes
// Khung tháo gỡ #0606 | Địa chỉ PC: 0x096720 | Địa chỉ FDE: 0x19cd78 | Kích thước: 40 bytes
//   0x096720: A9400001  ldp      x1, x0, [x0]
//   0x096724: D61F0020  br       x1
//   0x096728: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x09672c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0606_0x096720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096720ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x19cd78ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0607 | PC: 0x096748 | FDE: 0x19cda8 | Size: 56 bytes
// Khung tháo gỡ #0607 | Địa chỉ PC: 0x096748 | Địa chỉ FDE: 0x19cda8 | Kích thước: 56 bytes
//   0x096748: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x09674c: A9402009  ldp      x9, x8, [x0]
//   0x096750: F9400800  ldr      x0, [x0, #0x10]
//   0x096754: D63F0120  blr      x9
static inline uint64_t fde_func_0607_0x096748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096748ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x19cda8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0608 | PC: 0x096780 | FDE: 0x19cdd8 | Size: 44 bytes
// Khung tháo gỡ #0608 | Địa chỉ PC: 0x096780 | Địa chỉ FDE: 0x19cdd8 | Kích thước: 44 bytes
//   0x096780: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096784: AA0003F3  mov      x19, x0
//   0x096788: A9400008  ldp      x8, x0, [x0]
//   0x09678c: D63F0100  blr      x8
static inline uint64_t fde_func_0608_0x096780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096780ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19cdd8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0609 | PC: 0x0967ac | FDE: 0x19ce08 | Size: 36 bytes
// Khung tháo gỡ #0609 | Địa chỉ PC: 0x0967ac | Địa chỉ FDE: 0x19ce08 | Kích thước: 36 bytes
//   0x0967ac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0967b0: AA0003F3  mov      x19, x0
//   0x0967b4: A9400008  ldp      x8, x0, [x0]
//   0x0967b8: D63F0100  blr      x8
static inline uint64_t fde_func_0609_0x0967ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0967acULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19ce08ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0610 | PC: 0x0967d0 | FDE: 0x19ce38 | Size: 60 bytes
// Khung tháo gỡ #0610 | Địa chỉ PC: 0x0967d0 | Địa chỉ FDE: 0x19ce38 | Kích thước: 60 bytes
//   0x0967d0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0967d4: AA0003F3  mov      x19, x0
//   0x0967d8: A9400008  ldp      x8, x0, [x0]
//   0x0967dc: D63F0100  blr      x8
static inline uint64_t fde_func_0610_0x0967d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0967d0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19ce38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0611 | PC: 0x09680c | FDE: 0x19ce68 | Size: 60 bytes
// Khung tháo gỡ #0611 | Địa chỉ PC: 0x09680c | Địa chỉ FDE: 0x19ce68 | Kích thước: 60 bytes
//   0x09680c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096810: AA0003F3  mov      x19, x0
//   0x096814: A9400008  ldp      x8, x0, [x0]
//   0x096818: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0611_0x09680c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09680cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19ce68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0612 | PC: 0x096848 | FDE: 0x19ce98 | Size: 56 bytes
// Khung tháo gỡ #0612 | Địa chỉ PC: 0x096848 | Địa chỉ FDE: 0x19ce98 | Kích thước: 56 bytes
//   0x096848: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x09684c: F9400008  ldr      x8, [x0]
//   0x096850: AA0003F3  mov      x19, x0
//   0x096854: D63F0100  blr      x8
static inline uint64_t fde_func_0612_0x096848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096848ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x19ce98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0613 | PC: 0x096880 | FDE: 0x19cec8 | Size: 56 bytes
// Khung tháo gỡ #0613 | Địa chỉ PC: 0x096880 | Địa chỉ FDE: 0x19cec8 | Kích thước: 56 bytes
//   0x096880: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096884: F9400008  ldr      x8, [x0]
//   0x096888: AA0003F3  mov      x19, x0
//   0x09688c: D63F0100  blr      x8
static inline uint64_t fde_func_0613_0x096880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096880ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x19cec8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0614 | PC: 0x0968b8 | FDE: 0x19cef8 | Size: 48 bytes
// Khung tháo gỡ #0614 | Địa chỉ PC: 0x0968b8 | Địa chỉ FDE: 0x19cef8 | Kích thước: 48 bytes
//   0x0968b8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0968bc: A9402009  ldp      x9, x8, [x0]
//   0x0968c0: D63F0120  blr      x9
//   0x0968c4: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0614_0x0968b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0968b8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x19cef8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0615 | PC: 0x0968e8 | FDE: 0x19cf28 | Size: 72 bytes
// Khung tháo gỡ #0615 | Địa chỉ PC: 0x0968e8 | Địa chỉ FDE: 0x19cf28 | Kích thước: 72 bytes
//   0x0968e8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0968ec: AA0003F3  mov      x19, x0
//   0x0968f0: A9400008  ldp      x8, x0, [x0]
//   0x0968f4: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0615_0x0968e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0968e8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19cf28ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0616 | PC: 0x096930 | FDE: 0x19cf58 | Size: 64 bytes
// Khung tháo gỡ #0616 | Địa chỉ PC: 0x096930 | Địa chỉ FDE: 0x19cf58 | Kích thước: 64 bytes
//   0x096930: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096934: AA0003F3  mov      x19, x0
//   0x096938: A9400008  ldp      x8, x0, [x0]
//   0x09693c: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0616_0x096930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096930ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19cf58ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0617 | PC: 0x096970 | FDE: 0x19cf88 | Size: 60 bytes
// Khung tháo gỡ #0617 | Địa chỉ PC: 0x096970 | Địa chỉ FDE: 0x19cf88 | Kích thước: 60 bytes
//   0x096970: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096974: F9400809  ldr      x9, [x0, #0x10]
//   0x096978: A940200A  ldp      x10, x8, [x0]
//   0x09697c: 39406001  ldrb     w1, [x0, #0x18]
static inline uint64_t fde_func_0617_0x096970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096970ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x19cf88ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0618 | PC: 0x0969ac | FDE: 0x19cfb8 | Size: 52 bytes
// Khung tháo gỡ #0618 | Địa chỉ PC: 0x0969ac | Địa chỉ FDE: 0x19cfb8 | Kích thước: 52 bytes
//   0x0969ac: A9402002  ldp      x2, x8, [x0]
//   0x0969b0: F9400801  ldr      x1, [x0, #0x10]
//   0x0969b4: AA0803E0  mov      x0, x8
//   0x0969b8: D61F0040  br       x2
static inline uint64_t fde_func_0618_0x0969ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0969acULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19cfb8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0619 | PC: 0x0969e0 | FDE: 0x19cfe8 | Size: 60 bytes
// Khung tháo gỡ #0619 | Địa chỉ PC: 0x0969e0 | Địa chỉ FDE: 0x19cfe8 | Kích thước: 60 bytes
//   0x0969e0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0969e4: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x0969e8: A940200A  ldp      x10, x8, [x0]
//   0x0969ec: AA0903E0  mov      x0, x9
static inline uint64_t fde_func_0619_0x0969e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0969e0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x19cfe8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0620 | PC: 0x096a1c | FDE: 0x19d018 | Size: 16 bytes
// Khung tháo gỡ #0620 | Địa chỉ PC: 0x096a1c | Địa chỉ FDE: 0x19d018 | Kích thước: 16 bytes
//   0x096a1c: A9400001  ldp      x1, x0, [x0]
//   0x096a20: D61F0020  br       x1
//   0x096a24: A9400001  ldp      x1, x0, [x0]
//   0x096a28: D61F0020  br       x1
static inline uint64_t fde_func_0620_0x096a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096a1cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x19d018ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0621 | PC: 0x096a2c | FDE: 0x19d048 | Size: 60 bytes
// Khung tháo gỡ #0621 | Địa chỉ PC: 0x096a2c | Địa chỉ FDE: 0x19d048 | Kích thước: 60 bytes
//   0x096a2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096a30: F9400008  ldr      x8, [x0]
//   0x096a34: AA0003F3  mov      x19, x0
//   0x096a38: D63F0100  blr      x8
static inline uint64_t fde_func_0621_0x096a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096a2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x19d048ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0622 | PC: 0x096a68 | FDE: 0x19d078 | Size: 24 bytes
// Khung tháo gỡ #0622 | Địa chỉ PC: 0x096a68 | Địa chỉ FDE: 0x19d078 | Kích thước: 24 bytes
//   0x096a68: A9402002  ldp      x2, x8, [x0]
//   0x096a6c: F9400801  ldr      x1, [x0, #0x10]
//   0x096a70: AA0803E0  mov      x0, x8
//   0x096a74: D61F0040  br       x2
static inline uint64_t fde_func_0622_0x096a68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096a68ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19d078ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0623 | PC: 0x096a80 | FDE: 0x19d0a8 | Size: 56 bytes
// Khung tháo gỡ #0623 | Địa chỉ PC: 0x096a80 | Địa chỉ FDE: 0x19d0a8 | Kích thước: 56 bytes
//   0x096a80: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096a84: AA0003F3  mov      x19, x0
//   0x096a88: A9400008  ldp      x8, x0, [x0]
//   0x096a8c: D63F0100  blr      x8
static inline uint64_t fde_func_0623_0x096a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096a80ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d0a8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0624 | PC: 0x096ab8 | FDE: 0x19d0d8 | Size: 68 bytes
// Khung tháo gỡ #0624 | Địa chỉ PC: 0x096ab8 | Địa chỉ FDE: 0x19d0d8 | Kích thước: 68 bytes
//   0x096ab8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096abc: AA0003F3  mov      x19, x0
//   0x096ac0: A9400008  ldp      x8, x0, [x0]
//   0x096ac4: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0624_0x096ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ab8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d0d8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0625 | PC: 0x096afc | FDE: 0x19d108 | Size: 48 bytes
// Khung tháo gỡ #0625 | Địa chỉ PC: 0x096afc | Địa chỉ FDE: 0x19d108 | Kích thước: 48 bytes
//   0x096afc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096b00: AA0003F3  mov      x19, x0
//   0x096b04: A9400008  ldp      x8, x0, [x0]
//   0x096b08: D63F0100  blr      x8
static inline uint64_t fde_func_0625_0x096afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096afcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d108ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0626 | PC: 0x096b2c | FDE: 0x19d138 | Size: 64 bytes
// Khung tháo gỡ #0626 | Địa chỉ PC: 0x096b2c | Địa chỉ FDE: 0x19d138 | Kích thước: 64 bytes
//   0x096b2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096b30: AA0003F3  mov      x19, x0
//   0x096b34: A9400008  ldp      x8, x0, [x0]
//   0x096b38: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0626_0x096b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096b2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d138ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0627 | PC: 0x096b6c | FDE: 0x19d168 | Size: 44 bytes
// Khung tháo gỡ #0627 | Địa chỉ PC: 0x096b6c | Địa chỉ FDE: 0x19d168 | Kích thước: 44 bytes
//   0x096b6c: A9400001  ldp      x1, x0, [x0]
//   0x096b70: D61F0020  br       x1
//   0x096b74: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096b78: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0627_0x096b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096b6cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x19d168ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0628 | PC: 0x096b98 | FDE: 0x19d198 | Size: 56 bytes
// Khung tháo gỡ #0628 | Địa chỉ PC: 0x096b98 | Địa chỉ FDE: 0x19d198 | Kích thước: 56 bytes
//   0x096b98: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096b9c: AA0003F3  mov      x19, x0
//   0x096ba0: A9400008  ldp      x8, x0, [x0]
//   0x096ba4: D63F0100  blr      x8
static inline uint64_t fde_func_0628_0x096b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096b98ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d198ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0629 | PC: 0x096bd0 | FDE: 0x19d1c8 | Size: 56 bytes
// Khung tháo gỡ #0629 | Địa chỉ PC: 0x096bd0 | Địa chỉ FDE: 0x19d1c8 | Kích thước: 56 bytes
//   0x096bd0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096bd4: AA0003F3  mov      x19, x0
//   0x096bd8: A9400008  ldp      x8, x0, [x0]
//   0x096bdc: D63F0100  blr      x8
static inline uint64_t fde_func_0629_0x096bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096bd0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d1c8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0630 | PC: 0x096c08 | FDE: 0x19d1f8 | Size: 56 bytes
// Khung tháo gỡ #0630 | Địa chỉ PC: 0x096c08 | Địa chỉ FDE: 0x19d1f8 | Kích thước: 56 bytes
//   0x096c08: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096c0c: F9400008  ldr      x8, [x0]
//   0x096c10: AA0003F3  mov      x19, x0
//   0x096c14: D63F0100  blr      x8
static inline uint64_t fde_func_0630_0x096c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096c08ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x19d1f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0631 | PC: 0x096c40 | FDE: 0x19d228 | Size: 52 bytes
// Khung tháo gỡ #0631 | Địa chỉ PC: 0x096c40 | Địa chỉ FDE: 0x19d228 | Kích thước: 52 bytes
//   0x096c40: A9402003  ldp      x3, x8, [x0]
//   0x096c44: B9401402  ldr      w2, [x0, #0x14]
//   0x096c48: 39404001  ldrb     w1, [x0, #0x10]
//   0x096c4c: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0631_0x096c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096c40ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xb9401402ULL) ^ 0x19d228ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0632 | PC: 0x096c74 | FDE: 0x19d258 | Size: 48 bytes
// Khung tháo gỡ #0632 | Địa chỉ PC: 0x096c74 | Địa chỉ FDE: 0x19d258 | Kích thước: 48 bytes
//   0x096c74: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096c78: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x096c7c: A940200A  ldp      x10, x8, [x0]
//   0x096c80: AA0903E0  mov      x0, x9
static inline uint64_t fde_func_0632_0x096c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096c74ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x19d258ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0633 | PC: 0x096ca4 | FDE: 0x19d288 | Size: 64 bytes
// Khung tháo gỡ #0633 | Địa chỉ PC: 0x096ca4 | Địa chỉ FDE: 0x19d288 | Kích thước: 64 bytes
//   0x096ca4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096ca8: F9400809  ldr      x9, [x0, #0x10]
//   0x096cac: A940200A  ldp      x10, x8, [x0]
//   0x096cb0: B9401801  ldr      w1, [x0, #0x18]
static inline uint64_t fde_func_0633_0x096ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ca4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x19d288ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0634 | PC: 0x096ce4 | FDE: 0x19d2b8 | Size: 44 bytes
// Khung tháo gỡ #0634 | Địa chỉ PC: 0x096ce4 | Địa chỉ FDE: 0x19d2b8 | Kích thước: 44 bytes
//   0x096ce4: A9402003  ldp      x3, x8, [x0]
//   0x096ce8: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x096cec: AA0803E0  mov      x0, x8
//   0x096cf0: D61F0060  br       x3
static inline uint64_t fde_func_0634_0x096ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ce4ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x19d2b8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0635 | PC: 0x096d10 | FDE: 0x19d2e8 | Size: 60 bytes
// Khung tháo gỡ #0635 | Địa chỉ PC: 0x096d10 | Địa chỉ FDE: 0x19d2e8 | Kích thước: 60 bytes
//   0x096d10: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096d14: AA0003F3  mov      x19, x0
//   0x096d18: A9400008  ldp      x8, x0, [x0]
//   0x096d1c: D63F0100  blr      x8
static inline uint64_t fde_func_0635_0x096d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d10ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d2e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0636 | PC: 0x096d4c | FDE: 0x19d318 | Size: 68 bytes
// Khung tháo gỡ #0636 | Địa chỉ PC: 0x096d4c | Địa chỉ FDE: 0x19d318 | Kích thước: 68 bytes
//   0x096d4c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096d50: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x096d54: A940200A  ldp      x10, x8, [x0]
//   0x096d58: A9420C02  ldp      x2, x3, [x0, #0x20]
static inline uint64_t fde_func_0636_0x096d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d4cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x19d318ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0637 | PC: 0x096d90 | FDE: 0x19d348 | Size: 44 bytes
// Khung tháo gỡ #0637 | Địa chỉ PC: 0x096d90 | Địa chỉ FDE: 0x19d348 | Kích thước: 44 bytes
//   0x096d90: A9402003  ldp      x3, x8, [x0]
//   0x096d94: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x096d98: AA0803E0  mov      x0, x8
//   0x096d9c: D61F0060  br       x3
static inline uint64_t fde_func_0637_0x096d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d90ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x19d348ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0638 | PC: 0x096dbc | FDE: 0x19d378 | Size: 44 bytes
// Khung tháo gỡ #0638 | Địa chỉ PC: 0x096dbc | Địa chỉ FDE: 0x19d378 | Kích thước: 44 bytes
//   0x096dbc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096dc0: AA0003F3  mov      x19, x0
//   0x096dc4: A9400008  ldp      x8, x0, [x0]
//   0x096dc8: D63F0100  blr      x8
static inline uint64_t fde_func_0638_0x096dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096dbcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d378ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0639 | PC: 0x096de8 | FDE: 0x19d3a8 | Size: 32 bytes
// Khung tháo gỡ #0639 | Địa chỉ PC: 0x096de8 | Địa chỉ FDE: 0x19d3a8 | Kích thước: 32 bytes
//   0x096de8: A9400001  ldp      x1, x0, [x0]
//   0x096dec: D61F0020  br       x1
//   0x096df0: A9402005  ldp      x5, x8, [x0]
//   0x096df4: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0639_0x096de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096de8ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x19d3a8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0640 | PC: 0x096e08 | FDE: 0x19d3d8 | Size: 48 bytes
// Khung tháo gỡ #0640 | Địa chỉ PC: 0x096e08 | Địa chỉ FDE: 0x19d3d8 | Kích thước: 48 bytes
//   0x096e08: A9402003  ldp      x3, x8, [x0]
//   0x096e0c: F9400801  ldr      x1, [x0, #0x10]
//   0x096e10: B9401802  ldr      w2, [x0, #0x18]
//   0x096e14: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0640_0x096e08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096e08ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19d3d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0641 | PC: 0x096e38 | FDE: 0x19d408 | Size: 48 bytes
// Khung tháo gỡ #0641 | Địa chỉ PC: 0x096e38 | Địa chỉ FDE: 0x19d408 | Kích thước: 48 bytes
//   0x096e38: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x096e3c: F9400809  ldr      x9, [x0, #0x10]
//   0x096e40: A940200A  ldp      x10, x8, [x0]
//   0x096e44: 39406001  ldrb     w1, [x0, #0x18]
static inline uint64_t fde_func_0641_0x096e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096e38ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x19d408ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0642 | PC: 0x096e68 | FDE: 0x19d438 | Size: 56 bytes
// Khung tháo gỡ #0642 | Địa chỉ PC: 0x096e68 | Địa chỉ FDE: 0x19d438 | Kích thước: 56 bytes
//   0x096e68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096e6c: AA0003F3  mov      x19, x0
//   0x096e70: A9400008  ldp      x8, x0, [x0]
//   0x096e74: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0642_0x096e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096e68ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d438ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0643 | PC: 0x096ea0 | FDE: 0x19d468 | Size: 64 bytes
// Khung tháo gỡ #0643 | Địa chỉ PC: 0x096ea0 | Địa chỉ FDE: 0x19d468 | Kích thước: 64 bytes
//   0x096ea0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096ea4: AA0003F3  mov      x19, x0
//   0x096ea8: A9400008  ldp      x8, x0, [x0]
//   0x096eac: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0643_0x096ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ea0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d468ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0644 | PC: 0x096ee0 | FDE: 0x19d498 | Size: 44 bytes
// Khung tháo gỡ #0644 | Địa chỉ PC: 0x096ee0 | Địa chỉ FDE: 0x19d498 | Kích thước: 44 bytes
//   0x096ee0: A9402003  ldp      x3, x8, [x0]
//   0x096ee4: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x096ee8: AA0803E0  mov      x0, x8
//   0x096eec: D61F0060  br       x3
static inline uint64_t fde_func_0644_0x096ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ee0ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x19d498ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0645 | PC: 0x096f0c | FDE: 0x19d4c8 | Size: 24 bytes
// Khung tháo gỡ #0645 | Địa chỉ PC: 0x096f0c | Địa chỉ FDE: 0x19d4c8 | Kích thước: 24 bytes
//   0x096f0c: A9402002  ldp      x2, x8, [x0]
//   0x096f10: F9400801  ldr      x1, [x0, #0x10]
//   0x096f14: AA0803E0  mov      x0, x8
//   0x096f18: D61F0040  br       x2
static inline uint64_t fde_func_0645_0x096f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096f0cULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19d4c8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0646 | PC: 0x096f24 | FDE: 0x19d4f8 | Size: 64 bytes
// Khung tháo gỡ #0646 | Địa chỉ PC: 0x096f24 | Địa chỉ FDE: 0x19d4f8 | Kích thước: 64 bytes
//   0x096f24: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096f28: AA0003F3  mov      x19, x0
//   0x096f2c: A9400008  ldp      x8, x0, [x0]
//   0x096f30: D63F0100  blr      x8
static inline uint64_t fde_func_0646_0x096f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096f24ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d4f8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0647 | PC: 0x096f64 | FDE: 0x19d528 | Size: 52 bytes
// Khung tháo gỡ #0647 | Địa chỉ PC: 0x096f64 | Địa chỉ FDE: 0x19d528 | Kích thước: 52 bytes
//   0x096f64: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096f68: AA0003F3  mov      x19, x0
//   0x096f6c: A9400008  ldp      x8, x0, [x0]
//   0x096f70: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0647_0x096f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096f64ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d528ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0648 | PC: 0x096f98 | FDE: 0x19d558 | Size: 44 bytes
// Khung tháo gỡ #0648 | Địa chỉ PC: 0x096f98 | Địa chỉ FDE: 0x19d558 | Kích thước: 44 bytes
//   0x096f98: A9402002  ldp      x2, x8, [x0]
//   0x096f9c: B9401001  ldr      w1, [x0, #0x10]
//   0x096fa0: AA0803E0  mov      x0, x8
//   0x096fa4: D61F0040  br       x2
static inline uint64_t fde_func_0648_0x096f98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096f98ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xb9401001ULL) ^ 0x19d558ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0649 | PC: 0x096fc4 | FDE: 0x19d588 | Size: 64 bytes
// Khung tháo gỡ #0649 | Địa chỉ PC: 0x096fc4 | Địa chỉ FDE: 0x19d588 | Kích thước: 64 bytes
//   0x096fc4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x096fc8: AA0003F3  mov      x19, x0
//   0x096fcc: A9400008  ldp      x8, x0, [x0]
//   0x096fd0: 39404261  ldrb     w1, [x19, #0x10]
static inline uint64_t fde_func_0649_0x096fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096fc4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d588ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0650 | PC: 0x097004 | FDE: 0x19d5b8 | Size: 44 bytes
// Khung tháo gỡ #0650 | Địa chỉ PC: 0x097004 | Địa chỉ FDE: 0x19d5b8 | Kích thước: 44 bytes
//   0x097004: A9402002  ldp      x2, x8, [x0]
//   0x097008: F9400801  ldr      x1, [x0, #0x10]
//   0x09700c: AA0803E0  mov      x0, x8
//   0x097010: D61F0040  br       x2
static inline uint64_t fde_func_0650_0x097004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097004ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19d5b8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0651 | PC: 0x097030 | FDE: 0x19d5e8 | Size: 56 bytes
// Khung tháo gỡ #0651 | Địa chỉ PC: 0x097030 | Địa chỉ FDE: 0x19d5e8 | Kích thước: 56 bytes
//   0x097030: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x097034: A9402009  ldp      x9, x8, [x0]
//   0x097038: F9400800  ldr      x0, [x0, #0x10]
//   0x09703c: D63F0120  blr      x9
static inline uint64_t fde_func_0651_0x097030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097030ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x19d5e8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0652 | PC: 0x097068 | FDE: 0x19d618 | Size: 56 bytes
// Khung tháo gỡ #0652 | Địa chỉ PC: 0x097068 | Địa chỉ FDE: 0x19d618 | Kích thước: 56 bytes
//   0x097068: A9402003  ldp      x3, x8, [x0]
//   0x09706c: F9400801  ldr      x1, [x0, #0x10]
//   0x097070: B9401802  ldr      w2, [x0, #0x18]
//   0x097074: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0652_0x097068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097068ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x19d618ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0653 | PC: 0x0970a0 | FDE: 0x19d648 | Size: 56 bytes
// Khung tháo gỡ #0653 | Địa chỉ PC: 0x0970a0 | Địa chỉ FDE: 0x19d648 | Kích thước: 56 bytes
//   0x0970a0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0970a4: A9410409  ldp      x9, x1, [x0, #0x10]
//   0x0970a8: A940200A  ldp      x10, x8, [x0]
//   0x0970ac: AA0903E0  mov      x0, x9
static inline uint64_t fde_func_0653_0x0970a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0970a0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9410409ULL) ^ 0x19d648ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0654 | PC: 0x0970d8 | FDE: 0x19d678 | Size: 48 bytes
// Khung tháo gỡ #0654 | Địa chỉ PC: 0x0970d8 | Địa chỉ FDE: 0x19d678 | Kích thước: 48 bytes
//   0x0970d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0970dc: AA0003F3  mov      x19, x0
//   0x0970e0: A9400008  ldp      x8, x0, [x0]
//   0x0970e4: D63F0100  blr      x8
static inline uint64_t fde_func_0654_0x0970d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0970d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d678ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0655 | PC: 0x097108 | FDE: 0x19d6a8 | Size: 256 bytes
// Khung tháo gỡ #0655 | Địa chỉ PC: 0x097108 | Địa chỉ FDE: 0x19d6a8 | Kích thước: 256 bytes
//   0x097108: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x09710c: AA0003F3  mov      x19, x0
//   0x097110: A9400008  ldp      x8, x0, [x0]
//   0x097114: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0655_0x097108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097108ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x19d6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0656 | PC: 0x097488 | FDE: 0x19d748 | Size: 256 bytes
// Khung tháo gỡ #0656 | Địa chỉ PC: 0x097488 | Địa chỉ FDE: 0x19d748 | Kích thước: 256 bytes
//   0x097488: D10183FF  sub      sp, sp, #0x60
//   0x09748c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x097490: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x097494: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0656_0x097488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097488ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x19d748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0657 | PC: 0x097934 | FDE: 0x19d7a0 | Size: 256 bytes
// Khung tháo gỡ #0657 | Địa chỉ PC: 0x097934 | Địa chỉ FDE: 0x19d7a0 | Kích thước: 256 bytes
//   0x097934: D10583FF  sub      sp, sp, #0x160
//   0x097938: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x09793c: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x097940: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_0657_0x097934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097934ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x19d7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0658 | PC: 0x0994f4 | FDE: 0x19d800 | Size: 256 bytes
// Khung tháo gỡ #0658 | Địa chỉ PC: 0x0994f4 | Địa chỉ FDE: 0x19d800 | Kích thước: 256 bytes
//   0x0994f4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0994f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0994fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x099500: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0658_0x0994f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0994f4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19d800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0659 | PC: 0x09a128 | FDE: 0x19d850 | Size: 256 bytes
// Khung tháo gỡ #0659 | Địa chỉ PC: 0x09a128 | Địa chỉ FDE: 0x19d850 | Kích thước: 256 bytes
//   0x09a128: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09a12c: 910003FD  mov      x29, sp
//   0x09a130: D0000A08  adrp     x8, #0x1dc000
//   0x09a134: 91134108  add      x8, x8, #0x4d0
static inline uint64_t fde_func_0659_0x09a128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a128ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19d850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0660 | PC: 0x09a58c | FDE: 0x19d890 | Size: 256 bytes
// Khung tháo gỡ #0660 | Địa chỉ PC: 0x09a58c | Địa chỉ FDE: 0x19d890 | Kích thước: 256 bytes
//   0x09a58c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09a590: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09a594: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09a598: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0660_0x09a58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a58cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19d890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0661 | PC: 0x09ad20 | FDE: 0x19d8e0 | Size: 256 bytes
// Khung tháo gỡ #0661 | Địa chỉ PC: 0x09ad20 | Địa chỉ FDE: 0x19d8e0 | Kích thước: 256 bytes
//   0x09ad20: D101C3FF  sub      sp, sp, #0x70
//   0x09ad24: F9002BF3  str      x19, [sp, #0x50]
//   0x09ad28: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x09ad2c: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_0661_0x09ad20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ad20ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x19d8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0662 | PC: 0x09b114 | FDE: 0x19d920 | Size: 200 bytes
// Khung tháo gỡ #0662 | Địa chỉ PC: 0x09b114 | Địa chỉ FDE: 0x19d920 | Kích thước: 200 bytes
//   0x09b114: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x09b118: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09b11c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09b120: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0662_0x09b114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b114ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19d920ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0663 | PC: 0x09b1dc | FDE: 0x19d970 | Size: 256 bytes
// Khung tháo gỡ #0663 | Địa chỉ PC: 0x09b1dc | Địa chỉ FDE: 0x19d970 | Kích thước: 256 bytes
//   0x09b1dc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x09b1e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09b1e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09b1e8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0663_0x09b1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b1dcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19d970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0664 | PC: 0x09b2f8 | FDE: 0x19da28 | Size: 256 bytes
// Khung tháo gỡ #0664 | Địa chỉ PC: 0x09b2f8 | Địa chỉ FDE: 0x19da28 | Kích thước: 256 bytes
//   0x09b2f8: D10203FF  sub      sp, sp, #0x80
//   0x09b2fc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x09b300: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x09b304: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0664_0x09b2f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b2f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x19da28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0665 | PC: 0x09b520 | FDE: 0x19da90 | Size: 136 bytes
// Khung tháo gỡ #0665 | Địa chỉ PC: 0x09b520 | Địa chỉ FDE: 0x19da90 | Kích thước: 136 bytes
//   0x09b520: AA1E03E5  mov      x5, x30
//   0x09b524: 8B0000A5  add      x5, x5, x0
//   0x09b528: AA0503FE  mov      x30, x5
//   0x09b52c: D65F03C0  ret      
static inline uint64_t fde_func_0665_0x09b520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b520ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x8b0000a5ULL) ^ 0x19da90ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0666 | PC: 0x09b5a8 | FDE: 0x19db20 | Size: 256 bytes
// Khung tháo gỡ #0666 | Địa chỉ PC: 0x09b5a8 | Địa chỉ FDE: 0x19db20 | Kích thước: 256 bytes
//   0x09b5a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09b5ac: 910003FD  mov      x29, sp
//   0x09b5b0: 94000003  bl       #0x9b5bc
//   0x09b5b4: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0666_0x09b5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b5a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19db20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0667 | PC: 0x09bf78 | FDE: 0x19db70 | Size: 128 bytes
// Khung tháo gỡ #0667 | Địa chỉ PC: 0x09bf78 | Địa chỉ FDE: 0x19db70 | Kích thước: 128 bytes
//   0x09bf78: 7100043F  cmp      w1, #1
//   0x09bf7c: 540000A8  b.hi     #0x9bf90
//   0x09bf80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09bf84: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0667_0x09bf78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bf78ULL ^ (static_cast<uint64_t>(0x7100043fULL) << 13);
    acc = (acc + a1 + 0x540000a8ULL) ^ 0x19db70ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0668 | PC: 0x09bff8 | FDE: 0x19dbb0 | Size: 8 bytes
// Khung tháo gỡ #0668 | Địa chỉ PC: 0x09bff8 | Địa chỉ FDE: 0x19dbb0 | Kích thước: 8 bytes
//   0x09bff8: D65F03C0  ret      
//   0x09bffc: D65F03C0  ret      
static inline uint64_t fde_func_0668_0x09bff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bff8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19dbb0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0669 | PC: 0x09c000 | FDE: 0x19dbe0 | Size: 256 bytes
// Khung tháo gỡ #0669 | Địa chỉ PC: 0x09c000 | Địa chỉ FDE: 0x19dbe0 | Kích thước: 256 bytes
//   0x09c000: D10143FF  sub      sp, sp, #0x50
//   0x09c004: F90013F5  str      x21, [sp, #0x20]
//   0x09c008: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09c00c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0669_0x09c000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c000ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x19dbe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0670 | PC: 0x09c128 | FDE: 0x19dc20 | Size: 144 bytes
// Khung tháo gỡ #0670 | Địa chỉ PC: 0x09c128 | Địa chỉ FDE: 0x19dc20 | Kích thước: 144 bytes
//   0x09c128: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c12c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c130: 910043FD  add      x29, sp, #0x10
//   0x09c134: F9400C14  ldr      x20, [x0, #0x18]
static inline uint64_t fde_func_0670_0x09c128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c128ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19dc20ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0671 | PC: 0x09c1b8 | FDE: 0x19dc58 | Size: 256 bytes
// Khung tháo gỡ #0671 | Địa chỉ PC: 0x09c1b8 | Địa chỉ FDE: 0x19dc58 | Kích thước: 256 bytes
//   0x09c1b8: D65F03C0  ret      
//   0x09c1bc: D10143FF  sub      sp, sp, #0x50
//   0x09c1c0: F90013F5  str      x21, [sp, #0x20]
//   0x09c1c4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0671_0x09c1b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c1b8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x19dc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0672 | PC: 0x09c324 | FDE: 0x19dd08 | Size: 256 bytes
// Khung tháo gỡ #0672 | Địa chỉ PC: 0x09c324 | Địa chỉ FDE: 0x19dd08 | Kích thước: 256 bytes
//   0x09c324: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09c328: 910003FD  mov      x29, sp
//   0x09c32c: 91006008  add      x8, x0, #0x18
//   0x09c330: D00006C9  adrp     x9, #0x176000
static inline uint64_t fde_func_0672_0x09c324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c324ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19dd08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0673 | PC: 0x09c52c | FDE: 0x19dd50 | Size: 256 bytes
// Khung tháo gỡ #0673 | Địa chỉ PC: 0x09c52c | Địa chỉ FDE: 0x19dd50 | Kích thước: 256 bytes
//   0x09c52c: D10343FF  sub      sp, sp, #0xd0
//   0x09c530: FD003BE8  str      d8, [sp, #0x70]
//   0x09c534: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x09c538: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0673_0x09c52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c52cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xfd003be8ULL) ^ 0x19dd50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0674 | PC: 0x09cc40 | FDE: 0x19dda8 | Size: 256 bytes
// Khung tháo gỡ #0674 | Địa chỉ PC: 0x09cc40 | Địa chỉ FDE: 0x19dda8 | Kích thước: 256 bytes
//   0x09cc40: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x09cc44: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09cc48: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09cc4c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0674_0x09cc40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cc40ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19dda8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x09d9b4 | FDE: 0x19de00 | Size: 256 bytes
// Khung tháo gỡ #0675 | Địa chỉ PC: 0x09d9b4 | Địa chỉ FDE: 0x19de00 | Kích thước: 256 bytes
//   0x09d9b4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09d9b8: 910003FD  mov      x29, sp
//   0x09d9bc: F00009E8  adrp     x8, #0x1dc000
//   0x09d9c0: 9115C108  add      x8, x8, #0x570
static inline uint64_t fde_func_0675_0x09d9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d9b4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19de00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0676 | PC: 0x09e238 | FDE: 0x19de50 | Size: 252 bytes
// Khung tháo gỡ #0676 | Địa chỉ PC: 0x09e238 | Địa chỉ FDE: 0x19de50 | Kích thước: 252 bytes
//   0x09e238: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09e23c: 910003FD  mov      x29, sp
//   0x09e240: D00009E8  adrp     x8, #0x1dc000
//   0x09e244: 91160108  add      x8, x8, #0x580
static inline uint64_t fde_func_0676_0x09e238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e238ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19de50ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0677 | PC: 0x09e334 | FDE: 0x19de90 | Size: 256 bytes
// Khung tháo gỡ #0677 | Địa chỉ PC: 0x09e334 | Địa chỉ FDE: 0x19de90 | Kích thước: 256 bytes
//   0x09e334: D10343FF  sub      sp, sp, #0xd0
//   0x09e338: F90053F5  str      x21, [sp, #0xa0]
//   0x09e33c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x09e340: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0677_0x09e334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e334ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90053f5ULL) ^ 0x19de90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0678 | PC: 0x09e554 | FDE: 0x19ded0 | Size: 80 bytes
// Khung tháo gỡ #0678 | Địa chỉ PC: 0x09e554 | Địa chỉ FDE: 0x19ded0 | Kích thước: 80 bytes
//   0x09e554: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09e558: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e55c: 910043FD  add      x29, sp, #0x10
//   0x09e560: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0678_0x09e554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e554ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19ded0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0679 | PC: 0x09e5a4 | FDE: 0x19df08 | Size: 24 bytes
// Khung tháo gỡ #0679 | Địa chỉ PC: 0x09e5a4 | Địa chỉ FDE: 0x19df08 | Kích thước: 24 bytes
//   0x09e5a4: D65F03C0  ret      
//   0x09e5a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09e5ac: 910003FD  mov      x29, sp
//   0x09e5b0: 97FE3EB8  bl       #0x2e090
static inline uint64_t fde_func_0679_0x09e5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e5a4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x19df08ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0680 | PC: 0x09e5bc | FDE: 0x19df40 | Size: 228 bytes
// Khung tháo gỡ #0680 | Địa chỉ PC: 0x09e5bc | Địa chỉ FDE: 0x19df40 | Kích thước: 228 bytes
//   0x09e5bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09e5c0: 910003FD  mov      x29, sp
//   0x09e5c4: F9400400  ldr      x0, [x0, #8]
//   0x09e5c8: 97FFF99E  bl       #0x9cc40
static inline uint64_t fde_func_0680_0x09e5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e5bcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19df40ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0681 | PC: 0x09e6a0 | FDE: 0x19df80 | Size: 60 bytes
// Khung tháo gỡ #0681 | Địa chỉ PC: 0x09e6a0 | Địa chỉ FDE: 0x19df80 | Kích thước: 60 bytes
//   0x09e6a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09e6a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e6a8: 910043FD  add      x29, sp, #0x10
//   0x09e6ac: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0681_0x09e6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e6a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19df80ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0682 | PC: 0x09e6dc | FDE: 0x19e030 | Size: 256 bytes
// Khung tháo gỡ #0682 | Địa chỉ PC: 0x09e6dc | Địa chỉ FDE: 0x19e030 | Kích thước: 256 bytes
//   0x09e6dc: D101C3FF  sub      sp, sp, #0x70
//   0x09e6e0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09e6e4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09e6e8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0682_0x09e6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e6dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x19e030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0683 | PC: 0x09eb60 | FDE: 0x19e078 | Size: 256 bytes
// Khung tháo gỡ #0683 | Địa chỉ PC: 0x09eb60 | Địa chỉ FDE: 0x19e078 | Kích thước: 256 bytes
//   0x09eb60: D10283FF  sub      sp, sp, #0xa0
//   0x09eb64: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x09eb68: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x09eb6c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0683_0x09eb60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09eb60ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x19e078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0684 | PC: 0x09f39c | FDE: 0x19e0c8 | Size: 256 bytes
// Khung tháo gỡ #0684 | Địa chỉ PC: 0x09f39c | Địa chỉ FDE: 0x19e0c8 | Kích thước: 256 bytes
//   0x09f39c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x09f3a0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09f3a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09f3a8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0684_0x09f39c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f39cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19e0c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0685 | PC: 0x09fde8 | FDE: 0x19e120 | Size: 256 bytes
// Khung tháo gỡ #0685 | Địa chỉ PC: 0x09fde8 | Địa chỉ FDE: 0x19e120 | Kích thước: 256 bytes
//   0x09fde8: D10103FF  sub      sp, sp, #0x40
//   0x09fdec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09fdf0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x09fdf4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0685_0x09fde8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fde8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x19e120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0686 | PC: 0x0a03b0 | FDE: 0x19e168 | Size: 256 bytes
// Khung tháo gỡ #0686 | Địa chỉ PC: 0x0a03b0 | Địa chỉ FDE: 0x19e168 | Kích thước: 256 bytes
//   0x0a03b0: D102C3FF  sub      sp, sp, #0xb0
//   0x0a03b4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0a03b8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0a03bc: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0686_0x0a03b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a03b0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x19e168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0687 | PC: 0x0a09a4 | FDE: 0x19e1b0 | Size: 96 bytes
// Khung tháo gỡ #0687 | Địa chỉ PC: 0x0a09a4 | Địa chỉ FDE: 0x19e1b0 | Kích thước: 96 bytes
//   0x0a09a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a09a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a09ac: 910043FD  add      x29, sp, #0x10
//   0x0a09b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0687_0x0a09a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a09a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19e1b0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0688 | PC: 0x0a0a04 | FDE: 0x19e1e8 | Size: 24 bytes
// Khung tháo gỡ #0688 | Địa chỉ PC: 0x0a0a04 | Địa chỉ FDE: 0x19e1e8 | Kích thước: 24 bytes
//   0x0a0a04: D65F03C0  ret      
//   0x0a0a08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a0a0c: 910003FD  mov      x29, sp
//   0x0a0a10: 97FE35A0  bl       #0x2e090
static inline uint64_t fde_func_0688_0x0a0a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0a04ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x19e1e8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0689 | PC: 0x0a0a1c | FDE: 0x19e220 | Size: 256 bytes
// Khung tháo gỡ #0689 | Địa chỉ PC: 0x0a0a1c | Địa chỉ FDE: 0x19e220 | Kích thước: 256 bytes
//   0x0a0a1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a0a20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0a24: 910043FD  add      x29, sp, #0x10
//   0x0a0a28: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0689_0x0a0a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0a1cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19e220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0690 | PC: 0x0a11f8 | FDE: 0x19e290 | Size: 60 bytes
// Khung tháo gỡ #0690 | Địa chỉ PC: 0x0a11f8 | Địa chỉ FDE: 0x19e290 | Kích thước: 60 bytes
//   0x0a11f8: AA1E03E2  mov      x2, x30
//   0x0a11fc: 8B000042  add      x2, x2, x0
//   0x0a1200: AA0203FE  mov      x30, x2
//   0x0a1204: D65F03C0  ret      
static inline uint64_t fde_func_0690_0x0a11f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a11f8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x8b000042ULL) ^ 0x19e290ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0691 | PC: 0x0a1234 | FDE: 0x19e318 | Size: 8 bytes
// Khung tháo gỡ #0691 | Địa chỉ PC: 0x0a1234 | Địa chỉ FDE: 0x19e318 | Kích thước: 8 bytes
//   0x0a1234: D65F03C0  ret      
//   0x0a1238: D65F03C0  ret      
static inline uint64_t fde_func_0691_0x0a1234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1234ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19e318ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0692 | PC: 0x0a123c | FDE: 0x19e348 | Size: 256 bytes
// Khung tháo gỡ #0692 | Địa chỉ PC: 0x0a123c | Địa chỉ FDE: 0x19e348 | Kích thước: 256 bytes
//   0x0a123c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a1240: 910003FD  mov      x29, sp
//   0x0a1244: 52800300  mov      w0, #0x18
//   0x0a1248: 72A20000  movk     w0, #0x1000, lsl #16
static inline uint64_t fde_func_0692_0x0a123c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a123cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0693 | PC: 0x0a13b8 | FDE: 0x19e390 | Size: 256 bytes
// Khung tháo gỡ #0693 | Địa chỉ PC: 0x0a13b8 | Địa chỉ FDE: 0x19e390 | Kích thước: 256 bytes
//   0x0a13b8: D10183FF  sub      sp, sp, #0x60
//   0x0a13bc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a13c0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a13c4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0693_0x0a13b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a13b8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x19e390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0694 | PC: 0x0a14dc | FDE: 0x19e3d0 | Size: 56 bytes
// Khung tháo gỡ #0694 | Địa chỉ PC: 0x0a14dc | Địa chỉ FDE: 0x19e3d0 | Kích thước: 56 bytes
//   0x0a14dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a14e0: 910003FD  mov      x29, sp
//   0x0a14e4: 97FE32EB  bl       #0x2e090
//   0x0a14e8: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0694_0x0a14dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a14dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e3d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0695 | PC: 0x0a1514 | FDE: 0x19e410 | Size: 256 bytes
// Khung tháo gỡ #0695 | Địa chỉ PC: 0x0a1514 | Địa chỉ FDE: 0x19e410 | Kích thước: 256 bytes
//   0x0a1514: D10103FF  sub      sp, sp, #0x40
//   0x0a1518: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a151c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a1520: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0695_0x0a1514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1514ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x19e410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x0a16e4 | FDE: 0x19e450 | Size: 12 bytes
// Khung tháo gỡ #0696 | Địa chỉ PC: 0x0a16e4 | Địa chỉ FDE: 0x19e450 | Kích thước: 12 bytes
//   0x0a16e4: 52800020  mov      w0, #1
//   0x0a16e8: D65F03C0  ret      
//   0x0a16ec: D4200020  brk      #1
static inline uint64_t fde_func_0696_0x0a16e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a16e4ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19e450ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0697 | PC: 0x0a16f0 | FDE: 0x19e4f8 | Size: 8 bytes
// Khung tháo gỡ #0697 | Địa chỉ PC: 0x0a16f0 | Địa chỉ FDE: 0x19e4f8 | Kích thước: 8 bytes
//   0x0a16f0: D65F03C0  ret      
//   0x0a16f4: D65F03C0  ret      
static inline uint64_t fde_func_0697_0x0a16f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a16f0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19e4f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0698 | PC: 0x0a16f8 | FDE: 0x19e528 | Size: 256 bytes
// Khung tháo gỡ #0698 | Địa chỉ PC: 0x0a16f8 | Địa chỉ FDE: 0x19e528 | Kích thước: 256 bytes
//   0x0a16f8: D10483FF  sub      sp, sp, #0x120
//   0x0a16fc: FD0063E8  str      d8, [sp, #0xc0]
//   0x0a1700: F90067FC  str      x28, [sp, #0xc8]
//   0x0a1704: A90D67FA  stp      x26, x25, [sp, #0xd0]
static inline uint64_t fde_func_0698_0x0a16f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a16f8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xfd0063e8ULL) ^ 0x19e528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0699 | PC: 0x0a2324 | FDE: 0x19e570 | Size: 256 bytes
// Khung tháo gỡ #0699 | Địa chỉ PC: 0x0a2324 | Địa chỉ FDE: 0x19e570 | Kích thước: 256 bytes
//   0x0a2324: D10143FF  sub      sp, sp, #0x50
//   0x0a2328: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a232c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a2330: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0699_0x0a2324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2324ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x19e570ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0700 | PC: 0x0a2478 | FDE: 0x19e5b8 | Size: 28 bytes
// Khung tháo gỡ #0700 | Địa chỉ PC: 0x0a2478 | Địa chỉ FDE: 0x19e5b8 | Kích thước: 28 bytes
//   0x0a2478: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a247c: 910003FD  mov      x29, sp
//   0x0a2480: 97FE2F04  bl       #0x2e090
//   0x0a2484: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0700_0x0a2478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2478ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e5b8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0701 | PC: 0x0a2494 | FDE: 0x19e5f0 | Size: 16 bytes
// Khung tháo gỡ #0701 | Địa chỉ PC: 0x0a2494 | Địa chỉ FDE: 0x19e5f0 | Kích thước: 16 bytes
//   0x0a2494: 52800020  mov      w0, #1
//   0x0a2498: D65F03C0  ret      
//   0x0a249c: 52800020  mov      w0, #1
//   0x0a24a0: D65F03C0  ret      
static inline uint64_t fde_func_0701_0x0a2494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2494ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19e5f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0702 | PC: 0x0a24a4 | FDE: 0x19e698 | Size: 256 bytes
// Khung tháo gỡ #0702 | Địa chỉ PC: 0x0a24a4 | Địa chỉ FDE: 0x19e698 | Kích thước: 256 bytes
//   0x0a24a4: D0000908  adrp     x8, #0x1c4000
//   0x0a24a8: 9119C108  add      x8, x8, #0x670
//   0x0a24ac: F9000008  str      x8, [x0]
//   0x0a24b0: 3DC00020  ldr      q0, [x1]
static inline uint64_t fde_func_0702_0x0a24a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a24a4ULL ^ (static_cast<uint64_t>(0xd0000908ULL) << 13);
    acc = (acc + a1 + 0x9119c108ULL) ^ 0x19e698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0703 | PC: 0x0a2740 | FDE: 0x19e6d0 | Size: 256 bytes
// Khung tháo gỡ #0703 | Địa chỉ PC: 0x0a2740 | Địa chỉ FDE: 0x19e6d0 | Kích thước: 256 bytes
//   0x0a2740: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2744: 910003FD  mov      x29, sp
//   0x0a2748: 52800620  mov      w0, #0x31
//   0x0a274c: 72A02000  movk     w0, #0x100, lsl #16
static inline uint64_t fde_func_0703_0x0a2740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2740ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0704 | PC: 0x0a2844 | FDE: 0x19e710 | Size: 256 bytes
// Khung tháo gỡ #0704 | Địa chỉ PC: 0x0a2844 | Địa chỉ FDE: 0x19e710 | Kích thước: 256 bytes
//   0x0a2844: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2848: 910003FD  mov      x29, sp
//   0x0a284c: 52800780  mov      w0, #0x3c
//   0x0a2850: 72A02000  movk     w0, #0x100, lsl #16
static inline uint64_t fde_func_0704_0x0a2844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2844ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0705 | PC: 0x0a29dc | FDE: 0x19e758 | Size: 256 bytes
// Khung tháo gỡ #0705 | Địa chỉ PC: 0x0a29dc | Địa chỉ FDE: 0x19e758 | Kích thước: 256 bytes
//   0x0a29dc: D10183FF  sub      sp, sp, #0x60
//   0x0a29e0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a29e4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a29e8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0705_0x0a29dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a29dcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x19e758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0706 | PC: 0x0a2afc | FDE: 0x19e7a0 | Size: 256 bytes
// Khung tháo gỡ #0706 | Địa chỉ PC: 0x0a2afc | Địa chỉ FDE: 0x19e7a0 | Kích thước: 256 bytes
//   0x0a2afc: D10143FF  sub      sp, sp, #0x50
//   0x0a2b00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a2b04: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a2b08: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0706_0x0a2afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2afcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x19e7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0707 | PC: 0x0a2d40 | FDE: 0x19e7e8 | Size: 76 bytes
// Khung tháo gỡ #0707 | Địa chỉ PC: 0x0a2d40 | Địa chỉ FDE: 0x19e7e8 | Kích thước: 76 bytes
//   0x0a2d40: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2d44: 910003FD  mov      x29, sp
//   0x0a2d48: 97FE2CD2  bl       #0x2e090
//   0x0a2d4c: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0707_0x0a2d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2d40ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e7e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0708 | PC: 0x0a2d8c | FDE: 0x19e828 | Size: 28 bytes
// Khung tháo gỡ #0708 | Địa chỉ PC: 0x0a2d8c | Địa chỉ FDE: 0x19e828 | Kích thước: 28 bytes
//   0x0a2d8c: D0000908  adrp     x8, #0x1c4000
//   0x0a2d90: 911EA108  add      x8, x8, #0x7a8
//   0x0a2d94: F9000028  str      x8, [x1]
//   0x0a2d98: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0708_0x0a2d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2d8cULL ^ (static_cast<uint64_t>(0xd0000908ULL) << 13);
    acc = (acc + a1 + 0x911ea108ULL) ^ 0x19e828ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0709 | PC: 0x0a2da8 | FDE: 0x19e858 | Size: 244 bytes
// Khung tháo gỡ #0709 | Địa chỉ PC: 0x0a2da8 | Địa chỉ FDE: 0x19e858 | Kích thước: 244 bytes
//   0x0a2da8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2dac: 910003FD  mov      x29, sp
//   0x0a2db0: 97FE2CB8  bl       #0x2e090
//   0x0a2db4: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0709_0x0a2da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2da8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e858ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0710 | PC: 0x0a2e9c | FDE: 0x19e918 | Size: 44 bytes
// Khung tháo gỡ #0710 | Địa chỉ PC: 0x0a2e9c | Địa chỉ FDE: 0x19e918 | Kích thước: 44 bytes
//   0x0a2e9c: D0000908  adrp     x8, #0x1c4000
//   0x0a2ea0: 9119C108  add      x8, x8, #0x670
//   0x0a2ea4: F9000008  str      x8, [x0]
//   0x0a2ea8: 3DC00020  ldr      q0, [x1]
static inline uint64_t fde_func_0710_0x0a2e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2e9cULL ^ (static_cast<uint64_t>(0xd0000908ULL) << 13);
    acc = (acc + a1 + 0x9119c108ULL) ^ 0x19e918ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0711 | PC: 0x0a2ec8 | FDE: 0x19e948 | Size: 8 bytes
// Khung tháo gỡ #0711 | Địa chỉ PC: 0x0a2ec8 | Địa chỉ FDE: 0x19e948 | Kích thước: 8 bytes
//   0x0a2ec8: D65F03C0  ret      
//   0x0a2ecc: D65F03C0  ret      
static inline uint64_t fde_func_0711_0x0a2ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2ec8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19e948ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0712 | PC: 0x0a2ed0 | FDE: 0x19e978 | Size: 8 bytes
// Khung tháo gỡ #0712 | Địa chỉ PC: 0x0a2ed0 | Địa chỉ FDE: 0x19e978 | Kích thước: 8 bytes
//   0x0a2ed0: D65F03C0  ret      
//   0x0a2ed4: D65F03C0  ret      
static inline uint64_t fde_func_0712_0x0a2ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2ed0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19e978ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0713 | PC: 0x0a2ed8 | FDE: 0x19e9a8 | Size: 256 bytes
// Khung tháo gỡ #0713 | Địa chỉ PC: 0x0a2ed8 | Địa chỉ FDE: 0x19e9a8 | Kích thước: 256 bytes
//   0x0a2ed8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2edc: 910003FD  mov      x29, sp
//   0x0a2ee0: 97FE2C6C  bl       #0x2e090
//   0x0a2ee4: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0713_0x0a2ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2ed8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19e9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0714 | PC: 0x0a3038 | FDE: 0x19e9e8 | Size: 248 bytes
// Khung tháo gỡ #0714 | Địa chỉ PC: 0x0a3038 | Địa chỉ FDE: 0x19e9e8 | Kích thước: 248 bytes
//   0x0a3038: D10103FF  sub      sp, sp, #0x40
//   0x0a303c: FD0013E8  str      d8, [sp, #0x20]
//   0x0a3040: F90017F3  str      x19, [sp, #0x28]
//   0x0a3044: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0714_0x0a3038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3038ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x19e9e8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0715 | PC: 0x0a3130 | FDE: 0x19ea98 | Size: 256 bytes
// Khung tháo gỡ #0715 | Địa chỉ PC: 0x0a3130 | Địa chỉ FDE: 0x19ea98 | Kích thước: 256 bytes
//   0x0a3130: B0000908  adrp     x8, #0x1c4000
//   0x0a3134: 9119C108  add      x8, x8, #0x670
//   0x0a3138: F9000008  str      x8, [x0]
//   0x0a313c: 3DC00020  ldr      q0, [x1]
static inline uint64_t fde_func_0715_0x0a3130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3130ULL ^ (static_cast<uint64_t>(0xb0000908ULL) << 13);
    acc = (acc + a1 + 0x9119c108ULL) ^ 0x19ea98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0716 | PC: 0x0a3404 | FDE: 0x19ead8 | Size: 180 bytes
// Khung tháo gỡ #0716 | Địa chỉ PC: 0x0a3404 | Địa chỉ FDE: 0x19ead8 | Kích thước: 180 bytes
//   0x0a3404: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a3408: 910003FD  mov      x29, sp
//   0x0a340c: 52800200  mov      w0, #0x10
//   0x0a3410: 72A20000  movk     w0, #0x1000, lsl #16
static inline uint64_t fde_func_0716_0x0a3404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3404ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19ead8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0717 | PC: 0x0a34b8 | FDE: 0x19eb18 | Size: 256 bytes
// Khung tháo gỡ #0717 | Địa chỉ PC: 0x0a34b8 | Địa chỉ FDE: 0x19eb18 | Kích thước: 256 bytes
//   0x0a34b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a34bc: 910003FD  mov      x29, sp
//   0x0a34c0: 528002E0  mov      w0, #0x17
//   0x0a34c4: 72A20000  movk     w0, #0x1000, lsl #16
static inline uint64_t fde_func_0717_0x0a34b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a34b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19eb18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0718 | PC: 0x0a3634 | FDE: 0x19eb60 | Size: 256 bytes
// Khung tháo gỡ #0718 | Địa chỉ PC: 0x0a3634 | Địa chỉ FDE: 0x19eb60 | Kích thước: 256 bytes
//   0x0a3634: D10183FF  sub      sp, sp, #0x60
//   0x0a3638: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a363c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a3640: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0718_0x0a3634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3634ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x19eb60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0719 | PC: 0x0a3754 | FDE: 0x19eba8 | Size: 256 bytes
// Khung tháo gỡ #0719 | Địa chỉ PC: 0x0a3754 | Địa chỉ FDE: 0x19eba8 | Kích thước: 256 bytes
//   0x0a3754: D10143FF  sub      sp, sp, #0x50
//   0x0a3758: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a375c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a3760: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0719_0x0a3754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3754ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x19eba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0720 | PC: 0x0a399c | FDE: 0x19ebf0 | Size: 76 bytes
// Khung tháo gỡ #0720 | Địa chỉ PC: 0x0a399c | Địa chỉ FDE: 0x19ebf0 | Kích thước: 76 bytes
//   0x0a399c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a39a0: 910003FD  mov      x29, sp
//   0x0a39a4: 97FE29BB  bl       #0x2e090
//   0x0a39a8: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0720_0x0a399c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a399cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19ebf0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0721 | PC: 0x0a39e8 | FDE: 0x19ec30 | Size: 28 bytes
// Khung tháo gỡ #0721 | Địa chỉ PC: 0x0a39e8 | Địa chỉ FDE: 0x19ec30 | Kích thước: 28 bytes
//   0x0a39e8: B0000908  adrp     x8, #0x1c4000
//   0x0a39ec: 91230108  add      x8, x8, #0x8c0
//   0x0a39f0: F9000028  str      x8, [x1]
//   0x0a39f4: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0721_0x0a39e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a39e8ULL ^ (static_cast<uint64_t>(0xb0000908ULL) << 13);
    acc = (acc + a1 + 0x91230108ULL) ^ 0x19ec30ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0722 | PC: 0x0a3a04 | FDE: 0x19ec60 | Size: 188 bytes
// Khung tháo gỡ #0722 | Địa chỉ PC: 0x0a3a04 | Địa chỉ FDE: 0x19ec60 | Kích thước: 188 bytes
//   0x0a3a04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a3a08: 910003FD  mov      x29, sp
//   0x0a3a0c: 97FE29A1  bl       #0x2e090
//   0x0a3a10: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0722_0x0a3a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3a04ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19ec60ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0723 | PC: 0x0a3ac0 | FDE: 0x19ecc8 | Size: 256 bytes
// Khung tháo gỡ #0723 | Địa chỉ PC: 0x0a3ac0 | Địa chỉ FDE: 0x19ecc8 | Kích thước: 256 bytes
//   0x0a3ac0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a3ac4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a3ac8: 910043FD  add      x29, sp, #0x10
//   0x0a3acc: B00009C0  adrp     x0, #0x1dc000
static inline uint64_t fde_func_0723_0x0a3ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3ac0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19ecc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0724 | PC: 0x0a3f68 | FDE: 0x19ed80 | Size: 56 bytes
// Khung tháo gỡ #0724 | Địa chỉ PC: 0x0a3f68 | Địa chỉ FDE: 0x19ed80 | Kích thước: 56 bytes
//   0x0a3f68: 528000C0  mov      w0, #6
//   0x0a3f6c: D65F03C0  ret      
//   0x0a3f70: B0000908  adrp     x8, #0x1c4000
//   0x0a3f74: 91242108  add      x8, x8, #0x908
static inline uint64_t fde_func_0724_0x0a3f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3f68ULL ^ (static_cast<uint64_t>(0x528000c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x19ed80ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0725 | PC: 0x0a3fa0 | FDE: 0x19edb0 | Size: 256 bytes
// Khung tháo gỡ #0725 | Địa chỉ PC: 0x0a3fa0 | Địa chỉ FDE: 0x19edb0 | Kích thước: 256 bytes
//   0x0a3fa0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a3fa4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a3fa8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a3fac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0725_0x0a3fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3fa0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19edb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0726 | PC: 0x0a40a4 | FDE: 0x19edf8 | Size: 256 bytes
// Khung tháo gỡ #0726 | Địa chỉ PC: 0x0a40a4 | Địa chỉ FDE: 0x19edf8 | Kích thước: 256 bytes
//   0x0a40a4: D102C3FF  sub      sp, sp, #0xb0
//   0x0a40a8: F90033F9  str      x25, [sp, #0x60]
//   0x0a40ac: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0a40b0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0726_0x0a40a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a40a4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x19edf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0727 | PC: 0x0a473c | FDE: 0x19ee48 | Size: 256 bytes
// Khung tháo gỡ #0727 | Địa chỉ PC: 0x0a473c | Địa chỉ FDE: 0x19ee48 | Kích thước: 256 bytes
//   0x0a473c: D10383FF  sub      sp, sp, #0xe0
//   0x0a4740: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0a4744: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x0a4748: A90B57F6  stp      x22, x21, [sp, #0xb0]
static inline uint64_t fde_func_0727_0x0a473c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a473cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90967faULL) ^ 0x19ee48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0728 | PC: 0x0a4c58 | FDE: 0x19ee98 | Size: 76 bytes
// Khung tháo gỡ #0728 | Địa chỉ PC: 0x0a4c58 | Địa chỉ FDE: 0x19ee98 | Kích thước: 76 bytes
//   0x0a4c58: D65F03C0  ret      
//   0x0a4c5c: B4000221  cbz      x1, #0xa4ca0
//   0x0a4c60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a4c64: A9017BFD  stp      x29, x30, [sp, #0x10]
static inline uint64_t fde_func_0728_0x0a4c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4c58ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xb4000221ULL) ^ 0x19ee98ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0729 | PC: 0x0a4ca4 | FDE: 0x19eed0 | Size: 256 bytes
// Khung tháo gỡ #0729 | Địa chỉ PC: 0x0a4ca4 | Địa chỉ FDE: 0x19eed0 | Kích thước: 256 bytes
//   0x0a4ca4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a4ca8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a4cac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a4cb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0729_0x0a4ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4ca4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x19eed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0730 | PC: 0x0a4dc8 | FDE: 0x19ef30 | Size: 256 bytes
// Khung tháo gỡ #0730 | Địa chỉ PC: 0x0a4dc8 | Địa chỉ FDE: 0x19ef30 | Kích thước: 256 bytes
//   0x0a4dc8: D10143FF  sub      sp, sp, #0x50
//   0x0a4dcc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a4dd0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a4dd4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0730_0x0a4dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4dc8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x19ef30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0731 | PC: 0x0a520c | FDE: 0x19f000 | Size: 256 bytes
// Khung tháo gỡ #0731 | Địa chỉ PC: 0x0a520c | Địa chỉ FDE: 0x19f000 | Kích thước: 256 bytes
//   0x0a520c: 39400008  ldrb     w8, [x0]
//   0x0a5210: 350000C8  cbnz     w8, #0xa5228
//   0x0a5214: 39400408  ldrb     w8, [x0, #1]
//   0x0a5218: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_0731_0x0a520c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a520cULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x350000c8ULL) ^ 0x19f000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0732 | PC: 0x0a54c8 | FDE: 0x19f048 | Size: 28 bytes
// Khung tháo gỡ #0732 | Địa chỉ PC: 0x0a54c8 | Địa chỉ FDE: 0x19f048 | Kích thước: 28 bytes
//   0x0a54c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a54cc: 910003FD  mov      x29, sp
//   0x0a54d0: 97FFFE6C  bl       #0xa4e80
//   0x0a54d4: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0732_0x0a54c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a54c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19f048ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0733 | PC: 0x0a54e4 | FDE: 0x19f080 | Size: 244 bytes
// Khung tháo gỡ #0733 | Địa chỉ PC: 0x0a54e4 | Địa chỉ FDE: 0x19f080 | Kích thước: 244 bytes
//   0x0a54e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a54e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a54ec: 910043FD  add      x29, sp, #0x10
//   0x0a54f0: 91002014  add      x20, x0, #8
static inline uint64_t fde_func_0733_0x0a54e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a54e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f080ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0734 | PC: 0x0a55d8 | FDE: 0x19f0c8 | Size: 188 bytes
// Khung tháo gỡ #0734 | Địa chỉ PC: 0x0a55d8 | Địa chỉ FDE: 0x19f0c8 | Kích thước: 188 bytes
//   0x0a55d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a55dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a55e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a55e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0734_0x0a55d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a55d8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x19f0c8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0735 | PC: 0x0a5694 | FDE: 0x19f108 | Size: 72 bytes
// Khung tháo gỡ #0735 | Địa chỉ PC: 0x0a5694 | Địa chỉ FDE: 0x19f108 | Kích thước: 72 bytes
//   0x0a5694: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a5698: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a569c: 910043FD  add      x29, sp, #0x10
//   0x0a56a0: F00008E8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0735_0x0a5694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5694ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f108ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0736 | PC: 0x0a56dc | FDE: 0x19f140 | Size: 40 bytes
// Khung tháo gỡ #0736 | Địa chỉ PC: 0x0a56dc | Địa chỉ FDE: 0x19f140 | Kích thước: 40 bytes
//   0x0a56dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a56e0: 910003FD  mov      x29, sp
//   0x0a56e4: 90000721  adrp     x1, #0x189000
//   0x0a56e8: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0736_0x0a56dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a56dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19f140ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0737 | PC: 0x0a5704 | FDE: 0x19f198 | Size: 252 bytes
// Khung tháo gỡ #0737 | Địa chỉ PC: 0x0a5704 | Địa chỉ FDE: 0x19f198 | Kích thước: 252 bytes
//   0x0a5704: AA1E03E3  mov      x3, x30
//   0x0a5708: 8B000063  add      x3, x3, x0
//   0x0a570c: AA0303FE  mov      x30, x3
//   0x0a5710: D65F03C0  ret      
static inline uint64_t fde_func_0737_0x0a5704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5704ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x8b000063ULL) ^ 0x19f198ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0738 | PC: 0x0a5800 | FDE: 0x19f228 | Size: 184 bytes
// Khung tháo gỡ #0738 | Địa chỉ PC: 0x0a5800 | Địa chỉ FDE: 0x19f228 | Kích thước: 184 bytes
//   0x0a5800: 90000000  adrp     x0, #0xa5000
//   0x0a5804: 91203000  add      x0, x0, #0x80c
//   0x0a5808: D65F03C0  ret      
//   0x0a580c: D101C3FF  sub      sp, sp, #0x70
static inline uint64_t fde_func_0738_0x0a5800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5800ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x91203000ULL) ^ 0x19f228ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0739 | PC: 0x0a58b8 | FDE: 0x19f280 | Size: 256 bytes
// Khung tháo gỡ #0739 | Địa chỉ PC: 0x0a58b8 | Địa chỉ FDE: 0x19f280 | Kích thước: 256 bytes
//   0x0a58b8: AA1E03E2  mov      x2, x30
//   0x0a58bc: 8B000042  add      x2, x2, x0
//   0x0a58c0: AA0203FE  mov      x30, x2
//   0x0a58c4: D65F03C0  ret      
static inline uint64_t fde_func_0739_0x0a58b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a58b8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x8b000042ULL) ^ 0x19f280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0740 | PC: 0x0a5a0c | FDE: 0x19f338 | Size: 256 bytes
// Khung tháo gỡ #0740 | Địa chỉ PC: 0x0a5a0c | Địa chỉ FDE: 0x19f338 | Kích thước: 256 bytes
//   0x0a5a0c: AA1E03E1  mov      x1, x30
//   0x0a5a10: 8B000021  add      x1, x1, x0
//   0x0a5a14: AA0103FE  mov      x30, x1
//   0x0a5a18: D65F03C0  ret      
static inline uint64_t fde_func_0740_0x0a5a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5a0cULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x19f338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0741 | PC: 0x0a784c | FDE: 0x19f3d8 | Size: 256 bytes
// Khung tháo gỡ #0741 | Địa chỉ PC: 0x0a784c | Địa chỉ FDE: 0x19f3d8 | Kích thước: 256 bytes
//   0x0a784c: D10203FF  sub      sp, sp, #0x80
//   0x0a7850: F90013FB  str      x27, [sp, #0x20]
//   0x0a7854: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a7858: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0741_0x0a784c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a784cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x19f3d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0742 | PC: 0x0a7b24 | FDE: 0x19f428 | Size: 256 bytes
// Khung tháo gỡ #0742 | Địa chỉ PC: 0x0a7b24 | Địa chỉ FDE: 0x19f428 | Kích thước: 256 bytes
//   0x0a7b24: D10183FF  sub      sp, sp, #0x60
//   0x0a7b28: F9001BF5  str      x21, [sp, #0x30]
//   0x0a7b2c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a7b30: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0742_0x0a7b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7b24ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x19f428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0743 | PC: 0x0a7d34 | FDE: 0x19f468 | Size: 256 bytes
// Khung tháo gỡ #0743 | Địa chỉ PC: 0x0a7d34 | Địa chỉ FDE: 0x19f468 | Kích thước: 256 bytes
//   0x0a7d34: D10183FF  sub      sp, sp, #0x60
//   0x0a7d38: F9001BF5  str      x21, [sp, #0x30]
//   0x0a7d3c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a7d40: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0743_0x0a7d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7d34ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x19f468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0744 | PC: 0x0a7f7c | FDE: 0x19f4a8 | Size: 256 bytes
// Khung tháo gỡ #0744 | Địa chỉ PC: 0x0a7f7c | Địa chỉ FDE: 0x19f4a8 | Kích thước: 256 bytes
//   0x0a7f7c: D10143FF  sub      sp, sp, #0x50
//   0x0a7f80: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a7f84: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a7f88: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0744_0x0a7f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7f7cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19f4a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0745 | PC: 0x0a81c4 | FDE: 0x19f4f0 | Size: 256 bytes
// Khung tháo gỡ #0745 | Địa chỉ PC: 0x0a81c4 | Địa chỉ FDE: 0x19f4f0 | Kích thước: 256 bytes
//   0x0a81c4: D10143FF  sub      sp, sp, #0x50
//   0x0a81c8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a81cc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a81d0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0745_0x0a81c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a81c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19f4f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0746 | PC: 0x0a83a8 | FDE: 0x19f530 | Size: 256 bytes
// Khung tháo gỡ #0746 | Địa chỉ PC: 0x0a83a8 | Địa chỉ FDE: 0x19f530 | Kích thước: 256 bytes
//   0x0a83a8: D10143FF  sub      sp, sp, #0x50
//   0x0a83ac: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a83b0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a83b4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0746_0x0a83a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a83a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19f530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0747 | PC: 0x0a8594 | FDE: 0x19f570 | Size: 256 bytes
// Khung tháo gỡ #0747 | Địa chỉ PC: 0x0a8594 | Địa chỉ FDE: 0x19f570 | Kích thước: 256 bytes
//   0x0a8594: D10143FF  sub      sp, sp, #0x50
//   0x0a8598: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a859c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a85a0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0747_0x0a8594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8594ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19f570ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0748 | PC: 0x0a8768 | FDE: 0x19f5b0 | Size: 256 bytes
// Khung tháo gỡ #0748 | Địa chỉ PC: 0x0a8768 | Địa chỉ FDE: 0x19f5b0 | Kích thước: 256 bytes
//   0x0a8768: D10143FF  sub      sp, sp, #0x50
//   0x0a876c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a8770: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a8774: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0748_0x0a8768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8768ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19f5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x0a8988 | FDE: 0x19f668 | Size: 256 bytes
// Khung tháo gỡ #0749 | Địa chỉ PC: 0x0a8988 | Địa chỉ FDE: 0x19f668 | Kích thước: 256 bytes
//   0x0a8988: D10103FF  sub      sp, sp, #0x40
//   0x0a898c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a8990: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a8994: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0749_0x0a8988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8988ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x19f668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0750 | PC: 0x0a9650 | FDE: 0x19f6b8 | Size: 112 bytes
// Khung tháo gỡ #0750 | Địa chỉ PC: 0x0a9650 | Địa chỉ FDE: 0x19f6b8 | Kích thước: 112 bytes
//   0x0a9650: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a9654: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a9658: 910043FD  add      x29, sp, #0x10
//   0x0a965c: F00008C8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0750_0x0a9650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9650ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f6b8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0751 | PC: 0x0a96c0 | FDE: 0x19f718 | Size: 156 bytes
// Khung tháo gỡ #0751 | Địa chỉ PC: 0x0a96c0 | Địa chỉ FDE: 0x19f718 | Kích thước: 156 bytes
//   0x0a96c0: AA1E03E1  mov      x1, x30
//   0x0a96c4: 8B000021  add      x1, x1, x0
//   0x0a96c8: AA0103FE  mov      x30, x1
//   0x0a96cc: D65F03C0  ret      
static inline uint64_t fde_func_0751_0x0a96c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a96c0ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x19f718ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0752 | PC: 0x0a975c | FDE: 0x19f7a8 | Size: 256 bytes
// Khung tháo gỡ #0752 | Địa chỉ PC: 0x0a975c | Địa chỉ FDE: 0x19f7a8 | Kích thước: 256 bytes
//   0x0a975c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a9760: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a9764: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a9768: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0752_0x0a975c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a975cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x19f7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0753 | PC: 0x0a9c9c | FDE: 0x19f7f8 | Size: 96 bytes
// Khung tháo gỡ #0753 | Địa chỉ PC: 0x0a9c9c | Địa chỉ FDE: 0x19f7f8 | Kích thước: 96 bytes
//   0x0a9c9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a9ca0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a9ca4: 910043FD  add      x29, sp, #0x10
//   0x0a9ca8: F00008C8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0753_0x0a9c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9c9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f7f8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0754 | PC: 0x0a9cfc | FDE: 0x19f8a8 | Size: 256 bytes
// Khung tháo gỡ #0754 | Địa chỉ PC: 0x0a9cfc | Địa chỉ FDE: 0x19f8a8 | Kích thước: 256 bytes
//   0x0a9cfc: D10143FF  sub      sp, sp, #0x50
//   0x0a9d00: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a9d04: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a9d08: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0754_0x0a9cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9cfcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x19f8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0755 | PC: 0x0aa2a4 | FDE: 0x19f8f8 | Size: 256 bytes
// Khung tháo gỡ #0755 | Địa chỉ PC: 0x0aa2a4 | Địa chỉ FDE: 0x19f8f8 | Kích thước: 256 bytes
//   0x0aa2a4: D102C3FF  sub      sp, sp, #0xb0
//   0x0aa2a8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0aa2ac: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0aa2b0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0755_0x0aa2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa2a4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x19f8f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0756 | PC: 0x0aa6fc | FDE: 0x19f948 | Size: 256 bytes
// Khung tháo gỡ #0756 | Địa chỉ PC: 0x0aa6fc | Địa chỉ FDE: 0x19f948 | Kích thước: 256 bytes
//   0x0aa6fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0aa700: 910003FD  mov      x29, sp
//   0x0aa704: D0000988  adrp     x8, #0x1dc000
//   0x0aa708: 912CA108  add      x8, x8, #0xb28
static inline uint64_t fde_func_0756_0x0aa6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa6fcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19f948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0757 | PC: 0x0aa9b4 | FDE: 0x19f998 | Size: 256 bytes
// Khung tháo gỡ #0757 | Địa chỉ PC: 0x0aa9b4 | Địa chỉ FDE: 0x19f998 | Kích thước: 256 bytes
//   0x0aa9b4: D10543FF  sub      sp, sp, #0x150
//   0x0aa9b8: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0aa9bc: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x0aa9c0: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_0757_0x0aa9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa9b4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x19f998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0758 | PC: 0x0ab2ec | FDE: 0x19f9f0 | Size: 60 bytes
// Khung tháo gỡ #0758 | Địa chỉ PC: 0x0ab2ec | Địa chỉ FDE: 0x19f9f0 | Kích thước: 60 bytes
//   0x0ab2ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ab2f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ab2f4: 910043FD  add      x29, sp, #0x10
//   0x0ab2f8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0758_0x0ab2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab2ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f9f0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0759 | PC: 0x0ab328 | FDE: 0x19fa30 | Size: 112 bytes
// Khung tháo gỡ #0759 | Địa chỉ PC: 0x0ab328 | Địa chỉ FDE: 0x19fa30 | Kích thước: 112 bytes
//   0x0ab328: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ab32c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ab330: 910043FD  add      x29, sp, #0x10
//   0x0ab334: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0759_0x0ab328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab328ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fa30ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0760 | PC: 0x0ab398 | FDE: 0x19fa68 | Size: 24 bytes
// Khung tháo gỡ #0760 | Địa chỉ PC: 0x0ab398 | Địa chỉ FDE: 0x19fa68 | Kích thước: 24 bytes
//   0x0ab398: D65F03C0  ret      
//   0x0ab39c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ab3a0: 910003FD  mov      x29, sp
//   0x0ab3a4: 97FE0B3B  bl       #0x2e090
static inline uint64_t fde_func_0760_0x0ab398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab398ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x19fa68ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0761 | PC: 0x0ab3b0 | FDE: 0x19faa0 | Size: 256 bytes
// Khung tháo gỡ #0761 | Địa chỉ PC: 0x0ab3b0 | Địa chỉ FDE: 0x19faa0 | Kích thước: 256 bytes
//   0x0ab3b0: D106C3FF  sub      sp, sp, #0x1b0
//   0x0ab3b4: F900ABFC  str      x28, [sp, #0x150]
//   0x0ab3b8: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0ab3bc: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_0761_0x0ab3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab3b0ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x19faa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0762 | PC: 0x0abdc0 | FDE: 0x19fb70 | Size: 256 bytes
// Khung tháo gỡ #0762 | Địa chỉ PC: 0x0abdc0 | Địa chỉ FDE: 0x19fb70 | Kích thước: 256 bytes
//   0x0abdc0: D10183FF  sub      sp, sp, #0x60
//   0x0abdc4: F9001BF5  str      x21, [sp, #0x30]
//   0x0abdc8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0abdcc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0762_0x0abdc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abdc0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x19fb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0763 | PC: 0x0ac530 | FDE: 0x19fbb8 | Size: 256 bytes
// Khung tháo gỡ #0763 | Địa chỉ PC: 0x0ac530 | Địa chỉ FDE: 0x19fbb8 | Kích thước: 256 bytes
//   0x0ac530: D107C3FF  sub      sp, sp, #0x1f0
//   0x0ac534: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0ac538: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0ac53c: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
static inline uint64_t fde_func_0763_0x0ac530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac530ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa9196ffcULL) ^ 0x19fbb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0764 | PC: 0x0ac944 | FDE: 0x19fc08 | Size: 256 bytes
// Khung tháo gỡ #0764 | Địa chỉ PC: 0x0ac944 | Địa chỉ FDE: 0x19fc08 | Kích thước: 256 bytes
//   0x0ac944: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac948: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac94c: 910043FD  add      x29, sp, #0x10
//   0x0ac950: 900008C8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0764_0x0ac944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac944ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fc08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0765 | PC: 0x0aca80 | FDE: 0x19fcc0 | Size: 256 bytes
// Khung tháo gỡ #0765 | Địa chỉ PC: 0x0aca80 | Địa chỉ FDE: 0x19fcc0 | Kích thước: 256 bytes
//   0x0aca80: D101C3FF  sub      sp, sp, #0x70
//   0x0aca84: F9001BF7  str      x23, [sp, #0x30]
//   0x0aca88: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0aca8c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0765_0x0aca80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aca80ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x19fcc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0766 | PC: 0x0acc40 | FDE: 0x19fd10 | Size: 144 bytes
// Khung tháo gỡ #0766 | Địa chỉ PC: 0x0acc40 | Địa chỉ FDE: 0x19fd10 | Kích thước: 144 bytes
//   0x0acc40: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0acc44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0acc48: 910043FD  add      x29, sp, #0x10
//   0x0acc4c: 900008C8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0766_0x0acc40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acc40ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fd10ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0767 | PC: 0x0accd0 | FDE: 0x19fdc8 | Size: 256 bytes
// Khung tháo gỡ #0767 | Địa chỉ PC: 0x0accd0 | Địa chỉ FDE: 0x19fdc8 | Kích thước: 256 bytes
//   0x0accd0: D10343FF  sub      sp, sp, #0xd0
//   0x0accd4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0accd8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0accdc: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0767_0x0accd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0accd0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x19fdc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0768 | PC: 0x0ad034 | FDE: 0x19fe10 | Size: 256 bytes
// Khung tháo gỡ #0768 | Địa chỉ PC: 0x0ad034 | Địa chỉ FDE: 0x19fe10 | Kích thước: 256 bytes
//   0x0ad034: D107C3FF  sub      sp, sp, #0x1f0
//   0x0ad038: FD00BBEA  str      d10, [sp, #0x170]
//   0x0ad03c: 6D1823E9  stp      d9, d8, [sp, #0x180]
//   0x0ad040: A9196FFC  stp      x28, x27, [sp, #0x190]
static inline uint64_t fde_func_0768_0x0ad034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad034ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xfd00bbeaULL) ^ 0x19fe10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0769 | PC: 0x0adabc | FDE: 0x19fe68 | Size: 72 bytes
// Khung tháo gỡ #0769 | Địa chỉ PC: 0x0adabc | Địa chỉ FDE: 0x19fe68 | Kích thước: 72 bytes
//   0x0adabc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0adac0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0adac4: 910043FD  add      x29, sp, #0x10
//   0x0adac8: 7100043F  cmp      w1, #1
static inline uint64_t fde_func_0769_0x0adabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adabcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fe68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0770 | PC: 0x0adb04 | FDE: 0x19fea0 | Size: 60 bytes
// Khung tháo gỡ #0770 | Địa chỉ PC: 0x0adb04 | Địa chỉ FDE: 0x19fea0 | Kích thước: 60 bytes
//   0x0adb04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0adb08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0adb0c: 910043FD  add      x29, sp, #0x10
//   0x0adb10: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0770_0x0adb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adb04ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fea0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0771 | PC: 0x0adb40 | FDE: 0x19fee0 | Size: 80 bytes
// Khung tháo gỡ #0771 | Địa chỉ PC: 0x0adb40 | Địa chỉ FDE: 0x19fee0 | Kích thước: 80 bytes
//   0x0adb40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0adb44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0adb48: 910043FD  add      x29, sp, #0x10
//   0x0adb4c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0771_0x0adb40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adb40ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fee0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0772 | PC: 0x0adb90 | FDE: 0x19ff18 | Size: 24 bytes
// Khung tháo gỡ #0772 | Địa chỉ PC: 0x0adb90 | Địa chỉ FDE: 0x19ff18 | Kích thước: 24 bytes
//   0x0adb90: D65F03C0  ret      
//   0x0adb94: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0adb98: 910003FD  mov      x29, sp
//   0x0adb9c: 97FE013D  bl       #0x2e090
static inline uint64_t fde_func_0772_0x0adb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adb90ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x19ff18ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0773 | PC: 0x0adba8 | FDE: 0x19ff50 | Size: 68 bytes
// Khung tháo gỡ #0773 | Địa chỉ PC: 0x0adba8 | Địa chỉ FDE: 0x19ff50 | Kích thước: 68 bytes
//   0x0adba8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0adbac: 910003FD  mov      x29, sp
//   0x0adbb0: 52800340  mov      w0, #0x1a
//   0x0adbb4: 72A20000  movk     w0, #0x1000, lsl #16
static inline uint64_t fde_func_0773_0x0adba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adba8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x19ff50ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0774 | PC: 0x0adbec | FDE: 0x1a0000 | Size: 256 bytes
// Khung tháo gỡ #0774 | Địa chỉ PC: 0x0adbec | Địa chỉ FDE: 0x1a0000 | Kích thước: 256 bytes
//   0x0adbec: D10283FF  sub      sp, sp, #0xa0
//   0x0adbf0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0adbf4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0adbf8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0774_0x0adbec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adbecULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x1a0000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0775 | PC: 0x0ae7ac | FDE: 0x1a0058 | Size: 76 bytes
// Khung tháo gỡ #0775 | Địa chỉ PC: 0x0ae7ac | Địa chỉ FDE: 0x1a0058 | Kích thước: 76 bytes
//   0x0ae7ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ae7b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ae7b4: 910043FD  add      x29, sp, #0x10
//   0x0ae7b8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0775_0x0ae7ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae7acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0058ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0776 | PC: 0x0ae7f8 | FDE: 0x1a0108 | Size: 256 bytes
// Khung tháo gỡ #0776 | Địa chỉ PC: 0x0ae7f8 | Địa chỉ FDE: 0x1a0108 | Kích thước: 256 bytes
//   0x0ae7f8: D10303FF  sub      sp, sp, #0xc0
//   0x0ae7fc: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0ae800: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0ae804: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0776_0x0ae7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae7f8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x1a0108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0777 | PC: 0x0aec4c | FDE: 0x1a0158 | Size: 256 bytes
// Khung tháo gỡ #0777 | Địa chỉ PC: 0x0aec4c | Địa chỉ FDE: 0x1a0158 | Kích thước: 256 bytes
//   0x0aec4c: D10143FF  sub      sp, sp, #0x50
//   0x0aec50: F90013F5  str      x21, [sp, #0x20]
//   0x0aec54: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0aec58: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0777_0x0aec4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aec4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1a0158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0778 | PC: 0x0aedb8 | FDE: 0x1a0198 | Size: 256 bytes
// Khung tháo gỡ #0778 | Địa chỉ PC: 0x0aedb8 | Địa chỉ FDE: 0x1a0198 | Kích thước: 256 bytes
//   0x0aedb8: D10103FF  sub      sp, sp, #0x40
//   0x0aedbc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0aedc0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0aedc4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0778_0x0aedb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aedb8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1a0198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0779 | PC: 0x0af37c | FDE: 0x1a01e8 | Size: 144 bytes
// Khung tháo gỡ #0779 | Địa chỉ PC: 0x0af37c | Địa chỉ FDE: 0x1a01e8 | Kích thước: 144 bytes
//   0x0af37c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0af380: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0af384: 910043FD  add      x29, sp, #0x10
//   0x0af388: B00008A8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0779_0x0af37c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af37cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a01e8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0780 | PC: 0x0af40c | FDE: 0x1a0228 | Size: 256 bytes
// Khung tháo gỡ #0780 | Địa chỉ PC: 0x0af40c | Địa chỉ FDE: 0x1a0228 | Kích thước: 256 bytes
//   0x0af40c: D10203FF  sub      sp, sp, #0x80
//   0x0af410: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0af414: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0af418: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0780_0x0af40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af40cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1a0228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0781 | PC: 0x0af5f8 | FDE: 0x1a02e8 | Size: 256 bytes
// Khung tháo gỡ #0781 | Địa chỉ PC: 0x0af5f8 | Địa chỉ FDE: 0x1a02e8 | Kích thước: 256 bytes
//   0x0af5f8: D10183FF  sub      sp, sp, #0x60
//   0x0af5fc: F9001BF5  str      x21, [sp, #0x30]
//   0x0af600: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0af604: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0781_0x0af5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af5f8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1a02e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0782 | PC: 0x0af804 | FDE: 0x1a0328 | Size: 224 bytes
// Khung tháo gỡ #0782 | Địa chỉ PC: 0x0af804 | Địa chỉ FDE: 0x1a0328 | Kích thước: 224 bytes
//   0x0af804: D10103FF  sub      sp, sp, #0x40
//   0x0af808: F90013F3  str      x19, [sp, #0x20]
//   0x0af80c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0af810: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0782_0x0af804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af804ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1a0328ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0783 | PC: 0x0af8e4 | FDE: 0x1a0368 | Size: 256 bytes
// Khung tháo gỡ #0783 | Địa chỉ PC: 0x0af8e4 | Địa chỉ FDE: 0x1a0368 | Kích thước: 256 bytes
//   0x0af8e4: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x0af8e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0af8ec: 910043FD  add      x29, sp, #0x10
//   0x0af8f0: D12A83FF  sub      sp, sp, #0xaa0
static inline uint64_t fde_func_0783_0x0af8e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af8e4ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x0af9f4 | FDE: 0x1a03a8 | Size: 240 bytes
// Khung tháo gỡ #0784 | Địa chỉ PC: 0x0af9f4 | Địa chỉ FDE: 0x1a03a8 | Kích thước: 240 bytes
//   0x0af9f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0af9f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0af9fc: 910043FD  add      x29, sp, #0x10
//   0x0afa00: B00008A8  adrp     x8, #0x1c4000
static inline uint64_t fde_func_0784_0x0af9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af9f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a03a8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0785 | PC: 0x0afae4 | FDE: 0x1a03e8 | Size: 256 bytes
// Khung tháo gỡ #0785 | Địa chỉ PC: 0x0afae4 | Địa chỉ FDE: 0x1a03e8 | Kích thước: 256 bytes
//   0x0afae4: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x0afae8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0afaec: 910043FD  add      x29, sp, #0x10
//   0x0afaf0: D11843FF  sub      sp, sp, #0x610
static inline uint64_t fde_func_0785_0x0afae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afae4ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a03e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0786 | PC: 0x0afd8c | FDE: 0x1a0428 | Size: 76 bytes
// Khung tháo gỡ #0786 | Địa chỉ PC: 0x0afd8c | Địa chỉ FDE: 0x1a0428 | Kích thước: 76 bytes
//   0x0afd8c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0afd90: 910003FD  mov      x29, sp
//   0x0afd94: 97FDF8BF  bl       #0x2e090
//   0x0afd98: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0786_0x0afd8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afd8cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a0428ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0787 | PC: 0x0afdd8 | FDE: 0x1a0468 | Size: 28 bytes
// Khung tháo gỡ #0787 | Địa chỉ PC: 0x0afdd8 | Địa chỉ FDE: 0x1a0468 | Kích thước: 28 bytes
//   0x0afdd8: B00008A8  adrp     x8, #0x1c4000
//   0x0afddc: 91368108  add      x8, x8, #0xda0
//   0x0afde0: F9000028  str      x8, [x1]
//   0x0afde4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0787_0x0afdd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afdd8ULL ^ (static_cast<uint64_t>(0xb00008a8ULL) << 13);
    acc = (acc + a1 + 0x91368108ULL) ^ 0x1a0468ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0788 | PC: 0x0afdf4 | FDE: 0x1a0498 | Size: 48 bytes
// Khung tháo gỡ #0788 | Địa chỉ PC: 0x0afdf4 | Địa chỉ FDE: 0x1a0498 | Kích thước: 48 bytes
//   0x0afdf4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0afdf8: 910003FD  mov      x29, sp
//   0x0afdfc: 97FDF8A5  bl       #0x2e090
//   0x0afe00: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0788_0x0afdf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afdf4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a0498ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0789 | PC: 0x0afe24 | FDE: 0x1a04d8 | Size: 256 bytes
// Khung tháo gỡ #0789 | Địa chỉ PC: 0x0afe24 | Địa chỉ FDE: 0x1a04d8 | Kích thước: 256 bytes
//   0x0afe24: D10343FF  sub      sp, sp, #0xd0
//   0x0afe28: F90053F5  str      x21, [sp, #0xa0]
//   0x0afe2c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0afe30: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0789_0x0afe24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afe24ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90053f5ULL) ^ 0x1a04d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x0b004c | FDE: 0x1a0518 | Size: 80 bytes
// Khung tháo gỡ #0790 | Địa chỉ PC: 0x0b004c | Địa chỉ FDE: 0x1a0518 | Kích thước: 80 bytes
//   0x0b004c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b0050: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0054: 910043FD  add      x29, sp, #0x10
//   0x0b0058: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0790_0x0b004c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b004cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0518ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0791 | PC: 0x0b009c | FDE: 0x1a0550 | Size: 24 bytes
// Khung tháo gỡ #0791 | Địa chỉ PC: 0x0b009c | Địa chỉ FDE: 0x1a0550 | Kích thước: 24 bytes
//   0x0b009c: D65F03C0  ret      
//   0x0b00a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b00a4: 910003FD  mov      x29, sp
//   0x0b00a8: 97FDF7FA  bl       #0x2e090
static inline uint64_t fde_func_0791_0x0b009c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b009cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1a0550ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0792 | PC: 0x0b00b4 | FDE: 0x1a0588 | Size: 44 bytes
// Khung tháo gỡ #0792 | Địa chỉ PC: 0x0b00b4 | Địa chỉ FDE: 0x1a0588 | Kích thước: 44 bytes
//   0x0b00b4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b00b8: 910003FD  mov      x29, sp
//   0x0b00bc: F9400400  ldr      x0, [x0, #8]
//   0x0b00c0: 97FFFDEA  bl       #0xaf868
static inline uint64_t fde_func_0792_0x0b00b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b00b4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a0588ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0793 | PC: 0x0b00e0 | FDE: 0x1a05e0 | Size: 44 bytes
// Khung tháo gỡ #0793 | Địa chỉ PC: 0x0b00e0 | Địa chỉ FDE: 0x1a05e0 | Kích thước: 44 bytes
//   0x0b00e0: A9402002  ldp      x2, x8, [x0]
//   0x0b00e4: F9400801  ldr      x1, [x0, #0x10]
//   0x0b00e8: AA0803E0  mov      x0, x8
//   0x0b00ec: D61F0040  br       x2
static inline uint64_t fde_func_0793_0x0b00e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b00e0ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1a05e0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0794 | PC: 0x0b010c | FDE: 0x1a0610 | Size: 48 bytes
// Khung tháo gỡ #0794 | Địa chỉ PC: 0x0b010c | Địa chỉ FDE: 0x1a0610 | Kích thước: 48 bytes
//   0x0b010c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0110: AA0003F3  mov      x19, x0
//   0x0b0114: A9400008  ldp      x8, x0, [x0]
//   0x0b0118: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0794_0x0b010c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b010cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0610ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0795 | PC: 0x0b013c | FDE: 0x1a0640 | Size: 48 bytes
// Khung tháo gỡ #0795 | Địa chỉ PC: 0x0b013c | Địa chỉ FDE: 0x1a0640 | Kích thước: 48 bytes
//   0x0b013c: A9402002  ldp      x2, x8, [x0]
//   0x0b0140: F9400801  ldr      x1, [x0, #0x10]
//   0x0b0144: AA0803E0  mov      x0, x8
//   0x0b0148: D61F0040  br       x2
static inline uint64_t fde_func_0795_0x0b013c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b013cULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1a0640ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0796 | PC: 0x0b016c | FDE: 0x1a0670 | Size: 44 bytes
// Khung tháo gỡ #0796 | Địa chỉ PC: 0x0b016c | Địa chỉ FDE: 0x1a0670 | Kích thước: 44 bytes
//   0x0b016c: A9400001  ldp      x1, x0, [x0]
//   0x0b0170: D61F0020  br       x1
//   0x0b0174: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0178: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0796_0x0b016c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b016cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a0670ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0797 | PC: 0x0b0198 | FDE: 0x1a06a0 | Size: 60 bytes
// Khung tháo gỡ #0797 | Địa chỉ PC: 0x0b0198 | Địa chỉ FDE: 0x1a06a0 | Kích thước: 60 bytes
//   0x0b0198: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b019c: AA0003F3  mov      x19, x0
//   0x0b01a0: A9400008  ldp      x8, x0, [x0]
//   0x0b01a4: D63F0100  blr      x8
static inline uint64_t fde_func_0797_0x0b0198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0198ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a06a0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0798 | PC: 0x0b01d4 | FDE: 0x1a06d0 | Size: 36 bytes
// Khung tháo gỡ #0798 | Địa chỉ PC: 0x0b01d4 | Địa chỉ FDE: 0x1a06d0 | Kích thước: 36 bytes
//   0x0b01d4: A9400001  ldp      x1, x0, [x0]
//   0x0b01d8: D61F0020  br       x1
//   0x0b01dc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b01e0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0798_0x0b01d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b01d4ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a06d0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0799 | PC: 0x0b01f8 | FDE: 0x1a0700 | Size: 32 bytes
// Khung tháo gỡ #0799 | Địa chỉ PC: 0x0b01f8 | Địa chỉ FDE: 0x1a0700 | Kích thước: 32 bytes
//   0x0b01f8: A9402003  ldp      x3, x8, [x0]
//   0x0b01fc: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x0b0200: AA0803E0  mov      x0, x8
//   0x0b0204: D61F0060  br       x3
static inline uint64_t fde_func_0799_0x0b01f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b01f8ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x1a0700ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 400: return fde_func_0400_0x0727a4(a0, a1);
        case 401: return fde_func_0401_0x072be0(a0, a1);
        case 402: return fde_func_0402_0x072cbc(a0, a1);
        case 403: return fde_func_0403_0x072d34(a0, a1);
        case 404: return fde_func_0404_0x072d94(a0, a1);
        case 405: return fde_func_0405_0x0731fc(a0, a1);
        case 406: return fde_func_0406_0x07322c(a0, a1);
        case 407: return fde_func_0407_0x073a54(a0, a1);
        case 408: return fde_func_0408_0x074838(a0, a1);
        case 409: return fde_func_0409_0x0753a8(a0, a1);
        case 410: return fde_func_0410_0x075418(a0, a1);
        case 411: return fde_func_0411_0x075430(a0, a1);
        case 412: return fde_func_0412_0x075440(a0, a1);
        case 413: return fde_func_0413_0x07545c(a0, a1);
        case 414: return fde_func_0414_0x0754ac(a0, a1);
        case 415: return fde_func_0415_0x0754c4(a0, a1);
        case 416: return fde_func_0416_0x075584(a0, a1);
        case 417: return fde_func_0417_0x0755c4(a0, a1);
        case 418: return fde_func_0418_0x07560c(a0, a1);
        case 419: return fde_func_0419_0x07564c(a0, a1);
        case 420: return fde_func_0420_0x07568c(a0, a1);
        case 421: return fde_func_0421_0x07574c(a0, a1);
        case 422: return fde_func_0422_0x076b0c(a0, a1);
        case 423: return fde_func_0423_0x076ec4(a0, a1);
        case 424: return fde_func_0424_0x076f6c(a0, a1);
        case 425: return fde_func_0425_0x076fa0(a0, a1);
        case 426: return fde_func_0426_0x076fe8(a0, a1);
        case 427: return fde_func_0427_0x07721c(a0, a1);
        case 428: return fde_func_0428_0x077304(a0, a1);
        case 429: return fde_func_0429_0x07762c(a0, a1);
        case 430: return fde_func_0430_0x0779bc(a0, a1);
        case 431: return fde_func_0431_0x077c1c(a0, a1);
        case 432: return fde_func_0432_0x077d84(a0, a1);
        case 433: return fde_func_0433_0x078370(a0, a1);
        case 434: return fde_func_0434_0x078450(a0, a1);
        case 435: return fde_func_0435_0x07860c(a0, a1);
        case 436: return fde_func_0436_0x0787c8(a0, a1);
        case 437: return fde_func_0437_0x079160(a0, a1);
        case 438: return fde_func_0438_0x0796c8(a0, a1);
        case 439: return fde_func_0439_0x0797e4(a0, a1);
        case 440: return fde_func_0440_0x0798c8(a0, a1);
        case 441: return fde_func_0441_0x07a2c8(a0, a1);
        case 442: return fde_func_0442_0x07a56c(a0, a1);
        case 443: return fde_func_0443_0x07aad8(a0, a1);
        case 444: return fde_func_0444_0x07afb0(a0, a1);
        case 445: return fde_func_0445_0x07b1e4(a0, a1);
        case 446: return fde_func_0446_0x07b378(a0, a1);
        case 447: return fde_func_0447_0x07b394(a0, a1);
        case 448: return fde_func_0448_0x07b3e4(a0, a1);
        case 449: return fde_func_0449_0x07b3fc(a0, a1);
        case 450: return fde_func_0450_0x07b42c(a0, a1);
        case 451: return fde_func_0451_0x07b47c(a0, a1);
        case 452: return fde_func_0452_0x07b494(a0, a1);
        case 453: return fde_func_0453_0x07b4fc(a0, a1);
        case 454: return fde_func_0454_0x07b5d0(a0, a1);
        case 455: return fde_func_0455_0x07b618(a0, a1);
        case 456: return fde_func_0456_0x07b7c4(a0, a1);
        case 457: return fde_func_0457_0x07b864(a0, a1);
        case 458: return fde_func_0458_0x07b8f4(a0, a1);
        case 459: return fde_func_0459_0x07b9f8(a0, a1);
        case 460: return fde_func_0460_0x07bb04(a0, a1);
        case 461: return fde_func_0461_0x07bc20(a0, a1);
        case 462: return fde_func_0462_0x07bc6c(a0, a1);
        case 463: return fde_func_0463_0x07bca0(a0, a1);
        case 464: return fde_func_0464_0x07bcd0(a0, a1);
        case 465: return fde_func_0465_0x07bcfc(a0, a1);
        case 466: return fde_func_0466_0x07bd2c(a0, a1);
        case 467: return fde_func_0467_0x07bd5c(a0, a1);
        case 468: return fde_func_0468_0x07bd98(a0, a1);
        case 469: return fde_func_0469_0x07bda8(a0, a1);
        case 470: return fde_func_0470_0x07bde8(a0, a1);
        case 471: return fde_func_0471_0x07be30(a0, a1);
        case 472: return fde_func_0472_0x07be60(a0, a1);
        case 473: return fde_func_0473_0x07be88(a0, a1);
        case 474: return fde_func_0474_0x07beb4(a0, a1);
        case 475: return fde_func_0475_0x07bef0(a0, a1);
        case 476: return fde_func_0476_0x07bf34(a0, a1);
        case 477: return fde_func_0477_0x07bfd8(a0, a1);
        case 478: return fde_func_0478_0x07bff4(a0, a1);
        case 479: return fde_func_0479_0x07c028(a0, a1);
        case 480: return fde_func_0480_0x07c0bc(a0, a1);
        case 481: return fde_func_0481_0x07c218(a0, a1);
        case 482: return fde_func_0482_0x07c228(a0, a1);
        case 483: return fde_func_0483_0x07c23c(a0, a1);
        case 484: return fde_func_0484_0x07c2b4(a0, a1);
        case 485: return fde_func_0485_0x07c2cc(a0, a1);
        case 486: return fde_func_0486_0x07c2ec(a0, a1);
        case 487: return fde_func_0487_0x07c538(a0, a1);
        case 488: return fde_func_0488_0x07c668(a0, a1);
        case 489: return fde_func_0489_0x07c69c(a0, a1);
        case 490: return fde_func_0490_0x07c6cc(a0, a1);
        case 491: return fde_func_0491_0x07cbd8(a0, a1);
        case 492: return fde_func_0492_0x07d11c(a0, a1);
        case 493: return fde_func_0493_0x07d438(a0, a1);
        case 494: return fde_func_0494_0x07d644(a0, a1);
        case 495: return fde_func_0495_0x07d6cc(a0, a1);
        case 496: return fde_func_0496_0x07d754(a0, a1);
        case 497: return fde_func_0497_0x07d79c(a0, a1);
        case 498: return fde_func_0498_0x07d7bc(a0, a1);
        case 499: return fde_func_0499_0x07d9f8(a0, a1);
        case 500: return fde_func_0500_0x07db78(a0, a1);
        case 501: return fde_func_0501_0x07db94(a0, a1);
        case 502: return fde_func_0502_0x07dbb4(a0, a1);
        case 503: return fde_func_0503_0x07dbdc(a0, a1);
        case 504: return fde_func_0504_0x07dc0c(a0, a1);
        case 505: return fde_func_0505_0x07dc48(a0, a1);
        case 506: return fde_func_0506_0x07dc88(a0, a1);
        case 507: return fde_func_0507_0x07dcb4(a0, a1);
        case 508: return fde_func_0508_0x07dcf4(a0, a1);
        case 509: return fde_func_0509_0x07dd20(a0, a1);
        case 510: return fde_func_0510_0x07dd64(a0, a1);
        case 511: return fde_func_0511_0x07dd9c(a0, a1);
        case 512: return fde_func_0512_0x07ddd4(a0, a1);
        case 513: return fde_func_0513_0x07ddf8(a0, a1);
        case 514: return fde_func_0514_0x07de2c(a0, a1);
        case 515: return fde_func_0515_0x07de5c(a0, a1);
        case 516: return fde_func_0516_0x07de84(a0, a1);
        case 517: return fde_func_0517_0x07dea8(a0, a1);
        case 518: return fde_func_0518_0x07df7c(a0, a1);
        case 519: return fde_func_0519_0x07e1d8(a0, a1);
        case 520: return fde_func_0520_0x07e6fc(a0, a1);
        case 521: return fde_func_0521_0x07e880(a0, a1);
        case 522: return fde_func_0522_0x07ef60(a0, a1);
        case 523: return fde_func_0523_0x07f018(a0, a1);
        case 524: return fde_func_0524_0x07f100(a0, a1);
        case 525: return fde_func_0525_0x07f2d0(a0, a1);
        case 526: return fde_func_0526_0x07f3dc(a0, a1);
        case 527: return fde_func_0527_0x07f400(a0, a1);
        case 528: return fde_func_0528_0x07f410(a0, a1);
        case 529: return fde_func_0529_0x07f42c(a0, a1);
        case 530: return fde_func_0530_0x07f74c(a0, a1);
        case 531: return fde_func_0531_0x07f79c(a0, a1);
        case 532: return fde_func_0532_0x07f7b8(a0, a1);
        case 533: return fde_func_0533_0x07f870(a0, a1);
        case 534: return fde_func_0534_0x07f904(a0, a1);
        case 535: return fde_func_0535_0x07fb50(a0, a1);
        case 536: return fde_func_0536_0x07fcc4(a0, a1);
        case 537: return fde_func_0537_0x07fcf8(a0, a1);
        case 538: return fde_func_0538_0x0809f0(a0, a1);
        case 539: return fde_func_0539_0x080acc(a0, a1);
        case 540: return fde_func_0540_0x080e74(a0, a1);
        case 541: return fde_func_0541_0x081688(a0, a1);
        case 542: return fde_func_0542_0x081968(a0, a1);
        case 543: return fde_func_0543_0x0832ac(a0, a1);
        case 544: return fde_func_0544_0x087c4c(a0, a1);
        case 545: return fde_func_0545_0x087e60(a0, a1);
        case 546: return fde_func_0546_0x087f80(a0, a1);
        case 547: return fde_func_0547_0x088188(a0, a1);
        case 548: return fde_func_0548_0x088238(a0, a1);
        case 549: return fde_func_0549_0x08b070(a0, a1);
        case 550: return fde_func_0550_0x08b230(a0, a1);
        case 551: return fde_func_0551_0x08c518(a0, a1);
        case 552: return fde_func_0552_0x08c774(a0, a1);
        case 553: return fde_func_0553_0x08c7d0(a0, a1);
        case 554: return fde_func_0554_0x08c81c(a0, a1);
        case 555: return fde_func_0555_0x08c838(a0, a1);
        case 556: return fde_func_0556_0x08c868(a0, a1);
        case 557: return fde_func_0557_0x08c8b4(a0, a1);
        case 558: return fde_func_0558_0x08c8d0(a0, a1);
        case 559: return fde_func_0559_0x08c90c(a0, a1);
        case 560: return fde_func_0560_0x08c9bc(a0, a1);
        case 561: return fde_func_0561_0x08ca08(a0, a1);
        case 562: return fde_func_0562_0x08ca24(a0, a1);
        case 563: return fde_func_0563_0x08ca54(a0, a1);
        case 564: return fde_func_0564_0x08cb7c(a0, a1);
        case 565: return fde_func_0565_0x08d37c(a0, a1);
        case 566: return fde_func_0566_0x08d534(a0, a1);
        case 567: return fde_func_0567_0x08de74(a0, a1);
        case 568: return fde_func_0568_0x08eb8c(a0, a1);
        case 569: return fde_func_0569_0x08f340(a0, a1);
        case 570: return fde_func_0570_0x08fd98(a0, a1);
        case 571: return fde_func_0571_0x08fdd8(a0, a1);
        case 572: return fde_func_0572_0x08fec4(a0, a1);
        case 573: return fde_func_0573_0x08ff04(a0, a1);
        case 574: return fde_func_0574_0x08ffa0(a0, a1);
        case 575: return fde_func_0575_0x090018(a0, a1);
        case 576: return fde_func_0576_0x09002c(a0, a1);
        case 577: return fde_func_0577_0x0900b8(a0, a1);
        case 578: return fde_func_0578_0x0900d0(a0, a1);
        case 579: return fde_func_0579_0x0900e0(a0, a1);
        case 580: return fde_func_0580_0x0900f8(a0, a1);
        case 581: return fde_func_0581_0x090114(a0, a1);
        case 582: return fde_func_0582_0x090170(a0, a1);
        case 583: return fde_func_0583_0x090438(a0, a1);
        case 584: return fde_func_0584_0x0904fc(a0, a1);
        case 585: return fde_func_0585_0x0909d0(a0, a1);
        case 586: return fde_func_0586_0x093080(a0, a1);
        case 587: return fde_func_0587_0x0936ac(a0, a1);
        case 588: return fde_func_0588_0x0944d4(a0, a1);
        case 589: return fde_func_0589_0x0946a0(a0, a1);
        case 590: return fde_func_0590_0x0950e4(a0, a1);
        case 591: return fde_func_0591_0x095290(a0, a1);
        case 592: return fde_func_0592_0x095634(a0, a1);
        case 593: return fde_func_0593_0x0958e8(a0, a1);
        case 594: return fde_func_0594_0x096478(a0, a1);
        case 595: return fde_func_0595_0x096504(a0, a1);
        case 596: return fde_func_0596_0x096520(a0, a1);
        case 597: return fde_func_0597_0x096548(a0, a1);
        case 598: return fde_func_0598_0x096564(a0, a1);
        case 599: return fde_func_0599_0x0965a8(a0, a1);
        case 600: return fde_func_0600_0x0965e8(a0, a1);
        case 601: return fde_func_0601_0x096620(a0, a1);
        case 602: return fde_func_0602_0x096660(a0, a1);
        case 603: return fde_func_0603_0x096698(a0, a1);
        case 604: return fde_func_0604_0x0966bc(a0, a1);
        case 605: return fde_func_0605_0x0966fc(a0, a1);
        case 606: return fde_func_0606_0x096720(a0, a1);
        case 607: return fde_func_0607_0x096748(a0, a1);
        case 608: return fde_func_0608_0x096780(a0, a1);
        case 609: return fde_func_0609_0x0967ac(a0, a1);
        case 610: return fde_func_0610_0x0967d0(a0, a1);
        case 611: return fde_func_0611_0x09680c(a0, a1);
        case 612: return fde_func_0612_0x096848(a0, a1);
        case 613: return fde_func_0613_0x096880(a0, a1);
        case 614: return fde_func_0614_0x0968b8(a0, a1);
        case 615: return fde_func_0615_0x0968e8(a0, a1);
        case 616: return fde_func_0616_0x096930(a0, a1);
        case 617: return fde_func_0617_0x096970(a0, a1);
        case 618: return fde_func_0618_0x0969ac(a0, a1);
        case 619: return fde_func_0619_0x0969e0(a0, a1);
        case 620: return fde_func_0620_0x096a1c(a0, a1);
        case 621: return fde_func_0621_0x096a2c(a0, a1);
        case 622: return fde_func_0622_0x096a68(a0, a1);
        case 623: return fde_func_0623_0x096a80(a0, a1);
        case 624: return fde_func_0624_0x096ab8(a0, a1);
        case 625: return fde_func_0625_0x096afc(a0, a1);
        case 626: return fde_func_0626_0x096b2c(a0, a1);
        case 627: return fde_func_0627_0x096b6c(a0, a1);
        case 628: return fde_func_0628_0x096b98(a0, a1);
        case 629: return fde_func_0629_0x096bd0(a0, a1);
        case 630: return fde_func_0630_0x096c08(a0, a1);
        case 631: return fde_func_0631_0x096c40(a0, a1);
        case 632: return fde_func_0632_0x096c74(a0, a1);
        case 633: return fde_func_0633_0x096ca4(a0, a1);
        case 634: return fde_func_0634_0x096ce4(a0, a1);
        case 635: return fde_func_0635_0x096d10(a0, a1);
        case 636: return fde_func_0636_0x096d4c(a0, a1);
        case 637: return fde_func_0637_0x096d90(a0, a1);
        case 638: return fde_func_0638_0x096dbc(a0, a1);
        case 639: return fde_func_0639_0x096de8(a0, a1);
        case 640: return fde_func_0640_0x096e08(a0, a1);
        case 641: return fde_func_0641_0x096e38(a0, a1);
        case 642: return fde_func_0642_0x096e68(a0, a1);
        case 643: return fde_func_0643_0x096ea0(a0, a1);
        case 644: return fde_func_0644_0x096ee0(a0, a1);
        case 645: return fde_func_0645_0x096f0c(a0, a1);
        case 646: return fde_func_0646_0x096f24(a0, a1);
        case 647: return fde_func_0647_0x096f64(a0, a1);
        case 648: return fde_func_0648_0x096f98(a0, a1);
        case 649: return fde_func_0649_0x096fc4(a0, a1);
        case 650: return fde_func_0650_0x097004(a0, a1);
        case 651: return fde_func_0651_0x097030(a0, a1);
        case 652: return fde_func_0652_0x097068(a0, a1);
        case 653: return fde_func_0653_0x0970a0(a0, a1);
        case 654: return fde_func_0654_0x0970d8(a0, a1);
        case 655: return fde_func_0655_0x097108(a0, a1);
        case 656: return fde_func_0656_0x097488(a0, a1);
        case 657: return fde_func_0657_0x097934(a0, a1);
        case 658: return fde_func_0658_0x0994f4(a0, a1);
        case 659: return fde_func_0659_0x09a128(a0, a1);
        case 660: return fde_func_0660_0x09a58c(a0, a1);
        case 661: return fde_func_0661_0x09ad20(a0, a1);
        case 662: return fde_func_0662_0x09b114(a0, a1);
        case 663: return fde_func_0663_0x09b1dc(a0, a1);
        case 664: return fde_func_0664_0x09b2f8(a0, a1);
        case 665: return fde_func_0665_0x09b520(a0, a1);
        case 666: return fde_func_0666_0x09b5a8(a0, a1);
        case 667: return fde_func_0667_0x09bf78(a0, a1);
        case 668: return fde_func_0668_0x09bff8(a0, a1);
        case 669: return fde_func_0669_0x09c000(a0, a1);
        case 670: return fde_func_0670_0x09c128(a0, a1);
        case 671: return fde_func_0671_0x09c1b8(a0, a1);
        case 672: return fde_func_0672_0x09c324(a0, a1);
        case 673: return fde_func_0673_0x09c52c(a0, a1);
        case 674: return fde_func_0674_0x09cc40(a0, a1);
        case 675: return fde_func_0675_0x09d9b4(a0, a1);
        case 676: return fde_func_0676_0x09e238(a0, a1);
        case 677: return fde_func_0677_0x09e334(a0, a1);
        case 678: return fde_func_0678_0x09e554(a0, a1);
        case 679: return fde_func_0679_0x09e5a4(a0, a1);
        case 680: return fde_func_0680_0x09e5bc(a0, a1);
        case 681: return fde_func_0681_0x09e6a0(a0, a1);
        case 682: return fde_func_0682_0x09e6dc(a0, a1);
        case 683: return fde_func_0683_0x09eb60(a0, a1);
        case 684: return fde_func_0684_0x09f39c(a0, a1);
        case 685: return fde_func_0685_0x09fde8(a0, a1);
        case 686: return fde_func_0686_0x0a03b0(a0, a1);
        case 687: return fde_func_0687_0x0a09a4(a0, a1);
        case 688: return fde_func_0688_0x0a0a04(a0, a1);
        case 689: return fde_func_0689_0x0a0a1c(a0, a1);
        case 690: return fde_func_0690_0x0a11f8(a0, a1);
        case 691: return fde_func_0691_0x0a1234(a0, a1);
        case 692: return fde_func_0692_0x0a123c(a0, a1);
        case 693: return fde_func_0693_0x0a13b8(a0, a1);
        case 694: return fde_func_0694_0x0a14dc(a0, a1);
        case 695: return fde_func_0695_0x0a1514(a0, a1);
        case 696: return fde_func_0696_0x0a16e4(a0, a1);
        case 697: return fde_func_0697_0x0a16f0(a0, a1);
        case 698: return fde_func_0698_0x0a16f8(a0, a1);
        case 699: return fde_func_0699_0x0a2324(a0, a1);
        case 700: return fde_func_0700_0x0a2478(a0, a1);
        case 701: return fde_func_0701_0x0a2494(a0, a1);
        case 702: return fde_func_0702_0x0a24a4(a0, a1);
        case 703: return fde_func_0703_0x0a2740(a0, a1);
        case 704: return fde_func_0704_0x0a2844(a0, a1);
        case 705: return fde_func_0705_0x0a29dc(a0, a1);
        case 706: return fde_func_0706_0x0a2afc(a0, a1);
        case 707: return fde_func_0707_0x0a2d40(a0, a1);
        case 708: return fde_func_0708_0x0a2d8c(a0, a1);
        case 709: return fde_func_0709_0x0a2da8(a0, a1);
        case 710: return fde_func_0710_0x0a2e9c(a0, a1);
        case 711: return fde_func_0711_0x0a2ec8(a0, a1);
        case 712: return fde_func_0712_0x0a2ed0(a0, a1);
        case 713: return fde_func_0713_0x0a2ed8(a0, a1);
        case 714: return fde_func_0714_0x0a3038(a0, a1);
        case 715: return fde_func_0715_0x0a3130(a0, a1);
        case 716: return fde_func_0716_0x0a3404(a0, a1);
        case 717: return fde_func_0717_0x0a34b8(a0, a1);
        case 718: return fde_func_0718_0x0a3634(a0, a1);
        case 719: return fde_func_0719_0x0a3754(a0, a1);
        case 720: return fde_func_0720_0x0a399c(a0, a1);
        case 721: return fde_func_0721_0x0a39e8(a0, a1);
        case 722: return fde_func_0722_0x0a3a04(a0, a1);
        case 723: return fde_func_0723_0x0a3ac0(a0, a1);
        case 724: return fde_func_0724_0x0a3f68(a0, a1);
        case 725: return fde_func_0725_0x0a3fa0(a0, a1);
        case 726: return fde_func_0726_0x0a40a4(a0, a1);
        case 727: return fde_func_0727_0x0a473c(a0, a1);
        case 728: return fde_func_0728_0x0a4c58(a0, a1);
        case 729: return fde_func_0729_0x0a4ca4(a0, a1);
        case 730: return fde_func_0730_0x0a4dc8(a0, a1);
        case 731: return fde_func_0731_0x0a520c(a0, a1);
        case 732: return fde_func_0732_0x0a54c8(a0, a1);
        case 733: return fde_func_0733_0x0a54e4(a0, a1);
        case 734: return fde_func_0734_0x0a55d8(a0, a1);
        case 735: return fde_func_0735_0x0a5694(a0, a1);
        case 736: return fde_func_0736_0x0a56dc(a0, a1);
        case 737: return fde_func_0737_0x0a5704(a0, a1);
        case 738: return fde_func_0738_0x0a5800(a0, a1);
        case 739: return fde_func_0739_0x0a58b8(a0, a1);
        case 740: return fde_func_0740_0x0a5a0c(a0, a1);
        case 741: return fde_func_0741_0x0a784c(a0, a1);
        case 742: return fde_func_0742_0x0a7b24(a0, a1);
        case 743: return fde_func_0743_0x0a7d34(a0, a1);
        case 744: return fde_func_0744_0x0a7f7c(a0, a1);
        case 745: return fde_func_0745_0x0a81c4(a0, a1);
        case 746: return fde_func_0746_0x0a83a8(a0, a1);
        case 747: return fde_func_0747_0x0a8594(a0, a1);
        case 748: return fde_func_0748_0x0a8768(a0, a1);
        case 749: return fde_func_0749_0x0a8988(a0, a1);
        case 750: return fde_func_0750_0x0a9650(a0, a1);
        case 751: return fde_func_0751_0x0a96c0(a0, a1);
        case 752: return fde_func_0752_0x0a975c(a0, a1);
        case 753: return fde_func_0753_0x0a9c9c(a0, a1);
        case 754: return fde_func_0754_0x0a9cfc(a0, a1);
        case 755: return fde_func_0755_0x0aa2a4(a0, a1);
        case 756: return fde_func_0756_0x0aa6fc(a0, a1);
        case 757: return fde_func_0757_0x0aa9b4(a0, a1);
        case 758: return fde_func_0758_0x0ab2ec(a0, a1);
        case 759: return fde_func_0759_0x0ab328(a0, a1);
        case 760: return fde_func_0760_0x0ab398(a0, a1);
        case 761: return fde_func_0761_0x0ab3b0(a0, a1);
        case 762: return fde_func_0762_0x0abdc0(a0, a1);
        case 763: return fde_func_0763_0x0ac530(a0, a1);
        case 764: return fde_func_0764_0x0ac944(a0, a1);
        case 765: return fde_func_0765_0x0aca80(a0, a1);
        case 766: return fde_func_0766_0x0acc40(a0, a1);
        case 767: return fde_func_0767_0x0accd0(a0, a1);
        case 768: return fde_func_0768_0x0ad034(a0, a1);
        case 769: return fde_func_0769_0x0adabc(a0, a1);
        case 770: return fde_func_0770_0x0adb04(a0, a1);
        case 771: return fde_func_0771_0x0adb40(a0, a1);
        case 772: return fde_func_0772_0x0adb90(a0, a1);
        case 773: return fde_func_0773_0x0adba8(a0, a1);
        case 774: return fde_func_0774_0x0adbec(a0, a1);
        case 775: return fde_func_0775_0x0ae7ac(a0, a1);
        case 776: return fde_func_0776_0x0ae7f8(a0, a1);
        case 777: return fde_func_0777_0x0aec4c(a0, a1);
        case 778: return fde_func_0778_0x0aedb8(a0, a1);
        case 779: return fde_func_0779_0x0af37c(a0, a1);
        case 780: return fde_func_0780_0x0af40c(a0, a1);
        case 781: return fde_func_0781_0x0af5f8(a0, a1);
        case 782: return fde_func_0782_0x0af804(a0, a1);
        case 783: return fde_func_0783_0x0af8e4(a0, a1);
        case 784: return fde_func_0784_0x0af9f4(a0, a1);
        case 785: return fde_func_0785_0x0afae4(a0, a1);
        case 786: return fde_func_0786_0x0afd8c(a0, a1);
        case 787: return fde_func_0787_0x0afdd8(a0, a1);
        case 788: return fde_func_0788_0x0afdf4(a0, a1);
        case 789: return fde_func_0789_0x0afe24(a0, a1);
        case 790: return fde_func_0790_0x0b004c(a0, a1);
        case 791: return fde_func_0791_0x0b009c(a0, a1);
        case 792: return fde_func_0792_0x0b00b4(a0, a1);
        case 793: return fde_func_0793_0x0b00e0(a0, a1);
        case 794: return fde_func_0794_0x0b010c(a0, a1);
        case 795: return fde_func_0795_0x0b013c(a0, a1);
        case 796: return fde_func_0796_0x0b016c(a0, a1);
        case 797: return fde_func_0797_0x0b0198(a0, a1);
        case 798: return fde_func_0798_0x0b01d4(a0, a1);
        case 799: return fde_func_0799_0x0b01f8(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ov
} // namespace metasec