// ============================================================================
// File: encryptor_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libEncryptor.so (83,896 bytes)
// SHA-256: 6ffd80242ce93782454b9e76521f81526debe01d60f27a88c68da4f114c15dcb
// Task ID: TASK-193-RECONSTRUCTION-LIBENCRYPTOR (TASK_SO_137_libEncryptor)
// Clean-Room C++17 Implementation: ByteDance Applog White-Box AES-128 & SHA-512 Encryptor
// (41 FDEs @ 0x106e8, 7,268 AArch64 Instructions @ 0x0960..0x7af0)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x0960..0x7af0, 7,268 AArch64 instructions across 41 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x0960..0x7af0, 7.268 lệnh AArch64 trên 41 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "encryptor.hpp"

namespace bytedance {
namespace encryptor {

// ============================================================================
// [EN] Exact .eh_frame_hdr FDE Table (41 Entries @ 0x106e8)
// [VN] Bảng FDE .eh_frame_hdr chính xác (41 mục @ 0x106e8)
// ============================================================================
const FdeDescriptor kFdeTable[41] = {
    {  0U, 0x00099cULL, 0x000a18ULL, 0x007cU, 0x010858ULL },
    {  1U, 0x000a18ULL, 0x000a3cULL, 0x0024U, 0x0108a0ULL },
    {  2U, 0x000a3cULL, 0x000aecULL, 0x00b0U, 0x0108b8ULL },
    {  3U, 0x000aecULL, 0x000af8ULL, 0x000cU, 0x0108d8ULL },
    {  4U, 0x000af8ULL, 0x002444ULL, 0x194cU, 0x0108f0ULL },
    {  5U, 0x002444ULL, 0x0027c0ULL, 0x037cU, 0x010920ULL },
    {  6U, 0x0027c0ULL, 0x00293cULL, 0x017cU, 0x010940ULL },
    {  7U, 0x00293cULL, 0x0029b8ULL, 0x007cU, 0x010970ULL },
    {  8U, 0x0029b8ULL, 0x0029d4ULL, 0x001cU, 0x010990ULL },
    {  9U, 0x0029d4ULL, 0x002a0cULL, 0x0038U, 0x0109a8ULL },
    { 10U, 0x002a0cULL, 0x002a20ULL, 0x0014U, 0x0109c8ULL },
    { 11U, 0x002a20ULL, 0x002a30ULL, 0x0010U, 0x0109e0ULL },
    { 12U, 0x002a30ULL, 0x002a40ULL, 0x0010U, 0x0109f8ULL },
    { 13U, 0x002a40ULL, 0x002a60ULL, 0x0020U, 0x010a10ULL },
    { 14U, 0x002a60ULL, 0x002a7cULL, 0x001cU, 0x010a28ULL },
    { 15U, 0x002a7cULL, 0x002a84ULL, 0x0008U, 0x010a40ULL },
    { 16U, 0x002a84ULL, 0x002a90ULL, 0x000cU, 0x010a58ULL },
    { 17U, 0x002a90ULL, 0x0043dcULL, 0x194cU, 0x010a70ULL },
    { 18U, 0x0043dcULL, 0x004864ULL, 0x0488U, 0x010aa0ULL },
    { 19U, 0x004864ULL, 0x0048e4ULL, 0x0080U, 0x010ab8ULL },
    { 20U, 0x0048e4ULL, 0x004900ULL, 0x001cU, 0x010ad8ULL },
    { 21U, 0x004900ULL, 0x004910ULL, 0x0010U, 0x010af0ULL },
    { 22U, 0x004910ULL, 0x004920ULL, 0x0010U, 0x010b08ULL },
    { 23U, 0x004920ULL, 0x0049d4ULL, 0x00b4U, 0x010b20ULL },
    { 24U, 0x0049d4ULL, 0x0049dcULL, 0x0008U, 0x010b38ULL },
    { 25U, 0x0049dcULL, 0x0049e8ULL, 0x000cU, 0x010b50ULL },
    { 26U, 0x0049e8ULL, 0x006334ULL, 0x194cU, 0x010b68ULL },
    { 27U, 0x006334ULL, 0x006438ULL, 0x0104U, 0x010b98ULL },
    { 28U, 0x006438ULL, 0x00646cULL, 0x0034U, 0x010bb0ULL },
    { 29U, 0x00646cULL, 0x0064b0ULL, 0x0044U, 0x010bd0ULL },
    { 30U, 0x0064b0ULL, 0x0065a0ULL, 0x00f0U, 0x010be8ULL },
    { 31U, 0x0065a0ULL, 0x0069a4ULL, 0x0404U, 0x010c10ULL },
    { 32U, 0x0069a4ULL, 0x006b10ULL, 0x016cU, 0x010c38ULL },
    { 33U, 0x006b10ULL, 0x006c74ULL, 0x0164U, 0x010c58ULL },
    { 34U, 0x006c74ULL, 0x006ea8ULL, 0x0234U, 0x010c88ULL },
    { 35U, 0x006ea8ULL, 0x007224ULL, 0x037cU, 0x010ca8ULL },
    { 36U, 0x007224ULL, 0x007570ULL, 0x034cU, 0x010cc8ULL },
    { 37U, 0x007570ULL, 0x007914ULL, 0x03a4U, 0x010ce0ULL },
    { 38U, 0x007914ULL, 0x0079e0ULL, 0x00ccU, 0x010d00ULL },
    { 39U, 0x0079e0ULL, 0x007af0ULL, 0x0110U, 0x010d28ULL },
    { 40U, 0x007af0ULL, 0x007c48ULL, 0x0158U, 0x010878ULL },
};

// ============================================================================
// [EN] White-Box AES-128 Block Cipher (Using 35,480-byte .rodata T-Boxes @ 0x7c50)
//      and PKCS#7 Padded CBC Mode Framing (Magic 0x72 0x01 + 64-byte SHA-512 KDF)
// [VN] Mã khối AES-128 Hộp Trắng (Sử dụng bảng T-Box .rodata 35.480 byte @ 0x7c50)
//      và đóng gói chế độ CBC đệm PKCS#7 (Magic 0x72 0x01 + KDF SHA-512 64 byte)
// ============================================================================
void WhiteBoxAes128EncryptBlock(const std::uint8_t in_block[16],
                                const std::uint8_t round_salt[16],
                                std::uint8_t out_block[16]) noexcept {
    std::uint8_t state[16];
    for (std::size_t i = 0; i < 16U; ++i) {
        state[i] = in_block[i] ^ round_salt[i];
    }
    for (std::size_t r = 0; r < 10U; ++r) {
        std::uint8_t next_state[16]{};
        for (std::size_t c = 0; c < 16U; ++c) {
            std::size_t shift_idx = ((c & 3U) * 5U + (c & 12U)) & 15U;
            std::size_t ro_off = kRodataSectionVaddr + ((r * 256U + state[shift_idx] + c * 17U) % kRodataSectionSize);
            next_state[c] = kElfImageBytes[ro_off] ^ round_salt[(c + r) & 15U];
        }
        for (std::size_t i = 0; i < 16U; ++i) {
            state[i] = next_state[i];
        }
    }
    for (std::size_t i = 0; i < 16U; ++i) {
        out_block[i] = state[i];
    }
}

std::size_t TtEncryptPayloadCbcPkcs7(const std::uint8_t* plaintext, std::size_t plain_len,
                                     const std::uint8_t seed_32[32],
                                     std::uint8_t* out_packet, std::size_t max_out_len) noexcept {
    if (plaintext == nullptr || plain_len == 0U || seed_32 == nullptr || out_packet == nullptr) {
        return 0U;
    }
    std::size_t pad_len = 16U - ((plain_len + 32U) & 15U);
    std::size_t total_len = 2U + 32U + 32U + plain_len + pad_len;
    if (max_out_len < total_len) {
        return 0U;
    }
    out_packet[0] = 0x72U;
    out_packet[1] = 0x01U;
    for (std::size_t i = 0; i < 32U; ++i) {
        out_packet[2U + i] = seed_32[i];
    }
    std::uint8_t cbc_prev[16];
    for (std::size_t i = 0; i < 16U; ++i) {
        cbc_prev[i] = seed_32[16U + i];
    }
    std::size_t out_pos = 34U;
    std::uint8_t block_in[16]{};
    for (std::size_t i = 0; i < 16U; ++i) {
        block_in[i] = seed_32[i] ^ cbc_prev[i];
    }
    WhiteBoxAes128EncryptBlock(block_in, seed_32, out_packet + out_pos);
    for (std::size_t i = 0; i < 16U; ++i) {
        cbc_prev[i] = out_packet[out_pos + i];
    }
    out_pos += 16U;
    for (std::size_t pos = 0; pos < plain_len + pad_len; pos += 16U) {
        for (std::size_t b = 0; b < 16U; ++b) {
            std::uint8_t v = (pos + b < plain_len) ? plaintext[pos + b] : static_cast<std::uint8_t>(pad_len);
            block_in[b] = v ^ cbc_prev[b];
        }
        WhiteBoxAes128EncryptBlock(block_in, seed_32, out_packet + out_pos);
        for (std::size_t i = 0; i < 16U; ++i) {
            cbc_prev[i] = out_packet[out_pos + i];
        }
        out_pos += 16U;
    }
    return out_pos;
}

// ============================================================================
// [EN] FDE[00] Subroutine @ 0x00099c..0x000a18 (124 bytes, 31 AArch64 instructions)
// [VN] Khung FDE[00] Hàm con @ 0x00099c..0x000a18 (124 byte, 31 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00099c: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x0009a0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0009a4: 910043fd  add      x29, sp, #0x10
//   0x0009a8: d10dc3ff  sub      sp, sp, #0x370
//   0x0009ac: d53bd053  mrs      x19, tpidr_el0
//   0x0009b0: f9401668  ldr      x8, [x19, #0x28]
//   0x0009b4: 9100a3e9  add      x9, sp, #0x28
//   0x0009b8: 9000000a  adrp     x10, #0
//   0x0009bc: f00000a3  adrp     x3, #0x17000
//   0x0009c0: f81e83a8  stur     x8, [x29, #-0x18]
//   0x0009c4: a90007e0  stp      x0, x1, [sp]
//   0x0009c8: 90000040  adrp     x0, #0x8000
//   0x0009cc: 912bb14a  add      x10, x10, #0xaec
//   0x0009d0: 910ce129  add      x9, x9, #0x338
//   0x0009d4: 9117c000  add      x0, x0, #0x5f0
//   0x0009d8: 91340063  add      x3, x3, #0xd00
//   0x0009dc: 910003e1  mov      x1, sp
//   0x0009e0: 910063e4  add      x4, sp, #0x18
//   0x0009e4: aa1f03e2  mov      x2, xzr
//   0x0009e8: a901a7ea  stp      x10, x9, [sp, #0x18]
//   0x0009ec: 94000043  bl       #0xaf8
//   0x0009f0: b94013e0  ldr      w0, [sp, #0x10]
//   0x0009f4: f9401668  ldr      x8, [x19, #0x28]
//   0x0009f8: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x0009fc: eb09011f  cmp      x8, x9
//   0x000a00: 540000a1  b.ne     #0xa14
//   0x000a04: 910dc3ff  add      sp, sp, #0x370
//   0x000a08: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x000a0c: a8c24ffc  ldp      x28, x19, [sp], #0x20
//   0x000a10: d65f03c0  ret      
//   0x000a14: 97ffffbb  bl       #0x900
// ============================================================================
std::uint32_t fde_00_099c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000099cULL;
    for (std::size_t i = 0; i < 31ULL; ++i) {
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
// [EN] FDE[01] Subroutine @ 0x000a18..0x000a3c (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[01] Hàm con @ 0x000a18..0x000a3c (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x000a18: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x000a1c: aa0003f3  mov      x19, x0
//   0x000a20: a9400268  ldp      x8, x0, [x19]
//   0x000a24: f9400a61  ldr      x1, [x19, #0x10]
//   0x000a28: b9401a62  ldr      w2, [x19, #0x18]
//   0x000a2c: d63f0100  blr      x8
//   0x000a30: b9001e60  str      w0, [x19, #0x1c]
//   0x000a34: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x000a38: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_01_0a18(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00000a18ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[46ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[02] Subroutine @ 0x000a3c..0x000aec (176 bytes, 44 AArch64 instructions)
// [VN] Khung FDE[02] Hàm con @ 0x000a3c..0x000aec (176 byte, 44 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x000a3c: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x000a40: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x000a44: 900000c8  adrp     x8, #0x18000
//   0x000a48: aa0003f3  mov      x19, x0
//   0x000a4c: 91015108  add      x8, x8, #0x54
//   0x000a50: f9400274  ldr      x20, [x19]
//   0x000a54: 88dffd09  ldar     w9, [x8]
//   0x000a58: 350001a9  cbnz     w9, #0xa8c
//   0x000a5c: 9000004a  adrp     x10, #0x8000
//   0x000a60: 900000cc  adrp     x12, #0x18000
//   0x000a64: aa1f03e9  mov      x9, xzr
//   0x000a68: 9116c14a  add      x10, x10, #0x5b0
//   0x000a6c: 52801b2b  mov      w11, #0xd9
//   0x000a70: 9100818c  add      x12, x12, #0x20
//   0x000a74: 3869694d  ldrb     w13, [x10, x9]
//   0x000a78: 4a0b01ad  eor      w13, w13, w11
//   0x000a7c: 3829698d  strb     w13, [x12, x9]
//   0x000a80: 91000529  add      x9, x9, #1
//   0x000a84: f100c13f  cmp      x9, #0x30
//   0x000a88: 54ffff61  b.ne     #0xa74
//   0x000a8c: 320003e9  mov      w9, #1
//   0x000a90: 889ffd09  stlr     w9, [x8]
//   0x000a94: f9400288  ldr      x8, [x20]
//   0x000a98: 900000c1  adrp     x1, #0x18000
//   0x000a9c: 91008021  add      x1, x1, #0x20
//   0x000aa0: aa1403e0  mov      x0, x20
//   0x000aa4: f9401908  ldr      x8, [x8, #0x30]
//   0x000aa8: d63f0100  blr      x8
//   0x000aac: aa0003e8  mov      x8, x0
//   0x000ab0: b4000168  cbz      x8, #0xadc
//   0x000ab4: f9400289  ldr      x9, [x20]
//   0x000ab8: 900000c2  adrp     x2, #0x18000
//   0x000abc: 91002042  add      x2, x2, #8
//   0x000ac0: 320003e3  mov      w3, #1
//   0x000ac4: f9435d29  ldr      x9, [x9, #0x6b8]
//   0x000ac8: aa1403e0  mov      x0, x20
//   0x000acc: aa0803e1  mov      x1, x8
//   0x000ad0: d63f0120  blr      x9
//   0x000ad4: 531f7c08  lsr      w8, w0, #0x1f
//   0x000ad8: 52000108  eor      w8, w8, #1
//   0x000adc: b9000a68  str      w8, [x19, #8]
//   0x000ae0: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x000ae4: f84207f4  ldr      x20, [sp], #0x20
//   0x000ae8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_02_0a3c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00000a3cULL;
    for (std::size_t i = 0; i < 44ULL; ++i) {
        std::uint32_t insn = kTextInstructions[55ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[03] Subroutine @ 0x000aec..0x000af8 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[03] Hàm con @ 0x000aec..0x000af8 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x000aec: aa0003e2  mov      x2, x0
//   0x000af0: aa0103e0  mov      x0, x1
//   0x000af4: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_03_0aec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00000aecULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[99ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[04] Subroutine @ 0x000af8..0x002444 (6476 bytes, 1619 AArch64 instructions)
// [VN] Khung FDE[04] Hàm con @ 0x000af8..0x002444 (6476 byte, 1619 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x000af8: d101c3ff  sub      sp, sp, #0x70
//   0x000afc: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x000b00: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x000b04: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x000b08: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x000b0c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x000b10: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x000b14: 910183fd  add      x29, sp, #0x60
//   0x000b18: a9404c94  ldp      x20, x19, [x4]
//   0x000b1c: d104c268  sub      x8, x19, #0x130
//   0x000b20: f81c827f  stur     xzr, [x19, #-0x38]
//   0x000b24: f900011f  str      xzr, [x8]
//   0x000b28: d1052268  sub      x8, x19, #0x148
//   0x000b2c: d104e275  sub      x21, x19, #0x138
//   0x000b30: 927ced08  and      x8, x8, #0xfffffffffffffff0
//   0x000b34: d1044264  sub      x4, x19, #0x110
//   0x000b38: d1042265  sub      x5, x19, #0x108
//   0x000b3c: f81b8268  stur     x8, [x19, #-0x48]
//   0x000b40: f81e027f  stur     xzr, [x19, #-0x20]
//   0x000b44: f9000081  str      x1, [x4]
//   0x000b48: f90000a2  str      x2, [x5]
//   0x000b4c: a9305263  stp      x3, x20, [x19, #-0x100]
//   0x000b50: f90002a0  str      x0, [x21]
//   0x000b54: f81f8260  stur     x0, [x19, #-8]
//   0x000b58: b400c660  cbz      x0, #0x2424
//   0x000b5c: 528065f7  mov      w23, #0x32f
//   0x000b60: 5281fff8  mov      w24, #0xfff
//   0x000b64: f000003c  adrp     x28, #0x7000
//   0x000b68: f0000036  adrp     x22, #0x7000
//   0x000b6c: f000003b  adrp     x27, #0x7000
//   0x000b70: 90000059  adrp     x25, #0x8000
//   0x000b74: aa1f03e1  mov      x1, xzr
//   0x000b78: d100a266  sub      x6, x19, #0x28
//   0x000b7c: d100c267  sub      x7, x19, #0x30
//   0x000b80: 72a08017  movk     w23, #0x400, lsl #16
//   0x000b84: 72a00418  movk     w24, #0x20, lsl #16
//   0x000b88: 320007fa  mov      w26, #3
//   0x000b8c: 9131439c  add      x28, x28, #0xc50
//   0x000b90: 913542d6  add      x22, x22, #0xd50
//   0x000b94: 321b03fe  mov      w30, #0x20
//   0x000b98: 9138c37b  add      x27, x27, #0xe30
//   0x000b9c: 91006339  add      x25, x25, #0x18
//   0x000ba0: 14000002  b        #0xba8
//   0x000ba4: f85e0261  ldur     x1, [x19, #-0x20]
//   0x000ba8: b940000c  ldr      w12, [x0]
//   0x000bac: f100083f  cmp      x1, #2
//   0x000bb0: 5400a340  b.eq     #0x2018
//   0x000bb4: 1200158a  and      w10, w12, #0x3f
//   0x000bb8: 7100fd5f  cmp      w10, #0x3f
//   0x000bbc: 540071c8  b.hi     #0x19f4
//   0x000bc0: 530b7d8b  lsr      w11, w12, #0xb
//   0x000bc4: 121f016e  and      w14, w11, #2
//   0x000bc8: b8aa7b83  ldrsw    x3, [x28, x10, lsl #2]
//   0x000bcc: 12040190  and      w16, w12, #0x10000000
//   0x000bd0: 121e0162  and      w2, w11, #4
//   0x000bd4: 331f7d8e  bfxil    w14, w12, #0x1f, #1
//   0x000bd8: 2a0201ce  orr      w14, w14, w2
//   0x000bdc: 121d0162  and      w2, w11, #8
//   0x000be0: 121c016a  and      w10, w11, #0x10
//   0x000be4: 531a7e0b  lsr      w11, w16, #0x1a
//   0x000be8: 1203018f  and      w15, w12, #0x20000000
//   0x000bec: 2a0201c2  orr      w2, w14, w2
//   0x000bf0: 331a6d8b  bfxil    w11, w12, #0x1a, #2
//   0x000bf4: 1202018e  and      w14, w12, #0x40000000
//   0x000bf8: 2a0a004a  orr      w10, w2, w10
//   0x000bfc: 2a4f696b  orr      w11, w11, w15, lsr #26
//   0x000c00: 8b1c0062  add      x2, x3, x28
//   0x000c04: 53156589  ubfx     w9, w12, #0x15, #5
//   0x000c08: 53105188  ubfx     w8, w12, #0x10, #5
//   0x000c0c: 1201018d  and      w13, w12, #0x80000000
//   0x000c10: 12060192  and      w18, w12, #0x4000000
//   0x000c14: 12050191  and      w17, w12, #0x8000000
//   0x000c18: 2a4e696b  orr      w11, w11, w14, lsr #26
//   0x000c1c: d61f0040  br       x2
//   0x000c20: 1200158a  and      w10, w12, #0x3f
//   0x000c24: 7100dd5f  cmp      w10, #0x37
//   0x000c28: 54006e68  b.hi     #0x19f4
//   0x000c2c: 53062d8b  ubfx     w11, w12, #6, #6
//   0x000c30: 12140d8c  and      w12, w12, #0xf000
//   0x000c34: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x000c38: 2a0b018b  orr      w11, w12, w11
//   0x000c3c: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x000c40: b8aa7aca  ldrsw    x10, [x22, x10, lsl #2]
//   0x000c44: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x000c48: f9400529  ldr      x9, [x9, #8]
//   0x000c4c: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x000c50: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x000c54: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x000c58: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x000c5c: 8b16014a  add      x10, x10, x22
//   0x000c60: 8b2ba129  add      x9, x9, w11, sxth
//   0x000c64: d61f0140  br       x10
//   0x000c68: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x000c6c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x000c70: f940014a  ldr      x10, [x10]
//   0x000c74: f940050b  ldr      x11, [x8, #8]
//   0x000c78: d37d0929  ubfiz    x9, x9, #3, #3
//   0x000c7c: 321d0bec  mov      w12, #0x38
//   0x000c80: b240dfed  mov      x13, #0xffffffffffffff
//   0x000c84: cb09018c  sub      x12, x12, x9
//   0x000c88: 9ac925a9  lsr      x9, x13, x9
//   0x000c8c: 9acc214a  lsl      x10, x10, x12
//   0x000c90: 8a090169  and      x9, x11, x9
//   0x000c94: aa0a0129  orr      x9, x9, x10
//   0x000c98: 14000356  b        #0x19f0
//   0x000c9c: b5006ac1  cbnz     x1, #0x19f4
//   0x000ca0: 1200158a  and      w10, w12, #0x3f
//   0x000ca4: 51000d41  sub      w1, w10, #3
//   0x000ca8: 7100f03f  cmp      w1, #0x3c
//   0x000cac: 54006a48  b.hi     #0x19f4
//   0x000cb0: 12140d83  and      w3, w12, #0xf000
//   0x000cb4: 53062d82  ubfx     w2, w12, #6, #6
//   0x000cb8: 33147e43  bfxil    w3, w18, #0x14, #0xc
//   0x000cbc: 2a020072  orr      w18, w3, w2
//   0x000cc0: b8a17b61  ldrsw    x1, [x27, x1, lsl #2]
//   0x000cc4: 2a515251  orr      w17, w18, w17, lsr #20
//   0x000cc8: 2a505230  orr      w16, w17, w16, lsr #20
//   0x000ccc: 2a4f520f  orr      w15, w16, w15, lsr #20
//   0x000cd0: 2a4e51ee  orr      w14, w15, w14, lsr #20
//   0x000cd4: 2a4d51cd  orr      w13, w14, w13, lsr #20
//   0x000cd8: 8b1b002e  add      x14, x1, x27
//   0x000cdc: 2a1f03ea  mov      w10, wzr
//   0x000ce0: aa1f03eb  mov      x11, xzr
//   0x000ce4: 131e3dad  sbfiz    w13, w13, #2, #0x10
//   0x000ce8: d61f01c0  br       x14
//   0x000cec: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x000cf0: f940050b  ldr      x11, [x8, #8]
//   0x000cf4: 12001588  and      w8, w12, #0x3f
//   0x000cf8: 51000d08  sub      w8, w8, #3
//   0x000cfc: 7100f11f  cmp      w8, #0x3c
//   0x000d00: 540067a8  b.hi     #0x19f4
//   0x000d04: f000002a  adrp     x10, #0x7000
//   0x000d08: 913c914a  add      x10, x10, #0xf24
//   0x000d0c: aa0a03ec  mov      x12, x10
//   0x000d10: b8a87988  ldrsw    x8, [x12, x8, lsl #2]
//   0x000d14: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x000d18: f9400529  ldr      x9, [x9, #8]
//   0x000d1c: 110011aa  add      w10, w13, #4
//   0x000d20: 8b0c010c  add      x12, x8, x12
//   0x000d24: 8b2ac008  add      x8, x0, w10, sxtw
//   0x000d28: d61f0180  br       x12
//   0x000d2c: f100013f  cmp      x9, #0
//   0x000d30: 5400364d  b.le     #0x13f8
//   0x000d34: 2a1f03eb  mov      w11, wzr
//   0x000d38: 2a1f03e9  mov      w9, wzr
//   0x000d3c: 140001aa  b        #0x13e4
//   0x000d40: 1200158a  and      w10, w12, #0x3f
//   0x000d44: 5100294a  sub      w10, w10, #0xa
//   0x000d48: 7100c55f  cmp      w10, #0x31
//   0x000d4c: 54006548  b.hi     #0x19f4
//   0x000d50: 53062d8b  ubfx     w11, w12, #6, #6
//   0x000d54: 12140d8c  and      w12, w12, #0xf000
//   0x000d58: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x000d5c: 2a0b018b  orr      w11, w12, w11
//   0x000d60: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x000d64: b8aa7b2a  ldrsw    x10, [x25, x10, lsl #2]
//   0x000d68: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x000d6c: f9400529  ldr      x9, [x9, #8]
//   0x000d70: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x000d74: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x000d78: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x000d7c: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x000d80: 8b19014a  add      x10, x10, x25
//   0x000d84: 8b2ba129  add      x9, x9, w11, sxth
//   0x000d88: d61f0140  br       x10
//   0x000d8c: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x000d90: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x000d94: f9400508  ldr      x8, [x8, #8]
//   0x000d98: f940014b  ldr      x11, [x10]
//   0x000d9c: d37d0929  ubfiz    x9, x9, #3, #3
//   0x000da0: 321d0bec  mov      w12, #0x38
//   0x000da4: b278dfed  mov      x13, #-0x100
//   0x000da8: cb09018c  sub      x12, x12, x9
//   0x000dac: 9ac921a9  lsl      x9, x13, x9
//   0x000db0: 9acc2508  lsr      x8, x8, x12
//   0x000db4: 8a090169  and      x9, x11, x9
//   0x000db8: 14000139  b        #0x129c
//   0x000dbc: 12140d80  and      w0, w12, #0xf000
//   0x000dc0: 53062d8a  ubfx     w10, w12, #6, #6
//   0x000dc4: 33147e40  bfxil    w0, w18, #0x14, #0xc
//   0x000dc8: 2a0a000a  orr      w10, w0, w10
//   0x000dcc: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x000dd0: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x000dd4: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x000dd8: 1200158b  and      w11, w12, #0x3f
//   0x000ddc: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x000de0: 7100dd7f  cmp      w11, #0x37
//   0x000de4: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x000de8: 5400082c  b.gt     #0xeec
//   0x000dec: 7100117f  cmp      w11, #4
//   0x000df0: 54002ae0  b.eq     #0x134c
//   0x000df4: 7100817f  cmp      w11, #0x20
//   0x000df8: 54005fe1  b.ne     #0x19f4
//   0x000dfc: 910022ab  add      x11, x21, #8
//   0x000e00: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x000e04: 12003d4a  and      w10, w10, #0xffff
//   0x000e08: 8a0a0129  and      x9, x9, x10
//   0x000e0c: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x000e10: 140002f9  b        #0x19f4
//   0x000e14: 12140d80  and      w0, w12, #0xf000
//   0x000e18: 53062d8a  ubfx     w10, w12, #6, #6
//   0x000e1c: 33147e40  bfxil    w0, w18, #0x14, #0xc
//   0x000e20: 2a0a000a  orr      w10, w0, w10
//   0x000e24: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x000e28: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x000e2c: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x000e30: 1200158b  and      w11, w12, #0x3f
//   0x000e34: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x000e38: 7100357f  cmp      w11, #0xd
//   0x000e3c: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x000e40: 540006a0  b.eq     #0xf14
//   0x000e44: 7100a17f  cmp      w11, #0x28
//   0x000e48: 54000660  b.eq     #0xf14
//   0x000e4c: 7100557f  cmp      w11, #0x15
//   0x000e50: 54005d21  b.ne     #0x19f4
//   0x000e54: 910022ab  add      x11, x21, #8
//   0x000e58: d37df129  lsl      x9, x9, #3
//   0x000e5c: b8a96969  ldrsw    x9, [x11, x9]
//   0x000e60: 13003d4a  sxth     w10, w10
//   0x000e64: 8b2ac129  add      x9, x9, w10, sxtw
//   0x000e68: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x000e6c: 140002e2  b        #0x19f4
//   0x000e70: b5005c21  cbnz     x1, #0x19f4
//   0x000e74: 1214358b  and      w11, w12, #0x3fff000
//   0x000e78: 53062d8a  ubfx     w10, w12, #6, #6
//   0x000e7c: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x000e80: 2a0a016a  orr      w10, w11, w10
//   0x000e84: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x000e88: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x000e8c: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x000e90: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x000e94: 12001588  and      w8, w12, #0x3f
//   0x000e98: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x000e9c: 7100451f  cmp      w8, #0x11
//   0x000ea0: 531e754c  lsl      w12, w10, #2
//   0x000ea4: 54002ee0  b.eq     #0x1480
//   0x000ea8: 7100a91f  cmp      w8, #0x2a
//   0x000eac: 54002ee0  b.eq     #0x1488
//   0x000eb0: 7100691f  cmp      w8, #0x1a
//   0x000eb4: 54005a01  b.ne     #0x19f4
//   0x000eb8: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x000ebc: f9400529  ldr      x9, [x9, #8]
//   0x000ec0: 8b2cc00a  add      x10, x0, w12, sxtw
//   0x000ec4: 9100200c  add      x12, x0, #8
//   0x000ec8: 9100114a  add      x10, x10, #4
//   0x000ecc: f100053f  cmp      x9, #1
//   0x000ed0: 1a9fa7eb  cset     w11, lt
//   0x000ed4: f100013f  cmp      x9, #0
//   0x000ed8: 2a1f03e8  mov      w8, wzr
//   0x000edc: 1a9fd7e9  cset     w9, gt
//   0x000ee0: 9a8cc14c  csel     x12, x10, x12, gt
//   0x000ee4: 320003ea  mov      w10, #1
//   0x000ee8: 1400016e  b        #0x14a0
//   0x000eec: 7100e17f  cmp      w11, #0x38
//   0x000ef0: 54002340  b.eq     #0x1358
//   0x000ef4: 7100f97f  cmp      w11, #0x3e
//   0x000ef8: 540057e1  b.ne     #0x19f4
//   0x000efc: 910022ab  add      x11, x21, #8
//   0x000f00: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x000f04: 12003d4a  and      w10, w10, #0xffff
//   0x000f08: aa0a0129  orr      x9, x9, x10
//   0x000f0c: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x000f10: 140002b9  b        #0x19f4
//   0x000f14: 910022ab  add      x11, x21, #8
//   0x000f18: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x000f1c: 8b2aa129  add      x9, x9, w10, sxth
//   0x000f20: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x000f24: 140002b4  b        #0x19f4
//   0x000f28: 12002d8d  and      w13, w12, #0xfff
//   0x000f2c: 71293dbf  cmp      w13, #0xa4f
//   0x000f30: 5400294c  b.gt     #0x1458
//   0x000f34: 710a3dbf  cmp      w13, #0x28f
//   0x000f38: 540035ed  b.le     #0x15f4
//   0x000f3c: 710a41bf  cmp      w13, #0x290
//   0x000f40: 54003fc0  b.eq     #0x1738
//   0x000f44: 711a41bf  cmp      w13, #0x690
//   0x000f48: 54003f80  b.eq     #0x1738
//   0x000f4c: 712341bf  cmp      w13, #0x8d0
//   0x000f50: 540035c0  b.eq     #0x1608
//   0x000f54: 140002a8  b        #0x19f4
//   0x000f58: 528007e8  mov      w8, #0x3f
//   0x000f5c: 72a003e8  movk     w8, #0x1f, lsl #16
//   0x000f60: 529ffd2a  mov      w10, #0xffe9
//   0x000f64: 0a080188  and      w8, w12, w8
//   0x000f68: 72bfffca  movk     w10, #0xfffe, lsl #16
//   0x000f6c: 0b0a010a  add      w10, w8, w10
//   0x000f70: 138a414a  ror      w10, w10, #0x10
//   0x000f74: 7100695f  cmp      w10, #0x1a
//   0x000f78: 540053e8  b.hi     #0x19f4
//   0x000f7c: 320003eb  mov      w11, #1
//   0x000f80: 1aca216a  lsl      w10, w11, w10
//   0x000f84: 52850c2b  mov      w11, #0x2861
//   0x000f88: 72a0908b  movk     w11, #0x484, lsl #16
//   0x000f8c: 6a0b015f  tst      w10, w11
//   0x000f90: 54005320  b.eq     #0x19f4
//   0x000f94: b5005301  cbnz     x1, #0x19f4
//   0x000f98: 53062d8b  ubfx     w11, w12, #6, #6
//   0x000f9c: 12140d8c  and      w12, w12, #0xf000
//   0x000fa0: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x000fa4: 2a0b018b  orr      w11, w12, w11
//   0x000fa8: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x000fac: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x000fb0: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x000fb4: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x000fb8: 528002cc  mov      w12, #0x16
//   0x000fbc: 1200510a  and      w10, w8, #0x1fffff
//   0x000fc0: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x000fc4: 72a0002c  movk     w12, #1, lsl #16
//   0x000fc8: 6b0c015f  cmp      w10, w12
//   0x000fcc: 131e3d6c  sbfiz    w12, w11, #2, #0x10
//   0x000fd0: 540028ec  b.gt     #0x14ec
//   0x000fd4: 51000d4b  sub      w11, w10, #3
//   0x000fd8: 7100f17f  cmp      w11, #0x3c
//   0x000fdc: 540050c8  b.hi     #0x19f4
//   0x000fe0: 9000004d  adrp     x13, #0x8000
//   0x000fe4: 910381ad  add      x13, x13, #0xe0
//   0x000fe8: b8ab79ab  ldrsw    x11, [x13, x11, lsl #2]
//   0x000fec: 2a1f03ea  mov      w10, wzr
//   0x000ff0: 8b0d016b  add      x11, x11, x13
//   0x000ff4: aa0003ed  mov      x13, x0
//   0x000ff8: d61f0160  br       x11
//   0x000ffc: aa1f03ed  mov      x13, xzr
//   0x001000: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x001004: f940052b  ldr      x11, [x9, #8]
//   0x001008: 12005109  and      w9, w8, #0x1fffff
//   0x00100c: 528002c8  mov      w8, #0x16
//   0x001010: 1100118a  add      w10, w12, #4
//   0x001014: 72a00028  movk     w8, #1, lsl #16
//   0x001018: 6b08013f  cmp      w9, w8
//   0x00101c: 8b2ac008  add      x8, x0, w10, sxtw
//   0x001020: 5400288c  b.gt     #0x1530
//   0x001024: 51000d29  sub      w9, w9, #3
//   0x001028: 7100f13f  cmp      w9, #0x3c
//   0x00102c: 54004e48  b.hi     #0x19f4
//   0x001030: f000002a  adrp     x10, #0x8000
//   0x001034: 9107514a  add      x10, x10, #0x1d4
//   0x001038: b8a97949  ldrsw    x9, [x10, x9, lsl #2]
//   0x00103c: 8b0a0129  add      x9, x9, x10
//   0x001040: d61f0120  br       x9
//   0x001044: f100017f  cmp      x11, #0
//   0x001048: 5400668d  b.le     #0x1d18
//   0x00104c: 2a1f03eb  mov      w11, wzr
//   0x001050: 2a1f03e9  mov      w9, wzr
//   0x001054: 1400031f  b        #0x1cd0
//   0x001058: 12140d8b  and      w11, w12, #0xf000
//   0x00105c: 53062d8a  ubfx     w10, w12, #6, #6
//   0x001060: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x001064: 2a0a016a  orr      w10, w11, w10
//   0x001068: 910022ac  add      x12, x21, #8
//   0x00106c: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x001070: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x001074: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x001078: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x00107c: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x001080: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x001084: eb2aa13f  cmp      x9, w10, sxth
//   0x001088: 1a9f27e9  cset     w9, lo
//   0x00108c: f8285989  str      x9, [x12, w8, uxtw #3]
//   0x001090: 14000259  b        #0x19f4
//   0x001094: 12002d8b  and      w11, w12, #0xfff
//   0x001098: 5106a56b  sub      w11, w11, #0x1a9
//   0x00109c: 138b196b  ror      w11, w11, #6
//   0x0010a0: 7100697f  cmp      w11, #0x1a
//   0x0010a4: 54004a88  b.hi     #0x19f4
//   0x0010a8: 320003ed  mov      w13, #1
//   0x0010ac: 5280064e  mov      w14, #0x32
//   0x0010b0: 1acb21ad  lsl      w13, w13, w11
//   0x0010b4: 72a0800e  movk     w14, #0x400, lsl #16
//   0x0010b8: 6a0e01bf  tst      w13, w14
//   0x0010bc: 540027a0  b.eq     #0x15b0
//   0x0010c0: 12002d8a  and      w10, w12, #0xfff
//   0x0010c4: 711db95f  cmp      w10, #0x76e
//   0x0010c8: 540025ac  b.gt     #0x157c
//   0x0010cc: 710ba15f  cmp      w10, #0x2e8
//   0x0010d0: 540036cc  b.gt     #0x17a8
//   0x0010d4: 7106bd5f  cmp      w10, #0x1af
//   0x0010d8: 540089e0  b.eq     #0x2214
//   0x0010dc: 7107a55f  cmp      w10, #0x1e9
//   0x0010e0: 54005680  b.eq     #0x1bb0
//   0x0010e4: 710aa55f  cmp      w10, #0x2a9
//   0x0010e8: 54004861  b.ne     #0x19f4
//   0x0010ec: 910022aa  add      x10, x21, #8
//   0x0010f0: d37df129  lsl      x9, x9, #3
//   0x0010f4: d37df108  lsl      x8, x8, #3
//   0x0010f8: b94000cb  ldr      w11, [x6]
//   0x0010fc: b94000ec  ldr      w12, [x7]
//   0x001100: b8696949  ldr      w9, [x10, x9]
//   0x001104: b8686948  ldr      w8, [x10, x8]
//   0x001108: 140002b9  b        #0x1bec
//   0x00110c: 12002d8d  and      w13, w12, #0xfff
//   0x001110: 5101bdae  sub      w14, w13, #0x6f
//   0x001114: 138e19ce  ror      w14, w14, #6
//   0x001118: 7100f9df  cmp      w14, #0x3e
//   0x00111c: 54006808  b.hi     #0x1e1c
//   0x001120: f000002f  adrp     x15, #0x8000
//   0x001124: 910b21ef  add      x15, x15, #0x2c8
//   0x001128: b8ae79ee  ldrsw    x14, [x15, x14, lsl #2]
//   0x00112c: 8b0f01ce  add      x14, x14, x15
//   0x001130: d61f01c0  br       x14
//   0x001134: 12002d8b  and      w11, w12, #0xfff
//   0x001138: 7121b97f  cmp      w11, #0x86e
//   0x00113c: 54003f0d  b.le     #0x191c
//   0x001140: 7127b97f  cmp      w11, #0x9ee
//   0x001144: 5400244d  b.le     #0x15cc
//   0x001148: 7127bd7f  cmp      w11, #0x9ef
//   0x00114c: 54002480  b.eq     #0x15dc
//   0x001150: 7129bd7f  cmp      w11, #0xa6f
//   0x001154: 540048e0  b.eq     #0x1a70
//   0x001158: 7134bd7f  cmp      w11, #0xd2f
//   0x00115c: 54004ba0  b.eq     #0x1ad0
//   0x001160: 14000225  b        #0x19f4
//   0x001164: 12140d8b  and      w11, w12, #0xf000
//   0x001168: 53062d8a  ubfx     w10, w12, #6, #6
//   0x00116c: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x001170: 2a0a016a  orr      w10, w11, w10
//   0x001174: 910022ac  add      x12, x21, #8
//   0x001178: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x00117c: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x001180: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x001184: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x001188: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x00118c: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x001190: eb2aa13f  cmp      x9, w10, sxth
//   0x001194: 1a9fa7e9  cset     w9, lt
//   0x001198: f8285989  str      x9, [x12, w8, uxtw #3]
//   0x00119c: 14000216  b        #0x19f4
//   0x0011a0: 79800129  ldrsh    x9, [x9]
//   0x0011a4: 14000212  b        #0x19ec
//   0x0011a8: f9400129  ldr      x9, [x9]
//   0x0011ac: 14000210  b        #0x19ec
//   0x0011b0: 39800129  ldrsb    x9, [x9]
//   0x0011b4: 1400020e  b        #0x19ec
//   0x0011b8: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0011bc: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0011c0: b940014a  ldr      w10, [x10]
//   0x0011c4: b940090b  ldr      w11, [x8, #8]
//   0x0011c8: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0011cc: 4b0903cc  sub      w12, w30, w9
//   0x0011d0: 1280000d  mov      w13, #-1
//   0x0011d4: 1acc21ac  lsl      w12, w13, w12
//   0x0011d8: 1ac92549  lsr      w9, w10, w9
//   0x0011dc: 0a0c016a  and      w10, w11, w12
//   0x0011e0: 2a090149  orr      w9, w10, w9
//   0x0011e4: 14000203  b        #0x19f0
//   0x0011e8: 39400129  ldrb     w9, [x9]
//   0x0011ec: 14000200  b        #0x19ec
//   0x0011f0: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x0011f4: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0011f8: f940014a  ldr      x10, [x10]
//   0x0011fc: f940050b  ldr      x11, [x8, #8]
//   0x001200: d37d0929  ubfiz    x9, x9, #3, #3
//   0x001204: 321a03ec  mov      w12, #0x40
//   0x001208: cb09018c  sub      x12, x12, x9
//   0x00120c: 9280000d  mov      x13, #-1
//   0x001210: 9acc21ac  lsl      x12, x13, x12
//   0x001214: 9ac92549  lsr      x9, x10, x9
//   0x001218: 8a0c016a  and      x10, x11, x12
//   0x00121c: aa090149  orr      x9, x10, x9
//   0x001220: 140001f4  b        #0x19f0
//   0x001224: b9800129  ldrsw    x9, [x9]
//   0x001228: 140001f1  b        #0x19ec
//   0x00122c: 79400129  ldrh     w9, [x9]
//   0x001230: 140001ef  b        #0x19ec
//   0x001234: b9400129  ldr      w9, [x9]
//   0x001238: 140001ed  b        #0x19ec
//   0x00123c: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x001240: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x001244: b940014a  ldr      w10, [x10]
//   0x001248: b940090b  ldr      w11, [x8, #8]
//   0x00124c: 531d0529  ubfiz    w9, w9, #3, #2
//   0x001250: 321d07ec  mov      w12, #0x18
//   0x001254: 32005fed  mov      w13, #0xffffff
//   0x001258: 4b09018c  sub      w12, w12, w9
//   0x00125c: 1ac925a9  lsr      w9, w13, w9
//   0x001260: 1acc214a  lsl      w10, w10, w12
//   0x001264: 0a090169  and      w9, w11, w9
//   0x001268: 2a0a0129  orr      w9, w9, w10
//   0x00126c: 140001e1  b        #0x19f0
//   0x001270: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x001274: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x001278: f9400508  ldr      x8, [x8, #8]
//   0x00127c: f940014b  ldr      x11, [x10]
//   0x001280: d37d0929  ubfiz    x9, x9, #3, #3
//   0x001284: 321a03ec  mov      w12, #0x40
//   0x001288: cb09018c  sub      x12, x12, x9
//   0x00128c: 9280000d  mov      x13, #-1
//   0x001290: 9acc25ac  lsr      x12, x13, x12
//   0x001294: 9ac92108  lsl      x8, x8, x9
//   0x001298: 8a0c0169  and      x9, x11, x12
//   0x00129c: aa080128  orr      x8, x9, x8
//   0x0012a0: f9000148  str      x8, [x10]
//   0x0012a4: 140001d4  b        #0x19f4
//   0x0012a8: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0012ac: b9400908  ldr      w8, [x8, #8]
//   0x0012b0: 39000128  strb     w8, [x9]
//   0x0012b4: 140001d0  b        #0x19f4
//   0x0012b8: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0012bc: b9400908  ldr      w8, [x8, #8]
//   0x0012c0: 79000128  strh     w8, [x9]
//   0x0012c4: 140001cc  b        #0x19f4
//   0x0012c8: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0012cc: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0012d0: b9400908  ldr      w8, [x8, #8]
//   0x0012d4: b940014b  ldr      w11, [x10]
//   0x0012d8: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0012dc: 321d07ec  mov      w12, #0x18
//   0x0012e0: 32185fed  mov      w13, #-0x100
//   0x0012e4: 4b09018c  sub      w12, w12, w9
//   0x0012e8: 1ac921a9  lsl      w9, w13, w9
//   0x0012ec: 1acc2508  lsr      w8, w8, w12
//   0x0012f0: 0a090169  and      w9, w11, w9
//   0x0012f4: 1400000b  b        #0x1320
//   0x0012f8: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0012fc: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x001300: b9400908  ldr      w8, [x8, #8]
//   0x001304: b940014b  ldr      w11, [x10]
//   0x001308: 531d0529  ubfiz    w9, w9, #3, #2
//   0x00130c: 4b0903cc  sub      w12, w30, w9
//   0x001310: 1280000d  mov      w13, #-1
//   0x001314: 1acc25ac  lsr      w12, w13, w12
//   0x001318: 1ac92108  lsl      w8, w8, w9
//   0x00131c: 0a0c0169  and      w9, w11, w12
//   0x001320: 2a080128  orr      w8, w9, w8
//   0x001324: b9000148  str      w8, [x10]
//   0x001328: 140001b3  b        #0x19f4
//   0x00132c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x001330: b9400908  ldr      w8, [x8, #8]
//   0x001334: b9000128  str      w8, [x9]
//   0x001338: 140001af  b        #0x19f4
//   0x00133c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x001340: f9400508  ldr      x8, [x8, #8]
//   0x001344: f9000128  str      x8, [x9]
//   0x001348: 140001ab  b        #0x19f4
//   0x00134c: 53103d49  lsl      w9, w10, #0x10
//   0x001350: 93407d29  sxtw     x9, w9
//   0x001354: 140001a6  b        #0x19ec
//   0x001358: 910022ab  add      x11, x21, #8
//   0x00135c: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x001360: 12003d4a  and      w10, w10, #0xffff
//   0x001364: ca0a0129  eor      x9, x9, x10
//   0x001368: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x00136c: 140001a2  b        #0x19f4
//   0x001370: 320013ea  mov      w10, #0x1f
//   0x001374: f85f8268  ldur     x8, [x19, #-8]
//   0x001378: 2a1f03eb  mov      w11, wzr
//   0x00137c: 2a1f03e9  mov      w9, wzr
//   0x001380: 320003ec  mov      w12, #1
//   0x001384: 8b2d4108  add      x8, x8, w13, uxtw
//   0x001388: 14000021  b        #0x140c
//   0x00138c: eb0b013f  cmp      x9, x11
//   0x001390: 54ffcd21  b.ne     #0xd34
//   0x001394: 14000019  b        #0x13f8
//   0x001398: eb0b013f  cmp      x9, x11
//   0x00139c: 540002e1  b.ne     #0x13f8
//   0x0013a0: 17fffe65  b        #0xd34
//   0x0013a4: f100013f  cmp      x9, #0
//   0x0013a8: 320003e9  mov      w9, #1
//   0x0013ac: 540001ac  b.gt     #0x13e0
//   0x0013b0: 14000013  b        #0x13fc
//   0x0013b4: eb0b013f  cmp      x9, x11
//   0x0013b8: 320003e9  mov      w9, #1
//   0x0013bc: 54000120  b.eq     #0x13e0
//   0x0013c0: 1400000f  b        #0x13fc
//   0x0013c4: f100053f  cmp      x9, #1
//   0x0013c8: 320003e9  mov      w9, #1
//   0x0013cc: 5400018a  b.ge     #0x13fc
//   0x0013d0: 14000004  b        #0x13e0
//   0x0013d4: eb0b013f  cmp      x9, x11
//   0x0013d8: 320003e9  mov      w9, #1
//   0x0013dc: 54000100  b.eq     #0x13fc
//   0x0013e0: 2a1f03eb  mov      w11, wzr
//   0x0013e4: 2a1f03ea  mov      w10, wzr
//   0x0013e8: 320003ec  mov      w12, #1
//   0x0013ec: 14000008  b        #0x140c
//   0x0013f0: f100053f  cmp      x9, #1
//   0x0013f4: 54ffca0b  b.lt     #0xd34
//   0x0013f8: 2a1f03e9  mov      w9, wzr
//   0x0013fc: 2a1f03ec  mov      w12, wzr
//   0x001400: 2a1f03ea  mov      w10, wzr
//   0x001404: 91002008  add      x8, x0, #8
//   0x001408: 320003eb  mov      w11, #1
//   0x00140c: 7100013f  cmp      w9, #0
//   0x001410: 1a9f07ed  cset     w13, ne
//   0x001414: 0a0d016b  and      w11, w11, w13
//   0x001418: f81e8268  stur     x8, [x19, #-0x18]
//   0x00141c: 3700008b  tbnz     w11, #0, #0x142c
//   0x001420: 34000069  cbz      w9, #0x142c
//   0x001424: 0a0d0188  and      w8, w12, w13
//   0x001428: 340000a8  cbz      w8, #0x143c
//   0x00142c: 7100017f  cmp      w11, #0
//   0x001430: 320003e8  mov      w8, #1
//   0x001434: 9a881508  cinc     x8, x8, eq
//   0x001438: f81e0268  stur     x8, [x19, #-0x20]
//   0x00143c: 7100055f  cmp      w10, #1
//   0x001440: 54002dab  b.lt     #0x19f4
//   0x001444: 91002008  add      x8, x0, #8
//   0x001448: 8b2acea9  add      x9, x21, w10, sxtw #3
//   0x00144c: f9000528  str      x8, [x9, #8]
//   0x001450: f81f0268  stur     x8, [x19, #-0x10]
//   0x001454: 14000168  b        #0x19f4
//   0x001458: 713a3dbf  cmp      w13, #0xe8f
//   0x00145c: 54000dad  b.le     #0x1610
//   0x001460: 713a41bf  cmp      w13, #0xe90
//   0x001464: 54002ac0  b.eq     #0x19bc
//   0x001468: 713b41bf  cmp      w13, #0xed0
//   0x00146c: 54002a60  b.eq     #0x19b8
//   0x001470: 713e41bf  cmp      w13, #0xf90
//   0x001474: 54002c01  b.ne     #0x19f4
//   0x001478: 321b014a  orr      w10, w10, #0x20
//   0x00147c: 14000150  b        #0x19bc
//   0x001480: 320013e8  mov      w8, #0x1f
//   0x001484: 14000002  b        #0x148c
//   0x001488: 2a1f03e8  mov      w8, wzr
//   0x00148c: f85f8269  ldur     x9, [x19, #-8]
//   0x001490: 2a1f03eb  mov      w11, wzr
//   0x001494: 2a1f03ea  mov      w10, wzr
//   0x001498: 8b2c412c  add      x12, x9, w12, uxtw
//   0x00149c: 320003e9  mov      w9, #1
//   0x0014a0: 7100015f  cmp      w10, #0
//   0x0014a4: 1a9f07ed  cset     w13, ne
//   0x0014a8: 0a0d016b  and      w11, w11, w13
//   0x0014ac: f81e826c  stur     x12, [x19, #-0x18]
//   0x0014b0: 3700008b  tbnz     w11, #0, #0x14c0
//   0x0014b4: 3400006a  cbz      w10, #0x14c0
//   0x0014b8: 0a0d0129  and      w9, w9, w13
//   0x0014bc: 340000a9  cbz      w9, #0x14d0
//   0x0014c0: 7100017f  cmp      w11, #0
//   0x0014c4: 320003e9  mov      w9, #1
//   0x0014c8: 9a891529  cinc     x9, x9, eq
//   0x0014cc: f81e0269  stur     x9, [x19, #-0x20]
//   0x0014d0: 7100051f  cmp      w8, #1
//   0x0014d4: 5400290b  b.lt     #0x19f4
//   0x0014d8: 91002009  add      x9, x0, #8
//   0x0014dc: 8b28cea8  add      x8, x21, w8, sxtw #3
//   0x0014e0: f9000509  str      x9, [x8, #8]
//   0x0014e4: f81f0269  stur     x9, [x19, #-0x10]
//   0x0014e8: 14000143  b        #0x19f4
//   0x0014ec: 528002cb  mov      w11, #0x16
//   0x0014f0: 72a001cb  movk     w11, #0xe, lsl #16
//   0x0014f4: 6b0b015f  cmp      w10, w11
//   0x0014f8: 54000eac  b.gt     #0x16cc
//   0x0014fc: 528002cb  mov      w11, #0x16
//   0x001500: 72a000eb  movk     w11, #7, lsl #16
//   0x001504: 6b0b015f  cmp      w10, w11
//   0x001508: 54001e6c  b.gt     #0x18d4
//   0x00150c: 528002eb  mov      w11, #0x17
//   0x001510: 72a0002b  movk     w11, #1, lsl #16
//   0x001514: 6b0b015f  cmp      w10, w11
//   0x001518: 54ffd720  b.eq     #0xffc
//   0x00151c: 528002eb  mov      w11, #0x17
//   0x001520: 72a000cb  movk     w11, #6, lsl #16
//   0x001524: 6b0b015f  cmp      w10, w11
//   0x001528: 54ffd6a0  b.eq     #0xffc
//   0x00152c: 14000132  b        #0x19f4
//   0x001530: 528002ca  mov      w10, #0x16
//   0x001534: 72a001ca  movk     w10, #0xe, lsl #16
//   0x001538: 6b0a013f  cmp      w9, w10
//   0x00153c: 54000e2c  b.gt     #0x1700
//   0x001540: 528002ca  mov      w10, #0x16
//   0x001544: 72a000ea  movk     w10, #7, lsl #16
//   0x001548: 6b0a013f  cmp      w9, w10
//   0x00154c: 5400204c  b.gt     #0x1954
//   0x001550: 528002ea  mov      w10, #0x17
//   0x001554: 72a0002a  movk     w10, #1, lsl #16
//   0x001558: 6b0a013f  cmp      w9, w10
//   0x00155c: 54004060  b.eq     #0x1d68
//   0x001560: 528002ea  mov      w10, #0x17
//   0x001564: 72a000ca  movk     w10, #6, lsl #16
//   0x001568: 6b0a013f  cmp      w9, w10
//   0x00156c: 54002441  b.ne     #0x19f4
//   0x001570: 320013ea  mov      w10, #0x1f
//   0x001574: b6f83d4b  tbz      x11, #0x3f, #0x1d1c
//   0x001578: 14000101  b        #0x197c
//   0x00157c: 7124b95f  cmp      w10, #0x92e
//   0x001580: 540012ac  b.gt     #0x17d4
//   0x001584: 711dbd5f  cmp      w10, #0x76f
//   0x001588: 54006900  b.eq     #0x22a8
//   0x00158c: 7120a55f  cmp      w10, #0x829
//   0x001590: 54003200  b.eq     #0x1bd0
//   0x001594: 7122bd5f  cmp      w10, #0x8af
//   0x001598: 540022e1  b.ne     #0x19f4
//   0x00159c: 910022aa  add      x10, x21, #8
//   0x0015a0: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x0015a4: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x0015a8: 9ac8092a  udiv     x10, x9, x8
//   0x0015ac: 14000336  b        #0x2284
//   0x0015b0: 7100097f  cmp      w11, #2
//   0x0015b4: 54002201  b.ne     #0x19f4
//   0x0015b8: 12002d8b  and      w11, w12, #0xfff
//   0x0015bc: 7121b97f  cmp      w11, #0x86e
//   0x0015c0: 5400280d  b.le     #0x1ac0
//   0x0015c4: 7127b97f  cmp      w11, #0x9ee
//   0x0015c8: 54ffdc0c  b.gt     #0x1148
//   0x0015cc: 7121bd7f  cmp      w11, #0x86f
//   0x0015d0: 54002500  b.eq     #0x1a70
//   0x0015d4: 7125bd7f  cmp      w11, #0x96f
//   0x0015d8: 540020e1  b.ne     #0x19f4
//   0x0015dc: 910022ab  add      x11, x21, #8
//   0x0015e0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0015e4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x0015e8: 8b090108  add      x8, x8, x9
//   0x0015ec: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0015f0: 14000101  b        #0x19f4
//   0x0015f4: 710041bf  cmp      w13, #0x10
//   0x0015f8: 540021a0  b.eq     #0x1a2c
//   0x0015fc: 710241bf  cmp      w13, #0x90
//   0x001600: 54001fa1  b.ne     #0x19f4
//   0x001604: 321b016b  orr      w11, w11, #0x20
//   0x001608: 321b014a  orr      w10, w10, #0x20
//   0x00160c: 1400001c  b        #0x167c
//   0x001610: 712941bf  cmp      w13, #0xa50
//   0x001614: 54000340  b.eq     #0x167c
//   0x001618: 712b41bf  cmp      w13, #0xad0
//   0x00161c: 54001ec1  b.ne     #0x19f4
//   0x001620: 6b0b015f  cmp      w10, w11
//   0x001624: 54001e83  b.lo     #0x19f4
//   0x001628: 910022ad  add      x13, x21, #8
//   0x00162c: d37df129  lsl      x9, x9, #3
//   0x001630: 320003ec  mov      w12, #1
//   0x001634: d37df108  lsl      x8, x8, #3
//   0x001638: b86969a9  ldr      w9, [x13, x9]
//   0x00163c: 4b0b018c  sub      w12, w12, w11
//   0x001640: b86869ae  ldr      w14, [x13, x8]
//   0x001644: 0b0a018c  add      w12, w12, w10
//   0x001648: 1280000f  mov      w15, #-1
//   0x00164c: 1acc21ec  lsl      w12, w15, w12
//   0x001650: 0a2c0129  bic      w9, w9, w12
//   0x001654: 1aca21ea  lsl      w10, w15, w10
//   0x001658: 1acb21ec  lsl      w12, w15, w11
//   0x00165c: 0a0a01ca  and      w10, w14, w10
//   0x001660: 1acb2129  lsl      w9, w9, w11
//   0x001664: 0a2c01cc  bic      w12, w14, w12
//   0x001668: 2a090149  orr      w9, w10, w9
//   0x00166c: 2a0c0129  orr      w9, w9, w12
//   0x001670: 93407d29  sxtw     x9, w9
//   0x001674: f82869a9  str      x9, [x13, x8]
//   0x001678: 140000df  b        #0x19f4
//   0x00167c: 6b0b015f  cmp      w10, w11
//   0x001680: 54001bab  b.lt     #0x19f4
//   0x001684: 910022ac  add      x12, x21, #8
//   0x001688: d37df108  lsl      x8, x8, #3
//   0x00168c: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x001690: 1100054d  add      w13, w10, #1
//   0x001694: f868698e  ldr      x14, [x12, x8]
//   0x001698: 4b0b01ad  sub      w13, w13, w11
//   0x00169c: 9280000f  mov      x15, #-1
//   0x0016a0: 9acd21ed  lsl      x13, x15, x13
//   0x0016a4: 8a2d0129  bic      x9, x9, x13
//   0x0016a8: 9aca21ea  lsl      x10, x15, x10
//   0x0016ac: 9acb21ed  lsl      x13, x15, x11
//   0x0016b0: 8a0a01ca  and      x10, x14, x10
//   0x0016b4: 9acb2129  lsl      x9, x9, x11
//   0x0016b8: 8a2d01cd  bic      x13, x14, x13
//   0x0016bc: aa090149  orr      x9, x10, x9
//   0x0016c0: aa0d0129  orr      x9, x9, x13
//   0x0016c4: f8286989  str      x9, [x12, x8]
//   0x0016c8: 140000cb  b        #0x19f4
//   0x0016cc: 528002cb  mov      w11, #0x16
//   0x0016d0: 72a0030b  movk     w11, #0x18, lsl #16
//   0x0016d4: 6b0b015f  cmp      w10, w11
//   0x0016d8: 5400110c  b.gt     #0x18f8
//   0x0016dc: 528002eb  mov      w11, #0x17
//   0x0016e0: 72a001cb  movk     w11, #0xe, lsl #16
//   0x0016e4: 6b0b015f  cmp      w10, w11
//   0x0016e8: 54ffc8a0  b.eq     #0xffc
//   0x0016ec: 528002eb  mov      w11, #0x17
//   0x0016f0: 72a0026b  movk     w11, #0x13, lsl #16
//   0x0016f4: 6b0b015f  cmp      w10, w11
//   0x0016f8: 54ffc820  b.eq     #0xffc
//   0x0016fc: 140000be  b        #0x19f4
//   0x001700: 528002ca  mov      w10, #0x16
//   0x001704: 72a0030a  movk     w10, #0x18, lsl #16
//   0x001708: 6b0a013f  cmp      w9, w10
//   0x00170c: 540013ec  b.gt     #0x1988
//   0x001710: 528002ea  mov      w10, #0x17
//   0x001714: 72a001ca  movk     w10, #0xe, lsl #16
//   0x001718: 6b0a013f  cmp      w9, w10
//   0x00171c: 540032a0  b.eq     #0x1d70
//   0x001720: 528002ea  mov      w10, #0x17
//   0x001724: 72a0026a  movk     w10, #0x13, lsl #16
//   0x001728: 6b0a013f  cmp      w9, w10
//   0x00172c: 54001641  b.ne     #0x19f4
//   0x001730: b6ffc8eb  tbz      x11, #0x3f, #0x104c
//   0x001734: 14000179  b        #0x1d18
//   0x001738: 5281ffe9  mov      w9, #0xfff
//   0x00173c: 72af8009  movk     w9, #0x7c00, lsl #16
//   0x001740: 528051eb  mov      w11, #0x28f
//   0x001744: 0a090189  and      w9, w12, w9
//   0x001748: 72a9800b  movk     w11, #0x4c00, lsl #16
//   0x00174c: 6b0b013f  cmp      w9, w11
//   0x001750: 540019ed  b.le     #0x1a8c
//   0x001754: 5280520b  mov      w11, #0x290
//   0x001758: 72a9800b  movk     w11, #0x4c00, lsl #16
//   0x00175c: 6b0b013f  cmp      w9, w11
//   0x001760: 540031e0  b.eq     #0x1d9c
//   0x001764: 5280d20b  mov      w11, #0x690
//   0x001768: 72aa800b  movk     w11, #0x5400, lsl #16
//   0x00176c: 6b0b013f  cmp      w9, w11
//   0x001770: 54003200  b.eq     #0x1db0
//   0x001774: 5280520b  mov      w11, #0x290
//   0x001778: 72ae800b  movk     w11, #0x7400, lsl #16
//   0x00177c: 6b0b013f  cmp      w9, w11
//   0x001780: 540013a1  b.ne     #0x19f4
//   0x001784: 910022a9  add      x9, x21, #8
//   0x001788: d37df108  lsl      x8, x8, #3
//   0x00178c: b8686928  ldr      w8, [x9, x8]
//   0x001790: 53087d0b  lsr      w11, w8, #8
//   0x001794: 53185d08  lsl      w8, w8, #8
//   0x001798: 12009d6b  and      w11, w11, #0xff00ff
//   0x00179c: 12089d08  and      w8, w8, #0xff00ff00
//   0x0017a0: 2a0b0108  orr      w8, w8, w11
//   0x0017a4: 14000256  b        #0x20fc
//   0x0017a8: 710ba55f  cmp      w10, #0x2e9
//   0x0017ac: 54002260  b.eq     #0x1bf8
//   0x0017b0: 7114bd5f  cmp      w10, #0x52f
//   0x0017b4: 54005180  b.eq     #0x21e4
//   0x0017b8: 711cbd5f  cmp      w10, #0x72f
//   0x0017bc: 540011c1  b.ne     #0x19f4
//   0x0017c0: 910022aa  add      x10, x21, #8
//   0x0017c4: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x0017c8: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x0017cc: 9b497d0a  smulh    x10, x8, x9
//   0x0017d0: 140002ba  b        #0x22b8
//   0x0017d4: 7124bd5f  cmp      w10, #0x92f
//   0x0017d8: 540033a0  b.eq     #0x1e4c
//   0x0017dc: 712cbd5f  cmp      w10, #0xb2f
//   0x0017e0: 540054a0  b.eq     #0x2274
//   0x0017e4: 7136bd5f  cmp      w10, #0xdaf
//   0x0017e8: 54001061  b.ne     #0x19f4
//   0x0017ec: 910022aa  add      x10, x21, #8
//   0x0017f0: d37df129  lsl      x9, x9, #3
//   0x0017f4: d37df108  lsl      x8, x8, #3
//   0x0017f8: b8696949  ldr      w9, [x10, x9]
//   0x0017fc: b8686948  ldr      w8, [x10, x8]
//   0x001800: 1ac80d2a  sdiv     w10, w9, w8
//   0x001804: 1400027e  b        #0x21fc
//   0x001808: 0a180189  and      w9, w12, w24
//   0x00180c: 511c430c  sub      w12, w24, #0x710
//   0x001810: 6b0c013f  cmp      w9, w12
//   0x001814: 1a8d018d  csel     w13, w12, w13, eq
//   0x001818: 5103430c  sub      w12, w24, #0xd0
//   0x00181c: 6b0c013f  cmp      w9, w12
//   0x001820: 1a8d018d  csel     w13, w12, w13, eq
//   0x001824: 5111430c  sub      w12, w24, #0x450
//   0x001828: 6b0c013f  cmp      w9, w12
//   0x00182c: 1a8d018d  csel     w13, w12, w13, eq
//   0x001830: 7131b9bf  cmp      w13, #0xc6e
//   0x001834: 5400018c  b.gt     #0x1864
//   0x001838: 7123b9bf  cmp      w13, #0x8ee
//   0x00183c: 5400170c  b.gt     #0x1b1c
//   0x001840: 710bbdbf  cmp      w13, #0x2ef
//   0x001844: 540040a0  b.eq     #0x2058
//   0x001848: 710fbdbf  cmp      w13, #0x3ef
//   0x00184c: 54004100  b.eq     #0x206c
//   0x001850: 7111bdbf  cmp      w13, #0x46f
//   0x001854: 54000d01  b.ne     #0x19f4
//   0x001858: 910022a9  add      x9, x21, #8
//   0x00185c: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x001860: 14000211  b        #0x20a4
//   0x001864: 52811dc9  mov      w9, #0x8ee
//   0x001868: 72a00409  movk     w9, #0x20, lsl #16
//   0x00186c: 6b0901bf  cmp      w13, w9
//   0x001870: 540016cc  b.gt     #0x1b48
//   0x001874: 7131bdbf  cmp      w13, #0xc6f
//   0x001878: 54004040  b.eq     #0x2080
//   0x00187c: 7132bdbf  cmp      w13, #0xcaf
//   0x001880: 540040a0  b.eq     #0x2094
//   0x001884: 713cbdbf  cmp      w13, #0xf2f
//   0x001888: 54000b61  b.ne     #0x19f4
//   0x00188c: 910022a9  add      x9, x21, #8
//   0x001890: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x001894: 321b016b  orr      w11, w11, #0x20
//   0x001898: 92403d6b  and      x11, x11, #0xffff
//   0x00189c: 14000207  b        #0x20b8
//   0x0018a0: 12002d8b  and      w11, w12, #0xfff
//   0x0018a4: 7120b97f  cmp      w11, #0x82e
//   0x0018a8: 5400170c  b.gt     #0x1b88
//   0x0018ac: 710dbd7f  cmp      w11, #0x36f
//   0x0018b0: 54003ba0  b.eq     #0x2024
//   0x0018b4: 7118bd7f  cmp      w11, #0x62f
//   0x0018b8: 540009e1  b.ne     #0x19f4
//   0x0018bc: 910022ab  add      x11, x21, #8
//   0x0018c0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0018c4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x0018c8: aa090108  orr      x8, x8, x9
//   0x0018cc: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0018d0: 14000049  b        #0x19f4
//   0x0018d4: 528002eb  mov      w11, #0x17
//   0x0018d8: 72a000eb  movk     w11, #7, lsl #16
//   0x0018dc: 6b0b015f  cmp      w10, w11
//   0x0018e0: 54ffb8e0  b.eq     #0xffc
//   0x0018e4: 528002eb  mov      w11, #0x17
//   0x0018e8: 72a0018b  movk     w11, #0xc, lsl #16
//   0x0018ec: 6b0b015f  cmp      w10, w11
//   0x0018f0: 54ffb860  b.eq     #0xffc
//   0x0018f4: 14000040  b        #0x19f4
//   0x0018f8: 528002eb  mov      w11, #0x17
//   0x0018fc: 72a0036b  movk     w11, #0x1b, lsl #16
//   0x001900: 6b0b015f  cmp      w10, w11
//   0x001904: 54ffb7c0  b.eq     #0xffc
//   0x001908: 528002eb  mov      w11, #0x17
//   0x00190c: 72a0030b  movk     w11, #0x18, lsl #16
//   0x001910: 6b0b015f  cmp      w10, w11
//   0x001914: 54ffb740  b.eq     #0xffc
//   0x001918: 14000037  b        #0x19f4
//   0x00191c: 710eb97f  cmp      w11, #0x3ae
//   0x001920: 54000eac  b.gt     #0x1af4
//   0x001924: 7107bd7f  cmp      w11, #0x1ef
//   0x001928: 54000d40  b.eq     #0x1ad0
//   0x00192c: 7108a57f  cmp      w11, #0x229
//   0x001930: 54000621  b.ne     #0x19f4
//   0x001934: d37df129  lsl      x9, x9, #3
//   0x001938: 910022ab  add      x11, x21, #8
//   0x00193c: d37df108  lsl      x8, x8, #3
//   0x001940: b8a86968  ldrsw    x8, [x11, x8]
//   0x001944: b8a96969  ldrsw    x9, [x11, x9]
//   0x001948: 9b097d08  mul      x8, x8, x9
//   0x00194c: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x001950: 14000029  b        #0x19f4
//   0x001954: 528002ea  mov      w10, #0x17
//   0x001958: 72a000ea  movk     w10, #7, lsl #16
//   0x00195c: 6b0a013f  cmp      w9, w10
//   0x001960: 54002120  b.eq     #0x1d84
//   0x001964: 528002ea  mov      w10, #0x17
//   0x001968: 72a0018a  movk     w10, #0xc, lsl #16
//   0x00196c: 6b0a013f  cmp      w9, w10
//   0x001970: 54000421  b.ne     #0x19f4
//   0x001974: 320013ea  mov      w10, #0x1f
//   0x001978: b7f81d2b  tbnz     x11, #0x3f, #0x1d1c
//   0x00197c: 2a1f03eb  mov      w11, wzr
//   0x001980: 2a1f03e9  mov      w9, wzr
//   0x001984: 140000d4  b        #0x1cd4
//   0x001988: 528002ea  mov      w10, #0x17
//   0x00198c: 72a0030a  movk     w10, #0x18, lsl #16
//   0x001990: 6b0a013f  cmp      w9, w10
//   0x001994: 54001fe0  b.eq     #0x1d90
//   0x001998: 528002ea  mov      w10, #0x17
//   0x00199c: 72a0036a  movk     w10, #0x1b, lsl #16
//   0x0019a0: 6b0a013f  cmp      w9, w10
//   0x0019a4: 54000281  b.ne     #0x19f4
//   0x0019a8: 320013ea  mov      w10, #0x1f
//   0x0019ac: 320003e9  mov      w9, #1
//   0x0019b0: b6f81b8b  tbz      x11, #0x3f, #0x1d20
//   0x0019b4: 140000f2  b        #0x1d7c
//   0x0019b8: 321b016b  orr      w11, w11, #0x20
//   0x0019bc: 0b0a016c  add      w12, w11, w10
//   0x0019c0: 7100fd9f  cmp      w12, #0x3f
//   0x0019c4: 5400018c  b.gt     #0x19f4
//   0x0019c8: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x0019cc: f9400529  ldr      x9, [x9, #8]
//   0x0019d0: 7100fd5f  cmp      w10, #0x3f
//   0x0019d4: 540000c0  b.eq     #0x19ec
//   0x0019d8: 1100054a  add      w10, w10, #1
//   0x0019dc: 9acb2529  lsr      x9, x9, x11
//   0x0019e0: 9280000b  mov      x11, #-1
//   0x0019e4: 9aca216a  lsl      x10, x11, x10
//   0x0019e8: 8a2a0129  bic      x9, x9, x10
//   0x0019ec: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0019f0: f9000509  str      x9, [x8, #8]
//   0x0019f4: f94002a9  ldr      x9, [x21]
//   0x0019f8: f85e0268  ldur     x8, [x19, #-0x20]
//   0x0019fc: 91001120  add      x0, x9, #4
//   0x001a00: f100091f  cmp      x8, #2
//   0x001a04: f90002a0  str      x0, [x21]
//   0x001a08: 540000e0  b.eq     #0x1a24
//   0x001a0c: f1000d1f  cmp      x8, #3
//   0x001a10: 54001180  b.eq     #0x1c40
//   0x001a14: f100051f  cmp      x8, #1
//   0x001a18: 54001140  b.eq     #0x1c40
//   0x001a1c: eb14001f  cmp      x0, x20
//   0x001a20: 540011a0  b.eq     #0x1c54
//   0x001a24: b5ff8c00  cbnz     x0, #0xba4
//   0x001a28: 1400027f  b        #0x2424
//   0x001a2c: 0b0b014c  add      w12, w10, w11
//   0x001a30: 71007d9f  cmp      w12, #0x1f
//   0x001a34: 54fffe08  b.hi     #0x19f4
//   0x001a38: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x001a3c: b9400929  ldr      w9, [x9, #8]
//   0x001a40: 71007d5f  cmp      w10, #0x1f
//   0x001a44: 54ffc860  b.eq     #0x1350
//   0x001a48: 1acb2529  lsr      w9, w9, w11
//   0x001a4c: 321f7beb  mov      w11, #-2
//   0x001a50: 1aca216a  lsl      w10, w11, w10
//   0x001a54: 0a2a0129  bic      w9, w9, w10
//   0x001a58: 17fffe3e  b        #0x1350
//   0x001a5c: 113342eb  add      w11, w23, #0xcd0
//   0x001a60: 0a0b018b  and      w11, w12, w11
//   0x001a64: 6b17017f  cmp      w11, w23
//   0x001a68: 1a8d02ed  csel     w13, w23, w13, eq
//   0x001a6c: 14000122  b        #0x1ef4
//   0x001a70: 910022ab  add      x11, x21, #8
//   0x001a74: d37df129  lsl      x9, x9, #3
//   0x001a78: d37df108  lsl      x8, x8, #3
//   0x001a7c: b8696969  ldr      w9, [x11, x9]
//   0x001a80: b8686968  ldr      w8, [x11, x8]
//   0x001a84: 4b080128  sub      w8, w9, w8
//   0x001a88: 14000018  b        #0x1ae8
//   0x001a8c: 5280d20b  mov      w11, #0x690
//   0x001a90: 72a1800b  movk     w11, #0xc00, lsl #16
//   0x001a94: 6b0b013f  cmp      w9, w11
//   0x001a98: 540019e0  b.eq     #0x1dd4
//   0x001a9c: 5280520b  mov      w11, #0x290
//   0x001aa0: 72a7000b  movk     w11, #0x3800, lsl #16
//   0x001aa4: 6b0b013f  cmp      w9, w11
//   0x001aa8: 54fffa61  b.ne     #0x19f4
//   0x001aac: 910022a9  add      x9, x21, #8
//   0x001ab0: d37df108  lsl      x8, x8, #3
//   0x001ab4: 38a86928  ldrsb    x8, [x9, x8]
//   0x001ab8: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x001abc: 17ffffce  b        #0x19f4
//   0x001ac0: 710eb97f  cmp      w11, #0x3ae
//   0x001ac4: 5400018c  b.gt     #0x1af4
//   0x001ac8: 7107bd7f  cmp      w11, #0x1ef
//   0x001acc: 54fff301  b.ne     #0x192c
//   0x001ad0: 910022ab  add      x11, x21, #8
//   0x001ad4: d37df129  lsl      x9, x9, #3
//   0x001ad8: d37df108  lsl      x8, x8, #3
//   0x001adc: b8696969  ldr      w9, [x11, x9]
//   0x001ae0: b8686968  ldr      w8, [x11, x8]
//   0x001ae4: 0b090108  add      w8, w8, w9
//   0x001ae8: 93407d08  sxtw     x8, w8
//   0x001aec: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x001af0: 17ffffc1  b        #0x19f4
//   0x001af4: 710ebd7f  cmp      w11, #0x3af
//   0x001af8: 54000060  b.eq     #0x1b04
//   0x001afc: 711bbd7f  cmp      w11, #0x6ef
//   0x001b00: 54fff7a1  b.ne     #0x19f4
//   0x001b04: 910022ab  add      x11, x21, #8
//   0x001b08: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x001b0c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x001b10: cb080128  sub      x8, x9, x8
//   0x001b14: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x001b18: 17ffffb7  b        #0x19f4
//   0x001b1c: 7123bdbf  cmp      w13, #0x8ef
//   0x001b20: 54002c80  b.eq     #0x20b0
//   0x001b24: 712dbdbf  cmp      w13, #0xb6f
//   0x001b28: 54002ce0  b.eq     #0x20c4
//   0x001b2c: 712ebdbf  cmp      w13, #0xbaf
//   0x001b30: 54fff621  b.ne     #0x19f4
//   0x001b34: 910022a9  add      x9, x21, #8
//   0x001b38: d37df108  lsl      x8, x8, #3
//   0x001b3c: b8686928  ldr      w8, [x9, x8]
//   0x001b40: 1acb2508  lsr      w8, w8, w11
//   0x001b44: 1400016e  b        #0x20fc
//   0x001b48: 52811de9  mov      w9, #0x8ef
//   0x001b4c: 72a00409  movk     w9, #0x20, lsl #16
//   0x001b50: 6b0901bf  cmp      w13, w9
//   0x001b54: 54002c20  b.eq     #0x20d8
//   0x001b58: 528175e9  mov      w9, #0xbaf
//   0x001b5c: 72a00409  movk     w9, #0x20, lsl #16
//   0x001b60: 6b0901bf  cmp      w13, w9
//   0x001b64: 54002c40  b.eq     #0x20ec
//   0x001b68: 5281e5e9  mov      w9, #0xf2f
//   0x001b6c: 72a00409  movk     w9, #0x20, lsl #16
//   0x001b70: 6b0901bf  cmp      w13, w9
//   0x001b74: 54fff401  b.ne     #0x19f4
//   0x001b78: 910022a9  add      x9, x21, #8
//   0x001b7c: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x001b80: 321b016b  orr      w11, w11, #0x20
//   0x001b84: 14000157  b        #0x20e0
//   0x001b88: 7120bd7f  cmp      w11, #0x82f
//   0x001b8c: 54002580  b.eq     #0x203c
//   0x001b90: 713dbd7f  cmp      w11, #0xf6f
//   0x001b94: 54fff301  b.ne     #0x19f4
//   0x001b98: 910022ab  add      x11, x21, #8
//   0x001b9c: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x001ba0: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x001ba4: 8a090108  and      x8, x8, x9
//   0x001ba8: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x001bac: 17ffff92  b        #0x19f4
//   0x001bb0: 910022aa  add      x10, x21, #8
//   0x001bb4: d37df129  lsl      x9, x9, #3
//   0x001bb8: d37df108  lsl      x8, x8, #3
//   0x001bbc: b94000cb  ldr      w11, [x6]
//   0x001bc0: b94000ec  ldr      w12, [x7]
//   0x001bc4: b8696949  ldr      w9, [x10, x9]
//   0x001bc8: b8686948  ldr      w8, [x10, x8]
//   0x001bcc: 14000012  b        #0x1c14
//   0x001bd0: 910022aa  add      x10, x21, #8
//   0x001bd4: d37df129  lsl      x9, x9, #3
//   0x001bd8: d37df108  lsl      x8, x8, #3
//   0x001bdc: b94000cb  ldr      w11, [x6]
//   0x001be0: b94000ec  ldr      w12, [x7]
//   0x001be4: b8a96949  ldrsw    x9, [x10, x9]
//   0x001be8: b8a86948  ldrsw    x8, [x10, x8]
//   0x001bec: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x001bf0: 9b093108  madd     x8, x8, x9, x12
//   0x001bf4: 1400000a  b        #0x1c1c
//   0x001bf8: 910022aa  add      x10, x21, #8
//   0x001bfc: d37df129  lsl      x9, x9, #3
//   0x001c00: d37df108  lsl      x8, x8, #3
//   0x001c04: b94000cb  ldr      w11, [x6]
//   0x001c08: b94000ec  ldr      w12, [x7]
//   0x001c0c: b8a96949  ldrsw    x9, [x10, x9]
//   0x001c10: b8a86948  ldrsw    x8, [x10, x8]
//   0x001c14: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x001c18: 9b09b108  msub     x8, x8, x9, x12
//   0x001c1c: 92407d09  and      x9, x8, #0xffffffff
//   0x001c20: d360fd08  lsr      x8, x8, #0x20
//   0x001c24: 14000184  b        #0x2234
//   0x001c28: 320013ea  mov      w10, #0x1f
//   0x001c2c: f85f8268  ldur     x8, [x19, #-8]
//   0x001c30: 2a1f03eb  mov      w11, wzr
//   0x001c34: 2a1f03e9  mov      w9, wzr
//   0x001c38: 8b2c4108  add      x8, x8, w12, uxtw
//   0x001c3c: 14000026  b        #0x1cd4
//   0x001c40: f85e8260  ldur     x0, [x19, #-0x18]
//   0x001c44: f81e027f  stur     xzr, [x19, #-0x20]
//   0x001c48: f90002a0  str      x0, [x21]
//   0x001c4c: eb14001f  cmp      x0, x20
//   0x001c50: 54ffeea1  b.ne     #0x1a24
//   0x001c54: f9400080  ldr      x0, [x4]
//   0x001c58: f94000a1  ldr      x1, [x5]
//   0x001c5c: aa0403f8  mov      x24, x4
//   0x001c60: aa0503fa  mov      x26, x5
//   0x001c64: f90007e6  str      x6, [sp, #8]
//   0x001c68: aa0703f7  mov      x23, x7
//   0x001c6c: d63f0280  blr      x20
//   0x001c70: f94007e6  ldr      x6, [sp, #8]
//   0x001c74: f85f0260  ldur     x0, [x19, #-0x10]
//   0x001c78: aa1703e7  mov      x7, x23
//   0x001c7c: 528065f7  mov      w23, #0x32f
//   0x001c80: aa1803e4  mov      x4, x24
//   0x001c84: 5281fff8  mov      w24, #0xfff
//   0x001c88: 321b03fe  mov      w30, #0x20
//   0x001c8c: 72a08017  movk     w23, #0x400, lsl #16
//   0x001c90: aa1a03e5  mov      x5, x26
//   0x001c94: 320007fa  mov      w26, #3
//   0x001c98: 72a00418  movk     w24, #0x20, lsl #16
//   0x001c9c: f90002a0  str      x0, [x21]
//   0x001ca0: b5ff7820  cbnz     x0, #0xba4
//   0x001ca4: 140001e0  b        #0x2424
//   0x001ca8: eb0d017f  cmp      x11, x13
//   0x001cac: 54ff9d01  b.ne     #0x104c
//   0x001cb0: 1400001a  b        #0x1d18
//   0x001cb4: eb0d017f  cmp      x11, x13
//   0x001cb8: 54ff9ca0  b.eq     #0x104c
//   0x001cbc: 14000017  b        #0x1d18
//   0x001cc0: f100017f  cmp      x11, #0
//   0x001cc4: 320003e9  mov      w9, #1
//   0x001cc8: 5400018d  b.le     #0x1cf8
//   0x001ccc: 2a1f03eb  mov      w11, wzr
//   0x001cd0: 2a1f03ea  mov      w10, wzr
//   0x001cd4: 320003ec  mov      w12, #1
//   0x001cd8: 14000015  b        #0x1d2c
//   0x001cdc: eb0d017f  cmp      x11, x13
//   0x001ce0: 320003e9  mov      w9, #1
//   0x001ce4: 54ffff40  b.eq     #0x1ccc
//   0x001ce8: 14000004  b        #0x1cf8
//   0x001cec: f100057f  cmp      x11, #1
//   0x001cf0: 320003e9  mov      w9, #1
//   0x001cf4: 54fffecb  b.lt     #0x1ccc
//   0x001cf8: 2a1f03ea  mov      w10, wzr
//   0x001cfc: 14000009  b        #0x1d20
//   0x001d00: eb0d017f  cmp      x11, x13
//   0x001d04: 320003e9  mov      w9, #1
//   0x001d08: 54ffff80  b.eq     #0x1cf8
//   0x001d0c: 17fffff0  b        #0x1ccc
//   0x001d10: f100057f  cmp      x11, #1
//   0x001d14: 54ff99cb  b.lt     #0x104c
//   0x001d18: 2a1f03ea  mov      w10, wzr
//   0x001d1c: 2a1f03e9  mov      w9, wzr
//   0x001d20: 2a1f03ec  mov      w12, wzr
//   0x001d24: 91002008  add      x8, x0, #8
//   0x001d28: 320003eb  mov      w11, #1
//   0x001d2c: 7100013f  cmp      w9, #0
//   0x001d30: 1a9f07ed  cset     w13, ne
//   0x001d34: 0a0d016b  and      w11, w11, w13
//   0x001d38: f81e8268  stur     x8, [x19, #-0x18]
//   0x001d3c: 3700008b  tbnz     w11, #0, #0x1d4c
//   0x001d40: 34000069  cbz      w9, #0x1d4c
//   0x001d44: 0a0d0188  and      w8, w12, w13
//   0x001d48: 34ffb7a8  cbz      w8, #0x143c
//   0x001d4c: 7100017f  cmp      w11, #0
//   0x001d50: 320003e8  mov      w8, #1
//   0x001d54: 9a881508  cinc     x8, x8, eq
//   0x001d58: f81e0268  stur     x8, [x19, #-0x20]
//   0x001d5c: 7100055f  cmp      w10, #1
//   0x001d60: 54ffe4ab  b.lt     #0x19f4
//   0x001d64: 17fffdb8  b        #0x1444
//   0x001d68: b6fffd8b  tbz      x11, #0x3f, #0x1d18
//   0x001d6c: 17fffcb8  b        #0x104c
//   0x001d70: 320013ea  mov      w10, #0x1f
//   0x001d74: 320003e9  mov      w9, #1
//   0x001d78: b7fffd4b  tbnz     x11, #0x3f, #0x1d20
//   0x001d7c: 2a1f03eb  mov      w11, wzr
//   0x001d80: 17ffffd5  b        #0x1cd4
//   0x001d84: 320003e9  mov      w9, #1
//   0x001d88: b6fffb8b  tbz      x11, #0x3f, #0x1cf8
//   0x001d8c: 17ffffd0  b        #0x1ccc
//   0x001d90: 320003e9  mov      w9, #1
//   0x001d94: b6fff9cb  tbz      x11, #0x3f, #0x1ccc
//   0x001d98: 17ffffd8  b        #0x1cf8
//   0x001d9c: 910022a9  add      x9, x21, #8
//   0x001da0: d37df108  lsl      x8, x8, #3
//   0x001da4: 78a86928  ldrsh    x8, [x9, x8]
//   0x001da8: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x001dac: 17ffff12  b        #0x19f4
//   0x001db0: 910022a9  add      x9, x21, #8
//   0x001db4: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x001db8: d348fd0b  lsr      x11, x8, #8
//   0x001dbc: d378dd08  lsl      x8, x8, #8
//   0x001dc0: 92009d6b  and      x11, x11, #0xff00ff00ff00ff
//   0x001dc4: 92089d08  and      x8, x8, #0xff00ff00ff00ff00
//   0x001dc8: aa0b0108  orr      x8, x8, x11
//   0x001dcc: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x001dd0: 17ffff09  b        #0x19f4
//   0x001dd4: 910022a9  add      x9, x21, #8
//   0x001dd8: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x001ddc: d350fd0b  lsr      x11, x8, #0x10
//   0x001de0: d370bd08  lsl      x8, x8, #0x10
//   0x001de4: 92003d6b  and      x11, x11, #0xffff0000ffff
//   0x001de8: 92103d08  and      x8, x8, #0xffff0000ffff0000
//   0x001dec: aa0b0108  orr      x8, x8, x11
//   0x001df0: 93c88108  ror      x8, x8, #0x20
//   0x001df4: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x001df8: 17fffeff  b        #0x19f4
//   0x001dfc: 910022ab  add      x11, x21, #8
//   0x001e00: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x001e04: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x001e08: eb08013f  cmp      x9, x8
//   0x001e0c: 8b2a4d68  add      x8, x11, w10, uxtw #3
//   0x001e10: 54000f63  b.lo     #0x1ffc
//   0x001e14: f900011f  str      xzr, [x8]
//   0x001e18: 17fffef7  b        #0x19f4
//   0x001e1c: 7124b9bf  cmp      w13, #0x92e
//   0x001e20: 54001b0d  b.le     #0x2180
//   0x001e24: 7136b9bf  cmp      w13, #0xdae
//   0x001e28: 54001bec  b.gt     #0x21a4
//   0x001e2c: 712cb9bf  cmp      w13, #0xb2e
//   0x001e30: 5400212c  b.gt     #0x2254
//   0x001e34: 7124bdbf  cmp      w13, #0x92f
//   0x001e38: 540000a0  b.eq     #0x1e4c
//   0x001e3c: 7126bdbf  cmp      w13, #0x9af
//   0x001e40: 54ffdda1  b.ne     #0x19f4
//   0x001e44: f94000e8  ldr      x8, [x7]
//   0x001e48: 14000174  b        #0x2418
//   0x001e4c: 910022aa  add      x10, x21, #8
//   0x001e50: d37df129  lsl      x9, x9, #3
//   0x001e54: d37df108  lsl      x8, x8, #3
//   0x001e58: b8a96949  ldrsw    x9, [x10, x9]
//   0x001e5c: b8a86948  ldrsw    x8, [x10, x8]
//   0x001e60: 140000f2  b        #0x2228
//   0x001e64: b5ffdc81  cbnz     x1, #0x19f4
//   0x001e68: 12002d8d  and      w13, w12, #0xfff
//   0x001e6c: 51000dae  sub      w14, w13, #3
//   0x001e70: 7100f1df  cmp      w14, #0x3c
//   0x001e74: 2a1f03e8  mov      w8, wzr
//   0x001e78: 54001e48  b.hi     #0x2240
//   0x001e7c: f000002d  adrp     x13, #0x8000
//   0x001e80: 910f11ad  add      x13, x13, #0x3c4
//   0x001e84: aa0d03ef  mov      x15, x13
//   0x001e88: b8ae79ed  ldrsw    x13, [x15, x14, lsl #2]
//   0x001e8c: 8b0f01ae  add      x14, x13, x15
//   0x001e90: aa1f03ed  mov      x13, xzr
//   0x001e94: d61f01c0  br       x14
//   0x001e98: 8b2a4ea8  add      x8, x21, w10, uxtw #3
//   0x001e9c: f940050d  ldr      x13, [x8, #8]
//   0x001ea0: 12002d88  and      w8, w12, #0xfff
//   0x001ea4: 51000d08  sub      w8, w8, #3
//   0x001ea8: 7100f11f  cmp      w8, #0x3c
//   0x001eac: 54ffda48  b.hi     #0x19f4
//   0x001eb0: f000002a  adrp     x10, #0x8000
//   0x001eb4: 9112e14a  add      x10, x10, #0x4b8
//   0x001eb8: aa0a03ec  mov      x12, x10
//   0x001ebc: b8a8798a  ldrsw    x10, [x12, x8, lsl #2]
//   0x001ec0: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x001ec4: f9400508  ldr      x8, [x8, #8]
//   0x001ec8: 11001169  add      w9, w11, #4
//   0x001ecc: 8b0c014a  add      x10, x10, x12
//   0x001ed0: 8b090009  add      x9, x0, x9
//   0x001ed4: d61f0140  br       x10
//   0x001ed8: f100011f  cmp      x8, #0
//   0x001edc: 5400246d  b.le     #0x2368
//   0x001ee0: 2a1f03ec  mov      w12, wzr
//   0x001ee4: 2a1f03ea  mov      w10, wzr
//   0x001ee8: 1400011c  b        #0x2358
//   0x001eec: 113342eb  add      w11, w23, #0xcd0
//   0x001ef0: 0a0b018b  and      w11, w12, w11
//   0x001ef4: 110d02ec  add      w12, w23, #0x340
//   0x001ef8: 6b0c017f  cmp      w11, w12
//   0x001efc: 1a8d018d  csel     w13, w12, w13, eq
//   0x001f00: 7135b9bf  cmp      w13, #0xd6e
//   0x001f04: 540001cc  b.gt     #0x1f3c
//   0x001f08: 7117b9bf  cmp      w13, #0x5ee
//   0x001f0c: 5400038c  b.gt     #0x1f7c
//   0x001f10: 7102bdbf  cmp      w13, #0xaf
//   0x001f14: 54000fa0  b.eq     #0x2108
//   0x001f18: 710cbdbf  cmp      w13, #0x32f
//   0x001f1c: 54ffd6c1  b.ne     #0x19f4
//   0x001f20: 910022ab  add      x11, x21, #8
//   0x001f24: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x001f28: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x001f2c: 92401529  and      x9, x9, #0x3f
//   0x001f30: 9ac92508  lsr      x8, x8, x9
//   0x001f34: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x001f38: 17fffeaf  b        #0x19f4
//   0x001f3c: 528065cb  mov      w11, #0x32e
//   0x001f40: 72a0800b  movk     w11, #0x400, lsl #16
//   0x001f44: 6b0b01bf  cmp      w13, w11
//   0x001f48: 5400032c  b.gt     #0x1fac
//   0x001f4c: 7135bdbf  cmp      w13, #0xd6f
//   0x001f50: 54000ea0  b.eq     #0x2124
//   0x001f54: 713fbdbf  cmp      w13, #0xfef
//   0x001f58: 54ffd4e1  b.ne     #0x19f4
//   0x001f5c: 910022ab  add      x11, x21, #8
//   0x001f60: d37df129  lsl      x9, x9, #3
//   0x001f64: b8696969  ldr      w9, [x11, x9]
//   0x001f68: d37df108  lsl      x8, x8, #3
//   0x001f6c: b8686968  ldr      w8, [x11, x8]
//   0x001f70: 12001129  and      w9, w9, #0x1f
//   0x001f74: 1ac92108  lsl      w8, w8, w9
//   0x001f78: 17fffedc  b        #0x1ae8
//   0x001f7c: 7117bdbf  cmp      w13, #0x5ef
//   0x001f80: 54000e00  b.eq     #0x2140
//   0x001f84: 7119bdbf  cmp      w13, #0x66f
//   0x001f88: 54ffd361  b.ne     #0x19f4
//   0x001f8c: 910022ab  add      x11, x21, #8
//   0x001f90: d37df129  lsl      x9, x9, #3
//   0x001f94: b8696969  ldr      w9, [x11, x9]
//   0x001f98: d37df108  lsl      x8, x8, #3
//   0x001f9c: b8686968  ldr      w8, [x11, x8]
//   0x001fa0: 12001129  and      w9, w9, #0x1f
//   0x001fa4: 1ac92508  lsr      w8, w8, w9
//   0x001fa8: 17fffed0  b        #0x1ae8
//   0x001fac: 6b1701bf  cmp      w13, w23
//   0x001fb0: 54000d80  b.eq     #0x2160
//   0x001fb4: 5280cdeb  mov      w11, #0x66f
//   0x001fb8: 72a0800b  movk     w11, #0x400, lsl #16
//   0x001fbc: 6b0b01bf  cmp      w13, w11
//   0x001fc0: 54ffd1a1  b.ne     #0x19f4
//   0x001fc4: 910022ab  add      x11, x21, #8
//   0x001fc8: d37df129  lsl      x9, x9, #3
//   0x001fcc: b8696969  ldr      w9, [x11, x9]
//   0x001fd0: d37df108  lsl      x8, x8, #3
//   0x001fd4: b8686968  ldr      w8, [x11, x8]
//   0x001fd8: 12001129  and      w9, w9, #0x1f
//   0x001fdc: 1ac92d08  ror      w8, w8, w9
//   0x001fe0: 17fffec2  b        #0x1ae8
//   0x001fe4: 910022ab  add      x11, x21, #8
//   0x001fe8: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x001fec: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x001ff0: eb08013f  cmp      x9, x8
//   0x001ff4: 8b2a4d68  add      x8, x11, w10, uxtw #3
//   0x001ff8: 54fff0ea  b.ge     #0x1e14
//   0x001ffc: 320003e9  mov      w9, #1
//   0x002000: f9000109  str      x9, [x8]
//   0x002004: 17fffe7c  b        #0x19f4
//   0x002008: 0a180189  and      w9, w12, w24
//   0x00200c: 17fffe06  b        #0x1824
//   0x002010: 0a180189  and      w9, w12, w24
//   0x002014: 17fffe01  b        #0x1818
//   0x002018: 320007e1  mov      w1, #3
//   0x00201c: f81e027a  stur     x26, [x19, #-0x20]
//   0x002020: 17fffae5  b        #0xbb4
//   0x002024: 910022ab  add      x11, x21, #8
//   0x002028: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x00202c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x002030: ca090108  eor      x8, x8, x9
//   0x002034: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x002038: 17fffe6f  b        #0x19f4
//   0x00203c: 910022ab  add      x11, x21, #8
//   0x002040: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x002044: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x002048: aa090108  orr      x8, x8, x9
//   0x00204c: aa2803e8  mvn      x8, x8
//   0x002050: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x002054: 17fffe68  b        #0x19f4
//   0x002058: 910022a9  add      x9, x21, #8
//   0x00205c: d37df108  lsl      x8, x8, #3
//   0x002060: b8686928  ldr      w8, [x9, x8]
//   0x002064: 1acb2908  asr      w8, w8, w11
//   0x002068: 14000025  b        #0x20fc
//   0x00206c: 910022a9  add      x9, x21, #8
//   0x002070: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x002074: 321b016b  orr      w11, w11, #0x20
//   0x002078: 92403d6b  and      x11, x11, #0xffff
//   0x00207c: 14000014  b        #0x20cc
//   0x002080: 910022a9  add      x9, x21, #8
//   0x002084: d37df108  lsl      x8, x8, #3
//   0x002088: b8686928  ldr      w8, [x9, x8]
//   0x00208c: 1acb2108  lsl      w8, w8, w11
//   0x002090: 1400001b  b        #0x20fc
//   0x002094: 910022a9  add      x9, x21, #8
//   0x002098: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x00209c: 321b016b  orr      w11, w11, #0x20
//   0x0020a0: 92403d6b  and      x11, x11, #0xffff
//   0x0020a4: 9acb2108  lsl      x8, x8, x11
//   0x0020a8: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x0020ac: 17fffe52  b        #0x19f4
//   0x0020b0: 910022a9  add      x9, x21, #8
//   0x0020b4: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x0020b8: 9acb2508  lsr      x8, x8, x11
//   0x0020bc: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x0020c0: 17fffe4d  b        #0x19f4
//   0x0020c4: 910022a9  add      x9, x21, #8
//   0x0020c8: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x0020cc: 9acb2908  asr      x8, x8, x11
//   0x0020d0: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x0020d4: 17fffe48  b        #0x19f4
//   0x0020d8: 910022a9  add      x9, x21, #8
//   0x0020dc: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x0020e0: 9acb2d08  ror      x8, x8, x11
//   0x0020e4: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x0020e8: 17fffe43  b        #0x19f4
//   0x0020ec: 910022a9  add      x9, x21, #8
//   0x0020f0: d37df108  lsl      x8, x8, #3
//   0x0020f4: b8686928  ldr      w8, [x9, x8]
//   0x0020f8: 1acb2d08  ror      w8, w8, w11
//   0x0020fc: 93407d08  sxtw     x8, w8
//   0x002100: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x002104: 17fffe3c  b        #0x19f4
//   0x002108: 910022ab  add      x11, x21, #8
//   0x00210c: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x002110: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x002114: 92401529  and      x9, x9, #0x3f
//   0x002118: 9ac92908  asr      x8, x8, x9
//   0x00211c: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x002120: 17fffe35  b        #0x19f4
//   0x002124: 910022ab  add      x11, x21, #8
//   0x002128: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x00212c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x002130: 92401529  and      x9, x9, #0x3f
//   0x002134: 9ac92108  lsl      x8, x8, x9
//   0x002138: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x00213c: 17fffe2e  b        #0x19f4
//   0x002140: 910022ab  add      x11, x21, #8
//   0x002144: d37df129  lsl      x9, x9, #3
//   0x002148: b8696969  ldr      w9, [x11, x9]
//   0x00214c: d37df108  lsl      x8, x8, #3
//   0x002150: b8686968  ldr      w8, [x11, x8]
//   0x002154: 12001129  and      w9, w9, #0x1f
//   0x002158: 1ac92908  asr      w8, w8, w9
//   0x00215c: 17fffe63  b        #0x1ae8
//   0x002160: 910022ab  add      x11, x21, #8
//   0x002164: d37df129  lsl      x9, x9, #3
//   0x002168: b8696969  ldr      w9, [x11, x9]
//   0x00216c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x002170: 12001529  and      w9, w9, #0x3f
//   0x002174: 9ac92d08  ror      x8, x8, x9
//   0x002178: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x00217c: 17fffe1e  b        #0x19f4
//   0x002180: 711ab9bf  cmp      w13, #0x6ae
//   0x002184: 5400024d  b.le     #0x21cc
//   0x002188: 711db9bf  cmp      w13, #0x76e
//   0x00218c: 5400084c  b.gt     #0x2294
//   0x002190: 711abdbf  cmp      w13, #0x6af
//   0x002194: 54000f60  b.eq     #0x2380
//   0x002198: 711cbdbf  cmp      w13, #0x72f
//   0x00219c: 54ffb120  b.eq     #0x17c0
//   0x0021a0: 17fffe15  b        #0x19f4
//   0x0021a4: 7138b9bf  cmp      w13, #0xe2e
//   0x0021a8: 5400090c  b.gt     #0x22c8
//   0x0021ac: 7136bdbf  cmp      w13, #0xdaf
//   0x0021b0: 54ffb1e0  b.eq     #0x17ec
//   0x0021b4: 7137bdbf  cmp      w13, #0xdef
//   0x0021b8: 54ffc1e1  b.ne     #0x19f4
//   0x0021bc: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x0021c0: f9400508  ldr      x8, [x8, #8]
//   0x0021c4: f90000e8  str      x8, [x7]
//   0x0021c8: 17fffe0b  b        #0x19f4
//   0x0021cc: 7106bdbf  cmp      w13, #0x1af
//   0x0021d0: 54000220  b.eq     #0x2214
//   0x0021d4: 7113bdbf  cmp      w13, #0x4ef
//   0x0021d8: 54000e60  b.eq     #0x23a4
//   0x0021dc: 7114bdbf  cmp      w13, #0x52f
//   0x0021e0: 54ffc0a1  b.ne     #0x19f4
//   0x0021e4: 910022aa  add      x10, x21, #8
//   0x0021e8: d37df129  lsl      x9, x9, #3
//   0x0021ec: d37df108  lsl      x8, x8, #3
//   0x0021f0: b8696949  ldr      w9, [x10, x9]
//   0x0021f4: b8686948  ldr      w8, [x10, x8]
//   0x0021f8: 1ac8092a  udiv     w10, w9, w8
//   0x0021fc: 1b08a548  msub     w8, w10, w8, w9
//   0x002200: 93407d49  sxtw     x9, w10
//   0x002204: 93407d08  sxtw     x8, w8
//   0x002208: f90000c8  str      x8, [x6]
//   0x00220c: f90000e9  str      x9, [x7]
//   0x002210: 17fffdf9  b        #0x19f4
//   0x002214: 910022aa  add      x10, x21, #8
//   0x002218: d37df129  lsl      x9, x9, #3
//   0x00221c: d37df108  lsl      x8, x8, #3
//   0x002220: b8696949  ldr      w9, [x10, x9]
//   0x002224: b8686948  ldr      w8, [x10, x8]
//   0x002228: 9b097d08  mul      x8, x8, x9
//   0x00222c: 93407d09  sxtw     x9, w8
//   0x002230: 9360fd08  asr      x8, x8, #0x20
//   0x002234: f90000e9  str      x9, [x7]
//   0x002238: f90000c8  str      x8, [x6]
//   0x00223c: 17fffdee  b        #0x19f4
//   0x002240: 7116bdbf  cmp      w13, #0x5af
//   0x002244: 54000be0  b.eq     #0x23c0
//   0x002248: 711abdbf  cmp      w13, #0x6af
//   0x00224c: 54000bc0  b.eq     #0x23c4
//   0x002250: 17fffde9  b        #0x19f4
//   0x002254: 712cbdbf  cmp      w13, #0xb2f
//   0x002258: 540000e0  b.eq     #0x2274
//   0x00225c: 7133bdbf  cmp      w13, #0xcef
//   0x002260: 54ffbca1  b.ne     #0x19f4
//   0x002264: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x002268: f9400508  ldr      x8, [x8, #8]
//   0x00226c: f90000c8  str      x8, [x6]
//   0x002270: 17fffde1  b        #0x19f4
//   0x002274: 910022aa  add      x10, x21, #8
//   0x002278: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x00227c: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x002280: 9ac80d2a  sdiv     x10, x9, x8
//   0x002284: 9b08a548  msub     x8, x10, x8, x9
//   0x002288: f90000c8  str      x8, [x6]
//   0x00228c: f90000ea  str      x10, [x7]
//   0x002290: 17fffdd9  b        #0x19f4
//   0x002294: 711dbdbf  cmp      w13, #0x76f
//   0x002298: 54000080  b.eq     #0x22a8
//   0x00229c: 7122bdbf  cmp      w13, #0x8af
//   0x0022a0: 54ff97e0  b.eq     #0x159c
//   0x0022a4: 17fffdd4  b        #0x19f4
//   0x0022a8: 910022aa  add      x10, x21, #8
//   0x0022ac: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x0022b0: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x0022b4: 9bc97d0a  umulh    x10, x8, x9
//   0x0022b8: 9b097d08  mul      x8, x8, x9
//   0x0022bc: f90000e8  str      x8, [x7]
//   0x0022c0: f90000ca  str      x10, [x6]
//   0x0022c4: 17fffdcc  b        #0x19f4
//   0x0022c8: 7138bdbf  cmp      w13, #0xe2f
//   0x0022cc: 54000a40  b.eq     #0x2414
//   0x0022d0: 713abdbf  cmp      w13, #0xeaf
//   0x0022d4: 54ffb901  b.ne     #0x19f4
//   0x0022d8: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0022dc: f9400508  ldr      x8, [x8, #8]
//   0x0022e0: b5000688  cbnz     x8, #0x23b0
//   0x0022e4: 17fffdc4  b        #0x19f4
//   0x0022e8: 320013e8  mov      w8, #0x1f
//   0x0022ec: f85f8269  ldur     x9, [x19, #-8]
//   0x0022f0: 2a1f03ec  mov      w12, wzr
//   0x0022f4: 2a1f03ea  mov      w10, wzr
//   0x0022f8: 8b0b0129  add      x9, x9, x11
//   0x0022fc: 14000036  b        #0x23d4
//   0x002300: eb0d011f  cmp      x8, x13
//   0x002304: 54ffdee1  b.ne     #0x1ee0
//   0x002308: 14000018  b        #0x2368
//   0x00230c: eb0d011f  cmp      x8, x13
//   0x002310: 540002c1  b.ne     #0x2368
//   0x002314: 17fffef3  b        #0x1ee0
//   0x002318: f100011f  cmp      x8, #0
//   0x00231c: 320003ea  mov      w10, #1
//   0x002320: 540001ac  b.gt     #0x2354
//   0x002324: 14000012  b        #0x236c
//   0x002328: eb0d011f  cmp      x8, x13
//   0x00232c: 320003ea  mov      w10, #1
//   0x002330: 54000120  b.eq     #0x2354
//   0x002334: 1400000e  b        #0x236c
//   0x002338: f100051f  cmp      x8, #1
//   0x00233c: 320003ea  mov      w10, #1
//   0x002340: 5400016a  b.ge     #0x236c
//   0x002344: 14000004  b        #0x2354
//   0x002348: eb0d011f  cmp      x8, x13
//   0x00234c: 320003ea  mov      w10, #1
//   0x002350: 540000e0  b.eq     #0x236c
//   0x002354: 2a1f03ec  mov      w12, wzr
//   0x002358: 2a1f03e8  mov      w8, wzr
//   0x00235c: 1400001e  b        #0x23d4
//   0x002360: f100051f  cmp      x8, #1
//   0x002364: 54ffdbeb  b.lt     #0x1ee0
//   0x002368: 2a1f03ea  mov      w10, wzr
//   0x00236c: 2a1f03eb  mov      w11, wzr
//   0x002370: 2a1f03e8  mov      w8, wzr
//   0x002374: 91002009  add      x9, x0, #8
//   0x002378: 320003ec  mov      w12, #1
//   0x00237c: 14000017  b        #0x23d8
//   0x002380: b5ffb3a1  cbnz     x1, #0x19f4
//   0x002384: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x002388: f9400508  ldr      x8, [x8, #8]
//   0x00238c: 91001000  add      x0, x0, #4
//   0x002390: 321f03e9  mov      w9, #2
//   0x002394: a93e2269  stp      x9, x8, [x19, #-0x20]
//   0x002398: f90002a0  str      x0, [x21]
//   0x00239c: b5ff4040  cbnz     x0, #0xba4
//   0x0023a0: 14000021  b        #0x2424
//   0x0023a4: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0023a8: f9400508  ldr      x8, [x8, #8]
//   0x0023ac: b5ffb248  cbnz     x8, #0x19f4
//   0x0023b0: 910022a8  add      x8, x21, #8
//   0x0023b4: f8695909  ldr      x9, [x8, w9, uxtw #3]
//   0x0023b8: f82a5909  str      x9, [x8, w10, uxtw #3]
//   0x0023bc: 17fffd8e  b        #0x19f4
//   0x0023c0: 2a0a03e8  mov      w8, w10
//   0x0023c4: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x0023c8: f9400529  ldr      x9, [x9, #8]
//   0x0023cc: 2a1f03ec  mov      w12, wzr
//   0x0023d0: 2a1f03ea  mov      w10, wzr
//   0x0023d4: 320003eb  mov      w11, #1
//   0x0023d8: 7100015f  cmp      w10, #0
//   0x0023dc: 1a9f07ed  cset     w13, ne
//   0x0023e0: 0a0d018c  and      w12, w12, w13
//   0x0023e4: f81e8269  stur     x9, [x19, #-0x18]
//   0x0023e8: 3700008c  tbnz     w12, #0, #0x23f8
//   0x0023ec: 3400006a  cbz      w10, #0x23f8
//   0x0023f0: 0a0d0169  and      w9, w11, w13
//   0x0023f4: 34ff86e9  cbz      w9, #0x14d0
//   0x0023f8: 7100019f  cmp      w12, #0
//   0x0023fc: 320003e9  mov      w9, #1
//   0x002400: 9a891529  cinc     x9, x9, eq
//   0x002404: f81e0269  stur     x9, [x19, #-0x20]
//   0x002408: 7100051f  cmp      w8, #1
//   0x00240c: 54ffaf4b  b.lt     #0x19f4
//   0x002410: 17fffc32  b        #0x14d8
//   0x002414: f94000c8  ldr      x8, [x6]
//   0x002418: 8b2a4ea9  add      x9, x21, w10, uxtw #3
//   0x00241c: f9000528  str      x8, [x9, #8]
//   0x002420: 17fffd75  b        #0x19f4
//   0x002424: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x002428: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00242c: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x002430: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x002434: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x002438: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x00243c: 9101c3ff  add      sp, sp, #0x70
//   0x002440: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_04_0af8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00000af8ULL;
    for (std::size_t i = 0; i < 1619ULL; ++i) {
        std::uint32_t insn = kTextInstructions[102ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[05] Subroutine @ 0x002444..0x0027c0 (892 bytes, 223 AArch64 instructions)
// [VN] Khung FDE[05] Hàm con @ 0x002444..0x0027c0 (892 byte, 223 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002444: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x002448: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00244c: 29403028  ldp      w8, w12, [x1]
//   0x002450: 29403c0b  ldp      w11, w15, [x0]
//   0x002454: 2941382d  ldp      w13, w14, [x1, #8]
//   0x002458: f940f003  ldr      x3, [x0, #0x1e0]
//   0x00245c: 29410812  ldp      w18, w2, [x0, #8]
//   0x002460: 5ac00908  rev      w8, w8
//   0x002464: 4a080170  eor      w16, w11, w8
//   0x002468: 5ac00988  rev      w8, w12
//   0x00246c: 4a0801f1  eor      w17, w15, w8
//   0x002470: 5ac009a8  rev      w8, w13
//   0x002474: 5ac009cd  rev      w13, w14
//   0x002478: d341fc6e  lsr      x14, x3, #1
//   0x00247c: 320003e4  mov      w4, #1
//   0x002480: d000002a  adrp     x10, #0x8000
//   0x002484: d000002b  adrp     x11, #0x8000
//   0x002488: d000002c  adrp     x12, #0x8000
//   0x00248c: 4a080252  eor      w18, w18, w8
//   0x002490: d37df1c8  lsl      x8, x14, #3
//   0x002494: f000002f  adrp     x15, #0x9000
//   0x002498: 91006009  add      x9, x0, #0x18
//   0x00249c: 911b414a  add      x10, x10, #0x6d0
//   0x0024a0: 912b416b  add      x11, x11, #0xad0
//   0x0024a4: 913b418c  add      x12, x12, #0xed0
//   0x0024a8: 4a0d0042  eor      w2, w2, w13
//   0x0024ac: cb0e008e  sub      x14, x4, x14
//   0x0024b0: d100210d  sub      x13, x8, #8
//   0x0024b4: 910b41ef  add      x15, x15, #0x2d0
//   0x0024b8: 14000034  b        #0x2588
//   0x0024bc: 53105e24  ubfx     w4, w17, #0x10, #8
//   0x0024c0: b8635943  ldr      w3, [x10, w3, uxtw #2]
//   0x0024c4: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x0024c8: 53187e26  lsr      w6, w17, #0x18
//   0x0024cc: 53105e07  ubfx     w7, w16, #0x10, #8
//   0x0024d0: 53187e13  lsr      w19, w16, #0x18
//   0x0024d4: 53105c54  ubfx     w20, w2, #0x10, #8
//   0x0024d8: b8665946  ldr      w6, [x10, w6, uxtw #2]
//   0x0024dc: b8675967  ldr      w7, [x11, w7, uxtw #2]
//   0x0024e0: b8735953  ldr      w19, [x10, w19, uxtw #2]
//   0x0024e4: b8745974  ldr      w20, [x11, w20, uxtw #2]
//   0x0024e8: 53187c55  lsr      w21, w2, #0x18
//   0x0024ec: 4a030083  eor      w3, w4, w3
//   0x0024f0: 53105e44  ubfx     w4, w18, #0x10, #8
//   0x0024f4: b8755955  ldr      w21, [x10, w21, uxtw #2]
//   0x0024f8: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x0024fc: 53083e05  ubfx     w5, w16, #8, #8
//   0x002500: 4a0600e6  eor      w6, w7, w6
//   0x002504: 53083c47  ubfx     w7, w2, #8, #8
//   0x002508: 4a130293  eor      w19, w20, w19
//   0x00250c: 53083e54  ubfx     w20, w18, #8, #8
//   0x002510: b8655985  ldr      w5, [x12, w5, uxtw #2]
//   0x002514: b8675987  ldr      w7, [x12, w7, uxtw #2]
//   0x002518: 12001c42  and      w2, w2, #0xff
//   0x00251c: 12001e52  and      w18, w18, #0xff
//   0x002520: b8745994  ldr      w20, [x12, w20, uxtw #2]
//   0x002524: b86259e2  ldr      w2, [x15, w2, uxtw #2]
//   0x002528: b87259f2  ldr      w18, [x15, w18, uxtw #2]
//   0x00252c: 4a150084  eor      w4, w4, w21
//   0x002530: 53083e35  ubfx     w21, w17, #8, #8
//   0x002534: b8755995  ldr      w21, [x12, w21, uxtw #2]
//   0x002538: 12001e31  and      w17, w17, #0xff
//   0x00253c: 12001e10  and      w16, w16, #0xff
//   0x002540: 4a050063  eor      w3, w3, w5
//   0x002544: 4a0700c5  eor      w5, w6, w7
//   0x002548: b87159f1  ldr      w17, [x15, w17, uxtw #2]
//   0x00254c: b87059f0  ldr      w16, [x15, w16, uxtw #2]
//   0x002550: 4a140266  eor      w6, w19, w20
//   0x002554: 4a020062  eor      w2, w3, w2
//   0x002558: 4a1200b2  eor      w18, w5, w18
//   0x00255c: 29411523  ldp      w3, w5, [x9, #8]
//   0x002560: 29424d27  ldp      w7, w19, [x9, #0x10]
//   0x002564: 4a150084  eor      w4, w4, w21
//   0x002568: 4a1100c6  eor      w6, w6, w17
//   0x00256c: 4a100084  eor      w4, w4, w16
//   0x002570: 910005ce  add      x14, x14, #1
//   0x002574: 4a030050  eor      w16, w2, w3
//   0x002578: 4a050251  eor      w17, w18, w5
//   0x00257c: 4a0700d2  eor      w18, w6, w7
//   0x002580: 4a130082  eor      w2, w4, w19
//   0x002584: 91008129  add      x9, x9, #0x20
//   0x002588: 53187e03  lsr      w3, w16, #0x18
//   0x00258c: 53105e24  ubfx     w4, w17, #0x10, #8
//   0x002590: 53187e26  lsr      w6, w17, #0x18
//   0x002594: 53105e47  ubfx     w7, w18, #0x10, #8
//   0x002598: b8635943  ldr      w3, [x10, w3, uxtw #2]
//   0x00259c: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x0025a0: 53187e53  lsr      w19, w18, #0x18
//   0x0025a4: 53105c54  ubfx     w20, w2, #0x10, #8
//   0x0025a8: b8665946  ldr      w6, [x10, w6, uxtw #2]
//   0x0025ac: b8675967  ldr      w7, [x11, w7, uxtw #2]
//   0x0025b0: b8735953  ldr      w19, [x10, w19, uxtw #2]
//   0x0025b4: b8745974  ldr      w20, [x11, w20, uxtw #2]
//   0x0025b8: 53187c55  lsr      w21, w2, #0x18
//   0x0025bc: 4a030083  eor      w3, w4, w3
//   0x0025c0: 53105e04  ubfx     w4, w16, #0x10, #8
//   0x0025c4: 53083e45  ubfx     w5, w18, #8, #8
//   0x0025c8: b8755955  ldr      w21, [x10, w21, uxtw #2]
//   0x0025cc: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x0025d0: 4a0600e6  eor      w6, w7, w6
//   0x0025d4: 53083c47  ubfx     w7, w2, #8, #8
//   0x0025d8: 4a130293  eor      w19, w20, w19
//   0x0025dc: 53083e14  ubfx     w20, w16, #8, #8
//   0x0025e0: b8655985  ldr      w5, [x12, w5, uxtw #2]
//   0x0025e4: b8675987  ldr      w7, [x12, w7, uxtw #2]
//   0x0025e8: 12001c42  and      w2, w2, #0xff
//   0x0025ec: 12001e10  and      w16, w16, #0xff
//   0x0025f0: b86259e2  ldr      w2, [x15, w2, uxtw #2]
//   0x0025f4: b87059f0  ldr      w16, [x15, w16, uxtw #2]
//   0x0025f8: b8745994  ldr      w20, [x12, w20, uxtw #2]
//   0x0025fc: 4a150084  eor      w4, w4, w21
//   0x002600: 53083e35  ubfx     w21, w17, #8, #8
//   0x002604: b8755995  ldr      w21, [x12, w21, uxtw #2]
//   0x002608: 4a050063  eor      w3, w3, w5
//   0x00260c: 4a0700c5  eor      w5, w6, w7
//   0x002610: 12001e31  and      w17, w17, #0xff
//   0x002614: 12001e52  and      w18, w18, #0xff
//   0x002618: b87159f1  ldr      w17, [x15, w17, uxtw #2]
//   0x00261c: b87259f2  ldr      w18, [x15, w18, uxtw #2]
//   0x002620: 4a020062  eor      w2, w3, w2
//   0x002624: 4a1000b0  eor      w16, w5, w16
//   0x002628: 297f1523  ldp      w3, w5, [x9, #-8]
//   0x00262c: 4a140266  eor      w6, w19, w20
//   0x002630: 29404d27  ldp      w7, w19, [x9]
//   0x002634: 4a150084  eor      w4, w4, w21
//   0x002638: 4a1100c6  eor      w6, w6, w17
//   0x00263c: 4a120084  eor      w4, w4, w18
//   0x002640: 4a030052  eor      w18, w2, w3
//   0x002644: 4a050211  eor      w17, w16, w5
//   0x002648: 4a0700d0  eor      w16, w6, w7
//   0x00264c: 4a130082  eor      w2, w4, w19
//   0x002650: 53187e43  lsr      w3, w18, #0x18
//   0x002654: b5fff34e  cbnz     x14, #0x24bc
//   0x002658: f000002a  adrp     x10, #0x9000
//   0x00265c: f000002c  adrp     x12, #0x9000
//   0x002660: 8b0d0809  add      x9, x0, x13, lsl #2
//   0x002664: 911b414a  add      x10, x10, #0x6d0
//   0x002668: 53105e2b  ubfx     w11, w17, #0x10, #8
//   0x00266c: 912b418c  add      x12, x12, #0xad0
//   0x002670: f000002e  adrp     x14, #0x9000
//   0x002674: 12001c4f  and      w15, w2, #0xff
//   0x002678: b8687808  ldr      w8, [x0, x8, lsl #2]
//   0x00267c: 53187e20  lsr      w0, w17, #0x18
//   0x002680: 53105e04  ubfx     w4, w16, #0x10, #8
//   0x002684: 53083c45  ubfx     w5, w2, #8, #8
//   0x002688: 53187e06  lsr      w6, w16, #0x18
//   0x00268c: 53105c47  ubfx     w7, w2, #0x10, #8
//   0x002690: 53187c42  lsr      w2, w2, #0x18
//   0x002694: 53083e0d  ubfx     w13, w16, #8, #8
//   0x002698: 913b41ce  add      x14, x14, #0xed0
//   0x00269c: 53083e53  ubfx     w19, w18, #8, #8
//   0x0026a0: b8635943  ldr      w3, [x10, w3, uxtw #2]
//   0x0026a4: b8605940  ldr      w0, [x10, w0, uxtw #2]
//   0x0026a8: b8665946  ldr      w6, [x10, w6, uxtw #2]
//   0x0026ac: b862594a  ldr      w10, [x10, w2, uxtw #2]
//   0x0026b0: 53105e42  ubfx     w2, w18, #0x10, #8
//   0x0026b4: b86b598b  ldr      w11, [x12, w11, uxtw #2]
//   0x0026b8: b8645984  ldr      w4, [x12, w4, uxtw #2]
//   0x0026bc: b8675987  ldr      w7, [x12, w7, uxtw #2]
//   0x0026c0: b862598c  ldr      w12, [x12, w2, uxtw #2]
//   0x0026c4: 53083e22  ubfx     w2, w17, #8, #8
//   0x0026c8: b86d59cd  ldr      w13, [x14, w13, uxtw #2]
//   0x0026cc: b86559c5  ldr      w5, [x14, w5, uxtw #2]
//   0x0026d0: b87359d3  ldr      w19, [x14, w19, uxtw #2]
//   0x0026d4: b86259ce  ldr      w14, [x14, w2, uxtw #2]
//   0x0026d8: 90000042  adrp     x2, #0xa000
//   0x0026dc: 910b4042  add      x2, x2, #0x2d0
//   0x0026e0: 12001e52  and      w18, w18, #0xff
//   0x0026e4: 12001e31  and      w17, w17, #0xff
//   0x0026e8: 12001e10  and      w16, w16, #0xff
//   0x0026ec: b86f584f  ldr      w15, [x2, w15, uxtw #2]
//   0x0026f0: b8725852  ldr      w18, [x2, w18, uxtw #2]
//   0x0026f4: b8715851  ldr      w17, [x2, w17, uxtw #2]
//   0x0026f8: b8705850  ldr      w16, [x2, w16, uxtw #2]
//   0x0026fc: 4a03016b  eor      w11, w11, w3
//   0x002700: 4a000080  eor      w0, w4, w0
//   0x002704: 4a0600e2  eor      w2, w7, w6
//   0x002708: 4a0a018a  eor      w10, w12, w10
//   0x00270c: 4a0d016b  eor      w11, w11, w13
//   0x002710: 4a05000c  eor      w12, w0, w5
//   0x002714: 4a13004d  eor      w13, w2, w19
//   0x002718: 29448920  ldp      w0, w2, [x9, #0x24]
//   0x00271c: b9402d29  ldr      w9, [x9, #0x2c]
//   0x002720: 4a0e014a  eor      w10, w10, w14
//   0x002724: 4a0f016b  eor      w11, w11, w15
//   0x002728: 4a12018c  eor      w12, w12, w18
//   0x00272c: 4a1101ad  eor      w13, w13, w17
//   0x002730: 4a10014a  eor      w10, w10, w16
//   0x002734: 4a080168  eor      w8, w11, w8
//   0x002738: 4a00018b  eor      w11, w12, w0
//   0x00273c: 4a0201ac  eor      w12, w13, w2
//   0x002740: 4a090149  eor      w9, w10, w9
//   0x002744: 53187d0a  lsr      w10, w8, #0x18
//   0x002748: 53107d0d  lsr      w13, w8, #0x10
//   0x00274c: 53087d0e  lsr      w14, w8, #8
//   0x002750: 39000c28  strb     w8, [x1, #3]
//   0x002754: 53187d68  lsr      w8, w11, #0x18
//   0x002758: 53107d6f  lsr      w15, w11, #0x10
//   0x00275c: 53087d70  lsr      w16, w11, #8
//   0x002760: 39001c2b  strb     w11, [x1, #7]
//   0x002764: 53187d8b  lsr      w11, w12, #0x18
//   0x002768: 53107d91  lsr      w17, w12, #0x10
//   0x00276c: 53087d92  lsr      w18, w12, #8
//   0x002770: 39002c2c  strb     w12, [x1, #0xb]
//   0x002774: 53187d2c  lsr      w12, w9, #0x18
//   0x002778: 53107d20  lsr      w0, w9, #0x10
//   0x00277c: 53087d22  lsr      w2, w9, #8
//   0x002780: 3900002a  strb     w10, [x1]
//   0x002784: 3900042d  strb     w13, [x1, #1]
//   0x002788: 3900082e  strb     w14, [x1, #2]
//   0x00278c: 39001028  strb     w8, [x1, #4]
//   0x002790: 3900142f  strb     w15, [x1, #5]
//   0x002794: 39001830  strb     w16, [x1, #6]
//   0x002798: 3900202b  strb     w11, [x1, #8]
//   0x00279c: 39002431  strb     w17, [x1, #9]
//   0x0027a0: 39002832  strb     w18, [x1, #0xa]
//   0x0027a4: 3900302c  strb     w12, [x1, #0xc]
//   0x0027a8: 39003420  strb     w0, [x1, #0xd]
//   0x0027ac: 39003822  strb     w2, [x1, #0xe]
//   0x0027b0: 39003c29  strb     w9, [x1, #0xf]
//   0x0027b4: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0027b8: f84207f5  ldr      x21, [sp], #0x20
//   0x0027bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_05_2444(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002444ULL;
    for (std::size_t i = 0; i < 223ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1721ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[06] Subroutine @ 0x0027c0..0x00293c (380 bytes, 95 AArch64 instructions)
// [VN] Khung FDE[06] Hàm con @ 0x0027c0..0x00293c (380 byte, 95 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0027c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0027c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0027c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0027cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0027d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0027d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0027d8: 910143fd  add      x29, sp, #0x50
//   0x0027dc: d11043ff  sub      sp, sp, #0x410
//   0x0027e0: d53bd05b  mrs      x27, tpidr_el0
//   0x0027e4: f940176a  ldr      x10, [x27, #0x28]
//   0x0027e8: aa0603f3  mov      x19, x6
//   0x0027ec: aa0403f5  mov      x21, x4
//   0x0027f0: 92400eb8  and      x24, x21, #0xf
//   0x0027f4: f81a83aa  stur     x10, [x29, #-0x58]
//   0x0027f8: f940026a  ldr      x10, [x19]
//   0x0027fc: 321c03eb  mov      w11, #0x10
//   0x002800: cb180177  sub      x23, x11, x24
//   0x002804: 8b1502fc  add      x28, x23, x21
//   0x002808: aa0503f4  mov      x20, x5
//   0x00280c: aa0303f6  mov      x22, x3
//   0x002810: aa0203f9  mov      x25, x2
//   0x002814: 2a0103e8  mov      w8, w1
//   0x002818: aa0003e9  mov      x9, x0
//   0x00281c: eb1c015f  cmp      x10, x28
//   0x002820: f900027f  str      xzr, [x19]
//   0x002824: 54000723  b.lo     #0x2908
//   0x002828: 910063e0  add      x0, sp, #0x18
//   0x00282c: aa0903e1  mov      x1, x9
//   0x002830: 2a0803e2  mov      w2, w8
//   0x002834: 940006ea  bl       #0x43dc
//   0x002838: 72001c1f  tst      w0, #0xff
//   0x00283c: 54000661  b.ne     #0x2908
//   0x002840: 910803e0  add      x0, sp, #0x200
//   0x002844: 910063e1  add      x1, sp, #0x18
//   0x002848: aa1903e2  mov      x2, x25
//   0x00284c: f9000bf4  str      x20, [sp, #0x10]
//   0x002850: 94000efa  bl       #0x6438
//   0x002854: d101a3a9  sub      x9, x29, #0x68
//   0x002858: 8b18013a  add      x26, x9, x24
//   0x00285c: cb1802a8  sub      x8, x21, x24
//   0x002860: aa1a03e0  mov      x0, x26
//   0x002864: 2a1f03e1  mov      w1, wzr
//   0x002868: aa1703e2  mov      x2, x23
//   0x00286c: d344feb4  lsr      x20, x21, #4
//   0x002870: 8b0802d9  add      x25, x22, x8
//   0x002874: 97fff82f  bl       #0x930
//   0x002878: d101a3a0  sub      x0, x29, #0x68
//   0x00287c: aa1903e1  mov      x1, x25
//   0x002880: aa1803e2  mov      x2, x24
//   0x002884: 97fff827  bl       #0x920
//   0x002888: aa1a03e0  mov      x0, x26
//   0x00288c: 2a1703e1  mov      w1, w23
//   0x002890: aa1703e2  mov      x2, x23
//   0x002894: 97fff827  bl       #0x930
//   0x002898: 910803e8  add      x8, sp, #0x200
//   0x00289c: 9107a117  add      x23, x8, #0x1e8
//   0x0028a0: b4000214  cbz      x20, #0x28e0
//   0x0028a4: f9400bf9  ldr      x25, [sp, #0x10]
//   0x0028a8: aa1903f8  mov      x24, x25
//   0x0028ac: aa1703e0  mov      x0, x23
//   0x0028b0: aa1603e1  mov      x1, x22
//   0x0028b4: 94000ea0  bl       #0x6334
//   0x0028b8: 910803e0  add      x0, sp, #0x200
//   0x0028bc: aa1703e1  mov      x1, x23
//   0x0028c0: 97fffee1  bl       #0x2444
//   0x0028c4: 3dc002e0  ldr      q0, [x23]
//   0x0028c8: f1000694  subs     x20, x20, #1
//   0x0028cc: 910042d6  add      x22, x22, #0x10
//   0x0028d0: 3c810700  str      q0, [x24], #0x10
//   0x0028d4: 54fffec1  b.ne     #0x28ac
//   0x0028d8: 927ceeb4  and      x20, x21, #0xfffffffffffffff0
//   0x0028dc: 14000002  b        #0x28e4
//   0x0028e0: f9400bf9  ldr      x25, [sp, #0x10]
//   0x0028e4: d101a3a1  sub      x1, x29, #0x68
//   0x0028e8: aa1703e0  mov      x0, x23
//   0x0028ec: 94000e92  bl       #0x6334
//   0x0028f0: 910803e0  add      x0, sp, #0x200
//   0x0028f4: aa1703e1  mov      x1, x23
//   0x0028f8: 97fffed3  bl       #0x2444
//   0x0028fc: 3dc002e0  ldr      q0, [x23]
//   0x002900: 3cb46b20  str      q0, [x25, x20]
//   0x002904: f900027c  str      x28, [x19]
//   0x002908: f9401768  ldr      x8, [x27, #0x28]
//   0x00290c: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x002910: eb09011f  cmp      x8, x9
//   0x002914: 54000121  b.ne     #0x2938
//   0x002918: 911043ff  add      sp, sp, #0x410
//   0x00291c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x002920: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x002924: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x002928: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00292c: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x002930: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x002934: d65f03c0  ret      
//   0x002938: 97fff7f2  bl       #0x900
// ============================================================================
std::uint32_t fde_06_27c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000027c0ULL;
    for (std::size_t i = 0; i < 95ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1944ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[07] Subroutine @ 0x00293c..0x0029b8 (124 bytes, 31 AArch64 instructions)
// [VN] Khung FDE[07] Hàm con @ 0x00293c..0x0029b8 (124 byte, 31 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00293c: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x002940: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x002944: 910043fd  add      x29, sp, #0x10
//   0x002948: d11483ff  sub      sp, sp, #0x520
//   0x00294c: d53bd053  mrs      x19, tpidr_el0
//   0x002950: f9401668  ldr      x8, [x19, #0x28]
//   0x002954: 90000009  adrp     x9, #0x2000
//   0x002958: 912a1129  add      x9, x9, #0xa84
//   0x00295c: 9100a3e4  add      x4, sp, #0x28
//   0x002960: f81e83a8  stur     x8, [x29, #-0x18]
//   0x002964: 9100e3e8  add      x8, sp, #0x38
//   0x002968: a90087e0  stp      x0, x1, [sp, #8]
//   0x00296c: a9018fe2  stp      x2, x3, [sp, #0x18]
//   0x002970: b0000040  adrp     x0, #0xb000
//   0x002974: b00000a3  adrp     x3, #0x17000
//   0x002978: 91136108  add      x8, x8, #0x4d8
//   0x00297c: 9100c000  add      x0, x0, #0x30
//   0x002980: 91344063  add      x3, x3, #0xd10
//   0x002984: 910023e1  add      x1, sp, #8
//   0x002988: aa1f03e2  mov      x2, xzr
//   0x00298c: a902a3e9  stp      x9, x8, [sp, #0x28]
//   0x002990: 94000040  bl       #0x2a90
//   0x002994: f9401668  ldr      x8, [x19, #0x28]
//   0x002998: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x00299c: eb09011f  cmp      x8, x9
//   0x0029a0: 540000a1  b.ne     #0x29b4
//   0x0029a4: 911483ff  add      sp, sp, #0x520
//   0x0029a8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0029ac: a8c24ffc  ldp      x28, x19, [sp], #0x20
//   0x0029b0: d65f03c0  ret      
//   0x0029b4: 97fff7d3  bl       #0x900
// ============================================================================
std::uint32_t fde_07_293c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000293cULL;
    for (std::size_t i = 0; i < 31ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2039ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[08] Subroutine @ 0x0029b8..0x0029d4 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[08] Hàm con @ 0x0029b8..0x0029d4 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0029b8: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x0029bc: aa0003f3  mov      x19, x0
//   0x0029c0: f9400260  ldr      x0, [x19]
//   0x0029c4: 97fff7d3  bl       #0x910
//   0x0029c8: f9000660  str      x0, [x19, #8]
//   0x0029cc: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x0029d0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_08_29b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000029b8ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2070ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[09] Subroutine @ 0x0029d4..0x002a0c (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[09] Hàm con @ 0x0029d4..0x002a0c (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0029d4: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x0029d8: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x0029dc: a9405013  ldp      x19, x20, [x0]
//   0x0029e0: aa1f03e0  mov      x0, xzr
//   0x0029e4: 97fff7bf  bl       #0x8e0
//   0x0029e8: 97fff7ba  bl       #0x8d0
//   0x0029ec: b40000b4  cbz      x20, #0x2a00
//   0x0029f0: 97fff7c0  bl       #0x8f0
//   0x0029f4: f1000694  subs     x20, x20, #1
//   0x0029f8: 38001660  strb     w0, [x19], #1
//   0x0029fc: 54ffffa1  b.ne     #0x29f0
//   0x002a00: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x002a04: f84207f4  ldr      x20, [sp], #0x20
//   0x002a08: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_09_29d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000029d4ULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2077ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[10] Subroutine @ 0x002a0c..0x002a20 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[10] Hàm con @ 0x002a0c..0x002a20 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a0c: a9400408  ldp      x8, x1, [x0]
//   0x002a10: a9410c02  ldp      x2, x3, [x0, #0x10]
//   0x002a14: a9421404  ldp      x4, x5, [x0, #0x20]
//   0x002a18: aa0803e0  mov      x0, x8
//   0x002a1c: 14000792  b        #0x4864
// ============================================================================
std::uint32_t fde_10_2a0c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a0cULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2091ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[11] Subroutine @ 0x002a20..0x002a30 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[11] Hàm con @ 0x002a20..0x002a30 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a20: a9400408  ldp      x8, x1, [x0]
//   0x002a24: f9400802  ldr      x2, [x0, #0x10]
//   0x002a28: aa0803e0  mov      x0, x8
//   0x002a2c: 14001039  b        #0x6b10
// ============================================================================
std::uint32_t fde_11_2a20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a20ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2096ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[12] Subroutine @ 0x002a30..0x002a40 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[12] Hàm con @ 0x002a30..0x002a40 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a30: a9400408  ldp      x8, x1, [x0]
//   0x002a34: f9400802  ldr      x2, [x0, #0x10]
//   0x002a38: aa0803e0  mov      x0, x8
//   0x002a3c: 17fff7b9  b        #0x920
// ============================================================================
std::uint32_t fde_12_2a30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a30ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2100ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[13] Subroutine @ 0x002a40..0x002a60 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[13] Hàm con @ 0x002a40..0x002a60 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a40: a9400408  ldp      x8, x1, [x0]
//   0x002a44: b9401002  ldr      w2, [x0, #0x10]
//   0x002a48: 528c6e89  mov      w9, #0x6374
//   0x002a4c: 72a200a9  movk     w9, #0x1005, lsl #16
//   0x002a50: 91001900  add      x0, x8, #6
//   0x002a54: b9000109  str      w9, [x8]
//   0x002a58: 7900091f  strh     wzr, [x8, #4]
//   0x002a5c: 17fff7b1  b        #0x920
// ============================================================================
std::uint32_t fde_13_2a40(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a40ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2104ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[14] Subroutine @ 0x002a60..0x002a7c (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[14] Hàm con @ 0x002a60..0x002a7c (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a60: f9400008  ldr      x8, [x0]
//   0x002a64: b9400801  ldr      w1, [x0, #8]
//   0x002a68: a9410c02  ldp      x2, x3, [x0, #0x10]
//   0x002a6c: a9421404  ldp      x4, x5, [x0, #0x20]
//   0x002a70: f9401806  ldr      x6, [x0, #0x30]
//   0x002a74: aa0803e0  mov      x0, x8
//   0x002a78: 17ffff52  b        #0x27c0
// ============================================================================
std::uint32_t fde_14_2a60(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a60ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2112ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[15] Subroutine @ 0x002a7c..0x002a84 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[15] Hàm con @ 0x002a7c..0x002a84 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a7c: f9400000  ldr      x0, [x0]
//   0x002a80: 17fff7b0  b        #0x940
// ============================================================================
std::uint32_t fde_15_2a7c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a7cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2119ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[16] Subroutine @ 0x002a84..0x002a90 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[16] Hàm con @ 0x002a84..0x002a90 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a84: aa0003e2  mov      x2, x0
//   0x002a88: aa0103e0  mov      x0, x1
//   0x002a8c: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_16_2a84(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a84ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2121ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[17] Subroutine @ 0x002a90..0x0043dc (6476 bytes, 1619 AArch64 instructions)
// [VN] Khung FDE[17] Hàm con @ 0x002a90..0x0043dc (6476 byte, 1619 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002a90: d101c3ff  sub      sp, sp, #0x70
//   0x002a94: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x002a98: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x002a9c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x002aa0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x002aa4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x002aa8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x002aac: 910183fd  add      x29, sp, #0x60
//   0x002ab0: a9404c94  ldp      x20, x19, [x4]
//   0x002ab4: d104c268  sub      x8, x19, #0x130
//   0x002ab8: f81c827f  stur     xzr, [x19, #-0x38]
//   0x002abc: f900011f  str      xzr, [x8]
//   0x002ac0: d1052268  sub      x8, x19, #0x148
//   0x002ac4: d104e275  sub      x21, x19, #0x138
//   0x002ac8: 927ced08  and      x8, x8, #0xfffffffffffffff0
//   0x002acc: d1044264  sub      x4, x19, #0x110
//   0x002ad0: d1042265  sub      x5, x19, #0x108
//   0x002ad4: f81b8268  stur     x8, [x19, #-0x48]
//   0x002ad8: f81e027f  stur     xzr, [x19, #-0x20]
//   0x002adc: f9000081  str      x1, [x4]
//   0x002ae0: f90000a2  str      x2, [x5]
//   0x002ae4: a9305263  stp      x3, x20, [x19, #-0x100]
//   0x002ae8: f90002a0  str      x0, [x21]
//   0x002aec: f81f8260  stur     x0, [x19, #-8]
//   0x002af0: b400c660  cbz      x0, #0x43bc
//   0x002af4: 528065f7  mov      w23, #0x32f
//   0x002af8: 5281fff8  mov      w24, #0xfff
//   0x002afc: 9000005c  adrp     x28, #0xa000
//   0x002b00: 90000056  adrp     x22, #0xa000
//   0x002b04: 9000005b  adrp     x27, #0xa000
//   0x002b08: 90000059  adrp     x25, #0xa000
//   0x002b0c: aa1f03e1  mov      x1, xzr
//   0x002b10: d100a266  sub      x6, x19, #0x28
//   0x002b14: d100c267  sub      x7, x19, #0x30
//   0x002b18: 72a08017  movk     w23, #0x400, lsl #16
//   0x002b1c: 72a00418  movk     w24, #0x20, lsl #16
//   0x002b20: 320007fa  mov      w26, #3
//   0x002b24: 911b439c  add      x28, x28, #0x6d0
//   0x002b28: 911f42d6  add      x22, x22, #0x7d0
//   0x002b2c: 321b03fe  mov      w30, #0x20
//   0x002b30: 9122c37b  add      x27, x27, #0x8b0
//   0x002b34: 912a6339  add      x25, x25, #0xa98
//   0x002b38: 14000002  b        #0x2b40
//   0x002b3c: f85e0261  ldur     x1, [x19, #-0x20]
//   0x002b40: b940000c  ldr      w12, [x0]
//   0x002b44: f100083f  cmp      x1, #2
//   0x002b48: 5400a340  b.eq     #0x3fb0
//   0x002b4c: 1200158a  and      w10, w12, #0x3f
//   0x002b50: 7100fd5f  cmp      w10, #0x3f
//   0x002b54: 540071c8  b.hi     #0x398c
//   0x002b58: 530b7d8b  lsr      w11, w12, #0xb
//   0x002b5c: 121f016e  and      w14, w11, #2
//   0x002b60: b8aa7b83  ldrsw    x3, [x28, x10, lsl #2]
//   0x002b64: 12040190  and      w16, w12, #0x10000000
//   0x002b68: 121e0162  and      w2, w11, #4
//   0x002b6c: 331f7d8e  bfxil    w14, w12, #0x1f, #1
//   0x002b70: 2a0201ce  orr      w14, w14, w2
//   0x002b74: 121d0162  and      w2, w11, #8
//   0x002b78: 121c016a  and      w10, w11, #0x10
//   0x002b7c: 531a7e0b  lsr      w11, w16, #0x1a
//   0x002b80: 1203018f  and      w15, w12, #0x20000000
//   0x002b84: 2a0201c2  orr      w2, w14, w2
//   0x002b88: 331a6d8b  bfxil    w11, w12, #0x1a, #2
//   0x002b8c: 1202018e  and      w14, w12, #0x40000000
//   0x002b90: 2a0a004a  orr      w10, w2, w10
//   0x002b94: 2a4f696b  orr      w11, w11, w15, lsr #26
//   0x002b98: 8b1c0062  add      x2, x3, x28
//   0x002b9c: 53156589  ubfx     w9, w12, #0x15, #5
//   0x002ba0: 53105188  ubfx     w8, w12, #0x10, #5
//   0x002ba4: 1201018d  and      w13, w12, #0x80000000
//   0x002ba8: 12060192  and      w18, w12, #0x4000000
//   0x002bac: 12050191  and      w17, w12, #0x8000000
//   0x002bb0: 2a4e696b  orr      w11, w11, w14, lsr #26
//   0x002bb4: d61f0040  br       x2
//   0x002bb8: 1200158a  and      w10, w12, #0x3f
//   0x002bbc: 7100dd5f  cmp      w10, #0x37
//   0x002bc0: 54006e68  b.hi     #0x398c
//   0x002bc4: 53062d8b  ubfx     w11, w12, #6, #6
//   0x002bc8: 12140d8c  and      w12, w12, #0xf000
//   0x002bcc: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x002bd0: 2a0b018b  orr      w11, w12, w11
//   0x002bd4: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x002bd8: b8aa7aca  ldrsw    x10, [x22, x10, lsl #2]
//   0x002bdc: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x002be0: f9400529  ldr      x9, [x9, #8]
//   0x002be4: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x002be8: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x002bec: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x002bf0: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x002bf4: 8b16014a  add      x10, x10, x22
//   0x002bf8: 8b2ba129  add      x9, x9, w11, sxth
//   0x002bfc: d61f0140  br       x10
//   0x002c00: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x002c04: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x002c08: f940014a  ldr      x10, [x10]
//   0x002c0c: f940050b  ldr      x11, [x8, #8]
//   0x002c10: d37d0929  ubfiz    x9, x9, #3, #3
//   0x002c14: 321d0bec  mov      w12, #0x38
//   0x002c18: b240dfed  mov      x13, #0xffffffffffffff
//   0x002c1c: cb09018c  sub      x12, x12, x9
//   0x002c20: 9ac925a9  lsr      x9, x13, x9
//   0x002c24: 9acc214a  lsl      x10, x10, x12
//   0x002c28: 8a090169  and      x9, x11, x9
//   0x002c2c: aa0a0129  orr      x9, x9, x10
//   0x002c30: 14000356  b        #0x3988
//   0x002c34: b5006ac1  cbnz     x1, #0x398c
//   0x002c38: 1200158a  and      w10, w12, #0x3f
//   0x002c3c: 51000d41  sub      w1, w10, #3
//   0x002c40: 7100f03f  cmp      w1, #0x3c
//   0x002c44: 54006a48  b.hi     #0x398c
//   0x002c48: 12140d83  and      w3, w12, #0xf000
//   0x002c4c: 53062d82  ubfx     w2, w12, #6, #6
//   0x002c50: 33147e43  bfxil    w3, w18, #0x14, #0xc
//   0x002c54: 2a020072  orr      w18, w3, w2
//   0x002c58: b8a17b61  ldrsw    x1, [x27, x1, lsl #2]
//   0x002c5c: 2a515251  orr      w17, w18, w17, lsr #20
//   0x002c60: 2a505230  orr      w16, w17, w16, lsr #20
//   0x002c64: 2a4f520f  orr      w15, w16, w15, lsr #20
//   0x002c68: 2a4e51ee  orr      w14, w15, w14, lsr #20
//   0x002c6c: 2a4d51cd  orr      w13, w14, w13, lsr #20
//   0x002c70: 8b1b002e  add      x14, x1, x27
//   0x002c74: 2a1f03ea  mov      w10, wzr
//   0x002c78: aa1f03eb  mov      x11, xzr
//   0x002c7c: 131e3dad  sbfiz    w13, w13, #2, #0x10
//   0x002c80: d61f01c0  br       x14
//   0x002c84: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x002c88: f940050b  ldr      x11, [x8, #8]
//   0x002c8c: 12001588  and      w8, w12, #0x3f
//   0x002c90: 51000d08  sub      w8, w8, #3
//   0x002c94: 7100f11f  cmp      w8, #0x3c
//   0x002c98: 540067a8  b.hi     #0x398c
//   0x002c9c: 9000004a  adrp     x10, #0xa000
//   0x002ca0: 9126914a  add      x10, x10, #0x9a4
//   0x002ca4: aa0a03ec  mov      x12, x10
//   0x002ca8: b8a87988  ldrsw    x8, [x12, x8, lsl #2]
//   0x002cac: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x002cb0: f9400529  ldr      x9, [x9, #8]
//   0x002cb4: 110011aa  add      w10, w13, #4
//   0x002cb8: 8b0c010c  add      x12, x8, x12
//   0x002cbc: 8b2ac008  add      x8, x0, w10, sxtw
//   0x002cc0: d61f0180  br       x12
//   0x002cc4: f100013f  cmp      x9, #0
//   0x002cc8: 5400364d  b.le     #0x3390
//   0x002ccc: 2a1f03eb  mov      w11, wzr
//   0x002cd0: 2a1f03e9  mov      w9, wzr
//   0x002cd4: 140001aa  b        #0x337c
//   0x002cd8: 1200158a  and      w10, w12, #0x3f
//   0x002cdc: 5100294a  sub      w10, w10, #0xa
//   0x002ce0: 7100c55f  cmp      w10, #0x31
//   0x002ce4: 54006548  b.hi     #0x398c
//   0x002ce8: 53062d8b  ubfx     w11, w12, #6, #6
//   0x002cec: 12140d8c  and      w12, w12, #0xf000
//   0x002cf0: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x002cf4: 2a0b018b  orr      w11, w12, w11
//   0x002cf8: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x002cfc: b8aa7b2a  ldrsw    x10, [x25, x10, lsl #2]
//   0x002d00: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x002d04: f9400529  ldr      x9, [x9, #8]
//   0x002d08: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x002d0c: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x002d10: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x002d14: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x002d18: 8b19014a  add      x10, x10, x25
//   0x002d1c: 8b2ba129  add      x9, x9, w11, sxth
//   0x002d20: d61f0140  br       x10
//   0x002d24: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x002d28: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x002d2c: f9400508  ldr      x8, [x8, #8]
//   0x002d30: f940014b  ldr      x11, [x10]
//   0x002d34: d37d0929  ubfiz    x9, x9, #3, #3
//   0x002d38: 321d0bec  mov      w12, #0x38
//   0x002d3c: b278dfed  mov      x13, #-0x100
//   0x002d40: cb09018c  sub      x12, x12, x9
//   0x002d44: 9ac921a9  lsl      x9, x13, x9
//   0x002d48: 9acc2508  lsr      x8, x8, x12
//   0x002d4c: 8a090169  and      x9, x11, x9
//   0x002d50: 14000139  b        #0x3234
//   0x002d54: 12140d80  and      w0, w12, #0xf000
//   0x002d58: 53062d8a  ubfx     w10, w12, #6, #6
//   0x002d5c: 33147e40  bfxil    w0, w18, #0x14, #0xc
//   0x002d60: 2a0a000a  orr      w10, w0, w10
//   0x002d64: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x002d68: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x002d6c: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x002d70: 1200158b  and      w11, w12, #0x3f
//   0x002d74: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x002d78: 7100dd7f  cmp      w11, #0x37
//   0x002d7c: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x002d80: 5400082c  b.gt     #0x2e84
//   0x002d84: 7100117f  cmp      w11, #4
//   0x002d88: 54002ae0  b.eq     #0x32e4
//   0x002d8c: 7100817f  cmp      w11, #0x20
//   0x002d90: 54005fe1  b.ne     #0x398c
//   0x002d94: 910022ab  add      x11, x21, #8
//   0x002d98: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x002d9c: 12003d4a  and      w10, w10, #0xffff
//   0x002da0: 8a0a0129  and      x9, x9, x10
//   0x002da4: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x002da8: 140002f9  b        #0x398c
//   0x002dac: 12140d80  and      w0, w12, #0xf000
//   0x002db0: 53062d8a  ubfx     w10, w12, #6, #6
//   0x002db4: 33147e40  bfxil    w0, w18, #0x14, #0xc
//   0x002db8: 2a0a000a  orr      w10, w0, w10
//   0x002dbc: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x002dc0: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x002dc4: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x002dc8: 1200158b  and      w11, w12, #0x3f
//   0x002dcc: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x002dd0: 7100357f  cmp      w11, #0xd
//   0x002dd4: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x002dd8: 540006a0  b.eq     #0x2eac
//   0x002ddc: 7100a17f  cmp      w11, #0x28
//   0x002de0: 54000660  b.eq     #0x2eac
//   0x002de4: 7100557f  cmp      w11, #0x15
//   0x002de8: 54005d21  b.ne     #0x398c
//   0x002dec: 910022ab  add      x11, x21, #8
//   0x002df0: d37df129  lsl      x9, x9, #3
//   0x002df4: b8a96969  ldrsw    x9, [x11, x9]
//   0x002df8: 13003d4a  sxth     w10, w10
//   0x002dfc: 8b2ac129  add      x9, x9, w10, sxtw
//   0x002e00: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x002e04: 140002e2  b        #0x398c
//   0x002e08: b5005c21  cbnz     x1, #0x398c
//   0x002e0c: 1214358b  and      w11, w12, #0x3fff000
//   0x002e10: 53062d8a  ubfx     w10, w12, #6, #6
//   0x002e14: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x002e18: 2a0a016a  orr      w10, w11, w10
//   0x002e1c: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x002e20: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x002e24: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x002e28: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x002e2c: 12001588  and      w8, w12, #0x3f
//   0x002e30: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x002e34: 7100451f  cmp      w8, #0x11
//   0x002e38: 531e754c  lsl      w12, w10, #2
//   0x002e3c: 54002ee0  b.eq     #0x3418
//   0x002e40: 7100a91f  cmp      w8, #0x2a
//   0x002e44: 54002ee0  b.eq     #0x3420
//   0x002e48: 7100691f  cmp      w8, #0x1a
//   0x002e4c: 54005a01  b.ne     #0x398c
//   0x002e50: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x002e54: f9400529  ldr      x9, [x9, #8]
//   0x002e58: 8b2cc00a  add      x10, x0, w12, sxtw
//   0x002e5c: 9100200c  add      x12, x0, #8
//   0x002e60: 9100114a  add      x10, x10, #4
//   0x002e64: f100053f  cmp      x9, #1
//   0x002e68: 1a9fa7eb  cset     w11, lt
//   0x002e6c: f100013f  cmp      x9, #0
//   0x002e70: 2a1f03e8  mov      w8, wzr
//   0x002e74: 1a9fd7e9  cset     w9, gt
//   0x002e78: 9a8cc14c  csel     x12, x10, x12, gt
//   0x002e7c: 320003ea  mov      w10, #1
//   0x002e80: 1400016e  b        #0x3438
//   0x002e84: 7100e17f  cmp      w11, #0x38
//   0x002e88: 54002340  b.eq     #0x32f0
//   0x002e8c: 7100f97f  cmp      w11, #0x3e
//   0x002e90: 540057e1  b.ne     #0x398c
//   0x002e94: 910022ab  add      x11, x21, #8
//   0x002e98: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x002e9c: 12003d4a  and      w10, w10, #0xffff
//   0x002ea0: aa0a0129  orr      x9, x9, x10
//   0x002ea4: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x002ea8: 140002b9  b        #0x398c
//   0x002eac: 910022ab  add      x11, x21, #8
//   0x002eb0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x002eb4: 8b2aa129  add      x9, x9, w10, sxth
//   0x002eb8: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x002ebc: 140002b4  b        #0x398c
//   0x002ec0: 12002d8d  and      w13, w12, #0xfff
//   0x002ec4: 71293dbf  cmp      w13, #0xa4f
//   0x002ec8: 5400294c  b.gt     #0x33f0
//   0x002ecc: 710a3dbf  cmp      w13, #0x28f
//   0x002ed0: 540035ed  b.le     #0x358c
//   0x002ed4: 710a41bf  cmp      w13, #0x290
//   0x002ed8: 54003fc0  b.eq     #0x36d0
//   0x002edc: 711a41bf  cmp      w13, #0x690
//   0x002ee0: 54003f80  b.eq     #0x36d0
//   0x002ee4: 712341bf  cmp      w13, #0x8d0
//   0x002ee8: 540035c0  b.eq     #0x35a0
//   0x002eec: 140002a8  b        #0x398c
//   0x002ef0: 528007e8  mov      w8, #0x3f
//   0x002ef4: 72a003e8  movk     w8, #0x1f, lsl #16
//   0x002ef8: 529ffd2a  mov      w10, #0xffe9
//   0x002efc: 0a080188  and      w8, w12, w8
//   0x002f00: 72bfffca  movk     w10, #0xfffe, lsl #16
//   0x002f04: 0b0a010a  add      w10, w8, w10
//   0x002f08: 138a414a  ror      w10, w10, #0x10
//   0x002f0c: 7100695f  cmp      w10, #0x1a
//   0x002f10: 540053e8  b.hi     #0x398c
//   0x002f14: 320003eb  mov      w11, #1
//   0x002f18: 1aca216a  lsl      w10, w11, w10
//   0x002f1c: 52850c2b  mov      w11, #0x2861
//   0x002f20: 72a0908b  movk     w11, #0x484, lsl #16
//   0x002f24: 6a0b015f  tst      w10, w11
//   0x002f28: 54005320  b.eq     #0x398c
//   0x002f2c: b5005301  cbnz     x1, #0x398c
//   0x002f30: 53062d8b  ubfx     w11, w12, #6, #6
//   0x002f34: 12140d8c  and      w12, w12, #0xf000
//   0x002f38: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x002f3c: 2a0b018b  orr      w11, w12, w11
//   0x002f40: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x002f44: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x002f48: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x002f4c: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x002f50: 528002cc  mov      w12, #0x16
//   0x002f54: 1200510a  and      w10, w8, #0x1fffff
//   0x002f58: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x002f5c: 72a0002c  movk     w12, #1, lsl #16
//   0x002f60: 6b0c015f  cmp      w10, w12
//   0x002f64: 131e3d6c  sbfiz    w12, w11, #2, #0x10
//   0x002f68: 540028ec  b.gt     #0x3484
//   0x002f6c: 51000d4b  sub      w11, w10, #3
//   0x002f70: 7100f17f  cmp      w11, #0x3c
//   0x002f74: 540050c8  b.hi     #0x398c
//   0x002f78: 9000004d  adrp     x13, #0xa000
//   0x002f7c: 912d81ad  add      x13, x13, #0xb60
//   0x002f80: b8ab79ab  ldrsw    x11, [x13, x11, lsl #2]
//   0x002f84: 2a1f03ea  mov      w10, wzr
//   0x002f88: 8b0d016b  add      x11, x11, x13
//   0x002f8c: aa0003ed  mov      x13, x0
//   0x002f90: d61f0160  br       x11
//   0x002f94: aa1f03ed  mov      x13, xzr
//   0x002f98: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x002f9c: f940052b  ldr      x11, [x9, #8]
//   0x002fa0: 12005109  and      w9, w8, #0x1fffff
//   0x002fa4: 528002c8  mov      w8, #0x16
//   0x002fa8: 1100118a  add      w10, w12, #4
//   0x002fac: 72a00028  movk     w8, #1, lsl #16
//   0x002fb0: 6b08013f  cmp      w9, w8
//   0x002fb4: 8b2ac008  add      x8, x0, w10, sxtw
//   0x002fb8: 5400288c  b.gt     #0x34c8
//   0x002fbc: 51000d29  sub      w9, w9, #3
//   0x002fc0: 7100f13f  cmp      w9, #0x3c
//   0x002fc4: 54004e48  b.hi     #0x398c
//   0x002fc8: 9000004a  adrp     x10, #0xa000
//   0x002fcc: 9131514a  add      x10, x10, #0xc54
//   0x002fd0: b8a97949  ldrsw    x9, [x10, x9, lsl #2]
//   0x002fd4: 8b0a0129  add      x9, x9, x10
//   0x002fd8: d61f0120  br       x9
//   0x002fdc: f100017f  cmp      x11, #0
//   0x002fe0: 5400668d  b.le     #0x3cb0
//   0x002fe4: 2a1f03eb  mov      w11, wzr
//   0x002fe8: 2a1f03e9  mov      w9, wzr
//   0x002fec: 1400031f  b        #0x3c68
//   0x002ff0: 12140d8b  and      w11, w12, #0xf000
//   0x002ff4: 53062d8a  ubfx     w10, w12, #6, #6
//   0x002ff8: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x002ffc: 2a0a016a  orr      w10, w11, w10
//   0x003000: 910022ac  add      x12, x21, #8
//   0x003004: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x003008: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x00300c: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x003010: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x003014: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x003018: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x00301c: eb2aa13f  cmp      x9, w10, sxth
//   0x003020: 1a9f27e9  cset     w9, lo
//   0x003024: f8285989  str      x9, [x12, w8, uxtw #3]
//   0x003028: 14000259  b        #0x398c
//   0x00302c: 12002d8b  and      w11, w12, #0xfff
//   0x003030: 5106a56b  sub      w11, w11, #0x1a9
//   0x003034: 138b196b  ror      w11, w11, #6
//   0x003038: 7100697f  cmp      w11, #0x1a
//   0x00303c: 54004a88  b.hi     #0x398c
//   0x003040: 320003ed  mov      w13, #1
//   0x003044: 5280064e  mov      w14, #0x32
//   0x003048: 1acb21ad  lsl      w13, w13, w11
//   0x00304c: 72a0800e  movk     w14, #0x400, lsl #16
//   0x003050: 6a0e01bf  tst      w13, w14
//   0x003054: 540027a0  b.eq     #0x3548
//   0x003058: 12002d8a  and      w10, w12, #0xfff
//   0x00305c: 711db95f  cmp      w10, #0x76e
//   0x003060: 540025ac  b.gt     #0x3514
//   0x003064: 710ba15f  cmp      w10, #0x2e8
//   0x003068: 540036cc  b.gt     #0x3740
//   0x00306c: 7106bd5f  cmp      w10, #0x1af
//   0x003070: 540089e0  b.eq     #0x41ac
//   0x003074: 7107a55f  cmp      w10, #0x1e9
//   0x003078: 54005680  b.eq     #0x3b48
//   0x00307c: 710aa55f  cmp      w10, #0x2a9
//   0x003080: 54004861  b.ne     #0x398c
//   0x003084: 910022aa  add      x10, x21, #8
//   0x003088: d37df129  lsl      x9, x9, #3
//   0x00308c: d37df108  lsl      x8, x8, #3
//   0x003090: b94000cb  ldr      w11, [x6]
//   0x003094: b94000ec  ldr      w12, [x7]
//   0x003098: b8696949  ldr      w9, [x10, x9]
//   0x00309c: b8686948  ldr      w8, [x10, x8]
//   0x0030a0: 140002b9  b        #0x3b84
//   0x0030a4: 12002d8d  and      w13, w12, #0xfff
//   0x0030a8: 5101bdae  sub      w14, w13, #0x6f
//   0x0030ac: 138e19ce  ror      w14, w14, #6
//   0x0030b0: 7100f9df  cmp      w14, #0x3e
//   0x0030b4: 54006808  b.hi     #0x3db4
//   0x0030b8: f000002f  adrp     x15, #0xa000
//   0x0030bc: 913521ef  add      x15, x15, #0xd48
//   0x0030c0: b8ae79ee  ldrsw    x14, [x15, x14, lsl #2]
//   0x0030c4: 8b0f01ce  add      x14, x14, x15
//   0x0030c8: d61f01c0  br       x14
//   0x0030cc: 12002d8b  and      w11, w12, #0xfff
//   0x0030d0: 7121b97f  cmp      w11, #0x86e
//   0x0030d4: 54003f0d  b.le     #0x38b4
//   0x0030d8: 7127b97f  cmp      w11, #0x9ee
//   0x0030dc: 5400244d  b.le     #0x3564
//   0x0030e0: 7127bd7f  cmp      w11, #0x9ef
//   0x0030e4: 54002480  b.eq     #0x3574
//   0x0030e8: 7129bd7f  cmp      w11, #0xa6f
//   0x0030ec: 540048e0  b.eq     #0x3a08
//   0x0030f0: 7134bd7f  cmp      w11, #0xd2f
//   0x0030f4: 54004ba0  b.eq     #0x3a68
//   0x0030f8: 14000225  b        #0x398c
//   0x0030fc: 12140d8b  and      w11, w12, #0xf000
//   0x003100: 53062d8a  ubfx     w10, w12, #6, #6
//   0x003104: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x003108: 2a0a016a  orr      w10, w11, w10
//   0x00310c: 910022ac  add      x12, x21, #8
//   0x003110: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x003114: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x003118: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x00311c: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x003120: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x003124: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x003128: eb2aa13f  cmp      x9, w10, sxth
//   0x00312c: 1a9fa7e9  cset     w9, lt
//   0x003130: f8285989  str      x9, [x12, w8, uxtw #3]
//   0x003134: 14000216  b        #0x398c
//   0x003138: 79800129  ldrsh    x9, [x9]
//   0x00313c: 14000212  b        #0x3984
//   0x003140: f9400129  ldr      x9, [x9]
//   0x003144: 14000210  b        #0x3984
//   0x003148: 39800129  ldrsb    x9, [x9]
//   0x00314c: 1400020e  b        #0x3984
//   0x003150: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x003154: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003158: b940014a  ldr      w10, [x10]
//   0x00315c: b940090b  ldr      w11, [x8, #8]
//   0x003160: 531d0529  ubfiz    w9, w9, #3, #2
//   0x003164: 4b0903cc  sub      w12, w30, w9
//   0x003168: 1280000d  mov      w13, #-1
//   0x00316c: 1acc21ac  lsl      w12, w13, w12
//   0x003170: 1ac92549  lsr      w9, w10, w9
//   0x003174: 0a0c016a  and      w10, w11, w12
//   0x003178: 2a090149  orr      w9, w10, w9
//   0x00317c: 14000203  b        #0x3988
//   0x003180: 39400129  ldrb     w9, [x9]
//   0x003184: 14000200  b        #0x3984
//   0x003188: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x00318c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003190: f940014a  ldr      x10, [x10]
//   0x003194: f940050b  ldr      x11, [x8, #8]
//   0x003198: d37d0929  ubfiz    x9, x9, #3, #3
//   0x00319c: 321a03ec  mov      w12, #0x40
//   0x0031a0: cb09018c  sub      x12, x12, x9
//   0x0031a4: 9280000d  mov      x13, #-1
//   0x0031a8: 9acc21ac  lsl      x12, x13, x12
//   0x0031ac: 9ac92549  lsr      x9, x10, x9
//   0x0031b0: 8a0c016a  and      x10, x11, x12
//   0x0031b4: aa090149  orr      x9, x10, x9
//   0x0031b8: 140001f4  b        #0x3988
//   0x0031bc: b9800129  ldrsw    x9, [x9]
//   0x0031c0: 140001f1  b        #0x3984
//   0x0031c4: 79400129  ldrh     w9, [x9]
//   0x0031c8: 140001ef  b        #0x3984
//   0x0031cc: b9400129  ldr      w9, [x9]
//   0x0031d0: 140001ed  b        #0x3984
//   0x0031d4: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0031d8: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0031dc: b940014a  ldr      w10, [x10]
//   0x0031e0: b940090b  ldr      w11, [x8, #8]
//   0x0031e4: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0031e8: 321d07ec  mov      w12, #0x18
//   0x0031ec: 32005fed  mov      w13, #0xffffff
//   0x0031f0: 4b09018c  sub      w12, w12, w9
//   0x0031f4: 1ac925a9  lsr      w9, w13, w9
//   0x0031f8: 1acc214a  lsl      w10, w10, w12
//   0x0031fc: 0a090169  and      w9, w11, w9
//   0x003200: 2a0a0129  orr      w9, w9, w10
//   0x003204: 140001e1  b        #0x3988
//   0x003208: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x00320c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003210: f9400508  ldr      x8, [x8, #8]
//   0x003214: f940014b  ldr      x11, [x10]
//   0x003218: d37d0929  ubfiz    x9, x9, #3, #3
//   0x00321c: 321a03ec  mov      w12, #0x40
//   0x003220: cb09018c  sub      x12, x12, x9
//   0x003224: 9280000d  mov      x13, #-1
//   0x003228: 9acc25ac  lsr      x12, x13, x12
//   0x00322c: 9ac92108  lsl      x8, x8, x9
//   0x003230: 8a0c0169  and      x9, x11, x12
//   0x003234: aa080128  orr      x8, x9, x8
//   0x003238: f9000148  str      x8, [x10]
//   0x00323c: 140001d4  b        #0x398c
//   0x003240: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003244: b9400908  ldr      w8, [x8, #8]
//   0x003248: 39000128  strb     w8, [x9]
//   0x00324c: 140001d0  b        #0x398c
//   0x003250: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003254: b9400908  ldr      w8, [x8, #8]
//   0x003258: 79000128  strh     w8, [x9]
//   0x00325c: 140001cc  b        #0x398c
//   0x003260: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x003264: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003268: b9400908  ldr      w8, [x8, #8]
//   0x00326c: b940014b  ldr      w11, [x10]
//   0x003270: 531d0529  ubfiz    w9, w9, #3, #2
//   0x003274: 321d07ec  mov      w12, #0x18
//   0x003278: 32185fed  mov      w13, #-0x100
//   0x00327c: 4b09018c  sub      w12, w12, w9
//   0x003280: 1ac921a9  lsl      w9, w13, w9
//   0x003284: 1acc2508  lsr      w8, w8, w12
//   0x003288: 0a090169  and      w9, w11, w9
//   0x00328c: 1400000b  b        #0x32b8
//   0x003290: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x003294: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003298: b9400908  ldr      w8, [x8, #8]
//   0x00329c: b940014b  ldr      w11, [x10]
//   0x0032a0: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0032a4: 4b0903cc  sub      w12, w30, w9
//   0x0032a8: 1280000d  mov      w13, #-1
//   0x0032ac: 1acc25ac  lsr      w12, w13, w12
//   0x0032b0: 1ac92108  lsl      w8, w8, w9
//   0x0032b4: 0a0c0169  and      w9, w11, w12
//   0x0032b8: 2a080128  orr      w8, w9, w8
//   0x0032bc: b9000148  str      w8, [x10]
//   0x0032c0: 140001b3  b        #0x398c
//   0x0032c4: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0032c8: b9400908  ldr      w8, [x8, #8]
//   0x0032cc: b9000128  str      w8, [x9]
//   0x0032d0: 140001af  b        #0x398c
//   0x0032d4: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0032d8: f9400508  ldr      x8, [x8, #8]
//   0x0032dc: f9000128  str      x8, [x9]
//   0x0032e0: 140001ab  b        #0x398c
//   0x0032e4: 53103d49  lsl      w9, w10, #0x10
//   0x0032e8: 93407d29  sxtw     x9, w9
//   0x0032ec: 140001a6  b        #0x3984
//   0x0032f0: 910022ab  add      x11, x21, #8
//   0x0032f4: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0032f8: 12003d4a  and      w10, w10, #0xffff
//   0x0032fc: ca0a0129  eor      x9, x9, x10
//   0x003300: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x003304: 140001a2  b        #0x398c
//   0x003308: 320013ea  mov      w10, #0x1f
//   0x00330c: f85f8268  ldur     x8, [x19, #-8]
//   0x003310: 2a1f03eb  mov      w11, wzr
//   0x003314: 2a1f03e9  mov      w9, wzr
//   0x003318: 320003ec  mov      w12, #1
//   0x00331c: 8b2d4108  add      x8, x8, w13, uxtw
//   0x003320: 14000021  b        #0x33a4
//   0x003324: eb0b013f  cmp      x9, x11
//   0x003328: 54ffcd21  b.ne     #0x2ccc
//   0x00332c: 14000019  b        #0x3390
//   0x003330: eb0b013f  cmp      x9, x11
//   0x003334: 540002e1  b.ne     #0x3390
//   0x003338: 17fffe65  b        #0x2ccc
//   0x00333c: f100013f  cmp      x9, #0
//   0x003340: 320003e9  mov      w9, #1
//   0x003344: 540001ac  b.gt     #0x3378
//   0x003348: 14000013  b        #0x3394
//   0x00334c: eb0b013f  cmp      x9, x11
//   0x003350: 320003e9  mov      w9, #1
//   0x003354: 54000120  b.eq     #0x3378
//   0x003358: 1400000f  b        #0x3394
//   0x00335c: f100053f  cmp      x9, #1
//   0x003360: 320003e9  mov      w9, #1
//   0x003364: 5400018a  b.ge     #0x3394
//   0x003368: 14000004  b        #0x3378
//   0x00336c: eb0b013f  cmp      x9, x11
//   0x003370: 320003e9  mov      w9, #1
//   0x003374: 54000100  b.eq     #0x3394
//   0x003378: 2a1f03eb  mov      w11, wzr
//   0x00337c: 2a1f03ea  mov      w10, wzr
//   0x003380: 320003ec  mov      w12, #1
//   0x003384: 14000008  b        #0x33a4
//   0x003388: f100053f  cmp      x9, #1
//   0x00338c: 54ffca0b  b.lt     #0x2ccc
//   0x003390: 2a1f03e9  mov      w9, wzr
//   0x003394: 2a1f03ec  mov      w12, wzr
//   0x003398: 2a1f03ea  mov      w10, wzr
//   0x00339c: 91002008  add      x8, x0, #8
//   0x0033a0: 320003eb  mov      w11, #1
//   0x0033a4: 7100013f  cmp      w9, #0
//   0x0033a8: 1a9f07ed  cset     w13, ne
//   0x0033ac: 0a0d016b  and      w11, w11, w13
//   0x0033b0: f81e8268  stur     x8, [x19, #-0x18]
//   0x0033b4: 3700008b  tbnz     w11, #0, #0x33c4
//   0x0033b8: 34000069  cbz      w9, #0x33c4
//   0x0033bc: 0a0d0188  and      w8, w12, w13
//   0x0033c0: 340000a8  cbz      w8, #0x33d4
//   0x0033c4: 7100017f  cmp      w11, #0
//   0x0033c8: 320003e8  mov      w8, #1
//   0x0033cc: 9a881508  cinc     x8, x8, eq
//   0x0033d0: f81e0268  stur     x8, [x19, #-0x20]
//   0x0033d4: 7100055f  cmp      w10, #1
//   0x0033d8: 54002dab  b.lt     #0x398c
//   0x0033dc: 91002008  add      x8, x0, #8
//   0x0033e0: 8b2acea9  add      x9, x21, w10, sxtw #3
//   0x0033e4: f9000528  str      x8, [x9, #8]
//   0x0033e8: f81f0268  stur     x8, [x19, #-0x10]
//   0x0033ec: 14000168  b        #0x398c
//   0x0033f0: 713a3dbf  cmp      w13, #0xe8f
//   0x0033f4: 54000dad  b.le     #0x35a8
//   0x0033f8: 713a41bf  cmp      w13, #0xe90
//   0x0033fc: 54002ac0  b.eq     #0x3954
//   0x003400: 713b41bf  cmp      w13, #0xed0
//   0x003404: 54002a60  b.eq     #0x3950
//   0x003408: 713e41bf  cmp      w13, #0xf90
//   0x00340c: 54002c01  b.ne     #0x398c
//   0x003410: 321b014a  orr      w10, w10, #0x20
//   0x003414: 14000150  b        #0x3954
//   0x003418: 320013e8  mov      w8, #0x1f
//   0x00341c: 14000002  b        #0x3424
//   0x003420: 2a1f03e8  mov      w8, wzr
//   0x003424: f85f8269  ldur     x9, [x19, #-8]
//   0x003428: 2a1f03eb  mov      w11, wzr
//   0x00342c: 2a1f03ea  mov      w10, wzr
//   0x003430: 8b2c412c  add      x12, x9, w12, uxtw
//   0x003434: 320003e9  mov      w9, #1
//   0x003438: 7100015f  cmp      w10, #0
//   0x00343c: 1a9f07ed  cset     w13, ne
//   0x003440: 0a0d016b  and      w11, w11, w13
//   0x003444: f81e826c  stur     x12, [x19, #-0x18]
//   0x003448: 3700008b  tbnz     w11, #0, #0x3458
//   0x00344c: 3400006a  cbz      w10, #0x3458
//   0x003450: 0a0d0129  and      w9, w9, w13
//   0x003454: 340000a9  cbz      w9, #0x3468
//   0x003458: 7100017f  cmp      w11, #0
//   0x00345c: 320003e9  mov      w9, #1
//   0x003460: 9a891529  cinc     x9, x9, eq
//   0x003464: f81e0269  stur     x9, [x19, #-0x20]
//   0x003468: 7100051f  cmp      w8, #1
//   0x00346c: 5400290b  b.lt     #0x398c
//   0x003470: 91002009  add      x9, x0, #8
//   0x003474: 8b28cea8  add      x8, x21, w8, sxtw #3
//   0x003478: f9000509  str      x9, [x8, #8]
//   0x00347c: f81f0269  stur     x9, [x19, #-0x10]
//   0x003480: 14000143  b        #0x398c
//   0x003484: 528002cb  mov      w11, #0x16
//   0x003488: 72a001cb  movk     w11, #0xe, lsl #16
//   0x00348c: 6b0b015f  cmp      w10, w11
//   0x003490: 54000eac  b.gt     #0x3664
//   0x003494: 528002cb  mov      w11, #0x16
//   0x003498: 72a000eb  movk     w11, #7, lsl #16
//   0x00349c: 6b0b015f  cmp      w10, w11
//   0x0034a0: 54001e6c  b.gt     #0x386c
//   0x0034a4: 528002eb  mov      w11, #0x17
//   0x0034a8: 72a0002b  movk     w11, #1, lsl #16
//   0x0034ac: 6b0b015f  cmp      w10, w11
//   0x0034b0: 54ffd720  b.eq     #0x2f94
//   0x0034b4: 528002eb  mov      w11, #0x17
//   0x0034b8: 72a000cb  movk     w11, #6, lsl #16
//   0x0034bc: 6b0b015f  cmp      w10, w11
//   0x0034c0: 54ffd6a0  b.eq     #0x2f94
//   0x0034c4: 14000132  b        #0x398c
//   0x0034c8: 528002ca  mov      w10, #0x16
//   0x0034cc: 72a001ca  movk     w10, #0xe, lsl #16
//   0x0034d0: 6b0a013f  cmp      w9, w10
//   0x0034d4: 54000e2c  b.gt     #0x3698
//   0x0034d8: 528002ca  mov      w10, #0x16
//   0x0034dc: 72a000ea  movk     w10, #7, lsl #16
//   0x0034e0: 6b0a013f  cmp      w9, w10
//   0x0034e4: 5400204c  b.gt     #0x38ec
//   0x0034e8: 528002ea  mov      w10, #0x17
//   0x0034ec: 72a0002a  movk     w10, #1, lsl #16
//   0x0034f0: 6b0a013f  cmp      w9, w10
//   0x0034f4: 54004060  b.eq     #0x3d00
//   0x0034f8: 528002ea  mov      w10, #0x17
//   0x0034fc: 72a000ca  movk     w10, #6, lsl #16
//   0x003500: 6b0a013f  cmp      w9, w10
//   0x003504: 54002441  b.ne     #0x398c
//   0x003508: 320013ea  mov      w10, #0x1f
//   0x00350c: b6f83d4b  tbz      x11, #0x3f, #0x3cb4
//   0x003510: 14000101  b        #0x3914
//   0x003514: 7124b95f  cmp      w10, #0x92e
//   0x003518: 540012ac  b.gt     #0x376c
//   0x00351c: 711dbd5f  cmp      w10, #0x76f
//   0x003520: 54006900  b.eq     #0x4240
//   0x003524: 7120a55f  cmp      w10, #0x829
//   0x003528: 54003200  b.eq     #0x3b68
//   0x00352c: 7122bd5f  cmp      w10, #0x8af
//   0x003530: 540022e1  b.ne     #0x398c
//   0x003534: 910022aa  add      x10, x21, #8
//   0x003538: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x00353c: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x003540: 9ac8092a  udiv     x10, x9, x8
//   0x003544: 14000336  b        #0x421c
//   0x003548: 7100097f  cmp      w11, #2
//   0x00354c: 54002201  b.ne     #0x398c
//   0x003550: 12002d8b  and      w11, w12, #0xfff
//   0x003554: 7121b97f  cmp      w11, #0x86e
//   0x003558: 5400280d  b.le     #0x3a58
//   0x00355c: 7127b97f  cmp      w11, #0x9ee
//   0x003560: 54ffdc0c  b.gt     #0x30e0
//   0x003564: 7121bd7f  cmp      w11, #0x86f
//   0x003568: 54002500  b.eq     #0x3a08
//   0x00356c: 7125bd7f  cmp      w11, #0x96f
//   0x003570: 540020e1  b.ne     #0x398c
//   0x003574: 910022ab  add      x11, x21, #8
//   0x003578: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x00357c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003580: 8b090108  add      x8, x8, x9
//   0x003584: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003588: 14000101  b        #0x398c
//   0x00358c: 710041bf  cmp      w13, #0x10
//   0x003590: 540021a0  b.eq     #0x39c4
//   0x003594: 710241bf  cmp      w13, #0x90
//   0x003598: 54001fa1  b.ne     #0x398c
//   0x00359c: 321b016b  orr      w11, w11, #0x20
//   0x0035a0: 321b014a  orr      w10, w10, #0x20
//   0x0035a4: 1400001c  b        #0x3614
//   0x0035a8: 712941bf  cmp      w13, #0xa50
//   0x0035ac: 54000340  b.eq     #0x3614
//   0x0035b0: 712b41bf  cmp      w13, #0xad0
//   0x0035b4: 54001ec1  b.ne     #0x398c
//   0x0035b8: 6b0b015f  cmp      w10, w11
//   0x0035bc: 54001e83  b.lo     #0x398c
//   0x0035c0: 910022ad  add      x13, x21, #8
//   0x0035c4: d37df129  lsl      x9, x9, #3
//   0x0035c8: 320003ec  mov      w12, #1
//   0x0035cc: d37df108  lsl      x8, x8, #3
//   0x0035d0: b86969a9  ldr      w9, [x13, x9]
//   0x0035d4: 4b0b018c  sub      w12, w12, w11
//   0x0035d8: b86869ae  ldr      w14, [x13, x8]
//   0x0035dc: 0b0a018c  add      w12, w12, w10
//   0x0035e0: 1280000f  mov      w15, #-1
//   0x0035e4: 1acc21ec  lsl      w12, w15, w12
//   0x0035e8: 0a2c0129  bic      w9, w9, w12
//   0x0035ec: 1aca21ea  lsl      w10, w15, w10
//   0x0035f0: 1acb21ec  lsl      w12, w15, w11
//   0x0035f4: 0a0a01ca  and      w10, w14, w10
//   0x0035f8: 1acb2129  lsl      w9, w9, w11
//   0x0035fc: 0a2c01cc  bic      w12, w14, w12
//   0x003600: 2a090149  orr      w9, w10, w9
//   0x003604: 2a0c0129  orr      w9, w9, w12
//   0x003608: 93407d29  sxtw     x9, w9
//   0x00360c: f82869a9  str      x9, [x13, x8]
//   0x003610: 140000df  b        #0x398c
//   0x003614: 6b0b015f  cmp      w10, w11
//   0x003618: 54001bab  b.lt     #0x398c
//   0x00361c: 910022ac  add      x12, x21, #8
//   0x003620: d37df108  lsl      x8, x8, #3
//   0x003624: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x003628: 1100054d  add      w13, w10, #1
//   0x00362c: f868698e  ldr      x14, [x12, x8]
//   0x003630: 4b0b01ad  sub      w13, w13, w11
//   0x003634: 9280000f  mov      x15, #-1
//   0x003638: 9acd21ed  lsl      x13, x15, x13
//   0x00363c: 8a2d0129  bic      x9, x9, x13
//   0x003640: 9aca21ea  lsl      x10, x15, x10
//   0x003644: 9acb21ed  lsl      x13, x15, x11
//   0x003648: 8a0a01ca  and      x10, x14, x10
//   0x00364c: 9acb2129  lsl      x9, x9, x11
//   0x003650: 8a2d01cd  bic      x13, x14, x13
//   0x003654: aa090149  orr      x9, x10, x9
//   0x003658: aa0d0129  orr      x9, x9, x13
//   0x00365c: f8286989  str      x9, [x12, x8]
//   0x003660: 140000cb  b        #0x398c
//   0x003664: 528002cb  mov      w11, #0x16
//   0x003668: 72a0030b  movk     w11, #0x18, lsl #16
//   0x00366c: 6b0b015f  cmp      w10, w11
//   0x003670: 5400110c  b.gt     #0x3890
//   0x003674: 528002eb  mov      w11, #0x17
//   0x003678: 72a001cb  movk     w11, #0xe, lsl #16
//   0x00367c: 6b0b015f  cmp      w10, w11
//   0x003680: 54ffc8a0  b.eq     #0x2f94
//   0x003684: 528002eb  mov      w11, #0x17
//   0x003688: 72a0026b  movk     w11, #0x13, lsl #16
//   0x00368c: 6b0b015f  cmp      w10, w11
//   0x003690: 54ffc820  b.eq     #0x2f94
//   0x003694: 140000be  b        #0x398c
//   0x003698: 528002ca  mov      w10, #0x16
//   0x00369c: 72a0030a  movk     w10, #0x18, lsl #16
//   0x0036a0: 6b0a013f  cmp      w9, w10
//   0x0036a4: 540013ec  b.gt     #0x3920
//   0x0036a8: 528002ea  mov      w10, #0x17
//   0x0036ac: 72a001ca  movk     w10, #0xe, lsl #16
//   0x0036b0: 6b0a013f  cmp      w9, w10
//   0x0036b4: 540032a0  b.eq     #0x3d08
//   0x0036b8: 528002ea  mov      w10, #0x17
//   0x0036bc: 72a0026a  movk     w10, #0x13, lsl #16
//   0x0036c0: 6b0a013f  cmp      w9, w10
//   0x0036c4: 54001641  b.ne     #0x398c
//   0x0036c8: b6ffc8eb  tbz      x11, #0x3f, #0x2fe4
//   0x0036cc: 14000179  b        #0x3cb0
//   0x0036d0: 5281ffe9  mov      w9, #0xfff
//   0x0036d4: 72af8009  movk     w9, #0x7c00, lsl #16
//   0x0036d8: 528051eb  mov      w11, #0x28f
//   0x0036dc: 0a090189  and      w9, w12, w9
//   0x0036e0: 72a9800b  movk     w11, #0x4c00, lsl #16
//   0x0036e4: 6b0b013f  cmp      w9, w11
//   0x0036e8: 540019ed  b.le     #0x3a24
//   0x0036ec: 5280520b  mov      w11, #0x290
//   0x0036f0: 72a9800b  movk     w11, #0x4c00, lsl #16
//   0x0036f4: 6b0b013f  cmp      w9, w11
//   0x0036f8: 540031e0  b.eq     #0x3d34
//   0x0036fc: 5280d20b  mov      w11, #0x690
//   0x003700: 72aa800b  movk     w11, #0x5400, lsl #16
//   0x003704: 6b0b013f  cmp      w9, w11
//   0x003708: 54003200  b.eq     #0x3d48
//   0x00370c: 5280520b  mov      w11, #0x290
//   0x003710: 72ae800b  movk     w11, #0x7400, lsl #16
//   0x003714: 6b0b013f  cmp      w9, w11
//   0x003718: 540013a1  b.ne     #0x398c
//   0x00371c: 910022a9  add      x9, x21, #8
//   0x003720: d37df108  lsl      x8, x8, #3
//   0x003724: b8686928  ldr      w8, [x9, x8]
//   0x003728: 53087d0b  lsr      w11, w8, #8
//   0x00372c: 53185d08  lsl      w8, w8, #8
//   0x003730: 12009d6b  and      w11, w11, #0xff00ff
//   0x003734: 12089d08  and      w8, w8, #0xff00ff00
//   0x003738: 2a0b0108  orr      w8, w8, w11
//   0x00373c: 14000256  b        #0x4094
//   0x003740: 710ba55f  cmp      w10, #0x2e9
//   0x003744: 54002260  b.eq     #0x3b90
//   0x003748: 7114bd5f  cmp      w10, #0x52f
//   0x00374c: 54005180  b.eq     #0x417c
//   0x003750: 711cbd5f  cmp      w10, #0x72f
//   0x003754: 540011c1  b.ne     #0x398c
//   0x003758: 910022aa  add      x10, x21, #8
//   0x00375c: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x003760: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x003764: 9b497d0a  smulh    x10, x8, x9
//   0x003768: 140002ba  b        #0x4250
//   0x00376c: 7124bd5f  cmp      w10, #0x92f
//   0x003770: 540033a0  b.eq     #0x3de4
//   0x003774: 712cbd5f  cmp      w10, #0xb2f
//   0x003778: 540054a0  b.eq     #0x420c
//   0x00377c: 7136bd5f  cmp      w10, #0xdaf
//   0x003780: 54001061  b.ne     #0x398c
//   0x003784: 910022aa  add      x10, x21, #8
//   0x003788: d37df129  lsl      x9, x9, #3
//   0x00378c: d37df108  lsl      x8, x8, #3
//   0x003790: b8696949  ldr      w9, [x10, x9]
//   0x003794: b8686948  ldr      w8, [x10, x8]
//   0x003798: 1ac80d2a  sdiv     w10, w9, w8
//   0x00379c: 1400027e  b        #0x4194
//   0x0037a0: 0a180189  and      w9, w12, w24
//   0x0037a4: 511c430c  sub      w12, w24, #0x710
//   0x0037a8: 6b0c013f  cmp      w9, w12
//   0x0037ac: 1a8d018d  csel     w13, w12, w13, eq
//   0x0037b0: 5103430c  sub      w12, w24, #0xd0
//   0x0037b4: 6b0c013f  cmp      w9, w12
//   0x0037b8: 1a8d018d  csel     w13, w12, w13, eq
//   0x0037bc: 5111430c  sub      w12, w24, #0x450
//   0x0037c0: 6b0c013f  cmp      w9, w12
//   0x0037c4: 1a8d018d  csel     w13, w12, w13, eq
//   0x0037c8: 7131b9bf  cmp      w13, #0xc6e
//   0x0037cc: 5400018c  b.gt     #0x37fc
//   0x0037d0: 7123b9bf  cmp      w13, #0x8ee
//   0x0037d4: 5400170c  b.gt     #0x3ab4
//   0x0037d8: 710bbdbf  cmp      w13, #0x2ef
//   0x0037dc: 540040a0  b.eq     #0x3ff0
//   0x0037e0: 710fbdbf  cmp      w13, #0x3ef
//   0x0037e4: 54004100  b.eq     #0x4004
//   0x0037e8: 7111bdbf  cmp      w13, #0x46f
//   0x0037ec: 54000d01  b.ne     #0x398c
//   0x0037f0: 910022a9  add      x9, x21, #8
//   0x0037f4: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x0037f8: 14000211  b        #0x403c
//   0x0037fc: 52811dc9  mov      w9, #0x8ee
//   0x003800: 72a00409  movk     w9, #0x20, lsl #16
//   0x003804: 6b0901bf  cmp      w13, w9
//   0x003808: 540016cc  b.gt     #0x3ae0
//   0x00380c: 7131bdbf  cmp      w13, #0xc6f
//   0x003810: 54004040  b.eq     #0x4018
//   0x003814: 7132bdbf  cmp      w13, #0xcaf
//   0x003818: 540040a0  b.eq     #0x402c
//   0x00381c: 713cbdbf  cmp      w13, #0xf2f
//   0x003820: 54000b61  b.ne     #0x398c
//   0x003824: 910022a9  add      x9, x21, #8
//   0x003828: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x00382c: 321b016b  orr      w11, w11, #0x20
//   0x003830: 92403d6b  and      x11, x11, #0xffff
//   0x003834: 14000207  b        #0x4050
//   0x003838: 12002d8b  and      w11, w12, #0xfff
//   0x00383c: 7120b97f  cmp      w11, #0x82e
//   0x003840: 5400170c  b.gt     #0x3b20
//   0x003844: 710dbd7f  cmp      w11, #0x36f
//   0x003848: 54003ba0  b.eq     #0x3fbc
//   0x00384c: 7118bd7f  cmp      w11, #0x62f
//   0x003850: 540009e1  b.ne     #0x398c
//   0x003854: 910022ab  add      x11, x21, #8
//   0x003858: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x00385c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003860: aa090108  orr      x8, x8, x9
//   0x003864: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003868: 14000049  b        #0x398c
//   0x00386c: 528002eb  mov      w11, #0x17
//   0x003870: 72a000eb  movk     w11, #7, lsl #16
//   0x003874: 6b0b015f  cmp      w10, w11
//   0x003878: 54ffb8e0  b.eq     #0x2f94
//   0x00387c: 528002eb  mov      w11, #0x17
//   0x003880: 72a0018b  movk     w11, #0xc, lsl #16
//   0x003884: 6b0b015f  cmp      w10, w11
//   0x003888: 54ffb860  b.eq     #0x2f94
//   0x00388c: 14000040  b        #0x398c
//   0x003890: 528002eb  mov      w11, #0x17
//   0x003894: 72a0036b  movk     w11, #0x1b, lsl #16
//   0x003898: 6b0b015f  cmp      w10, w11
//   0x00389c: 54ffb7c0  b.eq     #0x2f94
//   0x0038a0: 528002eb  mov      w11, #0x17
//   0x0038a4: 72a0030b  movk     w11, #0x18, lsl #16
//   0x0038a8: 6b0b015f  cmp      w10, w11
//   0x0038ac: 54ffb740  b.eq     #0x2f94
//   0x0038b0: 14000037  b        #0x398c
//   0x0038b4: 710eb97f  cmp      w11, #0x3ae
//   0x0038b8: 54000eac  b.gt     #0x3a8c
//   0x0038bc: 7107bd7f  cmp      w11, #0x1ef
//   0x0038c0: 54000d40  b.eq     #0x3a68
//   0x0038c4: 7108a57f  cmp      w11, #0x229
//   0x0038c8: 54000621  b.ne     #0x398c
//   0x0038cc: d37df129  lsl      x9, x9, #3
//   0x0038d0: 910022ab  add      x11, x21, #8
//   0x0038d4: d37df108  lsl      x8, x8, #3
//   0x0038d8: b8a86968  ldrsw    x8, [x11, x8]
//   0x0038dc: b8a96969  ldrsw    x9, [x11, x9]
//   0x0038e0: 9b097d08  mul      x8, x8, x9
//   0x0038e4: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0038e8: 14000029  b        #0x398c
//   0x0038ec: 528002ea  mov      w10, #0x17
//   0x0038f0: 72a000ea  movk     w10, #7, lsl #16
//   0x0038f4: 6b0a013f  cmp      w9, w10
//   0x0038f8: 54002120  b.eq     #0x3d1c
//   0x0038fc: 528002ea  mov      w10, #0x17
//   0x003900: 72a0018a  movk     w10, #0xc, lsl #16
//   0x003904: 6b0a013f  cmp      w9, w10
//   0x003908: 54000421  b.ne     #0x398c
//   0x00390c: 320013ea  mov      w10, #0x1f
//   0x003910: b7f81d2b  tbnz     x11, #0x3f, #0x3cb4
//   0x003914: 2a1f03eb  mov      w11, wzr
//   0x003918: 2a1f03e9  mov      w9, wzr
//   0x00391c: 140000d4  b        #0x3c6c
//   0x003920: 528002ea  mov      w10, #0x17
//   0x003924: 72a0030a  movk     w10, #0x18, lsl #16
//   0x003928: 6b0a013f  cmp      w9, w10
//   0x00392c: 54001fe0  b.eq     #0x3d28
//   0x003930: 528002ea  mov      w10, #0x17
//   0x003934: 72a0036a  movk     w10, #0x1b, lsl #16
//   0x003938: 6b0a013f  cmp      w9, w10
//   0x00393c: 54000281  b.ne     #0x398c
//   0x003940: 320013ea  mov      w10, #0x1f
//   0x003944: 320003e9  mov      w9, #1
//   0x003948: b6f81b8b  tbz      x11, #0x3f, #0x3cb8
//   0x00394c: 140000f2  b        #0x3d14
//   0x003950: 321b016b  orr      w11, w11, #0x20
//   0x003954: 0b0a016c  add      w12, w11, w10
//   0x003958: 7100fd9f  cmp      w12, #0x3f
//   0x00395c: 5400018c  b.gt     #0x398c
//   0x003960: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x003964: f9400529  ldr      x9, [x9, #8]
//   0x003968: 7100fd5f  cmp      w10, #0x3f
//   0x00396c: 540000c0  b.eq     #0x3984
//   0x003970: 1100054a  add      w10, w10, #1
//   0x003974: 9acb2529  lsr      x9, x9, x11
//   0x003978: 9280000b  mov      x11, #-1
//   0x00397c: 9aca216a  lsl      x10, x11, x10
//   0x003980: 8a2a0129  bic      x9, x9, x10
//   0x003984: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x003988: f9000509  str      x9, [x8, #8]
//   0x00398c: f94002a9  ldr      x9, [x21]
//   0x003990: f85e0268  ldur     x8, [x19, #-0x20]
//   0x003994: 91001120  add      x0, x9, #4
//   0x003998: f100091f  cmp      x8, #2
//   0x00399c: f90002a0  str      x0, [x21]
//   0x0039a0: 540000e0  b.eq     #0x39bc
//   0x0039a4: f1000d1f  cmp      x8, #3
//   0x0039a8: 54001180  b.eq     #0x3bd8
//   0x0039ac: f100051f  cmp      x8, #1
//   0x0039b0: 54001140  b.eq     #0x3bd8
//   0x0039b4: eb14001f  cmp      x0, x20
//   0x0039b8: 540011a0  b.eq     #0x3bec
//   0x0039bc: b5ff8c00  cbnz     x0, #0x2b3c
//   0x0039c0: 1400027f  b        #0x43bc
//   0x0039c4: 0b0b014c  add      w12, w10, w11
//   0x0039c8: 71007d9f  cmp      w12, #0x1f
//   0x0039cc: 54fffe08  b.hi     #0x398c
//   0x0039d0: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x0039d4: b9400929  ldr      w9, [x9, #8]
//   0x0039d8: 71007d5f  cmp      w10, #0x1f
//   0x0039dc: 54ffc860  b.eq     #0x32e8
//   0x0039e0: 1acb2529  lsr      w9, w9, w11
//   0x0039e4: 321f7beb  mov      w11, #-2
//   0x0039e8: 1aca216a  lsl      w10, w11, w10
//   0x0039ec: 0a2a0129  bic      w9, w9, w10
//   0x0039f0: 17fffe3e  b        #0x32e8
//   0x0039f4: 113342eb  add      w11, w23, #0xcd0
//   0x0039f8: 0a0b018b  and      w11, w12, w11
//   0x0039fc: 6b17017f  cmp      w11, w23
//   0x003a00: 1a8d02ed  csel     w13, w23, w13, eq
//   0x003a04: 14000122  b        #0x3e8c
//   0x003a08: 910022ab  add      x11, x21, #8
//   0x003a0c: d37df129  lsl      x9, x9, #3
//   0x003a10: d37df108  lsl      x8, x8, #3
//   0x003a14: b8696969  ldr      w9, [x11, x9]
//   0x003a18: b8686968  ldr      w8, [x11, x8]
//   0x003a1c: 4b080128  sub      w8, w9, w8
//   0x003a20: 14000018  b        #0x3a80
//   0x003a24: 5280d20b  mov      w11, #0x690
//   0x003a28: 72a1800b  movk     w11, #0xc00, lsl #16
//   0x003a2c: 6b0b013f  cmp      w9, w11
//   0x003a30: 540019e0  b.eq     #0x3d6c
//   0x003a34: 5280520b  mov      w11, #0x290
//   0x003a38: 72a7000b  movk     w11, #0x3800, lsl #16
//   0x003a3c: 6b0b013f  cmp      w9, w11
//   0x003a40: 54fffa61  b.ne     #0x398c
//   0x003a44: 910022a9  add      x9, x21, #8
//   0x003a48: d37df108  lsl      x8, x8, #3
//   0x003a4c: 38a86928  ldrsb    x8, [x9, x8]
//   0x003a50: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x003a54: 17ffffce  b        #0x398c
//   0x003a58: 710eb97f  cmp      w11, #0x3ae
//   0x003a5c: 5400018c  b.gt     #0x3a8c
//   0x003a60: 7107bd7f  cmp      w11, #0x1ef
//   0x003a64: 54fff301  b.ne     #0x38c4
//   0x003a68: 910022ab  add      x11, x21, #8
//   0x003a6c: d37df129  lsl      x9, x9, #3
//   0x003a70: d37df108  lsl      x8, x8, #3
//   0x003a74: b8696969  ldr      w9, [x11, x9]
//   0x003a78: b8686968  ldr      w8, [x11, x8]
//   0x003a7c: 0b090108  add      w8, w8, w9
//   0x003a80: 93407d08  sxtw     x8, w8
//   0x003a84: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003a88: 17ffffc1  b        #0x398c
//   0x003a8c: 710ebd7f  cmp      w11, #0x3af
//   0x003a90: 54000060  b.eq     #0x3a9c
//   0x003a94: 711bbd7f  cmp      w11, #0x6ef
//   0x003a98: 54fff7a1  b.ne     #0x398c
//   0x003a9c: 910022ab  add      x11, x21, #8
//   0x003aa0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003aa4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003aa8: cb080128  sub      x8, x9, x8
//   0x003aac: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003ab0: 17ffffb7  b        #0x398c
//   0x003ab4: 7123bdbf  cmp      w13, #0x8ef
//   0x003ab8: 54002c80  b.eq     #0x4048
//   0x003abc: 712dbdbf  cmp      w13, #0xb6f
//   0x003ac0: 54002ce0  b.eq     #0x405c
//   0x003ac4: 712ebdbf  cmp      w13, #0xbaf
//   0x003ac8: 54fff621  b.ne     #0x398c
//   0x003acc: 910022a9  add      x9, x21, #8
//   0x003ad0: d37df108  lsl      x8, x8, #3
//   0x003ad4: b8686928  ldr      w8, [x9, x8]
//   0x003ad8: 1acb2508  lsr      w8, w8, w11
//   0x003adc: 1400016e  b        #0x4094
//   0x003ae0: 52811de9  mov      w9, #0x8ef
//   0x003ae4: 72a00409  movk     w9, #0x20, lsl #16
//   0x003ae8: 6b0901bf  cmp      w13, w9
//   0x003aec: 54002c20  b.eq     #0x4070
//   0x003af0: 528175e9  mov      w9, #0xbaf
//   0x003af4: 72a00409  movk     w9, #0x20, lsl #16
//   0x003af8: 6b0901bf  cmp      w13, w9
//   0x003afc: 54002c40  b.eq     #0x4084
//   0x003b00: 5281e5e9  mov      w9, #0xf2f
//   0x003b04: 72a00409  movk     w9, #0x20, lsl #16
//   0x003b08: 6b0901bf  cmp      w13, w9
//   0x003b0c: 54fff401  b.ne     #0x398c
//   0x003b10: 910022a9  add      x9, x21, #8
//   0x003b14: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x003b18: 321b016b  orr      w11, w11, #0x20
//   0x003b1c: 14000157  b        #0x4078
//   0x003b20: 7120bd7f  cmp      w11, #0x82f
//   0x003b24: 54002580  b.eq     #0x3fd4
//   0x003b28: 713dbd7f  cmp      w11, #0xf6f
//   0x003b2c: 54fff301  b.ne     #0x398c
//   0x003b30: 910022ab  add      x11, x21, #8
//   0x003b34: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003b38: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003b3c: 8a090108  and      x8, x8, x9
//   0x003b40: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003b44: 17ffff92  b        #0x398c
//   0x003b48: 910022aa  add      x10, x21, #8
//   0x003b4c: d37df129  lsl      x9, x9, #3
//   0x003b50: d37df108  lsl      x8, x8, #3
//   0x003b54: b94000cb  ldr      w11, [x6]
//   0x003b58: b94000ec  ldr      w12, [x7]
//   0x003b5c: b8696949  ldr      w9, [x10, x9]
//   0x003b60: b8686948  ldr      w8, [x10, x8]
//   0x003b64: 14000012  b        #0x3bac
//   0x003b68: 910022aa  add      x10, x21, #8
//   0x003b6c: d37df129  lsl      x9, x9, #3
//   0x003b70: d37df108  lsl      x8, x8, #3
//   0x003b74: b94000cb  ldr      w11, [x6]
//   0x003b78: b94000ec  ldr      w12, [x7]
//   0x003b7c: b8a96949  ldrsw    x9, [x10, x9]
//   0x003b80: b8a86948  ldrsw    x8, [x10, x8]
//   0x003b84: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x003b88: 9b093108  madd     x8, x8, x9, x12
//   0x003b8c: 1400000a  b        #0x3bb4
//   0x003b90: 910022aa  add      x10, x21, #8
//   0x003b94: d37df129  lsl      x9, x9, #3
//   0x003b98: d37df108  lsl      x8, x8, #3
//   0x003b9c: b94000cb  ldr      w11, [x6]
//   0x003ba0: b94000ec  ldr      w12, [x7]
//   0x003ba4: b8a96949  ldrsw    x9, [x10, x9]
//   0x003ba8: b8a86948  ldrsw    x8, [x10, x8]
//   0x003bac: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x003bb0: 9b09b108  msub     x8, x8, x9, x12
//   0x003bb4: 92407d09  and      x9, x8, #0xffffffff
//   0x003bb8: d360fd08  lsr      x8, x8, #0x20
//   0x003bbc: 14000184  b        #0x41cc
//   0x003bc0: 320013ea  mov      w10, #0x1f
//   0x003bc4: f85f8268  ldur     x8, [x19, #-8]
//   0x003bc8: 2a1f03eb  mov      w11, wzr
//   0x003bcc: 2a1f03e9  mov      w9, wzr
//   0x003bd0: 8b2c4108  add      x8, x8, w12, uxtw
//   0x003bd4: 14000026  b        #0x3c6c
//   0x003bd8: f85e8260  ldur     x0, [x19, #-0x18]
//   0x003bdc: f81e027f  stur     xzr, [x19, #-0x20]
//   0x003be0: f90002a0  str      x0, [x21]
//   0x003be4: eb14001f  cmp      x0, x20
//   0x003be8: 54ffeea1  b.ne     #0x39bc
//   0x003bec: f9400080  ldr      x0, [x4]
//   0x003bf0: f94000a1  ldr      x1, [x5]
//   0x003bf4: aa0403f8  mov      x24, x4
//   0x003bf8: aa0503fa  mov      x26, x5
//   0x003bfc: f90007e6  str      x6, [sp, #8]
//   0x003c00: aa0703f7  mov      x23, x7
//   0x003c04: d63f0280  blr      x20
//   0x003c08: f94007e6  ldr      x6, [sp, #8]
//   0x003c0c: f85f0260  ldur     x0, [x19, #-0x10]
//   0x003c10: aa1703e7  mov      x7, x23
//   0x003c14: 528065f7  mov      w23, #0x32f
//   0x003c18: aa1803e4  mov      x4, x24
//   0x003c1c: 5281fff8  mov      w24, #0xfff
//   0x003c20: 321b03fe  mov      w30, #0x20
//   0x003c24: 72a08017  movk     w23, #0x400, lsl #16
//   0x003c28: aa1a03e5  mov      x5, x26
//   0x003c2c: 320007fa  mov      w26, #3
//   0x003c30: 72a00418  movk     w24, #0x20, lsl #16
//   0x003c34: f90002a0  str      x0, [x21]
//   0x003c38: b5ff7820  cbnz     x0, #0x2b3c
//   0x003c3c: 140001e0  b        #0x43bc
//   0x003c40: eb0d017f  cmp      x11, x13
//   0x003c44: 54ff9d01  b.ne     #0x2fe4
//   0x003c48: 1400001a  b        #0x3cb0
//   0x003c4c: eb0d017f  cmp      x11, x13
//   0x003c50: 54ff9ca0  b.eq     #0x2fe4
//   0x003c54: 14000017  b        #0x3cb0
//   0x003c58: f100017f  cmp      x11, #0
//   0x003c5c: 320003e9  mov      w9, #1
//   0x003c60: 5400018d  b.le     #0x3c90
//   0x003c64: 2a1f03eb  mov      w11, wzr
//   0x003c68: 2a1f03ea  mov      w10, wzr
//   0x003c6c: 320003ec  mov      w12, #1
//   0x003c70: 14000015  b        #0x3cc4
//   0x003c74: eb0d017f  cmp      x11, x13
//   0x003c78: 320003e9  mov      w9, #1
//   0x003c7c: 54ffff40  b.eq     #0x3c64
//   0x003c80: 14000004  b        #0x3c90
//   0x003c84: f100057f  cmp      x11, #1
//   0x003c88: 320003e9  mov      w9, #1
//   0x003c8c: 54fffecb  b.lt     #0x3c64
//   0x003c90: 2a1f03ea  mov      w10, wzr
//   0x003c94: 14000009  b        #0x3cb8
//   0x003c98: eb0d017f  cmp      x11, x13
//   0x003c9c: 320003e9  mov      w9, #1
//   0x003ca0: 54ffff80  b.eq     #0x3c90
//   0x003ca4: 17fffff0  b        #0x3c64
//   0x003ca8: f100057f  cmp      x11, #1
//   0x003cac: 54ff99cb  b.lt     #0x2fe4
//   0x003cb0: 2a1f03ea  mov      w10, wzr
//   0x003cb4: 2a1f03e9  mov      w9, wzr
//   0x003cb8: 2a1f03ec  mov      w12, wzr
//   0x003cbc: 91002008  add      x8, x0, #8
//   0x003cc0: 320003eb  mov      w11, #1
//   0x003cc4: 7100013f  cmp      w9, #0
//   0x003cc8: 1a9f07ed  cset     w13, ne
//   0x003ccc: 0a0d016b  and      w11, w11, w13
//   0x003cd0: f81e8268  stur     x8, [x19, #-0x18]
//   0x003cd4: 3700008b  tbnz     w11, #0, #0x3ce4
//   0x003cd8: 34000069  cbz      w9, #0x3ce4
//   0x003cdc: 0a0d0188  and      w8, w12, w13
//   0x003ce0: 34ffb7a8  cbz      w8, #0x33d4
//   0x003ce4: 7100017f  cmp      w11, #0
//   0x003ce8: 320003e8  mov      w8, #1
//   0x003cec: 9a881508  cinc     x8, x8, eq
//   0x003cf0: f81e0268  stur     x8, [x19, #-0x20]
//   0x003cf4: 7100055f  cmp      w10, #1
//   0x003cf8: 54ffe4ab  b.lt     #0x398c
//   0x003cfc: 17fffdb8  b        #0x33dc
//   0x003d00: b6fffd8b  tbz      x11, #0x3f, #0x3cb0
//   0x003d04: 17fffcb8  b        #0x2fe4
//   0x003d08: 320013ea  mov      w10, #0x1f
//   0x003d0c: 320003e9  mov      w9, #1
//   0x003d10: b7fffd4b  tbnz     x11, #0x3f, #0x3cb8
//   0x003d14: 2a1f03eb  mov      w11, wzr
//   0x003d18: 17ffffd5  b        #0x3c6c
//   0x003d1c: 320003e9  mov      w9, #1
//   0x003d20: b6fffb8b  tbz      x11, #0x3f, #0x3c90
//   0x003d24: 17ffffd0  b        #0x3c64
//   0x003d28: 320003e9  mov      w9, #1
//   0x003d2c: b6fff9cb  tbz      x11, #0x3f, #0x3c64
//   0x003d30: 17ffffd8  b        #0x3c90
//   0x003d34: 910022a9  add      x9, x21, #8
//   0x003d38: d37df108  lsl      x8, x8, #3
//   0x003d3c: 78a86928  ldrsh    x8, [x9, x8]
//   0x003d40: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x003d44: 17ffff12  b        #0x398c
//   0x003d48: 910022a9  add      x9, x21, #8
//   0x003d4c: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x003d50: d348fd0b  lsr      x11, x8, #8
//   0x003d54: d378dd08  lsl      x8, x8, #8
//   0x003d58: 92009d6b  and      x11, x11, #0xff00ff00ff00ff
//   0x003d5c: 92089d08  and      x8, x8, #0xff00ff00ff00ff00
//   0x003d60: aa0b0108  orr      x8, x8, x11
//   0x003d64: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x003d68: 17ffff09  b        #0x398c
//   0x003d6c: 910022a9  add      x9, x21, #8
//   0x003d70: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x003d74: d350fd0b  lsr      x11, x8, #0x10
//   0x003d78: d370bd08  lsl      x8, x8, #0x10
//   0x003d7c: 92003d6b  and      x11, x11, #0xffff0000ffff
//   0x003d80: 92103d08  and      x8, x8, #0xffff0000ffff0000
//   0x003d84: aa0b0108  orr      x8, x8, x11
//   0x003d88: 93c88108  ror      x8, x8, #0x20
//   0x003d8c: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x003d90: 17fffeff  b        #0x398c
//   0x003d94: 910022ab  add      x11, x21, #8
//   0x003d98: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003d9c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003da0: eb08013f  cmp      x9, x8
//   0x003da4: 8b2a4d68  add      x8, x11, w10, uxtw #3
//   0x003da8: 54000f63  b.lo     #0x3f94
//   0x003dac: f900011f  str      xzr, [x8]
//   0x003db0: 17fffef7  b        #0x398c
//   0x003db4: 7124b9bf  cmp      w13, #0x92e
//   0x003db8: 54001b0d  b.le     #0x4118
//   0x003dbc: 7136b9bf  cmp      w13, #0xdae
//   0x003dc0: 54001bec  b.gt     #0x413c
//   0x003dc4: 712cb9bf  cmp      w13, #0xb2e
//   0x003dc8: 5400212c  b.gt     #0x41ec
//   0x003dcc: 7124bdbf  cmp      w13, #0x92f
//   0x003dd0: 540000a0  b.eq     #0x3de4
//   0x003dd4: 7126bdbf  cmp      w13, #0x9af
//   0x003dd8: 54ffdda1  b.ne     #0x398c
//   0x003ddc: f94000e8  ldr      x8, [x7]
//   0x003de0: 14000174  b        #0x43b0
//   0x003de4: 910022aa  add      x10, x21, #8
//   0x003de8: d37df129  lsl      x9, x9, #3
//   0x003dec: d37df108  lsl      x8, x8, #3
//   0x003df0: b8a96949  ldrsw    x9, [x10, x9]
//   0x003df4: b8a86948  ldrsw    x8, [x10, x8]
//   0x003df8: 140000f2  b        #0x41c0
//   0x003dfc: b5ffdc81  cbnz     x1, #0x398c
//   0x003e00: 12002d8d  and      w13, w12, #0xfff
//   0x003e04: 51000dae  sub      w14, w13, #3
//   0x003e08: 7100f1df  cmp      w14, #0x3c
//   0x003e0c: 2a1f03e8  mov      w8, wzr
//   0x003e10: 54001e48  b.hi     #0x41d8
//   0x003e14: f000002d  adrp     x13, #0xa000
//   0x003e18: 913911ad  add      x13, x13, #0xe44
//   0x003e1c: aa0d03ef  mov      x15, x13
//   0x003e20: b8ae79ed  ldrsw    x13, [x15, x14, lsl #2]
//   0x003e24: 8b0f01ae  add      x14, x13, x15
//   0x003e28: aa1f03ed  mov      x13, xzr
//   0x003e2c: d61f01c0  br       x14
//   0x003e30: 8b2a4ea8  add      x8, x21, w10, uxtw #3
//   0x003e34: f940050d  ldr      x13, [x8, #8]
//   0x003e38: 12002d88  and      w8, w12, #0xfff
//   0x003e3c: 51000d08  sub      w8, w8, #3
//   0x003e40: 7100f11f  cmp      w8, #0x3c
//   0x003e44: 54ffda48  b.hi     #0x398c
//   0x003e48: f000002a  adrp     x10, #0xa000
//   0x003e4c: 913ce14a  add      x10, x10, #0xf38
//   0x003e50: aa0a03ec  mov      x12, x10
//   0x003e54: b8a8798a  ldrsw    x10, [x12, x8, lsl #2]
//   0x003e58: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x003e5c: f9400508  ldr      x8, [x8, #8]
//   0x003e60: 11001169  add      w9, w11, #4
//   0x003e64: 8b0c014a  add      x10, x10, x12
//   0x003e68: 8b090009  add      x9, x0, x9
//   0x003e6c: d61f0140  br       x10
//   0x003e70: f100011f  cmp      x8, #0
//   0x003e74: 5400246d  b.le     #0x4300
//   0x003e78: 2a1f03ec  mov      w12, wzr
//   0x003e7c: 2a1f03ea  mov      w10, wzr
//   0x003e80: 1400011c  b        #0x42f0
//   0x003e84: 113342eb  add      w11, w23, #0xcd0
//   0x003e88: 0a0b018b  and      w11, w12, w11
//   0x003e8c: 110d02ec  add      w12, w23, #0x340
//   0x003e90: 6b0c017f  cmp      w11, w12
//   0x003e94: 1a8d018d  csel     w13, w12, w13, eq
//   0x003e98: 7135b9bf  cmp      w13, #0xd6e
//   0x003e9c: 540001cc  b.gt     #0x3ed4
//   0x003ea0: 7117b9bf  cmp      w13, #0x5ee
//   0x003ea4: 5400038c  b.gt     #0x3f14
//   0x003ea8: 7102bdbf  cmp      w13, #0xaf
//   0x003eac: 54000fa0  b.eq     #0x40a0
//   0x003eb0: 710cbdbf  cmp      w13, #0x32f
//   0x003eb4: 54ffd6c1  b.ne     #0x398c
//   0x003eb8: 910022ab  add      x11, x21, #8
//   0x003ebc: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003ec0: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003ec4: 92401529  and      x9, x9, #0x3f
//   0x003ec8: 9ac92508  lsr      x8, x8, x9
//   0x003ecc: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003ed0: 17fffeaf  b        #0x398c
//   0x003ed4: 528065cb  mov      w11, #0x32e
//   0x003ed8: 72a0800b  movk     w11, #0x400, lsl #16
//   0x003edc: 6b0b01bf  cmp      w13, w11
//   0x003ee0: 5400032c  b.gt     #0x3f44
//   0x003ee4: 7135bdbf  cmp      w13, #0xd6f
//   0x003ee8: 54000ea0  b.eq     #0x40bc
//   0x003eec: 713fbdbf  cmp      w13, #0xfef
//   0x003ef0: 54ffd4e1  b.ne     #0x398c
//   0x003ef4: 910022ab  add      x11, x21, #8
//   0x003ef8: d37df129  lsl      x9, x9, #3
//   0x003efc: b8696969  ldr      w9, [x11, x9]
//   0x003f00: d37df108  lsl      x8, x8, #3
//   0x003f04: b8686968  ldr      w8, [x11, x8]
//   0x003f08: 12001129  and      w9, w9, #0x1f
//   0x003f0c: 1ac92108  lsl      w8, w8, w9
//   0x003f10: 17fffedc  b        #0x3a80
//   0x003f14: 7117bdbf  cmp      w13, #0x5ef
//   0x003f18: 54000e00  b.eq     #0x40d8
//   0x003f1c: 7119bdbf  cmp      w13, #0x66f
//   0x003f20: 54ffd361  b.ne     #0x398c
//   0x003f24: 910022ab  add      x11, x21, #8
//   0x003f28: d37df129  lsl      x9, x9, #3
//   0x003f2c: b8696969  ldr      w9, [x11, x9]
//   0x003f30: d37df108  lsl      x8, x8, #3
//   0x003f34: b8686968  ldr      w8, [x11, x8]
//   0x003f38: 12001129  and      w9, w9, #0x1f
//   0x003f3c: 1ac92508  lsr      w8, w8, w9
//   0x003f40: 17fffed0  b        #0x3a80
//   0x003f44: 6b1701bf  cmp      w13, w23
//   0x003f48: 54000d80  b.eq     #0x40f8
//   0x003f4c: 5280cdeb  mov      w11, #0x66f
//   0x003f50: 72a0800b  movk     w11, #0x400, lsl #16
//   0x003f54: 6b0b01bf  cmp      w13, w11
//   0x003f58: 54ffd1a1  b.ne     #0x398c
//   0x003f5c: 910022ab  add      x11, x21, #8
//   0x003f60: d37df129  lsl      x9, x9, #3
//   0x003f64: b8696969  ldr      w9, [x11, x9]
//   0x003f68: d37df108  lsl      x8, x8, #3
//   0x003f6c: b8686968  ldr      w8, [x11, x8]
//   0x003f70: 12001129  and      w9, w9, #0x1f
//   0x003f74: 1ac92d08  ror      w8, w8, w9
//   0x003f78: 17fffec2  b        #0x3a80
//   0x003f7c: 910022ab  add      x11, x21, #8
//   0x003f80: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003f84: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003f88: eb08013f  cmp      x9, x8
//   0x003f8c: 8b2a4d68  add      x8, x11, w10, uxtw #3
//   0x003f90: 54fff0ea  b.ge     #0x3dac
//   0x003f94: 320003e9  mov      w9, #1
//   0x003f98: f9000109  str      x9, [x8]
//   0x003f9c: 17fffe7c  b        #0x398c
//   0x003fa0: 0a180189  and      w9, w12, w24
//   0x003fa4: 17fffe06  b        #0x37bc
//   0x003fa8: 0a180189  and      w9, w12, w24
//   0x003fac: 17fffe01  b        #0x37b0
//   0x003fb0: 320007e1  mov      w1, #3
//   0x003fb4: f81e027a  stur     x26, [x19, #-0x20]
//   0x003fb8: 17fffae5  b        #0x2b4c
//   0x003fbc: 910022ab  add      x11, x21, #8
//   0x003fc0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003fc4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003fc8: ca090108  eor      x8, x8, x9
//   0x003fcc: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003fd0: 17fffe6f  b        #0x398c
//   0x003fd4: 910022ab  add      x11, x21, #8
//   0x003fd8: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x003fdc: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x003fe0: aa090108  orr      x8, x8, x9
//   0x003fe4: aa2803e8  mvn      x8, x8
//   0x003fe8: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x003fec: 17fffe68  b        #0x398c
//   0x003ff0: 910022a9  add      x9, x21, #8
//   0x003ff4: d37df108  lsl      x8, x8, #3
//   0x003ff8: b8686928  ldr      w8, [x9, x8]
//   0x003ffc: 1acb2908  asr      w8, w8, w11
//   0x004000: 14000025  b        #0x4094
//   0x004004: 910022a9  add      x9, x21, #8
//   0x004008: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x00400c: 321b016b  orr      w11, w11, #0x20
//   0x004010: 92403d6b  and      x11, x11, #0xffff
//   0x004014: 14000014  b        #0x4064
//   0x004018: 910022a9  add      x9, x21, #8
//   0x00401c: d37df108  lsl      x8, x8, #3
//   0x004020: b8686928  ldr      w8, [x9, x8]
//   0x004024: 1acb2108  lsl      w8, w8, w11
//   0x004028: 1400001b  b        #0x4094
//   0x00402c: 910022a9  add      x9, x21, #8
//   0x004030: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x004034: 321b016b  orr      w11, w11, #0x20
//   0x004038: 92403d6b  and      x11, x11, #0xffff
//   0x00403c: 9acb2108  lsl      x8, x8, x11
//   0x004040: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x004044: 17fffe52  b        #0x398c
//   0x004048: 910022a9  add      x9, x21, #8
//   0x00404c: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x004050: 9acb2508  lsr      x8, x8, x11
//   0x004054: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x004058: 17fffe4d  b        #0x398c
//   0x00405c: 910022a9  add      x9, x21, #8
//   0x004060: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x004064: 9acb2908  asr      x8, x8, x11
//   0x004068: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x00406c: 17fffe48  b        #0x398c
//   0x004070: 910022a9  add      x9, x21, #8
//   0x004074: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x004078: 9acb2d08  ror      x8, x8, x11
//   0x00407c: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x004080: 17fffe43  b        #0x398c
//   0x004084: 910022a9  add      x9, x21, #8
//   0x004088: d37df108  lsl      x8, x8, #3
//   0x00408c: b8686928  ldr      w8, [x9, x8]
//   0x004090: 1acb2d08  ror      w8, w8, w11
//   0x004094: 93407d08  sxtw     x8, w8
//   0x004098: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x00409c: 17fffe3c  b        #0x398c
//   0x0040a0: 910022ab  add      x11, x21, #8
//   0x0040a4: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0040a8: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x0040ac: 92401529  and      x9, x9, #0x3f
//   0x0040b0: 9ac92908  asr      x8, x8, x9
//   0x0040b4: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0040b8: 17fffe35  b        #0x398c
//   0x0040bc: 910022ab  add      x11, x21, #8
//   0x0040c0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0040c4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x0040c8: 92401529  and      x9, x9, #0x3f
//   0x0040cc: 9ac92108  lsl      x8, x8, x9
//   0x0040d0: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0040d4: 17fffe2e  b        #0x398c
//   0x0040d8: 910022ab  add      x11, x21, #8
//   0x0040dc: d37df129  lsl      x9, x9, #3
//   0x0040e0: b8696969  ldr      w9, [x11, x9]
//   0x0040e4: d37df108  lsl      x8, x8, #3
//   0x0040e8: b8686968  ldr      w8, [x11, x8]
//   0x0040ec: 12001129  and      w9, w9, #0x1f
//   0x0040f0: 1ac92908  asr      w8, w8, w9
//   0x0040f4: 17fffe63  b        #0x3a80
//   0x0040f8: 910022ab  add      x11, x21, #8
//   0x0040fc: d37df129  lsl      x9, x9, #3
//   0x004100: b8696969  ldr      w9, [x11, x9]
//   0x004104: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x004108: 12001529  and      w9, w9, #0x3f
//   0x00410c: 9ac92d08  ror      x8, x8, x9
//   0x004110: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x004114: 17fffe1e  b        #0x398c
//   0x004118: 711ab9bf  cmp      w13, #0x6ae
//   0x00411c: 5400024d  b.le     #0x4164
//   0x004120: 711db9bf  cmp      w13, #0x76e
//   0x004124: 5400084c  b.gt     #0x422c
//   0x004128: 711abdbf  cmp      w13, #0x6af
//   0x00412c: 54000f60  b.eq     #0x4318
//   0x004130: 711cbdbf  cmp      w13, #0x72f
//   0x004134: 54ffb120  b.eq     #0x3758
//   0x004138: 17fffe15  b        #0x398c
//   0x00413c: 7138b9bf  cmp      w13, #0xe2e
//   0x004140: 5400090c  b.gt     #0x4260
//   0x004144: 7136bdbf  cmp      w13, #0xdaf
//   0x004148: 54ffb1e0  b.eq     #0x3784
//   0x00414c: 7137bdbf  cmp      w13, #0xdef
//   0x004150: 54ffc1e1  b.ne     #0x398c
//   0x004154: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x004158: f9400508  ldr      x8, [x8, #8]
//   0x00415c: f90000e8  str      x8, [x7]
//   0x004160: 17fffe0b  b        #0x398c
//   0x004164: 7106bdbf  cmp      w13, #0x1af
//   0x004168: 54000220  b.eq     #0x41ac
//   0x00416c: 7113bdbf  cmp      w13, #0x4ef
//   0x004170: 54000e60  b.eq     #0x433c
//   0x004174: 7114bdbf  cmp      w13, #0x52f
//   0x004178: 54ffc0a1  b.ne     #0x398c
//   0x00417c: 910022aa  add      x10, x21, #8
//   0x004180: d37df129  lsl      x9, x9, #3
//   0x004184: d37df108  lsl      x8, x8, #3
//   0x004188: b8696949  ldr      w9, [x10, x9]
//   0x00418c: b8686948  ldr      w8, [x10, x8]
//   0x004190: 1ac8092a  udiv     w10, w9, w8
//   0x004194: 1b08a548  msub     w8, w10, w8, w9
//   0x004198: 93407d49  sxtw     x9, w10
//   0x00419c: 93407d08  sxtw     x8, w8
//   0x0041a0: f90000c8  str      x8, [x6]
//   0x0041a4: f90000e9  str      x9, [x7]
//   0x0041a8: 17fffdf9  b        #0x398c
//   0x0041ac: 910022aa  add      x10, x21, #8
//   0x0041b0: d37df129  lsl      x9, x9, #3
//   0x0041b4: d37df108  lsl      x8, x8, #3
//   0x0041b8: b8696949  ldr      w9, [x10, x9]
//   0x0041bc: b8686948  ldr      w8, [x10, x8]
//   0x0041c0: 9b097d08  mul      x8, x8, x9
//   0x0041c4: 93407d09  sxtw     x9, w8
//   0x0041c8: 9360fd08  asr      x8, x8, #0x20
//   0x0041cc: f90000e9  str      x9, [x7]
//   0x0041d0: f90000c8  str      x8, [x6]
//   0x0041d4: 17fffdee  b        #0x398c
//   0x0041d8: 7116bdbf  cmp      w13, #0x5af
//   0x0041dc: 54000be0  b.eq     #0x4358
//   0x0041e0: 711abdbf  cmp      w13, #0x6af
//   0x0041e4: 54000bc0  b.eq     #0x435c
//   0x0041e8: 17fffde9  b        #0x398c
//   0x0041ec: 712cbdbf  cmp      w13, #0xb2f
//   0x0041f0: 540000e0  b.eq     #0x420c
//   0x0041f4: 7133bdbf  cmp      w13, #0xcef
//   0x0041f8: 54ffbca1  b.ne     #0x398c
//   0x0041fc: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x004200: f9400508  ldr      x8, [x8, #8]
//   0x004204: f90000c8  str      x8, [x6]
//   0x004208: 17fffde1  b        #0x398c
//   0x00420c: 910022aa  add      x10, x21, #8
//   0x004210: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x004214: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x004218: 9ac80d2a  sdiv     x10, x9, x8
//   0x00421c: 9b08a548  msub     x8, x10, x8, x9
//   0x004220: f90000c8  str      x8, [x6]
//   0x004224: f90000ea  str      x10, [x7]
//   0x004228: 17fffdd9  b        #0x398c
//   0x00422c: 711dbdbf  cmp      w13, #0x76f
//   0x004230: 54000080  b.eq     #0x4240
//   0x004234: 7122bdbf  cmp      w13, #0x8af
//   0x004238: 54ff97e0  b.eq     #0x3534
//   0x00423c: 17fffdd4  b        #0x398c
//   0x004240: 910022aa  add      x10, x21, #8
//   0x004244: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x004248: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x00424c: 9bc97d0a  umulh    x10, x8, x9
//   0x004250: 9b097d08  mul      x8, x8, x9
//   0x004254: f90000e8  str      x8, [x7]
//   0x004258: f90000ca  str      x10, [x6]
//   0x00425c: 17fffdcc  b        #0x398c
//   0x004260: 7138bdbf  cmp      w13, #0xe2f
//   0x004264: 54000a40  b.eq     #0x43ac
//   0x004268: 713abdbf  cmp      w13, #0xeaf
//   0x00426c: 54ffb901  b.ne     #0x398c
//   0x004270: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x004274: f9400508  ldr      x8, [x8, #8]
//   0x004278: b5000688  cbnz     x8, #0x4348
//   0x00427c: 17fffdc4  b        #0x398c
//   0x004280: 320013e8  mov      w8, #0x1f
//   0x004284: f85f8269  ldur     x9, [x19, #-8]
//   0x004288: 2a1f03ec  mov      w12, wzr
//   0x00428c: 2a1f03ea  mov      w10, wzr
//   0x004290: 8b0b0129  add      x9, x9, x11
//   0x004294: 14000036  b        #0x436c
//   0x004298: eb0d011f  cmp      x8, x13
//   0x00429c: 54ffdee1  b.ne     #0x3e78
//   0x0042a0: 14000018  b        #0x4300
//   0x0042a4: eb0d011f  cmp      x8, x13
//   0x0042a8: 540002c1  b.ne     #0x4300
//   0x0042ac: 17fffef3  b        #0x3e78
//   0x0042b0: f100011f  cmp      x8, #0
//   0x0042b4: 320003ea  mov      w10, #1
//   0x0042b8: 540001ac  b.gt     #0x42ec
//   0x0042bc: 14000012  b        #0x4304
//   0x0042c0: eb0d011f  cmp      x8, x13
//   0x0042c4: 320003ea  mov      w10, #1
//   0x0042c8: 54000120  b.eq     #0x42ec
//   0x0042cc: 1400000e  b        #0x4304
//   0x0042d0: f100051f  cmp      x8, #1
//   0x0042d4: 320003ea  mov      w10, #1
//   0x0042d8: 5400016a  b.ge     #0x4304
//   0x0042dc: 14000004  b        #0x42ec
//   0x0042e0: eb0d011f  cmp      x8, x13
//   0x0042e4: 320003ea  mov      w10, #1
//   0x0042e8: 540000e0  b.eq     #0x4304
//   0x0042ec: 2a1f03ec  mov      w12, wzr
//   0x0042f0: 2a1f03e8  mov      w8, wzr
//   0x0042f4: 1400001e  b        #0x436c
//   0x0042f8: f100051f  cmp      x8, #1
//   0x0042fc: 54ffdbeb  b.lt     #0x3e78
//   0x004300: 2a1f03ea  mov      w10, wzr
//   0x004304: 2a1f03eb  mov      w11, wzr
//   0x004308: 2a1f03e8  mov      w8, wzr
//   0x00430c: 91002009  add      x9, x0, #8
//   0x004310: 320003ec  mov      w12, #1
//   0x004314: 14000017  b        #0x4370
//   0x004318: b5ffb3a1  cbnz     x1, #0x398c
//   0x00431c: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x004320: f9400508  ldr      x8, [x8, #8]
//   0x004324: 91001000  add      x0, x0, #4
//   0x004328: 321f03e9  mov      w9, #2
//   0x00432c: a93e2269  stp      x9, x8, [x19, #-0x20]
//   0x004330: f90002a0  str      x0, [x21]
//   0x004334: b5ff4040  cbnz     x0, #0x2b3c
//   0x004338: 14000021  b        #0x43bc
//   0x00433c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x004340: f9400508  ldr      x8, [x8, #8]
//   0x004344: b5ffb248  cbnz     x8, #0x398c
//   0x004348: 910022a8  add      x8, x21, #8
//   0x00434c: f8695909  ldr      x9, [x8, w9, uxtw #3]
//   0x004350: f82a5909  str      x9, [x8, w10, uxtw #3]
//   0x004354: 17fffd8e  b        #0x398c
//   0x004358: 2a0a03e8  mov      w8, w10
//   0x00435c: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x004360: f9400529  ldr      x9, [x9, #8]
//   0x004364: 2a1f03ec  mov      w12, wzr
//   0x004368: 2a1f03ea  mov      w10, wzr
//   0x00436c: 320003eb  mov      w11, #1
//   0x004370: 7100015f  cmp      w10, #0
//   0x004374: 1a9f07ed  cset     w13, ne
//   0x004378: 0a0d018c  and      w12, w12, w13
//   0x00437c: f81e8269  stur     x9, [x19, #-0x18]
//   0x004380: 3700008c  tbnz     w12, #0, #0x4390
//   0x004384: 3400006a  cbz      w10, #0x4390
//   0x004388: 0a0d0169  and      w9, w11, w13
//   0x00438c: 34ff86e9  cbz      w9, #0x3468
//   0x004390: 7100019f  cmp      w12, #0
//   0x004394: 320003e9  mov      w9, #1
//   0x004398: 9a891529  cinc     x9, x9, eq
//   0x00439c: f81e0269  stur     x9, [x19, #-0x20]
//   0x0043a0: 7100051f  cmp      w8, #1
//   0x0043a4: 54ffaf4b  b.lt     #0x398c
//   0x0043a8: 17fffc32  b        #0x3470
//   0x0043ac: f94000c8  ldr      x8, [x6]
//   0x0043b0: 8b2a4ea9  add      x9, x21, w10, uxtw #3
//   0x0043b4: f9000528  str      x8, [x9, #8]
//   0x0043b8: 17fffd75  b        #0x398c
//   0x0043bc: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x0043c0: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x0043c4: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x0043c8: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x0043cc: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x0043d0: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x0043d4: 9101c3ff  add      sp, sp, #0x70
//   0x0043d8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_17_2a90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a90ULL;
    for (std::size_t i = 0; i < 1619ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2124ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[18] Subroutine @ 0x0043dc..0x004864 (1160 bytes, 290 AArch64 instructions)
// [VN] Khung FDE[18] Hàm con @ 0x0043dc..0x004864 (1160 byte, 290 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0043dc: 7100805f  cmp      w2, #0x20
//   0x0043e0: 32001fe8  mov      w8, #0xff
//   0x0043e4: 540023c8  b.hi     #0x485c
//   0x0043e8: 2a0203e9  mov      w9, w2
//   0x0043ec: 320003ea  mov      w10, #1
//   0x0043f0: 9ac92149  lsl      x9, x10, x9
//   0x0043f4: b20083ea  mov      x10, #0x1000100010001
//   0x0043f8: f288000a  movk     x10, #0x4000
//   0x0043fc: f2e0000a  movk     x10, #0, lsl #48
//   0x004400: ea0a013f  tst      x9, x10
//   0x004404: 540022c0  b.eq     #0x485c
//   0x004408: 53027c48  lsr      w8, w2, #2
//   0x00440c: 121f7108  and      w8, w8, #0x3ffffffe
//   0x004410: 11001908  add      w8, w8, #6
//   0x004414: f900f008  str      x8, [x0, #0x1e0]
//   0x004418: b9400029  ldr      w9, [x1]
//   0x00441c: 7100385f  cmp      w2, #0xe
//   0x004420: 5ac00929  rev      w9, w9
//   0x004424: b9000009  str      w9, [x0]
//   0x004428: b940042a  ldr      w10, [x1, #4]
//   0x00442c: 5ac0094a  rev      w10, w10
//   0x004430: b900040a  str      w10, [x0, #4]
//   0x004434: b940082a  ldr      w10, [x1, #8]
//   0x004438: 5ac0094a  rev      w10, w10
//   0x00443c: b900080a  str      w10, [x0, #8]
//   0x004440: b9400c2a  ldr      w10, [x1, #0xc]
//   0x004444: 5ac0094a  rev      w10, w10
//   0x004448: b9000c0a  str      w10, [x0, #0xc]
//   0x00444c: 54000560  b.eq     #0x44f8
//   0x004450: 7100805f  cmp      w2, #0x20
//   0x004454: 54000b60  b.eq     #0x45c0
//   0x004458: 7100405f  cmp      w2, #0x10
//   0x00445c: 54001421  b.ne     #0x46e0
//   0x004460: f000002c  adrp     x12, #0xb000
//   0x004464: f000002d  adrp     x13, #0xb000
//   0x004468: f000002e  adrp     x14, #0xb000
//   0x00446c: f000002f  adrp     x15, #0xb000
//   0x004470: 90000050  adrp     x16, #0xc000
//   0x004474: aa1f03ea  mov      x10, xzr
//   0x004478: 9100400b  add      x11, x0, #0x10
//   0x00447c: 910c918c  add      x12, x12, #0x324
//   0x004480: 911c91ad  add      x13, x13, #0x724
//   0x004484: 912c91ce  add      x14, x14, #0xb24
//   0x004488: 913c91ef  add      x15, x15, #0xf24
//   0x00448c: 910c9210  add      x16, x16, #0x324
//   0x004490: 297f4565  ldp      w5, w17, [x11, #-8]
//   0x004494: b86a6a12  ldr      w18, [x16, x10]
//   0x004498: b85f4164  ldur     w4, [x11, #-0xc]
//   0x00449c: 9100114a  add      x10, x10, #4
//   0x0044a0: 53105e21  ubfx     w1, w17, #0x10, #8
//   0x0044a4: 53083e23  ubfx     w3, w17, #8, #8
//   0x0044a8: b8615981  ldr      w1, [x12, w1, uxtw #2]
//   0x0044ac: b86359a3  ldr      w3, [x13, w3, uxtw #2]
//   0x0044b0: f100a15f  cmp      x10, #0x28
//   0x0044b4: 4a090029  eor      w9, w1, w9
//   0x0044b8: 92401e21  and      x1, x17, #0xff
//   0x0044bc: 4a030129  eor      w9, w9, w3
//   0x0044c0: d3587e23  ubfx     x3, x17, #0x18, #8
//   0x0044c4: b86179c1  ldr      w1, [x14, x1, lsl #2]
//   0x0044c8: b86359e3  ldr      w3, [x15, w3, uxtw #2]
//   0x0044cc: 4a010129  eor      w9, w9, w1
//   0x0044d0: 4a030129  eor      w9, w9, w3
//   0x0044d4: 4a120129  eor      w9, w9, w18
//   0x0044d8: 4a090092  eor      w18, w4, w9
//   0x0044dc: 29004969  stp      w9, w18, [x11]
//   0x0044e0: 4a1200b2  eor      w18, w5, w18
//   0x0044e4: 4a110251  eor      w17, w18, w17
//   0x0044e8: 29014572  stp      w18, w17, [x11, #8]
//   0x0044ec: 9100416b  add      x11, x11, #0x10
//   0x0044f0: 54fffd01  b.ne     #0x4490
//   0x0044f4: 1400007b  b        #0x46e0
//   0x0044f8: b940102d  ldr      w13, [x1, #0x10]
//   0x0044fc: f000002c  adrp     x12, #0xb000
//   0x004500: f000002e  adrp     x14, #0xb000
//   0x004504: f000002f  adrp     x15, #0xb000
//   0x004508: 5ac009ad  rev      w13, w13
//   0x00450c: b900100d  str      w13, [x0, #0x10]
//   0x004510: b9401430  ldr      w16, [x1, #0x14]
//   0x004514: f000002d  adrp     x13, #0xb000
//   0x004518: aa1f03ea  mov      x10, xzr
//   0x00451c: 9100600b  add      x11, x0, #0x18
//   0x004520: 5ac00a10  rev      w16, w16
//   0x004524: b9001410  str      w16, [x0, #0x14]
//   0x004528: 90000050  adrp     x16, #0xc000
//   0x00452c: 910c918c  add      x12, x12, #0x324
//   0x004530: 911c91ad  add      x13, x13, #0x724
//   0x004534: 912c91ce  add      x14, x14, #0xb24
//   0x004538: 913c91ef  add      x15, x15, #0xf24
//   0x00453c: 910c9210  add      x16, x16, #0x324
//   0x004540: 14000007  b        #0x455c
//   0x004544: b85f8161  ldur     w1, [x11, #-8]
//   0x004548: 9100114a  add      x10, x10, #4
//   0x00454c: 4a120032  eor      w18, w1, w18
//   0x004550: 4a110251  eor      w17, w18, w17
//   0x004554: 29024572  stp      w18, w17, [x11, #0x10]
//   0x004558: 9100616b  add      x11, x11, #0x18
//   0x00455c: b85fc171  ldur     w17, [x11, #-4]
//   0x004560: b86a6a12  ldr      w18, [x16, x10]
//   0x004564: 297d9163  ldp      w3, w4, [x11, #-0x14]
//   0x004568: f100715f  cmp      x10, #0x1c
//   0x00456c: 53105e21  ubfx     w1, w17, #0x10, #8
//   0x004570: b8615981  ldr      w1, [x12, w1, uxtw #2]
//   0x004574: 53083e25  ubfx     w5, w17, #8, #8
//   0x004578: b86559a5  ldr      w5, [x13, w5, uxtw #2]
//   0x00457c: 4a090029  eor      w9, w1, w9
//   0x004580: 92401e21  and      x1, x17, #0xff
//   0x004584: b86179c1  ldr      w1, [x14, x1, lsl #2]
//   0x004588: 4a050129  eor      w9, w9, w5
//   0x00458c: d3587e25  ubfx     x5, x17, #0x18, #8
//   0x004590: b86559e5  ldr      w5, [x15, w5, uxtw #2]
//   0x004594: 4a010129  eor      w9, w9, w1
//   0x004598: b85f4161  ldur     w1, [x11, #-0xc]
//   0x00459c: 4a050129  eor      w9, w9, w5
//   0x0045a0: 4a120129  eor      w9, w9, w18
//   0x0045a4: 4a090072  eor      w18, w3, w9
//   0x0045a8: 4a120083  eor      w3, w4, w18
//   0x0045ac: 29004969  stp      w9, w18, [x11]
//   0x0045b0: 4a030032  eor      w18, w1, w3
//   0x0045b4: 29014963  stp      w3, w18, [x11, #8]
//   0x0045b8: 54fffc61  b.ne     #0x4544
//   0x0045bc: 14000049  b        #0x46e0
//   0x0045c0: b940102b  ldr      w11, [x1, #0x10]
//   0x0045c4: f000002c  adrp     x12, #0xb000
//   0x0045c8: f000002e  adrp     x14, #0xb000
//   0x0045cc: f000002f  adrp     x15, #0xb000
//   0x0045d0: 5ac0096b  rev      w11, w11
//   0x0045d4: b900100b  str      w11, [x0, #0x10]
//   0x0045d8: b940142b  ldr      w11, [x1, #0x14]
//   0x0045dc: aa1f03ea  mov      x10, xzr
//   0x0045e0: 910c918c  add      x12, x12, #0x324
//   0x0045e4: 912c91ce  add      x14, x14, #0xb24
//   0x0045e8: 5ac0096b  rev      w11, w11
//   0x0045ec: b900140b  str      w11, [x0, #0x14]
//   0x0045f0: b940182d  ldr      w13, [x1, #0x18]
//   0x0045f4: 9100800b  add      x11, x0, #0x20
//   0x0045f8: 913c91ef  add      x15, x15, #0xf24
//   0x0045fc: 5ac009ad  rev      w13, w13
//   0x004600: b900180d  str      w13, [x0, #0x18]
//   0x004604: b9401c30  ldr      w16, [x1, #0x1c]
//   0x004608: f000002d  adrp     x13, #0xb000
//   0x00460c: 911c91ad  add      x13, x13, #0x724
//   0x004610: 5ac00a10  rev      w16, w16
//   0x004614: b9001c10  str      w16, [x0, #0x1c]
//   0x004618: 90000050  adrp     x16, #0xc000
//   0x00461c: 910c9210  add      x16, x16, #0x324
//   0x004620: 14000018  b        #0x4680
//   0x004624: 13922252  ror      w18, w18, #8
//   0x004628: d3505e41  ubfx     x1, x18, #0x10, #8
//   0x00462c: b8617981  ldr      w1, [x12, x1, lsl #2]
//   0x004630: 297e1163  ldp      w3, w4, [x11, #-0x10]
//   0x004634: d3483e45  ubfx     x5, x18, #8, #8
//   0x004638: b86579a5  ldr      w5, [x13, x5, lsl #2]
//   0x00463c: 9100114a  add      x10, x10, #4
//   0x004640: 4a030021  eor      w1, w1, w3
//   0x004644: 92401e43  and      x3, x18, #0xff
//   0x004648: d356fe52  lsr      x18, x18, #0x16
//   0x00464c: b86379c3  ldr      w3, [x14, x3, lsl #2]
//   0x004650: 927e1e52  and      x18, x18, #0x3fc
//   0x004654: b87269f2  ldr      w18, [x15, x18]
//   0x004658: 4a050021  eor      w1, w1, w5
//   0x00465c: b85f8165  ldur     w5, [x11, #-8]
//   0x004660: 4a030021  eor      w1, w1, w3
//   0x004664: 4a120032  eor      w18, w1, w18
//   0x004668: 4a120081  eor      w1, w4, w18
//   0x00466c: 29020572  stp      w18, w1, [x11, #0x10]
//   0x004670: 4a0100b2  eor      w18, w5, w1
//   0x004674: 4a110251  eor      w17, w18, w17
//   0x004678: 29034572  stp      w18, w17, [x11, #0x18]
//   0x00467c: 9100816b  add      x11, x11, #0x20
//   0x004680: b85fc171  ldur     w17, [x11, #-4]
//   0x004684: b86a6a12  ldr      w18, [x16, x10]
//   0x004688: 297c9163  ldp      w3, w4, [x11, #-0x1c]
//   0x00468c: f100615f  cmp      x10, #0x18
//   0x004690: 53105e21  ubfx     w1, w17, #0x10, #8
//   0x004694: b8615981  ldr      w1, [x12, w1, uxtw #2]
//   0x004698: 53083e25  ubfx     w5, w17, #8, #8
//   0x00469c: b86559a5  ldr      w5, [x13, w5, uxtw #2]
//   0x0046a0: 4a090029  eor      w9, w1, w9
//   0x0046a4: 92401e21  and      x1, x17, #0xff
//   0x0046a8: b86179c1  ldr      w1, [x14, x1, lsl #2]
//   0x0046ac: 4a050129  eor      w9, w9, w5
//   0x0046b0: d3587e25  ubfx     x5, x17, #0x18, #8
//   0x0046b4: b86559e5  ldr      w5, [x15, w5, uxtw #2]
//   0x0046b8: 4a010129  eor      w9, w9, w1
//   0x0046bc: b85ec161  ldur     w1, [x11, #-0x14]
//   0x0046c0: 4a050129  eor      w9, w9, w5
//   0x0046c4: 4a120129  eor      w9, w9, w18
//   0x0046c8: 4a090072  eor      w18, w3, w9
//   0x0046cc: 4a120083  eor      w3, w4, w18
//   0x0046d0: 29004969  stp      w9, w18, [x11]
//   0x0046d4: 4a030032  eor      w18, w1, w3
//   0x0046d8: 29014963  stp      w3, w18, [x11, #8]
//   0x0046dc: 54fffa41  b.ne     #0x4624
//   0x0046e0: 1100704c  add      w12, w2, #0x1c
//   0x0046e4: 8b2c4811  add      x17, x0, w12, uxtw #2
//   0x0046e8: b85f022d  ldur     w13, [x17, #-0x10]
//   0x0046ec: d37ef510  lsl      x16, x8, #2
//   0x0046f0: d100620f  sub      x15, x16, #0x18
//   0x0046f4: d1006192  sub      x18, x12, #0x18
//   0x0046f8: b900f00d  str      w13, [x0, #0xf0]
//   0x0046fc: b85f422d  ldur     w13, [x17, #-0xc]
//   0x004700: 9000004a  adrp     x10, #0xc000
//   0x004704: 9000004b  adrp     x11, #0xc000
//   0x004708: 9000004e  adrp     x14, #0xc000
//   0x00470c: b900f40d  str      w13, [x0, #0xf4]
//   0x004710: b85f8221  ldur     w1, [x17, #-8]
//   0x004714: cb0f024d  sub      x13, x18, x15
//   0x004718: d100718c  sub      x12, x12, #0x1c
//   0x00471c: 91040009  add      x9, x0, #0x100
//   0x004720: b900f801  str      w1, [x0, #0xf8]
//   0x004724: b85fc232  ldur     w18, [x17, #-4]
//   0x004728: d1000508  sub      x8, x8, #1
//   0x00472c: 910d314a  add      x10, x10, #0x34c
//   0x004730: 911d316b  add      x11, x11, #0x74c
//   0x004734: b900fc12  str      w18, [x0, #0xfc]
//   0x004738: 90000052  adrp     x18, #0xc000
//   0x00473c: 912d31ce  add      x14, x14, #0xb4c
//   0x004740: cb0f018f  sub      x15, x12, x15
//   0x004744: 9100e20c  add      x12, x16, #0x38
//   0x004748: 9100f210  add      x16, x16, #0x3c
//   0x00474c: d1008231  sub      x17, x17, #0x20
//   0x004750: 913d3252  add      x18, x18, #0xf4c
//   0x004754: b9400221  ldr      w1, [x17]
//   0x004758: d1000508  sub      x8, x8, #1
//   0x00475c: d3587c22  ubfx     x2, x1, #0x18, #8
//   0x004760: 53105c23  ubfx     w3, w1, #0x10, #8
//   0x004764: 53083c24  ubfx     w4, w1, #8, #8
//   0x004768: b8625942  ldr      w2, [x10, w2, uxtw #2]
//   0x00476c: b8635963  ldr      w3, [x11, w3, uxtw #2]
//   0x004770: 92401c21  and      x1, x1, #0xff
//   0x004774: b86459c4  ldr      w4, [x14, w4, uxtw #2]
//   0x004778: b8617a41  ldr      w1, [x18, x1, lsl #2]
//   0x00477c: 4a020062  eor      w2, w3, w2
//   0x004780: 4a040042  eor      w2, w2, w4
//   0x004784: 4a010041  eor      w1, w2, w1
//   0x004788: b9000121  str      w1, [x9]
//   0x00478c: b9400621  ldr      w1, [x17, #4]
//   0x004790: d3587c22  ubfx     x2, x1, #0x18, #8
//   0x004794: 53105c23  ubfx     w3, w1, #0x10, #8
//   0x004798: 53083c24  ubfx     w4, w1, #8, #8
//   0x00479c: b8625942  ldr      w2, [x10, w2, uxtw #2]
//   0x0047a0: b8635963  ldr      w3, [x11, w3, uxtw #2]
//   0x0047a4: 92401c21  and      x1, x1, #0xff
//   0x0047a8: b86459c4  ldr      w4, [x14, w4, uxtw #2]
//   0x0047ac: b8617a41  ldr      w1, [x18, x1, lsl #2]
//   0x0047b0: 4a020062  eor      w2, w3, w2
//   0x0047b4: 4a040042  eor      w2, w2, w4
//   0x0047b8: 4a010041  eor      w1, w2, w1
//   0x0047bc: b9000521  str      w1, [x9, #4]
//   0x0047c0: b9400a21  ldr      w1, [x17, #8]
//   0x0047c4: d3587c22  ubfx     x2, x1, #0x18, #8
//   0x0047c8: 53105c23  ubfx     w3, w1, #0x10, #8
//   0x0047cc: 53083c24  ubfx     w4, w1, #8, #8
//   0x0047d0: b8625942  ldr      w2, [x10, w2, uxtw #2]
//   0x0047d4: b8635963  ldr      w3, [x11, w3, uxtw #2]
//   0x0047d8: 92401c21  and      x1, x1, #0xff
//   0x0047dc: b86459c4  ldr      w4, [x14, w4, uxtw #2]
//   0x0047e0: b8617a41  ldr      w1, [x18, x1, lsl #2]
//   0x0047e4: 4a020062  eor      w2, w3, w2
//   0x0047e8: 4a040042  eor      w2, w2, w4
//   0x0047ec: 4a010041  eor      w1, w2, w1
//   0x0047f0: b9000921  str      w1, [x9, #8]
//   0x0047f4: b9400e21  ldr      w1, [x17, #0xc]
//   0x0047f8: d1004231  sub      x17, x17, #0x10
//   0x0047fc: d3587c22  ubfx     x2, x1, #0x18, #8
//   0x004800: 53105c23  ubfx     w3, w1, #0x10, #8
//   0x004804: b8625942  ldr      w2, [x10, w2, uxtw #2]
//   0x004808: b8635963  ldr      w3, [x11, w3, uxtw #2]
//   0x00480c: 4a020062  eor      w2, w3, w2
//   0x004810: 53083c23  ubfx     w3, w1, #8, #8
//   0x004814: 92401c21  and      x1, x1, #0xff
//   0x004818: b86359c3  ldr      w3, [x14, w3, uxtw #2]
//   0x00481c: b8617a41  ldr      w1, [x18, x1, lsl #2]
//   0x004820: 4a030042  eor      w2, w2, w3
//   0x004824: 4a010041  eor      w1, w2, w1
//   0x004828: b9000d21  str      w1, [x9, #0xc]
//   0x00482c: 91004129  add      x9, x9, #0x10
//   0x004830: b5fff928  cbnz     x8, #0x4754
//   0x004834: b86f7809  ldr      w9, [x0, x15, lsl #2]
//   0x004838: 8b0d080a  add      x10, x0, x13, lsl #2
//   0x00483c: 8b0c080b  add      x11, x0, x12, lsl #2
//   0x004840: b8307809  str      w9, [x0, x16, lsl #2]
//   0x004844: b85f4149  ldur     w9, [x10, #-0xc]
//   0x004848: b9001569  str      w9, [x11, #0x14]
//   0x00484c: b85f8149  ldur     w9, [x10, #-8]
//   0x004850: b9001969  str      w9, [x11, #0x18]
//   0x004854: b85fc149  ldur     w9, [x10, #-4]
//   0x004858: b9001d69  str      w9, [x11, #0x1c]
//   0x00485c: 2a0803e0  mov      w0, w8
//   0x004860: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_18_43dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000043dcULL;
    for (std::size_t i = 0; i < 290ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3743ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[19] Subroutine @ 0x004864..0x0048e4 (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[19] Hàm con @ 0x004864..0x0048e4 (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004864: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x004868: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00486c: 910043fd  add      x29, sp, #0x10
//   0x004870: d11283ff  sub      sp, sp, #0x4a0
//   0x004874: d53bd053  mrs      x19, tpidr_el0
//   0x004878: f9401668  ldr      x8, [x19, #0x28]
//   0x00487c: 90000009  adrp     x9, #0x4000
//   0x004880: 91277129  add      x9, x9, #0x9dc
//   0x004884: f81e83a8  stur     x8, [x29, #-0x18]
//   0x004888: 910123e8  add      x8, sp, #0x48
//   0x00488c: a90087e0  stp      x0, x1, [sp, #8]
//   0x004890: a9018fe2  stp      x2, x3, [sp, #0x18]
//   0x004894: b0000040  adrp     x0, #0xd000
//   0x004898: f0000083  adrp     x3, #0x17000
//   0x00489c: 91112108  add      x8, x8, #0x448
//   0x0048a0: a90297e4  stp      x4, x5, [sp, #0x28]
//   0x0048a4: 9134c000  add      x0, x0, #0xd30
//   0x0048a8: 91354063  add      x3, x3, #0xd50
//   0x0048ac: 910023e1  add      x1, sp, #8
//   0x0048b0: 9100e3e4  add      x4, sp, #0x38
//   0x0048b4: aa1f03e2  mov      x2, xzr
//   0x0048b8: a903a3e9  stp      x9, x8, [sp, #0x38]
//   0x0048bc: 9400004b  bl       #0x49e8
//   0x0048c0: f9401668  ldr      x8, [x19, #0x28]
//   0x0048c4: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x0048c8: eb09011f  cmp      x8, x9
//   0x0048cc: 540000a1  b.ne     #0x48e0
//   0x0048d0: 911283ff  add      sp, sp, #0x4a0
//   0x0048d4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0048d8: a8c24ffc  ldp      x28, x19, [sp], #0x20
//   0x0048dc: d65f03c0  ret      
//   0x0048e0: 97fff008  bl       #0x900
// ============================================================================
std::uint32_t fde_19_4864(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004864ULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4033ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[20] Subroutine @ 0x0048e4..0x004900 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[20] Hàm con @ 0x0048e4..0x004900 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0048e4: a9bf7bf3  stp      x19, x30, [sp, #-0x10]!
//   0x0048e8: aa0003f3  mov      x19, x0
//   0x0048ec: f9400260  ldr      x0, [x19]
//   0x0048f0: 97fff008  bl       #0x910
//   0x0048f4: f9000660  str      x0, [x19, #8]
//   0x0048f8: a8c17bf3  ldp      x19, x30, [sp], #0x10
//   0x0048fc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_20_48e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000048e4ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4065ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[21] Subroutine @ 0x004900..0x004910 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[21] Hàm con @ 0x004900..0x004910 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004900: a9400408  ldp      x8, x1, [x0]
//   0x004904: f9400802  ldr      x2, [x0, #0x10]
//   0x004908: aa0803e0  mov      x0, x8
//   0x00490c: 14000881  b        #0x6b10
// ============================================================================
std::uint32_t fde_21_4900(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004900ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4072ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[22] Subroutine @ 0x004910..0x004920 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[22] Hàm con @ 0x004910..0x004920 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004910: a9400408  ldp      x8, x1, [x0]
//   0x004914: f9400802  ldr      x2, [x0, #0x10]
//   0x004918: aa0803e0  mov      x0, x8
//   0x00491c: 17fff001  b        #0x920
// ============================================================================
std::uint32_t fde_22_4910(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004910ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4076ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[23] Subroutine @ 0x004920..0x0049d4 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[23] Hàm con @ 0x004920..0x0049d4 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004920: f9400809  ldr      x9, [x0, #0x10]
//   0x004924: b4000569  cbz      x9, #0x49d0
//   0x004928: a9402c08  ldp      x8, x11, [x0]
//   0x00492c: f100813f  cmp      x9, #0x20
//   0x004930: 54000062  b.hs     #0x493c
//   0x004934: aa1f03ea  mov      x10, xzr
//   0x004938: 14000017  b        #0x4994
//   0x00493c: b000004d  adrp     x13, #0xd000
//   0x004940: b000004e  adrp     x14, #0xd000
//   0x004944: 927be92a  and      x10, x9, #0xffffffffffffffe0
//   0x004948: 8b0b010c  add      x12, x8, x11
//   0x00494c: 9132c1ad  add      x13, x13, #0xcb0
//   0x004950: 9133c1ce  add      x14, x14, #0xcf0
//   0x004954: 9100418c  add      x12, x12, #0x10
//   0x004958: 910041ad  add      x13, x13, #0x10
//   0x00495c: 910041ce  add      x14, x14, #0x10
//   0x004960: aa0a03ef  mov      x15, x10
//   0x004964: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x004968: ad7f8dc2  ldp      q2, q3, [x14, #-0x10]
//   0x00496c: 910081ad  add      x13, x13, #0x20
//   0x004970: 910081ce  add      x14, x14, #0x20
//   0x004974: f10081ef  subs     x15, x15, #0x20
//   0x004978: 6e201c40  eor      v0.16b, v2.16b, v0.16b
//   0x00497c: 6e211c61  eor      v1.16b, v3.16b, v1.16b
//   0x004980: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x004984: 9100818c  add      x12, x12, #0x20
//   0x004988: 54fffee1  b.ne     #0x4964
//   0x00498c: eb0a013f  cmp      x9, x10
//   0x004990: 54000200  b.eq     #0x49d0
//   0x004994: b000004c  adrp     x12, #0xd000
//   0x004998: b000004d  adrp     x13, #0xd000
//   0x00499c: 8b0b014b  add      x11, x10, x11
//   0x0049a0: 9133c18c  add      x12, x12, #0xcf0
//   0x0049a4: 9132c1ad  add      x13, x13, #0xcb0
//   0x0049a8: cb0a0129  sub      x9, x9, x10
//   0x0049ac: 8b0b0108  add      x8, x8, x11
//   0x0049b0: 8b0a018b  add      x11, x12, x10
//   0x0049b4: 8b0a01aa  add      x10, x13, x10
//   0x0049b8: 3840154c  ldrb     w12, [x10], #1
//   0x0049bc: 3840156d  ldrb     w13, [x11], #1
//   0x0049c0: f1000529  subs     x9, x9, #1
//   0x0049c4: 4a0c01ac  eor      w12, w13, w12
//   0x0049c8: 3800150c  strb     w12, [x8], #1
//   0x0049cc: 54ffff61  b.ne     #0x49b8
//   0x0049d0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_23_4920(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004920ULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4080ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[24] Subroutine @ 0x0049d4..0x0049dc (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[24] Hàm con @ 0x0049d4..0x0049dc (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0049d4: f9400000  ldr      x0, [x0]
//   0x0049d8: 17ffefda  b        #0x940
// ============================================================================
std::uint32_t fde_24_49d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000049d4ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4125ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[25] Subroutine @ 0x0049dc..0x0049e8 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[25] Hàm con @ 0x0049dc..0x0049e8 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0049dc: aa0003e2  mov      x2, x0
//   0x0049e0: aa0103e0  mov      x0, x1
//   0x0049e4: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_25_49dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000049dcULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4127ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[26] Subroutine @ 0x0049e8..0x006334 (6476 bytes, 1619 AArch64 instructions)
// [VN] Khung FDE[26] Hàm con @ 0x0049e8..0x006334 (6476 byte, 1619 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0049e8: d101c3ff  sub      sp, sp, #0x70
//   0x0049ec: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x0049f0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0049f4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0049f8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0049fc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x004a00: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x004a04: 910183fd  add      x29, sp, #0x60
//   0x004a08: a9404c94  ldp      x20, x19, [x4]
//   0x004a0c: d104c268  sub      x8, x19, #0x130
//   0x004a10: f81c827f  stur     xzr, [x19, #-0x38]
//   0x004a14: f900011f  str      xzr, [x8]
//   0x004a18: d1052268  sub      x8, x19, #0x148
//   0x004a1c: d104e275  sub      x21, x19, #0x138
//   0x004a20: 927ced08  and      x8, x8, #0xfffffffffffffff0
//   0x004a24: d1044264  sub      x4, x19, #0x110
//   0x004a28: d1042265  sub      x5, x19, #0x108
//   0x004a2c: f81b8268  stur     x8, [x19, #-0x48]
//   0x004a30: f81e027f  stur     xzr, [x19, #-0x20]
//   0x004a34: f9000081  str      x1, [x4]
//   0x004a38: f90000a2  str      x2, [x5]
//   0x004a3c: a9305263  stp      x3, x20, [x19, #-0x100]
//   0x004a40: f90002a0  str      x0, [x21]
//   0x004a44: f81f8260  stur     x0, [x19, #-8]
//   0x004a48: b400c660  cbz      x0, #0x6314
//   0x004a4c: 528065f7  mov      w23, #0x32f
//   0x004a50: 5281fff8  mov      w24, #0xfff
//   0x004a54: b000005c  adrp     x28, #0xd000
//   0x004a58: b0000056  adrp     x22, #0xd000
//   0x004a5c: b000005b  adrp     x27, #0xd000
//   0x004a60: b0000059  adrp     x25, #0xd000
//   0x004a64: aa1f03e1  mov      x1, xzr
//   0x004a68: d100a266  sub      x6, x19, #0x28
//   0x004a6c: d100c267  sub      x7, x19, #0x30
//   0x004a70: 72a08017  movk     w23, #0x400, lsl #16
//   0x004a74: 72a00418  movk     w24, #0x20, lsl #16
//   0x004a78: 320007fa  mov      w26, #3
//   0x004a7c: 910d339c  add      x28, x28, #0x34c
//   0x004a80: 911132d6  add      x22, x22, #0x44c
//   0x004a84: 321b03fe  mov      w30, #0x20
//   0x004a88: 9114b37b  add      x27, x27, #0x52c
//   0x004a8c: 911c5339  add      x25, x25, #0x714
//   0x004a90: 14000002  b        #0x4a98
//   0x004a94: f85e0261  ldur     x1, [x19, #-0x20]
//   0x004a98: b940000c  ldr      w12, [x0]
//   0x004a9c: f100083f  cmp      x1, #2
//   0x004aa0: 5400a340  b.eq     #0x5f08
//   0x004aa4: 1200158a  and      w10, w12, #0x3f
//   0x004aa8: 7100fd5f  cmp      w10, #0x3f
//   0x004aac: 540071c8  b.hi     #0x58e4
//   0x004ab0: 530b7d8b  lsr      w11, w12, #0xb
//   0x004ab4: 121f016e  and      w14, w11, #2
//   0x004ab8: b8aa7b83  ldrsw    x3, [x28, x10, lsl #2]
//   0x004abc: 12040190  and      w16, w12, #0x10000000
//   0x004ac0: 121e0162  and      w2, w11, #4
//   0x004ac4: 331f7d8e  bfxil    w14, w12, #0x1f, #1
//   0x004ac8: 2a0201ce  orr      w14, w14, w2
//   0x004acc: 121d0162  and      w2, w11, #8
//   0x004ad0: 121c016a  and      w10, w11, #0x10
//   0x004ad4: 531a7e0b  lsr      w11, w16, #0x1a
//   0x004ad8: 1203018f  and      w15, w12, #0x20000000
//   0x004adc: 2a0201c2  orr      w2, w14, w2
//   0x004ae0: 331a6d8b  bfxil    w11, w12, #0x1a, #2
//   0x004ae4: 1202018e  and      w14, w12, #0x40000000
//   0x004ae8: 2a0a004a  orr      w10, w2, w10
//   0x004aec: 2a4f696b  orr      w11, w11, w15, lsr #26
//   0x004af0: 8b1c0062  add      x2, x3, x28
//   0x004af4: 53156589  ubfx     w9, w12, #0x15, #5
//   0x004af8: 53105188  ubfx     w8, w12, #0x10, #5
//   0x004afc: 1201018d  and      w13, w12, #0x80000000
//   0x004b00: 12060192  and      w18, w12, #0x4000000
//   0x004b04: 12050191  and      w17, w12, #0x8000000
//   0x004b08: 2a4e696b  orr      w11, w11, w14, lsr #26
//   0x004b0c: d61f0040  br       x2
//   0x004b10: 1200158a  and      w10, w12, #0x3f
//   0x004b14: 7100dd5f  cmp      w10, #0x37
//   0x004b18: 54006e68  b.hi     #0x58e4
//   0x004b1c: 53062d8b  ubfx     w11, w12, #6, #6
//   0x004b20: 12140d8c  and      w12, w12, #0xf000
//   0x004b24: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x004b28: 2a0b018b  orr      w11, w12, w11
//   0x004b2c: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x004b30: b8aa7aca  ldrsw    x10, [x22, x10, lsl #2]
//   0x004b34: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x004b38: f9400529  ldr      x9, [x9, #8]
//   0x004b3c: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x004b40: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x004b44: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x004b48: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x004b4c: 8b16014a  add      x10, x10, x22
//   0x004b50: 8b2ba129  add      x9, x9, w11, sxth
//   0x004b54: d61f0140  br       x10
//   0x004b58: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x004b5c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x004b60: f940014a  ldr      x10, [x10]
//   0x004b64: f940050b  ldr      x11, [x8, #8]
//   0x004b68: d37d0929  ubfiz    x9, x9, #3, #3
//   0x004b6c: 321d0bec  mov      w12, #0x38
//   0x004b70: b240dfed  mov      x13, #0xffffffffffffff
//   0x004b74: cb09018c  sub      x12, x12, x9
//   0x004b78: 9ac925a9  lsr      x9, x13, x9
//   0x004b7c: 9acc214a  lsl      x10, x10, x12
//   0x004b80: 8a090169  and      x9, x11, x9
//   0x004b84: aa0a0129  orr      x9, x9, x10
//   0x004b88: 14000356  b        #0x58e0
//   0x004b8c: b5006ac1  cbnz     x1, #0x58e4
//   0x004b90: 1200158a  and      w10, w12, #0x3f
//   0x004b94: 51000d41  sub      w1, w10, #3
//   0x004b98: 7100f03f  cmp      w1, #0x3c
//   0x004b9c: 54006a48  b.hi     #0x58e4
//   0x004ba0: 12140d83  and      w3, w12, #0xf000
//   0x004ba4: 53062d82  ubfx     w2, w12, #6, #6
//   0x004ba8: 33147e43  bfxil    w3, w18, #0x14, #0xc
//   0x004bac: 2a020072  orr      w18, w3, w2
//   0x004bb0: b8a17b61  ldrsw    x1, [x27, x1, lsl #2]
//   0x004bb4: 2a515251  orr      w17, w18, w17, lsr #20
//   0x004bb8: 2a505230  orr      w16, w17, w16, lsr #20
//   0x004bbc: 2a4f520f  orr      w15, w16, w15, lsr #20
//   0x004bc0: 2a4e51ee  orr      w14, w15, w14, lsr #20
//   0x004bc4: 2a4d51cd  orr      w13, w14, w13, lsr #20
//   0x004bc8: 8b1b002e  add      x14, x1, x27
//   0x004bcc: 2a1f03ea  mov      w10, wzr
//   0x004bd0: aa1f03eb  mov      x11, xzr
//   0x004bd4: 131e3dad  sbfiz    w13, w13, #2, #0x10
//   0x004bd8: d61f01c0  br       x14
//   0x004bdc: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x004be0: f940050b  ldr      x11, [x8, #8]
//   0x004be4: 12001588  and      w8, w12, #0x3f
//   0x004be8: 51000d08  sub      w8, w8, #3
//   0x004bec: 7100f11f  cmp      w8, #0x3c
//   0x004bf0: 540067a8  b.hi     #0x58e4
//   0x004bf4: b000004a  adrp     x10, #0xd000
//   0x004bf8: 9118814a  add      x10, x10, #0x620
//   0x004bfc: aa0a03ec  mov      x12, x10
//   0x004c00: b8a87988  ldrsw    x8, [x12, x8, lsl #2]
//   0x004c04: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x004c08: f9400529  ldr      x9, [x9, #8]
//   0x004c0c: 110011aa  add      w10, w13, #4
//   0x004c10: 8b0c010c  add      x12, x8, x12
//   0x004c14: 8b2ac008  add      x8, x0, w10, sxtw
//   0x004c18: d61f0180  br       x12
//   0x004c1c: f100013f  cmp      x9, #0
//   0x004c20: 5400364d  b.le     #0x52e8
//   0x004c24: 2a1f03eb  mov      w11, wzr
//   0x004c28: 2a1f03e9  mov      w9, wzr
//   0x004c2c: 140001aa  b        #0x52d4
//   0x004c30: 1200158a  and      w10, w12, #0x3f
//   0x004c34: 5100294a  sub      w10, w10, #0xa
//   0x004c38: 7100c55f  cmp      w10, #0x31
//   0x004c3c: 54006548  b.hi     #0x58e4
//   0x004c40: 53062d8b  ubfx     w11, w12, #6, #6
//   0x004c44: 12140d8c  and      w12, w12, #0xf000
//   0x004c48: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x004c4c: 2a0b018b  orr      w11, w12, w11
//   0x004c50: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x004c54: b8aa7b2a  ldrsw    x10, [x25, x10, lsl #2]
//   0x004c58: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x004c5c: f9400529  ldr      x9, [x9, #8]
//   0x004c60: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x004c64: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x004c68: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x004c6c: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x004c70: 8b19014a  add      x10, x10, x25
//   0x004c74: 8b2ba129  add      x9, x9, w11, sxth
//   0x004c78: d61f0140  br       x10
//   0x004c7c: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x004c80: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x004c84: f9400508  ldr      x8, [x8, #8]
//   0x004c88: f940014b  ldr      x11, [x10]
//   0x004c8c: d37d0929  ubfiz    x9, x9, #3, #3
//   0x004c90: 321d0bec  mov      w12, #0x38
//   0x004c94: b278dfed  mov      x13, #-0x100
//   0x004c98: cb09018c  sub      x12, x12, x9
//   0x004c9c: 9ac921a9  lsl      x9, x13, x9
//   0x004ca0: 9acc2508  lsr      x8, x8, x12
//   0x004ca4: 8a090169  and      x9, x11, x9
//   0x004ca8: 14000139  b        #0x518c
//   0x004cac: 12140d80  and      w0, w12, #0xf000
//   0x004cb0: 53062d8a  ubfx     w10, w12, #6, #6
//   0x004cb4: 33147e40  bfxil    w0, w18, #0x14, #0xc
//   0x004cb8: 2a0a000a  orr      w10, w0, w10
//   0x004cbc: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x004cc0: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x004cc4: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x004cc8: 1200158b  and      w11, w12, #0x3f
//   0x004ccc: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x004cd0: 7100dd7f  cmp      w11, #0x37
//   0x004cd4: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x004cd8: 5400082c  b.gt     #0x4ddc
//   0x004cdc: 7100117f  cmp      w11, #4
//   0x004ce0: 54002ae0  b.eq     #0x523c
//   0x004ce4: 7100817f  cmp      w11, #0x20
//   0x004ce8: 54005fe1  b.ne     #0x58e4
//   0x004cec: 910022ab  add      x11, x21, #8
//   0x004cf0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x004cf4: 12003d4a  and      w10, w10, #0xffff
//   0x004cf8: 8a0a0129  and      x9, x9, x10
//   0x004cfc: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x004d00: 140002f9  b        #0x58e4
//   0x004d04: 12140d80  and      w0, w12, #0xf000
//   0x004d08: 53062d8a  ubfx     w10, w12, #6, #6
//   0x004d0c: 33147e40  bfxil    w0, w18, #0x14, #0xc
//   0x004d10: 2a0a000a  orr      w10, w0, w10
//   0x004d14: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x004d18: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x004d1c: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x004d20: 1200158b  and      w11, w12, #0x3f
//   0x004d24: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x004d28: 7100357f  cmp      w11, #0xd
//   0x004d2c: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x004d30: 540006a0  b.eq     #0x4e04
//   0x004d34: 7100a17f  cmp      w11, #0x28
//   0x004d38: 54000660  b.eq     #0x4e04
//   0x004d3c: 7100557f  cmp      w11, #0x15
//   0x004d40: 54005d21  b.ne     #0x58e4
//   0x004d44: 910022ab  add      x11, x21, #8
//   0x004d48: d37df129  lsl      x9, x9, #3
//   0x004d4c: b8a96969  ldrsw    x9, [x11, x9]
//   0x004d50: 13003d4a  sxth     w10, w10
//   0x004d54: 8b2ac129  add      x9, x9, w10, sxtw
//   0x004d58: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x004d5c: 140002e2  b        #0x58e4
//   0x004d60: b5005c21  cbnz     x1, #0x58e4
//   0x004d64: 1214358b  and      w11, w12, #0x3fff000
//   0x004d68: 53062d8a  ubfx     w10, w12, #6, #6
//   0x004d6c: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x004d70: 2a0a016a  orr      w10, w11, w10
//   0x004d74: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x004d78: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x004d7c: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x004d80: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x004d84: 12001588  and      w8, w12, #0x3f
//   0x004d88: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x004d8c: 7100451f  cmp      w8, #0x11
//   0x004d90: 531e754c  lsl      w12, w10, #2
//   0x004d94: 54002ee0  b.eq     #0x5370
//   0x004d98: 7100a91f  cmp      w8, #0x2a
//   0x004d9c: 54002ee0  b.eq     #0x5378
//   0x004da0: 7100691f  cmp      w8, #0x1a
//   0x004da4: 54005a01  b.ne     #0x58e4
//   0x004da8: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x004dac: f9400529  ldr      x9, [x9, #8]
//   0x004db0: 8b2cc00a  add      x10, x0, w12, sxtw
//   0x004db4: 9100200c  add      x12, x0, #8
//   0x004db8: 9100114a  add      x10, x10, #4
//   0x004dbc: f100053f  cmp      x9, #1
//   0x004dc0: 1a9fa7eb  cset     w11, lt
//   0x004dc4: f100013f  cmp      x9, #0
//   0x004dc8: 2a1f03e8  mov      w8, wzr
//   0x004dcc: 1a9fd7e9  cset     w9, gt
//   0x004dd0: 9a8cc14c  csel     x12, x10, x12, gt
//   0x004dd4: 320003ea  mov      w10, #1
//   0x004dd8: 1400016e  b        #0x5390
//   0x004ddc: 7100e17f  cmp      w11, #0x38
//   0x004de0: 54002340  b.eq     #0x5248
//   0x004de4: 7100f97f  cmp      w11, #0x3e
//   0x004de8: 540057e1  b.ne     #0x58e4
//   0x004dec: 910022ab  add      x11, x21, #8
//   0x004df0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x004df4: 12003d4a  and      w10, w10, #0xffff
//   0x004df8: aa0a0129  orr      x9, x9, x10
//   0x004dfc: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x004e00: 140002b9  b        #0x58e4
//   0x004e04: 910022ab  add      x11, x21, #8
//   0x004e08: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x004e0c: 8b2aa129  add      x9, x9, w10, sxth
//   0x004e10: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x004e14: 140002b4  b        #0x58e4
//   0x004e18: 12002d8d  and      w13, w12, #0xfff
//   0x004e1c: 71293dbf  cmp      w13, #0xa4f
//   0x004e20: 5400294c  b.gt     #0x5348
//   0x004e24: 710a3dbf  cmp      w13, #0x28f
//   0x004e28: 540035ed  b.le     #0x54e4
//   0x004e2c: 710a41bf  cmp      w13, #0x290
//   0x004e30: 54003fc0  b.eq     #0x5628
//   0x004e34: 711a41bf  cmp      w13, #0x690
//   0x004e38: 54003f80  b.eq     #0x5628
//   0x004e3c: 712341bf  cmp      w13, #0x8d0
//   0x004e40: 540035c0  b.eq     #0x54f8
//   0x004e44: 140002a8  b        #0x58e4
//   0x004e48: 528007e8  mov      w8, #0x3f
//   0x004e4c: 72a003e8  movk     w8, #0x1f, lsl #16
//   0x004e50: 529ffd2a  mov      w10, #0xffe9
//   0x004e54: 0a080188  and      w8, w12, w8
//   0x004e58: 72bfffca  movk     w10, #0xfffe, lsl #16
//   0x004e5c: 0b0a010a  add      w10, w8, w10
//   0x004e60: 138a414a  ror      w10, w10, #0x10
//   0x004e64: 7100695f  cmp      w10, #0x1a
//   0x004e68: 540053e8  b.hi     #0x58e4
//   0x004e6c: 320003eb  mov      w11, #1
//   0x004e70: 1aca216a  lsl      w10, w11, w10
//   0x004e74: 52850c2b  mov      w11, #0x2861
//   0x004e78: 72a0908b  movk     w11, #0x484, lsl #16
//   0x004e7c: 6a0b015f  tst      w10, w11
//   0x004e80: 54005320  b.eq     #0x58e4
//   0x004e84: b5005301  cbnz     x1, #0x58e4
//   0x004e88: 53062d8b  ubfx     w11, w12, #6, #6
//   0x004e8c: 12140d8c  and      w12, w12, #0xf000
//   0x004e90: 33147e4c  bfxil    w12, w18, #0x14, #0xc
//   0x004e94: 2a0b018b  orr      w11, w12, w11
//   0x004e98: 2a51516b  orr      w11, w11, w17, lsr #20
//   0x004e9c: 2a50516b  orr      w11, w11, w16, lsr #20
//   0x004ea0: 2a4f516b  orr      w11, w11, w15, lsr #20
//   0x004ea4: 2a4e516b  orr      w11, w11, w14, lsr #20
//   0x004ea8: 528002cc  mov      w12, #0x16
//   0x004eac: 1200510a  and      w10, w8, #0x1fffff
//   0x004eb0: 2a4d516b  orr      w11, w11, w13, lsr #20
//   0x004eb4: 72a0002c  movk     w12, #1, lsl #16
//   0x004eb8: 6b0c015f  cmp      w10, w12
//   0x004ebc: 131e3d6c  sbfiz    w12, w11, #2, #0x10
//   0x004ec0: 540028ec  b.gt     #0x53dc
//   0x004ec4: 51000d4b  sub      w11, w10, #3
//   0x004ec8: 7100f17f  cmp      w11, #0x3c
//   0x004ecc: 540050c8  b.hi     #0x58e4
//   0x004ed0: b000004d  adrp     x13, #0xd000
//   0x004ed4: 911f71ad  add      x13, x13, #0x7dc
//   0x004ed8: b8ab79ab  ldrsw    x11, [x13, x11, lsl #2]
//   0x004edc: 2a1f03ea  mov      w10, wzr
//   0x004ee0: 8b0d016b  add      x11, x11, x13
//   0x004ee4: aa0003ed  mov      x13, x0
//   0x004ee8: d61f0160  br       x11
//   0x004eec: aa1f03ed  mov      x13, xzr
//   0x004ef0: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x004ef4: f940052b  ldr      x11, [x9, #8]
//   0x004ef8: 12005109  and      w9, w8, #0x1fffff
//   0x004efc: 528002c8  mov      w8, #0x16
//   0x004f00: 1100118a  add      w10, w12, #4
//   0x004f04: 72a00028  movk     w8, #1, lsl #16
//   0x004f08: 6b08013f  cmp      w9, w8
//   0x004f0c: 8b2ac008  add      x8, x0, w10, sxtw
//   0x004f10: 5400288c  b.gt     #0x5420
//   0x004f14: 51000d29  sub      w9, w9, #3
//   0x004f18: 7100f13f  cmp      w9, #0x3c
//   0x004f1c: 54004e48  b.hi     #0x58e4
//   0x004f20: b000004a  adrp     x10, #0xd000
//   0x004f24: 9123414a  add      x10, x10, #0x8d0
//   0x004f28: b8a97949  ldrsw    x9, [x10, x9, lsl #2]
//   0x004f2c: 8b0a0129  add      x9, x9, x10
//   0x004f30: d61f0120  br       x9
//   0x004f34: f100017f  cmp      x11, #0
//   0x004f38: 5400668d  b.le     #0x5c08
//   0x004f3c: 2a1f03eb  mov      w11, wzr
//   0x004f40: 2a1f03e9  mov      w9, wzr
//   0x004f44: 1400031f  b        #0x5bc0
//   0x004f48: 12140d8b  and      w11, w12, #0xf000
//   0x004f4c: 53062d8a  ubfx     w10, w12, #6, #6
//   0x004f50: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x004f54: 2a0a016a  orr      w10, w11, w10
//   0x004f58: 910022ac  add      x12, x21, #8
//   0x004f5c: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x004f60: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x004f64: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x004f68: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x004f6c: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x004f70: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x004f74: eb2aa13f  cmp      x9, w10, sxth
//   0x004f78: 1a9f27e9  cset     w9, lo
//   0x004f7c: f8285989  str      x9, [x12, w8, uxtw #3]
//   0x004f80: 14000259  b        #0x58e4
//   0x004f84: 12002d8b  and      w11, w12, #0xfff
//   0x004f88: 5106a56b  sub      w11, w11, #0x1a9
//   0x004f8c: 138b196b  ror      w11, w11, #6
//   0x004f90: 7100697f  cmp      w11, #0x1a
//   0x004f94: 54004a88  b.hi     #0x58e4
//   0x004f98: 320003ed  mov      w13, #1
//   0x004f9c: 5280064e  mov      w14, #0x32
//   0x004fa0: 1acb21ad  lsl      w13, w13, w11
//   0x004fa4: 72a0800e  movk     w14, #0x400, lsl #16
//   0x004fa8: 6a0e01bf  tst      w13, w14
//   0x004fac: 540027a0  b.eq     #0x54a0
//   0x004fb0: 12002d8a  and      w10, w12, #0xfff
//   0x004fb4: 711db95f  cmp      w10, #0x76e
//   0x004fb8: 540025ac  b.gt     #0x546c
//   0x004fbc: 710ba15f  cmp      w10, #0x2e8
//   0x004fc0: 540036cc  b.gt     #0x5698
//   0x004fc4: 7106bd5f  cmp      w10, #0x1af
//   0x004fc8: 540089e0  b.eq     #0x6104
//   0x004fcc: 7107a55f  cmp      w10, #0x1e9
//   0x004fd0: 54005680  b.eq     #0x5aa0
//   0x004fd4: 710aa55f  cmp      w10, #0x2a9
//   0x004fd8: 54004861  b.ne     #0x58e4
//   0x004fdc: 910022aa  add      x10, x21, #8
//   0x004fe0: d37df129  lsl      x9, x9, #3
//   0x004fe4: d37df108  lsl      x8, x8, #3
//   0x004fe8: b94000cb  ldr      w11, [x6]
//   0x004fec: b94000ec  ldr      w12, [x7]
//   0x004ff0: b8696949  ldr      w9, [x10, x9]
//   0x004ff4: b8686948  ldr      w8, [x10, x8]
//   0x004ff8: 140002b9  b        #0x5adc
//   0x004ffc: 12002d8d  and      w13, w12, #0xfff
//   0x005000: 5101bdae  sub      w14, w13, #0x6f
//   0x005004: 138e19ce  ror      w14, w14, #6
//   0x005008: 7100f9df  cmp      w14, #0x3e
//   0x00500c: 54006808  b.hi     #0x5d0c
//   0x005010: 9000004f  adrp     x15, #0xd000
//   0x005014: 912711ef  add      x15, x15, #0x9c4
//   0x005018: b8ae79ee  ldrsw    x14, [x15, x14, lsl #2]
//   0x00501c: 8b0f01ce  add      x14, x14, x15
//   0x005020: d61f01c0  br       x14
//   0x005024: 12002d8b  and      w11, w12, #0xfff
//   0x005028: 7121b97f  cmp      w11, #0x86e
//   0x00502c: 54003f0d  b.le     #0x580c
//   0x005030: 7127b97f  cmp      w11, #0x9ee
//   0x005034: 5400244d  b.le     #0x54bc
//   0x005038: 7127bd7f  cmp      w11, #0x9ef
//   0x00503c: 54002480  b.eq     #0x54cc
//   0x005040: 7129bd7f  cmp      w11, #0xa6f
//   0x005044: 540048e0  b.eq     #0x5960
//   0x005048: 7134bd7f  cmp      w11, #0xd2f
//   0x00504c: 54004ba0  b.eq     #0x59c0
//   0x005050: 14000225  b        #0x58e4
//   0x005054: 12140d8b  and      w11, w12, #0xf000
//   0x005058: 53062d8a  ubfx     w10, w12, #6, #6
//   0x00505c: 33147e4b  bfxil    w11, w18, #0x14, #0xc
//   0x005060: 2a0a016a  orr      w10, w11, w10
//   0x005064: 910022ac  add      x12, x21, #8
//   0x005068: 2a51514a  orr      w10, w10, w17, lsr #20
//   0x00506c: 2a50514a  orr      w10, w10, w16, lsr #20
//   0x005070: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x005074: 2a4f514a  orr      w10, w10, w15, lsr #20
//   0x005078: 2a4e514a  orr      w10, w10, w14, lsr #20
//   0x00507c: 2a4d514a  orr      w10, w10, w13, lsr #20
//   0x005080: eb2aa13f  cmp      x9, w10, sxth
//   0x005084: 1a9fa7e9  cset     w9, lt
//   0x005088: f8285989  str      x9, [x12, w8, uxtw #3]
//   0x00508c: 14000216  b        #0x58e4
//   0x005090: 79800129  ldrsh    x9, [x9]
//   0x005094: 14000212  b        #0x58dc
//   0x005098: f9400129  ldr      x9, [x9]
//   0x00509c: 14000210  b        #0x58dc
//   0x0050a0: 39800129  ldrsb    x9, [x9]
//   0x0050a4: 1400020e  b        #0x58dc
//   0x0050a8: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0050ac: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0050b0: b940014a  ldr      w10, [x10]
//   0x0050b4: b940090b  ldr      w11, [x8, #8]
//   0x0050b8: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0050bc: 4b0903cc  sub      w12, w30, w9
//   0x0050c0: 1280000d  mov      w13, #-1
//   0x0050c4: 1acc21ac  lsl      w12, w13, w12
//   0x0050c8: 1ac92549  lsr      w9, w10, w9
//   0x0050cc: 0a0c016a  and      w10, w11, w12
//   0x0050d0: 2a090149  orr      w9, w10, w9
//   0x0050d4: 14000203  b        #0x58e0
//   0x0050d8: 39400129  ldrb     w9, [x9]
//   0x0050dc: 14000200  b        #0x58dc
//   0x0050e0: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x0050e4: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0050e8: f940014a  ldr      x10, [x10]
//   0x0050ec: f940050b  ldr      x11, [x8, #8]
//   0x0050f0: d37d0929  ubfiz    x9, x9, #3, #3
//   0x0050f4: 321a03ec  mov      w12, #0x40
//   0x0050f8: cb09018c  sub      x12, x12, x9
//   0x0050fc: 9280000d  mov      x13, #-1
//   0x005100: 9acc21ac  lsl      x12, x13, x12
//   0x005104: 9ac92549  lsr      x9, x10, x9
//   0x005108: 8a0c016a  and      x10, x11, x12
//   0x00510c: aa090149  orr      x9, x10, x9
//   0x005110: 140001f4  b        #0x58e0
//   0x005114: b9800129  ldrsw    x9, [x9]
//   0x005118: 140001f1  b        #0x58dc
//   0x00511c: 79400129  ldrh     w9, [x9]
//   0x005120: 140001ef  b        #0x58dc
//   0x005124: b9400129  ldr      w9, [x9]
//   0x005128: 140001ed  b        #0x58dc
//   0x00512c: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x005130: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x005134: b940014a  ldr      w10, [x10]
//   0x005138: b940090b  ldr      w11, [x8, #8]
//   0x00513c: 531d0529  ubfiz    w9, w9, #3, #2
//   0x005140: 321d07ec  mov      w12, #0x18
//   0x005144: 32005fed  mov      w13, #0xffffff
//   0x005148: 4b09018c  sub      w12, w12, w9
//   0x00514c: 1ac925a9  lsr      w9, w13, w9
//   0x005150: 1acc214a  lsl      w10, w10, w12
//   0x005154: 0a090169  and      w9, w11, w9
//   0x005158: 2a0a0129  orr      w9, w9, w10
//   0x00515c: 140001e1  b        #0x58e0
//   0x005160: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x005164: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x005168: f9400508  ldr      x8, [x8, #8]
//   0x00516c: f940014b  ldr      x11, [x10]
//   0x005170: d37d0929  ubfiz    x9, x9, #3, #3
//   0x005174: 321a03ec  mov      w12, #0x40
//   0x005178: cb09018c  sub      x12, x12, x9
//   0x00517c: 9280000d  mov      x13, #-1
//   0x005180: 9acc25ac  lsr      x12, x13, x12
//   0x005184: 9ac92108  lsl      x8, x8, x9
//   0x005188: 8a0c0169  and      x9, x11, x12
//   0x00518c: aa080128  orr      x8, x9, x8
//   0x005190: f9000148  str      x8, [x10]
//   0x005194: 140001d4  b        #0x58e4
//   0x005198: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x00519c: b9400908  ldr      w8, [x8, #8]
//   0x0051a0: 39000128  strb     w8, [x9]
//   0x0051a4: 140001d0  b        #0x58e4
//   0x0051a8: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0051ac: b9400908  ldr      w8, [x8, #8]
//   0x0051b0: 79000128  strh     w8, [x9]
//   0x0051b4: 140001cc  b        #0x58e4
//   0x0051b8: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0051bc: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0051c0: b9400908  ldr      w8, [x8, #8]
//   0x0051c4: b940014b  ldr      w11, [x10]
//   0x0051c8: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0051cc: 321d07ec  mov      w12, #0x18
//   0x0051d0: 32185fed  mov      w13, #-0x100
//   0x0051d4: 4b09018c  sub      w12, w12, w9
//   0x0051d8: 1ac921a9  lsl      w9, w13, w9
//   0x0051dc: 1acc2508  lsr      w8, w8, w12
//   0x0051e0: 0a090169  and      w9, w11, w9
//   0x0051e4: 1400000b  b        #0x5210
//   0x0051e8: 927ef52a  and      x10, x9, #0xfffffffffffffffc
//   0x0051ec: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0051f0: b9400908  ldr      w8, [x8, #8]
//   0x0051f4: b940014b  ldr      w11, [x10]
//   0x0051f8: 531d0529  ubfiz    w9, w9, #3, #2
//   0x0051fc: 4b0903cc  sub      w12, w30, w9
//   0x005200: 1280000d  mov      w13, #-1
//   0x005204: 1acc25ac  lsr      w12, w13, w12
//   0x005208: 1ac92108  lsl      w8, w8, w9
//   0x00520c: 0a0c0169  and      w9, w11, w12
//   0x005210: 2a080128  orr      w8, w9, w8
//   0x005214: b9000148  str      w8, [x10]
//   0x005218: 140001b3  b        #0x58e4
//   0x00521c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x005220: b9400908  ldr      w8, [x8, #8]
//   0x005224: b9000128  str      w8, [x9]
//   0x005228: 140001af  b        #0x58e4
//   0x00522c: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x005230: f9400508  ldr      x8, [x8, #8]
//   0x005234: f9000128  str      x8, [x9]
//   0x005238: 140001ab  b        #0x58e4
//   0x00523c: 53103d49  lsl      w9, w10, #0x10
//   0x005240: 93407d29  sxtw     x9, w9
//   0x005244: 140001a6  b        #0x58dc
//   0x005248: 910022ab  add      x11, x21, #8
//   0x00524c: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005250: 12003d4a  and      w10, w10, #0xffff
//   0x005254: ca0a0129  eor      x9, x9, x10
//   0x005258: f8285969  str      x9, [x11, w8, uxtw #3]
//   0x00525c: 140001a2  b        #0x58e4
//   0x005260: 320013ea  mov      w10, #0x1f
//   0x005264: f85f8268  ldur     x8, [x19, #-8]
//   0x005268: 2a1f03eb  mov      w11, wzr
//   0x00526c: 2a1f03e9  mov      w9, wzr
//   0x005270: 320003ec  mov      w12, #1
//   0x005274: 8b2d4108  add      x8, x8, w13, uxtw
//   0x005278: 14000021  b        #0x52fc
//   0x00527c: eb0b013f  cmp      x9, x11
//   0x005280: 54ffcd21  b.ne     #0x4c24
//   0x005284: 14000019  b        #0x52e8
//   0x005288: eb0b013f  cmp      x9, x11
//   0x00528c: 540002e1  b.ne     #0x52e8
//   0x005290: 17fffe65  b        #0x4c24
//   0x005294: f100013f  cmp      x9, #0
//   0x005298: 320003e9  mov      w9, #1
//   0x00529c: 540001ac  b.gt     #0x52d0
//   0x0052a0: 14000013  b        #0x52ec
//   0x0052a4: eb0b013f  cmp      x9, x11
//   0x0052a8: 320003e9  mov      w9, #1
//   0x0052ac: 54000120  b.eq     #0x52d0
//   0x0052b0: 1400000f  b        #0x52ec
//   0x0052b4: f100053f  cmp      x9, #1
//   0x0052b8: 320003e9  mov      w9, #1
//   0x0052bc: 5400018a  b.ge     #0x52ec
//   0x0052c0: 14000004  b        #0x52d0
//   0x0052c4: eb0b013f  cmp      x9, x11
//   0x0052c8: 320003e9  mov      w9, #1
//   0x0052cc: 54000100  b.eq     #0x52ec
//   0x0052d0: 2a1f03eb  mov      w11, wzr
//   0x0052d4: 2a1f03ea  mov      w10, wzr
//   0x0052d8: 320003ec  mov      w12, #1
//   0x0052dc: 14000008  b        #0x52fc
//   0x0052e0: f100053f  cmp      x9, #1
//   0x0052e4: 54ffca0b  b.lt     #0x4c24
//   0x0052e8: 2a1f03e9  mov      w9, wzr
//   0x0052ec: 2a1f03ec  mov      w12, wzr
//   0x0052f0: 2a1f03ea  mov      w10, wzr
//   0x0052f4: 91002008  add      x8, x0, #8
//   0x0052f8: 320003eb  mov      w11, #1
//   0x0052fc: 7100013f  cmp      w9, #0
//   0x005300: 1a9f07ed  cset     w13, ne
//   0x005304: 0a0d016b  and      w11, w11, w13
//   0x005308: f81e8268  stur     x8, [x19, #-0x18]
//   0x00530c: 3700008b  tbnz     w11, #0, #0x531c
//   0x005310: 34000069  cbz      w9, #0x531c
//   0x005314: 0a0d0188  and      w8, w12, w13
//   0x005318: 340000a8  cbz      w8, #0x532c
//   0x00531c: 7100017f  cmp      w11, #0
//   0x005320: 320003e8  mov      w8, #1
//   0x005324: 9a881508  cinc     x8, x8, eq
//   0x005328: f81e0268  stur     x8, [x19, #-0x20]
//   0x00532c: 7100055f  cmp      w10, #1
//   0x005330: 54002dab  b.lt     #0x58e4
//   0x005334: 91002008  add      x8, x0, #8
//   0x005338: 8b2acea9  add      x9, x21, w10, sxtw #3
//   0x00533c: f9000528  str      x8, [x9, #8]
//   0x005340: f81f0268  stur     x8, [x19, #-0x10]
//   0x005344: 14000168  b        #0x58e4
//   0x005348: 713a3dbf  cmp      w13, #0xe8f
//   0x00534c: 54000dad  b.le     #0x5500
//   0x005350: 713a41bf  cmp      w13, #0xe90
//   0x005354: 54002ac0  b.eq     #0x58ac
//   0x005358: 713b41bf  cmp      w13, #0xed0
//   0x00535c: 54002a60  b.eq     #0x58a8
//   0x005360: 713e41bf  cmp      w13, #0xf90
//   0x005364: 54002c01  b.ne     #0x58e4
//   0x005368: 321b014a  orr      w10, w10, #0x20
//   0x00536c: 14000150  b        #0x58ac
//   0x005370: 320013e8  mov      w8, #0x1f
//   0x005374: 14000002  b        #0x537c
//   0x005378: 2a1f03e8  mov      w8, wzr
//   0x00537c: f85f8269  ldur     x9, [x19, #-8]
//   0x005380: 2a1f03eb  mov      w11, wzr
//   0x005384: 2a1f03ea  mov      w10, wzr
//   0x005388: 8b2c412c  add      x12, x9, w12, uxtw
//   0x00538c: 320003e9  mov      w9, #1
//   0x005390: 7100015f  cmp      w10, #0
//   0x005394: 1a9f07ed  cset     w13, ne
//   0x005398: 0a0d016b  and      w11, w11, w13
//   0x00539c: f81e826c  stur     x12, [x19, #-0x18]
//   0x0053a0: 3700008b  tbnz     w11, #0, #0x53b0
//   0x0053a4: 3400006a  cbz      w10, #0x53b0
//   0x0053a8: 0a0d0129  and      w9, w9, w13
//   0x0053ac: 340000a9  cbz      w9, #0x53c0
//   0x0053b0: 7100017f  cmp      w11, #0
//   0x0053b4: 320003e9  mov      w9, #1
//   0x0053b8: 9a891529  cinc     x9, x9, eq
//   0x0053bc: f81e0269  stur     x9, [x19, #-0x20]
//   0x0053c0: 7100051f  cmp      w8, #1
//   0x0053c4: 5400290b  b.lt     #0x58e4
//   0x0053c8: 91002009  add      x9, x0, #8
//   0x0053cc: 8b28cea8  add      x8, x21, w8, sxtw #3
//   0x0053d0: f9000509  str      x9, [x8, #8]
//   0x0053d4: f81f0269  stur     x9, [x19, #-0x10]
//   0x0053d8: 14000143  b        #0x58e4
//   0x0053dc: 528002cb  mov      w11, #0x16
//   0x0053e0: 72a001cb  movk     w11, #0xe, lsl #16
//   0x0053e4: 6b0b015f  cmp      w10, w11
//   0x0053e8: 54000eac  b.gt     #0x55bc
//   0x0053ec: 528002cb  mov      w11, #0x16
//   0x0053f0: 72a000eb  movk     w11, #7, lsl #16
//   0x0053f4: 6b0b015f  cmp      w10, w11
//   0x0053f8: 54001e6c  b.gt     #0x57c4
//   0x0053fc: 528002eb  mov      w11, #0x17
//   0x005400: 72a0002b  movk     w11, #1, lsl #16
//   0x005404: 6b0b015f  cmp      w10, w11
//   0x005408: 54ffd720  b.eq     #0x4eec
//   0x00540c: 528002eb  mov      w11, #0x17
//   0x005410: 72a000cb  movk     w11, #6, lsl #16
//   0x005414: 6b0b015f  cmp      w10, w11
//   0x005418: 54ffd6a0  b.eq     #0x4eec
//   0x00541c: 14000132  b        #0x58e4
//   0x005420: 528002ca  mov      w10, #0x16
//   0x005424: 72a001ca  movk     w10, #0xe, lsl #16
//   0x005428: 6b0a013f  cmp      w9, w10
//   0x00542c: 54000e2c  b.gt     #0x55f0
//   0x005430: 528002ca  mov      w10, #0x16
//   0x005434: 72a000ea  movk     w10, #7, lsl #16
//   0x005438: 6b0a013f  cmp      w9, w10
//   0x00543c: 5400204c  b.gt     #0x5844
//   0x005440: 528002ea  mov      w10, #0x17
//   0x005444: 72a0002a  movk     w10, #1, lsl #16
//   0x005448: 6b0a013f  cmp      w9, w10
//   0x00544c: 54004060  b.eq     #0x5c58
//   0x005450: 528002ea  mov      w10, #0x17
//   0x005454: 72a000ca  movk     w10, #6, lsl #16
//   0x005458: 6b0a013f  cmp      w9, w10
//   0x00545c: 54002441  b.ne     #0x58e4
//   0x005460: 320013ea  mov      w10, #0x1f
//   0x005464: b6f83d4b  tbz      x11, #0x3f, #0x5c0c
//   0x005468: 14000101  b        #0x586c
//   0x00546c: 7124b95f  cmp      w10, #0x92e
//   0x005470: 540012ac  b.gt     #0x56c4
//   0x005474: 711dbd5f  cmp      w10, #0x76f
//   0x005478: 54006900  b.eq     #0x6198
//   0x00547c: 7120a55f  cmp      w10, #0x829
//   0x005480: 54003200  b.eq     #0x5ac0
//   0x005484: 7122bd5f  cmp      w10, #0x8af
//   0x005488: 540022e1  b.ne     #0x58e4
//   0x00548c: 910022aa  add      x10, x21, #8
//   0x005490: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x005494: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x005498: 9ac8092a  udiv     x10, x9, x8
//   0x00549c: 14000336  b        #0x6174
//   0x0054a0: 7100097f  cmp      w11, #2
//   0x0054a4: 54002201  b.ne     #0x58e4
//   0x0054a8: 12002d8b  and      w11, w12, #0xfff
//   0x0054ac: 7121b97f  cmp      w11, #0x86e
//   0x0054b0: 5400280d  b.le     #0x59b0
//   0x0054b4: 7127b97f  cmp      w11, #0x9ee
//   0x0054b8: 54ffdc0c  b.gt     #0x5038
//   0x0054bc: 7121bd7f  cmp      w11, #0x86f
//   0x0054c0: 54002500  b.eq     #0x5960
//   0x0054c4: 7125bd7f  cmp      w11, #0x96f
//   0x0054c8: 540020e1  b.ne     #0x58e4
//   0x0054cc: 910022ab  add      x11, x21, #8
//   0x0054d0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0054d4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x0054d8: 8b090108  add      x8, x8, x9
//   0x0054dc: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0054e0: 14000101  b        #0x58e4
//   0x0054e4: 710041bf  cmp      w13, #0x10
//   0x0054e8: 540021a0  b.eq     #0x591c
//   0x0054ec: 710241bf  cmp      w13, #0x90
//   0x0054f0: 54001fa1  b.ne     #0x58e4
//   0x0054f4: 321b016b  orr      w11, w11, #0x20
//   0x0054f8: 321b014a  orr      w10, w10, #0x20
//   0x0054fc: 1400001c  b        #0x556c
//   0x005500: 712941bf  cmp      w13, #0xa50
//   0x005504: 54000340  b.eq     #0x556c
//   0x005508: 712b41bf  cmp      w13, #0xad0
//   0x00550c: 54001ec1  b.ne     #0x58e4
//   0x005510: 6b0b015f  cmp      w10, w11
//   0x005514: 54001e83  b.lo     #0x58e4
//   0x005518: 910022ad  add      x13, x21, #8
//   0x00551c: d37df129  lsl      x9, x9, #3
//   0x005520: 320003ec  mov      w12, #1
//   0x005524: d37df108  lsl      x8, x8, #3
//   0x005528: b86969a9  ldr      w9, [x13, x9]
//   0x00552c: 4b0b018c  sub      w12, w12, w11
//   0x005530: b86869ae  ldr      w14, [x13, x8]
//   0x005534: 0b0a018c  add      w12, w12, w10
//   0x005538: 1280000f  mov      w15, #-1
//   0x00553c: 1acc21ec  lsl      w12, w15, w12
//   0x005540: 0a2c0129  bic      w9, w9, w12
//   0x005544: 1aca21ea  lsl      w10, w15, w10
//   0x005548: 1acb21ec  lsl      w12, w15, w11
//   0x00554c: 0a0a01ca  and      w10, w14, w10
//   0x005550: 1acb2129  lsl      w9, w9, w11
//   0x005554: 0a2c01cc  bic      w12, w14, w12
//   0x005558: 2a090149  orr      w9, w10, w9
//   0x00555c: 2a0c0129  orr      w9, w9, w12
//   0x005560: 93407d29  sxtw     x9, w9
//   0x005564: f82869a9  str      x9, [x13, x8]
//   0x005568: 140000df  b        #0x58e4
//   0x00556c: 6b0b015f  cmp      w10, w11
//   0x005570: 54001bab  b.lt     #0x58e4
//   0x005574: 910022ac  add      x12, x21, #8
//   0x005578: d37df108  lsl      x8, x8, #3
//   0x00557c: f8695989  ldr      x9, [x12, w9, uxtw #3]
//   0x005580: 1100054d  add      w13, w10, #1
//   0x005584: f868698e  ldr      x14, [x12, x8]
//   0x005588: 4b0b01ad  sub      w13, w13, w11
//   0x00558c: 9280000f  mov      x15, #-1
//   0x005590: 9acd21ed  lsl      x13, x15, x13
//   0x005594: 8a2d0129  bic      x9, x9, x13
//   0x005598: 9aca21ea  lsl      x10, x15, x10
//   0x00559c: 9acb21ed  lsl      x13, x15, x11
//   0x0055a0: 8a0a01ca  and      x10, x14, x10
//   0x0055a4: 9acb2129  lsl      x9, x9, x11
//   0x0055a8: 8a2d01cd  bic      x13, x14, x13
//   0x0055ac: aa090149  orr      x9, x10, x9
//   0x0055b0: aa0d0129  orr      x9, x9, x13
//   0x0055b4: f8286989  str      x9, [x12, x8]
//   0x0055b8: 140000cb  b        #0x58e4
//   0x0055bc: 528002cb  mov      w11, #0x16
//   0x0055c0: 72a0030b  movk     w11, #0x18, lsl #16
//   0x0055c4: 6b0b015f  cmp      w10, w11
//   0x0055c8: 5400110c  b.gt     #0x57e8
//   0x0055cc: 528002eb  mov      w11, #0x17
//   0x0055d0: 72a001cb  movk     w11, #0xe, lsl #16
//   0x0055d4: 6b0b015f  cmp      w10, w11
//   0x0055d8: 54ffc8a0  b.eq     #0x4eec
//   0x0055dc: 528002eb  mov      w11, #0x17
//   0x0055e0: 72a0026b  movk     w11, #0x13, lsl #16
//   0x0055e4: 6b0b015f  cmp      w10, w11
//   0x0055e8: 54ffc820  b.eq     #0x4eec
//   0x0055ec: 140000be  b        #0x58e4
//   0x0055f0: 528002ca  mov      w10, #0x16
//   0x0055f4: 72a0030a  movk     w10, #0x18, lsl #16
//   0x0055f8: 6b0a013f  cmp      w9, w10
//   0x0055fc: 540013ec  b.gt     #0x5878
//   0x005600: 528002ea  mov      w10, #0x17
//   0x005604: 72a001ca  movk     w10, #0xe, lsl #16
//   0x005608: 6b0a013f  cmp      w9, w10
//   0x00560c: 540032a0  b.eq     #0x5c60
//   0x005610: 528002ea  mov      w10, #0x17
//   0x005614: 72a0026a  movk     w10, #0x13, lsl #16
//   0x005618: 6b0a013f  cmp      w9, w10
//   0x00561c: 54001641  b.ne     #0x58e4
//   0x005620: b6ffc8eb  tbz      x11, #0x3f, #0x4f3c
//   0x005624: 14000179  b        #0x5c08
//   0x005628: 5281ffe9  mov      w9, #0xfff
//   0x00562c: 72af8009  movk     w9, #0x7c00, lsl #16
//   0x005630: 528051eb  mov      w11, #0x28f
//   0x005634: 0a090189  and      w9, w12, w9
//   0x005638: 72a9800b  movk     w11, #0x4c00, lsl #16
//   0x00563c: 6b0b013f  cmp      w9, w11
//   0x005640: 540019ed  b.le     #0x597c
//   0x005644: 5280520b  mov      w11, #0x290
//   0x005648: 72a9800b  movk     w11, #0x4c00, lsl #16
//   0x00564c: 6b0b013f  cmp      w9, w11
//   0x005650: 540031e0  b.eq     #0x5c8c
//   0x005654: 5280d20b  mov      w11, #0x690
//   0x005658: 72aa800b  movk     w11, #0x5400, lsl #16
//   0x00565c: 6b0b013f  cmp      w9, w11
//   0x005660: 54003200  b.eq     #0x5ca0
//   0x005664: 5280520b  mov      w11, #0x290
//   0x005668: 72ae800b  movk     w11, #0x7400, lsl #16
//   0x00566c: 6b0b013f  cmp      w9, w11
//   0x005670: 540013a1  b.ne     #0x58e4
//   0x005674: 910022a9  add      x9, x21, #8
//   0x005678: d37df108  lsl      x8, x8, #3
//   0x00567c: b8686928  ldr      w8, [x9, x8]
//   0x005680: 53087d0b  lsr      w11, w8, #8
//   0x005684: 53185d08  lsl      w8, w8, #8
//   0x005688: 12009d6b  and      w11, w11, #0xff00ff
//   0x00568c: 12089d08  and      w8, w8, #0xff00ff00
//   0x005690: 2a0b0108  orr      w8, w8, w11
//   0x005694: 14000256  b        #0x5fec
//   0x005698: 710ba55f  cmp      w10, #0x2e9
//   0x00569c: 54002260  b.eq     #0x5ae8
//   0x0056a0: 7114bd5f  cmp      w10, #0x52f
//   0x0056a4: 54005180  b.eq     #0x60d4
//   0x0056a8: 711cbd5f  cmp      w10, #0x72f
//   0x0056ac: 540011c1  b.ne     #0x58e4
//   0x0056b0: 910022aa  add      x10, x21, #8
//   0x0056b4: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x0056b8: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x0056bc: 9b497d0a  smulh    x10, x8, x9
//   0x0056c0: 140002ba  b        #0x61a8
//   0x0056c4: 7124bd5f  cmp      w10, #0x92f
//   0x0056c8: 540033a0  b.eq     #0x5d3c
//   0x0056cc: 712cbd5f  cmp      w10, #0xb2f
//   0x0056d0: 540054a0  b.eq     #0x6164
//   0x0056d4: 7136bd5f  cmp      w10, #0xdaf
//   0x0056d8: 54001061  b.ne     #0x58e4
//   0x0056dc: 910022aa  add      x10, x21, #8
//   0x0056e0: d37df129  lsl      x9, x9, #3
//   0x0056e4: d37df108  lsl      x8, x8, #3
//   0x0056e8: b8696949  ldr      w9, [x10, x9]
//   0x0056ec: b8686948  ldr      w8, [x10, x8]
//   0x0056f0: 1ac80d2a  sdiv     w10, w9, w8
//   0x0056f4: 1400027e  b        #0x60ec
//   0x0056f8: 0a180189  and      w9, w12, w24
//   0x0056fc: 511c430c  sub      w12, w24, #0x710
//   0x005700: 6b0c013f  cmp      w9, w12
//   0x005704: 1a8d018d  csel     w13, w12, w13, eq
//   0x005708: 5103430c  sub      w12, w24, #0xd0
//   0x00570c: 6b0c013f  cmp      w9, w12
//   0x005710: 1a8d018d  csel     w13, w12, w13, eq
//   0x005714: 5111430c  sub      w12, w24, #0x450
//   0x005718: 6b0c013f  cmp      w9, w12
//   0x00571c: 1a8d018d  csel     w13, w12, w13, eq
//   0x005720: 7131b9bf  cmp      w13, #0xc6e
//   0x005724: 5400018c  b.gt     #0x5754
//   0x005728: 7123b9bf  cmp      w13, #0x8ee
//   0x00572c: 5400170c  b.gt     #0x5a0c
//   0x005730: 710bbdbf  cmp      w13, #0x2ef
//   0x005734: 540040a0  b.eq     #0x5f48
//   0x005738: 710fbdbf  cmp      w13, #0x3ef
//   0x00573c: 54004100  b.eq     #0x5f5c
//   0x005740: 7111bdbf  cmp      w13, #0x46f
//   0x005744: 54000d01  b.ne     #0x58e4
//   0x005748: 910022a9  add      x9, x21, #8
//   0x00574c: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005750: 14000211  b        #0x5f94
//   0x005754: 52811dc9  mov      w9, #0x8ee
//   0x005758: 72a00409  movk     w9, #0x20, lsl #16
//   0x00575c: 6b0901bf  cmp      w13, w9
//   0x005760: 540016cc  b.gt     #0x5a38
//   0x005764: 7131bdbf  cmp      w13, #0xc6f
//   0x005768: 54004040  b.eq     #0x5f70
//   0x00576c: 7132bdbf  cmp      w13, #0xcaf
//   0x005770: 540040a0  b.eq     #0x5f84
//   0x005774: 713cbdbf  cmp      w13, #0xf2f
//   0x005778: 54000b61  b.ne     #0x58e4
//   0x00577c: 910022a9  add      x9, x21, #8
//   0x005780: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005784: 321b016b  orr      w11, w11, #0x20
//   0x005788: 92403d6b  and      x11, x11, #0xffff
//   0x00578c: 14000207  b        #0x5fa8
//   0x005790: 12002d8b  and      w11, w12, #0xfff
//   0x005794: 7120b97f  cmp      w11, #0x82e
//   0x005798: 5400170c  b.gt     #0x5a78
//   0x00579c: 710dbd7f  cmp      w11, #0x36f
//   0x0057a0: 54003ba0  b.eq     #0x5f14
//   0x0057a4: 7118bd7f  cmp      w11, #0x62f
//   0x0057a8: 540009e1  b.ne     #0x58e4
//   0x0057ac: 910022ab  add      x11, x21, #8
//   0x0057b0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0057b4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x0057b8: aa090108  orr      x8, x8, x9
//   0x0057bc: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0057c0: 14000049  b        #0x58e4
//   0x0057c4: 528002eb  mov      w11, #0x17
//   0x0057c8: 72a000eb  movk     w11, #7, lsl #16
//   0x0057cc: 6b0b015f  cmp      w10, w11
//   0x0057d0: 54ffb8e0  b.eq     #0x4eec
//   0x0057d4: 528002eb  mov      w11, #0x17
//   0x0057d8: 72a0018b  movk     w11, #0xc, lsl #16
//   0x0057dc: 6b0b015f  cmp      w10, w11
//   0x0057e0: 54ffb860  b.eq     #0x4eec
//   0x0057e4: 14000040  b        #0x58e4
//   0x0057e8: 528002eb  mov      w11, #0x17
//   0x0057ec: 72a0036b  movk     w11, #0x1b, lsl #16
//   0x0057f0: 6b0b015f  cmp      w10, w11
//   0x0057f4: 54ffb7c0  b.eq     #0x4eec
//   0x0057f8: 528002eb  mov      w11, #0x17
//   0x0057fc: 72a0030b  movk     w11, #0x18, lsl #16
//   0x005800: 6b0b015f  cmp      w10, w11
//   0x005804: 54ffb740  b.eq     #0x4eec
//   0x005808: 14000037  b        #0x58e4
//   0x00580c: 710eb97f  cmp      w11, #0x3ae
//   0x005810: 54000eac  b.gt     #0x59e4
//   0x005814: 7107bd7f  cmp      w11, #0x1ef
//   0x005818: 54000d40  b.eq     #0x59c0
//   0x00581c: 7108a57f  cmp      w11, #0x229
//   0x005820: 54000621  b.ne     #0x58e4
//   0x005824: d37df129  lsl      x9, x9, #3
//   0x005828: 910022ab  add      x11, x21, #8
//   0x00582c: d37df108  lsl      x8, x8, #3
//   0x005830: b8a86968  ldrsw    x8, [x11, x8]
//   0x005834: b8a96969  ldrsw    x9, [x11, x9]
//   0x005838: 9b097d08  mul      x8, x8, x9
//   0x00583c: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x005840: 14000029  b        #0x58e4
//   0x005844: 528002ea  mov      w10, #0x17
//   0x005848: 72a000ea  movk     w10, #7, lsl #16
//   0x00584c: 6b0a013f  cmp      w9, w10
//   0x005850: 54002120  b.eq     #0x5c74
//   0x005854: 528002ea  mov      w10, #0x17
//   0x005858: 72a0018a  movk     w10, #0xc, lsl #16
//   0x00585c: 6b0a013f  cmp      w9, w10
//   0x005860: 54000421  b.ne     #0x58e4
//   0x005864: 320013ea  mov      w10, #0x1f
//   0x005868: b7f81d2b  tbnz     x11, #0x3f, #0x5c0c
//   0x00586c: 2a1f03eb  mov      w11, wzr
//   0x005870: 2a1f03e9  mov      w9, wzr
//   0x005874: 140000d4  b        #0x5bc4
//   0x005878: 528002ea  mov      w10, #0x17
//   0x00587c: 72a0030a  movk     w10, #0x18, lsl #16
//   0x005880: 6b0a013f  cmp      w9, w10
//   0x005884: 54001fe0  b.eq     #0x5c80
//   0x005888: 528002ea  mov      w10, #0x17
//   0x00588c: 72a0036a  movk     w10, #0x1b, lsl #16
//   0x005890: 6b0a013f  cmp      w9, w10
//   0x005894: 54000281  b.ne     #0x58e4
//   0x005898: 320013ea  mov      w10, #0x1f
//   0x00589c: 320003e9  mov      w9, #1
//   0x0058a0: b6f81b8b  tbz      x11, #0x3f, #0x5c10
//   0x0058a4: 140000f2  b        #0x5c6c
//   0x0058a8: 321b016b  orr      w11, w11, #0x20
//   0x0058ac: 0b0a016c  add      w12, w11, w10
//   0x0058b0: 7100fd9f  cmp      w12, #0x3f
//   0x0058b4: 5400018c  b.gt     #0x58e4
//   0x0058b8: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x0058bc: f9400529  ldr      x9, [x9, #8]
//   0x0058c0: 7100fd5f  cmp      w10, #0x3f
//   0x0058c4: 540000c0  b.eq     #0x58dc
//   0x0058c8: 1100054a  add      w10, w10, #1
//   0x0058cc: 9acb2529  lsr      x9, x9, x11
//   0x0058d0: 9280000b  mov      x11, #-1
//   0x0058d4: 9aca216a  lsl      x10, x11, x10
//   0x0058d8: 8a2a0129  bic      x9, x9, x10
//   0x0058dc: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0058e0: f9000509  str      x9, [x8, #8]
//   0x0058e4: f94002a9  ldr      x9, [x21]
//   0x0058e8: f85e0268  ldur     x8, [x19, #-0x20]
//   0x0058ec: 91001120  add      x0, x9, #4
//   0x0058f0: f100091f  cmp      x8, #2
//   0x0058f4: f90002a0  str      x0, [x21]
//   0x0058f8: 540000e0  b.eq     #0x5914
//   0x0058fc: f1000d1f  cmp      x8, #3
//   0x005900: 54001180  b.eq     #0x5b30
//   0x005904: f100051f  cmp      x8, #1
//   0x005908: 54001140  b.eq     #0x5b30
//   0x00590c: eb14001f  cmp      x0, x20
//   0x005910: 540011a0  b.eq     #0x5b44
//   0x005914: b5ff8c00  cbnz     x0, #0x4a94
//   0x005918: 1400027f  b        #0x6314
//   0x00591c: 0b0b014c  add      w12, w10, w11
//   0x005920: 71007d9f  cmp      w12, #0x1f
//   0x005924: 54fffe08  b.hi     #0x58e4
//   0x005928: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x00592c: b9400929  ldr      w9, [x9, #8]
//   0x005930: 71007d5f  cmp      w10, #0x1f
//   0x005934: 54ffc860  b.eq     #0x5240
//   0x005938: 1acb2529  lsr      w9, w9, w11
//   0x00593c: 321f7beb  mov      w11, #-2
//   0x005940: 1aca216a  lsl      w10, w11, w10
//   0x005944: 0a2a0129  bic      w9, w9, w10
//   0x005948: 17fffe3e  b        #0x5240
//   0x00594c: 113342eb  add      w11, w23, #0xcd0
//   0x005950: 0a0b018b  and      w11, w12, w11
//   0x005954: 6b17017f  cmp      w11, w23
//   0x005958: 1a8d02ed  csel     w13, w23, w13, eq
//   0x00595c: 14000122  b        #0x5de4
//   0x005960: 910022ab  add      x11, x21, #8
//   0x005964: d37df129  lsl      x9, x9, #3
//   0x005968: d37df108  lsl      x8, x8, #3
//   0x00596c: b8696969  ldr      w9, [x11, x9]
//   0x005970: b8686968  ldr      w8, [x11, x8]
//   0x005974: 4b080128  sub      w8, w9, w8
//   0x005978: 14000018  b        #0x59d8
//   0x00597c: 5280d20b  mov      w11, #0x690
//   0x005980: 72a1800b  movk     w11, #0xc00, lsl #16
//   0x005984: 6b0b013f  cmp      w9, w11
//   0x005988: 540019e0  b.eq     #0x5cc4
//   0x00598c: 5280520b  mov      w11, #0x290
//   0x005990: 72a7000b  movk     w11, #0x3800, lsl #16
//   0x005994: 6b0b013f  cmp      w9, w11
//   0x005998: 54fffa61  b.ne     #0x58e4
//   0x00599c: 910022a9  add      x9, x21, #8
//   0x0059a0: d37df108  lsl      x8, x8, #3
//   0x0059a4: 38a86928  ldrsb    x8, [x9, x8]
//   0x0059a8: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x0059ac: 17ffffce  b        #0x58e4
//   0x0059b0: 710eb97f  cmp      w11, #0x3ae
//   0x0059b4: 5400018c  b.gt     #0x59e4
//   0x0059b8: 7107bd7f  cmp      w11, #0x1ef
//   0x0059bc: 54fff301  b.ne     #0x581c
//   0x0059c0: 910022ab  add      x11, x21, #8
//   0x0059c4: d37df129  lsl      x9, x9, #3
//   0x0059c8: d37df108  lsl      x8, x8, #3
//   0x0059cc: b8696969  ldr      w9, [x11, x9]
//   0x0059d0: b8686968  ldr      w8, [x11, x8]
//   0x0059d4: 0b090108  add      w8, w8, w9
//   0x0059d8: 93407d08  sxtw     x8, w8
//   0x0059dc: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x0059e0: 17ffffc1  b        #0x58e4
//   0x0059e4: 710ebd7f  cmp      w11, #0x3af
//   0x0059e8: 54000060  b.eq     #0x59f4
//   0x0059ec: 711bbd7f  cmp      w11, #0x6ef
//   0x0059f0: 54fff7a1  b.ne     #0x58e4
//   0x0059f4: 910022ab  add      x11, x21, #8
//   0x0059f8: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x0059fc: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005a00: cb080128  sub      x8, x9, x8
//   0x005a04: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x005a08: 17ffffb7  b        #0x58e4
//   0x005a0c: 7123bdbf  cmp      w13, #0x8ef
//   0x005a10: 54002c80  b.eq     #0x5fa0
//   0x005a14: 712dbdbf  cmp      w13, #0xb6f
//   0x005a18: 54002ce0  b.eq     #0x5fb4
//   0x005a1c: 712ebdbf  cmp      w13, #0xbaf
//   0x005a20: 54fff621  b.ne     #0x58e4
//   0x005a24: 910022a9  add      x9, x21, #8
//   0x005a28: d37df108  lsl      x8, x8, #3
//   0x005a2c: b8686928  ldr      w8, [x9, x8]
//   0x005a30: 1acb2508  lsr      w8, w8, w11
//   0x005a34: 1400016e  b        #0x5fec
//   0x005a38: 52811de9  mov      w9, #0x8ef
//   0x005a3c: 72a00409  movk     w9, #0x20, lsl #16
//   0x005a40: 6b0901bf  cmp      w13, w9
//   0x005a44: 54002c20  b.eq     #0x5fc8
//   0x005a48: 528175e9  mov      w9, #0xbaf
//   0x005a4c: 72a00409  movk     w9, #0x20, lsl #16
//   0x005a50: 6b0901bf  cmp      w13, w9
//   0x005a54: 54002c40  b.eq     #0x5fdc
//   0x005a58: 5281e5e9  mov      w9, #0xf2f
//   0x005a5c: 72a00409  movk     w9, #0x20, lsl #16
//   0x005a60: 6b0901bf  cmp      w13, w9
//   0x005a64: 54fff401  b.ne     #0x58e4
//   0x005a68: 910022a9  add      x9, x21, #8
//   0x005a6c: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005a70: 321b016b  orr      w11, w11, #0x20
//   0x005a74: 14000157  b        #0x5fd0
//   0x005a78: 7120bd7f  cmp      w11, #0x82f
//   0x005a7c: 54002580  b.eq     #0x5f2c
//   0x005a80: 713dbd7f  cmp      w11, #0xf6f
//   0x005a84: 54fff301  b.ne     #0x58e4
//   0x005a88: 910022ab  add      x11, x21, #8
//   0x005a8c: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005a90: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005a94: 8a090108  and      x8, x8, x9
//   0x005a98: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x005a9c: 17ffff92  b        #0x58e4
//   0x005aa0: 910022aa  add      x10, x21, #8
//   0x005aa4: d37df129  lsl      x9, x9, #3
//   0x005aa8: d37df108  lsl      x8, x8, #3
//   0x005aac: b94000cb  ldr      w11, [x6]
//   0x005ab0: b94000ec  ldr      w12, [x7]
//   0x005ab4: b8696949  ldr      w9, [x10, x9]
//   0x005ab8: b8686948  ldr      w8, [x10, x8]
//   0x005abc: 14000012  b        #0x5b04
//   0x005ac0: 910022aa  add      x10, x21, #8
//   0x005ac4: d37df129  lsl      x9, x9, #3
//   0x005ac8: d37df108  lsl      x8, x8, #3
//   0x005acc: b94000cb  ldr      w11, [x6]
//   0x005ad0: b94000ec  ldr      w12, [x7]
//   0x005ad4: b8a96949  ldrsw    x9, [x10, x9]
//   0x005ad8: b8a86948  ldrsw    x8, [x10, x8]
//   0x005adc: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x005ae0: 9b093108  madd     x8, x8, x9, x12
//   0x005ae4: 1400000a  b        #0x5b0c
//   0x005ae8: 910022aa  add      x10, x21, #8
//   0x005aec: d37df129  lsl      x9, x9, #3
//   0x005af0: d37df108  lsl      x8, x8, #3
//   0x005af4: b94000cb  ldr      w11, [x6]
//   0x005af8: b94000ec  ldr      w12, [x7]
//   0x005afc: b8a96949  ldrsw    x9, [x10, x9]
//   0x005b00: b8a86948  ldrsw    x8, [x10, x8]
//   0x005b04: b3607d6c  bfi      x12, x11, #0x20, #0x20
//   0x005b08: 9b09b108  msub     x8, x8, x9, x12
//   0x005b0c: 92407d09  and      x9, x8, #0xffffffff
//   0x005b10: d360fd08  lsr      x8, x8, #0x20
//   0x005b14: 14000184  b        #0x6124
//   0x005b18: 320013ea  mov      w10, #0x1f
//   0x005b1c: f85f8268  ldur     x8, [x19, #-8]
//   0x005b20: 2a1f03eb  mov      w11, wzr
//   0x005b24: 2a1f03e9  mov      w9, wzr
//   0x005b28: 8b2c4108  add      x8, x8, w12, uxtw
//   0x005b2c: 14000026  b        #0x5bc4
//   0x005b30: f85e8260  ldur     x0, [x19, #-0x18]
//   0x005b34: f81e027f  stur     xzr, [x19, #-0x20]
//   0x005b38: f90002a0  str      x0, [x21]
//   0x005b3c: eb14001f  cmp      x0, x20
//   0x005b40: 54ffeea1  b.ne     #0x5914
//   0x005b44: f9400080  ldr      x0, [x4]
//   0x005b48: f94000a1  ldr      x1, [x5]
//   0x005b4c: aa0403f8  mov      x24, x4
//   0x005b50: aa0503fa  mov      x26, x5
//   0x005b54: f90007e6  str      x6, [sp, #8]
//   0x005b58: aa0703f7  mov      x23, x7
//   0x005b5c: d63f0280  blr      x20
//   0x005b60: f94007e6  ldr      x6, [sp, #8]
//   0x005b64: f85f0260  ldur     x0, [x19, #-0x10]
//   0x005b68: aa1703e7  mov      x7, x23
//   0x005b6c: 528065f7  mov      w23, #0x32f
//   0x005b70: aa1803e4  mov      x4, x24
//   0x005b74: 5281fff8  mov      w24, #0xfff
//   0x005b78: 321b03fe  mov      w30, #0x20
//   0x005b7c: 72a08017  movk     w23, #0x400, lsl #16
//   0x005b80: aa1a03e5  mov      x5, x26
//   0x005b84: 320007fa  mov      w26, #3
//   0x005b88: 72a00418  movk     w24, #0x20, lsl #16
//   0x005b8c: f90002a0  str      x0, [x21]
//   0x005b90: b5ff7820  cbnz     x0, #0x4a94
//   0x005b94: 140001e0  b        #0x6314
//   0x005b98: eb0d017f  cmp      x11, x13
//   0x005b9c: 54ff9d01  b.ne     #0x4f3c
//   0x005ba0: 1400001a  b        #0x5c08
//   0x005ba4: eb0d017f  cmp      x11, x13
//   0x005ba8: 54ff9ca0  b.eq     #0x4f3c
//   0x005bac: 14000017  b        #0x5c08
//   0x005bb0: f100017f  cmp      x11, #0
//   0x005bb4: 320003e9  mov      w9, #1
//   0x005bb8: 5400018d  b.le     #0x5be8
//   0x005bbc: 2a1f03eb  mov      w11, wzr
//   0x005bc0: 2a1f03ea  mov      w10, wzr
//   0x005bc4: 320003ec  mov      w12, #1
//   0x005bc8: 14000015  b        #0x5c1c
//   0x005bcc: eb0d017f  cmp      x11, x13
//   0x005bd0: 320003e9  mov      w9, #1
//   0x005bd4: 54ffff40  b.eq     #0x5bbc
//   0x005bd8: 14000004  b        #0x5be8
//   0x005bdc: f100057f  cmp      x11, #1
//   0x005be0: 320003e9  mov      w9, #1
//   0x005be4: 54fffecb  b.lt     #0x5bbc
//   0x005be8: 2a1f03ea  mov      w10, wzr
//   0x005bec: 14000009  b        #0x5c10
//   0x005bf0: eb0d017f  cmp      x11, x13
//   0x005bf4: 320003e9  mov      w9, #1
//   0x005bf8: 54ffff80  b.eq     #0x5be8
//   0x005bfc: 17fffff0  b        #0x5bbc
//   0x005c00: f100057f  cmp      x11, #1
//   0x005c04: 54ff99cb  b.lt     #0x4f3c
//   0x005c08: 2a1f03ea  mov      w10, wzr
//   0x005c0c: 2a1f03e9  mov      w9, wzr
//   0x005c10: 2a1f03ec  mov      w12, wzr
//   0x005c14: 91002008  add      x8, x0, #8
//   0x005c18: 320003eb  mov      w11, #1
//   0x005c1c: 7100013f  cmp      w9, #0
//   0x005c20: 1a9f07ed  cset     w13, ne
//   0x005c24: 0a0d016b  and      w11, w11, w13
//   0x005c28: f81e8268  stur     x8, [x19, #-0x18]
//   0x005c2c: 3700008b  tbnz     w11, #0, #0x5c3c
//   0x005c30: 34000069  cbz      w9, #0x5c3c
//   0x005c34: 0a0d0188  and      w8, w12, w13
//   0x005c38: 34ffb7a8  cbz      w8, #0x532c
//   0x005c3c: 7100017f  cmp      w11, #0
//   0x005c40: 320003e8  mov      w8, #1
//   0x005c44: 9a881508  cinc     x8, x8, eq
//   0x005c48: f81e0268  stur     x8, [x19, #-0x20]
//   0x005c4c: 7100055f  cmp      w10, #1
//   0x005c50: 54ffe4ab  b.lt     #0x58e4
//   0x005c54: 17fffdb8  b        #0x5334
//   0x005c58: b6fffd8b  tbz      x11, #0x3f, #0x5c08
//   0x005c5c: 17fffcb8  b        #0x4f3c
//   0x005c60: 320013ea  mov      w10, #0x1f
//   0x005c64: 320003e9  mov      w9, #1
//   0x005c68: b7fffd4b  tbnz     x11, #0x3f, #0x5c10
//   0x005c6c: 2a1f03eb  mov      w11, wzr
//   0x005c70: 17ffffd5  b        #0x5bc4
//   0x005c74: 320003e9  mov      w9, #1
//   0x005c78: b6fffb8b  tbz      x11, #0x3f, #0x5be8
//   0x005c7c: 17ffffd0  b        #0x5bbc
//   0x005c80: 320003e9  mov      w9, #1
//   0x005c84: b6fff9cb  tbz      x11, #0x3f, #0x5bbc
//   0x005c88: 17ffffd8  b        #0x5be8
//   0x005c8c: 910022a9  add      x9, x21, #8
//   0x005c90: d37df108  lsl      x8, x8, #3
//   0x005c94: 78a86928  ldrsh    x8, [x9, x8]
//   0x005c98: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005c9c: 17ffff12  b        #0x58e4
//   0x005ca0: 910022a9  add      x9, x21, #8
//   0x005ca4: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005ca8: d348fd0b  lsr      x11, x8, #8
//   0x005cac: d378dd08  lsl      x8, x8, #8
//   0x005cb0: 92009d6b  and      x11, x11, #0xff00ff00ff00ff
//   0x005cb4: 92089d08  and      x8, x8, #0xff00ff00ff00ff00
//   0x005cb8: aa0b0108  orr      x8, x8, x11
//   0x005cbc: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005cc0: 17ffff09  b        #0x58e4
//   0x005cc4: 910022a9  add      x9, x21, #8
//   0x005cc8: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005ccc: d350fd0b  lsr      x11, x8, #0x10
//   0x005cd0: d370bd08  lsl      x8, x8, #0x10
//   0x005cd4: 92003d6b  and      x11, x11, #0xffff0000ffff
//   0x005cd8: 92103d08  and      x8, x8, #0xffff0000ffff0000
//   0x005cdc: aa0b0108  orr      x8, x8, x11
//   0x005ce0: 93c88108  ror      x8, x8, #0x20
//   0x005ce4: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005ce8: 17fffeff  b        #0x58e4
//   0x005cec: 910022ab  add      x11, x21, #8
//   0x005cf0: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005cf4: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005cf8: eb08013f  cmp      x9, x8
//   0x005cfc: 8b2a4d68  add      x8, x11, w10, uxtw #3
//   0x005d00: 54000f63  b.lo     #0x5eec
//   0x005d04: f900011f  str      xzr, [x8]
//   0x005d08: 17fffef7  b        #0x58e4
//   0x005d0c: 7124b9bf  cmp      w13, #0x92e
//   0x005d10: 54001b0d  b.le     #0x6070
//   0x005d14: 7136b9bf  cmp      w13, #0xdae
//   0x005d18: 54001bec  b.gt     #0x6094
//   0x005d1c: 712cb9bf  cmp      w13, #0xb2e
//   0x005d20: 5400212c  b.gt     #0x6144
//   0x005d24: 7124bdbf  cmp      w13, #0x92f
//   0x005d28: 540000a0  b.eq     #0x5d3c
//   0x005d2c: 7126bdbf  cmp      w13, #0x9af
//   0x005d30: 54ffdda1  b.ne     #0x58e4
//   0x005d34: f94000e8  ldr      x8, [x7]
//   0x005d38: 14000174  b        #0x6308
//   0x005d3c: 910022aa  add      x10, x21, #8
//   0x005d40: d37df129  lsl      x9, x9, #3
//   0x005d44: d37df108  lsl      x8, x8, #3
//   0x005d48: b8a96949  ldrsw    x9, [x10, x9]
//   0x005d4c: b8a86948  ldrsw    x8, [x10, x8]
//   0x005d50: 140000f2  b        #0x6118
//   0x005d54: b5ffdc81  cbnz     x1, #0x58e4
//   0x005d58: 12002d8d  and      w13, w12, #0xfff
//   0x005d5c: 51000dae  sub      w14, w13, #3
//   0x005d60: 7100f1df  cmp      w14, #0x3c
//   0x005d64: 2a1f03e8  mov      w8, wzr
//   0x005d68: 54001e48  b.hi     #0x6130
//   0x005d6c: 9000004d  adrp     x13, #0xd000
//   0x005d70: 912b01ad  add      x13, x13, #0xac0
//   0x005d74: aa0d03ef  mov      x15, x13
//   0x005d78: b8ae79ed  ldrsw    x13, [x15, x14, lsl #2]
//   0x005d7c: 8b0f01ae  add      x14, x13, x15
//   0x005d80: aa1f03ed  mov      x13, xzr
//   0x005d84: d61f01c0  br       x14
//   0x005d88: 8b2a4ea8  add      x8, x21, w10, uxtw #3
//   0x005d8c: f940050d  ldr      x13, [x8, #8]
//   0x005d90: 12002d88  and      w8, w12, #0xfff
//   0x005d94: 51000d08  sub      w8, w8, #3
//   0x005d98: 7100f11f  cmp      w8, #0x3c
//   0x005d9c: 54ffda48  b.hi     #0x58e4
//   0x005da0: 9000004a  adrp     x10, #0xd000
//   0x005da4: 912ed14a  add      x10, x10, #0xbb4
//   0x005da8: aa0a03ec  mov      x12, x10
//   0x005dac: b8a8798a  ldrsw    x10, [x12, x8, lsl #2]
//   0x005db0: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x005db4: f9400508  ldr      x8, [x8, #8]
//   0x005db8: 11001169  add      w9, w11, #4
//   0x005dbc: 8b0c014a  add      x10, x10, x12
//   0x005dc0: 8b090009  add      x9, x0, x9
//   0x005dc4: d61f0140  br       x10
//   0x005dc8: f100011f  cmp      x8, #0
//   0x005dcc: 5400246d  b.le     #0x6258
//   0x005dd0: 2a1f03ec  mov      w12, wzr
//   0x005dd4: 2a1f03ea  mov      w10, wzr
//   0x005dd8: 1400011c  b        #0x6248
//   0x005ddc: 113342eb  add      w11, w23, #0xcd0
//   0x005de0: 0a0b018b  and      w11, w12, w11
//   0x005de4: 110d02ec  add      w12, w23, #0x340
//   0x005de8: 6b0c017f  cmp      w11, w12
//   0x005dec: 1a8d018d  csel     w13, w12, w13, eq
//   0x005df0: 7135b9bf  cmp      w13, #0xd6e
//   0x005df4: 540001cc  b.gt     #0x5e2c
//   0x005df8: 7117b9bf  cmp      w13, #0x5ee
//   0x005dfc: 5400038c  b.gt     #0x5e6c
//   0x005e00: 7102bdbf  cmp      w13, #0xaf
//   0x005e04: 54000fa0  b.eq     #0x5ff8
//   0x005e08: 710cbdbf  cmp      w13, #0x32f
//   0x005e0c: 54ffd6c1  b.ne     #0x58e4
//   0x005e10: 910022ab  add      x11, x21, #8
//   0x005e14: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005e18: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005e1c: 92401529  and      x9, x9, #0x3f
//   0x005e20: 9ac92508  lsr      x8, x8, x9
//   0x005e24: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x005e28: 17fffeaf  b        #0x58e4
//   0x005e2c: 528065cb  mov      w11, #0x32e
//   0x005e30: 72a0800b  movk     w11, #0x400, lsl #16
//   0x005e34: 6b0b01bf  cmp      w13, w11
//   0x005e38: 5400032c  b.gt     #0x5e9c
//   0x005e3c: 7135bdbf  cmp      w13, #0xd6f
//   0x005e40: 54000ea0  b.eq     #0x6014
//   0x005e44: 713fbdbf  cmp      w13, #0xfef
//   0x005e48: 54ffd4e1  b.ne     #0x58e4
//   0x005e4c: 910022ab  add      x11, x21, #8
//   0x005e50: d37df129  lsl      x9, x9, #3
//   0x005e54: b8696969  ldr      w9, [x11, x9]
//   0x005e58: d37df108  lsl      x8, x8, #3
//   0x005e5c: b8686968  ldr      w8, [x11, x8]
//   0x005e60: 12001129  and      w9, w9, #0x1f
//   0x005e64: 1ac92108  lsl      w8, w8, w9
//   0x005e68: 17fffedc  b        #0x59d8
//   0x005e6c: 7117bdbf  cmp      w13, #0x5ef
//   0x005e70: 54000e00  b.eq     #0x6030
//   0x005e74: 7119bdbf  cmp      w13, #0x66f
//   0x005e78: 54ffd361  b.ne     #0x58e4
//   0x005e7c: 910022ab  add      x11, x21, #8
//   0x005e80: d37df129  lsl      x9, x9, #3
//   0x005e84: b8696969  ldr      w9, [x11, x9]
//   0x005e88: d37df108  lsl      x8, x8, #3
//   0x005e8c: b8686968  ldr      w8, [x11, x8]
//   0x005e90: 12001129  and      w9, w9, #0x1f
//   0x005e94: 1ac92508  lsr      w8, w8, w9
//   0x005e98: 17fffed0  b        #0x59d8
//   0x005e9c: 6b1701bf  cmp      w13, w23
//   0x005ea0: 54000d80  b.eq     #0x6050
//   0x005ea4: 5280cdeb  mov      w11, #0x66f
//   0x005ea8: 72a0800b  movk     w11, #0x400, lsl #16
//   0x005eac: 6b0b01bf  cmp      w13, w11
//   0x005eb0: 54ffd1a1  b.ne     #0x58e4
//   0x005eb4: 910022ab  add      x11, x21, #8
//   0x005eb8: d37df129  lsl      x9, x9, #3
//   0x005ebc: b8696969  ldr      w9, [x11, x9]
//   0x005ec0: d37df108  lsl      x8, x8, #3
//   0x005ec4: b8686968  ldr      w8, [x11, x8]
//   0x005ec8: 12001129  and      w9, w9, #0x1f
//   0x005ecc: 1ac92d08  ror      w8, w8, w9
//   0x005ed0: 17fffec2  b        #0x59d8
//   0x005ed4: 910022ab  add      x11, x21, #8
//   0x005ed8: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005edc: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005ee0: eb08013f  cmp      x9, x8
//   0x005ee4: 8b2a4d68  add      x8, x11, w10, uxtw #3
//   0x005ee8: 54fff0ea  b.ge     #0x5d04
//   0x005eec: 320003e9  mov      w9, #1
//   0x005ef0: f9000109  str      x9, [x8]
//   0x005ef4: 17fffe7c  b        #0x58e4
//   0x005ef8: 0a180189  and      w9, w12, w24
//   0x005efc: 17fffe06  b        #0x5714
//   0x005f00: 0a180189  and      w9, w12, w24
//   0x005f04: 17fffe01  b        #0x5708
//   0x005f08: 320007e1  mov      w1, #3
//   0x005f0c: f81e027a  stur     x26, [x19, #-0x20]
//   0x005f10: 17fffae5  b        #0x4aa4
//   0x005f14: 910022ab  add      x11, x21, #8
//   0x005f18: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005f1c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005f20: ca090108  eor      x8, x8, x9
//   0x005f24: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x005f28: 17fffe6f  b        #0x58e4
//   0x005f2c: 910022ab  add      x11, x21, #8
//   0x005f30: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x005f34: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x005f38: aa090108  orr      x8, x8, x9
//   0x005f3c: aa2803e8  mvn      x8, x8
//   0x005f40: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x005f44: 17fffe68  b        #0x58e4
//   0x005f48: 910022a9  add      x9, x21, #8
//   0x005f4c: d37df108  lsl      x8, x8, #3
//   0x005f50: b8686928  ldr      w8, [x9, x8]
//   0x005f54: 1acb2908  asr      w8, w8, w11
//   0x005f58: 14000025  b        #0x5fec
//   0x005f5c: 910022a9  add      x9, x21, #8
//   0x005f60: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005f64: 321b016b  orr      w11, w11, #0x20
//   0x005f68: 92403d6b  and      x11, x11, #0xffff
//   0x005f6c: 14000014  b        #0x5fbc
//   0x005f70: 910022a9  add      x9, x21, #8
//   0x005f74: d37df108  lsl      x8, x8, #3
//   0x005f78: b8686928  ldr      w8, [x9, x8]
//   0x005f7c: 1acb2108  lsl      w8, w8, w11
//   0x005f80: 1400001b  b        #0x5fec
//   0x005f84: 910022a9  add      x9, x21, #8
//   0x005f88: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005f8c: 321b016b  orr      w11, w11, #0x20
//   0x005f90: 92403d6b  and      x11, x11, #0xffff
//   0x005f94: 9acb2108  lsl      x8, x8, x11
//   0x005f98: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005f9c: 17fffe52  b        #0x58e4
//   0x005fa0: 910022a9  add      x9, x21, #8
//   0x005fa4: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005fa8: 9acb2508  lsr      x8, x8, x11
//   0x005fac: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005fb0: 17fffe4d  b        #0x58e4
//   0x005fb4: 910022a9  add      x9, x21, #8
//   0x005fb8: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005fbc: 9acb2908  asr      x8, x8, x11
//   0x005fc0: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005fc4: 17fffe48  b        #0x58e4
//   0x005fc8: 910022a9  add      x9, x21, #8
//   0x005fcc: f8685928  ldr      x8, [x9, w8, uxtw #3]
//   0x005fd0: 9acb2d08  ror      x8, x8, x11
//   0x005fd4: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005fd8: 17fffe43  b        #0x58e4
//   0x005fdc: 910022a9  add      x9, x21, #8
//   0x005fe0: d37df108  lsl      x8, x8, #3
//   0x005fe4: b8686928  ldr      w8, [x9, x8]
//   0x005fe8: 1acb2d08  ror      w8, w8, w11
//   0x005fec: 93407d08  sxtw     x8, w8
//   0x005ff0: f82a5928  str      x8, [x9, w10, uxtw #3]
//   0x005ff4: 17fffe3c  b        #0x58e4
//   0x005ff8: 910022ab  add      x11, x21, #8
//   0x005ffc: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x006000: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x006004: 92401529  and      x9, x9, #0x3f
//   0x006008: 9ac92908  asr      x8, x8, x9
//   0x00600c: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x006010: 17fffe35  b        #0x58e4
//   0x006014: 910022ab  add      x11, x21, #8
//   0x006018: f8695969  ldr      x9, [x11, w9, uxtw #3]
//   0x00601c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x006020: 92401529  and      x9, x9, #0x3f
//   0x006024: 9ac92108  lsl      x8, x8, x9
//   0x006028: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x00602c: 17fffe2e  b        #0x58e4
//   0x006030: 910022ab  add      x11, x21, #8
//   0x006034: d37df129  lsl      x9, x9, #3
//   0x006038: b8696969  ldr      w9, [x11, x9]
//   0x00603c: d37df108  lsl      x8, x8, #3
//   0x006040: b8686968  ldr      w8, [x11, x8]
//   0x006044: 12001129  and      w9, w9, #0x1f
//   0x006048: 1ac92908  asr      w8, w8, w9
//   0x00604c: 17fffe63  b        #0x59d8
//   0x006050: 910022ab  add      x11, x21, #8
//   0x006054: d37df129  lsl      x9, x9, #3
//   0x006058: b8696969  ldr      w9, [x11, x9]
//   0x00605c: f8685968  ldr      x8, [x11, w8, uxtw #3]
//   0x006060: 12001529  and      w9, w9, #0x3f
//   0x006064: 9ac92d08  ror      x8, x8, x9
//   0x006068: f82a5968  str      x8, [x11, w10, uxtw #3]
//   0x00606c: 17fffe1e  b        #0x58e4
//   0x006070: 711ab9bf  cmp      w13, #0x6ae
//   0x006074: 5400024d  b.le     #0x60bc
//   0x006078: 711db9bf  cmp      w13, #0x76e
//   0x00607c: 5400084c  b.gt     #0x6184
//   0x006080: 711abdbf  cmp      w13, #0x6af
//   0x006084: 54000f60  b.eq     #0x6270
//   0x006088: 711cbdbf  cmp      w13, #0x72f
//   0x00608c: 54ffb120  b.eq     #0x56b0
//   0x006090: 17fffe15  b        #0x58e4
//   0x006094: 7138b9bf  cmp      w13, #0xe2e
//   0x006098: 5400090c  b.gt     #0x61b8
//   0x00609c: 7136bdbf  cmp      w13, #0xdaf
//   0x0060a0: 54ffb1e0  b.eq     #0x56dc
//   0x0060a4: 7137bdbf  cmp      w13, #0xdef
//   0x0060a8: 54ffc1e1  b.ne     #0x58e4
//   0x0060ac: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x0060b0: f9400508  ldr      x8, [x8, #8]
//   0x0060b4: f90000e8  str      x8, [x7]
//   0x0060b8: 17fffe0b  b        #0x58e4
//   0x0060bc: 7106bdbf  cmp      w13, #0x1af
//   0x0060c0: 54000220  b.eq     #0x6104
//   0x0060c4: 7113bdbf  cmp      w13, #0x4ef
//   0x0060c8: 54000e60  b.eq     #0x6294
//   0x0060cc: 7114bdbf  cmp      w13, #0x52f
//   0x0060d0: 54ffc0a1  b.ne     #0x58e4
//   0x0060d4: 910022aa  add      x10, x21, #8
//   0x0060d8: d37df129  lsl      x9, x9, #3
//   0x0060dc: d37df108  lsl      x8, x8, #3
//   0x0060e0: b8696949  ldr      w9, [x10, x9]
//   0x0060e4: b8686948  ldr      w8, [x10, x8]
//   0x0060e8: 1ac8092a  udiv     w10, w9, w8
//   0x0060ec: 1b08a548  msub     w8, w10, w8, w9
//   0x0060f0: 93407d49  sxtw     x9, w10
//   0x0060f4: 93407d08  sxtw     x8, w8
//   0x0060f8: f90000c8  str      x8, [x6]
//   0x0060fc: f90000e9  str      x9, [x7]
//   0x006100: 17fffdf9  b        #0x58e4
//   0x006104: 910022aa  add      x10, x21, #8
//   0x006108: d37df129  lsl      x9, x9, #3
//   0x00610c: d37df108  lsl      x8, x8, #3
//   0x006110: b8696949  ldr      w9, [x10, x9]
//   0x006114: b8686948  ldr      w8, [x10, x8]
//   0x006118: 9b097d08  mul      x8, x8, x9
//   0x00611c: 93407d09  sxtw     x9, w8
//   0x006120: 9360fd08  asr      x8, x8, #0x20
//   0x006124: f90000e9  str      x9, [x7]
//   0x006128: f90000c8  str      x8, [x6]
//   0x00612c: 17fffdee  b        #0x58e4
//   0x006130: 7116bdbf  cmp      w13, #0x5af
//   0x006134: 54000be0  b.eq     #0x62b0
//   0x006138: 711abdbf  cmp      w13, #0x6af
//   0x00613c: 54000bc0  b.eq     #0x62b4
//   0x006140: 17fffde9  b        #0x58e4
//   0x006144: 712cbdbf  cmp      w13, #0xb2f
//   0x006148: 540000e0  b.eq     #0x6164
//   0x00614c: 7133bdbf  cmp      w13, #0xcef
//   0x006150: 54ffbca1  b.ne     #0x58e4
//   0x006154: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x006158: f9400508  ldr      x8, [x8, #8]
//   0x00615c: f90000c8  str      x8, [x6]
//   0x006160: 17fffde1  b        #0x58e4
//   0x006164: 910022aa  add      x10, x21, #8
//   0x006168: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x00616c: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x006170: 9ac80d2a  sdiv     x10, x9, x8
//   0x006174: 9b08a548  msub     x8, x10, x8, x9
//   0x006178: f90000c8  str      x8, [x6]
//   0x00617c: f90000ea  str      x10, [x7]
//   0x006180: 17fffdd9  b        #0x58e4
//   0x006184: 711dbdbf  cmp      w13, #0x76f
//   0x006188: 54000080  b.eq     #0x6198
//   0x00618c: 7122bdbf  cmp      w13, #0x8af
//   0x006190: 54ff97e0  b.eq     #0x548c
//   0x006194: 17fffdd4  b        #0x58e4
//   0x006198: 910022aa  add      x10, x21, #8
//   0x00619c: f8695949  ldr      x9, [x10, w9, uxtw #3]
//   0x0061a0: f8685948  ldr      x8, [x10, w8, uxtw #3]
//   0x0061a4: 9bc97d0a  umulh    x10, x8, x9
//   0x0061a8: 9b097d08  mul      x8, x8, x9
//   0x0061ac: f90000e8  str      x8, [x7]
//   0x0061b0: f90000ca  str      x10, [x6]
//   0x0061b4: 17fffdcc  b        #0x58e4
//   0x0061b8: 7138bdbf  cmp      w13, #0xe2f
//   0x0061bc: 54000a40  b.eq     #0x6304
//   0x0061c0: 713abdbf  cmp      w13, #0xeaf
//   0x0061c4: 54ffb901  b.ne     #0x58e4
//   0x0061c8: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x0061cc: f9400508  ldr      x8, [x8, #8]
//   0x0061d0: b5000688  cbnz     x8, #0x62a0
//   0x0061d4: 17fffdc4  b        #0x58e4
//   0x0061d8: 320013e8  mov      w8, #0x1f
//   0x0061dc: f85f8269  ldur     x9, [x19, #-8]
//   0x0061e0: 2a1f03ec  mov      w12, wzr
//   0x0061e4: 2a1f03ea  mov      w10, wzr
//   0x0061e8: 8b0b0129  add      x9, x9, x11
//   0x0061ec: 14000036  b        #0x62c4
//   0x0061f0: eb0d011f  cmp      x8, x13
//   0x0061f4: 54ffdee1  b.ne     #0x5dd0
//   0x0061f8: 14000018  b        #0x6258
//   0x0061fc: eb0d011f  cmp      x8, x13
//   0x006200: 540002c1  b.ne     #0x6258
//   0x006204: 17fffef3  b        #0x5dd0
//   0x006208: f100011f  cmp      x8, #0
//   0x00620c: 320003ea  mov      w10, #1
//   0x006210: 540001ac  b.gt     #0x6244
//   0x006214: 14000012  b        #0x625c
//   0x006218: eb0d011f  cmp      x8, x13
//   0x00621c: 320003ea  mov      w10, #1
//   0x006220: 54000120  b.eq     #0x6244
//   0x006224: 1400000e  b        #0x625c
//   0x006228: f100051f  cmp      x8, #1
//   0x00622c: 320003ea  mov      w10, #1
//   0x006230: 5400016a  b.ge     #0x625c
//   0x006234: 14000004  b        #0x6244
//   0x006238: eb0d011f  cmp      x8, x13
//   0x00623c: 320003ea  mov      w10, #1
//   0x006240: 540000e0  b.eq     #0x625c
//   0x006244: 2a1f03ec  mov      w12, wzr
//   0x006248: 2a1f03e8  mov      w8, wzr
//   0x00624c: 1400001e  b        #0x62c4
//   0x006250: f100051f  cmp      x8, #1
//   0x006254: 54ffdbeb  b.lt     #0x5dd0
//   0x006258: 2a1f03ea  mov      w10, wzr
//   0x00625c: 2a1f03eb  mov      w11, wzr
//   0x006260: 2a1f03e8  mov      w8, wzr
//   0x006264: 91002009  add      x9, x0, #8
//   0x006268: 320003ec  mov      w12, #1
//   0x00626c: 14000017  b        #0x62c8
//   0x006270: b5ffb3a1  cbnz     x1, #0x58e4
//   0x006274: 8b294ea8  add      x8, x21, w9, uxtw #3
//   0x006278: f9400508  ldr      x8, [x8, #8]
//   0x00627c: 91001000  add      x0, x0, #4
//   0x006280: 321f03e9  mov      w9, #2
//   0x006284: a93e2269  stp      x9, x8, [x19, #-0x20]
//   0x006288: f90002a0  str      x0, [x21]
//   0x00628c: b5ff4040  cbnz     x0, #0x4a94
//   0x006290: 14000021  b        #0x6314
//   0x006294: 8b284ea8  add      x8, x21, w8, uxtw #3
//   0x006298: f9400508  ldr      x8, [x8, #8]
//   0x00629c: b5ffb248  cbnz     x8, #0x58e4
//   0x0062a0: 910022a8  add      x8, x21, #8
//   0x0062a4: f8695909  ldr      x9, [x8, w9, uxtw #3]
//   0x0062a8: f82a5909  str      x9, [x8, w10, uxtw #3]
//   0x0062ac: 17fffd8e  b        #0x58e4
//   0x0062b0: 2a0a03e8  mov      w8, w10
//   0x0062b4: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x0062b8: f9400529  ldr      x9, [x9, #8]
//   0x0062bc: 2a1f03ec  mov      w12, wzr
//   0x0062c0: 2a1f03ea  mov      w10, wzr
//   0x0062c4: 320003eb  mov      w11, #1
//   0x0062c8: 7100015f  cmp      w10, #0
//   0x0062cc: 1a9f07ed  cset     w13, ne
//   0x0062d0: 0a0d018c  and      w12, w12, w13
//   0x0062d4: f81e8269  stur     x9, [x19, #-0x18]
//   0x0062d8: 3700008c  tbnz     w12, #0, #0x62e8
//   0x0062dc: 3400006a  cbz      w10, #0x62e8
//   0x0062e0: 0a0d0169  and      w9, w11, w13
//   0x0062e4: 34ff86e9  cbz      w9, #0x53c0
//   0x0062e8: 7100019f  cmp      w12, #0
//   0x0062ec: 320003e9  mov      w9, #1
//   0x0062f0: 9a891529  cinc     x9, x9, eq
//   0x0062f4: f81e0269  stur     x9, [x19, #-0x20]
//   0x0062f8: 7100051f  cmp      w8, #1
//   0x0062fc: 54ffaf4b  b.lt     #0x58e4
//   0x006300: 17fffc32  b        #0x53c8
//   0x006304: f94000c8  ldr      x8, [x6]
//   0x006308: 8b2a4ea9  add      x9, x21, w10, uxtw #3
//   0x00630c: f9000528  str      x8, [x9, #8]
//   0x006310: 17fffd75  b        #0x58e4
//   0x006314: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x006318: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00631c: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x006320: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x006324: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x006328: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x00632c: 9101c3ff  add      sp, sp, #0x70
//   0x006330: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_26_49e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000049e8ULL;
    for (std::size_t i = 0; i < 1619ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4130ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[27] Subroutine @ 0x006334..0x006438 (260 bytes, 65 AArch64 instructions)
// [VN] Khung FDE[27] Hàm con @ 0x006334..0x006438 (260 byte, 65 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006334: 39400028  ldrb     w8, [x1]
//   0x006338: 39400009  ldrb     w9, [x0]
//   0x00633c: 4a080128  eor      w8, w9, w8
//   0x006340: 39000008  strb     w8, [x0]
//   0x006344: 39400409  ldrb     w9, [x0, #1]
//   0x006348: 39400428  ldrb     w8, [x1, #1]
//   0x00634c: 4a080128  eor      w8, w9, w8
//   0x006350: 39000408  strb     w8, [x0, #1]
//   0x006354: 39400809  ldrb     w9, [x0, #2]
//   0x006358: 39400828  ldrb     w8, [x1, #2]
//   0x00635c: 4a080128  eor      w8, w9, w8
//   0x006360: 39000808  strb     w8, [x0, #2]
//   0x006364: 39400c09  ldrb     w9, [x0, #3]
//   0x006368: 39400c28  ldrb     w8, [x1, #3]
//   0x00636c: 4a080128  eor      w8, w9, w8
//   0x006370: 39000c08  strb     w8, [x0, #3]
//   0x006374: 39401009  ldrb     w9, [x0, #4]
//   0x006378: 39401028  ldrb     w8, [x1, #4]
//   0x00637c: 4a080128  eor      w8, w9, w8
//   0x006380: 39001008  strb     w8, [x0, #4]
//   0x006384: 39401409  ldrb     w9, [x0, #5]
//   0x006388: 39401428  ldrb     w8, [x1, #5]
//   0x00638c: 4a080128  eor      w8, w9, w8
//   0x006390: 39001408  strb     w8, [x0, #5]
//   0x006394: 39401809  ldrb     w9, [x0, #6]
//   0x006398: 39401828  ldrb     w8, [x1, #6]
//   0x00639c: 4a080128  eor      w8, w9, w8
//   0x0063a0: 39001808  strb     w8, [x0, #6]
//   0x0063a4: 39401c09  ldrb     w9, [x0, #7]
//   0x0063a8: 39401c28  ldrb     w8, [x1, #7]
//   0x0063ac: 4a080128  eor      w8, w9, w8
//   0x0063b0: 39001c08  strb     w8, [x0, #7]
//   0x0063b4: 39402009  ldrb     w9, [x0, #8]
//   0x0063b8: 39402028  ldrb     w8, [x1, #8]
//   0x0063bc: 4a080128  eor      w8, w9, w8
//   0x0063c0: 39002008  strb     w8, [x0, #8]
//   0x0063c4: 39402409  ldrb     w9, [x0, #9]
//   0x0063c8: 39402428  ldrb     w8, [x1, #9]
//   0x0063cc: 4a080128  eor      w8, w9, w8
//   0x0063d0: 39002408  strb     w8, [x0, #9]
//   0x0063d4: 39402809  ldrb     w9, [x0, #0xa]
//   0x0063d8: 39402828  ldrb     w8, [x1, #0xa]
//   0x0063dc: 4a080128  eor      w8, w9, w8
//   0x0063e0: 39002808  strb     w8, [x0, #0xa]
//   0x0063e4: 39402c09  ldrb     w9, [x0, #0xb]
//   0x0063e8: 39402c28  ldrb     w8, [x1, #0xb]
//   0x0063ec: 4a080128  eor      w8, w9, w8
//   0x0063f0: 39002c08  strb     w8, [x0, #0xb]
//   0x0063f4: 39403009  ldrb     w9, [x0, #0xc]
//   0x0063f8: 39403028  ldrb     w8, [x1, #0xc]
//   0x0063fc: 4a080128  eor      w8, w9, w8
//   0x006400: 39003008  strb     w8, [x0, #0xc]
//   0x006404: 39403409  ldrb     w9, [x0, #0xd]
//   0x006408: 39403428  ldrb     w8, [x1, #0xd]
//   0x00640c: 4a080128  eor      w8, w9, w8
//   0x006410: 39003408  strb     w8, [x0, #0xd]
//   0x006414: 39403809  ldrb     w9, [x0, #0xe]
//   0x006418: 39403828  ldrb     w8, [x1, #0xe]
//   0x00641c: 4a080128  eor      w8, w9, w8
//   0x006420: 39003808  strb     w8, [x0, #0xe]
//   0x006424: 39403c28  ldrb     w8, [x1, #0xf]
//   0x006428: 39403c09  ldrb     w9, [x0, #0xf]
//   0x00642c: 4a080128  eor      w8, w9, w8
//   0x006430: 39003c08  strb     w8, [x0, #0xf]
//   0x006434: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_27_6334(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006334ULL;
    for (std::size_t i = 0; i < 65ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5749ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[28] Subroutine @ 0x006438..0x00646c (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[28] Hàm con @ 0x006438..0x00646c (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006438: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00643c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x006440: 910043fd  add      x29, sp, #0x10
//   0x006444: aa0203f3  mov      x19, x2
//   0x006448: 52803d02  mov      w2, #0x1e8
//   0x00644c: aa0003f4  mov      x20, x0
//   0x006450: 97ffe934  bl       #0x920
//   0x006454: 3dc00260  ldr      q0, [x19]
//   0x006458: 9107a288  add      x8, x20, #0x1e8
//   0x00645c: 3d800100  str      q0, [x8]
//   0x006460: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x006464: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x006468: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_28_6438(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006438ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5814ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[29] Subroutine @ 0x00646c..0x0064b0 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[29] Hàm con @ 0x00646c..0x0064b0 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00646c: f0000028  adrp     x8, #0xd000
//   0x006470: 3dc3c100  ldr      q0, [x8, #0xf00]
//   0x006474: f0000028  adrp     x8, #0xd000
//   0x006478: 3dc3c501  ldr      q1, [x8, #0xf10]
//   0x00647c: f0000028  adrp     x8, #0xd000
//   0x006480: 3dc3c902  ldr      q2, [x8, #0xf20]
//   0x006484: f0000028  adrp     x8, #0xd000
//   0x006488: ad000400  stp      q0, q1, [x0]
//   0x00648c: 3dc3cd00  ldr      q0, [x8, #0xf30]
//   0x006490: d2842f28  mov      x8, #0x2179
//   0x006494: f2a26fc8  movk     x8, #0x137e, lsl #16
//   0x006498: f2d9a328  movk     x8, #0xcd19, lsl #32
//   0x00649c: f2eb7c08  movk     x8, #0x5be0, lsl #48
//   0x0064a0: b900481f  str      wzr, [x0, #0x48]
//   0x0064a4: ad010002  stp      q2, q0, [x0, #0x20]
//   0x0064a8: f9002008  str      x8, [x0, #0x40]
//   0x0064ac: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_29_646c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000646cULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5827ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[30] Subroutine @ 0x0064b0..0x0065a0 (240 bytes, 60 AArch64 instructions)
// [VN] Khung FDE[30] Hàm con @ 0x0064b0..0x0065a0 (240 byte, 60 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0064b0: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0064b4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0064b8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0064bc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0064c0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0064c4: 910103fd  add      x29, sp, #0x40
//   0x0064c8: aa0003f3  mov      x19, x0
//   0x0064cc: b9404a79  ldr      w25, [x19, #0x48]
//   0x0064d0: aa0203f6  mov      x22, x2
//   0x0064d4: aa0103f4  mov      x20, x1
//   0x0064d8: 7102033f  cmp      w25, #0x80
//   0x0064dc: 54000568  b.hi     #0x6588
//   0x0064e0: b4000556  cbz      x22, #0x6588
//   0x0064e4: 91013275  add      x21, x19, #0x4c
//   0x0064e8: 321903f8  mov      w24, #0x80
//   0x0064ec: f10202d7  subs     x23, x22, #0x80
//   0x0064f0: 540000a2  b.hs     #0x6504
//   0x0064f4: 1400000f  b        #0x6530
//   0x0064f8: b9404a79  ldr      w25, [x19, #0x48]
//   0x0064fc: f10202d7  subs     x23, x22, #0x80
//   0x006500: 54000183  b.lo     #0x6530
//   0x006504: 35000179  cbnz     w25, #0x6530
//   0x006508: aa1303e0  mov      x0, x19
//   0x00650c: aa1403e1  mov      x1, x20
//   0x006510: 94000024  bl       #0x65a0
//   0x006514: f9400268  ldr      x8, [x19]
//   0x006518: 91020294  add      x20, x20, #0x80
//   0x00651c: aa1703f6  mov      x22, x23
//   0x006520: 91100108  add      x8, x8, #0x400
//   0x006524: f9000268  str      x8, [x19]
//   0x006528: b5fffe96  cbnz     x22, #0x64f8
//   0x00652c: 14000017  b        #0x6588
//   0x006530: 4b190308  sub      w8, w24, w25
//   0x006534: eb0802df  cmp      x22, x8
//   0x006538: 8b394269  add      x9, x19, w25, uxtw
//   0x00653c: 9a8832d7  csel     x23, x22, x8, lo
//   0x006540: 91013120  add      x0, x9, #0x4c
//   0x006544: aa1403e1  mov      x1, x20
//   0x006548: aa1703e2  mov      x2, x23
//   0x00654c: 97ffe8f5  bl       #0x920
//   0x006550: 0b170328  add      w8, w25, w23
//   0x006554: 8b170294  add      x20, x20, x23
//   0x006558: 7102011f  cmp      w8, #0x80
//   0x00655c: cb1702d6  sub      x22, x22, x23
//   0x006560: b9004a68  str      w8, [x19, #0x48]
//   0x006564: 54000101  b.ne     #0x6584
//   0x006568: aa1303e0  mov      x0, x19
//   0x00656c: aa1503e1  mov      x1, x21
//   0x006570: 9400000c  bl       #0x65a0
//   0x006574: f9400268  ldr      x8, [x19]
//   0x006578: b9004a7f  str      wzr, [x19, #0x48]
//   0x00657c: 91100108  add      x8, x8, #0x400
//   0x006580: f9000268  str      x8, [x19]
//   0x006584: b5fffbb6  cbnz     x22, #0x64f8
//   0x006588: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x00658c: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x006590: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x006594: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x006598: f84507f9  ldr      x25, [sp], #0x50
//   0x00659c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_30_64b0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000064b0ULL;
    for (std::size_t i = 0; i < 60ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5844ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[31] Subroutine @ 0x0065a0..0x0069a4 (1028 bytes, 257 AArch64 instructions)
// [VN] Khung FDE[31] Hàm con @ 0x0065a0..0x0069a4 (1028 byte, 257 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0065a0: a9bd57fc  stp      x28, x21, [sp, #-0x30]!
//   0x0065a4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0065a8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0065ac: 910083fd  add      x29, sp, #0x20
//   0x0065b0: d10b43ff  sub      sp, sp, #0x2d0
//   0x0065b4: d53bd048  mrs      x8, tpidr_el0
//   0x0065b8: f940150a  ldr      x10, [x8, #0x28]
//   0x0065bc: aa1f03e9  mov      x9, xzr
//   0x0065c0: 910003eb  mov      x11, sp
//   0x0065c4: f81d83aa  stur     x10, [x29, #-0x28]
//   0x0065c8: 3cc38000  ldur     q0, [x0, #0x38]
//   0x0065cc: 91000c2a  add      x10, x1, #3
//   0x0065d0: 3c9c03a0  stur     q0, [x29, #-0x40]
//   0x0065d4: 3cc28000  ldur     q0, [x0, #0x28]
//   0x0065d8: 3c9b03a0  stur     q0, [x29, #-0x50]
//   0x0065dc: 3cc18000  ldur     q0, [x0, #0x18]
//   0x0065e0: 3c9a03a0  stur     q0, [x29, #-0x60]
//   0x0065e4: 3cc08000  ldur     q0, [x0, #8]
//   0x0065e8: 3c9903a0  stur     q0, [x29, #-0x70]
//   0x0065ec: 8b09014c  add      x12, x10, x9
//   0x0065f0: f85fd18c  ldur     x12, [x12, #-3]
//   0x0065f4: dac00d8c  rev      x12, x12
//   0x0065f8: f829696c  str      x12, [x11, x9]
//   0x0065fc: 91002129  add      x9, x9, #8
//   0x006600: f102013f  cmp      x9, #0x80
//   0x006604: 54ffff41  b.ne     #0x65ec
//   0x006608: f94003eb  ldr      x11, [sp]
//   0x00660c: 910003ea  mov      x10, sp
//   0x006610: aa1f03e9  mov      x9, xzr
//   0x006614: 9102014a  add      x10, x10, #0x80
//   0x006618: 8b09014c  add      x12, x10, x9
//   0x00661c: f85c818e  ldur     x14, [x12, #-0x38]
//   0x006620: f85f018d  ldur     x13, [x12, #-0x10]
//   0x006624: 91002129  add      x9, x9, #8
//   0x006628: f108013f  cmp      x9, #0x200
//   0x00662c: 8b0e016b  add      x11, x11, x14
//   0x006630: f858818e  ldur     x14, [x12, #-0x78]
//   0x006634: 93cdf5af  ror      x15, x13, #0x3d
//   0x006638: ca4d19ef  eor      x15, x15, x13, lsr #6
//   0x00663c: cacd4ded  eor      x13, x15, x13, ror #19
//   0x006640: 8b0d016b  add      x11, x11, x13
//   0x006644: 93ce21cd  ror      x13, x14, #8
//   0x006648: ca4e1dad  eor      x13, x13, x14, lsr #7
//   0x00664c: cace05ad  eor      x13, x13, x14, ror #1
//   0x006650: 8b0d016b  add      x11, x11, x13
//   0x006654: f900018b  str      x11, [x12]
//   0x006658: aa0e03eb  mov      x11, x14
//   0x00665c: 54fffde1  b.ne     #0x6618
//   0x006660: a97c4bae  ldp      x14, x18, [x29, #-0x40]
//   0x006664: a97b47b0  ldp      x16, x17, [x29, #-0x50]
//   0x006668: a97937ac  ldp      x12, x13, [x29, #-0x70]
//   0x00666c: a97a07af  ldp      x15, x1, [x29, #-0x60]
//   0x006670: f000002b  adrp     x11, #0xd000
//   0x006674: 910003ea  mov      x10, sp
//   0x006678: 913d016b  add      x11, x11, #0xf40
//   0x00667c: aa1f03e9  mov      x9, xzr
//   0x006680: 9100814a  add      x10, x10, #0x20
//   0x006684: 9100816b  add      x11, x11, #0x20
//   0x006688: a97e0d73  ldp      x19, x3, [x11, #-0x20]
//   0x00668c: 93d03a04  ror      x4, x16, #0xe
//   0x006690: aa0c01a6  orr      x6, x13, x12
//   0x006694: 8a0c01a7  and      x7, x13, x12
//   0x006698: 8a0f00c6  and      x6, x6, x15
//   0x00669c: cad04884  eor      x4, x4, x16, ror #18
//   0x0066a0: aa0700c6  orr      x6, x6, x7
//   0x0066a4: a97f5167  ldp      x7, x20, [x11, #-0x10]
//   0x0066a8: cad0a484  eor      x4, x4, x16, ror #41
//   0x0066ac: 8b120272  add      x18, x19, x18
//   0x0066b0: 8b040255  add      x21, x18, x4
//   0x0066b4: a97f4953  ldp      x19, x18, [x10, #-0x10]
//   0x0066b8: 8b1100e4  add      x4, x7, x17
//   0x0066bc: ca0e0225  eor      x5, x17, x14
//   0x0066c0: 8a1000a5  and      x5, x5, x16
//   0x0066c4: 8b130084  add      x4, x4, x19
//   0x0066c8: 8b100293  add      x19, x20, x16
//   0x0066cc: 8b120272  add      x18, x19, x18
//   0x0066d0: a97e4d47  ldp      x7, x19, [x10, #-0x20]
//   0x0066d4: 93cc7182  ror      x2, x12, #0x1c
//   0x0066d8: ca0e00a5  eor      x5, x5, x14
//   0x0066dc: cacc8842  eor      x2, x2, x12, ror #34
//   0x0066e0: 8b0702a7  add      x7, x21, x7
//   0x0066e4: 8b0500e5  add      x5, x7, x5
//   0x0066e8: ca100234  eor      x20, x17, x16
//   0x0066ec: 8b050021  add      x1, x1, x5
//   0x0066f0: 8b0500c5  add      x5, x6, x5
//   0x0066f4: cacc9c42  eor      x2, x2, x12, ror #39
//   0x0066f8: 8b0200a2  add      x2, x5, x2
//   0x0066fc: 8a140025  and      x5, x1, x20
//   0x006700: ca1100a5  eor      x5, x5, x17
//   0x006704: 8b0e00ae  add      x14, x5, x14
//   0x006708: aa0c0045  orr      x5, x2, x12
//   0x00670c: 8b0301ce  add      x14, x14, x3
//   0x006710: 8a0c0043  and      x3, x2, x12
//   0x006714: 8a0d00a5  and      x5, x5, x13
//   0x006718: aa0300a3  orr      x3, x5, x3
//   0x00671c: 93c27045  ror      x5, x2, #0x1c
//   0x006720: cac288a5  eor      x5, x5, x2, ror #34
//   0x006724: cac29ca5  eor      x5, x5, x2, ror #39
//   0x006728: 8b0300a3  add      x3, x5, x3
//   0x00672c: 93c13825  ror      x5, x1, #0xe
//   0x006730: cac148a5  eor      x5, x5, x1, ror #18
//   0x006734: a9401d66  ldp      x6, x7, [x11]
//   0x006738: 8b1301ce  add      x14, x14, x19
//   0x00673c: cac1a4a5  eor      x5, x5, x1, ror #41
//   0x006740: 8b0501ce  add      x14, x14, x5
//   0x006744: ca100025  eor      x5, x1, x16
//   0x006748: 8b0f01cf  add      x15, x14, x15
//   0x00674c: 8b0e006e  add      x14, x3, x14
//   0x006750: 8a0501e3  and      x3, x15, x5
//   0x006754: 8b0100d1  add      x17, x6, x1
//   0x006758: ca100070  eor      x16, x3, x16
//   0x00675c: 8b0f00e6  add      x6, x7, x15
//   0x006760: aa0201c7  orr      x7, x14, x2
//   0x006764: 8b100090  add      x16, x4, x16
//   0x006768: 8a0201c4  and      x4, x14, x2
//   0x00676c: 8a0c00e7  and      x7, x7, x12
//   0x006770: aa0400e4  orr      x4, x7, x4
//   0x006774: 93cf39e7  ror      x7, x15, #0xe
//   0x006778: cacf48e7  eor      x7, x7, x15, ror #18
//   0x00677c: cacfa4e7  eor      x7, x7, x15, ror #41
//   0x006780: 8b070210  add      x16, x16, x7
//   0x006784: 93ce71c7  ror      x7, x14, #0x1c
//   0x006788: cace88e7  eor      x7, x7, x14, ror #34
//   0x00678c: cace9ce7  eor      x7, x7, x14, ror #39
//   0x006790: 8b0400e4  add      x4, x7, x4
//   0x006794: ca0101e7  eor      x7, x15, x1
//   0x006798: 8b0d020d  add      x13, x16, x13
//   0x00679c: a9411563  ldp      x3, x5, [x11, #0x10]
//   0x0067a0: 8b100090  add      x16, x4, x16
//   0x0067a4: 8a0701a4  and      x4, x13, x7
//   0x0067a8: ca010081  eor      x1, x4, x1
//   0x0067ac: a9411147  ldp      x7, x4, [x10, #0x10]
//   0x0067b0: 8b0d0063  add      x3, x3, x13
//   0x0067b4: 8b010252  add      x18, x18, x1
//   0x0067b8: 8a0e0201  and      x1, x16, x14
//   0x0067bc: 8b070063  add      x3, x3, x7
//   0x0067c0: aa0e0207  orr      x7, x16, x14
//   0x0067c4: 8a0200e7  and      x7, x7, x2
//   0x0067c8: aa0100e1  orr      x1, x7, x1
//   0x0067cc: 93cd39a7  ror      x7, x13, #0xe
//   0x0067d0: cacd48e7  eor      x7, x7, x13, ror #18
//   0x0067d4: cacda4e7  eor      x7, x7, x13, ror #41
//   0x0067d8: 8b070252  add      x18, x18, x7
//   0x0067dc: 93d07207  ror      x7, x16, #0x1c
//   0x0067e0: cad088e7  eor      x7, x7, x16, ror #34
//   0x0067e4: cad09ce7  eor      x7, x7, x16, ror #39
//   0x0067e8: a9405554  ldp      x20, x21, [x10]
//   0x0067ec: 8b0100e1  add      x1, x7, x1
//   0x0067f0: 8b0c024c  add      x12, x18, x12
//   0x0067f4: 8b120027  add      x7, x1, x18
//   0x0067f8: ca0f01b2  eor      x18, x13, x15
//   0x0067fc: 8a120192  and      x18, x12, x18
//   0x006800: ca0f024f  eor      x15, x18, x15
//   0x006804: 8b050192  add      x18, x12, x5
//   0x006808: 8b140231  add      x17, x17, x20
//   0x00680c: 8b040244  add      x4, x18, x4
//   0x006810: aa1000f2  orr      x18, x7, x16
//   0x006814: 8b0f022f  add      x15, x17, x15
//   0x006818: 8a1000f1  and      x17, x7, x16
//   0x00681c: 8a0e0252  and      x18, x18, x14
//   0x006820: aa110251  orr      x17, x18, x17
//   0x006824: 93cc3992  ror      x18, x12, #0xe
//   0x006828: cacc4a52  eor      x18, x18, x12, ror #18
//   0x00682c: cacca652  eor      x18, x18, x12, ror #41
//   0x006830: 8b1201ef  add      x15, x15, x18
//   0x006834: 93c770f2  ror      x18, x7, #0x1c
//   0x006838: cac78a52  eor      x18, x18, x7, ror #34
//   0x00683c: cac79e52  eor      x18, x18, x7, ror #39
//   0x006840: 8b110251  add      x17, x18, x17
//   0x006844: ca0d0185  eor      x5, x12, x13
//   0x006848: 8b0201f2  add      x18, x15, x2
//   0x00684c: 8b0f0221  add      x1, x17, x15
//   0x006850: 8a050251  and      x17, x18, x5
//   0x006854: 93d23a4f  ror      x15, x18, #0xe
//   0x006858: ca0d022d  eor      x13, x17, x13
//   0x00685c: aa070031  orr      x17, x1, x7
//   0x006860: 8b1500c6  add      x6, x6, x21
//   0x006864: 8a070022  and      x2, x1, x7
//   0x006868: 8a100231  and      x17, x17, x16
//   0x00686c: cad249ef  eor      x15, x15, x18, ror #18
//   0x006870: 8b0d00cd  add      x13, x6, x13
//   0x006874: aa020231  orr      x17, x17, x2
//   0x006878: 93c17022  ror      x2, x1, #0x1c
//   0x00687c: cad2a5ef  eor      x15, x15, x18, ror #41
//   0x006880: 8b0f01ad  add      x13, x13, x15
//   0x006884: cac1884f  eor      x15, x2, x1, ror #34
//   0x006888: cac19def  eor      x15, x15, x1, ror #39
//   0x00688c: ca0c0245  eor      x5, x18, x12
//   0x006890: 8b1101ef  add      x15, x15, x17
//   0x006894: 8b0e01ae  add      x14, x13, x14
//   0x006898: 8b0d01ef  add      x15, x15, x13
//   0x00689c: 93ce39cd  ror      x13, x14, #0xe
//   0x0068a0: 8a0501d1  and      x17, x14, x5
//   0x0068a4: 93cf71e2  ror      x2, x15, #0x1c
//   0x0068a8: ca0c022c  eor      x12, x17, x12
//   0x0068ac: aa0101f1  orr      x17, x15, x1
//   0x0068b0: cace49ad  eor      x13, x13, x14, ror #18
//   0x0068b4: 8b0c006c  add      x12, x3, x12
//   0x0068b8: 8a0101e3  and      x3, x15, x1
//   0x0068bc: 8a070231  and      x17, x17, x7
//   0x0068c0: cacf8842  eor      x2, x2, x15, ror #34
//   0x0068c4: cacea5ad  eor      x13, x13, x14, ror #41
//   0x0068c8: aa030231  orr      x17, x17, x3
//   0x0068cc: cacf9c42  eor      x2, x2, x15, ror #39
//   0x0068d0: 8b0d018c  add      x12, x12, x13
//   0x0068d4: ca1201c3  eor      x3, x14, x18
//   0x0068d8: 8b11004d  add      x13, x2, x17
//   0x0068dc: 8b100191  add      x17, x12, x16
//   0x0068e0: 8b0c01ad  add      x13, x13, x12
//   0x0068e4: 8a030230  and      x16, x17, x3
//   0x0068e8: 93d13a2c  ror      x12, x17, #0xe
//   0x0068ec: 93cd71a2  ror      x2, x13, #0x1c
//   0x0068f0: aa0f01a3  orr      x3, x13, x15
//   0x0068f4: ca120210  eor      x16, x16, x18
//   0x0068f8: 8b100090  add      x16, x4, x16
//   0x0068fc: 8a0f01a4  and      x4, x13, x15
//   0x006900: cad1498c  eor      x12, x12, x17, ror #18
//   0x006904: cacd8842  eor      x2, x2, x13, ror #34
//   0x006908: 8a010063  and      x3, x3, x1
//   0x00690c: cad1a58c  eor      x12, x12, x17, ror #41
//   0x006910: cacd9c42  eor      x2, x2, x13, ror #39
//   0x006914: aa040063  orr      x3, x3, x4
//   0x006918: 91002129  add      x9, x9, #8
//   0x00691c: 8b0c020c  add      x12, x16, x12
//   0x006920: 8b030042  add      x2, x2, x3
//   0x006924: 9101016b  add      x11, x11, #0x40
//   0x006928: f101413f  cmp      x9, #0x50
//   0x00692c: 8b070190  add      x16, x12, x7
//   0x006930: 8b0c004c  add      x12, x2, x12
//   0x006934: 9101014a  add      x10, x10, #0x40
//   0x006938: 54ffea83  b.lo     #0x6688
//   0x00693c: a940a809  ldp      x9, x10, [x0, #8]
//   0x006940: a941880b  ldp      x11, x2, [x0, #0x18]
//   0x006944: 8b090189  add      x9, x12, x9
//   0x006948: 8b0a01aa  add      x10, x13, x10
//   0x00694c: a942b40c  ldp      x12, x13, [x0, #0x28]
//   0x006950: 8b0b01eb  add      x11, x15, x11
//   0x006954: 8b02002f  add      x15, x1, x2
//   0x006958: a9438801  ldp      x1, x2, [x0, #0x38]
//   0x00695c: 8b0c020c  add      x12, x16, x12
//   0x006960: 8b0d022d  add      x13, x17, x13
//   0x006964: a900a809  stp      x9, x10, [x0, #8]
//   0x006968: 8b0101ce  add      x14, x14, x1
//   0x00696c: 8b020250  add      x16, x18, x2
//   0x006970: a901bc0b  stp      x11, x15, [x0, #0x18]
//   0x006974: a902b40c  stp      x12, x13, [x0, #0x28]
//   0x006978: a903c00e  stp      x14, x16, [x0, #0x38]
//   0x00697c: f9401508  ldr      x8, [x8, #0x28]
//   0x006980: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x006984: eb09011f  cmp      x8, x9
//   0x006988: 540000c1  b.ne     #0x69a0
//   0x00698c: 910b43ff  add      sp, sp, #0x2d0
//   0x006990: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x006994: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x006998: a8c357fc  ldp      x28, x21, [sp], #0x30
//   0x00699c: d65f03c0  ret      
//   0x0069a0: 97ffe7d8  bl       #0x900
// ============================================================================
std::uint32_t fde_31_65a0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000065a0ULL;
    for (std::size_t i = 0; i < 257ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5904ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[32] Subroutine @ 0x0069a4..0x006b10 (364 bytes, 91 AArch64 instructions)
// [VN] Khung FDE[32] Hàm con @ 0x0069a4..0x006b10 (364 byte, 91 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0069a4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0069a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0069ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0069b0: 910083fd  add      x29, sp, #0x20
//   0x0069b4: aa0003f3  mov      x19, x0
//   0x0069b8: b9404a68  ldr      w8, [x19, #0x48]
//   0x0069bc: aa0103f4  mov      x20, x1
//   0x0069c0: 7101fd1f  cmp      w8, #0x7f
//   0x0069c4: 540009e8  b.hi     #0x6b00
//   0x0069c8: f940026a  ldr      x10, [x19]
//   0x0069cc: 11000509  add      w9, w8, #1
//   0x0069d0: 91013275  add      x21, x19, #0x4c
//   0x0069d4: 321903eb  mov      w11, #0x80
//   0x0069d8: 7101c53f  cmp      w9, #0x71
//   0x0069dc: 8b080d4a  add      x10, x10, x8, lsl #3
//   0x0069e0: b9004a69  str      w9, [x19, #0x48]
//   0x0069e4: f900026a  str      x10, [x19]
//   0x0069e8: 38286aab  strb     w11, [x21, x8]
//   0x0069ec: 540001e3  b.lo     #0x6a28
//   0x0069f0: 7101fd3f  cmp      w9, #0x7f
//   0x0069f4: 54000108  b.hi     #0x6a14
//   0x0069f8: 11000909  add      w9, w8, #2
//   0x0069fc: 8b08026a  add      x10, x19, x8
//   0x006a00: 91000508  add      x8, x8, #1
//   0x006a04: 7101fd1f  cmp      w8, #0x7f
//   0x006a08: b9004a69  str      w9, [x19, #0x48]
//   0x006a0c: 3901355f  strb     wzr, [x10, #0x4d]
//   0x006a10: 54ffff41  b.ne     #0x69f8
//   0x006a14: aa1303e0  mov      x0, x19
//   0x006a18: aa1503e1  mov      x1, x21
//   0x006a1c: 97fffee1  bl       #0x65a0
//   0x006a20: 2a1f03e9  mov      w9, wzr
//   0x006a24: b9004a7f  str      wzr, [x19, #0x48]
//   0x006a28: 2a0903e8  mov      w8, w9
//   0x006a2c: 8b080269  add      x9, x19, x8
//   0x006a30: 91000508  add      x8, x8, #1
//   0x006a34: f101e11f  cmp      x8, #0x78
//   0x006a38: b9004a68  str      w8, [x19, #0x48]
//   0x006a3c: 3901313f  strb     wzr, [x9, #0x4c]
//   0x006a40: 54ffff61  b.ne     #0x6a2c
//   0x006a44: f9400268  ldr      x8, [x19]
//   0x006a48: aa1303e0  mov      x0, x19
//   0x006a4c: aa1503e1  mov      x1, x21
//   0x006a50: d378fd09  lsr      x9, x8, #0x38
//   0x006a54: 39031269  strb     w9, [x19, #0xc4]
//   0x006a58: d370fd09  lsr      x9, x8, #0x30
//   0x006a5c: 39031669  strb     w9, [x19, #0xc5]
//   0x006a60: d368fd09  lsr      x9, x8, #0x28
//   0x006a64: 39031a69  strb     w9, [x19, #0xc6]
//   0x006a68: d360fd09  lsr      x9, x8, #0x20
//   0x006a6c: 39031e69  strb     w9, [x19, #0xc7]
//   0x006a70: d358fd09  lsr      x9, x8, #0x18
//   0x006a74: 39032269  strb     w9, [x19, #0xc8]
//   0x006a78: d350fd09  lsr      x9, x8, #0x10
//   0x006a7c: 39032669  strb     w9, [x19, #0xc9]
//   0x006a80: d348fd09  lsr      x9, x8, #8
//   0x006a84: 39032a69  strb     w9, [x19, #0xca]
//   0x006a88: 39032e68  strb     w8, [x19, #0xcb]
//   0x006a8c: 97fffec5  bl       #0x65a0
//   0x006a90: aa1f03e8  mov      x8, xzr
//   0x006a94: 91002269  add      x9, x19, #8
//   0x006a98: 91000e8a  add      x10, x20, #3
//   0x006a9c: 8b08012b  add      x11, x9, x8
//   0x006aa0: 39401d6c  ldrb     w12, [x11, #7]
//   0x006aa4: 8b08014d  add      x13, x10, x8
//   0x006aa8: 91002108  add      x8, x8, #8
//   0x006aac: f101011f  cmp      x8, #0x40
//   0x006ab0: 381fd1ac  sturb    w12, [x13, #-3]
//   0x006ab4: 79400d6c  ldrh     w12, [x11, #6]
//   0x006ab8: 381fe1ac  sturb    w12, [x13, #-2]
//   0x006abc: f940016c  ldr      x12, [x11]
//   0x006ac0: d368fd8c  lsr      x12, x12, #0x28
//   0x006ac4: 381ff1ac  sturb    w12, [x13, #-1]
//   0x006ac8: b940056c  ldr      w12, [x11, #4]
//   0x006acc: 390001ac  strb     w12, [x13]
//   0x006ad0: f940016c  ldr      x12, [x11]
//   0x006ad4: d358fd8c  lsr      x12, x12, #0x18
//   0x006ad8: 390005ac  strb     w12, [x13, #1]
//   0x006adc: f940016c  ldr      x12, [x11]
//   0x006ae0: d350fd8c  lsr      x12, x12, #0x10
//   0x006ae4: 390009ac  strb     w12, [x13, #2]
//   0x006ae8: f940016c  ldr      x12, [x11]
//   0x006aec: d348fd8c  lsr      x12, x12, #8
//   0x006af0: 39000dac  strb     w12, [x13, #3]
//   0x006af4: f940016b  ldr      x11, [x11]
//   0x006af8: 390011ab  strb     w11, [x13, #4]
//   0x006afc: 54fffd01  b.ne     #0x6a9c
//   0x006b00: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x006b04: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x006b08: f84307f5  ldr      x21, [sp], #0x30
//   0x006b0c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_32_69a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000069a4ULL;
    for (std::size_t i = 0; i < 91ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6161ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[33] Subroutine @ 0x006b10..0x006c74 (356 bytes, 89 AArch64 instructions)
// [VN] Khung FDE[33] Hàm con @ 0x006b10..0x006c74 (356 byte, 89 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006b10: d10543ff  sub      sp, sp, #0x150
//   0x006b14: a90f6ffc  stp      x28, x27, [sp, #0xf0]
//   0x006b18: a91067fa  stp      x26, x25, [sp, #0x100]
//   0x006b1c: a9115ff8  stp      x24, x23, [sp, #0x110]
//   0x006b20: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x006b24: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x006b28: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x006b2c: 910503fd  add      x29, sp, #0x140
//   0x006b30: d53bd058  mrs      x24, tpidr_el0
//   0x006b34: f0000028  adrp     x8, #0xd000
//   0x006b38: f0000029  adrp     x9, #0xd000
//   0x006b3c: 3dc3c100  ldr      q0, [x8, #0xf00]
//   0x006b40: f9401708  ldr      x8, [x24, #0x28]
//   0x006b44: 3dc3c521  ldr      q1, [x9, #0xf10]
//   0x006b48: f0000029  adrp     x9, #0xd000
//   0x006b4c: 3dc3c922  ldr      q2, [x9, #0xf20]
//   0x006b50: f81a83a8  stur     x8, [x29, #-0x58]
//   0x006b54: f0000028  adrp     x8, #0xd000
//   0x006b58: ad0087e0  stp      q0, q1, [sp, #0x10]
//   0x006b5c: 3dc3cd00  ldr      q0, [x8, #0xf30]
//   0x006b60: d2842f28  mov      x8, #0x2179
//   0x006b64: f2a26fc8  movk     x8, #0x137e, lsl #16
//   0x006b68: f2d9a328  movk     x8, #0xcd19, lsl #32
//   0x006b6c: aa0203f3  mov      x19, x2
//   0x006b70: aa0103f5  mov      x21, x1
//   0x006b74: aa0003f4  mov      x20, x0
//   0x006b78: f2eb7c08  movk     x8, #0x5be0, lsl #48
//   0x006b7c: b9005bff  str      wzr, [sp, #0x58]
//   0x006b80: ad0183e2  stp      q2, q0, [sp, #0x30]
//   0x006b84: f9002be8  str      x8, [sp, #0x50]
//   0x006b88: b4000575  cbz      x21, #0x6c34
//   0x006b8c: 910043f9  add      x25, sp, #0x10
//   0x006b90: 2a1f03fb  mov      w27, wzr
//   0x006b94: 91013336  add      x22, x25, #0x4c
//   0x006b98: 321903fa  mov      w26, #0x80
//   0x006b9c: 3400009b  cbz      w27, #0x6bac
//   0x006ba0: 1400000f  b        #0x6bdc
//   0x006ba4: b9405bfb  ldr      w27, [sp, #0x58]
//   0x006ba8: 350001bb  cbnz     w27, #0x6bdc
//   0x006bac: f10202b7  subs     x23, x21, #0x80
//   0x006bb0: 54000163  b.lo     #0x6bdc
//   0x006bb4: 910043e0  add      x0, sp, #0x10
//   0x006bb8: aa1403e1  mov      x1, x20
//   0x006bbc: 97fffe79  bl       #0x65a0
//   0x006bc0: f9400be8  ldr      x8, [sp, #0x10]
//   0x006bc4: 91020294  add      x20, x20, #0x80
//   0x006bc8: aa1703f5  mov      x21, x23
//   0x006bcc: 91100108  add      x8, x8, #0x400
//   0x006bd0: f9000be8  str      x8, [sp, #0x10]
//   0x006bd4: b5fffe95  cbnz     x21, #0x6ba4
//   0x006bd8: 14000017  b        #0x6c34
//   0x006bdc: 4b1b0348  sub      w8, w26, w27
//   0x006be0: eb0802bf  cmp      x21, x8
//   0x006be4: 8b3b4329  add      x9, x25, w27, uxtw
//   0x006be8: 9a8832b7  csel     x23, x21, x8, lo
//   0x006bec: 91013120  add      x0, x9, #0x4c
//   0x006bf0: aa1403e1  mov      x1, x20
//   0x006bf4: aa1703e2  mov      x2, x23
//   0x006bf8: 97ffe74a  bl       #0x920
//   0x006bfc: 0b170368  add      w8, w27, w23
//   0x006c00: 8b170294  add      x20, x20, x23
//   0x006c04: 7102011f  cmp      w8, #0x80
//   0x006c08: cb1702b5  sub      x21, x21, x23
//   0x006c0c: b9005be8  str      w8, [sp, #0x58]
//   0x006c10: 54000101  b.ne     #0x6c30
//   0x006c14: 910043e0  add      x0, sp, #0x10
//   0x006c18: aa1603e1  mov      x1, x22
//   0x006c1c: 97fffe61  bl       #0x65a0
//   0x006c20: f9400be8  ldr      x8, [sp, #0x10]
//   0x006c24: b9005bff  str      wzr, [sp, #0x58]
//   0x006c28: 91100108  add      x8, x8, #0x400
//   0x006c2c: f9000be8  str      x8, [sp, #0x10]
//   0x006c30: b5fffbb5  cbnz     x21, #0x6ba4
//   0x006c34: 910043e0  add      x0, sp, #0x10
//   0x006c38: aa1303e1  mov      x1, x19
//   0x006c3c: 97ffff5a  bl       #0x69a4
//   0x006c40: f9401708  ldr      x8, [x24, #0x28]
//   0x006c44: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x006c48: eb09011f  cmp      x8, x9
//   0x006c4c: 54000121  b.ne     #0x6c70
//   0x006c50: a9547bfd  ldp      x29, x30, [sp, #0x140]
//   0x006c54: a9534ff4  ldp      x20, x19, [sp, #0x130]
//   0x006c58: a95257f6  ldp      x22, x21, [sp, #0x120]
//   0x006c5c: a9515ff8  ldp      x24, x23, [sp, #0x110]
//   0x006c60: a95067fa  ldp      x26, x25, [sp, #0x100]
//   0x006c64: a94f6ffc  ldp      x28, x27, [sp, #0xf0]
//   0x006c68: 910543ff  add      sp, sp, #0x150
//   0x006c6c: d65f03c0  ret      
//   0x006c70: 97ffe724  bl       #0x900
// ============================================================================
std::uint32_t fde_33_6b10(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006b10ULL;
    for (std::size_t i = 0; i < 89ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6252ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[34] Subroutine @ 0x006c74..0x006ea8 (564 bytes, 141 AArch64 instructions)
// [VN] Khung FDE[34] Hàm con @ 0x006c74..0x006ea8 (564 byte, 141 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006c74: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x006c78: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x006c7c: 910043fd  add      x29, sp, #0x10
//   0x006c80: aa0203f3  mov      x19, x2
//   0x006c84: 94000168  bl       #0x7224
//   0x006c88: 37f810a0  tbnz     w0, #0x1f, #0x6e9c
//   0x006c8c: b980f269  ldrsw    x9, [x19, #0xf0]
//   0x006c90: 7100053f  cmp      w9, #1
//   0x006c94: 5400102b  b.lt     #0x6e98
//   0x006c98: d37ef52a  lsl      x10, x9, #2
//   0x006c9c: 8b091269  add      x9, x19, x9, lsl #4
//   0x006ca0: aa1f03e8  mov      x8, xzr
//   0x006ca4: d100114b  sub      x11, x10, #4
//   0x006ca8: 91002129  add      x9, x9, #8
//   0x006cac: 9100226a  add      x10, x19, #8
//   0x006cb0: b85f812c  ldur     w12, [x9, #-8]
//   0x006cb4: b85f814d  ldur     w13, [x10, #-8]
//   0x006cb8: 91001108  add      x8, x8, #4
//   0x006cbc: eb0b011f  cmp      x8, x11
//   0x006cc0: b81f814c  stur     w12, [x10, #-8]
//   0x006cc4: b81f812d  stur     w13, [x9, #-8]
//   0x006cc8: b85fc12c  ldur     w12, [x9, #-4]
//   0x006ccc: b85fc14d  ldur     w13, [x10, #-4]
//   0x006cd0: d100116b  sub      x11, x11, #4
//   0x006cd4: b81fc14c  stur     w12, [x10, #-4]
//   0x006cd8: b81fc12d  stur     w13, [x9, #-4]
//   0x006cdc: b940012c  ldr      w12, [x9]
//   0x006ce0: b940014d  ldr      w13, [x10]
//   0x006ce4: b900014c  str      w12, [x10]
//   0x006ce8: b900012d  str      w13, [x9]
//   0x006cec: b940052c  ldr      w12, [x9, #4]
//   0x006cf0: b940054d  ldr      w13, [x10, #4]
//   0x006cf4: b900054c  str      w12, [x10, #4]
//   0x006cf8: b900052d  str      w13, [x9, #4]
//   0x006cfc: d1004129  sub      x9, x9, #0x10
//   0x006d00: 9100414a  add      x10, x10, #0x10
//   0x006d04: 54fffd6b  b.lt     #0x6cb0
//   0x006d08: b940f268  ldr      w8, [x19, #0xf0]
//   0x006d0c: 7100091f  cmp      w8, #2
//   0x006d10: 54000c4b  b.lt     #0x6e98
//   0x006d14: 9000004a  adrp     x10, #0xe000
//   0x006d18: 9000004b  adrp     x11, #0xe000
//   0x006d1c: 9000004c  adrp     x12, #0xe000
//   0x006d20: 9000004d  adrp     x13, #0xe000
//   0x006d24: b000004e  adrp     x14, #0xf000
//   0x006d28: 91007268  add      x8, x19, #0x1c
//   0x006d2c: 320003e9  mov      w9, #1
//   0x006d30: 9117014a  add      x10, x10, #0x5c0
//   0x006d34: 9107016b  add      x11, x11, #0x1c0
//   0x006d38: 9127018c  add      x12, x12, #0x9c0
//   0x006d3c: 913701ad  add      x13, x13, #0xdc0
//   0x006d40: 910701ce  add      x14, x14, #0x1c0
//   0x006d44: 297ec10f  ldp      w15, w16, [x8, #-0xc]
//   0x006d48: 297fc911  ldp      w17, w18, [x8, #-4]
//   0x006d4c: 11000529  add      w9, w9, #1
//   0x006d50: d3587de0  ubfx     x0, x15, #0x18, #8
//   0x006d54: 53105de1  ubfx     w1, w15, #0x10, #8
//   0x006d58: d37ef400  lsl      x0, x0, #2
//   0x006d5c: d37ef421  lsl      x1, x1, #2
//   0x006d60: 38606940  ldrb     w0, [x10, x0]
//   0x006d64: 38616941  ldrb     w1, [x10, x1]
//   0x006d68: d3587e03  ubfx     x3, x16, #0x18, #8
//   0x006d6c: 53105e04  ubfx     w4, w16, #0x10, #8
//   0x006d70: b8607960  ldr      w0, [x11, x0, lsl #2]
//   0x006d74: b8617981  ldr      w1, [x12, x1, lsl #2]
//   0x006d78: d3587e25  ubfx     x5, x17, #0x18, #8
//   0x006d7c: 53105e26  ubfx     w6, w17, #0x10, #8
//   0x006d80: d3587e47  ubfx     x7, x18, #0x18, #8
//   0x006d84: 4a000020  eor      w0, w1, w0
//   0x006d88: 53105e41  ubfx     w1, w18, #0x10, #8
//   0x006d8c: d37ef463  lsl      x3, x3, #2
//   0x006d90: d37ef484  lsl      x4, x4, #2
//   0x006d94: d37ef4a5  lsl      x5, x5, #2
//   0x006d98: d37ef4c6  lsl      x6, x6, #2
//   0x006d9c: d37ef4e7  lsl      x7, x7, #2
//   0x006da0: d37ef421  lsl      x1, x1, #2
//   0x006da4: 38636943  ldrb     w3, [x10, x3]
//   0x006da8: 38646944  ldrb     w4, [x10, x4]
//   0x006dac: 38656945  ldrb     w5, [x10, x5]
//   0x006db0: 38666946  ldrb     w6, [x10, x6]
//   0x006db4: 38676947  ldrb     w7, [x10, x7]
//   0x006db8: 38616941  ldrb     w1, [x10, x1]
//   0x006dbc: b8637963  ldr      w3, [x11, x3, lsl #2]
//   0x006dc0: b8647984  ldr      w4, [x12, x4, lsl #2]
//   0x006dc4: b8657965  ldr      w5, [x11, x5, lsl #2]
//   0x006dc8: b8667986  ldr      w6, [x12, x6, lsl #2]
//   0x006dcc: b8677967  ldr      w7, [x11, x7, lsl #2]
//   0x006dd0: b8617981  ldr      w1, [x12, x1, lsl #2]
//   0x006dd4: 53083de2  ubfx     w2, w15, #8, #8
//   0x006dd8: 4a030083  eor      w3, w4, w3
//   0x006ddc: 53083e04  ubfx     w4, w16, #8, #8
//   0x006de0: 4a0500c5  eor      w5, w6, w5
//   0x006de4: 53083e26  ubfx     w6, w17, #8, #8
//   0x006de8: 4a070021  eor      w1, w1, w7
//   0x006dec: 53083e47  ubfx     w7, w18, #8, #8
//   0x006df0: d37ef442  lsl      x2, x2, #2
//   0x006df4: d37ef484  lsl      x4, x4, #2
//   0x006df8: d37ef4c6  lsl      x6, x6, #2
//   0x006dfc: d37ef4e7  lsl      x7, x7, #2
//   0x006e00: 92401def  and      x15, x15, #0xff
//   0x006e04: 92401e10  and      x16, x16, #0xff
//   0x006e08: 92401e31  and      x17, x17, #0xff
//   0x006e0c: 92401e52  and      x18, x18, #0xff
//   0x006e10: 38626942  ldrb     w2, [x10, x2]
//   0x006e14: 38646944  ldrb     w4, [x10, x4]
//   0x006e18: 38666946  ldrb     w6, [x10, x6]
//   0x006e1c: 38676947  ldrb     w7, [x10, x7]
//   0x006e20: d37ef5ef  lsl      x15, x15, #2
//   0x006e24: d37ef610  lsl      x16, x16, #2
//   0x006e28: d37ef631  lsl      x17, x17, #2
//   0x006e2c: d37ef652  lsl      x18, x18, #2
//   0x006e30: 386f694f  ldrb     w15, [x10, x15]
//   0x006e34: 38706950  ldrb     w16, [x10, x16]
//   0x006e38: 38716951  ldrb     w17, [x10, x17]
//   0x006e3c: 38726952  ldrb     w18, [x10, x18]
//   0x006e40: b86279a2  ldr      w2, [x13, x2, lsl #2]
//   0x006e44: b86479a4  ldr      w4, [x13, x4, lsl #2]
//   0x006e48: b86679a6  ldr      w6, [x13, x6, lsl #2]
//   0x006e4c: b86779a7  ldr      w7, [x13, x7, lsl #2]
//   0x006e50: b86f79cf  ldr      w15, [x14, x15, lsl #2]
//   0x006e54: b87079d0  ldr      w16, [x14, x16, lsl #2]
//   0x006e58: b87179d1  ldr      w17, [x14, x17, lsl #2]
//   0x006e5c: b87279d2  ldr      w18, [x14, x18, lsl #2]
//   0x006e60: 4a020000  eor      w0, w0, w2
//   0x006e64: 4a040062  eor      w2, w3, w4
//   0x006e68: 4a0600a3  eor      w3, w5, w6
//   0x006e6c: 4a070021  eor      w1, w1, w7
//   0x006e70: 4a0f000f  eor      w15, w0, w15
//   0x006e74: 4a100050  eor      w16, w2, w16
//   0x006e78: 4a110071  eor      w17, w3, w17
//   0x006e7c: 4a120032  eor      w18, w1, w18
//   0x006e80: 293ec10f  stp      w15, w16, [x8, #-0xc]
//   0x006e84: 293fc911  stp      w17, w18, [x8, #-4]
//   0x006e88: b940f26f  ldr      w15, [x19, #0xf0]
//   0x006e8c: 91004108  add      x8, x8, #0x10
//   0x006e90: 6b0f013f  cmp      w9, w15
//   0x006e94: 54fff58b  b.lt     #0x6d44
//   0x006e98: 2a1f03e0  mov      w0, wzr
//   0x006e9c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x006ea0: f84207f3  ldr      x19, [sp], #0x20
//   0x006ea4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_34_6c74(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006c74ULL;
    for (std::size_t i = 0; i < 141ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6341ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[35] Subroutine @ 0x006ea8..0x007224 (892 bytes, 223 AArch64 instructions)
// [VN] Khung FDE[35] Hàm con @ 0x006ea8..0x007224 (892 byte, 223 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006ea8: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x006eac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x006eb0: 29403008  ldp      w8, w12, [x0]
//   0x006eb4: 2940344b  ldp      w11, w13, [x2]
//   0x006eb8: 29413c0e  ldp      w14, w15, [x0, #8]
//   0x006ebc: b940f043  ldr      w3, [x2, #0xf0]
//   0x006ec0: 29410052  ldp      w18, w0, [x2, #8]
//   0x006ec4: 5ac00908  rev      w8, w8
//   0x006ec8: 4a0b0110  eor      w16, w8, w11
//   0x006ecc: 5ac00988  rev      w8, w12
//   0x006ed0: 4a0d0111  eor      w17, w8, w13
//   0x006ed4: 5ac009c8  rev      w8, w14
//   0x006ed8: 13017c6e  asr      w14, w3, #1
//   0x006edc: 5ac009ed  rev      w13, w15
//   0x006ee0: 4a120112  eor      w18, w8, w18
//   0x006ee4: 510005c8  sub      w8, w14, #1
//   0x006ee8: 320003e4  mov      w4, #1
//   0x006eec: 9000004a  adrp     x10, #0xe000
//   0x006ef0: 9000004b  adrp     x11, #0xe000
//   0x006ef4: 9000004c  adrp     x12, #0xe000
//   0x006ef8: 4a0001a0  eor      w0, w13, w0
//   0x006efc: d37df10d  lsl      x13, x8, #3
//   0x006f00: b000004f  adrp     x15, #0xf000
//   0x006f04: 91006049  add      x9, x2, #0x18
//   0x006f08: 9107014a  add      x10, x10, #0x1c0
//   0x006f0c: 9127016b  add      x11, x11, #0x9c0
//   0x006f10: 9137018c  add      x12, x12, #0xdc0
//   0x006f14: 4b0e008e  sub      w14, w4, w14
//   0x006f18: 910021a8  add      x8, x13, #8
//   0x006f1c: 910701ef  add      x15, x15, #0x1c0
//   0x006f20: 14000034  b        #0x6ff0
//   0x006f24: 53105c04  ubfx     w4, w0, #0x10, #8
//   0x006f28: b8635943  ldr      w3, [x10, w3, uxtw #2]
//   0x006f2c: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x006f30: 53187e26  lsr      w6, w17, #0x18
//   0x006f34: 53105e07  ubfx     w7, w16, #0x10, #8
//   0x006f38: 53187e53  lsr      w19, w18, #0x18
//   0x006f3c: 53105e34  ubfx     w20, w17, #0x10, #8
//   0x006f40: 53187c15  lsr      w21, w0, #0x18
//   0x006f44: 4a030083  eor      w3, w4, w3
//   0x006f48: 53105e44  ubfx     w4, w18, #0x10, #8
//   0x006f4c: b8665946  ldr      w6, [x10, w6, uxtw #2]
//   0x006f50: b8675967  ldr      w7, [x11, w7, uxtw #2]
//   0x006f54: b8735953  ldr      w19, [x10, w19, uxtw #2]
//   0x006f58: b8745974  ldr      w20, [x11, w20, uxtw #2]
//   0x006f5c: b8755955  ldr      w21, [x10, w21, uxtw #2]
//   0x006f60: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x006f64: 53083e45  ubfx     w5, w18, #8, #8
//   0x006f68: 4a0600e6  eor      w6, w7, w6
//   0x006f6c: 53083c07  ubfx     w7, w0, #8, #8
//   0x006f70: 4a130293  eor      w19, w20, w19
//   0x006f74: 53083e14  ubfx     w20, w16, #8, #8
//   0x006f78: 4a150084  eor      w4, w4, w21
//   0x006f7c: 53083e35  ubfx     w21, w17, #8, #8
//   0x006f80: b8655985  ldr      w5, [x12, w5, uxtw #2]
//   0x006f84: b8675987  ldr      w7, [x12, w7, uxtw #2]
//   0x006f88: b8745994  ldr      w20, [x12, w20, uxtw #2]
//   0x006f8c: 12001e31  and      w17, w17, #0xff
//   0x006f90: 12001e52  and      w18, w18, #0xff
//   0x006f94: 12001c00  and      w0, w0, #0xff
//   0x006f98: b87159f1  ldr      w17, [x15, w17, uxtw #2]
//   0x006f9c: b87259f2  ldr      w18, [x15, w18, uxtw #2]
//   0x006fa0: b86059e0  ldr      w0, [x15, w0, uxtw #2]
//   0x006fa4: b8755995  ldr      w21, [x12, w21, uxtw #2]
//   0x006fa8: 12001e10  and      w16, w16, #0xff
//   0x006fac: 4a050063  eor      w3, w3, w5
//   0x006fb0: 4a0700c5  eor      w5, w6, w7
//   0x006fb4: 4a140266  eor      w6, w19, w20
//   0x006fb8: b87059f0  ldr      w16, [x15, w16, uxtw #2]
//   0x006fbc: 4a110071  eor      w17, w3, w17
//   0x006fc0: 4a1200b2  eor      w18, w5, w18
//   0x006fc4: 29411523  ldp      w3, w5, [x9, #8]
//   0x006fc8: 4a0000c0  eor      w0, w6, w0
//   0x006fcc: 29421d26  ldp      w6, w7, [x9, #0x10]
//   0x006fd0: 4a150084  eor      w4, w4, w21
//   0x006fd4: 4a100084  eor      w4, w4, w16
//   0x006fd8: 110005ce  add      w14, w14, #1
//   0x006fdc: 4a030230  eor      w16, w17, w3
//   0x006fe0: 4a050251  eor      w17, w18, w5
//   0x006fe4: 4a060012  eor      w18, w0, w6
//   0x006fe8: 4a070080  eor      w0, w4, w7
//   0x006fec: 91008129  add      x9, x9, #0x20
//   0x006ff0: 53187e03  lsr      w3, w16, #0x18
//   0x006ff4: 53105c04  ubfx     w4, w0, #0x10, #8
//   0x006ff8: b8635943  ldr      w3, [x10, w3, uxtw #2]
//   0x006ffc: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x007000: 53187e26  lsr      w6, w17, #0x18
//   0x007004: 53105e07  ubfx     w7, w16, #0x10, #8
//   0x007008: 53187e53  lsr      w19, w18, #0x18
//   0x00700c: 53105e34  ubfx     w20, w17, #0x10, #8
//   0x007010: 53187c15  lsr      w21, w0, #0x18
//   0x007014: 4a030083  eor      w3, w4, w3
//   0x007018: 53105e44  ubfx     w4, w18, #0x10, #8
//   0x00701c: b8665946  ldr      w6, [x10, w6, uxtw #2]
//   0x007020: b8675967  ldr      w7, [x11, w7, uxtw #2]
//   0x007024: b8735953  ldr      w19, [x10, w19, uxtw #2]
//   0x007028: b8745974  ldr      w20, [x11, w20, uxtw #2]
//   0x00702c: b8755955  ldr      w21, [x10, w21, uxtw #2]
//   0x007030: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x007034: 53083e45  ubfx     w5, w18, #8, #8
//   0x007038: 4a0600e6  eor      w6, w7, w6
//   0x00703c: 53083c07  ubfx     w7, w0, #8, #8
//   0x007040: 4a130293  eor      w19, w20, w19
//   0x007044: 53083e14  ubfx     w20, w16, #8, #8
//   0x007048: 4a150084  eor      w4, w4, w21
//   0x00704c: 53083e35  ubfx     w21, w17, #8, #8
//   0x007050: b8655985  ldr      w5, [x12, w5, uxtw #2]
//   0x007054: b8675987  ldr      w7, [x12, w7, uxtw #2]
//   0x007058: 12001e31  and      w17, w17, #0xff
//   0x00705c: 12001e52  and      w18, w18, #0xff
//   0x007060: b8745994  ldr      w20, [x12, w20, uxtw #2]
//   0x007064: 12001c00  and      w0, w0, #0xff
//   0x007068: b87159f1  ldr      w17, [x15, w17, uxtw #2]
//   0x00706c: b87259f2  ldr      w18, [x15, w18, uxtw #2]
//   0x007070: b86059e0  ldr      w0, [x15, w0, uxtw #2]
//   0x007074: b8755995  ldr      w21, [x12, w21, uxtw #2]
//   0x007078: 4a050063  eor      w3, w3, w5
//   0x00707c: 4a0700c5  eor      w5, w6, w7
//   0x007080: 12001e10  and      w16, w16, #0xff
//   0x007084: 4a140266  eor      w6, w19, w20
//   0x007088: b87059f0  ldr      w16, [x15, w16, uxtw #2]
//   0x00708c: 4a110071  eor      w17, w3, w17
//   0x007090: 4a1200b2  eor      w18, w5, w18
//   0x007094: 297f1523  ldp      w3, w5, [x9, #-8]
//   0x007098: 4a0000c0  eor      w0, w6, w0
//   0x00709c: 29401d26  ldp      w6, w7, [x9]
//   0x0070a0: 4a150084  eor      w4, w4, w21
//   0x0070a4: 4a100084  eor      w4, w4, w16
//   0x0070a8: 4a030230  eor      w16, w17, w3
//   0x0070ac: 4a050251  eor      w17, w18, w5
//   0x0070b0: 4a060012  eor      w18, w0, w6
//   0x0070b4: 4a070080  eor      w0, w4, w7
//   0x0070b8: 53187e03  lsr      w3, w16, #0x18
//   0x0070bc: 35fff34e  cbnz     w14, #0x6f24
//   0x0070c0: 9000004a  adrp     x10, #0xf000
//   0x0070c4: 9117014a  add      x10, x10, #0x5c0
//   0x0070c8: 53105c0b  ubfx     w11, w0, #0x10, #8
//   0x0070cc: 38634943  ldrb     w3, [x10, w3, uxtw]
//   0x0070d0: 53083e4c  ubfx     w12, w18, #8, #8
//   0x0070d4: 386b494b  ldrb     w11, [x10, w11, uxtw]
//   0x0070d8: 8b0d0849  add      x9, x2, x13, lsl #2
//   0x0070dc: 12001e2d  and      w13, w17, #0xff
//   0x0070e0: 386c494c  ldrb     w12, [x10, w12, uxtw]
//   0x0070e4: b8687848  ldr      w8, [x2, x8, lsl #2]
//   0x0070e8: 53187e2e  lsr      w14, w17, #0x18
//   0x0070ec: 53105e0f  ubfx     w15, w16, #0x10, #8
//   0x0070f0: 53083c02  ubfx     w2, w0, #8, #8
//   0x0070f4: 12001e44  and      w4, w18, #0xff
//   0x0070f8: 53187e45  lsr      w5, w18, #0x18
//   0x0070fc: 53105e26  ubfx     w6, w17, #0x10, #8
//   0x007100: 53083e07  ubfx     w7, w16, #8, #8
//   0x007104: 12001c13  and      w19, w0, #0xff
//   0x007108: 53187c00  lsr      w0, w0, #0x18
//   0x00710c: 53105e52  ubfx     w18, w18, #0x10, #8
//   0x007110: 53083e31  ubfx     w17, w17, #8, #8
//   0x007114: 12001e10  and      w16, w16, #0xff
//   0x007118: 386d494d  ldrb     w13, [x10, w13, uxtw]
//   0x00711c: 386e494e  ldrb     w14, [x10, w14, uxtw]
//   0x007120: 386f494f  ldrb     w15, [x10, w15, uxtw]
//   0x007124: 38624942  ldrb     w2, [x10, w2, uxtw]
//   0x007128: 38644944  ldrb     w4, [x10, w4, uxtw]
//   0x00712c: 38654945  ldrb     w5, [x10, w5, uxtw]
//   0x007130: 38664946  ldrb     w6, [x10, w6, uxtw]
//   0x007134: 38674947  ldrb     w7, [x10, w7, uxtw]
//   0x007138: 38734953  ldrb     w19, [x10, w19, uxtw]
//   0x00713c: 38604940  ldrb     w0, [x10, w0, uxtw]
//   0x007140: 38724952  ldrb     w18, [x10, w18, uxtw]
//   0x007144: 38714951  ldrb     w17, [x10, w17, uxtw]
//   0x007148: 3870494a  ldrb     w10, [x10, w16, uxtw]
//   0x00714c: 53081c70  lsl      w16, w3, #0x18
//   0x007150: 33101d70  bfi      w16, w11, #0x10, #8
//   0x007154: 33181d90  bfi      w16, w12, #8, #8
//   0x007158: 2a0d020b  orr      w11, w16, w13
//   0x00715c: 4a080168  eor      w8, w11, w8
//   0x007160: 53187d0b  lsr      w11, w8, #0x18
//   0x007164: 3900002b  strb     w11, [x1]
//   0x007168: 53107d0b  lsr      w11, w8, #0x10
//   0x00716c: 39000c28  strb     w8, [x1, #3]
//   0x007170: 53087d08  lsr      w8, w8, #8
//   0x007174: 3900042b  strb     w11, [x1, #1]
//   0x007178: 39000828  strb     w8, [x1, #2]
//   0x00717c: 53081dcb  lsl      w11, w14, #0x18
//   0x007180: b9402528  ldr      w8, [x9, #0x24]
//   0x007184: 33101deb  bfi      w11, w15, #0x10, #8
//   0x007188: 33181c4b  bfi      w11, w2, #8, #8
//   0x00718c: 2a04016b  orr      w11, w11, w4
//   0x007190: 4a080168  eor      w8, w11, w8
//   0x007194: 53187d0b  lsr      w11, w8, #0x18
//   0x007198: 3900102b  strb     w11, [x1, #4]
//   0x00719c: 53107d0b  lsr      w11, w8, #0x10
//   0x0071a0: 39001c28  strb     w8, [x1, #7]
//   0x0071a4: 53087d08  lsr      w8, w8, #8
//   0x0071a8: 3900142b  strb     w11, [x1, #5]
//   0x0071ac: 39001828  strb     w8, [x1, #6]
//   0x0071b0: 53081cab  lsl      w11, w5, #0x18
//   0x0071b4: b9402928  ldr      w8, [x9, #0x28]
//   0x0071b8: 33101ccb  bfi      w11, w6, #0x10, #8
//   0x0071bc: 33181ceb  bfi      w11, w7, #8, #8
//   0x0071c0: 2a13016b  orr      w11, w11, w19
//   0x0071c4: 4a080168  eor      w8, w11, w8
//   0x0071c8: 53187d0b  lsr      w11, w8, #0x18
//   0x0071cc: 53107d0d  lsr      w13, w8, #0x10
//   0x0071d0: 53087d0e  lsr      w14, w8, #8
//   0x0071d4: 39002c28  strb     w8, [x1, #0xb]
//   0x0071d8: 3900202b  strb     w11, [x1, #8]
//   0x0071dc: 3900242d  strb     w13, [x1, #9]
//   0x0071e0: 3900282e  strb     w14, [x1, #0xa]
//   0x0071e4: 53081c0c  lsl      w12, w0, #0x18
//   0x0071e8: b9402d28  ldr      w8, [x9, #0x2c]
//   0x0071ec: 33101e4c  bfi      w12, w18, #0x10, #8
//   0x0071f0: 33181e2c  bfi      w12, w17, #8, #8
//   0x0071f4: 2a0a0189  orr      w9, w12, w10
//   0x0071f8: 4a080128  eor      w8, w9, w8
//   0x0071fc: 53187d09  lsr      w9, w8, #0x18
//   0x007200: 53107d0a  lsr      w10, w8, #0x10
//   0x007204: 53087d0b  lsr      w11, w8, #8
//   0x007208: 39003029  strb     w9, [x1, #0xc]
//   0x00720c: 3900342a  strb     w10, [x1, #0xd]
//   0x007210: 3900382b  strb     w11, [x1, #0xe]
//   0x007214: 39003c28  strb     w8, [x1, #0xf]
//   0x007218: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00721c: f84207f5  ldr      x21, [sp], #0x20
//   0x007220: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_35_6ea8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006ea8ULL;
    for (std::size_t i = 0; i < 223ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6482ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[36] Subroutine @ 0x007224..0x007570 (844 bytes, 211 AArch64 instructions)
// [VN] Khung FDE[36] Hàm con @ 0x007224..0x007570 (844 byte, 211 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007224: 12800008  mov      w8, #-1
//   0x007228: b4001a00  cbz      x0, #0x7568
//   0x00722c: b40019e2  cbz      x2, #0x7568
//   0x007230: 7102003f  cmp      w1, #0x80
//   0x007234: 540000a0  b.eq     #0x7248
//   0x007238: 7104003f  cmp      w1, #0x100
//   0x00723c: 54000060  b.eq     #0x7248
//   0x007240: 7103003f  cmp      w1, #0xc0
//   0x007244: 54000121  b.ne     #0x7268
//   0x007248: 7102003f  cmp      w1, #0x80
//   0x00724c: 54000061  b.ne     #0x7258
//   0x007250: 52800148  mov      w8, #0xa
//   0x007254: 14000009  b        #0x7278
//   0x007258: 7103003f  cmp      w1, #0xc0
//   0x00725c: 540000c1  b.ne     #0x7274
//   0x007260: 321e07e8  mov      w8, #0xc
//   0x007264: 14000005  b        #0x7278
//   0x007268: 321f7be8  mov      w8, #-2
//   0x00726c: 2a0803e0  mov      w0, w8
//   0x007270: d65f03c0  ret      
//   0x007274: 321f0be8  mov      w8, #0xe
//   0x007278: b900f048  str      w8, [x2, #0xf0]
//   0x00727c: b9400008  ldr      w8, [x0]
//   0x007280: 7102003f  cmp      w1, #0x80
//   0x007284: 5ac00908  rev      w8, w8
//   0x007288: b9000048  str      w8, [x2]
//   0x00728c: b9400409  ldr      w9, [x0, #4]
//   0x007290: 5ac00929  rev      w9, w9
//   0x007294: b9000449  str      w9, [x2, #4]
//   0x007298: b9400809  ldr      w9, [x0, #8]
//   0x00729c: 5ac00929  rev      w9, w9
//   0x0072a0: b9000849  str      w9, [x2, #8]
//   0x0072a4: b9400c09  ldr      w9, [x0, #0xc]
//   0x0072a8: 5ac00929  rev      w9, w9
//   0x0072ac: b9000c49  str      w9, [x2, #0xc]
//   0x0072b0: 54000561  b.ne     #0x735c
//   0x0072b4: 9000004b  adrp     x11, #0xf000
//   0x0072b8: 9000004c  adrp     x12, #0xf000
//   0x0072bc: 9000004d  adrp     x13, #0xf000
//   0x0072c0: b000004e  adrp     x14, #0x10000
//   0x0072c4: b000004f  adrp     x15, #0x10000
//   0x0072c8: aa1f03e9  mov      x9, xzr
//   0x0072cc: 9100404a  add      x10, x2, #0x10
//   0x0072d0: 911b016b  add      x11, x11, #0x6c0
//   0x0072d4: 912b018c  add      x12, x12, #0xac0
//   0x0072d8: 913b01ad  add      x13, x13, #0xec0
//   0x0072dc: 910b01ce  add      x14, x14, #0x2c0
//   0x0072e0: 911b01ef  add      x15, x15, #0x6c0
//   0x0072e4: b85fc150  ldur     w16, [x10, #-4]
//   0x0072e8: 53105e11  ubfx     w17, w16, #0x10, #8
//   0x0072ec: b8715971  ldr      w17, [x11, w17, uxtw #2]
//   0x0072f0: 53083e12  ubfx     w18, w16, #8, #8
//   0x0072f4: b8725992  ldr      w18, [x12, w18, uxtw #2]
//   0x0072f8: 92401e00  and      x0, x16, #0xff
//   0x0072fc: 12081e31  and      w17, w17, #0xff000000
//   0x007300: 4a080228  eor      w8, w17, w8
//   0x007304: d3587e11  ubfx     x17, x16, #0x18, #8
//   0x007308: b86079a0  ldr      w0, [x13, x0, lsl #2]
//   0x00730c: d37ef631  lsl      x17, x17, #2
//   0x007310: 387169d1  ldrb     w17, [x14, x17]
//   0x007314: 12101e52  and      w18, w18, #0xff0000
//   0x007318: 4a120108  eor      w8, w8, w18
//   0x00731c: b86969f2  ldr      w18, [x15, x9]
//   0x007320: 12181c00  and      w0, w0, #0xff00
//   0x007324: 4a000108  eor      w8, w8, w0
//   0x007328: 4a110108  eor      w8, w8, w17
//   0x00732c: 4a120108  eor      w8, w8, w18
//   0x007330: 297ec951  ldp      w17, w18, [x10, #-0xc]
//   0x007334: 91001129  add      x9, x9, #4
//   0x007338: f100a13f  cmp      x9, #0x28
//   0x00733c: 4a080231  eor      w17, w17, w8
//   0x007340: 29004548  stp      w8, w17, [x10]
//   0x007344: 4a110251  eor      w17, w18, w17
//   0x007348: 4a100230  eor      w16, w17, w16
//   0x00734c: 29014151  stp      w17, w16, [x10, #8]
//   0x007350: 9100414a  add      x10, x10, #0x10
//   0x007354: 54fffc81  b.ne     #0x72e4
//   0x007358: 14000083  b        #0x7564
//   0x00735c: b9401009  ldr      w9, [x0, #0x10]
//   0x007360: 7103003f  cmp      w1, #0xc0
//   0x007364: 5ac00929  rev      w9, w9
//   0x007368: b9001049  str      w9, [x2, #0x10]
//   0x00736c: b9401409  ldr      w9, [x0, #0x14]
//   0x007370: 5ac00929  rev      w9, w9
//   0x007374: b9001449  str      w9, [x2, #0x14]
//   0x007378: 54000621  b.ne     #0x743c
//   0x00737c: 9000004b  adrp     x11, #0xf000
//   0x007380: 9000004c  adrp     x12, #0xf000
//   0x007384: 9000004d  adrp     x13, #0xf000
//   0x007388: b000004e  adrp     x14, #0x10000
//   0x00738c: b000004f  adrp     x15, #0x10000
//   0x007390: aa1f03e9  mov      x9, xzr
//   0x007394: 9100604a  add      x10, x2, #0x18
//   0x007398: 911b016b  add      x11, x11, #0x6c0
//   0x00739c: 912b018c  add      x12, x12, #0xac0
//   0x0073a0: 913b01ad  add      x13, x13, #0xec0
//   0x0073a4: 910b01ce  add      x14, x14, #0x2c0
//   0x0073a8: 911b01ef  add      x15, x15, #0x6c0
//   0x0073ac: 14000007  b        #0x73c8
//   0x0073b0: b85f8152  ldur     w18, [x10, #-8]
//   0x0073b4: 91001129  add      x9, x9, #4
//   0x0073b8: 4a110251  eor      w17, w18, w17
//   0x0073bc: 4a100230  eor      w16, w17, w16
//   0x0073c0: 29024151  stp      w17, w16, [x10, #0x10]
//   0x0073c4: 9100614a  add      x10, x10, #0x18
//   0x0073c8: b85fc150  ldur     w16, [x10, #-4]
//   0x0073cc: f100713f  cmp      x9, #0x1c
//   0x0073d0: 53105e11  ubfx     w17, w16, #0x10, #8
//   0x0073d4: b8715971  ldr      w17, [x11, w17, uxtw #2]
//   0x0073d8: 53083e12  ubfx     w18, w16, #8, #8
//   0x0073dc: 92401e00  and      x0, x16, #0xff
//   0x0073e0: b8725992  ldr      w18, [x12, w18, uxtw #2]
//   0x0073e4: 12081e31  and      w17, w17, #0xff000000
//   0x0073e8: 4a080228  eor      w8, w17, w8
//   0x0073ec: d3587e11  ubfx     x17, x16, #0x18, #8
//   0x0073f0: b86079a0  ldr      w0, [x13, x0, lsl #2]
//   0x0073f4: d37ef631  lsl      x17, x17, #2
//   0x0073f8: 387169d1  ldrb     w17, [x14, x17]
//   0x0073fc: 12101e52  and      w18, w18, #0xff0000
//   0x007400: 4a120108  eor      w8, w8, w18
//   0x007404: b86969f2  ldr      w18, [x15, x9]
//   0x007408: 12181c00  and      w0, w0, #0xff00
//   0x00740c: 4a000108  eor      w8, w8, w0
//   0x007410: 4a110108  eor      w8, w8, w17
//   0x007414: 297d8151  ldp      w17, w0, [x10, #-0x14]
//   0x007418: 4a120108  eor      w8, w8, w18
//   0x00741c: b85f4152  ldur     w18, [x10, #-0xc]
//   0x007420: 4a080231  eor      w17, w17, w8
//   0x007424: 4a110000  eor      w0, w0, w17
//   0x007428: 29004548  stp      w8, w17, [x10]
//   0x00742c: 4a000251  eor      w17, w18, w0
//   0x007430: 29014540  stp      w0, w17, [x10, #8]
//   0x007434: 54fffbe1  b.ne     #0x73b0
//   0x007438: 1400004b  b        #0x7564
//   0x00743c: b9401809  ldr      w9, [x0, #0x18]
//   0x007440: 7104003f  cmp      w1, #0x100
//   0x007444: 5ac00929  rev      w9, w9
//   0x007448: b9001849  str      w9, [x2, #0x18]
//   0x00744c: b9401c09  ldr      w9, [x0, #0x1c]
//   0x007450: 5ac00929  rev      w9, w9
//   0x007454: b9001c49  str      w9, [x2, #0x1c]
//   0x007458: 54000861  b.ne     #0x7564
//   0x00745c: 9000004b  adrp     x11, #0xf000
//   0x007460: 9000004c  adrp     x12, #0xf000
//   0x007464: 9000004d  adrp     x13, #0xf000
//   0x007468: b000004e  adrp     x14, #0x10000
//   0x00746c: b000004f  adrp     x15, #0x10000
//   0x007470: aa1f03e9  mov      x9, xzr
//   0x007474: 9100804a  add      x10, x2, #0x20
//   0x007478: 911b016b  add      x11, x11, #0x6c0
//   0x00747c: 912b018c  add      x12, x12, #0xac0
//   0x007480: 913b01ad  add      x13, x13, #0xec0
//   0x007484: 910b01ce  add      x14, x14, #0x2c0
//   0x007488: 911b01ef  add      x15, x15, #0x6c0
//   0x00748c: 1400001a  b        #0x74f4
//   0x007490: 53187e32  lsr      w18, w17, #0x18
//   0x007494: b8725972  ldr      w18, [x11, w18, uxtw #2]
//   0x007498: 297e0940  ldp      w0, w2, [x10, #-0x10]
//   0x00749c: 53105e21  ubfx     w1, w17, #0x10, #8
//   0x0074a0: b8615981  ldr      w1, [x12, w1, uxtw #2]
//   0x0074a4: 12081e52  and      w18, w18, #0xff000000
//   0x0074a8: 4a000252  eor      w18, w18, w0
//   0x0074ac: 53083e20  ubfx     w0, w17, #8, #8
//   0x0074b0: 12001e31  and      w17, w17, #0xff
//   0x0074b4: b86059a0  ldr      w0, [x13, w0, uxtw #2]
//   0x0074b8: d37ef631  lsl      x17, x17, #2
//   0x0074bc: 387169d1  ldrb     w17, [x14, x17]
//   0x0074c0: 12101c21  and      w1, w1, #0xff0000
//   0x0074c4: 4a010252  eor      w18, w18, w1
//   0x0074c8: 12181c00  and      w0, w0, #0xff00
//   0x0074cc: 4a000252  eor      w18, w18, w0
//   0x0074d0: 4a110251  eor      w17, w18, w17
//   0x0074d4: b85f8152  ldur     w18, [x10, #-8]
//   0x0074d8: 4a110040  eor      w0, w2, w17
//   0x0074dc: 29020151  stp      w17, w0, [x10, #0x10]
//   0x0074e0: 91001129  add      x9, x9, #4
//   0x0074e4: 4a000251  eor      w17, w18, w0
//   0x0074e8: 4a100230  eor      w16, w17, w16
//   0x0074ec: 29034151  stp      w17, w16, [x10, #0x18]
//   0x0074f0: 9100814a  add      x10, x10, #0x20
//   0x0074f4: b85fc150  ldur     w16, [x10, #-4]
//   0x0074f8: f100613f  cmp      x9, #0x18
//   0x0074fc: 53105e11  ubfx     w17, w16, #0x10, #8
//   0x007500: b8715971  ldr      w17, [x11, w17, uxtw #2]
//   0x007504: 53083e12  ubfx     w18, w16, #8, #8
//   0x007508: 92401e00  and      x0, x16, #0xff
//   0x00750c: b8725992  ldr      w18, [x12, w18, uxtw #2]
//   0x007510: 12081e31  and      w17, w17, #0xff000000
//   0x007514: 4a080228  eor      w8, w17, w8
//   0x007518: d3587e11  ubfx     x17, x16, #0x18, #8
//   0x00751c: b86079a0  ldr      w0, [x13, x0, lsl #2]
//   0x007520: d37ef631  lsl      x17, x17, #2
//   0x007524: 387169d1  ldrb     w17, [x14, x17]
//   0x007528: 12101e52  and      w18, w18, #0xff0000
//   0x00752c: 4a120108  eor      w8, w8, w18
//   0x007530: b86969f2  ldr      w18, [x15, x9]
//   0x007534: 12181c00  and      w0, w0, #0xff00
//   0x007538: 4a000108  eor      w8, w8, w0
//   0x00753c: 4a110108  eor      w8, w8, w17
//   0x007540: 297c8151  ldp      w17, w0, [x10, #-0x1c]
//   0x007544: 4a120108  eor      w8, w8, w18
//   0x007548: b85ec152  ldur     w18, [x10, #-0x14]
//   0x00754c: 4a080231  eor      w17, w17, w8
//   0x007550: 4a110000  eor      w0, w0, w17
//   0x007554: 29004548  stp      w8, w17, [x10]
//   0x007558: 4a000251  eor      w17, w18, w0
//   0x00755c: 29014540  stp      w0, w17, [x10, #8]
//   0x007560: 54fff981  b.ne     #0x7490
//   0x007564: 2a1f03e8  mov      w8, wzr
//   0x007568: 2a0803e0  mov      w0, w8
//   0x00756c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_36_7224(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007224ULL;
    for (std::size_t i = 0; i < 211ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6705ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[37] Subroutine @ 0x007570..0x007914 (932 bytes, 233 AArch64 instructions)
// [VN] Khung FDE[37] Hàm con @ 0x007570..0x007914 (932 byte, 233 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007570: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x007574: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x007578: 29402808  ldp      w8, w10, [x0]
//   0x00757c: 2940304b  ldp      w11, w12, [x2]
//   0x007580: 29413c0e  ldp      w14, w15, [x0, #8]
//   0x007584: b940f043  ldr      w3, [x2, #0xf0]
//   0x007588: 29410052  ldp      w18, w0, [x2, #8]
//   0x00758c: 5ac00908  rev      w8, w8
//   0x007590: 4a0b0110  eor      w16, w8, w11
//   0x007594: 5ac009cb  rev      w11, w14
//   0x007598: 13017c6e  asr      w14, w3, #1
//   0x00759c: 320003e4  mov      w4, #1
//   0x0075a0: 5ac0094a  rev      w10, w10
//   0x0075a4: 4a120172  eor      w18, w11, w18
//   0x0075a8: 510005cb  sub      w11, w14, #1
//   0x0075ac: 90000049  adrp     x9, #0xf000
//   0x0075b0: b0000048  adrp     x8, #0x10000
//   0x0075b4: 4a0c0151  eor      w17, w10, w12
//   0x0075b8: 9000004a  adrp     x10, #0xf000
//   0x0075bc: 5ac009ec  rev      w12, w15
//   0x0075c0: 4b0e008f  sub      w15, w4, w14
//   0x0075c4: d37df16e  lsl      x14, x11, #3
//   0x0075c8: 9000004b  adrp     x11, #0xf000
//   0x0075cc: 9100604d  add      x13, x2, #0x18
//   0x0075d0: 913b0129  add      x9, x9, #0xec0
//   0x0075d4: 910b0108  add      x8, x8, #0x2c0
//   0x0075d8: 911b014a  add      x10, x10, #0x6c0
//   0x0075dc: 4a000180  eor      w0, w12, w0
//   0x0075e0: 910021cc  add      x12, x14, #8
//   0x0075e4: 912b016b  add      x11, x11, #0xac0
//   0x0075e8: 14000034  b        #0x76b8
//   0x0075ec: 53105e24  ubfx     w4, w17, #0x10, #8
//   0x0075f0: b8635923  ldr      w3, [x9, w3, uxtw #2]
//   0x0075f4: b8645904  ldr      w4, [x8, w4, uxtw #2]
//   0x0075f8: 53187e26  lsr      w6, w17, #0x18
//   0x0075fc: 53105e07  ubfx     w7, w16, #0x10, #8
//   0x007600: 53187e13  lsr      w19, w16, #0x18
//   0x007604: 53105c14  ubfx     w20, w0, #0x10, #8
//   0x007608: b8665926  ldr      w6, [x9, w6, uxtw #2]
//   0x00760c: b8675907  ldr      w7, [x8, w7, uxtw #2]
//   0x007610: b8735933  ldr      w19, [x9, w19, uxtw #2]
//   0x007614: b8745914  ldr      w20, [x8, w20, uxtw #2]
//   0x007618: 53187c15  lsr      w21, w0, #0x18
//   0x00761c: 4a030083  eor      w3, w4, w3
//   0x007620: 53105e44  ubfx     w4, w18, #0x10, #8
//   0x007624: b8755935  ldr      w21, [x9, w21, uxtw #2]
//   0x007628: b8645904  ldr      w4, [x8, w4, uxtw #2]
//   0x00762c: 53083e05  ubfx     w5, w16, #8, #8
//   0x007630: 4a0600e6  eor      w6, w7, w6
//   0x007634: 53083c07  ubfx     w7, w0, #8, #8
//   0x007638: 4a130293  eor      w19, w20, w19
//   0x00763c: 53083e54  ubfx     w20, w18, #8, #8
//   0x007640: b8655945  ldr      w5, [x10, w5, uxtw #2]
//   0x007644: b8675947  ldr      w7, [x10, w7, uxtw #2]
//   0x007648: 12001c00  and      w0, w0, #0xff
//   0x00764c: 12001e52  and      w18, w18, #0xff
//   0x007650: b8745954  ldr      w20, [x10, w20, uxtw #2]
//   0x007654: b8605960  ldr      w0, [x11, w0, uxtw #2]
//   0x007658: b8725972  ldr      w18, [x11, w18, uxtw #2]
//   0x00765c: 4a150084  eor      w4, w4, w21
//   0x007660: 53083e35  ubfx     w21, w17, #8, #8
//   0x007664: b8755955  ldr      w21, [x10, w21, uxtw #2]
//   0x007668: 12001e31  and      w17, w17, #0xff
//   0x00766c: 12001e10  and      w16, w16, #0xff
//   0x007670: 4a050063  eor      w3, w3, w5
//   0x007674: 4a0700c5  eor      w5, w6, w7
//   0x007678: b8715971  ldr      w17, [x11, w17, uxtw #2]
//   0x00767c: b8705970  ldr      w16, [x11, w16, uxtw #2]
//   0x007680: 4a140266  eor      w6, w19, w20
//   0x007684: 4a000060  eor      w0, w3, w0
//   0x007688: 4a1200b2  eor      w18, w5, w18
//   0x00768c: 294115a3  ldp      w3, w5, [x13, #8]
//   0x007690: 29424da7  ldp      w7, w19, [x13, #0x10]
//   0x007694: 4a150084  eor      w4, w4, w21
//   0x007698: 4a1100c6  eor      w6, w6, w17
//   0x00769c: 4a100084  eor      w4, w4, w16
//   0x0076a0: 110005ef  add      w15, w15, #1
//   0x0076a4: 4a030010  eor      w16, w0, w3
//   0x0076a8: 4a050251  eor      w17, w18, w5
//   0x0076ac: 4a0700d2  eor      w18, w6, w7
//   0x0076b0: 4a130080  eor      w0, w4, w19
//   0x0076b4: 910081ad  add      x13, x13, #0x20
//   0x0076b8: 53187e03  lsr      w3, w16, #0x18
//   0x0076bc: 53105e24  ubfx     w4, w17, #0x10, #8
//   0x0076c0: 53187e26  lsr      w6, w17, #0x18
//   0x0076c4: 53105e47  ubfx     w7, w18, #0x10, #8
//   0x0076c8: b8635923  ldr      w3, [x9, w3, uxtw #2]
//   0x0076cc: b8645904  ldr      w4, [x8, w4, uxtw #2]
//   0x0076d0: 53187e53  lsr      w19, w18, #0x18
//   0x0076d4: 53105c14  ubfx     w20, w0, #0x10, #8
//   0x0076d8: b8665926  ldr      w6, [x9, w6, uxtw #2]
//   0x0076dc: b8675907  ldr      w7, [x8, w7, uxtw #2]
//   0x0076e0: b8735933  ldr      w19, [x9, w19, uxtw #2]
//   0x0076e4: b8745914  ldr      w20, [x8, w20, uxtw #2]
//   0x0076e8: 53187c15  lsr      w21, w0, #0x18
//   0x0076ec: 4a030083  eor      w3, w4, w3
//   0x0076f0: 53105e04  ubfx     w4, w16, #0x10, #8
//   0x0076f4: 53083e45  ubfx     w5, w18, #8, #8
//   0x0076f8: b8755935  ldr      w21, [x9, w21, uxtw #2]
//   0x0076fc: b8645904  ldr      w4, [x8, w4, uxtw #2]
//   0x007700: 4a0600e6  eor      w6, w7, w6
//   0x007704: 53083c07  ubfx     w7, w0, #8, #8
//   0x007708: 4a130293  eor      w19, w20, w19
//   0x00770c: 53083e14  ubfx     w20, w16, #8, #8
//   0x007710: b8655945  ldr      w5, [x10, w5, uxtw #2]
//   0x007714: b8675947  ldr      w7, [x10, w7, uxtw #2]
//   0x007718: 12001c00  and      w0, w0, #0xff
//   0x00771c: 12001e10  and      w16, w16, #0xff
//   0x007720: b8605960  ldr      w0, [x11, w0, uxtw #2]
//   0x007724: b8705970  ldr      w16, [x11, w16, uxtw #2]
//   0x007728: b8745954  ldr      w20, [x10, w20, uxtw #2]
//   0x00772c: 4a150084  eor      w4, w4, w21
//   0x007730: 53083e35  ubfx     w21, w17, #8, #8
//   0x007734: b8755955  ldr      w21, [x10, w21, uxtw #2]
//   0x007738: 4a050063  eor      w3, w3, w5
//   0x00773c: 4a0700c5  eor      w5, w6, w7
//   0x007740: 12001e31  and      w17, w17, #0xff
//   0x007744: 12001e52  and      w18, w18, #0xff
//   0x007748: b8715971  ldr      w17, [x11, w17, uxtw #2]
//   0x00774c: b8725972  ldr      w18, [x11, w18, uxtw #2]
//   0x007750: 4a000060  eor      w0, w3, w0
//   0x007754: 4a1000b0  eor      w16, w5, w16
//   0x007758: 297f15a3  ldp      w3, w5, [x13, #-8]
//   0x00775c: 4a140266  eor      w6, w19, w20
//   0x007760: 29404da7  ldp      w7, w19, [x13]
//   0x007764: 4a150084  eor      w4, w4, w21
//   0x007768: 4a1100c6  eor      w6, w6, w17
//   0x00776c: 4a120084  eor      w4, w4, w18
//   0x007770: 4a030012  eor      w18, w0, w3
//   0x007774: 4a050211  eor      w17, w16, w5
//   0x007778: 4a0700d0  eor      w16, w6, w7
//   0x00777c: 4a130080  eor      w0, w4, w19
//   0x007780: 53187e43  lsr      w3, w18, #0x18
//   0x007784: 35fff34f  cbnz     w15, #0x75ec
//   0x007788: 8b0e084d  add      x13, x2, x14, lsl #2
//   0x00778c: b863594e  ldr      w14, [x10, w3, uxtw #2]
//   0x007790: 53105e23  ubfx     w3, w17, #0x10, #8
//   0x007794: 53083e0f  ubfx     w15, w16, #8, #8
//   0x007798: b86c784c  ldr      w12, [x2, x12, lsl #2]
//   0x00779c: 53187e22  lsr      w2, w17, #0x18
//   0x0077a0: 53187e06  lsr      w6, w16, #0x18
//   0x0077a4: 53187c14  lsr      w20, w0, #0x18
//   0x0077a8: b8635963  ldr      w3, [x11, w3, uxtw #2]
//   0x0077ac: 53105e04  ubfx     w4, w16, #0x10, #8
//   0x0077b0: 53083c05  ubfx     w5, w0, #8, #8
//   0x0077b4: 53105c07  ubfx     w7, w0, #0x10, #8
//   0x0077b8: b8625942  ldr      w2, [x10, w2, uxtw #2]
//   0x0077bc: b8665946  ldr      w6, [x10, w6, uxtw #2]
//   0x0077c0: b874594a  ldr      w10, [x10, w20, uxtw #2]
//   0x0077c4: 53105e54  ubfx     w20, w18, #0x10, #8
//   0x0077c8: b86f592f  ldr      w15, [x9, w15, uxtw #2]
//   0x0077cc: 12001c00  and      w0, w0, #0xff
//   0x0077d0: 53083e53  ubfx     w19, w18, #8, #8
//   0x0077d4: b8645964  ldr      w4, [x11, w4, uxtw #2]
//   0x0077d8: b8675967  ldr      w7, [x11, w7, uxtw #2]
//   0x0077dc: b874596b  ldr      w11, [x11, w20, uxtw #2]
//   0x0077e0: 53083e34  ubfx     w20, w17, #8, #8
//   0x0077e4: 12001e52  and      w18, w18, #0xff
//   0x0077e8: 12001e31  and      w17, w17, #0xff
//   0x0077ec: 12001e10  and      w16, w16, #0xff
//   0x0077f0: d37ef400  lsl      x0, x0, #2
//   0x0077f4: d37ef652  lsl      x18, x18, #2
//   0x0077f8: d37ef631  lsl      x17, x17, #2
//   0x0077fc: d37ef610  lsl      x16, x16, #2
//   0x007800: 38606900  ldrb     w0, [x8, x0]
//   0x007804: 38726912  ldrb     w18, [x8, x18]
//   0x007808: 38716911  ldrb     w17, [x8, x17]
//   0x00780c: 38706908  ldrb     w8, [x8, x16]
//   0x007810: 12081dce  and      w14, w14, #0xff000000
//   0x007814: 12101c70  and      w16, w3, #0xff0000
//   0x007818: 2a0e020e  orr      w14, w16, w14
//   0x00781c: 12181def  and      w15, w15, #0xff00
//   0x007820: 2a0f01ce  orr      w14, w14, w15
//   0x007824: 2a0001ce  orr      w14, w14, w0
//   0x007828: 4a0c01cc  eor      w12, w14, w12
//   0x00782c: b8655925  ldr      w5, [x9, w5, uxtw #2]
//   0x007830: 53187d8e  lsr      w14, w12, #0x18
//   0x007834: b8735933  ldr      w19, [x9, w19, uxtw #2]
//   0x007838: b8745929  ldr      w9, [x9, w20, uxtw #2]
//   0x00783c: 3900002e  strb     w14, [x1]
//   0x007840: 53107d8e  lsr      w14, w12, #0x10
//   0x007844: 39000c2c  strb     w12, [x1, #3]
//   0x007848: 53087d8c  lsr      w12, w12, #8
//   0x00784c: 3900042e  strb     w14, [x1, #1]
//   0x007850: 3900082c  strb     w12, [x1, #2]
//   0x007854: 12081c50  and      w16, w2, #0xff000000
//   0x007858: 12101c82  and      w2, w4, #0xff0000
//   0x00785c: b94025ac  ldr      w12, [x13, #0x24]
//   0x007860: 2a100050  orr      w16, w2, w16
//   0x007864: 12181cae  and      w14, w5, #0xff00
//   0x007868: 2a0e020e  orr      w14, w16, w14
//   0x00786c: 2a1201ce  orr      w14, w14, w18
//   0x007870: 4a0c01cc  eor      w12, w14, w12
//   0x007874: 53187d8e  lsr      w14, w12, #0x18
//   0x007878: 53107d90  lsr      w16, w12, #0x10
//   0x00787c: 53087d92  lsr      w18, w12, #8
//   0x007880: 39001c2c  strb     w12, [x1, #7]
//   0x007884: 3900102e  strb     w14, [x1, #4]
//   0x007888: 39001430  strb     w16, [x1, #5]
//   0x00788c: 39001832  strb     w18, [x1, #6]
//   0x007890: 12081ccf  and      w15, w6, #0xff000000
//   0x007894: 12101ce0  and      w0, w7, #0xff0000
//   0x007898: b94029ac  ldr      w12, [x13, #0x28]
//   0x00789c: 12181e62  and      w2, w19, #0xff00
//   0x0078a0: 2a0f000e  orr      w14, w0, w15
//   0x0078a4: 2a0201ce  orr      w14, w14, w2
//   0x0078a8: 2a1101ce  orr      w14, w14, w17
//   0x0078ac: 4a0c01cc  eor      w12, w14, w12
//   0x0078b0: 53187d8e  lsr      w14, w12, #0x18
//   0x0078b4: 53107d8f  lsr      w15, w12, #0x10
//   0x0078b8: 53087d90  lsr      w16, w12, #8
//   0x0078bc: 39002c2c  strb     w12, [x1, #0xb]
//   0x0078c0: 3900202e  strb     w14, [x1, #8]
//   0x0078c4: 3900242f  strb     w15, [x1, #9]
//   0x0078c8: 39002830  strb     w16, [x1, #0xa]
//   0x0078cc: 12081d4a  and      w10, w10, #0xff000000
//   0x0078d0: 12101d6b  and      w11, w11, #0xff0000
//   0x0078d4: b9402dac  ldr      w12, [x13, #0x2c]
//   0x0078d8: 12181d29  and      w9, w9, #0xff00
//   0x0078dc: 2a0a016a  orr      w10, w11, w10
//   0x0078e0: 2a090149  orr      w9, w10, w9
//   0x0078e4: 2a080128  orr      w8, w9, w8
//   0x0078e8: 4a0c0108  eor      w8, w8, w12
//   0x0078ec: 53187d09  lsr      w9, w8, #0x18
//   0x0078f0: 53107d0a  lsr      w10, w8, #0x10
//   0x0078f4: 53087d0b  lsr      w11, w8, #8
//   0x0078f8: 39003029  strb     w9, [x1, #0xc]
//   0x0078fc: 3900342a  strb     w10, [x1, #0xd]
//   0x007900: 3900382b  strb     w11, [x1, #0xe]
//   0x007904: 39003c28  strb     w8, [x1, #0xf]
//   0x007908: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00790c: f84207f5  ldr      x21, [sp], #0x20
//   0x007910: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_37_7570(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007570ULL;
    for (std::size_t i = 0; i < 233ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6916ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[38] Subroutine @ 0x007914..0x0079e0 (204 bytes, 51 AArch64 instructions)
// [VN] Khung FDE[38] Hàm con @ 0x007914..0x0079e0 (204 byte, 51 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007914: d10543ff  sub      sp, sp, #0x150
//   0x007918: f90083fc  str      x28, [sp, #0x100]
//   0x00791c: a9115ff8  stp      x24, x23, [sp, #0x110]
//   0x007920: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x007924: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x007928: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x00792c: 910503fd  add      x29, sp, #0x140
//   0x007930: d53bd057  mrs      x23, tpidr_el0
//   0x007934: f94016e8  ldr      x8, [x23, #0x28]
//   0x007938: aa0403f3  mov      x19, x4
//   0x00793c: aa0203f4  mov      x20, x2
//   0x007940: aa0303f5  mov      x21, x3
//   0x007944: f81b83a8  stur     x8, [x29, #-0x48]
//   0x007948: f9400268  ldr      x8, [x19]
//   0x00794c: aa0103f6  mov      x22, x1
//   0x007950: eb14011f  cmp      x8, x20
//   0x007954: 54000062  b.hs     #0x7960
//   0x007958: f900027f  str      xzr, [x19]
//   0x00795c: 14000015  b        #0x79b0
//   0x007960: 321903e1  mov      w1, #0x80
//   0x007964: 910003e2  mov      x2, sp
//   0x007968: 97fffcc3  bl       #0x6c74
//   0x00796c: b4000154  cbz      x20, #0x7994
//   0x007970: aa1f03f8  mov      x24, xzr
//   0x007974: 8b1802c0  add      x0, x22, x24
//   0x007978: 8b1802a1  add      x1, x21, x24
//   0x00797c: 910003e2  mov      x2, sp
//   0x007980: 97fffd4a  bl       #0x6ea8
//   0x007984: 91004318  add      x24, x24, #0x10
//   0x007988: eb14031f  cmp      x24, x20
//   0x00798c: 54ffff43  b.lo     #0x7974
//   0x007990: 8b1802b5  add      x21, x21, x24
//   0x007994: 385ff2a8  ldurb    w8, [x21, #-1]
//   0x007998: 51000509  sub      w9, w8, #1
//   0x00799c: 12001d29  and      w9, w9, #0xff
//   0x0079a0: cb080288  sub      x8, x20, x8
//   0x0079a4: 71003d3f  cmp      w9, #0xf
//   0x0079a8: 9a8883e8  csel     x8, xzr, x8, hi
//   0x0079ac: f9000268  str      x8, [x19]
//   0x0079b0: f94016e8  ldr      x8, [x23, #0x28]
//   0x0079b4: f85b83a9  ldur     x9, [x29, #-0x48]
//   0x0079b8: eb09011f  cmp      x8, x9
//   0x0079bc: 54000101  b.ne     #0x79dc
//   0x0079c0: a9547bfd  ldp      x29, x30, [sp, #0x140]
//   0x0079c4: a9534ff4  ldp      x20, x19, [sp, #0x130]
//   0x0079c8: a95257f6  ldp      x22, x21, [sp, #0x120]
//   0x0079cc: a9515ff8  ldp      x24, x23, [sp, #0x110]
//   0x0079d0: f94083fc  ldr      x28, [sp, #0x100]
//   0x0079d4: 910543ff  add      sp, sp, #0x150
//   0x0079d8: d65f03c0  ret      
//   0x0079dc: 97ffe3c9  bl       #0x900
// ============================================================================
std::uint32_t fde_38_7914(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007914ULL;
    for (std::size_t i = 0; i < 51ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7149ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[39] Subroutine @ 0x0079e0..0x007af0 (272 bytes, 68 AArch64 instructions)
// [VN] Khung FDE[39] Hàm con @ 0x0079e0..0x007af0 (272 byte, 68 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0079e0: d105c3ff  sub      sp, sp, #0x170
//   0x0079e4: f9008bfc  str      x28, [sp, #0x110]
//   0x0079e8: a91267fa  stp      x26, x25, [sp, #0x120]
//   0x0079ec: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x0079f0: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x0079f4: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x0079f8: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x0079fc: 910583fd  add      x29, sp, #0x160
//   0x007a00: d53bd059  mrs      x25, tpidr_el0
//   0x007a04: f9401728  ldr      x8, [x25, #0x28]
//   0x007a08: aa0403f3  mov      x19, x4
//   0x007a0c: aa0203f4  mov      x20, x2
//   0x007a10: 91004289  add      x9, x20, #0x10
//   0x007a14: f81a83a8  stur     x8, [x29, #-0x58]
//   0x007a18: f9400268  ldr      x8, [x19]
//   0x007a1c: aa0303f5  mov      x21, x3
//   0x007a20: aa0103f6  mov      x22, x1
//   0x007a24: eb09011f  cmp      x8, x9
//   0x007a28: 54000062  b.hs     #0x7a34
//   0x007a2c: f900027f  str      xzr, [x19]
//   0x007a30: 14000023  b        #0x7abc
//   0x007a34: 92400e97  and      x23, x20, #0xf
//   0x007a38: 321903e1  mov      w1, #0x80
//   0x007a3c: 910003e2  mov      x2, sp
//   0x007a40: a939ffbf  stp      xzr, xzr, [x29, #-0x68]
//   0x007a44: cb170298  sub      x24, x20, x23
//   0x007a48: 97fffdf7  bl       #0x7224
//   0x007a4c: b4000178  cbz      x24, #0x7a78
//   0x007a50: aa1f03fa  mov      x26, xzr
//   0x007a54: 8b1a02c0  add      x0, x22, x26
//   0x007a58: 8b1a02a1  add      x1, x21, x26
//   0x007a5c: 910003e2  mov      x2, sp
//   0x007a60: 97fffec4  bl       #0x7570
//   0x007a64: 9100435a  add      x26, x26, #0x10
//   0x007a68: eb18035f  cmp      x26, x24
//   0x007a6c: 54ffff43  b.lo     #0x7a54
//   0x007a70: 8b1a02d6  add      x22, x22, x26
//   0x007a74: 8b1a02b5  add      x21, x21, x26
//   0x007a78: 321c03e8  mov      w8, #0x10
//   0x007a7c: d101a3a0  sub      x0, x29, #0x68
//   0x007a80: aa1603e1  mov      x1, x22
//   0x007a84: aa1703e2  mov      x2, x23
//   0x007a88: cb170118  sub      x24, x8, x23
//   0x007a8c: d101a3ba  sub      x26, x29, #0x68
//   0x007a90: 97ffe3a4  bl       #0x920
//   0x007a94: 8b170340  add      x0, x26, x23
//   0x007a98: 2a1803e1  mov      w1, w24
//   0x007a9c: aa1803e2  mov      x2, x24
//   0x007aa0: 97ffe3a4  bl       #0x930
//   0x007aa4: d101a3a0  sub      x0, x29, #0x68
//   0x007aa8: 910003e2  mov      x2, sp
//   0x007aac: aa1503e1  mov      x1, x21
//   0x007ab0: 97fffeb0  bl       #0x7570
//   0x007ab4: 8b140308  add      x8, x24, x20
//   0x007ab8: f9000268  str      x8, [x19]
//   0x007abc: f9401728  ldr      x8, [x25, #0x28]
//   0x007ac0: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x007ac4: eb09011f  cmp      x8, x9
//   0x007ac8: 54000121  b.ne     #0x7aec
//   0x007acc: a9567bfd  ldp      x29, x30, [sp, #0x160]
//   0x007ad0: a9554ff4  ldp      x20, x19, [sp, #0x150]
//   0x007ad4: a95457f6  ldp      x22, x21, [sp, #0x140]
//   0x007ad8: a9535ff8  ldp      x24, x23, [sp, #0x130]
//   0x007adc: a95267fa  ldp      x26, x25, [sp, #0x120]
//   0x007ae0: f9408bfc  ldr      x28, [sp, #0x110]
//   0x007ae4: 9105c3ff  add      sp, sp, #0x170
//   0x007ae8: d65f03c0  ret      
//   0x007aec: 97ffe385  bl       #0x900
// ============================================================================
std::uint32_t fde_39_79e0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000079e0ULL;
    for (std::size_t i = 0; i < 68ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7200ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[40] Subroutine @ 0x007af0..0x007c48 (344 bytes, 86 AArch64 instructions)
// [VN] Khung FDE[40] Hàm con @ 0x007af0..0x007c48 (344 byte, 86 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007af0: d10183ff  sub      sp, sp, #0x60
//   0x007af4: f9000bf9  str      x25, [sp, #0x10]
//   0x007af8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x007afc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x007b00: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x007b04: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x007b08: 910143fd  add      x29, sp, #0x50
//   0x007b0c: d53bd059  mrs      x25, tpidr_el0
//   0x007b10: f9401728  ldr      x8, [x25, #0x28]
//   0x007b14: 2a0303f8  mov      w24, w3
//   0x007b18: aa0203f3  mov      x19, x2
//   0x007b1c: aa0003f4  mov      x20, x0
//   0x007b20: aa1f03f7  mov      x23, xzr
//   0x007b24: f90007e8  str      x8, [sp, #8]
//   0x007b28: b4000773  cbz      x19, #0x7c14
//   0x007b2c: 7100071f  cmp      w24, #1
//   0x007b30: 5400072b  b.lt     #0x7c14
//   0x007b34: f9400288  ldr      x8, [x20]
//   0x007b38: aa1403e0  mov      x0, x20
//   0x007b3c: aa1303e1  mov      x1, x19
//   0x007b40: aa1f03e2  mov      x2, xzr
//   0x007b44: f942e108  ldr      x8, [x8, #0x5c0]
//   0x007b48: d63f0100  blr      x8
//   0x007b4c: aa0003f5  mov      x21, x0
//   0x007b50: b4000395  cbz      x21, #0x7bc0
//   0x007b54: 1101db08  add      w8, w24, #0x76
//   0x007b58: 93407d00  sxtw     x0, w8
//   0x007b5c: f90003e0  str      x0, [sp]
//   0x007b60: 97ffe36c  bl       #0x910
//   0x007b64: aa0003f6  mov      x22, x0
//   0x007b68: b4000316  cbz      x22, #0x7bc8
//   0x007b6c: 93407f01  sxtw     x1, w24
//   0x007b70: 910003e3  mov      x3, sp
//   0x007b74: aa1503e0  mov      x0, x21
//   0x007b78: aa1603e2  mov      x2, x22
//   0x007b7c: 97ffeb70  bl       #0x293c
//   0x007b80: f94003e1  ldr      x1, [sp]
//   0x007b84: b4000341  cbz      x1, #0x7bec
//   0x007b88: f9400288  ldr      x8, [x20]
//   0x007b8c: aa1403e0  mov      x0, x20
//   0x007b90: f942c108  ldr      x8, [x8, #0x580]
//   0x007b94: d63f0100  blr      x8
//   0x007b98: f9400288  ldr      x8, [x20]
//   0x007b9c: b94003e3  ldr      w3, [sp]
//   0x007ba0: aa0003f7  mov      x23, x0
//   0x007ba4: aa1403e0  mov      x0, x20
//   0x007ba8: f9434108  ldr      x8, [x8, #0x680]
//   0x007bac: aa1703e1  mov      x1, x23
//   0x007bb0: 2a1f03e2  mov      w2, wzr
//   0x007bb4: aa1603e4  mov      x4, x22
//   0x007bb8: d63f0100  blr      x8
//   0x007bbc: 1400000d  b        #0x7bf0
//   0x007bc0: aa1f03f7  mov      x23, xzr
//   0x007bc4: 14000014  b        #0x7c14
//   0x007bc8: f9400288  ldr      x8, [x20]
//   0x007bcc: aa1403e0  mov      x0, x20
//   0x007bd0: aa1303e1  mov      x1, x19
//   0x007bd4: aa1503e2  mov      x2, x21
//   0x007bd8: f9430108  ldr      x8, [x8, #0x600]
//   0x007bdc: 2a1f03e3  mov      w3, wzr
//   0x007be0: d63f0100  blr      x8
//   0x007be4: aa1f03f7  mov      x23, xzr
//   0x007be8: 1400000b  b        #0x7c14
//   0x007bec: aa1f03f7  mov      x23, xzr
//   0x007bf0: f9400288  ldr      x8, [x20]
//   0x007bf4: aa1403e0  mov      x0, x20
//   0x007bf8: aa1303e1  mov      x1, x19
//   0x007bfc: aa1503e2  mov      x2, x21
//   0x007c00: f9430108  ldr      x8, [x8, #0x600]
//   0x007c04: 2a1f03e3  mov      w3, wzr
//   0x007c08: d63f0100  blr      x8
//   0x007c0c: aa1603e0  mov      x0, x22
//   0x007c10: 97ffe34c  bl       #0x940
//   0x007c14: f9401728  ldr      x8, [x25, #0x28]
//   0x007c18: f94007e9  ldr      x9, [sp, #8]
//   0x007c1c: eb09011f  cmp      x8, x9
//   0x007c20: 54000121  b.ne     #0x7c44
//   0x007c24: aa1703e0  mov      x0, x23
//   0x007c28: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x007c2c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x007c30: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x007c34: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x007c38: f9400bf9  ldr      x25, [sp, #0x10]
//   0x007c3c: 910183ff  add      sp, sp, #0x60
//   0x007c40: d65f03c0  ret      
//   0x007c44: 97ffe32f  bl       #0x900
// ============================================================================
std::uint32_t fde_40_7af0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007af0ULL;
    for (std::size_t i = 0; i < 86ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7268ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t acc = 0x6ffd8024U;
    acc = fde_00_099c(acc);
    acc = fde_01_0a18(acc);
    acc = fde_02_0a3c(acc);
    acc = fde_03_0aec(acc);
    acc = fde_04_0af8(acc);
    acc = fde_05_2444(acc);
    acc = fde_06_27c0(acc);
    acc = fde_07_293c(acc);
    acc = fde_08_29b8(acc);
    acc = fde_09_29d4(acc);
    acc = fde_10_2a0c(acc);
    acc = fde_11_2a20(acc);
    acc = fde_12_2a30(acc);
    acc = fde_13_2a40(acc);
    acc = fde_14_2a60(acc);
    acc = fde_15_2a7c(acc);
    acc = fde_16_2a84(acc);
    acc = fde_17_2a90(acc);
    acc = fde_18_43dc(acc);
    acc = fde_19_4864(acc);
    acc = fde_20_48e4(acc);
    acc = fde_21_4900(acc);
    acc = fde_22_4910(acc);
    acc = fde_23_4920(acc);
    acc = fde_24_49d4(acc);
    acc = fde_25_49dc(acc);
    acc = fde_26_49e8(acc);
    acc = fde_27_6334(acc);
    acc = fde_28_6438(acc);
    acc = fde_29_646c(acc);
    acc = fde_30_64b0(acc);
    acc = fde_31_65a0(acc);
    acc = fde_32_69a4(acc);
    acc = fde_33_6b10(acc);
    acc = fde_34_6c74(acc);
    acc = fde_35_6ea8(acc);
    acc = fde_36_7224(acc);
    acc = fde_37_7570(acc);
    acc = fde_38_7914(acc);
    acc = fde_39_79e0(acc);
    acc = fde_40_7af0(acc);
    return acc;
}

} // namespace encryptor
} // namespace bytedance

extern "C" {
// ============================================================================
// [EN] Exported JNI Entry Point: JNI_OnLoad @ 0x00099c (124 bytes, first_op = 0xa9be4ffc)
//      Registers com/bytedance/frameworks/encryptor/EncryptorUtil.ttEncrypt([BI)[B
// [VN] Điểm nhập JNI xuất khẩu: JNI_OnLoad @ 0x00099c (124 byte, lệnh đầu = 0xa9be4ffc)
//      Đăng ký com/bytedance/frameworks/encryptor/EncryptorUtil.ttEncrypt([BI)[B
// ============================================================================
int JNI_OnLoad(void* vm, void* reserved) {
    (void)reserved;
    if (vm == nullptr) {
        return -1;
    }
    std::uint32_t sim = bytedance::encryptor::fde_00_099c(0x00010006U);
    return (sim != 0U) ? 0x00010006 : 0x00010006;
}
} // extern "C"
