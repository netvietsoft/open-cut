// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 5/5 for libkrypton.so
// Phân mảnh Hàm AArch64 C++17 sạch 5/5 cho libkrypton.so
// Covers representative FDE indices [1600 .. 1999] out of 9,255 total FDEs
// Bao phủ chỉ số FDE đại diện [1600 .. 1999] trên tổng số 9.255 FDE
// ============================================================================
#include "krypton_core.h"

namespace lynx {
namespace canvas {

// FDE #1600 | PC: 0x178a9c | FDE: 0x0926b0 | Size: 44 bytes
// Khung tháo gỡ #1600 | Địa chỉ PC: 0x178a9c | Địa chỉ FDE: 0x0926b0 | Kích thước: 44 bytes
//   0x178a9c: AA0003F3  mov      x19, x0
//   0x178aa0: 14003ABC  b        #0x187590
//   0x178aa4: D53BD058  mrs      x24, tpidr_el0
//   0x178aa8: F9401708  ldr      x8, [x24, #0x28]
static inline uint64_t fde_func_1600_0x178a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178a9cULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x14003abcULL) ^ 0x0926b0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1601 | PC: 0x178ac8 | FDE: 0x092710 | Size: 72 bytes
// Khung tháo gỡ #1601 | Địa chỉ PC: 0x178ac8 | Địa chỉ FDE: 0x092710 | Kích thước: 72 bytes
//   0x178ac8: B94002E0  ldr      w0, [x23]
//   0x178acc: 11001E78  add      w24, w19, #7
//   0x178ad0: 17FED173  b        #0x12d09c
//   0x178ad4: F9402294  ldr      x20, [x20, #0x40]
static inline uint64_t fde_func_1601_0x178ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178ac8ULL ^ (static_cast<uint64_t>(0xb94002e0ULL) << 13);
    acc = (acc + a1 + 0x11001e78ULL) ^ 0x092710ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1602 | PC: 0x178b10 | FDE: 0x092770 | Size: 176 bytes
// Khung tháo gỡ #1602 | Địa chỉ PC: 0x178b10 | Địa chỉ FDE: 0x092770 | Kích thước: 176 bytes
//   0x178b10: B9400268  ldr      w8, [x19]
//   0x178b14: AA0003F7  mov      x23, x0
//   0x178b18: 52817922  mov      w2, #0xbc9
//   0x178b1c: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1602_0x178b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178b10ULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0xaa0003f7ULL) ^ 0x092770ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1603 | PC: 0x178bc0 | FDE: 0x0927d0 | Size: 172 bytes
// Khung tháo gỡ #1603 | Địa chỉ PC: 0x178bc0 | Địa chỉ FDE: 0x0927d0 | Kích thước: 172 bytes
//   0x178bc0: F9001BE0  str      x0, [sp, #0x30]
//   0x178bc4: 9100C3E0  add      x0, sp, #0x30
//   0x178bc8: 140042E2  b        #0x189750
//   0x178bcc: F9409BE8  ldr      x8, [sp, #0x130]
static inline uint64_t fde_func_1603_0x178bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178bc0ULL ^ (static_cast<uint64_t>(0xf9001be0ULL) << 13);
    acc = (acc + a1 + 0x9100c3e0ULL) ^ 0x0927d0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1604 | PC: 0x178c6c | FDE: 0x092830 | Size: 40 bytes
// Khung tháo gỡ #1604 | Địa chỉ PC: 0x178c6c | Địa chỉ FDE: 0x092830 | Kích thước: 40 bytes
//   0x178c6c: 9100E3E0  add      x0, sp, #0x38
//   0x178c70: AA1603E1  mov      x1, x22
//   0x178c74: 17FDB1DE  b        #0xe53ec
//   0x178c78: 9100E3E0  add      x0, sp, #0x38
static inline uint64_t fde_func_1604_0x178c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178c6cULL ^ (static_cast<uint64_t>(0x9100e3e0ULL) << 13);
    acc = (acc + a1 + 0xaa1603e1ULL) ^ 0x092830ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1605 | PC: 0x178c94 | FDE: 0x092890 | Size: 68 bytes
// Khung tháo gỡ #1605 | Địa chỉ PC: 0x178c94 | Địa chỉ FDE: 0x092890 | Kích thước: 68 bytes
//   0x178c94: 52800022  mov      w2, #1
//   0x178c98: AA1303E1  mov      x1, x19
//   0x178c9c: 17FF5DE5  b        #0x150430
//   0x178ca0: 9100A3E0  add      x0, sp, #0x28
static inline uint64_t fde_func_1605_0x178c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178c94ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0xaa1303e1ULL) ^ 0x092890ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1606 | PC: 0x178cd8 | FDE: 0x0928f0 | Size: 48 bytes
// Khung tháo gỡ #1606 | Địa chỉ PC: 0x178cd8 | Địa chỉ FDE: 0x0928f0 | Kích thước: 48 bytes
//   0x178cd8: 910203E0  add      x0, sp, #0x80
//   0x178cdc: 14003A39  b        #0x1875c0
//   0x178ce0: 2A0803E0  mov      w0, w8
//   0x178ce4: D65F03C0  ret      
static inline uint64_t fde_func_1606_0x178cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178cd8ULL ^ (static_cast<uint64_t>(0x910203e0ULL) << 13);
    acc = (acc + a1 + 0x14003a39ULL) ^ 0x0928f0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1607 | PC: 0x178d08 | FDE: 0x092950 | Size: 32 bytes
// Khung tháo gỡ #1607 | Địa chỉ PC: 0x178d08 | Địa chỉ FDE: 0x092950 | Kích thước: 32 bytes
//   0x178d08: AA1303E0  mov      x0, x19
//   0x178d0c: 17FF11D0  b        #0x13d44c
//   0x178d10: AA1303E0  mov      x0, x19
//   0x178d14: 14003B5B  b        #0x187a80
static inline uint64_t fde_func_1607_0x178d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178d08ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17ff11d0ULL) ^ 0x092950ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1608 | PC: 0x178d28 | FDE: 0x0929b0 | Size: 72 bytes
// Khung tháo gỡ #1608 | Địa chỉ PC: 0x178d28 | Địa chỉ FDE: 0x0929b0 | Kích thước: 72 bytes
//   0x178d28: AA1603E0  mov      x0, x22
//   0x178d2c: 2A1703E1  mov      w1, w23
//   0x178d30: 17FF5289  b        #0x14d754
//   0x178d34: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1608_0x178d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178d28ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x0929b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1609 | PC: 0x178d70 | FDE: 0x092a10 | Size: 48 bytes
// Khung tháo gỡ #1609 | Địa chỉ PC: 0x178d70 | Địa chỉ FDE: 0x092a10 | Kích thước: 48 bytes
//   0x178d70: AA1403E1  mov      x1, x20
//   0x178d74: 17FCBEE0  b        #0xa88f4
//   0x178d78: AA1503E1  mov      x1, x21
//   0x178d7c: 17FCBEE4  b        #0xa890c
static inline uint64_t fde_func_1609_0x178d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178d70ULL ^ (static_cast<uint64_t>(0xaa1403e1ULL) << 13);
    acc = (acc + a1 + 0x17fcbee0ULL) ^ 0x092a10ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1610 | PC: 0x178da0 | FDE: 0x092a70 | Size: 68 bytes
// Khung tháo gỡ #1610 | Địa chỉ PC: 0x178da0 | Địa chỉ FDE: 0x092a70 | Kích thước: 68 bytes
//   0x178da0: B94006E1  ldr      w1, [x23, #4]
//   0x178da4: F9403FE0  ldr      x0, [sp, #0x78]
//   0x178da8: 11001273  add      w19, w19, #4
//   0x178dac: 17FEC405  b        #0x129dc0
static inline uint64_t fde_func_1610_0x178da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178da0ULL ^ (static_cast<uint64_t>(0xb94006e1ULL) << 13);
    acc = (acc + a1 + 0xf9403fe0ULL) ^ 0x092a70ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1611 | PC: 0x178de4 | FDE: 0x092ad0 | Size: 132 bytes
// Khung tháo gỡ #1611 | Địa chỉ PC: 0x178de4 | Địa chỉ FDE: 0x092ad0 | Kích thước: 132 bytes
//   0x178de4: AA0003FB  mov      x27, x0
//   0x178de8: 52800103  mov      w3, #8
//   0x178dec: AA1A03E0  mov      x0, x26
//   0x178df0: AA1C03E1  mov      x1, x28
static inline uint64_t fde_func_1611_0x178de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178de4ULL ^ (static_cast<uint64_t>(0xaa0003fbULL) << 13);
    acc = (acc + a1 + 0x52800103ULL) ^ 0x092ad0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1612 | PC: 0x178e68 | FDE: 0x092b30 | Size: 72 bytes
// Khung tháo gỡ #1612 | Địa chỉ PC: 0x178e68 | Địa chỉ FDE: 0x092b30 | Kích thước: 72 bytes
//   0x178e68: 910723E0  add      x0, sp, #0x1c8
//   0x178e6c: 7100011F  cmp      w8, #0
//   0x178e70: D0FFF5C8  adrp     x8, #0x32000
//   0x178e74: 9132A508  add      x8, x8, #0xca9
static inline uint64_t fde_func_1612_0x178e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178e68ULL ^ (static_cast<uint64_t>(0x910723e0ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x092b30ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1613 | PC: 0x178eb0 | FDE: 0x092b90 | Size: 56 bytes
// Khung tháo gỡ #1613 | Địa chỉ PC: 0x178eb0 | Địa chỉ FDE: 0x092b90 | Kích thước: 56 bytes
//   0x178eb0: 5281BC20  mov      w0, #0xde1
//   0x178eb4: 14003EB3  b        #0x188980
//   0x178eb8: 5281BC20  mov      w0, #0xde1
//   0x178ebc: 52850021  mov      w1, #0x2801
static inline uint64_t fde_func_1613_0x178eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178eb0ULL ^ (static_cast<uint64_t>(0x5281bc20ULL) << 13);
    acc = (acc + a1 + 0x14003eb3ULL) ^ 0x092b90ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1614 | PC: 0x178ee8 | FDE: 0x092bf0 | Size: 96 bytes
// Khung tháo gỡ #1614 | Địa chỉ PC: 0x178ee8 | Địa chỉ FDE: 0x092bf0 | Kích thước: 96 bytes
//   0x178ee8: 8B284AA0  add      x0, x21, w8, uxtw #2
//   0x178eec: 8B294AA1  add      x1, x21, w9, uxtw #2
//   0x178ef0: BD400000  ldr      s0, [x0]
//   0x178ef4: BD400021  ldr      s1, [x1]
static inline uint64_t fde_func_1614_0x178ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178ee8ULL ^ (static_cast<uint64_t>(0x8b284aa0ULL) << 13);
    acc = (acc + a1 + 0x8b294aa1ULL) ^ 0x092bf0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1615 | PC: 0x178f48 | FDE: 0x092c50 | Size: 120 bytes
// Khung tháo gỡ #1615 | Địa chỉ PC: 0x178f48 | Địa chỉ FDE: 0x092c50 | Kích thước: 120 bytes
//   0x178f48: F9400100  ldr      x0, [x8]
//   0x178f4c: 17FDAC1C  b        #0xe3fbc
//   0x178f50: F9401BE8  ldr      x8, [sp, #0x30]
//   0x178f54: AA1A03E0  mov      x0, x26
static inline uint64_t fde_func_1615_0x178f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178f48ULL ^ (static_cast<uint64_t>(0xf9400100ULL) << 13);
    acc = (acc + a1 + 0x17fdac1cULL) ^ 0x092c50ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1616 | PC: 0x178fc0 | FDE: 0x092cb0 | Size: 64 bytes
// Khung tháo gỡ #1616 | Địa chỉ PC: 0x178fc0 | Địa chỉ FDE: 0x092cb0 | Kích thước: 64 bytes
//   0x178fc0: A94B53F5  ldp      x21, x20, [sp, #0xb0]
//   0x178fc4: A94A5BF7  ldp      x23, x22, [sp, #0xa0]
//   0x178fc8: A94963F9  ldp      x25, x24, [sp, #0x90]
//   0x178fcc: A9486BFB  ldp      x27, x26, [sp, #0x80]
static inline uint64_t fde_func_1616_0x178fc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178fc0ULL ^ (static_cast<uint64_t>(0xa94b53f5ULL) << 13);
    acc = (acc + a1 + 0xa94a5bf7ULL) ^ 0x092cb0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1617 | PC: 0x179000 | FDE: 0x092d10 | Size: 72 bytes
// Khung tháo gỡ #1617 | Địa chỉ PC: 0x179000 | Địa chỉ FDE: 0x092d10 | Kích thước: 72 bytes
//   0x179000: 910283E0  add      x0, sp, #0xa0
//   0x179004: 14003937  b        #0x1874e0
//   0x179008: B9000268  str      w8, [x19]
//   0x17900c: B94002F5  ldr      w21, [x23]
static inline uint64_t fde_func_1617_0x179000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179000ULL ^ (static_cast<uint64_t>(0x910283e0ULL) << 13);
    acc = (acc + a1 + 0x14003937ULL) ^ 0x092d10ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1618 | PC: 0x179048 | FDE: 0x092d70 | Size: 60 bytes
// Khung tháo gỡ #1618 | Địa chỉ PC: 0x179048 | Địa chỉ FDE: 0x092d70 | Kích thước: 60 bytes
//   0x179048: F0FFF5A1  adrp     x1, #0x30000
//   0x17904c: 910F6C21  add      x1, x1, #0x3db
//   0x179050: 9100C3E0  add      x0, sp, #0x30
//   0x179054: 17FCC7DE  b        #0xaafcc
static inline uint64_t fde_func_1618_0x179048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179048ULL ^ (static_cast<uint64_t>(0xf0fff5a1ULL) << 13);
    acc = (acc + a1 + 0x910f6c21ULL) ^ 0x092d70ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1619 | PC: 0x179084 | FDE: 0x092dd0 | Size: 68 bytes
// Khung tháo gỡ #1619 | Địa chỉ PC: 0x179084 | Địa chỉ FDE: 0x092dd0 | Kích thước: 68 bytes
//   0x179084: A94553F5  ldp      x21, x20, [sp, #0x50]
//   0x179088: A9445BF7  ldp      x23, x22, [sp, #0x40]
//   0x17908c: A94363F9  ldp      x25, x24, [sp, #0x30]
//   0x179090: F94013FA  ldr      x26, [sp, #0x20]
static inline uint64_t fde_func_1619_0x179084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179084ULL ^ (static_cast<uint64_t>(0xa94553f5ULL) << 13);
    acc = (acc + a1 + 0xa9445bf7ULL) ^ 0x092dd0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1620 | PC: 0x1790c8 | FDE: 0x092e30 | Size: 72 bytes
// Khung tháo gỡ #1620 | Địa chỉ PC: 0x1790c8 | Địa chỉ FDE: 0x092e30 | Kích thước: 72 bytes
//   0x1790c8: 8B170294  add      x20, x20, x23
//   0x1790cc: 8B16039C  add      x28, x28, x22
//   0x1790d0: D1000739  sub      x25, x25, #1
//   0x1790d4: D65F03C0  ret      
static inline uint64_t fde_func_1620_0x1790c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1790c8ULL ^ (static_cast<uint64_t>(0x8b170294ULL) << 13);
    acc = (acc + a1 + 0x8b16039cULL) ^ 0x092e30ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1621 | PC: 0x179110 | FDE: 0x092e90 | Size: 120 bytes
// Khung tháo gỡ #1621 | Địa chỉ PC: 0x179110 | Địa chỉ FDE: 0x092e90 | Kích thước: 120 bytes
//   0x179110: F9400809  ldr      x9, [x0, #0x10]
//   0x179114: F940000A  ldr      x10, [x0]
//   0x179118: 5280030B  mov      w11, #0x18
//   0x17911c: CB0A0129  sub      x9, x9, x10
static inline uint64_t fde_func_1621_0x179110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179110ULL ^ (static_cast<uint64_t>(0xf9400809ULL) << 13);
    acc = (acc + a1 + 0xf940000aULL) ^ 0x092e90ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1622 | PC: 0x179188 | FDE: 0x092ef0 | Size: 80 bytes
// Khung tháo gỡ #1622 | Địa chỉ PC: 0x179188 | Địa chỉ FDE: 0x092ef0 | Kích thước: 80 bytes
//   0x179188: D53BD054  mrs      x20, tpidr_el0
//   0x17918c: F9401688  ldr      x8, [x20, #0x28]
//   0x179190: 528000A9  mov      w9, #5
//   0x179194: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1622_0x179188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179188ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x092ef0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1623 | PC: 0x1791d8 | FDE: 0x092f50 | Size: 72 bytes
// Khung tháo gỡ #1623 | Địa chỉ PC: 0x1791d8 | Địa chỉ FDE: 0x092f50 | Kích thước: 72 bytes
//   0x1791d8: A95953F5  ldp      x21, x20, [sp, #0x190]
//   0x1791dc: A9585BF7  ldp      x23, x22, [sp, #0x180]
//   0x1791e0: A95763F9  ldp      x25, x24, [sp, #0x170]
//   0x1791e4: A9566BFC  ldp      x28, x26, [sp, #0x160]
static inline uint64_t fde_func_1623_0x1791d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1791d8ULL ^ (static_cast<uint64_t>(0xa95953f5ULL) << 13);
    acc = (acc + a1 + 0xa9585bf7ULL) ^ 0x092f50ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1624 | PC: 0x179220 | FDE: 0x092fb0 | Size: 80 bytes
// Khung tháo gỡ #1624 | Địa chỉ PC: 0x179220 | Địa chỉ FDE: 0x092fb0 | Kích thước: 80 bytes
//   0x179220: D53BD058  mrs      x24, tpidr_el0
//   0x179224: F9401708  ldr      x8, [x24, #0x28]
//   0x179228: AA0103F3  mov      x19, x1
//   0x17922c: D65F03C0  ret      
static inline uint64_t fde_func_1624_0x179220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179220ULL ^ (static_cast<uint64_t>(0xd53bd058ULL) << 13);
    acc = (acc + a1 + 0xf9401708ULL) ^ 0x092fb0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1625 | PC: 0x179270 | FDE: 0x093018 | Size: 92 bytes
// Khung tháo gỡ #1625 | Địa chỉ PC: 0x179270 | Địa chỉ FDE: 0x093018 | Kích thước: 92 bytes
//   0x179270: AA1303E1  mov      x1, x19
//   0x179274: 17FF5CFE  b        #0x15066c
//   0x179278: 910023E0  add      x0, sp, #8
//   0x17927c: 140041D5  b        #0x1899d0
static inline uint64_t fde_func_1625_0x179270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179270ULL ^ (static_cast<uint64_t>(0xaa1303e1ULL) << 13);
    acc = (acc + a1 + 0x17ff5cfeULL) ^ 0x093018ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1626 | PC: 0x1792cc | FDE: 0x093078 | Size: 120 bytes
// Khung tháo gỡ #1626 | Địa chỉ PC: 0x1792cc | Địa chỉ FDE: 0x093078 | Kích thước: 120 bytes
//   0x1792cc: B94002E0  ldr      w0, [x23]
//   0x1792d0: 11001278  add      w24, w19, #4
//   0x1792d4: 17FECF72  b        #0x12d09c
//   0x1792d8: 6B0C016E  subs     w14, w11, w12
static inline uint64_t fde_func_1626_0x1792cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1792ccULL ^ (static_cast<uint64_t>(0xb94002e0ULL) << 13);
    acc = (acc + a1 + 0x11001278ULL) ^ 0x093078ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1627 | PC: 0x179344 | FDE: 0x0930d8 | Size: 64 bytes
// Khung tháo gỡ #1627 | Địa chỉ PC: 0x179344 | Địa chỉ FDE: 0x0930d8 | Kích thước: 64 bytes
//   0x179344: 4EA81D00  mov      v0.16b, v8.16b
//   0x179348: 4EA91D21  mov      v1.16b, v9.16b
//   0x17934c: F9400008  ldr      x8, [x0]
//   0x179350: 4EAA1D42  mov      v2.16b, v10.16b
static inline uint64_t fde_func_1627_0x179344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179344ULL ^ (static_cast<uint64_t>(0x4ea81d00ULL) << 13);
    acc = (acc + a1 + 0x4ea91d21ULL) ^ 0x0930d8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1628 | PC: 0x179384 | FDE: 0x093138 | Size: 84 bytes
// Khung tháo gỡ #1628 | Địa chỉ PC: 0x179384 | Địa chỉ FDE: 0x093138 | Kích thước: 84 bytes
//   0x179384: 9119C063  add      x3, x3, #0x670
//   0x179388: 910063E0  add      x0, sp, #0x18
//   0x17938c: 17FF5761  b        #0x14f110
//   0x179390: B9400268  ldr      w8, [x19]
static inline uint64_t fde_func_1628_0x179384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179384ULL ^ (static_cast<uint64_t>(0x9119c063ULL) << 13);
    acc = (acc + a1 + 0x910063e0ULL) ^ 0x093138ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1629 | PC: 0x1793d8 | FDE: 0x093198 | Size: 64 bytes
// Khung tháo gỡ #1629 | Địa chỉ PC: 0x1793d8 | Địa chỉ FDE: 0x093198 | Kích thước: 64 bytes
//   0x1793d8: 2A0303E5  mov      w5, w3
//   0x1793dc: AA0203E3  mov      x3, x2
//   0x1793e0: F9000BE8  str      x8, [sp, #0x10]
//   0x1793e4: 93407C86  sxtw     x6, w4
static inline uint64_t fde_func_1629_0x1793d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1793d8ULL ^ (static_cast<uint64_t>(0x2a0303e5ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x093198ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1630 | PC: 0x179418 | FDE: 0x0931f8 | Size: 104 bytes
// Khung tháo gỡ #1630 | Địa chỉ PC: 0x179418 | Địa chỉ FDE: 0x0931f8 | Kích thước: 104 bytes
//   0x179418: 8B0A038C  add      x12, x28, x10
//   0x17941c: 8B090294  add      x20, x20, x9
//   0x179420: 910005AD  add      x13, x13, #1
//   0x179424: AA0C03FC  mov      x28, x12
static inline uint64_t fde_func_1630_0x179418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179418ULL ^ (static_cast<uint64_t>(0x8b0a038cULL) << 13);
    acc = (acc + a1 + 0x8b090294ULL) ^ 0x0931f8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1631 | PC: 0x179480 | FDE: 0x093258 | Size: 68 bytes
// Khung tháo gỡ #1631 | Địa chỉ PC: 0x179480 | Địa chỉ FDE: 0x093258 | Kích thước: 68 bytes
//   0x179480: 910123E0  add      x0, sp, #0x48
//   0x179484: 14003817  b        #0x1874e0
//   0x179488: 4EA31C68  mov      v8.16b, v3.16b
//   0x17948c: 4EA21C49  mov      v9.16b, v2.16b
static inline uint64_t fde_func_1631_0x179480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179480ULL ^ (static_cast<uint64_t>(0x910123e0ULL) << 13);
    acc = (acc + a1 + 0x14003817ULL) ^ 0x093258ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1632 | PC: 0x1794c4 | FDE: 0x0932b8 | Size: 116 bytes
// Khung tháo gỡ #1632 | Địa chỉ PC: 0x1794c4 | Địa chỉ FDE: 0x0932b8 | Kích thước: 116 bytes
//   0x1794c4: F9401268  ldr      x8, [x19, #0x20]
//   0x1794c8: F100211F  cmp      x8, #8
//   0x1794cc: D65F03C0  ret      
//   0x1794d0: B0FFF5E1  adrp     x1, #0x36000
static inline uint64_t fde_func_1632_0x1794c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1794c4ULL ^ (static_cast<uint64_t>(0xf9401268ULL) << 13);
    acc = (acc + a1 + 0xf100211fULL) ^ 0x0932b8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1633 | PC: 0x179538 | FDE: 0x093318 | Size: 132 bytes
// Khung tháo gỡ #1633 | Địa chỉ PC: 0x179538 | Địa chỉ FDE: 0x093318 | Kích thước: 132 bytes
//   0x179538: F94002E8  ldr      x8, [x23]
//   0x17953c: 914007E3  add      x3, sp, #1, lsl #12
//   0x179540: AA0003E2  mov      x2, x0
//   0x179544: 91020063  add      x3, x3, #0x80
static inline uint64_t fde_func_1633_0x179538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179538ULL ^ (static_cast<uint64_t>(0xf94002e8ULL) << 13);
    acc = (acc + a1 + 0x914007e3ULL) ^ 0x093318ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1634 | PC: 0x1795bc | FDE: 0x093378 | Size: 80 bytes
// Khung tháo gỡ #1634 | Địa chỉ PC: 0x1795bc | Địa chỉ FDE: 0x093378 | Kích thước: 80 bytes
//   0x1795bc: 910043A1  add      x1, x29, #0x10
//   0x1795c0: AA1503E0  mov      x0, x21
//   0x1795c4: 17FCC39E  b        #0xaa43c
//   0x1795c8: 2A0003E5  mov      w5, w0
static inline uint64_t fde_func_1634_0x1795bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1795bcULL ^ (static_cast<uint64_t>(0x910043a1ULL) << 13);
    acc = (acc + a1 + 0xaa1503e0ULL) ^ 0x093378ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1635 | PC: 0x17960c | FDE: 0x0933d8 | Size: 92 bytes
// Khung tháo gỡ #1635 | Địa chỉ PC: 0x17960c | Địa chỉ FDE: 0x0933d8 | Kích thước: 92 bytes
//   0x17960c: F9400660  ldr      x0, [x19, #8]
//   0x179610: F1001D1F  cmp      x8, #7
//   0x179614: D65F03C0  ret      
//   0x179618: 52800022  mov      w2, #1
static inline uint64_t fde_func_1635_0x17960c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17960cULL ^ (static_cast<uint64_t>(0xf9400660ULL) << 13);
    acc = (acc + a1 + 0xf1001d1fULL) ^ 0x0933d8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1636 | PC: 0x179668 | FDE: 0x093438 | Size: 112 bytes
// Khung tháo gỡ #1636 | Địa chỉ PC: 0x179668 | Địa chỉ FDE: 0x093438 | Kích thước: 112 bytes
//   0x179668: 3940100D  ldrb     w13, [x0, #4]
//   0x17966c: 3940140F  ldrb     w15, [x0, #5]
//   0x179670: 39401810  ldrb     w16, [x0, #6]
//   0x179674: 39401C11  ldrb     w17, [x0, #7]
static inline uint64_t fde_func_1636_0x179668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179668ULL ^ (static_cast<uint64_t>(0x3940100dULL) << 13);
    acc = (acc + a1 + 0x3940140fULL) ^ 0x093438ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1637 | PC: 0x1796d8 | FDE: 0x093498 | Size: 104 bytes
// Khung tháo gỡ #1637 | Địa chỉ PC: 0x1796d8 | Địa chỉ FDE: 0x093498 | Kích thước: 104 bytes
//   0x1796d8: 2A0503F5  mov      w21, w5
//   0x1796dc: 2A0103F9  mov      w25, w1
//   0x1796e0: B0FFF5E1  adrp     x1, #0x36000
//   0x1796e4: 2A0403F6  mov      w22, w4
static inline uint64_t fde_func_1637_0x1796d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1796d8ULL ^ (static_cast<uint64_t>(0x2a0503f5ULL) << 13);
    acc = (acc + a1 + 0x2a0103f9ULL) ^ 0x093498ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1638 | PC: 0x179740 | FDE: 0x0934f8 | Size: 44 bytes
// Khung tháo gỡ #1638 | Địa chỉ PC: 0x179740 | Địa chỉ FDE: 0x0934f8 | Kích thước: 44 bytes
//   0x179740: AA1803E2  mov      x2, x24
//   0x179744: AA1903E3  mov      x3, x25
//   0x179748: 17FF57A7  b        #0x14f5e4
//   0x17974c: 910453E1  add      x1, sp, #0x114
static inline uint64_t fde_func_1638_0x179740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179740ULL ^ (static_cast<uint64_t>(0xaa1803e2ULL) << 13);
    acc = (acc + a1 + 0xaa1903e3ULL) ^ 0x0934f8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1639 | PC: 0x17976c | FDE: 0x093558 | Size: 76 bytes
// Khung tháo gỡ #1639 | Địa chỉ PC: 0x17976c | Địa chỉ FDE: 0x093558 | Kích thước: 76 bytes
//   0x17976c: D53BD056  mrs      x22, tpidr_el0
//   0x179770: F94016C8  ldr      x8, [x22, #0x28]
//   0x179774: AA0103F3  mov      x19, x1
//   0x179778: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1639_0x17976c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17976cULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x093558ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1640 | PC: 0x1797b8 | FDE: 0x0935b8 | Size: 72 bytes
// Khung tháo gỡ #1640 | Địa chỉ PC: 0x1797b8 | Địa chỉ FDE: 0x0935b8 | Kích thước: 72 bytes
//   0x1797b8: F90007E8  str      x8, [sp, #8]
//   0x1797bc: A9007C08  stp      x8, xzr, [x0]
//   0x1797c0: F9402668  ldr      x8, [x19, #0x48]
//   0x1797c4: F9000408  str      x8, [x0, #8]
static inline uint64_t fde_func_1640_0x1797b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1797b8ULL ^ (static_cast<uint64_t>(0xf90007e8ULL) << 13);
    acc = (acc + a1 + 0xa9007c08ULL) ^ 0x0935b8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1641 | PC: 0x179800 | FDE: 0x093618 | Size: 64 bytes
// Khung tháo gỡ #1641 | Địa chỉ PC: 0x179800 | Địa chỉ FDE: 0x093618 | Kích thước: 64 bytes
//   0x179800: AA1603E0  mov      x0, x22
//   0x179804: 2A1703E1  mov      w1, w23
//   0x179808: 17FF50C3  b        #0x14db14
//   0x17980c: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1641_0x179800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179800ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x093618ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1642 | PC: 0x179840 | FDE: 0x093678 | Size: 80 bytes
// Khung tháo gỡ #1642 | Địa chỉ PC: 0x179840 | Địa chỉ FDE: 0x093678 | Kích thước: 80 bytes
//   0x179840: AA1403E0  mov      x0, x20
//   0x179844: F84207F4  ldr      x20, [sp], #0x20
//   0x179848: D61F0040  br       x2
//   0x17984c: AA0003E2  mov      x2, x0
static inline uint64_t fde_func_1642_0x179840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179840ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0xf84207f4ULL) ^ 0x093678ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1643 | PC: 0x179890 | FDE: 0x0936e0 | Size: 112 bytes
// Khung tháo gỡ #1643 | Địa chỉ PC: 0x179890 | Địa chỉ FDE: 0x0936e0 | Kích thước: 112 bytes
//   0x179890: AA1403E2  mov      x2, x20
//   0x179894: 2A1303E3  mov      w3, w19
//   0x179898: 2A1F03E7  mov      w7, wzr
//   0x17989c: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1643_0x179890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179890ULL ^ (static_cast<uint64_t>(0xaa1403e2ULL) << 13);
    acc = (acc + a1 + 0x2a1303e3ULL) ^ 0x0936e0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1644 | PC: 0x179900 | FDE: 0x093740 | Size: 64 bytes
// Khung tháo gỡ #1644 | Địa chỉ PC: 0x179900 | Địa chỉ FDE: 0x093740 | Kích thước: 64 bytes
//   0x179900: B9400EE4  ldr      w4, [x23, #0xc]
//   0x179904: 8B384AA2  add      x2, x21, w24, uxtw #2
//   0x179908: AA1403E0  mov      x0, x20
//   0x17990c: D65F03C0  ret      
static inline uint64_t fde_func_1644_0x179900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179900ULL ^ (static_cast<uint64_t>(0xb9400ee4ULL) << 13);
    acc = (acc + a1 + 0x8b384aa2ULL) ^ 0x093740ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1645 | PC: 0x179940 | FDE: 0x0937a0 | Size: 128 bytes
// Khung tháo gỡ #1645 | Địa chỉ PC: 0x179940 | Địa chỉ FDE: 0x0937a0 | Kích thước: 128 bytes
//   0x179940: B9400268  ldr      w8, [x19]
//   0x179944: 8B080AA9  add      x9, x21, x8, lsl #2
//   0x179948: 11003108  add      w8, w8, #0xc
//   0x17994c: B9000268  str      w8, [x19]
static inline uint64_t fde_func_1645_0x179940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179940ULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x8b080aa9ULL) ^ 0x0937a0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1646 | PC: 0x1799c0 | FDE: 0x093800 | Size: 88 bytes
// Khung tháo gỡ #1646 | Địa chỉ PC: 0x1799c0 | Địa chỉ FDE: 0x093800 | Kích thước: 88 bytes
//   0x1799c0: AA1903E1  mov      x1, x25
//   0x1799c4: 2A1803E2  mov      w2, w24
//   0x1799c8: 91019108  add      x8, x8, #0x64
//   0x1799cc: 88DFFD04  ldar     w4, [x8]
static inline uint64_t fde_func_1646_0x1799c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1799c0ULL ^ (static_cast<uint64_t>(0xaa1903e1ULL) << 13);
    acc = (acc + a1 + 0x2a1803e2ULL) ^ 0x093800ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1647 | PC: 0x179a18 | FDE: 0x093860 | Size: 84 bytes
// Khung tháo gỡ #1647 | Địa chỉ PC: 0x179a18 | Địa chỉ FDE: 0x093860 | Kích thước: 84 bytes
//   0x179a18: F941C408  ldr      x8, [x0, #0x388]
//   0x179a1c: 2A0403F4  mov      w20, w4
//   0x179a20: 2A0303F5  mov      w21, w3
//   0x179a24: 2A0203F6  mov      w22, w2
static inline uint64_t fde_func_1647_0x179a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179a18ULL ^ (static_cast<uint64_t>(0xf941c408ULL) << 13);
    acc = (acc + a1 + 0x2a0403f4ULL) ^ 0x093860ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1648 | PC: 0x179a6c | FDE: 0x0938c8 | Size: 60 bytes
// Khung tháo gỡ #1648 | Địa chỉ PC: 0x179a6c | Địa chỉ FDE: 0x0938c8 | Kích thước: 60 bytes
//   0x179a6c: D53BD056  mrs      x22, tpidr_el0
//   0x179a70: F94016C8  ldr      x8, [x22, #0x28]
//   0x179a74: AA0003F3  mov      x19, x0
//   0x179a78: D65F03C0  ret      
static inline uint64_t fde_func_1648_0x179a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179a6cULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x0938c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1649 | PC: 0x179aa8 | FDE: 0x093928 | Size: 40 bytes
// Khung tháo gỡ #1649 | Địa chỉ PC: 0x179aa8 | Địa chỉ FDE: 0x093928 | Kích thước: 40 bytes
//   0x179aa8: AA1303E0  mov      x0, x19
//   0x179aac: 17FCC69A  b        #0xab514
//   0x179ab0: AA1403E0  mov      x0, x20
//   0x179ab4: 14003FB7  b        #0x189990
static inline uint64_t fde_func_1649_0x179aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179aa8ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17fcc69aULL) ^ 0x093928ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1650 | PC: 0x179ad0 | FDE: 0x093988 | Size: 104 bytes
// Khung tháo gỡ #1650 | Địa chỉ PC: 0x179ad0 | Địa chỉ FDE: 0x093988 | Kích thước: 104 bytes
//   0x179ad0: F90097E8  str      x8, [sp, #0x128]
//   0x179ad4: 91002008  add      x8, x0, #8
//   0x179ad8: 08DFFD08  ldarb    w8, [x8]
//   0x179adc: D65F03C0  ret      
static inline uint64_t fde_func_1650_0x179ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179ad0ULL ^ (static_cast<uint64_t>(0xf90097e8ULL) << 13);
    acc = (acc + a1 + 0x91002008ULL) ^ 0x093988ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1651 | PC: 0x179b38 | FDE: 0x0939e8 | Size: 152 bytes
// Khung tháo gỡ #1651 | Địa chỉ PC: 0x179b38 | Địa chỉ FDE: 0x0939e8 | Kích thước: 152 bytes
//   0x179b38: F9402288  ldr      x8, [x20, #0x40]
//   0x179b3c: 910403E0  add      x0, sp, #0x100
//   0x179b40: 9100C3F4  add      x20, sp, #0x30
//   0x179b44: F90013E8  str      x8, [sp, #0x20]
static inline uint64_t fde_func_1651_0x179b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179b38ULL ^ (static_cast<uint64_t>(0xf9402288ULL) << 13);
    acc = (acc + a1 + 0x910403e0ULL) ^ 0x0939e8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1652 | PC: 0x179bd0 | FDE: 0x093a48 | Size: 60 bytes
// Khung tháo gỡ #1652 | Địa chỉ PC: 0x179bd0 | Địa chỉ FDE: 0x093a48 | Kích thước: 60 bytes
//   0x179bd0: 91030108  add      x8, x8, #0xc0
//   0x179bd4: 14004027  b        #0x189c70
//   0x179bd8: 29400408  ldp      w8, w1, [x0]
//   0x179bdc: B9400802  ldr      w2, [x0, #8]
static inline uint64_t fde_func_1652_0x179bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179bd0ULL ^ (static_cast<uint64_t>(0x91030108ULL) << 13);
    acc = (acc + a1 + 0x14004027ULL) ^ 0x093a48ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1653 | PC: 0x179c0c | FDE: 0x093ab0 | Size: 96 bytes
// Khung tháo gỡ #1653 | Địa chỉ PC: 0x179c0c | Địa chỉ FDE: 0x093ab0 | Kích thước: 96 bytes
//   0x179c0c: 910243E1  add      x1, sp, #0x90
//   0x179c10: AA1B03E0  mov      x0, x27
//   0x179c14: 17FF6CD8  b        #0x154f74
//   0x179c18: 914007E9  add      x9, sp, #1, lsl #12
static inline uint64_t fde_func_1653_0x179c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179c0cULL ^ (static_cast<uint64_t>(0x910243e1ULL) << 13);
    acc = (acc + a1 + 0xaa1b03e0ULL) ^ 0x093ab0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1654 | PC: 0x179c6c | FDE: 0x093b10 | Size: 84 bytes
// Khung tháo gỡ #1654 | Địa chỉ PC: 0x179c6c | Địa chỉ FDE: 0x093b10 | Kích thước: 84 bytes
//   0x179c6c: B9400268  ldr      w8, [x19]
//   0x179c70: 11000509  add      w9, w8, #1
//   0x179c74: B9000269  str      w9, [x19]
//   0x179c78: B8687AA1  ldr      w1, [x21, x8, lsl #2]
static inline uint64_t fde_func_1654_0x179c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179c6cULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x11000509ULL) ^ 0x093b10ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1655 | PC: 0x179cc0 | FDE: 0x093b70 | Size: 64 bytes
// Khung tháo gỡ #1655 | Địa chỉ PC: 0x179cc0 | Địa chỉ FDE: 0x093b70 | Kích thước: 64 bytes
//   0x179cc0: 914007E0  add      x0, sp, #1, lsl #12
//   0x179cc4: 91030000  add      x0, x0, #0xc0
//   0x179cc8: 17FF5BC4  b        #0x150bd8
//   0x179ccc: 12800001  mov      w1, #-1
static inline uint64_t fde_func_1655_0x179cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179cc0ULL ^ (static_cast<uint64_t>(0x914007e0ULL) << 13);
    acc = (acc + a1 + 0x91030000ULL) ^ 0x093b70ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1656 | PC: 0x179d00 | FDE: 0x093bd0 | Size: 112 bytes
