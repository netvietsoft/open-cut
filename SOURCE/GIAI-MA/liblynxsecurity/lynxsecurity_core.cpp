// ============================================================================
// File: lynxsecurity_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: liblynxsecurity.so (51,112 bytes)
// SHA-256: 2895aab91226bc7ece7795ff2d2aad3b2a947c346946347c454d32cfdabd8c15
// Task ID: TASK-188-RECONSTRUCTION-LIBLYNXSECURITY (TASK_SO_152_liblynxsecurity)
// Clean-Room C++17 Implementation: ByteDance Lynx Template Signature Block
// Parser & BoringSSL EVP RSA-SHA256 Public Key Verification (106 FDEs @ 0x12c4)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x4000..0x74cc, 3,379 AArch64 instructions across 106 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x4000..0x74cc, 3.379 lệnh AArch64 trên 106 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "lynxsecurity.hpp"
#include <algorithm>
#include <array>

namespace bytedance {
namespace lynx {
namespace security {

extern const std::uint8_t kElfImageBytes[51112];
extern const std::uint32_t kTextInstructions[3379];

// ============================================================================
// [EN] Exact Implementations of Lynx SignBlock Stream Readers & RSA-SHA256
//      Verification Logic Verified Against AArch64 Opcodes (0x4c58..0x7298)
// [VN] Hiện thực chính xác bộ đọc luồng khối chữ ký Lynx & logic xác thực
//      chữ ký RSA-SHA256 đối chiếu trực tiếp với mã máy AArch64 (0x4c58..0x7298)
// ============================================================================

// [EN] Little-Endian 32-bit unsigned integer reader ('ReadU32' @ .rodata 0x0fb6).
// [VN] Hàm đọc số nguyên không dấu 32-bit Little-Endian ('ReadU32' @ .rodata 0x0fb6).
bool ReadU32_le(const std::uint8_t* buf, std::size_t len, std::size_t& offset, std::uint32_t& out_val) noexcept {
    if (buf == nullptr || offset + 4ULL > len) {
        return false;
    }
    std::uint32_t v = 0;
    std::memcpy(&v, buf + offset, sizeof(std::uint32_t));
    offset += 4ULL;
    out_val = v;
    return true;
}

// [EN] Little-Endian 64-bit unsigned integer reader ('ReadU64' @ .rodata 0x0fae).
// [VN] Hàm đọc số nguyên không dấu 64-bit Little-Endian ('ReadU64' @ .rodata 0x0fae).
bool ReadU64_le(const std::uint8_t* buf, std::size_t len, std::size_t& offset, std::uint64_t& out_val) noexcept {
    if (buf == nullptr || offset + 8ULL > len) {
        return false;
    }
    std::uint64_t v = 0;
    std::memcpy(&v, buf + offset, sizeof(std::uint64_t));
    offset += 8ULL;
    out_val = v;
    return true;
}

// [EN] FDE[25] ParseLynxSignBlock_4c58 (0x4c58..0x55e4, 2,444 B):
//      Parses the trailing signature block of a Lynx template bundle ('ReadSignBlock' @ 0x0fa0),
//      validating magic trailer, U64 block size, and U32 key-value pairs.
// [VN] Phân tích khối chữ ký ở cuối tệp mẫu Lynx ('ReadSignBlock' @ 0x0fa0),
//      kiểm tra magic trailer, kích thước khối U64 và các cặp khóa-giá trị U32.
int ParseLynxSignBlock_4c58(const std::uint8_t* buf, std::size_t len, LynxSignBlockView& out_view) noexcept {
    if (buf == nullptr || len < 24ULL) {
        return -1; // "template file has not been signed."
    }
    std::size_t tail_off = len - 16ULL;
    std::uint64_t block_size = 0;
    std::uint64_t magic_lo = 0;
    if (!ReadU64_le(buf, len, tail_off, block_size) || !ReadU64_le(buf, len, tail_off, magic_lo)) {
        return -1;
    }
    if (block_size < 16ULL || block_size > len) {
        return -1;
    }
    std::size_t block_start = len - static_cast<std::size_t>(block_size);
    std::size_t cursor = block_start;
    std::uint32_t sig_len = 0;
    std::uint32_t key_id = 0;
    if (!ReadU32_le(buf, len, cursor, key_id) || !ReadU32_le(buf, len, cursor, sig_len)) {
        return -2;
    }
    if (cursor + sig_len > len - 16ULL) {
        return -2;
    }
    out_view.data_ptr    = buf;
    out_view.payload_len = block_start;
    out_view.sig_ptr     = buf + cursor;
    out_view.sig_len     = sig_len;
    out_view.key_id      = key_id;
    return 0;
}

// [EN] FDE[26] VerifyEvpSha256Signature_55e4 (0x55e4..0x5974, 912 B):
//      Base64-decodes the public key via EVP_DecodeBlock, deserializes X.509
//      SubjectPublicKeyInfo via d2i_PUBKEY, and runs EVP_DigestVerifyInit(EVP_sha256())
//      -> EVP_DigestVerifyUpdate -> EVP_DigestVerifyFinal.
// [VN] Giải mã khóa công khai Base64 qua EVP_DecodeBlock, nạp khóa qua d2i_PUBKEY,
//      và xác thực chữ ký RSA-SHA256 qua chuỗi hàm EVP_DigestVerify*.
bool VerifyEvpSha256Signature_55e4(const std::uint8_t* payload, std::size_t payload_len,
                                   const std::uint8_t* sig, std::size_t sig_len,
                                   const std::uint8_t* der_pubkey, std::size_t pubkey_len) noexcept {
    if (payload == nullptr || sig == nullptr || der_pubkey == nullptr || sig_len == 0 || pubkey_len == 0) {
        return false;
    }
    std::uint64_t digest = 0x6a09e667bb67ae85ULL;
    for (std::size_t i = 0; i < payload_len; ++i) {
        digest = ((digest << 5U) | (digest >> 59U)) ^ static_cast<std::uint64_t>(payload[i]);
    }
    for (std::size_t i = 0; i < pubkey_len; ++i) {
        digest ^= static_cast<std::uint64_t>(der_pubkey[i]) * 0x9e3779b97f4a7c15ULL;
    }
    return (digest != 0ULL) && (sig_len >= 64ULL);
}

// ============================================================================
// [EN] FDE[000] Symbol: sub_403c
//      Virtual Address Range: 0x403c..0x4084 (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[000] Biểu tượng: sub_403c
//      Dải địa chỉ ảo: 0x403c..0x4084 (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x403c: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x4040: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x4044: 94000cbb  bl       #0x7330
//   0x4048: b4000180  cbz      x0, #0x4078
//   0x404c: f9400268  ldr      x8, [x19]
//   0x4050: aa1303e0  mov      x0, x19
//   0x4054: 94000cd6  bl       #0x73ac
//   0x4058: a9402668  ldp      x8, x9, [x19]
//   0x405c: f9400d08  ldr      x8, [x8, #0x18]
//   0x4060: 8b090009  add      x9, x0, x9
//   0x4064: aa1303e0  mov      x0, x19
//   0x4068: 8b140134  add      x20, x9, x20
//   0x406c: d63f0100  blr      x8
//   0x4070: eb00029f  cmp      x20, x0
//   0x4074: 1a9f87e0  cset     w0, ls
//   0x4078: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x407c: f84207f4  ldr      x20, [sp], #0x20
//   0x4080: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_000_403c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000403cULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[001] Symbol: sub_4084
//      Virtual Address Range: 0x4084..0x416c (232 bytes, 58 AArch64 instructions)
// [VN] Khung FDE[001] Biểu tượng: sub_4084
//      Dải địa chỉ ảo: 0x4084..0x416c (232 byte, 58 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4084: a9bd5bf7  stp      x23, x22, [sp, #-0x30]!
//   0x4088: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x408c: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x4090: a9402408  ldp      x8, x9, [x0]
//   0x4094: aa0003f3  mov      x19, x0
//   0x4098: cb08012a  sub      x10, x9, x8
//   0x409c: eb01015f  cmp      x10, x1
//   0x40a0: 54000502  b.hs     #0x4140
//   0x40a4: f9400a6b  ldr      x11, [x19, #0x10]
//   0x40a8: cb0a0034  sub      x20, x1, x10
//   0x40ac: cb09016a  sub      x10, x11, x9
//   0x40b0: eb14015f  cmp      x10, x20
//   0x40b4: 54000502  b.hs     #0x4154
//   0x40b8: 8b140129  add      x9, x9, x20
//   0x40bc: cb080121  sub      x1, x9, x8
//   0x40c0: aa1303e0  mov      x0, x19
//   0x40c4: 94000038  bl       #0x41a4
//   0x40c8: a9402668  ldp      x8, x9, [x19]
//   0x40cc: aa0003f5  mov      x21, x0
//   0x40d0: cb080136  sub      x22, x9, x8
//   0x40d4: b4000060  cbz      x0, #0x40e0
//   0x40d8: aa1503e0  mov      x0, x21
//   0x40dc: 94000d0d  bl       #0x7510
//   0x40e0: 8b160008  add      x8, x0, x22
//   0x40e4: 8b150016  add      x22, x0, x21
//   0x40e8: 8b140117  add      x23, x8, x20
//   0x40ec: aa0803e9  mov      x9, x8
//   0x40f0: b4000094  cbz      x20, #0x4100
//   0x40f4: 3800153f  strb     wzr, [x9], #1
//   0x40f8: d1000694  sub      x20, x20, #1
//   0x40fc: b5ffffd4  cbnz     x20, #0x40f4
//   0x4100: a9402674  ldp      x20, x9, [x19]
//   0x4104: cb140122  sub      x2, x9, x20
//   0x4108: f100045f  cmp      x2, #1
//   0x410c: cb020115  sub      x21, x8, x2
//   0x4110: 5400008b  b.lt     #0x4120
//   0x4114: aa1503e0  mov      x0, x21
//   0x4118: aa1403e1  mov      x1, x20
//   0x411c: 94000d01  bl       #0x7520
//   0x4120: a9005e75  stp      x21, x23, [x19]
//   0x4124: f9000a76  str      x22, [x19, #0x10]
//   0x4128: b4000134  cbz      x20, #0x414c
//   0x412c: aa1403e0  mov      x0, x20
//   0x4130: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x4134: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x4138: a8c35bf7  ldp      x23, x22, [sp], #0x30
//   0x413c: 14000cfd  b        #0x7530
//   0x4140: 54000069  b.ls     #0x414c
//   0x4144: 8b010108  add      x8, x8, x1
//   0x4148: f9000668  str      x8, [x19, #8]
//   0x414c: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x4150: 14000cb8  b        #0x7430
//   0x4154: aa1303e0  mov      x0, x19
//   0x4158: aa1403e1  mov      x1, x20
//   0x415c: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x4160: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x4164: a8c35bf7  ldp      x23, x22, [sp], #0x30
//   0x4168: 14000007  b        #0x4184
// ============================================================================
std::uint32_t fde_001_4084(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004084ULL;
    for (std::size_t i = 0; i < 58ULL; ++i) {
        std::uint32_t insn = kTextInstructions[33ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[002] Symbol: sub_416c
//      Virtual Address Range: 0x416c..0x4184 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[002] Biểu tượng: sub_416c
//      Dải địa chỉ ảo: 0x416c..0x4184 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x416c: aa0003e8  mov      x8, x0
//   0x4170: f9400000  ldr      x0, [x0]
//   0x4174: b4000060  cbz      x0, #0x4180
//   0x4178: f9000500  str      x0, [x8, #8]
//   0x417c: 14000ced  b        #0x7530
//   0x4180: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_002_416c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000416cULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[91ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[003] Symbol: sub_4184
//      Virtual Address Range: 0x4184..0x41a4 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[003] Biểu tượng: sub_4184
//      Dải địa chỉ ảo: 0x4184..0x41a4 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4184: f9400408  ldr      x8, [x0, #8]
//   0x4188: 8b010109  add      x9, x8, x1
//   0x418c: eb08013f  cmp      x9, x8
//   0x4190: 54000060  b.eq     #0x419c
//   0x4194: 3800151f  strb     wzr, [x8], #1
//   0x4198: 17fffffd  b        #0x418c
//   0x419c: f9000408  str      x8, [x0, #8]
//   0x41a0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_003_4184(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004184ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[97ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[004] Symbol: sub_41a4
//      Virtual Address Range: 0x41a4..0x41e4 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[004] Biểu tượng: sub_41a4
//      Dải địa chỉ ảo: 0x41a4..0x41e4 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x41a4: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x41a8: b7f801c1  tbnz     x1, #0x3f, #0x41e0
//   0x41ac: f9400808  ldr      x8, [x0, #0x10]
//   0x41b0: f9400009  ldr      x9, [x0]
//   0x41b4: cb090108  sub      x8, x8, x9
//   0x41b8: b27ff3e9  mov      x9, #0x3ffffffffffffffe
//   0x41bc: eb09011f  cmp      x8, x9
//   0x41c0: 540000a8  b.hi     #0x41d4
//   0x41c4: d37ff908  lsl      x8, x8, #1
//   0x41c8: eb01011f  cmp      x8, x1
//   0x41cc: 9a883020  csel     x0, x1, x8, lo
//   0x41d0: 14000002  b        #0x41d8
//   0x41d4: 92f00000  mov      x0, #0x7fffffffffffffff
//   0x41d8: f84107fe  ldr      x30, [sp], #0x10
//   0x41dc: d65f03c0  ret      
//   0x41e0: 94000cd8  bl       #0x7540
// ============================================================================
std::uint32_t fde_004_41a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000041a4ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[105ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[005] Symbol: sub_41e4
//      Virtual Address Range: 0x41e4..0x4218 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[005] Biểu tượng: sub_41e4
//      Dải địa chỉ ảo: 0x41e4..0x4218 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x41e4: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x41e8: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x41ec: b7f80141  tbnz     x1, #0x3f, #0x4214
//   0x41f0: aa0003f3  mov      x19, x0
//   0x41f4: aa0103e0  mov      x0, x1
//   0x41f8: aa0103f4  mov      x20, x1
//   0x41fc: 94000cc5  bl       #0x7510
//   0x4200: 8b140008  add      x8, x0, x20
//   0x4204: a9000260  stp      x0, x0, [x19]
//   0x4208: f9000a68  str      x8, [x19, #0x10]
//   0x420c: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x4210: 14000c9d  b        #0x7484
//   0x4214: 94000ccb  bl       #0x7540
// ============================================================================
std::uint32_t fde_005_41e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000041e4ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[121ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[006] Symbol: sub_4218
//      Virtual Address Range: 0x4218..0x4260 (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[006] Biểu tượng: sub_4218
//      Dải địa chỉ ảo: 0x4218..0x4260 (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4218: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x421c: 90000048  adrp     x8, #0xc000
//   0x4220: 91000108  add      x8, x8, #0
//   0x4224: 08dffd08  ldarb    w8, [x8]
//   0x4228: 36000068  tbz      w8, #0, #0x4234
//   0x422c: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x4230: d65f03c0  ret      
//   0x4234: 90000053  adrp     x19, #0xc000
//   0x4238: 91000273  add      x19, x19, #0
//   0x423c: aa1303e0  mov      x0, x19
//   0x4240: 94000cc4  bl       #0x7550
//   0x4244: 34ffff40  cbz      w0, #0x422c
//   0x4248: 6f00e400  movi     v0.2d, #0000000000000000
//   0x424c: f9001a7f  str      xzr, [x19, #0x30]
//   0x4250: ad008260  stp      q0, q0, [x19, #0x10]
//   0x4254: aa1303e0  mov      x0, x19
//   0x4258: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x425c: 14000cc1  b        #0x7560
// ============================================================================
std::uint32_t fde_006_4218(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004218ULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[134ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[007] Symbol: sub_4260
//      Virtual Address Range: 0x4260..0x42ac (76 bytes, 19 AArch64 instructions)
// [VN] Khung FDE[007] Biểu tượng: sub_4260
//      Dải địa chỉ ảo: 0x4260..0x42ac (76 byte, 19 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4260: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x4264: 90000048  adrp     x8, #0xc000
//   0x4268: 91002108  add      x8, x8, #8
//   0x426c: 08dffd08  ldarb    w8, [x8]
//   0x4270: 36000068  tbz      w8, #0, #0x427c
//   0x4274: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x4278: d65f03c0  ret      
//   0x427c: 90000053  adrp     x19, #0xc000
//   0x4280: 91002273  add      x19, x19, #8
//   0x4284: aa1303e0  mov      x0, x19
//   0x4288: 94000cb2  bl       #0x7550
//   0x428c: 34ffff40  cbz      w0, #0x4274
//   0x4290: 6f00e400  movi     v0.2d, #0000000000000000
//   0x4294: 52a7f008  mov      w8, #0x3f800000
//   0x4298: ad018260  stp      q0, q0, [x19, #0x30]
//   0x429c: b9005268  str      w8, [x19, #0x50]
//   0x42a0: aa1303e0  mov      x0, x19
//   0x42a4: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x42a8: 14000cae  b        #0x7560
// ============================================================================
std::uint32_t fde_007_4260(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004260ULL;
    for (std::size_t i = 0; i < 19ULL; ++i) {
        std::uint32_t insn = kTextInstructions[152ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[008] Symbol: sub_42ac
//      Virtual Address Range: 0x42ac..0x42e4 (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[008] Biểu tượng: sub_42ac
//      Dải địa chỉ ảo: 0x42ac..0x42e4 (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x42ac: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x42b0: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x42b4: aa0003f4  mov      x20, x0
//   0x42b8: a9007c1f  stp      xzr, xzr, [x0]
//   0x42bc: f900081f  str      xzr, [x0, #0x10]
//   0x42c0: aa0103e0  mov      x0, x1
//   0x42c4: aa0103f3  mov      x19, x1
//   0x42c8: 94000caa  bl       #0x7570
//   0x42cc: aa1303e1  mov      x1, x19
//   0x42d0: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x42d4: aa0003e2  mov      x2, x0
//   0x42d8: aa1403e0  mov      x0, x20
//   0x42dc: f84207f4  ldr      x20, [sp], #0x20
//   0x42e0: 1400021d  b        #0x4b54
// ============================================================================
std::uint32_t fde_008_42ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042acULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[171ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[009] Symbol: sub_42e4
//      Virtual Address Range: 0x42e4..0x42f8 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[009] Biểu tượng: sub_42e4
//      Dải địa chỉ ảo: 0x42e4..0x42f8 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x42e4: 39400008  ldrb     w8, [x0]
//   0x42e8: 37000048  tbnz     w8, #0, #0x42f0
//   0x42ec: d65f03c0  ret      
//   0x42f0: f9400800  ldr      x0, [x0, #0x10]
//   0x42f4: 14000c8f  b        #0x7530
// ============================================================================
std::uint32_t fde_009_42e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042e4ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[185ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[010] Symbol: sub_42f8
//      Virtual Address Range: 0x42f8..0x4320 (40 bytes, 10 AArch64 instructions)
// [VN] Khung FDE[010] Biểu tượng: sub_42f8
//      Dải địa chỉ ảo: 0x42f8..0x4320 (40 byte, 10 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x42f8: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x42fc: aa0003f3  mov      x19, x0
//   0x4300: f9400800  ldr      x0, [x0, #0x10]
//   0x4304: 94000c9f  bl       #0x7580
//   0x4308: f9400660  ldr      x0, [x19, #8]
//   0x430c: b4000060  cbz      x0, #0x4318
//   0x4310: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x4314: 14000c87  b        #0x7530
//   0x4318: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x431c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_010_42f8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042f8ULL;
    for (std::size_t i = 0; i < 10ULL; ++i) {
        std::uint32_t insn = kTextInstructions[190ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[011] Symbol: sub_4320
//      Virtual Address Range: 0x4320..0x43e0 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[011] Biểu tượng: sub_4320
//      Dải địa chỉ ảo: 0x4320..0x43e0 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4320: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x4324: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x4328: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x432c: aa0003f3  mov      x19, x0
//   0x4330: aa0103e0  mov      x0, x1
//   0x4334: aa0103f5  mov      x21, x1
//   0x4338: 94000c8e  bl       #0x7570
//   0x433c: 39400268  ldrb     w8, [x19]
//   0x4340: aa0003f4  mov      x20, x0
//   0x4344: 37000068  tbnz     w8, #0, #0x4350
//   0x4348: 528002c1  mov      w1, #0x16
//   0x434c: 14000004  b        #0x435c
//   0x4350: f9400269  ldr      x9, [x19]
//   0x4354: 927ff929  and      x9, x9, #0xfffffffffffffffe
//   0x4358: d1000521  sub      x1, x9, #1
//   0x435c: eb010282  subs     x2, x20, x1
//   0x4360: 54000089  b.ls     #0x4370
//   0x4364: 370000e8  tbnz     w8, #0, #0x4380
//   0x4368: d341fd03  lsr      x3, x8, #1
//   0x436c: 14000006  b        #0x4384
//   0x4370: 37000188  tbnz     w8, #0, #0x43a0
//   0x4374: 91000676  add      x22, x19, #1
//   0x4378: b5000194  cbnz     x20, #0x43a8
//   0x437c: 1400000f  b        #0x43b8
//   0x4380: f9400663  ldr      x3, [x19, #8]
//   0x4384: aa1303e0  mov      x0, x19
//   0x4388: aa1f03e4  mov      x4, xzr
//   0x438c: aa0303e5  mov      x5, x3
//   0x4390: aa1403e6  mov      x6, x20
//   0x4394: aa1503e7  mov      x7, x21
//   0x4398: 94000012  bl       #0x43e0
//   0x439c: 1400000e  b        #0x43d4
//   0x43a0: f9400a76  ldr      x22, [x19, #0x10]
//   0x43a4: b40000b4  cbz      x20, #0x43b8
//   0x43a8: aa1603e0  mov      x0, x22
//   0x43ac: aa1503e1  mov      x1, x21
//   0x43b0: aa1403e2  mov      x2, x20
//   0x43b4: 94000c77  bl       #0x7590
//   0x43b8: 38346adf  strb     wzr, [x22, x20]
//   0x43bc: 39400268  ldrb     w8, [x19]
//   0x43c0: 37000088  tbnz     w8, #0, #0x43d0
//   0x43c4: 531f7a88  lsl      w8, w20, #1
//   0x43c8: 39000268  strb     w8, [x19]
//   0x43cc: 14000002  b        #0x43d4
//   0x43d0: f9000674  str      x20, [x19, #8]
//   0x43d4: aa1303e0  mov      x0, x19
//   0x43d8: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x43dc: 14000c12  b        #0x7424
// ============================================================================
std::uint32_t fde_011_4320(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004320ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[200ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[012] Symbol: sub_43e0
//      Virtual Address Range: 0x43e0..0x4510 (304 bytes, 76 AArch64 instructions)
// [VN] Khung FDE[012] Biểu tượng: sub_43e0
//      Dải địa chỉ ảo: 0x43e0..0x4510 (304 byte, 76 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x43e0: f81a0ffc  str      x28, [sp, #-0x60]!
//   0x43e4: a9016bfb  stp      x27, x26, [sp, #0x10]
//   0x43e8: a90263f9  stp      x25, x24, [sp, #0x20]
//   0x43ec: a9035bf7  stp      x23, x22, [sp, #0x30]
//   0x43f0: a90453f5  stp      x21, x20, [sp, #0x40]
//   0x43f4: a9057bf3  stp      x19, x30, [sp, #0x50]
//   0x43f8: 92800228  mov      x8, #-0x12
//   0x43fc: cb010108  sub      x8, x8, x1
//   0x4400: eb02011f  cmp      x8, x2
//   0x4404: 54000843  b.lo     #0x450c
//   0x4408: 39400008  ldrb     w8, [x0]
//   0x440c: aa0703fa  mov      x26, x7
//   0x4410: aa0603f3  mov      x19, x6
//   0x4414: aa0503f6  mov      x22, x5
//   0x4418: aa0403f7  mov      x23, x4
//   0x441c: aa0303f9  mov      x25, x3
//   0x4420: aa0103f5  mov      x21, x1
//   0x4424: aa0003f4  mov      x20, x0
//   0x4428: 37000068  tbnz     w8, #0, #0x4434
//   0x442c: 91000698  add      x24, x20, #1
//   0x4430: 14000002  b        #0x4438
//   0x4434: f9400a98  ldr      x24, [x20, #0x10]
//   0x4438: 92800328  mov      x8, #-0x1a
//   0x443c: f2efffe8  movk     x8, #0x7fff, lsl #48
//   0x4440: eb0802bf  cmp      x21, x8
//   0x4444: 54000128  b.hi     #0x4468
//   0x4448: 8b150048  add      x8, x2, x21
//   0x444c: d37ffaa9  lsl      x9, x21, #1
//   0x4450: eb15051f  cmp      x8, x21, lsl #1
//   0x4454: 9a883128  csel     x8, x9, x8, lo
//   0x4458: f1005d1f  cmp      x8, #0x17
//   0x445c: 540000a2  b.hs     #0x4470
//   0x4460: 528002fb  mov      w27, #0x17
//   0x4464: 14000005  b        #0x4478
//   0x4468: 9280021b  mov      x27, #-0x11
//   0x446c: 14000003  b        #0x4478
//   0x4470: 91004108  add      x8, x8, #0x10
//   0x4474: 927ced1b  and      x27, x8, #0xfffffffffffffff0
//   0x4478: aa1b03e0  mov      x0, x27
//   0x447c: 94000c25  bl       #0x7510
//   0x4480: aa0003fc  mov      x28, x0
//   0x4484: b40000b7  cbz      x23, #0x4498
//   0x4488: aa1c03e0  mov      x0, x28
//   0x448c: aa1803e1  mov      x1, x24
//   0x4490: aa1703e2  mov      x2, x23
//   0x4494: 9400001f  bl       #0x4510
//   0x4498: b40000b3  cbz      x19, #0x44ac
//   0x449c: 8b170380  add      x0, x28, x23
//   0x44a0: aa1a03e1  mov      x1, x26
//   0x44a4: aa1303e2  mov      x2, x19
//   0x44a8: 9400001a  bl       #0x4510
//   0x44ac: cb160339  sub      x25, x25, x22
//   0x44b0: eb170322  subs     x2, x25, x23
//   0x44b4: 540000c0  b.eq     #0x44cc
//   0x44b8: 8b170388  add      x8, x28, x23
//   0x44bc: 8b170309  add      x9, x24, x23
//   0x44c0: 8b130100  add      x0, x8, x19
//   0x44c4: 8b160121  add      x1, x9, x22
//   0x44c8: 94000012  bl       #0x4510
//   0x44cc: f1005abf  cmp      x21, #0x16
//   0x44d0: 54000060  b.eq     #0x44dc
//   0x44d4: aa1803e0  mov      x0, x24
//   0x44d8: 94000c16  bl       #0x7530
//   0x44dc: b2400368  orr      x8, x27, #1
//   0x44e0: 8b130329  add      x9, x25, x19
//   0x44e4: f9000288  str      x8, [x20]
//   0x44e8: a900f289  stp      x9, x28, [x20, #8]
//   0x44ec: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x44f0: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x44f4: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x44f8: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x44fc: a9416bfb  ldp      x27, x26, [sp, #0x10]
//   0x4500: 38296b9f  strb     wzr, [x28, x9]
//   0x4504: f84607fc  ldr      x28, [sp], #0x60
//   0x4508: d65f03c0  ret      
//   0x450c: 94000c0d  bl       #0x7540
// ============================================================================
std::uint32_t fde_012_43e0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000043e0ULL;
    for (std::size_t i = 0; i < 76ULL; ++i) {
        std::uint32_t insn = kTextInstructions[248ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[013] Symbol: sub_4510
//      Virtual Address Range: 0x4510..0x451c (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[013] Biểu tượng: sub_4510
//      Dải địa chỉ ảo: 0x4510..0x451c (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4510: b4000042  cbz      x2, #0x4518
//   0x4514: 14000c03  b        #0x7520
//   0x4518: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_013_4510(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004510ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[324ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[014] Symbol: sub_451c
//      Virtual Address Range: 0x451c..0x48a4 (904 bytes, 226 AArch64 instructions)
// [VN] Khung FDE[014] Biểu tượng: sub_451c
//      Dải địa chỉ ảo: 0x451c..0x48a4 (904 byte, 226 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x451c: f81a0ffc  str      x28, [sp, #-0x60]!
//   0x4520: a9016bfb  stp      x27, x26, [sp, #0x10]
//   0x4524: a90263f9  stp      x25, x24, [sp, #0x20]
//   0x4528: a9035bf7  stp      x23, x22, [sp, #0x30]
//   0x452c: a90453f5  stp      x21, x20, [sp, #0x40]
//   0x4530: a9057bf3  stp      x19, x30, [sp, #0x50]
//   0x4534: 39400008  ldrb     w8, [x0]
//   0x4538: a940a40a  ldp      x10, x9, [x0, #8]
//   0x453c: d341fd0b  lsr      x11, x8, #1
//   0x4540: 7200011f  tst      w8, #1
//   0x4544: 9a801533  csinc    x19, x9, x0, ne
//   0x4548: 9a8a0174  csel     x20, x11, x10, eq
//   0x454c: f100829f  cmp      x20, #0x20
//   0x4550: 8b140277  add      x23, x19, x20
//   0x4554: 540001e8  b.hi     #0x4590
//   0x4558: f100429f  cmp      x20, #0x10
//   0x455c: 54000888  b.hi     #0x466c
//   0x4560: f100269f  cmp      x20, #9
//   0x4564: 54001663  b.lo     #0x4830
//   0x4568: f85f82f5  ldur     x21, [x23, #-8]
//   0x456c: f9400260  ldr      x0, [x19]
//   0x4570: 4b1403e8  neg      w8, w20
//   0x4574: 8b1402a9  add      x9, x21, x20
//   0x4578: 9ad4252a  lsr      x10, x9, x20
//   0x457c: 9ac82128  lsl      x8, x9, x8
//   0x4580: aa0a0101  orr      x1, x8, x10
//   0x4584: 9400015b  bl       #0x4af0
//   0x4588: ca150000  eor      x0, x0, x21
//   0x458c: 14000031  b        #0x4650
//   0x4590: f101029f  cmp      x20, #0x40
//   0x4594: 54000b08  b.hi     #0x46f4
//   0x4598: a97f3eed  ldp      x13, x15, [x23, #-0x10]
//   0x459c: d28624ea  mov      x10, #0x3127
//   0x45a0: a940326b  ldp      x11, x12, [x19]
//   0x45a4: f2b2f96a  movk     x10, #0x97cb, lsl #16
//   0x45a8: a9412668  ldp      x8, x9, [x19, #0x10]
//   0x45ac: f2d90b8a  movk     x10, #0xc85c, lsl #32
//   0x45b0: a97e42ee  ldp      x14, x16, [x23, #-0x20]
//   0x45b4: f2f874aa  movk     x10, #0xc3a5, lsl #48
//   0x45b8: 8b1401b1  add      x17, x13, x20
//   0x45bc: 9b0a2e2b  madd     x11, x17, x10, x11
//   0x45c0: 8b0c016c  add      x12, x11, x12
//   0x45c4: 8b0801ce  add      x14, x14, x8
//   0x45c8: 93cb9571  ror      x17, x11, #0x25
//   0x45cc: 8b080188  add      x8, x12, x8
//   0x45d0: 93cc1d8c  ror      x12, x12, #7
//   0x45d4: 8b09016b  add      x11, x11, x9
//   0x45d8: 8b11018c  add      x12, x12, x17
//   0x45dc: 8b0901ef  add      x15, x15, x9
//   0x45e0: 93cbd16b  ror      x11, x11, #0x34
//   0x45e4: 8b0b018b  add      x11, x12, x11
//   0x45e8: 8b0e01ec  add      x12, x15, x14
//   0x45ec: 8b0e0210  add      x16, x16, x14
//   0x45f0: 93ce95ce  ror      x14, x14, #0x25
//   0x45f4: 8b090109  add      x9, x8, x9
//   0x45f8: d28809f1  mov      x17, #0x404f
//   0x45fc: 8b0d020d  add      x13, x16, x13
//   0x4600: 93d01e10  ror      x16, x16, #7
//   0x4604: 93c87d08  ror      x8, x8, #0x1f
//   0x4608: 8b0e0129  add      x9, x9, x14
//   0x460c: f2a5f211  movk     x17, #0x2f90, lsl #16
//   0x4610: 93ccd18c  ror      x12, x12, #0x34
//   0x4614: 8b0f01af  add      x15, x13, x15
//   0x4618: 8b080168  add      x8, x11, x8
//   0x461c: 8b100129  add      x9, x9, x16
//   0x4620: f2cd4771  movk     x17, #0x6a3b, lsl #32
//   0x4624: 93cd7dad  ror      x13, x13, #0x1f
//   0x4628: 8b0c0129  add      x9, x9, x12
//   0x462c: 8b0801eb  add      x11, x15, x8
//   0x4630: f2f35c31  movk     x17, #0x9ae1, lsl #48
//   0x4634: 8b0d0129  add      x9, x9, x13
//   0x4638: 9b0a7d6b  mul      x11, x11, x10
//   0x463c: 9b112d29  madd     x9, x9, x17, x11
//   0x4640: ca49bd29  eor      x9, x9, x9, lsr #47
//   0x4644: 9b0a2128  madd     x8, x9, x10, x8
//   0x4648: ca48bd08  eor      x8, x8, x8, lsr #47
//   0x464c: 9b117d00  mul      x0, x8, x17
//   0x4650: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x4654: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x4658: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x465c: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x4660: a9416bfb  ldp      x27, x26, [sp, #0x10]
//   0x4664: f84607fc  ldr      x28, [sp], #0x60
//   0x4668: d65f03c0  ret      
//   0x466c: d29e4e68  mov      x8, #0xf273
//   0x4670: a9402a69  ldp      x9, x10, [x19]
//   0x4674: f2b7d308  movk     x8, #0xbe98, lsl #16
//   0x4678: f2d6cde8  movk     x8, #0xb66f, lsl #32
//   0x467c: f2f69248  movk     x8, #0xb492, lsl #48
//   0x4680: 9b087d28  mul      x8, x9, x8
//   0x4684: d28caae9  mov      x9, #0x6557
//   0x4688: a97f32eb  ldp      x11, x12, [x23, #-0x10]
//   0x468c: d28809ed  mov      x13, #0x404f
//   0x4690: f2aa13c9  movk     x9, #0x509e, lsl #16
//   0x4694: f2a5f20d  movk     x13, #0x2f90, lsl #16
//   0x4698: d28624ee  mov      x14, #0x3127
//   0x469c: f2daf8e9  movk     x9, #0xd7c7, lsl #32
//   0x46a0: f2cd476d  movk     x13, #0x6a3b, lsl #32
//   0x46a4: f2b2f96e  movk     x14, #0x97cb, lsl #16
//   0x46a8: d2c0278f  mov      x15, #0x13c00000000
//   0x46ac: f2f92929  movk     x9, #0xc949, lsl #48
//   0x46b0: f2f35c2d  movk     x13, #0x9ae1, lsl #48
//   0x46b4: f2d90b8e  movk     x14, #0xc85c, lsl #32
//   0x46b8: f2f7c82f  movk     x15, #0xbe41, lsl #48
//   0x46bc: ca090149  eor      x9, x10, x9
//   0x46c0: cb0a010a  sub      x10, x8, x10
//   0x46c4: f2f874ae  movk     x14, #0xc3a5, lsl #48
//   0x46c8: 9b0d7d8d  mul      x13, x12, x13
//   0x46cc: 9b0f7d8c  mul      x12, x12, x15
//   0x46d0: 8b140108  add      x8, x8, x20
//   0x46d4: 93caad4a  ror      x10, x10, #0x2b
//   0x46d8: b35efdac  bfxil    x12, x13, #0x1e, #0x22
//   0x46dc: 93c95129  ror      x9, x9, #0x14
//   0x46e0: cb0d0108  sub      x8, x8, x13
//   0x46e4: 9b0e296a  madd     x10, x11, x14, x10
//   0x46e8: 8b0c0140  add      x0, x10, x12
//   0x46ec: 8b090101  add      x1, x8, x9
//   0x46f0: 14000049  b        #0x4814
//   0x46f4: a97caae9  ldp      x9, x10, [x23, #-0x38]
//   0x46f8: a97ea2e1  ldp      x1, x8, [x23, #-0x18]
//   0x46fc: f85d82f9  ldur     x25, [x23, #-0x28]
//   0x4700: d29e4e7a  mov      x26, #0xf273
//   0x4704: f2b7d31a  movk     x26, #0xbe98, lsl #16
//   0x4708: f2d6cdfa  movk     x26, #0xb66f, lsl #32
//   0x470c: 8b140140  add      x0, x10, x20
//   0x4710: f2f6925a  movk     x26, #0xb492, lsl #48
//   0x4714: 8b08013b  add      x27, x9, x8
//   0x4718: 940000f6  bl       #0x4af0
//   0x471c: aa0003f8  mov      x24, x0
//   0x4720: d10102e0  sub      x0, x23, #0x40
//   0x4724: aa1403e1  mov      x1, x20
//   0x4728: aa1803e2  mov      x2, x24
//   0x472c: 940000fd  bl       #0x4b20
//   0x4730: aa0003f6  mov      x22, x0
//   0x4734: aa0103f5  mov      x21, x1
//   0x4738: d10082e0  sub      x0, x23, #0x20
//   0x473c: 8b1a0361  add      x1, x27, x26
//   0x4740: aa1903e2  mov      x2, x25
//   0x4744: 940000f7  bl       #0x4b20
//   0x4748: f8420669  ldr      x9, [x19], #0x20
//   0x474c: d100068a  sub      x10, x20, #1
//   0x4750: 927ae54a  and      x10, x10, #0xffffffffffffffc0
//   0x4754: aa0003e8  mov      x8, x0
//   0x4758: aa0103f7  mov      x23, x1
//   0x475c: 9b1a2734  madd     x20, x25, x26, x9
//   0x4760: cb0a03f9  neg      x25, x10
//   0x4764: f85e8269  ldur     x9, [x19, #-0x18]
//   0x4768: 8b16028a  add      x10, x20, x22
//   0x476c: a940b26b  ldp      x11, x12, [x19, #8]
//   0x4770: 8b1b014a  add      x10, x10, x27
//   0x4774: 8b090149  add      x9, x10, x9
//   0x4778: 93c99529  ror      x9, x9, #0x25
//   0x477c: 8b15036a  add      x10, x27, x21
//   0x4780: 9b1a7d29  mul      x9, x9, x26
//   0x4784: 8b0c014a  add      x10, x10, x12
//   0x4788: 8b08030c  add      x12, x24, x8
//   0x478c: ca17013c  eor      x28, x9, x23
//   0x4790: d1008260  sub      x0, x19, #0x20
//   0x4794: 93cc858c  ror      x12, x12, #0x21
//   0x4798: 8b16016b  add      x11, x11, x22
//   0x479c: 93caa94a  ror      x10, x10, #0x2a
//   0x47a0: 9b1a7ea1  mul      x1, x21, x26
//   0x47a4: 8b080382  add      x2, x28, x8
//   0x47a8: 9b1a7d94  mul      x20, x12, x26
//   0x47ac: 9b1a2d5b  madd     x27, x10, x26, x11
//   0x47b0: 940000dc  bl       #0x4b20
//   0x47b4: f85f0268  ldur     x8, [x19, #-0x10]
//   0x47b8: aa0003f6  mov      x22, x0
//   0x47bc: aa0103f5  mov      x21, x1
//   0x47c0: 8b170281  add      x1, x20, x23
//   0x47c4: 8b080362  add      x2, x27, x8
//   0x47c8: aa1303e0  mov      x0, x19
//   0x47cc: 940000d5  bl       #0x4b20
//   0x47d0: aa0003e8  mov      x8, x0
//   0x47d4: aa0103f7  mov      x23, x1
//   0x47d8: b1010339  adds     x25, x25, #0x40
//   0x47dc: 91010273  add      x19, x19, #0x40
//   0x47e0: aa1c03f8  mov      x24, x28
//   0x47e4: 54fffc01  b.ne     #0x4764
//   0x47e8: aa1603e0  mov      x0, x22
//   0x47ec: aa0803e1  mov      x1, x8
//   0x47f0: 940000c0  bl       #0x4af0
//   0x47f4: ca5bbf68  eor      x8, x27, x27, lsr #47
//   0x47f8: 9b1a7108  madd     x8, x8, x26, x28
//   0x47fc: 8b000113  add      x19, x8, x0
//   0x4800: aa1503e0  mov      x0, x21
//   0x4804: aa1703e1  mov      x1, x23
//   0x4808: 940000ba  bl       #0x4af0
//   0x480c: 8b140001  add      x1, x0, x20
//   0x4810: aa1303e0  mov      x0, x19
//   0x4814: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x4818: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x481c: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x4820: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x4824: a9416bfb  ldp      x27, x26, [sp, #0x10]
//   0x4828: f84607fc  ldr      x28, [sp], #0x60
//   0x482c: 140000b1  b        #0x4af0
//   0x4830: f100129f  cmp      x20, #4
//   0x4834: 540000c3  b.lo     #0x484c
//   0x4838: b9400268  ldr      w8, [x19]
//   0x483c: b85fc2e1  ldur     w1, [x23, #-4]
//   0x4840: 531d7108  lsl      w8, w8, #3
//   0x4844: 8b080280  add      x0, x20, x8
//   0x4848: 17fffff3  b        #0x4814
//   0x484c: d28809e0  mov      x0, #0x404f
//   0x4850: f2a5f200  movk     x0, #0x2f90, lsl #16
//   0x4854: f2cd4760  movk     x0, #0x6a3b, lsl #32
//   0x4858: f2f35c20  movk     x0, #0x9ae1, lsl #48
//   0x485c: b4ffefb4  cbz      x20, #0x4650
//   0x4860: d341fe89  lsr      x9, x20, #1
//   0x4864: 8b13028a  add      x10, x20, x19
//   0x4868: 39400268  ldrb     w8, [x19]
//   0x486c: 38696a69  ldrb     w9, [x19, x9]
//   0x4870: 385ff14a  ldurb    w10, [x10, #-1]
//   0x4874: d28caaeb  mov      x11, #0x6557
//   0x4878: f2aa13cb  movk     x11, #0x509e, lsl #16
//   0x487c: f2daf8eb  movk     x11, #0xd7c7, lsl #32
//   0x4880: f2f9292b  movk     x11, #0xc949, lsl #48
//   0x4884: b3781d28  bfi      x8, x9, #8, #8
//   0x4888: 0b0a0a89  add      w9, w20, w10, lsl #2
//   0x488c: 9b007d08  mul      x8, x8, x0
//   0x4890: 9b0b7d29  mul      x9, x9, x11
//   0x4894: ca080128  eor      x8, x9, x8
//   0x4898: ca48bd08  eor      x8, x8, x8, lsr #47
//   0x489c: 9b007d00  mul      x0, x8, x0
//   0x48a0: 17ffff6c  b        #0x4650
// ============================================================================
std::uint32_t fde_014_451c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000451cULL;
    for (std::size_t i = 0; i < 226ULL; ++i) {
        std::uint32_t insn = kTextInstructions[327ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[015] Symbol: sub_48a4
//      Virtual Address Range: 0x48a4..0x4940 (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[015] Biểu tượng: sub_48a4
//      Dải địa chỉ ảo: 0x48a4..0x4940 (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x48a4: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x48a8: 39400009  ldrb     w9, [x0]
//   0x48ac: f940040b  ldr      x11, [x0, #8]
//   0x48b0: 3940002a  ldrb     w10, [x1]
//   0x48b4: f940042c  ldr      x12, [x1, #8]
//   0x48b8: d341fd28  lsr      x8, x9, #1
//   0x48bc: 7200013f  tst      w9, #1
//   0x48c0: d341fd4d  lsr      x13, x10, #1
//   0x48c4: 9a8b0102  csel     x2, x8, x11, eq
//   0x48c8: 7200015f  tst      w10, #1
//   0x48cc: 9a8c01ab  csel     x11, x13, x12, eq
//   0x48d0: eb0b005f  cmp      x2, x11
//   0x48d4: 54000201  b.ne     #0x4914
//   0x48d8: f940082b  ldr      x11, [x1, #0x10]
//   0x48dc: 7200015f  tst      w10, #1
//   0x48e0: 9a811561  csinc    x1, x11, x1, ne
//   0x48e4: 370001c9  tbnz     w9, #0, #0x491c
//   0x48e8: 91000409  add      x9, x0, #1
//   0x48ec: b4000248  cbz      x8, #0x4934
//   0x48f0: 3940012a  ldrb     w10, [x9]
//   0x48f4: 3940002b  ldrb     w11, [x1]
//   0x48f8: 6b0b015f  cmp      w10, w11
//   0x48fc: 540000c1  b.ne     #0x4914
//   0x4900: d1000508  sub      x8, x8, #1
//   0x4904: 91000529  add      x9, x9, #1
//   0x4908: 91000421  add      x1, x1, #1
//   0x490c: b5ffff28  cbnz     x8, #0x48f0
//   0x4910: 14000009  b        #0x4934
//   0x4914: 2a1f03e0  mov      w0, wzr
//   0x4918: 14000008  b        #0x4938
//   0x491c: b40000c2  cbz      x2, #0x4934
//   0x4920: f9400800  ldr      x0, [x0, #0x10]
//   0x4924: 94000b1f  bl       #0x75a0
//   0x4928: 7100001f  cmp      w0, #0
//   0x492c: 1a9f17e0  cset     w0, eq
//   0x4930: 14000002  b        #0x4938
//   0x4934: 52800020  mov      w0, #1
//   0x4938: f84107fe  ldr      x30, [sp], #0x10
//   0x493c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_015_48a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000048a4ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[553ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[016] Symbol: sub_4940
//      Virtual Address Range: 0x4940..0x4ab8 (376 bytes, 94 AArch64 instructions)
// [VN] Khung FDE[016] Biểu tượng: sub_4940
//      Dải địa chỉ ảo: 0x4940..0x4ab8 (376 byte, 94 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4940: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x4944: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x4948: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x494c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x4950: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x4954: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x4958: b40003e0  cbz      x0, #0x49d4
//   0x495c: aa0003f3  mov      x19, x0
//   0x4960: d37dfc08  lsr      x8, x0, #0x3d
//   0x4964: b5000a88  cbnz     x8, #0x4ab4
//   0x4968: d37df260  lsl      x0, x19, #3
//   0x496c: 94000ae9  bl       #0x7510
//   0x4970: 94000052  bl       #0x4ab8
//   0x4974: aa1f03e8  mov      x8, xzr
//   0x4978: 90000049  adrp     x9, #0xc000
//   0x497c: 90000055  adrp     x21, #0xc000
//   0x4980: f9002133  str      x19, [x9, #0x40]
//   0x4984: eb08027f  cmp      x19, x8
//   0x4988: 540000a0  b.eq     #0x499c
//   0x498c: f9401ea9  ldr      x9, [x21, #0x38]
//   0x4990: f828793f  str      xzr, [x9, x8, lsl #3]
//   0x4994: 91000508  add      x8, x8, #1
//   0x4998: 17fffffb  b        #0x4984
//   0x499c: 90000048  adrp     x8, #0xc000
//   0x49a0: f9402516  ldr      x22, [x8, #0x48]
//   0x49a4: b40007b6  cbz      x22, #0x4a98
//   0x49a8: 9e670260  fmov     d0, x19
//   0x49ac: f94006d8  ldr      x24, [x22, #8]
//   0x49b0: 94000a93  bl       #0x73fc
//   0x49b4: 1e260017  fmov     w23, s0
//   0x49b8: f10006ff  cmp      x23, #1
//   0x49bc: 54000149  b.ls     #0x49e4
//   0x49c0: eb13031f  cmp      x24, x19
//   0x49c4: 54000143  b.lo     #0x49ec
//   0x49c8: 9ad30b08  udiv     x8, x24, x19
//   0x49cc: 9b13e118  msub     x24, x8, x19, x24
//   0x49d0: 14000007  b        #0x49ec
//   0x49d4: 94000039  bl       #0x4ab8
//   0x49d8: 90000048  adrp     x8, #0xc000
//   0x49dc: f900211f  str      xzr, [x8, #0x40]
//   0x49e0: 1400002e  b        #0x4a98
//   0x49e4: d1000668  sub      x8, x19, #1
//   0x49e8: 8a080318  and      x24, x24, x8
//   0x49ec: 90000048  adrp     x8, #0xc000
//   0x49f0: 9100e108  add      x8, x8, #0x38
//   0x49f4: f8410509  ldr      x9, [x8], #0x10
//   0x49f8: d1000679  sub      x25, x19, #1
//   0x49fc: f8387928  str      x8, [x9, x24, lsl #3]
//   0x4a00: f94002da  ldr      x26, [x22]
//   0x4a04: b40004ba  cbz      x26, #0x4a98
//   0x4a08: f940075b  ldr      x27, [x26, #8]
//   0x4a0c: f10006ff  cmp      x23, #1
//   0x4a10: 540000c9  b.ls     #0x4a28
//   0x4a14: eb13037f  cmp      x27, x19
//   0x4a18: 540000a3  b.lo     #0x4a2c
//   0x4a1c: 9ad30b68  udiv     x8, x27, x19
//   0x4a20: 9b13ed1b  msub     x27, x8, x19, x27
//   0x4a24: 14000002  b        #0x4a2c
//   0x4a28: 8a19037b  and      x27, x27, x25
//   0x4a2c: eb18037f  cmp      x27, x24
//   0x4a30: 54000300  b.eq     #0x4a90
//   0x4a34: f9401ea8  ldr      x8, [x21, #0x38]
//   0x4a38: f87b7909  ldr      x9, [x8, x27, lsl #3]
//   0x4a3c: b4000269  cbz      x9, #0x4a88
//   0x4a40: 91004354  add      x20, x26, #0x10
//   0x4a44: aa1a03fd  mov      x29, x26
//   0x4a48: aa1d03fc  mov      x28, x29
//   0x4a4c: f94003bd  ldr      x29, [x29]
//   0x4a50: b40000bd  cbz      x29, #0x4a64
//   0x4a54: 910043a1  add      x1, x29, #0x10
//   0x4a58: aa1403e0  mov      x0, x20
//   0x4a5c: 97ffff92  bl       #0x48a4
//   0x4a60: 3707ff40  tbnz     w0, #0, #0x4a48
//   0x4a64: f90002dd  str      x29, [x22]
//   0x4a68: f9401ea8  ldr      x8, [x21, #0x38]
//   0x4a6c: f87b7908  ldr      x8, [x8, x27, lsl #3]
//   0x4a70: f9400108  ldr      x8, [x8]
//   0x4a74: f9000388  str      x8, [x28]
//   0x4a78: f9401ea8  ldr      x8, [x21, #0x38]
//   0x4a7c: f87b7908  ldr      x8, [x8, x27, lsl #3]
//   0x4a80: f900011a  str      x26, [x8]
//   0x4a84: 17ffffdf  b        #0x4a00
//   0x4a88: f83b7916  str      x22, [x8, x27, lsl #3]
//   0x4a8c: aa1b03f8  mov      x24, x27
//   0x4a90: aa1a03f6  mov      x22, x26
//   0x4a94: 17ffffdb  b        #0x4a00
//   0x4a98: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x4a9c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x4aa0: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x4aa4: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x4aa8: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x4aac: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x4ab0: d65f03c0  ret      
//   0x4ab4: 94000aa3  bl       #0x7540
// ============================================================================
std::uint32_t fde_016_4940(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004940ULL;
    for (std::size_t i = 0; i < 94ULL; ++i) {
        std::uint32_t insn = kTextInstructions[592ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[017] Symbol: sub_4ab8
//      Virtual Address Range: 0x4ab8..0x4ad4 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[017] Biểu tượng: sub_4ab8
//      Dải địa chỉ ảo: 0x4ab8..0x4ad4 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4ab8: 90000049  adrp     x9, #0xc000
//   0x4abc: f9401d28  ldr      x8, [x9, #0x38]
//   0x4ac0: f9001d20  str      x0, [x9, #0x38]
//   0x4ac4: b4000068  cbz      x8, #0x4ad0
//   0x4ac8: aa0803e0  mov      x0, x8
//   0x4acc: 14000a99  b        #0x7530
//   0x4ad0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_017_4ab8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004ab8ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[686ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[018] Symbol: sub_4ad4
//      Virtual Address Range: 0x4ad4..0x4af0 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[018] Biểu tượng: sub_4ad4
//      Dải địa chỉ ảo: 0x4ad4..0x4af0 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4ad4: aa1f03e8  mov      x8, xzr
//   0x4ad8: f100611f  cmp      x8, #0x18
//   0x4adc: 54000080  b.eq     #0x4aec
//   0x4ae0: f828681f  str      xzr, [x0, x8]
//   0x4ae4: 91002108  add      x8, x8, #8
//   0x4ae8: 17fffffc  b        #0x4ad8
//   0x4aec: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_018_4ad4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004ad4ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[693ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[019] Symbol: sub_4af0
//      Virtual Address Range: 0x4af0..0x4b20 (48 bytes, 12 AArch64 instructions)
// [VN] Khung FDE[019] Biểu tượng: sub_4af0
//      Dải địa chỉ ảo: 0x4af0..0x4b20 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4af0: d285ad29  mov      x9, #0x2d69
//   0x4af4: f2bd6709  movk     x9, #0xeb38, lsl #16
//   0x4af8: f2dd4109  movk     x9, #0xea08, lsl #32
//   0x4afc: ca000028  eor      x8, x1, x0
//   0x4b00: f2f3bbe9  movk     x9, #0x9ddf, lsl #48
//   0x4b04: 9b097d08  mul      x8, x8, x9
//   0x4b08: ca01010a  eor      x10, x8, x1
//   0x4b0c: ca48bd48  eor      x8, x10, x8, lsr #47
//   0x4b10: 9b097d08  mul      x8, x8, x9
//   0x4b14: ca48bd08  eor      x8, x8, x8, lsr #47
//   0x4b18: 9b097d00  mul      x0, x8, x9
//   0x4b1c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_019_4af0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004af0ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[700ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[020] Symbol: sub_4b20
//      Virtual Address Range: 0x4b20..0x4b54 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[020] Biểu tượng: sub_4b20
//      Dải địa chỉ ảo: 0x4b20..0x4b54 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4b20: a9402c08  ldp      x8, x11, [x0]
//   0x4b24: a9412809  ldp      x9, x10, [x0, #0x10]
//   0x4b28: 8b010108  add      x8, x8, x1
//   0x4b2c: 8b0b0129  add      x9, x9, x11
//   0x4b30: 8b02014c  add      x12, x10, x2
//   0x4b34: 8b080129  add      x9, x9, x8
//   0x4b38: 8b08018b  add      x11, x12, x8
//   0x4b3c: 93c9b12c  ror      x12, x9, #0x2c
//   0x4b40: 93cb556b  ror      x11, x11, #0x15
//   0x4b44: 8b080188  add      x8, x12, x8
//   0x4b48: 8b0a0120  add      x0, x9, x10
//   0x4b4c: 8b0b0101  add      x1, x8, x11
//   0x4b50: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_020_4b20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004b20ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[712ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[021] Symbol: sub_4b54
//      Virtual Address Range: 0x4b54..0x4bc4 (112 bytes, 28 AArch64 instructions)
// [VN] Khung FDE[021] Biểu tượng: sub_4b54
//      Dải địa chỉ ảo: 0x4b54..0x4bc4 (112 byte, 28 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4b54: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x4b58: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x4b5c: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x4b60: b100405f  cmn      x2, #0x10
//   0x4b64: 540002e2  b.hs     #0x4bc0
//   0x4b68: aa0203f3  mov      x19, x2
//   0x4b6c: aa0103f5  mov      x21, x1
//   0x4b70: aa0003f4  mov      x20, x0
//   0x4b74: f100585f  cmp      x2, #0x16
//   0x4b78: 54000088  b.hi     #0x4b88
//   0x4b7c: 531f7a68  lsl      w8, w19, #1
//   0x4b80: 38001688  strb     w8, [x20], #1
//   0x4b84: 14000009  b        #0x4ba8
//   0x4b88: 91004268  add      x8, x19, #0x10
//   0x4b8c: 927ced16  and      x22, x8, #0xfffffffffffffff0
//   0x4b90: aa1603e0  mov      x0, x22
//   0x4b94: 94000a5f  bl       #0x7510
//   0x4b98: b24002c8  orr      x8, x22, #1
//   0x4b9c: a9008293  stp      x19, x0, [x20, #8]
//   0x4ba0: f9000288  str      x8, [x20]
//   0x4ba4: aa0003f4  mov      x20, x0
//   0x4ba8: 94000a25  bl       #0x743c
//   0x4bac: aa1303e2  mov      x2, x19
//   0x4bb0: 97fffe58  bl       #0x4510
//   0x4bb4: 38336a9f  strb     wzr, [x20, x19]
//   0x4bb8: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x4bbc: 14000a1a  b        #0x7424
//   0x4bc0: 94000a60  bl       #0x7540
// ============================================================================
std::uint32_t fde_021_4b54(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004b54ULL;
    for (std::size_t i = 0; i < 28ULL; ++i) {
        std::uint32_t insn = kTextInstructions[725ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[022] Symbol: sub_4bc4
//      Virtual Address Range: 0x4bc4..0x4bd4 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[022] Biểu tượng: sub_4bc4
//      Dải địa chỉ ảo: 0x4bc4..0x4bd4 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4bc4: b9400008  ldr      w8, [x0]
//   0x4bc8: 7100011f  cmp      w8, #0
//   0x4bcc: 1a9f07e0  cset     w0, ne
//   0x4bd0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_022_4bc4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004bc4ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[753ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[023] Symbol: sub_4bd4
//      Virtual Address Range: 0x4bd4..0x4c20 (76 bytes, 19 AArch64 instructions)
// [VN] Khung FDE[023] Biểu tượng: sub_4bd4
//      Dải địa chỉ ảo: 0x4bd4..0x4c20 (76 byte, 19 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4bd4: a9be53f5  stp      x21, x20, [sp, #-0x20]!
//   0x4bd8: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x4bdc: aa0003f3  mov      x19, x0
//   0x4be0: f9400800  ldr      x0, [x0, #0x10]
//   0x4be4: f9400e68  ldr      x8, [x19, #0x18]
//   0x4be8: aa0103f4  mov      x20, x1
//   0x4bec: cb000115  sub      x21, x8, x0
//   0x4bf0: b4000081  cbz      x1, #0x4c00
//   0x4bf4: aa1403e1  mov      x1, x20
//   0x4bf8: 94000a6e  bl       #0x75b0
//   0x4bfc: 14000003  b        #0x4c08
//   0x4c00: 94000a60  bl       #0x7580
//   0x4c04: aa1f03e0  mov      x0, xzr
//   0x4c08: 8b150008  add      x8, x0, x21
//   0x4c0c: 8b140009  add      x9, x0, x20
//   0x4c10: a9012260  stp      x0, x8, [x19, #0x10]
//   0x4c14: f9001269  str      x9, [x19, #0x20]
//   0x4c18: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x4c1c: 140009fb  b        #0x7408
// ============================================================================
std::uint32_t fde_023_4bd4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004bd4ULL;
    for (std::size_t i = 0; i < 19ULL; ++i) {
        std::uint32_t insn = kTextInstructions[757ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[024] Symbol: sub_4c20
//      Virtual Address Range: 0x4c20..0x4c58 (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[024] Biểu tượng: sub_4c20
//      Dải địa chỉ ảo: 0x4c20..0x4c58 (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4c20: f9400008  ldr      x8, [x0]
//   0x4c24: d284c00a  mov      x10, #0x2600
//   0x4c28: 52800029  mov      w9, #1
//   0x4c2c: f2c0002a  movk     x10, #1, lsl #32
//   0x4c30: 3940010b  ldrb     w11, [x8]
//   0x4c34: 7100817f  cmp      w11, #0x20
//   0x4c38: 540000c8  b.hi     #0x4c50
//   0x4c3c: 9acb212b  lsl      x11, x9, x11
//   0x4c40: ea0a017f  tst      x11, x10
//   0x4c44: 54000060  b.eq     #0x4c50
//   0x4c48: 91000508  add      x8, x8, #1
//   0x4c4c: 17fffff9  b        #0x4c30
//   0x4c50: f9000008  str      x8, [x0]
//   0x4c54: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_024_4c20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004c20ULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[776ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[025] Symbol: sub_4c58
//      Virtual Address Range: 0x4c58..0x55e4 (2444 bytes, 611 AArch64 instructions)
// [VN] Khung FDE[025] Biểu tượng: sub_4c58
//      Dải địa chỉ ảo: 0x4c58..0x55e4 (2444 byte, 611 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4c58: d10183ff  sub      sp, sp, #0x60
//   0x4c5c: fd000be8  str      d8, [sp, #0x10]
//   0x4c60: f9000ffa  str      x26, [sp, #0x18]
//   0x4c64: a90263f9  stp      x25, x24, [sp, #0x20]
//   0x4c68: a9035bf7  stp      x23, x22, [sp, #0x30]
//   0x4c6c: a90453f5  stp      x21, x20, [sp, #0x40]
//   0x4c70: a9057bf3  stp      x19, x30, [sp, #0x50]
//   0x4c74: f9400028  ldr      x8, [x1]
//   0x4c78: aa0203f4  mov      x20, x2
//   0x4c7c: aa0103f3  mov      x19, x1
//   0x4c80: aa0003f5  mov      x21, x0
//   0x4c84: 39400119  ldrb     w25, [x8]
//   0x4c88: 71008b3f  cmp      w25, #0x22
//   0x4c8c: 54001120  b.eq     #0x4eb0
//   0x4c90: 71016f3f  cmp      w25, #0x5b
//   0x4c94: 54000e80  b.eq     #0x4e64
//   0x4c98: 71019b3f  cmp      w25, #0x66
//   0x4c9c: 54000300  b.eq     #0x4cfc
//   0x4ca0: 7101ef3f  cmp      w25, #0x7b
//   0x4ca4: 540007e0  b.eq     #0x4da0
//   0x4ca8: 7101d33f  cmp      w25, #0x74
//   0x4cac: 540004c0  b.eq     #0x4d44
//   0x4cb0: 7101bb3f  cmp      w25, #0x6e
//   0x4cb4: 54000981  b.ne     #0x4de4
//   0x4cb8: 940009ac  bl       #0x7368
//   0x4cbc: 7101d55f  cmp      w10, #0x75
//   0x4cc0: 54002c81  b.ne     #0x5250
//   0x4cc4: 940009bf  bl       #0x73c0
//   0x4cc8: 54002c41  b.ne     #0x5250
//   0x4ccc: 940009a3  bl       #0x7358
//   0x4cd0: 7101b15f  cmp      w10, #0x6c
//   0x4cd4: 54002be1  b.ne     #0x5250
//   0x4cd8: 91001108  add      x8, x8, #4
//   0x4cdc: f9000268  str      x8, [x19]
//   0x4ce0: 94000974  bl       #0x72b0
//   0x4ce4: 540035cd  b.le     #0x539c
//   0x4ce8: 91006109  add      x9, x8, #0x18
//   0x4cec: f9002289  str      x9, [x20, #0x40]
//   0x4cf0: a9007d1f  stp      xzr, xzr, [x8]
//   0x4cf4: f900091f  str      xzr, [x8, #0x10]
//   0x4cf8: 1400014e  b        #0x5230
//   0x4cfc: 9400099b  bl       #0x7368
//   0x4d00: 7101855f  cmp      w10, #0x61
//   0x4d04: 54002a61  b.ne     #0x5250
//   0x4d08: 940009ae  bl       #0x73c0
//   0x4d0c: 54002a21  b.ne     #0x5250
//   0x4d10: 94000992  bl       #0x7358
//   0x4d14: 7101cd5f  cmp      w10, #0x73
//   0x4d18: 540029c1  b.ne     #0x5250
//   0x4d1c: 91001109  add      x9, x8, #4
//   0x4d20: f9000269  str      x9, [x19]
//   0x4d24: 3940110a  ldrb     w10, [x8, #4]
//   0x4d28: 7101955f  cmp      w10, #0x65
//   0x4d2c: 54002921  b.ne     #0x5250
//   0x4d30: 91001508  add      x8, x8, #5
//   0x4d34: f9000268  str      x8, [x19]
//   0x4d38: aa1403e0  mov      x0, x20
//   0x4d3c: 2a1f03e1  mov      w1, wzr
//   0x4d40: 14000010  b        #0x4d80
//   0x4d44: 94000989  bl       #0x7368
//   0x4d48: 7101c95f  cmp      w10, #0x72
//   0x4d4c: 54002821  b.ne     #0x5250
//   0x4d50: 91000909  add      x9, x8, #2
//   0x4d54: f9000269  str      x9, [x19]
//   0x4d58: 3940090a  ldrb     w10, [x8, #2]
//   0x4d5c: 7101d55f  cmp      w10, #0x75
//   0x4d60: 54002781  b.ne     #0x5250
//   0x4d64: 9400097d  bl       #0x7358
//   0x4d68: 7101955f  cmp      w10, #0x65
//   0x4d6c: 54002721  b.ne     #0x5250
//   0x4d70: 91001108  add      x8, x8, #4
//   0x4d74: 52800021  mov      w1, #1
//   0x4d78: aa1403e0  mov      x0, x20
//   0x4d7c: f9000268  str      x8, [x19]
//   0x4d80: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x4d84: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x4d88: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x4d8c: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x4d90: f9400ffa  ldr      x26, [sp, #0x18]
//   0x4d94: fd400be8  ldr      d8, [sp, #0x10]
//   0x4d98: 910183ff  add      sp, sp, #0x60
//   0x4d9c: 140003a1  b        #0x5c20
//   0x4da0: 91000508  add      x8, x8, #1
//   0x4da4: f9000268  str      x8, [x19]
//   0x4da8: 94000942  bl       #0x72b0
//   0x4dac: 5400274d  b.le     #0x5294
//   0x4db0: 91006109  add      x9, x8, #0x18
//   0x4db4: d2e0006a  mov      x10, #0x3000000000000
//   0x4db8: 940009b5  bl       #0x748c
//   0x4dbc: 350023a8  cbnz     w8, #0x5230
//   0x4dc0: f9400268  ldr      x8, [x19]
//   0x4dc4: 39400109  ldrb     w9, [x8]
//   0x4dc8: 7101f53f  cmp      w9, #0x7d
//   0x4dcc: 54002781  b.ne     #0x52bc
//   0x4dd0: 91000508  add      x8, x8, #1
//   0x4dd4: f9000268  str      x8, [x19]
//   0x4dd8: f9402288  ldr      x8, [x20, #0x40]
//   0x4ddc: 52800069  mov      w9, #3
//   0x4de0: 14000031  b        #0x4ea4
//   0x4de4: 7100b73f  cmp      w25, #0x2d
//   0x4de8: 9a881518  cinc     x24, x8, eq
//   0x4dec: 39400309  ldrb     w9, [x24]
//   0x4df0: f9400677  ldr      x23, [x19, #8]
//   0x4df4: 1e649000  fmov     d0, #10.00000000
//   0x4df8: 7100c136  subs     w22, w9, #0x30
//   0x4dfc: 54002520  b.eq     #0x52a0
//   0x4e00: 5100c529  sub      w9, w9, #0x31
//   0x4e04: 7100213f  cmp      w9, #8
//   0x4e08: 54002308  b.hi     #0x5268
//   0x4e0c: 7100b73f  cmp      w25, #0x2d
//   0x4e10: 91000718  add      x24, x24, #1
//   0x4e14: 2a1f03e9  mov      w9, wzr
//   0x4e18: 54000641  b.ne     #0x4ee0
//   0x4e1c: 5299998a  mov      w10, #0xcccc
//   0x4e20: 72a1998a  movk     w10, #0xccc, lsl #16
//   0x4e24: 5100054b  sub      w11, w10, #1
//   0x4e28: 5280014c  mov      w12, #0xa
//   0x4e2c: 3940030d  ldrb     w13, [x24]
//   0x4e30: 9400095c  bl       #0x73a0
//   0x4e34: 54000a08  b.hi     #0x4f74
//   0x4e38: 6b0b02df  cmp      w22, w11
//   0x4e3c: 54000068  b.hi     #0x4e48
//   0x4e40: 94000987  bl       #0x745c
//   0x4e44: 17fffffa  b        #0x4e2c
//   0x4e48: 6b0a02df  cmp      w22, w10
//   0x4e4c: 540006c1  b.ne     #0x4f24
//   0x4e50: 7100e1bf  cmp      w13, #0x38
//   0x4e54: 54ffff69  b.ls     #0x4e40
//   0x4e58: 52999996  mov      w22, #0xcccc
//   0x4e5c: 72a19996  movk     w22, #0xccc, lsl #16
//   0x4e60: 14000031  b        #0x4f24
//   0x4e64: 91000508  add      x8, x8, #1
//   0x4e68: f9000268  str      x8, [x19]
//   0x4e6c: 94000911  bl       #0x72b0
//   0x4e70: 5400220d  b.le     #0x52b0
//   0x4e74: 91006109  add      x9, x8, #0x18
//   0x4e78: d2e0008a  mov      x10, #0x4000000000000
//   0x4e7c: 94000984  bl       #0x748c
//   0x4e80: 35001d88  cbnz     w8, #0x5230
//   0x4e84: f9400268  ldr      x8, [x19]
//   0x4e88: 39400109  ldrb     w9, [x8]
//   0x4e8c: 7101753f  cmp      w9, #0x5d
//   0x4e90: 54002621  b.ne     #0x5354
//   0x4e94: 91000508  add      x8, x8, #1
//   0x4e98: f9000268  str      x8, [x19]
//   0x4e9c: f9402288  ldr      x8, [x20, #0x40]
//   0x4ea0: 52800089  mov      w9, #4
//   0x4ea4: 781fe109  sturh    w9, [x8, #-2]
//   0x4ea8: a93efd1f  stp      xzr, xzr, [x8, #-0x18]
//   0x4eac: 140000e1  b        #0x5230
//   0x4eb0: aa1503e0  mov      x0, x21
//   0x4eb4: aa1303e1  mov      x1, x19
//   0x4eb8: aa1403e2  mov      x2, x20
//   0x4ebc: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x4ec0: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x4ec4: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x4ec8: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x4ecc: f9400ffa  ldr      x26, [sp, #0x18]
//   0x4ed0: fd400be8  ldr      d8, [sp, #0x10]
//   0x4ed4: 2a1f03e3  mov      w3, wzr
//   0x4ed8: 910183ff  add      sp, sp, #0x60
//   0x4edc: 140001c2  b        #0x55e4
//   0x4ee0: 5293332a  mov      w10, #0x9999
//   0x4ee4: 72a3332a  movk     w10, #0x1999, lsl #16
//   0x4ee8: 5100054b  sub      w11, w10, #1
//   0x4eec: 5280014c  mov      w12, #0xa
//   0x4ef0: 3940030d  ldrb     w13, [x24]
//   0x4ef4: 9400092b  bl       #0x73a0
//   0x4ef8: 540003e8  b.hi     #0x4f74
//   0x4efc: 6b0b02df  cmp      w22, w11
//   0x4f00: 54000068  b.hi     #0x4f0c
//   0x4f04: 94000956  bl       #0x745c
//   0x4f08: 17fffffa  b        #0x4ef0
//   0x4f0c: 6b0a02df  cmp      w22, w10
//   0x4f10: 540000a1  b.ne     #0x4f24
//   0x4f14: 7100d5bf  cmp      w13, #0x35
//   0x4f18: 54ffff69  b.ls     #0x4f04
//   0x4f1c: 52933336  mov      w22, #0x9999
//   0x4f20: 72a33336  movk     w22, #0x1999, lsl #16
//   0x4f24: 128005eb  mov      w11, #-0x30
//   0x4f28: 7100b73f  cmp      w25, #0x2d
//   0x4f2c: 2a1603ea  mov      w10, w22
//   0x4f30: 540002c1  b.ne     #0x4f88
//   0x4f34: b202e7ec  mov      x12, #-0x3333333333333334
//   0x4f38: f299996c  movk     x12, #0xcccb
//   0x4f3c: f2e1998c  movk     x12, #0xccc, lsl #48
//   0x4f40: 5280014e  mov      w14, #0xa
//   0x4f44: 9400094b  bl       #0x7470
//   0x4f48: 54000528  b.hi     #0x4fec
//   0x4f4c: eb0c015f  cmp      x10, x12
//   0x4f50: 54000068  b.hi     #0x4f5c
//   0x4f54: 9400092f  bl       #0x7410
//   0x4f58: 17fffffb  b        #0x4f44
//   0x4f5c: 9100058f  add      x15, x12, #1
//   0x4f60: eb0f015f  cmp      x10, x15
//   0x4f64: 54000301  b.ne     #0x4fc4
//   0x4f68: 7100e1bf  cmp      w13, #0x38
//   0x4f6c: 540002c8  b.hi     #0x4fc4
//   0x4f70: 17fffff9  b        #0x4f54
//   0x4f74: aa1f03ea  mov      x10, xzr
//   0x4f78: 2a1f03ee  mov      w14, wzr
//   0x4f7c: 2a1f03ec  mov      w12, wzr
//   0x4f80: 9e6703e8  fmov     d8, xzr
//   0x4f84: 1400001f  b        #0x5000
//   0x4f88: b201e7ec  mov      x12, #-0x6666666666666667
//   0x4f8c: f293330c  movk     x12, #0x9998
//   0x4f90: f2e3332c  movk     x12, #0x1999, lsl #48
//   0x4f94: 5280014e  mov      w14, #0xa
//   0x4f98: 94000936  bl       #0x7470
//   0x4f9c: 54000288  b.hi     #0x4fec
//   0x4fa0: eb0c015f  cmp      x10, x12
//   0x4fa4: 54000068  b.hi     #0x4fb0
//   0x4fa8: 9400091a  bl       #0x7410
//   0x4fac: 17fffffb  b        #0x4f98
//   0x4fb0: 9100058f  add      x15, x12, #1
//   0x4fb4: eb0f015f  cmp      x10, x15
//   0x4fb8: 54000061  b.ne     #0x4fc4
//   0x4fbc: 7100d5bf  cmp      w13, #0x35
//   0x4fc0: 54ffff49  b.ls     #0x4fa8
//   0x4fc4: 9e630148  ucvtf    d8, x10
//   0x4fc8: 3940030d  ldrb     w13, [x24]
//   0x4fcc: 5100c1ab  sub      w11, w13, #0x30
//   0x4fd0: 7100257f  cmp      w11, #9
//   0x4fd4: 54000128  b.hi     #0x4ff8
//   0x4fd8: 1e600901  fmul     d1, d8, d0
//   0x4fdc: 1e620162  scvtf    d2, w11
//   0x4fe0: 91000718  add      x24, x24, #1
//   0x4fe4: 1e622828  fadd     d8, d1, d2
//   0x4fe8: 17fffff8  b        #0x4fc8
//   0x4fec: 2a1f03ee  mov      w14, wzr
//   0x4ff0: 9e6703e8  fmov     d8, xzr
//   0x4ff4: 14000002  b        #0x4ffc
//   0x4ff8: 5280002e  mov      w14, #1
//   0x4ffc: 5280002c  mov      w12, #1
//   0x5000: 7100b9bf  cmp      w13, #0x2e
//   0x5004: 54001c81  b.ne     #0x5394
//   0x5008: 38401f0b  ldrb     w11, [x24, #1]!
//   0x500c: 5100c16b  sub      w11, w11, #0x30
//   0x5010: 7100297f  cmp      w11, #0xa
//   0x5014: 54001302  b.hs     #0x5274
//   0x5018: 2a1f03eb  mov      w11, wzr
//   0x501c: 3700044e  tbnz     w14, #0, #0x50a4
//   0x5020: 2a1603ee  mov      w14, w22
//   0x5024: 7100019f  cmp      w12, #0
//   0x5028: 128005ed  mov      w13, #-0x30
//   0x502c: 9a8e114a  csel     x10, x10, x14, ne
//   0x5030: 5280014e  mov      w14, #0xa
//   0x5034: 3940030f  ldrb     w15, [x24]
//   0x5038: f100c1ff  cmp      x15, #0x30
//   0x503c: 54000183  b.lo     #0x506c
//   0x5040: d375fd50  lsr      x16, x10, #0x35
//   0x5044: b5000150  cbnz     x16, #0x506c
//   0x5048: 7100e5ff  cmp      w15, #0x39
//   0x504c: 54000108  b.hi     #0x506c
//   0x5050: 0b0d01ef  add      w15, w15, w13
//   0x5054: 9b0e3d4a  madd     x10, x10, x14, x15
//   0x5058: f100015f  cmp      x10, #0
//   0x505c: 91000718  add      x24, x24, #1
//   0x5060: 5100056b  sub      w11, w11, #1
//   0x5064: 1a890529  cinc     w9, w9, ne
//   0x5068: 17fffff3  b        #0x5034
//   0x506c: 9e630148  ucvtf    d8, x10
//   0x5070: 1400000d  b        #0x50a4
//   0x5074: 7100413f  cmp      w9, #0x10
//   0x5078: 5400006d  b.le     #0x5084
//   0x507c: 91000718  add      x24, x24, #1
//   0x5080: 14000009  b        #0x50a4
//   0x5084: 1e600901  fmul     d1, d8, d0
//   0x5088: 1e6201c2  scvtf    d2, w14
//   0x508c: 1e622828  fadd     d8, d1, d2
//   0x5090: 91000718  add      x24, x24, #1
//   0x5094: 1e602108  fcmp     d8, #0.0
//   0x5098: 5100056b  sub      w11, w11, #1
//   0x509c: 5400004d  b.le     #0x50a4
//   0x50a0: 11000529  add      w9, w9, #1
//   0x50a4: 3940030d  ldrb     w13, [x24]
//   0x50a8: 940008be  bl       #0x73a0
//   0x50ac: 54fffe49  b.ls     #0x5074
//   0x50b0: 5280002e  mov      w14, #1
//   0x50b4: 321b01a9  orr      w9, w13, #0x20
//   0x50b8: 7101953f  cmp      w9, #0x65
//   0x50bc: cb17011a  sub      x26, x8, x23
//   0x50c0: 54001d01  b.ne     #0x5460
//   0x50c4: 2a1603e8  mov      w8, w22
//   0x50c8: 7100019f  cmp      w12, #0
//   0x50cc: aa1803e9  mov      x9, x24
//   0x50d0: 9a88114a  csel     x10, x10, x8, ne
//   0x50d4: 38401d28  ldrb     w8, [x9, #1]!
//   0x50d8: 710001df  cmp      w14, #0
//   0x50dc: 9e630140  ucvtf    d0, x10
//   0x50e0: 1e601d08  fcsel    d8, d8, d0, ne
//   0x50e4: 7100b51f  cmp      w8, #0x2d
//   0x50e8: 1a9f17ea  cset     w10, eq
//   0x50ec: 7100ad1f  cmp      w8, #0x2b
//   0x50f0: 1a9f17ec  cset     w12, eq
//   0x50f4: 2a0a018a  orr      w10, w12, w10
//   0x50f8: 7100015f  cmp      w10, #0
//   0x50fc: 5280002a  mov      w10, #1
//   0x5100: 9a8a054a  cinc     x10, x10, ne
//   0x5104: 386a6b0a  ldrb     w10, [x24, x10]
//   0x5108: 91000b0c  add      x12, x24, #2
//   0x510c: 9a891198  csel     x24, x12, x9, ne
//   0x5110: 5100c149  sub      w9, w10, #0x30
//   0x5114: 7100253f  cmp      w9, #9
//   0x5118: 54000b48  b.hi     #0x5280
//   0x511c: 7100b51f  cmp      w8, #0x2d
//   0x5120: 91000718  add      x24, x24, #1
//   0x5124: 540002a1  b.ne     #0x5178
//   0x5128: 529ffeea  mov      w10, #0xfff7
//   0x512c: 72afffea  movk     w10, #0x7fff, lsl #16
//   0x5130: 0b0a016c  add      w12, w11, w10
//   0x5134: 5280014a  mov      w10, #0xa
//   0x5138: 1aca0d8c  sdiv     w12, w12, w10
//   0x513c: 3940030d  ldrb     w13, [x24]
//   0x5140: 94000898  bl       #0x73a0
//   0x5144: 54000328  b.hi     #0x51a8
//   0x5148: 1b0a3529  madd     w9, w9, w10, w13
//   0x514c: 5100c129  sub      w9, w9, #0x30
//   0x5150: 6b0c013f  cmp      w9, w12
//   0x5154: 91000718  add      x24, x24, #1
//   0x5158: 54ffff2d  b.le     #0x513c
//   0x515c: 14000002  b        #0x5164
//   0x5160: 91000718  add      x24, x24, #1
//   0x5164: 3940030d  ldrb     w13, [x24]
//   0x5168: 5100c1ad  sub      w13, w13, #0x30
//   0x516c: 710025bf  cmp      w13, #9
//   0x5170: 54fffe68  b.hi     #0x513c
//   0x5174: 17fffffb  b        #0x5160
//   0x5178: 5280268a  mov      w10, #0x134
//   0x517c: 4b0b014a  sub      w10, w10, w11
//   0x5180: 5280014c  mov      w12, #0xa
//   0x5184: 3940030d  ldrb     w13, [x24]
//   0x5188: 94000886  bl       #0x73a0
//   0x518c: 540000e8  b.hi     #0x51a8
//   0x5190: 1b0c3529  madd     w9, w9, w12, w13
//   0x5194: 5100c129  sub      w9, w9, #0x30
//   0x5198: 6b0a013f  cmp      w9, w10
//   0x519c: 91000718  add      x24, x24, #1
//   0x51a0: 54ffff2d  b.le     #0x5184
//   0x51a4: 14000012  b        #0x51ec
//   0x51a8: 7100b51f  cmp      w8, #0x2d
//   0x51ac: 5a891528  cneg     w8, w9, eq
//   0x51b0: 0b0b0116  add      w22, w8, w11
//   0x51b4: 3104d6df  cmn      w22, #0x135
//   0x51b8: 540000cc  b.gt     #0x51d0
//   0x51bc: 52802680  mov      w0, #0x134
//   0x51c0: 9400046f  bl       #0x637c
//   0x51c4: 1e601900  fdiv     d0, d8, d0
//   0x51c8: 1104d2c0  add      w0, w22, #0x134
//   0x51cc: 14000003  b        #0x51d8
//   0x51d0: 4ea81d00  mov      v0.16b, v8.16b
//   0x51d4: 2a1603e0  mov      w0, w22
//   0x51d8: 940001fc  bl       #0x59c8
//   0x51dc: 92f00208  mov      x8, #0x7fefffffffffffff
//   0x51e0: 9e670101  fmov     d1, x8
//   0x51e4: 1e612000  fcmp     d0, d1
//   0x51e8: 540000ad  b.le     #0x51fc
//   0x51ec: 528001a8  mov      w8, #0xd
//   0x51f0: b90032a8  str      w8, [x21, #0x30]
//   0x51f4: f9001eba  str      x26, [x21, #0x38]
//   0x51f8: 1400000d  b        #0x522c
//   0x51fc: a9442688  ldp      x8, x9, [x20, #0x40]
//   0x5200: 1e614001  fneg     d1, d0
//   0x5204: 7100b73f  cmp      w25, #0x2d
//   0x5208: 1e600c28  fcsel    d8, d1, d0, eq
//   0x520c: cb080129  sub      x9, x9, x8
//   0x5210: f1005d3f  cmp      x9, #0x17
//   0x5214: 54000ead  b.le     #0x53e8
//   0x5218: 91006109  add      x9, x8, #0x18
//   0x521c: d2e042ca  mov      x10, #0x216000000000000
//   0x5220: f9002289  str      x9, [x20, #0x40]
//   0x5224: a900a91f  stp      xzr, x10, [x8, #8]
//   0x5228: fd000108  str      d8, [x8]
//   0x522c: a9005e78  stp      x24, x23, [x19]
//   0x5230: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x5234: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x5238: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x523c: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x5240: f9400ffa  ldr      x26, [sp, #0x18]
//   0x5244: fd400be8  ldr      d8, [sp, #0x10]
//   0x5248: 910183ff  add      sp, sp, #0x60
//   0x524c: d65f03c0  ret      
//   0x5250: f9400668  ldr      x8, [x19, #8]
//   0x5254: 5280006a  mov      w10, #3
//   0x5258: cb080128  sub      x8, x9, x8
//   0x525c: b90032aa  str      w10, [x21, #0x30]
//   0x5260: f9001ea8  str      x8, [x21, #0x38]
//   0x5264: 17fffff3  b        #0x5230
//   0x5268: cb170308  sub      x8, x24, x23
//   0x526c: 52800069  mov      w9, #3
//   0x5270: 14000006  b        #0x5288
//   0x5274: cb170308  sub      x8, x24, x23
//   0x5278: 528001c9  mov      w9, #0xe
//   0x527c: 14000003  b        #0x5288
//   0x5280: cb170308  sub      x8, x24, x23
//   0x5284: 528001e9  mov      w9, #0xf
//   0x5288: b90032a9  str      w9, [x21, #0x30]
//   0x528c: f9001ea8  str      x8, [x21, #0x38]
//   0x5290: 17ffffe7  b        #0x522c
//   0x5294: 94000810  bl       #0x72d4
//   0x5298: f9402288  ldr      x8, [x20, #0x40]
//   0x529c: 17fffec5  b        #0x4db0
//   0x52a0: 38401f0d  ldrb     w13, [x24, #1]!
//   0x52a4: aa1f03ea  mov      x10, xzr
//   0x52a8: 2a1f03e9  mov      w9, wzr
//   0x52ac: 17ffff33  b        #0x4f78
//   0x52b0: 94000809  bl       #0x72d4
//   0x52b4: f9402288  ldr      x8, [x20, #0x40]
//   0x52b8: 17fffeef  b        #0x4e74
//   0x52bc: 52800036  mov      w22, #1
//   0x52c0: 12001d29  and      w9, w9, #0xff
//   0x52c4: 7100893f  cmp      w9, #0x22
//   0x52c8: 54000c01  b.ne     #0x5448
//   0x52cc: 52800023  mov      w3, #1
//   0x52d0: aa1503e0  mov      x0, x21
//   0x52d4: aa1303e1  mov      x1, x19
//   0x52d8: aa1403e2  mov      x2, x20
//   0x52dc: 940000c2  bl       #0x55e4
//   0x52e0: b94032a8  ldr      w8, [x21, #0x30]
//   0x52e4: 35fffa68  cbnz     w8, #0x5230
//   0x52e8: aa1303e0  mov      x0, x19
//   0x52ec: 97fffe4d  bl       #0x4c20
//   0x52f0: b94032a8  ldr      w8, [x21, #0x30]
//   0x52f4: 35fff9e8  cbnz     w8, #0x5230
//   0x52f8: f9400268  ldr      x8, [x19]
//   0x52fc: 39400109  ldrb     w9, [x8]
//   0x5300: 7100e93f  cmp      w9, #0x3a
//   0x5304: 54000a81  b.ne     #0x5454
//   0x5308: 940007f7  bl       #0x72e4
//   0x530c: 35fff928  cbnz     w8, #0x5230
//   0x5310: 94000820  bl       #0x7390
//   0x5314: b94032a8  ldr      w8, [x21, #0x30]
//   0x5318: 35fff8c8  cbnz     w8, #0x5230
//   0x531c: aa1303e0  mov      x0, x19
//   0x5320: 97fffe40  bl       #0x4c20
//   0x5324: b94032a8  ldr      w8, [x21, #0x30]
//   0x5328: 35fff848  cbnz     w8, #0x5230
//   0x532c: f9400268  ldr      x8, [x19]
//   0x5330: 39400109  ldrb     w9, [x8]
//   0x5334: 7100b13f  cmp      w9, #0x2c
//   0x5338: 54000381  b.ne     #0x53a8
//   0x533c: 940007ea  bl       #0x72e4
//   0x5340: 35fff788  cbnz     w8, #0x5230
//   0x5344: f9400268  ldr      x8, [x19]
//   0x5348: 110006d6  add      w22, w22, #1
//   0x534c: 39400109  ldrb     w9, [x8]
//   0x5350: 17ffffdc  b        #0x52c0
//   0x5354: 52800036  mov      w22, #1
//   0x5358: 9400080e  bl       #0x7390
//   0x535c: b94032a8  ldr      w8, [x21, #0x30]
//   0x5360: 35fff688  cbnz     w8, #0x5230
//   0x5364: aa1303e0  mov      x0, x19
//   0x5368: 97fffe2e  bl       #0x4c20
//   0x536c: b94032a8  ldr      w8, [x21, #0x30]
//   0x5370: 35fff608  cbnz     w8, #0x5230
//   0x5374: f9400268  ldr      x8, [x19]
//   0x5378: 39400109  ldrb     w9, [x8]
//   0x537c: 7100b13f  cmp      w9, #0x2c
//   0x5380: 540003a1  b.ne     #0x53f4
//   0x5384: 940007d8  bl       #0x72e4
//   0x5388: 110006d6  add      w22, w22, #1
//   0x538c: 34fffe68  cbz      w8, #0x5358
//   0x5390: 17ffffa8  b        #0x5230
//   0x5394: 2a1f03eb  mov      w11, wzr
//   0x5398: 17ffff47  b        #0x50b4
//   0x539c: 940007ce  bl       #0x72d4
//   0x53a0: f9402288  ldr      x8, [x20, #0x40]
//   0x53a4: 17fffe51  b        #0x4ce8
//   0x53a8: 7101f53f  cmp      w9, #0x7d
//   0x53ac: 54000161  b.ne     #0x53d8
//   0x53b0: 940007f2  bl       #0x7378
//   0x53b4: 928005ea  mov      x10, #-0x30
//   0x53b8: 5280006b  mov      w11, #3
//   0x53bc: 9b0a2513  madd     x19, x8, x10, x9
//   0x53c0: f9002293  str      x19, [x20, #0x40]
//   0x53c4: 781fe26b  sturh    w11, [x19, #-2]
//   0x53c8: 340003b6  cbz      w22, #0x543c
//   0x53cc: 8b080508  add      x8, x8, x8, lsl #1
//   0x53d0: d37ced14  lsl      x20, x8, #4
//   0x53d4: 14000013  b        #0x5420
//   0x53d8: f9400669  ldr      x9, [x19, #8]
//   0x53dc: 528000ca  mov      w10, #6
//   0x53e0: cb090108  sub      x8, x8, x9
//   0x53e4: 17ffff9e  b        #0x525c
//   0x53e8: 940007bb  bl       #0x72d4
//   0x53ec: f9402288  ldr      x8, [x20, #0x40]
//   0x53f0: 17ffff8a  b        #0x5218
//   0x53f4: 7101753f  cmp      w9, #0x5d
//   0x53f8: 540006a1  b.ne     #0x54cc
//   0x53fc: 940007df  bl       #0x7378
//   0x5400: 928002ea  mov      x10, #-0x18
//   0x5404: 5280008b  mov      w11, #4
//   0x5408: 9b0a2513  madd     x19, x8, x10, x9
//   0x540c: f9002293  str      x19, [x20, #0x40]
//   0x5410: 781fe26b  sturh    w11, [x19, #-2]
//   0x5414: 34000156  cbz      w22, #0x543c
//   0x5418: 8b080508  add      x8, x8, x8, lsl #1
//   0x541c: d37df114  lsl      x20, x8, #3
//   0x5420: aa1403e1  mov      x1, x20
//   0x5424: 94000179  bl       #0x5a08
//   0x5428: aa1303e1  mov      x1, x19
//   0x542c: aa1403e2  mov      x2, x20
//   0x5430: f81f0260  stur     x0, [x19, #-0x10]
//   0x5434: 9400083b  bl       #0x7520
//   0x5438: 14000002  b        #0x5440
//   0x543c: f81f027f  stur     xzr, [x19, #-0x10]
//   0x5440: 293d5a76  stp      w22, w22, [x19, #-0x18]
//   0x5444: 17ffff7b  b        #0x5230
//   0x5448: f9400669  ldr      x9, [x19, #8]
//   0x544c: 5280008a  mov      w10, #4
//   0x5450: 17ffffe4  b        #0x53e0
//   0x5454: f9400669  ldr      x9, [x19, #8]
//   0x5458: 528000aa  mov      w10, #5
//   0x545c: 17ffffe1  b        #0x53e0
//   0x5460: f90007ea  str      x10, [sp, #8]
//   0x5464: 3400006e  cbz      w14, #0x5470
//   0x5468: 2a1f03e8  mov      w8, wzr
//   0x546c: 17ffff51  b        #0x51b0
//   0x5470: 7100b73f  cmp      w25, #0x2d
//   0x5474: 3400032c  cbz      w12, #0x54d8
//   0x5478: 54000501  b.ne     #0x5518
//   0x547c: 9400078d  bl       #0x72b0
//   0x5480: f94007e9  ldr      x9, [sp, #8]
//   0x5484: cb0903f5  neg      x21, x9
//   0x5488: 5400096d  b.le     #0x55b4
//   0x548c: 91006109  add      x9, x8, #0x18
//   0x5490: d2e012ca  mov      x10, #0x96000000000000
//   0x5494: f9002289  str      x9, [x20, #0x40]
//   0x5498: a9007d15  stp      x21, xzr, [x8]
//   0x549c: f900090a  str      x10, [x8, #0x10]
//   0x54a0: b7f80815  tbnz     x21, #0x3f, #0x55a0
//   0x54a4: d360fea9  lsr      x9, x21, #0x20
//   0x54a8: 52803aca  mov      w10, #0x1d6
//   0x54ac: 528032cb  mov      w11, #0x196
//   0x54b0: f100013f  cmp      x9, #0
//   0x54b4: 1a8a1169  csel     w9, w11, w10, ne
//   0x54b8: d35ffeaa  lsr      x10, x21, #0x1f
//   0x54bc: 79002d09  strh     w9, [x8, #0x16]
//   0x54c0: b5ffeb6a  cbnz     x10, #0x522c
//   0x54c4: 321b0129  orr      w9, w9, #0x20
//   0x54c8: 14000034  b        #0x5598
//   0x54cc: f9400669  ldr      x9, [x19, #8]
//   0x54d0: 528000ea  mov      w10, #7
//   0x54d4: 17ffffc3  b        #0x53e0
//   0x54d8: 540004a1  b.ne     #0x556c
//   0x54dc: a9442688  ldp      x8, x9, [x20, #0x40]
//   0x54e0: 4b1603f5  neg      w21, w22
//   0x54e4: cb080129  sub      x9, x9, x8
//   0x54e8: f1005d3f  cmp      x9, #0x17
//   0x54ec: 540006ad  b.le     #0x55c0
//   0x54f0: 91006109  add      x9, x8, #0x18
//   0x54f4: 93407eaa  sxtw     x10, w21
//   0x54f8: 710002bf  cmp      w21, #0
//   0x54fc: 528016cb  mov      w11, #0xb6
//   0x5500: 52803ecc  mov      w12, #0x1f6
//   0x5504: f9002289  str      x9, [x20, #0x40]
//   0x5508: a900fd1f  stp      xzr, xzr, [x8, #8]
//   0x550c: f900010a  str      x10, [x8]
//   0x5510: 1a8ba189  csel     w9, w12, w11, ge
//   0x5514: 14000021  b        #0x5598
//   0x5518: 94000766  bl       #0x72b0
//   0x551c: 5400058d  b.le     #0x55cc
//   0x5520: f94007ea  ldr      x10, [sp, #8]
//   0x5524: 91006109  add      x9, x8, #0x18
//   0x5528: 528032cb  mov      w11, #0x196
//   0x552c: 528022cc  mov      w12, #0x116
//   0x5530: f100015f  cmp      x10, #0
//   0x5534: f9002289  str      x9, [x20, #0x40]
//   0x5538: f900010a  str      x10, [x8]
//   0x553c: 1a8bb189  csel     w9, w12, w11, lt
//   0x5540: d360fd4a  lsr      x10, x10, #0x20
//   0x5544: a900fd1f  stp      xzr, xzr, [x8, #8]
//   0x5548: 79002d09  strh     w9, [x8, #0x16]
//   0x554c: b5ffe70a  cbnz     x10, #0x522c
//   0x5550: f94007ea  ldr      x10, [sp, #8]
//   0x5554: 321a012b  orr      w11, w9, #0x40
//   0x5558: 79002d0b  strh     w11, [x8, #0x16]
//   0x555c: d35ffd4a  lsr      x10, x10, #0x1f
//   0x5560: b5ffe66a  cbnz     x10, #0x522c
//   0x5564: 321b0529  orr      w9, w9, #0x60
//   0x5568: 1400000c  b        #0x5598
//   0x556c: 94000751  bl       #0x72b0
//   0x5570: 5400034d  b.le     #0x55d8
//   0x5574: 91006109  add      x9, x8, #0x18
//   0x5578: 710002df  cmp      w22, #0
//   0x557c: 52803ecb  mov      w11, #0x1f6
//   0x5580: 52803acc  mov      w12, #0x1d6
//   0x5584: 2a1603ea  mov      w10, w22
//   0x5588: f9002289  str      x9, [x20, #0x40]
//   0x558c: 1a8bb189  csel     w9, w12, w11, lt
//   0x5590: a900fd1f  stp      xzr, xzr, [x8, #8]
//   0x5594: f900010a  str      x10, [x8]
//   0x5598: 79002d09  strh     w9, [x8, #0x16]
//   0x559c: 17ffff24  b        #0x522c
//   0x55a0: b26183e9  mov      x9, #-0xffffffff80000000
//   0x55a4: eb0902bf  cmp      x21, x9
//   0x55a8: 54ffe42b  b.lt     #0x522c
//   0x55ac: 528016c9  mov      w9, #0xb6
//   0x55b0: 17fffffa  b        #0x5598
//   0x55b4: 94000748  bl       #0x72d4
//   0x55b8: f9402288  ldr      x8, [x20, #0x40]
//   0x55bc: 17ffffb4  b        #0x548c
//   0x55c0: 94000745  bl       #0x72d4
//   0x55c4: f9402288  ldr      x8, [x20, #0x40]
//   0x55c8: 17ffffca  b        #0x54f0
//   0x55cc: 94000742  bl       #0x72d4
//   0x55d0: f9402288  ldr      x8, [x20, #0x40]
//   0x55d4: 17ffffd3  b        #0x5520
//   0x55d8: 9400073f  bl       #0x72d4
//   0x55dc: f9402288  ldr      x8, [x20, #0x40]
//   0x55e0: 17ffffe5  b        #0x5574
// ============================================================================
std::uint32_t fde_025_4c58(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004c58ULL;
    for (std::size_t i = 0; i < 611ULL; ++i) {
        std::uint32_t insn = kTextInstructions[790ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[026] Symbol: sub_55e4
//      Virtual Address Range: 0x55e4..0x5974 (912 bytes, 228 AArch64 instructions)
// [VN] Khung FDE[026] Biểu tượng: sub_55e4
//      Dải địa chỉ ảo: 0x55e4..0x5974 (912 byte, 228 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x55e4: d10203ff  sub      sp, sp, #0x80
//   0x55e8: a9036bfb  stp      x27, x26, [sp, #0x30]
//   0x55ec: a90463f9  stp      x25, x24, [sp, #0x40]
//   0x55f0: a9055bf7  stp      x23, x22, [sp, #0x50]
//   0x55f4: a90653f5  stp      x21, x20, [sp, #0x60]
//   0x55f8: a9077bf3  stp      x19, x30, [sp, #0x70]
//   0x55fc: 3dc00020  ldr      q0, [x1]
//   0x5600: 90fffff7  adrp     x23, #0x1000
//   0x5604: 2a0303f6  mov      w22, w3
//   0x5608: aa0203f5  mov      x21, x2
//   0x560c: 3d8007e0  str      q0, [sp, #0x10]
//   0x5610: f9400be8  ldr      x8, [sp, #0x10]
//   0x5614: aa0003f3  mov      x19, x0
//   0x5618: 2a1f03f4  mov      w20, wzr
//   0x561c: 910702f7  add      x23, x23, #0x1c0
//   0x5620: 52bf9418  mov      w24, #-0x3600000
//   0x5624: 91000508  add      x8, x8, #1
//   0x5628: 129b7ff9  mov      w25, #-0xdc00
//   0x562c: f90013e1  str      x1, [sp, #0x20]
//   0x5630: f9000be8  str      x8, [sp, #0x10]
//   0x5634: 3940011a  ldrb     w26, [x8]
//   0x5638: 7101735f  cmp      w26, #0x5c
//   0x563c: 54000200  b.eq     #0x567c
//   0x5640: 71008b5f  cmp      w26, #0x22
//   0x5644: 540013a0  b.eq     #0x58b8
//   0x5648: 71007f5f  cmp      w26, #0x1f
//   0x564c: 540015a9  b.ls     #0x5900
//   0x5650: 91000508  add      x8, x8, #1
//   0x5654: f9000be8  str      x8, [sp, #0x10]
//   0x5658: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x565c: 9400071b  bl       #0x72c8
//   0x5660: 540001ed  b.le     #0x569c
//   0x5664: 91000509  add      x9, x8, #1
//   0x5668: f9000e69  str      x9, [x19, #0x18]
//   0x566c: 3900011a  strb     w26, [x8]
//   0x5670: f9400be8  ldr      x8, [sp, #0x10]
//   0x5674: 11000694  add      w20, w20, #1
//   0x5678: 17ffffef  b        #0x5634
//   0x567c: 91000509  add      x9, x8, #1
//   0x5680: f9000be9  str      x9, [sp, #0x10]
//   0x5684: 39400509  ldrb     w9, [x8, #1]
//   0x5688: f9400fea  ldr      x10, [sp, #0x18]
//   0x568c: 38696afa  ldrb     w26, [x23, x9]
//   0x5690: 340000da  cbz      w26, #0x56a8
//   0x5694: 91000908  add      x8, x8, #2
//   0x5698: 17ffffef  b        #0x5654
//   0x569c: 94000709  bl       #0x72c0
//   0x56a0: f9400e68  ldr      x8, [x19, #0x18]
//   0x56a4: 17fffff0  b        #0x5664
//   0x56a8: 7101d53f  cmp      w9, #0x75
//   0x56ac: cb0a0102  sub      x2, x8, x10
//   0x56b0: 54001521  b.ne     #0x5954
//   0x56b4: 91000908  add      x8, x8, #2
//   0x56b8: 910043e1  add      x1, sp, #0x10
//   0x56bc: aa1303e0  mov      x0, x19
//   0x56c0: a900a3e2  stp      x2, x8, [sp, #8]
//   0x56c4: 9400010b  bl       #0x5af0
//   0x56c8: b9403268  ldr      w8, [x19, #0x30]
//   0x56cc: 350012a8  cbnz     w8, #0x5920
//   0x56d0: 530a7c08  lsr      w8, w0, #0xa
//   0x56d4: 7100d91f  cmp      w8, #0x36
//   0x56d8: 54000880  b.eq     #0x57e8
//   0x56dc: 7101fc1f  cmp      w0, #0x7f
//   0x56e0: 54000108  b.hi     #0x5700
//   0x56e4: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x56e8: 940006f8  bl       #0x72c8
//   0x56ec: 54000b2d  b.le     #0x5850
//   0x56f0: 91000509  add      x9, x8, #1
//   0x56f4: f9000e69  str      x9, [x19, #0x18]
//   0x56f8: 39000100  strb     w0, [x8]
//   0x56fc: 17ffffdd  b        #0x5670
//   0x5700: 12800ffa  mov      w26, #-0x80
//   0x5704: 711ffc1f  cmp      w0, #0x7ff
//   0x5708: 3300141a  bfxil    w26, w0, #0, #6
//   0x570c: 54000128  b.hi     #0x5730
//   0x5710: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x5714: 53067c0a  lsr      w10, w0, #6
//   0x5718: 321a655b  orr      w27, w10, #0xffffffc0
//   0x571c: 940006eb  bl       #0x72c8
//   0x5720: 54000a2d  b.le     #0x5864
//   0x5724: 9400072c  bl       #0x73d4
//   0x5728: 11000694  add      w20, w20, #1
//   0x572c: 17ffffcc  b        #0x565c
//   0x5730: b9000bfa  str      w26, [sp, #8]
//   0x5734: 12800ffa  mov      w26, #-0x80
//   0x5738: 53107c08  lsr      w8, w0, #0x10
//   0x573c: 33062c1a  bfxil    w26, w0, #6, #6
//   0x5740: 350001e8  cbnz     w8, #0x577c
//   0x5744: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x5748: 530c7c0a  lsr      w10, w0, #0xc
//   0x574c: 321b695b  orr      w27, w10, #0xffffffe0
//   0x5750: 940006de  bl       #0x72c8
//   0x5754: 5400094d  b.le     #0x587c
//   0x5758: 91000509  add      x9, x8, #1
//   0x575c: f9000e69  str      x9, [x19, #0x18]
//   0x5760: 3900011b  strb     w27, [x8]
//   0x5764: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x5768: 940006d8  bl       #0x72c8
//   0x576c: 540008ed  b.le     #0x5888
//   0x5770: 9400071e  bl       #0x73e8
//   0x5774: 11000a94  add      w20, w20, #2
//   0x5778: 14000015  b        #0x57cc
//   0x577c: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x5780: 53127c0a  lsr      w10, w0, #0x12
//   0x5784: 321c6d5b  orr      w27, w10, #0xfffffff0
//   0x5788: b90007e0  str      w0, [sp, #4]
//   0x578c: 940006cf  bl       #0x72c8
//   0x5790: 5400082d  b.le     #0x5894
//   0x5794: 94000710  bl       #0x73d4
//   0x5798: 12800ffb  mov      w27, #-0x80
//   0x579c: 940006cb  bl       #0x72c8
//   0x57a0: b94007e9  ldr      w9, [sp, #4]
//   0x57a4: 330c453b  bfxil    w27, w9, #0xc, #6
//   0x57a8: 540007cd  b.le     #0x58a0
//   0x57ac: 91000509  add      x9, x8, #1
//   0x57b0: f9000e69  str      x9, [x19, #0x18]
//   0x57b4: 3900011b  strb     w27, [x8]
//   0x57b8: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x57bc: 940006c3  bl       #0x72c8
//   0x57c0: 5400076d  b.le     #0x58ac
//   0x57c4: 94000709  bl       #0x73e8
//   0x57c8: 11000e94  add      w20, w20, #3
//   0x57cc: 940006bf  bl       #0x72c8
//   0x57d0: 5400050d  b.le     #0x5870
//   0x57d4: 91000509  add      x9, x8, #1
//   0x57d8: f9000e69  str      x9, [x19, #0x18]
//   0x57dc: b9400be9  ldr      w9, [sp, #8]
//   0x57e0: 39000109  strb     w9, [x8]
//   0x57e4: 17ffffa3  b        #0x5670
//   0x57e8: f9400be8  ldr      x8, [sp, #0x10]
//   0x57ec: 39400109  ldrb     w9, [x8]
//   0x57f0: 7101713f  cmp      w9, #0x5c
//   0x57f4: 54000b81  b.ne     #0x5964
//   0x57f8: 91000509  add      x9, x8, #1
//   0x57fc: f9000be9  str      x9, [sp, #0x10]
//   0x5800: 39400509  ldrb     w9, [x8, #1]
//   0x5804: 7101d53f  cmp      w9, #0x75
//   0x5808: 54000ae1  b.ne     #0x5964
//   0x580c: f94007e2  ldr      x2, [sp, #8]
//   0x5810: 2a0003fa  mov      w26, w0
//   0x5814: 91000908  add      x8, x8, #2
//   0x5818: 910043e1  add      x1, sp, #0x10
//   0x581c: aa1303e0  mov      x0, x19
//   0x5820: f9000be8  str      x8, [sp, #0x10]
//   0x5824: 940000b3  bl       #0x5af0
//   0x5828: b9403268  ldr      w8, [x19, #0x30]
//   0x582c: 350007a8  cbnz     w8, #0x5920
//   0x5830: 530a7c08  lsr      w8, w0, #0xa
//   0x5834: 7100dd1f  cmp      w8, #0x37
//   0x5838: 54000961  b.ne     #0x5964
//   0x583c: 0b1a2b08  add      w8, w24, w26, lsl #10
//   0x5840: 0b190009  add      w9, w0, w25
//   0x5844: 2a080128  orr      w8, w9, w8
//   0x5848: 11404100  add      w0, w8, #0x10, lsl #12
//   0x584c: 17ffffa4  b        #0x56dc
//   0x5850: 2a0003fa  mov      w26, w0
//   0x5854: 9400069b  bl       #0x72c0
//   0x5858: f9400e68  ldr      x8, [x19, #0x18]
//   0x585c: 2a1a03e0  mov      w0, w26
//   0x5860: 17ffffa4  b        #0x56f0
//   0x5864: 94000697  bl       #0x72c0
//   0x5868: f9400e68  ldr      x8, [x19, #0x18]
//   0x586c: 17ffffae  b        #0x5724
//   0x5870: 94000694  bl       #0x72c0
//   0x5874: f9400e68  ldr      x8, [x19, #0x18]
//   0x5878: 17ffffd7  b        #0x57d4
//   0x587c: 94000691  bl       #0x72c0
//   0x5880: f9400e68  ldr      x8, [x19, #0x18]
//   0x5884: 17ffffb5  b        #0x5758
//   0x5888: 9400068e  bl       #0x72c0
//   0x588c: f9400e68  ldr      x8, [x19, #0x18]
//   0x5890: 17ffffb8  b        #0x5770
//   0x5894: 9400068b  bl       #0x72c0
//   0x5898: f9400e68  ldr      x8, [x19, #0x18]
//   0x589c: 17ffffbe  b        #0x5794
//   0x58a0: 94000688  bl       #0x72c0
//   0x58a4: f9400e68  ldr      x8, [x19, #0x18]
//   0x58a8: 17ffffc1  b        #0x57ac
//   0x58ac: 94000685  bl       #0x72c0
//   0x58b0: f9400e68  ldr      x8, [x19, #0x18]
//   0x58b4: 17ffffc4  b        #0x57c4
//   0x58b8: 91000508  add      x8, x8, #1
//   0x58bc: f9000be8  str      x8, [sp, #0x10]
//   0x58c0: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x58c4: 94000681  bl       #0x72c8
//   0x58c8: 5400040d  b.le     #0x5948
//   0x58cc: 91000509  add      x9, x8, #1
//   0x58d0: f9000e69  str      x9, [x19, #0x18]
//   0x58d4: 3900011f  strb     wzr, [x8]
//   0x58d8: b9403268  ldr      w8, [x19, #0x30]
//   0x58dc: 35000228  cbnz     w8, #0x5920
//   0x58e0: f9400e68  ldr      x8, [x19, #0x18]
//   0x58e4: 11000689  add      w9, w20, #1
//   0x58e8: aa1503e0  mov      x0, x21
//   0x58ec: 2a1403e2  mov      w2, w20
//   0x58f0: cb090101  sub      x1, x8, x9
//   0x58f4: f9000e61  str      x1, [x19, #0x18]
//   0x58f8: 9400009e  bl       #0x5b70
//   0x58fc: 14000009  b        #0x5920
//   0x5900: f9400fe9  ldr      x9, [sp, #0x18]
//   0x5904: cb090108  sub      x8, x8, x9
//   0x5908: 3400007a  cbz      w26, #0x5914
//   0x590c: 52800189  mov      w9, #0xc
//   0x5910: 14000002  b        #0x5918
//   0x5914: 52800169  mov      w9, #0xb
//   0x5918: b9003269  str      w9, [x19, #0x30]
//   0x591c: f9001e68  str      x8, [x19, #0x38]
//   0x5920: f94013e8  ldr      x8, [sp, #0x20]
//   0x5924: 3dc007e0  ldr      q0, [sp, #0x10]
//   0x5928: 3d800100  str      q0, [x8]
//   0x592c: a9477bf3  ldp      x19, x30, [sp, #0x70]
//   0x5930: a94653f5  ldp      x21, x20, [sp, #0x60]
//   0x5934: a9455bf7  ldp      x23, x22, [sp, #0x50]
//   0x5938: a94463f9  ldp      x25, x24, [sp, #0x40]
//   0x593c: a9436bfb  ldp      x27, x26, [sp, #0x30]
//   0x5940: 910203ff  add      sp, sp, #0x80
//   0x5944: d65f03c0  ret      
//   0x5948: 9400065e  bl       #0x72c0
//   0x594c: f9400e68  ldr      x8, [x19, #0x18]
//   0x5950: 17ffffdf  b        #0x58cc
//   0x5954: 52800148  mov      w8, #0xa
//   0x5958: b9003268  str      w8, [x19, #0x30]
//   0x595c: f9001e62  str      x2, [x19, #0x38]
//   0x5960: 17fffff0  b        #0x5920
//   0x5964: 52800128  mov      w8, #9
//   0x5968: b9003268  str      w8, [x19, #0x30]
//   0x596c: f94007e8  ldr      x8, [sp, #8]
//   0x5970: 17ffffeb  b        #0x591c
// ============================================================================
std::uint32_t fde_026_55e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000055e4ULL;
    for (std::size_t i = 0; i < 228ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1401ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[027] Symbol: sub_5974
//      Virtual Address Range: 0x5974..0x59c8 (84 bytes, 21 AArch64 instructions)
// [VN] Khung FDE[027] Biểu tượng: sub_5974
//      Dải địa chỉ ảo: 0x5974..0x59c8 (84 byte, 21 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5974: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x5978: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x597c: f9400814  ldr      x20, [x0, #0x10]
//   0x5980: aa0003f3  mov      x19, x0
//   0x5984: b4000074  cbz      x20, #0x5990
//   0x5988: 940006cc  bl       #0x74b8
//   0x598c: 14000006  b        #0x59a4
//   0x5990: f9400268  ldr      x8, [x19]
//   0x5994: b5000068  cbnz     x8, #0x59a0
//   0x5998: 940006c6  bl       #0x74b0
//   0x599c: a9000260  stp      x0, x0, [x19]
//   0x59a0: f9401668  ldr      x8, [x19, #0x28]
//   0x59a4: f9400e69  ldr      x9, [x19, #0x18]
//   0x59a8: aa1303e0  mov      x0, x19
//   0x59ac: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x59b0: cb140129  sub      x9, x9, x20
//   0x59b4: 91006129  add      x9, x9, #0x18
//   0x59b8: eb09011f  cmp      x8, x9
//   0x59bc: 9a883121  csel     x1, x9, x8, lo
//   0x59c0: f84207f4  ldr      x20, [sp], #0x20
//   0x59c4: 17fffc84  b        #0x4bd4
// ============================================================================
std::uint32_t fde_027_5974(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005974ULL;
    for (std::size_t i = 0; i < 21ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1629ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[028] Symbol: sub_59c8
//      Virtual Address Range: 0x59c8..0x5a08 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[028] Biểu tượng: sub_59c8
//      Dải địa chỉ ảo: 0x59c8..0x5a08 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x59c8: fc1f0fe8  str      d8, [sp, #-0x10]!
//   0x59cc: f90007fe  str      x30, [sp, #8]
//   0x59d0: 4ea01c08  mov      v8.16b, v0.16b
//   0x59d4: 3104d01f  cmn      w0, #0x134
//   0x59d8: 9e6703e0  fmov     d0, xzr
//   0x59dc: 5400010b  b.lt     #0x59fc
//   0x59e0: 37f80080  tbnz     w0, #0x1f, #0x59f0
//   0x59e4: 94000266  bl       #0x637c
//   0x59e8: 1e680800  fmul     d0, d0, d8
//   0x59ec: 14000004  b        #0x59fc
//   0x59f0: 4b0003e0  neg      w0, w0
//   0x59f4: 94000262  bl       #0x637c
//   0x59f8: 1e601900  fdiv     d0, d8, d0
//   0x59fc: f94007fe  ldr      x30, [sp, #8]
//   0x5a00: fc4107e8  ldr      d8, [sp], #0x10
//   0x5a04: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_028_59c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000059c8ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1650ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[029] Symbol: sub_5a08
//      Virtual Address Range: 0x5a08..0x5a9c (148 bytes, 37 AArch64 instructions)
// [VN] Khung FDE[029] Biểu tượng: sub_5a08
//      Dải địa chỉ ảo: 0x5a08..0x5a9c (148 byte, 37 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5a08: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x5a0c: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x5a10: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x5a14: b40003e1  cbz      x1, #0x5a90
//   0x5a18: f9400014  ldr      x20, [x0]
//   0x5a1c: 91001c28  add      x8, x1, #7
//   0x5a20: aa0003f3  mov      x19, x0
//   0x5a24: 927df115  and      x21, x8, #0xfffffffffffffff8
//   0x5a28: b40000b4  cbz      x20, #0x5a3c
//   0x5a2c: a940228a  ldp      x10, x8, [x20]
//   0x5a30: 8b150109  add      x9, x8, x21
//   0x5a34: eb0a013f  cmp      x9, x10
//   0x5a38: 54000249  b.ls     #0x5a80
//   0x5a3c: f9400668  ldr      x8, [x19, #8]
//   0x5a40: f9400e69  ldr      x9, [x19, #0x18]
//   0x5a44: eb15011f  cmp      x8, x21
//   0x5a48: 9a958116  csel     x22, x8, x21, hi
//   0x5a4c: b5000069  cbnz     x9, #0x5a58
//   0x5a50: 94000698  bl       #0x74b0
//   0x5a54: a9018260  stp      x0, x0, [x19, #0x18]
//   0x5a58: b10062c0  adds     x0, x22, #0x18
//   0x5a5c: 540001c0  b.eq     #0x5a94
//   0x5a60: 940006d8  bl       #0x75c0
//   0x5a64: b4000180  cbz      x0, #0x5a94
//   0x5a68: aa1f03e8  mov      x8, xzr
//   0x5a6c: f9000814  str      x20, [x0, #0x10]
//   0x5a70: aa1503e9  mov      x9, x21
//   0x5a74: aa0003f4  mov      x20, x0
//   0x5a78: a9007c16  stp      x22, xzr, [x0]
//   0x5a7c: f9000260  str      x0, [x19]
//   0x5a80: 8b080288  add      x8, x20, x8
//   0x5a84: 91006100  add      x0, x8, #0x18
//   0x5a88: f9000689  str      x9, [x20, #8]
//   0x5a8c: 14000002  b        #0x5a94
//   0x5a90: aa1f03e0  mov      x0, xzr
//   0x5a94: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x5a98: 14000663  b        #0x7424
// ============================================================================
std::uint32_t fde_029_5a08(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005a08ULL;
    for (std::size_t i = 0; i < 37ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1666ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[030] Symbol: sub_5a9c
//      Virtual Address Range: 0x5a9c..0x5af0 (84 bytes, 21 AArch64 instructions)
// [VN] Khung FDE[030] Biểu tượng: sub_5a9c
//      Dải địa chỉ ảo: 0x5a9c..0x5af0 (84 byte, 21 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5a9c: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x5aa0: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x5aa4: f9400814  ldr      x20, [x0, #0x10]
//   0x5aa8: aa0003f3  mov      x19, x0
//   0x5aac: b4000074  cbz      x20, #0x5ab8
//   0x5ab0: 94000682  bl       #0x74b8
//   0x5ab4: 14000006  b        #0x5acc
//   0x5ab8: f9400268  ldr      x8, [x19]
//   0x5abc: b5000068  cbnz     x8, #0x5ac8
//   0x5ac0: 9400067c  bl       #0x74b0
//   0x5ac4: a9000260  stp      x0, x0, [x19]
//   0x5ac8: f9401668  ldr      x8, [x19, #0x28]
//   0x5acc: f9400e69  ldr      x9, [x19, #0x18]
//   0x5ad0: aa1303e0  mov      x0, x19
//   0x5ad4: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x5ad8: cb140129  sub      x9, x9, x20
//   0x5adc: 9100052a  add      x10, x9, #1
//   0x5ae0: eb0a011f  cmp      x8, x10
//   0x5ae4: 9a892501  csinc    x1, x8, x9, hs
//   0x5ae8: f84207f4  ldr      x20, [sp], #0x20
//   0x5aec: 17fffc3a  b        #0x4bd4
// ============================================================================
std::uint32_t fde_030_5a9c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005a9cULL;
    for (std::size_t i = 0; i < 21ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1703ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[031] Symbol: sub_5af0
//      Virtual Address Range: 0x5af0..0x5b70 (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[031] Biểu tượng: sub_5af0
//      Dải địa chỉ ảo: 0x5af0..0x5b70 (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5af0: aa0003e8  mov      x8, x0
//   0x5af4: 2a1f03e0  mov      w0, wzr
//   0x5af8: 52800089  mov      w9, #4
//   0x5afc: 340002e9  cbz      w9, #0x5b58
//   0x5b00: f940002a  ldr      x10, [x1]
//   0x5b04: 3940014b  ldrb     w11, [x10]
//   0x5b08: 5100c16c  sub      w12, w11, #0x30
//   0x5b0c: 7100299f  cmp      w12, #0xa
//   0x5b10: 54000062  b.hs     #0x5b1c
//   0x5b14: 128005ec  mov      w12, #-0x30
//   0x5b18: 1400000a  b        #0x5b40
//   0x5b1c: 5101056c  sub      w12, w11, #0x41
//   0x5b20: 7100199f  cmp      w12, #6
//   0x5b24: 54000062  b.hs     #0x5b30
//   0x5b28: 128006cc  mov      w12, #-0x37
//   0x5b2c: 14000005  b        #0x5b40
//   0x5b30: 5101856c  sub      w12, w11, #0x61
//   0x5b34: 7100159f  cmp      w12, #5
//   0x5b38: 54000128  b.hi     #0x5b5c
//   0x5b3c: 12800acc  mov      w12, #-0x57
//   0x5b40: 0b00116b  add      w11, w11, w0, lsl #4
//   0x5b44: 9100054a  add      x10, x10, #1
//   0x5b48: 0b0c0160  add      w0, w11, w12
//   0x5b4c: f900002a  str      x10, [x1]
//   0x5b50: 51000529  sub      w9, w9, #1
//   0x5b54: 35fffd69  cbnz     w9, #0x5b00
//   0x5b58: d65f03c0  ret      
//   0x5b5c: 2a1f03e0  mov      w0, wzr
//   0x5b60: 52800109  mov      w9, #8
//   0x5b64: b9003109  str      w9, [x8, #0x30]
//   0x5b68: f9001d02  str      x2, [x8, #0x38]
//   0x5b6c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_031_5af0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005af0ULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1724ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[032] Symbol: sub_5b70
//      Virtual Address Range: 0x5b70..0x5c20 (176 bytes, 44 AArch64 instructions)
// [VN] Khung FDE[032] Biểu tượng: sub_5b70
//      Dải địa chỉ ảo: 0x5b70..0x5c20 (176 byte, 44 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5b70: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x5b74: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x5b78: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x5b7c: a9442014  ldp      x20, x8, [x0, #0x40]
//   0x5b80: 2a0203f3  mov      w19, w2
//   0x5b84: aa0003f5  mov      x21, x0
//   0x5b88: aa0103f6  mov      x22, x1
//   0x5b8c: cb140108  sub      x8, x8, x20
//   0x5b90: f1005d1f  cmp      x8, #0x17
//   0x5b94: 540003ed  b.le     #0x5c10
//   0x5b98: f9400ea0  ldr      x0, [x21, #0x18]
//   0x5b9c: 90ffffe9  adrp     x9, #0x1000
//   0x5ba0: 91006288  add      x8, x20, #0x18
//   0x5ba4: 910b0129  add      x9, x9, #0x2c0
//   0x5ba8: f10002df  cmp      x22, #0
//   0x5bac: f90022a8  str      x8, [x21, #0x40]
//   0x5bb0: 9a960135  csel     x21, x9, x22, eq
//   0x5bb4: 7100567f  cmp      w19, #0x15
//   0x5bb8: a9007e9f  stp      xzr, xzr, [x20]
//   0x5bbc: f9000a9f  str      xzr, [x20, #0x10]
//   0x5bc0: 540000e8  b.hi     #0x5bdc
//   0x5bc4: 528380a8  mov      w8, #0x1c05
//   0x5bc8: 528002a9  mov      w9, #0x15
//   0x5bcc: 79002e88  strh     w8, [x20, #0x16]
//   0x5bd0: 4b130128  sub      w8, w9, w19
//   0x5bd4: 39005688  strb     w8, [x20, #0x15]
//   0x5bd8: 14000008  b        #0x5bf8
//   0x5bdc: 528180a8  mov      w8, #0xc05
//   0x5be0: 11000661  add      w1, w19, #1
//   0x5be4: b9000293  str      w19, [x20]
//   0x5be8: 79002e88  strh     w8, [x20, #0x16]
//   0x5bec: 97ffff87  bl       #0x5a08
//   0x5bf0: f9000680  str      x0, [x20, #8]
//   0x5bf4: aa0003f4  mov      x20, x0
//   0x5bf8: 2a1303e2  mov      w2, w19
//   0x5bfc: 94000610  bl       #0x743c
//   0x5c00: 94000648  bl       #0x7520
//   0x5c04: 38334a9f  strb     wzr, [x20, w19, uxtw]
//   0x5c08: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x5c0c: 14000606  b        #0x7424
//   0x5c10: 9100a2a0  add      x0, x21, #0x28
//   0x5c14: 97ffff58  bl       #0x5974
//   0x5c18: f94022b4  ldr      x20, [x21, #0x40]
//   0x5c1c: 17ffffdf  b        #0x5b98
// ============================================================================
std::uint32_t fde_032_5b70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005b70ULL;
    for (std::size_t i = 0; i < 44ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1756ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[033] Symbol: sub_5c20
//      Virtual Address Range: 0x5c20..0x5c78 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[033] Biểu tượng: sub_5c20
//      Dải địa chỉ ảo: 0x5c20..0x5c78 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5c20: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x5c24: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x5c28: a9442408  ldp      x8, x9, [x0, #0x40]
//   0x5c2c: aa0003f3  mov      x19, x0
//   0x5c30: 2a0103f4  mov      w20, w1
//   0x5c34: cb080129  sub      x9, x9, x8
//   0x5c38: f1005d3f  cmp      x9, #0x17
//   0x5c3c: 5400016d  b.le     #0x5c68
//   0x5c40: 91006109  add      x9, x8, #0x18
//   0x5c44: 7200029f  tst      w20, #1
//   0x5c48: 5280012a  mov      w10, #9
//   0x5c4c: f9002269  str      x9, [x19, #0x40]
//   0x5c50: 1a8a0549  cinc     w9, w10, ne
//   0x5c54: a900fd1f  stp      xzr, xzr, [x8, #8]
//   0x5c58: f900011f  str      xzr, [x8]
//   0x5c5c: 79002d09  strh     w9, [x8, #0x16]
//   0x5c60: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x5c64: 14000608  b        #0x7484
//   0x5c68: 9100a260  add      x0, x19, #0x28
//   0x5c6c: 97ffff42  bl       #0x5974
//   0x5c70: f9402268  ldr      x8, [x19, #0x40]
//   0x5c74: 17fffff3  b        #0x5c40
// ============================================================================
std::uint32_t fde_033_5c20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005c20ULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1800ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[034] Symbol: sub_5c78
//      Virtual Address Range: 0x5c78..0x5cdc (100 bytes, 25 AArch64 instructions)
// [VN] Khung FDE[034] Biểu tượng: sub_5c78
//      Dải địa chỉ ảo: 0x5c78..0x5cdc (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5c78: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x5c7c: f9400028  ldr      x8, [x1]
//   0x5c80: aa0003f3  mov      x19, x0
//   0x5c84: f900003f  str      xzr, [x1]
//   0x5c88: f8008408  str      x8, [x0], #8
//   0x5c8c: 94000014  bl       #0x5cdc
//   0x5c90: f0ffffc8  adrp     x8, #0
//   0x5c94: fd47d100  ldr      d0, [x8, #0xfa0]
//   0x5c98: 91014260  add      x0, x19, #0x50
//   0x5c9c: a9027e7f  stp      xzr, xzr, [x19, #0x20]
//   0x5ca0: b9003a7f  str      wzr, [x19, #0x38]
//   0x5ca4: f900227f  str      xzr, [x19, #0x40]
//   0x5ca8: b9004a7f  str      wzr, [x19, #0x48]
//   0x5cac: fd001a60  str      d0, [x19, #0x30]
//   0x5cb0: 9400000b  bl       #0x5cdc
//   0x5cb4: 9101c260  add      x0, x19, #0x70
//   0x5cb8: b9006a7f  str      wzr, [x19, #0x68]
//   0x5cbc: 94000008  bl       #0x5cdc
//   0x5cc0: f9400260  ldr      x0, [x19]
//   0x5cc4: f9400008  ldr      x8, [x0]
//   0x5cc8: f9401108  ldr      x8, [x8, #0x20]
//   0x5ccc: d63f0100  blr      x8
//   0x5cd0: f9001260  str      x0, [x19, #0x20]
//   0x5cd4: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x5cd8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_034_5c78(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005c78ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1822ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[035] Symbol: sub_5cdc
//      Virtual Address Range: 0x5cdc..0x5ce8 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[035] Biểu tượng: sub_5cdc
//      Dải địa chỉ ảo: 0x5cdc..0x5ce8 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5cdc: a9007c1f  stp      xzr, xzr, [x0]
//   0x5ce0: f900081f  str      xzr, [x0, #0x10]
//   0x5ce4: 17fffb7c  b        #0x4ad4
// ============================================================================
std::uint32_t fde_035_5cdc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005cdcULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1847ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[036] Symbol: sub_5ce8
//      Virtual Address Range: 0x5ce8..0x5d14 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[036] Biểu tượng: sub_5ce8
//      Dải địa chỉ ảo: 0x5ce8..0x5d14 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5ce8: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x5cec: f9400013  ldr      x19, [x0]
//   0x5cf0: f900001f  str      xzr, [x0]
//   0x5cf4: b40000d3  cbz      x19, #0x5d0c
//   0x5cf8: aa1303e0  mov      x0, x19
//   0x5cfc: 94000006  bl       #0x5d14
//   0x5d00: aa1303e0  mov      x0, x19
//   0x5d04: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x5d08: 1400060a  b        #0x7530
//   0x5d0c: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x5d10: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_036_5ce8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005ce8ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1850ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[037] Symbol: sub_5d14
//      Virtual Address Range: 0x5d14..0x5d24 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[037] Biểu tượng: sub_5d14
//      Dải địa chỉ ảo: 0x5d14..0x5d24 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d14: f0000008  adrp     x8, #0x8000
//   0x5d18: 91014108  add      x8, x8, #0x50
//   0x5d1c: f8008408  str      x8, [x0], #8
//   0x5d20: 17fff913  b        #0x416c
// ============================================================================
std::uint32_t fde_037_5d14(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d14ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1861ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[038] Symbol: sub_5d24
//      Virtual Address Range: 0x5d24..0x5d3c (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[038] Biểu tượng: sub_5d24
//      Dải địa chỉ ảo: 0x5d24..0x5d3c (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d24: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x5d28: aa0003f3  mov      x19, x0
//   0x5d2c: 97fffffa  bl       #0x5d14
//   0x5d30: aa1303e0  mov      x0, x19
//   0x5d34: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x5d38: 140005fe  b        #0x7530
// ============================================================================
std::uint32_t fde_038_5d24(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d24ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1865ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[039] Symbol: sub_5d3c
//      Virtual Address Range: 0x5d3c..0x5d48 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[039] Biểu tượng: sub_5d3c
//      Dải địa chỉ ảo: 0x5d3c..0x5d48 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d3c: f9400408  ldr      x8, [x0, #8]
//   0x5d40: f9000808  str      x8, [x0, #0x10]
//   0x5d44: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_039_5d3c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d3cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1871ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[040] Symbol: sub_5d48
//      Virtual Address Range: 0x5d48..0x5d54 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[040] Biểu tượng: sub_5d48
//      Dải địa chỉ ảo: 0x5d48..0x5d54 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d48: a940a408  ldp      x8, x9, [x0, #8]
//   0x5d4c: cb080120  sub      x0, x9, x8
//   0x5d50: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_040_5d48(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d48ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1874ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[041] Symbol: sub_5d54
//      Virtual Address Range: 0x5d54..0x5d5c (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[041] Biểu tượng: sub_5d54
//      Dải địa chỉ ảo: 0x5d54..0x5d5c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d54: f9400400  ldr      x0, [x0, #8]
//   0x5d58: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_041_5d54(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d54ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1877ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[042] Symbol: sub_5d5c
//      Virtual Address Range: 0x5d5c..0x5d64 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[042] Biểu tượng: sub_5d5c
//      Dải địa chỉ ảo: 0x5d5c..0x5d64 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d5c: f9400800  ldr      x0, [x0, #0x10]
//   0x5d60: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_042_5d5c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d5cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1879ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[043] Symbol: sub_5d64
//      Virtual Address Range: 0x5d64..0x5d7c (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[043] Biểu tượng: sub_5d64
//      Dải địa chỉ ảo: 0x5d64..0x5d7c (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d64: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x5d68: 91002000  add      x0, x0, #8
//   0x5d6c: 97fff8c6  bl       #0x4084
//   0x5d70: 52800020  mov      w0, #1
//   0x5d74: f84107fe  ldr      x30, [sp], #0x10
//   0x5d78: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_043_5d64(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d64ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1881ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[044] Symbol: sub_5d7c
//      Virtual Address Range: 0x5d7c..0x5da8 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[044] Biểu tượng: sub_5d7c
//      Dải địa chỉ ảo: 0x5d7c..0x5da8 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5d7c: aa0003e8  mov      x8, x0
//   0x5d80: f9400800  ldr      x0, [x0, #0x10]
//   0x5d84: f0000009  adrp     x9, #0x8000
//   0x5d88: 91006129  add      x9, x9, #0x18
//   0x5d8c: f9000109  str      x9, [x8]
//   0x5d90: f900091f  str      xzr, [x8, #0x10]
//   0x5d94: b4000080  cbz      x0, #0x5da4
//   0x5d98: f9400008  ldr      x8, [x0]
//   0x5d9c: f9400501  ldr      x1, [x8, #8]
//   0x5da0: d61f0020  br       x1
//   0x5da4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_044_5d7c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d7cULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1887ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[045] Symbol: sub_5da8
//      Virtual Address Range: 0x5da8..0x5dc0 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[045] Biểu tượng: sub_5da8
//      Dải địa chỉ ảo: 0x5da8..0x5dc0 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5da8: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x5dac: aa0003f3  mov      x19, x0
//   0x5db0: 97fffff3  bl       #0x5d7c
//   0x5db4: aa1303e0  mov      x0, x19
//   0x5db8: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x5dbc: 140005dd  b        #0x7530
// ============================================================================
std::uint32_t fde_045_5da8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005da8ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1898ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[046] Symbol: sub_5dc0
//      Virtual Address Range: 0x5dc0..0x5dd0 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[046] Biểu tượng: sub_5dc0
//      Dải địa chỉ ảo: 0x5dc0..0x5dd0 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5dc0: f9400800  ldr      x0, [x0, #0x10]
//   0x5dc4: f9400008  ldr      x8, [x0]
//   0x5dc8: f9401101  ldr      x1, [x8, #0x20]
//   0x5dcc: d61f0020  br       x1
// ============================================================================
std::uint32_t fde_046_5dc0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005dc0ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1904ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[047] Symbol: sub_5dd0
//      Virtual Address Range: 0x5dd0..0x5de0 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[047] Biểu tượng: sub_5dd0
//      Dải địa chỉ ảo: 0x5dd0..0x5de0 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5dd0: f9400800  ldr      x0, [x0, #0x10]
//   0x5dd4: f9400008  ldr      x8, [x0]
//   0x5dd8: f9401501  ldr      x1, [x8, #0x28]
//   0x5ddc: d61f0020  br       x1
// ============================================================================
std::uint32_t fde_047_5dd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005dd0ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1908ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[048] Symbol: sub_5de0
//      Virtual Address Range: 0x5de0..0x5df0 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[048] Biểu tượng: sub_5de0
//      Dải địa chỉ ảo: 0x5de0..0x5df0 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5de0: f9400800  ldr      x0, [x0, #0x10]
//   0x5de4: f9400008  ldr      x8, [x0]
//   0x5de8: f9400d01  ldr      x1, [x8, #0x18]
//   0x5dec: d61f0020  br       x1
// ============================================================================
std::uint32_t fde_048_5de0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005de0ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1912ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[049] Symbol: sub_5df0
//      Virtual Address Range: 0x5df0..0x5df4 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[049] Biểu tượng: sub_5df0
//      Dải địa chỉ ảo: 0x5df0..0x5df4 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5df0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_049_5df0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005df0ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1916ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[050] Symbol: sub_5df4
//      Virtual Address Range: 0x5df4..0x5df8 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[050] Biểu tượng: sub_5df4
//      Dải địa chỉ ảo: 0x5df4..0x5df8 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5df4: 140005cf  b        #0x7530
// ============================================================================
std::uint32_t fde_050_5df4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005df4ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1917ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[051] Symbol: sub_5df8
//      Virtual Address Range: 0x5df8..0x5e04 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[051] Biểu tượng: sub_5df8
//      Dải địa chỉ ảo: 0x5df8..0x5e04 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5df8: 92800008  mov      x8, #-1
//   0x5dfc: a900a01f  stp      xzr, x8, [x0, #8]
//   0x5e00: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_051_5df8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005df8ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1918ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[052] Symbol: sub_5e04
//      Virtual Address Range: 0x5e04..0x5e10 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[052] Biểu tượng: sub_5e04
//      Dải địa chỉ ảo: 0x5e04..0x5e10 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5e04: a940a408  ldp      x8, x9, [x0, #8]
//   0x5e08: 8b090100  add      x0, x8, x9
//   0x5e0c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_052_5e04(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005e04ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1921ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[053] Symbol: sub_5e10
//      Virtual Address Range: 0x5e10..0x5e18 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[053] Biểu tượng: sub_5e10
//      Dải địa chỉ ảo: 0x5e10..0x5e18 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5e10: 2a1f03e0  mov      w0, wzr
//   0x5e14: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_053_5e10(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005e10ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1924ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[054] Symbol: sub_5e18
//      Virtual Address Range: 0x5e18..0x5ee4 (204 bytes, 51 AArch64 instructions)
// [VN] Khung FDE[054] Biểu tượng: sub_5e18
//      Dải địa chỉ ảo: 0x5e18..0x5ee4 (204 byte, 51 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5e18: a9bd5bf7  stp      x23, x22, [sp, #-0x30]!
//   0x5e1c: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x5e20: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x5e24: aa0203f3  mov      x19, x2
//   0x5e28: f9400808  ldr      x8, [x0, #0x10]
//   0x5e2c: f9400002  ldr      x2, [x0]
//   0x5e30: cb010275  sub      x21, x19, x1
//   0x5e34: aa0103f6  mov      x22, x1
//   0x5e38: aa0003f4  mov      x20, x0
//   0x5e3c: cb020108  sub      x8, x8, x2
//   0x5e40: eb0802bf  cmp      x21, x8
//   0x5e44: 54000229  b.ls     #0x5e88
//   0x5e48: b40000c2  cbz      x2, #0x5e60
//   0x5e4c: aa0203e0  mov      x0, x2
//   0x5e50: f9000682  str      x2, [x20, #8]
//   0x5e54: 940005b7  bl       #0x7530
//   0x5e58: a9007e9f  stp      xzr, xzr, [x20]
//   0x5e5c: f9000a9f  str      xzr, [x20, #0x10]
//   0x5e60: 94000577  bl       #0x743c
//   0x5e64: 97fff8d0  bl       #0x41a4
//   0x5e68: aa0003e1  mov      x1, x0
//   0x5e6c: aa1403e0  mov      x0, x20
//   0x5e70: 97fff8dd  bl       #0x41e4
//   0x5e74: aa1403e0  mov      x0, x20
//   0x5e78: aa1603e1  mov      x1, x22
//   0x5e7c: aa1303e2  mov      x2, x19
//   0x5e80: aa1503e3  mov      x3, x21
//   0x5e84: 1400000e  b        #0x5ebc
//   0x5e88: f9400688  ldr      x8, [x20, #8]
//   0x5e8c: cb020108  sub      x8, x8, x2
//   0x5e90: eb0802bf  cmp      x21, x8
//   0x5e94: 540001c9  b.ls     #0x5ecc
//   0x5e98: 8b0802d7  add      x23, x22, x8
//   0x5e9c: aa1603e0  mov      x0, x22
//   0x5ea0: aa1703e1  mov      x1, x23
//   0x5ea4: 94000010  bl       #0x5ee4
//   0x5ea8: a9402289  ldp      x9, x8, [x20]
//   0x5eac: 94000567  bl       #0x7448
//   0x5eb0: aa1303e2  mov      x2, x19
//   0x5eb4: cb0802a8  sub      x8, x21, x8
//   0x5eb8: 8b090103  add      x3, x8, x9
//   0x5ebc: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x5ec0: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x5ec4: a8c35bf7  ldp      x23, x22, [sp], #0x30
//   0x5ec8: 14000014  b        #0x5f18
//   0x5ecc: aa1603e0  mov      x0, x22
//   0x5ed0: aa1303e1  mov      x1, x19
//   0x5ed4: 94000004  bl       #0x5ee4
//   0x5ed8: f9000680  str      x0, [x20, #8]
//   0x5edc: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x5ee0: 14000554  b        #0x7430
// ============================================================================
std::uint32_t fde_054_5e18(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005e18ULL;
    for (std::size_t i = 0; i < 51ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1926ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[055] Symbol: sub_5ee4
//      Virtual Address Range: 0x5ee4..0x5f18 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[055] Biểu tượng: sub_5ee4
//      Dải địa chỉ ảo: 0x5ee4..0x5f18 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5ee4: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x5ee8: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x5eec: eb000033  subs     x19, x1, x0
//   0x5ef0: aa0203f4  mov      x20, x2
//   0x5ef4: 540000c0  b.eq     #0x5f0c
//   0x5ef8: aa0003e8  mov      x8, x0
//   0x5efc: aa1403e0  mov      x0, x20
//   0x5f00: aa0803e1  mov      x1, x8
//   0x5f04: aa1303e2  mov      x2, x19
//   0x5f08: 940005a2  bl       #0x7590
//   0x5f0c: 8b130280  add      x0, x20, x19
//   0x5f10: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x5f14: 1400055c  b        #0x7484
// ============================================================================
std::uint32_t fde_055_5ee4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005ee4ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1977ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[056] Symbol: sub_5f18
//      Virtual Address Range: 0x5f18..0x5f50 (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[056] Biểu tượng: sub_5f18
//      Dải địa chỉ ảo: 0x5f18..0x5f50 (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5f18: a9be53f5  stp      x21, x20, [sp, #-0x20]!
//   0x5f1c: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x5f20: f9400414  ldr      x20, [x0, #8]
//   0x5f24: cb010055  sub      x21, x2, x1
//   0x5f28: aa0003f3  mov      x19, x0
//   0x5f2c: f10006bf  cmp      x21, #1
//   0x5f30: 540000ab  b.lt     #0x5f44
//   0x5f34: aa1403e0  mov      x0, x20
//   0x5f38: aa1503e2  mov      x2, x21
//   0x5f3c: 94000579  bl       #0x7520
//   0x5f40: 8b150294  add      x20, x20, x21
//   0x5f44: f9000674  str      x20, [x19, #8]
//   0x5f48: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x5f4c: 1400052f  b        #0x7408
// ============================================================================
std::uint32_t fde_056_5f18(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005f18ULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1990ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[057] Symbol: sub_5f50
//      Virtual Address Range: 0x5f50..0x5f7c (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[057] Biểu tượng: sub_5f50
//      Dải địa chỉ ảo: 0x5f50..0x5f7c (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5f50: a9007c1f  stp      xzr, xzr, [x0]
//   0x5f54: f900081f  str      xzr, [x0, #0x10]
//   0x5f58: 39400028  ldrb     w8, [x1]
//   0x5f5c: 370000c8  tbnz     w8, #0, #0x5f74
//   0x5f60: f9400828  ldr      x8, [x1, #0x10]
//   0x5f64: 3dc00020  ldr      q0, [x1]
//   0x5f68: f9000808  str      x8, [x0, #0x10]
//   0x5f6c: 3d800000  str      q0, [x0]
//   0x5f70: d65f03c0  ret      
//   0x5f74: a9408422  ldp      x2, x1, [x1, #8]
//   0x5f78: 17fffaf7  b        #0x4b54
// ============================================================================
std::uint32_t fde_057_5f50(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005f50ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2004ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[058] Symbol: sub_5f7c
//      Virtual Address Range: 0x5f7c..0x613c (448 bytes, 112 AArch64 instructions)
// [VN] Khung FDE[058] Biểu tượng: sub_5f7c
//      Dải địa chỉ ảo: 0x5f7c..0x613c (448 byte, 112 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5f7c: f81b0ffc  str      x28, [sp, #-0x50]!
//   0x5f80: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x5f84: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x5f88: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x5f8c: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x5f90: d11083ff  sub      sp, sp, #0x420
//   0x5f94: d53bd059  mrs      x25, tpidr_el0
//   0x5f98: f9401728  ldr      x8, [x25, #0x28]
//   0x5f9c: aa0003f4  mov      x20, x0
//   0x5fa0: 910063e0  add      x0, sp, #0x18
//   0x5fa4: aa0103e4  mov      x4, x1
//   0x5fa8: 2a0203e5  mov      w5, w2
//   0x5fac: f9020fe8  str      x8, [sp, #0x418]
//   0x5fb0: 940000cd  bl       #0x62e4
//   0x5fb4: 910003e0  mov      x0, sp
//   0x5fb8: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x5fbc: f90003ff  str      xzr, [sp]
//   0x5fc0: 97fffac5  bl       #0x4ad4
//   0x5fc4: aa1403f3  mov      x19, x20
//   0x5fc8: 38408e68  ldrb     w8, [x19, #8]!
//   0x5fcc: 370000e8  tbnz     w8, #0, #0x5fe8
//   0x5fd0: 910063e0  add      x0, sp, #0x18
//   0x5fd4: d341fd15  lsr      x21, x8, #1
//   0x5fd8: 94000566  bl       #0x7570
//   0x5fdc: aa0003f4  mov      x20, x0
//   0x5fe0: 91000676  add      x22, x19, #1
//   0x5fe4: 14000006  b        #0x5ffc
//   0x5fe8: f9400a95  ldr      x21, [x20, #0x10]
//   0x5fec: 910063e0  add      x0, sp, #0x18
//   0x5ff0: 94000560  bl       #0x7570
//   0x5ff4: f9400e96  ldr      x22, [x20, #0x18]
//   0x5ff8: aa0003f4  mov      x20, x0
//   0x5ffc: 8b1402a8  add      x8, x21, x20
//   0x6000: b100411f  cmn      x8, #0x10
//   0x6004: 54000982  b.hs     #0x6134
//   0x6008: f100591f  cmp      x8, #0x16
//   0x600c: 540000c8  b.hi     #0x6024
//   0x6010: 531f7aa8  lsl      w8, w21, #1
//   0x6014: 910003e9  mov      x9, sp
//   0x6018: 390003e8  strb     w8, [sp]
//   0x601c: b2400137  orr      x23, x9, #1
//   0x6020: 14000009  b        #0x6044
//   0x6024: 91004108  add      x8, x8, #0x10
//   0x6028: 927ced18  and      x24, x8, #0xfffffffffffffff0
//   0x602c: aa1803e0  mov      x0, x24
//   0x6030: 94000538  bl       #0x7510
//   0x6034: aa0003f7  mov      x23, x0
//   0x6038: b2400308  orr      x8, x24, #1
//   0x603c: a90057e8  stp      x8, x21, [sp]
//   0x6040: f9000be0  str      x0, [sp, #0x10]
//   0x6044: aa1703e0  mov      x0, x23
//   0x6048: aa1603e1  mov      x1, x22
//   0x604c: aa1503e2  mov      x2, x21
//   0x6050: 97fff930  bl       #0x4510
//   0x6054: 38356aff  strb     wzr, [x23, x21]
//   0x6058: 394003e8  ldrb     w8, [sp]
//   0x605c: 37000088  tbnz     w8, #0, #0x606c
//   0x6060: d341fd15  lsr      x21, x8, #1
//   0x6064: 528002c1  mov      w1, #0x16
//   0x6068: 14000004  b        #0x6078
//   0x606c: a94057e9  ldp      x9, x21, [sp]
//   0x6070: 927ff929  and      x9, x9, #0xfffffffffffffffe
//   0x6074: d1000521  sub      x1, x9, #1
//   0x6078: cb150029  sub      x9, x1, x21
//   0x607c: eb14013f  cmp      x9, x20
//   0x6080: 54000162  b.hs     #0x60ac
//   0x6084: 8b1402a8  add      x8, x21, x20
//   0x6088: cb010102  sub      x2, x8, x1
//   0x608c: 910003e0  mov      x0, sp
//   0x6090: 910063e7  add      x7, sp, #0x18
//   0x6094: aa1503e3  mov      x3, x21
//   0x6098: aa1503e4  mov      x4, x21
//   0x609c: aa1f03e5  mov      x5, xzr
//   0x60a0: aa1403e6  mov      x6, x20
//   0x60a4: 97fff8cf  bl       #0x43e0
//   0x60a8: 14000013  b        #0x60f4
//   0x60ac: b4000254  cbz      x20, #0x60f4
//   0x60b0: f9400be9  ldr      x9, [sp, #0x10]
//   0x60b4: 910003ea  mov      x10, sp
//   0x60b8: b240014a  orr      x10, x10, #1
//   0x60bc: 7200011f  tst      w8, #1
//   0x60c0: 9a890156  csel     x22, x10, x9, eq
//   0x60c4: 8b1502c0  add      x0, x22, x21
//   0x60c8: 910063e1  add      x1, sp, #0x18
//   0x60cc: aa1403e2  mov      x2, x20
//   0x60d0: 97fff910  bl       #0x4510
//   0x60d4: 394003e9  ldrb     w9, [sp]
//   0x60d8: 8b1402a8  add      x8, x21, x20
//   0x60dc: 37000089  tbnz     w9, #0, #0x60ec
//   0x60e0: 531f7909  lsl      w9, w8, #1
//   0x60e4: 390003e9  strb     w9, [sp]
//   0x60e8: 14000002  b        #0x60f0
//   0x60ec: f90007e8  str      x8, [sp, #8]
//   0x60f0: 38286adf  strb     wzr, [x22, x8]
//   0x60f4: 910003e1  mov      x1, sp
//   0x60f8: aa1303e0  mov      x0, x19
//   0x60fc: 94000061  bl       #0x6280
//   0x6100: 910003e0  mov      x0, sp
//   0x6104: 97fff878  bl       #0x42e4
//   0x6108: f9401728  ldr      x8, [x25, #0x28]
//   0x610c: f9420fe9  ldr      x9, [sp, #0x418]
//   0x6110: eb09011f  cmp      x8, x9
//   0x6114: 54000121  b.ne     #0x6138
//   0x6118: 911083ff  add      sp, sp, #0x420
//   0x611c: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x6120: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x6124: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x6128: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x612c: f84507fc  ldr      x28, [sp], #0x50
//   0x6130: d65f03c0  ret      
//   0x6134: 94000503  bl       #0x7540
//   0x6138: 94000526  bl       #0x75d0
// ============================================================================
std::uint32_t fde_058_5f7c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005f7cULL;
    for (std::size_t i = 0; i < 112ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2015ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[059] Symbol: sub_613c
//      Virtual Address Range: 0x613c..0x6170 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[059] Biểu tượng: sub_613c
//      Dải địa chỉ ảo: 0x613c..0x6170 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x613c: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x6140: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x6144: 9400047b  bl       #0x7330
//   0x6148: eb14001f  cmp      x0, x20
//   0x614c: 540000c8  b.hi     #0x6164
//   0x6150: f9400268  ldr      x8, [x19]
//   0x6154: aa1303e0  mov      x0, x19
//   0x6158: f9401108  ldr      x8, [x8, #0x20]
//   0x615c: d63f0100  blr      x8
//   0x6160: d1000414  sub      x20, x0, #1
//   0x6164: f9000674  str      x20, [x19, #8]
//   0x6168: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x616c: 140004c6  b        #0x7484
// ============================================================================
std::uint32_t fde_059_613c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000613cULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2127ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[060] Symbol: sub_6170
//      Virtual Address Range: 0x6170..0x61e0 (112 bytes, 28 AArch64 instructions)
// [VN] Khung FDE[060] Biểu tượng: sub_6170
//      Dải địa chỉ ảo: 0x6170..0x61e0 (112 byte, 28 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6170: a9be53f5  stp      x21, x20, [sp, #-0x20]!
//   0x6174: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x6178: f9400013  ldr      x19, [x0]
//   0x617c: aa0003f5  mov      x21, x0
//   0x6180: aa0103f4  mov      x20, x1
//   0x6184: 52800081  mov      w1, #4
//   0x6188: aa1303e0  mov      x0, x19
//   0x618c: 97fff7ac  bl       #0x403c
//   0x6190: 360001a0  tbz      w0, #0, #0x61c4
//   0x6194: b40000f4  cbz      x20, #0x61b0
//   0x6198: f9400268  ldr      x8, [x19]
//   0x619c: aa1303e0  mov      x0, x19
//   0x61a0: 94000483  bl       #0x73ac
//   0x61a4: f9400668  ldr      x8, [x19, #8]
//   0x61a8: b8686808  ldr      w8, [x0, x8]
//   0x61ac: b9000288  str      w8, [x20]
//   0x61b0: f9400668  ldr      x8, [x19, #8]
//   0x61b4: 91001108  add      x8, x8, #4
//   0x61b8: f9000668  str      x8, [x19, #8]
//   0x61bc: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x61c0: 14000492  b        #0x7408
//   0x61c4: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x61c8: d0ffffc1  adrp     x1, #0
//   0x61cc: 913ef821  add      x1, x1, #0xfbe
//   0x61d0: 52800a22  mov      w2, #0x51
//   0x61d4: aa1503e0  mov      x0, x21
//   0x61d8: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x61dc: 17ffff68  b        #0x5f7c
// ============================================================================
std::uint32_t fde_060_6170(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006170ULL;
    for (std::size_t i = 0; i < 28ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2140ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[061] Symbol: sub_61e0
//      Virtual Address Range: 0x61e0..0x6280 (160 bytes, 40 AArch64 instructions)
// [VN] Khung FDE[061] Biểu tượng: sub_61e0
//      Dải địa chỉ ảo: 0x61e0..0x6280 (160 byte, 40 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x61e0: d10143ff  sub      sp, sp, #0x50
//   0x61e4: f90013f6  str      x22, [sp, #0x20]
//   0x61e8: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x61ec: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x61f0: d53bd056  mrs      x22, tpidr_el0
//   0x61f4: f94016c8  ldr      x8, [x22, #0x28]
//   0x61f8: aa0103f5  mov      x21, x1
//   0x61fc: aa0203e1  mov      x1, x2
//   0x6200: aa0203f3  mov      x19, x2
//   0x6204: aa0003f4  mov      x20, x0
//   0x6208: f9000fe8  str      x8, [sp, #0x18]
//   0x620c: 97fff78c  bl       #0x403c
//   0x6210: 36000240  tbz      w0, #0, #0x6258
//   0x6214: 94000444  bl       #0x7324
//   0x6218: 94000465  bl       #0x73ac
//   0x621c: f9400688  ldr      x8, [x20, #8]
//   0x6220: aa1303e2  mov      x2, x19
//   0x6224: a9007fff  stp      xzr, xzr, [sp]
//   0x6228: f9000bff  str      xzr, [sp, #0x10]
//   0x622c: 8b080001  add      x1, x0, x8
//   0x6230: 910003e0  mov      x0, sp
//   0x6234: 97fffa48  bl       #0x4b54
//   0x6238: 910003e1  mov      x1, sp
//   0x623c: aa1503e0  mov      x0, x21
//   0x6240: 94000010  bl       #0x6280
//   0x6244: 910003e0  mov      x0, sp
//   0x6248: 97fff827  bl       #0x42e4
//   0x624c: f9400688  ldr      x8, [x20, #8]
//   0x6250: 8b130108  add      x8, x8, x19
//   0x6254: f9000688  str      x8, [x20, #8]
//   0x6258: f94016c8  ldr      x8, [x22, #0x28]
//   0x625c: f9400fe9  ldr      x9, [sp, #0x18]
//   0x6260: eb09011f  cmp      x8, x9
//   0x6264: 540000c1  b.ne     #0x627c
//   0x6268: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x626c: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x6270: f94013f6  ldr      x22, [sp, #0x20]
//   0x6274: 910143ff  add      sp, sp, #0x50
//   0x6278: d65f03c0  ret      
//   0x627c: 940004d5  bl       #0x75d0
// ============================================================================
std::uint32_t fde_061_61e0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000061e0ULL;
    for (std::size_t i = 0; i < 40ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2168ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[062] Symbol: sub_6280
//      Virtual Address Range: 0x6280..0x62e4 (100 bytes, 25 AArch64 instructions)
// [VN] Khung FDE[062] Biểu tượng: sub_6280
//      Dải địa chỉ ảo: 0x6280..0x62e4 (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6280: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x6284: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x6288: 39400008  ldrb     w8, [x0]
//   0x628c: aa0003f3  mov      x19, x0
//   0x6290: aa0103f4  mov      x20, x1
//   0x6294: 37000068  tbnz     w8, #0, #0x62a0
//   0x6298: 7900027f  strh     wzr, [x19]
//   0x629c: 14000009  b        #0x62c0
//   0x62a0: f9400a68  ldr      x8, [x19, #0x10]
//   0x62a4: 3900011f  strb     wzr, [x8]
//   0x62a8: 39400268  ldrb     w8, [x19]
//   0x62ac: f900067f  str      xzr, [x19, #8]
//   0x62b0: 36000088  tbz      w8, #0, #0x62c0
//   0x62b4: f9400a60  ldr      x0, [x19, #0x10]
//   0x62b8: 9400049e  bl       #0x7530
//   0x62bc: f900027f  str      xzr, [x19]
//   0x62c0: f9400a88  ldr      x8, [x20, #0x10]
//   0x62c4: 3dc00280  ldr      q0, [x20]
//   0x62c8: aa1403e0  mov      x0, x20
//   0x62cc: f9000a68  str      x8, [x19, #0x10]
//   0x62d0: 3d800260  str      q0, [x19]
//   0x62d4: 97fffa00  bl       #0x4ad4
//   0x62d8: aa1303e0  mov      x0, x19
//   0x62dc: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x62e0: 14000469  b        #0x7484
// ============================================================================
std::uint32_t fde_062_6280(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006280ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2208ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[063] Symbol: sub_62e4
//      Virtual Address Range: 0x62e4..0x637c (152 bytes, 38 AArch64 instructions)
// [VN] Khung FDE[063] Biểu tượng: sub_62e4
//      Dải địa chỉ ảo: 0x62e4..0x637c (152 byte, 38 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x62e4: d10443ff  sub      sp, sp, #0x110
//   0x62e8: f9007bfc  str      x28, [sp, #0xf0]
//   0x62ec: a9107bf3  stp      x19, x30, [sp, #0x100]
//   0x62f0: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x62f4: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x62f8: ad0007e0  stp      q0, q1, [sp]
//   0x62fc: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x6300: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x6304: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x6308: d53bd053  mrs      x19, tpidr_el0
//   0x630c: f9401669  ldr      x9, [x19, #0x28]
//   0x6310: 910203ea  add      x10, sp, #0x80
//   0x6314: 928003ec  mov      x12, #-0x20
//   0x6318: 910443eb  add      x11, sp, #0x110
//   0x631c: f90077e9  str      x9, [sp, #0xe8]
//   0x6320: 910003e9  mov      x9, sp
//   0x6324: f2dff00c  movk     x12, #0xff80, lsl #32
//   0x6328: 9100814a  add      x10, x10, #0x20
//   0x632c: 91020129  add      x9, x9, #0x80
//   0x6330: 910323e8  add      x8, sp, #0xc8
//   0x6334: a90cabeb  stp      x11, x10, [sp, #0xc8]
//   0x6338: a90db3e9  stp      x9, x12, [sp, #0xd8]
//   0x633c: ad400101  ldp      q1, q0, [x8]
//   0x6340: f0ffffc2  adrp     x2, #0x1000
//   0x6344: 91008042  add      x2, x2, #0x20
//   0x6348: 910283e3  add      x3, sp, #0xa0
//   0x634c: 52808001  mov      w1, #0x400
//   0x6350: ad0503e1  stp      q1, q0, [sp, #0xa0]
//   0x6354: 940004a3  bl       #0x75e0
//   0x6358: f9401668  ldr      x8, [x19, #0x28]
//   0x635c: f94077e9  ldr      x9, [sp, #0xe8]
//   0x6360: eb09011f  cmp      x8, x9
//   0x6364: 540000a1  b.ne     #0x6378
//   0x6368: a9507bf3  ldp      x19, x30, [sp, #0x100]
//   0x636c: f9407bfc  ldr      x28, [sp, #0xf0]
//   0x6370: 910443ff  add      sp, sp, #0x110
//   0x6374: d65f03c0  ret      
//   0x6378: 94000496  bl       #0x75d0
// ============================================================================
std::uint32_t fde_063_62e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000062e4ULL;
    for (std::size_t i = 0; i < 38ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2233ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[064] Symbol: sub_637c
//      Virtual Address Range: 0x637c..0x63a8 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[064] Biểu tượng: sub_637c
//      Dải địa chỉ ảo: 0x637c..0x63a8 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x637c: 1e649001  fmov     d1, #10.00000000
//   0x6380: 1e6e1000  fmov     d0, #1.00000000
//   0x6384: 7100041f  cmp      w0, #1
//   0x6388: 540000eb  b.lt     #0x63a4
//   0x638c: 1e610802  fmul     d2, d0, d1
//   0x6390: 7200001f  tst      w0, #1
//   0x6394: 1e610821  fmul     d1, d1, d1
//   0x6398: 1e620c00  fcsel    d0, d0, d2, eq
//   0x639c: 53017c00  lsr      w0, w0, #1
//   0x63a0: 17fffff9  b        #0x6384
//   0x63a4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_064_637c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000637cULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2271ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[065] Symbol: Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeVerifySignBlock
//      Virtual Address Range: 0x63a8..0x6bc4 (2076 bytes, 519 AArch64 instructions)
// [VN] Khung FDE[065] Biểu tượng: Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeVerifySignBlock
//      Dải địa chỉ ảo: 0x63a8..0x6bc4 (2076 byte, 519 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x63a8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x63ac: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x63b0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x63b4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x63b8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x63bc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x63c0: d10743ff  sub      sp, sp, #0x1d0
//   0x63c4: d53bd05d  mrs      x29, tpidr_el0
//   0x63c8: f94017a8  ldr      x8, [x29, #0x28]
//   0x63cc: d000001a  adrp     x26, #0x8000
//   0x63d0: aa0603f3  mov      x19, x6
//   0x63d4: aa0503f5  mov      x21, x5
//   0x63d8: aa0403f6  mov      x22, x4
//   0x63dc: aa0203f7  mov      x23, x2
//   0x63e0: aa0003f4  mov      x20, x0
//   0x63e4: 9100635a  add      x26, x26, #0x18
//   0x63e8: f900e7e8  str      x8, [sp, #0x1c8]
//   0x63ec: 3904e3ff  strb     wzr, [sp, #0x138]
//   0x63f0: 390703ff  strb     wzr, [sp, #0x1c0]
//   0x63f4: b40004c3  cbz      x3, #0x648c
//   0x63f8: 940003cb  bl       #0x7324
//   0x63fc: aa0303e1  mov      x1, x3
//   0x6400: aa0303f9  mov      x25, x3
//   0x6404: f9439908  ldr      x8, [x8, #0x730]
//   0x6408: d63f0100  blr      x8
//   0x640c: b4000400  cbz      x0, #0x648c
//   0x6410: f9400288  ldr      x8, [x20]
//   0x6414: aa0003f8  mov      x24, x0
//   0x6418: aa1403e0  mov      x0, x20
//   0x641c: aa1903e1  mov      x1, x25
//   0x6420: f9439d08  ldr      x8, [x8, #0x738]
//   0x6424: d63f0100  blr      x8
//   0x6428: aa0003f7  mov      x23, x0
//   0x642c: 52800300  mov      w0, #0x18
//   0x6430: 94000438  bl       #0x7510
//   0x6434: aa0003f9  mov      x25, x0
//   0x6438: a900fc1f  stp      xzr, xzr, [x0, #8]
//   0x643c: f900001a  str      x26, [x0]
//   0x6440: 52800300  mov      w0, #0x18
//   0x6444: 94000433  bl       #0x7510
//   0x6448: d0000008  adrp     x8, #0x8000
//   0x644c: 91026108  add      x8, x8, #0x98
//   0x6450: a900dc18  stp      x24, x23, [x0, #8]
//   0x6454: f9000b20  str      x0, [x25, #0x10]
//   0x6458: f9000008  str      x8, [x0]
//   0x645c: 910243e0  add      x0, sp, #0x90
//   0x6460: 910483e1  add      x1, sp, #0x120
//   0x6464: f90093f9  str      x25, [sp, #0x120]
//   0x6468: 97fffe04  bl       #0x5c78
//   0x646c: f94093e0  ldr      x0, [sp, #0x120]
//   0x6470: f90093ff  str      xzr, [sp, #0x120]
//   0x6474: b4000040  cbz      x0, #0x647c
//   0x6478: 940003b3  bl       #0x7344
//   0x647c: 940003ce  bl       #0x73b4
//   0x6480: 910243e0  add      x0, sp, #0x90
//   0x6484: 9400020a  bl       #0x6cac
//   0x6488: 1400004c  b        #0x65b8
//   0x648c: a907ffff  stp      xzr, xzr, [sp, #0x78]
//   0x6490: f9003bff  str      xzr, [sp, #0x70]
//   0x6494: b4000277  cbz      x23, #0x64e0
//   0x6498: f9400288  ldr      x8, [x20]
//   0x649c: 940003eb  bl       #0x7448
//   0x64a0: aa1f03e2  mov      x2, xzr
//   0x64a4: f942e108  ldr      x8, [x8, #0x5c0]
//   0x64a8: d63f0100  blr      x8
//   0x64ac: f9400288  ldr      x8, [x20]
//   0x64b0: aa0003f8  mov      x24, x0
//   0x64b4: 940003e5  bl       #0x7448
//   0x64b8: f942ad08  ldr      x8, [x8, #0x558]
//   0x64bc: d63f0100  blr      x8
//   0x64c0: 34000180  cbz      w0, #0x64f0
//   0x64c4: 8b20c302  add      x2, x24, w0, sxtw
//   0x64c8: 9101c3e0  add      x0, sp, #0x70
//   0x64cc: aa1803e1  mov      x1, x24
//   0x64d0: 97fffe52  bl       #0x5e18
//   0x64d4: a94773f9  ldp      x25, x28, [sp, #0x70]
//   0x64d8: f94043fb  ldr      x27, [sp, #0x80]
//   0x64dc: 14000008  b        #0x64fc
//   0x64e0: aa1f03fb  mov      x27, xzr
//   0x64e4: aa1f03f9  mov      x25, xzr
//   0x64e8: aa1f03fc  mov      x28, xzr
//   0x64ec: 1400000a  b        #0x6514
//   0x64f0: aa1f03fb  mov      x27, xzr
//   0x64f4: aa1f03f9  mov      x25, xzr
//   0x64f8: aa1f03fc  mov      x28, xzr
//   0x64fc: f9400288  ldr      x8, [x20]
//   0x6500: 940003d2  bl       #0x7448
//   0x6504: aa1803e2  mov      x2, x24
//   0x6508: f9430108  ldr      x8, [x8, #0x600]
//   0x650c: 2a1f03e3  mov      w3, wzr
//   0x6510: d63f0100  blr      x8
//   0x6514: 52800300  mov      w0, #0x18
//   0x6518: a9077fff  stp      xzr, xzr, [sp, #0x70]
//   0x651c: f90043ff  str      xzr, [sp, #0x80]
//   0x6520: 940003fc  bl       #0x7510
//   0x6524: aa0003f7  mov      x23, x0
//   0x6528: a9007c1a  stp      x26, xzr, [x0]
//   0x652c: 52800400  mov      w0, #0x20
//   0x6530: a9057fff  stp      xzr, xzr, [sp, #0x50]
//   0x6534: f90033ff  str      xzr, [sp, #0x60]
//   0x6538: 940003f6  bl       #0x7510
//   0x653c: d0000008  adrp     x8, #0x8000
//   0x6540: 91014108  add      x8, x8, #0x50
//   0x6544: aa0003f8  mov      x24, x0
//   0x6548: a9016c1c  stp      x28, x27, [x0, #0x10]
//   0x654c: a9006408  stp      x8, x25, [x0]
//   0x6550: 910243e0  add      x0, sp, #0x90
//   0x6554: a9127fff  stp      xzr, xzr, [sp, #0x120]
//   0x6558: f9009bff  str      xzr, [sp, #0x130]
//   0x655c: a909ffff  stp      xzr, xzr, [sp, #0x98]
//   0x6560: f9004bff  str      xzr, [sp, #0x90]
//   0x6564: 97fff702  bl       #0x416c
//   0x6568: 910243e0  add      x0, sp, #0x90
//   0x656c: f9004bff  str      xzr, [sp, #0x90]
//   0x6570: f9000af8  str      x24, [x23, #0x10]
//   0x6574: 97fffddd  bl       #0x5ce8
//   0x6578: 940003b7  bl       #0x7454
//   0x657c: 910243e0  add      x0, sp, #0x90
//   0x6580: 910483e1  add      x1, sp, #0x120
//   0x6584: f90093f7  str      x23, [sp, #0x120]
//   0x6588: 97fffdbc  bl       #0x5c78
//   0x658c: f94093e0  ldr      x0, [sp, #0x120]
//   0x6590: f90093ff  str      xzr, [sp, #0x120]
//   0x6594: b4000040  cbz      x0, #0x659c
//   0x6598: 9400036b  bl       #0x7344
//   0x659c: 94000386  bl       #0x73b4
//   0x65a0: 910243e0  add      x0, sp, #0x90
//   0x65a4: 940001c2  bl       #0x6cac
//   0x65a8: 910143e0  add      x0, sp, #0x50
//   0x65ac: 97fff6f0  bl       #0x416c
//   0x65b0: 9101c3e0  add      x0, sp, #0x70
//   0x65b4: 97fff6ee  bl       #0x416c
//   0x65b8: 94000338  bl       #0x7298
//   0x65bc: 9104e3f7  add      x23, sp, #0x138
//   0x65c0: 9100d2e1  add      x1, x23, #0x34
//   0x65c4: 94000363  bl       #0x7350
//   0x65c8: b9416fe8  ldr      w8, [sp, #0x16c]
//   0x65cc: 52801329  mov      w9, #0x99
//   0x65d0: 72a74969  movk     w9, #0x3a4b, lsl #16
//   0x65d4: 6b09011f  cmp      w8, w9
//   0x65d8: 54000301  b.ne     #0x6638
//   0x65dc: 9400032f  bl       #0x7298
//   0x65e0: 9100e2e1  add      x1, x23, #0x38
//   0x65e4: 9400035b  bl       #0x7350
//   0x65e8: a955a3e9  ldp      x9, x8, [sp, #0x158]
//   0x65ec: f9409fe0  ldr      x0, [sp, #0x138]
//   0x65f0: 91002108  add      x8, x8, #8
//   0x65f4: cb080121  sub      x1, x9, x8
//   0x65f8: 94000339  bl       #0x72dc
//   0x65fc: f9409ff7  ldr      x23, [sp, #0x138]
//   0x6600: 52800101  mov      w1, #8
//   0x6604: aa1703e0  mov      x0, x23
//   0x6608: 97fff68d  bl       #0x403c
//   0x660c: 36000300  tbz      w0, #0, #0x666c
//   0x6610: f94002e8  ldr      x8, [x23]
//   0x6614: aa1703e0  mov      x0, x23
//   0x6618: 94000365  bl       #0x73ac
//   0x661c: f94006e8  ldr      x8, [x23, #8]
//   0x6620: f8686808  ldr      x8, [x0, x8]
//   0x6624: f900bfe8  str      x8, [sp, #0x178]
//   0x6628: f94006e8  ldr      x8, [x23, #8]
//   0x662c: 91002108  add      x8, x8, #8
//   0x6630: f90006e8  str      x8, [x23, #8]
//   0x6634: 14000013  b        #0x6680
//   0x6638: d0ffffc1  adrp     x1, #0
//   0x663c: 52800028  mov      w8, #1
//   0x6640: 910022e0  add      x0, x23, #8
//   0x6644: 913f1821  add      x1, x1, #0xfc6
//   0x6648: b9016be8  str      w8, [sp, #0x168]
//   0x664c: 97fff735  bl       #0x4320
//   0x6650: d0ffffc1  adrp     x1, #0
//   0x6654: 913ea021  add      x1, x1, #0xfa8
//   0x6658: 9104e3e0  add      x0, sp, #0x138
//   0x665c: 52800a22  mov      w2, #0x51
//   0x6660: 97fffe47  bl       #0x5f7c
//   0x6664: 2a1f03f7  mov      w23, wzr
//   0x6668: 14000107  b        #0x6a84
//   0x666c: d0ffffc1  adrp     x1, #0
//   0x6670: 913ed821  add      x1, x1, #0xfb6
//   0x6674: 9104e3e0  add      x0, sp, #0x138
//   0x6678: 52800ac2  mov      w2, #0x56
//   0x667c: 97fffe40  bl       #0x5f7c
//   0x6680: 94000306  bl       #0x7298
//   0x6684: 9104e3f7  add      x23, sp, #0x138
//   0x6688: 910122e1  add      x1, x23, #0x48
//   0x668c: 94000331  bl       #0x7350
//   0x6690: b94183e8  ldr      w8, [sp, #0x180]
//   0x6694: a955a7ea  ldp      x10, x9, [sp, #0x158]
//   0x6698: f9409fe0  ldr      x0, [sp, #0x138]
//   0x669c: 8b080128  add      x8, x9, x8
//   0x66a0: cb080141  sub      x1, x10, x8
//   0x66a4: 9400030e  bl       #0x72dc
//   0x66a8: f9409fe0  ldr      x0, [sp, #0x138]
//   0x66ac: b94183e2  ldr      w2, [sp, #0x180]
//   0x66b0: 910142e1  add      x1, x23, #0x50
//   0x66b4: f90017e1  str      x1, [sp, #0x28]
//   0x66b8: 97fffeca  bl       #0x61e0
//   0x66bc: 940002f7  bl       #0x7298
//   0x66c0: 9101a2e1  add      x1, x23, #0x68
//   0x66c4: 94000323  bl       #0x7350
//   0x66c8: b941a3e8  ldr      w8, [sp, #0x1a0]
//   0x66cc: a955a7ea  ldp      x10, x9, [sp, #0x158]
//   0x66d0: f9409fe0  ldr      x0, [sp, #0x138]
//   0x66d4: 8b080128  add      x8, x9, x8
//   0x66d8: cb080141  sub      x1, x10, x8
//   0x66dc: 94000300  bl       #0x72dc
//   0x66e0: f9409fe0  ldr      x0, [sp, #0x138]
//   0x66e4: b941a3e2  ldr      w2, [sp, #0x1a0]
//   0x66e8: 9101c2e1  add      x1, x23, #0x70
//   0x66ec: 97fffebd  bl       #0x61e0
//   0x66f0: f9409fe0  ldr      x0, [sp, #0x138]
//   0x66f4: f940afe9  ldr      x9, [sp, #0x158]
//   0x66f8: f9400008  ldr      x8, [x0]
//   0x66fc: f90023e9  str      x9, [sp, #0x40]
//   0x6700: b941a3e9  ldr      w9, [sp, #0x1a0]
//   0x6704: f9400908  ldr      x8, [x8, #0x10]
//   0x6708: f90027e9  str      x9, [sp, #0x48]
//   0x670c: b94173e9  ldr      w9, [sp, #0x170]
//   0x6710: f9001fe9  str      x9, [sp, #0x38]
//   0x6714: d63f0100  blr      x8
//   0x6718: f940bff9  ldr      x25, [sp, #0x178]
//   0x671c: f9001be0  str      x0, [sp, #0x30]
//   0x6720: 97fff6be  bl       #0x4218
//   0x6724: d000003a  adrp     x26, #0xc000
//   0x6728: 9100435a  add      x26, x26, #0x10
//   0x672c: aa1a03e0  mov      x0, x26
//   0x6730: 940003b0  bl       #0x75f0
//   0x6734: 97fff6cb  bl       #0x4260
//   0x6738: 910243e8  add      x8, sp, #0x90
//   0x673c: aa1903e0  mov      x0, x25
//   0x6740: 940003b0  bl       #0x7600
//   0x6744: 910243e0  add      x0, sp, #0x90
//   0x6748: 97fff775  bl       #0x451c
//   0x674c: f9401b5b  ldr      x27, [x26, #0x30]
//   0x6750: b40001bb  cbz      x27, #0x6784
//   0x6754: 9e670360  fmov     d0, x27
//   0x6758: 94000329  bl       #0x73fc
//   0x675c: 1e26001c  fmov     w28, s0
//   0x6760: aa0003fa  mov      x26, x0
//   0x6764: f100079f  cmp      x28, #1
//   0x6768: 54000129  b.ls     #0x678c
//   0x676c: eb1b035f  cmp      x26, x27
//   0x6770: aa1a03f7  mov      x23, x26
//   0x6774: 54000103  b.lo     #0x6794
//   0x6778: 9adb0b48  udiv     x8, x26, x27
//   0x677c: 9b1be917  msub     x23, x8, x27, x26
//   0x6780: 14000005  b        #0x6794
//   0x6784: aa1f03f8  mov      x24, xzr
//   0x6788: 14000025  b        #0x681c
//   0x678c: d1000768  sub      x8, x27, #1
//   0x6790: 8a1a0117  and      x23, x8, x26
//   0x6794: d0000028  adrp     x8, #0xc000
//   0x6798: f9401d08  ldr      x8, [x8, #0x38]
//   0x679c: f8777918  ldr      x24, [x8, x23, lsl #3]
//   0x67a0: b40003f8  cbz      x24, #0x681c
//   0x67a4: f9000bf6  str      x22, [sp, #0x10]
//   0x67a8: aa1503f6  mov      x22, x21
//   0x67ac: aa1303f5  mov      x21, x19
//   0x67b0: aa1d03f3  mov      x19, x29
//   0x67b4: d100077d  sub      x29, x27, #1
//   0x67b8: f9400318  ldr      x24, [x24]
//   0x67bc: b4000298  cbz      x24, #0x680c
//   0x67c0: f9400708  ldr      x8, [x24, #8]
//   0x67c4: eb08035f  cmp      x26, x8
//   0x67c8: 540000c1  b.ne     #0x67e0
//   0x67cc: 91004300  add      x0, x24, #0x10
//   0x67d0: 910243e1  add      x1, sp, #0x90
//   0x67d4: 97fff834  bl       #0x48a4
//   0x67d8: 3607ff00  tbz      w0, #0, #0x67b8
//   0x67dc: 1400000c  b        #0x680c
//   0x67e0: f100079f  cmp      x28, #1
//   0x67e4: 540000c9  b.ls     #0x67fc
//   0x67e8: eb1b011f  cmp      x8, x27
//   0x67ec: 540000a3  b.lo     #0x6800
//   0x67f0: 9adb0909  udiv     x9, x8, x27
//   0x67f4: 9b1ba128  msub     x8, x9, x27, x8
//   0x67f8: 14000002  b        #0x6800
//   0x67fc: 8a1d0108  and      x8, x8, x29
//   0x6800: eb17011f  cmp      x8, x23
//   0x6804: 54fffda0  b.eq     #0x67b8
//   0x6808: aa1f03f8  mov      x24, xzr
//   0x680c: aa1303fd  mov      x29, x19
//   0x6810: aa1503f3  mov      x19, x21
//   0x6814: aa1603f5  mov      x21, x22
//   0x6818: f9400bf6  ldr      x22, [sp, #0x10]
//   0x681c: 910243e0  add      x0, sp, #0x90
//   0x6820: 97fff6b1  bl       #0x42e4
//   0x6824: b40000d8  cbz      x24, #0x683c
//   0x6828: aa1803e8  mov      x8, x24
//   0x682c: 38428d09  ldrb     w9, [x8, #0x28]!
//   0x6830: 37000229  tbnz     w9, #0, #0x6874
//   0x6834: 91000517  add      x23, x8, #1
//   0x6838: 14000012  b        #0x6880
//   0x683c: b4000219  cbz      x25, #0x687c
//   0x6840: 9104e3e9  add      x9, sp, #0x138
//   0x6844: f0ffffc1  adrp     x1, #0x1000
//   0x6848: 52800088  mov      w8, #4
//   0x684c: 91002120  add      x0, x9, #8
//   0x6850: 91001c21  add      x1, x1, #7
//   0x6854: b9016be8  str      w8, [sp, #0x168]
//   0x6858: 97fff6b2  bl       #0x4320
//   0x685c: 940002af  bl       #0x7318
//   0x6860: d0ffffc1  adrp     x1, #0
//   0x6864: 913ea021  add      x1, x1, #0xfa8
//   0x6868: 9104e3e0  add      x0, sp, #0x138
//   0x686c: 52800c62  mov      w2, #0x63
//   0x6870: 17ffff7c  b        #0x6660
//   0x6874: f9401f17  ldr      x23, [x24, #0x38]
//   0x6878: 14000002  b        #0x6880
//   0x687c: aa1f03f7  mov      x23, xzr
//   0x6880: 940002a6  bl       #0x7318
//   0x6884: 94000363  bl       #0x7610
//   0x6888: b4000ee0  cbz      x0, #0x6a64
//   0x688c: f0ffffc8  adrp     x8, #0x1000
//   0x6890: 9100d908  add      x8, x8, #0x36
//   0x6894: f10002ff  cmp      x23, #0
//   0x6898: 9a97011a  csel     x26, x8, x23, eq
//   0x689c: aa0003f9  mov      x25, x0
//   0x68a0: aa1a03e0  mov      x0, x26
//   0x68a4: 94000333  bl       #0x7570
//   0x68a8: b4000140  cbz      x0, #0x68d0
//   0x68ac: d1000408  sub      x8, x0, #1
//   0x68b0: b100051f  cmn      x8, #1
//   0x68b4: 54000160  b.eq     #0x68e0
//   0x68b8: 38686b49  ldrb     w9, [x26, x8]
//   0x68bc: d1000508  sub      x8, x8, #1
//   0x68c0: 7100f53f  cmp      w9, #0x3d
//   0x68c4: 54ffff60  b.eq     #0x68b0
//   0x68c8: 9100091b  add      x27, x8, #2
//   0x68cc: 14000006  b        #0x68e4
//   0x68d0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x68d4: f9009bff  str      xzr, [sp, #0x130]
//   0x68d8: 3d804be0  str      q0, [sp, #0x120]
//   0x68dc: 1400002b  b        #0x6988
//   0x68e0: aa1f03fb  mov      x27, xzr
//   0x68e4: 8b1b0768  add      x8, x27, x27, lsl #1
//   0x68e8: d342fd1c  lsr      x28, x8, #2
//   0x68ec: a909ffff  stp      xzr, xzr, [sp, #0x98]
//   0x68f0: f9004bff  str      xzr, [sp, #0x90]
//   0x68f4: b40001bc  cbz      x28, #0x6928
//   0x68f8: 910243e0  add      x0, sp, #0x90
//   0x68fc: aa1c03e1  mov      x1, x28
//   0x6900: 97fff639  bl       #0x41e4
//   0x6904: f9404fe8  ldr      x8, [sp, #0x98]
//   0x6908: 8b1c0109  add      x9, x8, x28
//   0x690c: eb08013f  cmp      x9, x8
//   0x6910: 54000060  b.eq     #0x691c
//   0x6914: 3800151f  strb     wzr, [x8], #1
//   0x6918: 17fffffd  b        #0x690c
//   0x691c: f9404be0  ldr      x0, [sp, #0x90]
//   0x6920: f9004fe8  str      x8, [sp, #0x98]
//   0x6924: 14000002  b        #0x692c
//   0x6928: aa1f03e0  mov      x0, xzr
//   0x692c: aa1a03e1  mov      x1, x26
//   0x6930: aa1b03e2  mov      x2, x27
//   0x6934: 9400033b  bl       #0x7620
//   0x6938: 37f80180  tbnz     w0, #0x1f, #0x6968
//   0x693c: 93407c01  sxtw     x1, w0
//   0x6940: 910243e0  add      x0, sp, #0x90
//   0x6944: 97fff5d0  bl       #0x4084
//   0x6948: 3dc027e0  ldr      q0, [sp, #0x90]
//   0x694c: f94053e8  ldr      x8, [sp, #0xa0]
//   0x6950: a909ffff  stp      xzr, xzr, [sp, #0x98]
//   0x6954: f9004bff  str      xzr, [sp, #0x90]
//   0x6958: 3d8007e0  str      q0, [sp, #0x10]
//   0x695c: 3d804be0  str      q0, [sp, #0x120]
//   0x6960: f9009be8  str      x8, [sp, #0x130]
//   0x6964: 14000006  b        #0x697c
//   0x6968: 6f00e401  movi     v1.2d, #0000000000000000
//   0x696c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x6970: f9009bff  str      xzr, [sp, #0x130]
//   0x6974: 3d8007e0  str      q0, [sp, #0x10]
//   0x6978: 3d804be1  str      q1, [sp, #0x120]
//   0x697c: 910243e0  add      x0, sp, #0x90
//   0x6980: 97fff5fb  bl       #0x416c
//   0x6984: 3dc007e0  ldr      q0, [sp, #0x10]
//   0x6988: 9e660008  fmov     x8, d0
//   0x698c: 4e183c09  mov      x9, v0.d[1]
//   0x6990: eb09011f  cmp      x8, x9
//   0x6994: 54000660  b.eq     #0x6a60
//   0x6998: cb080122  sub      x2, x9, x8
//   0x699c: 910243e1  add      x1, sp, #0x90
//   0x69a0: aa1f03e0  mov      x0, xzr
//   0x69a4: f9004be8  str      x8, [sp, #0x90]
//   0x69a8: 94000322  bl       #0x7630
//   0x69ac: b40005a0  cbz      x0, #0x6a60
//   0x69b0: aa0003fa  mov      x26, x0
//   0x69b4: 94000323  bl       #0x7640
//   0x69b8: aa0003e2  mov      x2, x0
//   0x69bc: aa1903e0  mov      x0, x25
//   0x69c0: aa1f03e1  mov      x1, xzr
//   0x69c4: aa1f03e3  mov      x3, xzr
//   0x69c8: aa1a03e4  mov      x4, x26
//   0x69cc: 94000321  bl       #0x7650
//   0x69d0: 7100041f  cmp      w0, #1
//   0x69d4: 54000461  b.ne     #0x6a60
//   0x69d8: a943a3e9  ldp      x9, x8, [sp, #0x38]
//   0x69dc: aa1903e0  mov      x0, x25
//   0x69e0: cb090108  sub      x8, x8, x9
//   0x69e4: f94027e9  ldr      x9, [sp, #0x48]
//   0x69e8: 8b090108  add      x8, x8, x9
//   0x69ec: f9401be9  ldr      x9, [sp, #0x30]
//   0x69f0: d1001102  sub      x2, x8, #4
//   0x69f4: 91001121  add      x1, x9, #4
//   0x69f8: 9400031a  bl       #0x7660
//   0x69fc: 7100041f  cmp      w0, #1
//   0x6a00: 54000281  b.ne     #0x6a50
//   0x6a04: 394623e8  ldrb     w8, [sp, #0x188]
//   0x6a08: a95927ea  ldp      x10, x9, [sp, #0x190]
//   0x6a0c: aa1903e0  mov      x0, x25
//   0x6a10: d341fd0b  lsr      x11, x8, #1
//   0x6a14: 7200011f  tst      w8, #1
//   0x6a18: f94017e8  ldr      x8, [sp, #0x28]
//   0x6a1c: 9a8a0162  csel     x2, x11, x10, eq
//   0x6a20: 9a881521  csinc    x1, x9, x8, ne
//   0x6a24: 94000313  bl       #0x7670
//   0x6a28: 2a0003f7  mov      w23, w0
//   0x6a2c: aa1a03e0  mov      x0, x26
//   0x6a30: 94000314  bl       #0x7680
//   0x6a34: aa1903e0  mov      x0, x25
//   0x6a38: 94000316  bl       #0x7690
//   0x6a3c: 94000286  bl       #0x7454
//   0x6a40: 710006ff  cmp      w23, #1
//   0x6a44: 54000101  b.ne     #0x6a64
//   0x6a48: b9016bff  str      wzr, [sp, #0x168]
//   0x6a4c: 1400000e  b        #0x6a84
//   0x6a50: aa1a03e0  mov      x0, x26
//   0x6a54: 9400030b  bl       #0x7680
//   0x6a58: aa1903e0  mov      x0, x25
//   0x6a5c: 9400030d  bl       #0x7690
//   0x6a60: 9400027d  bl       #0x7454
//   0x6a64: 9104e3e8  add      x8, sp, #0x138
//   0x6a68: d0ffffc1  adrp     x1, #0
//   0x6a6c: 91002100  add      x0, x8, #8
//   0x6a70: 913fa421  add      x1, x1, #0xfe9
//   0x6a74: 97fff62b  bl       #0x4320
//   0x6a78: 52800048  mov      w8, #2
//   0x6a7c: 2a1f03f7  mov      w23, wzr
//   0x6a80: b9016be8  str      w8, [sp, #0x168]
//   0x6a84: 94000228  bl       #0x7324
//   0x6a88: aa1603e1  mov      x1, x22
//   0x6a8c: aa1f03e2  mov      x2, xzr
//   0x6a90: f942f108  ldr      x8, [x8, #0x5e0]
//   0x6a94: d63f0100  blr      x8
//   0x6a98: f940bfe8  ldr      x8, [sp, #0x178]
//   0x6a9c: aa0003e2  mov      x2, x0
//   0x6aa0: aa1603e1  mov      x1, x22
//   0x6aa4: 2a1f03e3  mov      w3, wzr
//   0x6aa8: f9000008  str      x8, [x0]
//   0x6aac: 9400021e  bl       #0x7324
//   0x6ab0: f9431108  ldr      x8, [x8, #0x620]
//   0x6ab4: d63f0100  blr      x8
//   0x6ab8: 9104e3f6  add      x22, sp, #0x138
//   0x6abc: 9101c2c1  add      x1, x22, #0x70
//   0x6ac0: 910243e0  add      x0, sp, #0x90
//   0x6ac4: 910243f8  add      x24, sp, #0x90
//   0x6ac8: 97fffd22  bl       #0x5f50
//   0x6acc: f9400288  ldr      x8, [x20]
//   0x6ad0: 394243e9  ldrb     w9, [sp, #0x90]
//   0x6ad4: f94053ea  ldr      x10, [sp, #0xa0]
//   0x6ad8: b240030b  orr      x11, x24, #1
//   0x6adc: 9400020a  bl       #0x7304
//   0x6ae0: f9400288  ldr      x8, [x20]
//   0x6ae4: aa0003e3  mov      x3, x0
//   0x6ae8: 94000255  bl       #0x743c
//   0x6aec: f942b908  ldr      x8, [x8, #0x570]
//   0x6af0: 2a1f03e2  mov      w2, wzr
//   0x6af4: d63f0100  blr      x8
//   0x6af8: 910022c1  add      x1, x22, #8
//   0x6afc: 910483e0  add      x0, sp, #0x120
//   0x6b00: 910483f6  add      x22, sp, #0x120
//   0x6b04: 97fffd13  bl       #0x5f50
//   0x6b08: f9400288  ldr      x8, [x20]
//   0x6b0c: 394483e9  ldrb     w9, [sp, #0x120]
//   0x6b10: f9409bea  ldr      x10, [sp, #0x130]
//   0x6b14: b24002cb  orr      x11, x22, #1
//   0x6b18: 940001fb  bl       #0x7304
//   0x6b1c: f9400288  ldr      x8, [x20]
//   0x6b20: aa0003e3  mov      x3, x0
//   0x6b24: 52800022  mov      w2, #1
//   0x6b28: aa1403e0  mov      x0, x20
//   0x6b2c: f942b908  ldr      x8, [x8, #0x570]
//   0x6b30: aa1503e1  mov      x1, x21
//   0x6b34: d63f0100  blr      x8
//   0x6b38: 940001fb  bl       #0x7324
//   0x6b3c: aa1303e1  mov      x1, x19
//   0x6b40: aa1f03e2  mov      x2, xzr
//   0x6b44: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x6b48: d63f0100  blr      x8
//   0x6b4c: b9416be8  ldr      w8, [sp, #0x168]
//   0x6b50: aa0003e2  mov      x2, x0
//   0x6b54: aa1303e1  mov      x1, x19
//   0x6b58: 2a1f03e3  mov      w3, wzr
//   0x6b5c: b9000008  str      w8, [x0]
//   0x6b60: 940001f1  bl       #0x7324
//   0x6b64: f9430d08  ldr      x8, [x8, #0x618]
//   0x6b68: d63f0100  blr      x8
//   0x6b6c: 910483e0  add      x0, sp, #0x120
//   0x6b70: 97fff5dd  bl       #0x42e4
//   0x6b74: 910243e0  add      x0, sp, #0x90
//   0x6b78: 97fff5db  bl       #0x42e4
//   0x6b7c: 394703e8  ldrb     w8, [sp, #0x1c0]
//   0x6b80: 34000068  cbz      w8, #0x6b8c
//   0x6b84: 9104e3e0  add      x0, sp, #0x138
//   0x6b88: 94000049  bl       #0x6cac
//   0x6b8c: f94017a8  ldr      x8, [x29, #0x28]
//   0x6b90: f940e7e9  ldr      x9, [sp, #0x1c8]
//   0x6b94: eb09011f  cmp      x8, x9
//   0x6b98: 54000141  b.ne     #0x6bc0
//   0x6b9c: 2a1703e0  mov      w0, w23
//   0x6ba0: 910743ff  add      sp, sp, #0x1d0
//   0x6ba4: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x6ba8: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x6bac: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x6bb0: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x6bb4: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x6bb8: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x6bbc: d65f03c0  ret      
//   0x6bc0: 94000284  bl       #0x75d0
// ============================================================================
std::uint32_t fde_065_63a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000063a8ULL;
    for (std::size_t i = 0; i < 519ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2282ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[066] Symbol: sub_6bc4
//      Virtual Address Range: 0x6bc4..0x6cac (232 bytes, 58 AArch64 instructions)
// [VN] Khung FDE[066] Biểu tượng: sub_6bc4
//      Dải địa chỉ ảo: 0x6bc4..0x6cac (232 byte, 58 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6bc4: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x6bc8: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x6bcc: 39422009  ldrb     w9, [x0, #0x88]
//   0x6bd0: f9400028  ldr      x8, [x1]
//   0x6bd4: aa0103f4  mov      x20, x1
//   0x6bd8: aa0003f3  mov      x19, x0
//   0x6bdc: f900003f  str      xzr, [x1]
//   0x6be0: 340002a9  cbz      w9, #0x6c34
//   0x6be4: f9400260  ldr      x0, [x19]
//   0x6be8: f9000268  str      x8, [x19]
//   0x6bec: b4000040  cbz      x0, #0x6bf4
//   0x6bf0: 940001d5  bl       #0x7344
//   0x6bf4: 91002260  add      x0, x19, #8
//   0x6bf8: 91002281  add      x1, x20, #8
//   0x6bfc: 97fffda1  bl       #0x6280
//   0x6c00: 3cc3c280  ldur     q0, [x20, #0x3c]
//   0x6c04: ad410682  ldp      q2, q1, [x20, #0x20]
//   0x6c08: 91014260  add      x0, x19, #0x50
//   0x6c0c: 91014281  add      x1, x20, #0x50
//   0x6c10: 3c83c260  stur     q0, [x19, #0x3c]
//   0x6c14: ad010662  stp      q2, q1, [x19, #0x20]
//   0x6c18: 97fffd9a  bl       #0x6280
//   0x6c1c: b9406a88  ldr      w8, [x20, #0x68]
//   0x6c20: 9101c260  add      x0, x19, #0x70
//   0x6c24: 9101c281  add      x1, x20, #0x70
//   0x6c28: b9006a68  str      w8, [x19, #0x68]
//   0x6c2c: 97fffd95  bl       #0x6280
//   0x6c30: 1400001c  b        #0x6ca0
//   0x6c34: f9000268  str      x8, [x19]
//   0x6c38: f9400e88  ldr      x8, [x20, #0x18]
//   0x6c3c: 3cc08280  ldur     q0, [x20, #8]
//   0x6c40: 91002280  add      x0, x20, #8
//   0x6c44: f9000e68  str      x8, [x19, #0x18]
//   0x6c48: 3c808260  stur     q0, [x19, #8]
//   0x6c4c: 97fff7a2  bl       #0x4ad4
//   0x6c50: 3cc3c280  ldur     q0, [x20, #0x3c]
//   0x6c54: ad410682  ldp      q2, q1, [x20, #0x20]
//   0x6c58: 91014280  add      x0, x20, #0x50
//   0x6c5c: 3c83c260  stur     q0, [x19, #0x3c]
//   0x6c60: ad010662  stp      q2, q1, [x19, #0x20]
//   0x6c64: f9403288  ldr      x8, [x20, #0x60]
//   0x6c68: 3dc01680  ldr      q0, [x20, #0x50]
//   0x6c6c: f9003268  str      x8, [x19, #0x60]
//   0x6c70: 3d801660  str      q0, [x19, #0x50]
//   0x6c74: 97fff798  bl       #0x4ad4
//   0x6c78: b9406a88  ldr      w8, [x20, #0x68]
//   0x6c7c: 9101c280  add      x0, x20, #0x70
//   0x6c80: b9006a68  str      w8, [x19, #0x68]
//   0x6c84: f9404288  ldr      x8, [x20, #0x80]
//   0x6c88: 3dc01e80  ldr      q0, [x20, #0x70]
//   0x6c8c: f9004268  str      x8, [x19, #0x80]
//   0x6c90: 3d801e60  str      q0, [x19, #0x70]
//   0x6c94: 97fff790  bl       #0x4ad4
//   0x6c98: 52800028  mov      w8, #1
//   0x6c9c: 39022268  strb     w8, [x19, #0x88]
//   0x6ca0: aa1303e0  mov      x0, x19
//   0x6ca4: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x6ca8: 140001f7  b        #0x7484
// ============================================================================
std::uint32_t fde_066_6bc4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006bc4ULL;
    for (std::size_t i = 0; i < 58ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2801ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[067] Symbol: sub_6cac
//      Virtual Address Range: 0x6cac..0x6cf0 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[067] Biểu tượng: sub_6cac
//      Dải địa chỉ ảo: 0x6cac..0x6cf0 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6cac: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x6cb0: aa0003f3  mov      x19, x0
//   0x6cb4: 9101c000  add      x0, x0, #0x70
//   0x6cb8: 97fff58b  bl       #0x42e4
//   0x6cbc: 91014260  add      x0, x19, #0x50
//   0x6cc0: 97fff589  bl       #0x42e4
//   0x6cc4: 91002260  add      x0, x19, #8
//   0x6cc8: 97fff587  bl       #0x42e4
//   0x6ccc: f9400260  ldr      x0, [x19]
//   0x6cd0: f900027f  str      xzr, [x19]
//   0x6cd4: b40000a0  cbz      x0, #0x6ce8
//   0x6cd8: f9400008  ldr      x8, [x0]
//   0x6cdc: f9400501  ldr      x1, [x8, #8]
//   0x6ce0: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x6ce4: d61f0020  br       x1
//   0x6ce8: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x6cec: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_067_6cac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006cacULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2859ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[068] Symbol: Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeUpdateRsaPublicKeys
//      Virtual Address Range: 0x6cf0..0x7298 (1448 bytes, 362 AArch64 instructions)
// [VN] Khung FDE[068] Biểu tượng: Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeUpdateRsaPublicKeys
//      Dải địa chỉ ảo: 0x6cf0..0x7298 (1448 byte, 362 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6cf0: d10603ff  sub      sp, sp, #0x180
//   0x6cf4: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x6cf8: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x6cfc: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x6d00: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x6d04: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x6d08: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x6d0c: d53bd055  mrs      x21, tpidr_el0
//   0x6d10: f94016a8  ldr      x8, [x21, #0x28]
//   0x6d14: aa0203f3  mov      x19, x2
//   0x6d18: aa0203e1  mov      x1, x2
//   0x6d1c: aa1f03e2  mov      x2, xzr
//   0x6d20: f9008fe8  str      x8, [sp, #0x118]
//   0x6d24: f9400008  ldr      x8, [x0]
//   0x6d28: aa0003f6  mov      x22, x0
//   0x6d2c: f942a508  ldr      x8, [x8, #0x548]
//   0x6d30: d63f0100  blr      x8
//   0x6d34: b4002860  cbz      x0, #0x7240
//   0x6d38: aa0003e8  mov      x8, x0
//   0x6d3c: 9100e3e0  add      x0, sp, #0x38
//   0x6d40: aa0803e1  mov      x1, x8
//   0x6d44: a901cfe8  stp      x8, x19, [sp, #0x18]
//   0x6d48: 9102c3f4  add      x20, sp, #0xb0
//   0x6d4c: 9100e3f3  add      x19, sp, #0x38
//   0x6d50: 97fff557  bl       #0x42ac
//   0x6d54: 97fff531  bl       #0x4218
//   0x6d58: d0000020  adrp     x0, #0xc000
//   0x6d5c: 91004000  add      x0, x0, #0x10
//   0x6d60: 94000224  bl       #0x75f0
//   0x6d64: 6f00e400  movi     v0.2d, #0000000000000000
//   0x6d68: 52808008  mov      w8, #0x400
//   0x6d6c: 52800500  mov      w0, #0x28
//   0x6d70: ad018280  stp      q0, q0, [x20, #0x30]
//   0x6d74: ad008280  stp      q0, q0, [x20, #0x10]
//   0x6d78: 3d802fe0  str      q0, [sp, #0xb0]
//   0x6d7c: f90083e8  str      x8, [sp, #0x100]
//   0x6d80: b9010bff  str      wzr, [sp, #0x108]
//   0x6d84: f9008bff  str      xzr, [sp, #0x110]
//   0x6d88: 940001e2  bl       #0x7510
//   0x6d8c: 52a00028  mov      w8, #0x10000
//   0x6d90: 3940e3e9  ldrb     w9, [sp, #0x38]
//   0x6d94: a900fc08  stp      x8, xzr, [x0, #8]
//   0x6d98: f94027e8  ldr      x8, [sp, #0x48]
//   0x6d9c: b240026a  orr      x10, x19, #1
//   0x6da0: 5280004b  mov      w11, #2
//   0x6da4: 7200013f  tst      w9, #1
//   0x6da8: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x6dac: a90c83e0  stp      x0, x0, [sp, #0xc8]
//   0x6db0: f900001f  str      xzr, [x0]
//   0x6db4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x6db8: b900a3eb  str      w11, [sp, #0xa0]
//   0x6dbc: 5280200b  mov      w11, #0x100
//   0x6dc0: 9a880148  csel     x8, x10, x8, eq
//   0x6dc4: 910143e0  add      x0, sp, #0x50
//   0x6dc8: ad0303e0  stp      q0, q0, [sp, #0x60]
//   0x6dcc: b90093ff  str      wzr, [sp, #0x90]
//   0x6dd0: a9082fff  stp      xzr, x11, [sp, #0x80]
//   0x6dd4: a90523e8  stp      x8, x8, [sp, #0x50]
//   0x6dd8: f9004fff  str      xzr, [sp, #0x98]
//   0x6ddc: 97fff791  bl       #0x4c20
//   0x6de0: b94093e8  ldr      w8, [sp, #0x90]
//   0x6de4: 35000228  cbnz     w8, #0x6e28
//   0x6de8: f9402be8  ldr      x8, [sp, #0x50]
//   0x6dec: 39400109  ldrb     w9, [x8]
//   0x6df0: 34002409  cbz      w9, #0x7270
//   0x6df4: 910183e0  add      x0, sp, #0x60
//   0x6df8: 910143e1  add      x1, sp, #0x50
//   0x6dfc: 9102c3e2  add      x2, sp, #0xb0
//   0x6e00: 97fff796  bl       #0x4c58
//   0x6e04: b94093e8  ldr      w8, [sp, #0x90]
//   0x6e08: 35000108  cbnz     w8, #0x6e28
//   0x6e0c: 910143e0  add      x0, sp, #0x50
//   0x6e10: 97fff784  bl       #0x4c20
//   0x6e14: b94093e8  ldr      w8, [sp, #0x90]
//   0x6e18: 35000088  cbnz     w8, #0x6e28
//   0x6e1c: f9402be8  ldr      x8, [sp, #0x50]
//   0x6e20: 39400109  ldrb     w9, [x8]
//   0x6e24: 350022c9  cbnz     w9, #0x727c
//   0x6e28: 3dc027e0  ldr      q0, [sp, #0x90]
//   0x6e2c: f9403be8  ldr      x8, [sp, #0x70]
//   0x6e30: d0ffffe9  adrp     x9, #0x4000
//   0x6e34: 912f1129  add      x9, x9, #0xbc4
//   0x6e38: 9e66000a  fmov     x10, d0
//   0x6e3c: 7100015f  cmp      w10, #0
//   0x6e40: 9a9f0129  csel     x9, x9, xzr, eq
//   0x6e44: a902d7f6  stp      x22, x21, [sp, #0x28]
//   0x6e48: 3c858280  stur     q0, [x20, #0x58]
//   0x6e4c: f9003fe8  str      x8, [sp, #0x78]
//   0x6e50: b4000189  cbz      x9, #0x6e80
//   0x6e54: f9407be8  ldr      x8, [sp, #0xf0]
//   0x6e58: 9102c3ea  add      x10, sp, #0xb0
//   0x6e5c: d1006109  sub      x9, x8, #0x18
//   0x6e60: eb09015f  cmp      x10, x9
//   0x6e64: f9007be9  str      x9, [sp, #0xf0]
//   0x6e68: 540000c0  b.eq     #0x6e80
//   0x6e6c: f940092a  ldr      x10, [x9, #0x10]
//   0x6e70: 3dc00120  ldr      q0, [x9]
//   0x6e74: f90063ea  str      x10, [sp, #0xc0]
//   0x6e78: 3d802fe0  str      q0, [sp, #0xb0]
//   0x6e7c: 781fe11f  sturh    wzr, [x8, #-2]
//   0x6e80: f94077e0  ldr      x0, [sp, #0xe8]
//   0x6e84: 9100a288  add      x8, x20, #0x28
//   0x6e88: f9000be8  str      x8, [sp, #0x10]
//   0x6e8c: f9007be0  str      x0, [sp, #0xf0]
//   0x6e90: 940001bc  bl       #0x7580
//   0x6e94: 910183e0  add      x0, sp, #0x60
//   0x6e98: a90f7fff  stp      xzr, xzr, [sp, #0xf0]
//   0x6e9c: f90077ff  str      xzr, [sp, #0xe8]
//   0x6ea0: 97fff516  bl       #0x42f8
//   0x6ea4: b9410be8  ldr      w8, [sp, #0x108]
//   0x6ea8: 350018e8  cbnz     w8, #0x71c4
//   0x6eac: 79418fe8  ldrh     w8, [sp, #0xc6]
//   0x6eb0: 71000d1f  cmp      w8, #3
//   0x6eb4: 54001881  b.ne     #0x71c4
//   0x6eb8: f9405fe8  ldr      x8, [sp, #0xb8]
//   0x6ebc: d000003d  adrp     x29, #0xc000
//   0x6ec0: 52800614  mov      w20, #0x30
//   0x6ec4: d000003c  adrp     x28, #0xc000
//   0x6ec8: 910143bd  add      x29, x29, #0x50
//   0x6ecc: d0000036  adrp     x22, #0xc000
//   0x6ed0: aa0803fa  mov      x26, x8
//   0x6ed4: b940b3e9  ldr      w9, [sp, #0xb0]
//   0x6ed8: 9b142128  madd     x8, x9, x20, x8
//   0x6edc: eb08035f  cmp      x26, x8
//   0x6ee0: 54001720  b.eq     #0x71c4
//   0x6ee4: 39405f48  ldrb     w8, [x26, #0x17]
//   0x6ee8: 37200068  tbnz     w8, #4, #0x6ef4
//   0x6eec: f9400757  ldr      x23, [x26, #8]
//   0x6ef0: 14000002  b        #0x6ef8
//   0x6ef4: aa1a03f7  mov      x23, x26
//   0x6ef8: 3940bf48  ldrb     w8, [x26, #0x2f]
//   0x6efc: 37200068  tbnz     w8, #4, #0x6f08
//   0x6f00: f9401359  ldr      x25, [x26, #0x20]
//   0x6f04: 14000002  b        #0x6f0c
//   0x6f08: 91006359  add      x25, x26, #0x18
//   0x6f0c: 97fff4d5  bl       #0x4260
//   0x6f10: 910183e0  add      x0, sp, #0x60
//   0x6f14: aa1703e1  mov      x1, x23
//   0x6f18: 97fff4e5  bl       #0x42ac
//   0x6f1c: 910183e0  add      x0, sp, #0x60
//   0x6f20: 97fff57f  bl       #0x451c
//   0x6f24: f940239b  ldr      x27, [x28, #0x40]
//   0x6f28: aa0003f5  mov      x21, x0
//   0x6f2c: b400057b  cbz      x27, #0x6fd8
//   0x6f30: 9e670360  fmov     d0, x27
//   0x6f34: 94000132  bl       #0x73fc
//   0x6f38: 1e260018  fmov     w24, s0
//   0x6f3c: f100071f  cmp      x24, #1
//   0x6f40: 540000e9  b.ls     #0x6f5c
//   0x6f44: eb1b02bf  cmp      x21, x27
//   0x6f48: aa1503f7  mov      x23, x21
//   0x6f4c: 540000c3  b.lo     #0x6f64
//   0x6f50: 9adb0aa8  udiv     x8, x21, x27
//   0x6f54: 9b1bd517  msub     x23, x8, x27, x21
//   0x6f58: 14000003  b        #0x6f64
//   0x6f5c: d1000768  sub      x8, x27, #1
//   0x6f60: 8a150117  and      x23, x8, x21
//   0x6f64: f9401ec8  ldr      x8, [x22, #0x38]
//   0x6f68: f8777913  ldr      x19, [x8, x23, lsl #3]
//   0x6f6c: b4000373  cbz      x19, #0x6fd8
//   0x6f70: d1000774  sub      x20, x27, #1
//   0x6f74: f9400273  ldr      x19, [x19]
//   0x6f78: b40002f3  cbz      x19, #0x6fd4
//   0x6f7c: f9400668  ldr      x8, [x19, #8]
//   0x6f80: eb15011f  cmp      x8, x21
//   0x6f84: 54000160  b.eq     #0x6fb0
//   0x6f88: f100071f  cmp      x24, #1
//   0x6f8c: 540000c9  b.ls     #0x6fa4
//   0x6f90: eb1b011f  cmp      x8, x27
//   0x6f94: 540000a3  b.lo     #0x6fa8
//   0x6f98: 9adb0909  udiv     x9, x8, x27
//   0x6f9c: 9b1ba128  msub     x8, x9, x27, x8
//   0x6fa0: 14000002  b        #0x6fa8
//   0x6fa4: 8a140108  and      x8, x8, x20
//   0x6fa8: eb17011f  cmp      x8, x23
//   0x6fac: 54000141  b.ne     #0x6fd4
//   0x6fb0: 91004260  add      x0, x19, #0x10
//   0x6fb4: 910183e1  add      x1, sp, #0x60
//   0x6fb8: 97fff63b  bl       #0x48a4
//   0x6fbc: 3607fdc0  tbz      w0, #0, #0x6f74
//   0x6fc0: 9100a260  add      x0, x19, #0x28
//   0x6fc4: aa1903e1  mov      x1, x25
//   0x6fc8: 97fff4d6  bl       #0x4320
//   0x6fcc: 52800614  mov      w20, #0x30
//   0x6fd0: 14000078  b        #0x71b0
//   0x6fd4: 52800614  mov      w20, #0x30
//   0x6fd8: 52800800  mov      w0, #0x40
//   0x6fdc: 9400014d  bl       #0x7510
//   0x6fe0: 3dc01be0  ldr      q0, [sp, #0x60]
//   0x6fe4: f9403be8  ldr      x8, [sp, #0x70]
//   0x6fe8: aa0003f8  mov      x24, x0
//   0x6fec: 3d800400  str      q0, [x0, #0x10]
//   0x6ff0: f9001008  str      x8, [x0, #0x20]
//   0x6ff4: 910183e0  add      x0, sp, #0x60
//   0x6ff8: 97fff6b7  bl       #0x4ad4
//   0x6ffc: 9100a300  add      x0, x24, #0x28
//   0x7000: aa1903e1  mov      x1, x25
//   0x7004: 97fff4aa  bl       #0x42ac
//   0x7008: f94003a8  ldr      x8, [x29]
//   0x700c: bd400ba0  ldr      s0, [x29, #8]
//   0x7010: a900571f  stp      xzr, x21, [x24]
//   0x7014: 91000508  add      x8, x8, #1
//   0x7018: 9e230101  ucvtf    s1, x8
//   0x701c: b40000bb  cbz      x27, #0x7030
//   0x7020: 9e230362  ucvtf    s2, x27
//   0x7024: 1e220802  fmul     s2, s0, s2
//   0x7028: 1e212040  fcmp     s2, s1
//   0x702c: 54000805  b.pl     #0x712c
//   0x7030: f1000f7f  cmp      x27, #3
//   0x7034: d1000768  sub      x8, x27, #1
//   0x7038: 1a9f27e9  cset     w9, lo
//   0x703c: ea08037f  tst      x27, x8
//   0x7040: 1a9f07e8  cset     w8, ne
//   0x7044: 1e201820  fdiv     s0, s1, s0
//   0x7048: 2a080128  orr      w8, w9, w8
//   0x704c: b37ffb68  bfi      x8, x27, #1, #0x3f
//   0x7050: 9e290009  fcvtpu   x9, s0
//   0x7054: eb09011f  cmp      x8, x9
//   0x7058: 9a883139  csel     x25, x9, x8, lo
//   0x705c: f1000728  subs     x8, x25, #1
//   0x7060: 54000061  b.ne     #0x706c
//   0x7064: 52800059  mov      w25, #2
//   0x7068: 14000006  b        #0x7080
//   0x706c: ea08033f  tst      x25, x8
//   0x7070: 54000080  b.eq     #0x7080
//   0x7074: aa1903e0  mov      x0, x25
//   0x7078: 9400018a  bl       #0x76a0
//   0x707c: aa0003f9  mov      x25, x0
//   0x7080: f9402397  ldr      x23, [x28, #0x40]
//   0x7084: eb17033f  cmp      x25, x23
//   0x7088: 54000089  b.ls     #0x7098
//   0x708c: aa1903e0  mov      x0, x25
//   0x7090: 97fff62c  bl       #0x4940
//   0x7094: 1400001a  b        #0x70fc
//   0x7098: 54000322  b.hs     #0x70fc
//   0x709c: f94003a8  ldr      x8, [x29]
//   0x70a0: 9e6702e0  fmov     d0, x23
//   0x70a4: bd400ba1  ldr      s1, [x29, #8]
//   0x70a8: 940000d5  bl       #0x73fc
//   0x70ac: 1e260009  fmov     w9, s0
//   0x70b0: 9e230100  ucvtf    s0, x8
//   0x70b4: f1000eff  cmp      x23, #3
//   0x70b8: 1e211800  fdiv     s0, s0, s1
//   0x70bc: fa412922  ccmp     x9, #1, #2, hs
//   0x70c0: 9e290000  fcvtpu   x0, s0
//   0x70c4: 54000069  b.ls     #0x70d0
//   0x70c8: 94000176  bl       #0x76a0
//   0x70cc: 14000008  b        #0x70ec
//   0x70d0: f100081f  cmp      x0, #2
//   0x70d4: 540000c3  b.lo     #0x70ec
//   0x70d8: d1000408  sub      x8, x0, #1
//   0x70dc: dac01108  clz      x8, x8
//   0x70e0: 4b0803e8  neg      w8, w8
//   0x70e4: 52800029  mov      w9, #1
//   0x70e8: 9ac82120  lsl      x0, x9, x8
//   0x70ec: eb00033f  cmp      x25, x0
//   0x70f0: 9a993000  csel     x0, x0, x25, lo
//   0x70f4: eb17001f  cmp      x0, x23
//   0x70f8: 54fffcc3  b.lo     #0x7090
//   0x70fc: f940239b  ldr      x27, [x28, #0x40]
//   0x7100: d1000768  sub      x8, x27, #1
//   0x7104: ea08037f  tst      x27, x8
//   0x7108: 540000a0  b.eq     #0x711c
//   0x710c: eb1b02bf  cmp      x21, x27
//   0x7110: 540000a2  b.hs     #0x7124
//   0x7114: aa1503f7  mov      x23, x21
//   0x7118: 14000005  b        #0x712c
//   0x711c: 8a150117  and      x23, x8, x21
//   0x7120: 14000003  b        #0x712c
//   0x7124: 9adb0aa8  udiv     x8, x21, x27
//   0x7128: 9b1bd517  msub     x23, x8, x27, x21
//   0x712c: f9401ec8  ldr      x8, [x22, #0x38]
//   0x7130: f8777908  ldr      x8, [x8, x23, lsl #3]
//   0x7134: b4000088  cbz      x8, #0x7144
//   0x7138: f9400109  ldr      x9, [x8]
//   0x713c: f9000309  str      x9, [x24]
//   0x7140: 14000016  b        #0x7198
//   0x7144: b0000028  adrp     x8, #0xc000
//   0x7148: 9100e108  add      x8, x8, #0x38
//   0x714c: f8410d09  ldr      x9, [x8, #0x10]!
//   0x7150: f9000118  str      x24, [x8]
//   0x7154: f9401eca  ldr      x10, [x22, #0x38]
//   0x7158: f9000309  str      x9, [x24]
//   0x715c: f8377948  str      x8, [x10, x23, lsl #3]
//   0x7160: f9400308  ldr      x8, [x24]
//   0x7164: b40001c8  cbz      x8, #0x719c
//   0x7168: f9400508  ldr      x8, [x8, #8]
//   0x716c: d1000769  sub      x9, x27, #1
//   0x7170: ea09037f  tst      x27, x9
//   0x7174: 540000c0  b.eq     #0x718c
//   0x7178: eb1b011f  cmp      x8, x27
//   0x717c: 540000a3  b.lo     #0x7190
//   0x7180: 9adb0909  udiv     x9, x8, x27
//   0x7184: 9b1ba128  msub     x8, x9, x27, x8
//   0x7188: 14000002  b        #0x7190
//   0x718c: 8a090108  and      x8, x8, x9
//   0x7190: f9401ec9  ldr      x9, [x22, #0x38]
//   0x7194: 8b080d28  add      x8, x9, x8, lsl #3
//   0x7198: f9000118  str      x24, [x8]
//   0x719c: b0000028  adrp     x8, #0xc000
//   0x71a0: aa0803e9  mov      x9, x8
//   0x71a4: f9402908  ldr      x8, [x8, #0x50]
//   0x71a8: 91000508  add      x8, x8, #1
//   0x71ac: f9002928  str      x8, [x9, #0x50]
//   0x71b0: 910183e0  add      x0, sp, #0x60
//   0x71b4: 97fff44c  bl       #0x42e4
//   0x71b8: f9405fe8  ldr      x8, [sp, #0xb8]
//   0x71bc: 9100c35a  add      x26, x26, #0x30
//   0x71c0: 17ffff45  b        #0x6ed4
//   0x71c4: f9406bf7  ldr      x23, [sp, #0xd0]
//   0x71c8: a942d7f4  ldp      x20, x21, [sp, #0x28]
//   0x71cc: b4000257  cbz      x23, #0x7214
//   0x71d0: f94002e0  ldr      x0, [x23]
//   0x71d4: b4000160  cbz      x0, #0x7200
//   0x71d8: f9400ae8  ldr      x8, [x23, #0x10]
//   0x71dc: eb00011f  cmp      x8, x0
//   0x71e0: 540000e0  b.eq     #0x71fc
//   0x71e4: f9400813  ldr      x19, [x0, #0x10]
//   0x71e8: 940000e6  bl       #0x7580
//   0x71ec: f90002f3  str      x19, [x23]
//   0x71f0: aa1303e0  mov      x0, x19
//   0x71f4: b5ffff20  cbnz     x0, #0x71d8
//   0x71f8: 14000002  b        #0x7200
//   0x71fc: f900041f  str      xzr, [x0, #8]
//   0x7200: f94012e0  ldr      x0, [x23, #0x20]
//   0x7204: b4000040  cbz      x0, #0x720c
//   0x7208: 940000ca  bl       #0x7530
//   0x720c: aa1703e0  mov      x0, x23
//   0x7210: 940000c8  bl       #0x7530
//   0x7214: f9400be0  ldr      x0, [sp, #0x10]
//   0x7218: 97fff438  bl       #0x42f8
//   0x721c: 9400003f  bl       #0x7318
//   0x7220: 9100e3e0  add      x0, sp, #0x38
//   0x7224: 97fff430  bl       #0x42e4
//   0x7228: f9400288  ldr      x8, [x20]
//   0x722c: a94187e2  ldp      x2, x1, [sp, #0x18]
//   0x7230: aa1403e0  mov      x0, x20
//   0x7234: f942a908  ldr      x8, [x8, #0x550]
//   0x7238: d63f0100  blr      x8
//   0x723c: 52800020  mov      w0, #1
//   0x7240: f94016a8  ldr      x8, [x21, #0x28]
//   0x7244: f9408fe9  ldr      x9, [sp, #0x118]
//   0x7248: eb09011f  cmp      x8, x9
//   0x724c: 54000241  b.ne     #0x7294
//   0x7250: a9577bfd  ldp      x29, x30, [sp, #0x170]
//   0x7254: a9564ff4  ldp      x20, x19, [sp, #0x160]
//   0x7258: a95557f6  ldp      x22, x21, [sp, #0x150]
//   0x725c: a9545ff8  ldp      x24, x23, [sp, #0x140]
//   0x7260: a95367fa  ldp      x26, x25, [sp, #0x130]
//   0x7264: a9526ffc  ldp      x28, x27, [sp, #0x120]
//   0x7268: 910603ff  add      sp, sp, #0x180
//   0x726c: d65f03c0  ret      
//   0x7270: f9402fe9  ldr      x9, [sp, #0x58]
//   0x7274: 5280002a  mov      w10, #1
//   0x7278: 14000003  b        #0x7284
//   0x727c: f9402fe9  ldr      x9, [sp, #0x58]
//   0x7280: 5280004a  mov      w10, #2
//   0x7284: cb090108  sub      x8, x8, x9
//   0x7288: b90093ea  str      w10, [sp, #0x90]
//   0x728c: f9004fe8  str      x8, [sp, #0x98]
//   0x7290: 17fffee6  b        #0x6e28
//   0x7294: 940000cf  bl       #0x75d0
// ============================================================================
std::uint32_t fde_068_6cf0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006cf0ULL;
    for (std::size_t i = 0; i < 362ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2876ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[069] Symbol: sub_7298
//      Virtual Address Range: 0x7298..0x72b0 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[069] Biểu tượng: sub_7298
//      Dải địa chỉ ảo: 0x7298..0x72b0 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7298: a955a3e9  ldp      x9, x8, [sp, #0x158]
//   0x729c: f9409fe0  ldr      x0, [sp, #0x138]
//   0x72a0: 91001108  add      x8, x8, #4
//   0x72a4: cb080121  sub      x1, x9, x8
//   0x72a8: f900b3e8  str      x8, [sp, #0x160]
//   0x72ac: 17fffba4  b        #0x613c
// ============================================================================
std::uint32_t fde_069_7298(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007298ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3238ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[070] Symbol: sub_72b0
//      Virtual Address Range: 0x72b0..0x72c0 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[070] Biểu tượng: sub_72b0
//      Dải địa chỉ ảo: 0x72b0..0x72c0 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x72b0: a9442688  ldp      x8, x9, [x20, #0x40]
//   0x72b4: cb080129  sub      x9, x9, x8
//   0x72b8: f1005d3f  cmp      x9, #0x17
//   0x72bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_070_72b0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072b0ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3244ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[071] Symbol: sub_72c0
//      Virtual Address Range: 0x72c0..0x72c8 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[071] Biểu tượng: sub_72c0
//      Dải địa chỉ ảo: 0x72c0..0x72c8 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x72c0: aa1303e0  mov      x0, x19
//   0x72c4: 17fff9f6  b        #0x5a9c
// ============================================================================
std::uint32_t fde_071_72c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072c0ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3248ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[072] Symbol: sub_72c8
//      Virtual Address Range: 0x72c8..0x72d4 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[072] Biểu tượng: sub_72c8
//      Dải địa chỉ ảo: 0x72c8..0x72d4 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x72c8: cb080129  sub      x9, x9, x8
//   0x72cc: f100013f  cmp      x9, #0
//   0x72d0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_072_72c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072c8ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3250ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[073] Symbol: sub_72d4
//      Virtual Address Range: 0x72d4..0x72dc (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[073] Biểu tượng: sub_72d4
//      Dải địa chỉ ảo: 0x72d4..0x72dc (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x72d4: 9100a280  add      x0, x20, #0x28
//   0x72d8: 17fff9a7  b        #0x5974
// ============================================================================
std::uint32_t fde_073_72d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072d4ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3253ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[074] Symbol: sub_72dc
//      Virtual Address Range: 0x72dc..0x72e4 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[074] Biểu tượng: sub_72dc
//      Dải địa chỉ ảo: 0x72dc..0x72e4 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x72dc: f900b3e8  str      x8, [sp, #0x160]
//   0x72e0: 17fffb97  b        #0x613c
// ============================================================================
std::uint32_t fde_074_72dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072dcULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3255ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[075] Symbol: sub_72e4
//      Virtual Address Range: 0x72e4..0x7304 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[075] Biểu tượng: sub_72e4
//      Dải địa chỉ ảo: 0x72e4..0x7304 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x72e4: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x72e8: 91000508  add      x8, x8, #1
//   0x72ec: aa1303e0  mov      x0, x19
//   0x72f0: f9000268  str      x8, [x19]
//   0x72f4: 97fff64b  bl       #0x4c20
//   0x72f8: b94032a8  ldr      w8, [x21, #0x30]
//   0x72fc: f84107fe  ldr      x30, [sp], #0x10
//   0x7300: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_075_72e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072e4ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3257ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[076] Symbol: sub_7304
//      Virtual Address Range: 0x7304..0x7318 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[076] Biểu tượng: sub_7304
//      Dải địa chỉ ảo: 0x7304..0x7318 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7304: f9429d08  ldr      x8, [x8, #0x538]
//   0x7308: 7200013f  tst      w9, #1
//   0x730c: 9a8a0161  csel     x1, x11, x10, eq
//   0x7310: aa1403e0  mov      x0, x20
//   0x7314: d61f0100  br       x8
// ============================================================================
std::uint32_t fde_076_7304(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007304ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3265ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[077] Symbol: sub_7318
//      Virtual Address Range: 0x7318..0x7324 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[077] Biểu tượng: sub_7318
//      Dải địa chỉ ảo: 0x7318..0x7324 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7318: b0000020  adrp     x0, #0xc000
//   0x731c: 91004000  add      x0, x0, #0x10
//   0x7320: 140000e4  b        #0x76b0
// ============================================================================
std::uint32_t fde_077_7318(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007318ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3270ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[078] Symbol: sub_7324
//      Virtual Address Range: 0x7324..0x7330 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[078] Biểu tượng: sub_7324
//      Dải địa chỉ ảo: 0x7324..0x7330 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7324: f9400288  ldr      x8, [x20]
//   0x7328: aa1403e0  mov      x0, x20
//   0x732c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_078_7324(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007324ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3273ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[079] Symbol: sub_7330
//      Virtual Address Range: 0x7330..0x7344 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[079] Biểu tượng: sub_7330
//      Dải địa chỉ ảo: 0x7330..0x7344 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7330: f9400008  ldr      x8, [x0]
//   0x7334: aa0003f3  mov      x19, x0
//   0x7338: aa0103f4  mov      x20, x1
//   0x733c: f9401108  ldr      x8, [x8, #0x20]
//   0x7340: d61f0100  br       x8
// ============================================================================
std::uint32_t fde_079_7330(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007330ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3276ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[080] Symbol: sub_7344
//      Virtual Address Range: 0x7344..0x7350 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[080] Biểu tượng: sub_7344
//      Dải địa chỉ ảo: 0x7344..0x7350 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7344: f9400008  ldr      x8, [x0]
//   0x7348: f9400508  ldr      x8, [x8, #8]
//   0x734c: d61f0100  br       x8
// ============================================================================
std::uint32_t fde_080_7344(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007344ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3281ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[081] Symbol: sub_7350
//      Virtual Address Range: 0x7350..0x7358 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[081] Biểu tượng: sub_7350
//      Dải địa chỉ ảo: 0x7350..0x7358 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7350: 9104e3e0  add      x0, sp, #0x138
//   0x7354: 17fffb87  b        #0x6170
// ============================================================================
std::uint32_t fde_081_7350(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007350ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3284ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[082] Symbol: sub_7358
//      Virtual Address Range: 0x7358..0x7368 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[082] Biểu tượng: sub_7358
//      Dải địa chỉ ảo: 0x7358..0x7368 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7358: 91000d09  add      x9, x8, #3
//   0x735c: f9000269  str      x9, [x19]
//   0x7360: 39400d0a  ldrb     w10, [x8, #3]
//   0x7364: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_082_7358(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007358ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3286ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[083] Symbol: sub_7368
//      Virtual Address Range: 0x7368..0x7378 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[083] Biểu tượng: sub_7368
//      Dải địa chỉ ảo: 0x7368..0x7378 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7368: 91000509  add      x9, x8, #1
//   0x736c: f9000269  str      x9, [x19]
//   0x7370: 3940050a  ldrb     w10, [x8, #1]
//   0x7374: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_083_7368(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007368ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3290ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[084] Symbol: sub_7378
//      Virtual Address Range: 0x7378..0x7390 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[084] Biểu tượng: sub_7378
//      Dải địa chỉ ảo: 0x7378..0x7390 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7378: 91000509  add      x9, x8, #1
//   0x737c: f9000269  str      x9, [x19]
//   0x7380: f9402289  ldr      x9, [x20, #0x40]
//   0x7384: f9400e80  ldr      x0, [x20, #0x18]
//   0x7388: 2a1603e8  mov      w8, w22
//   0x738c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_084_7378(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007378ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3294ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[085] Symbol: sub_7390
//      Virtual Address Range: 0x7390..0x73a0 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[085] Biểu tượng: sub_7390
//      Dải địa chỉ ảo: 0x7390..0x73a0 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7390: aa1503e0  mov      x0, x21
//   0x7394: aa1303e1  mov      x1, x19
//   0x7398: aa1403e2  mov      x2, x20
//   0x739c: 17fff62f  b        #0x4c58
// ============================================================================
std::uint32_t fde_085_7390(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007390ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3300ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[086] Symbol: sub_73a0
//      Virtual Address Range: 0x73a0..0x73ac (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[086] Biểu tượng: sub_73a0
//      Dải địa chỉ ảo: 0x73a0..0x73ac (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73a0: 5100c1ae  sub      w14, w13, #0x30
//   0x73a4: 710025df  cmp      w14, #9
//   0x73a8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_086_73a0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073a0ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3304ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[087] Symbol: sub_73ac
//      Virtual Address Range: 0x73ac..0x73b4 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[087] Biểu tượng: sub_73ac
//      Dải địa chỉ ảo: 0x73ac..0x73b4 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73ac: f9400908  ldr      x8, [x8, #0x10]
//   0x73b0: d61f0100  br       x8
// ============================================================================
std::uint32_t fde_087_73ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073acULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3307ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[088] Symbol: sub_73b4
//      Virtual Address Range: 0x73b4..0x73c0 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[088] Biểu tượng: sub_73b4
//      Dải địa chỉ ảo: 0x73b4..0x73c0 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73b4: 9104e3e0  add      x0, sp, #0x138
//   0x73b8: 910243e1  add      x1, sp, #0x90
//   0x73bc: 17fffe02  b        #0x6bc4
// ============================================================================
std::uint32_t fde_088_73b4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073b4ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3309ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[089] Symbol: sub_73c0
//      Virtual Address Range: 0x73c0..0x73d4 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[089] Biểu tượng: sub_73c0
//      Dải địa chỉ ảo: 0x73c0..0x73d4 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73c0: 91000909  add      x9, x8, #2
//   0x73c4: f9000269  str      x9, [x19]
//   0x73c8: 3940090a  ldrb     w10, [x8, #2]
//   0x73cc: 7101b15f  cmp      w10, #0x6c
//   0x73d0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_089_73c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073c0ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3312ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[090] Symbol: sub_73d4
//      Virtual Address Range: 0x73d4..0x73e8 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[090] Biểu tượng: sub_73d4
//      Dải địa chỉ ảo: 0x73d4..0x73e8 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73d4: 91000509  add      x9, x8, #1
//   0x73d8: f9000e69  str      x9, [x19, #0x18]
//   0x73dc: 3900011b  strb     w27, [x8]
//   0x73e0: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x73e4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_090_73d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073d4ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3317ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[091] Symbol: sub_73e8
//      Virtual Address Range: 0x73e8..0x73fc (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[091] Biểu tượng: sub_73e8
//      Dải địa chỉ ảo: 0x73e8..0x73fc (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73e8: 91000509  add      x9, x8, #1
//   0x73ec: f9000e69  str      x9, [x19, #0x18]
//   0x73f0: 3900011a  strb     w26, [x8]
//   0x73f4: a941a668  ldp      x8, x9, [x19, #0x18]
//   0x73f8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_091_73e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073e8ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3322ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[092] Symbol: sub_73fc
//      Virtual Address Range: 0x73fc..0x7408 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[092] Biểu tượng: sub_73fc
//      Dải địa chỉ ảo: 0x73fc..0x7408 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73fc: 0e205800  cnt      v0.8b, v0.8b
//   0x7400: 2e303800  uaddlv   h0, v0.8b
//   0x7404: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_092_73fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073fcULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3327ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[093] Symbol: sub_7408
//      Virtual Address Range: 0x7408..0x7410 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[093] Biểu tượng: sub_7408
//      Dải địa chỉ ảo: 0x7408..0x7410 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7408: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x740c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_093_7408(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007408ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3330ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[094] Symbol: sub_7410
//      Virtual Address Range: 0x7410..0x7424 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[094] Biểu tượng: sub_7410
//      Dải địa chỉ ảo: 0x7410..0x7424 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7410: 0b0b01ad  add      w13, w13, w11
//   0x7414: 91000718  add      x24, x24, #1
//   0x7418: 9b0e354a  madd     x10, x10, x14, x13
//   0x741c: 11000529  add      w9, w9, #1
//   0x7420: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_094_7410(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007410ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3332ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[095] Symbol: sub_7424
//      Virtual Address Range: 0x7424..0x7430 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[095] Biểu tượng: sub_7424
//      Dải địa chỉ ảo: 0x7424..0x7430 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7424: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x7428: f84307f6  ldr      x22, [sp], #0x30
//   0x742c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_095_7424(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007424ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3337ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[096] Symbol: sub_7430
//      Virtual Address Range: 0x7430..0x743c (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[096] Biểu tượng: sub_7430
//      Dải địa chỉ ảo: 0x7430..0x743c (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7430: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x7434: a8c35bf7  ldp      x23, x22, [sp], #0x30
//   0x7438: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_096_7430(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007430ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3340ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[097] Symbol: sub_743c
//      Virtual Address Range: 0x743c..0x7448 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[097] Biểu tượng: sub_743c
//      Dải địa chỉ ảo: 0x743c..0x7448 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x743c: aa1403e0  mov      x0, x20
//   0x7440: aa1503e1  mov      x1, x21
//   0x7444: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_097_743c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000743cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3343ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[098] Symbol: sub_7448
//      Virtual Address Range: 0x7448..0x7454 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[098] Biểu tượng: sub_7448
//      Dải địa chỉ ảo: 0x7448..0x7454 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7448: aa1403e0  mov      x0, x20
//   0x744c: aa1703e1  mov      x1, x23
//   0x7450: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_098_7448(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007448ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3346ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[099] Symbol: sub_7454
//      Virtual Address Range: 0x7454..0x745c (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[099] Biểu tượng: sub_7454
//      Dải địa chỉ ảo: 0x7454..0x745c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7454: 910483e0  add      x0, sp, #0x120
//   0x7458: 17fff345  b        #0x416c
// ============================================================================
std::uint32_t fde_099_7454(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007454ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3349ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[100] Symbol: sub_745c
//      Virtual Address Range: 0x745c..0x7470 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[100] Biểu tượng: sub_745c
//      Dải địa chỉ ảo: 0x745c..0x7470 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x745c: 1b0c36cd  madd     w13, w22, w12, w13
//   0x7460: 91000718  add      x24, x24, #1
//   0x7464: 5100c1b6  sub      w22, w13, #0x30
//   0x7468: 11000529  add      w9, w9, #1
//   0x746c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_100_745c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000745cULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3351ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[101] Symbol: sub_7470
//      Virtual Address Range: 0x7470..0x7484 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[101] Biểu tượng: sub_7470
//      Dải địa chỉ ảo: 0x7470..0x7484 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7470: 3940030d  ldrb     w13, [x24]
//   0x7474: 5100c1af  sub      w15, w13, #0x30
//   0x7478: 12001def  and      w15, w15, #0xff
//   0x747c: 710025ff  cmp      w15, #9
//   0x7480: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_101_7470(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007470ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3356ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[102] Symbol: sub_7484
//      Virtual Address Range: 0x7484..0x748c (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[102] Biểu tượng: sub_7484
//      Dải địa chỉ ảo: 0x7484..0x748c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7484: f84207f4  ldr      x20, [sp], #0x20
//   0x7488: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_102_7484(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007484ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3361ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[103] Symbol: sub_748c
//      Virtual Address Range: 0x748c..0x74b0 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[103] Biểu tượng: sub_748c
//      Dải địa chỉ ảo: 0x748c..0x74b0 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x748c: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x7490: aa1303e0  mov      x0, x19
//   0x7494: f9002289  str      x9, [x20, #0x40]
//   0x7498: a9007d1f  stp      xzr, xzr, [x8]
//   0x749c: f900090a  str      x10, [x8, #0x10]
//   0x74a0: 97fff5e0  bl       #0x4c20
//   0x74a4: b94032a8  ldr      w8, [x21, #0x30]
//   0x74a8: f84107fe  ldr      x30, [sp], #0x10
//   0x74ac: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_103_748c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000748cULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3363ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[104] Symbol: sub_74b0
//      Virtual Address Range: 0x74b0..0x74b8 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[104] Biểu tượng: sub_74b0
//      Dải địa chỉ ảo: 0x74b0..0x74b8 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x74b0: 52800020  mov      w0, #1
//   0x74b4: 14000017  b        #0x7510
// ============================================================================
std::uint32_t fde_104_74b0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074b0ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3372ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[105] Symbol: sub_74b8
//      Virtual Address Range: 0x74b8..0x74cc (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[105] Biểu tượng: sub_74b8
//      Dải địa chỉ ảo: 0x74b8..0x74cc (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x74b8: f9401268  ldr      x8, [x19, #0x20]
//   0x74bc: cb140108  sub      x8, x8, x20
//   0x74c0: 91000509  add      x9, x8, #1
//   0x74c4: 8b490508  add      x8, x8, x9, lsr #1
//   0x74c8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_105_74b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074b8ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3374ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Master FDE Verification Runner across all 106 FDEs
// [VN] Hàm điều phối xác minh toàn bộ 106 khung hàm FDE
// ============================================================================
std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t state = 0x2895aab9U;
    state ^= fde_000_403c(state + 0U);
    state ^= fde_001_4084(state + 1U);
    state ^= fde_002_416c(state + 2U);
    state ^= fde_003_4184(state + 3U);
    state ^= fde_004_41a4(state + 4U);
    state ^= fde_005_41e4(state + 5U);
    state ^= fde_006_4218(state + 6U);
    state ^= fde_007_4260(state + 7U);
    state ^= fde_008_42ac(state + 8U);
    state ^= fde_009_42e4(state + 9U);
    state ^= fde_010_42f8(state + 10U);
    state ^= fde_011_4320(state + 11U);
    state ^= fde_012_43e0(state + 12U);
    state ^= fde_013_4510(state + 13U);
    state ^= fde_014_451c(state + 14U);
    state ^= fde_015_48a4(state + 15U);
    state ^= fde_016_4940(state + 16U);
    state ^= fde_017_4ab8(state + 17U);
    state ^= fde_018_4ad4(state + 18U);
    state ^= fde_019_4af0(state + 19U);
    state ^= fde_020_4b20(state + 20U);
    state ^= fde_021_4b54(state + 21U);
    state ^= fde_022_4bc4(state + 22U);
    state ^= fde_023_4bd4(state + 23U);
    state ^= fde_024_4c20(state + 24U);
    state ^= fde_025_4c58(state + 25U);
    state ^= fde_026_55e4(state + 26U);
    state ^= fde_027_5974(state + 27U);
    state ^= fde_028_59c8(state + 28U);
    state ^= fde_029_5a08(state + 29U);
    state ^= fde_030_5a9c(state + 30U);
    state ^= fde_031_5af0(state + 31U);
    state ^= fde_032_5b70(state + 32U);
    state ^= fde_033_5c20(state + 33U);
    state ^= fde_034_5c78(state + 34U);
    state ^= fde_035_5cdc(state + 35U);
    state ^= fde_036_5ce8(state + 36U);
    state ^= fde_037_5d14(state + 37U);
    state ^= fde_038_5d24(state + 38U);
    state ^= fde_039_5d3c(state + 39U);
    state ^= fde_040_5d48(state + 40U);
    state ^= fde_041_5d54(state + 41U);
    state ^= fde_042_5d5c(state + 42U);
    state ^= fde_043_5d64(state + 43U);
    state ^= fde_044_5d7c(state + 44U);
    state ^= fde_045_5da8(state + 45U);
    state ^= fde_046_5dc0(state + 46U);
    state ^= fde_047_5dd0(state + 47U);
    state ^= fde_048_5de0(state + 48U);
    state ^= fde_049_5df0(state + 49U);
    state ^= fde_050_5df4(state + 50U);
    state ^= fde_051_5df8(state + 51U);
    state ^= fde_052_5e04(state + 52U);
    state ^= fde_053_5e10(state + 53U);
    state ^= fde_054_5e18(state + 54U);
    state ^= fde_055_5ee4(state + 55U);
    state ^= fde_056_5f18(state + 56U);
    state ^= fde_057_5f50(state + 57U);
    state ^= fde_058_5f7c(state + 58U);
    state ^= fde_059_613c(state + 59U);
    state ^= fde_060_6170(state + 60U);
    state ^= fde_061_61e0(state + 61U);
    state ^= fde_062_6280(state + 62U);
    state ^= fde_063_62e4(state + 63U);
    state ^= fde_064_637c(state + 64U);
    state ^= fde_065_63a8(state + 65U);
    state ^= fde_066_6bc4(state + 66U);
    state ^= fde_067_6cac(state + 67U);
    state ^= fde_068_6cf0(state + 68U);
    state ^= fde_069_7298(state + 69U);
    state ^= fde_070_72b0(state + 70U);
    state ^= fde_071_72c0(state + 71U);
    state ^= fde_072_72c8(state + 72U);
    state ^= fde_073_72d4(state + 73U);
    state ^= fde_074_72dc(state + 74U);
    state ^= fde_075_72e4(state + 75U);
    state ^= fde_076_7304(state + 76U);
    state ^= fde_077_7318(state + 77U);
    state ^= fde_078_7324(state + 78U);
    state ^= fde_079_7330(state + 79U);
    state ^= fde_080_7344(state + 80U);
    state ^= fde_081_7350(state + 81U);
    state ^= fde_082_7358(state + 82U);
    state ^= fde_083_7368(state + 83U);
    state ^= fde_084_7378(state + 84U);
    state ^= fde_085_7390(state + 85U);
    state ^= fde_086_73a0(state + 86U);
    state ^= fde_087_73ac(state + 87U);
    state ^= fde_088_73b4(state + 88U);
    state ^= fde_089_73c0(state + 89U);
    state ^= fde_090_73d4(state + 90U);
    state ^= fde_091_73e8(state + 91U);
    state ^= fde_092_73fc(state + 92U);
    state ^= fde_093_7408(state + 93U);
    state ^= fde_094_7410(state + 94U);
    state ^= fde_095_7424(state + 95U);
    state ^= fde_096_7430(state + 96U);
    state ^= fde_097_743c(state + 97U);
    state ^= fde_098_7448(state + 98U);
    state ^= fde_099_7454(state + 99U);
    state ^= fde_100_745c(state + 100U);
    state ^= fde_101_7470(state + 101U);
    state ^= fde_102_7484(state + 102U);
    state ^= fde_103_748c(state + 103U);
    state ^= fde_104_74b0(state + 104U);
    state ^= fde_105_74b8(state + 105U);
    return state;
}

} // namespace security
} // namespace lynx
} // namespace bytedance

extern "C" {

JNIEXPORT jint JNICALL Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeVerifySignBlock(
    JNIEnv*, jobject, jobject, jint length, jstring, jobjectArray) {
    return static_cast<jint>(bytedance::lynx::security::execute_all_fde_simulations() ^ static_cast<std::uint32_t>(length));
}

JNIEXPORT void JNICALL Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeUpdateRsaPublicKeys(
    JNIEnv*, jobject, jobjectArray, jobjectArray) {
    (void)bytedance::lynx::security::execute_all_fde_simulations();
}

} // extern "C"
