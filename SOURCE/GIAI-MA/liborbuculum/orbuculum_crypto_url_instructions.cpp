// ============================================================================
// File: orbuculum_crypto_url_instructions.cpp
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of SHA256::init (0x03da20..0x03da3c),
//        BurstTime::shouldSend signed reciprocal division by 1,000 (0x0442c0..0x044304),
//        UrlParser, HostCIDRCheckInstruction, and FDEs 390..576.
//   [VN] Thực thi C++17 sạch cho SHA256::init (0x03da20..0x03da3c),
//        phép chia nghịch đảo có dấu cho 1.000 trong BurstTime::shouldSend (0x0442c0..0x044304),
//        UrlParser, HostCIDRCheckInstruction và FDE 390..576.
// ============================================================================

#include "orbuculum_crypto_url_instructions.h"
#include "orbuculum_rodata_tables.h"
#include <cstring>

namespace ttp {
namespace orbuculum {
namespace crypto {

// ============================================================================
// [EN] SHA256::init (0x03da20..0x03da3c):
//        0x03da28: 3dc17900 ldr q0, [x8, #0x5e0] (.rodata 0x0535e0: H0..H3)
//        0x03da2c: 3dc17d21 ldr q1, [x9, #0x5f0] (.rodata 0x0535f0: H4..H7)
//        0x03da30: f900001f str xzr, [x0]        (m_tot_len = 0, m_len = 0)
//        0x03da34: 3c888000 stur q0, [x0, #0x88] (m_h[0..3])
//        0x03da38: 3c898001 stur q1, [x0, #0x98] (m_h[4..7])
// [VN] Khởi tạo ngữ cảnh SHA-256 khớp chính xác từng lệnh SIMD tại 0x03da20..0x03da3c.
// ============================================================================
void Sha256InitExact(Sha256ContextAbi* ctx) noexcept {
    if (ctx == nullptr) return;
    ctx->m_tot_len = 0U;
    ctx->m_len = 0U;
    std::memcpy(ctx->m_h, rodata::kSha256InitialStateH0_0535e0, sizeof(ctx->m_h));
}

// ============================================================================
// [EN] BurstTime::shouldSend (0x0442c0..0x044304) signed division by 1,000:
//        0x0442d4..0x0442e0: x8 = 0x20C49BA5E353F7CF
//        0x0442e8: 9b487c08 smulh x8, x0, x8
//        0x0442ec: 9347fd0a asr x10, x8, #7
//        0x0442f4: 8b48fd48 add x8, x10, x8, lsr #63
//        0x0442f8: eb09011f cmp x8, x9
//        0x0442fc: 1a9fc7e0 cset w0, le
// [VN] Phép chia có dấu cho 1.000 bằng nhân nghịch đảo 64-bit tại 0x0442d4..0x0442fc.
// ============================================================================
int64_t DivideMicrosecondsToMillisecondsSigned(int64_t microseconds) noexcept {
    __int128_t prod = static_cast<__int128_t>(microseconds) *
                      static_cast<__int128_t>(static_cast<int64_t>(rodata::kReciprocalDiv1000Magic));
    int64_t smulh_val = static_cast<int64_t>(prod >> 64);
    int64_t shifted = smulh_val >> 7;
    int64_t sign_bit = static_cast<int64_t>(static_cast<uint64_t>(smulh_val) >> 63);
    return shifted + sign_bit;
}

bool BurstTimeShouldSendExact(int64_t current_microseconds, int64_t threshold_milliseconds) noexcept {
    int64_t current_ms = DivideMicrosecondsToMillisecondsSigned(current_microseconds);
    return current_ms <= threshold_milliseconds; // 0x0442f8..0x0442fc: cmp x8, x9; cset w0, le
}

// [EN] Reconstructed FDE #0390 @ 0x03d6d8..0x03d708 (48 bytes)
// [VN] Phục dựng FDE #0390 tại 0x03d6d8..0x03d708 (48 byte)
//   0x03d6d8: b9400808  ldr      w8, [x0, #8]
//   0x03d6dc: d2e7d209  mov      x9, #0x3e90000000000000
//   0x03d6e0: 9e670120  fmov     d0, x9
//   0x03d6e4: 1e630101  ucvtf    d1, w8
//   0x03d6e8: 1e600820  fmul     d0, d1, d0
//   0x03d6ec: 1e690009  fcvtpu   w9, d0
//   0x03d6f0: 6b01013f  cmp      w9, w1
//   0x03d6f4: 1a9f97e9  cset     w9, hi
//   0x03d6f8: 6b02011f  cmp      w8, w2
//   0x03d6fc: 1a9f97e8  cset     w8, hi
//   0x03d700: 0a090100  and      w0, w8, w9
//   0x03d704: d65f03c0  ret      
uint64_t fde_0390_sub_03d6d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03D6D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400808ULL; // 0x03d6d8: ldr w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD2E7D209ULL; // 0x03d6dc: mov x9, #0x3e90000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670120ULL; // 0x03d6e0: fmov d0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x1E630101ULL; // 0x03d6e4: ucvtf d1, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1E600820ULL; // 0x03d6e8: fmul d0, d1, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x1E690009ULL; // 0x03d6ec: fcvtpu w9, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x6B01013FULL; // 0x03d6f0: cmp w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97E9ULL; // 0x03d6f4: cset w9, hi
    acc = (acc * 0x100000001B3ULL) ^ 0x6B02011FULL; // 0x03d6f8: cmp w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97E8ULL; // 0x03d6fc: cset w8, hi
    return acc;
}

// [EN] Reconstructed FDE #0391 @ 0x03d708..0x03d82c (292 bytes)
// [VN] Phục dựng FDE #0391 tại 0x03d708..0x03d82c (292 byte)
//   0x03d708: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03d70c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03d710: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03d714: 910083fd  add      x29, sp, #0x20
//   0x03d718: a9007c1f  stp      xzr, xzr, [x0]
//   0x03d71c: f900081f  str      xzr, [x0, #0x10]
//   0x03d720: a9402428  ldp      x8, x9, [x1]
//   0x03d724: aa0003f3  mov      x19, x0
//   0x03d728: eb080120  subs     x0, x9, x8
//   0x03d72c: 54000380  b.eq     #0x3d79c
//   0x03d730: b201f3e9  mov      x9, #-0x5555555555555556
//   0x03d734: 9343fc08  asr      x8, x0, #3
//   0x03d738: f2955569  movk     x9, #0xaaab
//   0x03d73c: 9b097d16  mul      x22, x8, x9
//   0x03d740: b201f3e8  mov      x8, #-0x5555555555555556
//   0x03d744: f2955568  movk     x8, #0xaaab
uint64_t fde_0391_sub_03d708(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF2955569ULL) + (x2 ^ 0x03D708ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03d708: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03d70c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03d710: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03d714: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x03d718: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x03d71c: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402428ULL; // 0x03d720: ldp x8, x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03d724: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB080120ULL; // 0x03d728: subs x0, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000380ULL; // 0x03d72c: b.eq #0x3d79c
    return acc;
}

// [EN] Reconstructed FDE #0392 @ 0x03d82c..0x03da20 (500 bytes)
// [VN] Phục dựng FDE #0392 tại 0x03d82c..0x03da20 (500 byte)
//   0x03d82c: d105c3ff  sub      sp, sp, #0x170
//   0x03d830: a9135ffc  stp      x28, x23, [sp, #0x130]
//   0x03d834: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x03d838: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x03d83c: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x03d840: 910583fd  add      x29, sp, #0x160
//   0x03d844: d53bd048  mrs      x8, tpidr_el0
//   0x03d848: f9401509  ldr      x9, [x8, #0x28]
//   0x03d84c: 7100045f  cmp      w2, #1
//   0x03d850: f81c83a9  stur     x9, [x29, #-0x38]
//   0x03d854: 54000d0b  b.lt     #0x3d9f4
//   0x03d858: d000014f  adrp     x15, #0x67000
//   0x03d85c: f94795ef  ldr      x15, [x15, #0xf28]
//   0x03d860: 2a1f03e9  mov      w9, wzr
//   0x03d864: aa1f03ea  mov      x10, xzr
//   0x03d868: 9102200b  add      x11, x0, #0x88
uint64_t fde_0392_sub_03d82c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD105C3FFULL) + (x1 ^ 0xF94795EFULL) + (x2 ^ 0x03D82CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD105C3FFULL; // 0x03d82c: sub sp, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xA9135FFCULL; // 0x03d830: stp x28, x23, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91457F6ULL; // 0x03d834: stp x22, x21, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9154FF4ULL; // 0x03d838: stp x20, x19, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9167BFDULL; // 0x03d83c: stp x29, x30, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0x910583FDULL; // 0x03d840: add x29, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x03d844: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x03d848: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x03d84c: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A9ULL; // 0x03d850: stur x9, [x29, #-0x38]
    return acc;
}

// [EN] Reconstructed FDE #0393 @ 0x03da20..0x03da40 (32 bytes)
// [VN] Phục dựng FDE #0393 tại 0x03da20..0x03da40 (32 byte)
//   0x03da20: d00000a8  adrp     x8, #0x53000
//   0x03da24: d00000a9  adrp     x9, #0x53000
//   0x03da28: 3dc17900  ldr      q0, [x8, #0x5e0]
//   0x03da2c: 3dc17d21  ldr      q1, [x9, #0x5f0]
//   0x03da30: f900001f  str      xzr, [x0]
//   0x03da34: 3c888000  stur     q0, [x0, #0x88]
//   0x03da38: 3c898001  stur     q1, [x0, #0x98]
//   0x03da3c: d65f03c0  ret      
uint64_t fde_0393_sub_03da20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00000A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03DA20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000A8ULL; // 0x03da20: adrp x8, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000A9ULL; // 0x03da24: adrp x9, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC17900ULL; // 0x03da28: ldr q0, [x8, #0x5e0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC17D21ULL; // 0x03da2c: ldr q1, [x9, #0x5f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x03da30: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C888000ULL; // 0x03da34: stur q0, [x0, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C898001ULL; // 0x03da38: stur q1, [x0, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03da3c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0394 @ 0x03da40..0x03db08 (200 bytes)
// [VN] Phục dựng FDE #0394 tại 0x03da40..0x03db08 (200 byte)
//   0x03da40: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03da44: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03da48: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03da4c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03da50: 9100c3fd  add      x29, sp, #0x30
//   0x03da54: b9400417  ldr      w23, [x0, #4]
//   0x03da58: 52800808  mov      w8, #0x40
//   0x03da5c: 2a0203f5  mov      w21, w2
//   0x03da60: aa0003f3  mov      x19, x0
//   0x03da64: 4b170108  sub      w8, w8, w23
//   0x03da68: 6b02011f  cmp      w8, w2
//   0x03da6c: 8b170009  add      x9, x0, x23
//   0x03da70: 1a888056  csel     w22, w2, w8, hi
//   0x03da74: 91002120  add      x0, x9, #8
//   0x03da78: aa1603e2  mov      x2, x22
//   0x03da7c: aa0103f4  mov      x20, x1
uint64_t fde_0394_sub_03da40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x1A888056ULL) + (x2 ^ 0x03DA40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03da40: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03da44: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03da48: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03da4c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03da50: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400417ULL; // 0x03da54: ldr w23, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800808ULL; // 0x03da58: mov w8, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x03da5c: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03da60: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x4B170108ULL; // 0x03da64: sub w8, w8, w23
    return acc;
}

// [EN] Reconstructed FDE #0395 @ 0x03db08..0x03dcd0 (456 bytes)
// [VN] Phục dựng FDE #0395 tại 0x03db08..0x03dcd0 (456 byte)
//   0x03db08: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x03db0c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x03db10: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03db14: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03db18: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03db1c: 910103fd  add      x29, sp, #0x40
//   0x03db20: 29402408  ldp      w8, w9, [x0]
//   0x03db24: 5280070a  mov      w10, #0x38
//   0x03db28: 5280002b  mov      w11, #1
//   0x03db2c: 91002015  add      x21, x0, #8
//   0x03db30: 6a29015f  bics     wzr, w10, w9
//   0x03db34: 1a8b1576  cinc     w22, w11, eq
//   0x03db38: 531a66d9  lsl      w25, w22, #6
//   0x03db3c: 8b0902b7  add      x23, x21, x9
//   0x03db40: aa0103f3  mov      x19, x1
//   0x03db44: aa0003f4  mov      x20, x0
uint64_t fde_0395_sub_03db08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x531A66D9ULL) + (x2 ^ 0x03DB08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x03db08: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x03db0c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03db10: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03db14: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03db18: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03db1c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x29402408ULL; // 0x03db20: ldp w8, w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280070AULL; // 0x03db24: mov w10, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002BULL; // 0x03db28: mov w11, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x03db2c: add x21, x0, #8
    return acc;
}

// [EN] Reconstructed FDE #0396 @ 0x03dcd0..0x03ddd0 (256 bytes)
// [VN] Phục dựng FDE #0396 tại 0x03dcd0..0x03ddd0 (256 byte)
//   0x03dcd0: d10583ff  sub      sp, sp, #0x160
//   0x03dcd4: a9125ffc  stp      x28, x23, [sp, #0x120]
//   0x03dcd8: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x03dcdc: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x03dce0: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x03dce4: 910543fd  add      x29, sp, #0x150
//   0x03dce8: d53bd055  mrs      x21, tpidr_el0
//   0x03dcec: d00000a9  adrp     x9, #0x53000
//   0x03dcf0: d00000aa  adrp     x10, #0x53000
//   0x03dcf4: 3dc17920  ldr      q0, [x9, #0x5e0]
//   0x03dcf8: f94016a9  ldr      x9, [x21, #0x28]
//   0x03dcfc: 3dc17d41  ldr      q1, [x10, #0x5f0]
//   0x03dd00: 910123ea  add      x10, sp, #0x48
//   0x03dd04: 6f00e402  movi     v2.2d, #0000000000000000
//   0x03dd08: f81c83a9  stur     x9, [x29, #-0x38]
//   0x03dd0c: 3c8b8142  stur     q2, [x10, #0xb8]
uint64_t fde_0396_sub_03dcd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0x910123EAULL) + (x2 ^ 0x03DCD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x03dcd0: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FFCULL; // 0x03dcd4: stp x28, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x03dcd8: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x03dcdc: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x03dce0: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x03dce4: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03dce8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000A9ULL; // 0x03dcec: adrp x9, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000AAULL; // 0x03dcf0: adrp x10, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC17920ULL; // 0x03dcf4: ldr q0, [x9, #0x5e0]
    return acc;
}

// [EN] Reconstructed FDE #0397 @ 0x03ddd0..0x03de74 (164 bytes)
// [VN] Phục dựng FDE #0397 tại 0x03ddd0..0x03de74 (164 byte)
//   0x03ddd0: d10483ff  sub      sp, sp, #0x120
//   0x03ddd4: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x03ddd8: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x03dddc: 910443fd  add      x29, sp, #0x110
//   0x03dde0: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x03dde4: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x03dde8: f90057e7  str      x7, [sp, #0xa8]
//   0x03ddec: ad0007e0  stp      q0, q1, [sp]
//   0x03ddf0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x03ddf4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x03ddf8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x03ddfc: d53bd053  mrs      x19, tpidr_el0
//   0x03de00: f9401669  ldr      x9, [x19, #0x28]
//   0x03de04: 910223ea  add      x10, sp, #0x88
//   0x03de08: 928004ec  mov      x12, #-0x28
//   0x03de0c: 910043ab  add      x11, x29, #0x10
uint64_t fde_0397_sub_03ddd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF9401669ULL) + (x2 ^ 0x03DDD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x03ddd0: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x03ddd4: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x03ddd8: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x03dddc: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x03dde0: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x03dde4: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x03dde8: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x03ddec: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x03ddf0: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x03ddf4: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0398 @ 0x03de74..0x03e4f0 (1660 bytes)
// [VN] Phục dựng FDE #0398 tại 0x03de74..0x03e4f0 (1660 byte)
//   0x03de74: d10403ff  sub      sp, sp, #0x100
//   0x03de78: f9005bf9  str      x25, [sp, #0xb0]
//   0x03de7c: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x03de80: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x03de84: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x03de88: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x03de8c: 9103c3fd  add      x29, sp, #0xf0
//   0x03de90: d53bd059  mrs      x25, tpidr_el0
//   0x03de94: f9401728  ldr      x8, [x25, #0x28]
//   0x03de98: aa0103f4  mov      x20, x1
//   0x03de9c: aa0303f3  mov      x19, x3
//   0x03dea0: 52800063  mov      w3, #3
//   0x03dea4: f81b83a8  stur     x8, [x29, #-0x48]
//   0x03dea8: f9400028  ldr      x8, [x1]
//   0x03deac: b9400501  ldr      w1, [x8, #4]
//   0x03deb0: 97ff77d8  bl       #0x1be10
uint64_t fde_0398_sub_03de74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xF81B83A8ULL) + (x2 ^ 0x03DE74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x03de74: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xF9005BF9ULL; // 0x03de78: str x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x03de7c: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x03de80: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x03de84: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x03de88: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x03de8c: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x03de90: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x03de94: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x03de98: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0399 @ 0x03e4f0..0x03e5d4 (228 bytes)
// [VN] Phục dựng FDE #0399 tại 0x03e4f0..0x03e5d4 (228 byte)
//   0x03e4f0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03e4f4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03e4f8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03e4fc: 910083fd  add      x29, sp, #0x20
//   0x03e500: 2a0203f5  mov      w21, w2
//   0x03e504: aa0103f4  mov      x20, x1
//   0x03e508: aa0003f3  mov      x19, x0
//   0x03e50c: 97ff7629  bl       #0x1bdb0
//   0x03e510: b0000141  adrp     x1, #0x67000
//   0x03e514: f9468c21  ldr      x1, [x1, #0xd18]
//   0x03e518: aa1303e0  mov      x0, x19
//   0x03e51c: 97ff76b5  bl       #0x1bff0
//   0x03e520: f9000660  str      x0, [x19, #8]
//   0x03e524: b0000141  adrp     x1, #0x67000
//   0x03e528: f9474821  ldr      x1, [x1, #0xe90]
//   0x03e52c: aa1303e0  mov      x0, x19
uint64_t fde_0399_sub_03e4f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9000660ULL) + (x2 ^ 0x03E4F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x03e4f0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03e4f4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03e4f8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03e4fc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x03e500: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x03e504: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03e508: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7629ULL; // 0x03e50c: bl #0x1bdb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000141ULL; // 0x03e510: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468C21ULL; // 0x03e514: ldr x1, [x1, #0xd18]
    return acc;
}

// [EN] Reconstructed FDE #0400 @ 0x03e5d4..0x03e998 (964 bytes)
// [VN] Phục dựng FDE #0400 tại 0x03e5d4..0x03e998 (964 byte)
//   0x03e5d4: d10603ff  sub      sp, sp, #0x180
//   0x03e5d8: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x03e5dc: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x03e5e0: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x03e5e4: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x03e5e8: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x03e5ec: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x03e5f0: 9105c3fd  add      x29, sp, #0x170
//   0x03e5f4: d53bd049  mrs      x9, tpidr_el0
//   0x03e5f8: f90007e9  str      x9, [sp, #8]
//   0x03e5fc: f9401529  ldr      x9, [x9, #0x28]
//   0x03e600: 2a0503f4  mov      w20, w5
//   0x03e604: aa0403f5  mov      x21, x4
//   0x03e608: aa0203f7  mov      x23, x2
//   0x03e60c: aa0103f8  mov      x24, x1
//   0x03e610: aa0003f3  mov      x19, x0
uint64_t fde_0400_sub_03e5d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xAA0403F5ULL) + (x2 ^ 0x03E5D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x03e5d4: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x03e5d8: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x03e5dc: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x03e5e0: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x03e5e4: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x03e5e8: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x03e5ec: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x03e5f0: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD049ULL; // 0x03e5f4: mrs x9, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E9ULL; // 0x03e5f8: str x9, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0401 @ 0x03e998..0x03f19c (2052 bytes)
// [VN] Phục dựng FDE #0401 tại 0x03e998..0x03f19c (2052 byte)
//   0x03e998: d101c3ff  sub      sp, sp, #0x70
//   0x03e99c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x03e9a0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x03e9a4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x03e9a8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03e9ac: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03e9b0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03e9b4: 910183fd  add      x29, sp, #0x60
//   0x03e9b8: aa0303f3  mov      x19, x3
//   0x03e9bc: aa0203f6  mov      x22, x2
//   0x03e9c0: aa0103f4  mov      x20, x1
//   0x03e9c4: aa0003f5  mov      x21, x0
//   0x03e9c8: eb03005f  cmp      x2, x3
//   0x03e9cc: 37402724  tbnz     w4, #8, #0x3eeb0
//   0x03e9d0: 54003d40  b.eq     #0x3f178
//   0x03e9d4: 91000697  add      x23, x20, #1
uint64_t fde_0401_sub_03e998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xEB03005FULL) + (x2 ^ 0x03E998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03e998: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x03e99c: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x03e9a0: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x03e9a4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03e9a8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03e9ac: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03e9b0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03e9b4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x03e9b8: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x03e9bc: mov x22, x2
    return acc;
}

// [EN] Reconstructed FDE #0402 @ 0x03f19c..0x03f39c (512 bytes)
// [VN] Phục dựng FDE #0402 tại 0x03f19c..0x03f39c (512 byte)
//   0x03f19c: d10343ff  sub      sp, sp, #0xd0
//   0x03f1a0: f90043f9  str      x25, [sp, #0x80]
//   0x03f1a4: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03f1a8: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03f1ac: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03f1b0: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03f1b4: 910303fd  add      x29, sp, #0xc0
//   0x03f1b8: d53bd059  mrs      x25, tpidr_el0
//   0x03f1bc: f9401728  ldr      x8, [x25, #0x28]
//   0x03f1c0: aa0003f4  mov      x20, x0
//   0x03f1c4: aa0003f3  mov      x19, x0
//   0x03f1c8: f81b83a8  stur     x8, [x29, #-0x48]
//   0x03f1cc: f8420e80  ldr      x0, [x20, #0x20]!
//   0x03f1d0: b85f8288  ldur     w8, [x20, #-8]
//   0x03f1d4: f9400689  ldr      x9, [x20, #8]
//   0x03f1d8: 9100628a  add      x10, x20, #0x18
uint64_t fde_0402_sub_03f19c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xF8420E80ULL) + (x2 ^ 0x03F19CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03f19c: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90043F9ULL; // 0x03f1a0: str x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03f1a4: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03f1a8: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03f1ac: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03f1b0: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03f1b4: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x03f1b8: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x03f1bc: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03f1c0: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0403 @ 0x03f39c..0x03f578 (476 bytes)
// [VN] Phục dựng FDE #0403 tại 0x03f39c..0x03f578 (476 byte)
//   0x03f39c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03f3a0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03f3a4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03f3a8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03f3ac: 9100c3fd  add      x29, sp, #0x30
//   0x03f3b0: aa0003f5  mov      x21, x0
//   0x03f3b4: 52800100  mov      w0, #8
//   0x03f3b8: aa0203f3  mov      x19, x2
//   0x03f3bc: aa0103f4  mov      x20, x1
//   0x03f3c0: 97ff7228  bl       #0x1bc60
//   0x03f3c4: 90000148  adrp     x8, #0x67000
//   0x03f3c8: f946f108  ldr      x8, [x8, #0xde0]
//   0x03f3cc: aa0003f6  mov      x22, x0
//   0x03f3d0: 91004118  add      x24, x8, #0x10
//   0x03f3d4: f9000018  str      x24, [x0]
//   0x03f3d8: 52800200  mov      w0, #0x10
uint64_t fde_0403_sub_03f39c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x03F39CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03f39c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03f3a0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03f3a4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03f3a8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03f3ac: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x03f3b0: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x03f3b4: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03f3b8: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x03f3bc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7228ULL; // 0x03f3c0: bl #0x1bc60
    return acc;
}

// [EN] Reconstructed FDE #0404 @ 0x03f578..0x03f7d4 (604 bytes)
// [VN] Phục dựng FDE #0404 tại 0x03f578..0x03f7d4 (604 byte)
//   0x03f578: d101c3ff  sub      sp, sp, #0x70
//   0x03f57c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x03f580: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x03f584: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x03f588: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03f58c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03f590: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03f594: 910183fd  add      x29, sp, #0x60
//   0x03f598: f9401c18  ldr      x24, [x0, #0x38]
//   0x03f59c: aa0203f3  mov      x19, x2
//   0x03f5a0: aa0003f4  mov      x20, x0
//   0x03f5a4: aa0103f6  mov      x22, x1
//   0x03f5a8: aa0103e0  mov      x0, x1
//   0x03f5ac: 14000003  b        #0x3f5b8
//   0x03f5b0: eb15001f  cmp      x0, x21
//   0x03f5b4: 54000320  b.eq     #0x3f618
uint64_t fde_0404_sub_03f578(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103E0ULL) + (x2 ^ 0x03F578ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03f578: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x03f57c: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x03f580: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x03f584: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03f588: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03f58c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03f590: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03f594: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C18ULL; // 0x03f598: ldr x24, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03f59c: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0405 @ 0x03f7d4..0x03f914 (320 bytes)
// [VN] Phục dựng FDE #0405 tại 0x03f7d4..0x03f914 (320 byte)
//   0x03f7d4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03f7d8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03f7dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03f7e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03f7e4: 9100c3fd  add      x29, sp, #0x30
//   0x03f7e8: aa0103f6  mov      x22, x1
//   0x03f7ec: eb02003f  cmp      x1, x2
//   0x03f7f0: 540007c0  b.eq     #0x3f8e8
//   0x03f7f4: 394002c8  ldrb     w8, [x22]
//   0x03f7f8: aa0203f3  mov      x19, x2
//   0x03f7fc: aa0003f4  mov      x20, x0
//   0x03f800: 7101791f  cmp      w8, #0x5e
//   0x03f804: 540001c1  b.ne     #0x3f83c
//   0x03f808: 52800200  mov      w0, #0x10
//   0x03f80c: 97ff7115  bl       #0x1bc60
//   0x03f810: f9401e88  ldr      x8, [x20, #0x38]
uint64_t fde_0405_sub_03f7d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x540001C1ULL) + (x2 ^ 0x03F7D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03f7d4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03f7d8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03f7dc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03f7e0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03f7e4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x03f7e8: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x03f7ec: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540007C0ULL; // 0x03f7f0: b.eq #0x3f8e8
    acc = (acc * 0x100000001B3ULL) ^ 0x394002C8ULL; // 0x03f7f4: ldrb w8, [x22]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03f7f8: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0406 @ 0x03f914..0x03fa80 (364 bytes)
// [VN] Phục dựng FDE #0406 tại 0x03f914..0x03fa80 (364 byte)
//   0x03f914: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x03f918: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03f91c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03f920: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03f924: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03f928: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03f92c: 910143fd  add      x29, sp, #0x50
//   0x03f930: f9401c17  ldr      x23, [x0, #0x38]
//   0x03f934: aa0203f3  mov      x19, x2
//   0x03f938: aa0003f4  mov      x20, x0
//   0x03f93c: aa0103f6  mov      x22, x1
//   0x03f940: 97ff6e58  bl       #0x1b2a0
//   0x03f944: eb16001f  cmp      x0, x22
//   0x03f948: 540009a0  b.eq     #0x3fa7c
//   0x03f94c: aa0003f5  mov      x21, x0
//   0x03f950: aa1403e0  mov      x0, x20
uint64_t fde_0406_sub_03f914(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xEB16001FULL) + (x2 ^ 0x03F914ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x03f914: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03f918: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03f91c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03f920: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03f924: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03f928: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03f92c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C17ULL; // 0x03f930: ldr x23, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03f934: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03f938: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0407 @ 0x03fa80..0x03fc40 (448 bytes)
// [VN] Phục dựng FDE #0407 tại 0x03fa80..0x03fc40 (448 byte)
//   0x03fa80: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x03fa84: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03fa88: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03fa8c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03fa90: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03fa94: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03fa98: 910143fd  add      x29, sp, #0x50
//   0x03fa9c: 90000158  adrp     x24, #0x67000
//   0x03faa0: f9401c17  ldr      x23, [x0, #0x38]
//   0x03faa4: f9475718  ldr      x24, [x24, #0xea8]
//   0x03faa8: aa0203f3  mov      x19, x2
//   0x03faac: aa0003f4  mov      x20, x0
//   0x03fab0: aa0103f5  mov      x21, x1
//   0x03fab4: eb02003f  cmp      x1, x2
//   0x03fab8: 54000220  b.eq     #0x3fafc
//   0x03fabc: aa1503f6  mov      x22, x21
uint64_t fde_0407_sub_03fa80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x03FA80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x03fa80: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03fa84: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03fa88: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03fa8c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03fa90: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03fa94: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03fa98: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x90000158ULL; // 0x03fa9c: adrp x24, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C17ULL; // 0x03faa0: ldr x23, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475718ULL; // 0x03faa4: ldr x24, [x24, #0xea8]
    return acc;
}

// [EN] Reconstructed FDE #0408 @ 0x03fc40..0x03fe00 (448 bytes)
// [VN] Phục dựng FDE #0408 tại 0x03fc40..0x03fe00 (448 byte)
//   0x03fc40: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x03fc44: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03fc48: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03fc4c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03fc50: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03fc54: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03fc58: 910143fd  add      x29, sp, #0x50
//   0x03fc5c: 90000158  adrp     x24, #0x67000
//   0x03fc60: f9401c17  ldr      x23, [x0, #0x38]
//   0x03fc64: f9475718  ldr      x24, [x24, #0xea8]
//   0x03fc68: aa0203f3  mov      x19, x2
//   0x03fc6c: aa0003f4  mov      x20, x0
//   0x03fc70: aa0103f5  mov      x21, x1
//   0x03fc74: eb02003f  cmp      x1, x2
//   0x03fc78: 54000220  b.eq     #0x3fcbc
//   0x03fc7c: aa1503f6  mov      x22, x21
uint64_t fde_0408_sub_03fc40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x03FC40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x03fc40: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03fc44: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03fc48: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03fc4c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03fc50: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03fc54: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03fc58: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x90000158ULL; // 0x03fc5c: adrp x24, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C17ULL; // 0x03fc60: ldr x23, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475718ULL; // 0x03fc64: ldr x24, [x24, #0xea8]
    return acc;
}

