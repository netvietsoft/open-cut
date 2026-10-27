// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 1/5 for libkrypton.so
// Phân mảnh Hàm AArch64 C++17 sạch 1/5 cho libkrypton.so
// Covers representative FDE indices [0 .. 399] out of 9,255 total FDEs
// Bao phủ chỉ số FDE đại diện [0 .. 399] trên tổng số 9.255 FDE
// ============================================================================
#include "krypton_core.h"

namespace lynx {
namespace canvas {

// FDE #0000 | PC: 0x0a8518 | FDE: 0x0699a8 | Size: 256 bytes
// Khung tháo gỡ #0000 | Địa chỉ PC: 0x0a8518 | Địa chỉ FDE: 0x0699a8 | Kích thước: 256 bytes
//   0x0a8518: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0a851c: 90000001  adrp     x1, #0xa8000
//   0x0a8520: 910003FD  mov      x29, sp
//   0x0a8524: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_0000_0x0a8518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8518ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x90000001ULL) ^ 0x0699a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0001 | PC: 0x0a8690 | FDE: 0x069a58 | Size: 256 bytes [__emutls_get_address]
// Khung tháo gỡ #0001 | Địa chỉ PC: 0x0a8690 | Địa chỉ FDE: 0x069a58 | Kích thước: 256 bytes
//   0x0a8690: B0000761  adrp     x1, #0x195000
//   0x0a8694: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0a8698: 910003FD  mov      x29, sp
//   0x0a869c: F940E021  ldr      x1, [x1, #0x1c0]
static inline uint64_t fde_func_0001_0x0a8690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8690ULL ^ (static_cast<uint64_t>(0xb0000761ULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x069a58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0002 | PC: 0x0a87e8 | FDE: 0x069a90 | Size: 60 bytes [__emutls_register_common]
// Khung tháo gỡ #0002 | Địa chỉ PC: 0x0a87e8 | Địa chỉ FDE: 0x069a90 | Kích thước: 60 bytes
//   0x0a87e8: F9400004  ldr      x4, [x0]
//   0x0a87ec: EB01009F  cmp      x4, x1
//   0x0a87f0: 54000062  b.hs     #0xa87fc
//   0x0a87f4: F9000001  str      x1, [x0]
static inline uint64_t fde_func_0002_0x0a87e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a87e8ULL ^ (static_cast<uint64_t>(0xf9400004ULL) << 13);
    acc = (acc + a1 + 0xeb01009fULL) ^ 0x069a90ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0003 | PC: 0x0a8824 | FDE: 0x069ac0 | Size: 32 bytes [_ZN4lynx6canvas10DataHolder15MakeWithoutCopyEPKvm]
// Khung tháo gỡ #0003 | Địa chỉ PC: 0x0a8824 | Địa chỉ FDE: 0x069ac0 | Kích thước: 32 bytes
//   0x0a8824: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0a8828: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0a882c: 94036327  bl       #0x1814c8
//   0x0a8830: A9004C14  stp      x20, x19, [x0]
static inline uint64_t fde_func_0003_0x0a8824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8824ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x069ac0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0004 | PC: 0x0a8844 | FDE: 0x069ae0 | Size: 168 bytes [_ZN4lynx6canvas10DataHolder12MakeWithCopyEPKvm]
// Khung tháo gỡ #0004 | Địa chỉ PC: 0x0a8844 | Địa chỉ FDE: 0x069ae0 | Kích thước: 168 bytes
//   0x0a8844: AA1E03E2  mov      x2, x30
//   0x0a8848: 94034C53  bl       #0x17b994
//   0x0a884c: AA0203FE  mov      x30, x2
//   0x0a8850: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0004_0x0a8844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8844ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94034c53ULL) ^ 0x069ae0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0005 | PC: 0x0a88ec | FDE: 0x069b08 | Size: 256 bytes
// Khung tháo gỡ #0005 | Địa chỉ PC: 0x0a88ec | Địa chỉ FDE: 0x069b08 | Kích thước: 256 bytes
//   0x0a88ec: 52800043  mov      w3, #2
//   0x0a88f0: 14037A70  b        #0x1872b0
//   0x0a88f4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0a88f8: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0005_0x0a88ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a88ecULL ^ (static_cast<uint64_t>(0x52800043ULL) << 13);
    acc = (acc + a1 + 0x14037a70ULL) ^ 0x069b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0006 | PC: 0x0a89fc | FDE: 0x069b90 | Size: 136 bytes
// Khung tháo gỡ #0006 | Địa chỉ PC: 0x0a89fc | Địa chỉ FDE: 0x069b90 | Kích thước: 136 bytes
//   0x0a89fc: 14037A09  b        #0x187220
//   0x0a8a00: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0a8a04: 3900001F  strb     wzr, [x0]
//   0x0a8a08: F9000401  str      x1, [x0, #8]
static inline uint64_t fde_func_0006_0x0a89fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a89fcULL ^ (static_cast<uint64_t>(0x14037a09ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x069b90ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0007 | PC: 0x0a8a84 | FDE: 0x069bf0 | Size: 256 bytes
// Khung tháo gỡ #0007 | Địa chỉ PC: 0x0a8a84 | Địa chỉ FDE: 0x069bf0 | Kích thước: 256 bytes
//   0x0a8a84: B9402008  ldr      w8, [x0, #0x20]
//   0x0a8a88: 2A010101  orr      w1, w8, w1
//   0x0a8a8c: 14037A11  b        #0x1872d0
//   0x0a8a90: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0007_0x0a8a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8a84ULL ^ (static_cast<uint64_t>(0xb9402008ULL) << 13);
    acc = (acc + a1 + 0x2a010101ULL) ^ 0x069bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0008 | PC: 0x0a8bcc | FDE: 0x069c58 | Size: 256 bytes
// Khung tháo gỡ #0008 | Địa chỉ PC: 0x0a8bcc | Địa chỉ FDE: 0x069c58 | Kích thước: 256 bytes
//   0x0a8bcc: AA1E03E3  mov      x3, x30
//   0x0a8bd0: 94035494  bl       #0x17de20
//   0x0a8bd4: AA0303FE  mov      x30, x3
//   0x0a8bd8: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0008_0x0a8bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8bccULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94035494ULL) ^ 0x069c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0009 | PC: 0x0a8db4 | FDE: 0x069cd8 | Size: 168 bytes [_ZN4lynx6canvas10DataHolder14MakeWithMallocEm]
// Khung tháo gỡ #0009 | Địa chỉ PC: 0x0a8db4 | Địa chỉ FDE: 0x069cd8 | Kích thước: 168 bytes
//   0x0a8db4: AA1E03E1  mov      x1, x30
//   0x0a8db8: 94033E6A  bl       #0x178760
//   0x0a8dbc: AA0103FE  mov      x30, x1
//   0x0a8dc0: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0009_0x0a8db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8db4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94033e6aULL) ^ 0x069cd8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0010 | PC: 0x0a8e5c | FDE: 0x069d00 | Size: 156 bytes [_ZN4lynx6canvas10DataHolder19MakeWithCopyOnStackEPKvm]
// Khung tháo gỡ #0010 | Địa chỉ PC: 0x0a8e5c | Địa chỉ FDE: 0x069d00 | Kích thước: 156 bytes
//   0x0a8e5c: AA1E03E2  mov      x2, x30
//   0x0a8e60: 94034ACD  bl       #0x17b994
//   0x0a8e64: AA0203FE  mov      x30, x2
//   0x0a8e68: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0010_0x0a8e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8e5cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94034acdULL) ^ 0x069d00ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0011 | PC: 0x0a8ef8 | FDE: 0x069d28 | Size: 40 bytes [_ZN4lynx6canvas10DataHolder14MakeWithMoveToEPKvm]
// Khung tháo gỡ #0011 | Địa chỉ PC: 0x0a8ef8 | Địa chỉ FDE: 0x069d28 | Kích thước: 40 bytes
//   0x0a8ef8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0a8efc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0a8f00: 94036172  bl       #0x1814c8
//   0x0a8f04: A9004C14  stp      x20, x19, [x0]
static inline uint64_t fde_func_0011_0x0a8ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8ef8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x069d28ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0012 | PC: 0x0a8f20 | FDE: 0x069d48 | Size: 64 bytes [_ZN4lynx6canvas10DataHolder19MakeWithReleaseProcEPKvmPvPFvS3_S4_E]
// Khung tháo gỡ #0012 | Địa chỉ PC: 0x0a8f20 | Địa chỉ FDE: 0x069d48 | Kích thước: 64 bytes
//   0x0a8f20: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0a8f24: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0a8f28: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0a8f2c: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_0012_0x0a8f20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f20ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x069d48ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0013 | PC: 0x0a8f60 | FDE: 0x069d68 | Size: 12 bytes [_ZN4lynx6canvas10DataHolderC1EPKvmPFvS3_PvE]
// Khung tháo gỡ #0013 | Địa chỉ PC: 0x0a8f60 | Địa chỉ FDE: 0x069d68 | Kích thước: 12 bytes
//   0x0a8f60: A9000801  stp      x1, x2, [x0]
//   0x0a8f64: A9010C1F  stp      xzr, x3, [x0, #0x10]
//   0x0a8f68: D65F03C0  ret      
static inline uint64_t fde_func_0013_0x0a8f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f60ULL ^ (static_cast<uint64_t>(0xa9000801ULL) << 13);
    acc = (acc + a1 + 0xa9010c1fULL) ^ 0x069d68ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0014 | PC: 0x0a8f6c | FDE: 0x069d80 | Size: 12 bytes [_ZN4lynx6canvas10DataHolderC2EPKvmPvPFvS3_S4_E]
// Khung tháo gỡ #0014 | Địa chỉ PC: 0x0a8f6c | Địa chỉ FDE: 0x069d80 | Kích thước: 12 bytes
//   0x0a8f6c: A9000801  stp      x1, x2, [x0]
//   0x0a8f70: A9011003  stp      x3, x4, [x0, #0x10]
//   0x0a8f74: D65F03C0  ret      
static inline uint64_t fde_func_0014_0x0a8f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f6cULL ^ (static_cast<uint64_t>(0xa9000801ULL) << 13);
    acc = (acc + a1 + 0xa9011003ULL) ^ 0x069d80ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0015 | PC: 0x0a8f78 | FDE: 0x069d98 | Size: 28 bytes [_ZN4lynx6canvas10DataHolderD1Ev]
// Khung tháo gỡ #0015 | Địa chỉ PC: 0x0a8f78 | Địa chỉ FDE: 0x069d98 | Kích thước: 28 bytes
//   0x0a8f78: F9400C02  ldr      x2, [x0, #0x18]
//   0x0a8f7c: B40000A2  cbz      x2, #0xa8f90
//   0x0a8f80: F9400008  ldr      x8, [x0]
//   0x0a8f84: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0015_0x0a8f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f78ULL ^ (static_cast<uint64_t>(0xf9400c02ULL) << 13);
    acc = (acc + a1 + 0xb40000a2ULL) ^ 0x069d98ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0016 | PC: 0x0a8f94 | FDE: 0x069db0 | Size: 36 bytes [_ZN4lynx6canvas10DataHolderC1EOS1_]
// Khung tháo gỡ #0016 | Địa chỉ PC: 0x0a8f94 | Địa chỉ FDE: 0x069db0 | Kích thước: 36 bytes
//   0x0a8f94: F9400028  ldr      x8, [x1]
//   0x0a8f98: F9000008  str      x8, [x0]
//   0x0a8f9c: F9400428  ldr      x8, [x1, #8]
//   0x0a8fa0: A900FC08  stp      x8, xzr, [x0, #8]
static inline uint64_t fde_func_0016_0x0a8f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8f94ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x069db0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0017 | PC: 0x0a8fb8 | FDE: 0x069dc8 | Size: 16 bytes [_ZN4lynx6canvas10DataHolder7ReleaseEv]
// Khung tháo gỡ #0017 | Địa chỉ PC: 0x0a8fb8 | Địa chỉ FDE: 0x069dc8 | Kích thước: 16 bytes
//   0x0a8fb8: F9400008  ldr      x8, [x0]
//   0x0a8fbc: F900001F  str      xzr, [x0]
//   0x0a8fc0: F9000C1F  str      xzr, [x0, #0x18]
//   0x0a8fc4: 140345E2  b        #0x17a74c
static inline uint64_t fde_func_0017_0x0a8fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8fb8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x069dc8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0018 | PC: 0x0a8fc8 | FDE: 0x069de0 | Size: 32 bytes [_ZN4lynx6canvas10DataHolder7ReleaseERPFvPKvPvERS4_]
// Khung tháo gỡ #0018 | Địa chỉ PC: 0x0a8fc8 | Địa chỉ FDE: 0x069de0 | Kích thước: 32 bytes
//   0x0a8fc8: F9400C09  ldr      x9, [x0, #0x18]
//   0x0a8fcc: F9400008  ldr      x8, [x0]
//   0x0a8fd0: F900001F  str      xzr, [x0]
//   0x0a8fd4: F9000029  str      x9, [x1]
static inline uint64_t fde_func_0018_0x0a8fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8fc8ULL ^ (static_cast<uint64_t>(0xf9400c09ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x069de0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0019 | PC: 0x0a8fe8 | FDE: 0x069df8 | Size: 4 bytes [_ZN4lynx6canvas10DataHolder16ForsakeOwnerShipEv]
// Khung tháo gỡ #0019 | Địa chỉ PC: 0x0a8fe8 | Địa chỉ FDE: 0x069df8 | Kích thước: 4 bytes
//   0x0a8fe8: 140375AC  b        #0x186698
static inline uint64_t fde_func_0019_0x0a8fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8fe8ULL ^ (static_cast<uint64_t>(0x140375acULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x069df8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0020 | PC: 0x0a8fec | FDE: 0x069e10 | Size: 52 bytes [_ZN4lynx6canvas10LogMessageC2EPKci15KryptonLogLevel]
// Khung tháo gỡ #0020 | Địa chỉ PC: 0x0a8fec | Địa chỉ FDE: 0x069e10 | Kích thước: 52 bytes
//   0x0a8fec: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0a8ff0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0a8ff4: AA0003F4  mov      x20, x0
//   0x0a8ff8: F9000001  str      x1, [x0]
static inline uint64_t fde_func_0020_0x0a8fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8fecULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x069e10ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0021 | PC: 0x0a9020 | FDE: 0x069e30 | Size: 88 bytes
// Khung tháo gỡ #0021 | Địa chỉ PC: 0x0a9020 | Địa chỉ FDE: 0x069e30 | Kích thước: 88 bytes
//   0x0a9020: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0a9024: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0a9028: F0000708  adrp     x8, #0x18c000
//   0x0a902c: 9105C108  add      x8, x8, #0x170
static inline uint64_t fde_func_0021_0x0a9020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9020ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x069e30ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0022 | PC: 0x0a9078 | FDE: 0x069e50 | Size: 256 bytes [_ZN4lynx6canvas10LogMessage4InitEPKci]
// Khung tháo gỡ #0022 | Địa chỉ PC: 0x0a9078 | Địa chỉ FDE: 0x069e50 | Kích thước: 256 bytes
//   0x0a9078: D10183FF  sub      sp, sp, #0x60
//   0x0a907c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0a9080: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x0a9084: 94037573  bl       #0x186650
static inline uint64_t fde_func_0022_0x0a9078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9078ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x069e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0023 | PC: 0x0a91e0 | FDE: 0x069eb8 | Size: 256 bytes
// Khung tháo gỡ #0023 | Địa chỉ PC: 0x0a91e0 | Địa chỉ FDE: 0x069eb8 | Kích thước: 256 bytes
//   0x0a91e0: D10083FF  sub      sp, sp, #0x20
//   0x0a91e4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0a91e8: 940352D4  bl       #0x17dd38
//   0x0a91ec: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_0023_0x0a91e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a91e0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x069eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0024 | PC: 0x0a92e4 | FDE: 0x069f20 | Size: 200 bytes
// Khung tháo gỡ #0024 | Địa chỉ PC: 0x0a92e4 | Địa chỉ FDE: 0x069f20 | Kích thước: 200 bytes
//   0x0a92e4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0a92e8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0a92ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0a92f0: B100405F  cmn      x2, #0x10
static inline uint64_t fde_func_0024_0x0a92e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a92e4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x069f20ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0025 | PC: 0x0a93ac | FDE: 0x069f90 | Size: 60 bytes
// Khung tháo gỡ #0025 | Địa chỉ PC: 0x0a93ac | Địa chỉ FDE: 0x069f90 | Kích thước: 60 bytes
//   0x0a93ac: 140374FF  b        #0x1867a8
//   0x0a93b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0a93b4: F0000708  adrp     x8, #0x18c000
//   0x0a93b8: 9101A108  add      x8, x8, #0x68
static inline uint64_t fde_func_0025_0x0a93ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a93acULL ^ (static_cast<uint64_t>(0x140374ffULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x069f90ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0026 | PC: 0x0a93e8 | FDE: 0x069fd8 | Size: 4 bytes [_ZN4lynx6canvas11MediaStream9OnWrappedEv]
// Khung tháo gỡ #0026 | Địa chỉ PC: 0x0a93e8 | Địa chỉ FDE: 0x069fd8 | Kích thước: 4 bytes
//   0x0a93e8: D65F03C0  ret      
static inline uint64_t fde_func_0026_0x0a93e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a93e8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9402c08ULL) ^ 0x069fd8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0027 | PC: 0x0a93ec | FDE: 0x069ff0 | Size: 256 bytes
// Khung tháo gỡ #0027 | Địa chỉ PC: 0x0a93ec | Địa chỉ FDE: 0x069ff0 | Kích thước: 256 bytes
//   0x0a93ec: F9402C08  ldr      x8, [x0, #0x58]
//   0x0a93f0: F9401809  ldr      x9, [x0, #0x30]
//   0x0a93f4: EB09011F  cmp      x8, x9
//   0x0a93f8: 54000062  b.hs     #0xa9404
static inline uint64_t fde_func_0027_0x0a93ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a93ecULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x069ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0028 | PC: 0x0a94ec | FDE: 0x06a020 | Size: 8 bytes [_ZN4lynx6canvas27GLSurfaceGraphicsContextEGL12GLContextFBOEv]
// Khung tháo gỡ #0028 | Địa chỉ PC: 0x0a94ec | Địa chỉ FDE: 0x06a020 | Kích thước: 8 bytes
//   0x0a94ec: 14033163  b        #0x175a78
//   0x0a94f0: 14033D5A  b        #0x178a58
static inline uint64_t fde_func_0028_0x0a94ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a94ecULL ^ (static_cast<uint64_t>(0x14033163ULL) << 13);
    acc = (acc + a1 + 0x14033d5aULL) ^ 0x06a020ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0029 | PC: 0x0a94f4 | FDE: 0x06a050 | Size: 256 bytes
// Khung tháo gỡ #0029 | Địa chỉ PC: 0x0a94f4 | Địa chỉ FDE: 0x06a050 | Kích thước: 256 bytes
//   0x0a94f4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0a94f8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0a94fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0a9500: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0029_0x0a94f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a94f4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06a050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0030 | PC: 0x0a9678 | FDE: 0x06a0c0 | Size: 256 bytes
// Khung tháo gỡ #0030 | Địa chỉ PC: 0x0a9678 | Địa chỉ FDE: 0x06a0c0 | Kích thước: 256 bytes
//   0x0a9678: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0a967c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0a9680: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0a9684: 94033CFA  bl       #0x178a6c
static inline uint64_t fde_func_0030_0x0a9678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9678ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06a0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0031 | PC: 0x0a998c | FDE: 0x06a148 | Size: 256 bytes
// Khung tháo gỡ #0031 | Địa chỉ PC: 0x0a998c | Địa chỉ FDE: 0x06a148 | Kích thước: 256 bytes
//   0x0a998c: A9432009  ldp      x9, x8, [x0, #0x30]
//   0x0a9990: EB08013F  cmp      x9, x8
//   0x0a9994: 540000E0  b.eq     #0xa99b0
//   0x0a9998: 9100052A  add      x10, x9, #1
static inline uint64_t fde_func_0031_0x0a998c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a998cULL ^ (static_cast<uint64_t>(0xa9432009ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x06a148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0032 | PC: 0x0a9abc | FDE: 0x06a1b8 | Size: 52 bytes
// Khung tháo gỡ #0032 | Địa chỉ PC: 0x0a9abc | Địa chỉ FDE: 0x06a1b8 | Kích thước: 52 bytes
//   0x0a9abc: 92800001  mov      x1, #-1
//   0x0a9ac0: 14033BE6  b        #0x178a58
//   0x0a9ac4: 14035C95  b        #0x180d18
//   0x0a9ac8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0032_0x0a9abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9abcULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0x14033be6ULL) ^ 0x06a1b8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0033 | PC: 0x0a9af0 | FDE: 0x06a218 | Size: 108 bytes
// Khung tháo gỡ #0033 | Địa chỉ PC: 0x0a9af0 | Địa chỉ FDE: 0x06a218 | Kích thước: 108 bytes
//   0x0a9af0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0a9af4: AA0003F3  mov      x19, x0
//   0x0a9af8: 91002000  add      x0, x0, #8
//   0x0a9afc: 94037621  bl       #0x187380
static inline uint64_t fde_func_0033_0x0a9af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9af0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06a218ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0034 | PC: 0x0a9b5c | FDE: 0x06a278 | Size: 56 bytes
// Khung tháo gỡ #0034 | Địa chỉ PC: 0x0a9b5c | Địa chỉ FDE: 0x06a278 | Kích thước: 56 bytes
//   0x0a9b5c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0a9b60: AA0003F3  mov      x19, x0
//   0x0a9b64: 97FFFFF3  bl       #0xa9b30
//   0x0a9b68: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0034_0x0a9b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9b5cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06a278ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0035 | PC: 0x0a9b94 | FDE: 0x06a2c0 | Size: 256 bytes [_ZN4lynx6canvas10LogMessageD2Ev]
// Khung tháo gỡ #0035 | Địa chỉ PC: 0x0a9b94 | Địa chỉ FDE: 0x06a2c0 | Kích thước: 256 bytes
//   0x0a9b94: AA1E03E1  mov      x1, x30
//   0x0a9b98: 9403343D  bl       #0x176c8c
//   0x0a9b9c: AA0103FE  mov      x30, x1
//   0x0a9ba0: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0035_0x0a9b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9b94ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9403343dULL) ^ 0x06a2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0036 | PC: 0x0a9d70 | FDE: 0x06a2f0 | Size: 108 bytes
// Khung tháo gỡ #0036 | Địa chỉ PC: 0x0a9d70 | Địa chỉ FDE: 0x06a2f0 | Kích thước: 108 bytes
//   0x0a9d70: D100C3FF  sub      sp, sp, #0x30
//   0x0a9d74: F9000BF4  str      x20, [sp, #0x10]
//   0x0a9d78: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0a9d7c: 9403503C  bl       #0x17de6c
static inline uint64_t fde_func_0036_0x0a9d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9d70ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x06a2f0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0037 | PC: 0x0a9ddc | FDE: 0x06a310 | Size: 112 bytes [_ZN4lynx6canvas12ThreadAssert6AssertENS1_4TypeE]
// Khung tháo gỡ #0037 | Địa chỉ PC: 0x0a9ddc | Địa chỉ FDE: 0x06a310 | Kích thước: 112 bytes
//   0x0a9ddc: D10543FF  sub      sp, sp, #0x150
//   0x0a9de0: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0a9de4: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0a9de8: 940330EC  bl       #0x176198
static inline uint64_t fde_func_0037_0x0a9ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9ddcULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x06a310ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0038 | PC: 0x0a9e4c | FDE: 0x06a330 | Size: 156 bytes [_ZN4lynx6canvas7android14CheckExceptionEP7_JNIEnv]
// Khung tháo gỡ #0038 | Địa chỉ PC: 0x0a9e4c | Địa chỉ FDE: 0x06a330 | Kích thước: 156 bytes
//   0x0a9e4c: D105C3FF  sub      sp, sp, #0x170
//   0x0a9e50: F900A3FC  str      x28, [sp, #0x140]
//   0x0a9e54: A91553F5  stp      x21, x20, [sp, #0x150]
//   0x0a9e58: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0038_0x0a9e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9e4cULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf900a3fcULL) ^ 0x06a330ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0039 | PC: 0x0a9ee8 | FDE: 0x06a368 | Size: 256 bytes
// Khung tháo gỡ #0039 | Địa chỉ PC: 0x0a9ee8 | Địa chỉ FDE: 0x06a368 | Kích thước: 256 bytes
//   0x0a9ee8: AA1E03E3  mov      x3, x30
//   0x0a9eec: 940354AB  bl       #0x17f198
//   0x0a9ef0: AA0303FE  mov      x30, x3
//   0x0a9ef4: 17FFFB36  b        #0xa8bcc
static inline uint64_t fde_func_0039_0x0a9ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9ee8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940354abULL) ^ 0x06a368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0040 | PC: 0x0aa230 | FDE: 0x06a3e8 | Size: 192 bytes
// Khung tháo gỡ #0040 | Địa chỉ PC: 0x0aa230 | Địa chỉ FDE: 0x06a3e8 | Kích thước: 192 bytes
//   0x0aa230: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0aa234: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0aa238: AA0203F3  mov      x19, x2
//   0x0aa23c: 94034146  bl       #0x17a754
static inline uint64_t fde_func_0040_0x0aa230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa230ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06a3e8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0041 | PC: 0x0aa2f0 | FDE: 0x06a460 | Size: 152 bytes
// Khung tháo gỡ #0041 | Địa chỉ PC: 0x0aa2f0 | Địa chỉ FDE: 0x06a460 | Kích thước: 152 bytes
//   0x0aa2f0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0aa2f4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0aa2f8: F9400414  ldr      x20, [x0, #8]
//   0x0aa2fc: 94034166  bl       #0x17a894
static inline uint64_t fde_func_0041_0x0aa2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa2f0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06a460ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0042 | PC: 0x0aa388 | FDE: 0x06a4d0 | Size: 256 bytes
// Khung tháo gỡ #0042 | Địa chỉ PC: 0x0aa388 | Địa chỉ FDE: 0x06a4d0 | Kích thước: 256 bytes
//   0x0aa388: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0aa38c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0aa390: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0aa394: A9405416  ldp      x22, x21, [x0]
static inline uint64_t fde_func_0042_0x0aa388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa388ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06a4d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0043 | PC: 0x0aa4cc | FDE: 0x06a540 | Size: 256 bytes
// Khung tháo gỡ #0043 | Địa chỉ PC: 0x0aa4cc | Địa chỉ FDE: 0x06a540 | Kích thước: 256 bytes
//   0x0aa4cc: B4000042  cbz      x2, #0xaa4d4
//   0x0aa4d0: 140373E0  b        #0x187450
//   0x0aa4d4: 14032D69  b        #0x175a78
//   0x0aa4d8: D10183FF  sub      sp, sp, #0x60
static inline uint64_t fde_func_0043_0x0aa4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa4ccULL ^ (static_cast<uint64_t>(0xb4000042ULL) << 13);
    acc = (acc + a1 + 0x140373e0ULL) ^ 0x06a540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0044 | PC: 0x0aa648 | FDE: 0x06a5b8 | Size: 256 bytes
// Khung tháo gỡ #0044 | Địa chỉ PC: 0x0aa648 | Địa chỉ FDE: 0x06a5b8 | Kích thước: 256 bytes
//   0x0aa648: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0aa64c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0aa650: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0aa654: 94036F50  bl       #0x186394
static inline uint64_t fde_func_0044_0x0aa648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa648ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06a5b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0045 | PC: 0x0aa844 | FDE: 0x06a638 | Size: 128 bytes
// Khung tháo gỡ #0045 | Địa chỉ PC: 0x0aa844 | Địa chỉ FDE: 0x06a638 | Kích thước: 128 bytes
//   0x0aa844: F9400001  ldr      x1, [x0]
//   0x0aa848: 17FFFE88  b        #0xaa268
//   0x0aa84c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0aa850: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0045_0x0aa844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa844ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0x17fffe88ULL) ^ 0x06a638ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0046 | PC: 0x0aa8c4 | FDE: 0x06a698 | Size: 256 bytes
// Khung tháo gỡ #0046 | Địa chỉ PC: 0x0aa8c4 | Địa chỉ FDE: 0x06a698 | Kích thước: 256 bytes
//   0x0aa8c4: D10183FF  sub      sp, sp, #0x60
//   0x0aa8c8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0aa8cc: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0aa8d0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0046_0x0aa8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa8c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x06a698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0047 | PC: 0x0aa9cc | FDE: 0x06a708 | Size: 256 bytes
// Khung tháo gỡ #0047 | Địa chỉ PC: 0x0aa9cc | Địa chỉ FDE: 0x06a708 | Kích thước: 256 bytes
//   0x0aa9cc: F940004A  ldr      x10, [x2]
//   0x0aa9d0: AA0203E8  mov      x8, x2
//   0x0aa9d4: CB000022  sub      x2, x1, x0
//   0x0aa9d8: AA0003E9  mov      x9, x0
static inline uint64_t fde_func_0047_0x0aa9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa9ccULL ^ (static_cast<uint64_t>(0xf940004aULL) << 13);
    acc = (acc + a1 + 0xaa0203e8ULL) ^ 0x06a708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0048 | PC: 0x0aab74 | FDE: 0x06a778 | Size: 256 bytes
// Khung tháo gỡ #0048 | Địa chỉ PC: 0x0aab74 | Địa chỉ FDE: 0x06a778 | Kích thước: 256 bytes
//   0x0aab74: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0aab78: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0aab7c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0aab80: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0048_0x0aab74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aab74ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06a778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0049 | PC: 0x0aaff8 | FDE: 0x06a800 | Size: 252 bytes
// Khung tháo gỡ #0049 | Địa chỉ PC: 0x0aaff8 | Địa chỉ FDE: 0x06a800 | Kích thước: 252 bytes
//   0x0aaff8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0aaffc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ab000: 94033CCB  bl       #0x17a32c
//   0x0ab004: AA1303E1  mov      x1, x19
static inline uint64_t fde_func_0049_0x0aaff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aaff8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06a800ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0050 | PC: 0x0ab0f4 | FDE: 0x06a870 | Size: 256 bytes
// Khung tháo gỡ #0050 | Địa chỉ PC: 0x0ab0f4 | Địa chỉ FDE: 0x06a870 | Kích thước: 256 bytes
//   0x0ab0f4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0ab0f8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ab0fc: 39400008  ldrb     w8, [x0]
//   0x0ab100: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0050_0x0ab0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab0f4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06a870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0051 | PC: 0x0ab434 | FDE: 0x06a8f8 | Size: 200 bytes
// Khung tháo gỡ #0051 | Địa chỉ PC: 0x0ab434 | Địa chỉ FDE: 0x06a8f8 | Kích thước: 200 bytes
//   0x0ab434: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ab438: B40000A0  cbz      x0, #0xab44c
//   0x0ab43c: F9400008  ldr      x8, [x0]
//   0x0ab440: F9401903  ldr      x3, [x8, #0x30]
static inline uint64_t fde_func_0051_0x0ab434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab434ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb40000a0ULL) ^ 0x06a8f8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0052 | PC: 0x0ab4fc | FDE: 0x06a968 | Size: 240 bytes
// Khung tháo gỡ #0052 | Địa chỉ PC: 0x0ab4fc | Địa chỉ FDE: 0x06a968 | Kích thước: 240 bytes
//   0x0ab4fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ab500: 94032C4E  bl       #0x176638
//   0x0ab504: 94000004  bl       #0xab514
//   0x0ab508: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0052_0x0ab4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab4fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94032c4eULL) ^ 0x06a968ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0053 | PC: 0x0ab5ec | FDE: 0x06a9d8 | Size: 92 bytes
// Khung tháo gỡ #0053 | Địa chỉ PC: 0x0ab5ec | Địa chỉ FDE: 0x06a9d8 | Kích thước: 92 bytes
//   0x0ab5ec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ab5f0: 94033C84  bl       #0x17a800
//   0x0ab5f4: B40000C0  cbz      x0, #0xab60c
//   0x0ab5f8: 94036FDE  bl       #0x187570
static inline uint64_t fde_func_0053_0x0ab5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab5ecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94033c84ULL) ^ 0x06a9d8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0054 | PC: 0x0ab648 | FDE: 0x06aa38 | Size: 156 bytes
// Khung tháo gỡ #0054 | Địa chỉ PC: 0x0ab648 | Địa chỉ FDE: 0x06aa38 | Kích thước: 156 bytes
//   0x0ab648: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ab64c: AA0003F3  mov      x19, x0
//   0x0ab650: 97FFFFFA  bl       #0xab638
//   0x0ab654: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0054_0x0ab648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab648ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06aa38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0055 | PC: 0x0ab6e4 | FDE: 0x06aaa0 | Size: 184 bytes
// Khung tháo gỡ #0055 | Địa chỉ PC: 0x0ab6e4 | Địa chỉ FDE: 0x06aaa0 | Kích thước: 184 bytes
//   0x0ab6e4: 885F7C08  ldxr     w8, [x0]
//   0x0ab6e8: 71000508  subs     w8, w8, #1
//   0x0ab6ec: 8809FC08  stlxr    w9, w8, [x0]
//   0x0ab6f0: 35FFFFA9  cbnz     w9, #0xab6e4
static inline uint64_t fde_func_0055_0x0ab6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab6e4ULL ^ (static_cast<uint64_t>(0x885f7c08ULL) << 13);
    acc = (acc + a1 + 0x71000508ULL) ^ 0x06aaa0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0056 | PC: 0x0ab79c | FDE: 0x06ab00 | Size: 164 bytes
// Khung tháo gỡ #0056 | Địa chỉ PC: 0x0ab79c | Địa chỉ FDE: 0x06ab00 | Kích thước: 164 bytes
//   0x0ab79c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ab7a0: AA0003F3  mov      x19, x0
//   0x0ab7a4: 97FFFFF6  bl       #0xab77c
//   0x0ab7a8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0056_0x0ab79c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab79cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06ab00ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0057 | PC: 0x0ab840 | FDE: 0x06ab70 | Size: 88 bytes
// Khung tháo gỡ #0057 | Địa chỉ PC: 0x0ab840 | Địa chỉ FDE: 0x06ab70 | Kích thước: 88 bytes
//   0x0ab840: AA0003E8  mov      x8, x0
//   0x0ab844: F9400000  ldr      x0, [x0]
//   0x0ab848: F900011F  str      xzr, [x8]
//   0x0ab84c: B4000040  cbz      x0, #0xab854
static inline uint64_t fde_func_0057_0x0ab840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab840ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x06ab70ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0058 | PC: 0x0ab898 | FDE: 0x06abd0 | Size: 4 bytes [_ZNK4lynx6canvas30SurfaceWithAndroidNativeWindow14GetHandlerTypeEv]
// Khung tháo gỡ #0058 | Địa chỉ PC: 0x0ab898 | Địa chỉ FDE: 0x06abd0 | Kích thước: 4 bytes
//   0x0ab898: 14032AA6  b        #0x176330
static inline uint64_t fde_func_0058_0x0ab898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab898ULL ^ (static_cast<uint64_t>(0x14032aa6ULL) << 13);
    acc = (acc + a1 + 0xd10583ffULL) ^ 0x06abd0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0059 | PC: 0x0ab89c | FDE: 0x06abe8 | Size: 256 bytes [_ZN4lynx6canvas20CameraContextAndroidC2ERKNSt6__ndk110shared_ptrINS0_9CanvasAppEEERKNS2_8functionIFvNS2_10unique_ptrINS0_12VideoContextENS2_14default_deleteISA_EEEENS2_8optionalINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEEEEE]
// Khung tháo gỡ #0059 | Địa chỉ PC: 0x0ab89c | Địa chỉ FDE: 0x06abe8 | Kích thước: 256 bytes
//   0x0ab89c: D10583FF  sub      sp, sp, #0x160
//   0x0ab8a0: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0ab8a4: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ab8a8: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0059_0x0ab89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab89cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x06abe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0060 | PC: 0x0ab9a8 | FDE: 0x06ac40 | Size: 256 bytes
// Khung tháo gỡ #0060 | Địa chỉ PC: 0x0ab9a8 | Địa chỉ FDE: 0x06ac40 | Kích thước: 256 bytes
//   0x0ab9a8: AA1E03E1  mov      x1, x30
//   0x0ab9ac: 9403336D  bl       #0x178760
//   0x0ab9b0: AA0103FE  mov      x30, x1
//   0x0ab9b4: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0060_0x0ab9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab9a8ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9403336dULL) ^ 0x06ac40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0061 | PC: 0x0abb4c | FDE: 0x06acb8 | Size: 256 bytes
// Khung tháo gỡ #0061 | Địa chỉ PC: 0x0abb4c | Địa chỉ FDE: 0x06acb8 | Kích thước: 256 bytes
//   0x0abb4c: D10583FF  sub      sp, sp, #0x160
//   0x0abb50: F9009BFC  str      x28, [sp, #0x130]
//   0x0abb54: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0abb58: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0061_0x0abb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abb4cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x06acb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0062 | PC: 0x0abc5c | FDE: 0x06ad28 | Size: 112 bytes
// Khung tháo gỡ #0062 | Địa chỉ PC: 0x0abc5c | Địa chỉ FDE: 0x06ad28 | Kích thước: 112 bytes
//   0x0abc5c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0abc60: AA0003F3  mov      x19, x0
//   0x0abc64: 97FFFFFA  bl       #0xabc4c
//   0x0abc68: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0062_0x0abc5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abc5cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06ad28ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0063 | PC: 0x0abccc | FDE: 0x06ad88 | Size: 256 bytes [_ZN4lynx6canvas13CameraContext18DoRequestUserMediaERKNSt6__ndk110shared_ptrINS0_9CanvasAppEEENS2_10unique_ptrINS0_12CameraOptionENS2_14default_deleteIS9_EEEERKNS2_8functionIFvNS8_INS0_12VideoContextENSA_ISE_EEEENS2_8optionalINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEEEEE]
// Khung tháo gỡ #0063 | Địa chỉ PC: 0x0abccc | Địa chỉ FDE: 0x06ad88 | Kích thước: 256 bytes
//   0x0abccc: AA1E03E3  mov      x3, x30
//   0x0abcd0: 94033DDB  bl       #0x17b43c
//   0x0abcd4: AA0303FE  mov      x30, x3
//   0x0abcd8: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0063_0x0abccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abcccULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94033ddbULL) ^ 0x06ad88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0064 | PC: 0x0ac160 | FDE: 0x06ae30 | Size: 172 bytes
// Khung tháo gỡ #0064 | Địa chỉ PC: 0x0ac160 | Địa chỉ FDE: 0x06ae30 | Kích thước: 172 bytes
//   0x0ac160: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0ac164: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ac168: 2A0203F3  mov      w19, w2
//   0x0ac16c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0064_0x0ac160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac160ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06ae30ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0065 | PC: 0x0ac20c | FDE: 0x06ae98 | Size: 256 bytes
// Khung tháo gỡ #0065 | Địa chỉ PC: 0x0ac20c | Địa chỉ FDE: 0x06ae98 | Kích thước: 256 bytes
//   0x0ac20c: AA1F03E1  mov      x1, xzr
//   0x0ac210: 17FFFFF0  b        #0xac1d0
//   0x0ac214: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac218: 940330EF  bl       #0x1785d4
static inline uint64_t fde_func_0065_0x0ac20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac20cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fffff0ULL) ^ 0x06ae98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0066 | PC: 0x0ac314 | FDE: 0x06af00 | Size: 180 bytes
// Khung tháo gỡ #0066 | Địa chỉ PC: 0x0ac314 | Địa chỉ FDE: 0x06af00 | Kích thước: 180 bytes
//   0x0ac314: 39402000  ldrb     w0, [x0, #8]
//   0x0ac318: 14018D3C  b        #0x10f808
//   0x0ac31c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0ac320: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0066_0x0ac314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac314ULL ^ (static_cast<uint64_t>(0x39402000ULL) << 13);
    acc = (acc + a1 + 0x14018d3cULL) ^ 0x06af00ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0067 | PC: 0x0ac3c8 | FDE: 0x06af68 | Size: 120 bytes
// Khung tháo gỡ #0067 | Địa chỉ PC: 0x0ac3c8 | Địa chỉ FDE: 0x06af68 | Kích thước: 120 bytes
//   0x0ac3c8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0ac3cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ac3d0: F9400415  ldr      x21, [x0, #8]
//   0x0ac3d4: 94032608  bl       #0x175bf4
static inline uint64_t fde_func_0067_0x0ac3c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac3c8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06af68ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0068 | PC: 0x0ac440 | FDE: 0x06afd0 | Size: 220 bytes
// Khung tháo gỡ #0068 | Địa chỉ PC: 0x0ac440 | Địa chỉ FDE: 0x06afd0 | Kích thước: 220 bytes
//   0x0ac440: F9400001  ldr      x1, [x0]
//   0x0ac444: 14000001  b        #0xac448
//   0x0ac448: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0ac44c: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0068_0x0ac440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac440ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x06afd0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0069 | PC: 0x0ac51c | FDE: 0x06b048 | Size: 104 bytes
// Khung tháo gỡ #0069 | Địa chỉ PC: 0x0ac51c | Địa chỉ FDE: 0x06b048 | Kích thước: 104 bytes
//   0x0ac51c: AA1F03E1  mov      x1, xzr
//   0x0ac520: 14000001  b        #0xac524
//   0x0ac524: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac528: 9403302B  bl       #0x1785d4
static inline uint64_t fde_func_0069_0x0ac51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac51cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x06b048ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0070 | PC: 0x0ac584 | FDE: 0x06b0a8 | Size: 92 bytes
// Khung tháo gỡ #0070 | Địa chỉ PC: 0x0ac584 | Địa chỉ FDE: 0x06b0a8 | Kích thước: 92 bytes
//   0x0ac584: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac588: 90000708  adrp     x8, #0x18c000
//   0x0ac58c: 9112C108  add      x8, x8, #0x4b0
//   0x0ac590: 940331EC  bl       #0x178d40
static inline uint64_t fde_func_0070_0x0ac584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac584ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000708ULL) ^ 0x06b0a8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0071 | PC: 0x0ac5e0 | FDE: 0x06b108 | Size: 200 bytes
// Khung tháo gỡ #0071 | Địa chỉ PC: 0x0ac5e0 | Địa chỉ FDE: 0x06b108 | Kích thước: 200 bytes
//   0x0ac5e0: D10083FF  sub      sp, sp, #0x20
//   0x0ac5e4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ac5e8: AA0003F3  mov      x19, x0
//   0x0ac5ec: F84C0E60  ldr      x0, [x19, #0xc0]!
static inline uint64_t fde_func_0071_0x0ac5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac5e0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06b108ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0072 | PC: 0x0ac6a8 | FDE: 0x06b170 | Size: 80 bytes
// Khung tháo gỡ #0072 | Địa chỉ PC: 0x0ac6a8 | Địa chỉ FDE: 0x06b170 | Kích thước: 80 bytes
//   0x0ac6a8: AA1F03E1  mov      x1, xzr
//   0x0ac6ac: 14000001  b        #0xac6b0
//   0x0ac6b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac6b4: 94032FC8  bl       #0x1785d4
static inline uint64_t fde_func_0072_0x0ac6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac6a8ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x06b170ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0073 | PC: 0x0ac6f8 | FDE: 0x06b1d0 | Size: 256 bytes
// Khung tháo gỡ #0073 | Địa chỉ PC: 0x0ac6f8 | Địa chỉ FDE: 0x06b1d0 | Kích thước: 256 bytes
//   0x0ac6f8: B40000E0  cbz      x0, #0xac714
//   0x0ac6fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac700: AA0003F3  mov      x19, x0
//   0x0ac704: 94036BEB  bl       #0x1876b0
static inline uint64_t fde_func_0073_0x0ac6f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac6f8ULL ^ (static_cast<uint64_t>(0xb40000e0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x06b1d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0074 | PC: 0x0ac824 | FDE: 0x06b250 | Size: 248 bytes
// Khung tháo gỡ #0074 | Địa chỉ PC: 0x0ac824 | Địa chỉ FDE: 0x06b250 | Kích thước: 248 bytes
//   0x0ac824: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac828: AA0003F3  mov      x19, x0
//   0x0ac82c: 97FFFFE9  bl       #0xac7d0
//   0x0ac830: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0074_0x0ac824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac824ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06b250ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0075 | PC: 0x0ac91c | FDE: 0x06b2b0 | Size: 256 bytes
// Khung tháo gỡ #0075 | Địa chỉ PC: 0x0ac91c | Địa chỉ FDE: 0x06b2b0 | Kích thước: 256 bytes
//   0x0ac91c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ac920: 94032C6A  bl       #0x177ac8
//   0x0ac924: B4000113  cbz      x19, #0xac944
//   0x0ac928: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0075_0x0ac91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac91cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94032c6aULL) ^ 0x06b2b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0076 | PC: 0x0aca9c | FDE: 0x06b310 | Size: 256 bytes
// Khung tháo gỡ #0076 | Địa chỉ PC: 0x0aca9c | Địa chỉ FDE: 0x06b310 | Kích thước: 256 bytes
//   0x0aca9c: 14032FBF  b        #0x178998
//   0x0acaa0: D105C3FF  sub      sp, sp, #0x170
//   0x0acaa4: A9145BFC  stp      x28, x22, [sp, #0x140]
//   0x0acaa8: A91553F5  stp      x21, x20, [sp, #0x150]
static inline uint64_t fde_func_0076_0x0aca9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aca9cULL ^ (static_cast<uint64_t>(0x14032fbfULL) << 13);
    acc = (acc + a1 + 0xd105c3ffULL) ^ 0x06b310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0077 | PC: 0x0acd00 | FDE: 0x06b380 | Size: 80 bytes
// Khung tháo gỡ #0077 | Địa chỉ PC: 0x0acd00 | Địa chỉ FDE: 0x06b380 | Kích thước: 80 bytes
//   0x0acd00: F8410C08  ldr      x8, [x0, #0x10]!
//   0x0acd04: B4000048  cbz      x8, #0xacd0c
//   0x0acd08: 17FFFDDD  b        #0xac47c
//   0x0acd0c: D65F03C0  ret      
static inline uint64_t fde_func_0077_0x0acd00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acd00ULL ^ (static_cast<uint64_t>(0xf8410c08ULL) << 13);
    acc = (acc + a1 + 0xb4000048ULL) ^ 0x06b380ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0078 | PC: 0x0acd50 | FDE: 0x06b3e0 | Size: 96 bytes
// Khung tháo gỡ #0078 | Địa chỉ PC: 0x0acd50 | Địa chỉ FDE: 0x06b3e0 | Kích thước: 96 bytes
//   0x0acd50: B4000120  cbz      x0, #0xacd74
//   0x0acd54: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0acd58: 94032A8A  bl       #0x177780
//   0x0acd5c: 97FFFFFD  bl       #0xacd50
static inline uint64_t fde_func_0078_0x0acd50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acd50ULL ^ (static_cast<uint64_t>(0xb4000120ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x06b3e0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0079 | PC: 0x0acdb0 | FDE: 0x06b440 | Size: 80 bytes
// Khung tháo gỡ #0079 | Địa chỉ PC: 0x0acdb0 | Địa chỉ FDE: 0x06b440 | Kích thước: 80 bytes
//   0x0acdb0: F9400808  ldr      x8, [x0, #0x10]
//   0x0acdb4: 90000709  adrp     x9, #0x18c000
//   0x0acdb8: 9113A129  add      x9, x9, #0x4e8
//   0x0acdbc: 14033C69  b        #0x17bf60
static inline uint64_t fde_func_0079_0x0acdb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acdb0ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x06b440ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0080 | PC: 0x0ace00 | FDE: 0x06b4a0 | Size: 100 bytes
// Khung tháo gỡ #0080 | Địa chỉ PC: 0x0ace00 | Địa chỉ FDE: 0x06b4a0 | Kích thước: 100 bytes
//   0x0ace00: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ace04: AA0003F3  mov      x19, x0
//   0x0ace08: 97FFFFF6  bl       #0xacde0
//   0x0ace0c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0080_0x0ace00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ace00ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06b4a0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0081 | PC: 0x0ace64 | FDE: 0x06b500 | Size: 256 bytes [_ZN4lynx6canvas9CanvasApp15OnRuntimeAttachENS_7binding3EnvE]
// Khung tháo gỡ #0081 | Địa chỉ PC: 0x0ace64 | Địa chỉ FDE: 0x06b500 | Kích thước: 256 bytes
//   0x0ace64: D10683FF  sub      sp, sp, #0x1a0
//   0x0ace68: F900B3FC  str      x28, [sp, #0x160]
//   0x0ace6c: A9175BF7  stp      x23, x22, [sp, #0x170]
//   0x0ace70: A91853F5  stp      x21, x20, [sp, #0x180]
static inline uint64_t fde_func_0081_0x0ace64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ace64ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x06b500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0082 | PC: 0x0ad000 | FDE: 0x06b570 | Size: 16 bytes
// Khung tháo gỡ #0082 | Địa chỉ PC: 0x0ad000 | Địa chỉ FDE: 0x06b570 | Kích thước: 16 bytes
//   0x0ad000: AA1E03E2  mov      x2, x30
//   0x0ad004: 94032B20  bl       #0x177c84
//   0x0ad008: AA0203FE  mov      x30, x2
//   0x0ad00c: 17FFFFEF  b        #0xacfc8
static inline uint64_t fde_func_0082_0x0ad000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad000ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94032b20ULL) ^ 0x06b570ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0083 | PC: 0x0ad010 | FDE: 0x06b588 | Size: 256 bytes [_ZN4lynx6canvas9CanvasApp32RegisterVisibilityStatusObserverENSt6__ndk18weak_ptrINS0_24VisibilityStatusObserverEEE]
// Khung tháo gỡ #0083 | Địa chỉ PC: 0x0ad010 | Địa chỉ FDE: 0x06b588 | Kích thước: 256 bytes
//   0x0ad010: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0ad014: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0ad018: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ad01c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0083_0x0ad010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad010ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06b588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0084 | PC: 0x0ad198 | FDE: 0x06b5e8 | Size: 100 bytes
// Khung tháo gỡ #0084 | Địa chỉ PC: 0x0ad198 | Địa chỉ FDE: 0x06b5e8 | Kích thước: 100 bytes
//   0x0ad198: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ad19c: B50000E0  cbnz     x0, #0xad1b8
//   0x0ad1a0: 90000768  adrp     x8, #0x199000
//   0x0ad1a4: 91118108  add      x8, x8, #0x460
static inline uint64_t fde_func_0084_0x0ad198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad198ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb50000e0ULL) ^ 0x06b5e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0085 | PC: 0x0ad1fc | FDE: 0x06b648 | Size: 120 bytes [_ZN4lynx6canvas9CanvasApp14OnRemoteAttachENSt6__ndk110unique_ptrINS1_14RemoteDelegateENS2_14default_deleteIS4_EEEE]
// Khung tháo gỡ #0085 | Địa chỉ PC: 0x0ad1fc | Địa chỉ FDE: 0x06b648 | Kích thước: 120 bytes
//   0x0ad1fc: D10583FF  sub      sp, sp, #0x160
//   0x0ad200: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0ad204: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ad208: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0085_0x0ad1fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad1fcULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x06b648ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0086 | PC: 0x0ad274 | FDE: 0x06b670 | Size: 256 bytes [_ZN4lynx6canvas9CanvasApp17GetRemoteDelegateEv]
// Khung tháo gỡ #0086 | Địa chỉ PC: 0x0ad274 | Địa chỉ FDE: 0x06b670 | Kích thước: 256 bytes
//   0x0ad274: F9409800  ldr      x0, [x0, #0x130]
//   0x0ad278: D65F03C0  ret      
//   0x0ad27c: D101C3FF  sub      sp, sp, #0x70
//   0x0ad280: F90023F6  str      x22, [sp, #0x40]
static inline uint64_t fde_func_0086_0x0ad274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad274ULL ^ (static_cast<uint64_t>(0xf9409800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06b670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0087 | PC: 0x0ae1e8 | FDE: 0x06b6d8 | Size: 256 bytes
// Khung tháo gỡ #0087 | Địa chỉ PC: 0x0ae1e8 | Địa chỉ FDE: 0x06b6d8 | Kích thước: 256 bytes
//   0x0ae1e8: D10603FF  sub      sp, sp, #0x180
//   0x0ae1ec: A91463FC  stp      x28, x24, [sp, #0x140]
//   0x0ae1f0: A9155BF7  stp      x23, x22, [sp, #0x150]
//   0x0ae1f4: A91653F5  stp      x21, x20, [sp, #0x160]
static inline uint64_t fde_func_0087_0x0ae1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae1e8ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa91463fcULL) ^ 0x06b6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0088 | PC: 0x0ae578 | FDE: 0x06b778 | Size: 256 bytes
// Khung tháo gỡ #0088 | Địa chỉ PC: 0x0ae578 | Địa chỉ FDE: 0x06b778 | Kích thước: 256 bytes
//   0x0ae578: D10583FF  sub      sp, sp, #0x160
//   0x0ae57c: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0ae580: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ae584: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0088_0x0ae578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae578ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x06b778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0089 | PC: 0x0ae924 | FDE: 0x06b818 | Size: 256 bytes
// Khung tháo gỡ #0089 | Địa chỉ PC: 0x0ae924 | Địa chỉ FDE: 0x06b818 | Kích thước: 256 bytes
//   0x0ae924: A9400048  ldp      x8, x0, [x2]
//   0x0ae928: B40000C0  cbz      x0, #0xae940
//   0x0ae92c: 91002009  add      x9, x0, #8
//   0x0ae930: AA1E03E1  mov      x1, x30
static inline uint64_t fde_func_0089_0x0ae924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae924ULL ^ (static_cast<uint64_t>(0xa9400048ULL) << 13);
    acc = (acc + a1 + 0xb40000c0ULL) ^ 0x06b818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0090 | PC: 0x0aebf8 | FDE: 0x06b8a8 | Size: 256 bytes
// Khung tháo gỡ #0090 | Địa chỉ PC: 0x0aebf8 | Địa chỉ FDE: 0x06b8a8 | Kích thước: 256 bytes
//   0x0aebf8: D10103FF  sub      sp, sp, #0x40
//   0x0aebfc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0aec00: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0aec04: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0090_0x0aebf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aebf8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06b8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0091 | PC: 0x0aeda8 | FDE: 0x06b920 | Size: 256 bytes
// Khung tháo gỡ #0091 | Địa chỉ PC: 0x0aeda8 | Địa chỉ FDE: 0x06b920 | Kích thước: 256 bytes
//   0x0aeda8: AA1E03E1  mov      x1, x30
//   0x0aedac: 94032F7B  bl       #0x17ab98
//   0x0aedb0: AA0103FE  mov      x30, x1
//   0x0aedb4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0091_0x0aeda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeda8ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94032f7bULL) ^ 0x06b920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0092 | PC: 0x0aeff0 | FDE: 0x06b9a8 | Size: 120 bytes
// Khung tháo gỡ #0092 | Địa chỉ PC: 0x0aeff0 | Địa chỉ FDE: 0x06b9a8 | Kích thước: 120 bytes
//   0x0aeff0: B40001E0  cbz      x0, #0xaf02c
//   0x0aeff4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0aeff8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0aeffc: 94034D72  bl       #0x1825c4
static inline uint64_t fde_func_0092_0x0aeff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeff0ULL ^ (static_cast<uint64_t>(0xb40001e0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x06b9a8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0093 | PC: 0x0af068 | FDE: 0x06ba10 | Size: 256 bytes
// Khung tháo gỡ #0093 | Địa chỉ PC: 0x0af068 | Địa chỉ FDE: 0x06ba10 | Kích thước: 256 bytes
//   0x0af068: D10103FF  sub      sp, sp, #0x40
//   0x0af06c: FD000BE8  str      d8, [sp, #0x10]
//   0x0af070: F9000FF6  str      x22, [sp, #0x18]
//   0x0af074: A90253F5  stp      x21, x20, [sp, #0x20]
static inline uint64_t fde_func_0093_0x0af068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af068ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x06ba10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0094 | PC: 0x0af1cc | FDE: 0x06ba90 | Size: 80 bytes
// Khung tháo gỡ #0094 | Địa chỉ PC: 0x0af1cc | Địa chỉ FDE: 0x06ba90 | Kích thước: 80 bytes
//   0x0af1cc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0af1d0: 940347F7  bl       #0x1811ac
//   0x0af1d4: 97FFF2B9  bl       #0xabcb8
//   0x0af1d8: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0094_0x0af1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af1ccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940347f7ULL) ^ 0x06ba90ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0095 | PC: 0x0af21c | FDE: 0x06baf0 | Size: 256 bytes
// Khung tháo gỡ #0095 | Địa chỉ PC: 0x0af21c | Địa chỉ FDE: 0x06baf0 | Kích thước: 256 bytes
//   0x0af21c: B00006E8  adrp     x8, #0x18c000
//   0x0af220: 9121C108  add      x8, x8, #0x870
//   0x0af224: F8008408  str      x8, [x0], #8
//   0x0af228: 17FFF2A4  b        #0xabcb8
static inline uint64_t fde_func_0095_0x0af21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af21cULL ^ (static_cast<uint64_t>(0xb00006e8ULL) << 13);
    acc = (acc + a1 + 0x9121c108ULL) ^ 0x06baf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0096 | PC: 0x0af328 | FDE: 0x06bb68 | Size: 156 bytes
// Khung tháo gỡ #0096 | Địa chỉ PC: 0x0af328 | Địa chỉ FDE: 0x06bb68 | Kích thước: 156 bytes
//   0x0af328: F9400808  ldr      x8, [x0, #0x10]
//   0x0af32c: B00006E9  adrp     x9, #0x18c000
//   0x0af330: 91226129  add      x9, x9, #0x898
//   0x0af334: 1403330B  b        #0x17bf60
static inline uint64_t fde_func_0096_0x0af328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af328ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb00006e9ULL) ^ 0x06bb68ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0097 | PC: 0x0af3c4 | FDE: 0x06bbd0 | Size: 132 bytes
// Khung tháo gỡ #0097 | Địa chỉ PC: 0x0af3c4 | Địa chỉ FDE: 0x06bbd0 | Kích thước: 132 bytes
//   0x0af3c4: D10083FF  sub      sp, sp, #0x20
//   0x0af3c8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0af3cc: 94033FD1  bl       #0x17f310
//   0x0af3d0: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0097_0x0af3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af3c4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06bbd0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0098 | PC: 0x0af448 | FDE: 0x06bc30 | Size: 112 bytes
// Khung tháo gỡ #0098 | Địa chỉ PC: 0x0af448 | Địa chỉ FDE: 0x06bc30 | Kích thước: 112 bytes
//   0x0af448: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0af44c: 94032462  bl       #0x1785d4
//   0x0af450: B40000B3  cbz      x19, #0xaf464
//   0x0af454: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0098_0x0af448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af448ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94032462ULL) ^ 0x06bc30ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0099 | PC: 0x0af4b8 | FDE: 0x06bc90 | Size: 136 bytes
// Khung tháo gỡ #0099 | Địa chỉ PC: 0x0af4b8 | Địa chỉ FDE: 0x06bc90 | Kích thước: 136 bytes
//   0x0af4b8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0af4bc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0af4c0: 9403256B  bl       #0x178a6c
//   0x0af4c4: 9403603B  bl       #0x1875b0
static inline uint64_t fde_func_0099_0x0af4b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af4b8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06bc90ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0100 | PC: 0x0af540 | FDE: 0x06bcd0 | Size: 76 bytes [_ZN4lynx6canvas8GLRasterD0Ev]
// Khung tháo gỡ #0100 | Địa chỉ PC: 0x0af540 | Địa chỉ FDE: 0x06bcd0 | Kích thước: 76 bytes
//   0x0af540: D4200020  brk      #1
//   0x0af544: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0af548: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0af54c: F9400014  ldr      x20, [x0]
static inline uint64_t fde_func_0100_0x0af540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af540ULL ^ (static_cast<uint64_t>(0xd4200020ULL) << 13);
    acc = (acc + a1 + 0xa9be53f5ULL) ^ 0x06bcd0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0101 | PC: 0x0af58c | FDE: 0x06bd08 | Size: 256 bytes
// Khung tháo gỡ #0101 | Địa chỉ PC: 0x0af58c | Địa chỉ FDE: 0x06bd08 | Kích thước: 256 bytes
//   0x0af58c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0af590: B00006E8  adrp     x8, #0x18c000
//   0x0af594: B00006E9  adrp     x9, #0x18c000
//   0x0af598: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0101_0x0af58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af58cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb00006e8ULL) ^ 0x06bd08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0102 | PC: 0x0af6c8 | FDE: 0x06bd78 | Size: 256 bytes
// Khung tháo gỡ #0102 | Địa chỉ PC: 0x0af6c8 | Địa chỉ FDE: 0x06bd78 | Kích thước: 256 bytes
//   0x0af6c8: AA1E03E1  mov      x1, x30
//   0x0af6cc: 94031E1D  bl       #0x176f40
//   0x0af6d0: AA0103FE  mov      x30, x1
//   0x0af6d4: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_0102_0x0af6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af6c8ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94031e1dULL) ^ 0x06bd78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0103 | PC: 0x0af8b4 | FDE: 0x06bdf0 | Size: 8 bytes [_ZN4lynx6canvas16CanvasAppAndroid6GetIMPEv]
// Khung tháo gỡ #0103 | Địa chỉ PC: 0x0af8b4 | Địa chỉ FDE: 0x06bdf0 | Kích thước: 8 bytes
//   0x0af8b4: F940B000  ldr      x0, [x0, #0x160]
//   0x0af8b8: D65F03C0  ret      
static inline uint64_t fde_func_0103_0x0af8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af8b4ULL ^ (static_cast<uint64_t>(0xf940b000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06bdf0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0104 | PC: 0x0af8bc | FDE: 0x06be08 | Size: 164 bytes [_ZN4lynx6canvas16CanvasAppAndroid28UnwrapNativeCanvasAppWeakPtrEl]
// Khung tháo gỡ #0104 | Địa chỉ PC: 0x0af8bc | Địa chỉ FDE: 0x06be08 | Kích thước: 164 bytes
//   0x0af8bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0af8c0: B40001E0  cbz      x0, #0xaf8fc
//   0x0af8c4: F9400009  ldr      x9, [x0]
//   0x0af8c8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0104_0x0af8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af8bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb40001e0ULL) ^ 0x06be08ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0105 | PC: 0x0af960 | FDE: 0x06be60 | Size: 256 bytes
// Khung tháo gỡ #0105 | Địa chỉ PC: 0x0af960 | Địa chỉ FDE: 0x06be60 | Kích thước: 256 bytes
//   0x0af960: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0af964: AA1F03E0  mov      x0, xzr
//   0x0af968: 94035F8E  bl       #0x1877a0
//   0x0af96c: 94035F91  bl       #0x1877b0
static inline uint64_t fde_func_0105_0x0af960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af960ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x06be60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0106 | PC: 0x0afd40 | FDE: 0x06bef8 | Size: 84 bytes
// Khung tháo gỡ #0106 | Địa chỉ PC: 0x0afd40 | Địa chỉ FDE: 0x06bef8 | Kích thước: 84 bytes
//   0x0afd40: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0afd44: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0afd48: 94032AB3  bl       #0x17a814
//   0x0afd4c: A9417BF3  ldp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0106_0x0afd40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afd40ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06bef8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0107 | PC: 0x0afd94 | FDE: 0x06bf60 | Size: 256 bytes
// Khung tháo gỡ #0107 | Địa chỉ PC: 0x0afd94 | Địa chỉ FDE: 0x06bf60 | Kích thước: 256 bytes
//   0x0afd94: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0afd98: AA0003F3  mov      x19, x0
//   0x0afd9c: 97FFFFFA  bl       #0xafd84
//   0x0afda0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0107_0x0afd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afd94ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06bf60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0108 | PC: 0x0afe94 | FDE: 0x06bfd0 | Size: 104 bytes
// Khung tháo gỡ #0108 | Địa chỉ PC: 0x0afe94 | Địa chỉ FDE: 0x06bfd0 | Kích thước: 104 bytes
//   0x0afe94: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0afe98: 940323A7  bl       #0x178d34
//   0x0afe9c: 94000004  bl       #0xafeac
//   0x0afea0: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0108_0x0afe94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afe94ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940323a7ULL) ^ 0x06bfd0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0109 | PC: 0x0afefc | FDE: 0x06c030 | Size: 256 bytes
// Khung tháo gỡ #0109 | Địa chỉ PC: 0x0afefc | Địa chỉ FDE: 0x06c030 | Kích thước: 256 bytes
//   0x0afefc: AA1E03E2  mov      x2, x30
//   0x0aff00: 94031F61  bl       #0x177c84
//   0x0aff04: AA0203FE  mov      x30, x2
//   0x0aff08: 17FFFFAD  b        #0xafdbc
static inline uint64_t fde_func_0109_0x0afefc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afefcULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94031f61ULL) ^ 0x06c030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0110 | PC: 0x0b01c4 | FDE: 0x06c0b0 | Size: 256 bytes
// Khung tháo gỡ #0110 | Địa chỉ PC: 0x0b01c4 | Địa chỉ FDE: 0x06c0b0 | Kích thước: 256 bytes
//   0x0b01c4: 39400008  ldrb     w8, [x0]
//   0x0b01c8: 37000088  tbnz     w8, #0, #0xb01d8
//   0x0b01cc: 91000400  add      x0, x0, #1
//   0x0b01d0: D341FD01  lsr      x1, x8, #1
static inline uint64_t fde_func_0110_0x0b01c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b01c4ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000088ULL) ^ 0x06c0b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0111 | PC: 0x0b0484 | FDE: 0x06c118 | Size: 176 bytes
// Khung tháo gỡ #0111 | Địa chỉ PC: 0x0b0484 | Địa chỉ FDE: 0x06c118 | Kích thước: 176 bytes
//   0x0b0484: AA1F03E1  mov      x1, xzr
//   0x0b0488: 14000010  b        #0xb04c8
//   0x0b048c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0490: 94033977  bl       #0x17ea6c
static inline uint64_t fde_func_0111_0x0b0484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0484ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14000010ULL) ^ 0x06c118ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0112 | PC: 0x0b0534 | FDE: 0x06c178 | Size: 212 bytes
// Khung tháo gỡ #0112 | Địa chỉ PC: 0x0b0534 | Địa chỉ FDE: 0x06c178 | Kích thước: 212 bytes
//   0x0b0534: D10483FF  sub      sp, sp, #0x120
//   0x0b0538: F90083FC  str      x28, [sp, #0x100]
//   0x0b053c: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x0b0540: 940314DF  bl       #0x1758bc
static inline uint64_t fde_func_0112_0x0b0534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0534ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x06c178ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0113 | PC: 0x0b0608 | FDE: 0x06c1d0 | Size: 120 bytes [_ZN4lynx6canvas6BitmapC1EjjNS0_10DataFormatENSt6__ndk110unique_ptrINS0_10DataHolderENS3_14default_deleteIS5_EEEEjbb]
// Khung tháo gỡ #0113 | Địa chỉ PC: 0x0b0608 | Địa chỉ FDE: 0x06c1d0 | Kích thước: 120 bytes
//   0x0b0608: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0b060c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b0610: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b0614: F940008A  ldr      x10, [x4]
static inline uint64_t fde_func_0113_0x0b0608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0608ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06c1d0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0114 | PC: 0x0b0680 | FDE: 0x06c1f0 | Size: 256 bytes [_ZN4lynx6canvas6Bitmap5FlipYEv]
// Khung tháo gỡ #0114 | Địa chỉ PC: 0x0b0680 | Địa chỉ FDE: 0x06c1f0 | Kích thước: 256 bytes
//   0x0b0680: AA1E03E1  mov      x1, x30
//   0x0b0684: 94031C73  bl       #0x177850
//   0x0b0688: AA0103FE  mov      x30, x1
//   0x0b068c: A9197BFD  stp      x29, x30, [sp, #0x190]
static inline uint64_t fde_func_0114_0x0b0680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0680ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94031c73ULL) ^ 0x06c1f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0115 | PC: 0x0b07d0 | FDE: 0x06c220 | Size: 256 bytes [_ZN4lynx6canvas6Bitmap13ExtractBitmapEbjj]
// Khung tháo gỡ #0115 | Địa chỉ PC: 0x0b07d0 | Địa chỉ FDE: 0x06c220 | Kích thước: 256 bytes
//   0x0b07d0: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0b07d4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0b07d8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b07dc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0115_0x0b07d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b07d0ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06c220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0116 | PC: 0x0b08d4 | FDE: 0x06c248 | Size: 8 bytes [_ZNK4lynx6canvas6Bitmap14HasPremulAlphaEv]
// Khung tháo gỡ #0116 | Địa chỉ PC: 0x0b08d4 | Địa chỉ FDE: 0x06c248 | Kích thước: 8 bytes
//   0x0b08d4: 39406000  ldrb     w0, [x0, #0x18]
//   0x0b08d8: D65F03C0  ret      
static inline uint64_t fde_func_0116_0x0b08d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08d4ULL ^ (static_cast<uint64_t>(0x39406000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06c248ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0117 | PC: 0x0b08dc | FDE: 0x06c260 | Size: 8 bytes [_ZN4lynx6canvas6Bitmap8HasFlipYEv]
// Khung tháo gỡ #0117 | Địa chỉ PC: 0x0b08dc | Địa chỉ FDE: 0x06c260 | Kích thước: 8 bytes
//   0x0b08dc: 39406400  ldrb     w0, [x0, #0x19]
//   0x0b08e0: D65F03C0  ret      
static inline uint64_t fde_func_0117_0x0b08dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08dcULL ^ (static_cast<uint64_t>(0x39406400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06c260ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0118 | PC: 0x0b08e4 | FDE: 0x06c278 | Size: 4 bytes [_ZN4lynx6canvas11Framebuffer3FboEv]
// Khung tháo gỡ #0118 | Địa chỉ PC: 0x0b08e4 | Địa chỉ FDE: 0x06c278 | Kích thước: 4 bytes
//   0x0b08e4: 1403468B  b        #0x182310
static inline uint64_t fde_func_0118_0x0b08e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08e4ULL ^ (static_cast<uint64_t>(0x1403468bULL) << 13);
    acc = (acc + a1 + 0x14034688ULL) ^ 0x06c278ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0119 | PC: 0x0b08e8 | FDE: 0x06c290 | Size: 4 bytes [_ZN4lynx6canvas11Framebuffer7TextureEv]
// Khung tháo gỡ #0119 | Địa chỉ PC: 0x0b08e8 | Địa chỉ FDE: 0x06c290 | Kích thước: 4 bytes
//   0x0b08e8: 14034688  b        #0x182308
static inline uint64_t fde_func_0119_0x0b08e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08e8ULL ^ (static_cast<uint64_t>(0x14034688ULL) << 13);
    acc = (acc + a1 + 0x14035131ULL) ^ 0x06c290ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0120 | PC: 0x0b08ec | FDE: 0x06c2a8 | Size: 4 bytes [_ZNK4lynx6canvas6Bitmap11PixelFormatEv]
// Khung tháo gỡ #0120 | Địa chỉ PC: 0x0b08ec | Địa chỉ FDE: 0x06c2a8 | Kích thước: 4 bytes
//   0x0b08ec: 14035131  b        #0x184db0
static inline uint64_t fde_func_0120_0x0b08ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08ecULL ^ (static_cast<uint64_t>(0x14035131ULL) << 13);
    acc = (acc + a1 + 0xb9401400ULL) ^ 0x06c2a8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0121 | PC: 0x0b08f0 | FDE: 0x06c2c0 | Size: 8 bytes [_ZNK4lynx6canvas6Bitmap9AlignmentEv]
// Khung tháo gỡ #0121 | Địa chỉ PC: 0x0b08f0 | Địa chỉ FDE: 0x06c2c0 | Kích thước: 8 bytes
//   0x0b08f0: B9401400  ldr      w0, [x0, #0x14]
//   0x0b08f4: D65F03C0  ret      
static inline uint64_t fde_func_0121_0x0b08f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08f0ULL ^ (static_cast<uint64_t>(0xb9401400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06c2c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0122 | PC: 0x0b08f8 | FDE: 0x06c2d8 | Size: 8 bytes [_ZNK4lynx6canvas6Bitmap9PixelsLenEv]
// Khung tháo gỡ #0122 | Địa chỉ PC: 0x0b08f8 | Địa chỉ FDE: 0x06c2d8 | Kích thước: 8 bytes
//   0x0b08f8: B9402400  ldr      w0, [x0, #0x24]
//   0x0b08fc: D65F03C0  ret      
static inline uint64_t fde_func_0122_0x0b08f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08f8ULL ^ (static_cast<uint64_t>(0xb9402400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06c2d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0123 | PC: 0x0b0900 | FDE: 0x06c2f0 | Size: 8 bytes [_ZNK4lynx6canvas6Bitmap11BytesPerRowEv]
// Khung tháo gỡ #0123 | Địa chỉ PC: 0x0b0900 | Địa chỉ FDE: 0x06c2f0 | Kích thước: 8 bytes
//   0x0b0900: B9402000  ldr      w0, [x0, #0x20]
//   0x0b0904: D65F03C0  ret      
static inline uint64_t fde_func_0123_0x0b0900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0900ULL ^ (static_cast<uint64_t>(0xb9402000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06c2f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0124 | PC: 0x0b0908 | FDE: 0x06c308 | Size: 12 bytes [_ZNK4lynx6canvas6Bitmap6PixelsEv]
// Khung tháo gỡ #0124 | Địa chỉ PC: 0x0b0908 | Địa chỉ FDE: 0x06c308 | Kích thước: 12 bytes
//   0x0b0908: F9400008  ldr      x8, [x0]
//   0x0b090c: F9400100  ldr      x0, [x8]
//   0x0b0910: D65F03C0  ret      
static inline uint64_t fde_func_0124_0x0b0908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0908ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x06c308ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0125 | PC: 0x0b0914 | FDE: 0x06c320 | Size: 32 bytes [_ZN4lynx6canvas6Bitmap13ReleasePixelsERPFvPKvPvERS4_]
// Khung tháo gỡ #0125 | Địa chỉ PC: 0x0b0914 | Địa chỉ FDE: 0x06c320 | Kích thước: 32 bytes
//   0x0b0914: F9400008  ldr      x8, [x0]
//   0x0b0918: F9400D09  ldr      x9, [x8, #0x18]
//   0x0b091c: F9400100  ldr      x0, [x8]
//   0x0b0920: F900011F  str      xzr, [x8]
static inline uint64_t fde_func_0125_0x0b0914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0914ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400d09ULL) ^ 0x06c320ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0126 | PC: 0x0b0934 | FDE: 0x06c338 | Size: 108 bytes [_ZN4lynx6canvas6Bitmap10IsValidateEv]
// Khung tháo gỡ #0126 | Địa chỉ PC: 0x0b0934 | Địa chỉ FDE: 0x06c338 | Kích thước: 108 bytes
//   0x0b0934: B9400808  ldr      w8, [x0, #8]
//   0x0b0938: 34000148  cbz      w8, #0xb0960
//   0x0b093c: B9400C08  ldr      w8, [x0, #0xc]
//   0x0b0940: 34000108  cbz      w8, #0xb0960
static inline uint64_t fde_func_0126_0x0b0934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0934ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0x34000148ULL) ^ 0x06c338ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0127 | PC: 0x0b09a0 | FDE: 0x06c398 | Size: 256 bytes
// Khung tháo gỡ #0127 | Địa chỉ PC: 0x0b09a0 | Địa chỉ FDE: 0x06c398 | Kích thước: 256 bytes
//   0x0b09a0: AA1E03E5  mov      x5, x30
//   0x0b09a4: 94031A01  bl       #0x1771a8
//   0x0b09a8: AA0503FE  mov      x30, x5
//   0x0b09ac: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0127_0x0b09a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b09a0ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94031a01ULL) ^ 0x06c398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0128 | PC: 0x0b0cb8 | FDE: 0x06c418 | Size: 256 bytes
// Khung tháo gỡ #0128 | Địa chỉ PC: 0x0b0cb8 | Địa chỉ FDE: 0x06c418 | Kích thước: 256 bytes
//   0x0b0cb8: 6DB63BEF  stp      d15, d14, [sp, #-0xa0]!
//   0x0b0cbc: 6D0133ED  stp      d13, d12, [sp, #0x10]
//   0x0b0cc0: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x0b0cc4: 6D0323E9  stp      d9, d8, [sp, #0x30]
static inline uint64_t fde_func_0128_0x0b0cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0cb8ULL ^ (static_cast<uint64_t>(0x6db63befULL) << 13);
    acc = (acc + a1 + 0x6d0133edULL) ^ 0x06c418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0129 | PC: 0x0b1164 | FDE: 0x06c4a8 | Size: 256 bytes
// Khung tháo gỡ #0129 | Địa chỉ PC: 0x0b1164 | Địa chỉ FDE: 0x06c4a8 | Kích thước: 256 bytes
//   0x0b1164: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b1168: 9403244B  bl       #0x17a294
//   0x0b116c: 97FFE8EA  bl       #0xab514
//   0x0b1170: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0129_0x0b1164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1164ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403244bULL) ^ 0x06c4a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0130 | PC: 0x0b126c | FDE: 0x06c518 | Size: 256 bytes
// Khung tháo gỡ #0130 | Địa chỉ PC: 0x0b126c | Địa chỉ FDE: 0x06c518 | Kích thước: 256 bytes
//   0x0b126c: F9400028  ldr      x8, [x1]
//   0x0b1270: AA1E03E2  mov      x2, x30
//   0x0b1274: 940348C2  bl       #0x18357c
//   0x0b1278: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_0130_0x0b126c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b126cULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x06c518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0131 | PC: 0x0b14ac | FDE: 0x06c588 | Size: 256 bytes
// Khung tháo gỡ #0131 | Địa chỉ PC: 0x0b14ac | Địa chỉ FDE: 0x06c588 | Kích thước: 256 bytes
//   0x0b14ac: 39400008  ldrb     w8, [x0]
//   0x0b14b0: 37000068  tbnz     w8, #0, #0xb14bc
//   0x0b14b4: D341FD08  lsr      x8, x8, #1
//   0x0b14b8: 14000002  b        #0xb14c0
static inline uint64_t fde_func_0131_0x0b14ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b14acULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000068ULL) ^ 0x06c588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0132 | PC: 0x0b16ec | FDE: 0x06c5f8 | Size: 140 bytes
// Khung tháo gỡ #0132 | Địa chỉ PC: 0x0b16ec | Địa chỉ FDE: 0x06c5f8 | Kích thước: 140 bytes
//   0x0b16ec: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b16f0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b16f4: F00006C8  adrp     x8, #0x18c000
//   0x0b16f8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0132_0x0b16ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b16ecULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06c5f8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0133 | PC: 0x0b1778 | FDE: 0x06c660 | Size: 256 bytes
// Khung tháo gỡ #0133 | Địa chỉ PC: 0x0b1778 | Địa chỉ FDE: 0x06c660 | Kích thước: 256 bytes
//   0x0b1778: D10583FF  sub      sp, sp, #0x160
//   0x0b177c: F9009BFC  str      x28, [sp, #0x130]
//   0x0b1780: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0b1784: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0133_0x0b1778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1778ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x06c660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0134 | PC: 0x0b195c | FDE: 0x06c6d8 | Size: 8 bytes
// Khung tháo gỡ #0134 | Địa chỉ PC: 0x0b195c | Địa chỉ FDE: 0x06c6d8 | Kích thước: 8 bytes
//   0x0b195c: 3940C400  ldrb     w0, [x0, #0x31]
//   0x0b1960: D65F03C0  ret      
static inline uint64_t fde_func_0134_0x0b195c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b195cULL ^ (static_cast<uint64_t>(0x3940c400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06c6d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0135 | PC: 0x0b1964 | FDE: 0x06c6f0 | Size: 24 bytes [_ZN4lynx6canvas12ImageElement8GetWidthEv]
// Khung tháo gỡ #0135 | Địa chỉ PC: 0x0b1964 | Địa chỉ FDE: 0x06c6f0 | Kích thước: 24 bytes
//   0x0b1964: F9404C08  ldr      x8, [x0, #0x98]
//   0x0b1968: 9103A009  add      x9, x0, #0xe8
//   0x0b196c: 9100210A  add      x10, x8, #8
//   0x0b1970: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0135_0x0b1964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1964ULL ^ (static_cast<uint64_t>(0xf9404c08ULL) << 13);
    acc = (acc + a1 + 0x9103a009ULL) ^ 0x06c6f0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0136 | PC: 0x0b197c | FDE: 0x06c708 | Size: 76 bytes [_ZN4lynx6canvas12ImageElement9GetHeightEv]
// Khung tháo gỡ #0136 | Địa chỉ PC: 0x0b197c | Địa chỉ FDE: 0x06c708 | Kích thước: 76 bytes
//   0x0b197c: F9404C08  ldr      x8, [x0, #0x98]
//   0x0b1980: 9103B009  add      x9, x0, #0xec
//   0x0b1984: 9100310A  add      x10, x8, #0xc
//   0x0b1988: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0136_0x0b197c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b197cULL ^ (static_cast<uint64_t>(0xf9404c08ULL) << 13);
    acc = (acc + a1 + 0x9103b009ULL) ^ 0x06c708ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0137 | PC: 0x0b19c8 | FDE: 0x06c740 | Size: 220 bytes
// Khung tháo gỡ #0137 | Địa chỉ PC: 0x0b19c8 | Địa chỉ FDE: 0x06c740 | Kích thước: 220 bytes
//   0x0b19c8: D100C3FF  sub      sp, sp, #0x30
//   0x0b19cc: F9000BF4  str      x20, [sp, #0x10]
//   0x0b19d0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b19d4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0137_0x0b19c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b19c8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x06c740ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0138 | PC: 0x0b1aa4 | FDE: 0x06c7a8 | Size: 256 bytes
// Khung tháo gỡ #0138 | Địa chỉ PC: 0x0b1aa4 | Địa chỉ FDE: 0x06c7a8 | Kích thước: 256 bytes
//   0x0b1aa4: D1012000  sub      x0, x0, #0x48
//   0x0b1aa8: 17FFFFA7  b        #0xb1944
//   0x0b1aac: D10683FF  sub      sp, sp, #0x1a0
//   0x0b1ab0: F900B3FC  str      x28, [sp, #0x160]
static inline uint64_t fde_func_0138_0x0b1aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1aa4ULL ^ (static_cast<uint64_t>(0xd1012000ULL) << 13);
    acc = (acc + a1 + 0x17ffffa7ULL) ^ 0x06c7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0139 | PC: 0x0b1da0 | FDE: 0x06c820 | Size: 256 bytes
// Khung tháo gỡ #0139 | Địa chỉ PC: 0x0b1da0 | Địa chỉ FDE: 0x06c820 | Kích thước: 256 bytes
//   0x0b1da0: 39400009  ldrb     w9, [x0]
//   0x0b1da4: 37000089  tbnz     w9, #0, #0xb1db4
//   0x0b1da8: 91000408  add      x8, x0, #1
//   0x0b1dac: D341FD29  lsr      x9, x9, #1
static inline uint64_t fde_func_0139_0x0b1da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1da0ULL ^ (static_cast<uint64_t>(0x39400009ULL) << 13);
    acc = (acc + a1 + 0x37000089ULL) ^ 0x06c820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0140 | PC: 0x0b1eb0 | FDE: 0x06c880 | Size: 188 bytes
// Khung tháo gỡ #0140 | Địa chỉ PC: 0x0b1eb0 | Địa chỉ FDE: 0x06c880 | Kích thước: 188 bytes
//   0x0b1eb0: B40000C0  cbz      x0, #0xb1ec8
//   0x0b1eb4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b1eb8: AA0003F3  mov      x19, x0
//   0x0b1ebc: 940333A8  bl       #0x17ed5c
static inline uint64_t fde_func_0140_0x0b1eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1eb0ULL ^ (static_cast<uint64_t>(0xb40000c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x06c880ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0141 | PC: 0x0b1f6c | FDE: 0x06c8e8 | Size: 256 bytes
// Khung tháo gỡ #0141 | Địa chỉ PC: 0x0b1f6c | Địa chỉ FDE: 0x06c8e8 | Kích thước: 256 bytes
//   0x0b1f6c: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x0b1f70: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0b1f74: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b1f78: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0141_0x0b1f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1f6cULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06c8e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0142 | PC: 0x0b23c0 | FDE: 0x06c968 | Size: 104 bytes
// Khung tháo gỡ #0142 | Địa chỉ PC: 0x0b23c0 | Địa chỉ FDE: 0x06c968 | Kích thước: 104 bytes
//   0x0b23c0: 14030DAA  b        #0x175a68
//   0x0b23c4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b23c8: B4000140  cbz      x0, #0xb23f0
//   0x0b23cc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0142_0x0b23c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b23c0ULL ^ (static_cast<uint64_t>(0x14030daaULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x06c968ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0143 | PC: 0x0b2428 | FDE: 0x06c9c8 | Size: 120 bytes
// Khung tháo gỡ #0143 | Địa chỉ PC: 0x0b2428 | Địa chỉ FDE: 0x06c9c8 | Kích thước: 120 bytes
//   0x0b2428: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b242c: AA0003F3  mov      x19, x0
//   0x0b2430: 97FFFFE4  bl       #0xb23c0
//   0x0b2434: D00006C8  adrp     x8, #0x18c000
static inline uint64_t fde_func_0143_0x0b2428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2428ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06c9c8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0144 | PC: 0x0b24a0 | FDE: 0x06ca28 | Size: 256 bytes
// Khung tháo gỡ #0144 | Địa chỉ PC: 0x0b24a0 | Địa chỉ FDE: 0x06ca28 | Kích thước: 256 bytes
//   0x0b24a0: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x0b24a4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0b24a8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b24ac: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0144_0x0b24a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b24a0ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06ca28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0145 | PC: 0x0b26bc | FDE: 0x06caa0 | Size: 256 bytes
// Khung tháo gỡ #0145 | Địa chỉ PC: 0x0b26bc | Địa chỉ FDE: 0x06caa0 | Kích thước: 256 bytes
//   0x0b26bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b26c0: B4000140  cbz      x0, #0xb26e8
//   0x0b26c4: AA0003F3  mov      x19, x0
//   0x0b26c8: 94030FA4  bl       #0x176558
static inline uint64_t fde_func_0145_0x0b26bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b26bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000140ULL) ^ 0x06caa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0146 | PC: 0x0b2bb8 | FDE: 0x06cb18 | Size: 256 bytes
// Khung tháo gỡ #0146 | Địa chỉ PC: 0x0b2bb8 | Địa chỉ FDE: 0x06cb18 | Kích thước: 256 bytes
//   0x0b2bb8: D107C3FF  sub      sp, sp, #0x1f0
//   0x0b2bbc: A91B63FC  stp      x28, x24, [sp, #0x1b0]
//   0x0b2bc0: A91C5BF7  stp      x23, x22, [sp, #0x1c0]
//   0x0b2bc4: A91D53F5  stp      x21, x20, [sp, #0x1d0]
static inline uint64_t fde_func_0146_0x0b2bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2bb8ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91b63fcULL) ^ 0x06cb18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0147 | PC: 0x0b2d7c | FDE: 0x06cb90 | Size: 256 bytes
// Khung tháo gỡ #0147 | Địa chỉ PC: 0x0b2d7c | Địa chỉ FDE: 0x06cb90 | Kích thước: 256 bytes
//   0x0b2d7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b2d80: AA0003F3  mov      x19, x0
//   0x0b2d84: 9100A000  add      x0, x0, #0x28
//   0x0b2d88: 94027756  bl       #0x150ae0
static inline uint64_t fde_func_0147_0x0b2d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2d7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06cb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0148 | PC: 0x0b2eec | FDE: 0x06cc08 | Size: 56 bytes
// Khung tháo gỡ #0148 | Địa chỉ PC: 0x0b2eec | Địa chỉ FDE: 0x06cc08 | Kích thước: 56 bytes
//   0x0b2eec: D29D1768  mov      x8, #0xe8bb
//   0x0b2ef0: F2B17448  movk     x8, #0x8ba2, lsl #16
//   0x0b2ef4: F2D745C8  movk     x8, #0xba2e, lsl #32
//   0x0b2ef8: F2E05D08  movk     x8, #0x2e8, lsl #48
static inline uint64_t fde_func_0148_0x0b2eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2eecULL ^ (static_cast<uint64_t>(0xd29d1768ULL) << 13);
    acc = (acc + a1 + 0xf2b17448ULL) ^ 0x06cc08ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0149 | PC: 0x0b2f24 | FDE: 0x06cc38 | Size: 252 bytes [_ZN4lynx6canvas12ImageElement9GetBitmapEv]
// Khung tháo gỡ #0149 | Địa chỉ PC: 0x0b2f24 | Địa chỉ FDE: 0x06cc38 | Kích thước: 252 bytes
//   0x0b2f24: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b2f28: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b2f2c: 94034F3E  bl       #0x186c24
//   0x0b2f30: F9404E68  ldr      x8, [x19, #0x98]
static inline uint64_t fde_func_0149_0x0b2f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2f24ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06cc38ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0150 | PC: 0x0b3020 | FDE: 0x06cc78 | Size: 132 bytes
// Khung tháo gỡ #0150 | Địa chỉ PC: 0x0b3020 | Địa chỉ FDE: 0x06cc78 | Kích thước: 132 bytes
//   0x0b3020: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b3024: B00006C8  adrp     x8, #0x18c000
//   0x0b3028: 91358108  add      x8, x8, #0xd60
//   0x0b302c: F9000008  str      x8, [x0]
static inline uint64_t fde_func_0150_0x0b3020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3020ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb00006c8ULL) ^ 0x06cc78ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0151 | PC: 0x0b30a4 | FDE: 0x06ccd8 | Size: 256 bytes
// Khung tháo gỡ #0151 | Địa chỉ PC: 0x0b30a4 | Địa chỉ FDE: 0x06ccd8 | Kích thước: 256 bytes
//   0x0b30a4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b30a8: AA0003F3  mov      x19, x0
//   0x0b30ac: 97FFFFDD  bl       #0xb3020
//   0x0b30b0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0151_0x0b30a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b30a4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06ccd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0152 | PC: 0x0b3340 | FDE: 0x06cd58 | Size: 256 bytes
// Khung tháo gỡ #0152 | Địa chỉ PC: 0x0b3340 | Địa chỉ FDE: 0x06cd58 | Kích thước: 256 bytes
//   0x0b3340: 3940B000  ldrb     w0, [x0, #0x2c]
//   0x0b3344: D65F03C0  ret      
//   0x0b3348: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b334c: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0152_0x0b3340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3340ULL ^ (static_cast<uint64_t>(0x3940b000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06cd58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0153 | PC: 0x0b3680 | FDE: 0x06cde8 | Size: 256 bytes
// Khung tháo gỡ #0153 | Địa chỉ PC: 0x0b3680 | Địa chỉ FDE: 0x06cde8 | Kích thước: 256 bytes
//   0x0b3680: D10103FF  sub      sp, sp, #0x40
//   0x0b3684: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b3688: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0b368c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0153_0x0b3680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3680ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x06cde8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0154 | PC: 0x0b39b0 | FDE: 0x06ce88 | Size: 256 bytes
// Khung tháo gỡ #0154 | Địa chỉ PC: 0x0b39b0 | Địa chỉ FDE: 0x06ce88 | Kích thước: 256 bytes
//   0x0b39b0: D10583FF  sub      sp, sp, #0x160
//   0x0b39b4: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0b39b8: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0b39bc: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0154_0x0b39b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b39b0ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x06ce88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0155 | PC: 0x0b3ac0 | FDE: 0x06cef8 | Size: 256 bytes
// Khung tháo gỡ #0155 | Địa chỉ PC: 0x0b3ac0 | Địa chỉ FDE: 0x06cef8 | Kích thước: 256 bytes
//   0x0b3ac0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b3ac4: AA0003F3  mov      x19, x0
//   0x0b3ac8: 940307E8  bl       #0x175a68
//   0x0b3acc: A9007C1F  stp      xzr, xzr, [x0]
static inline uint64_t fde_func_0155_0x0b3ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3ac0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06cef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0156 | PC: 0x0b3c80 | FDE: 0x06cf78 | Size: 256 bytes
// Khung tháo gỡ #0156 | Địa chỉ PC: 0x0b3c80 | Địa chỉ FDE: 0x06cf78 | Kích thước: 256 bytes
//   0x0b3c80: D10603FF  sub      sp, sp, #0x180
//   0x0b3c84: A9155BFC  stp      x28, x22, [sp, #0x150]
//   0x0b3c88: A91653F5  stp      x21, x20, [sp, #0x160]
//   0x0b3c8c: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_0156_0x0b3c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3c80ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9155bfcULL) ^ 0x06cf78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0157 | PC: 0x0b3e5c | FDE: 0x06d000 | Size: 256 bytes
// Khung tháo gỡ #0157 | Địa chỉ PC: 0x0b3e5c | Địa chỉ FDE: 0x06d000 | Kích thước: 256 bytes
//   0x0b3e5c: D10243FF  sub      sp, sp, #0x90
//   0x0b3e60: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x0b3e64: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x0b3e68: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0157_0x0b3e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3e5cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x06d000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0158 | PC: 0x0b40f8 | FDE: 0x06d098 | Size: 256 bytes
// Khung tháo gỡ #0158 | Địa chỉ PC: 0x0b40f8 | Địa chỉ FDE: 0x06d098 | Kích thước: 256 bytes
//   0x0b40f8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b40fc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b4100: 94034BEA  bl       #0x1870a8
//   0x0b4104: 900006C8  adrp     x8, #0x18c000
static inline uint64_t fde_func_0158_0x0b40f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b40f8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06d098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0159 | PC: 0x0b4410 | FDE: 0x06d138 | Size: 236 bytes
// Khung tháo gỡ #0159 | Địa chỉ PC: 0x0b4410 | Địa chỉ FDE: 0x06d138 | Kích thước: 236 bytes
//   0x0b4410: D101C3FF  sub      sp, sp, #0x70
//   0x0b4414: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x0b4418: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0b441c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0159_0x0b4410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4410ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x06d138ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0160 | PC: 0x0b44fc | FDE: 0x06d188 | Size: 224 bytes [_ZN4lynx6canvas22AudioConsumerContainer25OnAudioSourceStartedUsingEPv]
// Khung tháo gỡ #0160 | Địa chỉ PC: 0x0b44fc | Địa chỉ FDE: 0x06d188 | Kích thước: 224 bytes
//   0x0b44fc: B4000341  cbz      x1, #0xb4564
//   0x0b4500: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0b4504: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b4508: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0160_0x0b44fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b44fcULL ^ (static_cast<uint64_t>(0xb4000341ULL) << 13);
    acc = (acc + a1 + 0xa9bd5bf7ULL) ^ 0x06d188ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0161 | PC: 0x0b45dc | FDE: 0x06d1a8 | Size: 148 bytes [_ZN4lynx6canvas22AudioConsumerContainer25OnAudioSourceStoppedUsingEPv]
// Khung tháo gỡ #0161 | Địa chỉ PC: 0x0b45dc | Địa chỉ FDE: 0x06d1a8 | Kích thước: 148 bytes
//   0x0b45dc: B4000481  cbz      x1, #0xb466c
//   0x0b45e0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0b45e4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b45e8: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0161_0x0b45dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b45dcULL ^ (static_cast<uint64_t>(0xb4000481ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff6ULL) ^ 0x06d1a8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0162 | PC: 0x0b4670 | FDE: 0x06d1c8 | Size: 108 bytes [_ZN4lynx6canvas22AudioConsumerContainer8OnSampleEPKsii]
// Khung tháo gỡ #0162 | Địa chỉ PC: 0x0b4670 | Địa chỉ FDE: 0x06d1c8 | Kích thước: 108 bytes
//   0x0b4670: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0b4674: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0b4678: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b467c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0162_0x0b4670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4670ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06d1c8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0163 | PC: 0x0b46dc | FDE: 0x06d1f0 | Size: 228 bytes [_ZN4lynx6canvas22AudioConsumerContainer3GetEN4Napi3EnvE]
// Khung tháo gỡ #0163 | Địa chỉ PC: 0x0b46dc | Địa chỉ FDE: 0x06d1f0 | Kích thước: 228 bytes
//   0x0b46dc: D100C3FF  sub      sp, sp, #0x30
//   0x0b46e0: F9000BF4  str      x20, [sp, #0x10]
//   0x0b46e4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b46e8: 940306AC  bl       #0x176198
static inline uint64_t fde_func_0163_0x0b46dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b46dcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x06d1f0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0164 | PC: 0x0b47c0 | FDE: 0x06d228 | Size: 100 bytes
// Khung tháo gỡ #0164 | Địa chỉ PC: 0x0b47c0 | Địa chỉ FDE: 0x06d228 | Kích thước: 100 bytes
//   0x0b47c0: B4000101  cbz      x1, #0xb47e0
//   0x0b47c4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b47c8: F9400420  ldr      x0, [x1, #8]
//   0x0b47cc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0164_0x0b47c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b47c0ULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x06d228ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0165 | PC: 0x0b4824 | FDE: 0x06d288 | Size: 44 bytes
// Khung tháo gỡ #0165 | Địa chỉ PC: 0x0b4824 | Địa chỉ FDE: 0x06d288 | Kích thước: 44 bytes
//   0x0b4824: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b4828: AA0003F3  mov      x19, x0
//   0x0b482c: 91016000  add      x0, x0, #0x58
//   0x0b4830: 94034B98  bl       #0x187690
static inline uint64_t fde_func_0165_0x0b4824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4824ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06d288ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0166 | PC: 0x0b4850 | FDE: 0x06d2a0 | Size: 112 bytes [_ZN4lynx6canvas22AudioConsumerContainer3GetENS_7binding3EnvE]
// Khung tháo gỡ #0166 | Địa chỉ PC: 0x0b4850 | Địa chỉ FDE: 0x06d2a0 | Kích thước: 112 bytes
//   0x0b4850: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b4854: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b4858: F9400008  ldr      x8, [x0]
//   0x0b485c: 900006C1  adrp     x1, #0x18c000
static inline uint64_t fde_func_0166_0x0b4850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4850ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06d2a0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0167 | PC: 0x0b48c0 | FDE: 0x06d2d8 | Size: 256 bytes [_ZN4lynx6canvas2au14GetAudioEngineEN4Napi3EnvEj]
// Khung tháo gỡ #0167 | Địa chỉ PC: 0x0b48c0 | Địa chỉ FDE: 0x06d2d8 | Kích thước: 256 bytes
//   0x0b48c0: D10183FF  sub      sp, sp, #0x60
//   0x0b48c4: F9001BF6  str      x22, [sp, #0x30]
//   0x0b48c8: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0b48cc: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0167_0x0b48c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b48c0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x06d2d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0168 | PC: 0x0b49ec | FDE: 0x06d2f8 | Size: 132 bytes
// Khung tháo gỡ #0168 | Địa chỉ PC: 0x0b49ec | Địa chỉ FDE: 0x06d2f8 | Kích thước: 132 bytes
//   0x0b49ec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0b49f0: 94033F1B  bl       #0x18465c
//   0x0b49f4: 39400008  ldrb     w8, [x0]
//   0x0b49f8: 34000068  cbz      w8, #0xb4a04
static inline uint64_t fde_func_0168_0x0b49ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b49ecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94033f1bULL) ^ 0x06d2f8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0169 | PC: 0x0b4a70 | FDE: 0x06d330 | Size: 256 bytes [_ZN4lynx6canvas2au15SaveAudioEngineEN4Napi3EnvENSt6__ndk110shared_ptrINS1_15AudioEngineBaseEEE]
// Khung tháo gỡ #0169 | Địa chỉ PC: 0x0b4a70 | Địa chỉ FDE: 0x06d330 | Kích thước: 256 bytes
//   0x0b4a70: D10103FF  sub      sp, sp, #0x40
//   0x0b4a74: F90013F4  str      x20, [sp, #0x20]
//   0x0b4a78: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0b4a7c: 94034781  bl       #0x186880
static inline uint64_t fde_func_0169_0x0b4a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4a70ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x06d330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0170 | PC: 0x0b4b80 | FDE: 0x06d368 | Size: 256 bytes [_ZN4lynx6canvas2au20AudioExecuteCallbackENSt6__ndk18weak_ptrINS0_9CanvasAppEEEPvPFvS6_E]
// Khung tháo gỡ #0170 | Địa chỉ PC: 0x0b4b80 | Địa chỉ FDE: 0x06d368 | Kích thước: 256 bytes
//   0x0b4b80: AA1E03E3  mov      x3, x30
//   0x0b4b84: 940323FE  bl       #0x17db7c
//   0x0b4b88: AA0303FE  mov      x30, x3
//   0x0b4b8c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0170_0x0b4b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4b80ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940323feULL) ^ 0x06d368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0171 | PC: 0x0b4cfc | FDE: 0x06d3e0 | Size: 256 bytes
// Khung tháo gỡ #0171 | Địa chỉ PC: 0x0b4cfc | Địa chỉ FDE: 0x06d3e0 | Kích thước: 256 bytes
//   0x0b4cfc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b4d00: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b4d04: 940348BA  bl       #0x186fec
//   0x0b4d08: F9401688  ldr      x8, [x20, #0x28]
static inline uint64_t fde_func_0171_0x0b4cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4cfcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06d3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0172 | PC: 0x0b50e4 | FDE: 0x06d468 | Size: 60 bytes
// Khung tháo gỡ #0172 | Địa chỉ PC: 0x0b50e4 | Địa chỉ FDE: 0x06d468 | Kích thước: 60 bytes
//   0x0b50e4: 528000E8  mov      w8, #7
//   0x0b50e8: B900A808  str      w8, [x0, #0xa8]
//   0x0b50ec: D65F03C0  ret      
//   0x0b50f0: AA1E03E3  mov      x3, x30
static inline uint64_t fde_func_0172_0x0b50e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b50e4ULL ^ (static_cast<uint64_t>(0x528000e8ULL) << 13);
    acc = (acc + a1 + 0xb900a808ULL) ^ 0x06d468ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0173 | PC: 0x0b5120 | FDE: 0x06d4c8 | Size: 96 bytes
// Khung tháo gỡ #0173 | Địa chỉ PC: 0x0b5120 | Địa chỉ FDE: 0x06d4c8 | Kích thước: 96 bytes
//   0x0b5120: AA0003E8  mov      x8, x0
//   0x0b5124: F9400000  ldr      x0, [x0]
//   0x0b5128: F9000101  str      x1, [x8]
//   0x0b512c: B4000040  cbz      x0, #0xb5134
static inline uint64_t fde_func_0173_0x0b5120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5120ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x06d4c8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0174 | PC: 0x0b5180 | FDE: 0x06d528 | Size: 256 bytes
// Khung tháo gỡ #0174 | Địa chỉ PC: 0x0b5180 | Địa chỉ FDE: 0x06d528 | Kích thước: 256 bytes
//   0x0b5180: D10443FF  sub      sp, sp, #0x110
//   0x0b5184: A90E5BFC  stp      x28, x22, [sp, #0xe0]
//   0x0b5188: A90F53F5  stp      x21, x20, [sp, #0xf0]
//   0x0b518c: A9107BF3  stp      x19, x30, [sp, #0x100]
static inline uint64_t fde_func_0174_0x0b5180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5180ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90e5bfcULL) ^ 0x06d528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0175 | PC: 0x0b52f4 | FDE: 0x06d598 | Size: 192 bytes
// Khung tháo gỡ #0175 | Địa chỉ PC: 0x0b52f4 | Địa chỉ FDE: 0x06d598 | Kích thước: 192 bytes
//   0x0b52f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b52f8: B4000140  cbz      x0, #0xb5320
//   0x0b52fc: AA0003F3  mov      x19, x0
//   0x0b5300: 94030496  bl       #0x176558
static inline uint64_t fde_func_0175_0x0b52f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b52f4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000140ULL) ^ 0x06d598ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0176 | PC: 0x0b53b4 | FDE: 0x06d600 | Size: 256 bytes
// Khung tháo gỡ #0176 | Địa chỉ PC: 0x0b53b4 | Địa chỉ FDE: 0x06d600 | Kích thước: 256 bytes
//   0x0b53b4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0b53b8: 940301AC  bl       #0x175a68
//   0x0b53bc: 900006C8  adrp     x8, #0x18d000
//   0x0b53c0: 91002108  add      x8, x8, #8
static inline uint64_t fde_func_0176_0x0b53b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b53b4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940301acULL) ^ 0x06d600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0177 | PC: 0x0b54c0 | FDE: 0x06d668 | Size: 256 bytes
// Khung tháo gỡ #0177 | Địa chỉ PC: 0x0b54c0 | Địa chỉ FDE: 0x06d668 | Kích thước: 256 bytes
//   0x0b54c0: D10543FF  sub      sp, sp, #0x150
//   0x0b54c4: A9125BFC  stp      x28, x22, [sp, #0x120]
//   0x0b54c8: A91353F5  stp      x21, x20, [sp, #0x130]
//   0x0b54cc: A9147BF3  stp      x19, x30, [sp, #0x140]
static inline uint64_t fde_func_0177_0x0b54c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b54c0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9125bfcULL) ^ 0x06d668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0178 | PC: 0x0b5780 | FDE: 0x06d6f0 | Size: 256 bytes
// Khung tháo gỡ #0178 | Địa chỉ PC: 0x0b5780 | Địa chỉ FDE: 0x06d6f0 | Kích thước: 256 bytes
//   0x0b5780: D10183FF  sub      sp, sp, #0x60
//   0x0b5784: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0b5788: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0b578c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0178_0x0b5780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5780ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x06d6f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0179 | PC: 0x0b589c | FDE: 0x06d768 | Size: 156 bytes
// Khung tháo gỡ #0179 | Địa chỉ PC: 0x0b589c | Địa chỉ FDE: 0x06d768 | Kích thước: 156 bytes
//   0x0b589c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b58a0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b58a4: 940320A3  bl       #0x17db30
//   0x0b58a8: 94032D0E  bl       #0x180ce0
static inline uint64_t fde_func_0179_0x0b589c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b589cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06d768ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0180 | PC: 0x0b5938 | FDE: 0x06d7d0 | Size: 256 bytes
// Khung tháo gỡ #0180 | Địa chỉ PC: 0x0b5938 | Địa chỉ FDE: 0x06d7d0 | Kích thước: 256 bytes
//   0x0b5938: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b593c: B940A828  ldr      w8, [x1, #0xa8]
//   0x0b5940: 7100051F  cmp      w8, #1
//   0x0b5944: 54000121  b.ne     #0xb5968
static inline uint64_t fde_func_0180_0x0b5938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5938ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb940a828ULL) ^ 0x06d7d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0181 | PC: 0x0b5af4 | FDE: 0x06d838 | Size: 256 bytes
// Khung tháo gỡ #0181 | Địa chỉ PC: 0x0b5af4 | Địa chỉ FDE: 0x06d838 | Kích thước: 256 bytes
//   0x0b5af4: D10583FF  sub      sp, sp, #0x160
//   0x0b5af8: F9009BFC  str      x28, [sp, #0x130]
//   0x0b5afc: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0b5b00: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0181_0x0b5af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5af4ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x06d838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0182 | PC: 0x0b5c7c | FDE: 0x06d8a8 | Size: 256 bytes
// Khung tháo gỡ #0182 | Địa chỉ PC: 0x0b5c7c | Địa chỉ FDE: 0x06d8a8 | Kích thước: 256 bytes
//   0x0b5c7c: 39400009  ldrb     w9, [x0]
//   0x0b5c80: 37000089  tbnz     w9, #0, #0xb5c90
//   0x0b5c84: 91000408  add      x8, x0, #1
//   0x0b5c88: D341FD29  lsr      x9, x9, #1
static inline uint64_t fde_func_0182_0x0b5c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5c7cULL ^ (static_cast<uint64_t>(0x39400009ULL) << 13);
    acc = (acc + a1 + 0x37000089ULL) ^ 0x06d8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0183 | PC: 0x0b600c | FDE: 0x06d920 | Size: 256 bytes
// Khung tháo gỡ #0183 | Địa chỉ PC: 0x0b600c | Địa chỉ FDE: 0x06d920 | Kích thước: 256 bytes
//   0x0b600c: D10543FF  sub      sp, sp, #0x150
//   0x0b6010: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0b6014: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0b6018: 940305A6  bl       #0x1776b0
static inline uint64_t fde_func_0183_0x0b600c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b600cULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x06d920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0184 | PC: 0x0b6468 | FDE: 0x06d9b0 | Size: 236 bytes
// Khung tháo gỡ #0184 | Địa chỉ PC: 0x0b6468 | Địa chỉ FDE: 0x06d9b0 | Kích thước: 236 bytes
//   0x0b6468: D10303FF  sub      sp, sp, #0xc0
//   0x0b646c: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x0b6470: A90B7BF3  stp      x19, x30, [sp, #0xb0]
//   0x0b6474: 9403012B  bl       #0x176920
static inline uint64_t fde_func_0184_0x0b6468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6468ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90a53f5ULL) ^ 0x06d9b0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0185 | PC: 0x0b6554 | FDE: 0x06da18 | Size: 84 bytes
// Khung tháo gỡ #0185 | Địa chỉ PC: 0x0b6554 | Địa chỉ FDE: 0x06da18 | Kích thước: 84 bytes
//   0x0b6554: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b6558: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b655c: AA0003F3  mov      x19, x0
//   0x0b6560: 97FFFFF3  bl       #0xb652c
static inline uint64_t fde_func_0185_0x0b6554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6554ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06da18ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0186 | PC: 0x0b65a8 | FDE: 0x06da80 | Size: 256 bytes
// Khung tháo gỡ #0186 | Địa chỉ PC: 0x0b65a8 | Địa chỉ FDE: 0x06da80 | Kích thước: 256 bytes
//   0x0b65a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b65ac: AA0103F3  mov      x19, x1
//   0x0b65b0: 528000C8  mov      w8, #6
//   0x0b65b4: B900A828  str      w8, [x1, #0xa8]
static inline uint64_t fde_func_0186_0x0b65a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b65a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x06da80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0187 | PC: 0x0b66f8 | FDE: 0x06dae8 | Size: 148 bytes
// Khung tháo gỡ #0187 | Địa chỉ PC: 0x0b66f8 | Địa chỉ FDE: 0x06dae8 | Kích thước: 148 bytes
//   0x0b66f8: AA0103E0  mov      x0, x1
//   0x0b66fc: 52800021  mov      w1, #1
//   0x0b6700: 17FFFBD0  b        #0xb5640
//   0x0b6704: F81E0FF4  str      x20, [sp, #-0x20]!
static inline uint64_t fde_func_0187_0x0b66f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b66f8ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x52800021ULL) ^ 0x06dae8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0188 | PC: 0x0b678c | FDE: 0x06db58 | Size: 104 bytes
// Khung tháo gỡ #0188 | Địa chỉ PC: 0x0b678c | Địa chỉ FDE: 0x06db58 | Kích thước: 104 bytes
//   0x0b678c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b6790: AA0003F3  mov      x19, x0
//   0x0b6794: 91006000  add      x0, x0, #0x18
//   0x0b6798: 940304EC  bl       #0x177b48
static inline uint64_t fde_func_0188_0x0b678c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b678cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06db58ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0189 | PC: 0x0b67f4 | FDE: 0x06dbc0 | Size: 112 bytes
// Khung tháo gỡ #0189 | Địa chỉ PC: 0x0b67f4 | Địa chỉ FDE: 0x06dbc0 | Kích thước: 112 bytes
//   0x0b67f4: F00006A9  adrp     x9, #0x18d000
//   0x0b67f8: AA0103E8  mov      x8, x1
//   0x0b67fc: 91082129  add      x9, x9, #0x208
//   0x0b6800: 14032CE3  b        #0x181b8c
static inline uint64_t fde_func_0189_0x0b67f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b67f4ULL ^ (static_cast<uint64_t>(0xf00006a9ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x06dbc0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0190 | PC: 0x0b6864 | FDE: 0x06dc28 | Size: 256 bytes
// Khung tháo gỡ #0190 | Địa chỉ PC: 0x0b6864 | Địa chỉ FDE: 0x06dc28 | Kích thước: 256 bytes
//   0x0b6864: D104C3FF  sub      sp, sp, #0x130
//   0x0b6868: F9007BFC  str      x28, [sp, #0xf0]
//   0x0b686c: A9105BF7  stp      x23, x22, [sp, #0x100]
//   0x0b6870: A91153F5  stp      x21, x20, [sp, #0x110]
static inline uint64_t fde_func_0190_0x0b6864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6864ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x06dc28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0191 | PC: 0x0b6a08 | FDE: 0x06dca0 | Size: 136 bytes
// Khung tháo gỡ #0191 | Địa chỉ PC: 0x0b6a08 | Địa chỉ FDE: 0x06dca0 | Kích thước: 136 bytes
//   0x0b6a08: F00006A9  adrp     x9, #0x18d000
//   0x0b6a0c: AA0103E8  mov      x8, x1
//   0x0b6a10: 91094129  add      x9, x9, #0x250
//   0x0b6a14: 14031178  b        #0x17aff4
static inline uint64_t fde_func_0191_0x0b6a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6a08ULL ^ (static_cast<uint64_t>(0xf00006a9ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x06dca0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0192 | PC: 0x0b6a90 | FDE: 0x06dd08 | Size: 100 bytes
// Khung tháo gỡ #0192 | Địa chỉ PC: 0x0b6a90 | Địa chỉ FDE: 0x06dd08 | Kích thước: 100 bytes
//   0x0b6a90: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b6a94: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b6a98: AA0003F3  mov      x19, x0
//   0x0b6a9c: 97FFFF26  bl       #0xb6734
static inline uint64_t fde_func_0192_0x0b6a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6a90ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06dd08ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0193 | PC: 0x0b6af4 | FDE: 0x06dd70 | Size: 128 bytes
// Khung tháo gỡ #0193 | Địa chỉ PC: 0x0b6af4 | Địa chỉ FDE: 0x06dd70 | Kích thước: 128 bytes
//   0x0b6af4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b6af8: AA0003F3  mov      x19, x0
//   0x0b6afc: 97FFFFFB  bl       #0xb6ae8
//   0x0b6b00: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0193_0x0b6af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6af4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06dd70ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0194 | PC: 0x0b6b74 | FDE: 0x06dde0 | Size: 256 bytes
// Khung tháo gỡ #0194 | Địa chỉ PC: 0x0b6b74 | Địa chỉ FDE: 0x06dde0 | Kích thước: 256 bytes
//   0x0b6b74: AA1E03E2  mov      x2, x30
//   0x0b6b78: 9402FF61  bl       #0x1768fc
//   0x0b6b7c: AA0203FE  mov      x30, x2
//   0x0b6b80: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0194_0x0b6b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6b74ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402ff61ULL) ^ 0x06dde0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0195 | PC: 0x0b70ac | FDE: 0x06de68 | Size: 256 bytes
// Khung tháo gỡ #0195 | Địa chỉ PC: 0x0b70ac | Địa chỉ FDE: 0x06de68 | Kích thước: 256 bytes
//   0x0b70ac: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0b70b0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b70b4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b70b8: AA0303F6  mov      x22, x3
static inline uint64_t fde_func_0195_0x0b70ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b70acULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06de68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0196 | PC: 0x0b72fc | FDE: 0x06dee0 | Size: 256 bytes
// Khung tháo gỡ #0196 | Địa chỉ PC: 0x0b72fc | Địa chỉ FDE: 0x06dee0 | Kích thước: 256 bytes
//   0x0b72fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b7300: AA0003F3  mov      x19, x0
//   0x0b7304: 97FFFFF6  bl       #0xb72dc
//   0x0b7308: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0196_0x0b72fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b72fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06dee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0197 | PC: 0x0b74e4 | FDE: 0x06df50 | Size: 256 bytes
// Khung tháo gỡ #0197 | Địa chỉ PC: 0x0b74e4 | Địa chỉ FDE: 0x06df50 | Kích thước: 256 bytes
//   0x0b74e4: AA1E03E2  mov      x2, x30
//   0x0b74e8: 940301E7  bl       #0x177c84
//   0x0b74ec: AA0203FE  mov      x30, x2
//   0x0b74f0: 17FFFF89  b        #0xb7314
static inline uint64_t fde_func_0197_0x0b74e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b74e4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940301e7ULL) ^ 0x06df50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0198 | PC: 0x0b76a0 | FDE: 0x06dfc0 | Size: 104 bytes
// Khung tháo gỡ #0198 | Địa chỉ PC: 0x0b76a0 | Địa chỉ FDE: 0x06dfc0 | Kích thước: 104 bytes
//   0x0b76a0: 91006000  add      x0, x0, #0x18
//   0x0b76a4: 1403410F  b        #0x187ae0
//   0x0b76a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b76ac: D00006A8  adrp     x8, #0x18d000
static inline uint64_t fde_func_0198_0x0b76a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b76a0ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x1403410fULL) ^ 0x06dfc0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0199 | PC: 0x0b7708 | FDE: 0x06e020 | Size: 256 bytes
// Khung tháo gỡ #0199 | Địa chỉ PC: 0x0b7708 | Địa chỉ FDE: 0x06e020 | Kích thước: 256 bytes
//   0x0b7708: AA1E03E1  mov      x1, x30
//   0x0b770c: 94031CE9  bl       #0x17eab0
//   0x0b7710: AA0103FE  mov      x30, x1
//   0x0b7714: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0199_0x0b7708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7708ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94031ce9ULL) ^ 0x06e020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0200 | PC: 0x0b7f38 | FDE: 0x06e0c0 | Size: 256 bytes
// Khung tháo gỡ #0200 | Địa chỉ PC: 0x0b7f38 | Địa chỉ FDE: 0x06e0c0 | Kích thước: 256 bytes
//   0x0b7f38: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0b7f3c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b7f40: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b7f44: F940AC08  ldr      x8, [x0, #0x158]
static inline uint64_t fde_func_0200_0x0b7f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7f38ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06e0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0201 | PC: 0x0b8268 | FDE: 0x06e140 | Size: 256 bytes
// Khung tháo gỡ #0201 | Địa chỉ PC: 0x0b8268 | Địa chỉ FDE: 0x06e140 | Kích thước: 256 bytes
//   0x0b8268: D10583FF  sub      sp, sp, #0x160
//   0x0b826c: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0b8270: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0b8274: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0201_0x0b8268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8268ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x06e140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0202 | PC: 0x0b84bc | FDE: 0x06e1d0 | Size: 256 bytes
// Khung tháo gỡ #0202 | Địa chỉ PC: 0x0b84bc | Địa chỉ FDE: 0x06e1d0 | Kích thước: 256 bytes
//   0x0b84bc: D10103FF  sub      sp, sp, #0x40
//   0x0b84c0: F9000BF6  str      x22, [sp, #0x10]
//   0x0b84c4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0b84c8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0202_0x0b84bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b84bcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x06e1d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0203 | PC: 0x0b85d8 | FDE: 0x06e238 | Size: 256 bytes
// Khung tháo gỡ #0203 | Địa chỉ PC: 0x0b85d8 | Địa chỉ FDE: 0x06e238 | Kích thước: 256 bytes
//   0x0b85d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b85dc: AA0003F3  mov      x19, x0
//   0x0b85e0: 97FFFFF2  bl       #0xb85a8
//   0x0b85e4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0203_0x0b85d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b85d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06e238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0204 | PC: 0x0b8780 | FDE: 0x06e2b0 | Size: 84 bytes
// Khung tháo gỡ #0204 | Địa chỉ PC: 0x0b8780 | Địa chỉ FDE: 0x06e2b0 | Kích thước: 84 bytes
//   0x0b8780: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b8784: AA0003F3  mov      x19, x0
//   0x0b8788: 97FFFFF4  bl       #0xb8758
//   0x0b878c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0204_0x0b8780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8780ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06e2b0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0205 | PC: 0x0b87d4 | FDE: 0x06e310 | Size: 64 bytes
// Khung tháo gỡ #0205 | Địa chỉ PC: 0x0b87d4 | Địa chỉ FDE: 0x06e310 | Kích thước: 64 bytes
//   0x0b87d4: F9400C00  ldr      x0, [x0, #0x18]
//   0x0b87d8: D65F03C0  ret      
//   0x0b87dc: F9401400  ldr      x0, [x0, #0x28]
//   0x0b87e0: D65F03C0  ret      
static inline uint64_t fde_func_0205_0x0b87d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b87d4ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06e310ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0206 | PC: 0x0b8814 | FDE: 0x06e370 | Size: 256 bytes
// Khung tháo gỡ #0206 | Địa chỉ PC: 0x0b8814 | Địa chỉ FDE: 0x06e370 | Kích thước: 256 bytes
//   0x0b8814: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b8818: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b881c: AA0003F4  mov      x20, x0
//   0x0b8820: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0206_0x0b8814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8814ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06e370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0207 | PC: 0x0b8984 | FDE: 0x06e3f0 | Size: 256 bytes
// Khung tháo gỡ #0207 | Địa chỉ PC: 0x0b8984 | Địa chỉ FDE: 0x06e3f0 | Kích thước: 256 bytes
//   0x0b8984: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b8988: AA0003F3  mov      x19, x0
//   0x0b898c: 97FFFFF0  bl       #0xb894c
//   0x0b8990: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0207_0x0b8984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8984ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06e3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0208 | PC: 0x0b8b44 | FDE: 0x06e468 | Size: 256 bytes
// Khung tháo gỡ #0208 | Địa chỉ PC: 0x0b8b44 | Địa chỉ FDE: 0x06e468 | Kích thước: 256 bytes
//   0x0b8b44: D10403FF  sub      sp, sp, #0x100
//   0x0b8b48: FD0063E8  str      d8, [sp, #0xc0]
//   0x0b8b4c: A90D5BF7  stp      x23, x22, [sp, #0xd0]
//   0x0b8b50: A90E53F5  stp      x21, x20, [sp, #0xe0]
static inline uint64_t fde_func_0208_0x0b8b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8b44ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xfd0063e8ULL) ^ 0x06e468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0209 | PC: 0x0b8e20 | FDE: 0x06e500 | Size: 256 bytes
// Khung tháo gỡ #0209 | Địa chỉ PC: 0x0b8e20 | Địa chỉ FDE: 0x06e500 | Kích thước: 256 bytes
//   0x0b8e20: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0b8e24: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b8e28: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b8e2c: AA0303F3  mov      x19, x3
static inline uint64_t fde_func_0209_0x0b8e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8e20ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06e500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0210 | PC: 0x0b8f8c | FDE: 0x06e568 | Size: 136 bytes [_ZN4lynx6canvas17PermissionManager23RequestUserMediaGrantedERKNSt6__ndk110shared_ptrINS0_9CanvasAppEEEbb]
// Khung tháo gỡ #0210 | Địa chỉ PC: 0x0b8f8c | Địa chỉ FDE: 0x06e568 | Kích thước: 136 bytes
//   0x0b8f8c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0b8f90: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0b8f94: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0b8f98: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0210_0x0b8f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8f8cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06e568ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0211 | PC: 0x0b9014 | FDE: 0x06e588 | Size: 256 bytes
// Khung tháo gỡ #0211 | Địa chỉ PC: 0x0b9014 | Địa chỉ FDE: 0x06e588 | Kích thước: 256 bytes
//   0x0b9014: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b9018: 900006A8  adrp     x8, #0x18d000
//   0x0b901c: 911B0108  add      x8, x8, #0x6c0
//   0x0b9020: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0211_0x0b9014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9014ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900006a8ULL) ^ 0x06e588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0212 | PC: 0x0b920c | FDE: 0x06e608 | Size: 256 bytes
// Khung tháo gỡ #0212 | Địa chỉ PC: 0x0b920c | Địa chỉ FDE: 0x06e608 | Kích thước: 256 bytes
//   0x0b920c: AA1E03E3  mov      x3, x30
//   0x0b9210: 9402F5BB  bl       #0x1768fc
//   0x0b9214: AA0303FE  mov      x30, x3
//   0x0b9218: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0212_0x0b920c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b920cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9402f5bbULL) ^ 0x06e608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0213 | PC: 0x0b9cc0 | FDE: 0x06e6b8 | Size: 124 bytes
// Khung tháo gỡ #0213 | Địa chỉ PC: 0x0b9cc0 | Địa chỉ FDE: 0x06e6b8 | Kích thước: 124 bytes
//   0x0b9cc0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0b9cc4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b9cc8: 940325B6  bl       #0x1833a0
//   0x0b9ccc: 54000040  b.eq     #0xb9cd4
static inline uint64_t fde_func_0213_0x0b9cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9cc0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06e6b8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0214 | PC: 0x0b9d3c | FDE: 0x06e720 | Size: 256 bytes
// Khung tháo gỡ #0214 | Địa chỉ PC: 0x0b9d3c | Địa chỉ FDE: 0x06e720 | Kích thước: 256 bytes
//   0x0b9d3c: 9100A000  add      x0, x0, #0x28
//   0x0b9d40: AA0203E1  mov      x1, x2
//   0x0b9d44: 14000001  b        #0xb9d48
//   0x0b9d48: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0214_0x0b9d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9d3cULL ^ (static_cast<uint64_t>(0x9100a000ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x06e720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0215 | PC: 0x0b9f38 | FDE: 0x06e798 | Size: 156 bytes
// Khung tháo gỡ #0215 | Địa chỉ PC: 0x0b9f38 | Địa chỉ FDE: 0x06e798 | Kích thước: 156 bytes
//   0x0b9f38: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0b9f3c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0b9f40: 9402FAAC  bl       #0x1789f0
//   0x0b9f44: 5400006B  b.lt     #0xb9f50
static inline uint64_t fde_func_0215_0x0b9f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9f38ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06e798ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0216 | PC: 0x0b9fd4 | FDE: 0x06e808 | Size: 256 bytes
// Khung tháo gỡ #0216 | Địa chỉ PC: 0x0b9fd4 | Địa chỉ FDE: 0x06e808 | Kích thước: 256 bytes
//   0x0b9fd4: D37EFC08  lsr      x8, x0, #0x3e
//   0x0b9fd8: B5000048  cbnz     x8, #0xb9fe0
//   0x0b9fdc: 14032869  b        #0x184180
//   0x0b9fe0: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_0216_0x0b9fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9fd4ULL ^ (static_cast<uint64_t>(0xd37efc08ULL) << 13);
    acc = (acc + a1 + 0xb5000048ULL) ^ 0x06e808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0217 | PC: 0x0ba0e8 | FDE: 0x06e878 | Size: 256 bytes
// Khung tháo gỡ #0217 | Địa chỉ PC: 0x0ba0e8 | Địa chỉ FDE: 0x06e878 | Kích thước: 256 bytes
//   0x0ba0e8: D10583FF  sub      sp, sp, #0x160
//   0x0ba0ec: F9009BFC  str      x28, [sp, #0x130]
//   0x0ba0f0: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ba0f4: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0217_0x0ba0e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba0e8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x06e878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0218 | PC: 0x0ba21c | FDE: 0x06e8e8 | Size: 256 bytes
// Khung tháo gỡ #0218 | Địa chỉ PC: 0x0ba21c | Địa chỉ FDE: 0x06e8e8 | Kích thước: 256 bytes
//   0x0ba21c: D10383FF  sub      sp, sp, #0xe0
//   0x0ba220: F9005BF6  str      x22, [sp, #0xb0]
//   0x0ba224: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x0ba228: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_0218_0x0ba21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba21cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf6ULL) ^ 0x06e8e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0219 | PC: 0x0ba33c | FDE: 0x06e960 | Size: 236 bytes
// Khung tháo gỡ #0219 | Địa chỉ PC: 0x0ba33c | Địa chỉ FDE: 0x06e960 | Kích thước: 236 bytes
//   0x0ba33c: D10383FF  sub      sp, sp, #0xe0
//   0x0ba340: F9005BF6  str      x22, [sp, #0xb0]
//   0x0ba344: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x0ba348: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_0219_0x0ba33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba33cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf6ULL) ^ 0x06e960ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0220 | PC: 0x0ba428 | FDE: 0x06e9d0 | Size: 256 bytes
// Khung tháo gỡ #0220 | Địa chỉ PC: 0x0ba428 | Địa chỉ FDE: 0x06e9d0 | Kích thước: 256 bytes
//   0x0ba428: F9401809  ldr      x9, [x0, #0x30]
//   0x0ba42c: 5296D58A  mov      w10, #0xb6ac
//   0x0ba430: 52802D8B  mov      w11, #0x16c
//   0x0ba434: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0220_0x0ba428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba428ULL ^ (static_cast<uint64_t>(0xf9401809ULL) << 13);
    acc = (acc + a1 + 0x5296d58aULL) ^ 0x06e9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0221 | PC: 0x0ba560 | FDE: 0x06ea40 | Size: 256 bytes
// Khung tháo gỡ #0221 | Địa chỉ PC: 0x0ba560 | Địa chỉ FDE: 0x06ea40 | Kích thước: 256 bytes
//   0x0ba560: AA1E03E1  mov      x1, x30
//   0x0ba564: 94030007  bl       #0x17a580
//   0x0ba568: AA0103FE  mov      x30, x1
//   0x0ba56c: BD401900  ldr      s0, [x8, #0x18]
static inline uint64_t fde_func_0221_0x0ba560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba560ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94030007ULL) ^ 0x06ea40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0222 | PC: 0x0ba790 | FDE: 0x06eab0 | Size: 108 bytes
// Khung tháo gỡ #0222 | Địa chỉ PC: 0x0ba790 | Địa chỉ FDE: 0x06eab0 | Kích thước: 108 bytes
//   0x0ba790: AA1E03E1  mov      x1, x30
//   0x0ba794: 9402FF7B  bl       #0x17a580
//   0x0ba798: AA0103FE  mov      x30, x1
//   0x0ba79c: BD40A500  ldr      s0, [x8, #0xa4]
static inline uint64_t fde_func_0222_0x0ba790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba790ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9402ff7bULL) ^ 0x06eab0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0223 | PC: 0x0ba7fc | FDE: 0x06eb10 | Size: 140 bytes
// Khung tháo gỡ #0223 | Địa chỉ PC: 0x0ba7fc | Địa chỉ FDE: 0x06eb10 | Kích thước: 140 bytes
//   0x0ba7fc: AA1E03E1  mov      x1, x30
//   0x0ba800: 9402FF60  bl       #0x17a580
//   0x0ba804: AA0103FE  mov      x30, x1
//   0x0ba808: BD409900  ldr      s0, [x8, #0x98]
static inline uint64_t fde_func_0223_0x0ba7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba7fcULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9402ff60ULL) ^ 0x06eb10ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0224 | PC: 0x0ba888 | FDE: 0x06eb70 | Size: 256 bytes
// Khung tháo gỡ #0224 | Địa chỉ PC: 0x0ba888 | Địa chỉ FDE: 0x06eb70 | Kích thước: 256 bytes
//   0x0ba888: D10583FF  sub      sp, sp, #0x160
//   0x0ba88c: FD008BE8  str      d8, [sp, #0x110]
//   0x0ba890: A91263FC  stp      x28, x24, [sp, #0x120]
//   0x0ba894: A9135BF7  stp      x23, x22, [sp, #0x130]
static inline uint64_t fde_func_0224_0x0ba888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba888ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xfd008be8ULL) ^ 0x06eb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0225 | PC: 0x0baa3c | FDE: 0x06ebe8 | Size: 256 bytes
// Khung tháo gỡ #0225 | Địa chỉ PC: 0x0baa3c | Địa chỉ FDE: 0x06ebe8 | Kích thước: 256 bytes
//   0x0baa3c: AA0003E9  mov      x9, x0
//   0x0baa40: F9402129  ldr      x9, [x9, #0x40]
//   0x0baa44: B0FFFBA1  adrp     x1, #0x2f000
//   0x0baa48: B0FFFCCA  adrp     x10, #0x53000
static inline uint64_t fde_func_0225_0x0baa3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baa3cULL ^ (static_cast<uint64_t>(0xaa0003e9ULL) << 13);
    acc = (acc + a1 + 0xf9402129ULL) ^ 0x06ebe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0226 | PC: 0x0bac38 | FDE: 0x06ec68 | Size: 148 bytes
// Khung tháo gỡ #0226 | Địa chỉ PC: 0x0bac38 | Địa chỉ FDE: 0x06ec68 | Kích thước: 148 bytes
//   0x0bac38: F9401800  ldr      x0, [x0, #0x30]
//   0x0bac3c: 1E624000  fcvt     s0, d0
//   0x0bac40: 1E624021  fcvt     s1, d1
//   0x0bac44: 140027BD  b        #0xc4b38
static inline uint64_t fde_func_0226_0x0bac38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bac38ULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0x1e624000ULL) ^ 0x06ec68ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0227 | PC: 0x0baccc | FDE: 0x06ecc8 | Size: 256 bytes
// Khung tháo gỡ #0227 | Địa chỉ PC: 0x0baccc | Địa chỉ FDE: 0x06ecc8 | Kích thước: 256 bytes
//   0x0baccc: D100C3FF  sub      sp, sp, #0x30
//   0x0bacd0: F90013FE  str      x30, [sp, #0x20]
//   0x0bacd4: D53BD048  mrs      x8, tpidr_el0
//   0x0bacd8: F9401509  ldr      x9, [x8, #0x28]
static inline uint64_t fde_func_0227_0x0baccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bacccULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013feULL) ^ 0x06ecc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0228 | PC: 0x0badf8 | FDE: 0x06ed30 | Size: 256 bytes
// Khung tháo gỡ #0228 | Địa chỉ PC: 0x0badf8 | Địa chỉ FDE: 0x06ed30 | Kích thước: 256 bytes
//   0x0badf8: F9401800  ldr      x0, [x0, #0x30]
//   0x0badfc: 1400288B  b        #0xc5028
//   0x0bae00: D10243FF  sub      sp, sp, #0x90
//   0x0bae04: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0228_0x0badf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0badf8ULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0x1400288bULL) ^ 0x06ed30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0229 | PC: 0x0baf48 | FDE: 0x06eda8 | Size: 256 bytes
// Khung tháo gỡ #0229 | Địa chỉ PC: 0x0baf48 | Địa chỉ FDE: 0x06eda8 | Kích thước: 256 bytes
//   0x0baf48: D10583FF  sub      sp, sp, #0x160
//   0x0baf4c: A91453FC  stp      x28, x20, [sp, #0x140]
//   0x0baf50: A9157BF3  stp      x19, x30, [sp, #0x150]
//   0x0baf54: 9402EE70  bl       #0x176914
static inline uint64_t fde_func_0229_0x0baf48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baf48ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa91453fcULL) ^ 0x06eda8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0230 | PC: 0x0bb1c0 | FDE: 0x06ee30 | Size: 256 bytes
// Khung tháo gỡ #0230 | Địa chỉ PC: 0x0bb1c0 | Địa chỉ FDE: 0x06ee30 | Kích thước: 256 bytes
//   0x0bb1c0: D10543FF  sub      sp, sp, #0x150
//   0x0bb1c4: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0bb1c8: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0bb1cc: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0230_0x0bb1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb1c0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x06ee30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0231 | PC: 0x0bb564 | FDE: 0x06eec8 | Size: 256 bytes
// Khung tháo gỡ #0231 | Địa chỉ PC: 0x0bb564 | Địa chỉ FDE: 0x06eec8 | Kích thước: 256 bytes
//   0x0bb564: D10183FF  sub      sp, sp, #0x60
//   0x0bb568: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x0bb56c: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x0bb570: F90023F4  str      x20, [sp, #0x40]
static inline uint64_t fde_func_0231_0x0bb564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb564ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0x6d022bebULL) ^ 0x06eec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0232 | PC: 0x0bb6dc | FDE: 0x06ef68 | Size: 256 bytes
// Khung tháo gỡ #0232 | Địa chỉ PC: 0x0bb6dc | Địa chỉ FDE: 0x06ef68 | Kích thước: 256 bytes
//   0x0bb6dc: 6DBD2BEB  stp      d11, d10, [sp, #-0x30]!
//   0x0bb6e0: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x0bb6e4: F90013FE  str      x30, [sp, #0x20]
//   0x0bb6e8: 52800F00  mov      w0, #0x78
static inline uint64_t fde_func_0232_0x0bb6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb6dcULL ^ (static_cast<uint64_t>(0x6dbd2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x06ef68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0233 | PC: 0x0bb988 | FDE: 0x06f000 | Size: 256 bytes
// Khung tháo gỡ #0233 | Địa chỉ PC: 0x0bb988 | Địa chỉ FDE: 0x06f000 | Kích thước: 256 bytes
//   0x0bb988: 14030A12  b        #0x17e1d0
//   0x0bb98c: AA1E03E6  mov      x6, x30
//   0x0bb990: 9402EFB0  bl       #0x177850
//   0x0bb994: AA0603FE  mov      x30, x6
static inline uint64_t fde_func_0233_0x0bb988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb988ULL ^ (static_cast<uint64_t>(0x14030a12ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e6ULL) ^ 0x06f000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0234 | PC: 0x0bbbb4 | FDE: 0x06f090 | Size: 200 bytes
// Khung tháo gỡ #0234 | Địa chỉ PC: 0x0bbbb4 | Địa chỉ FDE: 0x06f090 | Kích thước: 200 bytes
//   0x0bbbb4: 3941E000  ldrb     w0, [x0, #0x78]
//   0x0bbbb8: D65F03C0  ret      
//   0x0bbbbc: 12000028  and      w8, w1, #1
//   0x0bbbc0: 3901E008  strb     w8, [x0, #0x78]
static inline uint64_t fde_func_0234_0x0bbbb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbbb4ULL ^ (static_cast<uint64_t>(0x3941e000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x06f090ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0235 | PC: 0x0bbc7c | FDE: 0x06f100 | Size: 256 bytes
// Khung tháo gỡ #0235 | Địa chỉ PC: 0x0bbc7c | Địa chỉ FDE: 0x06f100 | Kích thước: 256 bytes
//   0x0bbc7c: AA1E03E1  mov      x1, x30
//   0x0bbc80: 940317CB  bl       #0x181bac
//   0x0bbc84: AA0103FE  mov      x30, x1
//   0x0bbc88: A91A7BF3  stp      x19, x30, [sp, #0x1a0]
static inline uint64_t fde_func_0235_0x0bbc7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbc7cULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940317cbULL) ^ 0x06f100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0236 | PC: 0x0bc1e8 | FDE: 0x06f198 | Size: 256 bytes
// Khung tháo gỡ #0236 | Địa chỉ PC: 0x0bc1e8 | Địa chỉ FDE: 0x06f198 | Kích thước: 256 bytes
//   0x0bc1e8: F9402009  ldr      x9, [x0, #0x40]
//   0x0bc1ec: AA0803E0  mov      x0, x8
//   0x0bc1f0: D1014121  sub      x1, x9, #0x50
//   0x0bc1f4: 17FFB85E  b        #0xaa36c
static inline uint64_t fde_func_0236_0x0bc1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc1e8ULL ^ (static_cast<uint64_t>(0xf9402009ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x06f198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0237 | PC: 0x0bc3cc | FDE: 0x06f208 | Size: 104 bytes
// Khung tháo gỡ #0237 | Địa chỉ PC: 0x0bc3cc | Địa chỉ FDE: 0x06f208 | Kích thước: 104 bytes
//   0x0bc3cc: 52800022  mov      w2, #1
//   0x0bc3d0: AA1F03E3  mov      x3, xzr
//   0x0bc3d4: 1400042E  b        #0xbd48c
//   0x0bc3d8: D10083FF  sub      sp, sp, #0x20
static inline uint64_t fde_func_0237_0x0bc3cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc3ccULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x06f208ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0238 | PC: 0x0bc434 | FDE: 0x06f268 | Size: 256 bytes
// Khung tháo gỡ #0238 | Địa chỉ PC: 0x0bc434 | Địa chỉ FDE: 0x06f268 | Kích thước: 256 bytes
//   0x0bc434: D10403FF  sub      sp, sp, #0x100
//   0x0bc438: 6D083BEF  stp      d15, d14, [sp, #0x80]
//   0x0bc43c: 6D0933ED  stp      d13, d12, [sp, #0x90]
//   0x0bc440: 6D0A2BEB  stp      d11, d10, [sp, #0xa0]
static inline uint64_t fde_func_0238_0x0bc434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc434ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0x6d083befULL) ^ 0x06f268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0239 | PC: 0x0bc6e4 | FDE: 0x06f2f0 | Size: 256 bytes
// Khung tháo gỡ #0239 | Địa chỉ PC: 0x0bc6e4 | Địa chỉ FDE: 0x06f2f0 | Kích thước: 256 bytes
//   0x0bc6e4: D10103FF  sub      sp, sp, #0x40
//   0x0bc6e8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0bc6ec: 9402E88A  bl       #0x176914
//   0x0bc6f0: 1E624000  fcvt     s0, d0
static inline uint64_t fde_func_0239_0x0bc6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc6e4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x06f2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0240 | PC: 0x0bca2c | FDE: 0x06f368 | Size: 256 bytes
// Khung tháo gỡ #0240 | Địa chỉ PC: 0x0bca2c | Địa chỉ FDE: 0x06f368 | Kích thước: 256 bytes
//   0x0bca2c: FC1B0FEE  str      d14, [sp, #-0x50]!
//   0x0bca30: 6D00B3ED  stp      d13, d12, [sp, #8]
//   0x0bca34: 6D01ABEB  stp      d11, d10, [sp, #0x18]
//   0x0bca38: 6D02A3E9  stp      d9, d8, [sp, #0x28]
static inline uint64_t fde_func_0240_0x0bca2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bca2cULL ^ (static_cast<uint64_t>(0xfc1b0feeULL) << 13);
    acc = (acc + a1 + 0x6d00b3edULL) ^ 0x06f368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0241 | PC: 0x0bcbe4 | FDE: 0x06f3e8 | Size: 256 bytes
// Khung tháo gỡ #0241 | Địa chỉ PC: 0x0bcbe4 | Địa chỉ FDE: 0x06f3e8 | Kích thước: 256 bytes
//   0x0bcbe4: AA1E03E2  mov      x2, x30
//   0x0bcbe8: 94032376  bl       #0x1859c0
//   0x0bcbec: AA0203FE  mov      x30, x2
//   0x0bcbf0: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_0241_0x0bcbe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcbe4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94032376ULL) ^ 0x06f3e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0242 | PC: 0x0bcd34 | FDE: 0x06f458 | Size: 256 bytes
// Khung tháo gỡ #0242 | Địa chỉ PC: 0x0bcd34 | Địa chỉ FDE: 0x06f458 | Kích thước: 256 bytes
//   0x0bcd34: D10583FF  sub      sp, sp, #0x160
//   0x0bcd38: F9009BFC  str      x28, [sp, #0x130]
//   0x0bcd3c: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0bcd40: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0242_0x0bcd34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcd34ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x06f458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0243 | PC: 0x0bce68 | FDE: 0x06f4c8 | Size: 256 bytes
// Khung tháo gỡ #0243 | Địa chỉ PC: 0x0bce68 | Địa chỉ FDE: 0x06f4c8 | Kích thước: 256 bytes
//   0x0bce68: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0bce6c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0bce70: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0bce74: A9405416  ldp      x22, x21, [x0]
static inline uint64_t fde_func_0243_0x0bce68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bce68ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06f4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0244 | PC: 0x0bcf94 | FDE: 0x06f548 | Size: 256 bytes
// Khung tháo gỡ #0244 | Địa chỉ PC: 0x0bcf94 | Địa chỉ FDE: 0x06f548 | Kích thước: 256 bytes
//   0x0bcf94: A9007C1F  stp      xzr, xzr, [x0]
//   0x0bcf98: F900081F  str      xzr, [x0, #0x10]
//   0x0bcf9c: 39400028  ldrb     w8, [x1]
//   0x0bcfa0: A940AC2A  ldp      x10, x11, [x1, #8]
static inline uint64_t fde_func_0244_0x0bcf94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcf94ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xf900081fULL) ^ 0x06f548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0245 | PC: 0x0bd3f0 | FDE: 0x06f5c0 | Size: 256 bytes
// Khung tháo gỡ #0245 | Địa chỉ PC: 0x0bd3f0 | Địa chỉ FDE: 0x06f5c0 | Kích thước: 256 bytes
//   0x0bd3f0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0bd3f4: AA0003F3  mov      x19, x0
//   0x0bd3f8: 940329F6  bl       #0x187bd0
//   0x0bd3fc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0245_0x0bd3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd3f0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06f5c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0246 | PC: 0x0bd73c | FDE: 0x06f648 | Size: 240 bytes
// Khung tháo gỡ #0246 | Địa chỉ PC: 0x0bd73c | Địa chỉ FDE: 0x06f648 | Kích thước: 240 bytes
//   0x0bd73c: D100C3FF  sub      sp, sp, #0x30
//   0x0bd740: F9000BF4  str      x20, [sp, #0x10]
//   0x0bd744: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0bd748: 9402EA88  bl       #0x178168
static inline uint64_t fde_func_0246_0x0bd73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd73cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x06f648ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0247 | PC: 0x0bd82c | FDE: 0x06f6b0 | Size: 256 bytes
// Khung tháo gỡ #0247 | Địa chỉ PC: 0x0bd82c | Địa chỉ FDE: 0x06f6b0 | Kích thước: 256 bytes
//   0x0bd82c: 90000688  adrp     x8, #0x18d000
//   0x0bd830: 912C4108  add      x8, x8, #0xb10
//   0x0bd834: F9000028  str      x8, [x1]
//   0x0bd838: 3CC18000  ldur     q0, [x0, #0x18]
static inline uint64_t fde_func_0247_0x0bd82c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd82cULL ^ (static_cast<uint64_t>(0x90000688ULL) << 13);
    acc = (acc + a1 + 0x912c4108ULL) ^ 0x06f6b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0248 | PC: 0x0bd960 | FDE: 0x06f720 | Size: 240 bytes
// Khung tháo gỡ #0248 | Địa chỉ PC: 0x0bd960 | Địa chỉ FDE: 0x06f720 | Kích thước: 240 bytes
//   0x0bd960: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0bd964: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0bd968: 9402E18E  bl       #0x175fa0
//   0x0bd96c: 94000009  bl       #0xbd990
static inline uint64_t fde_func_0248_0x0bd960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd960ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06f720ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0249 | PC: 0x0bda50 | FDE: 0x06f7a0 | Size: 256 bytes
// Khung tháo gỡ #0249 | Địa chỉ PC: 0x0bda50 | Địa chỉ FDE: 0x06f7a0 | Kích thước: 256 bytes
//   0x0bda50: D10183FF  sub      sp, sp, #0x60
//   0x0bda54: FD0013E8  str      d8, [sp, #0x20]
//   0x0bda58: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0bda5c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0249_0x0bda50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bda50ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x06f7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0250 | PC: 0x0bdb78 | FDE: 0x06f818 | Size: 256 bytes
// Khung tháo gỡ #0250 | Địa chỉ PC: 0x0bdb78 | Địa chỉ FDE: 0x06f818 | Kích thước: 256 bytes
//   0x0bdb78: D100C3FF  sub      sp, sp, #0x30
//   0x0bdb7c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0bdb80: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0bdb84: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0250_0x0bdb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdb78ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06f818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0251 | PC: 0x0bde94 | FDE: 0x06f8a8 | Size: 84 bytes
// Khung tháo gỡ #0251 | Địa chỉ PC: 0x0bde94 | Địa chỉ FDE: 0x06f8a8 | Kích thước: 84 bytes
//   0x0bde94: F9400020  ldr      x0, [x1]
//   0x0bde98: 140024F9  b        #0xc727c
//   0x0bde9c: 90000688  adrp     x8, #0x18d000
//   0x0bdea0: 912E8108  add      x8, x8, #0xba0
static inline uint64_t fde_func_0251_0x0bde94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bde94ULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0x140024f9ULL) ^ 0x06f8a8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0252 | PC: 0x0bdee8 | FDE: 0x06f910 | Size: 156 bytes
// Khung tháo gỡ #0252 | Địa chỉ PC: 0x0bdee8 | Địa chỉ FDE: 0x06f910 | Kích thước: 156 bytes
//   0x0bdee8: 90000689  adrp     x9, #0x18d000
//   0x0bdeec: AA0103E8  mov      x8, x1
//   0x0bdef0: 912E8129  add      x9, x9, #0xba0
//   0x0bdef4: 1402F440  b        #0x17aff4
static inline uint64_t fde_func_0252_0x0bdee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdee8ULL ^ (static_cast<uint64_t>(0x90000689ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x06f910ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0253 | PC: 0x0bdf84 | FDE: 0x06f978 | Size: 256 bytes
// Khung tháo gỡ #0253 | Địa chỉ PC: 0x0bdf84 | Địa chỉ FDE: 0x06f978 | Kích thước: 256 bytes
//   0x0bdf84: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0bdf88: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0bdf8c: 9402E3BB  bl       #0x176e78
//   0x0bdf90: 940324F0  bl       #0x187350
static inline uint64_t fde_func_0253_0x0bdf84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdf84ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06f978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0254 | PC: 0x0be094 | FDE: 0x06f9e8 | Size: 184 bytes
// Khung tháo gỡ #0254 | Địa chỉ PC: 0x0be094 | Địa chỉ FDE: 0x06f9e8 | Kích thước: 184 bytes
//   0x0be094: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0be098: AA0103F3  mov      x19, x1
//   0x0be09c: 94000009  bl       #0xbe0c0
//   0x0be0a0: 3CC38260  ldur     q0, [x19, #0x38]
static inline uint64_t fde_func_0254_0x0be094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be094ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x06f9e8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0255 | PC: 0x0be14c | FDE: 0x06fa50 | Size: 256 bytes
// Khung tháo gỡ #0255 | Địa chỉ PC: 0x0be14c | Địa chỉ FDE: 0x06fa50 | Kích thước: 256 bytes
//   0x0be14c: AA1E03E1  mov      x1, x30
//   0x0be150: 94030F60  bl       #0x181ed0
//   0x0be154: AA0103FE  mov      x30, x1
//   0x0be158: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0255_0x0be14c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be14cULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94030f60ULL) ^ 0x06fa50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0256 | PC: 0x0be980 | FDE: 0x06fb00 | Size: 256 bytes
// Khung tháo gỡ #0256 | Địa chỉ PC: 0x0be980 | Địa chỉ FDE: 0x06fb00 | Kích thước: 256 bytes
//   0x0be980: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0be984: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0be988: 9402FD12  bl       #0x17ddd0
//   0x0be98c: 940003CD  bl       #0xbf8c0
static inline uint64_t fde_func_0256_0x0be980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be980ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x06fb00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0257 | PC: 0x0beedc | FDE: 0x06fb80 | Size: 256 bytes
// Khung tháo gỡ #0257 | Địa chỉ PC: 0x0beedc | Địa chỉ FDE: 0x06fb80 | Kích thước: 256 bytes
//   0x0beedc: FC190FE8  str      d8, [sp, #-0x70]!
//   0x0beee0: AA1E03E8  mov      x8, x30
//   0x0beee4: 9402DEDF  bl       #0x176a60
//   0x0beee8: AA0803FE  mov      x30, x8
static inline uint64_t fde_func_0257_0x0beedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beedcULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e8ULL) ^ 0x06fb80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0258 | PC: 0x0bf518 | FDE: 0x06fc20 | Size: 256 bytes
// Khung tháo gỡ #0258 | Địa chỉ PC: 0x0bf518 | Địa chỉ FDE: 0x06fc20 | Kích thước: 256 bytes
//   0x0bf518: AA1E03E8  mov      x8, x30
//   0x0bf51c: 9402DCF8  bl       #0x1768fc
//   0x0bf520: AA0803FE  mov      x30, x8
//   0x0bf524: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0258_0x0bf518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf518ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9402dcf8ULL) ^ 0x06fc20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0259 | PC: 0x0bf8c0 | FDE: 0x06fcb0 | Size: 256 bytes
// Khung tháo gỡ #0259 | Địa chỉ PC: 0x0bf8c0 | Địa chỉ FDE: 0x06fcb0 | Kích thước: 256 bytes
//   0x0bf8c0: B9803808  ldrsw    x8, [x0, #0x38]
//   0x0bf8c4: AA1F03E9  mov      x9, xzr
//   0x0bf8c8: 9280000A  mov      x10, #-1
//   0x0bf8cc: 9100054A  add      x10, x10, #1
static inline uint64_t fde_func_0259_0x0bf8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf8c0ULL ^ (static_cast<uint64_t>(0xb9803808ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e9ULL) ^ 0x06fcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0260 | PC: 0x0bfa14 | FDE: 0x06fd20 | Size: 256 bytes
// Khung tháo gỡ #0260 | Địa chỉ PC: 0x0bfa14 | Địa chỉ FDE: 0x06fd20 | Kích thước: 256 bytes
//   0x0bfa14: D10343FF  sub      sp, sp, #0xd0
//   0x0bfa18: FD003BEC  str      d12, [sp, #0x70]
//   0x0bfa1c: 6D082BEB  stp      d11, d10, [sp, #0x80]
//   0x0bfa20: 6D0923E9  stp      d9, d8, [sp, #0x90]
static inline uint64_t fde_func_0260_0x0bfa14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfa14ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xfd003becULL) ^ 0x06fd20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0261 | PC: 0x0bfd70 | FDE: 0x06fda0 | Size: 256 bytes
// Khung tháo gỡ #0261 | Địa chỉ PC: 0x0bfd70 | Địa chỉ FDE: 0x06fda0 | Kích thước: 256 bytes
//   0x0bfd70: AA0003E8  mov      x8, x0
//   0x0bfd74: AA1F03E9  mov      x9, xzr
//   0x0bfd78: 2A1F03E0  mov      w0, wzr
//   0x0bfd7c: 93407C2A  sxtw     x10, w1
static inline uint64_t fde_func_0261_0x0bfd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfd70ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e9ULL) ^ 0x06fda0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0262 | PC: 0x0c00b0 | FDE: 0x06fe28 | Size: 256 bytes
// Khung tháo gỡ #0262 | Địa chỉ PC: 0x0c00b0 | Địa chỉ FDE: 0x06fe28 | Kích thước: 256 bytes
//   0x0c00b0: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0c00b4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c00b8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c00bc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0262_0x0c00b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c00b0ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x06fe28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0263 | PC: 0x0c033c | FDE: 0x06feb0 | Size: 256 bytes
// Khung tháo gỡ #0263 | Địa chỉ PC: 0x0c033c | Địa chỉ FDE: 0x06feb0 | Kích thước: 256 bytes
//   0x0c033c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0c0340: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0c0344: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0c0348: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0263_0x0c033c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c033cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x06feb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0264 | PC: 0x0c0504 | FDE: 0x06ff30 | Size: 256 bytes
// Khung tháo gỡ #0264 | Địa chỉ PC: 0x0c0504 | Địa chỉ FDE: 0x06ff30 | Kích thước: 256 bytes
//   0x0c0504: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c0508: AA0003F3  mov      x19, x0
//   0x0c050c: 97FFFFED  bl       #0xc04c0
//   0x0c0510: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0264_0x0c0504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0504ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x06ff30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0265 | PC: 0x0c063c | FDE: 0x06ffb8 | Size: 256 bytes
// Khung tháo gỡ #0265 | Địa chỉ PC: 0x0c063c | Địa chỉ FDE: 0x06ffb8 | Kích thước: 256 bytes
//   0x0c063c: 1402F9CD  b        #0x17ed70
//   0x0c0640: D10183FF  sub      sp, sp, #0x60
//   0x0c0644: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0c0648: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0265_0x0c063c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c063cULL ^ (static_cast<uint64_t>(0x1402f9cdULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x06ffb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0266 | PC: 0x0c0914 | FDE: 0x070040 | Size: 256 bytes
// Khung tháo gỡ #0266 | Địa chỉ PC: 0x0c0914 | Địa chỉ FDE: 0x070040 | Kích thước: 256 bytes
//   0x0c0914: AA1E03E2  mov      x2, x30
//   0x0c0918: 9402F043  bl       #0x17ca24
//   0x0c091c: AA0203FE  mov      x30, x2
//   0x0c0920: A9187BF3  stp      x19, x30, [sp, #0x180]
static inline uint64_t fde_func_0266_0x0c0914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0914ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402f043ULL) ^ 0x070040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0267 | PC: 0x0c1868 | FDE: 0x0700d8 | Size: 212 bytes
// Khung tháo gỡ #0267 | Địa chỉ PC: 0x0c1868 | Địa chỉ FDE: 0x0700d8 | Kích thước: 212 bytes
//   0x0c1868: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c186c: 52A7F008  mov      w8, #0x3f800000
//   0x0c1870: D0FFFBA1  adrp     x1, #0x37000
//   0x0c1874: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0267_0x0c1868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1868ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x52a7f008ULL) ^ 0x0700d8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0268 | PC: 0x0c193c | FDE: 0x070150 | Size: 256 bytes
// Khung tháo gỡ #0268 | Địa chỉ PC: 0x0c193c | Địa chỉ FDE: 0x070150 | Kích thước: 256 bytes
//   0x0c193c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c1940: AA0003F3  mov      x19, x0
//   0x0c1944: 91010000  add      x0, x0, #0x40
//   0x0c1948: 97FFA7BE  bl       #0xab840
static inline uint64_t fde_func_0268_0x0c193c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c193cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x070150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0269 | PC: 0x0c1a7c | FDE: 0x0701c8 | Size: 256 bytes
// Khung tháo gỡ #0269 | Địa chỉ PC: 0x0c1a7c | Địa chỉ FDE: 0x0701c8 | Kích thước: 256 bytes
//   0x0c1a7c: F9402400  ldr      x0, [x0, #0x48]
//   0x0c1a80: 17FFACB4  b        #0xacd50
//   0x0c1a84: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0c1a88: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0269_0x0c1a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1a7cULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0x17ffacb4ULL) ^ 0x0701c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0270 | PC: 0x0c1e2c | FDE: 0x070248 | Size: 256 bytes
// Khung tháo gỡ #0270 | Địa chỉ PC: 0x0c1e2c | Địa chỉ FDE: 0x070248 | Kích thước: 256 bytes
//   0x0c1e2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c1e30: 39447008  ldrb     w8, [x0, #0x11c]
//   0x0c1e34: AA0003F3  mov      x19, x0
//   0x0c1e38: 34000068  cbz      w8, #0xc1e44
static inline uint64_t fde_func_0270_0x0c1e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1e2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39447008ULL) ^ 0x070248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0271 | PC: 0x0c1fe4 | FDE: 0x0702b0 | Size: 256 bytes
// Khung tháo gỡ #0271 | Địa chỉ PC: 0x0c1fe4 | Địa chỉ FDE: 0x0702b0 | Kích thước: 256 bytes
//   0x0c1fe4: 37100060  tbnz     w0, #2, #0xc1ff0
//   0x0c1fe8: 37500060  tbnz     w0, #0xa, #0xc1ff4
//   0x0c1fec: 36400060  tbz      w0, #8, #0xc1ff8
//   0x0c1ff0: 1402D0D0  b        #0x176330
static inline uint64_t fde_func_0271_0x0c1fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1fe4ULL ^ (static_cast<uint64_t>(0x37100060ULL) << 13);
    acc = (acc + a1 + 0x37500060ULL) ^ 0x0702b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0272 | PC: 0x0c2358 | FDE: 0x070338 | Size: 256 bytes
// Khung tháo gỡ #0272 | Địa chỉ PC: 0x0c2358 | Địa chỉ FDE: 0x070338 | Kích thước: 256 bytes
//   0x0c2358: D10603FF  sub      sp, sp, #0x180
//   0x0c235c: 6D0E3BEF  stp      d15, d14, [sp, #0xe0]
//   0x0c2360: 6D0F33ED  stp      d13, d12, [sp, #0xf0]
//   0x0c2364: 6D102BEB  stp      d11, d10, [sp, #0x100]
static inline uint64_t fde_func_0272_0x0c2358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2358ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0x6d0e3befULL) ^ 0x070338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0273 | PC: 0x0c374c | FDE: 0x0703e8 | Size: 256 bytes
// Khung tháo gỡ #0273 | Địa chỉ PC: 0x0c374c | Địa chỉ FDE: 0x0703e8 | Kích thước: 256 bytes
//   0x0c374c: AA1E03E3  mov      x3, x30
//   0x0c3750: 9402D17F  bl       #0x177d4c
//   0x0c3754: AA0303FE  mov      x30, x3
//   0x0c3758: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0273_0x0c374c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c374cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9402d17fULL) ^ 0x0703e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0274 | PC: 0x0c3e8c | FDE: 0x070480 | Size: 256 bytes
// Khung tháo gỡ #0274 | Địa chỉ PC: 0x0c3e8c | Địa chỉ FDE: 0x070480 | Kích thước: 256 bytes
//   0x0c3e8c: 7100049F  cmp      w4, #1
//   0x0c3e90: 5400038B  b.lt     #0xc3f00
//   0x0c3e94: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x0c3e98: A9015BF7  stp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_0274_0x0c3e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3e8cULL ^ (static_cast<uint64_t>(0x7100049fULL) << 13);
    acc = (acc + a1 + 0x5400038bULL) ^ 0x070480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0275 | PC: 0x0c404c | FDE: 0x0704f0 | Size: 244 bytes
// Khung tháo gỡ #0275 | Địa chỉ PC: 0x0c404c | Địa chỉ FDE: 0x0704f0 | Kích thước: 244 bytes
//   0x0c404c: B940100A  ldr      w10, [x0, #0x10]
//   0x0c4050: 3400026A  cbz      w10, #0xc409c
//   0x0c4054: 937F7C29  sbfiz    x9, x1, #1, #0x20
//   0x0c4058: 8B21C129  add      x9, x9, w1, sxtw
static inline uint64_t fde_func_0275_0x0c404c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c404cULL ^ (static_cast<uint64_t>(0xb940100aULL) << 13);
    acc = (acc + a1 + 0x3400026aULL) ^ 0x0704f0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0276 | PC: 0x0c4140 | FDE: 0x070550 | Size: 256 bytes
// Khung tháo gỡ #0276 | Địa chỉ PC: 0x0c4140 | Địa chỉ FDE: 0x070550 | Kích thước: 256 bytes
//   0x0c4140: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0c4144: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c4148: B9400008  ldr      w8, [x0]
//   0x0c414c: 9402F3F3  bl       #0x181118
static inline uint64_t fde_func_0276_0x0c4140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4140ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x070550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0277 | PC: 0x0c42f0 | FDE: 0x0705c8 | Size: 256 bytes
// Khung tháo gỡ #0277 | Địa chỉ PC: 0x0c42f0 | Địa chỉ FDE: 0x0705c8 | Kích thước: 256 bytes
//   0x0c42f0: B40001A0  cbz      x0, #0xc4324
//   0x0c42f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c42f8: 94030A45  bl       #0x186c0c
//   0x0c42fc: 9402D8F1  bl       #0x17a6c0
static inline uint64_t fde_func_0277_0x0c42f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c42f0ULL ^ (static_cast<uint64_t>(0xb40001a0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x0705c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0278 | PC: 0x0c44d4 | FDE: 0x070640 | Size: 216 bytes
// Khung tháo gỡ #0278 | Địa chỉ PC: 0x0c44d4 | Địa chỉ FDE: 0x070640 | Kích thước: 216 bytes
//   0x0c44d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c44d8: AA0003F3  mov      x19, x0
//   0x0c44dc: 97FFFF13  bl       #0xc4128
//   0x0c44e0: F9400A60  ldr      x0, [x19, #0x10]
static inline uint64_t fde_func_0278_0x0c44d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c44d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x070640ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0279 | PC: 0x0c45ac | FDE: 0x0706a8 | Size: 256 bytes
// Khung tháo gỡ #0279 | Địa chỉ PC: 0x0c45ac | Địa chỉ FDE: 0x0706a8 | Kích thước: 256 bytes
//   0x0c45ac: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x0c45b0: F9000BF4  str      x20, [sp, #0x10]
//   0x0c45b4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0c45b8: 5296D588  mov      w8, #0xb6ac
static inline uint64_t fde_func_0279_0x0c45ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c45acULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0706a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0280 | PC: 0x0c4744 | FDE: 0x070710 | Size: 256 bytes
// Khung tháo gỡ #0280 | Địa chỉ PC: 0x0c4744 | Địa chỉ FDE: 0x070710 | Kích thước: 256 bytes
//   0x0c4744: D10103FF  sub      sp, sp, #0x40
//   0x0c4748: F90013F4  str      x20, [sp, #0x20]
//   0x0c474c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0c4750: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0280_0x0c4744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4744ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x070710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0281 | PC: 0x0c4934 | FDE: 0x070778 | Size: 256 bytes
// Khung tháo gỡ #0281 | Địa chỉ PC: 0x0c4934 | Địa chỉ FDE: 0x070778 | Kích thước: 256 bytes
//   0x0c4934: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0c4938: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0c493c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0c4940: B9400C28  ldr      w8, [x1, #0xc]
static inline uint64_t fde_func_0281_0x0c4934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4934ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x070778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0282 | PC: 0x0c4b38 | FDE: 0x0707e8 | Size: 180 bytes
// Khung tháo gỡ #0282 | Địa chỉ PC: 0x0c4b38 | Địa chỉ FDE: 0x0707e8 | Kích thước: 180 bytes
//   0x0c4b38: D100C3FF  sub      sp, sp, #0x30
//   0x0c4b3c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0c4b40: 9402E9F0  bl       #0x17f300
//   0x0c4b44: 910003E1  mov      x1, sp
static inline uint64_t fde_func_0282_0x0c4b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4b38ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0707e8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0283 | PC: 0x0c4bec | FDE: 0x070850 | Size: 256 bytes
// Khung tháo gỡ #0283 | Địa chỉ PC: 0x0c4bec | Địa chỉ FDE: 0x070850 | Kích thước: 256 bytes
//   0x0c4bec: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0c4bf0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c4bf4: 9402F2C8  bl       #0x181714
//   0x0c4bf8: D102B293  sub      x19, x20, #0xac
static inline uint64_t fde_func_0283_0x0c4bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4becULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x070850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0284 | PC: 0x0c4f8c | FDE: 0x0708d8 | Size: 252 bytes
// Khung tháo gỡ #0284 | Địa chỉ PC: 0x0c4f8c | Địa chỉ FDE: 0x0708d8 | Kích thước: 252 bytes
//   0x0c4f8c: 6F00E404  movi     v4.2d, #0000000000000000
//   0x0c4f90: 2D020400  stp      s0, s1, [x0, #0x10]
//   0x0c4f94: 4F03F600  fmov     v0.4s, #1.00000000
//   0x0c4f98: F0FFFB28  adrp     x8, #0x2b000
static inline uint64_t fde_func_0284_0x0c4f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4f8cULL ^ (static_cast<uint64_t>(0x6f00e404ULL) << 13);
    acc = (acc + a1 + 0x2d020400ULL) ^ 0x0708d8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0285 | PC: 0x0c5088 | FDE: 0x070938 | Size: 256 bytes
// Khung tháo gỡ #0285 | Địa chỉ PC: 0x0c5088 | Địa chỉ FDE: 0x070938 | Kích thước: 256 bytes
//   0x0c5088: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0c508c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c5090: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c5094: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0285_0x0c5088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5088ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x070938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0286 | PC: 0x0c54d4 | FDE: 0x0709d0 | Size: 256 bytes
// Khung tháo gỡ #0286 | Địa chỉ PC: 0x0c54d4 | Địa chỉ FDE: 0x0709d0 | Kích thước: 256 bytes
//   0x0c54d4: D10083FF  sub      sp, sp, #0x20
//   0x0c54d8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c54dc: 9402C50E  bl       #0x176914
//   0x0c54e0: 52A80809  mov      w9, #0x40400000
static inline uint64_t fde_func_0286_0x0c54d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c54d4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0709d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0287 | PC: 0x0c5f00 | FDE: 0x070a68 | Size: 256 bytes
// Khung tháo gỡ #0287 | Địa chỉ PC: 0x0c5f00 | Địa chỉ FDE: 0x070a68 | Kích thước: 256 bytes
//   0x0c5f00: D10303FF  sub      sp, sp, #0xc0
//   0x0c5f04: 6D023BEF  stp      d15, d14, [sp, #0x20]
//   0x0c5f08: 6D0333ED  stp      d13, d12, [sp, #0x30]
//   0x0c5f0c: 6D042BEB  stp      d11, d10, [sp, #0x40]
static inline uint64_t fde_func_0287_0x0c5f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5f00ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0x6d023befULL) ^ 0x070a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0288 | PC: 0x0c67ec | FDE: 0x070b20 | Size: 256 bytes
// Khung tháo gỡ #0288 | Địa chỉ PC: 0x0c67ec | Địa chỉ FDE: 0x070b20 | Kích thước: 256 bytes
//   0x0c67ec: BD400041  ldr      s1, [x2]
//   0x0c67f0: 34000260  cbz      w0, #0xc683c
//   0x0c67f4: BD400C22  ldr      s2, [x1, #0xc]
//   0x0c67f8: 1E200842  fmul     s2, s2, s0
static inline uint64_t fde_func_0288_0x0c67ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c67ecULL ^ (static_cast<uint64_t>(0xbd400041ULL) << 13);
    acc = (acc + a1 + 0x34000260ULL) ^ 0x070b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0289 | PC: 0x0c6ab4 | FDE: 0x070b98 | Size: 256 bytes
// Khung tháo gỡ #0289 | Địa chỉ PC: 0x0c6ab4 | Địa chỉ FDE: 0x070b98 | Kích thước: 256 bytes
//   0x0c6ab4: 6DB93BEF  stp      d15, d14, [sp, #-0x70]!
//   0x0c6ab8: 6D0133ED  stp      d13, d12, [sp, #0x10]
//   0x0c6abc: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x0c6ac0: 6D0323E9  stp      d9, d8, [sp, #0x30]
static inline uint64_t fde_func_0289_0x0c6ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6ab4ULL ^ (static_cast<uint64_t>(0x6db93befULL) << 13);
    acc = (acc + a1 + 0x6d0133edULL) ^ 0x070b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0290 | PC: 0x0c6f5c | FDE: 0x070c38 | Size: 256 bytes
// Khung tháo gỡ #0290 | Địa chỉ PC: 0x0c6f5c | Địa chỉ FDE: 0x070c38 | Kích thước: 256 bytes
//   0x0c6f5c: AA1E03E2  mov      x2, x30
//   0x0c6f60: 9402FA2E  bl       #0x185818
//   0x0c6f64: AA0203FE  mov      x30, x2
//   0x0c6f68: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_0290_0x0c6f5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6f5cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402fa2eULL) ^ 0x070c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0291 | PC: 0x0c7200 | FDE: 0x070cb0 | Size: 256 bytes
// Khung tháo gỡ #0291 | Địa chỉ PC: 0x0c7200 | Địa chỉ FDE: 0x070cb0 | Kích thước: 256 bytes
//   0x0c7200: 5296D588  mov      w8, #0xb6ac
//   0x0c7204: 8B080008  add      x8, x0, x8
//   0x0c7208: B9400109  ldr      w9, [x8]
//   0x0c720c: 7100092A  subs     w10, w9, #2
static inline uint64_t fde_func_0291_0x0c7200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7200ULL ^ (static_cast<uint64_t>(0x5296d588ULL) << 13);
    acc = (acc + a1 + 0x8b080008ULL) ^ 0x070cb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0292 | PC: 0x0c7d30 | FDE: 0x070d58 | Size: 256 bytes
// Khung tháo gỡ #0292 | Địa chỉ PC: 0x0c7d30 | Địa chỉ FDE: 0x070d58 | Kích thước: 256 bytes
//   0x0c7d30: BD4003F0  ldr      s16, [sp]
//   0x0c7d34: 1E250851  fmul     s17, s2, s5
//   0x0c7d38: 1E250865  fmul     s5, s3, s5
//   0x0c7d3c: 1E240872  fmul     s18, s3, s4
static inline uint64_t fde_func_0292_0x0c7d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7d30ULL ^ (static_cast<uint64_t>(0xbd4003f0ULL) << 13);
    acc = (acc + a1 + 0x1e250851ULL) ^ 0x070d58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0293 | PC: 0x0c83b4 | FDE: 0x070dd8 | Size: 256 bytes
// Khung tháo gỡ #0293 | Địa chỉ PC: 0x0c83b4 | Địa chỉ FDE: 0x070dd8 | Kích thước: 256 bytes
//   0x0c83b4: 6DB733ED  stp      d13, d12, [sp, #-0x90]!
//   0x0c83b8: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x0c83bc: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x0c83c0: A9036FFC  stp      x28, x27, [sp, #0x30]
static inline uint64_t fde_func_0293_0x0c83b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c83b4ULL ^ (static_cast<uint64_t>(0x6db733edULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x070dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0294 | PC: 0x0c8a78 | FDE: 0x070e60 | Size: 256 bytes
// Khung tháo gỡ #0294 | Địa chỉ PC: 0x0c8a78 | Địa chỉ FDE: 0x070e60 | Kích thước: 256 bytes
//   0x0c8a78: AA1E03E5  mov      x5, x30
//   0x0c8a7c: 9402D8E2  bl       #0x17ee04
//   0x0c8a80: AA0503FE  mov      x30, x5
//   0x0c8a84: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_0294_0x0c8a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8a78ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9402d8e2ULL) ^ 0x070e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0295 | PC: 0x0c8cb4 | FDE: 0x070ed8 | Size: 256 bytes
// Khung tháo gỡ #0295 | Địa chỉ PC: 0x0c8cb4 | Địa chỉ FDE: 0x070ed8 | Kích thước: 256 bytes
//   0x0c8cb4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0c8cb8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0c8cbc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0c8cc0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0295_0x0c8cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8cb4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x070ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0296 | PC: 0x0c9070 | FDE: 0x070f68 | Size: 256 bytes
// Khung tháo gỡ #0296 | Địa chỉ PC: 0x0c9070 | Địa chỉ FDE: 0x070f68 | Kích thước: 256 bytes
//   0x0c9070: D10583FF  sub      sp, sp, #0x160
//   0x0c9074: F9009BFC  str      x28, [sp, #0x130]
//   0x0c9078: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0c907c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0296_0x0c9070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9070ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x070f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0297 | PC: 0x0c9218 | FDE: 0x070fe0 | Size: 204 bytes
// Khung tháo gỡ #0297 | Địa chỉ PC: 0x0c9218 | Địa chỉ FDE: 0x070fe0 | Kích thước: 204 bytes
//   0x0c9218: B4000160  cbz      x0, #0xc9244
//   0x0c921c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0c9220: 9402B958  bl       #0x177780
//   0x0c9224: 97FFFFFD  bl       #0xc9218
static inline uint64_t fde_func_0297_0x0c9218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9218ULL ^ (static_cast<uint64_t>(0xb4000160ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x070fe0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0298 | PC: 0x0c92e4 | FDE: 0x071040 | Size: 256 bytes
// Khung tháo gỡ #0298 | Địa chỉ PC: 0x0c92e4 | Địa chỉ FDE: 0x071040 | Kích thước: 256 bytes
//   0x0c92e4: AA1E03E2  mov      x2, x30
//   0x0c92e8: 9402CF48  bl       #0x17d008
//   0x0c92ec: AA0203FE  mov      x30, x2
//   0x0c92f0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0298_0x0c92e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c92e4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402cf48ULL) ^ 0x071040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0299 | PC: 0x0c9560 | FDE: 0x0710c0 | Size: 256 bytes
// Khung tháo gỡ #0299 | Địa chỉ PC: 0x0c9560 | Địa chỉ FDE: 0x0710c0 | Kích thước: 256 bytes
//   0x0c9560: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0c9564: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c9568: F9000840  str      x0, [x2, #0x10]
//   0x0c956c: 9402F004  bl       #0x18557c
static inline uint64_t fde_func_0299_0x0c9560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9560ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0710c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0300 | PC: 0x0c97e4 | FDE: 0x071140 | Size: 176 bytes
// Khung tháo gỡ #0300 | Địa chỉ PC: 0x0c97e4 | Địa chỉ FDE: 0x071140 | Kích thước: 176 bytes
//   0x0c97e4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0c97e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0c97ec: F9000840  str      x0, [x2, #0x10]
//   0x0c97f0: F0000660  adrp     x0, #0x198000
static inline uint64_t fde_func_0300_0x0c97e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c97e4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x071140ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0301 | PC: 0x0c9894 | FDE: 0x0711a8 | Size: 256 bytes
// Khung tháo gỡ #0301 | Địa chỉ PC: 0x0c9894 | Địa chỉ FDE: 0x0711a8 | Kích thước: 256 bytes
//   0x0c9894: D10183FF  sub      sp, sp, #0x60
//   0x0c9898: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0c989c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0c98a0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0301_0x0c9894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9894ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0711a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0302 | PC: 0x0c9d80 | FDE: 0x071238 | Size: 256 bytes
// Khung tháo gỡ #0302 | Địa chỉ PC: 0x0c9d80 | Địa chỉ FDE: 0x071238 | Kích thước: 256 bytes
//   0x0c9d80: D10103FF  sub      sp, sp, #0x40
//   0x0c9d84: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0c9d88: 9402DBFC  bl       #0x180d78
//   0x0c9d8c: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0302_0x0c9d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9d80ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x071238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0303 | PC: 0x0ca3b8 | FDE: 0x0712b8 | Size: 256 bytes
// Khung tháo gỡ #0303 | Địa chỉ PC: 0x0ca3b8 | Địa chỉ FDE: 0x0712b8 | Kích thước: 256 bytes
//   0x0ca3b8: D10103FF  sub      sp, sp, #0x40
//   0x0ca3bc: F9000BF6  str      x22, [sp, #0x10]
//   0x0ca3c0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ca3c4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0303_0x0ca3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca3b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0712b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0304 | PC: 0x0ca638 | FDE: 0x071328 | Size: 256 bytes
// Khung tháo gỡ #0304 | Địa chỉ PC: 0x0ca638 | Địa chỉ FDE: 0x071328 | Kích thước: 256 bytes
//   0x0ca638: 90000628  adrp     x8, #0x18e000
//   0x0ca63c: 91026108  add      x8, x8, #0x98
//   0x0ca640: 52A7F009  mov      w9, #0x3f800000
//   0x0ca644: A902FC1F  stp      xzr, xzr, [x0, #0x28]
static inline uint64_t fde_func_0304_0x0ca638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca638ULL ^ (static_cast<uint64_t>(0x90000628ULL) << 13);
    acc = (acc + a1 + 0x91026108ULL) ^ 0x071328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0305 | PC: 0x0cabc8 | FDE: 0x0713b0 | Size: 256 bytes
// Khung tháo gỡ #0305 | Địa chỉ PC: 0x0cabc8 | Địa chỉ FDE: 0x0713b0 | Kích thước: 256 bytes
//   0x0cabc8: D10143FF  sub      sp, sp, #0x50
//   0x0cabcc: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0cabd0: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0cabd4: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_0305_0x0cabc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cabc8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0713b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0306 | PC: 0x0cacf0 | FDE: 0x071430 | Size: 144 bytes
// Khung tháo gỡ #0306 | Địa chỉ PC: 0x0cacf0 | Địa chỉ FDE: 0x071430 | Kích thước: 144 bytes
//   0x0cacf0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0cacf4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0cacf8: 9402ACAA  bl       #0x175fa0
//   0x0cacfc: 97FFBC98  bl       #0xb9f5c
static inline uint64_t fde_func_0306_0x0cacf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cacf0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x071430ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0307 | PC: 0x0cad80 | FDE: 0x0714a0 | Size: 256 bytes
// Khung tháo gỡ #0307 | Địa chỉ PC: 0x0cad80 | Địa chỉ FDE: 0x0714a0 | Kích thước: 256 bytes
//   0x0cad80: A940A408  ldp      x8, x9, [x0, #8]
//   0x0cad84: EB09011F  cmp      x8, x9
//   0x0cad88: 54000080  b.eq     #0xcad98
//   0x0cad8c: D1004129  sub      x9, x9, #0x10
static inline uint64_t fde_func_0307_0x0cad80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cad80ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x0714a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0308 | PC: 0x0cae94 | FDE: 0x071510 | Size: 256 bytes
// Khung tháo gỡ #0308 | Địa chỉ PC: 0x0cae94 | Địa chỉ FDE: 0x071510 | Kích thước: 256 bytes
//   0x0cae94: BD400000  ldr      s0, [x0]
//   0x0cae98: BD400021  ldr      s1, [x1]
//   0x0cae9c: 1E212000  fcmp     s0, s1
//   0x0caea0: 1A9F57E0  cset     w0, mi
static inline uint64_t fde_func_0308_0x0cae94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cae94ULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x071510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0309 | PC: 0x0cb830 | FDE: 0x0715b0 | Size: 220 bytes
// Khung tháo gỡ #0309 | Địa chỉ PC: 0x0cb830 | Địa chỉ FDE: 0x0715b0 | Kích thước: 220 bytes
//   0x0cb830: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0cb834: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0cb838: 9402EB40  bl       #0x186538
//   0x0cb83c: 54000040  b.eq     #0xcb844
static inline uint64_t fde_func_0309_0x0cb830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb830ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0715b0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0310 | PC: 0x0cb90c | FDE: 0x071618 | Size: 256 bytes
// Khung tháo gỡ #0310 | Địa chỉ PC: 0x0cb90c | Địa chỉ FDE: 0x071618 | Kích thước: 256 bytes
//   0x0cb90c: A9402C43  ldp      x3, x11, [x2]
//   0x0cb910: BD408800  ldr      s0, [x0, #0x88]
//   0x0cb914: BD409C02  ldr      s2, [x0, #0x9c]
//   0x0cb918: F9400022  ldr      x2, [x1]
static inline uint64_t fde_func_0310_0x0cb90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb90cULL ^ (static_cast<uint64_t>(0xa9402c43ULL) << 13);
    acc = (acc + a1 + 0xbd408800ULL) ^ 0x071618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0311 | PC: 0x0cbb98 | FDE: 0x071690 | Size: 256 bytes
// Khung tháo gỡ #0311 | Địa chỉ PC: 0x0cbb98 | Địa chỉ FDE: 0x071690 | Kích thước: 256 bytes
//   0x0cbb98: D10483FF  sub      sp, sp, #0x120
//   0x0cbb9c: FD006BE8  str      d8, [sp, #0xd0]
//   0x0cbba0: F9006FFC  str      x28, [sp, #0xd8]
//   0x0cbba4: A90E63F9  stp      x25, x24, [sp, #0xe0]
static inline uint64_t fde_func_0311_0x0cbb98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbb98ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xfd006be8ULL) ^ 0x071690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0312 | PC: 0x0cbeec | FDE: 0x071708 | Size: 256 bytes
// Khung tháo gỡ #0312 | Địa chỉ PC: 0x0cbeec | Địa chỉ FDE: 0x071708 | Kích thước: 256 bytes
//   0x0cbeec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0cbef0: AA0203E1  mov      x1, x2
//   0x0cbef4: AA0003F3  mov      x19, x0
//   0x0cbef8: 91020000  add      x0, x0, #0x80
static inline uint64_t fde_func_0312_0x0cbeec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbeecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x071708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0313 | PC: 0x0cc214 | FDE: 0x071790 | Size: 256 bytes
// Khung tháo gỡ #0313 | Địa chỉ PC: 0x0cc214 | Địa chỉ FDE: 0x071790 | Kích thước: 256 bytes
//   0x0cc214: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0cc218: D2840888  mov      x8, #0x2044
//   0x0cc21c: F2A89AE8  movk     x8, #0x44d7, lsl #16
//   0x0cc220: F2DAE408  movk     x8, #0xd720, lsl #32
static inline uint64_t fde_func_0313_0x0cc214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc214ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd2840888ULL) ^ 0x071790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0314 | PC: 0x0cc344 | FDE: 0x071808 | Size: 256 bytes
// Khung tháo gỡ #0314 | Địa chỉ PC: 0x0cc344 | Địa chỉ FDE: 0x071808 | Kích thước: 256 bytes
//   0x0cc344: D10583FF  sub      sp, sp, #0x160
//   0x0cc348: F9009BFC  str      x28, [sp, #0x130]
//   0x0cc34c: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0cc350: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0314_0x0cc344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc344ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x071808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0315 | PC: 0x0cc488 | FDE: 0x071878 | Size: 256 bytes
// Khung tháo gỡ #0315 | Địa chỉ PC: 0x0cc488 | Địa chỉ FDE: 0x071878 | Kích thước: 256 bytes
//   0x0cc488: D10183FF  sub      sp, sp, #0x60
//   0x0cc48c: F90023F4  str      x20, [sp, #0x40]
//   0x0cc490: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x0cc494: 9402CC13  bl       #0x17f4e0
static inline uint64_t fde_func_0315_0x0cc488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc488ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x071878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0316 | PC: 0x0ccac4 | FDE: 0x071908 | Size: 256 bytes
// Khung tháo gỡ #0316 | Địa chỉ PC: 0x0ccac4 | Địa chỉ FDE: 0x071908 | Kích thước: 256 bytes
//   0x0ccac4: D10183FF  sub      sp, sp, #0x60
//   0x0ccac8: F90023F4  str      x20, [sp, #0x40]
//   0x0ccacc: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x0ccad0: 9402CA84  bl       #0x17f4e0
static inline uint64_t fde_func_0316_0x0ccac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccac4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x071908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0317 | PC: 0x0ccc1c | FDE: 0x071978 | Size: 256 bytes
// Khung tháo gỡ #0317 | Địa chỉ PC: 0x0ccc1c | Địa chỉ FDE: 0x071978 | Kích thước: 256 bytes
//   0x0ccc1c: D10583FF  sub      sp, sp, #0x160
//   0x0ccc20: F9009BFC  str      x28, [sp, #0x130]
//   0x0ccc24: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ccc28: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0317_0x0ccc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccc1cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x071978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0318 | PC: 0x0ccdd4 | FDE: 0x0719e8 | Size: 256 bytes
// Khung tháo gỡ #0318 | Địa chỉ PC: 0x0ccdd4 | Địa chỉ FDE: 0x0719e8 | Kích thước: 256 bytes
//   0x0ccdd4: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x0ccdd8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ccddc: 1E602008  fcmp     d0, #0.0
//   0x0ccde0: 540001C9  b.ls     #0xcce18
static inline uint64_t fde_func_0318_0x0ccdd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccdd4ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0719e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0319 | PC: 0x0cd0e8 | FDE: 0x071a68 | Size: 160 bytes
// Khung tháo gỡ #0319 | Địa chỉ PC: 0x0cd0e8 | Địa chỉ FDE: 0x071a68 | Kích thước: 160 bytes
//   0x0cd0e8: D0FFFAE8  adrp     x8, #0x2b000
//   0x0cd0ec: FD438D01  ldr      d1, [x8, #0x718]
//   0x0cd0f0: F9401C08  ldr      x8, [x0, #0x38]
//   0x0cd0f4: 1E612000  fcmp     d0, d1
static inline uint64_t fde_func_0319_0x0cd0e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd0e8ULL ^ (static_cast<uint64_t>(0xd0fffae8ULL) << 13);
    acc = (acc + a1 + 0xfd438d01ULL) ^ 0x071a68ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0320 | PC: 0x0cd188 | FDE: 0x071ac8 | Size: 256 bytes
// Khung tháo gỡ #0320 | Địa chỉ PC: 0x0cd188 | Địa chỉ FDE: 0x071ac8 | Kích thước: 256 bytes
//   0x0cd188: D0FFFAE8  adrp     x8, #0x2b000
//   0x0cd18c: FD438D01  ldr      d1, [x8, #0x718]
//   0x0cd190: F9401C08  ldr      x8, [x0, #0x38]
//   0x0cd194: 1E612000  fcmp     d0, d1
static inline uint64_t fde_func_0320_0x0cd188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd188ULL ^ (static_cast<uint64_t>(0xd0fffae8ULL) << 13);
    acc = (acc + a1 + 0xfd438d01ULL) ^ 0x071ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0321 | PC: 0x0cd31c | FDE: 0x071b38 | Size: 212 bytes
// Khung tháo gỡ #0321 | Địa chỉ PC: 0x0cd31c | Địa chỉ FDE: 0x071b38 | Kích thước: 212 bytes
//   0x0cd31c: D10083FF  sub      sp, sp, #0x20
//   0x0cd320: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0cd324: AA0103E8  mov      x8, x1
//   0x0cd328: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0321_0x0cd31c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd31cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x071b38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0322 | PC: 0x0cd3f0 | FDE: 0x071b98 | Size: 256 bytes
// Khung tháo gỡ #0322 | Địa chỉ PC: 0x0cd3f0 | Địa chỉ FDE: 0x071b98 | Kích thước: 256 bytes
//   0x0cd3f0: AA1E03E2  mov      x2, x30
//   0x0cd3f4: 9402A857  bl       #0x177550
//   0x0cd3f8: AA0203FE  mov      x30, x2
//   0x0cd3fc: A9187BF3  stp      x19, x30, [sp, #0x180]
static inline uint64_t fde_func_0322_0x0cd3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd3f0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402a857ULL) ^ 0x071b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0323 | PC: 0x0cd750 | FDE: 0x071c28 | Size: 256 bytes
// Khung tháo gỡ #0323 | Địa chỉ PC: 0x0cd750 | Địa chỉ FDE: 0x071c28 | Kích thước: 256 bytes
//   0x0cd750: D103C3FF  sub      sp, sp, #0xf0
//   0x0cd754: F9006BF4  str      x20, [sp, #0xd0]
//   0x0cd758: A90E7BF3  stp      x19, x30, [sp, #0xe0]
//   0x0cd75c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0323_0x0cd750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd750ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf4ULL) ^ 0x071c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0324 | PC: 0x0cdce0 | FDE: 0x071cb8 | Size: 256 bytes
// Khung tháo gỡ #0324 | Địa chỉ PC: 0x0cdce0 | Địa chỉ FDE: 0x071cb8 | Kích thước: 256 bytes
//   0x0cdce0: D10103FF  sub      sp, sp, #0x40
//   0x0cdce4: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0cdce8: F9400028  ldr      x8, [x1]
//   0x0cdcec: B4000148  cbz      x8, #0xcdd14
static inline uint64_t fde_func_0324_0x0cdce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdce0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x071cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0325 | PC: 0x0cde30 | FDE: 0x071d20 | Size: 256 bytes
// Khung tháo gỡ #0325 | Địa chỉ PC: 0x0cde30 | Địa chỉ FDE: 0x071d20 | Kích thước: 256 bytes
//   0x0cde30: D10403FF  sub      sp, sp, #0x100
//   0x0cde34: 6D0C23E9  stp      d9, d8, [sp, #0xc0]
//   0x0cde38: F9006BF6  str      x22, [sp, #0xd0]
//   0x0cde3c: A90E53F5  stp      x21, x20, [sp, #0xe0]
static inline uint64_t fde_func_0325_0x0cde30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cde30ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0x6d0c23e9ULL) ^ 0x071d20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0326 | PC: 0x0ce138 | FDE: 0x071dc0 | Size: 256 bytes
// Khung tháo gỡ #0326 | Địa chỉ PC: 0x0ce138 | Địa chỉ FDE: 0x071dc0 | Kích thước: 256 bytes
//   0x0ce138: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0ce13c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ce140: 9402BF9D  bl       #0x17dfb4
//   0x0ce144: 94000D8B  bl       #0xd1770
static inline uint64_t fde_func_0326_0x0ce138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce138ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x071dc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0327 | PC: 0x0ce244 | FDE: 0x071e40 | Size: 252 bytes
// Khung tháo gỡ #0327 | Địa chỉ PC: 0x0ce244 | Địa chỉ FDE: 0x071e40 | Kích thước: 252 bytes
//   0x0ce244: 91012001  add      x1, x0, #0x48
//   0x0ce248: 14000C84  b        #0xd1458
//   0x0ce24c: D102C3FF  sub      sp, sp, #0xb0
//   0x0ce250: 6D0823E9  stp      d9, d8, [sp, #0x80]
static inline uint64_t fde_func_0327_0x0ce244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce244ULL ^ (static_cast<uint64_t>(0x91012001ULL) << 13);
    acc = (acc + a1 + 0x14000c84ULL) ^ 0x071e40ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0328 | PC: 0x0ce340 | FDE: 0x071ec0 | Size: 256 bytes
// Khung tháo gỡ #0328 | Địa chỉ PC: 0x0ce340 | Địa chỉ FDE: 0x071ec0 | Kích thước: 256 bytes
//   0x0ce340: D106C3FF  sub      sp, sp, #0x1b0
//   0x0ce344: 6D1533ED  stp      d13, d12, [sp, #0x150]
//   0x0ce348: 6D162BEB  stp      d11, d10, [sp, #0x160]
//   0x0ce34c: 6D1723E9  stp      d9, d8, [sp, #0x170]
static inline uint64_t fde_func_0328_0x0ce340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce340ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0x6d1533edULL) ^ 0x071ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0329 | PC: 0x0ce650 | FDE: 0x071f68 | Size: 256 bytes
// Khung tháo gỡ #0329 | Địa chỉ PC: 0x0ce650 | Địa chỉ FDE: 0x071f68 | Kích thước: 256 bytes
//   0x0ce650: 6DBC2BEB  stp      d11, d10, [sp, #-0x40]!
//   0x0ce654: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x0ce658: F90013F4  str      x20, [sp, #0x20]
//   0x0ce65c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0329_0x0ce650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce650ULL ^ (static_cast<uint64_t>(0x6dbc2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x071f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0330 | PC: 0x0cebdc | FDE: 0x072020 | Size: 256 bytes
// Khung tháo gỡ #0330 | Địa chỉ PC: 0x0cebdc | Địa chỉ FDE: 0x072020 | Kích thước: 256 bytes
//   0x0cebdc: D10783FF  sub      sp, sp, #0x1e0
//   0x0cebe0: FD00CBE8  str      d8, [sp, #0x190]
//   0x0cebe4: F900CFFC  str      x28, [sp, #0x198]
//   0x0cebe8: A91A63F9  stp      x25, x24, [sp, #0x1a0]
static inline uint64_t fde_func_0330_0x0cebdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cebdcULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xfd00cbe8ULL) ^ 0x072020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0331 | PC: 0x0cee50 | FDE: 0x072098 | Size: 256 bytes
// Khung tháo gỡ #0331 | Địa chỉ PC: 0x0cee50 | Địa chỉ FDE: 0x072098 | Kích thước: 256 bytes
//   0x0cee50: AA1E03E1  mov      x1, x30
//   0x0cee54: 9402A643  bl       #0x178760
//   0x0cee58: AA0103FE  mov      x30, x1
//   0x0cee5c: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0331_0x0cee50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cee50ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9402a643ULL) ^ 0x072098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0332 | PC: 0x0cf124 | FDE: 0x072128 | Size: 256 bytes
// Khung tháo gỡ #0332 | Địa chỉ PC: 0x0cf124 | Địa chỉ FDE: 0x072128 | Kích thước: 256 bytes
//   0x0cf124: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0cf128: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0cf12c: AA0103F4  mov      x20, x1
//   0x0cf130: F0FFFAE1  adrp     x1, #0x2e000
static inline uint64_t fde_func_0332_0x0cf124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf124ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0333 | PC: 0x0cf32c | FDE: 0x072198 | Size: 236 bytes
// Khung tháo gỡ #0333 | Địa chỉ PC: 0x0cf32c | Địa chỉ FDE: 0x072198 | Kích thước: 236 bytes
//   0x0cf32c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0cf330: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0cf334: AA0103F4  mov      x20, x1
//   0x0cf338: B0FFFB21  adrp     x1, #0x34000
static inline uint64_t fde_func_0333_0x0cf32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf32cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072198ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0334 | PC: 0x0cf418 | FDE: 0x072200 | Size: 256 bytes
// Khung tháo gỡ #0334 | Địa chỉ PC: 0x0cf418 | Địa chỉ FDE: 0x072200 | Kích thước: 256 bytes
//   0x0cf418: D10083FF  sub      sp, sp, #0x20
//   0x0cf41c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0cf420: 9402C660  bl       #0x180da0
//   0x0cf424: 940004B9  bl       #0xd0708
static inline uint64_t fde_func_0334_0x0cf418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf418ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0335 | PC: 0x0cf740 | FDE: 0x072288 | Size: 256 bytes
// Khung tháo gỡ #0335 | Địa chỉ PC: 0x0cf740 | Địa chỉ FDE: 0x072288 | Kích thước: 256 bytes
//   0x0cf740: D10143FF  sub      sp, sp, #0x50
//   0x0cf744: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x0cf748: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0cf74c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0335_0x0cf740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf740ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0223e9ULL) ^ 0x072288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0336 | PC: 0x0cff3c | FDE: 0x072350 | Size: 256 bytes
// Khung tháo gỡ #0336 | Địa chỉ PC: 0x0cff3c | Địa chỉ FDE: 0x072350 | Kích thước: 256 bytes
//   0x0cff3c: D10283FF  sub      sp, sp, #0xa0
//   0x0cff40: 6D0723E9  stp      d9, d8, [sp, #0x70]
//   0x0cff44: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x0cff48: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0336_0x0cff3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cff3cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0x6d0723e9ULL) ^ 0x072350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0337 | PC: 0x0d0258 | FDE: 0x0723e8 | Size: 132 bytes
// Khung tháo gỡ #0337 | Địa chỉ PC: 0x0d0258 | Địa chỉ FDE: 0x0723e8 | Kích thước: 132 bytes
//   0x0d0258: D10583FF  sub      sp, sp, #0x160
//   0x0d025c: F9009BFC  str      x28, [sp, #0x130]
//   0x0d0260: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0d0264: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0337_0x0d0258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0258ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x0723e8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0338 | PC: 0x0d02dc | FDE: 0x072450 | Size: 256 bytes
// Khung tháo gỡ #0338 | Địa chỉ PC: 0x0d02dc | Địa chỉ FDE: 0x072450 | Kích thước: 256 bytes
//   0x0d02dc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0d02e0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d02e4: F9400415  ldr      x21, [x0, #8]
//   0x0d02e8: 94029643  bl       #0x175bf4
static inline uint64_t fde_func_0338_0x0d02dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d02dcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0339 | PC: 0x0d051c | FDE: 0x0724c0 | Size: 256 bytes
// Khung tháo gỡ #0339 | Địa chỉ PC: 0x0d051c | Địa chỉ FDE: 0x0724c0 | Kích thước: 256 bytes
//   0x0d051c: 1E200802  fmul     s2, s0, s0
//   0x0d0520: 1E210823  fmul     s3, s1, s1
//   0x0d0524: 52A73008  mov      w8, #0x39800000
//   0x0d0528: 1E232844  fadd     s4, s2, s3
static inline uint64_t fde_func_0339_0x0d051c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d051cULL ^ (static_cast<uint64_t>(0x1e200802ULL) << 13);
    acc = (acc + a1 + 0x1e210823ULL) ^ 0x0724c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0340 | PC: 0x0d06b0 | FDE: 0x072520 | Size: 256 bytes
// Khung tháo gỡ #0340 | Địa chỉ PC: 0x0d06b0 | Địa chỉ FDE: 0x072520 | Kích thước: 256 bytes
//   0x0d06b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d06b4: F9400008  ldr      x8, [x0]
//   0x0d06b8: B40000C8  cbz      x8, #0xd06d0
//   0x0d06bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0340_0x0d06b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d06b0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x072520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0341 | PC: 0x0d0c48 | FDE: 0x0725b0 | Size: 104 bytes
// Khung tháo gỡ #0341 | Địa chỉ PC: 0x0d0c48 | Địa chỉ FDE: 0x0725b0 | Kích thước: 104 bytes
//   0x0d0c48: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d0c4c: A949CC00  ldp      x0, x19, [x0, #0x98]
//   0x0d0c50: B4000093  cbz      x19, #0xd0c60
//   0x0d0c54: 91002268  add      x8, x19, #8
static inline uint64_t fde_func_0341_0x0d0c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0c48ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xa949cc00ULL) ^ 0x0725b0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0342 | PC: 0x0d0cb0 | FDE: 0x072610 | Size: 256 bytes
// Khung tháo gỡ #0342 | Địa chỉ PC: 0x0d0cb0 | Địa chỉ FDE: 0x072610 | Kích thước: 256 bytes
//   0x0d0cb0: D10603FF  sub      sp, sp, #0x180
//   0x0d0cb4: 6D132BEB  stp      d11, d10, [sp, #0x130]
//   0x0d0cb8: 6D1423E9  stp      d9, d8, [sp, #0x140]
//   0x0d0cbc: A9155BFC  stp      x28, x22, [sp, #0x150]
static inline uint64_t fde_func_0342_0x0d0cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0cb0ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0x6d132bebULL) ^ 0x072610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0343 | PC: 0x0d1064 | FDE: 0x072688 | Size: 256 bytes
// Khung tháo gỡ #0343 | Địa chỉ PC: 0x0d1064 | Địa chỉ FDE: 0x072688 | Kích thước: 256 bytes
//   0x0d1064: D10383FF  sub      sp, sp, #0xe0
//   0x0d1068: A90B5BF7  stp      x23, x22, [sp, #0xb0]
//   0x0d106c: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x0d1070: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_0343_0x0d1064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1064ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b5bf7ULL) ^ 0x072688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0344 | PC: 0x0d1458 | FDE: 0x072720 | Size: 256 bytes
// Khung tháo gỡ #0344 | Địa chỉ PC: 0x0d1458 | Địa chỉ FDE: 0x072720 | Kích thước: 256 bytes
//   0x0d1458: D10783FF  sub      sp, sp, #0x1e0
//   0x0d145c: 6D1A23E9  stp      d9, d8, [sp, #0x1a0]
//   0x0d1460: F900DBFC  str      x28, [sp, #0x1b0]
//   0x0d1464: A91C53F5  stp      x21, x20, [sp, #0x1c0]
static inline uint64_t fde_func_0344_0x0d1458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1458ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0x6d1a23e9ULL) ^ 0x072720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0345 | PC: 0x0d16f8 | FDE: 0x0727a8 | Size: 256 bytes
// Khung tháo gỡ #0345 | Địa chỉ PC: 0x0d16f8 | Địa chỉ FDE: 0x0727a8 | Kích thước: 256 bytes
//   0x0d16f8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d16fc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d1700: D37CFC28  lsr      x8, x1, #0x3c
//   0x0d1704: B50000E8  cbnz     x8, #0xd1720
static inline uint64_t fde_func_0345_0x0d16f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d16f8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0727a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0346 | PC: 0x0d1884 | FDE: 0x072820 | Size: 256 bytes
// Khung tháo gỡ #0346 | Địa chỉ PC: 0x0d1884 | Địa chỉ FDE: 0x072820 | Kích thước: 256 bytes
//   0x0d1884: D10083FF  sub      sp, sp, #0x20
//   0x0d1888: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d188c: AA0103F3  mov      x19, x1
//   0x0d1890: 52A7F008  mov      w8, #0x3f800000
static inline uint64_t fde_func_0346_0x0d1884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1884ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0347 | PC: 0x0d1a44 | FDE: 0x072888 | Size: 256 bytes
// Khung tháo gỡ #0347 | Địa chỉ PC: 0x0d1a44 | Địa chỉ FDE: 0x072888 | Kích thước: 256 bytes
//   0x0d1a44: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0d1a48: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0d1a4c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0d1a50: 9402D567  bl       #0x186fec
static inline uint64_t fde_func_0347_0x0d1a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1a44ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x072888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0348 | PC: 0x0d1c48 | FDE: 0x072900 | Size: 256 bytes
// Khung tháo gỡ #0348 | Địa chỉ PC: 0x0d1c48 | Địa chỉ FDE: 0x072900 | Kích thước: 256 bytes
//   0x0d1c48: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0d1c4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d1c50: AA0003F3  mov      x19, x0
//   0x0d1c54: 910E4000  add      x0, x0, #0x390
static inline uint64_t fde_func_0348_0x0d1c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1c48ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0349 | PC: 0x0d1f50 | FDE: 0x072978 | Size: 256 bytes
// Khung tháo gỡ #0349 | Địa chỉ PC: 0x0d1f50 | Địa chỉ FDE: 0x072978 | Kích thước: 256 bytes
//   0x0d1f50: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d1f54: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d1f58: AA0003F3  mov      x19, x0
//   0x0d1f5c: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0349_0x0d1f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1f50ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0350 | PC: 0x0d2198 | FDE: 0x0729e8 | Size: 256 bytes
// Khung tháo gỡ #0350 | Địa chỉ PC: 0x0d2198 | Địa chỉ FDE: 0x0729e8 | Kích thước: 256 bytes
//   0x0d2198: D10243FF  sub      sp, sp, #0x90
//   0x0d219c: 6D032BEB  stp      d11, d10, [sp, #0x30]
//   0x0d21a0: 6D0423E9  stp      d9, d8, [sp, #0x40]
//   0x0d21a4: F9002BF8  str      x24, [sp, #0x50]
static inline uint64_t fde_func_0350_0x0d2198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2198ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0x6d032bebULL) ^ 0x0729e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0351 | PC: 0x0d24a8 | FDE: 0x072a70 | Size: 236 bytes
// Khung tháo gỡ #0351 | Địa chỉ PC: 0x0d24a8 | Địa chỉ FDE: 0x072a70 | Kích thước: 236 bytes
//   0x0d24a8: AA1F03E1  mov      x1, xzr
//   0x0d24ac: 17FFFFF5  b        #0xd2480
//   0x0d24b0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d24b4: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0351_0x0d24a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d24a8ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fffff5ULL) ^ 0x072a70ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0352 | PC: 0x0d2594 | FDE: 0x072ae8 | Size: 256 bytes
// Khung tháo gỡ #0352 | Địa chỉ PC: 0x0d2594 | Địa chỉ FDE: 0x072ae8 | Kích thước: 256 bytes
//   0x0d2594: D10103FF  sub      sp, sp, #0x40
//   0x0d2598: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0d259c: F9403C0B  ldr      x11, [x0, #0x78]
//   0x0d25a0: F9411C0D  ldr      x13, [x0, #0x238]
static inline uint64_t fde_func_0352_0x0d2594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2594ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x072ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0353 | PC: 0x0d299c | FDE: 0x072b70 | Size: 216 bytes
// Khung tháo gỡ #0353 | Địa chỉ PC: 0x0d299c | Địa chỉ FDE: 0x072b70 | Kích thước: 216 bytes
//   0x0d299c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d29a0: AA0003F3  mov      x19, x0
//   0x0d29a4: 91090000  add      x0, x0, #0x240
//   0x0d29a8: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_0353_0x0d299c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d299cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x072b70ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0354 | PC: 0x0d2a74 | FDE: 0x072bd8 | Size: 136 bytes
// Khung tháo gỡ #0354 | Địa chỉ PC: 0x0d2a74 | Địa chỉ FDE: 0x072bd8 | Kích thước: 136 bytes
//   0x0d2a74: F9400408  ldr      x8, [x0, #8]
//   0x0d2a78: 900005E9  adrp     x9, #0x18e000
//   0x0d2a7c: 91184129  add      x9, x9, #0x610
//   0x0d2a80: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0354_0x0d2a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2a74ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x900005e9ULL) ^ 0x072bd8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0355 | PC: 0x0d2afc | FDE: 0x072c38 | Size: 120 bytes
// Khung tháo gỡ #0355 | Địa chỉ PC: 0x0d2afc | Địa chỉ FDE: 0x072c38 | Kích thước: 120 bytes
//   0x0d2afc: F9400400  ldr      x0, [x0, #8]
//   0x0d2b00: 17FFFFD0  b        #0xd2a40
//   0x0d2b04: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d2b08: 940295B2  bl       #0x1781d0
static inline uint64_t fde_func_0355_0x0d2afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2afcULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffffd0ULL) ^ 0x072c38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0356 | PC: 0x0d2b74 | FDE: 0x072c98 | Size: 256 bytes
// Khung tháo gỡ #0356 | Địa chỉ PC: 0x0d2b74 | Địa chỉ FDE: 0x072c98 | Kích thước: 256 bytes
//   0x0d2b74: B900001F  str      wzr, [x0]
//   0x0d2b78: 2D008400  stp      s0, s1, [x0, #4]
//   0x0d2b7c: 2D018C02  stp      s2, s3, [x0, #0xc]
//   0x0d2b80: A9027C1F  stp      xzr, xzr, [x0, #0x20]
static inline uint64_t fde_func_0356_0x0d2b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2b74ULL ^ (static_cast<uint64_t>(0xb900001fULL) << 13);
    acc = (acc + a1 + 0x2d008400ULL) ^ 0x072c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0357 | PC: 0x0d2cc0 | FDE: 0x072d00 | Size: 256 bytes
