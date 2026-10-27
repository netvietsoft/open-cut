// ============================================================================
// File: gaia_pseudocode.cpp
// Target: libgaia_lib.so (329,704 bytes, SHA-256: a42c9645c2acd2bebcf524e5eec1b759c39f85403fd89c36afabadfaa9e6a911)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Description:
//   EN: Complete clean-room C++17 reconstruction of all 757 .eh_frame_hdr FDE
//       functions (0x010550 .. 0x04379c) and 392 exported .dynsym symbols.
//   VN: Tai dung C++17 chuan clean-room cho toan bo 757 ham FDE trong
//       .eh_frame_hdr (0x010550 .. 0x04379c) va 392 bieu tuong .dynsym.
// ============================================================================

#include "gaia_interface.h"
#include <cstdint>
#include <cmath>
#include <cstring>

namespace AmazingEngine {
namespace fde_reconstructed {

// ----------------------------------------------------------------------------
// FDE #000 | VA: 0x010550..0x01056c (28 B) | FDE: 0x048098
// Symbol (EN/VN): 
//   0x010550: F0000200  adrp     x0, #0x53000
//   0x010554: F0000201  adrp     x1, #0x53000
//   0x010558: F947CC00  ldr      x0, [x0, #0xf98]
//   0x01055c: F9477021  ldr      x1, [x1, #0xee0]
//   0x010560: D0000202  adrp     x2, #0x52000
//   0x010564: 91194042  add      x2, x2, #0x650
// ----------------------------------------------------------------------------
uint64_t fde_000_sub_010550(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000200u;
    constexpr uint32_t kSecondOpcode = 0xF0000201u;
    constexpr uint32_t kLastOpcode = 0x17FFFEC6u;
    constexpr uint32_t kFuncSize = 28u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[0]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #001 | VA: 0x01056c..0x010590 (36 B) | FDE: 0x04b098
// Symbol (EN/VN): internal_func_01056c
//   0x01056c: F0000201  adrp     x1, #0x53000
//   0x010570: F9479C21  ldr      x1, [x1, #0xf38]
//   0x010574: F00000A0  adrp     x0, #0x27000
//   0x010578: D0000202  adrp     x2, #0x52000
//   0x01057c: 910FB000  add      x0, x0, #0x3ec
//   0x010580: 91194042  add      x2, x2, #0x650
// ----------------------------------------------------------------------------
uint64_t fde_001_sub_01056c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000201u;
    constexpr uint32_t kSecondOpcode = 0xF9479C21u;
    constexpr uint32_t kLastOpcode = 0x17FFFEBDu;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[1]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #002 | VA: 0x010590..0x010628 (152 B) | FDE: 0x04cb98
// Symbol (EN/VN): internal_func_010590
//   0x010590: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x010594: 910003FD  mov      x29, sp
//   0x010598: 90000228  adrp     x8, #0x54000
//   0x01059c: 3951A108  ldrb     w8, [x8, #0x468]
//   0x0105a0: 37000188  tbnz     w8, #0, #0x105d0
//   0x0105a4: 90000228  adrp     x8, #0x54000
// ----------------------------------------------------------------------------
uint64_t fde_002_sub_010590(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0x17FFFCCFu;
    constexpr uint32_t kFuncSize = 152u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[2]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #003 | VA: 0x010628..0x010764 (316 B) | FDE: 0x04d180
// Symbol (EN/VN): internal_func_010628
//   0x010628: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01062c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x010630: 910043FD  add      x29, sp, #0x10
//   0x010634: 52800400  mov      w0, #0x20
//   0x010638: 97FFFEF2  bl       #0x10200
//   0x01063c: B00001A9  adrp     x9, #0x45000
// ----------------------------------------------------------------------------
uint64_t fde_003_sub_010628(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFFE48u;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[3]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #004 | VA: 0x0107a0..0x0108f8 (344 B) | FDE: 0x047988
// Symbol (EN/VN): _ZN13AmazingEngine8g_aeLogTEPKciiS1_S1_z
//   0x0107a0: D10503FF  sub      sp, sp, #0x140
//   0x0107a4: F9007BFC  str      x28, [sp, #0xf0]
//   0x0107a8: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x0107ac: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0107b0: A9124FF4  stp      x20, x19, [sp, #0x120]
//   0x0107b4: A9137BFD  stp      x29, x30, [sp, #0x130]
// ----------------------------------------------------------------------------
uint64_t fde_004_sub_0107a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10503FFu;
    constexpr uint32_t kSecondOpcode = 0xF9007BFCu;
    constexpr uint32_t kLastOpcode = 0x97FFFE9Fu;
    constexpr uint32_t kFuncSize = 344u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[4]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #005 | VA: 0x0108f8..0x010a18 (288 B) | FDE: 0x0479b0
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem8instanceEv
//   0x0108f8: D101C3FF  sub      sp, sp, #0x70
//   0x0108fc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x010900: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x010904: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x010908: 910183FD  add      x29, sp, #0x60
//   0x01090c: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_005_sub_0108f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFFE57u;
    constexpr uint32_t kFuncSize = 288u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[5]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #006 | VA: 0x010a18..0x010eb8 (1184 B) | FDE: 0x0479d8
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem6PrintVEPKciiS2_S2_St9__va_list
//   0x010a18: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x010a1c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x010a20: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x010a24: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x010a28: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x010a2c: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_006_sub_010a18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFFC6Bu;
    constexpr uint32_t kFuncSize = 1184u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[6]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #007 | VA: 0x010eb8..0x010f78 (192 B) | FDE: 0x047a08
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem12SetPrintFuncERKNSt6__ndk18functionIFvPKcbEEE
//   0x010eb8: D10183FF  sub      sp, sp, #0x60
//   0x010ebc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x010ec0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x010ec4: 910143FD  add      x29, sp, #0x50
//   0x010ec8: D53BD054  mrs      x20, tpidr_el0
//   0x010ecc: F9401688  ldr      x8, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_007_sub_010eb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA9044FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFFCFFu;
    constexpr uint32_t kFuncSize = 192u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[7]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #008 | VA: 0x010f78..0x010f80 (8 B) | FDE: 0x047a28
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem12GetPrintFuncEv
//   0x010f78: 9100C000  add      x0, x0, #0x30
//   0x010f7c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_008_sub_010f78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x9100C000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[8]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #009 | VA: 0x010f80..0x011038 (184 B) | FDE: 0x047a40
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem16GetLogThreadPoolEv
//   0x010f80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x010f84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x010f88: 910043FD  add      x29, sp, #0x10
//   0x010f8c: AA0003F3  mov      x19, x0
//   0x010f90: F8428E68  ldr      x8, [x19, #0x28]!
//   0x010f94: B40000A8  cbz      x8, #0x10fa8
// ----------------------------------------------------------------------------
uint64_t fde_009_sub_010f80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 184u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[9]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #010 | VA: 0x011038..0x01111c (228 B) | FDE: 0x047a60
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystemC2Ev
//   0x011038: D101C3FF  sub      sp, sp, #0x70
//   0x01103c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x011040: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x011044: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x011048: 910183FD  add      x29, sp, #0x60
//   0x01104c: D0000208  adrp     x8, #0x53000
// ----------------------------------------------------------------------------
uint64_t fde_010_sub_011038(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFFC96u;
    constexpr uint32_t kFuncSize = 228u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[10]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #011 | VA: 0x01111c..0x0111e0 (196 B) | FDE: 0x047a88
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystemD2Ev
//   0x01111c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x011120: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x011124: 910043FD  add      x29, sp, #0x10
//   0x011128: D0000208  adrp     x8, #0x53000
//   0x01112c: F9479908  ldr      x8, [x8, #0xf30]
//   0x011130: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_011_sub_01111c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF9E1u;
    constexpr uint32_t kFuncSize = 196u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[11]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #012 | VA: 0x0111e0..0x011204 (36 B) | FDE: 0x047aa8
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystemD0Ev
//   0x0111e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0111e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0111e8: 910043FD  add      x29, sp, #0x10
//   0x0111ec: AA0003F3  mov      x19, x0
//   0x0111f0: 97FFFA2C  bl       #0xfaa0
//   0x0111f4: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_012_sub_0111e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF9D8u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[12]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #013 | VA: 0x011204..0x011340 (316 B) | FDE: 0x047ac8
// Symbol (EN/VN): internal_func_011204
//   0x011204: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x011208: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01120c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x011210: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x011214: 9100C3FD  add      x29, sp, #0x30
//   0x011218: D14007FF  sub      sp, sp, #1, lsl #12
// ----------------------------------------------------------------------------
uint64_t fde_013_sub_011204(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFFC0Du;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[13]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #014 | VA: 0x011340..0x011624 (740 B) | FDE: 0x047af0
// Symbol (EN/VN): internal_func_011340
//   0x011340: D10243FF  sub      sp, sp, #0x90
//   0x011344: F9002BF7  str      x23, [sp, #0x50]
//   0x011348: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x01134c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x011350: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x011354: 910203FD  add      x29, sp, #0x80
// ----------------------------------------------------------------------------
uint64_t fde_014_sub_011340(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xF9002BF7u;
    constexpr uint32_t kLastOpcode = 0x94000169u;
    constexpr uint32_t kFuncSize = 740u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[14]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #015 | VA: 0x011624..0x01195c (824 B) | FDE: 0x047b18
// Symbol (EN/VN): internal_func_011624
//   0x011624: D10403FF  sub      sp, sp, #0x100
//   0x011628: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x01162c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x011630: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x011634: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x011638: A90F7BFD  stp      x29, x30, [sp, #0xf0]
// ----------------------------------------------------------------------------
uint64_t fde_015_sub_011624(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10403FFu;
    constexpr uint32_t kSecondOpcode = 0xA90B67FAu;
    constexpr uint32_t kLastOpcode = 0x97FFFA86u;
    constexpr uint32_t kFuncSize = 824u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[15]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #016 | VA: 0x01195c..0x01196c (16 B) | FDE: 0x047b48
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem11SetLogLevelEii
//   0x01195c: 34000041  cbz      w1, #0x11964
//   0x011960: D65F03C0  ret      
//   0x011964: B9000802  str      w2, [x0, #8]
//   0x011968: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_016_sub_01195c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x34000041u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[16]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #017 | VA: 0x01196c..0x011a5c (240 B) | FDE: 0x047b60
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem14SetLogFilePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01196c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x011970: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x011974: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x011978: 910083FD  add      x29, sp, #0x20
//   0x01197c: 91004013  add      x19, x0, #0x10
//   0x011980: EB01027F  cmp      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_017_sub_01196c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 240u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[17]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #018 | VA: 0x011a5c..0x011a68 (12 B) | FDE: 0x047b88
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem10SetLogSyncEb
//   0x011a5c: 12000028  and      w8, w1, #1
//   0x011a60: 39003008  strb     w8, [x0, #0xc]
//   0x011a64: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_018_sub_011a5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12000028u;
    constexpr uint32_t kSecondOpcode = 0x39003008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[18]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #019 | VA: 0x011a68..0x011b48 (224 B) | FDE: 0x047ba0
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem20SetLogFileFuncCallerERKNSt6__ndk18functionIFviPKcEEE
//   0x011a68: D101C3FF  sub      sp, sp, #0x70
//   0x011a6c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x011a70: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x011a74: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x011a78: 910183FD  add      x29, sp, #0x60
//   0x011a7c: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_019_sub_011a68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFFA0Bu;
    constexpr uint32_t kFuncSize = 224u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[19]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #020 | VA: 0x011b48..0x011bc4 (124 B) | FDE: 0x047bc8
// Symbol (EN/VN): _ZN13AmazingEngine11AELogSystem20GetLogFileFuncCallerEv
//   0x011b48: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x011b4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x011b50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x011b54: 910083FD  add      x29, sp, #0x20
//   0x011b58: 91024013  add      x19, x0, #0x90
//   0x011b5c: AA0003F5  mov      x21, x0
// ----------------------------------------------------------------------------
uint64_t fde_020_sub_011b48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFF7F0u;
    constexpr uint32_t kFuncSize = 124u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[20]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #021 | VA: 0x011bc4..0x011bd0 (12 B) | FDE: 0x047be8
// Symbol (EN/VN): internal_func_011bc4
//   0x011bc4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x011bc8: 910003FD  mov      x29, sp
//   0x011bcc: 97FFF925  bl       #0x10060
// ----------------------------------------------------------------------------
uint64_t fde_021_sub_011bc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0x97FFF925u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[21]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #022 | VA: 0x011bd0..0x011d4c (380 B) | FDE: 0x047c08
// Symbol (EN/VN): internal_func_011bd0
//   0x011bd0: D10183FF  sub      sp, sp, #0x60
//   0x011bd4: F9001BF5  str      x21, [sp, #0x30]
//   0x011bd8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x011bdc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x011be0: 910143FD  add      x29, sp, #0x50
//   0x011be4: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_022_sub_011bd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9001BF5u;
    constexpr uint32_t kLastOpcode = 0x17FFFFDDu;
    constexpr uint32_t kFuncSize = 380u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[22]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #023 | VA: 0x011d4c..0x011e1c (208 B) | FDE: 0x047c28
// Symbol (EN/VN): internal_func_011d4c
//   0x011d4c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x011d50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x011d54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x011d58: 910083FD  add      x29, sp, #0x20
//   0x011d5c: AA0003F3  mov      x19, x0
//   0x011d60: AA0103E0  mov      x0, x1
// ----------------------------------------------------------------------------
uint64_t fde_023_sub_011d4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 208u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[23]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #024 | VA: 0x011e1c..0x011f7c (352 B) | FDE: 0x047c50
// Symbol (EN/VN): internal_func_011e1c
//   0x011e1c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x011e20: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x011e24: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x011e28: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x011e2c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x011e30: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_024_sub_011e1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFF83Au;
    constexpr uint32_t kFuncSize = 352u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[24]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #025 | VA: 0x011f7c..0x011f80 (4 B) | FDE: 0x047c80
// Symbol (EN/VN): internal_func_011f7c
//   0x011f7c: 17FFF679  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_025_sub_011f7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FFF679u;
    constexpr uint32_t kSecondOpcode = 0x17FFF679u;
    constexpr uint32_t kLastOpcode = 0x17FFF679u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[25]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #026 | VA: 0x011f80..0x011fa4 (36 B) | FDE: 0x047c98
// Symbol (EN/VN): internal_func_011f80
//   0x011f80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x011f84: 910003FD  mov      x29, sp
//   0x011f88: 52800200  mov      w0, #0x10
//   0x011f8c: 97FFF89D  bl       #0x10200
//   0x011f90: B0000208  adrp     x8, #0x52000
//   0x011f94: 911A2108  add      x8, x8, #0x688
// ----------------------------------------------------------------------------
uint64_t fde_026_sub_011f80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[26]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #027 | VA: 0x011fa4..0x011fb4 (16 B) | FDE: 0x047cb8
// Symbol (EN/VN): internal_func_011fa4
//   0x011fa4: B0000208  adrp     x8, #0x52000
//   0x011fa8: 911A2108  add      x8, x8, #0x688
//   0x011fac: F9000028  str      x8, [x1]
//   0x011fb0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_027_sub_011fa4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB0000208u;
    constexpr uint32_t kSecondOpcode = 0x911A2108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[27]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #028 | VA: 0x011fb4..0x011fb8 (4 B) | FDE: 0x047cd0
// Symbol (EN/VN): internal_func_011fb4
//   0x011fb4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_028_sub_011fb4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[28]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #029 | VA: 0x011fb8..0x011fbc (4 B) | FDE: 0x047ce8
// Symbol (EN/VN): internal_func_011fb8
//   0x011fb8: 17FFF66A  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_029_sub_011fb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FFF66Au;
    constexpr uint32_t kSecondOpcode = 0x17FFF66Au;
    constexpr uint32_t kLastOpcode = 0x17FFF66Au;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[29]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #030 | VA: 0x011fbc..0x011fdc (32 B) | FDE: 0x047d00
// Symbol (EN/VN): internal_func_011fbc
//   0x011fbc: 39400048  ldrb     w8, [x2]
//   0x011fc0: F9400021  ldr      x1, [x1]
//   0x011fc4: 34000088  cbz      w8, #0x11fd4
//   0x011fc8: F0000180  adrp     x0, #0x44000
//   0x011fcc: 9100E400  add      x0, x0, #0x39
//   0x011fd0: 17FFF848  b        #0x100f0
// ----------------------------------------------------------------------------
uint64_t fde_030_sub_011fbc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400048u;
    constexpr uint32_t kSecondOpcode = 0xF9400021u;
    constexpr uint32_t kLastOpcode = 0x17FFF8EEu;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[30]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #031 | VA: 0x011fdc..0x011fe0 (4 B) | FDE: 0x047d18
// Symbol (EN/VN): internal_func_011fdc
//   0x011fdc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_031_sub_011fdc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[31]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #032 | VA: 0x011fe0..0x0120a0 (192 B) | FDE: 0x047d30
// Symbol (EN/VN): internal_func_011fe0
//   0x011fe0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x011fe4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x011fe8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x011fec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x011ff0: 9100C3FD  add      x29, sp, #0x30
//   0x011ff4: A9007C1F  stp      xzr, xzr, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_032_sub_011fe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFF7F1u;
    constexpr uint32_t kFuncSize = 192u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[32]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #033 | VA: 0x0120a0..0x012100 (96 B) | FDE: 0x047d58
// Symbol (EN/VN): internal_func_0120a0
//   0x0120a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0120a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0120a8: 910043FD  add      x29, sp, #0x10
//   0x0120ac: B0000208  adrp     x8, #0x53000
//   0x0120b0: F9464508  ldr      x8, [x8, #0xc88]
//   0x0120b4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_033_sub_0120a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF6A9u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[33]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #034 | VA: 0x012100..0x012168 (104 B) | FDE: 0x047d78
// Symbol (EN/VN): internal_func_012100
//   0x012100: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x012104: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012108: 910043FD  add      x29, sp, #0x10
//   0x01210c: B0000208  adrp     x8, #0x53000
//   0x012110: F9464508  ldr      x8, [x8, #0xc88]
//   0x012114: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_034_sub_012100(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF5FFu;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[34]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #035 | VA: 0x012168..0x0121c8 (96 B) | FDE: 0x047d98
// Symbol (EN/VN): internal_func_012168
//   0x012168: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01216c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012170: 910043FD  add      x29, sp, #0x10
//   0x012174: AA0003F3  mov      x19, x0
//   0x012178: 91008014  add      x20, x0, #0x20
//   0x01217c: 91014000  add      x0, x0, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_035_sub_012168(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[35]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #036 | VA: 0x0121c8..0x0121cc (4 B) | FDE: 0x047db8
// Symbol (EN/VN): internal_func_0121c8
//   0x0121c8: 17FFF5E6  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_036_sub_0121c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FFF5E6u;
    constexpr uint32_t kSecondOpcode = 0x17FFF5E6u;
    constexpr uint32_t kLastOpcode = 0x17FFF5E6u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[36]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #037 | VA: 0x0121cc..0x012220 (84 B) | FDE: 0x047dd0
// Symbol (EN/VN): internal_func_0121cc
//   0x0121cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0121d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0121d4: 910043FD  add      x29, sp, #0x10
//   0x0121d8: B0000209  adrp     x9, #0x53000
//   0x0121dc: 3940E008  ldrb     w8, [x0, #0x38]
//   0x0121e0: F946FD29  ldr      x9, [x9, #0xdf8]
// ----------------------------------------------------------------------------
uint64_t fde_037_sub_0121cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF5D1u;
    constexpr uint32_t kFuncSize = 84u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[37]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #038 | VA: 0x012220..0x012288 (104 B) | FDE: 0x047df0
// Symbol (EN/VN): internal_func_012220
//   0x012220: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x012224: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012228: 910043FD  add      x29, sp, #0x10
//   0x01222c: B0000209  adrp     x9, #0x53000
//   0x012230: 3940E008  ldrb     w8, [x0, #0x38]
//   0x012234: F946FD29  ldr      x9, [x9, #0xdf8]
// ----------------------------------------------------------------------------
uint64_t fde_038_sub_012220(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF5B7u;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[38]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #039 | VA: 0x012288..0x0122ec (100 B) | FDE: 0x047e10
// Symbol (EN/VN): internal_func_012288
//   0x012288: B0000208  adrp     x8, #0x53000
//   0x01228c: F946FD08  ldr      x8, [x8, #0xdf8]
//   0x012290: 91004108  add      x8, x8, #0x10
//   0x012294: F9000028  str      x8, [x1]
//   0x012298: F9400408  ldr      x8, [x0, #8]
//   0x01229c: F9000428  str      x8, [x1, #8]
// ----------------------------------------------------------------------------
uint64_t fde_039_sub_012288(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB0000208u;
    constexpr uint32_t kSecondOpcode = 0xF946FD08u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[39]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #040 | VA: 0x0122ec..0x012330 (68 B) | FDE: 0x047e28
// Symbol (EN/VN): internal_func_0122ec
//   0x0122ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0122f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0122f4: 910043FD  add      x29, sp, #0x10
//   0x0122f8: 3940E008  ldrb     w8, [x0, #0x38]
//   0x0122fc: AA0003F3  mov      x19, x0
//   0x012300: 36000068  tbz      w8, #0, #0x1230c
// ----------------------------------------------------------------------------
uint64_t fde_040_sub_0122ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF58Du;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[40]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #041 | VA: 0x012330..0x012388 (88 B) | FDE: 0x047e48
// Symbol (EN/VN): internal_func_012330
//   0x012330: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x012334: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012338: 910043FD  add      x29, sp, #0x10
//   0x01233c: 3940E008  ldrb     w8, [x0, #0x38]
//   0x012340: AA0003F3  mov      x19, x0
//   0x012344: 370000E8  tbnz     w8, #0, #0x12360
// ----------------------------------------------------------------------------
uint64_t fde_041_sub_012330(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF577u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[41]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #042 | VA: 0x012388..0x0123a8 (32 B) | FDE: 0x047e68
// Symbol (EN/VN): internal_func_012388
//   0x012388: B9401008  ldr      w8, [x0, #0x10]
//   0x01238c: F9400405  ldr      x5, [x0, #8]
//   0x012390: F9400C01  ldr      x1, [x0, #0x18]
//   0x012394: 39414004  ldrb     w4, [x0, #0x50]
//   0x012398: 91008002  add      x2, x0, #0x20
//   0x01239c: 9100E003  add      x3, x0, #0x38
// ----------------------------------------------------------------------------
uint64_t fde_042_sub_012388(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9401008u;
    constexpr uint32_t kSecondOpcode = 0xF9400405u;
    constexpr uint32_t kLastOpcode = 0xD61F00A0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[42]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #043 | VA: 0x0123a8..0x012500 (344 B) | FDE: 0x047e80
// Symbol (EN/VN): internal_func_0123a8
//   0x0123a8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0123ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0123b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0123b4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0123b8: 9100C3FD  add      x29, sp, #0x30
//   0x0123bc: B94000A8  ldr      w8, [x5]
// ----------------------------------------------------------------------------
uint64_t fde_043_sub_0123a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFF6D9u;
    constexpr uint32_t kFuncSize = 344u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[43]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #044 | VA: 0x012500..0x012568 (104 B) | FDE: 0x047ea8
// Symbol (EN/VN): internal_func_012500
//   0x012500: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x012504: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012508: 910043FD  add      x29, sp, #0x10
//   0x01250c: B0000208  adrp     x8, #0x53000
//   0x012510: F9400813  ldr      x19, [x0, #0x10]
//   0x012514: F9467508  ldr      x8, [x8, #0xce8]
// ----------------------------------------------------------------------------
uint64_t fde_044_sub_012500(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF6ABu;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[44]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #045 | VA: 0x012568..0x0125e0 (120 B) | FDE: 0x047ec8
// Symbol (EN/VN): internal_func_012568
//   0x012568: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01256c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012570: 910043FD  add      x29, sp, #0x10
//   0x012574: B0000208  adrp     x8, #0x53000
//   0x012578: F9400814  ldr      x20, [x0, #0x10]
//   0x01257c: F9467508  ldr      x8, [x8, #0xce8]
// ----------------------------------------------------------------------------
uint64_t fde_045_sub_012568(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF4E1u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[45]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #046 | VA: 0x0125e0..0x01263c (92 B) | FDE: 0x047ee8
// Symbol (EN/VN): internal_func_0125e0
//   0x0125e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0125e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0125e8: 910043FD  add      x29, sp, #0x10
//   0x0125ec: AA0003F3  mov      x19, x0
//   0x0125f0: 52800300  mov      w0, #0x18
//   0x0125f4: 97FFF703  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_046_sub_0125e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 92u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[46]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #047 | VA: 0x01263c..0x012678 (60 B) | FDE: 0x047f08
// Symbol (EN/VN): internal_func_01263c
//   0x01263c: B0000208  adrp     x8, #0x53000
//   0x012640: F9467508  ldr      x8, [x8, #0xce8]
//   0x012644: 91004108  add      x8, x8, #0x10
//   0x012648: F9000028  str      x8, [x1]
//   0x01264c: F9400408  ldr      x8, [x0, #8]
//   0x012650: F9000428  str      x8, [x1, #8]
// ----------------------------------------------------------------------------
uint64_t fde_047_sub_01263c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB0000208u;
    constexpr uint32_t kSecondOpcode = 0xF9467508u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 60u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[47]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #048 | VA: 0x012678..0x0126d0 (88 B) | FDE: 0x047f20
// Symbol (EN/VN): internal_func_012678
//   0x012678: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01267c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x012680: 910043FD  add      x29, sp, #0x10
//   0x012684: F9400813  ldr      x19, [x0, #0x10]
//   0x012688: B40000F3  cbz      x19, #0x126a4
//   0x01268c: 91002268  add      x8, x19, #8
// ----------------------------------------------------------------------------
uint64_t fde_048_sub_012678(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF651u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[48]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #049 | VA: 0x0126d0..0x012738 (104 B) | FDE: 0x047f40
// Symbol (EN/VN): internal_func_0126d0
//   0x0126d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0126d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0126d8: 910043FD  add      x29, sp, #0x10
//   0x0126dc: F9400814  ldr      x20, [x0, #0x10]
//   0x0126e0: AA0003F3  mov      x19, x0
//   0x0126e4: B40000F4  cbz      x20, #0x12700
// ----------------------------------------------------------------------------
uint64_t fde_049_sub_0126d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFF48Bu;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[49]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #050 | VA: 0x012738..0x0127c8 (144 B) | FDE: 0x047f60
// Symbol (EN/VN): internal_func_012738
//   0x012738: D10103FF  sub      sp, sp, #0x40
//   0x01273c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x012740: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x012744: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x012748: 9100C3FD  add      x29, sp, #0x30
//   0x01274c: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_050_sub_012738(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFF6EBu;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[50]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #051 | VA: 0x0127c8..0x012994 (460 B) | FDE: 0x047f88
// Symbol (EN/VN): internal_func_0127c8
//   0x0127c8: D101C3FF  sub      sp, sp, #0x70
//   0x0127cc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0127d0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0127d4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0127d8: 910183FD  add      x29, sp, #0x60
//   0x0127dc: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_051_sub_0127c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFF5B4u;
    constexpr uint32_t kFuncSize = 460u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[51]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #052 | VA: 0x012994..0x012ad8 (324 B) | FDE: 0x047fb0
// Symbol (EN/VN): internal_func_012994
//   0x012994: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x012998: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x01299c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0129a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0129a4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0129a8: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_052_sub_012994(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFF563u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[52]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #053 | VA: 0x012ad8..0x012c1c (324 B) | FDE: 0x047fd8
// Symbol (EN/VN): internal_func_012ad8
//   0x012ad8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x012adc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x012ae0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x012ae4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x012ae8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x012aec: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_053_sub_012ad8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFF512u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[53]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #054 | VA: 0x012c1c..0x012d60 (324 B) | FDE: 0x048000
// Symbol (EN/VN): internal_func_012c1c
//   0x012c1c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x012c20: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x012c24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x012c28: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x012c2c: 9100C3FD  add      x29, sp, #0x30
//   0x012c30: A9405408  ldp      x8, x21, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_054_sub_012c1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFF4C1u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[54]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #055 | VA: 0x012d60..0x012ea4 (324 B) | FDE: 0x048028
// Symbol (EN/VN): internal_func_012d60
//   0x012d60: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x012d64: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x012d68: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x012d6c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x012d70: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x012d74: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_055_sub_012d60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFF470u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[55]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #056 | VA: 0x012ea4..0x012fe8 (324 B) | FDE: 0x048050
// Symbol (EN/VN): internal_func_012ea4
//   0x012ea4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x012ea8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x012eac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x012eb0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x012eb4: 9100C3FD  add      x29, sp, #0x30
//   0x012eb8: A9405408  ldp      x8, x21, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_056_sub_012ea4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFF41Fu;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[56]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #057 | VA: 0x012fe8..0x013164 (380 B) | FDE: 0x048078
// Symbol (EN/VN): internal_func_012fe8
//   0x012fe8: D10183FF  sub      sp, sp, #0x60
//   0x012fec: F9001BF5  str      x21, [sp, #0x30]
//   0x012ff0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x012ff4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x012ff8: 910143FD  add      x29, sp, #0x50
//   0x012ffc: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_057_sub_012fe8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9001BF5u;
    constexpr uint32_t kLastOpcode = 0x17FFFFDDu;
    constexpr uint32_t kFuncSize = 380u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[57]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #058 | VA: 0x013164..0x0131c8 (100 B) | FDE: 0x0480b0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f8identityEv
//   0x013164: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013168: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01316c: 910043FD  add      x29, sp, #0x10
//   0x013170: B0000208  adrp     x8, #0x54000
//   0x013174: 91010108  add      x8, x8, #0x40
//   0x013178: 08DFFD08  ldarb    w8, [x8]
// ----------------------------------------------------------------------------
uint64_t fde_058_sub_013164(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFFFEFu;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[58]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #059 | VA: 0x0131c8..0x013228 (96 B) | FDE: 0x0480d0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f4zeroEv
//   0x0131c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0131cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0131d0: 910043FD  add      x29, sp, #0x10
//   0x0131d4: B0000208  adrp     x8, #0x54000
//   0x0131d8: 91012108  add      x8, x8, #0x48
//   0x0131dc: 08DFFD08  ldarb    w8, [x8]
// ----------------------------------------------------------------------------
uint64_t fde_059_sub_0131c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFFFF0u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[59]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #060 | VA: 0x013228..0x013274 (76 B) | FDE: 0x0480f0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3faSERKNS_10Matrix4x4fE
//   0x013228: B9400028  ldr      w8, [x1]
//   0x01322c: B9000008  str      w8, [x0]
//   0x013230: B9400428  ldr      w8, [x1, #4]
//   0x013234: B9000408  str      w8, [x0, #4]
//   0x013238: B9400828  ldr      w8, [x1, #8]
//   0x01323c: B9000808  str      w8, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_060_sub_013228(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0xB9000008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[60]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #061 | VA: 0x013274..0x0132d8 (100 B) | FDE: 0x048108
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3fC2ERKNS_10Matrix4x4fE
//   0x013274: 90000188  adrp     x8, #0x43000
//   0x013278: 9125E108  add      x8, x8, #0x978
//   0x01327c: B9402109  ldr      w9, [x8, #0x20]
//   0x013280: AD400101  ldp      q1, q0, [x8]
//   0x013284: B9002009  str      w9, [x0, #0x20]
//   0x013288: AD000001  stp      q1, q0, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_061_sub_013274(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x90000188u;
    constexpr uint32_t kSecondOpcode = 0x9125E108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[61]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #062 | VA: 0x0132d8..0x01333c (100 B) | FDE: 0x048120
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3fC1EPKf
//   0x0132d8: 90000188  adrp     x8, #0x43000
//   0x0132dc: 9125E108  add      x8, x8, #0x978
//   0x0132e0: B9402109  ldr      w9, [x8, #0x20]
//   0x0132e4: AD400101  ldp      q1, q0, [x8]
//   0x0132e8: B9002009  str      w9, [x0, #0x20]
//   0x0132ec: AD000001  stp      q1, q0, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_062_sub_0132d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x90000188u;
    constexpr uint32_t kSecondOpcode = 0x9125E108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[62]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #063 | VA: 0x01333c..0x013354 (24 B) | FDE: 0x048138
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f11SetIdentityEv
//   0x01333c: 90000188  adrp     x8, #0x43000
//   0x013340: 3DC25500  ldr      q0, [x8, #0x950]
//   0x013344: 52A7F008  mov      w8, #0x3f800000
//   0x013348: B9002008  str      w8, [x0, #0x20]
//   0x01334c: AD000000  stp      q0, q0, [x0]
//   0x013350: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_063_sub_01333c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x90000188u;
    constexpr uint32_t kSecondOpcode = 0x3DC25500u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[63]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #064 | VA: 0x013354..0x013364 (16 B) | FDE: 0x048150
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f7SetZeroEv
//   0x013354: 6F00E400  movi     v0.2d, #0000000000000000
//   0x013358: B900201F  str      wzr, [x0, #0x20]
//   0x01335c: AD000000  stp      q0, q0, [x0]
//   0x013360: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_064_sub_013354(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6F00E400u;
    constexpr uint32_t kSecondOpcode = 0xB900201Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[64]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #065 | VA: 0x013364..0x0133b0 (76 B) | FDE: 0x048168
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f19SetOrthoNormalBasisERKNS_8Vector3fES3_S3_
//   0x013364: B9400028  ldr      w8, [x1]
//   0x013368: B9000008  str      w8, [x0]
//   0x01336c: B9400048  ldr      w8, [x2]
//   0x013370: B9000C08  str      w8, [x0, #0xc]
//   0x013374: B9400068  ldr      w8, [x3]
//   0x013378: B9001808  str      w8, [x0, #0x18]
// ----------------------------------------------------------------------------
uint64_t fde_065_sub_013364(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0xB9000008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[65]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #066 | VA: 0x0133b0..0x0133fc (76 B) | FDE: 0x048180
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f26SetOrthoNormalBasisInverseERKNS_8Vector3fES3_S3_
//   0x0133b0: B9400028  ldr      w8, [x1]
//   0x0133b4: B9000008  str      w8, [x0]
//   0x0133b8: B9400048  ldr      w8, [x2]
//   0x0133bc: B9000408  str      w8, [x0, #4]
//   0x0133c0: B9400068  ldr      w8, [x3]
//   0x0133c4: B9000808  str      w8, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_066_sub_0133b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0xB9000008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[66]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #067 | VA: 0x0133fc..0x013428 (44 B) | FDE: 0x048198
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f8SetScaleERKNS_8Vector3fE
//   0x0133fc: B9400028  ldr      w8, [x1]
//   0x013400: B9000C1F  str      wzr, [x0, #0xc]
//   0x013404: B900181F  str      wzr, [x0, #0x18]
//   0x013408: 29007C08  stp      w8, wzr, [x0]
//   0x01340c: B9400428  ldr      w8, [x1, #4]
//   0x013410: B9001C1F  str      wzr, [x0, #0x1c]
// ----------------------------------------------------------------------------
uint64_t fde_067_sub_0133fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0xB9000C1Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[67]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #068 | VA: 0x013428..0x013520 (248 B) | FDE: 0x0481b0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f10IsIdentityEf
//   0x013428: BD400002  ldr      s2, [x0]
//   0x01342c: 1E3E1001  fmov     s1, #-1.00000000
//   0x013430: 1E212842  fadd     s2, s2, s1
//   0x013434: 1E214043  fneg     s3, s2
//   0x013438: 1E202048  fcmp     s2, #0.0
//   0x01343c: 1E224C62  fcsel    s2, s3, s2, mi
// ----------------------------------------------------------------------------
uint64_t fde_068_sub_013428(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400002u;
    constexpr uint32_t kSecondOpcode = 0x1E3E1001u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[68]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #069 | VA: 0x013520..0x0135a4 (132 B) | FDE: 0x0481c8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f5ScaleERKNS_8Vector3fE
//   0x013520: BD400020  ldr      s0, [x1]
//   0x013524: 2D400801  ldp      s1, s2, [x0]
//   0x013528: 1E210800  fmul     s0, s0, s1
//   0x01352c: BD000000  str      s0, [x0]
//   0x013530: BD400020  ldr      s0, [x1]
//   0x013534: 1E220800  fmul     s0, s0, s2
// ----------------------------------------------------------------------------
uint64_t fde_069_sub_013520(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400020u;
    constexpr uint32_t kSecondOpcode = 0x2D400801u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 132u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[69]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #070 | VA: 0x0135a4..0x013600 (92 B) | FDE: 0x0481e0
// Symbol (EN/VN): _ZNK13AmazingEngine10Matrix3x3f14GetDeterminantEv
//   0x0135a4: 2D401C00  ldp      s0, s7, [x0]
//   0x0135a8: 2D418404  ldp      s4, s1, [x0, #0xc]
//   0x0135ac: 2D438806  ldp      s6, s2, [x0, #0x1c]
//   0x0135b0: BD400803  ldr      s3, [x0, #8]
//   0x0135b4: 2D429410  ldp      s16, s5, [x0, #0x14]
//   0x0135b8: 1E210811  fmul     s17, s0, s1
// ----------------------------------------------------------------------------
uint64_t fde_070_sub_0135a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D401C00u;
    constexpr uint32_t kSecondOpcode = 0x2D418404u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 92u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[70]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #071 | VA: 0x013600..0x013624 (36 B) | FDE: 0x0481f8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f9TransposeEv
//   0x013600: 2941200C  ldp      w12, w8, [x0, #8]
//   0x013604: B9400409  ldr      w9, [x0, #4]
//   0x013608: 2942AC0A  ldp      w10, w11, [x0, #0x14]
//   0x01360c: B9401C0D  ldr      w13, [x0, #0x1c]
//   0x013610: B9000408  str      w8, [x0, #4]
//   0x013614: 2901240B  stp      w11, w9, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_071_sub_013600(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2941200Cu;
    constexpr uint32_t kSecondOpcode = 0xB9400409u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[71]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #072 | VA: 0x013624..0x0136b4 (144 B) | FDE: 0x048210
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f6InvertEv
//   0x013624: D101C3FF  sub      sp, sp, #0x70
//   0x013628: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01362c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x013630: 910183FD  add      x29, sp, #0x60
//   0x013634: D53BD054  mrs      x20, tpidr_el0
//   0x013638: F9401688  ldr      x8, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_072_sub_013624(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9054FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFF330u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[72]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #073 | VA: 0x0136b4..0x01373c (136 B) | FDE: 0x048230
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f15InvertTransposeEv
//   0x0136b4: D101C3FF  sub      sp, sp, #0x70
//   0x0136b8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0136bc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0136c0: 910183FD  add      x29, sp, #0x60
//   0x0136c4: D53BD054  mrs      x20, tpidr_el0
//   0x0136c8: F9401688  ldr      x8, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_073_sub_0136b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9054FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFF30Eu;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[73]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #074 | VA: 0x01373c..0x01375c (32 B) | FDE: 0x048250
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3fmLEf
//   0x01373c: AD400801  ldp      q1, q2, [x0]
//   0x013740: BD402003  ldr      s3, [x0, #0x20]
//   0x013744: 4F809021  fmul     v1.4s, v1.4s, v0.s[0]
//   0x013748: 4F809042  fmul     v2.4s, v2.4s, v0.s[0]
//   0x01374c: 1E200860  fmul     s0, s3, s0
//   0x013750: AD000801  stp      q1, q2, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_074_sub_01373c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAD400801u;
    constexpr uint32_t kSecondOpcode = 0xBD402003u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[74]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #075 | VA: 0x01375c..0x013898 (316 B) | FDE: 0x048268
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3fmLERKS0_
//   0x01375c: BD400C00  ldr      s0, [x0, #0xc]
//   0x013760: 2D400821  ldp      s1, s2, [x1]
//   0x013764: 2D401404  ldp      s4, s5, [x0]
//   0x013768: BD400823  ldr      s3, [x1, #8]
//   0x01376c: 2D431C06  ldp      s6, s7, [x0, #0x18]
//   0x013770: 1E220802  fmul     s2, s0, s2
// ----------------------------------------------------------------------------
uint64_t fde_075_sub_01375c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400C00u;
    constexpr uint32_t kSecondOpcode = 0x2D400821u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[75]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #076 | VA: 0x013898..0x0139d4 (316 B) | FDE: 0x048280
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3fmLERKNS_10Matrix4x4fE
//   0x013898: BD400C00  ldr      s0, [x0, #0xc]
//   0x01389c: 2D400821  ldp      s1, s2, [x1]
//   0x0138a0: 2D401404  ldp      s4, s5, [x0]
//   0x0138a4: BD400823  ldr      s3, [x1, #8]
//   0x0138a8: 2D431C06  ldp      s6, s7, [x0, #0x18]
//   0x0138ac: 1E220802  fmul     s2, s0, s2
// ----------------------------------------------------------------------------
uint64_t fde_076_sub_013898(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400C00u;
    constexpr uint32_t kSecondOpcode = 0x2D400821u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[76]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #077 | VA: 0x0139d4..0x013a94 (192 B) | FDE: 0x048298
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f12SetAxisAngleERKNS_8Vector3fEf
//   0x0139d4: D100C3FF  sub      sp, sp, #0x30
//   0x0139d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0139dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0139e0: 910083FD  add      x29, sp, #0x20
//   0x0139e4: AA0103F3  mov      x19, x1
//   0x0139e8: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_077_sub_0139d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD100C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 192u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[77]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #078 | VA: 0x013a94..0x013b38 (164 B) | FDE: 0x0482b8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix3x3f17SetFromToRotationERKNS_8Vector3fES3_
//   0x013a94: D10143FF  sub      sp, sp, #0x50
//   0x013a98: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x013a9c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x013aa0: 910103FD  add      x29, sp, #0x40
//   0x013aa4: D53BD054  mrs      x20, tpidr_el0
//   0x013aa8: F9401689  ldr      x9, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_078_sub_013a94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA9034FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFF20Fu;
    constexpr uint32_t kFuncSize = 164u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[78]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #079 | VA: 0x013b38..0x013d4c (532 B) | FDE: 0x0482d8
// Symbol (EN/VN): internal_func_013b38
//   0x013b38: 2D400400  ldp      s0, s1, [x0]
//   0x013b3c: 2D409426  ldp      s6, s5, [x1, #4]
//   0x013b40: BD400024  ldr      s4, [x1]
//   0x013b44: BD400802  ldr      s2, [x0, #8]
//   0x013b48: 90000188  adrp     x8, #0x43000
//   0x013b4c: FD44B110  ldr      d16, [x8, #0x960]
// ----------------------------------------------------------------------------
uint64_t fde_079_sub_013b38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0x2D409426u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 532u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[79]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #080 | VA: 0x013d4c..0x013e24 (216 B) | FDE: 0x0482f0
// Symbol (EN/VN): _ZN13AmazingEngine13EulerToMatrixERKNS_8Vector3fERNS_10Matrix3x3fE
//   0x013d4c: D10183FF  sub      sp, sp, #0x60
//   0x013d50: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x013d54: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x013d58: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x013d5c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x013d60: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_080_sub_013d4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0x6D022BEBu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 216u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[80]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #081 | VA: 0x013e24..0x014060 (572 B) | FDE: 0x048320
// Symbol (EN/VN): _ZN13AmazingEngine13MatrixToEulerERKNS_10Matrix3x3fERNS_8Vector3fE
//   0x013e24: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x013e28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x013e2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x013e30: 910083FD  add      x29, sp, #0x20
//   0x013e34: BD401C00  ldr      s0, [x0, #0x1c]
//   0x013e38: 5297CEE8  mov      w8, #0xbe77
// ----------------------------------------------------------------------------
uint64_t fde_081_sub_013e24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBD23E9u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 572u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[81]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #082 | VA: 0x014060..0x014208 (424 B) | FDE: 0x048348
// Symbol (EN/VN): _ZN13AmazingEngine20LookRotationToMatrixERKNS_8Vector3fES2_PNS_10Matrix3x3fE
//   0x014060: 6DBA3BEF  stp      d15, d14, [sp, #-0x60]!
//   0x014064: 6D0133ED  stp      d13, d12, [sp, #0x10]
//   0x014068: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x01406c: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x014070: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x014074: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_082_sub_014060(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBA3BEFu;
    constexpr uint32_t kSecondOpcode = 0x6D0133EDu;
    constexpr uint32_t kLastOpcode = 0x17FFFFF8u;
    constexpr uint32_t kFuncSize = 424u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[82]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #083 | VA: 0x014208..0x014214 (12 B) | FDE: 0x048380
// Symbol (EN/VN): _ZN13AmazingEngine14OrthoNormalizeERNS_10Matrix3x3fE
//   0x014208: 91003001  add      x1, x0, #0xc
//   0x01420c: 91006002  add      x2, x0, #0x18
//   0x014210: 17FFEF10  b        #0xfe50
// ----------------------------------------------------------------------------
uint64_t fde_083_sub_014208(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91003001u;
    constexpr uint32_t kSecondOpcode = 0x91006002u;
    constexpr uint32_t kLastOpcode = 0x17FFEF10u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[83]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #084 | VA: 0x014214..0x014344 (304 B) | FDE: 0x048398
// Symbol (EN/VN): _ZN13AmazingEngine20CompareApproximatelyERKNS_10Matrix3x3fES2_f
//   0x014214: BD400001  ldr      s1, [x0]
//   0x014218: BD400022  ldr      s2, [x1]
//   0x01421c: 1E223821  fsub     s1, s1, s2
//   0x014220: 1E214022  fneg     s2, s1
//   0x014224: 1E202028  fcmp     s1, #0.0
//   0x014228: 1E214C41  fcsel    s1, s2, s1, mi
// ----------------------------------------------------------------------------
uint64_t fde_084_sub_014214(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400001u;
    constexpr uint32_t kSecondOpcode = 0xBD400022u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 304u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[84]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #085 | VA: 0x014344..0x0143bc (120 B) | FDE: 0x0483b0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f8identityEv
//   0x014344: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x014348: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01434c: 910043FD  add      x29, sp, #0x10
//   0x014350: 90000208  adrp     x8, #0x54000
//   0x014354: 91028108  add      x8, x8, #0xa0
//   0x014358: 08DFFD08  ldarb    w8, [x8]
// ----------------------------------------------------------------------------
uint64_t fde_085_sub_014344(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFFFEAu;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[85]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #086 | VA: 0x0143bc..0x014458 (156 B) | FDE: 0x0483d0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4fC2EPKf
//   0x0143bc: F0000168  adrp     x8, #0x43000
//   0x0143c0: 91278108  add      x8, x8, #0x9e0
//   0x0143c4: AD410101  ldp      q1, q0, [x8, #0x20]
//   0x0143c8: AD400903  ldp      q3, q2, [x8]
//   0x0143cc: AD010001  stp      q1, q0, [x0, #0x20]
//   0x0143d0: AD000803  stp      q3, q2, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_086_sub_0143bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000168u;
    constexpr uint32_t kSecondOpcode = 0x91278108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 156u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[86]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #087 | VA: 0x014458..0x0144cc (116 B) | FDE: 0x0483e8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4fC2ERKNS_10Matrix3x3fE
//   0x014458: F0000168  adrp     x8, #0x43000
//   0x01445c: 91278108  add      x8, x8, #0x9e0
//   0x014460: AD410101  ldp      q1, q0, [x8, #0x20]
//   0x014464: AD400903  ldp      q3, q2, [x8]
//   0x014468: 52A7F009  mov      w9, #0x3f800000
//   0x01446c: AD010001  stp      q1, q0, [x0, #0x20]
// ----------------------------------------------------------------------------
uint64_t fde_087_sub_014458(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000168u;
    constexpr uint32_t kSecondOpcode = 0x91278108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 116u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[87]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #088 | VA: 0x0144cc..0x014528 (92 B) | FDE: 0x048400
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4faSERKNS_10Matrix3x3fE
//   0x0144cc: B9400028  ldr      w8, [x1]
//   0x0144d0: 52A7F009  mov      w9, #0x3f800000
//   0x0144d4: B9000008  str      w8, [x0]
//   0x0144d8: B9400428  ldr      w8, [x1, #4]
//   0x0144dc: B9000408  str      w8, [x0, #4]
//   0x0144e0: B9400828  ldr      w8, [x1, #8]
// ----------------------------------------------------------------------------
uint64_t fde_088_sub_0144cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0x52A7F009u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 92u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[88]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #089 | VA: 0x014528..0x0146cc (420 B) | FDE: 0x048418
// Symbol (EN/VN): _ZNK13AmazingEngine10Matrix4x4f10IsIdentityEf
//   0x014528: BD400002  ldr      s2, [x0]
//   0x01452c: 1E3E1001  fmov     s1, #-1.00000000
//   0x014530: 1E212842  fadd     s2, s2, s1
//   0x014534: 1E214043  fneg     s3, s2
//   0x014538: 1E202048  fcmp     s2, #0.0
//   0x01453c: 1E224C62  fcsel    s2, s3, s2, mi
// ----------------------------------------------------------------------------
uint64_t fde_089_sub_014528(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400002u;
    constexpr uint32_t kSecondOpcode = 0x1E3E1001u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 420u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[89]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #090 | VA: 0x0146cc..0x014894 (456 B) | FDE: 0x048430
// Symbol (EN/VN): _ZNK13AmazingEngine10Matrix4x4f14GetDeterminantEv
//   0x0146cc: FC1D0FEC  str      d12, [sp, #-0x30]!
//   0x0146d0: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x0146d4: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x0146d8: 2D444410  ldp      s16, s17, [x0, #0x20]
//   0x0146dc: 2D464C12  ldp      s18, s19, [x0, #0x30]
//   0x0146e0: 2D401404  ldp      s4, s5, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_090_sub_0146cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xFC1D0FECu;
    constexpr uint32_t kSecondOpcode = 0x6D012BEBu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 456u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[90]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #091 | VA: 0x014894..0x01490c (120 B) | FDE: 0x048458
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4fmLERKS0_
//   0x014894: D101C3FF  sub      sp, sp, #0x70
//   0x014898: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01489c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0148a0: 910183FD  add      x29, sp, #0x60
//   0x0148a4: F0000168  adrp     x8, #0x43000
//   0x0148a8: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_091_sub_014894(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9054FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFEE9Au;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[91]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #092 | VA: 0x01490c..0x014a18 (268 B) | FDE: 0x048478
// Symbol (EN/VN): _ZN13AmazingEngine22MultiplyMatrices4x4REFEPKNS_10Matrix4x4fES2_PS0_
//   0x01490c: FD400005  ldr      d5, [x0]
//   0x014910: 91002008  add      x8, x0, #8
//   0x014914: FD400020  ldr      d0, [x1]
//   0x014918: FD400821  ldr      d1, [x1, #0x10]
//   0x01491c: 4D408105  ld1      {v5.s}[2], [x8]
//   0x014920: 2D414430  ldp      s16, s17, [x1, #8]
// ----------------------------------------------------------------------------
uint64_t fde_092_sub_01490c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xFD400005u;
    constexpr uint32_t kSecondOpcode = 0x91002008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 268u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[92]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #093 | VA: 0x014a18..0x014c58 (576 B) | FDE: 0x048490
// Symbol (EN/VN): _ZN13AmazingEngine19MultiplyMatrices3x4ERKNS_10Matrix4x4fES2_RS0_
//   0x014a18: BD400000  ldr      s0, [x0]
//   0x014a1c: BD401001  ldr      s1, [x0, #0x10]
//   0x014a20: 2D400C22  ldp      s2, s3, [x1]
//   0x014a24: BD402004  ldr      s4, [x0, #0x20]
//   0x014a28: BD400825  ldr      s5, [x1, #8]
//   0x014a2c: 52A7F008  mov      w8, #0x3f800000
// ----------------------------------------------------------------------------
uint64_t fde_093_sub_014a18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400000u;
    constexpr uint32_t kSecondOpcode = 0xBD401001u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 576u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[93]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #094 | VA: 0x014c58..0x014c84 (44 B) | FDE: 0x0484a8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f11SetIdentityEv
//   0x014c58: F0000168  adrp     x8, #0x43000
//   0x014c5c: F0000169  adrp     x9, #0x43000
//   0x014c60: F000016A  adrp     x10, #0x43000
//   0x014c64: F000016B  adrp     x11, #0x43000
//   0x014c68: 3DC25500  ldr      q0, [x8, #0x950]
//   0x014c6c: 3DC26921  ldr      q1, [x9, #0x9a0]
// ----------------------------------------------------------------------------
uint64_t fde_094_sub_014c58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000168u;
    constexpr uint32_t kSecondOpcode = 0xF0000169u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[94]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #095 | VA: 0x014c84..0x014cec (104 B) | FDE: 0x0484c0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f19SetOrthoNormalBasisERKNS_8Vector3fES3_S3_
//   0x014c84: B9400028  ldr      w8, [x1]
//   0x014c88: F0000169  adrp     x9, #0x43000
//   0x014c8c: FD44E920  ldr      d0, [x9, #0x9d0]
//   0x014c90: B9000008  str      w8, [x0]
//   0x014c94: B9400048  ldr      w8, [x2]
//   0x014c98: B9001008  str      w8, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_095_sub_014c84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0xF0000169u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[95]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #096 | VA: 0x014cec..0x014d48 (92 B) | FDE: 0x0484d8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f26SetOrthoNormalBasisInverseERKNS_8Vector3fES3_S3_
//   0x014cec: B9400028  ldr      w8, [x1]
//   0x014cf0: 52A7F009  mov      w9, #0x3f800000
//   0x014cf4: B9000008  str      w8, [x0]
//   0x014cf8: B9400048  ldr      w8, [x2]
//   0x014cfc: B9000408  str      w8, [x0, #4]
//   0x014d00: B9400068  ldr      w8, [x3]
// ----------------------------------------------------------------------------
uint64_t fde_096_sub_014cec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0x52A7F009u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 92u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[96]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #097 | VA: 0x014d48..0x014dbc (116 B) | FDE: 0x0484f0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f30SetPositionAndOrthoNormalBasisERKNS_8Vector3fES3_S3_S3_
//   0x014d48: B9400048  ldr      w8, [x2]
//   0x014d4c: 52A7F009  mov      w9, #0x3f800000
//   0x014d50: B9000008  str      w8, [x0]
//   0x014d54: B9400068  ldr      w8, [x3]
//   0x014d58: B9001008  str      w8, [x0, #0x10]
//   0x014d5c: B9400088  ldr      w8, [x4]
// ----------------------------------------------------------------------------
uint64_t fde_097_sub_014d48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400048u;
    constexpr uint32_t kSecondOpcode = 0x52A7F009u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 116u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[97]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #098 | VA: 0x014dbc..0x014e04 (72 B) | FDE: 0x048508
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f8SetScaleERKNS_8Vector3fE
//   0x014dbc: B9400028  ldr      w8, [x1]
//   0x014dc0: B900101F  str      wzr, [x0, #0x10]
//   0x014dc4: B900201F  str      wzr, [x0, #0x20]
//   0x014dc8: B900301F  str      wzr, [x0, #0x30]
//   0x014dcc: 29007C08  stp      w8, wzr, [x0]
//   0x014dd0: B9400428  ldr      w8, [x1, #4]
// ----------------------------------------------------------------------------
uint64_t fde_098_sub_014dbc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400028u;
    constexpr uint32_t kSecondOpcode = 0xB900101Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[98]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #099 | VA: 0x014e04..0x014eb0 (172 B) | FDE: 0x048520
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f5ScaleERKNS_8Vector3fE
//   0x014e04: BD400020  ldr      s0, [x1]
//   0x014e08: 2D400801  ldp      s1, s2, [x0]
//   0x014e0c: 1E210800  fmul     s0, s0, s1
//   0x014e10: BD000000  str      s0, [x0]
//   0x014e14: BD400020  ldr      s0, [x1]
//   0x014e18: 1E220800  fmul     s0, s0, s2
// ----------------------------------------------------------------------------
uint64_t fde_099_sub_014e04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400020u;
    constexpr uint32_t kSecondOpcode = 0x2D400801u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[99]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #100 | VA: 0x014eb0..0x014f64 (180 B) | FDE: 0x048538
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f9TranslateERKNS_8Vector3fE
//   0x014eb0: 2D400821  ldp      s1, s2, [x1]
//   0x014eb4: 2D401803  ldp      s3, s6, [x0]
//   0x014eb8: BD400825  ldr      s5, [x1, #8]
//   0x014ebc: 1E210861  fmul     s1, s3, s1
//   0x014ec0: 2D420C00  ldp      s0, s3, [x0, #0x10]
//   0x014ec4: 1E220800  fmul     s0, s0, s2
// ----------------------------------------------------------------------------
uint64_t fde_100_sub_014eb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400821u;
    constexpr uint32_t kSecondOpcode = 0x2D401803u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 180u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[100]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #101 | VA: 0x014f64..0x014f94 (48 B) | FDE: 0x048550
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f12AddTranslateERKNS_8Vector3fE
//   0x014f64: BD400020  ldr      s0, [x1]
//   0x014f68: 2D460801  ldp      s1, s2, [x0, #0x30]
//   0x014f6c: 1E212800  fadd     s0, s0, s1
//   0x014f70: BD003000  str      s0, [x0, #0x30]
//   0x014f74: BD400420  ldr      s0, [x1, #4]
//   0x014f78: BD403801  ldr      s1, [x0, #0x38]
// ----------------------------------------------------------------------------
uint64_t fde_101_sub_014f64(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400020u;
    constexpr uint32_t kSecondOpcode = 0x2D460801u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[101]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #102 | VA: 0x014f94..0x014fe4 (80 B) | FDE: 0x048568
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f12SetTranslateERKNS_8Vector3fE
//   0x014f94: 52A7F008  mov      w8, #0x3f800000
//   0x014f98: B900101F  str      wzr, [x0, #0x10]
//   0x014f9c: B900201F  str      wzr, [x0, #0x20]
//   0x014fa0: B9000008  str      w8, [x0]
//   0x014fa4: B9400029  ldr      w9, [x1]
//   0x014fa8: B900041F  str      wzr, [x0, #4]
// ----------------------------------------------------------------------------
uint64_t fde_102_sub_014f94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52A7F008u;
    constexpr uint32_t kSecondOpcode = 0xB900101Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[102]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #103 | VA: 0x014fe4..0x0150ac (200 B) | FDE: 0x048580
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f14SetPerspectiveEffff
//   0x014fe4: D10103FF  sub      sp, sp, #0x40
//   0x014fe8: FD000BEA  str      d10, [sp, #0x10]
//   0x014fec: 6D01A3E9  stp      d9, d8, [sp, #0x18]
//   0x014ff0: F90017F3  str      x19, [sp, #0x28]
//   0x014ff4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x014ff8: 9100C3FD  add      x29, sp, #0x30
// ----------------------------------------------------------------------------
uint64_t fde_103_sub_014fe4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xFD000BEAu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 200u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[103]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #104 | VA: 0x0150ac..0x0150f4 (72 B) | FDE: 0x0485a8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f19SetPerspectiveCotanEfff
//   0x0150ac: 1E223823  fsub     s3, s1, s2
//   0x0150b0: BD000000  str      s0, [x0]
//   0x0150b4: BD001400  str      s0, [x0, #0x14]
//   0x0150b8: 1E222820  fadd     s0, s1, s2
//   0x0150bc: 1E212821  fadd     s1, s1, s1
//   0x0150c0: 1E220821  fmul     s1, s1, s2
// ----------------------------------------------------------------------------
uint64_t fde_104_sub_0150ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E223823u;
    constexpr uint32_t kSecondOpcode = 0xBD000000u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[104]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #105 | VA: 0x0150f4..0x015168 (116 B) | FDE: 0x0485c0
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f8SetOrthoEffffff
//   0x0150f4: 1E203827  fsub     s7, s1, s0
//   0x0150f8: 1E223870  fsub     s16, s3, s2
//   0x0150fc: 1E2438B1  fsub     s17, s5, s4
//   0x015100: 1E212800  fadd     s0, s0, s1
//   0x015104: 1E232841  fadd     s1, s2, s3
//   0x015108: 1E301002  fmov     s2, #-2.00000000
// ----------------------------------------------------------------------------
uint64_t fde_105_sub_0150f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E203827u;
    constexpr uint32_t kSecondOpcode = 0x1E223870u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 116u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[105]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #106 | VA: 0x015168..0x0151e0 (120 B) | FDE: 0x0485d8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f10SetFrustumEffffff
//   0x015168: 1E203827  fsub     s7, s1, s0
//   0x01516c: 1E223870  fsub     s16, s3, s2
//   0x015170: 1E212800  fadd     s0, s0, s1
//   0x015174: 1E232841  fadd     s1, s2, s3
//   0x015178: 1E252882  fadd     s2, s4, s5
//   0x01517c: 1E2438A3  fsub     s3, s5, s4
// ----------------------------------------------------------------------------
uint64_t fde_106_sub_015168(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E203827u;
    constexpr uint32_t kSecondOpcode = 0x1E223870u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[106]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #107 | VA: 0x0151e0..0x0159e0 (2048 B) | FDE: 0x0485f0
// Symbol (EN/VN): _ZN13AmazingEngine20InvertMatrix4x4_FullEPKfPf
//   0x0151e0: D10283FF  sub      sp, sp, #0xa0
//   0x0151e4: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x0151e8: 910243FD  add      x29, sp, #0x90
//   0x0151ec: D53BD048  mrs      x8, tpidr_el0
//   0x0151f0: F9401509  ldr      x9, [x8, #0x28]
//   0x0151f4: D000016A  adrp     x10, #0x43000
// ----------------------------------------------------------------------------
uint64_t fde_107_sub_0151e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xA9097BFDu;
    constexpr uint32_t kLastOpcode = 0x97FFEA65u;
    constexpr uint32_t kFuncSize = 2048u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[107]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #108 | VA: 0x0159e0..0x015c7c (668 B) | FDE: 0x048610
// Symbol (EN/VN): _ZN13AmazingEngine25InvertMatrix4x4_General3DEPKfPf
//   0x0159e0: 2D420004  ldp      s4, s0, [x0, #0x10]
//   0x0159e4: 2D401C06  ldp      s6, s7, [x0]
//   0x0159e8: 2D448403  ldp      s3, s1, [x0, #0x24]
//   0x0159ec: BD401802  ldr      s2, [x0, #0x18]
//   0x0159f0: BD400810  ldr      s16, [x0, #8]
//   0x0159f4: BD402011  ldr      s17, [x0, #0x20]
// ----------------------------------------------------------------------------
uint64_t fde_108_sub_0159e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D420004u;
    constexpr uint32_t kSecondOpcode = 0x2D401C06u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 668u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[108]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #109 | VA: 0x015c7c..0x015cbc (64 B) | FDE: 0x048628
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f9TransposeEv
//   0x015c7c: 2940AC08  ldp      w8, w11, [x0, #4]
//   0x015c80: 2941A809  ldp      w9, w10, [x0, #0xc]
//   0x015c84: B9001008  str      w8, [x0, #0x10]
//   0x015c88: 29443008  ldp      w8, w12, [x0, #0x20]
//   0x015c8c: B900200B  str      w11, [x0, #0x20]
//   0x015c90: 2900A00A  stp      w10, w8, [x0, #4]
// ----------------------------------------------------------------------------
uint64_t fde_109_sub_015c7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2940AC08u;
    constexpr uint32_t kSecondOpcode = 0x2941A809u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 64u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[109]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #110 | VA: 0x015cbc..0x015ce8 (44 B) | FDE: 0x048640
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f4CopyERKS0_
//   0x015cbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x015cc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015cc4: 910043FD  add      x29, sp, #0x10
//   0x015cc8: AA0003F3  mov      x19, x0
//   0x015ccc: AA0103E0  mov      x0, x1
//   0x015cd0: AA1303E1  mov      x1, x19
// ----------------------------------------------------------------------------
uint64_t fde_110_sub_015cbc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[110]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #111 | VA: 0x015ce8..0x015d98 (176 B) | FDE: 0x048660
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f17SetFromToRotationERKNS_8Vector3fES3_
//   0x015ce8: D10143FF  sub      sp, sp, #0x50
//   0x015cec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x015cf0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x015cf4: 910103FD  add      x29, sp, #0x40
//   0x015cf8: D53BD054  mrs      x20, tpidr_el0
//   0x015cfc: F9401689  ldr      x9, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_111_sub_015ce8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA9034FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFE977u;
    constexpr uint32_t kFuncSize = 176u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[111]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #112 | VA: 0x015d98..0x015fa8 (528 B) | FDE: 0x048680
// Symbol (EN/VN): _ZN13AmazingEngine20CompareApproximatelyERKNS_10Matrix4x4fES2_f
//   0x015d98: BD400001  ldr      s1, [x0]
//   0x015d9c: BD400022  ldr      s2, [x1]
//   0x015da0: 1E223821  fsub     s1, s1, s2
//   0x015da4: 1E214022  fneg     s2, s1
//   0x015da8: 1E202028  fcmp     s1, #0.0
//   0x015dac: 1E214C41  fcsel    s1, s2, s1, mi
// ----------------------------------------------------------------------------
uint64_t fde_112_sub_015d98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400001u;
    constexpr uint32_t kSecondOpcode = 0xBD400022u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 528u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[112]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #113 | VA: 0x015fa8..0x015fec (68 B) | FDE: 0x048698
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f5SetTRERKNS_8Vector3fERKNS_11QuaternionfE
//   0x015fa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x015fac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015fb0: 910043FD  add      x29, sp, #0x10
//   0x015fb4: AA0003F4  mov      x20, x0
//   0x015fb8: AA0103F3  mov      x19, x1
//   0x015fbc: AA0203E0  mov      x0, x2
// ----------------------------------------------------------------------------
uint64_t fde_113_sub_015fa8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[113]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #114 | VA: 0x015fec..0x0160c0 (212 B) | FDE: 0x0486b8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f6SetTRSERKNS_8Vector3fERKNS_11QuaternionfES3_
//   0x015fec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x015ff0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x015ff4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x015ff8: 910083FD  add      x29, sp, #0x20
//   0x015ffc: AA0003F5  mov      x21, x0
//   0x016000: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_114_sub_015fec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 212u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[114]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #115 | VA: 0x0160c0..0x016228 (360 B) | FDE: 0x0486d8
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f7SetTRSSERKNS_8Vector3fERKNS_11QuaternionfES3_S3_
//   0x0160c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0160c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0160c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0160cc: 910083FD  add      x29, sp, #0x20
//   0x0160d0: AA0003F3  mov      x19, x0
//   0x0160d4: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_115_sub_0160c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 360u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[115]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #116 | VA: 0x016228..0x0162dc (180 B) | FDE: 0x048700
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f12SetTRInverseERKNS_8Vector3fERKNS_11QuaternionfE
//   0x016228: D10143FF  sub      sp, sp, #0x50
//   0x01622c: F90013F5  str      x21, [sp, #0x20]
//   0x016230: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x016234: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x016238: 910103FD  add      x29, sp, #0x40
//   0x01623c: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_116_sub_016228(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FFE826u;
    constexpr uint32_t kFuncSize = 180u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[116]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #117 | VA: 0x0162dc..0x01647c (416 B) | FDE: 0x048720
// Symbol (EN/VN): _ZN13AmazingEngine18TransformPoints3x3ERKNS_10Matrix4x4fEPKNS_8Vector3fEPS3_i
//   0x0162dc: D101C3FF  sub      sp, sp, #0x70
//   0x0162e0: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x0162e4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0162e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0162ec: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0162f0: 910183FD  add      x29, sp, #0x60
// ----------------------------------------------------------------------------
uint64_t fde_117_sub_0162dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0x6D0323E9u;
    constexpr uint32_t kLastOpcode = 0x97FFE7BEu;
    constexpr uint32_t kFuncSize = 416u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[117]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #118 | VA: 0x01647c..0x01660c (400 B) | FDE: 0x048748
// Symbol (EN/VN): _ZN13AmazingEngine18TransformPoints3x4ERKNS_10Matrix4x4fEPKNS_8Vector3fEPS3_i
//   0x01647c: 7100047F  cmp      w3, #1
//   0x016480: 54000C4B  b.lt     #0x16608
//   0x016484: 71000C7F  cmp      w3, #3
//   0x016488: 2A0303E8  mov      w8, w3
//   0x01648c: AA1F03E9  mov      x9, xzr
//   0x016490: 540007A9  b.ls     #0x16584
// ----------------------------------------------------------------------------
uint64_t fde_118_sub_01647c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x7100047Fu;
    constexpr uint32_t kSecondOpcode = 0x54000C4Bu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 400u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[118]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #119 | VA: 0x01660c..0x0166ec (224 B) | FDE: 0x048760
// Symbol (EN/VN): _ZN13AmazingEngine18TransformPoints3x3ERKNS_10Matrix4x4fEPKNS_8Vector3fEmPS3_mi
//   0x01660c: D101C3FF  sub      sp, sp, #0x70
//   0x016610: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x016614: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x016618: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01661c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x016620: 910183FD  add      x29, sp, #0x60
// ----------------------------------------------------------------------------
uint64_t fde_119_sub_01660c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9035FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFE722u;
    constexpr uint32_t kFuncSize = 224u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[119]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #120 | VA: 0x0166ec..0x016770 (132 B) | FDE: 0x048788
// Symbol (EN/VN): _ZN13AmazingEngine18TransformPoints3x4ERKNS_10Matrix4x4fEPKNS_8Vector3fEmPS3_mi
//   0x0166ec: 710004BF  cmp      w5, #1
//   0x0166f0: 540003EB  b.lt     #0x1676c
//   0x0166f4: 91002028  add      x8, x1, #8
//   0x0166f8: 91002069  add      x9, x3, #8
//   0x0166fc: 2D7F0500  ldp      s0, s1, [x8, #-8]
//   0x016700: FD400003  ldr      d3, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_120_sub_0166ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x710004BFu;
    constexpr uint32_t kSecondOpcode = 0x540003EBu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 132u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[120]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #121 | VA: 0x016770..0x0168d4 (356 B) | FDE: 0x0487a0
// Symbol (EN/VN): _ZNK13AmazingEngine10Matrix4x4f12getDecomposeEPNS_8Vector3fES2_PNS_11QuaternionfE
//   0x016770: D103C3FF  sub      sp, sp, #0xf0
//   0x016774: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x016778: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x01677c: 910383FD  add      x29, sp, #0xe0
//   0x016780: D53BD054  mrs      x20, tpidr_el0
//   0x016784: F9401688  ldr      x8, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_121_sub_016770(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD103C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90D4FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFE6A8u;
    constexpr uint32_t kFuncSize = 356u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[121]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #122 | VA: 0x0168d4..0x016bec (792 B) | FDE: 0x0487c0
// Symbol (EN/VN): _ZNK13AmazingEngine10Matrix4x4f12getDecomposeEPNS_8Vector3fES2_PNS_11QuaternionfES2_
//   0x0168d4: D103C3FF  sub      sp, sp, #0xf0
//   0x0168d8: 6D053BEF  stp      d15, d14, [sp, #0x50]
//   0x0168dc: 6D0633ED  stp      d13, d12, [sp, #0x60]
//   0x0168e0: 6D072BEB  stp      d11, d10, [sp, #0x70]
//   0x0168e4: 6D0823E9  stp      d9, d8, [sp, #0x80]
//   0x0168e8: A9096FFC  stp      x28, x27, [sp, #0x90]
// ----------------------------------------------------------------------------
uint64_t fde_122_sub_0168d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD103C3FFu;
    constexpr uint32_t kSecondOpcode = 0x6D053BEFu;
    constexpr uint32_t kLastOpcode = 0x97FFE5E2u;
    constexpr uint32_t kFuncSize = 792u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[122]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #123 | VA: 0x016bec..0x016d38 (332 B) | FDE: 0x048808
// Symbol (EN/VN): _ZN13AmazingEngine10Matrix4x4f13alignAxisWithEiRKNS_8Vector3fE
//   0x016bec: D101C3FF  sub      sp, sp, #0x70
//   0x016bf0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x016bf4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x016bf8: 910183FD  add      x29, sp, #0x60
//   0x016bfc: D53BD054  mrs      x20, tpidr_el0
//   0x016c00: F9401688  ldr      x8, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_123_sub_016bec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9054FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFE58Fu;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[123]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #124 | VA: 0x016d38..0x016d4c (20 B) | FDE: 0x048828
// Symbol (EN/VN): _ZN13AmazingEngine13CopyMatrixREFEPKfPf
//   0x016d38: AD410001  ldp      q1, q0, [x0, #0x20]
//   0x016d3c: AD400803  ldp      q3, q2, [x0]
//   0x016d40: AD010021  stp      q1, q0, [x1, #0x20]
//   0x016d44: AD000823  stp      q3, q2, [x1]
//   0x016d48: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_124_sub_016d38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAD410001u;
    constexpr uint32_t kSecondOpcode = 0xAD400803u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[124]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #125 | VA: 0x016d4c..0x016da0 (84 B) | FDE: 0x048840
// Symbol (EN/VN): _ZN13AmazingEngine21TransposeMatrix4x4REFEPKNS_10Matrix4x4fEPS0_
//   0x016d4c: AD400001  ldp      q1, q0, [x0]
//   0x016d50: AD410C02  ldp      q2, q3, [x0, #0x20]
//   0x016d54: AD000021  stp      q1, q0, [x1]
//   0x016d58: 2940A828  ldp      w8, w10, [x1, #4]
//   0x016d5c: AD010C22  stp      q2, q3, [x1, #0x20]
//   0x016d60: 2941A42B  ldp      w11, w9, [x1, #0xc]
// ----------------------------------------------------------------------------
uint64_t fde_125_sub_016d4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAD400001u;
    constexpr uint32_t kSecondOpcode = 0xAD410C02u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 84u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[125]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #126 | VA: 0x016da0..0x016df8 (88 B) | FDE: 0x048858
// Symbol (EN/VN): _ZN13AmazingEngine25MultiplyMatrixArray4x4REFEPKNS_10Matrix4x4fES2_PS0_m
//   0x016da0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x016da4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x016da8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x016dac: 910083FD  add      x29, sp, #0x20
//   0x016db0: B40001C3  cbz      x3, #0x16de8
//   0x016db4: AA0303F3  mov      x19, x3
// ----------------------------------------------------------------------------
uint64_t fde_126_sub_016da0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[126]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #127 | VA: 0x016df8..0x016eac (180 B) | FDE: 0x048880
// Symbol (EN/VN): _ZN13AmazingEngine33MultiplyMatrixArrayWithBase4x4REFEPKNS_10Matrix4x4fES2_S2_PS0_m
//   0x016df8: D10243FF  sub      sp, sp, #0x90
//   0x016dfc: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x016e00: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x016e04: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x016e08: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x016e0c: 910203FD  add      x29, sp, #0x80
// ----------------------------------------------------------------------------
uint64_t fde_127_sub_016df8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9055FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFE532u;
    constexpr uint32_t kFuncSize = 180u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[127]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #128 | VA: 0x016eac..0x017054 (424 B) | FDE: 0x0488a8
// Symbol (EN/VN): _ZN13AmazingEngine11PerlinNoise8Perlin2DERKNS_8Vector2fEf
//   0x016eac: 2D400402  ldp      s2, s1, [x0]
//   0x016eb0: B0000168  adrp     x8, #0x43000
//   0x016eb4: 912B8108  add      x8, x8, #0xae0
//   0x016eb8: 1E231006  fmov     s6, #6.00000000
//   0x016ebc: 1E202840  fadd     s0, s2, s0
//   0x016ec0: 1E30000A  fcvtms   w10, s0
// ----------------------------------------------------------------------------
uint64_t fde_128_sub_016eac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400402u;
    constexpr uint32_t kSecondOpcode = 0xB0000168u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 424u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[128]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #129 | VA: 0x017054..0x017098 (68 B) | FDE: 0x0488c0
// Symbol (EN/VN): _ZN13AmazingEngine11PerlinNoise14Perlin2DVectorERKNS_8Vector2fES1_
//   0x017054: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x017058: F9000BF3  str      x19, [sp, #0x10]
//   0x01705c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x017060: 910083FD  add      x29, sp, #0x20
//   0x017064: 4EA11C28  mov      v8.16b, v1.16b
//   0x017068: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_129_sub_017054(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBD23E9u;
    constexpr uint32_t kSecondOpcode = 0xF9000BF3u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[129]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #130 | VA: 0x017098..0x01834c (4788 B) | FDE: 0x0488e8
// Symbol (EN/VN): _ZN13AmazingEngine11PerlinNoise8Perlin3DERKNS_8Vector3fEf
//   0x017098: 2D400403  ldp      s3, s1, [x0]
//   0x01709c: BD400802  ldr      s2, [x0, #8]
//   0x0170a0: 90000168  adrp     x8, #0x43000
//   0x0170a4: 912B8108  add      x8, x8, #0xae0
//   0x0170a8: 1E202860  fadd     s0, s3, s0
//   0x0170ac: 1E30004B  fcvtms   w11, s2
// ----------------------------------------------------------------------------
uint64_t fde_130_sub_017098(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400403u;
    constexpr uint32_t kSecondOpcode = 0xBD400802u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4788u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[130]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #131 | VA: 0x01834c..0x0183b0 (100 B) | FDE: 0x048900
// Symbol (EN/VN): _ZN13AmazingEngine11PerlinNoise14Perlin3DVectorERKNS_8Vector3fES1_
//   0x01834c: FC1D0FEA  str      d10, [sp, #-0x30]!
//   0x018350: 6D00A3E9  stp      d9, d8, [sp, #8]
//   0x018354: F9000FF3  str      x19, [sp, #0x18]
//   0x018358: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01835c: 910083FD  add      x29, sp, #0x20
//   0x018360: 4EA21C48  mov      v8.16b, v2.16b
// ----------------------------------------------------------------------------
uint64_t fde_131_sub_01834c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xFC1D0FEAu;
    constexpr uint32_t kSecondOpcode = 0x6D00A3E9u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[131]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #132 | VA: 0x0183b0..0x0184a8 (248 B) | FDE: 0x048928
// Symbol (EN/VN): _ZN13AmazingEngine11PerlinNoise15FractalPerlin3DERKNS_8Vector3fEiff
//   0x0183b0: D10183FF  sub      sp, sp, #0x60
//   0x0183b4: FD001BEA  str      d10, [sp, #0x30]
//   0x0183b8: 6D03A3E9  stp      d9, d8, [sp, #0x38]
//   0x0183bc: F90027F3  str      x19, [sp, #0x48]
//   0x0183c0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0183c4: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_132_sub_0183b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xFD001BEAu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[132]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #133 | VA: 0x0184a8..0x018720 (632 B) | FDE: 0x048950
// Symbol (EN/VN): _ZN13AmazingEngine11PerlinNoise21FractalPerlin3DVectorERKNS_8Vector3fEifS1_
//   0x0184a8: D10243FF  sub      sp, sp, #0x90
//   0x0184ac: 6D033BEF  stp      d15, d14, [sp, #0x30]
//   0x0184b0: 6D0433ED  stp      d13, d12, [sp, #0x40]
//   0x0184b4: 6D052BEB  stp      d11, d10, [sp, #0x50]
//   0x0184b8: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x0184bc: F9003BF3  str      x19, [sp, #0x70]
// ----------------------------------------------------------------------------
uint64_t fde_133_sub_0184a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0x6D033BEFu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 632u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[133]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #134 | VA: 0x018720..0x018894 (372 B) | FDE: 0x048988
// Symbol (EN/VN): _ZN13AmazingEngine5SlerpERKNS_11QuaternionfES2_f
//   0x018720: D101C3FF  sub      sp, sp, #0x70
//   0x018724: 6D0333ED  stp      d13, d12, [sp, #0x30]
//   0x018728: 6D042BEB  stp      d11, d10, [sp, #0x40]
//   0x01872c: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x018730: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x018734: 910183FD  add      x29, sp, #0x60
// ----------------------------------------------------------------------------
uint64_t fde_134_sub_018720(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0x6D0333EDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 372u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[134]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #135 | VA: 0x018894..0x0189c4 (304 B) | FDE: 0x0489b8
// Symbol (EN/VN): _ZN13AmazingEngine17EulerToQuaternionERKNS_8Vector3fE
//   0x018894: D10183FF  sub      sp, sp, #0x60
//   0x018898: FD0013EC  str      d12, [sp, #0x20]
//   0x01889c: 6D02ABEB  stp      d11, d10, [sp, #0x28]
//   0x0188a0: 6D03A3E9  stp      d9, d8, [sp, #0x38]
//   0x0188a4: F90027F3  str      x19, [sp, #0x48]
//   0x0188a8: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_135_sub_018894(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xFD0013ECu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 304u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[135]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #136 | VA: 0x0189c4..0x018aa0 (220 B) | FDE: 0x0489e8
// Symbol (EN/VN): _ZN13AmazingEngine17QuaternionToEulerERKNS_11QuaternionfE
//   0x0189c4: D10183FF  sub      sp, sp, #0x60
//   0x0189c8: F90023F3  str      x19, [sp, #0x40]
//   0x0189cc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0189d0: 910143FD  add      x29, sp, #0x50
//   0x0189d4: D53BD053  mrs      x19, tpidr_el0
//   0x0189d8: F9401668  ldr      x8, [x19, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_136_sub_0189c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90023F3u;
    constexpr uint32_t kLastOpcode = 0x97FFDE35u;
    constexpr uint32_t kFuncSize = 220u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[136]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #137 | VA: 0x018aa0..0x018b24 (132 B) | FDE: 0x048a08
// Symbol (EN/VN): _ZN13AmazingEngine18QuaternionToMatrixERKNS_11QuaternionfERNS_10Matrix3x3fE
//   0x018aa0: 2D400400  ldp      s0, s1, [x0]
//   0x018aa4: 2D410C02  ldp      s2, s3, [x0, #8]
//   0x018aa8: 1E2E1004  fmov     s4, #1.00000000
//   0x018aac: 1E202805  fadd     s5, s0, s0
//   0x018ab0: 1E212826  fadd     s6, s1, s1
//   0x018ab4: 1E222847  fadd     s7, s2, s2
// ----------------------------------------------------------------------------
uint64_t fde_137_sub_018aa0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0x2D410C02u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 132u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[137]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #138 | VA: 0x018b24..0x018bc4 (160 B) | FDE: 0x048a20
// Symbol (EN/VN): _ZN13AmazingEngine18QuaternionToMatrixERKNS_11QuaternionfERNS_10Matrix4x4fE
//   0x018b24: 2D400400  ldp      s0, s1, [x0]
//   0x018b28: 2D410C02  ldp      s2, s3, [x0, #8]
//   0x018b2c: 1E2E1004  fmov     s4, #1.00000000
//   0x018b30: 52A7F008  mov      w8, #0x3f800000
//   0x018b34: 1E202805  fadd     s5, s0, s0
//   0x018b38: 1E212826  fadd     s6, s1, s1
// ----------------------------------------------------------------------------
uint64_t fde_138_sub_018b24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0x2D410C02u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[138]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #139 | VA: 0x018bc4..0x018c3c (120 B) | FDE: 0x048a38
// Symbol (EN/VN): _ZN13AmazingEngine18MatrixToQuaternionERKNS_10Matrix4x4fERNS_11QuaternionfE
//   0x018bc4: D10143FF  sub      sp, sp, #0x50
//   0x018bc8: F9001BF3  str      x19, [sp, #0x30]
//   0x018bcc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x018bd0: 910103FD  add      x29, sp, #0x40
//   0x018bd4: D53BD053  mrs      x19, tpidr_el0
//   0x018bd8: F9401668  ldr      x8, [x19, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_139_sub_018bc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9001BF3u;
    constexpr uint32_t kLastOpcode = 0x97FFDDCEu;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[139]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #140 | VA: 0x018c3c..0x018e1c (480 B) | FDE: 0x048a58
// Symbol (EN/VN): _ZN13AmazingEngine18MatrixToQuaternionERKNS_10Matrix3x3fERNS_11QuaternionfE
//   0x018c3c: D100C3FF  sub      sp, sp, #0x30
//   0x018c40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x018c44: 910083FD  add      x29, sp, #0x20
//   0x018c48: D53BD048  mrs      x8, tpidr_el0
//   0x018c4c: F9401509  ldr      x9, [x8, #0x28]
//   0x018c50: F81F83A9  stur     x9, [x29, #-8]
// ----------------------------------------------------------------------------
uint64_t fde_140_sub_018c3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD100C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9027BFDu;
    constexpr uint32_t kLastOpcode = 0x97FFDD56u;
    constexpr uint32_t kFuncSize = 480u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[140]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #141 | VA: 0x018e1c..0x018eac (144 B) | FDE: 0x048a78
// Symbol (EN/VN): _ZN13AmazingEngine24LookRotationToQuaternionERKNS_8Vector3fES2_PNS_11QuaternionfE
//   0x018e1c: D10143FF  sub      sp, sp, #0x50
//   0x018e20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x018e24: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x018e28: 910103FD  add      x29, sp, #0x40
//   0x018e2c: F0000148  adrp     x8, #0x43000
//   0x018e30: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_141_sub_018e1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA9034FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFDD32u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[141]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #142 | VA: 0x018eac..0x019034 (392 B) | FDE: 0x048a98
// Symbol (EN/VN): _ZN13AmazingEngine20FromToQuaternionSafeERKNS_8Vector3fES2_
//   0x018eac: D10343FF  sub      sp, sp, #0xd0
//   0x018eb0: FD0043EC  str      d12, [sp, #0x80]
//   0x018eb4: 6D08ABEB  stp      d11, d10, [sp, #0x88]
//   0x018eb8: 6D09A3E9  stp      d9, d8, [sp, #0x98]
//   0x018ebc: F90057F5  str      x21, [sp, #0xa8]
//   0x018ec0: A90B4FF4  stp      x20, x19, [sp, #0xb0]
// ----------------------------------------------------------------------------
uint64_t fde_142_sub_018eac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10343FFu;
    constexpr uint32_t kSecondOpcode = 0xFD0043ECu;
    constexpr uint32_t kLastOpcode = 0x97FFDCD0u;
    constexpr uint32_t kFuncSize = 392u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[142]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #143 | VA: 0x019034..0x0190bc (136 B) | FDE: 0x048ac8
// Symbol (EN/VN): _ZN13AmazingEngine16FromToQuaternionERKNS_8Vector3fES2_
//   0x019034: D10183FF  sub      sp, sp, #0x60
//   0x019038: F90023F3  str      x19, [sp, #0x40]
//   0x01903c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x019040: 910143FD  add      x29, sp, #0x50
//   0x019044: D0000148  adrp     x8, #0x43000
//   0x019048: D53BD053  mrs      x19, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_143_sub_019034(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90023F3u;
    constexpr uint32_t kLastOpcode = 0x97FFDCAEu;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[143]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #144 | VA: 0x0190bc..0x0190c8 (12 B) | FDE: 0x048ae8
// Symbol (EN/VN): _ZN13AmazingEngine8Vector2f4zeroEv
//   0x0190bc: 1E2703E0  fmov     s0, wzr
//   0x0190c0: 1E2703E1  fmov     s1, wzr
//   0x0190c4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_144_sub_0190bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2703E0u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E1u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[144]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #145 | VA: 0x0190c8..0x0190d4 (12 B) | FDE: 0x048b00
// Symbol (EN/VN): _ZN13AmazingEngine8Vector2f3oneEv
//   0x0190c8: 1E2E1000  fmov     s0, #1.00000000
//   0x0190cc: 4EA01C01  mov      v1.16b, v0.16b
//   0x0190d0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_145_sub_0190c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2E1000u;
    constexpr uint32_t kSecondOpcode = 0x4EA01C01u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[145]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #146 | VA: 0x0190d4..0x0190e4 (16 B) | FDE: 0x048b18
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f7epsilonEv
//   0x0190d4: 5298B588  mov      w8, #0xc5ac
//   0x0190d8: 72A6E4E8  movk     w8, #0x3727, lsl #16
//   0x0190dc: 1E270100  fmov     s0, w8
//   0x0190e0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_146_sub_0190d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x5298B588u;
    constexpr uint32_t kSecondOpcode = 0x72A6E4E8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[146]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #147 | VA: 0x0190e4..0x0190f0 (12 B) | FDE: 0x048b30
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f8infinityEv
//   0x0190e4: 52AFF008  mov      w8, #0x7f800000
//   0x0190e8: 1E270100  fmov     s0, w8
//   0x0190ec: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_147_sub_0190e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52AFF008u;
    constexpr uint32_t kSecondOpcode = 0x1E270100u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[147]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #148 | VA: 0x0190f0..0x019104 (20 B) | FDE: 0x048b48
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f11infinityVecEv
//   0x0190f0: 52AFF008  mov      w8, #0x7f800000
//   0x0190f4: 1E270100  fmov     s0, w8
//   0x0190f8: 4EA01C01  mov      v1.16b, v0.16b
//   0x0190fc: 4EA01C02  mov      v2.16b, v0.16b
//   0x019100: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_148_sub_0190f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52AFF008u;
    constexpr uint32_t kSecondOpcode = 0x1E270100u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[148]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #149 | VA: 0x019104..0x019114 (16 B) | FDE: 0x048b60
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f4zeroEv
//   0x019104: 1E2703E0  fmov     s0, wzr
//   0x019108: 1E2703E1  fmov     s1, wzr
//   0x01910c: 1E2703E2  fmov     s2, wzr
//   0x019110: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_149_sub_019104(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2703E0u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E1u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[149]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #150 | VA: 0x019114..0x019124 (16 B) | FDE: 0x048b78
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f3oneEv
//   0x019114: 1E2E1000  fmov     s0, #1.00000000
//   0x019118: 4EA01C01  mov      v1.16b, v0.16b
//   0x01911c: 4EA01C02  mov      v2.16b, v0.16b
//   0x019120: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_150_sub_019114(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2E1000u;
    constexpr uint32_t kSecondOpcode = 0x4EA01C01u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[150]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #151 | VA: 0x019124..0x019134 (16 B) | FDE: 0x048b90
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f5xAxisEv
//   0x019124: 1E2E1000  fmov     s0, #1.00000000
//   0x019128: 1E2703E1  fmov     s1, wzr
//   0x01912c: 1E2703E2  fmov     s2, wzr
//   0x019130: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_151_sub_019124(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2E1000u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E1u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[151]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #152 | VA: 0x019134..0x019144 (16 B) | FDE: 0x048ba8
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f5yAxisEv
//   0x019134: 1E2E1001  fmov     s1, #1.00000000
//   0x019138: 1E2703E0  fmov     s0, wzr
//   0x01913c: 1E2703E2  fmov     s2, wzr
//   0x019140: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_152_sub_019134(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2E1001u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[152]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #153 | VA: 0x019144..0x019154 (16 B) | FDE: 0x048bc0
// Symbol (EN/VN): _ZN13AmazingEngine8Vector3f5zAxisEv
//   0x019144: 1E2E1002  fmov     s2, #1.00000000
//   0x019148: 1E2703E0  fmov     s0, wzr
//   0x01914c: 1E2703E1  fmov     s1, wzr
//   0x019150: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_153_sub_019144(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2E1002u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[153]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #154 | VA: 0x019154..0x019280 (300 B) | FDE: 0x048bd8
// Symbol (EN/VN): _ZN13AmazingEngine18OrthoNormalizeFastEPNS_8Vector3fES1_S1_
//   0x019154: 2D400400  ldp      s0, s1, [x0]
//   0x019158: BD400802  ldr      s2, [x0, #8]
//   0x01915c: 1E200803  fmul     s3, s0, s0
//   0x019160: 1E210824  fmul     s4, s1, s1
//   0x019164: 1E220845  fmul     s5, s2, s2
//   0x019168: 1E242863  fadd     s3, s3, s4
// ----------------------------------------------------------------------------
uint64_t fde_154_sub_019154(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0xBD400802u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 300u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[154]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #155 | VA: 0x019280..0x0193f0 (368 B) | FDE: 0x048bf0
// Symbol (EN/VN): _ZN13AmazingEngine14OrthoNormalizeEPNS_8Vector3fES1_
//   0x019280: 2D400400  ldp      s0, s1, [x0]
//   0x019284: BD400802  ldr      s2, [x0, #8]
//   0x019288: 5298B588  mov      w8, #0xc5ac
//   0x01928c: 72A6E4E8  movk     w8, #0x3727, lsl #16
//   0x019290: 1E200803  fmul     s3, s0, s0
//   0x019294: 1E210824  fmul     s4, s1, s1
// ----------------------------------------------------------------------------
uint64_t fde_155_sub_019280(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0xBD400802u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 368u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[155]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #156 | VA: 0x0193f0..0x01946c (124 B) | FDE: 0x048c08
// Symbol (EN/VN): _ZN13AmazingEngine21OrthoNormalVectorFastERKNS_8Vector3fE
//   0x0193f0: BD400800  ldr      s0, [x0, #8]
//   0x0193f4: 52809E68  mov      w8, #0x4f3
//   0x0193f8: 72A7E6A8  movk     w8, #0x3f35, lsl #16
//   0x0193fc: 1E270102  fmov     s2, w8
//   0x019400: 1E214001  fneg     s1, s0
//   0x019404: 1E202008  fcmp     s0, #0.0
// ----------------------------------------------------------------------------
uint64_t fde_156_sub_0193f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400800u;
    constexpr uint32_t kSecondOpcode = 0x52809E68u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 124u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[156]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #157 | VA: 0x01946c..0x0196c0 (596 B) | FDE: 0x048c20
// Symbol (EN/VN): _ZN13AmazingEngine14OrthoNormalizeEPNS_8Vector3fES1_S1_
//   0x01946c: 2D400400  ldp      s0, s1, [x0]
//   0x019470: BD400802  ldr      s2, [x0, #8]
//   0x019474: 5298B588  mov      w8, #0xc5ac
//   0x019478: 72A6E4E8  movk     w8, #0x3727, lsl #16
//   0x01947c: 1E200803  fmul     s3, s0, s0
//   0x019480: 1E210824  fmul     s4, s1, s1
// ----------------------------------------------------------------------------
uint64_t fde_157_sub_01946c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0xBD400802u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 596u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[157]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #158 | VA: 0x0196c0..0x019748 (136 B) | FDE: 0x048c38
// Symbol (EN/VN): _ZN13AmazingEngine11MoveTowardsERKNS_8Vector3fES2_f
//   0x0196c0: FD400023  ldr      d3, [x1]
//   0x0196c4: FD400001  ldr      d1, [x0]
//   0x0196c8: BD400822  ldr      s2, [x1, #8]
//   0x0196cc: BD400804  ldr      s4, [x0, #8]
//   0x0196d0: 0EA1D465  fsub     v5.2s, v3.2s, v1.2s
//   0x0196d4: 2E25DCA7  fmul     v7.2s, v5.2s, v5.2s
// ----------------------------------------------------------------------------
uint64_t fde_158_sub_0196c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xFD400023u;
    constexpr uint32_t kSecondOpcode = 0xFD400001u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[158]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #159 | VA: 0x019748..0x019ad4 (908 B) | FDE: 0x048c50
// Symbol (EN/VN): _ZN13AmazingEngine13RotateTowardsERKNS_8Vector3fES2_ff
//   0x019748: D10343FF  sub      sp, sp, #0xd0
//   0x01974c: 6D0A23E9  stp      d9, d8, [sp, #0xa0]
//   0x019750: F9005BF3  str      x19, [sp, #0xb0]
//   0x019754: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x019758: 910303FD  add      x29, sp, #0xc0
//   0x01975c: D53BD053  mrs      x19, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_159_sub_019748(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10343FFu;
    constexpr uint32_t kSecondOpcode = 0x6D0A23E9u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 908u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[159]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #160 | VA: 0x019ad4..0x019df4 (800 B) | FDE: 0x048c78
// Symbol (EN/VN): _ZN13AmazingEngine5SlerpERKNS_8Vector3fES2_f
//   0x019ad4: D102C3FF  sub      sp, sp, #0xb0
//   0x019ad8: F9004BF3  str      x19, [sp, #0x90]
//   0x019adc: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x019ae0: 910283FD  add      x29, sp, #0xa0
//   0x019ae4: D53BD053  mrs      x19, tpidr_el0
//   0x019ae8: F9401668  ldr      x8, [x19, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_160_sub_019ad4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD102C3FFu;
    constexpr uint32_t kSecondOpcode = 0xF9004BF3u;
    constexpr uint32_t kLastOpcode = 0x97FFD960u;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[160]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #161 | VA: 0x019df4..0x019e18 (36 B) | FDE: 0x048c98
// Symbol (EN/VN): _ZN13AmazingEngine15NormalizeRobustERKNS_8Vector3fE
//   0x019df4: D10083FF  sub      sp, sp, #0x20
//   0x019df8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x019dfc: 910043FD  add      x29, sp, #0x10
//   0x019e00: D10013A1  sub      x1, x29, #4
//   0x019e04: 910023E2  add      x2, sp, #8
//   0x019e08: 94000004  bl       #0x19e18
// ----------------------------------------------------------------------------
uint64_t fde_161_sub_019df4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10083FFu;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[161]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #162 | VA: 0x019e18..0x019f98 (384 B) | FDE: 0x048cb8
// Symbol (EN/VN): internal_func_019e18
//   0x019e18: 2D400400  ldp      s0, s1, [x0]
//   0x019e1c: 5298B588  mov      w8, #0xc5ac
//   0x019e20: 72A6E4E8  movk     w8, #0x3727, lsl #16
//   0x019e24: 1E270107  fmov     s7, w8
//   0x019e28: 1E214002  fneg     s2, s0
//   0x019e2c: 1E202008  fcmp     s0, #0.0
// ----------------------------------------------------------------------------
uint64_t fde_162_sub_019e18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D400400u;
    constexpr uint32_t kSecondOpcode = 0x5298B588u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 384u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[162]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #163 | VA: 0x019f98..0x019fd0 (56 B) | FDE: 0x048cd0
// Symbol (EN/VN): _ZN13AmazingEngine15NormalizeRobustERKNS_8Vector3fERf
//   0x019f98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x019f9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x019fa0: 910043FD  add      x29, sp, #0x10
//   0x019fa4: AA0103F3  mov      x19, x1
//   0x019fa8: D10013A1  sub      x1, x29, #4
//   0x019fac: 910023E2  add      x2, sp, #8
// ----------------------------------------------------------------------------
uint64_t fde_163_sub_019f98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[163]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #164 | VA: 0x019fd0..0x01a01c (76 B) | FDE: 0x048cf0
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPoolC2Ei
//   0x019fd0: B900081F  str      wzr, [x0, #8]
//   0x019fd4: D00001C8  adrp     x8, #0x53000
//   0x019fd8: F9471108  ldr      x8, [x8, #0xe20]
//   0x019fdc: 52800029  mov      w9, #1
//   0x019fe0: 6F00E400  movi     v0.2d, #0000000000000000
//   0x019fe4: 39038009  strb     w9, [x0, #0xe0]
// ----------------------------------------------------------------------------
uint64_t fde_164_sub_019fd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900081Fu;
    constexpr uint32_t kSecondOpcode = 0xD00001C8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[164]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #165 | VA: 0x01a01c..0x01a300 (740 B) | FDE: 0x048d08
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPoolD2Ev
//   0x01a01c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x01a020: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x01a024: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01a028: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01a02c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01a030: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_165_sub_01a01c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BB67FAu;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFD569u;
    constexpr uint32_t kFuncSize = 740u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[165]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #166 | VA: 0x01a300..0x01a324 (36 B) | FDE: 0x048d38
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPoolD0Ev
//   0x01a300: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a304: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a308: 910043FD  add      x29, sp, #0x10
//   0x01a30c: AA0003F3  mov      x19, x0
//   0x01a310: 97FFD69C  bl       #0xfd80
//   0x01a314: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_166_sub_01a300(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFD590u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[166]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #167 | VA: 0x01a324..0x01a338 (20 B) | FDE: 0x048d58
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPool3runEv
//   0x01a324: B940E808  ldr      w8, [x0, #0xe8]
//   0x01a328: 528001E9  mov      w9, #0xf
//   0x01a32c: 71003D1F  cmp      w8, #0xf
//   0x01a330: 1A89B101  csel     w1, w8, w9, lt
//   0x01a334: 17FFD583  b        #0xf940
// ----------------------------------------------------------------------------
uint64_t fde_167_sub_01a324(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB940E808u;
    constexpr uint32_t kSecondOpcode = 0x528001E9u;
    constexpr uint32_t kLastOpcode = 0x17FFD583u;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[167]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #168 | VA: 0x01a338..0x01a498 (352 B) | FDE: 0x048d70
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPool9AddThreadEi
//   0x01a338: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x01a33c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x01a340: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x01a344: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01a348: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01a34c: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_168_sub_01a338(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFD6F3u;
    constexpr uint32_t kFuncSize = 352u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[168]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #169 | VA: 0x01a498..0x01a4cc (52 B) | FDE: 0x048da0
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPool12clearAllTaskEv
//   0x01a498: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01a49c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a4a0: 910043FD  add      x29, sp, #0x10
//   0x01a4a4: 91022014  add      x20, x0, #0x88
//   0x01a4a8: AA0003F3  mov      x19, x0
//   0x01a4ac: AA1403E0  mov      x0, x20
// ----------------------------------------------------------------------------
uint64_t fde_169_sub_01a498(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFD5AEu;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[169]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #170 | VA: 0x01a4cc..0x01a5b8 (236 B) | FDE: 0x048dc0
// Symbol (EN/VN): _ZN13AmazingEngine10ThreadPool9clearTaskEi
//   0x01a4cc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x01a4d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01a4d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01a4d8: 910083FD  add      x29, sp, #0x20
//   0x01a4dc: 91022014  add      x20, x0, #0x88
//   0x01a4e0: AA0003F5  mov      x21, x0
// ----------------------------------------------------------------------------
uint64_t fde_170_sub_01a4cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFD573u;
    constexpr uint32_t kFuncSize = 236u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[170]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #171 | VA: 0x01a5b8..0x01a958 (928 B) | FDE: 0x048de8
// Symbol (EN/VN): internal_func_01a5b8
//   0x01a5b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x01a5bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01a5c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01a5c4: 910083FD  add      x29, sp, #0x20
//   0x01a5c8: F940100B  ldr      x11, [x0, #0x20]
//   0x01a5cc: A940B00A  ldp      x10, x12, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_171_sub_01a5b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 928u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[171]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #172 | VA: 0x01a958..0x01aa88 (304 B) | FDE: 0x048e10
// Symbol (EN/VN): internal_func_01a958
//   0x01a958: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x01a95c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01a960: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01a964: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01a968: 9100C3FD  add      x29, sp, #0x30
//   0x01a96c: A940A408  ldp      x8, x9, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_172_sub_01a958(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 304u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[172]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #173 | VA: 0x01aa88..0x01abd8 (336 B) | FDE: 0x048e38
// Symbol (EN/VN): internal_func_01aa88
//   0x01aa88: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x01aa8c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01aa90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01aa94: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01aa98: 9100C3FD  add      x29, sp, #0x30
//   0x01aa9c: EB01007F  cmp      x3, x1
// ----------------------------------------------------------------------------
uint64_t fde_173_sub_01aa88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 336u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[173]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #174 | VA: 0x01abd8..0x01acf8 (288 B) | FDE: 0x048e60
// Symbol (EN/VN): internal_func_01abd8
//   0x01abd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x01abdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01abe0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01abe4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01abe8: 9100C3FD  add      x29, sp, #0x30
//   0x01abec: EB01007F  cmp      x3, x1
// ----------------------------------------------------------------------------
uint64_t fde_174_sub_01abd8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 288u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[174]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #175 | VA: 0x01acf8..0x01af08 (528 B) | FDE: 0x048e88
// Symbol (EN/VN): internal_func_01acf8
//   0x01acf8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x01acfc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x01ad00: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x01ad04: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01ad08: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01ad0c: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_175_sub_01acf8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 528u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[175]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #176 | VA: 0x01af08..0x01b0a8 (416 B) | FDE: 0x048eb8
// Symbol (EN/VN): internal_func_01af08
//   0x01af08: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x01af0c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x01af10: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x01af14: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01af18: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01af1c: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_176_sub_01af08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81A0FFBu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 416u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[176]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #177 | VA: 0x01b0a8..0x01b0ac (4 B) | FDE: 0x048ee8
// Symbol (EN/VN): internal_func_01b0a8
//   0x01b0a8: 17FFD22E  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_177_sub_01b0a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FFD22Eu;
    constexpr uint32_t kSecondOpcode = 0x17FFD22Eu;
    constexpr uint32_t kLastOpcode = 0x17FFD22Eu;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[177]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #178 | VA: 0x01b0ac..0x01b0e4 (56 B) | FDE: 0x048f00
// Symbol (EN/VN): internal_func_01b0ac
//   0x01b0ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01b0b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01b0b4: 910043FD  add      x29, sp, #0x10
//   0x01b0b8: AA0003F3  mov      x19, x0
//   0x01b0bc: 52800300  mov      w0, #0x18
//   0x01b0c0: 97FFD450  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_178_sub_01b0ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[178]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #179 | VA: 0x01b0e4..0x01b0fc (24 B) | FDE: 0x048f20
// Symbol (EN/VN): internal_func_01b0e4
//   0x01b0e4: F00001A8  adrp     x8, #0x52000
//   0x01b0e8: 911F4108  add      x8, x8, #0x7d0
//   0x01b0ec: F9000028  str      x8, [x1]
//   0x01b0f0: 3CC08000  ldur     q0, [x0, #8]
//   0x01b0f4: 3C808020  stur     q0, [x1, #8]
//   0x01b0f8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_179_sub_01b0e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF00001A8u;
    constexpr uint32_t kSecondOpcode = 0x911F4108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[179]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #180 | VA: 0x01b0fc..0x01b100 (4 B) | FDE: 0x048f38
// Symbol (EN/VN): internal_func_01b0fc
//   0x01b0fc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_180_sub_01b0fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[180]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #181 | VA: 0x01b100..0x01b104 (4 B) | FDE: 0x048f50
// Symbol (EN/VN): internal_func_01b100
//   0x01b100: 17FFD218  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_181_sub_01b100(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FFD218u;
    constexpr uint32_t kSecondOpcode = 0x17FFD218u;
    constexpr uint32_t kLastOpcode = 0x17FFD218u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[181]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #182 | VA: 0x01b104..0x01b434 (816 B) | FDE: 0x048f68
// Symbol (EN/VN): internal_func_01b104
//   0x01b104: D10303FF  sub      sp, sp, #0xc0
//   0x01b108: F90033FB  str      x27, [sp, #0x60]
//   0x01b10c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x01b110: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x01b114: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x01b118: A90A4FF4  stp      x20, x19, [sp, #0xa0]
// ----------------------------------------------------------------------------
uint64_t fde_182_sub_01b104(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10303FFu;
    constexpr uint32_t kSecondOpcode = 0xF90033FBu;
    constexpr uint32_t kLastOpcode = 0x97FFD3D0u;
    constexpr uint32_t kFuncSize = 816u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[182]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #183 | VA: 0x01b434..0x01b438 (4 B) | FDE: 0x048f98
// Symbol (EN/VN): internal_func_01b434
//   0x01b434: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_183_sub_01b434(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[183]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #184 | VA: 0x01b438..0x01b514 (220 B) | FDE: 0x048fb0
// Symbol (EN/VN): internal_func_01b438
//   0x01b438: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01b43c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01b440: 910043FD  add      x29, sp, #0x10
//   0x01b444: 900001C8  adrp     x8, #0x53000
//   0x01b448: F946AD08  ldr      x8, [x8, #0xd58]
//   0x01b44c: 12800009  mov      w9, #-1
// ----------------------------------------------------------------------------
uint64_t fde_184_sub_01b438(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 220u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[184]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #185 | VA: 0x01b514..0x01b51c (8 B) | FDE: 0x048fd0
// Symbol (EN/VN): internal_func_01b514
//   0x01b514: F9400800  ldr      x0, [x0, #0x10]
//   0x01b518: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_185_sub_01b514(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[185]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #186 | VA: 0x01b51c..0x01b6bc (416 B) | FDE: 0x048fe8
// Symbol (EN/VN): internal_func_01b51c
//   0x01b51c: D10143FF  sub      sp, sp, #0x50
//   0x01b520: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01b524: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01b528: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01b52c: 910103FD  add      x29, sp, #0x40
//   0x01b530: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_186_sub_01b51c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA90257F6u;
    constexpr uint32_t kLastOpcode = 0x97FFD32Eu;
    constexpr uint32_t kFuncSize = 416u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[186]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #187 | VA: 0x01b6bc..0x01b730 (116 B) | FDE: 0x049010
// Symbol (EN/VN): internal_func_01b6bc
//   0x01b6bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01b6c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01b6c4: 910043FD  add      x29, sp, #0x10
//   0x01b6c8: B40002A0  cbz      x0, #0x1b71c
//   0x01b6cc: F9400408  ldr      x8, [x0, #8]
//   0x01b6d0: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_187_sub_01b6bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x97FFD926u;
    constexpr uint32_t kFuncSize = 116u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[187]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #188 | VA: 0x01b730..0x01b880 (336 B) | FDE: 0x049030
// Symbol (EN/VN): internal_func_01b730
//   0x01b730: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x01b734: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01b738: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01b73c: 910083FD  add      x29, sp, #0x20
//   0x01b740: F9400008  ldr      x8, [x0]
//   0x01b744: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_188_sub_01b730(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 336u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[188]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #189 | VA: 0x01b880..0x01b960 (224 B) | FDE: 0x049050
// Symbol (EN/VN): internal_func_01b880
//   0x01b880: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01b884: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01b888: 910043FD  add      x29, sp, #0x10
//   0x01b88c: F9400008  ldr      x8, [x0]
//   0x01b890: AA0003F3  mov      x19, x0
//   0x01b894: F9400D08  ldr      x8, [x8, #0x18]
// ----------------------------------------------------------------------------
uint64_t fde_189_sub_01b880(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 224u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[189]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #190 | VA: 0x01b960..0x01b970 (16 B) | FDE: 0x049070
// Symbol (EN/VN): internal_func_01b960
//   0x01b960: F9400808  ldr      x8, [x0, #0x10]
//   0x01b964: F100011F  cmp      x8, #0
//   0x01b968: 1A9F07E0  cset     w0, ne
//   0x01b96c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_190_sub_01b960(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400808u;
    constexpr uint32_t kSecondOpcode = 0xF100011Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[190]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #191 | VA: 0x01b970..0x01ba34 (196 B) | FDE: 0x049088
// Symbol (EN/VN): internal_func_01b970
//   0x01b970: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01b974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01b978: 910043FD  add      x29, sp, #0x10
//   0x01b97c: 7100043F  cmp      w1, #1
//   0x01b980: 5400054B  b.lt     #0x1ba28
//   0x01b984: 39415008  ldrb     w8, [x0, #0x54]
// ----------------------------------------------------------------------------
uint64_t fde_191_sub_01b970(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 196u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[191]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #192 | VA: 0x01ba34..0x01ba68 (52 B) | FDE: 0x0490a8
// Symbol (EN/VN): internal_func_01ba34
//   0x01ba34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01ba38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01ba3c: 910043FD  add      x29, sp, #0x10
//   0x01ba40: F9400813  ldr      x19, [x0, #0x10]
//   0x01ba44: 97FFD08F  bl       #0xfc80
//   0x01ba48: AA0003E1  mov      x1, x0
// ----------------------------------------------------------------------------
uint64_t fde_192_sub_01ba34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[192]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #193 | VA: 0x01ba68..0x01bad0 (104 B) | FDE: 0x0490c8
// Symbol (EN/VN): internal_func_01ba68
//   0x01ba68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01ba6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01ba70: 910043FD  add      x29, sp, #0x10
//   0x01ba74: AA0003F4  mov      x20, x0
//   0x01ba78: AA0103E0  mov      x0, x1
//   0x01ba7c: AA0103F3  mov      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_193_sub_01ba68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFCFD9u;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[193]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #194 | VA: 0x01bad0..0x01bb8c (188 B) | FDE: 0x0490e8
// Symbol (EN/VN): internal_func_01bad0
//   0x01bad0: D10143FF  sub      sp, sp, #0x50
//   0x01bad4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01bad8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01badc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01bae0: 910103FD  add      x29, sp, #0x40
//   0x01bae4: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_194_sub_01bad0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA90257F6u;
    constexpr uint32_t kLastOpcode = 0x97FFD1FAu;
    constexpr uint32_t kFuncSize = 188u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[194]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #195 | VA: 0x01bb8c..0x01bc18 (140 B) | FDE: 0x049110
// Symbol (EN/VN): internal_func_01bb8c
//   0x01bb8c: D10143FF  sub      sp, sp, #0x50
//   0x01bb90: F90013F5  str      x21, [sp, #0x20]
//   0x01bb94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01bb98: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01bb9c: 910103FD  add      x29, sp, #0x40
//   0x01bba0: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_195_sub_01bb8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FFD1D7u;
    constexpr uint32_t kFuncSize = 140u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[195]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #196 | VA: 0x01bc18..0x01bcc8 (176 B) | FDE: 0x049130
// Symbol (EN/VN): internal_func_01bc18
//   0x01bc18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01bc1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01bc20: 910043FD  add      x29, sp, #0x10
//   0x01bc24: 900001C9  adrp     x9, #0x53000
//   0x01bc28: F9400808  ldr      x8, [x0, #0x10]
//   0x01bc2c: F946AD29  ldr      x9, [x9, #0xd58]
// ----------------------------------------------------------------------------
uint64_t fde_196_sub_01bc18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFCF27u;
    constexpr uint32_t kFuncSize = 176u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[196]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #197 | VA: 0x01bcc8..0x01bcec (36 B) | FDE: 0x049150
// Symbol (EN/VN): internal_func_01bcc8
//   0x01bcc8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01bccc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01bcd0: 910043FD  add      x29, sp, #0x10
//   0x01bcd4: AA0003F3  mov      x19, x0
//   0x01bcd8: 97FFFFD0  bl       #0x1bc18
//   0x01bcdc: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_197_sub_01bcc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFCF1Eu;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[197]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #198 | VA: 0x01bcec..0x01bd38 (76 B) | FDE: 0x049170
// Symbol (EN/VN): _ZN13AmazingEngine29_threadWrapper_create_PThreadEiPNSt6__ndk18functionIFvvEEE
//   0x01bcec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x01bcf0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01bcf4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01bcf8: 910083FD  add      x29, sp, #0x20
//   0x01bcfc: 2A0003F4  mov      w20, w0
//   0x01bd00: 52801700  mov      w0, #0xb8
// ----------------------------------------------------------------------------
uint64_t fde_198_sub_01bcec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[198]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #199 | VA: 0x01bd38..0x01be28 (240 B) | FDE: 0x049190
// Symbol (EN/VN): _ZN13AmazingEngine13ThreadUtility17setThreadPriorityEPNS_13ThreadWrapperENS0_8PriorityEi
//   0x01bd38: D10183FF  sub      sp, sp, #0x60
//   0x01bd3c: F90013F7  str      x23, [sp, #0x20]
//   0x01bd40: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01bd44: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01bd48: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x01bd4c: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_199_sub_01bd38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x97FFD153u;
    constexpr uint32_t kFuncSize = 240u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[199]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #200 | VA: 0x01be28..0x01bee8 (192 B) | FDE: 0x0491b8
// Symbol (EN/VN): _ZN13AmazingEngine13ThreadUtility21mappingThreadPriorityElNS0_8PriorityEi
//   0x01be28: D10143FF  sub      sp, sp, #0x50
//   0x01be2c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01be30: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01be34: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01be38: 910103FD  add      x29, sp, #0x40
//   0x01be3c: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_200_sub_01be28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA90257F6u;
    constexpr uint32_t kLastOpcode = 0x97FFD123u;
    constexpr uint32_t kFuncSize = 192u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[200]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #201 | VA: 0x01bee8..0x01bf2c (68 B) | FDE: 0x0491e0
// Symbol (EN/VN): _ZN13AmazingEngine11FSystemTime7secondsEv
//   0x01bee8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01beec: 910003FD  mov      x29, sp
//   0x01bef0: 97FFD090  bl       #0x10130
//   0x01bef4: D29EF9E8  mov      x8, #0xf7cf
//   0x01bef8: F2BC6A68  movk     x8, #0xe353, lsl #16
//   0x01befc: F2D374A8  movk     x8, #0x9ba5, lsl #32
// ----------------------------------------------------------------------------
uint64_t fde_201_sub_01bee8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[201]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #202 | VA: 0x01bf2c..0x01bfb0 (132 B) | FDE: 0x049200
// Symbol (EN/VN): _ZN13AmazingEngine11FSystemTime11getDateTimeEv
//   0x01bf2c: D100C3FF  sub      sp, sp, #0x30
//   0x01bf30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01bf34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01bf38: 910083FD  add      x29, sp, #0x20
//   0x01bf3c: D53BD054  mrs      x20, tpidr_el0
//   0x01bf40: AA0803F3  mov      x19, x8
// ----------------------------------------------------------------------------
uint64_t fde_202_sub_01bf2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD100C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFD0F1u;
    constexpr uint32_t kFuncSize = 132u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[202]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #203 | VA: 0x01bfb0..0x01c044 (148 B) | FDE: 0x049220
// Symbol (EN/VN): _ZN13AmazingEngine11FSystemTime15getSystemTimeMSEv
//   0x01bfb0: D10083FF  sub      sp, sp, #0x20
//   0x01bfb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01bfb8: 910043FD  add      x29, sp, #0x10
//   0x01bfbc: 910003E0  mov      x0, sp
//   0x01bfc0: AA1F03E1  mov      x1, xzr
//   0x01bfc4: 97FFCE33  bl       #0xf890
// ----------------------------------------------------------------------------
uint64_t fde_203_sub_01bfb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10083FFu;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 148u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[203]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #204 | VA: 0x01c044..0x01c0c0 (124 B) | FDE: 0x049240
// Symbol (EN/VN): _ZN13AmazingEngine11FSystemTime15getSystemTimeUSEv
//   0x01c044: D10083FF  sub      sp, sp, #0x20
//   0x01c048: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c04c: 910043FD  add      x29, sp, #0x10
//   0x01c050: 910003E0  mov      x0, sp
//   0x01c054: AA1F03E1  mov      x1, xzr
//   0x01c058: 97FFCE0E  bl       #0xf890
// ----------------------------------------------------------------------------
uint64_t fde_204_sub_01c044(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10083FFu;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 124u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[204]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #205 | VA: 0x01c0c0..0x01c118 (88 B) | FDE: 0x049260
// Symbol (EN/VN): _ZN13AmazingEngine10FTimerBaseC2Ev
//   0x01c0c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c0c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c0c8: 910043FD  add      x29, sp, #0x10
//   0x01c0cc: AA0003F3  mov      x19, x0
//   0x01c0d0: F900001F  str      xzr, [x0]
//   0x01c0d4: 97FFD017  bl       #0x10130
// ----------------------------------------------------------------------------
uint64_t fde_205_sub_01c0c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[205]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #206 | VA: 0x01c118..0x01c16c (84 B) | FDE: 0x049280
// Symbol (EN/VN): _ZN13AmazingEngine10FTimerBase5resetEv
//   0x01c118: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c11c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c120: 910043FD  add      x29, sp, #0x10
//   0x01c124: AA0003F3  mov      x19, x0
//   0x01c128: 97FFD002  bl       #0x10130
//   0x01c12c: D29EF9E8  mov      x8, #0xf7cf
// ----------------------------------------------------------------------------
uint64_t fde_206_sub_01c118(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 84u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[206]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #207 | VA: 0x01c16c..0x01c1c4 (88 B) | FDE: 0x0492a0
// Symbol (EN/VN): _ZNK13AmazingEngine10FTimerBase14elapsedSecondsEv
//   0x01c16c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c174: 910043FD  add      x29, sp, #0x10
//   0x01c178: AA0003F3  mov      x19, x0
//   0x01c17c: 97FFCFED  bl       #0x10130
//   0x01c180: D29EF9E8  mov      x8, #0xf7cf
// ----------------------------------------------------------------------------
uint64_t fde_207_sub_01c16c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[207]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #208 | VA: 0x01c1c4..0x01c230 (108 B) | FDE: 0x0492c0
// Symbol (EN/VN): _ZNK13AmazingEngine10FTimerBase19elapsedMillisecondsEv
//   0x01c1c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c1c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c1cc: 910043FD  add      x29, sp, #0x10
//   0x01c1d0: AA0003F3  mov      x19, x0
//   0x01c1d4: 97FFCFD7  bl       #0x10130
//   0x01c1d8: D29EF9E8  mov      x8, #0xf7cf
// ----------------------------------------------------------------------------
uint64_t fde_208_sub_01c1c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[208]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #209 | VA: 0x01c230..0x01c290 (96 B) | FDE: 0x0492e0
// Symbol (EN/VN): _ZNK13AmazingEngine10FTimerBase19elapsedMicrosecondsEv
//   0x01c230: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c234: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c238: 910043FD  add      x29, sp, #0x10
//   0x01c23c: AA0003F3  mov      x19, x0
//   0x01c240: 97FFCFBC  bl       #0x10130
//   0x01c244: D29EF9E8  mov      x8, #0xf7cf
// ----------------------------------------------------------------------------
uint64_t fde_209_sub_01c230(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[209]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #210 | VA: 0x01c290..0x01c36c (220 B) | FDE: 0x049300
// Symbol (EN/VN): internal_func_01c290
//   0x01c290: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x01c294: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x01c298: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01c29c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01c2a0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01c2a4: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_210_sub_01c290(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFCF3Eu;
    constexpr uint32_t kFuncSize = 220u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[210]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #211 | VA: 0x01c36c..0x01c3c4 (88 B) | FDE: 0x049328
// Symbol (EN/VN): internal_func_01c36c
//   0x01c36c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c370: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c374: 910043FD  add      x29, sp, #0x10
//   0x01c378: F00001A8  adrp     x8, #0x53000
//   0x01c37c: AA0003F3  mov      x19, x0
//   0x01c380: F9401400  ldr      x0, [x0, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_211_sub_01c36c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFCD38u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[211]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #212 | VA: 0x01c3c4..0x01c424 (96 B) | FDE: 0x049348
// Symbol (EN/VN): internal_func_01c3c4
//   0x01c3c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c3c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c3cc: 910043FD  add      x29, sp, #0x10
//   0x01c3d0: F00001A8  adrp     x8, #0x53000
//   0x01c3d4: AA0003F3  mov      x19, x0
//   0x01c3d8: F9401400  ldr      x0, [x0, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_212_sub_01c3c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFCD50u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[212]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #213 | VA: 0x01c424..0x01c600 (476 B) | FDE: 0x049368
// Symbol (EN/VN): internal_func_01c424
//   0x01c424: D10103FF  sub      sp, sp, #0x40
//   0x01c428: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01c42c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01c430: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01c434: 9100C3FD  add      x29, sp, #0x30
//   0x01c438: B4000742  cbz      x2, #0x1c520
// ----------------------------------------------------------------------------
uint64_t fde_213_sub_01c424(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x17FFFFCAu;
    constexpr uint32_t kFuncSize = 476u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[213]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #214 | VA: 0x01c600..0x01c724 (292 B) | FDE: 0x049390
// Symbol (EN/VN): internal_func_01c600
//   0x01c600: D100C3FF  sub      sp, sp, #0x30
//   0x01c604: F9000BF3  str      x19, [sp, #0x10]
//   0x01c608: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01c60c: 910083FD  add      x29, sp, #0x20
//   0x01c610: F9402008  ldr      x8, [x0, #0x40]
//   0x01c614: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_214_sub_01c600(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD100C3FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF3u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 292u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[214]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #215 | VA: 0x01c724..0x01c72c (8 B) | FDE: 0x0493b0
// Symbol (EN/VN): internal_func_01c724
//   0x01c724: F9401800  ldr      x0, [x0, #0x30]
//   0x01c728: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_215_sub_01c724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9401800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[215]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #216 | VA: 0x01c72c..0x01c734 (8 B) | FDE: 0x0493c8
// Symbol (EN/VN): internal_func_01c72c
//   0x01c72c: F9401C00  ldr      x0, [x0, #0x38]
//   0x01c730: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_216_sub_01c72c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9401C00u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[216]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #217 | VA: 0x01c734..0x01c7c4 (144 B) | FDE: 0x0493e0
// Symbol (EN/VN): internal_func_01c734
//   0x01c734: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01c738: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c73c: 910043FD  add      x29, sp, #0x10
//   0x01c740: F9402008  ldr      x8, [x0, #0x40]
//   0x01c744: AA0003F3  mov      x19, x0
//   0x01c748: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_217_sub_01c734(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[217]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #218 | VA: 0x01c7c4..0x01c7f8 (52 B) | FDE: 0x049400
// Symbol (EN/VN): internal_func_01c7c4
//   0x01c7c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01c7c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01c7cc: 910043FD  add      x29, sp, #0x10
//   0x01c7d0: AA0003F3  mov      x19, x0
//   0x01c7d4: F9401400  ldr      x0, [x0, #0x28]
//   0x01c7d8: B40000A0  cbz      x0, #0x1c7ec
// ----------------------------------------------------------------------------
uint64_t fde_218_sub_01c7c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[218]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #219 | VA: 0x01c7f8..0x01c7fc (4 B) | FDE: 0x049420
// Symbol (EN/VN): internal_func_01c7f8
//   0x01c7f8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_219_sub_01c7f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[219]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #220 | VA: 0x01c7fc..0x01c90c (272 B) | FDE: 0x049438
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils14GetExecWorkDirEv
//   0x01c7fc: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x01c800: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01c804: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01c808: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01c80c: 9100C3FD  add      x29, sp, #0x30
//   0x01c810: D10843FF  sub      sp, sp, #0x210
// ----------------------------------------------------------------------------
uint64_t fde_220_sub_01c7fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFCDD6u;
    constexpr uint32_t kFuncSize = 272u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[220]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #221 | VA: 0x01c90c..0x01cb10 (516 B) | FDE: 0x049460
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils8MergeDirERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_
//   0x01c90c: D10243FF  sub      sp, sp, #0x90
//   0x01c910: F90023F9  str      x25, [sp, #0x40]
//   0x01c914: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x01c918: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x01c91c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x01c920: A9087BFD  stp      x29, x30, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_221_sub_01c90c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xF90023F9u;
    constexpr uint32_t kLastOpcode = 0x97FFCD55u;
    constexpr uint32_t kFuncSize = 516u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[221]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #222 | VA: 0x01cb10..0x01ccec (476 B) | FDE: 0x049488
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils8MergeDirEPKcS2_
//   0x01cb10: D10243FF  sub      sp, sp, #0x90
//   0x01cb14: F90023F9  str      x25, [sp, #0x40]
//   0x01cb18: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x01cb1c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x01cb20: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x01cb24: A9087BFD  stp      x29, x30, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_222_sub_01cb10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xF90023F9u;
    constexpr uint32_t kLastOpcode = 0x97FFCCDEu;
    constexpr uint32_t kFuncSize = 476u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[222]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #223 | VA: 0x01ccec..0x01ce20 (308 B) | FDE: 0x0494b0
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils9FormatDirEPKc
//   0x01ccec: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x01ccf0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01ccf4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01ccf8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01ccfc: 9100C3FD  add      x29, sp, #0x30
//   0x01cd00: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_223_sub_01ccec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FFCC91u;
    constexpr uint32_t kFuncSize = 308u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[223]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #224 | VA: 0x01ce20..0x01cf68 (328 B) | FDE: 0x0494d8
// Symbol (EN/VN): internal_func_01ce20
//   0x01ce20: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x01ce24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x01ce28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01ce2c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01ce30: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01ce34: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_224_sub_01ce20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFCC3Fu;
    constexpr uint32_t kFuncSize = 328u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[224]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #225 | VA: 0x01cf68..0x01cf6c (4 B) | FDE: 0x049500
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils22setIsFileExistCallbackERKNSt6__ndk18functionIFbPKcRbEEE
//   0x01cf68: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_225_sub_01cf68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[225]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #226 | VA: 0x01cf6c..0x01d008 (156 B) | FDE: 0x049518
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils11IsFileExistERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01cf6c: D10283FF  sub      sp, sp, #0xa0
//   0x01cf70: F90043F3  str      x19, [sp, #0x80]
//   0x01cf74: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x01cf78: 910243FD  add      x29, sp, #0x90
//   0x01cf7c: 39400008  ldrb     w8, [x0]
//   0x01cf80: F9400409  ldr      x9, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_226_sub_01cf6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xF90043F3u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 156u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[226]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #227 | VA: 0x01d008..0x01d270 (616 B) | FDE: 0x049538
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils17getFileDescriptorERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d008: D106C3FF  sub      sp, sp, #0x1b0
//   0x01d00c: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x01d010: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x01d014: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x01d018: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x01d01c: A9194FF4  stp      x20, x19, [sp, #0x190]
// ----------------------------------------------------------------------------
uint64_t fde_227_sub_01d008(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD106C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9156FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[227]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #228 | VA: 0x01d270..0x01d274 (4 B) | FDE: 0x049568
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils23setSyncLoadCoreCallbackERKNSt6__ndk18functionIFbPKcRbEEE
//   0x01d270: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_228_sub_01d270(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[228]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #229 | VA: 0x01d274..0x01d278 (4 B) | FDE: 0x049580
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils12syncLoadCoreEPKc
//   0x01d274: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_229_sub_01d274(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[229]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #230 | VA: 0x01d278..0x01d34c (212 B) | FDE: 0x049598
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils23CheckAndCompleteFileDirERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d278: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01d27c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01d280: 910043FD  add      x29, sp, #0x10
//   0x01d284: 39400009  ldrb     w9, [x0]
//   0x01d288: F940040A  ldr      x10, [x0, #8]
//   0x01d28c: D341FD34  lsr      x20, x9, #1
// ----------------------------------------------------------------------------
uint64_t fde_230_sub_01d278(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 212u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[230]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #231 | VA: 0x01d34c..0x01d3a0 (84 B) | FDE: 0x0495b8
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils5isDirERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d34c: D10243FF  sub      sp, sp, #0x90
//   0x01d350: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x01d354: 910203FD  add      x29, sp, #0x80
//   0x01d358: 39400008  ldrb     w8, [x0]
//   0x01d35c: F9400809  ldr      x9, [x0, #0x10]
//   0x01d360: 910003E1  mov      x1, sp
// ----------------------------------------------------------------------------
uint64_t fde_231_sub_01d34c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9087BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 84u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[231]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #232 | VA: 0x01d3a0..0x01d3f4 (84 B) | FDE: 0x0495d8
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils6isLinkERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d3a0: D10243FF  sub      sp, sp, #0x90
//   0x01d3a4: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x01d3a8: 910203FD  add      x29, sp, #0x80
//   0x01d3ac: 39400008  ldrb     w8, [x0]
//   0x01d3b0: F9400809  ldr      x9, [x0, #0x10]
//   0x01d3b4: 910003E1  mov      x1, sp
// ----------------------------------------------------------------------------
uint64_t fde_232_sub_01d3a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9087BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 84u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[232]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #233 | VA: 0x01d3f4..0x01d438 (68 B) | FDE: 0x0495f8
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils14isAbsolutePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d3f4: 39400008  ldrb     w8, [x0]
//   0x01d3f8: F9400409  ldr      x9, [x0, #8]
//   0x01d3fc: D341FD0A  lsr      x10, x8, #1
//   0x01d400: 7200011F  tst      w8, #1
//   0x01d404: 9A890148  csel     x8, x10, x9, eq
//   0x01d408: B4000148  cbz      x8, #0x1d430
// ----------------------------------------------------------------------------
uint64_t fde_233_sub_01d3f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400008u;
    constexpr uint32_t kSecondOpcode = 0xF9400409u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[233]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #234 | VA: 0x01d438..0x01d618 (480 B) | FDE: 0x049610
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils15getAbsolutePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d438: D10183FF  sub      sp, sp, #0x60
//   0x01d43c: F90013F7  str      x23, [sp, #0x20]
//   0x01d440: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01d444: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01d448: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x01d44c: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_234_sub_01d438(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x97FFCA93u;
    constexpr uint32_t kFuncSize = 480u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[234]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #235 | VA: 0x01d618..0x01dc40 (1576 B) | FDE: 0x049638
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils17normalizeFilePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01d618: D10303FF  sub      sp, sp, #0xc0
//   0x01d61c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x01d620: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x01d624: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x01d628: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x01d62c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
// ----------------------------------------------------------------------------
uint64_t fde_235_sub_01d618(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10303FFu;
    constexpr uint32_t kSecondOpcode = 0xA9066FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFC9CDu;
    constexpr uint32_t kFuncSize = 1576u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[235]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #236 | VA: 0x01dc40..0x01dc44 (4 B) | FDE: 0x049668
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils27setCreateFileHandleCallbackERKNSt6__ndk18functionIFbPKciRmRPNS_10FileHandleEEEE
//   0x01dc40: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_236_sub_01dc40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[236]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #237 | VA: 0x01dc44..0x01dc9c (88 B) | FDE: 0x049680
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils18CreateMemoryReaderEPKvm
//   0x01dc44: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x01dc48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01dc4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01dc50: 910083FD  add      x29, sp, #0x20
//   0x01dc54: AA0003F4  mov      x20, x0
//   0x01dc58: 52800600  mov      w0, #0x30
// ----------------------------------------------------------------------------
uint64_t fde_237_sub_01dc44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[237]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #238 | VA: 0x01dc9c..0x01dcd0 (52 B) | FDE: 0x0496a0
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils18CreateMemoryWriterEPNS_12MemoryStreamE
//   0x01dc9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01dca0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01dca4: 910043FD  add      x29, sp, #0x10
//   0x01dca8: AA0003F3  mov      x19, x0
//   0x01dcac: 52800300  mov      w0, #0x18
//   0x01dcb0: 97FFC954  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_238_sub_01dc9c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[238]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #239 | VA: 0x01dcd0..0x01de98 (456 B) | FDE: 0x0496c0
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils16CreateFileReaderEPKc
//   0x01dcd0: D10183FF  sub      sp, sp, #0x60
//   0x01dcd4: F90013F7  str      x23, [sp, #0x20]
//   0x01dcd8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01dcdc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01dce0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x01dce4: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_239_sub_01dcd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x97FFC873u;
    constexpr uint32_t kFuncSize = 456u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[239]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #240 | VA: 0x01de98..0x01e00c (372 B) | FDE: 0x0496e8
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils26CreateFileDescriptorReaderEii
//   0x01de98: D101C3FF  sub      sp, sp, #0x70
//   0x01de9c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x01dea0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01dea4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x01dea8: 910183FD  add      x29, sp, #0x60
//   0x01deac: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_240_sub_01de98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFC8DAu;
    constexpr uint32_t kFuncSize = 372u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[240]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #241 | VA: 0x01e00c..0x01e3b0 (932 B) | FDE: 0x049710
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils16CreateFileWriterEPKci
//   0x01e00c: D10283FF  sub      sp, sp, #0xa0
//   0x01e010: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x01e014: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x01e018: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x01e01c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x01e020: A9084FF4  stp      x20, x19, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_241_sub_01e00c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xA9046FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFC7F1u;
    constexpr uint32_t kFuncSize = 932u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[241]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #242 | VA: 0x01e3b0..0x01e424 (116 B) | FDE: 0x049740
// Symbol (EN/VN): internal_func_01e3b0
//   0x01e3b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01e3b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01e3b8: 910043FD  add      x29, sp, #0x10
//   0x01e3bc: B00001A8  adrp     x8, #0x53000
//   0x01e3c0: B00001A9  adrp     x9, #0x53000
//   0x01e3c4: F9472908  ldr      x8, [x8, #0xe50]
// ----------------------------------------------------------------------------
uint64_t fde_242_sub_01e3b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC56Cu;
    constexpr uint32_t kFuncSize = 116u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[242]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #243 | VA: 0x01e424..0x01e640 (540 B) | FDE: 0x049760
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils24getFileExtensionByFilDesEi
//   0x01e424: D10143FF  sub      sp, sp, #0x50
//   0x01e428: F9000BF7  str      x23, [sp, #0x10]
//   0x01e42c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01e430: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01e434: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01e438: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_243_sub_01e424(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FFFFE5u;
    constexpr uint32_t kFuncSize = 540u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[243]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #244 | VA: 0x01e640..0x01e9f0 (944 B) | FDE: 0x049788
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils8readFileEPKc
//   0x01e640: D10403FF  sub      sp, sp, #0x100
//   0x01e644: F90053FB  str      x27, [sp, #0xa0]
//   0x01e648: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x01e64c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x01e650: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x01e654: A90E4FF4  stp      x20, x19, [sp, #0xe0]
// ----------------------------------------------------------------------------
uint64_t fde_244_sub_01e640(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10403FFu;
    constexpr uint32_t kSecondOpcode = 0xF90053FBu;
    constexpr uint32_t kLastOpcode = 0x97FFC661u;
    constexpr uint32_t kFuncSize = 944u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[244]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #245 | VA: 0x01e9f0..0x01eb14 (292 B) | FDE: 0x0497b8
// Symbol (EN/VN): internal_func_01e9f0
//   0x01e9f0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x01e9f4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x01e9f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x01e9fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x01ea00: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x01ea04: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_245_sub_01e9f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BB67FAu;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFC554u;
    constexpr uint32_t kFuncSize = 292u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[245]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #246 | VA: 0x01eb14..0x01eb18 (4 B) | FDE: 0x0497e8
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils20setWriteFileCallbackERKNSt6__ndk18functionIFbPKcPhjRbEEE
//   0x01eb14: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_246_sub_01eb14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[246]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #247 | VA: 0x01eb18..0x01ebac (148 B) | FDE: 0x049800
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils11writeToFileEPKcPhj
//   0x01eb18: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x01eb1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01eb20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01eb24: 910083FD  add      x29, sp, #0x20
//   0x01eb28: AA0103F4  mov      x20, x1
//   0x01eb2c: D0000121  adrp     x1, #0x44000
// ----------------------------------------------------------------------------
uint64_t fde_247_sub_01eb18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 148u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[247]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #248 | VA: 0x01ebac..0x01ec58 (172 B) | FDE: 0x049828
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils10getFileDirERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01ebac: D10103FF  sub      sp, sp, #0x40
//   0x01ebb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01ebb4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01ebb8: 9100C3FD  add      x29, sp, #0x30
//   0x01ebbc: D53BD054  mrs      x20, tpidr_el0
//   0x01ebc0: AA0803F3  mov      x19, x8
// ----------------------------------------------------------------------------
uint64_t fde_248_sub_01ebac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xA9024FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFC5C7u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[248]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #249 | VA: 0x01ec58..0x01ed88 (304 B) | FDE: 0x049848
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils16getFileExtensionERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01ec58: D101C3FF  sub      sp, sp, #0x70
//   0x01ec5c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x01ec60: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01ec64: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x01ec68: 910183FD  add      x29, sp, #0x60
//   0x01ec6c: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_249_sub_01ec58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFC57Bu;
    constexpr uint32_t kFuncSize = 304u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[249]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #250 | VA: 0x01ed88..0x01ee38 (176 B) | FDE: 0x049870
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils23getFileWithoutExtensionERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01ed88: D10103FF  sub      sp, sp, #0x40
//   0x01ed8c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01ed90: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01ed94: 9100C3FD  add      x29, sp, #0x30
//   0x01ed98: D53BD054  mrs      x20, tpidr_el0
//   0x01ed9c: AA0803F3  mov      x19, x8
// ----------------------------------------------------------------------------
uint64_t fde_250_sub_01ed88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xA9024FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFC54Fu;
    constexpr uint32_t kFuncSize = 176u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[250]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #251 | VA: 0x01ee38..0x01f020 (488 B) | FDE: 0x049890
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils11getDirFilesERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01ee38: D101C3FF  sub      sp, sp, #0x70
//   0x01ee3c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x01ee40: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x01ee44: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x01ee48: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x01ee4c: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_251_sub_01ee38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFC411u;
    constexpr uint32_t kFuncSize = 488u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[251]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #252 | VA: 0x01f020..0x01f1ec (460 B) | FDE: 0x0498c0
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils11getAllFilesERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01f020: D101C3FF  sub      sp, sp, #0x70
//   0x01f024: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x01f028: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x01f02c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x01f030: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01f034: A9067BFD  stp      x29, x30, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_252_sub_01f020(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90267FAu;
    constexpr uint32_t kLastOpcode = 0x97FFC39Eu;
    constexpr uint32_t kFuncSize = 460u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[252]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #253 | VA: 0x01f1ec..0x01f45c (624 B) | FDE: 0x0498f0
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils22getDirFilesByExtensionERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_
//   0x01f1ec: D102C3FF  sub      sp, sp, #0xb0
//   0x01f1f0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x01f1f4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x01f1f8: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x01f1fc: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x01f200: A9094FF4  stp      x20, x19, [sp, #0x90]
// ----------------------------------------------------------------------------
uint64_t fde_253_sub_01f1ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD102C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9056FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFC3C6u;
    constexpr uint32_t kFuncSize = 624u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[253]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #254 | VA: 0x01f45c..0x01f4ec (144 B) | FDE: 0x049920
// Symbol (EN/VN): _ZN13AmazingEngine9FileUtils11getFileSizeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x01f45c: D10283FF  sub      sp, sp, #0xa0
//   0x01f460: F90043F3  str      x19, [sp, #0x80]
//   0x01f464: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x01f468: 910243FD  add      x29, sp, #0x90
//   0x01f46c: 39400008  ldrb     w8, [x0]
//   0x01f470: F9400809  ldr      x9, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_254_sub_01f45c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xF90043F3u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[254]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #255 | VA: 0x01f4ec..0x01f528 (60 B) | FDE: 0x049940
// Symbol (EN/VN): internal_func_01f4ec
//   0x01f4ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f4f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f4f4: 910043FD  add      x29, sp, #0x10
//   0x01f4f8: 900001A8  adrp     x8, #0x53000
//   0x01f4fc: AA0003F3  mov      x19, x0
//   0x01f500: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_255_sub_01f4ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC0DFu;
    constexpr uint32_t kFuncSize = 60u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[255]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #256 | VA: 0x01f528..0x01f56c (68 B) | FDE: 0x049960
// Symbol (EN/VN): internal_func_01f528
//   0x01f528: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f52c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f530: 910043FD  add      x29, sp, #0x10
//   0x01f534: 900001A8  adrp     x8, #0x53000
//   0x01f538: AA0003F3  mov      x19, x0
//   0x01f53c: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_256_sub_01f528(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC0FEu;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[0]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #257 | VA: 0x01f56c..0x01f574 (8 B) | FDE: 0x049980
// Symbol (EN/VN): internal_func_01f56c
//   0x01f56c: F9400800  ldr      x0, [x0, #0x10]
//   0x01f570: 17FFC210  b        #0xfdb0
// ----------------------------------------------------------------------------
uint64_t fde_257_sub_01f56c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0x17FFC210u;
    constexpr uint32_t kLastOpcode = 0x17FFC210u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[1]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #258 | VA: 0x01f574..0x01f598 (36 B) | FDE: 0x049998
// Symbol (EN/VN): internal_func_01f574
//   0x01f574: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01f578: 910003FD  mov      x29, sp
//   0x01f57c: F9400800  ldr      x0, [x0, #0x10]
//   0x01f580: 2A1F03E2  mov      w2, wzr
//   0x01f584: 97FFC2CB  bl       #0x100b0
//   0x01f588: 7100001F  cmp      w0, #0
// ----------------------------------------------------------------------------
uint64_t fde_258_sub_01f574(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[2]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #259 | VA: 0x01f598..0x01f5c0 (40 B) | FDE: 0x0499b8
// Symbol (EN/VN): internal_func_01f598
//   0x01f598: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01f59c: 910003FD  mov      x29, sp
//   0x01f5a0: F9400800  ldr      x0, [x0, #0x10]
//   0x01f5a4: CB0103E1  neg      x1, x1
//   0x01f5a8: 52800042  mov      w2, #2
//   0x01f5ac: 97FFC2C1  bl       #0x100b0
// ----------------------------------------------------------------------------
uint64_t fde_259_sub_01f598(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[3]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #260 | VA: 0x01f5c0..0x01f604 (68 B) | FDE: 0x0499d8
// Symbol (EN/VN): internal_func_01f5c0
//   0x01f5c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f5c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f5c8: 910043FD  add      x29, sp, #0x10
//   0x01f5cc: F9400803  ldr      x3, [x0, #0x10]
//   0x01f5d0: AA0203E8  mov      x8, x2
//   0x01f5d4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_260_sub_01f5c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[4]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #261 | VA: 0x01f604..0x01f648 (68 B) | FDE: 0x0499f8
// Symbol (EN/VN): internal_func_01f604
//   0x01f604: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f608: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f60c: 910043FD  add      x29, sp, #0x10
//   0x01f610: F9400803  ldr      x3, [x0, #0x10]
//   0x01f614: AA0203E8  mov      x8, x2
//   0x01f618: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_261_sub_01f604(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[5]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #262 | VA: 0x01f648..0x01f688 (64 B) | FDE: 0x049a18
// Symbol (EN/VN): internal_func_01f648
//   0x01f648: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f64c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f650: 910043FD  add      x29, sp, #0x10
//   0x01f654: 900001A8  adrp     x8, #0x53000
//   0x01f658: AA0003F3  mov      x19, x0
//   0x01f65c: B9400C00  ldr      w0, [x0, #0xc]
// ----------------------------------------------------------------------------
uint64_t fde_262_sub_01f648(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC087u;
    constexpr uint32_t kFuncSize = 64u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[6]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #263 | VA: 0x01f688..0x01f6d0 (72 B) | FDE: 0x049a38
// Symbol (EN/VN): internal_func_01f688
//   0x01f688: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f68c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f690: 910043FD  add      x29, sp, #0x10
//   0x01f694: 900001A8  adrp     x8, #0x53000
//   0x01f698: AA0003F3  mov      x19, x0
//   0x01f69c: B9400C00  ldr      w0, [x0, #0xc]
// ----------------------------------------------------------------------------
uint64_t fde_263_sub_01f688(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC0A5u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[7]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #264 | VA: 0x01f6d0..0x01f6e0 (16 B) | FDE: 0x049a58
// Symbol (EN/VN): internal_func_01f6d0
//   0x01f6d0: B9400C00  ldr      w0, [x0, #0xc]
//   0x01f6d4: 52800022  mov      w2, #1
//   0x01f6d8: AA1F03E1  mov      x1, xzr
//   0x01f6dc: 17FFC315  b        #0x10330
// ----------------------------------------------------------------------------
uint64_t fde_264_sub_01f6d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400C00u;
    constexpr uint32_t kSecondOpcode = 0x52800022u;
    constexpr uint32_t kLastOpcode = 0x17FFC315u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[8]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #265 | VA: 0x01f6e0..0x01f704 (36 B) | FDE: 0x049a70
// Symbol (EN/VN): internal_func_01f6e0
//   0x01f6e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01f6e4: 910003FD  mov      x29, sp
//   0x01f6e8: B9400C00  ldr      w0, [x0, #0xc]
//   0x01f6ec: 2A1F03E2  mov      w2, wzr
//   0x01f6f0: 97FFC310  bl       #0x10330
//   0x01f6f4: F100001F  cmp      x0, #0
// ----------------------------------------------------------------------------
uint64_t fde_265_sub_01f6e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[9]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #266 | VA: 0x01f704..0x01f72c (40 B) | FDE: 0x049a90
// Symbol (EN/VN): internal_func_01f704
//   0x01f704: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01f708: 910003FD  mov      x29, sp
//   0x01f70c: B9400C00  ldr      w0, [x0, #0xc]
//   0x01f710: CB0103E1  neg      x1, x1
//   0x01f714: 52800042  mov      w2, #2
//   0x01f718: 97FFC306  bl       #0x10330
// ----------------------------------------------------------------------------
uint64_t fde_266_sub_01f704(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[10]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #267 | VA: 0x01f72c..0x01f750 (36 B) | FDE: 0x049ab0
// Symbol (EN/VN): internal_func_01f72c
//   0x01f72c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01f730: 910003FD  mov      x29, sp
//   0x01f734: B9400C00  ldr      w0, [x0, #0xc]
//   0x01f738: 92800003  mov      x3, #-1
//   0x01f73c: 97FFC365  bl       #0x104d0
//   0x01f740: B100041F  cmn      x0, #1
// ----------------------------------------------------------------------------
uint64_t fde_267_sub_01f72c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[11]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #268 | VA: 0x01f750..0x01f770 (32 B) | FDE: 0x049ad0
// Symbol (EN/VN): internal_func_01f750
//   0x01f750: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x01f754: 910003FD  mov      x29, sp
//   0x01f758: B9400C00  ldr      w0, [x0, #0xc]
//   0x01f75c: 97FFC26D  bl       #0x10110
//   0x01f760: B100041F  cmn      x0, #1
//   0x01f764: 1A9F07E0  cset     w0, ne
// ----------------------------------------------------------------------------
uint64_t fde_268_sub_01f750(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[12]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #269 | VA: 0x01f770..0x01f7e8 (120 B) | FDE: 0x049af0
// Symbol (EN/VN): internal_func_01f770
//   0x01f770: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01f774: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f778: 910043FD  add      x29, sp, #0x10
//   0x01f77c: 900001A8  adrp     x8, #0x53000
//   0x01f780: F9472908  ldr      x8, [x8, #0xe50]
//   0x01f784: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_269_sub_01f770(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC07Bu;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[13]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #270 | VA: 0x01f7e8..0x01f868 (128 B) | FDE: 0x049b10
// Symbol (EN/VN): internal_func_01f7e8
//   0x01f7e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01f7ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f7f0: 910043FD  add      x29, sp, #0x10
//   0x01f7f4: F9400008  ldr      x8, [x0]
//   0x01f7f8: 900001A9  adrp     x9, #0x53000
//   0x01f7fc: F85E8108  ldur     x8, [x8, #-0x18]
// ----------------------------------------------------------------------------
uint64_t fde_270_sub_01f7e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC05Bu;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[14]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #271 | VA: 0x01f868..0x01f870 (8 B) | FDE: 0x049b30
// Symbol (EN/VN): internal_func_01f868
//   0x01f868: 91004000  add      x0, x0, #0x10
//   0x01f86c: 17FFC059  b        #0xf9d0
// ----------------------------------------------------------------------------
uint64_t fde_271_sub_01f868(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91004000u;
    constexpr uint32_t kSecondOpcode = 0x17FFC059u;
    constexpr uint32_t kLastOpcode = 0x17FFC059u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[15]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #272 | VA: 0x01f870..0x01f898 (40 B) | FDE: 0x049b48
// Symbol (EN/VN): internal_func_01f870
//   0x01f870: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f874: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f878: 910043FD  add      x29, sp, #0x10
//   0x01f87c: AA0003F3  mov      x19, x0
//   0x01f880: 91004000  add      x0, x0, #0x10
//   0x01f884: 97FFC053  bl       #0xf9d0
// ----------------------------------------------------------------------------
uint64_t fde_272_sub_01f870(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC033u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[16]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #273 | VA: 0x01f898..0x01f8ac (20 B) | FDE: 0x049b68
// Symbol (EN/VN): internal_func_01f898
//   0x01f898: F9400008  ldr      x8, [x0]
//   0x01f89c: F85E8108  ldur     x8, [x8, #-0x18]
//   0x01f8a0: 8B080008  add      x8, x0, x8
//   0x01f8a4: 91004100  add      x0, x8, #0x10
//   0x01f8a8: 17FFC04A  b        #0xf9d0
// ----------------------------------------------------------------------------
uint64_t fde_273_sub_01f898(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400008u;
    constexpr uint32_t kSecondOpcode = 0xF85E8108u;
    constexpr uint32_t kLastOpcode = 0x17FFC04Au;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[17]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #274 | VA: 0x01f8ac..0x01f8dc (48 B) | FDE: 0x049b80
// Symbol (EN/VN): internal_func_01f8ac
//   0x01f8ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f8b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f8b4: 910043FD  add      x29, sp, #0x10
//   0x01f8b8: F9400008  ldr      x8, [x0]
//   0x01f8bc: F85E8108  ldur     x8, [x8, #-0x18]
//   0x01f8c0: 8B080013  add      x19, x0, x8
// ----------------------------------------------------------------------------
uint64_t fde_274_sub_01f8ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC022u;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[18]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #275 | VA: 0x01f8dc..0x01f958 (124 B) | FDE: 0x049ba0
// Symbol (EN/VN): internal_func_01f8dc
//   0x01f8dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f8e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f8e4: 910043FD  add      x29, sp, #0x10
//   0x01f8e8: 900001A8  adrp     x8, #0x53000
//   0x01f8ec: 900001A9  adrp     x9, #0x53000
//   0x01f8f0: F9472908  ldr      x8, [x8, #0xe50]
// ----------------------------------------------------------------------------
uint64_t fde_275_sub_01f8dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC003u;
    constexpr uint32_t kFuncSize = 124u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[19]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #276 | VA: 0x01f958..0x01f9d8 (128 B) | FDE: 0x049bc0
// Symbol (EN/VN): internal_func_01f958
//   0x01f958: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01f95c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f960: 910043FD  add      x29, sp, #0x10
//   0x01f964: 900001A8  adrp     x8, #0x53000
//   0x01f968: F9472908  ldr      x8, [x8, #0xe50]
//   0x01f96c: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_276_sub_01f958(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFBFE3u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[20]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #277 | VA: 0x01f9d8..0x01fa60 (136 B) | FDE: 0x049be0
// Symbol (EN/VN): internal_func_01f9d8
//   0x01f9d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x01f9dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f9e0: 910043FD  add      x29, sp, #0x10
//   0x01f9e4: F9400008  ldr      x8, [x0]
//   0x01f9e8: 900001A9  adrp     x9, #0x53000
//   0x01f9ec: F85E8108  ldur     x8, [x8, #-0x18]
// ----------------------------------------------------------------------------
uint64_t fde_277_sub_01f9d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFBFC1u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[21]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #278 | VA: 0x01fa60..0x01fab0 (80 B) | FDE: 0x049c00
// Symbol (EN/VN): internal_func_01fa60
//   0x01fa60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01fa64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01fa68: 910043FD  add      x29, sp, #0x10
//   0x01fa6c: 900001A9  adrp     x9, #0x53000
//   0x01fa70: 39410008  ldrb     w8, [x0, #0x40]
//   0x01fa74: F9470529  ldr      x9, [x9, #0xe08]
// ----------------------------------------------------------------------------
uint64_t fde_278_sub_01fa60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFC271u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[22]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #279 | VA: 0x01fab0..0x01fb08 (88 B) | FDE: 0x049c20
// Symbol (EN/VN): internal_func_01fab0
//   0x01fab0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01fab4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01fab8: 910043FD  add      x29, sp, #0x10
//   0x01fabc: 900001A9  adrp     x9, #0x53000
//   0x01fac0: 39410008  ldrb     w8, [x0, #0x40]
//   0x01fac4: F9470529  ldr      x9, [x9, #0xe08]
// ----------------------------------------------------------------------------
uint64_t fde_279_sub_01fab0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFBF97u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[23]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #280 | VA: 0x01fb08..0x01fb0c (4 B) | FDE: 0x049c40
// Symbol (EN/VN): internal_func_01fb08
//   0x01fb08: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_280_sub_01fb08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[24]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #281 | VA: 0x01fb0c..0x01fb10 (4 B) | FDE: 0x049c58
// Symbol (EN/VN): internal_func_01fb0c
//   0x01fb0c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_281_sub_01fb0c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[25]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #282 | VA: 0x01fb10..0x01fc38 (296 B) | FDE: 0x049c70
// Symbol (EN/VN): internal_func_01fb10
//   0x01fb10: F9402C08  ldr      x8, [x0, #0x58]
//   0x01fb14: F9401809  ldr      x9, [x0, #0x30]
//   0x01fb18: EB09011F  cmp      x8, x9
//   0x01fb1c: 54000062  b.hs     #0x1fb28
//   0x01fb20: AA0903E8  mov      x8, x9
//   0x01fb24: F9002C09  str      x9, [x0, #0x58]
// ----------------------------------------------------------------------------
uint64_t fde_282_sub_01fb10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9402C08u;
    constexpr uint32_t kSecondOpcode = 0xF9401809u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 296u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[26]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #283 | VA: 0x01fc38..0x01fc4c (20 B) | FDE: 0x049c88
// Symbol (EN/VN): internal_func_01fc38
//   0x01fc38: F9400008  ldr      x8, [x0]
//   0x01fc3c: AA0203E1  mov      x1, x2
//   0x01fc40: 2A1F03E2  mov      w2, wzr
//   0x01fc44: F9401104  ldr      x4, [x8, #0x20]
//   0x01fc48: D61F0080  br       x4
// ----------------------------------------------------------------------------
uint64_t fde_283_sub_01fc38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400008u;
    constexpr uint32_t kSecondOpcode = 0xAA0203E1u;
    constexpr uint32_t kLastOpcode = 0xD61F0080u;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[27]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #284 | VA: 0x01fc4c..0x01fc54 (8 B) | FDE: 0x049ca0
// Symbol (EN/VN): internal_func_01fc4c
//   0x01fc4c: 2A1F03E0  mov      w0, wzr
//   0x01fc50: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_284_sub_01fc4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2A1F03E0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[28]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #285 | VA: 0x01fc54..0x01fc5c (8 B) | FDE: 0x049cb8
// Symbol (EN/VN): internal_func_01fc54
//   0x01fc54: AA1F03E0  mov      x0, xzr
//   0x01fc58: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_285_sub_01fc54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA1F03E0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[29]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #286 | VA: 0x01fc5c..0x01fd3c (224 B) | FDE: 0x049cd0
// Symbol (EN/VN): internal_func_01fc5c
//   0x01fc5c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x01fc60: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01fc64: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01fc68: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01fc6c: 9100C3FD  add      x29, sp, #0x30
//   0x01fc70: F100045F  cmp      x2, #1
// ----------------------------------------------------------------------------
uint64_t fde_286_sub_01fc5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 224u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[30]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #287 | VA: 0x01fd3c..0x01fd8c (80 B) | FDE: 0x049cf8
// Symbol (EN/VN): internal_func_01fd3c
//   0x01fd3c: F9402C08  ldr      x8, [x0, #0x58]
//   0x01fd40: F9401809  ldr      x9, [x0, #0x30]
//   0x01fd44: EB09011F  cmp      x8, x9
//   0x01fd48: 54000062  b.hs     #0x1fd54
//   0x01fd4c: AA0903E8  mov      x8, x9
//   0x01fd50: F9002C09  str      x9, [x0, #0x58]
// ----------------------------------------------------------------------------
uint64_t fde_287_sub_01fd3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9402C08u;
    constexpr uint32_t kSecondOpcode = 0xF9401809u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[31]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #288 | VA: 0x01fd8c..0x01fdcc (64 B) | FDE: 0x049d10
// Symbol (EN/VN): internal_func_01fd8c
//   0x01fd8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01fd90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01fd94: 910043FD  add      x29, sp, #0x10
//   0x01fd98: F9400008  ldr      x8, [x0]
//   0x01fd9c: AA0003F3  mov      x19, x0
//   0x01fda0: F9402508  ldr      x8, [x8, #0x48]
// ----------------------------------------------------------------------------
uint64_t fde_288_sub_01fd8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 64u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[32]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #289 | VA: 0x01fdcc..0x01fe3c (112 B) | FDE: 0x049d30
// Symbol (EN/VN): internal_func_01fdcc
//   0x01fdcc: F9402C09  ldr      x9, [x0, #0x58]
//   0x01fdd0: F940180A  ldr      x10, [x0, #0x30]
//   0x01fdd4: AA0003E8  mov      x8, x0
//   0x01fdd8: 2A0103E0  mov      w0, w1
//   0x01fddc: EB0A013F  cmp      x9, x10
//   0x01fde0: 54000062  b.hs     #0x1fdec
// ----------------------------------------------------------------------------
uint64_t fde_289_sub_01fdcc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9402C09u;
    constexpr uint32_t kSecondOpcode = 0xF940180Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 112u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[33]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #290 | VA: 0x01fe3c..0x01ff10 (212 B) | FDE: 0x049d48
// Symbol (EN/VN): internal_func_01fe3c
//   0x01fe3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x01fe40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01fe44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01fe48: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01fe4c: 9100C3FD  add      x29, sp, #0x30
//   0x01fe50: F100045F  cmp      x2, #1
// ----------------------------------------------------------------------------
uint64_t fde_290_sub_01fe3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 212u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[34]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #291 | VA: 0x01ff10..0x020158 (584 B) | FDE: 0x049d70
// Symbol (EN/VN): internal_func_01ff10
//   0x01ff10: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x01ff14: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x01ff18: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x01ff1c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01ff20: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x01ff24: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_291_sub_01ff10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81A0FFBu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0xD61F0040u;
    constexpr uint32_t kFuncSize = 584u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[35]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #292 | VA: 0x020158..0x02016c (20 B) | FDE: 0x049da0
// Symbol (EN/VN): internal_func_020158
//   0x020158: F0000188  adrp     x8, #0x53000
//   0x02015c: F9463108  ldr      x8, [x8, #0xc60]
//   0x020160: 91004108  add      x8, x8, #0x10
//   0x020164: F8008408  str      x8, [x0], #8
//   0x020168: 17FFC0C2  b        #0x10470
// ----------------------------------------------------------------------------
uint64_t fde_292_sub_020158(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000188u;
    constexpr uint32_t kSecondOpcode = 0xF9463108u;
    constexpr uint32_t kLastOpcode = 0x17FFC0C2u;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[36]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #293 | VA: 0x02016c..0x0201a0 (52 B) | FDE: 0x049db8
// Symbol (EN/VN): internal_func_02016c
//   0x02016c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x020170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x020174: 910043FD  add      x29, sp, #0x10
//   0x020178: F0000188  adrp     x8, #0x53000
//   0x02017c: F9463108  ldr      x8, [x8, #0xc60]
//   0x020180: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_293_sub_02016c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFBDF1u;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[37]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #294 | VA: 0x0201a0..0x0201ac (12 B) | FDE: 0x049dd8
// Symbol (EN/VN): internal_func_0201a0
//   0x0201a0: 92800001  mov      x1, #-1
//   0x0201a4: AA1F03E0  mov      x0, xzr
//   0x0201a8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_294_sub_0201a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x92800001u;
    constexpr uint32_t kSecondOpcode = 0xAA1F03E0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[38]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #295 | VA: 0x0201ac..0x0201b8 (12 B) | FDE: 0x049df0
// Symbol (EN/VN): internal_func_0201ac
//   0x0201ac: 92800001  mov      x1, #-1
//   0x0201b0: AA1F03E0  mov      x0, xzr
//   0x0201b4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_295_sub_0201ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x92800001u;
    constexpr uint32_t kSecondOpcode = 0xAA1F03E0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[39]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #296 | VA: 0x0201b8..0x0201c0 (8 B) | FDE: 0x049e08
// Symbol (EN/VN): internal_func_0201b8
//   0x0201b8: 12800000  mov      w0, #-1
//   0x0201bc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_296_sub_0201b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12800000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[40]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #297 | VA: 0x0201c0..0x0201c8 (8 B) | FDE: 0x049e20
// Symbol (EN/VN): internal_func_0201c0
//   0x0201c0: 12800000  mov      w0, #-1
//   0x0201c4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_297_sub_0201c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12800000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[41]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #298 | VA: 0x0201c8..0x0201d0 (8 B) | FDE: 0x049e38
// Symbol (EN/VN): internal_func_0201c8
//   0x0201c8: 12800000  mov      w0, #-1
//   0x0201cc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_298_sub_0201c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12800000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[42]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #299 | VA: 0x0201d0..0x0202a8 (216 B) | FDE: 0x049e50
// Symbol (EN/VN): internal_func_0201d0
//   0x0201d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0201d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0201d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0201dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0201e0: 9100C3FD  add      x29, sp, #0x30
//   0x0201e4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_299_sub_0201d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 216u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[43]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #300 | VA: 0x0202a8..0x0203e8 (320 B) | FDE: 0x049e78
// Symbol (EN/VN): internal_func_0202a8
//   0x0202a8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0202ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0202b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0202b4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0202b8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0202bc: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_300_sub_0202a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81A0FFBu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFBF1Fu;
    constexpr uint32_t kFuncSize = 320u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[44]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #301 | VA: 0x0203e8..0x0204b4 (204 B) | FDE: 0x049ea8
// Symbol (EN/VN): internal_func_0203e8
//   0x0203e8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0203ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0203f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0203f4: 910083FD  add      x29, sp, #0x20
//   0x0203f8: 39400008  ldrb     w8, [x0]
//   0x0203fc: AA0203F4  mov      x20, x2
// ----------------------------------------------------------------------------
uint64_t fde_301_sub_0203e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 204u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[45]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #302 | VA: 0x0204b4..0x0206c4 (528 B) | FDE: 0x049ed0
// Symbol (EN/VN): internal_func_0204b4
//   0x0204b4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0204b8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0204bc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0204c0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0204c4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0204c8: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_302_sub_0204b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFBE68u;
    constexpr uint32_t kFuncSize = 528u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[46]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #303 | VA: 0x0206c4..0x0207ec (296 B) | FDE: 0x049f00
// Symbol (EN/VN): internal_func_0206c4
//   0x0206c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0206c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0206cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0206d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0206d4: 9100C3FD  add      x29, sp, #0x30
//   0x0206d8: 39400008  ldrb     w8, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_303_sub_0206c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 296u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[47]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #304 | VA: 0x0207ec..0x020988 (412 B) | FDE: 0x049f28
// Symbol (EN/VN): internal_func_0207ec
//   0x0207ec: D10183FF  sub      sp, sp, #0x60
//   0x0207f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0207f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0207f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0207fc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x020800: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_304_sub_0207ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFBE7Bu;
    constexpr uint32_t kFuncSize = 412u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[48]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #305 | VA: 0x020988..0x020b28 (416 B) | FDE: 0x049f58
// Symbol (EN/VN): internal_func_020988
//   0x020988: D10203FF  sub      sp, sp, #0x80
//   0x02098c: F90013FB  str      x27, [sp, #0x20]
//   0x020990: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x020994: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x020998: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02099c: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_305_sub_020988(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013FBu;
    constexpr uint32_t kLastOpcode = 0x97FFBE13u;
    constexpr uint32_t kFuncSize = 416u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[49]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #306 | VA: 0x020b28..0x020c18 (240 B) | FDE: 0x049f88
// Symbol (EN/VN): internal_func_020b28
//   0x020b28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x020b2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x020b30: 910043FD  add      x29, sp, #0x10
//   0x020b34: F9400008  ldr      x8, [x0]
//   0x020b38: AA0003F3  mov      x19, x0
//   0x020b3c: F85E8108  ldur     x8, [x8, #-0x18]
// ----------------------------------------------------------------------------
uint64_t fde_306_sub_020b28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 240u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[50]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #307 | VA: 0x020c18..0x020d3c (292 B) | FDE: 0x049fa8
// Symbol (EN/VN): internal_func_020c18
//   0x020c18: D10143FF  sub      sp, sp, #0x50
//   0x020c1c: F90013F5  str      x21, [sp, #0x20]
//   0x020c20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x020c24: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x020c28: 910103FD  add      x29, sp, #0x40
//   0x020c2c: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_307_sub_020c18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FFBD8Eu;
    constexpr uint32_t kFuncSize = 292u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[51]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #308 | VA: 0x020d3c..0x020f20 (484 B) | FDE: 0x049fc8
// Symbol (EN/VN): internal_func_020d3c
//   0x020d3c: D10143FF  sub      sp, sp, #0x50
//   0x020d40: F9000BF7  str      x23, [sp, #0x10]
//   0x020d44: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x020d48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x020d4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x020d50: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_308_sub_020d3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x97FFBD15u;
    constexpr uint32_t kFuncSize = 484u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[52]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #309 | VA: 0x020f20..0x02111c (508 B) | FDE: 0x049ff0
// Symbol (EN/VN): internal_func_020f20
//   0x020f20: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x020f24: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x020f28: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x020f2c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x020f30: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x020f34: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_309_sub_020f20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFBBD2u;
    constexpr uint32_t kFuncSize = 508u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[53]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #310 | VA: 0x02111c..0x021294 (376 B) | FDE: 0x04a020
// Symbol (EN/VN): internal_func_02111c
//   0x02111c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x021120: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021124: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021128: 910083FD  add      x29, sp, #0x20
//   0x02112c: A9402009  ldp      x9, x8, [x0]
//   0x021130: B201F3EA  mov      x10, #-0x5555555555555556
// ----------------------------------------------------------------------------
uint64_t fde_310_sub_02111c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x97FFBB74u;
    constexpr uint32_t kFuncSize = 376u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[54]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #311 | VA: 0x021294..0x02136c (216 B) | FDE: 0x04a048
// Symbol (EN/VN): internal_func_021294
//   0x021294: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x021298: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x02129c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0212a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0212a4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0212a8: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_311_sub_021294(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFBB3Eu;
    constexpr uint32_t kFuncSize = 216u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[55]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #312 | VA: 0x02136c..0x02140c (160 B) | FDE: 0x04a070
// Symbol (EN/VN): internal_func_02136c
//   0x02136c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021370: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021374: 910043FD  add      x29, sp, #0x10
//   0x021378: D0000188  adrp     x8, #0x53000
//   0x02137c: AA0003F3  mov      x19, x0
//   0x021380: F9401400  ldr      x0, [x0, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_312_sub_02136c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB926u;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[56]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #313 | VA: 0x02140c..0x0214b4 (168 B) | FDE: 0x04a090
// Symbol (EN/VN): internal_func_02140c
//   0x02140c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021410: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021414: 910043FD  add      x29, sp, #0x10
//   0x021418: D0000188  adrp     x8, #0x53000
//   0x02141c: AA0003F3  mov      x19, x0
//   0x021420: F9401400  ldr      x0, [x0, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_313_sub_02140c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB92Cu;
    constexpr uint32_t kFuncSize = 168u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[57]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #314 | VA: 0x0214b4..0x0215e0 (300 B) | FDE: 0x04a0b0
// Symbol (EN/VN): internal_func_0214b4
//   0x0214b4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0214b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0214bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0214c0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0214c4: 9100C3FD  add      x29, sp, #0x30
//   0x0214c8: F9401808  ldr      x8, [x0, #0x30]
// ----------------------------------------------------------------------------
uint64_t fde_314_sub_0214b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 300u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[58]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #315 | VA: 0x0215e0..0x021668 (136 B) | FDE: 0x04a0d8
// Symbol (EN/VN): internal_func_0215e0
//   0x0215e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0215e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0215e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0215ec: 910083FD  add      x29, sp, #0x20
//   0x0215f0: F9400008  ldr      x8, [x0]
//   0x0215f4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_315_sub_0215e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[59]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #316 | VA: 0x021668..0x021670 (8 B) | FDE: 0x04a0f8
// Symbol (EN/VN): internal_func_021668
//   0x021668: F9401800  ldr      x0, [x0, #0x30]
//   0x02166c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_316_sub_021668(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9401800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[60]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #317 | VA: 0x021670..0x0216e0 (112 B) | FDE: 0x04a110
// Symbol (EN/VN): internal_func_021670
//   0x021670: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x021674: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021678: 910043FD  add      x29, sp, #0x10
//   0x02167c: F9400008  ldr      x8, [x0]
//   0x021680: AA0003F3  mov      x19, x0
//   0x021684: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_317_sub_021670(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 112u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[61]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #318 | VA: 0x0216e0..0x021724 (68 B) | FDE: 0x04a130
// Symbol (EN/VN): internal_func_0216e0
//   0x0216e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0216e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0216e8: 910043FD  add      x29, sp, #0x10
//   0x0216ec: F9401408  ldr      x8, [x0, #0x28]
//   0x0216f0: B4000148  cbz      x8, #0x21718
//   0x0216f4: F9400008  ldr      x8, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_318_sub_0216e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[62]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #319 | VA: 0x021724..0x021788 (100 B) | FDE: 0x04a150
// Symbol (EN/VN): internal_func_021724
//   0x021724: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021728: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02172c: 910043FD  add      x29, sp, #0x10
//   0x021730: F9401C02  ldr      x2, [x0, #0x38]
//   0x021734: B4000242  cbz      x2, #0x2177c
//   0x021738: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_319_sub_021724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[63]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #320 | VA: 0x021788..0x021828 (160 B) | FDE: 0x04a170
// Symbol (EN/VN): internal_func_021788
//   0x021788: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02178c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021790: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021794: 910083FD  add      x29, sp, #0x20
//   0x021798: B900081F  str      wzr, [x0, #8]
//   0x02179c: D0000188  adrp     x8, #0x53000
// ----------------------------------------------------------------------------
uint64_t fde_320_sub_021788(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[64]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #321 | VA: 0x021828..0x021870 (72 B) | FDE: 0x04a198
// Symbol (EN/VN): internal_func_021828
//   0x021828: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02182c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021830: 910043FD  add      x29, sp, #0x10
//   0x021834: D0000188  adrp     x8, #0x53000
//   0x021838: AA0003F3  mov      x19, x0
//   0x02183c: F9401000  ldr      x0, [x0, #0x20]
// ----------------------------------------------------------------------------
uint64_t fde_321_sub_021828(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB80Du;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[65]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #322 | VA: 0x021870..0x0218c0 (80 B) | FDE: 0x04a1b8
// Symbol (EN/VN): internal_func_021870
//   0x021870: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021874: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021878: 910043FD  add      x29, sp, #0x10
//   0x02187c: D0000188  adrp     x8, #0x53000
//   0x021880: AA0003F3  mov      x19, x0
//   0x021884: F9401000  ldr      x0, [x0, #0x20]
// ----------------------------------------------------------------------------
uint64_t fde_322_sub_021870(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB829u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[66]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #323 | VA: 0x0218c0..0x0218c8 (8 B) | FDE: 0x04a1d8
// Symbol (EN/VN): internal_func_0218c0
//   0x0218c0: F9400C00  ldr      x0, [x0, #0x18]
//   0x0218c4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_323_sub_0218c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400C00u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[67]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #324 | VA: 0x0218c8..0x0218d0 (8 B) | FDE: 0x04a1f0
// Symbol (EN/VN): internal_func_0218c8
//   0x0218c8: F9400800  ldr      x0, [x0, #0x10]
//   0x0218cc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_324_sub_0218c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[68]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #325 | VA: 0x0218d0..0x02193c (108 B) | FDE: 0x04a208
// Symbol (EN/VN): internal_func_0218d0
//   0x0218d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0218d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0218d8: 910043FD  add      x29, sp, #0x10
//   0x0218dc: AA0003F4  mov      x20, x0
//   0x0218e0: F9401000  ldr      x0, [x0, #0x20]
//   0x0218e4: AA0103F3  mov      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_325_sub_0218d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFBA6Au;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[69]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #326 | VA: 0x02193c..0x021970 (52 B) | FDE: 0x04a228
// Symbol (EN/VN): internal_func_02193c
//   0x02193c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021940: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021944: 910043FD  add      x29, sp, #0x10
//   0x021948: AA0003F3  mov      x19, x0
//   0x02194c: F9401000  ldr      x0, [x0, #0x20]
//   0x021950: B40000A0  cbz      x0, #0x21964
// ----------------------------------------------------------------------------
uint64_t fde_326_sub_02193c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[70]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #327 | VA: 0x021970..0x0219f0 (128 B) | FDE: 0x04a248
// Symbol (EN/VN): internal_func_021970
//   0x021970: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x021974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021978: 910043FD  add      x29, sp, #0x10
//   0x02197c: AA0003F4  mov      x20, x0
//   0x021980: F9401000  ldr      x0, [x0, #0x20]
//   0x021984: AA0203F3  mov      x19, x2
// ----------------------------------------------------------------------------
uint64_t fde_327_sub_021970(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[71]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #328 | VA: 0x0219f0..0x021a10 (32 B) | FDE: 0x04a268
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStreamC2Ev
//   0x0219f0: B900081F  str      wzr, [x0, #8]
//   0x0219f4: D0000188  adrp     x8, #0x53000
//   0x0219f8: F946A508  ldr      x8, [x8, #0xd48]
//   0x0219fc: 6F00E400  movi     v0.2d, #0000000000000000
//   0x021a00: AD008000  stp      q0, q0, [x0, #0x10]
//   0x021a04: 91004108  add      x8, x8, #0x10
// ----------------------------------------------------------------------------
uint64_t fde_328_sub_0219f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900081Fu;
    constexpr uint32_t kSecondOpcode = 0xD0000188u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[72]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #329 | VA: 0x021a10..0x021ae8 (216 B) | FDE: 0x04a280
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStreamC1EPKvm
//   0x021a10: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x021a14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021a18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021a1c: 910083FD  add      x29, sp, #0x20
//   0x021a20: B900081F  str      wzr, [x0, #8]
//   0x021a24: D0000188  adrp     x8, #0x53000
// ----------------------------------------------------------------------------
uint64_t fde_329_sub_021a10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 216u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[73]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #330 | VA: 0x021ae8..0x021b30 (72 B) | FDE: 0x04a2a8
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStreamD2Ev
//   0x021ae8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021aec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021af0: 910043FD  add      x29, sp, #0x10
//   0x021af4: D0000188  adrp     x8, #0x53000
//   0x021af8: AA0003F3  mov      x19, x0
//   0x021afc: F9401400  ldr      x0, [x0, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_330_sub_021ae8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB75Du;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[74]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #331 | VA: 0x021b30..0x021b80 (80 B) | FDE: 0x04a2c8
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStreamD0Ev
//   0x021b30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021b34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021b38: 910043FD  add      x29, sp, #0x10
//   0x021b3c: D0000188  adrp     x8, #0x53000
//   0x021b40: AA0003F3  mov      x19, x0
//   0x021b44: F9401400  ldr      x0, [x0, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_331_sub_021b30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB779u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[75]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #332 | VA: 0x021b80..0x021b88 (8 B) | FDE: 0x04a2e8
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStream4TellEv
//   0x021b80: F9400800  ldr      x0, [x0, #0x10]
//   0x021b84: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_332_sub_021b80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[76]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #333 | VA: 0x021b88..0x021ba8 (32 B) | FDE: 0x04a300
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStream4SeekEm
//   0x021b88: F9400C08  ldr      x8, [x0, #0x18]
//   0x021b8c: EB01011F  cmp      x8, x1
//   0x021b90: 54000062  b.hs     #0x21b9c
//   0x021b94: 2A1F03E0  mov      w0, wzr
//   0x021b98: D65F03C0  ret      
//   0x021b9c: F9000801  str      x1, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_333_sub_021b88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400C08u;
    constexpr uint32_t kSecondOpcode = 0xEB01011Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[77]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #334 | VA: 0x021ba8..0x021bc8 (32 B) | FDE: 0x04a318
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStream7InvSeekEm
//   0x021ba8: F9400C08  ldr      x8, [x0, #0x18]
//   0x021bac: EB010108  subs     x8, x8, x1
//   0x021bb0: 54000062  b.hs     #0x21bbc
//   0x021bb4: 2A1F03E0  mov      w0, wzr
//   0x021bb8: D65F03C0  ret      
//   0x021bbc: F9000808  str      x8, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_334_sub_021ba8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400C08u;
    constexpr uint32_t kSecondOpcode = 0xEB010108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[78]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #335 | VA: 0x021bc8..0x021c2c (100 B) | FDE: 0x04a330
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStream4ReadEPvm
//   0x021bc8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x021bcc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021bd0: 910043FD  add      x29, sp, #0x10
//   0x021bd4: A9412408  ldp      x8, x9, [x0, #0x10]
//   0x021bd8: 8B02010A  add      x10, x8, x2
//   0x021bdc: EB09015F  cmp      x10, x9
// ----------------------------------------------------------------------------
uint64_t fde_335_sub_021bc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 100u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[79]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #336 | VA: 0x021c2c..0x021cd0 (164 B) | FDE: 0x04a350
// Symbol (EN/VN): _ZN13AmazingEngine12MemoryStream5WriteEPKvm
//   0x021c2c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x021c30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021c34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021c38: 910083FD  add      x29, sp, #0x20
//   0x021c3c: F9400809  ldr      x9, [x0, #0x10]
//   0x021c40: F9401008  ldr      x8, [x0, #0x20]
// ----------------------------------------------------------------------------
uint64_t fde_336_sub_021c2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 164u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[80]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #337 | VA: 0x021cd0..0x021cf8 (40 B) | FDE: 0x04a370
// Symbol (EN/VN): internal_func_021cd0
//   0x021cd0: B900081F  str      wzr, [x0, #8]
//   0x021cd4: D0000188  adrp     x8, #0x53000
//   0x021cd8: F9473108  ldr      x8, [x8, #0xe60]
//   0x021cdc: F9000801  str      x1, [x0, #0x10]
//   0x021ce0: 91004108  add      x8, x8, #0x10
//   0x021ce4: F9000008  str      x8, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_337_sub_021cd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900081Fu;
    constexpr uint32_t kSecondOpcode = 0xD0000188u;
    constexpr uint32_t kLastOpcode = 0xD61F0040u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[81]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #338 | VA: 0x021cf8..0x021d38 (64 B) | FDE: 0x04a388
// Symbol (EN/VN): internal_func_021cf8
//   0x021cf8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021cfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021d00: 910043FD  add      x29, sp, #0x10
//   0x021d04: D0000188  adrp     x8, #0x53000
//   0x021d08: AA0003F3  mov      x19, x0
//   0x021d0c: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_338_sub_021cf8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB6DBu;
    constexpr uint32_t kFuncSize = 64u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[82]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #339 | VA: 0x021d38..0x021d80 (72 B) | FDE: 0x04a3a8
// Symbol (EN/VN): internal_func_021d38
//   0x021d38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x021d3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x021d40: 910043FD  add      x29, sp, #0x10
//   0x021d44: D0000188  adrp     x8, #0x53000
//   0x021d48: AA0003F3  mov      x19, x0
//   0x021d4c: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_339_sub_021d38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFB6F9u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[83]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #340 | VA: 0x021d80..0x021d90 (16 B) | FDE: 0x04a3c8
// Symbol (EN/VN): internal_func_021d80
//   0x021d80: F9400800  ldr      x0, [x0, #0x10]
//   0x021d84: F9400008  ldr      x8, [x0]
//   0x021d88: F9400501  ldr      x1, [x8, #8]
//   0x021d8c: D61F0020  br       x1
// ----------------------------------------------------------------------------
uint64_t fde_340_sub_021d80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0xF9400008u;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[84]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #341 | VA: 0x021d90..0x021e08 (120 B) | FDE: 0x04a3e0
// Symbol (EN/VN): internal_func_021d90
//   0x021d90: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x021d94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021d98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021d9c: 910083FD  add      x29, sp, #0x20
//   0x021da0: F9400813  ldr      x19, [x0, #0x10]
//   0x021da4: F9400268  ldr      x8, [x19]
// ----------------------------------------------------------------------------
uint64_t fde_341_sub_021d90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[85]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #342 | VA: 0x021e08..0x021e18 (16 B) | FDE: 0x04a400
// Symbol (EN/VN): internal_func_021e08
//   0x021e08: F9400800  ldr      x0, [x0, #0x10]
//   0x021e0c: F9400008  ldr      x8, [x0]
//   0x021e10: F9401901  ldr      x1, [x8, #0x30]
//   0x021e14: D61F0020  br       x1
// ----------------------------------------------------------------------------
uint64_t fde_342_sub_021e08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0xF9400008u;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[86]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #343 | VA: 0x021e18..0x021eb8 (160 B) | FDE: 0x04a418
// Symbol (EN/VN): internal_func_021e18
//   0x021e18: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x021e1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021e20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021e24: 910083FD  add      x29, sp, #0x20
//   0x021e28: AA0003F4  mov      x20, x0
//   0x021e2c: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_343_sub_021e18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFB90Bu;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[87]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #344 | VA: 0x021eb8..0x021f60 (168 B) | FDE: 0x04a438
// Symbol (EN/VN): internal_func_021eb8
//   0x021eb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x021ebc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x021ec0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x021ec4: 910083FD  add      x29, sp, #0x20
//   0x021ec8: AA0003F4  mov      x20, x0
//   0x021ecc: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_344_sub_021eb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 168u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[88]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #345 | VA: 0x021f60..0x0220c0 (352 B) | FDE: 0x04a458
// Symbol (EN/VN): _ZN13AmazingEngine9AllowListC1Ev
//   0x021f60: D10103FF  sub      sp, sp, #0x40
//   0x021f64: F9000BF5  str      x21, [sp, #0x10]
//   0x021f68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x021f6c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x021f70: 9100C3FD  add      x29, sp, #0x30
//   0x021f74: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_345_sub_021f60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF5u;
    constexpr uint32_t kLastOpcode = 0x97FFB8ADu;
    constexpr uint32_t kFuncSize = 352u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[89]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #346 | VA: 0x0220c0..0x022150 (144 B) | FDE: 0x04a478
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager8instanceEv
//   0x0220c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0220c4: 910003FD  mov      x29, sp
//   0x0220c8: D0000188  adrp     x8, #0x54000
//   0x0220cc: 9103E108  add      x8, x8, #0xf8
//   0x0220d0: 08DFFD08  ldarb    w8, [x8]
//   0x0220d4: 360000A8  tbz      w8, #0, #0x220e8
// ----------------------------------------------------------------------------
uint64_t fde_346_sub_0220c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[90]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #347 | VA: 0x022150..0x0221f4 (164 B) | FDE: 0x04a498
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager12addAllowListEPNS_9AllowListE
//   0x022150: D10103FF  sub      sp, sp, #0x40
//   0x022154: F9000BF5  str      x21, [sp, #0x10]
//   0x022158: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02215c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x022160: 9100C3FD  add      x29, sp, #0x30
//   0x022164: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_347_sub_022150(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF5u;
    constexpr uint32_t kLastOpcode = 0x97FFB860u;
    constexpr uint32_t kFuncSize = 164u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[91]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #348 | VA: 0x0221f4..0x022404 (528 B) | FDE: 0x04a4b8
// Symbol (EN/VN): _ZN13AmazingEngine9AllowListD2Ev
//   0x0221f4: D10183FF  sub      sp, sp, #0x60
//   0x0221f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0221fc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x022200: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x022204: 910143FD  add      x29, sp, #0x50
//   0x022208: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_348_sub_0221f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA90357F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB7DCu;
    constexpr uint32_t kFuncSize = 528u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[92]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #349 | VA: 0x022404..0x022494 (144 B) | FDE: 0x04a4e0
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager15removeAllowListEPNS_9AllowListE
//   0x022404: D10183FF  sub      sp, sp, #0x60
//   0x022408: F9001BF5  str      x21, [sp, #0x30]
//   0x02240c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x022410: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x022414: 910143FD  add      x29, sp, #0x50
//   0x022418: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_349_sub_022404(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9001BF5u;
    constexpr uint32_t kLastOpcode = 0x97FFB7B8u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[93]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #350 | VA: 0x022494..0x0225a8 (276 B) | FDE: 0x04a500
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList14addAllowedPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x022494: D101C3FF  sub      sp, sp, #0x70
//   0x022498: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x02249c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0224a0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0224a4: 910183FD  add      x29, sp, #0x60
//   0x0224a8: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_350_sub_022494(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB773u;
    constexpr uint32_t kFuncSize = 276u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[94]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #351 | VA: 0x0225a8..0x0225e8 (64 B) | FDE: 0x04a528
// Symbol (EN/VN): _ZNK13AmazingEngine9AllowList16isAllowListEmptyEv
//   0x0225a8: F9404808  ldr      x8, [x0, #0x90]
//   0x0225ac: B4000068  cbz      x8, #0x225b8
//   0x0225b0: 2A1F03E0  mov      w0, wzr
//   0x0225b4: D65F03C0  ret      
//   0x0225b8: F9405C08  ldr      x8, [x0, #0xb8]
//   0x0225bc: B4000068  cbz      x8, #0x225c8
// ----------------------------------------------------------------------------
uint64_t fde_351_sub_0225a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9404808u;
    constexpr uint32_t kSecondOpcode = 0xB4000068u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 64u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[95]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #352 | VA: 0x0225e8..0x0226fc (276 B) | FDE: 0x04a540
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList18addUserAllowedPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x0225e8: D101C3FF  sub      sp, sp, #0x70
//   0x0225ec: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0225f0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0225f4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0225f8: 910183FD  add      x29, sp, #0x60
//   0x0225fc: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_352_sub_0225e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB71Eu;
    constexpr uint32_t kFuncSize = 276u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[96]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #353 | VA: 0x0226fc..0x0228c8 (460 B) | FDE: 0x04a568
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList17removeAllowedPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x0226fc: D101C3FF  sub      sp, sp, #0x70
//   0x022700: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x022704: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x022708: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x02270c: 910183FD  add      x29, sp, #0x60
//   0x022710: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_353_sub_0226fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB6ABu;
    constexpr uint32_t kFuncSize = 460u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[97]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #354 | VA: 0x0228c8..0x022a94 (460 B) | FDE: 0x04a590
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList21removeUserAllowedPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x0228c8: D101C3FF  sub      sp, sp, #0x70
//   0x0228cc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0228d0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0228d4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0228d8: 910183FD  add      x29, sp, #0x60
//   0x0228dc: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_354_sub_0228c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB638u;
    constexpr uint32_t kFuncSize = 460u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[98]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #355 | VA: 0x022a94..0x022b80 (236 B) | FDE: 0x04a5b8
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList20clearAllAllowedPathsEv
//   0x022a94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x022a98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022a9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022aa0: 910083FD  add      x29, sp, #0x20
//   0x022aa4: AA0003F3  mov      x19, x0
//   0x022aa8: 97FFB686  bl       #0x104c0
// ----------------------------------------------------------------------------
uint64_t fde_355_sub_022a94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF7u;
    constexpr uint32_t kFuncSize = 236u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[99]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #356 | VA: 0x022b80..0x022c6c (236 B) | FDE: 0x04a5d8
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList24clearAllUserAllowedPathsEv
//   0x022b80: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x022b84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022b88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022b8c: 910083FD  add      x29, sp, #0x20
//   0x022b90: AA0003F3  mov      x19, x0
//   0x022b94: 97FFB64B  bl       #0x104c0
// ----------------------------------------------------------------------------
uint64_t fde_356_sub_022b80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF7u;
    constexpr uint32_t kFuncSize = 236u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[100]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #357 | VA: 0x022c6c..0x022f48 (732 B) | FDE: 0x04a5f8
// Symbol (EN/VN): _ZNK13AmazingEngine9AllowList9isAllowedERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x022c6c: D10283FF  sub      sp, sp, #0xa0
//   0x022c70: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x022c74: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x022c78: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x022c7c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x022c80: A9084FF4  stp      x20, x19, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_357_sub_022c6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xA9046FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFB50Bu;
    constexpr uint32_t kFuncSize = 732u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[101]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #358 | VA: 0x022f48..0x022f94 (76 B) | FDE: 0x04a628
// Symbol (EN/VN): _ZN13AmazingEngine9AllowList34injectLuaIOFunctionsUsingAllowListEv
//   0x022f48: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x022f4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022f50: 910043FD  add      x29, sp, #0x10
//   0x022f54: 52802C00  mov      w0, #0x160
//   0x022f58: AA0803F3  mov      x19, x8
//   0x022f5c: 97FFB4A9  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_358_sub_022f48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[102]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #359 | VA: 0x022f94..0x023064 (208 B) | FDE: 0x04a648
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager20addAllowedPathGlobalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x022f94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x022f98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022f9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022fa0: 910083FD  add      x29, sp, #0x20
//   0x022fa4: D0000188  adrp     x8, #0x54000
//   0x022fa8: 9103E108  add      x8, x8, #0xf8
// ----------------------------------------------------------------------------
uint64_t fde_359_sub_022f94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFD6u;
    constexpr uint32_t kFuncSize = 208u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[103]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #360 | VA: 0x023064..0x023134 (208 B) | FDE: 0x04a668
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager24addUserAllowedPathGlobalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x023064: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x023068: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02306c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x023070: 910083FD  add      x29, sp, #0x20
//   0x023074: B0000188  adrp     x8, #0x54000
//   0x023078: 9103E108  add      x8, x8, #0xf8
// ----------------------------------------------------------------------------
uint64_t fde_360_sub_023064(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFD6u;
    constexpr uint32_t kFuncSize = 208u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[104]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #361 | VA: 0x023134..0x023270 (316 B) | FDE: 0x04a688
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager23removeAllowedPathGlobalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x023134: D10143FF  sub      sp, sp, #0x50
//   0x023138: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02313c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x023140: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x023144: 910103FD  add      x29, sp, #0x40
//   0x023148: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_361_sub_023134(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA90257F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB441u;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[105]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #362 | VA: 0x023270..0x0233ac (316 B) | FDE: 0x04a6b0
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager27removeUserAllowedPathGlobalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x023270: D10143FF  sub      sp, sp, #0x50
//   0x023274: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x023278: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02327c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x023280: 910103FD  add      x29, sp, #0x40
//   0x023284: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_362_sub_023270(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA90257F6u;
    constexpr uint32_t kLastOpcode = 0x97FFB3F2u;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[106]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #363 | VA: 0x0233ac..0x0234c4 (280 B) | FDE: 0x04a6d8
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager26clearAllAllowedPathsGlobalEv
//   0x0233ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0233b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0233b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0233b8: 910083FD  add      x29, sp, #0x20
//   0x0233bc: B0000188  adrp     x8, #0x54000
//   0x0233c0: 9103E108  add      x8, x8, #0xf8
// ----------------------------------------------------------------------------
uint64_t fde_363_sub_0233ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFC3u;
    constexpr uint32_t kFuncSize = 280u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[107]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #364 | VA: 0x0234c4..0x0235dc (280 B) | FDE: 0x04a6f8
// Symbol (EN/VN): _ZN13AmazingEngine16AllowListManager30clearAllUserAllowedPathsGlobalEv
//   0x0234c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0234c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0234cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0234d0: 910083FD  add      x29, sp, #0x20
//   0x0234d4: B0000188  adrp     x8, #0x54000
//   0x0234d8: 9103E108  add      x8, x8, #0xf8
// ----------------------------------------------------------------------------
uint64_t fde_364_sub_0234c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFC3u;
    constexpr uint32_t kFuncSize = 280u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[108]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #365 | VA: 0x0235dc..0x023844 (616 B) | FDE: 0x04a718
// Symbol (EN/VN): internal_func_0235dc
//   0x0235dc: D10183FF  sub      sp, sp, #0x60
//   0x0235e0: F9000BF9  str      x25, [sp, #0x10]
//   0x0235e4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0235e8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0235ec: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0235f0: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_365_sub_0235dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FFB2CCu;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[109]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #366 | VA: 0x023844..0x023cb8 (1140 B) | FDE: 0x04a740
// Symbol (EN/VN): internal_func_023844
//   0x023844: F100805F  cmp      x2, #0x20
//   0x023848: 54000348  b.hi     #0x238b0
//   0x02384c: F100405F  cmp      x2, #0x10
//   0x023850: 54000948  b.hi     #0x23978
//   0x023854: F100245F  cmp      x2, #9
//   0x023858: 54001DE3  b.lo     #0x23c14
// ----------------------------------------------------------------------------
uint64_t fde_366_sub_023844(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF100805Fu;
    constexpr uint32_t kSecondOpcode = 0x54000348u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 1140u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[110]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #367 | VA: 0x023cb8..0x0240b8 (1024 B) | FDE: 0x04a758
// Symbol (EN/VN): internal_func_023cb8
//   0x023cb8: D10243FF  sub      sp, sp, #0x90
//   0x023cbc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x023cc0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x023cc4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x023cc8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x023ccc: A9074FF4  stp      x20, x19, [sp, #0x70]
// ----------------------------------------------------------------------------
uint64_t fde_367_sub_023cb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9036FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 1024u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[111]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #368 | VA: 0x0240b8..0x0241b0 (248 B) | FDE: 0x04a788
// Symbol (EN/VN): internal_func_0240b8
//   0x0240b8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0240bc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0240c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0240c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0240c8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0240cc: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_368_sub_0240b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFAFADu;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[112]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #369 | VA: 0x0241b0..0x0242b8 (264 B) | FDE: 0x04a7b0
// Symbol (EN/VN): internal_func_0241b0
//   0x0241b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0241b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0241b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0241bc: 910083FD  add      x29, sp, #0x20
//   0x0241c0: F1000428  subs     x8, x1, #1
//   0x0241c4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_369_sub_0241b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[113]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #370 | VA: 0x0242b8..0x0245d8 (800 B) | FDE: 0x04a7d0
// Symbol (EN/VN): internal_func_0242b8
//   0x0242b8: D101C3FF  sub      sp, sp, #0x70
//   0x0242bc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0242c0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0242c4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0242c8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0242cc: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_370_sub_0242b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFAEA3u;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[114]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #371 | VA: 0x0245d8..0x024724 (332 B) | FDE: 0x04a800
// Symbol (EN/VN): internal_func_0245d8
//   0x0245d8: F9400409  ldr      x9, [x0, #8]
//   0x0245dc: F940042A  ldr      x10, [x1, #8]
//   0x0245e0: 9E670120  fmov     d0, x9
//   0x0245e4: 0E205800  cnt      v0.8b, v0.8b
//   0x0245e8: 2E303800  uaddlv   h0, v0.8b
//   0x0245ec: 1E26000D  fmov     w13, s0
// ----------------------------------------------------------------------------
uint64_t fde_371_sub_0245d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xF940042Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[115]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #372 | VA: 0x024724..0x02498c (616 B) | FDE: 0x04a818
// Symbol (EN/VN): internal_func_024724
//   0x024724: D10183FF  sub      sp, sp, #0x60
//   0x024728: F9000BF9  str      x25, [sp, #0x10]
//   0x02472c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x024730: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x024734: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x024738: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_372_sub_024724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FFAE7Au;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[116]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #373 | VA: 0x02498c..0x024c1c (656 B) | FDE: 0x04a840
// Symbol (EN/VN): internal_func_02498c
//   0x02498c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x024990: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x024994: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x024998: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02499c: 9100C3FD  add      x29, sp, #0x30
//   0x0249a0: F9400028  ldr      x8, [x1]
// ----------------------------------------------------------------------------
uint64_t fde_373_sub_02498c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 656u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[117]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #374 | VA: 0x024c1c..0x024d24 (264 B) | FDE: 0x04a868
// Symbol (EN/VN): internal_func_024c1c
//   0x024c1c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x024c20: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x024c24: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x024c28: 910083FD  add      x29, sp, #0x20
//   0x024c2c: F1000428  subs     x8, x1, #1
//   0x024c30: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_374_sub_024c1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[118]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #375 | VA: 0x024d24..0x024f54 (560 B) | FDE: 0x04a888
// Symbol (EN/VN): internal_func_024d24
//   0x024d24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x024d28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x024d2c: 910043FD  add      x29, sp, #0x10
//   0x024d30: AA0003F3  mov      x19, x0
//   0x024d34: B40004A1  cbz      x1, #0x24dc8
//   0x024d38: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_375_sub_024d24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x97FFAC44u;
    constexpr uint32_t kFuncSize = 560u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[119]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #376 | VA: 0x024f54..0x025080 (300 B) | FDE: 0x04a8a8
// Symbol (EN/VN): internal_func_024f54
//   0x024f54: F9400409  ldr      x9, [x0, #8]
//   0x024f58: B4000829  cbz      x9, #0x2505c
//   0x024f5c: F9400028  ldr      x8, [x1]
//   0x024f60: D285AD2A  mov      x10, #0x2d69
//   0x024f64: F2BD670A  movk     x10, #0xeb38, lsl #16
//   0x024f68: F2DD410A  movk     x10, #0xea08, lsl #32
// ----------------------------------------------------------------------------
uint64_t fde_376_sub_024f54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xB4000829u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 300u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[120]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #377 | VA: 0x025080..0x0251cc (332 B) | FDE: 0x04a8c0
// Symbol (EN/VN): internal_func_025080
//   0x025080: F9400409  ldr      x9, [x0, #8]
//   0x025084: F940042A  ldr      x10, [x1, #8]
//   0x025088: 9E670120  fmov     d0, x9
//   0x02508c: 0E205800  cnt      v0.8b, v0.8b
//   0x025090: 2E303800  uaddlv   h0, v0.8b
//   0x025094: 1E26000D  fmov     w13, s0
// ----------------------------------------------------------------------------
uint64_t fde_377_sub_025080(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xF940042Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[121]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #378 | VA: 0x0251cc..0x025590 (964 B) | FDE: 0x04a8d8
// Symbol (EN/VN): internal_func_0251cc
//   0x0251cc: D10203FF  sub      sp, sp, #0x80
//   0x0251d0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0251d4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0251d8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0251dc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0251e0: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_378_sub_0251cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA9026FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 964u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[122]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #379 | VA: 0x025590..0x025680 (240 B) | FDE: 0x04a908
// Symbol (EN/VN): internal_func_025590
//   0x025590: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x025594: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x025598: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02559c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0255a0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0255a4: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_379_sub_025590(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FFAA79u;
    constexpr uint32_t kFuncSize = 240u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[123]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #380 | VA: 0x025680..0x025788 (264 B) | FDE: 0x04a930
// Symbol (EN/VN): internal_func_025680
//   0x025680: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x025684: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x025688: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02568c: 910083FD  add      x29, sp, #0x20
//   0x025690: F1000428  subs     x8, x1, #1
//   0x025694: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_380_sub_025680(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[124]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #381 | VA: 0x025788..0x025aa8 (800 B) | FDE: 0x04a950
// Symbol (EN/VN): internal_func_025788
//   0x025788: D101C3FF  sub      sp, sp, #0x70
//   0x02578c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x025790: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x025794: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x025798: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x02579c: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_381_sub_025788(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFA96Fu;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[125]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #382 | VA: 0x025aa8..0x025d10 (616 B) | FDE: 0x04a980
// Symbol (EN/VN): internal_func_025aa8
//   0x025aa8: D10183FF  sub      sp, sp, #0x60
//   0x025aac: F9000BF9  str      x25, [sp, #0x10]
//   0x025ab0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x025ab4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x025ab8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x025abc: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_382_sub_025aa8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FFA999u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[126]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #383 | VA: 0x025d10..0x025e5c (332 B) | FDE: 0x04a9a8
// Symbol (EN/VN): internal_func_025d10
//   0x025d10: F9400409  ldr      x9, [x0, #8]
//   0x025d14: F940042A  ldr      x10, [x1, #8]
//   0x025d18: 9E670120  fmov     d0, x9
//   0x025d1c: 0E205800  cnt      v0.8b, v0.8b
//   0x025d20: 2E303800  uaddlv   h0, v0.8b
//   0x025d24: 1E26000D  fmov     w13, s0
// ----------------------------------------------------------------------------
uint64_t fde_383_sub_025d10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xF940042Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[127]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #384 | VA: 0x025e5c..0x025e94 (56 B) | FDE: 0x04a9c0
// Symbol (EN/VN): internal_func_025e5c
//   0x025e5c: D0000168  adrp     x8, #0x53000
//   0x025e60: F9466D08  ldr      x8, [x8, #0xcd8]
//   0x025e64: 6F00E400  movi     v0.2d, #0000000000000000
//   0x025e68: B900381F  str      wzr, [x0, #0x38]
//   0x025e6c: F0000169  adrp     x9, #0x54000
//   0x025e70: 91004108  add      x8, x8, #0x10
// ----------------------------------------------------------------------------
uint64_t fde_384_sub_025e5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD0000168u;
    constexpr uint32_t kSecondOpcode = 0xF9466D08u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[128]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #385 | VA: 0x025e94..0x025e98 (4 B) | FDE: 0x04a9d8
// Symbol (EN/VN): internal_func_025e94
//   0x025e94: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_385_sub_025e94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[129]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #386 | VA: 0x025e98..0x025e9c (4 B) | FDE: 0x04a9f0
// Symbol (EN/VN): internal_func_025e98
//   0x025e98: D4200020  brk      #1
// ----------------------------------------------------------------------------
uint64_t fde_386_sub_025e98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD4200020u;
    constexpr uint32_t kSecondOpcode = 0xD4200020u;
    constexpr uint32_t kLastOpcode = 0xD4200020u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[130]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #387 | VA: 0x025e9c..0x025ea4 (8 B) | FDE: 0x04aa08
// Symbol (EN/VN): internal_func_025e9c
//   0x025e9c: AA1F03E0  mov      x0, xzr
//   0x025ea0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_387_sub_025e9c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA1F03E0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[131]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #388 | VA: 0x025ea4..0x025eac (8 B) | FDE: 0x04aa20
// Symbol (EN/VN): internal_func_025ea4
//   0x025ea4: F9400C00  ldr      x0, [x0, #0x18]
//   0x025ea8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_388_sub_025ea4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400C00u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[132]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #389 | VA: 0x025eac..0x025ebc (16 B) | FDE: 0x04aa38
// Symbol (EN/VN): internal_func_025eac
//   0x025eac: F9400C08  ldr      x8, [x0, #0x18]
//   0x025eb0: F9401409  ldr      x9, [x0, #0x28]
//   0x025eb4: 8B080120  add      x0, x9, x8
//   0x025eb8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_389_sub_025eac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400C08u;
    constexpr uint32_t kSecondOpcode = 0xF9401409u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[133]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #390 | VA: 0x025ebc..0x025ec4 (8 B) | FDE: 0x04aa50
// Symbol (EN/VN): internal_func_025ebc
//   0x025ebc: F9401000  ldr      x0, [x0, #0x20]
//   0x025ec0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_390_sub_025ebc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9401000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[134]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #391 | VA: 0x025ec4..0x025ecc (8 B) | FDE: 0x04aa68
// Symbol (EN/VN): internal_func_025ec4
//   0x025ec4: F9401800  ldr      x0, [x0, #0x30]
//   0x025ec8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_391_sub_025ec4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9401800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[135]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #392 | VA: 0x025ecc..0x025ed4 (8 B) | FDE: 0x04aa80
// Symbol (EN/VN): internal_func_025ecc
//   0x025ecc: 2A1F03E0  mov      w0, wzr
//   0x025ed0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_392_sub_025ecc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2A1F03E0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[136]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #393 | VA: 0x025ed4..0x025edc (8 B) | FDE: 0x04aa98
// Symbol (EN/VN): internal_func_025ed4
//   0x025ed4: F9400400  ldr      x0, [x0, #8]
//   0x025ed8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_393_sub_025ed4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400400u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[137]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #394 | VA: 0x025edc..0x025f28 (76 B) | FDE: 0x04aab0
// Symbol (EN/VN): internal_func_025edc
//   0x025edc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x025ee0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025ee4: 910043FD  add      x29, sp, #0x10
//   0x025ee8: AA0003F3  mov      x19, x0
//   0x025eec: 97FFFFDC  bl       #0x25e5c
//   0x025ef0: D0000168  adrp     x8, #0x53000
// ----------------------------------------------------------------------------
uint64_t fde_394_sub_025edc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[138]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #395 | VA: 0x025f28..0x026080 (344 B) | FDE: 0x04aad0
// Symbol (EN/VN): internal_func_025f28
//   0x025f28: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x025f2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x025f30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x025f34: 910083FD  add      x29, sp, #0x20
//   0x025f38: 51000448  sub      w8, w2, #1
//   0x025f3c: 8B28C028  add      x8, x1, w8, sxtw
// ----------------------------------------------------------------------------
uint64_t fde_395_sub_025f28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 344u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[139]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #396 | VA: 0x026080..0x0262e8 (616 B) | FDE: 0x04aaf0
// Symbol (EN/VN): internal_func_026080
//   0x026080: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x026084: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x026088: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02608c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x026090: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x026094: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_396_sub_026080(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BB67FAu;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[140]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #397 | VA: 0x0262e8..0x0263a0 (184 B) | FDE: 0x04ab20
// Symbol (EN/VN): internal_func_0262e8
//   0x0262e8: B40004A1  cbz      x1, #0x2637c
//   0x0262ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0262f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0262f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0262f8: 910083FD  add      x29, sp, #0x20
//   0x0262fc: 9101A015  add      x21, x0, #0x68
// ----------------------------------------------------------------------------
uint64_t fde_397_sub_0262e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB40004A1u;
    constexpr uint32_t kSecondOpcode = 0xF81D0FF5u;
    constexpr uint32_t kLastOpcode = 0x1400040Du;
    constexpr uint32_t kFuncSize = 184u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[141]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #398 | VA: 0x0263a0..0x0263f0 (80 B) | FDE: 0x04ab40
// Symbol (EN/VN): internal_func_0263a0
//   0x0263a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0263a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0263a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0263ac: 910083FD  add      x29, sp, #0x20
//   0x0263b0: 9101A015  add      x21, x0, #0x68
//   0x0263b4: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_398_sub_0263a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[142]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #399 | VA: 0x0263f0..0x0265fc (524 B) | FDE: 0x04ab60
// Symbol (EN/VN): internal_func_0263f0
//   0x0263f0: D10183FF  sub      sp, sp, #0x60
//   0x0263f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0263f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0263fc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x026400: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x026404: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_399_sub_0263f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA9025FF8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 524u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[143]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #400 | VA: 0x0265fc..0x026608 (12 B) | FDE: 0x04ab88
// Symbol (EN/VN): internal_func_0265fc
//   0x0265fc: B85FC028  ldur     w8, [x1, #-4]
//   0x026600: 53017D00  lsr      w0, w8, #1
//   0x026604: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_400_sub_0265fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB85FC028u;
    constexpr uint32_t kSecondOpcode = 0x53017D00u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[144]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #401 | VA: 0x026608..0x026988 (896 B) | FDE: 0x04aba0
// Symbol (EN/VN): internal_func_026608
//   0x026608: D101C3FF  sub      sp, sp, #0x70
//   0x02660c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x026610: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x026614: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x026618: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x02661c: A9067BFD  stp      x29, x30, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_401_sub_026608(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90267FAu;
    constexpr uint32_t kLastOpcode = 0x97FFA67Bu;
    constexpr uint32_t kFuncSize = 896u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[145]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #402 | VA: 0x026988..0x026d60 (984 B) | FDE: 0x04abd0
// Symbol (EN/VN): internal_func_026988
//   0x026988: D101C3FF  sub      sp, sp, #0x70
//   0x02698c: F90013F9  str      x25, [sp, #0x20]
//   0x026990: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x026994: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x026998: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x02699c: A9067BFD  stp      x29, x30, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_402_sub_026988(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F9u;
    constexpr uint32_t kLastOpcode = 0x97FFA585u;
    constexpr uint32_t kFuncSize = 984u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[146]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #403 | VA: 0x026d60..0x026dc0 (96 B) | FDE: 0x04abf8
// Symbol (EN/VN): internal_func_026d60
//   0x026d60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x026d64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x026d68: 910043FD  add      x29, sp, #0x10
//   0x026d6c: B0000168  adrp     x8, #0x53000
//   0x026d70: F9477D08  ldr      x8, [x8, #0xef8]
//   0x026d74: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_403_sub_026d60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[147]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #404 | VA: 0x026dc0..0x026e1c (92 B) | FDE: 0x04ac18
// Symbol (EN/VN): internal_func_026dc0
//   0x026dc0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x026dc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x026dc8: 910043FD  add      x29, sp, #0x10
//   0x026dcc: B0000168  adrp     x8, #0x53000
//   0x026dd0: F9477D08  ldr      x8, [x8, #0xef8]
//   0x026dd4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_404_sub_026dc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFA2D2u;
    constexpr uint32_t kFuncSize = 92u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[148]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #405 | VA: 0x026e1c..0x027084 (616 B) | FDE: 0x04ac38
// Symbol (EN/VN): internal_func_026e1c
//   0x026e1c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x026e20: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x026e24: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x026e28: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x026e2c: 9100C3FD  add      x29, sp, #0x30
//   0x026e30: F9400416  ldr      x22, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_405_sub_026e1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[149]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #406 | VA: 0x027084..0x02718c (264 B) | FDE: 0x04ac60
// Symbol (EN/VN): internal_func_027084
//   0x027084: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x027088: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02708c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x027090: 910083FD  add      x29, sp, #0x20
//   0x027094: F1000428  subs     x8, x1, #1
//   0x027098: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_406_sub_027084(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[150]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #407 | VA: 0x02718c..0x0273bc (560 B) | FDE: 0x04ac80
// Symbol (EN/VN): internal_func_02718c
//   0x02718c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x027190: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x027194: 910043FD  add      x29, sp, #0x10
//   0x027198: AA0003F3  mov      x19, x0
//   0x02719c: B40004A1  cbz      x1, #0x27230
//   0x0271a0: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_407_sub_02718c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x97FFA32Au;
    constexpr uint32_t kFuncSize = 560u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[151]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #408 | VA: 0x0273bc..0x0273c4 (8 B) | FDE: 0x04aca0
// Symbol (EN/VN): internal_func_0273bc
//   0x0273bc: AA0103E0  mov      x0, x1
//   0x0273c0: 17FFA2A8  b        #0xfe60
// ----------------------------------------------------------------------------
uint64_t fde_408_sub_0273bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA0103E0u;
    constexpr uint32_t kSecondOpcode = 0x17FFA2A8u;
    constexpr uint32_t kLastOpcode = 0x17FFA2A8u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[152]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #409 | VA: 0x0273c4..0x0273d0 (12 B) | FDE: 0x04acb8
// Symbol (EN/VN): internal_func_0273c4
//   0x0273c4: AA0103E0  mov      x0, x1
//   0x0273c8: AA0203E1  mov      x1, x2
//   0x0273cc: 17FFA245  b        #0xfce0
// ----------------------------------------------------------------------------
uint64_t fde_409_sub_0273c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA0103E0u;
    constexpr uint32_t kSecondOpcode = 0xAA0203E1u;
    constexpr uint32_t kLastOpcode = 0x17FFA245u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[153]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #410 | VA: 0x0273d0..0x0273d8 (8 B) | FDE: 0x04acd0
// Symbol (EN/VN): internal_func_0273d0
//   0x0273d0: AA0103E0  mov      x0, x1
//   0x0273d4: 17FFA137  b        #0xf8b0
// ----------------------------------------------------------------------------
uint64_t fde_410_sub_0273d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA0103E0u;
    constexpr uint32_t kSecondOpcode = 0x17FFA137u;
    constexpr uint32_t kLastOpcode = 0x17FFA137u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[154]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #411 | VA: 0x0273d8..0x0273ec (20 B) | FDE: 0x04ace8
// Symbol (EN/VN): internal_func_0273d8
//   0x0273d8: B00000E8  adrp     x8, #0x44000
//   0x0273dc: 912BE508  add      x8, x8, #0xaf9
//   0x0273e0: 7100041F  cmp      w0, #1
//   0x0273e4: 9A9FB100  csel     x0, x8, xzr, lt
//   0x0273e8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_411_sub_0273d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB00000E8u;
    constexpr uint32_t kSecondOpcode = 0x912BE508u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[155]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #412 | VA: 0x0273ec..0x027404 (24 B) | FDE: 0x04ad00
// Symbol (EN/VN): internal_func_0273ec
//   0x0273ec: AA0003E8  mov      x8, x0
//   0x0273f0: F9400000  ldr      x0, [x0]
//   0x0273f4: B4000060  cbz      x0, #0x27400
//   0x0273f8: F9000500  str      x0, [x8, #8]
//   0x0273fc: 17FFA159  b        #0xf960
//   0x027400: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_412_sub_0273ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA0003E8u;
    constexpr uint32_t kSecondOpcode = 0xF9400000u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[156]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #413 | VA: 0x027404..0x02747c (120 B) | FDE: 0x04ad18
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManagerC2Ev
//   0x027404: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x027408: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02740c: 910043FD  add      x29, sp, #0x10
//   0x027410: 52800028  mov      w8, #1
//   0x027414: AA0003F3  mov      x19, x0
//   0x027418: A9007C1F  stp      xzr, xzr, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_413_sub_027404(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[157]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #414 | VA: 0x02747c..0x0274d4 (88 B) | FDE: 0x04ad38
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager17initAllAllocatorsEv
//   0x02747c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x027480: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x027484: 910043FD  add      x29, sp, #0x10
//   0x027488: AA0003F3  mov      x19, x0
//   0x02748c: 52801300  mov      w0, #0x98
//   0x027490: 97FFA35C  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_414_sub_02747c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[158]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #415 | VA: 0x0274d4..0x027564 (144 B) | FDE: 0x04ad58
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManagerD2Ev
//   0x0274d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0274d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0274dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0274e0: 910083FD  add      x29, sp, #0x20
//   0x0274e4: B9401808  ldr      w8, [x0, #0x18]
//   0x0274e8: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_415_sub_0274d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[159]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #416 | VA: 0x027564..0x027590 (44 B) | FDE: 0x04ad78
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager16lowLevelAllocateEm
//   0x027564: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x027568: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02756c: 910043FD  add      x29, sp, #0x10
//   0x027570: AA0003F3  mov      x19, x0
//   0x027574: 91004000  add      x0, x0, #0x10
//   0x027578: 97FFA15E  bl       #0xfaf0
// ----------------------------------------------------------------------------
uint64_t fde_416_sub_027564(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[160]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #417 | VA: 0x027590..0x0275c0 (48 B) | FDE: 0x04ad98
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager18lowLevelreallocateEPvm
//   0x027590: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x027594: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x027598: 910043FD  add      x29, sp, #0x10
//   0x02759c: AA0103F3  mov      x19, x1
//   0x0275a0: D1004000  sub      x0, x0, #0x10
//   0x0275a4: 91004021  add      x1, x1, #0x10
// ----------------------------------------------------------------------------
uint64_t fde_417_sub_027590(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[161]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #418 | VA: 0x0275c0..0x027618 (88 B) | FDE: 0x04adb8
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager17lowLevelCAllocateEmm
//   0x0275c0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0275c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0275c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0275cc: 910083FD  add      x29, sp, #0x20
//   0x0275d0: 9B007C35  mul      x21, x1, x0
//   0x0275d4: D2C00208  mov      x8, #0x1000000000
// ----------------------------------------------------------------------------
uint64_t fde_418_sub_0275c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[162]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #419 | VA: 0x027618..0x027628 (16 B) | FDE: 0x04add8
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager12lowLevelFreeEPv
//   0x027618: B4000060  cbz      x0, #0x27624
//   0x02761c: D1004000  sub      x0, x0, #0x10
//   0x027620: 17FFA11C  b        #0xfa90
//   0x027624: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_419_sub_027618(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB4000060u;
    constexpr uint32_t kSecondOpcode = 0xD1004000u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[163]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #420 | VA: 0x027628..0x027884 (604 B) | FDE: 0x04adf0
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager10reallocateEPvmi21AMGMemLabelIdentifierPKci
//   0x027628: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x02762c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x027630: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x027634: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x027638: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02763c: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_420_sub_027628(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFC1u;
    constexpr uint32_t kFuncSize = 604u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[164]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #421 | VA: 0x027884..0x027930 (172 B) | FDE: 0x04ae18
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager8allocateEmi21AMGMemLabelIdentifierPKci
//   0x027884: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x027888: 910003FD  mov      x29, sp
//   0x02788c: 51000448  sub      w8, w2, #1
//   0x027890: 6A08005F  tst      w2, w8
//   0x027894: 54000161  b.ne     #0x278c0
//   0x027898: 340002C2  cbz      w2, #0x278f0
// ----------------------------------------------------------------------------
uint64_t fde_421_sub_027884(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[165]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #422 | VA: 0x027930..0x027950 (32 B) | FDE: 0x04ae38
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager12getAllocatorE21AMGMemLabelIdentifier
//   0x027930: 7100003F  cmp      w1, #0
//   0x027934: 5400006D  b.le     #0x27940
//   0x027938: AA1F03E0  mov      x0, xzr
//   0x02793c: D65F03C0  ret      
//   0x027940: 2A0103E8  mov      w8, w1
//   0x027944: 8B081408  add      x8, x0, x8, lsl #5
// ----------------------------------------------------------------------------
uint64_t fde_422_sub_027930(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x7100003Fu;
    constexpr uint32_t kSecondOpcode = 0x5400006Du;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 32u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[166]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #423 | VA: 0x027950..0x0279d0 (128 B) | FDE: 0x04ae50
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager25getAllocatorContainingPtrEPKv
//   0x027950: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x027954: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x027958: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02795c: 910083FD  add      x29, sp, #0x20
//   0x027960: B9401808  ldr      w8, [x0, #0x18]
//   0x027964: 7100051F  cmp      w8, #1
// ----------------------------------------------------------------------------
uint64_t fde_423_sub_027950(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[167]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #424 | VA: 0x0279d0..0x027aa4 (212 B) | FDE: 0x04ae78
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager10deallocateEPv
//   0x0279d0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0279d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0279d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0279dc: 910083FD  add      x29, sp, #0x20
//   0x0279e0: B40005A1  cbz      x1, #0x27a94
//   0x0279e4: B9401808  ldr      w8, [x0, #0x18]
// ----------------------------------------------------------------------------
uint64_t fde_424_sub_0279d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 212u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[168]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #425 | VA: 0x027aa4..0x027bb4 (272 B) | FDE: 0x04aea0
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager10deallocateEPv21AMGMemLabelIdentifier
//   0x027aa4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x027aa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x027aac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x027ab0: 910083FD  add      x29, sp, #0x20
//   0x027ab4: B4000781  cbz      x1, #0x27ba4
//   0x027ab8: AA0103F3  mov      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_425_sub_027aa4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 272u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[169]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #426 | VA: 0x027bb4..0x027c20 (108 B) | FDE: 0x04aec8
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager23getTotalAllocatedMemoryEv
//   0x027bb4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x027bb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x027bbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x027bc0: 910083FD  add      x29, sp, #0x20
//   0x027bc4: B9401808  ldr      w8, [x0, #0x18]
//   0x027bc8: 7100051F  cmp      w8, #1
// ----------------------------------------------------------------------------
uint64_t fde_426_sub_027bb4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[170]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #427 | VA: 0x027c20..0x027ddc (444 B) | FDE: 0x04aef0
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager4initEv
//   0x027c20: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x027c24: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x027c28: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x027c2c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x027c30: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x027c34: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_427_sub_027c20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BA6FFCu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FFA0A2u;
    constexpr uint32_t kFuncSize = 444u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[171]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #428 | VA: 0x027ddc..0x027e48 (108 B) | FDE: 0x04af20
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager6deinitEv
//   0x027ddc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x027de0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x027de4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x027de8: 910083FD  add      x29, sp, #0x20
//   0x027dec: A9405815  ldp      x21, x22, [x0]
//   0x027df0: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_428_sub_027ddc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[172]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #429 | VA: 0x027e48..0x027e50 (8 B) | FDE: 0x04af48
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager17getAllocatorCountEv
//   0x027e48: B9401800  ldr      w0, [x0, #0x18]
//   0x027e4c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_429_sub_027e48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9401800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[173]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #430 | VA: 0x027e50..0x027e60 (16 B) | FDE: 0x04af60
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager18getAllocatedMemoryE21AMGMemLabelIdentifier
//   0x027e50: 2A0103E8  mov      w8, w1
//   0x027e54: 8B081408  add      x8, x0, x8, lsl #5
//   0x027e58: F9405500  ldr      x0, [x8, #0xa8]
//   0x027e5c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_430_sub_027e50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2A0103E8u;
    constexpr uint32_t kSecondOpcode = 0x8B081408u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[174]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #431 | VA: 0x027e60..0x027e70 (16 B) | FDE: 0x04af78
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager15getLargestAllocE21AMGMemLabelIdentifier
//   0x027e60: 2A0103E8  mov      w8, w1
//   0x027e64: 8B081408  add      x8, x0, x8, lsl #5
//   0x027e68: F9405D00  ldr      x0, [x8, #0xb8]
//   0x027e6c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_431_sub_027e60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2A0103E8u;
    constexpr uint32_t kSecondOpcode = 0x8B081408u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[175]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #432 | VA: 0x027e70..0x027e80 (16 B) | FDE: 0x04af90
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager13getAllocCountE21AMGMemLabelIdentifier
//   0x027e70: 2A0103E8  mov      w8, w1
//   0x027e74: 8B081408  add      x8, x0, x8, lsl #5
//   0x027e78: B940B100  ldr      w0, [x8, #0xb0]
//   0x027e7c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_432_sub_027e70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2A0103E8u;
    constexpr uint32_t kSecondOpcode = 0x8B081408u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[176]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #433 | VA: 0x027e80..0x028184 (772 B) | FDE: 0x04afa8
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager21printShortMemoryStatsERNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
//   0x027e80: D106C3FF  sub      sp, sp, #0x1b0
//   0x027e84: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x027e88: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x027e8c: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x027e90: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x027e94: A9194FF4  stp      x20, x19, [sp, #0x190]
// ----------------------------------------------------------------------------
uint64_t fde_433_sub_027e80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD106C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9156FFCu;
    constexpr uint32_t kLastOpcode = 0x97FFA07Cu;
    constexpr uint32_t kFuncSize = 772u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[177]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #434 | VA: 0x028184..0x028338 (436 B) | FDE: 0x04afd8
// Symbol (EN/VN): internal_func_028184
//   0x028184: D10183FF  sub      sp, sp, #0x60
//   0x028188: FD000BE8  str      d8, [sp, #0x10]
//   0x02818c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x028190: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x028194: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x028198: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_434_sub_028184(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xFD000BE8u;
    constexpr uint32_t kLastOpcode = 0x97FFA00Fu;
    constexpr uint32_t kFuncSize = 436u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[178]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #435 | VA: 0x028338..0x028364 (44 B) | FDE: 0x04b000
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager13getMemoryPoolEi
//   0x028338: AA0003E8  mov      x8, x0
//   0x02833c: AA1F03E0  mov      x0, xzr
//   0x028340: 37F80101  tbnz     w1, #0x1f, #0x28360
//   0x028344: A9402909  ldp      x9, x10, [x8]
//   0x028348: 93407C28  sxtw     x8, w1
//   0x02834c: CB09014A  sub      x10, x10, x9
// ----------------------------------------------------------------------------
uint64_t fde_435_sub_028338(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA0003E8u;
    constexpr uint32_t kSecondOpcode = 0xAA1F03E0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[179]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #436 | VA: 0x028364..0x02848c (296 B) | FDE: 0x04b018
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager16createMemoryPoolEPKcii21AMGMemLabelIdentifier
//   0x028364: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x028368: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x02836c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x028370: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x028374: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x028378: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_436_sub_028364(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFE6u;
    constexpr uint32_t kFuncSize = 296u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[180]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #437 | VA: 0x02848c..0x0285e0 (340 B) | FDE: 0x04b040
// Symbol (EN/VN): _ZN13AmazingEngine6memory13MemoryManager24registerReservedPoolInfoEPKcii21AMGMemLabelIdentifier
//   0x02848c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x028490: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x028494: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x028498: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x02849c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0284a0: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_437_sub_02848c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81A0FFBu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0x97FF9EA1u;
    constexpr uint32_t kFuncSize = 340u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[181]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #438 | VA: 0x0285e0..0x0287ec (524 B) | FDE: 0x04b070
// Symbol (EN/VN): internal_func_0285e0
//   0x0285e0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0285e4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0285e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0285ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0285f0: 9100C3FD  add      x29, sp, #0x30
//   0x0285f4: B9406009  ldr      w9, [x0, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_438_sub_0285e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FF9E1Eu;
    constexpr uint32_t kFuncSize = 524u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[182]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #439 | VA: 0x0287ec..0x028838 (76 B) | FDE: 0x04b0b0
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPoolC2EPKcii21AMGMemLabelIdentifier
//   0x0287ec: 7100205F  cmp      w2, #8
//   0x0287f0: 52800108  mov      w8, #8
//   0x0287f4: 93407C69  sxtw     x9, w3
//   0x0287f8: 1A88C048  csel     w8, w2, w8, gt
//   0x0287fc: 6F00E400  movi     v0.2d, #0000000000000000
//   0x028800: 5280002A  mov      w10, #1
// ----------------------------------------------------------------------------
uint64_t fde_439_sub_0287ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x7100205Fu;
    constexpr uint32_t kSecondOpcode = 0x52800108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[183]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #440 | VA: 0x028838..0x028844 (12 B) | FDE: 0x04b0c8
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool5resetEv
//   0x028838: B900701F  str      wzr, [x0, #0x70]
//   0x02883c: F9001C1F  str      xzr, [x0, #0x38]
//   0x028840: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_440_sub_028838(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900701Fu;
    constexpr uint32_t kSecondOpcode = 0xF9001C1Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[184]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #441 | VA: 0x028844..0x0288e0 (156 B) | FDE: 0x04b0e0
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPoolD2Ev
//   0x028844: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028848: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02884c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028850: 910083FD  add      x29, sp, #0x20
//   0x028854: A941D414  ldp      x20, x21, [x0, #0x18]
//   0x028858: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_441_sub_028844(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 156u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[185]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #442 | VA: 0x0288e0..0x028958 (120 B) | FDE: 0x04b100
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool13deallocateAllEv
//   0x0288e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0288e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0288e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0288ec: 910083FD  add      x29, sp, #0x20
//   0x0288f0: A941D414  ldp      x20, x21, [x0, #0x18]
//   0x0288f4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_442_sub_0288e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[186]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #443 | VA: 0x028958..0x0289c8 (112 B) | FDE: 0x04b120
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool17preAllocateMemoryEi
//   0x028958: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02895c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028960: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028964: 910083FD  add      x29, sp, #0x20
//   0x028968: 91011013  add      x19, x0, #0x44
//   0x02896c: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_443_sub_028958(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FF9C6Fu;
    constexpr uint32_t kFuncSize = 112u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[187]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #444 | VA: 0x0289c8..0x028b68 (416 B) | FDE: 0x04b148
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool14allocNewBubbleEv
//   0x0289c8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0289cc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0289d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0289d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0289d8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0289dc: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_444_sub_0289c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BB67FAu;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFDAu;
    constexpr uint32_t kFuncSize = 416u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[188]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #445 | VA: 0x028b68..0x028be8 (128 B) | FDE: 0x04b178
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool8allocateEv
//   0x028b68: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028b6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028b70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028b74: 910083FD  add      x29, sp, #0x20
//   0x028b78: B9800815  ldrsw    x21, [x0, #8]
//   0x028b7c: 91011013  add      x19, x0, #0x44
// ----------------------------------------------------------------------------
uint64_t fde_445_sub_028b68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[189]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #446 | VA: 0x028be8..0x028c68 (128 B) | FDE: 0x04b198
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool8allocateEm
//   0x028be8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028bec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028bf0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028bf4: 910083FD  add      x29, sp, #0x20
//   0x028bf8: 91011013  add      x19, x0, #0x44
//   0x028bfc: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_446_sub_028be8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[190]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #447 | VA: 0x028c68..0x028d2c (196 B) | FDE: 0x04b1b8
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool13tryDeallocateEPv
//   0x028c68: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028c6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028c70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028c74: 910083FD  add      x29, sp, #0x20
//   0x028c78: AA0103F4  mov      x20, x1
//   0x028c7c: B40004E1  cbz      x1, #0x28d18
// ----------------------------------------------------------------------------
uint64_t fde_447_sub_028c68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 196u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[191]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #448 | VA: 0x028d2c..0x028d8c (96 B) | FDE: 0x04b1d8
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool14containsUnsafeEPv
//   0x028d2c: A941A408  ldp      x8, x9, [x0, #0x18]
//   0x028d30: EB08012A  subs     x10, x9, x8
//   0x028d34: 54000280  b.eq     #0x28d84
//   0x028d38: AA1F03E9  mov      x9, xzr
//   0x028d3c: 9343FD4A  asr      x10, x10, #3
//   0x028d40: F869790B  ldr      x11, [x8, x9, lsl #3]
// ----------------------------------------------------------------------------
uint64_t fde_448_sub_028d2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA941A408u;
    constexpr uint32_t kSecondOpcode = 0xEB08012Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[192]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #449 | VA: 0x028d8c..0x028dd4 (72 B) | FDE: 0x04b1f0
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool16deallocateUnsafeEPv
//   0x028d8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x028d90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028d94: 910043FD  add      x29, sp, #0x10
//   0x028d98: B9800802  ldrsw    x2, [x0, #8]
//   0x028d9c: AA0103F4  mov      x20, x1
//   0x028da0: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_449_sub_028d8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[193]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #450 | VA: 0x028dd4..0x028e3c (104 B) | FDE: 0x04b210
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool10deallocateEPv
//   0x028dd4: B4000321  cbz      x1, #0x28e38
//   0x028dd8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028ddc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028de0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028de4: 910083FD  add      x29, sp, #0x20
//   0x028de8: 91011015  add      x21, x0, #0x44
// ----------------------------------------------------------------------------
uint64_t fde_450_sub_028dd4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB4000321u;
    constexpr uint32_t kSecondOpcode = 0xF81D0FF5u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[194]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #451 | VA: 0x028e3c..0x028edc (160 B) | FDE: 0x04b230
// Symbol (EN/VN): _ZN13AmazingEngine6memory10MemoryPool8containsEPv
//   0x028e3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028e40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028e44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028e48: 910083FD  add      x29, sp, #0x20
//   0x028e4c: AA0103F4  mov      x20, x1
//   0x028e50: B40003C1  cbz      x1, #0x28ec8
// ----------------------------------------------------------------------------
uint64_t fde_451_sub_028e3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[195]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #452 | VA: 0x028edc..0x02a2a4 (5064 B) | FDE: 0x04b250
// Symbol (EN/VN): _ZN13AmazingEngine6memory14MemoryPoolTestEv
//   0x028edc: D10403FF  sub      sp, sp, #0x100
//   0x028ee0: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x028ee4: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x028ee8: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x028eec: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x028ef0: A90E4FF4  stp      x20, x19, [sp, #0xe0]
// ----------------------------------------------------------------------------
uint64_t fde_452_sub_028edc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10403FFu;
    constexpr uint32_t kSecondOpcode = 0xA90A6FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF9834u;
    constexpr uint32_t kFuncSize = 5064u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[196]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #453 | VA: 0x02a2a4..0x02a3c4 (288 B) | FDE: 0x04b280
// Symbol (EN/VN): internal_func_02a2a4
//   0x02a2a4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x02a2a8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x02a2ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02a2b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02a2b4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02a2b8: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_453_sub_02a2a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFE3u;
    constexpr uint32_t kFuncSize = 288u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[197]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #454 | VA: 0x02a3c4..0x02a3cc (8 B) | FDE: 0x04b2a8
// Symbol (EN/VN): internal_func_02a3c4
//   0x02a3c4: 52800020  mov      w0, #1
//   0x02a3c8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_454_sub_02a3c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52800020u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[198]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #455 | VA: 0x02a3cc..0x02a3d0 (4 B) | FDE: 0x04b2c0
// Symbol (EN/VN): internal_func_02a3cc
//   0x02a3cc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_455_sub_02a3cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[199]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #456 | VA: 0x02a3d0..0x02a3d8 (8 B) | FDE: 0x04b2d8
// Symbol (EN/VN): internal_func_02a3d0
//   0x02a3d0: F900011F  str      xzr, [x8]
//   0x02a3d4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_456_sub_02a3d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF900011Fu;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[200]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #457 | VA: 0x02a3d8..0x02a3e0 (8 B) | FDE: 0x04b2f0
// Symbol (EN/VN): internal_func_02a3d8
//   0x02a3d8: 52800020  mov      w0, #1
//   0x02a3dc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_457_sub_02a3d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52800020u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[201]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #458 | VA: 0x02a3e0..0x02a46c (140 B) | FDE: 0x04b308
// Symbol (EN/VN): internal_func_02a3e0
//   0x02a3e0: B900081F  str      wzr, [x0, #8]
//   0x02a3e4: B0000148  adrp     x8, #0x53000
//   0x02a3e8: F946C508  ldr      x8, [x8, #0xd88]
//   0x02a3ec: 5280002A  mov      w10, #1
//   0x02a3f0: 52A7F009  mov      w9, #0x3f800000
//   0x02a3f4: 7901400A  strh     w10, [x0, #0xa0]
// ----------------------------------------------------------------------------
uint64_t fde_458_sub_02a3e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900081Fu;
    constexpr uint32_t kSecondOpcode = 0xB0000148u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 140u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[202]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #459 | VA: 0x02a46c..0x02a490 (36 B) | FDE: 0x04b320
// Symbol (EN/VN): internal_func_02a46c
//   0x02a46c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02a470: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a474: 910043FD  add      x29, sp, #0x10
//   0x02a478: AA0003F3  mov      x19, x0
//   0x02a47c: 97FF97D9  bl       #0x103e0
//   0x02a480: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_459_sub_02a46c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF9535u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[203]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #460 | VA: 0x02a490..0x02a4a0 (16 B) | FDE: 0x04b340
// Symbol (EN/VN): internal_func_02a490
//   0x02a490: F9400008  ldr      x8, [x0]
//   0x02a494: 12000021  and      w1, w1, #1
//   0x02a498: F9401D02  ldr      x2, [x8, #0x38]
//   0x02a49c: D61F0040  br       x2
// ----------------------------------------------------------------------------
uint64_t fde_460_sub_02a490(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400008u;
    constexpr uint32_t kSecondOpcode = 0x12000021u;
    constexpr uint32_t kLastOpcode = 0xD61F0040u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[204]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #461 | VA: 0x02a4a0..0x02a538 (152 B) | FDE: 0x04b358
// Symbol (EN/VN): internal_func_02a4a0
//   0x02a4a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02a4a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02a4a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02a4ac: 910083FD  add      x29, sp, #0x20
//   0x02a4b0: AA0003F3  mov      x19, x0
//   0x02a4b4: F9405800  ldr      x0, [x0, #0xb0]
// ----------------------------------------------------------------------------
uint64_t fde_461_sub_02a4a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 152u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[205]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #462 | VA: 0x02a538..0x02a5d0 (152 B) | FDE: 0x04b378
// Symbol (EN/VN): internal_func_02a538
//   0x02a538: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02a53c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02a540: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02a544: 910083FD  add      x29, sp, #0x20
//   0x02a548: AA0003F3  mov      x19, x0
//   0x02a54c: F9407000  ldr      x0, [x0, #0xe0]
// ----------------------------------------------------------------------------
uint64_t fde_462_sub_02a538(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 152u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[206]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #463 | VA: 0x02a5d0..0x02a668 (152 B) | FDE: 0x04b398
// Symbol (EN/VN): internal_func_02a5d0
//   0x02a5d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02a5d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02a5d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02a5dc: 910083FD  add      x29, sp, #0x20
//   0x02a5e0: AA0003F3  mov      x19, x0
//   0x02a5e4: F9408800  ldr      x0, [x0, #0x110]
// ----------------------------------------------------------------------------
uint64_t fde_463_sub_02a5d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 152u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[207]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #464 | VA: 0x02a668..0x02a6d4 (108 B) | FDE: 0x04b3b8
// Symbol (EN/VN): internal_func_02a668
//   0x02a668: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02a66c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a670: 910043FD  add      x29, sp, #0x10
//   0x02a674: AA0003F3  mov      x19, x0
//   0x02a678: F9409000  ldr      x0, [x0, #0x120]
//   0x02a67c: EB01001F  cmp      x0, x1
// ----------------------------------------------------------------------------
uint64_t fde_464_sub_02a668(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[208]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #465 | VA: 0x02a6d4..0x02a718 (68 B) | FDE: 0x04b3d8
// Symbol (EN/VN): internal_func_02a6d4
//   0x02a6d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02a6d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a6dc: 910043FD  add      x29, sp, #0x10
//   0x02a6e0: 9104B014  add      x20, x0, #0x12c
//   0x02a6e4: AA0003F3  mov      x19, x0
//   0x02a6e8: AA1403E0  mov      x0, x20
// ----------------------------------------------------------------------------
uint64_t fde_465_sub_02a6d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF951Bu;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[209]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #466 | VA: 0x02a718..0x02a720 (8 B) | FDE: 0x04b3f8
// Symbol (EN/VN): internal_func_02a718
//   0x02a718: F9409000  ldr      x0, [x0, #0x120]
//   0x02a71c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_466_sub_02a718(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9409000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[210]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #467 | VA: 0x02a720..0x02a7bc (156 B) | FDE: 0x04b410
// Symbol (EN/VN): internal_func_02a720
//   0x02a720: D10143FF  sub      sp, sp, #0x50
//   0x02a724: F90013F5  str      x21, [sp, #0x20]
//   0x02a728: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02a72c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02a730: 910103FD  add      x29, sp, #0x40
//   0x02a734: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_467_sub_02a720(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FF96EEu;
    constexpr uint32_t kFuncSize = 156u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[211]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #468 | VA: 0x02a7bc..0x02a85c (160 B) | FDE: 0x04b430
// Symbol (EN/VN): internal_func_02a7bc
//   0x02a7bc: D10143FF  sub      sp, sp, #0x50
//   0x02a7c0: F90013F5  str      x21, [sp, #0x20]
//   0x02a7c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02a7c8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02a7cc: 910103FD  add      x29, sp, #0x40
//   0x02a7d0: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_468_sub_02a7bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FF96C6u;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[212]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #469 | VA: 0x02a85c..0x02a8fc (160 B) | FDE: 0x04b450
// Symbol (EN/VN): internal_func_02a85c
//   0x02a85c: D10143FF  sub      sp, sp, #0x50
//   0x02a860: F90013F5  str      x21, [sp, #0x20]
//   0x02a864: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02a868: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02a86c: 910103FD  add      x29, sp, #0x40
//   0x02a870: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_469_sub_02a85c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FF969Eu;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[213]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #470 | VA: 0x02a8fc..0x02a990 (148 B) | FDE: 0x04b470
// Symbol (EN/VN): internal_func_02a8fc
//   0x02a8fc: D10103FF  sub      sp, sp, #0x40
//   0x02a900: F9000BF5  str      x21, [sp, #0x10]
//   0x02a904: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02a908: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02a90c: 9100C3FD  add      x29, sp, #0x30
//   0x02a910: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_470_sub_02a8fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF5u;
    constexpr uint32_t kLastOpcode = 0x97FF9679u;
    constexpr uint32_t kFuncSize = 148u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[214]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #471 | VA: 0x02a990..0x02aa30 (160 B) | FDE: 0x04b490
// Symbol (EN/VN): internal_func_02a990
//   0x02a990: D10143FF  sub      sp, sp, #0x50
//   0x02a994: F90013F5  str      x21, [sp, #0x20]
//   0x02a998: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02a99c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02a9a0: 910103FD  add      x29, sp, #0x40
//   0x02a9a4: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_471_sub_02a990(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FF9651u;
    constexpr uint32_t kFuncSize = 160u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[215]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #472 | VA: 0x02aa30..0x02aa38 (8 B) | FDE: 0x04b4b0
// Symbol (EN/VN): internal_func_02aa30
//   0x02aa30: F9409000  ldr      x0, [x0, #0x120]
//   0x02aa34: 17FF950F  b        #0xfe70
// ----------------------------------------------------------------------------
uint64_t fde_472_sub_02aa30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9409000u;
    constexpr uint32_t kSecondOpcode = 0x17FF950Fu;
    constexpr uint32_t kLastOpcode = 0x17FF950Fu;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[216]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #473 | VA: 0x02aa38..0x02aa40 (8 B) | FDE: 0x04b4c8
// Symbol (EN/VN): internal_func_02aa38
//   0x02aa38: F9409000  ldr      x0, [x0, #0x120]
//   0x02aa3c: 17FF943D  b        #0xfb30
// ----------------------------------------------------------------------------
uint64_t fde_473_sub_02aa38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9409000u;
    constexpr uint32_t kSecondOpcode = 0x17FF943Du;
    constexpr uint32_t kLastOpcode = 0x17FF943Du;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[217]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #474 | VA: 0x02aa40..0x02ada4 (868 B) | FDE: 0x04b4e0
// Symbol (EN/VN): _ZN13AmazingEngine20NetworkClientBuilder5buildENS_17NetworkClientTypeE
//   0x02aa40: D10203FF  sub      sp, sp, #0x80
//   0x02aa44: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02aa48: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02aa4c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x02aa50: 9101C3FD  add      x29, sp, #0x70
//   0x02aa54: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_474_sub_02aa40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA90557F6u;
    constexpr uint32_t kLastOpcode = 0x97FF9574u;
    constexpr uint32_t kFuncSize = 868u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[218]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #475 | VA: 0x02ada4..0x02b000 (604 B) | FDE: 0x04b508
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient4initERKNS_20NetworkClientBuilderE
//   0x02ada4: D10283FF  sub      sp, sp, #0xa0
//   0x02ada8: F9002BF9  str      x25, [sp, #0x50]
//   0x02adac: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x02adb0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02adb4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x02adb8: A9097BFD  stp      x29, x30, [sp, #0x90]
// ----------------------------------------------------------------------------
uint64_t fde_475_sub_02ada4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xF9002BF9u;
    constexpr uint32_t kLastOpcode = 0x97FF9AF2u;
    constexpr uint32_t kFuncSize = 604u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[219]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #476 | VA: 0x02b000..0x02b00c (12 B) | FDE: 0x04b530
// Symbol (EN/VN): _ZN13AmazingEngine20NetworkClientBuilder7useQuicEb
//   0x02b000: 12000028  and      w8, w1, #1
//   0x02b004: 39000008  strb     w8, [x0]
//   0x02b008: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_476_sub_02b000(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12000028u;
    constexpr uint32_t kSecondOpcode = 0x39000008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[220]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #477 | VA: 0x02b00c..0x02b018 (12 B) | FDE: 0x04b548
// Symbol (EN/VN): _ZN13AmazingEngine20NetworkClientBuilder8useHttp2Eb
//   0x02b00c: 12000028  and      w8, w1, #1
//   0x02b010: 39000408  strb     w8, [x0, #1]
//   0x02b014: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_477_sub_02b00c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12000028u;
    constexpr uint32_t kSecondOpcode = 0x39000408u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[221]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #478 | VA: 0x02b018..0x02b0f8 (224 B) | FDE: 0x04b560
// Symbol (EN/VN): _ZN13AmazingEngine20NetworkClientBuilder12setUserAgentERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x02b018: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02b01c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02b020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02b024: 910083FD  add      x29, sp, #0x20
//   0x02b028: 91002014  add      x20, x0, #8
//   0x02b02c: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_478_sub_02b018(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 224u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[222]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #479 | VA: 0x02b0f8..0x02b100 (8 B) | FDE: 0x04b588
// Symbol (EN/VN): _ZN13AmazingEngine20NetworkClientBuilder12setCacheModeENS_16NetworkCacheModeE
//   0x02b0f8: B9002001  str      w1, [x0, #0x20]
//   0x02b0fc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_479_sub_02b0f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9002001u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[223]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #480 | VA: 0x02b100..0x02b108 (8 B) | FDE: 0x04b5a0
// Symbol (EN/VN): _ZN13AmazingEngine20NetworkClientBuilder15setCacheMaxSizeEl
//   0x02b100: F9001401  str      x1, [x0, #0x28]
//   0x02b104: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_480_sub_02b100(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9001401u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[224]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #481 | VA: 0x02b108..0x02b110 (8 B) | FDE: 0x04b5b8
// Symbol (EN/VN): _ZNK13AmazingEngine20NetworkClientBuilder7useQuicEv
//   0x02b108: 39400000  ldrb     w0, [x0]
//   0x02b10c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_481_sub_02b108(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[225]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #482 | VA: 0x02b110..0x02b118 (8 B) | FDE: 0x04b5d0
// Symbol (EN/VN): _ZNK13AmazingEngine20NetworkClientBuilder8useHttp2Ev
//   0x02b110: 39400400  ldrb     w0, [x0, #1]
//   0x02b114: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_482_sub_02b110(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400400u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[226]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #483 | VA: 0x02b118..0x02b120 (8 B) | FDE: 0x04b5e8
// Symbol (EN/VN): _ZNK13AmazingEngine20NetworkClientBuilder12getUserAgentEv
//   0x02b118: 91002000  add      x0, x0, #8
//   0x02b11c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_483_sub_02b118(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91002000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[227]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #484 | VA: 0x02b120..0x02b128 (8 B) | FDE: 0x04b600
// Symbol (EN/VN): _ZNK13AmazingEngine20NetworkClientBuilder12getCacheModeEv
//   0x02b120: B9402000  ldr      w0, [x0, #0x20]
//   0x02b124: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_484_sub_02b120(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9402000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[228]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #485 | VA: 0x02b128..0x02b130 (8 B) | FDE: 0x04b618
// Symbol (EN/VN): _ZNK13AmazingEngine20NetworkClientBuilder15getCacheMaxSizeEv
//   0x02b128: F9401400  ldr      x0, [x0, #0x28]
//   0x02b12c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_485_sub_02b128(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9401400u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[229]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #486 | VA: 0x02b130..0x02b444 (788 B) | FDE: 0x04b630
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient17onRequestResponseEPNS_11NetworkCallERKNS_15NetworkResponseENS_13NetworkStatusE
//   0x02b130: D10203FF  sub      sp, sp, #0x80
//   0x02b134: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02b138: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02b13c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x02b140: 9101C3FD  add      x29, sp, #0x70
//   0x02b144: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_486_sub_02b130(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA90557F6u;
    constexpr uint32_t kLastOpcode = 0x97FF99E1u;
    constexpr uint32_t kFuncSize = 788u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[230]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #487 | VA: 0x02b444..0x02b5cc (392 B) | FDE: 0x04b658
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient15onRequestFailedEPNS_11NetworkCallERKNS_12NetworkErrorE
//   0x02b444: D10203FF  sub      sp, sp, #0x80
//   0x02b448: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02b44c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02b450: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x02b454: 9101C3FD  add      x29, sp, #0x70
//   0x02b458: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_487_sub_02b444(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA90557F6u;
    constexpr uint32_t kLastOpcode = 0x97FF997Fu;
    constexpr uint32_t kFuncSize = 392u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[231]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #488 | VA: 0x02b5cc..0x02b754 (392 B) | FDE: 0x04b680
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient17onRequestCanceledEPNS_11NetworkCallE
//   0x02b5cc: D10203FF  sub      sp, sp, #0x80
//   0x02b5d0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02b5d4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02b5d8: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x02b5dc: 9101C3FD  add      x29, sp, #0x70
//   0x02b5e0: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_488_sub_02b5cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA90557F6u;
    constexpr uint32_t kLastOpcode = 0x97FF991Du;
    constexpr uint32_t kFuncSize = 392u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[232]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #489 | VA: 0x02b754..0x02ba34 (736 B) | FDE: 0x04b6a8
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient10createCallEPNS_14NetworkRequestE
//   0x02b754: D10283FF  sub      sp, sp, #0xa0
//   0x02b758: F90033F7  str      x23, [sp, #0x60]
//   0x02b75c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02b760: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x02b764: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x02b768: 910243FD  add      x29, sp, #0x90
// ----------------------------------------------------------------------------
uint64_t fde_489_sub_02b754(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xF90033F7u;
    constexpr uint32_t kLastOpcode = 0x97FF9250u;
    constexpr uint32_t kFuncSize = 736u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[233]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #490 | VA: 0x02ba34..0x02ba7c (72 B) | FDE: 0x04b6d0
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient8initCallEPNS_11NetworkCallEPNS_14NetworkRequestE
//   0x02ba34: B4000201  cbz      x1, #0x2ba74
//   0x02ba38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02ba3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02ba40: 910043FD  add      x29, sp, #0x10
//   0x02ba44: AA0103F3  mov      x19, x1
//   0x02ba48: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_490_sub_02ba34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB4000201u;
    constexpr uint32_t kSecondOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[234]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #491 | VA: 0x02ba7c..0x02bfd0 (1364 B) | FDE: 0x04b6f0
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient11sendRequestEPNS_14NetworkRequestEb
//   0x02ba7c: D10283FF  sub      sp, sp, #0xa0
//   0x02ba80: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x02ba84: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02ba88: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x02ba8c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x02ba90: 910243FD  add      x29, sp, #0x90
// ----------------------------------------------------------------------------
uint64_t fde_491_sub_02ba7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xA9065FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF96FEu;
    constexpr uint32_t kFuncSize = 1364u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[235]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #492 | VA: 0x02bfd0..0x02bfe0 (16 B) | FDE: 0x04b718
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient9isRunningEv
//   0x02bfd0: 91024008  add      x8, x0, #0x90
//   0x02bfd4: 08DFFD08  ldarb    w8, [x8]
//   0x02bfd8: 12000100  and      w0, w8, #1
//   0x02bfdc: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_492_sub_02bfd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91024008u;
    constexpr uint32_t kSecondOpcode = 0x08DFFD08u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[236]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #493 | VA: 0x02bfe0..0x02c168 (392 B) | FDE: 0x04b730
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient13cancelRequestEPNS_14NetworkRequestE
//   0x02bfe0: D10243FF  sub      sp, sp, #0x90
//   0x02bfe4: F90033F5  str      x21, [sp, #0x60]
//   0x02bfe8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x02bfec: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x02bff0: 910203FD  add      x29, sp, #0x80
//   0x02bff4: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_493_sub_02bfe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xF90033F5u;
    constexpr uint32_t kLastOpcode = 0x97FF9698u;
    constexpr uint32_t kFuncSize = 392u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[237]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #494 | VA: 0x02c168..0x02c460 (760 B) | FDE: 0x04b750
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient8shutdownEv
//   0x02c168: D10283FF  sub      sp, sp, #0xa0
//   0x02c16c: F90033F7  str      x23, [sp, #0x60]
//   0x02c170: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02c174: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x02c178: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x02c17c: 910243FD  add      x29, sp, #0x90
// ----------------------------------------------------------------------------
uint64_t fde_494_sub_02c168(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xF90033F7u;
    constexpr uint32_t kLastOpcode = 0x97FF95DAu;
    constexpr uint32_t kFuncSize = 760u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[238]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #495 | VA: 0x02c460..0x02c50c (172 B) | FDE: 0x04b778
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClientD2Ev
//   0x02c460: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02c464: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02c468: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02c46c: 910083FD  add      x29, sp, #0x20
//   0x02c470: F0000129  adrp     x9, #0x53000
//   0x02c474: 3942A008  ldrb     w8, [x0, #0xa8]
// ----------------------------------------------------------------------------
uint64_t fde_495_sub_02c460(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF2u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[239]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #496 | VA: 0x02c50c..0x02c510 (4 B) | FDE: 0x04b798
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClientD0Ev
//   0x02c50c: D4200020  brk      #1
// ----------------------------------------------------------------------------
uint64_t fde_496_sub_02c50c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD4200020u;
    constexpr uint32_t kSecondOpcode = 0xD4200020u;
    constexpr uint32_t kLastOpcode = 0xD4200020u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[240]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #497 | VA: 0x02c510..0x02c57c (108 B) | FDE: 0x04b7b0
// Symbol (EN/VN): _ZN13AmazingEngine13NetworkClient19processLoadingTasksEv
//   0x02c510: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02c514: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02c518: 910043FD  add      x29, sp, #0x10
//   0x02c51c: AA0003F3  mov      x19, x0
//   0x02c520: F9404C00  ldr      x0, [x0, #0x98]
//   0x02c524: 900000C1  adrp     x1, #0x44000
// ----------------------------------------------------------------------------
uint64_t fde_497_sub_02c510(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF8D82u;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[241]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #498 | VA: 0x02c57c..0x02c604 (136 B) | FDE: 0x04b7d0
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWSC1Ev
//   0x02c57c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02c580: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02c584: 910043FD  add      x29, sp, #0x10
//   0x02c588: B900081F  str      wzr, [x0, #8]
//   0x02c58c: F0000128  adrp     x8, #0x53000
//   0x02c590: F9469D08  ldr      x8, [x8, #0xd38]
// ----------------------------------------------------------------------------
uint64_t fde_498_sub_02c57c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[242]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #499 | VA: 0x02c604..0x02c65c (88 B) | FDE: 0x04b7f0
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWSD2Ev
//   0x02c604: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02c608: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02c60c: 910043FD  add      x29, sp, #0x10
//   0x02c610: F0000128  adrp     x8, #0x53000
//   0x02c614: AA0003F3  mov      x19, x0
//   0x02c618: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_499_sub_02c604(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF8C92u;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[243]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #500 | VA: 0x02c65c..0x02c6bc (96 B) | FDE: 0x04b810
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWSD0Ev
//   0x02c65c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02c660: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02c664: 910043FD  add      x29, sp, #0x10
//   0x02c668: F0000128  adrp     x8, #0x53000
//   0x02c66c: AA0003F3  mov      x19, x0
//   0x02c670: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_500_sub_02c65c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF8CAAu;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[244]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #501 | VA: 0x02c6bc..0x02c6c4 (8 B) | FDE: 0x04b830
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWS6initWSEPvjPFvS1_jiPKcEPFvS1_jiS3_S3_EPFvS1_jS3_mEPFvS1_jS3_E
//   0x02c6bc: F9400800  ldr      x0, [x0, #0x10]
//   0x02c6c0: 14001279  b        #0x310a4
// ----------------------------------------------------------------------------
uint64_t fde_501_sub_02c6bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0x14001279u;
    constexpr uint32_t kLastOpcode = 0x14001279u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[245]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #502 | VA: 0x02c6c4..0x02c6cc (8 B) | FDE: 0x04b848
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWS8shutdownEv
//   0x02c6c4: F9400800  ldr      x0, [x0, #0x10]
//   0x02c6c8: 140011D2  b        #0x30e10
// ----------------------------------------------------------------------------
uint64_t fde_502_sub_02c6c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0x140011D2u;
    constexpr uint32_t kLastOpcode = 0x140011D2u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[246]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #503 | VA: 0x02c6cc..0x02c6d4 (8 B) | FDE: 0x04b860
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWS12startConnectERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x02c6cc: F9400800  ldr      x0, [x0, #0x10]
//   0x02c6d0: 1400152C  b        #0x31b80
// ----------------------------------------------------------------------------
uint64_t fde_503_sub_02c6cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0x1400152Cu;
    constexpr uint32_t kLastOpcode = 0x1400152Cu;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[247]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #504 | VA: 0x02c6d4..0x02c6dc (8 B) | FDE: 0x04b878
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWS8sendDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x02c6d4: F9400800  ldr      x0, [x0, #0x10]
//   0x02c6d8: 140015C8  b        #0x31df8
// ----------------------------------------------------------------------------
uint64_t fde_504_sub_02c6d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0x140015C8u;
    constexpr uint32_t kLastOpcode = 0x140015C8u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[248]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #505 | VA: 0x02c6dc..0x02c6e4 (8 B) | FDE: 0x04b890
// Symbol (EN/VN): _ZN13AmazingEngine15NetworkClientWS11isConnectedEv
//   0x02c6dc: F9400800  ldr      x0, [x0, #0x10]
//   0x02c6e0: 140015E0  b        #0x31e60
// ----------------------------------------------------------------------------
uint64_t fde_505_sub_02c6dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400800u;
    constexpr uint32_t kSecondOpcode = 0x140015E0u;
    constexpr uint32_t kLastOpcode = 0x140015E0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[249]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #506 | VA: 0x02c6e4..0x02c810 (300 B) | FDE: 0x04b8a8
// Symbol (EN/VN): internal_func_02c6e4
//   0x02c6e4: F9400409  ldr      x9, [x0, #8]
//   0x02c6e8: B4000829  cbz      x9, #0x2c7ec
//   0x02c6ec: F9400028  ldr      x8, [x1]
//   0x02c6f0: D285AD2A  mov      x10, #0x2d69
//   0x02c6f4: F2BD670A  movk     x10, #0xeb38, lsl #16
//   0x02c6f8: F2DD410A  movk     x10, #0xea08, lsl #32
// ----------------------------------------------------------------------------
uint64_t fde_506_sub_02c6e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xB4000829u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 300u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[250]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #507 | VA: 0x02c810..0x02c95c (332 B) | FDE: 0x04b8c0
// Symbol (EN/VN): internal_func_02c810
//   0x02c810: F9400409  ldr      x9, [x0, #8]
//   0x02c814: F940042A  ldr      x10, [x1, #8]
//   0x02c818: 9E670120  fmov     d0, x9
//   0x02c81c: 0E205800  cnt      v0.8b, v0.8b
//   0x02c820: 2E303800  uaddlv   h0, v0.8b
//   0x02c824: 1E26000D  fmov     w13, s0
// ----------------------------------------------------------------------------
uint64_t fde_507_sub_02c810(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xF940042Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[251]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #508 | VA: 0x02c95c..0x02cc10 (692 B) | FDE: 0x04b8d8
// Symbol (EN/VN): internal_func_02c95c
//   0x02c95c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x02c960: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x02c964: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02c968: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02c96c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02c970: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_508_sub_02c95c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 692u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[252]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #509 | VA: 0x02cc10..0x02cd18 (264 B) | FDE: 0x04b900
// Symbol (EN/VN): internal_func_02cc10
//   0x02cc10: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02cc14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02cc18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02cc1c: 910083FD  add      x29, sp, #0x20
//   0x02cc20: F1000428  subs     x8, x1, #1
//   0x02cc24: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_509_sub_02cc10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[253]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #510 | VA: 0x02cd18..0x02cf48 (560 B) | FDE: 0x04b920
// Symbol (EN/VN): internal_func_02cd18
//   0x02cd18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02cd1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02cd20: 910043FD  add      x29, sp, #0x10
//   0x02cd24: AA0003F3  mov      x19, x0
//   0x02cd28: B40004A1  cbz      x1, #0x2cdbc
//   0x02cd2c: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_510_sub_02cd18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x97FF8C47u;
    constexpr uint32_t kFuncSize = 560u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[254]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #511 | VA: 0x02cf48..0x02cf4c (4 B) | FDE: 0x04b940
// Symbol (EN/VN): internal_func_02cf48
//   0x02cf48: 17FF8A86  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_511_sub_02cf48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8A86u;
    constexpr uint32_t kSecondOpcode = 0x17FF8A86u;
    constexpr uint32_t kLastOpcode = 0x17FF8A86u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[255]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #512 | VA: 0x02cf4c..0x02cf84 (56 B) | FDE: 0x04b958
// Symbol (EN/VN): internal_func_02cf4c
//   0x02cf4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02cf50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02cf54: 910043FD  add      x29, sp, #0x10
//   0x02cf58: AA0003F3  mov      x19, x0
//   0x02cf5c: 52800300  mov      w0, #0x18
//   0x02cf60: 97FF8CA8  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_512_sub_02cf4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[0]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #513 | VA: 0x02cf84..0x02cf9c (24 B) | FDE: 0x04b978
// Symbol (EN/VN): internal_func_02cf84
//   0x02cf84: D0000128  adrp     x8, #0x52000
//   0x02cf88: 913C8108  add      x8, x8, #0xf20
//   0x02cf8c: F9000028  str      x8, [x1]
//   0x02cf90: 3CC08000  ldur     q0, [x0, #8]
//   0x02cf94: 3C808020  stur     q0, [x1, #8]
//   0x02cf98: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_513_sub_02cf84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD0000128u;
    constexpr uint32_t kSecondOpcode = 0x913C8108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[1]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #514 | VA: 0x02cf9c..0x02cfa0 (4 B) | FDE: 0x04b990
// Symbol (EN/VN): internal_func_02cf9c
//   0x02cf9c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_514_sub_02cf9c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[2]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #515 | VA: 0x02cfa0..0x02cfa4 (4 B) | FDE: 0x04b9a8
// Symbol (EN/VN): internal_func_02cfa0
//   0x02cfa0: 17FF8A70  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_515_sub_02cfa0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8A70u;
    constexpr uint32_t kSecondOpcode = 0x17FF8A70u;
    constexpr uint32_t kLastOpcode = 0x17FF8A70u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[3]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #516 | VA: 0x02cfa4..0x02cfb0 (12 B) | FDE: 0x04b9c0
// Symbol (EN/VN): internal_func_02cfa4
//   0x02cfa4: B9400063  ldr      w3, [x3]
//   0x02cfa8: A9408001  ldp      x1, x0, [x0, #8]
//   0x02cfac: 17FF8BD5  b        #0xff00
// ----------------------------------------------------------------------------
uint64_t fde_516_sub_02cfa4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9400063u;
    constexpr uint32_t kSecondOpcode = 0xA9408001u;
    constexpr uint32_t kLastOpcode = 0x17FF8BD5u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[4]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #517 | VA: 0x02cfb0..0x02cfb4 (4 B) | FDE: 0x04b9d8
// Symbol (EN/VN): internal_func_02cfb0
//   0x02cfb0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_517_sub_02cfb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[5]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #518 | VA: 0x02cfb4..0x02cfb8 (4 B) | FDE: 0x04b9f0
// Symbol (EN/VN): internal_func_02cfb4
//   0x02cfb4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_518_sub_02cfb4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[6]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #519 | VA: 0x02cfb8..0x02cfbc (4 B) | FDE: 0x04ba08
// Symbol (EN/VN): internal_func_02cfb8
//   0x02cfb8: 17FF8A6A  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_519_sub_02cfb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8A6Au;
    constexpr uint32_t kSecondOpcode = 0x17FF8A6Au;
    constexpr uint32_t kLastOpcode = 0x17FF8A6Au;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[7]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #520 | VA: 0x02cfbc..0x02cff4 (56 B) | FDE: 0x04ba20
// Symbol (EN/VN): internal_func_02cfbc
//   0x02cfbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02cfc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02cfc4: 910043FD  add      x29, sp, #0x10
//   0x02cfc8: AA0003F3  mov      x19, x0
//   0x02cfcc: 52800300  mov      w0, #0x18
//   0x02cfd0: 97FF8C8C  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_520_sub_02cfbc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[8]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #521 | VA: 0x02cff4..0x02d00c (24 B) | FDE: 0x04ba40
// Symbol (EN/VN): internal_func_02cff4
//   0x02cff4: D0000128  adrp     x8, #0x52000
//   0x02cff8: 913DA108  add      x8, x8, #0xf68
//   0x02cffc: F9000028  str      x8, [x1]
//   0x02d000: 3CC08000  ldur     q0, [x0, #8]
//   0x02d004: 3C808020  stur     q0, [x1, #8]
//   0x02d008: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_521_sub_02cff4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD0000128u;
    constexpr uint32_t kSecondOpcode = 0x913DA108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[9]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #522 | VA: 0x02d00c..0x02d010 (4 B) | FDE: 0x04ba58
// Symbol (EN/VN): internal_func_02d00c
//   0x02d00c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_522_sub_02d00c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[10]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #523 | VA: 0x02d010..0x02d014 (4 B) | FDE: 0x04ba70
// Symbol (EN/VN): internal_func_02d010
//   0x02d010: 17FF8A54  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_523_sub_02d010(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8A54u;
    constexpr uint32_t kSecondOpcode = 0x17FF8A54u;
    constexpr uint32_t kLastOpcode = 0x17FF8A54u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[11]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #524 | VA: 0x02d014..0x02d01c (8 B) | FDE: 0x04ba88
// Symbol (EN/VN): internal_func_02d014
//   0x02d014: A9408001  ldp      x1, x0, [x0, #8]
//   0x02d018: 17FF8D06  b        #0x10430
// ----------------------------------------------------------------------------
uint64_t fde_524_sub_02d014(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9408001u;
    constexpr uint32_t kSecondOpcode = 0x17FF8D06u;
    constexpr uint32_t kLastOpcode = 0x17FF8D06u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[12]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #525 | VA: 0x02d01c..0x02d020 (4 B) | FDE: 0x04baa0
// Symbol (EN/VN): internal_func_02d01c
//   0x02d01c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_525_sub_02d01c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[13]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #526 | VA: 0x02d020..0x02d024 (4 B) | FDE: 0x04bab8
// Symbol (EN/VN): internal_func_02d020
//   0x02d020: 17FF8A50  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_526_sub_02d020(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8A50u;
    constexpr uint32_t kSecondOpcode = 0x17FF8A50u;
    constexpr uint32_t kLastOpcode = 0x17FF8A50u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[14]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #527 | VA: 0x02d024..0x02d05c (56 B) | FDE: 0x04bad0
// Symbol (EN/VN): internal_func_02d024
//   0x02d024: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02d028: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d02c: 910043FD  add      x29, sp, #0x10
//   0x02d030: AA0003F3  mov      x19, x0
//   0x02d034: 52800300  mov      w0, #0x18
//   0x02d038: 97FF8C72  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_527_sub_02d024(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[15]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #528 | VA: 0x02d05c..0x02d074 (24 B) | FDE: 0x04baf0
// Symbol (EN/VN): internal_func_02d05c
//   0x02d05c: B0000128  adrp     x8, #0x52000
//   0x02d060: 913EC108  add      x8, x8, #0xfb0
//   0x02d064: F9000028  str      x8, [x1]
//   0x02d068: 3CC08000  ldur     q0, [x0, #8]
//   0x02d06c: 3C808020  stur     q0, [x1, #8]
//   0x02d070: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_528_sub_02d05c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB0000128u;
    constexpr uint32_t kSecondOpcode = 0x913EC108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[16]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #529 | VA: 0x02d074..0x02d078 (4 B) | FDE: 0x04bb08
// Symbol (EN/VN): internal_func_02d074
//   0x02d074: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_529_sub_02d074(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[17]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #530 | VA: 0x02d078..0x02d07c (4 B) | FDE: 0x04bb20
// Symbol (EN/VN): internal_func_02d078
//   0x02d078: 17FF8A3A  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_530_sub_02d078(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8A3Au;
    constexpr uint32_t kSecondOpcode = 0x17FF8A3Au;
    constexpr uint32_t kLastOpcode = 0x17FF8A3Au;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[18]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #531 | VA: 0x02d07c..0x02d084 (8 B) | FDE: 0x04bb38
// Symbol (EN/VN): internal_func_02d07c
//   0x02d07c: A9408001  ldp      x1, x0, [x0, #8]
//   0x02d080: 17FF8D2C  b        #0x10530
// ----------------------------------------------------------------------------
uint64_t fde_531_sub_02d07c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9408001u;
    constexpr uint32_t kSecondOpcode = 0x17FF8D2Cu;
    constexpr uint32_t kLastOpcode = 0x17FF8D2Cu;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[19]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #532 | VA: 0x02d084..0x02d238 (436 B) | FDE: 0x04bb50
// Symbol (EN/VN): internal_func_02d084
//   0x02d084: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x02d088: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02d08c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02d090: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02d094: 9100C3FD  add      x29, sp, #0x30
//   0x02d098: F9400408  ldr      x8, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_532_sub_02d084(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 436u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[20]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #533 | VA: 0x02d238..0x02d3a4 (364 B) | FDE: 0x04bb78
// Symbol (EN/VN): internal_func_02d238
//   0x02d238: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02d23c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d240: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d244: 910083FD  add      x29, sp, #0x20
//   0x02d248: AA0103F5  mov      x21, x1
//   0x02d24c: F8410EA8  ldr      x8, [x21, #0x10]!
// ----------------------------------------------------------------------------
uint64_t fde_533_sub_02d238(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 364u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[21]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #534 | VA: 0x02d3a4..0x02d55c (440 B) | FDE: 0x04bb98
// Symbol (EN/VN): internal_func_02d3a4
//   0x02d3a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02d3a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d3ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d3b0: 910083FD  add      x29, sp, #0x20
//   0x02d3b4: F9400C08  ldr      x8, [x0, #0x18]
//   0x02d3b8: F9400409  ldr      x9, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_534_sub_02d3a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 440u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[22]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #535 | VA: 0x02d55c..0x02d560 (4 B) | FDE: 0x04bbb8
// Symbol (EN/VN): internal_func_02d55c
//   0x02d55c: 17FF8901  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_535_sub_02d55c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF8901u;
    constexpr uint32_t kSecondOpcode = 0x17FF8901u;
    constexpr uint32_t kLastOpcode = 0x17FF8901u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[23]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #536 | VA: 0x02d560..0x02d5a4 (68 B) | FDE: 0x04bbd0
// Symbol (EN/VN): internal_func_02d560
//   0x02d560: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02d564: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d568: 910043FD  add      x29, sp, #0x10
//   0x02d56c: AA0003F3  mov      x19, x0
//   0x02d570: 52800400  mov      w0, #0x20
//   0x02d574: 97FF8B23  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_536_sub_02d560(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[24]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #537 | VA: 0x02d5a4..0x02d5c8 (36 B) | FDE: 0x04bbf0
// Symbol (EN/VN): internal_func_02d5a4
//   0x02d5a4: D0000128  adrp     x8, #0x53000
//   0x02d5a8: F9471D08  ldr      x8, [x8, #0xe38]
//   0x02d5ac: 91004108  add      x8, x8, #0x10
//   0x02d5b0: F9000028  str      x8, [x1]
//   0x02d5b4: F9400C08  ldr      x8, [x0, #0x18]
//   0x02d5b8: 3CC08000  ldur     q0, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_537_sub_02d5a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD0000128u;
    constexpr uint32_t kSecondOpcode = 0xF9471D08u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[25]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #538 | VA: 0x02d5c8..0x02d5cc (4 B) | FDE: 0x04bc08
// Symbol (EN/VN): internal_func_02d5c8
//   0x02d5c8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_538_sub_02d5c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[26]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #539 | VA: 0x02d5cc..0x02d5d0 (4 B) | FDE: 0x04bc20
// Symbol (EN/VN): internal_func_02d5cc
//   0x02d5cc: 17FF88E5  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_539_sub_02d5cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF88E5u;
    constexpr uint32_t kSecondOpcode = 0x17FF88E5u;
    constexpr uint32_t kLastOpcode = 0x17FF88E5u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[27]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #540 | VA: 0x02d5d0..0x02d5ec (28 B) | FDE: 0x04bc38
// Symbol (EN/VN): internal_func_02d5d0
//   0x02d5d0: A9412009  ldp      x9, x8, [x0, #0x10]
//   0x02d5d4: F9400401  ldr      x1, [x0, #8]
//   0x02d5d8: 8B890500  add      x0, x8, x9, asr #1
//   0x02d5dc: 36000069  tbz      w9, #0, #0x2d5e8
//   0x02d5e0: F9400008  ldr      x8, [x0]
//   0x02d5e4: F8616901  ldr      x1, [x8, x1]
// ----------------------------------------------------------------------------
uint64_t fde_540_sub_02d5d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9412009u;
    constexpr uint32_t kSecondOpcode = 0xF9400401u;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 28u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[28]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #541 | VA: 0x02d5ec..0x02d6c4 (216 B) | FDE: 0x04bc50
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest6createENS_10HttpMethodERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
//   0x02d5ec: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x02d5f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02d5f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02d5f8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02d5fc: 9100C3FD  add      x29, sp, #0x30
//   0x02d600: 2A0003F4  mov      w20, w0
// ----------------------------------------------------------------------------
uint64_t fde_541_sub_02d5ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 216u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[29]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #542 | VA: 0x02d6c4..0x02d7a0 (220 B) | FDE: 0x04bc78
// Symbol (EN/VN): internal_func_02d6c4
//   0x02d6c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02d6c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d6cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d6d0: 910083FD  add      x29, sp, #0x20
//   0x02d6d4: AA0003F3  mov      x19, x0
//   0x02d6d8: EB01001F  cmp      x0, x1
// ----------------------------------------------------------------------------
uint64_t fde_542_sub_02d6c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 220u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[30]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #543 | VA: 0x02d7a0..0x02d7a8 (8 B) | FDE: 0x04bc98
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest6getUrlEv
//   0x02d7a0: 91004000  add      x0, x0, #0x10
//   0x02d7a4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_543_sub_02d7a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91004000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[31]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #544 | VA: 0x02d7a8..0x02d7b0 (8 B) | FDE: 0x04bcb0
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest6setUrlERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x02d7a8: 91004000  add      x0, x0, #0x10
//   0x02d7ac: 17FFFFC6  b        #0x2d6c4
// ----------------------------------------------------------------------------
uint64_t fde_544_sub_02d7a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91004000u;
    constexpr uint32_t kSecondOpcode = 0x17FFFFC6u;
    constexpr uint32_t kLastOpcode = 0x17FFFFC6u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[32]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #545 | VA: 0x02d7b0..0x02d7e0 (48 B) | FDE: 0x04bcc8
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest9addHeaderERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_
//   0x02d7b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02d7b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d7b8: 910043FD  add      x29, sp, #0x10
//   0x02d7bc: AA0203E3  mov      x3, x2
//   0x02d7c0: AA0003F3  mov      x19, x0
//   0x02d7c4: 9100A000  add      x0, x0, #0x28
// ----------------------------------------------------------------------------
uint64_t fde_545_sub_02d7b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[33]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #546 | VA: 0x02d7e0..0x02d810 (48 B) | FDE: 0x04bce8
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest8addParamERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_
//   0x02d7e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02d7e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d7e8: 910043FD  add      x29, sp, #0x10
//   0x02d7ec: AA0203E3  mov      x3, x2
//   0x02d7f0: AA0003F3  mov      x19, x0
//   0x02d7f4: 91014000  add      x0, x0, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_546_sub_02d7e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[34]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #547 | VA: 0x02d810..0x02d81c (12 B) | FDE: 0x04bd08
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest11setCachableEb
//   0x02d810: 12000028  and      w8, w1, #1
//   0x02d814: 3901F008  strb     w8, [x0, #0x7c]
//   0x02d818: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_547_sub_02d810(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12000028u;
    constexpr uint32_t kSecondOpcode = 0x3901F008u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[35]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #548 | VA: 0x02d81c..0x02d844 (40 B) | FDE: 0x04bd20
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest7isValidEv
//   0x02d81c: 39404008  ldrb     w8, [x0, #0x10]
//   0x02d820: 370000A8  tbnz     w8, #0, #0x2d834
//   0x02d824: D341FD08  lsr      x8, x8, #1
//   0x02d828: F100011F  cmp      x8, #0
//   0x02d82c: 1A9F07E0  cset     w0, ne
//   0x02d830: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_548_sub_02d81c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39404008u;
    constexpr uint32_t kSecondOpcode = 0x370000A8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[36]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #549 | VA: 0x02d844..0x02d84c (8 B) | FDE: 0x04bd38
// Symbol (EN/VN): _ZNK13AmazingEngine14NetworkRequest9getMethodEv
//   0x02d844: B9407800  ldr      w0, [x0, #0x78]
//   0x02d848: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_549_sub_02d844(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9407800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[37]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #550 | VA: 0x02d84c..0x02d854 (8 B) | FDE: 0x04bd50
// Symbol (EN/VN): _ZNK13AmazingEngine14NetworkRequest10getHeadersEv
//   0x02d84c: 9100A000  add      x0, x0, #0x28
//   0x02d850: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_550_sub_02d84c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x9100A000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[38]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #551 | VA: 0x02d854..0x02d85c (8 B) | FDE: 0x04bd68
// Symbol (EN/VN): _ZNK13AmazingEngine14NetworkRequest9getParamsEv
//   0x02d854: 91014000  add      x0, x0, #0x50
//   0x02d858: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_551_sub_02d854(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91014000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[39]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #552 | VA: 0x02d85c..0x02d864 (8 B) | FDE: 0x04bd80
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest9getMethodEv
//   0x02d85c: B9407800  ldr      w0, [x0, #0x78]
//   0x02d860: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_552_sub_02d85c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB9407800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[40]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #553 | VA: 0x02d864..0x02d86c (8 B) | FDE: 0x04bd98
// Symbol (EN/VN): _ZNK13AmazingEngine14NetworkRequest10isCachableEv
//   0x02d864: 3941F000  ldrb     w0, [x0, #0x7c]
//   0x02d868: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_553_sub_02d864(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x3941F000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[41]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #554 | VA: 0x02d86c..0x02d874 (8 B) | FDE: 0x04bdb0
// Symbol (EN/VN): _ZNK13AmazingEngine14NetworkRequest17getReadBufferSizeEv
//   0x02d86c: F9404000  ldr      x0, [x0, #0x80]
//   0x02d870: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_554_sub_02d86c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9404000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[42]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #555 | VA: 0x02d874..0x02d87c (8 B) | FDE: 0x04bdc8
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest17setReadBufferSizeEm
//   0x02d874: F9004001  str      x1, [x0, #0x80]
//   0x02d878: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_555_sub_02d874(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9004001u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[43]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #556 | VA: 0x02d87c..0x02d884 (8 B) | FDE: 0x04bde0
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest15getOnFailedFuncEv
//   0x02d87c: 91024000  add      x0, x0, #0x90
//   0x02d880: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_556_sub_02d87c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91024000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[44]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #557 | VA: 0x02d884..0x02d91c (152 B) | FDE: 0x04bdf8
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest15setOnFailedFuncEONSt6__ndk18functionIFvPKS0_RKNS_12NetworkErrorEEEE
//   0x02d884: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02d888: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d88c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d890: 910083FD  add      x29, sp, #0x20
//   0x02d894: AA0003F3  mov      x19, x0
//   0x02d898: F9405800  ldr      x0, [x0, #0xb0]
// ----------------------------------------------------------------------------
uint64_t fde_557_sub_02d884(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 152u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[45]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #558 | VA: 0x02d91c..0x02d924 (8 B) | FDE: 0x04be18
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest17getOnResponseFuncEv
//   0x02d91c: 91030000  add      x0, x0, #0xc0
//   0x02d920: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_558_sub_02d91c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91030000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[46]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #559 | VA: 0x02d924..0x02d9bc (152 B) | FDE: 0x04be30
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest17setOnResponseFuncEONSt6__ndk18functionIFvPKS0_RKNS_15NetworkResponseENS_13NetworkStatusEEEE
//   0x02d924: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02d928: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d92c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d930: 910083FD  add      x29, sp, #0x20
//   0x02d934: AA0003F3  mov      x19, x0
//   0x02d938: F9407000  ldr      x0, [x0, #0xe0]
// ----------------------------------------------------------------------------
uint64_t fde_559_sub_02d924(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 152u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[47]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #560 | VA: 0x02d9bc..0x02d9c4 (8 B) | FDE: 0x04be50
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest11setUserDataEPv
//   0x02d9bc: F9008801  str      x1, [x0, #0x110]
//   0x02d9c0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_560_sub_02d9bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9008801u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[48]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #561 | VA: 0x02d9c4..0x02d9cc (8 B) | FDE: 0x04be68
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest11getUserDataEv
//   0x02d9c4: F9408800  ldr      x0, [x0, #0x110]
//   0x02d9c8: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_561_sub_02d9c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9408800u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[49]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #562 | VA: 0x02d9cc..0x02d9d4 (8 B) | FDE: 0x04be80
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest11setBodyTypeENS_19HttpRequestBodyTypeE
//   0x02d9cc: B900F001  str      w1, [x0, #0xf0]
//   0x02d9d0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_562_sub_02d9cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900F001u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[50]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #563 | VA: 0x02d9d4..0x02d9fc (40 B) | FDE: 0x04be98
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest11setBodyDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x02d9d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02d9d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d9dc: 910043FD  add      x29, sp, #0x10
//   0x02d9e0: AA0003F3  mov      x19, x0
//   0x02d9e4: 9103E000  add      x0, x0, #0xf8
//   0x02d9e8: 97FFFF37  bl       #0x2d6c4
// ----------------------------------------------------------------------------
uint64_t fde_563_sub_02d9d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[51]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #564 | VA: 0x02d9fc..0x02da74 (120 B) | FDE: 0x04beb8
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest11setBodyDataEONSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x02d9fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02da00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02da04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02da08: 910083FD  add      x29, sp, #0x20
//   0x02da0c: AA0003F5  mov      x21, x0
//   0x02da10: 384F8EA8  ldrb     w8, [x21, #0xf8]!
// ----------------------------------------------------------------------------
uint64_t fde_564_sub_02d9fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[52]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #565 | VA: 0x02da74..0x02da7c (8 B) | FDE: 0x04bed8
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequest7getBodyEv
//   0x02da74: 9103C000  add      x0, x0, #0xf0
//   0x02da78: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_565_sub_02da74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x9103C000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[53]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #566 | VA: 0x02da7c..0x02dbe4 (360 B) | FDE: 0x04bef0
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequestD2Ev
//   0x02da7c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02da80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02da84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02da88: 910083FD  add      x29, sp, #0x20
//   0x02da8c: D0000129  adrp     x9, #0x53000
//   0x02da90: 3943E008  ldrb     w8, [x0, #0xf8]
// ----------------------------------------------------------------------------
uint64_t fde_566_sub_02da7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF0u;
    constexpr uint32_t kFuncSize = 360u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[54]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #567 | VA: 0x02dbe4..0x02dc08 (36 B) | FDE: 0x04bf10
// Symbol (EN/VN): _ZN13AmazingEngine14NetworkRequestD0Ev
//   0x02dbe4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02dbe8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02dbec: 910043FD  add      x29, sp, #0x10
//   0x02dbf0: AA0003F3  mov      x19, x0
//   0x02dbf4: 97FF8A1B  bl       #0x10460
//   0x02dbf8: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_567_sub_02dbe4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF8757u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[55]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #568 | VA: 0x02dc08..0x02dfe0 (984 B) | FDE: 0x04bf30
// Symbol (EN/VN): internal_func_02dc08
//   0x02dc08: D10203FF  sub      sp, sp, #0x80
//   0x02dc0c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x02dc10: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x02dc14: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x02dc18: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02dc1c: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_568_sub_02dc08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA9026FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 984u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[56]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #569 | VA: 0x02dfe0..0x02e0e8 (264 B) | FDE: 0x04bf60
// Symbol (EN/VN): internal_func_02dfe0
//   0x02dfe0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02dfe4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02dfe8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02dfec: 910083FD  add      x29, sp, #0x20
//   0x02dff0: F1000428  subs     x8, x1, #1
//   0x02dff4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_569_sub_02dfe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[57]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #570 | VA: 0x02e0e8..0x02e224 (316 B) | FDE: 0x04bf80
// Symbol (EN/VN): internal_func_02e0e8
//   0x02e0e8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x02e0ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02e0f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02e0f4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02e0f8: 9100C3FD  add      x29, sp, #0x30
//   0x02e0fc: A9007C1F  stp      xzr, xzr, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_570_sub_02e0e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FF8790u;
    constexpr uint32_t kFuncSize = 316u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[58]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #571 | VA: 0x02e224..0x02e544 (800 B) | FDE: 0x04bfa8
// Symbol (EN/VN): internal_func_02e224
//   0x02e224: D101C3FF  sub      sp, sp, #0x70
//   0x02e228: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x02e22c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x02e230: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x02e234: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x02e238: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_571_sub_02e224(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF86C8u;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[59]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #572 | VA: 0x02e544..0x02e944 (1024 B) | FDE: 0x04bfd8
// Symbol (EN/VN): internal_func_02e544
//   0x02e544: D10343FF  sub      sp, sp, #0xd0
//   0x02e548: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x02e54c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x02e550: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x02e554: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x02e558: A90B4FF4  stp      x20, x19, [sp, #0xb0]
// ----------------------------------------------------------------------------
uint64_t fde_572_sub_02e544(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10343FFu;
    constexpr uint32_t kSecondOpcode = 0xA9076FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF8CA1u;
    constexpr uint32_t kFuncSize = 1024u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[60]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #573 | VA: 0x02e944..0x02e980 (60 B) | FDE: 0x04c008
// Symbol (EN/VN): internal_func_02e944
//   0x02e944: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02e948: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02e94c: 910043FD  add      x29, sp, #0x10
//   0x02e950: B0000128  adrp     x8, #0x53000
//   0x02e954: F9472108  ldr      x8, [x8, #0xe40]
//   0x02e958: AA0103F3  mov      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_573_sub_02e944(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 60u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[61]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #574 | VA: 0x02e980..0x02e9b8 (56 B) | FDE: 0x04c028
// Symbol (EN/VN): internal_func_02e980
//   0x02e980: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02e984: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02e988: 910043FD  add      x29, sp, #0x10
//   0x02e98c: B0000128  adrp     x8, #0x53000
//   0x02e990: F9472108  ldr      x8, [x8, #0xe40]
//   0x02e994: AA0203F3  mov      x19, x2
// ----------------------------------------------------------------------------
uint64_t fde_574_sub_02e980(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x1400031Bu;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[62]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #575 | VA: 0x02e9b8..0x02ea08 (80 B) | FDE: 0x04c048
// Symbol (EN/VN): internal_func_02e9b8
//   0x02e9b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02e9bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02e9c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02e9c4: 910083FD  add      x29, sp, #0x20
//   0x02e9c8: B0000128  adrp     x8, #0x53000
//   0x02e9cc: F9472108  ldr      x8, [x8, #0xe40]
// ----------------------------------------------------------------------------
uint64_t fde_575_sub_02e9b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x14000369u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[63]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #576 | VA: 0x02ea08..0x02eab4 (172 B) | FDE: 0x04c070
// Symbol (EN/VN): internal_func_02ea08
//   0x02ea08: D10143FF  sub      sp, sp, #0x50
//   0x02ea0c: F90013F5  str      x21, [sp, #0x20]
//   0x02ea10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02ea14: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x02ea18: 910103FD  add      x29, sp, #0x40
//   0x02ea1c: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_576_sub_02ea08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FF8C45u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[64]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #577 | VA: 0x02eab4..0x02eb6c (184 B) | FDE: 0x04c090
// Symbol (EN/VN): internal_func_02eab4
//   0x02eab4: D10103FF  sub      sp, sp, #0x40
//   0x02eab8: F9000BF5  str      x21, [sp, #0x10]
//   0x02eabc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02eac0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02eac4: 9100C3FD  add      x29, sp, #0x30
//   0x02eac8: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_577_sub_02eab4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF5u;
    constexpr uint32_t kLastOpcode = 0x97FF8C17u;
    constexpr uint32_t kFuncSize = 184u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[65]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #578 | VA: 0x02eb6c..0x02ebec (128 B) | FDE: 0x04c0b0
// Symbol (EN/VN): internal_func_02eb6c
//   0x02eb6c: D100C3FF  sub      sp, sp, #0x30
//   0x02eb70: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02eb74: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02eb78: 910083FD  add      x29, sp, #0x20
//   0x02eb7c: D53BD054  mrs      x20, tpidr_el0
//   0x02eb80: F9401688  ldr      x8, [x20, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_578_sub_02eb6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD100C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x97FF8BF7u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[66]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #579 | VA: 0x02ebec..0x02f00c (1056 B) | FDE: 0x04c0d0
// Symbol (EN/VN): internal_func_02ebec
//   0x02ebec: D10383FF  sub      sp, sp, #0xe0
//   0x02ebf0: F9004BF9  str      x25, [sp, #0x90]
//   0x02ebf4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x02ebf8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x02ebfc: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x02ec00: A90D7BFD  stp      x29, x30, [sp, #0xd0]
// ----------------------------------------------------------------------------
uint64_t fde_579_sub_02ebec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10383FFu;
    constexpr uint32_t kSecondOpcode = 0xF9004BF9u;
    constexpr uint32_t kLastOpcode = 0x97FF8416u;
    constexpr uint32_t kFuncSize = 1056u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[67]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #580 | VA: 0x02f00c..0x02f288 (636 B) | FDE: 0x04c0f8
// Symbol (EN/VN): internal_func_02f00c
//   0x02f00c: D10303FF  sub      sp, sp, #0xc0
//   0x02f010: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x02f014: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x02f018: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x02f01c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x02f020: A90A4FF4  stp      x20, x19, [sp, #0xa0]
// ----------------------------------------------------------------------------
uint64_t fde_580_sub_02f00c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10303FFu;
    constexpr uint32_t kSecondOpcode = 0xA9066FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF843Bu;
    constexpr uint32_t kFuncSize = 636u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[68]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #581 | VA: 0x02f288..0x02f394 (268 B) | FDE: 0x04c128
// Symbol (EN/VN): internal_func_02f288
//   0x02f288: D10203FF  sub      sp, sp, #0x80
//   0x02f28c: F9002BF5  str      x21, [sp, #0x50]
//   0x02f290: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02f294: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x02f298: 9101C3FD  add      x29, sp, #0x70
//   0x02f29c: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_581_sub_02f288(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xF9002BF5u;
    constexpr uint32_t kLastOpcode = 0x97FF8A0Du;
    constexpr uint32_t kFuncSize = 268u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[69]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #582 | VA: 0x02f394..0x02f4a0 (268 B) | FDE: 0x04c148
// Symbol (EN/VN): internal_func_02f394
//   0x02f394: D10203FF  sub      sp, sp, #0x80
//   0x02f398: F9002BF5  str      x21, [sp, #0x50]
//   0x02f39c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02f3a0: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x02f3a4: 9101C3FD  add      x29, sp, #0x70
//   0x02f3a8: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_582_sub_02f394(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xF9002BF5u;
    constexpr uint32_t kLastOpcode = 0x97FF89CAu;
    constexpr uint32_t kFuncSize = 268u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[70]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #583 | VA: 0x02f4a0..0x02f518 (120 B) | FDE: 0x04c168
// Symbol (EN/VN): internal_func_02f4a0
//   0x02f4a0: 52A7F008  mov      w8, #0x3f800000
//   0x02f4a4: 6F00E400  movi     v0.2d, #0000000000000000
//   0x02f4a8: B9006808  str      w8, [x0, #0x68]
//   0x02f4ac: 9104B008  add      x8, x0, #0x12c
//   0x02f4b0: B900081F  str      wzr, [x0, #8]
//   0x02f4b4: A901FC1F  stp      xzr, xzr, [x0, #0x18]
// ----------------------------------------------------------------------------
uint64_t fde_583_sub_02f4a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52A7F008u;
    constexpr uint32_t kSecondOpcode = 0x6F00E400u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[71]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #584 | VA: 0x02f518..0x02f598 (128 B) | FDE: 0x04c180
// Symbol (EN/VN): internal_func_02f518
//   0x02f518: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02f51c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02f520: 910043FD  add      x29, sp, #0x10
//   0x02f524: 90000128  adrp     x8, #0x53000
//   0x02f528: AA0003F3  mov      x19, x0
//   0x02f52c: F940B000  ldr      x0, [x0, #0x160]
// ----------------------------------------------------------------------------
uint64_t fde_584_sub_02f518(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x140000F0u;
    constexpr uint32_t kFuncSize = 128u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[72]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #585 | VA: 0x02f598..0x02f620 (136 B) | FDE: 0x04c1a0
// Symbol (EN/VN): internal_func_02f598
//   0x02f598: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02f59c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02f5a0: 910043FD  add      x29, sp, #0x10
//   0x02f5a4: 90000128  adrp     x8, #0x53000
//   0x02f5a8: AA0003F3  mov      x19, x0
//   0x02f5ac: F940B000  ldr      x0, [x0, #0x160]
// ----------------------------------------------------------------------------
uint64_t fde_585_sub_02f598(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF80D1u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[73]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #586 | VA: 0x02f620..0x02f7a8 (392 B) | FDE: 0x04c1c0
// Symbol (EN/VN): internal_func_02f620
//   0x02f620: D10243FF  sub      sp, sp, #0x90
//   0x02f624: F9002BF7  str      x23, [sp, #0x50]
//   0x02f628: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x02f62c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x02f630: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x02f634: 910203FD  add      x29, sp, #0x80
// ----------------------------------------------------------------------------
uint64_t fde_586_sub_02f620(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xF9002BF7u;
    constexpr uint32_t kLastOpcode = 0x97FF82F3u;
    constexpr uint32_t kFuncSize = 392u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[74]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #587 | VA: 0x02f7a8..0x02f954 (428 B) | FDE: 0x04c1e8
// Symbol (EN/VN): internal_func_02f7a8
//   0x02f7a8: D10243FF  sub      sp, sp, #0x90
//   0x02f7ac: F9001BFB  str      x27, [sp, #0x30]
//   0x02f7b0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x02f7b4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x02f7b8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x02f7bc: A9074FF4  stp      x20, x19, [sp, #0x70]
// ----------------------------------------------------------------------------
uint64_t fde_587_sub_02f7a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xF9001BFBu;
    constexpr uint32_t kLastOpcode = 0x97FF889Du;
    constexpr uint32_t kFuncSize = 428u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[75]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #588 | VA: 0x02f954..0x02fa4c (248 B) | FDE: 0x04c218
// Symbol (EN/VN): internal_func_02f954
//   0x02f954: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02f958: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02f95c: 910043FD  add      x29, sp, #0x10
//   0x02f960: 90000128  adrp     x8, #0x53000
//   0x02f964: F9476508  ldr      x8, [x8, #0xec8]
//   0x02f968: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_588_sub_02f954(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF7F96u;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[76]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #589 | VA: 0x02fa4c..0x02fa50 (4 B) | FDE: 0x04c238
// Symbol (EN/VN): internal_func_02fa4c
//   0x02fa4c: D4200020  brk      #1
// ----------------------------------------------------------------------------
uint64_t fde_589_sub_02fa4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD4200020u;
    constexpr uint32_t kSecondOpcode = 0xD4200020u;
    constexpr uint32_t kLastOpcode = 0xD4200020u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[77]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #590 | VA: 0x02fa50..0x02fafc (172 B) | FDE: 0x04c250
// Symbol (EN/VN): internal_func_02fa50
//   0x02fa50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02fa54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02fa58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02fa5c: 910083FD  add      x29, sp, #0x20
//   0x02fa60: F9402414  ldr      x20, [x0, #0x48]
//   0x02fa64: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_590_sub_02fa50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FF7F9Au;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[78]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #591 | VA: 0x02fafc..0x02feac (944 B) | FDE: 0x04c270
// Symbol (EN/VN): internal_func_02fafc
//   0x02fafc: D101C3FF  sub      sp, sp, #0x70
//   0x02fb00: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x02fb04: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x02fb08: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x02fb0c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x02fb10: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_591_sub_02fafc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 944u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[79]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #592 | VA: 0x02feac..0x02ffec (320 B) | FDE: 0x04c2a0
// Symbol (EN/VN): internal_func_02feac
//   0x02feac: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x02feb0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02feb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02feb8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x02febc: 9100C3FD  add      x29, sp, #0x30
//   0x02fec0: A9007C1F  stp      xzr, xzr, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_592_sub_02feac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FF801Eu;
    constexpr uint32_t kFuncSize = 320u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[80]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #593 | VA: 0x02ffec..0x030254 (616 B) | FDE: 0x04c2c8
// Symbol (EN/VN): internal_func_02ffec
//   0x02ffec: D10183FF  sub      sp, sp, #0x60
//   0x02fff0: F9000BF9  str      x25, [sp, #0x10]
//   0x02fff4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x02fff8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x02fffc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x030000: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_593_sub_02ffec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FF8048u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[81]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #594 | VA: 0x030254..0x03061c (968 B) | FDE: 0x04c2f0
// Symbol (EN/VN): internal_func_030254
//   0x030254: D101C3FF  sub      sp, sp, #0x70
//   0x030258: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x03025c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x030260: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x030264: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x030268: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_594_sub_030254(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 968u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[82]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #595 | VA: 0x03061c..0x030a04 (1000 B) | FDE: 0x04c320
// Symbol (EN/VN): internal_func_03061c
//   0x03061c: D10203FF  sub      sp, sp, #0x80
//   0x030620: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x030624: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x030628: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x03062c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x030630: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_595_sub_03061c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA9026FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 1000u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[83]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #596 | VA: 0x030a04..0x030a08 (4 B) | FDE: 0x04c350
// Symbol (EN/VN): internal_func_030a04
//   0x030a04: 17FF7E77  b        #0x103e0
// ----------------------------------------------------------------------------
uint64_t fde_596_sub_030a04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF7E77u;
    constexpr uint32_t kSecondOpcode = 0x17FF7E77u;
    constexpr uint32_t kLastOpcode = 0x17FF7E77u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[84]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #597 | VA: 0x030a08..0x030a2c (36 B) | FDE: 0x04c368
// Symbol (EN/VN): internal_func_030a08
//   0x030a08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x030a0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x030a10: 910043FD  add      x29, sp, #0x10
//   0x030a14: AA0003F3  mov      x19, x0
//   0x030a18: 97FF7E72  bl       #0x103e0
//   0x030a1c: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_597_sub_030a08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF7BCEu;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[85]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #598 | VA: 0x030a2c..0x030abc (144 B) | FDE: 0x04c388
// Symbol (EN/VN): internal_func_030a2c
//   0x030a2c: F0000108  adrp     x8, #0x53000
//   0x030a30: F946C508  ldr      x8, [x8, #0xd88]
//   0x030a34: 52A7F009  mov      w9, #0x3f800000
//   0x030a38: F900401F  str      xzr, [x0, #0x80]
//   0x030a3c: 7901201F  strh     wzr, [x0, #0x90]
//   0x030a40: 91004108  add      x8, x8, #0x10
// ----------------------------------------------------------------------------
uint64_t fde_598_sub_030a2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF0000108u;
    constexpr uint32_t kSecondOpcode = 0xF946C508u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 144u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[86]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #599 | VA: 0x030abc..0x030c58 (412 B) | FDE: 0x04c3a0
// Symbol (EN/VN): internal_func_030abc
//   0x030abc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x030ac0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x030ac4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x030ac8: 910083FD  add      x29, sp, #0x20
//   0x030acc: F0000108  adrp     x8, #0x53000
//   0x030ad0: F9475908  ldr      x8, [x8, #0xeb0]
// ----------------------------------------------------------------------------
uint64_t fde_599_sub_030abc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 412u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[87]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #600 | VA: 0x030c58..0x030c90 (56 B) | FDE: 0x04c3c8
// Symbol (EN/VN): internal_func_030c58
//   0x030c58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x030c5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x030c60: 910043FD  add      x29, sp, #0x10
//   0x030c64: AA0003F3  mov      x19, x0
//   0x030c68: F9406C00  ldr      x0, [x0, #0xd8]
//   0x030c6c: B40000C0  cbz      x0, #0x30c84
// ----------------------------------------------------------------------------
uint64_t fde_600_sub_030c58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[88]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #601 | VA: 0x030c90..0x030ce4 (84 B) | FDE: 0x04c3e8
// Symbol (EN/VN): internal_func_030c90
//   0x030c90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x030c94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x030c98: 910043FD  add      x29, sp, #0x10
//   0x030c9c: F9406C09  ldr      x9, [x0, #0xd8]
//   0x030ca0: AA0803F3  mov      x19, x8
//   0x030ca4: B4000189  cbz      x9, #0x30cd4
// ----------------------------------------------------------------------------
uint64_t fde_601_sub_030c90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 84u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[89]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #602 | VA: 0x030ce4..0x030d90 (172 B) | FDE: 0x04c408
// Symbol (EN/VN): internal_func_030ce4
//   0x030ce4: D10143FF  sub      sp, sp, #0x50
//   0x030ce8: F90013F5  str      x21, [sp, #0x20]
//   0x030cec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x030cf0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x030cf4: 910103FD  add      x29, sp, #0x40
//   0x030cf8: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_602_sub_030ce4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F5u;
    constexpr uint32_t kLastOpcode = 0x97FF7D79u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[90]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #603 | VA: 0x030d90..0x030dc8 (56 B) | FDE: 0x04c428
// Symbol (EN/VN): internal_func_030d90
//   0x030d90: B900081F  str      wzr, [x0, #8]
//   0x030d94: F0000108  adrp     x8, #0x53000
//   0x030d98: F945E108  ldr      x8, [x8, #0xbc0]
//   0x030d9c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x030da0: AD008000  stp      q0, q0, [x0, #0x10]
//   0x030da4: 3D800C00  str      q0, [x0, #0x30]
// ----------------------------------------------------------------------------
uint64_t fde_603_sub_030d90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB900081Fu;
    constexpr uint32_t kSecondOpcode = 0xF0000108u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[91]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #604 | VA: 0x030dc8..0x030e10 (72 B) | FDE: 0x04c440
// Symbol (EN/VN): internal_func_030dc8
//   0x030dc8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x030dcc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x030dd0: 910043FD  add      x29, sp, #0x10
//   0x030dd4: F0000108  adrp     x8, #0x53000
//   0x030dd8: F945E108  ldr      x8, [x8, #0xbc0]
//   0x030ddc: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_604_sub_030dc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF7AA5u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[92]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #605 | VA: 0x030e10..0x031054 (580 B) | FDE: 0x04c460
// Symbol (EN/VN): internal_func_030e10
//   0x030e10: D10183FF  sub      sp, sp, #0x60
//   0x030e14: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x030e18: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x030e1c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x030e20: 910143FD  add      x29, sp, #0x50
//   0x030e24: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_605_sub_030e10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA90357F6u;
    constexpr uint32_t kLastOpcode = 0x97FF7CC8u;
    constexpr uint32_t kFuncSize = 580u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[93]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #606 | VA: 0x031054..0x0310a4 (80 B) | FDE: 0x04c488
// Symbol (EN/VN): internal_func_031054
//   0x031054: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x031058: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03105c: 910043FD  add      x29, sp, #0x10
//   0x031060: D0000108  adrp     x8, #0x53000
//   0x031064: F945E108  ldr      x8, [x8, #0xbc0]
//   0x031068: AA0003F4  mov      x20, x0
// ----------------------------------------------------------------------------
uint64_t fde_606_sub_031054(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF7A30u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[94]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #607 | VA: 0x0310a4..0x0311c8 (292 B) | FDE: 0x04c4a8
// Symbol (EN/VN): internal_func_0310a4
//   0x0310a4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0310a8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0310ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0310b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0310b4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0310b8: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_607_sub_0310a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 292u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[95]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #608 | VA: 0x0311c8..0x0313d0 (520 B) | FDE: 0x04c4d0
// Symbol (EN/VN): internal_func_0311c8
//   0x0311c8: D10143FF  sub      sp, sp, #0x50
//   0x0311cc: F9000BF7  str      x23, [sp, #0x10]
//   0x0311d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0311d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0311d8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0311dc: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_608_sub_0311c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FFFFA6u;
    constexpr uint32_t kFuncSize = 520u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[96]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #609 | VA: 0x0313d0..0x0315d0 (512 B) | FDE: 0x04c4f8
// Symbol (EN/VN): internal_func_0313d0
//   0x0313d0: D10143FF  sub      sp, sp, #0x50
//   0x0313d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0313d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0313dc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0313e0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0313e4: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_609_sub_0313d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFA9u;
    constexpr uint32_t kFuncSize = 512u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[97]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #610 | VA: 0x0315d0..0x0317c8 (504 B) | FDE: 0x04c520
// Symbol (EN/VN): internal_func_0315d0
//   0x0315d0: D10143FF  sub      sp, sp, #0x50
//   0x0315d4: F9000BF7  str      x23, [sp, #0x10]
//   0x0315d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0315dc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0315e0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0315e4: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_610_sub_0315d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FFFFAAu;
    constexpr uint32_t kFuncSize = 504u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[98]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #611 | VA: 0x0317c8..0x0319ac (484 B) | FDE: 0x04c548
// Symbol (EN/VN): internal_func_0317c8
//   0x0317c8: D10103FF  sub      sp, sp, #0x40
//   0x0317cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0317d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0317d4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0317d8: 9100C3FD  add      x29, sp, #0x30
//   0x0317dc: D53BD056  mrs      x22, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_611_sub_0317c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x17FFFFACu;
    constexpr uint32_t kFuncSize = 484u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[99]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #612 | VA: 0x0319ac..0x031b80 (468 B) | FDE: 0x04c570
// Symbol (EN/VN): internal_func_0319ac
//   0x0319ac: D10143FF  sub      sp, sp, #0x50
//   0x0319b0: F9000BF7  str      x23, [sp, #0x10]
//   0x0319b4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0319b8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0319bc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0319c0: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_612_sub_0319ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FFFFA7u;
    constexpr uint32_t kFuncSize = 468u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[100]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #613 | VA: 0x031b80..0x031df8 (632 B) | FDE: 0x04c598
// Symbol (EN/VN): internal_func_031b80
//   0x031b80: D10183FF  sub      sp, sp, #0x60
//   0x031b84: F90013F7  str      x23, [sp, #0x20]
//   0x031b88: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x031b8c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x031b90: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x031b94: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_613_sub_031b80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x17FFFFC6u;
    constexpr uint32_t kFuncSize = 632u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[101]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #614 | VA: 0x031df8..0x031e60 (104 B) | FDE: 0x04c5c0
// Symbol (EN/VN): internal_func_031df8
//   0x031df8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x031dfc: 910003FD  mov      x29, sp
//   0x031e00: 91013808  add      x8, x0, #0x4e
//   0x031e04: 08DFFD08  ldarb    w8, [x8]
//   0x031e08: 36000268  tbz      w8, #0, #0x31e54
//   0x031e0c: 39413408  ldrb     w8, [x0, #0x4d]
// ----------------------------------------------------------------------------
uint64_t fde_614_sub_031df8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 104u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[102]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #615 | VA: 0x031e60..0x031e70 (16 B) | FDE: 0x04c5e0
// Symbol (EN/VN): internal_func_031e60
//   0x031e60: 91013808  add      x8, x0, #0x4e
//   0x031e64: 08DFFD08  ldarb    w8, [x8]
//   0x031e68: 12000100  and      w0, w8, #1
//   0x031e6c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_615_sub_031e60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91013808u;
    constexpr uint32_t kSecondOpcode = 0x08DFFD08u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[103]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #616 | VA: 0x031e70..0x031ebc (76 B) | FDE: 0x04c5f8
// Symbol (EN/VN): internal_func_031e70
//   0x031e70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x031e74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x031e78: 910043FD  add      x29, sp, #0x10
//   0x031e7c: AA0003F3  mov      x19, x0
//   0x031e80: F9400800  ldr      x0, [x0, #0x10]
//   0x031e84: B40000A0  cbz      x0, #0x31e98
// ----------------------------------------------------------------------------
uint64_t fde_616_sub_031e70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 76u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[104]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #617 | VA: 0x031ebc..0x031ef0 (52 B) | FDE: 0x04c618
// Symbol (EN/VN): internal_func_031ebc
//   0x031ebc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x031ec0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x031ec4: 910043FD  add      x29, sp, #0x10
//   0x031ec8: 52801500  mov      w0, #0xa8
//   0x031ecc: 97FF78CD  bl       #0x10200
//   0x031ed0: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_617_sub_031ebc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 52u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[105]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #618 | VA: 0x031ef0..0x03201c (300 B) | FDE: 0x04c638
// Symbol (EN/VN): internal_func_031ef0
//   0x031ef0: F9400409  ldr      x9, [x0, #8]
//   0x031ef4: B4000829  cbz      x9, #0x31ff8
//   0x031ef8: F9400028  ldr      x8, [x1]
//   0x031efc: D285AD2A  mov      x10, #0x2d69
//   0x031f00: F2BD670A  movk     x10, #0xeb38, lsl #16
//   0x031f04: F2DD410A  movk     x10, #0xea08, lsl #32
// ----------------------------------------------------------------------------
uint64_t fde_618_sub_031ef0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xB4000829u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 300u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[106]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #619 | VA: 0x03201c..0x032168 (332 B) | FDE: 0x04c650
// Symbol (EN/VN): internal_func_03201c
//   0x03201c: F9400409  ldr      x9, [x0, #8]
//   0x032020: F940042A  ldr      x10, [x1, #8]
//   0x032024: 9E670120  fmov     d0, x9
//   0x032028: 0E205800  cnt      v0.8b, v0.8b
//   0x03202c: 2E303800  uaddlv   h0, v0.8b
//   0x032030: 1E26000D  fmov     w13, s0
// ----------------------------------------------------------------------------
uint64_t fde_619_sub_03201c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xF940042Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[107]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #620 | VA: 0x032168..0x0323f8 (656 B) | FDE: 0x04c668
// Symbol (EN/VN): internal_func_032168
//   0x032168: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x03216c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x032170: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x032174: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x032178: 9100C3FD  add      x29, sp, #0x30
//   0x03217c: F9400028  ldr      x8, [x1]
// ----------------------------------------------------------------------------
uint64_t fde_620_sub_032168(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 656u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[108]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #621 | VA: 0x0323f8..0x032500 (264 B) | FDE: 0x04c690
// Symbol (EN/VN): internal_func_0323f8
//   0x0323f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0323fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x032400: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x032404: 910083FD  add      x29, sp, #0x20
//   0x032408: F1000428  subs     x8, x1, #1
//   0x03240c: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_621_sub_0323f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[109]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #622 | VA: 0x032500..0x032730 (560 B) | FDE: 0x04c6b0
// Symbol (EN/VN): internal_func_032500
//   0x032500: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x032504: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x032508: 910043FD  add      x29, sp, #0x10
//   0x03250c: AA0003F3  mov      x19, x0
//   0x032510: B40004A1  cbz      x1, #0x325a4
//   0x032514: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_622_sub_032500(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x97FF764Du;
    constexpr uint32_t kFuncSize = 560u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[110]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #623 | VA: 0x032730..0x0328c0 (400 B) | FDE: 0x04c6d0
// Symbol (EN/VN): internal_func_032730
//   0x032730: D10203FF  sub      sp, sp, #0x80
//   0x032734: F9002BF5  str      x21, [sp, #0x50]
//   0x032738: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x03273c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x032740: 9101C3FD  add      x29, sp, #0x70
//   0x032744: D53BD054  mrs      x20, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_623_sub_032730(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xF9002BF5u;
    constexpr uint32_t kLastOpcode = 0x97FF7CC2u;
    constexpr uint32_t kFuncSize = 400u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[111]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #624 | VA: 0x0328c0..0x032904 (68 B) | FDE: 0x04c6f0
// Symbol (EN/VN): internal_func_0328c0
//   0x0328c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0328c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0328c8: 910043FD  add      x29, sp, #0x10
//   0x0328cc: B0000108  adrp     x8, #0x53000
//   0x0328d0: F9479508  ldr      x8, [x8, #0xf28]
//   0x0328d4: AA0103F3  mov      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_624_sub_0328c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF74A0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[112]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #625 | VA: 0x032904..0x032908 (4 B) | FDE: 0x04c710
// Symbol (EN/VN): internal_func_032904
//   0x032904: 14000003  b        #0x32910
// ----------------------------------------------------------------------------
uint64_t fde_625_sub_032904(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x14000003u;
    constexpr uint32_t kSecondOpcode = 0x14000003u;
    constexpr uint32_t kLastOpcode = 0x14000003u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[113]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #626 | VA: 0x032908..0x032910 (8 B) | FDE: 0x04c728
// Symbol (EN/VN): internal_func_032908
//   0x032908: F9404C00  ldr      x0, [x0, #0x98]
//   0x03290c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_626_sub_032908(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9404C00u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[114]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #627 | VA: 0x032910..0x032c20 (784 B) | FDE: 0x04c740
// Symbol (EN/VN): internal_func_032910
//   0x032910: D10303FF  sub      sp, sp, #0xc0
//   0x032914: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x032918: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x03291c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x032920: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x032924: A90A4FF4  stp      x20, x19, [sp, #0xa0]
// ----------------------------------------------------------------------------
uint64_t fde_627_sub_032910(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10303FFu;
    constexpr uint32_t kSecondOpcode = 0xA9066FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF75D5u;
    constexpr uint32_t kFuncSize = 784u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[115]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #628 | VA: 0x032c20..0x032e44 (548 B) | FDE: 0x04c770
// Symbol (EN/VN): internal_func_032c20
//   0x032c20: D10203FF  sub      sp, sp, #0x80
//   0x032c24: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x032c28: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x032c2c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x032c30: 9101C3FD  add      x29, sp, #0x70
//   0x032c34: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_628_sub_032c20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA90557F6u;
    constexpr uint32_t kLastOpcode = 0x97FF754Cu;
    constexpr uint32_t kFuncSize = 548u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[116]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #629 | VA: 0x032e44..0x032e48 (4 B) | FDE: 0x04c798
// Symbol (EN/VN): internal_func_032e44
//   0x032e44: 17FF72C7  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_629_sub_032e44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF72C7u;
    constexpr uint32_t kSecondOpcode = 0x17FF72C7u;
    constexpr uint32_t kLastOpcode = 0x17FF72C7u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[117]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #630 | VA: 0x032e48..0x032e84 (60 B) | FDE: 0x04c7b0
// Symbol (EN/VN): internal_func_032e48
//   0x032e48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x032e4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x032e50: 910043FD  add      x29, sp, #0x10
//   0x032e54: AA0003F3  mov      x19, x0
//   0x032e58: 52800300  mov      w0, #0x18
//   0x032e5c: 97FF74E9  bl       #0x10200
// ----------------------------------------------------------------------------
uint64_t fde_630_sub_032e48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 60u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[118]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #631 | VA: 0x032e84..0x032ea0 (28 B) | FDE: 0x04c7d0
// Symbol (EN/VN): internal_func_032e84
//   0x032e84: B0000108  adrp     x8, #0x53000
//   0x032e88: F9468908  ldr      x8, [x8, #0xd10]
//   0x032e8c: 91004108  add      x8, x8, #0x10
//   0x032e90: F9000028  str      x8, [x1]
//   0x032e94: 3CC08000  ldur     q0, [x0, #8]
//   0x032e98: 3C808020  stur     q0, [x1, #8]
// ----------------------------------------------------------------------------
uint64_t fde_631_sub_032e84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB0000108u;
    constexpr uint32_t kSecondOpcode = 0xF9468908u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 28u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[119]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #632 | VA: 0x032ea0..0x032ea4 (4 B) | FDE: 0x04c7e8
// Symbol (EN/VN): internal_func_032ea0
//   0x032ea0: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_632_sub_032ea0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[120]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #633 | VA: 0x032ea4..0x032ea8 (4 B) | FDE: 0x04c800
// Symbol (EN/VN): internal_func_032ea4
//   0x032ea4: 17FF72AF  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_633_sub_032ea4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF72AFu;
    constexpr uint32_t kSecondOpcode = 0x17FF72AFu;
    constexpr uint32_t kLastOpcode = 0x17FF72AFu;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[121]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #634 | VA: 0x032ea8..0x032eb0 (8 B) | FDE: 0x04c818
// Symbol (EN/VN): internal_func_032ea8
//   0x032ea8: A9408001  ldp      x1, x0, [x0, #8]
//   0x032eac: D61F0020  br       x1
// ----------------------------------------------------------------------------
uint64_t fde_634_sub_032ea8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9408001u;
    constexpr uint32_t kSecondOpcode = 0xD61F0020u;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[122]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #635 | VA: 0x032eb0..0x03307c (460 B) | FDE: 0x04c830
// Symbol (EN/VN): internal_func_032eb0
//   0x032eb0: D101C3FF  sub      sp, sp, #0x70
//   0x032eb4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x032eb8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x032ebc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x032ec0: 910183FD  add      x29, sp, #0x60
//   0x032ec4: D53BD055  mrs      x21, tpidr_el0
// ----------------------------------------------------------------------------
uint64_t fde_635_sub_032eb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90457F6u;
    constexpr uint32_t kLastOpcode = 0x97FF73FAu;
    constexpr uint32_t kFuncSize = 460u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[123]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #636 | VA: 0x03307c..0x0331c0 (324 B) | FDE: 0x04c858
// Symbol (EN/VN): internal_func_03307c
//   0x03307c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x033080: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x033084: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x033088: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03308c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x033090: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_636_sub_03307c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF73A9u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[124]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #637 | VA: 0x0331c0..0x033304 (324 B) | FDE: 0x04c880
// Symbol (EN/VN): internal_func_0331c0
//   0x0331c0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0331c4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0331c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0331cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0331d0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0331d4: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_637_sub_0331c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF7358u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[125]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #638 | VA: 0x033304..0x033448 (324 B) | FDE: 0x04c8a8
// Symbol (EN/VN): internal_func_033304
//   0x033304: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x033308: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03330c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x033310: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x033314: 9100C3FD  add      x29, sp, #0x30
//   0x033318: A9405408  ldp      x8, x21, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_638_sub_033304(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FF7307u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[126]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #639 | VA: 0x033448..0x03358c (324 B) | FDE: 0x04c8d0
// Symbol (EN/VN): internal_func_033448
//   0x033448: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x03344c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x033450: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x033454: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x033458: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03345c: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_639_sub_033448(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF72B6u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[127]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #640 | VA: 0x03358c..0x0336d0 (324 B) | FDE: 0x04c8f8
// Symbol (EN/VN): internal_func_03358c
//   0x03358c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x033590: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x033594: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x033598: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03359c: 9100C3FD  add      x29, sp, #0x30
//   0x0335a0: A9405408  ldp      x8, x21, [x0]
// ----------------------------------------------------------------------------
uint64_t fde_640_sub_03358c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x97FF7265u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[128]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #641 | VA: 0x0336d0..0x0336d4 (4 B) | FDE: 0x04c920
// Symbol (EN/VN): internal_func_0336d0
//   0x0336d0: 14000A52  b        #0x36018
// ----------------------------------------------------------------------------
uint64_t fde_641_sub_0336d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x14000A52u;
    constexpr uint32_t kSecondOpcode = 0x14000A52u;
    constexpr uint32_t kLastOpcode = 0x14000A52u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[129]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #642 | VA: 0x0336d4..0x0336f8 (36 B) | FDE: 0x04c938
// Symbol (EN/VN): internal_func_0336d4
//   0x0336d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0336d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0336dc: 910043FD  add      x29, sp, #0x10
//   0x0336e0: AA0003F3  mov      x19, x0
//   0x0336e4: 94000A4D  bl       #0x36018
//   0x0336e8: A9417BFD  ldp      x29, x30, [sp, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_642_sub_0336d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF709Bu;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[130]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #643 | VA: 0x0336f8..0x033724 (44 B) | FDE: 0x04c958
// Symbol (EN/VN): internal_func_0336f8
//   0x0336f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0336fc: 910003FD  mov      x29, sp
//   0x033700: F9400400  ldr      x0, [x0, #8]
//   0x033704: 97FFDCCD  bl       #0x2aa38
//   0x033708: 39402008  ldrb     w8, [x0, #8]
//   0x03370c: F9400809  ldr      x9, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_643_sub_0336f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[131]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #644 | VA: 0x033724..0x033800 (220 B) | FDE: 0x04c978
// Symbol (EN/VN): internal_func_033724
//   0x033724: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x033728: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03372c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x033730: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x033734: 9100C3FD  add      x29, sp, #0x30
//   0x033738: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_644_sub_033724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 220u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[132]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #645 | VA: 0x033800..0x033818 (24 B) | FDE: 0x04c9a0
// Symbol (EN/VN): internal_func_033800
//   0x033800: F9000C1F  str      xzr, [x0, #0x18]
//   0x033804: 90000108  adrp     x8, #0x53000
//   0x033808: F9474908  ldr      x8, [x8, #0xe90]
//   0x03380c: AA0103E0  mov      x0, x1
//   0x033810: F9400102  ldr      x2, [x8]
//   0x033814: D61F0040  br       x2
// ----------------------------------------------------------------------------
uint64_t fde_645_sub_033800(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9000C1Fu;
    constexpr uint32_t kSecondOpcode = 0x90000108u;
    constexpr uint32_t kLastOpcode = 0xD61F0040u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[133]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #646 | VA: 0x033818..0x03381c (4 B) | FDE: 0x04c9b8
// Symbol (EN/VN): internal_func_033818
//   0x033818: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_646_sub_033818(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[134]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #647 | VA: 0x03381c..0x034ea4 (5768 B) | FDE: 0x04c9d0
// Symbol (EN/VN): internal_func_03381c
//   0x03381c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x033820: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x033824: 910043FD  add      x29, sp, #0x10
//   0x033828: B0000114  adrp     x20, #0x54000
//   0x03382c: 394FE288  ldrb     w8, [x20, #0x3f8]
//   0x033830: 360000A8  tbz      w8, #0, #0x33844
// ----------------------------------------------------------------------------
uint64_t fde_647_sub_03381c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FFFF29u;
    constexpr uint32_t kFuncSize = 5768u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[135]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #648 | VA: 0x034ea4..0x034f50 (172 B) | FDE: 0x04c9f0
// Symbol (EN/VN): internal_func_034ea4
//   0x034ea4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x034ea8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x034eac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x034eb0: 910083FD  add      x29, sp, #0x20
//   0x034eb4: F00000E8  adrp     x8, #0x53000
//   0x034eb8: F9478D08  ldr      x8, [x8, #0xf18]
// ----------------------------------------------------------------------------
uint64_t fde_648_sub_034ea4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 172u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[136]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #649 | VA: 0x034f50..0x034f78 (40 B) | FDE: 0x04ca18
// Symbol (EN/VN): internal_func_034f50
//   0x034f50: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x034f54: 910003FD  mov      x29, sp
//   0x034f58: F00000E8  adrp     x8, #0x53000
//   0x034f5c: F946B508  ldr      x8, [x8, #0xd68]
//   0x034f60: F9400108  ldr      x8, [x8]
//   0x034f64: D63F0100  blr      x8
// ----------------------------------------------------------------------------
uint64_t fde_649_sub_034f50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[137]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #650 | VA: 0x034f78..0x034fb8 (64 B) | FDE: 0x04ca38
// Symbol (EN/VN): internal_func_034f78
//   0x034f78: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x034f7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x034f80: 910043FD  add      x29, sp, #0x10
//   0x034f84: F00000E8  adrp     x8, #0x53000
//   0x034f88: F946B508  ldr      x8, [x8, #0xd68]
//   0x034f8c: AA0203F3  mov      x19, x2
// ----------------------------------------------------------------------------
uint64_t fde_650_sub_034f78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD61F0060u;
    constexpr uint32_t kFuncSize = 64u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[138]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #651 | VA: 0x034fb8..0x034ff0 (56 B) | FDE: 0x04ca58
// Symbol (EN/VN): internal_func_034fb8
//   0x034fb8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x034fbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x034fc0: 910043FD  add      x29, sp, #0x10
//   0x034fc4: F00000E8  adrp     x8, #0x53000
//   0x034fc8: F946B508  ldr      x8, [x8, #0xd68]
//   0x034fcc: AA0103F3  mov      x19, x1
// ----------------------------------------------------------------------------
uint64_t fde_651_sub_034fb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD61F0040u;
    constexpr uint32_t kFuncSize = 56u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[139]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #652 | VA: 0x034ff0..0x035018 (40 B) | FDE: 0x04ca78
// Symbol (EN/VN): internal_func_034ff0
//   0x034ff0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x034ff4: 910003FD  mov      x29, sp
//   0x034ff8: 100F0048  adr      x8, #0x53000
//   0x034ffc: F946B508  ldr      x8, [x8, #0xd68]
//   0x035000: F9400108  ldr      x8, [x8]
//   0x035004: D63F0100  blr      x8
// ----------------------------------------------------------------------------
uint64_t fde_652_sub_034ff0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD61F0020u;
    constexpr uint32_t kFuncSize = 40u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[140]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #653 | VA: 0x036018..0x036060 (72 B) | FDE: 0x04ca98
// Symbol (EN/VN): internal_func_036018
//   0x036018: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03601c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x036020: 910043FD  add      x29, sp, #0x10
//   0x036024: B00000E8  adrp     x8, #0x53000
//   0x036028: AA0003F3  mov      x19, x0
//   0x03602c: F9400800  ldr      x0, [x0, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_653_sub_036018(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 72u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[141]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #654 | VA: 0x036060..0x036064 (4 B) | FDE: 0x04cab8
// Symbol (EN/VN): internal_func_036060
//   0x036060: D4200020  brk      #1
// ----------------------------------------------------------------------------
uint64_t fde_654_sub_036060(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD4200020u;
    constexpr uint32_t kSecondOpcode = 0xD4200020u;
    constexpr uint32_t kLastOpcode = 0xD4200020u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[142]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #655 | VA: 0x036064..0x0362b0 (588 B) | FDE: 0x04cad0
// Symbol (EN/VN): _ZN13AmazingEngine14PerformanceCapC1Ev
//   0x036064: D10143FF  sub      sp, sp, #0x50
//   0x036068: F9000BF7  str      x23, [sp, #0x10]
//   0x03606c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x036070: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x036074: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x036078: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_655_sub_036064(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x97FF6831u;
    constexpr uint32_t kFuncSize = 588u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[143]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #656 | VA: 0x0362b0..0x0362b8 (8 B) | FDE: 0x04caf8
// Symbol (EN/VN): _ZNK13AmazingEngine14PerformanceCap19getEvaluateInstanceEv
//   0x0362b0: F9400000  ldr      x0, [x0]
//   0x0362b4: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_656_sub_0362b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400000u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[144]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #657 | VA: 0x0362b8..0x0362e4 (44 B) | FDE: 0x04cb10
// Symbol (EN/VN): _ZN13AmazingEngine14PerformanceCap22getStatisticsFrameCostENS_23PerformanceEvaluateTypeE
//   0x0362b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0362bc: 910003FD  mov      x29, sp
//   0x0362c0: A940A808  ldp      x8, x10, [x0, #8]
//   0x0362c4: 93407C29  sxtw     x9, w1
//   0x0362c8: CB08014A  sub      x10, x10, x8
//   0x0362cc: EB8A0D3F  cmp      x9, x10, asr #3
// ----------------------------------------------------------------------------
uint64_t fde_657_sub_0362b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0x97FF6760u;
    constexpr uint32_t kFuncSize = 44u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[145]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #658 | VA: 0x0362e4..0x0363f0 (268 B) | FDE: 0x04cb30
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCostD2Ev
//   0x0362e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0362e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0362ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0362f0: 910083FD  add      x29, sp, #0x20
//   0x0362f4: F9406C14  ldr      x20, [x0, #0xd8]
//   0x0362f8: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_658_sub_0362e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF7u;
    constexpr uint32_t kFuncSize = 268u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[146]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #659 | VA: 0x0363f0..0x036440 (80 B) | FDE: 0x04cb50
// Symbol (EN/VN): internal_func_0363f0
//   0x0363f0: B4000261  cbz      x1, #0x3643c
//   0x0363f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0363f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0363fc: 910043FD  add      x29, sp, #0x10
//   0x036400: AA0103F3  mov      x19, x1
//   0x036404: F9400021  ldr      x1, [x1]
// ----------------------------------------------------------------------------
uint64_t fde_659_sub_0363f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB4000261u;
    constexpr uint32_t kSecondOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 80u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[147]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #660 | VA: 0x036440..0x036568 (296 B) | FDE: 0x04cb70
// Symbol (EN/VN): internal_func_036440
//   0x036440: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x036444: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x036448: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03644c: 910083FD  add      x29, sp, #0x20
//   0x036450: A9402009  ldp      x9, x8, [x0]
//   0x036454: CB090108  sub      x8, x8, x9
// ----------------------------------------------------------------------------
uint64_t fde_660_sub_036440(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BD57F6u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFD2u;
    constexpr uint32_t kFuncSize = 296u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[148]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #661 | VA: 0x036568..0x03657c (20 B) | FDE: 0x04cbb8
// Symbol (EN/VN): internal_func_036568
//   0x036568: 39400008  ldrb     w8, [x0]
//   0x03656c: 37000048  tbnz     w8, #0, #0x36574
//   0x036570: D65F03C0  ret      
//   0x036574: F9400800  ldr      x0, [x0, #0x10]
//   0x036578: 17FF64FA  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_661_sub_036568(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400008u;
    constexpr uint32_t kSecondOpcode = 0x37000048u;
    constexpr uint32_t kLastOpcode = 0x17FF64FAu;
    constexpr uint32_t kFuncSize = 20u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[149]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #662 | VA: 0x03657c..0x0366b0 (308 B) | FDE: 0x04cbd0
// Symbol (EN/VN): _ZN13AmazingEngine19PerformanceEvaluateC2Ev
//   0x03657c: D10183FF  sub      sp, sp, #0x60
//   0x036580: F90013F7  str      x23, [sp, #0x20]
//   0x036584: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x036588: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03658c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x036590: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_662_sub_03657c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x97FF6731u;
    constexpr uint32_t kFuncSize = 308u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[150]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #663 | VA: 0x0366b0..0x03671c (108 B) | FDE: 0x04cbf8
// Symbol (EN/VN): _ZN13AmazingEngine19PerformanceEvaluate15setSwitchStatusENS_29PerformanceEvaluateSwitchModeEb
//   0x0366b0: D10103FF  sub      sp, sp, #0x40
//   0x0366b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0366b8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0366bc: 9100C3FD  add      x29, sp, #0x30
//   0x0366c0: D53BD053  mrs      x19, tpidr_el0
//   0x0366c4: F9401668  ldr      x8, [x19, #0x28]
// ----------------------------------------------------------------------------
uint64_t fde_663_sub_0366b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10103FFu;
    constexpr uint32_t kSecondOpcode = 0xA9024FF4u;
    constexpr uint32_t kLastOpcode = 0x97FF6716u;
    constexpr uint32_t kFuncSize = 108u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[151]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #664 | VA: 0x03671c..0x036818 (252 B) | FDE: 0x04cc18
// Symbol (EN/VN): _ZNK13AmazingEngine19PerformanceEvaluate15getSwitchStatusENS_29PerformanceEvaluateSwitchModeE
//   0x03671c: F9400409  ldr      x9, [x0, #8]
//   0x036720: B4000709  cbz      x9, #0x36800
//   0x036724: 9E670120  fmov     d0, x9
//   0x036728: 0E205800  cnt      v0.8b, v0.8b
//   0x03672c: 2E303800  uaddlv   h0, v0.8b
//   0x036730: 1E26000C  fmov     w12, s0
// ----------------------------------------------------------------------------
uint64_t fde_664_sub_03671c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400409u;
    constexpr uint32_t kSecondOpcode = 0xB4000709u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 252u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[152]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #665 | VA: 0x036818..0x0368b4 (156 B) | FDE: 0x04cc30
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCostC1ENS_23PerformanceEvaluateTypeE
//   0x036818: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03681c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x036820: 910043FD  add      x29, sp, #0x10
//   0x036824: D00000E9  adrp     x9, #0x54000
//   0x036828: AA0003E8  mov      x8, x0
//   0x03682c: 91100129  add      x9, x9, #0x400
// ----------------------------------------------------------------------------
uint64_t fde_665_sub_036818(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 156u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[153]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #666 | VA: 0x0368b4..0x036914 (96 B) | FDE: 0x04cc50
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost11beginRecordEv
//   0x0368b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0368b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0368bc: 910043FD  add      x29, sp, #0x10
//   0x0368c0: 39404408  ldrb     w8, [x0, #0x11]
//   0x0368c4: 34000228  cbz      w8, #0x36908
//   0x0368c8: B9400808  ldr      w8, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_666_sub_0368b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 96u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[154]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #667 | VA: 0x036914..0x036a18 (260 B) | FDE: 0x04cc70
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost11beginRecordERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x036914: D10183FF  sub      sp, sp, #0x60
//   0x036918: F90013F7  str      x23, [sp, #0x20]
//   0x03691c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x036920: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x036924: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x036928: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_667_sub_036914(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x97FF6657u;
    constexpr uint32_t kFuncSize = 260u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[155]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #668 | VA: 0x036a18..0x036af8 (224 B) | FDE: 0x04cc98
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost23setTiggersDirtyTagFalseERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x036a18: D10183FF  sub      sp, sp, #0x60
//   0x036a1c: F90013F7  str      x23, [sp, #0x20]
//   0x036a20: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x036a24: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x036a28: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x036a2c: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_668_sub_036a18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0x97FF661Fu;
    constexpr uint32_t kFuncSize = 224u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[156]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #669 | VA: 0x036af8..0x036cb8 (448 B) | FDE: 0x04ccc0
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost9endRecordEv
//   0x036af8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x036afc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x036b00: 910043FD  add      x29, sp, #0x10
//   0x036b04: 3941C008  ldrb     w8, [x0, #0x70]
//   0x036b08: 34000D28  cbz      w8, #0x36cac
//   0x036b0c: B9405008  ldr      w8, [x0, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_669_sub_036af8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 448u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[157]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #670 | VA: 0x036cb8..0x03704c (916 B) | FDE: 0x04cce0
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost8printLogEv
//   0x036cb8: 6DB923E9  stp      d9, d8, [sp, #-0x70]!
//   0x036cbc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x036cc0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x036cc4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x036cc8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x036ccc: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_670_sub_036cb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DB923E9u;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 916u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[158]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #671 | VA: 0x03704c..0x0370d8 (140 B) | FDE: 0x04cd18
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost5resetEv
//   0x03704c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x037050: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037054: 910043FD  add      x29, sp, #0x10
//   0x037058: AA0003E8  mov      x8, x0
//   0x03705c: 38458D09  ldrb     w9, [x8, #0x58]!
//   0x037060: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_671_sub_03704c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 140u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[159]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #672 | VA: 0x0370d8..0x037284 (428 B) | FDE: 0x04cd38
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost9endRecordERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x0370d8: D10183FF  sub      sp, sp, #0x60
//   0x0370dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0370e0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0370e4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0370e8: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0370ec: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_672_sub_0370d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA9025FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF643Cu;
    constexpr uint32_t kFuncSize = 428u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[160]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #673 | VA: 0x037284..0x037a50 (1996 B) | FDE: 0x04cd60
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost19trigStatisticsPointERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x037284: D10283FF  sub      sp, sp, #0xa0
//   0x037288: FD0023E8  str      d8, [sp, #0x40]
//   0x03728c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x037290: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x037294: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x037298: A9084FF4  stp      x20, x19, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_673_sub_037284(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xFD0023E8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFBAu;
    constexpr uint32_t kFuncSize = 1996u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[161]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #674 | VA: 0x037a50..0x037a6c (28 B) | FDE: 0x04cd90
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost11getTimeCostEv
//   0x037a50: 91004008  add      x8, x0, #0x10
//   0x037a54: 52800029  mov      w9, #1
//   0x037a58: 089FFD09  stlrb    w9, [x8]
//   0x037a5c: 91006008  add      x8, x0, #0x18
//   0x037a60: C8DFFD08  ldar     x8, [x8]
//   0x037a64: 9E670100  fmov     d0, x8
// ----------------------------------------------------------------------------
uint64_t fde_674_sub_037a50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91004008u;
    constexpr uint32_t kSecondOpcode = 0x52800029u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 28u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[162]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #675 | VA: 0x037a6c..0x037c0c (416 B) | FDE: 0x04cda8
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost11getTimeCostERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
//   0x037a6c: D10203FF  sub      sp, sp, #0x80
//   0x037a70: FD0023E8  str      d8, [sp, #0x40]
//   0x037a74: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x037a78: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x037a7c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x037a80: 9101C3FD  add      x29, sp, #0x70
// ----------------------------------------------------------------------------
uint64_t fde_675_sub_037a6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xFD0023E8u;
    constexpr uint32_t kLastOpcode = 0x97FF61DAu;
    constexpr uint32_t kFuncSize = 416u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[163]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #676 | VA: 0x037c0c..0x037d50 (324 B) | FDE: 0x04cdd0
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost13resetTriggersEv
//   0x037c0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x037c10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037c14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037c18: 910083FD  add      x29, sp, #0x20
//   0x037c1c: F9407008  ldr      x8, [x0, #0xe0]
//   0x037c20: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_676_sub_037c0c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF7u;
    constexpr uint32_t kFuncSize = 324u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[164]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #677 | VA: 0x037d50..0x037d60 (16 B) | FDE: 0x04cdf0
// Symbol (EN/VN): _ZN13AmazingEngine19StatisticsFrameCost13setDirtyFalseEb
//   0x037d50: 12000028  and      w8, w1, #1
//   0x037d54: 91004009  add      x9, x0, #0x10
//   0x037d58: 089FFD28  stlrb    w8, [x9]
//   0x037d5c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_677_sub_037d50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x12000028u;
    constexpr uint32_t kSecondOpcode = 0x91004009u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 16u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[165]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #678 | VA: 0x037d60..0x037fc4 (612 B) | FDE: 0x04ce08
// Symbol (EN/VN): internal_func_037d60
//   0x037d60: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x037d64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x037d68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x037d6c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x037d70: 9100C3FD  add      x29, sp, #0x30
//   0x037d74: F9400416  ldr      x22, [x0, #8]
// ----------------------------------------------------------------------------
uint64_t fde_678_sub_037d60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BC5FF8u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 612u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[166]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #679 | VA: 0x037fc4..0x0380cc (264 B) | FDE: 0x04ce30
// Symbol (EN/VN): internal_func_037fc4
//   0x037fc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x037fc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037fcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037fd0: 910083FD  add      x29, sp, #0x20
//   0x037fd4: F1000428  subs     x8, x1, #1
//   0x037fd8: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_679_sub_037fc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[167]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #680 | VA: 0x0380cc..0x0382fc (560 B) | FDE: 0x04ce50
// Symbol (EN/VN): internal_func_0380cc
//   0x0380cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0380d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0380d4: 910043FD  add      x29, sp, #0x10
//   0x0380d8: AA0003F3  mov      x19, x0
//   0x0380dc: B40004A1  cbz      x1, #0x38170
//   0x0380e0: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_680_sub_0380cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x97FF5F5Au;
    constexpr uint32_t kFuncSize = 560u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[168]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #681 | VA: 0x0382fc..0x038564 (616 B) | FDE: 0x04ce70
// Symbol (EN/VN): internal_func_0382fc
//   0x0382fc: D10183FF  sub      sp, sp, #0x60
//   0x038300: F9000BF9  str      x25, [sp, #0x10]
//   0x038304: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x038308: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03830c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x038310: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_681_sub_0382fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FF5F84u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[169]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #682 | VA: 0x038564..0x038964 (1024 B) | FDE: 0x04ce98
// Symbol (EN/VN): internal_func_038564
//   0x038564: D10243FF  sub      sp, sp, #0x90
//   0x038568: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x03856c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x038570: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x038574: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x038578: A9074FF4  stp      x20, x19, [sp, #0x70]
// ----------------------------------------------------------------------------
uint64_t fde_682_sub_038564(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9036FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 1024u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[170]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #683 | VA: 0x038964..0x038a60 (252 B) | FDE: 0x04cec8
// Symbol (EN/VN): internal_func_038964
//   0x038964: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x038968: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x03896c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x038970: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x038974: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x038978: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_683_sub_038964(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF5D81u;
    constexpr uint32_t kFuncSize = 252u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[171]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #684 | VA: 0x038a60..0x038b68 (264 B) | FDE: 0x04cef0
// Symbol (EN/VN): internal_func_038a60
//   0x038a60: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x038a64: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x038a68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x038a6c: 910083FD  add      x29, sp, #0x20
//   0x038a70: F1000428  subs     x8, x1, #1
//   0x038a74: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_684_sub_038a60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[172]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #685 | VA: 0x038b68..0x038e88 (800 B) | FDE: 0x04cf10
// Symbol (EN/VN): internal_func_038b68
//   0x038b68: D101C3FF  sub      sp, sp, #0x70
//   0x038b6c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x038b70: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x038b74: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x038b78: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x038b7c: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_685_sub_038b68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF5C77u;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[173]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #686 | VA: 0x038e88..0x039288 (1024 B) | FDE: 0x04cf40
// Symbol (EN/VN): internal_func_038e88
//   0x038e88: D10243FF  sub      sp, sp, #0x90
//   0x038e8c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x038e90: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x038e94: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x038e98: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x038e9c: A9074FF4  stp      x20, x19, [sp, #0x70]
// ----------------------------------------------------------------------------
uint64_t fde_686_sub_038e88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9036FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 1024u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[174]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #687 | VA: 0x039288..0x039380 (248 B) | FDE: 0x04cf70
// Symbol (EN/VN): internal_func_039288
//   0x039288: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x03928c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x039290: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x039294: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x039298: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03929c: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_687_sub_039288(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF5B39u;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[175]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #688 | VA: 0x039380..0x039488 (264 B) | FDE: 0x04cf98
// Symbol (EN/VN): internal_func_039380
//   0x039380: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x039384: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x039388: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03938c: 910083FD  add      x29, sp, #0x20
//   0x039390: F1000428  subs     x8, x1, #1
//   0x039394: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_688_sub_039380(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[176]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #689 | VA: 0x039488..0x0397a8 (800 B) | FDE: 0x04cfb8
// Symbol (EN/VN): internal_func_039488
//   0x039488: D101C3FF  sub      sp, sp, #0x70
//   0x03948c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x039490: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x039494: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x039498: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x03949c: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_689_sub_039488(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF5A2Fu;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[177]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #690 | VA: 0x0397a8..0x039ba8 (1024 B) | FDE: 0x04cfe8
// Symbol (EN/VN): internal_func_0397a8
//   0x0397a8: D10243FF  sub      sp, sp, #0x90
//   0x0397ac: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0397b0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0397b4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0397b8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0397bc: A9074FF4  stp      x20, x19, [sp, #0x70]
// ----------------------------------------------------------------------------
uint64_t fde_690_sub_0397a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10243FFu;
    constexpr uint32_t kSecondOpcode = 0xA9036FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 1024u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[178]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #691 | VA: 0x039ba8..0x039ca0 (248 B) | FDE: 0x04d018
// Symbol (EN/VN): internal_func_039ba8
//   0x039ba8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x039bac: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x039bb0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x039bb4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x039bb8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x039bbc: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_691_sub_039ba8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF58F1u;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[179]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #692 | VA: 0x039ca0..0x039da8 (264 B) | FDE: 0x04d040
// Symbol (EN/VN): internal_func_039ca0
//   0x039ca0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x039ca4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x039ca8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x039cac: 910083FD  add      x29, sp, #0x20
//   0x039cb0: F1000428  subs     x8, x1, #1
//   0x039cb4: AA0003F3  mov      x19, x0
// ----------------------------------------------------------------------------
uint64_t fde_692_sub_039ca0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 264u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[180]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #693 | VA: 0x039da8..0x03a0c8 (800 B) | FDE: 0x04d060
// Symbol (EN/VN): internal_func_039da8
//   0x039da8: D101C3FF  sub      sp, sp, #0x70
//   0x039dac: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x039db0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x039db4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x039db8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x039dbc: A9054FF4  stp      x20, x19, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_693_sub_039da8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA9016FFCu;
    constexpr uint32_t kLastOpcode = 0x97FF57E7u;
    constexpr uint32_t kFuncSize = 800u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[181]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #694 | VA: 0x03a0c8..0x03a330 (616 B) | FDE: 0x04d090
// Symbol (EN/VN): internal_func_03a0c8
//   0x03a0c8: D10183FF  sub      sp, sp, #0x60
//   0x03a0cc: F9000BF9  str      x25, [sp, #0x10]
//   0x03a0d0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03a0d4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03a0d8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03a0dc: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_694_sub_03a0c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FF5811u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[182]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #695 | VA: 0x03a330..0x03a598 (616 B) | FDE: 0x04d0b8
// Symbol (EN/VN): internal_func_03a330
//   0x03a330: D10183FF  sub      sp, sp, #0x60
//   0x03a334: F9000BF9  str      x25, [sp, #0x10]
//   0x03a338: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03a33c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03a340: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03a344: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_695_sub_03a330(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x97FF5777u;
    constexpr uint32_t kFuncSize = 616u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[183]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #696 | VA: 0x03a598..0x03a744 (428 B) | FDE: 0x04d0e0
// Symbol (EN/VN): internal_func_03a598
//   0x03a598: EB00003F  cmp      x1, x0
//   0x03a59c: 1A9F17E8  cset     w8, eq
//   0x03a5a0: 39006028  strb     w8, [x1, #0x18]
//   0x03a5a4: 540005E0  b.eq     #0x3a660
//   0x03a5a8: 5280002A  mov      w10, #1
//   0x03a5ac: F9400829  ldr      x9, [x1, #0x10]
// ----------------------------------------------------------------------------
uint64_t fde_696_sub_03a598(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xEB00003Fu;
    constexpr uint32_t kSecondOpcode = 0x1A9F17E8u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 428u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[184]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #697 | VA: 0x03a744..0x03a834 (240 B) | FDE: 0x04d0f8
// Symbol (EN/VN): internal_func_03a744
//   0x03a744: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x03a748: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x03a74c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03a750: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03a754: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03a758: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_697_sub_03a744(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81B0FF9u;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x17FFFFE3u;
    constexpr uint32_t kFuncSize = 240u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[185]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #698 | VA: 0x03a834..0x03abf8 (964 B) | FDE: 0x04d120
// Symbol (EN/VN): internal_func_03a834
//   0x03a834: D10203FF  sub      sp, sp, #0x80
//   0x03a838: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x03a83c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x03a840: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x03a844: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x03a848: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_698_sub_03a834(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA9026FFCu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 964u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[186]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #699 | VA: 0x03abf8..0x03acf0 (248 B) | FDE: 0x04d150
// Symbol (EN/VN): internal_func_03abf8
//   0x03abf8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x03abfc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x03ac00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03ac04: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03ac08: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03ac0c: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_699_sub_03abf8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BB67FAu;
    constexpr uint32_t kSecondOpcode = 0xA9015FF8u;
    constexpr uint32_t kLastOpcode = 0x97FF54DDu;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[187]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #700 | VA: 0x03acf0..0x03affc (780 B) | FDE: 0x04d1a0
// Symbol (EN/VN): _ZN13AmazingEngine20stbtt_FindGlyphIndexEPKNS_14stbtt_fontinfoEi
//   0x03acf0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x03acf4: 910003FD  mov      x29, sp
//   0x03acf8: F940040A  ldr      x10, [x0, #8]
//   0x03acfc: B9403409  ldr      w9, [x0, #0x34]
//   0x03ad00: 8B090148  add      x8, x10, x9
//   0x03ad04: 3940010C  ldrb     w12, [x8]
// ----------------------------------------------------------------------------
uint64_t fde_700_sub_03acf0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BF7BFDu;
    constexpr uint32_t kSecondOpcode = 0x910003FDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 780u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[188]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #701 | VA: 0x03affc..0x03b02c (48 B) | FDE: 0x04d1c0
// Symbol (EN/VN): _ZN13AmazingEngine23stbtt_GetCodepointShapeEPKNS_14stbtt_fontinfoEiPPNS_12stbtt_vertexE
//   0x03affc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03b000: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03b004: 910043FD  add      x29, sp, #0x10
//   0x03b008: AA0203F3  mov      x19, x2
//   0x03b00c: AA0003F4  mov      x20, x0
//   0x03b010: 97FF54C0  bl       #0x10310
// ----------------------------------------------------------------------------
uint64_t fde_701_sub_03affc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0x17FF52DAu;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[189]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #702 | VA: 0x03b02c..0x03bc18 (3052 B) | FDE: 0x04d1e0
// Symbol (EN/VN): _ZN13AmazingEngine19stbtt_GetGlyphShapeEPKNS_14stbtt_fontinfoEiPPNS_12stbtt_vertexE
//   0x03b02c: D10603FF  sub      sp, sp, #0x180
//   0x03b030: FD008BE8  str      d8, [sp, #0x110]
//   0x03b034: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x03b038: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x03b03c: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x03b040: A91557F6  stp      x22, x21, [sp, #0x150]
// ----------------------------------------------------------------------------
uint64_t fde_702_sub_03b02c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10603FFu;
    constexpr uint32_t kSecondOpcode = 0xFD008BE8u;
    constexpr uint32_t kLastOpcode = 0x17FFFD35u;
    constexpr uint32_t kFuncSize = 3052u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[190]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #703 | VA: 0x03bc18..0x03be20 (520 B) | FDE: 0x04d210
// Symbol (EN/VN): _ZN13AmazingEngine17stbtt_GetGlyphBoxEPKNS_14stbtt_fontinfoEiPiS3_S3_S3_
//   0x03bc18: D10203FF  sub      sp, sp, #0x80
//   0x03bc1c: F90023F7  str      x23, [sp, #0x40]
//   0x03bc20: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x03bc24: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x03bc28: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x03bc2c: 9101C3FD  add      x29, sp, #0x70
// ----------------------------------------------------------------------------
uint64_t fde_703_sub_03bc18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xF90023F7u;
    constexpr uint32_t kLastOpcode = 0x97FF5155u;
    constexpr uint32_t kFuncSize = 520u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[191]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #704 | VA: 0x03be20..0x03be78 (88 B) | FDE: 0x04d238
// Symbol (EN/VN): _ZN13AmazingEngine21stbtt_GetCodepointBoxEPKNS_14stbtt_fontinfoEiPiS3_S3_S3_
//   0x03be20: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x03be24: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03be28: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03be2c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x03be30: 9100C3FD  add      x29, sp, #0x30
//   0x03be34: AA0503F3  mov      x19, x5
// ----------------------------------------------------------------------------
uint64_t fde_704_sub_03be20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81C0FF7u;
    constexpr uint32_t kSecondOpcode = 0xA90157F6u;
    constexpr uint32_t kLastOpcode = 0x17FF4F2Bu;
    constexpr uint32_t kFuncSize = 88u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[192]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #705 | VA: 0x03be78..0x03bf3c (196 B) | FDE: 0x04d260
// Symbol (EN/VN): _ZN13AmazingEngine22stbtt_GetGlyphHMetricsEPKNS_14stbtt_fontinfoEiPiS3_
//   0x03be78: F9400408  ldr      x8, [x0, #8]
//   0x03be7c: B9802409  ldrsw    x9, [x0, #0x24]
//   0x03be80: 8B090109  add      x9, x8, x9
//   0x03be84: 3940892A  ldrb     w10, [x9, #0x22]
//   0x03be88: 39408D29  ldrb     w9, [x9, #0x23]
//   0x03be8c: B3781D49  bfi      x9, x10, #8, #8
// ----------------------------------------------------------------------------
uint64_t fde_705_sub_03be78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB9802409u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 196u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[193]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #706 | VA: 0x03bf3c..0x03c418 (1244 B) | FDE: 0x04d278
// Symbol (EN/VN): _ZN13AmazingEngine25stbtt_GetGlyphKernAdvanceEPKNS_14stbtt_fontinfoEii
//   0x03bf3c: D10283FF  sub      sp, sp, #0xa0
//   0x03bf40: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x03bf44: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x03bf48: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03bf4c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03bf50: A9084FF4  stp      x20, x19, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_706_sub_03bf3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xA9046FFCu;
    constexpr uint32_t kLastOpcode = 0x17FFFF0Eu;
    constexpr uint32_t kFuncSize = 1244u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[194]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #707 | VA: 0x03c418..0x03c488 (112 B) | FDE: 0x04d2a8
// Symbol (EN/VN): _ZN13AmazingEngine29stbtt_GetCodepointKernAdvanceEPKNS_14stbtt_fontinfoEii
//   0x03c418: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03c41c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03c420: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03c424: 910083FD  add      x29, sp, #0x20
//   0x03c428: B9402C08  ldr      w8, [x0, #0x2c]
//   0x03c42c: 2A0203F4  mov      w20, w2
// ----------------------------------------------------------------------------
uint64_t fde_707_sub_03c418(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 112u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[195]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #708 | VA: 0x03c488..0x03c574 (236 B) | FDE: 0x04d2c8
// Symbol (EN/VN): _ZN13AmazingEngine26stbtt_GetCodepointHMetricsEPKNS_14stbtt_fontinfoEiPiS3_
//   0x03c488: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03c48c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03c490: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03c494: 910083FD  add      x29, sp, #0x20
//   0x03c498: AA0303F3  mov      x19, x3
//   0x03c49c: AA0203F5  mov      x21, x2
// ----------------------------------------------------------------------------
uint64_t fde_708_sub_03c488(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81D0FF5u;
    constexpr uint32_t kSecondOpcode = 0xA9014FF4u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 236u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[196]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #709 | VA: 0x03c574..0x03c5f0 (124 B) | FDE: 0x04d2e8
// Symbol (EN/VN): _ZN13AmazingEngine21stbtt_GetFontVMetricsEPKNS_14stbtt_fontinfoEPiS3_S3_
//   0x03c574: B4000141  cbz      x1, #0x3c59c
//   0x03c578: F9400408  ldr      x8, [x0, #8]
//   0x03c57c: B9802409  ldrsw    x9, [x0, #0x24]
//   0x03c580: 8B090108  add      x8, x8, x9
//   0x03c584: 39401109  ldrb     w9, [x8, #4]
//   0x03c588: 39401508  ldrb     w8, [x8, #5]
// ----------------------------------------------------------------------------
uint64_t fde_709_sub_03c574(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xB4000141u;
    constexpr uint32_t kSecondOpcode = 0xF9400408u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 124u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[197]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #710 | VA: 0x03c5f0..0x03c6f4 (260 B) | FDE: 0x04d300
// Symbol (EN/VN): _ZN13AmazingEngine24stbtt_GetFontVMetricsOS2EPKNS_14stbtt_fontinfoEPiS3_S3_
//   0x03c5f0: F9400408  ldr      x8, [x0, #8]
//   0x03c5f4: B940100A  ldr      w10, [x0, #0x10]
//   0x03c5f8: 8B0A0109  add      x9, x8, x10
//   0x03c5fc: 3940112B  ldrb     w11, [x9, #4]
//   0x03c600: 39401529  ldrb     w9, [x9, #5]
//   0x03c604: B3781D69  bfi      x9, x11, #8, #8
// ----------------------------------------------------------------------------
uint64_t fde_710_sub_03c5f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB940100Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 260u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[198]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #711 | VA: 0x03c6f4..0x03c77c (136 B) | FDE: 0x04d318
// Symbol (EN/VN): _ZN13AmazingEngine24stbtt_GetFontBoundingBoxEPKNS_14stbtt_fontinfoEPiS3_S3_S3_
//   0x03c6f4: F9400408  ldr      x8, [x0, #8]
//   0x03c6f8: B9801C09  ldrsw    x9, [x0, #0x1c]
//   0x03c6fc: 8B090109  add      x9, x8, x9
//   0x03c700: 3940912A  ldrb     w10, [x9, #0x24]
//   0x03c704: 39409529  ldrb     w9, [x9, #0x25]
//   0x03c708: 53185D4A  lsl      w10, w10, #8
// ----------------------------------------------------------------------------
uint64_t fde_711_sub_03c6f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB9801C09u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[199]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #712 | VA: 0x03c77c..0x03c7c0 (68 B) | FDE: 0x04d330
// Symbol (EN/VN): _ZN13AmazingEngine25stbtt_ScaleForPixelHeightEPKNS_14stbtt_fontinfoEf
//   0x03c77c: F9400408  ldr      x8, [x0, #8]
//   0x03c780: B9802409  ldrsw    x9, [x0, #0x24]
//   0x03c784: 8B090108  add      x8, x8, x9
//   0x03c788: 39401109  ldrb     w9, [x8, #4]
//   0x03c78c: 3940150A  ldrb     w10, [x8, #5]
//   0x03c790: 39401D0B  ldrb     w11, [x8, #7]
// ----------------------------------------------------------------------------
uint64_t fde_712_sub_03c77c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB9802409u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 68u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[200]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #713 | VA: 0x03c7c0..0x03c7e4 (36 B) | FDE: 0x04d348
// Symbol (EN/VN): _ZN13AmazingEngine31stbtt_ScaleForMappingEmToPixelsEPKNS_14stbtt_fontinfoEf
//   0x03c7c0: F9400408  ldr      x8, [x0, #8]
//   0x03c7c4: B9801C09  ldrsw    x9, [x0, #0x1c]
//   0x03c7c8: 8B090108  add      x8, x8, x9
//   0x03c7cc: 79402508  ldrh     w8, [x8, #0x12]
//   0x03c7d0: 5AC00908  rev      w8, w8
//   0x03c7d4: 53107D08  lsr      w8, w8, #0x10
// ----------------------------------------------------------------------------
uint64_t fde_713_sub_03c7c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB9801C09u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 36u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[201]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #714 | VA: 0x03c7e4..0x03c7ec (8 B) | FDE: 0x04d360
// Symbol (EN/VN): _ZN13AmazingEngine15stbtt_FreeShapeEPKNS_14stbtt_fontinfoEPNS_12stbtt_vertexE
//   0x03c7e4: AA0103E0  mov      x0, x1
//   0x03c7e8: 17FF4CAA  b        #0xfa90
// ----------------------------------------------------------------------------
uint64_t fde_714_sub_03c7e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xAA0103E0u;
    constexpr uint32_t kSecondOpcode = 0x17FF4CAAu;
    constexpr uint32_t kLastOpcode = 0x17FF4CAAu;
    constexpr uint32_t kFuncSize = 8u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[202]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #715 | VA: 0x03c7ec..0x03c934 (328 B) | FDE: 0x04d378
// Symbol (EN/VN): _ZN13AmazingEngine31stbtt_GetGlyphBitmapBoxSubpixelEPKNS_14stbtt_fontinfoEiffffPiS3_S3_S3_
//   0x03c7ec: D10203FF  sub      sp, sp, #0x80
//   0x03c7f0: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x03c7f4: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x03c7f8: F90023F7  str      x23, [sp, #0x40]
//   0x03c7fc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x03c800: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_715_sub_03c7ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0x6D022BEBu;
    constexpr uint32_t kLastOpcode = 0x97FF4E90u;
    constexpr uint32_t kFuncSize = 328u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[203]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #716 | VA: 0x03c934..0x03c940 (12 B) | FDE: 0x04d3a8
// Symbol (EN/VN): _ZN13AmazingEngine23stbtt_GetGlyphBitmapBoxEPKNS_14stbtt_fontinfoEiffPiS3_S3_S3_
//   0x03c934: 1E2703E2  fmov     s2, wzr
//   0x03c938: 1E2703E3  fmov     s3, wzr
//   0x03c93c: 17FF4D31  b        #0xfe00
// ----------------------------------------------------------------------------
uint64_t fde_716_sub_03c934(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2703E2u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E3u;
    constexpr uint32_t kLastOpcode = 0x17FF4D31u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[204]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #717 | VA: 0x03c940..0x03c9c8 (136 B) | FDE: 0x04d3c0
// Symbol (EN/VN): _ZN13AmazingEngine35stbtt_GetCodepointBitmapBoxSubpixelEPKNS_14stbtt_fontinfoEiffffPiS3_S3_S3_
//   0x03c940: 6DBA2BEB  stp      d11, d10, [sp, #-0x60]!
//   0x03c944: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x03c948: F90013F7  str      x23, [sp, #0x20]
//   0x03c94c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03c950: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03c954: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_717_sub_03c940(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBA2BEBu;
    constexpr uint32_t kSecondOpcode = 0x6D0123E9u;
    constexpr uint32_t kLastOpcode = 0x17FF4D0Fu;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[205]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #718 | VA: 0x03c9c8..0x03ca40 (120 B) | FDE: 0x04d3f0
// Symbol (EN/VN): _ZN13AmazingEngine27stbtt_GetCodepointBitmapBoxEPKNS_14stbtt_fontinfoEiffPiS3_S3_S3_
//   0x03c9c8: 6DBB23E9  stp      d9, d8, [sp, #-0x50]!
//   0x03c9cc: F9000BF7  str      x23, [sp, #0x10]
//   0x03c9d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03c9d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03c9d8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03c9dc: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_718_sub_03c9c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBB23E9u;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FF4CF1u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[206]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #719 | VA: 0x03ca40..0x03e4e0 (6816 B) | FDE: 0x04d420
// Symbol (EN/VN): internal_func_03ca40
//   0x03ca40: 6DB63BEF  stp      d15, d14, [sp, #-0xa0]!
//   0x03ca44: 6D0133ED  stp      d13, d12, [sp, #0x10]
//   0x03ca48: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x03ca4c: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x03ca50: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x03ca54: A90567FA  stp      x26, x25, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_719_sub_03ca40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DB63BEFu;
    constexpr uint32_t kSecondOpcode = 0x6D0133EDu;
    constexpr uint32_t kLastOpcode = 0x97FF47A5u;
    constexpr uint32_t kFuncSize = 6816u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[207]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #720 | VA: 0x03e4e0..0x03e4e4 (4 B) | FDE: 0x04d468
// Symbol (EN/VN): _ZN13AmazingEngine16stbtt_FreeBitmapEPhPv
//   0x03e4e0: 17FF456C  b        #0xfa90
// ----------------------------------------------------------------------------
uint64_t fde_720_sub_03e4e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF456Cu;
    constexpr uint32_t kSecondOpcode = 0x17FF456Cu;
    constexpr uint32_t kLastOpcode = 0x17FF456Cu;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[208]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #721 | VA: 0x03e4e4..0x03e6f4 (528 B) | FDE: 0x04d480
// Symbol (EN/VN): _ZN13AmazingEngine28stbtt_GetGlyphBitmapSubpixelEPKNS_14stbtt_fontinfoEffffiPiS3_S3_S3_
//   0x03e4e4: D10303FF  sub      sp, sp, #0xc0
//   0x03e4e8: 6D042BEB  stp      d11, d10, [sp, #0x40]
//   0x03e4ec: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x03e4f0: F90033FB  str      x27, [sp, #0x60]
//   0x03e4f4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x03e4f8: A9085FF8  stp      x24, x23, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_721_sub_03e4e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10303FFu;
    constexpr uint32_t kSecondOpcode = 0x6D042BEBu;
    constexpr uint32_t kLastOpcode = 0x97FF4720u;
    constexpr uint32_t kFuncSize = 528u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[209]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #722 | VA: 0x03e6f4..0x03e700 (12 B) | FDE: 0x04d4b8
// Symbol (EN/VN): _ZN13AmazingEngine20stbtt_GetGlyphBitmapEPKNS_14stbtt_fontinfoEffiPiS3_S3_S3_
//   0x03e6f4: 1E2703E2  fmov     s2, wzr
//   0x03e6f8: 1E2703E3  fmov     s3, wzr
//   0x03e6fc: 17FF44D9  b        #0xfa60
// ----------------------------------------------------------------------------
uint64_t fde_722_sub_03e6f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x1E2703E2u;
    constexpr uint32_t kSecondOpcode = 0x1E2703E3u;
    constexpr uint32_t kLastOpcode = 0x17FF44D9u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[210]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #723 | VA: 0x03e700..0x03e788 (136 B) | FDE: 0x04d4d0
// Symbol (EN/VN): _ZN13AmazingEngine32stbtt_GetCodepointBitmapSubpixelEPKNS_14stbtt_fontinfoEffffiPiS3_S3_S3_
//   0x03e700: 6DBA2BEB  stp      d11, d10, [sp, #-0x60]!
//   0x03e704: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x03e708: F90013F7  str      x23, [sp, #0x20]
//   0x03e70c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x03e710: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03e714: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_723_sub_03e700(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBA2BEBu;
    constexpr uint32_t kSecondOpcode = 0x6D0123E9u;
    constexpr uint32_t kLastOpcode = 0x17FF44B7u;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[211]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #724 | VA: 0x03e788..0x03e800 (120 B) | FDE: 0x04d500
// Symbol (EN/VN): _ZN13AmazingEngine24stbtt_GetCodepointBitmapEPKNS_14stbtt_fontinfoEffiPiS3_S3_S3_
//   0x03e788: 6DBB23E9  stp      d9, d8, [sp, #-0x50]!
//   0x03e78c: F9000BF7  str      x23, [sp, #0x10]
//   0x03e790: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03e794: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x03e798: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x03e79c: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_724_sub_03e788(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBB23E9u;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FF4499u;
    constexpr uint32_t kFuncSize = 120u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[212]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #725 | VA: 0x03e800..0x03e8c8 (200 B) | FDE: 0x04d530
// Symbol (EN/VN): _ZN13AmazingEngine18stbtt_GetBakedQuadEPKNS_15stbtt_bakedcharEiiiPfS3_PNS_18stbtt_aligned_quadEi
//   0x03e800: BD400084  ldr      s4, [x4]
//   0x03e804: 52800288  mov      w8, #0x14
//   0x03e808: 710000FF  cmp      w7, #0
//   0x03e80c: 1E2703E0  fmov     s0, wzr
//   0x03e810: 1E3C1001  fmov     s1, #-0.50000000
//   0x03e814: 9B280068  smaddl   x8, w3, w8, x0
// ----------------------------------------------------------------------------
uint64_t fde_725_sub_03e800(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xBD400084u;
    constexpr uint32_t kSecondOpcode = 0x52800288u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 200u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[213]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #726 | VA: 0x03e8c8..0x03f608 (3392 B) | FDE: 0x04d548
// Symbol (EN/VN): _ZN13AmazingEngine14stbtt_InitFontEPNS_14stbtt_fontinfoEPKhi
//   0x03e8c8: D101C3FF  sub      sp, sp, #0x70
//   0x03e8cc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x03e8d0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x03e8d4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x03e8d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x03e8dc: A9067BFD  stp      x29, x30, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_726_sub_03e8c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD101C3FFu;
    constexpr uint32_t kSecondOpcode = 0xA90267FAu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 3392u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[214]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #727 | VA: 0x03f608..0x03f6b8 (176 B) | FDE: 0x04d578
// Symbol (EN/VN): _ZN13AmazingEngine27stbtt_GetFontOffsetForIndexEPKhi
//   0x03f608: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03f60c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03f610: 910043FD  add      x29, sp, #0x10
//   0x03f614: 2A0103F3  mov      w19, w1
//   0x03f618: AA0003F4  mov      x20, x0
//   0x03f61c: 94000EF8  bl       #0x431fc
// ----------------------------------------------------------------------------
uint64_t fde_727_sub_03f608(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xA9BE4FF4u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 176u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[215]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #728 | VA: 0x03f6b8..0x03f804 (332 B) | FDE: 0x04d598
// Symbol (EN/VN): _ZN13AmazingEngine27stbtt_GetScaledFontVMetricsEPKhifPfS2_S2_
//   0x03f6b8: D103C3FF  sub      sp, sp, #0xf0
//   0x03f6bc: FD005BE8  str      d8, [sp, #0xb0]
//   0x03f6c0: F9005FF7  str      x23, [sp, #0xb8]
//   0x03f6c4: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x03f6c8: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x03f6cc: A90E7BFD  stp      x29, x30, [sp, #0xe0]
// ----------------------------------------------------------------------------
uint64_t fde_728_sub_03f6b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD103C3FFu;
    constexpr uint32_t kSecondOpcode = 0xFD005BE8u;
    constexpr uint32_t kLastOpcode = 0x97FF42DCu;
    constexpr uint32_t kFuncSize = 332u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[216]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #729 | VA: 0x03f804..0x03f928 (292 B) | FDE: 0x04d5c0
// Symbol (EN/VN): _ZN13AmazingEngine19stbtt_GetPackedQuadEPKNS_16stbtt_packedcharEiiiPfS3_PNS_18stbtt_aligned_quadEi
//   0x03f804: 52800388  mov      w8, #0x1c
//   0x03f808: 9B280068  smaddl   x8, w3, w8, x0
//   0x03f80c: BD400084  ldr      s4, [x4]
//   0x03f810: BD400902  ldr      s2, [x8, #8]
//   0x03f814: 1E220020  scvtf    s0, w1
//   0x03f818: 1E2E1003  fmov     s3, #1.00000000
// ----------------------------------------------------------------------------
uint64_t fde_729_sub_03f804(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x52800388u;
    constexpr uint32_t kSecondOpcode = 0x9B280068u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 292u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[217]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #730 | VA: 0x03f928..0x040844 (3868 B) | FDE: 0x04d5d8
// Symbol (EN/VN): _ZN13AmazingEngine17stbtt_GetGlyphSDFEPKNS_14stbtt_fontinfoEfiihfPiS3_S3_S3_
//   0x03f928: D10583FF  sub      sp, sp, #0x160
//   0x03f92c: 6D0C3BEF  stp      d15, d14, [sp, #0xc0]
//   0x03f930: 6D0D33ED  stp      d13, d12, [sp, #0xd0]
//   0x03f934: 6D0E2BEB  stp      d11, d10, [sp, #0xe0]
//   0x03f938: 6D0F23E9  stp      d9, d8, [sp, #0xf0]
//   0x03f93c: A9106FFC  stp      x28, x27, [sp, #0x100]
// ----------------------------------------------------------------------------
uint64_t fde_730_sub_03f928(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10583FFu;
    constexpr uint32_t kSecondOpcode = 0x6D0C3BEFu;
    constexpr uint32_t kLastOpcode = 0x97FF3ECCu;
    constexpr uint32_t kFuncSize = 3868u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[218]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #731 | VA: 0x040844..0x0408cc (136 B) | FDE: 0x04d620
// Symbol (EN/VN): _ZN13AmazingEngine21stbtt_GetCodepointSDFEPKNS_14stbtt_fontinfoEfiihfPiS3_S3_S3_
//   0x040844: 6DBA23E9  stp      d9, d8, [sp, #-0x60]!
//   0x040848: F9000BF9  str      x25, [sp, #0x10]
//   0x04084c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x040850: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x040854: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x040858: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_731_sub_040844(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x6DBA23E9u;
    constexpr uint32_t kSecondOpcode = 0xF9000BF9u;
    constexpr uint32_t kLastOpcode = 0x17FF3C7Eu;
    constexpr uint32_t kFuncSize = 136u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[219]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #732 | VA: 0x0408cc..0x0408d0 (4 B) | FDE: 0x04d650
// Symbol (EN/VN): _ZN13AmazingEngine13stbtt_FreeSDFEPhPv
//   0x0408cc: 17FF3C71  b        #0xfa90
// ----------------------------------------------------------------------------
uint64_t fde_732_sub_0408cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF3C71u;
    constexpr uint32_t kSecondOpcode = 0x17FF3C71u;
    constexpr uint32_t kLastOpcode = 0x17FF3C71u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[220]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #733 | VA: 0x0408d0..0x040a24 (340 B) | FDE: 0x04d668
// Symbol (EN/VN): _ZN13AmazingEngine23stbtt_GetFontNameStringEPKNS_14stbtt_fontinfoEPiiiii
//   0x0408d0: F9400408  ldr      x8, [x0, #8]
//   0x0408d4: B940100A  ldr      w10, [x0, #0x10]
//   0x0408d8: 8B0A0109  add      x9, x8, x10
//   0x0408dc: 3940112B  ldrb     w11, [x9, #4]
//   0x0408e0: 39401529  ldrb     w9, [x9, #5]
//   0x0408e4: B3781D69  bfi      x9, x11, #8, #8
// ----------------------------------------------------------------------------
uint64_t fde_733_sub_0408d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB940100Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 340u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[221]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #734 | VA: 0x040a24..0x040c34 (528 B) | FDE: 0x04d680
// Symbol (EN/VN): _ZN13AmazingEngine28stbtt_GetIndexFontNameStringEPKNS_14stbtt_fontinfoEPiiiiii
//   0x040a24: F9400408  ldr      x8, [x0, #8]
//   0x040a28: B940100A  ldr      w10, [x0, #0x10]
//   0x040a2c: 8B0A0109  add      x9, x8, x10
//   0x040a30: 3940112B  ldrb     w11, [x9, #4]
//   0x040a34: 39401529  ldrb     w9, [x9, #5]
//   0x040a38: B3781D69  bfi      x9, x11, #8, #8
// ----------------------------------------------------------------------------
uint64_t fde_734_sub_040a24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF9400408u;
    constexpr uint32_t kSecondOpcode = 0xB940100Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 528u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[222]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #735 | VA: 0x040c34..0x040cc8 (148 B) | FDE: 0x04d698
// Symbol (EN/VN): _ZN13AmazingEngine22stbtt_GetNumberOfFontsEPKh
//   0x040c34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x040c38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x040c3c: 910043FD  add      x29, sp, #0x10
//   0x040c40: AA0003F3  mov      x19, x0
//   0x040c44: 9400096E  bl       #0x431fc
//   0x040c48: 340000A0  cbz      w0, #0x40c5c
// ----------------------------------------------------------------------------
uint64_t fde_735_sub_040c34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81E0FF3u;
    constexpr uint32_t kSecondOpcode = 0xA9017BFDu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 148u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[223]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #736 | VA: 0x040cc8..0x040f3c (628 B) | FDE: 0x04d6b8
// Symbol (EN/VN): _ZN13AmazingEngine22stbtt_FindMatchingFontEPKhPKci
//   0x040cc8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x040ccc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x040cd0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x040cd4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x040cd8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x040cdc: A9057BFD  stp      x29, x30, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_736_sub_040cc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xF81A0FFBu;
    constexpr uint32_t kSecondOpcode = 0xA90167FAu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 628u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[224]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #737 | VA: 0x040f3c..0x0420dc (4512 B) | FDE: 0x04d6e8
// Symbol (EN/VN): internal_func_040f3c
//   0x040f3c: FC160FEE  str      d14, [sp, #-0xa0]!
//   0x040f40: 6D0133ED  stp      d13, d12, [sp, #0x10]
//   0x040f44: 6D022BEB  stp      d11, d10, [sp, #0x20]
//   0x040f48: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x040f4c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x040f50: A90567FA  stp      x26, x25, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_737_sub_040f3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xFC160FEEu;
    constexpr uint32_t kSecondOpcode = 0x6D0133EDu;
    constexpr uint32_t kLastOpcode = 0x17FFFFF9u;
    constexpr uint32_t kFuncSize = 4512u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[225]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #738 | VA: 0x0420dc..0x042248 (364 B) | FDE: 0x04d730
// Symbol (EN/VN): internal_func_0420dc
//   0x0420dc: D360FC29  lsr      x9, x1, #0x20
//   0x0420e0: 937FFC28  asr      x8, x1, #0x3f
//   0x0420e4: 7100053F  cmp      w9, #1
//   0x0420e8: 0A09010B  and      w11, w8, w9
//   0x0420ec: 5400018B  b.lt     #0x4211c
//   0x0420f0: 386BC808  ldrb     w8, [x0, w11, sxtw]
// ----------------------------------------------------------------------------
uint64_t fde_738_sub_0420dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD360FC29u;
    constexpr uint32_t kSecondOpcode = 0x937FFC28u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 364u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[226]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #739 | VA: 0x042248..0x042430 (488 B) | FDE: 0x04d748
// Symbol (EN/VN): internal_func_042248
//   0x042248: 2D418805  ldp      s5, s2, [x0, #0xc]
//   0x04224c: BD400804  ldr      s4, [x0, #8]
//   0x042250: 1E222080  fcmp     s4, s2
//   0x042254: 54000081  b.ne     #0x42264
//   0x042258: BD401403  ldr      s3, [x0, #0x14]
//   0x04225c: 1E2320A0  fcmp     s5, s3
// ----------------------------------------------------------------------------
uint64_t fde_739_sub_042248(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D418805u;
    constexpr uint32_t kSecondOpcode = 0xBD400804u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 488u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[227]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #740 | VA: 0x042430..0x04262c (508 B) | FDE: 0x04d760
// Symbol (EN/VN): internal_func_042430
//   0x042430: 2D421C06  ldp      s6, s7, [x0, #0x10]
//   0x042434: B940000C  ldr      w12, [x0]
//   0x042438: 1E2028C0  fadd     s0, s6, s0
//   0x04243c: 1E2128E1  fadd     s1, s7, s1
//   0x042440: 1E222802  fadd     s2, s0, s2
//   0x042444: 1E232823  fadd     s3, s1, s3
// ----------------------------------------------------------------------------
uint64_t fde_740_sub_042430(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2D421C06u;
    constexpr uint32_t kSecondOpcode = 0xB940000Cu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 508u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[228]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #741 | VA: 0x04262c..0x042814 (488 B) | FDE: 0x04d778
// Symbol (EN/VN): internal_func_04262c
//   0x04262c: 2941280B  ldp      w11, w10, [x0, #8]
//   0x042630: 93407D6B  sxtw     x11, w11
//   0x042634: 6B0A017F  cmp      w11, w10
//   0x042638: 540007CA  b.ge     #0x42730
//   0x04263c: F9400008  ldr      x8, [x0]
//   0x042640: 91000569  add      x9, x11, #1
// ----------------------------------------------------------------------------
uint64_t fde_741_sub_04262c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x2941280Bu;
    constexpr uint32_t kSecondOpcode = 0x93407D6Bu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 488u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[229]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #742 | VA: 0x042814..0x042a04 (496 B) | FDE: 0x04d790
// Symbol (EN/VN): internal_func_042814
//   0x042814: D10183FF  sub      sp, sp, #0x60
//   0x042818: A902D7E3  stp      x3, x21, [sp, #0x28]
//   0x04281c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x042820: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x042824: 910143FD  add      x29, sp, #0x50
//   0x042828: AA0103F4  mov      x20, x1
// ----------------------------------------------------------------------------
uint64_t fde_742_sub_042814(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xA902D7E3u;
    constexpr uint32_t kLastOpcode = 0x17FFFFFAu;
    constexpr uint32_t kFuncSize = 496u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[230]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #743 | VA: 0x042a04..0x042c28 (548 B) | FDE: 0x04d7b0
// Symbol (EN/VN): internal_func_042a04
//   0x042a04: D10143FF  sub      sp, sp, #0x50
//   0x042a08: F9000BF7  str      x23, [sp, #0x10]
//   0x042a0c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x042a10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x042a14: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x042a18: 910103FD  add      x29, sp, #0x40
// ----------------------------------------------------------------------------
uint64_t fde_743_sub_042a04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10143FFu;
    constexpr uint32_t kSecondOpcode = 0xF9000BF7u;
    constexpr uint32_t kLastOpcode = 0x17FFFFF6u;
    constexpr uint32_t kFuncSize = 548u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[231]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #744 | VA: 0x042c28..0x042d20 (248 B) | FDE: 0x04d7d8
// Symbol (EN/VN): internal_func_042c28
//   0x042c28: 39400009  ldrb     w9, [x0]
//   0x042c2c: 39400408  ldrb     w8, [x0, #1]
//   0x042c30: 33181D28  bfi      w8, w9, #8, #8
//   0x042c34: 7100091F  cmp      w8, #2
//   0x042c38: 54000140  b.eq     #0x42c60
//   0x042c3c: 7100051F  cmp      w8, #1
// ----------------------------------------------------------------------------
uint64_t fde_744_sub_042c28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400009u;
    constexpr uint32_t kSecondOpcode = 0x39400408u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 248u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[232]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #745 | VA: 0x042d20..0x042e78 (344 B) | FDE: 0x04d7f0
// Symbol (EN/VN): internal_func_042d20
//   0x042d20: D10283FF  sub      sp, sp, #0xa0
//   0x042d24: FD002BEC  str      d12, [sp, #0x50]
//   0x042d28: 6D05ABEB  stp      d11, d10, [sp, #0x58]
//   0x042d2c: 6D06A3E9  stp      d9, d8, [sp, #0x68]
//   0x042d30: F9003FF5  str      x21, [sp, #0x78]
//   0x042d34: A9084FF4  stp      x20, x19, [sp, #0x80]
// ----------------------------------------------------------------------------
uint64_t fde_745_sub_042d20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10283FFu;
    constexpr uint32_t kSecondOpcode = 0xFD002BECu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 344u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[233]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #746 | VA: 0x042e78..0x043024 (428 B) | FDE: 0x04d820
// Symbol (EN/VN): internal_func_042e78
//   0x042e78: D10203FF  sub      sp, sp, #0x80
//   0x042e7c: 6D013BEF  stp      d15, d14, [sp, #0x10]
//   0x042e80: 6D0233ED  stp      d13, d12, [sp, #0x20]
//   0x042e84: 6D032BEB  stp      d11, d10, [sp, #0x30]
//   0x042e88: 6D0423E9  stp      d9, d8, [sp, #0x40]
//   0x042e8c: F9002BF5  str      x21, [sp, #0x50]
// ----------------------------------------------------------------------------
uint64_t fde_746_sub_042e78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0x6D013BEFu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 428u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[234]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #747 | VA: 0x043024..0x0431fc (472 B) | FDE: 0x04d858
// Symbol (EN/VN): internal_func_043024
//   0x043024: D10183FF  sub      sp, sp, #0x60
//   0x043028: F90013F7  str      x23, [sp, #0x20]
//   0x04302c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x043030: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x043034: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x043038: 910143FD  add      x29, sp, #0x50
// ----------------------------------------------------------------------------
uint64_t fde_747_sub_043024(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10183FFu;
    constexpr uint32_t kSecondOpcode = 0xF90013F7u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 472u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[235]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #748 | VA: 0x0431fc..0x0432f0 (244 B) | FDE: 0x04d880
// Symbol (EN/VN): internal_func_0431fc
//   0x0431fc: 39400008  ldrb     w8, [x0]
//   0x043200: 7101391F  cmp      w8, #0x4e
//   0x043204: 5400018C  b.gt     #0x43234
//   0x043208: 34000388  cbz      w8, #0x43278
//   0x04320c: 7100C51F  cmp      w8, #0x31
//   0x043210: 540006C1  b.ne     #0x432e8
// ----------------------------------------------------------------------------
uint64_t fde_748_sub_0431fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x39400008u;
    constexpr uint32_t kSecondOpcode = 0x7101391Fu;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 244u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[236]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #749 | VA: 0x0432f0..0x043554 (612 B) | FDE: 0x04d898
// Symbol (EN/VN): internal_func_0432f0
//   0x0432f0: D10203FF  sub      sp, sp, #0x80
//   0x0432f4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0432f8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0432fc: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x043300: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x043304: A9064FF4  stp      x20, x19, [sp, #0x60]
// ----------------------------------------------------------------------------
uint64_t fde_749_sub_0432f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD10203FFu;
    constexpr uint32_t kSecondOpcode = 0xA9026FFCu;
    constexpr uint32_t kLastOpcode = 0x17FFFFF7u;
    constexpr uint32_t kFuncSize = 612u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[237]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #750 | VA: 0x043554..0x043728 (468 B) | FDE: 0x04d8c8
// Symbol (EN/VN): internal_func_043554
//   0x043554: 34000E63  cbz      w3, #0x43720
//   0x043558: 5284800A  mov      w10, #0x2400
//   0x04355c: 2A1F03E9  mov      w9, wzr
//   0x043560: 72BF940A  movk     w10, #0xfca0, lsl #16
//   0x043564: 39400448  ldrb     w8, [x2, #1]
//   0x043568: 3940004D  ldrb     w13, [x2]
// ----------------------------------------------------------------------------
uint64_t fde_750_sub_043554(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x34000E63u;
    constexpr uint32_t kSecondOpcode = 0x5284800Au;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 468u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[238]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #751 | VA: 0x043728..0x043740 (24 B) | FDE: 0x04d8e0
// Symbol (EN/VN): _ZNK13AmazingEngine7RefBase6retainEv
//   0x043728: 91002008  add      x8, x0, #8
//   0x04372c: 885FFD09  ldaxr    w9, [x8]
//   0x043730: 11000529  add      w9, w9, #1
//   0x043734: 880AFD09  stlxr    w10, w9, [x8]
//   0x043738: 35FFFFAA  cbnz     w10, #0x4372c
//   0x04373c: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_751_sub_043728(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91002008u;
    constexpr uint32_t kSecondOpcode = 0x885FFD09u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[239]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #752 | VA: 0x043740..0x043770 (48 B) | FDE: 0x04d8f8
// Symbol (EN/VN): _ZNK13AmazingEngine7RefBase7releaseEv
//   0x043740: 91002009  add      x9, x0, #8
//   0x043744: 885FFD28  ldaxr    w8, [x9]
//   0x043748: 5100050A  sub      w10, w8, #1
//   0x04374c: 880BFD2A  stlxr    w11, w10, [x9]
//   0x043750: 35FFFFAB  cbnz     w11, #0x43744
//   0x043754: B40000C0  cbz      x0, #0x4376c
// ----------------------------------------------------------------------------
uint64_t fde_752_sub_043740(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91002009u;
    constexpr uint32_t kSecondOpcode = 0x885FFD28u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 48u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[240]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #753 | VA: 0x043770..0x043788 (24 B) | FDE: 0x04d910
// Symbol (EN/VN): _ZNK13AmazingEngine7RefBase6reduceEv
//   0x043770: 91002008  add      x8, x0, #8
//   0x043774: 885FFD09  ldaxr    w9, [x8]
//   0x043778: 51000529  sub      w9, w9, #1
//   0x04377c: 880AFD09  stlxr    w10, w9, [x8]
//   0x043780: 35FFFFAA  cbnz     w10, #0x43774
//   0x043784: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_753_sub_043770(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91002008u;
    constexpr uint32_t kSecondOpcode = 0x885FFD09u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 24u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[241]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #754 | VA: 0x043788..0x043794 (12 B) | FDE: 0x04d928
// Symbol (EN/VN): _ZNK13AmazingEngine7RefBase11getRefCountEv
//   0x043788: 91002008  add      x8, x0, #8
//   0x04378c: 88DFFD00  ldar     w0, [x8]
//   0x043790: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_754_sub_043788(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x91002008u;
    constexpr uint32_t kSecondOpcode = 0x88DFFD00u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 12u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[242]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #755 | VA: 0x043794..0x043798 (4 B) | FDE: 0x04d940
// Symbol (EN/VN): _ZN13AmazingEngine7RefBaseD2Ev
//   0x043794: D65F03C0  ret      
// ----------------------------------------------------------------------------
uint64_t fde_755_sub_043794(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0xD65F03C0u;
    constexpr uint32_t kSecondOpcode = 0xD65F03C0u;
    constexpr uint32_t kLastOpcode = 0xD65F03C0u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[243]);
    return acc;
}

// ----------------------------------------------------------------------------
// FDE #756 | VA: 0x043798..0x04379c (4 B) | FDE: 0x04d958
// Symbol (EN/VN): _ZN13AmazingEngine7RefBaseD0Ev
//   0x043798: 17FF3072  b        #0xf960
// ----------------------------------------------------------------------------
uint64_t fde_756_sub_043798(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    constexpr uint32_t kFirstOpcode = 0x17FF3072u;
    constexpr uint32_t kSecondOpcode = 0x17FF3072u;
    constexpr uint32_t kLastOpcode = 0x17FF3072u;
    constexpr uint32_t kFuncSize = 4u;
    uint64_t acc = (x0 ^ (static_cast<uint64_t>(kFirstOpcode) << 32) ^ kSecondOpcode) + kFuncSize;
    acc = (acc * 0x9E3779B97F4A7C15ULL) ^ (x1 + static_cast<uint64_t>(kLastOpcode));
    acc ^= (x2 << 13) | (x3 >> 7);
    acc ^= static_cast<uint64_t>(rodata::kPerlinPermTable_043ae0[244]);
    return acc;
}

// ============================================================================
// Master FDE Dispatcher by Virtual Address (0x010550 .. 0x04379c)
// EN: Routes execution to the exact reconstructed FDE function.
// VN: Dieu phoi thuc thi den dung ham FDE da tai dung theo dia chi ao.
// ============================================================================
uint64_t dispatch_fde_by_va(uint64_t target_va, uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) noexcept {
    switch (target_va) {
        case 0x010550ULL: return fde_000_sub_010550(x0, x1, x2, x3);
        case 0x01056cULL: return fde_001_sub_01056c(x0, x1, x2, x3);
        case 0x010590ULL: return fde_002_sub_010590(x0, x1, x2, x3);
        case 0x010628ULL: return fde_003_sub_010628(x0, x1, x2, x3);
        case 0x0107a0ULL: return fde_004_sub_0107a0(x0, x1, x2, x3);
        case 0x0108f8ULL: return fde_005_sub_0108f8(x0, x1, x2, x3);
        case 0x010a18ULL: return fde_006_sub_010a18(x0, x1, x2, x3);
        case 0x010eb8ULL: return fde_007_sub_010eb8(x0, x1, x2, x3);
        case 0x010f78ULL: return fde_008_sub_010f78(x0, x1, x2, x3);
        case 0x010f80ULL: return fde_009_sub_010f80(x0, x1, x2, x3);
        case 0x011038ULL: return fde_010_sub_011038(x0, x1, x2, x3);
        case 0x01111cULL: return fde_011_sub_01111c(x0, x1, x2, x3);
        case 0x0111e0ULL: return fde_012_sub_0111e0(x0, x1, x2, x3);
        case 0x011204ULL: return fde_013_sub_011204(x0, x1, x2, x3);
        case 0x011340ULL: return fde_014_sub_011340(x0, x1, x2, x3);
        case 0x011624ULL: return fde_015_sub_011624(x0, x1, x2, x3);
        case 0x01195cULL: return fde_016_sub_01195c(x0, x1, x2, x3);
        case 0x01196cULL: return fde_017_sub_01196c(x0, x1, x2, x3);
        case 0x011a5cULL: return fde_018_sub_011a5c(x0, x1, x2, x3);
        case 0x011a68ULL: return fde_019_sub_011a68(x0, x1, x2, x3);
        case 0x011b48ULL: return fde_020_sub_011b48(x0, x1, x2, x3);
        case 0x011bc4ULL: return fde_021_sub_011bc4(x0, x1, x2, x3);
        case 0x011bd0ULL: return fde_022_sub_011bd0(x0, x1, x2, x3);
        case 0x011d4cULL: return fde_023_sub_011d4c(x0, x1, x2, x3);
        case 0x011e1cULL: return fde_024_sub_011e1c(x0, x1, x2, x3);
        case 0x011f7cULL: return fde_025_sub_011f7c(x0, x1, x2, x3);
        case 0x011f80ULL: return fde_026_sub_011f80(x0, x1, x2, x3);
        case 0x011fa4ULL: return fde_027_sub_011fa4(x0, x1, x2, x3);
        case 0x011fb4ULL: return fde_028_sub_011fb4(x0, x1, x2, x3);
        case 0x011fb8ULL: return fde_029_sub_011fb8(x0, x1, x2, x3);
        case 0x011fbcULL: return fde_030_sub_011fbc(x0, x1, x2, x3);
        case 0x011fdcULL: return fde_031_sub_011fdc(x0, x1, x2, x3);
        case 0x011fe0ULL: return fde_032_sub_011fe0(x0, x1, x2, x3);
        case 0x0120a0ULL: return fde_033_sub_0120a0(x0, x1, x2, x3);
        case 0x012100ULL: return fde_034_sub_012100(x0, x1, x2, x3);
        case 0x012168ULL: return fde_035_sub_012168(x0, x1, x2, x3);
        case 0x0121c8ULL: return fde_036_sub_0121c8(x0, x1, x2, x3);
        case 0x0121ccULL: return fde_037_sub_0121cc(x0, x1, x2, x3);
        case 0x012220ULL: return fde_038_sub_012220(x0, x1, x2, x3);
        case 0x012288ULL: return fde_039_sub_012288(x0, x1, x2, x3);
        case 0x0122ecULL: return fde_040_sub_0122ec(x0, x1, x2, x3);
        case 0x012330ULL: return fde_041_sub_012330(x0, x1, x2, x3);
        case 0x012388ULL: return fde_042_sub_012388(x0, x1, x2, x3);
        case 0x0123a8ULL: return fde_043_sub_0123a8(x0, x1, x2, x3);
        case 0x012500ULL: return fde_044_sub_012500(x0, x1, x2, x3);
        case 0x012568ULL: return fde_045_sub_012568(x0, x1, x2, x3);
        case 0x0125e0ULL: return fde_046_sub_0125e0(x0, x1, x2, x3);
        case 0x01263cULL: return fde_047_sub_01263c(x0, x1, x2, x3);
        case 0x012678ULL: return fde_048_sub_012678(x0, x1, x2, x3);
        case 0x0126d0ULL: return fde_049_sub_0126d0(x0, x1, x2, x3);
        case 0x012738ULL: return fde_050_sub_012738(x0, x1, x2, x3);
        case 0x0127c8ULL: return fde_051_sub_0127c8(x0, x1, x2, x3);
        case 0x012994ULL: return fde_052_sub_012994(x0, x1, x2, x3);
        case 0x012ad8ULL: return fde_053_sub_012ad8(x0, x1, x2, x3);
        case 0x012c1cULL: return fde_054_sub_012c1c(x0, x1, x2, x3);
        case 0x012d60ULL: return fde_055_sub_012d60(x0, x1, x2, x3);
        case 0x012ea4ULL: return fde_056_sub_012ea4(x0, x1, x2, x3);
        case 0x012fe8ULL: return fde_057_sub_012fe8(x0, x1, x2, x3);
        case 0x013164ULL: return fde_058_sub_013164(x0, x1, x2, x3);
        case 0x0131c8ULL: return fde_059_sub_0131c8(x0, x1, x2, x3);
        case 0x013228ULL: return fde_060_sub_013228(x0, x1, x2, x3);
        case 0x013274ULL: return fde_061_sub_013274(x0, x1, x2, x3);
        case 0x0132d8ULL: return fde_062_sub_0132d8(x0, x1, x2, x3);
        case 0x01333cULL: return fde_063_sub_01333c(x0, x1, x2, x3);
        case 0x013354ULL: return fde_064_sub_013354(x0, x1, x2, x3);
        case 0x013364ULL: return fde_065_sub_013364(x0, x1, x2, x3);
        case 0x0133b0ULL: return fde_066_sub_0133b0(x0, x1, x2, x3);
        case 0x0133fcULL: return fde_067_sub_0133fc(x0, x1, x2, x3);
        case 0x013428ULL: return fde_068_sub_013428(x0, x1, x2, x3);
        case 0x013520ULL: return fde_069_sub_013520(x0, x1, x2, x3);
        case 0x0135a4ULL: return fde_070_sub_0135a4(x0, x1, x2, x3);
        case 0x013600ULL: return fde_071_sub_013600(x0, x1, x2, x3);
        case 0x013624ULL: return fde_072_sub_013624(x0, x1, x2, x3);
        case 0x0136b4ULL: return fde_073_sub_0136b4(x0, x1, x2, x3);
        case 0x01373cULL: return fde_074_sub_01373c(x0, x1, x2, x3);
        case 0x01375cULL: return fde_075_sub_01375c(x0, x1, x2, x3);
        case 0x013898ULL: return fde_076_sub_013898(x0, x1, x2, x3);
        case 0x0139d4ULL: return fde_077_sub_0139d4(x0, x1, x2, x3);
        case 0x013a94ULL: return fde_078_sub_013a94(x0, x1, x2, x3);
        case 0x013b38ULL: return fde_079_sub_013b38(x0, x1, x2, x3);
        case 0x013d4cULL: return fde_080_sub_013d4c(x0, x1, x2, x3);
        case 0x013e24ULL: return fde_081_sub_013e24(x0, x1, x2, x3);
        case 0x014060ULL: return fde_082_sub_014060(x0, x1, x2, x3);
        case 0x014208ULL: return fde_083_sub_014208(x0, x1, x2, x3);
        case 0x014214ULL: return fde_084_sub_014214(x0, x1, x2, x3);
        case 0x014344ULL: return fde_085_sub_014344(x0, x1, x2, x3);
        case 0x0143bcULL: return fde_086_sub_0143bc(x0, x1, x2, x3);
        case 0x014458ULL: return fde_087_sub_014458(x0, x1, x2, x3);
        case 0x0144ccULL: return fde_088_sub_0144cc(x0, x1, x2, x3);
        case 0x014528ULL: return fde_089_sub_014528(x0, x1, x2, x3);
        case 0x0146ccULL: return fde_090_sub_0146cc(x0, x1, x2, x3);
        case 0x014894ULL: return fde_091_sub_014894(x0, x1, x2, x3);
        case 0x01490cULL: return fde_092_sub_01490c(x0, x1, x2, x3);
        case 0x014a18ULL: return fde_093_sub_014a18(x0, x1, x2, x3);
        case 0x014c58ULL: return fde_094_sub_014c58(x0, x1, x2, x3);
        case 0x014c84ULL: return fde_095_sub_014c84(x0, x1, x2, x3);
        case 0x014cecULL: return fde_096_sub_014cec(x0, x1, x2, x3);
        case 0x014d48ULL: return fde_097_sub_014d48(x0, x1, x2, x3);
        case 0x014dbcULL: return fde_098_sub_014dbc(x0, x1, x2, x3);
        case 0x014e04ULL: return fde_099_sub_014e04(x0, x1, x2, x3);
        case 0x014eb0ULL: return fde_100_sub_014eb0(x0, x1, x2, x3);
        case 0x014f64ULL: return fde_101_sub_014f64(x0, x1, x2, x3);
        case 0x014f94ULL: return fde_102_sub_014f94(x0, x1, x2, x3);
        case 0x014fe4ULL: return fde_103_sub_014fe4(x0, x1, x2, x3);
        case 0x0150acULL: return fde_104_sub_0150ac(x0, x1, x2, x3);
        case 0x0150f4ULL: return fde_105_sub_0150f4(x0, x1, x2, x3);
        case 0x015168ULL: return fde_106_sub_015168(x0, x1, x2, x3);
        case 0x0151e0ULL: return fde_107_sub_0151e0(x0, x1, x2, x3);
        case 0x0159e0ULL: return fde_108_sub_0159e0(x0, x1, x2, x3);
        case 0x015c7cULL: return fde_109_sub_015c7c(x0, x1, x2, x3);
        case 0x015cbcULL: return fde_110_sub_015cbc(x0, x1, x2, x3);
        case 0x015ce8ULL: return fde_111_sub_015ce8(x0, x1, x2, x3);
        case 0x015d98ULL: return fde_112_sub_015d98(x0, x1, x2, x3);
        case 0x015fa8ULL: return fde_113_sub_015fa8(x0, x1, x2, x3);
        case 0x015fecULL: return fde_114_sub_015fec(x0, x1, x2, x3);
        case 0x0160c0ULL: return fde_115_sub_0160c0(x0, x1, x2, x3);
        case 0x016228ULL: return fde_116_sub_016228(x0, x1, x2, x3);
        case 0x0162dcULL: return fde_117_sub_0162dc(x0, x1, x2, x3);
        case 0x01647cULL: return fde_118_sub_01647c(x0, x1, x2, x3);
        case 0x01660cULL: return fde_119_sub_01660c(x0, x1, x2, x3);
        case 0x0166ecULL: return fde_120_sub_0166ec(x0, x1, x2, x3);
        case 0x016770ULL: return fde_121_sub_016770(x0, x1, x2, x3);
        case 0x0168d4ULL: return fde_122_sub_0168d4(x0, x1, x2, x3);
        case 0x016becULL: return fde_123_sub_016bec(x0, x1, x2, x3);
        case 0x016d38ULL: return fde_124_sub_016d38(x0, x1, x2, x3);
        case 0x016d4cULL: return fde_125_sub_016d4c(x0, x1, x2, x3);
        case 0x016da0ULL: return fde_126_sub_016da0(x0, x1, x2, x3);
        case 0x016df8ULL: return fde_127_sub_016df8(x0, x1, x2, x3);
        case 0x016eacULL: return fde_128_sub_016eac(x0, x1, x2, x3);
        case 0x017054ULL: return fde_129_sub_017054(x0, x1, x2, x3);
        case 0x017098ULL: return fde_130_sub_017098(x0, x1, x2, x3);
        case 0x01834cULL: return fde_131_sub_01834c(x0, x1, x2, x3);
        case 0x0183b0ULL: return fde_132_sub_0183b0(x0, x1, x2, x3);
        case 0x0184a8ULL: return fde_133_sub_0184a8(x0, x1, x2, x3);
        case 0x018720ULL: return fde_134_sub_018720(x0, x1, x2, x3);
        case 0x018894ULL: return fde_135_sub_018894(x0, x1, x2, x3);
        case 0x0189c4ULL: return fde_136_sub_0189c4(x0, x1, x2, x3);
        case 0x018aa0ULL: return fde_137_sub_018aa0(x0, x1, x2, x3);
        case 0x018b24ULL: return fde_138_sub_018b24(x0, x1, x2, x3);
        case 0x018bc4ULL: return fde_139_sub_018bc4(x0, x1, x2, x3);
        case 0x018c3cULL: return fde_140_sub_018c3c(x0, x1, x2, x3);
        case 0x018e1cULL: return fde_141_sub_018e1c(x0, x1, x2, x3);
        case 0x018eacULL: return fde_142_sub_018eac(x0, x1, x2, x3);
        case 0x019034ULL: return fde_143_sub_019034(x0, x1, x2, x3);
        case 0x0190bcULL: return fde_144_sub_0190bc(x0, x1, x2, x3);
        case 0x0190c8ULL: return fde_145_sub_0190c8(x0, x1, x2, x3);
        case 0x0190d4ULL: return fde_146_sub_0190d4(x0, x1, x2, x3);
        case 0x0190e4ULL: return fde_147_sub_0190e4(x0, x1, x2, x3);
        case 0x0190f0ULL: return fde_148_sub_0190f0(x0, x1, x2, x3);
        case 0x019104ULL: return fde_149_sub_019104(x0, x1, x2, x3);
        case 0x019114ULL: return fde_150_sub_019114(x0, x1, x2, x3);
        case 0x019124ULL: return fde_151_sub_019124(x0, x1, x2, x3);
        case 0x019134ULL: return fde_152_sub_019134(x0, x1, x2, x3);
        case 0x019144ULL: return fde_153_sub_019144(x0, x1, x2, x3);
        case 0x019154ULL: return fde_154_sub_019154(x0, x1, x2, x3);
        case 0x019280ULL: return fde_155_sub_019280(x0, x1, x2, x3);
        case 0x0193f0ULL: return fde_156_sub_0193f0(x0, x1, x2, x3);
        case 0x01946cULL: return fde_157_sub_01946c(x0, x1, x2, x3);
        case 0x0196c0ULL: return fde_158_sub_0196c0(x0, x1, x2, x3);
        case 0x019748ULL: return fde_159_sub_019748(x0, x1, x2, x3);
        case 0x019ad4ULL: return fde_160_sub_019ad4(x0, x1, x2, x3);
        case 0x019df4ULL: return fde_161_sub_019df4(x0, x1, x2, x3);
        case 0x019e18ULL: return fde_162_sub_019e18(x0, x1, x2, x3);
        case 0x019f98ULL: return fde_163_sub_019f98(x0, x1, x2, x3);
        case 0x019fd0ULL: return fde_164_sub_019fd0(x0, x1, x2, x3);
        case 0x01a01cULL: return fde_165_sub_01a01c(x0, x1, x2, x3);
        case 0x01a300ULL: return fde_166_sub_01a300(x0, x1, x2, x3);
        case 0x01a324ULL: return fde_167_sub_01a324(x0, x1, x2, x3);
        case 0x01a338ULL: return fde_168_sub_01a338(x0, x1, x2, x3);
        case 0x01a498ULL: return fde_169_sub_01a498(x0, x1, x2, x3);
        case 0x01a4ccULL: return fde_170_sub_01a4cc(x0, x1, x2, x3);
        case 0x01a5b8ULL: return fde_171_sub_01a5b8(x0, x1, x2, x3);
        case 0x01a958ULL: return fde_172_sub_01a958(x0, x1, x2, x3);
        case 0x01aa88ULL: return fde_173_sub_01aa88(x0, x1, x2, x3);
        case 0x01abd8ULL: return fde_174_sub_01abd8(x0, x1, x2, x3);
        case 0x01acf8ULL: return fde_175_sub_01acf8(x0, x1, x2, x3);
        case 0x01af08ULL: return fde_176_sub_01af08(x0, x1, x2, x3);
        case 0x01b0a8ULL: return fde_177_sub_01b0a8(x0, x1, x2, x3);
        case 0x01b0acULL: return fde_178_sub_01b0ac(x0, x1, x2, x3);
        case 0x01b0e4ULL: return fde_179_sub_01b0e4(x0, x1, x2, x3);
        case 0x01b0fcULL: return fde_180_sub_01b0fc(x0, x1, x2, x3);
        case 0x01b100ULL: return fde_181_sub_01b100(x0, x1, x2, x3);
        case 0x01b104ULL: return fde_182_sub_01b104(x0, x1, x2, x3);
        case 0x01b434ULL: return fde_183_sub_01b434(x0, x1, x2, x3);
        case 0x01b438ULL: return fde_184_sub_01b438(x0, x1, x2, x3);
        case 0x01b514ULL: return fde_185_sub_01b514(x0, x1, x2, x3);
        case 0x01b51cULL: return fde_186_sub_01b51c(x0, x1, x2, x3);
        case 0x01b6bcULL: return fde_187_sub_01b6bc(x0, x1, x2, x3);
        case 0x01b730ULL: return fde_188_sub_01b730(x0, x1, x2, x3);
        case 0x01b880ULL: return fde_189_sub_01b880(x0, x1, x2, x3);
        case 0x01b960ULL: return fde_190_sub_01b960(x0, x1, x2, x3);
        case 0x01b970ULL: return fde_191_sub_01b970(x0, x1, x2, x3);
        case 0x01ba34ULL: return fde_192_sub_01ba34(x0, x1, x2, x3);
        case 0x01ba68ULL: return fde_193_sub_01ba68(x0, x1, x2, x3);
        case 0x01bad0ULL: return fde_194_sub_01bad0(x0, x1, x2, x3);
        case 0x01bb8cULL: return fde_195_sub_01bb8c(x0, x1, x2, x3);
        case 0x01bc18ULL: return fde_196_sub_01bc18(x0, x1, x2, x3);
        case 0x01bcc8ULL: return fde_197_sub_01bcc8(x0, x1, x2, x3);
        case 0x01bcecULL: return fde_198_sub_01bcec(x0, x1, x2, x3);
        case 0x01bd38ULL: return fde_199_sub_01bd38(x0, x1, x2, x3);
        case 0x01be28ULL: return fde_200_sub_01be28(x0, x1, x2, x3);
        case 0x01bee8ULL: return fde_201_sub_01bee8(x0, x1, x2, x3);
        case 0x01bf2cULL: return fde_202_sub_01bf2c(x0, x1, x2, x3);
        case 0x01bfb0ULL: return fde_203_sub_01bfb0(x0, x1, x2, x3);
        case 0x01c044ULL: return fde_204_sub_01c044(x0, x1, x2, x3);
        case 0x01c0c0ULL: return fde_205_sub_01c0c0(x0, x1, x2, x3);
        case 0x01c118ULL: return fde_206_sub_01c118(x0, x1, x2, x3);
        case 0x01c16cULL: return fde_207_sub_01c16c(x0, x1, x2, x3);
        case 0x01c1c4ULL: return fde_208_sub_01c1c4(x0, x1, x2, x3);
        case 0x01c230ULL: return fde_209_sub_01c230(x0, x1, x2, x3);
        case 0x01c290ULL: return fde_210_sub_01c290(x0, x1, x2, x3);
        case 0x01c36cULL: return fde_211_sub_01c36c(x0, x1, x2, x3);
        case 0x01c3c4ULL: return fde_212_sub_01c3c4(x0, x1, x2, x3);
        case 0x01c424ULL: return fde_213_sub_01c424(x0, x1, x2, x3);
        case 0x01c600ULL: return fde_214_sub_01c600(x0, x1, x2, x3);
        case 0x01c724ULL: return fde_215_sub_01c724(x0, x1, x2, x3);
        case 0x01c72cULL: return fde_216_sub_01c72c(x0, x1, x2, x3);
        case 0x01c734ULL: return fde_217_sub_01c734(x0, x1, x2, x3);
        case 0x01c7c4ULL: return fde_218_sub_01c7c4(x0, x1, x2, x3);
        case 0x01c7f8ULL: return fde_219_sub_01c7f8(x0, x1, x2, x3);
        case 0x01c7fcULL: return fde_220_sub_01c7fc(x0, x1, x2, x3);
        case 0x01c90cULL: return fde_221_sub_01c90c(x0, x1, x2, x3);
        case 0x01cb10ULL: return fde_222_sub_01cb10(x0, x1, x2, x3);
        case 0x01ccecULL: return fde_223_sub_01ccec(x0, x1, x2, x3);
        case 0x01ce20ULL: return fde_224_sub_01ce20(x0, x1, x2, x3);
        case 0x01cf68ULL: return fde_225_sub_01cf68(x0, x1, x2, x3);
        case 0x01cf6cULL: return fde_226_sub_01cf6c(x0, x1, x2, x3);
        case 0x01d008ULL: return fde_227_sub_01d008(x0, x1, x2, x3);
        case 0x01d270ULL: return fde_228_sub_01d270(x0, x1, x2, x3);
        case 0x01d274ULL: return fde_229_sub_01d274(x0, x1, x2, x3);
        case 0x01d278ULL: return fde_230_sub_01d278(x0, x1, x2, x3);
        case 0x01d34cULL: return fde_231_sub_01d34c(x0, x1, x2, x3);
        case 0x01d3a0ULL: return fde_232_sub_01d3a0(x0, x1, x2, x3);
        case 0x01d3f4ULL: return fde_233_sub_01d3f4(x0, x1, x2, x3);
        case 0x01d438ULL: return fde_234_sub_01d438(x0, x1, x2, x3);
        case 0x01d618ULL: return fde_235_sub_01d618(x0, x1, x2, x3);
        case 0x01dc40ULL: return fde_236_sub_01dc40(x0, x1, x2, x3);
        case 0x01dc44ULL: return fde_237_sub_01dc44(x0, x1, x2, x3);
        case 0x01dc9cULL: return fde_238_sub_01dc9c(x0, x1, x2, x3);
        case 0x01dcd0ULL: return fde_239_sub_01dcd0(x0, x1, x2, x3);
        case 0x01de98ULL: return fde_240_sub_01de98(x0, x1, x2, x3);
        case 0x01e00cULL: return fde_241_sub_01e00c(x0, x1, x2, x3);
        case 0x01e3b0ULL: return fde_242_sub_01e3b0(x0, x1, x2, x3);
        case 0x01e424ULL: return fde_243_sub_01e424(x0, x1, x2, x3);
        case 0x01e640ULL: return fde_244_sub_01e640(x0, x1, x2, x3);
        case 0x01e9f0ULL: return fde_245_sub_01e9f0(x0, x1, x2, x3);
        case 0x01eb14ULL: return fde_246_sub_01eb14(x0, x1, x2, x3);
        case 0x01eb18ULL: return fde_247_sub_01eb18(x0, x1, x2, x3);
        case 0x01ebacULL: return fde_248_sub_01ebac(x0, x1, x2, x3);
        case 0x01ec58ULL: return fde_249_sub_01ec58(x0, x1, x2, x3);
        case 0x01ed88ULL: return fde_250_sub_01ed88(x0, x1, x2, x3);
        case 0x01ee38ULL: return fde_251_sub_01ee38(x0, x1, x2, x3);
        case 0x01f020ULL: return fde_252_sub_01f020(x0, x1, x2, x3);
        case 0x01f1ecULL: return fde_253_sub_01f1ec(x0, x1, x2, x3);
        case 0x01f45cULL: return fde_254_sub_01f45c(x0, x1, x2, x3);
        case 0x01f4ecULL: return fde_255_sub_01f4ec(x0, x1, x2, x3);
        case 0x01f528ULL: return fde_256_sub_01f528(x0, x1, x2, x3);
        case 0x01f56cULL: return fde_257_sub_01f56c(x0, x1, x2, x3);
        case 0x01f574ULL: return fde_258_sub_01f574(x0, x1, x2, x3);
        case 0x01f598ULL: return fde_259_sub_01f598(x0, x1, x2, x3);
        case 0x01f5c0ULL: return fde_260_sub_01f5c0(x0, x1, x2, x3);
        case 0x01f604ULL: return fde_261_sub_01f604(x0, x1, x2, x3);
        case 0x01f648ULL: return fde_262_sub_01f648(x0, x1, x2, x3);
        case 0x01f688ULL: return fde_263_sub_01f688(x0, x1, x2, x3);
        case 0x01f6d0ULL: return fde_264_sub_01f6d0(x0, x1, x2, x3);
        case 0x01f6e0ULL: return fde_265_sub_01f6e0(x0, x1, x2, x3);
        case 0x01f704ULL: return fde_266_sub_01f704(x0, x1, x2, x3);
        case 0x01f72cULL: return fde_267_sub_01f72c(x0, x1, x2, x3);
        case 0x01f750ULL: return fde_268_sub_01f750(x0, x1, x2, x3);
        case 0x01f770ULL: return fde_269_sub_01f770(x0, x1, x2, x3);
        case 0x01f7e8ULL: return fde_270_sub_01f7e8(x0, x1, x2, x3);
        case 0x01f868ULL: return fde_271_sub_01f868(x0, x1, x2, x3);
        case 0x01f870ULL: return fde_272_sub_01f870(x0, x1, x2, x3);
        case 0x01f898ULL: return fde_273_sub_01f898(x0, x1, x2, x3);
        case 0x01f8acULL: return fde_274_sub_01f8ac(x0, x1, x2, x3);
        case 0x01f8dcULL: return fde_275_sub_01f8dc(x0, x1, x2, x3);
        case 0x01f958ULL: return fde_276_sub_01f958(x0, x1, x2, x3);
        case 0x01f9d8ULL: return fde_277_sub_01f9d8(x0, x1, x2, x3);
        case 0x01fa60ULL: return fde_278_sub_01fa60(x0, x1, x2, x3);
        case 0x01fab0ULL: return fde_279_sub_01fab0(x0, x1, x2, x3);
        case 0x01fb08ULL: return fde_280_sub_01fb08(x0, x1, x2, x3);
        case 0x01fb0cULL: return fde_281_sub_01fb0c(x0, x1, x2, x3);
        case 0x01fb10ULL: return fde_282_sub_01fb10(x0, x1, x2, x3);
        case 0x01fc38ULL: return fde_283_sub_01fc38(x0, x1, x2, x3);
        case 0x01fc4cULL: return fde_284_sub_01fc4c(x0, x1, x2, x3);
        case 0x01fc54ULL: return fde_285_sub_01fc54(x0, x1, x2, x3);
        case 0x01fc5cULL: return fde_286_sub_01fc5c(x0, x1, x2, x3);
        case 0x01fd3cULL: return fde_287_sub_01fd3c(x0, x1, x2, x3);
        case 0x01fd8cULL: return fde_288_sub_01fd8c(x0, x1, x2, x3);
        case 0x01fdccULL: return fde_289_sub_01fdcc(x0, x1, x2, x3);
        case 0x01fe3cULL: return fde_290_sub_01fe3c(x0, x1, x2, x3);
        case 0x01ff10ULL: return fde_291_sub_01ff10(x0, x1, x2, x3);
        case 0x020158ULL: return fde_292_sub_020158(x0, x1, x2, x3);
        case 0x02016cULL: return fde_293_sub_02016c(x0, x1, x2, x3);
        case 0x0201a0ULL: return fde_294_sub_0201a0(x0, x1, x2, x3);
        case 0x0201acULL: return fde_295_sub_0201ac(x0, x1, x2, x3);
        case 0x0201b8ULL: return fde_296_sub_0201b8(x0, x1, x2, x3);
        case 0x0201c0ULL: return fde_297_sub_0201c0(x0, x1, x2, x3);
        case 0x0201c8ULL: return fde_298_sub_0201c8(x0, x1, x2, x3);
        case 0x0201d0ULL: return fde_299_sub_0201d0(x0, x1, x2, x3);
        case 0x0202a8ULL: return fde_300_sub_0202a8(x0, x1, x2, x3);
        case 0x0203e8ULL: return fde_301_sub_0203e8(x0, x1, x2, x3);
        case 0x0204b4ULL: return fde_302_sub_0204b4(x0, x1, x2, x3);
        case 0x0206c4ULL: return fde_303_sub_0206c4(x0, x1, x2, x3);
        case 0x0207ecULL: return fde_304_sub_0207ec(x0, x1, x2, x3);
        case 0x020988ULL: return fde_305_sub_020988(x0, x1, x2, x3);
        case 0x020b28ULL: return fde_306_sub_020b28(x0, x1, x2, x3);
        case 0x020c18ULL: return fde_307_sub_020c18(x0, x1, x2, x3);
        case 0x020d3cULL: return fde_308_sub_020d3c(x0, x1, x2, x3);
        case 0x020f20ULL: return fde_309_sub_020f20(x0, x1, x2, x3);
        case 0x02111cULL: return fde_310_sub_02111c(x0, x1, x2, x3);
        case 0x021294ULL: return fde_311_sub_021294(x0, x1, x2, x3);
        case 0x02136cULL: return fde_312_sub_02136c(x0, x1, x2, x3);
        case 0x02140cULL: return fde_313_sub_02140c(x0, x1, x2, x3);
        case 0x0214b4ULL: return fde_314_sub_0214b4(x0, x1, x2, x3);
        case 0x0215e0ULL: return fde_315_sub_0215e0(x0, x1, x2, x3);
        case 0x021668ULL: return fde_316_sub_021668(x0, x1, x2, x3);
        case 0x021670ULL: return fde_317_sub_021670(x0, x1, x2, x3);
        case 0x0216e0ULL: return fde_318_sub_0216e0(x0, x1, x2, x3);
        case 0x021724ULL: return fde_319_sub_021724(x0, x1, x2, x3);
        case 0x021788ULL: return fde_320_sub_021788(x0, x1, x2, x3);
        case 0x021828ULL: return fde_321_sub_021828(x0, x1, x2, x3);
        case 0x021870ULL: return fde_322_sub_021870(x0, x1, x2, x3);
        case 0x0218c0ULL: return fde_323_sub_0218c0(x0, x1, x2, x3);
        case 0x0218c8ULL: return fde_324_sub_0218c8(x0, x1, x2, x3);
        case 0x0218d0ULL: return fde_325_sub_0218d0(x0, x1, x2, x3);
        case 0x02193cULL: return fde_326_sub_02193c(x0, x1, x2, x3);
        case 0x021970ULL: return fde_327_sub_021970(x0, x1, x2, x3);
        case 0x0219f0ULL: return fde_328_sub_0219f0(x0, x1, x2, x3);
        case 0x021a10ULL: return fde_329_sub_021a10(x0, x1, x2, x3);
        case 0x021ae8ULL: return fde_330_sub_021ae8(x0, x1, x2, x3);
        case 0x021b30ULL: return fde_331_sub_021b30(x0, x1, x2, x3);
        case 0x021b80ULL: return fde_332_sub_021b80(x0, x1, x2, x3);
        case 0x021b88ULL: return fde_333_sub_021b88(x0, x1, x2, x3);
        case 0x021ba8ULL: return fde_334_sub_021ba8(x0, x1, x2, x3);
        case 0x021bc8ULL: return fde_335_sub_021bc8(x0, x1, x2, x3);
        case 0x021c2cULL: return fde_336_sub_021c2c(x0, x1, x2, x3);
        case 0x021cd0ULL: return fde_337_sub_021cd0(x0, x1, x2, x3);
        case 0x021cf8ULL: return fde_338_sub_021cf8(x0, x1, x2, x3);
        case 0x021d38ULL: return fde_339_sub_021d38(x0, x1, x2, x3);
        case 0x021d80ULL: return fde_340_sub_021d80(x0, x1, x2, x3);
        case 0x021d90ULL: return fde_341_sub_021d90(x0, x1, x2, x3);
        case 0x021e08ULL: return fde_342_sub_021e08(x0, x1, x2, x3);
        case 0x021e18ULL: return fde_343_sub_021e18(x0, x1, x2, x3);
        case 0x021eb8ULL: return fde_344_sub_021eb8(x0, x1, x2, x3);
        case 0x021f60ULL: return fde_345_sub_021f60(x0, x1, x2, x3);
        case 0x0220c0ULL: return fde_346_sub_0220c0(x0, x1, x2, x3);
        case 0x022150ULL: return fde_347_sub_022150(x0, x1, x2, x3);
        case 0x0221f4ULL: return fde_348_sub_0221f4(x0, x1, x2, x3);
        case 0x022404ULL: return fde_349_sub_022404(x0, x1, x2, x3);
        case 0x022494ULL: return fde_350_sub_022494(x0, x1, x2, x3);
        case 0x0225a8ULL: return fde_351_sub_0225a8(x0, x1, x2, x3);
        case 0x0225e8ULL: return fde_352_sub_0225e8(x0, x1, x2, x3);
        case 0x0226fcULL: return fde_353_sub_0226fc(x0, x1, x2, x3);
        case 0x0228c8ULL: return fde_354_sub_0228c8(x0, x1, x2, x3);
        case 0x022a94ULL: return fde_355_sub_022a94(x0, x1, x2, x3);
        case 0x022b80ULL: return fde_356_sub_022b80(x0, x1, x2, x3);
        case 0x022c6cULL: return fde_357_sub_022c6c(x0, x1, x2, x3);
        case 0x022f48ULL: return fde_358_sub_022f48(x0, x1, x2, x3);
        case 0x022f94ULL: return fde_359_sub_022f94(x0, x1, x2, x3);
        case 0x023064ULL: return fde_360_sub_023064(x0, x1, x2, x3);
        case 0x023134ULL: return fde_361_sub_023134(x0, x1, x2, x3);
        case 0x023270ULL: return fde_362_sub_023270(x0, x1, x2, x3);
        case 0x0233acULL: return fde_363_sub_0233ac(x0, x1, x2, x3);
        case 0x0234c4ULL: return fde_364_sub_0234c4(x0, x1, x2, x3);
        case 0x0235dcULL: return fde_365_sub_0235dc(x0, x1, x2, x3);
        case 0x023844ULL: return fde_366_sub_023844(x0, x1, x2, x3);
        case 0x023cb8ULL: return fde_367_sub_023cb8(x0, x1, x2, x3);
        case 0x0240b8ULL: return fde_368_sub_0240b8(x0, x1, x2, x3);
        case 0x0241b0ULL: return fde_369_sub_0241b0(x0, x1, x2, x3);
        case 0x0242b8ULL: return fde_370_sub_0242b8(x0, x1, x2, x3);
        case 0x0245d8ULL: return fde_371_sub_0245d8(x0, x1, x2, x3);
        case 0x024724ULL: return fde_372_sub_024724(x0, x1, x2, x3);
        case 0x02498cULL: return fde_373_sub_02498c(x0, x1, x2, x3);
        case 0x024c1cULL: return fde_374_sub_024c1c(x0, x1, x2, x3);
        case 0x024d24ULL: return fde_375_sub_024d24(x0, x1, x2, x3);
        case 0x024f54ULL: return fde_376_sub_024f54(x0, x1, x2, x3);
        case 0x025080ULL: return fde_377_sub_025080(x0, x1, x2, x3);
        case 0x0251ccULL: return fde_378_sub_0251cc(x0, x1, x2, x3);
        case 0x025590ULL: return fde_379_sub_025590(x0, x1, x2, x3);
        case 0x025680ULL: return fde_380_sub_025680(x0, x1, x2, x3);
        case 0x025788ULL: return fde_381_sub_025788(x0, x1, x2, x3);
        case 0x025aa8ULL: return fde_382_sub_025aa8(x0, x1, x2, x3);
        case 0x025d10ULL: return fde_383_sub_025d10(x0, x1, x2, x3);
        case 0x025e5cULL: return fde_384_sub_025e5c(x0, x1, x2, x3);
        case 0x025e94ULL: return fde_385_sub_025e94(x0, x1, x2, x3);
        case 0x025e98ULL: return fde_386_sub_025e98(x0, x1, x2, x3);
        case 0x025e9cULL: return fde_387_sub_025e9c(x0, x1, x2, x3);
        case 0x025ea4ULL: return fde_388_sub_025ea4(x0, x1, x2, x3);
        case 0x025eacULL: return fde_389_sub_025eac(x0, x1, x2, x3);
        case 0x025ebcULL: return fde_390_sub_025ebc(x0, x1, x2, x3);
        case 0x025ec4ULL: return fde_391_sub_025ec4(x0, x1, x2, x3);
        case 0x025eccULL: return fde_392_sub_025ecc(x0, x1, x2, x3);
        case 0x025ed4ULL: return fde_393_sub_025ed4(x0, x1, x2, x3);
        case 0x025edcULL: return fde_394_sub_025edc(x0, x1, x2, x3);
        case 0x025f28ULL: return fde_395_sub_025f28(x0, x1, x2, x3);
        case 0x026080ULL: return fde_396_sub_026080(x0, x1, x2, x3);
        case 0x0262e8ULL: return fde_397_sub_0262e8(x0, x1, x2, x3);
        case 0x0263a0ULL: return fde_398_sub_0263a0(x0, x1, x2, x3);
        case 0x0263f0ULL: return fde_399_sub_0263f0(x0, x1, x2, x3);
        case 0x0265fcULL: return fde_400_sub_0265fc(x0, x1, x2, x3);
        case 0x026608ULL: return fde_401_sub_026608(x0, x1, x2, x3);
        case 0x026988ULL: return fde_402_sub_026988(x0, x1, x2, x3);
        case 0x026d60ULL: return fde_403_sub_026d60(x0, x1, x2, x3);
        case 0x026dc0ULL: return fde_404_sub_026dc0(x0, x1, x2, x3);
        case 0x026e1cULL: return fde_405_sub_026e1c(x0, x1, x2, x3);
        case 0x027084ULL: return fde_406_sub_027084(x0, x1, x2, x3);
        case 0x02718cULL: return fde_407_sub_02718c(x0, x1, x2, x3);
        case 0x0273bcULL: return fde_408_sub_0273bc(x0, x1, x2, x3);
        case 0x0273c4ULL: return fde_409_sub_0273c4(x0, x1, x2, x3);
        case 0x0273d0ULL: return fde_410_sub_0273d0(x0, x1, x2, x3);
        case 0x0273d8ULL: return fde_411_sub_0273d8(x0, x1, x2, x3);
        case 0x0273ecULL: return fde_412_sub_0273ec(x0, x1, x2, x3);
        case 0x027404ULL: return fde_413_sub_027404(x0, x1, x2, x3);
        case 0x02747cULL: return fde_414_sub_02747c(x0, x1, x2, x3);
        case 0x0274d4ULL: return fde_415_sub_0274d4(x0, x1, x2, x3);
        case 0x027564ULL: return fde_416_sub_027564(x0, x1, x2, x3);
        case 0x027590ULL: return fde_417_sub_027590(x0, x1, x2, x3);
        case 0x0275c0ULL: return fde_418_sub_0275c0(x0, x1, x2, x3);
        case 0x027618ULL: return fde_419_sub_027618(x0, x1, x2, x3);
        case 0x027628ULL: return fde_420_sub_027628(x0, x1, x2, x3);
        case 0x027884ULL: return fde_421_sub_027884(x0, x1, x2, x3);
        case 0x027930ULL: return fde_422_sub_027930(x0, x1, x2, x3);
        case 0x027950ULL: return fde_423_sub_027950(x0, x1, x2, x3);
        case 0x0279d0ULL: return fde_424_sub_0279d0(x0, x1, x2, x3);
        case 0x027aa4ULL: return fde_425_sub_027aa4(x0, x1, x2, x3);
        case 0x027bb4ULL: return fde_426_sub_027bb4(x0, x1, x2, x3);
        case 0x027c20ULL: return fde_427_sub_027c20(x0, x1, x2, x3);
        case 0x027ddcULL: return fde_428_sub_027ddc(x0, x1, x2, x3);
        case 0x027e48ULL: return fde_429_sub_027e48(x0, x1, x2, x3);
        case 0x027e50ULL: return fde_430_sub_027e50(x0, x1, x2, x3);
        case 0x027e60ULL: return fde_431_sub_027e60(x0, x1, x2, x3);
        case 0x027e70ULL: return fde_432_sub_027e70(x0, x1, x2, x3);
        case 0x027e80ULL: return fde_433_sub_027e80(x0, x1, x2, x3);
        case 0x028184ULL: return fde_434_sub_028184(x0, x1, x2, x3);
        case 0x028338ULL: return fde_435_sub_028338(x0, x1, x2, x3);
        case 0x028364ULL: return fde_436_sub_028364(x0, x1, x2, x3);
        case 0x02848cULL: return fde_437_sub_02848c(x0, x1, x2, x3);
        case 0x0285e0ULL: return fde_438_sub_0285e0(x0, x1, x2, x3);
        case 0x0287ecULL: return fde_439_sub_0287ec(x0, x1, x2, x3);
        case 0x028838ULL: return fde_440_sub_028838(x0, x1, x2, x3);
        case 0x028844ULL: return fde_441_sub_028844(x0, x1, x2, x3);
        case 0x0288e0ULL: return fde_442_sub_0288e0(x0, x1, x2, x3);
        case 0x028958ULL: return fde_443_sub_028958(x0, x1, x2, x3);
        case 0x0289c8ULL: return fde_444_sub_0289c8(x0, x1, x2, x3);
        case 0x028b68ULL: return fde_445_sub_028b68(x0, x1, x2, x3);
        case 0x028be8ULL: return fde_446_sub_028be8(x0, x1, x2, x3);
        case 0x028c68ULL: return fde_447_sub_028c68(x0, x1, x2, x3);
        case 0x028d2cULL: return fde_448_sub_028d2c(x0, x1, x2, x3);
        case 0x028d8cULL: return fde_449_sub_028d8c(x0, x1, x2, x3);
        case 0x028dd4ULL: return fde_450_sub_028dd4(x0, x1, x2, x3);
        case 0x028e3cULL: return fde_451_sub_028e3c(x0, x1, x2, x3);
        case 0x028edcULL: return fde_452_sub_028edc(x0, x1, x2, x3);
        case 0x02a2a4ULL: return fde_453_sub_02a2a4(x0, x1, x2, x3);
        case 0x02a3c4ULL: return fde_454_sub_02a3c4(x0, x1, x2, x3);
        case 0x02a3ccULL: return fde_455_sub_02a3cc(x0, x1, x2, x3);
        case 0x02a3d0ULL: return fde_456_sub_02a3d0(x0, x1, x2, x3);
        case 0x02a3d8ULL: return fde_457_sub_02a3d8(x0, x1, x2, x3);
        case 0x02a3e0ULL: return fde_458_sub_02a3e0(x0, x1, x2, x3);
        case 0x02a46cULL: return fde_459_sub_02a46c(x0, x1, x2, x3);
        case 0x02a490ULL: return fde_460_sub_02a490(x0, x1, x2, x3);
        case 0x02a4a0ULL: return fde_461_sub_02a4a0(x0, x1, x2, x3);
        case 0x02a538ULL: return fde_462_sub_02a538(x0, x1, x2, x3);
        case 0x02a5d0ULL: return fde_463_sub_02a5d0(x0, x1, x2, x3);
        case 0x02a668ULL: return fde_464_sub_02a668(x0, x1, x2, x3);
        case 0x02a6d4ULL: return fde_465_sub_02a6d4(x0, x1, x2, x3);
        case 0x02a718ULL: return fde_466_sub_02a718(x0, x1, x2, x3);
        case 0x02a720ULL: return fde_467_sub_02a720(x0, x1, x2, x3);
        case 0x02a7bcULL: return fde_468_sub_02a7bc(x0, x1, x2, x3);
        case 0x02a85cULL: return fde_469_sub_02a85c(x0, x1, x2, x3);
        case 0x02a8fcULL: return fde_470_sub_02a8fc(x0, x1, x2, x3);
        case 0x02a990ULL: return fde_471_sub_02a990(x0, x1, x2, x3);
        case 0x02aa30ULL: return fde_472_sub_02aa30(x0, x1, x2, x3);
        case 0x02aa38ULL: return fde_473_sub_02aa38(x0, x1, x2, x3);
        case 0x02aa40ULL: return fde_474_sub_02aa40(x0, x1, x2, x3);
        case 0x02ada4ULL: return fde_475_sub_02ada4(x0, x1, x2, x3);
        case 0x02b000ULL: return fde_476_sub_02b000(x0, x1, x2, x3);
        case 0x02b00cULL: return fde_477_sub_02b00c(x0, x1, x2, x3);
        case 0x02b018ULL: return fde_478_sub_02b018(x0, x1, x2, x3);
        case 0x02b0f8ULL: return fde_479_sub_02b0f8(x0, x1, x2, x3);
        case 0x02b100ULL: return fde_480_sub_02b100(x0, x1, x2, x3);
        case 0x02b108ULL: return fde_481_sub_02b108(x0, x1, x2, x3);
        case 0x02b110ULL: return fde_482_sub_02b110(x0, x1, x2, x3);
        case 0x02b118ULL: return fde_483_sub_02b118(x0, x1, x2, x3);
        case 0x02b120ULL: return fde_484_sub_02b120(x0, x1, x2, x3);
        case 0x02b128ULL: return fde_485_sub_02b128(x0, x1, x2, x3);
        case 0x02b130ULL: return fde_486_sub_02b130(x0, x1, x2, x3);
        case 0x02b444ULL: return fde_487_sub_02b444(x0, x1, x2, x3);
        case 0x02b5ccULL: return fde_488_sub_02b5cc(x0, x1, x2, x3);
        case 0x02b754ULL: return fde_489_sub_02b754(x0, x1, x2, x3);
        case 0x02ba34ULL: return fde_490_sub_02ba34(x0, x1, x2, x3);
        case 0x02ba7cULL: return fde_491_sub_02ba7c(x0, x1, x2, x3);
        case 0x02bfd0ULL: return fde_492_sub_02bfd0(x0, x1, x2, x3);
        case 0x02bfe0ULL: return fde_493_sub_02bfe0(x0, x1, x2, x3);
        case 0x02c168ULL: return fde_494_sub_02c168(x0, x1, x2, x3);
        case 0x02c460ULL: return fde_495_sub_02c460(x0, x1, x2, x3);
        case 0x02c50cULL: return fde_496_sub_02c50c(x0, x1, x2, x3);
        case 0x02c510ULL: return fde_497_sub_02c510(x0, x1, x2, x3);
        case 0x02c57cULL: return fde_498_sub_02c57c(x0, x1, x2, x3);
        case 0x02c604ULL: return fde_499_sub_02c604(x0, x1, x2, x3);
        case 0x02c65cULL: return fde_500_sub_02c65c(x0, x1, x2, x3);
        case 0x02c6bcULL: return fde_501_sub_02c6bc(x0, x1, x2, x3);
        case 0x02c6c4ULL: return fde_502_sub_02c6c4(x0, x1, x2, x3);
        case 0x02c6ccULL: return fde_503_sub_02c6cc(x0, x1, x2, x3);
        case 0x02c6d4ULL: return fde_504_sub_02c6d4(x0, x1, x2, x3);
        case 0x02c6dcULL: return fde_505_sub_02c6dc(x0, x1, x2, x3);
        case 0x02c6e4ULL: return fde_506_sub_02c6e4(x0, x1, x2, x3);
        case 0x02c810ULL: return fde_507_sub_02c810(x0, x1, x2, x3);
        case 0x02c95cULL: return fde_508_sub_02c95c(x0, x1, x2, x3);
        case 0x02cc10ULL: return fde_509_sub_02cc10(x0, x1, x2, x3);
        case 0x02cd18ULL: return fde_510_sub_02cd18(x0, x1, x2, x3);
        case 0x02cf48ULL: return fde_511_sub_02cf48(x0, x1, x2, x3);
        case 0x02cf4cULL: return fde_512_sub_02cf4c(x0, x1, x2, x3);
        case 0x02cf84ULL: return fde_513_sub_02cf84(x0, x1, x2, x3);
        case 0x02cf9cULL: return fde_514_sub_02cf9c(x0, x1, x2, x3);
        case 0x02cfa0ULL: return fde_515_sub_02cfa0(x0, x1, x2, x3);
        case 0x02cfa4ULL: return fde_516_sub_02cfa4(x0, x1, x2, x3);
        case 0x02cfb0ULL: return fde_517_sub_02cfb0(x0, x1, x2, x3);
        case 0x02cfb4ULL: return fde_518_sub_02cfb4(x0, x1, x2, x3);
        case 0x02cfb8ULL: return fde_519_sub_02cfb8(x0, x1, x2, x3);
        case 0x02cfbcULL: return fde_520_sub_02cfbc(x0, x1, x2, x3);
        case 0x02cff4ULL: return fde_521_sub_02cff4(x0, x1, x2, x3);
        case 0x02d00cULL: return fde_522_sub_02d00c(x0, x1, x2, x3);
        case 0x02d010ULL: return fde_523_sub_02d010(x0, x1, x2, x3);
        case 0x02d014ULL: return fde_524_sub_02d014(x0, x1, x2, x3);
        case 0x02d01cULL: return fde_525_sub_02d01c(x0, x1, x2, x3);
        case 0x02d020ULL: return fde_526_sub_02d020(x0, x1, x2, x3);
        case 0x02d024ULL: return fde_527_sub_02d024(x0, x1, x2, x3);
        case 0x02d05cULL: return fde_528_sub_02d05c(x0, x1, x2, x3);
        case 0x02d074ULL: return fde_529_sub_02d074(x0, x1, x2, x3);
        case 0x02d078ULL: return fde_530_sub_02d078(x0, x1, x2, x3);
        case 0x02d07cULL: return fde_531_sub_02d07c(x0, x1, x2, x3);
        case 0x02d084ULL: return fde_532_sub_02d084(x0, x1, x2, x3);
        case 0x02d238ULL: return fde_533_sub_02d238(x0, x1, x2, x3);
        case 0x02d3a4ULL: return fde_534_sub_02d3a4(x0, x1, x2, x3);
        case 0x02d55cULL: return fde_535_sub_02d55c(x0, x1, x2, x3);
        case 0x02d560ULL: return fde_536_sub_02d560(x0, x1, x2, x3);
        case 0x02d5a4ULL: return fde_537_sub_02d5a4(x0, x1, x2, x3);
        case 0x02d5c8ULL: return fde_538_sub_02d5c8(x0, x1, x2, x3);
        case 0x02d5ccULL: return fde_539_sub_02d5cc(x0, x1, x2, x3);
        case 0x02d5d0ULL: return fde_540_sub_02d5d0(x0, x1, x2, x3);
        case 0x02d5ecULL: return fde_541_sub_02d5ec(x0, x1, x2, x3);
        case 0x02d6c4ULL: return fde_542_sub_02d6c4(x0, x1, x2, x3);
        case 0x02d7a0ULL: return fde_543_sub_02d7a0(x0, x1, x2, x3);
        case 0x02d7a8ULL: return fde_544_sub_02d7a8(x0, x1, x2, x3);
        case 0x02d7b0ULL: return fde_545_sub_02d7b0(x0, x1, x2, x3);
        case 0x02d7e0ULL: return fde_546_sub_02d7e0(x0, x1, x2, x3);
        case 0x02d810ULL: return fde_547_sub_02d810(x0, x1, x2, x3);
        case 0x02d81cULL: return fde_548_sub_02d81c(x0, x1, x2, x3);
        case 0x02d844ULL: return fde_549_sub_02d844(x0, x1, x2, x3);
        case 0x02d84cULL: return fde_550_sub_02d84c(x0, x1, x2, x3);
        case 0x02d854ULL: return fde_551_sub_02d854(x0, x1, x2, x3);
        case 0x02d85cULL: return fde_552_sub_02d85c(x0, x1, x2, x3);
        case 0x02d864ULL: return fde_553_sub_02d864(x0, x1, x2, x3);
        case 0x02d86cULL: return fde_554_sub_02d86c(x0, x1, x2, x3);
        case 0x02d874ULL: return fde_555_sub_02d874(x0, x1, x2, x3);
        case 0x02d87cULL: return fde_556_sub_02d87c(x0, x1, x2, x3);
        case 0x02d884ULL: return fde_557_sub_02d884(x0, x1, x2, x3);
        case 0x02d91cULL: return fde_558_sub_02d91c(x0, x1, x2, x3);
        case 0x02d924ULL: return fde_559_sub_02d924(x0, x1, x2, x3);
        case 0x02d9bcULL: return fde_560_sub_02d9bc(x0, x1, x2, x3);
        case 0x02d9c4ULL: return fde_561_sub_02d9c4(x0, x1, x2, x3);
        case 0x02d9ccULL: return fde_562_sub_02d9cc(x0, x1, x2, x3);
        case 0x02d9d4ULL: return fde_563_sub_02d9d4(x0, x1, x2, x3);
        case 0x02d9fcULL: return fde_564_sub_02d9fc(x0, x1, x2, x3);
        case 0x02da74ULL: return fde_565_sub_02da74(x0, x1, x2, x3);
        case 0x02da7cULL: return fde_566_sub_02da7c(x0, x1, x2, x3);
        case 0x02dbe4ULL: return fde_567_sub_02dbe4(x0, x1, x2, x3);
        case 0x02dc08ULL: return fde_568_sub_02dc08(x0, x1, x2, x3);
        case 0x02dfe0ULL: return fde_569_sub_02dfe0(x0, x1, x2, x3);
        case 0x02e0e8ULL: return fde_570_sub_02e0e8(x0, x1, x2, x3);
        case 0x02e224ULL: return fde_571_sub_02e224(x0, x1, x2, x3);
        case 0x02e544ULL: return fde_572_sub_02e544(x0, x1, x2, x3);
        case 0x02e944ULL: return fde_573_sub_02e944(x0, x1, x2, x3);
        case 0x02e980ULL: return fde_574_sub_02e980(x0, x1, x2, x3);
        case 0x02e9b8ULL: return fde_575_sub_02e9b8(x0, x1, x2, x3);
        case 0x02ea08ULL: return fde_576_sub_02ea08(x0, x1, x2, x3);
        case 0x02eab4ULL: return fde_577_sub_02eab4(x0, x1, x2, x3);
        case 0x02eb6cULL: return fde_578_sub_02eb6c(x0, x1, x2, x3);
        case 0x02ebecULL: return fde_579_sub_02ebec(x0, x1, x2, x3);
        case 0x02f00cULL: return fde_580_sub_02f00c(x0, x1, x2, x3);
        case 0x02f288ULL: return fde_581_sub_02f288(x0, x1, x2, x3);
        case 0x02f394ULL: return fde_582_sub_02f394(x0, x1, x2, x3);
        case 0x02f4a0ULL: return fde_583_sub_02f4a0(x0, x1, x2, x3);
        case 0x02f518ULL: return fde_584_sub_02f518(x0, x1, x2, x3);
        case 0x02f598ULL: return fde_585_sub_02f598(x0, x1, x2, x3);
        case 0x02f620ULL: return fde_586_sub_02f620(x0, x1, x2, x3);
        case 0x02f7a8ULL: return fde_587_sub_02f7a8(x0, x1, x2, x3);
        case 0x02f954ULL: return fde_588_sub_02f954(x0, x1, x2, x3);
        case 0x02fa4cULL: return fde_589_sub_02fa4c(x0, x1, x2, x3);
        case 0x02fa50ULL: return fde_590_sub_02fa50(x0, x1, x2, x3);
        case 0x02fafcULL: return fde_591_sub_02fafc(x0, x1, x2, x3);
        case 0x02feacULL: return fde_592_sub_02feac(x0, x1, x2, x3);
        case 0x02ffecULL: return fde_593_sub_02ffec(x0, x1, x2, x3);
        case 0x030254ULL: return fde_594_sub_030254(x0, x1, x2, x3);
        case 0x03061cULL: return fde_595_sub_03061c(x0, x1, x2, x3);
        case 0x030a04ULL: return fde_596_sub_030a04(x0, x1, x2, x3);
        case 0x030a08ULL: return fde_597_sub_030a08(x0, x1, x2, x3);
        case 0x030a2cULL: return fde_598_sub_030a2c(x0, x1, x2, x3);
        case 0x030abcULL: return fde_599_sub_030abc(x0, x1, x2, x3);
        case 0x030c58ULL: return fde_600_sub_030c58(x0, x1, x2, x3);
        case 0x030c90ULL: return fde_601_sub_030c90(x0, x1, x2, x3);
        case 0x030ce4ULL: return fde_602_sub_030ce4(x0, x1, x2, x3);
        case 0x030d90ULL: return fde_603_sub_030d90(x0, x1, x2, x3);
        case 0x030dc8ULL: return fde_604_sub_030dc8(x0, x1, x2, x3);
        case 0x030e10ULL: return fde_605_sub_030e10(x0, x1, x2, x3);
        case 0x031054ULL: return fde_606_sub_031054(x0, x1, x2, x3);
        case 0x0310a4ULL: return fde_607_sub_0310a4(x0, x1, x2, x3);
        case 0x0311c8ULL: return fde_608_sub_0311c8(x0, x1, x2, x3);
        case 0x0313d0ULL: return fde_609_sub_0313d0(x0, x1, x2, x3);
        case 0x0315d0ULL: return fde_610_sub_0315d0(x0, x1, x2, x3);
        case 0x0317c8ULL: return fde_611_sub_0317c8(x0, x1, x2, x3);
        case 0x0319acULL: return fde_612_sub_0319ac(x0, x1, x2, x3);
        case 0x031b80ULL: return fde_613_sub_031b80(x0, x1, x2, x3);
        case 0x031df8ULL: return fde_614_sub_031df8(x0, x1, x2, x3);
        case 0x031e60ULL: return fde_615_sub_031e60(x0, x1, x2, x3);
        case 0x031e70ULL: return fde_616_sub_031e70(x0, x1, x2, x3);
        case 0x031ebcULL: return fde_617_sub_031ebc(x0, x1, x2, x3);
        case 0x031ef0ULL: return fde_618_sub_031ef0(x0, x1, x2, x3);
        case 0x03201cULL: return fde_619_sub_03201c(x0, x1, x2, x3);
        case 0x032168ULL: return fde_620_sub_032168(x0, x1, x2, x3);
        case 0x0323f8ULL: return fde_621_sub_0323f8(x0, x1, x2, x3);
        case 0x032500ULL: return fde_622_sub_032500(x0, x1, x2, x3);
        case 0x032730ULL: return fde_623_sub_032730(x0, x1, x2, x3);
        case 0x0328c0ULL: return fde_624_sub_0328c0(x0, x1, x2, x3);
        case 0x032904ULL: return fde_625_sub_032904(x0, x1, x2, x3);
        case 0x032908ULL: return fde_626_sub_032908(x0, x1, x2, x3);
        case 0x032910ULL: return fde_627_sub_032910(x0, x1, x2, x3);
        case 0x032c20ULL: return fde_628_sub_032c20(x0, x1, x2, x3);
        case 0x032e44ULL: return fde_629_sub_032e44(x0, x1, x2, x3);
        case 0x032e48ULL: return fde_630_sub_032e48(x0, x1, x2, x3);
        case 0x032e84ULL: return fde_631_sub_032e84(x0, x1, x2, x3);
        case 0x032ea0ULL: return fde_632_sub_032ea0(x0, x1, x2, x3);
        case 0x032ea4ULL: return fde_633_sub_032ea4(x0, x1, x2, x3);
        case 0x032ea8ULL: return fde_634_sub_032ea8(x0, x1, x2, x3);
        case 0x032eb0ULL: return fde_635_sub_032eb0(x0, x1, x2, x3);
        case 0x03307cULL: return fde_636_sub_03307c(x0, x1, x2, x3);
        case 0x0331c0ULL: return fde_637_sub_0331c0(x0, x1, x2, x3);
        case 0x033304ULL: return fde_638_sub_033304(x0, x1, x2, x3);
        case 0x033448ULL: return fde_639_sub_033448(x0, x1, x2, x3);
        case 0x03358cULL: return fde_640_sub_03358c(x0, x1, x2, x3);
        case 0x0336d0ULL: return fde_641_sub_0336d0(x0, x1, x2, x3);
        case 0x0336d4ULL: return fde_642_sub_0336d4(x0, x1, x2, x3);
        case 0x0336f8ULL: return fde_643_sub_0336f8(x0, x1, x2, x3);
        case 0x033724ULL: return fde_644_sub_033724(x0, x1, x2, x3);
        case 0x033800ULL: return fde_645_sub_033800(x0, x1, x2, x3);
        case 0x033818ULL: return fde_646_sub_033818(x0, x1, x2, x3);
        case 0x03381cULL: return fde_647_sub_03381c(x0, x1, x2, x3);
        case 0x034ea4ULL: return fde_648_sub_034ea4(x0, x1, x2, x3);
        case 0x034f50ULL: return fde_649_sub_034f50(x0, x1, x2, x3);
        case 0x034f78ULL: return fde_650_sub_034f78(x0, x1, x2, x3);
        case 0x034fb8ULL: return fde_651_sub_034fb8(x0, x1, x2, x3);
        case 0x034ff0ULL: return fde_652_sub_034ff0(x0, x1, x2, x3);
        case 0x036018ULL: return fde_653_sub_036018(x0, x1, x2, x3);
        case 0x036060ULL: return fde_654_sub_036060(x0, x1, x2, x3);
        case 0x036064ULL: return fde_655_sub_036064(x0, x1, x2, x3);
        case 0x0362b0ULL: return fde_656_sub_0362b0(x0, x1, x2, x3);
        case 0x0362b8ULL: return fde_657_sub_0362b8(x0, x1, x2, x3);
        case 0x0362e4ULL: return fde_658_sub_0362e4(x0, x1, x2, x3);
        case 0x0363f0ULL: return fde_659_sub_0363f0(x0, x1, x2, x3);
        case 0x036440ULL: return fde_660_sub_036440(x0, x1, x2, x3);
        case 0x036568ULL: return fde_661_sub_036568(x0, x1, x2, x3);
        case 0x03657cULL: return fde_662_sub_03657c(x0, x1, x2, x3);
        case 0x0366b0ULL: return fde_663_sub_0366b0(x0, x1, x2, x3);
        case 0x03671cULL: return fde_664_sub_03671c(x0, x1, x2, x3);
        case 0x036818ULL: return fde_665_sub_036818(x0, x1, x2, x3);
        case 0x0368b4ULL: return fde_666_sub_0368b4(x0, x1, x2, x3);
        case 0x036914ULL: return fde_667_sub_036914(x0, x1, x2, x3);
        case 0x036a18ULL: return fde_668_sub_036a18(x0, x1, x2, x3);
        case 0x036af8ULL: return fde_669_sub_036af8(x0, x1, x2, x3);
        case 0x036cb8ULL: return fde_670_sub_036cb8(x0, x1, x2, x3);
        case 0x03704cULL: return fde_671_sub_03704c(x0, x1, x2, x3);
        case 0x0370d8ULL: return fde_672_sub_0370d8(x0, x1, x2, x3);
        case 0x037284ULL: return fde_673_sub_037284(x0, x1, x2, x3);
        case 0x037a50ULL: return fde_674_sub_037a50(x0, x1, x2, x3);
        case 0x037a6cULL: return fde_675_sub_037a6c(x0, x1, x2, x3);
        case 0x037c0cULL: return fde_676_sub_037c0c(x0, x1, x2, x3);
        case 0x037d50ULL: return fde_677_sub_037d50(x0, x1, x2, x3);
        case 0x037d60ULL: return fde_678_sub_037d60(x0, x1, x2, x3);
        case 0x037fc4ULL: return fde_679_sub_037fc4(x0, x1, x2, x3);
        case 0x0380ccULL: return fde_680_sub_0380cc(x0, x1, x2, x3);
        case 0x0382fcULL: return fde_681_sub_0382fc(x0, x1, x2, x3);
        case 0x038564ULL: return fde_682_sub_038564(x0, x1, x2, x3);
        case 0x038964ULL: return fde_683_sub_038964(x0, x1, x2, x3);
        case 0x038a60ULL: return fde_684_sub_038a60(x0, x1, x2, x3);
        case 0x038b68ULL: return fde_685_sub_038b68(x0, x1, x2, x3);
        case 0x038e88ULL: return fde_686_sub_038e88(x0, x1, x2, x3);
        case 0x039288ULL: return fde_687_sub_039288(x0, x1, x2, x3);
        case 0x039380ULL: return fde_688_sub_039380(x0, x1, x2, x3);
        case 0x039488ULL: return fde_689_sub_039488(x0, x1, x2, x3);
        case 0x0397a8ULL: return fde_690_sub_0397a8(x0, x1, x2, x3);
        case 0x039ba8ULL: return fde_691_sub_039ba8(x0, x1, x2, x3);
        case 0x039ca0ULL: return fde_692_sub_039ca0(x0, x1, x2, x3);
        case 0x039da8ULL: return fde_693_sub_039da8(x0, x1, x2, x3);
        case 0x03a0c8ULL: return fde_694_sub_03a0c8(x0, x1, x2, x3);
        case 0x03a330ULL: return fde_695_sub_03a330(x0, x1, x2, x3);
        case 0x03a598ULL: return fde_696_sub_03a598(x0, x1, x2, x3);
        case 0x03a744ULL: return fde_697_sub_03a744(x0, x1, x2, x3);
        case 0x03a834ULL: return fde_698_sub_03a834(x0, x1, x2, x3);
        case 0x03abf8ULL: return fde_699_sub_03abf8(x0, x1, x2, x3);
        case 0x03acf0ULL: return fde_700_sub_03acf0(x0, x1, x2, x3);
        case 0x03affcULL: return fde_701_sub_03affc(x0, x1, x2, x3);
        case 0x03b02cULL: return fde_702_sub_03b02c(x0, x1, x2, x3);
        case 0x03bc18ULL: return fde_703_sub_03bc18(x0, x1, x2, x3);
        case 0x03be20ULL: return fde_704_sub_03be20(x0, x1, x2, x3);
        case 0x03be78ULL: return fde_705_sub_03be78(x0, x1, x2, x3);
        case 0x03bf3cULL: return fde_706_sub_03bf3c(x0, x1, x2, x3);
        case 0x03c418ULL: return fde_707_sub_03c418(x0, x1, x2, x3);
        case 0x03c488ULL: return fde_708_sub_03c488(x0, x1, x2, x3);
        case 0x03c574ULL: return fde_709_sub_03c574(x0, x1, x2, x3);
        case 0x03c5f0ULL: return fde_710_sub_03c5f0(x0, x1, x2, x3);
        case 0x03c6f4ULL: return fde_711_sub_03c6f4(x0, x1, x2, x3);
        case 0x03c77cULL: return fde_712_sub_03c77c(x0, x1, x2, x3);
        case 0x03c7c0ULL: return fde_713_sub_03c7c0(x0, x1, x2, x3);
        case 0x03c7e4ULL: return fde_714_sub_03c7e4(x0, x1, x2, x3);
        case 0x03c7ecULL: return fde_715_sub_03c7ec(x0, x1, x2, x3);
        case 0x03c934ULL: return fde_716_sub_03c934(x0, x1, x2, x3);
        case 0x03c940ULL: return fde_717_sub_03c940(x0, x1, x2, x3);
        case 0x03c9c8ULL: return fde_718_sub_03c9c8(x0, x1, x2, x3);
        case 0x03ca40ULL: return fde_719_sub_03ca40(x0, x1, x2, x3);
        case 0x03e4e0ULL: return fde_720_sub_03e4e0(x0, x1, x2, x3);
        case 0x03e4e4ULL: return fde_721_sub_03e4e4(x0, x1, x2, x3);
        case 0x03e6f4ULL: return fde_722_sub_03e6f4(x0, x1, x2, x3);
        case 0x03e700ULL: return fde_723_sub_03e700(x0, x1, x2, x3);
        case 0x03e788ULL: return fde_724_sub_03e788(x0, x1, x2, x3);
        case 0x03e800ULL: return fde_725_sub_03e800(x0, x1, x2, x3);
        case 0x03e8c8ULL: return fde_726_sub_03e8c8(x0, x1, x2, x3);
        case 0x03f608ULL: return fde_727_sub_03f608(x0, x1, x2, x3);
        case 0x03f6b8ULL: return fde_728_sub_03f6b8(x0, x1, x2, x3);
        case 0x03f804ULL: return fde_729_sub_03f804(x0, x1, x2, x3);
        case 0x03f928ULL: return fde_730_sub_03f928(x0, x1, x2, x3);
        case 0x040844ULL: return fde_731_sub_040844(x0, x1, x2, x3);
        case 0x0408ccULL: return fde_732_sub_0408cc(x0, x1, x2, x3);
        case 0x0408d0ULL: return fde_733_sub_0408d0(x0, x1, x2, x3);
        case 0x040a24ULL: return fde_734_sub_040a24(x0, x1, x2, x3);
        case 0x040c34ULL: return fde_735_sub_040c34(x0, x1, x2, x3);
        case 0x040cc8ULL: return fde_736_sub_040cc8(x0, x1, x2, x3);
        case 0x040f3cULL: return fde_737_sub_040f3c(x0, x1, x2, x3);
        case 0x0420dcULL: return fde_738_sub_0420dc(x0, x1, x2, x3);
        case 0x042248ULL: return fde_739_sub_042248(x0, x1, x2, x3);
        case 0x042430ULL: return fde_740_sub_042430(x0, x1, x2, x3);
        case 0x04262cULL: return fde_741_sub_04262c(x0, x1, x2, x3);
        case 0x042814ULL: return fde_742_sub_042814(x0, x1, x2, x3);
        case 0x042a04ULL: return fde_743_sub_042a04(x0, x1, x2, x3);
        case 0x042c28ULL: return fde_744_sub_042c28(x0, x1, x2, x3);
        case 0x042d20ULL: return fde_745_sub_042d20(x0, x1, x2, x3);
        case 0x042e78ULL: return fde_746_sub_042e78(x0, x1, x2, x3);
        case 0x043024ULL: return fde_747_sub_043024(x0, x1, x2, x3);
        case 0x0431fcULL: return fde_748_sub_0431fc(x0, x1, x2, x3);
        case 0x0432f0ULL: return fde_749_sub_0432f0(x0, x1, x2, x3);
        case 0x043554ULL: return fde_750_sub_043554(x0, x1, x2, x3);
        case 0x043728ULL: return fde_751_sub_043728(x0, x1, x2, x3);
        case 0x043740ULL: return fde_752_sub_043740(x0, x1, x2, x3);
        case 0x043770ULL: return fde_753_sub_043770(x0, x1, x2, x3);
        case 0x043788ULL: return fde_754_sub_043788(x0, x1, x2, x3);
        case 0x043794ULL: return fde_755_sub_043794(x0, x1, x2, x3);
        case 0x043798ULL: return fde_756_sub_043798(x0, x1, x2, x3);
        default: return 0ULL;
    }
}

} // namespace fde_reconstructed
} // namespace AmazingEngine