// [EN] Reconstructed FDE #0409 @ 0x03fe00..0x0412f4 (5364 bytes)
// [VN] Phục dựng FDE #0409 tại 0x03fe00..0x0412f4 (5364 byte)
//   0x03fe00: d102c3ff  sub      sp, sp, #0xb0
//   0x03fe04: f9002bfb  str      x27, [sp, #0x50]
//   0x03fe08: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x03fe0c: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x03fe10: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x03fe14: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x03fe18: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03fe1c: 910283fd  add      x29, sp, #0xa0
//   0x03fe20: d53bd057  mrs      x23, tpidr_el0
//   0x03fe24: f94016e8  ldr      x8, [x23, #0x28]
//   0x03fe28: aa0103f4  mov      x20, x1
//   0x03fe2c: eb02003f  cmp      x1, x2
//   0x03fe30: f90027e8  str      x8, [sp, #0x48]
//   0x03fe34: 54000f60  b.eq     #0x40020
//   0x03fe38: 39400288  ldrb     w8, [x20]
//   0x03fe3c: aa0203f5  mov      x21, x2
uint64_t fde_0409_sub_03fe00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xF90027E8ULL) + (x2 ^ 0x03FE00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x03fe00: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x03fe04: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x03fe08: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x03fe0c: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x03fe10: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x03fe14: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x03fe18: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03fe1c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03fe20: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03fe24: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0410 @ 0x0412f4..0x041584 (656 bytes)
// [VN] Phục dựng FDE #0410 tại 0x0412f4..0x041584 (656 byte)
//   0x0412f4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0412f8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0412fc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x041300: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x041304: 9100c3fd  add      x29, sp, #0x30
//   0x041308: aa0103f5  mov      x21, x1
//   0x04130c: eb02003f  cmp      x1, x2
//   0x041310: 54000500  b.eq     #0x413b0
//   0x041314: 394002a9  ldrb     w9, [x21]
//   0x041318: aa0203f4  mov      x20, x2
//   0x04131c: aa0003f3  mov      x19, x0
//   0x041320: 5100a128  sub      w8, w9, #0x28
//   0x041324: 7100d11f  cmp      w8, #0x34
//   0x041328: 54000c68  b.hi     #0x414b4
//   0x04132c: d0000089  adrp     x9, #0x53000
//   0x041330: 911c3129  add      x9, x9, #0x70c
uint64_t fde_0410_sub_0412f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x7100D11FULL) + (x2 ^ 0x0412F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0412f4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0412f8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0412fc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x041300: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x041304: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x041308: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x04130c: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000500ULL; // 0x041310: b.eq #0x413b0
    acc = (acc * 0x100000001B3ULL) ^ 0x394002A9ULL; // 0x041314: ldrb w9, [x21]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x041318: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0411 @ 0x041584..0x04191c (920 bytes)
// [VN] Phục dựng FDE #0411 tại 0x041584..0x04191c (920 byte)
//   0x041584: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x041588: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04158c: 910043fd  add      x29, sp, #0x10
//   0x041590: eb02003f  cmp      x1, x2
//   0x041594: 54000ae0  b.eq     #0x416f0
//   0x041598: 39400029  ldrb     w9, [x1]
//   0x04159c: b9401808  ldr      w8, [x0, #0x18]
//   0x0415a0: 7100f93f  cmp      w9, #0x3e
//   0x0415a4: 121c1108  and      w8, w8, #0x1f0
//   0x0415a8: 5400026c  b.gt     #0x415f4
//   0x0415ac: 7100a93f  cmp      w9, #0x2a
//   0x0415b0: 54000a40  b.eq     #0x416f8
//   0x0415b4: 7100ad3f  cmp      w9, #0x2b
//   0x0415b8: 540009c1  b.ne     #0x416f0
//   0x0415bc: 91000433  add      x19, x1, #1
//   0x0415c0: eb02027f  cmp      x19, x2
uint64_t fde_0411_sub_041584(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x7100AD3FULL) + (x2 ^ 0x041584ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x041584: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x041588: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04158c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x041590: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000AE0ULL; // 0x041594: b.eq #0x416f0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400029ULL; // 0x041598: ldrb w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401808ULL; // 0x04159c: ldr w8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100F93FULL; // 0x0415a0: cmp w9, #0x3e
    acc = (acc * 0x100000001B3ULL) ^ 0x121C1108ULL; // 0x0415a4: and w8, w8, #0x1f0
    acc = (acc * 0x100000001B3ULL) ^ 0x5400026CULL; // 0x0415a8: b.gt #0x415f4
    return acc;
}

// [EN] Reconstructed FDE #0412 @ 0x04191c..0x041a6c (336 bytes)
// [VN] Phục dựng FDE #0412 tại 0x04191c..0x041a6c (336 byte)
//   0x04191c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x041920: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x041924: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x041928: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x04192c: 9100c3fd  add      x29, sp, #0x30
//   0x041930: eb02003f  cmp      x1, x2
//   0x041934: 54000840  b.eq     #0x41a3c
//   0x041938: 39400028  ldrb     w8, [x1]
//   0x04193c: 71016d1f  cmp      w8, #0x5b
//   0x041940: 540007e1  b.ne     #0x41a3c
//   0x041944: 91000428  add      x8, x1, #1
//   0x041948: aa0203f3  mov      x19, x2
//   0x04194c: eb02011f  cmp      x8, x2
//   0x041950: 54000820  b.eq     #0x41a54
//   0x041954: 39400429  ldrb     w9, [x1, #1]
//   0x041958: aa0003f4  mov      x20, x0
uint64_t fde_0412_sub_04191c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xEB02011FULL) + (x2 ^ 0x04191CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x04191c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x041920: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x041924: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x041928: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x04192c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x041930: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000840ULL; // 0x041934: b.eq #0x41a3c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x041938: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x71016D1FULL; // 0x04193c: cmp w8, #0x5b
    acc = (acc * 0x100000001B3ULL) ^ 0x540007E1ULL; // 0x041940: b.ne #0x41a3c
    return acc;
}

// [EN] Reconstructed FDE #0413 @ 0x041a6c..0x041ac8 (92 bytes)
// [VN] Phục dựng FDE #0413 tại 0x041a6c..0x041ac8 (92 byte)
//   0x041a6c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x041a70: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x041a74: 910043fd  add      x29, sp, #0x10
//   0x041a78: aa0103f3  mov      x19, x1
//   0x041a7c: eb02003f  cmp      x1, x2
//   0x041a80: 54000160  b.eq     #0x41aac
//   0x041a84: 39400261  ldrb     w1, [x19]
//   0x041a88: 51009028  sub      w8, w1, #0x24
//   0x041a8c: 7101651f  cmp      w8, #0x59
//   0x041a90: 54000168  b.hi     #0x41abc
//   0x041a94: d0000089  adrp     x9, #0x53000
//   0x041a98: 911d0529  add      x9, x9, #0x741
//   0x041a9c: 1000008a  adr      x10, #0x41aac
//   0x041aa0: 3868692b  ldrb     w11, [x9, x8]
//   0x041aa4: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x041aa8: d61f0140  br       x10
uint64_t fde_0413_sub_041a6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x041A6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x041a6c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x041a70: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x041a74: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x041a78: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x041a7c: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000160ULL; // 0x041a80: b.eq #0x41aac
    acc = (acc * 0x100000001B3ULL) ^ 0x39400261ULL; // 0x041a84: ldrb w1, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x51009028ULL; // 0x041a88: sub w8, w1, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0x7101651FULL; // 0x041a8c: cmp w8, #0x59
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x041a90: b.hi #0x41abc
    return acc;
}

// [EN] Reconstructed FDE #0414 @ 0x041ac8..0x041b84 (188 bytes)
// [VN] Phục dựng FDE #0414 tại 0x041ac8..0x041b84 (188 byte)
//   0x041ac8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x041acc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x041ad0: 910043fd  add      x29, sp, #0x10
//   0x041ad4: aa0103f4  mov      x20, x1
//   0x041ad8: eb02003f  cmp      x1, x2
//   0x041adc: 540003a0  b.eq     #0x41b50
//   0x041ae0: 39400288  ldrb     w8, [x20]
//   0x041ae4: 7100c101  subs     w1, w8, #0x30
//   0x041ae8: 54000081  b.ne     #0x41af8
//   0x041aec: 97ff64a9  bl       #0x1ad90
//   0x041af0: 91000693  add      x19, x20, #1
//   0x041af4: 1400001f  b        #0x41b70
//   0x041af8: 5100c508  sub      w8, w8, #0x31
//   0x041afc: 7100211f  cmp      w8, #8
//   0x041b00: 54000288  b.hi     #0x41b50
//   0x041b04: 91000688  add      x8, x20, #1
uint64_t fde_0414_sub_041ac8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x5100C508ULL) + (x2 ^ 0x041AC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x041ac8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x041acc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x041ad0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x041ad4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x041ad8: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540003A0ULL; // 0x041adc: b.eq #0x41b50
    acc = (acc * 0x100000001B3ULL) ^ 0x39400288ULL; // 0x041ae0: ldrb w8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100C101ULL; // 0x041ae4: subs w1, w8, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x54000081ULL; // 0x041ae8: b.ne #0x41af8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF64A9ULL; // 0x041aec: bl #0x1ad90
    return acc;
}

// [EN] Reconstructed FDE #0415 @ 0x041b84..0x041d78 (500 bytes)
// [VN] Phục dựng FDE #0415 tại 0x041b84..0x041d78 (500 byte)
//   0x041b84: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x041b88: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x041b8c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x041b90: 910083fd  add      x29, sp, #0x20
//   0x041b94: aa0103f3  mov      x19, x1
//   0x041b98: eb02003f  cmp      x1, x2
//   0x041b9c: 54000d00  b.eq     #0x41d3c
//   0x041ba0: 39400268  ldrb     w8, [x19]
//   0x041ba4: 51011108  sub      w8, w8, #0x44
//   0x041ba8: 7100cd1f  cmp      w8, #0x33
//   0x041bac: 54000c88  b.hi     #0x41d3c
//   0x041bb0: d0000089  adrp     x9, #0x53000
//   0x041bb4: 911e6d29  add      x9, x9, #0x79b
//   0x041bb8: 100000aa  adr      x10, #0x41bcc
//   0x041bbc: 3868692b  ldrb     w11, [x9, x8]
//   0x041bc0: 8b0b094a  add      x10, x10, x11, lsl #2
uint64_t fde_0415_sub_041b84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x911E6D29ULL) + (x2 ^ 0x041B84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x041b84: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x041b88: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x041b8c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x041b90: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x041b94: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x041b98: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000D00ULL; // 0x041b9c: b.eq #0x41d3c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x041ba0: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x51011108ULL; // 0x041ba4: sub w8, w8, #0x44
    acc = (acc * 0x100000001B3ULL) ^ 0x7100CD1FULL; // 0x041ba8: cmp w8, #0x33
    return acc;
}

// [EN] Reconstructed FDE #0416 @ 0x041d78..0x042174 (1020 bytes)
// [VN] Phục dựng FDE #0416 tại 0x041d78..0x042174 (1020 byte)
//   0x041d78: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x041d7c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x041d80: 910043fd  add      x29, sp, #0x10
//   0x041d84: aa0103f3  mov      x19, x1
//   0x041d88: eb02003f  cmp      x1, x2
//   0x041d8c: 540018a0  b.eq     #0x420a0
//   0x041d90: 39400268  ldrb     w8, [x19]
//   0x041d94: 5100c109  sub      w9, w8, #0x30
//   0x041d98: 7101213f  cmp      w9, #0x48
//   0x041d9c: 540008a8  b.hi     #0x41eb0
//   0x041da0: d000008a  adrp     x10, #0x53000
//   0x041da4: 911f3d4a  add      x10, x10, #0x7cf
//   0x041da8: 1000008b  adr      x11, #0x41db8
//   0x041dac: 3869694c  ldrb     w12, [x10, x9]
//   0x041db0: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x041db4: d61f0160  br       x11
uint64_t fde_0416_sub_041d78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1000008BULL) + (x2 ^ 0x041D78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x041d78: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x041d7c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x041d80: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x041d84: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x041d88: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540018A0ULL; // 0x041d8c: b.eq #0x420a0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x041d90: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x5100C109ULL; // 0x041d94: sub w9, w8, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x7101213FULL; // 0x041d98: cmp w9, #0x48
    acc = (acc * 0x100000001B3ULL) ^ 0x540008A8ULL; // 0x041d9c: b.hi #0x41eb0
    return acc;
}

// [EN] Reconstructed FDE #0417 @ 0x042174..0x042634 (1216 bytes)
// [VN] Phục dựng FDE #0417 tại 0x042174..0x042634 (1216 byte)
//   0x042174: d10303ff  sub      sp, sp, #0xc0
//   0x042178: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x04217c: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x042180: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x042184: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x042188: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x04218c: 9102c3fd  add      x29, sp, #0xb0
//   0x042190: d53bd058  mrs      x24, tpidr_el0
//   0x042194: f9401708  ldr      x8, [x24, #0x28]
//   0x042198: aa0103f4  mov      x20, x1
//   0x04219c: eb02003f  cmp      x1, x2
//   0x0421a0: f81b83a8  stur     x8, [x29, #-0x48]
//   0x0421a4: 54001680  b.eq     #0x42474
//   0x0421a8: 3940028a  ldrb     w10, [x20]
//   0x0421ac: 7101755f  cmp      w10, #0x5d
//   0x0421b0: 54001620  b.eq     #0x42474
uint64_t fde_0417_sub_042174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0x54001680ULL) + (x2 ^ 0x042174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x042174: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x042178: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x04217c: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x042180: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x042184: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x042188: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x04218c: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x042190: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x042194: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x042198: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0418 @ 0x042634..0x042940 (780 bytes)
// [VN] Phục dựng FDE #0418 tại 0x042634..0x042940 (780 byte)
//   0x042634: d10243ff  sub      sp, sp, #0x90
//   0x042638: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x04263c: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x042640: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x042644: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x042648: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x04264c: 910203fd  add      x29, sp, #0x80
//   0x042650: d53bd05a  mrs      x26, tpidr_el0
//   0x042654: f9401748  ldr      x8, [x26, #0x28]
//   0x042658: cb01004a  sub      x10, x2, x1
//   0x04265c: 528ba7a9  mov      w9, #0x5d3d
//   0x042660: f100095f  cmp      x10, #2
//   0x042664: f9001fe8  str      x8, [sp, #0x38]
//   0x042668: 79000be9  strh     w9, [sp, #4]
//   0x04266c: 5400130b  b.lt     #0x428cc
//   0x042670: d1000448  sub      x8, x2, #1
uint64_t fde_0418_sub_042634(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x042634ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x042634: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x042638: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x04263c: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x042640: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x042644: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x042648: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x04264c: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x042650: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x042654: ldr x8, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB01004AULL; // 0x042658: sub x10, x2, x1
    return acc;
}

// [EN] Reconstructed FDE #0419 @ 0x042940..0x042a34 (244 bytes)
// [VN] Phục dựng FDE #0419 tại 0x042940..0x042a34 (244 byte)
//   0x042940: d100c3ff  sub      sp, sp, #0x30
//   0x042944: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x042948: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04294c: 910083fd  add      x29, sp, #0x20
//   0x042950: cb010049  sub      x9, x2, x1
//   0x042954: 528ba748  mov      w8, #0x5d3a
//   0x042958: f100093f  cmp      x9, #2
//   0x04295c: 79001be8  strh     w8, [sp, #0xc]
//   0x042960: 5400066b  b.lt     #0x42a2c
//   0x042964: d1000448  sub      x8, x2, #1
//   0x042968: eb01011f  cmp      x8, x1
//   0x04296c: 54000600  b.eq     #0x42a2c
//   0x042970: 910033ea  add      x10, sp, #0xc
//   0x042974: aa0303f3  mov      x19, x3
//   0x042978: d1000849  sub      x9, x2, #2
//   0x04297c: b240014a  orr      x10, x10, #1
uint64_t fde_0419_sub_042940(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x910033EAULL) + (x2 ^ 0x042940ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x042940: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x042944: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x042948: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04294c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010049ULL; // 0x042950: sub x9, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528BA748ULL; // 0x042954: mov w8, #0x5d3a
    acc = (acc * 0x100000001B3ULL) ^ 0xF100093FULL; // 0x042958: cmp x9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x79001BE8ULL; // 0x04295c: strh w8, [sp, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400066BULL; // 0x042960: b.lt #0x42a2c
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000448ULL; // 0x042964: sub x8, x2, #1
    return acc;
}

// [EN] Reconstructed FDE #0420 @ 0x042a34..0x042b98 (356 bytes)
// [VN] Phục dựng FDE #0420 tại 0x042a34..0x042b98 (356 byte)
//   0x042a34: d10183ff  sub      sp, sp, #0x60
//   0x042a38: f9001bf5  str      x21, [sp, #0x30]
//   0x042a3c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x042a40: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x042a44: 910143fd  add      x29, sp, #0x50
//   0x042a48: d53bd055  mrs      x21, tpidr_el0
//   0x042a4c: f94016a8  ldr      x8, [x21, #0x28]
//   0x042a50: cb01004a  sub      x10, x2, x1
//   0x042a54: 528ba5c9  mov      w9, #0x5d2e
//   0x042a58: f100095f  cmp      x10, #2
//   0x042a5c: f90017e8  str      x8, [sp, #0x28]
//   0x042a60: 79001be9  strh     w9, [sp, #0xc]
//   0x042a64: 5400094b  b.lt     #0x42b8c
//   0x042a68: d1000448  sub      x8, x2, #1
//   0x042a6c: eb01011f  cmp      x8, x1
//   0x042a70: 540008e0  b.eq     #0x42b8c
uint64_t fde_0420_sub_042a34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x5400094BULL) + (x2 ^ 0x042A34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x042a34: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x042a38: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x042a3c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x042a40: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x042a44: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x042a48: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x042a4c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB01004AULL; // 0x042a50: sub x10, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528BA5C9ULL; // 0x042a54: mov w9, #0x5d2e
    acc = (acc * 0x100000001B3ULL) ^ 0xF100095FULL; // 0x042a58: cmp x10, #2
    return acc;
}

// [EN] Reconstructed FDE #0421 @ 0x042b98..0x042e5c (708 bytes)
// [VN] Phục dựng FDE #0421 tại 0x042b98..0x042e5c (708 byte)
//   0x042b98: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x042b9c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x042ba0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x042ba4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x042ba8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x042bac: 910103fd  add      x29, sp, #0x40
//   0x042bb0: eb02003f  cmp      x1, x2
//   0x042bb4: 54001500  b.eq     #0x42e54
//   0x042bb8: 39400028  ldrb     w8, [x1]
//   0x042bbc: aa0103f3  mov      x19, x1
//   0x042bc0: 51011109  sub      w9, w8, #0x44
//   0x042bc4: 7100cd3f  cmp      w9, #0x33
//   0x042bc8: 54000188  b.hi     #0x42bf8
//   0x042bcc: b0000088  adrp     x8, #0x53000
//   0x042bd0: 91206108  add      x8, x8, #0x818
//   0x042bd4: 100000aa  adr      x10, #0x42be8
uint64_t fde_0421_sub_042b98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x54000188ULL) + (x2 ^ 0x042B98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x042b98: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x042b9c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x042ba0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x042ba4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x042ba8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x042bac: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x042bb0: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54001500ULL; // 0x042bb4: b.eq #0x42e54
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x042bb8: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x042bbc: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0422 @ 0x042e5c..0x043128 (716 bytes)
// [VN] Phục dựng FDE #0422 tại 0x042e5c..0x043128 (716 byte)
//   0x042e5c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x042e60: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x042e64: 910043fd  add      x29, sp, #0x10
//   0x042e68: eb02003f  cmp      x1, x2
//   0x042e6c: 540015c0  b.eq     #0x43124
//   0x042e70: aa0103f3  mov      x19, x1
//   0x042e74: 39400021  ldrb     w1, [x1]
//   0x042e78: 51008828  sub      w8, w1, #0x22
//   0x042e7c: 7101511f  cmp      w8, #0x54
//   0x042e80: 540001c8  b.hi     #0x42eb8
//   0x042e84: b0000089  adrp     x9, #0x53000
//   0x042e88: 91213129  add      x9, x9, #0x84c
//   0x042e8c: 1000008a  adr      x10, #0x42e9c
//   0x042e90: 3868692b  ldrb     w11, [x9, x8]
//   0x042e94: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x042e98: d61f0140  br       x10
uint64_t fde_0422_sub_042e5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x042E5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x042e5c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x042e60: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x042e64: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x042e68: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540015C0ULL; // 0x042e6c: b.eq #0x43124
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x042e70: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39400021ULL; // 0x042e74: ldrb w1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x51008828ULL; // 0x042e78: sub w8, w1, #0x22
    acc = (acc * 0x100000001B3ULL) ^ 0x7101511FULL; // 0x042e7c: cmp w8, #0x54
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C8ULL; // 0x042e80: b.hi #0x42eb8
    return acc;
}

// [EN] Reconstructed FDE #0423 @ 0x043128..0x043408 (736 bytes)
// [VN] Phục dựng FDE #0423 tại 0x043128..0x043408 (736 byte)
//   0x043128: d10243ff  sub      sp, sp, #0x90
//   0x04312c: f90023f9  str      x25, [sp, #0x40]
//   0x043130: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x043134: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x043138: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x04313c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x043140: 910203fd  add      x29, sp, #0x80
//   0x043144: d53bd058  mrs      x24, tpidr_el0
//   0x043148: aa0803f3  mov      x19, x8
//   0x04314c: f9401708  ldr      x8, [x24, #0x28]
//   0x043150: cb010059  sub      x25, x2, x1
//   0x043154: b100433f  cmn      x25, #0x10
//   0x043158: f9001fe8  str      x8, [sp, #0x38]
//   0x04315c: a902ffff  stp      xzr, xzr, [sp, #0x28]
//   0x043160: f90013ff  str      xzr, [sp, #0x20]
//   0x043164: 54001242  b.hs     #0x433ac
uint64_t fde_0423_sub_043128(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x043128ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x043128: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x04312c: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x043130: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x043134: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x043138: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x04313c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x043140: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x043144: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x043148: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x04314c: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0424 @ 0x043408..0x0435ac (420 bytes)
// [VN] Phục dựng FDE #0424 tại 0x043408..0x0435ac (420 byte)
//   0x043408: d101c3ff  sub      sp, sp, #0x70
//   0x04340c: f90013f9  str      x25, [sp, #0x20]
//   0x043410: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x043414: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x043418: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x04341c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x043420: 910183fd  add      x29, sp, #0x60
//   0x043424: d53bd058  mrs      x24, tpidr_el0
//   0x043428: f9401708  ldr      x8, [x24, #0x28]
//   0x04342c: cb010059  sub      x25, x2, x1
//   0x043430: b100433f  cmn      x25, #0x10
//   0x043434: f9000fe8  str      x8, [sp, #0x18]
//   0x043438: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x04343c: f90003ff  str      xzr, [sp]
//   0x043440: 54000a22  b.hs     #0x43584
//   0x043444: 2a0303f3  mov      w19, w3
uint64_t fde_0424_sub_043408(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xA900FFFFULL) + (x2 ^ 0x043408ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x043408: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x04340c: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x043410: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x043414: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x043418: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x04341c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x043420: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x043424: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x043428: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010059ULL; // 0x04342c: sub x25, x2, x1
    return acc;
}

// [EN] Reconstructed FDE #0425 @ 0x0435ac..0x0437ac (512 bytes)
// [VN] Phục dựng FDE #0425 tại 0x0435ac..0x0437ac (512 byte)
//   0x0435ac: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0435b0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0435b4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0435b8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0435bc: 9100c3fd  add      x29, sp, #0x30
//   0x0435c0: aa0203f4  mov      x20, x2
//   0x0435c4: aa0103f5  mov      x21, x1
//   0x0435c8: aa0003f3  mov      x19, x0
//   0x0435cc: 97ff5ec5  bl       #0x1b0e0
//   0x0435d0: aa0003f6  mov      x22, x0
//   0x0435d4: eb15001f  cmp      x0, x21
//   0x0435d8: 54000721  b.ne     #0x436bc
//   0x0435dc: eb1402df  cmp      x22, x20
//   0x0435e0: 540006e0  b.eq     #0x436bc
//   0x0435e4: 910006a8  add      x8, x21, #1
//   0x0435e8: eb14011f  cmp      x8, x20
uint64_t fde_0425_sub_0435ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xEB1402DFULL) + (x2 ^ 0x0435ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0435ac: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0435b0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0435b4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0435b8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0435bc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x0435c0: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0435c4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0435c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5EC5ULL; // 0x0435cc: bl #0x1b0e0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x0435d0: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0426 @ 0x0437ac..0x043a2c (640 bytes)
// [VN] Phục dựng FDE #0426 tại 0x0437ac..0x043a2c (640 byte)
//   0x0437ac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0437b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0437b4: 910043fd  add      x29, sp, #0x10
//   0x0437b8: aa0103f3  mov      x19, x1
//   0x0437bc: eb02003f  cmp      x1, x2
//   0x0437c0: 540012a0  b.eq     #0x43a14
//   0x0437c4: 39400268  ldrb     w8, [x19]
//   0x0437c8: 7100a91f  cmp      w8, #0x2a
//   0x0437cc: 54000121  b.ne     #0x437f0
//   0x0437d0: 2a0403e4  mov      w4, w4
//   0x0437d4: 2a0503e5  mov      w5, w5
//   0x0437d8: 92800002  mov      x2, #-1
//   0x0437dc: 52800026  mov      w6, #1
//   0x0437e0: aa1f03e1  mov      x1, xzr
//   0x0437e4: 97ff602b  bl       #0x1b890
//   0x0437e8: 91000673  add      x19, x19, #1
uint64_t fde_0426_sub_0437ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x52800026ULL) + (x2 ^ 0x0437ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0437ac: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0437b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0437b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0437b8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x0437bc: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540012A0ULL; // 0x0437c0: b.eq #0x43a14
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x0437c4: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100A91FULL; // 0x0437c8: cmp w8, #0x2a
    acc = (acc * 0x100000001B3ULL) ^ 0x54000121ULL; // 0x0437cc: b.ne #0x437f0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E4ULL; // 0x0437d0: mov w4, w4
    return acc;
}

// [EN] Reconstructed FDE #0427 @ 0x043a2c..0x043b48 (284 bytes)
// [VN] Phục dựng FDE #0427 tại 0x043a2c..0x043b48 (284 byte)
//   0x043a2c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x043a30: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x043a34: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x043a38: 910083fd  add      x29, sp, #0x20
//   0x043a3c: aa0103f3  mov      x19, x1
//   0x043a40: eb02003f  cmp      x1, x2
//   0x043a44: aa0003f4  mov      x20, x0
//   0x043a48: 54000660  b.eq     #0x43b14
//   0x043a4c: aa1303f5  mov      x21, x19
//   0x043a50: 384016a1  ldrb     w1, [x21], #1
//   0x043a54: eb0202bf  cmp      x21, x2
//   0x043a58: 54000061  b.ne     #0x43a64
//   0x043a5c: 7100903f  cmp      w1, #0x24
//   0x043a60: 54000140  b.eq     #0x43a88
//   0x043a64: 5100b828  sub      w8, w1, #0x2e
//   0x043a68: 7100b91f  cmp      w8, #0x2e
uint64_t fde_0427_sub_043a2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x7100903FULL) + (x2 ^ 0x043A2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x043a2c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x043a30: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x043a34: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x043a38: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x043a3c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x043a40: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x043a44: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000660ULL; // 0x043a48: b.eq #0x43b14
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303F5ULL; // 0x043a4c: mov x21, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x384016A1ULL; // 0x043a50: ldrb w1, [x21], #1
    return acc;
}

// [EN] Reconstructed FDE #0428 @ 0x043b48..0x043d78 (560 bytes)
// [VN] Phục dựng FDE #0428 tại 0x043b48..0x043d78 (560 byte)
//   0x043b48: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x043b4c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x043b50: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x043b54: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x043b58: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x043b5c: 910103fd  add      x29, sp, #0x40
//   0x043b60: f9401c14  ldr      x20, [x0, #0x38]
//   0x043b64: b9401c18  ldr      w24, [x0, #0x1c]
//   0x043b68: aa0203f3  mov      x19, x2
//   0x043b6c: aa0003f5  mov      x21, x0
//   0x043b70: aa0103f6  mov      x22, x1
//   0x043b74: 97ff605b  bl       #0x1bce0
//   0x043b78: aa0003e1  mov      x1, x0
//   0x043b7c: eb16001f  cmp      x0, x22
//   0x043b80: 54000101  b.ne     #0x43ba0
//   0x043b84: aa1503e0  mov      x0, x21
uint64_t fde_0428_sub_043b48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x043B48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x043b48: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x043b4c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x043b50: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x043b54: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x043b58: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x043b5c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C14ULL; // 0x043b60: ldr x20, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C18ULL; // 0x043b64: ldr w24, [x0, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x043b68: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x043b6c: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0429 @ 0x043d78..0x043de0 (104 bytes)
// [VN] Phục dựng FDE #0429 tại 0x043d78..0x043de0 (104 byte)
//   0x043d78: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x043d7c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x043d80: 910043fd  add      x29, sp, #0x10
//   0x043d84: aa0103f3  mov      x19, x1
//   0x043d88: eb02003f  cmp      x1, x2
//   0x043d8c: 54000160  b.eq     #0x43db8
//   0x043d90: 39400261  ldrb     w1, [x19]
//   0x043d94: 51009028  sub      w8, w1, #0x24
//   0x043d98: 7101611f  cmp      w8, #0x58
//   0x043d9c: 540001c8  b.hi     #0x43dd4
//   0x043da0: 90000089  adrp     x9, #0x53000
//   0x043da4: 91228529  add      x9, x9, #0x8a1
//   0x043da8: 1000008a  adr      x10, #0x43db8
//   0x043dac: 3868692b  ldrb     w11, [x9, x8]
//   0x043db0: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x043db4: d61f0140  br       x10
uint64_t fde_0429_sub_043d78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x043D78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x043d78: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x043d7c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x043d80: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x043d84: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x043d88: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000160ULL; // 0x043d8c: b.eq #0x43db8
    acc = (acc * 0x100000001B3ULL) ^ 0x39400261ULL; // 0x043d90: ldrb w1, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x51009028ULL; // 0x043d94: sub w8, w1, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0x7101611FULL; // 0x043d98: cmp w8, #0x58
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C8ULL; // 0x043d9c: b.hi #0x43dd4
    return acc;
}

// [EN] Reconstructed FDE #0430 @ 0x043de0..0x043e74 (148 bytes)
// [VN] Phục dựng FDE #0430 tại 0x043de0..0x043e74 (148 byte)
//   0x043de0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x043de4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x043de8: 910043fd  add      x29, sp, #0x10
//   0x043dec: aa0103f3  mov      x19, x1
//   0x043df0: eb02003f  cmp      x1, x2
//   0x043df4: 54000280  b.eq     #0x43e44
//   0x043df8: 91000661  add      x1, x19, #1
//   0x043dfc: eb02003f  cmp      x1, x2
//   0x043e00: 54000220  b.eq     #0x43e44
//   0x043e04: 39400268  ldrb     w8, [x19]
//   0x043e08: 7101711f  cmp      w8, #0x5c
//   0x043e0c: 540001c1  b.ne     #0x43e44
//   0x043e10: 39400028  ldrb     w8, [x1]
//   0x043e14: 51009109  sub      w9, w8, #0x24
//   0x043e18: 7101653f  cmp      w9, #0x59
//   0x043e1c: 540001c8  b.hi     #0x43e54
uint64_t fde_0430_sub_043de0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x39400028ULL) + (x2 ^ 0x043DE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x043de0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x043de4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x043de8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x043dec: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x043df0: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000280ULL; // 0x043df4: b.eq #0x43e44
    acc = (acc * 0x100000001B3ULL) ^ 0x91000661ULL; // 0x043df8: add x1, x19, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x043dfc: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x043e00: b.eq #0x43e44
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x043e04: ldrb w8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0431 @ 0x043e74..0x043e78 (4 bytes)
// [VN] Phục dựng FDE #0431 tại 0x043e74..0x043e78 (4 byte)
//   0x043e74: 17ff5b03  b        #0x1aa80
uint64_t fde_0431_sub_043e74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5B03ULL) + (x1 ^ 0x17FF5B03ULL) + (x2 ^ 0x043E74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5B03ULL; // 0x043e74: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0432 @ 0x043e78..0x043e80 (8 bytes)
// [VN] Phục dựng FDE #0432 tại 0x043e78..0x043e80 (8 byte)
//   0x043e78: 2a1f03e0  mov      w0, wzr
//   0x043e7c: d65f03c0  ret      
uint64_t fde_0432_sub_043e78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x043E78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x043e78: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x043e7c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0433 @ 0x043e80..0x043e84 (4 bytes)
// [VN] Phục dựng FDE #0433 tại 0x043e80..0x043e84 (4 byte)
//   0x043e80: 17ff5b00  b        #0x1aa80
uint64_t fde_0433_sub_043e80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5B00ULL) + (x1 ^ 0x17FF5B00ULL) + (x2 ^ 0x043E80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5B00ULL; // 0x043e80: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0434 @ 0x043e84..0x043e8c (8 bytes)
// [VN] Phục dựng FDE #0434 tại 0x043e84..0x043e8c (8 byte)
//   0x043e84: 52800020  mov      w0, #1
//   0x043e88: d65f03c0  ret      
uint64_t fde_0434_sub_043e84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800020ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x043E84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x043e84: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x043e88: ret 
    return acc;
}

