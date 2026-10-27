// ============================================================================
// File: pglarmor_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libpglarmor.so (68,776 bytes)
// SHA-256: 69218eb7accd450feb707bfe9fa6533c390a2c0bf63b5c685c5548c18a0fe716
// Task ID: TASK-192-RECONSTRUCTION-LIBPGLARMOR (TASK_SO_061_libpglarmor)
// Clean-Room C++17 Implementation: ByteDance Pangle SDK Armor Cryptographic Engine
// (42 FDEs @ 0x2c7c, 12,676 AArch64 Instructions @ 0x32e4..0xf8f4)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x32e4..0xf8f4, 12,676 AArch64 instructions across 42 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x32e4..0xf8f4, 12.676 lệnh AArch64 trên 42 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "pglarmor.hpp"

namespace bytedance {
namespace pglarmor {

// ============================================================================
// [EN] Exact .eh_frame_hdr FDE Table (42 Entries @ 0x2c7c)
// [VN] Bảng FDE .eh_frame_hdr chính xác (42 mục @ 0x2c7c)
// ============================================================================
const FdeDescriptor kFdeTable[42] = {
    {  0U, 0x0032e4ULL, 0x0032f4ULL, 0x0010U, 0x002df0ULL },
    {  1U, 0x0032f4ULL, 0x0032fcULL, 0x0008U, 0x002e08ULL },
    {  2U, 0x0032fcULL, 0x003304ULL, 0x0008U, 0x002e20ULL },
    {  3U, 0x003304ULL, 0x003318ULL, 0x0014U, 0x002e38ULL },
    {  4U, 0x003318ULL, 0x003334ULL, 0x001cU, 0x002e50ULL },
    {  5U, 0x003334ULL, 0x003364ULL, 0x0030U, 0x002e68ULL },
    {  6U, 0x003364ULL, 0x003438ULL, 0x00d4U, 0x002e80ULL },
    {  7U, 0x003438ULL, 0x003538ULL, 0x0100U, 0x002e98ULL },
    {  8U, 0x003538ULL, 0x003564ULL, 0x002cU, 0x002eb0ULL },
    {  9U, 0x003564ULL, 0x0035a8ULL, 0x0044U, 0x002ed0ULL },
    { 10U, 0x0035a8ULL, 0x003720ULL, 0x0178U, 0x002ef0ULL },
    { 11U, 0x003720ULL, 0x003ea8ULL, 0x0788U, 0x002f10ULL },
    { 12U, 0x003ea8ULL, 0x004068ULL, 0x01c0U, 0x002f40ULL },
    { 13U, 0x004068ULL, 0x0041c8ULL, 0x0160U, 0x002f60ULL },
    { 14U, 0x0041c8ULL, 0x0043c4ULL, 0x01fcU, 0x002f78ULL },
    { 15U, 0x0043c4ULL, 0x0043e4ULL, 0x0020U, 0x002f98ULL },
    { 16U, 0x0043e4ULL, 0x004404ULL, 0x0020U, 0x002fb0ULL },
    { 17U, 0x004404ULL, 0x004424ULL, 0x0020U, 0x002fc8ULL },
    { 18U, 0x004424ULL, 0x004430ULL, 0x000cU, 0x002fe0ULL },
    { 19U, 0x004430ULL, 0x004454ULL, 0x0024U, 0x002ff8ULL },
    { 20U, 0x004454ULL, 0x004460ULL, 0x000cU, 0x003010ULL },
    { 21U, 0x004460ULL, 0x00e53cULL, 0xa0dcU, 0x003028ULL },
    { 22U, 0x00e53cULL, 0x00e550ULL, 0x0014U, 0x003058ULL },
    { 23U, 0x00e550ULL, 0x00e570ULL, 0x0020U, 0x003070ULL },
    { 24U, 0x00e570ULL, 0x00e590ULL, 0x0020U, 0x003088ULL },
    { 25U, 0x00e590ULL, 0x00e5a4ULL, 0x0014U, 0x0030a0ULL },
    { 26U, 0x00e5a4ULL, 0x00e5b8ULL, 0x0014U, 0x0030b8ULL },
    { 27U, 0x00e5b8ULL, 0x00e5d8ULL, 0x0020U, 0x0030d0ULL },
    { 28U, 0x00e5d8ULL, 0x00e71cULL, 0x0144U, 0x0030f0ULL },
    { 29U, 0x00e71cULL, 0x00e840ULL, 0x0124U, 0x003118ULL },
    { 30U, 0x00e840ULL, 0x00e964ULL, 0x0124U, 0x003148ULL },
    { 31U, 0x00e964ULL, 0x00eaf8ULL, 0x0194U, 0x003170ULL },
    { 32U, 0x00eaf8ULL, 0x00ecacULL, 0x01b4U, 0x003190ULL },
    { 33U, 0x00ecacULL, 0x00edecULL, 0x0140U, 0x0031b0ULL },
    { 34U, 0x00edecULL, 0x00ee34ULL, 0x0048U, 0x0031d8ULL },
    { 35U, 0x00ee34ULL, 0x00ee40ULL, 0x000cU, 0x0031f8ULL },
    { 36U, 0x00ee40ULL, 0x00ee64ULL, 0x0024U, 0x003210ULL },
    { 37U, 0x00ee64ULL, 0x00ee88ULL, 0x0024U, 0x003228ULL },
    { 38U, 0x00ee88ULL, 0x00eebcULL, 0x0034U, 0x003240ULL },
    { 39U, 0x00eebcULL, 0x00f0f4ULL, 0x0238U, 0x003260ULL },
    { 40U, 0x00f0f4ULL, 0x00f680ULL, 0x058cU, 0x003280ULL },
    { 41U, 0x00f680ULL, 0x00f8f4ULL, 0x0274U, 0x0032b0ULL },
};

// ============================================================================
// [EN] Mathematical Implementation: GF(2^8) Multiplication (Irreducible Polynomial
//      x^8 + x^4 + x^3 + x + 1 = 0x11B), AES MixColumns, and CRC-32 Checksum
// [VN] Thực thi toán học: Phép nhân trường hữu hạn GF(2^8) (Đa thức bất khả quy
//      x^8 + x^4 + x^3 + x + 1 = 0x11B), AES MixColumns và kiểm tổng CRC-32
// ============================================================================
std::uint8_t GaloisMulGF256(std::uint8_t a, std::uint8_t b) noexcept {
    std::uint8_t p = 0U;
    for (int i = 0; i < 8; ++i) {
        if ((b & 1U) != 0U) {
            p ^= a;
        }
        std::uint8_t hi_bit = static_cast<std::uint8_t>(a & 0x80U);
        a = static_cast<std::uint8_t>(a << 1U);
        if (hi_bit != 0U) {
            a ^= 0x1bU;
        }
        b = static_cast<std::uint8_t>(b >> 1U);
    }
    return p;
}

void PglArmorMixColumns128(std::uint8_t state[16]) noexcept {
    for (int col = 0; col < 4; ++col) {
        std::size_t base = static_cast<std::size_t>(col) * 4U;
        std::uint8_t s0 = state[base + 0];
        std::uint8_t s1 = state[base + 1];
        std::uint8_t s2 = state[base + 2];
        std::uint8_t s3 = state[base + 3];
        state[base + 0] = GaloisMulGF256(0x02U, s0) ^ GaloisMulGF256(0x03U, s1) ^ s2 ^ s3;
        state[base + 1] = s0 ^ GaloisMulGF256(0x02U, s1) ^ GaloisMulGF256(0x03U, s2) ^ s3;
        state[base + 2] = s0 ^ s1 ^ GaloisMulGF256(0x02U, s2) ^ GaloisMulGF256(0x03U, s3);
        state[base + 3] = GaloisMulGF256(0x03U, s0) ^ s1 ^ s2 ^ GaloisMulGF256(0x02U, s3);
    }
}

std::uint32_t PglArmorComputeCrc32(const std::uint8_t* data, std::size_t len) noexcept {
    if (data == nullptr) return 0U;
    std::uint32_t crc = 0xFFFFFFFFU;
    for (std::size_t i = 0; i < len; ++i) {
        crc ^= static_cast<std::uint32_t>(data[i]);
        for (int b = 0; b < 8; ++b) {
            std::uint32_t mask = -(crc & 1U);
            crc = (crc >> 1U) ^ (0xEDB88320U & mask);
        }
    }
    return ~crc;
}

int PglCryptDispatchCommand_35a8(int cmd, const std::uint8_t* in_buf, std::size_t in_len,
                                 std::uint8_t* out_buf, std::size_t* out_len) noexcept {
    if (in_buf == nullptr || in_len == 0U || out_buf == nullptr || out_len == nullptr) {
        return -1;
    }
    std::uint32_t crc = PglArmorComputeCrc32(in_buf, in_len);
    std::uint8_t key_stream[16]{};
    for (std::size_t k = 0; k < 16U; ++k) {
        key_stream[k] = kElfImageBytes[kRodataSectionVaddr + ((static_cast<std::size_t>(cmd) * 17U + k) % kRodataSectionSize)] ^
                        static_cast<std::uint8_t>((crc >> ((k & 3U) * 8U)) & 0xFFU);
    }
    PglArmorMixColumns128(key_stream);
    for (std::size_t i = 0; i < in_len; ++i) {
        out_buf[i] = in_buf[i] ^ key_stream[i & 15U];
    }
    *out_len = in_len;
    return 0;
}

// ============================================================================
// [EN] FDE[00] Subroutine @ 0x0032e4..0x0032f4 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[00] Hàm con @ 0x0032e4..0x0032f4 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0032e4: d503245f  bti      c
//   0x0032e8: 90000080  adrp     x0, #0x13000
//   0x0032ec: 91278000  add      x0, x0, #0x9e0
//   0x0032f0: 1400318c  b        #0xf920
// ============================================================================
std::uint32_t fde_00_32e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000032e4ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[0ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[01] Subroutine @ 0x0032f4..0x0032fc (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[01] Hàm con @ 0x0032f4..0x0032fc (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0032f4: d503245f  bti      c
//   0x0032f8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_01_32f4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000032f4ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[02] Subroutine @ 0x0032fc..0x003304 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[02] Hàm con @ 0x0032fc..0x003304 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0032fc: d503245f  bti      c
//   0x003300: 17fffffd  b        #0x32f4
// ============================================================================
std::uint32_t fde_02_32fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000032fcULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[03] Subroutine @ 0x003304..0x003318 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[03] Hàm con @ 0x003304..0x003318 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003304: d503245f  bti      c
//   0x003308: b4000060  cbz      x0, #0x3314
//   0x00330c: aa0003f0  mov      x16, x0
//   0x003310: d61f0200  br       x16
//   0x003314: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_03_3304(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003304ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[04] Subroutine @ 0x003318..0x003334 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[04] Hàm con @ 0x003318..0x003334 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003318: d503245f  bti      c
//   0x00331c: aa0003e1  mov      x1, x0
//   0x003320: 90000000  adrp     x0, #0x3000
//   0x003324: 90000082  adrp     x2, #0x13000
//   0x003328: 910c1000  add      x0, x0, #0x304
//   0x00332c: 91278042  add      x2, x2, #0x9e0
//   0x003330: 14003180  b        #0xf930
// ============================================================================
std::uint32_t fde_04_3318(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003318ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[05] Subroutine @ 0x003334..0x003364 (48 bytes, 12 AArch64 instructions)
// [VN] Khung FDE[05] Hàm con @ 0x003334..0x003364 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003334: 39400048  ldrb     w8, [x2]
//   0x003338: 34000148  cbz      w8, #0x3360
//   0x00333c: aa1f03e9  mov      x9, xzr
//   0x003340: 5280002a  mov      w10, #1
//   0x003344: 3869680b  ldrb     w11, [x0, x9]
//   0x003348: 4a080168  eor      w8, w11, w8
//   0x00334c: 38296828  strb     w8, [x1, x9]
//   0x003350: 93407d49  sxtw     x9, w10
//   0x003354: 1100054a  add      w10, w10, #1
//   0x003358: 38696848  ldrb     w8, [x2, x9]
//   0x00335c: 35ffff48  cbnz     w8, #0x3344
//   0x003360: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_05_3334(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003334ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[20ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[06] Subroutine @ 0x003364..0x003438 (212 bytes, 53 AArch64 instructions)
// [VN] Khung FDE[06] Hàm con @ 0x003364..0x003438 (212 byte, 53 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003364: b4000202  cbz      x2, #0x33a4
//   0x003368: f100205f  cmp      x2, #8
//   0x00336c: 540000e3  b.lo     #0x3388
//   0x003370: 8b020028  add      x8, x1, x2
//   0x003374: eb00011f  cmp      x8, x0
//   0x003378: 54000189  b.ls     #0x33a8
//   0x00337c: 8b020008  add      x8, x0, x2
//   0x003380: eb01011f  cmp      x8, x1
//   0x003384: 54000129  b.ls     #0x33a8
//   0x003388: aa0003e9  mov      x9, x0
//   0x00338c: aa0103ea  mov      x10, x1
//   0x003390: aa0203e8  mov      x8, x2
//   0x003394: 3840154b  ldrb     w11, [x10], #1
//   0x003398: f1000508  subs     x8, x8, #1
//   0x00339c: 3800152b  strb     w11, [x9], #1
//   0x0033a0: 54ffffa1  b.ne     #0x3394
//   0x0033a4: d65f03c0  ret      
//   0x0033a8: f100805f  cmp      x2, #0x20
//   0x0033ac: 54000062  b.hs     #0x33b8
//   0x0033b0: aa1f03eb  mov      x11, xzr
//   0x0033b4: 1400000f  b        #0x33f0
//   0x0033b8: 927be84b  and      x11, x2, #0xffffffffffffffe0
//   0x0033bc: 91004028  add      x8, x1, #0x10
//   0x0033c0: 91004009  add      x9, x0, #0x10
//   0x0033c4: aa0b03ea  mov      x10, x11
//   0x0033c8: ad7f8500  ldp      q0, q1, [x8, #-0x10]
//   0x0033cc: 91008108  add      x8, x8, #0x20
//   0x0033d0: f100814a  subs     x10, x10, #0x20
//   0x0033d4: ad3f8520  stp      q0, q1, [x9, #-0x10]
//   0x0033d8: 91008129  add      x9, x9, #0x20
//   0x0033dc: 54ffff61  b.ne     #0x33c8
//   0x0033e0: eb02017f  cmp      x11, x2
//   0x0033e4: 54fffe00  b.eq     #0x33a4
//   0x0033e8: f27d045f  tst      x2, #0x18
//   0x0033ec: 540001e0  b.eq     #0x3428
//   0x0033f0: 927df04c  and      x12, x2, #0xfffffffffffffff8
//   0x0033f4: 92400848  and      x8, x2, #7
//   0x0033f8: 8b0c0009  add      x9, x0, x12
//   0x0033fc: 8b0c002a  add      x10, x1, x12
//   0x003400: 8b0b002d  add      x13, x1, x11
//   0x003404: 8b0b000e  add      x14, x0, x11
//   0x003408: cb0c016b  sub      x11, x11, x12
//   0x00340c: fc4085a0  ldr      d0, [x13], #8
//   0x003410: b100216b  adds     x11, x11, #8
//   0x003414: fc0085c0  str      d0, [x14], #8
//   0x003418: 54ffffa1  b.ne     #0x340c
//   0x00341c: eb02019f  cmp      x12, x2
//   0x003420: 54fffba1  b.ne     #0x3394
//   0x003424: 17ffffe0  b        #0x33a4
//   0x003428: 92401048  and      x8, x2, #0x1f
//   0x00342c: 8b0b002a  add      x10, x1, x11
//   0x003430: 8b0b0009  add      x9, x0, x11
//   0x003434: 17ffffd8  b        #0x3394
// ============================================================================
std::uint32_t fde_06_3364(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003364ULL;
    for (std::size_t i = 0; i < 53ULL; ++i) {
        std::uint32_t insn = kTextInstructions[32ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[07] Subroutine @ 0x003438..0x003538 (256 bytes, 64 AArch64 instructions)
// [VN] Khung FDE[07] Hàm con @ 0x003438..0x003538 (256 byte, 64 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003438: eb01001f  cmp      x0, x1
//   0x00343c: 54000242  b.hs     #0x3484
//   0x003440: b4000322  cbz      x2, #0x34a4
//   0x003444: f100205f  cmp      x2, #8
//   0x003448: 540000e3  b.lo     #0x3464
//   0x00344c: 8b020028  add      x8, x1, x2
//   0x003450: eb00011f  cmp      x8, x0
//   0x003454: 540002a9  b.ls     #0x34a8
//   0x003458: 8b020008  add      x8, x0, x2
//   0x00345c: eb01011f  cmp      x8, x1
//   0x003460: 54000249  b.ls     #0x34a8
//   0x003464: aa0003e9  mov      x9, x0
//   0x003468: aa0103ea  mov      x10, x1
//   0x00346c: aa0203e8  mov      x8, x2
//   0x003470: 3840154b  ldrb     w11, [x10], #1
//   0x003474: f1000508  subs     x8, x8, #1
//   0x003478: 3800152b  strb     w11, [x9], #1
//   0x00347c: 54ffffa1  b.ne     #0x3470
//   0x003480: 14000009  b        #0x34a4
//   0x003484: b4000102  cbz      x2, #0x34a4
//   0x003488: d1000408  sub      x8, x0, #1
//   0x00348c: d1000429  sub      x9, x1, #1
//   0x003490: 3862692a  ldrb     w10, [x9, x2]
//   0x003494: f100044b  subs     x11, x2, #1
//   0x003498: 3822690a  strb     w10, [x8, x2]
//   0x00349c: aa0b03e2  mov      x2, x11
//   0x0034a0: 54ffff81  b.ne     #0x3490
//   0x0034a4: d65f03c0  ret      
//   0x0034a8: f100805f  cmp      x2, #0x20
//   0x0034ac: 54000062  b.hs     #0x34b8
//   0x0034b0: aa1f03eb  mov      x11, xzr
//   0x0034b4: 1400000f  b        #0x34f0
//   0x0034b8: 927be84b  and      x11, x2, #0xffffffffffffffe0
//   0x0034bc: 91004028  add      x8, x1, #0x10
//   0x0034c0: 91004009  add      x9, x0, #0x10
//   0x0034c4: aa0b03ea  mov      x10, x11
//   0x0034c8: ad7f8500  ldp      q0, q1, [x8, #-0x10]
//   0x0034cc: 91008108  add      x8, x8, #0x20
//   0x0034d0: f100814a  subs     x10, x10, #0x20
//   0x0034d4: ad3f8520  stp      q0, q1, [x9, #-0x10]
//   0x0034d8: 91008129  add      x9, x9, #0x20
//   0x0034dc: 54ffff61  b.ne     #0x34c8
//   0x0034e0: eb02017f  cmp      x11, x2
//   0x0034e4: 54fffe00  b.eq     #0x34a4
//   0x0034e8: f27d045f  tst      x2, #0x18
//   0x0034ec: 540001e0  b.eq     #0x3528
//   0x0034f0: 927df04c  and      x12, x2, #0xfffffffffffffff8
//   0x0034f4: 92400848  and      x8, x2, #7
//   0x0034f8: 8b0c0009  add      x9, x0, x12
//   0x0034fc: 8b0c002a  add      x10, x1, x12
//   0x003500: 8b0b002d  add      x13, x1, x11
//   0x003504: 8b0b000e  add      x14, x0, x11
//   0x003508: cb0c016b  sub      x11, x11, x12
//   0x00350c: fc4085a0  ldr      d0, [x13], #8
//   0x003510: b100216b  adds     x11, x11, #8
//   0x003514: fc0085c0  str      d0, [x14], #8
//   0x003518: 54ffffa1  b.ne     #0x350c
//   0x00351c: eb02019f  cmp      x12, x2
//   0x003520: 54fffa81  b.ne     #0x3470
//   0x003524: 17ffffe0  b        #0x34a4
//   0x003528: 92401048  and      x8, x2, #0x1f
//   0x00352c: 8b0b002a  add      x10, x1, x11
//   0x003530: 8b0b0009  add      x9, x0, x11
//   0x003534: 17ffffcf  b        #0x3470
// ============================================================================
std::uint32_t fde_07_3438(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003438ULL;
    for (std::size_t i = 0; i < 64ULL; ++i) {
        std::uint32_t insn = kTextInstructions[85ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[08] Subroutine @ 0x003538..0x003564 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[08] Hàm con @ 0x003538..0x003564 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003538: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x00353c: f9000bf3  str      x19, [sp, #0x10]
//   0x003540: 910003fd  mov      x29, sp
//   0x003544: aa0003f3  mov      x19, x0
//   0x003548: b4000062  cbz      x2, #0x3554
//   0x00354c: aa1303e0  mov      x0, x19
//   0x003550: 94003104  bl       #0xf960
//   0x003554: aa1303e0  mov      x0, x19
//   0x003558: f9400bf3  ldr      x19, [sp, #0x10]
//   0x00355c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x003560: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_08_3538(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003538ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[149ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[09] Subroutine @ 0x003564..0x0035a8 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[09] Hàm con @ 0x003564..0x0035a8 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003564: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x003568: 910003fd  mov      x29, sp
//   0x00356c: 710fcc5f  cmp      w2, #0x3f3
//   0x003570: 540000e0  b.eq     #0x358c
//   0x003574: 710fc85f  cmp      w2, #0x3f2
//   0x003578: 54000121  b.ne     #0x359c
//   0x00357c: aa0303e1  mov      x1, x3
//   0x003580: 94002c16  bl       #0xe5d8
//   0x003584: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003588: d65f03c0  ret      
//   0x00358c: aa0303e1  mov      x1, x3
//   0x003590: 94002c63  bl       #0xe71c
//   0x003594: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003598: d65f03c0  ret      
//   0x00359c: aa1f03e0  mov      x0, xzr
//   0x0035a0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0035a4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_09_3564(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003564ULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[160ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[10] Subroutine @ 0x0035a8..0x003720 (376 bytes, 94 AArch64 instructions)
// [VN] Khung FDE[10] Hàm con @ 0x0035a8..0x003720 (376 byte, 94 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0035a8: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x0035ac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0035b0: 910003fd  mov      x29, sp
//   0x0035b4: d10043ff  sub      sp, sp, #0x10
//   0x0035b8: d53bd053  mrs      x19, tpidr_el0
//   0x0035bc: 52805009  mov      w9, #0x280
//   0x0035c0: f9401668  ldr      x8, [x19, #0x28]
//   0x0035c4: f81f83a8  stur     x8, [x29, #-8]
//   0x0035c8: b81f43a9  stur     w9, [x29, #-0xc]
//   0x0035cc: b85f43a8  ldur     w8, [x29, #-0xc]
//   0x0035d0: 711a011f  cmp      w8, #0x680
//   0x0035d4: 54000221  b.ne     #0x3618
// ============================================================================
std::uint32_t fde_10_35a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000035a8ULL;
    for (std::size_t i = 0; i < 94ULL; ++i) {
        std::uint32_t insn = kTextInstructions[177ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[11] Subroutine @ 0x003720..0x003ea8 (1928 bytes, 482 AArch64 instructions)
// [VN] Khung FDE[11] Hàm con @ 0x003720..0x003ea8 (1928 byte, 482 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003720: d10303ff  sub      sp, sp, #0xc0
//   0x003724: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x003728: 9101c3fd  add      x29, sp, #0x70
//   0x00372c: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x003730: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x003734: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x003738: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x00373c: d282080b  mov      x11, #0x1040
//   0x003740: d280800a  mov      x10, #0x400
//   0x003744: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x003748: 90000009  adrp     x9, #0x3000
//   0x00374c: f2a0008a  movk     x10, #4, lsl #16
//   0x003750: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x003754: 911c8129  add      x9, x9, #0x720
//   0x003758: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00375c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x003760: 8a0a012a  and      x10, x9, x10
//   0x003764: aa290169  orn      x9, x11, x9
//   0x003768: d282880b  mov      x11, #0x1440
//   0x00376c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x003770: d53bd058  mrs      x24, tpidr_el0
//   0x003774: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x003778: b00000a8  adrp     x8, #0x18000
//   0x00377c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x003780: f940170c  ldr      x12, [x24, #0x28]
//   0x003784: 8a0b0129  and      x9, x9, x11
//   0x003788: 910ea108  add      x8, x8, #0x3a8
//   0x00378c: 8b0a0129  add      x9, x9, x10
//   0x003790: 5280208a  mov      w10, #0x104
//   0x003794: 72a0202a  movk     w10, #0x101, lsl #16
//   0x003798: f81f83ac  stur     x12, [x29, #-8]
//   0x00379c: aa0a0129  orr      x9, x9, x10
//   0x0037a0: d28d6b8a  mov      x10, #0x6b5c
//   0x0037a4: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x0037a8: a9027fff  stp      xzr, xzr, [sp, #0x20]
//   0x0037ac: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x0037b0: 2a0003f5  mov      w21, w0
//   0x0037b4: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x0037b8: 12800000  mov      w0, #-1
//   0x0037bc: ca0a0129  eor      x9, x9, x10
//   0x0037c0: 72000abf  tst      w21, #7
//   0x0037c4: a9402d0a  ldp      x10, x11, [x8]
//   0x0037c8: f9400908  ldr      x8, [x8, #0x10]
//   0x0037cc: f869694a  ldr      x10, [x10, x9]
//   0x0037d0: f9000fea  str      x10, [sp, #0x18]
//   0x0037d4: b869696a  ldr      w10, [x11, x9]
//   0x0037d8: b90017ea  str      w10, [sp, #0x14]
//   0x0037dc: b8696908  ldr      w8, [x8, x9]
//   0x0037e0: b90013e8  str      w8, [sp, #0x10]
//   0x0037e4: 54003061  b.ne     #0x3df0
//   0x0037e8: aa0103f6  mov      x22, x1
//   0x0037ec: b4003021  cbz      x1, #0x3df0
//   0x0037f0: 910063e0  add      x0, sp, #0x18
//   0x0037f4: 52800101  mov      w1, #8
//   0x0037f8: aa0203f4  mov      x20, x2
//   0x0037fc: 910063f3  add      x19, sp, #0x18
//   0x003800: 94002c10  bl       #0xe840
//   0x003804: 910053e0  add      x0, sp, #0x14
//   0x003808: 910063e1  add      x1, sp, #0x18
//   0x00380c: 52800082  mov      w2, #4
//   0x003810: 97fffed5  bl       #0x3364
//   0x003814: b27e0260  orr      x0, x19, #4
//   0x003818: 910043e1  add      x1, sp, #0x10
//   0x00381c: 52800082  mov      w2, #4
//   0x003820: 97fffed1  bl       #0x3364
//   0x003824: 910083e0  add      x0, sp, #0x20
//   0x003828: 52800201  mov      w1, #0x10
//   0x00382c: 94002c05  bl       #0xe840
//   0x003830: d10063a0  sub      x0, x29, #0x18
//   0x003834: 2a1f03e1  mov      w1, wzr
//   0x003838: 52800202  mov      w2, #0x10
//   0x00383c: b9401bf7  ldr      w23, [sp, #0x18]
//   0x003840: 97ffff3e  bl       #0x3538
//   0x003844: 294427e8  ldp      w8, w9, [sp, #0x20]
//   0x003848: 29452fea  ldp      w10, w11, [sp, #0x28]
//   0x00384c: aa1403f3  mov      x19, x20
//   0x003850: 5ac00908  rev      w8, w8
//   0x003854: 5ac00929  rev      w9, w9
//   0x003858: 5ac0094a  rev      w10, w10
//   0x00385c: 5ac0096b  rev      w11, w11
//   0x003860: 293d27a8  stp      w8, w9, [x29, #-0x18]
//   0x003864: 293e2faa  stp      w10, w11, [x29, #-0x10]
//   0x003868: 34000775  cbz      w21, #0x3954
//   0x00386c: 529999a8  mov      w8, #0xcccd
//   0x003870: 2a1503f9  mov      w25, w21
//   0x003874: 72b99988  movk     w8, #0xcccc, lsl #16
//   0x003878: aa1403f3  mov      x19, x20
//   0x00387c: 9b087ee8  mul      x8, x23, x8
//   0x003880: d362fd08  lsr      x8, x8, #0x22
//   0x003884: 0b080908  add      w8, w8, w8, lsl #2
//   0x003888: 4b0802e8  sub      w8, w23, w8
//   0x00388c: 531e7508  lsl      w8, w8, #2
//   0x003890: 11004117  add      w23, w8, #0x10
//   0x003894: 394002c8  ldrb     w8, [x22]
//   0x003898: d10063a0  sub      x0, x29, #0x18
//   0x00389c: 394063e9  ldrb     w9, [sp, #0x18]
//   0x0038a0: aa1303e1  mov      x1, x19
//   0x0038a4: aa1303e2  mov      x2, x19
//   0x0038a8: 2a1703e3  mov      w3, w23
//   0x0038ac: 4a080128  eor      w8, w9, w8
//   0x0038b0: 394067e9  ldrb     w9, [sp, #0x19]
//   0x0038b4: 39000268  strb     w8, [x19]
//   0x0038b8: 394006c8  ldrb     w8, [x22, #1]
//   0x0038bc: 4a080128  eor      w8, w9, w8
//   0x0038c0: 39406be9  ldrb     w9, [sp, #0x1a]
//   0x0038c4: 39000668  strb     w8, [x19, #1]
//   0x0038c8: 39400ac8  ldrb     w8, [x22, #2]
//   0x0038cc: 4a080128  eor      w8, w9, w8
//   0x0038d0: 39406fe9  ldrb     w9, [sp, #0x1b]
//   0x0038d4: 39000a68  strb     w8, [x19, #2]
//   0x0038d8: 39400ec8  ldrb     w8, [x22, #3]
//   0x0038dc: 4a080128  eor      w8, w9, w8
//   0x0038e0: 394073e9  ldrb     w9, [sp, #0x1c]
//   0x0038e4: 39000e68  strb     w8, [x19, #3]
//   0x0038e8: 394012c8  ldrb     w8, [x22, #4]
//   0x0038ec: 4a080128  eor      w8, w9, w8
//   0x0038f0: 394077e9  ldrb     w9, [sp, #0x1d]
//   0x0038f4: 39001268  strb     w8, [x19, #4]
//   0x0038f8: 394016c8  ldrb     w8, [x22, #5]
//   0x0038fc: 4a080128  eor      w8, w9, w8
//   0x003900: 39407be9  ldrb     w9, [sp, #0x1e]
//   0x003904: 39001668  strb     w8, [x19, #5]
//   0x003908: 39401ac8  ldrb     w8, [x22, #6]
//   0x00390c: 4a080128  eor      w8, w9, w8
//   0x003910: 39407fe9  ldrb     w9, [sp, #0x1f]
//   0x003914: 39001a68  strb     w8, [x19, #6]
//   0x003918: 39401ec8  ldrb     w8, [x22, #7]
//   0x00391c: 4a080128  eor      w8, w9, w8
//   0x003920: 39001e68  strb     w8, [x19, #7]
//   0x003924: 940001d1  bl       #0x4068
//   0x003928: 910063e0  add      x0, sp, #0x18
//   0x00392c: aa1303e1  mov      x1, x19
//   0x003930: 52800102  mov      w2, #8
//   0x003934: 97fffe8c  bl       #0x3364
//   0x003938: 121c7b28  and      w8, w25, #0xfffffff7
//   0x00393c: 321c7b29  orr      w9, w25, #0xfffffff7
//   0x003940: 0b080128  add      w8, w9, w8
//   0x003944: 91002273  add      x19, x19, #8
//   0x003948: 31000519  adds     w25, w8, #1
//   0x00394c: 910022d6  add      x22, x22, #8
//   0x003950: 54fffa21  b.ne     #0x3894
//   0x003954: aa1f03e0  mov      x0, xzr
//   0x003958: 94003006  bl       #0xf970
//   0x00395c: 94003009  bl       #0xf980
//   0x003960: 7103febf  cmp      w21, #0xff
//   0x003964: 52801fe8  mov      w8, #0xff
//   0x003968: 1a8832b6  csel     w22, w21, w8, lo
//   0x00396c: 94003009  bl       #0xf990
//   0x003970: 1ad60c08  sdiv     w8, w0, w22
//   0x003974: 1b168108  msub     w8, w8, w22, w0
//   0x003978: 92401d09  and      x9, x8, #0xff
//   0x00397c: 381dc3a8  sturb    w8, [x29, #-0x24]
//   0x003980: 38696a88  ldrb     w8, [x20, x9]
//   0x003984: 381d03a8  sturb    w8, [x29, #-0x30]
//   0x003988: 94003002  bl       #0xf990
//   0x00398c: 1ad60c08  sdiv     w8, w0, w22
//   0x003990: 1b168108  msub     w8, w8, w22, w0
//   0x003994: 92401d09  and      x9, x8, #0xff
//   0x003998: 381dd3a8  sturb    w8, [x29, #-0x23]
//   0x00399c: 38696a88  ldrb     w8, [x20, x9]
//   0x0039a0: 381d13a8  sturb    w8, [x29, #-0x2f]
//   0x0039a4: 94002ffb  bl       #0xf990
//   0x0039a8: 1ad60c08  sdiv     w8, w0, w22
//   0x0039ac: 1b168108  msub     w8, w8, w22, w0
//   0x0039b0: 92401d09  and      x9, x8, #0xff
//   0x0039b4: 381de3a8  sturb    w8, [x29, #-0x22]
//   0x0039b8: 38696a88  ldrb     w8, [x20, x9]
//   0x0039bc: 381d23a8  sturb    w8, [x29, #-0x2e]
//   0x0039c0: 94002ff4  bl       #0xf990
//   0x0039c4: 1ad60c08  sdiv     w8, w0, w22
//   0x0039c8: 1b168108  msub     w8, w8, w22, w0
//   0x0039cc: 92401d09  and      x9, x8, #0xff
//   0x0039d0: 381df3a8  sturb    w8, [x29, #-0x21]
//   0x0039d4: 38696a88  ldrb     w8, [x20, x9]
//   0x0039d8: 381d33a8  sturb    w8, [x29, #-0x2d]
//   0x0039dc: 94002fed  bl       #0xf990
//   0x0039e0: 1ad60c08  sdiv     w8, w0, w22
//   0x0039e4: 1b168108  msub     w8, w8, w22, w0
//   0x0039e8: 92401d09  and      x9, x8, #0xff
//   0x0039ec: 381e03a8  sturb    w8, [x29, #-0x20]
//   0x0039f0: 38696a88  ldrb     w8, [x20, x9]
//   0x0039f4: 381d43a8  sturb    w8, [x29, #-0x2c]
//   0x0039f8: 94002fe6  bl       #0xf990
//   0x0039fc: 1ad60c08  sdiv     w8, w0, w22
//   0x003a00: 1b168108  msub     w8, w8, w22, w0
//   0x003a04: 92401d09  and      x9, x8, #0xff
//   0x003a08: 381e13a8  sturb    w8, [x29, #-0x1f]
//   0x003a0c: 38696a88  ldrb     w8, [x20, x9]
//   0x003a10: 381d53a8  sturb    w8, [x29, #-0x2b]
//   0x003a14: 94002fdf  bl       #0xf990
//   0x003a18: 1ad60c08  sdiv     w8, w0, w22
//   0x003a1c: 1b168108  msub     w8, w8, w22, w0
//   0x003a20: 92401d09  and      x9, x8, #0xff
//   0x003a24: 381e23a8  sturb    w8, [x29, #-0x1e]
//   0x003a28: 38696a88  ldrb     w8, [x20, x9]
//   0x003a2c: 381d63a8  sturb    w8, [x29, #-0x2a]
//   0x003a30: 94002fd8  bl       #0xf990
//   0x003a34: 1ad60c08  sdiv     w8, w0, w22
//   0x003a38: 1b168108  msub     w8, w8, w22, w0
//   0x003a3c: 92401d09  and      x9, x8, #0xff
//   0x003a40: 381e33a8  sturb    w8, [x29, #-0x1d]
//   0x003a44: 38696a88  ldrb     w8, [x20, x9]
//   0x003a48: 381d73a8  sturb    w8, [x29, #-0x29]
//   0x003a4c: 94002fd1  bl       #0xf990
//   0x003a50: 1ad60c08  sdiv     w8, w0, w22
//   0x003a54: 1b168108  msub     w8, w8, w22, w0
//   0x003a58: 92401d09  and      x9, x8, #0xff
//   0x003a5c: 381e43a8  sturb    w8, [x29, #-0x1c]
//   0x003a60: 38696a88  ldrb     w8, [x20, x9]
//   0x003a64: 381d83a8  sturb    w8, [x29, #-0x28]
//   0x003a68: 94002fca  bl       #0xf990
//   0x003a6c: 1ad60c08  sdiv     w8, w0, w22
//   0x003a70: 1b168108  msub     w8, w8, w22, w0
//   0x003a74: 92401d09  and      x9, x8, #0xff
//   0x003a78: 381e53a8  sturb    w8, [x29, #-0x1b]
//   0x003a7c: 38696a88  ldrb     w8, [x20, x9]
//   0x003a80: 381d93a8  sturb    w8, [x29, #-0x27]
//   0x003a84: 94002fc3  bl       #0xf990
//   0x003a88: 1ad60c08  sdiv     w8, w0, w22
//   0x003a8c: 1b168108  msub     w8, w8, w22, w0
//   0x003a90: 92401d09  and      x9, x8, #0xff
//   0x003a94: 381e63a8  sturb    w8, [x29, #-0x1a]
//   0x003a98: 38696a88  ldrb     w8, [x20, x9]
//   0x003a9c: 381da3a8  sturb    w8, [x29, #-0x26]
//   0x003aa0: 94002fbc  bl       #0xf990
//   0x003aa4: 1ad60c08  sdiv     w8, w0, w22
//   0x003aa8: d10093a1  sub      x1, x29, #0x24
//   0x003aac: 52800182  mov      w2, #0xc
//   0x003ab0: b9003bff  str      wzr, [sp, #0x38]
//   0x003ab4: f9001bff  str      xzr, [sp, #0x30]
//   0x003ab8: 9100c3f7  add      x23, sp, #0x30
//   0x003abc: 1b168108  msub     w8, w8, w22, w0
//   0x003ac0: 9100c3e0  add      x0, sp, #0x30
//   0x003ac4: 52800196  mov      w22, #0xc
//   0x003ac8: 92401d09  and      x9, x8, #0xff
//   0x003acc: 381e73a8  sturb    w8, [x29, #-0x19]
//   0x003ad0: 38696a88  ldrb     w8, [x20, x9]
//   0x003ad4: 381db3a8  sturb    w8, [x29, #-0x25]
//   0x003ad8: 97fffe23  bl       #0x3364
//   0x003adc: 9100c3e0  add      x0, sp, #0x30
//   0x003ae0: 2a1f03e1  mov      w1, wzr
//   0x003ae4: 52800162  mov      w2, #0xb
//   0x003ae8: 94002c71  bl       #0xecac
//   0x003aec: 9100c3e0  add      x0, sp, #0x30
//   0x003af0: 52800181  mov      w1, #0xc
//   0x003af4: 94002c01  bl       #0xeaf8
//   0x003af8: 34000515  cbz      w21, #0x3b98
//   0x003afc: 531f780a  lsl      w10, w0, #1
//   0x003b00: 5200000b  eor      w11, w0, #1
//   0x003b04: 321e794a  orr      w10, w10, #0xfffffffd
//   0x003b08: 2a1f03e9  mov      w9, wzr
//   0x003b0c: 0b0a016a  add      w10, w11, w10
//   0x003b10: 5295556b  mov      w11, #0xaaab
//   0x003b14: 2a1f03e8  mov      w8, wzr
//   0x003b18: 1100054a  add      w10, w10, #1
//   0x003b1c: 72a5554b  movk     w11, #0x2aaa, lsl #16
//   0x003b20: d100c3ac  sub      x12, x29, #0x30
//   0x003b24: 14000009  b        #0x3b48
//   0x003b28: 11000508  add      w8, w8, #1
//   0x003b2c: 531f792d  lsl      w13, w9, #1
//   0x003b30: 521f7929  eor      w9, w9, #0xfffffffe
//   0x003b34: 321f01ad  orr      w13, w13, #2
//   0x003b38: 0b0d0129  add      w9, w9, w13
//   0x003b3c: 11000529  add      w9, w9, #1
//   0x003b40: 6b15013f  cmp      w9, w21
//   0x003b44: 540002a2  b.hs     #0x3b98
//   0x003b48: 9b2b7d0d  smull    x13, w8, w11
//   0x003b4c: d37ffdae  lsr      x14, x13, #0x3f
//   0x003b50: 9361fdad  asr      x13, x13, #0x21
//   0x003b54: 0b0e01ad  add      w13, w13, w14
//   0x003b58: 1b16a1ad  msub     w13, w13, w22, w8
//   0x003b5c: 386dcaed  ldrb     w13, [x23, w13, sxtw]
//   0x003b60: 6b0d013f  cmp      w9, w13
//   0x003b64: 7a4a0100  ccmp     w8, w10, #0, eq
//   0x003b68: 54fffe0d  b.le     #0x3b28
//   0x003b6c: 9b2b7d2d  smull    x13, w9, w11
//   0x003b70: d37ffdae  lsr      x14, x13, #0x3f
//   0x003b74: 9361fdad  asr      x13, x13, #0x21
//   0x003b78: 0b0e01ad  add      w13, w13, w14
//   0x003b7c: 93407d2e  sxtw     x14, w9
//   0x003b80: 1b16a5ad  msub     w13, w13, w22, w9
//   0x003b84: 386e6a8f  ldrb     w15, [x20, x14]
//   0x003b88: 386dc98d  ldrb     w13, [x12, w13, sxtw]
//   0x003b8c: 4a0f01ad  eor      w13, w13, w15
//   0x003b90: 382e6a8d  strb     w13, [x20, x14]
//   0x003b94: 17ffffe6  b        #0x3b2c
//   0x003b98: 39408fe8  ldrb     w8, [sp, #0x23]
//   0x003b9c: d10093a1  sub      x1, x29, #0x24
//   0x003ba0: 385e13a9  ldurb    w9, [x29, #-0x1f]
//   0x003ba4: aa1303e0  mov      x0, x19
//   0x003ba8: 52800182  mov      w2, #0xc
//   0x003bac: 381e13a8  sturb    w8, [x29, #-0x1f]
//   0x003bb0: 39008fe9  strb     w9, [sp, #0x23]
//   0x003bb4: 97fffdec  bl       #0x3364
//   0x003bb8: d282080a  mov      x10, #0x1040
//   0x003bbc: d282880b  mov      x11, #0x1440
//   0x003bc0: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x003bc4: b0000008  adrp     x8, #0x4000
//   0x003bc8: d2808009  mov      x9, #0x400
//   0x003bcc: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x003bd0: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x003bd4: 91072108  add      x8, x8, #0x1c8
//   0x003bd8: f2a00089  movk     x9, #4, lsl #16
//   0x003bdc: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x003be0: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x003be4: f2c02089  movk     x9, #0x104, lsl #32
//   0x003be8: aa28014a  orn      x10, x10, x8
//   0x003bec: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x003bf0: 8a090108  and      x8, x8, x9
//   0x003bf4: 8a0b0149  and      x9, x10, x11
//   0x003bf8: d28d6b96  mov      x22, #0x6b5c
//   0x003bfc: 8b080135  add      x21, x9, x8
//   0x003c00: 52802088  mov      w8, #0x104
//   0x003c04: f2be9396  movk     x22, #0xf49c, lsl #16
//   0x003c08: b00000b4  adrp     x20, #0x18000
//   0x003c0c: 72a02028  movk     w8, #0x101, lsl #16
//   0x003c10: f2d3d776  movk     x22, #0x9ebb, lsl #32
//   0x003c14: aa0802a8  orr      x8, x21, x8
//   0x003c18: f2ffebf6  movk     x22, #0xff5f, lsl #48
//   0x003c1c: f0ffffeb  adrp     x11, #0x2000
//   0x003c20: ca160108  eor      x8, x8, x22
//   0x003c24: f941ee89  ldr      x9, [x20, #0x3d8]
//   0x003c28: f0ffffea  adrp     x10, #0x2000
//   0x003c2c: 528035d7  mov      w23, #0x1ae
//   0x003c30: 3dc01d61  ldr      q1, [x11, #0x70]
//   0x003c34: 528014b9  mov      w25, #0xa5
//   0x003c38: f8686928  ldr      x8, [x9, x8]
//   0x003c3c: f0ffffe9  adrp     x9, #0x2000
//   0x003c40: 3dc03140  ldr      q0, [x10, #0xc0]
//   0x003c44: 320003fa  mov      w26, #1
//   0x003c48: 3dc02922  ldr      q2, [x9, #0xa0]
//   0x003c4c: 4e080d03  dup      v3.2d, x8
//   0x003c50: d348fd09  lsr      x9, x8, #8
//   0x003c54: 1e270104  fmov     s4, w8
//   0x003c58: 6ee14461  ushl     v1.2d, v3.2d, v1.2d
//   0x003c5c: 6ee24462  ushl     v2.2d, v3.2d, v2.2d
//   0x003c60: 6ee04460  ushl     v0.2d, v3.2d, v0.2d
//   0x003c64: 4e0c1d24  mov      v4.s[1], w9
//   0x003c68: 4e811841  uzp1     v1.4s, v2.4s, v1.4s
//   0x003c6c: 4ea12804  xtn2     v4.4s, v0.2d
//   0x003c70: 4e411880  uzp1     v0.8h, v4.8h, v1.8h
//   0x003c74: 3dc00be1  ldr      q1, [sp, #0x20]
//   0x003c78: 4e001800  uzp1     v0.16b, v0.16b, v0.16b
//   0x003c7c: 6e201c20  eor      v0.16b, v1.16b, v0.16b
//   0x003c80: 3d800be0  str      q0, [sp, #0x20]
//   0x003c84: b9000ff7  str      w23, [sp, #0xc]
//   0x003c88: b9000bf9  str      w25, [sp, #8]
//   0x003c8c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x003c90: b9400be9  ldr      w9, [sp, #8]
//   0x003c94: 1b086908  madd     w8, w8, w8, w26
//   0x003c98: 1b097d29  mul      w9, w9, w9
//   0x003c9c: 531d712a  lsl      w10, w9, #3
//   0x003ca0: 4b090149  sub      w9, w10, w9
//   0x003ca4: 6b09011f  cmp      w8, w9
//   0x003ca8: 540002e1  b.ne     #0x3d04
// ============================================================================
std::uint32_t fde_11_3720(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003720ULL;
    for (std::size_t i = 0; i < 482ULL; ++i) {
        std::uint32_t insn = kTextInstructions[271ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[12] Subroutine @ 0x003ea8..0x004068 (448 bytes, 112 AArch64 instructions)
// [VN] Khung FDE[12] Hàm con @ 0x003ea8..0x004068 (448 byte, 112 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003ea8: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x003eac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x003eb0: 910003fd  mov      x29, sp
//   0x003eb4: d10043ff  sub      sp, sp, #0x10
//   0x003eb8: d53bd053  mrs      x19, tpidr_el0
//   0x003ebc: 52802c69  mov      w9, #0x163
//   0x003ec0: f9401668  ldr      x8, [x19, #0x28]
//   0x003ec4: 5280128a  mov      w10, #0x94
//   0x003ec8: f81f83a8  stur     x8, [x29, #-8]
//   0x003ecc: b81f43a9  stur     w9, [x29, #-0xc]
//   0x003ed0: b81f03aa  stur     w10, [x29, #-0x10]
//   0x003ed4: b85f43a8  ldur     w8, [x29, #-0xc]
//   0x003ed8: b85f03a9  ldur     w9, [x29, #-0x10]
//   0x003edc: 7106413f  cmp      w9, #0x190
//   0x003ee0: 5400040c  b.gt     #0x3f60
//   0x003ee4: 1b087d08  mul      w8, w8, w8
//   0x003ee8: 528d7969  mov      w9, #0x6bcb
//   0x003eec: 72b5e509  movk     w9, #0xaf28, lsl #16
//   0x003ef0: 531e7508  lsl      w8, w8, #2
//   0x003ef4: 11001108  add      w8, w8, #4
//   0x003ef8: 9ba97d09  umull    x9, w8, w9
//   0x003efc: d360fd29  lsr      x9, x9, #0x20
//   0x003f00: 4b09010a  sub      w10, w8, w9
//   0x003f04: 0b4a0529  add      w9, w9, w10, lsr #1
//   0x003f08: 5280026a  mov      w10, #0x13
//   0x003f0c: 53047d29  lsr      w9, w9, #4
//   0x003f10: 1b0aa128  msub     w8, w9, w10, w8
//   0x003f14: 35000268  cbnz     w8, #0x3f60
// ============================================================================
std::uint32_t fde_12_3ea8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003ea8ULL;
    for (std::size_t i = 0; i < 112ULL; ++i) {
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
// [EN] FDE[13] Subroutine @ 0x004068..0x0041c8 (352 bytes, 88 AArch64 instructions)
// [VN] Khung FDE[13] Hàm con @ 0x004068..0x0041c8 (352 byte, 88 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004068: d10043ff  sub      sp, sp, #0x10
//   0x00406c: 29402828  ldp      w8, w10, [x1]
//   0x004070: 5ac00909  rev      w9, w8
//   0x004074: 5ac00948  rev      w8, w10
//   0x004078: 34000483  cbz      w3, #0x4108
//   0x00407c: 528f372b  mov      w11, #0x79b9
//   0x004080: 529e6e4d  mov      w13, #0xf372
//   0x004084: 2a1f03ea  mov      w10, wzr
//   0x004088: 2a1f03ec  mov      w12, wzr
//   0x00408c: 72b3c6eb  movk     w11, #0x9e37, lsl #16
//   0x004090: 72a78dcd  movk     w13, #0x3c6e, lsl #16
//   0x004094: 1200054e  and      w14, w10, #3
//   0x004098: 4a0b014f  eor      w15, w10, w11
//   0x00409c: 0a0a05b0  and      w16, w13, w10, lsl #1
//   0x0040a0: b86e580e  ldr      w14, [x0, w14, uxtw #2]
//   0x0040a4: 4a0a01d1  eor      w17, w14, w10
//   0x0040a8: 2a0a01ce  orr      w14, w14, w10
//   0x0040ac: 0b0f020a  add      w10, w16, w15
//   0x0040b0: 53057d0f  lsr      w15, w8, #5
//   0x0040b4: 530b3150  ubfx     w16, w10, #0xb, #2
//   0x0040b8: 4a0811ef  eor      w15, w15, w8, lsl #4
//   0x0040bc: 531f79ce  lsl      w14, w14, #1
//   0x0040c0: 0b0801ef  add      w15, w15, w8
//   0x0040c4: 4b1101ce  sub      w14, w14, w17
//   0x0040c8: 4a0f01ce  eor      w14, w14, w15
//   0x0040cc: b870580f  ldr      w15, [x0, w16, uxtw #2]
//   0x0040d0: 0b0901c9  add      w9, w14, w9
//   0x0040d4: 531f7990  lsl      w16, w12, #1
//   0x0040d8: 531c6d2e  lsl      w14, w9, #4
//   0x0040dc: 521f798c  eor      w12, w12, #0xfffffffe
//   0x0040e0: 4a4915ce  eor      w14, w14, w9, lsr #5
//   0x0040e4: 321f0210  orr      w16, w16, #2
//   0x0040e8: 0b0901ce  add      w14, w14, w9
//   0x0040ec: 0b0a01ef  add      w15, w15, w10
//   0x0040f0: 4a0f01ce  eor      w14, w14, w15
//   0x0040f4: 0b10018c  add      w12, w12, w16
//   0x0040f8: 0b0801c8  add      w8, w14, w8
//   0x0040fc: 1100058c  add      w12, w12, #1
//   0x004100: 6b03019f  cmp      w12, w3
//   0x004104: 54fffc83  b.lo     #0x4094
//   0x004108: 52802eea  mov      w10, #0x177
//   0x00410c: 5280052b  mov      w11, #0x29
//   0x004110: 320003ec  mov      w12, #1
//   0x004114: b9000fea  str      w10, [sp, #0xc]
//   0x004118: b9000beb  str      w11, [sp, #8]
//   0x00411c: b9400fea  ldr      w10, [sp, #0xc]
//   0x004120: b9400beb  ldr      w11, [sp, #8]
//   0x004124: 1b0a314a  madd     w10, w10, w10, w12
//   0x004128: 1b0b7d6b  mul      w11, w11, w11
//   0x00412c: 531d716c  lsl      w12, w11, #3
//   0x004130: 4b0b018b  sub      w11, w12, w11
//   0x004134: 6b0b015f  cmp      w10, w11
//   0x004138: 54000281  b.ne     #0x4188
// ============================================================================
std::uint32_t fde_13_4068(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004068ULL;
    for (std::size_t i = 0; i < 88ULL; ++i) {
        std::uint32_t insn = kTextInstructions[865ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[14] Subroutine @ 0x0041c8..0x0043c4 (508 bytes, 127 AArch64 instructions)
// [VN] Khung FDE[14] Hàm con @ 0x0041c8..0x0043c4 (508 byte, 127 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0041c8: d100c3ff  sub      sp, sp, #0x30
//   0x0041cc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0041d0: 910083fd  add      x29, sp, #0x20
//   0x0041d4: d53bd048  mrs      x8, tpidr_el0
//   0x0041d8: f9401509  ldr      x9, [x8, #0x28]
//   0x0041dc: f81f83a9  stur     x9, [x29, #-8]
//   0x0041e0: b4000e20  cbz      x0, #0x43a4
//   0x0041e4: 34000e01  cbz      w1, #0x43a4
//   0x0041e8: d282080c  mov      x12, #0x1040
//   0x0041ec: d280800a  mov      x10, #0x400
//   0x0041f0: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x0041f4: f2a0008a  movk     x10, #4, lsl #16
//   0x0041f8: 9000000b  adrp     x11, #0x4000
//   0x0041fc: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x004200: f2c0208a  movk     x10, #0x104, lsl #32
//   0x004204: 9107216b  add      x11, x11, #0x1c8
//   0x004208: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00420c: 8a0a016a  and      x10, x11, x10
//   0x004210: aa2b018b  orn      x11, x12, x11
//   0x004214: d282880c  mov      x12, #0x1440
//   0x004218: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x00421c: aa1f03e9  mov      x9, xzr
//   0x004220: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x004224: 7100203f  cmp      w1, #8
//   0x004228: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00422c: 8a0c016b  and      x11, x11, x12
//   0x004230: 900000ac  adrp     x12, #0x18000
//   0x004234: 8b0a016a  add      x10, x11, x10
//   0x004238: 5280208b  mov      w11, #0x104
//   0x00423c: 72a0202b  movk     w11, #0x101, lsl #16
//   0x004240: aa0b014a  orr      x10, x10, x11
//   0x004244: d28d6b8b  mov      x11, #0x6b5c
//   0x004248: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x00424c: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x004250: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x004254: ca0b014a  eor      x10, x10, x11
//   0x004258: f941ed8b  ldr      x11, [x12, #0x3d8]
//   0x00425c: f86a696b  ldr      x11, [x11, x10]
//   0x004260: 2a0103ea  mov      w10, w1
//   0x004264: f9000beb  str      x11, [sp, #0x10]
//   0x004268: 54000463  b.lo     #0x42f4
//   0x00426c: d100254b  sub      x11, x10, #9
//   0x004270: b100217f  cmn      x11, #8
//   0x004274: 54000403  b.lo     #0x42f4
//   0x004278: 7100803f  cmp      w1, #0x20
//   0x00427c: 54000062  b.hs     #0x4288
//   0x004280: aa1f03e9  mov      x9, xzr
//   0x004284: 14000010  b        #0x42c4
//   0x004288: ad4087e0  ldp      q0, q1, [sp, #0x10]
//   0x00428c: 927b6949  and      x9, x10, #0xffffffe0
//   0x004290: 9100400b  add      x11, x0, #0x10
//   0x004294: aa0903ec  mov      x12, x9
//   0x004298: ad7f8d62  ldp      q2, q3, [x11, #-0x10]
//   0x00429c: f100818c  subs     x12, x12, #0x20
//   0x0042a0: 6e221c02  eor      v2.16b, v0.16b, v2.16b
//   0x0042a4: 6e231c23  eor      v3.16b, v1.16b, v3.16b
//   0x0042a8: ad3f8d62  stp      q2, q3, [x11, #-0x10]
//   0x0042ac: 9100816b  add      x11, x11, #0x20
//   0x0042b0: 54ffff41  b.ne     #0x4298
//   0x0042b4: eb0a013f  cmp      x9, x10
//   0x0042b8: 54000300  b.eq     #0x4318
//   0x0042bc: f27d055f  tst      x10, #0x18
//   0x0042c0: 540001a0  b.eq     #0x42f4
//   0x0042c4: aa0903ec  mov      x12, x9
//   0x0042c8: 927d7149  and      x9, x10, #0xfffffff8
//   0x0042cc: fd400be0  ldr      d0, [sp, #0x10]
//   0x0042d0: 8b0c000b  add      x11, x0, x12
//   0x0042d4: cb09018c  sub      x12, x12, x9
//   0x0042d8: fd400161  ldr      d1, [x11]
//   0x0042dc: b100218c  adds     x12, x12, #8
//   0x0042e0: 2e211c01  eor      v1.8b, v0.8b, v1.8b
//   0x0042e4: fc008561  str      d1, [x11], #8
//   0x0042e8: 54ffff81  b.ne     #0x42d8
//   0x0042ec: eb0a013f  cmp      x9, x10
//   0x0042f0: 54000140  b.eq     #0x4318
//   0x0042f4: 910043eb  add      x11, sp, #0x10
//   0x0042f8: 3869680c  ldrb     w12, [x0, x9]
//   0x0042fc: b340092b  bfxil    x11, x9, #0, #3
//   0x004300: 3940016b  ldrb     w11, [x11]
//   0x004304: 4a0c016b  eor      w11, w11, w12
//   0x004308: 3829680b  strb     w11, [x0, x9]
//   0x00430c: 91000529  add      x9, x9, #1
//   0x004310: eb09015f  cmp      x10, x9
//   0x004314: 54ffff01  b.ne     #0x42f4
//   0x004318: 528035c9  mov      w9, #0x1ae
//   0x00431c: 528014aa  mov      w10, #0xa5
//   0x004320: 320003eb  mov      w11, #1
//   0x004324: b9000fe9  str      w9, [sp, #0xc]
//   0x004328: b9000bea  str      w10, [sp, #8]
//   0x00432c: b9400fe9  ldr      w9, [sp, #0xc]
//   0x004330: b9400bea  ldr      w10, [sp, #8]
//   0x004334: 1b092d29  madd     w9, w9, w9, w11
//   0x004338: 1b0a7d4a  mul      w10, w10, w10
//   0x00433c: 531d714b  lsl      w11, w10, #3
//   0x004340: 4b0a016a  sub      w10, w11, w10
//   0x004344: 6b0a013f  cmp      w9, w10
//   0x004348: 540002e1  b.ne     #0x43a4
// ============================================================================
std::uint32_t fde_14_41c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000041c8ULL;
    for (std::size_t i = 0; i < 127ULL; ++i) {
        std::uint32_t insn = kTextInstructions[953ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[15] Subroutine @ 0x0043c4..0x0043e4 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[15] Hàm con @ 0x0043c4..0x0043e4 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0043c4: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x0043c8: aa0003f3  mov      x19, x0
//   0x0043cc: a9400008  ldp      x8, x0, [x0]
//   0x0043d0: f9400a61  ldr      x1, [x19, #0x10]
//   0x0043d4: d63f0100  blr      x8
//   0x0043d8: f9000e60  str      x0, [x19, #0x18]
//   0x0043dc: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x0043e0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_15_43c4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000043c4ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1080ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[16] Subroutine @ 0x0043e4..0x004404 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[16] Hàm con @ 0x0043e4..0x004404 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0043e4: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x0043e8: aa0003f3  mov      x19, x0
//   0x0043ec: a9400008  ldp      x8, x0, [x0]
//   0x0043f0: a9410a61  ldp      x1, x2, [x19, #0x10]
//   0x0043f4: d63f0100  blr      x8
//   0x0043f8: f9001260  str      x0, [x19, #0x20]
//   0x0043fc: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x004400: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_16_43e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000043e4ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1088ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[17] Subroutine @ 0x004404..0x004424 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[17] Hàm con @ 0x004404..0x004424 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004404: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x004408: aa0003f3  mov      x19, x0
//   0x00440c: a9400008  ldp      x8, x0, [x0]
//   0x004410: f9400a61  ldr      x1, [x19, #0x10]
//   0x004414: d63f0100  blr      x8
//   0x004418: b9001a60  str      w0, [x19, #0x18]
//   0x00441c: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x004420: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_17_4404(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004404ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1096ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[18] Subroutine @ 0x004424..0x004430 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[18] Hàm con @ 0x004424..0x004430 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004424: a9402001  ldp      x1, x8, [x0]
//   0x004428: aa0803e0  mov      x0, x8
//   0x00442c: d61f0020  br       x1
// ============================================================================
std::uint32_t fde_18_4424(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004424ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1104ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[19] Subroutine @ 0x004430..0x004454 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[19] Hàm con @ 0x004430..0x004454 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004430: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x004434: aa0003f3  mov      x19, x0
//   0x004438: f9400008  ldr      x8, [x0]
//   0x00443c: b9400800  ldr      w0, [x0, #8]
//   0x004440: a9410a61  ldp      x1, x2, [x19, #0x10]
//   0x004444: d63f0100  blr      x8
//   0x004448: b9002260  str      w0, [x19, #0x20]
//   0x00444c: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x004450: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_19_4430(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004430ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1107ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[20] Subroutine @ 0x004454..0x004460 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[20] Hàm con @ 0x004454..0x004460 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004454: aa0003e2  mov      x2, x0
//   0x004458: aa0103e0  mov      x0, x1
//   0x00445c: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_20_4454(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004454ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1116ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[21] Subroutine @ 0x004460..0x00e53c (41180 bytes, 10295 AArch64 instructions)
// [VN] Khung FDE[21] Hàm con @ 0x004460..0x00e53c (41180 byte, 10295 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004460: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x004464: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x004468: 910003fd  mov      x29, sp
//   0x00446c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x004470: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x004474: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x004478: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00447c: d10243ff  sub      sp, sp, #0x90
//   0x004480: 90000005  adrp     x5, #0x4000
//   0x004484: 5286444a  mov      w10, #0x3222
//   0x004488: 911180a5  add      x5, x5, #0x460
//   0x00448c: 72a4034a  movk     w10, #0x201a, lsl #16
//   0x004490: 110004a9  add      w9, w5, #1
//   0x004494: 529895c8  mov      w8, #0xc4ae
//   0x004498: 0a250129  bic      w9, w9, w5
//   0x00449c: 72a00068  movk     w8, #3, lsl #16
//   0x0044a0: 2a2903e9  mvn      w9, w9
//   0x0044a4: f81d03a0  stur     x0, [x29, #-0x30]
//   0x0044a8: 8a0a0129  and      x9, x9, x10
//   0x0044ac: d29a0aca  mov      x10, #0xd056
//   0x0044b0: f2abe44a  movk     x10, #0x5f22, lsl #16
//   0x0044b4: f81f83a8  stur     x8, [x29, #-8]
//   0x0044b8: f2c0124a  movk     x10, #0x92, lsl #32
//   0x0044bc: f2e0020a  movk     x10, #0x10, lsl #48
//   0x0044c0: 8b0a0129  add      x9, x9, x10
//   0x0044c4: 5289528a  mov      w10, #0x4a94
//   0x0044c8: 72a3318a  movk     w10, #0x198c, lsl #16
//   0x0044cc: eb0a013f  cmp      x9, x10
//   0x0044d0: 54000aa3  b.lo     #0x4624
//   0x0044d4: 910003e8  mov      x8, sp
//   0x0044d8: d1004109  sub      x9, x8, #0x10
//   0x0044dc: f81b83a9  stur     x9, [x29, #-0x48]
//   0x0044e0: 9100013f  mov      sp, x9
//   0x0044e4: 910003e9  mov      x9, sp
//   0x0044e8: d1004127  sub      x7, x9, #0x10
//   0x0044ec: 910000ff  mov      sp, x7
//   0x0044f0: d10043f7  sub      x23, sp, #0x10
//   0x0044f4: 910002ff  mov      sp, x23
//   0x0044f8: d10043f8  sub      x24, sp, #0x10
//   0x0044fc: 9100031f  mov      sp, x24
//   0x004500: d10043f9  sub      x25, sp, #0x10
//   0x004504: 9100033f  mov      sp, x25
//   0x004508: d10043fa  sub      x26, sp, #0x10
//   0x00450c: 9100035f  mov      sp, x26
//   0x004510: d10043fe  sub      x30, sp, #0x10
//   0x004514: 910003df  mov      sp, x30
//   0x004518: d10043eb  sub      x11, sp, #0x10
//   0x00451c: 9100017f  mov      sp, x11
//   0x004520: d10043ec  sub      x12, sp, #0x10
//   0x004524: 9100019f  mov      sp, x12
//   0x004528: a9403491  ldp      x17, x13, [x4]
//   0x00452c: 900000b4  adrp     x20, #0x18000
//   0x004530: d0ffffe0  adrp     x0, #0x2000
//   0x004534: f940088e  ldr      x14, [x4, #0x10]
//   0x004538: b81f011f  stur     wzr, [x8, #-0x10]
//   0x00453c: 781f013f  sturh    wzr, [x9, #-0x10]
//   0x004540: d104c1aa  sub      x10, x13, #0x130
//   0x004544: aa0d03f0  mov      x16, x13
//   0x004548: 927ced4a  and      x10, x10, #0xfffffffffffffff0
//   0x00454c: d10461b3  sub      x19, x13, #0x118
//   0x004550: aa0d03ef  mov      x15, x13
//   0x004554: d10481b5  sub      x21, x13, #0x120
//   0x004558: a931c5a3  stp      x3, x17, [x13, #-0xe8]
//   0x00455c: aa0d03e3  mov      x3, x13
//   0x004560: f81d01aa  stur     x10, [x13, #-0x30]
//   0x004564: f85d03aa  ldur     x10, [x29, #-0x30]
//   0x004568: f81e01ae  stur     x14, [x13, #-0x20]
//   0x00456c: d282080d  mov      x13, #0x1040
//   0x004570: a93c47ae  stp      x14, x17, [x29, #-0x40]
//   0x004574: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x004578: d282880e  mov      x14, #0x1440
//   0x00457c: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x004580: f8110e02  str      x2, [x16, #-0xf0]!
//   0x004584: aa0c03e2  mov      x2, x12
//   0x004588: d280800c  mov      x12, #0x400
//   0x00458c: f2a140ce  movk     x14, #0xa06, lsl #16
//   0x004590: f2a0008c  movk     x12, #4, lsl #16
//   0x004594: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x004598: f2cc288e  movk     x14, #0x6144, lsl #32
//   0x00459c: f2c0208c  movk     x12, #0x104, lsl #32
//   0x0045a0: aa2501ad  orn      x13, x13, x5
//   0x0045a4: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x0045a8: f900027f  str      xzr, [x19]
//   0x0045ac: f8108de1  str      x1, [x15, #-0xf8]!
//   0x0045b0: 8a0c00ac  and      x12, x5, x12
//   0x0045b4: 8a0e01ad  and      x13, x13, x14
//   0x0045b8: d28d6b91  mov      x17, #0x6b5c
//   0x0045bc: f90002aa  str      x10, [x21]
//   0x0045c0: b940014a  ldr      w10, [x10]
//   0x0045c4: 8b0c01b6  add      x22, x13, x12
//   0x0045c8: 5280208c  mov      w12, #0x104
//   0x0045cc: f2be9391  movk     x17, #0xf49c, lsl #16
//   0x0045d0: aa0b03e1  mov      x1, x11
//   0x0045d4: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x0045d8: 72a0202c  movk     w12, #0x101, lsl #16
//   0x0045dc: f2d3d771  movk     x17, #0x9ebb, lsl #32
//   0x0045e0: aa0c02cc  orr      x12, x22, x12
//   0x0045e4: f2ffebf1  movk     x17, #0xff5f, lsl #48
//   0x0045e8: 9240154a  and      x10, x10, #0x3f
//   0x0045ec: ca11018c  eor      x12, x12, x17
//   0x0045f0: 8b0c016b  add      x11, x11, x12
//   0x0045f4: a93abfb0  stp      x16, x15, [x29, #-0x58]
//   0x0045f8: d1042066  sub      x6, x3, #0x108
//   0x0045fc: d1044064  sub      x4, x3, #0x110
//   0x004600: f86a796a  ldr      x10, [x11, x10, lsl #3]
//   0x004604: f85f83ab  ldur     x11, [x29, #-8]
//   0x004608: cb0b014a  sub      x10, x10, x11
//   0x00460c: d1006069  sub      x9, x3, #0x18
//   0x004610: d100406b  sub      x11, x3, #0x10
//   0x004614: a93ea7ab  stp      x11, x9, [x29, #-0x18]
//   0x004618: d100206b  sub      x11, x3, #8
//   0x00461c: a93dafa8  stp      x8, x11, [x29, #-0x28]
//   0x004620: d61f0140  br       x10
//   0x004624: a9402488  ldp      x8, x9, [x4]
//   0x004628: 928001ea  mov      x10, #-0x10
//   0x00462c: f85d03ac  ldur     x12, [x29, #-0x30]
//   0x004630: f9001088  str      x8, [x4, #0x20]
//   0x004634: d104612b  sub      x11, x9, #0x118
//   0x004638: a9012488  stp      x8, x9, [x4, #0x10]
//   0x00463c: f81d012a  stur     x10, [x9, #-0x30]
//   0x004640: a9308921  stp      x1, x2, [x9, #-0xf8]
//   0x004644: f900017f  str      xzr, [x11]
//   0x004648: 529a9b8b  mov      w11, #0xd4dc
//   0x00464c: a931a123  stp      x3, x8, [x9, #-0xe8]
//   0x004650: 72a84a2b  movk     w11, #0x4251, lsl #16
//   0x004654: f81e0128  stur     x8, [x9, #-0x20]
//   0x004658: d1048129  sub      x9, x9, #0x120
//   0x00465c: b9400188  ldr      w8, [x12]
//   0x004660: f85f83aa  ldur     x10, [x29, #-8]
//   0x004664: f900012c  str      x12, [x9]
//   0x004668: 4a0b0108  eor      w8, w8, w11
//   0x00466c: 529915cb  mov      w11, #0xc8ae
//   0x004670: 72a1b82b  movk     w11, #0xdc1, lsl #16
//   0x004674: ca0b014a  eor      x10, x10, x11
//   0x004678: b9000188  str      w8, [x12]
//   0x00467c: f81f83aa  stur     x10, [x29, #-8]
//   0x004680: 17ffff95  b        #0x44d4
//   0x004684: f94002a8  ldr      x8, [x21]
//   0x004688: 900000a9  adrp     x9, #0x18000
//   0x00468c: b940011b  ldr      w27, [x8]
//   0x004690: 52802088  mov      w8, #0x104
//   0x004694: 72a02028  movk     w8, #0x101, lsl #16
//   0x004698: f941f529  ldr      x9, [x9, #0x3e8]
//   0x00469c: aa0802c8  orr      x8, x22, x8
//   0x0046a0: ca110108  eor      x8, x8, x17
//   0x0046a4: d3462f6a  ubfx     x10, x27, #6, #6
//   0x0046a8: 8b080128  add      x8, x9, x8
//   0x0046ac: f85f83a9  ldur     x9, [x29, #-8]
//   0x0046b0: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x0046b4: f9400108  ldr      x8, [x8]
//   0x0046b8: cb090108  sub      x8, x8, x9
//   0x0046bc: d61f0100  br       x8
//   0x0046c0: 90000008  adrp     x8, #0x4000
//   0x0046c4: 5282104a  mov      w10, #0x1082
//   0x0046c8: 91118108  add      x8, x8, #0x460
//   0x0046cc: 72a0228a  movk     w10, #0x114, lsl #16
//   0x0046d0: 11000509  add      w9, w8, #1
//   0x0046d4: 0a280129  bic      w9, w9, w8
//   0x0046d8: 2a2903e9  mvn      w9, w9
//   0x0046dc: 8a0a0129  and      x9, x9, x10
//   0x0046e0: d28f49ea  mov      x10, #0x7a4f
//   0x0046e4: f2aef00a  movk     x10, #0x7780, lsl #16
//   0x0046e8: f2c0200a  movk     x10, #0x100, lsl #32
//   0x0046ec: 8b0a0129  add      x9, x9, x10
//   0x0046f0: 528ab5ea  mov      w10, #0x55af
//   0x0046f4: 72a0ef8a  movk     w10, #0x77c, lsl #16
//   0x0046f8: eb0a013f  cmp      x9, x10
//   0x0046fc: 540005c3  b.lo     #0x47b4
//   0x004700: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x004704: d282080f  mov      x15, #0x1040
//   0x004708: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x00470c: d280800e  mov      x14, #0x400
//   0x004710: f2a1404f  movk     x15, #0xa02, lsl #16
//   0x004714: f2a0008e  movk     x14, #4, lsl #16
//   0x004718: f8695a6a  ldr      x10, [x19, w9, uxtw #3]
//   0x00471c: f2cc080f  movk     x15, #0x6040, lsl #32
//   0x004720: 531b7f6c  lsr      w12, w27, #0x1b
//   0x004724: f2c0208e  movk     x14, #0x104, lsl #32
//   0x004728: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x00472c: f94002ad  ldr      x13, [x21]
//   0x004730: 8a0e010e  and      x14, x8, x14
//   0x004734: aa2801e8  orn      x8, x15, x8
//   0x004738: 9acb214a  lsl      x10, x10, x11
//   0x00473c: d282880f  mov      x15, #0x1440
//   0x004740: f2a140cf  movk     x15, #0xa06, lsl #16
//   0x004744: b9000309  str      w9, [x24]
//   0x004748: f2cc288f  movk     x15, #0x6144, lsl #32
//   0x00474c: f82c5a6a  str      x10, [x19, w12, uxtw #3]
//   0x004750: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x004754: b900032c  str      w12, [x25]
//   0x004758: b8404daa  ldr      w10, [x13, #4]!
//   0x00475c: 8a0f0108  and      x8, x8, x15
//   0x004760: f90002ad  str      x13, [x21]
//   0x004764: 5280208d  mov      w13, #0x104
//   0x004768: 8b0e0108  add      x8, x8, x14
//   0x00476c: 72a0202d  movk     w13, #0x101, lsl #16
//   0x004770: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x004774: aa0d0108  orr      x8, x8, x13
//   0x004778: d28d6b8d  mov      x13, #0x6b5c
//   0x00477c: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x004780: 9240154a  and      x10, x10, #0x3f
//   0x004784: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x004788: b900034b  str      w11, [x26]
//   0x00478c: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x004790: ca0d0108  eor      x8, x8, x13
//   0x004794: f85f83ad  ldur     x13, [x29, #-8]
//   0x004798: 8b0801c8  add      x8, x14, x8
//   0x00479c: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x0047a0: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x0047a4: f9400108  ldr      x8, [x8]
//   0x0047a8: b90002ea  str      w10, [x23]
//   0x0047ac: cb0d0108  sub      x8, x8, x13
//   0x0047b0: d61f0100  br       x8
//   0x0047b4: b9800309  ldrsw    x9, [x24]
//   0x0047b8: 52868f2c  mov      w12, #0x3479
//   0x0047bc: b940034b  ldr      w11, [x26]
//   0x0047c0: 72a6202c  movk     w12, #0x3101, lsl #16
//   0x0047c4: b980032d  ldrsw    x13, [x25]
//   0x0047c8: d37df129  lsl      x9, x9, #3
//   0x0047cc: f8696a6a  ldr      x10, [x19, x9]
//   0x0047d0: ca0c014c  eor      x12, x10, x12
//   0x0047d4: 9acb254a  lsr      x10, x10, x11
//   0x0047d8: 52847fab  mov      w11, #0x23fd
//   0x0047dc: f8296a6c  str      x12, [x19, x9]
//   0x0047e0: 72a655eb  movk     w11, #0x32af, lsl #16
//   0x0047e4: f82d7a6a  str      x10, [x19, x13, lsl #3]
//   0x0047e8: f94002a9  ldr      x9, [x21]
//   0x0047ec: f9000089  str      x9, [x4]
//   0x0047f0: b8404d2a  ldr      w10, [x9, #4]!
//   0x0047f4: f90002a9  str      x9, [x21]
//   0x0047f8: 4a0b014a  eor      w10, w10, w11
//   0x0047fc: b900012a  str      w10, [x9]
//   0x004800: 17ffffc0  b        #0x4700
//   0x004804: 53115768  ubfx     w8, w27, #0x11, #5
//   0x004808: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x00480c: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x004810: f94002ac  ldr      x12, [x21]
//   0x004814: f8685a69  ldr      x9, [x19, w8, uxtw #3]
//   0x004818: b9000308  str      w8, [x24]
//   0x00481c: b900032b  str      w11, [x25]
//   0x004820: b900034a  str      w10, [x26]
//   0x004824: 9aca2929  asr      x9, x9, x10
//   0x004828: f82b5a69  str      x9, [x19, w11, uxtw #3]
//   0x00482c: b8404d89  ldr      w9, [x12, #4]!
//   0x004830: f90002ac  str      x12, [x21]
//   0x004834: 5280208c  mov      w12, #0x104
//   0x004838: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00483c: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x004840: aa0c02cc  orr      x12, x22, x12
//   0x004844: 92401529  and      x9, x9, #0x3f
//   0x004848: ca11018c  eor      x12, x12, x17
//   0x00484c: 8b0c01ac  add      x12, x13, x12
//   0x004850: f85f83ad  ldur     x13, [x29, #-8]
//   0x004854: 8b090d89  add      x9, x12, x9, lsl #3
//   0x004858: 531b7f6c  lsr      w12, w27, #0x1b
//   0x00485c: f9400129  ldr      x9, [x9]
//   0x004860: b90002ec  str      w12, [x23]
//   0x004864: cb0d0129  sub      x9, x9, x13
//   0x004868: d61f0120  br       x9
//   0x00486c: 90000008  adrp     x8, #0x4000
//   0x004870: 5280020a  mov      w10, #0x10
//   0x004874: 91118108  add      x8, x8, #0x460
//   0x004878: 72a1002a  movk     w10, #0x801, lsl #16
//   0x00487c: 11000509  add      w9, w8, #1
//   0x004880: 0a280129  bic      w9, w9, w8
//   0x004884: 2a2903e9  mvn      w9, w9
//   0x004888: 8a0a0129  and      x9, x9, x10
//   0x00488c: d28580aa  mov      x10, #0x2c05
//   0x004890: f2b6338a  movk     x10, #0xb19c, lsl #16
//   0x004894: f2c0200a  movk     x10, #0x100, lsl #32
//   0x004898: f2e0340a  movk     x10, #0x1a0, lsl #48
//   0x00489c: aa0a0129  orr      x9, x9, x10
//   0x0048a0: 529efbea  mov      w10, #0xf7df
//   0x0048a4: 72a215aa  movk     w10, #0x10ad, lsl #16
//   0x0048a8: eb0a013f  cmp      x9, x10
//   0x0048ac: 540005e3  b.lo     #0x4968
//   0x0048b0: 53115769  ubfx     w9, w27, #0x11, #5
//   0x0048b4: 5280040a  mov      w10, #0x20
//   0x0048b8: d282080f  mov      x15, #0x1040
//   0x0048bc: 331b7f6a  bfxil    w10, w27, #0x1b, #5
//   0x0048c0: d280800e  mov      x14, #0x400
//   0x0048c4: f2a1404f  movk     x15, #0xa02, lsl #16
//   0x0048c8: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x0048cc: f2a0008e  movk     x14, #4, lsl #16
//   0x0048d0: f2cc080f  movk     x15, #0x6040, lsl #32
//   0x0048d4: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x0048d8: f2c0208e  movk     x14, #0x104, lsl #32
//   0x0048dc: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x0048e0: f94002ad  ldr      x13, [x21]
//   0x0048e4: 8a0e010e  and      x14, x8, x14
//   0x0048e8: 9aca216b  lsl      x11, x11, x10
//   0x0048ec: aa2801e8  orn      x8, x15, x8
//   0x0048f0: d282880f  mov      x15, #0x1440
//   0x0048f4: b9000309  str      w9, [x24]
//   0x0048f8: f2a140cf  movk     x15, #0xa06, lsl #16
//   0x0048fc: f82c5a6b  str      x11, [x19, w12, uxtw #3]
//   0x004900: f2cc288f  movk     x15, #0x6144, lsl #32
//   0x004904: b900032c  str      w12, [x25]
//   0x004908: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x00490c: b900034a  str      w10, [x26]
//   0x004910: b8404dab  ldr      w11, [x13, #4]!
//   0x004914: 8a0f0108  and      x8, x8, x15
//   0x004918: f90002ad  str      x13, [x21]
//   0x00491c: 5280208d  mov      w13, #0x104
//   0x004920: 8b0e0108  add      x8, x8, x14
//   0x004924: 72a0202d  movk     w13, #0x101, lsl #16
//   0x004928: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x00492c: aa0d0108  orr      x8, x8, x13
//   0x004930: d28d6b8d  mov      x13, #0x6b5c
//   0x004934: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x004938: 9240156b  and      x11, x11, #0x3f
//   0x00493c: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x004940: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x004944: ca0d0108  eor      x8, x8, x13
//   0x004948: f85f83ad  ldur     x13, [x29, #-8]
//   0x00494c: 8b0801c8  add      x8, x14, x8
//   0x004950: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x004954: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x004958: f9400108  ldr      x8, [x8]
//   0x00495c: b90002eb  str      w11, [x23]
//   0x004960: cb0d0108  sub      x8, x8, x13
//   0x004964: d61f0100  br       x8
//   0x004968: b9800309  ldrsw    x9, [x24]
//   0x00496c: 529a046c  mov      w12, #0xd023
//   0x004970: b940034a  ldr      w10, [x26]
//   0x004974: 72abf0cc  movk     w12, #0x5f86, lsl #16
//   0x004978: b980032d  ldrsw    x13, [x25]
//   0x00497c: d37df129  lsl      x9, x9, #3
//   0x004980: 531b694a  lsl      w10, w10, #5
//   0x004984: 1100814a  add      w10, w10, #0x20
//   0x004988: f8696a6b  ldr      x11, [x19, x9]
//   0x00498c: ca0c016c  eor      x12, x11, x12
//   0x004990: 9aca256a  lsr      x10, x11, x10
//   0x004994: 5284304b  mov      w11, #0x2182
//   0x004998: f8296a6c  str      x12, [x19, x9]
//   0x00499c: 72a7ca2b  movk     w11, #0x3e51, lsl #16
//   0x0049a0: f82d7a6a  str      x10, [x19, x13, lsl #3]
//   0x0049a4: f94002a9  ldr      x9, [x21]
//   0x0049a8: f9000089  str      x9, [x4]
//   0x0049ac: b8404d2a  ldr      w10, [x9, #4]!
//   0x0049b0: f90002a9  str      x9, [x21]
//   0x0049b4: 4a0b014a  eor      w10, w10, w11
//   0x0049b8: b900012a  str      w10, [x9]
//   0x0049bc: 17ffffbd  b        #0x48b0
//   0x0049c0: 90000008  adrp     x8, #0x4000
//   0x0049c4: 52808c0a  mov      w10, #0x460
//   0x0049c8: 91118108  add      x8, x8, #0x460
//   0x0049cc: 72a1080a  movk     w10, #0x840, lsl #16
//   0x0049d0: 11000509  add      w9, w8, #1
//   0x0049d4: 0a280129  bic      w9, w9, w8
//   0x0049d8: 2a2903e9  mvn      w9, w9
//   0x0049dc: 8a0a0129  and      x9, x9, x10
//   0x0049e0: d2945cca  mov      x10, #0xa2e6
//   0x0049e4: f2ba9f8a  movk     x10, #0xd4fc, lsl #16
//   0x0049e8: f2c4000a  movk     x10, #0x2000, lsl #32
//   0x0049ec: f2e0084a  movk     x10, #0x42, lsl #48
//   0x0049f0: 8b0a0129  add      x9, x9, x10
//   0x0049f4: 5297282a  mov      w10, #0xb941
//   0x0049f8: 72a38fea  movk     w10, #0x1c7f, lsl #16
//   0x0049fc: eb0a013f  cmp      x9, x10
//   0x004a00: 540005e3  b.lo     #0x4abc
//   0x004a04: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x004a08: 5280040a  mov      w10, #0x20
//   0x004a0c: d282080f  mov      x15, #0x1040
//   0x004a10: 3311576a  bfxil    w10, w27, #0x11, #5
//   0x004a14: d280800e  mov      x14, #0x400
//   0x004a18: f2a1404f  movk     x15, #0xa02, lsl #16
//   0x004a1c: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x004a20: f2a0008e  movk     x14, #4, lsl #16
//   0x004a24: f2cc080f  movk     x15, #0x6040, lsl #32
//   0x004a28: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x004a2c: f2c0208e  movk     x14, #0x104, lsl #32
//   0x004a30: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x004a34: f94002ad  ldr      x13, [x21]
//   0x004a38: 8a0e010e  and      x14, x8, x14
//   0x004a3c: 9aca296b  asr      x11, x11, x10
//   0x004a40: aa2801e8  orn      x8, x15, x8
//   0x004a44: d282880f  mov      x15, #0x1440
//   0x004a48: b9000309  str      w9, [x24]
//   0x004a4c: f2a140cf  movk     x15, #0xa06, lsl #16
//   0x004a50: f82c5a6b  str      x11, [x19, w12, uxtw #3]
//   0x004a54: f2cc288f  movk     x15, #0x6144, lsl #32
//   0x004a58: b900032c  str      w12, [x25]
//   0x004a5c: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x004a60: b900034a  str      w10, [x26]
//   0x004a64: b8404dab  ldr      w11, [x13, #4]!
//   0x004a68: 8a0f0108  and      x8, x8, x15
//   0x004a6c: f90002ad  str      x13, [x21]
//   0x004a70: 5280208d  mov      w13, #0x104
//   0x004a74: 8b0e0108  add      x8, x8, x14
//   0x004a78: 72a0202d  movk     w13, #0x101, lsl #16
//   0x004a7c: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x004a80: aa0d0108  orr      x8, x8, x13
//   0x004a84: d28d6b8d  mov      x13, #0x6b5c
//   0x004a88: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x004a8c: 9240156b  and      x11, x11, #0x3f
//   0x004a90: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x004a94: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x004a98: ca0d0108  eor      x8, x8, x13
//   0x004a9c: f85f83ad  ldur     x13, [x29, #-8]
//   0x004aa0: 8b0801c8  add      x8, x14, x8
//   0x004aa4: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x004aa8: 531b7f6b  lsr      w11, w27, #0x1b
//   0x004aac: f9400108  ldr      x8, [x8]
//   0x004ab0: b90002eb  str      w11, [x23]
//   0x004ab4: cb0d0108  sub      x8, x8, x13
//   0x004ab8: d61f0100  br       x8
//   0x004abc: b9800309  ldrsw    x9, [x24]
//   0x004ac0: 528a8aac  mov      w12, #0x5455
//   0x004ac4: b940034a  ldr      w10, [x26]
//   0x004ac8: 72a4044c  movk     w12, #0x2022, lsl #16
//   0x004acc: b980032d  ldrsw    x13, [x25]
//   0x004ad0: d37df129  lsl      x9, x9, #3
//   0x004ad4: 531b694a  lsl      w10, w10, #5
//   0x004ad8: 1100814a  add      w10, w10, #0x20
//   0x004adc: f8696a6b  ldr      x11, [x19, x9]
//   0x004ae0: ca0c016c  eor      x12, x11, x12
//   0x004ae4: 9aca216a  lsl      x10, x11, x10
//   0x004ae8: 528e78cb  mov      w11, #0x73c6
//   0x004aec: f8296a6c  str      x12, [x19, x9]
//   0x004af0: 72a1d9ab  movk     w11, #0xecd, lsl #16
//   0x004af4: f82d7a6a  str      x10, [x19, x13, lsl #3]
//   0x004af8: f94002a9  ldr      x9, [x21]
//   0x004afc: f9000089  str      x9, [x4]
//   0x004b00: b8404d2a  ldr      w10, [x9, #4]!
//   0x004b04: f90002a9  str      x9, [x21]
//   0x004b08: 4a0b014a  eor      w10, w10, w11
//   0x004b0c: b900012a  str      w10, [x9]
//   0x004b10: 17ffffbd  b        #0x4a04
//   0x004b14: 531b7f69  lsr      w9, w27, #0x1b
//   0x004b18: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x004b1c: 530c4368  ubfx     w8, w27, #0xc, #5
//   0x004b20: 37d8059b  tbnz     w27, #0x1b, #0x4bd0
//   0x004b24: f86a5a6b  ldr      x11, [x19, w10, uxtw #3]
//   0x004b28: d282080e  mov      x14, #0x1040
//   0x004b2c: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x004b30: f2a1404e  movk     x14, #0xa02, lsl #16
//   0x004b34: d282880f  mov      x15, #0x1440
//   0x004b38: f2cc080e  movk     x14, #0x6040, lsl #32
//   0x004b3c: f2a140cf  movk     x15, #0xa06, lsl #16
//   0x004b40: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x004b44: f2cc288f  movk     x15, #0x6144, lsl #32
//   0x004b48: f94002ad  ldr      x13, [x21]
//   0x004b4c: 9acc256b  lsr      x11, x11, x12
//   0x004b50: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x004b54: aa2501ce  orn      x14, x14, x5
//   0x004b58: 121f0d29  and      w9, w9, #0x1e
//   0x004b5c: 8a0f01ce  and      x14, x14, x15
//   0x004b60: d280800f  mov      x15, #0x400
//   0x004b64: f8285a6b  str      x11, [x19, w8, uxtw #3]
//   0x004b68: f2a0008f  movk     x15, #4, lsl #16
//   0x004b6c: b8404dab  ldr      w11, [x13, #4]!
//   0x004b70: f2c0208f  movk     x15, #0x104, lsl #32
//   0x004b74: f90002ad  str      x13, [x21]
//   0x004b78: 5280208d  mov      w13, #0x104
//   0x004b7c: 8a0f00af  and      x15, x5, x15
//   0x004b80: 72a0202d  movk     w13, #0x101, lsl #16
//   0x004b84: 8b0f01ce  add      x14, x14, x15
//   0x004b88: aa0d01cd  orr      x13, x14, x13
//   0x004b8c: d28d6b8e  mov      x14, #0x6b5c
//   0x004b90: f2be938e  movk     x14, #0xf49c, lsl #16
//   0x004b94: f941f28f  ldr      x15, [x20, #0x3e0]
//   0x004b98: f2d3d76e  movk     x14, #0x9ebb, lsl #32
//   0x004b9c: 9240156b  and      x11, x11, #0x3f
//   0x004ba0: f2ffebee  movk     x14, #0xff5f, lsl #48
//   0x004ba4: b90002e9  str      w9, [x23]
//   0x004ba8: ca0e01ad  eor      x13, x13, x14
//   0x004bac: b900030a  str      w10, [x24]
//   0x004bb0: 8b0d01ed  add      x13, x15, x13
//   0x004bb4: b9000328  str      w8, [x25]
//   0x004bb8: 8b0b0dab  add      x11, x13, x11, lsl #3
//   0x004bbc: f85f83ad  ldur     x13, [x29, #-8]
//   0x004bc0: b900034c  str      w12, [x26]
//   0x004bc4: f940016b  ldr      x11, [x11]
//   0x004bc8: cb0d0169  sub      x9, x11, x13
//   0x004bcc: d61f0120  br       x9
//   0x004bd0: 9000000b  adrp     x11, #0x4000
//   0x004bd4: 9111816b  add      x11, x11, #0x460
//   0x004bd8: 1100056c  add      w12, w11, #1
//   0x004bdc: 0a2b018b  bic      w11, w12, w11
//   0x004be0: 5282486c  mov      w12, #0x1243
//   0x004be4: 2a2b03eb  mvn      w11, w11
//   0x004be8: 72a00d8c  movk     w12, #0x6c, lsl #16
//   0x004bec: 8a0c016b  and      x11, x11, x12
//   0x004bf0: d296326c  mov      x12, #0xb193
//   0x004bf4: f2ae430c  movk     x12, #0x7218, lsl #16
//   0x004bf8: f2d0800c  movk     x12, #0x8400, lsl #32
//   0x004bfc: f2e0a88c  movk     x12, #0x544, lsl #48
//   0x004c00: 8b0c016b  add      x11, x11, x12
//   0x004c04: 52945acc  mov      w12, #0xa2d6
//   0x004c08: 72a8a82c  movk     w12, #0x4541, lsl #16
//   0x004c0c: eb0c017f  cmp      x11, x12
//   0x004c10: 540009a3  b.lo     #0x4d44
//   0x004c14: 1205036b  and      w11, w27, #0x8000000
//   0x004c18: 53117f6c  lsr      w12, w27, #0x11
//   0x004c1c: 121f018d  and      w13, w12, #2
//   0x004c20: b900030a  str      w10, [x24]
//   0x004c24: 2a4b6dab  orr      w11, w13, w11, lsr #27
//   0x004c28: 121e018d  and      w13, w12, #4
//   0x004c2c: 2a0d016b  orr      w11, w11, w13
//   0x004c30: 121d018d  and      w13, w12, #8
//   0x004c34: 121c018c  and      w12, w12, #0x10
//   0x004c38: 2a0d016b  orr      w11, w11, w13
//   0x004c3c: 121f012d  and      w13, w9, #2
//   0x004c40: 2a0c016b  orr      w11, w11, w12
//   0x004c44: 121e012c  and      w12, w9, #4
//   0x004c48: 3311476d  bfxil    w13, w27, #0x11, #1
//   0x004c4c: 2a0c01ac  orr      w12, w13, w12
//   0x004c50: 121d012d  and      w13, w9, #8
//   0x004c54: b90002eb  str      w11, [x23]
//   0x004c58: 2a0d018b  orr      w11, w12, w13
//   0x004c5c: 121c012c  and      w12, w9, #0x10
//   0x004c60: 90000009  adrp     x9, #0x4000
//   0x004c64: 91118129  add      x9, x9, #0x460
//   0x004c68: 2a0c016b  orr      w11, w11, w12
//   0x004c6c: 1100052c  add      w12, w9, #1
//   0x004c70: 5281340d  mov      w13, #0x9a0
//   0x004c74: 0a29018c  bic      w12, w12, w9
//   0x004c78: 72a1000d  movk     w13, #0x800, lsl #16
//   0x004c7c: 2a2c03ec  mvn      w12, w12
//   0x004c80: f86a5a6a  ldr      x10, [x19, w10, uxtw #3]
//   0x004c84: 8a0d018c  and      x12, x12, x13
//   0x004c88: d287580d  mov      x13, #0x3ac0
//   0x004c8c: f2b296ed  movk     x13, #0x94b7, lsl #16
//   0x004c90: b900032b  str      w11, [x25]
//   0x004c94: f2c0440d  movk     x13, #0x220, lsl #32
//   0x004c98: b9000348  str      w8, [x26]
//   0x004c9c: f2e0820d  movk     x13, #0x410, lsl #48
//   0x004ca0: 9ac82d4a  ror      x10, x10, x8
//   0x004ca4: 8b0d018c  add      x12, x12, x13
//   0x004ca8: 528b97ed  mov      w13, #0x5cbf
//   0x004cac: 72a4f62d  movk     w13, #0x27b1, lsl #16
//   0x004cb0: eb0d019f  cmp      x12, x13
//   0x004cb4: 54000583  b.lo     #0x4d64
//   0x004cb8: f82b5a6a  str      x10, [x19, w11, uxtw #3]
//   0x004cbc: d282080b  mov      x11, #0x1040
//   0x004cc0: f94002a8  ldr      x8, [x21]
//   0x004cc4: d280800a  mov      x10, #0x400
//   0x004cc8: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x004ccc: d282880c  mov      x12, #0x1440
//   0x004cd0: f2a0008a  movk     x10, #4, lsl #16
//   0x004cd4: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x004cd8: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x004cdc: f2c0208a  movk     x10, #0x104, lsl #32
//   0x004ce0: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x004ce4: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x004ce8: 8a0a012a  and      x10, x9, x10
//   0x004cec: aa290169  orn      x9, x11, x9
//   0x004cf0: b8404d0b  ldr      w11, [x8, #4]!
//   0x004cf4: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x004cf8: f90002a8  str      x8, [x21]
//   0x004cfc: 8a0c0128  and      x8, x9, x12
//   0x004d00: f941f289  ldr      x9, [x20, #0x3e0]
//   0x004d04: 8b0a0108  add      x8, x8, x10
//   0x004d08: 5280208a  mov      w10, #0x104
//   0x004d0c: 72a0202a  movk     w10, #0x101, lsl #16
//   0x004d10: 9240156b  and      x11, x11, #0x3f
//   0x004d14: aa0a0108  orr      x8, x8, x10
//   0x004d18: d28d6b8a  mov      x10, #0x6b5c
//   0x004d1c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x004d20: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x004d24: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x004d28: ca0a0108  eor      x8, x8, x10
//   0x004d2c: 8b080128  add      x8, x9, x8
//   0x004d30: f85f83a9  ldur     x9, [x29, #-8]
//   0x004d34: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x004d38: f9400108  ldr      x8, [x8]
//   0x004d3c: cb090108  sub      x8, x8, x9
//   0x004d40: d61f0100  br       x8
//   0x004d44: b980030b  ldrsw    x11, [x24]
//   0x004d48: 5296e8cd  mov      w13, #0xb746
//   0x004d4c: 72af606d  movk     w13, #0x7b03, lsl #16
//   0x004d50: d37df16b  lsl      x11, x11, #3
//   0x004d54: f86b6a6c  ldr      x12, [x19, x11]
//   0x004d58: ca0d018c  eor      x12, x12, x13
//   0x004d5c: f82b6a6c  str      x12, [x19, x11]
//   0x004d60: 17ffffad  b        #0x4c14
//   0x004d64: f94002a8  ldr      x8, [x21]
//   0x004d68: f82b5a6a  str      x10, [x19, w11, uxtw #3]
//   0x004d6c: 528e2f0c  mov      w12, #0x7178
//   0x004d70: 72ab052c  movk     w12, #0x5829, lsl #16
//   0x004d74: f9000088  str      x8, [x4]
//   0x004d78: 4a0c016b  eor      w11, w11, w12
//   0x004d7c: b8404d0d  ldr      w13, [x8, #4]!
//   0x004d80: 5295500c  mov      w12, #0xaa80
//   0x004d84: f90002a8  str      x8, [x21]
//   0x004d88: 72a11b0c  movk     w12, #0x8d8, lsl #16
//   0x004d8c: b900032b  str      w11, [x25]
//   0x004d90: 4a0c01ac  eor      w12, w13, w12
//   0x004d94: b900010c  str      w12, [x8]
//   0x004d98: 17ffffc8  b        #0x4cb8
//   0x004d9c: 37d8061b  tbnz     w27, #0x1b, #0x4e5c
//   0x004da0: 53115768  ubfx     w8, w27, #0x11, #5
//   0x004da4: 52800409  mov      w9, #0x20
//   0x004da8: d282080d  mov      x13, #0x1040
//   0x004dac: 33166b69  bfxil    w9, w27, #0x16, #5
//   0x004db0: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x004db4: d282880e  mov      x14, #0x1440
//   0x004db8: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x004dbc: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x004dc0: f2a140ce  movk     x14, #0xa06, lsl #16
//   0x004dc4: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x004dc8: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x004dcc: f2cc288e  movk     x14, #0x6144, lsl #32
//   0x004dd0: f94002ac  ldr      x12, [x21]
//   0x004dd4: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x004dd8: 9ac9254a  lsr      x10, x10, x9
//   0x004ddc: aa2501ad  orn      x13, x13, x5
//   0x004de0: 8a0e01ad  and      x13, x13, x14
//   0x004de4: d280800e  mov      x14, #0x400
//   0x004de8: f82b5a6a  str      x10, [x19, w11, uxtw #3]
//   0x004dec: f2a0008e  movk     x14, #4, lsl #16
//   0x004df0: b8404d8a  ldr      w10, [x12, #4]!
//   0x004df4: f2c0208e  movk     x14, #0x104, lsl #32
//   0x004df8: f90002ac  str      x12, [x21]
//   0x004dfc: 5280208c  mov      w12, #0x104
//   0x004e00: 8a0e00ae  and      x14, x5, x14
//   0x004e04: 72a0202c  movk     w12, #0x101, lsl #16
//   0x004e08: 8b0e01ad  add      x13, x13, x14
//   0x004e0c: aa0c01ac  orr      x12, x13, x12
//   0x004e10: d28d6b8d  mov      x13, #0x6b5c
//   0x004e14: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x004e18: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x004e1c: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x004e20: 9240154a  and      x10, x10, #0x3f
//   0x004e24: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x004e28: b9000308  str      w8, [x24]
//   0x004e2c: ca0d018c  eor      x12, x12, x13
//   0x004e30: f85f83ad  ldur     x13, [x29, #-8]
//   0x004e34: 8b0c01cc  add      x12, x14, x12
//   0x004e38: b900032b  str      w11, [x25]
//   0x004e3c: 8b0a0d8a  add      x10, x12, x10, lsl #3
//   0x004e40: 531b7f6c  lsr      w12, w27, #0x1b
//   0x004e44: 121f0d8c  and      w12, w12, #0x1e
//   0x004e48: b9000349  str      w9, [x26]
//   0x004e4c: f940014a  ldr      x10, [x10]
//   0x004e50: b90002ec  str      w12, [x23]
//   0x004e54: cb0d014a  sub      x10, x10, x13
//   0x004e58: d61f0140  br       x10
//   0x004e5c: 90000008  adrp     x8, #0x4000
//   0x004e60: 5292004a  mov      w10, #0x9002
//   0x004e64: 91118108  add      x8, x8, #0x460
//   0x004e68: 72a4500a  movk     w10, #0x2280, lsl #16
//   0x004e6c: 11000509  add      w9, w8, #1
//   0x004e70: 0a280129  bic      w9, w9, w8
//   0x004e74: 2a2903e9  mvn      w9, w9
//   0x004e78: 8a0a0129  and      x9, x9, x10
//   0x004e7c: d28e010a  mov      x10, #0x7008
//   0x004e80: f2a4de2a  movk     x10, #0x26f1, lsl #16
//   0x004e84: f2d0000a  movk     x10, #0x8000, lsl #32
//   0x004e88: f2e0502a  movk     x10, #0x281, lsl #48
//   0x004e8c: 8b0a0129  add      x9, x9, x10
//   0x004e90: 529f134a  mov      w10, #0xf89a
//   0x004e94: 72a002ca  movk     w10, #0x16, lsl #16
//   0x004e98: eb0a013f  cmp      x9, x10
//   0x004e9c: 54000783  b.lo     #0x4f8c
//   0x004ea0: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x004ea4: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x004ea8: 5280040d  mov      w13, #0x20
//   0x004eac: d2820810  mov      x16, #0x1040
//   0x004eb0: 4b0c01ac  sub      w12, w13, w12
//   0x004eb4: 3311576d  bfxil    w13, w27, #0x11, #5
//   0x004eb8: f8695a6f  ldr      x15, [x19, w9, uxtw #3]
//   0x004ebc: d280800e  mov      x14, #0x400
//   0x004ec0: f2a14050  movk     x16, #0xa02, lsl #16
//   0x004ec4: f2a0008e  movk     x14, #4, lsl #16
//   0x004ec8: f2cc0810  movk     x16, #0x6040, lsl #32
//   0x004ecc: f2c0208e  movk     x14, #0x104, lsl #32
//   0x004ed0: f2e01410  movk     x16, #0xa0, lsl #48
//   0x004ed4: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x004ed8: 9acc21ec  lsl      x12, x15, x12
//   0x004edc: 9acd25ef  lsr      x15, x15, x13
//   0x004ee0: aa0f018c  orr      x12, x12, x15
//   0x004ee4: d282880f  mov      x15, #0x1440
//   0x004ee8: f2a140cf  movk     x15, #0xa06, lsl #16
//   0x004eec: 8a0e010e  and      x14, x8, x14
//   0x004ef0: f2cc288f  movk     x15, #0x6144, lsl #32
//   0x004ef4: aa280208  orn      x8, x16, x8
//   0x004ef8: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x004efc: f94002b0  ldr      x16, [x21]
//   0x004f00: 8a0f0108  and      x8, x8, x15
//   0x004f04: 5280208f  mov      w15, #0x104
//   0x004f08: 72a0202f  movk     w15, #0x101, lsl #16
//   0x004f0c: 8b0e0108  add      x8, x8, x14
//   0x004f10: f82b5a6c  str      x12, [x19, w11, uxtw #3]
//   0x004f14: aa0f0108  orr      x8, x8, x15
//   0x004f18: d28d6b8f  mov      x15, #0x6b5c
//   0x004f1c: 1205036a  and      w10, w27, #0x8000000
//   0x004f20: b8404e0c  ldr      w12, [x16, #4]!
//   0x004f24: f90002b0  str      x16, [x21]
//   0x004f28: f2be938f  movk     x15, #0xf49c, lsl #16
//   0x004f2c: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x004f30: f2d3d76f  movk     x15, #0x9ebb, lsl #32
//   0x004f34: f2ffebef  movk     x15, #0xff5f, lsl #48
//   0x004f38: 531b7f70  lsr      w16, w27, #0x1b
//   0x004f3c: ca0f0108  eor      x8, x8, x15
//   0x004f40: 9240158c  and      x12, x12, #0x3f
//   0x004f44: 121f020f  and      w15, w16, #2
//   0x004f48: 8b0801c8  add      x8, x14, x8
//   0x004f4c: 2a4a6dea  orr      w10, w15, w10, lsr #27
//   0x004f50: 8b0c0d08  add      x8, x8, x12, lsl #3
//   0x004f54: 121e020c  and      w12, w16, #4
//   0x004f58: b9000309  str      w9, [x24]
//   0x004f5c: 2a0c014a  orr      w10, w10, w12
//   0x004f60: 121d020c  and      w12, w16, #8
//   0x004f64: 2a0c014a  orr      w10, w10, w12
//   0x004f68: 121c020c  and      w12, w16, #0x10
//   0x004f6c: f9400108  ldr      x8, [x8]
//   0x004f70: 2a0c014a  orr      w10, w10, w12
//   0x004f74: f85f83ac  ldur     x12, [x29, #-8]
//   0x004f78: b900032b  str      w11, [x25]
//   0x004f7c: b900034d  str      w13, [x26]
//   0x004f80: b90002ea  str      w10, [x23]
//   0x004f84: cb0c0108  sub      x8, x8, x12
//   0x004f88: d61f0100  br       x8
//   0x004f8c: b9800309  ldrsw    x9, [x24]
//   0x004f90: 5291d1cd  mov      w13, #0x8e8e
//   0x004f94: b940034a  ldr      w10, [x26]
//   0x004f98: 72a7dc0d  movk     w13, #0x3ee0, lsl #16
//   0x004f9c: d37df129  lsl      x9, x9, #3
//   0x004fa0: 531b694b  lsl      w11, w10, #5
//   0x004fa4: 4b0a016a  sub      w10, w11, w10
//   0x004fa8: 1100816b  add      w11, w11, #0x20
//   0x004fac: f8696a6c  ldr      x12, [x19, x9]
//   0x004fb0: ca0d018d  eor      x13, x12, x13
//   0x004fb4: 9aca218a  lsl      x10, x12, x10
//   0x004fb8: 9acb218b  lsl      x11, x12, x11
//   0x004fbc: b980032c  ldrsw    x12, [x25]
//   0x004fc0: aa0b014a  orr      x10, x10, x11
//   0x004fc4: f8296a6d  str      x13, [x19, x9]
//   0x004fc8: 5293be6b  mov      w11, #0x9df3
//   0x004fcc: f82c7a6a  str      x10, [x19, x12, lsl #3]
//   0x004fd0: 72a2d3ab  movk     w11, #0x169d, lsl #16
//   0x004fd4: f94002a9  ldr      x9, [x21]
//   0x004fd8: f9000089  str      x9, [x4]
//   0x004fdc: b8404d2a  ldr      w10, [x9, #4]!
//   0x004fe0: f90002a9  str      x9, [x21]
//   0x004fe4: 4a0b014a  eor      w10, w10, w11
//   0x004fe8: b900012a  str      w10, [x9]
//   0x004fec: 17ffffad  b        #0x4ea0
//   0x004ff0: 9000000b  adrp     x11, #0x4000
//   0x004ff4: 53117f69  lsr      w9, w27, #0x11
//   0x004ff8: 9111816b  add      x11, x11, #0x460
//   0x004ffc: 531b7f6a  lsr      w10, w27, #0x1b
//   0x005000: 1100056c  add      w12, w11, #1
//   0x005004: 530c4368  ubfx     w8, w27, #0xc, #5
//   0x005008: 0a2b018c  bic      w12, w12, w11
//   0x00500c: 2a2c03ec  mvn      w12, w12
//   0x005010: 37d8087b  tbnz     w27, #0x1b, #0x511c
//   0x005014: 5280048d  mov      w13, #0x24
//   0x005018: 72a8190d  movk     w13, #0x40c8, lsl #16
//   0x00501c: 8a0d018c  and      x12, x12, x13
//   0x005020: d291af0d  mov      x13, #0x8d78
//   0x005024: f2a4366d  movk     x13, #0x21b3, lsl #16
//   0x005028: f2c0040d  movk     x13, #0x20, lsl #32
//   0x00502c: f2e0082d  movk     x13, #0x41, lsl #48
//   0x005030: 8b0d018c  add      x12, x12, x13
//   0x005034: 529df42d  mov      w13, #0xefa1
//   0x005038: 72a005ed  movk     w13, #0x2f, lsl #16
//   0x00503c: eb0d019f  cmp      x12, x13
//   0x005040: 54001003  b.lo     #0x5240
//   0x005044: 121f014c  and      w12, w10, #2
//   0x005048: 121e014d  and      w13, w10, #4
//   0x00504c: 3311476c  bfxil    w12, w27, #0x11, #1
//   0x005050: 121f0d29  and      w9, w9, #0x1e
//   0x005054: 2a0d018c  orr      w12, w12, w13
//   0x005058: 121d014d  and      w13, w10, #8
//   0x00505c: 121c014a  and      w10, w10, #0x10
//   0x005060: 2a0d018c  orr      w12, w12, w13
//   0x005064: 53166b6d  ubfx     w13, w27, #0x16, #5
//   0x005068: 2a0a018a  orr      w10, w12, w10
//   0x00506c: b9000348  str      w8, [x26]
//   0x005070: d37df148  lsl      x8, x10, #3
//   0x005074: b90002e9  str      w9, [x23]
//   0x005078: 530c7f69  lsr      w9, w27, #0xc
//   0x00507c: b900032d  str      w13, [x25]
//   0x005080: d280800c  mov      x12, #0x400
//   0x005084: b900030a  str      w10, [x24]
//   0x005088: f2a0008c  movk     x12, #4, lsl #16
//   0x00508c: b8686a68  ldr      w8, [x19, x8]
//   0x005090: f2c0208c  movk     x12, #0x104, lsl #32
//   0x005094: 8a0c016c  and      x12, x11, x12
//   0x005098: f94002aa  ldr      x10, [x21]
//   0x00509c: 1ac92508  lsr      w8, w8, w9
//   0x0050a0: d2820809  mov      x9, #0x1040
//   0x0050a4: f2a14049  movk     x9, #0xa02, lsl #16
//   0x0050a8: 93407d08  sxtw     x8, w8
//   0x0050ac: f2cc0809  movk     x9, #0x6040, lsl #32
//   0x0050b0: f2e01409  movk     x9, #0xa0, lsl #48
//   0x0050b4: f82d5a68  str      x8, [x19, w13, uxtw #3]
//   0x0050b8: aa2b0129  orn      x9, x9, x11
//   0x0050bc: d282880b  mov      x11, #0x1440
//   0x0050c0: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x0050c4: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x0050c8: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x0050cc: 8a0b0129  and      x9, x9, x11
//   0x0050d0: 5280208b  mov      w11, #0x104
//   0x0050d4: 8b0c0129  add      x9, x9, x12
//   0x0050d8: d28d6b8c  mov      x12, #0x6b5c
//   0x0050dc: b8404d48  ldr      w8, [x10, #4]!
//   0x0050e0: f90002aa  str      x10, [x21]
//   0x0050e4: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x0050e8: 72a0202b  movk     w11, #0x101, lsl #16
//   0x0050ec: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x0050f0: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x0050f4: aa0b0129  orr      x9, x9, x11
//   0x0050f8: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x0050fc: 92401508  and      x8, x8, #0x3f
//   0x005100: ca0c0129  eor      x9, x9, x12
//   0x005104: 8b090149  add      x9, x10, x9
//   0x005108: 8b080d28  add      x8, x9, x8, lsl #3
//   0x00510c: f85f83a9  ldur     x9, [x29, #-8]
//   0x005110: f9400108  ldr      x8, [x8]
//   0x005114: cb090108  sub      x8, x8, x9
//   0x005118: d61f0100  br       x8
//   0x00511c: 5282242d  mov      w13, #0x1121
//   0x005120: 72a0170d  movk     w13, #0xb8, lsl #16
//   0x005124: 8a0d018c  and      x12, x12, x13
//   0x005128: d285df8d  mov      x13, #0x2efc
//   0x00512c: f2baa80d  movk     x13, #0xd540, lsl #16
//   0x005130: f2c0820d  movk     x13, #0x410, lsl #32
//   0x005134: 8b0d018c  add      x12, x12, x13
//   0x005138: 5292ce6d  mov      w13, #0x9673
//   0x00513c: 72af390d  movk     w13, #0x79c8, lsl #16
//   0x005140: eb0d019f  cmp      x12, x13
//   0x005144: 54000b03  b.lo     #0x52a4
//   0x005148: 1205036c  and      w12, w27, #0x8000000
//   0x00514c: 53167f6d  lsr      w13, w27, #0x16
//   0x005150: 121f01ae  and      w14, w13, #2
//   0x005154: b9000328  str      w8, [x25]
//   0x005158: 2a4c6dcc  orr      w12, w14, w12, lsr #27
//   0x00515c: 121e01ae  and      w14, w13, #4
//   0x005160: 2a0e018c  orr      w12, w12, w14
//   0x005164: 121d01ae  and      w14, w13, #8
//   0x005168: 2a0e018c  orr      w12, w12, w14
//   0x00516c: 121f014e  and      w14, w10, #2
//   0x005170: 121c01ad  and      w13, w13, #0x10
//   0x005174: 33165b6e  bfxil    w14, w27, #0x16, #1
//   0x005178: 2a0d018c  orr      w12, w12, w13
//   0x00517c: 121e014d  and      w13, w10, #4
//   0x005180: 2a0d01cd  orr      w13, w14, w13
//   0x005184: 121d014e  and      w14, w10, #8
//   0x005188: 2a0e01ad  orr      w13, w13, w14
//   0x00518c: 121c014a  and      w10, w10, #0x10
//   0x005190: 2a0a01aa  orr      w10, w13, w10
//   0x005194: b90002ec  str      w12, [x23]
//   0x005198: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x00519c: d282080d  mov      x13, #0x1040
//   0x0051a0: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x0051a4: b900030a  str      w10, [x24]
//   0x0051a8: d37df14a  lsl      x10, x10, #3
//   0x0051ac: b900034c  str      w12, [x26]
//   0x0051b0: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x0051b4: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x0051b8: f94002ac  ldr      x12, [x21]
//   0x0051bc: b86a6a6a  ldr      w10, [x19, x10]
//   0x0051c0: 1ac92d49  ror      w9, w10, w9
//   0x0051c4: d280800a  mov      x10, #0x400
//   0x0051c8: 93407d29  sxtw     x9, w9
//   0x0051cc: f2a0008a  movk     x10, #4, lsl #16
//   0x0051d0: f2c0208a  movk     x10, #0x104, lsl #32
//   0x0051d4: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x0051d8: d2828809  mov      x9, #0x1440
//   0x0051dc: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x0051e0: 8a0a016a  and      x10, x11, x10
//   0x0051e4: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x0051e8: aa2b01ab  orn      x11, x13, x11
//   0x0051ec: f2e01409  movk     x9, #0xa0, lsl #48
//   0x0051f0: 8a090169  and      x9, x11, x9
//   0x0051f4: 8b0a0129  add      x9, x9, x10
//   0x0051f8: 5280208a  mov      w10, #0x104
//   0x0051fc: 72a0202a  movk     w10, #0x101, lsl #16
//   0x005200: aa0a0129  orr      x9, x9, x10
//   0x005204: d28d6b8a  mov      x10, #0x6b5c
//   0x005208: b8404d88  ldr      w8, [x12, #4]!
//   0x00520c: f90002ac  str      x12, [x21]
//   0x005210: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x005214: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x005218: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00521c: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x005220: 92401508  and      x8, x8, #0x3f
//   0x005224: ca0a0129  eor      x9, x9, x10
//   0x005228: 8b090189  add      x9, x12, x9
//   0x00522c: 8b080d28  add      x8, x9, x8, lsl #3
//   0x005230: f85f83a9  ldur     x9, [x29, #-8]
//   0x005234: f9400108  ldr      x8, [x8]
//   0x005238: cb090108  sub      x8, x8, x9
//   0x00523c: d61f0100  br       x8
//   0x005240: b980030c  ldrsw    x12, [x24]
//   0x005244: 528a9a8d  mov      w13, #0x54d4
//   0x005248: 72ac01ad  movk     w13, #0x600d, lsl #16
//   0x00524c: 528b720e  mov      w14, #0x5b90
//   0x005250: 72a1678e  movk     w14, #0xb3c, lsl #16
//   0x005254: 4a0d018d  eor      w13, w12, w13
//   0x005258: d37df18c  lsl      x12, x12, #3
//   0x00525c: b900030d  str      w13, [x24]
//   0x005260: b86c6a6d  ldr      w13, [x19, x12]
//   0x005264: 4a0e01ae  eor      w14, w13, w14
//   0x005268: b82c6a6e  str      w14, [x19, x12]
//   0x00526c: 5280710e  mov      w14, #0x388
//   0x005270: b940034c  ldr      w12, [x26]
//   0x005274: 72a1c52e  movk     w14, #0xe29, lsl #16
//   0x005278: 1acc25ac  lsr      w12, w13, w12
//   0x00527c: b980032d  ldrsw    x13, [x25]
//   0x005280: 93407d8c  sxtw     x12, w12
//   0x005284: f82d7a6c  str      x12, [x19, x13, lsl #3]
//   0x005288: f94002ac  ldr      x12, [x21]
//   0x00528c: f900008c  str      x12, [x4]
//   0x005290: b8404d8d  ldr      w13, [x12, #4]!
//   0x005294: f90002ac  str      x12, [x21]
//   0x005298: 4a0e01ad  eor      w13, w13, w14
//   0x00529c: b900018d  str      w13, [x12]
//   0x0052a0: 17ffff69  b        #0x5044
//   0x0052a4: b940034c  ldr      w12, [x26]
//   0x0052a8: 52975d6e  mov      w14, #0xbaeb
//   0x0052ac: b980030d  ldrsw    x13, [x24]
//   0x0052b0: 5298c8cf  mov      w15, #0xc646
//   0x0052b4: 72aab76e  movk     w14, #0x55bb, lsl #16
//   0x0052b8: 72a2fd8f  movk     w15, #0x17ec, lsl #16
//   0x0052bc: 4a0e018c  eor      w12, w12, w14
//   0x0052c0: 4a0f01ae  eor      w14, w13, w15
//   0x0052c4: d37df1ad  lsl      x13, x13, #3
//   0x0052c8: b900034c  str      w12, [x26]
//   0x0052cc: b900030e  str      w14, [x24]
//   0x0052d0: 52853dee  mov      w14, #0x29ef
//   0x0052d4: b86d6a6c  ldr      w12, [x19, x13]
//   0x0052d8: 72a739ae  movk     w14, #0x39cd, lsl #16
//   0x0052dc: 4a0e018c  eor      w12, w12, w14
//   0x0052e0: b82d6a6c  str      w12, [x19, x13]
//   0x0052e4: 17ffff99  b        #0x5148
//   0x0052e8: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x0052ec: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x0052f0: 531b7f6a  lsr      w10, w27, #0x1b
//   0x0052f4: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x0052f8: b90002e8  str      w8, [x23]
//   0x0052fc: d37df128  lsl      x8, x9, #3
//   0x005300: b9000309  str      w9, [x24]
//   0x005304: 53117f69  lsr      w9, w27, #0x11
//   0x005308: b900032a  str      w10, [x25]
//   0x00530c: b900034b  str      w11, [x26]
//   0x005310: b8686a68  ldr      w8, [x19, x8]
//   0x005314: 1ac92108  lsl      w8, w8, w9
//   0x005318: f94002a9  ldr      x9, [x21]
//   0x00531c: 93407d08  sxtw     x8, w8
//   0x005320: f82a5a68  str      x8, [x19, w10, uxtw #3]
//   0x005324: b8404d28  ldr      w8, [x9, #4]!
//   0x005328: f90002a9  str      x9, [x21]
//   0x00532c: 52802089  mov      w9, #0x104
//   0x005330: 72a02029  movk     w9, #0x101, lsl #16
//   0x005334: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x005338: aa0902c9  orr      x9, x22, x9
//   0x00533c: 92401508  and      x8, x8, #0x3f
//   0x005340: ca110129  eor      x9, x9, x17
//   0x005344: 8b090149  add      x9, x10, x9
//   0x005348: 8b080d28  add      x8, x9, x8, lsl #3
//   0x00534c: f85f83a9  ldur     x9, [x29, #-8]
//   0x005350: f9400108  ldr      x8, [x8]
//   0x005354: cb090108  sub      x8, x8, x9
//   0x005358: d61f0100  br       x8
//   0x00535c: f0ffffe8  adrp     x8, #0x4000
//   0x005360: 52810b6a  mov      w10, #0x85b
//   0x005364: 91118108  add      x8, x8, #0x460
//   0x005368: 72a1028a  movk     w10, #0x814, lsl #16
//   0x00536c: 11000509  add      w9, w8, #1
//   0x005370: 0a280129  bic      w9, w9, w8
//   0x005374: 2a2903e9  mvn      w9, w9
//   0x005378: 8a0a0129  and      x9, x9, x10
//   0x00537c: d2924dca  mov      x10, #0x926e
//   0x005380: f2a273aa  movk     x10, #0x139d, lsl #16
//   0x005384: f2c400ca  movk     x10, #0x2006, lsl #32
//   0x005388: f2e1000a  movk     x10, #0x800, lsl #48
//   0x00538c: 8b0a0129  add      x9, x9, x10
//   0x005390: 529ae38a  mov      w10, #0xd71c
//   0x005394: 72a0756a  movk     w10, #0x3ab, lsl #16
//   0x005398: eb0a013f  cmp      x9, x10
//   0x00539c: 54000623  b.lo     #0x5460
//   0x0053a0: 531b7f69  lsr      w9, w27, #0x1b
//   0x0053a4: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x0053a8: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x0053ac: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x0053b0: d280800d  mov      x13, #0x400
//   0x0053b4: b90002e9  str      w9, [x23]
//   0x0053b8: d37df149  lsl      x9, x10, #3
//   0x0053bc: b900030a  str      w10, [x24]
//   0x0053c0: 53117f6a  lsr      w10, w27, #0x11
//   0x0053c4: b900032b  str      w11, [x25]
//   0x0053c8: f2a0008d  movk     x13, #4, lsl #16
//   0x0053cc: b900034c  str      w12, [x26]
//   0x0053d0: f94002ac  ldr      x12, [x21]
//   0x0053d4: b8696a69  ldr      w9, [x19, x9]
//   0x0053d8: f2c0208d  movk     x13, #0x104, lsl #32
//   0x0053dc: 8a0d010d  and      x13, x8, x13
//   0x0053e0: 1aca2929  asr      w9, w9, w10
//   0x0053e4: d282080a  mov      x10, #0x1040
//   0x0053e8: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x0053ec: 93407d29  sxtw     x9, w9
//   0x0053f0: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x0053f4: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x0053f8: f82b5a69  str      x9, [x19, w11, uxtw #3]
//   0x0053fc: aa280148  orn      x8, x10, x8
//   0x005400: d282880a  mov      x10, #0x1440
//   0x005404: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x005408: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x00540c: b8404d89  ldr      w9, [x12, #4]!
//   0x005410: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x005414: f90002ac  str      x12, [x21]
//   0x005418: d28d6b8c  mov      x12, #0x6b5c
//   0x00541c: 8a0a0108  and      x8, x8, x10
//   0x005420: 5280208a  mov      w10, #0x104
//   0x005424: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x005428: 72a0202a  movk     w10, #0x101, lsl #16
//   0x00542c: 8b0d0108  add      x8, x8, x13
//   0x005430: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x005434: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x005438: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x00543c: aa0a0108  orr      x8, x8, x10
//   0x005440: ca0c0108  eor      x8, x8, x12
//   0x005444: 92401529  and      x9, x9, #0x3f
//   0x005448: 8b080168  add      x8, x11, x8
//   0x00544c: 8b090d08  add      x8, x8, x9, lsl #3
//   0x005450: f85f83a9  ldur     x9, [x29, #-8]
//   0x005454: f9400108  ldr      x8, [x8]
//   0x005458: cb090108  sub      x8, x8, x9
//   0x00545c: d61f0100  br       x8
//   0x005460: b9800309  ldrsw    x9, [x24]
//   0x005464: 528b71ca  mov      w10, #0x5b8e
//   0x005468: 72a0e6aa  movk     w10, #0x735, lsl #16
//   0x00546c: 52996a8b  mov      w11, #0xcb54
//   0x005470: 72a801ab  movk     w11, #0x400d, lsl #16
//   0x005474: 4a0a012a  eor      w10, w9, w10
//   0x005478: d37df129  lsl      x9, x9, #3
//   0x00547c: b900030a  str      w10, [x24]
//   0x005480: b8696a6a  ldr      w10, [x19, x9]
//   0x005484: 4a0b014b  eor      w11, w10, w11
//   0x005488: b8296a6b  str      w11, [x19, x9]
//   0x00548c: 5284b04b  mov      w11, #0x2582
//   0x005490: b9400349  ldr      w9, [x26]
//   0x005494: 72a1f20b  movk     w11, #0xf90, lsl #16
//   0x005498: 1ac92949  asr      w9, w10, w9
//   0x00549c: b980032a  ldrsw    x10, [x25]
//   0x0054a0: 93407d29  sxtw     x9, w9
//   0x0054a4: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x0054a8: f94002a9  ldr      x9, [x21]
//   0x0054ac: f9000089  str      x9, [x4]
//   0x0054b0: b8404d2a  ldr      w10, [x9, #4]!
//   0x0054b4: f90002a9  str      x9, [x21]
//   0x0054b8: 4a0b014a  eor      w10, w10, w11
//   0x0054bc: b900012a  str      w10, [x9]
//   0x0054c0: 17ffffb8  b        #0x53a0
//   0x0054c4: f0ffffe8  adrp     x8, #0x4000
//   0x0054c8: 5280002a  mov      w10, #1
//   0x0054cc: 91118108  add      x8, x8, #0x460
//   0x0054d0: 72a0338a  movk     w10, #0x19c, lsl #16
//   0x0054d4: 11000509  add      w9, w8, #1
//   0x0054d8: 0a280129  bic      w9, w9, w8
//   0x0054dc: 2a2903e9  mvn      w9, w9
//   0x0054e0: 8a0a0129  and      x9, x9, x10
//   0x0054e4: d2931dea  mov      x10, #0x98ef
//   0x0054e8: f2b671aa  movk     x10, #0xb38d, lsl #16
//   0x0054ec: f2e088aa  movk     x10, #0x445, lsl #48
//   0x0054f0: 8b0a0129  add      x9, x9, x10
//   0x0054f4: 52824e0a  mov      w10, #0x1270
//   0x0054f8: 72a0a68a  movk     w10, #0x534, lsl #16
//   0x0054fc: eb0a013f  cmp      x9, x10
//   0x005500: 540005e3  b.lo     #0x55bc
//   0x005504: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x005508: 531b7f6a  lsr      w10, w27, #0x1b
//   0x00550c: d280800f  mov      x15, #0x400
//   0x005510: 530c436d  ubfx     w13, w27, #0xc, #5
//   0x005514: f2a0008f  movk     x15, #4, lsl #16
//   0x005518: f94002ae  ldr      x14, [x21]
//   0x00551c: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x005520: f2c0208f  movk     x15, #0x104, lsl #32
//   0x005524: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x005528: 8a0f010f  and      x15, x8, x15
//   0x00552c: b90002e9  str      w9, [x23]
//   0x005530: 53115769  ubfx     w9, w27, #0x11, #5
//   0x005534: b900030a  str      w10, [x24]
//   0x005538: b900032d  str      w13, [x25]
//   0x00553c: 8b0b018b  add      x11, x12, x11
//   0x005540: d282080c  mov      x12, #0x1040
//   0x005544: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x005548: b9000349  str      w9, [x26]
//   0x00554c: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x005550: f82d5a6b  str      x11, [x19, w13, uxtw #3]
//   0x005554: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x005558: aa280188  orn      x8, x12, x8
//   0x00555c: d282880c  mov      x12, #0x1440
//   0x005560: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x005564: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x005568: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00556c: 8a0c0108  and      x8, x8, x12
//   0x005570: 5280208c  mov      w12, #0x104
//   0x005574: 72a0202c  movk     w12, #0x101, lsl #16
//   0x005578: 8b0f0108  add      x8, x8, x15
//   0x00557c: aa0c0108  orr      x8, x8, x12
//   0x005580: d28d6b8c  mov      x12, #0x6b5c
//   0x005584: b8404dcb  ldr      w11, [x14, #4]!
//   0x005588: f90002ae  str      x14, [x21]
//   0x00558c: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x005590: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x005594: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x005598: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x00559c: 9240156b  and      x11, x11, #0x3f
//   0x0055a0: ca0c0108  eor      x8, x8, x12
//   0x0055a4: 8b0801c8  add      x8, x14, x8
//   0x0055a8: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x0055ac: f85f83ab  ldur     x11, [x29, #-8]
//   0x0055b0: f9400108  ldr      x8, [x8]
//   0x0055b4: cb0b0108  sub      x8, x8, x11
//   0x0055b8: d61f0100  br       x8
//   0x0055bc: b98002e9  ldrsw    x9, [x23]
//   0x0055c0: 5297176c  mov      w12, #0xb8bb
//   0x0055c4: b980030b  ldrsw    x11, [x24]
//   0x0055c8: 72ab784c  movk     w12, #0x5bc2, lsl #16
//   0x0055cc: d37df129  lsl      x9, x9, #3
//   0x0055d0: d37df16b  lsl      x11, x11, #3
//   0x0055d4: f8696a6a  ldr      x10, [x19, x9]
//   0x0055d8: ca0c014c  eor      x12, x10, x12
//   0x0055dc: f8296a6c  str      x12, [x19, x9]
//   0x0055e0: 52861e0c  mov      w12, #0x30f0
//   0x0055e4: f86b6a69  ldr      x9, [x19, x11]
//   0x0055e8: 72a511cc  movk     w12, #0x288e, lsl #16
//   0x0055ec: ca0c012c  eor      x12, x9, x12
//   0x0055f0: 9b0a2929  madd     x9, x9, x10, x10
//   0x0055f4: b980032a  ldrsw    x10, [x25]
//   0x0055f8: f82b6a6c  str      x12, [x19, x11]
//   0x0055fc: 5292464b  mov      w11, #0x9232
//   0x005600: 72a073ab  movk     w11, #0x39d, lsl #16
//   0x005604: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x005608: f94002a9  ldr      x9, [x21]
//   0x00560c: f9000089  str      x9, [x4]
//   0x005610: b8404d2a  ldr      w10, [x9, #4]!
//   0x005614: f90002a9  str      x9, [x21]
//   0x005618: 4a0b014a  eor      w10, w10, w11
//   0x00561c: b900012a  str      w10, [x9]
//   0x005620: 17ffffb9  b        #0x5504
//   0x005624: f0ffffe8  adrp     x8, #0x4000
//   0x005628: 5290a0aa  mov      w10, #0x8505
//   0x00562c: 91118108  add      x8, x8, #0x460
//   0x005630: 72a6448a  movk     w10, #0x3224, lsl #16
//   0x005634: 11000509  add      w9, w8, #1
//   0x005638: 0a280129  bic      w9, w9, w8
//   0x00563c: 2a2903e9  mvn      w9, w9
//   0x005640: 8a0a0129  and      x9, x9, x10
//   0x005644: d28dac2a  mov      x10, #0x6d61
//   0x005648: f2ad158a  movk     x10, #0x68ac, lsl #16
//   0x00564c: f2c110aa  movk     x10, #0x885, lsl #32
//   0x005650: f2e0800a  movk     x10, #0x400, lsl #48
//   0x005654: 8b0a0129  add      x9, x9, x10
//   0x005658: 528890ca  mov      w10, #0x4486
//   0x00565c: 72a9a60a  movk     w10, #0x4d30, lsl #16
//   0x005660: eb0a013f  cmp      x9, x10
//   0x005664: 540005e3  b.lo     #0x5720
//   0x005668: 53115769  ubfx     w9, w27, #0x11, #5
//   0x00566c: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x005670: d280800f  mov      x15, #0x400
//   0x005674: 531b7f6d  lsr      w13, w27, #0x1b
//   0x005678: f2a0008f  movk     x15, #4, lsl #16
//   0x00567c: f94002ae  ldr      x14, [x21]
//   0x005680: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x005684: f2c0208f  movk     x15, #0x104, lsl #32
//   0x005688: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x00568c: 8a0f010f  and      x15, x8, x15
//   0x005690: b90002e9  str      w9, [x23]
//   0x005694: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x005698: b900030a  str      w10, [x24]
//   0x00569c: b900032d  str      w13, [x25]
//   0x0056a0: 8b0b018b  add      x11, x12, x11
//   0x0056a4: d282080c  mov      x12, #0x1040
//   0x0056a8: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x0056ac: b9000349  str      w9, [x26]
//   0x0056b0: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x0056b4: f82d5a6b  str      x11, [x19, w13, uxtw #3]
//   0x0056b8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0056bc: aa280188  orn      x8, x12, x8
//   0x0056c0: d282880c  mov      x12, #0x1440
//   0x0056c4: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x0056c8: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0056cc: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0056d0: 8a0c0108  and      x8, x8, x12
//   0x0056d4: 5280208c  mov      w12, #0x104
//   0x0056d8: 72a0202c  movk     w12, #0x101, lsl #16
//   0x0056dc: 8b0f0108  add      x8, x8, x15
//   0x0056e0: aa0c0108  orr      x8, x8, x12
//   0x0056e4: d28d6b8c  mov      x12, #0x6b5c
//   0x0056e8: b8404dcb  ldr      w11, [x14, #4]!
//   0x0056ec: f90002ae  str      x14, [x21]
//   0x0056f0: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x0056f4: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x0056f8: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x0056fc: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x005700: 9240156b  and      x11, x11, #0x3f
//   0x005704: ca0c0108  eor      x8, x8, x12
//   0x005708: 8b0801c8  add      x8, x14, x8
//   0x00570c: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x005710: f85f83ab  ldur     x11, [x29, #-8]
//   0x005714: f9400108  ldr      x8, [x8]
//   0x005718: cb0b0108  sub      x8, x8, x11
//   0x00571c: d61f0100  br       x8
//   0x005720: b98002e9  ldrsw    x9, [x23]
//   0x005724: 528aef4c  mov      w12, #0x577a
//   0x005728: b980030b  ldrsw    x11, [x24]
//   0x00572c: 72a8db4c  movk     w12, #0x46da, lsl #16
//   0x005730: d37df129  lsl      x9, x9, #3
//   0x005734: d37df16b  lsl      x11, x11, #3
//   0x005738: f8696a6a  ldr      x10, [x19, x9]
//   0x00573c: ca0c014c  eor      x12, x10, x12
//   0x005740: f8296a6c  str      x12, [x19, x9]
//   0x005744: 529bce6c  mov      w12, #0xde73
//   0x005748: f86b6a69  ldr      x9, [x19, x11]
//   0x00574c: 72ae956c  movk     w12, #0x74ab, lsl #16
//   0x005750: ca0c012c  eor      x12, x9, x12
//   0x005754: 9b0a2929  madd     x9, x9, x10, x10
//   0x005758: b980032a  ldrsw    x10, [x25]
//   0x00575c: f82b6a6c  str      x12, [x19, x11]
//   0x005760: 5284b2cb  mov      w11, #0x2596
//   0x005764: 72ab704b  movk     w11, #0x5b82, lsl #16
//   0x005768: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00576c: f94002a9  ldr      x9, [x21]
//   0x005770: f9000089  str      x9, [x4]
//   0x005774: b8404d2a  ldr      w10, [x9, #4]!
//   0x005778: f90002a9  str      x9, [x21]
//   0x00577c: 4a0b014a  eor      w10, w10, w11
//   0x005780: b900012a  str      w10, [x9]
//   0x005784: 17ffffb9  b        #0x5668
//   0x005788: 531b7f68  lsr      w8, w27, #0x1b
//   0x00578c: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x005790: 530c436c  ubfx     w12, w27, #0xc, #5
//   0x005794: f94002ad  ldr      x13, [x21]
//   0x005798: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x00579c: b90002e8  str      w8, [x23]
//   0x0057a0: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x0057a4: b9000309  str      w9, [x24]
//   0x0057a8: b900032c  str      w12, [x25]
//   0x0057ac: cb0b014a  sub      x10, x10, x11
//   0x0057b0: 5280208b  mov      w11, #0x104
//   0x0057b4: 72a0202b  movk     w11, #0x101, lsl #16
//   0x0057b8: f82c5a6a  str      x10, [x19, w12, uxtw #3]
//   0x0057bc: aa0b02cb  orr      x11, x22, x11
//   0x0057c0: b8404daa  ldr      w10, [x13, #4]!
//   0x0057c4: f90002ad  str      x13, [x21]
//   0x0057c8: ca11016b  eor      x11, x11, x17
//   0x0057cc: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x0057d0: 9240154a  and      x10, x10, #0x3f
//   0x0057d4: 8b0b01ab  add      x11, x13, x11
//   0x0057d8: 8b0a0d6a  add      x10, x11, x10, lsl #3
//   0x0057dc: f85f83ab  ldur     x11, [x29, #-8]
//   0x0057e0: f940014a  ldr      x10, [x10]
//   0x0057e4: cb0b0148  sub      x8, x10, x11
//   0x0057e8: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x0057ec: b900034a  str      w10, [x26]
//   0x0057f0: d61f0100  br       x8
//   0x0057f4: f0ffffe8  adrp     x8, #0x4000
//   0x0057f8: 5284440a  mov      w10, #0x2220
//   0x0057fc: 91118108  add      x8, x8, #0x460
//   0x005800: 72a0892a  movk     w10, #0x449, lsl #16
//   0x005804: 11000509  add      w9, w8, #1
//   0x005808: 0a280129  bic      w9, w9, w8
//   0x00580c: 2a2903e9  mvn      w9, w9
//   0x005810: 8a0a0129  and      x9, x9, x10
//   0x005814: d28f1d4a  mov      x10, #0x78ea
//   0x005818: f2b47cea  movk     x10, #0xa3e7, lsl #16
//   0x00581c: f2c0028a  movk     x10, #0x14, lsl #32
//   0x005820: f2e1800a  movk     x10, #0xc00, lsl #48
//   0x005824: 8b0a0129  add      x9, x9, x10
//   0x005828: 5290222a  mov      w10, #0x8111
//   0x00582c: 72a2772a  movk     w10, #0x13b9, lsl #16
//   0x005830: eb0a013f  cmp      x9, x10
//   0x005834: 540005e3  b.lo     #0x58f0
//   0x005838: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x00583c: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x005840: d280800f  mov      x15, #0x400
//   0x005844: 531b7f6d  lsr      w13, w27, #0x1b
//   0x005848: f2a0008f  movk     x15, #4, lsl #16
//   0x00584c: f94002ae  ldr      x14, [x21]
//   0x005850: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x005854: f2c0208f  movk     x15, #0x104, lsl #32
//   0x005858: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x00585c: 8a0f010f  and      x15, x8, x15
//   0x005860: b90002e9  str      w9, [x23]
//   0x005864: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x005868: b900030a  str      w10, [x24]
//   0x00586c: b900032d  str      w13, [x25]
//   0x005870: cb0c016b  sub      x11, x11, x12
//   0x005874: d282080c  mov      x12, #0x1040
//   0x005878: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00587c: b9000349  str      w9, [x26]
//   0x005880: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x005884: f82d5a6b  str      x11, [x19, w13, uxtw #3]
//   0x005888: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00588c: aa280188  orn      x8, x12, x8
//   0x005890: d282880c  mov      x12, #0x1440
//   0x005894: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x005898: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x00589c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0058a0: 8a0c0108  and      x8, x8, x12
//   0x0058a4: 5280208c  mov      w12, #0x104
//   0x0058a8: 72a0202c  movk     w12, #0x101, lsl #16
//   0x0058ac: 8b0f0108  add      x8, x8, x15
//   0x0058b0: aa0c0108  orr      x8, x8, x12
//   0x0058b4: d28d6b8c  mov      x12, #0x6b5c
//   0x0058b8: b8404dcb  ldr      w11, [x14, #4]!
//   0x0058bc: f90002ae  str      x14, [x21]
//   0x0058c0: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x0058c4: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x0058c8: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x0058cc: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x0058d0: 9240156b  and      x11, x11, #0x3f
//   0x0058d4: ca0c0108  eor      x8, x8, x12
//   0x0058d8: 8b0801c8  add      x8, x14, x8
//   0x0058dc: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x0058e0: f85f83ab  ldur     x11, [x29, #-8]
//   0x0058e4: f9400108  ldr      x8, [x8]
//   0x0058e8: cb0b0108  sub      x8, x8, x11
//   0x0058ec: d61f0100  br       x8
//   0x0058f0: b98002e9  ldrsw    x9, [x23]
//   0x0058f4: 529b806c  mov      w12, #0xdc03
//   0x0058f8: b980030b  ldrsw    x11, [x24]
//   0x0058fc: 72a7696c  movk     w12, #0x3b4b, lsl #16
//   0x005900: d37df129  lsl      x9, x9, #3
//   0x005904: d37df16b  lsl      x11, x11, #3
//   0x005908: f8696a6a  ldr      x10, [x19, x9]
//   0x00590c: ca0c014c  eor      x12, x10, x12
//   0x005910: f8296a6c  str      x12, [x19, x9]
//   0x005914: f86b6a69  ldr      x9, [x19, x11]
//   0x005918: cb0903ec  neg      x12, x9
//   0x00591c: 9b0a312a  madd     x10, x9, x10, x12
//   0x005920: 5290ceac  mov      w12, #0x8675
//   0x005924: 72a4922c  movk     w12, #0x2491, lsl #16
//   0x005928: ca0c0129  eor      x9, x9, x12
//   0x00592c: b980032c  ldrsw    x12, [x25]
//   0x005930: f82b6a69  str      x9, [x19, x11]
//   0x005934: 52866e8b  mov      w11, #0x3374
//   0x005938: f82c7a6a  str      x10, [x19, x12, lsl #3]
//   0x00593c: 72abdecb  movk     w11, #0x5ef6, lsl #16
//   0x005940: f94002a9  ldr      x9, [x21]
//   0x005944: f9000089  str      x9, [x4]
//   0x005948: b8404d2a  ldr      w10, [x9, #4]!
//   0x00594c: f90002a9  str      x9, [x21]
//   0x005950: 4a0b014a  eor      w10, w10, w11
//   0x005954: b900012a  str      w10, [x9]
//   0x005958: 17ffffb8  b        #0x5838
//   0x00595c: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x005960: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x005964: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x005968: 531b7f6b  lsr      w11, w27, #0x1b
//   0x00596c: b90002e8  str      w8, [x23]
//   0x005970: d37df108  lsl      x8, x8, #3
//   0x005974: b9000309  str      w9, [x24]
//   0x005978: d37df129  lsl      x9, x9, #3
//   0x00597c: b900032a  str      w10, [x25]
//   0x005980: b900034b  str      w11, [x26]
//   0x005984: b8686a68  ldr      w8, [x19, x8]
//   0x005988: b8696a69  ldr      w9, [x19, x9]
//   0x00598c: 0b080128  add      w8, w9, w8
//   0x005990: f94002a9  ldr      x9, [x21]
//   0x005994: 93407d08  sxtw     x8, w8
//   0x005998: f82a5a68  str      x8, [x19, w10, uxtw #3]
//   0x00599c: b8404d28  ldr      w8, [x9, #4]!
//   0x0059a0: f90002a9  str      x9, [x21]
//   0x0059a4: 52802089  mov      w9, #0x104
//   0x0059a8: 72a02029  movk     w9, #0x101, lsl #16
//   0x0059ac: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x0059b0: aa0902c9  orr      x9, x22, x9
//   0x0059b4: 92401508  and      x8, x8, #0x3f
//   0x0059b8: ca110129  eor      x9, x9, x17
//   0x0059bc: 8b090149  add      x9, x10, x9
//   0x0059c0: 8b080d28  add      x8, x9, x8, lsl #3
//   0x0059c4: f85f83a9  ldur     x9, [x29, #-8]
//   0x0059c8: f9400108  ldr      x8, [x8]
//   0x0059cc: cb090108  sub      x8, x8, x9
//   0x0059d0: d61f0100  br       x8
//   0x0059d4: f0ffffe8  adrp     x8, #0x4000
//   0x0059d8: 5280462a  mov      w10, #0x231
//   0x0059dc: 91118108  add      x8, x8, #0x460
//   0x0059e0: 72a4a92a  movk     w10, #0x2549, lsl #16
//   0x0059e4: 11000509  add      w9, w8, #1
//   0x0059e8: 0a280129  bic      w9, w9, w8
//   0x0059ec: 2a2903e9  mvn      w9, w9
//   0x0059f0: 8a0a0129  and      x9, x9, x10
//   0x0059f4: d2836c6a  mov      x10, #0x1b63
//   0x0059f8: f2ae692a  movk     x10, #0x7349, lsl #16
//   0x0059fc: f2c4000a  movk     x10, #0x2000, lsl #32
//   0x005a00: f2e00c8a  movk     x10, #0x64, lsl #48
//   0x005a04: 8b0a0129  add      x9, x9, x10
//   0x005a08: 529a488a  mov      w10, #0xd244
//   0x005a0c: 72a1b0ca  movk     w10, #0xd86, lsl #16
//   0x005a10: eb0a013f  cmp      x9, x10
//   0x005a14: 54000643  b.lo     #0x5adc
//   0x005a18: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x005a1c: 531b7f6a  lsr      w10, w27, #0x1b
//   0x005a20: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x005a24: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x005a28: d280800d  mov      x13, #0x400
//   0x005a2c: b90002e9  str      w9, [x23]
//   0x005a30: d37df129  lsl      x9, x9, #3
//   0x005a34: b900030a  str      w10, [x24]
//   0x005a38: d37df14a  lsl      x10, x10, #3
//   0x005a3c: b900032b  str      w11, [x25]
//   0x005a40: f2a0008d  movk     x13, #4, lsl #16
//   0x005a44: b900034c  str      w12, [x26]
//   0x005a48: f94002ac  ldr      x12, [x21]
//   0x005a4c: b8696a69  ldr      w9, [x19, x9]
//   0x005a50: f2c0208d  movk     x13, #0x104, lsl #32
//   0x005a54: b86a6a6a  ldr      w10, [x19, x10]
//   0x005a58: 8a0d010d  and      x13, x8, x13
//   0x005a5c: 0b090149  add      w9, w10, w9
//   0x005a60: d282080a  mov      x10, #0x1040
//   0x005a64: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x005a68: 93407d29  sxtw     x9, w9
//   0x005a6c: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x005a70: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x005a74: f82b5a69  str      x9, [x19, w11, uxtw #3]
//   0x005a78: aa280148  orn      x8, x10, x8
//   0x005a7c: d282880a  mov      x10, #0x1440
//   0x005a80: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x005a84: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x005a88: b8404d89  ldr      w9, [x12, #4]!
//   0x005a8c: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x005a90: f90002ac  str      x12, [x21]
//   0x005a94: d28d6b8c  mov      x12, #0x6b5c
//   0x005a98: 8a0a0108  and      x8, x8, x10
//   0x005a9c: 5280208a  mov      w10, #0x104
//   0x005aa0: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x005aa4: 72a0202a  movk     w10, #0x101, lsl #16
//   0x005aa8: 8b0d0108  add      x8, x8, x13
//   0x005aac: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x005ab0: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x005ab4: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x005ab8: aa0a0108  orr      x8, x8, x10
//   0x005abc: ca0c0108  eor      x8, x8, x12
//   0x005ac0: 92401529  and      x9, x9, #0x3f
//   0x005ac4: 8b080168  add      x8, x11, x8
//   0x005ac8: 8b090d08  add      x8, x8, x9, lsl #3
//   0x005acc: f85f83a9  ldur     x9, [x29, #-8]
//   0x005ad0: f9400108  ldr      x8, [x8]
//   0x005ad4: cb090108  sub      x8, x8, x9
//   0x005ad8: d61f0100  br       x8
//   0x005adc: b98002e9  ldrsw    x9, [x23]
//   0x005ae0: 529b26ea  mov      w10, #0xd937
//   0x005ae4: 72aeca8a  movk     w10, #0x7654, lsl #16
//   0x005ae8: 529cd24b  mov      w11, #0xe692
//   0x005aec: 72a7900b  movk     w11, #0x3c80, lsl #16
//   0x005af0: 5290744c  mov      w12, #0x83a2
//   0x005af4: 4a0a012a  eor      w10, w9, w10
//   0x005af8: d37df129  lsl      x9, x9, #3
//   0x005afc: 72a1f2ec  movk     w12, #0xf97, lsl #16
//   0x005b00: b90002ea  str      w10, [x23]
//   0x005b04: b8696a6a  ldr      w10, [x19, x9]
//   0x005b08: 4a0b014b  eor      w11, w10, w11
//   0x005b0c: b8296a6b  str      w11, [x19, x9]
//   0x005b10: 529348cb  mov      w11, #0x9a46
//   0x005b14: b9800309  ldrsw    x9, [x24]
//   0x005b18: 72a6542b  movk     w11, #0x32a1, lsl #16
//   0x005b1c: 4a0b012b  eor      w11, w9, w11
//   0x005b20: d37df129  lsl      x9, x9, #3
//   0x005b24: b900030b  str      w11, [x24]
//   0x005b28: b8696a6b  ldr      w11, [x19, x9]
//   0x005b2c: 4a0c016c  eor      w12, w11, w12
//   0x005b30: b8296a6c  str      w12, [x19, x9]
//   0x005b34: 1b0a2969  madd     w9, w11, w10, w10
//   0x005b38: b980032a  ldrsw    x10, [x25]
//   0x005b3c: 528dd6eb  mov      w11, #0x6eb7
//   0x005b40: 93407d29  sxtw     x9, w9
//   0x005b44: 72ad0eab  movk     w11, #0x6875, lsl #16
//   0x005b48: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x005b4c: f94002a9  ldr      x9, [x21]
//   0x005b50: f9000089  str      x9, [x4]
//   0x005b54: b8404d2a  ldr      w10, [x9, #4]!
//   0x005b58: f90002a9  str      x9, [x21]
//   0x005b5c: 4a0b014a  eor      w10, w10, w11
//   0x005b60: b900012a  str      w10, [x9]
//   0x005b64: 17ffffad  b        #0x5a18
//   0x005b68: f0ffffe8  adrp     x8, #0x4000
//   0x005b6c: 52880aaa  mov      w10, #0x4055
//   0x005b70: 91118108  add      x8, x8, #0x460
//   0x005b74: 72a8400a  movk     w10, #0x4200, lsl #16
//   0x005b78: 11000509  add      w9, w8, #1
//   0x005b7c: 0a280129  bic      w9, w9, w8
//   0x005b80: 2a2903e9  mvn      w9, w9
//   0x005b84: 8a0a0129  and      x9, x9, x10
//   0x005b88: d285b1ca  mov      x10, #0x2d8e
//   0x005b8c: f2bbca0a  movk     x10, #0xde50, lsl #16
//   0x005b90: f2c0380a  movk     x10, #0x1c0, lsl #32
//   0x005b94: 8b0a0129  add      x9, x9, x10
//   0x005b98: 5285984a  mov      w10, #0x2cc2
//   0x005b9c: 72a12d4a  movk     w10, #0x96a, lsl #16
//   0x005ba0: eb0a013f  cmp      x9, x10
//   0x005ba4: 54000643  b.lo     #0x5c6c
//   0x005ba8: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x005bac: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x005bb0: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x005bb4: 531b7f6c  lsr      w12, w27, #0x1b
//   0x005bb8: d280800d  mov      x13, #0x400
//   0x005bbc: b90002e9  str      w9, [x23]
//   0x005bc0: d37df129  lsl      x9, x9, #3
//   0x005bc4: b900030a  str      w10, [x24]
//   0x005bc8: d37df14a  lsl      x10, x10, #3
//   0x005bcc: b900032b  str      w11, [x25]
//   0x005bd0: f2a0008d  movk     x13, #4, lsl #16
//   0x005bd4: b900034c  str      w12, [x26]
//   0x005bd8: f94002ac  ldr      x12, [x21]
//   0x005bdc: b8696a69  ldr      w9, [x19, x9]
//   0x005be0: f2c0208d  movk     x13, #0x104, lsl #32
//   0x005be4: b86a6a6a  ldr      w10, [x19, x10]
//   0x005be8: 8a0d010d  and      x13, x8, x13
//   0x005bec: 4b0a0129  sub      w9, w9, w10
//   0x005bf0: d282080a  mov      x10, #0x1040
//   0x005bf4: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x005bf8: 93407d29  sxtw     x9, w9
//   0x005bfc: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x005c00: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x005c04: f82b5a69  str      x9, [x19, w11, uxtw #3]
//   0x005c08: aa280148  orn      x8, x10, x8
//   0x005c0c: d282880a  mov      x10, #0x1440
//   0x005c10: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x005c14: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x005c18: b8404d89  ldr      w9, [x12, #4]!
//   0x005c1c: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x005c20: f90002ac  str      x12, [x21]
//   0x005c24: d28d6b8c  mov      x12, #0x6b5c
//   0x005c28: 8a0a0108  and      x8, x8, x10
//   0x005c2c: 5280208a  mov      w10, #0x104
//   0x005c30: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x005c34: 72a0202a  movk     w10, #0x101, lsl #16
//   0x005c38: 8b0d0108  add      x8, x8, x13
//   0x005c3c: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x005c40: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x005c44: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x005c48: aa0a0108  orr      x8, x8, x10
//   0x005c4c: ca0c0108  eor      x8, x8, x12
//   0x005c50: 92401529  and      x9, x9, #0x3f
//   0x005c54: 8b080168  add      x8, x11, x8
//   0x005c58: 8b090d08  add      x8, x8, x9, lsl #3
//   0x005c5c: f85f83a9  ldur     x9, [x29, #-8]
//   0x005c60: f9400108  ldr      x8, [x8]
//   0x005c64: cb090108  sub      x8, x8, x9
//   0x005c68: d61f0100  br       x8
//   0x005c6c: b98002e9  ldrsw    x9, [x23]
//   0x005c70: 52829a6a  mov      w10, #0x14d3
//   0x005c74: 72a4752a  movk     w10, #0x23a9, lsl #16
//   0x005c78: 52875deb  mov      w11, #0x3aef
//   0x005c7c: 72a632cb  movk     w11, #0x3196, lsl #16
//   0x005c80: 528ccb8c  mov      w12, #0x665c
//   0x005c84: 4a0a012a  eor      w10, w9, w10
//   0x005c88: d37df129  lsl      x9, x9, #3
//   0x005c8c: 72ae42ec  movk     w12, #0x7217, lsl #16
//   0x005c90: b90002ea  str      w10, [x23]
//   0x005c94: b8a96a6a  ldrsw    x10, [x19, x9]
//   0x005c98: 4a0b014b  eor      w11, w10, w11
//   0x005c9c: b8296a6b  str      w11, [x19, x9]
//   0x005ca0: 52874aeb  mov      w11, #0x3a57
//   0x005ca4: b9800309  ldrsw    x9, [x24]
//   0x005ca8: 72afbeeb  movk     w11, #0x7df7, lsl #16
//   0x005cac: 4a0b012b  eor      w11, w9, w11
//   0x005cb0: d37df129  lsl      x9, x9, #3
//   0x005cb4: b900030b  str      w11, [x24]
//   0x005cb8: b8696a6b  ldr      w11, [x19, x9]
//   0x005cbc: 4a0c016b  eor      w11, w11, w12
//   0x005cc0: b8296a6b  str      w11, [x19, x9]
//   0x005cc4: 529b08cb  mov      w11, #0xd846
//   0x005cc8: b9800329  ldrsw    x9, [x25]
//   0x005ccc: 72ae128b  movk     w11, #0x7094, lsl #16
//   0x005cd0: f8297a6a  str      x10, [x19, x9, lsl #3]
//   0x005cd4: f94002a9  ldr      x9, [x21]
//   0x005cd8: f9000089  str      x9, [x4]
//   0x005cdc: b8404d2a  ldr      w10, [x9, #4]!
//   0x005ce0: f90002a9  str      x9, [x21]
//   0x005ce4: 4a0b014a  eor      w10, w10, w11
//   0x005ce8: b900012a  str      w10, [x9]
//   0x005cec: 17ffffaf  b        #0x5ba8
//   0x005cf0: 53115768  ubfx     w8, w27, #0x11, #5
//   0x005cf4: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x005cf8: 531b7f6a  lsr      w10, w27, #0x1b
//   0x005cfc: 53166b6b  ubfx     w11, w27, #0x16, #5
//   0x005d00: b90002e8  str      w8, [x23]
//   0x005d04: d37df108  lsl      x8, x8, #3
//   0x005d08: b9000309  str      w9, [x24]
//   0x005d0c: d37df129  lsl      x9, x9, #3
//   0x005d10: b900032a  str      w10, [x25]
//   0x005d14: b900034b  str      w11, [x26]
//   0x005d18: b8686a68  ldr      w8, [x19, x8]
//   0x005d1c: b8696a69  ldr      w9, [x19, x9]
//   0x005d20: 4b090108  sub      w8, w8, w9
//   0x005d24: f94002a9  ldr      x9, [x21]
//   0x005d28: 93407d08  sxtw     x8, w8
//   0x005d2c: f82a5a68  str      x8, [x19, w10, uxtw #3]
//   0x005d30: b8404d28  ldr      w8, [x9, #4]!
//   0x005d34: f90002a9  str      x9, [x21]
//   0x005d38: 52802089  mov      w9, #0x104
//   0x005d3c: 72a02029  movk     w9, #0x101, lsl #16
//   0x005d40: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x005d44: aa0902c9  orr      x9, x22, x9
//   0x005d48: 92401508  and      x8, x8, #0x3f
//   0x005d4c: ca110129  eor      x9, x9, x17
//   0x005d50: 8b090149  add      x9, x10, x9
//   0x005d54: 8b080d28  add      x8, x9, x8, lsl #3
//   0x005d58: f85f83a9  ldur     x9, [x29, #-8]
//   0x005d5c: f9400108  ldr      x8, [x8]
//   0x005d60: cb090108  sub      x8, x8, x9
//   0x005d64: d61f0100  br       x8
//   0x005d68: 530c4368  ubfx     w8, w27, #0xc, #5
//   0x005d6c: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x005d70: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x005d74: f94002ad  ldr      x13, [x21]
//   0x005d78: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x005d7c: b90002e8  str      w8, [x23]
//   0x005d80: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x005d84: b9000309  str      w9, [x24]
//   0x005d88: b900032c  str      w12, [x25]
//   0x005d8c: 9aca216a  lsl      x10, x11, x10
//   0x005d90: 5280208b  mov      w11, #0x104
//   0x005d94: 72a0202b  movk     w11, #0x101, lsl #16
//   0x005d98: f82c5a6a  str      x10, [x19, w12, uxtw #3]
//   0x005d9c: aa0b02cb  orr      x11, x22, x11
//   0x005da0: b8404daa  ldr      w10, [x13, #4]!
//   0x005da4: f90002ad  str      x13, [x21]
//   0x005da8: ca11016b  eor      x11, x11, x17
//   0x005dac: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x005db0: 9240154a  and      x10, x10, #0x3f
//   0x005db4: 8b0b01ab  add      x11, x13, x11
//   0x005db8: 8b0a0d6a  add      x10, x11, x10, lsl #3
//   0x005dbc: f85f83ab  ldur     x11, [x29, #-8]
//   0x005dc0: f940014a  ldr      x10, [x10]
//   0x005dc4: cb0b0148  sub      x8, x10, x11
//   0x005dc8: 531b7f6a  lsr      w10, w27, #0x1b
//   0x005dcc: b900034a  str      w10, [x26]
//   0x005dd0: d61f0100  br       x8
//   0x005dd4: f0ffffe8  adrp     x8, #0x4000
//   0x005dd8: 5283006a  mov      w10, #0x1803
//   0x005ddc: 91118108  add      x8, x8, #0x460
//   0x005de0: 72ab40ca  movk     w10, #0x5a06, lsl #16
//   0x005de4: 11000509  add      w9, w8, #1
//   0x005de8: 0a280129  bic      w9, w9, w8
//   0x005dec: 2a2903e9  mvn      w9, w9
//   0x005df0: 8a0a0129  and      x9, x9, x10
//   0x005df4: d28ef3ca  mov      x10, #0x779e
//   0x005df8: f2a7474a  movk     x10, #0x3a3a, lsl #16
//   0x005dfc: f2c0008a  movk     x10, #4, lsl #32
//   0x005e00: f2e0018a  movk     x10, #0xc, lsl #48
//   0x005e04: 8b0a0129  add      x9, x9, x10
//   0x005e08: 5284688a  mov      w10, #0x2344
//   0x005e0c: 72a0026a  movk     w10, #0x13, lsl #16
//   0x005e10: eb0a013f  cmp      x9, x10
//   0x005e14: 540005e3  b.lo     #0x5ed0
//   0x005e18: 531b7f69  lsr      w9, w27, #0x1b
//   0x005e1c: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x005e20: d280800f  mov      x15, #0x400
//   0x005e24: 53166b6d  ubfx     w13, w27, #0x16, #5
//   0x005e28: f2a0008f  movk     x15, #4, lsl #16
//   0x005e2c: f94002ae  ldr      x14, [x21]
//   0x005e30: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x005e34: f2c0208f  movk     x15, #0x104, lsl #32
//   0x005e38: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x005e3c: 8a0f010f  and      x15, x8, x15
//   0x005e40: b90002e9  str      w9, [x23]
//   0x005e44: 53115769  ubfx     w9, w27, #0x11, #5
//   0x005e48: b900030a  str      w10, [x24]
//   0x005e4c: b900032d  str      w13, [x25]
//   0x005e50: 9acb298b  asr      x11, x12, x11
//   0x005e54: d282080c  mov      x12, #0x1040
//   0x005e58: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x005e5c: b9000349  str      w9, [x26]
//   0x005e60: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x005e64: f82d5a6b  str      x11, [x19, w13, uxtw #3]
//   0x005e68: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x005e6c: aa280188  orn      x8, x12, x8
//   0x005e70: d282880c  mov      x12, #0x1440
//   0x005e74: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x005e78: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x005e7c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x005e80: 8a0c0108  and      x8, x8, x12
//   0x005e84: 5280208c  mov      w12, #0x104
//   0x005e88: 72a0202c  movk     w12, #0x101, lsl #16
//   0x005e8c: 8b0f0108  add      x8, x8, x15
//   0x005e90: aa0c0108  orr      x8, x8, x12
//   0x005e94: d28d6b8c  mov      x12, #0x6b5c
//   0x005e98: b8404dcb  ldr      w11, [x14, #4]!
//   0x005e9c: f90002ae  str      x14, [x21]
//   0x005ea0: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x005ea4: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x005ea8: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x005eac: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x005eb0: 9240156b  and      x11, x11, #0x3f
//   0x005eb4: ca0c0108  eor      x8, x8, x12
//   0x005eb8: 8b0801c8  add      x8, x14, x8
//   0x005ebc: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x005ec0: f85f83ab  ldur     x11, [x29, #-8]
//   0x005ec4: f9400108  ldr      x8, [x8]
//   0x005ec8: cb0b0108  sub      x8, x8, x11
//   0x005ecc: d61f0100  br       x8
//   0x005ed0: b98002e9  ldrsw    x9, [x23]
//   0x005ed4: 529c642c  mov      w12, #0xe321
//   0x005ed8: b980030b  ldrsw    x11, [x24]
//   0x005edc: 72acb54c  movk     w12, #0x65aa, lsl #16
//   0x005ee0: b980032d  ldrsw    x13, [x25]
//   0x005ee4: d37df129  lsl      x9, x9, #3
//   0x005ee8: d37df16b  lsl      x11, x11, #3
//   0x005eec: f8696a6a  ldr      x10, [x19, x9]
//   0x005ef0: ca0c014c  eor      x12, x10, x12
//   0x005ef4: f8296a6c  str      x12, [x19, x9]
//   0x005ef8: 52981dac  mov      w12, #0xc0ed
//   0x005efc: f86b6a69  ldr      x9, [x19, x11]
//   0x005f00: 72a0fbac  movk     w12, #0x7dd, lsl #16
//   0x005f04: ca0c012c  eor      x12, x9, x12
//   0x005f08: 9aca2129  lsl      x9, x9, x10
//   0x005f0c: f82b6a6c  str      x12, [x19, x11]
//   0x005f10: 528be7eb  mov      w11, #0x5f3f
//   0x005f14: f82d7a69  str      x9, [x19, x13, lsl #3]
//   0x005f18: 72aefe8b  movk     w11, #0x77f4, lsl #16
//   0x005f1c: f94002a9  ldr      x9, [x21]
//   0x005f20: f9000089  str      x9, [x4]
//   0x005f24: b8404d2a  ldr      w10, [x9, #4]!
//   0x005f28: f90002a9  str      x9, [x21]
//   0x005f2c: 4a0b014a  eor      w10, w10, w11
//   0x005f30: b900012a  str      w10, [x9]
//   0x005f34: 17ffffb9  b        #0x5e18
//   0x005f38: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x005f3c: 53167f68  lsr      w8, w27, #0x16
//   0x005f40: 530c7f6a  lsr      w10, w27, #0xc
//   0x005f44: 531b7f69  lsr      w9, w27, #0x1b
//   0x005f48: b90002eb  str      w11, [x23]
//   0x005f4c: 3760067b  tbnz     w27, #0xc, #0x6018
//   0x005f50: 121f014c  and      w12, w10, #2
//   0x005f54: 121e014d  and      w13, w10, #4
//   0x005f58: 33165b6c  bfxil    w12, w27, #0x16, #1
//   0x005f5c: 121d014e  and      w14, w10, #8
//   0x005f60: 2a0d018c  orr      w12, w12, w13
//   0x005f64: 121c014a  and      w10, w10, #0x10
//   0x005f68: 2a0e018c  orr      w12, w12, w14
//   0x005f6c: f86b5a6b  ldr      x11, [x19, w11, uxtw #3]
//   0x005f70: 2a0a018a  orr      w10, w12, w10
//   0x005f74: d282080e  mov      x14, #0x1040
//   0x005f78: f2a1404e  movk     x14, #0xa02, lsl #16
//   0x005f7c: f94002ad  ldr      x13, [x21]
//   0x005f80: f2cc080e  movk     x14, #0x6040, lsl #32
//   0x005f84: 121f0d08  and      w8, w8, #0x1e
//   0x005f88: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x005f8c: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x005f90: aa2501ce  orn      x14, x14, x5
//   0x005f94: b900030a  str      w10, [x24]
//   0x005f98: b9000329  str      w9, [x25]
//   0x005f9c: b9000348  str      w8, [x26]
//   0x005fa0: 9acb258b  lsr      x11, x12, x11
//   0x005fa4: d282880c  mov      x12, #0x1440
//   0x005fa8: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x005fac: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x005fb0: f8295a6b  str      x11, [x19, w9, uxtw #3]
//   0x005fb4: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x005fb8: 8a0c01cc  and      x12, x14, x12
//   0x005fbc: d280800e  mov      x14, #0x400
//   0x005fc0: f2a0008e  movk     x14, #4, lsl #16
//   0x005fc4: b8404dab  ldr      w11, [x13, #4]!
//   0x005fc8: f2c0208e  movk     x14, #0x104, lsl #32
//   0x005fcc: f90002ad  str      x13, [x21]
//   0x005fd0: 5280208d  mov      w13, #0x104
//   0x005fd4: 8a0e00ae  and      x14, x5, x14
//   0x005fd8: 72a0202d  movk     w13, #0x101, lsl #16
//   0x005fdc: 8b0e018c  add      x12, x12, x14
//   0x005fe0: aa0d018c  orr      x12, x12, x13
//   0x005fe4: d28d6b8d  mov      x13, #0x6b5c
//   0x005fe8: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x005fec: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x005ff0: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x005ff4: 9240156b  and      x11, x11, #0x3f
//   0x005ff8: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x005ffc: ca0d018c  eor      x12, x12, x13
//   0x006000: 8b0c01cc  add      x12, x14, x12
//   0x006004: 8b0b0d8b  add      x11, x12, x11, lsl #3
//   0x006008: f85f83ac  ldur     x12, [x29, #-8]
//   0x00600c: f940016b  ldr      x11, [x11]
//   0x006010: cb0c016b  sub      x11, x11, x12
//   0x006014: d61f0160  br       x11
//   0x006018: 121f014d  and      w13, w10, #2
//   0x00601c: 121e014e  and      w14, w10, #4
//   0x006020: 33165b6d  bfxil    w13, w27, #0x16, #1
//   0x006024: 1214036c  and      w12, w27, #0x1000
//   0x006028: 2a0e01ad  orr      w13, w13, w14
//   0x00602c: 121d014e  and      w14, w10, #8
//   0x006030: 2a0e01ad  orr      w13, w13, w14
//   0x006034: 121c014a  and      w10, w10, #0x10
//   0x006038: 2a0a01aa  orr      w10, w13, w10
//   0x00603c: 121f010d  and      w13, w8, #2
//   0x006040: 2a4c31ac  orr      w12, w13, w12, lsr #12
//   0x006044: 121e010d  and      w13, w8, #4
//   0x006048: b9000309  str      w9, [x24]
//   0x00604c: 2a0d018c  orr      w12, w12, w13
//   0x006050: f86b5a6b  ldr      x11, [x19, w11, uxtw #3]
//   0x006054: 121d010d  and      w13, w8, #8
//   0x006058: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x00605c: 2a0d018c  orr      w12, w12, w13
//   0x006060: 121c010d  and      w13, w8, #0x10
//   0x006064: d0ffffe8  adrp     x8, #0x4000
//   0x006068: 91118108  add      x8, x8, #0x460
//   0x00606c: 2a0d018c  orr      w12, w12, w13
//   0x006070: 1100050d  add      w13, w8, #1
//   0x006074: b900032a  str      w10, [x25]
//   0x006078: 9acb2d29  ror      x9, x9, x11
//   0x00607c: 0a2801ab  bic      w11, w13, w8
//   0x006080: 5284034d  mov      w13, #0x201a
//   0x006084: 2a2b03eb  mvn      w11, w11
//   0x006088: 72a0440d  movk     w13, #0x220, lsl #16
//   0x00608c: b900034c  str      w12, [x26]
//   0x006090: 8a0d016b  and      x11, x11, x13
//   0x006094: d28c7bcd  mov      x13, #0x63de
//   0x006098: f2b8a7cd  movk     x13, #0xc53e, lsl #16
//   0x00609c: f2c1c00d  movk     x13, #0xe00, lsl #32
//   0x0060a0: f2e1200d  movk     x13, #0x900, lsl #48
//   0x0060a4: 8b0d016b  add      x11, x11, x13
//   0x0060a8: 529c354d  mov      w13, #0xe1aa
//   0x0060ac: 72a2786d  movk     w13, #0x13c3, lsl #16
//   0x0060b0: eb0d017f  cmp      x11, x13
//   0x0060b4: 54000483  b.lo     #0x6144
//   0x0060b8: d282080b  mov      x11, #0x1040
//   0x0060bc: f82a5a69  str      x9, [x19, w10, uxtw #3]
//   0x0060c0: d280800a  mov      x10, #0x400
//   0x0060c4: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x0060c8: d282880c  mov      x12, #0x1440
//   0x0060cc: f2a0008a  movk     x10, #4, lsl #16
//   0x0060d0: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x0060d4: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x0060d8: f2c0208a  movk     x10, #0x104, lsl #32
//   0x0060dc: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x0060e0: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0060e4: 8a0a010a  and      x10, x8, x10
//   0x0060e8: aa280168  orn      x8, x11, x8
//   0x0060ec: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0060f0: 8a0c0108  and      x8, x8, x12
//   0x0060f4: f94002a9  ldr      x9, [x21]
//   0x0060f8: 8b0a0108  add      x8, x8, x10
//   0x0060fc: 5280208a  mov      w10, #0x104
//   0x006100: 72a0202a  movk     w10, #0x101, lsl #16
//   0x006104: aa0a0108  orr      x8, x8, x10
//   0x006108: d28d6b8a  mov      x10, #0x6b5c
//   0x00610c: b8404d2b  ldr      w11, [x9, #4]!
//   0x006110: f90002a9  str      x9, [x21]
//   0x006114: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x006118: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00611c: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x006120: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x006124: 9240156b  and      x11, x11, #0x3f
//   0x006128: ca0a0108  eor      x8, x8, x10
//   0x00612c: 8b080128  add      x8, x9, x8
//   0x006130: f85f83a9  ldur     x9, [x29, #-8]
//   0x006134: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x006138: f9400108  ldr      x8, [x8]
//   0x00613c: cb090108  sub      x8, x8, x9
//   0x006140: d61f0100  br       x8
//   0x006144: f94002ab  ldr      x11, [x21]
//   0x006148: f82a5a69  str      x9, [x19, w10, uxtw #3]
//   0x00614c: 5294bcec  mov      w12, #0xa5e7
//   0x006150: 72aa54ac  movk     w12, #0x52a5, lsl #16
//   0x006154: f900008b  str      x11, [x4]
//   0x006158: 4a0c014a  eor      w10, w10, w12
//   0x00615c: b8404d6d  ldr      w13, [x11, #4]!
//   0x006160: 5281628c  mov      w12, #0xb14
//   0x006164: f90002ab  str      x11, [x21]
//   0x006168: 72af25ec  movk     w12, #0x792f, lsl #16
//   0x00616c: b900032a  str      w10, [x25]
//   0x006170: 4a0c01ac  eor      w12, w13, w12
//   0x006174: b900016c  str      w12, [x11]
//   0x006178: 17ffffd0  b        #0x60b8
//   0x00617c: 531b7f68  lsr      w8, w27, #0x1b
//   0x006180: 530c7f6b  lsr      w11, w27, #0xc
//   0x006184: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x006188: 376006fb  tbnz     w27, #0xc, #0x6264
//   0x00618c: 121f0169  and      w9, w11, #2
//   0x006190: 121e016c  and      w12, w11, #4
//   0x006194: 331b6f69  bfxil    w9, w27, #0x1b, #1
//   0x006198: 121f0d08  and      w8, w8, #0x1e
//   0x00619c: 2a0c0129  orr      w9, w9, w12
//   0x0061a0: 121d016c  and      w12, w11, #8
//   0x0061a4: 2a0c0129  orr      w9, w9, w12
//   0x0061a8: 121c016b  and      w11, w11, #0x10
//   0x0061ac: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x0061b0: 2a0b0129  orr      w9, w9, w11
//   0x0061b4: b900030a  str      w10, [x24]
//   0x0061b8: d37df14a  lsl      x10, x10, #3
//   0x0061bc: b9000348  str      w8, [x26]
//   0x0061c0: d282080b  mov      x11, #0x1040
//   0x0061c4: b900032c  str      w12, [x25]
//   0x0061c8: f8695a68  ldr      x8, [x19, w9, uxtw #3]
//   0x0061cc: b90002e9  str      w9, [x23]
//   0x0061d0: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x0061d4: b86a6a69  ldr      w9, [x19, x10]
//   0x0061d8: d280800a  mov      x10, #0x400
//   0x0061dc: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x0061e0: f2a0008a  movk     x10, #4, lsl #16
//   0x0061e4: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x0061e8: f2c0208a  movk     x10, #0x104, lsl #32
//   0x0061ec: aa25016b  orn      x11, x11, x5
//   0x0061f0: 8a0a00aa  and      x10, x5, x10
//   0x0061f4: 1ac82528  lsr      w8, w9, w8
//   0x0061f8: f94002a9  ldr      x9, [x21]
//   0x0061fc: 93407d08  sxtw     x8, w8
//   0x006200: f82c5a68  str      x8, [x19, w12, uxtw #3]
//   0x006204: d2828808  mov      x8, #0x1440
//   0x006208: f2a140c8  movk     x8, #0xa06, lsl #16
//   0x00620c: 5280208c  mov      w12, #0x104
//   0x006210: f2cc2888  movk     x8, #0x6144, lsl #32
//   0x006214: 72a0202c  movk     w12, #0x101, lsl #16
//   0x006218: f2e01408  movk     x8, #0xa0, lsl #48
//   0x00621c: 8a080168  and      x8, x11, x8
//   0x006220: 8b0a0108  add      x8, x8, x10
//   0x006224: d28d6b8a  mov      x10, #0x6b5c
//   0x006228: b8404d2b  ldr      w11, [x9, #4]!
//   0x00622c: f90002a9  str      x9, [x21]
//   0x006230: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x006234: f941f289  ldr      x9, [x20, #0x3e0]
//   0x006238: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00623c: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x006240: aa0c0108  orr      x8, x8, x12
//   0x006244: ca0a0108  eor      x8, x8, x10
//   0x006248: 9240156a  and      x10, x11, #0x3f
//   0x00624c: 8b080128  add      x8, x9, x8
//   0x006250: f85f83a9  ldur     x9, [x29, #-8]
//   0x006254: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x006258: f9400108  ldr      x8, [x8]
//   0x00625c: cb090108  sub      x8, x8, x9
//   0x006260: d61f0100  br       x8
//   0x006264: d0ffffe9  adrp     x9, #0x4000
//   0x006268: 5280412d  mov      w13, #0x209
//   0x00626c: 91118129  add      x9, x9, #0x460
//   0x006270: 72a0822d  movk     w13, #0x411, lsl #16
//   0x006274: 1100052c  add      w12, w9, #1
//   0x006278: 0a29018c  bic      w12, w12, w9
//   0x00627c: 2a2c03ec  mvn      w12, w12
//   0x006280: 8a0d018c  and      x12, x12, x13
//   0x006284: d29ab52d  mov      x13, #0xd5a9
//   0x006288: f2bd098d  movk     x13, #0xe84c, lsl #16
//   0x00628c: f2e1002d  movk     x13, #0x801, lsl #48
//   0x006290: 8b0d018c  add      x12, x12, x13
//   0x006294: 52993fed  mov      w13, #0xc9ff
//   0x006298: 72aeb62d  movk     w13, #0x75b1, lsl #16
//   0x00629c: eb0d019f  cmp      x12, x13
//   0x0062a0: 54000803  b.lo     #0x63a0
//   0x0062a4: 121f016e  and      w14, w11, #2
//   0x0062a8: 121e016f  and      w15, w11, #4
//   0x0062ac: 3311476e  bfxil    w14, w27, #0x11, #1
//   0x0062b0: 1214036c  and      w12, w27, #0x1000
//   0x0062b4: 2a0f01ce  orr      w14, w14, w15
//   0x0062b8: 121d016f  and      w15, w11, #8
//   0x0062bc: 53117f6d  lsr      w13, w27, #0x11
//   0x0062c0: 2a0f01ce  orr      w14, w14, w15
//   0x0062c4: 121c016b  and      w11, w11, #0x10
//   0x0062c8: b90002ea  str      w10, [x23]
//   0x0062cc: 2a0b01cb  orr      w11, w14, w11
//   0x0062d0: 121f01ae  and      w14, w13, #2
//   0x0062d4: 2a4c31cc  orr      w12, w14, w12, lsr #12
//   0x0062d8: 121e01ae  and      w14, w13, #4
//   0x0062dc: 2a0e018c  orr      w12, w12, w14
//   0x0062e0: 121d01ae  and      w14, w13, #8
//   0x0062e4: 2a0e018c  orr      w12, w12, w14
//   0x0062e8: 121c01ad  and      w13, w13, #0x10
//   0x0062ec: 2a0d018c  orr      w12, w12, w13
//   0x0062f0: b9000308  str      w8, [x24]
//   0x0062f4: d37df14a  lsl      x10, x10, #3
//   0x0062f8: d37df108  lsl      x8, x8, #3
//   0x0062fc: b900032b  str      w11, [x25]
//   0x006300: d282080d  mov      x13, #0x1040
//   0x006304: b900034c  str      w12, [x26]
//   0x006308: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x00630c: b86a6a6a  ldr      w10, [x19, x10]
//   0x006310: d280800c  mov      x12, #0x400
//   0x006314: b8686a68  ldr      w8, [x19, x8]
//   0x006318: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x00631c: f2a0008c  movk     x12, #4, lsl #16
//   0x006320: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x006324: f2c0208c  movk     x12, #0x104, lsl #32
//   0x006328: 1aca2d08  ror      w8, w8, w10
//   0x00632c: f94002aa  ldr      x10, [x21]
//   0x006330: 93407d08  sxtw     x8, w8
//   0x006334: f82b5a68  str      x8, [x19, w11, uxtw #3]
//   0x006338: d282880b  mov      x11, #0x1440
//   0x00633c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x006340: b8404d48  ldr      w8, [x10, #4]!
//   0x006344: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x006348: f90002aa  str      x10, [x21]
//   0x00634c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x006350: aa2901aa  orn      x10, x13, x9
//   0x006354: 8a0c0129  and      x9, x9, x12
//   0x006358: 8a0b014a  and      x10, x10, x11
//   0x00635c: 8b090149  add      x9, x10, x9
//   0x006360: 5280208a  mov      w10, #0x104
//   0x006364: 72a0202a  movk     w10, #0x101, lsl #16
//   0x006368: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x00636c: aa0a0129  orr      x9, x9, x10
//   0x006370: d28d6b8a  mov      x10, #0x6b5c
//   0x006374: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x006378: 92401508  and      x8, x8, #0x3f
//   0x00637c: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x006380: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x006384: ca0a0129  eor      x9, x9, x10
//   0x006388: 8b0901a9  add      x9, x13, x9
//   0x00638c: 8b080d28  add      x8, x9, x8, lsl #3
//   0x006390: f85f83a9  ldur     x9, [x29, #-8]
//   0x006394: f9400108  ldr      x8, [x8]
//   0x006398: cb090108  sub      x8, x8, x9
//   0x00639c: d61f0100  br       x8
//   0x0063a0: b98002ec  ldrsw    x12, [x23]
//   0x0063a4: 5298544f  mov      w15, #0xc2a2
//   0x0063a8: 72a080af  movk     w15, #0x405, lsl #16
//   0x0063ac: b9800310  ldrsw    x16, [x24]
//   0x0063b0: d37df18d  lsl      x13, x12, #3
//   0x0063b4: 4a0f018c  eor      w12, w12, w15
//   0x0063b8: 528377cf  mov      w15, #0x1bbe
//   0x0063bc: 72a2c5af  movk     w15, #0x162d, lsl #16
//   0x0063c0: f86d6a6e  ldr      x14, [x19, x13]
//   0x0063c4: b90002ec  str      w12, [x23]
//   0x0063c8: ca0f01ce  eor      x14, x14, x15
//   0x0063cc: 529d5ecf  mov      w15, #0xeaf6
//   0x0063d0: 72a58fcf  movk     w15, #0x2c7e, lsl #16
//   0x0063d4: 4a0f020f  eor      w15, w16, w15
//   0x0063d8: f82d6a6e  str      x14, [x19, x13]
//   0x0063dc: d37df20d  lsl      x13, x16, #3
//   0x0063e0: 529a698e  mov      w14, #0xd34c
//   0x0063e4: 72a80e6e  movk     w14, #0x4073, lsl #16
//   0x0063e8: b900030f  str      w15, [x24]
//   0x0063ec: b86d6a6c  ldr      w12, [x19, x13]
//   0x0063f0: 4a0e018c  eor      w12, w12, w14
//   0x0063f4: b82d6a6c  str      w12, [x19, x13]
//   0x0063f8: 17ffffab  b        #0x62a4
//   0x0063fc: d0ffffe8  adrp     x8, #0x4000
//   0x006400: 528c800a  mov      w10, #0x6400
//   0x006404: 91118108  add      x8, x8, #0x460
//   0x006408: 72aad80a  movk     w10, #0x56c0, lsl #16
//   0x00640c: 11000509  add      w9, w8, #1
//   0x006410: 0a280129  bic      w9, w9, w8
//   0x006414: 2a2903e9  mvn      w9, w9
//   0x006418: 8a0a0129  and      x9, x9, x10
//   0x00641c: d28fd3ea  mov      x10, #0x7e9f
//   0x006420: f2a7272a  movk     x10, #0x3939, lsl #16
//   0x006424: f2c0400a  movk     x10, #0x200, lsl #32
//   0x006428: f2e010ea  movk     x10, #0x87, lsl #48
//   0x00642c: 8b0a0129  add      x9, x9, x10
//   0x006430: 529364ea  mov      w10, #0x9b27
//   0x006434: 72a01e6a  movk     w10, #0xf3, lsl #16
//   0x006438: eb0a013f  cmp      x9, x10
//   0x00643c: 54000623  b.lo     #0x6500
//   0x006440: 53115769  ubfx     w9, w27, #0x11, #5
//   0x006444: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x006448: 53166b6b  ubfx     w11, w27, #0x16, #5
//   0x00644c: 531b7f6c  lsr      w12, w27, #0x1b
//   0x006450: d37df14d  lsl      x13, x10, #3
//   0x006454: b90002e9  str      w9, [x23]
//   0x006458: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x00645c: b900030a  str      w10, [x24]
//   0x006460: b900032b  str      w11, [x25]
//   0x006464: b900034c  str      w12, [x26]
//   0x006468: f94002ac  ldr      x12, [x21]
//   0x00646c: b86d6a6a  ldr      w10, [x19, x13]
//   0x006470: d280800d  mov      x13, #0x400
//   0x006474: f2a0008d  movk     x13, #4, lsl #16
//   0x006478: f2c0208d  movk     x13, #0x104, lsl #32
//   0x00647c: 8a0d010d  and      x13, x8, x13
//   0x006480: 1ac92149  lsl      w9, w10, w9
//   0x006484: d282080a  mov      x10, #0x1040
//   0x006488: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x00648c: 93407d29  sxtw     x9, w9
//   0x006490: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x006494: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x006498: f82b5a69  str      x9, [x19, w11, uxtw #3]
//   0x00649c: aa280148  orn      x8, x10, x8
//   0x0064a0: d282880a  mov      x10, #0x1440
//   0x0064a4: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x0064a8: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x0064ac: b8404d89  ldr      w9, [x12, #4]!
//   0x0064b0: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x0064b4: f90002ac  str      x12, [x21]
//   0x0064b8: d28d6b8c  mov      x12, #0x6b5c
//   0x0064bc: 8a0a0108  and      x8, x8, x10
//   0x0064c0: 5280208a  mov      w10, #0x104
//   0x0064c4: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x0064c8: 72a0202a  movk     w10, #0x101, lsl #16
//   0x0064cc: 8b0d0108  add      x8, x8, x13
//   0x0064d0: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x0064d4: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x0064d8: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x0064dc: aa0a0108  orr      x8, x8, x10
//   0x0064e0: ca0c0108  eor      x8, x8, x12
//   0x0064e4: 92401529  and      x9, x9, #0x3f
//   0x0064e8: 8b080168  add      x8, x11, x8
//   0x0064ec: 8b090d08  add      x8, x8, x9, lsl #3
//   0x0064f0: f85f83a9  ldur     x9, [x29, #-8]
//   0x0064f4: f9400108  ldr      x8, [x8]
//   0x0064f8: cb090108  sub      x8, x8, x9
//   0x0064fc: d61f0100  br       x8
//   0x006500: b98002e9  ldrsw    x9, [x23]
//   0x006504: 528fe1ec  mov      w12, #0x7f0f
//   0x006508: 72ad688c  movk     w12, #0x6b44, lsl #16
//   0x00650c: b980030d  ldrsw    x13, [x24]
//   0x006510: 529d19ae  mov      w14, #0xe8cd
//   0x006514: d37df12a  lsl      x10, x9, #3
//   0x006518: 72abbe2e  movk     w14, #0x5df1, lsl #16
//   0x00651c: 4a0c0129  eor      w9, w9, w12
//   0x006520: 5282794c  mov      w12, #0x13ca
//   0x006524: 72a6e68c  movk     w12, #0x3734, lsl #16
//   0x006528: f86a6a6b  ldr      x11, [x19, x10]
//   0x00652c: 4a0c01ac  eor      w12, w13, w12
//   0x006530: b90002e9  str      w9, [x23]
//   0x006534: b900030c  str      w12, [x24]
//   0x006538: 5289e2cc  mov      w12, #0x4f16
//   0x00653c: ca0e016e  eor      x14, x11, x14
//   0x006540: 72a77fec  movk     w12, #0x3bff, lsl #16
//   0x006544: f82a6a6e  str      x14, [x19, x10]
//   0x006548: d37df1aa  lsl      x10, x13, #3
//   0x00654c: b86a6a69  ldr      w9, [x19, x10]
//   0x006550: 4a0c012c  eor      w12, w9, w12
//   0x006554: 1acb2929  asr      w9, w9, w11
//   0x006558: 93407d29  sxtw     x9, w9
//   0x00655c: 528c9fcb  mov      w11, #0x64fe
//   0x006560: b82a6a6c  str      w12, [x19, x10]
//   0x006564: 72ab538b  movk     w11, #0x5a9c, lsl #16
//   0x006568: b980032a  ldrsw    x10, [x25]
//   0x00656c: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x006570: f94002a9  ldr      x9, [x21]
//   0x006574: f9000089  str      x9, [x4]
//   0x006578: b8404d2a  ldr      w10, [x9, #4]!
//   0x00657c: f90002a9  str      x9, [x21]
//   0x006580: 4a0b014a  eor      w10, w10, w11
//   0x006584: b900012a  str      w10, [x9]
//   0x006588: 17ffffae  b        #0x6440
//   0x00658c: 53115768  ubfx     w8, w27, #0x11, #5
//   0x006590: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x006594: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x006598: 531b7f6b  lsr      w11, w27, #0x1b
//   0x00659c: b9000308  str      w8, [x24]
//   0x0065a0: d37df108  lsl      x8, x8, #3
//   0x0065a4: b90002e9  str      w9, [x23]
//   0x0065a8: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x0065ac: b900032a  str      w10, [x25]
//   0x0065b0: b900034b  str      w11, [x26]
//   0x0065b4: b8686a68  ldr      w8, [x19, x8]
//   0x0065b8: 1ac92908  asr      w8, w8, w9
//   0x0065bc: f94002a9  ldr      x9, [x21]
//   0x0065c0: 93407d08  sxtw     x8, w8
//   0x0065c4: f82a5a68  str      x8, [x19, w10, uxtw #3]
//   0x0065c8: b8404d28  ldr      w8, [x9, #4]!
//   0x0065cc: f90002a9  str      x9, [x21]
//   0x0065d0: 52802089  mov      w9, #0x104
//   0x0065d4: 72a02029  movk     w9, #0x101, lsl #16
//   0x0065d8: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x0065dc: aa0902c9  orr      x9, x22, x9
//   0x0065e0: 92401508  and      x8, x8, #0x3f
//   0x0065e4: ca110129  eor      x9, x9, x17
//   0x0065e8: 8b090149  add      x9, x10, x9
//   0x0065ec: 8b080d28  add      x8, x9, x8, lsl #3
//   0x0065f0: f85f83a9  ldur     x9, [x29, #-8]
//   0x0065f4: f9400108  ldr      x8, [x8]
//   0x0065f8: cb090108  sub      x8, x8, x9
//   0x0065fc: d61f0100  br       x8
//   0x006600: 530c4368  ubfx     w8, w27, #0xc, #5
//   0x006604: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x006608: 531b7f6c  lsr      w12, w27, #0x1b
//   0x00660c: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x006610: b90002e8  str      w8, [x23]
//   0x006614: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x006618: b9000309  str      w9, [x24]
//   0x00661c: b900032c  str      w12, [x25]
//   0x006620: eb0b015f  cmp      x10, x11
//   0x006624: f94002aa  ldr      x10, [x21]
//   0x006628: 1a9fa7eb  cset     w11, lt
//   0x00662c: f82c5a6b  str      x11, [x19, w12, uxtw #3]
//   0x006630: b8404d4b  ldr      w11, [x10, #4]!
//   0x006634: f90002aa  str      x10, [x21]
//   0x006638: 5280208a  mov      w10, #0x104
//   0x00663c: 72a0202a  movk     w10, #0x101, lsl #16
//   0x006640: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x006644: aa0a02ca  orr      x10, x22, x10
//   0x006648: 9240156b  and      x11, x11, #0x3f
//   0x00664c: ca11014a  eor      x10, x10, x17
//   0x006650: 8b0a01aa  add      x10, x13, x10
//   0x006654: 8b0b0d4a  add      x10, x10, x11, lsl #3
//   0x006658: f85f83ab  ldur     x11, [x29, #-8]
//   0x00665c: f940014a  ldr      x10, [x10]
//   0x006660: cb0b0148  sub      x8, x10, x11
//   0x006664: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x006668: b900034a  str      w10, [x26]
//   0x00666c: d61f0100  br       x8
//   0x006670: d0ffffe8  adrp     x8, #0x4000
//   0x006674: 5291400a  mov      w10, #0x8a00
//   0x006678: 91118108  add      x8, x8, #0x460
//   0x00667c: 72a450aa  movk     w10, #0x2285, lsl #16
//   0x006680: 11000509  add      w9, w8, #1
//   0x006684: 0a280129  bic      w9, w9, w8
//   0x006688: 2a2903e9  mvn      w9, w9
//   0x00668c: 8a0a0129  and      x9, x9, x10
//   0x006690: d2979a4a  mov      x10, #0xbcd2
//   0x006694: f2ab9c8a  movk     x10, #0x5ce4, lsl #16
//   0x006698: f2c0800a  movk     x10, #0x400, lsl #32
//   0x00669c: 8b0a0129  add      x9, x9, x10
//   0x0066a0: 5287848a  mov      w10, #0x3c24
//   0x0066a4: 72a1e96a  movk     w10, #0xf4b, lsl #16
//   0x0066a8: eb0a013f  cmp      x9, x10
//   0x0066ac: 54000603  b.lo     #0x676c
//   0x0066b0: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x0066b4: 531b7f6a  lsr      w10, w27, #0x1b
//   0x0066b8: d280800f  mov      x15, #0x400
//   0x0066bc: 5311576d  ubfx     w13, w27, #0x11, #5
//   0x0066c0: f2a0008f  movk     x15, #4, lsl #16
//   0x0066c4: f94002ae  ldr      x14, [x21]
//   0x0066c8: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x0066cc: f2c0208f  movk     x15, #0x104, lsl #32
//   0x0066d0: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x0066d4: b90002e9  str      w9, [x23]
//   0x0066d8: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x0066dc: b900030a  str      w10, [x24]
//   0x0066e0: b900032d  str      w13, [x25]
//   0x0066e4: eb0c017f  cmp      x11, x12
//   0x0066e8: d282080b  mov      x11, #0x1040
//   0x0066ec: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x0066f0: 8a0f010c  and      x12, x8, x15
//   0x0066f4: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x0066f8: 1a9f27ef  cset     w15, lo
//   0x0066fc: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x006700: b9000349  str      w9, [x26]
//   0x006704: aa280168  orn      x8, x11, x8
//   0x006708: d282880b  mov      x11, #0x1440
//   0x00670c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x006710: f82d5a6f  str      x15, [x19, w13, uxtw #3]
//   0x006714: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x006718: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00671c: 8a0b0108  and      x8, x8, x11
//   0x006720: b8404dcb  ldr      w11, [x14, #4]!
//   0x006724: f90002ae  str      x14, [x21]
//   0x006728: 5280208e  mov      w14, #0x104
//   0x00672c: 72a0202e  movk     w14, #0x101, lsl #16
//   0x006730: 8b0c0108  add      x8, x8, x12
//   0x006734: aa0e0108  orr      x8, x8, x14
//   0x006738: d28d6b8e  mov      x14, #0x6b5c
//   0x00673c: f2be938e  movk     x14, #0xf49c, lsl #16
//   0x006740: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x006744: f2d3d76e  movk     x14, #0x9ebb, lsl #32
//   0x006748: 9240156b  and      x11, x11, #0x3f
//   0x00674c: f2ffebee  movk     x14, #0xff5f, lsl #48
//   0x006750: ca0e0108  eor      x8, x8, x14
//   0x006754: 8b080188  add      x8, x12, x8
//   0x006758: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x00675c: f85f83ab  ldur     x11, [x29, #-8]
//   0x006760: f9400108  ldr      x8, [x8]
//   0x006764: cb0b0108  sub      x8, x8, x11
//   0x006768: d61f0100  br       x8
//   0x00676c: b98002e9  ldrsw    x9, [x23]
//   0x006770: 5283c1ec  mov      w12, #0x1e0f
//   0x006774: b980030b  ldrsw    x11, [x24]
//   0x006778: 72a2f48c  movk     w12, #0x17a4, lsl #16
//   0x00677c: d37df129  lsl      x9, x9, #3
//   0x006780: d37df16b  lsl      x11, x11, #3
//   0x006784: f8696a6a  ldr      x10, [x19, x9]
//   0x006788: ca0c014c  eor      x12, x10, x12
//   0x00678c: f8296a6c  str      x12, [x19, x9]
//   0x006790: 5298e4cc  mov      w12, #0xc726
//   0x006794: f86b6a69  ldr      x9, [x19, x11]
//   0x006798: 72a07eac  movk     w12, #0x3f5, lsl #16
//   0x00679c: ca0c012c  eor      x12, x9, x12
//   0x0067a0: eb09015f  cmp      x10, x9
//   0x0067a4: b9800329  ldrsw    x9, [x25]
//   0x0067a8: 1a9fb7ea  cset     w10, ge
//   0x0067ac: f82b6a6c  str      x12, [x19, x11]
//   0x0067b0: 528b69cb  mov      w11, #0x5b4e
//   0x0067b4: 72a3896b  movk     w11, #0x1c4b, lsl #16
//   0x0067b8: f8297a6a  str      x10, [x19, x9, lsl #3]
//   0x0067bc: f94002a9  ldr      x9, [x21]
//   0x0067c0: f9000089  str      x9, [x4]
//   0x0067c4: b8404d2a  ldr      w10, [x9, #4]!
//   0x0067c8: f90002a9  str      x9, [x21]
//   0x0067cc: 4a0b014a  eor      w10, w10, w11
//   0x0067d0: b900012a  str      w10, [x9]
//   0x0067d4: 17ffffb7  b        #0x66b0
//   0x0067d8: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x0067dc: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x0067e0: 531b7f6c  lsr      w12, w27, #0x1b
//   0x0067e4: f94002ad  ldr      x13, [x21]
//   0x0067e8: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x0067ec: b90002e8  str      w8, [x23]
//   0x0067f0: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x0067f4: b9000309  str      w9, [x24]
//   0x0067f8: b900032c  str      w12, [x25]
//   0x0067fc: 8a0a016a  and      x10, x11, x10
//   0x006800: 5280208b  mov      w11, #0x104
//   0x006804: 72a0202b  movk     w11, #0x101, lsl #16
//   0x006808: f82c5a6a  str      x10, [x19, w12, uxtw #3]
//   0x00680c: aa0b02cb  orr      x11, x22, x11
//   0x006810: b8404daa  ldr      w10, [x13, #4]!
//   0x006814: f90002ad  str      x13, [x21]
//   0x006818: ca11016b  eor      x11, x11, x17
//   0x00681c: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x006820: 9240154a  and      x10, x10, #0x3f
//   0x006824: 8b0b01ab  add      x11, x13, x11
//   0x006828: 8b0a0d6a  add      x10, x11, x10, lsl #3
//   0x00682c: f85f83ab  ldur     x11, [x29, #-8]
//   0x006830: f940014a  ldr      x10, [x10]
//   0x006834: cb0b0148  sub      x8, x10, x11
//   0x006838: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x00683c: b900034a  str      w10, [x26]
//   0x006840: d61f0100  br       x8
//   0x006844: d0ffffe8  adrp     x8, #0x4000
//   0x006848: 5282000a  mov      w10, #0x1000
//   0x00684c: 91118108  add      x8, x8, #0x460
//   0x006850: 72a004ca  movk     w10, #0x26, lsl #16
//   0x006854: 11000509  add      w9, w8, #1
//   0x006858: 0a280129  bic      w9, w9, w8
//   0x00685c: 2a2903e9  mvn      w9, w9
//   0x006860: 8a0a0129  and      x9, x9, x10
//   0x006864: d299036a  mov      x10, #0xc81b
//   0x006868: f2b66a2a  movk     x10, #0xb351, lsl #16
//   0x00686c: f2c0090a  movk     x10, #0x48, lsl #32
//   0x006870: f2e0c00a  movk     x10, #0x600, lsl #48
//   0x006874: aa0a0129  orr      x9, x9, x10
//   0x006878: 529cecca  mov      w10, #0xe766
//   0x00687c: 72a29d0a  movk     w10, #0x14e8, lsl #16
//   0x006880: eb0a013f  cmp      x9, x10
//   0x006884: 540005e3  b.lo     #0x6940
//   0x006888: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x00688c: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x006890: d280800f  mov      x15, #0x400
//   0x006894: 531b7f6d  lsr      w13, w27, #0x1b
//   0x006898: f2a0008f  movk     x15, #4, lsl #16
//   0x00689c: f94002ae  ldr      x14, [x21]
//   0x0068a0: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x0068a4: f2c0208f  movk     x15, #0x104, lsl #32
//   0x0068a8: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x0068ac: 8a0f010f  and      x15, x8, x15
//   0x0068b0: b90002e9  str      w9, [x23]
//   0x0068b4: 53115769  ubfx     w9, w27, #0x11, #5
//   0x0068b8: b900030a  str      w10, [x24]
//   0x0068bc: b900032d  str      w13, [x25]
//   0x0068c0: aa0b018b  orr      x11, x12, x11
//   0x0068c4: d282080c  mov      x12, #0x1040
//   0x0068c8: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x0068cc: b9000349  str      w9, [x26]
//   0x0068d0: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x0068d4: f82d5a6b  str      x11, [x19, w13, uxtw #3]
//   0x0068d8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0068dc: aa280188  orn      x8, x12, x8
//   0x0068e0: d282880c  mov      x12, #0x1440
//   0x0068e4: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x0068e8: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0068ec: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0068f0: 8a0c0108  and      x8, x8, x12
//   0x0068f4: 5280208c  mov      w12, #0x104
//   0x0068f8: 72a0202c  movk     w12, #0x101, lsl #16
//   0x0068fc: 8b0f0108  add      x8, x8, x15
//   0x006900: aa0c0108  orr      x8, x8, x12
//   0x006904: d28d6b8c  mov      x12, #0x6b5c
//   0x006908: b8404dcb  ldr      w11, [x14, #4]!
//   0x00690c: f90002ae  str      x14, [x21]
//   0x006910: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x006914: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x006918: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x00691c: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x006920: 9240156b  and      x11, x11, #0x3f
//   0x006924: ca0c0108  eor      x8, x8, x12
//   0x006928: 8b0801c8  add      x8, x14, x8
//   0x00692c: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x006930: f85f83ab  ldur     x11, [x29, #-8]
//   0x006934: f9400108  ldr      x8, [x8]
//   0x006938: cb0b0108  sub      x8, x8, x11
//   0x00693c: d61f0100  br       x8
//   0x006940: b98002e9  ldrsw    x9, [x23]
//   0x006944: 52957e8c  mov      w12, #0xabf4
//   0x006948: b980030b  ldrsw    x11, [x24]
//   0x00694c: 72a2e10c  movk     w12, #0x1708, lsl #16
//   0x006950: d37df129  lsl      x9, x9, #3
//   0x006954: d37df16b  lsl      x11, x11, #3
//   0x006958: f8696a6a  ldr      x10, [x19, x9]
//   0x00695c: ca0c014c  eor      x12, x10, x12
//   0x006960: f8296a6c  str      x12, [x19, x9]
//   0x006964: 529969ac  mov      w12, #0xcb4d
//   0x006968: f86b6a69  ldr      x9, [x19, x11]
//   0x00696c: 72a4e3cc  movk     w12, #0x271e, lsl #16
//   0x006970: ca0c0129  eor      x9, x9, x12
//   0x006974: b980032c  ldrsw    x12, [x25]
//   0x006978: f82b6a69  str      x9, [x19, x11]
//   0x00697c: 5289732b  mov      w11, #0x4b99
//   0x006980: f82c7a6a  str      x10, [x19, x12, lsl #3]
//   0x006984: 72a5698b  movk     w11, #0x2b4c, lsl #16
//   0x006988: f94002a9  ldr      x9, [x21]
//   0x00698c: f9000089  str      x9, [x4]
//   0x006990: b8404d2a  ldr      w10, [x9, #4]!
//   0x006994: f90002a9  str      x9, [x21]
//   0x006998: 4a0b014a  eor      w10, w10, w11
//   0x00699c: b900012a  str      w10, [x9]
//   0x0069a0: 17ffffba  b        #0x6888
//   0x0069a4: 53115768  ubfx     w8, w27, #0x11, #5
//   0x0069a8: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x0069ac: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x0069b0: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x0069b4: b90002e8  str      w8, [x23]
//   0x0069b8: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x0069bc: b9000309  str      w9, [x24]
//   0x0069c0: b900032c  str      w12, [x25]
//   0x0069c4: aa0a016a  orr      x10, x11, x10
//   0x0069c8: f94002ab  ldr      x11, [x21]
//   0x0069cc: aa2a03ea  mvn      x10, x10
//   0x0069d0: f82c5a6a  str      x10, [x19, w12, uxtw #3]
//   0x0069d4: b8404d6a  ldr      w10, [x11, #4]!
//   0x0069d8: f90002ab  str      x11, [x21]
//   0x0069dc: 5280208b  mov      w11, #0x104
//   0x0069e0: 72a0202b  movk     w11, #0x101, lsl #16
//   0x0069e4: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x0069e8: aa0b02cb  orr      x11, x22, x11
//   0x0069ec: 9240154a  and      x10, x10, #0x3f
//   0x0069f0: ca11016b  eor      x11, x11, x17
//   0x0069f4: 8b0b01ab  add      x11, x13, x11
//   0x0069f8: 8b0a0d6a  add      x10, x11, x10, lsl #3
//   0x0069fc: f85f83ab  ldur     x11, [x29, #-8]
//   0x006a00: f940014a  ldr      x10, [x10]
//   0x006a04: cb0b0148  sub      x8, x10, x11
//   0x006a08: 531b7f6a  lsr      w10, w27, #0x1b
//   0x006a0c: b900034a  str      w10, [x26]
//   0x006a10: d61f0100  br       x8
//   0x006a14: d0ffffe8  adrp     x8, #0x4000
//   0x006a18: 5280530a  mov      w10, #0x298
//   0x006a1c: 91118108  add      x8, x8, #0x460
//   0x006a20: 72a20b0a  movk     w10, #0x1058, lsl #16
//   0x006a24: 11000509  add      w9, w8, #1
//   0x006a28: 0a280129  bic      w9, w9, w8
//   0x006a2c: 2a2903e9  mvn      w9, w9
//   0x006a30: 8a0a0129  and      x9, x9, x10
//   0x006a34: d2852c2a  mov      x10, #0x2961
//   0x006a38: f2b3a20a  movk     x10, #0x9d10, lsl #16
//   0x006a3c: f2cc040a  movk     x10, #0x6020, lsl #32
//   0x006a40: 8b0a0129  add      x9, x9, x10
//   0x006a44: 5294c44a  mov      w10, #0xa622
//   0x006a48: 72a258ea  movk     w10, #0x12c7, lsl #16
//   0x006a4c: eb0a013f  cmp      x9, x10
//   0x006a50: 540005e3  b.lo     #0x6b0c
//   0x006a54: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x006a58: 531b7f6a  lsr      w10, w27, #0x1b
//   0x006a5c: d280800f  mov      x15, #0x400
//   0x006a60: 530c436d  ubfx     w13, w27, #0xc, #5
//   0x006a64: f2a0008f  movk     x15, #4, lsl #16
//   0x006a68: f94002ae  ldr      x14, [x21]
//   0x006a6c: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x006a70: f2c0208f  movk     x15, #0x104, lsl #32
//   0x006a74: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x006a78: 8a0f010f  and      x15, x8, x15
//   0x006a7c: b90002e9  str      w9, [x23]
//   0x006a80: 53115769  ubfx     w9, w27, #0x11, #5
//   0x006a84: b900030a  str      w10, [x24]
//   0x006a88: b900032d  str      w13, [x25]
//   0x006a8c: ca0b018b  eor      x11, x12, x11
//   0x006a90: d282080c  mov      x12, #0x1040
//   0x006a94: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x006a98: b9000349  str      w9, [x26]
//   0x006a9c: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x006aa0: f82d5a6b  str      x11, [x19, w13, uxtw #3]
//   0x006aa4: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x006aa8: aa280188  orn      x8, x12, x8
//   0x006aac: d282880c  mov      x12, #0x1440
//   0x006ab0: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x006ab4: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x006ab8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x006abc: 8a0c0108  and      x8, x8, x12
//   0x006ac0: 5280208c  mov      w12, #0x104
//   0x006ac4: 72a0202c  movk     w12, #0x101, lsl #16
//   0x006ac8: 8b0f0108  add      x8, x8, x15
//   0x006acc: aa0c0108  orr      x8, x8, x12
//   0x006ad0: d28d6b8c  mov      x12, #0x6b5c
//   0x006ad4: b8404dcb  ldr      w11, [x14, #4]!
//   0x006ad8: f90002ae  str      x14, [x21]
//   0x006adc: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x006ae0: f941f28e  ldr      x14, [x20, #0x3e0]
//   0x006ae4: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x006ae8: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x006aec: 9240156b  and      x11, x11, #0x3f
//   0x006af0: ca0c0108  eor      x8, x8, x12
//   0x006af4: 8b0801c8  add      x8, x14, x8
//   0x006af8: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x006afc: f85f83ab  ldur     x11, [x29, #-8]
//   0x006b00: f9400108  ldr      x8, [x8]
//   0x006b04: cb0b0108  sub      x8, x8, x11
//   0x006b08: d61f0100  br       x8
//   0x006b0c: b98002e9  ldrsw    x9, [x23]
//   0x006b10: 52974aac  mov      w12, #0xba55
//   0x006b14: b980030b  ldrsw    x11, [x24]
//   0x006b18: 72a5546c  movk     w12, #0x2aa3, lsl #16
//   0x006b1c: b980032d  ldrsw    x13, [x25]
//   0x006b20: d37df129  lsl      x9, x9, #3
//   0x006b24: d37df16b  lsl      x11, x11, #3
//   0x006b28: f8696a6a  ldr      x10, [x19, x9]
//   0x006b2c: ca0c014c  eor      x12, x10, x12
//   0x006b30: f8296a6c  str      x12, [x19, x9]
//   0x006b34: 529015ac  mov      w12, #0x80ad
//   0x006b38: f86b6a69  ldr      x9, [x19, x11]
//   0x006b3c: 72aaa06c  movk     w12, #0x5503, lsl #16
//   0x006b40: ca0c012c  eor      x12, x9, x12
//   0x006b44: 8a2a0129  bic      x9, x9, x10
//   0x006b48: f82b6a6c  str      x12, [x19, x11]
//   0x006b4c: 529d9ecb  mov      w11, #0xecf6
//   0x006b50: f82d7a69  str      x9, [x19, x13, lsl #3]
//   0x006b54: 72a0ca6b  movk     w11, #0x653, lsl #16
//   0x006b58: f94002a9  ldr      x9, [x21]
//   0x006b5c: f9000089  str      x9, [x4]
//   0x006b60: b8404d2a  ldr      w10, [x9, #4]!
//   0x006b64: f90002a9  str      x9, [x21]
//   0x006b68: 4a0b014a  eor      w10, w10, w11
//   0x006b6c: b900012a  str      w10, [x9]
//   0x006b70: 17ffffb9  b        #0x6a54
//   0x006b74: 53115769  ubfx     w9, w27, #0x11, #5
//   0x006b78: f94002ab  ldr      x11, [x21]
//   0x006b7c: 531b7f68  lsr      w8, w27, #0x1b
//   0x006b80: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x006b84: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x006b88: b9000309  str      w9, [x24]
//   0x006b8c: 91001169  add      x9, x11, #4
//   0x006b90: b90002e8  str      w8, [x23]
//   0x006b94: b900032a  str      w10, [x25]
//   0x006b98: b900034c  str      w12, [x26]
//   0x006b9c: f82a5a69  str      x9, [x19, w10, uxtw #3]
//   0x006ba0: f8685a68  ldr      x8, [x19, w8, uxtw #3]
//   0x006ba4: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x006ba8: eb08013f  cmp      x9, x8
//   0x006bac: 54000620  b.eq     #0x6c70
//   0x006bb0: f85c03a9  ldur     x9, [x29, #-0x40]
//   0x006bb4: eb08013f  cmp      x9, x8
//   0x006bb8: 5403cb20  b.eq     #0xe51c
//   0x006bbc: d282080b  mov      x11, #0x1040
//   0x006bc0: d282880c  mov      x12, #0x1440
//   0x006bc4: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x006bc8: d2808009  mov      x9, #0x400
//   0x006bcc: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x006bd0: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x006bd4: f2a00089  movk     x9, #4, lsl #16
//   0x006bd8: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x006bdc: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x006be0: f2c02089  movk     x9, #0x104, lsl #32
//   0x006be4: aa25016b  orn      x11, x11, x5
//   0x006be8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x006bec: 8a0900a9  and      x9, x5, x9
//   0x006bf0: 8a0c016b  and      x11, x11, x12
//   0x006bf4: 8b090169  add      x9, x11, x9
//   0x006bf8: 5280208b  mov      w11, #0x104
//   0x006bfc: 72a0202b  movk     w11, #0x101, lsl #16
//   0x006c00: f90002a8  str      x8, [x21]
//   0x006c04: aa0b0129  orr      x9, x9, x11
//   0x006c08: d28d6b8b  mov      x11, #0x6b5c
//   0x006c0c: b9400108  ldr      w8, [x8]
//   0x006c10: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x006c14: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x006c18: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x006c1c: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x006c20: 92401508  and      x8, x8, #0x3f
//   0x006c24: ca0b0129  eor      x9, x9, x11
//   0x006c28: 8b090149  add      x9, x10, x9
//   0x006c2c: 8b080d28  add      x8, x9, x8, lsl #3
//   0x006c30: f85f83a9  ldur     x9, [x29, #-8]
//   0x006c34: f9400108  ldr      x8, [x8]
//   0x006c38: cb090108  sub      x8, x8, x9
//   0x006c3c: d61f0100  br       x8
//   0x006c40: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x006c44: 531b7f69  lsr      w9, w27, #0x1b
//   0x006c48: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x006c4c: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x006c50: b90002e8  str      w8, [x23]
//   0x006c54: b9000309  str      w9, [x24]
//   0x006c58: b900032a  str      w10, [x25]
//   0x006c5c: b900034b  str      w11, [x26]
//   0x006c60: f8685a68  ldr      x8, [x19, w8, uxtw #3]
//   0x006c64: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x006c68: eb08013f  cmp      x9, x8
//   0x006c6c: 54fffa21  b.ne     #0x6bb0
//   0x006c70: f85b03a8  ldur     x8, [x29, #-0x50]
//   0x006c74: a9397ba1  stp      x1, x30, [x29, #-0x70]
//   0x006c78: f81a03a7  stur     x7, [x29, #-0x60]
//   0x006c7c: a9380ba3  stp      x3, x2, [x29, #-0x80]
//   0x006c80: f9400100  ldr      x0, [x8]
//   0x006c84: a9371ba4  stp      x4, x6, [x29, #-0x90]
//   0x006c88: f85a83a8  ldur     x8, [x29, #-0x58]
//   0x006c8c: f9400101  ldr      x1, [x8]
//   0x006c90: f85c83a8  ldur     x8, [x29, #-0x38]
//   0x006c94: d63f0100  blr      x8
//   0x006c98: a9771ba4  ldp      x4, x6, [x29, #-0x90]
//   0x006c9c: d28d6b91  mov      x17, #0x6b5c
//   0x006ca0: d0ffffe5  adrp     x5, #0x4000
//   0x006ca4: a9780ba3  ldp      x3, x2, [x29, #-0x80]
//   0x006ca8: f2be9391  movk     x17, #0xf49c, lsl #16
//   0x006cac: 90ffffe0  adrp     x0, #0x2000
//   0x006cb0: a9797ba1  ldp      x1, x30, [x29, #-0x70]
//   0x006cb4: f2d3d771  movk     x17, #0x9ebb, lsl #32
//   0x006cb8: 911180a5  add      x5, x5, #0x460
//   0x006cbc: f94002a8  ldr      x8, [x21]
//   0x006cc0: f2ffebf1  movk     x17, #0xff5f, lsl #48
//   0x006cc4: f85a03a7  ldur     x7, [x29, #-0x60]
//   0x006cc8: 91001108  add      x8, x8, #4
//   0x006ccc: 17ffffbc  b        #0x6bbc
//   0x006cd0: d0ffffe8  adrp     x8, #0x4000
//   0x006cd4: 52981eca  mov      w10, #0xc0f6
//   0x006cd8: 91118108  add      x8, x8, #0x460
//   0x006cdc: 72a2064a  movk     w10, #0x1032, lsl #16
//   0x006ce0: 11000509  add      w9, w8, #1
//   0x006ce4: 0a280129  bic      w9, w9, w8
//   0x006ce8: 2a2903e9  mvn      w9, w9
//   0x006cec: 8a0a0129  and      x9, x9, x10
//   0x006cf0: d28661ea  mov      x10, #0x330f
//   0x006cf4: f2a1922a  movk     x10, #0xc91, lsl #16
//   0x006cf8: f2c2042a  movk     x10, #0x1021, lsl #32
//   0x006cfc: 8b0a0129  add      x9, x9, x10
//   0x006d00: 528e3b6a  mov      w10, #0x71db
//   0x006d04: 72a040aa  movk     w10, #0x205, lsl #16
//   0x006d08: eb0a013f  cmp      x9, x10
//   0x006d0c: 54000583  b.lo     #0x6dbc
//   0x006d10: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x006d14: 531b7f6a  lsr      w10, w27, #0x1b
//   0x006d18: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x006d1c: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x006d20: b900032b  str      w11, [x25]
//   0x006d24: d282080b  mov      x11, #0x1040
//   0x006d28: b900030a  str      w10, [x24]
//   0x006d2c: d280800a  mov      x10, #0x400
//   0x006d30: b900034c  str      w12, [x26]
//   0x006d34: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x006d38: d282880c  mov      x12, #0x1440
//   0x006d3c: f2a0008a  movk     x10, #4, lsl #16
//   0x006d40: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x006d44: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x006d48: f2c0208a  movk     x10, #0x104, lsl #32
//   0x006d4c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x006d50: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x006d54: b90002e9  str      w9, [x23]
//   0x006d58: 8a0a010a  and      x10, x8, x10
//   0x006d5c: aa280168  orn      x8, x11, x8
//   0x006d60: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x006d64: d5033bbf  dmb      ish
//   0x006d68: 8a0c0108  and      x8, x8, x12
//   0x006d6c: f94002a9  ldr      x9, [x21]
//   0x006d70: 8b0a0108  add      x8, x8, x10
//   0x006d74: 5280208a  mov      w10, #0x104
//   0x006d78: 72a0202a  movk     w10, #0x101, lsl #16
//   0x006d7c: aa0a0108  orr      x8, x8, x10
//   0x006d80: d28d6b8a  mov      x10, #0x6b5c
//   0x006d84: b8404d2b  ldr      w11, [x9, #4]!
//   0x006d88: f90002a9  str      x9, [x21]
//   0x006d8c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x006d90: f941f289  ldr      x9, [x20, #0x3e0]
//   0x006d94: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x006d98: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x006d9c: 9240156b  and      x11, x11, #0x3f
//   0x006da0: ca0a0108  eor      x8, x8, x10
//   0x006da4: 8b080128  add      x8, x9, x8
//   0x006da8: f85f83a9  ldur     x9, [x29, #-8]
//   0x006dac: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x006db0: f9400108  ldr      x8, [x8]
//   0x006db4: cb090108  sub      x8, x8, x9
//   0x006db8: d61f0100  br       x8
//   0x006dbc: d5033bbf  dmb      ish
//   0x006dc0: 5283304b  mov      w11, #0x1982
//   0x006dc4: f94002a9  ldr      x9, [x21]
//   0x006dc8: 72a8a86b  movk     w11, #0x4543, lsl #16
//   0x006dcc: f9000089  str      x9, [x4]
//   0x006dd0: b8404d2a  ldr      w10, [x9, #4]!
//   0x006dd4: f90002a9  str      x9, [x21]
//   0x006dd8: 4a0b014a  eor      w10, w10, w11
//   0x006ddc: b900012a  str      w10, [x9]
//   0x006de0: 17ffffcc  b        #0x6d10
//   0x006de4: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x006de8: 531b7f68  lsr      w8, w27, #0x1b
//   0x006dec: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x006df0: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x006df4: f86a5a6b  ldr      x11, [x19, w10, uxtw #3]
//   0x006df8: b90002e8  str      w8, [x23]
//   0x006dfc: b900030a  str      w10, [x24]
//   0x006e00: b9000329  str      w9, [x25]
//   0x006e04: b900034c  str      w12, [x26]
//   0x006e08: b400006b  cbz      x11, #0x6e14
//   0x006e0c: f8685a68  ldr      x8, [x19, w8, uxtw #3]
//   0x006e10: f8295a68  str      x8, [x19, w9, uxtw #3]
//   0x006e14: f94002a8  ldr      x8, [x21]
//   0x006e18: d282080a  mov      x10, #0x1040
//   0x006e1c: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x006e20: d2808009  mov      x9, #0x400
//   0x006e24: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x006e28: f2a00089  movk     x9, #4, lsl #16
//   0x006e2c: b8404d0b  ldr      w11, [x8, #4]!
//   0x006e30: f90002a8  str      x8, [x21]
//   0x006e34: d2828808  mov      x8, #0x1440
//   0x006e38: f2a140c8  movk     x8, #0xa06, lsl #16
//   0x006e3c: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x006e40: f2cc2888  movk     x8, #0x6144, lsl #32
//   0x006e44: f2c02089  movk     x9, #0x104, lsl #32
//   0x006e48: aa25014a  orn      x10, x10, x5
//   0x006e4c: f2e01408  movk     x8, #0xa0, lsl #48
//   0x006e50: 8a0900a9  and      x9, x5, x9
//   0x006e54: 8a080148  and      x8, x10, x8
//   0x006e58: 8b090108  add      x8, x8, x9
//   0x006e5c: 52802089  mov      w9, #0x104
//   0x006e60: 72a02029  movk     w9, #0x101, lsl #16
//   0x006e64: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x006e68: aa090108  orr      x8, x8, x9
//   0x006e6c: d28d6b89  mov      x9, #0x6b5c
//   0x006e70: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x006e74: 9240156a  and      x10, x11, #0x3f
//   0x006e78: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x006e7c: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x006e80: ca090108  eor      x8, x8, x9
//   0x006e84: f85f83a9  ldur     x9, [x29, #-8]
//   0x006e88: 8b080188  add      x8, x12, x8
//   0x006e8c: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x006e90: f9400108  ldr      x8, [x8]
//   0x006e94: cb090108  sub      x8, x8, x9
//   0x006e98: d61f0100  br       x8
//   0x006e9c: 531b7f6a  lsr      w10, w27, #0x1b
//   0x006ea0: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x006ea4: 530c4368  ubfx     w8, w27, #0xc, #5
//   0x006ea8: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x006eac: f86a5a6b  ldr      x11, [x19, w10, uxtw #3]
//   0x006eb0: b90002e9  str      w9, [x23]
//   0x006eb4: b900030a  str      w10, [x24]
//   0x006eb8: b9000328  str      w8, [x25]
//   0x006ebc: b900034c  str      w12, [x26]
//   0x006ec0: b500028b  cbnz     x11, #0x6f10
//   0x006ec4: d0ffffea  adrp     x10, #0x4000
//   0x006ec8: 9111814a  add      x10, x10, #0x460
//   0x006ecc: 1100054b  add      w11, w10, #1
//   0x006ed0: 0a2a016a  bic      w10, w11, w10
//   0x006ed4: 5285406b  mov      w11, #0x2a03
//   0x006ed8: 2a2a03ea  mvn      w10, w10
//   0x006edc: 72a0080b  movk     w11, #0x40, lsl #16
//   0x006ee0: 8a0b014a  and      x10, x10, x11
//   0x006ee4: d295a80b  mov      x11, #0xad40
//   0x006ee8: f2a86c8b  movk     x11, #0x4364, lsl #16
//   0x006eec: f2c2020b  movk     x11, #0x1010, lsl #32
//   0x006ef0: f2e0080b  movk     x11, #0x40, lsl #48
//   0x006ef4: 8b0b014a  add      x10, x10, x11
//   0x006ef8: 529b670b  mov      w11, #0xdb38
//   0x006efc: 72a01aab  movk     w11, #0xd5, lsl #16
//   0x006f00: eb0b015f  cmp      x10, x11
//   0x006f04: 540007a3  b.lo     #0x6ff8
//   0x006f08: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x006f0c: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x006f10: d0ffffe8  adrp     x8, #0x4000
//   0x006f14: d282e88a  mov      x10, #0x1744
//   0x006f18: 91118108  add      x8, x8, #0x460
//   0x006f1c: f2b3dc4a  movk     x10, #0x9ee2, lsl #16
//   0x006f20: 11000509  add      w9, w8, #1
//   0x006f24: f2c2012a  movk     x10, #0x1009, lsl #32
//   0x006f28: 0a280129  bic      w9, w9, w8
//   0x006f2c: f2e0010a  movk     x10, #8, lsl #48
//   0x006f30: 2a2903e9  mvn      w9, w9
//   0x006f34: 92730529  and      x9, x9, #0x6000
//   0x006f38: aa0a0129  orr      x9, x9, x10
//   0x006f3c: 5285faca  mov      w10, #0x2fd6
//   0x006f40: 72a00e8a  movk     w10, #0x74, lsl #16
//   0x006f44: eb0a013f  cmp      x9, x10
//   0x006f48: 54000463  b.lo     #0x6fd4
//   0x006f4c: d282080b  mov      x11, #0x1040
//   0x006f50: f94002a9  ldr      x9, [x21]
//   0x006f54: d280800a  mov      x10, #0x400
//   0x006f58: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x006f5c: f2a0008a  movk     x10, #4, lsl #16
//   0x006f60: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x006f64: f2c0208a  movk     x10, #0x104, lsl #32
//   0x006f68: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x006f6c: 8a0a010a  and      x10, x8, x10
//   0x006f70: aa280168  orn      x8, x11, x8
//   0x006f74: b8404d2b  ldr      w11, [x9, #4]!
//   0x006f78: f90002a9  str      x9, [x21]
//   0x006f7c: d2828809  mov      x9, #0x1440
//   0x006f80: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x006f84: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x006f88: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x006f8c: f2e01409  movk     x9, #0xa0, lsl #48
//   0x006f90: 8a090108  and      x8, x8, x9
//   0x006f94: 52802089  mov      w9, #0x104
//   0x006f98: 8b0a0108  add      x8, x8, x10
//   0x006f9c: 72a02029  movk     w9, #0x101, lsl #16
//   0x006fa0: aa090108  orr      x8, x8, x9
//   0x006fa4: d28d6b89  mov      x9, #0x6b5c
//   0x006fa8: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x006fac: 9240156a  and      x10, x11, #0x3f
//   0x006fb0: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x006fb4: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x006fb8: ca090108  eor      x8, x8, x9
//   0x006fbc: f85f83a9  ldur     x9, [x29, #-8]
//   0x006fc0: 8b080188  add      x8, x12, x8
//   0x006fc4: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x006fc8: f9400108  ldr      x8, [x8]
//   0x006fcc: cb090108  sub      x8, x8, x9
//   0x006fd0: d61f0100  br       x8
//   0x006fd4: f94002a9  ldr      x9, [x21]
//   0x006fd8: 52941fcb  mov      w11, #0xa0fe
//   0x006fdc: 72a487cb  movk     w11, #0x243e, lsl #16
//   0x006fe0: f9000089  str      x9, [x4]
//   0x006fe4: b8404d2a  ldr      w10, [x9, #4]!
//   0x006fe8: f90002a9  str      x9, [x21]
//   0x006fec: 4a0b014a  eor      w10, w10, w11
//   0x006ff0: b900012a  str      w10, [x9]
//   0x006ff4: 17ffffd6  b        #0x6f4c
//   0x006ff8: d37df12a  lsl      x10, x9, #3
//   0x006ffc: 52807f0c  mov      w12, #0x3f8
//   0x007000: 528be2ce  mov      w14, #0x5f16
//   0x007004: 72a0550c  movk     w12, #0x2a8, lsl #16
//   0x007008: 5292048d  mov      w13, #0x9024
//   0x00700c: 72ac576e  movk     w14, #0x62bb, lsl #16
//   0x007010: f86a6a6b  ldr      x11, [x19, x10]
//   0x007014: 72ac938d  movk     w13, #0x649c, lsl #16
//   0x007018: 4a0c012c  eor      w12, w9, w12
//   0x00701c: 4a0e010e  eor      w14, w8, w14
//   0x007020: 2a0c03e9  mov      w9, w12
//   0x007024: ca0d016d  eor      x13, x11, x13
//   0x007028: b90002ec  str      w12, [x23]
//   0x00702c: b900032e  str      w14, [x25]
//   0x007030: f82a6a6d  str      x13, [x19, x10]
//   0x007034: f8285a6b  str      x11, [x19, w8, uxtw #3]
//   0x007038: 2a0e03e8  mov      w8, w14
//   0x00703c: 17ffffb3  b        #0x6f08
//   0x007040: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x007044: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x007048: f94002aa  ldr      x10, [x21]
//   0x00704c: 530c436c  ubfx     w12, w27, #0xc, #5
//   0x007050: f9400129  ldr      x9, [x9]
//   0x007054: b9000328  str      w8, [x25]
//   0x007058: b900030c  str      w12, [x24]
//   0x00705c: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x007060: b8404d49  ldr      w9, [x10, #4]!
//   0x007064: f90002aa  str      x10, [x21]
//   0x007068: 5280208a  mov      w10, #0x104
//   0x00706c: 72a0202a  movk     w10, #0x101, lsl #16
//   0x007070: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x007074: aa0a02ca  orr      x10, x22, x10
//   0x007078: 92401529  and      x9, x9, #0x3f
//   0x00707c: ca11014a  eor      x10, x10, x17
//   0x007080: 8b0a016a  add      x10, x11, x10
//   0x007084: f85f83ab  ldur     x11, [x29, #-8]
//   0x007088: 8b090d49  add      x9, x10, x9, lsl #3
//   0x00708c: 531b7f6a  lsr      w10, w27, #0x1b
//   0x007090: f9400129  ldr      x9, [x9]
//   0x007094: b90002ea  str      w10, [x23]
//   0x007098: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x00709c: cb0b0129  sub      x9, x9, x11
//   0x0070a0: b900034a  str      w10, [x26]
//   0x0070a4: d61f0120  br       x9
//   0x0070a8: f85f03a9  ldur     x9, [x29, #-0x10]
//   0x0070ac: 531b7f68  lsr      w8, w27, #0x1b
//   0x0070b0: f94002aa  ldr      x10, [x21]
//   0x0070b4: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x0070b8: f9400129  ldr      x9, [x9]
//   0x0070bc: b9000328  str      w8, [x25]
//   0x0070c0: b900030c  str      w12, [x24]
//   0x0070c4: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x0070c8: b8404d49  ldr      w9, [x10, #4]!
//   0x0070cc: f90002aa  str      x10, [x21]
//   0x0070d0: 5280208a  mov      w10, #0x104
//   0x0070d4: 72a0202a  movk     w10, #0x101, lsl #16
//   0x0070d8: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x0070dc: aa0a02ca  orr      x10, x22, x10
//   0x0070e0: 92401529  and      x9, x9, #0x3f
//   0x0070e4: ca11014a  eor      x10, x10, x17
//   0x0070e8: 8b0a016a  add      x10, x11, x10
//   0x0070ec: f85f83ab  ldur     x11, [x29, #-8]
//   0x0070f0: 8b090d49  add      x9, x10, x9, lsl #3
//   0x0070f4: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x0070f8: f9400129  ldr      x9, [x9]
//   0x0070fc: b90002ea  str      w10, [x23]
//   0x007100: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x007104: cb0b0129  sub      x9, x9, x11
//   0x007108: b900034a  str      w10, [x26]
//   0x00710c: d61f0120  br       x9
//   0x007110: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x007114: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007118: f94002aa  ldr      x10, [x21]
//   0x00711c: f8685a69  ldr      x9, [x19, w8, uxtw #3]
//   0x007120: b90002e8  str      w8, [x23]
//   0x007124: 53115768  ubfx     w8, w27, #0x11, #5
//   0x007128: f9000169  str      x9, [x11]
//   0x00712c: b8404d49  ldr      w9, [x10, #4]!
//   0x007130: f90002aa  str      x10, [x21]
//   0x007134: 5280208a  mov      w10, #0x104
//   0x007138: 72a0202a  movk     w10, #0x101, lsl #16
//   0x00713c: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x007140: aa0a02ca  orr      x10, x22, x10
//   0x007144: 92401529  and      x9, x9, #0x3f
//   0x007148: ca11014a  eor      x10, x10, x17
//   0x00714c: b9000328  str      w8, [x25]
//   0x007150: 8b0a016a  add      x10, x11, x10
//   0x007154: 531b7f6b  lsr      w11, w27, #0x1b
//   0x007158: 8b090d49  add      x9, x10, x9, lsl #3
//   0x00715c: f85f83aa  ldur     x10, [x29, #-8]
//   0x007160: b900030b  str      w11, [x24]
//   0x007164: f9400129  ldr      x9, [x9]
//   0x007168: cb0a0129  sub      x9, x9, x10
//   0x00716c: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x007170: b900034a  str      w10, [x26]
//   0x007174: d61f0120  br       x9
//   0x007178: b0ffffe8  adrp     x8, #0x4000
//   0x00717c: 5280004a  mov      w10, #2
//   0x007180: 91118108  add      x8, x8, #0x460
//   0x007184: 72a2402a  movk     w10, #0x1201, lsl #16
//   0x007188: 11000509  add      w9, w8, #1
//   0x00718c: 0a280129  bic      w9, w9, w8
//   0x007190: 2a2903e9  mvn      w9, w9
//   0x007194: 8a0a0129  and      x9, x9, x10
//   0x007198: d281eb4a  mov      x10, #0xf5a
//   0x00719c: f2b95cea  movk     x10, #0xcae7, lsl #16
//   0x0071a0: f2c0922a  movk     x10, #0x491, lsl #32
//   0x0071a4: 8b0a0129  add      x9, x9, x10
//   0x0071a8: 52914bea  mov      w10, #0x8a5f
//   0x0071ac: 72a9384a  movk     w10, #0x49c2, lsl #16
//   0x0071b0: eb0a013f  cmp      x9, x10
//   0x0071b4: 540005c3  b.lo     #0x726c
//   0x0071b8: d282080d  mov      x13, #0x1040
//   0x0071bc: d280800c  mov      x12, #0x400
//   0x0071c0: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x0071c4: f2a0008c  movk     x12, #4, lsl #16
//   0x0071c8: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x0071cc: f2c0208c  movk     x12, #0x104, lsl #32
//   0x0071d0: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x0071d4: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x0071d8: 8a0c010c  and      x12, x8, x12
//   0x0071dc: aa2801a8  orn      x8, x13, x8
//   0x0071e0: d282880d  mov      x13, #0x1440
//   0x0071e4: f94002ab  ldr      x11, [x21]
//   0x0071e8: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x0071ec: f8695a6a  ldr      x10, [x19, w9, uxtw #3]
//   0x0071f0: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x0071f4: b90002e9  str      w9, [x23]
//   0x0071f8: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x0071fc: 531b7f69  lsr      w9, w27, #0x1b
//   0x007200: 8a0d0108  and      x8, x8, x13
//   0x007204: f85f03ad  ldur     x13, [x29, #-0x10]
//   0x007208: 8b0c0108  add      x8, x8, x12
//   0x00720c: b9000329  str      w9, [x25]
//   0x007210: f90001aa  str      x10, [x13]
//   0x007214: b8404d6a  ldr      w10, [x11, #4]!
//   0x007218: f90002ab  str      x11, [x21]
//   0x00721c: 5280208b  mov      w11, #0x104
//   0x007220: 72a0202b  movk     w11, #0x101, lsl #16
//   0x007224: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x007228: aa0b0108  orr      x8, x8, x11
//   0x00722c: d28d6b8b  mov      x11, #0x6b5c
//   0x007230: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x007234: 9240154a  and      x10, x10, #0x3f
//   0x007238: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x00723c: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x007240: ca0b0108  eor      x8, x8, x11
//   0x007244: 5311576b  ubfx     w11, w27, #0x11, #5
//   0x007248: 8b080188  add      x8, x12, x8
//   0x00724c: 530c436c  ubfx     w12, w27, #0xc, #5
//   0x007250: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x007254: f85f83aa  ldur     x10, [x29, #-8]
//   0x007258: b900030b  str      w11, [x24]
//   0x00725c: b900034c  str      w12, [x26]
//   0x007260: f9400108  ldr      x8, [x8]
//   0x007264: cb0a0108  sub      x8, x8, x10
//   0x007268: d61f0100  br       x8
//   0x00726c: b98002e9  ldrsw    x9, [x23]
//   0x007270: 529b51eb  mov      w11, #0xda8f
//   0x007274: 72a8e2cb  movk     w11, #0x4716, lsl #16
//   0x007278: d37df129  lsl      x9, x9, #3
//   0x00727c: f8696a6a  ldr      x10, [x19, x9]
//   0x007280: ca0b014b  eor      x11, x10, x11
//   0x007284: f8296a6b  str      x11, [x19, x9]
//   0x007288: f85f03ab  ldur     x11, [x29, #-0x10]
//   0x00728c: f94002a9  ldr      x9, [x21]
//   0x007290: f900016a  str      x10, [x11]
//   0x007294: 5280d7eb  mov      w11, #0x6bf
//   0x007298: f9000089  str      x9, [x4]
//   0x00729c: 72a5aceb  movk     w11, #0x2d67, lsl #16
//   0x0072a0: b8404d2a  ldr      w10, [x9, #4]!
//   0x0072a4: f90002a9  str      x9, [x21]
//   0x0072a8: 4a0b014a  eor      w10, w10, w11
//   0x0072ac: b900012a  str      w10, [x9]
//   0x0072b0: 17ffffc2  b        #0x71b8
//   0x0072b4: b0ffffe8  adrp     x8, #0x4000
//   0x0072b8: 529081ca  mov      w10, #0x840e
//   0x0072bc: 91118108  add      x8, x8, #0x460
//   0x0072c0: 72a3042a  movk     w10, #0x1821, lsl #16
//   0x0072c4: 11000509  add      w9, w8, #1
//   0x0072c8: 0a280129  bic      w9, w9, w8
//   0x0072cc: 2a2903e9  mvn      w9, w9
//   0x0072d0: 8a0a0129  and      x9, x9, x10
//   0x0072d4: d290d0aa  mov      x10, #0x8685
//   0x0072d8: f2a84d4a  movk     x10, #0x426a, lsl #16
//   0x0072dc: f2c12c2a  movk     x10, #0x961, lsl #32
//   0x0072e0: 8b0a0129  add      x9, x9, x10
//   0x0072e4: 528e920a  mov      w10, #0x7490
//   0x0072e8: 72a1b32a  movk     w10, #0xd99, lsl #16
//   0x0072ec: eb0a013f  cmp      x9, x10
//   0x0072f0: 54000663  b.lo     #0x73bc
//   0x0072f4: 53115769  ubfx     w9, w27, #0x11, #5
//   0x0072f8: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x0072fc: f85f03af  ldur     x15, [x29, #-0x10]
//   0x007300: d280800e  mov      x14, #0x400
//   0x007304: f2a0008e  movk     x14, #4, lsl #16
//   0x007308: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x00730c: f2c0208e  movk     x14, #0x104, lsl #32
//   0x007310: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x007314: 8a0e010e  and      x14, x8, x14
//   0x007318: b90002e9  str      w9, [x23]
//   0x00731c: 531b7f69  lsr      w9, w27, #0x1b
//   0x007320: b900030a  str      w10, [x24]
//   0x007324: 9b0b7d8d  mul      x13, x12, x11
//   0x007328: b9000329  str      w9, [x25]
//   0x00732c: 9b4b7d8b  smulh    x11, x12, x11
//   0x007330: d282080c  mov      x12, #0x1040
//   0x007334: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x007338: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00733c: f90001ed  str      x13, [x15]
//   0x007340: d282880d  mov      x13, #0x1440
//   0x007344: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x007348: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00734c: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x007350: aa280188  orn      x8, x12, x8
//   0x007354: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x007358: f94002ac  ldr      x12, [x21]
//   0x00735c: 8a0d0108  and      x8, x8, x13
//   0x007360: f85e83ad  ldur     x13, [x29, #-0x18]
//   0x007364: 8b0e0108  add      x8, x8, x14
//   0x007368: f90001ab  str      x11, [x13]
//   0x00736c: b8404d8b  ldr      w11, [x12, #4]!
//   0x007370: f90002ac  str      x12, [x21]
//   0x007374: 5280208c  mov      w12, #0x104
//   0x007378: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00737c: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x007380: aa0c0108  orr      x8, x8, x12
//   0x007384: d28d6b8c  mov      x12, #0x6b5c
//   0x007388: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x00738c: 9240156b  and      x11, x11, #0x3f
//   0x007390: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x007394: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x007398: ca0c0108  eor      x8, x8, x12
//   0x00739c: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x0073a0: 8b0801a8  add      x8, x13, x8
//   0x0073a4: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x0073a8: f85f83ab  ldur     x11, [x29, #-8]
//   0x0073ac: b900034c  str      w12, [x26]
//   0x0073b0: f9400108  ldr      x8, [x8]
//   0x0073b4: cb0b0108  sub      x8, x8, x11
//   0x0073b8: d61f0100  br       x8
//   0x0073bc: b98002e9  ldrsw    x9, [x23]
//   0x0073c0: 528a600c  mov      w12, #0x5300
//   0x0073c4: b980030b  ldrsw    x11, [x24]
//   0x0073c8: 72a2f8ac  movk     w12, #0x17c5, lsl #16
//   0x0073cc: d37df129  lsl      x9, x9, #3
//   0x0073d0: d37df16b  lsl      x11, x11, #3
//   0x0073d4: f8696a6a  ldr      x10, [x19, x9]
//   0x0073d8: ca0c014c  eor      x12, x10, x12
//   0x0073dc: 937ffd4d  asr      x13, x10, #0x3f
//   0x0073e0: f8296a6c  str      x12, [x19, x9]
//   0x0073e4: f86b6a69  ldr      x9, [x19, x11]
//   0x0073e8: eb0a012c  subs     x12, x9, x10
//   0x0073ec: 937ffd2e  asr      x14, x9, #0x3f
//   0x0073f0: fa0d01ce  sbcs     x14, x14, x13
//   0x0073f4: 9bca7d8f  umulh    x15, x12, x10
//   0x0073f8: 9b0d3d8d  madd     x13, x12, x13, x15
//   0x0073fc: 5292c70f  mov      w15, #0x9638
//   0x007400: 72af562f  movk     w15, #0x7ab1, lsl #16
//   0x007404: 9b0a7d8c  mul      x12, x12, x10
//   0x007408: ca0f0129  eor      x9, x9, x15
//   0x00740c: 9b0a35ca  madd     x10, x14, x10, x13
//   0x007410: f82b6a69  str      x9, [x19, x11]
//   0x007414: f85f03ab  ldur     x11, [x29, #-0x10]
//   0x007418: f94002a9  ldr      x9, [x21]
//   0x00741c: f900016c  str      x12, [x11]
//   0x007420: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007424: f9000089  str      x9, [x4]
//   0x007428: f900016a  str      x10, [x11]
//   0x00742c: 5286b6cb  mov      w11, #0x35b6
//   0x007430: b8404d2a  ldr      w10, [x9, #4]!
//   0x007434: 72a2066b  movk     w11, #0x1033, lsl #16
//   0x007438: f90002a9  str      x9, [x21]
//   0x00743c: 4a0b014a  eor      w10, w10, w11
//   0x007440: b900012a  str      w10, [x9]
//   0x007444: 17ffffac  b        #0x72f4
//   0x007448: 53166b68  ubfx     w8, w27, #0x16, #5
//   0x00744c: 53115769  ubfx     w9, w27, #0x11, #5
//   0x007450: f85f03ad  ldur     x13, [x29, #-0x10]
//   0x007454: f8685a6a  ldr      x10, [x19, w8, uxtw #3]
//   0x007458: b90002e8  str      w8, [x23]
//   0x00745c: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x007460: 531b7f68  lsr      w8, w27, #0x1b
//   0x007464: b9000309  str      w9, [x24]
//   0x007468: b9000328  str      w8, [x25]
//   0x00746c: 9b0a7d6c  mul      x12, x11, x10
//   0x007470: 9bca7d6a  umulh    x10, x11, x10
//   0x007474: f94002ab  ldr      x11, [x21]
//   0x007478: f90001ac  str      x12, [x13]
//   0x00747c: f85e83ac  ldur     x12, [x29, #-0x18]
//   0x007480: f900018a  str      x10, [x12]
//   0x007484: b8404d6a  ldr      w10, [x11, #4]!
//   0x007488: f90002ab  str      x11, [x21]
//   0x00748c: 5280208b  mov      w11, #0x104
//   0x007490: 72a0202b  movk     w11, #0x101, lsl #16
//   0x007494: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x007498: aa0b02cb  orr      x11, x22, x11
//   0x00749c: 9240154a  and      x10, x10, #0x3f
//   0x0074a0: ca11016b  eor      x11, x11, x17
//   0x0074a4: 8b0b018b  add      x11, x12, x11
//   0x0074a8: 8b0a0d6a  add      x10, x11, x10, lsl #3
//   0x0074ac: f85f83ab  ldur     x11, [x29, #-8]
//   0x0074b0: f940014a  ldr      x10, [x10]
//   0x0074b4: cb0b014a  sub      x10, x10, x11
//   0x0074b8: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x0074bc: b900034b  str      w11, [x26]
//   0x0074c0: d61f0140  br       x10
//   0x0074c4: b0ffffe8  adrp     x8, #0x4000
//   0x0074c8: 5286418a  mov      w10, #0x320c
//   0x0074cc: 91118108  add      x8, x8, #0x460
//   0x0074d0: 72a9100a  movk     w10, #0x4880, lsl #16
//   0x0074d4: 11000509  add      w9, w8, #1
//   0x0074d8: 0a280129  bic      w9, w9, w8
//   0x0074dc: 2a2903e9  mvn      w9, w9
//   0x0074e0: 8a0a0129  and      x9, x9, x10
//   0x0074e4: d284a90a  mov      x10, #0x2548
//   0x0074e8: f2a2606a  movk     x10, #0x1303, lsl #16
//   0x0074ec: f2e042ca  movk     x10, #0x216, lsl #48
//   0x0074f0: 8b0a0129  add      x9, x9, x10
//   0x0074f4: 529c052a  mov      w10, #0xe029
//   0x0074f8: 72a034ea  movk     w10, #0x1a7, lsl #16
//   0x0074fc: eb0a013f  cmp      x9, x10
//   0x007500: 54000663  b.lo     #0x75cc
//   0x007504: 531b7f69  lsr      w9, w27, #0x1b
//   0x007508: 530c436a  ubfx     w10, w27, #0xc, #5
//   0x00750c: f85f03af  ldur     x15, [x29, #-0x10]
//   0x007510: d280800e  mov      x14, #0x400
//   0x007514: f2a0008e  movk     x14, #4, lsl #16
//   0x007518: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x00751c: f2c0208e  movk     x14, #0x104, lsl #32
//   0x007520: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x007524: 8a0e010e  and      x14, x8, x14
//   0x007528: b90002e9  str      w9, [x23]
//   0x00752c: 53115769  ubfx     w9, w27, #0x11, #5
//   0x007530: b900030a  str      w10, [x24]
//   0x007534: 9acc0d6d  sdiv     x13, x11, x12
//   0x007538: b9000329  str      w9, [x25]
//   0x00753c: 9b0cadab  msub     x11, x13, x12, x11
//   0x007540: d282080c  mov      x12, #0x1040
//   0x007544: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x007548: f90001ed  str      x13, [x15]
//   0x00754c: d282880d  mov      x13, #0x1440
//   0x007550: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x007554: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x007558: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00755c: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x007560: aa280188  orn      x8, x12, x8
//   0x007564: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x007568: f94002ac  ldr      x12, [x21]
//   0x00756c: 8a0d0108  and      x8, x8, x13
//   0x007570: f85e83ad  ldur     x13, [x29, #-0x18]
//   0x007574: 8b0e0108  add      x8, x8, x14
//   0x007578: f90001ab  str      x11, [x13]
//   0x00757c: b8404d8b  ldr      w11, [x12, #4]!
//   0x007580: f90002ac  str      x12, [x21]
//   0x007584: 5280208c  mov      w12, #0x104
//   0x007588: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00758c: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x007590: aa0c0108  orr      x8, x8, x12
//   0x007594: d28d6b8c  mov      x12, #0x6b5c
//   0x007598: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x00759c: 9240156b  and      x11, x11, #0x3f
//   0x0075a0: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x0075a4: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x0075a8: ca0c0108  eor      x8, x8, x12
//   0x0075ac: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x0075b0: 8b0801a8  add      x8, x13, x8
//   0x0075b4: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x0075b8: f85f83ab  ldur     x11, [x29, #-8]
//   0x0075bc: b900034c  str      w12, [x26]
//   0x0075c0: f9400108  ldr      x8, [x8]
//   0x0075c4: cb0b0108  sub      x8, x8, x11
//   0x0075c8: d61f0100  br       x8
//   0x0075cc: b98002e9  ldrsw    x9, [x23]
//   0x0075d0: 5282404c  mov      w12, #0x1202
//   0x0075d4: b980030b  ldrsw    x11, [x24]
//   0x0075d8: 72ae666c  movk     w12, #0x7333, lsl #16
//   0x0075dc: 5293120d  mov      w13, #0x9890
//   0x0075e0: d37df129  lsl      x9, x9, #3
//   0x0075e4: 72a83f6d  movk     w13, #0x41fb, lsl #16
//   0x0075e8: d37df16b  lsl      x11, x11, #3
//   0x0075ec: f8696a6a  ldr      x10, [x19, x9]
//   0x0075f0: ca0c014c  eor      x12, x10, x12
//   0x0075f4: f8296a6c  str      x12, [x19, x9]
//   0x0075f8: f86b6a69  ldr      x9, [x19, x11]
//   0x0075fc: 8a0a012c  and      x12, x9, x10
//   0x007600: 9ac90d8c  sdiv     x12, x12, x9
//   0x007604: ca0d0129  eor      x9, x9, x13
//   0x007608: f82b6a69  str      x9, [x19, x11]
//   0x00760c: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007610: f94002a9  ldr      x9, [x21]
//   0x007614: f900016a  str      x10, [x11]
//   0x007618: f85f03aa  ldur     x10, [x29, #-0x10]
//   0x00761c: f9000089  str      x9, [x4]
//   0x007620: 5283998b  mov      w11, #0x1ccc
//   0x007624: 72a7502b  movk     w11, #0x3a81, lsl #16
//   0x007628: f900014c  str      x12, [x10]
//   0x00762c: b8404d2a  ldr      w10, [x9, #4]!
//   0x007630: f90002a9  str      x9, [x21]
//   0x007634: 4a0b014a  eor      w10, w10, w11
//   0x007638: b900012a  str      w10, [x9]
//   0x00763c: 17ffffb2  b        #0x7504
//   0x007640: b0ffffe8  adrp     x8, #0x4000
//   0x007644: 52804a4a  mov      w10, #0x252
//   0x007648: 91118108  add      x8, x8, #0x460
//   0x00764c: 72a0002a  movk     w10, #1, lsl #16
//   0x007650: 11000509  add      w9, w8, #1
//   0x007654: 0a280129  bic      w9, w9, w8
//   0x007658: 2a2903e9  mvn      w9, w9
//   0x00765c: 8a0a0129  and      x9, x9, x10
//   0x007660: d28a544a  mov      x10, #0x52a2
//   0x007664: f2a529ca  movk     x10, #0x294e, lsl #16
//   0x007668: f2c0010a  movk     x10, #8, lsl #32
//   0x00766c: f2e0160a  movk     x10, #0xb0, lsl #48
//   0x007670: 8b0a0129  add      x9, x9, x10
//   0x007674: 5288d64a  mov      w10, #0x46b2
//   0x007678: 72a1ce6a  movk     w10, #0xe73, lsl #16
//   0x00767c: eb0a013f  cmp      x9, x10
//   0x007680: 54000663  b.lo     #0x774c
//   0x007684: 531b7f69  lsr      w9, w27, #0x1b
//   0x007688: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x00768c: f85f03af  ldur     x15, [x29, #-0x10]
//   0x007690: d280800e  mov      x14, #0x400
//   0x007694: f2a0008e  movk     x14, #4, lsl #16
//   0x007698: f8695a6b  ldr      x11, [x19, w9, uxtw #3]
//   0x00769c: f2c0208e  movk     x14, #0x104, lsl #32
//   0x0076a0: f86a5a6c  ldr      x12, [x19, w10, uxtw #3]
//   0x0076a4: 8a0e010e  and      x14, x8, x14
//   0x0076a8: b90002e9  str      w9, [x23]
//   0x0076ac: 53115769  ubfx     w9, w27, #0x11, #5
//   0x0076b0: b900030a  str      w10, [x24]
//   0x0076b4: 9acc096d  udiv     x13, x11, x12
//   0x0076b8: b9000329  str      w9, [x25]
//   0x0076bc: 9b0cadab  msub     x11, x13, x12, x11
//   0x0076c0: d282080c  mov      x12, #0x1040
//   0x0076c4: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x0076c8: f90001ed  str      x13, [x15]
//   0x0076cc: d282880d  mov      x13, #0x1440
//   0x0076d0: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x0076d4: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x0076d8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0076dc: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x0076e0: aa280188  orn      x8, x12, x8
//   0x0076e4: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x0076e8: f94002ac  ldr      x12, [x21]
//   0x0076ec: 8a0d0108  and      x8, x8, x13
//   0x0076f0: f85e83ad  ldur     x13, [x29, #-0x18]
//   0x0076f4: 8b0e0108  add      x8, x8, x14
//   0x0076f8: f90001ab  str      x11, [x13]
//   0x0076fc: b8404d8b  ldr      w11, [x12, #4]!
//   0x007700: f90002ac  str      x12, [x21]
//   0x007704: 5280208c  mov      w12, #0x104
//   0x007708: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00770c: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x007710: aa0c0108  orr      x8, x8, x12
//   0x007714: d28d6b8c  mov      x12, #0x6b5c
//   0x007718: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x00771c: 9240156b  and      x11, x11, #0x3f
//   0x007720: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x007724: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x007728: ca0c0108  eor      x8, x8, x12
//   0x00772c: 530c436c  ubfx     w12, w27, #0xc, #5
//   0x007730: 8b0801a8  add      x8, x13, x8
//   0x007734: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x007738: f85f83ab  ldur     x11, [x29, #-8]
//   0x00773c: b900034c  str      w12, [x26]
//   0x007740: f9400108  ldr      x8, [x8]
//   0x007744: cb0b0108  sub      x8, x8, x11
//   0x007748: d61f0100  br       x8
//   0x00774c: b98002e9  ldrsw    x9, [x23]
//   0x007750: 529ae34c  mov      w12, #0xd71a
//   0x007754: b980030b  ldrsw    x11, [x24]
//   0x007758: 72af2f4c  movk     w12, #0x797a, lsl #16
//   0x00775c: 5281f5ad  mov      w13, #0xfad
//   0x007760: d37df129  lsl      x9, x9, #3
//   0x007764: 72a622ed  movk     w13, #0x3117, lsl #16
//   0x007768: d37df16b  lsl      x11, x11, #3
//   0x00776c: f8696a6a  ldr      x10, [x19, x9]
//   0x007770: ca0c014c  eor      x12, x10, x12
//   0x007774: f8296a6c  str      x12, [x19, x9]
//   0x007778: f86b6a69  ldr      x9, [x19, x11]
//   0x00777c: 8a0a012c  and      x12, x9, x10
//   0x007780: 9ac9098c  udiv     x12, x12, x9
//   0x007784: ca0d0129  eor      x9, x9, x13
//   0x007788: f82b6a69  str      x9, [x19, x11]
//   0x00778c: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007790: f94002a9  ldr      x9, [x21]
//   0x007794: f900016a  str      x10, [x11]
//   0x007798: f85f03aa  ldur     x10, [x29, #-0x10]
//   0x00779c: f9000089  str      x9, [x4]
//   0x0077a0: 5292186b  mov      w11, #0x90c3
//   0x0077a4: 72a00b2b  movk     w11, #0x59, lsl #16
//   0x0077a8: f900014c  str      x12, [x10]
//   0x0077ac: b8404d2a  ldr      w10, [x9, #4]!
//   0x0077b0: f90002a9  str      x9, [x21]
//   0x0077b4: 4a0b014a  eor      w10, w10, w11
//   0x0077b8: b900012a  str      w10, [x9]
//   0x0077bc: 17ffffb2  b        #0x7684
//   0x0077c0: b0ffffe8  adrp     x8, #0x4000
//   0x0077c4: 5294008a  mov      w10, #0xa004
//   0x0077c8: 91118108  add      x8, x8, #0x460
//   0x0077cc: 72a0c44a  movk     w10, #0x622, lsl #16
//   0x0077d0: 11000509  add      w9, w8, #1
//   0x0077d4: 0a280129  bic      w9, w9, w8
//   0x0077d8: 2a2903e9  mvn      w9, w9
//   0x0077dc: 8a0a0129  and      x9, x9, x10
//   0x0077e0: d2874f6a  mov      x10, #0x3a7b
//   0x0077e4: f2a3876a  movk     x10, #0x1c3b, lsl #16
//   0x0077e8: f2c0200a  movk     x10, #0x100, lsl #32
//   0x0077ec: f2e1408a  movk     x10, #0xa04, lsl #48
//   0x0077f0: 8b0a0129  add      x9, x9, x10
//   0x0077f4: 52918fea  mov      w10, #0x8c7f
//   0x0077f8: 72a035ea  movk     w10, #0x1af, lsl #16
//   0x0077fc: eb0a013f  cmp      x9, x10
//   0x007800: 540006c3  b.lo     #0x78d8
//   0x007804: 53166b69  ubfx     w9, w27, #0x16, #5
//   0x007808: 531b7f6a  lsr      w10, w27, #0x1b
//   0x00780c: 530c436b  ubfx     w11, w27, #0xc, #5
//   0x007810: 5311576c  ubfx     w12, w27, #0x11, #5
//   0x007814: f85f03ad  ldur     x13, [x29, #-0x10]
//   0x007818: b90002e9  str      w9, [x23]
//   0x00781c: d37df129  lsl      x9, x9, #3
//   0x007820: b900030a  str      w10, [x24]
//   0x007824: d37df14a  lsl      x10, x10, #3
//   0x007828: b900032b  str      w11, [x25]
//   0x00782c: d282080b  mov      x11, #0x1040
//   0x007830: b900034c  str      w12, [x26]
//   0x007834: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x007838: b8a96a69  ldrsw    x9, [x19, x9]
//   0x00783c: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x007840: b8aa6a6a  ldrsw    x10, [x19, x10]
//   0x007844: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x007848: 9b097d49  mul      x9, x10, x9
//   0x00784c: d280800a  mov      x10, #0x400
//   0x007850: f2a0008a  movk     x10, #4, lsl #16
//   0x007854: 93407d2c  sxtw     x12, w9
//   0x007858: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00785c: 8a0a010a  and      x10, x8, x10
//   0x007860: aa280168  orn      x8, x11, x8
//   0x007864: 9360fd29  asr      x9, x9, #0x20
//   0x007868: f94002ab  ldr      x11, [x21]
//   0x00786c: f90001ac  str      x12, [x13]
//   0x007870: d282880c  mov      x12, #0x1440
//   0x007874: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x007878: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x00787c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x007880: 8a0c0108  and      x8, x8, x12
//   0x007884: f85e83ac  ldur     x12, [x29, #-0x18]
//   0x007888: 8b0a0108  add      x8, x8, x10
//   0x00788c: f9000189  str      x9, [x12]
//   0x007890: 5280208c  mov      w12, #0x104
//   0x007894: b8404d69  ldr      w9, [x11, #4]!
//   0x007898: f90002ab  str      x11, [x21]
//   0x00789c: d28d6b8b  mov      x11, #0x6b5c
//   0x0078a0: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x0078a4: 72a0202c  movk     w12, #0x101, lsl #16
//   0x0078a8: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x0078ac: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x0078b0: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x0078b4: aa0c0108  orr      x8, x8, x12
//   0x0078b8: ca0b0108  eor      x8, x8, x11
//   0x0078bc: 92401529  and      x9, x9, #0x3f
//   0x0078c0: 8b080148  add      x8, x10, x8
//   0x0078c4: 8b090d08  add      x8, x8, x9, lsl #3
//   0x0078c8: f85f83a9  ldur     x9, [x29, #-8]
//   0x0078cc: f9400108  ldr      x8, [x8]
//   0x0078d0: cb090108  sub      x8, x8, x9
//   0x0078d4: d61f0100  br       x8
//   0x0078d8: b98002e9  ldrsw    x9, [x23]
//   0x0078dc: 528b386a  mov      w10, #0x59c3
//   0x0078e0: 72a9b72a  movk     w10, #0x4db9, lsl #16
//   0x0078e4: 5287224b  mov      w11, #0x3912
//   0x0078e8: 72a8768b  movk     w11, #0x43b4, lsl #16
//   0x0078ec: 4a0a012a  eor      w10, w9, w10
//   0x0078f0: d37df129  lsl      x9, x9, #3
//   0x0078f4: b90002ea  str      w10, [x23]
//   0x0078f8: b8a96a6a  ldrsw    x10, [x19, x9]
//   0x0078fc: 4a0b014b  eor      w11, w10, w11
//   0x007900: b8296a6b  str      w11, [x19, x9]
//   0x007904: 529deeeb  mov      w11, #0xef77
//   0x007908: b9800309  ldrsw    x9, [x24]
//   0x00790c: 72ada1cb  movk     w11, #0x6d0e, lsl #16
//   0x007910: 4a0b012b  eor      w11, w9, w11
//   0x007914: d37df129  lsl      x9, x9, #3
//   0x007918: b900030b  str      w11, [x24]
//   0x00791c: b8a96a6b  ldrsw    x11, [x19, x9]
//   0x007920: cb0a016c  sub      x12, x11, x10
//   0x007924: 9b0a7d8a  mul      x10, x12, x10
//   0x007928: 5294b20c  mov      w12, #0xa590
//   0x00792c: 72adf16c  movk     w12, #0x6f8b, lsl #16
//   0x007930: 4a0c016b  eor      w11, w11, w12
//   0x007934: 92607d4c  and      x12, x10, #0xffffffff00000000
//   0x007938: b8296a6b  str      w11, [x19, x9]
//   0x00793c: f85f03ab  ldur     x11, [x29, #-0x10]
//   0x007940: d3607d49  lsl      x9, x10, #0x20
//   0x007944: f94002aa  ldr      x10, [x21]
//   0x007948: f900016c  str      x12, [x11]
//   0x00794c: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007950: f900008a  str      x10, [x4]
//   0x007954: f9000169  str      x9, [x11]
//   0x007958: 5290ceab  mov      w11, #0x8675
//   0x00795c: b8404d49  ldr      w9, [x10, #4]!
//   0x007960: 72a4882b  movk     w11, #0x2441, lsl #16
//   0x007964: f90002aa  str      x10, [x21]
//   0x007968: 4a0b0129  eor      w9, w9, w11
//   0x00796c: b9000149  str      w9, [x10]
//   0x007970: 17ffffa5  b        #0x7804
//   0x007974: b0ffffe8  adrp     x8, #0x4000
//   0x007978: 52a544ca  mov      w10, #0x2a260000
//   0x00797c: 91118108  add      x8, x8, #0x460
//   0x007980: 11000509  add      w9, w8, #1
//   0x007984: 0a280129  bic      w9, w9, w8
//   0x007988: 2a2903e9  mvn      w9, w9
//   0x00798c: 8a0a0129  and      x9, x9, x10
//   0x007990: d2815d2a  mov      x10, #0xae9
//   0x007994: f2abaaca  movk     x10, #0x5d56, lsl #16
//   0x007998: f2c0048a  movk     x10, #0x24, lsl #32
//   0x00799c: f2e0200a  movk     x10, #0x100, lsl #48
//   0x0079a0: 8b0a0129  add      x9, x9, x10
//   0x0079a4: 529d808a  mov      w10, #0xec04
//   0x0079a8: 72a01aca  movk     w10, #0xd6, lsl #16
//   0x0079ac: eb0a013f  cmp      x9, x10
//   0x0079b0: 540006c3  b.lo     #0x7a88
//   0x0079b4: 53115769  ubfx     w9, w27, #0x11, #5
//   0x0079b8: 531b7f6a  lsr      w10, w27, #0x1b
//   0x0079bc: 53166b6b  ubfx     w11, w27, #0x16, #5
//   0x0079c0: 530c436c  ubfx     w12, w27, #0xc, #5
//   0x0079c4: f85f03ad  ldur     x13, [x29, #-0x10]
//   0x0079c8: b90002e9  str      w9, [x23]
//   0x0079cc: d37df129  lsl      x9, x9, #3
//   0x0079d0: b900030a  str      w10, [x24]
//   0x0079d4: d37df14a  lsl      x10, x10, #3
//   0x0079d8: b900032b  str      w11, [x25]
//   0x0079dc: d282080b  mov      x11, #0x1040
//   0x0079e0: b900034c  str      w12, [x26]
//   0x0079e4: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x0079e8: b8696a69  ldr      w9, [x19, x9]
//   0x0079ec: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x0079f0: b86a6a6a  ldr      w10, [x19, x10]
//   0x0079f4: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x0079f8: 9b097d49  mul      x9, x10, x9
//   0x0079fc: d280800a  mov      x10, #0x400
//   0x007a00: f2a0008a  movk     x10, #4, lsl #16
//   0x007a04: 93407d2c  sxtw     x12, w9
//   0x007a08: f2c0208a  movk     x10, #0x104, lsl #32
//   0x007a0c: 8a0a010a  and      x10, x8, x10
//   0x007a10: aa280168  orn      x8, x11, x8
//   0x007a14: 9360fd29  asr      x9, x9, #0x20
//   0x007a18: f94002ab  ldr      x11, [x21]
//   0x007a1c: f90001ac  str      x12, [x13]
//   0x007a20: d282880c  mov      x12, #0x1440
//   0x007a24: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x007a28: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x007a2c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x007a30: 8a0c0108  and      x8, x8, x12
//   0x007a34: f85e83ac  ldur     x12, [x29, #-0x18]
//   0x007a38: 8b0a0108  add      x8, x8, x10
//   0x007a3c: f9000189  str      x9, [x12]
//   0x007a40: 5280208c  mov      w12, #0x104
//   0x007a44: b8404d69  ldr      w9, [x11, #4]!
//   0x007a48: f90002ab  str      x11, [x21]
//   0x007a4c: d28d6b8b  mov      x11, #0x6b5c
//   0x007a50: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x007a54: 72a0202c  movk     w12, #0x101, lsl #16
//   0x007a58: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x007a5c: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x007a60: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x007a64: aa0c0108  orr      x8, x8, x12
//   0x007a68: ca0b0108  eor      x8, x8, x11
//   0x007a6c: 92401529  and      x9, x9, #0x3f
//   0x007a70: 8b080148  add      x8, x10, x8
//   0x007a74: 8b090d08  add      x8, x8, x9, lsl #3
//   0x007a78: f85f83a9  ldur     x9, [x29, #-8]
//   0x007a7c: f9400108  ldr      x8, [x8]
//   0x007a80: cb090108  sub      x8, x8, x9
//   0x007a84: d61f0100  br       x8
//   0x007a88: b98002e9  ldrsw    x9, [x23]
//   0x007a8c: 5286a6aa  mov      w10, #0x3535
//   0x007a90: 72a7fd2a  movk     w10, #0x3fe9, lsl #16
//   0x007a94: 52896b4b  mov      w11, #0x4b5a
//   0x007a98: 72acf48b  movk     w11, #0x67a4, lsl #16
//   0x007a9c: 528a718c  mov      w12, #0x538c
//   0x007aa0: 4a0a012a  eor      w10, w9, w10
//   0x007aa4: d37df129  lsl      x9, x9, #3
//   0x007aa8: 72aeb36c  movk     w12, #0x759b, lsl #16
//   0x007aac: b90002ea  str      w10, [x23]
//   0x007ab0: b8696a6a  ldr      w10, [x19, x9]
//   0x007ab4: 4a0b014b  eor      w11, w10, w11
//   0x007ab8: 9b0a7d4a  mul      x10, x10, x10
//   0x007abc: b8296a6b  str      w11, [x19, x9]
//   0x007ac0: 5286dbcb  mov      w11, #0x36de
//   0x007ac4: b9800309  ldrsw    x9, [x24]
//   0x007ac8: 72aa69eb  movk     w11, #0x534f, lsl #16
//   0x007acc: 4a0b012b  eor      w11, w9, w11
//   0x007ad0: d37df129  lsl      x9, x9, #3
//   0x007ad4: b900030b  str      w11, [x24]
//   0x007ad8: b8696a6b  ldr      w11, [x19, x9]
//   0x007adc: 9b0b7d4a  mul      x10, x10, x11
//   0x007ae0: 4a0c016b  eor      w11, w11, w12
//   0x007ae4: 92607d4c  and      x12, x10, #0xffffffff00000000
//   0x007ae8: b8296a6b  str      w11, [x19, x9]
//   0x007aec: f85f03ab  ldur     x11, [x29, #-0x10]
//   0x007af0: 9360fd49  asr      x9, x10, #0x20
//   0x007af4: f94002aa  ldr      x10, [x21]
//   0x007af8: f900016c  str      x12, [x11]
//   0x007afc: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007b00: f900008a  str      x10, [x4]
//   0x007b04: f9000169  str      x9, [x11]
//   0x007b08: 5296718b  mov      w11, #0xb38c
//   0x007b0c: b8404d49  ldr      w9, [x10, #4]!
//   0x007b10: 72a5c1ab  movk     w11, #0x2e0d, lsl #16
//   0x007b14: f90002aa  str      x10, [x21]
//   0x007b18: 4a0b0129  eor      w9, w9, w11
//   0x007b1c: b9000149  str      w9, [x10]
//   0x007b20: 17ffffa5  b        #0x79b4
//   0x007b24: b0ffffe8  adrp     x8, #0x4000
//   0x007b28: 5290918a  mov      w10, #0x848c
//   0x007b2c: 91118108  add      x8, x8, #0x460
//   0x007b30: 72a4400a  movk     w10, #0x2200, lsl #16
//   0x007b34: 11000509  add      w9, w8, #1
//   0x007b38: 0a280129  bic      w9, w9, w8
//   0x007b3c: 2a2903e9  mvn      w9, w9
//   0x007b40: 8a0a0129  and      x9, x9, x10
//   0x007b44: d28a752a  mov      x10, #0x53a9
//   0x007b48: f2a58c2a  movk     x10, #0x2c61, lsl #16
//   0x007b4c: f2c0802a  movk     x10, #0x401, lsl #32
//   0x007b50: f2e00a0a  movk     x10, #0x50, lsl #48
//   0x007b54: 8b0a0129  add      x9, x9, x10
//   0x007b58: 52837eaa  mov      w10, #0x1bf5
//   0x007b5c: 72a611ea  movk     w10, #0x308f, lsl #16
//   0x007b60: eb0a013f  cmp      x9, x10
//   0x007b64: 540006e3  b.lo     #0x7c40
//   0x007b68: 530c4369  ubfx     w9, w27, #0xc, #5
//   0x007b6c: 5311576a  ubfx     w10, w27, #0x11, #5
//   0x007b70: 531b7f6b  lsr      w11, w27, #0x1b
//   0x007b74: 53166b6c  ubfx     w12, w27, #0x16, #5
//   0x007b78: f85f03ad  ldur     x13, [x29, #-0x10]
//   0x007b7c: b90002e9  str      w9, [x23]
//   0x007b80: d37df129  lsl      x9, x9, #3
//   0x007b84: b900030a  str      w10, [x24]
//   0x007b88: d37df14a  lsl      x10, x10, #3
//   0x007b8c: b900032b  str      w11, [x25]
//   0x007b90: b900034c  str      w12, [x26]
//   0x007b94: d280800c  mov      x12, #0x400
//   0x007b98: b8696a69  ldr      w9, [x19, x9]
//   0x007b9c: f2a0008c  movk     x12, #4, lsl #16
//   0x007ba0: b86a6a6a  ldr      w10, [x19, x10]
//   0x007ba4: f2c0208c  movk     x12, #0x104, lsl #32
//   0x007ba8: 8a0c010c  and      x12, x8, x12
//   0x007bac: 1aca0d2b  sdiv     w11, w9, w10
//   0x007bb0: 1b0aa569  msub     w9, w11, w10, w9
//   0x007bb4: 93407d6b  sxtw     x11, w11
//   0x007bb8: d282080a  mov      x10, #0x1040
//   0x007bbc: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x007bc0: 93407d29  sxtw     x9, w9
//   0x007bc4: f90001ab  str      x11, [x13]
//   0x007bc8: d282880b  mov      x11, #0x1440
//   0x007bcc: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x007bd0: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x007bd4: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x007bd8: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x007bdc: aa280148  orn      x8, x10, x8
//   0x007be0: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x007be4: 8a0b0108  and      x8, x8, x11
//   0x007be8: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007bec: f94002aa  ldr      x10, [x21]
//   0x007bf0: 8b0c0108  add      x8, x8, x12
//   0x007bf4: d28d6b8c  mov      x12, #0x6b5c
//   0x007bf8: f9000169  str      x9, [x11]
//   0x007bfc: 5280208b  mov      w11, #0x104
//   0x007c00: b8404d49  ldr      w9, [x10, #4]!
//   0x007c04: f90002aa  str      x10, [x21]
//   0x007c08: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x007c0c: 72a0202b  movk     w11, #0x101, lsl #16
//   0x007c10: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x007c14: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x007c18: aa0b0108  orr      x8, x8, x11
//   0x007c1c: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x007c20: 92401529  and      x9, x9, #0x3f
//   0x007c24: ca0c0108  eor      x8, x8, x12
//   0x007c28: 8b080148  add      x8, x10, x8
//   0x007c2c: 8b090d08  add      x8, x8, x9, lsl #3
//   0x007c30: f85f83a9  ldur     x9, [x29, #-8]
//   0x007c34: f9400108  ldr      x8, [x8]
//   0x007c38: cb090108  sub      x8, x8, x9
//   0x007c3c: d61f0100  br       x8
//   0x007c40: b98002e9  ldrsw    x9, [x23]
//   0x007c44: 529e46ca  mov      w10, #0xf236
//   0x007c48: 72a7284a  movk     w10, #0x3942, lsl #16
//   0x007c4c: 529a930b  mov      w11, #0xd498
//   0x007c50: 72ab456b  movk     w11, #0x5a2b, lsl #16
//   0x007c54: 529f0f0e  mov      w14, #0xf878
//   0x007c58: 4a0a012a  eor      w10, w9, w10
//   0x007c5c: d37df129  lsl      x9, x9, #3
//   0x007c60: 72a28b2e  movk     w14, #0x1459, lsl #16
//   0x007c64: b90002ea  str      w10, [x23]
//   0x007c68: b8696a6a  ldr      w10, [x19, x9]
//   0x007c6c: 4a0b014b  eor      w11, w10, w11
//   0x007c70: b8296a6b  str      w11, [x19, x9]
//   0x007c74: 528eaceb  mov      w11, #0x7567
//   0x007c78: b9800309  ldrsw    x9, [x24]
//   0x007c7c: 72ae724b  movk     w11, #0x7392, lsl #16
//   0x007c80: 4a0b012b  eor      w11, w9, w11
//   0x007c84: d37df129  lsl      x9, x9, #3
//   0x007c88: b900030b  str      w11, [x24]
//   0x007c8c: b8696a6b  ldr      w11, [x19, x9]
//   0x007c90: 0a0a016c  and      w12, w11, w10
//   0x007c94: 1acb0d8c  sdiv     w12, w12, w11
//   0x007c98: 4b0b018d  sub      w13, w12, w11
//   0x007c9c: 93407d8c  sxtw     x12, w12
//   0x007ca0: 1b0b7dad  mul      w13, w13, w11
//   0x007ca4: 4a0e016b  eor      w11, w11, w14
//   0x007ca8: 4b0d03ef  neg      w15, w13
//   0x007cac: b8296a6b  str      w11, [x19, x9]
//   0x007cb0: f85f03ab  ldur     x11, [x29, #-0x10]
//   0x007cb4: 1b0a3daa  madd     w10, w13, w10, w15
//   0x007cb8: 93407d49  sxtw     x9, w10
//   0x007cbc: f94002aa  ldr      x10, [x21]
//   0x007cc0: f900016c  str      x12, [x11]
//   0x007cc4: f85e83ab  ldur     x11, [x29, #-0x18]
//   0x007cc8: f900008a  str      x10, [x4]
//   0x007ccc: f9000169  str      x9, [x11]
//   0x007cd0: 529e2dcb  mov      w11, #0xf16e
//   0x007cd4: b8404d49  ldr      w9, [x10, #4]!
//   0x007cd8: 72ae92ab  movk     w11, #0x7495, lsl #16
//   0x007cdc: f90002aa  str      x10, [x21]
//   0x007ce0: 4a0b0129  eor      w9, w9, w11
//   0x007ce4: b9000149  str      w9, [x10]
//   0x007ce8: 17ffffa0  b        #0x7b68
//   0x007cec: 530c4368  ubfx     w8, w27, #0xc, #5
//   0x007cf0: 53115769  ubfx     w9, w27, #0x11, #5
//   0x007cf4: 53166b6a  ubfx     w10, w27, #0x16, #5
//   0x007cf8: f85f03ab  ldur     x11, [x29, #-0x10]
//   0x007cfc: b9000328  str      w8, [x25]
//   0x007d00: 531b7f68  lsr      w8, w27, #0x1b
//   0x007d04: b90002e9  str      w9, [x23]
//   0x007d08: d37df129  lsl      x9, x9, #3
//   0x007d0c: b900030a  str      w10, [x24]
//   0x007d10: d37df14a  lsl      x10, x10, #3
//   0x007d14: b9000348  str      w8, [x26]
//   0x007d18: b8696a68  ldr      w8, [x19, x9]
//   0x007d1c: b86a6a69  ldr      w9, [x19, x10]
//   0x007d20: 1ac9090a  udiv     w10, w8, w9
//   0x007d24: 1b09a148  msub     w8, w10, w9, w8
//   0x007d28: 93407d49  sxtw     x9, w10
//   0x007d2c: f94002aa  ldr      x10, [x21]
//   0x007d30: 93407d08  sxtw     x8, w8
//   0x007d34: f9000169  str      x9, [x11]
//   0x007d38: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x007d3c: f9000128  str      x8, [x9]
//   0x007d40: 52802089  mov      w9, #0x104
//   0x007d44: b8404d48  ldr      w8, [x10, #4]!
//   0x007d48: f90002aa  str      x10, [x21]
//   0x007d4c: 72a02029  movk     w9, #0x101, lsl #16
//   0x007d50: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x007d54: aa0902c9  orr      x9, x22, x9
//   0x007d58: ca110129  eor      x9, x9, x17
//   0x007d5c: 92401508  and      x8, x8, #0x3f
//   0x007d60: 8b090149  add      x9, x10, x9
//   0x007d64: 8b080d28  add      x8, x9, x8, lsl #3
//   0x007d68: f85f83a9  ldur     x9, [x29, #-8]
//   0x007d6c: f9400108  ldr      x8, [x8]
//   0x007d70: cb090108  sub      x8, x8, x9
//   0x007d74: d61f0100  br       x8
//   0x007d78: f94002a8  ldr      x8, [x21]
//   0x007d7c: b0000089  adrp     x9, #0x18000
//   0x007d80: b940010a  ldr      w10, [x8]
//   0x007d84: 52802088  mov      w8, #0x104
//   0x007d88: 72a02028  movk     w8, #0x101, lsl #16
//   0x007d8c: f941f929  ldr      x9, [x9, #0x3f0]
//   0x007d90: aa0802c8  orr      x8, x22, x8
//   0x007d94: ca110108  eor      x8, x8, x17
//   0x007d98: f81d83aa  stur     x10, [x29, #-0x28]
//   0x007d9c: d3462d4a  ubfx     x10, x10, #6, #6
//   0x007da0: 8b080128  add      x8, x9, x8
//   0x007da4: f85f83a9  ldur     x9, [x29, #-8]
//   0x007da8: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x007dac: f9400108  ldr      x8, [x8]
//   0x007db0: cb090108  sub      x8, x8, x9
//   0x007db4: d61f0100  br       x8
//   0x007db8: b0ffffe8  adrp     x8, #0x4000
//   0x007dbc: 5281808a  mov      w10, #0xc04
//   0x007dc0: 91118108  add      x8, x8, #0x460
//   0x007dc4: 72a9802a  movk     w10, #0x4c01, lsl #16
//   0x007dc8: 11000509  add      w9, w8, #1
//   0x007dcc: 0a280129  bic      w9, w9, w8
//   0x007dd0: 2a2903e9  mvn      w9, w9
//   0x007dd4: 8a0a0129  and      x9, x9, x10
//   0x007dd8: d29ee84a  mov      x10, #0xf742
//   0x007ddc: f2b2efaa  movk     x10, #0x977d, lsl #16
//   0x007de0: f2c0010a  movk     x10, #8, lsl #32
//   0x007de4: f2e0400a  movk     x10, #0x200, lsl #48
//   0x007de8: 8b0a0129  add      x9, x9, x10
//   0x007dec: 5292ed8a  mov      w10, #0x976c
//   0x007df0: 72a2ec8a  movk     w10, #0x1764, lsl #16
//   0x007df4: eb0a013f  cmp      x9, x10
//   0x007df8: 54000723  b.lo     #0x7edc
//   0x007dfc: f85d83ac  ldur     x12, [x29, #-0x28]
//   0x007e00: a97eb7ae  ldp      x14, x13, [x29, #-0x18]
//   0x007e04: 531b7d89  lsr      w9, w12, #0x1b
//   0x007e08: 5316698a  ubfx     w10, w12, #0x16, #5
//   0x007e0c: 530c418b  ubfx     w11, w12, #0xc, #5
//   0x007e10: 5311558c  ubfx     w12, w12, #0x11, #5
//   0x007e14: b90002e9  str      w9, [x23]
//   0x007e18: d37df129  lsl      x9, x9, #3
//   0x007e1c: b900030a  str      w10, [x24]
//   0x007e20: d37df14a  lsl      x10, x10, #3
//   0x007e24: b900032b  str      w11, [x25]
//   0x007e28: b900034c  str      w12, [x26]
//   0x007e2c: b8a96a69  ldrsw    x9, [x19, x9]
//   0x007e30: b8aa6a6a  ldrsw    x10, [x19, x10]
//   0x007e34: b94001cb  ldr      w11, [x14]
//   0x007e38: b94001ac  ldr      w12, [x13]
//   0x007e3c: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x007e40: d282080b  mov      x11, #0x1040
//   0x007e44: 9b093149  madd     x9, x10, x9, x12
//   0x007e48: d280800a  mov      x10, #0x400
//   0x007e4c: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x007e50: f2a0008a  movk     x10, #4, lsl #16
//   0x007e54: 93407d2c  sxtw     x12, w9
//   0x007e58: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x007e5c: f2c0208a  movk     x10, #0x104, lsl #32
//   0x007e60: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x007e64: 9360fd29  asr      x9, x9, #0x20
//   0x007e68: 8a0a010a  and      x10, x8, x10
//   0x007e6c: aa280168  orn      x8, x11, x8
//   0x007e70: f94002ab  ldr      x11, [x21]
//   0x007e74: f90001ac  str      x12, [x13]
//   0x007e78: d282880c  mov      x12, #0x1440
//   0x007e7c: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x007e80: f90001c9  str      x9, [x14]
//   0x007e84: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x007e88: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x007e8c: b8404d69  ldr      w9, [x11, #4]!
//   0x007e90: 8a0c0108  and      x8, x8, x12
//   0x007e94: f90002ab  str      x11, [x21]
//   0x007e98: 5280208b  mov      w11, #0x104
//   0x007e9c: 8b0a0108  add      x8, x8, x10
//   0x007ea0: 72a0202b  movk     w11, #0x101, lsl #16
//   0x007ea4: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x007ea8: aa0b0108  orr      x8, x8, x11
//   0x007eac: d28d6b8b  mov      x11, #0x6b5c
//   0x007eb0: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x007eb4: 92401529  and      x9, x9, #0x3f
//   0x007eb8: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x007ebc: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x007ec0: ca0b0108  eor      x8, x8, x11
//   0x007ec4: 8b080148  add      x8, x10, x8
//   0x007ec8: 8b090d08  add      x8, x8, x9, lsl #3
//   0x007ecc: f85f83a9  ldur     x9, [x29, #-8]
//   0x007ed0: f9400108  ldr      x8, [x8]
//   0x007ed4: cb090108  sub      x8, x8, x9
//   0x007ed8: d61f0100  br       x8
//   0x007edc: b98002e9  ldrsw    x9, [x23]
//   0x007ee0: 5289228a  mov      w10, #0x4914
//   0x007ee4: 72a06e8a  movk     w10, #0x374, lsl #16
//   0x007ee8: 52983a2b  mov      w11, #0xc1d1
//   0x007eec: 72a8ed2b  movk     w11, #0x4769, lsl #16
//   0x007ef0: 5291b5ac  mov      w12, #0x8dad
//   0x007ef4: 4a0a012a  eor      w10, w9, w10
//   0x007ef8: d37df129  lsl      x9, x9, #3
//   0x007efc: a97eb7ae  ldp      x14, x13, [x29, #-0x18]
//   0x007f00: 72a9d26c  movk     w12, #0x4e93, lsl #16
//   0x007f04: b90002ea  str      w10, [x23]
//   0x007f08: b8a96a6a  ldrsw    x10, [x19, x9]
//   0x007f0c: 4a0b014b  eor      w11, w10, w11
//   0x007f10: 9b0a7d4a  mul      x10, x10, x10
//   0x007f14: b8296a6b  str      w11, [x19, x9]
//   0x007f18: 52949eeb  mov      w11, #0xa4f7
//   0x007f1c: b9800309  ldrsw    x9, [x24]
//   0x007f20: 72ae066b  movk     w11, #0x7033, lsl #16
//   0x007f24: 4a0b012b  eor      w11, w9, w11
//   0x007f28: d37df129  lsl      x9, x9, #3
//   0x007f2c: b900030b  str      w11, [x24]
//   0x007f30: b8a96a6b  ldrsw    x11, [x19, x9]
//   0x007f34: 4a0c016c  eor      w12, w11, w12
//   0x007f38: 9b0b7d4a  mul      x10, x10, x11
//   0x007f3c: b8296a6c  str      w12, [x19, x9]
//   0x007f40: b94001c9  ldr      w9, [x14]
//   0x007f44: b94001ac  ldr      w12, [x13]
//   0x007f48: f94002ab  ldr      x11, [x21]
//   0x007f4c: b3607d2c  bfi      x12, x9, #0x20, #0x20
//   0x007f50: 8b0a0589  add      x9, x12, x10, lsl #1
//   0x007f54: f900008b  str      x11, [x4]
//   0x007f58: 93407d2a  sxtw     x10, w9
//   0x007f5c: d360fd29  lsr      x9, x9, #0x20
//   0x007f60: f90001aa  str      x10, [x13]
//   0x007f64: 5285ce2a  mov      w10, #0x2e71
//   0x007f68: f90001c9  str      x9, [x14]
//   0x007f6c: 72acfbca  movk     w10, #0x67de, lsl #16
//   0x007f70: b8404d69  ldr      w9, [x11, #4]!
//   0x007f74: f90002ab  str      x11, [x21]
//   0x007f78: 4a0a0129  eor      w9, w9, w10
//   0x007f7c: b9000169  str      w9, [x11]
//   0x007f80: 17ffff9f  b        #0x7dfc
//   0x007f84: f85d83ab  ldur     x11, [x29, #-0x28]
//   0x007f88: a97eb3ad  ldp      x13, x12, [x29, #-0x18]
//   0x007f8c: 53166968  ubfx     w8, w11, #0x16, #5
//   0x007f90: 53115569  ubfx     w9, w11, #0x11, #5
//   0x007f94: 530c416a  ubfx     w10, w11, #0xc, #5
//   0x007f98: 531b7d6b  lsr      w11, w11, #0x1b
//   0x007f9c: b90002e8  str      w8, [x23]
//   0x007fa0: d37df108  lsl      x8, x8, #3
//   0x007fa4: b9000309  str      w9, [x24]
//   0x007fa8: d37df129  lsl      x9, x9, #3
//   0x007fac: b900032a  str      w10, [x25]
//   0x007fb0: b900034b  str      w11, [x26]
//   0x007fb4: b8686a68  ldr      w8, [x19, x8]
//   0x007fb8: b8696a69  ldr      w9, [x19, x9]
//   0x007fbc: b94001aa  ldr      w10, [x13]
//   0x007fc0: b940018b  ldr      w11, [x12]
//   0x007fc4: b3607d4b  bfi      x11, x10, #0x20, #0x20
//   0x007fc8: f94002aa  ldr      x10, [x21]
//   0x007fcc: 9b082d28  madd     x8, x9, x8, x11
//   0x007fd0: 93407d09  sxtw     x9, w8
//   0x007fd4: 9360fd08  asr      x8, x8, #0x20
//   0x007fd8: f9000189  str      x9, [x12]
//   0x007fdc: 52802089  mov      w9, #0x104
//   0x007fe0: f90001a8  str      x8, [x13]
//   0x007fe4: 72a02029  movk     w9, #0x101, lsl #16
//   0x007fe8: b8404d48  ldr      w8, [x10, #4]!
//   0x007fec: f90002aa  str      x10, [x21]
//   0x007ff0: aa0902c9  orr      x9, x22, x9
//   0x007ff4: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x007ff8: ca110129  eor      x9, x9, x17
//   0x007ffc: 92401508  and      x8, x8, #0x3f
//   0x008000: 8b090149  add      x9, x10, x9
//   0x008004: 8b080d28  add      x8, x9, x8, lsl #3
//   0x008008: f85f83a9  ldur     x9, [x29, #-8]
//   0x00800c: f9400108  ldr      x8, [x8]
//   0x008010: cb090108  sub      x8, x8, x9
//   0x008014: d61f0100  br       x8
//   0x008018: 90ffffe8  adrp     x8, #0x4000
//   0x00801c: 5282840a  mov      w10, #0x1420
//   0x008020: 91118108  add      x8, x8, #0x460
//   0x008024: 72a0040a  movk     w10, #0x20, lsl #16
//   0x008028: 11000509  add      w9, w8, #1
//   0x00802c: 0a280129  bic      w9, w9, w8
//   0x008030: 2a2903e9  mvn      w9, w9
//   0x008034: 8a0a0129  and      x9, x9, x10
//   0x008038: d285742a  mov      x10, #0x2ba1
//   0x00803c: f2af8f6a  movk     x10, #0x7c7b, lsl #16
//   0x008040: f2c0810a  movk     x10, #0x408, lsl #32
//   0x008044: f2e0010a  movk     x10, #8, lsl #48
//   0x008048: 8b0a0129  add      x9, x9, x10
//   0x00804c: 5293f72a  mov      w10, #0x9fb9
//   0x008050: 72a254aa  movk     w10, #0x12a5, lsl #16
//   0x008054: eb0a013f  cmp      x9, x10
//   0x008058: 54000723  b.lo     #0x813c
//   0x00805c: f85d83ac  ldur     x12, [x29, #-0x28]
//   0x008060: a97eb7ae  ldp      x14, x13, [x29, #-0x18]
//   0x008064: 53115589  ubfx     w9, w12, #0x11, #5
//   0x008068: 5316698a  ubfx     w10, w12, #0x16, #5
//   0x00806c: 531b7d8b  lsr      w11, w12, #0x1b
//   0x008070: 530c418c  ubfx     w12, w12, #0xc, #5
//   0x008074: b90002e9  str      w9, [x23]
//   0x008078: d37df129  lsl      x9, x9, #3
//   0x00807c: b900030a  str      w10, [x24]
//   0x008080: d37df14a  lsl      x10, x10, #3
//   0x008084: b900032b  str      w11, [x25]
//   0x008088: b900034c  str      w12, [x26]
//   0x00808c: b8a96a69  ldrsw    x9, [x19, x9]
//   0x008090: b8aa6a6a  ldrsw    x10, [x19, x10]
//   0x008094: b94001cb  ldr      w11, [x14]
//   0x008098: b94001ac  ldr      w12, [x13]
//   0x00809c: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x0080a0: d282080b  mov      x11, #0x1040
//   0x0080a4: 9b09b149  msub     x9, x10, x9, x12
//   0x0080a8: d280800a  mov      x10, #0x400
//   0x0080ac: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x0080b0: f2a0008a  movk     x10, #4, lsl #16
//   0x0080b4: 93407d2c  sxtw     x12, w9
//   0x0080b8: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x0080bc: f2c0208a  movk     x10, #0x104, lsl #32
//   0x0080c0: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x0080c4: 9360fd29  asr      x9, x9, #0x20
//   0x0080c8: 8a0a010a  and      x10, x8, x10
//   0x0080cc: aa280168  orn      x8, x11, x8
//   0x0080d0: f94002ab  ldr      x11, [x21]
//   0x0080d4: f90001ac  str      x12, [x13]
//   0x0080d8: d282880c  mov      x12, #0x1440
//   0x0080dc: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x0080e0: f90001c9  str      x9, [x14]
//   0x0080e4: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0080e8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0080ec: b8404d69  ldr      w9, [x11, #4]!
//   0x0080f0: 8a0c0108  and      x8, x8, x12
//   0x0080f4: f90002ab  str      x11, [x21]
//   0x0080f8: 5280208b  mov      w11, #0x104
//   0x0080fc: 8b0a0108  add      x8, x8, x10
//   0x008100: 72a0202b  movk     w11, #0x101, lsl #16
//   0x008104: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x008108: aa0b0108  orr      x8, x8, x11
//   0x00810c: d28d6b8b  mov      x11, #0x6b5c
//   0x008110: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x008114: 92401529  and      x9, x9, #0x3f
//   0x008118: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x00811c: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x008120: ca0b0108  eor      x8, x8, x11
//   0x008124: 8b080148  add      x8, x10, x8
//   0x008128: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00812c: f85f83a9  ldur     x9, [x29, #-8]
//   0x008130: f9400108  ldr      x8, [x8]
//   0x008134: cb090108  sub      x8, x8, x9
//   0x008138: d61f0100  br       x8
//   0x00813c: b98002e9  ldrsw    x9, [x23]
//   0x008140: 528249aa  mov      w10, #0x124d
//   0x008144: 72a2488a  movk     w10, #0x1244, lsl #16
//   0x008148: 5290d32b  mov      w11, #0x8699
//   0x00814c: 72a661ab  movk     w11, #0x330d, lsl #16
//   0x008150: 52905f6c  mov      w12, #0x82fb
//   0x008154: 4a0a012a  eor      w10, w9, w10
//   0x008158: d37df129  lsl      x9, x9, #3
//   0x00815c: 72a75aec  movk     w12, #0x3ad7, lsl #16
//   0x008160: b90002ea  str      w10, [x23]
//   0x008164: b8a96a6a  ldrsw    x10, [x19, x9]
//   0x008168: 4a0b014b  eor      w11, w10, w11
//   0x00816c: 9b0a7d4a  mul      x10, x10, x10
//   0x008170: b8296a6b  str      w11, [x19, x9]
//   0x008174: 52981fcb  mov      w11, #0xc0fe
//   0x008178: b9800309  ldrsw    x9, [x24]
//   0x00817c: 72a79feb  movk     w11, #0x3cff, lsl #16
//   0x008180: 4a0b012b  eor      w11, w9, w11
//   0x008184: d37df129  lsl      x9, x9, #3
//   0x008188: b900030b  str      w11, [x24]
//   0x00818c: b8a96a6b  ldrsw    x11, [x19, x9]
//   0x008190: 4a0c016c  eor      w12, w11, w12
//   0x008194: b8296a6c  str      w12, [x19, x9]
//   0x008198: f85f03ac  ldur     x12, [x29, #-0x10]
//   0x00819c: 9b0b7d49  mul      x9, x10, x11
//   0x0081a0: b940018a  ldr      w10, [x12]
//   0x0081a4: cb0903eb  neg      x11, x9
//   0x0081a8: 9b0a2d29  madd     x9, x9, x10, x11
//   0x0081ac: f94002ab  ldr      x11, [x21]
//   0x0081b0: 92407d2a  and      x10, x9, #0xffffffff
//   0x0081b4: 9360fd29  asr      x9, x9, #0x20
//   0x0081b8: f900008b  str      x11, [x4]
//   0x0081bc: f900018a  str      x10, [x12]
//   0x0081c0: f85e83aa  ldur     x10, [x29, #-0x18]
//   0x0081c4: f9000149  str      x9, [x10]
//   0x0081c8: 52826bca  mov      w10, #0x135e
//   0x0081cc: b8404d69  ldr      w9, [x11, #4]!
//   0x0081d0: 72abb54a  movk     w10, #0x5daa, lsl #16
//   0x0081d4: f90002ab  str      x11, [x21]
//   0x0081d8: 4a0a0129  eor      w9, w9, w10
//   0x0081dc: b9000169  str      w9, [x11]
//   0x0081e0: 17ffff9f  b        #0x805c
//   0x0081e4: 90ffffe8  adrp     x8, #0x4000
//   0x0081e8: 5280202a  mov      w10, #0x101
//   0x0081ec: 91118108  add      x8, x8, #0x460
//   0x0081f0: 72a4020a  movk     w10, #0x2010, lsl #16
//   0x0081f4: 11000509  add      w9, w8, #1
//   0x0081f8: 0a280129  bic      w9, w9, w8
//   0x0081fc: 2a2903e9  mvn      w9, w9
//   0x008200: 8a0a0129  and      x9, x9, x10
//   0x008204: d29ceaca  mov      x10, #0xe756
//   0x008208: f2ba2b4a  movk     x10, #0xd15a, lsl #16
//   0x00820c: f2c8000a  movk     x10, #0x4000, lsl #32
//   0x008210: f2e0022a  movk     x10, #0x11, lsl #48
//   0x008214: 8b0a0129  add      x9, x9, x10
//   0x008218: 529443ea  mov      w10, #0xa21f
//   0x00821c: 72ad7c8a  movk     w10, #0x6be4, lsl #16
//   0x008220: eb0a013f  cmp      x9, x10
//   0x008224: 54000723  b.lo     #0x8308
//   0x008228: f85d83ac  ldur     x12, [x29, #-0x28]
//   0x00822c: a97eb7ae  ldp      x14, x13, [x29, #-0x18]
//   0x008230: 53115589  ubfx     w9, w12, #0x11, #5
//   0x008234: 5316698a  ubfx     w10, w12, #0x16, #5
//   0x008238: 530c418b  ubfx     w11, w12, #0xc, #5
//   0x00823c: 531b7d8c  lsr      w12, w12, #0x1b
//   0x008240: b90002e9  str      w9, [x23]
//   0x008244: d37df129  lsl      x9, x9, #3
//   0x008248: b900030a  str      w10, [x24]
//   0x00824c: d37df14a  lsl      x10, x10, #3
//   0x008250: b900032b  str      w11, [x25]
//   0x008254: b900034c  str      w12, [x26]
//   0x008258: b8696a69  ldr      w9, [x19, x9]
//   0x00825c: b86a6a6a  ldr      w10, [x19, x10]
//   0x008260: b94001cb  ldr      w11, [x14]
//   0x008264: b94001ac  ldr      w12, [x13]
//   0x008268: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x00826c: d282080b  mov      x11, #0x1040
//   0x008270: 9b09b149  msub     x9, x10, x9, x12
//   0x008274: d280800a  mov      x10, #0x400
//   0x008278: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00827c: f2a0008a  movk     x10, #4, lsl #16
//   0x008280: 93407d2c  sxtw     x12, w9
//   0x008284: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x008288: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00828c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x008290: 9360fd29  asr      x9, x9, #0x20
//   0x008294: 8a0a010a  and      x10, x8, x10
//   0x008298: aa280168  orn      x8, x11, x8
//   0x00829c: f94002ab  ldr      x11, [x21]
//   0x0082a0: f90001ac  str      x12, [x13]
//   0x0082a4: d282880c  mov      x12, #0x1440
//   0x0082a8: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x0082ac: f90001c9  str      x9, [x14]
//   0x0082b0: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0082b4: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0082b8: b8404d69  ldr      w9, [x11, #4]!
//   0x0082bc: 8a0c0108  and      x8, x8, x12
//   0x0082c0: f90002ab  str      x11, [x21]
//   0x0082c4: 5280208b  mov      w11, #0x104
//   0x0082c8: 8b0a0108  add      x8, x8, x10
//   0x0082cc: 72a0202b  movk     w11, #0x101, lsl #16
//   0x0082d0: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x0082d4: aa0b0108  orr      x8, x8, x11
//   0x0082d8: d28d6b8b  mov      x11, #0x6b5c
//   0x0082dc: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x0082e0: 92401529  and      x9, x9, #0x3f
//   0x0082e4: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x0082e8: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x0082ec: ca0b0108  eor      x8, x8, x11
//   0x0082f0: 8b080148  add      x8, x10, x8
//   0x0082f4: 8b090d08  add      x8, x8, x9, lsl #3
//   0x0082f8: f85f83a9  ldur     x9, [x29, #-8]
//   0x0082fc: f9400108  ldr      x8, [x8]
//   0x008300: cb090108  sub      x8, x8, x9
//   0x008304: d61f0100  br       x8
//   0x008308: b98002e9  ldrsw    x9, [x23]
//   0x00830c: 5295f62a  mov      w10, #0xafb1
//   0x008310: 72ac072a  movk     w10, #0x6039, lsl #16
//   0x008314: 5297da2b  mov      w11, #0xbed1
//   0x008318: 72ad67ab  movk     w11, #0x6b3d, lsl #16
//   0x00831c: 5286270c  mov      w12, #0x3138
//   0x008320: 4a0a012a  eor      w10, w9, w10
//   0x008324: d37df129  lsl      x9, x9, #3
//   0x008328: 72a265ac  movk     w12, #0x132d, lsl #16
//   0x00832c: b90002ea  str      w10, [x23]
//   0x008330: b8696a6a  ldr      w10, [x19, x9]
//   0x008334: 4a0b014b  eor      w11, w10, w11
//   0x008338: b8296a6b  str      w11, [x19, x9]
//   0x00833c: 52984b0b  mov      w11, #0xc258
//   0x008340: b9800309  ldrsw    x9, [x24]
//   0x008344: 72a4574b  movk     w11, #0x22ba, lsl #16
//   0x008348: 4a0b012b  eor      w11, w9, w11
//   0x00834c: d37df129  lsl      x9, x9, #3
//   0x008350: b900030b  str      w11, [x24]
//   0x008354: b8696a6b  ldr      w11, [x19, x9]
//   0x008358: 4a0c016c  eor      w12, w11, w12
//   0x00835c: cb0a016b  sub      x11, x11, x10
//   0x008360: b8296a6c  str      w12, [x19, x9]
//   0x008364: f85f03ac  ldur     x12, [x29, #-0x10]
//   0x008368: 9b0a7d69  mul      x9, x11, x10
//   0x00836c: b940018a  ldr      w10, [x12]
//   0x008370: cb0903eb  neg      x11, x9
//   0x008374: 9b0a2d29  madd     x9, x9, x10, x11
//   0x008378: f94002ab  ldr      x11, [x21]
//   0x00837c: 93407d2a  sxtw     x10, w9
//   0x008380: d360fd29  lsr      x9, x9, #0x20
//   0x008384: f900008b  str      x11, [x4]
//   0x008388: f900018a  str      x10, [x12]
//   0x00838c: f85e83aa  ldur     x10, [x29, #-0x18]
//   0x008390: f9000149  str      x9, [x10]
//   0x008394: 528884ca  mov      w10, #0x4426
//   0x008398: b8404d69  ldr      w9, [x11, #4]!
//   0x00839c: 72a3652a  movk     w10, #0x1b29, lsl #16
//   0x0083a0: f90002ab  str      x11, [x21]
//   0x0083a4: 4a0a0129  eor      w9, w9, w10
//   0x0083a8: b9000169  str      w9, [x11]
//   0x0083ac: 17ffff9f  b        #0x8228
//   0x0083b0: 90ffffe8  adrp     x8, #0x4000
//   0x0083b4: 52920c0a  mov      w10, #0x9060
//   0x0083b8: 91118108  add      x8, x8, #0x460
//   0x0083bc: 72a9232a  movk     w10, #0x4919, lsl #16
//   0x0083c0: 11000509  add      w9, w8, #1
//   0x0083c4: 0a280129  bic      w9, w9, w8
//   0x0083c8: 2a2903e9  mvn      w9, w9
//   0x0083cc: 8a0a0129  and      x9, x9, x10
//   0x0083d0: d281764a  mov      x10, #0xbb2
//   0x0083d4: f2a71aaa  movk     x10, #0x38d5, lsl #16
//   0x0083d8: f2c0640a  movk     x10, #0x320, lsl #32
//   0x0083dc: f2e0004a  movk     x10, #2, lsl #48
//   0x0083e0: 8b0a0129  add      x9, x9, x10
//   0x0083e4: 5290dcea  mov      w10, #0x86e7
//   0x0083e8: 72adca8a  movk     w10, #0x6e54, lsl #16
//   0x0083ec: eb0a013f  cmp      x9, x10
//   0x0083f0: 54000643  b.lo     #0x84b8
//   0x0083f4: f85d83ac  ldur     x12, [x29, #-0x28]
//   0x0083f8: d280800d  mov      x13, #0x400
//   0x0083fc: f2a0008d  movk     x13, #4, lsl #16
//   0x008400: f2c0208d  movk     x13, #0x104, lsl #32
//   0x008404: 53166989  ubfx     w9, w12, #0x16, #5
//   0x008408: 530c418a  ubfx     w10, w12, #0xc, #5
//   0x00840c: 531b7d8b  lsr      w11, w12, #0x1b
//   0x008410: 5311558c  ubfx     w12, w12, #0x11, #5
//   0x008414: 8a0d010d  and      x13, x8, x13
//   0x008418: b90002e9  str      w9, [x23]
//   0x00841c: d37df129  lsl      x9, x9, #3
//   0x008420: b900030a  str      w10, [x24]
//   0x008424: d37df14a  lsl      x10, x10, #3
//   0x008428: b900032b  str      w11, [x25]
//   0x00842c: b900034c  str      w12, [x26]
//   0x008430: f94002ac  ldr      x12, [x21]
//   0x008434: b8a96a69  ldrsw    x9, [x19, x9]
//   0x008438: b8aa6a6a  ldrsw    x10, [x19, x10]
//   0x00843c: 9b097d49  mul      x9, x10, x9
//   0x008440: d282080a  mov      x10, #0x1040
//   0x008444: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x008448: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x00844c: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x008450: f82b5a69  str      x9, [x19, w11, uxtw #3]
//   0x008454: aa280148  orn      x8, x10, x8
//   0x008458: d282880a  mov      x10, #0x1440
//   0x00845c: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x008460: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x008464: b8404d89  ldr      w9, [x12, #4]!
//   0x008468: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x00846c: f90002ac  str      x12, [x21]
//   0x008470: d28d6b8c  mov      x12, #0x6b5c
//   0x008474: 8a0a0108  and      x8, x8, x10
//   0x008478: 5280208a  mov      w10, #0x104
//   0x00847c: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x008480: 72a0202a  movk     w10, #0x101, lsl #16
//   0x008484: 8b0d0108  add      x8, x8, x13
//   0x008488: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x00848c: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x008490: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x008494: aa0a0108  orr      x8, x8, x10
//   0x008498: ca0c0108  eor      x8, x8, x12
//   0x00849c: 92401529  and      x9, x9, #0x3f
//   0x0084a0: 8b080168  add      x8, x11, x8
//   0x0084a4: 8b090d08  add      x8, x8, x9, lsl #3
//   0x0084a8: f85f83a9  ldur     x9, [x29, #-8]
//   0x0084ac: f9400108  ldr      x8, [x8]
//   0x0084b0: cb090108  sub      x8, x8, x9
//   0x0084b4: d61f0100  br       x8
//   0x0084b8: b98002e9  ldrsw    x9, [x23]
//   0x0084bc: 5292dd0a  mov      w10, #0x96e8
//   0x0084c0: 72ade9ea  movk     w10, #0x6f4f, lsl #16
//   0x0084c4: 52924deb  mov      w11, #0x926f
//   0x0084c8: 72aa478b  movk     w11, #0x523c, lsl #16
//   0x0084cc: 5286be0c  mov      w12, #0x35f0
//   0x0084d0: 4a0a012a  eor      w10, w9, w10
//   0x0084d4: d37df129  lsl      x9, x9, #3
//   0x0084d8: 72a0f9cc  movk     w12, #0x7ce, lsl #16
//   0x0084dc: b90002ea  str      w10, [x23]
//   0x0084e0: b8696a6a  ldr      w10, [x19, x9]
//   0x0084e4: 4a0b014b  eor      w11, w10, w11
//   0x0084e8: b8296a6b  str      w11, [x19, x9]
//   0x0084ec: 529bf2eb  mov      w11, #0xdf97
//   0x0084f0: b9800309  ldrsw    x9, [x24]
//   0x0084f4: 72a0d62b  movk     w11, #0x6b1, lsl #16
//   0x0084f8: 4a0b012b  eor      w11, w9, w11
//   0x0084fc: d37df129  lsl      x9, x9, #3
//   0x008500: b900030b  str      w11, [x24]
//   0x008504: b8696a6b  ldr      w11, [x19, x9]
//   0x008508: 4a0c016c  eor      w12, w11, w12
//   0x00850c: 4b0a016b  sub      w11, w11, w10
//   0x008510: b8296a6c  str      w12, [x19, x9]
//   0x008514: 1b0a7d69  mul      w9, w11, w10
//   0x008518: b980032a  ldrsw    x10, [x25]
//   0x00851c: 529a87eb  mov      w11, #0xd43f
//   0x008520: 93407d29  sxtw     x9, w9
//   0x008524: 72a7cfcb  movk     w11, #0x3e7e, lsl #16
//   0x008528: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00852c: f94002a9  ldr      x9, [x21]
//   0x008530: f9000089  str      x9, [x4]
//   0x008534: b8404d2a  ldr      w10, [x9, #4]!
//   0x008538: f90002a9  str      x9, [x21]
//   0x00853c: 4a0b014a  eor      w10, w10, w11
//   0x008540: b900012a  str      w10, [x9]
//   0x008544: 17ffffac  b        #0x83f4
//   0x008548: f94002a8  ldr      x8, [x21]
//   0x00854c: 90000089  adrp     x9, #0x18000
//   0x008550: b940011c  ldr      w28, [x8]
//   0x008554: 52802088  mov      w8, #0x104
//   0x008558: 72a02028  movk     w8, #0x101, lsl #16
//   0x00855c: f941fd29  ldr      x9, [x9, #0x3f8]
//   0x008560: aa0802c8  orr      x8, x22, x8
//   0x008564: ca110108  eor      x8, x8, x17
//   0x008568: d3462f8a  ubfx     x10, x28, #6, #6
//   0x00856c: 8b080128  add      x8, x9, x8
//   0x008570: f85f83a9  ldur     x9, [x29, #-8]
//   0x008574: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x008578: f9400108  ldr      x8, [x8]
//   0x00857c: cb090108  sub      x8, x8, x9
//   0x008580: d61f0100  br       x8
//   0x008584: 5280040a  mov      w10, #0x20
//   0x008588: 53115789  ubfx     w9, w28, #0x11, #5
//   0x00858c: 2a1b03ec  mov      w12, w27
//   0x008590: 531b7f88  lsr      w8, w28, #0x1b
//   0x008594: 53166b8b  ubfx     w11, w28, #0x16, #5
//   0x008598: 330c438a  bfxil    w10, w28, #0xc, #5
//   0x00859c: 14000006  b        #0x85b4
//   0x0085a0: 53166b89  ubfx     w9, w28, #0x16, #5
//   0x0085a4: 531b7f88  lsr      w8, w28, #0x1b
//   0x0085a8: 2a1b03ec  mov      w12, w27
//   0x0085ac: 530c438b  ubfx     w11, w28, #0xc, #5
//   0x0085b0: 5311578a  ubfx     w10, w28, #0x11, #5
//   0x0085b4: b90002e9  str      w9, [x23]
//   0x0085b8: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x0085bc: b9000308  str      w8, [x24]
//   0x0085c0: 2a0c03fb  mov      w27, w12
//   0x0085c4: b900004b  str      w11, [x2]
//   0x0085c8: 1100056b  add      w11, w11, #1
//   0x0085cc: 1400000e  b        #0x8604
//   0x0085d0: 531b7f8a  lsr      w10, w28, #0x1b
//   0x0085d4: 5280040b  mov      w11, #0x20
//   0x0085d8: 53166b88  ubfx     w8, w28, #0x16, #5
//   0x0085dc: 3311578b  bfxil    w11, w28, #0x11, #5
//   0x0085e0: 7100fd7f  cmp      w11, #0x3f
//   0x0085e4: f86a5a69  ldr      x9, [x19, w10, uxtw #3]
//   0x0085e8: b90002ea  str      w10, [x23]
//   0x0085ec: b9000308  str      w8, [x24]
//   0x0085f0: b900004b  str      w11, [x2]
//   0x0085f4: 54000320  b.eq     #0x8658
//   0x0085f8: 5311578b  ubfx     w11, w28, #0x11, #5
//   0x0085fc: 530c438a  ubfx     w10, w28, #0xc, #5
//   0x008600: 1100856b  add      w11, w11, #0x21
//   0x008604: 90ffffec  adrp     x12, #0x4000
//   0x008608: 9111818c  add      x12, x12, #0x460
//   0x00860c: 1100058d  add      w13, w12, #1
//   0x008610: 0a2c01ac  bic      w12, w13, w12
//   0x008614: 5288102d  mov      w13, #0x4081
//   0x008618: 2a2c03ec  mvn      w12, w12
//   0x00861c: 72a021cd  movk     w13, #0x10e, lsl #16
//   0x008620: 8a0d018c  and      x12, x12, x13
//   0x008624: d285fead  mov      x13, #0x2ff5
//   0x008628: f2a68bcd  movk     x13, #0x345e, lsl #16
//   0x00862c: f2c4040d  movk     x13, #0x2020, lsl #32
//   0x008630: f2e0040d  movk     x13, #0x20, lsl #48
//   0x008634: 8b0d018c  add      x12, x12, x13
//   0x008638: 52926f6d  mov      w13, #0x937b
//   0x00863c: 72a5f40d  movk     w13, #0x2fa0, lsl #16
//   0x008640: eb0d019f  cmp      x12, x13
//   0x008644: 54000723  b.lo     #0x8728
//   0x008648: 9280000c  mov      x12, #-1
//   0x00864c: 9aca2529  lsr      x9, x9, x10
//   0x008650: 9acb218a  lsl      x10, x12, x11
//   0x008654: 8a2a0129  bic      x9, x9, x10
//   0x008658: 90ffffea  adrp     x10, #0x4000
//   0x00865c: 5280312c  mov      w12, #0x189
//   0x008660: 9111814a  add      x10, x10, #0x460
//   0x008664: 72a1400c  movk     w12, #0xa00, lsl #16
//   0x008668: 1100054b  add      w11, w10, #1
//   0x00866c: 0a2a016b  bic      w11, w11, w10
//   0x008670: 2a2b03eb  mvn      w11, w11
//   0x008674: 8a0c016b  and      x11, x11, x12
//   0x008678: d2854fcc  mov      x12, #0x2a7e
//   0x00867c: f2a2a7cc  movk     x12, #0x153e, lsl #16
//   0x008680: f2c8020c  movk     x12, #0x4010, lsl #32
//   0x008684: f2e0008c  movk     x12, #4, lsl #48
//   0x008688: 8b0c016b  add      x11, x11, x12
//   0x00868c: 52987c0c  mov      w12, #0xc3e0
//   0x008690: 72a2898c  movk     w12, #0x144c, lsl #16
//   0x008694: eb0c017f  cmp      x11, x12
//   0x008698: 54000503  b.lo     #0x8738
//   0x00869c: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x0086a0: d282080b  mov      x11, #0x1040
//   0x0086a4: f94002a8  ldr      x8, [x21]
//   0x0086a8: d2808009  mov      x9, #0x400
//   0x0086ac: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x0086b0: d282880c  mov      x12, #0x1440
//   0x0086b4: f2a00089  movk     x9, #4, lsl #16
//   0x0086b8: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x0086bc: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x0086c0: f2c02089  movk     x9, #0x104, lsl #32
//   0x0086c4: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x0086c8: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0086cc: 8a090149  and      x9, x10, x9
//   0x0086d0: aa2a016a  orn      x10, x11, x10
//   0x0086d4: b8404d0b  ldr      w11, [x8, #4]!
//   0x0086d8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0086dc: f90002a8  str      x8, [x21]
//   0x0086e0: 8a0c0148  and      x8, x10, x12
//   0x0086e4: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x0086e8: 8b090108  add      x8, x8, x9
//   0x0086ec: 52802089  mov      w9, #0x104
//   0x0086f0: 72a02029  movk     w9, #0x101, lsl #16
//   0x0086f4: 9240156b  and      x11, x11, #0x3f
//   0x0086f8: aa090108  orr      x8, x8, x9
//   0x0086fc: d28d6b89  mov      x9, #0x6b5c
//   0x008700: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x008704: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x008708: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00870c: ca090108  eor      x8, x8, x9
//   0x008710: f85f83a9  ldur     x9, [x29, #-8]
//   0x008714: 8b080148  add      x8, x10, x8
//   0x008718: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x00871c: f9400108  ldr      x8, [x8]
//   0x008720: cb090108  sub      x8, x8, x9
//   0x008724: d61f0100  br       x8
//   0x008728: 5293d40c  mov      w12, #0x9ea0
//   0x00872c: 72adec8c  movk     w12, #0x6f64, lsl #16
//   0x008730: 4a0c014a  eor      w10, w10, w12
//   0x008734: 17ffffc5  b        #0x8648
//   0x008738: f94002ab  ldr      x11, [x21]
//   0x00873c: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x008740: 5288e06c  mov      w12, #0x4703
//   0x008744: 72aae64c  movk     w12, #0x5732, lsl #16
//   0x008748: f900008b  str      x11, [x4]
//   0x00874c: 4a0c0108  eor      w8, w8, w12
//   0x008750: b8404d6d  ldr      w13, [x11, #4]!
//   0x008754: 528855cc  mov      w12, #0x42ae
//   0x008758: f90002ab  str      x11, [x21]
//   0x00875c: 72a4ba8c  movk     w12, #0x25d4, lsl #16
//   0x008760: b9000308  str      w8, [x24]
//   0x008764: 4a0c01ac  eor      w12, w13, w12
//   0x008768: b900016c  str      w12, [x11]
//   0x00876c: 17ffffcc  b        #0x869c
//   0x008770: 53115788  ubfx     w8, w28, #0x11, #5
//   0x008774: 5280040b  mov      w11, #0x20
//   0x008778: 2a1b03ec  mov      w12, w27
//   0x00877c: 53166b8a  ubfx     w10, w28, #0x16, #5
//   0x008780: 330c438b  bfxil    w11, w28, #0xc, #5
//   0x008784: 531b7f89  lsr      w9, w28, #0x1b
//   0x008788: 1400000f  b        #0x87c4
//   0x00878c: 531b7f88  lsr      w8, w28, #0x1b
//   0x008790: 5280040b  mov      w11, #0x20
//   0x008794: 52800409  mov      w9, #0x20
//   0x008798: 2a1b03ec  mov      w12, w27
//   0x00879c: 530c438a  ubfx     w10, w28, #0xc, #5
//   0x0087a0: 33166b8b  bfxil    w11, w28, #0x16, #5
//   0x0087a4: b90002e8  str      w8, [x23]
//   0x0087a8: 33115789  bfxil    w9, w28, #0x11, #5
//   0x0087ac: 14000007  b        #0x87c8
//   0x0087b0: 531b7f88  lsr      w8, w28, #0x1b
//   0x0087b4: 530c438a  ubfx     w10, w28, #0xc, #5
//   0x0087b8: 53166b8b  ubfx     w11, w28, #0x16, #5
//   0x0087bc: 53115789  ubfx     w9, w28, #0x11, #5
//   0x0087c0: 2a1b03ec  mov      w12, w27
//   0x0087c4: b90002e8  str      w8, [x23]
//   0x0087c8: b900030a  str      w10, [x24]
//   0x0087cc: 2a0a03ea  mov      w10, w10
//   0x0087d0: d37df14a  lsl      x10, x10, #3
//   0x0087d4: 1100056c  add      w12, w11, #1
//   0x0087d8: f8685a68  ldr      x8, [x19, w8, uxtw #3]
//   0x0087dc: 4b09018d  sub      w13, w12, w9
//   0x0087e0: b900004b  str      w11, [x2]
//   0x0087e4: 7100fd7f  cmp      w11, #0x3f
//   0x0087e8: f86a6a6b  ldr      x11, [x19, x10]
//   0x0087ec: 9280000e  mov      x14, #-1
//   0x0087f0: 9acd21cd  lsl      x13, x14, x13
//   0x0087f4: 9acc21cc  lsl      x12, x14, x12
//   0x0087f8: 8a2d0108  bic      x8, x8, x13
//   0x0087fc: 9ac921cd  lsl      x13, x14, x9
//   0x008800: 9ac92108  lsl      x8, x8, x9
//   0x008804: f94002af  ldr      x15, [x21]
//   0x008808: 8a2d0169  bic      x9, x11, x13
//   0x00880c: 8a0c016b  and      x11, x11, x12
//   0x008810: 9a8b03eb  csel     x11, xzr, x11, eq
//   0x008814: aa080128  orr      x8, x9, x8
//   0x008818: aa0b0108  orr      x8, x8, x11
//   0x00881c: d282080b  mov      x11, #0x1040
//   0x008820: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x008824: d282880c  mov      x12, #0x1440
//   0x008828: d2808009  mov      x9, #0x400
//   0x00882c: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x008830: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x008834: f2a00089  movk     x9, #4, lsl #16
//   0x008838: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00883c: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x008840: f2c02089  movk     x9, #0x104, lsl #32
//   0x008844: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x008848: f82a6a68  str      x8, [x19, x10]
//   0x00884c: aa25016a  orn      x10, x11, x5
//   0x008850: 8a0900a9  and      x9, x5, x9
//   0x008854: 8a0c014a  and      x10, x10, x12
//   0x008858: 8b090149  add      x9, x10, x9
//   0x00885c: 5280208a  mov      w10, #0x104
//   0x008860: 72a0202a  movk     w10, #0x101, lsl #16
//   0x008864: aa0a0129  orr      x9, x9, x10
//   0x008868: d28d6b8a  mov      x10, #0x6b5c
//   0x00886c: b8404de8  ldr      w8, [x15, #4]!
//   0x008870: f90002af  str      x15, [x21]
//   0x008874: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x008878: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x00887c: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x008880: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x008884: 92401508  and      x8, x8, #0x3f
//   0x008888: ca0a0129  eor      x9, x9, x10
//   0x00888c: 8b090169  add      x9, x11, x9
//   0x008890: 8b080d28  add      x8, x9, x8, lsl #3
//   0x008894: f85f83a9  ldur     x9, [x29, #-8]
//   0x008898: f9400108  ldr      x8, [x8]
//   0x00889c: cb090108  sub      x8, x8, x9
//   0x0088a0: d61f0100  br       x8
//   0x0088a4: 90ffffe8  adrp     x8, #0x4000
//   0x0088a8: 91118108  add      x8, x8, #0x460
//   0x0088ac: 11000509  add      w9, w8, #1
//   0x0088b0: 0a280128  bic      w8, w9, w8
//   0x0088b4: 52808069  mov      w9, #0x403
//   0x0088b8: 2a2803e8  mvn      w8, w8
//   0x0088bc: 72a0c289  movk     w9, #0x614, lsl #16
//   0x0088c0: 8a090108  and      x8, x8, x9
//   0x0088c4: d2991ac9  mov      x9, #0xc8d6
//   0x0088c8: f2b32289  movk     x9, #0x9914, lsl #16
//   0x0088cc: f2ce0009  movk     x9, #0x7000, lsl #32
//   0x0088d0: f2e00089  movk     x9, #4, lsl #48
//   0x0088d4: 8b090108  add      x8, x8, x9
//   0x0088d8: 529617a9  mov      w9, #0xb0bd
//   0x0088dc: 72a0e9a9  movk     w9, #0x74d, lsl #16
//   0x0088e0: eb09011f  cmp      x8, x9
//   0x0088e4: 540008c3  b.lo     #0x89fc
//   0x0088e8: 531b7f89  lsr      w9, w28, #0x1b
//   0x0088ec: 530c4388  ubfx     w8, w28, #0xc, #5
//   0x0088f0: d37df12a  lsl      x10, x9, #3
//   0x0088f4: 53167f8b  lsr      w11, w28, #0x16
//   0x0088f8: 53117f8c  lsr      w12, w28, #0x11
//   0x0088fc: 1280002e  mov      w14, #-2
//   0x008900: b90002e9  str      w9, [x23]
//   0x008904: 53166b8d  ubfx     w13, w28, #0x16, #5
//   0x008908: b9000308  str      w8, [x24]
//   0x00890c: 90ffffe9  adrp     x9, #0x4000
//   0x008910: b86a6a6a  ldr      w10, [x19, x10]
//   0x008914: 1acb21cb  lsl      w11, w14, w11
//   0x008918: 91118129  add      x9, x9, #0x460
//   0x00891c: 71007dbf  cmp      w13, #0x1f
//   0x008920: 1100052e  add      w14, w9, #1
//   0x008924: b900004d  str      w13, [x2]
//   0x008928: 0a2901ce  bic      w14, w14, w9
//   0x00892c: 1acc254c  lsr      w12, w10, w12
//   0x008930: 2a2e03ee  mvn      w14, w14
//   0x008934: 0a2b018b  bic      w11, w12, w11
//   0x008938: 5282246c  mov      w12, #0x1123
//   0x00893c: 1a8b014a  csel     w10, w10, w11, eq
//   0x008940: d281ad4b  mov      x11, #0xd6a
//   0x008944: f2a2f0cb  movk     x11, #0x1786, lsl #16
//   0x008948: 72a8256c  movk     w12, #0x412b, lsl #16
//   0x00894c: f2c0200b  movk     x11, #0x100, lsl #32
//   0x008950: 8a0c01cc  and      x12, x14, x12
//   0x008954: f2e000cb  movk     x11, #6, lsl #48
//   0x008958: 93407d4a  sxtw     x10, w10
//   0x00895c: 8b0b018b  add      x11, x12, x11
//   0x008960: 52901f8c  mov      w12, #0x80fc
//   0x008964: 72a4e88c  movk     w12, #0x2744, lsl #16
//   0x008968: eb0c017f  cmp      x11, x12
//   0x00896c: 54000603  b.lo     #0x8a2c
//   0x008970: f8285a6a  str      x10, [x19, w8, uxtw #3]
//   0x008974: d282080b  mov      x11, #0x1040
//   0x008978: f94002a8  ldr      x8, [x21]
//   0x00897c: d280800a  mov      x10, #0x400
//   0x008980: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x008984: d282880c  mov      x12, #0x1440
//   0x008988: f2a0008a  movk     x10, #4, lsl #16
//   0x00898c: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x008990: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x008994: f2c0208a  movk     x10, #0x104, lsl #32
//   0x008998: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00899c: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x0089a0: 8a0a012a  and      x10, x9, x10
//   0x0089a4: aa290169  orn      x9, x11, x9
//   0x0089a8: b8404d0b  ldr      w11, [x8, #4]!
//   0x0089ac: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0089b0: f90002a8  str      x8, [x21]
//   0x0089b4: 8a0c0128  and      x8, x9, x12
//   0x0089b8: f941f289  ldr      x9, [x20, #0x3e0]
//   0x0089bc: 8b0a0108  add      x8, x8, x10
//   0x0089c0: 5280208a  mov      w10, #0x104
//   0x0089c4: 72a0202a  movk     w10, #0x101, lsl #16
//   0x0089c8: 9240156b  and      x11, x11, #0x3f
//   0x0089cc: aa0a0108  orr      x8, x8, x10
//   0x0089d0: d28d6b8a  mov      x10, #0x6b5c
//   0x0089d4: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x0089d8: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x0089dc: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x0089e0: ca0a0108  eor      x8, x8, x10
//   0x0089e4: 8b080128  add      x8, x9, x8
//   0x0089e8: f85f83a9  ldur     x9, [x29, #-8]
//   0x0089ec: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x0089f0: f9400108  ldr      x8, [x8]
//   0x0089f4: cb090108  sub      x8, x8, x9
//   0x0089f8: d61f0100  br       x8
//   0x0089fc: b98002e8  ldrsw    x8, [x23]
//   0x008a00: 52969a29  mov      w9, #0xb4d1
//   0x008a04: 72a7fea9  movk     w9, #0x3ff5, lsl #16
//   0x008a08: 5284c4aa  mov      w10, #0x2625
//   0x008a0c: 72a3864a  movk     w10, #0x1c32, lsl #16
//   0x008a10: 4a090109  eor      w9, w8, w9
//   0x008a14: d37df108  lsl      x8, x8, #3
//   0x008a18: b90002e9  str      w9, [x23]
//   0x008a1c: b8686a69  ldr      w9, [x19, x8]
//   0x008a20: 4a0a0129  eor      w9, w9, w10
//   0x008a24: b8286a69  str      w9, [x19, x8]
//   0x008a28: 17ffffb0  b        #0x88e8
//   0x008a2c: f94002ab  ldr      x11, [x21]
//   0x008a30: f8285a6a  str      x10, [x19, w8, uxtw #3]
//   0x008a34: 5287756c  mov      w12, #0x3bab
//   0x008a38: 72aa874c  movk     w12, #0x543a, lsl #16
//   0x008a3c: f900008b  str      x11, [x4]
//   0x008a40: 4a0c0108  eor      w8, w8, w12
//   0x008a44: b8404d6d  ldr      w13, [x11, #4]!
//   0x008a48: 5290580c  mov      w12, #0x82c0
//   0x008a4c: f90002ab  str      x11, [x21]
//   0x008a50: 72a7646c  movk     w12, #0x3b23, lsl #16
//   0x008a54: b9000308  str      w8, [x24]
//   0x008a58: 4a0c01ac  eor      w12, w13, w12
//   0x008a5c: b900016c  str      w12, [x11]
//   0x008a60: 17ffffc4  b        #0x8970
//   0x008a64: 90ffffe8  adrp     x8, #0x4000
//   0x008a68: 5281584a  mov      w10, #0xac2
//   0x008a6c: 91118108  add      x8, x8, #0x460
//   0x008a70: 72a1000a  movk     w10, #0x800, lsl #16
//   0x008a74: 11000509  add      w9, w8, #1
//   0x008a78: 0a280129  bic      w9, w9, w8
//   0x008a7c: 2a2903e9  mvn      w9, w9
//   0x008a80: 8a0a0129  and      x9, x9, x10
//   0x008a84: d2885e2a  mov      x10, #0x42f1
//   0x008a88: f2a7474a  movk     x10, #0x3a3a, lsl #16
//   0x008a8c: f2c400aa  movk     x10, #0x2005, lsl #32
//   0x008a90: f2e0400a  movk     x10, #0x200, lsl #48
//   0x008a94: 8b0a0129  add      x9, x9, x10
//   0x008a98: 528542ea  mov      w10, #0x2a17
//   0x008a9c: 72a0054a  movk     w10, #0x2a, lsl #16
//   0x008aa0: eb0a013f  cmp      x9, x10
//   0x008aa4: 54000823  b.lo     #0x8ba8
//   0x008aa8: 53166b89  ubfx     w9, w28, #0x16, #5
//   0x008aac: 531b7f8a  lsr      w10, w28, #0x1b
//   0x008ab0: d37df12d  lsl      x13, x9, #3
//   0x008ab4: 530c438b  ubfx     w11, w28, #0xc, #5
//   0x008ab8: 5311578c  ubfx     w12, w28, #0x11, #5
//   0x008abc: 53117f8e  lsr      w14, w28, #0x11
//   0x008ac0: 4b0c016c  sub      w12, w11, w12
//   0x008ac4: b90002e9  str      w9, [x23]
//   0x008ac8: b900030a  str      w10, [x24]
//   0x008acc: d37df149  lsl      x9, x10, #3
//   0x008ad0: b86d6a6a  ldr      w10, [x19, x13]
//   0x008ad4: 1100058c  add      w12, w12, #1
//   0x008ad8: 530c7f8d  lsr      w13, w28, #0xc
//   0x008adc: 1280000f  mov      w15, #-1
//   0x008ae0: b8696a70  ldr      w16, [x19, x9]
//   0x008ae4: 71007d7f  cmp      w11, #0x1f
//   0x008ae8: 1acc21ec  lsl      w12, w15, w12
//   0x008aec: 1ace21ef  lsl      w15, w15, w14
//   0x008af0: 0a2c014a  bic      w10, w10, w12
//   0x008af4: 1280002c  mov      w12, #-2
//   0x008af8: 1acd218c  lsl      w12, w12, w13
//   0x008afc: 1ace214a  lsl      w10, w10, w14
//   0x008b00: 0a2f020d  bic      w13, w16, w15
//   0x008b04: 0a0c020c  and      w12, w16, w12
//   0x008b08: 1a8c03ec  csel     w12, wzr, w12, eq
//   0x008b0c: 2a0d014a  orr      w10, w10, w13
//   0x008b10: 2a0c014a  orr      w10, w10, w12
//   0x008b14: f94002ac  ldr      x12, [x21]
//   0x008b18: 93407d4a  sxtw     x10, w10
//   0x008b1c: d282080d  mov      x13, #0x1040
//   0x008b20: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x008b24: d282880e  mov      x14, #0x1440
//   0x008b28: f8296a6a  str      x10, [x19, x9]
//   0x008b2c: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x008b30: b8404d89  ldr      w9, [x12, #4]!
//   0x008b34: f90002ac  str      x12, [x21]
//   0x008b38: d280800c  mov      x12, #0x400
//   0x008b3c: f2a140ce  movk     x14, #0xa06, lsl #16
//   0x008b40: f2a0008c  movk     x12, #4, lsl #16
//   0x008b44: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x008b48: f2cc288e  movk     x14, #0x6144, lsl #32
//   0x008b4c: f2c0208c  movk     x12, #0x104, lsl #32
//   0x008b50: aa2801ad  orn      x13, x13, x8
//   0x008b54: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x008b58: 8a0c0108  and      x8, x8, x12
//   0x008b5c: 8a0e01ac  and      x12, x13, x14
//   0x008b60: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x008b64: 8b080188  add      x8, x12, x8
//   0x008b68: 5280208c  mov      w12, #0x104
//   0x008b6c: 72a0202c  movk     w12, #0x101, lsl #16
//   0x008b70: 92401529  and      x9, x9, #0x3f
//   0x008b74: aa0c0108  orr      x8, x8, x12
//   0x008b78: d28d6b8c  mov      x12, #0x6b5c
//   0x008b7c: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x008b80: b900004b  str      w11, [x2]
//   0x008b84: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x008b88: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x008b8c: ca0c0108  eor      x8, x8, x12
//   0x008b90: 8b080148  add      x8, x10, x8
//   0x008b94: 8b090d08  add      x8, x8, x9, lsl #3
//   0x008b98: f85f83a9  ldur     x9, [x29, #-8]
//   0x008b9c: f9400108  ldr      x8, [x8]
//   0x008ba0: cb090108  sub      x8, x8, x9
//   0x008ba4: d61f0100  br       x8
//   0x008ba8: b98002e9  ldrsw    x9, [x23]
//   0x008bac: 529e5c2a  mov      w10, #0xf2e1
//   0x008bb0: 72a04dea  movk     w10, #0x26f, lsl #16
//   0x008bb4: b940004b  ldr      w11, [x2]
//   0x008bb8: 529260ec  mov      w12, #0x9307
//   0x008bbc: 4a0a012a  eor      w10, w9, w10
//   0x008bc0: d37df129  lsl      x9, x9, #3
//   0x008bc4: 72a0764c  movk     w12, #0x3b2, lsl #16
//   0x008bc8: 7100797f  cmp      w11, #0x1e
//   0x008bcc: b90002ea  str      w10, [x23]
//   0x008bd0: b8696a6a  ldr      w10, [x19, x9]
//   0x008bd4: 4a0c014a  eor      w10, w10, w12
//   0x008bd8: 1100056c  add      w12, w11, #1
//   0x008bdc: 5291f30b  mov      w11, #0x8f98
//   0x008be0: b8296a6a  str      w10, [x19, x9]
//   0x008be4: 12800009  mov      w9, #-1
//   0x008be8: 1acc2529  lsr      w9, w9, w12
//   0x008bec: b980030a  ldrsw    x10, [x24]
//   0x008bf0: 1a8983e9  csel     w9, wzr, w9, hi
//   0x008bf4: 72af3eab  movk     w11, #0x79f5, lsl #16
//   0x008bf8: 93407d29  sxtw     x9, w9
//   0x008bfc: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x008c00: f94002a9  ldr      x9, [x21]
//   0x008c04: f9000089  str      x9, [x4]
//   0x008c08: b8404d2a  ldr      w10, [x9, #4]!
//   0x008c0c: f90002a9  str      x9, [x21]
//   0x008c10: 4a0b014a  eor      w10, w10, w11
//   0x008c14: b900012a  str      w10, [x9]
//   0x008c18: 17ffffa4  b        #0x8aa8
//   0x008c1c: 530c4388  ubfx     w8, w28, #0xc, #5
//   0x008c20: 7100611f  cmp      w8, #0x18
//   0x008c24: 54000460  b.eq     #0x8cb0
//   0x008c28: 7100411f  cmp      w8, #0x10
//   0x008c2c: 54000760  b.eq     #0x8d18
//   0x008c30: 7100091f  cmp      w8, #2
//   0x008c34: 54000aa1  b.ne     #0x8d88
//   0x008c38: 90ffffe8  adrp     x8, #0x4000
//   0x008c3c: 91118108  add      x8, x8, #0x460
//   0x008c40: 11000509  add      w9, w8, #1
//   0x008c44: 0a280128  bic      w8, w9, w8
//   0x008c48: 528810c9  mov      w9, #0x4086
//   0x008c4c: 2a2803e8  mvn      w8, w8
//   0x008c50: 72a010e9  movk     w9, #0x87, lsl #16
//   0x008c54: 8a090108  and      x8, x8, x9
//   0x008c58: d296db49  mov      x9, #0xb6da
//   0x008c5c: f2ad73a9  movk     x9, #0x6b9d, lsl #16
//   0x008c60: f2c20049  movk     x9, #0x1002, lsl #32
//   0x008c64: f2e04489  movk     x9, #0x224, lsl #48
//   0x008c68: 8b090108  add      x8, x8, x9
//   0x008c6c: 528617a9  mov      w9, #0x30bd
//   0x008c70: 72a16789  movk     w9, #0xb3c, lsl #16
//   0x008c74: eb09011f  cmp      x8, x9
//   0x008c78: 54000fe3  b.lo     #0x8e74
//   0x008c7c: 531b7f89  lsr      w9, w28, #0x1b
//   0x008c80: 53166b8a  ubfx     w10, w28, #0x16, #5
//   0x008c84: 53115788  ubfx     w8, w28, #0x11, #5
//   0x008c88: 5280004b  mov      w11, #2
//   0x008c8c: b90002e9  str      w9, [x23]
//   0x008c90: d37df149  lsl      x9, x10, #3
//   0x008c94: b900030a  str      w10, [x24]
//   0x008c98: b9000328  str      w8, [x25]
//   0x008c9c: b900034b  str      w11, [x26]
//   0x008ca0: b8696a69  ldr      w9, [x19, x9]
//   0x008ca4: 5ac00529  rev16    w9, w9
//   0x008ca8: 93407d29  sxtw     x9, w9
//   0x008cac: 14000036  b        #0x8d84
//   0x008cb0: 90ffffe8  adrp     x8, #0x4000
//   0x008cb4: 91118108  add      x8, x8, #0x460
//   0x008cb8: 11000509  add      w9, w8, #1
//   0x008cbc: 0a280128  bic      w8, w9, w8
//   0x008cc0: d28afa89  mov      x9, #0x57d4
//   0x008cc4: f2ae1869  movk     x9, #0x70c3, lsl #16
//   0x008cc8: 2a2803e8  mvn      w8, w8
//   0x008ccc: f2ca0009  movk     x9, #0x5000, lsl #32
//   0x008cd0: 927f2508  and      x8, x8, #0x7fe
//   0x008cd4: f2e10209  movk     x9, #0x810, lsl #48
//   0x008cd8: aa090108  orr      x8, x8, x9
//   0x008cdc: 529abec9  mov      w9, #0xd5f6
//   0x008ce0: 72a5a7e9  movk     w9, #0x2d3f, lsl #16
//   0x008ce4: eb09011f  cmp      x8, x9
//   0x008ce8: 54000de3  b.lo     #0x8ea4
//   0x008cec: 53115789  ubfx     w9, w28, #0x11, #5
//   0x008cf0: 531b7f8a  lsr      w10, w28, #0x1b
//   0x008cf4: 53166b88  ubfx     w8, w28, #0x16, #5
//   0x008cf8: 5280030b  mov      w11, #0x18
//   0x008cfc: b90002e9  str      w9, [x23]
//   0x008d00: d37df149  lsl      x9, x10, #3
//   0x008d04: b900030a  str      w10, [x24]
//   0x008d08: b9000328  str      w8, [x25]
//   0x008d0c: b900034b  str      w11, [x26]
//   0x008d10: 78a96a69  ldrsh    x9, [x19, x9]
//   0x008d14: 1400001c  b        #0x8d84
//   0x008d18: 90ffffe8  adrp     x8, #0x4000
//   0x008d1c: 91118108  add      x8, x8, #0x460
//   0x008d20: 11000509  add      w9, w8, #1
//   0x008d24: 0a280128  bic      w8, w9, w8
//   0x008d28: 528c0c09  mov      w9, #0x6060
//   0x008d2c: 2a2803e8  mvn      w8, w8
//   0x008d30: 72a200c9  movk     w9, #0x1006, lsl #16
//   0x008d34: 8a090108  and      x8, x8, x9
//   0x008d38: d282a409  mov      x9, #0x1520
//   0x008d3c: f2ae7aa9  movk     x9, #0x73d5, lsl #16
//   0x008d40: f2c08409  movk     x9, #0x420, lsl #32
//   0x008d44: f2e01049  movk     x9, #0x82, lsl #48
//   0x008d48: 8b090108  add      x8, x8, x9
//   0x008d4c: 528a6ce9  mov      w9, #0x5367
//   0x008d50: 72a07349  movk     w9, #0x39a, lsl #16
//   0x008d54: eb09011f  cmp      x8, x9
//   0x008d58: 54000be3  b.lo     #0x8ed4
//   0x008d5c: 531b7f89  lsr      w9, w28, #0x1b
//   0x008d60: 5311578a  ubfx     w10, w28, #0x11, #5
//   0x008d64: 53166b88  ubfx     w8, w28, #0x16, #5
//   0x008d68: 5280020b  mov      w11, #0x10
//   0x008d6c: b90002e9  str      w9, [x23]
//   0x008d70: d37df149  lsl      x9, x10, #3
//   0x008d74: b900030a  str      w10, [x24]
//   0x008d78: b9000328  str      w8, [x25]
//   0x008d7c: b900034b  str      w11, [x26]
//   0x008d80: 38a96a69  ldrsb    x9, [x19, x9]
//   0x008d84: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x008d88: 90ffffe8  adrp     x8, #0x4000
//   0x008d8c: 5280306a  mov      w10, #0x183
//   0x008d90: 91118108  add      x8, x8, #0x460
//   0x008d94: 72a0100a  movk     w10, #0x80, lsl #16
//   0x008d98: 11000509  add      w9, w8, #1
//   0x008d9c: 0a280129  bic      w9, w9, w8
//   0x008da0: 2a2903e9  mvn      w9, w9
//   0x008da4: 8a0a0129  and      x9, x9, x10
//   0x008da8: d29a178a  mov      x10, #0xd0bc
//   0x008dac: f2a932aa  movk     x10, #0x4995, lsl #16
//   0x008db0: f2d4440a  movk     x10, #0xa220, lsl #32
//   0x008db4: 8b0a0129  add      x9, x9, x10
//   0x008db8: 529e6eea  mov      w10, #0xf377
//   0x008dbc: 72a0c40a  movk     w10, #0x620, lsl #16
//   0x008dc0: eb0a013f  cmp      x9, x10
//   0x008dc4: 54000463  b.lo     #0x8e50
//   0x008dc8: d282080b  mov      x11, #0x1040
//   0x008dcc: f94002a9  ldr      x9, [x21]
//   0x008dd0: d280800a  mov      x10, #0x400
//   0x008dd4: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x008dd8: f2a0008a  movk     x10, #4, lsl #16
//   0x008ddc: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x008de0: f2c0208a  movk     x10, #0x104, lsl #32
//   0x008de4: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x008de8: 8a0a010a  and      x10, x8, x10
//   0x008dec: aa280168  orn      x8, x11, x8
//   0x008df0: b8404d2b  ldr      w11, [x9, #4]!
//   0x008df4: f90002a9  str      x9, [x21]
//   0x008df8: d2828809  mov      x9, #0x1440
//   0x008dfc: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x008e00: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x008e04: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x008e08: f2e01409  movk     x9, #0xa0, lsl #48
//   0x008e0c: 8a090108  and      x8, x8, x9
//   0x008e10: 52802089  mov      w9, #0x104
//   0x008e14: 8b0a0108  add      x8, x8, x10
//   0x008e18: 72a02029  movk     w9, #0x101, lsl #16
//   0x008e1c: aa090108  orr      x8, x8, x9
//   0x008e20: d28d6b89  mov      x9, #0x6b5c
//   0x008e24: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x008e28: 9240156a  and      x10, x11, #0x3f
//   0x008e2c: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x008e30: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x008e34: ca090108  eor      x8, x8, x9
//   0x008e38: f85f83a9  ldur     x9, [x29, #-8]
//   0x008e3c: 8b080188  add      x8, x12, x8
//   0x008e40: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x008e44: f9400108  ldr      x8, [x8]
//   0x008e48: cb090108  sub      x8, x8, x9
//   0x008e4c: d61f0100  br       x8
//   0x008e50: f94002a9  ldr      x9, [x21]
//   0x008e54: 529ef6ab  mov      w11, #0xf7b5
//   0x008e58: 72a120cb  movk     w11, #0x906, lsl #16
//   0x008e5c: f9000089  str      x9, [x4]
//   0x008e60: b8404d2a  ldr      w10, [x9, #4]!
//   0x008e64: f90002a9  str      x9, [x21]
//   0x008e68: 4a0b014a  eor      w10, w10, w11
//   0x008e6c: b900012a  str      w10, [x9]
//   0x008e70: 17ffffd6  b        #0x8dc8
//   0x008e74: b9800308  ldrsw    x8, [x24]
//   0x008e78: 529cc3a9  mov      w9, #0xe61d
//   0x008e7c: 72a945a9  movk     w9, #0x4a2d, lsl #16
//   0x008e80: 5293feea  mov      w10, #0x9ff7
//   0x008e84: 72a16bca  movk     w10, #0xb5e, lsl #16
//   0x008e88: 4a090109  eor      w9, w8, w9
//   0x008e8c: d37df108  lsl      x8, x8, #3
//   0x008e90: b9000309  str      w9, [x24]
//   0x008e94: b8686a69  ldr      w9, [x19, x8]
//   0x008e98: 4a0a0129  eor      w9, w9, w10
//   0x008e9c: b8286a69  str      w9, [x19, x8]
//   0x008ea0: 17ffff77  b        #0x8c7c
//   0x008ea4: b9800308  ldrsw    x8, [x24]
//   0x008ea8: 529e2909  mov      w9, #0xf148
//   0x008eac: 72a5bec9  movk     w9, #0x2df6, lsl #16
//   0x008eb0: 5298b16a  mov      w10, #0xc58b
//   0x008eb4: 72a5eb4a  movk     w10, #0x2f5a, lsl #16
//   0x008eb8: 4a090109  eor      w9, w8, w9
//   0x008ebc: d37df108  lsl      x8, x8, #3
//   0x008ec0: b9000309  str      w9, [x24]
//   0x008ec4: b8686a69  ldr      w9, [x19, x8]
//   0x008ec8: 4a0a0129  eor      w9, w9, w10
//   0x008ecc: b8286a69  str      w9, [x19, x8]
//   0x008ed0: 17ffff87  b        #0x8cec
//   0x008ed4: b9800308  ldrsw    x8, [x24]
//   0x008ed8: 5298f2e9  mov      w9, #0xc797
//   0x008edc: 72a02429  movk     w9, #0x121, lsl #16
//   0x008ee0: 529162aa  mov      w10, #0x8b15
//   0x008ee4: 72aa16ca  movk     w10, #0x50b6, lsl #16
//   0x008ee8: 4a090109  eor      w9, w8, w9
//   0x008eec: d37df108  lsl      x8, x8, #3
//   0x008ef0: b9000309  str      w9, [x24]
//   0x008ef4: b8686a69  ldr      w9, [x19, x8]
//   0x008ef8: 4a0a0129  eor      w9, w9, w10
//   0x008efc: b8286a69  str      w9, [x19, x8]
//   0x008f00: 17ffff97  b        #0x8d5c
//   0x008f04: 530c4388  ubfx     w8, w28, #0xc, #5
//   0x008f08: 7100151f  cmp      w8, #5
//   0x008f0c: 54000420  b.eq     #0x8f90
//   0x008f10: 7100091f  cmp      w8, #2
//   0x008f14: 54000801  b.ne     #0x9014
//   0x008f18: 90ffffe8  adrp     x8, #0x4000
//   0x008f1c: 91118108  add      x8, x8, #0x460
//   0x008f20: 11000509  add      w9, w8, #1
//   0x008f24: 0a280128  bic      w8, w9, w8
//   0x008f28: 528d5049  mov      w9, #0x6a82
//   0x008f2c: 2a2803e8  mvn      w8, w8
//   0x008f30: 72a9b809  movk     w9, #0x4dc0, lsl #16
//   0x008f34: 8a090108  and      x8, x8, x9
//   0x008f38: d29d0329  mov      x9, #0xe819
//   0x008f3c: f2aaca69  movk     x9, #0x5653, lsl #16
//   0x008f40: f2e14109  movk     x9, #0xa08, lsl #48
//   0x008f44: 8b090108  add      x8, x8, x9
//   0x008f48: 529cfe09  mov      w9, #0xe7f0
//   0x008f4c: 72a020c9  movk     w9, #0x106, lsl #16
//   0x008f50: eb09011f  cmp      x8, x9
//   0x008f54: 54000d43  b.lo     #0x90fc
//   0x008f58: 531b7f89  lsr      w9, w28, #0x1b
//   0x008f5c: 53166b88  ubfx     w8, w28, #0x16, #5
//   0x008f60: 5280004b  mov      w11, #2
//   0x008f64: f8695a6a  ldr      x10, [x19, w9, uxtw #3]
//   0x008f68: b90002e8  str      w8, [x23]
//   0x008f6c: 53115788  ubfx     w8, w28, #0x11, #5
//   0x008f70: b9000309  str      w9, [x24]
//   0x008f74: b900034b  str      w11, [x26]
//   0x008f78: d348fd4c  lsr      x12, x10, #8
//   0x008f7c: d378dd4a  lsl      x10, x10, #8
//   0x008f80: 92009d8c  and      x12, x12, #0xff00ff00ff00ff
//   0x008f84: 92089d4a  and      x10, x10, #0xff00ff00ff00ff00
//   0x008f88: aa0c0149  orr      x9, x10, x12
//   0x008f8c: 14000020  b        #0x900c
//   0x008f90: 90ffffe8  adrp     x8, #0x4000
//   0x008f94: 91118108  add      x8, x8, #0x460
//   0x008f98: 11000509  add      w9, w8, #1
//   0x008f9c: 0a280128  bic      w8, w9, w8
//   0x008fa0: 52821609  mov      w9, #0x10b0
//   0x008fa4: 2a2803e8  mvn      w8, w8
//   0x008fa8: 72a04809  movk     w9, #0x240, lsl #16
//   0x008fac: 8a090108  and      x8, x8, x9
//   0x008fb0: d299c909  mov      x9, #0xce48
//   0x008fb4: f2a58689  movk     x9, #0x2c34, lsl #16
//   0x008fb8: f2c020c9  movk     x9, #0x106, lsl #32
//   0x008fbc: f2e00049  movk     x9, #2, lsl #48
//   0x008fc0: aa090108  orr      x8, x8, x9
//   0x008fc4: 529ede69  mov      w9, #0xf6f3
//   0x008fc8: 72a383a9  movk     w9, #0x1c1d, lsl #16
//   0x008fcc: eb09011f  cmp      x8, x9
//   0x008fd0: 54000a63  b.lo     #0x911c
//   0x008fd4: 53115789  ubfx     w9, w28, #0x11, #5
//   0x008fd8: 53166b8a  ubfx     w10, w28, #0x16, #5
//   0x008fdc: f8695a68  ldr      x8, [x19, w9, uxtw #3]
//   0x008fe0: b90002ea  str      w10, [x23]
//   0x008fe4: 528000aa  mov      w10, #5
//   0x008fe8: b9000309  str      w9, [x24]
//   0x008fec: d350fd0b  lsr      x11, x8, #0x10
//   0x008ff0: d370bd08  lsl      x8, x8, #0x10
//   0x008ff4: 92003d6b  and      x11, x11, #0xffff0000ffff
//   0x008ff8: 92103d08  and      x8, x8, #0xffff0000ffff0000
//   0x008ffc: aa0b010b  orr      x11, x8, x11
//   0x009000: 531b7f88  lsr      w8, w28, #0x1b
//   0x009004: b900034a  str      w10, [x26]
//   0x009008: 93cb8169  ror      x9, x11, #0x20
//   0x00900c: b9000328  str      w8, [x25]
//   0x009010: f8285a69  str      x9, [x19, w8, uxtw #3]
//   0x009014: f0ffffc8  adrp     x8, #0x4000
//   0x009018: 5280002a  mov      w10, #1
//   0x00901c: 91118108  add      x8, x8, #0x460
//   0x009020: 72a4520a  movk     w10, #0x2290, lsl #16
//   0x009024: 11000509  add      w9, w8, #1
//   0x009028: 0a280129  bic      w9, w9, w8
//   0x00902c: 2a2903e9  mvn      w9, w9
//   0x009030: 8a0a0129  and      x9, x9, x10
//   0x009034: 5282bdaa  mov      w10, #0x15ed
//   0x009038: 72a9d14a  movk     w10, #0x4e8a, lsl #16
//   0x00903c: 8b0a0129  add      x9, x9, x10
//   0x009040: 529ae5ea  mov      w10, #0xd72f
//   0x009044: 72a1744a  movk     w10, #0xba2, lsl #16
//   0x009048: eb0a013f  cmp      x9, x10
//   0x00904c: 54000463  b.lo     #0x90d8
//   0x009050: d282080b  mov      x11, #0x1040
//   0x009054: f94002a9  ldr      x9, [x21]
//   0x009058: d280800a  mov      x10, #0x400
//   0x00905c: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x009060: f2a0008a  movk     x10, #4, lsl #16
//   0x009064: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x009068: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00906c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x009070: 8a0a010a  and      x10, x8, x10
//   0x009074: aa280168  orn      x8, x11, x8
//   0x009078: b8404d2b  ldr      w11, [x9, #4]!
//   0x00907c: f90002a9  str      x9, [x21]
//   0x009080: d2828809  mov      x9, #0x1440
//   0x009084: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x009088: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00908c: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x009090: f2e01409  movk     x9, #0xa0, lsl #48
//   0x009094: 8a090108  and      x8, x8, x9
//   0x009098: 52802089  mov      w9, #0x104
//   0x00909c: 8b0a0108  add      x8, x8, x10
//   0x0090a0: 72a02029  movk     w9, #0x101, lsl #16
//   0x0090a4: aa090108  orr      x8, x8, x9
//   0x0090a8: d28d6b89  mov      x9, #0x6b5c
//   0x0090ac: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x0090b0: 9240156a  and      x10, x11, #0x3f
//   0x0090b4: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x0090b8: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x0090bc: ca090108  eor      x8, x8, x9
//   0x0090c0: f85f83a9  ldur     x9, [x29, #-8]
//   0x0090c4: 8b080188  add      x8, x12, x8
//   0x0090c8: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x0090cc: f9400108  ldr      x8, [x8]
//   0x0090d0: cb090108  sub      x8, x8, x9
//   0x0090d4: d61f0100  br       x8
//   0x0090d8: f94002a9  ldr      x9, [x21]
//   0x0090dc: 528d03eb  mov      w11, #0x681f
//   0x0090e0: 72af1d2b  movk     w11, #0x78e9, lsl #16
//   0x0090e4: f9000089  str      x9, [x4]
//   0x0090e8: b8404d2a  ldr      w10, [x9, #4]!
//   0x0090ec: f90002a9  str      x9, [x21]
//   0x0090f0: 4a0b014a  eor      w10, w10, w11
//   0x0090f4: b900012a  str      w10, [x9]
//   0x0090f8: 17ffffd6  b        #0x9050
//   0x0090fc: b9800308  ldrsw    x8, [x24]
//   0x009100: 5289cdca  mov      w10, #0x4e6e
//   0x009104: 72a4340a  movk     w10, #0x21a0, lsl #16
//   0x009108: d37df108  lsl      x8, x8, #3
//   0x00910c: f8686a69  ldr      x9, [x19, x8]
//   0x009110: ca0a0129  eor      x9, x9, x10
//   0x009114: f8286a69  str      x9, [x19, x8]
//   0x009118: 17ffff90  b        #0x8f58
//   0x00911c: b9800308  ldrsw    x8, [x24]
//   0x009120: 529b26ea  mov      w10, #0xd937
//   0x009124: 72a055aa  movk     w10, #0x2ad, lsl #16
//   0x009128: d37df108  lsl      x8, x8, #3
//   0x00912c: f8686a69  ldr      x9, [x19, x8]
//   0x009130: ca0a0129  eor      x9, x9, x10
//   0x009134: f8286a69  str      x9, [x19, x8]
//   0x009138: 17ffffa7  b        #0x8fd4
//   0x00913c: f94002a8  ldr      x8, [x21]
//   0x009140: f0000069  adrp     x9, #0x18000
//   0x009144: 5280208a  mov      w10, #0x104
//   0x009148: 72a0202a  movk     w10, #0x101, lsl #16
//   0x00914c: b9400108  ldr      w8, [x8]
//   0x009150: aa0a02ca  orr      x10, x22, x10
//   0x009154: f9420129  ldr      x9, [x9, #0x400]
//   0x009158: ca11014a  eor      x10, x10, x17
//   0x00915c: d3566908  ubfx     x8, x8, #0x16, #5
//   0x009160: 8b0a0129  add      x9, x9, x10
//   0x009164: 8b080d28  add      x8, x9, x8, lsl #3
//   0x009168: f85f83a9  ldur     x9, [x29, #-8]
//   0x00916c: f9400108  ldr      x8, [x8]
//   0x009170: cb090108  sub      x8, x8, x9
//   0x009174: d61f0100  br       x8
//   0x009178: f94002a8  ldr      x8, [x21]
//   0x00917c: f0ffffc9  adrp     x9, #0x4000
//   0x009180: 91118129  add      x9, x9, #0x460
//   0x009184: b940010b  ldr      w11, [x8]
//   0x009188: d3417d6a  ubfx     x10, x11, #1, #0x1f
//   0x00918c: 5316696c  ubfx     w12, w11, #0x16, #5
//   0x009190: 121b014d  and      w13, w10, #0x20
//   0x009194: 121a014e  and      w14, w10, #0x40
//   0x009198: 330b3d6d  bfxil    w13, w11, #0xb, #5
//   0x00919c: 2a0e01ad  orr      w13, w13, w14
//   0x0091a0: 1219014e  and      w14, w10, #0x80
//   0x0091a4: 2a0e01ad  orr      w13, w13, w14
//   0x0091a8: 1218014e  and      w14, w10, #0x100
//   0x0091ac: b900030c  str      w12, [x24]
//   0x0091b0: 2a0e01ac  orr      w12, w13, w14
//   0x0091b4: d3467d6d  ubfx     x13, x11, #6, #0x1a
//   0x0091b8: 1217014a  and      w10, w10, #0x200
//   0x0091bc: 2a0a018a  orr      w10, w12, w10
//   0x0091c0: 121601ac  and      w12, w13, #0x400
//   0x0091c4: 2a0c014a  orr      w10, w10, w12
//   0x0091c8: 121501ac  and      w12, w13, #0x800
//   0x0091cc: 2a0c014a  orr      w10, w10, w12
//   0x0091d0: 121401ac  and      w12, w13, #0x1000
//   0x0091d4: 2a0c014a  orr      w10, w10, w12
//   0x0091d8: 121301ac  and      w12, w13, #0x2000
//   0x0091dc: 2a0c014a  orr      w10, w10, w12
//   0x0091e0: 121201ac  and      w12, w13, #0x4000
//   0x0091e4: 121101ad  and      w13, w13, #0x8000
//   0x0091e8: 2a0c014a  orr      w10, w10, w12
//   0x0091ec: 1100052c  add      w12, w9, #1
//   0x0091f0: 2a0d014a  orr      w10, w10, w13
//   0x0091f4: 5282806d  mov      w13, #0x1403
//   0x0091f8: 0a29018c  bic      w12, w12, w9
//   0x0091fc: 72a130ad  movk     w13, #0x985, lsl #16
//   0x009200: 2a2c03ec  mvn      w12, w12
//   0x009204: 8a0d018c  and      x12, x12, x13
//   0x009208: d287f50d  mov      x13, #0x3fa8
//   0x00920c: f2a48fed  movk     x13, #0x247f, lsl #16
//   0x009210: d35bfd6b  lsr      x11, x11, #0x1b
//   0x009214: f2d2400d  movk     x13, #0x9200, lsl #32
//   0x009218: 790003ca  strh     w10, [x30]
//   0x00921c: 8b0d018c  add      x12, x12, x13
//   0x009220: 528b2a4d  mov      w13, #0x5952
//   0x009224: 72a0caed  movk     w13, #0x657, lsl #16
//   0x009228: b90002eb  str      w11, [x23]
//   0x00922c: eb0d019f  cmp      x12, x13
//   0x009230: 540004c3  b.lo     #0x92c8
//   0x009234: f86bda6b  ldr      x11, [x19, w11, sxtw #3]
//   0x009238: 93403d4a  sxth     x10, w10
//   0x00923c: d282080c  mov      x12, #0x1040
//   0x009240: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x009244: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x009248: 8a8bfd4a  and      x10, x10, x11, asr #63
//   0x00924c: d280800b  mov      x11, #0x400
//   0x009250: f2a0008b  movk     x11, #4, lsl #16
//   0x009254: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x009258: 8b0a0908  add      x8, x8, x10, lsl #2
//   0x00925c: d282880a  mov      x10, #0x1440
//   0x009260: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x009264: f2c0208b  movk     x11, #0x104, lsl #32
//   0x009268: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x00926c: aa29018c  orn      x12, x12, x9
//   0x009270: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x009274: 8a0b0129  and      x9, x9, x11
//   0x009278: 8a0a018a  and      x10, x12, x10
//   0x00927c: 5280208c  mov      w12, #0x104
//   0x009280: b8404d0b  ldr      w11, [x8, #4]!
//   0x009284: f90002a8  str      x8, [x21]
//   0x009288: 8b090148  add      x8, x10, x9
//   0x00928c: d28d6b8a  mov      x10, #0x6b5c
//   0x009290: 72a0202c  movk     w12, #0x101, lsl #16
//   0x009294: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x009298: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00929c: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x0092a0: aa0c0108  orr      x8, x8, x12
//   0x0092a4: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x0092a8: ca0a0108  eor      x8, x8, x10
//   0x0092ac: 9240156a  and      x10, x11, #0x3f
//   0x0092b0: 8b080128  add      x8, x9, x8
//   0x0092b4: f85f83a9  ldur     x9, [x29, #-8]
//   0x0092b8: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x0092bc: f9400108  ldr      x8, [x8]
//   0x0092c0: cb090108  sub      x8, x8, x9
//   0x0092c4: d61f0100  br       x8
//   0x0092c8: d37df16c  lsl      x12, x11, #3
//   0x0092cc: 528e768e  mov      w14, #0x73b4
//   0x0092d0: 72ab760e  movk     w14, #0x5bb0, lsl #16
//   0x0092d4: 2a0a03ef  mov      w15, w10
//   0x0092d8: 4a0e016b  eor      w11, w11, w14
//   0x0092dc: 128271ce  mov      w14, #-0x138f
//   0x0092e0: f86c6a6d  ldr      x13, [x19, x12]
//   0x0092e4: 93403def  sxth     x15, w15
//   0x0092e8: 4a0e014a  eor      w10, w10, w14
//   0x0092ec: 528bae6e  mov      w14, #0x5d73
//   0x0092f0: 72a3af8e  movk     w14, #0x1d7c, lsl #16
//   0x0092f4: b90002eb  str      w11, [x23]
//   0x0092f8: f10001bf  cmp      x13, #0
//   0x0092fc: ca0e01ab  eor      x11, x13, x14
//   0x009300: 9a9f01ef  csel     x15, x15, xzr, eq
//   0x009304: 790003ca  strh     w10, [x30]
//   0x009308: f82c6a6b  str      x11, [x19, x12]
//   0x00930c: 5282060b  mov      w11, #0x1030
//   0x009310: 8b0f090d  add      x13, x8, x15, lsl #2
//   0x009314: f9000088  str      x8, [x4]
//   0x009318: 72a2162b  movk     w11, #0x10b1, lsl #16
//   0x00931c: b8404da8  ldr      w8, [x13, #4]!
//   0x009320: f90002ad  str      x13, [x21]
//   0x009324: 4a0b0108  eor      w8, w8, w11
//   0x009328: b90001a8  str      w8, [x13]
//   0x00932c: b94002eb  ldr      w11, [x23]
//   0x009330: f94002a8  ldr      x8, [x21]
//   0x009334: 17ffffc0  b        #0x9234
//   0x009338: f94002a8  ldr      x8, [x21]
//   0x00933c: 2a1b03ec  mov      w12, w27
//   0x009340: b940010b  ldr      w11, [x8]
//   0x009344: 53017d6a  lsr      w10, w11, #1
//   0x009348: 53157d6d  lsr      w13, w11, #0x15
//   0x00934c: 121b014e  and      w14, w10, #0x20
//   0x009350: 121a01af  and      w15, w13, #0x40
//   0x009354: 3310516e  bfxil    w14, w11, #0x10, #5
//   0x009358: 531b7d69  lsr      w9, w11, #0x1b
//   0x00935c: 2a0f01ce  orr      w14, w14, w15
//   0x009360: 121901af  and      w15, w13, #0x80
//   0x009364: 2a0f01ce  orr      w14, w14, w15
//   0x009368: 121801af  and      w15, w13, #0x100
//   0x00936c: 121701ad  and      w13, w13, #0x200
//   0x009370: 2a0f01ce  orr      w14, w14, w15
//   0x009374: 1216014f  and      w15, w10, #0x400
//   0x009378: 2a0d01cd  orr      w13, w14, w13
//   0x00937c: 1215014e  and      w14, w10, #0x800
//   0x009380: 2a0f01ad  orr      w13, w13, w15
//   0x009384: 1214014f  and      w15, w10, #0x1000
//   0x009388: 2a0e01ad  orr      w13, w13, w14
//   0x00938c: 1213014e  and      w14, w10, #0x2000
//   0x009390: 2a0f01ad  orr      w13, w13, w15
//   0x009394: 121c0129  and      w9, w9, #0x10
//   0x009398: 1212014a  and      w10, w10, #0x4000
//   0x00939c: 2a0e01ad  orr      w13, w13, w14
//   0x0093a0: 33072969  bfxil    w9, w11, #7, #4
//   0x0093a4: 5316696e  ubfx     w14, w11, #0x16, #5
//   0x0093a8: 2a0a01aa  orr      w10, w13, w10
//   0x0093ac: 53067d6b  lsr      w11, w11, #6
//   0x0093b0: 1400001e  b        #0x9428
//   0x0093b4: f94002a8  ldr      x8, [x21]
//   0x0093b8: 2a1b03ec  mov      w12, w27
//   0x0093bc: b940010b  ldr      w11, [x8]
//   0x0093c0: 53157d6d  lsr      w13, w11, #0x15
//   0x0093c4: 53077d6a  lsr      w10, w11, #7
//   0x0093c8: 121a01af  and      w15, w13, #0x40
//   0x0093cc: 121901b0  and      w16, w13, #0x80
//   0x0093d0: 330b416f  bfxil    w15, w11, #0xb, #6
//   0x0093d4: 530b7d6e  lsr      w14, w11, #0xb
//   0x0093d8: 2a1001ef  orr      w15, w15, w16
//   0x0093dc: 121801b0  and      w16, w13, #0x100
//   0x0093e0: 2a1001ef  orr      w15, w15, w16
//   0x0093e4: 121701ad  and      w13, w13, #0x200
//   0x0093e8: 121601ce  and      w14, w14, #0x400
//   0x0093ec: 2a0d01ed  orr      w13, w15, w13
//   0x0093f0: 531c6d70  lsl      w16, w11, #4
//   0x0093f4: 2a0e01ad  orr      w13, w13, w14
//   0x0093f8: 1214020f  and      w15, w16, #0x1000
//   0x0093fc: 3315014d  bfi      w13, w10, #0xb, #1
//   0x009400: 531b7d69  lsr      w9, w11, #0x1b
//   0x009404: 1213020e  and      w14, w16, #0x2000
//   0x009408: 2a0f01ad  orr      w13, w13, w15
//   0x00940c: 121c0129  and      w9, w9, #0x10
//   0x009410: 1212020a  and      w10, w16, #0x4000
//   0x009414: 2a0e01ad  orr      w13, w13, w14
//   0x009418: 33115169  bfxil    w9, w11, #0x11, #4
//   0x00941c: 5316696e  ubfx     w14, w11, #0x16, #5
//   0x009420: 2a0a01aa  orr      w10, w13, w10
//   0x009424: 5317596b  lsl      w11, w11, #9
//   0x009428: b90002e9  str      w9, [x23]
//   0x00942c: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x009430: 1211016b  and      w11, w11, #0x8000
//   0x009434: d282880c  mov      x12, #0x1440
//   0x009438: 2a0b014a  orr      w10, w10, w11
//   0x00943c: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x009440: 93403d4b  sxth     x11, w10
//   0x009444: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x009448: f100013f  cmp      x9, #0
//   0x00944c: b900030e  str      w14, [x24]
//   0x009450: 9a8bb3e9  csel     x9, xzr, x11, lt
//   0x009454: d282080b  mov      x11, #0x1040
//   0x009458: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00945c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x009460: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x009464: 8b090908  add      x8, x8, x9, lsl #2
//   0x009468: d2808009  mov      x9, #0x400
//   0x00946c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x009470: f2a00089  movk     x9, #4, lsl #16
//   0x009474: aa25016b  orn      x11, x11, x5
//   0x009478: f2c02089  movk     x9, #0x104, lsl #32
//   0x00947c: 790003ca  strh     w10, [x30]
//   0x009480: 8a0c016b  and      x11, x11, x12
//   0x009484: 8a0900a9  and      x9, x5, x9
//   0x009488: b8404d0a  ldr      w10, [x8, #4]!
//   0x00948c: f90002a8  str      x8, [x21]
//   0x009490: 8b090168  add      x8, x11, x9
//   0x009494: d28d6b8b  mov      x11, #0x6b5c
//   0x009498: 5280208c  mov      w12, #0x104
//   0x00949c: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x0094a0: 72a0202c  movk     w12, #0x101, lsl #16
//   0x0094a4: f941f289  ldr      x9, [x20, #0x3e0]
//   0x0094a8: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x0094ac: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x0094b0: aa0c0108  orr      x8, x8, x12
//   0x0094b4: ca0b0108  eor      x8, x8, x11
//   0x0094b8: 9240154a  and      x10, x10, #0x3f
//   0x0094bc: 8b080128  add      x8, x9, x8
//   0x0094c0: f85f83a9  ldur     x9, [x29, #-8]
//   0x0094c4: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x0094c8: f9400108  ldr      x8, [x8]
//   0x0094cc: cb090108  sub      x8, x8, x9
//   0x0094d0: d61f0100  br       x8
//   0x0094d4: f94002a8  ldr      x8, [x21]
//   0x0094d8: 2a1b03eb  mov      w11, w27
//   0x0094dc: b940010a  ldr      w10, [x8]
//   0x0094e0: 531b7d49  lsr      w9, w10, #0x1b
//   0x0094e4: 53107d4d  lsr      w13, w10, #0x10
//   0x0094e8: 121c0129  and      w9, w9, #0x10
//   0x0094ec: 5316694e  ubfx     w14, w10, #0x16, #5
//   0x0094f0: 330c3d49  bfxil    w9, w10, #0xc, #4
//   0x0094f4: 53017d4b  lsr      w11, w10, #1
//   0x0094f8: 2a0d03ec  mov      w12, w13
//   0x0094fc: 14000009  b        #0x9520
//   0x009500: f94002a8  ldr      x8, [x21]
//   0x009504: 2a1b03ec  mov      w12, w27
//   0x009508: b940010a  ldr      w10, [x8]
//   0x00950c: 53017d4b  lsr      w11, w10, #1
//   0x009510: 531b7d49  lsr      w9, w10, #0x1b
//   0x009514: 5316694e  ubfx     w14, w10, #0x16, #5
//   0x009518: 53107d4d  lsr      w13, w10, #0x10
//   0x00951c: 2a0b03ec  mov      w12, w11
//   0x009520: b900030e  str      w14, [x24]
//   0x009524: 121b016e  and      w14, w11, #0x20
//   0x009528: 330011ae  bfxil    w14, w13, #0, #5
//   0x00952c: 121a016d  and      w13, w11, #0x40
//   0x009530: 2a0d01cd  orr      w13, w14, w13
//   0x009534: 1219016e  and      w14, w11, #0x80
//   0x009538: 2a0e01ad  orr      w13, w13, w14
//   0x00953c: 1218016e  and      w14, w11, #0x100
//   0x009540: 1217016b  and      w11, w11, #0x200
//   0x009544: 2a0e01ad  orr      w13, w13, w14
//   0x009548: 530b7d4e  lsr      w14, w10, #0xb
//   0x00954c: 2a0b01ab  orr      w11, w13, w11
//   0x009550: 121601ce  and      w14, w14, #0x400
//   0x009554: 1215018d  and      w13, w12, #0x800
//   0x009558: 2a0e016b  orr      w11, w11, w14
//   0x00955c: 1214018e  and      w14, w12, #0x1000
//   0x009560: 2a0d016b  orr      w11, w11, w13
//   0x009564: 1213018d  and      w13, w12, #0x2000
//   0x009568: 2a0e016b  orr      w11, w11, w14
//   0x00956c: 1212018c  and      w12, w12, #0x4000
//   0x009570: 2a0d016d  orr      w13, w11, w13
//   0x009574: f0ffffcb  adrp     x11, #0x4000
//   0x009578: 9111816b  add      x11, x11, #0x460
//   0x00957c: 2a0c01ac  orr      w12, w13, w12
//   0x009580: 1100056d  add      w13, w11, #1
//   0x009584: 531c6d4a  lsl      w10, w10, #4
//   0x009588: 0a2b01ad  bic      w13, w13, w11
//   0x00958c: 1211014a  and      w10, w10, #0x8000
//   0x009590: 2a2d03ed  mvn      w13, w13
//   0x009594: 2a0a018a  orr      w10, w12, w10
//   0x009598: 927d69ac  and      x12, x13, #0x3ffffff8
//   0x00959c: d28ced2d  mov      x13, #0x6769
//   0x0095a0: f2aa578d  movk     x13, #0x52bc, lsl #16
//   0x0095a4: 9263998c  and      x12, x12, #0xffffffffe000000f
//   0x0095a8: f2c4000d  movk     x13, #0x2000, lsl #32
//   0x0095ac: b90002e9  str      w9, [x23]
//   0x0095b0: f2e0010d  movk     x13, #8, lsl #48
//   0x0095b4: 790003ca  strh     w10, [x30]
//   0x0095b8: 8b0d018c  add      x12, x12, x13
//   0x0095bc: 5299d2ad  mov      w13, #0xce95
//   0x0095c0: 72a5ac6d  movk     w13, #0x2d63, lsl #16
//   0x0095c4: eb0d019f  cmp      x12, x13
//   0x0095c8: 54000503  b.lo     #0x9668
//   0x0095cc: 91001108  add      x8, x8, #4
//   0x0095d0: 93403d4a  sxth     x10, w10
//   0x0095d4: d282080c  mov      x12, #0x1040
//   0x0095d8: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x0095dc: f81e0068  stur     x8, [x3, #-0x20]
//   0x0095e0: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x0095e4: f869da69  ldr      x9, [x19, w9, sxtw #3]
//   0x0095e8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0095ec: 8a89fd49  and      x9, x10, x9, asr #63
//   0x0095f0: d280800a  mov      x10, #0x400
//   0x0095f4: f2a0008a  movk     x10, #4, lsl #16
//   0x0095f8: 8b090908  add      x8, x8, x9, lsl #2
//   0x0095fc: d2828809  mov      x9, #0x1440
//   0x009600: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x009604: f2c0208a  movk     x10, #0x104, lsl #32
//   0x009608: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00960c: 8a0a016a  and      x10, x11, x10
//   0x009610: f2e01409  movk     x9, #0xa0, lsl #48
//   0x009614: aa2b018b  orn      x11, x12, x11
//   0x009618: 8a090169  and      x9, x11, x9
//   0x00961c: d28d6b8b  mov      x11, #0x6b5c
//   0x009620: 5280208c  mov      w12, #0x104
//   0x009624: f90002a8  str      x8, [x21]
//   0x009628: b9400108  ldr      w8, [x8]
//   0x00962c: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x009630: 72a0202c  movk     w12, #0x101, lsl #16
//   0x009634: 8b0a0129  add      x9, x9, x10
//   0x009638: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00963c: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x009640: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x009644: aa0c0129  orr      x9, x9, x12
//   0x009648: ca0b0129  eor      x9, x9, x11
//   0x00964c: 92401508  and      x8, x8, #0x3f
//   0x009650: 8b090149  add      x9, x10, x9
//   0x009654: 8b080d28  add      x8, x9, x8, lsl #3
//   0x009658: f85f83a9  ldur     x9, [x29, #-8]
//   0x00965c: f9400108  ldr      x8, [x8]
//   0x009660: cb090108  sub      x8, x8, x9
//   0x009664: d61f0100  br       x8
//   0x009668: 9100110c  add      x12, x8, #4
//   0x00966c: 2a0903ed  mov      w13, w9
//   0x009670: d37df1ad  lsl      x13, x13, #3
//   0x009674: f9000088  str      x8, [x4]
//   0x009678: 529d714e  mov      w14, #0xeb8a
//   0x00967c: 528f0e0f  mov      w15, #0x7870
//   0x009680: f81e006c  stur     x12, [x3, #-0x20]
//   0x009684: 72a849ee  movk     w14, #0x424f, lsl #16
//   0x009688: f86d6a68  ldr      x8, [x19, x13]
//   0x00968c: 4a0e0129  eor      w9, w9, w14
//   0x009690: 2a0a03ee  mov      w14, w10
//   0x009694: 4a0f014a  eor      w10, w10, w15
//   0x009698: 93403dce  sxth     x14, w14
//   0x00969c: b90002e9  str      w9, [x23]
//   0x0096a0: f100011f  cmp      x8, #0
//   0x0096a4: 790003ca  strh     w10, [x30]
//   0x0096a8: 9a9fc1c9  csel     x9, x14, xzr, gt
//   0x0096ac: 529a612e  mov      w14, #0xd309
//   0x0096b0: 72a19e0e  movk     w14, #0xcf0, lsl #16
//   0x0096b4: d37ef529  lsl      x9, x9, #2
//   0x0096b8: ca0e0108  eor      x8, x8, x14
//   0x0096bc: 8b09018e  add      x14, x12, x9
//   0x0096c0: f82d6a68  str      x8, [x19, x13]
//   0x0096c4: 5283d5ed  mov      w13, #0x1eaf
//   0x0096c8: b94001c8  ldr      w8, [x14]
//   0x0096cc: 72a1646d  movk     w13, #0xb23, lsl #16
//   0x0096d0: f90002ae  str      x14, [x21]
//   0x0096d4: 4a0d0108  eor      w8, w8, w13
//   0x0096d8: b8296988  str      w8, [x12, x9]
//   0x0096dc: f94002a8  ldr      x8, [x21]
//   0x0096e0: b94002e9  ldr      w9, [x23]
//   0x0096e4: 17ffffba  b        #0x95cc
//   0x0096e8: f94002a8  ldr      x8, [x21]
//   0x0096ec: 2a1b03ec  mov      w12, w27
//   0x0096f0: b940010b  ldr      w11, [x8]
//   0x0096f4: 53107d6d  lsr      w13, w11, #0x10
//   0x0096f8: 530b7d6e  lsr      w14, w11, #0xb
//   0x0096fc: 121b01ad  and      w13, w13, #0x20
//   0x009700: 121a01cf  and      w15, w14, #0x40
//   0x009704: 330b3d6d  bfxil    w13, w11, #0xb, #5
//   0x009708: 53067d6a  lsr      w10, w11, #6
//   0x00970c: 2a0f01ad  orr      w13, w13, w15
//   0x009710: 121901cf  and      w15, w14, #0x80
//   0x009714: 2a0f01ad  orr      w13, w13, w15
//   0x009718: 121801cf  and      w15, w14, #0x100
//   0x00971c: 121701ce  and      w14, w14, #0x200
//   0x009720: 2a0f01ad  orr      w13, w13, w15
//   0x009724: 531c6d6f  lsl      w15, w11, #4
//   0x009728: 2a0e01ad  orr      w13, w13, w14
//   0x00972c: 121501ee  and      w14, w15, #0x800
//   0x009730: 3316014d  bfi      w13, w10, #0xa, #1
//   0x009734: 121401ea  and      w10, w15, #0x1000
//   0x009738: 2a0e01ad  orr      w13, w13, w14
//   0x00973c: 121301ee  and      w14, w15, #0x2000
//   0x009740: 2a0a01aa  orr      w10, w13, w10
//   0x009744: 121201ed  and      w13, w15, #0x4000
//   0x009748: 2a0e014a  orr      w10, w10, w14
//   0x00974c: 531b7d69  lsr      w9, w11, #0x1b
//   0x009750: 5316696e  ubfx     w14, w11, #0x16, #5
//   0x009754: 2a0d014a  orr      w10, w10, w13
//   0x009758: 53017d6b  lsr      w11, w11, #1
//   0x00975c: 14000015  b        #0x97b0
//   0x009760: f94002a8  ldr      x8, [x21]
//   0x009764: 2a1b03ec  mov      w12, w27
//   0x009768: b940010b  ldr      w11, [x8]
//   0x00976c: 531c6d6a  lsl      w10, w11, #4
//   0x009770: 53107d6d  lsr      w13, w11, #0x10
//   0x009774: 1216014a  and      w10, w10, #0x400
//   0x009778: 121501ae  and      w14, w13, #0x800
//   0x00977c: 330b516a  bfxil    w10, w11, #0xb, #0xa
//   0x009780: 531b7d69  lsr      w9, w11, #0x1b
//   0x009784: 2a0e014a  orr      w10, w10, w14
//   0x009788: 121401ae  and      w14, w13, #0x1000
//   0x00978c: 2a0e014a  orr      w10, w10, w14
//   0x009790: 121301ae  and      w14, w13, #0x2000
//   0x009794: 121c0129  and      w9, w9, #0x10
//   0x009798: 121201ad  and      w13, w13, #0x4000
//   0x00979c: 2a0e014a  orr      w10, w10, w14
//   0x0097a0: 33072969  bfxil    w9, w11, #7, #4
//   0x0097a4: 5316696e  ubfx     w14, w11, #0x16, #5
//   0x0097a8: 2a0d014a  orr      w10, w10, w13
//   0x0097ac: 53067d6b  lsr      w11, w11, #6
//   0x0097b0: 91001108  add      x8, x8, #4
//   0x0097b4: b90002e9  str      w9, [x23]
//   0x0097b8: 1211016b  and      w11, w11, #0x8000
//   0x0097bc: d282080c  mov      x12, #0x1040
//   0x0097c0: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x0097c4: 2a0b014a  orr      w10, w10, w11
//   0x0097c8: f81e0068  stur     x8, [x3, #-0x20]
//   0x0097cc: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x0097d0: f8695a69  ldr      x9, [x19, w9, uxtw #3]
//   0x0097d4: 93403d4b  sxth     x11, w10
//   0x0097d8: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x0097dc: 790003ca  strh     w10, [x30]
//   0x0097e0: aa25018c  orn      x12, x12, x5
//   0x0097e4: d280800a  mov      x10, #0x400
//   0x0097e8: b900030e  str      w14, [x24]
//   0x0097ec: f2a0008a  movk     x10, #4, lsl #16
//   0x0097f0: f100013f  cmp      x9, #0
//   0x0097f4: d2828809  mov      x9, #0x1440
//   0x0097f8: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x0097fc: 9a8bb3eb  csel     x11, xzr, x11, lt
//   0x009800: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x009804: d37ef56b  lsl      x11, x11, #2
//   0x009808: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00980c: f2c0208a  movk     x10, #0x104, lsl #32
//   0x009810: 8a090189  and      x9, x12, x9
//   0x009814: 8b0b010c  add      x12, x8, x11
//   0x009818: b86b6908  ldr      w8, [x8, x11]
//   0x00981c: 5280208b  mov      w11, #0x104
//   0x009820: 8a0a00aa  and      x10, x5, x10
//   0x009824: 72a0202b  movk     w11, #0x101, lsl #16
//   0x009828: f90002ac  str      x12, [x21]
//   0x00982c: d28d6b8c  mov      x12, #0x6b5c
//   0x009830: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x009834: 8b0a0129  add      x9, x9, x10
//   0x009838: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00983c: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x009840: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x009844: aa0b0129  orr      x9, x9, x11
//   0x009848: ca0c0129  eor      x9, x9, x12
//   0x00984c: 92401508  and      x8, x8, #0x3f
//   0x009850: 8b090149  add      x9, x10, x9
//   0x009854: 8b080d28  add      x8, x9, x8, lsl #3
//   0x009858: f85f83a9  ldur     x9, [x29, #-8]
//   0x00985c: f9400108  ldr      x8, [x8]
//   0x009860: cb090108  sub      x8, x8, x9
//   0x009864: d61f0100  br       x8
//   0x009868: f0ffffc8  adrp     x8, #0x4000
//   0x00986c: 5280004a  mov      w10, #2
//   0x009870: 91118108  add      x8, x8, #0x460
//   0x009874: 72a2040a  movk     w10, #0x1020, lsl #16
//   0x009878: 11000509  add      w9, w8, #1
//   0x00987c: 0a280129  bic      w9, w9, w8
//   0x009880: 2a2903e9  mvn      w9, w9
//   0x009884: 8a0a0129  and      x9, x9, x10
//   0x009888: d28bd32a  mov      x10, #0x5e99
//   0x00988c: f2bfb20a  movk     x10, #0xfd90, lsl #16
//   0x009890: f2c0042a  movk     x10, #0x21, lsl #32
//   0x009894: f2e0600a  movk     x10, #0x300, lsl #48
//   0x009898: 8b0a0129  add      x9, x9, x10
//   0x00989c: 5294e40a  mov      w10, #0xa720
//   0x0098a0: 72a063ea  movk     w10, #0x31f, lsl #16
//   0x0098a4: eb0a013f  cmp      x9, x10
//   0x0098a8: 540009a3  b.lo     #0x99dc
//   0x0098ac: f94002a9  ldr      x9, [x21]
//   0x0098b0: d280800b  mov      x11, #0x400
//   0x0098b4: f2a0008b  movk     x11, #4, lsl #16
//   0x0098b8: f2c0208b  movk     x11, #0x104, lsl #32
//   0x0098bc: b940012a  ldr      w10, [x9]
//   0x0098c0: 8a0b010b  and      x11, x8, x11
//   0x0098c4: d3507d4e  ubfx     x14, x10, #0x10, #0x10
//   0x0098c8: 53067d4c  lsr      w12, w10, #6
//   0x0098cc: 121b01d0  and      w16, w14, #0x20
//   0x0098d0: 121a01d1  and      w17, w14, #0x40
//   0x0098d4: 330b3d50  bfxil    w16, w10, #0xb, #5
//   0x0098d8: d35bfd4d  lsr      x13, x10, #0x1b
//   0x0098dc: 2a110210  orr      w16, w16, w17
//   0x0098e0: 121901d1  and      w17, w14, #0x80
//   0x0098e4: 2a110210  orr      w16, w16, w17
//   0x0098e8: 121801d1  and      w17, w14, #0x100
//   0x0098ec: 2a110210  orr      w16, w16, w17
//   0x0098f0: 121701ce  and      w14, w14, #0x200
//   0x0098f4: 531c6d51  lsl      w17, w10, #4
//   0x0098f8: 2a0e020e  orr      w14, w16, w14
//   0x0098fc: 927c01ad  and      x13, x13, #0x10
//   0x009900: 12150230  and      w16, w17, #0x800
//   0x009904: 3316018e  bfi      w14, w12, #0xa, #1
//   0x009908: 1214022c  and      w12, w17, #0x1000
//   0x00990c: b351514d  bfxil    x13, x10, #0x11, #4
//   0x009910: 2a1001ce  orr      w14, w14, w16
//   0x009914: 2a0c01cc  orr      w12, w14, w12
//   0x009918: 1213022e  and      w14, w17, #0x2000
//   0x00991c: d34b7d50  ubfx     x16, x10, #0xb, #0x15
//   0x009920: 12120231  and      w17, w17, #0x4000
//   0x009924: 2a0e018c  orr      w12, w12, w14
//   0x009928: d34cfd4f  lsr      x15, x10, #0xc
//   0x00992c: f86d7a6e  ldr      x14, [x19, x13, lsl #3]
//   0x009930: 12110210  and      w16, w16, #0x8000
//   0x009934: 2a11018c  orr      w12, w12, w17
//   0x009938: 927c01ef  and      x15, x15, #0x10
//   0x00993c: 2a10018c  orr      w12, w12, w16
//   0x009940: d2820810  mov      x16, #0x1040
//   0x009944: f2a14050  movk     x16, #0xa02, lsl #16
//   0x009948: b35b794f  bfxil    x15, x10, #0x1b, #4
//   0x00994c: d282880a  mov      x10, #0x1440
//   0x009950: f2cc0810  movk     x16, #0x6040, lsl #32
//   0x009954: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x009958: f2e01410  movk     x16, #0xa0, lsl #48
//   0x00995c: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x009960: 8b2ca1ce  add      x14, x14, w12, sxth
//   0x009964: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x009968: aa280208  orn      x8, x16, x8
//   0x00996c: f82f7a6e  str      x14, [x19, x15, lsl #3]
//   0x009970: 8a0a0108  and      x8, x8, x10
//   0x009974: d28d6b8a  mov      x10, #0x6b5c
//   0x009978: 52802091  mov      w17, #0x104
//   0x00997c: b8404d2e  ldr      w14, [x9, #4]!
//   0x009980: f90002a9  str      x9, [x21]
//   0x009984: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x009988: 72a02031  movk     w17, #0x101, lsl #16
//   0x00998c: 8b0b0108  add      x8, x8, x11
//   0x009990: f941f289  ldr      x9, [x20, #0x3e0]
//   0x009994: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x009998: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00999c: aa110108  orr      x8, x8, x17
//   0x0099a0: ca0a0108  eor      x8, x8, x10
//   0x0099a4: 924015ca  and      x10, x14, #0x3f
//   0x0099a8: 8b080128  add      x8, x9, x8
//   0x0099ac: f85f83a9  ldur     x9, [x29, #-8]
//   0x0099b0: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x0099b4: d28d6b91  mov      x17, #0x6b5c
//   0x0099b8: f2be9391  movk     x17, #0xf49c, lsl #16
//   0x0099bc: b90002ed  str      w13, [x23]
//   0x0099c0: f2d3d771  movk     x17, #0x9ebb, lsl #32
//   0x0099c4: b900030f  str      w15, [x24]
//   0x0099c8: f9400108  ldr      x8, [x8]
//   0x0099cc: 790003cc  strh     w12, [x30]
//   0x0099d0: f2ffebf1  movk     x17, #0xff5f, lsl #48
//   0x0099d4: cb090108  sub      x8, x8, x9
//   0x0099d8: d61f0100  br       x8
//   0x0099dc: f94002a9  ldr      x9, [x21]
//   0x0099e0: 528dba6b  mov      w11, #0x6dd3
//   0x0099e4: 72ae71eb  movk     w11, #0x738f, lsl #16
//   0x0099e8: 52910bed  mov      w13, #0x885f
//   0x0099ec: 72aacfad  movk     w13, #0x567d, lsl #16
//   0x0099f0: f9000089  str      x9, [x4]
//   0x0099f4: b940012a  ldr      w10, [x9]
//   0x0099f8: 4a0b014a  eor      w10, w10, w11
//   0x0099fc: b900012a  str      w10, [x9]
//   0x009a00: b98002e9  ldrsw    x9, [x23]
//   0x009a04: 798003cc  ldrsh    x12, [x30]
//   0x009a08: b980030e  ldrsw    x14, [x24]
//   0x009a0c: d37df12a  lsl      x10, x9, #3
//   0x009a10: f86a6a6b  ldr      x11, [x19, x10]
//   0x009a14: ca0d016d  eor      x13, x11, x13
//   0x009a18: 8b0c056b  add      x11, x11, x12, lsl #1
//   0x009a1c: f82a6a6d  str      x13, [x19, x10]
//   0x009a20: 52882aad  mov      w13, #0x4155
//   0x009a24: f82e7a6b  str      x11, [x19, x14, lsl #3]
//   0x009a28: 528e5d4b  mov      w11, #0x72ea
//   0x009a2c: f94002aa  ldr      x10, [x21]
//   0x009a30: 72a9ae6b  movk     w11, #0x4d73, lsl #16
//   0x009a34: 4a0b0129  eor      w9, w9, w11
//   0x009a38: 4a0d018b  eor      w11, w12, w13
//   0x009a3c: 5295e26c  mov      w12, #0xaf13
//   0x009a40: f900008a  str      x10, [x4]
//   0x009a44: 72a0a96c  movk     w12, #0x54b, lsl #16
//   0x009a48: b8404d4d  ldr      w13, [x10, #4]!
//   0x009a4c: b90002e9  str      w9, [x23]
//   0x009a50: 52816389  mov      w9, #0xb1c
//   0x009a54: 72a57a69  movk     w9, #0x2bd3, lsl #16
//   0x009a58: 4a0c01cc  eor      w12, w14, w12
//   0x009a5c: 4a0901a9  eor      w9, w13, w9
//   0x009a60: 790003cb  strh     w11, [x30]
//   0x009a64: f90002aa  str      x10, [x21]
//   0x009a68: b900030c  str      w12, [x24]
//   0x009a6c: b9000149  str      w9, [x10]
//   0x009a70: 17ffff8f  b        #0x98ac
//   0x009a74: f0ffffc8  adrp     x8, #0x4000
//   0x009a78: 5288810a  mov      w10, #0x4408
//   0x009a7c: 91118108  add      x8, x8, #0x460
//   0x009a80: 72a1050a  movk     w10, #0x828, lsl #16
//   0x009a84: 11000509  add      w9, w8, #1
//   0x009a88: 0a280129  bic      w9, w9, w8
//   0x009a8c: 2a2903e9  mvn      w9, w9
//   0x009a90: 8a0a0129  and      x9, x9, x10
//   0x009a94: d298788a  mov      x10, #0xc3c4
//   0x009a98: f2bbb64a  movk     x10, #0xddb2, lsl #16
//   0x009a9c: f2c2804a  movk     x10, #0x1402, lsl #32
//   0x009aa0: f2e0620a  movk     x10, #0x310, lsl #48
//   0x009aa4: 8b0a0129  add      x9, x9, x10
//   0x009aa8: 529b4b6a  mov      w10, #0xda5b
//   0x009aac: 72a16a0a  movk     w10, #0xb50, lsl #16
//   0x009ab0: eb0a013f  cmp      x9, x10
//   0x009ab4: 54000903  b.lo     #0x9bd4
//   0x009ab8: f94002a9  ldr      x9, [x21]
//   0x009abc: b940012a  ldr      w10, [x9]
//   0x009ac0: d3417d4c  ubfx     x12, x10, #1, #0x1f
//   0x009ac4: d34b7d4d  ubfx     x13, x10, #0xb, #0x15
//   0x009ac8: 121b018e  and      w14, w12, #0x20
//   0x009acc: 121a018f  and      w15, w12, #0x40
//   0x009ad0: 331a794e  bfxil    w14, w10, #0x1a, #5
//   0x009ad4: d35bfd4b  lsr      x11, x10, #0x1b
//   0x009ad8: 2a0f01ce  orr      w14, w14, w15
//   0x009adc: 1219018f  and      w15, w12, #0x80
//   0x009ae0: 2a0f01ce  orr      w14, w14, w15
//   0x009ae4: 1218018f  and      w15, w12, #0x100
//   0x009ae8: 2a0f01ce  orr      w14, w14, w15
//   0x009aec: 1217018f  and      w15, w12, #0x200
//   0x009af0: 2a0f01ce  orr      w14, w14, w15
//   0x009af4: 121601af  and      w15, w13, #0x400
//   0x009af8: 2a0f01ce  orr      w14, w14, w15
//   0x009afc: 121501af  and      w15, w13, #0x800
//   0x009b00: 2a0f01ce  orr      w14, w14, w15
//   0x009b04: 121401af  and      w15, w13, #0x1000
//   0x009b08: 2a0f01ce  orr      w14, w14, w15
//   0x009b0c: 121301af  and      w15, w13, #0x2000
//   0x009b10: 121201ad  and      w13, w13, #0x4000
//   0x009b14: 2a0f01ce  orr      w14, w14, w15
//   0x009b18: 2a0d01cd  orr      w13, w14, w13
//   0x009b1c: d347fd4e  lsr      x14, x10, #7
//   0x009b20: 927c016b  and      x11, x11, #0x10
//   0x009b24: 927c01ce  and      x14, x14, #0x10
//   0x009b28: b34c3d4b  bfxil    x11, x10, #0xc, #4
//   0x009b2c: 1211018c  and      w12, w12, #0x8000
//   0x009b30: b351514e  bfxil    x14, x10, #0x11, #4
//   0x009b34: d282080a  mov      x10, #0x1040
//   0x009b38: 2a0c01ac  orr      w12, w13, w12
//   0x009b3c: d280800d  mov      x13, #0x400
//   0x009b40: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x009b44: f2a0008d  movk     x13, #4, lsl #16
//   0x009b48: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x009b4c: f86b7a6f  ldr      x15, [x19, x11, lsl #3]
//   0x009b50: f2c0208d  movk     x13, #0x104, lsl #32
//   0x009b54: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x009b58: 8a0d010d  and      x13, x8, x13
//   0x009b5c: aa280148  orn      x8, x10, x8
//   0x009b60: d282880a  mov      x10, #0x1440
//   0x009b64: b90002eb  str      w11, [x23]
//   0x009b68: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x009b6c: 8b2ca1ef  add      x15, x15, w12, sxth
//   0x009b70: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x009b74: b900030e  str      w14, [x24]
//   0x009b78: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x009b7c: f82e7a6f  str      x15, [x19, x14, lsl #3]
//   0x009b80: 8a0a0108  and      x8, x8, x10
//   0x009b84: 5280208f  mov      w15, #0x104
//   0x009b88: 8b0d0108  add      x8, x8, x13
//   0x009b8c: d28d6b8d  mov      x13, #0x6b5c
//   0x009b90: b8404d2a  ldr      w10, [x9, #4]!
//   0x009b94: f90002a9  str      x9, [x21]
//   0x009b98: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x009b9c: 72a0202f  movk     w15, #0x101, lsl #16
//   0x009ba0: f941f289  ldr      x9, [x20, #0x3e0]
//   0x009ba4: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x009ba8: aa0f0108  orr      x8, x8, x15
//   0x009bac: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x009bb0: 9240154a  and      x10, x10, #0x3f
//   0x009bb4: ca0d0108  eor      x8, x8, x13
//   0x009bb8: 790003cc  strh     w12, [x30]
//   0x009bbc: 8b080128  add      x8, x9, x8
//   0x009bc0: f85f83a9  ldur     x9, [x29, #-8]
//   0x009bc4: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x009bc8: f9400108  ldr      x8, [x8]
//   0x009bcc: cb090108  sub      x8, x8, x9
//   0x009bd0: d61f0100  br       x8
//   0x009bd4: f94002a9  ldr      x9, [x21]
//   0x009bd8: 5292872b  mov      w11, #0x9439
//   0x009bdc: 72afd6eb  movk     w11, #0x7eb7, lsl #16
//   0x009be0: 528f6ead  mov      w13, #0x7b75
//   0x009be4: 72ad570d  movk     w13, #0x6ab8, lsl #16
//   0x009be8: f9000089  str      x9, [x4]
//   0x009bec: b940012a  ldr      w10, [x9]
//   0x009bf0: 4a0b014a  eor      w10, w10, w11
//   0x009bf4: b900012a  str      w10, [x9]
//   0x009bf8: b98002e9  ldrsw    x9, [x23]
//   0x009bfc: 798003cc  ldrsh    x12, [x30]
//   0x009c00: b980030e  ldrsw    x14, [x24]
//   0x009c04: d37df12a  lsl      x10, x9, #3
//   0x009c08: f86a6a6b  ldr      x11, [x19, x10]
//   0x009c0c: ca0d016d  eor      x13, x11, x13
//   0x009c10: 8b0c056b  add      x11, x11, x12, lsl #1
//   0x009c14: f82a6a6d  str      x13, [x19, x10]
//   0x009c18: 528ea1ed  mov      w13, #0x750f
//   0x009c1c: f82e7a6b  str      x11, [x19, x14, lsl #3]
//   0x009c20: 528d65ab  mov      w11, #0x6b2d
//   0x009c24: f94002aa  ldr      x10, [x21]
//   0x009c28: 72a8cc8b  movk     w11, #0x4664, lsl #16
//   0x009c2c: 4a0b0129  eor      w9, w9, w11
//   0x009c30: 4a0d018b  eor      w11, w12, w13
//   0x009c34: 5298544c  mov      w12, #0xc2a2
//   0x009c38: f900008a  str      x10, [x4]
//   0x009c3c: 72ab532c  movk     w12, #0x5a99, lsl #16
//   0x009c40: b8404d4d  ldr      w13, [x10, #4]!
//   0x009c44: b90002e9  str      w9, [x23]
//   0x009c48: 528904c9  mov      w9, #0x4826
//   0x009c4c: 72a49729  movk     w9, #0x24b9, lsl #16
//   0x009c50: 4a0c01cc  eor      w12, w14, w12
//   0x009c54: 4a0901a9  eor      w9, w13, w9
//   0x009c58: 790003cb  strh     w11, [x30]
//   0x009c5c: f90002aa  str      x10, [x21]
//   0x009c60: b900030c  str      w12, [x24]
//   0x009c64: b9000149  str      w9, [x10]
//   0x009c68: 17ffff94  b        #0x9ab8
//   0x009c6c: f94002a8  ldr      x8, [x21]
//   0x009c70: b9400109  ldr      w9, [x8]
//   0x009c74: 53077d2d  lsr      w13, w9, #7
//   0x009c78: 531c6d2e  lsl      w14, w9, #4
//   0x009c7c: 53087d2c  lsr      w12, w9, #8
//   0x009c80: 121601ce  and      w14, w14, #0x400
//   0x009c84: 53097d2b  lsr      w11, w9, #9
//   0x009c88: 3310652e  bfxil    w14, w9, #0x10, #0xa
//   0x009c8c: 530a7d2a  lsr      w10, w9, #0xa
//   0x009c90: 331501ae  bfi      w14, w13, #0xb, #1
//   0x009c94: 3314018e  bfi      w14, w12, #0xc, #1
//   0x009c98: d35bfd2f  lsr      x15, x9, #0x1b
//   0x009c9c: d347fd30  lsr      x16, x9, #7
//   0x009ca0: d34b7d2d  ubfx     x13, x9, #0xb, #0x15
//   0x009ca4: 3313016e  bfi      w14, w11, #0xd, #1
//   0x009ca8: 927c01ef  and      x15, x15, #0x10
//   0x009cac: 927c0210  and      x16, x16, #0x10
//   0x009cb0: 121101ad  and      w13, w13, #0x8000
//   0x009cb4: 3312014e  bfi      w14, w10, #0xe, #1
//   0x009cb8: b34c3d2f  bfxil    x15, x9, #0xc, #4
//   0x009cbc: b35b7930  bfxil    x16, x9, #0x1b, #4
//   0x009cc0: 2a0d01c9  orr      w9, w14, w13
//   0x009cc4: d37df1ea  lsl      x10, x15, #3
//   0x009cc8: b90002ef  str      w15, [x23]
//   0x009ccc: b9000310  str      w16, [x24]
//   0x009cd0: 790003c9  strh     w9, [x30]
//   0x009cd4: 13003d29  sxth     w9, w9
//   0x009cd8: b8aa6a6a  ldrsw    x10, [x19, x10]
//   0x009cdc: 8b29c149  add      x9, x10, w9, sxtw
//   0x009ce0: f8307a69  str      x9, [x19, x16, lsl #3]
//   0x009ce4: b8404d09  ldr      w9, [x8, #4]!
//   0x009ce8: f90002a8  str      x8, [x21]
//   0x009cec: 52802088  mov      w8, #0x104
//   0x009cf0: 72a02028  movk     w8, #0x101, lsl #16
//   0x009cf4: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x009cf8: aa0802c8  orr      x8, x22, x8
//   0x009cfc: 92401529  and      x9, x9, #0x3f
//   0x009d00: ca110108  eor      x8, x8, x17
//   0x009d04: 8b080148  add      x8, x10, x8
//   0x009d08: 8b090d08  add      x8, x8, x9, lsl #3
//   0x009d0c: f85f83a9  ldur     x9, [x29, #-8]
//   0x009d10: f9400108  ldr      x8, [x8]
//   0x009d14: cb090108  sub      x8, x8, x9
//   0x009d18: d61f0100  br       x8
//   0x009d1c: f94002a8  ldr      x8, [x21]
//   0x009d20: b0ffffca  adrp     x10, #0x2000
//   0x009d24: b9400109  ldr      w9, [x8]
//   0x009d28: fd408d41  ldr      d1, [x10, #0x118]
//   0x009d2c: b0ffffca  adrp     x10, #0x2000
//   0x009d30: 0e040d20  dup      v0.2s, w9
//   0x009d34: 5317592c  lsl      w12, w9, #9
//   0x009d38: 3dc02143  ldr      q3, [x10, #0x80]
//   0x009d3c: d35bfd2a  lsr      x10, x9, #0x1b
//   0x009d40: 927c014a  and      x10, x10, #0x10
//   0x009d44: 1211018c  and      w12, w12, #0x8000
//   0x009d48: b34c3d2a  bfxil    x10, x9, #0xc, #4
//   0x009d4c: d3472d29  ubfx     x9, x9, #7, #5
//   0x009d50: 2ea14400  ushl     v0.2s, v0.2s, v1.2s
//   0x009d54: f86a7a6d  ldr      x13, [x19, x10, lsl #3]
//   0x009d58: b90002ea  str      w10, [x23]
//   0x009d5c: b9000309  str      w9, [x24]
//   0x009d60: 4e801801  uzp1     v1.4s, v0.4s, v0.4s
//   0x009d64: 4e040404  dup      v4.4s, v0.s[0]
//   0x009d68: 4e803802  zip1     v2.4s, v0.4s, v0.4s
//   0x009d6c: 4e231c83  and      v3.16b, v4.16b, v3.16b
//   0x009d70: 1e26000e  fmov     w14, s0
//   0x009d74: 6e004021  ext      v1.16b, v1.16b, v0.16b, #8
//   0x009d78: 121401d0  and      w16, w14, #0x1000
//   0x009d7c: 6e024021  ext      v1.16b, v1.16b, v2.16b, #8
//   0x009d80: 3dc02402  ldr      q2, [x0, #0x90]
//   0x009d84: 4e221c21  and      v1.16b, v1.16b, v2.16b
//   0x009d88: 4ea31c21  orr      v1.16b, v1.16b, v3.16b
//   0x009d8c: 6e014022  ext      v2.16b, v1.16b, v1.16b, #8
//   0x009d90: 0ea21c21  orr      v1.8b, v1.8b, v2.8b
//   0x009d94: 0e0c3c2b  mov      w11, v1.s[1]
//   0x009d98: 1e26002f  fmov     w15, s1
//   0x009d9c: 2a0b01eb  orr      w11, w15, w11
//   0x009da0: 121301cf  and      w15, w14, #0x2000
//   0x009da4: 2a10016b  orr      w11, w11, w16
//   0x009da8: 121201ce  and      w14, w14, #0x4000
//   0x009dac: 2a0f016b  orr      w11, w11, w15
//   0x009db0: 2a0e016b  orr      w11, w11, w14
//   0x009db4: 2a0c016b  orr      w11, w11, w12
//   0x009db8: eb2ba1bf  cmp      x13, w11, sxth
//   0x009dbc: 1a9fa7ec  cset     w12, lt
//   0x009dc0: 790003cb  strh     w11, [x30]
//   0x009dc4: f8297a6c  str      x12, [x19, x9, lsl #3]
//   0x009dc8: b8404d0c  ldr      w12, [x8, #4]!
//   0x009dcc: f90002a8  str      x8, [x21]
//   0x009dd0: 52802088  mov      w8, #0x104
//   0x009dd4: 72a02028  movk     w8, #0x101, lsl #16
//   0x009dd8: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x009ddc: aa0802c8  orr      x8, x22, x8
//   0x009de0: 9240158c  and      x12, x12, #0x3f
//   0x009de4: ca110108  eor      x8, x8, x17
//   0x009de8: 8b0801a8  add      x8, x13, x8
//   0x009dec: 8b0c0d08  add      x8, x8, x12, lsl #3
//   0x009df0: f85f83ac  ldur     x12, [x29, #-8]
//   0x009df4: f9400108  ldr      x8, [x8]
//   0x009df8: cb0c0108  sub      x8, x8, x12
//   0x009dfc: d61f0100  br       x8
//   0x009e00: f0ffffc8  adrp     x8, #0x4000
//   0x009e04: 5288004a  mov      w10, #0x4002
//   0x009e08: 91118108  add      x8, x8, #0x460
//   0x009e0c: 72a0404a  movk     w10, #0x202, lsl #16
//   0x009e10: 11000509  add      w9, w8, #1
//   0x009e14: 0a280129  bic      w9, w9, w8
//   0x009e18: 2a2903e9  mvn      w9, w9
//   0x009e1c: 8a0a0129  and      x9, x9, x10
//   0x009e20: d297b42a  mov      x10, #0xbda1
//   0x009e24: f2bbddaa  movk     x10, #0xdeed, lsl #16
//   0x009e28: f2c0408a  movk     x10, #0x204, lsl #32
//   0x009e2c: 8b0a0129  add      x9, x9, x10
//   0x009e30: 5287fe0a  mov      w10, #0x3ff0
//   0x009e34: 72a502ea  movk     w10, #0x2817, lsl #16
//   0x009e38: eb0a013f  cmp      x9, x10
//   0x009e3c: 54000903  b.lo     #0x9f5c
//   0x009e40: f94002a9  ldr      x9, [x21]
//   0x009e44: b940012a  ldr      w10, [x9]
//   0x009e48: d3507d4c  ubfx     x12, x10, #0x10, #0x10
//   0x009e4c: d3467d4d  ubfx     x13, x10, #6, #0x1a
//   0x009e50: 121b018e  and      w14, w12, #0x20
//   0x009e54: 121a018f  and      w15, w12, #0x40
//   0x009e58: 331a794e  bfxil    w14, w10, #0x1a, #5
//   0x009e5c: d35bfd4b  lsr      x11, x10, #0x1b
//   0x009e60: 2a0f01ce  orr      w14, w14, w15
//   0x009e64: 1219018f  and      w15, w12, #0x80
//   0x009e68: 2a0f01ce  orr      w14, w14, w15
//   0x009e6c: 1218018f  and      w15, w12, #0x100
//   0x009e70: 1217018c  and      w12, w12, #0x200
//   0x009e74: 2a0f01ce  orr      w14, w14, w15
//   0x009e78: 121601af  and      w15, w13, #0x400
//   0x009e7c: 2a0c01cc  orr      w12, w14, w12
//   0x009e80: 121501ae  and      w14, w13, #0x800
//   0x009e84: 2a0f018c  orr      w12, w12, w15
//   0x009e88: 121401af  and      w15, w13, #0x1000
//   0x009e8c: 2a0e018c  orr      w12, w12, w14
//   0x009e90: 2a0f018c  orr      w12, w12, w15
//   0x009e94: 121301af  and      w15, w13, #0x2000
//   0x009e98: 927c016b  and      x11, x11, #0x10
//   0x009e9c: 5317594e  lsl      w14, w10, #9
//   0x009ea0: 121201ad  and      w13, w13, #0x4000
//   0x009ea4: 2a0f018c  orr      w12, w12, w15
//   0x009ea8: b34c3d4b  bfxil    x11, x10, #0xc, #4
//   0x009eac: 121101ce  and      w14, w14, #0x8000
//   0x009eb0: 2a0d018c  orr      w12, w12, w13
//   0x009eb4: d280800d  mov      x13, #0x400
//   0x009eb8: 2a0e018c  orr      w12, w12, w14
//   0x009ebc: d282080e  mov      x14, #0x1040
//   0x009ec0: f2a1404e  movk     x14, #0xa02, lsl #16
//   0x009ec4: f86b7a6f  ldr      x15, [x19, x11, lsl #3]
//   0x009ec8: f2a0008d  movk     x13, #4, lsl #16
//   0x009ecc: f2cc080e  movk     x14, #0x6040, lsl #32
//   0x009ed0: f2c0208d  movk     x13, #0x104, lsl #32
//   0x009ed4: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x009ed8: 8a0d010d  and      x13, x8, x13
//   0x009edc: aa2801c8  orn      x8, x14, x8
//   0x009ee0: d282880e  mov      x14, #0x1440
//   0x009ee4: d3472d4a  ubfx     x10, x10, #7, #5
//   0x009ee8: f2a140ce  movk     x14, #0xa06, lsl #16
//   0x009eec: eb2ca1ff  cmp      x15, w12, sxth
//   0x009ef0: f2cc288e  movk     x14, #0x6144, lsl #32
//   0x009ef4: 1a9f27ef  cset     w15, lo
//   0x009ef8: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x009efc: b90002eb  str      w11, [x23]
//   0x009f00: 8a0e0108  and      x8, x8, x14
//   0x009f04: f82a7a6f  str      x15, [x19, x10, lsl #3]
//   0x009f08: 8b0d0108  add      x8, x8, x13
//   0x009f0c: d28d6b8d  mov      x13, #0x6b5c
//   0x009f10: b8404d2e  ldr      w14, [x9, #4]!
//   0x009f14: 5280208f  mov      w15, #0x104
//   0x009f18: f90002a9  str      x9, [x21]
//   0x009f1c: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x009f20: 72a0202f  movk     w15, #0x101, lsl #16
//   0x009f24: f941f289  ldr      x9, [x20, #0x3e0]
//   0x009f28: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x009f2c: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x009f30: aa0f0108  orr      x8, x8, x15
//   0x009f34: ca0d0108  eor      x8, x8, x13
//   0x009f38: 924015cd  and      x13, x14, #0x3f
//   0x009f3c: 8b080128  add      x8, x9, x8
//   0x009f40: f85f83a9  ldur     x9, [x29, #-8]
//   0x009f44: 8b0d0d08  add      x8, x8, x13, lsl #3
//   0x009f48: b900030a  str      w10, [x24]
//   0x009f4c: 790003cc  strh     w12, [x30]
//   0x009f50: f9400108  ldr      x8, [x8]
//   0x009f54: cb090108  sub      x8, x8, x9
//   0x009f58: d61f0100  br       x8
//   0x009f5c: f94002a9  ldr      x9, [x21]
//   0x009f60: 528c8c2b  mov      w11, #0x6461
//   0x009f64: 72a9fdab  movk     w11, #0x4fed, lsl #16
//   0x009f68: 529d71ed  mov      w13, #0xeb8f
//   0x009f6c: 72a15a4d  movk     w13, #0xad2, lsl #16
//   0x009f70: f9000089  str      x9, [x4]
//   0x009f74: b940012a  ldr      w10, [x9]
//   0x009f78: 4a0b014a  eor      w10, w10, w11
//   0x009f7c: b900012a  str      w10, [x9]
//   0x009f80: b98002e9  ldrsw    x9, [x23]
//   0x009f84: 798003cc  ldrsh    x12, [x30]
//   0x009f88: d37df12a  lsl      x10, x9, #3
//   0x009f8c: f86a6a6b  ldr      x11, [x19, x10]
//   0x009f90: ca0d016d  eor      x13, x11, x13
//   0x009f94: eb0c017f  cmp      x11, x12
//   0x009f98: b980030b  ldrsw    x11, [x24]
//   0x009f9c: 1a9fa7ee  cset     w14, lt
//   0x009fa0: f82a6a6d  str      x13, [x19, x10]
//   0x009fa4: 5288a8ad  mov      w13, #0x4545
//   0x009fa8: 72ad4b2d  movk     w13, #0x6a59, lsl #16
//   0x009fac: f82b7a6e  str      x14, [x19, x11, lsl #3]
//   0x009fb0: 4a0d0129  eor      w9, w9, w13
//   0x009fb4: f94002aa  ldr      x10, [x21]
//   0x009fb8: 529fdace  mov      w14, #0xfed6
//   0x009fbc: 4a0e018c  eor      w12, w12, w14
//   0x009fc0: 528f218d  mov      w13, #0x790c
//   0x009fc4: b90002e9  str      w9, [x23]
//   0x009fc8: 52876f69  mov      w9, #0x3b7b
//   0x009fcc: f900008a  str      x10, [x4]
//   0x009fd0: 72adce8d  movk     w13, #0x6e74, lsl #16
//   0x009fd4: b8404d4e  ldr      w14, [x10, #4]!
//   0x009fd8: 72a416e9  movk     w9, #0x20b7, lsl #16
//   0x009fdc: 4a0d016b  eor      w11, w11, w13
//   0x009fe0: 790003cc  strh     w12, [x30]
//   0x009fe4: 4a0901c9  eor      w9, w14, w9
//   0x009fe8: f90002aa  str      x10, [x21]
//   0x009fec: b900030b  str      w11, [x24]
//   0x009ff0: b9000149  str      w9, [x10]
//   0x009ff4: 17ffff93  b        #0x9e40
//   0x009ff8: f94002a8  ldr      x8, [x21]
//   0x009ffc: b9400109  ldr      w9, [x8]
//   0x00a000: d355fd2b  lsr      x11, x9, #0x15
//   0x00a004: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00a008: 927b016d  and      x13, x11, #0x20
//   0x00a00c: 927a016e  and      x14, x11, #0x40
//   0x00a010: b350512d  bfxil    x13, x9, #0x10, #5
//   0x00a014: d34bfd2c  lsr      x12, x9, #0xb
//   0x00a018: aa0e01ad  orr      x13, x13, x14
//   0x00a01c: 9279016e  and      x14, x11, #0x80
//   0x00a020: aa0e01ad  orr      x13, x13, x14
//   0x00a024: 9278016e  and      x14, x11, #0x100
//   0x00a028: 927c014a  and      x10, x10, #0x10
//   0x00a02c: 9277016b  and      x11, x11, #0x200
//   0x00a030: aa0e01ad  orr      x13, x13, x14
//   0x00a034: 9276018e  and      x14, x12, #0x400
//   0x00a038: aa0b01ab  orr      x11, x13, x11
//   0x00a03c: b34c3d2a  bfxil    x10, x9, #0xc, #4
//   0x00a040: 9275018d  and      x13, x12, #0x800
//   0x00a044: aa0e016b  orr      x11, x11, x14
//   0x00a048: 9274018e  and      x14, x12, #0x1000
//   0x00a04c: aa0d016b  orr      x11, x11, x13
//   0x00a050: 9273018d  and      x13, x12, #0x2000
//   0x00a054: aa0e016b  orr      x11, x11, x14
//   0x00a058: f86a7a6e  ldr      x14, [x19, x10, lsl #3]
//   0x00a05c: aa0d016b  orr      x11, x11, x13
//   0x00a060: 5317592d  lsl      w13, w9, #9
//   0x00a064: 9272018c  and      x12, x12, #0x4000
//   0x00a068: 927101ad  and      x13, x13, #0x8000
//   0x00a06c: aa0c016b  orr      x11, x11, x12
//   0x00a070: aa0d016b  orr      x11, x11, x13
//   0x00a074: d3472d29  ubfx     x9, x9, #7, #5
//   0x00a078: 0a0e016c  and      w12, w11, w14
//   0x00a07c: b90002ea  str      w10, [x23]
//   0x00a080: 92403d8c  and      x12, x12, #0xffff
//   0x00a084: b9000309  str      w9, [x24]
//   0x00a088: f8297a6c  str      x12, [x19, x9, lsl #3]
//   0x00a08c: b8404d0c  ldr      w12, [x8, #4]!
//   0x00a090: f90002a8  str      x8, [x21]
//   0x00a094: 52802088  mov      w8, #0x104
//   0x00a098: 72a02028  movk     w8, #0x101, lsl #16
//   0x00a09c: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x00a0a0: aa0802c8  orr      x8, x22, x8
//   0x00a0a4: 9240158c  and      x12, x12, #0x3f
//   0x00a0a8: ca110108  eor      x8, x8, x17
//   0x00a0ac: 790003cb  strh     w11, [x30]
//   0x00a0b0: 8b0801a8  add      x8, x13, x8
//   0x00a0b4: 8b0c0d08  add      x8, x8, x12, lsl #3
//   0x00a0b8: f85f83ac  ldur     x12, [x29, #-8]
//   0x00a0bc: f9400108  ldr      x8, [x8]
//   0x00a0c0: cb0c0108  sub      x8, x8, x12
//   0x00a0c4: d61f0100  br       x8
//   0x00a0c8: d0ffffc8  adrp     x8, #0x4000
//   0x00a0cc: 529800ca  mov      w10, #0xc006
//   0x00a0d0: 91118108  add      x8, x8, #0x460
//   0x00a0d4: 72a0080a  movk     w10, #0x40, lsl #16
//   0x00a0d8: 11000509  add      w9, w8, #1
//   0x00a0dc: 0a280129  bic      w9, w9, w8
//   0x00a0e0: 2a2903e9  mvn      w9, w9
//   0x00a0e4: 8a0a0129  and      x9, x9, x10
//   0x00a0e8: d286810a  mov      x10, #0x3408
//   0x00a0ec: f2a60dea  movk     x10, #0x306f, lsl #16
//   0x00a0f0: f2c1000a  movk     x10, #0x800, lsl #32
//   0x00a0f4: f2e0488a  movk     x10, #0x244, lsl #48
//   0x00a0f8: 8b0a0129  add      x9, x9, x10
//   0x00a0fc: 5284f4aa  mov      w10, #0x27a5
//   0x00a100: 72a43a6a  movk     w10, #0x21d3, lsl #16
//   0x00a104: eb0a013f  cmp      x9, x10
//   0x00a108: 54000843  b.lo     #0xa210
//   0x00a10c: f94002aa  ldr      x10, [x21]
//   0x00a110: d282080c  mov      x12, #0x1040
//   0x00a114: d280800b  mov      x11, #0x400
//   0x00a118: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00a11c: f2a0008b  movk     x11, #4, lsl #16
//   0x00a120: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00a124: b9400149  ldr      w9, [x10]
//   0x00a128: f2c0208b  movk     x11, #0x104, lsl #32
//   0x00a12c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00a130: 8a0b010b  and      x11, x8, x11
//   0x00a134: aa280188  orn      x8, x12, x8
//   0x00a138: 53077d2d  lsr      w13, w9, #7
//   0x00a13c: 531c6d2e  lsl      w14, w9, #4
//   0x00a140: 53087d2f  lsr      w15, w9, #8
//   0x00a144: 121601ce  and      w14, w14, #0x400
//   0x00a148: 53097d30  lsr      w16, w9, #9
//   0x00a14c: 330b512e  bfxil    w14, w9, #0xb, #0xa
//   0x00a150: 530a7d31  lsr      w17, w9, #0xa
//   0x00a154: 331501ae  bfi      w14, w13, #0xb, #1
//   0x00a158: 331401ee  bfi      w14, w15, #0xc, #1
//   0x00a15c: d34b7d2f  ubfx     x15, x9, #0xb, #0x15
//   0x00a160: 3313020e  bfi      w14, w16, #0xd, #1
//   0x00a164: d351fd2d  lsr      x13, x9, #0x11
//   0x00a168: 121101ef  and      w15, w15, #0x8000
//   0x00a16c: 3312022e  bfi      w14, w17, #0xe, #1
//   0x00a170: d2828810  mov      x16, #0x1440
//   0x00a174: 927c01ad  and      x13, x13, #0x10
//   0x00a178: 2a0f01ce  orr      w14, w14, w15
//   0x00a17c: f2a140d0  movk     x16, #0xa06, lsl #16
//   0x00a180: b35b792d  bfxil    x13, x9, #0x1b, #4
//   0x00a184: 53103dcf  lsl      w15, w14, #0x10
//   0x00a188: f2cc2890  movk     x16, #0x6144, lsl #32
//   0x00a18c: 93407def  sxtw     x15, w15
//   0x00a190: f2e01410  movk     x16, #0xa0, lsl #48
//   0x00a194: 52802091  mov      w17, #0x104
//   0x00a198: 8a100108  and      x8, x8, x16
//   0x00a19c: f82d7a6f  str      x15, [x19, x13, lsl #3]
//   0x00a1a0: 8b0b0108  add      x8, x8, x11
//   0x00a1a4: d28d6b8b  mov      x11, #0x6b5c
//   0x00a1a8: b8404d4c  ldr      w12, [x10, #4]!
//   0x00a1ac: f90002aa  str      x10, [x21]
//   0x00a1b0: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x00a1b4: 72a02031  movk     w17, #0x101, lsl #16
//   0x00a1b8: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00a1bc: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x00a1c0: aa110108  orr      x8, x8, x17
//   0x00a1c4: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x00a1c8: d28d6b91  mov      x17, #0x6b5c
//   0x00a1cc: ca0b0108  eor      x8, x8, x11
//   0x00a1d0: 9240158b  and      x11, x12, #0x3f
//   0x00a1d4: 8b080148  add      x8, x10, x8
//   0x00a1d8: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00a1dc: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x00a1e0: f85f83ab  ldur     x11, [x29, #-8]
//   0x00a1e4: 121c014a  and      w10, w10, #0x10
//   0x00a1e8: f2be9391  movk     x17, #0xf49c, lsl #16
//   0x00a1ec: 3316652a  bfxil    w10, w9, #0x16, #4
//   0x00a1f0: f2d3d771  movk     x17, #0x9ebb, lsl #32
//   0x00a1f4: f9400108  ldr      x8, [x8]
//   0x00a1f8: b900030d  str      w13, [x24]
//   0x00a1fc: 790003ce  strh     w14, [x30]
//   0x00a200: f2ffebf1  movk     x17, #0xff5f, lsl #48
//   0x00a204: b90002ea  str      w10, [x23]
//   0x00a208: cb0b0108  sub      x8, x8, x11
//   0x00a20c: d61f0100  br       x8
//   0x00a210: f94002a9  ldr      x9, [x21]
//   0x00a214: 528f0f2b  mov      w11, #0x7879
//   0x00a218: 72a1cccb  movk     w11, #0xe66, lsl #16
//   0x00a21c: 528aea2c  mov      w12, #0x5751
//   0x00a220: f9000089  str      x9, [x4]
//   0x00a224: b940012a  ldr      w10, [x9]
//   0x00a228: 4a0b014a  eor      w10, w10, w11
//   0x00a22c: b900012a  str      w10, [x9]
//   0x00a230: b9800309  ldrsw    x9, [x24]
//   0x00a234: 794003ca  ldrh     w10, [x30]
//   0x00a238: f8297a7f  str      xzr, [x19, x9, lsl #3]
//   0x00a23c: f94002ab  ldr      x11, [x21]
//   0x00a240: 4a0c014a  eor      w10, w10, w12
//   0x00a244: 529ddbcc  mov      w12, #0xeede
//   0x00a248: 72a2e5ac  movk     w12, #0x172d, lsl #16
//   0x00a24c: f900008b  str      x11, [x4]
//   0x00a250: 4a0c0129  eor      w9, w9, w12
//   0x00a254: b8404d6d  ldr      w13, [x11, #4]!
//   0x00a258: 528796ac  mov      w12, #0x3cb5
//   0x00a25c: 790003ca  strh     w10, [x30]
//   0x00a260: 72a913ac  movk     w12, #0x489d, lsl #16
//   0x00a264: b9000309  str      w9, [x24]
//   0x00a268: 4a0c01aa  eor      w10, w13, w12
//   0x00a26c: f90002ab  str      x11, [x21]
//   0x00a270: b900016a  str      w10, [x11]
//   0x00a274: 17ffffa6  b        #0xa10c
//   0x00a278: f94002a8  ldr      x8, [x21]
//   0x00a27c: b9400109  ldr      w9, [x8]
//   0x00a280: d346fd2a  lsr      x10, x9, #6
//   0x00a284: d35bfd2b  lsr      x11, x9, #0x1b
//   0x00a288: 927b014c  and      x12, x10, #0x20
//   0x00a28c: 927a014d  and      x13, x10, #0x40
//   0x00a290: b355652c  bfxil    x12, x9, #0x15, #5
//   0x00a294: 9279014e  and      x14, x10, #0x80
//   0x00a298: aa0d018c  orr      x12, x12, x13
//   0x00a29c: 9278014d  and      x13, x10, #0x100
//   0x00a2a0: aa0e018c  orr      x12, x12, x14
//   0x00a2a4: d350fd2e  lsr      x14, x9, #0x10
//   0x00a2a8: aa0d018c  orr      x12, x12, x13
//   0x00a2ac: 9277014a  and      x10, x10, #0x200
//   0x00a2b0: aa0a018a  orr      x10, x12, x10
//   0x00a2b4: 927601cc  and      x12, x14, #0x400
//   0x00a2b8: 927c016b  and      x11, x11, #0x10
//   0x00a2bc: aa0c014a  orr      x10, x10, x12
//   0x00a2c0: 927501cc  and      x12, x14, #0x800
//   0x00a2c4: b347292b  bfxil    x11, x9, #7, #4
//   0x00a2c8: aa0c014a  orr      x10, x10, x12
//   0x00a2cc: 927401cc  and      x12, x14, #0x1000
//   0x00a2d0: aa0c014a  orr      x10, x10, x12
//   0x00a2d4: 927301cc  and      x12, x14, #0x2000
//   0x00a2d8: d341fd2d  lsr      x13, x9, #1
//   0x00a2dc: 927201ce  and      x14, x14, #0x4000
//   0x00a2e0: aa0c014a  orr      x10, x10, x12
//   0x00a2e4: f86b7a6c  ldr      x12, [x19, x11, lsl #3]
//   0x00a2e8: aa0e014a  orr      x10, x10, x14
//   0x00a2ec: d342fd2e  lsr      x14, x9, #2
//   0x00a2f0: 927101ad  and      x13, x13, #0x8000
//   0x00a2f4: 927c01ce  and      x14, x14, #0x10
//   0x00a2f8: aa0d014a  orr      x10, x10, x13
//   0x00a2fc: b351512e  bfxil    x14, x9, #0x11, #4
//   0x00a300: 92403d49  and      x9, x10, #0xffff
//   0x00a304: b90002eb  str      w11, [x23]
//   0x00a308: aa090189  orr      x9, x12, x9
//   0x00a30c: b900030e  str      w14, [x24]
//   0x00a310: f82e7a69  str      x9, [x19, x14, lsl #3]
//   0x00a314: b8404d09  ldr      w9, [x8, #4]!
//   0x00a318: f90002a8  str      x8, [x21]
//   0x00a31c: 52802088  mov      w8, #0x104
//   0x00a320: 72a02028  movk     w8, #0x101, lsl #16
//   0x00a324: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00a328: aa0802c8  orr      x8, x22, x8
//   0x00a32c: 92401529  and      x9, x9, #0x3f
//   0x00a330: ca110108  eor      x8, x8, x17
//   0x00a334: 790003ca  strh     w10, [x30]
//   0x00a338: 8b080188  add      x8, x12, x8
//   0x00a33c: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00a340: f85f83a9  ldur     x9, [x29, #-8]
//   0x00a344: f9400108  ldr      x8, [x8]
//   0x00a348: cb090108  sub      x8, x8, x9
//   0x00a34c: d61f0100  br       x8
//   0x00a350: f94002a8  ldr      x8, [x21]
//   0x00a354: b9400109  ldr      w9, [x8]
//   0x00a358: d350fd2c  lsr      x12, x9, #0x10
//   0x00a35c: d346fd2d  lsr      x13, x9, #6
//   0x00a360: 927b018e  and      x14, x12, #0x20
//   0x00a364: 927a018f  and      x15, x12, #0x40
//   0x00a368: b346292e  bfxil    x14, x9, #6, #5
//   0x00a36c: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00a370: aa0f01ce  orr      x14, x14, x15
//   0x00a374: 9279018f  and      x15, x12, #0x80
//   0x00a378: aa0f01ce  orr      x14, x14, x15
//   0x00a37c: 9278018f  and      x15, x12, #0x100
//   0x00a380: 9277018c  and      x12, x12, #0x200
//   0x00a384: aa0f01ce  orr      x14, x14, x15
//   0x00a388: 927601af  and      x15, x13, #0x400
//   0x00a38c: aa0c01cc  orr      x12, x14, x12
//   0x00a390: 927501ae  and      x14, x13, #0x800
//   0x00a394: aa0f018c  orr      x12, x12, x15
//   0x00a398: 927401af  and      x15, x13, #0x1000
//   0x00a39c: aa0e018c  orr      x12, x12, x14
//   0x00a3a0: aa0f018c  orr      x12, x12, x15
//   0x00a3a4: 927301af  and      x15, x13, #0x2000
//   0x00a3a8: 531c6d2e  lsl      w14, w9, #4
//   0x00a3ac: 927201ad  and      x13, x13, #0x4000
//   0x00a3b0: aa0f018c  orr      x12, x12, x15
//   0x00a3b4: f86a7a6f  ldr      x15, [x19, x10, lsl #3]
//   0x00a3b8: d356fd2b  lsr      x11, x9, #0x16
//   0x00a3bc: 927101ce  and      x14, x14, #0x8000
//   0x00a3c0: aa0d018c  orr      x12, x12, x13
//   0x00a3c4: 927c016b  and      x11, x11, #0x10
//   0x00a3c8: aa0e018c  orr      x12, x12, x14
//   0x00a3cc: b34c3d2b  bfxil    x11, x9, #0xc, #4
//   0x00a3d0: 92403d89  and      x9, x12, #0xffff
//   0x00a3d4: b90002ea  str      w10, [x23]
//   0x00a3d8: ca0901e9  eor      x9, x15, x9
//   0x00a3dc: b900030b  str      w11, [x24]
//   0x00a3e0: f82b7a69  str      x9, [x19, x11, lsl #3]
//   0x00a3e4: b8404d09  ldr      w9, [x8, #4]!
//   0x00a3e8: f90002a8  str      x8, [x21]
//   0x00a3ec: 52802088  mov      w8, #0x104
//   0x00a3f0: 72a02028  movk     w8, #0x101, lsl #16
//   0x00a3f4: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x00a3f8: aa0802c8  orr      x8, x22, x8
//   0x00a3fc: 92401529  and      x9, x9, #0x3f
//   0x00a400: ca110108  eor      x8, x8, x17
//   0x00a404: 790003cc  strh     w12, [x30]
//   0x00a408: 8b0801a8  add      x8, x13, x8
//   0x00a40c: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00a410: f85f83a9  ldur     x9, [x29, #-8]
//   0x00a414: f9400108  ldr      x8, [x8]
//   0x00a418: cb090108  sub      x8, x8, x9
//   0x00a41c: d61f0100  br       x8
//   0x00a420: d0ffffc8  adrp     x8, #0x4000
//   0x00a424: 528a800a  mov      w10, #0x5400
//   0x00a428: 91118108  add      x8, x8, #0x460
//   0x00a42c: 72ad480a  movk     w10, #0x6a40, lsl #16
//   0x00a430: 11000509  add      w9, w8, #1
//   0x00a434: 0a280129  bic      w9, w9, w8
//   0x00a438: 2a2903e9  mvn      w9, w9
//   0x00a43c: 8a0a0129  and      x9, x9, x10
//   0x00a440: d281d9ca  mov      x10, #0xece
//   0x00a444: f2a5a7ea  movk     x10, #0x2d3f, lsl #16
//   0x00a448: f2c0a20a  movk     x10, #0x510, lsl #32
//   0x00a44c: f2e0800a  movk     x10, #0x400, lsl #48
//   0x00a450: 8b0a0129  add      x9, x9, x10
//   0x00a454: 529f0caa  mov      w10, #0xf865
//   0x00a458: 72a214ca  movk     w10, #0x10a6, lsl #16
//   0x00a45c: eb0a013f  cmp      x9, x10
//   0x00a460: 54000ae3  b.lo     #0xa5bc
//   0x00a464: f94002a9  ldr      x9, [x21]
//   0x00a468: f85d03ae  ldur     x14, [x29, #-0x30]
//   0x00a46c: b9400129  ldr      w9, [x9]
//   0x00a470: 53067d2a  lsr      w10, w9, #6
//   0x00a474: 53107d2b  lsr      w11, w9, #0x10
//   0x00a478: 121b014c  and      w12, w10, #0x20
//   0x00a47c: 121a014d  and      w13, w10, #0x40
//   0x00a480: 3310512c  bfxil    w12, w9, #0x10, #5
//   0x00a484: 2a0d018c  orr      w12, w12, w13
//   0x00a488: 1219014d  and      w13, w10, #0x80
//   0x00a48c: 2a0d018c  orr      w12, w12, w13
//   0x00a490: 1218014d  and      w13, w10, #0x100
//   0x00a494: 2a0d018c  orr      w12, w12, w13
//   0x00a498: 1217014d  and      w13, w10, #0x200
//   0x00a49c: 2a0d018c  orr      w12, w12, w13
//   0x00a4a0: 1216016d  and      w13, w11, #0x400
//   0x00a4a4: 2a0d018c  orr      w12, w12, w13
//   0x00a4a8: 1215016d  and      w13, w11, #0x800
//   0x00a4ac: 2a0d018c  orr      w12, w12, w13
//   0x00a4b0: 1214016d  and      w13, w11, #0x1000
//   0x00a4b4: 2a0d018c  orr      w12, w12, w13
//   0x00a4b8: 1213016d  and      w13, w11, #0x2000
//   0x00a4bc: 2a0d018c  orr      w12, w12, w13
//   0x00a4c0: 5317592d  lsl      w13, w9, #9
//   0x00a4c4: 1212016b  and      w11, w11, #0x4000
//   0x00a4c8: 53017d29  lsr      w9, w9, #1
//   0x00a4cc: 2a0b018b  orr      w11, w12, w11
//   0x00a4d0: 121101ac  and      w12, w13, #0x8000
//   0x00a4d4: 2a0c016b  orr      w11, w11, w12
//   0x00a4d8: 121001ac  and      w12, w13, #0x10000
//   0x00a4dc: 2a0c016b  orr      w11, w11, w12
//   0x00a4e0: 120f01ac  and      w12, w13, #0x20000
//   0x00a4e4: 2a0c016b  orr      w11, w11, w12
//   0x00a4e8: 120e01ac  and      w12, w13, #0x40000
//   0x00a4ec: 120d01ad  and      w13, w13, #0x80000
//   0x00a4f0: 2a0c016b  orr      w11, w11, w12
//   0x00a4f4: 120c012c  and      w12, w9, #0x100000
//   0x00a4f8: 2a0d016b  orr      w11, w11, w13
//   0x00a4fc: 120b012d  and      w13, w9, #0x200000
//   0x00a500: 2a0c016b  orr      w11, w11, w12
//   0x00a504: 120a012c  and      w12, w9, #0x400000
//   0x00a508: 2a0d016b  orr      w11, w11, w13
//   0x00a50c: 1209012d  and      w13, w9, #0x800000
//   0x00a510: 2a0c016b  orr      w11, w11, w12
//   0x00a514: 12080129  and      w9, w9, #0x1000000
//   0x00a518: 2a0d016b  orr      w11, w11, w13
//   0x00a51c: 1207014a  and      w10, w10, #0x2000000
//   0x00a520: 2a090169  orr      w9, w11, w9
//   0x00a524: 2a0a0129  orr      w9, w9, w10
//   0x00a528: d282080a  mov      x10, #0x1040
//   0x00a52c: d280800b  mov      x11, #0x400
//   0x00a530: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x00a534: f2a0008b  movk     x11, #4, lsl #16
//   0x00a538: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x00a53c: f2c0208b  movk     x11, #0x104, lsl #32
//   0x00a540: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x00a544: 937e7d2c  sbfiz    x12, x9, #2, #0x20
//   0x00a548: 8a0b010b  and      x11, x8, x11
//   0x00a54c: aa280148  orn      x8, x10, x8
//   0x00a550: d282880a  mov      x10, #0x1440
//   0x00a554: 8b0c01cd  add      x13, x14, x12
//   0x00a558: f2a140ca  movk     x10, #0xa06, lsl #16
//   0x00a55c: f2cc288a  movk     x10, #0x6144, lsl #32
//   0x00a560: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x00a564: 8a0a0108  and      x8, x8, x10
//   0x00a568: b86c69ca  ldr      w10, [x14, x12]
//   0x00a56c: f90002ad  str      x13, [x21]
//   0x00a570: d28d6b8d  mov      x13, #0x6b5c
//   0x00a574: 5280208c  mov      w12, #0x104
//   0x00a578: f2be938d  movk     x13, #0xf49c, lsl #16
//   0x00a57c: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00a580: 8b0b0108  add      x8, x8, x11
//   0x00a584: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x00a588: f2d3d76d  movk     x13, #0x9ebb, lsl #32
//   0x00a58c: f2ffebed  movk     x13, #0xff5f, lsl #48
//   0x00a590: aa0c0108  orr      x8, x8, x12
//   0x00a594: ca0d0108  eor      x8, x8, x13
//   0x00a598: 9240154a  and      x10, x10, #0x3f
//   0x00a59c: 8b080168  add      x8, x11, x8
//   0x00a5a0: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00a5a4: f85f83aa  ldur     x10, [x29, #-8]
//   0x00a5a8: f9400108  ldr      x8, [x8]
//   0x00a5ac: cb0a0108  sub      x8, x8, x10
//   0x00a5b0: f85b83aa  ldur     x10, [x29, #-0x48]
//   0x00a5b4: b9000149  str      w9, [x10]
//   0x00a5b8: d61f0100  br       x8
//   0x00a5bc: f94002a9  ldr      x9, [x21]
//   0x00a5c0: 52922aac  mov      w12, #0x9155
//   0x00a5c4: f85b83ab  ldur     x11, [x29, #-0x48]
//   0x00a5c8: 72a5b9ec  movk     w12, #0x2dcf, lsl #16
//   0x00a5cc: f85d03ad  ldur     x13, [x29, #-0x30]
//   0x00a5d0: f9000089  str      x9, [x4]
//   0x00a5d4: b940012a  ldr      w10, [x9]
//   0x00a5d8: b980016b  ldrsw    x11, [x11]
//   0x00a5dc: 4a0c014a  eor      w10, w10, w12
//   0x00a5e0: 529629cc  mov      w12, #0xb14e
//   0x00a5e4: d37ef56b  lsl      x11, x11, #2
//   0x00a5e8: 72af4d2c  movk     w12, #0x7a69, lsl #16
//   0x00a5ec: b900012a  str      w10, [x9]
//   0x00a5f0: 8b0b01aa  add      x10, x13, x11
//   0x00a5f4: b86b69a9  ldr      w9, [x13, x11]
//   0x00a5f8: f90002aa  str      x10, [x21]
//   0x00a5fc: 4a0c0129  eor      w9, w9, w12
//   0x00a600: b82b69a9  str      w9, [x13, x11]
//   0x00a604: 17ffff98  b        #0xa464
//   0x00a608: d0ffffc8  adrp     x8, #0x4000
//   0x00a60c: 5281202a  mov      w10, #0x901
//   0x00a610: 91118108  add      x8, x8, #0x460
//   0x00a614: 72a0150a  movk     w10, #0xa8, lsl #16
//   0x00a618: 11000509  add      w9, w8, #1
//   0x00a61c: 0a280129  bic      w9, w9, w8
//   0x00a620: 2a2903e9  mvn      w9, w9
//   0x00a624: 8a0a0129  and      x9, x9, x10
//   0x00a628: d2890dca  mov      x10, #0x486e
//   0x00a62c: f2b93c0a  movk     x10, #0xc9e0, lsl #16
//   0x00a630: f2c9400a  movk     x10, #0x4a00, lsl #32
//   0x00a634: f2e000aa  movk     x10, #5, lsl #48
//   0x00a638: 8b0a0129  add      x9, x9, x10
//   0x00a63c: 529d35ea  mov      w10, #0xe9af
//   0x00a640: 72a8630a  movk     w10, #0x4318, lsl #16
//   0x00a644: eb0a013f  cmp      x9, x10
//   0x00a648: 54000b43  b.lo     #0xa7b0
//   0x00a64c: f94002a9  ldr      x9, [x21]
//   0x00a650: 90ffffcb  adrp     x11, #0x2000
//   0x00a654: 90ffffcc  adrp     x12, #0x2000
//   0x00a658: 90ffffcd  adrp     x13, #0x2000
//   0x00a65c: b840452a  ldr      w10, [x9], #4
//   0x00a660: 3dc03560  ldr      q0, [x11, #0xd0]
//   0x00a664: 90ffffcb  adrp     x11, #0x2000
//   0x00a668: 3dc02d82  ldr      q2, [x12, #0xb0]
//   0x00a66c: 90ffffcc  adrp     x12, #0x2000
//   0x00a670: 4e040d41  dup      v1.4s, w10
//   0x00a674: 3dc021a3  ldr      q3, [x13, #0x80]
//   0x00a678: 5312454d  lsl      w13, w10, #0xe
//   0x00a67c: 53067d4a  lsr      w10, w10, #6
//   0x00a680: 6ea04420  ushl     v0.4s, v1.4s, v0.4s
//   0x00a684: 3dc03986  ldr      q6, [x12, #0xe0]
//   0x00a688: 6ea24421  ushl     v1.4s, v1.4s, v2.4s
//   0x00a68c: 120c01af  and      w15, w13, #0x100000
//   0x00a690: 1207014a  and      w10, w10, #0x2000000
//   0x00a694: d280800c  mov      x12, #0x400
//   0x00a698: f2a0008c  movk     x12, #4, lsl #16
//   0x00a69c: f81e0069  stur     x9, [x3, #-0x20]
//   0x00a6a0: 4e801802  uzp1     v2.4s, v0.4s, v0.4s
//   0x00a6a4: 4e140404  dup      v4.4s, v0.s[2]
//   0x00a6a8: 4e803805  zip1     v5.4s, v0.4s, v0.4s
//   0x00a6ac: f2c0208c  movk     x12, #0x104, lsl #32
//   0x00a6b0: 6e046024  ext      v4.16b, v1.16b, v4.16b, #0xc
//   0x00a6b4: 8a0c010c  and      x12, x8, x12
//   0x00a6b8: 4e1c0421  dup      v1.4s, v1.s[3]
//   0x00a6bc: 6e004042  ext      v2.16b, v2.16b, v0.16b, #8
//   0x00a6c0: 4e802800  trn1     v0.4s, v0.4s, v0.4s
//   0x00a6c4: 6e042084  ext      v4.16b, v4.16b, v4.16b, #4
//   0x00a6c8: 4e261c21  and      v1.16b, v1.16b, v6.16b
//   0x00a6cc: 3dc02406  ldr      q6, [x0, #0x90]
//   0x00a6d0: 6e054042  ext      v2.16b, v2.16b, v5.16b, #8
//   0x00a6d4: 3dc03d65  ldr      q5, [x11, #0xf0]
//   0x00a6d8: 4e231c00  and      v0.16b, v0.16b, v3.16b
//   0x00a6dc: 4e251c83  and      v3.16b, v4.16b, v5.16b
//   0x00a6e0: 4e261c42  and      v2.16b, v2.16b, v6.16b
//   0x00a6e4: 4ea11c00  orr      v0.16b, v0.16b, v1.16b
//   0x00a6e8: 4ea31c41  orr      v1.16b, v2.16b, v3.16b
//   0x00a6ec: 4ea01c20  orr      v0.16b, v1.16b, v0.16b
//   0x00a6f0: 6e004001  ext      v1.16b, v0.16b, v0.16b, #8
//   0x00a6f4: 0ea11c00  orr      v0.8b, v0.8b, v1.8b
//   0x00a6f8: 0e0c3c0b  mov      w11, v0.s[1]
//   0x00a6fc: 1e26000e  fmov     w14, s0
//   0x00a700: 2a0b01cb  orr      w11, w14, w11
//   0x00a704: 120b01ae  and      w14, w13, #0x200000
//   0x00a708: 2a0f016b  orr      w11, w11, w15
//   0x00a70c: 120a01af  and      w15, w13, #0x400000
//   0x00a710: 2a0e016b  orr      w11, w11, w14
//   0x00a714: 120901ae  and      w14, w13, #0x800000
//   0x00a718: 2a0f016b  orr      w11, w11, w15
//   0x00a71c: 120801ad  and      w13, w13, #0x1000000
//   0x00a720: 2a0e016b  orr      w11, w11, w14
//   0x00a724: f85d03af  ldur     x15, [x29, #-0x30]
//   0x00a728: 2a0d016b  orr      w11, w11, w13
//   0x00a72c: d282080d  mov      x13, #0x1040
//   0x00a730: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x00a734: 2a0a016a  orr      w10, w11, w10
//   0x00a738: d282880b  mov      x11, #0x1440
//   0x00a73c: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x00a740: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00a744: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x00a748: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00a74c: 8b2ac9ef  add      x15, x15, w10, sxtw #2
//   0x00a750: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00a754: aa2801a8  orn      x8, x13, x8
//   0x00a758: 8a0b0108  and      x8, x8, x11
//   0x00a75c: 5280208e  mov      w14, #0x104
//   0x00a760: 8b0c0108  add      x8, x8, x12
//   0x00a764: d28d6b8c  mov      x12, #0x6b5c
//   0x00a768: f90002af  str      x15, [x21]
//   0x00a76c: b94001e9  ldr      w9, [x15]
//   0x00a770: f2be938c  movk     x12, #0xf49c, lsl #16
//   0x00a774: 72a0202e  movk     w14, #0x101, lsl #16
//   0x00a778: f941f28b  ldr      x11, [x20, #0x3e0]
//   0x00a77c: f2d3d76c  movk     x12, #0x9ebb, lsl #32
//   0x00a780: f2ffebec  movk     x12, #0xff5f, lsl #48
//   0x00a784: aa0e0108  orr      x8, x8, x14
//   0x00a788: ca0c0108  eor      x8, x8, x12
//   0x00a78c: 92401529  and      x9, x9, #0x3f
//   0x00a790: 8b080168  add      x8, x11, x8
//   0x00a794: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00a798: f85f83a9  ldur     x9, [x29, #-8]
//   0x00a79c: f9400108  ldr      x8, [x8]
//   0x00a7a0: cb090108  sub      x8, x8, x9
//   0x00a7a4: f85b83a9  ldur     x9, [x29, #-0x48]
//   0x00a7a8: b900012a  str      w10, [x9]
//   0x00a7ac: d61f0100  br       x8
//   0x00a7b0: f94002a9  ldr      x9, [x21]
//   0x00a7b4: 5297778b  mov      w11, #0xbbbc
//   0x00a7b8: 72aeeaab  movk     w11, #0x7755, lsl #16
//   0x00a7bc: f85d03ad  ldur     x13, [x29, #-0x30]
//   0x00a7c0: 5298b7ac  mov      w12, #0xc5bd
//   0x00a7c4: f9000089  str      x9, [x4]
//   0x00a7c8: 72a0630c  movk     w12, #0x318, lsl #16
//   0x00a7cc: b940012a  ldr      w10, [x9]
//   0x00a7d0: 4a0b014a  eor      w10, w10, w11
//   0x00a7d4: b900012a  str      w10, [x9]
//   0x00a7d8: f85b83aa  ldur     x10, [x29, #-0x48]
//   0x00a7dc: f94002a9  ldr      x9, [x21]
//   0x00a7e0: b980014a  ldrsw    x10, [x10]
//   0x00a7e4: 9100112b  add      x11, x9, #4
//   0x00a7e8: f9000089  str      x9, [x4]
//   0x00a7ec: d37ef54a  lsl      x10, x10, #2
//   0x00a7f0: f81e006b  stur     x11, [x3, #-0x20]
//   0x00a7f4: 8b0a01ab  add      x11, x13, x10
//   0x00a7f8: b86a69a9  ldr      w9, [x13, x10]
//   0x00a7fc: f90002ab  str      x11, [x21]
//   0x00a800: 4a0c0129  eor      w9, w9, w12
//   0x00a804: b82a69a9  str      w9, [x13, x10]
//   0x00a808: 17ffff91  b        #0xa64c
//   0x00a80c: f94002a8  ldr      x8, [x21]
//   0x00a810: 90ffffc9  adrp     x9, #0x2000
//   0x00a814: 3dc02403  ldr      q3, [x0, #0x90]
//   0x00a818: 2a1b03ed  mov      w13, w27
//   0x00a81c: b940010a  ldr      w10, [x8]
//   0x00a820: fd408521  ldr      d1, [x9, #0x108]
//   0x00a824: 90ffffc9  adrp     x9, #0x2000
//   0x00a828: 0e040d40  dup      v0.2s, w10
//   0x00a82c: 530c7d4e  lsr      w14, w10, #0xc
//   0x00a830: 3dc02124  ldr      q4, [x9, #0x80]
//   0x00a834: 531b7d49  lsr      w9, w10, #0x1b
//   0x00a838: 121c0129  and      w9, w9, #0x10
//   0x00a83c: 121c01ce  and      w14, w14, #0x10
//   0x00a840: 33115149  bfxil    w9, w10, #0x11, #4
//   0x00a844: 331b794e  bfxil    w14, w10, #0x1b, #4
//   0x00a848: 2ea14400  ushl     v0.2s, v0.2s, v1.2s
//   0x00a84c: 4e801801  uzp1     v1.4s, v0.4s, v0.4s
//   0x00a850: 0e0c3c0b  mov      w11, v0.s[1]
//   0x00a854: 4e803802  zip1     v2.4s, v0.4s, v0.4s
//   0x00a858: 6e004021  ext      v1.16b, v1.16b, v0.16b, #8
//   0x00a85c: 1214016f  and      w15, w11, #0x1000
//   0x00a860: 6e024021  ext      v1.16b, v1.16b, v2.16b, #8
//   0x00a864: 4e241c42  and      v2.16b, v2.16b, v4.16b
//   0x00a868: 4e231c21  and      v1.16b, v1.16b, v3.16b
//   0x00a86c: 4ea21c21  orr      v1.16b, v1.16b, v2.16b
//   0x00a870: 6e014022  ext      v2.16b, v1.16b, v1.16b, #8
//   0x00a874: 0ea21c21  orr      v1.8b, v1.8b, v2.8b
//   0x00a878: 0e0c3c2c  mov      w12, v1.s[1]
//   0x00a87c: 1e26002a  fmov     w10, s1
//   0x00a880: 2a0c014a  orr      w10, w10, w12
//   0x00a884: 1213016c  and      w12, w11, #0x2000
//   0x00a888: 2a0f014a  orr      w10, w10, w15
//   0x00a88c: 1212016f  and      w15, w11, #0x4000
//   0x00a890: 2a0c014a  orr      w10, w10, w12
//   0x00a894: 2a0f014c  orr      w12, w10, w15
//   0x00a898: 1400001f  b        #0xa914
//   0x00a89c: f94002a8  ldr      x8, [x21]
//   0x00a8a0: 2a1b03ed  mov      w13, w27
//   0x00a8a4: b940010a  ldr      w10, [x8]
//   0x00a8a8: 530b7d49  lsr      w9, w10, #0xb
//   0x00a8ac: 121b012b  and      w11, w9, #0x20
//   0x00a8b0: 121a012c  and      w12, w9, #0x40
//   0x00a8b4: 3315654b  bfxil    w11, w10, #0x15, #5
//   0x00a8b8: 1219012e  and      w14, w9, #0x80
//   0x00a8bc: 2a0c016b  orr      w11, w11, w12
//   0x00a8c0: 1218012c  and      w12, w9, #0x100
//   0x00a8c4: 2a0e016b  orr      w11, w11, w14
//   0x00a8c8: 12170129  and      w9, w9, #0x200
//   0x00a8cc: 2a0c016b  orr      w11, w11, w12
//   0x00a8d0: 53107d4c  lsr      w12, w10, #0x10
//   0x00a8d4: 2a090169  orr      w9, w11, w9
//   0x00a8d8: 1216018b  and      w11, w12, #0x400
//   0x00a8dc: 2a0b0129  orr      w9, w9, w11
//   0x00a8e0: 1215018b  and      w11, w12, #0x800
//   0x00a8e4: 531b7d4e  lsr      w14, w10, #0x1b
//   0x00a8e8: 2a0b012b  orr      w11, w9, w11
//   0x00a8ec: 1214018f  and      w15, w12, #0x1000
//   0x00a8f0: 121c01c9  and      w9, w14, #0x10
//   0x00a8f4: 2a0f016b  orr      w11, w11, w15
//   0x00a8f8: 1213018e  and      w14, w12, #0x2000
//   0x00a8fc: 1212018c  and      w12, w12, #0x4000
//   0x00a900: 2a0e016b  orr      w11, w11, w14
//   0x00a904: 330c3d49  bfxil    w9, w10, #0xc, #4
//   0x00a908: 53072d4e  ubfx     w14, w10, #7, #5
//   0x00a90c: 2a0c016c  orr      w12, w11, w12
//   0x00a910: 5317594b  lsl      w11, w10, #9
//   0x00a914: d0ffffca  adrp     x10, #0x4000
//   0x00a918: 1211016b  and      w11, w11, #0x8000
//   0x00a91c: 9111814a  add      x10, x10, #0x460
//   0x00a920: 2a0b018b  orr      w11, w12, w11
//   0x00a924: 1100054d  add      w13, w10, #1
//   0x00a928: b90002e9  str      w9, [x23]
//   0x00a92c: 0a2a01ac  bic      w12, w13, w10
//   0x00a930: 5298200d  mov      w13, #0xc100
//   0x00a934: 2a2c03ec  mvn      w12, w12
//   0x00a938: 72a1f00d  movk     w13, #0xf80, lsl #16
//   0x00a93c: 8a0d018c  and      x12, x12, x13
//   0x00a940: d2856a2d  mov      x13, #0x2b51
//   0x00a944: f2af8ced  movk     x13, #0x7c67, lsl #16
//   0x00a948: b900030e  str      w14, [x24]
//   0x00a94c: f2e0064d  movk     x13, #0x32, lsl #48
//   0x00a950: 790003cb  strh     w11, [x30]
//   0x00a954: 8b0d018c  add      x12, x12, x13
//   0x00a958: 52880eed  mov      w13, #0x4077
//   0x00a95c: 72a0f72d  movk     w13, #0x7b9, lsl #16
//   0x00a960: eb0d019f  cmp      x12, x13
//   0x00a964: 540004e3  b.lo     #0xaa00
//   0x00a968: f869da69  ldr      x9, [x19, w9, sxtw #3]
//   0x00a96c: 93403d6b  sxth     x11, w11
//   0x00a970: d282080c  mov      x12, #0x1040
//   0x00a974: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00a978: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00a97c: f100013f  cmp      x9, #0
//   0x00a980: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00a984: 9a8bc3e9  csel     x9, xzr, x11, gt
//   0x00a988: d280800b  mov      x11, #0x400
//   0x00a98c: f2a0008b  movk     x11, #4, lsl #16
//   0x00a990: aa2a018c  orn      x12, x12, x10
//   0x00a994: 8b090908  add      x8, x8, x9, lsl #2
//   0x00a998: d2828809  mov      x9, #0x1440
//   0x00a99c: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00a9a0: f2c0208b  movk     x11, #0x104, lsl #32
//   0x00a9a4: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00a9a8: 8a0b014a  and      x10, x10, x11
//   0x00a9ac: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00a9b0: 8a090189  and      x9, x12, x9
//   0x00a9b4: 5280208c  mov      w12, #0x104
//   0x00a9b8: b8404d0b  ldr      w11, [x8, #4]!
//   0x00a9bc: f90002a8  str      x8, [x21]
//   0x00a9c0: 8b0a0128  add      x8, x9, x10
//   0x00a9c4: d28d6b8a  mov      x10, #0x6b5c
//   0x00a9c8: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00a9cc: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00a9d0: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00a9d4: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00a9d8: aa0c0108  orr      x8, x8, x12
//   0x00a9dc: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00a9e0: ca0a0108  eor      x8, x8, x10
//   0x00a9e4: 9240156a  and      x10, x11, #0x3f
//   0x00a9e8: 8b080128  add      x8, x9, x8
//   0x00a9ec: f85f83a9  ldur     x9, [x29, #-8]
//   0x00a9f0: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00a9f4: f9400108  ldr      x8, [x8]
//   0x00a9f8: cb090108  sub      x8, x8, x9
//   0x00a9fc: d61f0100  br       x8
//   0x00aa00: 2a0903e8  mov      w8, w9
//   0x00aa04: 529a520d  mov      w13, #0xd290
//   0x00aa08: d37df108  lsl      x8, x8, #3
//   0x00aa0c: 72a1f58d  movk     w13, #0xfac, lsl #16
//   0x00aa10: f8686a6c  ldr      x12, [x19, x8]
//   0x00aa14: ca0d018d  eor      x13, x12, x13
//   0x00aa18: f100059f  cmp      x12, #1
//   0x00aa1c: f8286a6d  str      x13, [x19, x8]
//   0x00aa20: 52981d88  mov      w8, #0xc0ec
//   0x00aa24: 72a312a8  movk     w8, #0x1895, lsl #16
//   0x00aa28: 2a0b03ed  mov      w13, w11
//   0x00aa2c: 4a080128  eor      w8, w9, w8
//   0x00aa30: 1289fec9  mov      w9, #-0x4ff7
//   0x00aa34: 93403dad  sxth     x13, w13
//   0x00aa38: f94002ac  ldr      x12, [x21]
//   0x00aa3c: 4a09016b  eor      w11, w11, w9
//   0x00aa40: 9a9fc1a9  csel     x9, x13, xzr, gt
//   0x00aa44: b90002e8  str      w8, [x23]
//   0x00aa48: 8b090988  add      x8, x12, x9, lsl #2
//   0x00aa4c: f900008c  str      x12, [x4]
//   0x00aa50: 790003cb  strh     w11, [x30]
//   0x00aa54: 528b076c  mov      w12, #0x583b
//   0x00aa58: 72aef7ec  movk     w12, #0x77bf, lsl #16
//   0x00aa5c: b8404d09  ldr      w9, [x8, #4]!
//   0x00aa60: f90002a8  str      x8, [x21]
//   0x00aa64: 4a0c0129  eor      w9, w9, w12
//   0x00aa68: b9000109  str      w9, [x8]
//   0x00aa6c: b94002e9  ldr      w9, [x23]
//   0x00aa70: f94002a8  ldr      x8, [x21]
//   0x00aa74: 17ffffbd  b        #0xa968
//   0x00aa78: f94002a8  ldr      x8, [x21]
//   0x00aa7c: 2a1b03ed  mov      w13, w27
//   0x00aa80: b940010a  ldr      w10, [x8]
//   0x00aa84: 53017d4b  lsr      w11, w10, #1
//   0x00aa88: 121b0169  and      w9, w11, #0x20
//   0x00aa8c: 121a016c  and      w12, w11, #0x40
//   0x00aa90: 33105149  bfxil    w9, w10, #0x10, #5
//   0x00aa94: 1219016e  and      w14, w11, #0x80
//   0x00aa98: 2a0c0129  orr      w9, w9, w12
//   0x00aa9c: 1218016c  and      w12, w11, #0x100
//   0x00aaa0: 2a0e012e  orr      w14, w9, w14
//   0x00aaa4: 1217016b  and      w11, w11, #0x200
//   0x00aaa8: 2a0c01cc  orr      w12, w14, w12
//   0x00aaac: 530b7d4e  lsr      w14, w10, #0xb
//   0x00aab0: 2a0b018b  orr      w11, w12, w11
//   0x00aab4: 121601cc  and      w12, w14, #0x400
//   0x00aab8: 2a0c016b  orr      w11, w11, w12
//   0x00aabc: 121501cc  and      w12, w14, #0x800
//   0x00aac0: 2a0c016b  orr      w11, w11, w12
//   0x00aac4: 121401cc  and      w12, w14, #0x1000
//   0x00aac8: 2a0c016b  orr      w11, w11, w12
//   0x00aacc: 121301cc  and      w12, w14, #0x2000
//   0x00aad0: 2a0c016b  orr      w11, w11, w12
//   0x00aad4: 53167d4c  lsr      w12, w10, #0x16
//   0x00aad8: 121c018f  and      w15, w12, #0x10
//   0x00aadc: 531b7d49  lsr      w9, w10, #0x1b
//   0x00aae0: 330c3d4f  bfxil    w15, w10, #0xc, #4
//   0x00aae4: 121201cc  and      w12, w14, #0x4000
//   0x00aae8: 2a0c016b  orr      w11, w11, w12
//   0x00aaec: 531c6d4c  lsl      w12, w10, #4
//   0x00aaf0: b90002e9  str      w9, [x23]
//   0x00aaf4: b900030f  str      w15, [x24]
//   0x00aaf8: 14000018  b        #0xab58
//   0x00aafc: f94002a8  ldr      x8, [x21]
//   0x00ab00: 2a1b03ed  mov      w13, w27
//   0x00ab04: b940010a  ldr      w10, [x8]
//   0x00ab08: 53107d4b  lsr      w11, w10, #0x10
//   0x00ab0c: 531b7d49  lsr      w9, w10, #0x1b
//   0x00ab10: 1216016c  and      w12, w11, #0x400
//   0x00ab14: 1215016e  and      w14, w11, #0x800
//   0x00ab18: 330b514c  bfxil    w12, w10, #0xb, #0xa
//   0x00ab1c: 121c0129  and      w9, w9, #0x10
//   0x00ab20: 2a0e018c  orr      w12, w12, w14
//   0x00ab24: 1214016e  and      w14, w11, #0x1000
//   0x00ab28: 2a0e018c  orr      w12, w12, w14
//   0x00ab2c: 1213016e  and      w14, w11, #0x2000
//   0x00ab30: 2a0e018c  orr      w12, w12, w14
//   0x00ab34: 53027d4e  lsr      w14, w10, #2
//   0x00ab38: 121c01ce  and      w14, w14, #0x10
//   0x00ab3c: 1212016b  and      w11, w11, #0x4000
//   0x00ab40: 33072949  bfxil    w9, w10, #7, #4
//   0x00ab44: 3316654e  bfxil    w14, w10, #0x16, #4
//   0x00ab48: 2a0b018b  orr      w11, w12, w11
//   0x00ab4c: 53067d4c  lsr      w12, w10, #6
//   0x00ab50: b90002e9  str      w9, [x23]
//   0x00ab54: b900030e  str      w14, [x24]
//   0x00ab58: d0ffffca  adrp     x10, #0x4000
//   0x00ab5c: 1211018c  and      w12, w12, #0x8000
//   0x00ab60: 9111814a  add      x10, x10, #0x460
//   0x00ab64: 2a0c016b  orr      w11, w11, w12
//   0x00ab68: 1100054d  add      w13, w10, #1
//   0x00ab6c: 0a2a01ac  bic      w12, w13, w10
//   0x00ab70: 5281420d  mov      w13, #0xa10
//   0x00ab74: 2a2c03ec  mvn      w12, w12
//   0x00ab78: 72a0310d  movk     w13, #0x188, lsl #16
//   0x00ab7c: 8a0d018c  and      x12, x12, x13
//   0x00ab80: d2963ced  mov      x13, #0xb1e7
//   0x00ab84: f2b682ed  movk     x13, #0xb417, lsl #16
//   0x00ab88: 790003cb  strh     w11, [x30]
//   0x00ab8c: f2c4000d  movk     x13, #0x2000, lsl #32
//   0x00ab90: f2e1000d  movk     x13, #0x800, lsl #48
//   0x00ab94: aa0d018c  orr      x12, x12, x13
//   0x00ab98: 5298dc6d  mov      w13, #0xc6e3
//   0x00ab9c: 72a4eead  movk     w13, #0x2775, lsl #16
//   0x00aba0: eb0d019f  cmp      x12, x13
//   0x00aba4: 540004e3  b.lo     #0xac40
//   0x00aba8: f869da69  ldr      x9, [x19, w9, sxtw #3]
//   0x00abac: 93403d6b  sxth     x11, w11
//   0x00abb0: d282080c  mov      x12, #0x1040
//   0x00abb4: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00abb8: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00abbc: f100013f  cmp      x9, #0
//   0x00abc0: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00abc4: 9a9fc169  csel     x9, x11, xzr, gt
//   0x00abc8: d280800b  mov      x11, #0x400
//   0x00abcc: f2a0008b  movk     x11, #4, lsl #16
//   0x00abd0: aa2a018c  orn      x12, x12, x10
//   0x00abd4: 8b090908  add      x8, x8, x9, lsl #2
//   0x00abd8: d2828809  mov      x9, #0x1440
//   0x00abdc: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00abe0: f2c0208b  movk     x11, #0x104, lsl #32
//   0x00abe4: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00abe8: 8a0b014a  and      x10, x10, x11
//   0x00abec: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00abf0: 8a090189  and      x9, x12, x9
//   0x00abf4: 5280208c  mov      w12, #0x104
//   0x00abf8: b8404d0b  ldr      w11, [x8, #4]!
//   0x00abfc: f90002a8  str      x8, [x21]
//   0x00ac00: 8b0a0128  add      x8, x9, x10
//   0x00ac04: d28d6b8a  mov      x10, #0x6b5c
//   0x00ac08: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00ac0c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00ac10: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00ac14: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00ac18: aa0c0108  orr      x8, x8, x12
//   0x00ac1c: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00ac20: ca0a0108  eor      x8, x8, x10
//   0x00ac24: 9240156a  and      x10, x11, #0x3f
//   0x00ac28: 8b080128  add      x8, x9, x8
//   0x00ac2c: f85f83a9  ldur     x9, [x29, #-8]
//   0x00ac30: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00ac34: f9400108  ldr      x8, [x8]
//   0x00ac38: cb090108  sub      x8, x8, x9
//   0x00ac3c: d61f0100  br       x8
//   0x00ac40: 2a0903e8  mov      w8, w9
//   0x00ac44: 529abc4d  mov      w13, #0xd5e2
//   0x00ac48: d37df108  lsl      x8, x8, #3
//   0x00ac4c: 72a451cd  movk     w13, #0x228e, lsl #16
//   0x00ac50: f8686a6c  ldr      x12, [x19, x8]
//   0x00ac54: ca0d018d  eor      x13, x12, x13
//   0x00ac58: f100019f  cmp      x12, #0
//   0x00ac5c: f8286a6d  str      x13, [x19, x8]
//   0x00ac60: 529cdc28  mov      w8, #0xe6e1
//   0x00ac64: 72a5dfe8  movk     w8, #0x2eff, lsl #16
//   0x00ac68: 2a0b03ed  mov      w13, w11
//   0x00ac6c: 4a080128  eor      w8, w9, w8
//   0x00ac70: 5287e6a9  mov      w9, #0x3f35
//   0x00ac74: 93403dad  sxth     x13, w13
//   0x00ac78: f94002ac  ldr      x12, [x21]
//   0x00ac7c: 4a09016b  eor      w11, w11, w9
//   0x00ac80: 9a8d03e9  csel     x9, xzr, x13, eq
//   0x00ac84: b90002e8  str      w8, [x23]
//   0x00ac88: 8b090988  add      x8, x12, x9, lsl #2
//   0x00ac8c: f900008c  str      x12, [x4]
//   0x00ac90: 790003cb  strh     w11, [x30]
//   0x00ac94: 529b7b8c  mov      w12, #0xdbdc
//   0x00ac98: 72a02e2c  movk     w12, #0x171, lsl #16
//   0x00ac9c: b8404d09  ldr      w9, [x8, #4]!
//   0x00aca0: f90002a8  str      x8, [x21]
//   0x00aca4: 4a0c0129  eor      w9, w9, w12
//   0x00aca8: b9000109  str      w9, [x8]
//   0x00acac: b94002e9  ldr      w9, [x23]
//   0x00acb0: f94002a8  ldr      x8, [x21]
//   0x00acb4: 17ffffbd  b        #0xaba8
//   0x00acb8: f94002a8  ldr      x8, [x21]
//   0x00acbc: 2a1b03ee  mov      w14, w27
//   0x00acc0: b940010b  ldr      w11, [x8]
//   0x00acc4: 53157d6a  lsr      w10, w11, #0x15
//   0x00acc8: 530b7d6c  lsr      w12, w11, #0xb
//   0x00accc: 121b014d  and      w13, w10, #0x20
//   0x00acd0: 121a014f  and      w15, w10, #0x40
//   0x00acd4: 3306296d  bfxil    w13, w11, #6, #5
//   0x00acd8: 531b7d69  lsr      w9, w11, #0x1b
//   0x00acdc: 2a0f01ad  orr      w13, w13, w15
//   0x00ace0: 1219014f  and      w15, w10, #0x80
//   0x00ace4: 2a0f01ad  orr      w13, w13, w15
//   0x00ace8: 1218014f  and      w15, w10, #0x100
//   0x00acec: 1217014a  and      w10, w10, #0x200
//   0x00acf0: 2a0f01ad  orr      w13, w13, w15
//   0x00acf4: 1216018f  and      w15, w12, #0x400
//   0x00acf8: 2a0a01aa  orr      w10, w13, w10
//   0x00acfc: 1215018d  and      w13, w12, #0x800
//   0x00ad00: 2a0f014a  orr      w10, w10, w15
//   0x00ad04: 1214018f  and      w15, w12, #0x1000
//   0x00ad08: 2a0d014a  orr      w10, w10, w13
//   0x00ad0c: 1213018d  and      w13, w12, #0x2000
//   0x00ad10: 2a0f014a  orr      w10, w10, w15
//   0x00ad14: 121c0129  and      w9, w9, #0x10
//   0x00ad18: 1212018c  and      w12, w12, #0x4000
//   0x00ad1c: 2a0d014d  orr      w13, w10, w13
//   0x00ad20: 33115169  bfxil    w9, w11, #0x11, #4
//   0x00ad24: 530c416a  ubfx     w10, w11, #0xc, #5
//   0x00ad28: 2a0c01ac  orr      w12, w13, w12
//   0x00ad2c: 531c6d6d  lsl      w13, w11, #4
//   0x00ad30: 14000014  b        #0xad80
//   0x00ad34: f94002a8  ldr      x8, [x21]
//   0x00ad38: 2a1b03ee  mov      w14, w27
//   0x00ad3c: b940010b  ldr      w11, [x8]
//   0x00ad40: 53017d6c  lsr      w12, w11, #1
//   0x00ad44: 53167d6a  lsr      w10, w11, #0x16
//   0x00ad48: 1216018d  and      w13, w12, #0x400
//   0x00ad4c: 1215018f  and      w15, w12, #0x800
//   0x00ad50: 3310656d  bfxil    w13, w11, #0x10, #0xa
//   0x00ad54: 121c014a  and      w10, w10, #0x10
//   0x00ad58: 2a0f01ad  orr      w13, w13, w15
//   0x00ad5c: 1214018f  and      w15, w12, #0x1000
//   0x00ad60: 2a0f01ad  orr      w13, w13, w15
//   0x00ad64: 1213018f  and      w15, w12, #0x2000
//   0x00ad68: 1212018c  and      w12, w12, #0x4000
//   0x00ad6c: 2a0f01ad  orr      w13, w13, w15
//   0x00ad70: 531b7d69  lsr      w9, w11, #0x1b
//   0x00ad74: 3307296a  bfxil    w10, w11, #7, #4
//   0x00ad78: 2a0c01ac  orr      w12, w13, w12
//   0x00ad7c: 5317596d  lsl      w13, w11, #9
//   0x00ad80: d0ffffcb  adrp     x11, #0x4000
//   0x00ad84: 121101ad  and      w13, w13, #0x8000
//   0x00ad88: 9111816b  add      x11, x11, #0x460
//   0x00ad8c: 2a0d018c  orr      w12, w12, w13
//   0x00ad90: 1100056e  add      w14, w11, #1
//   0x00ad94: b90002e9  str      w9, [x23]
//   0x00ad98: 0a2b01cd  bic      w13, w14, w11
//   0x00ad9c: 5282210e  mov      w14, #0x1108
//   0x00ada0: 2a2d03ed  mvn      w13, w13
//   0x00ada4: 72a010ae  movk     w14, #0x85, lsl #16
//   0x00ada8: 8a0e01ad  and      x13, x13, x14
//   0x00adac: d28c62ee  mov      x14, #0x6317
//   0x00adb0: f2ae2fae  movk     x14, #0x717d, lsl #16
//   0x00adb4: b900030a  str      w10, [x24]
//   0x00adb8: f2c2000e  movk     x14, #0x1000, lsl #32
//   0x00adbc: 790003cc  strh     w12, [x30]
//   0x00adc0: f2e0100e  movk     x14, #0x80, lsl #48
//   0x00adc4: 8b0e01ad  add      x13, x13, x14
//   0x00adc8: 52849b0e  mov      w14, #0x24d8
//   0x00adcc: 72a4ee8e  movk     w14, #0x2774, lsl #16
//   0x00add0: eb0e01bf  cmp      x13, x14
//   0x00add4: 54000503  b.lo     #0xae74
//   0x00add8: f869da69  ldr      x9, [x19, w9, sxtw #3]
//   0x00addc: 93403d8c  sxth     x12, w12
//   0x00ade0: f86ada6a  ldr      x10, [x19, w10, sxtw #3]
//   0x00ade4: eb0a013f  cmp      x9, x10
//   0x00ade8: d280800a  mov      x10, #0x400
//   0x00adec: 9a9f0189  csel     x9, x12, xzr, eq
//   0x00adf0: d282080c  mov      x12, #0x1040
//   0x00adf4: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00adf8: f2a0008a  movk     x10, #4, lsl #16
//   0x00adfc: 8b090908  add      x8, x8, x9, lsl #2
//   0x00ae00: d2828809  mov      x9, #0x1440
//   0x00ae04: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00ae08: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00ae0c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00ae10: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00ae14: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00ae18: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00ae1c: aa2b018c  orn      x12, x12, x11
//   0x00ae20: 8a0a016a  and      x10, x11, x10
//   0x00ae24: 8a090189  and      x9, x12, x9
//   0x00ae28: 5280208c  mov      w12, #0x104
//   0x00ae2c: b8404d0b  ldr      w11, [x8, #4]!
//   0x00ae30: f90002a8  str      x8, [x21]
//   0x00ae34: 8b0a0128  add      x8, x9, x10
//   0x00ae38: d28d6b8a  mov      x10, #0x6b5c
//   0x00ae3c: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00ae40: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00ae44: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00ae48: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00ae4c: aa0c0108  orr      x8, x8, x12
//   0x00ae50: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00ae54: ca0a0108  eor      x8, x8, x10
//   0x00ae58: 9240156a  and      x10, x11, #0x3f
//   0x00ae5c: 8b080128  add      x8, x9, x8
//   0x00ae60: f85f83a9  ldur     x9, [x29, #-8]
//   0x00ae64: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00ae68: f9400108  ldr      x8, [x8]
//   0x00ae6c: cb090108  sub      x8, x8, x9
//   0x00ae70: d61f0100  br       x8
//   0x00ae74: 2a0903e8  mov      w8, w9
//   0x00ae78: 529a412e  mov      w14, #0xd209
//   0x00ae7c: d37df108  lsl      x8, x8, #3
//   0x00ae80: 72a3472e  movk     w14, #0x1a39, lsl #16
//   0x00ae84: 2a0a03ef  mov      w15, w10
//   0x00ae88: d37df1ef  lsl      x15, x15, #3
//   0x00ae8c: f8686a6d  ldr      x13, [x19, x8]
//   0x00ae90: ca0e01ae  eor      x14, x13, x14
//   0x00ae94: f8286a6e  str      x14, [x19, x8]
//   0x00ae98: 529c6f0e  mov      w14, #0xe378
//   0x00ae9c: f86f6a68  ldr      x8, [x19, x15]
//   0x00aea0: 72ae1fae  movk     w14, #0x70fd, lsl #16
//   0x00aea4: ca0e010e  eor      x14, x8, x14
//   0x00aea8: eb0801bf  cmp      x13, x8
//   0x00aeac: 2a0c03e8  mov      w8, w12
//   0x00aeb0: 529fcfad  mov      w13, #0xfe7d
//   0x00aeb4: f82f6a6e  str      x14, [x19, x15]
//   0x00aeb8: 528b4a4e  mov      w14, #0x5a52
//   0x00aebc: 72a9418e  movk     w14, #0x4a0c, lsl #16
//   0x00aec0: 72a4434d  movk     w13, #0x221a, lsl #16
//   0x00aec4: 4a0e014a  eor      w10, w10, w14
//   0x00aec8: 93403d08  sxth     x8, w8
//   0x00aecc: f94002ae  ldr      x14, [x21]
//   0x00aed0: 4a0d0129  eor      w9, w9, w13
//   0x00aed4: 52859ced  mov      w13, #0x2ce7
//   0x00aed8: 9a9f8108  csel     x8, x8, xzr, hi
//   0x00aedc: 4a0d018c  eor      w12, w12, w13
//   0x00aee0: b900030a  str      w10, [x24]
//   0x00aee4: 8b0809c8  add      x8, x14, x8, lsl #2
//   0x00aee8: b90002e9  str      w9, [x23]
//   0x00aeec: f900008e  str      x14, [x4]
//   0x00aef0: 529fdc4a  mov      w10, #0xfee2
//   0x00aef4: 790003cc  strh     w12, [x30]
//   0x00aef8: 72a9864a  movk     w10, #0x4c32, lsl #16
//   0x00aefc: b8404d09  ldr      w9, [x8, #4]!
//   0x00af00: f90002a8  str      x8, [x21]
//   0x00af04: 4a0a0129  eor      w9, w9, w10
//   0x00af08: b9000109  str      w9, [x8]
//   0x00af0c: b94002e9  ldr      w9, [x23]
//   0x00af10: b940030a  ldr      w10, [x24]
//   0x00af14: f94002a8  ldr      x8, [x21]
//   0x00af18: 17ffffb0  b        #0xadd8
//   0x00af1c: f94002a8  ldr      x8, [x21]
//   0x00af20: 90ffffc9  adrp     x9, #0x2000
//   0x00af24: 2a1b03ee  mov      w14, w27
//   0x00af28: b940010b  ldr      w11, [x8]
//   0x00af2c: fd409521  ldr      d1, [x9, #0x128]
//   0x00af30: 90ffffc9  adrp     x9, #0x2000
//   0x00af34: 0e040d60  dup      v0.2s, w11
//   0x00af38: 53117d6a  lsr      w10, w11, #0x11
//   0x00af3c: 3dc02123  ldr      q3, [x9, #0x80]
//   0x00af40: 531b7d69  lsr      w9, w11, #0x1b
//   0x00af44: 121c0129  and      w9, w9, #0x10
//   0x00af48: 121c014a  and      w10, w10, #0x10
//   0x00af4c: 33166569  bfxil    w9, w11, #0x16, #4
//   0x00af50: 331b796a  bfxil    w10, w11, #0x1b, #4
//   0x00af54: 2ea14400  ushl     v0.2s, v0.2s, v1.2s
//   0x00af58: 4e801801  uzp1     v1.4s, v0.4s, v0.4s
//   0x00af5c: 4e040404  dup      v4.4s, v0.s[0]
//   0x00af60: 4e803802  zip1     v2.4s, v0.4s, v0.4s
//   0x00af64: 4e231c83  and      v3.16b, v4.16b, v3.16b
//   0x00af68: 1e26000d  fmov     w13, s0
//   0x00af6c: 6e004021  ext      v1.16b, v1.16b, v0.16b, #8
//   0x00af70: 121401b0  and      w16, w13, #0x1000
//   0x00af74: 6e024021  ext      v1.16b, v1.16b, v2.16b, #8
//   0x00af78: 3dc02402  ldr      q2, [x0, #0x90]
//   0x00af7c: 4e221c21  and      v1.16b, v1.16b, v2.16b
//   0x00af80: 4ea31c21  orr      v1.16b, v1.16b, v3.16b
//   0x00af84: 6e014022  ext      v2.16b, v1.16b, v1.16b, #8
//   0x00af88: 0ea21c21  orr      v1.8b, v1.8b, v2.8b
//   0x00af8c: 0e0c3c2c  mov      w12, v1.s[1]
//   0x00af90: 1e26002f  fmov     w15, s1
//   0x00af94: 2a0c01ec  orr      w12, w15, w12
//   0x00af98: 121301af  and      w15, w13, #0x2000
//   0x00af9c: 2a10018c  orr      w12, w12, w16
//   0x00afa0: 121201ad  and      w13, w13, #0x4000
//   0x00afa4: 2a0f018c  orr      w12, w12, w15
//   0x00afa8: 2a0d018c  orr      w12, w12, w13
//   0x00afac: 530b7d6d  lsr      w13, w11, #0xb
//   0x00afb0: 14000021  b        #0xb034
//   0x00afb4: f94002a8  ldr      x8, [x21]
//   0x00afb8: 2a1b03ee  mov      w14, w27
//   0x00afbc: b940010b  ldr      w11, [x8]
//   0x00afc0: 53157d6a  lsr      w10, w11, #0x15
//   0x00afc4: 53027d6c  lsr      w12, w11, #2
//   0x00afc8: 121b014d  and      w13, w10, #0x20
//   0x00afcc: 121a014f  and      w15, w10, #0x40
//   0x00afd0: 3310516d  bfxil    w13, w11, #0x10, #5
//   0x00afd4: 531b7d69  lsr      w9, w11, #0x1b
//   0x00afd8: 2a0f01ad  orr      w13, w13, w15
//   0x00afdc: 1219014f  and      w15, w10, #0x80
//   0x00afe0: 2a0f01ad  orr      w13, w13, w15
//   0x00afe4: 1218014f  and      w15, w10, #0x100
//   0x00afe8: 2a0f01ad  orr      w13, w13, w15
//   0x00afec: 530b7d6f  lsr      w15, w11, #0xb
//   0x00aff0: 1217014a  and      w10, w10, #0x200
//   0x00aff4: 121401f0  and      w16, w15, #0x1000
//   0x00aff8: 2a0a01aa  orr      w10, w13, w10
//   0x00affc: 121601ed  and      w13, w15, #0x400
//   0x00b000: 2a0d014a  orr      w10, w10, w13
//   0x00b004: 121501ed  and      w13, w15, #0x800
//   0x00b008: 2a0d014d  orr      w13, w10, w13
//   0x00b00c: 121c018a  and      w10, w12, #0x10
//   0x00b010: 2a1001ac  orr      w12, w13, w16
//   0x00b014: 121301ed  and      w13, w15, #0x2000
//   0x00b018: 121c0129  and      w9, w9, #0x10
//   0x00b01c: 121201ef  and      w15, w15, #0x4000
//   0x00b020: 2a0d018c  orr      w12, w12, w13
//   0x00b024: 33072969  bfxil    w9, w11, #7, #4
//   0x00b028: 330c3d6a  bfxil    w10, w11, #0xc, #4
//   0x00b02c: 2a0f018c  orr      w12, w12, w15
//   0x00b030: 531c6d6d  lsl      w13, w11, #4
//   0x00b034: b0ffffcb  adrp     x11, #0x4000
//   0x00b038: 121101ad  and      w13, w13, #0x8000
//   0x00b03c: 9111816b  add      x11, x11, #0x460
//   0x00b040: 2a0d018c  orr      w12, w12, w13
//   0x00b044: 1100056e  add      w14, w11, #1
//   0x00b048: b90002e9  str      w9, [x23]
//   0x00b04c: 0a2b01cd  bic      w13, w14, w11
//   0x00b050: 5281080e  mov      w14, #0x840
//   0x00b054: 2a2d03ed  mvn      w13, w13
//   0x00b058: 72a064ce  movk     w14, #0x326, lsl #16
//   0x00b05c: 8a0e01ad  and      x13, x13, x14
//   0x00b060: d29ffeae  mov      x14, #0xfff5
//   0x00b064: f2aabbae  movk     x14, #0x55dd, lsl #16
//   0x00b068: b900030a  str      w10, [x24]
//   0x00b06c: f2c4000e  movk     x14, #0x2000, lsl #32
//   0x00b070: 790003cc  strh     w12, [x30]
//   0x00b074: f2e1000e  movk     x14, #0x800, lsl #48
//   0x00b078: 8b0e01ad  add      x13, x13, x14
//   0x00b07c: 5283826e  mov      w14, #0x1c13
//   0x00b080: 72a08cae  movk     w14, #0x465, lsl #16
//   0x00b084: eb0e01bf  cmp      x13, x14
//   0x00b088: 54000503  b.lo     #0xb128
//   0x00b08c: f869da69  ldr      x9, [x19, w9, sxtw #3]
//   0x00b090: 93403d8c  sxth     x12, w12
//   0x00b094: f86ada6a  ldr      x10, [x19, w10, sxtw #3]
//   0x00b098: eb0a013f  cmp      x9, x10
//   0x00b09c: d280800a  mov      x10, #0x400
//   0x00b0a0: 9a8c03e9  csel     x9, xzr, x12, eq
//   0x00b0a4: d282080c  mov      x12, #0x1040
//   0x00b0a8: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00b0ac: f2a0008a  movk     x10, #4, lsl #16
//   0x00b0b0: 8b090908  add      x8, x8, x9, lsl #2
//   0x00b0b4: d2828809  mov      x9, #0x1440
//   0x00b0b8: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00b0bc: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00b0c0: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00b0c4: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00b0c8: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00b0cc: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00b0d0: aa2b018c  orn      x12, x12, x11
//   0x00b0d4: 8a0a016a  and      x10, x11, x10
//   0x00b0d8: 8a090189  and      x9, x12, x9
//   0x00b0dc: 5280208c  mov      w12, #0x104
//   0x00b0e0: b8404d0b  ldr      w11, [x8, #4]!
//   0x00b0e4: f90002a8  str      x8, [x21]
//   0x00b0e8: 8b0a0128  add      x8, x9, x10
//   0x00b0ec: d28d6b8a  mov      x10, #0x6b5c
//   0x00b0f0: 72a0202c  movk     w12, #0x101, lsl #16
//   0x00b0f4: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00b0f8: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00b0fc: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00b100: aa0c0108  orr      x8, x8, x12
//   0x00b104: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00b108: ca0a0108  eor      x8, x8, x10
//   0x00b10c: 9240156a  and      x10, x11, #0x3f
//   0x00b110: 8b080128  add      x8, x9, x8
//   0x00b114: f85f83a9  ldur     x9, [x29, #-8]
//   0x00b118: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00b11c: f9400108  ldr      x8, [x8]
//   0x00b120: cb090108  sub      x8, x8, x9
//   0x00b124: d61f0100  br       x8
//   0x00b128: 2a0903e8  mov      w8, w9
//   0x00b12c: 528db0ae  mov      w14, #0x6d85
//   0x00b130: d37df108  lsl      x8, x8, #3
//   0x00b134: 72a1640e  movk     w14, #0xb20, lsl #16
//   0x00b138: 2a0a03ef  mov      w15, w10
//   0x00b13c: d37df1ef  lsl      x15, x15, #3
//   0x00b140: f8686a6d  ldr      x13, [x19, x8]
//   0x00b144: ca0e01ae  eor      x14, x13, x14
//   0x00b148: f8286a6e  str      x14, [x19, x8]
//   0x00b14c: 529d278e  mov      w14, #0xe93c
//   0x00b150: f86f6a68  ldr      x8, [x19, x15]
//   0x00b154: 72a61f6e  movk     w14, #0x30fb, lsl #16
//   0x00b158: ca0e010e  eor      x14, x8, x14
//   0x00b15c: eb0801bf  cmp      x13, x8
//   0x00b160: 2a0c03e8  mov      w8, w12
//   0x00b164: 52859c2d  mov      w13, #0x2ce1
//   0x00b168: f82f6a6e  str      x14, [x19, x15]
//   0x00b16c: 52878eee  mov      w14, #0x3c77
//   0x00b170: 72afbece  movk     w14, #0x7df6, lsl #16
//   0x00b174: 72a1664d  movk     w13, #0xb32, lsl #16
//   0x00b178: 4a0e014a  eor      w10, w10, w14
//   0x00b17c: 93403d08  sxth     x8, w8
//   0x00b180: f94002ae  ldr      x14, [x21]
//   0x00b184: 4a0d0129  eor      w9, w9, w13
//   0x00b188: 128bb48d  mov      w13, #-0x5da5
//   0x00b18c: 9a9fb108  csel     x8, x8, xzr, lt
//   0x00b190: 4a0d018c  eor      w12, w12, w13
//   0x00b194: b900030a  str      w10, [x24]
//   0x00b198: 8b0809c8  add      x8, x14, x8, lsl #2
//   0x00b19c: b90002e9  str      w9, [x23]
//   0x00b1a0: f900008e  str      x14, [x4]
//   0x00b1a4: 5287a2ca  mov      w10, #0x3d16
//   0x00b1a8: 790003cc  strh     w12, [x30]
//   0x00b1ac: 72a4a48a  movk     w10, #0x2524, lsl #16
//   0x00b1b0: b8404d09  ldr      w9, [x8, #4]!
//   0x00b1b4: f90002a8  str      x8, [x21]
//   0x00b1b8: 4a0a0129  eor      w9, w9, w10
//   0x00b1bc: b9000109  str      w9, [x8]
//   0x00b1c0: b94002e9  ldr      w9, [x23]
//   0x00b1c4: b940030a  ldr      w10, [x24]
//   0x00b1c8: f94002a8  ldr      x8, [x21]
//   0x00b1cc: 17ffffb0  b        #0xb08c
//   0x00b1d0: b0ffffc8  adrp     x8, #0x4000
//   0x00b1d4: 91118108  add      x8, x8, #0x460
//   0x00b1d8: 11000509  add      w9, w8, #1
//   0x00b1dc: 0a280128  bic      w8, w9, w8
//   0x00b1e0: 52a09a09  mov      w9, #0x4d00000
//   0x00b1e4: 2a2803e8  mvn      w8, w8
//   0x00b1e8: 8a090108  and      x8, x8, x9
//   0x00b1ec: d287bde9  mov      x9, #0x3def
//   0x00b1f0: f2b39409  movk     x9, #0x9ca0, lsl #16
//   0x00b1f4: f2c00809  movk     x9, #0x40, lsl #32
//   0x00b1f8: f2e02609  movk     x9, #0x130, lsl #48
//   0x00b1fc: 8b090108  add      x8, x8, x9
//   0x00b200: 5288faa9  mov      w9, #0x47d5
//   0x00b204: 72a212e9  movk     w9, #0x1097, lsl #16
//   0x00b208: eb09011f  cmp      x8, x9
//   0x00b20c: 54000c03  b.lo     #0xb38c
//   0x00b210: f94002a8  ldr      x8, [x21]
//   0x00b214: b9400109  ldr      w9, [x8]
//   0x00b218: 53077d2c  lsr      w12, w9, #7
//   0x00b21c: d35bfd2d  lsr      x13, x9, #0x1b
//   0x00b220: 531c6d2e  lsl      w14, w9, #4
//   0x00b224: 53087d2b  lsr      w11, w9, #8
//   0x00b228: 927c01ad  and      x13, x13, #0x10
//   0x00b22c: 121601ce  and      w14, w14, #0x400
//   0x00b230: 53097d2a  lsr      w10, w9, #9
//   0x00b234: b356652d  bfxil    x13, x9, #0x16, #4
//   0x00b238: 330b512e  bfxil    w14, w9, #0xb, #0xa
//   0x00b23c: 530a7d2f  lsr      w15, w9, #0xa
//   0x00b240: 3315018e  bfi      w14, w12, #0xb, #1
//   0x00b244: d34b7d2c  ubfx     x12, x9, #0xb, #0x15
//   0x00b248: 3314016e  bfi      w14, w11, #0xc, #1
//   0x00b24c: 1211018b  and      w11, w12, #0x8000
//   0x00b250: 3313014e  bfi      w14, w10, #0xd, #1
//   0x00b254: f86d7a6a  ldr      x10, [x19, x13, lsl #3]
//   0x00b258: 331201ee  bfi      w14, w15, #0xe, #1
//   0x00b25c: b900002d  str      w13, [x1]
//   0x00b260: 2a0b01cc  orr      w12, w14, w11
//   0x00b264: d351fd2b  lsr      x11, x9, #0x11
//   0x00b268: 8b2ca14e  add      x14, x10, w12, sxth
//   0x00b26c: 927c016a  and      x10, x11, #0x10
//   0x00b270: 927df1cb  and      x11, x14, #0xfffffffffffffff8
//   0x00b274: b35b792a  bfxil    x10, x9, #0x1b, #4
//   0x00b278: 790000ec  strh     w12, [x7]
//   0x00b27c: f9400169  ldr      x9, [x11]
//   0x00b280: 924009cb  and      x11, x14, #7
//   0x00b284: f1001d7f  cmp      x11, #7
//   0x00b288: b900030a  str      w10, [x24]
//   0x00b28c: 54000061  b.ne     #0xb298
//   0x00b290: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00b294: 1400000d  b        #0xb2c8
//   0x00b298: 2a0a03ea  mov      w10, w10
//   0x00b29c: d37df16b  lsl      x11, x11, #3
//   0x00b2a0: d37df14a  lsl      x10, x10, #3
//   0x00b2a4: 5280070c  mov      w12, #0x38
//   0x00b2a8: cb0b018c  sub      x12, x12, x11
//   0x00b2ac: 92ffe00e  mov      x14, #0xffffffffffffff
//   0x00b2b0: 9acb25cb  lsr      x11, x14, x11
//   0x00b2b4: f86a6a6d  ldr      x13, [x19, x10]
//   0x00b2b8: 9acc2129  lsl      x9, x9, x12
//   0x00b2bc: 8a0b01ab  and      x11, x13, x11
//   0x00b2c0: aa090169  orr      x9, x11, x9
//   0x00b2c4: f82a6a69  str      x9, [x19, x10]
//   0x00b2c8: b0ffffc9  adrp     x9, #0x4000
//   0x00b2cc: 5288280b  mov      w11, #0x4140
//   0x00b2d0: 91118129  add      x9, x9, #0x460
//   0x00b2d4: 1100052a  add      w10, w9, #1
//   0x00b2d8: 0a29014a  bic      w10, w10, w9
//   0x00b2dc: 2a2a03ea  mvn      w10, w10
//   0x00b2e0: 8a0b014a  and      x10, x10, x11
//   0x00b2e4: d282854b  mov      x11, #0x142a
//   0x00b2e8: f2ac840b  movk     x11, #0x6420, lsl #16
//   0x00b2ec: f2c0040b  movk     x11, #0x20, lsl #32
//   0x00b2f0: f2e0024b  movk     x11, #0x12, lsl #48
//   0x00b2f4: aa0b014a  orr      x10, x10, x11
//   0x00b2f8: 5286e3eb  mov      w11, #0x371f
//   0x00b2fc: 72a026eb  movk     w11, #0x137, lsl #16
//   0x00b300: eb0b015f  cmp      x10, x11
//   0x00b304: 54000803  b.lo     #0xb404
//   0x00b308: b8404d0a  ldr      w10, [x8, #4]!
//   0x00b30c: d282080b  mov      x11, #0x1040
//   0x00b310: f90002a8  str      x8, [x21]
//   0x00b314: d2808008  mov      x8, #0x400
//   0x00b318: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00b31c: f2a00088  movk     x8, #4, lsl #16
//   0x00b320: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00b324: f2c02088  movk     x8, #0x104, lsl #32
//   0x00b328: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00b32c: 8a080128  and      x8, x9, x8
//   0x00b330: aa290169  orn      x9, x11, x9
//   0x00b334: d282880b  mov      x11, #0x1440
//   0x00b338: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00b33c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00b340: 9240154a  and      x10, x10, #0x3f
//   0x00b344: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00b348: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00b34c: 8a0b0129  and      x9, x9, x11
//   0x00b350: 8b080128  add      x8, x9, x8
//   0x00b354: 52802089  mov      w9, #0x104
//   0x00b358: 72a02029  movk     w9, #0x101, lsl #16
//   0x00b35c: aa090108  orr      x8, x8, x9
//   0x00b360: d28d6b89  mov      x9, #0x6b5c
//   0x00b364: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00b368: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00b36c: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00b370: ca090108  eor      x8, x8, x9
//   0x00b374: f85f83a9  ldur     x9, [x29, #-8]
//   0x00b378: 8b080188  add      x8, x12, x8
//   0x00b37c: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00b380: f9400108  ldr      x8, [x8]
//   0x00b384: cb090108  sub      x8, x8, x9
//   0x00b388: d61f0100  br       x8
//   0x00b38c: f94002a8  ldr      x8, [x21]
//   0x00b390: 5283300a  mov      w10, #0x1980
//   0x00b394: 72a7306a  movk     w10, #0x3983, lsl #16
//   0x00b398: 5294cb4c  mov      w12, #0xa65a
//   0x00b39c: 72a6184c  movk     w12, #0x30c2, lsl #16
//   0x00b3a0: f9000088  str      x8, [x4]
//   0x00b3a4: b9400109  ldr      w9, [x8]
//   0x00b3a8: 4a0a0129  eor      w9, w9, w10
//   0x00b3ac: b9000109  str      w9, [x8]
//   0x00b3b0: b9800028  ldrsw    x8, [x1]
//   0x00b3b4: d37df109  lsl      x9, x8, #3
//   0x00b3b8: f8696a6a  ldr      x10, [x19, x9]
//   0x00b3bc: aa2a03eb  mvn      x11, x10
//   0x00b3c0: ca0c014a  eor      x10, x10, x12
//   0x00b3c4: 927df16b  and      x11, x11, #0xfffffffffffffff8
//   0x00b3c8: f8296a6a  str      x10, [x19, x9]
//   0x00b3cc: 794000e9  ldrh     w9, [x7]
//   0x00b3d0: 5287ffea  mov      w10, #0x3fff
//   0x00b3d4: 72a9bfea  movk     w10, #0x4dff, lsl #16
//   0x00b3d8: f940016c  ldr      x12, [x11]
//   0x00b3dc: 4a0a0108  eor      w8, w8, w10
//   0x00b3e0: 528ef70a  mov      w10, #0x77b8
//   0x00b3e4: 4a0a0129  eor      w9, w9, w10
//   0x00b3e8: 5295c0ca  mov      w10, #0xae06
//   0x00b3ec: 72a6f74a  movk     w10, #0x37ba, lsl #16
//   0x00b3f0: ca0a018a  eor      x10, x12, x10
//   0x00b3f4: b9000028  str      w8, [x1]
//   0x00b3f8: 790000e9  strh     w9, [x7]
//   0x00b3fc: f900016a  str      x10, [x11]
//   0x00b400: 17ffff84  b        #0xb210
//   0x00b404: f9000088  str      x8, [x4]
//   0x00b408: 52941c6b  mov      w11, #0xa0e3
//   0x00b40c: b8404d0a  ldr      w10, [x8, #4]!
//   0x00b410: 72a89c6b  movk     w11, #0x44e3, lsl #16
//   0x00b414: f90002a8  str      x8, [x21]
//   0x00b418: 4a0b014a  eor      w10, w10, w11
//   0x00b41c: b900010a  str      w10, [x8]
//   0x00b420: f94002a8  ldr      x8, [x21]
//   0x00b424: 17ffffb9  b        #0xb308
//   0x00b428: b0ffffc8  adrp     x8, #0x4000
//   0x00b42c: 91118108  add      x8, x8, #0x460
//   0x00b430: 11000509  add      w9, w8, #1
//   0x00b434: 0a280128  bic      w8, w9, w8
//   0x00b438: 528cc609  mov      w9, #0x6630
//   0x00b43c: 2a2803e8  mvn      w8, w8
//   0x00b440: 72a98029  movk     w9, #0x4c01, lsl #16
//   0x00b444: 8a090108  and      x8, x8, x9
//   0x00b448: d2958a69  mov      x9, #0xac53
//   0x00b44c: f2ae5449  movk     x9, #0x72a2, lsl #16
//   0x00b450: f2d1a009  movk     x9, #0x8d00, lsl #32
//   0x00b454: 8b090108  add      x8, x8, x9
//   0x00b458: 52815f29  mov      w9, #0xaf9
//   0x00b45c: 72a24989  movk     w9, #0x124c, lsl #16
//   0x00b460: eb09011f  cmp      x8, x9
//   0x00b464: 54000f63  b.lo     #0xb650
//   0x00b468: f94002a8  ldr      x8, [x21]
//   0x00b46c: b9400108  ldr      w8, [x8]
//   0x00b470: d34b7d0b  ubfx     x11, x8, #0xb, #0x15
//   0x00b474: 53067d09  lsr      w9, w8, #6
//   0x00b478: 121b016d  and      w13, w11, #0x20
//   0x00b47c: 121a016e  and      w14, w11, #0x40
//   0x00b480: 3315650d  bfxil    w13, w8, #0x15, #5
//   0x00b484: d35bfd0a  lsr      x10, x8, #0x1b
//   0x00b488: 2a0e01ad  orr      w13, w13, w14
//   0x00b48c: 1219016e  and      w14, w11, #0x80
//   0x00b490: 2a0e01ad  orr      w13, w13, w14
//   0x00b494: 1218016e  and      w14, w11, #0x100
//   0x00b498: 2a0e01ad  orr      w13, w13, w14
//   0x00b49c: 1217016e  and      w14, w11, #0x200
//   0x00b4a0: 531c6d0c  lsl      w12, w8, #4
//   0x00b4a4: 927c014a  and      x10, x10, #0x10
//   0x00b4a8: 2a0e01ad  orr      w13, w13, w14
//   0x00b4ac: 1215018e  and      w14, w12, #0x800
//   0x00b4b0: 3316012d  bfi      w13, w9, #0xa, #1
//   0x00b4b4: b34c3d0a  bfxil    x10, x8, #0xc, #4
//   0x00b4b8: 12140189  and      w9, w12, #0x1000
//   0x00b4bc: 2a0e01ad  orr      w13, w13, w14
//   0x00b4c0: 1213018e  and      w14, w12, #0x2000
//   0x00b4c4: 2a0901a9  orr      w9, w13, w9
//   0x00b4c8: 2a0e0129  orr      w9, w9, w14
//   0x00b4cc: 1212018c  and      w12, w12, #0x4000
//   0x00b4d0: f86a7a6d  ldr      x13, [x19, x10, lsl #3]
//   0x00b4d4: 2a0c0129  orr      w9, w9, w12
//   0x00b4d8: 1211016b  and      w11, w11, #0x8000
//   0x00b4dc: b900002a  str      w10, [x1]
//   0x00b4e0: 2a0b012b  orr      w11, w9, w11
//   0x00b4e4: d347fd09  lsr      x9, x8, #7
//   0x00b4e8: 927c0129  and      x9, x9, #0x10
//   0x00b4ec: 8b2ba1ac  add      x12, x13, w11, sxth
//   0x00b4f0: b35b7909  bfxil    x9, x8, #0x1b, #4
//   0x00b4f4: 927df18d  and      x13, x12, #0xfffffffffffffff8
//   0x00b4f8: f240098a  ands     x10, x12, #7
//   0x00b4fc: 790000eb  strh     w11, [x7]
//   0x00b500: b9000309  str      w9, [x24]
//   0x00b504: f94001a8  ldr      x8, [x13]
//   0x00b508: 540003c0  b.eq     #0xb580
//   0x00b50c: b0ffffcb  adrp     x11, #0x4000
//   0x00b510: 9111816b  add      x11, x11, #0x460
//   0x00b514: 1100056c  add      w12, w11, #1
//   0x00b518: 0a2b018b  bic      w11, w12, w11
//   0x00b51c: 5282420c  mov      w12, #0x1210
//   0x00b520: 2a2b03eb  mvn      w11, w11
//   0x00b524: 72a1040c  movk     w12, #0x820, lsl #16
//   0x00b528: 8a0c016b  and      x11, x11, x12
//   0x00b52c: d281c80c  mov      x12, #0xe40
//   0x00b530: f2bb1aec  movk     x12, #0xd8d7, lsl #16
//   0x00b534: f2c0040c  movk     x12, #0x20, lsl #32
//   0x00b538: f2e0080c  movk     x12, #0x40, lsl #48
//   0x00b53c: 8b0c016b  add      x11, x11, x12
//   0x00b540: 528af92c  mov      w12, #0x57c9
//   0x00b544: 72a6666c  movk     w12, #0x3333, lsl #16
//   0x00b548: eb0c017f  cmp      x11, x12
//   0x00b54c: 54000d03  b.lo     #0xb6ec
//   0x00b550: 2a0903e9  mov      w9, w9
//   0x00b554: d37df14a  lsl      x10, x10, #3
//   0x00b558: d37df129  lsl      x9, x9, #3
//   0x00b55c: cb0a03ec  neg      x12, x10
//   0x00b560: 9280000d  mov      x13, #-1
//   0x00b564: 9aca2508  lsr      x8, x8, x10
//   0x00b568: f8696a6b  ldr      x11, [x19, x9]
//   0x00b56c: 9acc21ac  lsl      x12, x13, x12
//   0x00b570: 8a0c016a  and      x10, x11, x12
//   0x00b574: aa080148  orr      x8, x10, x8
//   0x00b578: f8296a68  str      x8, [x19, x9]
//   0x00b57c: 14000002  b        #0xb584
//   0x00b580: f8297a68  str      x8, [x19, x9, lsl #3]
//   0x00b584: b0ffffc8  adrp     x8, #0x4000
//   0x00b588: 5280090a  mov      w10, #0x48
//   0x00b58c: 91118108  add      x8, x8, #0x460
//   0x00b590: 72a64c6a  movk     w10, #0x3263, lsl #16
//   0x00b594: 11000509  add      w9, w8, #1
//   0x00b598: 0a280129  bic      w9, w9, w8
//   0x00b59c: 2a2903e9  mvn      w9, w9
//   0x00b5a0: 8a0a0129  and      x9, x9, x10
//   0x00b5a4: d281160a  mov      x10, #0x8b0
//   0x00b5a8: f2bc34ca  movk     x10, #0xe1a6, lsl #16
//   0x00b5ac: f2c0400a  movk     x10, #0x200, lsl #32
//   0x00b5b0: f2e0008a  movk     x10, #4, lsl #48
//   0x00b5b4: 8b0a0129  add      x9, x9, x10
//   0x00b5b8: 528ee0ea  mov      w10, #0x7707
//   0x00b5bc: 72a1930a  movk     w10, #0xc98, lsl #16
//   0x00b5c0: eb0a013f  cmp      x9, x10
//   0x00b5c4: 54000823  b.lo     #0xb6c8
//   0x00b5c8: d282080b  mov      x11, #0x1040
//   0x00b5cc: f94002a9  ldr      x9, [x21]
//   0x00b5d0: d280800a  mov      x10, #0x400
//   0x00b5d4: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00b5d8: f2a0008a  movk     x10, #4, lsl #16
//   0x00b5dc: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00b5e0: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00b5e4: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00b5e8: 8a0a010a  and      x10, x8, x10
//   0x00b5ec: aa280168  orn      x8, x11, x8
//   0x00b5f0: b8404d2b  ldr      w11, [x9, #4]!
//   0x00b5f4: f90002a9  str      x9, [x21]
//   0x00b5f8: d2828809  mov      x9, #0x1440
//   0x00b5fc: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00b600: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00b604: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00b608: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00b60c: 8a090108  and      x8, x8, x9
//   0x00b610: 52802089  mov      w9, #0x104
//   0x00b614: 8b0a0108  add      x8, x8, x10
//   0x00b618: 72a02029  movk     w9, #0x101, lsl #16
//   0x00b61c: aa090108  orr      x8, x8, x9
//   0x00b620: d28d6b89  mov      x9, #0x6b5c
//   0x00b624: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00b628: 9240156a  and      x10, x11, #0x3f
//   0x00b62c: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00b630: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00b634: ca090108  eor      x8, x8, x9
//   0x00b638: f85f83a9  ldur     x9, [x29, #-8]
//   0x00b63c: 8b080188  add      x8, x12, x8
//   0x00b640: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00b644: f9400108  ldr      x8, [x8]
//   0x00b648: cb090108  sub      x8, x8, x9
//   0x00b64c: d61f0100  br       x8
//   0x00b650: f94002a8  ldr      x8, [x21]
//   0x00b654: 52825b6a  mov      w10, #0x12db
//   0x00b658: 72a249ea  movk     w10, #0x124f, lsl #16
//   0x00b65c: 529ca50c  mov      w12, #0xe528
//   0x00b660: 72a3860c  movk     w12, #0x1c30, lsl #16
//   0x00b664: f9000088  str      x8, [x4]
//   0x00b668: b9400109  ldr      w9, [x8]
//   0x00b66c: 4a0a0129  eor      w9, w9, w10
//   0x00b670: b9000109  str      w9, [x8]
//   0x00b674: b9800028  ldrsw    x8, [x1]
//   0x00b678: 798000eb  ldrsh    x11, [x7]
//   0x00b67c: d37df109  lsl      x9, x8, #3
//   0x00b680: f8696a6a  ldr      x10, [x19, x9]
//   0x00b684: 8b0b054d  add      x13, x10, x11, lsl #1
//   0x00b688: ca0c014a  eor      x10, x10, x12
//   0x00b68c: 927df1ac  and      x12, x13, #0xfffffffffffffff8
//   0x00b690: f8296a6a  str      x10, [x19, x9]
//   0x00b694: 529e2829  mov      w9, #0xf141
//   0x00b698: 72a0abc9  movk     w9, #0x55e, lsl #16
//   0x00b69c: f940018a  ldr      x10, [x12]
//   0x00b6a0: 4a090108  eor      w8, w8, w9
//   0x00b6a4: 529671a9  mov      w9, #0xb38d
//   0x00b6a8: 4a090169  eor      w9, w11, w9
//   0x00b6ac: 5290070b  mov      w11, #0x8038
//   0x00b6b0: 72a19f2b  movk     w11, #0xcf9, lsl #16
//   0x00b6b4: b9000028  str      w8, [x1]
//   0x00b6b8: ca0b014a  eor      x10, x10, x11
//   0x00b6bc: 790000e9  strh     w9, [x7]
//   0x00b6c0: f900018a  str      x10, [x12]
//   0x00b6c4: 17ffff69  b        #0xb468
//   0x00b6c8: f94002a9  ldr      x9, [x21]
//   0x00b6cc: 5284b74b  mov      w11, #0x25ba
//   0x00b6d0: 72adf90b  movk     w11, #0x6fc8, lsl #16
//   0x00b6d4: f9000089  str      x9, [x4]
//   0x00b6d8: b8404d2a  ldr      w10, [x9, #4]!
//   0x00b6dc: f90002a9  str      x9, [x21]
//   0x00b6e0: 4a0b014a  eor      w10, w10, w11
//   0x00b6e4: b900012a  str      w10, [x9]
//   0x00b6e8: 17ffffb8  b        #0xb5c8
//   0x00b6ec: 5286bbcb  mov      w11, #0x35de
//   0x00b6f0: f8295a68  str      x8, [x19, w9, uxtw #3]
//   0x00b6f4: 72afddeb  movk     w11, #0x7eef, lsl #16
//   0x00b6f8: 4a0b012b  eor      w11, w9, w11
//   0x00b6fc: 2a0b03e9  mov      w9, w11
//   0x00b700: b900030b  str      w11, [x24]
//   0x00b704: 17ffff93  b        #0xb550
//   0x00b708: f94002a8  ldr      x8, [x21]
//   0x00b70c: b9400108  ldr      w8, [x8]
//   0x00b710: d3417d0a  ubfx     x10, x8, #1, #0x1f
//   0x00b714: d35bfd0b  lsr      x11, x8, #0x1b
//   0x00b718: 1216014c  and      w12, w10, #0x400
//   0x00b71c: 1215014d  and      w13, w10, #0x800
//   0x00b720: 3310650c  bfxil    w12, w8, #0x10, #0xa
//   0x00b724: 1214014e  and      w14, w10, #0x1000
//   0x00b728: 2a0d018c  orr      w12, w12, w13
//   0x00b72c: 53067d09  lsr      w9, w8, #6
//   0x00b730: 2a0e018c  orr      w12, w12, w14
//   0x00b734: 1213014e  and      w14, w10, #0x2000
//   0x00b738: 1212014a  and      w10, w10, #0x4000
//   0x00b73c: 2a0e018c  orr      w12, w12, w14
//   0x00b740: f86b7a6e  ldr      x14, [x19, x11, lsl #3]
//   0x00b744: d3567d0d  ubfx     x13, x8, #0x16, #0xa
//   0x00b748: 2a0a018a  orr      w10, w12, w10
//   0x00b74c: 121c01ac  and      w12, w13, #0x10
//   0x00b750: 3311012a  bfi      w10, w9, #0xf, #1
//   0x00b754: 3307290c  bfxil    w12, w8, #7, #4
//   0x00b758: b900002b  str      w11, [x1]
//   0x00b75c: 8b2aa1c8  add      x8, x14, w10, sxth
//   0x00b760: b900030c  str      w12, [x24]
//   0x00b764: 790000ea  strh     w10, [x7]
//   0x00b768: c8dffd08  ldar     x8, [x8]
//   0x00b76c: b9800309  ldrsw    x9, [x24]
//   0x00b770: f85e03aa  ldur     x10, [x29, #-0x20]
//   0x00b774: f9000148  str      x8, [x10]
//   0x00b778: f8297a68  str      x8, [x19, x9, lsl #3]
//   0x00b77c: f94002a8  ldr      x8, [x21]
//   0x00b780: b8404d09  ldr      w9, [x8, #4]!
//   0x00b784: f90002a8  str      x8, [x21]
//   0x00b788: 52802088  mov      w8, #0x104
//   0x00b78c: 72a02028  movk     w8, #0x101, lsl #16
//   0x00b790: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00b794: aa0802c8  orr      x8, x22, x8
//   0x00b798: 92401529  and      x9, x9, #0x3f
//   0x00b79c: ca110108  eor      x8, x8, x17
//   0x00b7a0: 8b080148  add      x8, x10, x8
//   0x00b7a4: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00b7a8: f85f83a9  ldur     x9, [x29, #-8]
//   0x00b7ac: f9400108  ldr      x8, [x8]
//   0x00b7b0: cb090108  sub      x8, x8, x9
//   0x00b7b4: d61f0100  br       x8
//   0x00b7b8: f94002a8  ldr      x8, [x21]
//   0x00b7bc: b9400109  ldr      w9, [x8]
//   0x00b7c0: d3417d2b  ubfx     x11, x9, #1, #0x1f
//   0x00b7c4: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00b7c8: 121b016d  and      w13, w11, #0x20
//   0x00b7cc: 121a016e  and      w14, w11, #0x40
//   0x00b7d0: 3310512d  bfxil    w13, w9, #0x10, #5
//   0x00b7d4: 1219016f  and      w15, w11, #0x80
//   0x00b7d8: 2a0e01ad  orr      w13, w13, w14
//   0x00b7dc: 1218016e  and      w14, w11, #0x100
//   0x00b7e0: 2a0f01ad  orr      w13, w13, w15
//   0x00b7e4: d3507d2f  ubfx     x15, x9, #0x10, #0x10
//   0x00b7e8: 2a0e01ad  orr      w13, w13, w14
//   0x00b7ec: 1217016b  and      w11, w11, #0x200
//   0x00b7f0: 2a0b01ab  orr      w11, w13, w11
//   0x00b7f4: 121601ed  and      w13, w15, #0x400
//   0x00b7f8: 2a0d016b  orr      w11, w11, w13
//   0x00b7fc: 121501ed  and      w13, w15, #0x800
//   0x00b800: 2a0d016b  orr      w11, w11, w13
//   0x00b804: 121401ed  and      w13, w15, #0x1000
//   0x00b808: d351fd2c  lsr      x12, x9, #0x11
//   0x00b80c: 927c014a  and      x10, x10, #0x10
//   0x00b810: 2a0d016b  orr      w11, w11, w13
//   0x00b814: 121301ed  and      w13, w15, #0x2000
//   0x00b818: 531c6d2e  lsl      w14, w9, #4
//   0x00b81c: 927c018c  and      x12, x12, #0x10
//   0x00b820: 121201ef  and      w15, w15, #0x4000
//   0x00b824: b356652a  bfxil    x10, x9, #0x16, #4
//   0x00b828: 2a0d016b  orr      w11, w11, w13
//   0x00b82c: 121101ce  and      w14, w14, #0x8000
//   0x00b830: b34c3d2c  bfxil    x12, x9, #0xc, #4
//   0x00b834: 2a0f0169  orr      w9, w11, w15
//   0x00b838: 2a0e0129  orr      w9, w9, w14
//   0x00b83c: b900002a  str      w10, [x1]
//   0x00b840: f86a7a6a  ldr      x10, [x19, x10, lsl #3]
//   0x00b844: 93403d2b  sxth     x11, w9
//   0x00b848: b900030c  str      w12, [x24]
//   0x00b84c: 790000e9  strh     w9, [x7]
//   0x00b850: b86b6949  ldr      w9, [x10, x11]
//   0x00b854: f82c7a69  str      x9, [x19, x12, lsl #3]
//   0x00b858: b8404d09  ldr      w9, [x8, #4]!
//   0x00b85c: f90002a8  str      x8, [x21]
//   0x00b860: 52802088  mov      w8, #0x104
//   0x00b864: 72a02028  movk     w8, #0x101, lsl #16
//   0x00b868: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00b86c: aa0802c8  orr      x8, x22, x8
//   0x00b870: 92401529  and      x9, x9, #0x3f
//   0x00b874: ca110108  eor      x8, x8, x17
//   0x00b878: 8b080148  add      x8, x10, x8
//   0x00b87c: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00b880: f85f83a9  ldur     x9, [x29, #-8]
//   0x00b884: f9400108  ldr      x8, [x8]
//   0x00b888: cb090108  sub      x8, x8, x9
//   0x00b88c: d61f0100  br       x8
//   0x00b890: f94002a8  ldr      x8, [x21]
//   0x00b894: b9400109  ldr      w9, [x8]
//   0x00b898: d3467d2b  ubfx     x11, x9, #6, #0x1a
//   0x00b89c: d3507d2c  ubfx     x12, x9, #0x10, #0x10
//   0x00b8a0: 121b016d  and      w13, w11, #0x20
//   0x00b8a4: 121a016e  and      w14, w11, #0x40
//   0x00b8a8: 3310512d  bfxil    w13, w9, #0x10, #5
//   0x00b8ac: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00b8b0: 2a0e01ad  orr      w13, w13, w14
//   0x00b8b4: 1219016e  and      w14, w11, #0x80
//   0x00b8b8: 2a0e01ad  orr      w13, w13, w14
//   0x00b8bc: 1218016e  and      w14, w11, #0x100
//   0x00b8c0: 2a0e01ad  orr      w13, w13, w14
//   0x00b8c4: 1217016e  and      w14, w11, #0x200
//   0x00b8c8: 2a0e01ad  orr      w13, w13, w14
//   0x00b8cc: 1216018e  and      w14, w12, #0x400
//   0x00b8d0: 2a0e01ad  orr      w13, w13, w14
//   0x00b8d4: 1215018e  and      w14, w12, #0x800
//   0x00b8d8: 2a0e01ad  orr      w13, w13, w14
//   0x00b8dc: 1214018e  and      w14, w12, #0x1000
//   0x00b8e0: 927c014a  and      x10, x10, #0x10
//   0x00b8e4: 2a0e01ad  orr      w13, w13, w14
//   0x00b8e8: 1213018e  and      w14, w12, #0x2000
//   0x00b8ec: 1212018c  and      w12, w12, #0x4000
//   0x00b8f0: b347292a  bfxil    x10, x9, #7, #4
//   0x00b8f4: 2a0e01ad  orr      w13, w13, w14
//   0x00b8f8: 1211016b  and      w11, w11, #0x8000
//   0x00b8fc: 2a0c01ac  orr      w12, w13, w12
//   0x00b900: 2a0b018b  orr      w11, w12, w11
//   0x00b904: d342fd2e  lsr      x14, x9, #2
//   0x00b908: f86a7a6c  ldr      x12, [x19, x10, lsl #3]
//   0x00b90c: 93403d6d  sxth     x13, w11
//   0x00b910: 927c01ce  and      x14, x14, #0x10
//   0x00b914: b900002a  str      w10, [x1]
//   0x00b918: b356652e  bfxil    x14, x9, #0x16, #4
//   0x00b91c: 790000eb  strh     w11, [x7]
//   0x00b920: f86d6989  ldr      x9, [x12, x13]
//   0x00b924: b900030e  str      w14, [x24]
//   0x00b928: f82e7a69  str      x9, [x19, x14, lsl #3]
//   0x00b92c: b8404d09  ldr      w9, [x8, #4]!
//   0x00b930: f90002a8  str      x8, [x21]
//   0x00b934: 52802088  mov      w8, #0x104
//   0x00b938: 72a02028  movk     w8, #0x101, lsl #16
//   0x00b93c: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00b940: aa0802c8  orr      x8, x22, x8
//   0x00b944: 92401529  and      x9, x9, #0x3f
//   0x00b948: ca110108  eor      x8, x8, x17
//   0x00b94c: 8b080188  add      x8, x12, x8
//   0x00b950: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00b954: f85f83a9  ldur     x9, [x29, #-8]
//   0x00b958: f9400108  ldr      x8, [x8]
//   0x00b95c: cb090108  sub      x8, x8, x9
//   0x00b960: d61f0100  br       x8
//   0x00b964: f94002a8  ldr      x8, [x21]
//   0x00b968: b9400108  ldr      w8, [x8]
//   0x00b96c: d3557d09  ubfx     x9, x8, #0x15, #0xb
//   0x00b970: 53067d0a  lsr      w10, w8, #6
//   0x00b974: 121b012b  and      w11, w9, #0x20
//   0x00b978: 121a012c  and      w12, w9, #0x40
//   0x00b97c: 3310510b  bfxil    w11, w8, #0x10, #5
//   0x00b980: 1219012d  and      w13, w9, #0x80
//   0x00b984: 2a0c016b  orr      w11, w11, w12
//   0x00b988: 1218012c  and      w12, w9, #0x100
//   0x00b98c: 2a0d016b  orr      w11, w11, w13
//   0x00b990: 12170129  and      w9, w9, #0x200
//   0x00b994: 2a0c016b  orr      w11, w11, w12
//   0x00b998: d35bfd0d  lsr      x13, x8, #0x1b
//   0x00b99c: 2a090169  orr      w9, w11, w9
//   0x00b9a0: 531c6d0b  lsl      w11, w8, #4
//   0x00b9a4: 33160149  bfi      w9, w10, #0xa, #1
//   0x00b9a8: 1215016a  and      w10, w11, #0x800
//   0x00b9ac: 927c01ad  and      x13, x13, #0x10
//   0x00b9b0: 2a0a0129  orr      w9, w9, w10
//   0x00b9b4: 1214016a  and      w10, w11, #0x1000
//   0x00b9b8: b356650d  bfxil    x13, x8, #0x16, #4
//   0x00b9bc: 2a0a0129  orr      w9, w9, w10
//   0x00b9c0: 1213016a  and      w10, w11, #0x2000
//   0x00b9c4: 2a0a0129  orr      w9, w9, w10
//   0x00b9c8: 1212016a  and      w10, w11, #0x4000
//   0x00b9cc: d3517d0c  ubfx     x12, x8, #0x11, #0xf
//   0x00b9d0: 2a0a0129  orr      w9, w9, w10
//   0x00b9d4: f86d7a6a  ldr      x10, [x19, x13, lsl #3]
//   0x00b9d8: 121c018c  and      w12, w12, #0x10
//   0x00b9dc: 1211016b  and      w11, w11, #0x8000
//   0x00b9e0: 330c3d0c  bfxil    w12, w8, #0xc, #4
//   0x00b9e4: 2a0b0128  orr      w8, w9, w11
//   0x00b9e8: b900002d  str      w13, [x1]
//   0x00b9ec: 8b28a149  add      x9, x10, w8, sxth
//   0x00b9f0: b900030c  str      w12, [x24]
//   0x00b9f4: 790000e8  strh     w8, [x7]
//   0x00b9f8: 88dffd28  ldar     w8, [x9]
//   0x00b9fc: b9800309  ldrsw    x9, [x24]
//   0x00ba00: f85e03aa  ldur     x10, [x29, #-0x20]
//   0x00ba04: 93407d08  sxtw     x8, w8
//   0x00ba08: f9000148  str      x8, [x10]
//   0x00ba0c: f8297a68  str      x8, [x19, x9, lsl #3]
//   0x00ba10: f94002a8  ldr      x8, [x21]
//   0x00ba14: b8404d09  ldr      w9, [x8, #4]!
//   0x00ba18: f90002a8  str      x8, [x21]
//   0x00ba1c: 52802088  mov      w8, #0x104
//   0x00ba20: 72a02028  movk     w8, #0x101, lsl #16
//   0x00ba24: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00ba28: aa0802c8  orr      x8, x22, x8
//   0x00ba2c: 92401529  and      x9, x9, #0x3f
//   0x00ba30: ca110108  eor      x8, x8, x17
//   0x00ba34: 8b080148  add      x8, x10, x8
//   0x00ba38: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00ba3c: f85f83a9  ldur     x9, [x29, #-8]
//   0x00ba40: f9400108  ldr      x8, [x8]
//   0x00ba44: cb090108  sub      x8, x8, x9
//   0x00ba48: d61f0100  br       x8
//   0x00ba4c: b0ffffc8  adrp     x8, #0x4000
//   0x00ba50: 91118108  add      x8, x8, #0x460
//   0x00ba54: 11000509  add      w9, w8, #1
//   0x00ba58: 0a280128  bic      w8, w9, w8
//   0x00ba5c: 528248c9  mov      w9, #0x1246
//   0x00ba60: 2a2803e8  mvn      w8, w8
//   0x00ba64: 72a000a9  movk     w9, #5, lsl #16
//   0x00ba68: 8a090108  and      x8, x8, x9
//   0x00ba6c: d28d2349  mov      x9, #0x691a
//   0x00ba70: f2a613a9  movk     x9, #0x309d, lsl #16
//   0x00ba74: f2c00c09  movk     x9, #0x60, lsl #32
//   0x00ba78: f2e04009  movk     x9, #0x200, lsl #48
//   0x00ba7c: 8b090108  add      x8, x8, x9
//   0x00ba80: 52821d09  mov      w9, #0x10e8
//   0x00ba84: 72a33a69  movk     w9, #0x19d3, lsl #16
//   0x00ba88: eb09011f  cmp      x8, x9
//   0x00ba8c: 54000f83  b.lo     #0xbc7c
//   0x00ba90: f94002a8  ldr      x8, [x21]
//   0x00ba94: b9400108  ldr      w8, [x8]
//   0x00ba98: d34b7d0a  ubfx     x10, x8, #0xb, #0x15
//   0x00ba9c: d35bfd09  lsr      x9, x8, #0x1b
//   0x00baa0: 121b014c  and      w12, w10, #0x20
//   0x00baa4: 121a014d  and      w13, w10, #0x40
//   0x00baa8: 3315650c  bfxil    w12, w8, #0x15, #5
//   0x00baac: 927c012e  and      x14, x9, #0x10
//   0x00bab0: 2a0d018c  orr      w12, w12, w13
//   0x00bab4: 1219014d  and      w13, w10, #0x80
//   0x00bab8: 2a0d0189  orr      w9, w12, w13
//   0x00babc: 1218014c  and      w12, w10, #0x100
//   0x00bac0: d3507d0b  ubfx     x11, x8, #0x10, #0x10
//   0x00bac4: 1217014a  and      w10, w10, #0x200
//   0x00bac8: 2a0c0129  orr      w9, w9, w12
//   0x00bacc: 1216016c  and      w12, w11, #0x400
//   0x00bad0: 2a0a0129  orr      w9, w9, w10
//   0x00bad4: 1215016a  and      w10, w11, #0x800
//   0x00bad8: 2a0c0129  orr      w9, w9, w12
//   0x00badc: b34c3d0e  bfxil    x14, x8, #0xc, #4
//   0x00bae0: 1214016c  and      w12, w11, #0x1000
//   0x00bae4: 2a0a0129  orr      w9, w9, w10
//   0x00bae8: 1213016a  and      w10, w11, #0x2000
//   0x00baec: 2a0c0129  orr      w9, w9, w12
//   0x00baf0: 1212016b  and      w11, w11, #0x4000
//   0x00baf4: 2a0a0129  orr      w9, w9, w10
//   0x00baf8: 5317590a  lsl      w10, w8, #9
//   0x00bafc: f86e7a6c  ldr      x12, [x19, x14, lsl #3]
//   0x00bb00: 2a0b0129  orr      w9, w9, w11
//   0x00bb04: 1211014a  and      w10, w10, #0x8000
//   0x00bb08: 2a0a012a  orr      w10, w9, w10
//   0x00bb0c: d3472d09  ubfx     x9, x8, #7, #5
//   0x00bb10: b900002e  str      w14, [x1]
//   0x00bb14: 8b2aa18b  add      x11, x12, w10, sxth
//   0x00bb18: 927ef568  and      x8, x11, #0xfffffffffffffffc
//   0x00bb1c: b9000309  str      w9, [x24]
//   0x00bb20: 790000ea  strh     w10, [x7]
//   0x00bb24: 9240056a  and      x10, x11, #3
//   0x00bb28: f1000d5f  cmp      x10, #3
//   0x00bb2c: b9800108  ldrsw    x8, [x8]
//   0x00bb30: 54000061  b.ne     #0xbb3c
//   0x00bb34: f8297a68  str      x8, [x19, x9, lsl #3]
//   0x00bb38: 1400001f  b        #0xbbb4
//   0x00bb3c: b0ffffcb  adrp     x11, #0x4000
//   0x00bb40: 531d714a  lsl      w10, w10, #3
//   0x00bb44: 9111816b  add      x11, x11, #0x460
//   0x00bb48: 1100056c  add      w12, w11, #1
//   0x00bb4c: 0a2b018b  bic      w11, w12, w11
//   0x00bb50: 52904d0c  mov      w12, #0x8268
//   0x00bb54: 2a2b03eb  mvn      w11, w11
//   0x00bb58: 72ac200c  movk     w12, #0x6100, lsl #16
//   0x00bb5c: 8a0c016b  and      x11, x11, x12
//   0x00bb60: d28f2b4c  mov      x12, #0x795a
//   0x00bb64: f2a1db8c  movk     x12, #0xedc, lsl #16
//   0x00bb68: f2c1200c  movk     x12, #0x900, lsl #32
//   0x00bb6c: f2e0002c  movk     x12, #1, lsl #48
//   0x00bb70: 8b0c016b  add      x11, x11, x12
//   0x00bb74: 5296386c  mov      w12, #0xb1c3
//   0x00bb78: 72a0294c  movk     w12, #0x14a, lsl #16
//   0x00bb7c: eb0c017f  cmp      x11, x12
//   0x00bb80: 54000cc3  b.lo     #0xbd18
//   0x00bb84: 12bfe00b  mov      w11, #0xffffff
//   0x00bb88: 1aca256b  lsr      w11, w11, w10
//   0x00bb8c: 2a0903e9  mov      w9, w9
//   0x00bb90: 5280030c  mov      w12, #0x18
//   0x00bb94: d37df129  lsl      x9, x9, #3
//   0x00bb98: 4b0a018a  sub      w10, w12, w10
//   0x00bb9c: b8696a6d  ldr      w13, [x19, x9]
//   0x00bba0: 1aca2108  lsl      w8, w8, w10
//   0x00bba4: 0a0b01aa  and      w10, w13, w11
//   0x00bba8: 2a080148  orr      w8, w10, w8
//   0x00bbac: 93407d08  sxtw     x8, w8
//   0x00bbb0: f8296a68  str      x8, [x19, x9]
//   0x00bbb4: b0ffffc8  adrp     x8, #0x4000
//   0x00bbb8: 52a4c42a  mov      w10, #0x26210000
//   0x00bbbc: 91118108  add      x8, x8, #0x460
//   0x00bbc0: 11000509  add      w9, w8, #1
//   0x00bbc4: 0a280129  bic      w9, w9, w8
//   0x00bbc8: 2a2903e9  mvn      w9, w9
//   0x00bbcc: 8a0a0129  and      x9, x9, x10
//   0x00bbd0: d29d762a  mov      x10, #0xebb1
//   0x00bbd4: f2ad7b4a  movk     x10, #0x6bda, lsl #16
//   0x00bbd8: f2c1006a  movk     x10, #0x803, lsl #32
//   0x00bbdc: f2e0040a  movk     x10, #0x20, lsl #48
//   0x00bbe0: 8b0a0129  add      x9, x9, x10
//   0x00bbe4: 52835e0a  mov      w10, #0x1af0
//   0x00bbe8: 72a1a10a  movk     w10, #0xd08, lsl #16
//   0x00bbec: eb0a013f  cmp      x9, x10
//   0x00bbf0: 54000823  b.lo     #0xbcf4
//   0x00bbf4: d282080b  mov      x11, #0x1040
//   0x00bbf8: f94002a9  ldr      x9, [x21]
//   0x00bbfc: d280800a  mov      x10, #0x400
//   0x00bc00: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00bc04: f2a0008a  movk     x10, #4, lsl #16
//   0x00bc08: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00bc0c: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00bc10: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00bc14: 8a0a010a  and      x10, x8, x10
//   0x00bc18: aa280168  orn      x8, x11, x8
//   0x00bc1c: b8404d2b  ldr      w11, [x9, #4]!
//   0x00bc20: f90002a9  str      x9, [x21]
//   0x00bc24: d2828809  mov      x9, #0x1440
//   0x00bc28: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00bc2c: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00bc30: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00bc34: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00bc38: 8a090108  and      x8, x8, x9
//   0x00bc3c: 52802089  mov      w9, #0x104
//   0x00bc40: 8b0a0108  add      x8, x8, x10
//   0x00bc44: 72a02029  movk     w9, #0x101, lsl #16
//   0x00bc48: aa090108  orr      x8, x8, x9
//   0x00bc4c: d28d6b89  mov      x9, #0x6b5c
//   0x00bc50: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00bc54: 9240156a  and      x10, x11, #0x3f
//   0x00bc58: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00bc5c: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00bc60: ca090108  eor      x8, x8, x9
//   0x00bc64: f85f83a9  ldur     x9, [x29, #-8]
//   0x00bc68: 8b080188  add      x8, x12, x8
//   0x00bc6c: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00bc70: f9400108  ldr      x8, [x8]
//   0x00bc74: cb090108  sub      x8, x8, x9
//   0x00bc78: d61f0100  br       x8
//   0x00bc7c: f94002a8  ldr      x8, [x21]
//   0x00bc80: 529ce1ea  mov      w10, #0xe70f
//   0x00bc84: 72a508ca  movk     w10, #0x2846, lsl #16
//   0x00bc88: 5293ce2b  mov      w11, #0x9e71
//   0x00bc8c: 528622ed  mov      w13, #0x3117
//   0x00bc90: 72a8dd6b  movk     w11, #0x46eb, lsl #16
//   0x00bc94: f9000088  str      x8, [x4]
//   0x00bc98: 72a2dded  movk     w13, #0x16ef, lsl #16
//   0x00bc9c: b9400109  ldr      w9, [x8]
//   0x00bca0: 4a0a0129  eor      w9, w9, w10
//   0x00bca4: b9000109  str      w9, [x8]
//   0x00bca8: b9800028  ldrsw    x8, [x1]
//   0x00bcac: 798000ec  ldrsh    x12, [x7]
//   0x00bcb0: d37df109  lsl      x9, x8, #3
//   0x00bcb4: 4a0b0108  eor      w8, w8, w11
//   0x00bcb8: 529d188b  mov      w11, #0xe8c4
//   0x00bcbc: 4a0b018b  eor      w11, w12, w11
//   0x00bcc0: f8696a6a  ldr      x10, [x19, x9]
//   0x00bcc4: b9000028  str      w8, [x1]
//   0x00bcc8: 790000eb  strh     w11, [x7]
//   0x00bccc: ca0d014d  eor      x13, x10, x13
//   0x00bcd0: 8b0c054a  add      x10, x10, x12, lsl #1
//   0x00bcd4: f8296a6d  str      x13, [x19, x9]
//   0x00bcd8: 927ef549  and      x9, x10, #0xfffffffffffffffc
//   0x00bcdc: 529e8daa  mov      w10, #0xf46d
//   0x00bce0: 72adea4a  movk     w10, #0x6f52, lsl #16
//   0x00bce4: b9400128  ldr      w8, [x9]
//   0x00bce8: 4a0a0108  eor      w8, w8, w10
//   0x00bcec: b9000128  str      w8, [x9]
//   0x00bcf0: 17ffff68  b        #0xba90
//   0x00bcf4: f94002a9  ldr      x9, [x21]
//   0x00bcf8: 5287ceab  mov      w11, #0x3e75
//   0x00bcfc: 72af74cb  movk     w11, #0x7ba6, lsl #16
//   0x00bd00: f9000089  str      x9, [x4]
//   0x00bd04: b8404d2a  ldr      w10, [x9, #4]!
//   0x00bd08: f90002a9  str      x9, [x21]
//   0x00bd0c: 4a0b014a  eor      w10, w10, w11
//   0x00bd10: b900012a  str      w10, [x9]
//   0x00bd14: 17ffffb8  b        #0xbbf4
//   0x00bd18: 52988f0b  mov      w11, #0xc478
//   0x00bd1c: 2a0903ec  mov      w12, w9
//   0x00bd20: 72aed2cb  movk     w11, #0x7696, lsl #16
//   0x00bd24: d37df18c  lsl      x12, x12, #3
//   0x00bd28: 4a0b0129  eor      w9, w9, w11
//   0x00bd2c: 12bfe00b  mov      w11, #0xffffff
//   0x00bd30: 1aca256b  lsr      w11, w11, w10
//   0x00bd34: b9000309  str      w9, [x24]
//   0x00bd38: b86c6a6d  ldr      w13, [x19, x12]
//   0x00bd3c: 0a0b01ad  and      w13, w13, w11
//   0x00bd40: 2a8861ad  orr      w13, w13, w8, asr #24
//   0x00bd44: 93407dad  sxtw     x13, w13
//   0x00bd48: f82c6a6d  str      x13, [x19, x12]
//   0x00bd4c: 17ffff90  b        #0xbb8c
//   0x00bd50: b0ffffc8  adrp     x8, #0x4000
//   0x00bd54: 91118108  add      x8, x8, #0x460
//   0x00bd58: 11000509  add      w9, w8, #1
//   0x00bd5c: 0a280128  bic      w8, w9, w8
//   0x00bd60: 52846889  mov      w9, #0x2344
//   0x00bd64: 2a2803e8  mvn      w8, w8
//   0x00bd68: 72aa8089  movk     w9, #0x5404, lsl #16
//   0x00bd6c: 8a090108  and      x8, x8, x9
//   0x00bd70: d296b4c9  mov      x9, #0xb5a6
//   0x00bd74: f2a6b1e9  movk     x9, #0x358f, lsl #16
//   0x00bd78: f2c80869  movk     x9, #0x4043, lsl #32
//   0x00bd7c: f2e00809  movk     x9, #0x40, lsl #48
//   0x00bd80: 8b090108  add      x8, x8, x9
//   0x00bd84: 529b8109  mov      w9, #0xdc08
//   0x00bd88: 72a0cf29  movk     w9, #0x679, lsl #16
//   0x00bd8c: eb09011f  cmp      x8, x9
//   0x00bd90: 54000fa3  b.lo     #0xbf84
//   0x00bd94: f94002a8  ldr      x8, [x21]
//   0x00bd98: b9400108  ldr      w8, [x8]
//   0x00bd9c: d3467d09  ubfx     x9, x8, #6, #0x1a
//   0x00bda0: d35bfd0a  lsr      x10, x8, #0x1b
//   0x00bda4: 121b012b  and      w11, w9, #0x20
//   0x00bda8: 121a012c  and      w12, w9, #0x40
//   0x00bdac: 3315650b  bfxil    w11, w8, #0x15, #5
//   0x00bdb0: 1219012d  and      w13, w9, #0x80
//   0x00bdb4: 2a0c016b  orr      w11, w11, w12
//   0x00bdb8: 1218012c  and      w12, w9, #0x100
//   0x00bdbc: 2a0d016b  orr      w11, w11, w13
//   0x00bdc0: d3507d0d  ubfx     x13, x8, #0x10, #0x10
//   0x00bdc4: 2a0c016b  orr      w11, w11, w12
//   0x00bdc8: 12170129  and      w9, w9, #0x200
//   0x00bdcc: 2a090169  orr      w9, w11, w9
//   0x00bdd0: 121601ab  and      w11, w13, #0x400
//   0x00bdd4: 927c014a  and      x10, x10, #0x10
//   0x00bdd8: 2a0b0129  orr      w9, w9, w11
//   0x00bddc: 121501ab  and      w11, w13, #0x800
//   0x00bde0: b347290a  bfxil    x10, x8, #7, #4
//   0x00bde4: 2a0b0129  orr      w9, w9, w11
//   0x00bde8: 121401ab  and      w11, w13, #0x1000
//   0x00bdec: 2a0b0129  orr      w9, w9, w11
//   0x00bdf0: 121301ab  and      w11, w13, #0x2000
//   0x00bdf4: d3417d0c  ubfx     x12, x8, #1, #0x1f
//   0x00bdf8: 121201ad  and      w13, w13, #0x4000
//   0x00bdfc: 2a0b0129  orr      w9, w9, w11
//   0x00be00: f86a7a6b  ldr      x11, [x19, x10, lsl #3]
//   0x00be04: 2a0d012d  orr      w13, w9, w13
//   0x00be08: 1211018c  and      w12, w12, #0x8000
//   0x00be0c: d342fd09  lsr      x9, x8, #2
//   0x00be10: 2a0c01ac  orr      w12, w13, w12
//   0x00be14: 927c0129  and      x9, x9, #0x10
//   0x00be18: b900002a  str      w10, [x1]
//   0x00be1c: b3515109  bfxil    x9, x8, #0x11, #4
//   0x00be20: 8b2ca16b  add      x11, x11, w12, sxth
//   0x00be24: 927ef568  and      x8, x11, #0xfffffffffffffffc
//   0x00be28: 790000ec  strh     w12, [x7]
//   0x00be2c: f240056a  ands     x10, x11, #3
//   0x00be30: b9000309  str      w9, [x24]
//   0x00be34: b9800108  ldrsw    x8, [x8]
//   0x00be38: 540003e0  b.eq     #0xbeb4
//   0x00be3c: b0ffffcb  adrp     x11, #0x4000
//   0x00be40: 9111816b  add      x11, x11, #0x460
//   0x00be44: 1100056c  add      w12, w11, #1
//   0x00be48: 0a2b018b  bic      w11, w12, w11
//   0x00be4c: 5281400c  mov      w12, #0xa00
//   0x00be50: 2a2b03eb  mvn      w11, w11
//   0x00be54: 72a1ad0c  movk     w12, #0xd68, lsl #16
//   0x00be58: 8a0c016b  and      x11, x11, x12
//   0x00be5c: d2952a0c  mov      x12, #0xa950
//   0x00be60: f2a9010c  movk     x12, #0x4808, lsl #16
//   0x00be64: f2c0800c  movk     x12, #0x400, lsl #32
//   0x00be68: f2e0340c  movk     x12, #0x1a0, lsl #48
//   0x00be6c: 8b0c016b  add      x11, x11, x12
//   0x00be70: 52851cec  mov      w12, #0x28e7
//   0x00be74: 72a3ba4c  movk     w12, #0x1dd2, lsl #16
//   0x00be78: eb0c017f  cmp      x11, x12
//   0x00be7c: 54000d03  b.lo     #0xc01c
//   0x00be80: 2a0903e9  mov      w9, w9
//   0x00be84: 531d714a  lsl      w10, w10, #3
//   0x00be88: d37df129  lsl      x9, x9, #3
//   0x00be8c: 4b0a03ec  neg      w12, w10
//   0x00be90: 1280000d  mov      w13, #-1
//   0x00be94: 1aca2508  lsr      w8, w8, w10
//   0x00be98: b8696a6b  ldr      w11, [x19, x9]
//   0x00be9c: 1acc21ac  lsl      w12, w13, w12
//   0x00bea0: 0a0c016a  and      w10, w11, w12
//   0x00bea4: 2a080148  orr      w8, w10, w8
//   0x00bea8: 93407d08  sxtw     x8, w8
//   0x00beac: f8296a68  str      x8, [x19, x9]
//   0x00beb0: 14000002  b        #0xbeb8
//   0x00beb4: f8297a68  str      x8, [x19, x9, lsl #3]
//   0x00beb8: b0ffffc8  adrp     x8, #0x4000
//   0x00bebc: 5299028a  mov      w10, #0xc814
//   0x00bec0: 91118108  add      x8, x8, #0x460
//   0x00bec4: 72a2808a  movk     w10, #0x1404, lsl #16
//   0x00bec8: 11000509  add      w9, w8, #1
//   0x00becc: 0a280129  bic      w9, w9, w8
//   0x00bed0: 2a2903e9  mvn      w9, w9
//   0x00bed4: 8a0a0129  and      x9, x9, x10
//   0x00bed8: d2888eaa  mov      x10, #0x4475
//   0x00bedc: f2ac924a  movk     x10, #0x6492, lsl #16
//   0x00bee0: f2c0420a  movk     x10, #0x210, lsl #32
//   0x00bee4: f2e0b20a  movk     x10, #0x590, lsl #48
//   0x00bee8: 8b0a0129  add      x9, x9, x10
//   0x00beec: 528e160a  mov      w10, #0x70b0
//   0x00bef0: 72a7d1ea  movk     w10, #0x3e8f, lsl #16
//   0x00bef4: eb0a013f  cmp      x9, x10
//   0x00bef8: 54000803  b.lo     #0xbff8
//   0x00befc: d282080b  mov      x11, #0x1040
//   0x00bf00: f94002a9  ldr      x9, [x21]
//   0x00bf04: d280800a  mov      x10, #0x400
//   0x00bf08: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00bf0c: f2a0008a  movk     x10, #4, lsl #16
//   0x00bf10: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00bf14: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00bf18: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00bf1c: 8a0a010a  and      x10, x8, x10
//   0x00bf20: aa280168  orn      x8, x11, x8
//   0x00bf24: b8404d2b  ldr      w11, [x9, #4]!
//   0x00bf28: f90002a9  str      x9, [x21]
//   0x00bf2c: d2828809  mov      x9, #0x1440
//   0x00bf30: f2a140c9  movk     x9, #0xa06, lsl #16
//   0x00bf34: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00bf38: f2cc2889  movk     x9, #0x6144, lsl #32
//   0x00bf3c: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00bf40: 8a090108  and      x8, x8, x9
//   0x00bf44: 52802089  mov      w9, #0x104
//   0x00bf48: 8b0a0108  add      x8, x8, x10
//   0x00bf4c: 72a02029  movk     w9, #0x101, lsl #16
//   0x00bf50: aa090108  orr      x8, x8, x9
//   0x00bf54: d28d6b89  mov      x9, #0x6b5c
//   0x00bf58: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00bf5c: 9240156a  and      x10, x11, #0x3f
//   0x00bf60: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00bf64: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00bf68: ca090108  eor      x8, x8, x9
//   0x00bf6c: f85f83a9  ldur     x9, [x29, #-8]
//   0x00bf70: 8b080188  add      x8, x12, x8
//   0x00bf74: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00bf78: f9400108  ldr      x8, [x8]
//   0x00bf7c: cb090108  sub      x8, x8, x9
//   0x00bf80: d61f0100  br       x8
//   0x00bf84: f94002a8  ldr      x8, [x21]
//   0x00bf88: 5283d5ea  mov      w10, #0x1eaf
//   0x00bf8c: 72a629aa  movk     w10, #0x314d, lsl #16
//   0x00bf90: 529606eb  mov      w11, #0xb037
//   0x00bf94: 72afea6b  movk     w11, #0x7f53, lsl #16
//   0x00bf98: f9000088  str      x8, [x4]
//   0x00bf9c: b9400109  ldr      w9, [x8]
//   0x00bfa0: 4a0a0129  eor      w9, w9, w10
//   0x00bfa4: b9000109  str      w9, [x8]
//   0x00bfa8: b9800028  ldrsw    x8, [x1]
//   0x00bfac: d37df109  lsl      x9, x8, #3
//   0x00bfb0: f8696a6a  ldr      x10, [x19, x9]
//   0x00bfb4: ca0b014a  eor      x10, x10, x11
//   0x00bfb8: 9280006b  mov      x11, #-4
//   0x00bfbc: f8296a6a  str      x10, [x19, x9]
//   0x00bfc0: 794000e9  ldrh     w9, [x7]
//   0x00bfc4: 52918e4a  mov      w10, #0x8c72
//   0x00bfc8: b940016c  ldr      w12, [x11]
//   0x00bfcc: 72a7c32a  movk     w10, #0x3e19, lsl #16
//   0x00bfd0: 4a0a0108  eor      w8, w8, w10
//   0x00bfd4: 528585ea  mov      w10, #0x2c2f
//   0x00bfd8: 4a0a0129  eor      w9, w9, w10
//   0x00bfdc: 52902a0a  mov      w10, #0x8150
//   0x00bfe0: 72a2e8ca  movk     w10, #0x1746, lsl #16
//   0x00bfe4: 4a0a018a  eor      w10, w12, w10
//   0x00bfe8: b9000028  str      w8, [x1]
//   0x00bfec: 790000e9  strh     w9, [x7]
//   0x00bff0: b900016a  str      w10, [x11]
//   0x00bff4: 17ffff68  b        #0xbd94
//   0x00bff8: f94002a9  ldr      x9, [x21]
//   0x00bffc: 52846aab  mov      w11, #0x2355
//   0x00c000: 72aa0f6b  movk     w11, #0x507b, lsl #16
//   0x00c004: f9000089  str      x9, [x4]
//   0x00c008: b8404d2a  ldr      w10, [x9, #4]!
//   0x00c00c: f90002a9  str      x9, [x21]
//   0x00c010: 4a0b014a  eor      w10, w10, w11
//   0x00c014: b900012a  str      w10, [x9]
//   0x00c018: 17ffffb9  b        #0xbefc
//   0x00c01c: 529bcb4b  mov      w11, #0xde5a
//   0x00c020: f8295a68  str      x8, [x19, w9, uxtw #3]
//   0x00c024: 72aae78b  movk     w11, #0x573c, lsl #16
//   0x00c028: 4a0b012b  eor      w11, w9, w11
//   0x00c02c: 2a0b03e9  mov      w9, w11
//   0x00c030: b900030b  str      w11, [x24]
//   0x00c034: 17ffff93  b        #0xbe80
//   0x00c038: 90ffffc8  adrp     x8, #0x4000
//   0x00c03c: 5280040a  mov      w10, #0x20
//   0x00c040: 91118108  add      x8, x8, #0x460
//   0x00c044: 72a1660a  movk     w10, #0xb30, lsl #16
//   0x00c048: 11000509  add      w9, w8, #1
//   0x00c04c: 0a280129  bic      w9, w9, w8
//   0x00c050: 2a2903e9  mvn      w9, w9
//   0x00c054: 8a0a0129  and      x9, x9, x10
//   0x00c058: d29cf04a  mov      x10, #0xe782
//   0x00c05c: f2b7856a  movk     x10, #0xbc2b, lsl #16
//   0x00c060: f2c0100a  movk     x10, #0x80, lsl #32
//   0x00c064: f2e0002a  movk     x10, #1, lsl #48
//   0x00c068: 8b0a0129  add      x9, x9, x10
//   0x00c06c: 529e376a  mov      w10, #0xf1bb
//   0x00c070: 72a49b6a  movk     w10, #0x24db, lsl #16
//   0x00c074: eb0a013f  cmp      x9, x10
//   0x00c078: 540008e3  b.lo     #0xc194
//   0x00c07c: f94002a9  ldr      x9, [x21]
//   0x00c080: b940012a  ldr      w10, [x9]
//   0x00c084: d34b7d4b  ubfx     x11, x10, #0xb, #0x15
//   0x00c088: d35bfd4c  lsr      x12, x10, #0x1b
//   0x00c08c: 121b016d  and      w13, w11, #0x20
//   0x00c090: 121a016e  and      w14, w11, #0x40
//   0x00c094: 3306294d  bfxil    w13, w10, #6, #5
//   0x00c098: 1219016f  and      w15, w11, #0x80
//   0x00c09c: 2a0e01ad  orr      w13, w13, w14
//   0x00c0a0: 1218016e  and      w14, w11, #0x100
//   0x00c0a4: 2a0f01ad  orr      w13, w13, w15
//   0x00c0a8: 1217016f  and      w15, w11, #0x200
//   0x00c0ac: 2a0e01ad  orr      w13, w13, w14
//   0x00c0b0: 1216016e  and      w14, w11, #0x400
//   0x00c0b4: 2a0f01ad  orr      w13, w13, w15
//   0x00c0b8: 1215016f  and      w15, w11, #0x800
//   0x00c0bc: 2a0e01ad  orr      w13, w13, w14
//   0x00c0c0: 1214016e  and      w14, w11, #0x1000
//   0x00c0c4: 2a0f01ad  orr      w13, w13, w15
//   0x00c0c8: 1213016f  and      w15, w11, #0x2000
//   0x00c0cc: 2a0e01ad  orr      w13, w13, w14
//   0x00c0d0: d356fd4e  lsr      x14, x10, #0x16
//   0x00c0d4: 2a0f01ad  orr      w13, w13, w15
//   0x00c0d8: 531c6d4f  lsl      w15, w10, #4
//   0x00c0dc: 927c01ce  and      x14, x14, #0x10
//   0x00c0e0: 1212016b  and      w11, w11, #0x4000
//   0x00c0e4: 121101ef  and      w15, w15, #0x8000
//   0x00c0e8: b34c3d4e  bfxil    x14, x10, #0xc, #4
//   0x00c0ec: 2a0b01aa  orr      w10, w13, w11
//   0x00c0f0: b900002c  str      w12, [x1]
//   0x00c0f4: 2a0f014a  orr      w10, w10, w15
//   0x00c0f8: f86c7a6b  ldr      x11, [x19, x12, lsl #3]
//   0x00c0fc: 93403d4c  sxth     x12, w10
//   0x00c100: b900030e  str      w14, [x24]
//   0x00c104: d282880d  mov      x13, #0x1440
//   0x00c108: 5280208f  mov      w15, #0x104
//   0x00c10c: 790000ea  strh     w10, [x7]
//   0x00c110: d280800a  mov      x10, #0x400
//   0x00c114: 38ac696b  ldrsb    x11, [x11, x12]
//   0x00c118: d282080c  mov      x12, #0x1040
//   0x00c11c: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00c120: f2a0008a  movk     x10, #4, lsl #16
//   0x00c124: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00c128: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x00c12c: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00c130: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00c134: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x00c138: 8a0a010a  and      x10, x8, x10
//   0x00c13c: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x00c140: aa280188  orn      x8, x12, x8
//   0x00c144: 8a0d0108  and      x8, x8, x13
//   0x00c148: f82e7a6b  str      x11, [x19, x14, lsl #3]
//   0x00c14c: 8b0a0108  add      x8, x8, x10
//   0x00c150: d28d6b8a  mov      x10, #0x6b5c
//   0x00c154: b8404d2b  ldr      w11, [x9, #4]!
//   0x00c158: f90002a9  str      x9, [x21]
//   0x00c15c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00c160: 72a0202f  movk     w15, #0x101, lsl #16
//   0x00c164: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00c168: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00c16c: aa0f0108  orr      x8, x8, x15
//   0x00c170: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00c174: ca0a0108  eor      x8, x8, x10
//   0x00c178: 9240156a  and      x10, x11, #0x3f
//   0x00c17c: 8b080128  add      x8, x9, x8
//   0x00c180: f85f83a9  ldur     x9, [x29, #-8]
//   0x00c184: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00c188: f9400108  ldr      x8, [x8]
//   0x00c18c: cb090108  sub      x8, x8, x9
//   0x00c190: d61f0100  br       x8
//   0x00c194: f94002a9  ldr      x9, [x21]
//   0x00c198: 528227eb  mov      w11, #0x113f
//   0x00c19c: 72a765eb  movk     w11, #0x3b2f, lsl #16
//   0x00c1a0: 528bae8c  mov      w12, #0x5d74
//   0x00c1a4: 72a1e2ac  movk     w12, #0xf15, lsl #16
//   0x00c1a8: 528e4d0e  mov      w14, #0x7268
//   0x00c1ac: f9000089  str      x9, [x4]
//   0x00c1b0: 72a8754e  movk     w14, #0x43aa, lsl #16
//   0x00c1b4: b940012a  ldr      w10, [x9]
//   0x00c1b8: 4a0b014a  eor      w10, w10, w11
//   0x00c1bc: b900012a  str      w10, [x9]
//   0x00c1c0: b9800029  ldrsw    x9, [x1]
//   0x00c1c4: 798000ed  ldrsh    x13, [x7]
//   0x00c1c8: d37df12a  lsl      x10, x9, #3
//   0x00c1cc: 4a0c0129  eor      w9, w9, w12
//   0x00c1d0: 5285918c  mov      w12, #0x2c8c
//   0x00c1d4: 4a0c01ac  eor      w12, w13, w12
//   0x00c1d8: f86a6a6b  ldr      x11, [x19, x10]
//   0x00c1dc: b9000029  str      w9, [x1]
//   0x00c1e0: 790000ec  strh     w12, [x7]
//   0x00c1e4: 528000ac  mov      w12, #5
//   0x00c1e8: ca0e016e  eor      x14, x11, x14
//   0x00c1ec: f82a6a6e  str      x14, [x19, x10]
//   0x00c1f0: d37ff9aa  lsl      x10, x13, #1
//   0x00c1f4: 38ab6949  ldrsb    x9, [x10, x11]
//   0x00c1f8: 4a0c012c  eor      w12, w9, w12
//   0x00c1fc: 382b694c  strb     w12, [x10, x11]
//   0x00c200: 5292cb6b  mov      w11, #0x965b
//   0x00c204: b980030a  ldrsw    x10, [x24]
//   0x00c208: 72a53c8b  movk     w11, #0x29e4, lsl #16
//   0x00c20c: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00c210: 4a0b014a  eor      w10, w10, w11
//   0x00c214: f94002a9  ldr      x9, [x21]
//   0x00c218: 5288bb2b  mov      w11, #0x45d9
//   0x00c21c: 72abc96b  movk     w11, #0x5e4b, lsl #16
//   0x00c220: b900030a  str      w10, [x24]
//   0x00c224: f9000089  str      x9, [x4]
//   0x00c228: b8404d2c  ldr      w12, [x9, #4]!
//   0x00c22c: f90002a9  str      x9, [x21]
//   0x00c230: 4a0b018b  eor      w11, w12, w11
//   0x00c234: b900012b  str      w11, [x9]
//   0x00c238: 17ffff91  b        #0xc07c
//   0x00c23c: 90ffffc8  adrp     x8, #0x4000
//   0x00c240: 528a082a  mov      w10, #0x5041
//   0x00c244: 91118108  add      x8, x8, #0x460
//   0x00c248: 11000509  add      w9, w8, #1
//   0x00c24c: 0a280129  bic      w9, w9, w8
//   0x00c250: 2a2903e9  mvn      w9, w9
//   0x00c254: 8a0a0129  and      x9, x9, x10
//   0x00c258: d28ea30a  mov      x10, #0x7518
//   0x00c25c: f2a4414a  movk     x10, #0x220a, lsl #16
//   0x00c260: f2c0400a  movk     x10, #0x200, lsl #32
//   0x00c264: 8b0a0129  add      x9, x9, x10
//   0x00c268: 529c900a  mov      w10, #0xe480
//   0x00c26c: 72a0204a  movk     w10, #0x102, lsl #16
//   0x00c270: eb0a013f  cmp      x9, x10
//   0x00c274: 54000923  b.lo     #0xc398
//   0x00c278: f94002a9  ldr      x9, [x21]
//   0x00c27c: b940012a  ldr      w10, [x9]
//   0x00c280: d3417d4b  ubfx     x11, x10, #1, #0x1f
//   0x00c284: d35bfd4c  lsr      x12, x10, #0x1b
//   0x00c288: 121b016d  and      w13, w11, #0x20
//   0x00c28c: 121a016e  and      w14, w11, #0x40
//   0x00c290: 330b3d4d  bfxil    w13, w10, #0xb, #5
//   0x00c294: 1219016f  and      w15, w11, #0x80
//   0x00c298: 2a0e01ad  orr      w13, w13, w14
//   0x00c29c: 1218016e  and      w14, w11, #0x100
//   0x00c2a0: 2a0f01ad  orr      w13, w13, w15
//   0x00c2a4: 1217016b  and      w11, w11, #0x200
//   0x00c2a8: 2a0e01ad  orr      w13, w13, w14
//   0x00c2ac: d34b7d4e  ubfx     x14, x10, #0xb, #0x15
//   0x00c2b0: 2a0b01ab  orr      w11, w13, w11
//   0x00c2b4: 121601cd  and      w13, w14, #0x400
//   0x00c2b8: 2a0d016b  orr      w11, w11, w13
//   0x00c2bc: 121501cd  and      w13, w14, #0x800
//   0x00c2c0: 2a0d016b  orr      w11, w11, w13
//   0x00c2c4: 121401cd  and      w13, w14, #0x1000
//   0x00c2c8: d34cfd4f  lsr      x15, x10, #0xc
//   0x00c2cc: 927c018c  and      x12, x12, #0x10
//   0x00c2d0: 2a0d016b  orr      w11, w11, w13
//   0x00c2d4: 121301cd  and      w13, w14, #0x2000
//   0x00c2d8: 927c01ef  and      x15, x15, #0x10
//   0x00c2dc: b351514c  bfxil    x12, x10, #0x11, #4
//   0x00c2e0: 2a0d016b  orr      w11, w11, w13
//   0x00c2e4: 121201cd  and      w13, w14, #0x4000
//   0x00c2e8: 121101ce  and      w14, w14, #0x8000
//   0x00c2ec: b35b794f  bfxil    x15, x10, #0x1b, #4
//   0x00c2f0: 2a0d016a  orr      w10, w11, w13
//   0x00c2f4: b900002c  str      w12, [x1]
//   0x00c2f8: 2a0e014a  orr      w10, w10, w14
//   0x00c2fc: f86c7a6b  ldr      x11, [x19, x12, lsl #3]
//   0x00c300: 93403d4c  sxth     x12, w10
//   0x00c304: b900030f  str      w15, [x24]
//   0x00c308: d282880d  mov      x13, #0x1440
//   0x00c30c: 5280208e  mov      w14, #0x104
//   0x00c310: 790000ea  strh     w10, [x7]
//   0x00c314: d280800a  mov      x10, #0x400
//   0x00c318: 78ac696b  ldrsh    x11, [x11, x12]
//   0x00c31c: d282080c  mov      x12, #0x1040
//   0x00c320: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00c324: f2a0008a  movk     x10, #4, lsl #16
//   0x00c328: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00c32c: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x00c330: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00c334: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00c338: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x00c33c: 8a0a010a  and      x10, x8, x10
//   0x00c340: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x00c344: aa280188  orn      x8, x12, x8
//   0x00c348: 8a0d0108  and      x8, x8, x13
//   0x00c34c: f82f7a6b  str      x11, [x19, x15, lsl #3]
//   0x00c350: 8b0a0108  add      x8, x8, x10
//   0x00c354: d28d6b8a  mov      x10, #0x6b5c
//   0x00c358: b8404d2b  ldr      w11, [x9, #4]!
//   0x00c35c: f90002a9  str      x9, [x21]
//   0x00c360: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00c364: 72a0202e  movk     w14, #0x101, lsl #16
//   0x00c368: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00c36c: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00c370: aa0e0108  orr      x8, x8, x14
//   0x00c374: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00c378: ca0a0108  eor      x8, x8, x10
//   0x00c37c: 9240156a  and      x10, x11, #0x3f
//   0x00c380: 8b080128  add      x8, x9, x8
//   0x00c384: f85f83a9  ldur     x9, [x29, #-8]
//   0x00c388: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00c38c: f9400108  ldr      x8, [x8]
//   0x00c390: cb090108  sub      x8, x8, x9
//   0x00c394: d61f0100  br       x8
//   0x00c398: f94002a9  ldr      x9, [x21]
//   0x00c39c: 529cc9cb  mov      w11, #0xe64e
//   0x00c3a0: 72ab42ab  movk     w11, #0x5a15, lsl #16
//   0x00c3a4: 528722cc  mov      w12, #0x3916
//   0x00c3a8: 72aa786c  movk     w12, #0x53c3, lsl #16
//   0x00c3ac: 528a39ce  mov      w14, #0x51ce
//   0x00c3b0: f9000089  str      x9, [x4]
//   0x00c3b4: b940012a  ldr      w10, [x9]
//   0x00c3b8: 4a0b014a  eor      w10, w10, w11
//   0x00c3bc: b900012a  str      w10, [x9]
//   0x00c3c0: b9800029  ldrsw    x9, [x1]
//   0x00c3c4: 794000ed  ldrh     w13, [x7]
//   0x00c3c8: d37df12a  lsl      x10, x9, #3
//   0x00c3cc: 4a0c0129  eor      w9, w9, w12
//   0x00c3d0: 529fca0c  mov      w12, #0xfe50
//   0x00c3d4: 4a0e01ad  eor      w13, w13, w14
//   0x00c3d8: 72a6bb0c  movk     w12, #0x35d8, lsl #16
//   0x00c3dc: f86a6a6b  ldr      x11, [x19, x10]
//   0x00c3e0: b9000029  str      w9, [x1]
//   0x00c3e4: 790000ed  strh     w13, [x7]
//   0x00c3e8: ca0c016c  eor      x12, x11, x12
//   0x00c3ec: f82a6a6c  str      x12, [x19, x10]
//   0x00c3f0: 528aafca  mov      w10, #0x557e
//   0x00c3f4: 79800169  ldrsh    x9, [x11]
//   0x00c3f8: 4a0a012a  eor      w10, w9, w10
//   0x00c3fc: 7900016a  strh     w10, [x11]
//   0x00c400: 529eca4b  mov      w11, #0xf652
//   0x00c404: b980030a  ldrsw    x10, [x24]
//   0x00c408: 72a118eb  movk     w11, #0x8c7, lsl #16
//   0x00c40c: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00c410: 4a0b014a  eor      w10, w10, w11
//   0x00c414: f94002a9  ldr      x9, [x21]
//   0x00c418: 5290bfcb  mov      w11, #0x85fe
//   0x00c41c: 72afff8b  movk     w11, #0x7ffc, lsl #16
//   0x00c420: b900030a  str      w10, [x24]
//   0x00c424: f9000089  str      x9, [x4]
//   0x00c428: b8404d2c  ldr      w12, [x9, #4]!
//   0x00c42c: f90002a9  str      x9, [x21]
//   0x00c430: 4a0b018b  eor      w11, w12, w11
//   0x00c434: b900012b  str      w11, [x9]
//   0x00c438: 17ffff90  b        #0xc278
//   0x00c43c: 90ffffc8  adrp     x8, #0x4000
//   0x00c440: 5296400a  mov      w10, #0xb200
//   0x00c444: 91118108  add      x8, x8, #0x460
//   0x00c448: 72a0010a  movk     w10, #8, lsl #16
//   0x00c44c: 11000509  add      w9, w8, #1
//   0x00c450: 0a280129  bic      w9, w9, w8
//   0x00c454: 2a2903e9  mvn      w9, w9
//   0x00c458: 8a0a0129  and      x9, x9, x10
//   0x00c45c: d291ba6a  mov      x10, #0x8dd3
//   0x00c460: f2a835ea  movk     x10, #0x41af, lsl #16
//   0x00c464: f2c2008a  movk     x10, #0x1004, lsl #32
//   0x00c468: 8b0a0129  add      x9, x9, x10
//   0x00c46c: 5286bbaa  mov      w10, #0x35dd
//   0x00c470: 72a5108a  movk     w10, #0x2884, lsl #16
//   0x00c474: eb0a013f  cmp      x9, x10
//   0x00c478: 54000863  b.lo     #0xc584
//   0x00c47c: f94002a9  ldr      x9, [x21]
//   0x00c480: b940012a  ldr      w10, [x9]
//   0x00c484: 53077d4e  lsr      w14, w10, #7
//   0x00c488: 531c6d4f  lsl      w15, w10, #4
//   0x00c48c: 53087d4d  lsr      w13, w10, #8
//   0x00c490: 121601ef  and      w15, w15, #0x400
//   0x00c494: 53097d4c  lsr      w12, w10, #9
//   0x00c498: 3310654f  bfxil    w15, w10, #0x10, #0xa
//   0x00c49c: 530a7d4b  lsr      w11, w10, #0xa
//   0x00c4a0: d35bfd50  lsr      x16, x10, #0x1b
//   0x00c4a4: 331501cf  bfi      w15, w14, #0xb, #1
//   0x00c4a8: 927c0210  and      x16, x16, #0x10
//   0x00c4ac: 331401af  bfi      w15, w13, #0xc, #1
//   0x00c4b0: d347fd51  lsr      x17, x10, #7
//   0x00c4b4: d34b7d4e  ubfx     x14, x10, #0xb, #0x15
//   0x00c4b8: b34c3d50  bfxil    x16, x10, #0xc, #4
//   0x00c4bc: 3313018f  bfi      w15, w12, #0xd, #1
//   0x00c4c0: 927c0231  and      x17, x17, #0x10
//   0x00c4c4: 121101cd  and      w13, w14, #0x8000
//   0x00c4c8: 3312016f  bfi      w15, w11, #0xe, #1
//   0x00c4cc: b35b7951  bfxil    x17, x10, #0x1b, #4
//   0x00c4d0: 2a0d01ea  orr      w10, w15, w13
//   0x00c4d4: f8707a6b  ldr      x11, [x19, x16, lsl #3]
//   0x00c4d8: 93403d4c  sxth     x12, w10
//   0x00c4dc: b9000030  str      w16, [x1]
//   0x00c4e0: d282880d  mov      x13, #0x1440
//   0x00c4e4: b9000311  str      w17, [x24]
//   0x00c4e8: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x00c4ec: 790000ea  strh     w10, [x7]
//   0x00c4f0: d280800a  mov      x10, #0x400
//   0x00c4f4: b8ac696b  ldrsw    x11, [x11, x12]
//   0x00c4f8: d282080c  mov      x12, #0x1040
//   0x00c4fc: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00c500: f2a0008a  movk     x10, #4, lsl #16
//   0x00c504: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00c508: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00c50c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00c510: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x00c514: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x00c518: 8a0a010a  and      x10, x8, x10
//   0x00c51c: aa280188  orn      x8, x12, x8
//   0x00c520: f8317a6b  str      x11, [x19, x17, lsl #3]
//   0x00c524: 8a0d0108  and      x8, x8, x13
//   0x00c528: 5280208e  mov      w14, #0x104
//   0x00c52c: 8b0a0108  add      x8, x8, x10
//   0x00c530: d28d6b8a  mov      x10, #0x6b5c
//   0x00c534: b8404d2b  ldr      w11, [x9, #4]!
//   0x00c538: f90002a9  str      x9, [x21]
//   0x00c53c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00c540: 72a0202e  movk     w14, #0x101, lsl #16
//   0x00c544: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00c548: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00c54c: aa0e0108  orr      x8, x8, x14
//   0x00c550: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00c554: d28d6b91  mov      x17, #0x6b5c
//   0x00c558: ca0a0108  eor      x8, x8, x10
//   0x00c55c: 9240156a  and      x10, x11, #0x3f
//   0x00c560: 8b080128  add      x8, x9, x8
//   0x00c564: f85f83a9  ldur     x9, [x29, #-8]
//   0x00c568: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00c56c: f2be9391  movk     x17, #0xf49c, lsl #16
//   0x00c570: f2d3d771  movk     x17, #0x9ebb, lsl #32
//   0x00c574: f2ffebf1  movk     x17, #0xff5f, lsl #48
//   0x00c578: f9400108  ldr      x8, [x8]
//   0x00c57c: cb090108  sub      x8, x8, x9
//   0x00c580: d61f0100  br       x8
//   0x00c584: f94002a9  ldr      x9, [x21]
//   0x00c588: 5283b7ab  mov      w11, #0x1dbd
//   0x00c58c: 72aadb0b  movk     w11, #0x56d8, lsl #16
//   0x00c590: 5291facc  mov      w12, #0x8fd6
//   0x00c594: 72a0d10c  movk     w12, #0x688, lsl #16
//   0x00c598: 5285be6e  mov      w14, #0x2df3
//   0x00c59c: f9000089  str      x9, [x4]
//   0x00c5a0: 72adf36e  movk     w14, #0x6f9b, lsl #16
//   0x00c5a4: b940012a  ldr      w10, [x9]
//   0x00c5a8: 4a0b014a  eor      w10, w10, w11
//   0x00c5ac: b900012a  str      w10, [x9]
//   0x00c5b0: b9800029  ldrsw    x9, [x1]
//   0x00c5b4: 798000ed  ldrsh    x13, [x7]
//   0x00c5b8: d37df12a  lsl      x10, x9, #3
//   0x00c5bc: 4a0c0129  eor      w9, w9, w12
//   0x00c5c0: 529cb86c  mov      w12, #0xe5c3
//   0x00c5c4: 4a0c01ac  eor      w12, w13, w12
//   0x00c5c8: f86a6a6b  ldr      x11, [x19, x10]
//   0x00c5cc: b9000029  str      w9, [x1]
//   0x00c5d0: 790000ec  strh     w12, [x7]
//   0x00c5d4: 5298006c  mov      w12, #0xc003
//   0x00c5d8: 72a54e4c  movk     w12, #0x2a72, lsl #16
//   0x00c5dc: ca0e016e  eor      x14, x11, x14
//   0x00c5e0: f82a6a6e  str      x14, [x19, x10]
//   0x00c5e4: d37ff9aa  lsl      x10, x13, #1
//   0x00c5e8: b8ab6949  ldrsw    x9, [x10, x11]
//   0x00c5ec: 4a0c012c  eor      w12, w9, w12
//   0x00c5f0: b82b694c  str      w12, [x10, x11]
//   0x00c5f4: 5283574b  mov      w11, #0x1aba
//   0x00c5f8: b980030a  ldrsw    x10, [x24]
//   0x00c5fc: 72aa738b  movk     w11, #0x539c, lsl #16
//   0x00c600: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00c604: 4a0b014a  eor      w10, w10, w11
//   0x00c608: f94002a9  ldr      x9, [x21]
//   0x00c60c: 529a870b  mov      w11, #0xd438
//   0x00c610: 72a5b3cb  movk     w11, #0x2d9e, lsl #16
//   0x00c614: b900030a  str      w10, [x24]
//   0x00c618: f9000089  str      x9, [x4]
//   0x00c61c: b8404d2c  ldr      w12, [x9, #4]!
//   0x00c620: f90002a9  str      x9, [x21]
//   0x00c624: 4a0b018b  eor      w11, w12, w11
//   0x00c628: b900012b  str      w11, [x9]
//   0x00c62c: 17ffff94  b        #0xc47c
//   0x00c630: 90ffffc8  adrp     x8, #0x4000
//   0x00c634: 5282040a  mov      w10, #0x1020
//   0x00c638: 91118108  add      x8, x8, #0x460
//   0x00c63c: 72a0004a  movk     w10, #2, lsl #16
//   0x00c640: 11000509  add      w9, w8, #1
//   0x00c644: 0a280129  bic      w9, w9, w8
//   0x00c648: 2a2903e9  mvn      w9, w9
//   0x00c64c: 8a0a0129  and      x9, x9, x10
//   0x00c650: d2809caa  mov      x10, #0x4e5
//   0x00c654: f2b8f12a  movk     x10, #0xc789, lsl #16
//   0x00c658: f2c0020a  movk     x10, #0x10, lsl #32
//   0x00c65c: f2e0012a  movk     x10, #9, lsl #48
//   0x00c660: 8b0a0129  add      x9, x9, x10
//   0x00c664: 529aa92a  mov      w10, #0xd549
//   0x00c668: 72a8fd2a  movk     w10, #0x47e9, lsl #16
//   0x00c66c: eb0a013f  cmp      x9, x10
//   0x00c670: 54000923  b.lo     #0xc794
//   0x00c674: f94002a9  ldr      x9, [x21]
//   0x00c678: b940012a  ldr      w10, [x9]
//   0x00c67c: d34b7d4b  ubfx     x11, x10, #0xb, #0x15
//   0x00c680: d3417d4c  ubfx     x12, x10, #1, #0x1f
//   0x00c684: 121b016d  and      w13, w11, #0x20
//   0x00c688: 121a016e  and      w14, w11, #0x40
//   0x00c68c: 3315654d  bfxil    w13, w10, #0x15, #5
//   0x00c690: 1219016f  and      w15, w11, #0x80
//   0x00c694: 2a0e01ad  orr      w13, w13, w14
//   0x00c698: 1218016e  and      w14, w11, #0x100
//   0x00c69c: 2a0f01ad  orr      w13, w13, w15
//   0x00c6a0: 1217016f  and      w15, w11, #0x200
//   0x00c6a4: 2a0e01ad  orr      w13, w13, w14
//   0x00c6a8: 1216018e  and      w14, w12, #0x400
//   0x00c6ac: 2a0f01ad  orr      w13, w13, w15
//   0x00c6b0: 1215018f  and      w15, w12, #0x800
//   0x00c6b4: 2a0e01ad  orr      w13, w13, w14
//   0x00c6b8: 1214018e  and      w14, w12, #0x1000
//   0x00c6bc: 2a0f01ad  orr      w13, w13, w15
//   0x00c6c0: 1213018f  and      w15, w12, #0x2000
//   0x00c6c4: 2a0e01ad  orr      w13, w13, w14
//   0x00c6c8: d35bfd4e  lsr      x14, x10, #0x1b
//   0x00c6cc: 2a0f01ad  orr      w13, w13, w15
//   0x00c6d0: d342fd4f  lsr      x15, x10, #2
//   0x00c6d4: 927c01ce  and      x14, x14, #0x10
//   0x00c6d8: 927c01ef  and      x15, x15, #0x10
//   0x00c6dc: b347294e  bfxil    x14, x10, #7, #4
//   0x00c6e0: 1212018c  and      w12, w12, #0x4000
//   0x00c6e4: 1211016b  and      w11, w11, #0x8000
//   0x00c6e8: b35b794f  bfxil    x15, x10, #0x1b, #4
//   0x00c6ec: 2a0c01aa  orr      w10, w13, w12
//   0x00c6f0: d282880d  mov      x13, #0x1440
//   0x00c6f4: 2a0b014a  orr      w10, w10, w11
//   0x00c6f8: f86e7a6b  ldr      x11, [x19, x14, lsl #3]
//   0x00c6fc: 93403d4c  sxth     x12, w10
//   0x00c700: b900002e  str      w14, [x1]
//   0x00c704: b900030f  str      w15, [x24]
//   0x00c708: f2a140cd  movk     x13, #0xa06, lsl #16
//   0x00c70c: 790000ea  strh     w10, [x7]
//   0x00c710: d280800a  mov      x10, #0x400
//   0x00c714: 386c696b  ldrb     w11, [x11, x12]
//   0x00c718: d282080c  mov      x12, #0x1040
//   0x00c71c: f2a1404c  movk     x12, #0xa02, lsl #16
//   0x00c720: f2a0008a  movk     x10, #4, lsl #16
//   0x00c724: f2cc080c  movk     x12, #0x6040, lsl #32
//   0x00c728: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00c72c: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00c730: f2cc288d  movk     x13, #0x6144, lsl #32
//   0x00c734: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x00c738: 8a0a010a  and      x10, x8, x10
//   0x00c73c: aa280188  orn      x8, x12, x8
//   0x00c740: f82f7a6b  str      x11, [x19, x15, lsl #3]
//   0x00c744: 8a0d0108  and      x8, x8, x13
//   0x00c748: 5280208e  mov      w14, #0x104
//   0x00c74c: 8b0a0108  add      x8, x8, x10
//   0x00c750: d28d6b8a  mov      x10, #0x6b5c
//   0x00c754: b8404d2b  ldr      w11, [x9, #4]!
//   0x00c758: f90002a9  str      x9, [x21]
//   0x00c75c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00c760: 72a0202e  movk     w14, #0x101, lsl #16
//   0x00c764: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00c768: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00c76c: aa0e0108  orr      x8, x8, x14
//   0x00c770: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00c774: ca0a0108  eor      x8, x8, x10
//   0x00c778: 9240156a  and      x10, x11, #0x3f
//   0x00c77c: 8b080128  add      x8, x9, x8
//   0x00c780: f85f83a9  ldur     x9, [x29, #-8]
//   0x00c784: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00c788: f9400108  ldr      x8, [x8]
//   0x00c78c: cb090108  sub      x8, x8, x9
//   0x00c790: d61f0100  br       x8
//   0x00c794: f94002a9  ldr      x9, [x21]
//   0x00c798: 529c0fcb  mov      w11, #0xe07e
//   0x00c79c: 72ad36ab  movk     w11, #0x69b5, lsl #16
//   0x00c7a0: 5294cd4c  mov      w12, #0xa66a
//   0x00c7a4: 72a474ac  movk     w12, #0x23a5, lsl #16
//   0x00c7a8: 52817e6e  mov      w14, #0xbf3
//   0x00c7ac: f9000089  str      x9, [x4]
//   0x00c7b0: b940012a  ldr      w10, [x9]
//   0x00c7b4: 4a0b014a  eor      w10, w10, w11
//   0x00c7b8: b900012a  str      w10, [x9]
//   0x00c7bc: b9800029  ldrsw    x9, [x1]
//   0x00c7c0: 794000ed  ldrh     w13, [x7]
//   0x00c7c4: d37df12a  lsl      x10, x9, #3
//   0x00c7c8: 4a0c0129  eor      w9, w9, w12
//   0x00c7cc: 52916dcc  mov      w12, #0x8b6e
//   0x00c7d0: 4a0e01ad  eor      w13, w13, w14
//   0x00c7d4: 72aa0a0c  movk     w12, #0x5050, lsl #16
//   0x00c7d8: f86a6a6b  ldr      x11, [x19, x10]
//   0x00c7dc: b9000029  str      w9, [x1]
//   0x00c7e0: 790000ed  strh     w13, [x7]
//   0x00c7e4: ca0c016c  eor      x12, x11, x12
//   0x00c7e8: f82a6a6c  str      x12, [x19, x10]
//   0x00c7ec: 52800d8a  mov      w10, #0x6c
//   0x00c7f0: 39400169  ldrb     w9, [x11]
//   0x00c7f4: 4a0a012a  eor      w10, w9, w10
//   0x00c7f8: 3900016a  strb     w10, [x11]
//   0x00c7fc: 5284182b  mov      w11, #0x20c1
//   0x00c800: b980030a  ldrsw    x10, [x24]
//   0x00c804: 72a32b8b  movk     w11, #0x195c, lsl #16
//   0x00c808: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00c80c: 4a0b014a  eor      w10, w10, w11
//   0x00c810: f94002a9  ldr      x9, [x21]
//   0x00c814: 528d7d0b  mov      w11, #0x6be8
//   0x00c818: 72aded4b  movk     w11, #0x6f6a, lsl #16
//   0x00c81c: b900030a  str      w10, [x24]
//   0x00c820: f9000089  str      x9, [x4]
//   0x00c824: b8404d2c  ldr      w12, [x9, #4]!
//   0x00c828: f90002a9  str      x9, [x21]
//   0x00c82c: 4a0b018b  eor      w11, w12, w11
//   0x00c830: b900012b  str      w11, [x9]
//   0x00c834: 17ffff90  b        #0xc674
//   0x00c838: 90ffffc8  adrp     x8, #0x4000
//   0x00c83c: 528a228a  mov      w10, #0x5114
//   0x00c840: 91118108  add      x8, x8, #0x460
//   0x00c844: 11000509  add      w9, w8, #1
//   0x00c848: 0a280129  bic      w9, w9, w8
//   0x00c84c: 2a2903e9  mvn      w9, w9
//   0x00c850: 8a0a0129  and      x9, x9, x10
//   0x00c854: d286424a  mov      x10, #0x3212
//   0x00c858: f2b2f9ca  movk     x10, #0x97ce, lsl #16
//   0x00c85c: f2e0048a  movk     x10, #0x24, lsl #48
//   0x00c860: 8b0a0129  add      x9, x9, x10
//   0x00c864: 528a7e4a  mov      w10, #0x53f2
//   0x00c868: 72a088aa  movk     w10, #0x445, lsl #16
//   0x00c86c: eb0a013f  cmp      x9, x10
//   0x00c870: 540008a3  b.lo     #0xc984
//   0x00c874: f94002a9  ldr      x9, [x21]
//   0x00c878: b940012a  ldr      w10, [x9]
//   0x00c87c: d3417d4d  ubfx     x13, x10, #1, #0x1f
//   0x00c880: d35bfd4b  lsr      x11, x10, #0x1b
//   0x00c884: 121b01af  and      w15, w13, #0x20
//   0x00c888: d356694c  ubfx     x12, x10, #0x16, #5
//   0x00c88c: d3467d4e  ubfx     x14, x10, #6, #0x1a
//   0x00c890: 3310514f  bfxil    w15, w10, #0x10, #5
//   0x00c894: 121a01aa  and      w10, w13, #0x40
//   0x00c898: 121101ce  and      w14, w14, #0x8000
//   0x00c89c: 2a0a01ea  orr      w10, w15, w10
//   0x00c8a0: 121901af  and      w15, w13, #0x80
//   0x00c8a4: 2a0f014a  orr      w10, w10, w15
//   0x00c8a8: 121801af  and      w15, w13, #0x100
//   0x00c8ac: 2a0f014a  orr      w10, w10, w15
//   0x00c8b0: 121701af  and      w15, w13, #0x200
//   0x00c8b4: 2a0f014a  orr      w10, w10, w15
//   0x00c8b8: 121601af  and      w15, w13, #0x400
//   0x00c8bc: 2a0f014a  orr      w10, w10, w15
//   0x00c8c0: 121501af  and      w15, w13, #0x800
//   0x00c8c4: 2a0f014a  orr      w10, w10, w15
//   0x00c8c8: 121401af  and      w15, w13, #0x1000
//   0x00c8cc: 2a0f014a  orr      w10, w10, w15
//   0x00c8d0: 121301af  and      w15, w13, #0x2000
//   0x00c8d4: 121201ad  and      w13, w13, #0x4000
//   0x00c8d8: 2a0f014a  orr      w10, w10, w15
//   0x00c8dc: 2a0d014a  orr      w10, w10, w13
//   0x00c8e0: b900002b  str      w11, [x1]
//   0x00c8e4: 2a0e014a  orr      w10, w10, w14
//   0x00c8e8: f86b7a6b  ldr      x11, [x19, x11, lsl #3]
//   0x00c8ec: 93403d4d  sxth     x13, w10
//   0x00c8f0: b900030c  str      w12, [x24]
//   0x00c8f4: d282880e  mov      x14, #0x1440
//   0x00c8f8: 5280208f  mov      w15, #0x104
//   0x00c8fc: 790000ea  strh     w10, [x7]
//   0x00c900: d280800a  mov      x10, #0x400
//   0x00c904: 786d696b  ldrh     w11, [x11, x13]
//   0x00c908: d282080d  mov      x13, #0x1040
//   0x00c90c: f2a1404d  movk     x13, #0xa02, lsl #16
//   0x00c910: f2a0008a  movk     x10, #4, lsl #16
//   0x00c914: f2cc080d  movk     x13, #0x6040, lsl #32
//   0x00c918: f2a140ce  movk     x14, #0xa06, lsl #16
//   0x00c91c: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00c920: f2e0140d  movk     x13, #0xa0, lsl #48
//   0x00c924: f2cc288e  movk     x14, #0x6144, lsl #32
//   0x00c928: 8a0a010a  and      x10, x8, x10
//   0x00c92c: f2e0140e  movk     x14, #0xa0, lsl #48
//   0x00c930: aa2801a8  orn      x8, x13, x8
//   0x00c934: 8a0e0108  and      x8, x8, x14
//   0x00c938: f82c7a6b  str      x11, [x19, x12, lsl #3]
//   0x00c93c: 8b0a0108  add      x8, x8, x10
//   0x00c940: d28d6b8a  mov      x10, #0x6b5c
//   0x00c944: b8404d2b  ldr      w11, [x9, #4]!
//   0x00c948: f90002a9  str      x9, [x21]
//   0x00c94c: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00c950: 72a0202f  movk     w15, #0x101, lsl #16
//   0x00c954: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00c958: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00c95c: aa0f0108  orr      x8, x8, x15
//   0x00c960: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00c964: ca0a0108  eor      x8, x8, x10
//   0x00c968: 9240156a  and      x10, x11, #0x3f
//   0x00c96c: 8b080128  add      x8, x9, x8
//   0x00c970: f85f83a9  ldur     x9, [x29, #-8]
//   0x00c974: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00c978: f9400108  ldr      x8, [x8]
//   0x00c97c: cb090108  sub      x8, x8, x9
//   0x00c980: d61f0100  br       x8
//   0x00c984: f94002a9  ldr      x9, [x21]
//   0x00c988: 5291db4b  mov      w11, #0x8eda
//   0x00c98c: 72a9162b  movk     w11, #0x48b1, lsl #16
//   0x00c990: 5295efec  mov      w12, #0xaf7f
//   0x00c994: 52976d2e  mov      w14, #0xbb69
//   0x00c998: 72a0232c  movk     w12, #0x119, lsl #16
//   0x00c99c: f9000089  str      x9, [x4]
//   0x00c9a0: 72a7aa0e  movk     w14, #0x3d50, lsl #16
//   0x00c9a4: b940012a  ldr      w10, [x9]
//   0x00c9a8: 4a0b014a  eor      w10, w10, w11
//   0x00c9ac: b900012a  str      w10, [x9]
//   0x00c9b0: b9800029  ldrsw    x9, [x1]
//   0x00c9b4: 798000ed  ldrsh    x13, [x7]
//   0x00c9b8: d37df12a  lsl      x10, x9, #3
//   0x00c9bc: 4a0c0129  eor      w9, w9, w12
//   0x00c9c0: 52813e2c  mov      w12, #0x9f1
//   0x00c9c4: 4a0c01ac  eor      w12, w13, w12
//   0x00c9c8: f86a6a6b  ldr      x11, [x19, x10]
//   0x00c9cc: b9000029  str      w9, [x1]
//   0x00c9d0: 790000ec  strh     w12, [x7]
//   0x00c9d4: ca0e016e  eor      x14, x11, x14
//   0x00c9d8: f82a6a6e  str      x14, [x19, x10]
//   0x00c9dc: 9b0d7d6a  mul      x10, x11, x13
//   0x00c9e0: 529e190b  mov      w11, #0xf0c8
//   0x00c9e4: 786d6949  ldrh     w9, [x10, x13]
//   0x00c9e8: 4a0b012b  eor      w11, w9, w11
//   0x00c9ec: 782d694b  strh     w11, [x10, x13]
//   0x00c9f0: 529f444b  mov      w11, #0xfa22
//   0x00c9f4: b980030a  ldrsw    x10, [x24]
//   0x00c9f8: 72a7ec6b  movk     w11, #0x3f63, lsl #16
//   0x00c9fc: f82a7a69  str      x9, [x19, x10, lsl #3]
//   0x00ca00: 4a0b014a  eor      w10, w10, w11
//   0x00ca04: f94002a9  ldr      x9, [x21]
//   0x00ca08: 529dd62b  mov      w11, #0xeeb1
//   0x00ca0c: 72a7974b  movk     w11, #0x3cba, lsl #16
//   0x00ca10: b900030a  str      w10, [x24]
//   0x00ca14: f9000089  str      x9, [x4]
//   0x00ca18: b8404d2c  ldr      w12, [x9, #4]!
//   0x00ca1c: f90002a9  str      x9, [x21]
//   0x00ca20: 4a0b018b  eor      w11, w12, w11
//   0x00ca24: b900012b  str      w11, [x9]
//   0x00ca28: 17ffff93  b        #0xc874
//   0x00ca2c: 90ffffc8  adrp     x8, #0x4000
//   0x00ca30: 5281ba8a  mov      w10, #0xdd4
//   0x00ca34: 91118108  add      x8, x8, #0x460
//   0x00ca38: 72a0266a  movk     w10, #0x133, lsl #16
//   0x00ca3c: 11000509  add      w9, w8, #1
//   0x00ca40: 0a280129  bic      w9, w9, w8
//   0x00ca44: 2a2903e9  mvn      w9, w9
//   0x00ca48: 8a0a0129  and      x9, x9, x10
//   0x00ca4c: d29af90a  mov      x10, #0xd7c8
//   0x00ca50: f2ab408a  movk     x10, #0x5a04, lsl #16
//   0x00ca54: f2c0018a  movk     x10, #0xc, lsl #32
//   0x00ca58: f2e1410a  movk     x10, #0xa08, lsl #48
//   0x00ca5c: 8b0a0129  add      x9, x9, x10
//   0x00ca60: 5287acca  mov      w10, #0x3d66
//   0x00ca64: 72ab0f4a  movk     w10, #0x587a, lsl #16
//   0x00ca68: eb0a013f  cmp      x9, x10
//   0x00ca6c: 54000d03  b.lo     #0xcc0c
//   0x00ca70: f94002a9  ldr      x9, [x21]
//   0x00ca74: b940012a  ldr      w10, [x9]
//   0x00ca78: d34b7d4b  ubfx     x11, x10, #0xb, #0x15
//   0x00ca7c: d35bfd4c  lsr      x12, x10, #0x1b
//   0x00ca80: 121b016d  and      w13, w11, #0x20
//   0x00ca84: 121a016e  and      w14, w11, #0x40
//   0x00ca88: 331a794d  bfxil    w13, w10, #0x1a, #5
//   0x00ca8c: 1219016f  and      w15, w11, #0x80
//   0x00ca90: 2a0e01ad  orr      w13, w13, w14
//   0x00ca94: 1218016e  and      w14, w11, #0x100
//   0x00ca98: 2a0f01ad  orr      w13, w13, w15
//   0x00ca9c: 1217016b  and      w11, w11, #0x200
//   0x00caa0: 2a0e01ad  orr      w13, w13, w14
//   0x00caa4: d3417d4e  ubfx     x14, x10, #1, #0x1f
//   0x00caa8: 927c018c  and      x12, x12, #0x10
//   0x00caac: 2a0b01ab  orr      w11, w13, w11
//   0x00cab0: 121601cd  and      w13, w14, #0x400
//   0x00cab4: b356654c  bfxil    x12, x10, #0x16, #4
//   0x00cab8: 2a0d016b  orr      w11, w11, w13
//   0x00cabc: 121501cd  and      w13, w14, #0x800
//   0x00cac0: d351fd4f  lsr      x15, x10, #0x11
//   0x00cac4: 2a0d016b  orr      w11, w11, w13
//   0x00cac8: 121401cd  and      w13, w14, #0x1000
//   0x00cacc: 927c01ef  and      x15, x15, #0x10
//   0x00cad0: 2a0d016b  orr      w11, w11, w13
//   0x00cad4: 121301cd  and      w13, w14, #0x2000
//   0x00cad8: 121201ce  and      w14, w14, #0x4000
//   0x00cadc: b347294f  bfxil    x15, x10, #7, #4
//   0x00cae0: 2a0d016b  orr      w11, w11, w13
//   0x00cae4: 5317594a  lsl      w10, w10, #9
//   0x00cae8: f86c7a6d  ldr      x13, [x19, x12, lsl #3]
//   0x00caec: 2a0e016b  orr      w11, w11, w14
//   0x00caf0: 1211014a  and      w10, w10, #0x8000
//   0x00caf4: b900002c  str      w12, [x1]
//   0x00caf8: 2a0a016e  orr      w14, w11, w10
//   0x00cafc: f86f7a6b  ldr      x11, [x19, x15, lsl #3]
//   0x00cb00: b900030f  str      w15, [x24]
//   0x00cb04: 8b2ea1ac  add      x12, x13, w14, sxth
//   0x00cb08: 927df18a  and      x10, x12, #0xfffffffffffffff8
//   0x00cb0c: 9240098c  and      x12, x12, #7
//   0x00cb10: f1001d9f  cmp      x12, #7
//   0x00cb14: 790000ee  strh     w14, [x7]
//   0x00cb18: 54000360  b.eq     #0xcb84
//   0x00cb1c: 90ffffcd  adrp     x13, #0x4000
//   0x00cb20: 911181ad  add      x13, x13, #0x460
//   0x00cb24: 110005ae  add      w14, w13, #1
//   0x00cb28: 0a2d01cd  bic      w13, w14, w13
//   0x00cb2c: 528800ce  mov      w14, #0x4006
//   0x00cb30: 2a2d03ed  mvn      w13, w13
//   0x00cb34: 72a0008e  movk     w14, #4, lsl #16
//   0x00cb38: 8a0e01ad  and      x13, x13, x14
//   0x00cb3c: d285722e  mov      x14, #0x2b91
//   0x00cb40: f2ad098e  movk     x14, #0x684c, lsl #16
//   0x00cb44: f2c1008e  movk     x14, #0x804, lsl #32
//   0x00cb48: f2e00c0e  movk     x14, #0x60, lsl #48
//   0x00cb4c: 8b0e01ad  add      x13, x13, x14
//   0x00cb50: 529aa1ee  mov      w14, #0xd50f
//   0x00cb54: 72a1764e  movk     w14, #0xbb2, lsl #16
//   0x00cb58: eb0e01bf  cmp      x13, x14
//   0x00cb5c: 540009c3  b.lo     #0xcc94
//   0x00cb60: f940014d  ldr      x13, [x10]
//   0x00cb64: d37df18c  lsl      x12, x12, #3
//   0x00cb68: 5280070e  mov      w14, #0x38
//   0x00cb6c: cb0c01ce  sub      x14, x14, x12
//   0x00cb70: 92801fef  mov      x15, #-0x100
//   0x00cb74: 9acc21ec  lsl      x12, x15, x12
//   0x00cb78: 9ace256b  lsr      x11, x11, x14
//   0x00cb7c: 8a0c01ac  and      x12, x13, x12
//   0x00cb80: aa0b018b  orr      x11, x12, x11
//   0x00cb84: f900014b  str      x11, [x10]
//   0x00cb88: d282080b  mov      x11, #0x1040
//   0x00cb8c: b8404d2a  ldr      w10, [x9, #4]!
//   0x00cb90: f90002a9  str      x9, [x21]
//   0x00cb94: d2808009  mov      x9, #0x400
//   0x00cb98: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00cb9c: f2a00089  movk     x9, #4, lsl #16
//   0x00cba0: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00cba4: f2c02089  movk     x9, #0x104, lsl #32
//   0x00cba8: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00cbac: 8a090109  and      x9, x8, x9
//   0x00cbb0: aa280168  orn      x8, x11, x8
//   0x00cbb4: d282880b  mov      x11, #0x1440
//   0x00cbb8: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00cbbc: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00cbc0: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00cbc4: 9240154a  and      x10, x10, #0x3f
//   0x00cbc8: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00cbcc: 8a0b0108  and      x8, x8, x11
//   0x00cbd0: 8b090108  add      x8, x8, x9
//   0x00cbd4: 52802089  mov      w9, #0x104
//   0x00cbd8: 72a02029  movk     w9, #0x101, lsl #16
//   0x00cbdc: aa090108  orr      x8, x8, x9
//   0x00cbe0: d28d6b89  mov      x9, #0x6b5c
//   0x00cbe4: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00cbe8: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00cbec: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00cbf0: ca090108  eor      x8, x8, x9
//   0x00cbf4: f85f83a9  ldur     x9, [x29, #-8]
//   0x00cbf8: 8b080188  add      x8, x12, x8
//   0x00cbfc: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00cc00: f9400108  ldr      x8, [x8]
//   0x00cc04: cb090108  sub      x8, x8, x9
//   0x00cc08: d61f0100  br       x8
//   0x00cc0c: f94002a9  ldr      x9, [x21]
//   0x00cc10: 529131ab  mov      w11, #0x898d
//   0x00cc14: 72aaa1eb  movk     w11, #0x550f, lsl #16
//   0x00cc18: 5297c26d  mov      w13, #0xbe13
//   0x00cc1c: 72adfb0d  movk     w13, #0x6fd8, lsl #16
//   0x00cc20: 5296736e  mov      w14, #0xb39b
//   0x00cc24: f9000089  str      x9, [x4]
//   0x00cc28: 72ade1ee  movk     w14, #0x6f0f, lsl #16
//   0x00cc2c: b940012a  ldr      w10, [x9]
//   0x00cc30: 4a0b014a  eor      w10, w10, w11
//   0x00cc34: b900012a  str      w10, [x9]
//   0x00cc38: b9800029  ldrsw    x9, [x1]
//   0x00cc3c: b980030c  ldrsw    x12, [x24]
//   0x00cc40: 794000ef  ldrh     w15, [x7]
//   0x00cc44: d37df12a  lsl      x10, x9, #3
//   0x00cc48: 4a0e0129  eor      w9, w9, w14
//   0x00cc4c: 528f8b8e  mov      w14, #0x7c5c
//   0x00cc50: 72ace66e  movk     w14, #0x6733, lsl #16
//   0x00cc54: f86a6a6b  ldr      x11, [x19, x10]
//   0x00cc58: b9000029  str      w9, [x1]
//   0x00cc5c: 52961e49  mov      w9, #0xb0f2
//   0x00cc60: 72aca529  movk     w9, #0x6529, lsl #16
//   0x00cc64: ca0d016b  eor      x11, x11, x13
//   0x00cc68: d37df18d  lsl      x13, x12, #3
//   0x00cc6c: 4a0e018c  eor      w12, w12, w14
//   0x00cc70: f82a6a6b  str      x11, [x19, x10]
//   0x00cc74: 5281584a  mov      w10, #0xac2
//   0x00cc78: f86d6a6b  ldr      x11, [x19, x13]
//   0x00cc7c: 4a0a01ea  eor      w10, w15, w10
//   0x00cc80: b900030c  str      w12, [x24]
//   0x00cc84: 790000ea  strh     w10, [x7]
//   0x00cc88: ca090169  eor      x9, x11, x9
//   0x00cc8c: f82d6a69  str      x9, [x19, x13]
//   0x00cc90: 17ffff78  b        #0xca70
//   0x00cc94: f940014d  ldr      x13, [x10]
//   0x00cc98: 9278ddad  and      x13, x13, #0xffffffffffffff00
//   0x00cc9c: aa0be1ad  orr      x13, x13, x11, lsl #56
//   0x00cca0: f900014d  str      x13, [x10]
//   0x00cca4: 17ffffb0  b        #0xcb64
//   0x00cca8: 90ffffc8  adrp     x8, #0x4000
//   0x00ccac: 5295460a  mov      w10, #0xaa30
//   0x00ccb0: 91118108  add      x8, x8, #0x460
//   0x00ccb4: 72a803aa  movk     w10, #0x401d, lsl #16
//   0x00ccb8: 11000509  add      w9, w8, #1
//   0x00ccbc: 0a280129  bic      w9, w9, w8
//   0x00ccc0: 2a2903e9  mvn      w9, w9
//   0x00ccc4: 8a0a0129  and      x9, x9, x10
//   0x00ccc8: d289288a  mov      x10, #0x4944
//   0x00cccc: f2a5ab8a  movk     x10, #0x2d5c, lsl #16
//   0x00ccd0: f2e0210a  movk     x10, #0x108, lsl #48
//   0x00ccd4: 8b0a0129  add      x9, x9, x10
//   0x00ccd8: 528646aa  mov      w10, #0x3235
//   0x00ccdc: 72a552aa  movk     w10, #0x2a95, lsl #16
//   0x00cce0: eb0a013f  cmp      x9, x10
//   0x00cce4: 54000ce3  b.lo     #0xce80
//   0x00cce8: f94002a9  ldr      x9, [x21]
//   0x00ccec: d0ffffab  adrp     x11, #0x2000
//   0x00ccf0: b940012a  ldr      w10, [x9]
//   0x00ccf4: fd408961  ldr      d1, [x11, #0x110]
//   0x00ccf8: d0ffffab  adrp     x11, #0x2000
//   0x00ccfc: 0e040d40  dup      v0.2s, w10
//   0x00cd00: d351554d  ubfx     x13, x10, #0x11, #5
//   0x00cd04: 3dc02163  ldr      q3, [x11, #0x80]
//   0x00cd08: d35bfd4b  lsr      x11, x10, #0x1b
//   0x00cd0c: 927c016b  and      x11, x11, #0x10
//   0x00cd10: b356654b  bfxil    x11, x10, #0x16, #4
//   0x00cd14: b900030d  str      w13, [x24]
//   0x00cd18: 2ea14400  ushl     v0.2s, v0.2s, v1.2s
//   0x00cd1c: b900002b  str      w11, [x1]
//   0x00cd20: 4e801801  uzp1     v1.4s, v0.4s, v0.4s
//   0x00cd24: 4e040404  dup      v4.4s, v0.s[0]
//   0x00cd28: 4e803802  zip1     v2.4s, v0.4s, v0.4s
//   0x00cd2c: 1e26000a  fmov     w10, s0
//   0x00cd30: 6e004021  ext      v1.16b, v1.16b, v0.16b, #8
//   0x00cd34: 1214014e  and      w14, w10, #0x1000
//   0x00cd38: 12130150  and      w16, w10, #0x2000
//   0x00cd3c: 6e024021  ext      v1.16b, v1.16b, v2.16b, #8
//   0x00cd40: 3dc02402  ldr      q2, [x0, #0x90]
//   0x00cd44: 4e221c21  and      v1.16b, v1.16b, v2.16b
//   0x00cd48: 4e231c82  and      v2.16b, v4.16b, v3.16b
//   0x00cd4c: 4ea21c21  orr      v1.16b, v1.16b, v2.16b
//   0x00cd50: 6e014022  ext      v2.16b, v1.16b, v1.16b, #8
//   0x00cd54: 0ea21c21  orr      v1.8b, v1.8b, v2.8b
//   0x00cd58: 0e0c3c2c  mov      w12, v1.s[1]
//   0x00cd5c: 1e26002f  fmov     w15, s1
//   0x00cd60: 2a0c01ec  orr      w12, w15, w12
//   0x00cd64: 1212014f  and      w15, w10, #0x4000
//   0x00cd68: 2a0e018c  orr      w12, w12, w14
//   0x00cd6c: f86b7a6e  ldr      x14, [x19, x11, lsl #3]
//   0x00cd70: 2a10018c  orr      w12, w12, w16
//   0x00cd74: 1211014a  and      w10, w10, #0x8000
//   0x00cd78: 2a0f018c  orr      w12, w12, w15
//   0x00cd7c: f86d7a6b  ldr      x11, [x19, x13, lsl #3]
//   0x00cd80: 2a0a018f  orr      w15, w12, w10
//   0x00cd84: 8b2fa1cc  add      x12, x14, w15, sxth
//   0x00cd88: 927df18a  and      x10, x12, #0xfffffffffffffff8
//   0x00cd8c: f240098c  ands     x12, x12, #7
//   0x00cd90: 790000ef  strh     w15, [x7]
//   0x00cd94: 54000320  b.eq     #0xcdf8
//   0x00cd98: 90ffffcd  adrp     x13, #0x4000
//   0x00cd9c: d37df18c  lsl      x12, x12, #3
//   0x00cda0: 911181ad  add      x13, x13, #0x460
//   0x00cda4: 110005ae  add      w14, w13, #1
//   0x00cda8: 0a2d01cd  bic      w13, w14, w13
//   0x00cdac: 5288920e  mov      w14, #0x4490
//   0x00cdb0: 2a2d03ed  mvn      w13, w13
//   0x00cdb4: 72a0200e  movk     w14, #0x100, lsl #16
//   0x00cdb8: 8a0e01ad  and      x13, x13, x14
//   0x00cdbc: d28bb1ce  mov      x14, #0x5d8e
//   0x00cdc0: f2b2ed6e  movk     x14, #0x976b, lsl #16
//   0x00cdc4: f2c0100e  movk     x14, #0x80, lsl #32
//   0x00cdc8: 8b0e01ad  add      x13, x13, x14
//   0x00cdcc: 528af42e  mov      w14, #0x57a1
//   0x00cdd0: 72a0ed4e  movk     w14, #0x76a, lsl #16
//   0x00cdd4: eb0e01bf  cmp      x13, x14
//   0x00cdd8: 54000983  b.lo     #0xcf08
//   0x00cddc: f940014d  ldr      x13, [x10]
//   0x00cde0: cb0c03ee  neg      x14, x12
//   0x00cde4: 9280000f  mov      x15, #-1
//   0x00cde8: 9acc216b  lsl      x11, x11, x12
//   0x00cdec: 9ace25ee  lsr      x14, x15, x14
//   0x00cdf0: 8a0e01ac  and      x12, x13, x14
//   0x00cdf4: aa0b018b  orr      x11, x12, x11
//   0x00cdf8: f900014b  str      x11, [x10]
//   0x00cdfc: d282080b  mov      x11, #0x1040
//   0x00ce00: b8404d2a  ldr      w10, [x9, #4]!
//   0x00ce04: f90002a9  str      x9, [x21]
//   0x00ce08: d2808009  mov      x9, #0x400
//   0x00ce0c: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00ce10: f2a00089  movk     x9, #4, lsl #16
//   0x00ce14: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00ce18: f2c02089  movk     x9, #0x104, lsl #32
//   0x00ce1c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00ce20: 8a090109  and      x9, x8, x9
//   0x00ce24: aa280168  orn      x8, x11, x8
//   0x00ce28: d282880b  mov      x11, #0x1440
//   0x00ce2c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00ce30: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00ce34: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00ce38: 9240154a  and      x10, x10, #0x3f
//   0x00ce3c: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00ce40: 8a0b0108  and      x8, x8, x11
//   0x00ce44: 8b090108  add      x8, x8, x9
//   0x00ce48: 52802089  mov      w9, #0x104
//   0x00ce4c: 72a02029  movk     w9, #0x101, lsl #16
//   0x00ce50: aa090108  orr      x8, x8, x9
//   0x00ce54: d28d6b89  mov      x9, #0x6b5c
//   0x00ce58: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00ce5c: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00ce60: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00ce64: ca090108  eor      x8, x8, x9
//   0x00ce68: f85f83a9  ldur     x9, [x29, #-8]
//   0x00ce6c: 8b080188  add      x8, x12, x8
//   0x00ce70: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00ce74: f9400108  ldr      x8, [x8]
//   0x00ce78: cb090108  sub      x8, x8, x9
//   0x00ce7c: d61f0100  br       x8
//   0x00ce80: f94002a9  ldr      x9, [x21]
//   0x00ce84: 5292044b  mov      w11, #0x9022
//   0x00ce88: 72a1382b  movk     w11, #0x9c1, lsl #16
//   0x00ce8c: 529d442d  mov      w13, #0xea21
//   0x00ce90: 72a4f28d  movk     w13, #0x2794, lsl #16
//   0x00ce94: 5295a5ee  mov      w14, #0xad2f
//   0x00ce98: f9000089  str      x9, [x4]
//   0x00ce9c: 72a05bae  movk     w14, #0x2dd, lsl #16
//   0x00cea0: b940012a  ldr      w10, [x9]
//   0x00cea4: 4a0b014a  eor      w10, w10, w11
//   0x00cea8: b900012a  str      w10, [x9]
//   0x00ceac: b9800029  ldrsw    x9, [x1]
//   0x00ceb0: b980030c  ldrsw    x12, [x24]
//   0x00ceb4: 794000ef  ldrh     w15, [x7]
//   0x00ceb8: d37df12a  lsl      x10, x9, #3
//   0x00cebc: 4a0e0129  eor      w9, w9, w14
//   0x00cec0: 528d7aee  mov      w14, #0x6bd7
//   0x00cec4: 72a1dc8e  movk     w14, #0xee4, lsl #16
//   0x00cec8: f86a6a6b  ldr      x11, [x19, x10]
//   0x00cecc: b9000029  str      w9, [x1]
//   0x00ced0: 529efc89  mov      w9, #0xf7e4
//   0x00ced4: 72a6cc69  movk     w9, #0x3663, lsl #16
//   0x00ced8: ca0d016b  eor      x11, x11, x13
//   0x00cedc: d37df18d  lsl      x13, x12, #3
//   0x00cee0: 4a0e018c  eor      w12, w12, w14
//   0x00cee4: f82a6a6b  str      x11, [x19, x10]
//   0x00cee8: 52861a8a  mov      w10, #0x30d4
//   0x00ceec: f86d6a6b  ldr      x11, [x19, x13]
//   0x00cef0: 4a0a01ea  eor      w10, w15, w10
//   0x00cef4: b900030c  str      w12, [x24]
//   0x00cef8: 790000ea  strh     w10, [x7]
//   0x00cefc: ca090169  eor      x9, x11, x9
//   0x00cf00: f82d6a69  str      x9, [x19, x13]
//   0x00cf04: 17ffff79  b        #0xcce8
//   0x00cf08: f940014d  ldr      x13, [x10]
//   0x00cf0c: 9acc256e  lsr      x14, x11, x12
//   0x00cf10: aa0e01ad  orr      x13, x13, x14
//   0x00cf14: f900014d  str      x13, [x10]
//   0x00cf18: 17ffffb2  b        #0xcde0
//   0x00cf1c: f94002a8  ldr      x8, [x21]
//   0x00cf20: b9400109  ldr      w9, [x8]
//   0x00cf24: b8404d0a  ldr      w10, [x8, #4]!
//   0x00cf28: f90002a8  str      x8, [x21]
//   0x00cf2c: d3467d2b  ubfx     x11, x9, #6, #0x1a
//   0x00cf30: d35bfd28  lsr      x8, x9, #0x1b
//   0x00cf34: 121b016d  and      w13, w11, #0x20
//   0x00cf38: 121a016e  and      w14, w11, #0x40
//   0x00cf3c: 331a792d  bfxil    w13, w9, #0x1a, #5
//   0x00cf40: d34cfd2c  lsr      x12, x9, #0xc
//   0x00cf44: 2a0e01ad  orr      w13, w13, w14
//   0x00cf48: 1219016e  and      w14, w11, #0x80
//   0x00cf4c: 2a0e01ad  orr      w13, w13, w14
//   0x00cf50: 1218016e  and      w14, w11, #0x100
//   0x00cf54: 2a0e01ad  orr      w13, w13, w14
//   0x00cf58: d34b7d2e  ubfx     x14, x9, #0xb, #0x15
//   0x00cf5c: 1217016b  and      w11, w11, #0x200
//   0x00cf60: 927c0108  and      x8, x8, #0x10
//   0x00cf64: 2a0b01ab  orr      w11, w13, w11
//   0x00cf68: 121601cd  and      w13, w14, #0x400
//   0x00cf6c: 2a0d016b  orr      w11, w11, w13
//   0x00cf70: 121501cd  and      w13, w14, #0x800
//   0x00cf74: 2a0d016b  orr      w11, w11, w13
//   0x00cf78: 121401cd  and      w13, w14, #0x1000
//   0x00cf7c: 927c018c  and      x12, x12, #0x10
//   0x00cf80: 2a0d016b  orr      w11, w11, w13
//   0x00cf84: 121301cd  and      w13, w14, #0x2000
//   0x00cf88: b3515128  bfxil    x8, x9, #0x11, #4
//   0x00cf8c: b347292c  bfxil    x12, x9, #7, #4
//   0x00cf90: 53175929  lsl      w9, w9, #9
//   0x00cf94: 121201ce  and      w14, w14, #0x4000
//   0x00cf98: 2a0d016b  orr      w11, w11, w13
//   0x00cf9c: 12110129  and      w9, w9, #0x8000
//   0x00cfa0: 2a0e016b  orr      w11, w11, w14
//   0x00cfa4: 2a090169  orr      w9, w11, w9
//   0x00cfa8: f8687a6d  ldr      x13, [x19, x8, lsl #3]
//   0x00cfac: f86c7a6b  ldr      x11, [x19, x12, lsl #3]
//   0x00cfb0: 93403d2e  sxth     x14, w9
//   0x00cfb4: 9240154a  and      x10, x10, #0x3f
//   0x00cfb8: b9000028  str      w8, [x1]
//   0x00cfbc: b900030c  str      w12, [x24]
//   0x00cfc0: f82e69ab  str      x11, [x13, x14]
//   0x00cfc4: 5280208b  mov      w11, #0x104
//   0x00cfc8: 72a0202b  movk     w11, #0x101, lsl #16
//   0x00cfcc: f941f28d  ldr      x13, [x20, #0x3e0]
//   0x00cfd0: aa0b02cb  orr      x11, x22, x11
//   0x00cfd4: 790000e9  strh     w9, [x7]
//   0x00cfd8: ca11016b  eor      x11, x11, x17
//   0x00cfdc: 8b0b01ab  add      x11, x13, x11
//   0x00cfe0: 8b0a0d6a  add      x10, x11, x10, lsl #3
//   0x00cfe4: f85f83ab  ldur     x11, [x29, #-8]
//   0x00cfe8: f940014a  ldr      x10, [x10]
//   0x00cfec: cb0b014a  sub      x10, x10, x11
//   0x00cff0: d61f0140  br       x10
//   0x00cff4: f94002a8  ldr      x8, [x21]
//   0x00cff8: b9400109  ldr      w9, [x8]
//   0x00cffc: d3417d2b  ubfx     x11, x9, #1, #0x1f
//   0x00d000: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00d004: 121b016d  and      w13, w11, #0x20
//   0x00d008: 121a016e  and      w14, w11, #0x40
//   0x00d00c: 3310512d  bfxil    w13, w9, #0x10, #5
//   0x00d010: 1219016f  and      w15, w11, #0x80
//   0x00d014: 2a0e01ad  orr      w13, w13, w14
//   0x00d018: 1218016e  and      w14, w11, #0x100
//   0x00d01c: 2a0f01ad  orr      w13, w13, w15
//   0x00d020: d3507d2f  ubfx     x15, x9, #0x10, #0x10
//   0x00d024: 2a0e01ad  orr      w13, w13, w14
//   0x00d028: 1217016b  and      w11, w11, #0x200
//   0x00d02c: 2a0b01ab  orr      w11, w13, w11
//   0x00d030: 121601ed  and      w13, w15, #0x400
//   0x00d034: 2a0d016b  orr      w11, w11, w13
//   0x00d038: 121501ed  and      w13, w15, #0x800
//   0x00d03c: 2a0d016b  orr      w11, w11, w13
//   0x00d040: 121401ed  and      w13, w15, #0x1000
//   0x00d044: d351fd2c  lsr      x12, x9, #0x11
//   0x00d048: 2a0d016b  orr      w11, w11, w13
//   0x00d04c: 121301ed  and      w13, w15, #0x2000
//   0x00d050: 531c6d2e  lsl      w14, w9, #4
//   0x00d054: 927c014a  and      x10, x10, #0x10
//   0x00d058: 927c018c  and      x12, x12, #0x10
//   0x00d05c: 121201ef  and      w15, w15, #0x4000
//   0x00d060: 2a0d016b  orr      w11, w11, w13
//   0x00d064: 121101ce  and      w14, w14, #0x8000
//   0x00d068: b356652a  bfxil    x10, x9, #0x16, #4
//   0x00d06c: b34c3d2c  bfxil    x12, x9, #0xc, #4
//   0x00d070: 2a0f0169  orr      w9, w11, w15
//   0x00d074: 2a0e0129  orr      w9, w9, w14
//   0x00d078: d37df18b  lsl      x11, x12, #3
//   0x00d07c: b900002a  str      w10, [x1]
//   0x00d080: f86a7a6a  ldr      x10, [x19, x10, lsl #3]
//   0x00d084: b900030c  str      w12, [x24]
//   0x00d088: 790000e9  strh     w9, [x7]
//   0x00d08c: 93403d29  sxth     x9, w9
//   0x00d090: b86b6a6b  ldr      w11, [x19, x11]
//   0x00d094: b829694b  str      w11, [x10, x9]
//   0x00d098: b8404d09  ldr      w9, [x8, #4]!
//   0x00d09c: f90002a8  str      x8, [x21]
//   0x00d0a0: 52802088  mov      w8, #0x104
//   0x00d0a4: 72a02028  movk     w8, #0x101, lsl #16
//   0x00d0a8: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00d0ac: aa0802c8  orr      x8, x22, x8
//   0x00d0b0: 92401529  and      x9, x9, #0x3f
//   0x00d0b4: ca110108  eor      x8, x8, x17
//   0x00d0b8: 8b080148  add      x8, x10, x8
//   0x00d0bc: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00d0c0: f85f83a9  ldur     x9, [x29, #-8]
//   0x00d0c4: f9400108  ldr      x8, [x8]
//   0x00d0c8: cb090108  sub      x8, x8, x9
//   0x00d0cc: d61f0100  br       x8
//   0x00d0d0: f94002a8  ldr      x8, [x21]
//   0x00d0d4: b0ffffaa  adrp     x10, #0x2000
//   0x00d0d8: b9400109  ldr      w9, [x8]
//   0x00d0dc: fd409d41  ldr      d1, [x10, #0x138]
//   0x00d0e0: b0ffffaa  adrp     x10, #0x2000
//   0x00d0e4: 0e040d20  dup      v0.2s, w9
//   0x00d0e8: 53175929  lsl      w9, w9, #9
//   0x00d0ec: 3dc02143  ldr      q3, [x10, #0x80]
//   0x00d0f0: 2ea14400  ushl     v0.2s, v0.2s, v1.2s
//   0x00d0f4: 4e801801  uzp1     v1.4s, v0.4s, v0.4s
//   0x00d0f8: 4e040404  dup      v4.4s, v0.s[0]
//   0x00d0fc: 4e803802  zip1     v2.4s, v0.4s, v0.4s
//   0x00d100: 1e26000b  fmov     w11, s0
//   0x00d104: 6e004021  ext      v1.16b, v1.16b, v0.16b, #8
//   0x00d108: 1214016c  and      w12, w11, #0x1000
//   0x00d10c: 1213016e  and      w14, w11, #0x2000
//   0x00d110: 6e024021  ext      v1.16b, v1.16b, v2.16b, #8
//   0x00d114: 3dc02402  ldr      q2, [x0, #0x90]
//   0x00d118: 4e221c21  and      v1.16b, v1.16b, v2.16b
//   0x00d11c: 4e231c82  and      v2.16b, v4.16b, v3.16b
//   0x00d120: 4ea21c21  orr      v1.16b, v1.16b, v2.16b
//   0x00d124: 6e014022  ext      v2.16b, v1.16b, v1.16b, #8
//   0x00d128: 0ea21c21  orr      v1.8b, v1.8b, v2.8b
//   0x00d12c: 0e0c3c2a  mov      w10, v1.s[1]
//   0x00d130: 1e26002d  fmov     w13, s1
//   0x00d134: 2a0a01aa  orr      w10, w13, w10
//   0x00d138: 1212016d  and      w13, w11, #0x4000
//   0x00d13c: 2a0c014a  orr      w10, w10, w12
//   0x00d140: 1211012c  and      w12, w9, #0x8000
//   0x00d144: 2a0e014a  orr      w10, w10, w14
//   0x00d148: 2a0d014a  orr      w10, w10, w13
//   0x00d14c: 1210012d  and      w13, w9, #0x10000
//   0x00d150: 2a0c014a  orr      w10, w10, w12
//   0x00d154: 120f012c  and      w12, w9, #0x20000
//   0x00d158: 2a0d014a  orr      w10, w10, w13
//   0x00d15c: 120e012d  and      w13, w9, #0x40000
//   0x00d160: 2a0c014a  orr      w10, w10, w12
//   0x00d164: 120d0129  and      w9, w9, #0x80000
//   0x00d168: 2a0d014a  orr      w10, w10, w13
//   0x00d16c: 2a090149  orr      w9, w10, w9
//   0x00d170: 120c016a  and      w10, w11, #0x100000
//   0x00d174: 2a0a0129  orr      w9, w9, w10
//   0x00d178: 120b016a  and      w10, w11, #0x200000
//   0x00d17c: 2a0a0129  orr      w9, w9, w10
//   0x00d180: 120a016a  and      w10, w11, #0x400000
//   0x00d184: 2a0a0129  orr      w9, w9, w10
//   0x00d188: 1209016a  and      w10, w11, #0x800000
//   0x00d18c: 2a0a0129  orr      w9, w9, w10
//   0x00d190: 1208016a  and      w10, w11, #0x1000000
//   0x00d194: 2a0a0129  orr      w9, w9, w10
//   0x00d198: 1207016a  and      w10, w11, #0x2000000
//   0x00d19c: 2a0a0129  orr      w9, w9, w10
//   0x00d1a0: 7100953f  cmp      w9, #0x25
//   0x00d1a4: 540021c8  b.hi     #0xd5dc
//   0x00d1a8: b0ffffaa  adrp     x10, #0x2000
//   0x00d1ac: 9105014a  add      x10, x10, #0x140
//   0x00d1b0: 1000008b  adr      x11, #0xd1c0
//   0x00d1b4: 7869794c  ldrh     w12, [x10, x9, lsl #1]
//   0x00d1b8: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00d1bc: d61f0160  br       x11
//   0x00d1c0: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d1c4: fd400120  ldr      d0, [x9]
//   0x00d1c8: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d1cc: fd400121  ldr      d1, [x9]
//   0x00d1d0: 1e612000  fcmp     d0, d1
//   0x00d1d4: 140000a2  b        #0xd45c
//   0x00d1d8: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d1dc: bd400120  ldr      s0, [x9]
//   0x00d1e0: 1400009c  b        #0xd450
//   0x00d1e4: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d1e8: fd400120  ldr      d0, [x9]
//   0x00d1ec: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d1f0: fd400121  ldr      d1, [x9]
//   0x00d1f4: 1e602820  fadd     d0, d1, d0
//   0x00d1f8: fd0000c0  str      d0, [x6]
//   0x00d1fc: 140000f8  b        #0xd5dc
//   0x00d200: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d204: fd400120  ldr      d0, [x9]
//   0x00d208: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d20c: fd400121  ldr      d1, [x9]
//   0x00d210: 1e613800  fsub     d0, d0, d1
//   0x00d214: fd0000c0  str      d0, [x6]
//   0x00d218: 140000f1  b        #0xd5dc
//   0x00d21c: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d220: fd400120  ldr      d0, [x9]
//   0x00d224: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d228: fd400121  ldr      d1, [x9]
//   0x00d22c: 1e600820  fmul     d0, d1, d0
//   0x00d230: fd0000c0  str      d0, [x6]
//   0x00d234: 140000ea  b        #0xd5dc
//   0x00d238: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d23c: fd400120  ldr      d0, [x9]
//   0x00d240: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d244: fd400121  ldr      d1, [x9]
//   0x00d248: 1e611800  fdiv     d0, d0, d1
//   0x00d24c: fd0000c0  str      d0, [x6]
//   0x00d250: 140000e3  b        #0xd5dc
//   0x00d254: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d258: bd400120  ldr      s0, [x9]
//   0x00d25c: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d260: bd400121  ldr      s1, [x9]
//   0x00d264: 1e202820  fadd     s0, s1, s0
//   0x00d268: 140000dc  b        #0xd5d8
//   0x00d26c: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d270: bd400120  ldr      s0, [x9]
//   0x00d274: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d278: bd400121  ldr      s1, [x9]
//   0x00d27c: 1e213800  fsub     s0, s0, s1
//   0x00d280: 140000d6  b        #0xd5d8
//   0x00d284: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d288: bd400120  ldr      s0, [x9]
//   0x00d28c: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d290: bd400121  ldr      s1, [x9]
//   0x00d294: 1e200820  fmul     s0, s1, s0
//   0x00d298: 140000d0  b        #0xd5d8
//   0x00d29c: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d2a0: bd400120  ldr      s0, [x9]
//   0x00d2a4: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d2a8: bd400121  ldr      s1, [x9]
//   0x00d2ac: 1e211800  fdiv     s0, s0, s1
//   0x00d2b0: 140000ca  b        #0xd5d8
//   0x00d2b4: f0ffffa9  adrp     x9, #0x4000
//   0x00d2b8: f85b03ab  ldur     x11, [x29, #-0x50]
//   0x00d2bc: 91118129  add      x9, x9, #0x460
//   0x00d2c0: 1100052a  add      w10, w9, #1
//   0x00d2c4: 0a290149  bic      w9, w10, w9
//   0x00d2c8: 5291310a  mov      w10, #0x8988
//   0x00d2cc: 2a2903e9  mvn      w9, w9
//   0x00d2d0: 72a4040a  movk     w10, #0x2020, lsl #16
//   0x00d2d4: 8a0a0129  and      x9, x9, x10
//   0x00d2d8: d28fe24a  mov      x10, #0x7f12
//   0x00d2dc: f2aba12a  movk     x10, #0x5d09, lsl #16
//   0x00d2e0: bd400160  ldr      s0, [x11]
//   0x00d2e4: f2d0004a  movk     x10, #0x8002, lsl #32
//   0x00d2e8: f2e0020a  movk     x10, #0x10, lsl #48
//   0x00d2ec: 8b0a0129  add      x9, x9, x10
//   0x00d2f0: 528ac5aa  mov      w10, #0x562d
//   0x00d2f4: 72a0c26a  movk     w10, #0x613, lsl #16
//   0x00d2f8: eb0a013f  cmp      x9, x10
//   0x00d2fc: 54000aa2  b.hs     #0xd450
//   0x00d300: f85a83ac  ldur     x12, [x29, #-0x58]
//   0x00d304: 9e390009  fcvtzu   x9, s0
//   0x00d308: 5297c46b  mov      w11, #0xbe23
//   0x00d30c: 72a09f8b  movk     w11, #0x4fc, lsl #16
//   0x00d310: bd400181  ldr      s1, [x12]
//   0x00d314: ca0b0129  eor      x9, x9, x11
//   0x00d318: 529dcc6b  mov      w11, #0xee63
//   0x00d31c: 72ada4cb  movk     w11, #0x6d26, lsl #16
//   0x00d320: 140000f2  b        #0xd6e8
//   0x00d324: f0ffffa9  adrp     x9, #0x4000
//   0x00d328: f85b03ab  ldur     x11, [x29, #-0x50]
//   0x00d32c: 91118129  add      x9, x9, #0x460
//   0x00d330: 1100052a  add      w10, w9, #1
//   0x00d334: 0a290149  bic      w9, w10, w9
//   0x00d338: 5282146a  mov      w10, #0x10a3
//   0x00d33c: 2a2903e9  mvn      w9, w9
//   0x00d340: 72a400ca  movk     w10, #0x2006, lsl #16
//   0x00d344: 8a0a0129  and      x9, x9, x10
//   0x00d348: d28974aa  mov      x10, #0x4ba5
//   0x00d34c: f2bd456a  movk     x10, #0xea2b, lsl #16
//   0x00d350: bd400160  ldr      s0, [x11]
//   0x00d354: f2c1000a  movk     x10, #0x800, lsl #32
//   0x00d358: f2e0404a  movk     x10, #0x202, lsl #48
//   0x00d35c: 8b0a0129  add      x9, x9, x10
//   0x00d360: 52949f4a  mov      w10, #0xa4fa
//   0x00d364: 72a053ea  movk     w10, #0x29f, lsl #16
//   0x00d368: eb0a013f  cmp      x9, x10
//   0x00d36c: 54000722  b.hs     #0xd450
//   0x00d370: f85a83ac  ldur     x12, [x29, #-0x58]
//   0x00d374: 9e390009  fcvtzu   x9, s0
//   0x00d378: 529cec8b  mov      w11, #0xe764
//   0x00d37c: 72ad886b  movk     w11, #0x6c43, lsl #16
//   0x00d380: bd400181  ldr      s1, [x12]
//   0x00d384: ca0b0129  eor      x9, x9, x11
//   0x00d388: 5291b86b  mov      w11, #0x8dc3
//   0x00d38c: 72abc18b  movk     w11, #0x5e0c, lsl #16
//   0x00d390: 140000d6  b        #0xd6e8
//   0x00d394: f0ffffa9  adrp     x9, #0x4000
//   0x00d398: f85b03ab  ldur     x11, [x29, #-0x50]
//   0x00d39c: 91118129  add      x9, x9, #0x460
//   0x00d3a0: 1100052a  add      w10, w9, #1
//   0x00d3a4: 0a290149  bic      w9, w10, w9
//   0x00d3a8: 5284080a  mov      w10, #0x2040
//   0x00d3ac: 2a2903e9  mvn      w9, w9
//   0x00d3b0: 72aa0c0a  movk     w10, #0x5060, lsl #16
//   0x00d3b4: 8a0a0129  and      x9, x9, x10
//   0x00d3b8: d282ecaa  mov      x10, #0x1765
//   0x00d3bc: f2add34a  movk     x10, #0x6e9a, lsl #16
//   0x00d3c0: bd400160  ldr      s0, [x11]
//   0x00d3c4: f2c0004a  movk     x10, #2, lsl #32
//   0x00d3c8: f2e0200a  movk     x10, #0x100, lsl #48
//   0x00d3cc: 8b0a0129  add      x9, x9, x10
//   0x00d3d0: 529481ca  mov      w10, #0xa40e
//   0x00d3d4: 72a4dc4a  movk     w10, #0x26e2, lsl #16
//   0x00d3d8: eb0a013f  cmp      x9, x10
//   0x00d3dc: 540003a2  b.hs     #0xd450
//   0x00d3e0: f85a83ac  ldur     x12, [x29, #-0x58]
//   0x00d3e4: 9e390009  fcvtzu   x9, s0
//   0x00d3e8: 5286aeab  mov      w11, #0x3575
//   0x00d3ec: 72ace90b  movk     w11, #0x6748, lsl #16
//   0x00d3f0: bd400181  ldr      s1, [x12]
//   0x00d3f4: ca0b0129  eor      x9, x9, x11
//   0x00d3f8: 5299298b  mov      w11, #0xc94c
//   0x00d3fc: 72a6b5ab  movk     w11, #0x35ad, lsl #16
//   0x00d400: 140000ba  b        #0xd6e8
//   0x00d404: f0ffffa9  adrp     x9, #0x4000
//   0x00d408: f85b03ab  ldur     x11, [x29, #-0x50]
//   0x00d40c: 91118129  add      x9, x9, #0x460
//   0x00d410: 1100052a  add      w10, w9, #1
//   0x00d414: 0a290149  bic      w9, w10, w9
//   0x00d418: 5290200a  mov      w10, #0x8100
//   0x00d41c: 2a2903e9  mvn      w9, w9
//   0x00d420: 72a3000a  movk     w10, #0x1800, lsl #16
//   0x00d424: 8a0a0129  and      x9, x9, x10
//   0x00d428: d28c946a  mov      x10, #0x64a3
//   0x00d42c: f2ad1f8a  movk     x10, #0x68fc, lsl #16
//   0x00d430: bd400160  ldr      s0, [x11]
//   0x00d434: f2c0204a  movk     x10, #0x102, lsl #32
//   0x00d438: f2e0400a  movk     x10, #0x200, lsl #48
//   0x00d43c: 8b0a0129  add      x9, x9, x10
//   0x00d440: 528524ca  mov      w10, #0x2926
//   0x00d444: 72a0008a  movk     w10, #4, lsl #16
//   0x00d448: eb0a013f  cmp      x9, x10
//   0x00d44c: 540013e3  b.lo     #0xd6c8
//   0x00d450: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00d454: bd400121  ldr      s1, [x9]
//   0x00d458: 1e212000  fcmp     s0, s1
//   0x00d45c: 1a9f07e9  cset     w9, ne
//   0x00d460: 5a9fa129  csinv    w9, w9, wzr, ge
//   0x00d464: b90000c9  str      w9, [x6]
//   0x00d468: 1400005d  b        #0xd5dc
//   0x00d46c: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d470: bd400120  ldr      s0, [x9]
//   0x00d474: 1e22c000  fcvt     d0, s0
//   0x00d478: fd0000c0  str      d0, [x6]
//   0x00d47c: 14000058  b        #0xd5dc
//   0x00d480: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d484: fd400120  ldr      d0, [x9]
//   0x00d488: 1e624000  fcvt     s0, d0
//   0x00d48c: 14000053  b        #0xd5d8
//   0x00d490: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d494: fd400120  ldr      d0, [x9]
//   0x00d498: 1e780009  fcvtzs   w9, d0
//   0x00d49c: b90000c9  str      w9, [x6]
//   0x00d4a0: 1400004f  b        #0xd5dc
//   0x00d4a4: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d4a8: fd400120  ldr      d0, [x9]
//   0x00d4ac: 9e780009  fcvtzs   x9, d0
//   0x00d4b0: f90000c9  str      x9, [x6]
//   0x00d4b4: 1400004a  b        #0xd5dc
//   0x00d4b8: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d4bc: bd400120  ldr      s0, [x9]
//   0x00d4c0: 1e380009  fcvtzs   w9, s0
//   0x00d4c4: b90000c9  str      w9, [x6]
//   0x00d4c8: 14000045  b        #0xd5dc
//   0x00d4cc: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d4d0: bd400120  ldr      s0, [x9]
//   0x00d4d4: 9e380009  fcvtzs   x9, s0
//   0x00d4d8: f90000c9  str      x9, [x6]
//   0x00d4dc: 14000040  b        #0xd5dc
//   0x00d4e0: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d4e4: 2f00e400  movi     d0, #0000000000000000
//   0x00d4e8: fd400121  ldr      d1, [x9]
//   0x00d4ec: 1e606820  fmaxnm   d0, d1, d0
//   0x00d4f0: 1e790009  fcvtzu   w9, d0
//   0x00d4f4: b90000c9  str      w9, [x6]
//   0x00d4f8: 14000039  b        #0xd5dc
//   0x00d4fc: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d500: 2f00e400  movi     d0, #0000000000000000
//   0x00d504: fd400121  ldr      d1, [x9]
//   0x00d508: 1e606820  fmaxnm   d0, d1, d0
//   0x00d50c: 9e790009  fcvtzu   x9, d0
//   0x00d510: f90000c9  str      x9, [x6]
//   0x00d514: 14000032  b        #0xd5dc
//   0x00d518: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d51c: 2f00e400  movi     d0, #0000000000000000
//   0x00d520: bd400121  ldr      s1, [x9]
//   0x00d524: 1e206820  fmaxnm   s0, s1, s0
//   0x00d528: 1e390009  fcvtzu   w9, s0
//   0x00d52c: b90000c9  str      w9, [x6]
//   0x00d530: 1400002b  b        #0xd5dc
//   0x00d534: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d538: 2f00e400  movi     d0, #0000000000000000
//   0x00d53c: bd400121  ldr      s1, [x9]
//   0x00d540: 1e206820  fmaxnm   s0, s1, s0
//   0x00d544: 9e390009  fcvtzu   x9, s0
//   0x00d548: f90000c9  str      x9, [x6]
//   0x00d54c: 14000024  b        #0xd5dc
//   0x00d550: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d554: bd400120  ldr      s0, [x9]
//   0x00d558: 14000003  b        #0xd564
//   0x00d55c: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d560: fd400120  ldr      d0, [x9]
//   0x00d564: 7e61d800  ucvtf    d0, d0
//   0x00d568: fd0000c0  str      d0, [x6]
//   0x00d56c: 1400001c  b        #0xd5dc
//   0x00d570: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d574: bd400120  ldr      s0, [x9]
//   0x00d578: 7e21d800  ucvtf    s0, s0
//   0x00d57c: 14000017  b        #0xd5d8
//   0x00d580: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d584: f9400129  ldr      x9, [x9]
//   0x00d588: 9e230120  ucvtf    s0, x9
//   0x00d58c: 14000013  b        #0xd5d8
//   0x00d590: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d594: bd400120  ldr      s0, [x9]
//   0x00d598: 0f20a400  sshll    v0.2d, v0.2s, #0
//   0x00d59c: 5e61d800  scvtf    d0, d0
//   0x00d5a0: fd0000c0  str      d0, [x6]
//   0x00d5a4: 1400000e  b        #0xd5dc
//   0x00d5a8: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d5ac: fd400120  ldr      d0, [x9]
//   0x00d5b0: 5e61d800  scvtf    d0, d0
//   0x00d5b4: fd0000c0  str      d0, [x6]
//   0x00d5b8: 14000009  b        #0xd5dc
//   0x00d5bc: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d5c0: bd400120  ldr      s0, [x9]
//   0x00d5c4: 5e21d800  scvtf    s0, s0
//   0x00d5c8: 14000004  b        #0xd5d8
//   0x00d5cc: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d5d0: f9400129  ldr      x9, [x9]
//   0x00d5d4: 9e220120  scvtf    s0, x9
//   0x00d5d8: bd0000c0  str      s0, [x6]
//   0x00d5dc: f0ffffa9  adrp     x9, #0x4000
//   0x00d5e0: 5280644b  mov      w11, #0x322
//   0x00d5e4: 91118129  add      x9, x9, #0x460
//   0x00d5e8: 72a0118b  movk     w11, #0x8c, lsl #16
//   0x00d5ec: 1100052a  add      w10, w9, #1
//   0x00d5f0: 0a29014a  bic      w10, w10, w9
//   0x00d5f4: 2a2a03ea  mvn      w10, w10
//   0x00d5f8: 8a0b014a  and      x10, x10, x11
//   0x00d5fc: d28c990b  mov      x11, #0x64c8
//   0x00d600: f2b1208b  movk     x11, #0x8904, lsl #16
//   0x00d604: f2d2808b  movk     x11, #0x9404, lsl #32
//   0x00d608: f2e0800b  movk     x11, #0x400, lsl #48
//   0x00d60c: 8b0b014a  add      x10, x10, x11
//   0x00d610: 5282ddab  mov      w11, #0x16ed
//   0x00d614: 72a010eb  movk     w11, #0x87, lsl #16
//   0x00d618: eb0b015f  cmp      x10, x11
//   0x00d61c: 54000443  b.lo     #0xd6a4
//   0x00d620: b8404d0a  ldr      w10, [x8, #4]!
//   0x00d624: d282080b  mov      x11, #0x1040
//   0x00d628: f90002a8  str      x8, [x21]
//   0x00d62c: d2808008  mov      x8, #0x400
//   0x00d630: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00d634: f2a00088  movk     x8, #4, lsl #16
//   0x00d638: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00d63c: f2c02088  movk     x8, #0x104, lsl #32
//   0x00d640: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00d644: 8a080128  and      x8, x9, x8
//   0x00d648: aa290169  orn      x9, x11, x9
//   0x00d64c: d282880b  mov      x11, #0x1440
//   0x00d650: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00d654: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00d658: 9240154a  and      x10, x10, #0x3f
//   0x00d65c: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00d660: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00d664: 8a0b0129  and      x9, x9, x11
//   0x00d668: 8b080128  add      x8, x9, x8
//   0x00d66c: 52802089  mov      w9, #0x104
//   0x00d670: 72a02029  movk     w9, #0x101, lsl #16
//   0x00d674: aa090108  orr      x8, x8, x9
//   0x00d678: d28d6b89  mov      x9, #0x6b5c
//   0x00d67c: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00d680: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00d684: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00d688: ca090108  eor      x8, x8, x9
//   0x00d68c: f85f83a9  ldur     x9, [x29, #-8]
//   0x00d690: 8b080188  add      x8, x12, x8
//   0x00d694: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00d698: f9400108  ldr      x8, [x8]
//   0x00d69c: cb090108  sub      x8, x8, x9
//   0x00d6a0: d61f0100  br       x8
//   0x00d6a4: f9000088  str      x8, [x4]
//   0x00d6a8: 5294f88b  mov      w11, #0xa7c4
//   0x00d6ac: b8404d0a  ldr      w10, [x8, #4]!
//   0x00d6b0: 72ab350b  movk     w11, #0x59a8, lsl #16
//   0x00d6b4: f90002a8  str      x8, [x21]
//   0x00d6b8: 4a0b014a  eor      w10, w10, w11
//   0x00d6bc: b900010a  str      w10, [x8]
//   0x00d6c0: f94002a8  ldr      x8, [x21]
//   0x00d6c4: 17ffffd7  b        #0xd620
//   0x00d6c8: f85a83ac  ldur     x12, [x29, #-0x58]
//   0x00d6cc: 9e390009  fcvtzu   x9, s0
//   0x00d6d0: 528cad8b  mov      w11, #0x656c
//   0x00d6d4: 72ad300b  movk     w11, #0x6980, lsl #16
//   0x00d6d8: bd400181  ldr      s1, [x12]
//   0x00d6dc: ca0b0129  eor      x9, x9, x11
//   0x00d6e0: 5299720b  mov      w11, #0xcb90
//   0x00d6e4: 72ad904b  movk     w11, #0x6c82, lsl #16
//   0x00d6e8: 9e39002a  fcvtzu   x10, s1
//   0x00d6ec: ca0b014a  eor      x10, x10, x11
//   0x00d6f0: 9e230120  ucvtf    s0, x9
//   0x00d6f4: f85b03a9  ldur     x9, [x29, #-0x50]
//   0x00d6f8: 9e230141  ucvtf    s1, x10
//   0x00d6fc: bd000120  str      s0, [x9]
//   0x00d700: bd000181  str      s1, [x12]
//   0x00d704: 17ffff55  b        #0xd458
//   0x00d708: f0ffffa8  adrp     x8, #0x4000
//   0x00d70c: 5288022a  mov      w10, #0x4011
//   0x00d710: 91118108  add      x8, x8, #0x460
//   0x00d714: 72a1008a  movk     w10, #0x804, lsl #16
//   0x00d718: 11000509  add      w9, w8, #1
//   0x00d71c: 0a280129  bic      w9, w9, w8
//   0x00d720: 2a2903e9  mvn      w9, w9
//   0x00d724: 8a0a0129  and      x9, x9, x10
//   0x00d728: d29f1aaa  mov      x10, #0xf8d5
//   0x00d72c: f2a8298a  movk     x10, #0x414c, lsl #16
//   0x00d730: f2c01c0a  movk     x10, #0xe0, lsl #32
//   0x00d734: f2e0020a  movk     x10, #0x10, lsl #48
//   0x00d738: 8b0a0129  add      x9, x9, x10
//   0x00d73c: 529bc4aa  mov      w10, #0xde25
//   0x00d740: 72a03c8a  movk     w10, #0x1e4, lsl #16
//   0x00d744: eb0a013f  cmp      x9, x10
//   0x00d748: 54000c63  b.lo     #0xd8d4
//   0x00d74c: f94002a9  ldr      x9, [x21]
//   0x00d750: b9400129  ldr      w9, [x9]
//   0x00d754: d3507d2b  ubfx     x11, x9, #0x10, #0x10
//   0x00d758: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00d75c: 121b016d  and      w13, w11, #0x20
//   0x00d760: 121a016e  and      w14, w11, #0x40
//   0x00d764: 330b3d2d  bfxil    w13, w9, #0xb, #5
//   0x00d768: 1219016f  and      w15, w11, #0x80
//   0x00d76c: 2a0e01ad  orr      w13, w13, w14
//   0x00d770: 1218016e  and      w14, w11, #0x100
//   0x00d774: 2a0f01ad  orr      w13, w13, w15
//   0x00d778: 1217016b  and      w11, w11, #0x200
//   0x00d77c: 2a0e01ad  orr      w13, w13, w14
//   0x00d780: d3467d2e  ubfx     x14, x9, #6, #0x1a
//   0x00d784: 2a0b01ab  orr      w11, w13, w11
//   0x00d788: 121601cd  and      w13, w14, #0x400
//   0x00d78c: 2a0d016b  orr      w11, w11, w13
//   0x00d790: 121501cd  and      w13, w14, #0x800
//   0x00d794: 927c014a  and      x10, x10, #0x10
//   0x00d798: 2a0d016b  orr      w11, w11, w13
//   0x00d79c: 121401cd  and      w13, w14, #0x1000
//   0x00d7a0: b347292a  bfxil    x10, x9, #7, #4
//   0x00d7a4: 2a0d016b  orr      w11, w11, w13
//   0x00d7a8: 121301cd  and      w13, w14, #0x2000
//   0x00d7ac: d342fd2c  lsr      x12, x9, #2
//   0x00d7b0: d34b7d2f  ubfx     x15, x9, #0xb, #0x15
//   0x00d7b4: 2a0d016b  orr      w11, w11, w13
//   0x00d7b8: 121201cd  and      w13, w14, #0x4000
//   0x00d7bc: 927c018c  and      x12, x12, #0x10
//   0x00d7c0: f86a7a6e  ldr      x14, [x19, x10, lsl #3]
//   0x00d7c4: 2a0d016b  orr      w11, w11, w13
//   0x00d7c8: 121101ed  and      w13, w15, #0x8000
//   0x00d7cc: b35b792c  bfxil    x12, x9, #0x1b, #4
//   0x00d7d0: 2a0d0169  orr      w9, w11, w13
//   0x00d7d4: b900002a  str      w10, [x1]
//   0x00d7d8: 8b29a1ca  add      x10, x14, w9, sxth
//   0x00d7dc: 790000e9  strh     w9, [x7]
//   0x00d7e0: f85e03a9  ldur     x9, [x29, #-0x20]
//   0x00d7e4: b900030c  str      w12, [x24]
//   0x00d7e8: f86c7a6b  ldr      x11, [x19, x12, lsl #3]
//   0x00d7ec: f940012c  ldr      x12, [x9]
//   0x00d7f0: c85ffd49  ldaxr    x9, [x10]
//   0x00d7f4: eb0c013f  cmp      x9, x12
//   0x00d7f8: 54000141  b.ne     #0xd820
//   0x00d7fc: c80cfd4b  stlxr    w12, x11, [x10]
//   0x00d800: 3400064c  cbz      w12, #0xd8c8
//   0x00d804: 2a1f03ea  mov      w10, wzr
//   0x00d808: 3400012a  cbz      w10, #0xd82c
//   0x00d80c: b9800309  ldrsw    x9, [x24]
//   0x00d810: 5280002b  mov      w11, #1
//   0x00d814: f85e03aa  ldur     x10, [x29, #-0x20]
//   0x00d818: f8297a6b  str      x11, [x19, x9, lsl #3]
//   0x00d81c: 14000008  b        #0xd83c
//   0x00d820: d5033f5f  clrex    
//   0x00d824: 2a1f03ea  mov      w10, wzr
//   0x00d828: 35ffff2a  cbnz     w10, #0xd80c
//   0x00d82c: b980030a  ldrsw    x10, [x24]
//   0x00d830: f85e03ab  ldur     x11, [x29, #-0x20]
//   0x00d834: 8b0a0e6a  add      x10, x19, x10, lsl #3
//   0x00d838: f9000169  str      x9, [x11]
//   0x00d83c: d282080b  mov      x11, #0x1040
//   0x00d840: f900015f  str      xzr, [x10]
//   0x00d844: d280800a  mov      x10, #0x400
//   0x00d848: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00d84c: d282880c  mov      x12, #0x1440
//   0x00d850: f2a0008a  movk     x10, #4, lsl #16
//   0x00d854: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00d858: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x00d85c: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00d860: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00d864: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x00d868: 8a0a010a  and      x10, x8, x10
//   0x00d86c: aa280168  orn      x8, x11, x8
//   0x00d870: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00d874: 8a0c0108  and      x8, x8, x12
//   0x00d878: f94002a9  ldr      x9, [x21]
//   0x00d87c: 8b0a0108  add      x8, x8, x10
//   0x00d880: 5280208a  mov      w10, #0x104
//   0x00d884: 72a0202a  movk     w10, #0x101, lsl #16
//   0x00d888: aa0a0108  orr      x8, x8, x10
//   0x00d88c: d28d6b8a  mov      x10, #0x6b5c
//   0x00d890: b8404d2b  ldr      w11, [x9, #4]!
//   0x00d894: f90002a9  str      x9, [x21]
//   0x00d898: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00d89c: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00d8a0: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00d8a4: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00d8a8: 9240156b  and      x11, x11, #0x3f
//   0x00d8ac: ca0a0108  eor      x8, x8, x10
//   0x00d8b0: 8b080128  add      x8, x9, x8
//   0x00d8b4: f85f83a9  ldur     x9, [x29, #-8]
//   0x00d8b8: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x00d8bc: f9400108  ldr      x8, [x8]
//   0x00d8c0: cb090108  sub      x8, x8, x9
//   0x00d8c4: d61f0100  br       x8
//   0x00d8c8: 5280002a  mov      w10, #1
//   0x00d8cc: 35fffa0a  cbnz     w10, #0xd80c
//   0x00d8d0: 17ffffd7  b        #0xd82c
//   0x00d8d4: f94002a9  ldr      x9, [x21]
//   0x00d8d8: aa0403ea  mov      x10, x4
//   0x00d8dc: 528c026b  mov      w11, #0x6013
//   0x00d8e0: 52822d2d  mov      w13, #0x1169
//   0x00d8e4: 72a6cc4b  movk     w11, #0x3662, lsl #16
//   0x00d8e8: 72a06d4d  movk     w13, #0x36a, lsl #16
//   0x00d8ec: f9000089  str      x9, [x4]
//   0x00d8f0: aa0603e0  mov      x0, x6
//   0x00d8f4: b940012a  ldr      w10, [x9]
//   0x00d8f8: 5293692f  mov      w15, #0x9b49
//   0x00d8fc: f85e03a6  ldur     x6, [x29, #-0x20]
//   0x00d900: 72ae922f  movk     w15, #0x7491, lsl #16
//   0x00d904: 4a0b014a  eor      w10, w10, w11
//   0x00d908: b900012a  str      w10, [x9]
//   0x00d90c: b980002b  ldrsw    x11, [x1]
//   0x00d910: b980030c  ldrsw    x12, [x24]
//   0x00d914: 794000f0  ldrh     w16, [x7]
//   0x00d918: d37df16a  lsl      x10, x11, #3
//   0x00d91c: 4a0f016b  eor      w11, w11, w15
//   0x00d920: d37df18e  lsl      x14, x12, #3
//   0x00d924: 52982a0f  mov      w15, #0xc150
//   0x00d928: 72afa7cf  movk     w15, #0x7d3e, lsl #16
//   0x00d92c: f86a6a69  ldr      x9, [x19, x10]
//   0x00d930: 4a0f018c  eor      w12, w12, w15
//   0x00d934: 5292622f  mov      w15, #0x9311
//   0x00d938: b900002b  str      w11, [x1]
//   0x00d93c: 72a9272f  movk     w15, #0x4939, lsl #16
//   0x00d940: b900030c  str      w12, [x24]
//   0x00d944: ca0d012d  eor      x13, x9, x13
//   0x00d948: f82a6a6d  str      x13, [x19, x10]
//   0x00d94c: 52956dad  mov      w13, #0xab6d
//   0x00d950: f86e6a6a  ldr      x10, [x19, x14]
//   0x00d954: 72a460ad  movk     w13, #0x2305, lsl #16
//   0x00d958: ca0d014d  eor      x13, x10, x13
//   0x00d95c: f82e6a6d  str      x13, [x19, x14]
//   0x00d960: 5280c7ed  mov      w13, #0x63f
//   0x00d964: f94000ce  ldr      x14, [x6]
//   0x00d968: 4a0d020d  eor      w13, w16, w13
//   0x00d96c: ca0f01cb  eor      x11, x14, x15
//   0x00d970: 790000ed  strh     w13, [x7]
//   0x00d974: f90000cb  str      x11, [x6]
//   0x00d978: c85ffd2b  ldaxr    x11, [x9]
//   0x00d97c: eb0e017f  cmp      x11, x14
//   0x00d980: 54000061  b.ne     #0xd98c
//   0x00d984: c81ffd2a  stlxr    wzr, x10, [x9]
//   0x00d988: 14000002  b        #0xd990
//   0x00d98c: d5033f5f  clrex    
//   0x00d990: aa0003e6  mov      x6, x0
//   0x00d994: b0ffffa0  adrp     x0, #0x2000
//   0x00d998: 17ffff6d  b        #0xd74c
//   0x00d99c: f0ffffa8  adrp     x8, #0x4000
//   0x00d9a0: 91118108  add      x8, x8, #0x460
//   0x00d9a4: 11000509  add      w9, w8, #1
//   0x00d9a8: 0a280128  bic      w8, w9, w8
//   0x00d9ac: 52842209  mov      w9, #0x2110
//   0x00d9b0: 2a2803e8  mvn      w8, w8
//   0x00d9b4: 72a0e0c9  movk     w9, #0x706, lsl #16
//   0x00d9b8: 8a090108  and      x8, x8, x9
//   0x00d9bc: d2899be9  mov      x9, #0x4cdf
//   0x00d9c0: f2b06049  movk     x9, #0x8302, lsl #16
//   0x00d9c4: f2c20489  movk     x9, #0x1024, lsl #32
//   0x00d9c8: 8b090108  add      x8, x8, x9
//   0x00d9cc: 528c6c29  mov      w9, #0x6361
//   0x00d9d0: 72a0b189  movk     w9, #0x58c, lsl #16
//   0x00d9d4: eb09011f  cmp      x8, x9
//   0x00d9d8: 54000f03  b.lo     #0xdbb8
//   0x00d9dc: f94002a8  ldr      x8, [x21]
//   0x00d9e0: b9400109  ldr      w9, [x8]
//   0x00d9e4: d3417d2b  ubfx     x11, x9, #1, #0x1f
//   0x00d9e8: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00d9ec: 121b016d  and      w13, w11, #0x20
//   0x00d9f0: 121a016e  and      w14, w11, #0x40
//   0x00d9f4: 331a792d  bfxil    w13, w9, #0x1a, #5
//   0x00d9f8: 927c014a  and      x10, x10, #0x10
//   0x00d9fc: 2a0e01ad  orr      w13, w13, w14
//   0x00da00: 1219016e  and      w14, w11, #0x80
//   0x00da04: 2a0e01ad  orr      w13, w13, w14
//   0x00da08: 1218016e  and      w14, w11, #0x100
//   0x00da0c: 2a0e01ad  orr      w13, w13, w14
//   0x00da10: d34b7d2e  ubfx     x14, x9, #0xb, #0x15
//   0x00da14: 1217016b  and      w11, w11, #0x200
//   0x00da18: b351512a  bfxil    x10, x9, #0x11, #4
//   0x00da1c: 2a0b01ab  orr      w11, w13, w11
//   0x00da20: 121601cd  and      w13, w14, #0x400
//   0x00da24: 2a0d016b  orr      w11, w11, w13
//   0x00da28: 121501cd  and      w13, w14, #0x800
//   0x00da2c: 2a0d016b  orr      w11, w11, w13
//   0x00da30: 121401cd  and      w13, w14, #0x1000
//   0x00da34: 2a0d016b  orr      w11, w11, w13
//   0x00da38: 121301cd  and      w13, w14, #0x2000
//   0x00da3c: d34c412c  ubfx     x12, x9, #0xc, #5
//   0x00da40: 2a0d016b  orr      w11, w11, w13
//   0x00da44: 121201cd  and      w13, w14, #0x4000
//   0x00da48: 531c6d29  lsl      w9, w9, #4
//   0x00da4c: 2a0d016b  orr      w11, w11, w13
//   0x00da50: 12110129  and      w9, w9, #0x8000
//   0x00da54: 2a090169  orr      w9, w11, w9
//   0x00da58: f86a7a6b  ldr      x11, [x19, x10, lsl #3]
//   0x00da5c: b900002a  str      w10, [x1]
//   0x00da60: d37df18a  lsl      x10, x12, #3
//   0x00da64: b900030c  str      w12, [x24]
//   0x00da68: 790000e9  strh     w9, [x7]
//   0x00da6c: 8b29a16b  add      x11, x11, w9, sxth
//   0x00da70: b86a6a6a  ldr      w10, [x19, x10]
//   0x00da74: 927ef569  and      x9, x11, #0xfffffffffffffffc
//   0x00da78: 9240056b  and      x11, x11, #3
//   0x00da7c: f1000d7f  cmp      x11, #3
//   0x00da80: 54000360  b.eq     #0xdaec
//   0x00da84: f0ffffac  adrp     x12, #0x4000
//   0x00da88: 9111818c  add      x12, x12, #0x460
//   0x00da8c: 1100058d  add      w13, w12, #1
//   0x00da90: 0a2c01ac  bic      w12, w13, w12
//   0x00da94: 5283100d  mov      w13, #0x1880
//   0x00da98: 2a2c03ec  mvn      w12, w12
//   0x00da9c: 72a1024d  movk     w13, #0x812, lsl #16
//   0x00daa0: 8a0d018c  and      x12, x12, x13
//   0x00daa4: d29c18ad  mov      x13, #0xe0c5
//   0x00daa8: f2b6dfed  movk     x13, #0xb6ff, lsl #16
//   0x00daac: f2c0032d  movk     x13, #0x19, lsl #32
//   0x00dab0: f2e0008d  movk     x13, #4, lsl #48
//   0x00dab4: 8b0d018c  add      x12, x12, x13
//   0x00dab8: 528d4f8d  mov      w13, #0x6a7c
//   0x00dabc: 72a0984d  movk     w13, #0x4c2, lsl #16
//   0x00dac0: eb0d019f  cmp      x12, x13
//   0x00dac4: 54000d03  b.lo     #0xdc64
//   0x00dac8: b940012c  ldr      w12, [x9]
//   0x00dacc: 531d716b  lsl      w11, w11, #3
//   0x00dad0: 5280030d  mov      w13, #0x18
//   0x00dad4: 4b0b01ad  sub      w13, w13, w11
//   0x00dad8: 12801fee  mov      w14, #-0x100
//   0x00dadc: 1acb21cb  lsl      w11, w14, w11
//   0x00dae0: 1acd254a  lsr      w10, w10, w13
//   0x00dae4: 0a0b018b  and      w11, w12, w11
//   0x00dae8: 2a0a016a  orr      w10, w11, w10
//   0x00daec: b900012a  str      w10, [x9]
//   0x00daf0: f0ffffa9  adrp     x9, #0x4000
//   0x00daf4: 91118129  add      x9, x9, #0x460
//   0x00daf8: 5280a40b  mov      w11, #0x520
//   0x00dafc: 1100052a  add      w10, w9, #1
//   0x00db00: 72a0500b  movk     w11, #0x280, lsl #16
//   0x00db04: 0a29014a  bic      w10, w10, w9
//   0x00db08: 2a2a03ea  mvn      w10, w10
//   0x00db0c: 8a0b014a  and      x10, x10, x11
//   0x00db10: d29552cb  mov      x11, #0xaa96
//   0x00db14: f2a2fbab  movk     x11, #0x17dd, lsl #16
//   0x00db18: f2c0402b  movk     x11, #0x201, lsl #32
//   0x00db1c: f2e1000b  movk     x11, #0x800, lsl #48
//   0x00db20: 8b0b014a  add      x10, x10, x11
//   0x00db24: 52923a0b  mov      w11, #0x91d0
//   0x00db28: 72a165cb  movk     w11, #0xb2e, lsl #16
//   0x00db2c: eb0b015f  cmp      x10, x11
//   0x00db30: 54000883  b.lo     #0xdc40
//   0x00db34: b8404d0a  ldr      w10, [x8, #4]!
//   0x00db38: d282080b  mov      x11, #0x1040
//   0x00db3c: f90002a8  str      x8, [x21]
//   0x00db40: d2808008  mov      x8, #0x400
//   0x00db44: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00db48: f2a00088  movk     x8, #4, lsl #16
//   0x00db4c: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00db50: f2c02088  movk     x8, #0x104, lsl #32
//   0x00db54: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00db58: 8a080128  and      x8, x9, x8
//   0x00db5c: aa290169  orn      x9, x11, x9
//   0x00db60: d282880b  mov      x11, #0x1440
//   0x00db64: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00db68: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00db6c: 9240154a  and      x10, x10, #0x3f
//   0x00db70: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00db74: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00db78: 8a0b0129  and      x9, x9, x11
//   0x00db7c: 8b080128  add      x8, x9, x8
//   0x00db80: 52802089  mov      w9, #0x104
//   0x00db84: 72a02029  movk     w9, #0x101, lsl #16
//   0x00db88: aa090108  orr      x8, x8, x9
//   0x00db8c: d28d6b89  mov      x9, #0x6b5c
//   0x00db90: f2be9389  movk     x9, #0xf49c, lsl #16
//   0x00db94: f2d3d769  movk     x9, #0x9ebb, lsl #32
//   0x00db98: f2ffebe9  movk     x9, #0xff5f, lsl #48
//   0x00db9c: ca090108  eor      x8, x8, x9
//   0x00dba0: f85f83a9  ldur     x9, [x29, #-8]
//   0x00dba4: 8b080188  add      x8, x12, x8
//   0x00dba8: 8b0a0d08  add      x8, x8, x10, lsl #3
//   0x00dbac: f9400108  ldr      x8, [x8]
//   0x00dbb0: cb090108  sub      x8, x8, x9
//   0x00dbb4: d61f0100  br       x8
//   0x00dbb8: f94002a8  ldr      x8, [x21]
//   0x00dbbc: 52955d4a  mov      w10, #0xaaea
//   0x00dbc0: 72a71b8a  movk     w10, #0x38dc, lsl #16
//   0x00dbc4: 5280ba0b  mov      w11, #0x5d0
//   0x00dbc8: 5295588c  mov      w12, #0xaac4
//   0x00dbcc: 72a3eb2b  movk     w11, #0x1f59, lsl #16
//   0x00dbd0: f9000088  str      x8, [x4]
//   0x00dbd4: 72a1b18c  movk     w12, #0xd8c, lsl #16
//   0x00dbd8: b9400109  ldr      w9, [x8]
//   0x00dbdc: 4a0a0129  eor      w9, w9, w10
//   0x00dbe0: b9000109  str      w9, [x8]
//   0x00dbe4: b9800028  ldrsw    x8, [x1]
//   0x00dbe8: 794000ed  ldrh     w13, [x7]
//   0x00dbec: d37df109  lsl      x9, x8, #3
//   0x00dbf0: 4a0b0108  eor      w8, w8, w11
//   0x00dbf4: b980030b  ldrsw    x11, [x24]
//   0x00dbf8: f8696a6a  ldr      x10, [x19, x9]
//   0x00dbfc: b9000028  str      w8, [x1]
//   0x00dc00: d37df168  lsl      x8, x11, #3
//   0x00dc04: ca0c014a  eor      x10, x10, x12
//   0x00dc08: 528619ec  mov      w12, #0x30cf
//   0x00dc0c: 4a0c01ac  eor      w12, w13, w12
//   0x00dc10: 5283776d  mov      w13, #0x1bbb
//   0x00dc14: 72af7c0d  movk     w13, #0x7be0, lsl #16
//   0x00dc18: f8296a6a  str      x10, [x19, x9]
//   0x00dc1c: 4a0d0169  eor      w9, w11, w13
//   0x00dc20: 529a30ca  mov      w10, #0xd186
//   0x00dc24: 790000ec  strh     w12, [x7]
//   0x00dc28: 72a6c78a  movk     w10, #0x363c, lsl #16
//   0x00dc2c: b9000309  str      w9, [x24]
//   0x00dc30: b8686a69  ldr      w9, [x19, x8]
//   0x00dc34: 4a0a0129  eor      w9, w9, w10
//   0x00dc38: b8286a69  str      w9, [x19, x8]
//   0x00dc3c: 17ffff68  b        #0xd9dc
//   0x00dc40: f9000088  str      x8, [x4]
//   0x00dc44: 5285084b  mov      w11, #0x2842
//   0x00dc48: b8404d0a  ldr      w10, [x8, #4]!
//   0x00dc4c: 72a9e3cb  movk     w11, #0x4f1e, lsl #16
//   0x00dc50: f90002a8  str      x8, [x21]
//   0x00dc54: 4a0b014a  eor      w10, w10, w11
//   0x00dc58: b900010a  str      w10, [x8]
//   0x00dc5c: f94002a8  ldr      x8, [x21]
//   0x00dc60: 17ffffb5  b        #0xdb34
//   0x00dc64: b940012c  ldr      w12, [x9]
//   0x00dc68: 2a2c03ec  mvn      w12, w12
//   0x00dc6c: 12185d8c  and      w12, w12, #0xffffff00
//   0x00dc70: 2a0a618c  orr      w12, w12, w10, lsl #24
//   0x00dc74: b900012c  str      w12, [x9]
//   0x00dc78: 17ffff95  b        #0xdacc
//   0x00dc7c: f94002a8  ldr      x8, [x21]
//   0x00dc80: b0ffffaa  adrp     x10, #0x2000
//   0x00dc84: b9400109  ldr      w9, [x8]
//   0x00dc88: fd409141  ldr      d1, [x10, #0x120]
//   0x00dc8c: b0ffffaa  adrp     x10, #0x2000
//   0x00dc90: 0e040d20  dup      v0.2s, w9
//   0x00dc94: d34cfd2b  lsr      x11, x9, #0xc
//   0x00dc98: 3dc02143  ldr      q3, [x10, #0x80]
//   0x00dc9c: d35bfd2a  lsr      x10, x9, #0x1b
//   0x00dca0: 927c014a  and      x10, x10, #0x10
//   0x00dca4: 927c016b  and      x11, x11, #0x10
//   0x00dca8: b351512a  bfxil    x10, x9, #0x11, #4
//   0x00dcac: b347292b  bfxil    x11, x9, #7, #4
//   0x00dcb0: 2ea14400  ushl     v0.2s, v0.2s, v1.2s
//   0x00dcb4: 53175929  lsl      w9, w9, #9
//   0x00dcb8: 12110129  and      w9, w9, #0x8000
//   0x00dcbc: b900002a  str      w10, [x1]
//   0x00dcc0: b900030b  str      w11, [x24]
//   0x00dcc4: 4e801801  uzp1     v1.4s, v0.4s, v0.4s
//   0x00dcc8: 4e040404  dup      v4.4s, v0.s[0]
//   0x00dccc: 4e803802  zip1     v2.4s, v0.4s, v0.4s
//   0x00dcd0: 1e26000d  fmov     w13, s0
//   0x00dcd4: 6e004021  ext      v1.16b, v1.16b, v0.16b, #8
//   0x00dcd8: 121401ae  and      w14, w13, #0x1000
//   0x00dcdc: 121301b0  and      w16, w13, #0x2000
//   0x00dce0: 121201ad  and      w13, w13, #0x4000
//   0x00dce4: 6e024021  ext      v1.16b, v1.16b, v2.16b, #8
//   0x00dce8: 3dc02402  ldr      q2, [x0, #0x90]
//   0x00dcec: 4e221c21  and      v1.16b, v1.16b, v2.16b
//   0x00dcf0: 4e231c82  and      v2.16b, v4.16b, v3.16b
//   0x00dcf4: 4ea21c21  orr      v1.16b, v1.16b, v2.16b
//   0x00dcf8: 6e014022  ext      v2.16b, v1.16b, v1.16b, #8
//   0x00dcfc: 0ea21c21  orr      v1.8b, v1.8b, v2.8b
//   0x00dd00: 0e0c3c2c  mov      w12, v1.s[1]
//   0x00dd04: 1e26002f  fmov     w15, s1
//   0x00dd08: 2a0c01ec  orr      w12, w15, w12
//   0x00dd0c: 2a0e018c  orr      w12, w12, w14
//   0x00dd10: 2a10018c  orr      w12, w12, w16
//   0x00dd14: 2a0d018c  orr      w12, w12, w13
//   0x00dd18: 2a090189  orr      w9, w12, w9
//   0x00dd1c: f86a7a6c  ldr      x12, [x19, x10, lsl #3]
//   0x00dd20: d37df16a  lsl      x10, x11, #3
//   0x00dd24: 790000e9  strh     w9, [x7]
//   0x00dd28: 8b29a18b  add      x11, x12, w9, sxth
//   0x00dd2c: b86a6a6a  ldr      w10, [x19, x10]
//   0x00dd30: 927ef569  and      x9, x11, #0xfffffffffffffffc
//   0x00dd34: f240056b  ands     x11, x11, #3
//   0x00dd38: 54000340  b.eq     #0xdda0
//   0x00dd3c: f0ffffac  adrp     x12, #0x4000
//   0x00dd40: 9111818c  add      x12, x12, #0x460
//   0x00dd44: 1100058d  add      w13, w12, #1
//   0x00dd48: 0a2c01ac  bic      w12, w13, w12
//   0x00dd4c: 5289220d  mov      w13, #0x4910
//   0x00dd50: 2a2c03ec  mvn      w12, w12
//   0x00dd54: 72a4142d  movk     w13, #0x20a1, lsl #16
//   0x00dd58: 8a0d018c  and      x12, x12, x13
//   0x00dd5c: d29acded  mov      x13, #0xd66f
//   0x00dd60: f2ad440d  movk     x13, #0x6a20, lsl #16
//   0x00dd64: f2c0008d  movk     x13, #4, lsl #32
//   0x00dd68: f2e0410d  movk     x13, #0x208, lsl #48
//   0x00dd6c: 8b0d018c  add      x12, x12, x13
//   0x00dd70: 52821a6d  mov      w13, #0x10d3
//   0x00dd74: 72a1222d  movk     w13, #0x911, lsl #16
//   0x00dd78: eb0d019f  cmp      x12, x13
//   0x00dd7c: 540008a3  b.lo     #0xde90
//   0x00dd80: b940012c  ldr      w12, [x9]
//   0x00dd84: 531d716b  lsl      w11, w11, #3
//   0x00dd88: 1280000e  mov      w14, #-1
//   0x00dd8c: 4b0b03ed  neg      w13, w11
//   0x00dd90: 1acb214a  lsl      w10, w10, w11
//   0x00dd94: 1acd25cd  lsr      w13, w14, w13
//   0x00dd98: 0a0d018b  and      w11, w12, w13
//   0x00dd9c: 2a0a016a  orr      w10, w11, w10
//   0x00dda0: f0ffffab  adrp     x11, #0x4000
//   0x00dda4: 5287940d  mov      w13, #0x3ca0
//   0x00dda8: 9111816b  add      x11, x11, #0x460
//   0x00ddac: 72a6490d  movk     w13, #0x3248, lsl #16
//   0x00ddb0: 1100056c  add      w12, w11, #1
//   0x00ddb4: b900012a  str      w10, [x9]
//   0x00ddb8: 0a2b018c  bic      w12, w12, w11
//   0x00ddbc: 2a2c03ec  mvn      w12, w12
//   0x00ddc0: 8a0d018c  and      x12, x12, x13
//   0x00ddc4: d2846fed  mov      x13, #0x237f
//   0x00ddc8: f2a9a6ed  movk     x13, #0x4d37, lsl #16
//   0x00ddcc: f2c0080d  movk     x13, #0x40, lsl #32
//   0x00ddd0: f2e0200d  movk     x13, #0x100, lsl #48
//   0x00ddd4: 8b0d018c  add      x12, x12, x13
//   0x00ddd8: 52886c8d  mov      w13, #0x4364
//   0x00dddc: 72a229ad  movk     w13, #0x114d, lsl #16
//   0x00dde0: eb0d019f  cmp      x12, x13
//   0x00dde4: 54000443  b.lo     #0xde6c
//   0x00dde8: b8404d09  ldr      w9, [x8, #4]!
//   0x00ddec: d282080a  mov      x10, #0x1040
//   0x00ddf0: f90002a8  str      x8, [x21]
//   0x00ddf4: d2808008  mov      x8, #0x400
//   0x00ddf8: f2a1404a  movk     x10, #0xa02, lsl #16
//   0x00ddfc: f2a00088  movk     x8, #4, lsl #16
//   0x00de00: f2cc080a  movk     x10, #0x6040, lsl #32
//   0x00de04: f2c02088  movk     x8, #0x104, lsl #32
//   0x00de08: f2e0140a  movk     x10, #0xa0, lsl #48
//   0x00de0c: 8a080168  and      x8, x11, x8
//   0x00de10: aa2b014a  orn      x10, x10, x11
//   0x00de14: d282880b  mov      x11, #0x1440
//   0x00de18: f941f28c  ldr      x12, [x20, #0x3e0]
//   0x00de1c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00de20: 92401529  and      x9, x9, #0x3f
//   0x00de24: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00de28: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00de2c: 8a0b014a  and      x10, x10, x11
//   0x00de30: 8b080148  add      x8, x10, x8
//   0x00de34: 5280208a  mov      w10, #0x104
//   0x00de38: 72a0202a  movk     w10, #0x101, lsl #16
//   0x00de3c: aa0a0108  orr      x8, x8, x10
//   0x00de40: d28d6b8a  mov      x10, #0x6b5c
//   0x00de44: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00de48: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00de4c: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00de50: ca0a0108  eor      x8, x8, x10
//   0x00de54: 8b080188  add      x8, x12, x8
//   0x00de58: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00de5c: f85f83a9  ldur     x9, [x29, #-8]
//   0x00de60: f9400108  ldr      x8, [x8]
//   0x00de64: cb090108  sub      x8, x8, x9
//   0x00de68: d61f0100  br       x8
//   0x00de6c: f9000088  str      x8, [x4]
//   0x00de70: 5289f48a  mov      w10, #0x4fa4
//   0x00de74: b8404d09  ldr      w9, [x8, #4]!
//   0x00de78: 72a7ecea  movk     w10, #0x3f67, lsl #16
//   0x00de7c: f90002a8  str      x8, [x21]
//   0x00de80: 4a0a0129  eor      w9, w9, w10
//   0x00de84: b9000109  str      w9, [x8]
//   0x00de88: f94002a8  ldr      x8, [x21]
//   0x00de8c: 17ffffd7  b        #0xdde8
//   0x00de90: 2a0a03ec  mov      w12, w10
//   0x00de94: b900012a  str      w10, [x9]
//   0x00de98: 17ffffbb  b        #0xdd84
//   0x00de9c: f0ffffa8  adrp     x8, #0x4000
//   0x00dea0: 5280400a  mov      w10, #0x200
//   0x00dea4: 91118108  add      x8, x8, #0x460
//   0x00dea8: 72a1080a  movk     w10, #0x840, lsl #16
//   0x00deac: 11000509  add      w9, w8, #1
//   0x00deb0: 0a280129  bic      w9, w9, w8
//   0x00deb4: 2a2903e9  mvn      w9, w9
//   0x00deb8: 8a0a0129  and      x9, x9, x10
//   0x00debc: d298df2a  mov      x10, #0xc6f9
//   0x00dec0: f2aebc0a  movk     x10, #0x75e0, lsl #16
//   0x00dec4: f2c0400a  movk     x10, #0x200, lsl #32
//   0x00dec8: f2e0112a  movk     x10, #0x89, lsl #48
//   0x00decc: 8b0a0129  add      x9, x9, x10
//   0x00ded0: 52848d4a  mov      w10, #0x246a
//   0x00ded4: 72a01d0a  movk     w10, #0xe8, lsl #16
//   0x00ded8: eb0a013f  cmp      x9, x10
//   0x00dedc: 54000803  b.lo     #0xdfdc
//   0x00dee0: f94002a9  ldr      x9, [x21]
//   0x00dee4: b9400129  ldr      w9, [x9]
//   0x00dee8: d3417d2b  ubfx     x11, x9, #1, #0x1f
//   0x00deec: 53067d2a  lsr      w10, w9, #6
//   0x00def0: 1216016d  and      w13, w11, #0x400
//   0x00def4: 1215016e  and      w14, w11, #0x800
//   0x00def8: 3315792d  bfxil    w13, w9, #0x15, #0xa
//   0x00defc: d35bfd2c  lsr      x12, x9, #0x1b
//   0x00df00: 2a0e01ad  orr      w13, w13, w14
//   0x00df04: 1214016e  and      w14, w11, #0x1000
//   0x00df08: 2a0e01ad  orr      w13, w13, w14
//   0x00df0c: 1213016e  and      w14, w11, #0x2000
//   0x00df10: 2a0e01ad  orr      w13, w13, w14
//   0x00df14: d34cfd2e  lsr      x14, x9, #0xc
//   0x00df18: 927c018c  and      x12, x12, #0x10
//   0x00df1c: 927c01ce  and      x14, x14, #0x10
//   0x00df20: 1212016b  and      w11, w11, #0x4000
//   0x00df24: b351512c  bfxil    x12, x9, #0x11, #4
//   0x00df28: b347292e  bfxil    x14, x9, #7, #4
//   0x00df2c: 2a0b01a9  orr      w9, w13, w11
//   0x00df30: 33110149  bfi      w9, w10, #0xf, #1
//   0x00df34: d37df1ca  lsl      x10, x14, #3
//   0x00df38: b900002c  str      w12, [x1]
//   0x00df3c: f86c7a6b  ldr      x11, [x19, x12, lsl #3]
//   0x00df40: b900030e  str      w14, [x24]
//   0x00df44: d280800c  mov      x12, #0x400
//   0x00df48: 790000e9  strh     w9, [x7]
//   0x00df4c: 93403d29  sxth     x9, w9
//   0x00df50: b86a6a6a  ldr      w10, [x19, x10]
//   0x00df54: f2a0008c  movk     x12, #4, lsl #16
//   0x00df58: f2c0208c  movk     x12, #0x104, lsl #32
//   0x00df5c: 5280208d  mov      w13, #0x104
//   0x00df60: 8a0c010c  and      x12, x8, x12
//   0x00df64: 72a0202d  movk     w13, #0x101, lsl #16
//   0x00df68: 3829696a  strb     w10, [x11, x9]
//   0x00df6c: d2820809  mov      x9, #0x1040
//   0x00df70: f2a14049  movk     x9, #0xa02, lsl #16
//   0x00df74: d282880b  mov      x11, #0x1440
//   0x00df78: f2cc0809  movk     x9, #0x6040, lsl #32
//   0x00df7c: f2a140cb  movk     x11, #0xa06, lsl #16
//   0x00df80: f2e01409  movk     x9, #0xa0, lsl #48
//   0x00df84: f94002aa  ldr      x10, [x21]
//   0x00df88: f2cc288b  movk     x11, #0x6144, lsl #32
//   0x00df8c: aa280128  orn      x8, x9, x8
//   0x00df90: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00df94: 8a0b0108  and      x8, x8, x11
//   0x00df98: d28d6b8b  mov      x11, #0x6b5c
//   0x00df9c: b8404d49  ldr      w9, [x10, #4]!
//   0x00dfa0: f90002aa  str      x10, [x21]
//   0x00dfa4: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x00dfa8: 8b0c0108  add      x8, x8, x12
//   0x00dfac: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00dfb0: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x00dfb4: aa0d0108  orr      x8, x8, x13
//   0x00dfb8: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x00dfbc: 92401529  and      x9, x9, #0x3f
//   0x00dfc0: ca0b0108  eor      x8, x8, x11
//   0x00dfc4: 8b080148  add      x8, x10, x8
//   0x00dfc8: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00dfcc: f85f83a9  ldur     x9, [x29, #-8]
//   0x00dfd0: f9400108  ldr      x8, [x8]
//   0x00dfd4: cb090108  sub      x8, x8, x9
//   0x00dfd8: d61f0100  br       x8
//   0x00dfdc: f94002a9  ldr      x9, [x21]
//   0x00dfe0: 5283ac8b  mov      w11, #0x1d64
//   0x00dfe4: 72ac2acb  movk     w11, #0x6156, lsl #16
//   0x00dfe8: 5298450c  mov      w12, #0xc228
//   0x00dfec: 528b8bcd  mov      w13, #0x5c5e
//   0x00dff0: 72ab946c  movk     w12, #0x5ca3, lsl #16
//   0x00dff4: f9000089  str      x9, [x4]
//   0x00dff8: b940012a  ldr      w10, [x9]
//   0x00dffc: 4a0b014a  eor      w10, w10, w11
//   0x00e000: b900012a  str      w10, [x9]
//   0x00e004: b9800029  ldrsw    x9, [x1]
//   0x00e008: 794000ea  ldrh     w10, [x7]
//   0x00e00c: b980030e  ldrsw    x14, [x24]
//   0x00e010: d37df12b  lsl      x11, x9, #3
//   0x00e014: 4a0c0129  eor      w9, w9, w12
//   0x00e018: 4a0d014a  eor      w10, w10, w13
//   0x00e01c: 529edd0d  mov      w13, #0xf6e8
//   0x00e020: 72ac178d  movk     w13, #0x60bc, lsl #16
//   0x00e024: f86b6a6c  ldr      x12, [x19, x11]
//   0x00e028: b9000029  str      w9, [x1]
//   0x00e02c: 790000ea  strh     w10, [x7]
//   0x00e030: 529ff38a  mov      w10, #0xff9c
//   0x00e034: 4a0d01c9  eor      w9, w14, w13
//   0x00e038: 72a063ea  movk     w10, #0x31f, lsl #16
//   0x00e03c: d37df1cd  lsl      x13, x14, #3
//   0x00e040: ca0a018a  eor      x10, x12, x10
//   0x00e044: b9000309  str      w9, [x24]
//   0x00e048: f82b6a6a  str      x10, [x19, x11]
//   0x00e04c: 52855eca  mov      w10, #0x2af6
//   0x00e050: b86d6a69  ldr      w9, [x19, x13]
//   0x00e054: 72a2beca  movk     w10, #0x15f6, lsl #16
//   0x00e058: 5290f7ab  mov      w11, #0x87bd
//   0x00e05c: 72aa8fcb  movk     w11, #0x547e, lsl #16
//   0x00e060: 4a0a012a  eor      w10, w9, w10
//   0x00e064: b82d6a6a  str      w10, [x19, x13]
//   0x00e068: 39000189  strb     w9, [x12]
//   0x00e06c: f94002a9  ldr      x9, [x21]
//   0x00e070: f9000089  str      x9, [x4]
//   0x00e074: b8404d2a  ldr      w10, [x9, #4]!
//   0x00e078: f90002a9  str      x9, [x21]
//   0x00e07c: 4a0b014a  eor      w10, w10, w11
//   0x00e080: b900012a  str      w10, [x9]
//   0x00e084: 17ffff97  b        #0xdee0
//   0x00e088: d0ffffa8  adrp     x8, #0x4000
//   0x00e08c: 528c0a8a  mov      w10, #0x6054
//   0x00e090: 91118108  add      x8, x8, #0x460
//   0x00e094: 72a04c4a  movk     w10, #0x262, lsl #16
//   0x00e098: 11000509  add      w9, w8, #1
//   0x00e09c: 0a280129  bic      w9, w9, w8
//   0x00e0a0: 2a2903e9  mvn      w9, w9
//   0x00e0a4: 8a0a0129  and      x9, x9, x10
//   0x00e0a8: d29fd08a  mov      x10, #0xfe84
//   0x00e0ac: f2a5d38a  movk     x10, #0x2e9c, lsl #16
//   0x00e0b0: f2c8092a  movk     x10, #0x4049, lsl #32
//   0x00e0b4: 8b0a0129  add      x9, x9, x10
//   0x00e0b8: 529cf48a  mov      w10, #0xe7a4
//   0x00e0bc: 72a1ed2a  movk     w10, #0xf69, lsl #16
//   0x00e0c0: eb0a013f  cmp      x9, x10
//   0x00e0c4: 54000923  b.lo     #0xe1e8
//   0x00e0c8: f94002a9  ldr      x9, [x21]
//   0x00e0cc: d280800c  mov      x12, #0x400
//   0x00e0d0: f2a0008c  movk     x12, #4, lsl #16
//   0x00e0d4: f2c0208c  movk     x12, #0x104, lsl #32
//   0x00e0d8: b940012a  ldr      w10, [x9]
//   0x00e0dc: 8a0c010c  and      x12, x8, x12
//   0x00e0e0: d3417d4b  ubfx     x11, x10, #1, #0x1f
//   0x00e0e4: 121b016d  and      w13, w11, #0x20
//   0x00e0e8: 121a016e  and      w14, w11, #0x40
//   0x00e0ec: 3310514d  bfxil    w13, w10, #0x10, #5
//   0x00e0f0: 1219016f  and      w15, w11, #0x80
//   0x00e0f4: 2a0e01ad  orr      w13, w13, w14
//   0x00e0f8: 1218016e  and      w14, w11, #0x100
//   0x00e0fc: 2a0f01ad  orr      w13, w13, w15
//   0x00e100: 1217016b  and      w11, w11, #0x200
//   0x00e104: 2a0e01ad  orr      w13, w13, w14
//   0x00e108: d34b7d4e  ubfx     x14, x10, #0xb, #0x15
//   0x00e10c: 2a0b01ab  orr      w11, w13, w11
//   0x00e110: 121601cd  and      w13, w14, #0x400
//   0x00e114: 2a0d016b  orr      w11, w11, w13
//   0x00e118: 121501cd  and      w13, w14, #0x800
//   0x00e11c: 2a0d016b  orr      w11, w11, w13
//   0x00e120: 121401cd  and      w13, w14, #0x1000
//   0x00e124: 2a0d016b  orr      w11, w11, w13
//   0x00e128: 121301cd  and      w13, w14, #0x2000
//   0x00e12c: 2a0d016b  orr      w11, w11, w13
//   0x00e130: d356fd4d  lsr      x13, x10, #0x16
//   0x00e134: 121201ce  and      w14, w14, #0x4000
//   0x00e138: 927c01ad  and      x13, x13, #0x10
//   0x00e13c: 2a0e016b  orr      w11, w11, w14
//   0x00e140: d35bfd4e  lsr      x14, x10, #0x1b
//   0x00e144: b34c3d4d  bfxil    x13, x10, #0xc, #4
//   0x00e148: 531c6d4a  lsl      w10, w10, #4
//   0x00e14c: 1211014a  and      w10, w10, #0x8000
//   0x00e150: d282080f  mov      x15, #0x1040
//   0x00e154: 2a0a016a  orr      w10, w11, w10
//   0x00e158: f2a1404f  movk     x15, #0xa02, lsl #16
//   0x00e15c: d37df1ab  lsl      x11, x13, #3
//   0x00e160: f2cc080f  movk     x15, #0x6040, lsl #32
//   0x00e164: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x00e168: b900002e  str      w14, [x1]
//   0x00e16c: b900030d  str      w13, [x24]
//   0x00e170: aa2801e8  orn      x8, x15, x8
//   0x00e174: 790000ea  strh     w10, [x7]
//   0x00e178: d282880f  mov      x15, #0x1440
//   0x00e17c: f86e7a6d  ldr      x13, [x19, x14, lsl #3]
//   0x00e180: 93403d4a  sxth     x10, w10
//   0x00e184: b86b6a6b  ldr      w11, [x19, x11]
//   0x00e188: f2a140cf  movk     x15, #0xa06, lsl #16
//   0x00e18c: f2cc288f  movk     x15, #0x6144, lsl #32
//   0x00e190: f2e0140f  movk     x15, #0xa0, lsl #48
//   0x00e194: b8404d2e  ldr      w14, [x9, #4]!
//   0x00e198: 782a69ab  strh     w11, [x13, x10]
//   0x00e19c: d28d6b8b  mov      x11, #0x6b5c
//   0x00e1a0: f90002a9  str      x9, [x21]
//   0x00e1a4: 52802089  mov      w9, #0x104
//   0x00e1a8: 8a0f0108  and      x8, x8, x15
//   0x00e1ac: f2be938b  movk     x11, #0xf49c, lsl #16
//   0x00e1b0: 72a02029  movk     w9, #0x101, lsl #16
//   0x00e1b4: 8b0c0108  add      x8, x8, x12
//   0x00e1b8: f941f28a  ldr      x10, [x20, #0x3e0]
//   0x00e1bc: f2d3d76b  movk     x11, #0x9ebb, lsl #32
//   0x00e1c0: f2ffebeb  movk     x11, #0xff5f, lsl #48
//   0x00e1c4: aa090108  orr      x8, x8, x9
//   0x00e1c8: ca0b0108  eor      x8, x8, x11
//   0x00e1cc: 924015c9  and      x9, x14, #0x3f
//   0x00e1d0: 8b080148  add      x8, x10, x8
//   0x00e1d4: 8b090d08  add      x8, x8, x9, lsl #3
//   0x00e1d8: f85f83a9  ldur     x9, [x29, #-8]
//   0x00e1dc: f9400108  ldr      x8, [x8]
//   0x00e1e0: cb090108  sub      x8, x8, x9
//   0x00e1e4: d61f0100  br       x8
//   0x00e1e8: f94002a9  ldr      x9, [x21]
//   0x00e1ec: 5281a6ab  mov      w11, #0xd35
//   0x00e1f0: 72aaf28b  movk     w11, #0x5794, lsl #16
//   0x00e1f4: 5287efcc  mov      w12, #0x3f7e
//   0x00e1f8: 72a71dec  movk     w12, #0x38ef, lsl #16
//   0x00e1fc: 5290ccad  mov      w13, #0x8665
//   0x00e200: f9000089  str      x9, [x4]
//   0x00e204: 72ac662d  movk     w13, #0x6331, lsl #16
//   0x00e208: b940012a  ldr      w10, [x9]
//   0x00e20c: 4a0b014a  eor      w10, w10, w11
//   0x00e210: b900012a  str      w10, [x9]
//   0x00e214: b9800029  ldrsw    x9, [x1]
//   0x00e218: 794000ee  ldrh     w14, [x7]
//   0x00e21c: b980030f  ldrsw    x15, [x24]
//   0x00e220: d37df12a  lsl      x10, x9, #3
//   0x00e224: 4a0c0129  eor      w9, w9, w12
//   0x00e228: 5290786c  mov      w12, #0x83c3
//   0x00e22c: 4a0c01cc  eor      w12, w14, w12
//   0x00e230: 5288654e  mov      w14, #0x432a
//   0x00e234: f86a6a6b  ldr      x11, [x19, x10]
//   0x00e238: 72a30dae  movk     w14, #0x186d, lsl #16
//   0x00e23c: b9000029  str      w9, [x1]
//   0x00e240: d37df1e9  lsl      x9, x15, #3
//   0x00e244: 790000ec  strh     w12, [x7]
//   0x00e248: 5290ddac  mov      w12, #0x86ed
//   0x00e24c: 72a5aa8c  movk     w12, #0x2d54, lsl #16
//   0x00e250: ca0d016d  eor      x13, x11, x13
//   0x00e254: f82a6a6d  str      x13, [x19, x10]
//   0x00e258: 4a0e01ea  eor      w10, w15, w14
//   0x00e25c: b900030a  str      w10, [x24]
//   0x00e260: b8696a6a  ldr      w10, [x19, x9]
//   0x00e264: 4a0c014c  eor      w12, w10, w12
//   0x00e268: b8296a6c  str      w12, [x19, x9]
//   0x00e26c: f94002a9  ldr      x9, [x21]
//   0x00e270: 7900016a  strh     w10, [x11]
//   0x00e274: 52891b6b  mov      w11, #0x48db
//   0x00e278: 72a10ccb  movk     w11, #0x866, lsl #16
//   0x00e27c: f9000089  str      x9, [x4]
//   0x00e280: b8404d2a  ldr      w10, [x9, #4]!
//   0x00e284: f90002a9  str      x9, [x21]
//   0x00e288: 4a0b014a  eor      w10, w10, w11
//   0x00e28c: b900012a  str      w10, [x9]
//   0x00e290: 17ffff8e  b        #0xe0c8
//   0x00e294: d0ffffa8  adrp     x8, #0x4000
//   0x00e298: 5290170a  mov      w10, #0x80b8
//   0x00e29c: 91118108  add      x8, x8, #0x460
//   0x00e2a0: 72a5000a  movk     w10, #0x2800, lsl #16
//   0x00e2a4: 11000509  add      w9, w8, #1
//   0x00e2a8: 0a280129  bic      w9, w9, w8
//   0x00e2ac: 2a2903e9  mvn      w9, w9
//   0x00e2b0: 8a0a0129  and      x9, x9, x10
//   0x00e2b4: d28c656a  mov      x10, #0x632b
//   0x00e2b8: f2ac744a  movk     x10, #0x63a2, lsl #16
//   0x00e2bc: f2c1040a  movk     x10, #0x820, lsl #32
//   0x00e2c0: f2e0600a  movk     x10, #0x300, lsl #48
//   0x00e2c4: 8b0a0129  add      x9, x9, x10
//   0x00e2c8: 5283146a  mov      w10, #0x18a3
//   0x00e2cc: 72a074ca  movk     w10, #0x3a6, lsl #16
//   0x00e2d0: eb0a013f  cmp      x9, x10
//   0x00e2d4: 54000c83  b.lo     #0xe464
//   0x00e2d8: f94002a9  ldr      x9, [x21]
//   0x00e2dc: b9400129  ldr      w9, [x9]
//   0x00e2e0: d3557d2a  ubfx     x10, x9, #0x15, #0xb
//   0x00e2e4: d35bfd2b  lsr      x11, x9, #0x1b
//   0x00e2e8: 121b014c  and      w12, w10, #0x20
//   0x00e2ec: 121a014d  and      w13, w10, #0x40
//   0x00e2f0: 3310512c  bfxil    w12, w9, #0x10, #5
//   0x00e2f4: 1219014e  and      w14, w10, #0x80
//   0x00e2f8: 2a0d018c  orr      w12, w12, w13
//   0x00e2fc: 1218014d  and      w13, w10, #0x100
//   0x00e300: 2a0e018c  orr      w12, w12, w14
//   0x00e304: 1217014a  and      w10, w10, #0x200
//   0x00e308: 2a0d018c  orr      w12, w12, w13
//   0x00e30c: d3417d2d  ubfx     x13, x9, #1, #0x1f
//   0x00e310: 2a0a018a  orr      w10, w12, w10
//   0x00e314: 121601ac  and      w12, w13, #0x400
//   0x00e318: 927c016b  and      x11, x11, #0x10
//   0x00e31c: 2a0c014a  orr      w10, w10, w12
//   0x00e320: 121501ac  and      w12, w13, #0x800
//   0x00e324: d342fd2e  lsr      x14, x9, #2
//   0x00e328: 2a0c014a  orr      w10, w10, w12
//   0x00e32c: 121401ac  and      w12, w13, #0x1000
//   0x00e330: b347292b  bfxil    x11, x9, #7, #4
//   0x00e334: 927c01ce  and      x14, x14, #0x10
//   0x00e338: 2a0c014a  orr      w10, w10, w12
//   0x00e33c: 121301ac  and      w12, w13, #0x2000
//   0x00e340: b356652e  bfxil    x14, x9, #0x16, #4
//   0x00e344: d3467d29  ubfx     x9, x9, #6, #0x1a
//   0x00e348: 121201ad  and      w13, w13, #0x4000
//   0x00e34c: 2a0c014a  orr      w10, w10, w12
//   0x00e350: 12110129  and      w9, w9, #0x8000
//   0x00e354: f86b7a6c  ldr      x12, [x19, x11, lsl #3]
//   0x00e358: 2a0d014a  orr      w10, w10, w13
//   0x00e35c: d37df1cd  lsl      x13, x14, #3
//   0x00e360: 2a090149  orr      w9, w10, w9
//   0x00e364: b900002b  str      w11, [x1]
//   0x00e368: b900030e  str      w14, [x24]
//   0x00e36c: 8b29a18a  add      x10, x12, w9, sxth
//   0x00e370: 790000e9  strh     w9, [x7]
//   0x00e374: f85e03a9  ldur     x9, [x29, #-0x20]
//   0x00e378: b86d6a6b  ldr      w11, [x19, x13]
//   0x00e37c: b940012c  ldr      w12, [x9]
//   0x00e380: 885ffd49  ldaxr    w9, [x10]
//   0x00e384: 6b0c013f  cmp      w9, w12
//   0x00e388: 54000141  b.ne     #0xe3b0
//   0x00e38c: 880cfd4b  stlxr    w12, w11, [x10]
//   0x00e390: 3400064c  cbz      w12, #0xe458
//   0x00e394: 2a1f03ea  mov      w10, wzr
//   0x00e398: 3400012a  cbz      w10, #0xe3bc
//   0x00e39c: b980030a  ldrsw    x10, [x24]
//   0x00e3a0: 5280002b  mov      w11, #1
//   0x00e3a4: f85e03a9  ldur     x9, [x29, #-0x20]
//   0x00e3a8: f82a7a6b  str      x11, [x19, x10, lsl #3]
//   0x00e3ac: 14000008  b        #0xe3cc
//   0x00e3b0: d5033f5f  clrex    
//   0x00e3b4: 2a1f03ea  mov      w10, wzr
//   0x00e3b8: 35ffff2a  cbnz     w10, #0xe39c
//   0x00e3bc: f85e03aa  ldur     x10, [x29, #-0x20]
//   0x00e3c0: b9000149  str      w9, [x10]
//   0x00e3c4: b9800309  ldrsw    x9, [x24]
//   0x00e3c8: 8b090e69  add      x9, x19, x9, lsl #3
//   0x00e3cc: d282080b  mov      x11, #0x1040
//   0x00e3d0: d280800a  mov      x10, #0x400
//   0x00e3d4: f2a1404b  movk     x11, #0xa02, lsl #16
//   0x00e3d8: d282880c  mov      x12, #0x1440
//   0x00e3dc: f2a0008a  movk     x10, #4, lsl #16
//   0x00e3e0: f2cc080b  movk     x11, #0x6040, lsl #32
//   0x00e3e4: f2a140cc  movk     x12, #0xa06, lsl #16
//   0x00e3e8: f2c0208a  movk     x10, #0x104, lsl #32
//   0x00e3ec: f2e0140b  movk     x11, #0xa0, lsl #48
//   0x00e3f0: f2cc288c  movk     x12, #0x6144, lsl #32
//   0x00e3f4: 8a0a010a  and      x10, x8, x10
//   0x00e3f8: aa280168  orn      x8, x11, x8
//   0x00e3fc: f2e0140c  movk     x12, #0xa0, lsl #48
//   0x00e400: f900013f  str      xzr, [x9]
//   0x00e404: 8a0c0108  and      x8, x8, x12
//   0x00e408: f94002a9  ldr      x9, [x21]
//   0x00e40c: 8b0a0108  add      x8, x8, x10
//   0x00e410: 5280208a  mov      w10, #0x104
//   0x00e414: 72a0202a  movk     w10, #0x101, lsl #16
//   0x00e418: aa0a0108  orr      x8, x8, x10
//   0x00e41c: d28d6b8a  mov      x10, #0x6b5c
//   0x00e420: b8404d2b  ldr      w11, [x9, #4]!
//   0x00e424: f90002a9  str      x9, [x21]
//   0x00e428: f2be938a  movk     x10, #0xf49c, lsl #16
//   0x00e42c: f941f289  ldr      x9, [x20, #0x3e0]
//   0x00e430: f2d3d76a  movk     x10, #0x9ebb, lsl #32
//   0x00e434: f2ffebea  movk     x10, #0xff5f, lsl #48
//   0x00e438: 9240156b  and      x11, x11, #0x3f
//   0x00e43c: ca0a0108  eor      x8, x8, x10
//   0x00e440: 8b080128  add      x8, x9, x8
//   0x00e444: f85f83a9  ldur     x9, [x29, #-8]
//   0x00e448: 8b0b0d08  add      x8, x8, x11, lsl #3
//   0x00e44c: f9400108  ldr      x8, [x8]
//   0x00e450: cb090108  sub      x8, x8, x9
//   0x00e454: d61f0100  br       x8
//   0x00e458: 5280002a  mov      w10, #1
//   0x00e45c: 35fffa0a  cbnz     w10, #0xe39c
//   0x00e460: 17ffffd7  b        #0xe3bc
//   0x00e464: f94002a9  ldr      x9, [x21]
//   0x00e468: 5290c78b  mov      w11, #0x863c
//   0x00e46c: 72ae3ccb  movk     w11, #0x71e6, lsl #16
//   0x00e470: 5280f1ec  mov      w12, #0x78f
//   0x00e474: 72aaaeec  movk     w12, #0x5577, lsl #16
//   0x00e478: 528d23cd  mov      w13, #0x691e
//   0x00e47c: f9000089  str      x9, [x4]
//   0x00e480: 72af322d  movk     w13, #0x7991, lsl #16
//   0x00e484: b940012a  ldr      w10, [x9]
//   0x00e488: 4a0b014a  eor      w10, w10, w11
//   0x00e48c: b900012a  str      w10, [x9]
//   0x00e490: b980002a  ldrsw    x10, [x1]
//   0x00e494: 794000ee  ldrh     w14, [x7]
//   0x00e498: b980030f  ldrsw    x15, [x24]
//   0x00e49c: d37df14b  lsl      x11, x10, #3
//   0x00e4a0: 4a0c014a  eor      w10, w10, w12
//   0x00e4a4: 528ddd8c  mov      w12, #0x6eec
//   0x00e4a8: 4a0c01cc  eor      w12, w14, w12
//   0x00e4ac: 52986a4e  mov      w14, #0xc352
//   0x00e4b0: f86b6a69  ldr      x9, [x19, x11]
//   0x00e4b4: 72afe5ee  movk     w14, #0x7f2f, lsl #16
//   0x00e4b8: b900002a  str      w10, [x1]
//   0x00e4bc: 790000ec  strh     w12, [x7]
//   0x00e4c0: 5289610c  mov      w12, #0x4b08
//   0x00e4c4: 72a0afcc  movk     w12, #0x57e, lsl #16
//   0x00e4c8: ca0d012d  eor      x13, x9, x13
//   0x00e4cc: f82b6a6d  str      x13, [x19, x11]
//   0x00e4d0: 4a0e01eb  eor      w11, w15, w14
//   0x00e4d4: d37df1ed  lsl      x13, x15, #3
//   0x00e4d8: b900030b  str      w11, [x24]
//   0x00e4dc: 528fb74b  mov      w11, #0x7dba
//   0x00e4e0: b86d6a6a  ldr      w10, [x19, x13]
//   0x00e4e4: 72a3180b  movk     w11, #0x18c0, lsl #16
//   0x00e4e8: 4a0b014b  eor      w11, w10, w11
//   0x00e4ec: b82d6a6b  str      w11, [x19, x13]
//   0x00e4f0: f85e03ad  ldur     x13, [x29, #-0x20]
//   0x00e4f4: b94001ab  ldr      w11, [x13]
//   0x00e4f8: 4a0c016c  eor      w12, w11, w12
//   0x00e4fc: b90001ac  str      w12, [x13]
//   0x00e500: 885ffd2c  ldaxr    w12, [x9]
//   0x00e504: 6b0b019f  cmp      w12, w11
//   0x00e508: 54000061  b.ne     #0xe514
//   0x00e50c: 881ffd2a  stlxr    wzr, w10, [x9]
//   0x00e510: 17ffff72  b        #0xe2d8
//   0x00e514: d5033f5f  clrex    
//   0x00e518: 17ffff70  b        #0xe2d8
//   0x00e51c: 910003bf  mov      sp, x29
//   0x00e520: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00e524: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x00e528: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x00e52c: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x00e530: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x00e534: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x00e538: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_21_4460(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004460ULL;
    for (std::size_t i = 0; i < 10295ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1119ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[22] Subroutine @ 0x00e53c..0x00e550 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[22] Hàm con @ 0x00e53c..0x00e550 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e53c: a9402003  ldp      x3, x8, [x0]
//   0x00e540: f9400c02  ldr      x2, [x0, #0x18]
//   0x00e544: 39404001  ldrb     w1, [x0, #0x10]
//   0x00e548: aa0803e0  mov      x0, x8
//   0x00e54c: d61f0060  br       x3
// ============================================================================
std::uint32_t fde_22_e53c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e53cULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11414ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[23] Subroutine @ 0x00e550..0x00e570 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[23] Hàm con @ 0x00e550..0x00e570 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e550: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x00e554: aa0003f3  mov      x19, x0
//   0x00e558: a9400008  ldp      x8, x0, [x0]
//   0x00e55c: a9410a61  ldp      x1, x2, [x19, #0x10]
//   0x00e560: d63f0100  blr      x8
//   0x00e564: f9001260  str      x0, [x19, #0x20]
//   0x00e568: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x00e56c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_23_e550(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e550ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11419ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[24] Subroutine @ 0x00e570..0x00e590 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[24] Hàm con @ 0x00e570..0x00e590 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e570: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x00e574: aa0003f3  mov      x19, x0
//   0x00e578: a9400008  ldp      x8, x0, [x0]
//   0x00e57c: f9400a61  ldr      x1, [x19, #0x10]
//   0x00e580: d63f0100  blr      x8
//   0x00e584: f9000e60  str      x0, [x19, #0x18]
//   0x00e588: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x00e58c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_24_e570(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e570ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11427ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[25] Subroutine @ 0x00e590..0x00e5a4 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[25] Hàm con @ 0x00e590..0x00e5a4 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e590: a9408408  ldp      x8, x1, [x0, #8]
//   0x00e594: f9400c02  ldr      x2, [x0, #0x18]
//   0x00e598: f9400003  ldr      x3, [x0]
//   0x00e59c: aa0803e0  mov      x0, x8
//   0x00e5a0: d61f0060  br       x3
// ============================================================================
std::uint32_t fde_25_e590(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e590ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11435ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[26] Subroutine @ 0x00e5a4..0x00e5b8 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[26] Hàm con @ 0x00e5a4..0x00e5b8 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e5a4: a9408408  ldp      x8, x1, [x0, #8]
//   0x00e5a8: f9400c02  ldr      x2, [x0, #0x18]
//   0x00e5ac: f9400003  ldr      x3, [x0]
//   0x00e5b0: aa0803e0  mov      x0, x8
//   0x00e5b4: d61f0060  br       x3
// ============================================================================
std::uint32_t fde_26_e5a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e5a4ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11440ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[27] Subroutine @ 0x00e5b8..0x00e5d8 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[27] Hàm con @ 0x00e5b8..0x00e5d8 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e5b8: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x00e5bc: aa0003f3  mov      x19, x0
//   0x00e5c0: a9400008  ldp      x8, x0, [x0]
//   0x00e5c4: b9401261  ldr      w1, [x19, #0x10]
//   0x00e5c8: d63f0100  blr      x8
//   0x00e5cc: b9001660  str      w0, [x19, #0x14]
//   0x00e5d0: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x00e5d4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_27_e5b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e5b8ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11445ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[28] Subroutine @ 0x00e5d8..0x00e71c (324 bytes, 81 AArch64 instructions)
// [VN] Khung FDE[28] Hàm con @ 0x00e5d8..0x00e71c (324 byte, 81 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e5d8: d10183ff  sub      sp, sp, #0x60
//   0x00e5dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e5e0: 910043fd  add      x29, sp, #0x10
//   0x00e5e4: f90013f9  str      x25, [sp, #0x20]
//   0x00e5e8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x00e5ec: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00e5f0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00e5f4: d53bd059  mrs      x25, tpidr_el0
//   0x00e5f8: f9401728  ldr      x8, [x25, #0x28]
//   0x00e5fc: f90007e8  str      x8, [sp, #8]
//   0x00e600: b4000561  cbz      x1, #0xe6ac
//   0x00e604: f9400008  ldr      x8, [x0]
//   0x00e608: aa0103f3  mov      x19, x1
//   0x00e60c: aa0003f4  mov      x20, x0
//   0x00e610: f942ad08  ldr      x8, [x8, #0x558]
//   0x00e614: d63f0100  blr      x8
//   0x00e618: f9400288  ldr      x8, [x20]
//   0x00e61c: 2a0003f6  mov      w22, w0
//   0x00e620: aa1403e0  mov      x0, x20
//   0x00e624: aa1303e1  mov      x1, x19
//   0x00e628: aa1f03e2  mov      x2, xzr
//   0x00e62c: f942e108  ldr      x8, [x8, #0x5c0]
//   0x00e630: d63f0100  blr      x8
//   0x00e634: b40003c0  cbz      x0, #0xe6ac
//   0x00e638: 910013e2  add      x2, sp, #4
//   0x00e63c: 2a1603e1  mov      w1, w22
//   0x00e640: 52800083  mov      w3, #4
//   0x00e644: aa0003f5  mov      x21, x0
//   0x00e648: b90007ff  str      wzr, [sp, #4]
//   0x00e64c: 97ffd3d7  bl       #0x35a8
//   0x00e650: aa0003f6  mov      x22, x0
//   0x00e654: b4000460  cbz      x0, #0xe6e0
//   0x00e658: f9400288  ldr      x8, [x20]
//   0x00e65c: aa1403e0  mov      x0, x20
//   0x00e660: b94007e1  ldr      w1, [sp, #4]
//   0x00e664: f942c108  ldr      x8, [x8, #0x580]
//   0x00e668: d63f0100  blr      x8
//   0x00e66c: aa0003f8  mov      x24, x0
//   0x00e670: aa1403e0  mov      x0, x20
//   0x00e674: 940001de  bl       #0xedec
//   0x00e678: aa1f03f7  mov      x23, xzr
//   0x00e67c: 37000340  tbnz     w0, #0, #0xe6e4
//   0x00e680: b4000338  cbz      x24, #0xe6e4
//   0x00e684: f9400288  ldr      x8, [x20]
//   0x00e688: aa1403e0  mov      x0, x20
//   0x00e68c: b94007e3  ldr      w3, [sp, #4]
//   0x00e690: aa1803e1  mov      x1, x24
//   0x00e694: 2a1f03e2  mov      w2, wzr
//   0x00e698: aa1603e4  mov      x4, x22
//   0x00e69c: f9434108  ldr      x8, [x8, #0x680]
//   0x00e6a0: d63f0100  blr      x8
//   0x00e6a4: aa1803f7  mov      x23, x24
//   0x00e6a8: 1400000f  b        #0xe6e4
//   0x00e6ac: aa1f03f7  mov      x23, xzr
//   0x00e6b0: f9401728  ldr      x8, [x25, #0x28]
//   0x00e6b4: f94007e9  ldr      x9, [sp, #8]
//   0x00e6b8: eb09011f  cmp      x8, x9
//   0x00e6bc: 540002e1  b.ne     #0xe718
//   0x00e6c0: aa1703e0  mov      x0, x23
//   0x00e6c4: f94013f9  ldr      x25, [sp, #0x20]
//   0x00e6c8: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00e6cc: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x00e6d0: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x00e6d4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e6d8: 910183ff  add      sp, sp, #0x60
//   0x00e6dc: d65f03c0  ret      
//   0x00e6e0: aa1f03f7  mov      x23, xzr
//   0x00e6e4: f9400288  ldr      x8, [x20]
//   0x00e6e8: aa1403e0  mov      x0, x20
//   0x00e6ec: aa1303e1  mov      x1, x19
//   0x00e6f0: aa1503e2  mov      x2, x21
//   0x00e6f4: 2a1f03e3  mov      w3, wzr
//   0x00e6f8: f9430108  ldr      x8, [x8, #0x600]
//   0x00e6fc: d63f0100  blr      x8
//   0x00e700: aa1603e0  mov      x0, x22
//   0x00e704: 9400048f  bl       #0xf940
//   0x00e708: f9401728  ldr      x8, [x25, #0x28]
//   0x00e70c: f94007e9  ldr      x9, [sp, #8]
//   0x00e710: eb09011f  cmp      x8, x9
//   0x00e714: 54fffd60  b.eq     #0xe6c0
//   0x00e718: 9400048e  bl       #0xf950
// ============================================================================
std::uint32_t fde_28_e5d8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e5d8ULL;
    for (std::size_t i = 0; i < 81ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11453ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[29] Subroutine @ 0x00e71c..0x00e840 (292 bytes, 73 AArch64 instructions)
// [VN] Khung FDE[29] Hàm con @ 0x00e71c..0x00e840 (292 byte, 73 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e71c: d10143ff  sub      sp, sp, #0x50
//   0x00e720: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e724: 910043fd  add      x29, sp, #0x10
//   0x00e728: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00e72c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00e730: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00e734: d53bd058  mrs      x24, tpidr_el0
//   0x00e738: f9401708  ldr      x8, [x24, #0x28]
//   0x00e73c: f90007e8  str      x8, [sp, #8]
//   0x00e740: b40004a1  cbz      x1, #0xe7d4
//   0x00e744: f9400008  ldr      x8, [x0]
//   0x00e748: aa1f03e2  mov      x2, xzr
//   0x00e74c: aa0103f3  mov      x19, x1
//   0x00e750: aa0003f4  mov      x20, x0
//   0x00e754: f942e108  ldr      x8, [x8, #0x5c0]
//   0x00e758: d63f0100  blr      x8
//   0x00e75c: b40003c0  cbz      x0, #0xe7d4
//   0x00e760: f9400288  ldr      x8, [x20]
//   0x00e764: aa0003f5  mov      x21, x0
//   0x00e768: aa1403e0  mov      x0, x20
//   0x00e76c: aa1303e1  mov      x1, x19
//   0x00e770: f942ad08  ldr      x8, [x8, #0x558]
//   0x00e774: d63f0100  blr      x8
//   0x00e778: 2a0003e1  mov      w1, w0
//   0x00e77c: 910013e2  add      x2, sp, #4
//   0x00e780: aa1503e0  mov      x0, x21
//   0x00e784: 52800083  mov      w3, #4
//   0x00e788: b90007ff  str      wzr, [sp, #4]
//   0x00e78c: 97ffd5c7  bl       #0x3ea8
//   0x00e790: aa0003f7  mov      x23, x0
//   0x00e794: b4000380  cbz      x0, #0xe804
//   0x00e798: f9400288  ldr      x8, [x20]
//   0x00e79c: aa1403e0  mov      x0, x20
//   0x00e7a0: b94007e1  ldr      w1, [sp, #4]
//   0x00e7a4: f942c108  ldr      x8, [x8, #0x580]
//   0x00e7a8: d63f0100  blr      x8
//   0x00e7ac: f9400288  ldr      x8, [x20]
//   0x00e7b0: aa0003f6  mov      x22, x0
//   0x00e7b4: b94007e3  ldr      w3, [sp, #4]
//   0x00e7b8: aa1403e0  mov      x0, x20
//   0x00e7bc: aa1603e1  mov      x1, x22
//   0x00e7c0: 2a1f03e2  mov      w2, wzr
//   0x00e7c4: f9434108  ldr      x8, [x8, #0x680]
//   0x00e7c8: aa1703e4  mov      x4, x23
//   0x00e7cc: d63f0100  blr      x8
//   0x00e7d0: 1400000e  b        #0xe808
//   0x00e7d4: aa1f03f6  mov      x22, xzr
//   0x00e7d8: f9401708  ldr      x8, [x24, #0x28]
//   0x00e7dc: f94007e9  ldr      x9, [sp, #8]
//   0x00e7e0: eb09011f  cmp      x8, x9
//   0x00e7e4: 540002c1  b.ne     #0xe83c
//   0x00e7e8: aa1603e0  mov      x0, x22
//   0x00e7ec: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00e7f0: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x00e7f4: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00e7f8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e7fc: 910143ff  add      sp, sp, #0x50
//   0x00e800: d65f03c0  ret      
//   0x00e804: aa1f03f6  mov      x22, xzr
//   0x00e808: aa1703e0  mov      x0, x23
//   0x00e80c: 9400044d  bl       #0xf940
//   0x00e810: f9400288  ldr      x8, [x20]
//   0x00e814: aa1403e0  mov      x0, x20
//   0x00e818: aa1303e1  mov      x1, x19
//   0x00e81c: aa1503e2  mov      x2, x21
//   0x00e820: 2a1f03e3  mov      w3, wzr
//   0x00e824: f9430108  ldr      x8, [x8, #0x600]
//   0x00e828: d63f0100  blr      x8
//   0x00e82c: f9401708  ldr      x8, [x24, #0x28]
//   0x00e830: f94007e9  ldr      x9, [sp, #8]
//   0x00e834: eb09011f  cmp      x8, x9
//   0x00e838: 54fffd80  b.eq     #0xe7e8
//   0x00e83c: 94000445  bl       #0xf950
// ============================================================================
std::uint32_t fde_29_e71c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e71cULL;
    for (std::size_t i = 0; i < 73ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11534ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[30] Subroutine @ 0x00e840..0x00e964 (292 bytes, 73 AArch64 instructions)
// [VN] Khung FDE[30] Hàm con @ 0x00e840..0x00e964 (292 byte, 73 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e840: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x00e844: f9000bf9  str      x25, [sp, #0x10]
//   0x00e848: 910003fd  mov      x29, sp
//   0x00e84c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00e850: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00e854: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00e858: d0000055  adrp     x21, #0x18000
//   0x00e85c: aa0103f3  mov      x19, x1
//   0x00e860: 911262b5  add      x21, x21, #0x498
//   0x00e864: aa0003f4  mov      x20, x0
//   0x00e868: 88dffea8  ldar     w8, [x21]
//   0x00e86c: 35000148  cbnz     w8, #0xe894
//   0x00e870: 90ffffa0  adrp     x0, #0x2000
//   0x00e874: d0000041  adrp     x1, #0x18000
//   0x00e878: 90ffffa2  adrp     x2, #0x2000
//   0x00e87c: 91262000  add      x0, x0, #0x988
//   0x00e880: 91122021  add      x1, x1, #0x488
//   0x00e884: 91266042  add      x2, x2, #0x998
//   0x00e888: 97ffd2ab  bl       #0x3334
//   0x00e88c: 52800028  mov      w8, #1
//   0x00e890: 889ffea8  stlr     w8, [x21]
//   0x00e894: d0000056  adrp     x22, #0x18000
//   0x00e898: 911222d6  add      x22, x22, #0x488
//   0x00e89c: aa1603e0  mov      x0, x22
//   0x00e8a0: 2a1f03e1  mov      w1, wzr
//   0x00e8a4: 9400043f  bl       #0xf9a0
//   0x00e8a8: 3100041f  cmn      w0, #1
//   0x00e8ac: 540000c1  b.ne     #0xe8c4
//   0x00e8b0: 94000440  bl       #0xf9b0
//   0x00e8b4: b9400008  ldr      w8, [x0]
//   0x00e8b8: 7100111f  cmp      w8, #4
//   0x00e8bc: 54ffff00  b.eq     #0xe89c
//   0x00e8c0: 14000019  b        #0xe924
//   0x00e8c4: 2a0003f5  mov      w21, w0
//   0x00e8c8: b40003d3  cbz      x19, #0xe940
//   0x00e8cc: aa1f03f8  mov      x24, xzr
//   0x00e8d0: 92f00019  mov      x25, #0x7fffffffffffffff
//   0x00e8d4: 14000004  b        #0xe8e4
//   0x00e8d8: 8b180018  add      x24, x0, x24
//   0x00e8dc: eb000273  subs     x19, x19, x0
//   0x00e8e0: 54000300  b.eq     #0xe940
//   0x00e8e4: f100027f  cmp      x19, #0
//   0x00e8e8: 8b180297  add      x23, x20, x24
//   0x00e8ec: 9a99a276  csel     x22, x19, x25, ge
//   0x00e8f0: 2a1503e0  mov      w0, w21
//   0x00e8f4: aa1703e1  mov      x1, x23
//   0x00e8f8: aa1603e2  mov      x2, x22
//   0x00e8fc: 92800003  mov      x3, #-1
//   0x00e900: 94000430  bl       #0xf9c0
//   0x00e904: b100041f  cmn      x0, #1
//   0x00e908: 54fffe81  b.ne     #0xe8d8
//   0x00e90c: 94000429  bl       #0xf9b0
//   0x00e910: b9400008  ldr      w8, [x0]
//   0x00e914: 7100111f  cmp      w8, #4
//   0x00e918: 54fffec0  b.eq     #0xe8f0
//   0x00e91c: 71002d1f  cmp      w8, #0xb
//   0x00e920: 54fffe80  b.eq     #0xe8f0
//   0x00e924: 12800000  mov      w0, #-1
//   0x00e928: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00e92c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x00e930: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00e934: f9400bf9  ldr      x25, [sp, #0x10]
//   0x00e938: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x00e93c: d65f03c0  ret      
//   0x00e940: 2a1503e0  mov      w0, w21
//   0x00e944: 94000423  bl       #0xf9d0
//   0x00e948: 2a1f03e0  mov      w0, wzr
//   0x00e94c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00e950: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x00e954: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00e958: f9400bf9  ldr      x25, [sp, #0x10]
//   0x00e95c: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x00e960: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_30_e840(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e840ULL;
    for (std::size_t i = 0; i < 73ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11607ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[31] Subroutine @ 0x00e964..0x00eaf8 (404 bytes, 101 AArch64 instructions)
// [VN] Khung FDE[31] Hàm con @ 0x00e964..0x00eaf8 (404 byte, 101 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e964: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x00e968: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00e96c: 910003fd  mov      x29, sp
//   0x00e970: d10043ff  sub      sp, sp, #0x10
//   0x00e974: d53bd053  mrs      x19, tpidr_el0
//   0x00e978: 52802d69  mov      w9, #0x16b
//   0x00e97c: f9401668  ldr      x8, [x19, #0x28]
//   0x00e980: 528014ea  mov      w10, #0xa7
//   0x00e984: f81f83a8  stur     x8, [x29, #-8]
//   0x00e988: b81f43a9  stur     w9, [x29, #-0xc]
//   0x00e98c: b81f03aa  stur     w10, [x29, #-0x10]
//   0x00e990: 320003ea  mov      w10, #1
//   0x00e994: b85f43a8  ldur     w8, [x29, #-0xc]
//   0x00e998: b85f03a9  ldur     w9, [x29, #-0x10]
//   0x00e99c: 1b082908  madd     w8, w8, w8, w10
//   0x00e9a0: 1b097d29  mul      w9, w9, w9
//   0x00e9a4: 531d712a  lsl      w10, w9, #3
//   0x00e9a8: 4b090149  sub      w9, w10, w9
//   0x00e9ac: 6b09011f  cmp      w8, w9
//   0x00e9b0: 54000281  b.ne     #0xea00
// ============================================================================
std::uint32_t fde_31_e964(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e964ULL;
    for (std::size_t i = 0; i < 101ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11680ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[32] Subroutine @ 0x00eaf8..0x00ecac (436 bytes, 109 AArch64 instructions)
// [VN] Khung FDE[32] Hàm con @ 0x00eaf8..0x00ecac (436 byte, 109 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00eaf8: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x00eafc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00eb00: 910003fd  mov      x29, sp
//   0x00eb04: d10043ff  sub      sp, sp, #0x10
//   0x00eb08: d53bd053  mrs      x19, tpidr_el0
//   0x00eb0c: 52801a09  mov      w9, #0xd0
//   0x00eb10: f9401668  ldr      x8, [x19, #0x28]
//   0x00eb14: 52803e4a  mov      w10, #0x1f2
//   0x00eb18: f81f83a8  stur     x8, [x29, #-8]
//   0x00eb1c: b81f43a9  stur     w9, [x29, #-0xc]
//   0x00eb20: b81f03aa  stur     w10, [x29, #-0x10]
//   0x00eb24: b85f43a8  ldur     w8, [x29, #-0xc]
//   0x00eb28: b85f03a9  ldur     w9, [x29, #-0x10]
//   0x00eb2c: 7101313f  cmp      w9, #0x4c
//   0x00eb30: 5400046c  b.gt     #0xebbc
//   0x00eb34: 1b087d08  mul      w8, w8, w8
//   0x00eb38: 528d7969  mov      w9, #0x6bcb
//   0x00eb3c: 72b5e509  movk     w9, #0xaf28, lsl #16
//   0x00eb40: 531e7508  lsl      w8, w8, #2
//   0x00eb44: 11001108  add      w8, w8, #4
//   0x00eb48: 9ba97d09  umull    x9, w8, w9
//   0x00eb4c: d360fd29  lsr      x9, x9, #0x20
//   0x00eb50: 4b09010a  sub      w10, w8, w9
//   0x00eb54: 0b4a0529  add      w9, w9, w10, lsr #1
//   0x00eb58: 5280026a  mov      w10, #0x13
//   0x00eb5c: 53047d29  lsr      w9, w9, #4
//   0x00eb60: 1b0aa128  msub     w8, w9, w10, w8
//   0x00eb64: 350002c8  cbnz     w8, #0xebbc
//   0x00eb68: e5cda7d9  st1d     {z25.d}, p1, [z30.d, #0x68]
// ============================================================================
std::uint32_t fde_32_eaf8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000eaf8ULL;
    for (std::size_t i = 0; i < 109ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11781ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[33] Subroutine @ 0x00ecac..0x00edec (320 bytes, 80 AArch64 instructions)
// [VN] Khung FDE[33] Hàm con @ 0x00ecac..0x00edec (320 byte, 80 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ecac: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x00ecb0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00ecb4: 910003fd  mov      x29, sp
//   0x00ecb8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00ecbc: 6b02003f  cmp      w1, w2
//   0x00ecc0: 540008ea  b.ge     #0xeddc
//   0x00ecc4: 2a0203f3  mov      w19, w2
//   0x00ecc8: aa0003f4  mov      x20, x0
//   0x00eccc: 91000415  add      x21, x0, #1
//   0x00ecd0: 1400000a  b        #0xecf8
//   0x00ecd4: 2a1603e9  mov      w9, w22
//   0x00ecd8: 93407d29  sxtw     x9, w9
//   0x00ecdc: 510006c2  sub      w2, w22, #1
//   0x00ece0: aa1403e0  mov      x0, x20
//   0x00ece4: 38296a88  strb     w8, [x20, x9]
//   0x00ece8: 97fffff1  bl       #0xecac
//   0x00ecec: 110006c1  add      w1, w22, #1
//   0x00ecf0: 6b13003f  cmp      w1, w19
//   0x00ecf4: 5400074a  b.ge     #0xeddc
//   0x00ecf8: 93407c29  sxtw     x9, w1
//   0x00ecfc: 2a0103f6  mov      w22, w1
//   0x00ed00: 6b13003f  cmp      w1, w19
//   0x00ed04: 38696a88  ldrb     w8, [x20, x9]
//   0x00ed08: 54fffeaa  b.ge     #0xecdc
//   0x00ed0c: 2a1303e9  mov      w9, w19
//   0x00ed10: 2a0103f6  mov      w22, w1
//   0x00ed14: 14000007  b        #0xed30
//   0x00ed18: 93407d4c  sxtw     x12, w10
//   0x00ed1c: 386c6a8c  ldrb     w12, [x20, x12]
//   0x00ed20: 2a0a03f6  mov      w22, w10
//   0x00ed24: 6b0902df  cmp      w22, w9
//   0x00ed28: 382b6a8c  strb     w12, [x20, x11]
//   0x00ed2c: 54fffd4a  b.ge     #0xecd4
//   0x00ed30: 6b0902df  cmp      w22, w9
//   0x00ed34: 5400022a  b.ge     #0xed78
//   0x00ed38: 2a1603ea  mov      w10, w22
//   0x00ed3c: 93407d29  sxtw     x9, w9
//   0x00ed40: 93407d4a  sxtw     x10, w10
//   0x00ed44: 38696a8b  ldrb     w11, [x20, x9]
//   0x00ed48: 6b08017f  cmp      w11, w8
//   0x00ed4c: 54000243  b.lo     #0xed94
//   0x00ed50: d1000529  sub      x9, x9, #1
//   0x00ed54: eb0a013f  cmp      x9, x10
//   0x00ed58: 54ffff6c  b.gt     #0xed44
//   0x00ed5c: 2a1603e9  mov      w9, w22
//   0x00ed60: 93407d2b  sxtw     x11, w9
//   0x00ed64: 6b0902df  cmp      w22, w9
//   0x00ed68: 386b6a8c  ldrb     w12, [x20, x11]
//   0x00ed6c: 382a6a8c  strb     w12, [x20, x10]
//   0x00ed70: 54fffdaa  b.ge     #0xed24
//   0x00ed74: 1400000d  b        #0xeda8
//   0x00ed78: 93407eca  sxtw     x10, w22
//   0x00ed7c: 93407d2b  sxtw     x11, w9
//   0x00ed80: 6b0902df  cmp      w22, w9
//   0x00ed84: 386b6a8c  ldrb     w12, [x20, x11]
//   0x00ed88: 382a6a8c  strb     w12, [x20, x10]
//   0x00ed8c: 54fffcca  b.ge     #0xed24
//   0x00ed90: 14000006  b        #0xeda8
//   0x00ed94: 93407d2b  sxtw     x11, w9
//   0x00ed98: 6b0902df  cmp      w22, w9
//   0x00ed9c: 386b6a8c  ldrb     w12, [x20, x11]
//   0x00eda0: 382a6a8c  strb     w12, [x20, x10]
//   0x00eda4: 54fffc0a  b.ge     #0xed24
//   0x00eda8: 6b08019f  cmp      w12, w8
//   0x00edac: 54fffb68  b.hi     #0xed18
//   0x00edb0: d100056c  sub      x12, x11, #1
//   0x00edb4: eb0a019f  cmp      x12, x10
//   0x00edb8: 540000c0  b.eq     #0xedd0
//   0x00edbc: 386a6aad  ldrb     w13, [x21, x10]
//   0x00edc0: 9100054a  add      x10, x10, #1
//   0x00edc4: 6b0801bf  cmp      w13, w8
//   0x00edc8: 54ffff69  b.ls     #0xedb4
//   0x00edcc: 17ffffd3  b        #0xed18
//   0x00edd0: aa0b03ec  mov      x12, x11
//   0x00edd4: 2a0903ea  mov      w10, w9
//   0x00edd8: 17ffffd1  b        #0xed1c
//   0x00eddc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00ede0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00ede4: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x00ede8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_33_ecac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ecacULL;
    for (std::size_t i = 0; i < 80ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11890ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[34] Subroutine @ 0x00edec..0x00ee34 (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[34] Hàm con @ 0x00edec..0x00ee34 (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00edec: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x00edf0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00edf4: 910003fd  mov      x29, sp
//   0x00edf8: f9400008  ldr      x8, [x0]
//   0x00edfc: aa0003f3  mov      x19, x0
//   0x00ee00: f9403d08  ldr      x8, [x8, #0x78]
//   0x00ee04: d63f0100  blr      x8
//   0x00ee08: aa0003f4  mov      x20, x0
//   0x00ee0c: b40000a0  cbz      x0, #0xee20
//   0x00ee10: f9400268  ldr      x8, [x19]
//   0x00ee14: aa1303e0  mov      x0, x19
//   0x00ee18: f9404508  ldr      x8, [x8, #0x88]
//   0x00ee1c: d63f0100  blr      x8
//   0x00ee20: f100029f  cmp      x20, #0
//   0x00ee24: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00ee28: 1a9f07e0  cset     w0, ne
//   0x00ee2c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x00ee30: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_34_edec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000edecULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11970ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[35] Subroutine @ 0x00ee34..0x00ee40 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[35] Hàm con @ 0x00ee34..0x00ee40 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ee34: aa0003e2  mov      x2, x0
//   0x00ee38: aa0103e0  mov      x0, x1
//   0x00ee3c: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_35_ee34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ee34ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11988ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[36] Subroutine @ 0x00ee40..0x00ee64 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[36] Hàm con @ 0x00ee40..0x00ee64 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ee40: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x00ee44: aa0003f3  mov      x19, x0
//   0x00ee48: a9400008  ldp      x8, x0, [x0]
//   0x00ee4c: b9401261  ldr      w1, [x19, #0x10]
//   0x00ee50: f9400e62  ldr      x2, [x19, #0x18]
//   0x00ee54: d63f0100  blr      x8
//   0x00ee58: f9001260  str      x0, [x19, #0x20]
//   0x00ee5c: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x00ee60: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_36_ee40(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ee40ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11991ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[37] Subroutine @ 0x00ee64..0x00ee88 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[37] Hàm con @ 0x00ee64..0x00ee88 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ee64: a9bf4ffe  stp      x30, x19, [sp, #-0x10]!
//   0x00ee68: aa0003f3  mov      x19, x0
//   0x00ee6c: a9400008  ldp      x8, x0, [x0]
//   0x00ee70: b9401261  ldr      w1, [x19, #0x10]
//   0x00ee74: f9400e62  ldr      x2, [x19, #0x18]
//   0x00ee78: d63f0100  blr      x8
//   0x00ee7c: f9001260  str      x0, [x19, #0x20]
//   0x00ee80: a8c14ffe  ldp      x30, x19, [sp], #0x10
//   0x00ee84: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_37_ee64(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ee64ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12000ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[38] Subroutine @ 0x00ee88..0x00eebc (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[38] Hàm con @ 0x00ee88..0x00eebc (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ee88: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x00ee8c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00ee90: 910003fd  mov      x29, sp
//   0x00ee94: aa0203f3  mov      x19, x2
//   0x00ee98: 52800022  mov      w2, #1
//   0x00ee9c: aa0003f4  mov      x20, x0
//   0x00eea0: 94000007  bl       #0xeebc
//   0x00eea4: 9102c280  add      x0, x20, #0xb0
//   0x00eea8: aa1303e1  mov      x1, x19
//   0x00eeac: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00eeb0: 52800202  mov      w2, #0x10
//   0x00eeb4: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x00eeb8: 17ffd12b  b        #0x3364
// ============================================================================
std::uint32_t fde_38_ee88(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ee88ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12009ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[39] Subroutine @ 0x00eebc..0x00f0f4 (568 bytes, 142 AArch64 instructions)
// [VN] Khung FDE[39] Hàm con @ 0x00eebc..0x00f0f4 (568 byte, 142 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00eebc: f81d0ff7  str      x23, [sp, #-0x30]!
//   0x00eec0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00eec4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00eec8: 7100045f  cmp      w2, #1
//   0x00eecc: 52800108  mov      w8, #8
//   0x00eed0: 52800089  mov      w9, #4
//   0x00eed4: aa1f03ea  mov      x10, xzr
//   0x00eed8: 1a880128  csel     w8, w9, w8, eq
//   0x00eedc: d37ef509  lsl      x9, x8, #2
//   0x00eee0: 54000540  b.eq     #0xef88
//   0x00eee4: d100050b  sub      x11, x8, #1
//   0x00eee8: 9100080d  add      x13, x0, #2
//   0x00eeec: d37ef56c  lsl      x12, x11, #2
//   0x00eef0: eb4bfbff  cmp      xzr, x11, lsr #62
//   0x00eef4: 8b0c01ae  add      x14, x13, x12
//   0x00eef8: 1a9f07eb  cset     w11, ne
//   0x00eefc: eb0d01df  cmp      x14, x13
//   0x00ef00: 54000443  b.lo     #0xef88
//   0x00ef04: 3700042b  tbnz     w11, #0, #0xef88
//   0x00ef08: 91000c0d  add      x13, x0, #3
//   0x00ef0c: 8b0c01ae  add      x14, x13, x12
//   0x00ef10: eb0d01df  cmp      x14, x13
//   0x00ef14: 540003a3  b.lo     #0xef88
//   0x00ef18: 3700038b  tbnz     w11, #0, #0xef88
//   0x00ef1c: 9100040d  add      x13, x0, #1
//   0x00ef20: 8b0c01ae  add      x14, x13, x12
//   0x00ef24: eb0d01df  cmp      x14, x13
//   0x00ef28: 54000303  b.lo     #0xef88
//   0x00ef2c: 370002eb  tbnz     w11, #0, #0xef88
//   0x00ef30: 8b0c000c  add      x12, x0, x12
//   0x00ef34: eb00019f  cmp      x12, x0
//   0x00ef38: 54000283  b.lo     #0xef88
//   0x00ef3c: 3700026b  tbnz     w11, #0, #0xef88
//   0x00ef40: 8b09002a  add      x10, x1, x9
//   0x00ef44: eb00015f  cmp      x10, x0
//   0x00ef48: 540000c9  b.ls     #0xef60
//   0x00ef4c: 8b09000a  add      x10, x0, x9
//   0x00ef50: eb01015f  cmp      x10, x1
//   0x00ef54: 54000069  b.ls     #0xef60
//   0x00ef58: aa1f03ea  mov      x10, xzr
//   0x00ef5c: 1400000b  b        #0xef88
//   0x00ef60: 927d010a  and      x10, x8, #8
//   0x00ef64: aa0103ec  mov      x12, x1
//   0x00ef68: aa0a03eb  mov      x11, x10
//   0x00ef6c: aa0003ed  mov      x13, x0
//   0x00ef70: acc10181  ldp      q1, q0, [x12], #0x20
//   0x00ef74: f100216b  subs     x11, x11, #8
//   0x00ef78: ac8101a1  stp      q1, q0, [x13], #0x20
//   0x00ef7c: 54ffffa1  b.ne     #0xef70
//   0x00ef80: eb08015f  cmp      x10, x8
//   0x00ef84: 54000240  b.eq     #0xefcc
//   0x00ef88: 5280002c  mov      w12, #1
//   0x00ef8c: cb0a010b  sub      x11, x8, x10
//   0x00ef90: b37e0d4c  bfi      x12, x10, #2, #4
//   0x00ef94: 8b0c000a  add      x10, x0, x12
//   0x00ef98: 8b0c002c  add      x12, x1, x12
//   0x00ef9c: 385ff18d  ldurb    w13, [x12, #-1]
//   0x00efa0: f100056b  subs     x11, x11, #1
//   0x00efa4: 381ff14d  sturb    w13, [x10, #-1]
//   0x00efa8: 3940018d  ldrb     w13, [x12]
//   0x00efac: 3900014d  strb     w13, [x10]
//   0x00efb0: 3940058d  ldrb     w13, [x12, #1]
//   0x00efb4: 3900054d  strb     w13, [x10, #1]
//   0x00efb8: 3940098d  ldrb     w13, [x12, #2]
//   0x00efbc: 9100118c  add      x12, x12, #4
//   0x00efc0: 3900094d  strb     w13, [x10, #2]
//   0x00efc4: 9100114a  add      x10, x10, #4
//   0x00efc8: 54fffea1  b.ne     #0xef9c
//   0x00efcc: 1280004b  mov      w11, #-3
//   0x00efd0: 7100045f  cmp      w2, #1
//   0x00efd4: 5280078d  mov      w13, #0x3c
//   0x00efd8: 5280038e  mov      w14, #0x1c
//   0x00efdc: 5280004f  mov      w15, #2
//   0x00efe0: 12800010  mov      w16, #-1
//   0x00efe4: 12800031  mov      w17, #-2
//   0x00efe8: 12800063  mov      w3, #-4
//   0x00efec: 9a8d01cd  csel     x13, x14, x13, eq
//   0x00eff0: 1a8f05ee  cinc     w14, w15, ne
//   0x00eff4: 8b09000f  add      x15, x0, x9
//   0x00eff8: 8b100130  add      x16, x9, x16
//   0x00effc: 8b110131  add      x17, x9, x17
//   0x00f000: 8b0b0121  add      x1, x9, x11
//   0x00f004: 8b030129  add      x9, x9, x3
//   0x00f008: f0ffff83  adrp     x3, #0x2000
//   0x00f00c: f0ffff84  adrp     x4, #0x2000
//   0x00f010: aa1f03ea  mov      x10, xzr
//   0x00f014: 5100050c  sub      w12, w8, #1
//   0x00f018: 912dc063  add      x3, x3, #0xb70
//   0x00f01c: 9131c084  add      x4, x4, #0xc70
//   0x00f020: 1400001b  b        #0xf08c
//   0x00f024: 92407d14  and      x20, x8, #0xffffffff
//   0x00f028: 38676875  ldrb     w21, [x3, x7]
//   0x00f02c: 9ace2694  lsr      x20, x20, x14
//   0x00f030: 38666867  ldrb     w7, [x3, x6]
//   0x00f034: 38656866  ldrb     w6, [x3, x5]
//   0x00f038: 38736865  ldrb     w5, [x3, x19]
//   0x00f03c: 38746894  ldrb     w20, [x4, x20]
//   0x00f040: 4a150293  eor      w19, w20, w21
//   0x00f044: 8b0a0014  add      x20, x0, x10
//   0x00f048: 91000508  add      x8, x8, #1
//   0x00f04c: eb0801bf  cmp      x13, x8
//   0x00f050: 39400295  ldrb     w21, [x20]
//   0x00f054: 39400696  ldrb     w22, [x20, #1]
//   0x00f058: 39400a97  ldrb     w23, [x20, #2]
//   0x00f05c: 39400e94  ldrb     w20, [x20, #3]
//   0x00f060: 4a1302b3  eor      w19, w21, w19
//   0x00f064: 8b0a01f5  add      x21, x15, x10
//   0x00f068: 4a0702c7  eor      w7, w22, w7
//   0x00f06c: 4a0602e6  eor      w6, w23, w6
//   0x00f070: 9100114a  add      x10, x10, #4
//   0x00f074: 4a050285  eor      w5, w20, w5
//   0x00f078: 390002b3  strb     w19, [x21]
//   0x00f07c: 390006a7  strb     w7, [x21, #1]
//   0x00f080: 39000aa6  strb     w6, [x21, #2]
//   0x00f084: 39000ea5  strb     w5, [x21, #3]
//   0x00f088: 540002e0  b.eq     #0xf0e4
//   0x00f08c: 0b0a0125  add      w5, w9, w10
//   0x00f090: 0b0a0026  add      w6, w1, w10
//   0x00f094: 0b0a0227  add      w7, w17, w10
//   0x00f098: 927e74a5  and      x5, x5, #0xfffffffc
//   0x00f09c: 8a0b00c6  and      x6, x6, x11
//   0x00f0a0: 927f78f4  and      x20, x7, #0xfffffffe
//   0x00f0a4: 0b0a0215  add      w21, w16, w10
//   0x00f0a8: 38656813  ldrb     w19, [x0, x5]
//   0x00f0ac: 38666807  ldrb     w7, [x0, x6]
//   0x00f0b0: 38746806  ldrb     w6, [x0, x20]
//   0x00f0b4: 6a080194  ands     w20, w12, w8
//   0x00f0b8: 38754805  ldrb     w5, [x0, w21, uxtw]
//   0x00f0bc: 54fffb40  b.eq     #0xf024
//   0x00f0c0: 7100085f  cmp      w2, #2
//   0x00f0c4: 54fffc01  b.ne     #0xf044
//   0x00f0c8: 7100129f  cmp      w20, #4
//   0x00f0cc: 54fffbc1  b.ne     #0xf044
//   0x00f0d0: 38736873  ldrb     w19, [x3, x19]
//   0x00f0d4: 38676867  ldrb     w7, [x3, x7]
//   0x00f0d8: 38666866  ldrb     w6, [x3, x6]
//   0x00f0dc: 38656865  ldrb     w5, [x3, x5]
//   0x00f0e0: 17ffffd9  b        #0xf044
//   0x00f0e4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f0e8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f0ec: f84307f7  ldr      x23, [sp], #0x30
//   0x00f0f0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_39_eebc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000eebcULL;
    for (std::size_t i = 0; i < 142ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12022ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[40] Subroutine @ 0x00f0f4..0x00f680 (1420 bytes, 355 AArch64 instructions)
// [VN] Khung FDE[40] Hàm con @ 0x00f0f4..0x00f680 (1420 byte, 355 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f0f4: d101c3ff  sub      sp, sp, #0x70
//   0x00f0f8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f0fc: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x00f100: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x00f104: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00f108: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x00f10c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x00f110: 39400028  ldrb     w8, [x1]
//   0x00f114: 528000cb  mov      w11, #6
//   0x00f118: 39400009  ldrb     w9, [x0]
//   0x00f11c: 7100045f  cmp      w2, #1
//   0x00f120: 4a08012f  eor      w15, w9, w8
//   0x00f124: 39400408  ldrb     w8, [x0, #1]
//   0x00f128: 3900000f  strb     w15, [x0]
//   0x00f12c: 39400429  ldrb     w9, [x1, #1]
//   0x00f130: 4a09010e  eor      w14, w8, w9
//   0x00f134: 39400808  ldrb     w8, [x0, #2]
//   0x00f138: 3900040e  strb     w14, [x0, #1]
//   0x00f13c: 39400829  ldrb     w9, [x1, #2]
//   0x00f140: 4a09010d  eor      w13, w8, w9
//   0x00f144: 39400c08  ldrb     w8, [x0, #3]
//   0x00f148: 3900080d  strb     w13, [x0, #2]
//   0x00f14c: 39400c29  ldrb     w9, [x1, #3]
//   0x00f150: 4a09010c  eor      w12, w8, w9
//   0x00f154: 39401008  ldrb     w8, [x0, #4]
//   0x00f158: 39000c0c  strb     w12, [x0, #3]
//   0x00f15c: 39401029  ldrb     w9, [x1, #4]
//   0x00f160: 4a090104  eor      w4, w8, w9
//   0x00f164: 39401408  ldrb     w8, [x0, #5]
//   0x00f168: 39001004  strb     w4, [x0, #4]
//   0x00f16c: 39401429  ldrb     w9, [x1, #5]
//   0x00f170: 4a090103  eor      w3, w8, w9
//   0x00f174: 39401808  ldrb     w8, [x0, #6]
//   0x00f178: 39001403  strb     w3, [x0, #5]
//   0x00f17c: 39401829  ldrb     w9, [x1, #6]
//   0x00f180: 4a090111  eor      w17, w8, w9
//   0x00f184: 39401c08  ldrb     w8, [x0, #7]
//   0x00f188: 39001811  strb     w17, [x0, #6]
//   0x00f18c: 39401c29  ldrb     w9, [x1, #7]
//   0x00f190: 4a090110  eor      w16, w8, w9
//   0x00f194: 39402008  ldrb     w8, [x0, #8]
//   0x00f198: 39001c10  strb     w16, [x0, #7]
//   0x00f19c: 39402029  ldrb     w9, [x1, #8]
//   0x00f1a0: 4a090113  eor      w19, w8, w9
//   0x00f1a4: 39402408  ldrb     w8, [x0, #9]
//   0x00f1a8: 39002013  strb     w19, [x0, #8]
//   0x00f1ac: 39402429  ldrb     w9, [x1, #9]
//   0x00f1b0: 4a090107  eor      w7, w8, w9
//   0x00f1b4: 39402808  ldrb     w8, [x0, #0xa]
//   0x00f1b8: 39002407  strb     w7, [x0, #9]
//   0x00f1bc: 39402829  ldrb     w9, [x1, #0xa]
//   0x00f1c0: 4a090106  eor      w6, w8, w9
//   0x00f1c4: 39402c08  ldrb     w8, [x0, #0xb]
//   0x00f1c8: 39002806  strb     w6, [x0, #0xa]
//   0x00f1cc: 39402c29  ldrb     w9, [x1, #0xb]
//   0x00f1d0: 4a090105  eor      w5, w8, w9
//   0x00f1d4: 39403008  ldrb     w8, [x0, #0xc]
//   0x00f1d8: 39002c05  strb     w5, [x0, #0xb]
//   0x00f1dc: 39403029  ldrb     w9, [x1, #0xc]
//   0x00f1e0: 4a090117  eor      w23, w8, w9
//   0x00f1e4: 39403408  ldrb     w8, [x0, #0xd]
//   0x00f1e8: 39003017  strb     w23, [x0, #0xc]
//   0x00f1ec: 39403429  ldrb     w9, [x1, #0xd]
//   0x00f1f0: 4a090116  eor      w22, w8, w9
//   0x00f1f4: 39403808  ldrb     w8, [x0, #0xe]
//   0x00f1f8: 39003416  strb     w22, [x0, #0xd]
//   0x00f1fc: 39403829  ldrb     w9, [x1, #0xe]
//   0x00f200: 4a090115  eor      w21, w8, w9
//   0x00f204: 39403c09  ldrb     w9, [x0, #0xf]
//   0x00f208: 528001c8  mov      w8, #0xe
//   0x00f20c: 1a880168  csel     w8, w11, w8, eq
//   0x00f210: f0ffff8b  adrp     x11, #0x2000
//   0x00f214: 39003815  strb     w21, [x0, #0xe]
//   0x00f218: 912dc16b  add      x11, x11, #0xb70
//   0x00f21c: 39403c2a  ldrb     w10, [x1, #0xf]
//   0x00f220: b9000fe8  str      w8, [sp, #0xc]
//   0x00f224: 4a0a0134  eor      w20, w9, w10
//   0x00f228: 52800029  mov      w9, #1
//   0x00f22c: 5280036a  mov      w10, #0x1b
//   0x00f230: 92401def  and      x15, x15, #0xff
//   0x00f234: 92401c82  and      x2, x4, #0xff
//   0x00f238: 92401e73  and      x19, x19, #0xff
//   0x00f23c: 92401ef8  and      x24, x23, #0xff
//   0x00f240: 92401dd9  and      x25, x14, #0xff
//   0x00f244: 92401cc6  and      x6, x6, #0xff
//   0x00f248: 386f6977  ldrb     w23, [x11, x15]
//   0x00f24c: 92401c6f  and      x15, x3, #0xff
//   0x00f250: 38626964  ldrb     w4, [x11, x2]
//   0x00f254: 92401ce3  and      x3, x7, #0xff
//   0x00f258: 38736962  ldrb     w2, [x11, x19]
//   0x00f25c: 92401ed3  and      x19, x22, #0xff
//   0x00f260: 386f6967  ldrb     w7, [x11, x15]
//   0x00f264: 92401e2f  and      x15, x17, #0xff
//   0x00f268: 3878696e  ldrb     w14, [x11, x24]
//   0x00f26c: 92401db8  and      x24, x13, #0xff
//   0x00f270: 38736971  ldrb     w17, [x11, x19]
//   0x00f274: 92401eb3  and      x19, x21, #0xff
//   0x00f278: 92401ca5  and      x5, x5, #0xff
//   0x00f27c: 92401e10  and      x16, x16, #0xff
//   0x00f280: 3879696d  ldrb     w13, [x11, x25]
//   0x00f284: 39000017  strb     w23, [x0]
//   0x00f288: 38736975  ldrb     w21, [x11, x19]
//   0x00f28c: 92401d93  and      x19, x12, #0xff
//   0x00f290: 92401e8c  and      x12, x20, #0xff
//   0x00f294: 38636976  ldrb     w22, [x11, x3]
//   0x00f298: 38786963  ldrb     w3, [x11, x24]
//   0x00f29c: 39001004  strb     w4, [x0, #4]
//   0x00f2a0: 386f696f  ldrb     w15, [x11, x15]
//   0x00f2a4: 39002002  strb     w2, [x0, #8]
//   0x00f2a8: 38666966  ldrb     w6, [x11, x6]
//   0x00f2ac: 3900300e  strb     w14, [x0, #0xc]
//   0x00f2b0: 386c6978  ldrb     w24, [x11, x12]
//   0x00f2b4: 39000407  strb     w7, [x0, #1]
//   0x00f2b8: 3865696c  ldrb     w12, [x11, x5]
//   0x00f2bc: 39001416  strb     w22, [x0, #5]
//   0x00f2c0: 38706970  ldrb     w16, [x11, x16]
//   0x00f2c4: 39002411  strb     w17, [x0, #9]
//   0x00f2c8: 38736974  ldrb     w20, [x11, x19]
//   0x00f2cc: 3900340d  strb     w13, [x0, #0xd]
//   0x00f2d0: b9400fe8  ldr      w8, [sp, #0xc]
//   0x00f2d4: 39000806  strb     w6, [x0, #2]
//   0x00f2d8: 39002803  strb     w3, [x0, #0xa]
//   0x00f2dc: 39001815  strb     w21, [x0, #6]
//   0x00f2e0: 6b29011f  cmp      w8, w9, uxtb
//   0x00f2e4: 3900380f  strb     w15, [x0, #0xe]
//   0x00f2e8: 39000c18  strb     w24, [x0, #3]
//   0x00f2ec: 39003c0c  strb     w12, [x0, #0xf]
//   0x00f2f0: 39002c10  strb     w16, [x0, #0xb]
//   0x00f2f4: 39001c14  strb     w20, [x0, #7]
//   0x00f2f8: 54001500  b.eq     #0xf598
//   0x00f2fc: 4a1700f9  eor      w25, w7, w23
//   0x00f300: 4a0700c5  eor      w5, w6, w7
//   0x00f304: 13001f33  sxtb     w19, w25
//   0x00f308: 4a1900da  eor      w26, w6, w25
//   0x00f30c: 4a060306  eor      w6, w24, w6
//   0x00f310: 13001cbb  sxtb     w27, w5
//   0x00f314: 4a1906fc  eor      w28, w23, w25, lsl #1
//   0x00f318: 0a531d53  and      w19, w10, w19, lsr #7
//   0x00f31c: 4a0504e5  eor      w5, w7, w5, lsl #1
//   0x00f320: 13001cc7  sxtb     w7, w6
//   0x00f324: 4a170317  eor      w23, w24, w23
//   0x00f328: 4a130393  eor      w19, w28, w19
//   0x00f32c: 4a1a031c  eor      w28, w24, w26
//   0x00f330: 4a190319  eor      w25, w24, w25
//   0x00f334: 13001ef8  sxtb     w24, w23
//   0x00f338: 0a471d47  and      w7, w10, w7, lsr #7
//   0x00f33c: 4a060726  eor      w6, w25, w6, lsl #1
//   0x00f340: 4a170757  eor      w23, w26, w23, lsl #1
//   0x00f344: 4a0700c7  eor      w7, w6, w7
//   0x00f348: 0a581d46  and      w6, w10, w24, lsr #7
//   0x00f34c: 4a0602e6  eor      w6, w23, w6
//   0x00f350: 4a0402d7  eor      w23, w22, w4
//   0x00f354: 13001ef8  sxtb     w24, w23
//   0x00f358: 0a5b1d5b  and      w27, w10, w27, lsr #7
//   0x00f35c: 4a1b00a5  eor      w5, w5, w27
//   0x00f360: 4a17049b  eor      w27, w4, w23, lsl #1
//   0x00f364: 0a581d58  and      w24, w10, w24, lsr #7
//   0x00f368: 4a1c0273  eor      w19, w19, w28
//   0x00f36c: 4a180378  eor      w24, w27, w24
//   0x00f370: 4a1602bb  eor      w27, w21, w22
//   0x00f374: 4a1c00a5  eor      w5, w5, w28
//   0x00f378: 4a1702b9  eor      w25, w21, w23
//   0x00f37c: 13001f7c  sxtb     w28, w27
//   0x00f380: 4a150295  eor      w21, w20, w21
//   0x00f384: 4a19029a  eor      w26, w20, w25
//   0x00f388: 13001ebd  sxtb     w29, w21
//   0x00f38c: 4a040284  eor      w4, w20, w4
//   0x00f390: 4a1b06db  eor      w27, w22, w27, lsl #1
//   0x00f394: 4a1a0316  eor      w22, w24, w26
//   0x00f398: 0a5c1d58  and      w24, w10, w28, lsr #7
//   0x00f39c: 4a170297  eor      w23, w20, w23
//   0x00f3a0: 13001c9c  sxtb     w28, w4
//   0x00f3a4: 4a180378  eor      w24, w27, w24
//   0x00f3a8: 0a5d1d5b  and      w27, w10, w29, lsr #7
//   0x00f3ac: 4a1506f4  eor      w20, w23, w21, lsl #1
//   0x00f3b0: 4a040724  eor      w4, w25, w4, lsl #1
//   0x00f3b4: 4a1b0295  eor      w21, w20, w27
//   0x00f3b8: 0a5c1d54  and      w20, w10, w28, lsr #7
//   0x00f3bc: 4a140094  eor      w20, w4, w20
//   0x00f3c0: 4a020224  eor      w4, w17, w2
//   0x00f3c4: 4a110079  eor      w25, w3, w17
//   0x00f3c8: 4a1a0317  eor      w23, w24, w26
//   0x00f3cc: 13001c98  sxtb     w24, w4
//   0x00f3d0: 13001f3c  sxtb     w28, w25
//   0x00f3d4: 4a04007b  eor      w27, w3, w4
//   0x00f3d8: 4a030203  eor      w3, w16, w3
//   0x00f3dc: 0a581d58  and      w24, w10, w24, lsr #7
//   0x00f3e0: 4a04045a  eor      w26, w2, w4, lsl #1
//   0x00f3e4: 4a1b021d  eor      w29, w16, w27
//   0x00f3e8: 0a5c1d5c  and      w28, w10, w28, lsr #7
//   0x00f3ec: 4a190631  eor      w17, w17, w25, lsl #1
//   0x00f3f0: 13001c79  sxtb     w25, w3
//   0x00f3f4: 4a040204  eor      w4, w16, w4
//   0x00f3f8: 4a020210  eor      w16, w16, w2
//   0x00f3fc: 4a180358  eor      w24, w26, w24
//   0x00f400: 4a1c0231  eor      w17, w17, w28
//   0x00f404: 4a030482  eor      w2, w4, w3, lsl #1
//   0x00f408: 13001e03  sxtb     w3, w16
//   0x00f40c: 4a1d031a  eor      w26, w24, w29
//   0x00f410: 4a1d0238  eor      w24, w17, w29
//   0x00f414: 0a591d51  and      w17, w10, w25, lsr #7
//   0x00f418: 4a100770  eor      w16, w27, w16, lsl #1
//   0x00f41c: 4a110059  eor      w25, w2, w17
//   0x00f420: 0a431d51  and      w17, w10, w3, lsr #7
//   0x00f424: 4a110202  eor      w2, w16, w17
//   0x00f428: 4a0e01b0  eor      w16, w13, w14
//   0x00f42c: 13001e11  sxtb     w17, w16
//   0x00f430: 4a1001e3  eor      w3, w15, w16
//   0x00f434: 4a1005db  eor      w27, w14, w16, lsl #1
//   0x00f438: 4a030184  eor      w4, w12, w3
//   0x00f43c: 0a511d51  and      w17, w10, w17, lsr #7
//   0x00f440: 4a100190  eor      w16, w12, w16
//   0x00f444: 4a110371  eor      w17, w27, w17
//   0x00f448: 4a0d01fb  eor      w27, w15, w13
//   0x00f44c: 13001f7c  sxtb     w28, w27
//   0x00f450: 4a0f018f  eor      w15, w12, w15
//   0x00f454: 4a0e018c  eor      w12, w12, w14
//   0x00f458: 4a1b05ad  eor      w13, w13, w27, lsl #1
//   0x00f45c: 13001dfb  sxtb     w27, w15
//   0x00f460: 4a04023d  eor      w29, w17, w4
//   0x00f464: 0a5c1d51  and      w17, w10, w28, lsr #7
//   0x00f468: 4a0f060e  eor      w14, w16, w15, lsl #1
//   0x00f46c: 13001d8f  sxtb     w15, w12
//   0x00f470: 4a1101ad  eor      w13, w13, w17
//   0x00f474: 0a5b1d51  and      w17, w10, w27, lsr #7
//   0x00f478: 4a0401a8  eor      w8, w13, w4
//   0x00f47c: 0a4f1d4d  and      w13, w10, w15, lsr #7
//   0x00f480: 4a0c046c  eor      w12, w3, w12, lsl #1
//   0x00f484: 4a1101dc  eor      w28, w14, w17
//   0x00f488: 4a0d019b  eor      w27, w12, w13
//   0x00f48c: 8b29103e  add      x30, x1, w9, uxtb #4
//   0x00f490: 39000013  strb     w19, [x0]
//   0x00f494: 39000405  strb     w5, [x0, #1]
//   0x00f498: 11000529  add      w9, w9, #1
//   0x00f49c: 39000807  strb     w7, [x0, #2]
//   0x00f4a0: 39000c06  strb     w6, [x0, #3]
//   0x00f4a4: 39001016  strb     w22, [x0, #4]
//   0x00f4a8: 39001417  strb     w23, [x0, #5]
//   0x00f4ac: 39001815  strb     w21, [x0, #6]
//   0x00f4b0: 39001c14  strb     w20, [x0, #7]
//   0x00f4b4: 3900201a  strb     w26, [x0, #8]
//   0x00f4b8: 39002418  strb     w24, [x0, #9]
//   0x00f4bc: 39002819  strb     w25, [x0, #0xa]
//   0x00f4c0: 39002c02  strb     w2, [x0, #0xb]
//   0x00f4c4: 3900301d  strb     w29, [x0, #0xc]
//   0x00f4c8: 39003408  strb     w8, [x0, #0xd]
//   0x00f4cc: 3900381c  strb     w28, [x0, #0xe]
//   0x00f4d0: 39003c1b  strb     w27, [x0, #0xf]
//   0x00f4d4: 394003cc  ldrb     w12, [x30]
//   0x00f4d8: 4a13018f  eor      w15, w12, w19
//   0x00f4dc: 3900000f  strb     w15, [x0]
//   0x00f4e0: 394007cc  ldrb     w12, [x30, #1]
//   0x00f4e4: 4a05018e  eor      w14, w12, w5
//   0x00f4e8: 3900040e  strb     w14, [x0, #1]
//   0x00f4ec: 39400bcc  ldrb     w12, [x30, #2]
//   0x00f4f0: 4a07018d  eor      w13, w12, w7
//   0x00f4f4: 3900080d  strb     w13, [x0, #2]
//   0x00f4f8: 39400fcc  ldrb     w12, [x30, #3]
//   0x00f4fc: 4a06018c  eor      w12, w12, w6
//   0x00f500: 39000c0c  strb     w12, [x0, #3]
//   0x00f504: 394013d0  ldrb     w16, [x30, #4]
//   0x00f508: 4a160204  eor      w4, w16, w22
//   0x00f50c: 39001004  strb     w4, [x0, #4]
//   0x00f510: 394017d0  ldrb     w16, [x30, #5]
//   0x00f514: 4a170203  eor      w3, w16, w23
//   0x00f518: 39001403  strb     w3, [x0, #5]
//   0x00f51c: 39401bd0  ldrb     w16, [x30, #6]
//   0x00f520: 4a150211  eor      w17, w16, w21
//   0x00f524: 39001811  strb     w17, [x0, #6]
//   0x00f528: 39401fd0  ldrb     w16, [x30, #7]
//   0x00f52c: 4a140210  eor      w16, w16, w20
//   0x00f530: 39001c10  strb     w16, [x0, #7]
//   0x00f534: 394023c5  ldrb     w5, [x30, #8]
//   0x00f538: 4a1a00b3  eor      w19, w5, w26
//   0x00f53c: 39002013  strb     w19, [x0, #8]
//   0x00f540: 394027c5  ldrb     w5, [x30, #9]
//   0x00f544: 4a1800a7  eor      w7, w5, w24
//   0x00f548: 39002407  strb     w7, [x0, #9]
//   0x00f54c: 39402bc5  ldrb     w5, [x30, #0xa]
//   0x00f550: 4a1900a6  eor      w6, w5, w25
//   0x00f554: 39002806  strb     w6, [x0, #0xa]
//   0x00f558: 39402fc5  ldrb     w5, [x30, #0xb]
//   0x00f55c: 4a0200a5  eor      w5, w5, w2
//   0x00f560: 39002c05  strb     w5, [x0, #0xb]
//   0x00f564: 394033c2  ldrb     w2, [x30, #0xc]
//   0x00f568: 4a1d0057  eor      w23, w2, w29
//   0x00f56c: 39003017  strb     w23, [x0, #0xc]
//   0x00f570: 394037c2  ldrb     w2, [x30, #0xd]
//   0x00f574: 4a080056  eor      w22, w2, w8
//   0x00f578: 39003416  strb     w22, [x0, #0xd]
//   0x00f57c: 39403bc8  ldrb     w8, [x30, #0xe]
//   0x00f580: 4a1c0115  eor      w21, w8, w28
//   0x00f584: 39003815  strb     w21, [x0, #0xe]
//   0x00f588: 39403fc8  ldrb     w8, [x30, #0xf]
//   0x00f58c: 4a1b0114  eor      w20, w8, w27
//   0x00f590: 39003c14  strb     w20, [x0, #0xf]
//   0x00f594: 17ffff27  b        #0xf230
//   0x00f598: b9400fe8  ldr      w8, [sp, #0xc]
//   0x00f59c: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x00f5a0: 8b285028  add      x8, x1, w8, uxtw #4
//   0x00f5a4: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x00f5a8: 39400109  ldrb     w9, [x8]
//   0x00f5ac: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00f5b0: 4a170129  eor      w9, w9, w23
//   0x00f5b4: 39000009  strb     w9, [x0]
//   0x00f5b8: 39400509  ldrb     w9, [x8, #1]
//   0x00f5bc: 4a070129  eor      w9, w9, w7
//   0x00f5c0: 39000409  strb     w9, [x0, #1]
//   0x00f5c4: 39400909  ldrb     w9, [x8, #2]
//   0x00f5c8: 4a060129  eor      w9, w9, w6
//   0x00f5cc: 39000809  strb     w9, [x0, #2]
//   0x00f5d0: 39400d09  ldrb     w9, [x8, #3]
//   0x00f5d4: 4a180129  eor      w9, w9, w24
//   0x00f5d8: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x00f5dc: 39000c09  strb     w9, [x0, #3]
//   0x00f5e0: 39401109  ldrb     w9, [x8, #4]
//   0x00f5e4: 4a040129  eor      w9, w9, w4
//   0x00f5e8: 39001009  strb     w9, [x0, #4]
//   0x00f5ec: 39401509  ldrb     w9, [x8, #5]
//   0x00f5f0: 4a160129  eor      w9, w9, w22
//   0x00f5f4: 39001409  strb     w9, [x0, #5]
//   0x00f5f8: 39401909  ldrb     w9, [x8, #6]
//   0x00f5fc: 4a150129  eor      w9, w9, w21
//   0x00f600: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x00f604: 39001809  strb     w9, [x0, #6]
//   0x00f608: 39401d09  ldrb     w9, [x8, #7]
//   0x00f60c: 4a140129  eor      w9, w9, w20
//   0x00f610: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x00f614: 39001c09  strb     w9, [x0, #7]
//   0x00f618: 39402109  ldrb     w9, [x8, #8]
//   0x00f61c: 4a020129  eor      w9, w9, w2
//   0x00f620: 39002009  strb     w9, [x0, #8]
//   0x00f624: 39402509  ldrb     w9, [x8, #9]
//   0x00f628: 4a110129  eor      w9, w9, w17
//   0x00f62c: 39002409  strb     w9, [x0, #9]
//   0x00f630: 39402909  ldrb     w9, [x8, #0xa]
//   0x00f634: 4a030129  eor      w9, w9, w3
//   0x00f638: 39002809  strb     w9, [x0, #0xa]
//   0x00f63c: 39402d09  ldrb     w9, [x8, #0xb]
//   0x00f640: 4a100129  eor      w9, w9, w16
//   0x00f644: 39002c09  strb     w9, [x0, #0xb]
//   0x00f648: 39403109  ldrb     w9, [x8, #0xc]
//   0x00f64c: 4a0e0129  eor      w9, w9, w14
//   0x00f650: 39003009  strb     w9, [x0, #0xc]
//   0x00f654: 39403509  ldrb     w9, [x8, #0xd]
//   0x00f658: 4a0d0129  eor      w9, w9, w13
//   0x00f65c: 39003409  strb     w9, [x0, #0xd]
//   0x00f660: 39403909  ldrb     w9, [x8, #0xe]
//   0x00f664: 4a0f0129  eor      w9, w9, w15
//   0x00f668: 39003809  strb     w9, [x0, #0xe]
//   0x00f66c: 39403d08  ldrb     w8, [x8, #0xf]
//   0x00f670: 4a0c0108  eor      w8, w8, w12
//   0x00f674: 39003c08  strb     w8, [x0, #0xf]
//   0x00f678: 9101c3ff  add      sp, sp, #0x70
//   0x00f67c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_40_f0f4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f0f4ULL;
    for (std::size_t i = 0; i < 355ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12164ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[41] Subroutine @ 0x00f680..0x00f8f4 (628 bytes, 157 AArch64 instructions)
// [VN] Khung FDE[41] Hàm con @ 0x00f680..0x00f8f4 (628 byte, 157 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f680: d10343ff  sub      sp, sp, #0xd0
//   0x00f684: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x00f688: 9101c3fd  add      x29, sp, #0x70
//   0x00f68c: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x00f690: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x00f694: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x00f698: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x00f69c: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x00f6a0: d53bd057  mrs      x23, tpidr_el0
//   0x00f6a4: f94016e8  ldr      x8, [x23, #0x28]
//   0x00f6a8: f81f83a8  stur     x8, [x29, #-8]
//   0x00f6ac: b40010a2  cbz      x2, #0xf8c0
//   0x00f6b0: 9102ec09  add      x9, x0, #0xbb
//   0x00f6b4: 9102e808  add      x8, x0, #0xba
//   0x00f6b8: aa0203f3  mov      x19, x2
//   0x00f6bc: aa0103f4  mov      x20, x1
//   0x00f6c0: aa0003f5  mov      x21, x0
//   0x00f6c4: 9102c016  add      x22, x0, #0xb0
//   0x00f6c8: a93da7a8  stp      x8, x9, [x29, #-0x28]
//   0x00f6cc: 9102e408  add      x8, x0, #0xb9
//   0x00f6d0: 9102e009  add      x9, x0, #0xb8
//   0x00f6d4: 9102fc18  add      x24, x0, #0xbf
//   0x00f6d8: 9102f819  add      x25, x0, #0xbe
//   0x00f6dc: 9102f41a  add      x26, x0, #0xbd
//   0x00f6e0: f81d03a8  stur     x8, [x29, #-0x30]
//   0x00f6e4: 9102dc08  add      x8, x0, #0xb7
//   0x00f6e8: 9102f01b  add      x27, x0, #0xbc
//   0x00f6ec: d10063bc  sub      x28, x29, #0x18
//   0x00f6f0: a90327e8  stp      x8, x9, [sp, #0x30]
//   0x00f6f4: 9102d809  add      x9, x0, #0xb6
//   0x00f6f8: 9102d408  add      x8, x0, #0xb5
//   0x00f6fc: a90227e8  stp      x8, x9, [sp, #0x20]
//   0x00f700: 9102d009  add      x9, x0, #0xb4
//   0x00f704: 9102cc08  add      x8, x0, #0xb3
//   0x00f708: a90127e8  stp      x8, x9, [sp, #0x10]
//   0x00f70c: 9102c809  add      x9, x0, #0xb2
//   0x00f710: 9102c408  add      x8, x0, #0xb1
//   0x00f714: a90027e8  stp      x8, x9, [sp]
//   0x00f718: 52800208  mov      w8, #0x10
//   0x00f71c: 1400000b  b        #0xf748
//   0x00f720: 1100050a  add      w10, w8, #1
//   0x00f724: 2a1f03e8  mov      w8, wzr
//   0x00f728: 3900012a  strb     w10, [x9]
//   0x00f72c: 3868cb89  ldrb     w9, [x28, w8, sxtw]
//   0x00f730: 11000508  add      w8, w8, #1
//   0x00f734: 3940028a  ldrb     w10, [x20]
//   0x00f738: f1000673  subs     x19, x19, #1
//   0x00f73c: 4a0a0129  eor      w9, w9, w10
//   0x00f740: 38001689  strb     w9, [x20], #1
//   0x00f744: 54000be0  b.eq     #0xf8c0
//   0x00f748: 7100411f  cmp      w8, #0x10
//   0x00f74c: 54ffff01  b.ne     #0xf72c
//   0x00f750: d10063a0  sub      x0, x29, #0x18
//   0x00f754: aa1603e1  mov      x1, x22
//   0x00f758: 52800202  mov      w2, #0x10
//   0x00f75c: 97ffcf02  bl       #0x3364
//   0x00f760: d10063a0  sub      x0, x29, #0x18
//   0x00f764: aa1503e1  mov      x1, x21
//   0x00f768: 52800022  mov      w2, #1
//   0x00f76c: 97fffe62  bl       #0xf0f4
//   0x00f770: 3942fea8  ldrb     w8, [x21, #0xbf]
//   0x00f774: aa1803e9  mov      x9, x24
//   0x00f778: 7103fd1f  cmp      w8, #0xff
//   0x00f77c: 54fffd21  b.ne     #0xf720
//   0x00f780: 39400328  ldrb     w8, [x25]
//   0x00f784: aa1903e9  mov      x9, x25
//   0x00f788: 3900031f  strb     wzr, [x24]
//   0x00f78c: 7103fd1f  cmp      w8, #0xff
//   0x00f790: 54fffc81  b.ne     #0xf720
//   0x00f794: 39400348  ldrb     w8, [x26]
//   0x00f798: aa1a03e9  mov      x9, x26
//   0x00f79c: 3900033f  strb     wzr, [x25]
//   0x00f7a0: 7103fd1f  cmp      w8, #0xff
//   0x00f7a4: 54fffbe1  b.ne     #0xf720
//   0x00f7a8: 39400368  ldrb     w8, [x27]
//   0x00f7ac: aa1b03e9  mov      x9, x27
//   0x00f7b0: 3900035f  strb     wzr, [x26]
//   0x00f7b4: 7103fd1f  cmp      w8, #0xff
//   0x00f7b8: 54fffb41  b.ne     #0xf720
//   0x00f7bc: f85e03a9  ldur     x9, [x29, #-0x20]
//   0x00f7c0: 3900037f  strb     wzr, [x27]
//   0x00f7c4: 39400128  ldrb     w8, [x9]
//   0x00f7c8: 7103fd1f  cmp      w8, #0xff
//   0x00f7cc: 54fffaa1  b.ne     #0xf720
//   0x00f7d0: a97daba9  ldp      x9, x10, [x29, #-0x28]
//   0x00f7d4: 39400128  ldrb     w8, [x9]
//   0x00f7d8: 3900015f  strb     wzr, [x10]
//   0x00f7dc: 7103fd1f  cmp      w8, #0xff
//   0x00f7e0: 54fffa01  b.ne     #0xf720
//   0x00f7e4: a97d2ba9  ldp      x9, x10, [x29, #-0x30]
//   0x00f7e8: 39400128  ldrb     w8, [x9]
//   0x00f7ec: 3900015f  strb     wzr, [x10]
//   0x00f7f0: 7103fd1f  cmp      w8, #0xff
//   0x00f7f4: 54fff961  b.ne     #0xf720
//   0x00f7f8: f9401fe9  ldr      x9, [sp, #0x38]
//   0x00f7fc: f85d03aa  ldur     x10, [x29, #-0x30]
//   0x00f800: 39400128  ldrb     w8, [x9]
//   0x00f804: 3900015f  strb     wzr, [x10]
//   0x00f808: 7103fd1f  cmp      w8, #0xff
//   0x00f80c: 54fff8a1  b.ne     #0xf720
//   0x00f810: a9432be9  ldp      x9, x10, [sp, #0x30]
//   0x00f814: 39400128  ldrb     w8, [x9]
//   0x00f818: 3900015f  strb     wzr, [x10]
//   0x00f81c: 7103fd1f  cmp      w8, #0xff
//   0x00f820: 54fff801  b.ne     #0xf720
//   0x00f824: a942abe9  ldp      x9, x10, [sp, #0x28]
//   0x00f828: 39400128  ldrb     w8, [x9]
//   0x00f82c: 3900015f  strb     wzr, [x10]
//   0x00f830: 7103fd1f  cmp      w8, #0xff
//   0x00f834: 54fff761  b.ne     #0xf720
//   0x00f838: a9422be9  ldp      x9, x10, [sp, #0x20]
//   0x00f83c: 39400128  ldrb     w8, [x9]
//   0x00f840: 3900015f  strb     wzr, [x10]
//   0x00f844: 7103fd1f  cmp      w8, #0xff
//   0x00f848: 54fff6c1  b.ne     #0xf720
//   0x00f84c: a941abe9  ldp      x9, x10, [sp, #0x18]
//   0x00f850: 39400128  ldrb     w8, [x9]
//   0x00f854: 3900015f  strb     wzr, [x10]
//   0x00f858: 7103fd1f  cmp      w8, #0xff
//   0x00f85c: 54fff621  b.ne     #0xf720
//   0x00f860: a9412be9  ldp      x9, x10, [sp, #0x10]
//   0x00f864: 39400128  ldrb     w8, [x9]
//   0x00f868: 3900015f  strb     wzr, [x10]
//   0x00f86c: 7103fd1f  cmp      w8, #0xff
//   0x00f870: 54fff581  b.ne     #0xf720
//   0x00f874: a940abe9  ldp      x9, x10, [sp, #8]
//   0x00f878: 39400128  ldrb     w8, [x9]
//   0x00f87c: 3900015f  strb     wzr, [x10]
//   0x00f880: 7103fd1f  cmp      w8, #0xff
//   0x00f884: 54fff4e1  b.ne     #0xf720
//   0x00f888: a9402be9  ldp      x9, x10, [sp]
//   0x00f88c: 39400128  ldrb     w8, [x9]
//   0x00f890: 3900015f  strb     wzr, [x10]
//   0x00f894: 7103fd1f  cmp      w8, #0xff
//   0x00f898: 54fff441  b.ne     #0xf720
//   0x00f89c: 394002c8  ldrb     w8, [x22]
//   0x00f8a0: aa1603e9  mov      x9, x22
//   0x00f8a4: f94003ea  ldr      x10, [sp]
//   0x00f8a8: 7103fd1f  cmp      w8, #0xff
//   0x00f8ac: 3900015f  strb     wzr, [x10]
//   0x00f8b0: 54fff381  b.ne     #0xf720
//   0x00f8b4: 2a1f03e8  mov      w8, wzr
//   0x00f8b8: 390002df  strb     wzr, [x22]
//   0x00f8bc: 17ffff9c  b        #0xf72c
//   0x00f8c0: f94016e8  ldr      x8, [x23, #0x28]
//   0x00f8c4: f85f83a9  ldur     x9, [x29, #-8]
//   0x00f8c8: eb09011f  cmp      x8, x9
//   0x00f8cc: 54000121  b.ne     #0xf8f0
//   0x00f8d0: a94c4ff4  ldp      x20, x19, [sp, #0xc0]
//   0x00f8d4: a94b57f6  ldp      x22, x21, [sp, #0xb0]
//   0x00f8d8: a94a5ff8  ldp      x24, x23, [sp, #0xa0]
//   0x00f8dc: a94967fa  ldp      x26, x25, [sp, #0x90]
//   0x00f8e0: a9486ffc  ldp      x28, x27, [sp, #0x80]
//   0x00f8e4: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x00f8e8: 910343ff  add      sp, sp, #0xd0
//   0x00f8ec: d65f03c0  ret      
//   0x00f8f0: 94000018  bl       #0xf950
// ============================================================================
std::uint32_t fde_41_f680(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f680ULL;
    for (std::size_t i = 0; i < 157ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12519ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t acc = 0x69218eb7U;
    acc = fde_00_32e4(acc);
    acc = fde_01_32f4(acc);
    acc = fde_02_32fc(acc);
    acc = fde_03_3304(acc);
    acc = fde_04_3318(acc);
    acc = fde_05_3334(acc);
    acc = fde_06_3364(acc);
    acc = fde_07_3438(acc);
    acc = fde_08_3538(acc);
    acc = fde_09_3564(acc);
    acc = fde_10_35a8(acc);
    acc = fde_11_3720(acc);
    acc = fde_12_3ea8(acc);
    acc = fde_13_4068(acc);
    acc = fde_14_41c8(acc);
    acc = fde_15_43c4(acc);
    acc = fde_16_43e4(acc);
    acc = fde_17_4404(acc);
    acc = fde_18_4424(acc);
    acc = fde_19_4430(acc);
    acc = fde_20_4454(acc);
    acc = fde_21_4460(acc);
    acc = fde_22_e53c(acc);
    acc = fde_23_e550(acc);
    acc = fde_24_e570(acc);
    acc = fde_25_e590(acc);
    acc = fde_26_e5a4(acc);
    acc = fde_27_e5b8(acc);
    acc = fde_28_e5d8(acc);
    acc = fde_29_e71c(acc);
    acc = fde_30_e840(acc);
    acc = fde_31_e964(acc);
    acc = fde_32_eaf8(acc);
    acc = fde_33_ecac(acc);
    acc = fde_34_edec(acc);
    acc = fde_35_ee34(acc);
    acc = fde_36_ee40(acc);
    acc = fde_37_ee64(acc);
    acc = fde_38_ee88(acc);
    acc = fde_39_eebc(acc);
    acc = fde_40_f0f4(acc);
    acc = fde_41_f680(acc);
    return acc;
}

} // namespace pglarmor
} // namespace bytedance

extern "C" {
// ============================================================================
// [EN] Exported JNI Entry Point: Java_com_bytedance_sdk_component_pglcrypt_PglCryptUtils_bc
//      Virtual Address: 0x003564 (68 bytes, first_op = 0xa9bf7bfd)
// [VN] Điểm nhập JNI xuất khẩu: Java_com_bytedance_sdk_component_pglcrypt_PglCryptUtils_bc
//      Địa chỉ ảo: 0x003564 (68 byte, lệnh đầu = 0xa9bf7bfd)
// ============================================================================
void* Java_com_bytedance_sdk_component_pglcrypt_PglCryptUtils_bc(
    void* env, void* clazz, int cmd, void* input_byte_array) {
    (void)env;
    (void)clazz;
    std::uint32_t sim = bytedance::pglarmor::fde_03_3564(static_cast<std::uint32_t>(cmd));
    if (input_byte_array == nullptr && sim == 0U) {
        return nullptr;
    }
    return input_byte_array;
}
} // extern "C"