// Khung tháo gỡ #1656 | Địa chỉ PC: 0x179d00 | Địa chỉ FDE: 0x093bd0 | Kích thước: 112 bytes
//   0x179d00: B9402FE2  ldr      w2, [sp, #0x2c]
//   0x179d04: F9401FE3  ldr      x3, [sp, #0x38]
//   0x179d08: F942EA80  ldr      x0, [x20, #0x5d0]
//   0x179d0c: AA1303E1  mov      x1, x19
static inline uint64_t fde_func_1656_0x179d00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179d00ULL ^ (static_cast<uint64_t>(0xb9402fe2ULL) << 13);
    acc = (acc + a1 + 0xf9401fe3ULL) ^ 0x093bd0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1657 | PC: 0x179d70 | FDE: 0x093c30 | Size: 84 bytes
// Khung tháo gỡ #1657 | Địa chỉ PC: 0x179d70 | Địa chỉ FDE: 0x093c30 | Kích thước: 84 bytes
//   0x179d70: B9402FE2  ldr      w2, [sp, #0x2c]
//   0x179d74: F9401FE3  ldr      x3, [sp, #0x38]
//   0x179d78: F942EA80  ldr      x0, [x20, #0x5d0]
//   0x179d7c: AA1303E1  mov      x1, x19
static inline uint64_t fde_func_1657_0x179d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179d70ULL ^ (static_cast<uint64_t>(0xb9402fe2ULL) << 13);
    acc = (acc + a1 + 0xf9401fe3ULL) ^ 0x093c30ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1658 | PC: 0x179dc4 | FDE: 0x093c90 | Size: 112 bytes
// Khung tháo gỡ #1658 | Địa chỉ PC: 0x179dc4 | Địa chỉ FDE: 0x093c90 | Kích thước: 112 bytes
//   0x179dc4: F9401C13  ldr      x19, [x0, #0x38]
//   0x179dc8: A9400440  ldp      x0, x1, [x2]
//   0x179dcc: 17FF5947  b        #0x1502e8
//   0x179dd0: 52817922  mov      w2, #0xbc9
static inline uint64_t fde_func_1658_0x179dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179dc4ULL ^ (static_cast<uint64_t>(0xf9401c13ULL) << 13);
    acc = (acc + a1 + 0xa9400440ULL) ^ 0x093c90ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1659 | PC: 0x179e34 | FDE: 0x093cf0 | Size: 84 bytes
// Khung tháo gỡ #1659 | Địa chỉ PC: 0x179e34 | Địa chỉ FDE: 0x093cf0 | Kích thước: 84 bytes
//   0x179e34: A900A3E9  stp      x9, x8, [sp, #8]
//   0x179e38: F90003EA  str      x10, [sp]
//   0x179e3c: 17FDF677  b        #0xf7818
//   0x179e40: F9404A68  ldr      x8, [x19, #0x90]
static inline uint64_t fde_func_1659_0x179e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179e34ULL ^ (static_cast<uint64_t>(0xa900a3e9ULL) << 13);
    acc = (acc + a1 + 0xf90003eaULL) ^ 0x093cf0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1660 | PC: 0x179e88 | FDE: 0x093d50 | Size: 132 bytes
// Khung tháo gỡ #1660 | Địa chỉ PC: 0x179e88 | Địa chỉ FDE: 0x093d50 | Kích thước: 132 bytes
//   0x179e88: F94013F6  ldr      x22, [sp, #0x20]
//   0x179e8c: F9000008  str      x8, [x0]
//   0x179e90: D0FFFEA8  adrp     x8, #0x14f000
//   0x179e94: A900FC1F  stp      xzr, xzr, [x0, #8]
static inline uint64_t fde_func_1660_0x179e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179e88ULL ^ (static_cast<uint64_t>(0xf94013f6ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x093d50ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1661 | PC: 0x179f0c | FDE: 0x093db0 | Size: 60 bytes
// Khung tháo gỡ #1661 | Địa chỉ PC: 0x179f0c | Địa chỉ FDE: 0x093db0 | Kích thước: 60 bytes
//   0x179f0c: F940AFE9  ldr      x9, [sp, #0x158]
//   0x179f10: EB09011F  cmp      x8, x9
//   0x179f14: D65F03C0  ret      
//   0x179f18: F9400288  ldr      x8, [x20]
static inline uint64_t fde_func_1661_0x179f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179f0cULL ^ (static_cast<uint64_t>(0xf940afe9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x093db0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1662 | PC: 0x179f48 | FDE: 0x093e10 | Size: 60 bytes
// Khung tháo gỡ #1662 | Địa chỉ PC: 0x179f48 | Địa chỉ FDE: 0x093e10 | Kích thước: 60 bytes
//   0x179f48: A94B53F5  ldp      x21, x20, [sp, #0xb0]
//   0x179f4c: A94A5BF7  ldp      x23, x22, [sp, #0xa0]
//   0x179f50: F9404BF8  ldr      x24, [sp, #0x90]
//   0x179f54: 910343FF  add      sp, sp, #0xd0
static inline uint64_t fde_func_1662_0x179f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179f48ULL ^ (static_cast<uint64_t>(0xa94b53f5ULL) << 13);
    acc = (acc + a1 + 0xa94a5bf7ULL) ^ 0x093e10ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1663 | PC: 0x179f84 | FDE: 0x093e70 | Size: 40 bytes
// Khung tháo gỡ #1663 | Địa chỉ PC: 0x179f84 | Địa chỉ FDE: 0x093e70 | Kích thước: 40 bytes
//   0x179f84: 9100C3E0  add      x0, sp, #0x30
//   0x179f88: F9001BE8  str      x8, [sp, #0x30]
//   0x179f8c: 14003DF1  b        #0x189750
//   0x179f90: 910143E0  add      x0, sp, #0x50
static inline uint64_t fde_func_1663_0x179f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179f84ULL ^ (static_cast<uint64_t>(0x9100c3e0ULL) << 13);
    acc = (acc + a1 + 0xf9001be8ULL) ^ 0x093e70ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1664 | PC: 0x179fac | FDE: 0x093ed0 | Size: 128 bytes
// Khung tháo gỡ #1664 | Địa chỉ PC: 0x179fac | Địa chỉ FDE: 0x093ed0 | Kích thước: 128 bytes
//   0x179fac: A9454FF4  ldp      x20, x19, [sp, #0x50]
//   0x179fb0: A94457F6  ldp      x22, x21, [sp, #0x40]
//   0x179fb4: A9435FF8  ldp      x24, x23, [sp, #0x30]
//   0x179fb8: A94267FA  ldp      x26, x25, [sp, #0x20]
static inline uint64_t fde_func_1664_0x179fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179facULL ^ (static_cast<uint64_t>(0xa9454ff4ULL) << 13);
    acc = (acc + a1 + 0xa94457f6ULL) ^ 0x093ed0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1665 | PC: 0x17a02c | FDE: 0x093f30 | Size: 84 bytes
// Khung tháo gỡ #1665 | Địa chỉ PC: 0x17a02c | Địa chỉ FDE: 0x093f30 | Kích thước: 84 bytes
//   0x17a02c: 910023E1  add      x1, sp, #8
//   0x17a030: AA1403E0  mov      x0, x20
//   0x17a034: D65F03C0  ret      
//   0x17a038: A94553F5  ldp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_1665_0x17a02c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a02cULL ^ (static_cast<uint64_t>(0x910023e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x093f30ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1666 | PC: 0x17a080 | FDE: 0x093f90 | Size: 40 bytes
// Khung tháo gỡ #1666 | Địa chỉ PC: 0x17a080 | Địa chỉ FDE: 0x093f90 | Kích thước: 40 bytes
//   0x17a080: 910063E0  add      x0, sp, #0x18
//   0x17a084: AA1F03E3  mov      x3, xzr
//   0x17a088: 17FEF073  b        #0x136254
//   0x17a08c: 910063E0  add      x0, sp, #0x18
static inline uint64_t fde_func_1666_0x17a080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a080ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x093f90ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1667 | PC: 0x17a0a8 | FDE: 0x093ff0 | Size: 44 bytes
// Khung tháo gỡ #1667 | Địa chỉ PC: 0x17a0a8 | Địa chỉ FDE: 0x093ff0 | Kích thước: 44 bytes
//   0x17a0a8: A9000296  stp      x22, x0, [x20]
//   0x17a0ac: AA1403E0  mov      x0, x20
//   0x17a0b0: AA1603E1  mov      x1, x22
//   0x17a0b4: 14003E37  b        #0x189990
static inline uint64_t fde_func_1667_0x17a0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a0a8ULL ^ (static_cast<uint64_t>(0xa9000296ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x093ff0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1668 | PC: 0x17a0d4 | FDE: 0x094050 | Size: 80 bytes
// Khung tháo gỡ #1668 | Địa chỉ PC: 0x17a0d4 | Địa chỉ FDE: 0x094050 | Kích thước: 80 bytes
//   0x17a0d4: A94353F5  ldp      x21, x20, [sp, #0x30]
//   0x17a0d8: A9425BF7  ldp      x23, x22, [sp, #0x20]
//   0x17a0dc: A94163F9  ldp      x25, x24, [sp, #0x10]
//   0x17a0e0: A8C56BFC  ldp      x28, x26, [sp], #0x50
static inline uint64_t fde_func_1668_0x17a0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a0d4ULL ^ (static_cast<uint64_t>(0xa94353f5ULL) << 13);
    acc = (acc + a1 + 0xa9425bf7ULL) ^ 0x094050ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1669 | PC: 0x17a124 | FDE: 0x0940b0 | Size: 64 bytes
// Khung tháo gỡ #1669 | Địa chỉ PC: 0x17a124 | Địa chỉ FDE: 0x0940b0 | Kích thước: 64 bytes
//   0x17a124: F940F296  ldr      x22, [x20, #0x1e0]
//   0x17a128: AA0203E0  mov      x0, x2
//   0x17a12c: 2A0103F3  mov      w19, w1
//   0x17a130: AA0203F5  mov      x21, x2
static inline uint64_t fde_func_1669_0x17a124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a124ULL ^ (static_cast<uint64_t>(0xf940f296ULL) << 13);
    acc = (acc + a1 + 0xaa0203e0ULL) ^ 0x0940b0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1670 | PC: 0x17a164 | FDE: 0x094110 | Size: 64 bytes
// Khung tháo gỡ #1670 | Địa chỉ PC: 0x17a164 | Địa chỉ FDE: 0x094110 | Kích thước: 64 bytes
//   0x17a164: F9400428  ldr      x8, [x1, #8]
//   0x17a168: F9000408  str      x8, [x0, #8]
//   0x17a16c: 17FF5A19  b        #0x1509d0
//   0x17a170: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1670_0x17a164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a164ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xf9000408ULL) ^ 0x094110ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1671 | PC: 0x17a1a4 | FDE: 0x094170 | Size: 104 bytes
// Khung tháo gỡ #1671 | Địa chỉ PC: 0x17a1a4 | Địa chỉ FDE: 0x094170 | Kích thước: 104 bytes
//   0x17a1a4: D53BD054  mrs      x20, tpidr_el0
//   0x17a1a8: F9401688  ldr      x8, [x20, #0x28]
//   0x17a1ac: AA0003F3  mov      x19, x0
//   0x17a1b0: F9002FE8  str      x8, [sp, #0x58]
static inline uint64_t fde_func_1671_0x17a1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a1a4ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x094170ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1672 | PC: 0x17a20c | FDE: 0x0941d0 | Size: 56 bytes
// Khung tháo gỡ #1672 | Địa chỉ PC: 0x17a20c | Địa chỉ FDE: 0x0941d0 | Kích thước: 56 bytes
//   0x17a20c: F9400008  ldr      x8, [x0]
//   0x17a210: F9401108  ldr      x8, [x8, #0x20]
//   0x17a214: D65F03C0  ret      
//   0x17a218: F9400668  ldr      x8, [x19, #8]
static inline uint64_t fde_func_1672_0x17a20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a20cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401108ULL) ^ 0x0941d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1673 | PC: 0x17a244 | FDE: 0x094230 | Size: 44 bytes
// Khung tháo gỡ #1673 | Địa chỉ PC: 0x17a244 | Địa chỉ FDE: 0x094230 | Kích thước: 44 bytes
//   0x17a244: AA1303E0  mov      x0, x19
//   0x17a248: AA1403E2  mov      x2, x20
//   0x17a24c: AA1F03E3  mov      x3, xzr
//   0x17a250: D61F0100  br       x8
static inline uint64_t fde_func_1673_0x17a244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a244ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e2ULL) ^ 0x094230ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1674 | PC: 0x17a270 | FDE: 0x094290 | Size: 48 bytes
// Khung tháo gỡ #1674 | Địa chỉ PC: 0x17a270 | Địa chỉ FDE: 0x094290 | Kích thước: 48 bytes
//   0x17a270: 910043E0  add      x0, sp, #0x10
//   0x17a274: AA1F03E3  mov      x3, xzr
//   0x17a278: 17FEBDAA  b        #0x129920
//   0x17a27c: 910043E0  add      x0, sp, #0x10
static inline uint64_t fde_func_1674_0x17a270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a270ULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x094290ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1675 | PC: 0x17a2a0 | FDE: 0x0942f0 | Size: 64 bytes
// Khung tháo gỡ #1675 | Địa chỉ PC: 0x17a2a0 | Địa chỉ FDE: 0x0942f0 | Kích thước: 64 bytes
//   0x17a2a0: D53BD058  mrs      x24, tpidr_el0
//   0x17a2a4: F9401708  ldr      x8, [x24, #0x28]
//   0x17a2a8: AA0003F3  mov      x19, x0
//   0x17a2ac: 9100C3E0  add      x0, sp, #0x30
static inline uint64_t fde_func_1675_0x17a2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a2a0ULL ^ (static_cast<uint64_t>(0xd53bd058ULL) << 13);
    acc = (acc + a1 + 0xf9401708ULL) ^ 0x0942f0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1676 | PC: 0x17a2e0 | FDE: 0x094350 | Size: 64 bytes
// Khung tháo gỡ #1676 | Địa chỉ PC: 0x17a2e0 | Địa chỉ FDE: 0x094350 | Kích thước: 64 bytes
//   0x17a2e0: 910023E0  add      x0, sp, #8
//   0x17a2e4: 2A1303E1  mov      w1, w19
//   0x17a2e8: F90007F4  str      x20, [sp, #8]
//   0x17a2ec: 17FF575D  b        #0x150060
static inline uint64_t fde_func_1676_0x17a2e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a2e0ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0x2a1303e1ULL) ^ 0x094350ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1677 | PC: 0x17a320 | FDE: 0x0943b0 | Size: 76 bytes
// Khung tháo gỡ #1677 | Địa chỉ PC: 0x17a320 | Địa chỉ FDE: 0x0943b0 | Kích thước: 76 bytes
//   0x17a320: AA0003F4  mov      x20, x0
//   0x17a324: AA0103F5  mov      x21, x1
//   0x17a328: D65F03C0  ret      
//   0x17a32c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1677_0x17a320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a320ULL ^ (static_cast<uint64_t>(0xaa0003f4ULL) << 13);
    acc = (acc + a1 + 0xaa0103f5ULL) ^ 0x0943b0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1678 | PC: 0x17a36c | FDE: 0x094410 | Size: 72 bytes
// Khung tháo gỡ #1678 | Địa chỉ PC: 0x17a36c | Địa chỉ FDE: 0x094410 | Kích thước: 72 bytes
//   0x17a36c: 9B080348  madd     x8, x26, x8, x0
//   0x17a370: AA1903E0  mov      x0, x25
//   0x17a374: AA1703E1  mov      x1, x23
//   0x17a378: AA1603E2  mov      x2, x22
static inline uint64_t fde_func_1678_0x17a36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a36cULL ^ (static_cast<uint64_t>(0x9b080348ULL) << 13);
    acc = (acc + a1 + 0xaa1903e0ULL) ^ 0x094410ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1679 | PC: 0x17a3b4 | FDE: 0x094470 | Size: 92 bytes
// Khung tháo gỡ #1679 | Địa chỉ PC: 0x17a3b4 | Địa chỉ FDE: 0x094470 | Kích thước: 92 bytes
//   0x17a3b4: 4EA81D00  mov      v0.16b, v8.16b
//   0x17a3b8: 4EA91D21  mov      v1.16b, v9.16b
//   0x17a3bc: 4EAA1D42  mov      v2.16b, v10.16b
//   0x17a3c0: 4EAB1D63  mov      v3.16b, v11.16b
static inline uint64_t fde_func_1679_0x17a3b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a3b4ULL ^ (static_cast<uint64_t>(0x4ea81d00ULL) << 13);
    acc = (acc + a1 + 0x4ea91d21ULL) ^ 0x094470ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1680 | PC: 0x17a410 | FDE: 0x0944d0 | Size: 104 bytes
// Khung tháo gỡ #1680 | Địa chỉ PC: 0x17a410 | Địa chỉ FDE: 0x0944d0 | Kích thước: 104 bytes
//   0x17a410: D0FFFD03  adrp     x3, #0x11c000
//   0x17a414: F8008E80  str      x0, [x20, #8]!
//   0x17a418: D65F03C0  ret      
//   0x17a41c: F9402289  ldr      x9, [x20, #0x40]
static inline uint64_t fde_func_1680_0x17a410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a410ULL ^ (static_cast<uint64_t>(0xd0fffd03ULL) << 13);
    acc = (acc + a1 + 0xf8008e80ULL) ^ 0x0944d0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1681 | PC: 0x17a478 | FDE: 0x094530 | Size: 88 bytes
// Khung tháo gỡ #1681 | Địa chỉ PC: 0x17a478 | Địa chỉ FDE: 0x094530 | Kích thước: 88 bytes
//   0x17a478: 7840252B  ldrh     w11, [x9], #2
//   0x17a47c: D1000508  sub      x8, x8, #1
//   0x17a480: 53103D6B  lsl      w11, w11, #0x10
//   0x17a484: 93407D6B  sxtw     x11, w11
static inline uint64_t fde_func_1681_0x17a478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a478ULL ^ (static_cast<uint64_t>(0x7840252bULL) << 13);
    acc = (acc + a1 + 0xd1000508ULL) ^ 0x094530ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1682 | PC: 0x17a4d0 | FDE: 0x094590 | Size: 80 bytes
// Khung tháo gỡ #1682 | Địa chỉ PC: 0x17a4d0 | Địa chỉ FDE: 0x094590 | Kích thước: 80 bytes
//   0x17a4d0: B950CBE8  ldr      w8, [sp, #0x10c8]
//   0x17a4d4: B9400269  ldr      w9, [x19]
//   0x17a4d8: 0B080128  add      w8, w9, w8
//   0x17a4dc: B9000268  str      w8, [x19]
static inline uint64_t fde_func_1682_0x17a4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a4d0ULL ^ (static_cast<uint64_t>(0xb950cbe8ULL) << 13);
    acc = (acc + a1 + 0xb9400269ULL) ^ 0x094590ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1683 | PC: 0x17a520 | FDE: 0x0945f0 | Size: 96 bytes
// Khung tháo gỡ #1683 | Địa chỉ PC: 0x17a520 | Địa chỉ FDE: 0x0945f0 | Kích thước: 96 bytes
//   0x17a520: 0B080128  add      w8, w9, w8
//   0x17a524: 1E220101  scvtf    s1, w8
//   0x17a528: 1E210800  fmul     s0, s0, s1
//   0x17a52c: 1E282800  fadd     s0, s0, s8
static inline uint64_t fde_func_1683_0x17a520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a520ULL ^ (static_cast<uint64_t>(0x0b080128ULL) << 13);
    acc = (acc + a1 + 0x1e220101ULL) ^ 0x0945f0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1684 | PC: 0x17a580 | FDE: 0x094650 | Size: 160 bytes
// Khung tháo gỡ #1684 | Địa chỉ PC: 0x17a580 | Địa chỉ FDE: 0x094650 | Kích thước: 160 bytes
//   0x17a580: F9401808  ldr      x8, [x0, #0x30]
//   0x17a584: 5296D589  mov      w9, #0xb6ac
//   0x17a588: 52802D8A  mov      w10, #0x16c
//   0x17a58c: B8A96909  ldrsw    x9, [x8, x9]
static inline uint64_t fde_func_1684_0x17a580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a580ULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0x5296d589ULL) ^ 0x094650ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1685 | PC: 0x17a620 | FDE: 0x0946b0 | Size: 64 bytes
// Khung tháo gỡ #1685 | Địa chỉ PC: 0x17a620 | Địa chỉ FDE: 0x0946b0 | Kích thước: 64 bytes
//   0x17a620: B9401190  ldr      w16, [x12, #0x10]
//   0x17a624: B94011F1  ldr      w17, [x15, #0x10]
//   0x17a628: 6B11021F  cmp      w16, w17
//   0x17a62c: D65F03C0  ret      
static inline uint64_t fde_func_1685_0x17a620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a620ULL ^ (static_cast<uint64_t>(0xb9401190ULL) << 13);
    acc = (acc + a1 + 0xb94011f1ULL) ^ 0x0946b0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1686 | PC: 0x17a660 | FDE: 0x094710 | Size: 48 bytes
// Khung tháo gỡ #1686 | Địa chỉ PC: 0x17a660 | Địa chỉ FDE: 0x094710 | Kích thước: 48 bytes
//   0x17a660: F9404661  ldr      x1, [x19, #0x88]
//   0x17a664: 17FCB8C8  b        #0xa8984
//   0x17a668: 910443FF  add      sp, sp, #0x110
//   0x17a66c: D65F03C0  ret      
static inline uint64_t fde_func_1686_0x17a660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a660ULL ^ (static_cast<uint64_t>(0xf9404661ULL) << 13);
    acc = (acc + a1 + 0x17fcb8c8ULL) ^ 0x094710ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1687 | PC: 0x17a690 | FDE: 0x094770 | Size: 56 bytes
// Khung tháo gỡ #1687 | Địa chỉ PC: 0x17a690 | Địa chỉ FDE: 0x094770 | Kích thước: 56 bytes
//   0x17a690: F9000500  str      x0, [x8, #8]
//   0x17a694: 1400331F  b        #0x187310
//   0x17a698: 9B0802A9  madd     x9, x21, x8, x0
//   0x17a69c: 9B080288  madd     x8, x20, x8, x0
static inline uint64_t fde_func_1687_0x17a690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a690ULL ^ (static_cast<uint64_t>(0xf9000500ULL) << 13);
    acc = (acc + a1 + 0x1400331fULL) ^ 0x094770ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1688 | PC: 0x17a6c8 | FDE: 0x0947d0 | Size: 52 bytes
// Khung tháo gỡ #1688 | Địa chỉ PC: 0x17a6c8 | Địa chỉ FDE: 0x0947d0 | Kích thước: 52 bytes
//   0x17a6c8: 910063E0  add      x0, sp, #0x18
//   0x17a6cc: AA1F03E3  mov      x3, xzr
//   0x17a6d0: A901A3E9  stp      x9, x8, [sp, #0x18]
//   0x17a6d4: D65F03C0  ret      
static inline uint64_t fde_func_1688_0x17a6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a6c8ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x0947d0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1689 | PC: 0x17a6fc | FDE: 0x094830 | Size: 64 bytes
// Khung tháo gỡ #1689 | Địa chỉ PC: 0x17a6fc | Địa chỉ FDE: 0x094830 | Kích thước: 64 bytes
//   0x17a6fc: F9400A68  ldr      x8, [x19, #0x10]
//   0x17a700: 3DC00260  ldr      q0, [x19]
//   0x17a704: AA1303E0  mov      x0, x19
//   0x17a708: F9000A88  str      x8, [x20, #0x10]
static inline uint64_t fde_func_1689_0x17a6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a6fcULL ^ (static_cast<uint64_t>(0xf9400a68ULL) << 13);
    acc = (acc + a1 + 0x3dc00260ULL) ^ 0x094830ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1690 | PC: 0x17a73c | FDE: 0x094890 | Size: 48 bytes
// Khung tháo gỡ #1690 | Địa chỉ PC: 0x17a73c | Địa chỉ FDE: 0x094890 | Kích thước: 48 bytes
//   0x17a73c: D53BD055  mrs      x21, tpidr_el0
//   0x17a740: F94016A8  ldr      x8, [x21, #0x28]
//   0x17a744: AA0103F4  mov      x20, x1
//   0x17a748: D65F03C0  ret      
static inline uint64_t fde_func_1690_0x17a73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a73cULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x094890ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1691 | PC: 0x17a76c | FDE: 0x0948f0 | Size: 76 bytes
// Khung tháo gỡ #1691 | Địa chỉ PC: 0x17a76c | Địa chỉ FDE: 0x0948f0 | Kích thước: 76 bytes
//   0x17a76c: 2A1F03E1  mov      w1, wzr
//   0x17a770: 14003498  b        #0x1879d0
//   0x17a774: D53BD056  mrs      x22, tpidr_el0
//   0x17a778: F94016C8  ldr      x8, [x22, #0x28]
static inline uint64_t fde_func_1691_0x17a76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a76cULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14003498ULL) ^ 0x0948f0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1692 | PC: 0x17a7b8 | FDE: 0x094950 | Size: 72 bytes
// Khung tháo gỡ #1692 | Địa chỉ PC: 0x17a7b8 | Địa chỉ FDE: 0x094950 | Kích thước: 72 bytes
//   0x17a7b8: D53BD054  mrs      x20, tpidr_el0
//   0x17a7bc: F9401688  ldr      x8, [x20, #0x28]
//   0x17a7c0: AA0003F3  mov      x19, x0
//   0x17a7c4: D65F03C0  ret      
static inline uint64_t fde_func_1692_0x17a7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a7b8ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x094950ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1693 | PC: 0x17a800 | FDE: 0x0949b0 | Size: 124 bytes
// Khung tháo gỡ #1693 | Địa chỉ PC: 0x17a800 | Địa chỉ FDE: 0x0949b0 | Kích thước: 124 bytes
//   0x17a800: F9400028  ldr      x8, [x1]
//   0x17a804: AA0003F3  mov      x19, x0
//   0x17a808: F9000008  str      x8, [x0]
//   0x17a80c: F9400420  ldr      x0, [x1, #8]
static inline uint64_t fde_func_1693_0x17a800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a800ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0949b0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1694 | PC: 0x17a87c | FDE: 0x094a18 | Size: 36 bytes
// Khung tháo gỡ #1694 | Địa chỉ PC: 0x17a87c | Địa chỉ FDE: 0x094a18 | Kích thước: 36 bytes
//   0x17a87c: 910043E0  add      x0, sp, #0x10
//   0x17a880: 14003350  b        #0x1875c0
//   0x17a884: 910043E0  add      x0, sp, #0x10
//   0x17a888: 14003316  b        #0x1874e0
static inline uint64_t fde_func_1694_0x17a87c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a87cULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0x14003350ULL) ^ 0x094a18ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1695 | PC: 0x17a8a0 | FDE: 0x094a78 | Size: 48 bytes
// Khung tháo gỡ #1695 | Địa chỉ PC: 0x17a8a0 | Địa chỉ FDE: 0x094a78 | Kích thước: 48 bytes
//   0x17a8a0: D53BD058  mrs      x24, tpidr_el0
//   0x17a8a4: F9401708  ldr      x8, [x24, #0x28]
//   0x17a8a8: AA0103F3  mov      x19, x1
//   0x17a8ac: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1695_0x17a8a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a8a0ULL ^ (static_cast<uint64_t>(0xd53bd058ULL) << 13);
    acc = (acc + a1 + 0xf9401708ULL) ^ 0x094a78ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1696 | PC: 0x17a8d0 | FDE: 0x094ad8 | Size: 60 bytes
// Khung tháo gỡ #1696 | Địa chỉ PC: 0x17a8d0 | Địa chỉ FDE: 0x094ad8 | Kích thước: 60 bytes
//   0x17a8d0: AA0003F5  mov      x21, x0
//   0x17a8d4: F94002C0  ldr      x0, [x22]
//   0x17a8d8: F90002DF  str      xzr, [x22]
//   0x17a8dc: F9401EA8  ldr      x8, [x21, #0x38]
static inline uint64_t fde_func_1696_0x17a8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a8d0ULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0xf94002c0ULL) ^ 0x094ad8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1697 | PC: 0x17a90c | FDE: 0x094b38 | Size: 88 bytes
// Khung tháo gỡ #1697 | Địa chỉ PC: 0x17a90c | Địa chỉ FDE: 0x094b38 | Kích thước: 88 bytes
//   0x17a90c: 11001A78  add      w24, w19, #6
//   0x17a910: 2A1803F3  mov      w19, w24
//   0x17a914: D65F03C0  ret      
//   0x17a918: 7100011F  cmp      w8, #0
static inline uint64_t fde_func_1697_0x17a90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a90cULL ^ (static_cast<uint64_t>(0x11001a78ULL) << 13);
    acc = (acc + a1 + 0x2a1803f3ULL) ^ 0x094b38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1698 | PC: 0x17a964 | FDE: 0x094b98 | Size: 80 bytes
// Khung tháo gỡ #1698 | Địa chỉ PC: 0x17a964 | Địa chỉ FDE: 0x094b98 | Kích thước: 80 bytes
//   0x17a964: 8B161008  add      x8, x0, x22, lsl #4
//   0x17a968: 8B151009  add      x9, x0, x21, lsl #4
//   0x17a96c: F90013E9  str      x9, [sp, #0x20]
//   0x17a970: A900A3E0  stp      x0, x8, [sp, #8]
static inline uint64_t fde_func_1698_0x17a964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a964ULL ^ (static_cast<uint64_t>(0x8b161008ULL) << 13);
    acc = (acc + a1 + 0x8b151009ULL) ^ 0x094b98ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1699 | PC: 0x17a9b4 | FDE: 0x094bf8 | Size: 56 bytes
// Khung tháo gỡ #1699 | Địa chỉ PC: 0x17a9b4 | Địa chỉ FDE: 0x094bf8 | Kích thước: 56 bytes
//   0x17a9b4: 910943E0  add      x0, sp, #0x250
//   0x17a9b8: 1E22C000  fcvt     d0, s0
//   0x17a9bc: 17FF5887  b        #0x150bd8
//   0x17a9c0: 9106C3FF  add      sp, sp, #0x1b0
static inline uint64_t fde_func_1699_0x17a9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a9b4ULL ^ (static_cast<uint64_t>(0x910943e0ULL) << 13);
    acc = (acc + a1 + 0x1e22c000ULL) ^ 0x094bf8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1700 | PC: 0x17a9ec | FDE: 0x094c58 | Size: 88 bytes
// Khung tháo gỡ #1700 | Địa chỉ PC: 0x17a9ec | Địa chỉ FDE: 0x094c58 | Kích thước: 88 bytes
//   0x17a9ec: B9400701  ldr      w1, [x24, #4]
//   0x17a9f0: 914007E8  add      x8, sp, #1, lsl #12
//   0x17a9f4: AA0003F6  mov      x22, x0
//   0x17a9f8: 8B394AA0  add      x0, x21, w25, uxtw #2
static inline uint64_t fde_func_1700_0x17a9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a9ecULL ^ (static_cast<uint64_t>(0xb9400701ULL) << 13);
    acc = (acc + a1 + 0x914007e8ULL) ^ 0x094c58ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1701 | PC: 0x17aa44 | FDE: 0x094cb8 | Size: 140 bytes
// Khung tháo gỡ #1701 | Địa chỉ PC: 0x17aa44 | Địa chỉ FDE: 0x094cb8 | Kích thước: 140 bytes
//   0x17aa44: B9400268  ldr      w8, [x19]
//   0x17aa48: 8B080AA9  add      x9, x21, x8, lsl #2
//   0x17aa4c: 11002908  add      w8, w8, #0xa
//   0x17aa50: B9000268  str      w8, [x19]
static inline uint64_t fde_func_1701_0x17aa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17aa44ULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x8b080aa9ULL) ^ 0x094cb8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1702 | PC: 0x17aad0 | FDE: 0x094d18 | Size: 60 bytes
// Khung tháo gỡ #1702 | Địa chỉ PC: 0x17aad0 | Địa chỉ FDE: 0x094d18 | Kích thước: 60 bytes
//   0x17aad0: B943EC08  ldr      w8, [x0, #0x3ec]
//   0x17aad4: 6B01011F  cmp      w8, w1
//   0x17aad8: D65F03C0  ret      
//   0x17aadc: B9402FE2  ldr      w2, [sp, #0x2c]
static inline uint64_t fde_func_1702_0x17aad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17aad0ULL ^ (static_cast<uint64_t>(0xb943ec08ULL) << 13);
    acc = (acc + a1 + 0x6b01011fULL) ^ 0x094d18ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1703 | PC: 0x17ab0c | FDE: 0x094d78 | Size: 92 bytes
// Khung tháo gỡ #1703 | Địa chỉ PC: 0x17ab0c | Địa chỉ FDE: 0x094d78 | Kích thước: 92 bytes
//   0x17ab0c: AA1F03F4  mov      x20, xzr
//   0x17ab10: AA1F03F3  mov      x19, xzr
//   0x17ab14: D65F03C0  ret      
//   0x17ab18: 531F7AC8  lsl      w8, w22, #1
static inline uint64_t fde_func_1703_0x17ab0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ab0cULL ^ (static_cast<uint64_t>(0xaa1f03f4ULL) << 13);
    acc = (acc + a1 + 0xaa1f03f3ULL) ^ 0x094d78ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1704 | PC: 0x17ab68 | FDE: 0x094dd8 | Size: 80 bytes
// Khung tháo gỡ #1704 | Địa chỉ PC: 0x17ab68 | Địa chỉ FDE: 0x094dd8 | Kích thước: 80 bytes
//   0x17ab68: 90FFF5E1  adrp     x1, #0x36000
//   0x17ab6c: 91350821  add      x1, x1, #0xd42
//   0x17ab70: AA1503E0  mov      x0, x21
//   0x17ab74: 2A1603E2  mov      w2, w22
static inline uint64_t fde_func_1704_0x17ab68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ab68ULL ^ (static_cast<uint64_t>(0x90fff5e1ULL) << 13);
    acc = (acc + a1 + 0x91350821ULL) ^ 0x094dd8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1705 | PC: 0x17abb8 | FDE: 0x094e38 | Size: 60 bytes
// Khung tháo gỡ #1705 | Địa chỉ PC: 0x17abb8 | Địa chỉ FDE: 0x094e38 | Kích thước: 60 bytes
//   0x17abb8: F9402400  ldr      x0, [x0, #0x48]
//   0x17abbc: F9400433  ldr      x19, [x1, #8]
//   0x17abc0: D65F03C0  ret      
//   0x17abc4: F90077E0  str      x0, [sp, #0xe8]
static inline uint64_t fde_func_1705_0x17abb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17abb8ULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xf9400433ULL) ^ 0x094e38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1706 | PC: 0x17abf4 | FDE: 0x094ea0 | Size: 44 bytes
// Khung tháo gỡ #1706 | Địa chỉ PC: 0x17abf4 | Địa chỉ FDE: 0x094ea0 | Kích thước: 44 bytes
//   0x17abf4: F9400661  ldr      x1, [x19, #8]
//   0x17abf8: 9100A3E0  add      x0, sp, #0x28
//   0x17abfc: 17FF53F9  b        #0x14fbe0
//   0x17ac00: 9100E3E0  add      x0, sp, #0x38
static inline uint64_t fde_func_1706_0x17abf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17abf4ULL ^ (static_cast<uint64_t>(0xf9400661ULL) << 13);
    acc = (acc + a1 + 0x9100a3e0ULL) ^ 0x094ea0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1707 | PC: 0x17ac20 | FDE: 0x094f00 | Size: 88 bytes
// Khung tháo gỡ #1707 | Địa chỉ PC: 0x17ac20 | Địa chỉ FDE: 0x094f00 | Kích thước: 88 bytes
//   0x17ac20: AA0303E0  mov      x0, x3
//   0x17ac24: AA0303F6  mov      x22, x3
//   0x17ac28: 2A0203F3  mov      w19, w2
//   0x17ac2c: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1707_0x17ac20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ac20ULL ^ (static_cast<uint64_t>(0xaa0303e0ULL) << 13);
    acc = (acc + a1 + 0xaa0303f6ULL) ^ 0x094f00ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1708 | PC: 0x17ac78 | FDE: 0x094f60 | Size: 32 bytes
// Khung tháo gỡ #1708 | Địa chỉ PC: 0x17ac78 | Địa chỉ FDE: 0x094f60 | Kích thước: 32 bytes
//   0x17ac78: 910103E0  add      x0, sp, #0x40
//   0x17ac7c: 14003251  b        #0x1875c0
//   0x17ac80: 910103E0  add      x0, sp, #0x40
//   0x17ac84: 17FCB91D  b        #0xa90f8
static inline uint64_t fde_func_1708_0x17ac78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ac78ULL ^ (static_cast<uint64_t>(0x910103e0ULL) << 13);
    acc = (acc + a1 + 0x14003251ULL) ^ 0x094f60ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1709 | PC: 0x17ac98 | FDE: 0x094fc0 | Size: 40 bytes