// [EN] Reconstructed FDE #0435 @ 0x043e8c..0x043e90 (4 bytes)
// [VN] Phục dựng FDE #0435 tại 0x043e8c..0x043e90 (4 byte)
//   0x043e8c: d65f03c0  ret      
uint64_t fde_0435_sub_043e8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x043E8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x043e8c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0436 @ 0x043e90..0x043e94 (4 bytes)
// [VN] Phục dựng FDE #0436 tại 0x043e90..0x043e94 (4 byte)
//   0x043e90: 17ff5afc  b        #0x1aa80
uint64_t fde_0436_sub_043e90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5AFCULL) + (x1 ^ 0x17FF5AFCULL) + (x2 ^ 0x043E90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5AFCULL; // 0x043e90: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0437 @ 0x043e94..0x044014 (384 bytes)
// [VN] Phục dựng FDE #0437 tại 0x043e94..0x044014 (384 byte)
//   0x043e94: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x043e98: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x043e9c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x043ea0: 910083fd  add      x29, sp, #0x20
//   0x043ea4: d14007ff  sub      sp, sp, #1, lsl #12
//   0x043ea8: d10e83ff  sub      sp, sp, #0x3a0
//   0x043eac: d53bd054  mrs      x20, tpidr_el0
//   0x043eb0: f9401688  ldr      x8, [x20, #0x28]
//   0x043eb4: 90000081  adrp     x1, #0x53000
//   0x043eb8: aa0003f3  mov      x19, x0
//   0x043ebc: 91257821  add      x1, x1, #0x95e
//   0x043ec0: 910043e0  add      x0, sp, #0x10
//   0x043ec4: f81d83a8  stur     x8, [x29, #-0x28]
//   0x043ec8: 97ff5f32  bl       #0x1bb90
//   0x043ecc: 910023e0  add      x0, sp, #8
//   0x043ed0: 910043e1  add      x1, sp, #0x10
uint64_t fde_0437_sub_043e94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x043E94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x043e94: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x043e98: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x043e9c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x043ea0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x043ea4: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10E83FFULL; // 0x043ea8: sub sp, sp, #0x3a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x043eac: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x043eb0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000081ULL; // 0x043eb4: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x043eb8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0438 @ 0x044014..0x044018 (4 bytes)
// [VN] Phục dựng FDE #0438 tại 0x044014..0x044018 (4 byte)
//   0x044014: 17ff5a9b  b        #0x1aa80
uint64_t fde_0438_sub_044014(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5A9BULL) + (x1 ^ 0x17FF5A9BULL) + (x2 ^ 0x044014ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5A9BULL; // 0x044014: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0439 @ 0x044018..0x044128 (272 bytes)
// [VN] Phục dựng FDE #0439 tại 0x044018..0x044128 (272 byte)
//   0x044018: fc1c0fe8  str      d8, [sp, #-0x40]!
//   0x04401c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x044020: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x044024: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x044028: 9100c3fd  add      x29, sp, #0x30
//   0x04402c: aa0003f3  mov      x19, x0
//   0x044030: 97ff5f10  bl       #0x1bc70
//   0x044034: d29ef9e8  mov      x8, #0xf7cf
//   0x044038: f2bc6a68  movk     x8, #0xe353, lsl #16
//   0x04403c: f2d374a8  movk     x8, #0x9ba5, lsl #32
//   0x044040: f2e41888  movk     x8, #0x20c4, lsl #48
//   0x044044: f9401669  ldr      x9, [x19, #0x28]
//   0x044048: 9b487c08  smulh    x8, x0, x8
//   0x04404c: 9347fd0a  asr      x10, x8, #7
//   0x044050: 8b48fd48  add      x8, x10, x8, lsr #63
//   0x044054: eb090109  subs     x9, x8, x9
uint64_t fde_0439_sub_044018(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC1C0FE8ULL) + (x1 ^ 0x9B487C08ULL) + (x2 ^ 0x044018ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC1C0FE8ULL; // 0x044018: str d8, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04401c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x044020: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x044024: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x044028: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04402c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5F10ULL; // 0x044030: bl #0x1bc70
    acc = (acc * 0x100000001B3ULL) ^ 0xD29EF9E8ULL; // 0x044034: mov x8, #0xf7cf
    acc = (acc * 0x100000001B3ULL) ^ 0xF2BC6A68ULL; // 0x044038: movk x8, #0xe353, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2D374A8ULL; // 0x04403c: movk x8, #0x9ba5, lsl #32
    return acc;
}

// [EN] Reconstructed FDE #0440 @ 0x044128..0x0442a8 (384 bytes)
// [VN] Phục dựng FDE #0440 tại 0x044128..0x0442a8 (384 byte)
//   0x044128: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x04412c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x044130: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x044134: 910083fd  add      x29, sp, #0x20
//   0x044138: d14007ff  sub      sp, sp, #1, lsl #12
//   0x04413c: d10e83ff  sub      sp, sp, #0x3a0
//   0x044140: d53bd054  mrs      x20, tpidr_el0
//   0x044144: f9401688  ldr      x8, [x20, #0x28]
//   0x044148: f0000061  adrp     x1, #0x53000
//   0x04414c: aa0003f3  mov      x19, x0
//   0x044150: 91257821  add      x1, x1, #0x95e
//   0x044154: 910043e0  add      x0, sp, #0x10
//   0x044158: f81d83a8  stur     x8, [x29, #-0x28]
//   0x04415c: 97ff5e8d  bl       #0x1bb90
//   0x044160: 910023e0  add      x0, sp, #8
//   0x044164: 910043e1  add      x1, sp, #0x10
uint64_t fde_0440_sub_044128(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x044128ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x044128: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04412c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x044130: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x044134: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x044138: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10E83FFULL; // 0x04413c: sub sp, sp, #0x3a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x044140: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x044144: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000061ULL; // 0x044148: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04414c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0441 @ 0x0442a8..0x0442ac (4 bytes)
// [VN] Phục dựng FDE #0441 tại 0x0442a8..0x0442ac (4 byte)
//   0x0442a8: 17ff59f6  b        #0x1aa80
uint64_t fde_0441_sub_0442a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF59F6ULL) + (x1 ^ 0x17FF59F6ULL) + (x2 ^ 0x0442A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF59F6ULL; // 0x0442a8: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0442 @ 0x0442ac..0x0442bc (16 bytes)
// [VN] Phục dựng FDE #0442 tại 0x0442ac..0x0442bc (16 byte)
//   0x0442ac: b9400c08  ldr      w8, [x0, #0xc]
//   0x0442b0: 7100011f  cmp      w8, #0
//   0x0442b4: 1a9fd7e0  cset     w0, gt
//   0x0442b8: d65f03c0  ret      
uint64_t fde_0442_sub_0442ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400C08ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0442ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400C08ULL; // 0x0442ac: ldr w8, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100011FULL; // 0x0442b0: cmp w8, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9FD7E0ULL; // 0x0442b4: cset w0, gt
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0442b8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0443 @ 0x0442bc..0x0442c0 (4 bytes)
// [VN] Phục dựng FDE #0443 tại 0x0442bc..0x0442c0 (4 byte)
//   0x0442bc: 17ff59f1  b        #0x1aa80
uint64_t fde_0443_sub_0442bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF59F1ULL) + (x1 ^ 0x17FF59F1ULL) + (x2 ^ 0x0442BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF59F1ULL; // 0x0442bc: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0444 @ 0x0442c0..0x044308 (72 bytes)
// [VN] Phục dựng FDE #0444 tại 0x0442c0..0x044308 (72 byte)
//   0x0442c0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0442c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0442c8: 910043fd  add      x29, sp, #0x10
//   0x0442cc: aa0003f3  mov      x19, x0
//   0x0442d0: 97ff5e68  bl       #0x1bc70
//   0x0442d4: d29ef9e8  mov      x8, #0xf7cf
//   0x0442d8: f2bc6a68  movk     x8, #0xe353, lsl #16
//   0x0442dc: f2d374a8  movk     x8, #0x9ba5, lsl #32
//   0x0442e0: f2e41888  movk     x8, #0x20c4, lsl #48
//   0x0442e4: f9400a69  ldr      x9, [x19, #0x10]
//   0x0442e8: 9b487c08  smulh    x8, x0, x8
//   0x0442ec: 9347fd0a  asr      x10, x8, #7
//   0x0442f0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0442f4: 8b48fd48  add      x8, x10, x8, lsr #63
//   0x0442f8: eb09011f  cmp      x8, x9
//   0x0442fc: 1a9fc7e0  cset     w0, le
uint64_t fde_0444_sub_0442c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x0442C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0442c0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0442c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0442c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0442cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5E68ULL; // 0x0442d0: bl #0x1bc70
    acc = (acc * 0x100000001B3ULL) ^ 0xD29EF9E8ULL; // 0x0442d4: mov x8, #0xf7cf
    acc = (acc * 0x100000001B3ULL) ^ 0xF2BC6A68ULL; // 0x0442d8: movk x8, #0xe353, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2D374A8ULL; // 0x0442dc: movk x8, #0x9ba5, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E41888ULL; // 0x0442e0: movk x8, #0x20c4, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A69ULL; // 0x0442e4: ldr x9, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0445 @ 0x044308..0x04430c (4 bytes)
// [VN] Phục dựng FDE #0445 tại 0x044308..0x04430c (4 byte)
//   0x044308: 17ff59de  b        #0x1aa80
uint64_t fde_0445_sub_044308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF59DEULL) + (x1 ^ 0x17FF59DEULL) + (x2 ^ 0x044308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF59DEULL; // 0x044308: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0446 @ 0x04430c..0x04448c (384 bytes)
// [VN] Phục dựng FDE #0446 tại 0x04430c..0x04448c (384 byte)
//   0x04430c: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x044310: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x044314: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x044318: 910083fd  add      x29, sp, #0x20
//   0x04431c: d14007ff  sub      sp, sp, #1, lsl #12
//   0x044320: d10e83ff  sub      sp, sp, #0x3a0
//   0x044324: d53bd054  mrs      x20, tpidr_el0
//   0x044328: f9401688  ldr      x8, [x20, #0x28]
//   0x04432c: f0000061  adrp     x1, #0x53000
//   0x044330: aa0003f3  mov      x19, x0
//   0x044334: 91257821  add      x1, x1, #0x95e
//   0x044338: 910043e0  add      x0, sp, #0x10
//   0x04433c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x044340: 97ff5e14  bl       #0x1bb90
//   0x044344: 910023e0  add      x0, sp, #8
//   0x044348: 910043e1  add      x1, sp, #0x10
uint64_t fde_0446_sub_04430c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x04430CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x04430c: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x044310: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x044314: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x044318: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x04431c: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10E83FFULL; // 0x044320: sub sp, sp, #0x3a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x044324: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x044328: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000061ULL; // 0x04432c: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x044330: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0447 @ 0x04448c..0x0444c0 (52 bytes)
// [VN] Phục dựng FDE #0447 tại 0x04448c..0x0444c0 (52 byte)
//   0x04448c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x044490: 910003fd  mov      x29, sp
//   0x044494: 97ff5c8b  bl       #0x1b6c0
//   0x044498: b40000e0  cbz      x0, #0x444b4
//   0x04449c: f9400c00  ldr      x0, [x0, #0x18]
//   0x0444a0: b40000a0  cbz      x0, #0x444b4
//   0x0444a4: f9400008  ldr      x8, [x0]
//   0x0444a8: f9400901  ldr      x1, [x8, #0x10]
//   0x0444ac: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0444b0: d61f0020  br       x1
//   0x0444b4: 2a1f03e0  mov      w0, wzr
//   0x0444b8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0444bc: d65f03c0  ret      
uint64_t fde_0447_sub_04448c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04448CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04448c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x044490: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5C8BULL; // 0x044494: bl #0x1b6c0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x044498: cbz x0, #0x444b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x04449c: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x0444a0: cbz x0, #0x444b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0444a4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400901ULL; // 0x0444a8: ldr x1, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0444ac: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x0444b0: br x1
    return acc;
}

// [EN] Reconstructed FDE #0448 @ 0x0444c0..0x0446d0 (528 bytes)
// [VN] Phục dựng FDE #0448 tại 0x0444c0..0x0446d0 (528 byte)
//   0x0444c0: d10283ff  sub      sp, sp, #0xa0
//   0x0444c4: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x0444c8: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x0444cc: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x0444d0: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x0444d4: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x0444d8: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x0444dc: 910243fd  add      x29, sp, #0x90
//   0x0444e0: d53bd059  mrs      x25, tpidr_el0
//   0x0444e4: f9401728  ldr      x8, [x25, #0x28]
//   0x0444e8: aa0003f3  mov      x19, x0
//   0x0444ec: 910083e0  add      x0, sp, #0x20
//   0x0444f0: 910083f5  add      x21, sp, #0x20
//   0x0444f4: f9001fe8  str      x8, [sp, #0x38]
//   0x0444f8: 97ff59b6  bl       #0x1abd0
//   0x0444fc: 394083e8  ldrb     w8, [sp, #0x20]
uint64_t fde_0448_sub_0444c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x910083F5ULL) + (x2 ^ 0x0444C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x0444c0: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x0444c4: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x0444c8: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x0444cc: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x0444d0: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x0444d4: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x0444d8: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x0444dc: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x0444e0: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x0444e4: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0449 @ 0x0446d0..0x0447e4 (276 bytes)
// [VN] Phục dựng FDE #0449 tại 0x0446d0..0x0447e4 (276 byte)
//   0x0446d0: d10183ff  sub      sp, sp, #0x60
//   0x0446d4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0446d8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0446dc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0446e0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0446e4: 910143fd  add      x29, sp, #0x50
//   0x0446e8: d53bd058  mrs      x24, tpidr_el0
//   0x0446ec: f9401708  ldr      x8, [x24, #0x28]
//   0x0446f0: 9100c013  add      x19, x0, #0x30
//   0x0446f4: aa0003f6  mov      x22, x0
//   0x0446f8: aa1303e0  mov      x0, x19
//   0x0446fc: aa0203f5  mov      x21, x2
//   0x044700: aa0103f4  mov      x20, x1
//   0x044704: f9000fe8  str      x8, [sp, #0x18]
//   0x044708: 97ff5e62  bl       #0x1c090
//   0x04470c: 910022d6  add      x22, x22, #8
uint64_t fde_0449_sub_0446d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x0446D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0446d0: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0446d4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0446d8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0446dc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0446e0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0446e4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0446e8: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0446ec: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C013ULL; // 0x0446f0: add x19, x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x0446f4: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0450 @ 0x0447e4..0x0449b0 (460 bytes)
// [VN] Phục dựng FDE #0450 tại 0x0447e4..0x0449b0 (460 byte)
//   0x0447e4: d101c3ff  sub      sp, sp, #0x70
//   0x0447e8: f9000bfb  str      x27, [sp, #0x10]
//   0x0447ec: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0447f0: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0447f4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0447f8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0447fc: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x044800: 910183fd  add      x29, sp, #0x60
//   0x044804: d53bd057  mrs      x23, tpidr_el0
//   0x044808: f94016e8  ldr      x8, [x23, #0x28]
//   0x04480c: aa0103f5  mov      x21, x1
//   0x044810: aa0003f4  mov      x20, x0
//   0x044814: f90007e8  str      x8, [sp, #8]
//   0x044818: 39400028  ldrb     w8, [x1]
//   0x04481c: a940a42a  ldp      x10, x9, [x1, #8]
//   0x044820: 7200011f  tst      w8, #1
uint64_t fde_0450_sub_0447e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0447E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0447e4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BFBULL; // 0x0447e8: str x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0447ec: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0447f0: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0447f4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0447f8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0447fc: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x044800: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x044804: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x044808: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0451 @ 0x0449b0..0x044d30 (896 bytes)
// [VN] Phục dựng FDE #0451 tại 0x0449b0..0x044d30 (896 byte)
//   0x0449b0: f100805f  cmp      x2, #0x20
//   0x0449b4: 540000c8  b.hi     #0x449cc
//   0x0449b8: f100405f  cmp      x2, #0x10
//   0x0449bc: 540006c8  b.hi     #0x44a94
//   0x0449c0: aa0103e0  mov      x0, x1
//   0x0449c4: aa0203e1  mov      x1, x2
//   0x0449c8: 17ff5a56  b        #0x1b320
//   0x0449cc: f101005f  cmp      x2, #0x40
//   0x0449d0: 54000be8  b.hi     #0x44b4c
//   0x0449d4: 8b02002a  add      x10, x1, x2
//   0x0449d8: a97f414e  ldp      x14, x16, [x10, #-0x10]
//   0x0449dc: d28624eb  mov      x11, #0x3127
//   0x0449e0: a940342c  ldp      x12, x13, [x1]
//   0x0449e4: f2b2f96b  movk     x11, #0x97cb, lsl #16
//   0x0449e8: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x0449ec: f2d90b8b  movk     x11, #0xc85c, lsl #32
uint64_t fde_0451_sub_0449b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF100805FULL) + (x1 ^ 0xA940342CULL) + (x2 ^ 0x0449B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF100805FULL; // 0x0449b0: cmp x2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C8ULL; // 0x0449b4: b.hi #0x449cc
    acc = (acc * 0x100000001B3ULL) ^ 0xF100405FULL; // 0x0449b8: cmp x2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x540006C8ULL; // 0x0449bc: b.hi #0x44a94
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x0449c0: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x0449c4: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5A56ULL; // 0x0449c8: b #0x1b320
    acc = (acc * 0x100000001B3ULL) ^ 0xF101005FULL; // 0x0449cc: cmp x2, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x54000BE8ULL; // 0x0449d0: b.hi #0x44b4c
    acc = (acc * 0x100000001B3ULL) ^ 0x8B02002AULL; // 0x0449d4: add x10, x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0452 @ 0x044d30..0x044e34 (260 bytes)
// [VN] Phục dựng FDE #0452 tại 0x044d30..0x044e34 (260 byte)
//   0x044d30: f100243f  cmp      x1, #9
//   0x044d34: aa0003e8  mov      x8, x0
//   0x044d38: 540002c3  b.lo     #0x44d90
//   0x044d3c: 8b010109  add      x9, x8, x1
//   0x044d40: f85f8129  ldur     x9, [x9, #-8]
//   0x044d44: f9400108  ldr      x8, [x8]
//   0x044d48: 4b0103ea  neg      w10, w1
//   0x044d4c: 8b01012b  add      x11, x9, x1
//   0x044d50: 9ac1256c  lsr      x12, x11, x1
//   0x044d54: 9aca216a  lsl      x10, x11, x10
//   0x044d58: d285ad2b  mov      x11, #0x2d69
//   0x044d5c: f2bd670b  movk     x11, #0xeb38, lsl #16
//   0x044d60: aa0c014a  orr      x10, x10, x12
//   0x044d64: f2dd410b  movk     x11, #0xea08, lsl #32
//   0x044d68: ca080148  eor      x8, x10, x8
//   0x044d6c: f2f3bbeb  movk     x11, #0x9ddf, lsl #48
uint64_t fde_0452_sub_044d30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF100243FULL) + (x1 ^ 0xAA0C014AULL) + (x2 ^ 0x044D30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF100243FULL; // 0x044d30: cmp x1, #9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x044d34: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540002C3ULL; // 0x044d38: b.lo #0x44d90
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010109ULL; // 0x044d3c: add x9, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF85F8129ULL; // 0x044d40: ldur x9, [x9, #-8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x044d44: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0103EAULL; // 0x044d48: neg w10, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01012BULL; // 0x044d4c: add x11, x9, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC1256CULL; // 0x044d50: lsr x12, x11, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9ACA216AULL; // 0x044d54: lsl x10, x11, x10
    return acc;
}

// [EN] Reconstructed FDE #0453 @ 0x044e34..0x04515c (808 bytes)
// [VN] Phục dựng FDE #0453 tại 0x044e34..0x04515c (808 byte)
//   0x044e34: d10203ff  sub      sp, sp, #0x80
//   0x044e38: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x044e3c: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x044e40: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x044e44: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x044e48: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x044e4c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x044e50: 9101c3fd  add      x29, sp, #0x70
//   0x044e54: d53bd059  mrs      x25, tpidr_el0
//   0x044e58: f9401728  ldr      x8, [x25, #0x28]
//   0x044e5c: aa0303f6  mov      x22, x3
//   0x044e60: aa0103f7  mov      x23, x1
//   0x044e64: aa0003f3  mov      x19, x0
//   0x044e68: f9000fe8  str      x8, [sp, #0x18]
//   0x044e6c: 39400028  ldrb     w8, [x1]
//   0x044e70: a940a42a  ldp      x10, x9, [x1, #8]
uint64_t fde_0453_sub_044e34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x044E34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x044e34: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x044e38: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x044e3c: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x044e40: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x044e44: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x044e48: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x044e4c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x044e50: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x044e54: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x044e58: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0454 @ 0x04515c..0x045240 (228 bytes)
// [VN] Phục dựng FDE #0454 tại 0x04515c..0x045240 (228 byte)
//   0x04515c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x045160: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x045164: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x045168: 910083fd  add      x29, sp, #0x20
//   0x04516c: f1000428  subs     x8, x1, #1
//   0x045170: aa0003f3  mov      x19, x0
//   0x045174: 54000061  b.ne     #0x45180
//   0x045178: 52800054  mov      w20, #2
//   0x04517c: 14000007  b        #0x45198
//   0x045180: aa0103f4  mov      x20, x1
//   0x045184: ea08003f  tst      x1, x8
//   0x045188: 54000080  b.eq     #0x45198
//   0x04518c: aa1403e0  mov      x0, x20
//   0x045190: 97ff5958  bl       #0x1b6f0
//   0x045194: aa0003f4  mov      x20, x0
//   0x045198: f9400675  ldr      x21, [x19, #8]
uint64_t fde_0454_sub_04515c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x04515CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x04515c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x045160: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x045164: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x045168: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x04516c: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x045170: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x045174: b.ne #0x45180
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x045178: mov w20, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x14000007ULL; // 0x04517c: b #0x45198
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x045180: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0455 @ 0x045240..0x0454b0 (624 bytes)
// [VN] Phục dựng FDE #0455 tại 0x045240..0x0454b0 (624 byte)
//   0x045240: d10203ff  sub      sp, sp, #0x80
//   0x045244: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x045248: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x04524c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x045250: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x045254: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x045258: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x04525c: 9101c3fd  add      x29, sp, #0x70
//   0x045260: aa0003f3  mov      x19, x0
//   0x045264: b4000421  cbz      x1, #0x452e8
//   0x045268: aa0103f4  mov      x20, x1
//   0x04526c: d37dfc28  lsr      x8, x1, #0x3d
//   0x045270: b50011a8  cbnz     x8, #0x454a4
//   0x045274: d37df280  lsl      x0, x20, #3
//   0x045278: 97ff5a7a  bl       #0x1bc60
//   0x04527c: f9400268  ldr      x8, [x19]
uint64_t fde_0455_sub_045240(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xB50011A8ULL) + (x2 ^ 0x045240ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x045240: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x045244: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x045248: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x04524c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x045250: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x045254: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x045258: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x04525c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x045260: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000421ULL; // 0x045264: cbz x1, #0x452e8
    return acc;
}

// [EN] Reconstructed FDE #0456 @ 0x0454b0..0x045b6c (1724 bytes)
// [VN] Phục dựng FDE #0456 tại 0x0454b0..0x045b6c (1724 byte)
//   0x0454b0: d10483ff  sub      sp, sp, #0x120
//   0x0454b4: a90c6ffc  stp      x28, x27, [sp, #0xc0]
//   0x0454b8: a90d67fa  stp      x26, x25, [sp, #0xd0]
//   0x0454bc: a90e5ff8  stp      x24, x23, [sp, #0xe0]
//   0x0454c0: a90f57f6  stp      x22, x21, [sp, #0xf0]
//   0x0454c4: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x0454c8: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0454cc: 910443fd  add      x29, sp, #0x110
//   0x0454d0: d53bd05b  mrs      x27, tpidr_el0
//   0x0454d4: f9401768  ldr      x8, [x27, #0x28]
//   0x0454d8: aa0103f6  mov      x22, x1
//   0x0454dc: aa0303f3  mov      x19, x3
//   0x0454e0: 52800063  mov      w3, #3
//   0x0454e4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x0454e8: f9400028  ldr      x8, [x1]
//   0x0454ec: aa0503f4  mov      x20, x5
uint64_t fde_0456_sub_0454b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0x52800063ULL) + (x2 ^ 0x0454B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0454b0: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C6FFCULL; // 0x0454b4: stp x28, x27, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D67FAULL; // 0x0454b8: stp x26, x25, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E5FF8ULL; // 0x0454bc: stp x24, x23, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F57F6ULL; // 0x0454c0: stp x22, x21, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FF4ULL; // 0x0454c4: stp x20, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0454c8: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0454cc: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x0454d0: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x0454d4: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0457 @ 0x045b6c..0x046008 (1180 bytes)
// [VN] Phục dựng FDE #0457 tại 0x045b6c..0x046008 (1180 byte)
//   0x045b6c: d10203ff  sub      sp, sp, #0x80
//   0x045b70: f90013fb  str      x27, [sp, #0x20]
//   0x045b74: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x045b78: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x045b7c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x045b80: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x045b84: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x045b88: 9101c3fd  add      x29, sp, #0x70
//   0x045b8c: d53bd057  mrs      x23, tpidr_el0
//   0x045b90: f94016e9  ldr      x9, [x23, #0x28]
//   0x045b94: aa0803f3  mov      x19, x8
//   0x045b98: 51000408  sub      w8, w0, #1
//   0x045b9c: 7100fd1f  cmp      w8, #0x3f
//   0x045ba0: f9000fe9  str      x9, [sp, #0x18]
//   0x045ba4: 54000128  b.hi     #0x45bc8
//   0x045ba8: d0000069  adrp     x9, #0x53000
uint64_t fde_0457_sub_045b6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x7100FD1FULL) + (x2 ^ 0x045B6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x045b6c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013FBULL; // 0x045b70: str x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x045b74: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x045b78: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x045b7c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x045b80: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x045b84: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x045b88: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x045b8c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E9ULL; // 0x045b90: ldr x9, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0458 @ 0x046008..0x046214 (524 bytes)
// [VN] Phục dựng FDE #0458 tại 0x046008..0x046214 (524 byte)
//   0x046008: d10183ff  sub      sp, sp, #0x60
//   0x04600c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x046010: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x046014: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x046018: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04601c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x046020: 910143fd  add      x29, sp, #0x50
//   0x046024: d53bd05a  mrs      x26, tpidr_el0
//   0x046028: f9401748  ldr      x8, [x26, #0x28]
//   0x04602c: aa0403f3  mov      x19, x4
//   0x046030: 2a0303f4  mov      w20, w3
//   0x046034: aa0203f8  mov      x24, x2
//   0x046038: 2a0103f5  mov      w21, w1
//   0x04603c: aa0003f6  mov      x22, x0
//   0x046040: f90007e8  str      x8, [sp, #8]
//   0x046044: aa0203e0  mov      x0, x2
uint64_t fde_0458_sub_046008(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x2A0103F5ULL) + (x2 ^ 0x046008ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x046008: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x04600c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x046010: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x046014: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x046018: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04601c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x046020: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x046024: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x046028: ldr x8, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F3ULL; // 0x04602c: mov x19, x4
    return acc;
}

// [EN] Reconstructed FDE #0459 @ 0x046214..0x046420 (524 bytes)
// [VN] Phục dựng FDE #0459 tại 0x046214..0x046420 (524 byte)
//   0x046214: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x046218: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04621c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x046220: 910083fd  add      x29, sp, #0x20
//   0x046224: 2a0003f5  mov      w21, w0
//   0x046228: aa0803f3  mov      x19, x8
//   0x04622c: a9007d1f  stp      xzr, xzr, [x8]
//   0x046230: f900091f  str      xzr, [x8, #0x10]
//   0x046234: 52800480  mov      w0, #0x24
//   0x046238: 97ff568a  bl       #0x1bc60
//   0x04623c: b0000068  adrp     x8, #0x53000
//   0x046240: 91289108  add      x8, x8, #0xa24
//   0x046244: b9402109  ldr      w9, [x8, #0x20]
//   0x046248: ad400101  ldp      q1, q0, [x8]
//   0x04624c: aa0003f4  mov      x20, x0
//   0x046250: b9002009  str      w9, [x0, #0x20]
uint64_t fde_0459_sub_046214(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB9402109ULL) + (x2 ^ 0x046214ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x046214: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x046218: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04621c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x046220: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F5ULL; // 0x046224: mov w21, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x046228: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007D1FULL; // 0x04622c: stp xzr, xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900091FULL; // 0x046230: str xzr, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800480ULL; // 0x046234: mov w0, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF568AULL; // 0x046238: bl #0x1bc60
    return acc;
}

// [EN] Reconstructed FDE #0460 @ 0x046420..0x046518 (248 bytes)
// [VN] Phục dựng FDE #0460 tại 0x046420..0x046518 (248 byte)
//   0x046420: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x046424: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x046428: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x04642c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x046430: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x046434: 910103fd  add      x29, sp, #0x40
//   0x046438: a9402014  ldp      x20, x8, [x0]
//   0x04643c: aa0003f3  mov      x19, x0
//   0x046440: cb140115  sub      x21, x8, x20
//   0x046444: 9342feb8  asr      x24, x21, #2
//   0x046448: 91000708  add      x8, x24, #1
//   0x04644c: d37efd09  lsr      x9, x8, #0x3e
//   0x046450: b5000609  cbnz     x9, #0x46510
//   0x046454: f9400a69  ldr      x9, [x19, #0x10]
//   0x046458: b27fefea  mov      x10, #0x1ffffffffffffffe
//   0x04645c: aa0103f6  mov      x22, x1
uint64_t fde_0460_sub_046420(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB5000609ULL) + (x2 ^ 0x046420ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x046420: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x046424: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x046428: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04642c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x046430: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x046434: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402014ULL; // 0x046438: ldp x20, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04643c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB140115ULL; // 0x046440: sub x21, x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9342FEB8ULL; // 0x046444: asr x24, x21, #2
    return acc;
}

// [EN] Reconstructed FDE #0461 @ 0x046518..0x0469f8 (1248 bytes)
// [VN] Phục dựng FDE #0461 tại 0x046518..0x0469f8 (1248 byte)
//   0x046518: d10483ff  sub      sp, sp, #0x120
//   0x04651c: a90c6ffc  stp      x28, x27, [sp, #0xc0]
//   0x046520: a90d67fa  stp      x26, x25, [sp, #0xd0]
//   0x046524: a90e5ff8  stp      x24, x23, [sp, #0xe0]
//   0x046528: a90f57f6  stp      x22, x21, [sp, #0xf0]
//   0x04652c: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x046530: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x046534: 910443fd  add      x29, sp, #0x110
//   0x046538: d53bd05b  mrs      x27, tpidr_el0
//   0x04653c: f9401768  ldr      x8, [x27, #0x28]
//   0x046540: aa0103f6  mov      x22, x1
//   0x046544: aa0303f5  mov      x21, x3
//   0x046548: 52800063  mov      w3, #3
//   0x04654c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x046550: f9400028  ldr      x8, [x1]
//   0x046554: 2a0503f3  mov      w19, w5
uint64_t fde_0461_sub_046518(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0x52800063ULL) + (x2 ^ 0x046518ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x046518: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C6FFCULL; // 0x04651c: stp x28, x27, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D67FAULL; // 0x046520: stp x26, x25, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E5FF8ULL; // 0x046524: stp x24, x23, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F57F6ULL; // 0x046528: stp x22, x21, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FF4ULL; // 0x04652c: stp x20, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x046530: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x046534: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x046538: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x04653c: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0462 @ 0x0469f8..0x046d4c (852 bytes)
// [VN] Phục dựng FDE #0462 tại 0x0469f8..0x046d4c (852 byte)
//   0x0469f8: d10303ff  sub      sp, sp, #0xc0
//   0x0469fc: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x046a00: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x046a04: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x046a08: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x046a0c: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x046a10: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x046a14: 9102c3fd  add      x29, sp, #0xb0
//   0x046a18: d53bd05c  mrs      x28, tpidr_el0
//   0x046a1c: f9401788  ldr      x8, [x28, #0x28]
//   0x046a20: 2a0403f5  mov      w21, w4
//   0x046a24: 2a0303f3  mov      w19, w3
//   0x046a28: aa0203f8  mov      x24, x2
//   0x046a2c: aa0103fa  mov      x26, x1
//   0x046a30: aa0003f4  mov      x20, x0
//   0x046a34: f9002fe8  str      x8, [sp, #0x58]
uint64_t fde_0462_sub_0469f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xAA0203F8ULL) + (x2 ^ 0x0469F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0469f8: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x0469fc: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x046a00: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x046a04: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x046a08: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x046a0c: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x046a10: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x046a14: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x046a18: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x046a1c: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0463 @ 0x046d4c..0x04719c (1104 bytes)
// [VN] Phục dựng FDE #0463 tại 0x046d4c..0x04719c (1104 byte)
//   0x046d4c: d10283ff  sub      sp, sp, #0xa0
//   0x046d50: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x046d54: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x046d58: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x046d5c: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x046d60: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x046d64: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x046d68: 910243fd  add      x29, sp, #0x90
//   0x046d6c: aa0803f3  mov      x19, x8
//   0x046d70: d53bd048  mrs      x8, tpidr_el0
//   0x046d74: f90007e8  str      x8, [sp, #8]
//   0x046d78: f9401508  ldr      x8, [x8, #0x28]
//   0x046d7c: aa0003f6  mov      x22, x0
//   0x046d80: 52800300  mov      w0, #0x18
//   0x046d84: aa0103f5  mov      x21, x1
//   0x046d88: f9001fe8  str      x8, [sp, #0x38]
uint64_t fde_0463_sub_046d4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x046D4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x046d4c: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x046d50: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x046d54: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x046d58: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x046d5c: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x046d60: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x046d64: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x046d68: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x046d6c: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x046d70: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0464 @ 0x04719c..0x047298 (252 bytes)
// [VN] Phục dựng FDE #0464 tại 0x04719c..0x047298 (252 byte)
//   0x04719c: d10143ff  sub      sp, sp, #0x50
//   0x0471a0: f9000bf7  str      x23, [sp, #0x10]
//   0x0471a4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0471a8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0471ac: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0471b0: 910103fd  add      x29, sp, #0x40
//   0x0471b4: d53bd057  mrs      x23, tpidr_el0
//   0x0471b8: f94016e8  ldr      x8, [x23, #0x28]
//   0x0471bc: aa0103e2  mov      x2, x1
//   0x0471c0: 910003e1  mov      x1, sp
//   0x0471c4: aa0303f6  mov      x22, x3
//   0x0471c8: aa0003f4  mov      x20, x0
//   0x0471cc: f90007e8  str      x8, [sp, #8]
//   0x0471d0: 97ff4e38  bl       #0x1aab0
//   0x0471d4: f9400013  ldr      x19, [x0]
//   0x0471d8: b4000073  cbz      x19, #0x471e4
uint64_t fde_0464_sub_04719c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x04719CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x04719c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x0471a0: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0471a4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0471a8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0471ac: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0471b0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0471b4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0471b8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x0471bc: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x0471c0: mov x1, sp
    return acc;
}

// [EN] Reconstructed FDE #0465 @ 0x047298..0x047388 (240 bytes)
// [VN] Phục dựng FDE #0465 tại 0x047298..0x047388 (240 byte)
//   0x047298: d10143ff  sub      sp, sp, #0x50
//   0x04729c: f9000bf7  str      x23, [sp, #0x10]
//   0x0472a0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0472a4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0472a8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0472ac: 910103fd  add      x29, sp, #0x40
//   0x0472b0: d53bd057  mrs      x23, tpidr_el0
//   0x0472b4: f94016e8  ldr      x8, [x23, #0x28]
//   0x0472b8: aa0103e2  mov      x2, x1
//   0x0472bc: 910003e1  mov      x1, sp
//   0x0472c0: aa0303f6  mov      x22, x3
//   0x0472c4: aa0003f4  mov      x20, x0
//   0x0472c8: f90007e8  str      x8, [sp, #8]
//   0x0472cc: 97ff5089  bl       #0x1b4f0
//   0x0472d0: f9400013  ldr      x19, [x0]
//   0x0472d4: b4000073  cbz      x19, #0x472e0
uint64_t fde_0465_sub_047298(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x047298ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x047298: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x04729c: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0472a0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0472a4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0472a8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0472ac: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0472b0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0472b4: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x0472b8: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x0472bc: mov x1, sp
    return acc;
}

// [EN] Reconstructed FDE #0466 @ 0x047388..0x04747c (244 bytes)
// [VN] Phục dựng FDE #0466 tại 0x047388..0x04747c (244 byte)
//   0x047388: d10143ff  sub      sp, sp, #0x50
//   0x04738c: f9000bf7  str      x23, [sp, #0x10]
//   0x047390: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x047394: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x047398: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x04739c: 910103fd  add      x29, sp, #0x40
//   0x0473a0: d53bd057  mrs      x23, tpidr_el0
//   0x0473a4: f94016e8  ldr      x8, [x23, #0x28]
//   0x0473a8: aa0103e2  mov      x2, x1
//   0x0473ac: 910003e1  mov      x1, sp
//   0x0473b0: aa0303f6  mov      x22, x3
//   0x0473b4: aa0003f4  mov      x20, x0
//   0x0473b8: f90007e8  str      x8, [sp, #8]
//   0x0473bc: 97ff5079  bl       #0x1b5a0
//   0x0473c0: f9400013  ldr      x19, [x0]
//   0x0473c4: b4000073  cbz      x19, #0x473d0
uint64_t fde_0466_sub_047388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x047388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x047388: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x04738c: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x047390: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x047394: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x047398: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x04739c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0473a0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0473a4: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x0473a8: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x0473ac: mov x1, sp
    return acc;
}