// Khung tháo gỡ #0357 | Địa chỉ PC: 0x0d2cc0 | Địa chỉ FDE: 0x072d00 | Kích thước: 256 bytes
//   0x0d2cc0: D10083FF  sub      sp, sp, #0x20
//   0x0d2cc4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d2cc8: AA0003F3  mov      x19, x0
//   0x0d2ccc: EB00003F  cmp      x1, x0
static inline uint64_t fde_func_0357_0x0d2cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2cc0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0358 | PC: 0x0d2f30 | FDE: 0x072d90 | Size: 256 bytes
// Khung tháo gỡ #0358 | Địa chỉ PC: 0x0d2f30 | Địa chỉ FDE: 0x072d90 | Kích thước: 256 bytes
//   0x0d2f30: AA1E03E0  mov      x0, x30
//   0x0d2f34: 94028BC5  bl       #0x175e48
//   0x0d2f38: AA0003FE  mov      x30, x0
//   0x0d2f3c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0358_0x0d2f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2f30ULL ^ (static_cast<uint64_t>(0xaa1e03e0ULL) << 13);
    acc = (acc + a1 + 0x94028bc5ULL) ^ 0x072d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0359 | PC: 0x0d3524 | FDE: 0x072e20 | Size: 256 bytes
// Khung tháo gỡ #0359 | Địa chỉ PC: 0x0d3524 | Địa chỉ FDE: 0x072e20 | Kích thước: 256 bytes
//   0x0d3524: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d3528: A9432408  ldp      x8, x9, [x0, #0x30]
//   0x0d352c: EB08013F  cmp      x9, x8
//   0x0d3530: 54000060  b.eq     #0xd353c
static inline uint64_t fde_func_0359_0x0d3524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3524ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9432408ULL) ^ 0x072e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0360 | PC: 0x0d37d0 | FDE: 0x072e98 | Size: 256 bytes
// Khung tháo gỡ #0360 | Địa chỉ PC: 0x0d37d0 | Địa chỉ FDE: 0x072e98 | Kích thước: 256 bytes
//   0x0d37d0: 6DBC33ED  stp      d13, d12, [sp, #-0x40]!
//   0x0d37d4: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x0d37d8: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x0d37dc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0360_0x0d37d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d37d0ULL ^ (static_cast<uint64_t>(0x6dbc33edULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x072e98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0361 | PC: 0x0d455c | FDE: 0x072f68 | Size: 256 bytes
// Khung tháo gỡ #0361 | Địa chỉ PC: 0x0d455c | Địa chỉ FDE: 0x072f68 | Kích thước: 256 bytes
//   0x0d455c: D100C3FF  sub      sp, sp, #0x30
//   0x0d4560: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0d4564: F0FFFAA8  adrp     x8, #0x2b000
//   0x0d4568: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0361_0x0d455c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d455cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x072f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0362 | PC: 0x0d47fc | FDE: 0x072fd0 | Size: 220 bytes
// Khung tháo gỡ #0362 | Địa chỉ PC: 0x0d47fc | Địa chỉ FDE: 0x072fd0 | Kích thước: 220 bytes
//   0x0d47fc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d4800: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d4804: AA0203F3  mov      x19, x2
//   0x0d4808: EB000022  subs     x2, x1, x0
static inline uint64_t fde_func_0362_0x0d47fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d47fcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x072fd0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0363 | PC: 0x0d48d8 | FDE: 0x073040 | Size: 256 bytes
// Khung tháo gỡ #0363 | Địa chỉ PC: 0x0d48d8 | Địa chỉ FDE: 0x073040 | Kích thước: 256 bytes
//   0x0d48d8: D106C3FF  sub      sp, sp, #0x1b0
//   0x0d48dc: AA1E03E6  mov      x6, x30
//   0x0d48e0: 940299C9  bl       #0x17b004
//   0x0d48e4: AA0603FE  mov      x30, x6
static inline uint64_t fde_func_0363_0x0d48d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d48d8ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e6ULL) ^ 0x073040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0364 | PC: 0x0d4b30 | FDE: 0x0730b8 | Size: 256 bytes
// Khung tháo gỡ #0364 | Địa chỉ PC: 0x0d4b30 | Địa chỉ FDE: 0x0730b8 | Kích thước: 256 bytes
//   0x0d4b30: F9400409  ldr      x9, [x0, #8]
//   0x0d4b34: 5280030A  mov      w10, #0x18
//   0x0d4b38: AA0803E0  mov      x0, x8
//   0x0d4b3c: F9401529  ldr      x9, [x9, #0x28]
static inline uint64_t fde_func_0364_0x0d4b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4b30ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x5280030aULL) ^ 0x0730b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0365 | PC: 0x0d4c84 | FDE: 0x073130 | Size: 256 bytes
// Khung tháo gỡ #0365 | Địa chỉ PC: 0x0d4c84 | Địa chỉ FDE: 0x073130 | Kích thước: 256 bytes
//   0x0d4c84: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d4c88: 9402A4D2  bl       #0x17dfd0
//   0x0d4c8c: 97FF5A22  bl       #0xab514
//   0x0d4c90: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0365_0x0d4c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4c84ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402a4d2ULL) ^ 0x073130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0366 | PC: 0x0d4e60 | FDE: 0x0731b0 | Size: 256 bytes
// Khung tháo gỡ #0366 | Địa chỉ PC: 0x0d4e60 | Địa chỉ FDE: 0x0731b0 | Kích thước: 256 bytes
//   0x0d4e60: 39400008  ldrb     w8, [x0]
//   0x0d4e64: A940A40A  ldp      x10, x9, [x0, #8]
//   0x0d4e68: AA1E03E1  mov      x1, x30
//   0x0d4e6c: 9402AF5B  bl       #0x180bd8
static inline uint64_t fde_func_0366_0x0d4e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4e60ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0xa940a40aULL) ^ 0x0731b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0367 | PC: 0x0d5244 | FDE: 0x073228 | Size: 256 bytes
// Khung tháo gỡ #0367 | Địa chỉ PC: 0x0d5244 | Địa chỉ FDE: 0x073228 | Kích thước: 256 bytes
//   0x0d5244: D10183FF  sub      sp, sp, #0x60
//   0x0d5248: F9001BF6  str      x22, [sp, #0x30]
//   0x0d524c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0d5250: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0367_0x0d5244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5244ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x073228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0368 | PC: 0x0d5418 | FDE: 0x0732b0 | Size: 256 bytes
// Khung tháo gỡ #0368 | Địa chỉ PC: 0x0d5418 | Địa chỉ FDE: 0x0732b0 | Kích thước: 256 bytes
//   0x0d5418: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d541c: AA0003F3  mov      x19, x0
//   0x0d5420: 97FFFFE9  bl       #0xd53c4
//   0x0d5424: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0368_0x0d5418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5418ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0732b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0369 | PC: 0x0d5570 | FDE: 0x073320 | Size: 156 bytes
// Khung tháo gỡ #0369 | Địa chỉ PC: 0x0d5570 | Địa chỉ FDE: 0x073320 | Kích thước: 156 bytes
//   0x0d5570: 1402CBC8  b        #0x188490
//   0x0d5574: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d5578: B00005C8  adrp     x8, #0x18e000
//   0x0d557c: 911EA108  add      x8, x8, #0x7a8
static inline uint64_t fde_func_0369_0x0d5570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5570ULL ^ (static_cast<uint64_t>(0x1402cbc8ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x073320ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0370 | PC: 0x0d560c | FDE: 0x073380 | Size: 256 bytes
// Khung tháo gỡ #0370 | Địa chỉ PC: 0x0d560c | Địa chỉ FDE: 0x073380 | Kích thước: 256 bytes
//   0x0d560c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d5610: 94029027  bl       #0x1796ac
//   0x0d5614: B4000048  cbz      x8, #0xd561c
//   0x0d5618: 9402C413  bl       #0x186664
static inline uint64_t fde_func_0370_0x0d560c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d560cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94029027ULL) ^ 0x073380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0371 | PC: 0x0d5acc | FDE: 0x073408 | Size: 256 bytes
// Khung tháo gỡ #0371 | Địa chỉ PC: 0x0d5acc | Địa chỉ FDE: 0x073408 | Kích thước: 256 bytes
//   0x0d5acc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d5ad0: AA0003F3  mov      x19, x0
//   0x0d5ad4: 97FFFFE9  bl       #0xd5a78
//   0x0d5ad8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0371_0x0d5acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5accULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x073408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0372 | PC: 0x0d65ec | FDE: 0x0734a0 | Size: 256 bytes
// Khung tháo gỡ #0372 | Địa chỉ PC: 0x0d65ec | Địa chỉ FDE: 0x0734a0 | Kích thước: 256 bytes
//   0x0d65ec: D10183FF  sub      sp, sp, #0x60
//   0x0d65f0: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0d65f4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0d65f8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0372_0x0d65ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d65ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0734a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0373 | PC: 0x0d6770 | FDE: 0x073520 | Size: 256 bytes
// Khung tháo gỡ #0373 | Địa chỉ PC: 0x0d6770 | Địa chỉ FDE: 0x073520 | Kích thước: 256 bytes
//   0x0d6770: D28C4EE8  mov      x8, #0x6277
//   0x0d6774: F2AEC4E8  movk     x8, #0x7627, lsl #16
//   0x0d6778: F2C4EC48  movk     x8, #0x2762, lsl #32
//   0x0d677c: F2E04EC8  movk     x8, #0x276, lsl #48
static inline uint64_t fde_func_0373_0x0d6770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6770ULL ^ (static_cast<uint64_t>(0xd28c4ee8ULL) << 13);
    acc = (acc + a1 + 0xf2aec4e8ULL) ^ 0x073520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0374 | PC: 0x0d68a8 | FDE: 0x073598 | Size: 256 bytes
// Khung tháo gỡ #0374 | Địa chỉ PC: 0x0d68a8 | Địa chỉ FDE: 0x073598 | Kích thước: 256 bytes
//   0x0d68a8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0d68ac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0d68b0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0d68b4: A9405416  ldp      x22, x21, [x0]
static inline uint64_t fde_func_0374_0x0d68a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d68a8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x073598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0375 | PC: 0x0d6a68 | FDE: 0x073628 | Size: 256 bytes
// Khung tháo gỡ #0375 | Địa chỉ PC: 0x0d6a68 | Địa chỉ FDE: 0x073628 | Kích thước: 256 bytes
//   0x0d6a68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d6a6c: 900005C8  adrp     x8, #0x18e000
//   0x0d6a70: 91214108  add      x8, x8, #0x850
//   0x0d6a74: 940288B3  bl       #0x178d40
static inline uint64_t fde_func_0375_0x0d6a68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6a68ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900005c8ULL) ^ 0x073628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0376 | PC: 0x0d6cfc | FDE: 0x0736a0 | Size: 256 bytes
// Khung tháo gỡ #0376 | Địa chỉ PC: 0x0d6cfc | Địa chỉ FDE: 0x0736a0 | Kích thước: 256 bytes
//   0x0d6cfc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d6d00: AA0003F3  mov      x19, x0
//   0x0d6d04: 97FFFF69  bl       #0xd6aa8
//   0x0d6d08: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0376_0x0d6cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6cfcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0736a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0377 | PC: 0x0d7270 | FDE: 0x073720 | Size: 256 bytes
// Khung tháo gỡ #0377 | Địa chỉ PC: 0x0d7270 | Địa chỉ FDE: 0x073720 | Kích thước: 256 bytes
//   0x0d7270: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d7274: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d7278: B9402408  ldr      w8, [x0, #0x24]
//   0x0d727c: B9402429  ldr      w9, [x1, #0x24]
static inline uint64_t fde_func_0377_0x0d7270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7270ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x073720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0378 | PC: 0x0d7458 | FDE: 0x0737a0 | Size: 256 bytes
// Khung tháo gỡ #0378 | Địa chỉ PC: 0x0d7458 | Địa chỉ FDE: 0x0737a0 | Kích thước: 256 bytes
//   0x0d7458: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d745c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d7460: 9402819A  bl       #0x177ac8
//   0x0d7464: B4000153  cbz      x19, #0xd748c
static inline uint64_t fde_func_0378_0x0d7458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7458ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0737a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0379 | PC: 0x0d76ec | FDE: 0x073830 | Size: 256 bytes
// Khung tháo gỡ #0379 | Địa chỉ PC: 0x0d76ec | Địa chỉ FDE: 0x073830 | Kích thước: 256 bytes
//   0x0d76ec: 91002008  add      x8, x0, #8
//   0x0d76f0: 52800020  mov      w0, #1
//   0x0d76f4: F9400108  ldr      x8, [x8]
//   0x0d76f8: B40000E8  cbz      x8, #0xd7714
static inline uint64_t fde_func_0379_0x0d76ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d76ecULL ^ (static_cast<uint64_t>(0x91002008ULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x073830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0380 | PC: 0x0d7e6c | FDE: 0x073878 | Size: 256 bytes
// Khung tháo gỡ #0380 | Địa chỉ PC: 0x0d7e6c | Địa chỉ FDE: 0x073878 | Kích thước: 256 bytes
//   0x0d7e6c: 17FF4A6C  b        #0xaa81c
//   0x0d7e70: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0d7e74: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d7e78: F9400814  ldr      x20, [x0, #0x10]
static inline uint64_t fde_func_0380_0x0d7e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7e6cULL ^ (static_cast<uint64_t>(0x17ff4a6cULL) << 13);
    acc = (acc + a1 + 0xa9be53f5ULL) ^ 0x073878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0381 | PC: 0x0d8010 | FDE: 0x0738f8 | Size: 256 bytes
// Khung tháo gỡ #0381 | Địa chỉ PC: 0x0d8010 | Địa chỉ FDE: 0x0738f8 | Kích thước: 256 bytes
//   0x0d8010: AA1E03E3  mov      x3, x30
//   0x0d8014: 94027C65  bl       #0x1771a8
//   0x0d8018: AA0303FE  mov      x30, x3
//   0x0d801c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0381_0x0d8010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8010ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94027c65ULL) ^ 0x0738f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0382 | PC: 0x0d82c8 | FDE: 0x073970 | Size: 256 bytes
// Khung tháo gỡ #0382 | Địa chỉ PC: 0x0d82c8 | Địa chỉ FDE: 0x073970 | Kích thước: 256 bytes
//   0x0d82c8: AA1E03E2  mov      x2, x30
//   0x0d82cc: 94028ADA  bl       #0x17ae34
//   0x0d82d0: AA0203FE  mov      x30, x2
//   0x0d82d4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0382_0x0d82c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d82c8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94028adaULL) ^ 0x073970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0383 | PC: 0x0d84c0 | FDE: 0x0739f8 | Size: 192 bytes
// Khung tháo gỡ #0383 | Địa chỉ PC: 0x0d84c0 | Địa chỉ FDE: 0x0739f8 | Kích thước: 192 bytes
//   0x0d84c0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0d84c4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d84c8: AA0003F4  mov      x20, x0
//   0x0d84cc: 52800500  mov      w0, #0x28
static inline uint64_t fde_func_0383_0x0d84c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d84c0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0739f8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0384 | PC: 0x0d8580 | FDE: 0x073a70 | Size: 232 bytes
// Khung tháo gỡ #0384 | Địa chỉ PC: 0x0d8580 | Địa chỉ FDE: 0x073a70 | Kích thước: 232 bytes
//   0x0d8580: D10583FF  sub      sp, sp, #0x160
//   0x0d8584: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0d8588: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0d858c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0384_0x0d8580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8580ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x073a70ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0385 | PC: 0x0d8668 | FDE: 0x073ab8 | Size: 32 bytes [_ZN4lynx6canvas18CanvasRenderbufferD0Ev]
// Khung tháo gỡ #0385 | Địa chỉ PC: 0x0d8668 | Địa chỉ FDE: 0x073ab8 | Kích thước: 32 bytes
//   0x0d8668: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d866c: AA0003F3  mov      x19, x0
//   0x0d8670: 9402BFBC  bl       #0x188560
//   0x0d8674: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0385_0x0d8668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8668ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x073ab8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0386 | PC: 0x0d8688 | FDE: 0x073ae8 | Size: 84 bytes [_ZN4lynx6canvas18CanvasRenderbufferC1ERKNS0_19DrawingBufferOptionE]
// Khung tháo gỡ #0386 | Địa chỉ PC: 0x0d8688 | Địa chỉ FDE: 0x073ae8 | Kích thước: 84 bytes
//   0x0d8688: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d868c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d8690: B00005E8  adrp     x8, #0x195000
//   0x0d8694: F9410508  ldr      x8, [x8, #0x208]
static inline uint64_t fde_func_0386_0x0d8688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8688ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x073ae8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0387 | PC: 0x0d86dc | FDE: 0x073b08 | Size: 20 bytes [_ZN4lynx6canvas18CanvasRenderbufferD1Ev]
// Khung tháo gỡ #0387 | Địa chỉ PC: 0x0d86dc | Địa chỉ FDE: 0x073b08 | Kích thước: 20 bytes
//   0x0d86dc: B00005E8  adrp     x8, #0x195000
//   0x0d86e0: F9410508  ldr      x8, [x8, #0x208]
//   0x0d86e4: 91004108  add      x8, x8, #0x10
//   0x0d86e8: F8030408  str      x8, [x0], #0x30
static inline uint64_t fde_func_0387_0x0d86dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d86dcULL ^ (static_cast<uint64_t>(0xb00005e8ULL) << 13);
    acc = (acc + a1 + 0xf9410508ULL) ^ 0x073b08ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0388 | PC: 0x0d86f0 | FDE: 0x073b20 | Size: 256 bytes [_ZN4lynx6canvas18CanvasRenderbuffer7DisposeEv]
// Khung tháo gỡ #0388 | Địa chỉ PC: 0x0d86f0 | Địa chỉ FDE: 0x073b20 | Kích thước: 256 bytes
//   0x0d86f0: D10583FF  sub      sp, sp, #0x160
//   0x0d86f4: F9009BFC  str      x28, [sp, #0x130]
//   0x0d86f8: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0d86fc: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0388_0x0d86f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d86f0ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x073b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0389 | PC: 0x0d8860 | FDE: 0x073b58 | Size: 256 bytes
// Khung tháo gỡ #0389 | Địa chỉ PC: 0x0d8860 | Địa chỉ FDE: 0x073b58 | Kích thước: 256 bytes
//   0x0d8860: AA1E03E1  mov      x1, x30
//   0x0d8864: 94027826  bl       #0x1768fc
//   0x0d8868: AA0103FE  mov      x30, x1
//   0x0d886c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0389_0x0d8860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8860ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94027826ULL) ^ 0x073b58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0390 | PC: 0x0d89d8 | FDE: 0x073ba0 | Size: 256 bytes [_ZN4lynx6canvas18CanvasRenderbuffer5BuildEiii]
// Khung tháo gỡ #0390 | Địa chỉ PC: 0x0d89d8 | Địa chỉ FDE: 0x073ba0 | Kích thước: 256 bytes
//   0x0d89d8: AA1E03E4  mov      x4, x30
//   0x0d89dc: 94028BEE  bl       #0x17b994
//   0x0d89e0: AA0403FE  mov      x30, x4
//   0x0d89e4: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0390_0x0d89d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d89d8ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94028beeULL) ^ 0x073ba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0391 | PC: 0x0d8b10 | FDE: 0x073bc8 | Size: 256 bytes [_ZN4lynx6canvas18CanvasRenderbuffer20BuildMSAAFramebufferENS1_8MSAAModeEiii]
// Khung tháo gỡ #0391 | Địa chỉ PC: 0x0d8b10 | Địa chỉ FDE: 0x073bc8 | Kích thước: 256 bytes
//   0x0d8b10: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0d8b14: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0d8b18: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d8b1c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0391_0x0d8b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8b10ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x073bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0392 | PC: 0x0d8c1c | FDE: 0x073bf0 | Size: 256 bytes [_ZN4lynx6canvas18CanvasRenderbuffer22BuildNoMSAAFramebufferEii]
// Khung tháo gỡ #0392 | Địa chỉ PC: 0x0d8c1c | Địa chỉ FDE: 0x073bf0 | Kích thước: 256 bytes
//   0x0d8c1c: AA1E03E3  mov      x3, x30
//   0x0d8c20: 94029895  bl       #0x17ee74
//   0x0d8c24: AA0303FE  mov      x30, x3
//   0x0d8c28: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0392_0x0d8c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8c1cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94029895ULL) ^ 0x073bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0393 | PC: 0x0d8d54 | FDE: 0x073c18 | Size: 256 bytes [_ZN4lynx6canvas18CanvasRenderbuffer23BuildDepthStencilBufferERjS2_S2_NS1_8MSAAModeEiii]
// Khung tháo gỡ #0393 | Địa chỉ PC: 0x0d8d54 | Địa chỉ FDE: 0x073c18 | Kích thước: 256 bytes
//   0x0d8d54: AA1E03E8  mov      x8, x30
//   0x0d8d58: 9402AA59  bl       #0x1836bc
//   0x0d8d5c: AA0803FE  mov      x30, x8
//   0x0d8d60: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0393_0x0d8d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8d54ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9402aa59ULL) ^ 0x073c18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0394 | PC: 0x0d8f24 | FDE: 0x073c48 | Size: 160 bytes [_ZN4lynx6canvas18CanvasRenderbuffer11ClearIfNeedEv]
// Khung tháo gỡ #0394 | Địa chỉ PC: 0x0d8f24 | Địa chỉ FDE: 0x073c48 | Kích thước: 160 bytes
//   0x0d8f24: D10303FF  sub      sp, sp, #0xc0
//   0x0d8f28: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x0d8f2c: A90B7BF3  stp      x19, x30, [sp, #0xb0]
//   0x0d8f30: 9402767C  bl       #0x176920
static inline uint64_t fde_func_0394_0x0d8f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8f24ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90a53f5ULL) ^ 0x073c48ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0395 | PC: 0x0d8fc4 | FDE: 0x073c68 | Size: 116 bytes [_ZN4lynx6canvas18CanvasRenderbuffer15ResolveIfNeededEv]
// Khung tháo gỡ #0395 | Địa chỉ PC: 0x0d8fc4 | Địa chỉ FDE: 0x073c68 | Kích thước: 116 bytes
//   0x0d8fc4: D10143FF  sub      sp, sp, #0x50
//   0x0d8fc8: F9001BF4  str      x20, [sp, #0x30]
//   0x0d8fcc: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0d8fd0: 94028F8A  bl       #0x17cdf8
static inline uint64_t fde_func_0395_0x0d8fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8fc4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x073c68ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0396 | PC: 0x0d9038 | FDE: 0x073c88 | Size: 28 bytes [_ZNK4lynx6canvas18CanvasRenderbuffer11drawing_fboEv]
// Khung tháo gỡ #0396 | Địa chỉ PC: 0x0d9038 | Địa chỉ FDE: 0x073c88 | Kích thước: 28 bytes
//   0x0d9038: B9424808  ldr      w8, [x0, #0x248]
//   0x0d903c: 52804B89  mov      w9, #0x25c
//   0x0d9040: 7100011F  cmp      w8, #0
//   0x0d9044: 52800208  mov      w8, #0x10
static inline uint64_t fde_func_0396_0x0d9038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9038ULL ^ (static_cast<uint64_t>(0xb9424808ULL) << 13);
    acc = (acc + a1 + 0x52804b89ULL) ^ 0x073c88ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0397 | PC: 0x0d9054 | FDE: 0x073ca0 | Size: 8 bytes [_ZNK4lynx6canvas18CanvasRenderbuffer9color_texEv]
// Khung tháo gỡ #0397 | Địa chỉ PC: 0x0d9054 | Địa chỉ FDE: 0x073ca0 | Kích thước: 8 bytes
//   0x0d9054: B9424C00  ldr      w0, [x0, #0x24c]
//   0x0d9058: D65F03C0  ret      
static inline uint64_t fde_func_0397_0x0d9054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9054ULL ^ (static_cast<uint64_t>(0xb9424c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x073ca0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0398 | PC: 0x0d905c | FDE: 0x073cb8 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProviderC2EPNS0_13CanvasElementENSt6__ndk110shared_ptrINS0_12KryptonActorINS0_14KryptonRuntimeEEEEENS5_INS_5shell9LynxActorINS0_15SurfaceRegistryEEEEENS1_6OptionE]
// Khung tháo gỡ #0398 | Địa chỉ PC: 0x0d905c | Địa chỉ FDE: 0x073cb8 | Kích thước: 256 bytes
//   0x0d905c: AA1E03E5  mov      x5, x30
//   0x0d9060: 94027627  bl       #0x1768fc
//   0x0d9064: AA0503FE  mov      x30, x5
//   0x0d9068: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0398_0x0d905c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d905cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94027627ULL) ^ 0x073cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0399 | PC: 0x0d9568 | FDE: 0x073d00 | Size: 72 bytes
// Khung tháo gỡ #0399 | Địa chỉ PC: 0x0d9568 | Địa chỉ FDE: 0x073d00 | Kích thước: 72 bytes
//   0x0d9568: AA1F03E1  mov      x1, xzr
//   0x0d956c: 17FFFFF3  b        #0xd9538
//   0x0d9570: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d9574: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0399_0x0d9568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9568ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fffff3ULL) ^ 0x073d00ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x0a8518(a0, a1);
        case 1: return fde_func_0001_0x0a8690(a0, a1);
        case 2: return fde_func_0002_0x0a87e8(a0, a1);
        case 3: return fde_func_0003_0x0a8824(a0, a1);
        case 4: return fde_func_0004_0x0a8844(a0, a1);
        case 5: return fde_func_0005_0x0a88ec(a0, a1);
        case 6: return fde_func_0006_0x0a89fc(a0, a1);
        case 7: return fde_func_0007_0x0a8a84(a0, a1);
        case 8: return fde_func_0008_0x0a8bcc(a0, a1);
        case 9: return fde_func_0009_0x0a8db4(a0, a1);
        case 10: return fde_func_0010_0x0a8e5c(a0, a1);
        case 11: return fde_func_0011_0x0a8ef8(a0, a1);
        case 12: return fde_func_0012_0x0a8f20(a0, a1);
        case 13: return fde_func_0013_0x0a8f60(a0, a1);
        case 14: return fde_func_0014_0x0a8f6c(a0, a1);
        case 15: return fde_func_0015_0x0a8f78(a0, a1);
        case 16: return fde_func_0016_0x0a8f94(a0, a1);
        case 17: return fde_func_0017_0x0a8fb8(a0, a1);
        case 18: return fde_func_0018_0x0a8fc8(a0, a1);
        case 19: return fde_func_0019_0x0a8fe8(a0, a1);
        case 20: return fde_func_0020_0x0a8fec(a0, a1);
        case 21: return fde_func_0021_0x0a9020(a0, a1);
        case 22: return fde_func_0022_0x0a9078(a0, a1);
        case 23: return fde_func_0023_0x0a91e0(a0, a1);
        case 24: return fde_func_0024_0x0a92e4(a0, a1);
        case 25: return fde_func_0025_0x0a93ac(a0, a1);
        case 26: return fde_func_0026_0x0a93e8(a0, a1);
        case 27: return fde_func_0027_0x0a93ec(a0, a1);
        case 28: return fde_func_0028_0x0a94ec(a0, a1);
        case 29: return fde_func_0029_0x0a94f4(a0, a1);
        case 30: return fde_func_0030_0x0a9678(a0, a1);
        case 31: return fde_func_0031_0x0a998c(a0, a1);
        case 32: return fde_func_0032_0x0a9abc(a0, a1);
        case 33: return fde_func_0033_0x0a9af0(a0, a1);
        case 34: return fde_func_0034_0x0a9b5c(a0, a1);
        case 35: return fde_func_0035_0x0a9b94(a0, a1);
        case 36: return fde_func_0036_0x0a9d70(a0, a1);
        case 37: return fde_func_0037_0x0a9ddc(a0, a1);
        case 38: return fde_func_0038_0x0a9e4c(a0, a1);
        case 39: return fde_func_0039_0x0a9ee8(a0, a1);
        case 40: return fde_func_0040_0x0aa230(a0, a1);
        case 41: return fde_func_0041_0x0aa2f0(a0, a1);
        case 42: return fde_func_0042_0x0aa388(a0, a1);
        case 43: return fde_func_0043_0x0aa4cc(a0, a1);
        case 44: return fde_func_0044_0x0aa648(a0, a1);
        case 45: return fde_func_0045_0x0aa844(a0, a1);
        case 46: return fde_func_0046_0x0aa8c4(a0, a1);
        case 47: return fde_func_0047_0x0aa9cc(a0, a1);
        case 48: return fde_func_0048_0x0aab74(a0, a1);
        case 49: return fde_func_0049_0x0aaff8(a0, a1);
        case 50: return fde_func_0050_0x0ab0f4(a0, a1);
        case 51: return fde_func_0051_0x0ab434(a0, a1);
        case 52: return fde_func_0052_0x0ab4fc(a0, a1);
        case 53: return fde_func_0053_0x0ab5ec(a0, a1);
        case 54: return fde_func_0054_0x0ab648(a0, a1);
        case 55: return fde_func_0055_0x0ab6e4(a0, a1);
        case 56: return fde_func_0056_0x0ab79c(a0, a1);
        case 57: return fde_func_0057_0x0ab840(a0, a1);
        case 58: return fde_func_0058_0x0ab898(a0, a1);
        case 59: return fde_func_0059_0x0ab89c(a0, a1);
        case 60: return fde_func_0060_0x0ab9a8(a0, a1);
        case 61: return fde_func_0061_0x0abb4c(a0, a1);
        case 62: return fde_func_0062_0x0abc5c(a0, a1);
        case 63: return fde_func_0063_0x0abccc(a0, a1);
        case 64: return fde_func_0064_0x0ac160(a0, a1);
        case 65: return fde_func_0065_0x0ac20c(a0, a1);
        case 66: return fde_func_0066_0x0ac314(a0, a1);
        case 67: return fde_func_0067_0x0ac3c8(a0, a1);
        case 68: return fde_func_0068_0x0ac440(a0, a1);
        case 69: return fde_func_0069_0x0ac51c(a0, a1);
        case 70: return fde_func_0070_0x0ac584(a0, a1);
        case 71: return fde_func_0071_0x0ac5e0(a0, a1);
        case 72: return fde_func_0072_0x0ac6a8(a0, a1);
        case 73: return fde_func_0073_0x0ac6f8(a0, a1);
        case 74: return fde_func_0074_0x0ac824(a0, a1);
        case 75: return fde_func_0075_0x0ac91c(a0, a1);
        case 76: return fde_func_0076_0x0aca9c(a0, a1);
        case 77: return fde_func_0077_0x0acd00(a0, a1);
        case 78: return fde_func_0078_0x0acd50(a0, a1);
        case 79: return fde_func_0079_0x0acdb0(a0, a1);
        case 80: return fde_func_0080_0x0ace00(a0, a1);
        case 81: return fde_func_0081_0x0ace64(a0, a1);
        case 82: return fde_func_0082_0x0ad000(a0, a1);
        case 83: return fde_func_0083_0x0ad010(a0, a1);
        case 84: return fde_func_0084_0x0ad198(a0, a1);
        case 85: return fde_func_0085_0x0ad1fc(a0, a1);
        case 86: return fde_func_0086_0x0ad274(a0, a1);
        case 87: return fde_func_0087_0x0ae1e8(a0, a1);
        case 88: return fde_func_0088_0x0ae578(a0, a1);
        case 89: return fde_func_0089_0x0ae924(a0, a1);
        case 90: return fde_func_0090_0x0aebf8(a0, a1);
        case 91: return fde_func_0091_0x0aeda8(a0, a1);
        case 92: return fde_func_0092_0x0aeff0(a0, a1);
        case 93: return fde_func_0093_0x0af068(a0, a1);
        case 94: return fde_func_0094_0x0af1cc(a0, a1);
        case 95: return fde_func_0095_0x0af21c(a0, a1);
        case 96: return fde_func_0096_0x0af328(a0, a1);
        case 97: return fde_func_0097_0x0af3c4(a0, a1);
        case 98: return fde_func_0098_0x0af448(a0, a1);
        case 99: return fde_func_0099_0x0af4b8(a0, a1);
        case 100: return fde_func_0100_0x0af540(a0, a1);
        case 101: return fde_func_0101_0x0af58c(a0, a1);
        case 102: return fde_func_0102_0x0af6c8(a0, a1);
        case 103: return fde_func_0103_0x0af8b4(a0, a1);
        case 104: return fde_func_0104_0x0af8bc(a0, a1);
        case 105: return fde_func_0105_0x0af960(a0, a1);
        case 106: return fde_func_0106_0x0afd40(a0, a1);
        case 107: return fde_func_0107_0x0afd94(a0, a1);
        case 108: return fde_func_0108_0x0afe94(a0, a1);
        case 109: return fde_func_0109_0x0afefc(a0, a1);
        case 110: return fde_func_0110_0x0b01c4(a0, a1);
        case 111: return fde_func_0111_0x0b0484(a0, a1);
        case 112: return fde_func_0112_0x0b0534(a0, a1);
        case 113: return fde_func_0113_0x0b0608(a0, a1);
        case 114: return fde_func_0114_0x0b0680(a0, a1);
        case 115: return fde_func_0115_0x0b07d0(a0, a1);
        case 116: return fde_func_0116_0x0b08d4(a0, a1);
        case 117: return fde_func_0117_0x0b08dc(a0, a1);
        case 118: return fde_func_0118_0x0b08e4(a0, a1);
        case 119: return fde_func_0119_0x0b08e8(a0, a1);
        case 120: return fde_func_0120_0x0b08ec(a0, a1);
        case 121: return fde_func_0121_0x0b08f0(a0, a1);
        case 122: return fde_func_0122_0x0b08f8(a0, a1);
        case 123: return fde_func_0123_0x0b0900(a0, a1);
        case 124: return fde_func_0124_0x0b0908(a0, a1);
        case 125: return fde_func_0125_0x0b0914(a0, a1);
        case 126: return fde_func_0126_0x0b0934(a0, a1);
        case 127: return fde_func_0127_0x0b09a0(a0, a1);
        case 128: return fde_func_0128_0x0b0cb8(a0, a1);
        case 129: return fde_func_0129_0x0b1164(a0, a1);
        case 130: return fde_func_0130_0x0b126c(a0, a1);
        case 131: return fde_func_0131_0x0b14ac(a0, a1);
        case 132: return fde_func_0132_0x0b16ec(a0, a1);
        case 133: return fde_func_0133_0x0b1778(a0, a1);
        case 134: return fde_func_0134_0x0b195c(a0, a1);
        case 135: return fde_func_0135_0x0b1964(a0, a1);
        case 136: return fde_func_0136_0x0b197c(a0, a1);
        case 137: return fde_func_0137_0x0b19c8(a0, a1);
        case 138: return fde_func_0138_0x0b1aa4(a0, a1);
        case 139: return fde_func_0139_0x0b1da0(a0, a1);
        case 140: return fde_func_0140_0x0b1eb0(a0, a1);
        case 141: return fde_func_0141_0x0b1f6c(a0, a1);
        case 142: return fde_func_0142_0x0b23c0(a0, a1);
        case 143: return fde_func_0143_0x0b2428(a0, a1);
        case 144: return fde_func_0144_0x0b24a0(a0, a1);
        case 145: return fde_func_0145_0x0b26bc(a0, a1);
        case 146: return fde_func_0146_0x0b2bb8(a0, a1);
        case 147: return fde_func_0147_0x0b2d7c(a0, a1);
        case 148: return fde_func_0148_0x0b2eec(a0, a1);
        case 149: return fde_func_0149_0x0b2f24(a0, a1);
        case 150: return fde_func_0150_0x0b3020(a0, a1);
        case 151: return fde_func_0151_0x0b30a4(a0, a1);
        case 152: return fde_func_0152_0x0b3340(a0, a1);
        case 153: return fde_func_0153_0x0b3680(a0, a1);
        case 154: return fde_func_0154_0x0b39b0(a0, a1);
        case 155: return fde_func_0155_0x0b3ac0(a0, a1);
        case 156: return fde_func_0156_0x0b3c80(a0, a1);
        case 157: return fde_func_0157_0x0b3e5c(a0, a1);
        case 158: return fde_func_0158_0x0b40f8(a0, a1);
        case 159: return fde_func_0159_0x0b4410(a0, a1);
        case 160: return fde_func_0160_0x0b44fc(a0, a1);
        case 161: return fde_func_0161_0x0b45dc(a0, a1);
        case 162: return fde_func_0162_0x0b4670(a0, a1);
        case 163: return fde_func_0163_0x0b46dc(a0, a1);
        case 164: return fde_func_0164_0x0b47c0(a0, a1);
        case 165: return fde_func_0165_0x0b4824(a0, a1);
        case 166: return fde_func_0166_0x0b4850(a0, a1);
        case 167: return fde_func_0167_0x0b48c0(a0, a1);
        case 168: return fde_func_0168_0x0b49ec(a0, a1);
        case 169: return fde_func_0169_0x0b4a70(a0, a1);
        case 170: return fde_func_0170_0x0b4b80(a0, a1);
        case 171: return fde_func_0171_0x0b4cfc(a0, a1);
        case 172: return fde_func_0172_0x0b50e4(a0, a1);
        case 173: return fde_func_0173_0x0b5120(a0, a1);
        case 174: return fde_func_0174_0x0b5180(a0, a1);
        case 175: return fde_func_0175_0x0b52f4(a0, a1);
        case 176: return fde_func_0176_0x0b53b4(a0, a1);
        case 177: return fde_func_0177_0x0b54c0(a0, a1);
        case 178: return fde_func_0178_0x0b5780(a0, a1);
        case 179: return fde_func_0179_0x0b589c(a0, a1);
        case 180: return fde_func_0180_0x0b5938(a0, a1);
        case 181: return fde_func_0181_0x0b5af4(a0, a1);
        case 182: return fde_func_0182_0x0b5c7c(a0, a1);
        case 183: return fde_func_0183_0x0b600c(a0, a1);
        case 184: return fde_func_0184_0x0b6468(a0, a1);
        case 185: return fde_func_0185_0x0b6554(a0, a1);
        case 186: return fde_func_0186_0x0b65a8(a0, a1);
        case 187: return fde_func_0187_0x0b66f8(a0, a1);
        case 188: return fde_func_0188_0x0b678c(a0, a1);
        case 189: return fde_func_0189_0x0b67f4(a0, a1);
        case 190: return fde_func_0190_0x0b6864(a0, a1);
        case 191: return fde_func_0191_0x0b6a08(a0, a1);
        case 192: return fde_func_0192_0x0b6a90(a0, a1);
        case 193: return fde_func_0193_0x0b6af4(a0, a1);
        case 194: return fde_func_0194_0x0b6b74(a0, a1);
        case 195: return fde_func_0195_0x0b70ac(a0, a1);
        case 196: return fde_func_0196_0x0b72fc(a0, a1);
        case 197: return fde_func_0197_0x0b74e4(a0, a1);
        case 198: return fde_func_0198_0x0b76a0(a0, a1);
        case 199: return fde_func_0199_0x0b7708(a0, a1);
        case 200: return fde_func_0200_0x0b7f38(a0, a1);
        case 201: return fde_func_0201_0x0b8268(a0, a1);
        case 202: return fde_func_0202_0x0b84bc(a0, a1);
        case 203: return fde_func_0203_0x0b85d8(a0, a1);
        case 204: return fde_func_0204_0x0b8780(a0, a1);
        case 205: return fde_func_0205_0x0b87d4(a0, a1);
        case 206: return fde_func_0206_0x0b8814(a0, a1);
        case 207: return fde_func_0207_0x0b8984(a0, a1);
        case 208: return fde_func_0208_0x0b8b44(a0, a1);
        case 209: return fde_func_0209_0x0b8e20(a0, a1);
        case 210: return fde_func_0210_0x0b8f8c(a0, a1);
        case 211: return fde_func_0211_0x0b9014(a0, a1);
        case 212: return fde_func_0212_0x0b920c(a0, a1);
        case 213: return fde_func_0213_0x0b9cc0(a0, a1);
        case 214: return fde_func_0214_0x0b9d3c(a0, a1);
        case 215: return fde_func_0215_0x0b9f38(a0, a1);
        case 216: return fde_func_0216_0x0b9fd4(a0, a1);
        case 217: return fde_func_0217_0x0ba0e8(a0, a1);
        case 218: return fde_func_0218_0x0ba21c(a0, a1);
        case 219: return fde_func_0219_0x0ba33c(a0, a1);
        case 220: return fde_func_0220_0x0ba428(a0, a1);
        case 221: return fde_func_0221_0x0ba560(a0, a1);
        case 222: return fde_func_0222_0x0ba790(a0, a1);
        case 223: return fde_func_0223_0x0ba7fc(a0, a1);
        case 224: return fde_func_0224_0x0ba888(a0, a1);
        case 225: return fde_func_0225_0x0baa3c(a0, a1);
        case 226: return fde_func_0226_0x0bac38(a0, a1);
        case 227: return fde_func_0227_0x0baccc(a0, a1);
        case 228: return fde_func_0228_0x0badf8(a0, a1);
        case 229: return fde_func_0229_0x0baf48(a0, a1);
        case 230: return fde_func_0230_0x0bb1c0(a0, a1);
        case 231: return fde_func_0231_0x0bb564(a0, a1);
        case 232: return fde_func_0232_0x0bb6dc(a0, a1);
        case 233: return fde_func_0233_0x0bb988(a0, a1);
        case 234: return fde_func_0234_0x0bbbb4(a0, a1);
        case 235: return fde_func_0235_0x0bbc7c(a0, a1);
        case 236: return fde_func_0236_0x0bc1e8(a0, a1);
        case 237: return fde_func_0237_0x0bc3cc(a0, a1);
        case 238: return fde_func_0238_0x0bc434(a0, a1);
        case 239: return fde_func_0239_0x0bc6e4(a0, a1);
        case 240: return fde_func_0240_0x0bca2c(a0, a1);
        case 241: return fde_func_0241_0x0bcbe4(a0, a1);
        case 242: return fde_func_0242_0x0bcd34(a0, a1);
        case 243: return fde_func_0243_0x0bce68(a0, a1);
        case 244: return fde_func_0244_0x0bcf94(a0, a1);
        case 245: return fde_func_0245_0x0bd3f0(a0, a1);
        case 246: return fde_func_0246_0x0bd73c(a0, a1);
        case 247: return fde_func_0247_0x0bd82c(a0, a1);
        case 248: return fde_func_0248_0x0bd960(a0, a1);
        case 249: return fde_func_0249_0x0bda50(a0, a1);
        case 250: return fde_func_0250_0x0bdb78(a0, a1);
        case 251: return fde_func_0251_0x0bde94(a0, a1);
        case 252: return fde_func_0252_0x0bdee8(a0, a1);
        case 253: return fde_func_0253_0x0bdf84(a0, a1);
        case 254: return fde_func_0254_0x0be094(a0, a1);
        case 255: return fde_func_0255_0x0be14c(a0, a1);
        case 256: return fde_func_0256_0x0be980(a0, a1);
        case 257: return fde_func_0257_0x0beedc(a0, a1);
        case 258: return fde_func_0258_0x0bf518(a0, a1);
        case 259: return fde_func_0259_0x0bf8c0(a0, a1);
        case 260: return fde_func_0260_0x0bfa14(a0, a1);
        case 261: return fde_func_0261_0x0bfd70(a0, a1);
        case 262: return fde_func_0262_0x0c00b0(a0, a1);
        case 263: return fde_func_0263_0x0c033c(a0, a1);
        case 264: return fde_func_0264_0x0c0504(a0, a1);
        case 265: return fde_func_0265_0x0c063c(a0, a1);
        case 266: return fde_func_0266_0x0c0914(a0, a1);
        case 267: return fde_func_0267_0x0c1868(a0, a1);
        case 268: return fde_func_0268_0x0c193c(a0, a1);
        case 269: return fde_func_0269_0x0c1a7c(a0, a1);
        case 270: return fde_func_0270_0x0c1e2c(a0, a1);
        case 271: return fde_func_0271_0x0c1fe4(a0, a1);
        case 272: return fde_func_0272_0x0c2358(a0, a1);
        case 273: return fde_func_0273_0x0c374c(a0, a1);
        case 274: return fde_func_0274_0x0c3e8c(a0, a1);
        case 275: return fde_func_0275_0x0c404c(a0, a1);
        case 276: return fde_func_0276_0x0c4140(a0, a1);
        case 277: return fde_func_0277_0x0c42f0(a0, a1);
        case 278: return fde_func_0278_0x0c44d4(a0, a1);
        case 279: return fde_func_0279_0x0c45ac(a0, a1);
        case 280: return fde_func_0280_0x0c4744(a0, a1);
        case 281: return fde_func_0281_0x0c4934(a0, a1);
        case 282: return fde_func_0282_0x0c4b38(a0, a1);
        case 283: return fde_func_0283_0x0c4bec(a0, a1);
        case 284: return fde_func_0284_0x0c4f8c(a0, a1);
        case 285: return fde_func_0285_0x0c5088(a0, a1);
        case 286: return fde_func_0286_0x0c54d4(a0, a1);
        case 287: return fde_func_0287_0x0c5f00(a0, a1);
        case 288: return fde_func_0288_0x0c67ec(a0, a1);
        case 289: return fde_func_0289_0x0c6ab4(a0, a1);
        case 290: return fde_func_0290_0x0c6f5c(a0, a1);
        case 291: return fde_func_0291_0x0c7200(a0, a1);
        case 292: return fde_func_0292_0x0c7d30(a0, a1);
        case 293: return fde_func_0293_0x0c83b4(a0, a1);
        case 294: return fde_func_0294_0x0c8a78(a0, a1);
        case 295: return fde_func_0295_0x0c8cb4(a0, a1);
        case 296: return fde_func_0296_0x0c9070(a0, a1);
        case 297: return fde_func_0297_0x0c9218(a0, a1);
        case 298: return fde_func_0298_0x0c92e4(a0, a1);
        case 299: return fde_func_0299_0x0c9560(a0, a1);
        case 300: return fde_func_0300_0x0c97e4(a0, a1);
        case 301: return fde_func_0301_0x0c9894(a0, a1);
        case 302: return fde_func_0302_0x0c9d80(a0, a1);
        case 303: return fde_func_0303_0x0ca3b8(a0, a1);
        case 304: return fde_func_0304_0x0ca638(a0, a1);
        case 305: return fde_func_0305_0x0cabc8(a0, a1);
        case 306: return fde_func_0306_0x0cacf0(a0, a1);
        case 307: return fde_func_0307_0x0cad80(a0, a1);
        case 308: return fde_func_0308_0x0cae94(a0, a1);
        case 309: return fde_func_0309_0x0cb830(a0, a1);
        case 310: return fde_func_0310_0x0cb90c(a0, a1);
        case 311: return fde_func_0311_0x0cbb98(a0, a1);
        case 312: return fde_func_0312_0x0cbeec(a0, a1);
        case 313: return fde_func_0313_0x0cc214(a0, a1);
        case 314: return fde_func_0314_0x0cc344(a0, a1);
        case 315: return fde_func_0315_0x0cc488(a0, a1);
        case 316: return fde_func_0316_0x0ccac4(a0, a1);
        case 317: return fde_func_0317_0x0ccc1c(a0, a1);
        case 318: return fde_func_0318_0x0ccdd4(a0, a1);
        case 319: return fde_func_0319_0x0cd0e8(a0, a1);
        case 320: return fde_func_0320_0x0cd188(a0, a1);
        case 321: return fde_func_0321_0x0cd31c(a0, a1);
        case 322: return fde_func_0322_0x0cd3f0(a0, a1);
        case 323: return fde_func_0323_0x0cd750(a0, a1);
        case 324: return fde_func_0324_0x0cdce0(a0, a1);
        case 325: return fde_func_0325_0x0cde30(a0, a1);
        case 326: return fde_func_0326_0x0ce138(a0, a1);
        case 327: return fde_func_0327_0x0ce244(a0, a1);
        case 328: return fde_func_0328_0x0ce340(a0, a1);
        case 329: return fde_func_0329_0x0ce650(a0, a1);
        case 330: return fde_func_0330_0x0cebdc(a0, a1);
        case 331: return fde_func_0331_0x0cee50(a0, a1);
        case 332: return fde_func_0332_0x0cf124(a0, a1);
        case 333: return fde_func_0333_0x0cf32c(a0, a1);
        case 334: return fde_func_0334_0x0cf418(a0, a1);
        case 335: return fde_func_0335_0x0cf740(a0, a1);
        case 336: return fde_func_0336_0x0cff3c(a0, a1);
        case 337: return fde_func_0337_0x0d0258(a0, a1);
        case 338: return fde_func_0338_0x0d02dc(a0, a1);
        case 339: return fde_func_0339_0x0d051c(a0, a1);
        case 340: return fde_func_0340_0x0d06b0(a0, a1);
        case 341: return fde_func_0341_0x0d0c48(a0, a1);
        case 342: return fde_func_0342_0x0d0cb0(a0, a1);
        case 343: return fde_func_0343_0x0d1064(a0, a1);
        case 344: return fde_func_0344_0x0d1458(a0, a1);
        case 345: return fde_func_0345_0x0d16f8(a0, a1);
        case 346: return fde_func_0346_0x0d1884(a0, a1);
        case 347: return fde_func_0347_0x0d1a44(a0, a1);
        case 348: return fde_func_0348_0x0d1c48(a0, a1);
        case 349: return fde_func_0349_0x0d1f50(a0, a1);
        case 350: return fde_func_0350_0x0d2198(a0, a1);
        case 351: return fde_func_0351_0x0d24a8(a0, a1);
        case 352: return fde_func_0352_0x0d2594(a0, a1);
        case 353: return fde_func_0353_0x0d299c(a0, a1);
        case 354: return fde_func_0354_0x0d2a74(a0, a1);
        case 355: return fde_func_0355_0x0d2afc(a0, a1);
        case 356: return fde_func_0356_0x0d2b74(a0, a1);
        case 357: return fde_func_0357_0x0d2cc0(a0, a1);
        case 358: return fde_func_0358_0x0d2f30(a0, a1);
        case 359: return fde_func_0359_0x0d3524(a0, a1);
        case 360: return fde_func_0360_0x0d37d0(a0, a1);
        case 361: return fde_func_0361_0x0d455c(a0, a1);
        case 362: return fde_func_0362_0x0d47fc(a0, a1);
        case 363: return fde_func_0363_0x0d48d8(a0, a1);
        case 364: return fde_func_0364_0x0d4b30(a0, a1);
        case 365: return fde_func_0365_0x0d4c84(a0, a1);
        case 366: return fde_func_0366_0x0d4e60(a0, a1);
        case 367: return fde_func_0367_0x0d5244(a0, a1);
        case 368: return fde_func_0368_0x0d5418(a0, a1);
        case 369: return fde_func_0369_0x0d5570(a0, a1);
        case 370: return fde_func_0370_0x0d560c(a0, a1);
        case 371: return fde_func_0371_0x0d5acc(a0, a1);
        case 372: return fde_func_0372_0x0d65ec(a0, a1);
        case 373: return fde_func_0373_0x0d6770(a0, a1);
        case 374: return fde_func_0374_0x0d68a8(a0, a1);
        case 375: return fde_func_0375_0x0d6a68(a0, a1);
        case 376: return fde_func_0376_0x0d6cfc(a0, a1);
        case 377: return fde_func_0377_0x0d7270(a0, a1);
        case 378: return fde_func_0378_0x0d7458(a0, a1);
        case 379: return fde_func_0379_0x0d76ec(a0, a1);
        case 380: return fde_func_0380_0x0d7e6c(a0, a1);
        case 381: return fde_func_0381_0x0d8010(a0, a1);
        case 382: return fde_func_0382_0x0d82c8(a0, a1);
        case 383: return fde_func_0383_0x0d84c0(a0, a1);
        case 384: return fde_func_0384_0x0d8580(a0, a1);
        case 385: return fde_func_0385_0x0d8668(a0, a1);
        case 386: return fde_func_0386_0x0d8688(a0, a1);
        case 387: return fde_func_0387_0x0d86dc(a0, a1);
        case 388: return fde_func_0388_0x0d86f0(a0, a1);
        case 389: return fde_func_0389_0x0d8860(a0, a1);
        case 390: return fde_func_0390_0x0d89d8(a0, a1);
        case 391: return fde_func_0391_0x0d8b10(a0, a1);
        case 392: return fde_func_0392_0x0d8c1c(a0, a1);
        case 393: return fde_func_0393_0x0d8d54(a0, a1);
        case 394: return fde_func_0394_0x0d8f24(a0, a1);
        case 395: return fde_func_0395_0x0d8fc4(a0, a1);
        case 396: return fde_func_0396_0x0d9038(a0, a1);
        case 397: return fde_func_0397_0x0d9054(a0, a1);
        case 398: return fde_func_0398_0x0d905c(a0, a1);
        case 399: return fde_func_0399_0x0d9568(a0, a1);
        default: return 0ULL;
    }
}

} // namespace canvas
} // namespace lynx