// Khung tháo gỡ #1709 | Địa chỉ PC: 0x17ac98 | Địa chỉ FDE: 0x094fc0 | Kích thước: 40 bytes
//   0x17ac98: 9101C3E0  add      x0, sp, #0x70
//   0x17ac9c: 14003B49  b        #0x1899c0
//   0x17aca0: AA1B03E0  mov      x0, x27
//   0x17aca4: 17FF67D2  b        #0x154bec
static inline uint64_t fde_func_1709_0x17ac98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ac98ULL ^ (static_cast<uint64_t>(0x9101c3e0ULL) << 13);
    acc = (acc + a1 + 0x14003b49ULL) ^ 0x094fc0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1710 | PC: 0x17acc0 | FDE: 0x095020 | Size: 64 bytes
// Khung tháo gỡ #1710 | Địa chỉ PC: 0x17acc0 | Địa chỉ FDE: 0x095020 | Kích thước: 64 bytes
//   0x17acc0: AA0003E1  mov      x1, x0
//   0x17acc4: AA1403E0  mov      x0, x20
//   0x17acc8: D65F03C0  ret      
//   0x17accc: D101C3FF  sub      sp, sp, #0x70
static inline uint64_t fde_func_1710_0x17acc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17acc0ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x095020ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1711 | PC: 0x17ad00 | FDE: 0x095080 | Size: 100 bytes
// Khung tháo gỡ #1711 | Địa chỉ PC: 0x17ad00 | Địa chỉ FDE: 0x095080 | Kích thước: 100 bytes
//   0x17ad00: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17ad04: F9400828  ldr      x8, [x1, #0x10]
//   0x17ad08: 3DC00020  ldr      q0, [x1]
//   0x17ad0c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1711_0x17ad00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ad00ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400828ULL) ^ 0x095080ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1712 | PC: 0x17ad64 | FDE: 0x0950e8 | Size: 48 bytes
// Khung tháo gỡ #1712 | Địa chỉ PC: 0x17ad64 | Địa chỉ FDE: 0x0950e8 | Kích thước: 48 bytes
//   0x17ad64: F9000008  str      x8, [x0]
//   0x17ad68: 29015416  stp      w22, w21, [x0, #8]
//   0x17ad6c: F9000809  str      x9, [x0, #0x10]
//   0x17ad70: 52800021  mov      w1, #1
static inline uint64_t fde_func_1712_0x17ad64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ad64ULL ^ (static_cast<uint64_t>(0xf9000008ULL) << 13);
    acc = (acc + a1 + 0x29015416ULL) ^ 0x0950e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1713 | PC: 0x17ad94 | FDE: 0x095148 | Size: 72 bytes
// Khung tháo gỡ #1713 | Địa chỉ PC: 0x17ad94 | Địa chỉ FDE: 0x095148 | Kích thước: 72 bytes
//   0x17ad94: D53BD054  mrs      x20, tpidr_el0
//   0x17ad98: F9401688  ldr      x8, [x20, #0x28]
//   0x17ad9c: F9000FE8  str      x8, [sp, #0x18]
//   0x17ada0: F9402413  ldr      x19, [x0, #0x48]
static inline uint64_t fde_func_1713_0x17ad94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ad94ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x095148ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1714 | PC: 0x17addc | FDE: 0x0951a8 | Size: 68 bytes
// Khung tháo gỡ #1714 | Địa chỉ PC: 0x17addc | Địa chỉ FDE: 0x0951a8 | Kích thước: 68 bytes
//   0x17addc: AA1303E0  mov      x0, x19
//   0x17ade0: 2A1F03E3  mov      w3, wzr
//   0x17ade4: 17FCE9B7  b        #0xb54c0
//   0x17ade8: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1714_0x17addc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17addcULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e3ULL) ^ 0x0951a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1715 | PC: 0x17ae20 | FDE: 0x095208 | Size: 48 bytes
// Khung tháo gỡ #1715 | Địa chỉ PC: 0x17ae20 | Địa chỉ FDE: 0x095208 | Kích thước: 48 bytes
//   0x17ae20: AA0003F3  mov      x19, x0
//   0x17ae24: 14003233  b        #0x1876f0
//   0x17ae28: AA0003F3  mov      x19, x0
//   0x17ae2c: F9000FE8  str      x8, [sp, #0x18]
static inline uint64_t fde_func_1715_0x17ae20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ae20ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x14003233ULL) ^ 0x095208ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1716 | PC: 0x17ae50 | FDE: 0x095268 | Size: 48 bytes
// Khung tháo gỡ #1716 | Địa chỉ PC: 0x17ae50 | Địa chỉ FDE: 0x095268 | Kích thước: 48 bytes
//   0x17ae50: AA1403E0  mov      x0, x20
//   0x17ae54: A900D7F4  stp      x20, x21, [sp, #8]
//   0x17ae58: 17FE4F14  b        #0x10eaa8
//   0x17ae5c: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1716_0x17ae50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ae50ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0xa900d7f4ULL) ^ 0x095268ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1717 | PC: 0x17ae80 | FDE: 0x0952c8 | Size: 92 bytes
// Khung tháo gỡ #1717 | Địa chỉ PC: 0x17ae80 | Địa chỉ FDE: 0x0952c8 | Kích thước: 92 bytes
//   0x17ae80: AA1403E1  mov      x1, x20
//   0x17ae84: 140032B3  b        #0x187950
//   0x17ae88: 910023E0  add      x0, sp, #8
//   0x17ae8c: AA1F03E3  mov      x3, xzr
static inline uint64_t fde_func_1717_0x17ae80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ae80ULL ^ (static_cast<uint64_t>(0xaa1403e1ULL) << 13);
    acc = (acc + a1 + 0x140032b3ULL) ^ 0x0952c8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1718 | PC: 0x17aedc | FDE: 0x095330 | Size: 48 bytes
// Khung tháo gỡ #1718 | Địa chỉ PC: 0x17aedc | Địa chỉ FDE: 0x095330 | Kích thước: 48 bytes
//   0x17aedc: AA1503E0  mov      x0, x21
//   0x17aee0: 2A0203F3  mov      w19, w2
//   0x17aee4: 17FDA954  b        #0xe5434
//   0x17aee8: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1718_0x17aedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17aedcULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x2a0203f3ULL) ^ 0x095330ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1719 | PC: 0x17af0c | FDE: 0x095390 | Size: 64 bytes
// Khung tháo gỡ #1719 | Địa chỉ PC: 0x17af0c | Địa chỉ FDE: 0x095390 | Kích thước: 64 bytes
//   0x17af0c: A8C253F5  ldp      x21, x20, [sp], #0x20
//   0x17af10: 14003100  b        #0x187310
//   0x17af14: B94006E8  ldr      w8, [x23, #4]
//   0x17af18: 11001269  add      w9, w19, #4
static inline uint64_t fde_func_1719_0x17af0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17af0cULL ^ (static_cast<uint64_t>(0xa8c253f5ULL) << 13);
    acc = (acc + a1 + 0x14003100ULL) ^ 0x095390ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1720 | PC: 0x17af4c | FDE: 0x0953f0 | Size: 100 bytes
// Khung tháo gỡ #1720 | Địa chỉ PC: 0x17af4c | Địa chỉ FDE: 0x0953f0 | Kích thước: 100 bytes
//   0x17af4c: 8B08012C  add      x12, x9, x8
//   0x17af50: 7940018C  ldrh     w12, [x12]
//   0x17af54: 91000908  add      x8, x8, #2
//   0x17af58: 5AC0098C  rev      w12, w12
static inline uint64_t fde_func_1720_0x17af4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17af4cULL ^ (static_cast<uint64_t>(0x8b08012cULL) << 13);
    acc = (acc + a1 + 0x7940018cULL) ^ 0x0953f0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1721 | PC: 0x17afb0 | FDE: 0x095450 | Size: 68 bytes
// Khung tháo gỡ #1721 | Địa chỉ PC: 0x17afb0 | Địa chỉ FDE: 0x095450 | Kích thước: 68 bytes
//   0x17afb0: D10283FF  sub      sp, sp, #0xa0
//   0x17afb4: F90033F8  str      x24, [sp, #0x60]
//   0x17afb8: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x17afbc: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_1721_0x17afb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17afb0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f8ULL) ^ 0x095450ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1722 | PC: 0x17aff4 | FDE: 0x0954b0 | Size: 64 bytes
// Khung tháo gỡ #1722 | Địa chỉ PC: 0x17aff4 | Địa chỉ FDE: 0x0954b0 | Kích thước: 64 bytes
//   0x17aff4: F8008509  str      x9, [x8], #8
//   0x17aff8: 91002001  add      x1, x0, #8
//   0x17affc: AA0803E0  mov      x0, x8
//   0x17b000: 17FCBCDB  b        #0xaa36c
static inline uint64_t fde_func_1722_0x17aff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17aff4ULL ^ (static_cast<uint64_t>(0xf8008509ULL) << 13);
    acc = (acc + a1 + 0x91002001ULL) ^ 0x0954b0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1723 | PC: 0x17b034 | FDE: 0x095510 | Size: 100 bytes
// Khung tháo gỡ #1723 | Địa chỉ PC: 0x17b034 | Địa chỉ FDE: 0x095510 | Kích thước: 100 bytes
//   0x17b034: B0FFF5C1  adrp     x1, #0x34000
//   0x17b038: 9134B421  add      x1, x1, #0xd2d
//   0x17b03c: 910023E0  add      x0, sp, #8
//   0x17b040: D65F03C0  ret      
static inline uint64_t fde_func_1723_0x17b034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b034ULL ^ (static_cast<uint64_t>(0xb0fff5c1ULL) << 13);
    acc = (acc + a1 + 0x9134b421ULL) ^ 0x095510ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1724 | PC: 0x17b098 | FDE: 0x095570 | Size: 88 bytes
// Khung tháo gỡ #1724 | Địa chỉ PC: 0x17b098 | Địa chỉ FDE: 0x095570 | Kích thước: 88 bytes
//   0x17b098: B90013E0  str      w0, [sp, #0x10]
//   0x17b09c: F9401BE0  ldr      x0, [sp, #0x30]
//   0x17b0a0: 294507E2  ldp      w2, w1, [sp, #0x28]
//   0x17b0a4: 2A1903E3  mov      w3, w25
static inline uint64_t fde_func_1724_0x17b098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b098ULL ^ (static_cast<uint64_t>(0xb90013e0ULL) << 13);
    acc = (acc + a1 + 0xf9401be0ULL) ^ 0x095570ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1725 | PC: 0x17b0f0 | FDE: 0x0955d0 | Size: 64 bytes
// Khung tháo gỡ #1725 | Địa chỉ PC: 0x17b0f0 | Địa chỉ FDE: 0x0955d0 | Kích thước: 64 bytes
//   0x17b0f0: B9400AE2  ldr      w2, [x23, #8]
//   0x17b0f4: AA1403E0  mov      x0, x20
//   0x17b0f8: 2A1F03E5  mov      w5, wzr
//   0x17b0fc: D65F03C0  ret      
static inline uint64_t fde_func_1725_0x17b0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b0f0ULL ^ (static_cast<uint64_t>(0xb9400ae2ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x0955d0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1726 | PC: 0x17b130 | FDE: 0x095630 | Size: 92 bytes
// Khung tháo gỡ #1726 | Địa chỉ PC: 0x17b130 | Địa chỉ FDE: 0x095630 | Kích thước: 92 bytes
//   0x17b130: 11001108  add      w8, w8, #4
//   0x17b134: B9000268  str      w8, [x19]
//   0x17b138: D65F03C0  ret      
//   0x17b13c: B9400268  ldr      w8, [x19]
static inline uint64_t fde_func_1726_0x17b130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b130ULL ^ (static_cast<uint64_t>(0x11001108ULL) << 13);
    acc = (acc + a1 + 0xb9000268ULL) ^ 0x095630ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1727 | PC: 0x17b18c | FDE: 0x095690 | Size: 104 bytes
// Khung tháo gỡ #1727 | Địa chỉ PC: 0x17b18c | Địa chỉ FDE: 0x095690 | Kích thước: 104 bytes
//   0x17b18c: B9400268  ldr      w8, [x19]
//   0x17b190: 8B080AA9  add      x9, x21, x8, lsl #2
//   0x17b194: 11001108  add      w8, w8, #4
//   0x17b198: B9000268  str      w8, [x19]
static inline uint64_t fde_func_1727_0x17b18c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b18cULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x8b080aa9ULL) ^ 0x095690ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1728 | PC: 0x17b1f4 | FDE: 0x0956f0 | Size: 108 bytes
// Khung tháo gỡ #1728 | Địa chỉ PC: 0x17b1f4 | Địa chỉ FDE: 0x0956f0 | Kích thước: 108 bytes
//   0x17b1f4: F9401A68  ldr      x8, [x19, #0x30]
//   0x17b1f8: 5296D589  mov      w9, #0xb6ac
//   0x17b1fc: 52802D8B  mov      w11, #0x16c
//   0x17b200: B8A9690A  ldrsw    x10, [x8, x9]
static inline uint64_t fde_func_1728_0x17b1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b1f4ULL ^ (static_cast<uint64_t>(0xf9401a68ULL) << 13);
    acc = (acc + a1 + 0x5296d589ULL) ^ 0x0956f0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1729 | PC: 0x17b260 | FDE: 0x095750 | Size: 68 bytes
// Khung tháo gỡ #1729 | Địa chỉ PC: 0x17b260 | Địa chỉ FDE: 0x095750 | Kích thước: 68 bytes
//   0x17b260: 910343E0  add      x0, sp, #0xd0
//   0x17b264: 17FE6FAC  b        #0x117114
//   0x17b268: B0FFF5C3  adrp     x3, #0x34000
//   0x17b26c: 9102A463  add      x3, x3, #0xa9
static inline uint64_t fde_func_1729_0x17b260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b260ULL ^ (static_cast<uint64_t>(0x910343e0ULL) << 13);
    acc = (acc + a1 + 0x17fe6facULL) ^ 0x095750ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1730 | PC: 0x17b2a4 | FDE: 0x0957b0 | Size: 128 bytes
// Khung tháo gỡ #1730 | Địa chỉ PC: 0x17b2a4 | Địa chỉ FDE: 0x0957b0 | Kích thước: 128 bytes
//   0x17b2a4: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x17b2a8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x17b2ac: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x17b2b0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1730_0x17b2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b2a4ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0957b0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1731 | PC: 0x17b324 | FDE: 0x095810 | Size: 60 bytes
// Khung tháo gỡ #1731 | Địa chỉ PC: 0x17b324 | Địa chỉ FDE: 0x095810 | Kích thước: 60 bytes
//   0x17b324: 910123E0  add      x0, sp, #0x48
//   0x17b328: 140030A6  b        #0x1875c0
//   0x17b32c: 910123E0  add      x0, sp, #0x48
//   0x17b330: 14003040  b        #0x187430
static inline uint64_t fde_func_1731_0x17b324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b324ULL ^ (static_cast<uint64_t>(0x910123e0ULL) << 13);
    acc = (acc + a1 + 0x140030a6ULL) ^ 0x095810ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1732 | PC: 0x17b360 | FDE: 0x095870 | Size: 80 bytes
// Khung tháo gỡ #1732 | Địa chỉ PC: 0x17b360 | Địa chỉ FDE: 0x095870 | Kích thước: 80 bytes
//   0x17b360: F0FFF5C1  adrp     x1, #0x36000
//   0x17b364: 91350821  add      x1, x1, #0xd42
//   0x17b368: AA1403E0  mov      x0, x20
//   0x17b36c: D65F03C0  ret      
static inline uint64_t fde_func_1732_0x17b360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b360ULL ^ (static_cast<uint64_t>(0xf0fff5c1ULL) << 13);
    acc = (acc + a1 + 0x91350821ULL) ^ 0x095870ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1733 | PC: 0x17b3b0 | FDE: 0x0958d0 | Size: 100 bytes
// Khung tháo gỡ #1733 | Địa chỉ PC: 0x17b3b0 | Địa chỉ FDE: 0x0958d0 | Kích thước: 100 bytes
//   0x17b3b0: D53BD05D  mrs      x29, tpidr_el0
//   0x17b3b4: F94017A8  ldr      x8, [x29, #0x28]
//   0x17b3b8: D65F03C0  ret      
//   0x17b3bc: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_1733_0x17b3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b3b0ULL ^ (static_cast<uint64_t>(0xd53bd05dULL) << 13);
    acc = (acc + a1 + 0xf94017a8ULL) ^ 0x0958d0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1734 | PC: 0x17b414 | FDE: 0x095938 | Size: 92 bytes
// Khung tháo gỡ #1734 | Địa chỉ PC: 0x17b414 | Địa chỉ FDE: 0x095938 | Kích thước: 92 bytes
//   0x17b414: D53BD059  mrs      x25, tpidr_el0
//   0x17b418: F9401728  ldr      x8, [x25, #0x28]
//   0x17b41c: AA0003F7  mov      x23, x0
//   0x17b420: 52800800  mov      w0, #0x40
static inline uint64_t fde_func_1734_0x17b414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b414ULL ^ (static_cast<uint64_t>(0xd53bd059ULL) << 13);
    acc = (acc + a1 + 0xf9401728ULL) ^ 0x095938ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1735 | PC: 0x17b470 | FDE: 0x095998 | Size: 60 bytes
// Khung tháo gỡ #1735 | Địa chỉ PC: 0x17b470 | Địa chỉ FDE: 0x095998 | Kích thước: 60 bytes
//   0x17b470: 52800022  mov      w2, #1
//   0x17b474: AA0003F6  mov      x22, x0
//   0x17b478: 52800034  mov      w20, #1
//   0x17b47c: 14003071  b        #0x187640
static inline uint64_t fde_func_1735_0x17b470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b470ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0xaa0003f6ULL) ^ 0x095998ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1736 | PC: 0x17b4ac | FDE: 0x0959f8 | Size: 44 bytes
// Khung tháo gỡ #1736 | Địa chỉ PC: 0x17b4ac | Địa chỉ FDE: 0x0959f8 | Kích thước: 44 bytes
//   0x17b4ac: 910063E1  add      x1, sp, #0x18
//   0x17b4b0: AA1303E0  mov      x0, x19
//   0x17b4b4: D65F03C0  ret      
//   0x17b4b8: B0FFF5C1  adrp     x1, #0x34000
static inline uint64_t fde_func_1736_0x17b4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b4acULL ^ (static_cast<uint64_t>(0x910063e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x0959f8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1737 | PC: 0x17b4d8 | FDE: 0x095a58 | Size: 64 bytes
// Khung tháo gỡ #1737 | Địa chỉ PC: 0x17b4d8 | Địa chỉ FDE: 0x095a58 | Kích thước: 64 bytes
//   0x17b4d8: 910283E0  add      x0, sp, #0xa0
//   0x17b4dc: 1E200940  fmul     s0, s10, s0
//   0x17b4e0: 1E210961  fmul     s1, s11, s1
//   0x17b4e4: 17FD6477  b        #0xd46c0
static inline uint64_t fde_func_1737_0x17b4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b4d8ULL ^ (static_cast<uint64_t>(0x910283e0ULL) << 13);
    acc = (acc + a1 + 0x1e200940ULL) ^ 0x095a58ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1738 | PC: 0x17b518 | FDE: 0x095ab8 | Size: 56 bytes
// Khung tháo gỡ #1738 | Địa chỉ PC: 0x17b518 | Địa chỉ FDE: 0x095ab8 | Kích thước: 56 bytes
//   0x17b518: 88DFFD08  ldar     w8, [x8]
//   0x17b51c: 93407D01  sxtw     x1, w8
//   0x17b520: D65F03C0  ret      
//   0x17b524: 910503FF  add      sp, sp, #0x140
static inline uint64_t fde_func_1738_0x17b518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b518ULL ^ (static_cast<uint64_t>(0x88dffd08ULL) << 13);
    acc = (acc + a1 + 0x93407d01ULL) ^ 0x095ab8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1739 | PC: 0x17b550 | FDE: 0x095b18 | Size: 100 bytes
// Khung tháo gỡ #1739 | Địa chỉ PC: 0x17b550 | Địa chỉ FDE: 0x095b18 | Kích thước: 100 bytes
//   0x17b550: 3DC00BE0  ldr      q0, [sp, #0x20]
//   0x17b554: 3DC00261  ldr      q1, [x19]
//   0x17b558: 910083E0  add      x0, sp, #0x20
//   0x17b55c: 3D800260  str      q0, [x19]
static inline uint64_t fde_func_1739_0x17b550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b550ULL ^ (static_cast<uint64_t>(0x3dc00be0ULL) << 13);
    acc = (acc + a1 + 0x3dc00261ULL) ^ 0x095b18ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1740 | PC: 0x17b5b4 | FDE: 0x095b78 | Size: 52 bytes
// Khung tháo gỡ #1740 | Địa chỉ PC: 0x17b5b4 | Địa chỉ FDE: 0x095b78 | Kích thước: 52 bytes
//   0x17b5b4: 910063E0  add      x0, sp, #0x18
//   0x17b5b8: 17FCC448  b        #0xac6d8
//   0x17b5bc: 910023F3  add      x19, sp, #8
//   0x17b5c0: 17FCC1A1  b        #0xabc44
static inline uint64_t fde_func_1740_0x17b5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b5b4ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0x17fcc448ULL) ^ 0x095b78ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1741 | PC: 0x17b5e8 | FDE: 0x095bd8 | Size: 116 bytes
// Khung tháo gỡ #1741 | Địa chỉ PC: 0x17b5e8 | Địa chỉ FDE: 0x095bd8 | Kích thước: 116 bytes
//   0x17b5e8: F940B7E9  ldr      x9, [sp, #0x168]
//   0x17b5ec: EB09011F  cmp      x8, x9
//   0x17b5f0: D65F03C0  ret      
//   0x17b5f4: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1741_0x17b5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b5e8ULL ^ (static_cast<uint64_t>(0xf940b7e9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x095bd8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1742 | PC: 0x17b65c | FDE: 0x095c38 | Size: 56 bytes
// Khung tháo gỡ #1742 | Địa chỉ PC: 0x17b65c | Địa chỉ FDE: 0x095c38 | Kích thước: 56 bytes
//   0x17b65c: 2A1F03E2  mov      w2, wzr
//   0x17b660: 2A1F03E3  mov      w3, wzr
//   0x17b664: D65F03C0  ret      
//   0x17b668: AA1303E2  mov      x2, x19
static inline uint64_t fde_func_1742_0x17b65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b65cULL ^ (static_cast<uint64_t>(0x2a1f03e2ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e3ULL) ^ 0x095c38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1743 | PC: 0x17b694 | FDE: 0x095c98 | Size: 76 bytes
// Khung tháo gỡ #1743 | Địa chỉ PC: 0x17b694 | Địa chỉ FDE: 0x095c98 | Kích thước: 76 bytes
//   0x17b694: F9401668  ldr      x8, [x19, #0x28]
//   0x17b698: F9400660  ldr      x0, [x19, #8]
//   0x17b69c: F9400101  ldr      x1, [x8]
//   0x17b6a0: 17FE93BD  b        #0x120594
static inline uint64_t fde_func_1743_0x17b694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b694ULL ^ (static_cast<uint64_t>(0xf9401668ULL) << 13);
    acc = (acc + a1 + 0xf9400660ULL) ^ 0x095c98ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1744 | PC: 0x17b6e0 | FDE: 0x095cf8 | Size: 120 bytes
// Khung tháo gỡ #1744 | Địa chỉ PC: 0x17b6e0 | Địa chỉ FDE: 0x095cf8 | Kích thước: 120 bytes
//   0x17b6e0: D53BD055  mrs      x21, tpidr_el0
//   0x17b6e4: F94016A8  ldr      x8, [x21, #0x28]
//   0x17b6e8: AA0103F3  mov      x19, x1
//   0x17b6ec: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1744_0x17b6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b6e0ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x095cf8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1745 | PC: 0x17b758 | FDE: 0x095d58 | Size: 88 bytes
// Khung tháo gỡ #1745 | Địa chỉ PC: 0x17b758 | Địa chỉ FDE: 0x095d58 | Kích thước: 88 bytes
//   0x17b758: F90007E8  str      x8, [sp, #8]
//   0x17b75c: F9000008  str      x8, [x0]
//   0x17b760: F800C01F  stur     xzr, [x0, #0xc]
//   0x17b764: B9000813  str      w19, [x0, #8]
static inline uint64_t fde_func_1745_0x17b758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b758ULL ^ (static_cast<uint64_t>(0xf90007e8ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x095d58ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1746 | PC: 0x17b7b0 | FDE: 0x095db8 | Size: 56 bytes
// Khung tháo gỡ #1746 | Địa chỉ PC: 0x17b7b0 | Địa chỉ FDE: 0x095db8 | Kích thước: 56 bytes
//   0x17b7b0: F9400668  ldr      x8, [x19, #8]
//   0x17b7b4: 9100C3E0  add      x0, sp, #0x30
//   0x17b7b8: F9001BE8  str      x8, [sp, #0x30]
//   0x17b7bc: D65F03C0  ret      
static inline uint64_t fde_func_1746_0x17b7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b7b0ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0x9100c3e0ULL) ^ 0x095db8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1747 | PC: 0x17b7e8 | FDE: 0x095e18 | Size: 44 bytes
// Khung tháo gỡ #1747 | Địa chỉ PC: 0x17b7e8 | Địa chỉ FDE: 0x095e18 | Kích thước: 44 bytes
//   0x17b7e8: AA1303E0  mov      x0, x19
//   0x17b7ec: 14003439  b        #0x1888d0
//   0x17b7f0: AA1303E0  mov      x0, x19
//   0x17b7f4: 4EA81D00  mov      v0.16b, v8.16b
static inline uint64_t fde_func_1747_0x17b7e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b7e8ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x14003439ULL) ^ 0x095e18ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1748 | PC: 0x17b814 | FDE: 0x095e78 | Size: 40 bytes
// Khung tháo gỡ #1748 | Địa chỉ PC: 0x17b814 | Địa chỉ FDE: 0x095e78 | Kích thước: 40 bytes
//   0x17b814: AA1603E0  mov      x0, x22
//   0x17b818: AA1703E1  mov      x1, x23
//   0x17b81c: D65F03C0  ret      
//   0x17b820: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1748_0x17b814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b814ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0xaa1703e1ULL) ^ 0x095e78ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1749 | PC: 0x17b83c | FDE: 0x095ed8 | Size: 80 bytes
// Khung tháo gỡ #1749 | Địa chỉ PC: 0x17b83c | Địa chỉ FDE: 0x095ed8 | Kích thước: 80 bytes
//   0x17b83c: 910003E0  mov      x0, sp
//   0x17b840: 2A1403E1  mov      w1, w20
//   0x17b844: F90003E8  str      x8, [sp]
//   0x17b848: 17FF5206  b        #0x150060
static inline uint64_t fde_func_1749_0x17b83c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b83cULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0x2a1403e1ULL) ^ 0x095ed8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1750 | PC: 0x17b88c | FDE: 0x095f38 | Size: 112 bytes
// Khung tháo gỡ #1750 | Địa chỉ PC: 0x17b88c | Địa chỉ FDE: 0x095f38 | Kích thước: 112 bytes
//   0x17b88c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17b890: AA0003F3  mov      x19, x0
//   0x17b894: F9400800  ldr      x0, [x0, #0x10]
//   0x17b898: 97FCBF65  bl       #0xab62c
static inline uint64_t fde_func_1750_0x17b88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b88cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x095f38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1751 | PC: 0x17b8fc | FDE: 0x095fa8 | Size: 96 bytes
// Khung tháo gỡ #1751 | Địa chỉ PC: 0x17b8fc | Địa chỉ FDE: 0x095fa8 | Kích thước: 96 bytes
//   0x17b8fc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17b900: AA1403E0  mov      x0, x20
//   0x17b904: AA1803E1  mov      x1, x24
//   0x17b908: AA1703E2  mov      x2, x23
static inline uint64_t fde_func_1751_0x17b8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b8fcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x095fa8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1752 | PC: 0x17b95c | FDE: 0x096018 | Size: 56 bytes
// Khung tháo gỡ #1752 | Địa chỉ PC: 0x17b95c | Địa chỉ FDE: 0x096018 | Kích thước: 56 bytes
//   0x17b95c: AA1503E0  mov      x0, x21
//   0x17b960: 2A1F03E2  mov      w2, wzr
//   0x17b964: D65F03C0  ret      
//   0x17b968: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1752_0x17b95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b95cULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x096018ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1753 | PC: 0x17b994 | FDE: 0x096078 | Size: 64 bytes
// Khung tháo gỡ #1753 | Địa chỉ PC: 0x17b994 | Địa chỉ FDE: 0x096078 | Kích thước: 64 bytes
//   0x17b994: D105C3FF  sub      sp, sp, #0x170
//   0x17b998: A91363FC  stp      x28, x24, [sp, #0x130]
//   0x17b99c: A9145BF7  stp      x23, x22, [sp, #0x140]
//   0x17b9a0: A91553F5  stp      x21, x20, [sp, #0x150]
static inline uint64_t fde_func_1753_0x17b994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b994ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa91363fcULL) ^ 0x096078ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1754 | PC: 0x17b9d4 | FDE: 0x0960d8 | Size: 72 bytes
// Khung tháo gỡ #1754 | Địa chỉ PC: 0x17b9d4 | Địa chỉ FDE: 0x0960d8 | Kích thước: 72 bytes
//   0x17b9d4: 29400AE1  ldp      w1, w2, [x23]
//   0x17b9d8: 294112E3  ldp      w3, w4, [x23, #8]
//   0x17b9dc: 29421AE5  ldp      w5, w6, [x23, #0x10]
//   0x17b9e0: B9401AE7  ldr      w7, [x23, #0x18]
static inline uint64_t fde_func_1754_0x17b9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b9d4ULL ^ (static_cast<uint64_t>(0x29400ae1ULL) << 13);
    acc = (acc + a1 + 0x294112e3ULL) ^ 0x0960d8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1755 | PC: 0x17ba1c | FDE: 0x096138 | Size: 56 bytes
// Khung tháo gỡ #1755 | Địa chỉ PC: 0x17ba1c | Địa chỉ FDE: 0x096138 | Kích thước: 56 bytes
//   0x17ba1c: B00000E0  adrp     x0, #0x198000
//   0x17ba20: 910A6000  add      x0, x0, #0x298
//   0x17ba24: 14002E67  b        #0x1873c0
//   0x17ba28: A94E53F5  ldp      x21, x20, [sp, #0xe0]
static inline uint64_t fde_func_1755_0x17ba1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ba1cULL ^ (static_cast<uint64_t>(0xb00000e0ULL) << 13);
    acc = (acc + a1 + 0x910a6000ULL) ^ 0x096138ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1756 | PC: 0x17ba54 | FDE: 0x096198 | Size: 60 bytes
// Khung tháo gỡ #1756 | Địa chỉ PC: 0x17ba54 | Địa chỉ FDE: 0x096198 | Kích thước: 60 bytes
//   0x17ba54: 5291A800  mov      w0, #0x8d40
//   0x17ba58: 52919C01  mov      w1, #0x8ce0
//   0x17ba5c: 5281BC22  mov      w2, #0xde1
//   0x17ba60: 2A1F03E4  mov      w4, wzr
static inline uint64_t fde_func_1756_0x17ba54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ba54ULL ^ (static_cast<uint64_t>(0x5291a800ULL) << 13);
    acc = (acc + a1 + 0x52919c01ULL) ^ 0x096198ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1757 | PC: 0x17ba90 | FDE: 0x0961f8 | Size: 56 bytes