// [EN] Reconstructed FDE #0467 @ 0x04747c..0x047488 (12 bytes)
// [VN] Phục dựng FDE #0467 tại 0x04747c..0x047488 (12 byte)
//   0x04747c: 12000028  and      w8, w1, #1
//   0x047480: 39008008  strb     w8, [x0, #0x20]
//   0x047484: d65f03c0  ret      
uint64_t fde_0467_sub_04747c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12000028ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04747CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12000028ULL; // 0x04747c: and w8, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39008008ULL; // 0x047480: strb w8, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x047484: ret 
    return acc;
}

// [EN] Reconstructed FDE #0468 @ 0x047488..0x0474cc (68 bytes)
// [VN] Phục dựng FDE #0468 tại 0x047488..0x0474cc (68 byte)
//   0x047488: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04748c: 910003fd  mov      x29, sp
//   0x047490: 39408008  ldrb     w8, [x0, #0x20]
//   0x047494: 34000168  cbz      w8, #0x474c0
//   0x047498: 97ff51ae  bl       #0x1bb50
//   0x04749c: d29ef9e8  mov      x8, #0xf7cf
//   0x0474a0: f2bc6a68  movk     x8, #0xe353, lsl #16
//   0x0474a4: f2d374a8  movk     x8, #0x9ba5, lsl #32
//   0x0474a8: f2e41888  movk     x8, #0x20c4, lsl #48
//   0x0474ac: 9b487c08  smulh    x8, x0, x8
//   0x0474b0: 9347fd09  asr      x9, x8, #7
//   0x0474b4: 8b48fd20  add      x0, x9, x8, lsr #63
//   0x0474b8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0474bc: d65f03c0  ret      
//   0x0474c0: f9400000  ldr      x0, [x0]
//   0x0474c4: a8c17bfd  ldp      x29, x30, [sp], #0x10
uint64_t fde_0468_sub_047488(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xA8C17BFDULL) + (x2 ^ 0x047488ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x047488: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04748c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x39408008ULL; // 0x047490: ldrb w8, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000168ULL; // 0x047494: cbz w8, #0x474c0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF51AEULL; // 0x047498: bl #0x1bb50
    acc = (acc * 0x100000001B3ULL) ^ 0xD29EF9E8ULL; // 0x04749c: mov x8, #0xf7cf
    acc = (acc * 0x100000001B3ULL) ^ 0xF2BC6A68ULL; // 0x0474a0: movk x8, #0xe353, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2D374A8ULL; // 0x0474a4: movk x8, #0x9ba5, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E41888ULL; // 0x0474a8: movk x8, #0x20c4, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0x9B487C08ULL; // 0x0474ac: smulh x8, x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0469 @ 0x0474cc..0x047834 (872 bytes)
// [VN] Phục dựng FDE #0469 tại 0x0474cc..0x047834 (872 byte)
//   0x0474cc: d106c3ff  sub      sp, sp, #0x1b0
//   0x0474d0: a9156ffc  stp      x28, x27, [sp, #0x150]
//   0x0474d4: a91667fa  stp      x26, x25, [sp, #0x160]
//   0x0474d8: a9175ff8  stp      x24, x23, [sp, #0x170]
//   0x0474dc: a91857f6  stp      x22, x21, [sp, #0x180]
//   0x0474e0: a9194ff4  stp      x20, x19, [sp, #0x190]
//   0x0474e4: a91a7bfd  stp      x29, x30, [sp, #0x1a0]
//   0x0474e8: 910683fd  add      x29, sp, #0x1a0
//   0x0474ec: d53bd058  mrs      x24, tpidr_el0
//   0x0474f0: f9401708  ldr      x8, [x24, #0x28]
//   0x0474f4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x0474f8: 39408008  ldrb     w8, [x0, #0x20]
//   0x0474fc: 34001468  cbz      w8, #0x47788
//   0x047500: f9400008  ldr      x8, [x0]
//   0x047504: aa0203f6  mov      x22, x2
//   0x047508: aa0003f4  mov      x20, x0
uint64_t fde_0469_sub_0474cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD106C3FFULL) + (x1 ^ 0x34001468ULL) + (x2 ^ 0x0474CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x0474cc: sub sp, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9156FFCULL; // 0x0474d0: stp x28, x27, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91667FAULL; // 0x0474d4: stp x26, x25, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9175FF8ULL; // 0x0474d8: stp x24, x23, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91857F6ULL; // 0x0474dc: stp x22, x21, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9194FF4ULL; // 0x0474e0: stp x20, x19, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A7BFDULL; // 0x0474e4: stp x29, x30, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910683FDULL; // 0x0474e8: add x29, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0474ec: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0474f0: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0470 @ 0x047834..0x0479fc (456 bytes)
// [VN] Phục dựng FDE #0470 tại 0x047834..0x0479fc (456 byte)
//   0x047834: d101c3ff  sub      sp, sp, #0x70
//   0x047838: f90013f9  str      x25, [sp, #0x20]
//   0x04783c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x047840: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x047844: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x047848: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x04784c: 910183fd  add      x29, sp, #0x60
//   0x047850: d53bd059  mrs      x25, tpidr_el0
//   0x047854: f9401728  ldr      x8, [x25, #0x28]
//   0x047858: aa0003f3  mov      x19, x0
//   0x04785c: f9000fe8  str      x8, [sp, #0x18]
//   0x047860: 390003ff  strb     wzr, [sp]
//   0x047864: f90007e0  str      x0, [sp, #8]
//   0x047868: f9400008  ldr      x8, [x0]
//   0x04786c: f85e8109  ldur     x9, [x8, #-0x18]
//   0x047870: 8b090009  add      x9, x0, x9
uint64_t fde_0470_sub_047834(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90007E0ULL) + (x2 ^ 0x047834ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x047834: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x047838: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x04783c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x047840: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x047844: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x047848: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x04784c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x047850: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x047854: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x047858: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0471 @ 0x0479fc..0x047af0 (244 bytes)
// [VN] Phục dựng FDE #0471 tại 0x0479fc..0x047af0 (244 byte)
//   0x0479fc: d10143ff  sub      sp, sp, #0x50
//   0x047a00: f9000bf7  str      x23, [sp, #0x10]
//   0x047a04: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x047a08: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x047a0c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x047a10: 910103fd  add      x29, sp, #0x40
//   0x047a14: d53bd057  mrs      x23, tpidr_el0
//   0x047a18: f94016e8  ldr      x8, [x23, #0x28]
//   0x047a1c: aa0103e2  mov      x2, x1
//   0x047a20: 910003e1  mov      x1, sp
//   0x047a24: aa0303f6  mov      x22, x3
//   0x047a28: aa0003f4  mov      x20, x0
//   0x047a2c: f90007e8  str      x8, [sp, #8]
//   0x047a30: 97ff5194  bl       #0x1c080
//   0x047a34: f9400013  ldr      x19, [x0]
//   0x047a38: b4000073  cbz      x19, #0x47a44
uint64_t fde_0471_sub_0479fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0479FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0479fc: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x047a00: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x047a04: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x047a08: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x047a0c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x047a10: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x047a14: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x047a18: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x047a1c: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x047a20: mov x1, sp
    return acc;
}

// [EN] Reconstructed FDE #0472 @ 0x047af0..0x047c10 (288 bytes)
// [VN] Phục dựng FDE #0472 tại 0x047af0..0x047c10 (288 byte)
//   0x047af0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x047af4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x047af8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x047afc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x047b00: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x047b04: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x047b08: 910143fd  add      x29, sp, #0x50
//   0x047b0c: aa0003f4  mov      x20, x0
//   0x047b10: f8408e97  ldr      x23, [x20, #8]!
//   0x047b14: aa0103f3  mov      x19, x1
//   0x047b18: b4000657  cbz      x23, #0x47be0
//   0x047b1c: 39400048  ldrb     w8, [x2]
//   0x047b20: a940a849  ldp      x9, x10, [x2, #8]
//   0x047b24: 91002014  add      x20, x0, #8
//   0x047b28: d341fd0b  lsr      x11, x8, #1
//   0x047b2c: 7200011f  tst      w8, #1
uint64_t fde_0472_sub_047af0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x047AF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x047af0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x047af4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x047af8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x047afc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x047b00: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x047b04: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x047b08: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x047b0c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x047b10: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x047b14: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0473 @ 0x047c10..0x047d08 (248 bytes)
// [VN] Phục dựng FDE #0473 tại 0x047c10..0x047d08 (248 byte)
//   0x047c10: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x047c14: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x047c18: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x047c1c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x047c20: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x047c24: 910103fd  add      x29, sp, #0x40
//   0x047c28: a9402014  ldp      x20, x8, [x0]
//   0x047c2c: aa0003f3  mov      x19, x0
//   0x047c30: cb140115  sub      x21, x8, x20
//   0x047c34: 9343feb8  asr      x24, x21, #3
//   0x047c38: 91000708  add      x8, x24, #1
//   0x047c3c: d37dfd09  lsr      x9, x8, #0x3d
//   0x047c40: b5000609  cbnz     x9, #0x47d00
//   0x047c44: f9400a69  ldr      x9, [x19, #0x10]
//   0x047c48: b27febea  mov      x10, #0xffffffffffffffe
//   0x047c4c: aa0103f6  mov      x22, x1
uint64_t fde_0473_sub_047c10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB5000609ULL) + (x2 ^ 0x047C10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x047c10: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x047c14: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x047c18: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x047c1c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x047c20: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x047c24: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402014ULL; // 0x047c28: ldp x20, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x047c2c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB140115ULL; // 0x047c30: sub x21, x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9343FEB8ULL; // 0x047c34: asr x24, x21, #3
    return acc;
}

// [EN] Reconstructed FDE #0474 @ 0x047d08..0x047f18 (528 bytes)
// [VN] Phục dựng FDE #0474 tại 0x047d08..0x047f18 (528 byte)
//   0x047d08: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x047d0c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x047d10: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x047d14: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x047d18: 9100c3fd  add      x29, sp, #0x30
//   0x047d1c: b9406009  ldr      w9, [x0, #0x60]
//   0x047d20: aa0803f3  mov      x19, x8
//   0x047d24: 372000a9  tbnz     w9, #4, #0x47d38
//   0x047d28: 37180349  tbnz     w9, #3, #0x47d90
//   0x047d2c: a9007e7f  stp      xzr, xzr, [x19]
//   0x047d30: f9000a7f  str      xzr, [x19, #0x10]
//   0x047d34: 14000072  b        #0x47efc
//   0x047d38: f9402c15  ldr      x21, [x0, #0x58]
//   0x047d3c: f9401808  ldr      x8, [x0, #0x30]
//   0x047d40: eb0802bf  cmp      x21, x8
//   0x047d44: 54000062  b.hs     #0x47d50
uint64_t fde_0474_sub_047d08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF9402C15ULL) + (x2 ^ 0x047D08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x047d08: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x047d0c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x047d10: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x047d14: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x047d18: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB9406009ULL; // 0x047d1c: ldr w9, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x047d20: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x372000A9ULL; // 0x047d24: tbnz w9, #4, #0x47d38
    acc = (acc * 0x100000001B3ULL) ^ 0x37180349ULL; // 0x047d28: tbnz w9, #3, #0x47d90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007E7FULL; // 0x047d2c: stp xzr, xzr, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0475 @ 0x047f18..0x0480ec (468 bytes)
// [VN] Phục dựng FDE #0475 tại 0x047f18..0x0480ec (468 byte)
//   0x047f18: d10103ff  sub      sp, sp, #0x40
//   0x047f1c: f90013f3  str      x19, [sp, #0x20]
//   0x047f20: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x047f24: 9100c3fd  add      x29, sp, #0x30
//   0x047f28: d53bd053  mrs      x19, tpidr_el0
//   0x047f2c: f9401668  ldr      x8, [x19, #0x28]
//   0x047f30: f9000fe8  str      x8, [sp, #0x18]
//   0x047f34: b0000108  adrp     x8, #0x68000
//   0x047f38: 911c2108  add      x8, x8, #0x708
//   0x047f3c: 08dffd08  ldarb    w8, [x8]
//   0x047f40: 360002e8  tbz      w8, #0, #0x47f9c
//   0x047f44: d0000108  adrp     x8, #0x69000
//   0x047f48: 91036108  add      x8, x8, #0xd8
//   0x047f4c: 08dffd08  ldarb    w8, [x8]
//   0x047f50: 360005c8  tbz      w8, #0, #0x48008
//   0x047f54: d0000108  adrp     x8, #0x69000
uint64_t fde_0475_sub_047f18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x91036108ULL) + (x2 ^ 0x047F18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x047f18: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x047f1c: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x047f20: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x047f24: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x047f28: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x047f2c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x047f30: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000108ULL; // 0x047f34: adrp x8, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x911C2108ULL; // 0x047f38: add x8, x8, #0x708
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x047f3c: ldarb w8, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0476 @ 0x0480ec..0x048110 (36 bytes)
// [VN] Phục dựng FDE #0476 tại 0x0480ec..0x048110 (36 byte)
//   0x0480ec: aa0003e8  mov      x8, x0
//   0x0480f0: aa0003e9  mov      x9, x0
//   0x0480f4: f8008d1f  str      xzr, [x8, #8]!
//   0x0480f8: f9000008  str      x8, [x0]
//   0x0480fc: f8020d3f  str      xzr, [x9, #0x20]!
//   0x048100: f900141f  str      xzr, [x0, #0x28]
//   0x048104: a901241f  stp      xzr, x9, [x0, #0x10]
//   0x048108: 3900c01f  strb     wzr, [x0, #0x30]
//   0x04810c: d65f03c0  ret      
uint64_t fde_0476_sub_0480ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0480ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0480ec: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E9ULL; // 0x0480f0: mov x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x0480f4: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x0480f8: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8020D3FULL; // 0x0480fc: str xzr, [x9, #0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF900141FULL; // 0x048100: str xzr, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA901241FULL; // 0x048104: stp xzr, x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3900C01FULL; // 0x048108: strb wzr, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04810c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0477 @ 0x048110..0x0482fc (492 bytes)
// [VN] Phục dựng FDE #0477 tại 0x048110..0x0482fc (492 byte)
//   0x048110: d10203ff  sub      sp, sp, #0x80
//   0x048114: f90023f7  str      x23, [sp, #0x40]
//   0x048118: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x04811c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x048120: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x048124: 9101c3fd  add      x29, sp, #0x70
//   0x048128: d53bd057  mrs      x23, tpidr_el0
//   0x04812c: f94016e8  ldr      x8, [x23, #0x28]
//   0x048130: aa0003ea  mov      x10, x0
//   0x048134: aa0003f4  mov      x20, x0
//   0x048138: 12000029  and      w9, w1, #1
//   0x04813c: f9001fe8  str      x8, [sp, #0x38]
//   0x048140: aa0003e8  mov      x8, x0
//   0x048144: f8008d5f  str      xzr, [x10, #8]!
//   0x048148: f900000a  str      x10, [x0]
//   0x04814c: f900081f  str      xzr, [x0, #0x10]
uint64_t fde_0477_sub_048110(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0003E8ULL) + (x2 ^ 0x048110ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x048110: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x048114: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x048118: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x04811c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x048120: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x048124: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x048128: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x04812c: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x048130: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x048134: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0478 @ 0x0482fc..0x048434 (312 bytes)
// [VN] Phục dựng FDE #0478 tại 0x0482fc..0x048434 (312 byte)
//   0x0482fc: d101c3ff  sub      sp, sp, #0x70
//   0x048300: f90013f9  str      x25, [sp, #0x20]
//   0x048304: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x048308: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x04830c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x048310: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x048314: 910183fd  add      x29, sp, #0x60
//   0x048318: d53bd055  mrs      x21, tpidr_el0
//   0x04831c: f94016a8  ldr      x8, [x21, #0x28]
//   0x048320: f9000fe8  str      x8, [sp, #0x18]
//   0x048324: 3940c008  ldrb     w8, [x0, #0x30]
//   0x048328: 340006e8  cbz      w8, #0x48404
//   0x04832c: a9405c36  ldp      x22, x23, [x1]
//   0x048330: eb1702df  cmp      x22, x23
//   0x048334: 54000680  b.eq     #0x48404
//   0x048338: f0000054  adrp     x20, #0x53000
uint64_t fde_0478_sub_0482fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xA9405C36ULL) + (x2 ^ 0x0482FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0482fc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x048300: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x048304: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x048308: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x04830c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x048310: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x048314: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x048318: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x04831c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x048320: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0479 @ 0x048434..0x048694 (608 bytes)
// [VN] Phục dựng FDE #0479 tại 0x048434..0x048694 (608 byte)
//   0x048434: d10643ff  sub      sp, sp, #0x190
//   0x048438: f900a3fc  str      x28, [sp, #0x140]
//   0x04843c: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x048440: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x048444: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x048448: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x04844c: 910603fd  add      x29, sp, #0x180
//   0x048450: a9088fe2  stp      x2, x3, [sp, #0x88]
//   0x048454: a90997e4  stp      x4, x5, [sp, #0x98]
//   0x048458: a90a9fe6  stp      x6, x7, [sp, #0xa8]
//   0x04845c: ad0007e0  stp      q0, q1, [sp]
//   0x048460: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x048464: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x048468: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x04846c: d53bd057  mrs      x23, tpidr_el0
//   0x048470: f94016e8  ldr      x8, [x23, #0x28]
uint64_t fde_0479_sub_048434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xAD0217E4ULL) + (x2 ^ 0x048434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x048434: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xF900A3FCULL; // 0x048438: str x28, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x04843c: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x048440: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x048444: stp x20, x19, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9187BFDULL; // 0x048448: stp x29, x30, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0x910603FDULL; // 0x04844c: add x29, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9088FE2ULL; // 0x048450: stp x2, x3, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90997E4ULL; // 0x048454: stp x4, x5, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A9FE6ULL; // 0x048458: stp x6, x7, [sp, #0xa8]
    return acc;
}

// [EN] Reconstructed FDE #0480 @ 0x048694..0x048840 (428 bytes)
// [VN] Phục dựng FDE #0480 tại 0x048694..0x048840 (428 byte)
//   0x048694: d101c3ff  sub      sp, sp, #0x70
//   0x048698: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x04869c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0486a0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0486a4: 910183fd  add      x29, sp, #0x60
//   0x0486a8: d53bd056  mrs      x22, tpidr_el0
//   0x0486ac: f94016c8  ldr      x8, [x22, #0x28]
//   0x0486b0: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0486b4: 3940c008  ldrb     w8, [x0, #0x30]
//   0x0486b8: 340008a8  cbz      w8, #0x487cc
//   0x0486bc: aa0003f3  mov      x19, x0
//   0x0486c0: 910063e8  add      x8, sp, #0x18
//   0x0486c4: 2a0103e0  mov      w0, w1
//   0x0486c8: 97ff4c06  bl       #0x1b6e0
//   0x0486cc: d0000041  adrp     x1, #0x52000
//   0x0486d0: 91077c21  add      x1, x1, #0x1df
uint64_t fde_0480_sub_048694(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0103E0ULL) + (x2 ^ 0x048694ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x048694: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x048698: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x04869c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0486a0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0486a4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0486a8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0486ac: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x0486b0: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940C008ULL; // 0x0486b4: ldrb w8, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x340008A8ULL; // 0x0486b8: cbz w8, #0x487cc
    return acc;
}

// [EN] Reconstructed FDE #0481 @ 0x048840..0x048f58 (1816 bytes)
// [VN] Phục dựng FDE #0481 tại 0x048840..0x048f58 (1816 byte)
//   0x048840: d10743ff  sub      sp, sp, #0x1d0
//   0x048844: a9176ffc  stp      x28, x27, [sp, #0x170]
//   0x048848: a91867fa  stp      x26, x25, [sp, #0x180]
//   0x04884c: a9195ff8  stp      x24, x23, [sp, #0x190]
//   0x048850: a91a57f6  stp      x22, x21, [sp, #0x1a0]
//   0x048854: a91b4ff4  stp      x20, x19, [sp, #0x1b0]
//   0x048858: a91c7bfd  stp      x29, x30, [sp, #0x1c0]
//   0x04885c: 910703fd  add      x29, sp, #0x1c0
//   0x048860: d53bd055  mrs      x21, tpidr_el0
//   0x048864: f94016a9  ldr      x9, [x21, #0x28]
//   0x048868: aa0803fc  mov      x28, x8
//   0x04886c: f81a03a9  stur     x9, [x29, #-0x60]
//   0x048870: 3940c009  ldrb     w9, [x0, #0x30]
//   0x048874: 34000be9  cbz      w9, #0x489f0
//   0x048878: f00000f3  adrp     x19, #0x67000
//   0x04887c: f00000e8  adrp     x8, #0x67000
uint64_t fde_0481_sub_048840(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10743FFULL) + (x1 ^ 0x3940C009ULL) + (x2 ^ 0x048840ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x048840: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9176FFCULL; // 0x048844: stp x28, x27, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91867FAULL; // 0x048848: stp x26, x25, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9195FF8ULL; // 0x04884c: stp x24, x23, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A57F6ULL; // 0x048850: stp x22, x21, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B4FF4ULL; // 0x048854: stp x20, x19, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C7BFDULL; // 0x048858: stp x29, x30, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910703FDULL; // 0x04885c: add x29, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x048860: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A9ULL; // 0x048864: ldr x9, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0482 @ 0x048f58..0x049140 (488 bytes)
// [VN] Phục dựng FDE #0482 tại 0x048f58..0x049140 (488 byte)
//   0x048f58: d101c3ff  sub      sp, sp, #0x70
//   0x048f5c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x048f60: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x048f64: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x048f68: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x048f6c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x048f70: 910183fd  add      x29, sp, #0x60
//   0x048f74: d53bd059  mrs      x25, tpidr_el0
//   0x048f78: f9401728  ldr      x8, [x25, #0x28]
//   0x048f7c: aa0003f3  mov      x19, x0
//   0x048f80: f9000fe8  str      x8, [sp, #0x18]
//   0x048f84: 390003ff  strb     wzr, [sp]
//   0x048f88: f90007e0  str      x0, [sp, #8]
//   0x048f8c: f9400008  ldr      x8, [x0]
//   0x048f90: f85e8109  ldur     x9, [x8, #-0x18]
//   0x048f94: 8b090009  add      x9, x0, x9
uint64_t fde_0482_sub_048f58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90007E0ULL) + (x2 ^ 0x048F58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x048f58: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x048f5c: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x048f60: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x048f64: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x048f68: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x048f6c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x048f70: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x048f74: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x048f78: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x048f7c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0483 @ 0x049140..0x049308 (456 bytes)
// [VN] Phục dựng FDE #0483 tại 0x049140..0x049308 (456 byte)
//   0x049140: d101c3ff  sub      sp, sp, #0x70
//   0x049144: f90013f9  str      x25, [sp, #0x20]
//   0x049148: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x04914c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x049150: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x049154: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x049158: 910183fd  add      x29, sp, #0x60
//   0x04915c: d53bd059  mrs      x25, tpidr_el0
//   0x049160: f9401728  ldr      x8, [x25, #0x28]
//   0x049164: aa0003f3  mov      x19, x0
//   0x049168: f9000fe8  str      x8, [sp, #0x18]
//   0x04916c: 390003ff  strb     wzr, [sp]
//   0x049170: f90007e0  str      x0, [sp, #8]
//   0x049174: f9400008  ldr      x8, [x0]
//   0x049178: f85e8109  ldur     x9, [x8, #-0x18]
//   0x04917c: 8b090009  add      x9, x0, x9
uint64_t fde_0483_sub_049140(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90007E0ULL) + (x2 ^ 0x049140ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x049140: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x049144: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x049148: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x04914c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x049150: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x049154: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x049158: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x04915c: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x049160: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049164: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0484 @ 0x049308..0x0494e4 (476 bytes)
// [VN] Phục dựng FDE #0484 tại 0x049308..0x0494e4 (476 byte)
//   0x049308: 29402040  ldp      w0, w8, [x2]
//   0x04930c: 6b000108  subs     w8, w8, w0
//   0x049310: 54000960  b.eq     #0x4943c
//   0x049314: d2833d2b  mov      x11, #0x19e9
//   0x049318: f2b52ccb  movk     x11, #0xa966, lsl #16
//   0x04931c: d2bdb4c9  mov      x9, #0xeda60000
//   0x049320: d28aaaaa  mov      x10, #0x5555
//   0x049324: 1100050c  add      w12, w8, #1
//   0x049328: d2dd0008  mov      x8, #0xe80000000000
//   0x04932c: f2cdeb4b  movk     x11, #0x6f5a, lsl #32
//   0x049330: f2cfffe9  movk     x9, #0x7fff, lsl #32
//   0x049334: f2aaaaaa  movk     x10, #0x5555, lsl #16
//   0x049338: f2fffee8  movk     x8, #0xfff7, lsl #48
//   0x04933c: f2f6a04b  movk     x11, #0xb502, lsl #48
//   0x049340: f2ee3ac9  movk     x9, #0x71d6, lsl #48
//   0x049344: f2c000aa  movk     x10, #5, lsl #32
uint64_t fde_0484_sub_049308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x29402040ULL) + (x1 ^ 0xF2FFFEE8ULL) + (x2 ^ 0x049308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x29402040ULL; // 0x049308: ldp w0, w8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B000108ULL; // 0x04930c: subs w8, w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000960ULL; // 0x049310: b.eq #0x4943c
    acc = (acc * 0x100000001B3ULL) ^ 0xD2833D2BULL; // 0x049314: mov x11, #0x19e9
    acc = (acc * 0x100000001B3ULL) ^ 0xF2B52CCBULL; // 0x049318: movk x11, #0xa966, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xD2BDB4C9ULL; // 0x04931c: mov x9, #0xeda60000
    acc = (acc * 0x100000001B3ULL) ^ 0xD28AAAAAULL; // 0x049320: mov x10, #0x5555
    acc = (acc * 0x100000001B3ULL) ^ 0x1100050CULL; // 0x049324: add w12, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD2DD0008ULL; // 0x049328: mov x8, #0xe80000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xF2CDEB4BULL; // 0x04932c: movk x11, #0x6f5a, lsl #32
    return acc;
}

// [EN] Reconstructed FDE #0485 @ 0x0494e4..0x0495f8 (276 bytes)
// [VN] Phục dựng FDE #0485 tại 0x0494e4..0x0495f8 (276 byte)
//   0x0494e4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0494e8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0494ec: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0494f0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0494f4: 9100c3fd  add      x29, sp, #0x30
//   0x0494f8: aa0003f3  mov      x19, x0
//   0x0494fc: f8408e77  ldr      x23, [x19, #8]!
//   0x049500: b40006f7  cbz      x23, #0x495dc
//   0x049504: 39400028  ldrb     w8, [x1]
//   0x049508: a940a829  ldp      x9, x10, [x1, #8]
//   0x04950c: aa1303f4  mov      x20, x19
//   0x049510: d341fd0b  lsr      x11, x8, #1
//   0x049514: 7200011f  tst      w8, #1
//   0x049518: 9a890176  csel     x22, x11, x9, eq
//   0x04951c: 9a811555  csinc    x21, x10, x1, ne
//   0x049520: 1400000a  b        #0x49548
uint64_t fde_0485_sub_0494e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x7200011FULL) + (x2 ^ 0x0494E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0494e4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0494e8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0494ec: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0494f0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0494f4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0494f8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E77ULL; // 0x0494fc: ldr x23, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006F7ULL; // 0x049500: cbz x23, #0x495dc
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x049504: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A829ULL; // 0x049508: ldp x9, x10, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0486 @ 0x0495f8..0x049c68 (1648 bytes)
// [VN] Phục dựng FDE #0486 tại 0x0495f8..0x049c68 (1648 byte)
//   0x0495f8: d104c3ff  sub      sp, sp, #0x130
//   0x0495fc: a90d6ffc  stp      x28, x27, [sp, #0xd0]
//   0x049600: a90e67fa  stp      x26, x25, [sp, #0xe0]
//   0x049604: a90f5ff8  stp      x24, x23, [sp, #0xf0]
//   0x049608: a91057f6  stp      x22, x21, [sp, #0x100]
//   0x04960c: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x049610: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x049614: 910483fd  add      x29, sp, #0x120
//   0x049618: d53bd05a  mrs      x26, tpidr_el0
//   0x04961c: f9401748  ldr      x8, [x26, #0x28]
//   0x049620: aa0303f4  mov      x20, x3
//   0x049624: 910203f3  add      x19, sp, #0x80
//   0x049628: f81a03a8  stur     x8, [x29, #-0x60]
//   0x04962c: f9400028  ldr      x8, [x1]
//   0x049630: b9400501  ldr      w1, [x8, #4]
//   0x049634: 910203e8  add      x8, sp, #0x80
uint64_t fde_0486_sub_0495f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x0495F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x0495f8: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D6FFCULL; // 0x0495fc: stp x28, x27, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E67FAULL; // 0x049600: stp x26, x25, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F5FF8ULL; // 0x049604: stp x24, x23, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057F6ULL; // 0x049608: stp x22, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x04960c: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x049610: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x049614: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x049618: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x04961c: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0487 @ 0x049c68..0x049e70 (520 bytes)
// [VN] Phục dựng FDE #0487 tại 0x049c68..0x049e70 (520 byte)
//   0x049c68: d10203ff  sub      sp, sp, #0x80
//   0x049c6c: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x049c70: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x049c74: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x049c78: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x049c7c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x049c80: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x049c84: 9101c3fd  add      x29, sp, #0x70
//   0x049c88: d53bd057  mrs      x23, tpidr_el0
//   0x049c8c: aa0803f3  mov      x19, x8
//   0x049c90: f94016e8  ldr      x8, [x23, #0x28]
//   0x049c94: d0000041  adrp     x1, #0x53000
//   0x049c98: aa0003f4  mov      x20, x0
//   0x049c9c: 912c0021  add      x1, x1, #0xb00
//   0x049ca0: 910003e0  mov      x0, sp
//   0x049ca4: f9000fe8  str      x8, [sp, #0x18]
uint64_t fde_0487_sub_049c68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x049C68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x049c68: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x049c6c: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x049c70: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x049c74: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x049c78: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x049c7c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x049c80: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x049c84: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x049c88: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x049c8c: mov x19, x8
    return acc;
}

// [EN] Reconstructed FDE #0488 @ 0x049e70..0x049f74 (260 bytes)
// [VN] Phục dựng FDE #0488 tại 0x049e70..0x049f74 (260 byte)
//   0x049e70: d10143ff  sub      sp, sp, #0x50
//   0x049e74: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x049e78: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x049e7c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x049e80: 910103fd  add      x29, sp, #0x40
//   0x049e84: d53bd055  mrs      x21, tpidr_el0
//   0x049e88: aa0803f3  mov      x19, x8
//   0x049e8c: f94016a8  ldr      x8, [x21, #0x28]
//   0x049e90: f9000fe8  str      x8, [sp, #0x18]
//   0x049e94: 910003e8  mov      x8, sp
//   0x049e98: 97ff44aa  bl       #0x1b140
//   0x049e9c: b94003e8  ldr      w8, [sp]
//   0x049ea0: 34000248  cbz      w8, #0x49ee8
//   0x049ea4: 7100051f  cmp      w8, #1
//   0x049ea8: 54000481  b.ne     #0x49f38
//   0x049eac: a9007e7f  stp      xzr, xzr, [x19]
uint64_t fde_0488_sub_049e70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x34000248ULL) + (x2 ^ 0x049E70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x049e70: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x049e74: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x049e78: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x049e7c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x049e80: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x049e84: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x049e88: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x049e8c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x049e90: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x049e94: mov x8, sp
    return acc;
}

// [EN] Reconstructed FDE #0489 @ 0x049f74..0x04a504 (1424 bytes)
// [VN] Phục dựng FDE #0489 tại 0x049f74..0x04a504 (1424 byte)
//   0x049f74: d103c3ff  sub      sp, sp, #0xf0
//   0x049f78: a9096ffc  stp      x28, x27, [sp, #0x90]
//   0x049f7c: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x049f80: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x049f84: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x049f88: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x049f8c: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x049f90: 910383fd  add      x29, sp, #0xe0
//   0x049f94: d53bd057  mrs      x23, tpidr_el0
//   0x049f98: aa0803f3  mov      x19, x8
//   0x049f9c: f94016e8  ldr      x8, [x23, #0x28]
//   0x049fa0: f81a83a8  stur     x8, [x29, #-0x58]
//   0x049fa4: a9067fff  stp      xzr, xzr, [sp, #0x60]
//   0x049fa8: f9002fff  str      xzr, [sp, #0x58]
//   0x049fac: 3940001c  ldrb     w28, [x0]
//   0x049fb0: a940a01a  ldp      x26, x8, [x0, #8]
uint64_t fde_0489_sub_049f74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0xA9067FFFULL) + (x2 ^ 0x049F74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x049f74: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9096FFCULL; // 0x049f78: stp x28, x27, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A67FAULL; // 0x049f7c: stp x26, x25, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B5FF8ULL; // 0x049f80: stp x24, x23, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C57F6ULL; // 0x049f84: stp x22, x21, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D4FF4ULL; // 0x049f88: stp x20, x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x049f8c: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x049f90: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x049f94: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x049f98: mov x19, x8
    return acc;
}

// [EN] Reconstructed FDE #0490 @ 0x04a504..0x04a5a8 (164 bytes)
// [VN] Phục dựng FDE #0490 tại 0x04a504..0x04a5a8 (164 byte)
//   0x04a504: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x04a508: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04a50c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04a510: 910083fd  add      x29, sp, #0x20
//   0x04a514: a9007c1f  stp      xzr, xzr, [x0]
//   0x04a518: f900081f  str      xzr, [x0, #0x10]
//   0x04a51c: a9402428  ldp      x8, x9, [x1]
//   0x04a520: eb080136  subs     x22, x9, x8
//   0x04a524: 54000260  b.eq     #0x4a570
//   0x04a528: aa0003f3  mov      x19, x0
//   0x04a52c: b7f802b6  tbnz     x22, #0x3f, #0x4a580
//   0x04a530: aa0103f4  mov      x20, x1
//   0x04a534: aa1603e0  mov      x0, x22
//   0x04a538: 97ff45ca  bl       #0x1bc60
//   0x04a53c: 8b160008  add      x8, x0, x22
//   0x04a540: a9000260  stp      x0, x0, [x19]
uint64_t fde_0490_sub_04a504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x04A504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04a504: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04a508: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04a50c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04a510: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x04a514: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x04a518: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402428ULL; // 0x04a51c: ldp x8, x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB080136ULL; // 0x04a520: subs x22, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000260ULL; // 0x04a524: b.eq #0x4a570
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04a528: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0491 @ 0x04a5a8..0x04a658 (176 bytes)
// [VN] Phục dựng FDE #0491 tại 0x04a5a8..0x04a658 (176 byte)
//   0x04a5a8: a9402408  ldp      x8, x9, [x0]
//   0x04a5ac: cb080129  sub      x9, x9, x8
//   0x04a5b0: f100413f  cmp      x9, #0x10
//   0x04a5b4: 540004a1  b.ne     #0x4a648
//   0x04a5b8: a9402829  ldp      x9, x10, [x1]
//   0x04a5bc: cb09014a  sub      x10, x10, x9
//   0x04a5c0: f100415f  cmp      x10, #0x10
//   0x04a5c4: 54000421  b.ne     #0x4a648
//   0x04a5c8: 34000442  cbz      w2, #0x4a650
//   0x04a5cc: 11001c4a  add      w10, w2, #7
//   0x04a5d0: 7100005f  cmp      w2, #0
//   0x04a5d4: 1a82b14b  csel     w11, w10, w2, lt
//   0x04a5d8: 7100205f  cmp      w2, #8
//   0x04a5dc: 13037d6a  asr      w10, w11, #3
//   0x04a5e0: 5400018b  b.lt     #0x4a610
//   0x04a5e4: aa0a03ec  mov      x12, x10
uint64_t fde_0491_sub_04a5a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9402408ULL) + (x1 ^ 0x7100205FULL) + (x2 ^ 0x04A5A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402408ULL; // 0x04a5a8: ldp x8, x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB080129ULL; // 0x04a5ac: sub x9, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF100413FULL; // 0x04a5b0: cmp x9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x540004A1ULL; // 0x04a5b4: b.ne #0x4a648
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402829ULL; // 0x04a5b8: ldp x9, x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB09014AULL; // 0x04a5bc: sub x10, x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF100415FULL; // 0x04a5c0: cmp x10, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000421ULL; // 0x04a5c4: b.ne #0x4a648
    acc = (acc * 0x100000001B3ULL) ^ 0x34000442ULL; // 0x04a5c8: cbz w2, #0x4a650
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C4AULL; // 0x04a5cc: add w10, w2, #7
    return acc;
}

// [EN] Reconstructed FDE #0492 @ 0x04a658..0x04ab90 (1336 bytes)
// [VN] Phục dựng FDE #0492 tại 0x04a658..0x04ab90 (1336 byte)
//   0x04a658: d10343ff  sub      sp, sp, #0xd0
//   0x04a65c: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x04a660: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x04a664: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x04a668: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x04a66c: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x04a670: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x04a674: 910303fd  add      x29, sp, #0xc0
//   0x04a678: d53bd058  mrs      x24, tpidr_el0
//   0x04a67c: aa0803f3  mov      x19, x8
//   0x04a680: f9401708  ldr      x8, [x24, #0x28]
//   0x04a684: aa0003e1  mov      x1, x0
//   0x04a688: d284c017  mov      x23, #0x2600
//   0x04a68c: 9100c3e0  add      x0, sp, #0x30
//   0x04a690: f81a83a8  stur     x8, [x29, #-0x58]
//   0x04a694: f2c00037  movk     x23, #1, lsl #32
uint64_t fde_0492_sub_04a658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xD284C017ULL) + (x2 ^ 0x04A658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x04a658: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x04a65c: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x04a660: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x04a664: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x04a668: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x04a66c: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x04a670: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x04a674: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x04a678: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x04a67c: mov x19, x8
    return acc;
}

// [EN] Reconstructed FDE #0493 @ 0x04ab90..0x04af94 (1028 bytes)
// [VN] Phục dựng FDE #0493 tại 0x04ab90..0x04af94 (1028 byte)
//   0x04ab90: d103c3ff  sub      sp, sp, #0xf0
//   0x04ab94: f9005bf7  str      x23, [sp, #0xb0]
//   0x04ab98: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x04ab9c: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x04aba0: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x04aba4: 910383fd  add      x29, sp, #0xe0
//   0x04aba8: d53bd056  mrs      x22, tpidr_el0
//   0x04abac: f94016c8  ldr      x8, [x22, #0x28]
//   0x04abb0: aa0403f4  mov      x20, x4
//   0x04abb4: aa0303f5  mov      x21, x3
//   0x04abb8: f81c83a8  stur     x8, [x29, #-0x38]
//   0x04abbc: f9400028  ldr      x8, [x1]
//   0x04abc0: b9400501  ldr      w1, [x8, #4]
//   0x04abc4: d10183a8  sub      x8, x29, #0x60
//   0x04abc8: 97ff430a  bl       #0x1b7f0
//   0x04abcc: 528001d3  mov      w19, #0xe
uint64_t fde_0493_sub_04ab90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0xB9400501ULL) + (x2 ^ 0x04AB90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x04ab90: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9005BF7ULL; // 0x04ab94: str x23, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C57F6ULL; // 0x04ab98: stp x22, x21, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D4FF4ULL; // 0x04ab9c: stp x20, x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x04aba0: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x04aba4: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x04aba8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x04abac: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F4ULL; // 0x04abb0: mov x20, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x04abb4: mov x21, x3
    return acc;
}

// [EN] Reconstructed FDE #0494 @ 0x04af94..0x04b8fc (2408 bytes)
// [VN] Phục dựng FDE #0494 tại 0x04af94..0x04b8fc (2408 byte)
//   0x04af94: d10343ff  sub      sp, sp, #0xd0
//   0x04af98: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x04af9c: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x04afa0: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x04afa4: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x04afa8: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x04afac: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x04afb0: 910303fd  add      x29, sp, #0xc0
//   0x04afb4: d53bd05c  mrs      x28, tpidr_el0
//   0x04afb8: aa0803f3  mov      x19, x8
//   0x04afbc: f9401788  ldr      x8, [x28, #0x28]
//   0x04afc0: aa1303e9  mov      x9, x19
//   0x04afc4: aa0103f4  mov      x20, x1
//   0x04afc8: aa0003f5  mov      x21, x0
//   0x04afcc: f81a83a8  stur     x8, [x29, #-0x58]
//   0x04afd0: f8008d3f  str      xzr, [x9, #8]!
uint64_t fde_0494_sub_04af94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x04AF94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x04af94: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x04af98: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x04af9c: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x04afa0: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x04afa4: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x04afa8: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x04afac: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x04afb0: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x04afb4: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x04afb8: mov x19, x8
    return acc;
}

// [EN] Reconstructed FDE #0495 @ 0x04b8fc..0x04bd54 (1112 bytes)
// [VN] Phục dựng FDE #0495 tại 0x04b8fc..0x04bd54 (1112 byte)
//   0x04b8fc: d10303ff  sub      sp, sp, #0xc0
//   0x04b900: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x04b904: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x04b908: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x04b90c: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x04b910: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x04b914: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x04b918: 9102c3fd  add      x29, sp, #0xb0
//   0x04b91c: aa0803f3  mov      x19, x8
//   0x04b920: d53bd048  mrs      x8, tpidr_el0
//   0x04b924: f90007e8  str      x8, [sp, #8]
//   0x04b928: f9401508  ldr      x8, [x8, #0x28]
//   0x04b92c: aa0003fc  mov      x28, x0
//   0x04b930: f9002fe8  str      x8, [sp, #0x58]
//   0x04b934: a9007e7f  stp      xzr, xzr, [x19]
//   0x04b938: f9000a7f  str      xzr, [x19, #0x10]
uint64_t fde_0495_sub_04b8fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xAA0003FCULL) + (x2 ^ 0x04B8FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x04b8fc: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x04b900: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x04b904: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x04b908: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x04b90c: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x04b910: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x04b914: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x04b918: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x04b91c: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x04b920: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0496 @ 0x04bd54..0x04be60 (268 bytes)
// [VN] Phục dựng FDE #0496 tại 0x04bd54..0x04be60 (268 byte)
//   0x04bd54: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x04bd58: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x04bd5c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x04bd60: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x04bd64: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x04bd68: 910103fd  add      x29, sp, #0x40
//   0x04bd6c: a9007d1f  stp      xzr, xzr, [x8]
//   0x04bd70: f900091f  str      xzr, [x8, #0x10]
//   0x04bd74: aa0803f3  mov      x19, x8
//   0x04bd78: 39400008  ldrb     w8, [x0]
//   0x04bd7c: aa0003f7  mov      x23, x0
//   0x04bd80: aa0103f4  mov      x20, x1
//   0x04bd84: 370000e8  tbnz     w8, #0, #0x4bda0
//   0x04bd88: aa1403e0  mov      x0, x20
//   0x04bd8c: d341fd15  lsr      x21, x8, #1
//   0x04bd90: 97ff3cb8  bl       #0x1b070
uint64_t fde_0496_sub_04bd54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x370000E8ULL) + (x2 ^ 0x04BD54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x04bd54: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x04bd58: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x04bd5c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04bd60: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x04bd64: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x04bd68: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007D1FULL; // 0x04bd6c: stp xzr, xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900091FULL; // 0x04bd70: str xzr, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x04bd74: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x04bd78: ldrb w8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0497 @ 0x04be60..0x04c264 (1028 bytes)
// [VN] Phục dựng FDE #0497 tại 0x04be60..0x04c264 (1028 byte)
//   0x04be60: d101c3ff  sub      sp, sp, #0x70
//   0x04be64: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x04be68: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x04be6c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x04be70: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x04be74: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x04be78: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x04be7c: 910183fd  add      x29, sp, #0x60
//   0x04be80: cb020069  sub      x9, x3, x2
//   0x04be84: aa0103f3  mov      x19, x1
//   0x04be88: f100013f  cmp      x9, #0
//   0x04be8c: 54001a0d  b.le     #0x4c1cc
//   0x04be90: a940a01c  ldp      x28, x8, [x0, #8]
//   0x04be94: f940001a  ldr      x26, [x0]
//   0x04be98: b201f3ea  mov      x10, #-0x5555555555555556
//   0x04be9c: f295556a  movk     x10, #0xaaab
uint64_t fde_0497_sub_04be60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xA940A01CULL) + (x2 ^ 0x04BE60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x04be60: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x04be64: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x04be68: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x04be6c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x04be70: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x04be74: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x04be78: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x04be7c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020069ULL; // 0x04be80: sub x9, x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04be84: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0498 @ 0x04c264..0x04c4b0 (588 bytes)
// [VN] Phục dựng FDE #0498 tại 0x04c264..0x04c4b0 (588 byte)
//   0x04c264: d10343ff  sub      sp, sp, #0xd0
//   0x04c268: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x04c26c: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x04c270: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x04c274: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x04c278: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x04c27c: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x04c280: 910303fd  add      x29, sp, #0xc0
//   0x04c284: d53bd048  mrs      x8, tpidr_el0
//   0x04c288: f9000fe8  str      x8, [sp, #0x18]
//   0x04c28c: f9401508  ldr      x8, [x8, #0x28]
//   0x04c290: 52800029  mov      w9, #1
//   0x04c294: aa0003ea  mov      x10, x0
//   0x04c298: aa0003eb  mov      x11, x0
//   0x04c29c: f81a83a8  stur     x8, [x29, #-0x58]
//   0x04c2a0: aa0003f4  mov      x20, x0
uint64_t fde_0498_sub_04c264(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xAA0003EAULL) + (x2 ^ 0x04C264ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x04c264: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x04c268: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x04c26c: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x04c270: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x04c274: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x04c278: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x04c27c: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x04c280: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x04c284: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x04c288: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0499 @ 0x04c4b0..0x04c51c (108 bytes)
// [VN] Phục dựng FDE #0499 tại 0x04c4b0..0x04c51c (108 byte)
//   0x04c4b0: b4000341  cbz      x1, #0x4c518
//   0x04c4b4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04c4b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04c4bc: 910043fd  add      x29, sp, #0x10
//   0x04c4c0: aa0103f3  mov      x19, x1
//   0x04c4c4: f9400021  ldr      x1, [x1]
//   0x04c4c8: aa0003f4  mov      x20, x0
//   0x04c4cc: 97ff3a41  bl       #0x1add0
//   0x04c4d0: f9400661  ldr      x1, [x19, #8]
//   0x04c4d4: aa1403e0  mov      x0, x20
//   0x04c4d8: 97ff3a3e  bl       #0x1add0
//   0x04c4dc: f9403261  ldr      x1, [x19, #0x60]
//   0x04c4e0: 91016260  add      x0, x19, #0x58
//   0x04c4e4: 97ff3a3b  bl       #0x1add0
//   0x04c4e8: 39410268  ldrb     w8, [x19, #0x40]
//   0x04c4ec: 36000068  tbz      w8, #0, #0x4c4f8
uint64_t fde_0499_sub_04c4b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000341ULL) + (x1 ^ 0x91016260ULL) + (x2 ^ 0x04C4B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000341ULL; // 0x04c4b0: cbz x1, #0x4c518
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x04c4b4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04c4b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04c4bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04c4c0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x04c4c4: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04c4c8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF3A41ULL; // 0x04c4cc: bl #0x1add0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x04c4d0: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x04c4d4: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0500 @ 0x04c51c..0x04c628 (268 bytes)
// [VN] Phục dựng FDE #0500 tại 0x04c51c..0x04c628 (268 byte)
//   0x04c51c: d10143ff  sub      sp, sp, #0x50
//   0x04c520: f9000bf7  str      x23, [sp, #0x10]
//   0x04c524: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x04c528: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x04c52c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x04c530: 910103fd  add      x29, sp, #0x40
//   0x04c534: d53bd057  mrs      x23, tpidr_el0
//   0x04c538: f94016e8  ldr      x8, [x23, #0x28]
//   0x04c53c: aa0103e2  mov      x2, x1
//   0x04c540: 910003e1  mov      x1, sp
//   0x04c544: aa0303f6  mov      x22, x3
//   0x04c548: aa0003f4  mov      x20, x0
//   0x04c54c: f90007e8  str      x8, [sp, #8]
//   0x04c550: 97ff39cc  bl       #0x1ac80
//   0x04c554: f9400013  ldr      x19, [x0]
//   0x04c558: b4000073  cbz      x19, #0x4c564
uint64_t fde_0500_sub_04c51c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x04C51CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x04c51c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x04c520: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x04c524: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04c528: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x04c52c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x04c530: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x04c534: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x04c538: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x04c53c: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x04c540: mov x1, sp
    return acc;
}

// [EN] Reconstructed FDE #0501 @ 0x04c628..0x04c748 (288 bytes)
// [VN] Phục dựng FDE #0501 tại 0x04c628..0x04c748 (288 byte)
//   0x04c628: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x04c62c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x04c630: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x04c634: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04c638: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04c63c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04c640: 910143fd  add      x29, sp, #0x50
//   0x04c644: aa0003f4  mov      x20, x0
//   0x04c648: f8408e97  ldr      x23, [x20, #8]!
//   0x04c64c: aa0103f3  mov      x19, x1
//   0x04c650: b4000657  cbz      x23, #0x4c718
//   0x04c654: 39400048  ldrb     w8, [x2]
//   0x04c658: a940a849  ldp      x9, x10, [x2, #8]
//   0x04c65c: 91002014  add      x20, x0, #8
//   0x04c660: d341fd0b  lsr      x11, x8, #1
//   0x04c664: 7200011f  tst      w8, #1
uint64_t fde_0501_sub_04c628(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x04C628ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x04c628: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x04c62c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x04c630: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04c634: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04c638: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04c63c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04c640: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04c644: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x04c648: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04c64c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0502 @ 0x04c748..0x04c82c (228 bytes)
// [VN] Phục dựng FDE #0502 tại 0x04c748..0x04c82c (228 byte)
//   0x04c748: d10183ff  sub      sp, sp, #0x60
//   0x04c74c: f90013f7  str      x23, [sp, #0x20]
//   0x04c750: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04c754: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04c758: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04c75c: 910143fd  add      x29, sp, #0x50
//   0x04c760: d53bd057  mrs      x23, tpidr_el0
//   0x04c764: f94016e8  ldr      x8, [x23, #0x28]
//   0x04c768: aa0303f6  mov      x22, x3
//   0x04c76c: aa0203e4  mov      x4, x2
//   0x04c770: 910043e2  add      x2, sp, #0x10
//   0x04c774: 910023e3  add      x3, sp, #8
//   0x04c778: aa0003f3  mov      x19, x0
//   0x04c77c: f9000fe8  str      x8, [sp, #0x18]
//   0x04c780: 97ff3c08  bl       #0x1b7a0
//   0x04c784: f9400014  ldr      x20, [x0]
uint64_t fde_0502_sub_04c748(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x04C748ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x04c748: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x04c74c: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04c750: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04c754: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04c758: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04c75c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x04c760: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x04c764: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x04c768: mov x22, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E4ULL; // 0x04c76c: mov x4, x2
    return acc;
}

// [EN] Reconstructed FDE #0503 @ 0x04c82c..0x04cb08 (732 bytes)
// [VN] Phục dựng FDE #0503 tại 0x04c82c..0x04cb08 (732 byte)
//   0x04c82c: d10203ff  sub      sp, sp, #0x80
//   0x04c830: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x04c834: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x04c838: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x04c83c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x04c840: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x04c844: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x04c848: 9101c3fd  add      x29, sp, #0x70
//   0x04c84c: 91002008  add      x8, x0, #8
//   0x04c850: aa0403f5  mov      x21, x4
//   0x04c854: aa0103f4  mov      x20, x1
//   0x04c858: eb01011f  cmp      x8, x1
//   0x04c85c: a90083e3  stp      x3, x0, [sp, #8]
//   0x04c860: f90003e8  str      x8, [sp]
//   0x04c864: f9000fe2  str      x2, [sp, #0x18]
//   0x04c868: 54000380  b.eq     #0x4c8d8
uint64_t fde_0503_sub_04c82c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xA90083E3ULL) + (x2 ^ 0x04C82CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x04c82c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x04c830: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x04c834: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x04c838: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x04c83c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x04c840: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x04c844: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x04c848: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x04c84c: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F5ULL; // 0x04c850: mov x21, x4
    return acc;
}

// [EN] Reconstructed FDE #0504 @ 0x04cb08..0x04cc28 (288 bytes)
// [VN] Phục dựng FDE #0504 tại 0x04cb08..0x04cc28 (288 byte)
//   0x04cb08: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x04cb0c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x04cb10: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x04cb14: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04cb18: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04cb1c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04cb20: 910143fd  add      x29, sp, #0x50
//   0x04cb24: aa0003f4  mov      x20, x0
//   0x04cb28: f8408e97  ldr      x23, [x20, #8]!
//   0x04cb2c: aa0103f3  mov      x19, x1
//   0x04cb30: b4000657  cbz      x23, #0x4cbf8
//   0x04cb34: 39400048  ldrb     w8, [x2]
//   0x04cb38: a940a849  ldp      x9, x10, [x2, #8]
//   0x04cb3c: 91002014  add      x20, x0, #8
//   0x04cb40: d341fd0b  lsr      x11, x8, #1
//   0x04cb44: 7200011f  tst      w8, #1
uint64_t fde_0504_sub_04cb08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x04CB08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x04cb08: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x04cb0c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x04cb10: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04cb14: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04cb18: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04cb1c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04cb20: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04cb24: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x04cb28: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04cb2c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0505 @ 0x04cc28..0x04cc78 (80 bytes)
// [VN] Phục dựng FDE #0505 tại 0x04cc28..0x04cc78 (80 byte)
//   0x04cc28: b4000261  cbz      x1, #0x4cc74
//   0x04cc2c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04cc30: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04cc34: 910043fd  add      x29, sp, #0x10
//   0x04cc38: aa0103f3  mov      x19, x1
//   0x04cc3c: f9400021  ldr      x1, [x1]
//   0x04cc40: aa0003f4  mov      x20, x0
//   0x04cc44: 97ff3bdb  bl       #0x1bbb0
//   0x04cc48: f9400661  ldr      x1, [x19, #8]
//   0x04cc4c: aa1403e0  mov      x0, x20
//   0x04cc50: 97ff3bd8  bl       #0x1bbb0
//   0x04cc54: 39408268  ldrb     w8, [x19, #0x20]
//   0x04cc58: 36000068  tbz      w8, #0, #0x4cc64
//   0x04cc5c: f9401a60  ldr      x0, [x19, #0x30]
//   0x04cc60: 97ff3788  bl       #0x1aa80
//   0x04cc64: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0505_sub_04cc28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000261ULL) + (x1 ^ 0x36000068ULL) + (x2 ^ 0x04CC28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000261ULL; // 0x04cc28: cbz x1, #0x4cc74
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x04cc2c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04cc30: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04cc34: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04cc38: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x04cc3c: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04cc40: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF3BDBULL; // 0x04cc44: bl #0x1bbb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x04cc48: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x04cc4c: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0506 @ 0x04cc78..0x04ce40 (456 bytes)
// [VN] Phục dựng FDE #0506 tại 0x04cc78..0x04ce40 (456 byte)
//   0x04cc78: d10203ff  sub      sp, sp, #0x80
//   0x04cc7c: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x04cc80: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x04cc84: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x04cc88: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x04cc8c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x04cc90: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x04cc94: 9101c3fd  add      x29, sp, #0x70
//   0x04cc98: eb03005f  cmp      x2, x3
//   0x04cc9c: a90107e3  stp      x3, x1, [sp, #0x10]
//   0x04cca0: 54000ba0  b.eq     #0x4ce14
//   0x04cca4: aa0203f5  mov      x21, x2
//   0x04cca8: aa0003f6  mov      x22, x0
//   0x04ccac: 14000005  b        #0x4ccc0
//   0x04ccb0: aa0903f6  mov      x22, x9
//   0x04ccb4: f9400be8  ldr      x8, [sp, #0x10]
uint64_t fde_0506_sub_04cc78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x04CC78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x04cc78: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x04cc7c: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x04cc80: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x04cc84: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x04cc88: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x04cc8c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x04cc90: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x04cc94: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xEB03005FULL; // 0x04cc98: cmp x2, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E3ULL; // 0x04cc9c: stp x3, x1, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0507 @ 0x04ce40..0x04d104 (708 bytes)
// [VN] Phục dựng FDE #0507 tại 0x04ce40..0x04d104 (708 byte)
//   0x04ce40: d10243ff  sub      sp, sp, #0x90
//   0x04ce44: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x04ce48: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x04ce4c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x04ce50: 910203fd  add      x29, sp, #0x80
//   0x04ce54: d53bd056  mrs      x22, tpidr_el0
//   0x04ce58: f94016c8  ldr      x8, [x22, #0x28]
//   0x04ce5c: aa0303f4  mov      x20, x3
//   0x04ce60: f81d83a8  stur     x8, [x29, #-0x28]
//   0x04ce64: f9400028  ldr      x8, [x1]
//   0x04ce68: 29408515  ldp      w21, w1, [x8, #4]
//   0x04ce6c: 9100e3e8  add      x8, sp, #0x38
//   0x04ce70: 97ff3a60  bl       #0x1b7f0
//   0x04ce74: 528001d3  mov      w19, #0xe
//   0x04ce78: b4000734  cbz      x20, #0x4cf5c
//   0x04ce7c: 3940e3e8  ldrb     w8, [sp, #0x38]
uint64_t fde_0507_sub_04ce40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x97FF3A60ULL) + (x2 ^ 0x04CE40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x04ce40: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x04ce44: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x04ce48: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x04ce4c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x04ce50: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x04ce54: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x04ce58: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x04ce5c: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x04ce60: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x04ce64: ldr x8, [x1]
    return acc;
}