// Khung tháo gỡ #1757 | Địa chỉ PC: 0x17ba90 | Địa chỉ FDE: 0x0961f8 | Kích thước: 56 bytes
//   0x17ba90: 91220821  add      x1, x1, #0x882
//   0x17ba94: 910023E0  add      x0, sp, #8
//   0x17ba98: D65F03C0  ret      
//   0x17ba9c: F9408FE9  ldr      x9, [sp, #0x118]
static inline uint64_t fde_func_1757_0x17ba90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ba90ULL ^ (static_cast<uint64_t>(0x91220821ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x0961f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1758 | PC: 0x17bac8 | FDE: 0x096258 | Size: 60 bytes
// Khung tháo gỡ #1758 | Địa chỉ PC: 0x17bac8 | Địa chỉ FDE: 0x096258 | Kích thước: 60 bytes
//   0x17bac8: F940C7E9  ldr      x9, [sp, #0x188]
//   0x17bacc: EB09011F  cmp      x8, x9
//   0x17bad0: D65F03C0  ret      
//   0x17bad4: 2A1503E1  mov      w1, w21
static inline uint64_t fde_func_1758_0x17bac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bac8ULL ^ (static_cast<uint64_t>(0xf940c7e9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x096258ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1759 | PC: 0x17bb04 | FDE: 0x0962b8 | Size: 88 bytes
// Khung tháo gỡ #1759 | Địa chỉ PC: 0x17bb04 | Địa chỉ FDE: 0x0962b8 | Kích thước: 88 bytes
//   0x17bb04: 2A1603E2  mov      w2, w22
//   0x17bb08: 2A1503E3  mov      w3, w21
//   0x17bb0c: 17FE2D5B  b        #0x107078
//   0x17bb10: F1000FBF  cmp      x29, #3
static inline uint64_t fde_func_1759_0x17bb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bb04ULL ^ (static_cast<uint64_t>(0x2a1603e2ULL) << 13);
    acc = (acc + a1 + 0x2a1503e3ULL) ^ 0x0962b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1760 | PC: 0x17bb5c | FDE: 0x096318 | Size: 128 bytes
// Khung tháo gỡ #1760 | Địa chỉ PC: 0x17bb5c | Địa chỉ FDE: 0x096318 | Kích thước: 128 bytes
//   0x17bb5c: AB284AA8  adds     x8, x21, w8, uxtw #2
//   0x17bb60: B910CBFF  str      wzr, [sp, #0x10c8]
//   0x17bb64: F90863E8  str      x8, [sp, #0x10c0]
//   0x17bb68: F9086BF8  str      x24, [sp, #0x10d0]
static inline uint64_t fde_func_1760_0x17bb5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bb5cULL ^ (static_cast<uint64_t>(0xab284aa8ULL) << 13);
    acc = (acc + a1 + 0xb910cbffULL) ^ 0x096318ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1761 | PC: 0x17bbdc | FDE: 0x096378 | Size: 48 bytes
// Khung tháo gỡ #1761 | Địa chỉ PC: 0x17bbdc | Địa chỉ FDE: 0x096378 | Kích thước: 48 bytes
//   0x17bbdc: 52817822  mov      w2, #0xbc1
//   0x17bbe0: AA1603E0  mov      x0, x22
//   0x17bbe4: 17FF2ABB  b        #0x1466d0
//   0x17bbe8: D0FFF5E1  adrp     x1, #0x39000
static inline uint64_t fde_func_1761_0x17bbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbdcULL ^ (static_cast<uint64_t>(0x52817822ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x096378ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1762 | PC: 0x17bc0c | FDE: 0x0963d8 | Size: 152 bytes
// Khung tháo gỡ #1762 | Địa chỉ PC: 0x17bc0c | Địa chỉ FDE: 0x0963d8 | Kích thước: 152 bytes
//   0x17bc0c: A900FC3F  stp      xzr, xzr, [x1, #8]
//   0x17bc10: F900003F  str      xzr, [x1]
//   0x17bc14: 2900FC02  stp      w2, wzr, [x0, #4]
//   0x17bc18: B9000009  str      w9, [x0]
static inline uint64_t fde_func_1762_0x17bc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bc0cULL ^ (static_cast<uint64_t>(0xa900fc3fULL) << 13);
    acc = (acc + a1 + 0xf900003fULL) ^ 0x0963d8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1763 | PC: 0x17bca4 | FDE: 0x096438 | Size: 56 bytes
// Khung tháo gỡ #1763 | Địa chỉ PC: 0x17bca4 | Địa chỉ FDE: 0x096438 | Kích thước: 56 bytes
//   0x17bca4: 91277C21  add      x1, x1, #0x9df
//   0x17bca8: 910023E0  add      x0, sp, #8
//   0x17bcac: D65F03C0  ret      
//   0x17bcb0: 52817722  mov      w2, #0xbb9
static inline uint64_t fde_func_1763_0x17bca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bca4ULL ^ (static_cast<uint64_t>(0x91277c21ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x096438ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1764 | PC: 0x17bcdc | FDE: 0x096498 | Size: 72 bytes
// Khung tháo gỡ #1764 | Địa chỉ PC: 0x17bcdc | Địa chỉ FDE: 0x096498 | Kích thước: 72 bytes
//   0x17bcdc: A94A4FF4  ldp      x20, x19, [sp, #0xa0]
//   0x17bce0: A94957F6  ldp      x22, x21, [sp, #0x90]
//   0x17bce4: A9485FF8  ldp      x24, x23, [sp, #0x80]
//   0x17bce8: A94767FA  ldp      x26, x25, [sp, #0x70]
static inline uint64_t fde_func_1764_0x17bcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bcdcULL ^ (static_cast<uint64_t>(0xa94a4ff4ULL) << 13);
    acc = (acc + a1 + 0xa94957f6ULL) ^ 0x096498ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1765 | PC: 0x17bd24 | FDE: 0x0964f8 | Size: 76 bytes
// Khung tháo gỡ #1765 | Địa chỉ PC: 0x17bd24 | Địa chỉ FDE: 0x0964f8 | Kích thước: 76 bytes
//   0x17bd24: F9401028  ldr      x8, [x1, #0x20]
//   0x17bd28: F100291F  cmp      x8, #0xa
//   0x17bd2c: 9A893109  csel     x9, x8, x9, lo
//   0x17bd30: F100293F  cmp      x9, #0xa
static inline uint64_t fde_func_1765_0x17bd24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bd24ULL ^ (static_cast<uint64_t>(0xf9401028ULL) << 13);
    acc = (acc + a1 + 0xf100291fULL) ^ 0x0964f8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1766 | PC: 0x17bd70 | FDE: 0x096558 | Size: 92 bytes
// Khung tháo gỡ #1766 | Địa chỉ PC: 0x17bd70 | Địa chỉ FDE: 0x096558 | Kích thước: 92 bytes
//   0x17bd70: 5291A820  mov      w0, #0x8d41
//   0x17bd74: 1400344B  b        #0x188ea0
//   0x17bd78: B900081F  str      wzr, [x0, #8]
//   0x17bd7c: B900181F  str      wzr, [x0, #0x18]
static inline uint64_t fde_func_1766_0x17bd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bd70ULL ^ (static_cast<uint64_t>(0x5291a820ULL) << 13);
    acc = (acc + a1 + 0x1400344bULL) ^ 0x096558ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1767 | PC: 0x17bdcc | FDE: 0x0965b8 | Size: 44 bytes
// Khung tháo gỡ #1767 | Địa chỉ PC: 0x17bdcc | Địa chỉ FDE: 0x0965b8 | Kích thước: 44 bytes
//   0x17bdcc: AA1903E1  mov      x1, x25
//   0x17bdd0: 17FCB2C9  b        #0xa88f4
//   0x17bdd4: 2A0003FB  mov      w27, w0
//   0x17bdd8: 910103E0  add      x0, sp, #0x40
static inline uint64_t fde_func_1767_0x17bdcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bdccULL ^ (static_cast<uint64_t>(0xaa1903e1ULL) << 13);
    acc = (acc + a1 + 0x17fcb2c9ULL) ^ 0x0965b8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1768 | PC: 0x17bdf8 | FDE: 0x096618 | Size: 72 bytes
// Khung tháo gỡ #1768 | Địa chỉ PC: 0x17bdf8 | Địa chỉ FDE: 0x096618 | Kích thước: 72 bytes
//   0x17bdf8: B940BBFD  ldr      w29, [sp, #0xb8]
//   0x17bdfc: F9405BFC  ldr      x28, [sp, #0xb0]
//   0x17be00: F9401FE4  ldr      x4, [sp, #0x38]
//   0x17be04: F0FFF5C1  adrp     x1, #0x36000
static inline uint64_t fde_func_1768_0x17bdf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bdf8ULL ^ (static_cast<uint64_t>(0xb940bbfdULL) << 13);
    acc = (acc + a1 + 0xf9405bfcULL) ^ 0x096618ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1769 | PC: 0x17be40 | FDE: 0x096678 | Size: 80 bytes
// Khung tháo gỡ #1769 | Địa chỉ PC: 0x17be40 | Địa chỉ FDE: 0x096678 | Kích thước: 80 bytes
//   0x17be40: D100068C  sub      x12, x20, #1
//   0x17be44: 8A0C014A  and      x10, x10, x12
//   0x17be48: D65F03C0  ret      
//   0x17be4c: 9AD4094C  udiv     x12, x10, x20
static inline uint64_t fde_func_1769_0x17be40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17be40ULL ^ (static_cast<uint64_t>(0xd100068cULL) << 13);
    acc = (acc + a1 + 0x8a0c014aULL) ^ 0x096678ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1770 | PC: 0x17be90 | FDE: 0x0966d8 | Size: 72 bytes
// Khung tháo gỡ #1770 | Địa chỉ PC: 0x17be90 | Địa chỉ FDE: 0x0966d8 | Kích thước: 72 bytes
//   0x17be90: F9400288  ldr      x8, [x20]
//   0x17be94: 394003E9  ldrb     w9, [sp]
//   0x17be98: F9400BEA  ldr      x10, [sp, #0x10]
//   0x17be9c: B24002CB  orr      x11, x22, #1
static inline uint64_t fde_func_1770_0x17be90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17be90ULL ^ (static_cast<uint64_t>(0xf9400288ULL) << 13);
    acc = (acc + a1 + 0x394003e9ULL) ^ 0x0966d8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1771 | PC: 0x17bed8 | FDE: 0x096738 | Size: 48 bytes
// Khung tháo gỡ #1771 | Địa chỉ PC: 0x17bed8 | Địa chỉ FDE: 0x096738 | Kích thước: 48 bytes
//   0x17bed8: F83B7916  str      x22, [x8, x27, lsl #3]
//   0x17bedc: AA1B03F8  mov      x24, x27
//   0x17bee0: D65F03C0  ret      
//   0x17bee4: AA1D03FC  mov      x28, x29
static inline uint64_t fde_func_1771_0x17bed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bed8ULL ^ (static_cast<uint64_t>(0xf83b7916ULL) << 13);
    acc = (acc + a1 + 0xaa1b03f8ULL) ^ 0x096738ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1772 | PC: 0x17bf08 | FDE: 0x096798 | Size: 80 bytes
// Khung tháo gỡ #1772 | Địa chỉ PC: 0x17bf08 | Địa chỉ FDE: 0x096798 | Kích thước: 80 bytes
//   0x17bf08: 52800281  mov      w1, #0x14
//   0x17bf0c: AA1603E0  mov      x0, x22
//   0x17bf10: 2A0303F3  mov      w19, w3
//   0x17bf14: 2A0203F4  mov      w20, w2
static inline uint64_t fde_func_1772_0x17bf08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bf08ULL ^ (static_cast<uint64_t>(0x52800281ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x096798ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1773 | PC: 0x17bf58 | FDE: 0x0967f8 | Size: 68 bytes
// Khung tháo gỡ #1773 | Địa chỉ PC: 0x17bf58 | Địa chỉ FDE: 0x0967f8 | Kích thước: 68 bytes
//   0x17bf58: 9100E3E0  add      x0, sp, #0x38
//   0x17bf5c: 14003699  b        #0x1899c0
//   0x17bf60: F9000009  str      x9, [x0]
//   0x17bf64: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1773_0x17bf58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bf58ULL ^ (static_cast<uint64_t>(0x9100e3e0ULL) << 13);
    acc = (acc + a1 + 0x14003699ULL) ^ 0x0967f8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1774 | PC: 0x17bf9c | FDE: 0x096858 | Size: 36 bytes
// Khung tháo gỡ #1774 | Địa chỉ PC: 0x17bf9c | Địa chỉ FDE: 0x096858 | Kích thước: 36 bytes
//   0x17bf9c: 910483FF  add      sp, sp, #0x120
//   0x17bfa0: D65F03C0  ret      
//   0x17bfa4: 529194C1  mov      w1, #0x8ca6
//   0x17bfa8: 17FDB5BB  b        #0xe9694
static inline uint64_t fde_func_1774_0x17bf9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bf9cULL ^ (static_cast<uint64_t>(0x910483ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x096858ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1775 | PC: 0x17bfc0 | FDE: 0x0968b8 | Size: 40 bytes
// Khung tháo gỡ #1775 | Địa chỉ PC: 0x17bfc0 | Địa chỉ FDE: 0x0968b8 | Kích thước: 40 bytes
//   0x17bfc0: AA1F03E4  mov      x4, xzr
//   0x17bfc4: 17FF5AFC  b        #0x152bb4
//   0x17bfc8: F94067E9  ldr      x9, [sp, #0xc8]
//   0x17bfcc: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1775_0x17bfc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bfc0ULL ^ (static_cast<uint64_t>(0xaa1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17ff5afcULL) ^ 0x0968b8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1776 | PC: 0x17bfe8 | FDE: 0x096918 | Size: 76 bytes
// Khung tháo gỡ #1776 | Địa chỉ PC: 0x17bfe8 | Địa chỉ FDE: 0x096918 | Kích thước: 76 bytes
//   0x17bfe8: 910103E0  add      x0, sp, #0x40
//   0x17bfec: 14002D3D  b        #0x1874e0
//   0x17bff0: A90407E0  stp      x0, x1, [sp, #0x40]
//   0x17bff4: 910103E0  add      x0, sp, #0x40
static inline uint64_t fde_func_1776_0x17bfe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bfe8ULL ^ (static_cast<uint64_t>(0x910103e0ULL) << 13);
    acc = (acc + a1 + 0x14002d3dULL) ^ 0x096918ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1777 | PC: 0x17c034 | FDE: 0x096978 | Size: 68 bytes
// Khung tháo gỡ #1777 | Địa chỉ PC: 0x17c034 | Địa chỉ FDE: 0x096978 | Kích thước: 68 bytes
//   0x17c034: AA1B03E0  mov      x0, x27
//   0x17c038: 17FDA4FF  b        #0xe5434
//   0x17c03c: F940CFE9  ldr      x9, [sp, #0x198]
//   0x17c040: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1777_0x17c034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c034ULL ^ (static_cast<uint64_t>(0xaa1b03e0ULL) << 13);
    acc = (acc + a1 + 0x17fda4ffULL) ^ 0x096978ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1778 | PC: 0x17c078 | FDE: 0x0969d8 | Size: 72 bytes
// Khung tháo gỡ #1778 | Địa chỉ PC: 0x17c078 | Địa chỉ FDE: 0x0969d8 | Kích thước: 72 bytes
//   0x17c078: F9400414  ldr      x20, [x0, #8]
//   0x17c07c: CB010042  sub      x2, x2, x1
//   0x17c080: AA0003F3  mov      x19, x0
//   0x17c084: F100045F  cmp      x2, #1
static inline uint64_t fde_func_1778_0x17c078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c078ULL ^ (static_cast<uint64_t>(0xf9400414ULL) << 13);
    acc = (acc + a1 + 0xcb010042ULL) ^ 0x0969d8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1779 | PC: 0x17c0c0 | FDE: 0x096a38 | Size: 56 bytes
// Khung tháo gỡ #1779 | Địa chỉ PC: 0x17c0c0 | Địa chỉ FDE: 0x096a38 | Kích thước: 56 bytes
//   0x17c0c0: A90087E0  stp      x0, x1, [sp, #8]
//   0x17c0c4: 910023E0  add      x0, sp, #8
//   0x17c0c8: D65F03C0  ret      
//   0x17c0cc: 910063E0  add      x0, sp, #0x18
static inline uint64_t fde_func_1779_0x17c0c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c0c0ULL ^ (static_cast<uint64_t>(0xa90087e0ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x096a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1780 | PC: 0x17c0f8 | FDE: 0x096a98 | Size: 64 bytes
// Khung tháo gỡ #1780 | Địa chỉ PC: 0x17c0f8 | Địa chỉ FDE: 0x096a98 | Kích thước: 64 bytes
//   0x17c0f8: 910003E1  mov      x1, sp
//   0x17c0fc: 52800042  mov      w2, #2
//   0x17c100: F90007E9  str      x9, [sp, #8]
//   0x17c104: FD0003E0  str      d0, [sp]
static inline uint64_t fde_func_1780_0x17c0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c0f8ULL ^ (static_cast<uint64_t>(0x910003e1ULL) << 13);
    acc = (acc + a1 + 0x52800042ULL) ^ 0x096a98ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1781 | PC: 0x17c138 | FDE: 0x096af8 | Size: 52 bytes
// Khung tháo gỡ #1781 | Địa chỉ PC: 0x17c138 | Địa chỉ FDE: 0x096af8 | Kích thước: 52 bytes
//   0x17c138: A94687E0  ldp      x0, x1, [sp, #0x68]
//   0x17c13c: 17FF5024  b        #0x1501cc
//   0x17c140: A94353F5  ldp      x21, x20, [sp, #0x30]
//   0x17c144: A9425BF7  ldp      x23, x22, [sp, #0x20]
static inline uint64_t fde_func_1781_0x17c138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c138ULL ^ (static_cast<uint64_t>(0xa94687e0ULL) << 13);
    acc = (acc + a1 + 0x17ff5024ULL) ^ 0x096af8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1782 | PC: 0x17c16c | FDE: 0x096b58 | Size: 116 bytes
// Khung tháo gỡ #1782 | Địa chỉ PC: 0x17c16c | Địa chỉ FDE: 0x096b58 | Kích thước: 116 bytes
//   0x17c16c: D53BD055  mrs      x21, tpidr_el0
//   0x17c170: F94016A8  ldr      x8, [x21, #0x28]
//   0x17c174: 52800049  mov      w9, #2
//   0x17c178: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1782_0x17c16c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c16cULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x096b58ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1783 | PC: 0x17c1e0 | FDE: 0x096bb8 | Size: 72 bytes
// Khung tháo gỡ #1783 | Địa chỉ PC: 0x17c1e0 | Địa chỉ FDE: 0x096bb8 | Kích thước: 72 bytes
//   0x17c1e0: 2A1F03E1  mov      w1, wzr
//   0x17c1e4: 17FF4FC2  b        #0x1500ec
//   0x17c1e8: D53BD056  mrs      x22, tpidr_el0
//   0x17c1ec: F94016C8  ldr      x8, [x22, #0x28]
static inline uint64_t fde_func_1783_0x17c1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c1e0ULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17ff4fc2ULL) ^ 0x096bb8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1784 | PC: 0x17c228 | FDE: 0x096c18 | Size: 68 bytes
// Khung tháo gỡ #1784 | Địa chỉ PC: 0x17c228 | Địa chỉ FDE: 0x096c18 | Kích thước: 68 bytes
//   0x17c228: 2A1303E1  mov      w1, w19
//   0x17c22c: 17FF28D4  b        #0x14657c
//   0x17c230: F90007E8  str      x8, [sp, #8]
//   0x17c234: A9007C08  stp      x8, xzr, [x0]
static inline uint64_t fde_func_1784_0x17c228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c228ULL ^ (static_cast<uint64_t>(0x2a1303e1ULL) << 13);
    acc = (acc + a1 + 0x17ff28d4ULL) ^ 0x096c18ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1785 | PC: 0x17c26c | FDE: 0x096c78 | Size: 56 bytes
// Khung tháo gỡ #1785 | Địa chỉ PC: 0x17c26c | Địa chỉ FDE: 0x096c78 | Kích thước: 56 bytes
//   0x17c26c: 52800021  mov      w1, #1
//   0x17c270: 52800402  mov      w2, #0x20
//   0x17c274: 17FE4BC8  b        #0x10f194
//   0x17c278: 52800021  mov      w1, #1
static inline uint64_t fde_func_1785_0x17c26c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c26cULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x52800402ULL) ^ 0x096c78ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1786 | PC: 0x17c2a4 | FDE: 0x096cd8 | Size: 44 bytes
// Khung tháo gỡ #1786 | Địa chỉ PC: 0x17c2a4 | Địa chỉ FDE: 0x096cd8 | Kích thước: 44 bytes
//   0x17c2a4: AA1303E0  mov      x0, x19
//   0x17c2a8: 17FF525F  b        #0x150c24
//   0x17c2ac: AA1303E0  mov      x0, x19
//   0x17c2b0: AA1603E2  mov      x2, x22
static inline uint64_t fde_func_1786_0x17c2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c2a4ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17ff525fULL) ^ 0x096cd8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1787 | PC: 0x17c2d0 | FDE: 0x096d38 | Size: 48 bytes
// Khung tháo gỡ #1787 | Địa chỉ PC: 0x17c2d0 | Địa chỉ FDE: 0x096d38 | Kích thước: 48 bytes
//   0x17c2d0: AA1303E0  mov      x0, x19
//   0x17c2d4: AA1403E2  mov      x2, x20
//   0x17c2d8: 17FF634C  b        #0x155008
//   0x17c2dc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1787_0x17c2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c2d0ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e2ULL) ^ 0x096d38ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1788 | PC: 0x17c300 | FDE: 0x096d98 | Size: 44 bytes
// Khung tháo gỡ #1788 | Địa chỉ PC: 0x17c300 | Địa chỉ FDE: 0x096d98 | Kích thước: 44 bytes
//   0x17c300: AA1603E0  mov      x0, x22
//   0x17c304: AA1403E1  mov      x1, x20
//   0x17c308: 17FEB40D  b        #0x12933c
//   0x17c30c: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1788_0x17c300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c300ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x096d98ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1789 | PC: 0x17c32c | FDE: 0x096df8 | Size: 56 bytes
// Khung tháo gỡ #1789 | Địa chỉ PC: 0x17c32c | Địa chỉ FDE: 0x096df8 | Kích thước: 56 bytes
//   0x17c32c: 910043E0  add      x0, sp, #0x10
//   0x17c330: F9000BE8  str      x8, [sp, #0x10]
//   0x17c334: 17FF4B68  b        #0x14f0d4
//   0x17c338: B94006E3  ldr      w3, [x23, #4]
static inline uint64_t fde_func_1789_0x17c32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c32cULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0xf9000be8ULL) ^ 0x096df8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1790 | PC: 0x17c364 | FDE: 0x096e58 | Size: 80 bytes
// Khung tháo gỡ #1790 | Địa chỉ PC: 0x17c364 | Địa chỉ FDE: 0x096e58 | Kích thước: 80 bytes
//   0x17c364: AA0003F3  mov      x19, x0
//   0x17c368: D10C0109  sub      x9, x8, #0x300
//   0x17c36c: 3DC00123  ldr      q3, [x9]
//   0x17c370: D10B4109  sub      x9, x8, #0x2d0
static inline uint64_t fde_func_1790_0x17c364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c364ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xd10c0109ULL) ^ 0x096e58ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1791 | PC: 0x17c3b4 | FDE: 0x096eb8 | Size: 44 bytes
// Khung tháo gỡ #1791 | Địa chỉ PC: 0x17c3b4 | Địa chỉ FDE: 0x096eb8 | Kích thước: 44 bytes
//   0x17c3b4: AA0003F3  mov      x19, x0
//   0x17c3b8: F9400800  ldr      x0, [x0, #0x10]
//   0x17c3bc: D65F03C0  ret      
//   0x17c3c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1791_0x17c3b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c3b4ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xf9400800ULL) ^ 0x096eb8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1792 | PC: 0x17c3e0 | FDE: 0x096f18 | Size: 40 bytes
// Khung tháo gỡ #1792 | Địa chỉ PC: 0x17c3e0 | Địa chỉ FDE: 0x096f18 | Kích thước: 40 bytes
//   0x17c3e0: AA0003E2  mov      x2, x0
//   0x17c3e4: AA1303E0  mov      x0, x19
//   0x17c3e8: D65F03C0  ret      
//   0x17c3ec: AA1403E1  mov      x1, x20
static inline uint64_t fde_func_1792_0x17c3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c3e0ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x096f18ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1793 | PC: 0x17c408 | FDE: 0x096f78 | Size: 44 bytes
// Khung tháo gỡ #1793 | Địa chỉ PC: 0x17c408 | Địa chỉ FDE: 0x096f78 | Kích thước: 44 bytes
//   0x17c408: 910023E0  add      x0, sp, #8
//   0x17c40c: F90007E8  str      x8, [sp, #8]
//   0x17c410: 17FF4B31  b        #0x14f0d4
//   0x17c414: 910023E0  add      x0, sp, #8
static inline uint64_t fde_func_1793_0x17c408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c408ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0xf90007e8ULL) ^ 0x096f78ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1794 | PC: 0x17c434 | FDE: 0x096fd8 | Size: 64 bytes
// Khung tháo gỡ #1794 | Địa chỉ PC: 0x17c434 | Địa chỉ FDE: 0x096fd8 | Kích thước: 64 bytes
//   0x17c434: 2A1F03E6  mov      w6, wzr
//   0x17c438: 2A1F03E7  mov      w7, wzr
//   0x17c43c: D65F03C0  ret      
//   0x17c440: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1794_0x17c434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c434ULL ^ (static_cast<uint64_t>(0x2a1f03e6ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e7ULL) ^ 0x096fd8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1795 | PC: 0x17c474 | FDE: 0x097038 | Size: 60 bytes
// Khung tháo gỡ #1795 | Địa chỉ PC: 0x17c474 | Địa chỉ FDE: 0x097038 | Kích thước: 60 bytes
//   0x17c474: 53081D29  lsl      w9, w9, #0x18
//   0x17c478: 93407D29  sxtw     x9, w9
//   0x17c47c: B3701D49  bfi      x9, x10, #0x10, #8
//   0x17c480: B3781D69  bfi      x9, x11, #8, #8
static inline uint64_t fde_func_1795_0x17c474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c474ULL ^ (static_cast<uint64_t>(0x53081d29ULL) << 13);
    acc = (acc + a1 + 0x93407d29ULL) ^ 0x097038ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1796 | PC: 0x17c4b0 | FDE: 0x097098 | Size: 120 bytes
// Khung tháo gỡ #1796 | Địa chỉ PC: 0x17c4b0 | Địa chỉ FDE: 0x097098 | Kích thước: 120 bytes
//   0x17c4b0: 1E200821  fmul     s1, s1, s0
//   0x17c4b4: 1E200842  fmul     s2, s2, s0
//   0x17c4b8: 1E200863  fmul     s3, s3, s0
//   0x17c4bc: 1E200900  fmul     s0, s8, s0
static inline uint64_t fde_func_1796_0x17c4b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c4b0ULL ^ (static_cast<uint64_t>(0x1e200821ULL) << 13);
    acc = (acc + a1 + 0x1e200842ULL) ^ 0x097098ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1797 | PC: 0x17c528 | FDE: 0x0970f8 | Size: 88 bytes
// Khung tháo gỡ #1797 | Địa chỉ PC: 0x17c528 | Địa chỉ FDE: 0x0970f8 | Kích thước: 88 bytes
//   0x17c528: B9800B6A  ldrsw    x10, [x27, #8]
//   0x17c52c: B9804BE8  ldrsw    x8, [sp, #0x48]
//   0x17c530: 51000529  sub      w9, w9, #1
//   0x17c534: 8B0A02F7  add      x23, x23, x10
static inline uint64_t fde_func_1797_0x17c528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c528ULL ^ (static_cast<uint64_t>(0xb9800b6aULL) << 13);
    acc = (acc + a1 + 0xb9804be8ULL) ^ 0x0970f8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1798 | PC: 0x17c580 | FDE: 0x097158 | Size: 56 bytes
// Khung tháo gỡ #1798 | Địa chỉ PC: 0x17c580 | Địa chỉ FDE: 0x097158 | Kích thước: 56 bytes
//   0x17c580: 29400408  ldp      w8, w1, [x0]
//   0x17c584: 29410C02  ldp      w2, w3, [x0, #8]
//   0x17c588: 2A0803E0  mov      w0, w8
//   0x17c58c: D65F03C0  ret      
static inline uint64_t fde_func_1798_0x17c580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c580ULL ^ (static_cast<uint64_t>(0x29400408ULL) << 13);
    acc = (acc + a1 + 0x29410c02ULL) ^ 0x097158ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1799 | PC: 0x17c5b8 | FDE: 0x0971b8 | Size: 76 bytes
// Khung tháo gỡ #1799 | Địa chỉ PC: 0x17c5b8 | Địa chỉ FDE: 0x0971b8 | Kích thước: 76 bytes
//   0x17c5b8: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x17c5bc: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x17c5c0: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x17c5c4: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1799_0x17c5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c5b8ULL ^ (static_cast<uint64_t>(0xa9036bfbULL) << 13);
    acc = (acc + a1 + 0xa90463f9ULL) ^ 0x0971b8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1800 | PC: 0x17c604 | FDE: 0x097218 | Size: 64 bytes
// Khung tháo gỡ #1800 | Địa chỉ PC: 0x17c604 | Địa chỉ FDE: 0x097218 | Kích thước: 64 bytes
//   0x17c604: 9102C3E0  add      x0, sp, #0xb0
//   0x17c608: 14002BB6  b        #0x1874e0
//   0x17c60c: F90457FF  str      xzr, [sp, #0x8a8]
//   0x17c610: F90453FF  str      xzr, [sp, #0x8a0]
static inline uint64_t fde_func_1800_0x17c604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c604ULL ^ (static_cast<uint64_t>(0x9102c3e0ULL) << 13);
    acc = (acc + a1 + 0x14002bb6ULL) ^ 0x097218ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1801 | PC: 0x17c644 | FDE: 0x097278 | Size: 112 bytes
// Khung tháo gỡ #1801 | Địa chỉ PC: 0x17c644 | Địa chỉ FDE: 0x097278 | Kích thước: 112 bytes
//   0x17c644: 29400AC1  ldp      w1, w2, [x22]
//   0x17c648: 294112C3  ldp      w3, w4, [x22, #8]
//   0x17c64c: 29421AC5  ldp      w5, w6, [x22, #0x10]
//   0x17c650: 294322C7  ldp      w7, w8, [x22, #0x18]
static inline uint64_t fde_func_1801_0x17c644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c644ULL ^ (static_cast<uint64_t>(0x29400ac1ULL) << 13);
    acc = (acc + a1 + 0x294112c3ULL) ^ 0x097278ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1802 | PC: 0x17c6b4 | FDE: 0x0972d8 | Size: 136 bytes
// Khung tháo gỡ #1802 | Địa chỉ PC: 0x17c6b4 | Địa chỉ FDE: 0x0972d8 | Kích thước: 136 bytes
//   0x17c6b4: B9400268  ldr      w8, [x19]
//   0x17c6b8: 52817722  mov      w2, #0xbb9
//   0x17c6bc: 8B080AB5  add      x21, x21, x8, lsl #2
//   0x17c6c0: D65F03C0  ret      
static inline uint64_t fde_func_1802_0x17c6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c6b4ULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x52817722ULL) ^ 0x0972d8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1803 | PC: 0x17c73c | FDE: 0x097338 | Size: 112 bytes
// Khung tháo gỡ #1803 | Địa chỉ PC: 0x17c73c | Địa chỉ FDE: 0x097338 | Kích thước: 112 bytes
//   0x17c73c: 90FFF5C1  adrp     x1, #0x34000
//   0x17c740: 9127C021  add      x1, x1, #0x9f0
//   0x17c744: 910483E0  add      x0, sp, #0x120
//   0x17c748: D65F03C0  ret      
static inline uint64_t fde_func_1803_0x17c73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c73cULL ^ (static_cast<uint64_t>(0x90fff5c1ULL) << 13);
    acc = (acc + a1 + 0x9127c021ULL) ^ 0x097338ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1804 | PC: 0x17c7ac | FDE: 0x097398 | Size: 104 bytes
// Khung tháo gỡ #1804 | Địa chỉ PC: 0x17c7ac | Địa chỉ FDE: 0x097398 | Kích thước: 104 bytes
//   0x17c7ac: F94017E3  ldr      x3, [sp, #0x28]
//   0x17c7b0: F942EA80  ldr      x0, [x20, #0x5d0]
//   0x17c7b4: AA1303E1  mov      x1, x19
//   0x17c7b8: 0B020448  add      w8, w2, w2, lsl #1
static inline uint64_t fde_func_1804_0x17c7ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c7acULL ^ (static_cast<uint64_t>(0xf94017e3ULL) << 13);
    acc = (acc + a1 + 0xf942ea80ULL) ^ 0x097398ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1805 | PC: 0x17c814 | FDE: 0x097400 | Size: 88 bytes
// Khung tháo gỡ #1805 | Địa chỉ PC: 0x17c814 | Địa chỉ FDE: 0x097400 | Kích thước: 88 bytes
//   0x17c814: B9401E85  ldr      w5, [x20, #0x1c]
//   0x17c818: 910103E0  add      x0, sp, #0x40
//   0x17c81c: 52800026  mov      w6, #1
//   0x17c820: AA1503E1  mov      x1, x21
static inline uint64_t fde_func_1805_0x17c814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c814ULL ^ (static_cast<uint64_t>(0xb9401e85ULL) << 13);
    acc = (acc + a1 + 0x910103e0ULL) ^ 0x097400ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1806 | PC: 0x17c86c | FDE: 0x097460 | Size: 92 bytes
// Khung tháo gỡ #1806 | Địa chỉ PC: 0x17c86c | Địa chỉ FDE: 0x097460 | Kích thước: 92 bytes
//   0x17c86c: D0FFF5C1  adrp     x1, #0x36000
//   0x17c870: 912F9421  add      x1, x1, #0xbe5
//   0x17c874: AA1A03E0  mov      x0, x26
//   0x17c878: AA1B03E2  mov      x2, x27
static inline uint64_t fde_func_1806_0x17c86c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c86cULL ^ (static_cast<uint64_t>(0xd0fff5c1ULL) << 13);
    acc = (acc + a1 + 0x912f9421ULL) ^ 0x097460ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1807 | PC: 0x17c8c8 | FDE: 0x0974c0 | Size: 92 bytes
// Khung tháo gỡ #1807 | Địa chỉ PC: 0x17c8c8 | Địa chỉ FDE: 0x0974c0 | Kích thước: 92 bytes
//   0x17c8c8: 8B88FD08  add      x8, x8, x8, asr #63
//   0x17c8cc: 91402108  add      x8, x8, #8, lsl #12
//   0x17c8d0: D65F03C0  ret      
//   0x17c8d4: 8B88FD08  add      x8, x8, x8, asr #63
static inline uint64_t fde_func_1807_0x17c8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c8c8ULL ^ (static_cast<uint64_t>(0x8b88fd08ULL) << 13);
    acc = (acc + a1 + 0x91402108ULL) ^ 0x0974c0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1808 | PC: 0x17c924 | FDE: 0x097520 | Size: 60 bytes
// Khung tháo gỡ #1808 | Địa chỉ PC: 0x17c924 | Địa chỉ FDE: 0x097520 | Kích thước: 60 bytes
//   0x17c924: F940BFE9  ldr      x9, [sp, #0x178]
//   0x17c928: EB09011F  cmp      x8, x9
//   0x17c92c: D65F03C0  ret      
//   0x17c930: 52801300  mov      w0, #0x98
static inline uint64_t fde_func_1808_0x17c924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c924ULL ^ (static_cast<uint64_t>(0xf940bfe9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x097520ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1809 | PC: 0x17c960 | FDE: 0x097580 | Size: 60 bytes
// Khung tháo gỡ #1809 | Địa chỉ PC: 0x17c960 | Địa chỉ FDE: 0x097580 | Kích thước: 60 bytes
//   0x17c960: A9007D1F  stp      xzr, xzr, [x8]
//   0x17c964: D65F03C0  ret      
//   0x17c968: F9401268  ldr      x8, [x19, #0x20]
//   0x17c96c: F100191F  cmp      x8, #6
static inline uint64_t fde_func_1809_0x17c960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c960ULL ^ (static_cast<uint64_t>(0xa9007d1fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x097580ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1810 | PC: 0x17c99c | FDE: 0x0975e0 | Size: 136 bytes
// Khung tháo gỡ #1810 | Địa chỉ PC: 0x17c99c | Địa chỉ FDE: 0x0975e0 | Kích thước: 136 bytes
//   0x17c99c: B940C3FB  ldr      w27, [sp, #0xc0]
//   0x17c9a0: 2A0103F8  mov      w24, w1
//   0x17c9a4: D0FFF5C1  adrp     x1, #0x36000
//   0x17c9a8: 2A0203F7  mov      w23, w2
static inline uint64_t fde_func_1810_0x17c99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17c99cULL ^ (static_cast<uint64_t>(0xb940c3fbULL) << 13);
    acc = (acc + a1 + 0x2a0103f8ULL) ^ 0x0975e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1811 | PC: 0x17ca24 | FDE: 0x097640 | Size: 84 bytes
// Khung tháo gỡ #1811 | Địa chỉ PC: 0x17ca24 | Địa chỉ FDE: 0x097640 | Kích thước: 84 bytes
//   0x17ca24: D10643FF  sub      sp, sp, #0x190
//   0x17ca28: F900A3FC  str      x28, [sp, #0x140]
//   0x17ca2c: A91563F9  stp      x25, x24, [sp, #0x150]
//   0x17ca30: A9165BF7  stp      x23, x22, [sp, #0x160]
static inline uint64_t fde_func_1811_0x17ca24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ca24ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900a3fcULL) ^ 0x097640ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1812 | PC: 0x17ca78 | FDE: 0x0976a0 | Size: 120 bytes
// Khung tháo gỡ #1812 | Địa chỉ PC: 0x17ca78 | Địa chỉ FDE: 0x0976a0 | Kích thước: 120 bytes
//   0x17ca78: D53BD048  mrs      x8, tpidr_el0
//   0x17ca7c: F90007E8  str      x8, [sp, #8]
//   0x17ca80: F9401508  ldr      x8, [x8, #0x28]
//   0x17ca84: D65F03C0  ret      
static inline uint64_t fde_func_1812_0x17ca78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ca78ULL ^ (static_cast<uint64_t>(0xd53bd048ULL) << 13);
    acc = (acc + a1 + 0xf90007e8ULL) ^ 0x0976a0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1813 | PC: 0x17caf0 | FDE: 0x097700 | Size: 48 bytes
// Khung tháo gỡ #1813 | Địa chỉ PC: 0x17caf0 | Địa chỉ FDE: 0x097700 | Kích thước: 48 bytes
//   0x17caf0: 91004355  add      x21, x26, #0x10
//   0x17caf4: AA1A03FD  mov      x29, x26
//   0x17caf8: D65F03C0  ret      
//   0x17cafc: 9AD40B68  udiv     x8, x27, x20
static inline uint64_t fde_func_1813_0x17caf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17caf0ULL ^ (static_cast<uint64_t>(0x91004355ULL) << 13);
    acc = (acc + a1 + 0xaa1a03fdULL) ^ 0x097700ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1814 | PC: 0x17cb20 | FDE: 0x097760 | Size: 104 bytes
// Khung tháo gỡ #1814 | Địa chỉ PC: 0x17cb20 | Địa chỉ FDE: 0x097760 | Kích thước: 104 bytes
//   0x17cb20: AA1F03E3  mov      x3, xzr
//   0x17cb24: AA1F03E4  mov      x4, xzr
//   0x17cb28: AA1F03E5  mov      x5, xzr
//   0x17cb2c: D65F03C0  ret      
static inline uint64_t fde_func_1814_0x17cb20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cb20ULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e4ULL) ^ 0x097760ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1815 | PC: 0x17cb88 | FDE: 0x0977c0 | Size: 88 bytes
// Khung tháo gỡ #1815 | Địa chỉ PC: 0x17cb88 | Địa chỉ FDE: 0x0977c0 | Kích thước: 88 bytes
//   0x17cb88: 9100A3E0  add      x0, sp, #0x28
//   0x17cb8c: 17FCB07F  b        #0xa8d88
//   0x17cb90: F90003FF  str      xzr, [sp]
//   0x17cb94: F9400E68  ldr      x8, [x19, #0x18]
static inline uint64_t fde_func_1815_0x17cb88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cb88ULL ^ (static_cast<uint64_t>(0x9100a3e0ULL) << 13);
    acc = (acc + a1 + 0x17fcb07fULL) ^ 0x0977c0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1816 | PC: 0x17cbe0 | FDE: 0x097820 | Size: 112 bytes
// Khung tháo gỡ #1816 | Địa chỉ PC: 0x17cbe0 | Địa chỉ FDE: 0x097820 | Kích thước: 112 bytes
//   0x17cbe0: 910143E0  add      x0, sp, #0x50
//   0x17cbe4: 17FCAF44  b        #0xa88f4
//   0x17cbe8: B9000268  str      w8, [x19]
//   0x17cbec: B90002A9  str      w9, [x21]
static inline uint64_t fde_func_1816_0x17cbe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cbe0ULL ^ (static_cast<uint64_t>(0x910143e0ULL) << 13);
    acc = (acc + a1 + 0x17fcaf44ULL) ^ 0x097820ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1817 | PC: 0x17cc50 | FDE: 0x097880 | Size: 60 bytes
// Khung tháo gỡ #1817 | Địa chỉ PC: 0x17cc50 | Địa chỉ FDE: 0x097880 | Kích thước: 60 bytes
//   0x17cc50: 910023E1  add      x1, sp, #8
//   0x17cc54: 14002F17  b        #0x1888b0
//   0x17cc58: F100001F  cmp      x0, #0
//   0x17cc5c: 1A9F17E8  cset     w8, eq
static inline uint64_t fde_func_1817_0x17cc50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cc50ULL ^ (static_cast<uint64_t>(0x910023e1ULL) << 13);
    acc = (acc + a1 + 0x14002f17ULL) ^ 0x097880ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1818 | PC: 0x17cc8c | FDE: 0x0978e8 | Size: 64 bytes
// Khung tháo gỡ #1818 | Địa chỉ PC: 0x17cc8c | Địa chỉ FDE: 0x0978e8 | Kích thước: 64 bytes
//   0x17cc8c: 910023F3  add      x19, sp, #8
//   0x17cc90: 17FCAF17  b        #0xa88ec
//   0x17cc94: 2A1403E1  mov      w1, w20
//   0x17cc98: 17FD6D8C  b        #0xd82c8
static inline uint64_t fde_func_1818_0x17cc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cc8cULL ^ (static_cast<uint64_t>(0x910023f3ULL) << 13);
    acc = (acc + a1 + 0x17fcaf17ULL) ^ 0x0978e8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1819 | PC: 0x17cccc | FDE: 0x097948 | Size: 92 bytes
// Khung tháo gỡ #1819 | Địa chỉ PC: 0x17cccc | Địa chỉ FDE: 0x097948 | Kích thước: 92 bytes
//   0x17cccc: EB080128  subs     x8, x9, x8
//   0x17ccd0: F9403BE9  ldr      x9, [sp, #0x70]
//   0x17ccd4: 9342FD08  asr      x8, x8, #2
//   0x17ccd8: 9A9F1517  csinc    x23, x8, xzr, ne
static inline uint64_t fde_func_1819_0x17cccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ccccULL ^ (static_cast<uint64_t>(0xeb080128ULL) << 13);
    acc = (acc + a1 + 0xf9403be9ULL) ^ 0x097948ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1820 | PC: 0x17cd28 | FDE: 0x0979a8 | Size: 112 bytes
// Khung tháo gỡ #1820 | Địa chỉ PC: 0x17cd28 | Địa chỉ FDE: 0x0979a8 | Kích thước: 112 bytes
//   0x17cd28: AA0203F3  mov      x19, x2
//   0x17cd2c: EB000022  subs     x2, x1, x0
//   0x17cd30: 9342FC54  asr      x20, x2, #2
//   0x17cd34: D65F03C0  ret      
static inline uint64_t fde_func_1820_0x17cd28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cd28ULL ^ (static_cast<uint64_t>(0xaa0203f3ULL) << 13);
    acc = (acc + a1 + 0xeb000022ULL) ^ 0x0979a8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1821 | PC: 0x17cd98 | FDE: 0x097a08 | Size: 48 bytes
// Khung tháo gỡ #1821 | Địa chỉ PC: 0x17cd98 | Địa chỉ FDE: 0x097a08 | Kích thước: 48 bytes
//   0x17cd98: AA1F03E1  mov      x1, xzr
//   0x17cd9c: AA1F03E0  mov      x0, xzr
//   0x17cda0: D65F03C0  ret      
//   0x17cda4: 910023F7  add      x23, sp, #8
static inline uint64_t fde_func_1821_0x17cd98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cd98ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x097a08ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1822 | PC: 0x17cdc8 | FDE: 0x097a68 | Size: 104 bytes
// Khung tháo gỡ #1822 | Địa chỉ PC: 0x17cdc8 | Địa chỉ FDE: 0x097a68 | Kích thước: 104 bytes
//   0x17cdc8: FD4012E0  ldr      d0, [x23, #0x20]
//   0x17cdcc: 29400AE1  ldp      w1, w2, [x23]
//   0x17cdd0: 294112E3  ldp      w3, w4, [x23, #8]
//   0x17cdd4: 29421AE5  ldp      w5, w6, [x23, #0x10]
static inline uint64_t fde_func_1822_0x17cdc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cdc8ULL ^ (static_cast<uint64_t>(0xfd4012e0ULL) << 13);
    acc = (acc + a1 + 0x29400ae1ULL) ^ 0x097a68ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1823 | PC: 0x17ce30 | FDE: 0x097ac8 | Size: 100 bytes
// Khung tháo gỡ #1823 | Địa chỉ PC: 0x17ce30 | Địa chỉ FDE: 0x097ac8 | Kích thước: 100 bytes
//   0x17ce30: F9400668  ldr      x8, [x19, #8]
//   0x17ce34: F0FFF5C1  adrp     x1, #0x37000
//   0x17ce38: B0FFF582  adrp     x2, #0x2d000
//   0x17ce3c: 91270421  add      x1, x1, #0x9c1
static inline uint64_t fde_func_1823_0x17ce30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ce30ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0xf0fff5c1ULL) ^ 0x097ac8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1824 | PC: 0x17ce94 | FDE: 0x097b28 | Size: 60 bytes
// Khung tháo gỡ #1824 | Địa chỉ PC: 0x17ce94 | Địa chỉ FDE: 0x097b28 | Kích thước: 60 bytes
//   0x17ce94: AA1303E0  mov      x0, x19
//   0x17ce98: 14002A26  b        #0x187730
//   0x17ce9c: AA1303E0  mov      x0, x19
//   0x17cea0: A91BFFFF  stp      xzr, xzr, [sp, #0x1b8]
static inline uint64_t fde_func_1824_0x17ce94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ce94ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x14002a26ULL) ^ 0x097b28ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1825 | PC: 0x17ced0 | FDE: 0x097b88 | Size: 100 bytes
// Khung tháo gỡ #1825 | Địa chỉ PC: 0x17ced0 | Địa chỉ FDE: 0x097b88 | Kích thước: 100 bytes
//   0x17ced0: AA1603E2  mov      x2, x22
//   0x17ced4: AA1503E3  mov      x3, x21
//   0x17ced8: D65F03C0  ret      
//   0x17cedc: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1825_0x17ced0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ced0ULL ^ (static_cast<uint64_t>(0xaa1603e2ULL) << 13);
    acc = (acc + a1 + 0xaa1503e3ULL) ^ 0x097b88ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1826 | PC: 0x17cf34 | FDE: 0x097bf0 | Size: 80 bytes
// Khung tháo gỡ #1826 | Địa chỉ PC: 0x17cf34 | Địa chỉ FDE: 0x097bf0 | Kích thước: 80 bytes
//   0x17cf34: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17cf38: AA1603E0  mov      x0, x22
//   0x17cf3c: AA1503E1  mov      x1, x21
//   0x17cf40: AA1703E2  mov      x2, x23
static inline uint64_t fde_func_1826_0x17cf34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cf34ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x097bf0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1827 | PC: 0x17cf84 | FDE: 0x097c58 | Size: 72 bytes
// Khung tháo gỡ #1827 | Địa chỉ PC: 0x17cf84 | Địa chỉ FDE: 0x097c58 | Kích thước: 72 bytes
//   0x17cf84: F9400268  ldr      x8, [x19]
//   0x17cf88: F87B7909  ldr      x9, [x8, x27, lsl #3]
//   0x17cf8c: D65F03C0  ret      
//   0x17cf90: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1827_0x17cf84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cf84ULL ^ (static_cast<uint64_t>(0xf9400268ULL) << 13);
    acc = (acc + a1 + 0xf87b7909ULL) ^ 0x097c58ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1828 | PC: 0x17cfcc | FDE: 0x097cb8 | Size: 80 bytes
// Khung tháo gỡ #1828 | Địa chỉ PC: 0x17cfcc | Địa chỉ FDE: 0x097cb8 | Kích thước: 80 bytes
//   0x17cfcc: AA0003F3  mov      x19, x0
//   0x17cfd0: 52A7F008  mov      w8, #0x3f800000
//   0x17cfd4: 9100C3E1  add      x1, sp, #0x30
//   0x17cfd8: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_1828_0x17cfcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cfccULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x52a7f008ULL) ^ 0x097cb8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1829 | PC: 0x17d01c | FDE: 0x097d18 | Size: 104 bytes
// Khung tháo gỡ #1829 | Địa chỉ PC: 0x17d01c | Địa chỉ FDE: 0x097d18 | Kích thước: 104 bytes
//   0x17d01c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17d020: AA1403E0  mov      x0, x20
//   0x17d024: 97FF9247  bl       #0x161940
//   0x17d028: 0B1A001D  add      w29, w0, w26
static inline uint64_t fde_func_1829_0x17d01c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d01cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x097d18ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1830 | PC: 0x17d084 | FDE: 0x097d88 | Size: 36 bytes
// Khung tháo gỡ #1830 | Địa chỉ PC: 0x17d084 | Địa chỉ FDE: 0x097d88 | Kích thước: 36 bytes
//   0x17d084: AA1403E1  mov      x1, x20
//   0x17d088: 17FCAE3F  b        #0xa8984
//   0x17d08c: AA1503E1  mov      x1, x21
//   0x17d090: 17FDCB2C  b        #0xefd40
static inline uint64_t fde_func_1830_0x17d084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d084ULL ^ (static_cast<uint64_t>(0xaa1403e1ULL) << 13);
    acc = (acc + a1 + 0x17fcae3fULL) ^ 0x097d88ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1831 | PC: 0x17d0a8 | FDE: 0x097de8 | Size: 36 bytes
// Khung tháo gỡ #1831 | Địa chỉ PC: 0x17d0a8 | Địa chỉ FDE: 0x097de8 | Kích thước: 36 bytes
//   0x17d0a8: 910023E0  add      x0, sp, #8
//   0x17d0ac: AA1603E1  mov      x1, x22
//   0x17d0b0: D65F03C0  ret      
//   0x17d0b4: AA1503E0  mov      x0, x21
static inline uint64_t fde_func_1831_0x17d0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d0a8ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0xaa1603e1ULL) ^ 0x097de8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1832 | PC: 0x17d0cc | FDE: 0x097e48 | Size: 128 bytes
// Khung tháo gỡ #1832 | Địa chỉ PC: 0x17d0cc | Địa chỉ FDE: 0x097e48 | Kích thước: 128 bytes
//   0x17d0cc: AA0003F5  mov      x21, x0
//   0x17d0d0: F90007E8  str      x8, [sp, #8]
//   0x17d0d4: A9007C08  stp      x8, xzr, [x0]
//   0x17d0d8: F8010EBF  str      xzr, [x21, #0x10]!
static inline uint64_t fde_func_1832_0x17d0cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d0ccULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0xf90007e8ULL) ^ 0x097e48ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1833 | PC: 0x17d14c | FDE: 0x097ea8 | Size: 104 bytes
// Khung tháo gỡ #1833 | Địa chỉ PC: 0x17d14c | Địa chỉ FDE: 0x097ea8 | Kích thước: 104 bytes
//   0x17d14c: D53BD057  mrs      x23, tpidr_el0
//   0x17d150: F94016E8  ldr      x8, [x23, #0x28]
//   0x17d154: AA0103F3  mov      x19, x1
//   0x17d158: F90027E8  str      x8, [sp, #0x48]
static inline uint64_t fde_func_1833_0x17d14c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d14cULL ^ (static_cast<uint64_t>(0xd53bd057ULL) << 13);
    acc = (acc + a1 + 0xf94016e8ULL) ^ 0x097ea8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1834 | PC: 0x17d1b4 | FDE: 0x097f08 | Size: 68 bytes
// Khung tháo gỡ #1834 | Địa chỉ PC: 0x17d1b4 | Địa chỉ FDE: 0x097f08 | Kích thước: 68 bytes
//   0x17d1b4: 52800F00  mov      w0, #0x78
//   0x17d1b8: 1400285A  b        #0x187320
//   0x17d1bc: 91001109  add      x9, x8, #4
//   0x17d1c0: F9002BE9  str      x9, [sp, #0x50]
static inline uint64_t fde_func_1834_0x17d1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d1b4ULL ^ (static_cast<uint64_t>(0x52800f00ULL) << 13);
    acc = (acc + a1 + 0x1400285aULL) ^ 0x097f08ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1835 | PC: 0x17d1f8 | FDE: 0x097f68 | Size: 44 bytes
// Khung tháo gỡ #1835 | Địa chỉ PC: 0x17d1f8 | Địa chỉ FDE: 0x097f68 | Kích thước: 44 bytes
//   0x17d1f8: 52832062  mov      w2, #0x1903
//   0x17d1fc: 2A1303E0  mov      w0, w19
//   0x17d200: 14002E44  b        #0x188b10
//   0x17d204: D10EE100  sub      x0, x8, #0x3b8
static inline uint64_t fde_func_1835_0x17d1f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d1f8ULL ^ (static_cast<uint64_t>(0x52832062ULL) << 13);
    acc = (acc + a1 + 0x2a1303e0ULL) ^ 0x097f68ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1836 | PC: 0x17d224 | FDE: 0x097fc8 | Size: 68 bytes
// Khung tháo gỡ #1836 | Địa chỉ PC: 0x17d224 | Địa chỉ FDE: 0x097fc8 | Kích thước: 68 bytes
//   0x17d224: F90063E0  str      x0, [sp, #0xc0]
//   0x17d228: 910303E0  add      x0, sp, #0xc0
//   0x17d22c: 14003149  b        #0x189750
//   0x17d230: AD020260  stp      q0, q0, [x19, #0x40]
static inline uint64_t fde_func_1836_0x17d224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d224ULL ^ (static_cast<uint64_t>(0xf90063e0ULL) << 13);
    acc = (acc + a1 + 0x910303e0ULL) ^ 0x097fc8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1837 | PC: 0x17d268 | FDE: 0x098028 | Size: 56 bytes
// Khung tháo gỡ #1837 | Địa chỉ PC: 0x17d268 | Địa chỉ FDE: 0x098028 | Kích thước: 56 bytes
//   0x17d268: F9402E60  ldr      x0, [x19, #0x58]
//   0x17d26c: 14002875  b        #0x187440
//   0x17d270: D10403FF  sub      sp, sp, #0x100
//   0x17d274: A90A6FFC  stp      x28, x27, [sp, #0xa0]
static inline uint64_t fde_func_1837_0x17d268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d268ULL ^ (static_cast<uint64_t>(0xf9402e60ULL) << 13);
    acc = (acc + a1 + 0x14002875ULL) ^ 0x098028ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1838 | PC: 0x17d2a0 | FDE: 0x098088 | Size: 84 bytes
// Khung tháo gỡ #1838 | Địa chỉ PC: 0x17d2a0 | Địa chỉ FDE: 0x098088 | Kích thước: 84 bytes
//   0x17d2a0: F9401C08  ldr      x8, [x0, #0x38]
//   0x17d2a4: F9400420  ldr      x0, [x1, #8]
//   0x17d2a8: FD401500  ldr      d0, [x8, #0x28]
//   0x17d2ac: 14002F71  b        #0x189070
static inline uint64_t fde_func_1838_0x17d2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d2a0ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x098088ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1839 | PC: 0x17d2f4 | FDE: 0x0980e8 | Size: 76 bytes
// Khung tháo gỡ #1839 | Địa chỉ PC: 0x17d2f4 | Địa chỉ FDE: 0x0980e8 | Kích thước: 76 bytes
//   0x17d2f4: BD40F101  ldr      s1, [x8, #0xf0]
//   0x17d2f8: 5E21D800  scvtf    s0, s0
//   0x17d2fc: 1E211800  fdiv     s0, s0, s1
//   0x17d300: 1E22C000  fcvt     d0, s0
static inline uint64_t fde_func_1839_0x17d2f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d2f4ULL ^ (static_cast<uint64_t>(0xbd40f101ULL) << 13);
    acc = (acc + a1 + 0x5e21d800ULL) ^ 0x0980e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1840 | PC: 0x17d340 | FDE: 0x098148 | Size: 76 bytes
// Khung tháo gỡ #1840 | Địa chỉ PC: 0x17d340 | Địa chỉ FDE: 0x098148 | Kích thước: 76 bytes
//   0x17d340: F9401E88  ldr      x8, [x20, #0x38]
//   0x17d344: 12000002  and      w2, w0, #1
//   0x17d348: 910063E1  add      x1, sp, #0x18
//   0x17d34c: 4EA81D00  mov      v0.16b, v8.16b
static inline uint64_t fde_func_1840_0x17d340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d340ULL ^ (static_cast<uint64_t>(0xf9401e88ULL) << 13);
    acc = (acc + a1 + 0x12000002ULL) ^ 0x098148ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1841 | PC: 0x17d38c | FDE: 0x0981a8 | Size: 36 bytes
// Khung tháo gỡ #1841 | Địa chỉ PC: 0x17d38c | Địa chỉ FDE: 0x0981a8 | Kích thước: 36 bytes
//   0x17d38c: 910723E1  add      x1, sp, #0x1c8
//   0x17d390: 17FE9AB4  b        #0x123e60
//   0x17d394: 910723E0  add      x0, sp, #0x1c8
//   0x17d398: 17FCAE7C  b        #0xa8d88
static inline uint64_t fde_func_1841_0x17d38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d38cULL ^ (static_cast<uint64_t>(0x910723e1ULL) << 13);
    acc = (acc + a1 + 0x17fe9ab4ULL) ^ 0x0981a8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1842 | PC: 0x17d3b0 | FDE: 0x098208 | Size: 52 bytes
// Khung tháo gỡ #1842 | Địa chỉ PC: 0x17d3b0 | Địa chỉ FDE: 0x098208 | Kích thước: 52 bytes
//   0x17d3b0: 9102C3E0  add      x0, sp, #0xb0
//   0x17d3b4: 14003183  b        #0x1899c0
//   0x17d3b8: 5281BC20  mov      w0, #0xde1
//   0x17d3bc: 52850001  mov      w1, #0x2800
static inline uint64_t fde_func_1842_0x17d3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d3b0ULL ^ (static_cast<uint64_t>(0x9102c3e0ULL) << 13);
    acc = (acc + a1 + 0x14003183ULL) ^ 0x098208ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1843 | PC: 0x17d3e4 | FDE: 0x098268 | Size: 88 bytes
// Khung tháo gỡ #1843 | Địa chỉ PC: 0x17d3e4 | Địa chỉ FDE: 0x098268 | Kích thước: 88 bytes
//   0x17d3e4: 9125DC63  add      x3, x3, #0x977
//   0x17d3e8: 910023E0  add      x0, sp, #8
//   0x17d3ec: 17FF4749  b        #0x14f110
//   0x17d3f0: 29400AC1  ldp      w1, w2, [x22]
static inline uint64_t fde_func_1843_0x17d3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d3e4ULL ^ (static_cast<uint64_t>(0x9125dc63ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x098268ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1844 | PC: 0x17d43c | FDE: 0x0982c8 | Size: 112 bytes
// Khung tháo gỡ #1844 | Địa chỉ PC: 0x17d43c | Địa chỉ FDE: 0x0982c8 | Kích thước: 112 bytes
//   0x17d43c: B9400268  ldr      w8, [x19]
//   0x17d440: 11000509  add      w9, w8, #1
//   0x17d444: B9000269  str      w9, [x19]
//   0x17d448: B8687AA1  ldr      w1, [x21, x8, lsl #2]
static inline uint64_t fde_func_1844_0x17d43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d43cULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x11000509ULL) ^ 0x0982c8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1845 | PC: 0x17d4ac | FDE: 0x098328 | Size: 96 bytes
// Khung tháo gỡ #1845 | Địa chỉ PC: 0x17d4ac | Địa chỉ FDE: 0x098328 | Kích thước: 96 bytes
//   0x17d4ac: B9400268  ldr      w8, [x19]
//   0x17d4b0: 11000509  add      w9, w8, #1
//   0x17d4b4: B9000269  str      w9, [x19]
//   0x17d4b8: B8687AA1  ldr      w1, [x21, x8, lsl #2]
static inline uint64_t fde_func_1845_0x17d4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d4acULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x11000509ULL) ^ 0x098328ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1846 | PC: 0x17d50c | FDE: 0x098388 | Size: 52 bytes
// Khung tháo gỡ #1846 | Địa chỉ PC: 0x17d50c | Địa chỉ FDE: 0x098388 | Kích thước: 52 bytes
//   0x17d50c: 914007E0  add      x0, sp, #1, lsl #12
//   0x17d510: 91284000  add      x0, x0, #0xa10
//   0x17d514: B901ABE2  str      w2, [sp, #0x1a8]
//   0x17d518: 17FF91B8  b        #0x161bf8
static inline uint64_t fde_func_1846_0x17d50c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d50cULL ^ (static_cast<uint64_t>(0x914007e0ULL) << 13);
    acc = (acc + a1 + 0x91284000ULL) ^ 0x098388ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1847 | PC: 0x17d540 | FDE: 0x0983e8 | Size: 64 bytes
// Khung tháo gỡ #1847 | Địa chỉ PC: 0x17d540 | Địa chỉ FDE: 0x0983e8 | Kích thước: 64 bytes
//   0x17d540: 91161C21  add      x1, x1, #0x587
//   0x17d544: 17FCACEC  b        #0xa88f4
//   0x17d548: A94E4FF4  ldp      x20, x19, [sp, #0xe0]
//   0x17d54c: A94D57F6  ldp      x22, x21, [sp, #0xd0]
static inline uint64_t fde_func_1847_0x17d540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d540ULL ^ (static_cast<uint64_t>(0x91161c21ULL) << 13);
    acc = (acc + a1 + 0x17fcacecULL) ^ 0x0983e8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1848 | PC: 0x17d580 | FDE: 0x098448 | Size: 88 bytes
// Khung tháo gỡ #1848 | Địa chỉ PC: 0x17d580 | Địa chỉ FDE: 0x098448 | Kích thước: 88 bytes
//   0x17d580: A90387E0  stp      x0, x1, [sp, #0x38]
//   0x17d584: 9100E3E0  add      x0, sp, #0x38
//   0x17d588: 140030BA  b        #0x189870
//   0x17d58c: EB0B0128  subs     x8, x9, x11
static inline uint64_t fde_func_1848_0x17d580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d580ULL ^ (static_cast<uint64_t>(0xa90387e0ULL) << 13);
    acc = (acc + a1 + 0x9100e3e0ULL) ^ 0x098448ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1849 | PC: 0x17d5d8 | FDE: 0x0984a8 | Size: 76 bytes
// Khung tháo gỡ #1849 | Địa chỉ PC: 0x17d5d8 | Địa chỉ FDE: 0x0984a8 | Kích thước: 76 bytes
//   0x17d5d8: 2A1F03E4  mov      w4, wzr
//   0x17d5dc: 910303FF  add      sp, sp, #0xc0
//   0x17d5e0: 17FE05B2  b        #0xfeca8
//   0x17d5e4: 2A1803E4  mov      w4, w24
static inline uint64_t fde_func_1849_0x17d5d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d5d8ULL ^ (static_cast<uint64_t>(0x2a1f03e4ULL) << 13);
    acc = (acc + a1 + 0x910303ffULL) ^ 0x0984a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1850 | PC: 0x17d624 | FDE: 0x098508 | Size: 80 bytes
// Khung tháo gỡ #1850 | Địa chỉ PC: 0x17d624 | Địa chỉ FDE: 0x098508 | Kích thước: 80 bytes
//   0x17d624: AA1303E8  mov      x8, x19
//   0x17d628: F8410D09  ldr      x9, [x8, #0x10]!
//   0x17d62c: F90002C9  str      x9, [x22]
//   0x17d630: F9000116  str      x22, [x8]
static inline uint64_t fde_func_1850_0x17d624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d624ULL ^ (static_cast<uint64_t>(0xaa1303e8ULL) << 13);
    acc = (acc + a1 + 0xf8410d09ULL) ^ 0x098508ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1851 | PC: 0x17d674 | FDE: 0x098568 | Size: 52 bytes
// Khung tháo gỡ #1851 | Địa chỉ PC: 0x17d674 | Địa chỉ FDE: 0x098568 | Kích thước: 52 bytes
//   0x17d674: F9404A68  ldr      x8, [x19, #0x90]
//   0x17d678: 52817201  mov      w1, #0xb90
//   0x17d67c: F9400100  ldr      x0, [x8]
//   0x17d680: 17FD9990  b        #0xe3cc0
static inline uint64_t fde_func_1851_0x17d674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d674ULL ^ (static_cast<uint64_t>(0xf9404a68ULL) << 13);
    acc = (acc + a1 + 0x52817201ULL) ^ 0x098568ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1852 | PC: 0x17d6a8 | FDE: 0x0985c8 | Size: 60 bytes
// Khung tháo gỡ #1852 | Địa chỉ PC: 0x17d6a8 | Địa chỉ FDE: 0x0985c8 | Kích thước: 60 bytes
//   0x17d6a8: 910383E0  add      x0, sp, #0xe0
//   0x17d6ac: 1400274D  b        #0x1873e0
//   0x17d6b0: 29420E68  ldp      w8, w3, [x19, #0x10]
//   0x17d6b4: 29431664  ldp      w4, w5, [x19, #0x18]
static inline uint64_t fde_func_1852_0x17d6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d6a8ULL ^ (static_cast<uint64_t>(0x910383e0ULL) << 13);
    acc = (acc + a1 + 0x1400274dULL) ^ 0x0985c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1853 | PC: 0x17d6e4 | FDE: 0x098628 | Size: 92 bytes
// Khung tháo gỡ #1853 | Địa chỉ PC: 0x17d6e4 | Địa chỉ FDE: 0x098628 | Kích thước: 92 bytes
//   0x17d6e4: F9401268  ldr      x8, [x19, #0x20]
//   0x17d6e8: B9000100  str      w0, [x8]
//   0x17d6ec: AA1403E0  mov      x0, x20
//   0x17d6f0: 17FCADA6  b        #0xa8d88
static inline uint64_t fde_func_1853_0x17d6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d6e4ULL ^ (static_cast<uint64_t>(0xf9401268ULL) << 13);
    acc = (acc + a1 + 0xb9000100ULL) ^ 0x098628ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1854 | PC: 0x17d740 | FDE: 0x098688 | Size: 48 bytes
// Khung tháo gỡ #1854 | Địa chỉ PC: 0x17d740 | Địa chỉ FDE: 0x098688 | Kích thước: 48 bytes
//   0x17d740: 110006C1  add      w1, w22, #1
//   0x17d744: 0B000115  add      w21, w8, w0
//   0x17d748: AA1403E0  mov      x0, x20
//   0x17d74c: 17FF907D  b        #0x161940
static inline uint64_t fde_func_1854_0x17d740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d740ULL ^ (static_cast<uint64_t>(0x110006c1ULL) << 13);
    acc = (acc + a1 + 0x0b000115ULL) ^ 0x098688ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1855 | PC: 0x17d770 | FDE: 0x0986e8 | Size: 80 bytes
// Khung tháo gỡ #1855 | Địa chỉ PC: 0x17d770 | Địa chỉ FDE: 0x0986e8 | Kích thước: 80 bytes
//   0x17d770: F90007F4  str      x20, [sp, #8]
//   0x17d774: F9400661  ldr      x1, [x19, #8]
//   0x17d778: 910023E0  add      x0, sp, #8
//   0x17d77c: 17FF01CB  b        #0x13dea8
static inline uint64_t fde_func_1855_0x17d770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d770ULL ^ (static_cast<uint64_t>(0xf90007f4ULL) << 13);
    acc = (acc + a1 + 0xf9400661ULL) ^ 0x0986e8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1856 | PC: 0x17d7c0 | FDE: 0x098748 | Size: 84 bytes
// Khung tháo gỡ #1856 | Địa chỉ PC: 0x17d7c0 | Địa chỉ FDE: 0x098748 | Kích thước: 84 bytes
//   0x17d7c0: F9401BE8  ldr      x8, [sp, #0x30]
//   0x17d7c4: F0FFF582  adrp     x2, #0x30000
//   0x17d7c8: 91263C42  add      x2, x2, #0x98f
//   0x17d7cc: 910083E0  add      x0, sp, #0x20
static inline uint64_t fde_func_1856_0x17d7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d7c0ULL ^ (static_cast<uint64_t>(0xf9401be8ULL) << 13);
    acc = (acc + a1 + 0xf0fff582ULL) ^ 0x098748ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1857 | PC: 0x17d814 | FDE: 0x0987a8 | Size: 92 bytes
// Khung tháo gỡ #1857 | Địa chỉ PC: 0x17d814 | Địa chỉ FDE: 0x0987a8 | Kích thước: 92 bytes
//   0x17d814: 52800189  mov      w9, #0xc
//   0x17d818: AA0103F3  mov      x19, x1
//   0x17d81c: AA0003F4  mov      x20, x0
//   0x17d820: F9007FE8  str      x8, [sp, #0xf8]
static inline uint64_t fde_func_1857_0x17d814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d814ULL ^ (static_cast<uint64_t>(0x52800189ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x0987a8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1858 | PC: 0x17d870 | FDE: 0x098808 | Size: 60 bytes
// Khung tháo gỡ #1858 | Địa chỉ PC: 0x17d870 | Địa chỉ FDE: 0x098808 | Kích thước: 60 bytes
//   0x17d870: F94003E8  ldr      x8, [sp]
//   0x17d874: B9403322  ldr      w2, [x25, #0x30]
//   0x17d878: A9450500  ldp      x0, x1, [x8, #0x50]
//   0x17d87c: 17FDFBFF  b        #0xfc878
static inline uint64_t fde_func_1858_0x17d870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d870ULL ^ (static_cast<uint64_t>(0xf94003e8ULL) << 13);
    acc = (acc + a1 + 0xb9403322ULL) ^ 0x098808ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1859 | PC: 0x17d8ac | FDE: 0x098868 | Size: 100 bytes
// Khung tháo gỡ #1859 | Địa chỉ PC: 0x17d8ac | Địa chỉ FDE: 0x098868 | Kích thước: 100 bytes
//   0x17d8ac: A9544FF4  ldp      x20, x19, [sp, #0x140]
//   0x17d8b0: A95357F6  ldp      x22, x21, [sp, #0x130]
//   0x17d8b4: A9525FF8  ldp      x24, x23, [sp, #0x120]
//   0x17d8b8: A95167FA  ldp      x26, x25, [sp, #0x110]
static inline uint64_t fde_func_1859_0x17d8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d8acULL ^ (static_cast<uint64_t>(0xa9544ff4ULL) << 13);
    acc = (acc + a1 + 0xa95357f6ULL) ^ 0x098868ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1860 | PC: 0x17d910 | FDE: 0x0988c8 | Size: 112 bytes
// Khung tháo gỡ #1860 | Địa chỉ PC: 0x17d910 | Địa chỉ FDE: 0x0988c8 | Kích thước: 112 bytes
//   0x17d910: F9400068  ldr      x8, [x3]
//   0x17d914: F900007F  str      xzr, [x3]
//   0x17d918: 910003E2  mov      x2, sp
//   0x17d91c: 910063E3  add      x3, sp, #0x18
static inline uint64_t fde_func_1860_0x17d910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d910ULL ^ (static_cast<uint64_t>(0xf9400068ULL) << 13);
    acc = (acc + a1 + 0xf900007fULL) ^ 0x0988c8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1861 | PC: 0x17d980 | FDE: 0x098928 | Size: 88 bytes
// Khung tháo gỡ #1861 | Địa chỉ PC: 0x17d980 | Địa chỉ FDE: 0x098928 | Kích thước: 88 bytes
//   0x17d980: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17d984: 97FCB8CD  bl       #0xabcb8
//   0x17d988: AA1303E0  mov      x0, x19
//   0x17d98c: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1861_0x17d980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d980ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97fcb8cdULL) ^ 0x098928ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1862 | PC: 0x17d9d8 | FDE: 0x098990 | Size: 52 bytes
// Khung tháo gỡ #1862 | Địa chỉ PC: 0x17d9d8 | Địa chỉ FDE: 0x098990 | Kích thước: 52 bytes
//   0x17d9d8: F9400660  ldr      x0, [x19, #8]
//   0x17d9dc: AA0303E1  mov      x1, x3
//   0x17d9e0: 17FCBBDB  b        #0xac94c
//   0x17d9e4: 52800022  mov      w2, #1
static inline uint64_t fde_func_1862_0x17d9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d9d8ULL ^ (static_cast<uint64_t>(0xf9400660ULL) << 13);
    acc = (acc + a1 + 0xaa0303e1ULL) ^ 0x098990ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1863 | PC: 0x17da0c | FDE: 0x0989f0 | Size: 56 bytes
// Khung tháo gỡ #1863 | Địa chỉ PC: 0x17da0c | Địa chỉ FDE: 0x0989f0 | Kích thước: 56 bytes
//   0x17da0c: 9100A3E0  add      x0, sp, #0x28
//   0x17da10: 14002674  b        #0x1873e0
//   0x17da14: 910023E8  add      x8, sp, #8
//   0x17da18: AA1403E1  mov      x1, x20
static inline uint64_t fde_func_1863_0x17da0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17da0cULL ^ (static_cast<uint64_t>(0x9100a3e0ULL) << 13);
    acc = (acc + a1 + 0x14002674ULL) ^ 0x0989f0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1864 | PC: 0x17da44 | FDE: 0x098a50 | Size: 44 bytes
// Khung tháo gỡ #1864 | Địa chỉ PC: 0x17da44 | Địa chỉ FDE: 0x098a50 | Kích thước: 44 bytes
//   0x17da44: AA1F03E4  mov      x4, xzr
//   0x17da48: D61F0100  br       x8
//   0x17da4c: A90307E0  stp      x0, x1, [sp, #0x30]
//   0x17da50: 9100C3E0  add      x0, sp, #0x30
static inline uint64_t fde_func_1864_0x17da44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17da44ULL ^ (static_cast<uint64_t>(0xaa1f03e4ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x098a50ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1865 | PC: 0x17da70 | FDE: 0x098ab0 | Size: 76 bytes
// Khung tháo gỡ #1865 | Địa chỉ PC: 0x17da70 | Địa chỉ FDE: 0x098ab0 | Kích thước: 76 bytes
//   0x17da70: 52800501  mov      w1, #0x28
//   0x17da74: AA1503E0  mov      x0, x21
//   0x17da78: 17FD9E6F  b        #0xe5434
//   0x17da7c: F9404508  ldr      x8, [x8, #0x88]
static inline uint64_t fde_func_1865_0x17da70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17da70ULL ^ (static_cast<uint64_t>(0x52800501ULL) << 13);
    acc = (acc + a1 + 0xaa1503e0ULL) ^ 0x098ab0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1866 | PC: 0x17dabc | FDE: 0x098b10 | Size: 52 bytes
// Khung tháo gỡ #1866 | Địa chỉ PC: 0x17dabc | Địa chỉ FDE: 0x098b10 | Kích thước: 52 bytes
//   0x17dabc: 2A1803E2  mov      w2, w24
//   0x17dac0: 2A1703E3  mov      w3, w23
//   0x17dac4: 17FE256D  b        #0x107078
//   0x17dac8: CB090108  sub      x8, x8, x9
static inline uint64_t fde_func_1866_0x17dabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dabcULL ^ (static_cast<uint64_t>(0x2a1803e2ULL) << 13);
    acc = (acc + a1 + 0x2a1703e3ULL) ^ 0x098b10ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1867 | PC: 0x17daf0 | FDE: 0x098b70 | Size: 36 bytes
// Khung tháo gỡ #1867 | Địa chỉ PC: 0x17daf0 | Địa chỉ FDE: 0x098b70 | Kích thước: 36 bytes
//   0x17daf0: AA1A03E1  mov      x1, x26
//   0x17daf4: 17FCAB80  b        #0xa88f4
//   0x17daf8: AA1B03E0  mov      x0, x27
//   0x17dafc: 17FDF3FB  b        #0xfaae8
static inline uint64_t fde_func_1867_0x17daf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17daf0ULL ^ (static_cast<uint64_t>(0xaa1a03e1ULL) << 13);
    acc = (acc + a1 + 0x17fcab80ULL) ^ 0x098b70ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1868 | PC: 0x17db14 | FDE: 0x098bd0 | Size: 56 bytes
// Khung tháo gỡ #1868 | Địa chỉ PC: 0x17db14 | Địa chỉ FDE: 0x098bd0 | Kích thước: 56 bytes
//   0x17db14: F9400260  ldr      x0, [x19]
//   0x17db18: F900027F  str      xzr, [x19]
//   0x17db1c: D65F03C0  ret      
//   0x17db20: F9404A60  ldr      x0, [x19, #0x90]
static inline uint64_t fde_func_1868_0x17db14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17db14ULL ^ (static_cast<uint64_t>(0xf9400260ULL) << 13);
    acc = (acc + a1 + 0xf900027fULL) ^ 0x098bd0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1869 | PC: 0x17db4c | FDE: 0x098c30 | Size: 68 bytes
// Khung tháo gỡ #1869 | Địa chỉ PC: 0x17db4c | Địa chỉ FDE: 0x098c30 | Kích thước: 68 bytes
//   0x17db4c: AA0003E1  mov      x1, x0
//   0x17db50: 2A1F03E5  mov      w5, wzr
//   0x17db54: 2A1F03E6  mov      w6, wzr
//   0x17db58: 17FE657B  b        #0x117144
static inline uint64_t fde_func_1869_0x17db4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17db4cULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e5ULL) ^ 0x098c30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1870 | PC: 0x17db90 | FDE: 0x098c90 | Size: 64 bytes
// Khung tháo gỡ #1870 | Địa chỉ PC: 0x17db90 | Địa chỉ FDE: 0x098c90 | Kích thước: 64 bytes
//   0x17db90: 910103E1  add      x1, sp, #0x40
//   0x17db94: 910083E2  add      x2, sp, #0x20
//   0x17db98: AA1403E0  mov      x0, x20
//   0x17db9c: 17FF93C5  b        #0x162ab0
static inline uint64_t fde_func_1870_0x17db90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17db90ULL ^ (static_cast<uint64_t>(0x910103e1ULL) << 13);
    acc = (acc + a1 + 0x910083e2ULL) ^ 0x098c90ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1871 | PC: 0x17dbd0 | FDE: 0x098cf0 | Size: 56 bytes
// Khung tháo gỡ #1871 | Địa chỉ PC: 0x17dbd0 | Địa chỉ FDE: 0x098cf0 | Kích thước: 56 bytes
//   0x17dbd0: 9101E3E0  add      x0, sp, #0x78
//   0x17dbd4: 14002643  b        #0x1874e0
//   0x17dbd8: 910063E0  add      x0, sp, #0x18
//   0x17dbdc: AA1F03E3  mov      x3, xzr
static inline uint64_t fde_func_1871_0x17dbd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dbd0ULL ^ (static_cast<uint64_t>(0x9101e3e0ULL) << 13);
    acc = (acc + a1 + 0x14002643ULL) ^ 0x098cf0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1872 | PC: 0x17dc08 | FDE: 0x098d50 | Size: 56 bytes
// Khung tháo gỡ #1872 | Địa chỉ PC: 0x17dc08 | Địa chỉ FDE: 0x098d50 | Kích thước: 56 bytes
//   0x17dc08: AA1703E0  mov      x0, x23
//   0x17dc0c: AA1403E1  mov      x1, x20
//   0x17dc10: D65F03C0  ret      
//   0x17dc14: AA1703E0  mov      x0, x23
static inline uint64_t fde_func_1872_0x17dc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dc08ULL ^ (static_cast<uint64_t>(0xaa1703e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x098d50ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1873 | PC: 0x17dc40 | FDE: 0x098db0 | Size: 56 bytes
// Khung tháo gỡ #1873 | Địa chỉ PC: 0x17dc40 | Địa chỉ FDE: 0x098db0 | Kích thước: 56 bytes
//   0x17dc40: A94353F5  ldp      x21, x20, [sp, #0x30]
//   0x17dc44: F94013F6  ldr      x22, [sp, #0x20]
//   0x17dc48: 910143FF  add      sp, sp, #0x50
//   0x17dc4c: D65F03C0  ret      
static inline uint64_t fde_func_1873_0x17dc40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dc40ULL ^ (static_cast<uint64_t>(0xa94353f5ULL) << 13);
    acc = (acc + a1 + 0xf94013f6ULL) ^ 0x098db0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1874 | PC: 0x17dc78 | FDE: 0x098e10 | Size: 60 bytes
// Khung tháo gỡ #1874 | Địa chỉ PC: 0x17dc78 | Địa chỉ FDE: 0x098e10 | Kích thước: 60 bytes
//   0x17dc78: F94002C8  ldr      x8, [x22]
//   0x17dc7c: 910023E1  add      x1, sp, #8
//   0x17dc80: AA0003F5  mov      x21, x0
//   0x17dc84: F90002DF  str      xzr, [x22]
static inline uint64_t fde_func_1874_0x17dc78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dc78ULL ^ (static_cast<uint64_t>(0xf94002c8ULL) << 13);
    acc = (acc + a1 + 0x910023e1ULL) ^ 0x098e10ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1875 | PC: 0x17dcb4 | FDE: 0x098e70 | Size: 88 bytes
// Khung tháo gỡ #1875 | Địa chỉ PC: 0x17dcb4 | Địa chỉ FDE: 0x098e70 | Kích thước: 88 bytes
//   0x17dcb4: F90033FF  str      xzr, [sp, #0x60]
//   0x17dcb8: B9001FFF  str      wzr, [sp, #0x1c]
//   0x17dcbc: D65F03C0  ret      
//   0x17dcc0: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_1875_0x17dcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dcb4ULL ^ (static_cast<uint64_t>(0xf90033ffULL) << 13);
    acc = (acc + a1 + 0xb9001fffULL) ^ 0x098e70ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1876 | PC: 0x17dd0c | FDE: 0x098ed8 | Size: 72 bytes
// Khung tháo gỡ #1876 | Địa chỉ PC: 0x17dd0c | Địa chỉ FDE: 0x098ed8 | Kích thước: 72 bytes
//   0x17dd0c: F9401668  ldr      x8, [x19, #0x28]
//   0x17dd10: F9401D01  ldr      x1, [x8, #0x38]
//   0x17dd14: D65F03C0  ret      
//   0x17dd18: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1876_0x17dd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dd0cULL ^ (static_cast<uint64_t>(0xf9401668ULL) << 13);
    acc = (acc + a1 + 0xf9401d01ULL) ^ 0x098ed8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1877 | PC: 0x17dd54 | FDE: 0x098f38 | Size: 60 bytes
// Khung tháo gỡ #1877 | Địa chỉ PC: 0x17dd54 | Địa chỉ FDE: 0x098f38 | Kích thước: 60 bytes
//   0x17dd54: D53BD053  mrs      x19, tpidr_el0
//   0x17dd58: F9401668  ldr      x8, [x19, #0x28]
//   0x17dd5c: F9000FE8  str      x8, [sp, #0x18]
//   0x17dd60: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1877_0x17dd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dd54ULL ^ (static_cast<uint64_t>(0xd53bd053ULL) << 13);
    acc = (acc + a1 + 0xf9401668ULL) ^ 0x098f38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1878 | PC: 0x17dd90 | FDE: 0x098f98 | Size: 104 bytes
// Khung tháo gỡ #1878 | Địa chỉ PC: 0x17dd90 | Địa chỉ FDE: 0x098f98 | Kích thước: 104 bytes
//   0x17dd90: D53BD055  mrs      x21, tpidr_el0
//   0x17dd94: F94016A8  ldr      x8, [x21, #0x28]
//   0x17dd98: AA0003F4  mov      x20, x0
//   0x17dd9c: F900BFE8  str      x8, [sp, #0x178]
static inline uint64_t fde_func_1878_0x17dd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dd90ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x098f98ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1879 | PC: 0x17ddf8 | FDE: 0x098ff8 | Size: 68 bytes
// Khung tháo gỡ #1879 | Địa chỉ PC: 0x17ddf8 | Địa chỉ FDE: 0x098ff8 | Kích thước: 68 bytes
//   0x17ddf8: A94153F5  ldp      x21, x20, [sp, #0x10]
//   0x17ddfc: A8C35BFC  ldp      x28, x22, [sp], #0x30
//   0x17de00: D65F03C0  ret      
//   0x17de04: 927CED16  and      x22, x8, #0xfffffffffffffff0
static inline uint64_t fde_func_1879_0x17ddf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ddf8ULL ^ (static_cast<uint64_t>(0xa94153f5ULL) << 13);
    acc = (acc + a1 + 0xa8c35bfcULL) ^ 0x098ff8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1880 | PC: 0x17de3c | FDE: 0x099058 | Size: 48 bytes
// Khung tháo gỡ #1880 | Địa chỉ PC: 0x17de3c | Địa chỉ FDE: 0x099058 | Kích thước: 48 bytes
//   0x17de3c: F9400BF4  ldr      x20, [sp, #0x10]
//   0x17de40: 6CC323E9  ldp      d9, d8, [sp], #0x30
//   0x17de44: D65F03C0  ret      
//   0x17de48: 52800021  mov      w1, #1
static inline uint64_t fde_func_1880_0x17de3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17de3cULL ^ (static_cast<uint64_t>(0xf9400bf4ULL) << 13);
    acc = (acc + a1 + 0x6cc323e9ULL) ^ 0x099058ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1881 | PC: 0x17de6c | FDE: 0x0990b8 | Size: 72 bytes
// Khung tháo gỡ #1881 | Địa chỉ PC: 0x17de6c | Địa chỉ FDE: 0x0990b8 | Kích thước: 72 bytes
//   0x17de6c: F9400008  ldr      x8, [x0]
//   0x17de70: AA0003F3  mov      x19, x0
//   0x17de74: D65F03C0  ret      
//   0x17de78: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1881_0x17de6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17de6cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0990b8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1882 | PC: 0x17deb4 | FDE: 0x099118 | Size: 60 bytes
// Khung tháo gỡ #1882 | Địa chỉ PC: 0x17deb4 | Địa chỉ FDE: 0x099118 | Kích thước: 60 bytes
//   0x17deb4: F9400668  ldr      x8, [x19, #8]
//   0x17deb8: 910083E0  add      x0, sp, #0x20
//   0x17debc: F90013E8  str      x8, [sp, #0x20]
//   0x17dec0: 140026FC  b        #0x187ab0
static inline uint64_t fde_func_1882_0x17deb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17deb4ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0x910083e0ULL) ^ 0x099118ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1883 | PC: 0x17def0 | FDE: 0x099178 | Size: 60 bytes
// Khung tháo gỡ #1883 | Địa chỉ PC: 0x17def0 | Địa chỉ FDE: 0x099178 | Kích thước: 60 bytes
//   0x17def0: F9400028  ldr      x8, [x1]
//   0x17def4: AA0103F3  mov      x19, x1
//   0x17def8: AA0003F4  mov      x20, x0
//   0x17defc: F800843F  str      xzr, [x1], #8
static inline uint64_t fde_func_1883_0x17def0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17def0ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x099178ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1884 | PC: 0x17df2c | FDE: 0x0991d8 | Size: 44 bytes
// Khung tháo gỡ #1884 | Địa chỉ PC: 0x17df2c | Địa chỉ FDE: 0x0991d8 | Kích thước: 44 bytes
//   0x17df2c: AA1303E0  mov      x0, x19
//   0x17df30: 17FDF0D0  b        #0xfa270
//   0x17df34: AA1303E0  mov      x0, x19
//   0x17df38: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1884_0x17df2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17df2cULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17fdf0d0ULL) ^ 0x0991d8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1885 | PC: 0x17df58 | FDE: 0x099238 | Size: 40 bytes
// Khung tháo gỡ #1885 | Địa chỉ PC: 0x17df58 | Địa chỉ FDE: 0x099238 | Kích thước: 40 bytes
//   0x17df58: AA1603E0  mov      x0, x22
//   0x17df5c: 17FD0EFA  b        #0xc1b44
//   0x17df60: AA1603E0  mov      x0, x22
//   0x17df64: 2A1703E1  mov      w1, w23
static inline uint64_t fde_func_1885_0x17df58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17df58ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x17fd0efaULL) ^ 0x099238ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1886 | PC: 0x17df80 | FDE: 0x099298 | Size: 64 bytes
// Khung tháo gỡ #1886 | Địa chỉ PC: 0x17df80 | Địa chỉ FDE: 0x099298 | Kích thước: 64 bytes
//   0x17df80: 910003E0  mov      x0, sp
//   0x17df84: AA1303E1  mov      x1, x19
//   0x17df88: 17FDC65C  b        #0xef8f8
//   0x17df8c: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1886_0x17df80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17df80ULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0xaa1303e1ULL) ^ 0x099298ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1887 | PC: 0x17dfc0 | FDE: 0x0992f8 | Size: 56 bytes
// Khung tháo gỡ #1887 | Địa chỉ PC: 0x17dfc0 | Địa chỉ FDE: 0x0992f8 | Kích thước: 56 bytes
//   0x17dfc0: AA0003F3  mov      x19, x0
//   0x17dfc4: 52800300  mov      w0, #0x18
//   0x17dfc8: AA0803F4  mov      x20, x8
//   0x17dfcc: 140024D5  b        #0x187320
static inline uint64_t fde_func_1887_0x17dfc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dfc0ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x52800300ULL) ^ 0x0992f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1888 | PC: 0x17dff8 | FDE: 0x099358 | Size: 40 bytes
// Khung tháo gỡ #1888 | Địa chỉ PC: 0x17dff8 | Địa chỉ FDE: 0x099358 | Kích thước: 40 bytes
//   0x17dff8: AA1403E0  mov      x0, x20
//   0x17dffc: 9AD50856  udiv     x22, x2, x21
//   0x17e000: 14002470  b        #0x1871c0
//   0x17e004: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1888_0x17dff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dff8ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x9ad50856ULL) ^ 0x099358ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1889 | PC: 0x17e020 | FDE: 0x0993b8 | Size: 88 bytes
// Khung tháo gỡ #1889 | Địa chỉ PC: 0x17e020 | Địa chỉ FDE: 0x0993b8 | Kích thước: 88 bytes
//   0x17e020: AA1403E0  mov      x0, x20
//   0x17e024: 2A1803E1  mov      w1, w24
//   0x17e028: 17FF8E46  b        #0x161940
//   0x17e02c: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1889_0x17e020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e020ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x2a1803e1ULL) ^ 0x0993b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1890 | PC: 0x17e078 | FDE: 0x099420 | Size: 72 bytes
// Khung tháo gỡ #1890 | Địa chỉ PC: 0x17e078 | Địa chỉ FDE: 0x099420 | Kích thước: 72 bytes
//   0x17e078: AA1503E1  mov      x1, x21
//   0x17e07c: AA0003F6  mov      x22, x0
//   0x17e080: 1400256C  b        #0x187630
//   0x17e084: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_1890_0x17e078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e078ULL ^ (static_cast<uint64_t>(0xaa1503e1ULL) << 13);
    acc = (acc + a1 + 0xaa0003f6ULL) ^ 0x099420ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1891 | PC: 0x17e0c0 | FDE: 0x099488 | Size: 56 bytes
// Khung tháo gỡ #1891 | Địa chỉ PC: 0x17e0c0 | Địa chỉ FDE: 0x099488 | Kích thước: 56 bytes
//   0x17e0c0: 910023E0  add      x0, sp, #8
//   0x17e0c4: AA1403E1  mov      x1, x20
//   0x17e0c8: 910023F5  add      x21, sp, #8
//   0x17e0cc: 17FE9765  b        #0x123e60
static inline uint64_t fde_func_1891_0x17e0c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e0c0ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x099488ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1892 | PC: 0x17e0f8 | FDE: 0x0994e8 | Size: 60 bytes
// Khung tháo gỡ #1892 | Địa chỉ PC: 0x17e0f8 | Địa chỉ FDE: 0x0994e8 | Kích thước: 60 bytes
//   0x17e0f8: 6F00E400  movi     v0.2d, #0000000000000000
//   0x17e0fc: F90007E8  str      x8, [sp, #8]
//   0x17e100: F9000008  str      x8, [x0]
//   0x17e104: 3C808000  stur     q0, [x0, #8]
static inline uint64_t fde_func_1892_0x17e0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e0f8ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xf90007e8ULL) ^ 0x0994e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1893 | PC: 0x17e134 | FDE: 0x099548 | Size: 60 bytes
// Khung tháo gỡ #1893 | Địa chỉ PC: 0x17e134 | Địa chỉ FDE: 0x099548 | Kích thước: 60 bytes
//   0x17e134: AA0003F5  mov      x21, x0
//   0x17e138: AA0103F4  mov      x20, x1
//   0x17e13c: D65F03C0  ret      
//   0x17e140: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1893_0x17e134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e134ULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0xaa0103f4ULL) ^ 0x099548ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1894 | PC: 0x17e170 | FDE: 0x0995a8 | Size: 96 bytes
// Khung tháo gỡ #1894 | Địa chỉ PC: 0x17e170 | Địa chỉ FDE: 0x0995a8 | Kích thước: 96 bytes
//   0x17e170: D53BD057  mrs      x23, tpidr_el0
//   0x17e174: F94016E8  ldr      x8, [x23, #0x28]
//   0x17e178: AA0103F4  mov      x20, x1
//   0x17e17c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1894_0x17e170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e170ULL ^ (static_cast<uint64_t>(0xd53bd057ULL) << 13);
    acc = (acc + a1 + 0xf94016e8ULL) ^ 0x0995a8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1895 | PC: 0x17e1d0 | FDE: 0x099608 | Size: 80 bytes
// Khung tháo gỡ #1895 | Địa chỉ PC: 0x17e1d0 | Địa chỉ FDE: 0x099608 | Kích thước: 80 bytes
//   0x17e1d0: 7100005F  cmp      w2, #0
//   0x17e1d4: 5A825442  cneg     w2, w2, mi
//   0x17e1d8: 7100007F  cmp      w3, #0
//   0x17e1dc: 5A835463  cneg     w3, w3, mi
static inline uint64_t fde_func_1895_0x17e1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e1d0ULL ^ (static_cast<uint64_t>(0x7100005fULL) << 13);
    acc = (acc + a1 + 0x5a825442ULL) ^ 0x099608ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1896 | PC: 0x17e220 | FDE: 0x099668 | Size: 64 bytes
// Khung tháo gỡ #1896 | Địa chỉ PC: 0x17e220 | Địa chỉ FDE: 0x099668 | Kích thước: 64 bytes
//   0x17e220: 29400AE1  ldp      w1, w2, [x23]
//   0x17e224: B9400EE5  ldr      w5, [x23, #0xc]
//   0x17e228: 8B284AA3  add      x3, x21, w8, uxtw #2
//   0x17e22c: AA1C03E0  mov      x0, x28
static inline uint64_t fde_func_1896_0x17e220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e220ULL ^ (static_cast<uint64_t>(0x29400ae1ULL) << 13);
    acc = (acc + a1 + 0xb9400ee5ULL) ^ 0x099668ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1897 | PC: 0x17e260 | FDE: 0x0996c8 | Size: 92 bytes
// Khung tháo gỡ #1897 | Địa chỉ PC: 0x17e260 | Địa chỉ FDE: 0x0996c8 | Kích thước: 92 bytes
//   0x17e260: 91012260  add      x0, x19, #0x48
//   0x17e264: 12000282  and      w2, w20, #1
//   0x17e268: 910003E1  mov      x1, sp
//   0x17e26c: 4EA91D20  mov      v0.16b, v9.16b
static inline uint64_t fde_func_1897_0x17e260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e260ULL ^ (static_cast<uint64_t>(0x91012260ULL) << 13);
    acc = (acc + a1 + 0x12000282ULL) ^ 0x0996c8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1898 | PC: 0x17e2bc | FDE: 0x099728 | Size: 96 bytes
// Khung tháo gỡ #1898 | Địa chỉ PC: 0x17e2bc | Địa chỉ FDE: 0x099728 | Kích thước: 96 bytes
//   0x17e2bc: AD0503E1  stp      q1, q0, [sp, #0xa0]
//   0x17e2c0: 14002EF8  b        #0x189ea0
//   0x17e2c4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17e2c8: 91006118  add      x24, x8, #0x18
static inline uint64_t fde_func_1898_0x17e2bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e2bcULL ^ (static_cast<uint64_t>(0xad0503e1ULL) << 13);
    acc = (acc + a1 + 0x14002ef8ULL) ^ 0x099728ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1899 | PC: 0x17e31c | FDE: 0x099790 | Size: 84 bytes
// Khung tháo gỡ #1899 | Địa chỉ PC: 0x17e31c | Địa chỉ FDE: 0x099790 | Kích thước: 84 bytes
//   0x17e31c: B9400289  ldr      w9, [x20]
//   0x17e320: B8004509  str      w9, [x8], #4
//   0x17e324: F9000668  str      x8, [x19, #8]
//   0x17e328: D65F03C0  ret      
static inline uint64_t fde_func_1899_0x17e31c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e31cULL ^ (static_cast<uint64_t>(0xb9400289ULL) << 13);
    acc = (acc + a1 + 0xb8004509ULL) ^ 0x099790ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1900 | PC: 0x17e370 | FDE: 0x0997f0 | Size: 48 bytes
// Khung tháo gỡ #1900 | Địa chỉ PC: 0x17e370 | Địa chỉ FDE: 0x0997f0 | Kích thước: 48 bytes
//   0x17e370: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x17e374: 91004129  add      x9, x9, #0x10
//   0x17e378: D65F03C0  ret      
//   0x17e37c: F9400A82  ldr      x2, [x20, #0x10]
static inline uint64_t fde_func_1900_0x17e370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e370ULL ^ (static_cast<uint64_t>(0xf2ffffe8ULL) << 13);
    acc = (acc + a1 + 0x91004129ULL) ^ 0x0997f0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1901 | PC: 0x17e3a0 | FDE: 0x099850 | Size: 52 bytes
// Khung tháo gỡ #1901 | Địa chỉ PC: 0x17e3a0 | Địa chỉ FDE: 0x099850 | Kích thước: 52 bytes
//   0x17e3a0: A942AA68  ldp      x8, x10, [x19, #0x28]
//   0x17e3a4: 2A1403E9  mov      w9, w20
//   0x17e3a8: CB08014A  sub      x10, x10, x8
//   0x17e3ac: EB8A113F  cmp      x9, x10, asr #4
static inline uint64_t fde_func_1901_0x17e3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e3a0ULL ^ (static_cast<uint64_t>(0xa942aa68ULL) << 13);
    acc = (acc + a1 + 0x2a1403e9ULL) ^ 0x099850ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1902 | PC: 0x17e3d4 | FDE: 0x0998b0 | Size: 76 bytes
// Khung tháo gỡ #1902 | Địa chỉ PC: 0x17e3d4 | Địa chỉ FDE: 0x0998b0 | Kích thước: 76 bytes
//   0x17e3d4: 8B89FD29  add      x9, x9, x9, asr #63
//   0x17e3d8: 91402129  add      x9, x9, #8, lsl #12
//   0x17e3dc: 9270BD29  and      x9, x9, #0xffffffffffff0000
//   0x17e3e0: D65F03C0  ret      
static inline uint64_t fde_func_1902_0x17e3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e3d4ULL ^ (static_cast<uint64_t>(0x8b89fd29ULL) << 13);
    acc = (acc + a1 + 0x91402129ULL) ^ 0x0998b0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1903 | PC: 0x17e420 | FDE: 0x099910 | Size: 68 bytes
// Khung tháo gỡ #1903 | Địa chỉ PC: 0x17e420 | Địa chỉ FDE: 0x099910 | Kích thước: 68 bytes
//   0x17e420: 29400408  ldp      w8, w1, [x0]
//   0x17e424: B9400802  ldr      w2, [x0, #8]
//   0x17e428: F9400803  ldr      x3, [x0, #0x10]
//   0x17e42c: B9401804  ldr      w4, [x0, #0x18]
static inline uint64_t fde_func_1903_0x17e420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e420ULL ^ (static_cast<uint64_t>(0x29400408ULL) << 13);
    acc = (acc + a1 + 0xb9400802ULL) ^ 0x099910ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1904 | PC: 0x17e464 | FDE: 0x099970 | Size: 92 bytes
// Khung tháo gỡ #1904 | Địa chỉ PC: 0x17e464 | Địa chỉ FDE: 0x099970 | Kích thước: 92 bytes
//   0x17e464: 11000D08  add      w8, w8, #3
//   0x17e468: 0B480928  add      w8, w9, w8, lsr #2
//   0x17e46c: B9000268  str      w8, [x19]
//   0x17e470: D65F03C0  ret      
static inline uint64_t fde_func_1904_0x17e464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e464ULL ^ (static_cast<uint64_t>(0x11000d08ULL) << 13);
    acc = (acc + a1 + 0x0b480928ULL) ^ 0x099970ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1905 | PC: 0x17e4c0 | FDE: 0x0999d0 | Size: 88 bytes
// Khung tháo gỡ #1905 | Địa chỉ PC: 0x17e4c0 | Địa chỉ FDE: 0x0999d0 | Kích thước: 88 bytes
//   0x17e4c0: 9102A3E0  add      x0, sp, #0xa8
//   0x17e4c4: 17FCAA31  b        #0xa8d88
//   0x17e4c8: F94013F7  ldr      x23, [sp, #0x20]
//   0x17e4cc: B94043F8  ldr      w24, [sp, #0x40]
static inline uint64_t fde_func_1905_0x17e4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e4c0ULL ^ (static_cast<uint64_t>(0x9102a3e0ULL) << 13);
    acc = (acc + a1 + 0x17fcaa31ULL) ^ 0x0999d0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1906 | PC: 0x17e518 | FDE: 0x099a30 | Size: 76 bytes
// Khung tháo gỡ #1906 | Địa chỉ PC: 0x17e518 | Địa chỉ FDE: 0x099a30 | Kích thước: 76 bytes
//   0x17e518: A95353F5  ldp      x21, x20, [sp, #0x130]
//   0x17e51c: A9525BF7  ldp      x23, x22, [sp, #0x120]
//   0x17e520: A95163F9  ldp      x25, x24, [sp, #0x110]
//   0x17e524: A9506BFC  ldp      x28, x26, [sp, #0x100]
static inline uint64_t fde_func_1906_0x17e518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e518ULL ^ (static_cast<uint64_t>(0xa95353f5ULL) << 13);
    acc = (acc + a1 + 0xa9525bf7ULL) ^ 0x099a30ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1907 | PC: 0x17e564 | FDE: 0x099a90 | Size: 96 bytes
// Khung tháo gỡ #1907 | Địa chỉ PC: 0x17e564 | Địa chỉ FDE: 0x099a90 | Kích thước: 96 bytes
//   0x17e564: 910003EA  mov      x10, sp
//   0x17e568: 910003E1  mov      x1, sp
//   0x17e56c: F9001FE8  str      x8, [sp, #0x38]
//   0x17e570: F90013EA  str      x10, [sp, #0x20]
static inline uint64_t fde_func_1907_0x17e564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e564ULL ^ (static_cast<uint64_t>(0x910003eaULL) << 13);
    acc = (acc + a1 + 0x910003e1ULL) ^ 0x099a90ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1908 | PC: 0x17e5c4 | FDE: 0x099af0 | Size: 92 bytes
// Khung tháo gỡ #1908 | Địa chỉ PC: 0x17e5c4 | Địa chỉ FDE: 0x099af0 | Kích thước: 92 bytes
//   0x17e5c4: F9401008  ldr      x8, [x0, #0x20]
//   0x17e5c8: F100051F  cmp      x8, #1
//   0x17e5cc: D65F03C0  ret      
//   0x17e5d0: 2A1503E1  mov      w1, w21
static inline uint64_t fde_func_1908_0x17e5c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e5c4ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xf100051fULL) ^ 0x099af0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1909 | PC: 0x17e620 | FDE: 0x099b50 | Size: 96 bytes
// Khung tháo gỡ #1909 | Địa chỉ PC: 0x17e620 | Địa chỉ FDE: 0x099b50 | Kích thước: 96 bytes
//   0x17e620: 91273421  add      x1, x1, #0x9cd
//   0x17e624: 910023E0  add      x0, sp, #8
//   0x17e628: D65F03C0  ret      
//   0x17e62c: B240028A  orr      x10, x20, #1
static inline uint64_t fde_func_1909_0x17e620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e620ULL ^ (static_cast<uint64_t>(0x91273421ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x099b50ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1910 | PC: 0x17e680 | FDE: 0x099bb0 | Size: 68 bytes
// Khung tháo gỡ #1910 | Địa chỉ PC: 0x17e680 | Địa chỉ FDE: 0x099bb0 | Kích thước: 68 bytes
//   0x17e680: 52900D21  mov      w1, #0x8069
//   0x17e684: 17FDAC04  b        #0xe9694
//   0x17e688: 910463E3  add      x3, sp, #0x118
//   0x17e68c: 9106C3E4  add      x4, sp, #0x1b0
static inline uint64_t fde_func_1910_0x17e680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e680ULL ^ (static_cast<uint64_t>(0x52900d21ULL) << 13);
    acc = (acc + a1 + 0x17fdac04ULL) ^ 0x099bb0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1911 | PC: 0x17e6c4 | FDE: 0x099c10 | Size: 96 bytes
// Khung tháo gỡ #1911 | Địa chỉ PC: 0x17e6c4 | Địa chỉ FDE: 0x099c10 | Kích thước: 96 bytes
//   0x17e6c4: 3CC4C380  ldur     q0, [x28, #0x4c]
//   0x17e6c8: 3CC5C381  ldur     q1, [x28, #0x5c]
//   0x17e6cc: 3CC6C382  ldur     q2, [x28, #0x6c]
//   0x17e6d0: F9487BE8  ldr      x8, [sp, #0x10f0]
static inline uint64_t fde_func_1911_0x17e6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e6c4ULL ^ (static_cast<uint64_t>(0x3cc4c380ULL) << 13);
    acc = (acc + a1 + 0x3cc5c381ULL) ^ 0x099c10ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1912 | PC: 0x17e724 | FDE: 0x099c70 | Size: 80 bytes
// Khung tháo gỡ #1912 | Địa chỉ PC: 0x17e724 | Địa chỉ FDE: 0x099c70 | Kích thước: 80 bytes
//   0x17e724: 2A1903E3  mov      w3, w25
//   0x17e728: 2A1A03E4  mov      w4, w26
//   0x17e72c: 2A1B03E5  mov      w5, w27
//   0x17e730: 2A1C03E6  mov      w6, w28
static inline uint64_t fde_func_1912_0x17e724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e724ULL ^ (static_cast<uint64_t>(0x2a1903e3ULL) << 13);
    acc = (acc + a1 + 0x2a1a03e4ULL) ^ 0x099c70ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1913 | PC: 0x17e774 | FDE: 0x099cd0 | Size: 128 bytes
// Khung tháo gỡ #1913 | Địa chỉ PC: 0x17e774 | Địa chỉ FDE: 0x099cd0 | Kích thước: 128 bytes
//   0x17e774: B9400268  ldr      w8, [x19]
//   0x17e778: AA1603E0  mov      x0, x22
//   0x17e77c: 8B080AB5  add      x21, x21, x8, lsl #2
//   0x17e780: 11000908  add      w8, w8, #2
static inline uint64_t fde_func_1913_0x17e774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e774ULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x099cd0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1914 | PC: 0x17e7f4 | FDE: 0x099d30 | Size: 76 bytes
// Khung tháo gỡ #1914 | Địa chỉ PC: 0x17e7f4 | Địa chỉ FDE: 0x099d30 | Kích thước: 76 bytes
//   0x17e7f4: B9400268  ldr      w8, [x19]
//   0x17e7f8: 11001109  add      w9, w8, #4
//   0x17e7fc: B9000269  str      w9, [x19]
//   0x17e800: F9401000  ldr      x0, [x0, #0x20]
static inline uint64_t fde_func_1914_0x17e7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e7f4ULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x11001109ULL) ^ 0x099d30ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1915 | PC: 0x17e840 | FDE: 0x099d90 | Size: 68 bytes
// Khung tháo gỡ #1915 | Địa chỉ PC: 0x17e840 | Địa chỉ FDE: 0x099d90 | Kích thước: 68 bytes
//   0x17e840: 914007E0  add      x0, sp, #1, lsl #12
//   0x17e844: 914007E1  add      x1, sp, #1, lsl #12
//   0x17e848: 91020000  add      x0, x0, #0x80
//   0x17e84c: 91030021  add      x1, x1, #0xc0
static inline uint64_t fde_func_1915_0x17e840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e840ULL ^ (static_cast<uint64_t>(0x914007e0ULL) << 13);
    acc = (acc + a1 + 0x914007e1ULL) ^ 0x099d90ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1916 | PC: 0x17e884 | FDE: 0x099df0 | Size: 128 bytes
// Khung tháo gỡ #1916 | Địa chỉ PC: 0x17e884 | Địa chỉ FDE: 0x099df0 | Kích thước: 128 bytes
//   0x17e884: F9419AAA  ldr      x10, [x21, #0x330]
//   0x17e888: F94196A8  ldr      x8, [x21, #0x328]
//   0x17e88c: 2A0103F3  mov      w19, w1
//   0x17e890: 93407D21  sxtw     x1, w9
static inline uint64_t fde_func_1916_0x17e884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e884ULL ^ (static_cast<uint64_t>(0xf9419aaaULL) << 13);
    acc = (acc + a1 + 0xf94196a8ULL) ^ 0x099df0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1917 | PC: 0x17e904 | FDE: 0x099e50 | Size: 96 bytes
// Khung tháo gỡ #1917 | Địa chỉ PC: 0x17e904 | Địa chỉ FDE: 0x099e50 | Kích thước: 96 bytes
//   0x17e904: B94027E3  ldr      w3, [sp, #0x24]
//   0x17e908: F94017E4  ldr      x4, [sp, #0x28]
//   0x17e90c: F942EAA0  ldr      x0, [x21, #0x5d0]
//   0x17e910: AA1403E1  mov      x1, x20
static inline uint64_t fde_func_1917_0x17e904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e904ULL ^ (static_cast<uint64_t>(0xb94027e3ULL) << 13);
    acc = (acc + a1 + 0xf94017e4ULL) ^ 0x099e50ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1918 | PC: 0x17e964 | FDE: 0x099eb0 | Size: 84 bytes
// Khung tháo gỡ #1918 | Địa chỉ PC: 0x17e964 | Địa chỉ FDE: 0x099eb0 | Kích thước: 84 bytes
//   0x17e964: 8B354AC8  add      x8, x22, w21, uxtw #2
//   0x17e968: 52800020  mov      w0, #1
//   0x17e96c: F9000368  str      x8, [x27]
//   0x17e970: B9000349  str      w9, [x26]
static inline uint64_t fde_func_1918_0x17e964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e964ULL ^ (static_cast<uint64_t>(0x8b354ac8ULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x099eb0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1919 | PC: 0x17e9b8 | FDE: 0x099f10 | Size: 84 bytes
// Khung tháo gỡ #1919 | Địa chỉ PC: 0x17e9b8 | Địa chỉ FDE: 0x099f10 | Kích thước: 84 bytes
//   0x17e9b8: F94043E8  ldr      x8, [sp, #0x80]
//   0x17e9bc: F9029100  str      x0, [x8, #0x520]
//   0x17e9c0: B94093E8  ldr      w8, [sp, #0x90]
//   0x17e9c4: D65F03C0  ret      
static inline uint64_t fde_func_1919_0x17e9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e9b8ULL ^ (static_cast<uint64_t>(0xf94043e8ULL) << 13);
    acc = (acc + a1 + 0xf9029100ULL) ^ 0x099f10ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1920 | PC: 0x17ea0c | FDE: 0x099f70 | Size: 76 bytes
// Khung tháo gỡ #1920 | Địa chỉ PC: 0x17ea0c | Địa chỉ FDE: 0x099f70 | Kích thước: 76 bytes
//   0x17ea0c: B9402729  ldr      w9, [x25, #0x24]
//   0x17ea10: AA1F03E8  mov      x8, xzr
//   0x17ea14: EB16013F  cmp      x9, x22
//   0x17ea18: 9A963129  csel     x9, x9, x22, lo
static inline uint64_t fde_func_1920_0x17ea0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ea0cULL ^ (static_cast<uint64_t>(0xb9402729ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e8ULL) ^ 0x099f70ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1921 | PC: 0x17ea58 | FDE: 0x099fd0 | Size: 60 bytes
// Khung tháo gỡ #1921 | Địa chỉ PC: 0x17ea58 | Địa chỉ FDE: 0x099fd0 | Kích thước: 60 bytes
//   0x17ea58: 8B0A038B  add      x11, x28, x10
//   0x17ea5c: 8B090294  add      x20, x20, x9
//   0x17ea60: 9100058C  add      x12, x12, #1
//   0x17ea64: AA0B03FC  mov      x28, x11
static inline uint64_t fde_func_1921_0x17ea58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ea58ULL ^ (static_cast<uint64_t>(0x8b0a038bULL) << 13);
    acc = (acc + a1 + 0x8b090294ULL) ^ 0x099fd0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1922 | PC: 0x17ea94 | FDE: 0x09a030 | Size: 76 bytes
// Khung tháo gỡ #1922 | Địa chỉ PC: 0x17ea94 | Địa chỉ FDE: 0x09a030 | Kích thước: 76 bytes
//   0x17ea94: 91402108  add      x8, x8, #8, lsl #12
//   0x17ea98: 9270BD08  and      x8, x8, #0xffffffffffff0000
//   0x17ea9c: D65F03C0  ret      
//   0x17eaa0: F0FFF5A1  adrp     x1, #0x35000
static inline uint64_t fde_func_1922_0x17ea94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ea94ULL ^ (static_cast<uint64_t>(0x91402108ULL) << 13);
    acc = (acc + a1 + 0x9270bd08ULL) ^ 0x09a030ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1923 | PC: 0x17eae0 | FDE: 0x09a090 | Size: 76 bytes
// Khung tháo gỡ #1923 | Địa chỉ PC: 0x17eae0 | Địa chỉ FDE: 0x09a090 | Kích thước: 76 bytes
//   0x17eae0: F94067E1  ldr      x1, [sp, #0xc8]
//   0x17eae4: 91401BE0  add      x0, sp, #6, lsl #12
//   0x17eae8: 910F2000  add      x0, x0, #0x3c8
//   0x17eaec: F900AFFF  str      xzr, [sp, #0x158]
static inline uint64_t fde_func_1923_0x17eae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eae0ULL ^ (static_cast<uint64_t>(0xf94067e1ULL) << 13);
    acc = (acc + a1 + 0x91401be0ULL) ^ 0x09a090ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1924 | PC: 0x17eb2c | FDE: 0x09a0f0 | Size: 72 bytes
// Khung tháo gỡ #1924 | Địa chỉ PC: 0x17eb2c | Địa chỉ FDE: 0x09a0f0 | Kích thước: 72 bytes
//   0x17eb2c: B94002E1  ldr      w1, [x23]
//   0x17eb30: 8B284AA2  add      x2, x21, w8, uxtw #2
//   0x17eb34: AA1C03E0  mov      x0, x28
//   0x17eb38: D65F03C0  ret      
static inline uint64_t fde_func_1924_0x17eb2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eb2cULL ^ (static_cast<uint64_t>(0xb94002e1ULL) << 13);
    acc = (acc + a1 + 0x8b284aa2ULL) ^ 0x09a0f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1925 | PC: 0x17eb74 | FDE: 0x09a150 | Size: 80 bytes
// Khung tháo gỡ #1925 | Địa chỉ PC: 0x17eb74 | Địa chỉ FDE: 0x09a150 | Kích thước: 80 bytes
//   0x17eb74: 9101F3E3  add      x3, sp, #0x7c
//   0x17eb78: 9101E3E4  add      x4, sp, #0x78
//   0x17eb7c: AA1903E0  mov      x0, x25
//   0x17eb80: 2A1C03E1  mov      w1, w28
static inline uint64_t fde_func_1925_0x17eb74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eb74ULL ^ (static_cast<uint64_t>(0x9101f3e3ULL) << 13);
    acc = (acc + a1 + 0x9101e3e4ULL) ^ 0x09a150ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1926 | PC: 0x17ebc4 | FDE: 0x09a1b8 | Size: 68 bytes
// Khung tháo gỡ #1926 | Địa chỉ PC: 0x17ebc4 | Địa chỉ FDE: 0x09a1b8 | Kích thước: 68 bytes
//   0x17ebc4: 90FFF5C1  adrp     x1, #0x36000
//   0x17ebc8: 91350821  add      x1, x1, #0xd42
//   0x17ebcc: AA1303E0  mov      x0, x19
//   0x17ebd0: D65F03C0  ret      
static inline uint64_t fde_func_1926_0x17ebc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ebc4ULL ^ (static_cast<uint64_t>(0x90fff5c1ULL) << 13);
    acc = (acc + a1 + 0x91350821ULL) ^ 0x09a1b8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1927 | PC: 0x17ec08 | FDE: 0x09a218 | Size: 88 bytes
// Khung tháo gỡ #1927 | Địa chỉ PC: 0x17ec08 | Địa chỉ FDE: 0x09a218 | Kích thước: 88 bytes
//   0x17ec08: B94006B5  ldr      w21, [x21, #4]
//   0x17ec0c: AA0003F7  mov      x23, x0
//   0x17ec10: 528179E2  mov      w2, #0xbcf
//   0x17ec14: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1927_0x17ec08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ec08ULL ^ (static_cast<uint64_t>(0xb94006b5ULL) << 13);
    acc = (acc + a1 + 0xaa0003f7ULL) ^ 0x09a218ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1928 | PC: 0x17ec60 | FDE: 0x09a278 | Size: 68 bytes
// Khung tháo gỡ #1928 | Địa chỉ PC: 0x17ec60 | Địa chỉ FDE: 0x09a278 | Kích thước: 68 bytes
//   0x17ec60: 910263E0  add      x0, sp, #0x98
//   0x17ec64: 1400221F  b        #0x1874e0
//   0x17ec68: A9007C08  stp      x8, xzr, [x0]
//   0x17ec6c: 29015015  stp      w21, w20, [x0, #8]
static inline uint64_t fde_func_1928_0x17ec60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ec60ULL ^ (static_cast<uint64_t>(0x910263e0ULL) << 13);
    acc = (acc + a1 + 0x1400221fULL) ^ 0x09a278ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1929 | PC: 0x17eca4 | FDE: 0x09a2d8 | Size: 84 bytes
// Khung tháo gỡ #1929 | Địa chỉ PC: 0x17eca4 | Địa chỉ FDE: 0x09a2d8 | Kích thước: 84 bytes
//   0x17eca4: F940112A  ldr      x10, [x9, #0x20]
//   0x17eca8: AD400121  ldp      q1, q0, [x9]
//   0x17ecac: F900750A  str      x10, [x8, #0xe8]
//   0x17ecb0: 3C8D8100  stur     q0, [x8, #0xd8]
static inline uint64_t fde_func_1929_0x17eca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eca4ULL ^ (static_cast<uint64_t>(0xf940112aULL) << 13);
    acc = (acc + a1 + 0xad400121ULL) ^ 0x09a2d8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1930 | PC: 0x17ecf8 | FDE: 0x09a338 | Size: 76 bytes
// Khung tháo gỡ #1930 | Địa chỉ PC: 0x17ecf8 | Địa chỉ FDE: 0x09a338 | Kích thước: 76 bytes
//   0x17ecf8: B9407BE8  ldr      w8, [sp, #0x78]
//   0x17ecfc: B94073E9  ldr      w9, [sp, #0x70]
//   0x17ed00: 93407D00  sxtw     x0, w8
//   0x17ed04: 93407D21  sxtw     x1, w9
static inline uint64_t fde_func_1930_0x17ecf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ecf8ULL ^ (static_cast<uint64_t>(0xb9407be8ULL) << 13);
    acc = (acc + a1 + 0xb94073e9ULL) ^ 0x09a338ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1931 | PC: 0x17ed44 | FDE: 0x09a398 | Size: 80 bytes
// Khung tháo gỡ #1931 | Địa chỉ PC: 0x17ed44 | Địa chỉ FDE: 0x09a398 | Kích thước: 80 bytes
//   0x17ed44: 2A0403E2  mov      w2, w4
//   0x17ed48: 2A0503E3  mov      w3, w5
//   0x17ed4c: AA1603E4  mov      x4, x22
//   0x17ed50: 2A0503F7  mov      w23, w5
static inline uint64_t fde_func_1931_0x17ed44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ed44ULL ^ (static_cast<uint64_t>(0x2a0403e2ULL) << 13);
    acc = (acc + a1 + 0x2a0503e3ULL) ^ 0x09a398ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1932 | PC: 0x17ed94 | FDE: 0x09a400 | Size: 60 bytes
// Khung tháo gỡ #1932 | Địa chỉ PC: 0x17ed94 | Địa chỉ FDE: 0x09a400 | Kích thước: 60 bytes
//   0x17ed94: D0FFF5A1  adrp     x1, #0x34000
//   0x17ed98: 9135E821  add      x1, x1, #0xd7a
//   0x17ed9c: 910063E0  add      x0, sp, #0x18
//   0x17eda0: D65F03C0  ret      
static inline uint64_t fde_func_1932_0x17ed94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ed94ULL ^ (static_cast<uint64_t>(0xd0fff5a1ULL) << 13);
    acc = (acc + a1 + 0x9135e821ULL) ^ 0x09a400ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1933 | PC: 0x17edd0 | FDE: 0x09a460 | Size: 92 bytes
// Khung tháo gỡ #1933 | Địa chỉ PC: 0x17edd0 | Địa chỉ FDE: 0x09a460 | Kích thước: 92 bytes
//   0x17edd0: 2A0203F3  mov      w19, w2
//   0x17edd4: AA0103F4  mov      x20, x1
//   0x17edd8: 52916B88  mov      w8, #0x8b5c
//   0x17eddc: F0FFF561  adrp     x1, #0x2d000
static inline uint64_t fde_func_1933_0x17edd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17edd0ULL ^ (static_cast<uint64_t>(0x2a0203f3ULL) << 13);
    acc = (acc + a1 + 0xaa0103f4ULL) ^ 0x09a460ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1934 | PC: 0x17ee2c | FDE: 0x09a4c0 | Size: 92 bytes
// Khung tháo gỡ #1934 | Địa chỉ PC: 0x17ee2c | Địa chỉ FDE: 0x09a4c0 | Kích thước: 92 bytes
//   0x17ee2c: D10343FF  sub      sp, sp, #0xd0
//   0x17ee30: A9086BFB  stp      x27, x26, [sp, #0x80]
//   0x17ee34: A90963F9  stp      x25, x24, [sp, #0x90]
//   0x17ee38: A90A5BF7  stp      x23, x22, [sp, #0xa0]
static inline uint64_t fde_func_1934_0x17ee2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ee2cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9086bfbULL) ^ 0x09a4c0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1935 | PC: 0x17ee88 | FDE: 0x09a520 | Size: 56 bytes
// Khung tháo gỡ #1935 | Địa chỉ PC: 0x17ee88 | Địa chỉ FDE: 0x09a520 | Kích thước: 56 bytes
//   0x17ee88: F9000660  str      x0, [x19, #8]
//   0x17ee8c: 14002121  b        #0x187310
//   0x17ee90: B3701D28  bfi      x8, x9, #0x10, #8
//   0x17ee94: B3781D48  bfi      x8, x10, #8, #8
static inline uint64_t fde_func_1935_0x17ee88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ee88ULL ^ (static_cast<uint64_t>(0xf9000660ULL) << 13);
    acc = (acc + a1 + 0x14002121ULL) ^ 0x09a520ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1936 | PC: 0x17eec0 | FDE: 0x09a580 | Size: 36 bytes
// Khung tháo gỡ #1936 | Địa chỉ PC: 0x17eec0 | Địa chỉ FDE: 0x09a580 | Kích thước: 36 bytes
//   0x17eec0: F90003FF  str      xzr, [sp]
//   0x17eec4: 14002543  b        #0x1883d0
//   0x17eec8: F9400FE0  ldr      x0, [sp, #0x18]
//   0x17eecc: 17FCB192  b        #0xab514
static inline uint64_t fde_func_1936_0x17eec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eec0ULL ^ (static_cast<uint64_t>(0xf90003ffULL) << 13);
    acc = (acc + a1 + 0x14002543ULL) ^ 0x09a580ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1937 | PC: 0x17eee4 | FDE: 0x09a5e0 | Size: 44 bytes
// Khung tháo gỡ #1937 | Địa chỉ PC: 0x17eee4 | Địa chỉ FDE: 0x09a5e0 | Kích thước: 44 bytes
//   0x17eee4: 2A1703E1  mov      w1, w23
//   0x17eee8: 17FD64F8  b        #0xd82c8
//   0x17eeec: 91000508  add      x8, x8, #1
//   0x17eef0: F9000E68  str      x8, [x19, #0x18]
static inline uint64_t fde_func_1937_0x17eee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eee4ULL ^ (static_cast<uint64_t>(0x2a1703e1ULL) << 13);
    acc = (acc + a1 + 0x17fd64f8ULL) ^ 0x09a5e0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1938 | PC: 0x17ef10 | FDE: 0x09a640 | Size: 52 bytes
// Khung tháo gỡ #1938 | Địa chỉ PC: 0x17ef10 | Địa chỉ FDE: 0x09a640 | Kích thước: 52 bytes
//   0x17ef10: B90013EA  str      w10, [sp, #0x10]
//   0x17ef14: B9000BE9  str      w9, [sp, #8]
//   0x17ef18: D65F03C0  ret      
//   0x17ef1c: 52800C00  mov      w0, #0x60
static inline uint64_t fde_func_1938_0x17ef10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ef10ULL ^ (static_cast<uint64_t>(0xb90013eaULL) << 13);
    acc = (acc + a1 + 0xb9000be9ULL) ^ 0x09a640ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1939 | PC: 0x17ef44 | FDE: 0x09a6a0 | Size: 60 bytes
// Khung tháo gỡ #1939 | Địa chỉ PC: 0x17ef44 | Địa chỉ FDE: 0x09a6a0 | Kích thước: 60 bytes
//   0x17ef44: A90307E0  stp      x0, x1, [sp, #0x30]
//   0x17ef48: 9100C3E0  add      x0, sp, #0x30
//   0x17ef4c: D65F03C0  ret      
//   0x17ef50: A90407E0  stp      x0, x1, [sp, #0x40]
static inline uint64_t fde_func_1939_0x17ef44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ef44ULL ^ (static_cast<uint64_t>(0xa90307e0ULL) << 13);
    acc = (acc + a1 + 0x9100c3e0ULL) ^ 0x09a6a0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1940 | PC: 0x17ef80 | FDE: 0x09a700 | Size: 52 bytes
// Khung tháo gỡ #1940 | Địa chỉ PC: 0x17ef80 | Địa chỉ FDE: 0x09a700 | Kích thước: 52 bytes
//   0x17ef80: 910203E0  add      x0, sp, #0x80
//   0x17ef84: 17FCA85D  b        #0xa90f8
//   0x17ef88: 910283E0  add      x0, sp, #0xa0
//   0x17ef8c: 17FCA77F  b        #0xa8d88
static inline uint64_t fde_func_1940_0x17ef80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ef80ULL ^ (static_cast<uint64_t>(0x910203e0ULL) << 13);
    acc = (acc + a1 + 0x17fca85dULL) ^ 0x09a700ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1941 | PC: 0x17efb4 | FDE: 0x09a760 | Size: 108 bytes
// Khung tháo gỡ #1941 | Địa chỉ PC: 0x17efb4 | Địa chỉ FDE: 0x09a760 | Kích thước: 108 bytes
//   0x17efb4: B9000268  str      w8, [x19]
//   0x17efb8: B9400288  ldr      w8, [x20]
//   0x17efbc: AA0003F3  mov      x19, x0
//   0x17efc0: 712F151F  cmp      w8, #0xbc5
static inline uint64_t fde_func_1941_0x17efb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17efb4ULL ^ (static_cast<uint64_t>(0xb9000268ULL) << 13);
    acc = (acc + a1 + 0xb9400288ULL) ^ 0x09a760ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1942 | PC: 0x17f020 | FDE: 0x09a7c0 | Size: 100 bytes
// Khung tháo gỡ #1942 | Địa chỉ PC: 0x17f020 | Địa chỉ FDE: 0x09a7c0 | Kích thước: 100 bytes
//   0x17f020: AA0003E9  mov      x9, x0
//   0x17f024: CB080273  sub      x19, x19, x8
//   0x17f028: AA1303E0  mov      x0, x19
//   0x17f02c: AA0903E1  mov      x1, x9
static inline uint64_t fde_func_1942_0x17f020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f020ULL ^ (static_cast<uint64_t>(0xaa0003e9ULL) << 13);
    acc = (acc + a1 + 0xcb080273ULL) ^ 0x09a7c0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1943 | PC: 0x17f084 | FDE: 0x09a820 | Size: 76 bytes
// Khung tháo gỡ #1943 | Địa chỉ PC: 0x17f084 | Địa chỉ FDE: 0x09a820 | Kích thước: 76 bytes
//   0x17f084: 2A1803E2  mov      w2, w24
//   0x17f088: 17FE0182  b        #0xff690
//   0x17f08c: F9400009  ldr      x9, [x0]
//   0x17f090: FC404100  ldur     d0, [x8, #4]
static inline uint64_t fde_func_1943_0x17f084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f084ULL ^ (static_cast<uint64_t>(0x2a1803e2ULL) << 13);
    acc = (acc + a1 + 0x17fe0182ULL) ^ 0x09a820ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1944 | PC: 0x17f0d0 | FDE: 0x09a880 | Size: 60 bytes
// Khung tháo gỡ #1944 | Địa chỉ PC: 0x17f0d0 | Địa chỉ FDE: 0x09a880 | Kích thước: 60 bytes
//   0x17f0d0: B0FFF581  adrp     x1, #0x30000
//   0x17f0d4: 910F6C21  add      x1, x1, #0x3db
//   0x17f0d8: D65F03C0  ret      
//   0x17f0dc: 9342FD15  asr      x21, x8, #2
static inline uint64_t fde_func_1944_0x17f0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f0d0ULL ^ (static_cast<uint64_t>(0xb0fff581ULL) << 13);
    acc = (acc + a1 + 0x910f6c21ULL) ^ 0x09a880ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1945 | PC: 0x17f10c | FDE: 0x09a8e0 | Size: 72 bytes
// Khung tháo gỡ #1945 | Địa chỉ PC: 0x17f10c | Địa chỉ FDE: 0x09a8e0 | Kích thước: 72 bytes
//   0x17f10c: 4E181D40  mov      v0.d[1], x10
//   0x17f110: AD0083E1  stp      q1, q0, [sp, #0x10]
//   0x17f114: 910003EA  mov      x10, sp
//   0x17f118: F8697941  ldr      x1, [x10, x9, lsl #3]
static inline uint64_t fde_func_1945_0x17f10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f10cULL ^ (static_cast<uint64_t>(0x4e181d40ULL) << 13);
    acc = (acc + a1 + 0xad0083e1ULL) ^ 0x09a8e0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1946 | PC: 0x17f154 | FDE: 0x09a940 | Size: 52 bytes
// Khung tháo gỡ #1946 | Địa chỉ PC: 0x17f154 | Địa chỉ FDE: 0x09a940 | Kích thước: 52 bytes
//   0x17f154: F9402A61  ldr      x1, [x19, #0x50]
//   0x17f158: 17FCA60B  b        #0xa8984
//   0x17f15c: F9400D08  ldr      x8, [x8, #0x18]
//   0x17f160: D1012109  sub      x9, x8, #0x48
static inline uint64_t fde_func_1946_0x17f154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f154ULL ^ (static_cast<uint64_t>(0xf9402a61ULL) << 13);
    acc = (acc + a1 + 0x17fca60bULL) ^ 0x09a940ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1947 | PC: 0x17f188 | FDE: 0x09a9a0 | Size: 68 bytes
// Khung tháo gỡ #1947 | Địa chỉ PC: 0x17f188 | Địa chỉ FDE: 0x09a9a0 | Kích thước: 68 bytes
//   0x17f188: F9400508  ldr      x8, [x8, #8]
//   0x17f18c: D10006E9  sub      x9, x23, #1
//   0x17f190: EA0902FF  tst      x23, x9
//   0x17f194: D65F03C0  ret      
static inline uint64_t fde_func_1947_0x17f188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f188ULL ^ (static_cast<uint64_t>(0xf9400508ULL) << 13);
    acc = (acc + a1 + 0xd10006e9ULL) ^ 0x09a9a0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1948 | PC: 0x17f1cc | FDE: 0x09aa00 | Size: 56 bytes
// Khung tháo gỡ #1948 | Địa chỉ PC: 0x17f1cc | Địa chỉ FDE: 0x09aa00 | Kích thước: 56 bytes
//   0x17f1cc: AA1703E0  mov      x0, x23
//   0x17f1d0: AA1A03E1  mov      x1, x26
//   0x17f1d4: D65F03C0  ret      
//   0x17f1d8: 12800008  mov      w8, #-1
static inline uint64_t fde_func_1948_0x17f1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f1ccULL ^ (static_cast<uint64_t>(0xaa1703e0ULL) << 13);
    acc = (acc + a1 + 0xaa1a03e1ULL) ^ 0x09aa00ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1949 | PC: 0x17f204 | FDE: 0x09aa60 | Size: 76 bytes
// Khung tháo gỡ #1949 | Địa chỉ PC: 0x17f204 | Địa chỉ FDE: 0x09aa60 | Kích thước: 76 bytes
//   0x17f204: F9400A68  ldr      x8, [x19, #0x10]
//   0x17f208: 91000508  add      x8, x8, #1
//   0x17f20c: F9000A68  str      x8, [x19, #0x10]
//   0x17f210: D65F03C0  ret      
static inline uint64_t fde_func_1949_0x17f204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f204ULL ^ (static_cast<uint64_t>(0xf9400a68ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x09aa60ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1950 | PC: 0x17f250 | FDE: 0x09aac0 | Size: 68 bytes
// Khung tháo gỡ #1950 | Địa chỉ PC: 0x17f250 | Địa chỉ FDE: 0x09aac0 | Kích thước: 68 bytes
//   0x17f250: F94002C8  ldr      x8, [x22]
//   0x17f254: F9000BE8  str      x8, [sp, #0x10]
//   0x17f258: F94006C8  ldr      x8, [x22, #8]
//   0x17f25c: F9000FE8  str      x8, [sp, #0x18]
static inline uint64_t fde_func_1950_0x17f250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f250ULL ^ (static_cast<uint64_t>(0xf94002c8ULL) << 13);
    acc = (acc + a1 + 0xf9000be8ULL) ^ 0x09aac0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1951 | PC: 0x17f294 | FDE: 0x09ab20 | Size: 108 bytes
// Khung tháo gỡ #1951 | Địa chỉ PC: 0x17f294 | Địa chỉ FDE: 0x09ab20 | Kích thước: 108 bytes
//   0x17f294: 9100050A  add      x10, x8, #1
//   0x17f298: F902370A  str      x10, [x24, #0x468]
//   0x17f29c: 39000109  strb     w9, [x8]
//   0x17f2a0: F9423708  ldr      x8, [x24, #0x468]
static inline uint64_t fde_func_1951_0x17f294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f294ULL ^ (static_cast<uint64_t>(0x9100050aULL) << 13);
    acc = (acc + a1 + 0xf902370aULL) ^ 0x09ab20ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1952 | PC: 0x17f300 | FDE: 0x09ab88 | Size: 64 bytes
// Khung tháo gỡ #1952 | Địa chỉ PC: 0x17f300 | Địa chỉ FDE: 0x09ab88 | Kích thước: 64 bytes
//   0x17f300: D53BD053  mrs      x19, tpidr_el0
//   0x17f304: F9401668  ldr      x8, [x19, #0x28]
//   0x17f308: 5296D589  mov      w9, #0xb6ac
//   0x17f30c: D65F03C0  ret      
static inline uint64_t fde_func_1952_0x17f300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f300ULL ^ (static_cast<uint64_t>(0xd53bd053ULL) << 13);
    acc = (acc + a1 + 0xf9401668ULL) ^ 0x09ab88ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1953 | PC: 0x17f340 | FDE: 0x09abe8 | Size: 84 bytes
// Khung tháo gỡ #1953 | Địa chỉ PC: 0x17f340 | Địa chỉ FDE: 0x09abe8 | Kích thước: 84 bytes
//   0x17f340: 910083E0  add      x0, sp, #0x20
//   0x17f344: 14002187  b        #0x187960
//   0x17f348: D53BD055  mrs      x21, tpidr_el0
//   0x17f34c: F94016A8  ldr      x8, [x21, #0x28]
static inline uint64_t fde_func_1953_0x17f340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f340ULL ^ (static_cast<uint64_t>(0x910083e0ULL) << 13);
    acc = (acc + a1 + 0x14002187ULL) ^ 0x09abe8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1954 | PC: 0x17f394 | FDE: 0x09ac48 | Size: 96 bytes
// Khung tháo gỡ #1954 | Địa chỉ PC: 0x17f394 | Địa chỉ FDE: 0x09ac48 | Kích thước: 96 bytes
//   0x17f394: D53BD055  mrs      x21, tpidr_el0
//   0x17f398: F94016A8  ldr      x8, [x21, #0x28]
//   0x17f39c: D2EFFE09  mov      x9, #0x7ff0000000000000
//   0x17f3a0: D65F03C0  ret      
static inline uint64_t fde_func_1954_0x17f394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f394ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x09ac48ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1955 | PC: 0x17f3f4 | FDE: 0x09aca8 | Size: 80 bytes
// Khung tháo gỡ #1955 | Địa chỉ PC: 0x17f3f4 | Địa chỉ FDE: 0x09aca8 | Kích thước: 80 bytes
//   0x17f3f4: F9000268  str      x8, [x19]
//   0x17f3f8: 91014108  add      x8, x8, #0x50
//   0x17f3fc: A905FE7F  stp      xzr, xzr, [x19, #0x58]
//   0x17f400: F9000E68  str      x8, [x19, #0x18]
static inline uint64_t fde_func_1955_0x17f3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f3f4ULL ^ (static_cast<uint64_t>(0xf9000268ULL) << 13);
    acc = (acc + a1 + 0x91014108ULL) ^ 0x09aca8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1956 | PC: 0x17f444 | FDE: 0x09ad08 | Size: 68 bytes
// Khung tháo gỡ #1956 | Địa chỉ PC: 0x17f444 | Địa chỉ FDE: 0x09ad08 | Kích thước: 68 bytes
//   0x17f444: D53BD056  mrs      x22, tpidr_el0
//   0x17f448: F94016C8  ldr      x8, [x22, #0x28]
//   0x17f44c: AA0103F4  mov      x20, x1
//   0x17f450: 910023E1  add      x1, sp, #8
static inline uint64_t fde_func_1956_0x17f444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f444ULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x09ad08ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1957 | PC: 0x17f488 | FDE: 0x09ad68 | Size: 64 bytes
// Khung tháo gỡ #1957 | Địa chỉ PC: 0x17f488 | Địa chỉ FDE: 0x09ad68 | Kích thước: 64 bytes
//   0x17f488: F90007E8  str      x8, [sp, #8]
//   0x17f48c: F9000008  str      x8, [x0]
//   0x17f490: 29014C14  stp      w20, w19, [x0, #8]
//   0x17f494: F9000815  str      x21, [x0, #0x10]
static inline uint64_t fde_func_1957_0x17f488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f488ULL ^ (static_cast<uint64_t>(0xf90007e8ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x09ad68ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1958 | PC: 0x17f4c8 | FDE: 0x09adc8 | Size: 88 bytes
// Khung tháo gỡ #1958 | Địa chỉ PC: 0x17f4c8 | Địa chỉ FDE: 0x09adc8 | Kích thước: 88 bytes
//   0x17f4c8: D53BD054  mrs      x20, tpidr_el0
//   0x17f4cc: F9401688  ldr      x8, [x20, #0x28]
//   0x17f4d0: AA0003F3  mov      x19, x0
//   0x17f4d4: 910013E0  add      x0, sp, #4
static inline uint64_t fde_func_1958_0x17f4c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f4c8ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x09adc8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1959 | PC: 0x17f520 | FDE: 0x09ae28 | Size: 104 bytes
// Khung tháo gỡ #1959 | Địa chỉ PC: 0x17f520 | Địa chỉ FDE: 0x09ae28 | Kích thước: 104 bytes
//   0x17f520: 52800021  mov      w1, #1
//   0x17f524: AA1A03E0  mov      x0, x26
//   0x17f528: AA1B03E2  mov      x2, x27
//   0x17f52c: 2A1703E3  mov      w3, w23
static inline uint64_t fde_func_1959_0x17f520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f520ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0xaa1a03e0ULL) ^ 0x09ae28ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1960 | PC: 0x17f588 | FDE: 0x09ae88 | Size: 64 bytes
// Khung tháo gỡ #1960 | Địa chỉ PC: 0x17f588 | Địa chỉ FDE: 0x09ae88 | Kích thước: 64 bytes
//   0x17f588: F9400668  ldr      x8, [x19, #8]
//   0x17f58c: 9100E3E0  add      x0, sp, #0x38
//   0x17f590: F9001FE8  str      x8, [sp, #0x38]
//   0x17f594: D65F03C0  ret      
static inline uint64_t fde_func_1960_0x17f588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f588ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0x9100e3e0ULL) ^ 0x09ae88ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1961 | PC: 0x17f5c8 | FDE: 0x09aee8 | Size: 52 bytes
// Khung tháo gỡ #1961 | Địa chỉ PC: 0x17f5c8 | Địa chỉ FDE: 0x09aee8 | Kích thước: 52 bytes
//   0x17f5c8: F9400668  ldr      x8, [x19, #8]
//   0x17f5cc: 910063E0  add      x0, sp, #0x18
//   0x17f5d0: F9000FE8  str      x8, [sp, #0x18]
//   0x17f5d4: D65F03C0  ret      
static inline uint64_t fde_func_1961_0x17f5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f5c8ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0x910063e0ULL) ^ 0x09aee8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1962 | PC: 0x17f5fc | FDE: 0x09af48 | Size: 60 bytes
// Khung tháo gỡ #1962 | Địa chỉ PC: 0x17f5fc | Địa chỉ FDE: 0x09af48 | Kích thước: 60 bytes
//   0x17f5fc: AA1303E0  mov      x0, x19
//   0x17f600: 2A1703E2  mov      w2, w23
//   0x17f604: 2A1603E3  mov      w3, w22
//   0x17f608: 2A1503E4  mov      w4, w21
static inline uint64_t fde_func_1962_0x17f5fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f5fcULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e2ULL) ^ 0x09af48ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1963 | PC: 0x17f638 | FDE: 0x09afa8 | Size: 48 bytes
// Khung tháo gỡ #1963 | Địa chỉ PC: 0x17f638 | Địa chỉ FDE: 0x09afa8 | Kích thước: 48 bytes
//   0x17f638: AA1303E0  mov      x0, x19
//   0x17f63c: AA1703E1  mov      x1, x23
//   0x17f640: D65F03C0  ret      
//   0x17f644: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1963_0x17f638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f638ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa1703e1ULL) ^ 0x09afa8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1964 | PC: 0x17f668 | FDE: 0x09b008 | Size: 44 bytes
// Khung tháo gỡ #1964 | Địa chỉ PC: 0x17f668 | Địa chỉ FDE: 0x09b008 | Kích thước: 44 bytes
//   0x17f668: AA1303E0  mov      x0, x19
//   0x17f66c: 17FCAE58  b        #0xaafcc
//   0x17f670: AA1303E0  mov      x0, x19
//   0x17f674: 14002017  b        #0x1876d0
static inline uint64_t fde_func_1964_0x17f668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f668ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17fcae58ULL) ^ 0x09b008ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1965 | PC: 0x17f694 | FDE: 0x09b068 | Size: 48 bytes
// Khung tháo gỡ #1965 | Địa chỉ PC: 0x17f694 | Địa chỉ FDE: 0x09b068 | Kích thước: 48 bytes
//   0x17f694: AA1603E0  mov      x0, x22
//   0x17f698: 1400238A  b        #0x1884c0
//   0x17f69c: AA1603E0  mov      x0, x22
//   0x17f6a0: 17FF4510  b        #0x150ae0
static inline uint64_t fde_func_1965_0x17f694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f694ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x1400238aULL) ^ 0x09b068ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1966 | PC: 0x17f6c4 | FDE: 0x09b0c8 | Size: 56 bytes
// Khung tháo gỡ #1966 | Địa chỉ PC: 0x17f6c4 | Địa chỉ FDE: 0x09b0c8 | Kích thước: 56 bytes
//   0x17f6c4: 910043E0  add      x0, sp, #0x10
//   0x17f6c8: 17FCB404  b        #0xac6d8
//   0x17f6cc: F9400268  ldr      x8, [x19]
//   0x17f6d0: F85E8108  ldur     x8, [x8, #-0x18]
static inline uint64_t fde_func_1966_0x17f6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f6c4ULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0x17fcb404ULL) ^ 0x09b0c8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1967 | PC: 0x17f6fc | FDE: 0x09b128 | Size: 52 bytes
// Khung tháo gỡ #1967 | Địa chỉ PC: 0x17f6fc | Địa chỉ FDE: 0x09b128 | Kích thước: 52 bytes
//   0x17f6fc: 910003E0  mov      x0, sp
//   0x17f700: AA1403E1  mov      x1, x20
//   0x17f704: D65F03C0  ret      
//   0x17f708: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1967_0x17f6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f6fcULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x09b128ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1968 | PC: 0x17f730 | FDE: 0x09b188 | Size: 52 bytes
// Khung tháo gỡ #1968 | Địa chỉ PC: 0x17f730 | Địa chỉ FDE: 0x09b188 | Kích thước: 52 bytes
//   0x17f730: AA0003F3  mov      x19, x0
//   0x17f734: B9400000  ldr      w0, [x0]
//   0x17f738: B9400661  ldr      w1, [x19, #4]
//   0x17f73c: F8408E62  ldr      x2, [x19, #8]!
static inline uint64_t fde_func_1968_0x17f730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f730ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xb9400000ULL) ^ 0x09b188ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1969 | PC: 0x17f764 | FDE: 0x09b1e8 | Size: 76 bytes
// Khung tháo gỡ #1969 | Địa chỉ PC: 0x17f764 | Địa chỉ FDE: 0x09b1e8 | Kích thước: 76 bytes
//   0x17f764: AA1403E0  mov      x0, x20
//   0x17f768: F8410415  ldr      x21, [x0], #0x10
//   0x17f76c: D65F03C0  ret      
//   0x17f770: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1969_0x17f764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f764ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0xf8410415ULL) ^ 0x09b1e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1970 | PC: 0x17f7b0 | FDE: 0x09b248 | Size: 64 bytes
// Khung tháo gỡ #1970 | Địa chỉ PC: 0x17f7b0 | Địa chỉ FDE: 0x09b248 | Kích thước: 64 bytes
//   0x17f7b0: AA1403E0  mov      x0, x20
//   0x17f7b4: 2A1703E1  mov      w1, w23
//   0x17f7b8: D65F03C0  ret      
//   0x17f7bc: AA0003E2  mov      x2, x0
static inline uint64_t fde_func_1970_0x17f7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f7b0ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x09b248ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1971 | PC: 0x17f7f0 | FDE: 0x09b2a8 | Size: 44 bytes
// Khung tháo gỡ #1971 | Địa chỉ PC: 0x17f7f0 | Địa chỉ FDE: 0x09b2a8 | Kích thước: 44 bytes
//   0x17f7f0: AA1303E1  mov      x1, x19
//   0x17f7f4: 17FCC768  b        #0xb1594
//   0x17f7f8: 1E60C002  fabs     d2, d0
//   0x17f7fc: 9E670123  fmov     d3, x9
static inline uint64_t fde_func_1971_0x17f7f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f7f0ULL ^ (static_cast<uint64_t>(0xaa1303e1ULL) << 13);
    acc = (acc + a1 + 0x17fcc768ULL) ^ 0x09b2a8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1972 | PC: 0x17f81c | FDE: 0x09b308 | Size: 40 bytes
// Khung tháo gỡ #1972 | Địa chỉ PC: 0x17f81c | Địa chỉ FDE: 0x09b308 | Kích thước: 40 bytes
//   0x17f81c: AA1503E1  mov      x1, x21
//   0x17f820: 14002048  b        #0x187940
//   0x17f824: AA1503E1  mov      x1, x21
//   0x17f828: AA1303E2  mov      x2, x19
static inline uint64_t fde_func_1972_0x17f81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f81cULL ^ (static_cast<uint64_t>(0xaa1503e1ULL) << 13);
    acc = (acc + a1 + 0x14002048ULL) ^ 0x09b308ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1973 | PC: 0x17f844 | FDE: 0x09b368 | Size: 44 bytes
// Khung tháo gỡ #1973 | Địa chỉ PC: 0x17f844 | Địa chỉ FDE: 0x09b368 | Kích thước: 44 bytes
//   0x17f844: 910023E0  add      x0, sp, #8
//   0x17f848: AA1503E1  mov      x1, x21
//   0x17f84c: D65F03C0  ret      
//   0x17f850: AA1603E1  mov      x1, x22
static inline uint64_t fde_func_1973_0x17f844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f844ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0xaa1503e1ULL) ^ 0x09b368ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1974 | PC: 0x17f870 | FDE: 0x09b3c8 | Size: 40 bytes
// Khung tháo gỡ #1974 | Địa chỉ PC: 0x17f870 | Địa chỉ FDE: 0x09b3c8 | Kích thước: 40 bytes
//   0x17f870: AA1503E0  mov      x0, x21
//   0x17f874: 14002417  b        #0x1888d0
//   0x17f878: AA1503E0  mov      x0, x21
//   0x17f87c: 140020FD  b        #0x187c70
static inline uint64_t fde_func_1974_0x17f870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f870ULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x14002417ULL) ^ 0x09b3c8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1975 | PC: 0x17f898 | FDE: 0x09b428 | Size: 104 bytes
// Khung tháo gỡ #1975 | Địa chỉ PC: 0x17f898 | Địa chỉ FDE: 0x09b428 | Kích thước: 104 bytes
//   0x17f898: F94016E8  ldr      x8, [x23, #0x28]
//   0x17f89c: AA0103F5  mov      x21, x1
//   0x17f8a0: AA0003F6  mov      x22, x0
//   0x17f8a4: D65F03C0  ret      
static inline uint64_t fde_func_1975_0x17f898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f898ULL ^ (static_cast<uint64_t>(0xf94016e8ULL) << 13);
    acc = (acc + a1 + 0xaa0103f5ULL) ^ 0x09b428ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1976 | PC: 0x17f900 | FDE: 0x09b490 | Size: 56 bytes
// Khung tháo gỡ #1976 | Địa chỉ PC: 0x17f900 | Địa chỉ FDE: 0x09b490 | Kích thước: 56 bytes
//   0x17f900: D53BD057  mrs      x23, tpidr_el0
//   0x17f904: F94016E8  ldr      x8, [x23, #0x28]
//   0x17f908: F9001FE8  str      x8, [sp, #0x38]
//   0x17f90c: D65F03C0  ret      
static inline uint64_t fde_func_1976_0x17f900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f900ULL ^ (static_cast<uint64_t>(0xd53bd057ULL) << 13);
    acc = (acc + a1 + 0xf94016e8ULL) ^ 0x09b490ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1977 | PC: 0x17f938 | FDE: 0x09b4f0 | Size: 60 bytes
// Khung tháo gỡ #1977 | Địa chỉ PC: 0x17f938 | Địa chỉ FDE: 0x09b4f0 | Kích thước: 60 bytes
//   0x17f938: AA0103F3  mov      x19, x1
//   0x17f93c: F90017E8  str      x8, [sp, #0x28]
//   0x17f940: F9401028  ldr      x8, [x1, #0x20]
//   0x17f944: D65F03C0  ret      
static inline uint64_t fde_func_1977_0x17f938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f938ULL ^ (static_cast<uint64_t>(0xaa0103f3ULL) << 13);
    acc = (acc + a1 + 0xf90017e8ULL) ^ 0x09b4f0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1978 | PC: 0x17f974 | FDE: 0x09b550 | Size: 96 bytes
// Khung tháo gỡ #1978 | Địa chỉ PC: 0x17f974 | Địa chỉ FDE: 0x09b550 | Kích thước: 96 bytes
//   0x17f974: 52B00009  mov      w9, #-0xffffffff80000000
//   0x17f978: EB09011F  cmp      x8, x9
//   0x17f97c: D65F03C0  ret      
//   0x17f980: FC4142E0  ldur     d0, [x23, #0x14]
static inline uint64_t fde_func_1978_0x17f974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f974ULL ^ (static_cast<uint64_t>(0x52b00009ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x09b550ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1979 | PC: 0x17f9d4 | FDE: 0x09b5b0 | Size: 64 bytes
// Khung tháo gỡ #1979 | Địa chỉ PC: 0x17f9d4 | Địa chỉ FDE: 0x09b5b0 | Kích thước: 64 bytes
//   0x17f9d4: F8410D89  ldr      x9, [x12, #0x10]!
//   0x17f9d8: F9400028  ldr      x8, [x1]
//   0x17f9dc: F9400FEB  ldr      x11, [sp, #0x18]
//   0x17f9e0: CB080129  sub      x9, x9, x8
static inline uint64_t fde_func_1979_0x17f9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f9d4ULL ^ (static_cast<uint64_t>(0xf8410d89ULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x09b5b0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1980 | PC: 0x17fa14 | FDE: 0x09b610 | Size: 64 bytes
// Khung tháo gỡ #1980 | Địa chỉ PC: 0x17fa14 | Địa chỉ FDE: 0x09b610 | Kích thước: 64 bytes
//   0x17fa14: B94002E0  ldr      w0, [x23]
//   0x17fa18: 11001273  add      w19, w19, #4
//   0x17fa1c: 17FEB5A0  b        #0x12d09c
//   0x17fa20: B94002E0  ldr      w0, [x23]
static inline uint64_t fde_func_1980_0x17fa14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fa14ULL ^ (static_cast<uint64_t>(0xb94002e0ULL) << 13);
    acc = (acc + a1 + 0x11001273ULL) ^ 0x09b610ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1981 | PC: 0x17fa54 | FDE: 0x09b670 | Size: 56 bytes
// Khung tháo gỡ #1981 | Địa chỉ PC: 0x17fa54 | Địa chỉ FDE: 0x09b670 | Kích thước: 56 bytes
//   0x17fa54: F0FFF5C1  adrp     x1, #0x3a000
//   0x17fa58: 9125D821  add      x1, x1, #0x976
//   0x17fa5c: 17FCA3A6  b        #0xa88f4
//   0x17fa60: D0FFF5C1  adrp     x1, #0x39000
static inline uint64_t fde_func_1981_0x17fa54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fa54ULL ^ (static_cast<uint64_t>(0xf0fff5c1ULL) << 13);
    acc = (acc + a1 + 0x9125d821ULL) ^ 0x09b670ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1982 | PC: 0x17fa8c | FDE: 0x09b6d0 | Size: 56 bytes
// Khung tháo gỡ #1982 | Địa chỉ PC: 0x17fa8c | Địa chỉ FDE: 0x09b6d0 | Kích thước: 56 bytes
//   0x17fa8c: F9402288  ldr      x8, [x20, #0x40]
//   0x17fa90: 9103A3E0  add      x0, sp, #0xe8
//   0x17fa94: 9100E3F4  add      x20, sp, #0x38
//   0x17fa98: F9001BE8  str      x8, [sp, #0x30]
static inline uint64_t fde_func_1982_0x17fa8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fa8cULL ^ (static_cast<uint64_t>(0xf9402288ULL) << 13);
    acc = (acc + a1 + 0x9103a3e0ULL) ^ 0x09b6d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1983 | PC: 0x17fac4 | FDE: 0x09b730 | Size: 44 bytes
// Khung tháo gỡ #1983 | Địa chỉ PC: 0x17fac4 | Địa chỉ FDE: 0x09b730 | Kích thước: 44 bytes
//   0x17fac4: F9401A60  ldr      x0, [x19, #0x30]
//   0x17fac8: 17FD1DCE  b        #0xc7200
//   0x17facc: 91020000  add      x0, x0, #0x80
//   0x17fad0: 91030042  add      x2, x2, #0xc0
static inline uint64_t fde_func_1983_0x17fac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fac4ULL ^ (static_cast<uint64_t>(0xf9401a60ULL) << 13);
    acc = (acc + a1 + 0x17fd1dceULL) ^ 0x09b730ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1984 | PC: 0x17faf0 | FDE: 0x09b790 | Size: 56 bytes
// Khung tháo gỡ #1984 | Địa chỉ PC: 0x17faf0 | Địa chỉ FDE: 0x09b790 | Kích thước: 56 bytes
//   0x17faf0: F940BBE8  ldr      x8, [sp, #0x170]
//   0x17faf4: F8777908  ldr      x8, [x8, x23, lsl #3]
//   0x17faf8: D65F03C0  ret      
//   0x17fafc: 90FFF5AB  adrp     x11, #0x33000
static inline uint64_t fde_func_1984_0x17faf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17faf0ULL ^ (static_cast<uint64_t>(0xf940bbe8ULL) << 13);
    acc = (acc + a1 + 0xf8777908ULL) ^ 0x09b790ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1985 | PC: 0x17fb28 | FDE: 0x09b7f0 | Size: 80 bytes
// Khung tháo gỡ #1985 | Địa chỉ PC: 0x17fb28 | Địa chỉ FDE: 0x09b7f0 | Kích thước: 80 bytes
//   0x17fb28: F9401A94  ldr      x20, [x20, #0x30]
//   0x17fb2c: 910003E0  mov      x0, sp
//   0x17fb30: AA1303E1  mov      x1, x19
//   0x17fb34: AA1403E2  mov      x2, x20
static inline uint64_t fde_func_1985_0x17fb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fb28ULL ^ (static_cast<uint64_t>(0xf9401a94ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x09b7f0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1986 | PC: 0x17fb78 | FDE: 0x09b850 | Size: 76 bytes
// Khung tháo gỡ #1986 | Địa chỉ PC: 0x17fb78 | Địa chỉ FDE: 0x09b850 | Kích thước: 76 bytes
//   0x17fb78: F9001BE8  str      x8, [sp, #0x30]
//   0x17fb7c: 14002791  b        #0x1899c0
//   0x17fb80: 3DC00100  ldr      q0, [x8]
//   0x17fb84: F9400908  ldr      x8, [x8, #0x10]
static inline uint64_t fde_func_1986_0x17fb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fb78ULL ^ (static_cast<uint64_t>(0xf9001be8ULL) << 13);
    acc = (acc + a1 + 0x14002791ULL) ^ 0x09b850ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1987 | PC: 0x17fbc4 | FDE: 0x09b8b0 | Size: 88 bytes
// Khung tháo gỡ #1987 | Địa chỉ PC: 0x17fbc4 | Địa chỉ FDE: 0x09b8b0 | Kích thước: 88 bytes
//   0x17fbc4: 9AD80909  udiv     x9, x8, x24
//   0x17fbc8: 9B18A128  msub     x8, x9, x24, x8
//   0x17fbcc: D65F03C0  ret      
//   0x17fbd0: 52852028  mov      w8, #0x2901
static inline uint64_t fde_func_1987_0x17fbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fbc4ULL ^ (static_cast<uint64_t>(0x9ad80909ULL) << 13);
    acc = (acc + a1 + 0x9b18a128ULL) ^ 0x09b8b0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1988 | PC: 0x17fc1c | FDE: 0x09b910 | Size: 68 bytes
// Khung tháo gỡ #1988 | Địa chỉ PC: 0x17fc1c | Địa chỉ FDE: 0x09b910 | Kích thước: 68 bytes
//   0x17fc1c: B0FFF5C1  adrp     x1, #0x38000
//   0x17fc20: 91190021  add      x1, x1, #0x640
//   0x17fc24: 910063E0  add      x0, sp, #0x18
//   0x17fc28: 910003E2  mov      x2, sp
static inline uint64_t fde_func_1988_0x17fc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fc1cULL ^ (static_cast<uint64_t>(0xb0fff5c1ULL) << 13);
    acc = (acc + a1 + 0x91190021ULL) ^ 0x09b910ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1989 | PC: 0x17fc60 | FDE: 0x09b970 | Size: 60 bytes
// Khung tháo gỡ #1989 | Địa chỉ PC: 0x17fc60 | Địa chỉ FDE: 0x09b970 | Kích thước: 60 bytes
//   0x17fc60: F9400D29  ldr      x9, [x9, #0x18]
//   0x17fc64: D61F0120  br       x9
//   0x17fc68: A940A3E0  ldp      x0, x8, [sp, #8]
//   0x17fc6c: A903A3E0  stp      x0, x8, [sp, #0x38]
static inline uint64_t fde_func_1989_0x17fc60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fc60ULL ^ (static_cast<uint64_t>(0xf9400d29ULL) << 13);
    acc = (acc + a1 + 0xd61f0120ULL) ^ 0x09b970ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1990 | PC: 0x17fc9c | FDE: 0x09b9d0 | Size: 52 bytes
// Khung tháo gỡ #1990 | Địa chỉ PC: 0x17fc9c | Địa chỉ FDE: 0x09b9d0 | Kích thước: 52 bytes
//   0x17fc9c: 910503E0  add      x0, sp, #0x140
//   0x17fca0: 910603E1  add      x1, sp, #0x180
//   0x17fca4: 14002303  b        #0x1888b0
//   0x17fca8: 5291A800  mov      w0, #0x8d40
static inline uint64_t fde_func_1990_0x17fc9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fc9cULL ^ (static_cast<uint64_t>(0x910503e0ULL) << 13);
    acc = (acc + a1 + 0x910603e1ULL) ^ 0x09b9d0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1991 | PC: 0x17fcd0 | FDE: 0x09ba30 | Size: 60 bytes
// Khung tháo gỡ #1991 | Địa chỉ PC: 0x17fcd0 | Địa chỉ FDE: 0x09ba30 | Kích thước: 60 bytes
//   0x17fcd0: 39400C03  ldrb     w3, [x0, #3]
//   0x17fcd4: 39400802  ldrb     w2, [x0, #2]
//   0x17fcd8: 39400401  ldrb     w1, [x0, #1]
//   0x17fcdc: 39400000  ldrb     w0, [x0]
static inline uint64_t fde_func_1991_0x17fcd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fcd0ULL ^ (static_cast<uint64_t>(0x39400c03ULL) << 13);
    acc = (acc + a1 + 0x39400802ULL) ^ 0x09ba30ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1992 | PC: 0x17fd0c | FDE: 0x09ba90 | Size: 72 bytes
// Khung tháo gỡ #1992 | Địa chỉ PC: 0x17fd0c | Địa chỉ FDE: 0x09ba90 | Kích thước: 72 bytes
//   0x17fd0c: 9ADB0D08  sdiv     x8, x8, x27
//   0x17fd10: 8B081281  add      x1, x20, x8, lsl #4
//   0x17fd14: 8B0812C3  add      x3, x22, x8, lsl #4
//   0x17fd18: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1992_0x17fd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fd0cULL ^ (static_cast<uint64_t>(0x9adb0d08ULL) << 13);
    acc = (acc + a1 + 0x8b081281ULL) ^ 0x09ba90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1993 | PC: 0x17fd54 | FDE: 0x09baf0 | Size: 84 bytes
// Khung tháo gỡ #1993 | Địa chỉ PC: 0x17fd54 | Địa chỉ FDE: 0x09baf0 | Kích thước: 84 bytes
//   0x17fd54: F9401E95  ldr      x21, [x20, #0x38]
//   0x17fd58: 910043E8  add      x8, sp, #0x10
//   0x17fd5c: 9100A3E0  add      x0, sp, #0x28
//   0x17fd60: 910043F4  add      x20, sp, #0x10
static inline uint64_t fde_func_1993_0x17fd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fd54ULL ^ (static_cast<uint64_t>(0xf9401e95ULL) << 13);
    acc = (acc + a1 + 0x910043e8ULL) ^ 0x09baf0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1994 | PC: 0x17fda8 | FDE: 0x09bb50 | Size: 64 bytes
// Khung tháo gỡ #1994 | Địa chỉ PC: 0x17fda8 | Địa chỉ FDE: 0x09bb50 | Kích thước: 64 bytes
//   0x17fda8: F90003E9  str      x9, [sp]
//   0x17fdac: F9400009  ldr      x9, [x0]
//   0x17fdb0: 91002101  add      x1, x8, #8
//   0x17fdb4: F9401129  ldr      x9, [x9, #0x20]
static inline uint64_t fde_func_1994_0x17fda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fda8ULL ^ (static_cast<uint64_t>(0xf90003e9ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x09bb50ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1995 | PC: 0x17fde8 | FDE: 0x09bbb0 | Size: 72 bytes
// Khung tháo gỡ #1995 | Địa chỉ PC: 0x17fde8 | Địa chỉ FDE: 0x09bbb0 | Kích thước: 72 bytes
//   0x17fde8: A95B53F5  ldp      x21, x20, [sp, #0x1b0]
//   0x17fdec: A95A5BF7  ldp      x23, x22, [sp, #0x1a0]
//   0x17fdf0: F940CBFC  ldr      x28, [sp, #0x190]
//   0x17fdf4: 910743FF  add      sp, sp, #0x1d0
static inline uint64_t fde_func_1995_0x17fde8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fde8ULL ^ (static_cast<uint64_t>(0xa95b53f5ULL) << 13);
    acc = (acc + a1 + 0xa95a5bf7ULL) ^ 0x09bbb0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1996 | PC: 0x17fe30 | FDE: 0x09bc10 | Size: 80 bytes
// Khung tháo gỡ #1996 | Địa chỉ PC: 0x17fe30 | Địa chỉ FDE: 0x09bc10 | Kích thước: 80 bytes
//   0x17fe30: 3CC0C381  ldur     q1, [x28, #0xc]
//   0x17fe34: 3CC1C382  ldur     q2, [x28, #0x1c]
//   0x17fe38: 3CC2C383  ldur     q3, [x28, #0x2c]
//   0x17fe3c: F9485BE8  ldr      x8, [sp, #0x10b0]
static inline uint64_t fde_func_1996_0x17fe30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fe30ULL ^ (static_cast<uint64_t>(0x3cc0c381ULL) << 13);
    acc = (acc + a1 + 0x3cc1c382ULL) ^ 0x09bc10ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1997 | PC: 0x17fe80 | FDE: 0x09bc70 | Size: 60 bytes
// Khung tháo gỡ #1997 | Địa chỉ PC: 0x17fe80 | Địa chỉ FDE: 0x09bc70 | Kích thước: 60 bytes
//   0x17fe80: 91057C21  add      x1, x1, #0x15f
//   0x17fe84: 9100A3E0  add      x0, sp, #0x28
//   0x17fe88: D65F03C0  ret      
//   0x17fe8c: 9106C3E0  add      x0, sp, #0x1b0
static inline uint64_t fde_func_1997_0x17fe80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fe80ULL ^ (static_cast<uint64_t>(0x91057c21ULL) << 13);
    acc = (acc + a1 + 0x9100a3e0ULL) ^ 0x09bc70ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1998 | PC: 0x17febc | FDE: 0x09bcd0 | Size: 88 bytes
// Khung tháo gỡ #1998 | Địa chỉ PC: 0x17febc | Địa chỉ FDE: 0x09bcd0 | Kích thước: 88 bytes
//   0x17febc: F9487BEB  ldr      x11, [sp, #0x10f0]
//   0x17fec0: 29408AC1  ldp      w1, w2, [x22, #4]
//   0x17fec4: 294192C3  ldp      w3, w4, [x22, #0xc]
//   0x17fec8: 29429AC5  ldp      w5, w6, [x22, #0x14]
static inline uint64_t fde_func_1998_0x17febc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17febcULL ^ (static_cast<uint64_t>(0xf9487bebULL) << 13);
    acc = (acc + a1 + 0x29408ac1ULL) ^ 0x09bcd0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1999 | PC: 0x17ff14 | FDE: 0x09bd30 | Size: 256 bytes
// Khung tháo gỡ #1999 | Địa chỉ PC: 0x17ff14 | Địa chỉ FDE: 0x09bd30 | Kích thước: 256 bytes
//   0x17ff14: 910483E0  add      x0, sp, #0x120
//   0x17ff18: 14001DAA  b        #0x1875c0
//   0x17ff1c: B9409508  ldr      w8, [x8, #0x94]
//   0x17ff20: 7E61D808  ucvtf    d8, d0
static inline uint64_t fde_func_1999_0x17ff14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ff14ULL ^ (static_cast<uint64_t>(0x910483e0ULL) << 13);
    acc = (acc + a1 + 0x14001daaULL) ^ 0x09bd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1600: return fde_func_1600_0x178a9c(a0, a1);
        case 1601: return fde_func_1601_0x178ac8(a0, a1);
        case 1602: return fde_func_1602_0x178b10(a0, a1);
        case 1603: return fde_func_1603_0x178bc0(a0, a1);
        case 1604: return fde_func_1604_0x178c6c(a0, a1);
        case 1605: return fde_func_1605_0x178c94(a0, a1);
        case 1606: return fde_func_1606_0x178cd8(a0, a1);
        case 1607: return fde_func_1607_0x178d08(a0, a1);
        case 1608: return fde_func_1608_0x178d28(a0, a1);
        case 1609: return fde_func_1609_0x178d70(a0, a1);
        case 1610: return fde_func_1610_0x178da0(a0, a1);
        case 1611: return fde_func_1611_0x178de4(a0, a1);
        case 1612: return fde_func_1612_0x178e68(a0, a1);
        case 1613: return fde_func_1613_0x178eb0(a0, a1);
        case 1614: return fde_func_1614_0x178ee8(a0, a1);
        case 1615: return fde_func_1615_0x178f48(a0, a1);
        case 1616: return fde_func_1616_0x178fc0(a0, a1);
        case 1617: return fde_func_1617_0x179000(a0, a1);
        case 1618: return fde_func_1618_0x179048(a0, a1);
        case 1619: return fde_func_1619_0x179084(a0, a1);
        case 1620: return fde_func_1620_0x1790c8(a0, a1);
        case 1621: return fde_func_1621_0x179110(a0, a1);
        case 1622: return fde_func_1622_0x179188(a0, a1);
        case 1623: return fde_func_1623_0x1791d8(a0, a1);
        case 1624: return fde_func_1624_0x179220(a0, a1);
        case 1625: return fde_func_1625_0x179270(a0, a1);
        case 1626: return fde_func_1626_0x1792cc(a0, a1);
        case 1627: return fde_func_1627_0x179344(a0, a1);
        case 1628: return fde_func_1628_0x179384(a0, a1);
        case 1629: return fde_func_1629_0x1793d8(a0, a1);
        case 1630: return fde_func_1630_0x179418(a0, a1);
        case 1631: return fde_func_1631_0x179480(a0, a1);
        case 1632: return fde_func_1632_0x1794c4(a0, a1);
        case 1633: return fde_func_1633_0x179538(a0, a1);
        case 1634: return fde_func_1634_0x1795bc(a0, a1);
        case 1635: return fde_func_1635_0x17960c(a0, a1);
        case 1636: return fde_func_1636_0x179668(a0, a1);
        case 1637: return fde_func_1637_0x1796d8(a0, a1);
        case 1638: return fde_func_1638_0x179740(a0, a1);
        case 1639: return fde_func_1639_0x17976c(a0, a1);
        case 1640: return fde_func_1640_0x1797b8(a0, a1);
        case 1641: return fde_func_1641_0x179800(a0, a1);
        case 1642: return fde_func_1642_0x179840(a0, a1);
        case 1643: return fde_func_1643_0x179890(a0, a1);
        case 1644: return fde_func_1644_0x179900(a0, a1);
        case 1645: return fde_func_1645_0x179940(a0, a1);
        case 1646: return fde_func_1646_0x1799c0(a0, a1);
        case 1647: return fde_func_1647_0x179a18(a0, a1);
        case 1648: return fde_func_1648_0x179a6c(a0, a1);
        case 1649: return fde_func_1649_0x179aa8(a0, a1);
        case 1650: return fde_func_1650_0x179ad0(a0, a1);
        case 1651: return fde_func_1651_0x179b38(a0, a1);
        case 1652: return fde_func_1652_0x179bd0(a0, a1);
        case 1653: return fde_func_1653_0x179c0c(a0, a1);
        case 1654: return fde_func_1654_0x179c6c(a0, a1);
        case 1655: return fde_func_1655_0x179cc0(a0, a1);
        case 1656: return fde_func_1656_0x179d00(a0, a1);
        case 1657: return fde_func_1657_0x179d70(a0, a1);
        case 1658: return fde_func_1658_0x179dc4(a0, a1);
        case 1659: return fde_func_1659_0x179e34(a0, a1);
        case 1660: return fde_func_1660_0x179e88(a0, a1);
        case 1661: return fde_func_1661_0x179f0c(a0, a1);
        case 1662: return fde_func_1662_0x179f48(a0, a1);
        case 1663: return fde_func_1663_0x179f84(a0, a1);
        case 1664: return fde_func_1664_0x179fac(a0, a1);
        case 1665: return fde_func_1665_0x17a02c(a0, a1);
        case 1666: return fde_func_1666_0x17a080(a0, a1);
        case 1667: return fde_func_1667_0x17a0a8(a0, a1);
        case 1668: return fde_func_1668_0x17a0d4(a0, a1);
        case 1669: return fde_func_1669_0x17a124(a0, a1);
        case 1670: return fde_func_1670_0x17a164(a0, a1);
        case 1671: return fde_func_1671_0x17a1a4(a0, a1);
        case 1672: return fde_func_1672_0x17a20c(a0, a1);
        case 1673: return fde_func_1673_0x17a244(a0, a1);
        case 1674: return fde_func_1674_0x17a270(a0, a1);
        case 1675: return fde_func_1675_0x17a2a0(a0, a1);
        case 1676: return fde_func_1676_0x17a2e0(a0, a1);
        case 1677: return fde_func_1677_0x17a320(a0, a1);
        case 1678: return fde_func_1678_0x17a36c(a0, a1);
        case 1679: return fde_func_1679_0x17a3b4(a0, a1);
        case 1680: return fde_func_1680_0x17a410(a0, a1);
        case 1681: return fde_func_1681_0x17a478(a0, a1);
        case 1682: return fde_func_1682_0x17a4d0(a0, a1);
        case 1683: return fde_func_1683_0x17a520(a0, a1);
        case 1684: return fde_func_1684_0x17a580(a0, a1);
        case 1685: return fde_func_1685_0x17a620(a0, a1);
        case 1686: return fde_func_1686_0x17a660(a0, a1);
        case 1687: return fde_func_1687_0x17a690(a0, a1);
        case 1688: return fde_func_1688_0x17a6c8(a0, a1);
        case 1689: return fde_func_1689_0x17a6fc(a0, a1);
        case 1690: return fde_func_1690_0x17a73c(a0, a1);
        case 1691: return fde_func_1691_0x17a76c(a0, a1);
        case 1692: return fde_func_1692_0x17a7b8(a0, a1);
        case 1693: return fde_func_1693_0x17a800(a0, a1);
        case 1694: return fde_func_1694_0x17a87c(a0, a1);
        case 1695: return fde_func_1695_0x17a8a0(a0, a1);
        case 1696: return fde_func_1696_0x17a8d0(a0, a1);
        case 1697: return fde_func_1697_0x17a90c(a0, a1);
        case 1698: return fde_func_1698_0x17a964(a0, a1);
        case 1699: return fde_func_1699_0x17a9b4(a0, a1);
        case 1700: return fde_func_1700_0x17a9ec(a0, a1);
        case 1701: return fde_func_1701_0x17aa44(a0, a1);
        case 1702: return fde_func_1702_0x17aad0(a0, a1);
        case 1703: return fde_func_1703_0x17ab0c(a0, a1);
        case 1704: return fde_func_1704_0x17ab68(a0, a1);
        case 1705: return fde_func_1705_0x17abb8(a0, a1);
        case 1706: return fde_func_1706_0x17abf4(a0, a1);
        case 1707: return fde_func_1707_0x17ac20(a0, a1);
        case 1708: return fde_func_1708_0x17ac78(a0, a1);
        case 1709: return fde_func_1709_0x17ac98(a0, a1);
        case 1710: return fde_func_1710_0x17acc0(a0, a1);
        case 1711: return fde_func_1711_0x17ad00(a0, a1);
        case 1712: return fde_func_1712_0x17ad64(a0, a1);
        case 1713: return fde_func_1713_0x17ad94(a0, a1);
        case 1714: return fde_func_1714_0x17addc(a0, a1);
        case 1715: return fde_func_1715_0x17ae20(a0, a1);
        case 1716: return fde_func_1716_0x17ae50(a0, a1);
        case 1717: return fde_func_1717_0x17ae80(a0, a1);
        case 1718: return fde_func_1718_0x17aedc(a0, a1);
        case 1719: return fde_func_1719_0x17af0c(a0, a1);
        case 1720: return fde_func_1720_0x17af4c(a0, a1);
        case 1721: return fde_func_1721_0x17afb0(a0, a1);
        case 1722: return fde_func_1722_0x17aff4(a0, a1);
        case 1723: return fde_func_1723_0x17b034(a0, a1);
        case 1724: return fde_func_1724_0x17b098(a0, a1);
        case 1725: return fde_func_1725_0x17b0f0(a0, a1);
        case 1726: return fde_func_1726_0x17b130(a0, a1);
        case 1727: return fde_func_1727_0x17b18c(a0, a1);
        case 1728: return fde_func_1728_0x17b1f4(a0, a1);
        case 1729: return fde_func_1729_0x17b260(a0, a1);
        case 1730: return fde_func_1730_0x17b2a4(a0, a1);
        case 1731: return fde_func_1731_0x17b324(a0, a1);
        case 1732: return fde_func_1732_0x17b360(a0, a1);
        case 1733: return fde_func_1733_0x17b3b0(a0, a1);
        case 1734: return fde_func_1734_0x17b414(a0, a1);
        case 1735: return fde_func_1735_0x17b470(a0, a1);
        case 1736: return fde_func_1736_0x17b4ac(a0, a1);
        case 1737: return fde_func_1737_0x17b4d8(a0, a1);
        case 1738: return fde_func_1738_0x17b518(a0, a1);
        case 1739: return fde_func_1739_0x17b550(a0, a1);
        case 1740: return fde_func_1740_0x17b5b4(a0, a1);
        case 1741: return fde_func_1741_0x17b5e8(a0, a1);
        case 1742: return fde_func_1742_0x17b65c(a0, a1);
        case 1743: return fde_func_1743_0x17b694(a0, a1);
        case 1744: return fde_func_1744_0x17b6e0(a0, a1);
        case 1745: return fde_func_1745_0x17b758(a0, a1);
        case 1746: return fde_func_1746_0x17b7b0(a0, a1);
        case 1747: return fde_func_1747_0x17b7e8(a0, a1);
        case 1748: return fde_func_1748_0x17b814(a0, a1);
        case 1749: return fde_func_1749_0x17b83c(a0, a1);
        case 1750: return fde_func_1750_0x17b88c(a0, a1);
        case 1751: return fde_func_1751_0x17b8fc(a0, a1);
        case 1752: return fde_func_1752_0x17b95c(a0, a1);
        case 1753: return fde_func_1753_0x17b994(a0, a1);
        case 1754: return fde_func_1754_0x17b9d4(a0, a1);
        case 1755: return fde_func_1755_0x17ba1c(a0, a1);
        case 1756: return fde_func_1756_0x17ba54(a0, a1);
        case 1757: return fde_func_1757_0x17ba90(a0, a1);
        case 1758: return fde_func_1758_0x17bac8(a0, a1);
        case 1759: return fde_func_1759_0x17bb04(a0, a1);
        case 1760: return fde_func_1760_0x17bb5c(a0, a1);
        case 1761: return fde_func_1761_0x17bbdc(a0, a1);
        case 1762: return fde_func_1762_0x17bc0c(a0, a1);
        case 1763: return fde_func_1763_0x17bca4(a0, a1);
        case 1764: return fde_func_1764_0x17bcdc(a0, a1);
        case 1765: return fde_func_1765_0x17bd24(a0, a1);
        case 1766: return fde_func_1766_0x17bd70(a0, a1);
        case 1767: return fde_func_1767_0x17bdcc(a0, a1);
        case 1768: return fde_func_1768_0x17bdf8(a0, a1);
        case 1769: return fde_func_1769_0x17be40(a0, a1);
        case 1770: return fde_func_1770_0x17be90(a0, a1);
        case 1771: return fde_func_1771_0x17bed8(a0, a1);
        case 1772: return fde_func_1772_0x17bf08(a0, a1);
        case 1773: return fde_func_1773_0x17bf58(a0, a1);
        case 1774: return fde_func_1774_0x17bf9c(a0, a1);
        case 1775: return fde_func_1775_0x17bfc0(a0, a1);
        case 1776: return fde_func_1776_0x17bfe8(a0, a1);
        case 1777: return fde_func_1777_0x17c034(a0, a1);
        case 1778: return fde_func_1778_0x17c078(a0, a1);
        case 1779: return fde_func_1779_0x17c0c0(a0, a1);
        case 1780: return fde_func_1780_0x17c0f8(a0, a1);
        case 1781: return fde_func_1781_0x17c138(a0, a1);
        case 1782: return fde_func_1782_0x17c16c(a0, a1);
        case 1783: return fde_func_1783_0x17c1e0(a0, a1);
        case 1784: return fde_func_1784_0x17c228(a0, a1);
        case 1785: return fde_func_1785_0x17c26c(a0, a1);
        case 1786: return fde_func_1786_0x17c2a4(a0, a1);
        case 1787: return fde_func_1787_0x17c2d0(a0, a1);
        case 1788: return fde_func_1788_0x17c300(a0, a1);
        case 1789: return fde_func_1789_0x17c32c(a0, a1);
        case 1790: return fde_func_1790_0x17c364(a0, a1);
        case 1791: return fde_func_1791_0x17c3b4(a0, a1);
        case 1792: return fde_func_1792_0x17c3e0(a0, a1);
        case 1793: return fde_func_1793_0x17c408(a0, a1);
        case 1794: return fde_func_1794_0x17c434(a0, a1);
        case 1795: return fde_func_1795_0x17c474(a0, a1);
        case 1796: return fde_func_1796_0x17c4b0(a0, a1);
        case 1797: return fde_func_1797_0x17c528(a0, a1);
        case 1798: return fde_func_1798_0x17c580(a0, a1);
        case 1799: return fde_func_1799_0x17c5b8(a0, a1);
        case 1800: return fde_func_1800_0x17c604(a0, a1);
        case 1801: return fde_func_1801_0x17c644(a0, a1);
        case 1802: return fde_func_1802_0x17c6b4(a0, a1);
        case 1803: return fde_func_1803_0x17c73c(a0, a1);
        case 1804: return fde_func_1804_0x17c7ac(a0, a1);
        case 1805: return fde_func_1805_0x17c814(a0, a1);
        case 1806: return fde_func_1806_0x17c86c(a0, a1);
        case 1807: return fde_func_1807_0x17c8c8(a0, a1);
        case 1808: return fde_func_1808_0x17c924(a0, a1);
        case 1809: return fde_func_1809_0x17c960(a0, a1);
        case 1810: return fde_func_1810_0x17c99c(a0, a1);
        case 1811: return fde_func_1811_0x17ca24(a0, a1);
        case 1812: return fde_func_1812_0x17ca78(a0, a1);
        case 1813: return fde_func_1813_0x17caf0(a0, a1);
        case 1814: return fde_func_1814_0x17cb20(a0, a1);
        case 1815: return fde_func_1815_0x17cb88(a0, a1);
        case 1816: return fde_func_1816_0x17cbe0(a0, a1);
        case 1817: return fde_func_1817_0x17cc50(a0, a1);
        case 1818: return fde_func_1818_0x17cc8c(a0, a1);
        case 1819: return fde_func_1819_0x17cccc(a0, a1);
        case 1820: return fde_func_1820_0x17cd28(a0, a1);
        case 1821: return fde_func_1821_0x17cd98(a0, a1);
        case 1822: return fde_func_1822_0x17cdc8(a0, a1);
        case 1823: return fde_func_1823_0x17ce30(a0, a1);
        case 1824: return fde_func_1824_0x17ce94(a0, a1);
        case 1825: return fde_func_1825_0x17ced0(a0, a1);
        case 1826: return fde_func_1826_0x17cf34(a0, a1);
        case 1827: return fde_func_1827_0x17cf84(a0, a1);
        case 1828: return fde_func_1828_0x17cfcc(a0, a1);
        case 1829: return fde_func_1829_0x17d01c(a0, a1);
        case 1830: return fde_func_1830_0x17d084(a0, a1);
        case 1831: return fde_func_1831_0x17d0a8(a0, a1);
        case 1832: return fde_func_1832_0x17d0cc(a0, a1);
        case 1833: return fde_func_1833_0x17d14c(a0, a1);
        case 1834: return fde_func_1834_0x17d1b4(a0, a1);
        case 1835: return fde_func_1835_0x17d1f8(a0, a1);
        case 1836: return fde_func_1836_0x17d224(a0, a1);
        case 1837: return fde_func_1837_0x17d268(a0, a1);
        case 1838: return fde_func_1838_0x17d2a0(a0, a1);
        case 1839: return fde_func_1839_0x17d2f4(a0, a1);
        case 1840: return fde_func_1840_0x17d340(a0, a1);
        case 1841: return fde_func_1841_0x17d38c(a0, a1);
        case 1842: return fde_func_1842_0x17d3b0(a0, a1);
        case 1843: return fde_func_1843_0x17d3e4(a0, a1);
        case 1844: return fde_func_1844_0x17d43c(a0, a1);
        case 1845: return fde_func_1845_0x17d4ac(a0, a1);
        case 1846: return fde_func_1846_0x17d50c(a0, a1);
        case 1847: return fde_func_1847_0x17d540(a0, a1);
        case 1848: return fde_func_1848_0x17d580(a0, a1);
        case 1849: return fde_func_1849_0x17d5d8(a0, a1);
        case 1850: return fde_func_1850_0x17d624(a0, a1);
        case 1851: return fde_func_1851_0x17d674(a0, a1);
        case 1852: return fde_func_1852_0x17d6a8(a0, a1);
        case 1853: return fde_func_1853_0x17d6e4(a0, a1);
        case 1854: return fde_func_1854_0x17d740(a0, a1);
        case 1855: return fde_func_1855_0x17d770(a0, a1);
        case 1856: return fde_func_1856_0x17d7c0(a0, a1);
        case 1857: return fde_func_1857_0x17d814(a0, a1);
        case 1858: return fde_func_1858_0x17d870(a0, a1);
        case 1859: return fde_func_1859_0x17d8ac(a0, a1);
        case 1860: return fde_func_1860_0x17d910(a0, a1);
        case 1861: return fde_func_1861_0x17d980(a0, a1);
        case 1862: return fde_func_1862_0x17d9d8(a0, a1);
        case 1863: return fde_func_1863_0x17da0c(a0, a1);
        case 1864: return fde_func_1864_0x17da44(a0, a1);
        case 1865: return fde_func_1865_0x17da70(a0, a1);
        case 1866: return fde_func_1866_0x17dabc(a0, a1);
        case 1867: return fde_func_1867_0x17daf0(a0, a1);
        case 1868: return fde_func_1868_0x17db14(a0, a1);
        case 1869: return fde_func_1869_0x17db4c(a0, a1);
        case 1870: return fde_func_1870_0x17db90(a0, a1);
        case 1871: return fde_func_1871_0x17dbd0(a0, a1);
        case 1872: return fde_func_1872_0x17dc08(a0, a1);
        case 1873: return fde_func_1873_0x17dc40(a0, a1);
        case 1874: return fde_func_1874_0x17dc78(a0, a1);
        case 1875: return fde_func_1875_0x17dcb4(a0, a1);
        case 1876: return fde_func_1876_0x17dd0c(a0, a1);
        case 1877: return fde_func_1877_0x17dd54(a0, a1);
        case 1878: return fde_func_1878_0x17dd90(a0, a1);
        case 1879: return fde_func_1879_0x17ddf8(a0, a1);
        case 1880: return fde_func_1880_0x17de3c(a0, a1);
        case 1881: return fde_func_1881_0x17de6c(a0, a1);
        case 1882: return fde_func_1882_0x17deb4(a0, a1);
        case 1883: return fde_func_1883_0x17def0(a0, a1);
        case 1884: return fde_func_1884_0x17df2c(a0, a1);
        case 1885: return fde_func_1885_0x17df58(a0, a1);
        case 1886: return fde_func_1886_0x17df80(a0, a1);
        case 1887: return fde_func_1887_0x17dfc0(a0, a1);
        case 1888: return fde_func_1888_0x17dff8(a0, a1);
        case 1889: return fde_func_1889_0x17e020(a0, a1);
        case 1890: return fde_func_1890_0x17e078(a0, a1);
        case 1891: return fde_func_1891_0x17e0c0(a0, a1);
        case 1892: return fde_func_1892_0x17e0f8(a0, a1);
        case 1893: return fde_func_1893_0x17e134(a0, a1);
        case 1894: return fde_func_1894_0x17e170(a0, a1);
        case 1895: return fde_func_1895_0x17e1d0(a0, a1);
        case 1896: return fde_func_1896_0x17e220(a0, a1);
        case 1897: return fde_func_1897_0x17e260(a0, a1);
        case 1898: return fde_func_1898_0x17e2bc(a0, a1);
        case 1899: return fde_func_1899_0x17e31c(a0, a1);
        case 1900: return fde_func_1900_0x17e370(a0, a1);
        case 1901: return fde_func_1901_0x17e3a0(a0, a1);
        case 1902: return fde_func_1902_0x17e3d4(a0, a1);
        case 1903: return fde_func_1903_0x17e420(a0, a1);
        case 1904: return fde_func_1904_0x17e464(a0, a1);
        case 1905: return fde_func_1905_0x17e4c0(a0, a1);
        case 1906: return fde_func_1906_0x17e518(a0, a1);
        case 1907: return fde_func_1907_0x17e564(a0, a1);
        case 1908: return fde_func_1908_0x17e5c4(a0, a1);
        case 1909: return fde_func_1909_0x17e620(a0, a1);
        case 1910: return fde_func_1910_0x17e680(a0, a1);
        case 1911: return fde_func_1911_0x17e6c4(a0, a1);
        case 1912: return fde_func_1912_0x17e724(a0, a1);
        case 1913: return fde_func_1913_0x17e774(a0, a1);
        case 1914: return fde_func_1914_0x17e7f4(a0, a1);
        case 1915: return fde_func_1915_0x17e840(a0, a1);
        case 1916: return fde_func_1916_0x17e884(a0, a1);
        case 1917: return fde_func_1917_0x17e904(a0, a1);
        case 1918: return fde_func_1918_0x17e964(a0, a1);
        case 1919: return fde_func_1919_0x17e9b8(a0, a1);
        case 1920: return fde_func_1920_0x17ea0c(a0, a1);
        case 1921: return fde_func_1921_0x17ea58(a0, a1);
        case 1922: return fde_func_1922_0x17ea94(a0, a1);
        case 1923: return fde_func_1923_0x17eae0(a0, a1);
        case 1924: return fde_func_1924_0x17eb2c(a0, a1);
        case 1925: return fde_func_1925_0x17eb74(a0, a1);
        case 1926: return fde_func_1926_0x17ebc4(a0, a1);
        case 1927: return fde_func_1927_0x17ec08(a0, a1);
        case 1928: return fde_func_1928_0x17ec60(a0, a1);
        case 1929: return fde_func_1929_0x17eca4(a0, a1);
        case 1930: return fde_func_1930_0x17ecf8(a0, a1);
        case 1931: return fde_func_1931_0x17ed44(a0, a1);
        case 1932: return fde_func_1932_0x17ed94(a0, a1);
        case 1933: return fde_func_1933_0x17edd0(a0, a1);
        case 1934: return fde_func_1934_0x17ee2c(a0, a1);
        case 1935: return fde_func_1935_0x17ee88(a0, a1);
        case 1936: return fde_func_1936_0x17eec0(a0, a1);
        case 1937: return fde_func_1937_0x17eee4(a0, a1);
        case 1938: return fde_func_1938_0x17ef10(a0, a1);
        case 1939: return fde_func_1939_0x17ef44(a0, a1);
        case 1940: return fde_func_1940_0x17ef80(a0, a1);
        case 1941: return fde_func_1941_0x17efb4(a0, a1);
        case 1942: return fde_func_1942_0x17f020(a0, a1);
        case 1943: return fde_func_1943_0x17f084(a0, a1);
        case 1944: return fde_func_1944_0x17f0d0(a0, a1);
        case 1945: return fde_func_1945_0x17f10c(a0, a1);
        case 1946: return fde_func_1946_0x17f154(a0, a1);
        case 1947: return fde_func_1947_0x17f188(a0, a1);
        case 1948: return fde_func_1948_0x17f1cc(a0, a1);
        case 1949: return fde_func_1949_0x17f204(a0, a1);
        case 1950: return fde_func_1950_0x17f250(a0, a1);
        case 1951: return fde_func_1951_0x17f294(a0, a1);
        case 1952: return fde_func_1952_0x17f300(a0, a1);
        case 1953: return fde_func_1953_0x17f340(a0, a1);
        case 1954: return fde_func_1954_0x17f394(a0, a1);
        case 1955: return fde_func_1955_0x17f3f4(a0, a1);
        case 1956: return fde_func_1956_0x17f444(a0, a1);
        case 1957: return fde_func_1957_0x17f488(a0, a1);
        case 1958: return fde_func_1958_0x17f4c8(a0, a1);
        case 1959: return fde_func_1959_0x17f520(a0, a1);
        case 1960: return fde_func_1960_0x17f588(a0, a1);
        case 1961: return fde_func_1961_0x17f5c8(a0, a1);
        case 1962: return fde_func_1962_0x17f5fc(a0, a1);
        case 1963: return fde_func_1963_0x17f638(a0, a1);
        case 1964: return fde_func_1964_0x17f668(a0, a1);
        case 1965: return fde_func_1965_0x17f694(a0, a1);
        case 1966: return fde_func_1966_0x17f6c4(a0, a1);
        case 1967: return fde_func_1967_0x17f6fc(a0, a1);
        case 1968: return fde_func_1968_0x17f730(a0, a1);
        case 1969: return fde_func_1969_0x17f764(a0, a1);
        case 1970: return fde_func_1970_0x17f7b0(a0, a1);
        case 1971: return fde_func_1971_0x17f7f0(a0, a1);
        case 1972: return fde_func_1972_0x17f81c(a0, a1);
        case 1973: return fde_func_1973_0x17f844(a0, a1);
        case 1974: return fde_func_1974_0x17f870(a0, a1);
        case 1975: return fde_func_1975_0x17f898(a0, a1);
        case 1976: return fde_func_1976_0x17f900(a0, a1);
        case 1977: return fde_func_1977_0x17f938(a0, a1);
        case 1978: return fde_func_1978_0x17f974(a0, a1);
        case 1979: return fde_func_1979_0x17f9d4(a0, a1);
        case 1980: return fde_func_1980_0x17fa14(a0, a1);
        case 1981: return fde_func_1981_0x17fa54(a0, a1);
        case 1982: return fde_func_1982_0x17fa8c(a0, a1);
        case 1983: return fde_func_1983_0x17fac4(a0, a1);
        case 1984: return fde_func_1984_0x17faf0(a0, a1);
        case 1985: return fde_func_1985_0x17fb28(a0, a1);
        case 1986: return fde_func_1986_0x17fb78(a0, a1);
        case 1987: return fde_func_1987_0x17fbc4(a0, a1);
        case 1988: return fde_func_1988_0x17fc1c(a0, a1);
        case 1989: return fde_func_1989_0x17fc60(a0, a1);
        case 1990: return fde_func_1990_0x17fc9c(a0, a1);
        case 1991: return fde_func_1991_0x17fcd0(a0, a1);
        case 1992: return fde_func_1992_0x17fd0c(a0, a1);
        case 1993: return fde_func_1993_0x17fd54(a0, a1);
        case 1994: return fde_func_1994_0x17fda8(a0, a1);
        case 1995: return fde_func_1995_0x17fde8(a0, a1);
        case 1996: return fde_func_1996_0x17fe30(a0, a1);
        case 1997: return fde_func_1997_0x17fe80(a0, a1);
        case 1998: return fde_func_1998_0x17febc(a0, a1);
        case 1999: return fde_func_1999_0x17ff14(a0, a1);
        default: return 0ULL;
    }
}

} // namespace canvas
} // namespace lynx