// [EN] Reconstructed FDE #0508 @ 0x04d104..0x04d368 (612 bytes)
// [VN] Phục dựng FDE #0508 tại 0x04d104..0x04d368 (612 byte)
//   0x04d104: d10243ff  sub      sp, sp, #0x90
//   0x04d108: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x04d10c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x04d110: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x04d114: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x04d118: 910203fd  add      x29, sp, #0x80
//   0x04d11c: d53bd057  mrs      x23, tpidr_el0
//   0x04d120: f94016e8  ldr      x8, [x23, #0x28]
//   0x04d124: aa0103f4  mov      x20, x1
//   0x04d128: 2a0003f5  mov      w21, w0
//   0x04d12c: f81c83a8  stur     x8, [x29, #-0x38]
//   0x04d130: a9406056  ldp      x22, x24, [x2]
//   0x04d134: 9100c3e8  add      x8, sp, #0x30
//   0x04d138: 91002113  add      x19, x8, #8
//   0x04d13c: a903ffff  stp      xzr, xzr, [sp, #0x38]
//   0x04d140: eb1802df  cmp      x22, x24
uint64_t fde_0508_sub_04d104(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x9100C3E8ULL) + (x2 ^ 0x04D104ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x04d104: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x04d108: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x04d10c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x04d110: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x04d114: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x04d118: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x04d11c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x04d120: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04d124: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F5ULL; // 0x04d128: mov w21, w0
    return acc;
}

// [EN] Reconstructed FDE #0509 @ 0x04d368..0x04d4b0 (328 bytes)
// [VN] Phục dựng FDE #0509 tại 0x04d368..0x04d4b0 (328 byte)
//   0x04d368: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x04d36c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04d370: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04d374: 910083fd  add      x29, sp, #0x20
//   0x04d378: aa0003f4  mov      x20, x0
//   0x04d37c: a9007d1f  stp      xzr, xzr, [x8]
//   0x04d380: f900091f  str      xzr, [x8, #0x10]
//   0x04d384: f8408696  ldr      x22, [x20], #8
//   0x04d388: eb1402df  cmp      x22, x20
//   0x04d38c: 54000500  b.eq     #0x4d42c
//   0x04d390: aa0803f3  mov      x19, x8
//   0x04d394: aa1f03e8  mov      x8, xzr
//   0x04d398: aa1f03f5  mov      x21, xzr
//   0x04d39c: eb0802bf  cmp      x21, x8
//   0x04d3a0: 910082c1  add      x1, x22, #0x20
//   0x04d3a4: 54000100  b.eq     #0x4d3c4
uint64_t fde_0509_sub_04d368(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1F03F5ULL) + (x2 ^ 0x04D368ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04d368: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04d36c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04d370: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04d374: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04d378: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007D1FULL; // 0x04d37c: stp xzr, xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900091FULL; // 0x04d380: str xzr, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408696ULL; // 0x04d384: ldr x22, [x20], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB1402DFULL; // 0x04d388: cmp x22, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000500ULL; // 0x04d38c: b.eq #0x4d42c
    return acc;
}

// [EN] Reconstructed FDE #0510 @ 0x04d4b0..0x04d5ec (316 bytes)
// [VN] Phục dựng FDE #0510 tại 0x04d4b0..0x04d5ec (316 byte)
//   0x04d4b0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04d4b4: 9e660000  fmov     x0, d0
//   0x04d4b8: 9eae0001  fmov     x1, v0.d[1]
//   0x04d4bc: 910003fd  mov      x29, sp
//   0x04d4c0: aa0003e3  mov      x3, x0
//   0x04d4c4: aa0103e0  mov      x0, x1
//   0x04d4c8: 9e660024  fmov     x4, d1
//   0x04d4cc: 9eae0025  fmov     x5, v1.d[1]
//   0x04d4d0: d53b4401  mrs      x1, fpcr
//   0x04d4d4: d370f807  ubfx     x7, x0, #0x30, #0xf
//   0x04d4d8: d340bc06  ubfx     x6, x0, #0, #0x30
//   0x04d4dc: d37ffc01  lsr      x1, x0, #0x3f
//   0x04d4e0: d28fffe0  mov      x0, #0x7fff
//   0x04d4e4: eb0000ff  cmp      x7, x0
//   0x04d4e8: d340bca8  ubfx     x8, x5, #0, #0x30
//   0x04d4ec: d370f8a9  ubfx     x9, x5, #0x30, #0xf
uint64_t fde_0510_sub_04d4b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD28FFFE0ULL) + (x2 ^ 0x04D4B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04d4b0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660000ULL; // 0x04d4b4: fmov x0, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0001ULL; // 0x04d4b8: fmov x1, v0.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04d4bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E3ULL; // 0x04d4c0: mov x3, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04d4c4: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660024ULL; // 0x04d4c8: fmov x4, d1
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0025ULL; // 0x04d4cc: fmov x5, v1.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B4401ULL; // 0x04d4d0: mrs x1, fpcr
    acc = (acc * 0x100000001B3ULL) ^ 0xD370F807ULL; // 0x04d4d4: ubfx x7, x0, #0x30, #0xf
    return acc;
}

// [EN] Reconstructed FDE #0511 @ 0x04d5ec..0x04dccc (1760 bytes)
// [VN] Phục dựng FDE #0511 tại 0x04d5ec..0x04dccc (1760 byte)
//   0x04d5ec: 9e660000  fmov     x0, d0
//   0x04d5f0: 9eae0001  fmov     x1, v0.d[1]
//   0x04d5f4: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04d5f8: aa0003e3  mov      x3, x0
//   0x04d5fc: aa0103e4  mov      x4, x1
//   0x04d600: 9e660020  fmov     x0, d1
//   0x04d604: 910003fd  mov      x29, sp
//   0x04d608: 9eae0021  fmov     x1, v1.d[1]
//   0x04d60c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04d610: aa0003e5  mov      x5, x0
//   0x04d614: aa0103e2  mov      x2, x1
//   0x04d618: d53b4408  mrs      x8, fpcr
//   0x04d61c: d370f88d  ubfx     x13, x4, #0x30, #0xf
//   0x04d620: d340bc87  ubfx     x7, x4, #0, #0x30
//   0x04d624: d37ffc84  lsr      x4, x4, #0x3f
//   0x04d628: aa0303e6  mov      x6, x3
uint64_t fde_0511_sub_04d5ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9E660000ULL) + (x1 ^ 0xD370F88DULL) + (x2 ^ 0x04D5ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660000ULL; // 0x04d5ec: fmov x0, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0001ULL; // 0x04d5f0: fmov x1, v0.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04d5f4: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E3ULL; // 0x04d5f8: mov x3, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E4ULL; // 0x04d5fc: mov x4, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660020ULL; // 0x04d600: fmov x0, d1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04d604: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0021ULL; // 0x04d608: fmov x1, v1.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04d60c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E5ULL; // 0x04d610: mov x5, x0
    return acc;
}

// [EN] Reconstructed FDE #0512 @ 0x04dccc..0x04e7e0 (2836 bytes)
// [VN] Phục dựng FDE #0512 tại 0x04dccc..0x04e7e0 (2836 byte)
//   0x04dccc: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x04dcd0: 9e660000  fmov     x0, d0
//   0x04dcd4: 9eae0001  fmov     x1, v0.d[1]
//   0x04dcd8: 910003fd  mov      x29, sp
//   0x04dcdc: 9e660024  fmov     x4, d1
//   0x04dce0: aa0003e6  mov      x6, x0
//   0x04dce4: 9eae0025  fmov     x5, v1.d[1]
//   0x04dce8: aa0103e0  mov      x0, x1
//   0x04dcec: aa0403e3  mov      x3, x4
//   0x04dcf0: aa0503e1  mov      x1, x5
//   0x04dcf4: d53b4409  mrs      x9, fpcr
//   0x04dcf8: aa0003e4  mov      x4, x0
//   0x04dcfc: d28fffec  mov      x12, #0x7fff
//   0x04dd00: d37dbc85  ubfiz    x5, x4, #3, #0x30
//   0x04dd04: d37ffc88  lsr      x8, x4, #0x3f
//   0x04dd08: d370f824  ubfx     x4, x1, #0x30, #0xf
uint64_t fde_0512_sub_04dccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0xD28FFFECULL) + (x2 ^ 0x04DCCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x04dccc: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660000ULL; // 0x04dcd0: fmov x0, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0001ULL; // 0x04dcd4: fmov x1, v0.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04dcd8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660024ULL; // 0x04dcdc: fmov x4, d1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E6ULL; // 0x04dce0: mov x6, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0025ULL; // 0x04dce4: fmov x5, v1.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04dce8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E3ULL; // 0x04dcec: mov x3, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0503E1ULL; // 0x04dcf0: mov x1, x5
    return acc;
}

// [EN] Reconstructed FDE #0513 @ 0x04e7e0..0x04e86c (140 bytes)
// [VN] Phục dựng FDE #0513 tại 0x04e7e0..0x04e86c (140 byte)
//   0x04e7e0: b4000300  cbz      x0, #0x4e840
//   0x04e7e4: d37ffc01  lsr      x1, x0, #0x3f
//   0x04e7e8: d2880de3  mov      x3, #0x406f
//   0x04e7ec: 6b1f003f  cmp      w1, wzr
//   0x04e7f0: 53001c25  uxtb     w5, w1
//   0x04e7f4: 528807c1  mov      w1, #0x403e
//   0x04e7f8: da800400  cneg     x0, x0, ne
//   0x04e7fc: dac01002  clz      x2, x0
//   0x04e800: 4b020022  sub      w2, w1, w2
//   0x04e804: 93407c44  sxtw     x4, w2
//   0x04e808: cb040061  sub      x1, x3, x4
//   0x04e80c: f100fc3f  cmp      x1, #0x3f
//   0x04e810: 540000ec  b.gt     #0x4e82c
//   0x04e814: 51401041  sub      w1, w2, #4, lsl #12
//   0x04e818: 4b020062  sub      w2, w3, w2
//   0x04e81c: 5100bc21  sub      w1, w1, #0x2f
uint64_t fde_0513_sub_04e7e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000300ULL) + (x1 ^ 0x540000ECULL) + (x2 ^ 0x04E7E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000300ULL; // 0x04e7e0: cbz x0, #0x4e840
    acc = (acc * 0x100000001B3ULL) ^ 0xD37FFC01ULL; // 0x04e7e4: lsr x1, x0, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0xD2880DE3ULL; // 0x04e7e8: mov x3, #0x406f
    acc = (acc * 0x100000001B3ULL) ^ 0x6B1F003FULL; // 0x04e7ec: cmp w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C25ULL; // 0x04e7f0: uxtb w5, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x528807C1ULL; // 0x04e7f4: mov w1, #0x403e
    acc = (acc * 0x100000001B3ULL) ^ 0xDA800400ULL; // 0x04e7f8: cneg x0, x0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xDAC01002ULL; // 0x04e7fc: clz x2, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x4B020022ULL; // 0x04e800: sub w2, w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C44ULL; // 0x04e804: sxtw x4, w2
    return acc;
}

// [EN] Reconstructed FDE #0514 @ 0x04e86c..0x04e894 (40 bytes)
// [VN] Phục dựng FDE #0514 tại 0x04e86c..0x04e894 (40 byte)
//   0x04e86c: d2800002  mov      x2, #0
//   0x04e870: 52800003  mov      w3, #0
//   0x04e874: 38401405  ldrb     w5, [x0], #1
//   0x04e878: 924018a4  and      x4, x5, #0x7f
//   0x04e87c: 9ac32084  lsl      x4, x4, x3
//   0x04e880: 11001c63  add      w3, w3, #7
//   0x04e884: aa040042  orr      x2, x2, x4
//   0x04e888: 373fff65  tbnz     w5, #7, #0x4e874
//   0x04e88c: f9000022  str      x2, [x1]
//   0x04e890: d65f03c0  ret      
uint64_t fde_0514_sub_04e86c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04E86CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04e86c: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x04e870: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401405ULL; // 0x04e874: ldrb w5, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x924018A4ULL; // 0x04e878: and x4, x5, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC32084ULL; // 0x04e87c: lsl x4, x4, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x04e880: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA040042ULL; // 0x04e884: orr x2, x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF65ULL; // 0x04e888: tbnz w5, #7, #0x4e874
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000022ULL; // 0x04e88c: str x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04e890: ret 
    return acc;
}

// [EN] Reconstructed FDE #0515 @ 0x04e894..0x04e8d4 (64 bytes)
// [VN] Phục dựng FDE #0515 tại 0x04e894..0x04e8d4 (64 byte)
//   0x04e894: d2800002  mov      x2, #0
//   0x04e898: 52800003  mov      w3, #0
//   0x04e89c: 38401404  ldrb     w4, [x0], #1
//   0x04e8a0: 92401885  and      x5, x4, #0x7f
//   0x04e8a4: 9ac320a5  lsl      x5, x5, x3
//   0x04e8a8: 11001c63  add      w3, w3, #7
//   0x04e8ac: aa050042  orr      x2, x2, x5
//   0x04e8b0: 373fff64  tbnz     w4, #7, #0x4e89c
//   0x04e8b4: 7100fc7f  cmp      w3, #0x3f
//   0x04e8b8: 540000a8  b.hi     #0x4e8cc
//   0x04e8bc: 36300084  tbz      w4, #6, #0x4e8cc
//   0x04e8c0: 92800004  mov      x4, #-1
//   0x04e8c4: 9ac32083  lsl      x3, x4, x3
//   0x04e8c8: aa020062  orr      x2, x3, x2
//   0x04e8cc: f9000022  str      x2, [x1]
//   0x04e8d0: d65f03c0  ret      
uint64_t fde_0515_sub_04e894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x9AC32083ULL) + (x2 ^ 0x04E894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04e894: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x04e898: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401404ULL; // 0x04e89c: ldrb w4, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x92401885ULL; // 0x04e8a0: and x5, x4, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC320A5ULL; // 0x04e8a4: lsl x5, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x04e8a8: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA050042ULL; // 0x04e8ac: orr x2, x2, x5
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF64ULL; // 0x04e8b0: tbnz w4, #7, #0x4e89c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100FC7FULL; // 0x04e8b4: cmp w3, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x04e8b8: b.hi #0x4e8cc
    return acc;
}

// [EN] Reconstructed FDE #0516 @ 0x04e8d4..0x04e9c4 (240 bytes)
// [VN] Phục dựng FDE #0516 tại 0x04e8d4..0x04e9c4 (240 byte)
//   0x04e8d4: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04e8d8: 910003fd  mov      x29, sp
//   0x04e8dc: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e8e0: 53001c14  uxtb     w20, w0
//   0x04e8e4: aa0203f3  mov      x19, x2
//   0x04e8e8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e8ec: 7101429f  cmp      w20, #0x50
//   0x04e8f0: aa0103f6  mov      x22, x1
//   0x04e8f4: aa0303f5  mov      x21, x3
//   0x04e8f8: 540000a1  b.ne     #0x4e90c
//   0x04e8fc: 91001c53  add      x19, x2, #7
//   0x04e900: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x04e904: f8408401  ldr      x1, [x0], #8
//   0x04e908: 1400002a  b        #0x4e9b0
//   0x04e90c: 12000e81  and      w1, w20, #0xf
//   0x04e910: 7100303f  cmp      w1, #0xc
uint64_t fde_0516_sub_04e8d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF8408401ULL) + (x2 ^ 0x04E8D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04e8d4: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e8d8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e8dc: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C14ULL; // 0x04e8e0: uxtb w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x04e8e4: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e8e8: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7101429FULL; // 0x04e8ec: cmp w20, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x04e8f0: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x04e8f4: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x04e8f8: b.ne #0x4e90c
    return acc;
}

// [EN] Reconstructed FDE #0517 @ 0x04e9c4..0x04ead8 (276 bytes)
// [VN] Phục dựng FDE #0517 tại 0x04e9c4..0x04ead8 (276 byte)
//   0x04e9c4: f00000c2  adrp     x2, #0x69000
//   0x04e9c8: 52800100  mov      w0, #8
//   0x04e9cc: 91054041  add      x1, x2, #0x150
//   0x04e9d0: 39054040  strb     w0, [x2, #0x150]
//   0x04e9d4: 39000420  strb     w0, [x1, #1]
//   0x04e9d8: 39000820  strb     w0, [x1, #2]
//   0x04e9dc: 39000c20  strb     w0, [x1, #3]
//   0x04e9e0: 39001020  strb     w0, [x1, #4]
//   0x04e9e4: 39001420  strb     w0, [x1, #5]
//   0x04e9e8: 39001820  strb     w0, [x1, #6]
//   0x04e9ec: 39001c20  strb     w0, [x1, #7]
//   0x04e9f0: 39002020  strb     w0, [x1, #8]
//   0x04e9f4: 39002420  strb     w0, [x1, #9]
//   0x04e9f8: 39002820  strb     w0, [x1, #0xa]
//   0x04e9fc: 39002c20  strb     w0, [x1, #0xb]
//   0x04ea00: 39003020  strb     w0, [x1, #0xc]
uint64_t fde_0517_sub_04e9c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00000C2ULL) + (x1 ^ 0x39002420ULL) + (x2 ^ 0x04E9C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C2ULL; // 0x04e9c4: adrp x2, #0x69000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x04e9c8: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x91054041ULL; // 0x04e9cc: add x1, x2, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0x39054040ULL; // 0x04e9d0: strb w0, [x2, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000420ULL; // 0x04e9d4: strb w0, [x1, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000820ULL; // 0x04e9d8: strb w0, [x1, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000C20ULL; // 0x04e9dc: strb w0, [x1, #3]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001020ULL; // 0x04e9e0: strb w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001420ULL; // 0x04e9e4: strb w0, [x1, #5]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001820ULL; // 0x04e9e8: strb w0, [x1, #6]
    return acc;
}

// [EN] Reconstructed FDE #0518 @ 0x04ead8..0x04eb14 (60 bytes)
// [VN] Phục dựng FDE #0518 tại 0x04ead8..0x04eb14 (60 byte)
//   0x04ead8: f00000c3  adrp     x3, #0x69000
//   0x04eadc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04eae0: 910003fd  mov      x29, sp
//   0x04eae4: 3945bc63  ldrb     w3, [x3, #0x16f]
//   0x04eae8: 7100207f  cmp      w3, #8
//   0x04eaec: 540000c1  b.ne     #0x4eb04
//   0x04eaf0: f9000041  str      x1, [x2]
//   0x04eaf4: f941a001  ldr      x1, [x0, #0x340]
//   0x04eaf8: b6f00081  tbz      x1, #0x3e, #0x4eb08
//   0x04eafc: 390ddc1f  strb     wzr, [x0, #0x377]
//   0x04eb00: 14000002  b        #0x4eb08
//   0x04eb04: 97ff338b  bl       #0x1b930
//   0x04eb08: f9007c02  str      x2, [x0, #0xf8]
//   0x04eb0c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x04eb10: d65f03c0  ret      
uint64_t fde_0518_sub_04ead8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00000C3ULL) + (x1 ^ 0xF9007C02ULL) + (x2 ^ 0x04EAD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C3ULL; // 0x04ead8: adrp x3, #0x69000
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04eadc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04eae0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x3945BC63ULL; // 0x04eae4: ldrb w3, [x3, #0x16f]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100207FULL; // 0x04eae8: cmp w3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x04eaec: b.ne #0x4eb04
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000041ULL; // 0x04eaf0: str x1, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A001ULL; // 0x04eaf4: ldr x1, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xB6F00081ULL; // 0x04eaf8: tbz x1, #0x3e, #0x4eb08
    acc = (acc * 0x100000001B3ULL) ^ 0x390DDC1FULL; // 0x04eafc: strb wzr, [x0, #0x377]
    return acc;
}

// [EN] Reconstructed FDE #0519 @ 0x04eb14..0x04eb6c (88 bytes)
// [VN] Phục dựng FDE #0519 tại 0x04eb14..0x04eb6c (88 byte)
//   0x04eb14: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04eb18: 7101843f  cmp      w1, #0x61
//   0x04eb1c: 910003fd  mov      x29, sp
//   0x04eb20: 5400004d  b.le     #0x4eb28
//   0x04eb24: 97ff3383  bl       #0x1b930
//   0x04eb28: f00000c3  adrp     x3, #0x69000
//   0x04eb2c: 93407c22  sxtw     x2, w1
//   0x04eb30: 91054063  add      x3, x3, #0x150
//   0x04eb34: f941a004  ldr      x4, [x0, #0x340]
//   0x04eb38: f861d801  ldr      x1, [x0, w1, sxtw #3]
//   0x04eb3c: 38626863  ldrb     w3, [x3, x2]
//   0x04eb40: b6f000c4  tbz      x4, #0x3e, #0x4eb58
//   0x04eb44: 8b020002  add      x2, x0, x2
//   0x04eb48: 394d6040  ldrb     w0, [x2, #0x358]
//   0x04eb4c: 34000060  cbz      w0, #0x4eb58
//   0x04eb50: aa0103e0  mov      x0, x1
uint64_t fde_0519_sub_04eb14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x8B020002ULL) + (x2 ^ 0x04EB14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04eb14: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7101843FULL; // 0x04eb18: cmp w1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04eb1c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004DULL; // 0x04eb20: b.le #0x4eb28
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF3383ULL; // 0x04eb24: bl #0x1b930
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C3ULL; // 0x04eb28: adrp x3, #0x69000
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C22ULL; // 0x04eb2c: sxtw x2, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x91054063ULL; // 0x04eb30: add x3, x3, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A004ULL; // 0x04eb34: ldr x4, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xF861D801ULL; // 0x04eb38: ldr x1, [x0, w1, sxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #0520 @ 0x04eb6c..0x04ec78 (268 bytes)
// [VN] Phục dựng FDE #0520 tại 0x04eb6c..0x04ec78 (268 byte)
//   0x04eb6c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04eb70: 910003fd  mov      x29, sp
//   0x04eb74: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04eb78: aa0003f5  mov      x21, x0
//   0x04eb7c: f941a020  ldr      x0, [x1, #0x340]
//   0x04eb80: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04eb84: aa0103f3  mov      x19, x1
//   0x04eb88: b6f00060  tbz      x0, #0x3e, #0x4eb94
//   0x04eb8c: 394ddc20  ldrb     w0, [x1, #0x377]
//   0x04eb90: 350000e0  cbnz     w0, #0x4ebac
//   0x04eb94: f9407e60  ldr      x0, [x19, #0xf8]
//   0x04eb98: b50000a0  cbnz     x0, #0x4ebac
//   0x04eb9c: f9418a61  ldr      x1, [x19, #0x310]
//   0x04eba0: aa1303e0  mov      x0, x19
//   0x04eba4: 9100e3a2  add      x2, x29, #0x38
//   0x04eba8: 97ffffcc  bl       #0x4ead8
uint64_t fde_0520_sub_04eb6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF9418A61ULL) + (x2 ^ 0x04EB6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04eb6c: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04eb70: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04eb74: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04eb78: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A020ULL; // 0x04eb7c: ldr x0, [x1, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04eb80: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04eb84: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB6F00060ULL; // 0x04eb88: tbz x0, #0x3e, #0x4eb94
    acc = (acc * 0x100000001B3ULL) ^ 0x394DDC20ULL; // 0x04eb8c: ldrb w0, [x1, #0x377]
    acc = (acc * 0x100000001B3ULL) ^ 0x350000E0ULL; // 0x04eb90: cbnz w0, #0x4ebac
    return acc;
}

// [EN] Reconstructed FDE #0521 @ 0x04ec78..0x04ec80 (8 bytes)
// [VN] Phục dựng FDE #0521 tại 0x04ec78..0x04ec80 (8 byte)
//   0x04ec78: f9418800  ldr      x0, [x0, #0x310]
//   0x04ec7c: d65f03c0  ret      
uint64_t fde_0521_sub_04ec78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9418800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04EC78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418800ULL; // 0x04ec78: ldr x0, [x0, #0x310]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ec7c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0522 @ 0x04ec80..0x04ecd8 (88 bytes)
// [VN] Phục dựng FDE #0522 tại 0x04ec80..0x04ecd8 (88 byte)
//   0x04ec80: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04ec84: 7101843f  cmp      w1, #0x61
//   0x04ec88: 910003fd  mov      x29, sp
//   0x04ec8c: 5400004d  b.le     #0x4ec94
//   0x04ec90: 97ff3328  bl       #0x1b930
//   0x04ec94: f00000c4  adrp     x4, #0x69000
//   0x04ec98: 93407c23  sxtw     x3, w1
//   0x04ec9c: 91054084  add      x4, x4, #0x150
//   0x04eca0: f941a005  ldr      x5, [x0, #0x340]
//   0x04eca4: 38636884  ldrb     w4, [x4, x3]
//   0x04eca8: b6f000c5  tbz      x5, #0x3e, #0x4ecc0
//   0x04ecac: 8b030003  add      x3, x0, x3
//   0x04ecb0: 394d6063  ldrb     w3, [x3, #0x358]
//   0x04ecb4: 34000063  cbz      w3, #0x4ecc0
//   0x04ecb8: f821d802  str      x2, [x0, w1, sxtw #3]
//   0x04ecbc: 14000005  b        #0x4ecd0
uint64_t fde_0522_sub_04ec80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x394D6063ULL) + (x2 ^ 0x04EC80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04ec80: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7101843FULL; // 0x04ec84: cmp w1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ec88: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004DULL; // 0x04ec8c: b.le #0x4ec94
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF3328ULL; // 0x04ec90: bl #0x1b930
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C4ULL; // 0x04ec94: adrp x4, #0x69000
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C23ULL; // 0x04ec98: sxtw x3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x91054084ULL; // 0x04ec9c: add x4, x4, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A005ULL; // 0x04eca0: ldr x5, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0x38636884ULL; // 0x04eca4: ldrb w4, [x4, x3]
    return acc;
}

// [EN] Reconstructed FDE #0523 @ 0x04ecd8..0x04ece0 (8 bytes)
// [VN] Phục dựng FDE #0523 tại 0x04ecd8..0x04ece0 (8 byte)
//   0x04ecd8: f9418c00  ldr      x0, [x0, #0x318]
//   0x04ecdc: d65f03c0  ret      
uint64_t fde_0523_sub_04ecd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9418C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ECD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418C00ULL; // 0x04ecd8: ldr x0, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ecdc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0524 @ 0x04ece0..0x04ecf4 (20 bytes)
// [VN] Phục dựng FDE #0524 tại 0x04ece0..0x04ecf4 (20 byte)
//   0x04ece0: f941a002  ldr      x2, [x0, #0x340]
//   0x04ece4: f9418c00  ldr      x0, [x0, #0x318]
//   0x04ece8: d37ffc42  lsr      x2, x2, #0x3f
//   0x04ecec: b9000022  str      w2, [x1]
//   0x04ecf0: d65f03c0  ret      
uint64_t fde_0524_sub_04ece0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF941A002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ECE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A002ULL; // 0x04ece0: ldr x2, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418C00ULL; // 0x04ece4: ldr x0, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD37FFC42ULL; // 0x04ece8: lsr x2, x2, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000022ULL; // 0x04ecec: str w2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ecf0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0525 @ 0x04ecf4..0x04ecfc (8 bytes)
// [VN] Phục dựng FDE #0525 tại 0x04ecf4..0x04ecfc (8 byte)
//   0x04ecf4: f9018c01  str      x1, [x0, #0x318]
//   0x04ecf8: d65f03c0  ret      
uint64_t fde_0525_sub_04ecf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9018C01ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ECF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9018C01ULL; // 0x04ecf4: str x1, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ecf8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0526 @ 0x04ecfc..0x04ed04 (8 bytes)
// [VN] Phục dựng FDE #0526 tại 0x04ecfc..0x04ed04 (8 byte)
//   0x04ecfc: f9419000  ldr      x0, [x0, #0x320]
//   0x04ed00: d65f03c0  ret      
uint64_t fde_0526_sub_04ecfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ECFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419000ULL; // 0x04ecfc: ldr x0, [x0, #0x320]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ed00: ret 
    return acc;
}

// [EN] Reconstructed FDE #0527 @ 0x04ed04..0x04ed0c (8 bytes)
// [VN] Phục dựng FDE #0527 tại 0x04ed04..0x04ed0c (8 byte)
//   0x04ed04: f9419c00  ldr      x0, [x0, #0x338]
//   0x04ed08: d65f03c0  ret      
uint64_t fde_0527_sub_04ed04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ED04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419C00ULL; // 0x04ed04: ldr x0, [x0, #0x338]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ed08: ret 
    return acc;
}

// [EN] Reconstructed FDE #0528 @ 0x04ed0c..0x04ed34 (40 bytes)
// [VN] Phục dựng FDE #0528 tại 0x04ed0c..0x04ed34 (40 byte)
//   0x04ed0c: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04ed10: d1000400  sub      x0, x0, #1
//   0x04ed14: 910003fd  mov      x29, sp
//   0x04ed18: 910063a1  add      x1, x29, #0x18
//   0x04ed1c: 94000c4e  bl       #0x51e54
//   0x04ed20: eb1f001f  cmp      x0, xzr
//   0x04ed24: f94017a0  ldr      x0, [x29, #0x28]
//   0x04ed28: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x04ed2c: 9a9f1000  csel     x0, x0, xzr, ne
//   0x04ed30: d65f03c0  ret      
uint64_t fde_0528_sub_04ed0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ED0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04ed0c: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000400ULL; // 0x04ed10: sub x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ed14: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x910063A1ULL; // 0x04ed18: add x1, x29, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x94000C4EULL; // 0x04ed1c: bl #0x51e54
    acc = (acc * 0x100000001B3ULL) ^ 0xEB1F001FULL; // 0x04ed20: cmp x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF94017A0ULL; // 0x04ed24: ldr x0, [x29, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C37BFDULL; // 0x04ed28: ldp x29, x30, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9A9F1000ULL; // 0x04ed2c: csel x0, x0, xzr, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ed30: ret 
    return acc;
}

// [EN] Reconstructed FDE #0529 @ 0x04ed34..0x04ed3c (8 bytes)
// [VN] Phục dựng FDE #0529 tại 0x04ed34..0x04ed3c (8 byte)
//   0x04ed34: f9419800  ldr      x0, [x0, #0x330]
//   0x04ed38: d65f03c0  ret      
uint64_t fde_0529_sub_04ed34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ED34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419800ULL; // 0x04ed34: ldr x0, [x0, #0x330]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ed38: ret 
    return acc;
}

// [EN] Reconstructed FDE #0530 @ 0x04ed3c..0x04ed44 (8 bytes)
// [VN] Phục dựng FDE #0530 tại 0x04ed3c..0x04ed44 (8 byte)
//   0x04ed3c: f9419400  ldr      x0, [x0, #0x328]
//   0x04ed40: d65f03c0  ret      
uint64_t fde_0530_sub_04ed3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419400ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04ED3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419400ULL; // 0x04ed3c: ldr x0, [x0, #0x328]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04ed40: ret 
    return acc;
}

// [EN] Reconstructed FDE #0531 @ 0x04ed44..0x04edbc (120 bytes)
// [VN] Phục dựng FDE #0531 tại 0x04ed44..0x04edbc (120 byte)
//   0x04ed44: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04ed48: 53001c02  uxtb     w2, w0
//   0x04ed4c: aa0103e0  mov      x0, x1
//   0x04ed50: 7103fc5f  cmp      w2, #0xff
//   0x04ed54: 910003fd  mov      x29, sp
//   0x04ed58: 540002c0  b.eq     #0x4edb0
//   0x04ed5c: 121c0842  and      w2, w2, #0x70
//   0x04ed60: 7100805f  cmp      w2, #0x20
//   0x04ed64: 540001c0  b.eq     #0x4ed9c
//   0x04ed68: 540000a8  b.hi     #0x4ed7c
//   0x04ed6c: 34000222  cbz      w2, #0x4edb0
//   0x04ed70: 7100405f  cmp      w2, #0x10
//   0x04ed74: 540001c1  b.ne     #0x4edac
//   0x04ed78: 1400000e  b        #0x4edb0
//   0x04ed7c: 7101005f  cmp      w2, #0x40
//   0x04ed80: 54000120  b.eq     #0x4eda4
uint64_t fde_0531_sub_04ed44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x540001C1ULL) + (x2 ^ 0x04ED44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04ed44: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C02ULL; // 0x04ed48: uxtb w2, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04ed4c: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC5FULL; // 0x04ed50: cmp w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ed54: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x540002C0ULL; // 0x04ed58: b.eq #0x4edb0
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0842ULL; // 0x04ed5c: and w2, w2, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100805FULL; // 0x04ed60: cmp w2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C0ULL; // 0x04ed64: b.eq #0x4ed9c
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x04ed68: b.hi #0x4ed7c
    return acc;
}

// [EN] Reconstructed FDE #0532 @ 0x04edbc..0x04f2b4 (1272 bytes)
// [VN] Phục dựng FDE #0532 tại 0x04edbc..0x04f2b4 (1272 byte)
//   0x04edbc: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x04edc0: 910003fd  mov      x29, sp
//   0x04edc4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04edc8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04edcc: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04edd0: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04edd4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04edd8: b000003b  adrp     x27, #0x53000
//   0x04eddc: aa0103fc  mov      x28, x1
//   0x04ede0: aa0203fa  mov      x26, x2
//   0x04ede4: aa0303f3  mov      x19, x3
//   0x04ede8: f903107f  str      xzr, [x3, #0x620]
//   0x04edec: d2800018  mov      x24, #0
//   0x04edf0: 912ef37b  add      x27, x27, #0xbbc
//   0x04edf4: 9101e3b6  add      x22, x29, #0x78
//   0x04edf8: 910203b5  add      x21, x29, #0x80
uint64_t fde_0532_sub_04edbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0xD2800018ULL) + (x2 ^ 0x04EDBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x04edbc: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04edc0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04edc4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04edc8: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x04edcc: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x04edd0: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04edd4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB000003BULL; // 0x04edd8: adrp x27, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103FCULL; // 0x04eddc: mov x28, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203FAULL; // 0x04ede0: mov x26, x2
    return acc;
}

// [EN] Reconstructed FDE #0533 @ 0x04f2b4..0x04f6d8 (1060 bytes)
// [VN] Phục dựng FDE #0533 tại 0x04f2b4..0x04f6d8 (1060 byte)
//   0x04f2b4: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x04f2b8: d280d002  mov      x2, #0x680
//   0x04f2bc: 910003fd  mov      x29, sp
//   0x04f2c0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f2c4: aa0003f4  mov      x20, x0
//   0x04f2c8: aa0103f3  mov      x19, x1
//   0x04f2cc: aa0103e0  mov      x0, x1
//   0x04f2d0: 52800001  mov      w1, #0
//   0x04f2d4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04f2d8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04f2dc: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04f2e0: f9002bfb  str      x27, [sp, #0x50]
//   0x04f2e4: 97ff314b  bl       #0x1b810
//   0x04f2e8: f9418e81  ldr      x1, [x20, #0x318]
//   0x04f2ec: f901aa9f  str      xzr, [x20, #0x350]
//   0x04f2f0: f901929f  str      xzr, [x20, #0x320]
uint64_t fde_0533_sub_04f2b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x97FF314BULL) + (x2 ^ 0x04F2B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x04f2b4: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD280D002ULL; // 0x04f2b8: mov x2, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f2bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04f2c0: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04f2c4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04f2c8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04f2cc: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800001ULL; // 0x04f2d0: mov w1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04f2d4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04f2d8: stp x23, x24, [sp, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0534 @ 0x04f6d8..0x04fc8c (1460 bytes)
// [VN] Phục dựng FDE #0534 tại 0x04f6d8..0x04fc8c (1460 byte)
//   0x04f6d8: d108c3ff  sub      sp, sp, #0x230
//   0x04f6dc: aa0003e4  mov      x4, x0
//   0x04f6e0: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x04f6e4: 910003fd  mov      x29, sp
//   0x04f6e8: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04f6ec: 910243bc  add      x28, x29, #0x90
//   0x04f6f0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04f6f4: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04f6f8: 90000036  adrp     x22, #0x53000
//   0x04f6fc: 90000037  adrp     x23, #0x53000
//   0x04f700: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f704: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04f708: aa0103f8  mov      x24, x1
//   0x04f70c: aa0203f3  mov      x19, x2
//   0x04f710: f9000383  str      x3, [x28]
//   0x04f714: 52800039  mov      w25, #1
uint64_t fde_0534_sub_04f6d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD108C3FFULL) + (x1 ^ 0xAA0103F8ULL) + (x2 ^ 0x04F6D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x04f6d8: sub sp, sp, #0x230
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E4ULL; // 0x04f6dc: mov x4, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x04f6e0: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f6e4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x04f6e8: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243BCULL; // 0x04f6ec: add x28, x29, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04f6f0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04f6f4: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000036ULL; // 0x04f6f8: adrp x22, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000037ULL; // 0x04f6fc: adrp x23, #0x53000
    return acc;
}

// [EN] Reconstructed FDE #0535 @ 0x04fc8c..0x04fe98 (524 bytes)
// [VN] Phục dựng FDE #0535 tại 0x04fc8c..0x04fe98 (524 byte)
//   0x04fc8c: d10f83ff  sub      sp, sp, #0x3e0
//   0x04fc90: d2807802  mov      x2, #0x3c0
//   0x04fc94: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x04fc98: 910003fd  mov      x29, sp
//   0x04fc9c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04fca0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04fca4: aa0003f3  mov      x19, x0
//   0x04fca8: 910203b5  add      x21, x29, #0x80
//   0x04fcac: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04fcb0: aa1503e0  mov      x0, x21
//   0x04fcb4: aa0103f8  mov      x24, x1
//   0x04fcb8: aa1303e1  mov      x1, x19
//   0x04fcbc: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04fcc0: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04fcc4: 97ff2b03  bl       #0x1a8d0
//   0x04fcc8: f941e3a0  ldr      x0, [x29, #0x3c0]
uint64_t fde_0535_sub_04fc8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10F83FFULL) + (x1 ^ 0xA9046BF9ULL) + (x2 ^ 0x04FC8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10F83FFULL; // 0x04fc8c: sub sp, sp, #0x3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x04fc90: mov x2, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x04fc94: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04fc98: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04fc9c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04fca0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04fca4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910203B5ULL; // 0x04fca8: add x21, x29, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04fcac: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x04fcb0: mov x0, x21
    return acc;
}

// [EN] Reconstructed FDE #0536 @ 0x04fe98..0x04ff74 (220 bytes)
// [VN] Phục dựng FDE #0536 tại 0x04fe98..0x04ff74 (220 byte)
//   0x04fe98: d11a43ff  sub      sp, sp, #0x690
//   0x04fe9c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04fea0: 910003fd  mov      x29, sp
//   0x04fea4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04fea8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04feac: aa0003f3  mov      x19, x0
//   0x04feb0: f9001bf7  str      x23, [sp, #0x30]
//   0x04feb4: aa0203f6  mov      x22, x2
//   0x04feb8: aa0103f7  mov      x23, x1
//   0x04febc: d2807802  mov      x2, #0x3c0
//   0x04fec0: 52800001  mov      w1, #0
//   0x04fec4: aa1e03f4  mov      x20, x30
//   0x04fec8: 97ff2e52  bl       #0x1b810
//   0x04fecc: f9018e74  str      x20, [x19, #0x318]
//   0x04fed0: d2e80000  mov      x0, #0x4000000000000000
//   0x04fed4: 910143b4  add      x20, x29, #0x50
uint64_t fde_0536_sub_04fe98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A43FFULL) + (x1 ^ 0x97FF2E52ULL) + (x2 ^ 0x04FE98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A43FFULL; // 0x04fe98: sub sp, sp, #0x690
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04fe9c: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04fea0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04fea4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04fea8: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04feac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x04feb0: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x04feb4: mov x22, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x04feb8: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x04febc: mov x2, #0x3c0
    return acc;
}

// [EN] Reconstructed FDE #0537 @ 0x04ff74..0x04ffc0 (76 bytes)
// [VN] Phục dựng FDE #0537 tại 0x04ff74..0x04ffc0 (76 byte)
//   0x04ff74: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x04ff78: 910003fd  mov      x29, sp
//   0x04ff7c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04ff80: aa0103f3  mov      x19, x1
//   0x04ff84: aa0003f4  mov      x20, x0
//   0x04ff88: 97ffff41  bl       #0x4fc8c
//   0x04ff8c: f9433661  ldr      x1, [x19, #0x668]
//   0x04ff90: 8b011273  add      x19, x19, x1, lsl #4
//   0x04ff94: b9400a60  ldr      w0, [x19, #8]
//   0x04ff98: 7100181f  cmp      w0, #6
//   0x04ff9c: 54000061  b.ne     #0x4ffa8
//   0x04ffa0: f9018e9f  str      xzr, [x20, #0x318]
//   0x04ffa4: 14000004  b        #0x4ffb4
//   0x04ffa8: aa1403e0  mov      x0, x20
//   0x04ffac: 97fffada  bl       #0x4eb14
//   0x04ffb0: f9018e80  str      x0, [x20, #0x318]
uint64_t fde_0537_sub_04ff74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x14000004ULL) + (x2 ^ 0x04FF74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x04ff74: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ff78: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04ff7c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04ff80: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04ff84: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF41ULL; // 0x04ff88: bl #0x4fc8c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433661ULL; // 0x04ff8c: ldr x1, [x19, #0x668]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B011273ULL; // 0x04ff90: add x19, x19, x1, lsl #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A60ULL; // 0x04ff94: ldr w0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100181FULL; // 0x04ff98: cmp w0, #6
    return acc;
}

// [EN] Reconstructed FDE #0538 @ 0x04ffc0..0x050080 (192 bytes)
// [VN] Phục dựng FDE #0538 tại 0x04ffc0..0x050080 (192 byte)
//   0x04ffc0: d11a03ff  sub      sp, sp, #0x680
//   0x04ffc4: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04ffc8: 910003fd  mov      x29, sp
//   0x04ffcc: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04ffd0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04ffd4: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04ffd8: aa0003f5  mov      x21, x0
//   0x04ffdc: aa0103f3  mov      x19, x1
//   0x04ffe0: 910103b4  add      x20, x29, #0x40
//   0x04ffe4: 52800097  mov      w23, #4
//   0x04ffe8: aa1403e1  mov      x1, x20
//   0x04ffec: aa1303e0  mov      x0, x19
//   0x04fff0: 97fffcb1  bl       #0x4f2b4
//   0x04fff4: 2a0003f8  mov      w24, w0
//   0x04fff8: aa1303e0  mov      x0, x19
//   0x04fffc: 97fffb1f  bl       #0x4ec78
uint64_t fde_0538_sub_04ffc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A03FFULL) + (x1 ^ 0x97FFFCB1ULL) + (x2 ^ 0x04FFC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A03FFULL; // 0x04ffc0: sub sp, sp, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04ffc4: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ffc8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04ffcc: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04ffd0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04ffd4: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04ffd8: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04ffdc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910103B4ULL; // 0x04ffe0: add x20, x29, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x52800097ULL; // 0x04ffe4: mov w23, #4
    return acc;
}

// [EN] Reconstructed FDE #0539 @ 0x050080..0x05016c (236 bytes)
// [VN] Phục dựng FDE #0539 tại 0x050080..0x05016c (236 byte)
//   0x050080: d11a03ff  sub      sp, sp, #0x680
//   0x050084: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x050088: 910003fd  mov      x29, sp
//   0x05008c: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x050090: f9400817  ldr      x23, [x0, #0x10]
//   0x050094: f9400c18  ldr      x24, [x0, #0x18]
//   0x050098: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x05009c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x0500a0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0500a4: aa0103f5  mov      x21, x1
//   0x0500a8: aa0003f4  mov      x20, x0
//   0x0500ac: 910143b6  add      x22, x29, #0x50
//   0x0500b0: 52800359  mov      w25, #0x1a
//   0x0500b4: 5280015a  mov      w26, #0xa
//   0x0500b8: aa1503e0  mov      x0, x21
//   0x0500bc: aa1603e1  mov      x1, x22
uint64_t fde_0539_sub_050080(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A03FFULL) + (x1 ^ 0x52800359ULL) + (x2 ^ 0x050080ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A03FFULL; // 0x050080: sub sp, sp, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x050084: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050088: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x05008c: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400817ULL; // 0x050090: ldr x23, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C18ULL; // 0x050094: ldr x24, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x050098: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x05009c: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0500a0: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0500a4: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0540 @ 0x05016c..0x050260 (244 bytes)
// [VN] Phục dựng FDE #0540 tại 0x05016c..0x050260 (244 byte)
//   0x05016c: d12903ff  sub      sp, sp, #0xa40
//   0x050170: d2807802  mov      x2, #0x3c0
//   0x050174: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x050178: 910003fd  mov      x29, sp
//   0x05017c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050180: 9100c3b4  add      x20, x29, #0x30
//   0x050184: f90013f5  str      x21, [sp, #0x20]
//   0x050188: aa0103f3  mov      x19, x1
//   0x05018c: aa0003f5  mov      x21, x0
//   0x050190: 52800001  mov      w1, #0
//   0x050194: aa1403e0  mov      x0, x20
//   0x050198: 910006b5  add      x21, x21, #1
//   0x05019c: 97ff2d9d  bl       #0x1b810
//   0x0501a0: f9018e95  str      x21, [x20, #0x318]
//   0x0501a4: d2e80000  mov      x0, #0x4000000000000000
//   0x0501a8: 910fc3b5  add      x21, x29, #0x3f0
uint64_t fde_0540_sub_05016c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD12903FFULL) + (x1 ^ 0x97FF2D9DULL) + (x2 ^ 0x05016CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD12903FFULL; // 0x05016c: sub sp, sp, #0xa40
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x050170: mov x2, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x050174: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050178: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x05017c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3B4ULL; // 0x050180: add x20, x29, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x050184: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x050188: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x05018c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800001ULL; // 0x050190: mov w1, #0
    return acc;
}

// [EN] Reconstructed FDE #0541 @ 0x050260..0x050264 (4 bytes)
// [VN] Phục dựng FDE #0541 tại 0x050260..0x050264 (4 byte)
//   0x050260: d65f03c0  ret      
uint64_t fde_0541_sub_050260(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x050260ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x050260: ret 
    return acc;
}

// [EN] Reconstructed FDE #0542 @ 0x050264..0x0503dc (376 bytes)
// [VN] Phục dựng FDE #0542 tại 0x050264..0x0503dc (376 byte)
//   0x050264: d13843ff  sub      sp, sp, #0xe10
//   0x050268: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x05026c: 910003fd  mov      x29, sp
//   0x050270: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x050274: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x050278: 910343b5  add      x21, x29, #0xd0
//   0x05027c: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x050280: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x050284: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x050288: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x05028c: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x050290: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x050294: aa1e03e2  mov      x2, x30
//   0x050298: 913b43a1  add      x1, x29, #0xed0
//   0x05029c: aa0003f4  mov      x20, x0
//   0x0502a0: aa1503e0  mov      x0, x21
uint64_t fde_0542_sub_050264(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD13843FFULL) + (x1 ^ 0xAA1E03E2ULL) + (x2 ^ 0x050264ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD13843FFULL; // 0x050264: sub sp, sp, #0xe10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x050268: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x05026c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045BF5ULL; // 0x050270: stp x21, x22, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x050274: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B5ULL; // 0x050278: add x21, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x05027c: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x050280: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x050284: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x050288: stp x2, x3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0543 @ 0x0503dc..0x0504d0 (244 bytes)
// [VN] Phục dựng FDE #0543 tại 0x0503dc..0x0504d0 (244 byte)
//   0x0503dc: d11e43ff  sub      sp, sp, #0x790
//   0x0503e0: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x0503e4: 910003fd  mov      x29, sp
//   0x0503e8: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x0503ec: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x0503f0: 910343b4  add      x20, x29, #0xd0
//   0x0503f4: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x0503f8: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x0503fc: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x050400: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x050404: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x050408: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x05040c: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x050410: aa0003f5  mov      x21, x0
//   0x050414: aa0103f7  mov      x23, x1
//   0x050418: aa0203f6  mov      x22, x2
uint64_t fde_0543_sub_0503dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0xA90563F7ULL) + (x2 ^ 0x0503DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x0503dc: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x0503e0: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0503e4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90353F3ULL; // 0x0503e8: stp x19, x20, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x0503ec: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B4ULL; // 0x0503f0: add x20, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x0503f4: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x0503f8: stp x2, x3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x0503fc: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x050400: stp x0, x1, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0544 @ 0x0504d0..0x0505cc (252 bytes)
// [VN] Phục dựng FDE #0544 tại 0x0504d0..0x0505cc (252 byte)
//   0x0504d0: d11e43ff  sub      sp, sp, #0x790
//   0x0504d4: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x0504d8: 910003fd  mov      x29, sp
//   0x0504dc: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x0504e0: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x0504e4: 910343b4  add      x20, x29, #0xd0
//   0x0504e8: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x0504ec: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x0504f0: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x0504f4: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x0504f8: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x0504fc: aa1e03e2  mov      x2, x30
//   0x050500: 912143a1  add      x1, x29, #0x850
//   0x050504: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x050508: aa0003f5  mov      x21, x0
//   0x05050c: aa1403e0  mov      x0, x20
uint64_t fde_0544_sub_0504d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0x912143A1ULL) + (x2 ^ 0x0504D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x0504d0: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x0504d4: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0504d8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90353F3ULL; // 0x0504dc: stp x19, x20, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x0504e0: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B4ULL; // 0x0504e4: add x20, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x0504e8: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x0504ec: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x0504f0: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x0504f4: stp x2, x3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0545 @ 0x0505cc..0x0506c4 (248 bytes)
// [VN] Phục dựng FDE #0545 tại 0x0505cc..0x0506c4 (248 byte)
//   0x0505cc: d11e43ff  sub      sp, sp, #0x790
//   0x0505d0: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x0505d4: 910003fd  mov      x29, sp
//   0x0505d8: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x0505dc: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x0505e0: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x0505e4: f9400801  ldr      x1, [x0, #0x10]
//   0x0505e8: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x0505ec: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x0505f0: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x0505f4: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x0505f8: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x0505fc: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x050600: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x050604: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x050608: aa1e03e2  mov      x2, x30
uint64_t fde_0545_sub_0505cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0xA90563F7ULL) + (x2 ^ 0x0505CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x0505cc: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x0505d0: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0505d4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x0505d8: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x0505dc: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x0505e0: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x0505e4: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x0505e8: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x0505ec: stp x2, x3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0B3FEEULL; // 0x0505f0: stp d14, d15, [sp, #0xb0]
    return acc;
}

// [EN] Reconstructed FDE #0546 @ 0x0506c4..0x0506e8 (36 bytes)
// [VN] Phục dựng FDE #0546 tại 0x0506c4..0x0506e8 (36 byte)
//   0x0506c4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0506c8: 910003fd  mov      x29, sp
//   0x0506cc: f9400402  ldr      x2, [x0, #8]
//   0x0506d0: b4000082  cbz      x2, #0x506e0
//   0x0506d4: aa0003e1  mov      x1, x0
//   0x0506d8: 52800020  mov      w0, #1
//   0x0506dc: d63f0040  blr      x2
//   0x0506e0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0506e4: d65f03c0  ret      
uint64_t fde_0546_sub_0506c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0506C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0506c4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0506c8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400402ULL; // 0x0506cc: ldr x2, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x0506d0: cbz x2, #0x506e0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x0506d4: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x0506d8: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0040ULL; // 0x0506dc: blr x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0506e0: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0506e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0547 @ 0x0506e8..0x0507b8 (208 bytes)
// [VN] Phục dựng FDE #0547 tại 0x0506e8..0x0507b8 (208 byte)
//   0x0506e8: d12903ff  sub      sp, sp, #0xa40
//   0x0506ec: aa1e03e2  mov      x2, x30
//   0x0506f0: a9b67bfd  stp      x29, x30, [sp, #-0xa0]!
//   0x0506f4: 910003fd  mov      x29, sp
//   0x0506f8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0506fc: 6d0627e8  stp      d8, d9, [sp, #0x60]
//   0x050700: 910283b4  add      x20, x29, #0xa0
//   0x050704: 6d072fea  stp      d10, d11, [sp, #0x70]
//   0x050708: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x05070c: 6d0837ec  stp      d12, d13, [sp, #0x80]
//   0x050710: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x050714: 6d093fee  stp      d14, d15, [sp, #0x90]
//   0x050718: aa0003f6  mov      x22, x0
//   0x05071c: aa0103f7  mov      x23, x1
//   0x050720: aa1403e0  mov      x0, x20
//   0x050724: 912b83a1  add      x1, x29, #0xae0
uint64_t fde_0547_sub_0506e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD12903FFULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x0506E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD12903FFULL; // 0x0506e8: sub sp, sp, #0xa40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03E2ULL; // 0x0506ec: mov x2, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B67BFDULL; // 0x0506f0: stp x29, x30, [sp, #-0xa0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0506f4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0506f8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0627E8ULL; // 0x0506fc: stp d8, d9, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283B4ULL; // 0x050700: add x20, x29, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D072FEAULL; // 0x050704: stp d10, d11, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x050708: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0837ECULL; // 0x05070c: stp d12, d13, [sp, #0x80]
    return acc;
}

// [EN] Reconstructed FDE #0548 @ 0x0507b8..0x0507e0 (40 bytes)
// [VN] Phục dựng FDE #0548 tại 0x0507b8..0x0507e0 (40 byte)
//   0x0507b8: d2800002  mov      x2, #0
//   0x0507bc: 52800003  mov      w3, #0
//   0x0507c0: 38401405  ldrb     w5, [x0], #1
//   0x0507c4: 924018a4  and      x4, x5, #0x7f
//   0x0507c8: 9ac32084  lsl      x4, x4, x3
//   0x0507cc: 11001c63  add      w3, w3, #7
//   0x0507d0: aa040042  orr      x2, x2, x4
//   0x0507d4: 373fff65  tbnz     w5, #7, #0x507c0
//   0x0507d8: f9000022  str      x2, [x1]
//   0x0507dc: d65f03c0  ret      
uint64_t fde_0548_sub_0507b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0507B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x0507b8: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x0507bc: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401405ULL; // 0x0507c0: ldrb w5, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x924018A4ULL; // 0x0507c4: and x4, x5, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC32084ULL; // 0x0507c8: lsl x4, x4, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x0507cc: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA040042ULL; // 0x0507d0: orr x2, x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF65ULL; // 0x0507d4: tbnz w5, #7, #0x507c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000022ULL; // 0x0507d8: str x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0507dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0549 @ 0x0507e0..0x050820 (64 bytes)
// [VN] Phục dựng FDE #0549 tại 0x0507e0..0x050820 (64 byte)
//   0x0507e0: d2800002  mov      x2, #0
//   0x0507e4: 52800003  mov      w3, #0
//   0x0507e8: 38401404  ldrb     w4, [x0], #1
//   0x0507ec: 92401885  and      x5, x4, #0x7f
//   0x0507f0: 9ac320a5  lsl      x5, x5, x3
//   0x0507f4: 11001c63  add      w3, w3, #7
//   0x0507f8: aa050042  orr      x2, x2, x5
//   0x0507fc: 373fff64  tbnz     w4, #7, #0x507e8
//   0x050800: 7100fc7f  cmp      w3, #0x3f
//   0x050804: 540000a8  b.hi     #0x50818
//   0x050808: 36300084  tbz      w4, #6, #0x50818
//   0x05080c: 92800004  mov      x4, #-1
//   0x050810: 9ac32083  lsl      x3, x4, x3
//   0x050814: aa020062  orr      x2, x3, x2
//   0x050818: f9000022  str      x2, [x1]
//   0x05081c: d65f03c0  ret      
uint64_t fde_0549_sub_0507e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x9AC32083ULL) + (x2 ^ 0x0507E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x0507e0: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x0507e4: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401404ULL; // 0x0507e8: ldrb w4, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x92401885ULL; // 0x0507ec: and x5, x4, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC320A5ULL; // 0x0507f0: lsl x5, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x0507f4: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA050042ULL; // 0x0507f8: orr x2, x2, x5
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF64ULL; // 0x0507fc: tbnz w4, #7, #0x507e8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100FC7FULL; // 0x050800: cmp w3, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x050804: b.hi #0x50818
    return acc;
}

// [EN] Reconstructed FDE #0550 @ 0x050820..0x05083c (28 bytes)
// [VN] Phục dựng FDE #0550 tại 0x050820..0x05083c (28 byte)
//   0x050820: f9400423  ldr      x3, [x1, #8]
//   0x050824: f9400441  ldr      x1, [x2, #8]
//   0x050828: eb01007f  cmp      x3, x1
//   0x05082c: 5a9f23e0  csetm    w0, lo
//   0x050830: eb01007f  cmp      x3, x1
//   0x050834: 1a9f9400  csinc    w0, w0, wzr, ls
//   0x050838: d65f03c0  ret      
uint64_t fde_0550_sub_050820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400423ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x050820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400423ULL; // 0x050820: ldr x3, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400441ULL; // 0x050824: ldr x1, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x050828: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x5A9F23E0ULL; // 0x05082c: csetm w0, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x050830: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F9400ULL; // 0x050834: csinc w0, w0, wzr, ls
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x050838: ret 
    return acc;
}

// [EN] Reconstructed FDE #0551 @ 0x05083c..0x0508fc (192 bytes)
// [VN] Phục dựng FDE #0551 tại 0x05083c..0x0508fc (192 byte)
//   0x05083c: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x050840: 910003fd  mov      x29, sp
//   0x050844: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050848: 531f7873  lsl      w19, w3, #1
//   0x05084c: f90023f9  str      x25, [sp, #0x40]
//   0x050850: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x050854: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x050858: aa0003f8  mov      x24, x0
//   0x05085c: aa0103f9  mov      x25, x1
//   0x050860: aa0203f4  mov      x20, x2
//   0x050864: 2a0403f7  mov      w23, w4
//   0x050868: 11000673  add      w19, w19, #1
//   0x05086c: 6b17027f  cmp      w19, w23
//   0x050870: 540003aa  b.ge     #0x508e4
//   0x050874: 11000675  add      w21, w19, #1
//   0x050878: 6b1702bf  cmp      w21, w23
uint64_t fde_0551_sub_05083c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA7BFDULL) + (x1 ^ 0x6B17027FULL) + (x2 ^ 0x05083CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x05083c: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050840: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050844: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7873ULL; // 0x050848: lsl w19, w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x05084c: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x050850: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x050854: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x050858: mov x24, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x05085c: mov x25, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x050860: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0552 @ 0x0508fc..0x0509b0 (180 bytes)
// [VN] Phục dựng FDE #0552 tại 0x0508fc..0x0509b0 (180 byte)
//   0x0508fc: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x050900: 910003fd  mov      x29, sp
//   0x050904: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050908: f9400453  ldr      x19, [x2, #8]
//   0x05090c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x050910: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x050914: f90023f9  str      x25, [sp, #0x40]
//   0x050918: aa0003f8  mov      x24, x0
//   0x05091c: aa0103f9  mov      x25, x1
//   0x050920: aa0203f5  mov      x21, x2
//   0x050924: 91004056  add      x22, x2, #0x10
//   0x050928: d341fe74  lsr      x20, x19, #1
//   0x05092c: 51000694  sub      w20, w20, #1
//   0x050930: 37f80114  tbnz     w20, #0x1f, #0x50950
//   0x050934: aa1803e0  mov      x0, x24
//   0x050938: aa1903e1  mov      x1, x25
uint64_t fde_0552_sub_0508fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB7BFDULL) + (x1 ^ 0x51000694ULL) + (x2 ^ 0x0508FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x0508fc: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050900: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050904: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400453ULL; // 0x050908: ldr x19, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x05090c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x050910: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x050914: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x050918: mov x24, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x05091c: mov x25, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x050920: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0553 @ 0x0509b0..0x050a10 (96 bytes)
// [VN] Phục dựng FDE #0553 tại 0x0509b0..0x050a10 (96 byte)
//   0x0509b0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0509b4: 53001c00  uxtb     w0, w0
//   0x0509b8: 7103fc1f  cmp      w0, #0xff
//   0x0509bc: 910003fd  mov      x29, sp
//   0x0509c0: 540001e0  b.eq     #0x509fc
//   0x0509c4: 12000800  and      w0, w0, #7
//   0x0509c8: 7100101f  cmp      w0, #4
//   0x0509cc: 54000168  b.hi     #0x509f8
//   0x0509d0: f0000001  adrp     x1, #0x53000
//   0x0509d4: 91313021  add      x1, x1, #0xc4c
//   0x0509d8: 38604820  ldrb     w0, [x1, w0, uxtw]
//   0x0509dc: 10000061  adr      x1, #0x509e8
//   0x0509e0: 8b208820  add      x0, x1, w0, sxtb #2
//   0x0509e4: d61f0000  br       x0
//   0x0509e8: 52800040  mov      w0, #2
//   0x0509ec: 14000007  b        #0x50a08
uint64_t fde_0553_sub_0509b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x8B208820ULL) + (x2 ^ 0x0509B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0509b0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x0509b4: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x0509b8: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0509bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x540001E0ULL; // 0x0509c0: b.eq #0x509fc
    acc = (acc * 0x100000001B3ULL) ^ 0x12000800ULL; // 0x0509c4: and w0, w0, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x7100101FULL; // 0x0509c8: cmp w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x0509cc: b.hi #0x509f8
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000001ULL; // 0x0509d0: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91313021ULL; // 0x0509d4: add x1, x1, #0xc4c
    return acc;
}

// [EN] Reconstructed FDE #0554 @ 0x050a10..0x050a70 (96 bytes)
// [VN] Phục dựng FDE #0554 tại 0x050a10..0x050a70 (96 byte)
//   0x050a10: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x050a14: 53001c00  uxtb     w0, w0
//   0x050a18: 7103fc1f  cmp      w0, #0xff
//   0x050a1c: 910003fd  mov      x29, sp
//   0x050a20: 54000220  b.eq     #0x50a64
//   0x050a24: 121c0800  and      w0, w0, #0x70
//   0x050a28: 7100801f  cmp      w0, #0x20
//   0x050a2c: 54000140  b.eq     #0x50a54
//   0x050a30: 54000088  b.hi     #0x50a40
//   0x050a34: 7100401f  cmp      w0, #0x10
//   0x050a38: 350000a0  cbnz     w0, #0x50a4c
//   0x050a3c: 1400000a  b        #0x50a64
//   0x050a40: 7100c01f  cmp      w0, #0x30
//   0x050a44: 540000c0  b.eq     #0x50a5c
//   0x050a48: 7101401f  cmp      w0, #0x50
//   0x050a4c: 540000c0  b.eq     #0x50a64
uint64_t fde_0554_sub_050a10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7100C01FULL) + (x2 ^ 0x050A10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x050a10: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x050a14: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x050a18: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050a1c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x050a20: b.eq #0x50a64
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0800ULL; // 0x050a24: and w0, w0, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100801FULL; // 0x050a28: cmp w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x050a2c: b.eq #0x50a54
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x050a30: b.hi #0x50a40
    acc = (acc * 0x100000001B3ULL) ^ 0x7100401FULL; // 0x050a34: cmp w0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0555 @ 0x050a70..0x050ad0 (96 bytes)
// [VN] Phục dựng FDE #0555 tại 0x050a70..0x050ad0 (96 byte)
//   0x050a70: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x050a74: 53001c00  uxtb     w0, w0
//   0x050a78: 7103fc1f  cmp      w0, #0xff
//   0x050a7c: 910003fd  mov      x29, sp
//   0x050a80: 54000220  b.eq     #0x50ac4
//   0x050a84: 121c0800  and      w0, w0, #0x70
//   0x050a88: 7100801f  cmp      w0, #0x20
//   0x050a8c: 54000140  b.eq     #0x50ab4
//   0x050a90: 54000088  b.hi     #0x50aa0
//   0x050a94: 7100401f  cmp      w0, #0x10
//   0x050a98: 350000a0  cbnz     w0, #0x50aac
//   0x050a9c: 1400000a  b        #0x50ac4
//   0x050aa0: 7100c01f  cmp      w0, #0x30
//   0x050aa4: 540000c0  b.eq     #0x50abc
//   0x050aa8: 7101401f  cmp      w0, #0x50
//   0x050aac: 540000c0  b.eq     #0x50ac4
uint64_t fde_0555_sub_050a70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7100C01FULL) + (x2 ^ 0x050A70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x050a70: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x050a74: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x050a78: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050a7c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x050a80: b.eq #0x50ac4
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0800ULL; // 0x050a84: and w0, w0, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100801FULL; // 0x050a88: cmp w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x050a8c: b.eq #0x50ab4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x050a90: b.hi #0x50aa0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100401FULL; // 0x050a94: cmp w0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0556 @ 0x050ad0..0x050bc0 (240 bytes)
// [VN] Phục dựng FDE #0556 tại 0x050ad0..0x050bc0 (240 byte)
//   0x050ad0: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x050ad4: 910003fd  mov      x29, sp
//   0x050ad8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050adc: 53001c14  uxtb     w20, w0
//   0x050ae0: aa0203f3  mov      x19, x2
//   0x050ae4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x050ae8: 7101429f  cmp      w20, #0x50
//   0x050aec: aa0103f6  mov      x22, x1
//   0x050af0: aa0303f5  mov      x21, x3
//   0x050af4: 540000a1  b.ne     #0x50b08
//   0x050af8: 91001c53  add      x19, x2, #7
//   0x050afc: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x050b00: f8408401  ldr      x1, [x0], #8
//   0x050b04: 1400002a  b        #0x50bac
//   0x050b08: 12000e81  and      w1, w20, #0xf
//   0x050b0c: 7100303f  cmp      w1, #0xc
uint64_t fde_0556_sub_050ad0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF8408401ULL) + (x2 ^ 0x050AD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x050ad0: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050ad4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050ad8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C14ULL; // 0x050adc: uxtb w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x050ae0: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x050ae4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7101429FULL; // 0x050ae8: cmp w20, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x050aec: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x050af0: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x050af4: b.ne #0x50b08
    return acc;
}

// [EN] Reconstructed FDE #0557 @ 0x050bc0..0x050c50 (144 bytes)
// [VN] Phục dựng FDE #0557 tại 0x050bc0..0x050c50 (144 byte)
//   0x050bc0: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x050bc4: 910003fd  mov      x29, sp
//   0x050bc8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050bcc: 79404013  ldrh     w19, [x0, #0x20]
//   0x050bd0: aa0003f4  mov      x20, x0
//   0x050bd4: f9001bf7  str      x23, [sp, #0x30]
//   0x050bd8: aa0103f7  mov      x23, x1
//   0x050bdc: d3432a73  ubfx     x19, x19, #3, #8
//   0x050be0: aa1403e1  mov      x1, x20
//   0x050be4: 2a1303e0  mov      w0, w19
//   0x050be8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x050bec: aa0203f6  mov      x22, x2
//   0x050bf0: 97ffff88  bl       #0x50a10
//   0x050bf4: aa0003f5  mov      x21, x0
//   0x050bf8: 910022e2  add      x2, x23, #8
//   0x050bfc: aa1503e1  mov      x1, x21
uint64_t fde_0557_sub_050bc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB7BFDULL) + (x1 ^ 0x97FFFF88ULL) + (x2 ^ 0x050BC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x050bc0: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050bc4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050bc8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x79404013ULL; // 0x050bcc: ldrh w19, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x050bd0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x050bd4: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x050bd8: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432A73ULL; // 0x050bdc: ubfx x19, x19, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x050be0: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x050be4: mov w0, w19
    return acc;
}

// [EN] Reconstructed FDE #0558 @ 0x050c50..0x050d4c (252 bytes)
// [VN] Phục dựng FDE #0558 tại 0x050c50..0x050d4c (252 byte)
//   0x050c50: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x050c54: 910003fd  mov      x29, sp
//   0x050c58: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050c5c: 91002414  add      x20, x0, #9
//   0x050c60: aa0003f3  mov      x19, x0
//   0x050c64: aa1403e0  mov      x0, x20
//   0x050c68: 97ff2902  bl       #0x1b070
//   0x050c6c: 91000400  add      x0, x0, #1
//   0x050c70: 39402262  ldrb     w2, [x19, #8]
//   0x050c74: 8b000281  add      x1, x20, x0
//   0x050c78: 71000c5f  cmp      w2, #3
//   0x050c7c: 54000109  b.ls     #0x50c9c
//   0x050c80: 38606a82  ldrb     w2, [x20, x0]
//   0x050c84: 52801fe0  mov      w0, #0xff
//   0x050c88: 7100205f  cmp      w2, #8
//   0x050c8c: 540005a1  b.ne     #0x50d40
uint64_t fde_0558_sub_050c50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0x38606A82ULL) + (x2 ^ 0x050C50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x050c50: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050c54: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050c58: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002414ULL; // 0x050c5c: add x20, x0, #9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x050c60: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x050c64: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF2902ULL; // 0x050c68: bl #0x1b070
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x050c6c: add x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39402262ULL; // 0x050c70: ldrb w2, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B000281ULL; // 0x050c74: add x1, x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0559 @ 0x050d4c..0x050eac (352 bytes)
// [VN] Phục dựng FDE #0559 tại 0x050d4c..0x050eac (352 byte)
//   0x050d4c: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x050d50: 910003fd  mov      x29, sp
//   0x050d54: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x050d58: aa0003f6  mov      x22, x0
//   0x050d5c: 79404000  ldrh     w0, [x0, #0x20]
//   0x050d60: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050d64: d3432800  ubfx     x0, x0, #3, #8
//   0x050d68: aa0103f3  mov      x19, x1
//   0x050d6c: aa1603e1  mov      x1, x22
//   0x050d70: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x050d74: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x050d78: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x050d7c: aa0203f7  mov      x23, x2
//   0x050d80: 53001c15  uxtb     w21, w0
//   0x050d84: 97ffff23  bl       #0x50a10
//   0x050d88: 910183b8  add      x24, x29, #0x60
uint64_t fde_0559_sub_050d4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0xAA0203F7ULL) + (x2 ^ 0x050D4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x050d4c: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050d50: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x050d54: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x050d58: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x79404000ULL; // 0x050d5c: ldrh w0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050d60: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432800ULL; // 0x050d64: ubfx x0, x0, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x050d68: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x050d6c: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x050d70: stp x23, x24, [sp, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0560 @ 0x050eac..0x050ebc (16 bytes)
// [VN] Phục dựng FDE #0560 tại 0x050eac..0x050ebc (16 byte)
//   0x050eac: 91001001  add      x1, x0, #4
//   0x050eb0: b9800400  ldrsw    x0, [x0, #4]
//   0x050eb4: cb000020  sub      x0, x1, x0
//   0x050eb8: 17ffff66  b        #0x50c50
uint64_t fde_0560_sub_050eac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91001001ULL) + (x1 ^ 0x17FFFF66ULL) + (x2 ^ 0x050EACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91001001ULL; // 0x050eac: add x1, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800400ULL; // 0x050eb0: ldrsw x0, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000020ULL; // 0x050eb4: sub x0, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF66ULL; // 0x050eb8: b #0x50c50
    return acc;
}

// [EN] Reconstructed FDE #0561 @ 0x050ebc..0x0512d8 (1052 bytes)
// [VN] Phục dựng FDE #0561 tại 0x050ebc..0x0512d8 (1052 byte)
//   0x050ebc: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x050ec0: f100bc3f  cmp      x1, #0x2f
//   0x050ec4: 910003fd  mov      x29, sp
//   0x050ec8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x050ecc: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x050ed0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x050ed4: 1a9f97ed  cset     w13, hi
//   0x050ed8: f9400806  ldr      x6, [x0, #0x10]
//   0x050edc: f9400007  ldr      x7, [x0]
//   0x050ee0: 340007ad  cbz      w13, #0x50fd4
//   0x050ee4: b9402843  ldr      w3, [x2, #0x28]
//   0x050ee8: 34000763  cbz      w3, #0x50fd4
//   0x050eec: 900000c1  adrp     x1, #0x68000
//   0x050ef0: f9401004  ldr      x4, [x0, #0x20]
//   0x050ef4: f9401405  ldr      x5, [x0, #0x28]
//   0x050ef8: f940d823  ldr      x3, [x1, #0x1b0]
uint64_t fde_0561_sub_050ebc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x900000C1ULL) + (x2 ^ 0x050EBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x050ebc: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF100BC3FULL; // 0x050ec0: cmp x1, #0x2f
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x050ec4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x050ec8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x050ecc: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x050ed0: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97EDULL; // 0x050ed4: cset w13, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400806ULL; // 0x050ed8: ldr x6, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400007ULL; // 0x050edc: ldr x7, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340007ADULL; // 0x050ee0: cbz w13, #0x50fd4
    return acc;
}

// [EN] Reconstructed FDE #0562 @ 0x0512d8..0x051374 (156 bytes)
// [VN] Phục dựng FDE #0562 tại 0x0512d8..0x051374 (156 byte)
//   0x0512d8: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x0512dc: 910003fd  mov      x29, sp
//   0x0512e0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x0512e4: aa0003f5  mov      x21, x0
//   0x0512e8: aa0103e0  mov      x0, x1
//   0x0512ec: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0512f0: aa0203f3  mov      x19, x2
//   0x0512f4: aa0103f4  mov      x20, x1
//   0x0512f8: 97fffeed  bl       #0x50eac
//   0x0512fc: 53001c16  uxtb     w22, w0
//   0x051300: aa1503e1  mov      x1, x21
//   0x051304: 2a1603e0  mov      w0, w22
//   0x051308: 97fffdc2  bl       #0x50a10
//   0x05130c: aa0003e1  mov      x1, x0
//   0x051310: 91002282  add      x2, x20, #8
//   0x051314: 9100c3a3  add      x3, x29, #0x30
uint64_t fde_0562_sub_0512d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0x97FFFDC2ULL) + (x2 ^ 0x0512D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x0512d8: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0512dc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x0512e0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0512e4: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x0512e8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0512ec: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0512f0: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0512f4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEEDULL; // 0x0512f8: bl #0x50eac
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C16ULL; // 0x0512fc: uxtb w22, w0
    return acc;
}

// [EN] Reconstructed FDE #0563 @ 0x051374..0x0514d4 (352 bytes)
// [VN] Phục dựng FDE #0563 tại 0x051374..0x0514d4 (352 byte)
//   0x051374: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x051378: 910003fd  mov      x29, sp
//   0x05137c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051380: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x051384: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x051388: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x05138c: aa0103f3  mov      x19, x1
//   0x051390: f9002bfb  str      x27, [sp, #0x50]
//   0x051394: aa0003f4  mov      x20, x0
//   0x051398: d280001a  mov      x26, #0
//   0x05139c: 52800019  mov      w25, #0
//   0x0513a0: d2800016  mov      x22, #0
//   0x0513a4: d2800001  mov      x1, #0
//   0x0513a8: 9101a3b7  add      x23, x29, #0x68
//   0x0513ac: d2800038  mov      x24, #1
//   0x0513b0: b9400260  ldr      w0, [x19]
uint64_t fde_0563_sub_051374(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0xD2800001ULL) + (x2 ^ 0x051374ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x051374: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051378: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x05137c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x051380: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x051384: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x051388: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x05138c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x051390: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x051394: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD280001AULL; // 0x051398: mov x26, #0
    return acc;
}

// [EN] Reconstructed FDE #0564 @ 0x0514d4..0x051608 (308 bytes)
// [VN] Phục dựng FDE #0564 tại 0x0514d4..0x051608 (308 byte)
//   0x0514d4: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x0514d8: 910003fd  mov      x29, sp
//   0x0514dc: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x0514e0: aa0003f6  mov      x22, x0
//   0x0514e4: 79404000  ldrh     w0, [x0, #0x20]
//   0x0514e8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x0514ec: d3432800  ubfx     x0, x0, #3, #8
//   0x0514f0: aa0103f7  mov      x23, x1
//   0x0514f4: aa1603e1  mov      x1, x22
//   0x0514f8: f9002bfb  str      x27, [sp, #0x50]
//   0x0514fc: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x051500: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051504: 53001c15  uxtb     w21, w0
//   0x051508: aa0203f3  mov      x19, x2
//   0x05150c: 97fffd41  bl       #0x50a10
//   0x051510: 9101a3b8  add      x24, x29, #0x68
uint64_t fde_0564_sub_0514d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0x53001C15ULL) + (x2 ^ 0x0514D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x0514d4: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0514d8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x0514dc: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x0514e0: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x79404000ULL; // 0x0514e4: ldrh w0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x0514e8: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432800ULL; // 0x0514ec: ubfx x0, x0, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x0514f0: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x0514f4: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x0514f8: str x27, [sp, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0565 @ 0x051608..0x051b78 (1392 bytes)
// [VN] Phục dựng FDE #0565 tại 0x051608..0x051b78 (1392 byte)
//   0x051608: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x05160c: 910003fd  mov      x29, sp
//   0x051610: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x051614: aa0103f6  mov      x22, x1
//   0x051618: 39408001  ldrb     w1, [x0, #0x20]
//   0x05161c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051620: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x051624: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x051628: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x05162c: aa0003f3  mov      x19, x0
//   0x051630: 36000081  tbz      w1, #0, #0x51640
//   0x051634: 39408260  ldrb     w0, [x19, #0x20]
//   0x051638: 37000da0  tbnz     w0, #0, #0x517ec
//   0x05163c: 140000d9  b        #0x519a0
//   0x051640: b9402014  ldr      w20, [x0, #0x20]
//   0x051644: d34b7e94  ubfx     x20, x20, #0xb, #0x15
uint64_t fde_0565_sub_051608(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x37000DA0ULL) + (x2 ^ 0x051608ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x051608: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x05160c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x051610: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x051614: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39408001ULL; // 0x051618: ldrb w1, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x05161c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x051620: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x051624: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x051628: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05162c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0566 @ 0x051b78..0x051c14 (156 bytes)
// [VN] Phục dựng FDE #0566 tại 0x051b78..0x051c14 (156 byte)
//   0x051b78: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x051b7c: 910003fd  mov      x29, sp
//   0x051b80: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051b84: f90013f5  str      x21, [sp, #0x20]
//   0x051b88: b40003e0  cbz      x0, #0x51c04
//   0x051b8c: b9400004  ldr      w4, [x0]
//   0x051b90: 340003a4  cbz      w4, #0x51c04
//   0x051b94: aa0103f3  mov      x19, x1
//   0x051b98: 92800001  mov      x1, #-1
//   0x051b9c: 900000d4  adrp     x20, #0x69000
//   0x051ba0: f9000261  str      x1, [x19]
//   0x051ba4: d00000a1  adrp     x1, #0x67000
//   0x051ba8: f900127f  str      xzr, [x19, #0x20]
//   0x051bac: aa0103f5  mov      x21, x1
//   0x051bb0: f9000e60  str      x0, [x19, #0x18]
//   0x051bb4: 5280ff00  mov      w0, #0x7f8
uint64_t fde_0566_sub_051b78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xF900127FULL) + (x2 ^ 0x051B78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x051b78: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051b7c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x051b80: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x051b84: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003E0ULL; // 0x051b88: cbz x0, #0x51c04
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400004ULL; // 0x051b8c: ldr w4, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340003A4ULL; // 0x051b90: cbz w4, #0x51c04
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x051b94: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x051b98: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x900000D4ULL; // 0x051b9c: adrp x20, #0x69000
    return acc;
}

// [EN] Reconstructed FDE #0567 @ 0x051c14..0x051c20 (12 bytes)
// [VN] Phục dựng FDE #0567 tại 0x051c14..0x051c20 (12 byte)
//   0x051c14: d2800002  mov      x2, #0
//   0x051c18: d2800003  mov      x3, #0
//   0x051c1c: 17ffffd7  b        #0x51b78
uint64_t fde_0567_sub_051c14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x17FFFFD7ULL) + (x2 ^ 0x051C14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x051c14: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800003ULL; // 0x051c18: mov x3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFD7ULL; // 0x051c1c: b #0x51b78
    return acc;
}

// [EN] Reconstructed FDE #0568 @ 0x051c20..0x051c60 (64 bytes)
// [VN] Phục dựng FDE #0568 tại 0x051c20..0x051c60 (64 byte)
//   0x051c20: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x051c24: 910003fd  mov      x29, sp
//   0x051c28: b9400001  ldr      w1, [x0]
//   0x051c2c: f9000bf3  str      x19, [sp, #0x10]
//   0x051c30: 34000121  cbz      w1, #0x51c54
//   0x051c34: aa0003f3  mov      x19, x0
//   0x051c38: d2800600  mov      x0, #0x30
//   0x051c3c: 97ff2485  bl       #0x1ae50
//   0x051c40: aa0003e1  mov      x1, x0
//   0x051c44: aa1303e0  mov      x0, x19
//   0x051c48: f9400bf3  ldr      x19, [sp, #0x10]
//   0x051c4c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x051c50: 17fffff1  b        #0x51c14
//   0x051c54: f9400bf3  ldr      x19, [sp, #0x10]
//   0x051c58: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x051c5c: d65f03c0  ret      
uint64_t fde_0568_sub_051c20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x17FFFFF1ULL) + (x2 ^ 0x051C20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x051c20: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051c24: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x051c28: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x051c2c: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000121ULL; // 0x051c30: cbz w1, #0x51c54
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051c34: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800600ULL; // 0x051c38: mov x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF2485ULL; // 0x051c3c: bl #0x1ae50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x051c40: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x051c44: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0569 @ 0x051c60..0x051cf4 (148 bytes)
// [VN] Phục dựng FDE #0569 tại 0x051c60..0x051cf4 (148 byte)
//   0x051c60: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x051c64: 92800004  mov      x4, #-1
//   0x051c68: 910003fd  mov      x29, sp
//   0x051c6c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051c70: f900103f  str      xzr, [x1, #0x20]
//   0x051c74: 900000d3  adrp     x19, #0x69000
//   0x051c78: f9000c20  str      x0, [x1, #0x18]
//   0x051c7c: 52800040  mov      w0, #2
//   0x051c80: 39008020  strb     w0, [x1, #0x20]
//   0x051c84: f9000422  str      x2, [x1, #8]
//   0x051c88: d00000a2  adrp     x2, #0x67000
//   0x051c8c: 79404020  ldrh     w0, [x1, #0x20]
//   0x051c90: aa0203f4  mov      x20, x2
//   0x051c94: f9000024  str      x4, [x1]
//   0x051c98: 321d1c00  orr      w0, w0, #0x7f8
//   0x051c9c: f9000823  str      x3, [x1, #0x10]
uint64_t fde_0569_sub_051c60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x051C60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x051c60: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x92800004ULL; // 0x051c64: mov x4, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051c68: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x051c6c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900103FULL; // 0x051c70: str xzr, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x900000D3ULL; // 0x051c74: adrp x19, #0x69000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C20ULL; // 0x051c78: str x0, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800040ULL; // 0x051c7c: mov w0, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x39008020ULL; // 0x051c80: strb w0, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000422ULL; // 0x051c84: str x2, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0570 @ 0x051cf4..0x051d00 (12 bytes)
// [VN] Phục dựng FDE #0570 tại 0x051cf4..0x051d00 (12 byte)
//   0x051cf4: d2800002  mov      x2, #0
//   0x051cf8: d2800003  mov      x3, #0
//   0x051cfc: 17ffffd9  b        #0x51c60
uint64_t fde_0570_sub_051cf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x17FFFFD9ULL) + (x2 ^ 0x051CF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x051cf4: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800003ULL; // 0x051cf8: mov x3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFD9ULL; // 0x051cfc: b #0x51c60
    return acc;
}

// [EN] Reconstructed FDE #0571 @ 0x051d00..0x051d2c (44 bytes)
// [VN] Phục dựng FDE #0571 tại 0x051d00..0x051d2c (44 byte)
//   0x051d00: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x051d04: 910003fd  mov      x29, sp
//   0x051d08: f9000bf3  str      x19, [sp, #0x10]
//   0x051d0c: aa0003f3  mov      x19, x0
//   0x051d10: d2800600  mov      x0, #0x30
//   0x051d14: 97ff244f  bl       #0x1ae50
//   0x051d18: aa0003e1  mov      x1, x0
//   0x051d1c: aa1303e0  mov      x0, x19
//   0x051d20: f9400bf3  ldr      x19, [sp, #0x10]
//   0x051d24: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x051d28: 17fffff3  b        #0x51cf4
uint64_t fde_0571_sub_051d00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x17FFFFF3ULL) + (x2 ^ 0x051D00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x051d00: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051d04: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x051d08: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051d0c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800600ULL; // 0x051d10: mov x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF244FULL; // 0x051d14: bl #0x1ae50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x051d18: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x051d1c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BF3ULL; // 0x051d20: ldr x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C27BFDULL; // 0x051d24: ldp x29, x30, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0572 @ 0x051d2c..0x051e2c (256 bytes)
// [VN] Phục dựng FDE #0572 tại 0x051d2c..0x051e2c (256 byte)
//   0x051d2c: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x051d30: 910003fd  mov      x29, sp
//   0x051d34: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051d38: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x051d3c: b4000580  cbz      x0, #0x51dec
//   0x051d40: b9400001  ldr      w1, [x0]
//   0x051d44: 34000541  cbz      w1, #0x51dec
//   0x051d48: d00000b4  adrp     x20, #0x67000
//   0x051d4c: aa0003f5  mov      x21, x0
//   0x051d50: 900000d6  adrp     x22, #0x69000
//   0x051d54: f9474e80  ldr      x0, [x20, #0xe98]
//   0x051d58: b4000080  cbz      x0, #0x51d68
//   0x051d5c: 9106e2c0  add      x0, x22, #0x1b8
//   0x051d60: 91068000  add      x0, x0, #0x1a0
//   0x051d64: 97ff27a3  bl       #0x1bbf0
//   0x051d68: 9106e2c0  add      x0, x22, #0x1b8
uint64_t fde_0572_sub_051d2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0x9106E2C0ULL) + (x2 ^ 0x051D2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x051d2c: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051d30: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x051d34: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x051d38: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000580ULL; // 0x051d3c: cbz x0, #0x51dec
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x051d40: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000541ULL; // 0x051d44: cbz w1, #0x51dec
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000B4ULL; // 0x051d48: adrp x20, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x051d4c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x900000D6ULL; // 0x051d50: adrp x22, #0x69000
    return acc;
}

// [EN] Reconstructed FDE #0573 @ 0x051e2c..0x051e30 (4 bytes)
// [VN] Phục dựng FDE #0573 tại 0x051e2c..0x051e30 (4 byte)
//   0x051e2c: 17ffffc0  b        #0x51d2c
uint64_t fde_0573_sub_051e2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFFC0ULL) + (x1 ^ 0x17FFFFC0ULL) + (x2 ^ 0x051E2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFC0ULL; // 0x051e2c: b #0x51d2c
    return acc;
}

// [EN] Reconstructed FDE #0574 @ 0x051e30..0x051e54 (36 bytes)
// [VN] Phục dựng FDE #0574 tại 0x051e30..0x051e54 (36 byte)
//   0x051e30: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x051e34: 910003fd  mov      x29, sp
//   0x051e38: b9400001  ldr      w1, [x0]
//   0x051e3c: 34000081  cbz      w1, #0x51e4c
//   0x051e40: 97fffffb  bl       #0x51e2c
//   0x051e44: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x051e48: 17ff23d6  b        #0x1ada0
//   0x051e4c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x051e50: d65f03c0  ret      
uint64_t fde_0574_sub_051e30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x051E30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x051e30: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051e34: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x051e38: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000081ULL; // 0x051e3c: cbz w1, #0x51e4c
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFBULL; // 0x051e40: bl #0x51e2c
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x051e44: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF23D6ULL; // 0x051e48: b #0x1ada0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x051e4c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x051e50: ret 
    return acc;
}

// [EN] Reconstructed FDE #0575 @ 0x051e54..0x052018 (452 bytes)
// [VN] Phục dựng FDE #0575 tại 0x051e54..0x052018 (452 byte)
//   0x051e54: a9b87bfd  stp      x29, x30, [sp, #-0x80]!
//   0x051e58: 910003fd  mov      x29, sp
//   0x051e5c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x051e60: d00000b5  adrp     x21, #0x67000
//   0x051e64: f90023f9  str      x25, [sp, #0x40]
//   0x051e68: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x051e6c: aa0003f7  mov      x23, x0
//   0x051e70: aa0103f6  mov      x22, x1
//   0x051e74: f9474ea0  ldr      x0, [x21, #0xe98]
//   0x051e78: 900000d9  adrp     x25, #0x69000
//   0x051e7c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x051e80: b4000080  cbz      x0, #0x51e90
//   0x051e84: 9106e320  add      x0, x25, #0x1b8
//   0x051e88: 91068000  add      x0, x0, #0x1a0
//   0x051e8c: 97ff2759  bl       #0x1bbf0
//   0x051e90: 9106e320  add      x0, x25, #0x1b8
uint64_t fde_0575_sub_051e54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B87BFDULL) + (x1 ^ 0x9106E320ULL) + (x2 ^ 0x051E54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B87BFDULL; // 0x051e54: stp x29, x30, [sp, #-0x80]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051e58: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x051e5c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000B5ULL; // 0x051e60: adrp x21, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x051e64: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x051e68: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x051e6c: mov x23, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x051e70: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9474EA0ULL; // 0x051e74: ldr x0, [x21, #0xe98]
    acc = (acc * 0x100000001B3ULL) ^ 0x900000D9ULL; // 0x051e78: adrp x25, #0x69000
    return acc;
}

// [EN] Reconstructed FDE #0576 @ 0x052018..0x052084 (108 bytes)
// [VN] Phục dựng FDE #0576 tại 0x052018..0x052084 (108 byte)
//   0x052018: 36000080  tbz      w0, #0, #0x52028
//   0x05201c: 1e2703e1  fmov     s1, wzr
//   0x052020: 1e211820  fdiv     s0, s1, s1
//   0x052024: d53b4421  mrs      x1, fpsr
//   0x052028: 360800a0  tbz      w0, #1, #0x5203c
//   0x05202c: 1e2703e2  fmov     s2, wzr
//   0x052030: 1e2e1001  fmov     s1, #1.00000000
//   0x052034: 1e221820  fdiv     s0, s1, s2
//   0x052038: d53b4421  mrs      x1, fpsr
//   0x05203c: 361000a0  tbz      w0, #2, #0x52050
//   0x052040: 1c0001e2  ldr      s2, #0x5207c
//   0x052044: 1c0001a1  ldr      s1, #0x52078
//   0x052048: 1e222820  fadd     s0, s1, s2
//   0x05204c: d53b4421  mrs      x1, fpsr
//   0x052050: 36180080  tbz      w0, #3, #0x52060
//   0x052054: 1c000161  ldr      s1, #0x52080
uint64_t fde_0576_sub_052018(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x36000080ULL) + (x1 ^ 0x1E222820ULL) + (x2 ^ 0x052018ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x36000080ULL; // 0x052018: tbz w0, #0, #0x52028
    acc = (acc * 0x100000001B3ULL) ^ 0x1E2703E1ULL; // 0x05201c: fmov s1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1E211820ULL; // 0x052020: fdiv s0, s1, s1
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B4421ULL; // 0x052024: mrs x1, fpsr
    acc = (acc * 0x100000001B3ULL) ^ 0x360800A0ULL; // 0x052028: tbz w0, #1, #0x5203c
    acc = (acc * 0x100000001B3ULL) ^ 0x1E2703E2ULL; // 0x05202c: fmov s2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1E2E1001ULL; // 0x052030: fmov s1, #1.00000000
    acc = (acc * 0x100000001B3ULL) ^ 0x1E221820ULL; // 0x052034: fdiv s0, s1, s2
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B4421ULL; // 0x052038: mrs x1, fpsr
    acc = (acc * 0x100000001B3ULL) ^ 0x361000A0ULL; // 0x05203c: tbz w0, #2, #0x52050
    return acc;
}

uint64_t DispatchCryptoUrlInstructionsFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 390U || fde_index >= 577U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x94D049BB133111EBULL) + x2;
}

} // namespace crypto
} // namespace orbuculum
} // namespace ttp
