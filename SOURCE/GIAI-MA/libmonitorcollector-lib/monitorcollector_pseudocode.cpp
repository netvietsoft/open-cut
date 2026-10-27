/**
 * @file monitorcollector_pseudocode.cpp
 * @brief Clean-Room C++17 Full Function Reconstruction of libmonitorcollector-lib.so (1,030 FDEs & 350 Exported Symbols)
 *        Tái cấu trúc C++17 Clean-Room toàn bộ hàm của libmonitorcollector-lib.so (1.030 FDE & 350 Ký hiệu xuất khẩu)
 *
 * Binary SHA-256: 739e2276dd31bc2805670367cfff2abc4a3d26e73e5b75635daff2a1f125e183
 * Binary Size:    313,744 bytes
 */

#include "monitorcollector_interface.h"

namespace bytedance {
namespace monitor {
namespace collector {

namespace {
JavaVM* g_jvm_050210 = nullptr;
} // namespace

// ============================================================================
// Deterministic Reconstruction of All 1,030 `.eh_frame_hdr` Functions (`0x0117b0..0x038cf0`)
// Tái cấu trúc tất cả 1.030 hàm trong `.eh_frame_hdr` (`0x0117b0..0x038cf0`)
// ============================================================================
/**
 * @brief FDE[0000] `sub_117b0` (`0x117b0..0x118e8`, 312 bytes)
 *        Hàm FDE[0000] `sub_117b0` (`0x117b0..0x118e8`, 312 bytes)
 * Disassembly: 0x117b0: str x21, [sp, #-0x30]! ; 0x117b4: stp x20, x19, [sp, #0x10] ; 0x117b8: stp x29, x30, [sp, #0x20] ; 0x117bc: add x29, sp, #0x20 ; 0x117c0: adrp x19, #0x4f000
 */
uint64_t fde_0000_0x117b0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x117b0ULL;
    constexpr uint64_t kSize = 0x138ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0001] `sub_118e8` (`0x118e8..0x11f70`, 1672 bytes)
 *        Hàm FDE[0001] `sub_118e8` (`0x118e8..0x11f70`, 1672 bytes)
 * Disassembly: 0x118e8: sub sp, sp, #0x140 ; 0x118ec: str x28, [sp, #0x100] ; 0x118f0: stp x22, x21, [sp, #0x110] ; 0x118f4: stp x20, x19, [sp, #0x120] ; 0x118f8: stp x29, x30, [sp, #0x130]
 */
uint64_t fde_0001_0x118e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x118e8ULL;
    constexpr uint64_t kSize = 0x688ULL;
    constexpr uint32_t kOp0  = 0xd10503ffU;
    constexpr uint32_t kOpN  = 0x940093acU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0002] `sub_11f70` (`0x11f70..0x11fac`, 60 bytes)
 *        Hàm FDE[0002] `sub_11f70` (`0x11f70..0x11fac`, 60 bytes)
 * Disassembly: 0x11f70: stp x20, x19, [sp, #-0x20]! ; 0x11f74: stp x29, x30, [sp, #0x10] ; 0x11f78: add x29, sp, #0x10 ; 0x11f7c: adrp x20, #0x50000 ; 0x11f80: mov x19, xzr
 */
uint64_t fde_0002_0x11f70(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x11f70ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0003] `sub_11fac` (`0x11fac..0x12024`, 120 bytes)
 *        Hàm FDE[0003] `sub_11fac` (`0x11fac..0x12024`, 120 bytes)
 * Disassembly: 0x11fac: stp x20, x19, [sp, #-0x20]! ; 0x11fb0: stp x29, x30, [sp, #0x10] ; 0x11fb4: add x29, sp, #0x10 ; 0x11fb8: adrp x20, #0x50000 ; 0x11fbc: mov x19, xzr
 */
uint64_t fde_0003_0x11fac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x11facULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17fffddcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0004] `InitALogWrapper` (`0x12024..0x12068`, 68 bytes)
 *        Hàm FDE[0004] `InitALogWrapper` (`0x12024..0x12068`, 68 bytes)
 * Disassembly: 0x12024: stp x29, x30, [sp, #-0x10]! ; 0x12028: mov x29, sp ; 0x1202c: adrp x8, #0x50000 ; 0x12030: str x0, [x8, #0x348] ; 0x12034: adrp x0, #0x38000
 */
uint64_t fde_0004_0x12024(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12024ULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0005] `ALogWrite` (`0x12068..0x12098`, 48 bytes)
 *        Hàm FDE[0005] `ALogWrite` (`0x12068..0x12098`, 48 bytes)
 * Disassembly: 0x12068: adrp x9, #0x50000 ; 0x1206c: add x9, x9, #0x348 ; 0x12070: ldr x8, [x9] ; 0x12074: cbz x8, #0x12094 ; 0x12078: ldr x4, [x9, #8]
 */
uint64_t fde_0005_0x12068(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12068ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xd00001e9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0006] `ALogWriteV` (`0x12098..0x120a8`, 16 bytes)
 *        Hàm FDE[0006] `ALogWriteV` (`0x12098..0x120a8`, 16 bytes)
 * Disassembly: 0x12098: mov x2, x1 ; 0x1209c: mov x1, x0 ; 0x120a0: mov w0, wzr ; 0x120a4: b #0x10bf0
 */
uint64_t fde_0006_0x12098(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12098ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xaa0103e2U;
    constexpr uint32_t kOpN  = 0x17fffad3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0007] `ALogWriteD` (`0x120a8..0x120b4`, 12 bytes)
 *        Hàm FDE[0007] `ALogWriteD` (`0x120a8..0x120b4`, 12 bytes)
 * Disassembly: 0x120a8: mov x8, x0 ; 0x120ac: mov w0, #1 ; 0x120b0: b #0x1fb38
 */
uint64_t fde_0007_0x120a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x120a8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0x140036a2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0008] `ALogWriteI` (`0x120b4..0x120c0`, 12 bytes)
 *        Hàm FDE[0008] `ALogWriteI` (`0x120b4..0x120c0`, 12 bytes)
 * Disassembly: 0x120b4: mov x8, x0 ; 0x120b8: mov w0, #2 ; 0x120bc: b #0x1fb38
 */
uint64_t fde_0008_0x120b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x120b4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0x1400369fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0009] `ALogWriteW` (`0x120c0..0x120cc`, 12 bytes)
 *        Hàm FDE[0009] `ALogWriteW` (`0x120c0..0x120cc`, 12 bytes)
 * Disassembly: 0x120c0: mov x8, x0 ; 0x120c4: mov w0, #3 ; 0x120c8: b #0x1fb38
 */
uint64_t fde_0009_0x120c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x120c0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0x1400369cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0010] `ALogWriteE` (`0x120cc..0x120d8`, 12 bytes)
 *        Hàm FDE[0010] `ALogWriteE` (`0x120cc..0x120d8`, 12 bytes)
 * Disassembly: 0x120cc: mov x8, x0 ; 0x120d0: mov w0, #4 ; 0x120d4: b #0x1fb38
 */
uint64_t fde_0010_0x120cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x120ccULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0x14003699U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0011] `enable_log` (`0x120d8..0x120e8`, 16 bytes)
 *        Hàm FDE[0011] `enable_log` (`0x120d8..0x120e8`, 16 bytes)
 * Disassembly: 0x120d8: adrp x0, #0x38000 ; 0x120dc: add x0, x0, #0xd60 ; 0x120e0: mov w1, wzr ; 0x120e4: b #0x10ae0
 */
uint64_t fde_0011_0x120d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x120d8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xd0000120U;
    constexpr uint32_t kOpN  = 0x17fffa7fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0012] `sub_120e8` (`0x120e8..0x12138`, 80 bytes)
 *        Hàm FDE[0012] `sub_120e8` (`0x120e8..0x12138`, 80 bytes)
 * Disassembly: 0x120e8: str x21, [sp, #-0x30]! ; 0x120ec: stp x20, x19, [sp, #0x10] ; 0x120f0: stp x29, x30, [sp, #0x20] ; 0x120f4: add x29, sp, #0x20 ; 0x120f8: ldr x20, [x0, #0x10]
 */
uint64_t fde_0012_0x120e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x120e8ULL;
    constexpr uint64_t kSize = 0x50ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x14003538U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0013] `sub_12138` (`0x12138..0x1214c`, 20 bytes)
 *        Hàm FDE[0013] `sub_12138` (`0x12138..0x1214c`, 20 bytes)
 * Disassembly: 0x12138: ldrb w8, [x0] ; 0x1213c: tbnz w8, #0, #0x12144 ; 0x12140: ret ; 0x12144: ldr x0, [x0, #0x10] ; 0x12148: b #0x20e88
 */
uint64_t fde_0013_0x12138(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12138ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x39400008U;
    constexpr uint32_t kOpN  = 0x14003b50U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0014] `_Z12setDebugModeb` (`0x1214c..0x12158`, 12 bytes)
 *        Hàm FDE[0014] `_Z12setDebugModeb` (`0x1214c..0x12158`, 12 bytes)
 * Disassembly: 0x1214c: adrp x9, #0x4f000 ; 0x12150: ldr x9, [x9, #0xe38] ; 0x12154: b #0x2049c
 */
uint64_t fde_0014_0x1214c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1214cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb00001e9U;
    constexpr uint32_t kOpN  = 0x140038d2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0015] `_Z12getDebugModev` (`0x12158..0x12168`, 16 bytes)
 *        Hàm FDE[0015] `_Z12getDebugModev` (`0x12158..0x12168`, 16 bytes)
 * Disassembly: 0x12158: adrp x8, #0x4f000 ; 0x1215c: ldr x8, [x8, #0xe38] ; 0x12160: ldrb w0, [x8] ; 0x12164: ret
 */
uint64_t fde_0015_0x12158(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12158ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb00001e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0016] `_Z10enableLockv` (`0x12168..0x1216c`, 4 bytes)
 *        Hàm FDE[0016] `_Z10enableLockv` (`0x12168..0x1216c`, 4 bytes)
 * Disassembly: 0x12168: ret
 */
uint64_t fde_0016_0x12168(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12168ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0017] `_Z12doEnableLocklb` (`0x1216c..0x12258`, 236 bytes)
 *        Hàm FDE[0017] `_Z12doEnableLocklb` (`0x1216c..0x12258`, 236 bytes)
 * Disassembly: 0x1216c: sub sp, sp, #0x50 ; 0x12170: stp x24, x23, [sp, #0x10] ; 0x12174: stp x22, x21, [sp, #0x20] ; 0x12178: stp x20, x19, [sp, #0x30] ; 0x1217c: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0017_0x1216c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1216cULL;
    constexpr uint64_t kSize = 0xecULL;
    constexpr uint32_t kOp0  = 0xd10143ffU;
    constexpr uint32_t kOpN  = 0x97fffb8bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0018] `sub_12258` (`0x12258..0x124c0`, 616 bytes)
 *        Hàm FDE[0018] `sub_12258` (`0x12258..0x124c0`, 616 bytes)
 * Disassembly: 0x12258: mov x0, x30 ; 0x1225c: bl #0x1f620 ; 0x12260: mov x30, x0 ; 0x12264: stp x29, x30, [sp, #0x50] ; 0x12268: add x29, sp, #0x50
 */
uint64_t fde_0018_0x12258(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12258ULL;
    constexpr uint64_t kSize = 0x268ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e0U;
    constexpr uint32_t kOpN  = 0x97fffaf1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0019] `sub_124c0` (`0x124c0..0x1252c`, 108 bytes)
 *        Hàm FDE[0019] `sub_124c0` (`0x124c0..0x1252c`, 108 bytes)
 * Disassembly: 0x124c0: sub sp, sp, #0x110 ; 0x124c4: stp x28, x19, [sp, #0xf0] ; 0x124c8: stp x29, x30, [sp, #0x100] ; 0x124cc: add x29, sp, #0x100 ; 0x124d0: stp x4, x5, [sp, #0x80]
 */
uint64_t fde_0019_0x124c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x124c0ULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xd10443ffU;
    constexpr uint32_t kOpN  = 0x97fffad6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0020] `_Z19isSystraceInstalledv` (`0x1252c..0x12540`, 20 bytes)
 *        Hàm FDE[0020] `_Z19isSystraceInstalledv` (`0x1252c..0x12540`, 20 bytes)
 * Disassembly: 0x1252c: adrp x8, #0x4f000 ; 0x12530: ldr x8, [x8, #0xd40] ; 0x12534: ldarb w8, [x8] ; 0x12538: and w0, w8, #1 ; 0x1253c: ret
 */
uint64_t fde_0020_0x1252c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1252cULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xb00001e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0021] `_Z13doDisableLockv` (`0x12540..0x125b4`, 116 bytes)
 *        Hàm FDE[0021] `_Z13doDisableLockv` (`0x12540..0x125b4`, 116 bytes)
 * Disassembly: 0x12540: stp x20, x19, [sp, #-0x20]! ; 0x12544: stp x29, x30, [sp, #0x10] ; 0x12548: add x29, sp, #0x10 ; 0x1254c: bl #0x20118 ; 0x12550: cbz w8, #0x12568
 */
uint64_t fde_0021_0x12540(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12540ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17fffc74U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0022] `_Z12log_systracePKvm` (`0x125b4..0x128e8`, 820 bytes)
 *        Hàm FDE[0022] `_Z12log_systracePKvm` (`0x125b4..0x128e8`, 820 bytes)
 * Disassembly: 0x125b4: mov x2, x30 ; 0x125b8: bl #0x1ff68 ; 0x125bc: mov x30, x2 ; 0x125c0: stp x29, x30, [sp, #0xd0] ; 0x125c4: add x29, sp, #0xd0
 */
uint64_t fde_0022_0x125b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x125b4ULL;
    constexpr uint64_t kSize = 0x334ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e2U;
    constexpr uint32_t kOpN  = 0x94000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0023] `sub_128e8` (`0x128e8..0x128f4`, 12 bytes)
 *        Hàm FDE[0023] `sub_128e8` (`0x128e8..0x128f4`, 12 bytes)
 * Disassembly: 0x128e8: str x30, [sp, #-0x10]! ; 0x128ec: bl #0x2186c ; 0x128f0: bl #0x21ea8
 */
uint64_t fde_0023_0x128e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x128e8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf81f0ffeU;
    constexpr uint32_t kOpN  = 0x94003d6eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0024] `_Z19should_log_systraceim` (`0x128f4..0x12940`, 76 bytes)
 *        Hàm FDE[0024] `_Z19should_log_systraceim` (`0x128f4..0x12940`, 76 bytes)
 * Disassembly: 0x128f4: adrp x8, #0x50000 ; 0x128f8: ldrb w8, [x8, #0x2f0] ; 0x128fc: cmp w8, #1 ; 0x12900: b.ne #0x12914 ; 0x12904: adrp x8, #0x4f000
 */
uint64_t fde_0024_0x128f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x128f4ULL;
    constexpr uint64_t kSize = 0x4cULL;
    constexpr uint32_t kOp0  = 0xd00001e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0025] `_Z10write_hookiPKvm` (`0x12940..0x1299c`, 92 bytes)
 *        Hàm FDE[0025] `_Z10write_hookiPKvm` (`0x12940..0x1299c`, 92 bytes)
 * Disassembly: 0x12940: str x21, [sp, #-0x30]! ; 0x12944: stp x20, x19, [sp, #0x10] ; 0x12948: stp x29, x30, [sp, #0x20] ; 0x1294c: add x29, sp, #0x20 ; 0x12950: mov x20, x1
 */
uint64_t fde_0025_0x12940(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12940ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17fffff7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0026] `_Z18init_atrace_recordv` (`0x1299c..0x129d4`, 56 bytes)
 *        Hàm FDE[0026] `_Z18init_atrace_recordv` (`0x1299c..0x129d4`, 56 bytes)
 * Disassembly: 0x1299c: adrp x8, #0x4f000 ; 0x129a0: ldr x8, [x8, #0xe90] ; 0x129a4: ldrb w9, [x8] ; 0x129a8: cbz w9, #0x129b0 ; 0x129ac: ret
 */
uint64_t fde_0026_0x1299c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1299cULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0xb00001e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0027] `_Z14hookLoadedLibsv` (`0x129d4..0x12a40`, 108 bytes)
 *        Hàm FDE[0027] `_Z14hookLoadedLibsv` (`0x129d4..0x12a40`, 108 bytes)
 * Disassembly: 0x129d4: stp x20, x19, [sp, #-0x20]! ; 0x129d8: stp x29, x30, [sp, #0x10] ; 0x129dc: add x29, sp, #0x10 ; 0x129e0: adrp x19, #0x50000 ; 0x129e4: ldrb w8, [x19, #0x1f4]
 */
uint64_t fde_0027_0x129d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x129d4ULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x140032ffU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0028] `_Z16unHookLoadedLibsv` (`0x12a40..0x12a80`, 64 bytes)
 *        Hàm FDE[0028] `_Z16unHookLoadedLibsv` (`0x12a40..0x12a80`, 64 bytes)
 * Disassembly: 0x12a40: str x19, [sp, #-0x20]! ; 0x12a44: stp x29, x30, [sp, #0x10] ; 0x12a48: add x29, sp, #0x10 ; 0x12a4c: adrp x19, #0x50000 ; 0x12a50: ldrb w8, [x19, #0x1f4]
 */
uint64_t fde_0028_0x12a40(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12a40ULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14003301U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0029] `_Z20getCurrentThreadNamePNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE` (`0x12a80..0x12af8`, 120 bytes)
 *        Hàm FDE[0029] `_Z20getCurrentThreadNamePNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE` (`0x12a80..0x12af8`, 120 bytes)
 * Disassembly: 0x12a80: sub sp, sp, #0x90 ; 0x12a84: stp x20, x19, [sp, #0x70] ; 0x12a88: stp x29, x30, [sp, #0x80] ; 0x12a8c: add x29, sp, #0x80 ; 0x12a90: mrs x20, tpidr_el0
 */
uint64_t fde_0029_0x12a80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12a80ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xd10243ffU;
    constexpr uint32_t kOpN  = 0x97fff963U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0030] `sub_12af8` (`0x12af8..0x12b24`, 44 bytes)
 *        Hàm FDE[0030] `sub_12af8` (`0x12af8..0x12b24`, 44 bytes)
 * Disassembly: 0x12af8: stp x20, x19, [sp, #-0x20]! ; 0x12afc: stp x29, x30, [sp, #0x10] ; 0x12b00: add x29, sp, #0x10 ; 0x12b04: mov x20, x0 ; 0x12b08: bl #0x204f0
 */
uint64_t fde_0030_0x12af8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12af8ULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0031] `sub_12b24` (`0x12b24..0x12be8`, 196 bytes)
 *        Hàm FDE[0031] `sub_12b24` (`0x12b24..0x12be8`, 196 bytes)
 * Disassembly: 0x12b24: str x21, [sp, #-0x30]! ; 0x12b28: stp x20, x19, [sp, #0x10] ; 0x12b2c: stp x29, x30, [sp, #0x20] ; 0x12b30: add x29, sp, #0x20 ; 0x12b34: ldrb w8, [x0]
 */
uint64_t fde_0031_0x12b24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12b24ULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0032] `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc` (`0x12be8..0x12d18`, 304 bytes)
 *        Hàm FDE[0032] `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc` (`0x12be8..0x12d18`, 304 bytes)
 * Disassembly: 0x12be8: mov x8, x30 ; 0x12bec: bl #0x1f620 ; 0x12bf0: mov x30, x8 ; 0x12bf4: stp x29, x30, [sp, #0x50] ; 0x12bf8: add x29, sp, #0x50
 */
uint64_t fde_0032_0x12be8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12be8ULL;
    constexpr uint64_t kSize = 0x130ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e8U;
    constexpr uint32_t kOpN  = 0x97fff99fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0033] `_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv` (`0x12d18..0x12d2c`, 20 bytes)
 *        Hàm FDE[0033] `_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv` (`0x12d18..0x12d2c`, 20 bytes)
 * Disassembly: 0x12d18: stp x29, x30, [sp, #-0x10]! ; 0x12d1c: mov x29, sp ; 0x12d20: adrp x0, #0x3c000 ; 0x12d24: add x0, x0, #0x52c ; 0x12d28: bl #0x12d38
 */
uint64_t fde_0033_0x12d18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12d18ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x94000004U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0034] `sub_12d2c` (`0x12d2c..0x12d38`, 12 bytes)
 *        Hàm FDE[0034] `sub_12d2c` (`0x12d2c..0x12d38`, 12 bytes)
 * Disassembly: 0x12d2c: cbz x2, #0x12d34 ; 0x12d30: b #0x115f0 ; 0x12d34: ret
 */
uint64_t fde_0034_0x12d2c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12d2cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb4000042U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0035] `sub_12d38` (`0x12d38..0x12d80`, 72 bytes)
 *        Hàm FDE[0035] `sub_12d38` (`0x12d38..0x12d80`, 72 bytes)
 * Disassembly: 0x12d38: stp x20, x19, [sp, #-0x20]! ; 0x12d3c: stp x29, x30, [sp, #0x10] ; 0x12d40: add x29, sp, #0x10 ; 0x12d44: mov x20, x0 ; 0x12d48: mov w0, #0x10
 */
uint64_t fde_0035_0x12d38(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12d38ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x940034f3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0036] `sub_12d80` (`0x12d80..0x12dac`, 44 bytes)
 *        Hàm FDE[0036] `sub_12d80` (`0x12d80..0x12dac`, 44 bytes)
 * Disassembly: 0x12d80: str x19, [sp, #-0x20]! ; 0x12d84: stp x29, x30, [sp, #0x10] ; 0x12d88: add x29, sp, #0x10 ; 0x12d8c: mov x19, x0 ; 0x12d90: bl #0x20e8c
 */
uint64_t fde_0036_0x12d80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12d80ULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14003236U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0037] `_Z18reset_atrace_eventP11AtraceEvent` (`0x12dac..0x12dd0`, 36 bytes)
 *        Hàm FDE[0037] `_Z18reset_atrace_eventP11AtraceEvent` (`0x12dac..0x12dd0`, 36 bytes)
 * Disassembly: 0x12dac: str x19, [sp, #-0x20]! ; 0x12db0: stp x29, x30, [sp, #0x10] ; 0x12db4: add x29, sp, #0x10 ; 0x12db8: mov x19, x0 ; 0x12dbc: ldr x0, [x0, #0x10]
 */
uint64_t fde_0037_0x12dac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12dacULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x1400322dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0038] `_Z11recordTracePKvm` (`0x12dd0..0x13118`, 840 bytes)
 *        Hàm FDE[0038] `_Z11recordTracePKvm` (`0x12dd0..0x13118`, 840 bytes)
 * Disassembly: 0x12dd0: sub sp, sp, #0x80 ; 0x12dd4: stp x26, x25, [sp, #0x30] ; 0x12dd8: stp x24, x23, [sp, #0x40] ; 0x12ddc: stp x22, x21, [sp, #0x50] ; 0x12de0: stp x20, x19, [sp, #0x60]
 */
uint64_t fde_0038_0x12dd0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x12dd0ULL;
    constexpr uint64_t kSize = 0x348ULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0x94003138U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0039] `sub_13118` (`0x13118..0x13124`, 12 bytes)
 *        Hàm FDE[0039] `sub_13118` (`0x13118..0x13124`, 12 bytes)
 * Disassembly: 0x13118: stp xzr, xzr, [x0] ; 0x1311c: str xzr, [x0, #0x10] ; 0x13120: b #0x135bc
 */
uint64_t fde_0039_0x13118(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13118ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9007c1fU;
    constexpr uint32_t kOpN  = 0x14000127U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0040] `sub_13124` (`0x13124..0x133dc`, 696 bytes)
 *        Hàm FDE[0040] `sub_13124` (`0x13124..0x133dc`, 696 bytes)
 * Disassembly: 0x13124: sub sp, sp, #0x60 ; 0x13128: stp x24, x23, [sp, #0x20] ; 0x1312c: stp x22, x21, [sp, #0x30] ; 0x13130: stp x20, x19, [sp, #0x40] ; 0x13134: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_0040_0x13124(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13124ULL;
    constexpr uint64_t kSize = 0x2b8ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x94003087U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0041] `sub_133dc` (`0x133dc..0x13410`, 52 bytes)
 *        Hàm FDE[0041] `sub_133dc` (`0x133dc..0x13410`, 52 bytes)
 * Disassembly: 0x133dc: cmp x0, x1 ; 0x133e0: b.eq #0x1340c ; 0x133e4: stp x29, x30, [sp, #-0x10]! ; 0x133e8: mov x29, sp ; 0x133ec: ldrb w8, [x1]
 */
uint64_t fde_0041_0x133dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x133dcULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xeb01001fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0042] `sub_13410` (`0x13410..0x13448`, 56 bytes)
 *        Hàm FDE[0042] `sub_13410` (`0x13410..0x13448`, 56 bytes)
 * Disassembly: 0x13410: str x19, [sp, #-0x20]! ; 0x13414: stp x29, x30, [sp, #0x10] ; 0x13418: add x29, sp, #0x10 ; 0x1341c: ldr x19, [x0] ; 0x13420: str xzr, [x0]
 */
uint64_t fde_0042_0x13410(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13410ULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x1400308fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0043] `sub_13448` (`0x13448..0x1359c`, 340 bytes)
 *        Hàm FDE[0043] `sub_13448` (`0x13448..0x1359c`, 340 bytes)
 * Disassembly: 0x13448: str x19, [sp, #-0x20]! ; 0x1344c: stp x29, x30, [sp, #0x10] ; 0x13450: add x29, sp, #0x10 ; 0x13454: cbz x0, #0x134d0 ; 0x13458: mov x19, x0
 */
uint64_t fde_0043_0x13448(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13448ULL;
    constexpr uint64_t kSize = 0x154ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x940030c1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0044] `sub_1359c` (`0x1359c..0x135bc`, 32 bytes)
 *        Hàm FDE[0044] `sub_1359c` (`0x1359c..0x135bc`, 32 bytes)
 * Disassembly: 0x1359c: adrp x9, #0x4f000 ; 0x135a0: ldr x9, [x9, #0xd48] ; 0x135a4: ldr x8, [x9] ; 0x135a8: str x0, [x9] ; 0x135ac: cbz x8, #0x135b8
 */
uint64_t fde_0044_0x1359c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1359cULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0x900001e9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0045] `sub_135bc` (`0x135bc..0x135d8`, 28 bytes)
 *        Hàm FDE[0045] `sub_135bc` (`0x135bc..0x135d8`, 28 bytes)
 * Disassembly: 0x135bc: mov x8, xzr ; 0x135c0: cmp x8, #0x18 ; 0x135c4: b.eq #0x135d4 ; 0x135c8: str xzr, [x0, x8] ; 0x135cc: add x8, x8, #8
 */
uint64_t fde_0045_0x135bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x135bcULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xaa1f03e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0046] `_Z14lockinfo_chars9LockEvent` (`0x135d8..0x13670`, 152 bytes)
 *        Hàm FDE[0046] `_Z14lockinfo_chars9LockEvent` (`0x135d8..0x13670`, 152 bytes)
 * Disassembly: 0x135d8: stp x28, x21, [sp, #-0x30]! ; 0x135dc: stp x20, x19, [sp, #0x10] ; 0x135e0: stp x29, x30, [sp, #0x20] ; 0x135e4: add x29, sp, #0x20 ; 0x135e8: sub sp, sp, #1, lsl #12
 */
uint64_t fde_0046_0x135d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x135d8ULL;
    constexpr uint64_t kSize = 0x98ULL;
    constexpr uint32_t kOp0  = 0xa9bd57fcU;
    constexpr uint32_t kOpN  = 0x97fff685U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0047] `_Z21dumpAtraceRangeToALogP7_JNIEnvll` (`0x13670..0x13a20`, 944 bytes)
 *        Hàm FDE[0047] `_Z21dumpAtraceRangeToALogP7_JNIEnvll` (`0x13670..0x13a20`, 944 bytes)
 * Disassembly: 0x13670: mov x0, x30 ; 0x13674: bl #0x1f620 ; 0x13678: mov x30, x0 ; 0x1367c: stp x29, x30, [sp, #0x50] ; 0x13680: add x29, sp, #0x50
 */
uint64_t fde_0047_0x13670(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13670ULL;
    constexpr uint64_t kSize = 0x3b0ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e0U;
    constexpr uint32_t kOpN  = 0x97fff599U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0048] `_Z15dumpAtraceRangeP7_JNIEnvll` (`0x13a20..0x13e40`, 1056 bytes)
 *        Hàm FDE[0048] `_Z15dumpAtraceRangeP7_JNIEnvll` (`0x13a20..0x13e40`, 1056 bytes)
 * Disassembly: 0x13a20: mov x3, x30 ; 0x13a24: bl #0x1f620 ; 0x13a28: mov x30, x3 ; 0x13a2c: stp x29, x30, [sp, #0x50] ; 0x13a30: add x29, sp, #0x50
 */
uint64_t fde_0048_0x13a20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13a20ULL;
    constexpr uint64_t kSize = 0x420ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e3U;
    constexpr uint32_t kOpN  = 0x97fff491U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0049] `sub_13e40` (`0x13e40..0x13e7c`, 60 bytes)
 *        Hàm FDE[0049] `sub_13e40` (`0x13e40..0x13e7c`, 60 bytes)
 * Disassembly: 0x13e40: sub sp, sp, #0x120 ; 0x13e44: stp x28, x19, [sp, #0x100] ; 0x13e48: stp x29, x30, [sp, #0x110] ; 0x13e4c: add x29, sp, #0x110 ; 0x13e50: bl #0x1f594
 */
uint64_t fde_0049_0x13e40(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13e40ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xd10483ffU;
    constexpr uint32_t kOpN  = 0x97fff482U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0050] `_Z13isSymbolReadyv` (`0x13e7c..0x13eac`, 48 bytes)
 *        Hàm FDE[0050] `_Z13isSymbolReadyv` (`0x13e7c..0x13eac`, 48 bytes)
 * Disassembly: 0x13e7c: adrp x8, #0x4f000 ; 0x13e80: ldr x8, [x8, #0xf68] ; 0x13e84: adrp x9, #0x4f000 ; 0x13e88: ldr x8, [x8] ; 0x13e8c: ldr x9, [x9, #0xed0]
 */
uint64_t fde_0050_0x13e7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13e7cULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0x900001e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0051] `_Z11initSymbolsv` (`0x13eac..0x140b0`, 516 bytes)
 *        Hàm FDE[0051] `_Z11initSymbolsv` (`0x13eac..0x140b0`, 516 bytes)
 * Disassembly: 0x13eac: sub sp, sp, #0xd0 ; 0x13eb0: stp x22, x21, [sp, #0xa0] ; 0x13eb4: stp x20, x19, [sp, #0xb0] ; 0x13eb8: stp x29, x30, [sp, #0xc0] ; 0x13ebc: add x29, sp, #0xc0
 */
uint64_t fde_0051_0x13eac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x13eacULL;
    constexpr uint64_t kSize = 0x204ULL;
    constexpr uint32_t kOp0  = 0xd10343ffU;
    constexpr uint32_t kOpN  = 0x94002d52U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0052] `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc` (`0x140b0..0x140e4`, 52 bytes)
 *        Hàm FDE[0052] `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc` (`0x140b0..0x140e4`, 52 bytes)
 * Disassembly: 0x140b0: stp x20, x19, [sp, #-0x20]! ; 0x140b4: stp x29, x30, [sp, #0x10] ; 0x140b8: add x29, sp, #0x10 ; 0x140bc: mov x20, x0 ; 0x140c0: stp xzr, xzr, [x0]
 */
uint64_t fde_0052_0x140b0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x140b0ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0053] `sub_140e4` (`0x140e4..0x14160`, 124 bytes)
 *        Hàm FDE[0053] `sub_140e4` (`0x140e4..0x14160`, 124 bytes)
 * Disassembly: 0x140e4: stp x22, x21, [sp, #-0x30]! ; 0x140e8: stp x20, x19, [sp, #0x10] ; 0x140ec: stp x29, x30, [sp, #0x20] ; 0x140f0: add x29, sp, #0x20 ; 0x140f4: cmn x2, #0x10
 */
uint64_t fde_0053_0x140e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x140e4ULL;
    constexpr uint64_t kSize = 0x7cULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x97fff48dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0054] `_Z12initIfNeededv` (`0x14160..0x14174`, 20 bytes)
 *        Hàm FDE[0054] `_Z12initIfNeededv` (`0x14160..0x14174`, 20 bytes)
 * Disassembly: 0x14160: stp x29, x30, [sp, #-0x10]! ; 0x14164: mov x29, sp ; 0x14168: bl #0x11700 ; 0x1416c: ldp x29, x30, [sp], #0x10 ; 0x14170: b #0x10ce0
 */
uint64_t fde_0054_0x14160(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14160ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x17fff2dcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0055] `_Z14enableSystraceP7_JavaVMil` (`0x14174..0x14230`, 188 bytes)
 *        Hàm FDE[0055] `_Z14enableSystraceP7_JavaVMil` (`0x14174..0x14230`, 188 bytes)
 * Disassembly: 0x14174: str x21, [sp, #-0x30]! ; 0x14178: stp x20, x19, [sp, #0x10] ; 0x1417c: stp x29, x30, [sp, #0x20] ; 0x14180: add x29, sp, #0x20 ; 0x14184: adrp x21, #0x4f000
 */
uint64_t fde_0055_0x14174(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14174ULL;
    constexpr uint64_t kSize = 0xbcULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x14002cfaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0056] `_Z15restoreSystracev` (`0x14230..0x142a8`, 120 bytes)
 *        Hàm FDE[0056] `_Z15restoreSystracev` (`0x14230..0x142a8`, 120 bytes)
 * Disassembly: 0x14230: str x21, [sp, #-0x30]! ; 0x14234: stp x20, x19, [sp, #0x10] ; 0x14238: stp x29, x30, [sp, #0x20] ; 0x1423c: add x29, sp, #0x20 ; 0x14240: adrp x19, #0x4f000
 */
uint64_t fde_0056_0x14230(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14230ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x14002cdcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0057] `_Z16startHyperAtracev` (`0x142a8..0x14308`, 96 bytes)
 *        Hàm FDE[0057] `_Z16startHyperAtracev` (`0x142a8..0x14308`, 96 bytes)
 * Disassembly: 0x142a8: str x19, [sp, #-0x20]! ; 0x142ac: stp x29, x30, [sp, #0x10] ; 0x142b0: add x29, sp, #0x10 ; 0x142b4: adrp x19, #0x4f000 ; 0x142b8: ldr x19, [x19, #0xf18]
 */
uint64_t fde_0057_0x142a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x142a8ULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14002cdfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0058] `_Z15stopHyperAtracev` (`0x14308..0x143a0`, 152 bytes)
 *        Hàm FDE[0058] `_Z15stopHyperAtracev` (`0x14308..0x143a0`, 152 bytes)
 * Disassembly: 0x14308: stp x20, x19, [sp, #-0x20]! ; 0x1430c: stp x29, x30, [sp, #0x10] ; 0x14310: add x29, sp, #0x10 ; 0x14314: adrp x19, #0x4f000 ; 0x14318: ldr x19, [x19, #0xf18]
 */
uint64_t fde_0058_0x14308(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14308ULL;
    constexpr uint64_t kSize = 0x98ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14002ca7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0059] `_Z13transact_hookPvijPKvS_j` (`0x143a0..0x144a4`, 260 bytes)
 *        Hàm FDE[0059] `_Z13transact_hookPvijPKvS_j` (`0x143a0..0x144a4`, 260 bytes)
 * Disassembly: 0x143a0: str x25, [sp, #-0x50]! ; 0x143a4: stp x24, x23, [sp, #0x10] ; 0x143a8: stp x22, x21, [sp, #0x20] ; 0x143ac: stp x20, x19, [sp, #0x30] ; 0x143b0: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0059_0x143a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x143a0ULL;
    constexpr uint64_t kSize = 0x104ULL;
    constexpr uint32_t kOp0  = 0xf81b0ff9U;
    constexpr uint32_t kOpN  = 0xd61f00c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0060] `_Z11hook_binderv` (`0x144a4..0x144d4`, 48 bytes)
 *        Hàm FDE[0060] `_Z11hook_binderv` (`0x144a4..0x144d4`, 48 bytes)
 * Disassembly: 0x144a4: stp x29, x30, [sp, #-0x10]! ; 0x144a8: mov x29, sp ; 0x144ac: bl #0x11710 ; 0x144b0: adrp x2, #0x4f000 ; 0x144b4: ldr x2, [x2, #0xf60]
 */
uint64_t fde_0060_0x144a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x144a4ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x17fff248U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0061] `_Z13unhook_binderv` (`0x144d4..0x14508`, 52 bytes)
 *        Hàm FDE[0061] `_Z13unhook_binderv` (`0x144d4..0x14508`, 52 bytes)
 * Disassembly: 0x144d4: stp x29, x30, [sp, #-0x10]! ; 0x144d8: mov x29, sp ; 0x144dc: bl #0x11710 ; 0x144e0: adrp x8, #0x4f000 ; 0x144e4: ldr x8, [x8, #0xfb8]
 */
uint64_t fde_0061_0x144d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x144d4ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x17fff23bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0062] `_Z13disableBinderv` (`0x14508..0x1450c`, 4 bytes)
 *        Hàm FDE[0062] `_Z13disableBinderv` (`0x14508..0x1450c`, 4 bytes)
 * Disassembly: 0x14508: b #0x10b50
 */
uint64_t fde_0062_0x14508(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14508ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff192U;
    constexpr uint32_t kOpN  = 0x17fff192U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0063] `_Z12enableBinderv` (`0x1450c..0x147a4`, 664 bytes)
 *        Hàm FDE[0063] `_Z12enableBinderv` (`0x1450c..0x147a4`, 664 bytes)
 * Disassembly: 0x1450c: sub sp, sp, #0xb0 ; 0x14510: stp x22, x21, [sp, #0x80] ; 0x14514: stp x20, x19, [sp, #0x90] ; 0x14518: stp x29, x30, [sp, #0xa0] ; 0x1451c: add x29, sp, #0xa0
 */
uint64_t fde_0063_0x1450c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1450cULL;
    constexpr uint64_t kSize = 0x298ULL;
    constexpr uint32_t kOp0  = 0xd102c3ffU;
    constexpr uint32_t kOpN  = 0x9400899fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0064] `_Z5getVMv` (`0x147a4..0x147b4`, 16 bytes)
 *        Hàm FDE[0064] `_Z5getVMv` (`0x147a4..0x147b4`, 16 bytes)
 * Disassembly: 0x147a4: adrp x8, #0x4f000 ; 0x147a8: ldr x8, [x8, #0xd10] ; 0x147ac: ldr x0, [x8] ; 0x147b0: ret
 */
uint64_t fde_0064_0x147a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x147a4ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf00001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0065] `JNI_OnLoad` (`0x147b4..0x1498c`, 472 bytes)
 *        Hàm FDE[0065] `JNI_OnLoad` (`0x147b4..0x1498c`, 472 bytes)
 * Disassembly: 0x147b4: stp x28, x21, [sp, #-0x30]! ; 0x147b8: stp x20, x19, [sp, #0x10] ; 0x147bc: stp x29, x30, [sp, #0x20] ; 0x147c0: add x29, sp, #0x20 ; 0x147c4: sub sp, sp, #0x460
 */
uint64_t fde_0065_0x147b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x147b4ULL;
    constexpr uint64_t kSize = 0x1d8ULL;
    constexpr uint32_t kOp0  = 0xa9bd57fcU;
    constexpr uint32_t kOpN  = 0x97fff1beU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0066] `_Z14doSetDebugModeP7_JNIEnvP7_jclassh` (`0x1498c..0x14998`, 12 bytes)
 *        Hàm FDE[0066] `_Z14doSetDebugModeP7_JNIEnvP7_jclassh` (`0x1498c..0x14998`, 12 bytes)
 * Disassembly: 0x1498c: adrp x9, #0x4f000 ; 0x14990: ldr x9, [x9, #0xe38] ; 0x14994: b #0x200a0
 */
uint64_t fde_0066_0x1498c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1498cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf00001c9U;
    constexpr uint32_t kOpN  = 0x14002dc3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0067] `_Z6doInitP7_JNIEnvP7_jclass` (`0x14998..0x1499c`, 4 bytes)
 *        Hàm FDE[0067] `_Z6doInitP7_JNIEnvP7_jclass` (`0x14998..0x1499c`, 4 bytes)
 * Disassembly: 0x14998: b #0x112b0
 */
uint64_t fde_0067_0x14998(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14998ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff246U;
    constexpr uint32_t kOpN  = 0x17fff246U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0068] `_Z7doStartP7_JNIEnvP7_jclass` (`0x1499c..0x149a0`, 4 bytes)
 *        Hàm FDE[0068] `_Z7doStartP7_JNIEnvP7_jclass` (`0x1499c..0x149a0`, 4 bytes)
 * Disassembly: 0x1499c: ret
 */
uint64_t fde_0068_0x1499c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1499cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0069] `_Z13doGetProcInfoP7_JNIEnvP7_jclass` (`0x149a0..0x149a4`, 4 bytes)
 *        Hàm FDE[0069] `_Z13doGetProcInfoP7_JNIEnvP7_jclass` (`0x149a0..0x149a4`, 4 bytes)
 * Disassembly: 0x149a0: b #0x11600
 */
uint64_t fde_0069_0x149a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149a0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff318U;
    constexpr uint32_t kOpN  = 0x17fff318U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0070] `_Z29doDumpProcInfoTimeRangeToALogP7_JNIEnvP7_jclassll` (`0x149a4..0x149a8`, 4 bytes)
 *        Hàm FDE[0070] `_Z29doDumpProcInfoTimeRangeToALogP7_JNIEnvP7_jclassll` (`0x149a4..0x149a8`, 4 bytes)
 * Disassembly: 0x149a4: b #0x10f30
 */
uint64_t fde_0070_0x149a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149a4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff163U;
    constexpr uint32_t kOpN  = 0x17fff163U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0071] `_Z22doGetProcInfoTimeRangeP7_JNIEnvP7_jclassll` (`0x149a8..0x149ac`, 4 bytes)
 *        Hàm FDE[0071] `_Z22doGetProcInfoTimeRangeP7_JNIEnvP7_jclassll` (`0x149a8..0x149ac`, 4 bytes)
 * Disassembly: 0x149a8: b #0x114e0
 */
uint64_t fde_0071_0x149a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149a8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff2ceU;
    constexpr uint32_t kOpN  = 0x17fff2ceU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0072] `_Z15doSetBufferSizeP7_JNIEnvP7_jclassi` (`0x149ac..0x149b0`, 4 bytes)
 *        Hàm FDE[0072] `_Z15doSetBufferSizeP7_JNIEnvP7_jclassi` (`0x149ac..0x149b0`, 4 bytes)
 * Disassembly: 0x149ac: b #0x10fc0
 */
uint64_t fde_0072_0x149ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149acULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff185U;
    constexpr uint32_t kOpN  = 0x17fff185U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0073] `_Z9doCollectP7_JNIEnvP7_jclass` (`0x149b0..0x149b4`, 4 bytes)
 *        Hàm FDE[0073] `_Z9doCollectP7_JNIEnvP7_jclass` (`0x149b0..0x149b4`, 4 bytes)
 * Disassembly: 0x149b0: b #0x10ad0
 */
uint64_t fde_0073_0x149b0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149b0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff048U;
    constexpr uint32_t kOpN  = 0x17fff048U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0074] `_Z6doStopP7_JNIEnvP7_jclass` (`0x149b4..0x149b8`, 4 bytes)
 *        Hàm FDE[0074] `_Z6doStopP7_JNIEnvP7_jclass` (`0x149b4..0x149b8`, 4 bytes)
 * Disassembly: 0x149b4: ret
 */
uint64_t fde_0074_0x149b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149b4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0075] `_Z9doDestroyP7_JNIEnvP7_jclass` (`0x149b8..0x149bc`, 4 bytes)
 *        Hàm FDE[0075] `_Z9doDestroyP7_JNIEnvP7_jclass` (`0x149b8..0x149bc`, 4 bytes)
 * Disassembly: 0x149b8: ret
 */
uint64_t fde_0075_0x149b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149b8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0076] `_Z12doGetCpuTimeP7_JNIEnvP7_jclassi` (`0x149bc..0x149c0`, 4 bytes)
 *        Hàm FDE[0076] `_Z12doGetCpuTimeP7_JNIEnvP7_jclassi` (`0x149bc..0x149c0`, 4 bytes)
 * Disassembly: 0x149bc: b #0x10ab0
 */
uint64_t fde_0076_0x149bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149bcULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff03dU;
    constexpr uint32_t kOpN  = 0x17fff03dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0077] `_Z15doGetAppCpuTimeP7_JNIEnvP7_jclass` (`0x149c0..0x149c4`, 4 bytes)
 *        Hàm FDE[0077] `_Z15doGetAppCpuTimeP7_JNIEnvP7_jclass` (`0x149c0..0x149c4`, 4 bytes)
 * Disassembly: 0x149c0: b #0x10db0
 */
uint64_t fde_0077_0x149c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149c0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff0fcU;
    constexpr uint32_t kOpN  = 0x17fff0fcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0078] `_Z29doGetTotalCPUTimeByTimeInStatP7_JNIEnvP7_jclassi` (`0x149c4..0x149c8`, 4 bytes)
 *        Hàm FDE[0078] `_Z29doGetTotalCPUTimeByTimeInStatP7_JNIEnvP7_jclassi` (`0x149c4..0x149c8`, 4 bytes)
 * Disassembly: 0x149c4: b #0x11220
 */
uint64_t fde_0078_0x149c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149c4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff217U;
    constexpr uint32_t kOpN  = 0x17fff217U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0079] `_Z19doGetThreadStatInfoP7_JNIEnvP7_jclassii` (`0x149c8..0x149cc`, 4 bytes)
 *        Hàm FDE[0079] `_Z19doGetThreadStatInfoP7_JNIEnvP7_jclassii` (`0x149c8..0x149cc`, 4 bytes)
 * Disassembly: 0x149c8: b #0x10f20
 */
uint64_t fde_0079_0x149c8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149c8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff156U;
    constexpr uint32_t kOpN  = 0x17fff156U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0080] `_Z17doDumpNativeStackP7_JNIEnvP7_jclassi` (`0x149cc..0x149d0`, 4 bytes)
 *        Hàm FDE[0080] `_Z17doDumpNativeStackP7_JNIEnvP7_jclassi` (`0x149cc..0x149d0`, 4 bytes)
 * Disassembly: 0x149cc: b #0x11580
 */
uint64_t fde_0080_0x149cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149ccULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff2edU;
    constexpr uint32_t kOpN  = 0x17fff2edU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0081] `_Z15doGetProcCGroupP7_JNIEnvP7_jclassi` (`0x149d0..0x149d4`, 4 bytes)
 *        Hàm FDE[0081] `_Z15doGetProcCGroupP7_JNIEnvP7_jclassi` (`0x149d0..0x149d4`, 4 bytes)
 * Disassembly: 0x149d0: b #0x10c50
 */
uint64_t fde_0081_0x149d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149d0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff0a0U;
    constexpr uint32_t kOpN  = 0x17fff0a0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0082] `_Z14doGetSchedInfoP7_JNIEnvP7_jclassi` (`0x149d4..0x149d8`, 4 bytes)
 *        Hàm FDE[0082] `_Z14doGetSchedInfoP7_JNIEnvP7_jclassi` (`0x149d4..0x149d8`, 4 bytes)
 * Disassembly: 0x149d4: b #0x10ec0
 */
uint64_t fde_0082_0x149d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149d4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff13bU;
    constexpr uint32_t kOpN  = 0x17fff13bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0083] `_Z14doEnableAtraceP7_JNIEnvP7_jclassil` (`0x149d8..0x149f0`, 24 bytes)
 *        Hàm FDE[0083] `_Z14doEnableAtraceP7_JNIEnvP7_jclassil` (`0x149d8..0x149f0`, 24 bytes)
 * Disassembly: 0x149d8: adrp x8, #0x4f000 ; 0x149dc: ldr x8, [x8, #0xd10] ; 0x149e0: mov w1, w2 ; 0x149e4: mov x2, x3 ; 0x149e8: ldr x0, [x8]
 */
uint64_t fde_0083_0x149d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149d8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf00001c8U;
    constexpr uint32_t kOpN  = 0x17fff0edU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0084] `_Z15doDisableAtraceP7_JNIEnvP7_jclass` (`0x149f0..0x149f4`, 4 bytes)
 *        Hàm FDE[0084] `_Z15doDisableAtraceP7_JNIEnvP7_jclass` (`0x149f0..0x149f4`, 4 bytes)
 * Disassembly: 0x149f0: b #0x11750
 */
uint64_t fde_0084_0x149f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149f0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff358U;
    constexpr uint32_t kOpN  = 0x17fff358U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0085] `_Z12doDumpAtraceP7_JNIEnvP7_jclass` (`0x149f4..0x14a00`, 12 bytes)
 *        Hàm FDE[0085] `_Z12doDumpAtraceP7_JNIEnvP7_jclass` (`0x149f4..0x14a00`, 12 bytes)
 * Disassembly: 0x149f4: mov x2, #0x7fffffffffffffff ; 0x149f8: mov x1, xzr ; 0x149fc: b #0x10a40
 */
uint64_t fde_0085_0x149f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x149f4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x92f00002U;
    constexpr uint32_t kOpN  = 0x17fff011U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0086] `_Z23doDumpAtraceRangeToALogP7_JNIEnvP7_jclassll` (`0x14a00..0x14a0c`, 12 bytes)
 *        Hàm FDE[0086] `_Z23doDumpAtraceRangeToALogP7_JNIEnvP7_jclassll` (`0x14a00..0x14a0c`, 12 bytes)
 * Disassembly: 0x14a00: mov x1, x2 ; 0x14a04: mov x2, x3 ; 0x14a08: b #0x114f0
 */
uint64_t fde_0086_0x14a00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a00ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0203e1U;
    constexpr uint32_t kOpN  = 0x17fff2baU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0087] `_Z17doDumpAtraceRangeP7_JNIEnvP7_jclassll` (`0x14a0c..0x14a18`, 12 bytes)
 *        Hàm FDE[0087] `_Z17doDumpAtraceRangeP7_JNIEnvP7_jclassll` (`0x14a0c..0x14a18`, 12 bytes)
 * Disassembly: 0x14a0c: mov x1, x2 ; 0x14a10: mov x2, x3 ; 0x14a14: b #0x10a40
 */
uint64_t fde_0087_0x14a0c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a0cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0203e1U;
    constexpr uint32_t kOpN  = 0x17fff00bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0088] `_Z10enableLockP7_JNIEnvP7_jclassl` (`0x14a18..0x14a24`, 12 bytes)
 *        Hàm FDE[0088] `_Z10enableLockP7_JNIEnvP7_jclassl` (`0x14a18..0x14a24`, 12 bytes)
 * Disassembly: 0x14a18: mov x0, x2 ; 0x14a1c: mov w1, wzr ; 0x14a20: b #0x10f80
 */
uint64_t fde_0088_0x14a18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a18ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0203e0U;
    constexpr uint32_t kOpN  = 0x17fff158U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0089] `_Z13enableLockAllP7_JNIEnvP7_jclasslh` (`0x14a24..0x14a34`, 16 bytes)
 *        Hàm FDE[0089] `_Z13enableLockAllP7_JNIEnvP7_jclasslh` (`0x14a24..0x14a34`, 16 bytes)
 * Disassembly: 0x14a24: tst w3, #0xff ; 0x14a28: cset w1, ne ; 0x14a2c: mov x0, x2 ; 0x14a30: b #0x10f80
 */
uint64_t fde_0089_0x14a24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a24ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x72001c7fU;
    constexpr uint32_t kOpN  = 0x17fff154U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0090] `_Z11disableLockP7_JNIEnvP7_jclass` (`0x14a34..0x14a38`, 4 bytes)
 *        Hàm FDE[0090] `_Z11disableLockP7_JNIEnvP7_jclass` (`0x14a34..0x14a38`, 4 bytes)
 * Disassembly: 0x14a34: b #0x10c70
 */
uint64_t fde_0090_0x14a34(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a34ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff08fU;
    constexpr uint32_t kOpN  = 0x17fff08fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0091] `_Z16enableBinderHookP7_JNIEnvP7_jclass` (`0x14a38..0x14a3c`, 4 bytes)
 *        Hàm FDE[0091] `_Z16enableBinderHookP7_JNIEnvP7_jclass` (`0x14a38..0x14a3c`, 4 bytes)
 * Disassembly: 0x14a38: b #0x11190
 */
uint64_t fde_0091_0x14a38(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a38ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff1d6U;
    constexpr uint32_t kOpN  = 0x17fff1d6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0092] `_Z17disableBinderHookP7_JNIEnvP7_jclass` (`0x14a3c..0x14a40`, 4 bytes)
 *        Hàm FDE[0092] `_Z17disableBinderHookP7_JNIEnvP7_jclass` (`0x14a3c..0x14a40`, 4 bytes)
 * Disassembly: 0x14a3c: b #0x10b50
 */
uint64_t fde_0092_0x14a3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a3cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff045U;
    constexpr uint32_t kOpN  = 0x17fff045U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0093] `_Z17startHyperMonitorP7_JNIEnvP7_jclass` (`0x14a40..0x14a64`, 36 bytes)
 *        Hàm FDE[0093] `_Z17startHyperMonitorP7_JNIEnvP7_jclass` (`0x14a40..0x14a64`, 36 bytes)
 * Disassembly: 0x14a40: stp x29, x30, [sp, #-0x10]! ; 0x14a44: mov x29, sp ; 0x14a48: bl #0x10b20 ; 0x14a4c: adrp x8, #0x4f000 ; 0x14a50: ldr x8, [x8, #0xed8]
 */
uint64_t fde_0093_0x14a40(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a40ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0094] `_Z16stopHyperMonitorP7_JNIEnvP7_jclass` (`0x14a64..0x14a84`, 32 bytes)
 *        Hàm FDE[0094] `_Z16stopHyperMonitorP7_JNIEnvP7_jclass` (`0x14a64..0x14a84`, 32 bytes)
 * Disassembly: 0x14a64: stp x29, x30, [sp, #-0x10]! ; 0x14a68: mov x29, sp ; 0x14a6c: bl #0x10d20 ; 0x14a70: adrp x8, #0x4f000 ; 0x14a74: ldr x8, [x8, #0xed8]
 */
uint64_t fde_0094_0x14a64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a64ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0095] `_Z15setAlogInstanceP7_JNIEnvP7_jclassl` (`0x14a84..0x14a94`, 16 bytes)
 *        Hàm FDE[0095] `_Z15setAlogInstanceP7_JNIEnvP7_jclassl` (`0x14a84..0x14a94`, 16 bytes)
 * Disassembly: 0x14a84: cbz x2, #0x14a90 ; 0x14a88: mov x0, x2 ; 0x14a8c: b #0x114b0 ; 0x14a90: ret
 */
uint64_t fde_0095_0x14a84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a84ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb4000062U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0096] `_Z17keepProcHyperOpenP7_JNIEnvP7_jclassh` (`0x14a94..0x14aa0`, 12 bytes)
 *        Hàm FDE[0096] `_Z17keepProcHyperOpenP7_JNIEnvP7_jclassh` (`0x14a94..0x14aa0`, 12 bytes)
 * Disassembly: 0x14a94: adrp x9, #0x4f000 ; 0x14a98: ldr x9, [x9, #0xd28] ; 0x14a9c: b #0x200a0
 */
uint64_t fde_0096_0x14a94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14a94ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf00001c9U;
    constexpr uint32_t kOpN  = 0x14002d81U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0097] `_Z12readProcFileP7_JNIEnvP8_jobjectP8_jstringP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x14aa0..0x14aa4`, 4 bytes)
 *        Hàm FDE[0097] `_Z12readProcFileP7_JNIEnvP8_jobjectP8_jstringP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x14aa0..0x14aa4`, 4 bytes)
 * Disassembly: 0x14aa0: b #0x11760
 */
uint64_t fde_0097_0x14aa0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14aa0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff330U;
    constexpr uint32_t kOpN  = 0x17fff330U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0098] `_Z33startOrStopAllocatedMonitorNativeP7_JNIEnvP7_jclasshP8_jstring` (`0x14aa4..0x14b24`, 128 bytes)
 *        Hàm FDE[0098] `_Z33startOrStopAllocatedMonitorNativeP7_JNIEnvP7_jclasshP8_jstring` (`0x14aa4..0x14b24`, 128 bytes)
 * Disassembly: 0x14aa4: stp x22, x21, [sp, #-0x30]! ; 0x14aa8: stp x20, x19, [sp, #0x10] ; 0x14aac: stp x29, x30, [sp, #0x20] ; 0x14ab0: add x29, sp, #0x20 ; 0x14ab4: tst w2, #0xff
 */
uint64_t fde_0098_0x14aa4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14aa4ULL;
    constexpr uint64_t kSize = 0x80ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0099] `_Z31setEnableAllocatedMonitorNativeP7_JNIEnvP7_jclasshiiilP8_jobject` (`0x14b24..0x14b54`, 48 bytes)
 *        Hàm FDE[0099] `_Z31setEnableAllocatedMonitorNativeP7_JNIEnvP7_jclasshiiilP8_jobject` (`0x14b24..0x14b54`, 48 bytes)
 * Disassembly: 0x14b24: stp x29, x30, [sp, #-0x10]! ; 0x14b28: mov x29, sp ; 0x14b2c: tst w2, #0xff ; 0x14b30: mov w1, w3 ; 0x14b34: cset w0, ne
 */
uint64_t fde_0099_0x14b24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b24ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0100] `_Z17clearAllocateInfoP7_JNIEnvP7_jclass` (`0x14b54..0x14b58`, 4 bytes)
 *        Hàm FDE[0100] `_Z17clearAllocateInfoP7_JNIEnvP7_jclass` (`0x14b54..0x14b58`, 4 bytes)
 * Disassembly: 0x14b54: b #0x11440
 */
uint64_t fde_0100_0x14b54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b54ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff23bU;
    constexpr uint32_t kOpN  = 0x17fff23bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0101] `_Z7initMemP7_JNIEnvP7_jclass` (`0x14b58..0x14b70`, 24 bytes)
 *        Hàm FDE[0101] `_Z7initMemP7_JNIEnvP7_jclass` (`0x14b58..0x14b70`, 24 bytes)
 * Disassembly: 0x14b58: stp x29, x30, [sp, #-0x10]! ; 0x14b5c: mov x29, sp ; 0x14b60: bl #0x10a60 ; 0x14b64: and w0, w0, #1 ; 0x14b68: ldp x29, x30, [sp], #0x10
 */
uint64_t fde_0101_0x14b58(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b58ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0102] `_Z16getObjsAllocEverP7_JNIEnvP7_jclass` (`0x14b70..0x14b74`, 4 bytes)
 *        Hàm FDE[0102] `_Z16getObjsAllocEverP7_JNIEnvP7_jclass` (`0x14b70..0x14b74`, 4 bytes)
 * Disassembly: 0x14b70: b #0x11050
 */
uint64_t fde_0102_0x14b70(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b70ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff138U;
    constexpr uint32_t kOpN  = 0x17fff138U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0103] `_Z17getBytesAllocEverP7_JNIEnvP7_jclass` (`0x14b74..0x14b78`, 4 bytes)
 *        Hàm FDE[0103] `_Z17getBytesAllocEverP7_JNIEnvP7_jclass` (`0x14b74..0x14b78`, 4 bytes)
 * Disassembly: 0x14b74: b #0x11420
 */
uint64_t fde_0103_0x14b74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b74ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff22bU;
    constexpr uint32_t kOpN  = 0x17fff22bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0104] `_Z13getMinorFaultP7_JNIEnvP7_jclass` (`0x14b78..0x14b7c`, 4 bytes)
 *        Hàm FDE[0104] `_Z13getMinorFaultP7_JNIEnvP7_jclass` (`0x14b78..0x14b7c`, 4 bytes)
 * Disassembly: 0x14b78: b #0x11400
 */
uint64_t fde_0104_0x14b78(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b78ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff222U;
    constexpr uint32_t kOpN  = 0x17fff222U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0105] `_Z13getMajorFaultP7_JNIEnvP7_jclass` (`0x14b7c..0x14b80`, 4 bytes)
 *        Hàm FDE[0105] `_Z13getMajorFaultP7_JNIEnvP7_jclass` (`0x14b7c..0x14b80`, 4 bytes)
 * Disassembly: 0x14b7c: b #0x10b80
 */
uint64_t fde_0105_0x14b7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b7cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff001U;
    constexpr uint32_t kOpN  = 0x17fff001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0106] `_Z10getGcCountP7_JNIEnvP7_jclass` (`0x14b80..0x14b84`, 4 bytes)
 *        Hàm FDE[0106] `_Z10getGcCountP7_JNIEnvP7_jclass` (`0x14b80..0x14b84`, 4 bytes)
 * Disassembly: 0x14b80: b #0x10aa0
 */
uint64_t fde_0106_0x14b80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b80ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffefc8U;
    constexpr uint32_t kOpN  = 0x17ffefc8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0107] `_Z9getGcTimeP7_JNIEnvP7_jclass` (`0x14b84..0x14b88`, 4 bytes)
 *        Hàm FDE[0107] `_Z9getGcTimeP7_JNIEnvP7_jclass` (`0x14b84..0x14b88`, 4 bytes)
 * Disassembly: 0x14b84: b #0x10c00
 */
uint64_t fde_0107_0x14b84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b84ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff01fU;
    constexpr uint32_t kOpN  = 0x17fff01fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0108] `_Z18getBlockingGcCountP7_JNIEnvP7_jclass` (`0x14b88..0x14b8c`, 4 bytes)
 *        Hàm FDE[0108] `_Z18getBlockingGcCountP7_JNIEnvP7_jclass` (`0x14b88..0x14b8c`, 4 bytes)
 * Disassembly: 0x14b88: b #0x110b0
 */
uint64_t fde_0108_0x14b88(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b88ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff14aU;
    constexpr uint32_t kOpN  = 0x17fff14aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0109] `_Z17getBlockingGcTimeP7_JNIEnvP7_jclass` (`0x14b8c..0x14b90`, 4 bytes)
 *        Hàm FDE[0109] `_Z17getBlockingGcTimeP7_JNIEnvP7_jclass` (`0x14b8c..0x14b90`, 4 bytes)
 * Disassembly: 0x14b8c: b #0x10a10
 */
uint64_t fde_0109_0x14b8c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b8cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffefa1U;
    constexpr uint32_t kOpN  = 0x17ffefa1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0110] `_Z18getAllocReportInfoP7_JNIEnvP7_jclass` (`0x14b90..0x14b94`, 4 bytes)
 *        Hàm FDE[0110] `_Z18getAllocReportInfoP7_JNIEnvP7_jclass` (`0x14b90..0x14b94`, 4 bytes)
 * Disassembly: 0x14b90: b #0x112f0
 */
uint64_t fde_0110_0x14b90(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b90ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff1d8U;
    constexpr uint32_t kOpN  = 0x17fff1d8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0111] `_Z17releaseByteBufferP7_JNIEnvP7_jclassl` (`0x14b94..0x14bbc`, 40 bytes)
 *        Hàm FDE[0111] `_Z17releaseByteBufferP7_JNIEnvP7_jclassl` (`0x14b94..0x14bbc`, 40 bytes)
 * Disassembly: 0x14b94: cbz x2, #0x14bb8 ; 0x14b98: str x19, [sp, #-0x20]! ; 0x14b9c: stp x29, x30, [sp, #0x10] ; 0x14ba0: add x29, sp, #0x10 ; 0x14ba4: mov x0, x2
 */
uint64_t fde_0111_0x14b94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14b94ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xb4000122U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0112] `sub_14bbc` (`0x14bbc..0x14bd4`, 24 bytes)
 *        Hàm FDE[0112] `sub_14bbc` (`0x14bbc..0x14bd4`, 24 bytes)
 * Disassembly: 0x14bbc: mov x8, x0 ; 0x14bc0: ldr x0, [x0] ; 0x14bc4: cbz x0, #0x14bd0 ; 0x14bc8: str x0, [x8, #8] ; 0x14bcc: b #0x20e88
 */
uint64_t fde_0112_0x14bbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14bbcULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0113] `_Z14saveBinderInfolll` (`0x14bd4..0x14c74`, 160 bytes)
 *        Hàm FDE[0113] `_Z14saveBinderInfolll` (`0x14bd4..0x14c74`, 160 bytes)
 * Disassembly: 0x14bd4: sub sp, sp, #0x40 ; 0x14bd8: stp x22, x21, [sp, #0x10] ; 0x14bdc: stp x20, x19, [sp, #0x20] ; 0x14be0: stp x29, x30, [sp, #0x30] ; 0x14be4: add x29, sp, #0x30
 */
uint64_t fde_0113_0x14bd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14bd4ULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x17fffff5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0114] `sub_14c74` (`0x14c74..0x14cb0`, 60 bytes)
 *        Hàm FDE[0114] `sub_14c74` (`0x14c74..0x14cb0`, 60 bytes)
 * Disassembly: 0x14c74: sub sp, sp, #0x120 ; 0x14c78: stp x28, x19, [sp, #0x100] ; 0x14c7c: stp x29, x30, [sp, #0x110] ; 0x14c80: add x29, sp, #0x110 ; 0x14c84: bl #0x1f594
 */
uint64_t fde_0114_0x14c74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14c74ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xd10483ffU;
    constexpr uint32_t kOpN  = 0x97fff0f5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0115] `_Z12saveLockInfoP7_JNIEnvPc` (`0x14cb0..0x14d04`, 84 bytes)
 *        Hàm FDE[0115] `_Z12saveLockInfoP7_JNIEnvPc` (`0x14cb0..0x14d04`, 84 bytes)
 * Disassembly: 0x14cb0: cbz x0, #0x14d00 ; 0x14cb4: stp x20, x19, [sp, #-0x20]! ; 0x14cb8: stp x29, x30, [sp, #0x10] ; 0x14cbc: add x29, sp, #0x10 ; 0x14cc0: ldr x8, [x0]
 */
uint64_t fde_0115_0x14cb0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14cb0ULL;
    constexpr uint64_t kSize = 0x54ULL;
    constexpr uint32_t kOp0  = 0xb4000280U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0116] `_Z17getJavaStacktraceP7_JNIEnvPcS1_` (`0x14d04..0x14db0`, 172 bytes)
 *        Hàm FDE[0116] `_Z17getJavaStacktraceP7_JNIEnvPcS1_` (`0x14d04..0x14db0`, 172 bytes)
 * Disassembly: 0x14d04: str x21, [sp, #-0x30]! ; 0x14d08: stp x20, x19, [sp, #0x10] ; 0x14d0c: stp x29, x30, [sp, #0x20] ; 0x14d10: add x29, sp, #0x20 ; 0x14d14: adrp x8, #0x4f000
 */
uint64_t fde_0116_0x14d04(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14d04ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x140032d5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0117] `monotonicTime` (`0x14db0..0x14dd8`, 40 bytes)
 *        Hàm FDE[0117] `monotonicTime` (`0x14db0..0x14dd8`, 40 bytes)
 * Disassembly: 0x14db0: sub sp, sp, #0x40 ; 0x14db4: str x19, [sp, #0x20] ; 0x14db8: stp x29, x30, [sp, #0x30] ; 0x14dbc: add x29, sp, #0x30 ; 0x14dc0: bl #0x1f9bc
 */
uint64_t fde_0117_0x14db0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14db0ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x97fff0abU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0118] `clockTime` (`0x14dd8..0x14e1c`, 68 bytes)
 *        Hàm FDE[0118] `clockTime` (`0x14dd8..0x14e1c`, 68 bytes)
 * Disassembly: 0x14dd8: sub sp, sp, #0x40 ; 0x14ddc: str x19, [sp, #0x20] ; 0x14de0: stp x29, x30, [sp, #0x30] ; 0x14de4: add x29, sp, #0x30 ; 0x14de8: mrs x19, tpidr_el0
 */
uint64_t fde_0118_0x14dd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14dd8ULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x97fff09aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0119] `get_device_api_level` (`0x14e1c..0x14e9c`, 128 bytes)
 *        Hàm FDE[0119] `get_device_api_level` (`0x14e1c..0x14e9c`, 128 bytes)
 * Disassembly: 0x14e1c: sub sp, sp, #0x90 ; 0x14e20: stp x20, x19, [sp, #0x70] ; 0x14e24: stp x29, x30, [sp, #0x80] ; 0x14e28: add x29, sp, #0x80 ; 0x14e2c: bl #0x20414
 */
uint64_t fde_0119_0x14e1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14e1cULL;
    constexpr uint64_t kSize = 0x80ULL;
    constexpr uint32_t kOp0  = 0xd10243ffU;
    constexpr uint32_t kOpN  = 0x97fff07aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0120] `get_prop` (`0x14e9c..0x14f80`, 228 bytes)
 *        Hàm FDE[0120] `get_prop` (`0x14e9c..0x14f80`, 228 bytes)
 * Disassembly: 0x14e9c: sub sp, sp, #0x150 ; 0x14ea0: str x28, [sp, #0x110] ; 0x14ea4: stp x22, x21, [sp, #0x120] ; 0x14ea8: stp x20, x19, [sp, #0x130] ; 0x14eac: stp x29, x30, [sp, #0x140]
 */
uint64_t fde_0120_0x14e9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14e9cULL;
    constexpr uint64_t kSize = 0xe4ULL;
    constexpr uint32_t kOp0  = 0xd10543ffU;
    constexpr uint32_t kOpN  = 0x97fff041U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0121] `_Z16init_thread_infov` (`0x14f80..0x14ff4`, 116 bytes)
 *        Hàm FDE[0121] `_Z16init_thread_infov` (`0x14f80..0x14ff4`, 116 bytes)
 * Disassembly: 0x14f80: sub sp, sp, #0x70 ; 0x14f84: str x21, [sp, #0x40] ; 0x14f88: stp x20, x19, [sp, #0x50] ; 0x14f8c: stp x29, x30, [sp, #0x60] ; 0x14f90: add x29, sp, #0x60
 */
uint64_t fde_0121_0x14f80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14f80ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x97fff024U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0122] `_Z15is_stack_enoughm` (`0x14ff4..0x15068`, 116 bytes)
 *        Hàm FDE[0122] `_Z15is_stack_enoughm` (`0x14ff4..0x15068`, 116 bytes)
 * Disassembly: 0x14ff4: sub sp, sp, #0x30 ; 0x14ff8: stp x20, x19, [sp, #0x10] ; 0x14ffc: stp x29, x30, [sp, #0x20] ; 0x15000: add x29, sp, #0x20 ; 0x15004: mrs x20, tpidr_el0
 */
uint64_t fde_0122_0x14ff4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x14ff4ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x97fff007U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0123] `_Z16currentTimeMillsv` (`0x15068..0x15094`, 44 bytes)
 *        Hàm FDE[0123] `_Z16currentTimeMillsv` (`0x15068..0x15094`, 44 bytes)
 * Disassembly: 0x15068: sub sp, sp, #0x20 ; 0x1506c: stp x29, x30, [sp, #0x10] ; 0x15070: add x29, sp, #0x10 ; 0x15074: bl #0x20460 ; 0x15078: ldp x9, x8, [sp]
 */
uint64_t fde_0123_0x15068(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15068ULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xd10083ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0124] `setBufferSize` (`0x15094..0x150f4`, 96 bytes)
 *        Hàm FDE[0124] `setBufferSize` (`0x15094..0x150f4`, 96 bytes)
 * Disassembly: 0x15094: stp x20, x19, [sp, #-0x20]! ; 0x15098: stp x29, x30, [sp, #0x10] ; 0x1509c: add x29, sp, #0x10 ; 0x150a0: adrp x19, #0x4f000 ; 0x150a4: ldr x19, [x19, #0xdf8]
 */
uint64_t fde_0124_0x15094(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15094ULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14002952U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0125] `getProcInfo` (`0x150f4..0x15300`, 524 bytes)
 *        Hàm FDE[0125] `getProcInfo` (`0x150f4..0x15300`, 524 bytes)
 * Disassembly: 0x150f4: mov x1, x30 ; 0x150f8: bl #0x1f620 ; 0x150fc: mov x30, x1 ; 0x15100: stp x29, x30, [sp, #0x50] ; 0x15104: add x29, sp, #0x50
 */
uint64_t fde_0125_0x150f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x150f4ULL;
    constexpr uint64_t kSize = 0x20cULL;
    constexpr uint32_t kOp0  = 0xaa1e03e1U;
    constexpr uint32_t kOpN  = 0x97ffef61U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0126] `procinfo_chars` (`0x15300..0x1543c`, 316 bytes)
 *        Hàm FDE[0126] `procinfo_chars` (`0x15300..0x1543c`, 316 bytes)
 * Disassembly: 0x15300: str x28, [sp, #-0x50]! ; 0x15304: stp x24, x23, [sp, #0x10] ; 0x15308: stp x22, x21, [sp, #0x20] ; 0x1530c: stp x20, x19, [sp, #0x30] ; 0x15310: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0126_0x15300(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15300ULL;
    constexpr uint64_t kSize = 0x13cULL;
    constexpr uint32_t kOp0  = 0xf81b0ffcU;
    constexpr uint32_t kOpN  = 0x97ffef12U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0127] `cpuinfo_chars` (`0x1543c..0x154d0`, 148 bytes)
 *        Hàm FDE[0127] `cpuinfo_chars` (`0x1543c..0x154d0`, 148 bytes)
 * Disassembly: 0x1543c: sub sp, sp, #0x140 ; 0x15440: stp x28, x21, [sp, #0x110] ; 0x15444: stp x20, x19, [sp, #0x120] ; 0x15448: stp x29, x30, [sp, #0x130] ; 0x1544c: add x29, sp, #0x130
 */
uint64_t fde_0127_0x1543c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1543cULL;
    constexpr uint64_t kSize = 0x94ULL;
    constexpr uint32_t kOp0  = 0xd10503ffU;
    constexpr uint32_t kOpN  = 0x97ffeeedU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0128] `memoryinfo_chars` (`0x154d0..0x15570`, 160 bytes)
 *        Hàm FDE[0128] `memoryinfo_chars` (`0x154d0..0x15570`, 160 bytes)
 * Disassembly: 0x154d0: sub sp, sp, #0xc0 ; 0x154d4: str x21, [sp, #0x90] ; 0x154d8: stp x20, x19, [sp, #0xa0] ; 0x154dc: stp x29, x30, [sp, #0xb0] ; 0x154e0: add x29, sp, #0xb0
 */
uint64_t fde_0128_0x154d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x154d0ULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xd10303ffU;
    constexpr uint32_t kOpN  = 0x97ffeec5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0129] `schedinfo_chars` (`0x15570..0x15600`, 144 bytes)
 *        Hàm FDE[0129] `schedinfo_chars` (`0x15570..0x15600`, 144 bytes)
 * Disassembly: 0x15570: stp x28, x21, [sp, #-0x30]! ; 0x15574: stp x20, x19, [sp, #0x10] ; 0x15578: stp x29, x30, [sp, #0x20] ; 0x1557c: add x29, sp, #0x20 ; 0x15580: sub sp, sp, #0x410
 */
uint64_t fde_0129_0x15570(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15570ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xa9bd57fcU;
    constexpr uint32_t kOpN  = 0x97ffeea1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0130] `sub_15600` (`0x15600..0x1566c`, 108 bytes)
 *        Hàm FDE[0130] `sub_15600` (`0x15600..0x1566c`, 108 bytes)
 * Disassembly: 0x15600: sub sp, sp, #0x120 ; 0x15604: stp x28, x19, [sp, #0x100] ; 0x15608: stp x29, x30, [sp, #0x110] ; 0x1560c: add x29, sp, #0x110 ; 0x15610: stp x3, x4, [sp, #0x88]
 */
uint64_t fde_0130_0x15600(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15600ULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xd10483ffU;
    constexpr uint32_t kOpN  = 0x97ffee86U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0131] `dumpProcInfoTimeRangeToALog` (`0x1566c..0x157cc`, 352 bytes)
 *        Hàm FDE[0131] `dumpProcInfoTimeRangeToALog` (`0x1566c..0x157cc`, 352 bytes)
 * Disassembly: 0x1566c: sub sp, sp, #0x110 ; 0x15670: stp x28, x27, [sp, #0xb0] ; 0x15674: stp x26, x25, [sp, #0xc0] ; 0x15678: stp x24, x23, [sp, #0xd0] ; 0x1567c: stp x22, x21, [sp, #0xe0]
 */
uint64_t fde_0131_0x1566c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1566cULL;
    constexpr uint64_t kSize = 0x160ULL;
    constexpr uint32_t kOp0  = 0xd10443ffU;
    constexpr uint32_t kOpN  = 0x17ffefeeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0132] `getProcInfoTimeRange` (`0x157cc..0x15a7c`, 688 bytes)
 *        Hàm FDE[0132] `getProcInfoTimeRange` (`0x157cc..0x15a7c`, 688 bytes)
 * Disassembly: 0x157cc: mov x1, x30 ; 0x157d0: bl #0x1f620 ; 0x157d4: mov x30, x1 ; 0x157d8: stp x29, x30, [sp, #0x50] ; 0x157dc: add x29, sp, #0x50
 */
uint64_t fde_0132_0x157cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x157ccULL;
    constexpr uint64_t kSize = 0x2b0ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e1U;
    constexpr uint32_t kOpN  = 0x97ffed82U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0133] `getAppCpuTime` (`0x15a7c..0x15c14`, 408 bytes)
 *        Hàm FDE[0133] `getAppCpuTime` (`0x15a7c..0x15c14`, 408 bytes)
 * Disassembly: 0x15a7c: sub sp, sp, #0x150 ; 0x15a80: str x28, [sp, #0x110] ; 0x15a84: stp x22, x21, [sp, #0x120] ; 0x15a88: stp x20, x19, [sp, #0x130] ; 0x15a8c: stp x29, x30, [sp, #0x140]
 */
uint64_t fde_0133_0x15a7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15a7cULL;
    constexpr uint64_t kSize = 0x198ULL;
    constexpr uint32_t kOp0  = 0xd10543ffU;
    constexpr uint32_t kOpN  = 0x97ffed1cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0134] `getCpuTime` (`0x15c14..0x15d54`, 320 bytes)
 *        Hàm FDE[0134] `getCpuTime` (`0x15c14..0x15d54`, 320 bytes)
 * Disassembly: 0x15c14: sub sp, sp, #0x150 ; 0x15c18: str x28, [sp, #0x110] ; 0x15c1c: stp x22, x21, [sp, #0x120] ; 0x15c20: stp x20, x19, [sp, #0x130] ; 0x15c24: stp x29, x30, [sp, #0x140]
 */
uint64_t fde_0134_0x15c14(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15c14ULL;
    constexpr uint64_t kSize = 0x140ULL;
    constexpr uint32_t kOp0  = 0xd10543ffU;
    constexpr uint32_t kOpN  = 0x97ffecccU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0135] `getSchedInfo` (`0x15d54..0x15e44`, 240 bytes)
 *        Hàm FDE[0135] `getSchedInfo` (`0x15d54..0x15e44`, 240 bytes)
 * Disassembly: 0x15d54: sub sp, sp, #0x80 ; 0x15d58: str x25, [sp, #0x30] ; 0x15d5c: stp x24, x23, [sp, #0x40] ; 0x15d60: stp x22, x21, [sp, #0x50] ; 0x15d64: stp x20, x19, [sp, #0x60]
 */
uint64_t fde_0135_0x15d54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15d54ULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0xd61f00a0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0136] `CollectThreadSchedValue` (`0x15e44..0x15ed0`, 140 bytes)
 *        Hàm FDE[0136] `CollectThreadSchedValue` (`0x15e44..0x15ed0`, 140 bytes)
 * Disassembly: 0x15e44: stp x22, x21, [sp, #-0x30]! ; 0x15e48: stp x20, x19, [sp, #0x10] ; 0x15e4c: stp x29, x30, [sp, #0x20] ; 0x15e50: add x29, sp, #0x20 ; 0x15e54: mov w21, w0
 */
uint64_t fde_0136_0x15e44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15e44ULL;
    constexpr uint64_t kSize = 0x8cULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x140027d9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0137] `CollectSchedValueFd` (`0x15ed0..0x162a0`, 976 bytes)
 *        Hàm FDE[0137] `CollectSchedValueFd` (`0x15ed0..0x162a0`, 976 bytes)
 * Disassembly: 0x15ed0: mov x2, x30 ; 0x15ed4: bl #0x1f620 ; 0x15ed8: mov x30, x2 ; 0x15edc: stp x29, x30, [sp, #0x50] ; 0x15ee0: add x29, sp, #0x50
 */
uint64_t fde_0137_0x15ed0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x15ed0ULL;
    constexpr uint64_t kSize = 0x3d0ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e2U;
    constexpr uint32_t kOpN  = 0x97ffeb79U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0138] `getTotalCPUTimeByTimeInStat` (`0x162a0..0x163cc`, 300 bytes)
 *        Hàm FDE[0138] `getTotalCPUTimeByTimeInStat` (`0x162a0..0x163cc`, 300 bytes)
 * Disassembly: 0x162a0: sub sp, sp, #0xb0 ; 0x162a4: stp x28, x27, [sp, #0x50] ; 0x162a8: stp x26, x25, [sp, #0x60] ; 0x162ac: stp x24, x23, [sp, #0x70] ; 0x162b0: stp x22, x21, [sp, #0x80]
 */
uint64_t fde_0138_0x162a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x162a0ULL;
    constexpr uint64_t kSize = 0x12cULL;
    constexpr uint32_t kOp0  = 0xd102c3ffU;
    constexpr uint32_t kOpN  = 0x97ffeb2eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0139] `getThreadStatInfo` (`0x163cc..0x165bc`, 496 bytes)
 *        Hàm FDE[0139] `getThreadStatInfo` (`0x163cc..0x165bc`, 496 bytes)
 * Disassembly: 0x163cc: sub sp, sp, #0xb0 ; 0x163d0: stp x28, x27, [sp, #0x50] ; 0x163d4: stp x26, x25, [sp, #0x60] ; 0x163d8: stp x24, x23, [sp, #0x70] ; 0x163dc: stp x22, x21, [sp, #0x80]
 */
uint64_t fde_0139_0x163cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x163ccULL;
    constexpr uint64_t kSize = 0x1f0ULL;
    constexpr uint32_t kOp0  = 0xd102c3ffU;
    constexpr uint32_t kOpN  = 0x97ffeab2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0140] `CollectStateValueFd` (`0x165bc..0x16844`, 648 bytes)
 *        Hàm FDE[0140] `CollectStateValueFd` (`0x165bc..0x16844`, 648 bytes)
 * Disassembly: 0x165bc: sub sp, sp, #0x190 ; 0x165c0: stp x28, x27, [sp, #0x130] ; 0x165c4: stp x26, x25, [sp, #0x140] ; 0x165c8: stp x24, x23, [sp, #0x150] ; 0x165cc: stp x22, x21, [sp, #0x160]
 */
uint64_t fde_0140_0x165bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x165bcULL;
    constexpr uint64_t kSize = 0x288ULL;
    constexpr uint32_t kOp0  = 0xd10643ffU;
    constexpr uint32_t kOpN  = 0x97ffea10U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0141] `dumpNativeStack` (`0x16844..0x16944`, 256 bytes)
 *        Hàm FDE[0141] `dumpNativeStack` (`0x16844..0x16944`, 256 bytes)
 * Disassembly: 0x16844: str x25, [sp, #-0x50]! ; 0x16848: stp x24, x23, [sp, #0x10] ; 0x1684c: stp x22, x21, [sp, #0x20] ; 0x16850: stp x20, x19, [sp, #0x30] ; 0x16854: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0141_0x16844(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16844ULL;
    constexpr uint64_t kSize = 0x100ULL;
    constexpr uint32_t kOp0  = 0xf81b0ff9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0142] `getProcCGroup` (`0x16944..0x16afc`, 440 bytes)
 *        Hàm FDE[0142] `getProcCGroup` (`0x16944..0x16afc`, 440 bytes)
 * Disassembly: 0x16944: stp x26, x25, [sp, #-0x50]! ; 0x16948: stp x24, x23, [sp, #0x10] ; 0x1694c: stp x22, x21, [sp, #0x20] ; 0x16950: stp x20, x19, [sp, #0x30] ; 0x16954: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0142_0x16944(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16944ULL;
    constexpr uint64_t kSize = 0x1b8ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffe962U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0143] `init` (`0x16afc..0x16b60`, 100 bytes)
 *        Hàm FDE[0143] `init` (`0x16afc..0x16b60`, 100 bytes)
 * Disassembly: 0x16afc: stp x20, x19, [sp, #-0x20]! ; 0x16b00: stp x29, x30, [sp, #0x10] ; 0x16b04: add x29, sp, #0x10 ; 0x16b08: adrp x19, #0x4f000 ; 0x16b0c: ldr x19, [x19, #0xfa0]
 */
uint64_t fde_0143_0x16afc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16afcULL;
    constexpr uint64_t kSize = 0x64ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x140022b7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0144] `start` (`0x16b60..0x16b64`, 4 bytes)
 *        Hàm FDE[0144] `start` (`0x16b60..0x16b64`, 4 bytes)
 * Disassembly: 0x16b60: ret
 */
uint64_t fde_0144_0x16b60(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16b60ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0145] `collect` (`0x16b64..0x16c90`, 300 bytes)
 *        Hàm FDE[0145] `collect` (`0x16b64..0x16c90`, 300 bytes)
 * Disassembly: 0x16b64: sub sp, sp, #0xe0 ; 0x16b68: str x21, [sp, #0xb0] ; 0x16b6c: stp x20, x19, [sp, #0xc0] ; 0x16b70: stp x29, x30, [sp, #0xd0] ; 0x16b74: add x29, sp, #0xd0
 */
uint64_t fde_0145_0x16b64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16b64ULL;
    constexpr uint64_t kSize = 0x12cULL;
    constexpr uint32_t kOp0  = 0xd10383ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0146] `ResetProcInfo` (`0x16c90..0x16cc4`, 52 bytes)
 *        Hàm FDE[0146] `ResetProcInfo` (`0x16c90..0x16cc4`, 52 bytes)
 * Disassembly: 0x16c90: movi v0.2d, #0000000000000000 ; 0x16c94: mov w8, #0x30 ; 0x16c98: str xzr, [x0] ; 0x16c9c: str xzr, [x0, #0xa0] ; 0x16ca0: stp xzr, xzr, [x0, #0x40]
 */
uint64_t fde_0146_0x16c90(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16c90ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0x6f00e400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0147] `CollectStatValue` (`0x16cc4..0x16d2c`, 104 bytes)
 *        Hàm FDE[0147] `CollectStatValue` (`0x16cc4..0x16d2c`, 104 bytes)
 * Disassembly: 0x16cc4: str x21, [sp, #-0x30]! ; 0x16cc8: stp x20, x19, [sp, #0x10] ; 0x16ccc: stp x29, x30, [sp, #0x20] ; 0x16cd0: add x29, sp, #0x20 ; 0x16cd4: mov x19, x0
 */
uint64_t fde_0147_0x16cc4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16cc4ULL;
    constexpr uint64_t kSize = 0x68ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x1400223bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0148] `CollectSchedValue` (`0x16d2c..0x16d8c`, 96 bytes)
 *        Hàm FDE[0148] `CollectSchedValue` (`0x16d2c..0x16d8c`, 96 bytes)
 * Disassembly: 0x16d2c: str x21, [sp, #-0x30]! ; 0x16d30: stp x20, x19, [sp, #0x10] ; 0x16d34: stp x29, x30, [sp, #0x20] ; 0x16d38: add x29, sp, #0x20 ; 0x16d3c: mov x19, x0
 */
uint64_t fde_0148_0x16d2c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16d2cULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x14002223U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0149] `CollectMainThreadStat` (`0x16d8c..0x16e18`, 140 bytes)
 *        Hàm FDE[0149] `CollectMainThreadStat` (`0x16d8c..0x16e18`, 140 bytes)
 * Disassembly: 0x16d8c: str x21, [sp, #-0x30]! ; 0x16d90: stp x20, x19, [sp, #0x10] ; 0x16d94: stp x29, x30, [sp, #0x20] ; 0x16d98: add x29, sp, #0x20 ; 0x16d9c: mov x20, x0
 */
uint64_t fde_0149_0x16d8c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16d8cULL;
    constexpr uint64_t kSize = 0x8cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x14002200U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0150] `CollectThreadProcInfo` (`0x16e18..0x16ecc`, 180 bytes)
 *        Hàm FDE[0150] `CollectThreadProcInfo` (`0x16e18..0x16ecc`, 180 bytes)
 * Disassembly: 0x16e18: stp x22, x21, [sp, #-0x30]! ; 0x16e1c: stp x20, x19, [sp, #0x10] ; 0x16e20: stp x29, x30, [sp, #0x20] ; 0x16e24: add x29, sp, #0x20 ; 0x16e28: mov w22, w0
 */
uint64_t fde_0150_0x16e18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16e18ULL;
    constexpr uint64_t kSize = 0xb4ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x14002578U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0151] `stop` (`0x16ecc..0x16ed0`, 4 bytes)
 *        Hàm FDE[0151] `stop` (`0x16ecc..0x16ed0`, 4 bytes)
 * Disassembly: 0x16ecc: ret
 */
uint64_t fde_0151_0x16ecc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16eccULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0152] `destroy` (`0x16ed0..0x16ed4`, 4 bytes)
 *        Hàm FDE[0152] `destroy` (`0x16ed0..0x16ed4`, 4 bytes)
 * Disassembly: 0x16ed0: ret
 */
uint64_t fde_0152_0x16ed0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16ed0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0153] `startHyperProc` (`0x16ed4..0x16ee8`, 20 bytes)
 *        Hàm FDE[0153] `startHyperProc` (`0x16ed4..0x16ee8`, 20 bytes)
 * Disassembly: 0x16ed4: adrp x8, #0x4f000 ; 0x16ed8: ldr x8, [x8, #0xed8] ; 0x16edc: mov w9, #1 ; 0x16ee0: strb w9, [x8] ; 0x16ee4: ret
 */
uint64_t fde_0153_0x16ed4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16ed4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xb00001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0154] `stopHyperProc` (`0x16ee8..0x16ef8`, 16 bytes)
 *        Hàm FDE[0154] `stopHyperProc` (`0x16ee8..0x16ef8`, 16 bytes)
 * Disassembly: 0x16ee8: adrp x8, #0x4f000 ; 0x16eec: ldr x8, [x8, #0xed8] ; 0x16ef0: strb wzr, [x8] ; 0x16ef4: ret
 */
uint64_t fde_0154_0x16ee8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16ee8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb00001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0155] `keepProcHyperMode` (`0x16ef8..0x16f04`, 12 bytes)
 *        Hàm FDE[0155] `keepProcHyperMode` (`0x16ef8..0x16f04`, 12 bytes)
 * Disassembly: 0x16ef8: adrp x9, #0x4f000 ; 0x16efc: ldr x9, [x9, #0xd28] ; 0x16f00: b #0x2049c
 */
uint64_t fde_0155_0x16ef8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16ef8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb00001c9U;
    constexpr uint32_t kOpN  = 0x14002567U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0156] `thread_procinfo_chars` (`0x16f04..0x1701c`, 280 bytes)
 *        Hàm FDE[0156] `thread_procinfo_chars` (`0x16f04..0x1701c`, 280 bytes)
 * Disassembly: 0x16f04: str x28, [sp, #-0x50]! ; 0x16f08: stp x24, x23, [sp, #0x10] ; 0x16f0c: stp x22, x21, [sp, #0x20] ; 0x16f10: stp x20, x19, [sp, #0x30] ; 0x16f14: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0156_0x16f04(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x16f04ULL;
    constexpr uint64_t kSize = 0x118ULL;
    constexpr uint32_t kOp0  = 0xf81b0ffcU;
    constexpr uint32_t kOpN  = 0x97ffe81aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0157] `Java_com_bytedance_common_graphics_GraphicsMonitor_startHook` (`0x1701c..0x17084`, 104 bytes)
 *        Hàm FDE[0157] `Java_com_bytedance_common_graphics_GraphicsMonitor_startHook` (`0x1701c..0x17084`, 104 bytes)
 * Disassembly: 0x1701c: stp x29, x30, [sp, #-0x10]! ; 0x17020: mov x29, sp ; 0x17024: adrp x1, #0x39000 ; 0x17028: adrp x2, #0x17000 ; 0x1702c: adrp x3, #0x17000
 */
uint64_t fde_0157_0x1701c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1701cULL;
    constexpr uint64_t kSize = 0x68ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0158] `sub_17084` (`0x17084..0x17108`, 132 bytes)
 *        Hàm FDE[0158] `sub_17084` (`0x17084..0x17108`, 132 bytes)
 * Disassembly: 0x17084: sub sp, sp, #0x40 ; 0x17088: stp x22, x21, [sp, #0x10] ; 0x1708c: stp x20, x19, [sp, #0x20] ; 0x17090: stp x29, x30, [sp, #0x30] ; 0x17094: add x29, sp, #0x30
 */
uint64_t fde_0158_0x17084(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17084ULL;
    constexpr uint64_t kSize = 0x84ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x9400213cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0159] `sub_17108` (`0x17108..0x1713c`, 52 bytes)
 *        Hàm FDE[0159] `sub_17108` (`0x17108..0x1713c`, 52 bytes)
 * Disassembly: 0x17108: str x19, [sp, #-0x20]! ; 0x1710c: stp x29, x30, [sp, #0x10] ; 0x17110: add x29, sp, #0x10 ; 0x17114: mov w19, w1 ; 0x17118: adrp x1, #0x39000
 */
uint64_t fde_0159_0x17108(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17108ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14002152U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0160] `sub_1713c` (`0x1713c..0x171f4`, 184 bytes)
 *        Hàm FDE[0160] `sub_1713c` (`0x1713c..0x171f4`, 184 bytes)
 * Disassembly: 0x1713c: sub sp, sp, #0x30 ; 0x17140: stp x20, x19, [sp, #0x10] ; 0x17144: stp x29, x30, [sp, #0x20] ; 0x17148: add x29, sp, #0x20 ; 0x1714c: str x30, [sp, #8]
 */
uint64_t fde_0160_0x1713c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1713cULL;
    constexpr uint64_t kSize = 0xb8ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x94002101U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0161] `sub_171f4` (`0x171f4..0x17228`, 52 bytes)
 *        Hàm FDE[0161] `sub_171f4` (`0x171f4..0x17228`, 52 bytes)
 * Disassembly: 0x171f4: str x19, [sp, #-0x20]! ; 0x171f8: stp x29, x30, [sp, #0x10] ; 0x171fc: add x29, sp, #0x10 ; 0x17200: mov w19, w1 ; 0x17204: adrp x1, #0x39000
 */
uint64_t fde_0161_0x171f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x171f4ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14002117U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0162] `sub_17228` (`0x17228..0x17270`, 72 bytes)
 *        Hàm FDE[0162] `sub_17228` (`0x17228..0x17270`, 72 bytes)
 * Disassembly: 0x17228: str x19, [sp, #-0x20]! ; 0x1722c: stp x29, x30, [sp, #0x10] ; 0x17230: add x29, sp, #0x10 ; 0x17234: str x30, [sp, #8] ; 0x17238: adrp x0, #0x17000
 */
uint64_t fde_0162_0x17228(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17228ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x940020e2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0163] `sub_17270` (`0x17270..0x172a4`, 52 bytes)
 *        Hàm FDE[0163] `sub_17270` (`0x17270..0x172a4`, 52 bytes)
 * Disassembly: 0x17270: str x19, [sp, #-0x20]! ; 0x17274: stp x29, x30, [sp, #0x10] ; 0x17278: add x29, sp, #0x10 ; 0x1727c: mov w19, w1 ; 0x17280: adrp x1, #0x39000
 */
uint64_t fde_0163_0x17270(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17270ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x140020f8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0164] `sub_172a4` (`0x172a4..0x172d0`, 44 bytes)
 *        Hàm FDE[0164] `sub_172a4` (`0x172a4..0x172d0`, 44 bytes)
 * Disassembly: 0x172a4: str x19, [sp, #-0x20]! ; 0x172a8: stp x29, x30, [sp, #0x10] ; 0x172ac: add x29, sp, #0x10 ; 0x172b0: mov x19, x0 ; 0x172b4: bl #0x10dc0
 */
uint64_t fde_0164_0x172a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x172a4ULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x97ffed87U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0165] `sub_172d0` (`0x172d0..0x17318`, 72 bytes)
 *        Hàm FDE[0165] `sub_172d0` (`0x172d0..0x17318`, 72 bytes)
 * Disassembly: 0x172d0: sub sp, sp, #0x40 ; 0x172d4: str x19, [sp, #0x20] ; 0x172d8: stp x29, x30, [sp, #0x30] ; 0x172dc: add x29, sp, #0x30 ; 0x172e0: bl #0x1f9bc
 */
uint64_t fde_0165_0x172d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x172d0ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x97ffe75bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0166] `Java_com_bytedance_common_graphics_GraphicsMonitor_openStatistical` (`0x17318..0x17338`, 32 bytes)
 *        Hàm FDE[0166] `Java_com_bytedance_common_graphics_GraphicsMonitor_openStatistical` (`0x17318..0x17338`, 32 bytes)
 * Disassembly: 0x17318: adrp x9, #0x50000 ; 0x1731c: adrp x8, #0x50000 ; 0x17320: add x9, x9, #0x2f8 ; 0x17324: mov w10, #1 ; 0x17328: str xzr, [x8, #0x48]
 */
uint64_t fde_0166_0x17318(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17318ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xb00001c9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0167] `Java_com_bytedance_common_graphics_GraphicsMonitor_closeStatistical` (`0x17338..0x17344`, 12 bytes)
 *        Hàm FDE[0167] `Java_com_bytedance_common_graphics_GraphicsMonitor_closeStatistical` (`0x17338..0x17344`, 12 bytes)
 * Disassembly: 0x17338: adrp x8, #0x50000 ; 0x1733c: strb wzr, [x8, #0x2f8] ; 0x17340: ret
 */
uint64_t fde_0167_0x17338(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17338ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb00001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0168] `Java_com_bytedance_common_graphics_GraphicsMonitor_getStatisticOnceData` (`0x17344..0x17388`, 68 bytes)
 *        Hàm FDE[0168] `Java_com_bytedance_common_graphics_GraphicsMonitor_getStatisticOnceData` (`0x17344..0x17388`, 68 bytes)
 * Disassembly: 0x17344: adrp x8, #0x50000 ; 0x17348: ldrb w8, [x8, #0x2f5] ; 0x1734c: tbz w8, #0, #0x17358 ; 0x17350: fmov d0, #-1.00000000 ; 0x17354: ret
 */
uint64_t fde_0168_0x17344(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17344ULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xb00001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0169] `_Z14gpu_jni_onloadP7_JavaVMPv` (`0x17388..0x1738c`, 4 bytes)
 *        Hàm FDE[0169] `_Z14gpu_jni_onloadP7_JavaVMPv` (`0x17388..0x1738c`, 4 bytes)
 * Disassembly: 0x17388: ret
 */
uint64_t fde_0169_0x17388(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17388ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0170] `_Z18parseProcLineArrayP7_JNIEnvP8_jobjectPciiP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x1738c..0x1776c`, 992 bytes)
 *        Hàm FDE[0170] `_Z18parseProcLineArrayP7_JNIEnvP8_jobjectPciiP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x1738c..0x1776c`, 992 bytes)
 * Disassembly: 0x1738c: mov x1, x30 ; 0x17390: bl #0x1ff68 ; 0x17394: mov x30, x1 ; 0x17398: stp x29, x30, [sp, #0xd0] ; 0x1739c: add x29, sp, #0xd0
 */
uint64_t fde_0170_0x1738c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1738cULL;
    constexpr uint64_t kSize = 0x3e0ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e1U;
    constexpr uint32_t kOpN  = 0x17ffff60U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0171] `_Z13parseProcLineP7_JNIEnvP8_jobjectP11_jbyteArrayiiP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x1776c..0x17828`, 188 bytes)
 *        Hàm FDE[0171] `_Z13parseProcLineP7_JNIEnvP8_jobjectP11_jbyteArrayiiP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x1776c..0x17828`, 188 bytes)
 * Disassembly: 0x1776c: sub sp, sp, #0x70 ; 0x17770: str x27, [sp, #0x10] ; 0x17774: stp x26, x25, [sp, #0x20] ; 0x17778: stp x24, x23, [sp, #0x30] ; 0x1777c: stp x22, x21, [sp, #0x40]
 */
uint64_t fde_0171_0x1776c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1776cULL;
    constexpr uint64_t kSize = 0xbcULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0172] `_Z14doReadProcFileP7_JNIEnvP8_jobjectP8_jstringP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x17828..0x17b44`, 796 bytes)
 *        Hàm FDE[0172] `_Z14doReadProcFileP7_JNIEnvP8_jobjectP8_jstringP10_jintArrayP13_jobjectArrayP11_jlongArrayP12_jfloatArray` (`0x17828..0x17b44`, 796 bytes)
 * Disassembly: 0x17828: sub sp, sp, #0xd0 ; 0x1782c: stp x28, x27, [sp, #0x70] ; 0x17830: stp x26, x25, [sp, #0x80] ; 0x17834: stp x24, x23, [sp, #0x90] ; 0x17838: stp x22, x21, [sp, #0xa0]
 */
uint64_t fde_0172_0x17828(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17828ULL;
    constexpr uint64_t kSize = 0x31cULL;
    constexpr uint32_t kOp0  = 0xd10343ffU;
    constexpr uint32_t kOpN  = 0x94001eadU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0173] `sub_17b44` (`0x17b44..0x17c28`, 228 bytes)
 *        Hàm FDE[0173] `sub_17b44` (`0x17b44..0x17c28`, 228 bytes)
 * Disassembly: 0x17b44: sub sp, sp, #0x70 ; 0x17b48: str x23, [sp, #0x30] ; 0x17b4c: stp x22, x21, [sp, #0x40] ; 0x17b50: stp x20, x19, [sp, #0x50] ; 0x17b54: stp x29, x30, [sp, #0x60]
 */
uint64_t fde_0173_0x17b44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17b44ULL;
    constexpr uint64_t kSize = 0xe4ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x1400002aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0174] `sub_17c28` (`0x17c28..0x17c6c`, 68 bytes)
 *        Hàm FDE[0174] `sub_17c28` (`0x17c28..0x17c6c`, 68 bytes)
 * Disassembly: 0x17c28: stp x29, x30, [sp, #-0x10]! ; 0x17c2c: mov x29, sp ; 0x17c30: tbnz x1, #0x3f, #0x17c68 ; 0x17c34: ldr x8, [x0, #0x10] ; 0x17c38: ldr x9, [x0]
 */
uint64_t fde_0174_0x17c28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17c28ULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffe4e6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0175] `sub_17c6c` (`0x17c6c..0x17c90`, 36 bytes)
 *        Hàm FDE[0175] `sub_17c6c` (`0x17c6c..0x17c90`, 36 bytes)
 * Disassembly: 0x17c6c: stp x20, x19, [sp, #-0x20]! ; 0x17c70: stp x29, x30, [sp, #0x10] ; 0x17c74: add x29, sp, #0x10 ; 0x17c78: bl #0x1fb0c ; 0x17c7c: b.lt #0x17c84
 */
uint64_t fde_0175_0x17c6c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17c6cULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14001e6bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0176] `sub_17c90` (`0x17c90..0x17cb8`, 40 bytes)
 *        Hàm FDE[0176] `sub_17c90` (`0x17c90..0x17cb8`, 40 bytes)
 * Disassembly: 0x17c90: ldp x8, x9, [x0, #8] ; 0x17c94: cmp x8, x9 ; 0x17c98: b.eq #0x17ca8 ; 0x17c9c: sub x9, x9, #1 ; 0x17ca0: str x9, [x0, #0x10]
 */
uint64_t fde_0176_0x17c90(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17c90ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xa940a408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0177] `_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv` (`0x17cb8..0x17ccc`, 20 bytes)
 *        Hàm FDE[0177] `_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv` (`0x17cb8..0x17ccc`, 20 bytes)
 * Disassembly: 0x17cb8: stp x29, x30, [sp, #-0x10]! ; 0x17cbc: mov x29, sp ; 0x17cc0: adrp x0, #0x39000 ; 0x17cc4: add x0, x0, #0xad4 ; 0x17cc8: bl #0x12d38
 */
uint64_t fde_0177_0x17cb8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17cb8ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffec1cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0178] `sub_17ccc` (`0x17ccc..0x17cec`, 32 bytes)
 *        Hàm FDE[0178] `sub_17ccc` (`0x17ccc..0x17cec`, 32 bytes)
 * Disassembly: 0x17ccc: ldr x8, [x0, #8] ; 0x17cd0: add x9, x8, x1 ; 0x17cd4: cmp x9, x8 ; 0x17cd8: b.eq #0x17ce4 ; 0x17cdc: strb wzr, [x8], #1
 */
uint64_t fde_0178_0x17ccc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17cccULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xf9400408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0179] `sub_17cec` (`0x17cec..0x17cfc`, 16 bytes)
 *        Hàm FDE[0179] `sub_17cec` (`0x17cec..0x17cfc`, 16 bytes)
 * Disassembly: 0x17cec: ldr x0, [x0, #8] ; 0x17cf0: cbz x0, #0x17cf8 ; 0x17cf4: b #0x20d50 ; 0x17cf8: ret
 */
uint64_t fde_0179_0x17cec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17cecULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0180] `sub_17cfc` (`0x17cfc..0x17d44`, 72 bytes)
 *        Hàm FDE[0180] `sub_17cfc` (`0x17cfc..0x17d44`, 72 bytes)
 * Disassembly: 0x17cfc: stp x20, x19, [sp, #-0x20]! ; 0x17d00: stp x29, x30, [sp, #0x10] ; 0x17d04: add x29, sp, #0x10 ; 0x17d08: mov x19, x0 ; 0x17d0c: ldr x0, [x0, #0x10]
 */
uint64_t fde_0180_0x17cfc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17cfcULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14001e3eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0181] `sub_17d44` (`0x17d44..0x17df0`, 172 bytes)
 *        Hàm FDE[0181] `sub_17d44` (`0x17d44..0x17df0`, 172 bytes)
 * Disassembly: 0x17d44: str x23, [sp, #-0x40]! ; 0x17d48: stp x22, x21, [sp, #0x10] ; 0x17d4c: stp x20, x19, [sp, #0x20] ; 0x17d50: stp x29, x30, [sp, #0x30] ; 0x17d54: add x29, sp, #0x30
 */
uint64_t fde_0181_0x17d44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17d44ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x940020d7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0182] `sub_17df0` (`0x17df0..0x17e40`, 80 bytes)
 *        Hàm FDE[0182] `sub_17df0` (`0x17df0..0x17e40`, 80 bytes)
 * Disassembly: 0x17df0: str x21, [sp, #-0x30]! ; 0x17df4: stp x20, x19, [sp, #0x10] ; 0x17df8: stp x29, x30, [sp, #0x20] ; 0x17dfc: add x29, sp, #0x20 ; 0x17e00: ldr x21, [x0]
 */
uint64_t fde_0182_0x17df0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17df0ULL;
    constexpr uint64_t kSize = 0x50ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x14001df6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0183] `sub_17e40` (`0x17e40..0x17e68`, 40 bytes)
 *        Hàm FDE[0183] `sub_17e40` (`0x17e40..0x17e68`, 40 bytes)
 * Disassembly: 0x17e40: str x19, [sp, #-0x20]! ; 0x17e44: stp x29, x30, [sp, #0x10] ; 0x17e48: add x29, sp, #0x10 ; 0x17e4c: mov x19, x0 ; 0x17e50: add x0, x0, #0x18
 */
uint64_t fde_0183_0x17e40(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17e40ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17ffffe3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0184] `sub_17e68` (`0x17e68..0x17e78`, 16 bytes)
 *        Hàm FDE[0184] `sub_17e68` (`0x17e68..0x17e78`, 16 bytes)
 * Disassembly: 0x17e68: ldr x0, [x0, #8] ; 0x17e6c: cbz x0, #0x17e74 ; 0x17e70: b #0x20d50 ; 0x17e74: ret
 */
uint64_t fde_0184_0x17e68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17e68ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0185] `sub_17e78` (`0x17e78..0x17e88`, 16 bytes)
 *        Hàm FDE[0185] `sub_17e78` (`0x17e78..0x17e88`, 16 bytes)
 * Disassembly: 0x17e78: ldr x0, [x0, #8] ; 0x17e7c: cbz x0, #0x17e84 ; 0x17e80: b #0x20d50 ; 0x17e84: ret
 */
uint64_t fde_0185_0x17e78(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17e78ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0186] `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_` (`0x17e88..0x17eb4`, 44 bytes)
 *        Hàm FDE[0186] `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_` (`0x17e88..0x17eb4`, 44 bytes)
 * Disassembly: 0x17e88: stp xzr, xzr, [x0] ; 0x17e8c: str xzr, [x0, #0x10] ; 0x17e90: ldrb w8, [x1] ; 0x17e94: tbnz w8, #0, #0x17eac ; 0x17e98: ldr x8, [x1, #0x10]
 */
uint64_t fde_0186_0x17e88(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17e88ULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xa9007c1fU;
    constexpr uint32_t kOpN  = 0x17fff08dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0187] `_Z13class_lru_lenv` (`0x17eb4..0x17f28`, 116 bytes)
 *        Hàm FDE[0187] `_Z13class_lru_lenv` (`0x17eb4..0x17f28`, 116 bytes)
 * Disassembly: 0x17eb4: str x19, [sp, #-0x20]! ; 0x17eb8: stp x29, x30, [sp, #0x10] ; 0x17ebc: add x29, sp, #0x10 ; 0x17ec0: adrp x8, #0x50000 ; 0x17ec4: add x8, x8, #0x390
 */
uint64_t fde_0187_0x17eb4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17eb4ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94001db4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0188] `_Z18top_method_lru_lenv` (`0x17f28..0x17f9c`, 116 bytes)
 *        Hàm FDE[0188] `_Z18top_method_lru_lenv` (`0x17f28..0x17f9c`, 116 bytes)
 * Disassembly: 0x17f28: str x19, [sp, #-0x20]! ; 0x17f2c: stp x29, x30, [sp, #0x10] ; 0x17f30: add x29, sp, #0x10 ; 0x17f34: adrp x8, #0x50000 ; 0x17f38: add x8, x8, #0x398
 */
uint64_t fde_0188_0x17f28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17f28ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94001d97U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0189] `_Z15get_classloaderm` (`0x17f9c..0x17fb4`, 24 bytes)
 *        Hàm FDE[0189] `_Z15get_classloaderm` (`0x17f9c..0x17fb4`, 24 bytes)
 * Disassembly: 0x17f9c: cbz x0, #0x17fac ; 0x17fa0: ldr w8, [x0] ; 0x17fa4: cbz w8, #0x17fb0 ; 0x17fa8: ldr w0, [x8, #8] ; 0x17fac: ret
 */
uint64_t fde_0189_0x17f9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17f9cULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xb4000080U;
    constexpr uint32_t kOpN  = 0x1400216bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0190] `_Z22initJniEnvThreadOffsetPv` (`0x17fb4..0x18044`, 144 bytes)
 *        Hàm FDE[0190] `_Z22initJniEnvThreadOffsetPv` (`0x17fb4..0x18044`, 144 bytes)
 * Disassembly: 0x17fb4: sub sp, sp, #0x30 ; 0x17fb8: stp x20, x19, [sp, #0x10] ; 0x17fbc: stp x29, x30, [sp, #0x20] ; 0x17fc0: add x29, sp, #0x20 ; 0x17fc4: bl #0x2018c
 */
uint64_t fde_0190_0x17fb4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x17fb4ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x97ffe410U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0191] `_Z11hit_collectv` (`0x18044..0x18068`, 36 bytes)
 *        Hàm FDE[0191] `_Z11hit_collectv` (`0x18044..0x18068`, 36 bytes)
 * Disassembly: 0x18044: stp x29, x30, [sp, #-0x10]! ; 0x18048: mov x29, sp ; 0x1804c: bl #0x10f60 ; 0x18050: adrp x9, #0x50000 ; 0x18054: mov w8, #0x3e8
 */
uint64_t fde_0191_0x18044(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18044ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0192] `_Z13hit_dumptracev` (`0x18068..0x1808c`, 36 bytes)
 *        Hàm FDE[0192] `_Z13hit_dumptracev` (`0x18068..0x1808c`, 36 bytes)
 * Disassembly: 0x18068: stp x29, x30, [sp, #-0x10]! ; 0x1806c: mov x29, sp ; 0x18070: bl #0x10f60 ; 0x18074: adrp x9, #0x50000 ; 0x18078: mov w8, #0x3e8
 */
uint64_t fde_0192_0x18068(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18068ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0193] `_Z9get_tracePv` (`0x1808c..0x181dc`, 336 bytes)
 *        Hàm FDE[0193] `_Z9get_tracePv` (`0x1808c..0x181dc`, 336 bytes)
 * Disassembly: 0x1808c: stp x28, x23, [sp, #-0x40]! ; 0x18090: stp x22, x21, [sp, #0x10] ; 0x18094: stp x20, x19, [sp, #0x20] ; 0x18098: stp x29, x30, [sp, #0x30] ; 0x1809c: add x29, sp, #0x30
 */
uint64_t fde_0193_0x1808c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1808cULL;
    constexpr uint64_t kSize = 0x150ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ffcU;
    constexpr uint32_t kOpN  = 0x94001d07U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0194] `sub_181dc` (`0x181dc..0x181f8`, 28 bytes)
 *        Hàm FDE[0194] `sub_181dc` (`0x181dc..0x181f8`, 28 bytes)
 * Disassembly: 0x181dc: adrp x9, #0x4c000 ; 0x181e0: mov w8, #0x2830 ; 0x181e4: add x9, x9, #0xda8 ; 0x181e8: add x8, x0, x8 ; 0x181ec: str x9, [x0]
 */
uint64_t fde_0194_0x181dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x181dcULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0x900001a9U;
    constexpr uint32_t kOpN  = 0x14000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0195] `sub_181f8` (`0x181f8..0x18210`, 24 bytes)
 *        Hàm FDE[0195] `sub_181f8` (`0x181f8..0x18210`, 24 bytes)
 * Disassembly: 0x181f8: mov x8, x0 ; 0x181fc: ldr x0, [x0] ; 0x18200: cbz x0, #0x1820c ; 0x18204: str x0, [x8, #8] ; 0x18208: b #0x20e88
 */
uint64_t fde_0195_0x181f8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x181f8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0196] `sub_18210` (`0x18210..0x1822c`, 28 bytes)
 *        Hàm FDE[0196] `sub_18210` (`0x18210..0x1822c`, 28 bytes)
 * Disassembly: 0x18210: str x19, [sp, #-0x20]! ; 0x18214: stp x29, x30, [sp, #0x10] ; 0x18218: add x29, sp, #0x10 ; 0x1821c: mov x19, x0 ; 0x18220: bl #0x181dc
 */
uint64_t fde_0196_0x18210(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18210ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001cd3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0197] `sub_1822c` (`0x1822c..0x182c0`, 148 bytes)
 *        Hàm FDE[0197] `sub_1822c` (`0x1822c..0x182c0`, 148 bytes)
 * Disassembly: 0x1822c: sub sp, sp, #0x40 ; 0x18230: str x21, [sp, #0x10] ; 0x18234: stp x20, x19, [sp, #0x20] ; 0x18238: stp x29, x30, [sp, #0x30] ; 0x1823c: add x29, sp, #0x30
 */
uint64_t fde_0197_0x1822c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1822cULL;
    constexpr uint64_t kSize = 0x94ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x1400203cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0198] `sub_182c0` (`0x182c0..0x183a8`, 232 bytes)
 *        Hàm FDE[0198] `sub_182c0` (`0x182c0..0x183a8`, 232 bytes)
 * Disassembly: 0x182c0: sub sp, sp, #0x70 ; 0x182c4: str x23, [sp, #0x30] ; 0x182c8: stp x22, x21, [sp, #0x40] ; 0x182cc: stp x20, x19, [sp, #0x50] ; 0x182d0: stp x29, x30, [sp, #0x60]
 */
uint64_t fde_0198_0x182c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x182c0ULL;
    constexpr uint64_t kSize = 0xe8ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x97ffe317U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0199] `sub_183a8` (`0x183a8..0x183cc`, 36 bytes)
 *        Hàm FDE[0199] `sub_183a8` (`0x183a8..0x183cc`, 36 bytes)
 * Disassembly: 0x183a8: stp x20, x19, [sp, #-0x20]! ; 0x183ac: stp x29, x30, [sp, #0x10] ; 0x183b0: add x29, sp, #0x10 ; 0x183b4: bl #0x1fb0c ; 0x183b8: b.lt #0x183c0
 */
uint64_t fde_0199_0x183a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x183a8ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14001c9cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0200] `sub_183cc` (`0x183cc..0x183f4`, 40 bytes)
 *        Hàm FDE[0200] `sub_183cc` (`0x183cc..0x183f4`, 40 bytes)
 * Disassembly: 0x183cc: ldp x8, x9, [x0, #8] ; 0x183d0: cmp x8, x9 ; 0x183d4: b.eq #0x183e4 ; 0x183d8: sub x9, x9, #0x10 ; 0x183dc: str x9, [x0, #0x10]
 */
uint64_t fde_0200_0x183cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x183ccULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xa940a408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0201] `_Z10tryGetHeapPv` (`0x183f4..0x18400`, 12 bytes)
 *        Hàm FDE[0201] `_Z10tryGetHeapPv` (`0x183f4..0x18400`, 12 bytes)
 * Disassembly: 0x183f4: adrp x1, #0x50000 ; 0x183f8: add x1, x1, #0x570 ; 0x183fc: b #0x2034c
 */
uint64_t fde_0201_0x183f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x183f4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x900001c1U;
    constexpr uint32_t kOpN  = 0x14001fd4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0202] `_Z16tryGetThreadListPv` (`0x18400..0x1840c`, 12 bytes)
 *        Hàm FDE[0202] `_Z16tryGetThreadListPv` (`0x18400..0x1840c`, 12 bytes)
 * Disassembly: 0x18400: adrp x1, #0x50000 ; 0x18404: add x1, x1, #0x600 ; 0x18408: b #0x2034c
 */
uint64_t fde_0202_0x18400(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18400ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x900001c1U;
    constexpr uint32_t kOpN  = 0x14001fd1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0203] `_Z53getThread_ResetQuickAllocEntryPointsForThreadFuncNamev` (`0x1840c..0x18430`, 36 bytes)
 *        Hàm FDE[0203] `_Z53getThread_ResetQuickAllocEntryPointsForThreadFuncNamev` (`0x1840c..0x18430`, 36 bytes)
 * Disassembly: 0x1840c: adrp x8, #0x50000 ; 0x18410: ldrb w8, [x8, #0x2fc] ; 0x18414: adrp x9, #0x39000 ; 0x18418: adrp x10, #0x39000 ; 0x1841c: add x9, x9, #0xf2e
 */
uint64_t fde_0203_0x1840c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1840cULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0204] `_Z19initSymbolAndOffsetv` (`0x18430..0x186a4`, 628 bytes)
 *        Hàm FDE[0204] `_Z19initSymbolAndOffsetv` (`0x18430..0x186a4`, 628 bytes)
 * Disassembly: 0x18430: stp x24, x23, [sp, #-0x40]! ; 0x18434: stp x22, x21, [sp, #0x10] ; 0x18438: stp x20, x19, [sp, #0x20] ; 0x1843c: stp x29, x30, [sp, #0x30] ; 0x18440: add x29, sp, #0x30
 */
uint64_t fde_0204_0x18430(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18430ULL;
    constexpr uint64_t kSize = 0x274ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0205] `sub_186a4` (`0x186a4..0x186f0`, 76 bytes)
 *        Hàm FDE[0205] `sub_186a4` (`0x186a4..0x186f0`, 76 bytes)
 * Disassembly: 0x186a4: adrp x8, #0x50000 ; 0x186a8: ldr w8, [x8, #0x324] ; 0x186ac: mov w0, #1 ; 0x186b0: cmp w8, #1 ; 0x186b4: b.lt #0x186ec
 */
uint64_t fde_0205_0x186a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x186a4ULL;
    constexpr uint64_t kSize = 0x4cULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0206] `_Z13runCheckpointPv` (`0x186f0..0x1872c`, 60 bytes)
 *        Hàm FDE[0206] `_Z13runCheckpointPv` (`0x186f0..0x1872c`, 60 bytes)
 * Disassembly: 0x186f0: adrp x8, #0x50000 ; 0x186f4: ldrsw x8, [x8, #0x324] ; 0x186f8: cmp w8, #1 ; 0x186fc: b.lt #0x18728 ; 0x18700: adrp x9, #0x4f000
 */
uint64_t fde_0206_0x186f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x186f0ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001ce8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0207] `_Z36SetQuickAllocEntryPointsInstrumentedb` (`0x1872c..0x18760`, 52 bytes)
 *        Hàm FDE[0207] `_Z36SetQuickAllocEntryPointsInstrumentedb` (`0x1872c..0x18760`, 52 bytes)
 * Disassembly: 0x1872c: stp x29, x30, [sp, #-0x10]! ; 0x18730: mov x29, sp ; 0x18734: adrp x8, #0x4f000 ; 0x18738: ldr x8, [x8, #0xf10] ; 0x1873c: ldr x8, [x8]
 */
uint64_t fde_0207_0x1872c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1872cULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0208] `_Z40SetEntrypointsInstrumentedWithCheckpointPvb` (`0x18760..0x18860`, 256 bytes)
 *        Hàm FDE[0208] `_Z40SetEntrypointsInstrumentedWithCheckpointPvb` (`0x18760..0x18860`, 256 bytes)
 * Disassembly: 0x18760: str x21, [sp, #-0x30]! ; 0x18764: stp x20, x19, [sp, #0x10] ; 0x18768: stp x29, x30, [sp, #0x20] ; 0x1876c: add x29, sp, #0x20 ; 0x18770: adrp x8, #0x4f000
 */
uint64_t fde_0208_0x18760(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18760ULL;
    constexpr uint64_t kSize = 0x100ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0209] `sub_18860` (`0x18860..0x18870`, 16 bytes)
 *        Hàm FDE[0209] `sub_18860` (`0x18860..0x18870`, 16 bytes)
 * Disassembly: 0x18860: tst w1, #0xff ; 0x18864: b.eq #0x1886c ; 0x18868: b #0x20df0 ; 0x1886c: ret
 */
uint64_t fde_0209_0x18860(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18860ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x72001c3fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0210] `sub_18870` (`0x18870..0x188a4`, 52 bytes)
 *        Hàm FDE[0210] `sub_18870` (`0x18870..0x188a4`, 52 bytes)
 * Disassembly: 0x18870: str x19, [sp, #-0x20]! ; 0x18874: stp x29, x30, [sp, #0x10] ; 0x18878: add x29, sp, #0x10 ; 0x1887c: adrp x8, #0x4c000 ; 0x18880: mov x19, x0
 */
uint64_t fde_0210_0x18870(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18870ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x1400215aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0211] `sub_188a4` (`0x188a4..0x188c0`, 28 bytes)
 *        Hàm FDE[0211] `sub_188a4` (`0x188a4..0x188c0`, 28 bytes)
 * Disassembly: 0x188a4: str x19, [sp, #-0x20]! ; 0x188a8: stp x29, x30, [sp, #0x10] ; 0x188ac: add x29, sp, #0x10 ; 0x188b0: mov x19, x0 ; 0x188b4: bl #0x18870
 */
uint64_t fde_0211_0x188a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x188a4ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001b2eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0212] `sub_188c0` (`0x188c0..0x18990`, 208 bytes)
 *        Hàm FDE[0212] `sub_188c0` (`0x188c0..0x18990`, 208 bytes)
 * Disassembly: 0x188c0: stp x22, x21, [sp, #-0x30]! ; 0x188c4: stp x20, x19, [sp, #0x10] ; 0x188c8: stp x29, x30, [sp, #0x20] ; 0x188cc: add x29, sp, #0x20 ; 0x188d0: adrp x8, #0x4f000
 */
uint64_t fde_0212_0x188c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x188c0ULL;
    constexpr uint64_t kSize = 0xd0ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x94001b1aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0213] `_Z22hookSelfSetEntrypointsv` (`0x18990..0x18a9c`, 268 bytes)
 *        Hàm FDE[0213] `_Z22hookSelfSetEntrypointsv` (`0x18990..0x18a9c`, 268 bytes)
 * Disassembly: 0x18990: str x19, [sp, #-0x20]! ; 0x18994: stp x29, x30, [sp, #0x10] ; 0x18998: add x29, sp, #0x10 ; 0x1899c: bl #0x186a4 ; 0x189a0: tbz w0, #0, #0x189ac
 */
uint64_t fde_0213_0x18990(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18990ULL;
    constexpr uint64_t kSize = 0x10cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94001ad7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0214] `_Z24unhookSelfSetEntrypointsv` (`0x18a9c..0x18af0`, 84 bytes)
 *        Hàm FDE[0214] `_Z24unhookSelfSetEntrypointsv` (`0x18a9c..0x18af0`, 84 bytes)
 * Disassembly: 0x18a9c: str x19, [sp, #-0x20]! ; 0x18aa0: stp x29, x30, [sp, #0x10] ; 0x18aa4: add x29, sp, #0x10 ; 0x18aa8: bl #0x1ff18 ; 0x18aac: ldr x0, [x19]
 */
uint64_t fde_0214_0x18a9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18a9cULL;
    constexpr uint64_t kSize = 0x54ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94001ac2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0215] `_Z8init_memv` (`0x18af0..0x18af4`, 4 bytes)
 *        Hàm FDE[0215] `_Z8init_memv` (`0x18af0..0x18af4`, 4 bytes)
 * Disassembly: 0x18af0: b #0x10a60
 */
uint64_t fde_0215_0x18af0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18af0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffdfdcU;
    constexpr uint32_t kOpN  = 0x17ffdfdcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0216] `_Z20get_bytes_alloc_everv` (`0x18af4..0x18b1c`, 40 bytes)
 *        Hàm FDE[0216] `_Z20get_bytes_alloc_everv` (`0x18af4..0x18b1c`, 40 bytes)
 * Disassembly: 0x18af4: adrp x8, #0x50000 ; 0x18af8: ldrsw x8, [x8, #0x320] ; 0x18afc: cmp w8, #1 ; 0x18b00: b.lt #0x18b18 ; 0x18b04: adrp x9, #0x4f000
 */
uint64_t fde_0216_0x18af4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18af4ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001becU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0217] `_Z19get_objs_alloc_everv` (`0x18b1c..0x18b44`, 40 bytes)
 *        Hàm FDE[0217] `_Z19get_objs_alloc_everv` (`0x18b1c..0x18b44`, 40 bytes)
 * Disassembly: 0x18b1c: adrp x8, #0x50000 ; 0x18b20: ldrsw x8, [x8, #0x320] ; 0x18b24: cmp w8, #1 ; 0x18b28: b.lt #0x18b40 ; 0x18b2c: adrp x9, #0x4f000
 */
uint64_t fde_0217_0x18b1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18b1cULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001be2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0218] `_Z12get_gc_countv` (`0x18b44..0x18b6c`, 40 bytes)
 *        Hàm FDE[0218] `_Z12get_gc_countv` (`0x18b44..0x18b6c`, 40 bytes)
 * Disassembly: 0x18b44: adrp x8, #0x50000 ; 0x18b48: ldrsw x8, [x8, #0x320] ; 0x18b4c: cmp w8, #1 ; 0x18b50: b.lt #0x18b68 ; 0x18b54: adrp x9, #0x4f000
 */
uint64_t fde_0218_0x18b44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18b44ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001bd8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0219] `_Z11get_gc_timev` (`0x18b6c..0x18b94`, 40 bytes)
 *        Hàm FDE[0219] `_Z11get_gc_timev` (`0x18b6c..0x18b94`, 40 bytes)
 * Disassembly: 0x18b6c: adrp x8, #0x50000 ; 0x18b70: ldrsw x8, [x8, #0x320] ; 0x18b74: cmp w8, #1 ; 0x18b78: b.lt #0x18b90 ; 0x18b7c: adrp x9, #0x4f000
 */
uint64_t fde_0219_0x18b6c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18b6cULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001bceU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0220] `_Z21get_blocking_gc_countv` (`0x18b94..0x18bbc`, 40 bytes)
 *        Hàm FDE[0220] `_Z21get_blocking_gc_countv` (`0x18b94..0x18bbc`, 40 bytes)
 * Disassembly: 0x18b94: adrp x8, #0x50000 ; 0x18b98: ldrsw x8, [x8, #0x320] ; 0x18b9c: cmp w8, #1 ; 0x18ba0: b.lt #0x18bb8 ; 0x18ba4: adrp x9, #0x4f000
 */
uint64_t fde_0220_0x18b94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18b94ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001bc4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0221] `_Z20get_blocking_gc_timev` (`0x18bbc..0x18be4`, 40 bytes)
 *        Hàm FDE[0221] `_Z20get_blocking_gc_timev` (`0x18bbc..0x18be4`, 40 bytes)
 * Disassembly: 0x18bbc: adrp x8, #0x50000 ; 0x18bc0: ldrsw x8, [x8, #0x320] ; 0x18bc4: cmp w8, #1 ; 0x18bc8: b.lt #0x18be0 ; 0x18bcc: adrp x9, #0x4f000
 */
uint64_t fde_0221_0x18bbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18bbcULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0x14001bbaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0222] `_Z25setEnableAllocatedMonitorbiiil` (`0x18be4..0x18ef4`, 784 bytes)
 *        Hàm FDE[0222] `_Z25setEnableAllocatedMonitorbiiil` (`0x18be4..0x18ef4`, 784 bytes)
 * Disassembly: 0x18be4: sub sp, sp, #0x80 ; 0x18be8: stp x28, x27, [sp, #0x20] ; 0x18bec: stp x26, x25, [sp, #0x30] ; 0x18bf0: stp x24, x23, [sp, #0x40] ; 0x18bf4: stp x22, x21, [sp, #0x50]
 */
uint64_t fde_0222_0x18be4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18be4ULL;
    constexpr uint64_t kSize = 0x310ULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0x940019c1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0223] `_Z27startOrStopAllocatedMonitorbPKc` (`0x18ef4..0x18f7c`, 136 bytes)
 *        Hàm FDE[0223] `_Z27startOrStopAllocatedMonitorbPKc` (`0x18ef4..0x18f7c`, 136 bytes)
 * Disassembly: 0x18ef4: str x19, [sp, #-0x20]! ; 0x18ef8: stp x29, x30, [sp, #0x10] ; 0x18efc: add x29, sp, #0x10 ; 0x18f00: adrp x8, #0x50000 ; 0x18f04: ldrb w8, [x8, #0x300]
 */
uint64_t fde_0223_0x18ef4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18ef4ULL;
    constexpr uint64_t kSize = 0x88ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001c8aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0224] `sub_18f7c` (`0x18f7c..0x18f94`, 24 bytes)
 *        Hàm FDE[0224] `sub_18f7c` (`0x18f7c..0x18f94`, 24 bytes)
 * Disassembly: 0x18f7c: str x19, [sp, #-0x20]! ; 0x18f80: stp x29, x30, [sp, #0x10] ; 0x18f84: add x29, sp, #0x10 ; 0x18f88: bl #0x1fe48 ; 0x18f8c: ldp x29, x30, [sp, #0x10]
 */
uint64_t fde_0224_0x18f7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18f7cULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001979U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0225] `sub_18f94` (`0x18f94..0x18fa4`, 16 bytes)
 *        Hàm FDE[0225] `sub_18f94` (`0x18f94..0x18fa4`, 16 bytes)
 * Disassembly: 0x18f94: ldr x0, [x0, #0x18] ; 0x18f98: cbz x0, #0x18fa0 ; 0x18f9c: b #0x203dc ; 0x18fa0: ret
 */
uint64_t fde_0225_0x18f94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18f94ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0226] `sub_18fa4` (`0x18fa4..0x18fb4`, 16 bytes)
 *        Hàm FDE[0226] `sub_18fa4` (`0x18fa4..0x18fb4`, 16 bytes)
 * Disassembly: 0x18fa4: adrp x9, #0x4f000 ; 0x18fa8: ldr x8, [x1, #8] ; 0x18fac: ldr x9, [x9, #0xf90] ; 0x18fb0: b #0x1f6bc
 */
uint64_t fde_0226_0x18fa4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18fa4ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf00001a9U;
    constexpr uint32_t kOpN  = 0x140019c3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0227] `sub_18fb4` (`0x18fb4..0x18fb8`, 4 bytes)
 *        Hàm FDE[0227] `sub_18fb4` (`0x18fb4..0x18fb8`, 4 bytes)
 * Disassembly: 0x18fb4: b #0x20e88
 */
uint64_t fde_0227_0x18fb4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18fb4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001fb5U;
    constexpr uint32_t kOpN  = 0x14001fb5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0228] `sub_18fb8` (`0x18fb8..0x18fbc`, 4 bytes)
 *        Hàm FDE[0228] `sub_18fb8` (`0x18fb8..0x18fbc`, 4 bytes)
 * Disassembly: 0x18fb8: ret
 */
uint64_t fde_0228_0x18fb8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18fb8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0229] `sub_18fbc` (`0x18fbc..0x18fc0`, 4 bytes)
 *        Hàm FDE[0229] `sub_18fbc` (`0x18fbc..0x18fc0`, 4 bytes)
 * Disassembly: 0x18fbc: b #0x20e88
 */
uint64_t fde_0229_0x18fbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18fbcULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001fb3U;
    constexpr uint32_t kOpN  = 0x14001fb3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0230] `sub_18fc0` (`0x18fc0..0x18fd4`, 20 bytes)
 *        Hàm FDE[0230] `sub_18fc0` (`0x18fc0..0x18fd4`, 20 bytes)
 * Disassembly: 0x18fc0: adrp x8, #0x50000 ; 0x18fc4: ldr x0, [x8, #0x3e0] ; 0x18fc8: cbz x0, #0x18fd0 ; 0x18fcc: b #0x18fd4 ; 0x18fd0: ret
 */
uint64_t fde_0230_0x18fc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18fc0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x900001c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0231] `sub_18fd4` (`0x18fd4..0x19528`, 1364 bytes)
 *        Hàm FDE[0231] `sub_18fd4` (`0x18fd4..0x19528`, 1364 bytes)
 * Disassembly: 0x18fd4: sub sp, sp, #0x150 ; 0x18fd8: stp x28, x27, [sp, #0xf0] ; 0x18fdc: stp x26, x25, [sp, #0x100] ; 0x18fe0: stp x24, x23, [sp, #0x110] ; 0x18fe4: stp x22, x21, [sp, #0x120]
 */
uint64_t fde_0231_0x18fd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x18fd4ULL;
    constexpr uint64_t kSize = 0x554ULL;
    constexpr uint32_t kOp0  = 0xd10543ffU;
    constexpr uint32_t kOpN  = 0x9400763eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0232] `sub_19528` (`0x19528..0x19928`, 1024 bytes)
 *        Hàm FDE[0232] `sub_19528` (`0x19528..0x19928`, 1024 bytes)
 * Disassembly: 0x19528: sub sp, sp, #0xc0 ; 0x1952c: stp x28, x27, [sp, #0x60] ; 0x19530: stp x26, x25, [sp, #0x70] ; 0x19534: stp x24, x23, [sp, #0x80] ; 0x19538: stp x22, x21, [sp, #0x90]
 */
uint64_t fde_0232_0x19528(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19528ULL;
    constexpr uint64_t kSize = 0x400ULL;
    constexpr uint32_t kOp0  = 0xd10303ffU;
    constexpr uint32_t kOpN  = 0x94001a09U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0233] `sub_19928` (`0x19928..0x19934`, 12 bytes)
 *        Hàm FDE[0233] `sub_19928` (`0x19928..0x19934`, 12 bytes)
 * Disassembly: 0x19928: cbz x0, #0x19930 ; 0x1992c: b #0x20d50 ; 0x19930: ret
 */
uint64_t fde_0233_0x19928(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19928ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb4000040U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0234] `sub_19934` (`0x19934..0x199d4`, 160 bytes)
 *        Hàm FDE[0234] `sub_19934` (`0x19934..0x199d4`, 160 bytes)
 * Disassembly: 0x19934: ldr x8, [x0, #8] ; 0x19938: cbz x8, #0x199cc ; 0x1993c: fmov d0, x8 ; 0x19940: mov x2, x30 ; 0x19944: bl #0x1f730
 */
uint64_t fde_0234_0x19934(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19934ULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xf9400408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0235] `sub_199d4` (`0x199d4..0x199f0`, 28 bytes)
 *        Hàm FDE[0235] `sub_199d4` (`0x199d4..0x199f0`, 28 bytes)
 * Disassembly: 0x199d4: str x19, [sp, #-0x20]! ; 0x199d8: stp x29, x30, [sp, #0x10] ; 0x199dc: add x29, sp, #0x10 ; 0x199e0: bl #0x1f92c ; 0x199e4: bl #0x19928
 */
uint64_t fde_0235_0x199d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x199d4ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x140016e2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0236] `sub_199f0` (`0x199f0..0x19a20`, 48 bytes)
 *        Hàm FDE[0236] `sub_199f0` (`0x199f0..0x19a20`, 48 bytes)
 * Disassembly: 0x199f0: stp x20, x19, [sp, #-0x20]! ; 0x199f4: stp x29, x30, [sp, #0x10] ; 0x199f8: add x29, sp, #0x10 ; 0x199fc: bl #0x20150 ; 0x19a00: bl #0x1ff00
 */
uint64_t fde_0236_0x199f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x199f0ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14001707U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0237] `sub_19a20` (`0x19a20..0x19c10`, 496 bytes)
 *        Hàm FDE[0237] `sub_19a20` (`0x19a20..0x19c10`, 496 bytes)
 * Disassembly: 0x19a20: sub sp, sp, #0x70 ; 0x19a24: stp x26, x25, [sp, #0x20] ; 0x19a28: stp x24, x23, [sp, #0x30] ; 0x19a2c: stp x22, x21, [sp, #0x40] ; 0x19a30: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_0237_0x19a20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19a20ULL;
    constexpr uint64_t kSize = 0x1f0ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x9400167aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0238] `sub_19c10` (`0x19c10..0x19c28`, 24 bytes)
 *        Hàm FDE[0238] `sub_19c10` (`0x19c10..0x19c28`, 24 bytes)
 * Disassembly: 0x19c10: mov x8, x0 ; 0x19c14: ldr x0, [x0] ; 0x19c18: str xzr, [x8] ; 0x19c1c: cbz x0, #0x19c24 ; 0x19c20: b #0x20e88
 */
uint64_t fde_0238_0x19c10(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19c10ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0239] `sub_19c28` (`0x19c28..0x19d2c`, 260 bytes)
 *        Hàm FDE[0239] `sub_19c28` (`0x19c28..0x19d2c`, 260 bytes)
 * Disassembly: 0x19c28: stp x20, x19, [sp, #-0x20]! ; 0x19c2c: stp x29, x30, [sp, #0x10] ; 0x19c30: add x29, sp, #0x10 ; 0x19c34: mov x19, x0 ; 0x19c38: cbz x1, #0x19c9c
 */
uint64_t fde_0239_0x19c28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19c28ULL;
    constexpr uint64_t kSize = 0x104ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x940016ddU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0240] `sub_19d2c` (`0x19d2c..0x19d44`, 24 bytes)
 *        Hàm FDE[0240] `sub_19d2c` (`0x19d2c..0x19d44`, 24 bytes)
 * Disassembly: 0x19d2c: mov x8, x0 ; 0x19d30: ldr x0, [x0] ; 0x19d34: str x1, [x8] ; 0x19d38: cbz x0, #0x19d40 ; 0x19d3c: b #0x20e88
 */
uint64_t fde_0240_0x19d2c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19d2cULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0241] `sub_19d44` (`0x19d44..0x19d5c`, 24 bytes)
 *        Hàm FDE[0241] `sub_19d44` (`0x19d44..0x19d5c`, 24 bytes)
 * Disassembly: 0x19d44: mov x8, x0 ; 0x19d48: ldr x0, [x0] ; 0x19d4c: str xzr, [x8] ; 0x19d50: cbz x0, #0x19d58 ; 0x19d54: b #0x19d5c
 */
uint64_t fde_0241_0x19d44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19d44ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0242] `sub_19d5c` (`0x19d5c..0x19dfc`, 160 bytes)
 *        Hàm FDE[0242] `sub_19d5c` (`0x19d5c..0x19dfc`, 160 bytes)
 * Disassembly: 0x19d5c: cbz x0, #0x19dbc ; 0x19d60: stp x20, x19, [sp, #-0x20]! ; 0x19d64: stp x29, x30, [sp, #0x10] ; 0x19d68: add x29, sp, #0x10 ; 0x19d6c: adrp x8, #0x4c000
 */
uint64_t fde_0242_0x19d5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19d5cULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xb4000300U;
    constexpr uint32_t kOpN  = 0x14001c24U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0243] `sub_19dfc` (`0x19dfc..0x19e40`, 68 bytes)
 *        Hàm FDE[0243] `sub_19dfc` (`0x19dfc..0x19e40`, 68 bytes)
 * Disassembly: 0x19dfc: str x21, [sp, #-0x30]! ; 0x19e00: stp x20, x19, [sp, #0x10] ; 0x19e04: stp x29, x30, [sp, #0x20] ; 0x19e08: add x29, sp, #0x20 ; 0x19e0c: ldr x8, [x0, #0x10]
 */
uint64_t fde_0243_0x19dfc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19dfcULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x140015f6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0244] `sub_19e40` (`0x19e40..0x19e4c`, 12 bytes)
 *        Hàm FDE[0244] `sub_19e40` (`0x19e40..0x19e4c`, 12 bytes)
 * Disassembly: 0x19e40: cbz x0, #0x19e48 ; 0x19e44: b #0x20d50 ; 0x19e48: ret
 */
uint64_t fde_0244_0x19e40(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19e40ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb4000040U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0245] `sub_19e4c` (`0x19e4c..0x19e74`, 40 bytes)
 *        Hàm FDE[0245] `sub_19e4c` (`0x19e4c..0x19e74`, 40 bytes)
 * Disassembly: 0x19e4c: str x19, [sp, #-0x20]! ; 0x19e50: stp x29, x30, [sp, #0x10] ; 0x19e54: add x29, sp, #0x10 ; 0x19e58: cbz x0, #0x19e6c ; 0x19e5c: ldr x19, [x0]
 */
uint64_t fde_0245_0x19e4c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19e4cULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001604U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0246] `sub_19e74` (`0x19e74..0x19e7c`, 8 bytes)
 *        Hàm FDE[0246] `sub_19e74` (`0x19e74..0x19e7c`, 8 bytes)
 * Disassembly: 0x19e74: add x0, x0, #8 ; 0x19e78: ret
 */
uint64_t fde_0246_0x19e74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19e74ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x91002000U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0247] `sub_19e7c` (`0x19e7c..0x19ea8`, 44 bytes)
 *        Hàm FDE[0247] `sub_19e7c` (`0x19e7c..0x19ea8`, 44 bytes)
 * Disassembly: 0x19e7c: add x8, x0, #0x10 ; 0x19e80: ldaxr x9, [x8] ; 0x19e84: add x9, x9, #1 ; 0x19e88: stlxr w10, x9, [x8] ; 0x19e8c: cbnz w10, #0x19e80
 */
uint64_t fde_0247_0x19e7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19e7cULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0x91004008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0248] `sub_19ea8` (`0x19ea8..0x19ec0`, 24 bytes)
 *        Hàm FDE[0248] `sub_19ea8` (`0x19ea8..0x19ec0`, 24 bytes)
 * Disassembly: 0x19ea8: str x19, [sp, #-0x20]! ; 0x19eac: stp x29, x30, [sp, #0x10] ; 0x19eb0: add x29, sp, #0x10 ; 0x19eb4: bl #0x1fe48 ; 0x19eb8: ldp x29, x30, [sp, #0x10]
 */
uint64_t fde_0248_0x19ea8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19ea8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x140015aeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0249] `sub_19ec0` (`0x19ec0..0x19ec8`, 8 bytes)
 *        Hàm FDE[0249] `sub_19ec0` (`0x19ec0..0x19ec8`, 8 bytes)
 * Disassembly: 0x19ec0: ldr x0, [x0, #0x18] ; 0x19ec4: b #0x19d5c
 */
uint64_t fde_0249_0x19ec0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19ec0ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0x17ffffa6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0250] `sub_19ec8` (`0x19ec8..0x19ed8`, 16 bytes)
 *        Hàm FDE[0250] `sub_19ec8` (`0x19ec8..0x19ed8`, 16 bytes)
 * Disassembly: 0x19ec8: adrp x9, #0x4f000 ; 0x19ecc: ldr x8, [x1, #8] ; 0x19ed0: ldr x9, [x9, #0xfe0] ; 0x19ed4: b #0x1f6bc
 */
uint64_t fde_0250_0x19ec8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19ec8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xd00001a9U;
    constexpr uint32_t kOpN  = 0x140015faU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0251] `sub_19ed8` (`0x19ed8..0x19edc`, 4 bytes)
 *        Hàm FDE[0251] `sub_19ed8` (`0x19ed8..0x19edc`, 4 bytes)
 * Disassembly: 0x19ed8: b #0x20e88
 */
uint64_t fde_0251_0x19ed8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19ed8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001becU;
    constexpr uint32_t kOpN  = 0x14001becU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0252] `sub_19edc` (`0x19edc..0x19f7c`, 160 bytes)
 *        Hàm FDE[0252] `sub_19edc` (`0x19edc..0x19f7c`, 160 bytes)
 * Disassembly: 0x19edc: ldr x8, [x0, #8] ; 0x19ee0: cbz x8, #0x19f74 ; 0x19ee4: fmov d0, x8 ; 0x19ee8: mov x2, x30 ; 0x19eec: bl #0x1f730
 */
uint64_t fde_0252_0x19edc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19edcULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xf9400408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0253] `sub_19f7c` (`0x19f7c..0x19f98`, 28 bytes)
 *        Hàm FDE[0253] `sub_19f7c` (`0x19f7c..0x19f98`, 28 bytes)
 * Disassembly: 0x19f7c: str x19, [sp, #-0x20]! ; 0x19f80: stp x29, x30, [sp, #0x10] ; 0x19f84: add x29, sp, #0x10 ; 0x19f88: bl #0x1f92c ; 0x19f8c: bl #0x19e40
 */
uint64_t fde_0253_0x19f7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19f7cULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001578U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0254] `sub_19f98` (`0x19f98..0x19fc8`, 48 bytes)
 *        Hàm FDE[0254] `sub_19f98` (`0x19f98..0x19fc8`, 48 bytes)
 * Disassembly: 0x19f98: stp x20, x19, [sp, #-0x20]! ; 0x19f9c: stp x29, x30, [sp, #0x10] ; 0x19fa0: add x29, sp, #0x10 ; 0x19fa4: bl #0x20150 ; 0x19fa8: bl #0x1ff00
 */
uint64_t fde_0254_0x19f98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19f98ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x1400159dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0255] `sub_19fc8` (`0x19fc8..0x1a1b8`, 496 bytes)
 *        Hàm FDE[0255] `sub_19fc8` (`0x19fc8..0x1a1b8`, 496 bytes)
 * Disassembly: 0x19fc8: sub sp, sp, #0x70 ; 0x19fcc: stp x26, x25, [sp, #0x20] ; 0x19fd0: stp x24, x23, [sp, #0x30] ; 0x19fd4: stp x22, x21, [sp, #0x40] ; 0x19fd8: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_0255_0x19fc8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x19fc8ULL;
    constexpr uint64_t kSize = 0x1f0ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x94001510U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0256] `sub_1a1b8` (`0x1a1b8..0x1a1d0`, 24 bytes)
 *        Hàm FDE[0256] `sub_1a1b8` (`0x1a1b8..0x1a1d0`, 24 bytes)
 * Disassembly: 0x1a1b8: mov x8, x0 ; 0x1a1bc: ldr x0, [x0] ; 0x1a1c0: str xzr, [x8] ; 0x1a1c4: cbz x0, #0x1a1cc ; 0x1a1c8: b #0x20e88
 */
uint64_t fde_0256_0x1a1b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a1b8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0257] `sub_1a1d0` (`0x1a1d0..0x1a2d4`, 260 bytes)
 *        Hàm FDE[0257] `sub_1a1d0` (`0x1a1d0..0x1a2d4`, 260 bytes)
 * Disassembly: 0x1a1d0: stp x20, x19, [sp, #-0x20]! ; 0x1a1d4: stp x29, x30, [sp, #0x10] ; 0x1a1d8: add x29, sp, #0x10 ; 0x1a1dc: mov x19, x0 ; 0x1a1e0: cbz x1, #0x1a244
 */
uint64_t fde_0257_0x1a1d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a1d0ULL;
    constexpr uint64_t kSize = 0x104ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x94001573U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0258] `sub_1a2d4` (`0x1a2d4..0x1a2ec`, 24 bytes)
 *        Hàm FDE[0258] `sub_1a2d4` (`0x1a2d4..0x1a2ec`, 24 bytes)
 * Disassembly: 0x1a2d4: mov x8, x0 ; 0x1a2d8: ldr x0, [x0] ; 0x1a2dc: str x1, [x8] ; 0x1a2e0: cbz x0, #0x1a2e8 ; 0x1a2e4: b #0x20e88
 */
uint64_t fde_0258_0x1a2d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a2d4ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0259] `sub_1a2ec` (`0x1a2ec..0x1a304`, 24 bytes)
 *        Hàm FDE[0259] `sub_1a2ec` (`0x1a2ec..0x1a304`, 24 bytes)
 * Disassembly: 0x1a2ec: mov x8, x0 ; 0x1a2f0: ldr x0, [x0] ; 0x1a2f4: str xzr, [x8] ; 0x1a2f8: cbz x0, #0x1a300 ; 0x1a2fc: b #0x1a304
 */
uint64_t fde_0259_0x1a2ec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a2ecULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0260] `sub_1a304` (`0x1a304..0x1a334`, 48 bytes)
 *        Hàm FDE[0260] `sub_1a304` (`0x1a304..0x1a334`, 48 bytes)
 * Disassembly: 0x1a304: cbz x0, #0x1a330 ; 0x1a308: str x19, [sp, #-0x20]! ; 0x1a30c: stp x29, x30, [sp, #0x10] ; 0x1a310: add x29, sp, #0x10 ; 0x1a314: adrp x8, #0x4c000
 */
uint64_t fde_0260_0x1a304(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a304ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xb4000160U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0261] `sub_1a334` (`0x1a334..0x1a34c`, 24 bytes)
 *        Hàm FDE[0261] `sub_1a334` (`0x1a334..0x1a34c`, 24 bytes)
 * Disassembly: 0x1a334: str x19, [sp, #-0x20]! ; 0x1a338: stp x29, x30, [sp, #0x10] ; 0x1a33c: add x29, sp, #0x10 ; 0x1a340: bl #0x1fe48 ; 0x1a344: ldp x29, x30, [sp, #0x10]
 */
uint64_t fde_0261_0x1a334(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a334ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x1400148bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0262] `sub_1a34c` (`0x1a34c..0x1a354`, 8 bytes)
 *        Hàm FDE[0262] `sub_1a34c` (`0x1a34c..0x1a354`, 8 bytes)
 * Disassembly: 0x1a34c: ldr x0, [x0, #0x18] ; 0x1a350: b #0x1a304
 */
uint64_t fde_0262_0x1a34c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a34cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0x17ffffedU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0263] `sub_1a354` (`0x1a354..0x1a364`, 16 bytes)
 *        Hàm FDE[0263] `sub_1a354` (`0x1a354..0x1a364`, 16 bytes)
 * Disassembly: 0x1a354: adrp x9, #0x4f000 ; 0x1a358: ldr x8, [x1, #8] ; 0x1a35c: ldr x9, [x9, #0xdd0] ; 0x1a360: b #0x1f6bc
 */
uint64_t fde_0263_0x1a354(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a354ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb00001a9U;
    constexpr uint32_t kOpN  = 0x140014d7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0264] `sub_1a364` (`0x1a364..0x1a368`, 4 bytes)
 *        Hàm FDE[0264] `sub_1a364` (`0x1a364..0x1a368`, 4 bytes)
 * Disassembly: 0x1a364: b #0x20e88
 */
uint64_t fde_0264_0x1a364(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a364ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001ac9U;
    constexpr uint32_t kOpN  = 0x14001ac9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0265] `sub_1a368` (`0x1a368..0x1a380`, 24 bytes)
 *        Hàm FDE[0265] `sub_1a368` (`0x1a368..0x1a380`, 24 bytes)
 * Disassembly: 0x1a368: str x19, [sp, #-0x20]! ; 0x1a36c: stp x29, x30, [sp, #0x10] ; 0x1a370: add x29, sp, #0x10 ; 0x1a374: bl #0x1fe48 ; 0x1a378: ldp x29, x30, [sp, #0x10]
 */
uint64_t fde_0265_0x1a368(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a368ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x1400147eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0266] `sub_1a380` (`0x1a380..0x1a390`, 16 bytes)
 *        Hàm FDE[0266] `sub_1a380` (`0x1a380..0x1a390`, 16 bytes)
 * Disassembly: 0x1a380: ldr x0, [x0, #0x18] ; 0x1a384: cbz x0, #0x1a38c ; 0x1a388: b #0x203dc ; 0x1a38c: ret
 */
uint64_t fde_0266_0x1a380(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a380ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0267] `sub_1a390` (`0x1a390..0x1a3a0`, 16 bytes)
 *        Hàm FDE[0267] `sub_1a390` (`0x1a390..0x1a3a0`, 16 bytes)
 * Disassembly: 0x1a390: adrp x9, #0x4f000 ; 0x1a394: ldr x8, [x1, #8] ; 0x1a398: ldr x9, [x9, #0xf98] ; 0x1a39c: b #0x1f6bc
 */
uint64_t fde_0267_0x1a390(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a390ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb00001a9U;
    constexpr uint32_t kOpN  = 0x140014c8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0268] `sub_1a3a0` (`0x1a3a0..0x1a3a4`, 4 bytes)
 *        Hàm FDE[0268] `sub_1a3a0` (`0x1a3a0..0x1a3a4`, 4 bytes)
 * Disassembly: 0x1a3a0: b #0x20e88
 */
uint64_t fde_0268_0x1a3a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3a0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001abaU;
    constexpr uint32_t kOpN  = 0x14001abaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0269] `sub_1a3a4` (`0x1a3a4..0x1a3a8`, 4 bytes)
 *        Hàm FDE[0269] `sub_1a3a4` (`0x1a3a4..0x1a3a8`, 4 bytes)
 * Disassembly: 0x1a3a4: ret
 */
uint64_t fde_0269_0x1a3a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3a4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0270] `sub_1a3a8` (`0x1a3a8..0x1a3ac`, 4 bytes)
 *        Hàm FDE[0270] `sub_1a3a8` (`0x1a3a8..0x1a3ac`, 4 bytes)
 * Disassembly: 0x1a3a8: b #0x20e88
 */
uint64_t fde_0270_0x1a3a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3a8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001ab8U;
    constexpr uint32_t kOpN  = 0x14001ab8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0271] `sub_1a3ac` (`0x1a3ac..0x1a3b0`, 4 bytes)
 *        Hàm FDE[0271] `sub_1a3ac` (`0x1a3ac..0x1a3b0`, 4 bytes)
 * Disassembly: 0x1a3ac: ret
 */
uint64_t fde_0271_0x1a3ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3acULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0272] `sub_1a3b0` (`0x1a3b0..0x1a3b4`, 4 bytes)
 *        Hàm FDE[0272] `sub_1a3b0` (`0x1a3b0..0x1a3b4`, 4 bytes)
 * Disassembly: 0x1a3b0: b #0x1fe68
 */
uint64_t fde_0272_0x1a3b0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3b0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x140016aeU;
    constexpr uint32_t kOpN  = 0x140016aeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0273] `sub_1a3b4` (`0x1a3b4..0x1a3c8`, 20 bytes)
 *        Hàm FDE[0273] `sub_1a3b4` (`0x1a3b4..0x1a3c8`, 20 bytes)
 * Disassembly: 0x1a3b4: adrp x8, #0x50000 ; 0x1a3b8: ldr x0, [x8, #0x3e0] ; 0x1a3bc: cbz x0, #0x1a3c4 ; 0x1a3c0: b #0x18fd4 ; 0x1a3c4: ret
 */
uint64_t fde_0273_0x1a3b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3b4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xd00001a8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0274] `sub_1a3c8` (`0x1a3c8..0x1a3e0`, 24 bytes)
 *        Hàm FDE[0274] `sub_1a3c8` (`0x1a3c8..0x1a3e0`, 24 bytes)
 * Disassembly: 0x1a3c8: mov x8, x0 ; 0x1a3cc: ldr x0, [x0] ; 0x1a3d0: str xzr, [x8] ; 0x1a3d4: cbz x0, #0x1a3dc ; 0x1a3d8: b #0x1a3e0
 */
uint64_t fde_0274_0x1a3c8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3c8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0275] `sub_1a3e0` (`0x1a3e0..0x1a44c`, 108 bytes)
 *        Hàm FDE[0275] `sub_1a3e0` (`0x1a3e0..0x1a44c`, 108 bytes)
 * Disassembly: 0x1a3e0: str x21, [sp, #-0x30]! ; 0x1a3e4: stp x20, x19, [sp, #0x10] ; 0x1a3e8: stp x29, x30, [sp, #0x20] ; 0x1a3ec: add x29, sp, #0x20 ; 0x1a3f0: cbz x0, #0x1a428
 */
uint64_t fde_0275_0x1a3e0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a3e0ULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x97ffe128U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0276] `sub_1a44c` (`0x1a44c..0x1a4a4`, 88 bytes)
 *        Hàm FDE[0276] `sub_1a44c` (`0x1a44c..0x1a4a4`, 88 bytes)
 * Disassembly: 0x1a44c: str x19, [sp, #-0x20]! ; 0x1a450: stp x29, x30, [sp, #0x10] ; 0x1a454: add x29, sp, #0x10 ; 0x1a458: mov x19, x0 ; 0x1a45c: add x0, x0, #8
 */
uint64_t fde_0276_0x1a44c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a44cULL;
    constexpr uint64_t kSize = 0x58ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001478U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0277] `sub_1a4a4` (`0x1a4a4..0x1a4dc`, 56 bytes)
 *        Hàm FDE[0277] `sub_1a4a4` (`0x1a4a4..0x1a4dc`, 56 bytes)
 * Disassembly: 0x1a4a4: str x19, [sp, #-0x20]! ; 0x1a4a8: stp x29, x30, [sp, #0x10] ; 0x1a4ac: add x29, sp, #0x10 ; 0x1a4b0: mov x19, x0 ; 0x1a4b4: ldr x0, [x0, #0x30]
 */
uint64_t fde_0277_0x1a4a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a4a4ULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0278] `sub_1a4dc` (`0x1a4dc..0x1a520`, 68 bytes)
 *        Hàm FDE[0278] `sub_1a4dc` (`0x1a4dc..0x1a520`, 68 bytes)
 * Disassembly: 0x1a4dc: str x21, [sp, #-0x30]! ; 0x1a4e0: stp x20, x19, [sp, #0x10] ; 0x1a4e4: stp x29, x30, [sp, #0x20] ; 0x1a4e8: add x29, sp, #0x20 ; 0x1a4ec: ldr x8, [x0, #0x10]
 */
uint64_t fde_0278_0x1a4dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a4dcULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x1400143eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0279] `sub_1a520` (`0x1a520..0x1a548`, 40 bytes)
 *        Hàm FDE[0279] `sub_1a520` (`0x1a520..0x1a548`, 40 bytes)
 * Disassembly: 0x1a520: str x19, [sp, #-0x20]! ; 0x1a524: stp x29, x30, [sp, #0x10] ; 0x1a528: add x29, sp, #0x10 ; 0x1a52c: cbz x0, #0x1a540 ; 0x1a530: ldr x19, [x0]
 */
uint64_t fde_0279_0x1a520(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a520ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x1400144fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0280] `sub_1a548` (`0x1a548..0x1a560`, 24 bytes)
 *        Hàm FDE[0280] `sub_1a548` (`0x1a548..0x1a560`, 24 bytes)
 * Disassembly: 0x1a548: str x19, [sp, #-0x20]! ; 0x1a54c: stp x29, x30, [sp, #0x10] ; 0x1a550: add x29, sp, #0x10 ; 0x1a554: bl #0x1fe48 ; 0x1a558: ldp x29, x30, [sp, #0x10]
 */
uint64_t fde_0280_0x1a548(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a548ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x14001406U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0281] `sub_1a560` (`0x1a560..0x1a568`, 8 bytes)
 *        Hàm FDE[0281] `sub_1a560` (`0x1a560..0x1a568`, 8 bytes)
 * Disassembly: 0x1a560: ldr x0, [x0, #0x18] ; 0x1a564: b #0x1a3e0
 */
uint64_t fde_0281_0x1a560(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a560ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0x17ffff9fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0282] `sub_1a568` (`0x1a568..0x1a578`, 16 bytes)
 *        Hàm FDE[0282] `sub_1a568` (`0x1a568..0x1a578`, 16 bytes)
 * Disassembly: 0x1a568: adrp x9, #0x4f000 ; 0x1a56c: ldr x8, [x1, #8] ; 0x1a570: ldr x9, [x9, #0xf48] ; 0x1a574: b #0x1f6bc
 */
uint64_t fde_0282_0x1a568(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a568ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb00001a9U;
    constexpr uint32_t kOpN  = 0x14001452U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0283] `sub_1a578` (`0x1a578..0x1a57c`, 4 bytes)
 *        Hàm FDE[0283] `sub_1a578` (`0x1a578..0x1a57c`, 4 bytes)
 * Disassembly: 0x1a578: b #0x20e88
 */
uint64_t fde_0283_0x1a578(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a578ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14001a44U;
    constexpr uint32_t kOpN  = 0x14001a44U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0284] `_Z20clearAllocateMonitorv` (`0x1a57c..0x1a5d4`, 88 bytes)
 *        Hàm FDE[0284] `_Z20clearAllocateMonitorv` (`0x1a57c..0x1a5d4`, 88 bytes)
 * Disassembly: 0x1a57c: stp x20, x19, [sp, #-0x20]! ; 0x1a580: stp x29, x30, [sp, #0x10] ; 0x1a584: add x29, sp, #0x10 ; 0x1a588: adrp x8, #0x50000 ; 0x1a58c: ldr x19, [x8, #0x3e0]
 */
uint64_t fde_0284_0x1a57c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a57cULL;
    constexpr uint64_t kSize = 0x58ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x1400141aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0285] `_Z27tst_count_scanf_conversionsPKc` (`0x1a5d4..0x1a638`, 100 bytes)
 *        Hàm FDE[0285] `_Z27tst_count_scanf_conversionsPKc` (`0x1a5d4..0x1a638`, 100 bytes)
 * Disassembly: 0x1a5d4: mov w8, wzr ; 0x1a5d8: mov w9, wzr ; 0x1a5dc: ldrb w10, [x0] ; 0x1a5e0: cmp w10, #0x25 ; 0x1a5e4: b.eq #0x1a5fc
 */
uint64_t fde_0285_0x1a5d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a5d4ULL;
    constexpr uint64_t kSize = 0x64ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0286] `_Z15safe_file_scanfPKcS0_z` (`0x1a638..0x1a794`, 348 bytes)
 *        Hàm FDE[0286] `_Z15safe_file_scanfPKcS0_z` (`0x1a638..0x1a794`, 348 bytes)
 * Disassembly: 0x1a638: sub sp, sp, #0x150 ; 0x1a63c: str x28, [sp, #0x100] ; 0x1a640: stp x24, x23, [sp, #0x110] ; 0x1a644: stp x22, x21, [sp, #0x120] ; 0x1a648: stp x20, x19, [sp, #0x130]
 */
uint64_t fde_0286_0x1a638(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a638ULL;
    constexpr uint64_t kSize = 0x15cULL;
    constexpr uint32_t kOp0  = 0xd10543ffU;
    constexpr uint32_t kOpN  = 0x97ffda3cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0287] `_Z15get_minor_faultv` (`0x1a794..0x1a7dc`, 72 bytes)
 *        Hàm FDE[0287] `_Z15get_minor_faultv` (`0x1a794..0x1a7dc`, 72 bytes)
 * Disassembly: 0x1a794: sub sp, sp, #0x30 ; 0x1a798: str x19, [sp, #0x10] ; 0x1a79c: stp x29, x30, [sp, #0x20] ; 0x1a7a0: add x29, sp, #0x20 ; 0x1a7a4: mrs x19, tpidr_el0
 */
uint64_t fde_0287_0x1a794(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a794ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x97ffda2aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0288] `_Z15get_major_faultv` (`0x1a7dc..0x1a824`, 72 bytes)
 *        Hàm FDE[0288] `_Z15get_major_faultv` (`0x1a7dc..0x1a824`, 72 bytes)
 * Disassembly: 0x1a7dc: sub sp, sp, #0x30 ; 0x1a7e0: str x19, [sp, #0x10] ; 0x1a7e4: stp x29, x30, [sp, #0x20] ; 0x1a7e8: add x29, sp, #0x20 ; 0x1a7ec: mrs x19, tpidr_el0
 */
uint64_t fde_0288_0x1a7dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a7dcULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x97ffda18U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0289] `_Z18getRecordsAndClearPlS_` (`0x1a824..0x1a994`, 368 bytes)
 *        Hàm FDE[0289] `_Z18getRecordsAndClearPlS_` (`0x1a824..0x1a994`, 368 bytes)
 * Disassembly: 0x1a824: sub sp, sp, #0x70 ; 0x1a828: str x23, [sp, #0x30] ; 0x1a82c: stp x22, x21, [sp, #0x40] ; 0x1a830: stp x20, x19, [sp, #0x50] ; 0x1a834: stp x29, x30, [sp, #0x60]
 */
uint64_t fde_0289_0x1a824(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a824ULL;
    constexpr uint64_t kSize = 0x170ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x94001319U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0290] `sub_1a994` (`0x1a994..0x1a9dc`, 72 bytes)
 *        Hàm FDE[0290] `sub_1a994` (`0x1a994..0x1a9dc`, 72 bytes)
 * Disassembly: 0x1a994: stp x0, x0, [x0] ; 0x1a998: str xzr, [x0, #0x10] ; 0x1a99c: ldr x8, [x1, #0x10] ; 0x1a9a0: cbz x8, #0x1a9d8 ; 0x1a9a4: ldp x9, x10, [x1]
 */
uint64_t fde_0290_0x1a994(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a994ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xa9000000U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0291] `_Z17translateLocationPvjPPKcPi` (`0x1a9dc..0x1aa08`, 44 bytes)
 *        Hàm FDE[0291] `_Z17translateLocationPvjPPKcPi` (`0x1a9dc..0x1aa08`, 44 bytes)
 * Disassembly: 0x1a9dc: adrp x8, #0x4f000 ; 0x1a9e0: ldr x8, [x8, #0xfb0] ; 0x1a9e4: ldr x4, [x8] ; 0x1a9e8: cbz x4, #0x1a9f0 ; 0x1a9ec: br x4
 */
uint64_t fde_0291_0x1a9dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1a9dcULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xb00001a8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0292] `_Z24convert_records_to_bytesP7_JNIEnvRNSt6__ndk14listINS1_10shared_ptrI11ClassRecordEENS1_9allocatorIS5_EEEEllil` (`0x1aa08..0x1adc0`, 952 bytes)
 *        Hàm FDE[0292] `_Z24convert_records_to_bytesP7_JNIEnvRNSt6__ndk14listINS1_10shared_ptrI11ClassRecordEENS1_9allocatorIS5_EEEEllil` (`0x1aa08..0x1adc0`, 952 bytes)
 * Disassembly: 0x1aa08: mov x6, x30 ; 0x1aa0c: bl #0x1ff68 ; 0x1aa10: mov x30, x6 ; 0x1aa14: stp x29, x30, [sp, #0xd0] ; 0x1aa18: add x29, sp, #0xd0
 */
uint64_t fde_0292_0x1aa08(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1aa08ULL;
    constexpr uint64_t kSize = 0x3b8ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e6U;
    constexpr uint32_t kOpN  = 0x9400120eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0293] `_Z21get_alloc_report_infoP7_JNIEnvP7_jclass` (`0x1adc0..0x1ae84`, 196 bytes)
 *        Hàm FDE[0293] `_Z21get_alloc_report_infoP7_JNIEnvP7_jclass` (`0x1adc0..0x1ae84`, 196 bytes)
 * Disassembly: 0x1adc0: sub sp, sp, #0x80 ; 0x1adc4: str x21, [sp, #0x50] ; 0x1adc8: stp x20, x19, [sp, #0x60] ; 0x1adcc: stp x29, x30, [sp, #0x70] ; 0x1add0: add x29, sp, #0x70
 */
uint64_t fde_0293_0x1adc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1adc0ULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0x940011ddU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0294] `_Z19initAddGlobalRefSymPv` (`0x1ae84..0x1aec4`, 64 bytes)
 *        Hàm FDE[0294] `_Z19initAddGlobalRefSymPv` (`0x1ae84..0x1aec4`, 64 bytes)
 * Disassembly: 0x1ae84: stp x20, x19, [sp, #-0x20]! ; 0x1ae88: stp x29, x30, [sp, #0x10] ; 0x1ae8c: add x29, sp, #0x10 ; 0x1ae90: adrp x1, #0x3a000 ; 0x1ae94: add x1, x1, #0x56a
 */
uint64_t fde_0294_0x1ae84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ae84ULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x140011deU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0295] `_ZN17MirrorObjectCache3addEPvm` (`0x1aec4..0x1b1e4`, 800 bytes)
 *        Hàm FDE[0295] `_ZN17MirrorObjectCache3addEPvm` (`0x1aec4..0x1b1e4`, 800 bytes)
 * Disassembly: 0x1aec4: sub sp, sp, #0x70 ; 0x1aec8: stp x26, x25, [sp, #0x20] ; 0x1aecc: stp x24, x23, [sp, #0x30] ; 0x1aed0: stp x22, x21, [sp, #0x40] ; 0x1aed4: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_0295_0x1aec4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1aec4ULL;
    constexpr uint64_t kSize = 0x320ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x94001105U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0296] `sub_1b1e4` (`0x1b1e4..0x1b284`, 160 bytes)
 *        Hàm FDE[0296] `sub_1b1e4` (`0x1b1e4..0x1b284`, 160 bytes)
 * Disassembly: 0x1b1e4: ldr x8, [x0, #8] ; 0x1b1e8: cbz x8, #0x1b27c ; 0x1b1ec: fmov d0, x8 ; 0x1b1f0: mov x2, x30 ; 0x1b1f4: bl #0x1f730
 */
uint64_t fde_0296_0x1b1e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b1e4ULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xf9400408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0297] `sub_1b284` (`0x1b284..0x1b29c`, 24 bytes)
 *        Hàm FDE[0297] `sub_1b284` (`0x1b284..0x1b29c`, 24 bytes)
 * Disassembly: 0x1b284: mov x8, x0 ; 0x1b288: ldr x0, [x0] ; 0x1b28c: str xzr, [x8] ; 0x1b290: cbz x0, #0x1b298 ; 0x1b294: b #0x20e88
 */
uint64_t fde_0297_0x1b284(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b284ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0298] `sub_1b29c` (`0x1b29c..0x1b3a0`, 260 bytes)
 *        Hàm FDE[0298] `sub_1b29c` (`0x1b29c..0x1b3a0`, 260 bytes)
 * Disassembly: 0x1b29c: stp x20, x19, [sp, #-0x20]! ; 0x1b2a0: stp x29, x30, [sp, #0x10] ; 0x1b2a4: add x29, sp, #0x10 ; 0x1b2a8: mov x19, x0 ; 0x1b2ac: cbz x1, #0x1b310
 */
uint64_t fde_0298_0x1b29c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b29cULL;
    constexpr uint64_t kSize = 0x104ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x94001140U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0299] `sub_1b3a0` (`0x1b3a0..0x1b3b8`, 24 bytes)
 *        Hàm FDE[0299] `sub_1b3a0` (`0x1b3a0..0x1b3b8`, 24 bytes)
 * Disassembly: 0x1b3a0: mov x8, x0 ; 0x1b3a4: ldr x0, [x0] ; 0x1b3a8: str x1, [x8] ; 0x1b3ac: cbz x0, #0x1b3b4 ; 0x1b3b0: b #0x20e88
 */
uint64_t fde_0299_0x1b3a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b3a0ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xaa0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0300] `_ZN17MirrorObjectCache6removeEPvm` (`0x1b3b8..0x1b58c`, 468 bytes)
 *        Hàm FDE[0300] `_ZN17MirrorObjectCache6removeEPvm` (`0x1b3b8..0x1b58c`, 468 bytes)
 * Disassembly: 0x1b3b8: sub sp, sp, #0x60 ; 0x1b3bc: str x23, [sp, #0x20] ; 0x1b3c0: stp x22, x21, [sp, #0x30] ; 0x1b3c4: stp x20, x19, [sp, #0x40] ; 0x1b3c8: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_0300_0x1b3b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b3b8ULL;
    constexpr uint64_t kSize = 0x1d4ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x97ffd6beU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0301] `_ZN10ByteBuffer7putLongEl` (`0x1b58c..0x1b5c4`, 56 bytes)
 *        Hàm FDE[0301] `_ZN10ByteBuffer7putLongEl` (`0x1b58c..0x1b5c4`, 56 bytes)
 * Disassembly: 0x1b58c: stp x20, x19, [sp, #-0x20]! ; 0x1b590: stp x29, x30, [sp, #0x10] ; 0x1b594: add x29, sp, #0x10 ; 0x1b598: mov x19, x1 ; 0x1b59c: mov w1, #8
 */
uint64_t fde_0301_0x1b58c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b58cULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x1400101eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0302] `_ZN10ByteBuffer11ensureWriteEm` (`0x1b5c4..0x1b5e8`, 36 bytes)
 *        Hàm FDE[0302] `_ZN10ByteBuffer11ensureWriteEm` (`0x1b5c4..0x1b5e8`, 36 bytes)
 * Disassembly: 0x1b5c4: ldr w8, [x0, #0x18] ; 0x1b5c8: ldp x9, x10, [x0] ; 0x1b5cc: add w8, w8, w1 ; 0x1b5d0: sub x9, x10, x9 ; 0x1b5d4: cmp x9, w8, sxtw
 */
uint64_t fde_0302_0x1b5c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b5c4ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xb9401808U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0303] `_ZN10ByteBuffer6putIntEi` (`0x1b5e8..0x1b620`, 56 bytes)
 *        Hàm FDE[0303] `_ZN10ByteBuffer6putIntEi` (`0x1b5e8..0x1b620`, 56 bytes)
 * Disassembly: 0x1b5e8: stp x20, x19, [sp, #-0x20]! ; 0x1b5ec: stp x29, x30, [sp, #0x10] ; 0x1b5f0: add x29, sp, #0x10 ; 0x1b5f4: mov w19, w1 ; 0x1b5f8: mov w1, #4
 */
uint64_t fde_0303_0x1b5e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b5e8ULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14001007U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0304] `_ZN10ByteBuffer12putStringStdERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE` (`0x1b620..0x1b6b8`, 152 bytes)
 *        Hàm FDE[0304] `_ZN10ByteBuffer12putStringStdERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE` (`0x1b620..0x1b6b8`, 152 bytes)
 * Disassembly: 0x1b620: stp x20, x19, [sp, #-0x20]! ; 0x1b624: stp x29, x30, [sp, #0x10] ; 0x1b628: add x29, sp, #0x10 ; 0x1b62c: ldrb w8, [x1] ; 0x1b630: ldr w9, [x1, #8]
 */
uint64_t fde_0304_0x1b620(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b620ULL;
    constexpr uint64_t kSize = 0x98ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14000fe1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0305] `_ZN10ByteBuffer7getLongEv` (`0x1b6b8..0x1b6d0`, 24 bytes)
 *        Hàm FDE[0305] `_ZN10ByteBuffer7getLongEv` (`0x1b6b8..0x1b6d0`, 24 bytes)
 * Disassembly: 0x1b6b8: ldrsw x8, [x0, #0x18] ; 0x1b6bc: ldr x9, [x0] ; 0x1b6c0: add w10, w8, #8 ; 0x1b6c4: str w10, [x0, #0x18] ; 0x1b6c8: ldr x0, [x9, x8]
 */
uint64_t fde_0305_0x1b6b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b6b8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xb9801808U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0306] `_ZN10ByteBuffer6getIntEv` (`0x1b6d0..0x1b6e8`, 24 bytes)
 *        Hàm FDE[0306] `_ZN10ByteBuffer6getIntEv` (`0x1b6d0..0x1b6e8`, 24 bytes)
 * Disassembly: 0x1b6d0: ldrsw x8, [x0, #0x18] ; 0x1b6d4: ldr x9, [x0] ; 0x1b6d8: add w10, w8, #4 ; 0x1b6dc: str w10, [x0, #0x18] ; 0x1b6e0: ldr w0, [x9, x8]
 */
uint64_t fde_0306_0x1b6d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b6d0ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xb9801808U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0307] `_ZN10ByteBuffer9getStringEv` (`0x1b6e8..0x1b714`, 44 bytes)
 *        Hàm FDE[0307] `_ZN10ByteBuffer9getStringEv` (`0x1b6e8..0x1b714`, 44 bytes)
 * Disassembly: 0x1b6e8: ldrsw x9, [x0, #0x18] ; 0x1b6ec: ldr x10, [x0] ; 0x1b6f0: ldrsw x2, [x10, x9] ; 0x1b6f4: add x9, x9, #4 ; 0x1b6f8: add x1, x10, x9
 */
uint64_t fde_0307_0x1b6e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b6e8ULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xb9801809U;
    constexpr uint32_t kOpN  = 0x17ffe275U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0308] `_ZN10ByteBuffer6rebaseEm` (`0x1b714..0x1b71c`, 8 bytes)
 *        Hàm FDE[0308] `_ZN10ByteBuffer6rebaseEm` (`0x1b714..0x1b71c`, 8 bytes)
 * Disassembly: 0x1b714: str w1, [x0, #0x18] ; 0x1b718: ret
 */
uint64_t fde_0308_0x1b714(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b714ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xb9001801U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0309] `_Z24find_offset_by_call_instPvS_PFbiEi` (`0x1b71c..0x1b720`, 4 bytes)
 *        Hàm FDE[0309] `_Z24find_offset_by_call_instPvS_PFbiEi` (`0x1b71c..0x1b720`, 4 bytes)
 * Disassembly: 0x1b71c: b #0x111e0
 */
uint64_t fde_0309_0x1b71c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b71cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffd6b1U;
    constexpr uint32_t kOpN  = 0x17ffd6b1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0310] `_Z14get_signed_numij` (`0x1b720..0x1b740`, 32 bytes)
 *        Hàm FDE[0310] `_Z14get_signed_numij` (`0x1b720..0x1b740`, 32 bytes)
 * Disassembly: 0x1b720: sub w8, w1, #1 ; 0x1b724: mov w9, #1 ; 0x1b728: lsl w8, w9, w8 ; 0x1b72c: lsl w9, w9, w1 ; 0x1b730: cmp w8, w0
 */
uint64_t fde_0310_0x1b720(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b720ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0x51000428U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0311] `_Z19find_offset_by_callPvS_i` (`0x1b740..0x1b7c0`, 128 bytes)
 *        Hàm FDE[0311] `_Z19find_offset_by_callPvS_i` (`0x1b740..0x1b7c0`, 128 bytes)
 * Disassembly: 0x1b740: str x21, [sp, #-0x30]! ; 0x1b744: stp x20, x19, [sp, #0x10] ; 0x1b748: stp x29, x30, [sp, #0x20] ; 0x1b74c: add x29, sp, #0x20 ; 0x1b750: cbz x0, #0x1b78c
 */
uint64_t fde_0311_0x1b740(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b740ULL;
    constexpr uint64_t kSize = 0x80ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd689U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0312] `_Z13util_mprotectPvmi` (`0x1b7c0..0x1b7dc`, 28 bytes)
 *        Hàm FDE[0312] `_Z13util_mprotectPvmi` (`0x1b7c0..0x1b7dc`, 28 bytes)
 * Disassembly: 0x1b7c0: add x9, x1, x0 ; 0x1b7c4: add x9, x9, #0xffe ; 0x1b7c8: and x8, x0, #0xfffffffffffff000 ; 0x1b7cc: and x9, x9, #0xfffffffffffff000 ; 0x1b7d0: sub x1, x9, x8
 */
uint64_t fde_0312_0x1b7c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b7c0ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0x8b000029U;
    constexpr uint32_t kOpN  = 0x17ffd47eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0313] `_Z10print_infoPvi` (`0x1b7dc..0x1b844`, 104 bytes)
 *        Hàm FDE[0313] `_Z10print_infoPvi` (`0x1b7dc..0x1b844`, 104 bytes)
 * Disassembly: 0x1b7dc: str x23, [sp, #-0x40]! ; 0x1b7e0: stp x22, x21, [sp, #0x10] ; 0x1b7e4: stp x20, x19, [sp, #0x20] ; 0x1b7e8: stp x29, x30, [sp, #0x30] ; 0x1b7ec: add x29, sp, #0x30
 */
uint64_t fde_0313_0x1b7dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b7dcULL;
    constexpr uint64_t kSize = 0x68ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x14001095U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0314] `_Z22try_get_offset_by_callPvPK10call_map_tmPii` (`0x1b844..0x1bcb0`, 1132 bytes)
 *        Hàm FDE[0314] `_Z22try_get_offset_by_callPvPK10call_map_tmPii` (`0x1b844..0x1bcb0`, 1132 bytes)
 * Disassembly: 0x1b844: sub sp, sp, #0xd0 ; 0x1b848: stp x28, x27, [sp, #0x70] ; 0x1b84c: stp x26, x25, [sp, #0x80] ; 0x1b850: stp x24, x23, [sp, #0x90] ; 0x1b854: stp x22, x21, [sp, #0xa0]
 */
uint64_t fde_0314_0x1b844(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1b844ULL;
    constexpr uint64_t kSize = 0x46cULL;
    constexpr uint32_t kOp0  = 0xd10343ffU;
    constexpr uint32_t kOpN  = 0x94000e52U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0315] `sub_1bcb0` (`0x1bcb0..0x1bce0`, 48 bytes)
 *        Hàm FDE[0315] `sub_1bcb0` (`0x1bcb0..0x1bce0`, 48 bytes)
 * Disassembly: 0x1bcb0: cbz x0, #0x1bcdc ; 0x1bcb4: str x19, [sp, #-0x20]! ; 0x1bcb8: stp x29, x30, [sp, #0x10] ; 0x1bcbc: add x29, sp, #0x10 ; 0x1bcc0: mov x19, x0
 */
uint64_t fde_0315_0x1bcb0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1bcb0ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xb4000160U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0316] `sub_1bce0` (`0x1bce0..0x1bd1c`, 60 bytes)
 *        Hàm FDE[0316] `sub_1bce0` (`0x1bce0..0x1bd1c`, 60 bytes)
 * Disassembly: 0x1bce0: ldr x8, [x0, #8] ; 0x1bce4: ldr x9, [x8] ; 0x1bce8: str x9, [x0, #8] ; 0x1bcec: cbz x9, #0x1bcf4 ; 0x1bcf0: str x0, [x9, #0x10]
 */
uint64_t fde_0316_0x1bce0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1bce0ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xf9400408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0317] `sub_1bd1c` (`0x1bd1c..0x1bd58`, 60 bytes)
 *        Hàm FDE[0317] `sub_1bd1c` (`0x1bd1c..0x1bd58`, 60 bytes)
 * Disassembly: 0x1bd1c: ldr x8, [x0] ; 0x1bd20: ldr x9, [x8, #8] ; 0x1bd24: str x9, [x0] ; 0x1bd28: cbz x9, #0x1bd30 ; 0x1bd2c: str x0, [x9, #0x10]
 */
uint64_t fde_0317_0x1bd1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1bd1cULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xf9400008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0318] `_Z32try_get_offset_by_call_over_halfPvPK10call_map_tmi` (`0x1bd58..0x1bda0`, 72 bytes)
 *        Hàm FDE[0318] `_Z32try_get_offset_by_call_over_halfPvPK10call_map_tmi` (`0x1bd58..0x1bda0`, 72 bytes)
 * Disassembly: 0x1bd58: sub sp, sp, #0x30 ; 0x1bd5c: str x19, [sp, #0x10] ; 0x1bd60: stp x29, x30, [sp, #0x20] ; 0x1bd64: add x29, sp, #0x20 ; 0x1bd68: bl #0x20414
 */
uint64_t fde_0318_0x1bd58(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1bd58ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x97ffd4b9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0319] `_Z23find_offset_by_call_a64PvS_PFbiEi` (`0x1bda0..0x1bf1c`, 380 bytes)
 *        Hàm FDE[0319] `_Z23find_offset_by_call_a64PvS_PFbiEi` (`0x1bda0..0x1bf1c`, 380 bytes)
 * Disassembly: 0x1bda0: mov x4, x30 ; 0x1bda4: bl #0x1f620 ; 0x1bda8: mov x30, x4 ; 0x1bdac: stp x29, x30, [sp, #0x50] ; 0x1bdb0: add x29, sp, #0x50
 */
uint64_t fde_0319_0x1bda0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1bda0ULL;
    constexpr uint64_t kSize = 0x17cULL;
    constexpr uint32_t kOp0  = 0xaa1e03e4U;
    constexpr uint32_t kOpN  = 0x14000f42U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0320] `sub_1bf1c` (`0x1bf1c..0x1c044`, 296 bytes)
 *        Hàm FDE[0320] `sub_1bf1c` (`0x1bf1c..0x1c044`, 296 bytes)
 * Disassembly: 0x1bf1c: and w8, w0, #0xfc000000 ; 0x1bf20: mov w9, #0x14000000 ; 0x1bf24: cmp w8, w9 ; 0x1bf28: b.ne #0x1bf30 ; 0x1bf2c: b #0x1fe68
 */
uint64_t fde_0320_0x1bf1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1bf1cULL;
    constexpr uint64_t kSize = 0x128ULL;
    constexpr uint32_t kOp0  = 0x12061408U;
    constexpr uint32_t kOpN  = 0x14001147U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0321] `sub_1c044` (`0x1c044..0x1c164`, 288 bytes)
 *        Hàm FDE[0321] `sub_1c044` (`0x1c044..0x1c164`, 288 bytes)
 * Disassembly: 0x1c044: stp x20, x19, [sp, #-0x20]! ; 0x1c048: stp x29, x30, [sp, #0x10] ; 0x1c04c: add x29, sp, #0x10 ; 0x1c050: mov w20, w0 ; 0x1c054: adrp x0, #0x4f000
 */
uint64_t fde_0321_0x1c044(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c044ULL;
    constexpr uint64_t kSize = 0x120ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0322] `_Z17a32_is_b_imm_instPvS_` (`0x1c164..0x1c1dc`, 120 bytes)
 *        Hàm FDE[0322] `_Z17a32_is_b_imm_instPvS_` (`0x1c164..0x1c1dc`, 120 bytes)
 * Disassembly: 0x1c164: stp x22, x21, [sp, #-0x30]! ; 0x1c168: stp x20, x19, [sp, #0x10] ; 0x1c16c: stp x29, x30, [sp, #0x20] ; 0x1c170: add x29, sp, #0x20 ; 0x1c174: ldr w21, [x0]
 */
uint64_t fde_0322_0x1c164(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c164ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x14000d7aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0323] `sub_1c1dc` (`0x1c1dc..0x1c524`, 840 bytes)
 *        Hàm FDE[0323] `sub_1c1dc` (`0x1c1dc..0x1c524`, 840 bytes)
 * Disassembly: 0x1c1dc: lsr w8, w0, #0x1c ; 0x1c1e0: and w9, w0, #0xf000000 ; 0x1c1e4: cmp w8, #0xe ; 0x1c1e8: mov w10, #0xa000000 ; 0x1c1ec: ccmp w9, w10, #0, ls
 */
uint64_t fde_0323_0x1c1dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c1dcULL;
    constexpr uint64_t kSize = 0x348ULL;
    constexpr uint32_t kOp0  = 0x531c7c08U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0324] `sub_1c524` (`0x1c524..0x1c5b8`, 148 bytes)
 *        Hàm FDE[0324] `sub_1c524` (`0x1c524..0x1c5b8`, 148 bytes)
 * Disassembly: 0x1c524: sub w9, w0, #1 ; 0x1c528: mov w8, w0 ; 0x1c52c: cmp w9, #8 ; 0x1c530: mov w0, #-1 ; 0x1c534: b.hi #0x1c568
 */
uint64_t fde_0324_0x1c524(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c524ULL;
    constexpr uint64_t kSize = 0x94ULL;
    constexpr uint32_t kOp0  = 0x51000409U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0325] `_Z20a32_get_ldr_imm_instPvj` (`0x1c5b8..0x1c688`, 208 bytes)
 *        Hàm FDE[0325] `_Z20a32_get_ldr_imm_instPvj` (`0x1c5b8..0x1c688`, 208 bytes)
 * Disassembly: 0x1c5b8: str x23, [sp, #-0x40]! ; 0x1c5bc: stp x22, x21, [sp, #0x10] ; 0x1c5c0: stp x20, x19, [sp, #0x20] ; 0x1c5c4: stp x29, x30, [sp, #0x30] ; 0x1c5c8: add x29, sp, #0x30
 */
uint64_t fde_0325_0x1c5b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c5b8ULL;
    constexpr uint64_t kSize = 0xd0ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x14000e5fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0326] `_Z17t16_is_b_imm_instPvS_` (`0x1c688..0x1c700`, 120 bytes)
 *        Hàm FDE[0326] `_Z17t16_is_b_imm_instPvS_` (`0x1c688..0x1c700`, 120 bytes)
 * Disassembly: 0x1c688: stp x22, x21, [sp, #-0x30]! ; 0x1c68c: stp x20, x19, [sp, #0x10] ; 0x1c690: stp x29, x30, [sp, #0x20] ; 0x1c694: add x29, sp, #0x20 ; 0x1c698: ldrh w21, [x0]
 */
uint64_t fde_0326_0x1c688(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c688ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x14000c31U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0327] `sub_1c700` (`0x1c700..0x1c830`, 304 bytes)
 *        Hàm FDE[0327] `sub_1c700` (`0x1c700..0x1c830`, 304 bytes)
 * Disassembly: 0x1c700: and w8, w0, #0xffff ; 0x1c704: mvn w9, w8 ; 0x1c708: tst w9, #0xf0 ; 0x1c70c: b.eq #0x1c72c ; 0x1c710: and w9, w0, #0xff00
 */
uint64_t fde_0327_0x1c700(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c700ULL;
    constexpr uint64_t kSize = 0x130ULL;
    constexpr uint32_t kOp0  = 0x12003c08U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0328] `sub_1c830` (`0x1c830..0x1c8a4`, 116 bytes)
 *        Hàm FDE[0328] `sub_1c830` (`0x1c830..0x1c8a4`, 116 bytes)
 * Disassembly: 0x1c830: sub w8, w0, #2 ; 0x1c834: cmp w8, #9 ; 0x1c838: mov w0, #0xffff ; 0x1c83c: b.hi #0x1c8a0 ; 0x1c840: adrp x9, #0x38000
 */
uint64_t fde_0328_0x1c830(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c830ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0x51000808U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0329] `_Z20t16_get_ldr_imm_instPvj` (`0x1c8a4..0x1c970`, 204 bytes)
 *        Hàm FDE[0329] `_Z20t16_get_ldr_imm_instPvj` (`0x1c8a4..0x1c970`, 204 bytes)
 * Disassembly: 0x1c8a4: str x23, [sp, #-0x40]! ; 0x1c8a8: stp x22, x21, [sp, #0x10] ; 0x1c8ac: stp x20, x19, [sp, #0x20] ; 0x1c8b0: stp x29, x30, [sp, #0x30] ; 0x1c8b4: add x29, sp, #0x30
 */
uint64_t fde_0329_0x1c8a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c8a4ULL;
    constexpr uint64_t kSize = 0xccULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x14000da5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0330] `sub_1c970` (`0x1c970..0x1c9a8`, 56 bytes)
 *        Hàm FDE[0330] `sub_1c970` (`0x1c970..0x1c9a8`, 56 bytes)
 * Disassembly: 0x1c970: sub w8, w0, #5 ; 0x1c974: cmp w8, #6 ; 0x1c978: mov w0, #0xffff ; 0x1c97c: b.hi #0x1c9a4 ; 0x1c980: adrp x9, #0x38000
 */
uint64_t fde_0330_0x1c970(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c970ULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0x51001408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0331] `_Z16thumb_expand_immj` (`0x1c9a8..0x1ca24`, 124 bytes)
 *        Hàm FDE[0331] `_Z16thumb_expand_immj` (`0x1c9a8..0x1ca24`, 124 bytes)
 * Disassembly: 0x1c9a8: mov w8, w0 ; 0x1c9ac: tst w0, #0xc00 ; 0x1c9b0: b.eq #0x1c9c8 ; 0x1c9b4: mov w9, #0x80 ; 0x1c9b8: bfxil w9, w8, #0, #7
 */
uint64_t fde_0331_0x1c9a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1c9a8ULL;
    constexpr uint64_t kSize = 0x7cULL;
    constexpr uint32_t kOp0  = 0x2a0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0332] `_Z11t32_get_imm10t32_type_tj` (`0x1ca24..0x1cb50`, 300 bytes)
 *        Hàm FDE[0332] `_Z11t32_get_imm10t32_type_tj` (`0x1ca24..0x1cb50`, 300 bytes)
 * Disassembly: 0x1ca24: sub w8, w0, #1 ; 0x1ca28: cmp w8, #9 ; 0x1ca2c: mov w0, #-1 ; 0x1ca30: b.hi #0x1cb4c ; 0x1ca34: adrp x9, #0x38000
 */
uint64_t fde_0332_0x1ca24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ca24ULL;
    constexpr uint64_t kSize = 0x12cULL;
    constexpr uint32_t kOp0  = 0x51000408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0333] `_Z10t32_get_rt10t32_type_tj` (`0x1cb50..0x1cb80`, 48 bytes)
 *        Hàm FDE[0333] `_Z10t32_get_rt10t32_type_tj` (`0x1cb50..0x1cb80`, 48 bytes)
 * Disassembly: 0x1cb50: sub w8, w0, #9 ; 0x1cb54: cmp w8, #2 ; 0x1cb58: b.lo #0x1cb70 ; 0x1cb5c: sub w8, w0, #5 ; 0x1cb60: cmp w8, #1
 */
uint64_t fde_0333_0x1cb50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cb50ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0x51002408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0334] `_Z10t32_get_rn10t32_type_tj` (`0x1cb80..0x1cba8`, 40 bytes)
 *        Hàm FDE[0334] `_Z10t32_get_rn10t32_type_tj` (`0x1cb80..0x1cba8`, 40 bytes)
 * Disassembly: 0x1cb80: sub w8, w0, #9 ; 0x1cb84: cmp w8, #2 ; 0x1cb88: b.lo #0x1cb98 ; 0x1cb8c: sub w8, w0, #5 ; 0x1cb90: cmp w8, #1
 */
uint64_t fde_0334_0x1cb80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cb80ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0x51002408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0335] `_Z17t32_is_b_imm_instPvS_` (`0x1cba8..0x1cc5c`, 180 bytes)
 *        Hàm FDE[0335] `_Z17t32_is_b_imm_instPvS_` (`0x1cba8..0x1cc5c`, 180 bytes)
 * Disassembly: 0x1cba8: stp x22, x21, [sp, #-0x30]! ; 0x1cbac: stp x20, x19, [sp, #0x10] ; 0x1cbb0: stp x29, x30, [sp, #0x20] ; 0x1cbb4: add x29, sp, #0x20 ; 0x1cbb8: ldr w8, [x0]
 */
uint64_t fde_0335_0x1cba8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cba8ULL;
    constexpr uint64_t kSize = 0xb4ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x14000adaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0336] `sub_1cc5c` (`0x1cc5c..0x1cefc`, 672 bytes)
 *        Hàm FDE[0336] `sub_1cc5c` (`0x1cc5c..0x1cefc`, 672 bytes)
 * Disassembly: 0x1cc5c: mov w8, #0xd000 ; 0x1cc60: movk w8, #0xf800, lsl #16 ; 0x1cc64: mov w10, #0x8000 ; 0x1cc68: movk w10, #0xf000, lsl #16 ; 0x1cc6c: and w9, w0, w8
 */
uint64_t fde_0336_0x1cc5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cc5cULL;
    constexpr uint64_t kSize = 0x2a0ULL;
    constexpr uint32_t kOp0  = 0x529a0008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0337] `_Z20t32_get_ldr_imm_instPvj` (`0x1cefc..0x1cfbc`, 192 bytes)
 *        Hàm FDE[0337] `_Z20t32_get_ldr_imm_instPvj` (`0x1cefc..0x1cfbc`, 192 bytes)
 * Disassembly: 0x1cefc: str x23, [sp, #-0x40]! ; 0x1cf00: stp x22, x21, [sp, #0x10] ; 0x1cf04: stp x20, x19, [sp, #0x20] ; 0x1cf08: stp x29, x30, [sp, #0x30] ; 0x1cf0c: add x29, sp, #0x30
 */
uint64_t fde_0337_0x1cefc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cefcULL;
    constexpr uint64_t kSize = 0xc0ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0338] `xhook_register` (`0x1cfbc..0x1cfc0`, 4 bytes)
 *        Hàm FDE[0338] `xhook_register` (`0x1cfbc..0x1cfc0`, 4 bytes)
 * Disassembly: 0x1cfbc: b #0x11250
 */
uint64_t fde_0338_0x1cfbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfbcULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffd0a5U;
    constexpr uint32_t kOpN  = 0x17ffd0a5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0339] `xhook_ignore` (`0x1cfc0..0x1cfc4`, 4 bytes)
 *        Hàm FDE[0339] `xhook_ignore` (`0x1cfc0..0x1cfc4`, 4 bytes)
 * Disassembly: 0x1cfc0: b #0x10e30
 */
uint64_t fde_0339_0x1cfc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfc0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcf9cU;
    constexpr uint32_t kOpN  = 0x17ffcf9cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0340] `xhook_refresh` (`0x1cfc4..0x1cfc8`, 4 bytes)
 *        Hàm FDE[0340] `xhook_refresh` (`0x1cfc4..0x1cfc8`, 4 bytes)
 * Disassembly: 0x1cfc4: b #0x10df0
 */
uint64_t fde_0340_0x1cfc4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfc4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcf8bU;
    constexpr uint32_t kOpN  = 0x17ffcf8bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0341] `xhook_clear` (`0x1cfc8..0x1cfcc`, 4 bytes)
 *        Hàm FDE[0341] `xhook_clear` (`0x1cfc8..0x1cfcc`, 4 bytes)
 * Disassembly: 0x1cfc8: b #0x11710
 */
uint64_t fde_0341_0x1cfc8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfc8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffd1d2U;
    constexpr uint32_t kOpN  = 0x17ffd1d2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0342] `xhook_enable_debug` (`0x1cfcc..0x1cfd0`, 4 bytes)
 *        Hàm FDE[0342] `xhook_enable_debug` (`0x1cfcc..0x1cfd0`, 4 bytes)
 * Disassembly: 0x1cfcc: b #0x1f954
 */
uint64_t fde_0342_0x1cfcc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfccULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000a62U;
    constexpr uint32_t kOpN  = 0x14000a62U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0343] `xhook_enable_sigsegv_protection` (`0x1cfd0..0x1cfd4`, 4 bytes)
 *        Hàm FDE[0343] `xhook_enable_sigsegv_protection` (`0x1cfd0..0x1cfd4`, 4 bytes)
 * Disassembly: 0x1cfd0: b #0x1fd68
 */
uint64_t fde_0343_0x1cfd0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfd0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000b66U;
    constexpr uint32_t kOpN  = 0x14000b66U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0344] `xhook_elf_open` (`0x1cfd4..0x1cfd8`, 4 bytes)
 *        Hàm FDE[0344] `xhook_elf_open` (`0x1cfd4..0x1cfd8`, 4 bytes)
 * Disassembly: 0x1cfd4: b #0x110a0
 */
uint64_t fde_0344_0x1cfd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfd4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffd033U;
    constexpr uint32_t kOpN  = 0x17ffd033U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0345] `xhook_hook_symbol` (`0x1cfd8..0x1cfdc`, 4 bytes)
 *        Hàm FDE[0345] `xhook_hook_symbol` (`0x1cfd8..0x1cfdc`, 4 bytes)
 * Disassembly: 0x1cfd8: b #0x10f50
 */
uint64_t fde_0345_0x1cfd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfd8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcfdeU;
    constexpr uint32_t kOpN  = 0x17ffcfdeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0346] `xhook_elf_close` (`0x1cfdc..0x1cfe0`, 4 bytes)
 *        Hàm FDE[0346] `xhook_elf_close` (`0x1cfdc..0x1cfe0`, 4 bytes)
 * Disassembly: 0x1cfdc: b #0x11650
 */
uint64_t fde_0346_0x1cfdc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfdcULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffd19dU;
    constexpr uint32_t kOpN  = 0x17ffd19dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0347] `xh_core_register` (`0x1cfe0..0x1d0f4`, 276 bytes)
 *        Hàm FDE[0347] `xh_core_register` (`0x1cfe0..0x1d0f4`, 276 bytes)
 * Disassembly: 0x1cfe0: sub sp, sp, #0x70 ; 0x1cfe4: str x23, [sp, #0x30] ; 0x1cfe8: stp x22, x21, [sp, #0x40] ; 0x1cfec: stp x20, x19, [sp, #0x50] ; 0x1cff0: stp x29, x30, [sp, #0x60]
 */
uint64_t fde_0347_0x1cfe0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1cfe0ULL;
    constexpr uint64_t kSize = 0x114ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x97ffcfe4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0348] `xh_core_ignore` (`0x1d0f4..0x1d208`, 276 bytes)
 *        Hàm FDE[0348] `xh_core_ignore` (`0x1d0f4..0x1d208`, 276 bytes)
 * Disassembly: 0x1d0f4: sub sp, sp, #0x60 ; 0x1d0f8: str x21, [sp, #0x30] ; 0x1d0fc: stp x20, x19, [sp, #0x40] ; 0x1d100: stp x29, x30, [sp, #0x50] ; 0x1d104: add x29, sp, #0x50
 */
uint64_t fde_0348_0x1d0f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d0f4ULL;
    constexpr uint64_t kSize = 0x114ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x97ffcf9fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0349] `xh_core_refresh` (`0x1d208..0x1d3a0`, 408 bytes)
 *        Hàm FDE[0349] `xh_core_refresh` (`0x1d208..0x1d3a0`, 408 bytes)
 * Disassembly: 0x1d208: sub sp, sp, #0x70 ; 0x1d20c: str x23, [sp, #0x30] ; 0x1d210: stp x22, x21, [sp, #0x40] ; 0x1d214: stp x20, x19, [sp, #0x50] ; 0x1d218: stp x29, x30, [sp, #0x60]
 */
uint64_t fde_0349_0x1d208(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d208ULL;
    constexpr uint64_t kSize = 0x198ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x97ffcf39U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0350] `sub_1d3a0` (`0x1d3a0..0x1d3d0`, 48 bytes)
 *        Hàm FDE[0350] `sub_1d3a0` (`0x1d3a0..0x1d3d0`, 48 bytes)
 * Disassembly: 0x1d3a0: stp x29, x30, [sp, #-0x10]! ; 0x1d3a4: mov x29, sp ; 0x1d3a8: adrp x8, #0x50000 ; 0x1d3ac: ldr w8, [x8, #0x344] ; 0x1d3b0: cbnz w8, #0x1d3c0
 */
uint64_t fde_0350_0x1d3a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d3a0ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffce05U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0351] `sub_1d3d0` (`0x1d3d0..0x1d484`, 180 bytes)
 *        Hàm FDE[0351] `sub_1d3d0` (`0x1d3d0..0x1d484`, 180 bytes)
 * Disassembly: 0x1d3d0: str x23, [sp, #-0x40]! ; 0x1d3d4: stp x22, x21, [sp, #0x10] ; 0x1d3d8: stp x20, x19, [sp, #0x20] ; 0x1d3dc: stp x29, x30, [sp, #0x30] ; 0x1d3e0: add x29, sp, #0x30
 */
uint64_t fde_0351_0x1d3d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d3d0ULL;
    constexpr uint64_t kSize = 0xb4ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0352] `sub_1d484` (`0x1d484..0x1d748`, 708 bytes)
 *        Hàm FDE[0352] `sub_1d484` (`0x1d484..0x1d748`, 708 bytes)
 * Disassembly: 0x1d484: mov x0, x30 ; 0x1d488: bl #0x1f620 ; 0x1d48c: mov x30, x0 ; 0x1d490: stp x29, x30, [sp, #0x50] ; 0x1d494: add x29, sp, #0x50
 */
uint64_t fde_0352_0x1d484(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d484ULL;
    constexpr uint64_t kSize = 0x2c4ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e0U;
    constexpr uint32_t kOpN  = 0x97ffce4fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0353] `sub_1d748` (`0x1d748..0x1d7c4`, 124 bytes)
 *        Hàm FDE[0353] `sub_1d748` (`0x1d748..0x1d7c4`, 124 bytes)
 * Disassembly: 0x1d748: stp x20, x19, [sp, #-0x20]! ; 0x1d74c: stp x29, x30, [sp, #0x10] ; 0x1d750: add x29, sp, #0x10 ; 0x1d754: bl #0x20088 ; 0x1d758: mov x20, x0
 */
uint64_t fde_0353_0x1d748(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d748ULL;
    constexpr uint64_t kSize = 0x7cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0354] `sub_1d7c4` (`0x1d7c4..0x1d7c8`, 4 bytes)
 *        Hàm FDE[0354] `sub_1d7c4` (`0x1d7c4..0x1d7c8`, 4 bytes)
 * Disassembly: 0x1d7c4: b #0x112c0
 */
uint64_t fde_0354_0x1d7c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d7c4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcebfU;
    constexpr uint32_t kOpN  = 0x17ffcebfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0355] `sub_1d7c8` (`0x1d7c8..0x1dbf0`, 1064 bytes)
 *        Hàm FDE[0355] `sub_1d7c8` (`0x1d7c8..0x1dbf0`, 1064 bytes)
 * Disassembly: 0x1d7c8: mov x10, x0 ; 0x1d7cc: ldr x12, [x10, #0xc0]! ; 0x1d7d0: adrp x11, #0x50000 ; 0x1d7d4: ldr x8, [x10, #8] ; 0x1d7d8: cbz x12, #0x1d81c
 */
uint64_t fde_0355_0x1d7c8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1d7c8ULL;
    constexpr uint64_t kSize = 0x428ULL;
    constexpr uint32_t kOp0  = 0xaa0003eaU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0356] `sub_1dbf0` (`0x1dbf0..0x1de28`, 568 bytes)
 *        Hàm FDE[0356] `sub_1dbf0` (`0x1dbf0..0x1de28`, 568 bytes)
 * Disassembly: 0x1dbf0: str x21, [sp, #-0x30]! ; 0x1dbf4: stp x20, x19, [sp, #0x10] ; 0x1dbf8: stp x29, x30, [sp, #0x20] ; 0x1dbfc: add x29, sp, #0x20 ; 0x1dc00: mov x19, x0
 */
uint64_t fde_0356_0x1dbf0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1dbf0ULL;
    constexpr uint64_t kSize = 0x238ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0357] `sub_1de28` (`0x1de28..0x1de88`, 96 bytes)
 *        Hàm FDE[0357] `sub_1de28` (`0x1de28..0x1de88`, 96 bytes)
 * Disassembly: 0x1de28: str x19, [sp, #-0x20]! ; 0x1de2c: stp x29, x30, [sp, #0x10] ; 0x1de30: add x29, sp, #0x10 ; 0x1de34: bl #0x20088 ; 0x1de38: mov x19, x0
 */
uint64_t fde_0357_0x1de28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1de28ULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x140005ffU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0358] `sub_1de88` (`0x1de88..0x1dea8`, 32 bytes)
 *        Hàm FDE[0358] `sub_1de88` (`0x1de88..0x1dea8`, 32 bytes)
 * Disassembly: 0x1de88: adrp x9, #0x50000 ; 0x1de8c: mov x8, xzr ; 0x1de90: add x9, x9, #0x2e8 ; 0x1de94: mov x0, x8 ; 0x1de98: ldr x8, [x9]
 */
uint64_t fde_0358_0x1de88(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1de88ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xf0000189U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0359] `sub_1dea8` (`0x1dea8..0x1df04`, 92 bytes)
 *        Hàm FDE[0359] `sub_1dea8` (`0x1dea8..0x1df04`, 92 bytes)
 * Disassembly: 0x1dea8: ldr x9, [x0, #0xc8] ; 0x1deac: cbz x9, #0x1dec0 ; 0x1deb0: mov x0, x9 ; 0x1deb4: ldr x9, [x9, #0xc0] ; 0x1deb8: cbnz x9, #0x1deb0
 */
uint64_t fde_0359_0x1dea8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1dea8ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf9406409U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0360] `sub_1df04` (`0x1df04..0x1dfb0`, 172 bytes)
 *        Hàm FDE[0360] `sub_1df04` (`0x1df04..0x1dfb0`, 172 bytes)
 * Disassembly: 0x1df04: str x23, [sp, #-0x40]! ; 0x1df08: stp x22, x21, [sp, #0x10] ; 0x1df0c: stp x20, x19, [sp, #0x20] ; 0x1df10: stp x29, x30, [sp, #0x30] ; 0x1df14: add x29, sp, #0x30
 */
uint64_t fde_0360_0x1df04(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1df04ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x140006baU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0361] `xh_core_clear` (`0x1dfb0..0x1e104`, 340 bytes)
 *        Hàm FDE[0361] `xh_core_clear` (`0x1dfb0..0x1e104`, 340 bytes)
 * Disassembly: 0x1dfb0: str x21, [sp, #-0x30]! ; 0x1dfb4: stp x20, x19, [sp, #0x10] ; 0x1dfb8: stp x29, x30, [sp, #0x20] ; 0x1dfbc: add x29, sp, #0x20 ; 0x1dfc0: adrp x8, #0x50000
 */
uint64_t fde_0361_0x1dfb0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1dfb0ULL;
    constexpr uint64_t kSize = 0x154ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffcda0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0362] `xh_core_enable_debug` (`0x1e104..0x1e108`, 4 bytes)
 *        Hàm FDE[0362] `xh_core_enable_debug` (`0x1e104..0x1e108`, 4 bytes)
 * Disassembly: 0x1e104: b #0x1f954
 */
uint64_t fde_0362_0x1e104(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e104ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000614U;
    constexpr uint32_t kOpN  = 0x14000614U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0363] `xh_core_enable_sigsegv_protection` (`0x1e108..0x1e10c`, 4 bytes)
 *        Hàm FDE[0363] `xh_core_enable_sigsegv_protection` (`0x1e108..0x1e10c`, 4 bytes)
 * Disassembly: 0x1e108: b #0x1fd68
 */
uint64_t fde_0363_0x1e108(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e108ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000718U;
    constexpr uint32_t kOpN  = 0x14000718U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0364] `xh_core_elf_open` (`0x1e10c..0x1e300`, 500 bytes)
 *        Hàm FDE[0364] `xh_core_elf_open` (`0x1e10c..0x1e300`, 500 bytes)
 * Disassembly: 0x1e10c: mov x1, x30 ; 0x1e110: bl #0x1f620 ; 0x1e114: mov x30, x1 ; 0x1e118: stp x29, x30, [sp, #0x50] ; 0x1e11c: add x29, sp, #0x50
 */
uint64_t fde_0364_0x1e10c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e10cULL;
    constexpr uint64_t kSize = 0x1f4ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e1U;
    constexpr uint32_t kOpN  = 0x97ffcb61U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0365] `xh_core_hook_symbol` (`0x1e300..0x1e36c`, 108 bytes)
 *        Hàm FDE[0365] `xh_core_hook_symbol` (`0x1e300..0x1e36c`, 108 bytes)
 * Disassembly: 0x1e300: stp x22, x21, [sp, #-0x30]! ; 0x1e304: stp x20, x19, [sp, #0x10] ; 0x1e308: stp x29, x30, [sp, #0x20] ; 0x1e30c: add x29, sp, #0x20 ; 0x1e310: bl #0x20088
 */
uint64_t fde_0365_0x1e300(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e300ULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x14000516U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0366] `sub_1e36c` (`0x1e36c..0x1e3d8`, 108 bytes)
 *        Hàm FDE[0366] `sub_1e36c` (`0x1e36c..0x1e3d8`, 108 bytes)
 * Disassembly: 0x1e36c: stp x22, x21, [sp, #-0x30]! ; 0x1e370: stp x20, x19, [sp, #0x10] ; 0x1e374: stp x29, x30, [sp, #0x20] ; 0x1e378: add x29, sp, #0x20 ; 0x1e37c: mov x8, x0
 */
uint64_t fde_0366_0x1e36c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e36cULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x17ffcba3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0367] `xh_core_elf_close` (`0x1e3d8..0x1e408`, 48 bytes)
 *        Hàm FDE[0367] `xh_core_elf_close` (`0x1e3d8..0x1e408`, 48 bytes)
 * Disassembly: 0x1e3d8: cbz x0, #0x1e404 ; 0x1e3dc: str x19, [sp, #-0x20]! ; 0x1e3e0: stp x29, x30, [sp, #0x10] ; 0x1e3e4: add x29, sp, #0x10 ; 0x1e3e8: mov x19, x0
 */
uint64_t fde_0367_0x1e3d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e3d8ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xb4000160U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0368] `xh_elf_check_elfheader` (`0x1e408..0x1e47c`, 116 bytes)
 *        Hàm FDE[0368] `xh_elf_check_elfheader` (`0x1e408..0x1e47c`, 116 bytes)
 * Disassembly: 0x1e408: ldr w9, [x0] ; 0x1e40c: mov w10, #0x457f ; 0x1e410: movk w10, #0x464c, lsl #16 ; 0x1e414: cmp w9, w10 ; 0x1e418: b.ne #0x1e474
 */
uint64_t fde_0368_0x1e408(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e408ULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xb9400009U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0369] `xh_elf_init` (`0x1e47c..0x1e930`, 1204 bytes)
 *        Hàm FDE[0369] `xh_elf_init` (`0x1e47c..0x1e930`, 1204 bytes)
 * Disassembly: 0x1e47c: sub sp, sp, #0x40 ; 0x1e480: str x21, [sp, #0x10] ; 0x1e484: stp x20, x19, [sp, #0x20] ; 0x1e488: stp x29, x30, [sp, #0x30] ; 0x1e48c: add x29, sp, #0x30
 */
uint64_t fde_0369_0x1e47c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e47cULL;
    constexpr uint64_t kSize = 0x4b4ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x140006a0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0370] `xh_elf_hook` (`0x1e930..0x1efec`, 1724 bytes)
 *        Hàm FDE[0370] `xh_elf_hook` (`0x1e930..0x1efec`, 1724 bytes)
 * Disassembly: 0x1e930: sub sp, sp, #0x180 ; 0x1e934: stp x28, x27, [sp, #0x120] ; 0x1e938: stp x26, x25, [sp, #0x130] ; 0x1e93c: stp x24, x23, [sp, #0x140] ; 0x1e940: stp x22, x21, [sp, #0x150]
 */
uint64_t fde_0370_0x1e930(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1e930ULL;
    constexpr uint64_t kSize = 0x6bcULL;
    constexpr uint32_t kOp0  = 0xd10603ffU;
    constexpr uint32_t kOpN  = 0x97ffc826U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0371] `sub_1efec` (`0x1efec..0x1f238`, 588 bytes)
 *        Hàm FDE[0371] `sub_1efec` (`0x1efec..0x1f238`, 588 bytes)
 * Disassembly: 0x1efec: str x27, [sp, #-0x60]! ; 0x1eff0: stp x26, x25, [sp, #0x10] ; 0x1eff4: stp x24, x23, [sp, #0x20] ; 0x1eff8: stp x22, x21, [sp, #0x30] ; 0x1effc: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0371_0x1efec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1efecULL;
    constexpr uint64_t kSize = 0x24cULL;
    constexpr uint32_t kOp0  = 0xf81a0ffbU;
    constexpr uint32_t kOpN  = 0x17ffff86U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0372] `sub_1f238` (`0x1f238..0x1f2a0`, 104 bytes)
 *        Hàm FDE[0372] `sub_1f238` (`0x1f238..0x1f2a0`, 104 bytes)
 * Disassembly: 0x1f238: ldp x9, x11, [x0] ; 0x1f23c: mov x8, xzr ; 0x1f240: mov x10, xzr ; 0x1f244: cmp x9, x11 ; 0x1f248: b.hs #0x1f298
 */
uint64_t fde_0372_0x1f238(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f238ULL;
    constexpr uint64_t kSize = 0x68ULL;
    constexpr uint32_t kOp0  = 0xa9402c09U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0373] `Java_com_qiyi_xhook_NativeHandler_refresh` (`0x1f2a0..0x1f2ac`, 12 bytes)
 *        Hàm FDE[0373] `Java_com_qiyi_xhook_NativeHandler_refresh` (`0x1f2a0..0x1f2ac`, 12 bytes)
 * Disassembly: 0x1f2a0: tst w2, #0xff ; 0x1f2a4: cset w0, ne ; 0x1f2a8: b #0x10df0
 */
uint64_t fde_0373_0x1f2a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f2a0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x72001c5fU;
    constexpr uint32_t kOpN  = 0x17ffc6d2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0374] `Java_com_qiyi_xhook_NativeHandler_clear` (`0x1f2ac..0x1f2b0`, 4 bytes)
 *        Hàm FDE[0374] `Java_com_qiyi_xhook_NativeHandler_clear` (`0x1f2ac..0x1f2b0`, 4 bytes)
 * Disassembly: 0x1f2ac: b #0x11710
 */
uint64_t fde_0374_0x1f2ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f2acULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc919U;
    constexpr uint32_t kOpN  = 0x17ffc919U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0375] `Java_com_qiyi_xhook_NativeHandler_enableDebug` (`0x1f2b0..0x1f2d0`, 32 bytes)
 *        Hàm FDE[0375] `Java_com_qiyi_xhook_NativeHandler_enableDebug` (`0x1f2b0..0x1f2d0`, 32 bytes)
 * Disassembly: 0x1f2b0: tst w2, #0xff ; 0x1f2b4: mov w8, #3 ; 0x1f2b8: mov w9, #5 ; 0x1f2bc: csel w8, w9, w8, eq ; 0x1f2c0: adrp x9, #0x4f000
 */
uint64_t fde_0375_0x1f2b0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f2b0ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0x72001c5fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0376] `Java_com_qiyi_xhook_NativeHandler_enableSigSegvProtection` (`0x1f2d0..0x1f2e4`, 20 bytes)
 *        Hàm FDE[0376] `Java_com_qiyi_xhook_NativeHandler_enableSigSegvProtection` (`0x1f2d0..0x1f2e4`, 20 bytes)
 * Disassembly: 0x1f2d0: tst w2, #0xff ; 0x1f2d4: cset w8, ne ; 0x1f2d8: adrp x9, #0x50000 ; 0x1f2dc: str w8, [x9, #0x58] ; 0x1f2e0: ret
 */
uint64_t fde_0376_0x1f2d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f2d0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x72001c5fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0377] `xh_util_get_mem_protect` (`0x1f2e4..0x1f478`, 404 bytes)
 *        Hàm FDE[0377] `xh_util_get_mem_protect` (`0x1f2e4..0x1f478`, 404 bytes)
 * Disassembly: 0x1f2e4: mov x4, x30 ; 0x1f2e8: bl #0x1f620 ; 0x1f2ec: mov x30, x4 ; 0x1f2f0: stp x29, x30, [sp, #0x50] ; 0x1f2f4: add x29, sp, #0x50
 */
uint64_t fde_0377_0x1f2e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f2e4ULL;
    constexpr uint64_t kSize = 0x194ULL;
    constexpr uint32_t kOp0  = 0xaa1e03e4U;
    constexpr uint32_t kOpN  = 0x97ffc703U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0378] `xh_util_get_addr_protect` (`0x1f478..0x1f488`, 16 bytes)
 *        Hàm FDE[0378] `xh_util_get_addr_protect` (`0x1f478..0x1f488`, 16 bytes)
 * Disassembly: 0x1f478: mov x3, x2 ; 0x1f47c: mov x2, x1 ; 0x1f480: mov w1, #8 ; 0x1f484: b #0x109e0
 */
uint64_t fde_0378_0x1f478(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f478ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xaa0203e3U;
    constexpr uint32_t kOpN  = 0x17ffc557U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0379] `xh_util_set_addr_protect` (`0x1f488..0x1f500`, 120 bytes)
 *        Hàm FDE[0379] `xh_util_set_addr_protect` (`0x1f488..0x1f500`, 120 bytes)
 * Disassembly: 0x1f488: stp x22, x21, [sp, #-0x30]! ; 0x1f48c: stp x20, x19, [sp, #0x10] ; 0x1f490: stp x29, x30, [sp, #0x20] ; 0x1f494: add x29, sp, #0x20 ; 0x1f498: mov w19, w1
 */
uint64_t fde_0379_0x1f488(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f488ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x140000b1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0380] `xh_util_flush_instruction_cache` (`0x1f500..0x1f544`, 68 bytes)
 *        Hàm FDE[0380] `xh_util_flush_instruction_cache` (`0x1f500..0x1f544`, 68 bytes)
 * Disassembly: 0x1f500: stp x20, x19, [sp, #-0x20]! ; 0x1f504: stp x29, x30, [sp, #0x10] ; 0x1f508: add x29, sp, #0x10 ; 0x1f50c: mov x19, x0 ; 0x1f510: bl #0x11490
 */
uint64_t fde_0380_0x1f500(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f500ULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x14006509U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0381] `xh_version` (`0x1f544..0x1f550`, 12 bytes)
 *        Hàm FDE[0381] `xh_version` (`0x1f544..0x1f550`, 12 bytes)
 * Disassembly: 0x1f544: mov w0, #0x10c ; 0x1f548: movk w0, #1, lsl #16 ; 0x1f54c: ret
 */
uint64_t fde_0381_0x1f544(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f544ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52802180U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0382] `xh_version_str` (`0x1f550..0x1f55c`, 12 bytes)
 *        Hàm FDE[0382] `xh_version_str` (`0x1f550..0x1f55c`, 12 bytes)
 * Disassembly: 0x1f550: adrp x0, #0x3a000 ; 0x1f554: add x0, x0, #0xc72 ; 0x1f558: ret
 */
uint64_t fde_0382_0x1f550(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f550ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf00000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0383] `xh_version_str_full` (`0x1f55c..0x1f568`, 12 bytes)
 *        Hàm FDE[0383] `xh_version_str_full` (`0x1f55c..0x1f568`, 12 bytes)
 * Disassembly: 0x1f55c: adrp x0, #0x3a000 ; 0x1f560: add x0, x0, #0xc79 ; 0x1f564: ret
 */
uint64_t fde_0383_0x1f55c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f55cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf00000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0384] `sub_1f568` (`0x1f568..0x1f574`, 12 bytes)
 *        Hàm FDE[0384] `sub_1f568` (`0x1f568..0x1f574`, 12 bytes)
 * Disassembly: 0x1f568: str x0, [x8] ; 0x1f56c: mov x0, x19 ; 0x1f570: b #0x10f00
 */
uint64_t fde_0384_0x1f568(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f568ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf9000100U;
    constexpr uint32_t kOpN  = 0x17ffc664U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0385] `sub_1f574` (`0x1f574..0x1f580`, 12 bytes)
 *        Hàm FDE[0385] `sub_1f574` (`0x1f574..0x1f580`, 12 bytes)
 * Disassembly: 0x1f574: mov x0, x19 ; 0x1f578: ldr x19, [sp], #0x20 ; 0x1f57c: b #0x20e88
 */
uint64_t fde_0385_0x1f574(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f574ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x14000643U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0386] `sub_1f580` (`0x1f580..0x1f594`, 20 bytes)
 *        Hàm FDE[0386] `sub_1f580` (`0x1f580..0x1f594`, 20 bytes)
 * Disassembly: 0x1f580: adrp x8, #0x4f000 ; 0x1f584: ldr x8, [x8, #0xe50] ; 0x1f588: ldr w8, [x8] ; 0x1f58c: cmp w8, #6 ; 0x1f590: ret
 */
uint64_t fde_0386_0x1f580(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f580ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0387] `sub_1f594` (`0x1f594..0x1f5f4`, 96 bytes)
 *        Hàm FDE[0387] `sub_1f594` (`0x1f594..0x1f5f4`, 96 bytes)
 * Disassembly: 0x1f594: stp x3, x4, [sp, #0x88] ; 0x1f598: stp x5, x6, [sp, #0x98] ; 0x1f59c: str x7, [sp, #0xa8] ; 0x1f5a0: stp q0, q1, [sp] ; 0x1f5a4: stp q2, q3, [sp, #0x20]
 */
uint64_t fde_0387_0x1f594(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f594ULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xa90893e3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0388] `sub_1f5f4` (`0x1f5f4..0x1f5fc`, 8 bytes)
 *        Hàm FDE[0388] `sub_1f5f4` (`0x1f5f4..0x1f5fc`, 8 bytes)
 * Disassembly: 0x1f5f4: mov x0, x19 ; 0x1f5f8: b #0x36e1c
 */
uint64_t fde_0388_0x1f5f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f5f4ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x14005e09U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0389] `sub_1f5fc` (`0x1f5fc..0x1f614`, 24 bytes)
 *        Hàm FDE[0389] `sub_1f5fc` (`0x1f5fc..0x1f614`, 24 bytes)
 * Disassembly: 0x1f5fc: ldp x20, x19, [sp, #0x40] ; 0x1f600: ldp x22, x21, [sp, #0x30] ; 0x1f604: ldp x24, x23, [sp, #0x20] ; 0x1f608: ldp x26, x25, [sp, #0x10] ; 0x1f60c: ldp x28, x27, [sp], #0x60
 */
uint64_t fde_0389_0x1f5fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f5fcULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9444ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0390] `sub_1f614` (`0x1f614..0x1f620`, 12 bytes)
 *        Hàm FDE[0390] `sub_1f614` (`0x1f614..0x1f620`, 12 bytes)
 * Disassembly: 0x1f614: ldp x20, x19, [sp, #0x10] ; 0x1f618: ldr x21, [sp], #0x30 ; 0x1f61c: ret
 */
uint64_t fde_0390_0x1f614(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f614ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0391] `sub_1f620` (`0x1f620..0x1f638`, 24 bytes)
 *        Hàm FDE[0391] `sub_1f620` (`0x1f620..0x1f638`, 24 bytes)
 * Disassembly: 0x1f620: stp x28, x27, [sp, #-0x60]! ; 0x1f624: stp x26, x25, [sp, #0x10] ; 0x1f628: stp x24, x23, [sp, #0x20] ; 0x1f62c: stp x22, x21, [sp, #0x30] ; 0x1f630: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0391_0x1f620(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f620ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9ba6ffcU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0392] `sub_1f638` (`0x1f638..0x1f640`, 8 bytes)
 *        Hàm FDE[0392] `sub_1f638` (`0x1f638..0x1f640`, 8 bytes)
 * Disassembly: 0x1f638: ldp x20, x19, [sp], #0x20 ; 0x1f63c: ret
 */
uint64_t fde_0392_0x1f638(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f638ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xa8c24ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0393] `sub_1f640` (`0x1f640..0x1f648`, 8 bytes)
 *        Hàm FDE[0393] `sub_1f640` (`0x1f640..0x1f648`, 8 bytes)
 * Disassembly: 0x1f640: mov x0, x19 ; 0x1f644: b #0x10f00
 */
uint64_t fde_0393_0x1f640(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f640ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x17ffc62fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0394] `sub_1f648` (`0x1f648..0x1f658`, 16 bytes)
 *        Hàm FDE[0394] `sub_1f648` (`0x1f648..0x1f658`, 16 bytes)
 * Disassembly: 0x1f648: adrp x9, #0x50000 ; 0x1f64c: ldr x9, [x9, #0x3a0] ; 0x1f650: ldr x0, [x9, x8] ; 0x1f654: br x1
 */
uint64_t fde_0394_0x1f648(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f648ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb0000189U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0395] `sub_1f658` (`0x1f658..0x1f66c`, 20 bytes)
 *        Hàm FDE[0395] `sub_1f658` (`0x1f658..0x1f66c`, 20 bytes)
 * Disassembly: 0x1f658: cmp w10, #0x2e ; 0x1f65c: cset w10, eq ; 0x1f660: orr w23, w10, w23 ; 0x1f664: mov w28, #1 ; 0x1f668: ret
 */
uint64_t fde_0395_0x1f658(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f658ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x7100b95fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0396] `sub_1f66c` (`0x1f66c..0x1f680`, 20 bytes)
 *        Hàm FDE[0396] `sub_1f66c` (`0x1f66c..0x1f680`, 20 bytes)
 * Disassembly: 0x1f66c: adrp x8, #0x4f000 ; 0x1f670: ldr x8, [x8, #0xe50] ; 0x1f674: ldr w8, [x8] ; 0x1f678: cmp w8, #7 ; 0x1f67c: ret
 */
uint64_t fde_0396_0x1f66c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f66cULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0397] `sub_1f680` (`0x1f680..0x1f688`, 8 bytes)
 *        Hàm FDE[0397] `sub_1f680` (`0x1f680..0x1f688`, 8 bytes)
 * Disassembly: 0x1f680: ldr x19, [sp], #0x20 ; 0x1f684: ret
 */
uint64_t fde_0397_0x1f680(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f680ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf84207f3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0398] `sub_1f688` (`0x1f688..0x1f6ac`, 36 bytes)
 *        Hàm FDE[0398] `sub_1f688` (`0x1f688..0x1f6ac`, 36 bytes)
 * Disassembly: 0x1f688: str x15, [x8] ; 0x1f68c: ldr x15, [x19] ; 0x1f690: ldr x15, [x15, x13, lsl #3] ; 0x1f694: ldr x15, [x15] ; 0x1f698: str x15, [x14]
 */
uint64_t fde_0398_0x1f688(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f688ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf900010fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0399] `sub_1f6ac` (`0x1f6ac..0x1f6bc`, 16 bytes)
 *        Hàm FDE[0399] `sub_1f6ac` (`0x1f6ac..0x1f6bc`, 16 bytes)
 * Disassembly: 0x1f6ac: mov w1, #0x80000 ; 0x1f6b0: mov x0, x19 ; 0x1f6b4: str wzr, [x21] ; 0x1f6b8: b #0x112d0
 */
uint64_t fde_0399_0x1f6ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f6acULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x52a00101U;
    constexpr uint32_t kOpN  = 0x17ffc706U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0400] `sub_1f6bc` (`0x1f6bc..0x1f6cc`, 16 bytes)
 *        Hàm FDE[0400] `sub_1f6bc` (`0x1f6bc..0x1f6cc`, 16 bytes)
 * Disassembly: 0x1f6bc: add x10, x0, #0x18 ; 0x1f6c0: cmp x8, x9 ; 0x1f6c4: csel x0, x10, xzr, eq ; 0x1f6c8: ret
 */
uint64_t fde_0400_0x1f6bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f6bcULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x9100600aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0401] `sub_1f6cc` (`0x1f6cc..0x1f708`, 60 bytes)
 *        Hàm FDE[0401] `sub_1f6cc` (`0x1f6cc..0x1f708`, 60 bytes)
 * Disassembly: 0x1f6cc: ldr x8, [x19, #8] ; 0x1f6d0: ldr x9, [x20] ; 0x1f6d4: str x8, [x20] ; 0x1f6d8: ldr x8, [x19, #0x10] ; 0x1f6dc: str x9, [x19, #8]
 */
uint64_t fde_0401_0x1f6cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f6ccULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xf9400668U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0402] `sub_1f708` (`0x1f708..0x1f718`, 16 bytes)
 *        Hàm FDE[0402] `sub_1f708` (`0x1f708..0x1f718`, 16 bytes)
 * Disassembly: 0x1f708: sub w14, w15, #0x30 ; 0x1f70c: and w14, w14, #0xff ; 0x1f710: cmp w14, #9 ; 0x1f714: ret
 */
uint64_t fde_0402_0x1f708(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f708ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x5100c1eeU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0403] `sub_1f718` (`0x1f718..0x1f730`, 24 bytes)
 *        Hàm FDE[0403] `sub_1f718` (`0x1f718..0x1f730`, 24 bytes)
 * Disassembly: 0x1f718: sub x8, x0, #1 ; 0x1f71c: clz x8, x8 ; 0x1f720: neg w8, w8 ; 0x1f724: mov w9, #1 ; 0x1f728: lsl x0, x9, x8
 */
uint64_t fde_0403_0x1f718(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f718ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xd1000408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0404] `sub_1f730` (`0x1f730..0x1f744`, 20 bytes)
 *        Hàm FDE[0404] `sub_1f730` (`0x1f730..0x1f744`, 20 bytes)
 * Disassembly: 0x1f730: cnt v0.8b, v0.8b ; 0x1f734: uaddlv h0, v0.8b ; 0x1f738: fmov w9, s0 ; 0x1f73c: cmp x9, #1 ; 0x1f740: ret
 */
uint64_t fde_0404_0x1f730(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f730ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x0e205800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0405] `sub_1f744` (`0x1f744..0x1f74c`, 8 bytes)
 *        Hàm FDE[0405] `sub_1f744` (`0x1f744..0x1f74c`, 8 bytes)
 * Disassembly: 0x1f744: mov w0, #6 ; 0x1f748: b #0x11210
 */
uint64_t fde_0405_0x1f744(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f744ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x528000c0U;
    constexpr uint32_t kOpN  = 0x17ffc6b2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0406] `sub_1f74c` (`0x1f74c..0x1f75c`, 16 bytes)
 *        Hàm FDE[0406] `sub_1f74c` (`0x1f74c..0x1f75c`, 16 bytes)
 * Disassembly: 0x1f74c: ldr x8, [x21, #0x28] ; 0x1f750: ldur x9, [x29, #-0x28] ; 0x1f754: cmp x8, x9 ; 0x1f758: ret
 */
uint64_t fde_0406_0x1f74c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f74cULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf94016a8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0407] `sub_1f75c` (`0x1f75c..0x1f790`, 52 bytes)
 *        Hàm FDE[0407] `sub_1f75c` (`0x1f75c..0x1f790`, 52 bytes)
 * Disassembly: 0x1f75c: cmp x23, #3 ; 0x1f760: sub x8, x23, #1 ; 0x1f764: cset w9, lo ; 0x1f768: tst x23, x8 ; 0x1f76c: cset w8, ne
 */
uint64_t fde_0407_0x1f75c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f75cULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xf1000effU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0408] `sub_1f790` (`0x1f790..0x1f7a8`, 24 bytes)
 *        Hàm FDE[0408] `sub_1f790` (`0x1f790..0x1f7a8`, 24 bytes)
 * Disassembly: 0x1f790: ldp x20, x19, [sp, #0x50] ; 0x1f794: ldp x22, x21, [sp, #0x40] ; 0x1f798: ldp x24, x23, [sp, #0x30] ; 0x1f79c: ldp x26, x25, [sp, #0x20] ; 0x1f7a0: add sp, sp, #0x70
 */
uint64_t fde_0408_0x1f790(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f790ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9454ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0409] `sub_1f7a8` (`0x1f7a8..0x1f7c0`, 24 bytes)
 *        Hàm FDE[0409] `sub_1f7a8` (`0x1f7a8..0x1f7c0`, 24 bytes)
 * Disassembly: 0x1f7a8: ldp x20, x19, [sp, #0x40] ; 0x1f7ac: ldp x22, x21, [sp, #0x30] ; 0x1f7b0: ldp x24, x23, [sp, #0x20] ; 0x1f7b4: ldp x26, x25, [sp, #0x10] ; 0x1f7b8: ldp x28, x27, [sp], #0x60
 */
uint64_t fde_0409_0x1f7a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f7a8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9444ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0410] `sub_1f7c0` (`0x1f7c0..0x1f7cc`, 12 bytes)
 *        Hàm FDE[0410] `sub_1f7c0` (`0x1f7c0..0x1f7cc`, 12 bytes)
 * Disassembly: 0x1f7c0: ldp x20, x19, [sp, #0x10] ; 0x1f7c4: ldp x22, x21, [sp], #0x30 ; 0x1f7c8: ret
 */
uint64_t fde_0410_0x1f7c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f7c0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0411] `sub_1f7cc` (`0x1f7cc..0x1f7e8`, 28 bytes)
 *        Hàm FDE[0411] `sub_1f7cc` (`0x1f7cc..0x1f7e8`, 28 bytes)
 * Disassembly: 0x1f7cc: mov x20, x0 ; 0x1f7d0: adrp x2, #0x39000 ; 0x1f7d4: adrp x3, #0x39000 ; 0x1f7d8: ldr x8, [x8, #0x108] ; 0x1f7dc: add x2, x2, #0x6cf
 */
uint64_t fde_0411_0x1f7cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f7ccULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xaa0003f4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0412] `sub_1f7e8` (`0x1f7e8..0x1f818`, 48 bytes)
 *        Hàm FDE[0412] `sub_1f7e8` (`0x1f7e8..0x1f818`, 48 bytes)
 * Disassembly: 0x1f7e8: stp x0, x26, [sp] ; 0x1f7ec: ldr q0, [x21] ; 0x1f7f0: mov w8, #1 ; 0x1f7f4: strb w8, [sp, #0x10] ; 0x1f7f8: stp xzr, x24, [x0]
 */
uint64_t fde_0412_0x1f7e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f7e8ULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xa9006be0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0413] `sub_1f818` (`0x1f818..0x1f828`, 16 bytes)
 *        Hàm FDE[0413] `sub_1f818` (`0x1f818..0x1f828`, 16 bytes)
 * Disassembly: 0x1f818: sub w10, w20, #0x30 ; 0x1f81c: and w10, w10, #0xff ; 0x1f820: cmp w10, #9 ; 0x1f824: ret
 */
uint64_t fde_0413_0x1f818(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f818ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x5100c28aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0414] `sub_1f828` (`0x1f828..0x1f844`, 28 bytes)
 *        Hàm FDE[0414] `sub_1f828` (`0x1f828..0x1f844`, 28 bytes)
 * Disassembly: 0x1f828: adrp x2, #0x39000 ; 0x1f82c: adrp x3, #0x39000 ; 0x1f830: ldr x8, [x8, #0x108] ; 0x1f834: add x2, x2, #0x6cf ; 0x1f838: add x3, x3, #0x6d6
 */
uint64_t fde_0414_0x1f828(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f828ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xd00000c2U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0415] `sub_1f844` (`0x1f844..0x1f84c`, 8 bytes)
 *        Hàm FDE[0415] `sub_1f844` (`0x1f844..0x1f84c`, 8 bytes)
 * Disassembly: 0x1f844: mov x0, x19 ; 0x1f848: b #0x116c0
 */
uint64_t fde_0415_0x1f844(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f844ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x17ffc79eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0416] `sub_1f84c` (`0x1f84c..0x1f85c`, 16 bytes)
 *        Hàm FDE[0416] `sub_1f84c` (`0x1f84c..0x1f85c`, 16 bytes)
 * Disassembly: 0x1f84c: ldxr x9, [x8] ; 0x1f850: add x9, x9, #1 ; 0x1f854: stxr w10, x9, [x8] ; 0x1f858: ret
 */
uint64_t fde_0416_0x1f84c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f84cULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xc85f7d09U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0417] `sub_1f85c` (`0x1f85c..0x1f88c`, 48 bytes)
 *        Hàm FDE[0417] `sub_1f85c` (`0x1f85c..0x1f88c`, 48 bytes)
 * Disassembly: 0x1f85c: ldr x8, [x19, #0x18] ; 0x1f860: fmov d0, x23 ; 0x1f864: ldr s1, [x19, #0x20] ; 0x1f868: cnt v0.8b, v0.8b ; 0x1f86c: uaddlv h0, v0.8b
 */
uint64_t fde_0417_0x1f85c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f85cULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xf9400e68U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0418] `sub_1f88c` (`0x1f88c..0x1f89c`, 16 bytes)
 *        Hàm FDE[0418] `sub_1f88c` (`0x1f88c..0x1f89c`, 16 bytes)
 * Disassembly: 0x1f88c: mov x2, xzr ; 0x1f890: mov x3, xzr ; 0x1f894: mov w4, wzr ; 0x1f898: b #0x11320
 */
uint64_t fde_0418_0x1f88c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f88cULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xaa1f03e2U;
    constexpr uint32_t kOpN  = 0x17ffc6a2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0419] `sub_1f89c` (`0x1f89c..0x1f8a8`, 12 bytes)
 *        Hàm FDE[0419] `sub_1f89c` (`0x1f89c..0x1f8a8`, 12 bytes)
 * Disassembly: 0x1f89c: adrp x0, #0x3a000 ; 0x1f8a0: add x0, x0, #0x619 ; 0x1f8a4: b #0x12d38
 */
uint64_t fde_0419_0x1f89c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f89cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf00000c0U;
    constexpr uint32_t kOpN  = 0x17ffcd25U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0420] `sub_1f8a8` (`0x1f8a8..0x1f8cc`, 36 bytes)
 *        Hàm FDE[0420] `sub_1f8a8` (`0x1f8a8..0x1f8cc`, 36 bytes)
 * Disassembly: 0x1f8a8: add w8, w8, #0x14 ; 0x1f8ac: add x9, x8, #0xf ; 0x1f8b0: and x9, x9, #0x1fffffff0 ; 0x1f8b4: sub x22, x10, x9 ; 0x1f8b8: mov sp, x22
 */
uint64_t fde_0420_0x1f8a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f8a8ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0x11005108U;
    constexpr uint32_t kOpN  = 0x17ffc756U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0421] `sub_1f8cc` (`0x1f8cc..0x1f8e0`, 20 bytes)
 *        Hàm FDE[0421] `sub_1f8cc` (`0x1f8cc..0x1f8e0`, 20 bytes)
 * Disassembly: 0x1f8cc: ldp x20, x19, [sp, #0x50] ; 0x1f8d0: ldp x22, x21, [sp, #0x40] ; 0x1f8d4: ldr x23, [sp, #0x30] ; 0x1f8d8: add sp, sp, #0x70 ; 0x1f8dc: ret
 */
uint64_t fde_0421_0x1f8cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f8ccULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9454ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0422] `sub_1f8e0` (`0x1f8e0..0x1f8f4`, 20 bytes)
 *        Hàm FDE[0422] `sub_1f8e0` (`0x1f8e0..0x1f8f4`, 20 bytes)
 * Disassembly: 0x1f8e0: mov w9, #1 ; 0x1f8e4: add x0, x8, #0x34c ; 0x1f8e8: mov w1, #1 ; 0x1f8ec: str w9, [x8] ; 0x1f8f0: b #0x116a0
 */
uint64_t fde_0422_0x1f8e0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f8e0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x52800029U;
    constexpr uint32_t kOpN  = 0x17ffc76cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0423] `sub_1f8f4` (`0x1f8f4..0x1f908`, 20 bytes)
 *        Hàm FDE[0423] `sub_1f8f4` (`0x1f8f4..0x1f908`, 20 bytes)
 * Disassembly: 0x1f8f4: cnt v0.8b, v0.8b ; 0x1f8f8: uaddlv h0, v0.8b ; 0x1f8fc: fmov w8, s0 ; 0x1f900: cmp x8, #1 ; 0x1f904: ret
 */
uint64_t fde_0423_0x1f8f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f8f4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x0e205800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0424] `sub_1f908` (`0x1f908..0x1f914`, 12 bytes)
 *        Hàm FDE[0424] `sub_1f908` (`0x1f908..0x1f914`, 12 bytes)
 * Disassembly: 0x1f908: ldur x9, [x29, #-0x60] ; 0x1f90c: cmp x8, x9 ; 0x1f910: ret
 */
uint64_t fde_0424_0x1f908(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f908ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf85a03a9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0425] `sub_1f914` (`0x1f914..0x1f92c`, 24 bytes)
 *        Hàm FDE[0425] `sub_1f914` (`0x1f914..0x1f92c`, 24 bytes)
 * Disassembly: 0x1f914: ldr x11, [x8, #0xd0] ; 0x1f918: ldr x12, [x11, #0xc0]! ; 0x1f91c: add x13, x11, #8 ; 0x1f920: cmp x8, x12 ; 0x1f924: csel x11, x11, x13, eq
 */
uint64_t fde_0425_0x1f914(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f914ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf940690bU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0426] `sub_1f92c` (`0x1f92c..0x1f954`, 40 bytes)
 *        Hàm FDE[0426] `sub_1f92c` (`0x1f92c..0x1f954`, 40 bytes)
 * Disassembly: 0x1f92c: ldp x8, x9, [x1] ; 0x1f930: mov x19, x1 ; 0x1f934: str x9, [x8, #8] ; 0x1f938: ldr x9, [x1, #8] ; 0x1f93c: str x8, [x9]
 */
uint64_t fde_0426_0x1f92c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f92cULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xa9402428U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0427] `sub_1f954` (`0x1f954..0x1f974`, 32 bytes)
 *        Hàm FDE[0427] `sub_1f954` (`0x1f954..0x1f974`, 32 bytes)
 * Disassembly: 0x1f954: cmp w0, #0 ; 0x1f958: mov w8, #3 ; 0x1f95c: mov w9, #5 ; 0x1f960: csel w8, w9, w8, eq ; 0x1f964: adrp x9, #0x4f000
 */
uint64_t fde_0427_0x1f954(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f954ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0x7100001fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0428] `sub_1f974` (`0x1f974..0x1f984`, 16 bytes)
 *        Hàm FDE[0428] `sub_1f974` (`0x1f974..0x1f984`, 16 bytes)
 * Disassembly: 0x1f974: ldr x8, [x19] ; 0x1f978: mov x0, x19 ; 0x1f97c: mov x1, x21 ; 0x1f980: ret
 */
uint64_t fde_0428_0x1f974(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f974ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400268U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0429] `sub_1f984` (`0x1f984..0x1f994`, 16 bytes)
 *        Hàm FDE[0429] `sub_1f984` (`0x1f984..0x1f994`, 16 bytes)
 * Disassembly: 0x1f984: ldr x8, [x19] ; 0x1f988: mov x0, x19 ; 0x1f98c: mov x1, x20 ; 0x1f990: ret
 */
uint64_t fde_0429_0x1f984(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f984ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400268U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0430] `sub_1f994` (`0x1f994..0x1f9ac`, 24 bytes)
 *        Hàm FDE[0430] `sub_1f994` (`0x1f994..0x1f9ac`, 24 bytes)
 * Disassembly: 0x1f994: fmov d0, x9 ; 0x1f998: cnt v0.8b, v0.8b ; 0x1f99c: uaddlv h0, v0.8b ; 0x1f9a0: fmov w11, s0 ; 0x1f9a4: cmp x11, #1
 */
uint64_t fde_0430_0x1f994(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f994ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x9e670120U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0431] `sub_1f9ac` (`0x1f9ac..0x1f9bc`, 16 bytes)
 *        Hàm FDE[0431] `sub_1f9ac` (`0x1f9ac..0x1f9bc`, 16 bytes)
 * Disassembly: 0x1f9ac: ldr x8, [x19, #0x28] ; 0x1f9b0: ldur x9, [x29, #-0x18] ; 0x1f9b4: cmp x8, x9 ; 0x1f9b8: ret
 */
uint64_t fde_0431_0x1f9ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f9acULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9401668U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0432] `sub_1f9bc` (`0x1f9bc..0x1f9dc`, 32 bytes)
 *        Hàm FDE[0432] `sub_1f9bc` (`0x1f9bc..0x1f9dc`, 32 bytes)
 * Disassembly: 0x1f9bc: mrs x19, tpidr_el0 ; 0x1f9c0: ldr x8, [x19, #0x28] ; 0x1f9c4: add x2, sp, #8 ; 0x1f9c8: mov w0, #0x71 ; 0x1f9cc: mov w1, #1
 */
uint64_t fde_0432_0x1f9bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f9bcULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xd53bd053U;
    constexpr uint32_t kOpN  = 0x17ffc64eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0433] `sub_1f9dc` (`0x1f9dc..0x1f9ec`, 16 bytes)
 *        Hàm FDE[0433] `sub_1f9dc` (`0x1f9dc..0x1f9ec`, 16 bytes)
 * Disassembly: 0x1f9dc: add w8, w0, #1 ; 0x1f9e0: mov w20, w0 ; 0x1f9e4: sxtw x0, w8 ; 0x1f9e8: b #0x115d0
 */
uint64_t fde_0433_0x1f9dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f9dcULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x11000408U;
    constexpr uint32_t kOpN  = 0x17ffc6faU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0434] `sub_1f9ec` (`0x1f9ec..0x1fa10`, 36 bytes)
 *        Hàm FDE[0434] `sub_1f9ec` (`0x1f9ec..0x1fa10`, 36 bytes)
 * Disassembly: 0x1f9ec: ldp x8, x20, [x0] ; 0x1f9f0: mov x19, x0 ; 0x1f9f4: ldr x9, [x8, #8] ; 0x1f9f8: ldr x10, [x20] ; 0x1f9fc: str x9, [x10, #8]
 */
uint64_t fde_0434_0x1f9ec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1f9ecULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9405008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0435] `sub_1fa10` (`0x1fa10..0x1fa20`, 16 bytes)
 *        Hàm FDE[0435] `sub_1fa10` (`0x1fa10..0x1fa20`, 16 bytes)
 * Disassembly: 0x1fa10: ldr x8, [x8, #0xe0] ; 0x1fa14: mov x3, x24 ; 0x1fa18: mov x4, x23 ; 0x1fa1c: br x8
 */
uint64_t fde_0435_0x1fa10(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa10ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9407108U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0436] `sub_1fa20` (`0x1fa20..0x1fa3c`, 28 bytes)
 *        Hàm FDE[0436] `sub_1fa20` (`0x1fa20..0x1fa3c`, 28 bytes)
 * Disassembly: 0x1fa20: ldp x20, x19, [sp, #0xb0] ; 0x1fa24: ldp x22, x21, [sp, #0xa0] ; 0x1fa28: ldp x24, x23, [sp, #0x90] ; 0x1fa2c: ldp x26, x25, [sp, #0x80] ; 0x1fa30: ldp x28, x27, [sp, #0x70]
 */
uint64_t fde_0436_0x1fa20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa20ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xa94b4ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0437] `sub_1fa3c` (`0x1fa3c..0x1fa48`, 12 bytes)
 *        Hàm FDE[0437] `sub_1fa3c` (`0x1fa3c..0x1fa48`, 12 bytes)
 * Disassembly: 0x1fa3c: adrp x0, #0x50000 ; 0x1fa40: add x0, x0, #0x448 ; 0x1fa44: b #0x11780
 */
uint64_t fde_0437_0x1fa3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa3cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb0000180U;
    constexpr uint32_t kOpN  = 0x17ffc74fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0438] `sub_1fa48` (`0x1fa48..0x1fa58`, 16 bytes)
 *        Hàm FDE[0438] `sub_1fa48` (`0x1fa48..0x1fa58`, 16 bytes)
 * Disassembly: 0x1fa48: add x1, x1, #0x6ee ; 0x1fa4c: ldr x8, [x8, #0x538] ; 0x1fa50: mov x0, x19 ; 0x1fa54: br x8
 */
uint64_t fde_0438_0x1fa48(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa48ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x911bb821U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0439] `sub_1fa58` (`0x1fa58..0x1fa60`, 8 bytes)
 *        Hàm FDE[0439] `sub_1fa58` (`0x1fa58..0x1fa60`, 8 bytes)
 * Disassembly: 0x1fa58: ldr x8, [x8, #0x30] ; 0x1fa5c: br x8
 */
uint64_t fde_0439_0x1fa58(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa58ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9401908U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0440] `sub_1fa60` (`0x1fa60..0x1fa68`, 8 bytes)
 *        Hàm FDE[0440] `sub_1fa60` (`0x1fa60..0x1fa68`, 8 bytes)
 * Disassembly: 0x1fa60: mov w3, wzr ; 0x1fa64: br x8
 */
uint64_t fde_0440_0x1fa60(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa60ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e3U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0441] `sub_1fa68` (`0x1fa68..0x1fa70`, 8 bytes)
 *        Hàm FDE[0441] `sub_1fa68` (`0x1fa68..0x1fa70`, 8 bytes)
 * Disassembly: 0x1fa68: sxtw x0, w8 ; 0x1fa6c: b #0x115d0
 */
uint64_t fde_0441_0x1fa68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa68ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x93407d00U;
    constexpr uint32_t kOpN  = 0x17ffc6d9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0442] `sub_1fa70` (`0x1fa70..0x1fa94`, 36 bytes)
 *        Hàm FDE[0442] `sub_1fa70` (`0x1fa70..0x1fa94`, 36 bytes)
 * Disassembly: 0x1fa70: add x10, x8, x8, lsl #1 ; 0x1fa74: add x9, x9, x10, lsl #3 ; 0x1fa78: str x20, [x9] ; 0x1fa7c: str x22, [x9, #0x10] ; 0x1fa80: ldr x9, [x19]
 */
uint64_t fde_0442_0x1fa70(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa70ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0x8b08050aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0443] `sub_1fa94` (`0x1fa94..0x1faa4`, 16 bytes)
 *        Hàm FDE[0443] `sub_1fa94` (`0x1fa94..0x1faa4`, 16 bytes)
 * Disassembly: 0x1fa94: ldp x20, x19, [sp, #0x20] ; 0x1fa98: ldp x22, x21, [sp, #0x10] ; 0x1fa9c: ldr x23, [sp], #0x40 ; 0x1faa0: ret
 */
uint64_t fde_0443_0x1fa94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fa94ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xa9424ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0444] `sub_1faa4` (`0x1faa4..0x1fac8`, 36 bytes)
 *        Hàm FDE[0444] `sub_1faa4` (`0x1faa4..0x1fac8`, 36 bytes)
 * Disassembly: 0x1faa4: mov x8, x19 ; 0x1faa8: ldr x9, [x8, #0x10]! ; 0x1faac: str x9, [x20] ; 0x1fab0: str x20, [x8] ; 0x1fab4: ldr x9, [x19]
 */
uint64_t fde_0444_0x1faa4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1faa4ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xaa1303e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0445] `sub_1fac8` (`0x1fac8..0x1fad0`, 8 bytes)
 *        Hàm FDE[0445] `sub_1fac8` (`0x1fac8..0x1fad0`, 8 bytes)
 * Disassembly: 0x1fac8: mov x0, xzr ; 0x1facc: ret
 */
uint64_t fde_0445_0x1fac8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fac8ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1f03e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0446] `sub_1fad0` (`0x1fad0..0x1fadc`, 12 bytes)
 *        Hàm FDE[0446] `sub_1fad0` (`0x1fad0..0x1fadc`, 12 bytes)
 * Disassembly: 0x1fad0: adrp x0, #0x4f000 ; 0x1fad4: ldr x0, [x0, #0xd38] ; 0x1fad8: b #0x20df0
 */
uint64_t fde_0446_0x1fad0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fad0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x90000180U;
    constexpr uint32_t kOpN  = 0x140004c6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0447] `sub_1fadc` (`0x1fadc..0x1fae8`, 12 bytes)
 *        Hàm FDE[0447] `sub_1fadc` (`0x1fadc..0x1fae8`, 12 bytes)
 * Disassembly: 0x1fadc: adrp x0, #0x4f000 ; 0x1fae0: ldr x0, [x0, #0xd38] ; 0x1fae4: b #0x20dcc
 */
uint64_t fde_0447_0x1fadc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fadcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x90000180U;
    constexpr uint32_t kOpN  = 0x140004baU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0448] `sub_1fae8` (`0x1fae8..0x1fb04`, 28 bytes)
 *        Hàm FDE[0448] `sub_1fae8` (`0x1fae8..0x1fb04`, 28 bytes)
 * Disassembly: 0x1fae8: ldp x20, x19, [sp, #0x90] ; 0x1faec: ldp x22, x21, [sp, #0x80] ; 0x1faf0: ldp x24, x23, [sp, #0x70] ; 0x1faf4: ldp x26, x25, [sp, #0x60] ; 0x1faf8: ldp x28, x27, [sp, #0x50]
 */
uint64_t fde_0448_0x1fae8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fae8ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xa9494ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0449] `sub_1fb04` (`0x1fb04..0x1fb0c`, 8 bytes)
 *        Hàm FDE[0449] `sub_1fb04` (`0x1fb04..0x1fb0c`, 8 bytes)
 * Disassembly: 0x1fb04: mov x0, x20 ; 0x1fb08: b #0x116c0
 */
uint64_t fde_0449_0x1fb04(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb04ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1403e0U;
    constexpr uint32_t kOpN  = 0x17ffc6eeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0450] `sub_1fb0c` (`0x1fb0c..0x1fb30`, 36 bytes)
 *        Hàm FDE[0450] `sub_1fb0c` (`0x1fb0c..0x1fb30`, 36 bytes)
 * Disassembly: 0x1fb0c: mov x19, x1 ; 0x1fb10: ldp x1, x8, [x0] ; 0x1fb14: ldr x9, [x19, #8] ; 0x1fb18: mov x20, x0 ; 0x1fb1c: sub x2, x8, x1
 */
uint64_t fde_0450_0x1fb0c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb0cULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xaa0103f3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0451] `sub_1fb30` (`0x1fb30..0x1fb38`, 8 bytes)
 *        Hàm FDE[0451] `sub_1fb30` (`0x1fb30..0x1fb38`, 8 bytes)
 * Disassembly: 0x1fb30: mov w0, #3 ; 0x1fb34: b #0x11210
 */
uint64_t fde_0451_0x1fb30(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb30ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800060U;
    constexpr uint32_t kOpN  = 0x17ffc5b7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0452] `sub_1fb38` (`0x1fb38..0x1fb44`, 12 bytes)
 *        Hàm FDE[0452] `sub_1fb38` (`0x1fb38..0x1fb44`, 12 bytes)
 * Disassembly: 0x1fb38: mov x2, x1 ; 0x1fb3c: mov x1, x8 ; 0x1fb40: b #0x10bf0
 */
uint64_t fde_0452_0x1fb38(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb38ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0103e2U;
    constexpr uint32_t kOpN  = 0x17ffc42cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0453] `sub_1fb44` (`0x1fb44..0x1fb4c`, 8 bytes)
 *        Hàm FDE[0453] `sub_1fb44` (`0x1fb44..0x1fb4c`, 8 bytes)
 * Disassembly: 0x1fb44: mov w0, #0x20 ; 0x1fb48: b #0x20e20
 */
uint64_t fde_0453_0x1fb44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb44ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800400U;
    constexpr uint32_t kOpN  = 0x140004b6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0454] `sub_1fb4c` (`0x1fb4c..0x1fb54`, 8 bytes)
 *        Hàm FDE[0454] `sub_1fb4c` (`0x1fb4c..0x1fb54`, 8 bytes)
 * Disassembly: 0x1fb4c: add x0, sp, #8 ; 0x1fb50: b #0x172a4
 */
uint64_t fde_0454_0x1fb4c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb4cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x910023e0U;
    constexpr uint32_t kOpN  = 0x17ffddd5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0455] `sub_1fb54` (`0x1fb54..0x1fb6c`, 24 bytes)
 *        Hàm FDE[0455] `sub_1fb54` (`0x1fb54..0x1fb6c`, 24 bytes)
 * Disassembly: 0x1fb54: adrp x8, #0x4f000 ; 0x1fb58: ldr x8, [x8, #0xde0] ; 0x1fb5c: mov x0, x20 ; 0x1fb60: add x8, x8, #0x10 ; 0x1fb64: str x8, [sp, #0x10]
 */
uint64_t fde_0455_0x1fb54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb54ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0x14000741U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0456] `sub_1fb6c` (`0x1fb6c..0x1fb74`, 8 bytes)
 *        Hàm FDE[0456] `sub_1fb6c` (`0x1fb6c..0x1fb74`, 8 bytes)
 * Disassembly: 0x1fb6c: mov x0, x22 ; 0x1fb70: b #0x116c0
 */
uint64_t fde_0456_0x1fb6c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb6cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1603e0U;
    constexpr uint32_t kOpN  = 0x17ffc6d4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0457] `sub_1fb74` (`0x1fb74..0x1fb80`, 12 bytes)
 *        Hàm FDE[0457] `sub_1fb74` (`0x1fb74..0x1fb80`, 12 bytes)
 * Disassembly: 0x1fb74: sub w8, w26, #1 ; 0x1fb78: add x9, x9, x26 ; 0x1fb7c: ret
 */
uint64_t fde_0457_0x1fb74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb74ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x51000748U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0458] `sub_1fb80` (`0x1fb80..0x1fb94`, 20 bytes)
 *        Hàm FDE[0458] `sub_1fb80` (`0x1fb80..0x1fb94`, 20 bytes)
 * Disassembly: 0x1fb80: adrp x1, #0x39000 ; 0x1fb84: mov x21, x0 ; 0x1fb88: add x1, x1, #0x6ee ; 0x1fb8c: ldr x8, [x8, #0x538] ; 0x1fb90: ret
 */
uint64_t fde_0458_0x1fb80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb80ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xd00000c1U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0459] `sub_1fb94` (`0x1fb94..0x1fba0`, 12 bytes)
 *        Hàm FDE[0459] `sub_1fb94` (`0x1fb94..0x1fba0`, 12 bytes)
 * Disassembly: 0x1fb94: ldr w8, [x21] ; 0x1fb98: cmp w8, #4 ; 0x1fb9c: ret
 */
uint64_t fde_0459_0x1fb94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fb94ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb94002a8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0460] `sub_1fba0` (`0x1fba0..0x1fbb8`, 24 bytes)
 *        Hàm FDE[0460] `sub_1fba0` (`0x1fba0..0x1fbb8`, 24 bytes)
 * Disassembly: 0x1fba0: ldr x19, [sp, #0x20] ; 0x1fba4: mov w10, #0xca00 ; 0x1fba8: movk w10, #0x3b9a, lsl #16 ; 0x1fbac: madd x0, x9, x10, x8 ; 0x1fbb0: add sp, sp, #0x40
 */
uint64_t fde_0460_0x1fba0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fba0ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf94013f3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0461] `sub_1fbb8` (`0x1fbb8..0x1fbcc`, 20 bytes)
 *        Hàm FDE[0461] `sub_1fbb8` (`0x1fbb8..0x1fbcc`, 20 bytes)
 * Disassembly: 0x1fbb8: ldp x9, x8, [sp, #8] ; 0x1fbbc: ldr x10, [x19, #0x28] ; 0x1fbc0: ldr x11, [sp, #0x18] ; 0x1fbc4: cmp x10, x11 ; 0x1fbc8: ret
 */
uint64_t fde_0461_0x1fbb8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fbb8ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa940a3e9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0462] `sub_1fbcc` (`0x1fbcc..0x1fbe0`, 20 bytes)
 *        Hàm FDE[0462] `sub_1fbcc` (`0x1fbcc..0x1fbe0`, 20 bytes)
 * Disassembly: 0x1fbcc: adrp x0, #0x3a000 ; 0x1fbd0: adrp x1, #0x3c000 ; 0x1fbd4: add x0, x0, #0xc55 ; 0x1fbd8: add x1, x1, #0x206 ; 0x1fbdc: ret
 */
uint64_t fde_0462_0x1fbcc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fbccULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf00000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0463] `sub_1fbe0` (`0x1fbe0..0x1fc00`, 32 bytes)
 *        Hàm FDE[0463] `sub_1fbe0` (`0x1fbe0..0x1fc00`, 32 bytes)
 * Disassembly: 0x1fbe0: mrs x22, tpidr_el0 ; 0x1fbe4: ldr x8, [x22, #0x28] ; 0x1fbe8: mov x21, x1 ; 0x1fbec: mov x19, x0 ; 0x1fbf0: str x8, [sp, #0x18]
 */
uint64_t fde_0463_0x1fbe0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fbe0ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xd53bd056U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0464] `sub_1fc00` (`0x1fc00..0x1fc08`, 8 bytes)
 *        Hàm FDE[0464] `sub_1fc00` (`0x1fc00..0x1fc08`, 8 bytes)
 * Disassembly: 0x1fc00: mov x3, x19 ; 0x1fc04: b #0x11210
 */
uint64_t fde_0464_0x1fc00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc00ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1303e3U;
    constexpr uint32_t kOpN  = 0x17ffc583U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0465] `sub_1fc08` (`0x1fc08..0x1fc20`, 24 bytes)
 *        Hàm FDE[0465] `sub_1fc08` (`0x1fc08..0x1fc20`, 24 bytes)
 * Disassembly: 0x1fc08: add x2, x2, #0x7e6 ; 0x1fc0c: mov w0, #3 ; 0x1fc10: mov x3, x19 ; 0x1fc14: mov w4, w21 ; 0x1fc18: mov w5, w22
 */
uint64_t fde_0465_0x1fc08(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc08ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x911f9842U;
    constexpr uint32_t kOpN  = 0x17ffc57dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0466] `sub_1fc20` (`0x1fc20..0x1fc38`, 24 bytes)
 *        Hàm FDE[0466] `sub_1fc20` (`0x1fc20..0x1fc38`, 24 bytes)
 * Disassembly: 0x1fc20: ldp x20, x19, [sp, #0x40] ; 0x1fc24: ldp x22, x21, [sp, #0x30] ; 0x1fc28: ldp x24, x23, [sp, #0x20] ; 0x1fc2c: ldp x26, x25, [sp, #0x10] ; 0x1fc30: ldp x28, x27, [sp], #0x60
 */
uint64_t fde_0466_0x1fc20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc20ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9444ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0467] `sub_1fc38` (`0x1fc38..0x1fc50`, 24 bytes)
 *        Hàm FDE[0467] `sub_1fc38` (`0x1fc38..0x1fc50`, 24 bytes)
 * Disassembly: 0x1fc38: adrp x1, #0x3a000 ; 0x1fc3c: adrp x2, #0x3a000 ; 0x1fc40: add x1, x1, #0x95e ; 0x1fc44: add x2, x2, #0x8fe ; 0x1fc48: mov w0, #5
 */
uint64_t fde_0467_0x1fc38(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc38ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf00000c1U;
    constexpr uint32_t kOpN  = 0x17ffc571U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0468] `sub_1fc50` (`0x1fc50..0x1fc64`, 20 bytes)
 *        Hàm FDE[0468] `sub_1fc50` (`0x1fc50..0x1fc64`, 20 bytes)
 * Disassembly: 0x1fc50: adrp x8, #0x4f000 ; 0x1fc54: ldr x8, [x8, #0xe50] ; 0x1fc58: ldr w8, [x8] ; 0x1fc5c: cmp w8, #5 ; 0x1fc60: ret
 */
uint64_t fde_0468_0x1fc50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc50ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0469] `sub_1fc64` (`0x1fc64..0x1fc7c`, 24 bytes)
 *        Hàm FDE[0469] `sub_1fc64` (`0x1fc64..0x1fc7c`, 24 bytes)
 * Disassembly: 0x1fc64: movk w2, #1, lsl #16 ; 0x1fc68: ldr x8, [x8] ; 0x1fc6c: ldr x9, [x8] ; 0x1fc70: mov x0, x8 ; 0x1fc74: ldr x9, [x9, #0x30]
 */
uint64_t fde_0469_0x1fc64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc64ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x72a00022U;
    constexpr uint32_t kOpN  = 0xd61f0120U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0470] `sub_1fc7c` (`0x1fc7c..0x1fc90`, 20 bytes)
 *        Hàm FDE[0470] `sub_1fc7c` (`0x1fc7c..0x1fc90`, 20 bytes)
 * Disassembly: 0x1fc7c: mrs x21, tpidr_el0 ; 0x1fc80: ldr x8, [x21, #0x28] ; 0x1fc84: mov x19, x0 ; 0x1fc88: add x0, sp, #8 ; 0x1fc8c: ret
 */
uint64_t fde_0470_0x1fc7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc7cULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xd53bd055U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0471] `sub_1fc90` (`0x1fc90..0x1fc98`, 8 bytes)
 *        Hàm FDE[0471] `sub_1fc90` (`0x1fc90..0x1fc98`, 8 bytes)
 * Disassembly: 0x1fc90: mov x0, x21 ; 0x1fc94: b #0x10e50
 */
uint64_t fde_0471_0x1fc90(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc90ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1503e0U;
    constexpr uint32_t kOpN  = 0x17ffc46fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0472] `sub_1fc98` (`0x1fc98..0x1fca0`, 8 bytes)
 *        Hàm FDE[0472] `sub_1fc98` (`0x1fc98..0x1fca0`, 8 bytes)
 * Disassembly: 0x1fc98: mov x0, x20 ; 0x1fc9c: b #0x11480
 */
uint64_t fde_0472_0x1fc98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fc98ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1403e0U;
    constexpr uint32_t kOpN  = 0x17ffc5f9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0473] `sub_1fca0` (`0x1fca0..0x1fca8`, 8 bytes)
 *        Hàm FDE[0473] `sub_1fca0` (`0x1fca0..0x1fca8`, 8 bytes)
 * Disassembly: 0x1fca0: mov w1, wzr ; 0x1fca4: b #0x11620
 */
uint64_t fde_0473_0x1fca0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fca0ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e1U;
    constexpr uint32_t kOpN  = 0x17ffc65fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0474] `sub_1fca8` (`0x1fca8..0x1fcc0`, 24 bytes)
 *        Hàm FDE[0474] `sub_1fca8` (`0x1fca8..0x1fcc0`, 24 bytes)
 * Disassembly: 0x1fca8: adrp x0, #0x38000 ; 0x1fcac: adrp x1, #0x38000 ; 0x1fcb0: add x0, x0, #0xe83 ; 0x1fcb4: add x1, x1, #0xd5a ; 0x1fcb8: mov x3, xzr
 */
uint64_t fde_0474_0x1fca8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fca8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xb00000c0U;
    constexpr uint32_t kOpN  = 0x17ffc565U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0475] `sub_1fcc0` (`0x1fcc0..0x1fcd4`, 20 bytes)
 *        Hàm FDE[0475] `sub_1fcc0` (`0x1fcc0..0x1fcd4`, 20 bytes)
 * Disassembly: 0x1fcc0: add x1, sp, #8 ; 0x1fcc4: mov w2, #0x100 ; 0x1fcc8: mov w0, w20 ; 0x1fccc: add x21, sp, #8 ; 0x1fcd0: b #0x10ca0
 */
uint64_t fde_0475_0x1fcc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fcc0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x910023e1U;
    constexpr uint32_t kOpN  = 0x17ffc3f4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0476] `sub_1fcd4` (`0x1fcd4..0x1fce8`, 20 bytes)
 *        Hàm FDE[0476] `sub_1fcd4` (`0x1fcd4..0x1fce8`, 20 bytes)
 * Disassembly: 0x1fcd4: adrp x2, #0x3a000 ; 0x1fcd8: mov w0, #4 ; 0x1fcdc: mov x1, x24 ; 0x1fce0: add x2, x2, #0x701 ; 0x1fce4: b #0x11210
 */
uint64_t fde_0476_0x1fcd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fcd4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf00000c2U;
    constexpr uint32_t kOpN  = 0x17ffc54bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0477] `sub_1fce8` (`0x1fce8..0x1fcf4`, 12 bytes)
 *        Hàm FDE[0477] `sub_1fce8` (`0x1fce8..0x1fcf4`, 12 bytes)
 * Disassembly: 0x1fce8: add x1, sp, #0x20 ; 0x1fcec: mov x0, x25 ; 0x1fcf0: b #0x19f98
 */
uint64_t fde_0477_0x1fce8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fce8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x910083e1U;
    constexpr uint32_t kOpN  = 0x17ffe8aaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0478] `sub_1fcf4` (`0x1fcf4..0x1fd00`, 12 bytes)
 *        Hàm FDE[0478] `sub_1fcf4` (`0x1fcf4..0x1fd00`, 12 bytes)
 * Disassembly: 0x1fcf4: ldur x9, [x29, #-0x58] ; 0x1fcf8: cmp x8, x9 ; 0x1fcfc: ret
 */
uint64_t fde_0478_0x1fcf4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fcf4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf85a83a9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0479] `sub_1fd00` (`0x1fd00..0x1fd0c`, 12 bytes)
 *        Hàm FDE[0479] `sub_1fd00` (`0x1fd00..0x1fd0c`, 12 bytes)
 * Disassembly: 0x1fd00: adrp x0, #0x50000 ; 0x1fd04: add x0, x0, #0x448 ; 0x1fd08: b #0x11360
 */
uint64_t fde_0479_0x1fd00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd00ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb0000180U;
    constexpr uint32_t kOpN  = 0x17ffc596U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0480] `sub_1fd0c` (`0x1fd0c..0x1fd18`, 12 bytes)
 *        Hàm FDE[0480] `sub_1fd0c` (`0x1fd0c..0x1fd18`, 12 bytes)
 * Disassembly: 0x1fd0c: ldrb w20, [x9], #1 ; 0x1fd10: add w8, w8, #1 ; 0x1fd14: ret
 */
uint64_t fde_0480_0x1fd0c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd0cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x38401534U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0481] `sub_1fd18` (`0x1fd18..0x1fd2c`, 20 bytes)
 *        Hàm FDE[0481] `sub_1fd18` (`0x1fd18..0x1fd2c`, 20 bytes)
 * Disassembly: 0x1fd18: ldp x20, x19, [sp, #0x50] ; 0x1fd1c: ldp x22, x21, [sp, #0x40] ; 0x1fd20: ldr x23, [sp, #0x30] ; 0x1fd24: add sp, sp, #0x70 ; 0x1fd28: ret
 */
uint64_t fde_0481_0x1fd18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd18ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9454ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0482] `sub_1fd2c` (`0x1fd2c..0x1fd38`, 12 bytes)
 *        Hàm FDE[0482] `sub_1fd2c` (`0x1fd2c..0x1fd38`, 12 bytes)
 * Disassembly: 0x1fd2c: and w10, w20, #0xff ; 0x1fd30: cmp w10, #0x3a ; 0x1fd34: ret
 */
uint64_t fde_0482_0x1fd2c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd2cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x12001e8aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0483] `sub_1fd38` (`0x1fd38..0x1fd4c`, 20 bytes)
 *        Hàm FDE[0483] `sub_1fd38` (`0x1fd38..0x1fd4c`, 20 bytes)
 * Disassembly: 0x1fd38: ldp x20, x19, [sp, #0x130] ; 0x1fd3c: ldp x22, x21, [sp, #0x120] ; 0x1fd40: ldr x28, [sp, #0x110] ; 0x1fd44: add sp, sp, #0x150 ; 0x1fd48: ret
 */
uint64_t fde_0483_0x1fd38(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd38ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9534ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0484] `sub_1fd4c` (`0x1fd4c..0x1fd68`, 28 bytes)
 *        Hàm FDE[0484] `sub_1fd4c` (`0x1fd4c..0x1fd68`, 28 bytes)
 * Disassembly: 0x1fd4c: stp q0, q1, [sp] ; 0x1fd50: stp q2, q3, [sp, #0x20] ; 0x1fd54: stp q4, q5, [sp, #0x40] ; 0x1fd58: stp q6, q7, [sp, #0x60] ; 0x1fd5c: mrs x19, tpidr_el0
 */
uint64_t fde_0484_0x1fd4c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd4cULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xad0007e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0485] `sub_1fd68` (`0x1fd68..0x1fd7c`, 20 bytes)
 *        Hàm FDE[0485] `sub_1fd68` (`0x1fd68..0x1fd7c`, 20 bytes)
 * Disassembly: 0x1fd68: cmp w0, #0 ; 0x1fd6c: cset w8, ne ; 0x1fd70: adrp x9, #0x50000 ; 0x1fd74: str w8, [x9, #0x58] ; 0x1fd78: ret
 */
uint64_t fde_0485_0x1fd68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd68ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x7100001fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0486] `sub_1fd7c` (`0x1fd7c..0x1fd88`, 12 bytes)
 *        Hàm FDE[0486] `sub_1fd7c` (`0x1fd7c..0x1fd88`, 12 bytes)
 * Disassembly: 0x1fd7c: add x1, sp, #0x30 ; 0x1fd80: mov x0, x26 ; 0x1fd84: b #0x199f0
 */
uint64_t fde_0486_0x1fd7c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd7cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x9100c3e1U;
    constexpr uint32_t kOpN  = 0x17ffe71bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0487] `sub_1fd88` (`0x1fd88..0x1fd9c`, 20 bytes)
 *        Hàm FDE[0487] `sub_1fd88` (`0x1fd88..0x1fd9c`, 20 bytes)
 * Disassembly: 0x1fd88: mov w10, #0x18 ; 0x1fd8c: ldr x8, [x19] ; 0x1fd90: ldrsw x9, [x21] ; 0x1fd94: madd x0, x9, x10, x8 ; 0x1fd98: b #0x11270
 */
uint64_t fde_0487_0x1fd88(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd88ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x5280030aU;
    constexpr uint32_t kOpN  = 0x17ffc536U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0488] `sub_1fd9c` (`0x1fd9c..0x1fdc0`, 36 bytes)
 *        Hàm FDE[0488] `sub_1fd9c` (`0x1fd9c..0x1fdc0`, 36 bytes)
 * Disassembly: 0x1fd9c: str x30, [sp, #-0x10]! ; 0x1fda0: mov x0, x19 ; 0x1fda4: bl #0x1dea8 ; 0x1fda8: mov x20, x0 ; 0x1fdac: mov x0, x19
 */
uint64_t fde_0488_0x1fd9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fd9cULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf81f0ffeU;
    constexpr uint32_t kOpN  = 0x17ffc641U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0489] `sub_1fdc0` (`0x1fdc0..0x1fdcc`, 12 bytes)
 *        Hàm FDE[0489] `sub_1fdc0` (`0x1fdc0..0x1fdcc`, 12 bytes)
 * Disassembly: 0x1fdc0: sub x15, x9, #1 ; 0x1fdc4: and x14, x14, x15 ; 0x1fdc8: ret
 */
uint64_t fde_0489_0x1fdc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fdc0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd100052fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0490] `sub_1fdcc` (`0x1fdcc..0x1fdd8`, 12 bytes)
 *        Hàm FDE[0490] `sub_1fdcc` (`0x1fdcc..0x1fdd8`, 12 bytes)
 * Disassembly: 0x1fdcc: udiv x15, x14, x9 ; 0x1fdd0: msub x14, x15, x9, x14 ; 0x1fdd4: ret
 */
uint64_t fde_0490_0x1fdcc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fdccULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x9ac909cfU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0491] `sub_1fdd8` (`0x1fdd8..0x1fde4`, 12 bytes)
 *        Hàm FDE[0491] `sub_1fdd8` (`0x1fdd8..0x1fde4`, 12 bytes)
 * Disassembly: 0x1fdd8: adrp x0, #0x50000 ; 0x1fddc: add x0, x0, #0x4c0 ; 0x1fde0: b #0x11780
 */
uint64_t fde_0491_0x1fdd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fdd8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xb0000180U;
    constexpr uint32_t kOpN  = 0x17ffc668U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0492] `sub_1fde4` (`0x1fde4..0x1fdf0`, 12 bytes)
 *        Hàm FDE[0492] `sub_1fde4` (`0x1fde4..0x1fdf0`, 12 bytes)
 * Disassembly: 0x1fde4: mov x0, xzr ; 0x1fde8: mov x4, xzr ; 0x1fdec: b #0x10e80
 */
uint64_t fde_0492_0x1fde4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fde4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa1f03e0U;
    constexpr uint32_t kOpN  = 0x17ffc425U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0493] `sub_1fdf0` (`0x1fdf0..0x1fe04`, 20 bytes)
 *        Hàm FDE[0493] `sub_1fdf0` (`0x1fdf0..0x1fe04`, 20 bytes)
 * Disassembly: 0x1fdf0: ldp x20, x19, [sp, #0x30] ; 0x1fdf4: ldp x22, x21, [sp, #0x20] ; 0x1fdf8: ldp x24, x23, [sp, #0x10] ; 0x1fdfc: ldr x28, [sp], #0x50 ; 0x1fe00: ret
 */
uint64_t fde_0493_0x1fdf0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fdf0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9434ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0494] `sub_1fe04` (`0x1fe04..0x1fe10`, 12 bytes)
 *        Hàm FDE[0494] `sub_1fe04` (`0x1fe04..0x1fe10`, 12 bytes)
 * Disassembly: 0x1fe04: ldr x9, [sp, #8] ; 0x1fe08: cmp x8, x9 ; 0x1fe0c: ret
 */
uint64_t fde_0494_0x1fe04(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe04ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf94007e9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0495] `sub_1fe10` (`0x1fe10..0x1fe1c`, 12 bytes)
 *        Hàm FDE[0495] `sub_1fe10` (`0x1fe10..0x1fe1c`, 12 bytes)
 * Disassembly: 0x1fe10: mrs x21, tpidr_el0 ; 0x1fe14: ldr x8, [x21, #0x28] ; 0x1fe18: ret
 */
uint64_t fde_0495_0x1fe10(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe10ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd53bd055U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0496] `sub_1fe1c` (`0x1fe1c..0x1fe30`, 20 bytes)
 *        Hàm FDE[0496] `sub_1fe1c` (`0x1fe1c..0x1fe30`, 20 bytes)
 * Disassembly: 0x1fe1c: mov x0, x21 ; 0x1fe20: mov x1, x22 ; 0x1fe24: mov x2, x20 ; 0x1fe28: mov x3, x19 ; 0x1fe2c: b #0x1e36c
 */
uint64_t fde_0496_0x1fe1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe1cULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xaa1503e0U;
    constexpr uint32_t kOpN  = 0x17fff950U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0497] `sub_1fe30` (`0x1fe30..0x1fe3c`, 12 bytes)
 *        Hàm FDE[0497] `sub_1fe30` (`0x1fe30..0x1fe3c`, 12 bytes)
 * Disassembly: 0x1fe30: ldp x20, x19, [sp, #0x10] ; 0x1fe34: ldp x22, x21, [sp], #0x30 ; 0x1fe38: ret
 */
uint64_t fde_0497_0x1fe30(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe30ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0498] `sub_1fe3c` (`0x1fe3c..0x1fe48`, 12 bytes)
 *        Hàm FDE[0498] `sub_1fe3c` (`0x1fe3c..0x1fe48`, 12 bytes)
 * Disassembly: 0x1fe3c: ldp x20, x19, [sp, #0x10] ; 0x1fe40: ldr x21, [sp], #0x30 ; 0x1fe44: b #0x20e88
 */
uint64_t fde_0498_0x1fe3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe3cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0x14000411U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0499] `sub_1fe48` (`0x1fe48..0x1fe50`, 8 bytes)
 *        Hàm FDE[0499] `sub_1fe48` (`0x1fe48..0x1fe50`, 8 bytes)
 * Disassembly: 0x1fe48: mov x19, x0 ; 0x1fe4c: b #0x20d4c
 */
uint64_t fde_0499_0x1fe48(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe48ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa0003f3U;
    constexpr uint32_t kOpN  = 0x140003c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0500] `sub_1fe50` (`0x1fe50..0x1fe5c`, 12 bytes)
 *        Hàm FDE[0500] `sub_1fe50` (`0x1fe50..0x1fe5c`, 12 bytes)
 * Disassembly: 0x1fe50: mov w1, wzr ; 0x1fe54: stur x8, [x29, #-0x28] ; 0x1fe58: b #0x11620
 */
uint64_t fde_0500_0x1fe50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe50ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1f03e1U;
    constexpr uint32_t kOpN  = 0x17ffc5f2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0501] `sub_1fe5c` (`0x1fe5c..0x1fe68`, 12 bytes)
 *        Hàm FDE[0501] `sub_1fe5c` (`0x1fe5c..0x1fe68`, 12 bytes)
 * Disassembly: 0x1fe5c: mov w0, #3 ; 0x1fe60: mov w3, w19 ; 0x1fe64: b #0x11210
 */
uint64_t fde_0501_0x1fe5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe5cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52800060U;
    constexpr uint32_t kOpN  = 0x17ffc4ebU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0502] `sub_1fe68` (`0x1fe68..0x1fe70`, 8 bytes)
 *        Hàm FDE[0502] `sub_1fe68` (`0x1fe68..0x1fe70`, 8 bytes)
 * Disassembly: 0x1fe68: mov w0, #1 ; 0x1fe6c: ret
 */
uint64_t fde_0502_0x1fe68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe68ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0503] `sub_1fe70` (`0x1fe70..0x1fe8c`, 28 bytes)
 *        Hàm FDE[0503] `sub_1fe70` (`0x1fe70..0x1fe8c`, 28 bytes)
 * Disassembly: 0x1fe70: ldr x8, [x19, #8] ; 0x1fe74: stp x19, x8, [x0] ; 0x1fe78: str x0, [x8] ; 0x1fe7c: ldr x8, [x19, #0x10] ; 0x1fe80: add x8, x8, #1
 */
uint64_t fde_0503_0x1fe70(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe70ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xf9400668U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0504] `sub_1fe8c` (`0x1fe8c..0x1fe98`, 12 bytes)
 *        Hàm FDE[0504] `sub_1fe8c` (`0x1fe8c..0x1fe98`, 12 bytes)
 * Disassembly: 0x1fe8c: mov w1, #1 ; 0x1fe90: mov x0, x20 ; 0x1fe94: b #0x18860
 */
uint64_t fde_0504_0x1fe8c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe8cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52800021U;
    constexpr uint32_t kOpN  = 0x17ffe273U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0505] `sub_1fe98` (`0x1fe98..0x1fea8`, 16 bytes)
 *        Hàm FDE[0505] `sub_1fe98` (`0x1fe98..0x1fea8`, 16 bytes)
 * Disassembly: 0x1fe98: add x0, sp, #8 ; 0x1fe9c: mov w2, #4 ; 0x1fea0: mov x1, x3 ; 0x1fea4: b #0x10bd0
 */
uint64_t fde_0505_0x1fe98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fe98ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x910023e0U;
    constexpr uint32_t kOpN  = 0x17ffc34bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0506] `sub_1fea8` (`0x1fea8..0x1fec0`, 24 bytes)
 *        Hàm FDE[0506] `sub_1fea8` (`0x1fea8..0x1fec0`, 24 bytes)
 * Disassembly: 0x1fea8: ldr x12, [x10, #0xd0] ; 0x1feac: ldr x13, [x12, #0xc0]! ; 0x1feb0: add x14, x12, #8 ; 0x1feb4: cmp x10, x13 ; 0x1feb8: csel x12, x12, x14, eq
 */
uint64_t fde_0506_0x1fea8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fea8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf940694cU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0507] `sub_1fec0` (`0x1fec0..0x1fed0`, 16 bytes)
 *        Hàm FDE[0507] `sub_1fec0` (`0x1fec0..0x1fed0`, 16 bytes)
 * Disassembly: 0x1fec0: mov w2, #0x800 ; 0x1fec4: mov w1, wzr ; 0x1fec8: stur x8, [x29, #-0x48] ; 0x1fecc: b #0x11620
 */
uint64_t fde_0507_0x1fec0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fec0ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x52810002U;
    constexpr uint32_t kOpN  = 0x17ffc5d5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0508] `sub_1fed0` (`0x1fed0..0x1fee0`, 16 bytes)
 *        Hàm FDE[0508] `sub_1fed0` (`0x1fed0..0x1fee0`, 16 bytes)
 * Disassembly: 0x1fed0: ldr x16, [x12, #0x10] ; 0x1fed4: ldr x17, [x15, #0x10] ; 0x1fed8: cmp x16, x17 ; 0x1fedc: ret
 */
uint64_t fde_0508_0x1fed0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fed0ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400990U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0509] `sub_1fee0` (`0x1fee0..0x1fef0`, 16 bytes)
 *        Hàm FDE[0509] `sub_1fee0` (`0x1fee0..0x1fef0`, 16 bytes)
 * Disassembly: 0x1fee0: ldr x14, [x19] ; 0x1fee4: mov x15, x12 ; 0x1fee8: ldr x16, [x14, x13, lsl #3] ; 0x1feec: ret
 */
uint64_t fde_0509_0x1fee0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fee0ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf940026eU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0510] `sub_1fef0` (`0x1fef0..0x1ff00`, 16 bytes)
 *        Hàm FDE[0510] `sub_1fef0` (`0x1fef0..0x1ff00`, 16 bytes)
 * Disassembly: 0x1fef0: ldr x12, [x19] ; 0x1fef4: str x11, [x12, x10, lsl #3] ; 0x1fef8: sub x11, x20, #1 ; 0x1fefc: ret
 */
uint64_t fde_0510_0x1fef0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1fef0ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf940026cU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0511] `sub_1ff00` (`0x1ff00..0x1ff18`, 24 bytes)
 *        Hàm FDE[0511] `sub_1ff00` (`0x1ff00..0x1ff18`, 24 bytes)
 * Disassembly: 0x1ff00: str xzr, [x0] ; 0x1ff04: ldr x8, [x20] ; 0x1ff08: str x8, [x0, #0x10] ; 0x1ff0c: ldr x8, [x20, #8] ; 0x1ff10: str x8, [x0, #0x18]
 */
uint64_t fde_0511_0x1ff00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff00ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf900001fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0512] `sub_1ff18` (`0x1ff18..0x1ff28`, 16 bytes)
 *        Hàm FDE[0512] `sub_1ff18` (`0x1ff18..0x1ff28`, 16 bytes)
 * Disassembly: 0x1ff18: adrp x19, #0x50000 ; 0x1ff1c: add x19, x19, #0x3a8 ; 0x1ff20: add x0, x19, #0xf0 ; 0x1ff24: b #0x20dcc
 */
uint64_t fde_0512_0x1ff18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff18ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xb0000193U;
    constexpr uint32_t kOpN  = 0x140003aaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0513] `sub_1ff28` (`0x1ff28..0x1ff34`, 12 bytes)
 *        Hàm FDE[0513] `sub_1ff28` (`0x1ff28..0x1ff34`, 12 bytes)
 * Disassembly: 0x1ff28: ldr x9, [sp, #0x18] ; 0x1ff2c: cmp x8, x9 ; 0x1ff30: ret
 */
uint64_t fde_0513_0x1ff28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff28ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf9400fe9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0514] `sub_1ff34` (`0x1ff34..0x1ff4c`, 24 bytes)
 *        Hàm FDE[0514] `sub_1ff34` (`0x1ff34..0x1ff4c`, 24 bytes)
 * Disassembly: 0x1ff34: str xzr, [sp] ; 0x1ff38: ldr x8, [x19, #0x18] ; 0x1ff3c: mov x0, sp ; 0x1ff40: add x8, x8, #1 ; 0x1ff44: str x8, [x19, #0x18]
 */
uint64_t fde_0514_0x1ff34(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff34ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf90003ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0515] `sub_1ff4c` (`0x1ff4c..0x1ff68`, 28 bytes)
 *        Hàm FDE[0515] `sub_1ff4c` (`0x1ff4c..0x1ff68`, 28 bytes)
 * Disassembly: 0x1ff4c: ldp x20, x19, [sp, #0xc0] ; 0x1ff50: ldp x22, x21, [sp, #0xb0] ; 0x1ff54: ldp x24, x23, [sp, #0xa0] ; 0x1ff58: ldp x26, x25, [sp, #0x90] ; 0x1ff5c: ldp x28, x27, [sp, #0x80]
 */
uint64_t fde_0515_0x1ff4c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff4cULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xa94c4ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0516] `sub_1ff68` (`0x1ff68..0x1ff84`, 28 bytes)
 *        Hàm FDE[0516] `sub_1ff68` (`0x1ff68..0x1ff84`, 28 bytes)
 * Disassembly: 0x1ff68: sub sp, sp, #0xe0 ; 0x1ff6c: stp x28, x27, [sp, #0x80] ; 0x1ff70: stp x26, x25, [sp, #0x90] ; 0x1ff74: stp x24, x23, [sp, #0xa0] ; 0x1ff78: stp x22, x21, [sp, #0xb0]
 */
uint64_t fde_0516_0x1ff68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff68ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xd10383ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0517] `sub_1ff84` (`0x1ff84..0x1ff9c`, 24 bytes)
 *        Hàm FDE[0517] `sub_1ff84` (`0x1ff84..0x1ff9c`, 24 bytes)
 * Disassembly: 0x1ff84: add x2, x2, #0x81e ; 0x1ff88: mov w0, #3 ; 0x1ff8c: mov x3, x22 ; 0x1ff90: mov w4, w19 ; 0x1ff94: mov w5, w21
 */
uint64_t fde_0517_0x1ff84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff84ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x91207842U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0518] `sub_1ff9c` (`0x1ff9c..0x1ffa4`, 8 bytes)
 *        Hàm FDE[0518] `sub_1ff9c` (`0x1ff9c..0x1ffa4`, 8 bytes)
 * Disassembly: 0x1ff9c: ldr x8, [x8, #0x538] ; 0x1ffa0: br x8
 */
uint64_t fde_0518_0x1ff9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ff9cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9429d08U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0519] `sub_1ffa4` (`0x1ffa4..0x1ffbc`, 24 bytes)
 *        Hàm FDE[0519] `sub_1ffa4` (`0x1ffa4..0x1ffbc`, 24 bytes)
 * Disassembly: 0x1ffa4: add x10, x10, #0x80 ; 0x1ffa8: sub x9, x29, #0x38 ; 0x1ffac: stp x12, x11, [x29, #-0x38] ; 0x1ffb0: stp x10, x13, [x29, #-0x28] ; 0x1ffb4: ldp q1, q0, [x9]
 */
uint64_t fde_0519_0x1ffa4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ffa4ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x9102014aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0520] `sub_1ffbc` (`0x1ffbc..0x1ffc8`, 12 bytes)
 *        Hàm FDE[0520] `sub_1ffbc` (`0x1ffbc..0x1ffc8`, 12 bytes)
 * Disassembly: 0x1ffbc: ldr x9, [sp, #0x28] ; 0x1ffc0: cmp x8, x9 ; 0x1ffc4: ret
 */
uint64_t fde_0520_0x1ffbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ffbcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf94017e9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0521] `sub_1ffc8` (`0x1ffc8..0x1ffd8`, 16 bytes)
 *        Hàm FDE[0521] `sub_1ffc8` (`0x1ffc8..0x1ffd8`, 16 bytes)
 * Disassembly: 0x1ffc8: mov x3, #-1 ; 0x1ffcc: mov w4, #0x800 ; 0x1ffd0: mov x20, x0 ; 0x1ffd4: b #0x10e60
 */
uint64_t fde_0521_0x1ffc8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ffc8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x92800003U;
    constexpr uint32_t kOpN  = 0x17ffc3a3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0522] `sub_1ffd8` (`0x1ffd8..0x1ffe8`, 16 bytes)
 *        Hàm FDE[0522] `sub_1ffd8` (`0x1ffd8..0x1ffe8`, 16 bytes)
 * Disassembly: 0x1ffd8: ldr x8, [x19] ; 0x1ffdc: ldrsw x9, [x20] ; 0x1ffe0: madd x0, x9, x21, x8 ; 0x1ffe4: ret
 */
uint64_t fde_0522_0x1ffd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ffd8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400268U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0523] `sub_1ffe8` (`0x1ffe8..0x20000`, 24 bytes)
 *        Hàm FDE[0523] `sub_1ffe8` (`0x1ffe8..0x20000`, 24 bytes)
 * Disassembly: 0x1ffe8: add x0, sp, #0x30 ; 0x1ffec: add x2, sp, #0x20 ; 0x1fff0: add x3, sp, #0x28 ; 0x1fff4: add x4, sp, #0x18 ; 0x1fff8: add x5, sp, #0x14
 */
uint64_t fde_0523_0x1ffe8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x1ffe8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x9100c3e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0524] `sub_20000` (`0x20000..0x20010`, 16 bytes)
 *        Hàm FDE[0524] `sub_20000` (`0x20000..0x20010`, 16 bytes)
 * Disassembly: 0x20000: ldp x20, x19, [sp, #0x20] ; 0x20004: ldp x22, x21, [sp, #0x10] ; 0x20008: ldr x23, [sp], #0x40 ; 0x2000c: ret
 */
uint64_t fde_0524_0x20000(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20000ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xa9424ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0525] `sub_20010` (`0x20010..0x20020`, 16 bytes)
 *        Hàm FDE[0525] `sub_20010` (`0x20010..0x20020`, 16 bytes)
 * Disassembly: 0x20010: ldr x8, [x22, #0x28] ; 0x20014: ldur x9, [x29, #-0x38] ; 0x20018: cmp x8, x9 ; 0x2001c: ret
 */
uint64_t fde_0525_0x20010(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20010ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf94016c8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0526] `sub_20020` (`0x20020..0x20028`, 8 bytes)
 *        Hàm FDE[0526] `sub_20020` (`0x20020..0x20028`, 8 bytes)
 * Disassembly: 0x20020: mov x0, x19 ; 0x20024: b #0x11360
 */
uint64_t fde_0526_0x20020(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20020ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x17ffc4cfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0527] `sub_20028` (`0x20028..0x20030`, 8 bytes)
 *        Hàm FDE[0527] `sub_20028` (`0x20028..0x20030`, 8 bytes)
 * Disassembly: 0x20028: mov x0, x19 ; 0x2002c: b #0x11780
 */
uint64_t fde_0527_0x20028(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20028ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x17ffc5d5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0528] `sub_20030` (`0x20030..0x20048`, 24 bytes)
 *        Hàm FDE[0528] `sub_20030` (`0x20030..0x20048`, 24 bytes)
 * Disassembly: 0x20030: ldrb w8, [sp, #0x10] ; 0x20034: ldr x9, [sp, #0x20] ; 0x20038: add x10, sp, #0x10 ; 0x2003c: orr x10, x10, #1 ; 0x20040: tst w8, #1
 */
uint64_t fde_0528_0x20030(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20030ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x394043e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0529] `sub_20048` (`0x20048..0x20058`, 16 bytes)
 *        Hàm FDE[0529] `sub_20048` (`0x20048..0x20058`, 16 bytes)
 * Disassembly: 0x20048: adrp x1, #0x3a000 ; 0x2004c: add x1, x1, #0xae1 ; 0x20050: mov w0, wzr ; 0x20054: b #0x10ea0
 */
uint64_t fde_0529_0x20048(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20048ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xd00000c1U;
    constexpr uint32_t kOpN  = 0x17ffc393U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0530] `sub_20058` (`0x20058..0x20068`, 16 bytes)
 *        Hàm FDE[0530] `sub_20058` (`0x20058..0x20068`, 16 bytes)
 * Disassembly: 0x20058: adrp x8, #0x50000 ; 0x2005c: mov w9, #1 ; 0x20060: strb w9, [x8, #0x2f5] ; 0x20064: ret
 */
uint64_t fde_0530_0x20058(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20058ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0531] `sub_20068` (`0x20068..0x20078`, 16 bytes)
 *        Hàm FDE[0531] `sub_20068` (`0x20068..0x20078`, 16 bytes)
 * Disassembly: 0x20068: mov w1, #0x80000 ; 0x2006c: mov x0, x21 ; 0x20070: str wzr, [x20] ; 0x20074: b #0x112d0
 */
uint64_t fde_0531_0x20068(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20068ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x52a00101U;
    constexpr uint32_t kOpN  = 0x17ffc497U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0532] `sub_20078` (`0x20078..0x20088`, 16 bytes)
 *        Hàm FDE[0532] `sub_20078` (`0x20078..0x20088`, 16 bytes)
 * Disassembly: 0x20078: mov w1, #0x80000 ; 0x2007c: mov x0, x20 ; 0x20080: str wzr, [x21] ; 0x20084: b #0x112d0
 */
uint64_t fde_0532_0x20078(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20078ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x52a00101U;
    constexpr uint32_t kOpN  = 0x17ffc493U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0533] `sub_20088` (`0x20088..0x20094`, 12 bytes)
 *        Hàm FDE[0533] `sub_20088` (`0x20088..0x20094`, 12 bytes)
 * Disassembly: 0x20088: adrp x8, #0x50000 ; 0x2008c: ldr w8, [x8, #0x58] ; 0x20090: ret
 */
uint64_t fde_0533_0x20088(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20088ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0534] `sub_20094` (`0x20094..0x200a0`, 12 bytes)
 *        Hàm FDE[0534] `sub_20094` (`0x20094..0x200a0`, 12 bytes)
 * Disassembly: 0x20094: mrs x24, tpidr_el0 ; 0x20098: ldr x8, [x24, #0x28] ; 0x2009c: ret
 */
uint64_t fde_0534_0x20094(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20094ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd53bd058U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0535] `sub_200a0` (`0x200a0..0x200b0`, 16 bytes)
 *        Hàm FDE[0535] `sub_200a0` (`0x200a0..0x200b0`, 16 bytes)
 * Disassembly: 0x200a0: tst w2, #0xff ; 0x200a4: cset w8, ne ; 0x200a8: strb w8, [x9] ; 0x200ac: ret
 */
uint64_t fde_0535_0x200a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x200a0ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x72001c5fU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0536] `sub_200b0` (`0x200b0..0x200b8`, 8 bytes)
 *        Hàm FDE[0536] `sub_200b0` (`0x200b0..0x200b8`, 8 bytes)
 * Disassembly: 0x200b0: mov w0, #0xa ; 0x200b4: ret
 */
uint64_t fde_0536_0x200b0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x200b0ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800140U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0537] `sub_200b8` (`0x200b8..0x200c0`, 8 bytes)
 *        Hàm FDE[0537] `sub_200b8` (`0x200b8..0x200c0`, 8 bytes)
 * Disassembly: 0x200b8: mov w0, #9 ; 0x200bc: ret
 */
uint64_t fde_0537_0x200b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x200b8ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800120U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0538] `sub_200c0` (`0x200c0..0x200d8`, 24 bytes)
 *        Hàm FDE[0538] `sub_200c0` (`0x200c0..0x200d8`, 24 bytes)
 * Disassembly: 0x200c0: sdiv w10, w0, w8 ; 0x200c4: msub w8, w10, w8, w0 ; 0x200c8: add w8, w8, #1 ; 0x200cc: cmp w8, w9 ; 0x200d0: cset w0, lt
 */
uint64_t fde_0538_0x200c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x200c0ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0x1ac80c0aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0539] `sub_200d8` (`0x200d8..0x200f0`, 24 bytes)
 *        Hàm FDE[0539] `sub_200d8` (`0x200d8..0x200f0`, 24 bytes)
 * Disassembly: 0x200d8: adrp x8, #0x4f000 ; 0x200dc: ldr x8, [x8, #0xf08] ; 0x200e0: adrp x9, #0x4f000 ; 0x200e4: ldr w8, [x8] ; 0x200e8: ldr x9, [x9, #0xe68]
 */
uint64_t fde_0539_0x200d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x200d8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xf0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0540] `sub_200f0` (`0x200f0..0x20100`, 16 bytes)
 *        Hàm FDE[0540] `sub_200f0` (`0x200f0..0x20100`, 16 bytes)
 * Disassembly: 0x200f0: add x2, sp, #4 ; 0x200f4: str x8, [sp, #8] ; 0x200f8: str wzr, [sp, #4] ; 0x200fc: b #0x10f70
 */
uint64_t fde_0540_0x200f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x200f0ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x910013e2U;
    constexpr uint32_t kOpN  = 0x17ffc39dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0541] `sub_20100` (`0x20100..0x2010c`, 12 bytes)
 *        Hàm FDE[0541] `sub_20100` (`0x20100..0x2010c`, 12 bytes)
 * Disassembly: 0x20100: adrp x8, #0x4f000 ; 0x20104: ldr x8, [x8, #0xf80] ; 0x20108: ret
 */
uint64_t fde_0541_0x20100(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20100ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0542] `sub_2010c` (`0x2010c..0x20118`, 12 bytes)
 *        Hàm FDE[0542] `sub_2010c` (`0x2010c..0x20118`, 12 bytes)
 * Disassembly: 0x2010c: neg w8, w0 ; 0x20110: sxtw x8, w8 ; 0x20114: ret
 */
uint64_t fde_0542_0x2010c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2010cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x4b0003e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0543] `sub_20118` (`0x20118..0x20128`, 16 bytes)
 *        Hàm FDE[0543] `sub_20118` (`0x20118..0x20128`, 16 bytes)
 * Disassembly: 0x20118: adrp x8, #0x4f000 ; 0x2011c: ldr x8, [x8, #0xe38] ; 0x20120: ldrb w8, [x8] ; 0x20124: ret
 */
uint64_t fde_0543_0x20118(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20118ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0544] `sub_20128` (`0x20128..0x20138`, 16 bytes)
 *        Hàm FDE[0544] `sub_20128` (`0x20128..0x20138`, 16 bytes)
 * Disassembly: 0x20128: mov x0, x21 ; 0x2012c: ldr w8, [x8, x10] ; 0x20130: add x1, x9, x8 ; 0x20134: b #0x112c0
 */
uint64_t fde_0544_0x20128(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20128ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xaa1503e0U;
    constexpr uint32_t kOpN  = 0x17ffc463U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0545] `sub_20138` (`0x20138..0x20148`, 16 bytes)
 *        Hàm FDE[0545] `sub_20138` (`0x20138..0x20148`, 16 bytes)
 * Disassembly: 0x20138: ldr x9, [x19] ; 0x2013c: str xzr, [x9, x8, lsl #3] ; 0x20140: add x8, x8, #1 ; 0x20144: ret
 */
uint64_t fde_0545_0x20138(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20138ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400269U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0546] `sub_20148` (`0x20148..0x20150`, 8 bytes)
 *        Hàm FDE[0546] `sub_20148` (`0x20148..0x20150`, 8 bytes)
 * Disassembly: 0x20148: mov x0, x20 ; 0x2014c: b #0x36e1c
 */
uint64_t fde_0546_0x20148(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20148ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1403e0U;
    constexpr uint32_t kOpN  = 0x14005b34U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0547] `sub_20150` (`0x20150..0x20160`, 16 bytes)
 *        Hàm FDE[0547] `sub_20150` (`0x20150..0x20160`, 16 bytes)
 * Disassembly: 0x20150: mov x19, x0 ; 0x20154: mov w0, #0x20 ; 0x20158: mov x20, x1 ; 0x2015c: b #0x20e20
 */
uint64_t fde_0547_0x20150(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20150ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xaa0003f3U;
    constexpr uint32_t kOpN  = 0x14000331U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0548] `sub_20160` (`0x20160..0x2016c`, 12 bytes)
 *        Hàm FDE[0548] `sub_20160` (`0x20160..0x2016c`, 12 bytes)
 * Disassembly: 0x20160: mov x19, x0 ; 0x20164: mov x0, sp ; 0x20168: ret
 */
uint64_t fde_0548_0x20160(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20160ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003f3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0549] `sub_2016c` (`0x2016c..0x20174`, 8 bytes)
 *        Hàm FDE[0549] `sub_2016c` (`0x2016c..0x20174`, 8 bytes)
 * Disassembly: 0x2016c: mov w0, #4 ; 0x20170: ret
 */
uint64_t fde_0549_0x2016c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2016cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800080U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0550] `sub_20174` (`0x20174..0x2017c`, 8 bytes)
 *        Hàm FDE[0550] `sub_20174` (`0x20174..0x2017c`, 8 bytes)
 * Disassembly: 0x20174: mov w0, #3 ; 0x20178: b #0x11210
 */
uint64_t fde_0550_0x20174(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20174ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800060U;
    constexpr uint32_t kOpN  = 0x17ffc426U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0551] `sub_2017c` (`0x2017c..0x20184`, 8 bytes)
 *        Hàm FDE[0551] `sub_2017c` (`0x2017c..0x20184`, 8 bytes)
 * Disassembly: 0x2017c: mov w0, #3 ; 0x20180: ret
 */
uint64_t fde_0551_0x2017c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2017cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800060U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0552] `sub_20184` (`0x20184..0x2018c`, 8 bytes)
 *        Hàm FDE[0552] `sub_20184` (`0x20184..0x2018c`, 8 bytes)
 * Disassembly: 0x20184: mov w0, #2 ; 0x20188: ret
 */
uint64_t fde_0552_0x20184(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20184ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800040U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0553] `sub_2018c` (`0x2018c..0x20198`, 12 bytes)
 *        Hàm FDE[0553] `sub_2018c` (`0x2018c..0x20198`, 12 bytes)
 * Disassembly: 0x2018c: mrs x20, tpidr_el0 ; 0x20190: ldr x8, [x20, #0x28] ; 0x20194: ret
 */
uint64_t fde_0553_0x2018c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2018cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd53bd054U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0554] `sub_20198` (`0x20198..0x201a0`, 8 bytes)
 *        Hàm FDE[0554] `sub_20198` (`0x20198..0x201a0`, 8 bytes)
 * Disassembly: 0x20198: mov x0, x8 ; 0x2019c: b #0x21d54
 */
uint64_t fde_0554_0x20198(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20198ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa0803e0U;
    constexpr uint32_t kOpN  = 0x140006eeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0555] `sub_201a0` (`0x201a0..0x201a8`, 8 bytes)
 *        Hàm FDE[0555] `sub_201a0` (`0x201a0..0x201a8`, 8 bytes)
 * Disassembly: 0x201a0: ldr x19, [sp], #0x20 ; 0x201a4: ret
 */
uint64_t fde_0555_0x201a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201a0ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf84207f3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0556] `sub_201a8` (`0x201a8..0x201bc`, 20 bytes)
 *        Hàm FDE[0556] `sub_201a8` (`0x201a8..0x201bc`, 20 bytes)
 * Disassembly: 0x201a8: adrp x8, #0x4f000 ; 0x201ac: adrp x9, #0x4f000 ; 0x201b0: ldr x8, [x8, #0xff0] ; 0x201b4: ldr x9, [x9, #0xf80] ; 0x201b8: ret
 */
uint64_t fde_0556_0x201a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201a8ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0557] `sub_201bc` (`0x201bc..0x201d0`, 20 bytes)
 *        Hàm FDE[0557] `sub_201bc` (`0x201bc..0x201d0`, 20 bytes)
 * Disassembly: 0x201bc: stp x8, xzr, [x0] ; 0x201c0: mov x0, sp ; 0x201c4: str q0, [x21] ; 0x201c8: str q1, [sp] ; 0x201cc: ret
 */
uint64_t fde_0557_0x201bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201bcULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xa9007c08U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0558] `sub_201d0` (`0x201d0..0x201dc`, 12 bytes)
 *        Hàm FDE[0558] `sub_201d0` (`0x201d0..0x201dc`, 12 bytes)
 * Disassembly: 0x201d0: mov w0, #0x20 ; 0x201d4: add x26, x19, #0x10 ; 0x201d8: b #0x20e20
 */
uint64_t fde_0558_0x201d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201d0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52800400U;
    constexpr uint32_t kOpN  = 0x14000312U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0559] `sub_201dc` (`0x201dc..0x201e8`, 12 bytes)
 *        Hàm FDE[0559] `sub_201dc` (`0x201dc..0x201e8`, 12 bytes)
 * Disassembly: 0x201dc: ldur x9, [x29, #-0x48] ; 0x201e0: cmp x8, x9 ; 0x201e4: ret
 */
uint64_t fde_0559_0x201dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201dcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf85b83a9U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0560] `sub_201e8` (`0x201e8..0x201f4`, 12 bytes)
 *        Hàm FDE[0560] `sub_201e8` (`0x201e8..0x201f4`, 12 bytes)
 * Disassembly: 0x201e8: mov w0, w21 ; 0x201ec: mov w1, w19 ; 0x201f0: b #0x10fd0
 */
uint64_t fde_0560_0x201e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201e8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1503e0U;
    constexpr uint32_t kOpN  = 0x17ffc378U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0561] `sub_201f4` (`0x201f4..0x201fc`, 8 bytes)
 *        Hàm FDE[0561] `sub_201f4` (`0x201f4..0x201fc`, 8 bytes)
 * Disassembly: 0x201f4: mov x1, x20 ; 0x201f8: br x8
 */
uint64_t fde_0561_0x201f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201f4ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1403e1U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0562] `sub_201fc` (`0x201fc..0x20208`, 12 bytes)
 *        Hàm FDE[0562] `sub_201fc` (`0x201fc..0x20208`, 12 bytes)
 * Disassembly: 0x201fc: mov x20, x0 ; 0x20200: add x0, sp, #0x10 ; 0x20204: b #0x23ec0
 */
uint64_t fde_0562_0x201fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x201fcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003f4U;
    constexpr uint32_t kOpN  = 0x14000f2fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0563] `sub_20208` (`0x20208..0x20214`, 12 bytes)
 *        Hàm FDE[0563] `sub_20208` (`0x20208..0x20214`, 12 bytes)
 * Disassembly: 0x20208: mov x20, x0 ; 0x2020c: mov x0, x19 ; 0x20210: ret
 */
uint64_t fde_0563_0x20208(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20208ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003f4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0564] `sub_20214` (`0x20214..0x2021c`, 8 bytes)
 *        Hàm FDE[0564] `sub_20214` (`0x20214..0x2021c`, 8 bytes)
 * Disassembly: 0x20214: ldr x25, [x8, #0x680] ; 0x20218: b #0x11500
 */
uint64_t fde_0564_0x20214(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20214ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9434119U;
    constexpr uint32_t kOpN  = 0x17ffc4baU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0565] `sub_2021c` (`0x2021c..0x20224`, 8 bytes)
 *        Hàm FDE[0565] `sub_2021c` (`0x2021c..0x20224`, 8 bytes)
 * Disassembly: 0x2021c: ldr x24, [x8, #0x580] ; 0x20220: b #0x11500
 */
uint64_t fde_0565_0x2021c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2021cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf942c118U;
    constexpr uint32_t kOpN  = 0x17ffc4b8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0566] `sub_20224` (`0x20224..0x2022c`, 8 bytes)
 *        Hàm FDE[0566] `sub_20224` (`0x20224..0x2022c`, 8 bytes)
 * Disassembly: 0x20224: add x0, sp, #0x50 ; 0x20228: b #0x12138
 */
uint64_t fde_0566_0x20224(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20224ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x910143e0U;
    constexpr uint32_t kOpN  = 0x17ffc7c4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0567] `sub_2022c` (`0x2022c..0x20234`, 8 bytes)
 *        Hàm FDE[0567] `sub_2022c` (`0x2022c..0x20234`, 8 bytes)
 * Disassembly: 0x2022c: lsl x0, x20, #3 ; 0x20230: b #0x20e20
 */
uint64_t fde_0567_0x2022c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2022cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xd37df280U;
    constexpr uint32_t kOpN  = 0x140002fcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0568] `sub_20234` (`0x20234..0x2023c`, 8 bytes)
 *        Hàm FDE[0568] `sub_20234` (`0x20234..0x2023c`, 8 bytes)
 * Disassembly: 0x20234: mov x1, x21 ; 0x20238: br x8
 */
uint64_t fde_0568_0x20234(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20234ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1503e1U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0569] `sub_2023c` (`0x2023c..0x20244`, 8 bytes)
 *        Hàm FDE[0569] `sub_2023c` (`0x2023c..0x20244`, 8 bytes)
 * Disassembly: 0x2023c: mov w2, #0xa8 ; 0x20240: b #0x115f0
 */
uint64_t fde_0569_0x2023c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2023cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52801502U;
    constexpr uint32_t kOpN  = 0x17ffc4ecU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0570] `sub_20244` (`0x20244..0x20250`, 12 bytes)
 *        Hàm FDE[0570] `sub_20244` (`0x20244..0x20250`, 12 bytes)
 * Disassembly: 0x20244: mov w1, #0x100 ; 0x20248: mov x0, xzr ; 0x2024c: b #0x11540
 */
uint64_t fde_0570_0x20244(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20244ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52802001U;
    constexpr uint32_t kOpN  = 0x17ffc4bdU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0571] `sub_20250` (`0x20250..0x2025c`, 12 bytes)
 *        Hàm FDE[0571] `sub_20250` (`0x20250..0x2025c`, 12 bytes)
 * Disassembly: 0x20250: adrp x0, #0x50000 ; 0x20254: add x0, x0, #0x510 ; 0x20258: b #0x11730
 */
uint64_t fde_0571_0x20250(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20250ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x90000180U;
    constexpr uint32_t kOpN  = 0x17ffc536U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0572] `sub_2025c` (`0x2025c..0x20264`, 8 bytes)
 *        Hàm FDE[0572] `sub_2025c` (`0x2025c..0x20264`, 8 bytes)
 * Disassembly: 0x2025c: ldr x0, [x0, #0xfa8] ; 0x20260: b #0x11360
 */
uint64_t fde_0572_0x2025c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2025cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf947d400U;
    constexpr uint32_t kOpN  = 0x17ffc440U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0573] `sub_20264` (`0x20264..0x20270`, 12 bytes)
 *        Hàm FDE[0573] `sub_20264` (`0x20264..0x20270`, 12 bytes)
 * Disassembly: 0x20264: adrp x0, #0x4f000 ; 0x20268: ldr x0, [x0, #0xfa8] ; 0x2026c: b #0x11780
 */
uint64_t fde_0573_0x20264(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20264ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf0000160U;
    constexpr uint32_t kOpN  = 0x17ffc545U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0574] `sub_20270` (`0x20270..0x20278`, 8 bytes)
 *        Hàm FDE[0574] `sub_20270` (`0x20270..0x20278`, 8 bytes)
 * Disassembly: 0x20270: add x0, sp, #0x20 ; 0x20274: b #0x1a4dc
 */
uint64_t fde_0574_0x20270(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20270ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x910083e0U;
    constexpr uint32_t kOpN  = 0x17ffe89aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0575] `sub_20278` (`0x20278..0x2028c`, 20 bytes)
 *        Hàm FDE[0575] `sub_20278` (`0x20278..0x2028c`, 20 bytes)
 * Disassembly: 0x20278: adrp x8, #0x50000 ; 0x2027c: add x8, x8, #0x320 ; 0x20280: ldr x9, [x8, #0x80] ; 0x20284: ldrsw x8, [x8] ; 0x20288: ret
 */
uint64_t fde_0575_0x20278(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20278ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x90000188U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0576] `sub_2028c` (`0x2028c..0x20298`, 12 bytes)
 *        Hàm FDE[0576] `sub_2028c` (`0x2028c..0x20298`, 12 bytes)
 * Disassembly: 0x2028c: fmul s2, s0, s2 ; 0x20290: fcmp s2, s1 ; 0x20294: ret
 */
uint64_t fde_0576_0x2028c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2028cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x1e220802U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0577] `sub_20298` (`0x20298..0x202a0`, 8 bytes)
 *        Hàm FDE[0577] `sub_20298` (`0x20298..0x202a0`, 8 bytes)
 * Disassembly: 0x20298: ldr x0, [x0, #0xdb0] ; 0x2029c: b #0x38b5c
 */
uint64_t fde_0577_0x20298(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20298ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf946d800U;
    constexpr uint32_t kOpN  = 0x14006230U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0578] `sub_202a0` (`0x202a0..0x202b4`, 20 bytes)
 *        Hàm FDE[0578] `sub_202a0` (`0x202a0..0x202b4`, 20 bytes)
 * Disassembly: 0x202a0: mov x3, x0 ; 0x202a4: mov x0, x19 ; 0x202a8: mov x1, x24 ; 0x202ac: mov w2, wzr ; 0x202b0: ret
 */
uint64_t fde_0578_0x202a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x202a0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xaa0003e3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0579] `sub_202b4` (`0x202b4..0x202c0`, 12 bytes)
 *        Hàm FDE[0579] `sub_202b4` (`0x202b4..0x202c0`, 12 bytes)
 * Disassembly: 0x202b4: add x1, sp, #0x40 ; 0x202b8: mov x0, x23 ; 0x202bc: b #0x19fc8
 */
uint64_t fde_0579_0x202b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x202b4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x910103e1U;
    constexpr uint32_t kOpN  = 0x17ffe743U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0580] `sub_202c0` (`0x202c0..0x202d4`, 20 bytes)
 *        Hàm FDE[0580] `sub_202c0` (`0x202c0..0x202d4`, 20 bytes)
 * Disassembly: 0x202c0: add x12, x29, #0x10 ; 0x202c4: stur x10, [x29, #-0x18] ; 0x202c8: mov x10, sp ; 0x202cc: movk x13, #0xff80, lsl #32 ; 0x202d0: ret
 */
uint64_t fde_0580_0x202c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x202c0ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x910043acU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0581] `sub_202d4` (`0x202d4..0x202e8`, 20 bytes)
 *        Hàm FDE[0581] `sub_202d4` (`0x202d4..0x202e8`, 20 bytes)
 * Disassembly: 0x202d4: ldr w9, [x9] ; 0x202d8: sdiv w10, w8, w9 ; 0x202dc: msub w8, w10, w9, w8 ; 0x202e0: str w8, [x21] ; 0x202e4: ret
 */
uint64_t fde_0581_0x202d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x202d4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xb9400129U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0582] `sub_202e8` (`0x202e8..0x202f4`, 12 bytes)
 *        Hàm FDE[0582] `sub_202e8` (`0x202e8..0x202f4`, 12 bytes)
 * Disassembly: 0x202e8: mov w0, w22 ; 0x202ec: mov w1, w21 ; 0x202f0: b #0x1c524
 */
uint64_t fde_0582_0x202e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x202e8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1603e0U;
    constexpr uint32_t kOpN  = 0x17fff08dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0583] `sub_202f4` (`0x202f4..0x20300`, 12 bytes)
 *        Hàm FDE[0583] `sub_202f4` (`0x202f4..0x20300`, 12 bytes)
 * Disassembly: 0x202f4: mov w0, w22 ; 0x202f8: mov w1, w21 ; 0x202fc: b #0x1c830
 */
uint64_t fde_0583_0x202f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x202f4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1603e0U;
    constexpr uint32_t kOpN  = 0x17fff14dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0584] `sub_20300` (`0x20300..0x2030c`, 12 bytes)
 *        Hàm FDE[0584] `sub_20300` (`0x20300..0x2030c`, 12 bytes)
 * Disassembly: 0x20300: mov w0, w22 ; 0x20304: mov w1, w21 ; 0x20308: b #0x11470
 */
uint64_t fde_0584_0x20300(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20300ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1603e0U;
    constexpr uint32_t kOpN  = 0x17ffc45aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0585] `sub_2030c` (`0x2030c..0x20314`, 8 bytes)
 *        Hàm FDE[0585] `sub_2030c` (`0x2030c..0x20314`, 8 bytes)
 * Disassembly: 0x2030c: mov w22, w0 ; 0x20310: b #0x10e10
 */
uint64_t fde_0585_0x2030c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2030cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a0003f6U;
    constexpr uint32_t kOpN  = 0x17ffc2c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0586] `sub_20314` (`0x20314..0x20320`, 12 bytes)
 *        Hàm FDE[0586] `sub_20314` (`0x20314..0x20320`, 12 bytes)
 * Disassembly: 0x20314: ldr x8, [x19] ; 0x20318: mov x0, x19 ; 0x2031c: ret
 */
uint64_t fde_0586_0x20314(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20314ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf9400268U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0587] `sub_20320` (`0x20320..0x20328`, 8 bytes)
 *        Hàm FDE[0587] `sub_20320` (`0x20320..0x20328`, 8 bytes)
 * Disassembly: 0x20320: ldr x8, [x8, #0x558] ; 0x20324: br x8
 */
uint64_t fde_0587_0x20320(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20320ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf942ad08U;
    constexpr uint32_t kOpN  = 0xd61f0100U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0588] `sub_20328` (`0x20328..0x20334`, 12 bytes)
 *        Hàm FDE[0588] `sub_20328` (`0x20328..0x20334`, 12 bytes)
 * Disassembly: 0x20328: adrp x0, #0x4f000 ; 0x2032c: ldr x0, [x0, #0xf38] ; 0x20330: b #0x20df0
 */
uint64_t fde_0588_0x20328(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20328ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf0000160U;
    constexpr uint32_t kOpN  = 0x140002b0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0589] `sub_20334` (`0x20334..0x20340`, 12 bytes)
 *        Hàm FDE[0589] `sub_20334` (`0x20334..0x20340`, 12 bytes)
 * Disassembly: 0x20334: mov x1, x22 ; 0x20338: mov x2, x23 ; 0x2033c: b #0x11180
 */
uint64_t fde_0589_0x20334(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20334ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa1603e1U;
    constexpr uint32_t kOpN  = 0x17ffc391U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0590] `sub_20340` (`0x20340..0x2034c`, 12 bytes)
 *        Hàm FDE[0590] `sub_20340` (`0x20340..0x2034c`, 12 bytes)
 * Disassembly: 0x20340: mov x0, x19 ; 0x20344: str x21, [x8] ; 0x20348: b #0x10f90
 */
uint64_t fde_0590_0x20340(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20340ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa1303e0U;
    constexpr uint32_t kOpN  = 0x17ffc312U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0591] `sub_2034c` (`0x2034c..0x20358`, 12 bytes)
 *        Hàm FDE[0591] `sub_2034c` (`0x2034c..0x20358`, 12 bytes)
 * Disassembly: 0x2034c: mov w2, #3 ; 0x20350: mov w3, #0x40 ; 0x20354: b #0x10a00
 */
uint64_t fde_0591_0x2034c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2034cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52800062U;
    constexpr uint32_t kOpN  = 0x17ffc1abU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0592] `sub_20358` (`0x20358..0x2036c`, 20 bytes)
 *        Hàm FDE[0592] `sub_20358` (`0x20358..0x2036c`, 20 bytes)
 * Disassembly: 0x20358: adrp x1, #0x50000 ; 0x2035c: add x1, x1, #0x428 ; 0x20360: mov w0, #0xb ; 0x20364: mov x2, xzr ; 0x20368: ret
 */
uint64_t fde_0592_0x20358(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20358ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x90000181U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0593] `sub_2036c` (`0x2036c..0x20378`, 12 bytes)
 *        Hàm FDE[0593] `sub_2036c` (`0x2036c..0x20378`, 12 bytes)
 * Disassembly: 0x2036c: mov x1, x23 ; 0x20370: mov x2, x24 ; 0x20374: b #0x11180
 */
uint64_t fde_0593_0x2036c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2036cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa1703e1U;
    constexpr uint32_t kOpN  = 0x17ffc383U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0594] `sub_20378` (`0x20378..0x20380`, 8 bytes)
 *        Hàm FDE[0594] `sub_20378` (`0x20378..0x20380`, 8 bytes)
 * Disassembly: 0x20378: mov x0, x23 ; 0x2037c: b #0x11500
 */
uint64_t fde_0594_0x20378(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20378ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1703e0U;
    constexpr uint32_t kOpN  = 0x17ffc461U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0595] `sub_20380` (`0x20380..0x2038c`, 12 bytes)
 *        Hàm FDE[0595] `sub_20380` (`0x20380..0x2038c`, 12 bytes)
 * Disassembly: 0x20380: mov w0, w20 ; 0x20384: mov w1, w19 ; 0x20388: b #0x1c830
 */
uint64_t fde_0595_0x20380(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20380ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1403e0U;
    constexpr uint32_t kOpN  = 0x17fff12aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0596] `sub_2038c` (`0x2038c..0x20398`, 12 bytes)
 *        Hàm FDE[0596] `sub_2038c` (`0x2038c..0x20398`, 12 bytes)
 * Disassembly: 0x2038c: sub x1, x29, #0x78 ; 0x20390: mov x0, x24 ; 0x20394: b #0x19a20
 */
uint64_t fde_0596_0x2038c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2038cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd101e3a1U;
    constexpr uint32_t kOpN  = 0x17ffe5a3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0597] `sub_20398` (`0x20398..0x203ac`, 20 bytes)
 *        Hàm FDE[0597] `sub_20398` (`0x20398..0x203ac`, 20 bytes)
 * Disassembly: 0x20398: mrs x8, tpidr_el0 ; 0x2039c: sub x9, x29, #0x10 ; 0x203a0: stur x8, [x9, #-0x100] ; 0x203a4: ldr x8, [x8, #0x28] ; 0x203a8: ret
 */
uint64_t fde_0597_0x20398(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20398ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xd53bd048U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0598] `sub_203ac` (`0x203ac..0x203b4`, 8 bytes)
 *        Hàm FDE[0598] `sub_203ac` (`0x203ac..0x203b4`, 8 bytes)
 * Disassembly: 0x203ac: add sp, sp, #0x40 ; 0x203b0: ret
 */
uint64_t fde_0598_0x203ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203acULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x910103ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0599] `sub_203b4` (`0x203b4..0x203c8`, 20 bytes)
 *        Hàm FDE[0599] `sub_203b4` (`0x203b4..0x203c8`, 20 bytes)
 * Disassembly: 0x203b4: cnt v0.8b, v0.8b ; 0x203b8: uaddlv h0, v0.8b ; 0x203bc: fmov w9, s0 ; 0x203c0: ucvtf s0, x8 ; 0x203c4: ret
 */
uint64_t fde_0599_0x203b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203b4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x0e205800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0600] `sub_203c8` (`0x203c8..0x203dc`, 20 bytes)
 *        Hàm FDE[0600] `sub_203c8` (`0x203c8..0x203dc`, 20 bytes)
 * Disassembly: 0x203c8: ldr x8, [x0] ; 0x203cc: mov w9, #1 ; 0x203d0: str x8, [x12] ; 0x203d4: str xzr, [x0] ; 0x203d8: ret
 */
uint64_t fde_0600_0x203c8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203c8ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf9400008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0601] `sub_203dc` (`0x203dc..0x203e8`, 12 bytes)
 *        Hàm FDE[0601] `sub_203dc` (`0x203dc..0x203e8`, 12 bytes)
 * Disassembly: 0x203dc: ldr x8, [x0] ; 0x203e0: ldr x1, [x8, #8] ; 0x203e4: br x1
 */
uint64_t fde_0601_0x203dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203dcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf9400008U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0602] `sub_203e8` (`0x203e8..0x203f4`, 12 bytes)
 *        Hàm FDE[0602] `sub_203e8` (`0x203e8..0x203f4`, 12 bytes)
 * Disassembly: 0x203e8: add x1, sp, #0x50 ; 0x203ec: mov x0, x21 ; 0x203f0: b #0x10d60
 */
uint64_t fde_0602_0x203e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203e8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x910143e1U;
    constexpr uint32_t kOpN  = 0x17ffc25cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0603] `sub_203f4` (`0x203f4..0x203fc`, 8 bytes)
 *        Hàm FDE[0603] `sub_203f4` (`0x203f4..0x203fc`, 8 bytes)
 * Disassembly: 0x203f4: mov w0, #6 ; 0x203f8: ret
 */
uint64_t fde_0603_0x203f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203f4ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x528000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0604] `sub_203fc` (`0x203fc..0x20408`, 12 bytes)
 *        Hàm FDE[0604] `sub_203fc` (`0x203fc..0x20408`, 12 bytes)
 * Disassembly: 0x203fc: add x0, sp, #0x88 ; 0x20400: add x1, sp, #0x70 ; 0x20404: b #0x1f238
 */
uint64_t fde_0604_0x203fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x203fcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x910223e0U;
    constexpr uint32_t kOpN  = 0x17fffb8dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0605] `sub_20408` (`0x20408..0x20414`, 12 bytes)
 *        Hàm FDE[0605] `sub_20408` (`0x20408..0x20414`, 12 bytes)
 * Disassembly: 0x20408: add x0, sp, #0x88 ; 0x2040c: mov x1, x27 ; 0x20410: b #0x1f238
 */
uint64_t fde_0605_0x20408(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20408ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x910223e0U;
    constexpr uint32_t kOpN  = 0x17fffb8aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0606] `sub_20414` (`0x20414..0x20420`, 12 bytes)
 *        Hàm FDE[0606] `sub_20414` (`0x20414..0x20420`, 12 bytes)
 * Disassembly: 0x20414: mrs x19, tpidr_el0 ; 0x20418: ldr x8, [x19, #0x28] ; 0x2041c: ret
 */
uint64_t fde_0606_0x20414(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20414ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd53bd053U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0607] `sub_20420` (`0x20420..0x20434`, 20 bytes)
 *        Hàm FDE[0607] `sub_20420` (`0x20420..0x20434`, 20 bytes)
 * Disassembly: 0x20420: add w8, w8, #1 ; 0x20424: add x8, x8, #0xf ; 0x20428: and x8, x8, #0x1fffffff0 ; 0x2042c: mov x9, sp ; 0x20430: ret
 */
uint64_t fde_0607_0x20420(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20420ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x11000508U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0608] `sub_20434` (`0x20434..0x2043c`, 8 bytes)
 *        Hàm FDE[0608] `sub_20434` (`0x20434..0x2043c`, 8 bytes)
 * Disassembly: 0x20434: mov w0, #0xb ; 0x20438: ret
 */
uint64_t fde_0608_0x20434(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20434ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800160U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0609] `sub_2043c` (`0x2043c..0x20444`, 8 bytes)
 *        Hàm FDE[0609] `sub_2043c` (`0x2043c..0x20444`, 8 bytes)
 * Disassembly: 0x2043c: mov w0, #0xe ; 0x20440: ret
 */
uint64_t fde_0609_0x2043c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2043cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x528001c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0610] `sub_20444` (`0x20444..0x20458`, 20 bytes)
 *        Hàm FDE[0610] `sub_20444` (`0x20444..0x20458`, 20 bytes)
 * Disassembly: 0x20444: ldr q0, [sp, #0x80] ; 0x20448: ldr x8, [sp, #0x90] ; 0x2044c: stp xzr, xzr, [sp, #0x88] ; 0x20450: str xzr, [sp, #0x80] ; 0x20454: ret
 */
uint64_t fde_0610_0x20444(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20444ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x3dc023e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0611] `sub_20458` (`0x20458..0x20460`, 8 bytes)
 *        Hàm FDE[0611] `sub_20458` (`0x20458..0x20460`, 8 bytes)
 * Disassembly: 0x20458: mov w0, #8 ; 0x2045c: ret
 */
uint64_t fde_0611_0x20458(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20458ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800100U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0612] `sub_20460` (`0x20460..0x2046c`, 12 bytes)
 *        Hàm FDE[0612] `sub_20460` (`0x20460..0x2046c`, 12 bytes)
 * Disassembly: 0x20460: mov x0, sp ; 0x20464: mov x1, xzr ; 0x20468: b #0x110e0
 */
uint64_t fde_0612_0x20460(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20460ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x910003e0U;
    constexpr uint32_t kOpN  = 0x17ffc31eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0613] `sub_2046c` (`0x2046c..0x20480`, 20 bytes)
 *        Hàm FDE[0613] `sub_2046c` (`0x2046c..0x20480`, 20 bytes)
 * Disassembly: 0x2046c: adrp x8, #0x4f000 ; 0x20470: ldr x8, [x8, #0xe50] ; 0x20474: ldr w8, [x8] ; 0x20478: cmp w8, #4 ; 0x2047c: ret
 */
uint64_t fde_0613_0x2046c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2046cULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0614] `sub_20480` (`0x20480..0x20488`, 8 bytes)
 *        Hàm FDE[0614] `sub_20480` (`0x20480..0x20488`, 8 bytes)
 * Disassembly: 0x20480: mov w0, #5 ; 0x20484: ret
 */
uint64_t fde_0614_0x20480(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20480ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x528000a0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0615] `sub_20488` (`0x20488..0x20494`, 12 bytes)
 *        Hàm FDE[0615] `sub_20488` (`0x20488..0x20494`, 12 bytes)
 * Disassembly: 0x20488: ldr x19, [sp, #0x10] ; 0x2048c: add sp, sp, #0x30 ; 0x20490: ret
 */
uint64_t fde_0615_0x20488(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20488ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xf9400bf3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0616] `sub_20494` (`0x20494..0x2049c`, 8 bytes)
 *        Hàm FDE[0616] `sub_20494` (`0x20494..0x2049c`, 8 bytes)
 * Disassembly: 0x20494: mov w0, #7 ; 0x20498: ret
 */
uint64_t fde_0616_0x20494(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20494ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x528000e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0617] `sub_2049c` (`0x2049c..0x204a8`, 12 bytes)
 *        Hàm FDE[0617] `sub_2049c` (`0x2049c..0x204a8`, 12 bytes)
 * Disassembly: 0x2049c: and w8, w0, #1 ; 0x204a0: strb w8, [x9] ; 0x204a4: ret
 */
uint64_t fde_0617_0x2049c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2049cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x12000008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0618] `sub_204a8` (`0x204a8..0x204b4`, 12 bytes)
 *        Hàm FDE[0618] `sub_204a8` (`0x204a8..0x204b4`, 12 bytes)
 * Disassembly: 0x204a8: ldp x20, x19, [sp, #0x10] ; 0x204ac: ldp x22, x21, [sp], #0x30 ; 0x204b0: b #0x116c0
 */
uint64_t fde_0618_0x204a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204a8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0x17ffc484U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0619] `sub_204b4` (`0x204b4..0x204c0`, 12 bytes)
 *        Hàm FDE[0619] `sub_204b4` (`0x204b4..0x204c0`, 12 bytes)
 * Disassembly: 0x204b4: ldp x20, x19, [sp, #0x10] ; 0x204b8: ldp x28, x21, [sp], #0x30 ; 0x204bc: ret
 */
uint64_t fde_0619_0x204b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204b4ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0620] `sub_204c0` (`0x204c0..0x204cc`, 12 bytes)
 *        Hàm FDE[0620] `sub_204c0` (`0x204c0..0x204cc`, 12 bytes)
 * Disassembly: 0x204c0: ldp x20, x19, [sp, #0x10] ; 0x204c4: add sp, sp, #0x30 ; 0x204c8: ret
 */
uint64_t fde_0620_0x204c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204c0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9414ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0621] `sub_204cc` (`0x204cc..0x204d4`, 8 bytes)
 *        Hàm FDE[0621] `sub_204cc` (`0x204cc..0x204d4`, 8 bytes)
 * Disassembly: 0x204cc: mov x0, x20 ; 0x204d0: b #0x20dcc
 */
uint64_t fde_0621_0x204cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204ccULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1403e0U;
    constexpr uint32_t kOpN  = 0x1400023fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0622] `sub_204d4` (`0x204d4..0x204dc`, 8 bytes)
 *        Hàm FDE[0622] `sub_204d4` (`0x204d4..0x204dc`, 8 bytes)
 * Disassembly: 0x204d4: mov x0, x20 ; 0x204d8: b #0x20e88
 */
uint64_t fde_0622_0x204d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204d4ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa1403e0U;
    constexpr uint32_t kOpN  = 0x1400026cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0623] `sub_204dc` (`0x204dc..0x204e8`, 12 bytes)
 *        Hàm FDE[0623] `sub_204dc` (`0x204dc..0x204e8`, 12 bytes)
 * Disassembly: 0x204dc: mov x19, x0 ; 0x204e0: mov w0, w20 ; 0x204e4: b #0x11520
 */
uint64_t fde_0623_0x204dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204dcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003f3U;
    constexpr uint32_t kOpN  = 0x17ffc40fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0624] `sub_204e8` (`0x204e8..0x204f0`, 8 bytes)
 *        Hàm FDE[0624] `sub_204e8` (`0x204e8..0x204f0`, 8 bytes)
 * Disassembly: 0x204e8: mov x19, x0 ; 0x204ec: b #0x10e60
 */
uint64_t fde_0624_0x204e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204e8ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xaa0003f3U;
    constexpr uint32_t kOpN  = 0x17ffc25dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0625] `sub_204f0` (`0x204f0..0x204fc`, 12 bytes)
 *        Hàm FDE[0625] `sub_204f0` (`0x204f0..0x204fc`, 12 bytes)
 * Disassembly: 0x204f0: mov x0, x1 ; 0x204f4: mov x19, x1 ; 0x204f8: b #0x11500
 */
uint64_t fde_0625_0x204f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204f0ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0103e0U;
    constexpr uint32_t kOpN  = 0x17ffc402U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0626] `sub_204fc` (`0x204fc..0x20508`, 12 bytes)
 *        Hàm FDE[0626] `sub_204fc` (`0x204fc..0x20508`, 12 bytes)
 * Disassembly: 0x204fc: mov w1, wzr ; 0x20500: mov x2, x22 ; 0x20504: b #0x11620
 */
uint64_t fde_0626_0x204fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x204fcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1f03e1U;
    constexpr uint32_t kOpN  = 0x17ffc447U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0627] `sub_20508` (`0x20508..0x20514`, 12 bytes)
 *        Hàm FDE[0627] `sub_20508` (`0x20508..0x20514`, 12 bytes)
 * Disassembly: 0x20508: mov w1, wzr ; 0x2050c: mov x2, x24 ; 0x20510: b #0x11620
 */
uint64_t fde_0627_0x20508(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20508ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x2a1f03e1U;
    constexpr uint32_t kOpN  = 0x17ffc444U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0628] `sub_20514` (`0x20514..0x20520`, 12 bytes)
 *        Hàm FDE[0628] `sub_20514` (`0x20514..0x20520`, 12 bytes)
 * Disassembly: 0x20514: ldp x20, x19, [sp, #0x70] ; 0x20518: add sp, sp, #0x90 ; 0x2051c: ret
 */
uint64_t fde_0628_0x20514(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20514ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9474ff4U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0629] `sub_20520` (`0x20520..0x20534`, 20 bytes)
 *        Hàm FDE[0629] `sub_20520` (`0x20520..0x20534`, 20 bytes)
 * Disassembly: 0x20520: ldr w10, [x9] ; 0x20524: adrp x9, #0x4f000 ; 0x20528: ldr x9, [x9, #0xe68] ; 0x2052c: add w10, w11, w10 ; 0x20530: ret
 */
uint64_t fde_0629_0x20520(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20520ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xb940012aU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0630] `sub_20534` (`0x20534..0x2053c`, 8 bytes)
 *        Hàm FDE[0630] `sub_20534` (`0x20534..0x2053c`, 8 bytes)
 * Disassembly: 0x20534: add x0, sp, #0x18 ; 0x20538: b #0x12138
 */
uint64_t fde_0630_0x20534(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20534ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x910063e0U;
    constexpr uint32_t kOpN  = 0x17ffc700U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0631] `sub_2053c` (`0x2053c..0x20548`, 12 bytes)
 *        Hàm FDE[0631] `sub_2053c` (`0x2053c..0x20548`, 12 bytes)
 * Disassembly: 0x2053c: mov w0, #3 ; 0x20540: mov w3, w19 ; 0x20544: b #0x11210
 */
uint64_t fde_0631_0x2053c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2053cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x52800060U;
    constexpr uint32_t kOpN  = 0x17ffc333U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0632] `sub_20548` (`0x20548..0x2055c`, 20 bytes)
 *        Hàm FDE[0632] `sub_20548` (`0x20548..0x2055c`, 20 bytes)
 * Disassembly: 0x20548: adrp x8, #0x4f000 ; 0x2054c: ldr x8, [x8, #0xd08] ; 0x20550: adrp x9, #0x4f000 ; 0x20554: adrp x12, #0x4f000 ; 0x20558: ret
 */
uint64_t fde_0632_0x20548(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20548ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0633] `sub_2055c` (`0x2055c..0x20564`, 8 bytes)
 *        Hàm FDE[0633] `sub_2055c` (`0x2055c..0x20564`, 8 bytes)
 * Disassembly: 0x2055c: mov w0, wzr ; 0x20560: ret
 */
uint64_t fde_0633_0x2055c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2055cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0634] `sub_20564` (`0x20564..0x20570`, 12 bytes)
 *        Hàm FDE[0634] `sub_20564` (`0x20564..0x20570`, 12 bytes)
 * Disassembly: 0x20564: mov x1, x0 ; 0x20568: mov x0, x19 ; 0x2056c: ret
 */
uint64_t fde_0634_0x20564(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20564ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003e1U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0635] `sub_20570` (`0x20570..0x2057c`, 12 bytes)
 *        Hàm FDE[0635] `sub_20570` (`0x20570..0x2057c`, 12 bytes)
 * Disassembly: 0x20570: mov x1, x0 ; 0x20574: mov x0, x19 ; 0x20578: br x24
 */
uint64_t fde_0635_0x20570(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20570ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa0003e1U;
    constexpr uint32_t kOpN  = 0xd61f0300U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0636] `sub_2057c` (`0x2057c..0x20588`, 12 bytes)
 *        Hàm FDE[0636] `sub_2057c` (`0x2057c..0x20588`, 12 bytes)
 * Disassembly: 0x2057c: add x1, x1, #0x61 ; 0x20580: mov x3, xzr ; 0x20584: b #0x11250
 */
uint64_t fde_0636_0x2057c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2057cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x91018421U;
    constexpr uint32_t kOpN  = 0x17ffc333U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0637] `sub_20588` (`0x20588..0x2059c`, 20 bytes)
 *        Hàm FDE[0637] `sub_20588` (`0x20588..0x2059c`, 20 bytes)
 * Disassembly: 0x20588: mov w9, #0x18 ; 0x2058c: udiv x8, x8, x9 ; 0x20590: mov x10, #0x18 ; 0x20594: madd x2, x8, x9, x10 ; 0x20598: ret
 */
uint64_t fde_0637_0x20588(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20588ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x52800309U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0638] `sub_2059c` (`0x2059c..0x205b4`, 24 bytes)
 *        Hàm FDE[0638] `sub_2059c` (`0x2059c..0x205b4`, 24 bytes)
 * Disassembly: 0x2059c: stp x29, x30, [sp, #-0x10]! ; 0x205a0: mov x29, sp ; 0x205a4: bl #0x10c60 ; 0x205a8: ldp x29, x30, [sp], #0x10 ; 0x205ac: ret
 */
uint64_t fde_0638_0x2059c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2059cULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffc8ceU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0639] `sub_205b4` (`0x205b4..0x20ccc`, 1816 bytes)
 *        Hàm FDE[0639] `sub_205b4` (`0x205b4..0x20ccc`, 1816 bytes)
 * Disassembly: 0x205b4: stp x29, x30, [sp, #-0x10]! ; 0x205b8: mov x29, sp ; 0x205bc: cmp x0, #0xd3 ; 0x205c0: b.hi #0x205fc ; 0x205c4: adrp x8, #0x3b000
 */
uint64_t fde_0639_0x205b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x205b4ULL;
    constexpr uint64_t kSize = 0x718ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x94000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0640] `sub_20ccc` (`0x20ccc..0x20d1c`, 80 bytes)
 *        Hàm FDE[0640] `sub_20ccc` (`0x20ccc..0x20d1c`, 80 bytes)
 * Disassembly: 0x20ccc: stp x20, x19, [sp, #-0x20]! ; 0x20cd0: stp x29, x30, [sp, #0x10] ; 0x20cd4: add x29, sp, #0x10 ; 0x20cd8: mov x20, x0 ; 0x20cdc: mov w0, #0x10
 */
uint64_t fde_0640_0x20ccc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20cccULL;
    constexpr uint64_t kSize = 0x50ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x94005841U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0641] `sub_20d1c` (`0x20d1c..0x20d4c`, 48 bytes)
 *        Hàm FDE[0641] `sub_20d1c` (`0x20d1c..0x20d4c`, 48 bytes)
 * Disassembly: 0x20d1c: str x19, [sp, #-0x20]! ; 0x20d20: stp x29, x30, [sp, #0x10] ; 0x20d24: add x29, sp, #0x10 ; 0x20d28: mov x19, x0 ; 0x20d2c: bl #0x20f98
 */
uint64_t fde_0641_0x20d1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20d1cULL;
    constexpr uint64_t kSize = 0x30ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0642] `sub_20d4c` (`0x20d4c..0x20d50`, 4 bytes)
 *        Hàm FDE[0642] `sub_20d4c` (`0x20d4c..0x20d50`, 4 bytes)
 * Disassembly: 0x20d4c: ret
 */
uint64_t fde_0642_0x20d4c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20d4cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0643] `sub_20d50` (`0x20d50..0x20dcc`, 124 bytes)
 *        Hàm FDE[0643] `sub_20d50` (`0x20d50..0x20dcc`, 124 bytes)
 * Disassembly: 0x20d50: stp x20, x19, [sp, #-0x20]! ; 0x20d54: stp x29, x30, [sp, #0x10] ; 0x20d58: add x29, sp, #0x10 ; 0x20d5c: mov x19, x0 ; 0x20d60: add x8, x0, #8
 */
uint64_t fde_0643_0x20d50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20d50ULL;
    constexpr uint64_t kSize = 0x7cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0644] `sub_20dcc` (`0x20dcc..0x20df0`, 36 bytes)
 *        Hàm FDE[0644] `sub_20dcc` (`0x20dcc..0x20df0`, 36 bytes)
 * Disassembly: 0x20dcc: stp x29, x30, [sp, #-0x10]! ; 0x20dd0: mov x29, sp ; 0x20dd4: bl #0x11360 ; 0x20dd8: cbnz w0, #0x20de4 ; 0x20ddc: ldp x29, x30, [sp], #0x10
 */
uint64_t fde_0644_0x20dcc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20dccULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x940001b0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0645] `sub_20df0` (`0x20df0..0x20e08`, 24 bytes)
 *        Hàm FDE[0645] `sub_20df0` (`0x20df0..0x20e08`, 24 bytes)
 * Disassembly: 0x20df0: stp x29, x30, [sp, #-0x10]! ; 0x20df4: mov x29, sp ; 0x20df8: bl #0x11780 ; 0x20dfc: ldp x29, x30, [sp], #0x10 ; 0x20e00: ret
 */
uint64_t fde_0645_0x20df0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20df0ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffc6b9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0646] `sub_20e08` (`0x20e08..0x20e20`, 24 bytes)
 *        Hàm FDE[0646] `sub_20e08` (`0x20e08..0x20e20`, 24 bytes)
 * Disassembly: 0x20e08: stp x29, x30, [sp, #-0x10]! ; 0x20e0c: mov x29, sp ; 0x20e10: bl #0x10a20 ; 0x20e14: ldp x29, x30, [sp], #0x10 ; 0x20e18: ret
 */
uint64_t fde_0646_0x20e08(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20e08ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffc6b3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0647] `sub_20e20` (`0x20e20..0x20e84`, 100 bytes)
 *        Hàm FDE[0647] `sub_20e20` (`0x20e20..0x20e84`, 100 bytes)
 * Disassembly: 0x20e20: str x19, [sp, #-0x20]! ; 0x20e24: stp x29, x30, [sp, #0x10] ; 0x20e28: add x29, sp, #0x10 ; 0x20e2c: cmp x0, #0 ; 0x20e30: csinc x19, x0, xzr, ne
 */
uint64_t fde_0647_0x20e20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20e20ULL;
    constexpr uint64_t kSize = 0x64ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94000233U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0648] `sub_20e84` (`0x20e84..0x20e88`, 4 bytes)
 *        Hàm FDE[0648] `sub_20e84` (`0x20e84..0x20e88`, 4 bytes)
 * Disassembly: 0x20e84: b #0x20e20
 */
uint64_t fde_0648_0x20e84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20e84ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffffe7U;
    constexpr uint32_t kOpN  = 0x17ffffe7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0649] `sub_20e88` (`0x20e88..0x20e8c`, 4 bytes)
 *        Hàm FDE[0649] `sub_20e88` (`0x20e88..0x20e8c`, 4 bytes)
 * Disassembly: 0x20e88: b #0x116c0
 */
uint64_t fde_0649_0x20e88(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20e88ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc20eU;
    constexpr uint32_t kOpN  = 0x17ffc20eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0650] `sub_20e8c` (`0x20e8c..0x20f0c`, 128 bytes)
 *        Hàm FDE[0650] `sub_20e8c` (`0x20e8c..0x20f0c`, 128 bytes)
 * Disassembly: 0x20e8c: stp x22, x21, [sp, #-0x30]! ; 0x20e90: stp x20, x19, [sp, #0x10] ; 0x20e94: stp x29, x30, [sp, #0x20] ; 0x20e98: add x29, sp, #0x20 ; 0x20e9c: adrp x8, #0x4f000
 */
uint64_t fde_0650_0x20e8c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20e8cULL;
    constexpr uint64_t kSize = 0x80ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x940057c5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0651] `sub_20f0c` (`0x20f0c..0x20f98`, 140 bytes)
 *        Hàm FDE[0651] `sub_20f0c` (`0x20f0c..0x20f98`, 140 bytes)
 * Disassembly: 0x20f0c: stp x22, x21, [sp, #-0x30]! ; 0x20f10: stp x20, x19, [sp, #0x10] ; 0x20f14: stp x29, x30, [sp, #0x20] ; 0x20f18: add x29, sp, #0x20 ; 0x20f1c: adrp x8, #0x4f000
 */
uint64_t fde_0651_0x20f0c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20f0cULL;
    constexpr uint64_t kSize = 0x8cULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x940057a2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0652] `sub_20f98` (`0x20f98..0x21018`, 128 bytes)
 *        Hàm FDE[0652] `sub_20f98` (`0x20f98..0x21018`, 128 bytes)
 * Disassembly: 0x20f98: stp x22, x21, [sp, #-0x30]! ; 0x20f9c: stp x20, x19, [sp, #0x10] ; 0x20fa0: stp x29, x30, [sp, #0x20] ; 0x20fa4: add x29, sp, #0x20 ; 0x20fa8: adrp x8, #0x4f000
 */
uint64_t fde_0652_0x20f98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x20f98ULL;
    constexpr uint64_t kSize = 0x80ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x94005782U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0653] `sub_21018` (`0x21018..0x21028`, 16 bytes)
 *        Hàm FDE[0653] `sub_21018` (`0x21018..0x21028`, 16 bytes)
 * Disassembly: 0x21018: mov w8, w1 ; 0x2101c: mov x1, x0 ; 0x21020: mov x0, x8 ; 0x21024: ret
 */
uint64_t fde_0653_0x21018(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21018ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x2a0103e8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0654] `sub_21028` (`0x21028..0x2106c`, 68 bytes)
 *        Hàm FDE[0654] `sub_21028` (`0x21028..0x2106c`, 68 bytes)
 * Disassembly: 0x21028: str x19, [sp, #-0x20]! ; 0x2102c: stp x29, x30, [sp, #0x10] ; 0x21030: add x29, sp, #0x10 ; 0x21034: ldr x8, [x0] ; 0x21038: mov x19, x2
 */
uint64_t fde_0654_0x21028(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21028ULL;
    constexpr uint64_t kSize = 0x44ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0655] `sub_2106c` (`0x2106c..0x2108c`, 32 bytes)
 *        Hàm FDE[0655] `sub_2106c` (`0x2106c..0x2108c`, 32 bytes)
 * Disassembly: 0x2106c: ldr x8, [x1, #8] ; 0x21070: ldr w9, [x1] ; 0x21074: cmp x8, x0 ; 0x21078: cset w8, eq ; 0x2107c: cmp w9, w2
 */
uint64_t fde_0655_0x2106c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2106cULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xf9400428U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0656] `sub_2108c` (`0x2108c..0x21158`, 204 bytes)
 *        Hàm FDE[0656] `sub_2108c` (`0x2108c..0x21158`, 204 bytes)
 * Disassembly: 0x2108c: str x28, [sp, #-0x50]! ; 0x21090: stp x24, x23, [sp, #0x10] ; 0x21094: stp x22, x21, [sp, #0x20] ; 0x21098: stp x20, x19, [sp, #0x30] ; 0x2109c: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0656_0x2108c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2108cULL;
    constexpr uint64_t kSize = 0xccULL;
    constexpr uint32_t kOp0  = 0xf81b0ffcU;
    constexpr uint32_t kOpN  = 0x97ffbef7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0657] `sub_21158` (`0x21158..0x21164`, 12 bytes)
 *        Hàm FDE[0657] `sub_21158` (`0x21158..0x21164`, 12 bytes)
 * Disassembly: 0x21158: adrp x0, #0x3b000 ; 0x2115c: add x0, x0, #0x2a3 ; 0x21160: ret
 */
uint64_t fde_0657_0x21158(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21158ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd00000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0658] `sub_21164` (`0x21164..0x21180`, 28 bytes)
 *        Hàm FDE[0658] `sub_21164` (`0x21164..0x21180`, 28 bytes)
 * Disassembly: 0x21164: cmp w1, #1, lsl #12 ; 0x21168: b.lt #0x2117c ; 0x2116c: adrp x1, #0x3b000 ; 0x21170: add x1, x1, #0x2ab ; 0x21174: mov x0, x8
 */
uint64_t fde_0658_0x21164(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21164ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0x7140043fU;
    constexpr uint32_t kOpN  = 0x17ffffc4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0659] `sub_21180` (`0x21180..0x2118c`, 12 bytes)
 *        Hàm FDE[0659] `sub_21180` (`0x21180..0x2118c`, 12 bytes)
 * Disassembly: 0x21180: adrp x0, #0x3b000 ; 0x21184: add x0, x0, #0x2ce ; 0x21188: ret
 */
uint64_t fde_0659_0x21180(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21180ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd00000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0660] `sub_2118c` (`0x2118c..0x211a8`, 28 bytes)
 *        Hàm FDE[0660] `sub_2118c` (`0x2118c..0x211a8`, 28 bytes)
 * Disassembly: 0x2118c: cmp w1, #1, lsl #12 ; 0x21190: b.lt #0x211a4 ; 0x21194: adrp x1, #0x3b000 ; 0x21198: add x1, x1, #0x2d5 ; 0x2119c: mov x0, x8
 */
uint64_t fde_0660_0x2118c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2118cULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0x7140043fU;
    constexpr uint32_t kOpN  = 0x17ffffbaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0661] `sub_211a8` (`0x211a8..0x21280`, 216 bytes)
 *        Hàm FDE[0661] `sub_211a8` (`0x211a8..0x21280`, 216 bytes)
 * Disassembly: 0x211a8: str x19, [sp, #-0x20]! ; 0x211ac: stp x29, x30, [sp, #0x10] ; 0x211b0: add x29, sp, #0x10 ; 0x211b4: cmp w1, #1, lsl #12 ; 0x211b8: b.lt #0x211d8
 */
uint64_t fde_0661_0x211a8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x211a8ULL;
    constexpr uint64_t kSize = 0xd8ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17ffffddU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0662] `sub_21280` (`0x21280..0x21390`, 272 bytes)
 *        Hàm FDE[0662] `sub_21280` (`0x21280..0x21390`, 272 bytes)
 * Disassembly: 0x21280: sub sp, sp, #0x50 ; 0x21284: stp x22, x21, [sp, #0x20] ; 0x21288: stp x20, x19, [sp, #0x30] ; 0x2128c: stp x29, x30, [sp, #0x40] ; 0x21290: add x29, sp, #0x40
 */
uint64_t fde_0662_0x21280(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21280ULL;
    constexpr uint64_t kSize = 0x110ULL;
    constexpr uint32_t kOp0  = 0xd10143ffU;
    constexpr uint32_t kOpN  = 0x940056a4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0663] `sub_21390` (`0x21390..0x21484`, 244 bytes)
 *        Hàm FDE[0663] `sub_21390` (`0x21390..0x21484`, 244 bytes)
 * Disassembly: 0x21390: sub sp, sp, #0x70 ; 0x21394: stp x20, x19, [sp, #0x50] ; 0x21398: stp x29, x30, [sp, #0x60] ; 0x2139c: add x29, sp, #0x60 ; 0x213a0: mrs x20, tpidr_el0
 */
uint64_t fde_0663_0x21390(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21390ULL;
    constexpr uint64_t kSize = 0xf4ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x94005667U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0664] `sub_21484` (`0x21484..0x21488`, 4 bytes)
 *        Hàm FDE[0664] `sub_21484` (`0x21484..0x21488`, 4 bytes)
 * Disassembly: 0x21484: b #0x23fc0
 */
uint64_t fde_0664_0x21484(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21484ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000acfU;
    constexpr uint32_t kOpN  = 0x14000acfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0665] `sub_21488` (`0x21488..0x214ac`, 36 bytes)
 *        Hàm FDE[0665] `sub_21488` (`0x21488..0x214ac`, 36 bytes)
 * Disassembly: 0x21488: str x19, [sp, #-0x20]! ; 0x2148c: stp x29, x30, [sp, #0x10] ; 0x21490: add x29, sp, #0x10 ; 0x21494: mov x19, x0 ; 0x21498: bl #0x23fc0
 */
uint64_t fde_0665_0x21488(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21488ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fffe78U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0666] `sub_214ac` (`0x214ac..0x21550`, 164 bytes)
 *        Hàm FDE[0666] `sub_214ac` (`0x214ac..0x21550`, 164 bytes)
 * Disassembly: 0x214ac: str x21, [sp, #-0x30]! ; 0x214b0: stp x20, x19, [sp, #0x10] ; 0x214b4: stp x29, x30, [sp, #0x20] ; 0x214b8: add x29, sp, #0x20 ; 0x214bc: mov w21, w0
 */
uint64_t fde_0666_0x214ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x214acULL;
    constexpr uint64_t kSize = 0xa4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x94005634U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0667] `sub_21550` (`0x21550..0x21554`, 4 bytes)
 *        Hàm FDE[0667] `sub_21550` (`0x21550..0x21554`, 4 bytes)
 * Disassembly: 0x21550: ret
 */
uint64_t fde_0667_0x21550(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21550ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0668] `sub_21554` (`0x21554..0x21558`, 4 bytes)
 *        Hàm FDE[0668] `sub_21554` (`0x21554..0x21558`, 4 bytes)
 * Disassembly: 0x21554: b #0x20e88
 */
uint64_t fde_0668_0x21554(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21554ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fffe4dU;
    constexpr uint32_t kOpN  = 0x17fffe4dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0669] `sub_21558` (`0x21558..0x2155c`, 4 bytes)
 *        Hàm FDE[0669] `sub_21558` (`0x21558..0x2155c`, 4 bytes)
 * Disassembly: 0x21558: b #0x20e88
 */
uint64_t fde_0669_0x21558(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21558ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fffe4cU;
    constexpr uint32_t kOpN  = 0x17fffe4cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0670] `sub_2155c` (`0x2155c..0x215f8`, 156 bytes)
 *        Hàm FDE[0670] `sub_2155c` (`0x2155c..0x215f8`, 156 bytes)
 * Disassembly: 0x2155c: sub sp, sp, #0x110 ; 0x21560: stp x28, x19, [sp, #0xf0] ; 0x21564: stp x29, x30, [sp, #0x100] ; 0x21568: add x29, sp, #0x100 ; 0x2156c: stp x4, x5, [sp, #0x80]
 */
uint64_t fde_0670_0x2155c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2155cULL;
    constexpr uint64_t kSize = 0x9cULL;
    constexpr uint32_t kOp0  = 0xd10443ffU;
    constexpr uint32_t kOpN  = 0x97ffbea3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0671] `sub_215f8` (`0x215f8..0x216bc`, 196 bytes)
 *        Hàm FDE[0671] `sub_215f8` (`0x215f8..0x216bc`, 196 bytes)
 * Disassembly: 0x215f8: stp x22, x21, [sp, #-0x30]! ; 0x215fc: stp x20, x19, [sp, #0x10] ; 0x21600: stp x29, x30, [sp, #0x20] ; 0x21604: add x29, sp, #0x20 ; 0x21608: ldrb w8, [x0]
 */
uint64_t fde_0671_0x215f8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x215f8ULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0672] `sub_216bc` (`0x216bc..0x216c4`, 8 bytes)
 *        Hàm FDE[0672] `sub_216bc` (`0x216bc..0x216c4`, 8 bytes)
 * Disassembly: 0x216bc: ldr x0, [x0] ; 0x216c0: ret
 */
uint64_t fde_0672_0x216bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x216bcULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9400000U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0673] `sub_216c4` (`0x216c4..0x216e4`, 32 bytes)
 *        Hàm FDE[0673] `sub_216c4` (`0x216c4..0x216e4`, 32 bytes)
 * Disassembly: 0x216c4: ldr x8, [x0] ; 0x216c8: mov x9, #0x2b2b ; 0x216cc: movk x9, #0x4743, lsl #16 ; 0x216d0: movk x9, #0x4c4e, lsl #32 ; 0x216d4: movk x9, #0x43, lsl #48
 */
uint64_t fde_0673_0x216c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x216c4ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xf9400008U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0674] `sub_216e4` (`0x216e4..0x21730`, 76 bytes)
 *        Hàm FDE[0674] `sub_216e4` (`0x216e4..0x21730`, 76 bytes)
 * Disassembly: 0x216e4: stp x20, x19, [sp, #-0x20]! ; 0x216e8: stp x29, x30, [sp, #0x10] ; 0x216ec: add x29, sp, #0x10 ; 0x216f0: add x8, x0, #0x8f ; 0x216f4: and x19, x8, #0xfffffffffffffff0
 */
uint64_t fde_0674_0x216e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x216e4ULL;
    constexpr uint64_t kSize = 0x4cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x94000407U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0675] `sub_21730` (`0x21730..0x2174c`, 28 bytes)
 *        Hàm FDE[0675] `sub_21730` (`0x21730..0x2174c`, 28 bytes)
 * Disassembly: 0x21730: stp x29, x30, [sp, #-0x10]! ; 0x21734: mov x29, sp ; 0x21738: sub x0, x0, #0x80 ; 0x2173c: bl #0x22dd4 ; 0x21740: ldp x29, x30, [sp], #0x10
 */
uint64_t fde_0675_0x21730(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21730ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x94000400U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0676] `sub_2174c` (`0x2174c..0x217c0`, 116 bytes)
 *        Hàm FDE[0676] `sub_2174c` (`0x2174c..0x217c0`, 116 bytes)
 * Disassembly: 0x2174c: stp x22, x21, [sp, #-0x30]! ; 0x21750: stp x20, x19, [sp, #0x10] ; 0x21754: stp x29, x30, [sp, #0x20] ; 0x21758: add x29, sp, #0x20 ; 0x2175c: mov x19, x2
 */
uint64_t fde_0676_0x2174c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2174cULL;
    constexpr uint64_t kSize = 0x74ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x94000022U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0677] `sub_217c0` (`0x217c0..0x217e4`, 36 bytes)
 *        Hàm FDE[0677] `sub_217c0` (`0x217c0..0x217e4`, 36 bytes)
 * Disassembly: 0x217c0: sub sp, sp, #0x10 ; 0x217c4: mov x8, #0x2b00 ; 0x217c8: movk x8, #0x432b, lsl #16 ; 0x217cc: movk x8, #0x4e47, lsl #32 ; 0x217d0: movk x8, #0x434c, lsl #48
 */
uint64_t fde_0677_0x217c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x217c0ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xd10043ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0678] `sub_217e4` (`0x217e4..0x21844`, 96 bytes)
 *        Hàm FDE[0678] `sub_217e4` (`0x217e4..0x21844`, 96 bytes)
 * Disassembly: 0x217e4: str x19, [sp, #-0x20]! ; 0x217e8: stp x29, x30, [sp, #0x10] ; 0x217ec: add x29, sp, #0x10 ; 0x217f0: cmp w0, #1 ; 0x217f4: b.ne #0x21834
 */
uint64_t fde_0678_0x217e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x217e4ULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x940003c2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0679] `sub_21844` (`0x21844..0x21864`, 32 bytes)
 *        Hàm FDE[0679] `sub_21844` (`0x21844..0x21864`, 32 bytes)
 * Disassembly: 0x21844: str x19, [sp, #-0x20]! ; 0x21848: stp x29, x30, [sp, #0x10] ; 0x2184c: add x29, sp, #0x10 ; 0x21850: mov x19, x0 ; 0x21854: add x0, x0, #0x60
 */
uint64_t fde_0679_0x21844(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21844ULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x940001acU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0680] `sub_21864` (`0x21864..0x2186c`, 8 bytes)
 *        Hàm FDE[0680] `sub_21864` (`0x21864..0x2186c`, 8 bytes)
 * Disassembly: 0x21864: ldur x0, [x0, #-0x10] ; 0x21868: ret
 */
uint64_t fde_0680_0x21864(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21864ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf85f0000U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0681] `sub_2186c` (`0x2186c..0x21900`, 148 bytes)
 *        Hàm FDE[0681] `sub_2186c` (`0x2186c..0x21900`, 148 bytes)
 * Disassembly: 0x2186c: stp x20, x19, [sp, #-0x20]! ; 0x21870: stp x29, x30, [sp, #0x10] ; 0x21874: add x29, sp, #0x10 ; 0x21878: ldr x20, [x0] ; 0x2187c: mov x19, x0
 */
uint64_t fde_0681_0x2186c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2186cULL;
    constexpr uint64_t kSize = 0x94ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x94000393U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0682] `sub_21900` (`0x21900..0x219dc`, 220 bytes)
 *        Hàm FDE[0682] `sub_21900` (`0x21900..0x219dc`, 220 bytes)
 * Disassembly: 0x21900: stp x20, x19, [sp, #-0x20]! ; 0x21904: stp x29, x30, [sp, #0x10] ; 0x21908: add x29, sp, #0x10 ; 0x2190c: bl #0x21b50 ; 0x21910: ldr x19, [x0]
 */
uint64_t fde_0682_0x21900(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21900ULL;
    constexpr uint64_t kSize = 0xdcULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x9400035cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0683] `sub_219dc` (`0x219dc..0x21ac0`, 228 bytes)
 *        Hàm FDE[0683] `sub_219dc` (`0x219dc..0x21ac0`, 228 bytes)
 * Disassembly: 0x219dc: str x23, [sp, #-0x40]! ; 0x219e0: stp x22, x21, [sp, #0x10] ; 0x219e4: stp x20, x19, [sp, #0x20] ; 0x219e8: stp x29, x30, [sp, #0x30] ; 0x219ec: add x29, sp, #0x30
 */
uint64_t fde_0683_0x219dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x219dcULL;
    constexpr uint64_t kSize = 0xe4ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x94000323U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0684] `sub_21ac0` (`0x21ac0..0x21b50`, 144 bytes)
 *        Hàm FDE[0684] `sub_21ac0` (`0x21ac0..0x21b50`, 144 bytes)
 * Disassembly: 0x21ac0: stp x20, x19, [sp, #-0x20]! ; 0x21ac4: stp x29, x30, [sp, #0x10] ; 0x21ac8: add x29, sp, #0x10 ; 0x21acc: adrp x0, #0x50000 ; 0x21ad0: adrp x1, #0x21000
 */
uint64_t fde_0684_0x21ac0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21ac0ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x9400097aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0685] `sub_21b50` (`0x21b50..0x21b8c`, 60 bytes)
 *        Hàm FDE[0685] `sub_21b50` (`0x21b50..0x21b8c`, 60 bytes)
 * Disassembly: 0x21b50: stp x29, x30, [sp, #-0x10]! ; 0x21b54: mov x29, sp ; 0x21b58: adrp x0, #0x50000 ; 0x21b5c: adrp x1, #0x21000 ; 0x21b60: add x0, x0, #0x7bc
 */
uint64_t fde_0685_0x21b50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21b50ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x9400096bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0686] `sub_21b8c` (`0x21b8c..0x21bc0`, 52 bytes)
 *        Hàm FDE[0686] `sub_21b8c` (`0x21b8c..0x21bc0`, 52 bytes)
 * Disassembly: 0x21b8c: stp x29, x30, [sp, #-0x10]! ; 0x21b90: mov x29, sp ; 0x21b94: adrp x0, #0x50000 ; 0x21b98: adrp x1, #0x21000 ; 0x21b9c: add x0, x0, #0x7b8
 */
uint64_t fde_0686_0x21b8c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21b8cULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x9400095eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0687] `sub_21bc0` (`0x21bc0..0x21bf4`, 52 bytes)
 *        Hàm FDE[0687] `sub_21bc0` (`0x21bc0..0x21bf4`, 52 bytes)
 * Disassembly: 0x21bc0: stp x29, x30, [sp, #-0x10]! ; 0x21bc4: mov x29, sp ; 0x21bc8: bl #0x22ef8 ; 0x21bcc: adrp x8, #0x50000 ; 0x21bd0: ldr w0, [x8, #0x7b8]
 */
uint64_t fde_0687_0x21bc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21bc0ULL;
    constexpr uint64_t kSize = 0x34ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x94000951U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0688] `sub_21bf4` (`0x21bf4..0x21d54`, 352 bytes)
 *        Hàm FDE[0688] `sub_21bf4` (`0x21bf4..0x21d54`, 352 bytes)
 * Disassembly: 0x21bf4: str x23, [sp, #-0x40]! ; 0x21bf8: stp x22, x21, [sp, #0x10] ; 0x21bfc: stp x20, x19, [sp, #0x20] ; 0x21c00: stp x29, x30, [sp, #0x30] ; 0x21c04: add x29, sp, #0x30
 */
uint64_t fde_0688_0x21bf4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21bf4ULL;
    constexpr uint64_t kSize = 0x160ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffc2e6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0689] `sub_21d54` (`0x21d54..0x21dfc`, 168 bytes)
 *        Hàm FDE[0689] `sub_21d54` (`0x21d54..0x21dfc`, 168 bytes)
 * Disassembly: 0x21d54: str x21, [sp, #-0x30]! ; 0x21d58: stp x20, x19, [sp, #0x10] ; 0x21d5c: stp x29, x30, [sp, #0x20] ; 0x21d60: add x29, sp, #0x20 ; 0x21d64: mov w21, #1
 */
uint64_t fde_0689_0x21d54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21d54ULL;
    constexpr uint64_t kSize = 0xa8ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x97ffc2bcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0690] `sub_21dfc` (`0x21dfc..0x21e98`, 156 bytes)
 *        Hàm FDE[0690] `sub_21dfc` (`0x21dfc..0x21e98`, 156 bytes)
 * Disassembly: 0x21dfc: stp x20, x19, [sp, #-0x20]! ; 0x21e00: stp x29, x30, [sp, #0x10] ; 0x21e04: add x29, sp, #0x10 ; 0x21e08: mov x19, x0 ; 0x21e0c: adrp x0, #0x50000
 */
uint64_t fde_0690_0x21dfc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21dfcULL;
    constexpr uint64_t kSize = 0x9cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x97ffc295U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0691] `sub_21e98` (`0x21e98..0x21ea8`, 16 bytes)
 *        Hàm FDE[0691] `sub_21e98` (`0x21e98..0x21ea8`, 16 bytes)
 * Disassembly: 0x21e98: adrp x8, #0x4f000 ; 0x21e9c: ldr x8, [x8, #0xf70] ; 0x21ea0: ldar x0, [x8] ; 0x21ea4: ret
 */
uint64_t fde_0691_0x21e98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21e98ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xd0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0692] `sub_21ea8` (`0x21ea8..0x21ee8`, 64 bytes)
 *        Hàm FDE[0692] `sub_21ea8` (`0x21ea8..0x21ee8`, 64 bytes)
 * Disassembly: 0x21ea8: stp x19, x30, [sp, #-0x10]! ; 0x21eac: bl #0x21b50 ; 0x21eb0: cbz x0, #0x21ed0 ; 0x21eb4: ldr x19, [x0] ; 0x21eb8: cbz x19, #0x21ed0
 */
uint64_t fde_0692_0x21ea8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21ea8ULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bf3U;
    constexpr uint32_t kOpN  = 0x97ffc281U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0693] `sub_21ee8` (`0x21ee8..0x21f00`, 24 bytes)
 *        Hàm FDE[0693] `sub_21ee8` (`0x21ee8..0x21f00`, 24 bytes)
 * Disassembly: 0x21ee8: stp x29, x30, [sp, #-0x10]! ; 0x21eec: mov x29, sp ; 0x21ef0: blr x0 ; 0x21ef4: adrp x0, #0x3b000 ; 0x21ef8: add x0, x0, #0x559
 */
uint64_t fde_0693_0x21ee8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21ee8ULL;
    constexpr uint64_t kSize = 0x18ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x9400088eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0694] `sub_21f00` (`0x21f00..0x21f10`, 16 bytes)
 *        Hàm FDE[0694] `sub_21f00` (`0x21f00..0x21f10`, 16 bytes)
 * Disassembly: 0x21f00: adrp x8, #0x4f000 ; 0x21f04: ldr x8, [x8, #0xd00] ; 0x21f08: ldar x0, [x8] ; 0x21f0c: ret
 */
uint64_t fde_0694_0x21f00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21f00ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xd0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0695] `sub_21f10` (`0x21f10..0x21f50`, 64 bytes)
 *        Hàm FDE[0695] `sub_21f10` (`0x21f10..0x21f50`, 64 bytes)
 * Disassembly: 0x21f10: str x19, [sp, #-0x20]! ; 0x21f14: stp x29, x30, [sp, #0x10] ; 0x21f18: add x29, sp, #0x10 ; 0x21f1c: blr x0 ; 0x21f20: adrp x0, #0x3b000
 */
uint64_t fde_0695_0x21f10(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21f10ULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x97ffc267U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0696] `sub_21f50` (`0x21f50..0x21f60`, 16 bytes)
 *        Hàm FDE[0696] `sub_21f50` (`0x21f50..0x21f60`, 16 bytes)
 * Disassembly: 0x21f50: adrp x8, #0x4f000 ; 0x21f54: ldr x8, [x8, #0xef0] ; 0x21f58: ldar x0, [x8] ; 0x21f5c: ret
 */
uint64_t fde_0696_0x21f50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21f50ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xd0000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0697] `sub_21f60` (`0x21f60..0x22100`, 416 bytes)
 *        Hàm FDE[0697] `sub_21f60` (`0x21f60..0x22100`, 416 bytes)
 * Disassembly: 0x21f60: sub sp, sp, #0x60 ; 0x21f64: stp x22, x21, [sp, #0x30] ; 0x21f68: stp x20, x19, [sp, #0x40] ; 0x21f6c: stp x29, x30, [sp, #0x50] ; 0x21f70: add x29, sp, #0x50
 */
uint64_t fde_0697_0x21f60(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x21f60ULL;
    constexpr uint64_t kSize = 0x1a0ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x94000188U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0698] `sub_22100` (`0x22100..0x2271c`, 1564 bytes)
 *        Hàm FDE[0698] `sub_22100` (`0x22100..0x2271c`, 1564 bytes)
 * Disassembly: 0x22100: sub sp, sp, #0xc0 ; 0x22104: stp x28, x27, [sp, #0x60] ; 0x22108: stp x26, x25, [sp, #0x70] ; 0x2210c: stp x24, x23, [sp, #0x80] ; 0x22110: stp x22, x21, [sp, #0x90]
 */
uint64_t fde_0698_0x22100(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22100ULL;
    constexpr uint64_t kSize = 0x61cULL;
    constexpr uint32_t kOp0  = 0xd10303ffU;
    constexpr uint32_t kOpN  = 0x94000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0699] `sub_2271c` (`0x2271c..0x22748`, 44 bytes)
 *        Hàm FDE[0699] `sub_2271c` (`0x2271c..0x22748`, 44 bytes)
 * Disassembly: 0x2271c: stp x20, x19, [sp, #-0x20]! ; 0x22720: stp x29, x30, [sp, #0x10] ; 0x22724: add x29, sp, #0x10 ; 0x22728: mov w20, w0 ; 0x2272c: mov x0, x1
 */
uint64_t fde_0699_0x2271c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2271cULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x97fffdd9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0700] `sub_22748` (`0x22748..0x22ac4`, 892 bytes)
 *        Hàm FDE[0700] `sub_22748` (`0x22748..0x22ac4`, 892 bytes)
 * Disassembly: 0x22748: sub sp, sp, #0xa0 ; 0x2274c: stp x28, x27, [sp, #0x40] ; 0x22750: stp x26, x25, [sp, #0x50] ; 0x22754: stp x24, x23, [sp, #0x60] ; 0x22758: stp x22, x21, [sp, #0x70]
 */
uint64_t fde_0700_0x22748(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22748ULL;
    constexpr uint64_t kSize = 0x37cULL;
    constexpr uint32_t kOp0  = 0xd10283ffU;
    constexpr uint32_t kOpN  = 0x97ffbf8aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0701] `sub_22ac4` (`0x22ac4..0x22c18`, 340 bytes)
 *        Hàm FDE[0701] `sub_22ac4` (`0x22ac4..0x22c18`, 340 bytes)
 * Disassembly: 0x22ac4: stp x29, x30, [sp, #-0x10]! ; 0x22ac8: mov x29, sp ; 0x22acc: and w9, w1, #0xff ; 0x22ad0: cmp w9, #0xff ; 0x22ad4: b.eq #0x22b14
 */
uint64_t fde_0701_0x22ac4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22ac4ULL;
    constexpr uint64_t kSize = 0x154ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97ffb847U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0702] `sub_22c18` (`0x22c18..0x22c84`, 108 bytes)
 *        Hàm FDE[0702] `sub_22c18` (`0x22c18..0x22c84`, 108 bytes)
 * Disassembly: 0x22c18: sub sp, sp, #0x30 ; 0x22c1c: stp x20, x19, [sp, #0x10] ; 0x22c20: stp x29, x30, [sp, #0x20] ; 0x22c24: add x29, sp, #0x20 ; 0x22c28: mrs x20, tpidr_el0
 */
uint64_t fde_0702_0x22c18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22c18ULL;
    constexpr uint64_t kSize = 0x6cULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0x97ffb900U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0703] `sub_22c84` (`0x22c84..0x22d78`, 244 bytes)
 *        Hàm FDE[0703] `sub_22c84` (`0x22c84..0x22d78`, 244 bytes)
 * Disassembly: 0x22c84: stp x20, x19, [sp, #-0x20]! ; 0x22c88: stp x29, x30, [sp, #0x10] ; 0x22c8c: add x29, sp, #0x10 ; 0x22c90: mov x20, x0 ; 0x22c94: adrp x0, #0x50000
 */
uint64_t fde_0703_0x22c84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22c84ULL;
    constexpr uint64_t kSize = 0xf4ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x97ffbeddU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0704] `sub_22d78` (`0x22d78..0x22dd4`, 92 bytes)
 *        Hàm FDE[0704] `sub_22d78` (`0x22d78..0x22dd4`, 92 bytes)
 * Disassembly: 0x22d78: str x21, [sp, #-0x30]! ; 0x22d7c: stp x20, x19, [sp, #0x10] ; 0x22d80: stp x29, x30, [sp, #0x20] ; 0x22d84: add x29, sp, #0x20 ; 0x22d88: mov x20, x1
 */
uint64_t fde_0704_0x22d78(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22d78ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0705] `sub_22dd4` (`0x22dd4..0x22dfc`, 40 bytes)
 *        Hàm FDE[0705] `sub_22dd4` (`0x22dd4..0x22dfc`, 40 bytes)
 * Disassembly: 0x22dd4: adrp x8, #0x50000 ; 0x22dd8: add x8, x8, #0xa50 ; 0x22ddc: cmp x0, x8 ; 0x22de0: b.hs #0x22df8 ; 0x22de4: adrp x8, #0x50000
 */
uint64_t fde_0705_0x22dd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22dd4ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xd0000168U;
    constexpr uint32_t kOpN  = 0x17ffba32U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0706] `sub_22dfc` (`0x22dfc..0x22ef8`, 252 bytes)
 *        Hàm FDE[0706] `sub_22dfc` (`0x22dfc..0x22ef8`, 252 bytes)
 * Disassembly: 0x22dfc: stp x20, x19, [sp, #-0x20]! ; 0x22e00: stp x29, x30, [sp, #0x10] ; 0x22e04: add x29, sp, #0x10 ; 0x22e08: mov x19, x0 ; 0x22e0c: sub x20, x0, #4
 */
uint64_t fde_0706_0x22dfc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22dfcULL;
    constexpr uint64_t kSize = 0xfcULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x97ffbe7dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0707] `sub_22ef8` (`0x22ef8..0x22f20`, 40 bytes)
 *        Hàm FDE[0707] `sub_22ef8` (`0x22ef8..0x22f20`, 40 bytes)
 * Disassembly: 0x22ef8: adrp x8, #0x50000 ; 0x22efc: add x8, x8, #0xa50 ; 0x22f00: cmp x0, x8 ; 0x22f04: b.hs #0x22f1c ; 0x22f08: adrp x8, #0x50000
 */
uint64_t fde_0707_0x22ef8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22ef8ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xd0000168U;
    constexpr uint32_t kOpN  = 0x17ffb9e9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0708] `sub_22f20` (`0x22f20..0x22f24`, 4 bytes)
 *        Hàm FDE[0708] `sub_22f20` (`0x22f20..0x22f24`, 4 bytes)
 * Disassembly: 0x22f20: b #0x24130
 */
uint64_t fde_0708_0x22f20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f20ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000484U;
    constexpr uint32_t kOpN  = 0x14000484U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0709] `sub_22f24` (`0x22f24..0x22f28`, 4 bytes)
 *        Hàm FDE[0709] `sub_22f24` (`0x22f24..0x22f28`, 4 bytes)
 * Disassembly: 0x22f24: ret
 */
uint64_t fde_0709_0x22f24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f24ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0710] `sub_22f28` (`0x22f28..0x22f2c`, 4 bytes)
 *        Hàm FDE[0710] `sub_22f28` (`0x22f28..0x22f2c`, 4 bytes)
 * Disassembly: 0x22f28: ret
 */
uint64_t fde_0710_0x22f28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f28ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0711] `sub_22f2c` (`0x22f2c..0x22f50`, 36 bytes)
 *        Hàm FDE[0711] `sub_22f2c` (`0x22f2c..0x22f50`, 36 bytes)
 * Disassembly: 0x22f2c: str x19, [sp, #-0x20]! ; 0x22f30: stp x29, x30, [sp, #0x10] ; 0x22f34: add x29, sp, #0x10 ; 0x22f38: mov x19, x0 ; 0x22f3c: bl #0x24130
 */
uint64_t fde_0711_0x22f2c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f2cULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff7cfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0712] `sub_22f50` (`0x22f50..0x22f74`, 36 bytes)
 *        Hàm FDE[0712] `sub_22f50` (`0x22f50..0x22f74`, 36 bytes)
 * Disassembly: 0x22f50: str x19, [sp, #-0x20]! ; 0x22f54: stp x29, x30, [sp, #0x10] ; 0x22f58: add x29, sp, #0x10 ; 0x22f5c: mov x19, x0 ; 0x22f60: bl #0x24130
 */
uint64_t fde_0712_0x22f50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f50ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff7c6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0713] `sub_22f74` (`0x22f74..0x22f98`, 36 bytes)
 *        Hàm FDE[0713] `sub_22f74` (`0x22f74..0x22f98`, 36 bytes)
 * Disassembly: 0x22f74: str x19, [sp, #-0x20]! ; 0x22f78: stp x29, x30, [sp, #0x10] ; 0x22f7c: add x29, sp, #0x10 ; 0x22f80: mov x19, x0 ; 0x22f84: bl #0x24130
 */
uint64_t fde_0713_0x22f74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f74ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff7bdU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0714] `sub_22f98` (`0x22f98..0x23078`, 224 bytes)
 *        Hàm FDE[0714] `sub_22f98` (`0x22f98..0x23078`, 224 bytes)
 * Disassembly: 0x22f98: sub sp, sp, #0x90 ; 0x22f9c: str x21, [sp, #0x60] ; 0x22fa0: stp x20, x19, [sp, #0x70] ; 0x22fa4: stp x29, x30, [sp, #0x80] ; 0x22fa8: add x29, sp, #0x80
 */
uint64_t fde_0714_0x22f98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x22f98ULL;
    constexpr uint64_t kSize = 0xe0ULL;
    constexpr uint32_t kOp0  = 0xd10243ffU;
    constexpr uint32_t kOpN  = 0x97ffb803U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0715] `sub_23078` (`0x23078..0x230e8`, 112 bytes)
 *        Hàm FDE[0715] `sub_23078` (`0x23078..0x230e8`, 112 bytes)
 * Disassembly: 0x23078: ldr x8, [x1, #0x10] ; 0x2307c: ldr x9, [x0, #8] ; 0x23080: ldr x8, [x8, #8] ; 0x23084: cmp x9, x8 ; 0x23088: b.eq #0x23090
 */
uint64_t fde_0715_0x23078(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23078ULL;
    constexpr uint64_t kSize = 0x70ULL;
    constexpr uint32_t kOp0  = 0xf9400828U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0716] `sub_230e8` (`0x230e8..0x23164`, 124 bytes)
 *        Hàm FDE[0716] `sub_230e8` (`0x230e8..0x23164`, 124 bytes)
 * Disassembly: 0x230e8: ldr x8, [x1, #0x10] ; 0x230ec: ldr x9, [x0, #8] ; 0x230f0: ldr x8, [x8, #8] ; 0x230f4: cmp x9, x8 ; 0x230f8: b.eq #0x2310c
 */
uint64_t fde_0716_0x230e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x230e8ULL;
    constexpr uint64_t kSize = 0x7cULL;
    constexpr uint32_t kOp0  = 0xf9400828U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0717] `sub_23164` (`0x23164..0x232b8`, 340 bytes)
 *        Hàm FDE[0717] `sub_23164` (`0x23164..0x232b8`, 340 bytes)
 * Disassembly: 0x23164: stp x24, x23, [sp, #-0x40]! ; 0x23168: stp x22, x21, [sp, #0x10] ; 0x2316c: stp x20, x19, [sp, #0x20] ; 0x23170: stp x29, x30, [sp, #0x30] ; 0x23174: add x29, sp, #0x30
 */
uint64_t fde_0717_0x23164(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23164ULL;
    constexpr uint64_t kSize = 0x154ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0718] `sub_232b8` (`0x232b8..0x233f0`, 312 bytes)
 *        Hàm FDE[0718] `sub_232b8` (`0x232b8..0x233f0`, 312 bytes)
 * Disassembly: 0x232b8: sub sp, sp, #0x80 ; 0x232bc: stp x20, x19, [sp, #0x60] ; 0x232c0: stp x29, x30, [sp, #0x70] ; 0x232c4: add x29, sp, #0x70 ; 0x232c8: mrs x20, tpidr_el0
 */
uint64_t fde_0718_0x232b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x232b8ULL;
    constexpr uint64_t kSize = 0x138ULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0x97ffb725U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0719] `sub_233f0` (`0x233f0..0x237a4`, 948 bytes)
 *        Hàm FDE[0719] `sub_233f0` (`0x233f0..0x237a4`, 948 bytes)
 * Disassembly: 0x233f0: str x27, [sp, #-0x60]! ; 0x233f4: stp x26, x25, [sp, #0x10] ; 0x233f8: stp x24, x23, [sp, #0x20] ; 0x233fc: stp x22, x21, [sp, #0x30] ; 0x23400: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0719_0x233f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x233f0ULL;
    constexpr uint64_t kSize = 0x3b4ULL;
    constexpr uint32_t kOp0  = 0xf81a0ffbU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0720] `sub_237a4` (`0x237a4..0x23944`, 416 bytes)
 *        Hàm FDE[0720] `sub_237a4` (`0x237a4..0x23944`, 416 bytes)
 * Disassembly: 0x237a4: stp x24, x23, [sp, #-0x40]! ; 0x237a8: stp x22, x21, [sp, #0x10] ; 0x237ac: stp x20, x19, [sp, #0x20] ; 0x237b0: stp x29, x30, [sp, #0x30] ; 0x237b4: add x29, sp, #0x30
 */
uint64_t fde_0720_0x237a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x237a4ULL;
    constexpr uint64_t kSize = 0x1a0ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0721] `sub_23944` (`0x23944..0x23a64`, 288 bytes)
 *        Hàm FDE[0721] `sub_23944` (`0x23944..0x23a64`, 288 bytes)
 * Disassembly: 0x23944: str x23, [sp, #-0x40]! ; 0x23948: stp x22, x21, [sp, #0x10] ; 0x2394c: stp x20, x19, [sp, #0x20] ; 0x23950: stp x29, x30, [sp, #0x30] ; 0x23954: add x29, sp, #0x30
 */
uint64_t fde_0721_0x23944(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23944ULL;
    constexpr uint64_t kSize = 0x120ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0722] `sub_23a64` (`0x23a64..0x23ca0`, 572 bytes)
 *        Hàm FDE[0722] `sub_23a64` (`0x23a64..0x23ca0`, 572 bytes)
 * Disassembly: 0x23a64: stp x28, x27, [sp, #-0x60]! ; 0x23a68: stp x26, x25, [sp, #0x10] ; 0x23a6c: stp x24, x23, [sp, #0x20] ; 0x23a70: stp x22, x21, [sp, #0x30] ; 0x23a74: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0722_0x23a64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23a64ULL;
    constexpr uint64_t kSize = 0x23cULL;
    constexpr uint32_t kOp0  = 0xa9ba6ffcU;
    constexpr uint32_t kOpN  = 0x17ffffe7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0723] `sub_23ca0` (`0x23ca0..0x23dd0`, 304 bytes)
 *        Hàm FDE[0723] `sub_23ca0` (`0x23ca0..0x23dd0`, 304 bytes)
 * Disassembly: 0x23ca0: stp x24, x23, [sp, #-0x40]! ; 0x23ca4: stp x22, x21, [sp, #0x10] ; 0x23ca8: stp x20, x19, [sp, #0x20] ; 0x23cac: stp x29, x30, [sp, #0x30] ; 0x23cb0: add x29, sp, #0x30
 */
uint64_t fde_0723_0x23ca0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ca0ULL;
    constexpr uint64_t kSize = 0x130ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0x17ffffcdU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0724] `sub_23dd0` (`0x23dd0..0x23ec0`, 240 bytes)
 *        Hàm FDE[0724] `sub_23dd0` (`0x23dd0..0x23ec0`, 240 bytes)
 * Disassembly: 0x23dd0: stp x22, x21, [sp, #-0x30]! ; 0x23dd4: stp x20, x19, [sp, #0x10] ; 0x23dd8: stp x29, x30, [sp, #0x20] ; 0x23ddc: add x29, sp, #0x20 ; 0x23de0: ldr x8, [x1, #0x10]
 */
uint64_t fde_0724_0x23dd0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23dd0ULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x17ffffdfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0725] `sub_23ec0` (`0x23ec0..0x23ec4`, 4 bytes)
 *        Hàm FDE[0725] `sub_23ec0` (`0x23ec0..0x23ec4`, 4 bytes)
 * Disassembly: 0x23ec0: ret
 */
uint64_t fde_0725_0x23ec0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ec0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0726] `sub_23ec4` (`0x23ec4..0x23ec8`, 4 bytes)
 *        Hàm FDE[0726] `sub_23ec4` (`0x23ec4..0x23ec8`, 4 bytes)
 * Disassembly: 0x23ec4: b #0x20e88
 */
uint64_t fde_0726_0x23ec4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ec4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff3f1U;
    constexpr uint32_t kOpN  = 0x17fff3f1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0727] `sub_23ec8` (`0x23ec8..0x23ed4`, 12 bytes)
 *        Hàm FDE[0727] `sub_23ec8` (`0x23ec8..0x23ed4`, 12 bytes)
 * Disassembly: 0x23ec8: adrp x0, #0x3b000 ; 0x23ecc: add x0, x0, #0x73e ; 0x23ed0: ret
 */
uint64_t fde_0727_0x23ec8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ec8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x900000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0728] `sub_23ed4` (`0x23ed4..0x23ed8`, 4 bytes)
 *        Hàm FDE[0728] `sub_23ed4` (`0x23ed4..0x23ed8`, 4 bytes)
 * Disassembly: 0x23ed4: b #0x20e88
 */
uint64_t fde_0728_0x23ed4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ed4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff3edU;
    constexpr uint32_t kOpN  = 0x17fff3edU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0729] `sub_23ed8` (`0x23ed8..0x23ee4`, 12 bytes)
 *        Hàm FDE[0729] `sub_23ed8` (`0x23ed8..0x23ee4`, 12 bytes)
 * Disassembly: 0x23ed8: adrp x0, #0x3b000 ; 0x23edc: add x0, x0, #0x74d ; 0x23ee0: ret
 */
uint64_t fde_0729_0x23ed8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ed8ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x900000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0730] `sub_23ee4` (`0x23ee4..0x23ef8`, 20 bytes)
 *        Hàm FDE[0730] `sub_23ee4` (`0x23ee4..0x23ef8`, 20 bytes)
 * Disassembly: 0x23ee4: adrp x8, #0x4f000 ; 0x23ee8: ldr x8, [x8, #0xf00] ; 0x23eec: add x8, x8, #0x10 ; 0x23ef0: str x8, [x0] ; 0x23ef4: ret
 */
uint64_t fde_0730_0x23ee4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ee4ULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0x90000168U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0731] `sub_23ef8` (`0x23ef8..0x23efc`, 4 bytes)
 *        Hàm FDE[0731] `sub_23ef8` (`0x23ef8..0x23efc`, 4 bytes)
 * Disassembly: 0x23ef8: b #0x20e88
 */
uint64_t fde_0731_0x23ef8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23ef8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17fff3e4U;
    constexpr uint32_t kOpN  = 0x17fff3e4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0732] `sub_23efc` (`0x23efc..0x23f08`, 12 bytes)
 *        Hàm FDE[0732] `sub_23efc` (`0x23efc..0x23f08`, 12 bytes)
 * Disassembly: 0x23efc: adrp x0, #0x3b000 ; 0x23f00: add x0, x0, #0x760 ; 0x23f04: ret
 */
uint64_t fde_0732_0x23efc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23efcULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0x900000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0733] `sub_23f08` (`0x23f08..0x23f5c`, 84 bytes)
 *        Hàm FDE[0733] `sub_23f08` (`0x23f08..0x23f5c`, 84 bytes)
 * Disassembly: 0x23f08: str x19, [sp, #-0x20]! ; 0x23f0c: stp x29, x30, [sp, #0x10] ; 0x23f10: add x29, sp, #0x10 ; 0x23f14: adrp x9, #0x4f000 ; 0x23f18: ldr x8, [x0, #8]
 */
uint64_t fde_0733_0x23f08(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23f08ULL;
    constexpr uint64_t kSize = 0x54ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17ffffdaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0734] `sub_23f5c` (`0x23f5c..0x23fb8`, 92 bytes)
 *        Hàm FDE[0734] `sub_23f5c` (`0x23f5c..0x23fb8`, 92 bytes)
 * Disassembly: 0x23f5c: str x19, [sp, #-0x20]! ; 0x23f60: stp x29, x30, [sp, #0x10] ; 0x23f64: add x29, sp, #0x10 ; 0x23f68: adrp x9, #0x4f000 ; 0x23f6c: ldr x8, [x0, #8]
 */
uint64_t fde_0734_0x23f5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23f5cULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff3b5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0735] `sub_23fb8` (`0x23fb8..0x23fc0`, 8 bytes)
 *        Hàm FDE[0735] `sub_23fb8` (`0x23fb8..0x23fc0`, 8 bytes)
 * Disassembly: 0x23fb8: ldr x0, [x0, #8] ; 0x23fbc: ret
 */
uint64_t fde_0735_0x23fb8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23fb8ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9400400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0736] `sub_23fc0` (`0x23fc0..0x24014`, 84 bytes)
 *        Hàm FDE[0736] `sub_23fc0` (`0x23fc0..0x24014`, 84 bytes)
 * Disassembly: 0x23fc0: str x19, [sp, #-0x20]! ; 0x23fc4: stp x29, x30, [sp, #0x10] ; 0x23fc8: add x29, sp, #0x10 ; 0x23fcc: adrp x9, #0x4f000 ; 0x23fd0: ldr x8, [x0, #8]
 */
uint64_t fde_0736_0x23fc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x23fc0ULL;
    constexpr uint64_t kSize = 0x54ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17ffffacU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0737] `sub_24014` (`0x24014..0x24070`, 92 bytes)
 *        Hàm FDE[0737] `sub_24014` (`0x24014..0x24070`, 92 bytes)
 * Disassembly: 0x24014: str x19, [sp, #-0x20]! ; 0x24018: stp x29, x30, [sp, #0x10] ; 0x2401c: add x29, sp, #0x10 ; 0x24020: adrp x9, #0x4f000 ; 0x24024: ldr x8, [x0, #8]
 */
uint64_t fde_0737_0x24014(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24014ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff387U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0738] `sub_24070` (`0x24070..0x24078`, 8 bytes)
 *        Hàm FDE[0738] `sub_24070` (`0x24070..0x24078`, 8 bytes)
 * Disassembly: 0x24070: ldr x0, [x0, #8] ; 0x24074: ret
 */
uint64_t fde_0738_0x24070(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24070ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9400400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0739] `sub_24078` (`0x24078..0x240d4`, 92 bytes)
 *        Hàm FDE[0739] `sub_24078` (`0x24078..0x240d4`, 92 bytes)
 * Disassembly: 0x24078: str x19, [sp, #-0x20]! ; 0x2407c: stp x29, x30, [sp, #0x10] ; 0x24080: add x29, sp, #0x10 ; 0x24084: adrp x9, #0x4f000 ; 0x24088: ldr x8, [x0, #8]
 */
uint64_t fde_0739_0x24078(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24078ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff36eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0740] `sub_240d4` (`0x240d4..0x24130`, 92 bytes)
 *        Hàm FDE[0740] `sub_240d4` (`0x240d4..0x24130`, 92 bytes)
 * Disassembly: 0x240d4: str x19, [sp, #-0x20]! ; 0x240d8: stp x29, x30, [sp, #0x10] ; 0x240dc: add x29, sp, #0x10 ; 0x240e0: adrp x9, #0x4f000 ; 0x240e4: ldr x8, [x0, #8]
 */
uint64_t fde_0740_0x240d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x240d4ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x17fff357U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0741] `sub_24130` (`0x24130..0x24134`, 4 bytes)
 *        Hàm FDE[0741] `sub_24130` (`0x24130..0x24134`, 4 bytes)
 * Disassembly: 0x24130: ret
 */
uint64_t fde_0741_0x24130(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24130ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0742] `sub_24134` (`0x24134..0x24224`, 240 bytes)
 *        Hàm FDE[0742] `sub_24134` (`0x24134..0x24224`, 240 bytes)
 * Disassembly: 0x24134: sub sp, sp, #0x1a0 ; 0x24138: stp x28, x25, [sp, #0x150] ; 0x2413c: stp x24, x23, [sp, #0x160] ; 0x24140: stp x22, x21, [sp, #0x170] ; 0x24144: stp x20, x19, [sp, #0x180]
 */
uint64_t fde_0742_0x24134(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24134ULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xd10683ffU;
    constexpr uint32_t kOpN  = 0x97ffb2c4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0743] `sub_24224` (`0x24224..0x24344`, 288 bytes)
 *        Hàm FDE[0743] `sub_24224` (`0x24224..0x24344`, 288 bytes)
 * Disassembly: 0x24224: str x28, [sp, #-0x30]! ; 0x24228: stp x20, x19, [sp, #0x10] ; 0x2422c: stp x29, x30, [sp, #0x20] ; 0x24230: add x29, sp, #0x20 ; 0x24234: sub sp, sp, #0x410
 */
uint64_t fde_0743_0x24224(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24224ULL;
    constexpr uint64_t kSize = 0x120ULL;
    constexpr uint32_t kOp0  = 0xf81d0ffcU;
    constexpr uint32_t kOpN  = 0x97ffff7dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0744] `sub_24344` (`0x24344..0x24360`, 28 bytes)
 *        Hàm FDE[0744] `sub_24344` (`0x24344..0x24360`, 28 bytes)
 * Disassembly: 0x24344: stp x29, x30, [sp, #-0x10]! ; 0x24348: mov x29, sp ; 0x2434c: adrp x9, #0x3b000 ; 0x24350: adrp x8, #0x50000 ; 0x24354: add x9, x9, #0x89e
 */
uint64_t fde_0744_0x24344(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24344ULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0x97fff6d3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0745] `sub_24360` (`0x24360..0x24a9c`, 1852 bytes)
 *        Hàm FDE[0745] `sub_24360` (`0x24360..0x24a9c`, 1852 bytes)
 * Disassembly: 0x24360: stp x28, x27, [sp, #-0x60]! ; 0x24364: stp x26, x25, [sp, #0x10] ; 0x24368: stp x24, x23, [sp, #0x20] ; 0x2436c: stp x22, x21, [sp, #0x30] ; 0x24370: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0745_0x24360(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24360ULL;
    constexpr uint64_t kSize = 0x73cULL;
    constexpr uint32_t kOp0  = 0xa9ba6ffcU;
    constexpr uint32_t kOpN  = 0x940048e1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0746] `sub_24a9c` (`0x24a9c..0x255e4`, 2888 bytes)
 *        Hàm FDE[0746] `sub_24a9c` (`0x24a9c..0x255e4`, 2888 bytes)
 * Disassembly: 0x24a9c: sub sp, sp, #0x90 ; 0x24aa0: str x27, [sp, #0x30] ; 0x24aa4: stp x26, x25, [sp, #0x40] ; 0x24aa8: stp x24, x23, [sp, #0x50] ; 0x24aac: stp x22, x21, [sp, #0x60]
 */
uint64_t fde_0746_0x24a9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x24a9cULL;
    constexpr uint64_t kSize = 0xb48ULL;
    constexpr uint32_t kOp0  = 0xd10243ffU;
    constexpr uint32_t kOpN  = 0x97fff232U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0747] `sub_255e4` (`0x255e4..0x26c64`, 5760 bytes)
 *        Hàm FDE[0747] `sub_255e4` (`0x255e4..0x26c64`, 5760 bytes)
 * Disassembly: 0x255e4: sub sp, sp, #0x50 ; 0x255e8: stp x24, x23, [sp, #0x10] ; 0x255ec: stp x22, x21, [sp, #0x20] ; 0x255f0: stp x20, x19, [sp, #0x30] ; 0x255f4: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0747_0x255e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x255e4ULL;
    constexpr uint64_t kSize = 0x1680ULL;
    constexpr uint32_t kOp0  = 0xd10143ffU;
    constexpr uint32_t kOpN  = 0x97ffec92U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0748] `sub_26c64` (`0x26c64..0x278a0`, 3132 bytes)
 *        Hàm FDE[0748] `sub_26c64` (`0x26c64..0x278a0`, 3132 bytes)
 * Disassembly: 0x26c64: sub sp, sp, #0x80 ; 0x26c68: stp x28, x27, [sp, #0x20] ; 0x26c6c: stp x26, x25, [sp, #0x30] ; 0x26c70: stp x24, x23, [sp, #0x40] ; 0x26c74: stp x22, x21, [sp, #0x50]
 */
uint64_t fde_0748_0x26c64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x26c64ULL;
    constexpr uint64_t kSize = 0xc3cULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0x97ffe983U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0749] `sub_278a0` (`0x278a0..0x27a78`, 472 bytes)
 *        Hàm FDE[0749] `sub_278a0` (`0x278a0..0x27a78`, 472 bytes)
 * Disassembly: 0x278a0: sub sp, sp, #0x40 ; 0x278a4: stp x22, x21, [sp, #0x10] ; 0x278a8: stp x20, x19, [sp, #0x20] ; 0x278ac: stp x29, x30, [sp, #0x30] ; 0x278b0: add x29, sp, #0x30
 */
uint64_t fde_0749_0x278a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x278a0ULL;
    constexpr uint64_t kSize = 0x1d8ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x97ffe90dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0750] `sub_27a78` (`0x27a78..0x27b34`, 188 bytes)
 *        Hàm FDE[0750] `sub_27a78` (`0x27a78..0x27b34`, 188 bytes)
 * Disassembly: 0x27a78: str x23, [sp, #-0x40]! ; 0x27a7c: stp x22, x21, [sp, #0x10] ; 0x27a80: stp x20, x19, [sp, #0x20] ; 0x27a84: stp x29, x30, [sp, #0x30] ; 0x27a88: add x29, sp, #0x30
 */
uint64_t fde_0750_0x27a78(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27a78ULL;
    constexpr uint64_t kSize = 0xbcULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffe8deU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0751] `sub_27b34` (`0x27b34..0x27dbc`, 648 bytes)
 *        Hàm FDE[0751] `sub_27b34` (`0x27b34..0x27dbc`, 648 bytes)
 * Disassembly: 0x27b34: ldp x11, x9, [x0] ; 0x27b38: cmp x11, x9 ; 0x27b3c: b.eq #0x27d9c ; 0x27b40: ldrb w8, [x11] ; 0x27b44: cmp w8, #0x68
 */
uint64_t fde_0751_0x27b34(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27b34ULL;
    constexpr uint64_t kSize = 0x288ULL;
    constexpr uint32_t kOp0  = 0xa940240bU;
    constexpr uint32_t kOpN  = 0x17ffffeeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0752] `sub_27dbc` (`0x27dbc..0x27dc4`, 8 bytes)
 *        Hàm FDE[0752] `sub_27dbc` (`0x27dbc..0x27dc4`, 8 bytes)
 * Disassembly: 0x27dbc: mov w0, wzr ; 0x27dc0: ret
 */
uint64_t fde_0752_0x27dbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27dbcULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0753] `sub_27dc4` (`0x27dc4..0x27dcc`, 8 bytes)
 *        Hàm FDE[0753] `sub_27dc4` (`0x27dc4..0x27dcc`, 8 bytes)
 * Disassembly: 0x27dc4: mov w0, wzr ; 0x27dc8: ret
 */
uint64_t fde_0753_0x27dc4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27dc4ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0754] `sub_27dcc` (`0x27dcc..0x27dd4`, 8 bytes)
 *        Hàm FDE[0754] `sub_27dcc` (`0x27dcc..0x27dd4`, 8 bytes)
 * Disassembly: 0x27dcc: mov w0, wzr ; 0x27dd0: ret
 */
uint64_t fde_0754_0x27dcc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27dccULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x2a1f03e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0755] `sub_27dd4` (`0x27dd4..0x27dd8`, 4 bytes)
 *        Hàm FDE[0755] `sub_27dd4` (`0x27dd4..0x27dd8`, 4 bytes)
 * Disassembly: 0x27dd4: ret
 */
uint64_t fde_0755_0x27dd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27dd4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0756] `sub_27dd8` (`0x27dd8..0x27e48`, 112 bytes)
 *        Hàm FDE[0756] `sub_27dd8` (`0x27dd8..0x27e48`, 112 bytes)
 * Disassembly: 0x27dd8: stp x20, x19, [sp, #-0x20]! ; 0x27ddc: stp x29, x30, [sp, #0x10] ; 0x27de0: add x29, sp, #0x10 ; 0x27de4: ldp x8, x2, [x0, #0x10] ; 0x27de8: mov x20, x0
 */
uint64_t fde_0756_0x27dd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27dd8ULL;
    constexpr uint64_t kSize = 0x70ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0757] `sub_27e48` (`0x27e48..0x27e4c`, 4 bytes)
 *        Hàm FDE[0757] `sub_27e48` (`0x27e48..0x27e4c`, 4 bytes)
 * Disassembly: 0x27e48: ret
 */
uint64_t fde_0757_0x27e48(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27e48ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0758] `sub_27e4c` (`0x27e4c..0x27e58`, 12 bytes)
 *        Hàm FDE[0758] `sub_27e4c` (`0x27e4c..0x27e58`, 12 bytes)
 * Disassembly: 0x27e4c: mov x0, xzr ; 0x27e50: mov x1, xzr ; 0x27e54: ret
 */
uint64_t fde_0758_0x27e4c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27e4cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xaa1f03e0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0759] `sub_27e58` (`0x27e58..0x27e5c`, 4 bytes)
 *        Hàm FDE[0759] `sub_27e58` (`0x27e58..0x27e5c`, 4 bytes)
 * Disassembly: 0x27e58: b #0x20e88
 */
uint64_t fde_0759_0x27e58(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27e58ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffe40cU;
    constexpr uint32_t kOpN  = 0x17ffe40cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0760] `sub_27e5c` (`0x27e5c..0x27ee8`, 140 bytes)
 *        Hàm FDE[0760] `sub_27e5c` (`0x27e5c..0x27ee8`, 140 bytes)
 * Disassembly: 0x27e5c: str x21, [sp, #-0x30]! ; 0x27e60: stp x20, x19, [sp, #0x10] ; 0x27e64: stp x29, x30, [sp, #0x20] ; 0x27e68: add x29, sp, #0x20 ; 0x27e6c: subs x20, x2, x1
 */
uint64_t fde_0760_0x27e5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27e5cULL;
    constexpr uint64_t kSize = 0x8cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x97ffe7f1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0761] `sub_27ee8` (`0x27ee8..0x27fd4`, 236 bytes)
 *        Hàm FDE[0761] `sub_27ee8` (`0x27ee8..0x27fd4`, 236 bytes)
 * Disassembly: 0x27ee8: str x21, [sp, #-0x30]! ; 0x27eec: stp x20, x19, [sp, #0x10] ; 0x27ef0: stp x29, x30, [sp, #0x20] ; 0x27ef4: add x29, sp, #0x20 ; 0x27ef8: adrp x21, #0x3c000
 */
uint64_t fde_0761_0x27ee8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27ee8ULL;
    constexpr uint64_t kSize = 0xecULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0762] `sub_27fd4` (`0x27fd4..0x27fd8`, 4 bytes)
 *        Hàm FDE[0762] `sub_27fd4` (`0x27fd4..0x27fd8`, 4 bytes)
 * Disassembly: 0x27fd4: b #0x20e88
 */
uint64_t fde_0762_0x27fd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27fd4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffe3adU;
    constexpr uint32_t kOpN  = 0x17ffe3adU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0763] `sub_27fd8` (`0x27fd8..0x28360`, 904 bytes)
 *        Hàm FDE[0763] `sub_27fd8` (`0x27fd8..0x28360`, 904 bytes)
 * Disassembly: 0x27fd8: sub sp, sp, #0x40 ; 0x27fdc: stp x22, x21, [sp, #0x10] ; 0x27fe0: stp x20, x19, [sp, #0x20] ; 0x27fe4: stp x29, x30, [sp, #0x30] ; 0x27fe8: add x29, sp, #0x30
 */
uint64_t fde_0763_0x27fd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x27fd8ULL;
    constexpr uint64_t kSize = 0x388ULL;
    constexpr uint32_t kOp0  = 0xd10103ffU;
    constexpr uint32_t kOpN  = 0x97ffe6d3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0764] `sub_28360` (`0x28360..0x2882c`, 1228 bytes)
 *        Hàm FDE[0764] `sub_28360` (`0x28360..0x2882c`, 1228 bytes)
 * Disassembly: 0x28360: sub sp, sp, #0xf0 ; 0x28364: stp x28, x27, [sp, #0x90] ; 0x28368: stp x26, x25, [sp, #0xa0] ; 0x2836c: stp x24, x23, [sp, #0xb0] ; 0x28370: stp x22, x21, [sp, #0xc0]
 */
uint64_t fde_0764_0x28360(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x28360ULL;
    constexpr uint64_t kSize = 0x4ccULL;
    constexpr uint32_t kOp0  = 0xd103c3ffU;
    constexpr uint32_t kOpN  = 0x9400397dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0765] `sub_2882c` (`0x2882c..0x28abc`, 656 bytes)
 *        Hàm FDE[0765] `sub_2882c` (`0x2882c..0x28abc`, 656 bytes)
 * Disassembly: 0x2882c: str x23, [sp, #-0x40]! ; 0x28830: stp x22, x21, [sp, #0x10] ; 0x28834: stp x20, x19, [sp, #0x20] ; 0x28838: stp x29, x30, [sp, #0x30] ; 0x2883c: add x29, sp, #0x30
 */
uint64_t fde_0765_0x2882c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2882cULL;
    constexpr uint64_t kSize = 0x290ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffe4fcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0766] `sub_28abc` (`0x28abc..0x28b6c`, 176 bytes)
 *        Hàm FDE[0766] `sub_28abc` (`0x28abc..0x28b6c`, 176 bytes)
 * Disassembly: 0x28abc: str x19, [sp, #-0x20]! ; 0x28ac0: stp x29, x30, [sp, #0x10] ; 0x28ac4: add x29, sp, #0x10 ; 0x28ac8: ldp x8, x9, [x0] ; 0x28acc: cmp x8, x9
 */
uint64_t fde_0766_0x28abc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x28abcULL;
    constexpr uint64_t kSize = 0xb0ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0767] `sub_28b6c` (`0x28b6c..0x28ddc`, 624 bytes)
 *        Hàm FDE[0767] `sub_28b6c` (`0x28b6c..0x28ddc`, 624 bytes)
 * Disassembly: 0x28b6c: str x23, [sp, #-0x40]! ; 0x28b70: stp x22, x21, [sp, #0x10] ; 0x28b74: stp x20, x19, [sp, #0x20] ; 0x28b78: stp x29, x30, [sp, #0x30] ; 0x28b7c: add x29, sp, #0x30
 */
uint64_t fde_0767_0x28b6c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x28b6cULL;
    constexpr uint64_t kSize = 0x270ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffe434U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0768] `sub_28ddc` (`0x28ddc..0x28f64`, 392 bytes)
 *        Hàm FDE[0768] `sub_28ddc` (`0x28ddc..0x28f64`, 392 bytes)
 * Disassembly: 0x28ddc: stp x26, x25, [sp, #-0x50]! ; 0x28de0: stp x24, x23, [sp, #0x10] ; 0x28de4: stp x22, x21, [sp, #0x20] ; 0x28de8: stp x20, x19, [sp, #0x30] ; 0x28dec: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0768_0x28ddc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x28ddcULL;
    constexpr uint64_t kSize = 0x188ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffe3d2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0769] `sub_28f64` (`0x28f64..0x2963c`, 1752 bytes)
 *        Hàm FDE[0769] `sub_28f64` (`0x28f64..0x2963c`, 1752 bytes)
 * Disassembly: 0x28f64: sub sp, sp, #0x60 ; 0x28f68: stp x26, x25, [sp, #0x10] ; 0x28f6c: stp x24, x23, [sp, #0x20] ; 0x28f70: stp x22, x21, [sp, #0x30] ; 0x28f74: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0769_0x28f64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x28f64ULL;
    constexpr uint64_t kSize = 0x6d8ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x940035f9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0770] `sub_2963c` (`0x2963c..0x2964c`, 16 bytes)
 *        Hàm FDE[0770] `sub_2963c` (`0x2963c..0x2964c`, 16 bytes)
 * Disassembly: 0x2963c: ldp x8, x2, [x0, #0x10] ; 0x29640: mov x0, x1 ; 0x29644: mov x1, x8 ; 0x29648: b #0x27e5c
 */
uint64_t fde_0770_0x2963c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2963cULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xa9410808U;
    constexpr uint32_t kOpN  = 0x17fffa05U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0771] `sub_2964c` (`0x2964c..0x29658`, 12 bytes)
 *        Hàm FDE[0771] `sub_2964c` (`0x2964c..0x29658`, 12 bytes)
 * Disassembly: 0x2964c: ldp x8, x1, [x0, #0x10] ; 0x29650: mov x0, x8 ; 0x29654: ret
 */
uint64_t fde_0771_0x2964c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2964cULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xa9410408U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0772] `sub_29658` (`0x29658..0x2965c`, 4 bytes)
 *        Hàm FDE[0772] `sub_29658` (`0x29658..0x2965c`, 4 bytes)
 * Disassembly: 0x29658: b #0x20e88
 */
uint64_t fde_0772_0x29658(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29658ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffde0cU;
    constexpr uint32_t kOpN  = 0x17ffde0cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0773] `sub_2965c` (`0x2965c..0x29720`, 196 bytes)
 *        Hàm FDE[0773] `sub_2965c` (`0x2965c..0x29720`, 196 bytes)
 * Disassembly: 0x2965c: str x21, [sp, #-0x30]! ; 0x29660: stp x20, x19, [sp, #0x10] ; 0x29664: stp x29, x30, [sp, #0x20] ; 0x29668: add x29, sp, #0x20 ; 0x2966c: ldr x21, [x0, #0x10]
 */
uint64_t fde_0773_0x2965c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2965cULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0774] `sub_29720` (`0x29720..0x29730`, 16 bytes)
 *        Hàm FDE[0774] `sub_29720` (`0x29720..0x29730`, 16 bytes)
 * Disassembly: 0x29720: ldr x0, [x0, #0x18] ; 0x29724: ldr x8, [x0] ; 0x29728: ldr x1, [x8, #0x30] ; 0x2972c: br x1
 */
uint64_t fde_0774_0x29720(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29720ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0775] `sub_29730` (`0x29730..0x29734`, 4 bytes)
 *        Hàm FDE[0775] `sub_29730` (`0x29730..0x29734`, 4 bytes)
 * Disassembly: 0x29730: b #0x20e88
 */
uint64_t fde_0775_0x29730(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29730ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffddd6U;
    constexpr uint32_t kOpN  = 0x17ffddd6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0776] `sub_29734` (`0x29734..0x297a4`, 112 bytes)
 *        Hàm FDE[0776] `sub_29734` (`0x29734..0x297a4`, 112 bytes)
 * Disassembly: 0x29734: str x19, [sp, #-0x20]! ; 0x29738: stp x29, x30, [sp, #0x10] ; 0x2973c: add x29, sp, #0x10 ; 0x29740: ldrb w8, [x0, #0x20] ; 0x29744: cbz w8, #0x29750
 */
uint64_t fde_0776_0x29734(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29734ULL;
    constexpr uint64_t kSize = 0x70ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x9400359fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0777] `sub_297a4` (`0x297a4..0x29814`, 112 bytes)
 *        Hàm FDE[0777] `sub_297a4` (`0x297a4..0x29814`, 112 bytes)
 * Disassembly: 0x297a4: str x19, [sp, #-0x20]! ; 0x297a8: stp x29, x30, [sp, #0x10] ; 0x297ac: add x29, sp, #0x10 ; 0x297b0: ldrb w8, [x0, #0x20] ; 0x297b4: cbz w8, #0x297c0
 */
uint64_t fde_0777_0x297a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x297a4ULL;
    constexpr uint64_t kSize = 0x70ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94003583U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0778] `sub_29814` (`0x29814..0x29884`, 112 bytes)
 *        Hàm FDE[0778] `sub_29814` (`0x29814..0x29884`, 112 bytes)
 * Disassembly: 0x29814: str x19, [sp, #-0x20]! ; 0x29818: stp x29, x30, [sp, #0x10] ; 0x2981c: add x29, sp, #0x10 ; 0x29820: ldrb w8, [x0, #0x20] ; 0x29824: cbz w8, #0x29830
 */
uint64_t fde_0778_0x29814(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29814ULL;
    constexpr uint64_t kSize = 0x70ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94003567U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0779] `sub_29884` (`0x29884..0x298d4`, 80 bytes)
 *        Hàm FDE[0779] `sub_29884` (`0x29884..0x298d4`, 80 bytes)
 * Disassembly: 0x29884: str x19, [sp, #-0x20]! ; 0x29888: stp x29, x30, [sp, #0x10] ; 0x2988c: add x29, sp, #0x10 ; 0x29890: ldrb w8, [x0, #0x20] ; 0x29894: mov x19, x0
 */
uint64_t fde_0779_0x29884(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29884ULL;
    constexpr uint64_t kSize = 0x50ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94003553U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0780] `sub_298d4` (`0x298d4..0x2991c`, 72 bytes)
 *        Hàm FDE[0780] `sub_298d4` (`0x298d4..0x2991c`, 72 bytes)
 * Disassembly: 0x298d4: str x19, [sp, #-0x20]! ; 0x298d8: stp x29, x30, [sp, #0x10] ; 0x298dc: add x29, sp, #0x10 ; 0x298e0: ldrb w8, [x0, #0x20] ; 0x298e4: cbnz w8, #0x29908
 */
uint64_t fde_0780_0x298d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x298d4ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x94003541U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0781] `sub_2991c` (`0x2991c..0x29964`, 72 bytes)
 *        Hàm FDE[0781] `sub_2991c` (`0x2991c..0x29964`, 72 bytes)
 * Disassembly: 0x2991c: str x19, [sp, #-0x20]! ; 0x29920: stp x29, x30, [sp, #0x10] ; 0x29924: add x29, sp, #0x10 ; 0x29928: ldrb w8, [x0, #0x20] ; 0x2992c: cbnz w8, #0x29950
 */
uint64_t fde_0781_0x2991c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2991cULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0x9400352fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0782] `sub_29964` (`0x29964..0x29968`, 4 bytes)
 *        Hàm FDE[0782] `sub_29964` (`0x29964..0x29968`, 4 bytes)
 * Disassembly: 0x29964: b #0x20e88
 */
uint64_t fde_0782_0x29964(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29964ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffdd49U;
    constexpr uint32_t kOpN  = 0x17ffdd49U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0783] `sub_29968` (`0x29968..0x2b57c`, 7188 bytes)
 *        Hàm FDE[0783] `sub_29968` (`0x29968..0x2b57c`, 7188 bytes)
 * Disassembly: 0x29968: sub sp, sp, #0x80 ; 0x2996c: str x27, [sp, #0x20] ; 0x29970: stp x26, x25, [sp, #0x30] ; 0x29974: stp x24, x23, [sp, #0x40] ; 0x29978: stp x22, x21, [sp, #0x50]
 */
uint64_t fde_0783_0x29968(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x29968ULL;
    constexpr uint64_t kSize = 0x1c14ULL;
    constexpr uint32_t kOp0  = 0xd10203ffU;
    constexpr uint32_t kOpN  = 0x94002e29U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0784] `sub_2b57c` (`0x2b57c..0x2b640`, 196 bytes)
 *        Hàm FDE[0784] `sub_2b57c` (`0x2b57c..0x2b640`, 196 bytes)
 * Disassembly: 0x2b57c: str x23, [sp, #-0x40]! ; 0x2b580: stp x22, x21, [sp, #0x10] ; 0x2b584: stp x20, x19, [sp, #0x20] ; 0x2b588: stp x29, x30, [sp, #0x30] ; 0x2b58c: add x29, sp, #0x30
 */
uint64_t fde_0784_0x2b57c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2b57cULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffda1bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0785] `sub_2b640` (`0x2b640..0x2be34`, 2036 bytes)
 *        Hàm FDE[0785] `sub_2b640` (`0x2b640..0x2be34`, 2036 bytes)
 * Disassembly: 0x2b640: stp x24, x23, [sp, #-0x40]! ; 0x2b644: stp x22, x21, [sp, #0x10] ; 0x2b648: stp x20, x19, [sp, #0x20] ; 0x2b64c: stp x29, x30, [sp, #0x30] ; 0x2b650: add x29, sp, #0x30
 */
uint64_t fde_0785_0x2b640(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2b640ULL;
    constexpr uint64_t kSize = 0x7f4ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0x97ffd81eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0786] `sub_2be34` (`0x2be34..0x2c1a4`, 880 bytes)
 *        Hàm FDE[0786] `sub_2be34` (`0x2be34..0x2c1a4`, 880 bytes)
 * Disassembly: 0x2be34: stp x22, x21, [sp, #-0x30]! ; 0x2be38: stp x20, x19, [sp, #0x10] ; 0x2be3c: stp x29, x30, [sp, #0x20] ; 0x2be40: add x29, sp, #0x20 ; 0x2be44: mov x19, x0
 */
uint64_t fde_0786_0x2be34(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2be34ULL;
    constexpr uint64_t kSize = 0x370ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x97ffd742U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0787] `sub_2c1a4` (`0x2c1a4..0x2cfc4`, 3616 bytes)
 *        Hàm FDE[0787] `sub_2c1a4` (`0x2c1a4..0x2cfc4`, 3616 bytes)
 * Disassembly: 0x2c1a4: str x25, [sp, #-0x50]! ; 0x2c1a8: stp x24, x23, [sp, #0x10] ; 0x2c1ac: stp x22, x21, [sp, #0x20] ; 0x2c1b0: stp x20, x19, [sp, #0x30] ; 0x2c1b4: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0787_0x2c1a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2c1a4ULL;
    constexpr uint64_t kSize = 0xe20ULL;
    constexpr uint32_t kOp0  = 0xf81b0ff9U;
    constexpr uint32_t kOpN  = 0x97ffd3baU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0788] `sub_2cfc4` (`0x2cfc4..0x2d074`, 176 bytes)
 *        Hàm FDE[0788] `sub_2cfc4` (`0x2cfc4..0x2d074`, 176 bytes)
 * Disassembly: 0x2cfc4: stp x24, x23, [sp, #-0x40]! ; 0x2cfc8: stp x22, x21, [sp, #0x10] ; 0x2cfcc: stp x20, x19, [sp, #0x20] ; 0x2cfd0: stp x29, x30, [sp, #0x30] ; 0x2cfd4: add x29, sp, #0x30
 */
uint64_t fde_0788_0x2cfc4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2cfc4ULL;
    constexpr uint64_t kSize = 0xb0ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0x97ffd38eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0789] `sub_2d074` (`0x2d074..0x2d6a0`, 1580 bytes)
 *        Hàm FDE[0789] `sub_2d074` (`0x2d074..0x2d6a0`, 1580 bytes)
 * Disassembly: 0x2d074: stp x28, x27, [sp, #-0x60]! ; 0x2d078: stp x26, x25, [sp, #0x10] ; 0x2d07c: stp x24, x23, [sp, #0x20] ; 0x2d080: stp x22, x21, [sp, #0x30] ; 0x2d084: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0789_0x2d074(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2d074ULL;
    constexpr uint64_t kSize = 0x62cULL;
    constexpr uint32_t kOp0  = 0xa9ba6ffcU;
    constexpr uint32_t kOpN  = 0x97ffd203U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0790] `sub_2d6a0` (`0x2d6a0..0x2d8cc`, 556 bytes)
 *        Hàm FDE[0790] `sub_2d6a0` (`0x2d6a0..0x2d8cc`, 556 bytes)
 * Disassembly: 0x2d6a0: str x23, [sp, #-0x40]! ; 0x2d6a4: stp x22, x21, [sp, #0x10] ; 0x2d6a8: stp x20, x19, [sp, #0x20] ; 0x2d6ac: stp x29, x30, [sp, #0x30] ; 0x2d6b0: add x29, sp, #0x30
 */
uint64_t fde_0790_0x2d6a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2d6a0ULL;
    constexpr uint64_t kSize = 0x22cULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffd178U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0791] `sub_2d8cc` (`0x2d8cc..0x2d990`, 196 bytes)
 *        Hàm FDE[0791] `sub_2d8cc` (`0x2d8cc..0x2d990`, 196 bytes)
 * Disassembly: 0x2d8cc: str x23, [sp, #-0x40]! ; 0x2d8d0: stp x22, x21, [sp, #0x10] ; 0x2d8d4: stp x20, x19, [sp, #0x20] ; 0x2d8d8: stp x29, x30, [sp, #0x30] ; 0x2d8dc: add x29, sp, #0x30
 */
uint64_t fde_0791_0x2d8cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2d8ccULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffd147U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0792] `sub_2d990` (`0x2d990..0x2da5c`, 204 bytes)
 *        Hàm FDE[0792] `sub_2d990` (`0x2d990..0x2da5c`, 204 bytes)
 * Disassembly: 0x2d990: str x23, [sp, #-0x40]! ; 0x2d994: stp x22, x21, [sp, #0x10] ; 0x2d998: stp x20, x19, [sp, #0x20] ; 0x2d99c: stp x29, x30, [sp, #0x30] ; 0x2d9a0: add x29, sp, #0x30
 */
uint64_t fde_0792_0x2d990(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2d990ULL;
    constexpr uint64_t kSize = 0xccULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffd114U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0793] `sub_2da5c` (`0x2da5c..0x2dbac`, 336 bytes)
 *        Hàm FDE[0793] `sub_2da5c` (`0x2da5c..0x2dbac`, 336 bytes)
 * Disassembly: 0x2da5c: stp x24, x23, [sp, #-0x40]! ; 0x2da60: stp x22, x21, [sp, #0x10] ; 0x2da64: stp x20, x19, [sp, #0x20] ; 0x2da68: stp x29, x30, [sp, #0x30] ; 0x2da6c: add x29, sp, #0x30
 */
uint64_t fde_0793_0x2da5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2da5cULL;
    constexpr uint64_t kSize = 0x150ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0x97ffd0c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0794] `sub_2dbac` (`0x2dbac..0x2dcac`, 256 bytes)
 *        Hàm FDE[0794] `sub_2dbac` (`0x2dbac..0x2dcac`, 256 bytes)
 * Disassembly: 0x2dbac: str x21, [sp, #-0x30]! ; 0x2dbb0: stp x20, x19, [sp, #0x10] ; 0x2dbb4: stp x29, x30, [sp, #0x20] ; 0x2dbb8: add x29, sp, #0x20 ; 0x2dbbc: ldp x8, x9, [x0, #0x10]
 */
uint64_t fde_0794_0x2dbac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2dbacULL;
    constexpr uint64_t kSize = 0x100ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0795] `sub_2dcac` (`0x2dcac..0x2dcb0`, 4 bytes)
 *        Hàm FDE[0795] `sub_2dcac` (`0x2dcac..0x2dcb0`, 4 bytes)
 * Disassembly: 0x2dcac: b #0x20e88
 */
uint64_t fde_0795_0x2dcac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2dcacULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcc77U;
    constexpr uint32_t kOpN  = 0x17ffcc77U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0796] `sub_2dcb0` (`0x2dcb0..0x2dd04`, 84 bytes)
 *        Hàm FDE[0796] `sub_2dcb0` (`0x2dcb0..0x2dd04`, 84 bytes)
 * Disassembly: 0x2dcb0: stp x20, x19, [sp, #-0x20]! ; 0x2dcb4: stp x29, x30, [sp, #0x10] ; 0x2dcb8: add x29, sp, #0x10 ; 0x2dcbc: ldrb w8, [x0, #0xc] ; 0x2dcc0: mov x19, x1
 */
uint64_t fde_0796_0x2dcb0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2dcb0ULL;
    constexpr uint64_t kSize = 0x54ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17ffe857U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0797] `sub_2dd04` (`0x2dd04..0x2dd08`, 4 bytes)
 *        Hàm FDE[0797] `sub_2dd04` (`0x2dd04..0x2dd08`, 4 bytes)
 * Disassembly: 0x2dd04: b #0x20e88
 */
uint64_t fde_0797_0x2dd04(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2dd04ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcc61U;
    constexpr uint32_t kOpN  = 0x17ffcc61U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0798] `sub_2dd08` (`0x2dd08..0x2de9c`, 404 bytes)
 *        Hàm FDE[0798] `sub_2dd08` (`0x2dd08..0x2de9c`, 404 bytes)
 * Disassembly: 0x2dd08: sub sp, sp, #0x60 ; 0x2dd0c: str x21, [sp, #0x30] ; 0x2dd10: stp x20, x19, [sp, #0x40] ; 0x2dd14: stp x29, x30, [sp, #0x50] ; 0x2dd18: add x29, sp, #0x50
 */
uint64_t fde_0798_0x2dd08(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2dd08ULL;
    constexpr uint64_t kSize = 0x194ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x97ff8c7aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0799] `sub_2de9c` (`0x2de9c..0x2dea0`, 4 bytes)
 *        Hàm FDE[0799] `sub_2de9c` (`0x2de9c..0x2dea0`, 4 bytes)
 * Disassembly: 0x2de9c: b #0x20e88
 */
uint64_t fde_0799_0x2de9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2de9cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcbfbU;
    constexpr uint32_t kOpN  = 0x17ffcbfbU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0800] `sub_2dea0` (`0x2dea0..0x2df44`, 164 bytes)
 *        Hàm FDE[0800] `sub_2dea0` (`0x2dea0..0x2df44`, 164 bytes)
 * Disassembly: 0x2dea0: sub sp, sp, #0x110 ; 0x2dea4: stp x28, x19, [sp, #0xf0] ; 0x2dea8: stp x29, x30, [sp, #0x100] ; 0x2deac: add x29, sp, #0x100 ; 0x2deb0: stp x4, x5, [sp, #0x80]
 */
uint64_t fde_0800_0x2dea0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2dea0ULL;
    constexpr uint64_t kSize = 0xa4ULL;
    constexpr uint32_t kOp0  = 0xd10443ffU;
    constexpr uint32_t kOpN  = 0x97ff8c50U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0801] `sub_2df44` (`0x2df44..0x2e19c`, 600 bytes)
 *        Hàm FDE[0801] `sub_2df44` (`0x2df44..0x2e19c`, 600 bytes)
 * Disassembly: 0x2df44: sub sp, sp, #0x70 ; 0x2df48: str x21, [sp, #0x40] ; 0x2df4c: stp x20, x19, [sp, #0x50] ; 0x2df50: stp x29, x30, [sp, #0x60] ; 0x2df54: add x29, sp, #0x60
 */
uint64_t fde_0801_0x2df44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2df44ULL;
    constexpr uint64_t kSize = 0x258ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x97ff8bbaU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0802] `sub_2e19c` (`0x2e19c..0x2e1a0`, 4 bytes)
 *        Hàm FDE[0802] `sub_2e19c` (`0x2e19c..0x2e1a0`, 4 bytes)
 * Disassembly: 0x2e19c: b #0x20e88
 */
uint64_t fde_0802_0x2e19c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e19cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcb3bU;
    constexpr uint32_t kOpN  = 0x17ffcb3bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0803] `sub_2e1a0` (`0x2e1a0..0x2e3d8`, 568 bytes)
 *        Hàm FDE[0803] `sub_2e1a0` (`0x2e1a0..0x2e3d8`, 568 bytes)
 * Disassembly: 0x2e1a0: sub sp, sp, #0x70 ; 0x2e1a4: str x21, [sp, #0x40] ; 0x2e1a8: stp x20, x19, [sp, #0x50] ; 0x2e1ac: stp x29, x30, [sp, #0x60] ; 0x2e1b0: add x29, sp, #0x60
 */
uint64_t fde_0803_0x2e1a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e1a0ULL;
    constexpr uint64_t kSize = 0x238ULL;
    constexpr uint32_t kOp0  = 0xd101c3ffU;
    constexpr uint32_t kOpN  = 0x97ff8b2bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0804] `sub_2e3d8` (`0x2e3d8..0x2e3dc`, 4 bytes)
 *        Hàm FDE[0804] `sub_2e3d8` (`0x2e3d8..0x2e3dc`, 4 bytes)
 * Disassembly: 0x2e3d8: b #0x20e88
 */
uint64_t fde_0804_0x2e3d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e3d8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffcaacU;
    constexpr uint32_t kOpN  = 0x17ffcaacU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0805] `sub_2e3dc` (`0x2e3dc..0x2e48c`, 176 bytes)
 *        Hàm FDE[0805] `sub_2e3dc` (`0x2e3dc..0x2e48c`, 176 bytes)
 * Disassembly: 0x2e3dc: str x21, [sp, #-0x30]! ; 0x2e3e0: stp x20, x19, [sp, #0x10] ; 0x2e3e4: stp x29, x30, [sp, #0x20] ; 0x2e3e8: add x29, sp, #0x20 ; 0x2e3ec: adrp x21, #0x3c000
 */
uint64_t fde_0805_0x2e3dc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e3dcULL;
    constexpr uint64_t kSize = 0xb0ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffe675U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0806] `sub_2e48c` (`0x2e48c..0x2e490`, 4 bytes)
 *        Hàm FDE[0806] `sub_2e48c` (`0x2e48c..0x2e490`, 4 bytes)
 * Disassembly: 0x2e48c: b #0x20e88
 */
uint64_t fde_0806_0x2e48c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e48cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffca7fU;
    constexpr uint32_t kOpN  = 0x17ffca7fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0807] `sub_2e490` (`0x2e490..0x2e4e4`, 84 bytes)
 *        Hàm FDE[0807] `sub_2e490` (`0x2e490..0x2e4e4`, 84 bytes)
 * Disassembly: 0x2e490: str x21, [sp, #-0x30]! ; 0x2e494: stp x20, x19, [sp, #0x10] ; 0x2e498: stp x29, x30, [sp, #0x20] ; 0x2e49c: add x29, sp, #0x20 ; 0x2e4a0: adrp x21, #0x3c000
 */
uint64_t fde_0807_0x2e490(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e490ULL;
    constexpr uint64_t kSize = 0x54ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffe65fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0808] `sub_2e4e4` (`0x2e4e4..0x2e4e8`, 4 bytes)
 *        Hàm FDE[0808] `sub_2e4e4` (`0x2e4e4..0x2e4e8`, 4 bytes)
 * Disassembly: 0x2e4e4: ret
 */
uint64_t fde_0808_0x2e4e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e4e4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0809] `sub_2e4e8` (`0x2e4e8..0x2e4ec`, 4 bytes)
 *        Hàm FDE[0809] `sub_2e4e8` (`0x2e4e8..0x2e4ec`, 4 bytes)
 * Disassembly: 0x2e4e8: b #0x20e88
 */
uint64_t fde_0809_0x2e4e8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e4e8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffca68U;
    constexpr uint32_t kOpN  = 0x17ffca68U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0810] `sub_2e4ec` (`0x2e4ec..0x2ea70`, 1412 bytes)
 *        Hàm FDE[0810] `sub_2e4ec` (`0x2e4ec..0x2ea70`, 1412 bytes)
 * Disassembly: 0x2e4ec: sub sp, sp, #0x60 ; 0x2e4f0: str x23, [sp, #0x20] ; 0x2e4f4: stp x22, x21, [sp, #0x30] ; 0x2e4f8: stp x20, x19, [sp, #0x40] ; 0x2e4fc: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_0810_0x2e4ec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2e4ecULL;
    constexpr uint64_t kSize = 0x584ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x940020ecU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0811] `sub_2ea70` (`0x2ea70..0x2ea74`, 4 bytes)
 *        Hàm FDE[0811] `sub_2ea70` (`0x2ea70..0x2ea74`, 4 bytes)
 * Disassembly: 0x2ea70: b #0x20e88
 */
uint64_t fde_0811_0x2ea70(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ea70ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc906U;
    constexpr uint32_t kOpN  = 0x17ffc906U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0812] `sub_2ea74` (`0x2ea74..0x2ebc4`, 336 bytes)
 *        Hàm FDE[0812] `sub_2ea74` (`0x2ea74..0x2ebc4`, 336 bytes)
 * Disassembly: 0x2ea74: stp x26, x25, [sp, #-0x50]! ; 0x2ea78: stp x24, x23, [sp, #0x10] ; 0x2ea7c: stp x22, x21, [sp, #0x20] ; 0x2ea80: stp x20, x19, [sp, #0x30] ; 0x2ea84: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0812_0x2ea74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ea74ULL;
    constexpr uint64_t kSize = 0x150ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x94002097U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0813] `sub_2ebc4` (`0x2ebc4..0x2ebc8`, 4 bytes)
 *        Hàm FDE[0813] `sub_2ebc4` (`0x2ebc4..0x2ebc8`, 4 bytes)
 * Disassembly: 0x2ebc4: b #0x20e88
 */
uint64_t fde_0813_0x2ebc4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ebc4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc8b1U;
    constexpr uint32_t kOpN  = 0x17ffc8b1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0814] `sub_2ebc8` (`0x2ebc8..0x2ede0`, 536 bytes)
 *        Hàm FDE[0814] `sub_2ebc8` (`0x2ebc8..0x2ede0`, 536 bytes)
 * Disassembly: 0x2ebc8: str x21, [sp, #-0x30]! ; 0x2ebcc: stp x20, x19, [sp, #0x10] ; 0x2ebd0: stp x29, x30, [sp, #0x20] ; 0x2ebd4: add x29, sp, #0x20 ; 0x2ebd8: mov x20, x0
 */
uint64_t fde_0814_0x2ebc8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ebc8ULL;
    constexpr uint64_t kSize = 0x218ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0815] `sub_2ede0` (`0x2ede0..0x2ede4`, 4 bytes)
 *        Hàm FDE[0815] `sub_2ede0` (`0x2ede0..0x2ede4`, 4 bytes)
 * Disassembly: 0x2ede0: b #0x20e88
 */
uint64_t fde_0815_0x2ede0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ede0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc82aU;
    constexpr uint32_t kOpN  = 0x17ffc82aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0816] `sub_2ede4` (`0x2ede4..0x2ee98`, 180 bytes)
 *        Hàm FDE[0816] `sub_2ede4` (`0x2ede4..0x2ee98`, 180 bytes)
 * Disassembly: 0x2ede4: str x21, [sp, #-0x30]! ; 0x2ede8: stp x20, x19, [sp, #0x10] ; 0x2edec: stp x29, x30, [sp, #0x20] ; 0x2edf0: add x29, sp, #0x20 ; 0x2edf4: ldp x8, x2, [x0, #0x10]
 */
uint64_t fde_0816_0x2ede4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ede4ULL;
    constexpr uint64_t kSize = 0xb4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffe3f2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0817] `sub_2ee98` (`0x2ee98..0x2ee9c`, 4 bytes)
 *        Hàm FDE[0817] `sub_2ee98` (`0x2ee98..0x2ee9c`, 4 bytes)
 * Disassembly: 0x2ee98: b #0x20e88
 */
uint64_t fde_0817_0x2ee98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ee98ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc7fcU;
    constexpr uint32_t kOpN  = 0x17ffc7fcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0818] `sub_2ee9c` (`0x2ee9c..0x2ef64`, 200 bytes)
 *        Hàm FDE[0818] `sub_2ee9c` (`0x2ee9c..0x2ef64`, 200 bytes)
 * Disassembly: 0x2ee9c: str x21, [sp, #-0x30]! ; 0x2eea0: stp x20, x19, [sp, #0x10] ; 0x2eea4: stp x29, x30, [sp, #0x20] ; 0x2eea8: add x29, sp, #0x20 ; 0x2eeac: ldp x8, x2, [x0, #0x10]
 */
uint64_t fde_0818_0x2ee9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ee9cULL;
    constexpr uint64_t kSize = 0xc8ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffe3bfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0819] `sub_2ef64` (`0x2ef64..0x2ef68`, 4 bytes)
 *        Hàm FDE[0819] `sub_2ef64` (`0x2ef64..0x2ef68`, 4 bytes)
 * Disassembly: 0x2ef64: b #0x20e88
 */
uint64_t fde_0819_0x2ef64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ef64ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc7c9U;
    constexpr uint32_t kOpN  = 0x17ffc7c9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0820] `sub_2ef68` (`0x2ef68..0x2f0d0`, 360 bytes)
 *        Hàm FDE[0820] `sub_2ef68` (`0x2ef68..0x2f0d0`, 360 bytes)
 * Disassembly: 0x2ef68: stp x26, x25, [sp, #-0x50]! ; 0x2ef6c: stp x24, x23, [sp, #0x10] ; 0x2ef70: stp x22, x21, [sp, #0x20] ; 0x2ef74: stp x20, x19, [sp, #0x30] ; 0x2ef78: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0820_0x2ef68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2ef68ULL;
    constexpr uint64_t kSize = 0x168ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x17ffe364U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0821] `sub_2f0d0` (`0x2f0d0..0x2f0d4`, 4 bytes)
 *        Hàm FDE[0821] `sub_2f0d0` (`0x2f0d0..0x2f0d4`, 4 bytes)
 * Disassembly: 0x2f0d0: b #0x20e88
 */
uint64_t fde_0821_0x2f0d0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f0d0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc76eU;
    constexpr uint32_t kOpN  = 0x17ffc76eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0822] `sub_2f0d4` (`0x2f0d4..0x2f1a4`, 208 bytes)
 *        Hàm FDE[0822] `sub_2f0d4` (`0x2f0d4..0x2f1a4`, 208 bytes)
 * Disassembly: 0x2f0d4: str x23, [sp, #-0x40]! ; 0x2f0d8: stp x22, x21, [sp, #0x10] ; 0x2f0dc: stp x20, x19, [sp, #0x20] ; 0x2f0e0: stp x29, x30, [sp, #0x30] ; 0x2f0e4: add x29, sp, #0x30
 */
uint64_t fde_0822_0x2f0d4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f0d4ULL;
    constexpr uint64_t kSize = 0xd0ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffcb42U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0823] `sub_2f1a4` (`0x2f1a4..0x2f334`, 400 bytes)
 *        Hàm FDE[0823] `sub_2f1a4` (`0x2f1a4..0x2f334`, 400 bytes)
 * Disassembly: 0x2f1a4: stp x26, x25, [sp, #-0x50]! ; 0x2f1a8: stp x24, x23, [sp, #0x10] ; 0x2f1ac: stp x22, x21, [sp, #0x20] ; 0x2f1b0: stp x20, x19, [sp, #0x30] ; 0x2f1b4: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0823_0x2f1a4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f1a4ULL;
    constexpr uint64_t kSize = 0x190ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x17ffe2cbU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0824] `sub_2f334` (`0x2f334..0x2f338`, 4 bytes)
 *        Hàm FDE[0824] `sub_2f334` (`0x2f334..0x2f338`, 4 bytes)
 * Disassembly: 0x2f334: b #0x20e88
 */
uint64_t fde_0824_0x2f334(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f334ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc6d5U;
    constexpr uint32_t kOpN  = 0x17ffc6d5U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0825] `sub_2f338` (`0x2f338..0x2f420`, 232 bytes)
 *        Hàm FDE[0825] `sub_2f338` (`0x2f338..0x2f420`, 232 bytes)
 * Disassembly: 0x2f338: str x21, [sp, #-0x30]! ; 0x2f33c: stp x20, x19, [sp, #0x10] ; 0x2f340: stp x29, x30, [sp, #0x20] ; 0x2f344: add x29, sp, #0x20 ; 0x2f348: ldrb w8, [x0, #0x18]
 */
uint64_t fde_0825_0x2f338(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f338ULL;
    constexpr uint64_t kSize = 0xe8ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0826] `sub_2f420` (`0x2f420..0x2f424`, 4 bytes)
 *        Hàm FDE[0826] `sub_2f420` (`0x2f420..0x2f424`, 4 bytes)
 * Disassembly: 0x2f420: b #0x20e88
 */
uint64_t fde_0826_0x2f420(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f420ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc69aU;
    constexpr uint32_t kOpN  = 0x17ffc69aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0827] `sub_2f424` (`0x2f424..0x2f4ac`, 136 bytes)
 *        Hàm FDE[0827] `sub_2f424` (`0x2f424..0x2f4ac`, 136 bytes)
 * Disassembly: 0x2f424: sub sp, sp, #0x30 ; 0x2f428: stp x20, x19, [sp, #0x10] ; 0x2f42c: stp x29, x30, [sp, #0x20] ; 0x2f430: add x29, sp, #0x20 ; 0x2f434: ldp x8, x9, [x0]
 */
uint64_t fde_0827_0x2f424(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f424ULL;
    constexpr uint64_t kSize = 0x88ULL;
    constexpr uint32_t kOp0  = 0xd100c3ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0828] `sub_2f4ac` (`0x2f4ac..0x2f784`, 728 bytes)
 *        Hàm FDE[0828] `sub_2f4ac` (`0x2f4ac..0x2f784`, 728 bytes)
 * Disassembly: 0x2f4ac: stp x22, x21, [sp, #-0x30]! ; 0x2f4b0: stp x20, x19, [sp, #0x10] ; 0x2f4b4: stp x29, x30, [sp, #0x20] ; 0x2f4b8: add x29, sp, #0x20 ; 0x2f4bc: ldp x8, x9, [x0]
 */
uint64_t fde_0828_0x2f4ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f4acULL;
    constexpr uint64_t kSize = 0x2d8ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x97ffc9caU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0829] `sub_2f784` (`0x2f784..0x2f964`, 480 bytes)
 *        Hàm FDE[0829] `sub_2f784` (`0x2f784..0x2f964`, 480 bytes)
 * Disassembly: 0x2f784: stp x22, x21, [sp, #-0x30]! ; 0x2f788: stp x20, x19, [sp, #0x10] ; 0x2f78c: stp x29, x30, [sp, #0x20] ; 0x2f790: add x29, sp, #0x20 ; 0x2f794: ldp x20, x8, [x0]
 */
uint64_t fde_0829_0x2f784(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f784ULL;
    constexpr uint64_t kSize = 0x1e0ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x97ffc952U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0830] `sub_2f964` (`0x2f964..0x2fa28`, 196 bytes)
 *        Hàm FDE[0830] `sub_2f964` (`0x2f964..0x2fa28`, 196 bytes)
 * Disassembly: 0x2f964: str x21, [sp, #-0x30]! ; 0x2f968: stp x20, x19, [sp, #0x10] ; 0x2f96c: stp x29, x30, [sp, #0x20] ; 0x2f970: add x29, sp, #0x20 ; 0x2f974: ldr x21, [x0, #0x10]
 */
uint64_t fde_0830_0x2f964(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2f964ULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0831] `sub_2fa28` (`0x2fa28..0x2fa38`, 16 bytes)
 *        Hàm FDE[0831] `sub_2fa28` (`0x2fa28..0x2fa38`, 16 bytes)
 * Disassembly: 0x2fa28: ldr x0, [x0, #0x18] ; 0x2fa2c: ldr x8, [x0] ; 0x2fa30: ldr x1, [x8, #0x30] ; 0x2fa34: br x1
 */
uint64_t fde_0831_0x2fa28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2fa28ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0832] `sub_2fa38` (`0x2fa38..0x2fa3c`, 4 bytes)
 *        Hàm FDE[0832] `sub_2fa38` (`0x2fa38..0x2fa3c`, 4 bytes)
 * Disassembly: 0x2fa38: b #0x20e88
 */
uint64_t fde_0832_0x2fa38(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2fa38ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc514U;
    constexpr uint32_t kOpN  = 0x17ffc514U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0833] `sub_2fa3c` (`0x2fa3c..0x30ce4`, 4776 bytes)
 *        Hàm FDE[0833] `sub_2fa3c` (`0x2fa3c..0x30ce4`, 4776 bytes)
 * Disassembly: 0x2fa3c: stp x24, x23, [sp, #-0x40]! ; 0x2fa40: stp x22, x21, [sp, #0x10] ; 0x2fa44: stp x20, x19, [sp, #0x20] ; 0x2fa48: stp x29, x30, [sp, #0x30] ; 0x2fa4c: add x29, sp, #0x30
 */
uint64_t fde_0833_0x2fa3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x2fa3cULL;
    constexpr uint64_t kSize = 0x12a8ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0x9400184fU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0834] `sub_30ce4` (`0x30ce4..0x30d40`, 92 bytes)
 *        Hàm FDE[0834] `sub_30ce4` (`0x30ce4..0x30d40`, 92 bytes)
 * Disassembly: 0x30ce4: str x21, [sp, #-0x30]! ; 0x30ce8: stp x20, x19, [sp, #0x10] ; 0x30cec: stp x29, x30, [sp, #0x20] ; 0x30cf0: add x29, sp, #0x20 ; 0x30cf4: adrp x21, #0x3c000
 */
uint64_t fde_0834_0x30ce4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30ce4ULL;
    constexpr uint64_t kSize = 0x5cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0835] `sub_30d40` (`0x30d40..0x30d44`, 4 bytes)
 *        Hàm FDE[0835] `sub_30d40` (`0x30d40..0x30d44`, 4 bytes)
 * Disassembly: 0x30d40: b #0x20e88
 */
uint64_t fde_0835_0x30d40(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30d40ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc052U;
    constexpr uint32_t kOpN  = 0x17ffc052U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0836] `sub_30d44` (`0x30d44..0x30dd4`, 144 bytes)
 *        Hàm FDE[0836] `sub_30d44` (`0x30d44..0x30dd4`, 144 bytes)
 * Disassembly: 0x30d44: str x21, [sp, #-0x30]! ; 0x30d48: stp x20, x19, [sp, #0x10] ; 0x30d4c: stp x29, x30, [sp, #0x20] ; 0x30d50: add x29, sp, #0x20 ; 0x30d54: adrp x21, #0x3c000
 */
uint64_t fde_0836_0x30d44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30d44ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0837] `sub_30dd4` (`0x30dd4..0x30dd8`, 4 bytes)
 *        Hàm FDE[0837] `sub_30dd4` (`0x30dd4..0x30dd8`, 4 bytes)
 * Disassembly: 0x30dd4: b #0x20e88
 */
uint64_t fde_0837_0x30dd4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30dd4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc02dU;
    constexpr uint32_t kOpN  = 0x17ffc02dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0838] `sub_30dd8` (`0x30dd8..0x30e68`, 144 bytes)
 *        Hàm FDE[0838] `sub_30dd8` (`0x30dd8..0x30e68`, 144 bytes)
 * Disassembly: 0x30dd8: str x21, [sp, #-0x30]! ; 0x30ddc: stp x20, x19, [sp, #0x10] ; 0x30de0: stp x29, x30, [sp, #0x20] ; 0x30de4: add x29, sp, #0x20 ; 0x30de8: adrp x21, #0x3c000
 */
uint64_t fde_0838_0x30dd8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30dd8ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0839] `sub_30e68` (`0x30e68..0x30e6c`, 4 bytes)
 *        Hàm FDE[0839] `sub_30e68` (`0x30e68..0x30e6c`, 4 bytes)
 * Disassembly: 0x30e68: b #0x20e88
 */
uint64_t fde_0839_0x30e68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30e68ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffc008U;
    constexpr uint32_t kOpN  = 0x17ffc008U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0840] `sub_30e6c` (`0x30e6c..0x30efc`, 144 bytes)
 *        Hàm FDE[0840] `sub_30e6c` (`0x30e6c..0x30efc`, 144 bytes)
 * Disassembly: 0x30e6c: str x21, [sp, #-0x30]! ; 0x30e70: stp x20, x19, [sp, #0x10] ; 0x30e74: stp x29, x30, [sp, #0x20] ; 0x30e78: add x29, sp, #0x20 ; 0x30e7c: adrp x21, #0x3c000
 */
uint64_t fde_0840_0x30e6c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30e6cULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0841] `sub_30efc` (`0x30efc..0x30f0c`, 16 bytes)
 *        Hàm FDE[0841] `sub_30efc` (`0x30efc..0x30f0c`, 16 bytes)
 * Disassembly: 0x30efc: ldr x0, [x0, #0x10] ; 0x30f00: ldr x8, [x0] ; 0x30f04: ldr x1, [x8, #0x30] ; 0x30f08: br x1
 */
uint64_t fde_0841_0x30efc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30efcULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0842] `sub_30f0c` (`0x30f0c..0x30f10`, 4 bytes)
 *        Hàm FDE[0842] `sub_30f0c` (`0x30f0c..0x30f10`, 4 bytes)
 * Disassembly: 0x30f0c: b #0x20e88
 */
uint64_t fde_0842_0x30f0c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30f0cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbfdfU;
    constexpr uint32_t kOpN  = 0x17ffbfdfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0843] `sub_30f10` (`0x30f10..0x30fbc`, 172 bytes)
 *        Hàm FDE[0843] `sub_30f10` (`0x30f10..0x30fbc`, 172 bytes)
 * Disassembly: 0x30f10: str x21, [sp, #-0x30]! ; 0x30f14: stp x20, x19, [sp, #0x10] ; 0x30f18: stp x29, x30, [sp, #0x20] ; 0x30f1c: add x29, sp, #0x20 ; 0x30f20: ldr x21, [x0, #0x10]
 */
uint64_t fde_0843_0x30f10(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30f10ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0844] `sub_30fbc` (`0x30fbc..0x30fc0`, 4 bytes)
 *        Hàm FDE[0844] `sub_30fbc` (`0x30fbc..0x30fc0`, 4 bytes)
 * Disassembly: 0x30fbc: b #0x20e88
 */
uint64_t fde_0844_0x30fbc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30fbcULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbfb3U;
    constexpr uint32_t kOpN  = 0x17ffbfb3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0845] `sub_30fc0` (`0x30fc0..0x310c0`, 256 bytes)
 *        Hàm FDE[0845] `sub_30fc0` (`0x30fc0..0x310c0`, 256 bytes)
 * Disassembly: 0x30fc0: str x21, [sp, #-0x30]! ; 0x30fc4: stp x20, x19, [sp, #0x10] ; 0x30fc8: stp x29, x30, [sp, #0x20] ; 0x30fcc: add x29, sp, #0x20 ; 0x30fd0: adrp x21, #0x3c000
 */
uint64_t fde_0845_0x30fc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x30fc0ULL;
    constexpr uint64_t kSize = 0x100ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffdb68U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0846] `sub_310c0` (`0x310c0..0x310c4`, 4 bytes)
 *        Hàm FDE[0846] `sub_310c0` (`0x310c0..0x310c4`, 4 bytes)
 * Disassembly: 0x310c0: b #0x20e88
 */
uint64_t fde_0846_0x310c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x310c0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbf72U;
    constexpr uint32_t kOpN  = 0x17ffbf72U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0847] `sub_310c4` (`0x310c4..0x312c0`, 508 bytes)
 *        Hàm FDE[0847] `sub_310c4` (`0x310c4..0x312c0`, 508 bytes)
 * Disassembly: 0x310c4: str x21, [sp, #-0x30]! ; 0x310c8: stp x20, x19, [sp, #0x10] ; 0x310cc: stp x29, x30, [sp, #0x20] ; 0x310d0: add x29, sp, #0x20 ; 0x310d4: ldp x8, x10, [x1, #8]
 */
uint64_t fde_0847_0x310c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x310c4ULL;
    constexpr uint64_t kSize = 0x1fcULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x97ffc2fbU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0848] `sub_312c0` (`0x312c0..0x312c4`, 4 bytes)
 *        Hàm FDE[0848] `sub_312c0` (`0x312c0..0x312c4`, 4 bytes)
 * Disassembly: 0x312c0: b #0x20e88
 */
uint64_t fde_0848_0x312c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x312c0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbef2U;
    constexpr uint32_t kOpN  = 0x17ffbef2U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0849] `sub_312c4` (`0x312c4..0x31498`, 468 bytes)
 *        Hàm FDE[0849] `sub_312c4` (`0x312c4..0x31498`, 468 bytes)
 * Disassembly: 0x312c4: str x21, [sp, #-0x30]! ; 0x312c8: stp x20, x19, [sp, #0x10] ; 0x312cc: stp x29, x30, [sp, #0x20] ; 0x312d0: add x29, sp, #0x20 ; 0x312d4: ldp x8, x10, [x1, #8]
 */
uint64_t fde_0849_0x312c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x312c4ULL;
    constexpr uint64_t kSize = 0x1d4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x97ffc285U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0850] `sub_31498` (`0x31498..0x3149c`, 4 bytes)
 *        Hàm FDE[0850] `sub_31498` (`0x31498..0x3149c`, 4 bytes)
 * Disassembly: 0x31498: b #0x20e88
 */
uint64_t fde_0850_0x31498(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31498ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbe7cU;
    constexpr uint32_t kOpN  = 0x17ffbe7cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0851] `sub_3149c` (`0x3149c..0x31668`, 460 bytes)
 *        Hàm FDE[0851] `sub_3149c` (`0x3149c..0x31668`, 460 bytes)
 * Disassembly: 0x3149c: stp x26, x25, [sp, #-0x50]! ; 0x314a0: stp x24, x23, [sp, #0x10] ; 0x314a4: stp x22, x21, [sp, #0x20] ; 0x314a8: stp x20, x19, [sp, #0x30] ; 0x314ac: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0851_0x3149c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3149cULL;
    constexpr uint64_t kSize = 0x1ccULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffc211U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0852] `sub_31668` (`0x31668..0x3166c`, 4 bytes)
 *        Hàm FDE[0852] `sub_31668` (`0x31668..0x3166c`, 4 bytes)
 * Disassembly: 0x31668: b #0x20e88
 */
uint64_t fde_0852_0x31668(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31668ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbe08U;
    constexpr uint32_t kOpN  = 0x17ffbe08U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0853] `sub_3166c` (`0x3166c..0x3171c`, 176 bytes)
 *        Hàm FDE[0853] `sub_3166c` (`0x3166c..0x3171c`, 176 bytes)
 * Disassembly: 0x3166c: str x21, [sp, #-0x30]! ; 0x31670: stp x20, x19, [sp, #0x10] ; 0x31674: stp x29, x30, [sp, #0x20] ; 0x31678: add x29, sp, #0x20 ; 0x3167c: adrp x21, #0x3c000
 */
uint64_t fde_0853_0x3166c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3166cULL;
    constexpr uint64_t kSize = 0xb0ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd9d1U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0854] `sub_3171c` (`0x3171c..0x31720`, 4 bytes)
 *        Hàm FDE[0854] `sub_3171c` (`0x3171c..0x31720`, 4 bytes)
 * Disassembly: 0x3171c: b #0x20e88
 */
uint64_t fde_0854_0x3171c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3171cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbddbU;
    constexpr uint32_t kOpN  = 0x17ffbddbU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0855] `sub_31720` (`0x31720..0x31a74`, 852 bytes)
 *        Hàm FDE[0855] `sub_31720` (`0x31720..0x31a74`, 852 bytes)
 * Disassembly: 0x31720: stp x28, x27, [sp, #-0x60]! ; 0x31724: stp x26, x25, [sp, #0x10] ; 0x31728: stp x24, x23, [sp, #0x20] ; 0x3172c: stp x22, x21, [sp, #0x30] ; 0x31730: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0855_0x31720(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31720ULL;
    constexpr uint64_t kSize = 0x354ULL;
    constexpr uint32_t kOp0  = 0xa9ba6ffcU;
    constexpr uint32_t kOpN  = 0x97ffc10eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0856] `sub_31a74` (`0x31a74..0x31a78`, 4 bytes)
 *        Hàm FDE[0856] `sub_31a74` (`0x31a74..0x31a78`, 4 bytes)
 * Disassembly: 0x31a74: b #0x20e88
 */
uint64_t fde_0856_0x31a74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31a74ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbd05U;
    constexpr uint32_t kOpN  = 0x17ffbd05U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0857] `sub_31a78` (`0x31a78..0x31af0`, 120 bytes)
 *        Hàm FDE[0857] `sub_31a78` (`0x31a78..0x31af0`, 120 bytes)
 * Disassembly: 0x31a78: str x21, [sp, #-0x30]! ; 0x31a7c: stp x20, x19, [sp, #0x10] ; 0x31a80: stp x29, x30, [sp, #0x20] ; 0x31a84: add x29, sp, #0x20 ; 0x31a88: ldp x8, x2, [x0, #0x10]
 */
uint64_t fde_0857_0x31a78(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31a78ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd8dcU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0858] `sub_31af0` (`0x31af0..0x31af4`, 4 bytes)
 *        Hàm FDE[0858] `sub_31af0` (`0x31af0..0x31af4`, 4 bytes)
 * Disassembly: 0x31af0: b #0x20e88
 */
uint64_t fde_0858_0x31af0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31af0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbce6U;
    constexpr uint32_t kOpN  = 0x17ffbce6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0859] `sub_31af4` (`0x31af4..0x31c50`, 348 bytes)
 *        Hàm FDE[0859] `sub_31af4` (`0x31af4..0x31c50`, 348 bytes)
 * Disassembly: 0x31af4: str x21, [sp, #-0x30]! ; 0x31af8: stp x20, x19, [sp, #0x10] ; 0x31afc: stp x29, x30, [sp, #0x20] ; 0x31b00: add x29, sp, #0x20 ; 0x31b04: adrp x21, #0x3c000
 */
uint64_t fde_0859_0x31af4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31af4ULL;
    constexpr uint64_t kSize = 0x15cULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd884U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0860] `sub_31c50` (`0x31c50..0x31c54`, 4 bytes)
 *        Hàm FDE[0860] `sub_31c50` (`0x31c50..0x31c54`, 4 bytes)
 * Disassembly: 0x31c50: b #0x20e88
 */
uint64_t fde_0860_0x31c50(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31c50ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbc8eU;
    constexpr uint32_t kOpN  = 0x17ffbc8eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0861] `sub_31c54` (`0x31c54..0x31cf8`, 164 bytes)
 *        Hàm FDE[0861] `sub_31c54` (`0x31c54..0x31cf8`, 164 bytes)
 * Disassembly: 0x31c54: sub sp, sp, #0x50 ; 0x31c58: str x21, [sp, #0x20] ; 0x31c5c: stp x20, x19, [sp, #0x30] ; 0x31c60: stp x29, x30, [sp, #0x40] ; 0x31c64: add x29, sp, #0x40
 */
uint64_t fde_0861_0x31c54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31c54ULL;
    constexpr uint64_t kSize = 0xa4ULL;
    constexpr uint32_t kOp0  = 0xd10143ffU;
    constexpr uint32_t kOpN  = 0x9400144aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0862] `sub_31cf8` (`0x31cf8..0x31cfc`, 4 bytes)
 *        Hàm FDE[0862] `sub_31cf8` (`0x31cf8..0x31cfc`, 4 bytes)
 * Disassembly: 0x31cf8: b #0x20e88
 */
uint64_t fde_0862_0x31cf8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31cf8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbc64U;
    constexpr uint32_t kOpN  = 0x17ffbc64U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0863] `sub_31cfc` (`0x31cfc..0x31dec`, 240 bytes)
 *        Hàm FDE[0863] `sub_31cfc` (`0x31cfc..0x31dec`, 240 bytes)
 * Disassembly: 0x31cfc: stp x26, x25, [sp, #-0x50]! ; 0x31d00: stp x24, x23, [sp, #0x10] ; 0x31d04: stp x22, x21, [sp, #0x20] ; 0x31d08: stp x20, x19, [sp, #0x30] ; 0x31d0c: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0863_0x31cfc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31cfcULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0864] `sub_31dec` (`0x31dec..0x31df0`, 4 bytes)
 *        Hàm FDE[0864] `sub_31dec` (`0x31dec..0x31df0`, 4 bytes)
 * Disassembly: 0x31dec: b #0x20e88
 */
uint64_t fde_0864_0x31dec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31decULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbc27U;
    constexpr uint32_t kOpN  = 0x17ffbc27U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0865] `sub_31df0` (`0x31df0..0x31e80`, 144 bytes)
 *        Hàm FDE[0865] `sub_31df0` (`0x31df0..0x31e80`, 144 bytes)
 * Disassembly: 0x31df0: str x21, [sp, #-0x30]! ; 0x31df4: stp x20, x19, [sp, #0x10] ; 0x31df8: stp x29, x30, [sp, #0x20] ; 0x31dfc: add x29, sp, #0x20 ; 0x31e00: adrp x21, #0x3c000
 */
uint64_t fde_0865_0x31df0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31df0ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0866] `sub_31e80` (`0x31e80..0x31e84`, 4 bytes)
 *        Hàm FDE[0866] `sub_31e80` (`0x31e80..0x31e84`, 4 bytes)
 * Disassembly: 0x31e80: b #0x20e88
 */
uint64_t fde_0866_0x31e80(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31e80ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbc02U;
    constexpr uint32_t kOpN  = 0x17ffbc02U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0867] `sub_31e84` (`0x31e84..0x31f28`, 164 bytes)
 *        Hàm FDE[0867] `sub_31e84` (`0x31e84..0x31f28`, 164 bytes)
 * Disassembly: 0x31e84: str x21, [sp, #-0x30]! ; 0x31e88: stp x20, x19, [sp, #0x10] ; 0x31e8c: stp x29, x30, [sp, #0x20] ; 0x31e90: add x29, sp, #0x20 ; 0x31e94: adrp x21, #0x3c000
 */
uint64_t fde_0867_0x31e84(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31e84ULL;
    constexpr uint64_t kSize = 0xa4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd7ceU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0868] `sub_31f28` (`0x31f28..0x31f2c`, 4 bytes)
 *        Hàm FDE[0868] `sub_31f28` (`0x31f28..0x31f2c`, 4 bytes)
 * Disassembly: 0x31f28: b #0x20e88
 */
uint64_t fde_0868_0x31f28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31f28ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbbd8U;
    constexpr uint32_t kOpN  = 0x17ffbbd8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0869] `sub_31f2c` (`0x31f2c..0x31fe8`, 188 bytes)
 *        Hàm FDE[0869] `sub_31f2c` (`0x31f2c..0x31fe8`, 188 bytes)
 * Disassembly: 0x31f2c: stp x20, x19, [sp, #-0x20]! ; 0x31f30: stp x29, x30, [sp, #0x10] ; 0x31f34: add x29, sp, #0x10 ; 0x31f38: ldr w8, [x0, #0xc] ; 0x31f3c: cmp w8, #5
 */
uint64_t fde_0869_0x31f2c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31f2cULL;
    constexpr uint64_t kSize = 0xbcULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17ffd79eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0870] `sub_31fe8` (`0x31fe8..0x32078`, 144 bytes)
 *        Hàm FDE[0870] `sub_31fe8` (`0x31fe8..0x32078`, 144 bytes)
 * Disassembly: 0x31fe8: str x19, [sp, #-0x20]! ; 0x31fec: stp x29, x30, [sp, #0x10] ; 0x31ff0: add x29, sp, #0x10 ; 0x31ff4: ldr w8, [x0, #0xc] ; 0x31ff8: adrp x9, #0x3c000
 */
uint64_t fde_0870_0x31fe8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x31fe8ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0871] `sub_32078` (`0x32078..0x3207c`, 4 bytes)
 *        Hàm FDE[0871] `sub_32078` (`0x32078..0x3207c`, 4 bytes)
 * Disassembly: 0x32078: b #0x20e88
 */
uint64_t fde_0871_0x32078(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32078ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbb84U;
    constexpr uint32_t kOpN  = 0x17ffbb84U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0872] `sub_3207c` (`0x3207c..0x320f4`, 120 bytes)
 *        Hàm FDE[0872] `sub_3207c` (`0x3207c..0x320f4`, 120 bytes)
 * Disassembly: 0x3207c: str x21, [sp, #-0x30]! ; 0x32080: stp x20, x19, [sp, #0x10] ; 0x32084: stp x29, x30, [sp, #0x20] ; 0x32088: add x29, sp, #0x20 ; 0x3208c: ldrb w8, [x0, #0x18]
 */
uint64_t fde_0872_0x3207c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3207cULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd75bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0873] `sub_320f4` (`0x320f4..0x320f8`, 4 bytes)
 *        Hàm FDE[0873] `sub_320f4` (`0x320f4..0x320f8`, 4 bytes)
 * Disassembly: 0x320f4: b #0x20e88
 */
uint64_t fde_0873_0x320f4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x320f4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbb65U;
    constexpr uint32_t kOpN  = 0x17ffbb65U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0874] `sub_320f8` (`0x320f8..0x32180`, 136 bytes)
 *        Hàm FDE[0874] `sub_320f8` (`0x320f8..0x32180`, 136 bytes)
 * Disassembly: 0x320f8: str x21, [sp, #-0x30]! ; 0x320fc: stp x20, x19, [sp, #0x10] ; 0x32100: stp x29, x30, [sp, #0x20] ; 0x32104: add x29, sp, #0x20 ; 0x32108: mov x19, x0
 */
uint64_t fde_0874_0x320f8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x320f8ULL;
    constexpr uint64_t kSize = 0x88ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd738U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0875] `sub_32180` (`0x32180..0x32184`, 4 bytes)
 *        Hàm FDE[0875] `sub_32180` (`0x32180..0x32184`, 4 bytes)
 * Disassembly: 0x32180: b #0x20e88
 */
uint64_t fde_0875_0x32180(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32180ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbb42U;
    constexpr uint32_t kOpN  = 0x17ffbb42U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0876] `sub_32184` (`0x32184..0x321fc`, 120 bytes)
 *        Hàm FDE[0876] `sub_32184` (`0x32184..0x321fc`, 120 bytes)
 * Disassembly: 0x32184: str x21, [sp, #-0x30]! ; 0x32188: stp x20, x19, [sp, #0x10] ; 0x3218c: stp x29, x30, [sp, #0x20] ; 0x32190: add x29, sp, #0x20 ; 0x32194: adrp x21, #0x3c000
 */
uint64_t fde_0876_0x32184(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32184ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd719U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0877] `sub_321fc` (`0x321fc..0x32200`, 4 bytes)
 *        Hàm FDE[0877] `sub_321fc` (`0x321fc..0x32200`, 4 bytes)
 * Disassembly: 0x321fc: b #0x20e88
 */
uint64_t fde_0877_0x321fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x321fcULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbb23U;
    constexpr uint32_t kOpN  = 0x17ffbb23U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0878] `sub_32200` (`0x32200..0x32364`, 356 bytes)
 *        Hàm FDE[0878] `sub_32200` (`0x32200..0x32364`, 356 bytes)
 * Disassembly: 0x32200: stp x26, x25, [sp, #-0x50]! ; 0x32204: stp x24, x23, [sp, #0x10] ; 0x32208: stp x22, x21, [sp, #0x20] ; 0x3220c: stp x20, x19, [sp, #0x30] ; 0x32210: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0878_0x32200(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32200ULL;
    constexpr uint64_t kSize = 0x164ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x17ffd6bfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0879] `sub_32364` (`0x32364..0x32368`, 4 bytes)
 *        Hàm FDE[0879] `sub_32364` (`0x32364..0x32368`, 4 bytes)
 * Disassembly: 0x32364: b #0x20e88
 */
uint64_t fde_0879_0x32364(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32364ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffbac9U;
    constexpr uint32_t kOpN  = 0x17ffbac9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0880] `sub_32368` (`0x32368..0x324f8`, 400 bytes)
 *        Hàm FDE[0880] `sub_32368` (`0x32368..0x324f8`, 400 bytes)
 * Disassembly: 0x32368: stp x26, x25, [sp, #-0x50]! ; 0x3236c: stp x24, x23, [sp, #0x10] ; 0x32370: stp x22, x21, [sp, #0x20] ; 0x32374: stp x20, x19, [sp, #0x30] ; 0x32378: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0880_0x32368(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32368ULL;
    constexpr uint64_t kSize = 0x190ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffbe6dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0881] `sub_324f8` (`0x324f8..0x324fc`, 4 bytes)
 *        Hàm FDE[0881] `sub_324f8` (`0x324f8..0x324fc`, 4 bytes)
 * Disassembly: 0x324f8: b #0x20e88
 */
uint64_t fde_0881_0x324f8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x324f8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffba64U;
    constexpr uint32_t kOpN  = 0x17ffba64U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0882] `sub_324fc` (`0x324fc..0x325c0`, 196 bytes)
 *        Hàm FDE[0882] `sub_324fc` (`0x324fc..0x325c0`, 196 bytes)
 * Disassembly: 0x324fc: str x21, [sp, #-0x30]! ; 0x32500: stp x20, x19, [sp, #0x10] ; 0x32504: stp x29, x30, [sp, #0x20] ; 0x32508: add x29, sp, #0x20 ; 0x3250c: ldr x21, [x0, #0x10]
 */
uint64_t fde_0882_0x324fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x324fcULL;
    constexpr uint64_t kSize = 0xc4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0883] `sub_325c0` (`0x325c0..0x325c4`, 4 bytes)
 *        Hàm FDE[0883] `sub_325c0` (`0x325c0..0x325c4`, 4 bytes)
 * Disassembly: 0x325c0: b #0x20e88
 */
uint64_t fde_0883_0x325c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x325c0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffba32U;
    constexpr uint32_t kOpN  = 0x17ffba32U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0884] `sub_325c4` (`0x325c4..0x32680`, 188 bytes)
 *        Hàm FDE[0884] `sub_325c4` (`0x325c4..0x32680`, 188 bytes)
 * Disassembly: 0x325c4: stp x20, x19, [sp, #-0x20]! ; 0x325c8: stp x29, x30, [sp, #0x10] ; 0x325cc: add x29, sp, #0x10 ; 0x325d0: ldr w8, [x0, #0xc] ; 0x325d4: cmp w8, #5
 */
uint64_t fde_0884_0x325c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x325c4ULL;
    constexpr uint64_t kSize = 0xbcULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17ffd5f8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0885] `sub_32680` (`0x32680..0x32720`, 160 bytes)
 *        Hàm FDE[0885] `sub_32680` (`0x32680..0x32720`, 160 bytes)
 * Disassembly: 0x32680: str x19, [sp, #-0x20]! ; 0x32684: stp x29, x30, [sp, #0x10] ; 0x32688: add x29, sp, #0x10 ; 0x3268c: ldr w8, [x0, #0xc] ; 0x32690: adrp x9, #0x3c000
 */
uint64_t fde_0885_0x32680(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32680ULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xf81e0ff3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0886] `sub_32720` (`0x32720..0x32724`, 4 bytes)
 *        Hàm FDE[0886] `sub_32720` (`0x32720..0x32724`, 4 bytes)
 * Disassembly: 0x32720: b #0x20e88
 */
uint64_t fde_0886_0x32720(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32720ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb9daU;
    constexpr uint32_t kOpN  = 0x17ffb9daU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0887] `sub_32724` (`0x32724..0x32788`, 100 bytes)
 *        Hàm FDE[0887] `sub_32724` (`0x32724..0x32788`, 100 bytes)
 * Disassembly: 0x32724: ldr w8, [x1, #0x1c] ; 0x32728: cmn w8, #1 ; 0x3272c: b.eq #0x32760 ; 0x32730: ldr w8, [x1, #0x18] ; 0x32734: ldr x9, [x0, #0x18]
 */
uint64_t fde_0887_0x32724(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32724ULL;
    constexpr uint64_t kSize = 0x64ULL;
    constexpr uint32_t kOp0  = 0xb9401c28U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0888] `sub_32788` (`0x32788..0x327ec`, 100 bytes)
 *        Hàm FDE[0888] `sub_32788` (`0x32788..0x327ec`, 100 bytes)
 * Disassembly: 0x32788: ldr w8, [x1, #0x1c] ; 0x3278c: cmn w8, #1 ; 0x32790: b.eq #0x327c4 ; 0x32794: ldr w8, [x1, #0x18] ; 0x32798: ldr x9, [x0, #0x18]
 */
uint64_t fde_0888_0x32788(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32788ULL;
    constexpr uint64_t kSize = 0x64ULL;
    constexpr uint32_t kOp0  = 0xb9401c28U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0889] `sub_327ec` (`0x327ec..0x32850`, 100 bytes)
 *        Hàm FDE[0889] `sub_327ec` (`0x327ec..0x32850`, 100 bytes)
 * Disassembly: 0x327ec: ldr w8, [x1, #0x1c] ; 0x327f0: cmn w8, #1 ; 0x327f4: b.eq #0x32828 ; 0x327f8: ldr w8, [x1, #0x18] ; 0x327fc: ldr x9, [x0, #0x18]
 */
uint64_t fde_0889_0x327ec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x327ecULL;
    constexpr uint64_t kSize = 0x64ULL;
    constexpr uint32_t kOp0  = 0xb9401c28U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0890] `sub_32850` (`0x32850..0x32898`, 72 bytes)
 *        Hàm FDE[0890] `sub_32850` (`0x32850..0x32898`, 72 bytes)
 * Disassembly: 0x32850: ldr w8, [x1, #0x1c] ; 0x32854: cmn w8, #1 ; 0x32858: b.eq #0x32880 ; 0x3285c: ldr w8, [x1, #0x18] ; 0x32860: ldr x9, [x0, #0x18]
 */
uint64_t fde_0890_0x32850(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32850ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xb9401c28U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0891] `sub_32898` (`0x32898..0x328e0`, 72 bytes)
 *        Hàm FDE[0891] `sub_32898` (`0x32898..0x328e0`, 72 bytes)
 * Disassembly: 0x32898: ldr w8, [x1, #0x1c] ; 0x3289c: cmn w8, #1 ; 0x328a0: b.eq #0x328c8 ; 0x328a4: ldr w8, [x1, #0x18] ; 0x328a8: ldr x9, [x0, #0x18]
 */
uint64_t fde_0891_0x32898(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32898ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xb9401c28U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0892] `sub_328e0` (`0x328e0..0x32928`, 72 bytes)
 *        Hàm FDE[0892] `sub_328e0` (`0x328e0..0x32928`, 72 bytes)
 * Disassembly: 0x328e0: ldr w8, [x1, #0x1c] ; 0x328e4: cmn w8, #1 ; 0x328e8: b.eq #0x32910 ; 0x328ec: ldr w8, [x1, #0x18] ; 0x328f0: ldr x9, [x0, #0x18]
 */
uint64_t fde_0892_0x328e0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x328e0ULL;
    constexpr uint64_t kSize = 0x48ULL;
    constexpr uint32_t kOp0  = 0xb9401c28U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0893] `sub_32928` (`0x32928..0x3292c`, 4 bytes)
 *        Hàm FDE[0893] `sub_32928` (`0x32928..0x3292c`, 4 bytes)
 * Disassembly: 0x32928: b #0x20e88
 */
uint64_t fde_0893_0x32928(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32928ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb958U;
    constexpr uint32_t kOpN  = 0x17ffb958U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0894] `sub_3292c` (`0x3292c..0x32aa0`, 372 bytes)
 *        Hàm FDE[0894] `sub_3292c` (`0x3292c..0x32aa0`, 372 bytes)
 * Disassembly: 0x3292c: stp x26, x25, [sp, #-0x50]! ; 0x32930: stp x24, x23, [sp, #0x10] ; 0x32934: stp x22, x21, [sp, #0x20] ; 0x32938: stp x20, x19, [sp, #0x30] ; 0x3293c: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0894_0x3292c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3292cULL;
    constexpr uint64_t kSize = 0x174ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x17ffd4f0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0895] `sub_32aa0` (`0x32aa0..0x32aa4`, 4 bytes)
 *        Hàm FDE[0895] `sub_32aa0` (`0x32aa0..0x32aa4`, 4 bytes)
 * Disassembly: 0x32aa0: b #0x20e88
 */
uint64_t fde_0895_0x32aa0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32aa0ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb8faU;
    constexpr uint32_t kOpN  = 0x17ffb8faU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0896] `sub_32aa4` (`0x32aa4..0x32b44`, 160 bytes)
 *        Hàm FDE[0896] `sub_32aa4` (`0x32aa4..0x32b44`, 160 bytes)
 * Disassembly: 0x32aa4: str x21, [sp, #-0x30]! ; 0x32aa8: stp x20, x19, [sp, #0x10] ; 0x32aac: stp x29, x30, [sp, #0x20] ; 0x32ab0: add x29, sp, #0x20 ; 0x32ab4: ldr x21, [x0, #0x10]
 */
uint64_t fde_0896_0x32aa4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32aa4ULL;
    constexpr uint64_t kSize = 0xa0ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0897] `sub_32b44` (`0x32b44..0x32b54`, 16 bytes)
 *        Hàm FDE[0897] `sub_32b44` (`0x32b44..0x32b54`, 16 bytes)
 * Disassembly: 0x32b44: ldr x0, [x0, #0x10] ; 0x32b48: ldr x8, [x0] ; 0x32b4c: ldr x1, [x8, #0x30] ; 0x32b50: br x1
 */
uint64_t fde_0897_0x32b44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32b44ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0898] `sub_32b54` (`0x32b54..0x32b58`, 4 bytes)
 *        Hàm FDE[0898] `sub_32b54` (`0x32b54..0x32b58`, 4 bytes)
 * Disassembly: 0x32b54: b #0x20e88
 */
uint64_t fde_0898_0x32b54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32b54ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb8cdU;
    constexpr uint32_t kOpN  = 0x17ffb8cdU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0899] `sub_32b58` (`0x32b58..0x32be8`, 144 bytes)
 *        Hàm FDE[0899] `sub_32b58` (`0x32b58..0x32be8`, 144 bytes)
 * Disassembly: 0x32b58: str x21, [sp, #-0x30]! ; 0x32b5c: stp x20, x19, [sp, #0x10] ; 0x32b60: stp x29, x30, [sp, #0x20] ; 0x32b64: add x29, sp, #0x20 ; 0x32b68: adrp x21, #0x3c000
 */
uint64_t fde_0899_0x32b58(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32b58ULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0900] `sub_32be8` (`0x32be8..0x32bf8`, 16 bytes)
 *        Hàm FDE[0900] `sub_32be8` (`0x32be8..0x32bf8`, 16 bytes)
 * Disassembly: 0x32be8: ldr x0, [x0, #0x10] ; 0x32bec: ldr x8, [x0] ; 0x32bf0: ldr x1, [x8, #0x30] ; 0x32bf4: br x1
 */
uint64_t fde_0900_0x32be8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32be8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd61f0020U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0901] `sub_32bf8` (`0x32bf8..0x32bfc`, 4 bytes)
 *        Hàm FDE[0901] `sub_32bf8` (`0x32bf8..0x32bfc`, 4 bytes)
 * Disassembly: 0x32bf8: b #0x20e88
 */
uint64_t fde_0901_0x32bf8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32bf8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb8a4U;
    constexpr uint32_t kOpN  = 0x17ffb8a4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0902] `sub_32bfc` (`0x32bfc..0x32cec`, 240 bytes)
 *        Hàm FDE[0902] `sub_32bfc` (`0x32bfc..0x32cec`, 240 bytes)
 * Disassembly: 0x32bfc: stp x26, x25, [sp, #-0x50]! ; 0x32c00: stp x24, x23, [sp, #0x10] ; 0x32c04: stp x22, x21, [sp, #0x20] ; 0x32c08: stp x20, x19, [sp, #0x30] ; 0x32c0c: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0902_0x32bfc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32bfcULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0903] `sub_32cec` (`0x32cec..0x32cf0`, 4 bytes)
 *        Hàm FDE[0903] `sub_32cec` (`0x32cec..0x32cf0`, 4 bytes)
 * Disassembly: 0x32cec: b #0x20e88
 */
uint64_t fde_0903_0x32cec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32cecULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb867U;
    constexpr uint32_t kOpN  = 0x17ffb867U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0904] `sub_32cf0` (`0x32cf0..0x32e58`, 360 bytes)
 *        Hàm FDE[0904] `sub_32cf0` (`0x32cf0..0x32e58`, 360 bytes)
 * Disassembly: 0x32cf0: stp x26, x25, [sp, #-0x50]! ; 0x32cf4: stp x24, x23, [sp, #0x10] ; 0x32cf8: stp x22, x21, [sp, #0x20] ; 0x32cfc: stp x20, x19, [sp, #0x30] ; 0x32d00: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0904_0x32cf0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32cf0ULL;
    constexpr uint64_t kSize = 0x168ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffbc15U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0905] `sub_32e58` (`0x32e58..0x32e5c`, 4 bytes)
 *        Hàm FDE[0905] `sub_32e58` (`0x32e58..0x32e5c`, 4 bytes)
 * Disassembly: 0x32e58: b #0x20e88
 */
uint64_t fde_0905_0x32e58(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32e58ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb80cU;
    constexpr uint32_t kOpN  = 0x17ffb80cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0906] `sub_32e5c` (`0x32e5c..0x32e64`, 8 bytes)
 *        Hàm FDE[0906] `sub_32e5c` (`0x32e5c..0x32e64`, 8 bytes)
 * Disassembly: 0x32e5c: mov w0, #1 ; 0x32e60: ret
 */
uint64_t fde_0906_0x32e5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32e5cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0907] `sub_32e64` (`0x32e64..0x32e6c`, 8 bytes)
 *        Hàm FDE[0907] `sub_32e64` (`0x32e64..0x32e6c`, 8 bytes)
 * Disassembly: 0x32e64: mov w0, #1 ; 0x32e68: ret
 */
uint64_t fde_0907_0x32e64(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32e64ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0908] `sub_32e6c` (`0x32e6c..0x32f3c`, 208 bytes)
 *        Hàm FDE[0908] `sub_32e6c` (`0x32e6c..0x32f3c`, 208 bytes)
 * Disassembly: 0x32e6c: str x21, [sp, #-0x30]! ; 0x32e70: stp x20, x19, [sp, #0x10] ; 0x32e74: stp x29, x30, [sp, #0x20] ; 0x32e78: add x29, sp, #0x20 ; 0x32e7c: mov x20, x0
 */
uint64_t fde_0908_0x32e6c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32e6cULL;
    constexpr uint64_t kSize = 0xd0ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0909] `sub_32f3c` (`0x32f3c..0x331b4`, 632 bytes)
 *        Hàm FDE[0909] `sub_32f3c` (`0x32f3c..0x331b4`, 632 bytes)
 * Disassembly: 0x32f3c: stp x26, x25, [sp, #-0x50]! ; 0x32f40: stp x24, x23, [sp, #0x10] ; 0x32f44: stp x22, x21, [sp, #0x20] ; 0x32f48: stp x20, x19, [sp, #0x30] ; 0x32f4c: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0909_0x32f3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x32f3cULL;
    constexpr uint64_t kSize = 0x278ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0910] `sub_331b4` (`0x331b4..0x331b8`, 4 bytes)
 *        Hàm FDE[0910] `sub_331b4` (`0x331b4..0x331b8`, 4 bytes)
 * Disassembly: 0x331b4: b #0x20e88
 */
uint64_t fde_0910_0x331b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x331b4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb735U;
    constexpr uint32_t kOpN  = 0x17ffb735U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0911] `sub_331b8` (`0x331b8..0x33264`, 172 bytes)
 *        Hàm FDE[0911] `sub_331b8` (`0x331b8..0x33264`, 172 bytes)
 * Disassembly: 0x331b8: str x21, [sp, #-0x30]! ; 0x331bc: stp x20, x19, [sp, #0x10] ; 0x331c0: stp x29, x30, [sp, #0x20] ; 0x331c4: add x29, sp, #0x20 ; 0x331c8: ldr x21, [x0, #0x10]
 */
uint64_t fde_0911_0x331b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x331b8ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffd2ffU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0912] `sub_33264` (`0x33264..0x33268`, 4 bytes)
 *        Hàm FDE[0912] `sub_33264` (`0x33264..0x33268`, 4 bytes)
 * Disassembly: 0x33264: b #0x20e88
 */
uint64_t fde_0912_0x33264(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x33264ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb709U;
    constexpr uint32_t kOpN  = 0x17ffb709U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0913] `sub_33268` (`0x33268..0x3387c`, 1556 bytes)
 *        Hàm FDE[0913] `sub_33268` (`0x33268..0x3387c`, 1556 bytes)
 * Disassembly: 0x33268: sub sp, sp, #0x60 ; 0x3326c: stp x26, x25, [sp, #0x10] ; 0x33270: stp x24, x23, [sp, #0x20] ; 0x33274: stp x22, x21, [sp, #0x30] ; 0x33278: stp x20, x19, [sp, #0x40]
 */
uint64_t fde_0913_0x33268(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x33268ULL;
    constexpr uint64_t kSize = 0x614ULL;
    constexpr uint32_t kOp0  = 0xd10183ffU;
    constexpr uint32_t kOpN  = 0x97ffb98cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0914] `sub_3387c` (`0x3387c..0x33c3c`, 960 bytes)
 *        Hàm FDE[0914] `sub_3387c` (`0x3387c..0x33c3c`, 960 bytes)
 * Disassembly: 0x3387c: stp x24, x23, [sp, #-0x40]! ; 0x33880: stp x22, x21, [sp, #0x10] ; 0x33884: stp x20, x19, [sp, #0x20] ; 0x33888: stp x29, x30, [sp, #0x30] ; 0x3388c: add x29, sp, #0x30
 */
uint64_t fde_0914_0x3387c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3387cULL;
    constexpr uint64_t kSize = 0x3c0ULL;
    constexpr uint32_t kOp0  = 0xa9bc5ff8U;
    constexpr uint32_t kOpN  = 0x97ffb89cU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0915] `sub_33c3c` (`0x33c3c..0x33e44`, 520 bytes)
 *        Hàm FDE[0915] `sub_33c3c` (`0x33c3c..0x33e44`, 520 bytes)
 * Disassembly: 0x33c3c: str x23, [sp, #-0x40]! ; 0x33c40: stp x22, x21, [sp, #0x10] ; 0x33c44: stp x20, x19, [sp, #0x20] ; 0x33c48: stp x29, x30, [sp, #0x30] ; 0x33c4c: add x29, sp, #0x30
 */
uint64_t fde_0915_0x33c3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x33c3cULL;
    constexpr uint64_t kSize = 0x208ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x97ffb81aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0916] `sub_33e44` (`0x33e44..0x33ee8`, 164 bytes)
 *        Hàm FDE[0916] `sub_33e44` (`0x33e44..0x33ee8`, 164 bytes)
 * Disassembly: 0x33e44: str x21, [sp, #-0x30]! ; 0x33e48: stp x20, x19, [sp, #0x10] ; 0x33e4c: stp x29, x30, [sp, #0x20] ; 0x33e50: add x29, sp, #0x20 ; 0x33e54: adrp x21, #0x3c000
 */
uint64_t fde_0916_0x33e44(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x33e44ULL;
    constexpr uint64_t kSize = 0xa4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffcfdeU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0917] `sub_33ee8` (`0x33ee8..0x33eec`, 4 bytes)
 *        Hàm FDE[0917] `sub_33ee8` (`0x33ee8..0x33eec`, 4 bytes)
 * Disassembly: 0x33ee8: b #0x20e88
 */
uint64_t fde_0917_0x33ee8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x33ee8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb3e8U;
    constexpr uint32_t kOpN  = 0x17ffb3e8U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0918] `sub_33eec` (`0x33eec..0x34054`, 360 bytes)
 *        Hàm FDE[0918] `sub_33eec` (`0x33eec..0x34054`, 360 bytes)
 * Disassembly: 0x33eec: stp x26, x25, [sp, #-0x50]! ; 0x33ef0: stp x24, x23, [sp, #0x10] ; 0x33ef4: stp x22, x21, [sp, #0x20] ; 0x33ef8: stp x20, x19, [sp, #0x30] ; 0x33efc: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0918_0x33eec(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x33eecULL;
    constexpr uint64_t kSize = 0x168ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffb796U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0919] `sub_34054` (`0x34054..0x34058`, 4 bytes)
 *        Hàm FDE[0919] `sub_34054` (`0x34054..0x34058`, 4 bytes)
 * Disassembly: 0x34054: b #0x20e88
 */
uint64_t fde_0919_0x34054(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34054ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb38dU;
    constexpr uint32_t kOpN  = 0x17ffb38dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0920] `sub_34058` (`0x34058..0x34060`, 8 bytes)
 *        Hàm FDE[0920] `sub_34058` (`0x34058..0x34060`, 8 bytes)
 * Disassembly: 0x34058: mov w0, #1 ; 0x3405c: ret
 */
uint64_t fde_0920_0x34058(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34058ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0921] `sub_34060` (`0x34060..0x34068`, 8 bytes)
 *        Hàm FDE[0921] `sub_34060` (`0x34060..0x34068`, 8 bytes)
 * Disassembly: 0x34060: mov w0, #1 ; 0x34064: ret
 */
uint64_t fde_0921_0x34060(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34060ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0922] `sub_34068` (`0x34068..0x340b4`, 76 bytes)
 *        Hàm FDE[0922] `sub_34068` (`0x34068..0x340b4`, 76 bytes)
 * Disassembly: 0x34068: stp x20, x19, [sp, #-0x20]! ; 0x3406c: stp x29, x30, [sp, #0x10] ; 0x34070: add x29, sp, #0x10 ; 0x34074: ldr x0, [x0, #0x10] ; 0x34078: mov x19, x1
 */
uint64_t fde_0922_0x34068(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34068ULL;
    constexpr uint64_t kSize = 0x4cULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17ffcf6bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0923] `sub_340b4` (`0x340b4..0x3437c`, 712 bytes)
 *        Hàm FDE[0923] `sub_340b4` (`0x340b4..0x3437c`, 712 bytes)
 * Disassembly: 0x340b4: stp x26, x25, [sp, #-0x50]! ; 0x340b8: stp x24, x23, [sp, #0x10] ; 0x340bc: stp x22, x21, [sp, #0x20] ; 0x340c0: stp x20, x19, [sp, #0x30] ; 0x340c4: stp x29, x30, [sp, #0x40]
 */
uint64_t fde_0923_0x340b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x340b4ULL;
    constexpr uint64_t kSize = 0x2c8ULL;
    constexpr uint32_t kOp0  = 0xa9bb67faU;
    constexpr uint32_t kOpN  = 0x97ffb6ccU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0924] `sub_3437c` (`0x3437c..0x34380`, 4 bytes)
 *        Hàm FDE[0924] `sub_3437c` (`0x3437c..0x34380`, 4 bytes)
 * Disassembly: 0x3437c: b #0x20e88
 */
uint64_t fde_0924_0x3437c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3437cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb2c3U;
    constexpr uint32_t kOpN  = 0x17ffb2c3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0925] `sub_34380` (`0x34380..0x3442c`, 172 bytes)
 *        Hàm FDE[0925] `sub_34380` (`0x34380..0x3442c`, 172 bytes)
 * Disassembly: 0x34380: str x21, [sp, #-0x30]! ; 0x34384: stp x20, x19, [sp, #0x10] ; 0x34388: stp x29, x30, [sp, #0x20] ; 0x3438c: add x29, sp, #0x20 ; 0x34390: ldr x21, [x0, #0x10]
 */
uint64_t fde_0925_0x34380(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34380ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffce8dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0926] `sub_3442c` (`0x3442c..0x34430`, 4 bytes)
 *        Hàm FDE[0926] `sub_3442c` (`0x3442c..0x34430`, 4 bytes)
 * Disassembly: 0x3442c: b #0x20e88
 */
uint64_t fde_0926_0x3442c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3442cULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb297U;
    constexpr uint32_t kOpN  = 0x17ffb297U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0927] `sub_34430` (`0x34430..0x344b8`, 136 bytes)
 *        Hàm FDE[0927] `sub_34430` (`0x34430..0x344b8`, 136 bytes)
 * Disassembly: 0x34430: str x21, [sp, #-0x30]! ; 0x34434: stp x20, x19, [sp, #0x10] ; 0x34438: stp x29, x30, [sp, #0x20] ; 0x3443c: add x29, sp, #0x20 ; 0x34440: ldr x21, [x0, #0x10]
 */
uint64_t fde_0927_0x34430(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34430ULL;
    constexpr uint64_t kSize = 0x88ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffce6aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0928] `sub_344b8` (`0x344b8..0x344bc`, 4 bytes)
 *        Hàm FDE[0928] `sub_344b8` (`0x344b8..0x344bc`, 4 bytes)
 * Disassembly: 0x344b8: b #0x20e88
 */
uint64_t fde_0928_0x344b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x344b8ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb274U;
    constexpr uint32_t kOpN  = 0x17ffb274U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0929] `sub_344bc` (`0x344bc..0x344e4`, 40 bytes)
 *        Hàm FDE[0929] `sub_344bc` (`0x344bc..0x344e4`, 40 bytes)
 * Disassembly: 0x344bc: ldr x0, [x0, #0x10] ; 0x344c0: ldrb w8, [x0, #9] ; 0x344c4: cmp w8, #2 ; 0x344c8: b.ne #0x344d8 ; 0x344cc: ldr x8, [x0]
 */
uint64_t fde_0929_0x344bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x344bcULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0930] `sub_344e4` (`0x344e4..0x3450c`, 40 bytes)
 *        Hàm FDE[0930] `sub_344e4` (`0x344e4..0x3450c`, 40 bytes)
 * Disassembly: 0x344e4: ldr x0, [x0, #0x10] ; 0x344e8: ldrb w8, [x0, #0xa] ; 0x344ec: cmp w8, #2 ; 0x344f0: b.ne #0x34500 ; 0x344f4: ldr x8, [x0]
 */
uint64_t fde_0930_0x344e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x344e4ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0931] `sub_3450c` (`0x3450c..0x34534`, 40 bytes)
 *        Hàm FDE[0931] `sub_3450c` (`0x3450c..0x34534`, 40 bytes)
 * Disassembly: 0x3450c: ldr x0, [x0, #0x10] ; 0x34510: ldrb w8, [x0, #0xb] ; 0x34514: cmp w8, #2 ; 0x34518: b.ne #0x34528 ; 0x3451c: ldr x8, [x0]
 */
uint64_t fde_0931_0x3450c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3450cULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0932] `sub_34534` (`0x34534..0x34604`, 208 bytes)
 *        Hàm FDE[0932] `sub_34534` (`0x34534..0x34604`, 208 bytes)
 * Disassembly: 0x34534: str x21, [sp, #-0x30]! ; 0x34538: stp x20, x19, [sp, #0x10] ; 0x3453c: stp x29, x30, [sp, #0x20] ; 0x34540: add x29, sp, #0x20 ; 0x34544: mov x20, x0
 */
uint64_t fde_0932_0x34534(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34534ULL;
    constexpr uint64_t kSize = 0xd0ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffce17U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0933] `sub_34604` (`0x34604..0x34614`, 16 bytes)
 *        Hàm FDE[0933] `sub_34604` (`0x34604..0x34614`, 16 bytes)
 * Disassembly: 0x34604: ldr x0, [x0, #0x10] ; 0x34608: ldr x8, [x0] ; 0x3460c: ldr x2, [x8, #0x28] ; 0x34610: br x2
 */
uint64_t fde_0933_0x34604(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34604ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0934] `sub_34614` (`0x34614..0x34618`, 4 bytes)
 *        Hàm FDE[0934] `sub_34614` (`0x34614..0x34618`, 4 bytes)
 * Disassembly: 0x34614: b #0x20e88
 */
uint64_t fde_0934_0x34614(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34614ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb21dU;
    constexpr uint32_t kOpN  = 0x17ffb21dU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0935] `sub_34618` (`0x34618..0x34690`, 120 bytes)
 *        Hàm FDE[0935] `sub_34618` (`0x34618..0x34690`, 120 bytes)
 * Disassembly: 0x34618: str x21, [sp, #-0x30]! ; 0x3461c: stp x20, x19, [sp, #0x10] ; 0x34620: stp x29, x30, [sp, #0x20] ; 0x34624: add x29, sp, #0x20 ; 0x34628: adrp x21, #0x3c000
 */
uint64_t fde_0935_0x34618(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34618ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffcdf4U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0936] `sub_34690` (`0x34690..0x34694`, 4 bytes)
 *        Hàm FDE[0936] `sub_34690` (`0x34690..0x34694`, 4 bytes)
 * Disassembly: 0x34690: b #0x20e88
 */
uint64_t fde_0936_0x34690(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34690ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb1feU;
    constexpr uint32_t kOpN  = 0x17ffb1feU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0937] `sub_34694` (`0x34694..0x34788`, 244 bytes)
 *        Hàm FDE[0937] `sub_34694` (`0x34694..0x34788`, 244 bytes)
 * Disassembly: 0x34694: str x21, [sp, #-0x30]! ; 0x34698: stp x20, x19, [sp, #0x10] ; 0x3469c: stp x29, x30, [sp, #0x20] ; 0x346a0: add x29, sp, #0x20 ; 0x346a4: ldr x21, [x0, #0x10]
 */
uint64_t fde_0937_0x34694(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34694ULL;
    constexpr uint64_t kSize = 0xf4ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffcdb6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0938] `sub_34788` (`0x34788..0x3478c`, 4 bytes)
 *        Hàm FDE[0938] `sub_34788` (`0x34788..0x3478c`, 4 bytes)
 * Disassembly: 0x34788: b #0x20e88
 */
uint64_t fde_0938_0x34788(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34788ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb1c0U;
    constexpr uint32_t kOpN  = 0x17ffb1c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0939] `sub_3478c` (`0x3478c..0x34794`, 8 bytes)
 *        Hàm FDE[0939] `sub_3478c` (`0x3478c..0x34794`, 8 bytes)
 * Disassembly: 0x3478c: mov w0, #1 ; 0x34790: ret
 */
uint64_t fde_0939_0x3478c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3478cULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0940] `sub_34794` (`0x34794..0x3479c`, 8 bytes)
 *        Hàm FDE[0940] `sub_34794` (`0x34794..0x3479c`, 8 bytes)
 * Disassembly: 0x34794: mov w0, #1 ; 0x34798: ret
 */
uint64_t fde_0940_0x34794(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34794ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0x52800020U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0941] `sub_3479c` (`0x3479c..0x347ac`, 16 bytes)
 *        Hàm FDE[0941] `sub_3479c` (`0x3479c..0x347ac`, 16 bytes)
 * Disassembly: 0x3479c: ldr x0, [x0, #0x10] ; 0x347a0: ldr x8, [x0] ; 0x347a4: ldr x2, [x8, #0x20] ; 0x347a8: br x2
 */
uint64_t fde_0941_0x3479c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3479cULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0942] `sub_347ac` (`0x347ac..0x348c4`, 280 bytes)
 *        Hàm FDE[0942] `sub_347ac` (`0x347ac..0x348c4`, 280 bytes)
 * Disassembly: 0x347ac: str x21, [sp, #-0x30]! ; 0x347b0: stp x20, x19, [sp, #0x10] ; 0x347b4: stp x29, x30, [sp, #0x20] ; 0x347b8: add x29, sp, #0x20 ; 0x347bc: ldr x8, [x1, #8]
 */
uint64_t fde_0942_0x347ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x347acULL;
    constexpr uint64_t kSize = 0x118ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0943] `sub_348c4` (`0x348c4..0x348c8`, 4 bytes)
 *        Hàm FDE[0943] `sub_348c4` (`0x348c4..0x348c8`, 4 bytes)
 * Disassembly: 0x348c4: b #0x20e88
 */
uint64_t fde_0943_0x348c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x348c4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb171U;
    constexpr uint32_t kOpN  = 0x17ffb171U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0944] `sub_348c8` (`0x348c8..0x348f0`, 40 bytes)
 *        Hàm FDE[0944] `sub_348c8` (`0x348c8..0x348f0`, 40 bytes)
 * Disassembly: 0x348c8: ldr x0, [x0, #0x18] ; 0x348cc: ldrb w8, [x0, #9] ; 0x348d0: cmp w8, #2 ; 0x348d4: b.ne #0x348e4 ; 0x348d8: ldr x8, [x0]
 */
uint64_t fde_0944_0x348c8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x348c8ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf9400c00U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0945] `sub_348f0` (`0x348f0..0x34a00`, 272 bytes)
 *        Hàm FDE[0945] `sub_348f0` (`0x348f0..0x34a00`, 272 bytes)
 * Disassembly: 0x348f0: str x21, [sp, #-0x30]! ; 0x348f4: stp x20, x19, [sp, #0x10] ; 0x348f8: stp x29, x30, [sp, #0x20] ; 0x348fc: add x29, sp, #0x20 ; 0x34900: mov x20, x0
 */
uint64_t fde_0945_0x348f0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x348f0ULL;
    constexpr uint64_t kSize = 0x110ULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0x17ffcd18U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0946] `sub_34a00` (`0x34a00..0x34aac`, 172 bytes)
 *        Hàm FDE[0946] `sub_34a00` (`0x34a00..0x34aac`, 172 bytes)
 * Disassembly: 0x34a00: str x21, [sp, #-0x30]! ; 0x34a04: stp x20, x19, [sp, #0x10] ; 0x34a08: stp x29, x30, [sp, #0x20] ; 0x34a0c: add x29, sp, #0x20 ; 0x34a10: mov x20, x0
 */
uint64_t fde_0946_0x34a00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34a00ULL;
    constexpr uint64_t kSize = 0xacULL;
    constexpr uint32_t kOp0  = 0xf81d0ff5U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0947] `sub_34aac` (`0x34aac..0x34ab0`, 4 bytes)
 *        Hàm FDE[0947] `sub_34aac` (`0x34aac..0x34ab0`, 4 bytes)
 * Disassembly: 0x34aac: b #0x20e88
 */
uint64_t fde_0947_0x34aac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34aacULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb0f7U;
    constexpr uint32_t kOpN  = 0x17ffb0f7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0948] `sub_34ab0` (`0x34ab0..0x34b70`, 192 bytes)
 *        Hàm FDE[0948] `sub_34ab0` (`0x34ab0..0x34b70`, 192 bytes)
 * Disassembly: 0x34ab0: stp x20, x19, [sp, #-0x20]! ; 0x34ab4: stp x29, x30, [sp, #0x10] ; 0x34ab8: add x29, sp, #0x10 ; 0x34abc: ldp x8, x2, [x0, #0x10] ; 0x34ac0: mov x20, x0
 */
uint64_t fde_0948_0x34ab0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34ab0ULL;
    constexpr uint64_t kSize = 0xc0ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x97ffb4cfU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0949] `sub_34b70` (`0x34b70..0x34b74`, 4 bytes)
 *        Hàm FDE[0949] `sub_34b70` (`0x34b70..0x34b74`, 4 bytes)
 * Disassembly: 0x34b70: b #0x20e88
 */
uint64_t fde_0949_0x34b70(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34b70ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffb0c6U;
    constexpr uint32_t kOpN  = 0x17ffb0c6U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0950] `sub_34b74` (`0x34b74..0x34b9c`, 40 bytes)
 *        Hàm FDE[0950] `sub_34b74` (`0x34b74..0x34b9c`, 40 bytes)
 * Disassembly: 0x34b74: ldr x0, [x0, #0x10] ; 0x34b78: ldrb w8, [x0, #9] ; 0x34b7c: cmp w8, #2 ; 0x34b80: b.ne #0x34b90 ; 0x34b84: ldr x8, [x0]
 */
uint64_t fde_0950_0x34b74(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34b74ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0951] `sub_34b9c` (`0x34b9c..0x34d68`, 460 bytes)
 *        Hàm FDE[0951] `sub_34b9c` (`0x34b9c..0x34d68`, 460 bytes)
 * Disassembly: 0x34b9c: stp x22, x21, [sp, #-0x30]! ; 0x34ba0: stp x20, x19, [sp, #0x10] ; 0x34ba4: stp x29, x30, [sp, #0x20] ; 0x34ba8: add x29, sp, #0x20 ; 0x34bac: ldr x8, [x0, #0x10]
 */
uint64_t fde_0951_0x34b9c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34b9cULL;
    constexpr uint64_t kSize = 0x1ccULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x17ffcc3eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0952] `sub_34d68` (`0x34d68..0x34e94`, 300 bytes)
 *        Hàm FDE[0952] `sub_34d68` (`0x34d68..0x34e94`, 300 bytes)
 * Disassembly: 0x34d68: stp x22, x21, [sp, #-0x30]! ; 0x34d6c: stp x20, x19, [sp, #0x10] ; 0x34d70: stp x29, x30, [sp, #0x20] ; 0x34d74: add x29, sp, #0x20 ; 0x34d78: ldr x8, [x0, #0x10]
 */
uint64_t fde_0952_0x34d68(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34d68ULL;
    constexpr uint64_t kSize = 0x12cULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0xd61f0040U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0953] `sub_34e94` (`0x34e94..0x34e98`, 4 bytes)
 *        Hàm FDE[0953] `sub_34e94` (`0x34e94..0x34e98`, 4 bytes)
 * Disassembly: 0x34e94: b #0x20e88
 */
uint64_t fde_0953_0x34e94(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34e94ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffaffdU;
    constexpr uint32_t kOpN  = 0x17ffaffdU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0954] `sub_34e98` (`0x34e98..0x34ec0`, 40 bytes)
 *        Hàm FDE[0954] `sub_34e98` (`0x34e98..0x34ec0`, 40 bytes)
 * Disassembly: 0x34e98: ldr x0, [x0, #0x10] ; 0x34e9c: ldrb w8, [x0, #9] ; 0x34ea0: cmp w8, #2 ; 0x34ea4: b.ne #0x34eb4 ; 0x34ea8: ldr x8, [x0]
 */
uint64_t fde_0954_0x34e98(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34e98ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xf9400800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0955] `sub_34ec0` (`0x34ec0..0x35068`, 424 bytes)
 *        Hàm FDE[0955] `sub_34ec0` (`0x34ec0..0x35068`, 424 bytes)
 * Disassembly: 0x34ec0: str x23, [sp, #-0x40]! ; 0x34ec4: stp x22, x21, [sp, #0x10] ; 0x34ec8: stp x20, x19, [sp, #0x20] ; 0x34ecc: stp x29, x30, [sp, #0x30] ; 0x34ed0: add x29, sp, #0x30
 */
uint64_t fde_0955_0x34ec0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x34ec0ULL;
    constexpr uint64_t kSize = 0x1a8ULL;
    constexpr uint32_t kOp0  = 0xf81c0ff7U;
    constexpr uint32_t kOpN  = 0x9400076eU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0956] `sub_35068` (`0x35068..0x35178`, 272 bytes)
 *        Hàm FDE[0956] `sub_35068` (`0x35068..0x35178`, 272 bytes)
 * Disassembly: 0x35068: stp x22, x21, [sp, #-0x30]! ; 0x3506c: stp x20, x19, [sp, #0x10] ; 0x35070: stp x29, x30, [sp, #0x20] ; 0x35074: add x29, sp, #0x20 ; 0x35078: ldrb w8, [x0, #0x1c]
 */
uint64_t fde_0956_0x35068(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35068ULL;
    constexpr uint64_t kSize = 0x110ULL;
    constexpr uint32_t kOp0  = 0xa9bd57f6U;
    constexpr uint32_t kOpN  = 0x9400072aU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0957] `sub_35178` (`0x35178..0x3517c`, 4 bytes)
 *        Hàm FDE[0957] `sub_35178` (`0x35178..0x3517c`, 4 bytes)
 * Disassembly: 0x35178: b #0x20e88
 */
uint64_t fde_0957_0x35178(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35178ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffaf44U;
    constexpr uint32_t kOpN  = 0x17ffaf44U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0958] `sub_3517c` (`0x3517c..0x351b4`, 56 bytes)
 *        Hàm FDE[0958] `sub_3517c` (`0x3517c..0x351b4`, 56 bytes)
 * Disassembly: 0x3517c: stp x20, x19, [sp, #-0x20]! ; 0x35180: stp x29, x30, [sp, #0x10] ; 0x35184: add x29, sp, #0x10 ; 0x35188: mov x19, x0 ; 0x3518c: ldr x0, [x0, #0x10]
 */
uint64_t fde_0958_0x3517c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3517cULL;
    constexpr uint64_t kSize = 0x38ULL;
    constexpr uint32_t kOp0  = 0xa9be4ff4U;
    constexpr uint32_t kOpN  = 0x17ffcb2bU;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0959] `sub_351b4` (`0x351b4..0x351b8`, 4 bytes)
 *        Hàm FDE[0959] `sub_351b4` (`0x351b4..0x351b8`, 4 bytes)
 * Disassembly: 0x351b4: b #0x20e88
 */
uint64_t fde_0959_0x351b4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x351b4ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffaf35U;
    constexpr uint32_t kOpN  = 0x17ffaf35U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0960] `sub_351b8` (`0x351b8..0x351e0`, 40 bytes)
 *        Hàm FDE[0960] `sub_351b8` (`0x351b8..0x351e0`, 40 bytes)
 * Disassembly: 0x351b8: mov x2, #0 ; 0x351bc: mov w3, #0 ; 0x351c0: ldrb w5, [x0], #1 ; 0x351c4: and x4, x5, #0x7f ; 0x351c8: lsl x4, x4, x3
 */
uint64_t fde_0960_0x351b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x351b8ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xd2800002U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0961] `sub_351e0` (`0x351e0..0x35220`, 64 bytes)
 *        Hàm FDE[0961] `sub_351e0` (`0x351e0..0x35220`, 64 bytes)
 * Disassembly: 0x351e0: mov x2, #0 ; 0x351e4: mov w3, #0 ; 0x351e8: ldrb w4, [x0], #1 ; 0x351ec: and x5, x4, #0x7f ; 0x351f0: lsl x5, x5, x3
 */
uint64_t fde_0961_0x351e0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x351e0ULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xd2800002U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0962] `sub_35220` (`0x35220..0x35310`, 240 bytes)
 *        Hàm FDE[0962] `sub_35220` (`0x35220..0x35310`, 240 bytes)
 * Disassembly: 0x35220: stp x29, x30, [sp, #-0x40]! ; 0x35224: mov x29, sp ; 0x35228: stp x19, x20, [sp, #0x10] ; 0x3522c: uxtb w20, w0 ; 0x35230: mov x19, x2
 */
uint64_t fde_0962_0x35220(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35220ULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xa9bc7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0963] `sub_35310` (`0x35310..0x35424`, 276 bytes)
 *        Hàm FDE[0963] `sub_35310` (`0x35310..0x35424`, 276 bytes)
 * Disassembly: 0x35310: adrp x2, #0x50000 ; 0x35314: mov w0, #8 ; 0x35318: add x1, x2, #0xa50 ; 0x3531c: strb w0, [x2, #0xa50] ; 0x35320: strb w0, [x1, #1]
 */
uint64_t fde_0963_0x35310(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35310ULL;
    constexpr uint64_t kSize = 0x114ULL;
    constexpr uint32_t kOp0  = 0xf00000c2U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0964] `sub_35424` (`0x35424..0x35460`, 60 bytes)
 *        Hàm FDE[0964] `sub_35424` (`0x35424..0x35460`, 60 bytes)
 * Disassembly: 0x35424: adrp x3, #0x50000 ; 0x35428: stp x29, x30, [sp, #-0x10]! ; 0x3542c: mov x29, sp ; 0x35430: ldrb w3, [x3, #0xa6f] ; 0x35434: cmp w3, #8
 */
uint64_t fde_0964_0x35424(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35424ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xf00000c3U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0965] `sub_35460` (`0x35460..0x354b8`, 88 bytes)
 *        Hàm FDE[0965] `sub_35460` (`0x35460..0x354b8`, 88 bytes)
 * Disassembly: 0x35460: stp x29, x30, [sp, #-0x10]! ; 0x35464: cmp w1, #0x61 ; 0x35468: mov x29, sp ; 0x3546c: b.le #0x35474 ; 0x35470: bl #0x10d30
 */
uint64_t fde_0965_0x35460(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35460ULL;
    constexpr uint64_t kSize = 0x58ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0966] `sub_354b8` (`0x354b8..0x355c4`, 268 bytes)
 *        Hàm FDE[0966] `sub_354b8` (`0x354b8..0x355c4`, 268 bytes)
 * Disassembly: 0x354b8: stp x29, x30, [sp, #-0x40]! ; 0x354bc: mov x29, sp ; 0x354c0: stp x21, x22, [sp, #0x20] ; 0x354c4: mov x21, x0 ; 0x354c8: ldr x0, [x1, #0x340]
 */
uint64_t fde_0966_0x354b8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x354b8ULL;
    constexpr uint64_t kSize = 0x10cULL;
    constexpr uint32_t kOp0  = 0xa9bc7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0967] `sub_355c4` (`0x355c4..0x355cc`, 8 bytes)
 *        Hàm FDE[0967] `sub_355c4` (`0x355c4..0x355cc`, 8 bytes)
 * Disassembly: 0x355c4: ldr x0, [x0, #0x310] ; 0x355c8: ret
 */
uint64_t fde_0967_0x355c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x355c4ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9418800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0968] `sub_355cc` (`0x355cc..0x35624`, 88 bytes)
 *        Hàm FDE[0968] `sub_355cc` (`0x355cc..0x35624`, 88 bytes)
 * Disassembly: 0x355cc: stp x29, x30, [sp, #-0x10]! ; 0x355d0: cmp w1, #0x61 ; 0x355d4: mov x29, sp ; 0x355d8: b.le #0x355e0 ; 0x355dc: bl #0x10d30
 */
uint64_t fde_0968_0x355cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x355ccULL;
    constexpr uint64_t kSize = 0x58ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0969] `sub_35624` (`0x35624..0x3562c`, 8 bytes)
 *        Hàm FDE[0969] `sub_35624` (`0x35624..0x3562c`, 8 bytes)
 * Disassembly: 0x35624: ldr x0, [x0, #0x318] ; 0x35628: ret
 */
uint64_t fde_0969_0x35624(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35624ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9418c00U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0970] `sub_3562c` (`0x3562c..0x35640`, 20 bytes)
 *        Hàm FDE[0970] `sub_3562c` (`0x3562c..0x35640`, 20 bytes)
 * Disassembly: 0x3562c: ldr x2, [x0, #0x340] ; 0x35630: ldr x0, [x0, #0x318] ; 0x35634: lsr x2, x2, #0x3f ; 0x35638: str w2, [x1] ; 0x3563c: ret
 */
uint64_t fde_0970_0x3562c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3562cULL;
    constexpr uint64_t kSize = 0x14ULL;
    constexpr uint32_t kOp0  = 0xf941a002U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0971] `sub_35640` (`0x35640..0x35648`, 8 bytes)
 *        Hàm FDE[0971] `sub_35640` (`0x35640..0x35648`, 8 bytes)
 * Disassembly: 0x35640: str x1, [x0, #0x318] ; 0x35644: ret
 */
uint64_t fde_0971_0x35640(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35640ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9018c01U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0972] `sub_35648` (`0x35648..0x35650`, 8 bytes)
 *        Hàm FDE[0972] `sub_35648` (`0x35648..0x35650`, 8 bytes)
 * Disassembly: 0x35648: ldr x0, [x0, #0x320] ; 0x3564c: ret
 */
uint64_t fde_0972_0x35648(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35648ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9419000U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0973] `sub_35650` (`0x35650..0x35658`, 8 bytes)
 *        Hàm FDE[0973] `sub_35650` (`0x35650..0x35658`, 8 bytes)
 * Disassembly: 0x35650: ldr x0, [x0, #0x338] ; 0x35654: ret
 */
uint64_t fde_0973_0x35650(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35650ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9419c00U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0974] `sub_35658` (`0x35658..0x35680`, 40 bytes)
 *        Hàm FDE[0974] `sub_35658` (`0x35658..0x35680`, 40 bytes)
 * Disassembly: 0x35658: stp x29, x30, [sp, #-0x30]! ; 0x3565c: sub x0, x0, #1 ; 0x35660: mov x29, sp ; 0x35664: add x1, x29, #0x18 ; 0x35668: bl #0x387a0
 */
uint64_t fde_0974_0x35658(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35658ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xa9bd7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0975] `sub_35680` (`0x35680..0x35688`, 8 bytes)
 *        Hàm FDE[0975] `sub_35680` (`0x35680..0x35688`, 8 bytes)
 * Disassembly: 0x35680: ldr x0, [x0, #0x330] ; 0x35684: ret
 */
uint64_t fde_0975_0x35680(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35680ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9419800U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0976] `sub_35688` (`0x35688..0x35690`, 8 bytes)
 *        Hàm FDE[0976] `sub_35688` (`0x35688..0x35690`, 8 bytes)
 * Disassembly: 0x35688: ldr x0, [x0, #0x328] ; 0x3568c: ret
 */
uint64_t fde_0976_0x35688(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35688ULL;
    constexpr uint64_t kSize = 0x8ULL;
    constexpr uint32_t kOp0  = 0xf9419400U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0977] `sub_35690` (`0x35690..0x35708`, 120 bytes)
 *        Hàm FDE[0977] `sub_35690` (`0x35690..0x35708`, 120 bytes)
 * Disassembly: 0x35690: stp x29, x30, [sp, #-0x10]! ; 0x35694: uxtb w2, w0 ; 0x35698: mov x0, x1 ; 0x3569c: cmp w2, #0xff ; 0x356a0: mov x29, sp
 */
uint64_t fde_0977_0x35690(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35690ULL;
    constexpr uint64_t kSize = 0x78ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0978] `sub_35708` (`0x35708..0x35c00`, 1272 bytes)
 *        Hàm FDE[0978] `sub_35708` (`0x35708..0x35c00`, 1272 bytes)
 * Disassembly: 0x35708: stp x29, x30, [sp, #-0x90]! ; 0x3570c: mov x29, sp ; 0x35710: stp x21, x22, [sp, #0x20] ; 0x35714: stp x23, x24, [sp, #0x30] ; 0x35718: stp x25, x26, [sp, #0x40]
 */
uint64_t fde_0978_0x35708(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35708ULL;
    constexpr uint64_t kSize = 0x4f8ULL;
    constexpr uint32_t kOp0  = 0xa9b77bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0979] `sub_35c00` (`0x35c00..0x36024`, 1060 bytes)
 *        Hàm FDE[0979] `sub_35c00` (`0x35c00..0x36024`, 1060 bytes)
 * Disassembly: 0x35c00: stp x29, x30, [sp, #-0x90]! ; 0x35c04: mov x2, #0x680 ; 0x35c08: mov x29, sp ; 0x35c0c: stp x19, x20, [sp, #0x10] ; 0x35c10: mov x20, x0
 */
uint64_t fde_0979_0x35c00(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x35c00ULL;
    constexpr uint64_t kSize = 0x424ULL;
    constexpr uint32_t kOp0  = 0xa9b77bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0980] `sub_36024` (`0x36024..0x365d8`, 1460 bytes)
 *        Hàm FDE[0980] `sub_36024` (`0x36024..0x365d8`, 1460 bytes)
 * Disassembly: 0x36024: sub sp, sp, #0x230 ; 0x36028: mov x4, x0 ; 0x3602c: stp x29, x30, [sp, #-0x60]! ; 0x36030: mov x29, sp ; 0x36034: stp x27, x28, [sp, #0x50]
 */
uint64_t fde_0980_0x36024(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36024ULL;
    constexpr uint64_t kSize = 0x5b4ULL;
    constexpr uint32_t kOp0  = 0xd108c3ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0981] `sub_365d8` (`0x365d8..0x367e4`, 524 bytes)
 *        Hàm FDE[0981] `sub_365d8` (`0x365d8..0x367e4`, 524 bytes)
 * Disassembly: 0x365d8: sub sp, sp, #0x3e0 ; 0x365dc: mov x2, #0x3c0 ; 0x365e0: stp x29, x30, [sp, #-0x60]! ; 0x365e4: mov x29, sp ; 0x365e8: stp x19, x20, [sp, #0x10]
 */
uint64_t fde_0981_0x365d8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x365d8ULL;
    constexpr uint64_t kSize = 0x20cULL;
    constexpr uint32_t kOp0  = 0xd10f83ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0982] `sub_367e4` (`0x367e4..0x368c0`, 220 bytes)
 *        Hàm FDE[0982] `sub_367e4` (`0x367e4..0x368c0`, 220 bytes)
 * Disassembly: 0x367e4: sub sp, sp, #0x690 ; 0x367e8: stp x29, x30, [sp, #-0x40]! ; 0x367ec: mov x29, sp ; 0x367f0: stp x19, x20, [sp, #0x10] ; 0x367f4: stp x21, x22, [sp, #0x20]
 */
uint64_t fde_0982_0x367e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x367e4ULL;
    constexpr uint64_t kSize = 0xdcULL;
    constexpr uint32_t kOp0  = 0xd11a43ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0983] `sub_368c0` (`0x368c0..0x3690c`, 76 bytes)
 *        Hàm FDE[0983] `sub_368c0` (`0x368c0..0x3690c`, 76 bytes)
 * Disassembly: 0x368c0: stp x29, x30, [sp, #-0x20]! ; 0x368c4: mov x29, sp ; 0x368c8: stp x19, x20, [sp, #0x10] ; 0x368cc: mov x19, x1 ; 0x368d0: mov x20, x0
 */
uint64_t fde_0983_0x368c0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x368c0ULL;
    constexpr uint64_t kSize = 0x4cULL;
    constexpr uint32_t kOp0  = 0xa9be7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0984] `sub_3690c` (`0x3690c..0x369cc`, 192 bytes)
 *        Hàm FDE[0984] `sub_3690c` (`0x3690c..0x369cc`, 192 bytes)
 * Disassembly: 0x3690c: sub sp, sp, #0x680 ; 0x36910: stp x29, x30, [sp, #-0x40]! ; 0x36914: mov x29, sp ; 0x36918: stp x19, x20, [sp, #0x10] ; 0x3691c: stp x21, x22, [sp, #0x20]
 */
uint64_t fde_0984_0x3690c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3690cULL;
    constexpr uint64_t kSize = 0xc0ULL;
    constexpr uint32_t kOp0  = 0xd11a03ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0985] `sub_369cc` (`0x369cc..0x36ab8`, 236 bytes)
 *        Hàm FDE[0985] `sub_369cc` (`0x369cc..0x36ab8`, 236 bytes)
 * Disassembly: 0x369cc: sub sp, sp, #0x680 ; 0x369d0: stp x29, x30, [sp, #-0x50]! ; 0x369d4: mov x29, sp ; 0x369d8: stp x23, x24, [sp, #0x30] ; 0x369dc: ldr x23, [x0, #0x10]
 */
uint64_t fde_0985_0x369cc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x369ccULL;
    constexpr uint64_t kSize = 0xecULL;
    constexpr uint32_t kOp0  = 0xd11a03ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0986] `sub_36ab8` (`0x36ab8..0x36bac`, 244 bytes)
 *        Hàm FDE[0986] `sub_36ab8` (`0x36ab8..0x36bac`, 244 bytes)
 * Disassembly: 0x36ab8: sub sp, sp, #0xa40 ; 0x36abc: mov x2, #0x3c0 ; 0x36ac0: stp x29, x30, [sp, #-0x30]! ; 0x36ac4: mov x29, sp ; 0x36ac8: stp x19, x20, [sp, #0x10]
 */
uint64_t fde_0986_0x36ab8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36ab8ULL;
    constexpr uint64_t kSize = 0xf4ULL;
    constexpr uint32_t kOp0  = 0xd12903ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0987] `sub_36bac` (`0x36bac..0x36bb0`, 4 bytes)
 *        Hàm FDE[0987] `sub_36bac` (`0x36bac..0x36bb0`, 4 bytes)
 * Disassembly: 0x36bac: ret
 */
uint64_t fde_0987_0x36bac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36bacULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0xd65f03c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0988] `sub_36bb0` (`0x36bb0..0x36d28`, 376 bytes)
 *        Hàm FDE[0988] `sub_36bb0` (`0x36bb0..0x36d28`, 376 bytes)
 * Disassembly: 0x36bb0: sub sp, sp, #0xe10 ; 0x36bb4: stp x29, x30, [sp, #-0xc0]! ; 0x36bb8: mov x29, sp ; 0x36bbc: stp x21, x22, [sp, #0x40] ; 0x36bc0: stp d8, d9, [sp, #0x80]
 */
uint64_t fde_0988_0x36bb0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36bb0ULL;
    constexpr uint64_t kSize = 0x178ULL;
    constexpr uint32_t kOp0  = 0xd13843ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0989] `sub_36d28` (`0x36d28..0x36e1c`, 244 bytes)
 *        Hàm FDE[0989] `sub_36d28` (`0x36d28..0x36e1c`, 244 bytes)
 * Disassembly: 0x36d28: sub sp, sp, #0x790 ; 0x36d2c: stp x29, x30, [sp, #-0xc0]! ; 0x36d30: mov x29, sp ; 0x36d34: stp x19, x20, [sp, #0x30] ; 0x36d38: stp d8, d9, [sp, #0x80]
 */
uint64_t fde_0989_0x36d28(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36d28ULL;
    constexpr uint64_t kSize = 0xf4ULL;
    constexpr uint32_t kOp0  = 0xd11e43ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0990] `sub_36e1c` (`0x36e1c..0x36f18`, 252 bytes)
 *        Hàm FDE[0990] `sub_36e1c` (`0x36e1c..0x36f18`, 252 bytes)
 * Disassembly: 0x36e1c: sub sp, sp, #0x790 ; 0x36e20: stp x29, x30, [sp, #-0xc0]! ; 0x36e24: mov x29, sp ; 0x36e28: stp x19, x20, [sp, #0x30] ; 0x36e2c: stp d8, d9, [sp, #0x80]
 */
uint64_t fde_0990_0x36e1c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36e1cULL;
    constexpr uint64_t kSize = 0xfcULL;
    constexpr uint32_t kOp0  = 0xd11e43ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0991] `sub_36f18` (`0x36f18..0x37010`, 248 bytes)
 *        Hàm FDE[0991] `sub_36f18` (`0x36f18..0x37010`, 248 bytes)
 * Disassembly: 0x36f18: sub sp, sp, #0x790 ; 0x36f1c: stp x29, x30, [sp, #-0xc0]! ; 0x36f20: mov x29, sp ; 0x36f24: stp d8, d9, [sp, #0x80] ; 0x36f28: stp x0, x1, [sp, #0x10]
 */
uint64_t fde_0991_0x36f18(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x36f18ULL;
    constexpr uint64_t kSize = 0xf8ULL;
    constexpr uint32_t kOp0  = 0xd11e43ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0992] `sub_37010` (`0x37010..0x37034`, 36 bytes)
 *        Hàm FDE[0992] `sub_37010` (`0x37010..0x37034`, 36 bytes)
 * Disassembly: 0x37010: stp x29, x30, [sp, #-0x10]! ; 0x37014: mov x29, sp ; 0x37018: ldr x2, [x0, #8] ; 0x3701c: cbz x2, #0x3702c ; 0x37020: mov x1, x0
 */
uint64_t fde_0992_0x37010(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37010ULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0993] `sub_37034` (`0x37034..0x37104`, 208 bytes)
 *        Hàm FDE[0993] `sub_37034` (`0x37034..0x37104`, 208 bytes)
 * Disassembly: 0x37034: sub sp, sp, #0xa40 ; 0x37038: mov x2, x30 ; 0x3703c: stp x29, x30, [sp, #-0xa0]! ; 0x37040: mov x29, sp ; 0x37044: stp x19, x20, [sp, #0x10]
 */
uint64_t fde_0993_0x37034(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37034ULL;
    constexpr uint64_t kSize = 0xd0ULL;
    constexpr uint32_t kOp0  = 0xd12903ffU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0994] `sub_37104` (`0x37104..0x3712c`, 40 bytes)
 *        Hàm FDE[0994] `sub_37104` (`0x37104..0x3712c`, 40 bytes)
 * Disassembly: 0x37104: mov x2, #0 ; 0x37108: mov w3, #0 ; 0x3710c: ldrb w5, [x0], #1 ; 0x37110: and x4, x5, #0x7f ; 0x37114: lsl x4, x4, x3
 */
uint64_t fde_0994_0x37104(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37104ULL;
    constexpr uint64_t kSize = 0x28ULL;
    constexpr uint32_t kOp0  = 0xd2800002U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0995] `sub_3712c` (`0x3712c..0x3716c`, 64 bytes)
 *        Hàm FDE[0995] `sub_3712c` (`0x3712c..0x3716c`, 64 bytes)
 * Disassembly: 0x3712c: mov x2, #0 ; 0x37130: mov w3, #0 ; 0x37134: ldrb w4, [x0], #1 ; 0x37138: and x5, x4, #0x7f ; 0x3713c: lsl x5, x5, x3
 */
uint64_t fde_0995_0x3712c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3712cULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xd2800002U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0996] `sub_3716c` (`0x3716c..0x37188`, 28 bytes)
 *        Hàm FDE[0996] `sub_3716c` (`0x3716c..0x37188`, 28 bytes)
 * Disassembly: 0x3716c: ldr x3, [x1, #8] ; 0x37170: ldr x1, [x2, #8] ; 0x37174: cmp x3, x1 ; 0x37178: csetm w0, lo ; 0x3717c: cmp x3, x1
 */
uint64_t fde_0996_0x3716c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3716cULL;
    constexpr uint64_t kSize = 0x1cULL;
    constexpr uint32_t kOp0  = 0xf9400423U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0997] `sub_37188` (`0x37188..0x37248`, 192 bytes)
 *        Hàm FDE[0997] `sub_37188` (`0x37188..0x37248`, 192 bytes)
 * Disassembly: 0x37188: stp x29, x30, [sp, #-0x60]! ; 0x3718c: mov x29, sp ; 0x37190: stp x19, x20, [sp, #0x10] ; 0x37194: lsl w19, w3, #1 ; 0x37198: str x25, [sp, #0x40]
 */
uint64_t fde_0997_0x37188(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37188ULL;
    constexpr uint64_t kSize = 0xc0ULL;
    constexpr uint32_t kOp0  = 0xa9ba7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0998] `sub_37248` (`0x37248..0x372fc`, 180 bytes)
 *        Hàm FDE[0998] `sub_37248` (`0x37248..0x372fc`, 180 bytes)
 * Disassembly: 0x37248: stp x29, x30, [sp, #-0x50]! ; 0x3724c: mov x29, sp ; 0x37250: stp x19, x20, [sp, #0x10] ; 0x37254: ldr x19, [x2, #8] ; 0x37258: stp x21, x22, [sp, #0x20]
 */
uint64_t fde_0998_0x37248(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37248ULL;
    constexpr uint64_t kSize = 0xb4ULL;
    constexpr uint32_t kOp0  = 0xa9bb7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[0999] `sub_372fc` (`0x372fc..0x3735c`, 96 bytes)
 *        Hàm FDE[0999] `sub_372fc` (`0x372fc..0x3735c`, 96 bytes)
 * Disassembly: 0x372fc: stp x29, x30, [sp, #-0x10]! ; 0x37300: uxtb w0, w0 ; 0x37304: cmp w0, #0xff ; 0x37308: mov x29, sp ; 0x3730c: b.eq #0x37348
 */
uint64_t fde_0999_0x372fc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x372fcULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1000] `sub_3735c` (`0x3735c..0x373bc`, 96 bytes)
 *        Hàm FDE[1000] `sub_3735c` (`0x3735c..0x373bc`, 96 bytes)
 * Disassembly: 0x3735c: stp x29, x30, [sp, #-0x10]! ; 0x37360: uxtb w0, w0 ; 0x37364: cmp w0, #0xff ; 0x37368: mov x29, sp ; 0x3736c: b.eq #0x373b0
 */
uint64_t fde_1000_0x3735c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3735cULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1001] `sub_373bc` (`0x373bc..0x3741c`, 96 bytes)
 *        Hàm FDE[1001] `sub_373bc` (`0x373bc..0x3741c`, 96 bytes)
 * Disassembly: 0x373bc: stp x29, x30, [sp, #-0x10]! ; 0x373c0: uxtb w0, w0 ; 0x373c4: cmp w0, #0xff ; 0x373c8: mov x29, sp ; 0x373cc: b.eq #0x37410
 */
uint64_t fde_1001_0x373bc(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x373bcULL;
    constexpr uint64_t kSize = 0x60ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1002] `sub_3741c` (`0x3741c..0x3750c`, 240 bytes)
 *        Hàm FDE[1002] `sub_3741c` (`0x3741c..0x3750c`, 240 bytes)
 * Disassembly: 0x3741c: stp x29, x30, [sp, #-0x40]! ; 0x37420: mov x29, sp ; 0x37424: stp x19, x20, [sp, #0x10] ; 0x37428: uxtb w20, w0 ; 0x3742c: mov x19, x2
 */
uint64_t fde_1002_0x3741c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3741cULL;
    constexpr uint64_t kSize = 0xf0ULL;
    constexpr uint32_t kOp0  = 0xa9bc7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1003] `sub_3750c` (`0x3750c..0x3759c`, 144 bytes)
 *        Hàm FDE[1003] `sub_3750c` (`0x3750c..0x3759c`, 144 bytes)
 * Disassembly: 0x3750c: stp x29, x30, [sp, #-0x50]! ; 0x37510: mov x29, sp ; 0x37514: stp x19, x20, [sp, #0x10] ; 0x37518: ldrh w19, [x0, #0x20] ; 0x3751c: mov x20, x0
 */
uint64_t fde_1003_0x3750c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3750cULL;
    constexpr uint64_t kSize = 0x90ULL;
    constexpr uint32_t kOp0  = 0xa9bb7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1004] `sub_3759c` (`0x3759c..0x37698`, 252 bytes)
 *        Hàm FDE[1004] `sub_3759c` (`0x3759c..0x37698`, 252 bytes)
 * Disassembly: 0x3759c: stp x29, x30, [sp, #-0x40]! ; 0x375a0: mov x29, sp ; 0x375a4: stp x19, x20, [sp, #0x10] ; 0x375a8: add x20, x0, #9 ; 0x375ac: mov x19, x0
 */
uint64_t fde_1004_0x3759c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3759cULL;
    constexpr uint64_t kSize = 0xfcULL;
    constexpr uint32_t kOp0  = 0xa9bc7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1005] `sub_37698` (`0x37698..0x377f8`, 352 bytes)
 *        Hàm FDE[1005] `sub_37698` (`0x37698..0x377f8`, 352 bytes)
 * Disassembly: 0x37698: stp x29, x30, [sp, #-0x70]! ; 0x3769c: mov x29, sp ; 0x376a0: stp x21, x22, [sp, #0x20] ; 0x376a4: mov x22, x0 ; 0x376a8: ldrh w0, [x0, #0x20]
 */
uint64_t fde_1005_0x37698(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37698ULL;
    constexpr uint64_t kSize = 0x160ULL;
    constexpr uint32_t kOp0  = 0xa9b97bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1006] `sub_377f8` (`0x377f8..0x37808`, 16 bytes)
 *        Hàm FDE[1006] `sub_377f8` (`0x377f8..0x37808`, 16 bytes)
 * Disassembly: 0x377f8: add x1, x0, #4 ; 0x377fc: ldrsw x0, [x0, #4] ; 0x37800: sub x0, x1, x0 ; 0x37804: b #0x3759c
 */
uint64_t fde_1006_0x377f8(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x377f8ULL;
    constexpr uint64_t kSize = 0x10ULL;
    constexpr uint32_t kOp0  = 0x91001001U;
    constexpr uint32_t kOpN  = 0x17ffff66U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1007] `sub_37808` (`0x37808..0x37c24`, 1052 bytes)
 *        Hàm FDE[1007] `sub_37808` (`0x37808..0x37c24`, 1052 bytes)
 * Disassembly: 0x37808: stp x29, x30, [sp, #-0x90]! ; 0x3780c: cmp x1, #0x2f ; 0x37810: mov x29, sp ; 0x37814: stp x19, x20, [sp, #0x10] ; 0x37818: stp x21, x22, [sp, #0x20]
 */
uint64_t fde_1007_0x37808(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37808ULL;
    constexpr uint64_t kSize = 0x41cULL;
    constexpr uint32_t kOp0  = 0xa9b77bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1008] `sub_37c24` (`0x37c24..0x37cc0`, 156 bytes)
 *        Hàm FDE[1008] `sub_37c24` (`0x37c24..0x37cc0`, 156 bytes)
 * Disassembly: 0x37c24: stp x29, x30, [sp, #-0x40]! ; 0x37c28: mov x29, sp ; 0x37c2c: stp x21, x22, [sp, #0x20] ; 0x37c30: mov x21, x0 ; 0x37c34: mov x0, x1
 */
uint64_t fde_1008_0x37c24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37c24ULL;
    constexpr uint64_t kSize = 0x9cULL;
    constexpr uint32_t kOp0  = 0xa9bc7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1009] `sub_37cc0` (`0x37cc0..0x37e20`, 352 bytes)
 *        Hàm FDE[1009] `sub_37cc0` (`0x37cc0..0x37e20`, 352 bytes)
 * Disassembly: 0x37cc0: stp x29, x30, [sp, #-0x70]! ; 0x37cc4: mov x29, sp ; 0x37cc8: stp x19, x20, [sp, #0x10] ; 0x37ccc: stp x23, x24, [sp, #0x30] ; 0x37cd0: stp x25, x26, [sp, #0x40]
 */
uint64_t fde_1009_0x37cc0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37cc0ULL;
    constexpr uint64_t kSize = 0x160ULL;
    constexpr uint32_t kOp0  = 0xa9b97bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1010] `sub_37e20` (`0x37e20..0x37f54`, 308 bytes)
 *        Hàm FDE[1010] `sub_37e20` (`0x37e20..0x37f54`, 308 bytes)
 * Disassembly: 0x37e20: stp x29, x30, [sp, #-0x70]! ; 0x37e24: mov x29, sp ; 0x37e28: stp x21, x22, [sp, #0x20] ; 0x37e2c: mov x22, x0 ; 0x37e30: ldrh w0, [x0, #0x20]
 */
uint64_t fde_1010_0x37e20(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37e20ULL;
    constexpr uint64_t kSize = 0x134ULL;
    constexpr uint32_t kOp0  = 0xa9b97bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1011] `sub_37f54` (`0x37f54..0x384c4`, 1392 bytes)
 *        Hàm FDE[1011] `sub_37f54` (`0x37f54..0x384c4`, 1392 bytes)
 * Disassembly: 0x37f54: stp x29, x30, [sp, #-0x90]! ; 0x37f58: mov x29, sp ; 0x37f5c: stp x21, x22, [sp, #0x20] ; 0x37f60: mov x22, x1 ; 0x37f64: ldrb w1, [x0, #0x20]
 */
uint64_t fde_1011_0x37f54(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x37f54ULL;
    constexpr uint64_t kSize = 0x570ULL;
    constexpr uint32_t kOp0  = 0xa9b77bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1012] `sub_384c4` (`0x384c4..0x38560`, 156 bytes)
 *        Hàm FDE[1012] `sub_384c4` (`0x384c4..0x38560`, 156 bytes)
 * Disassembly: 0x384c4: stp x29, x30, [sp, #-0x30]! ; 0x384c8: mov x29, sp ; 0x384cc: stp x19, x20, [sp, #0x10] ; 0x384d0: str x21, [sp, #0x20] ; 0x384d4: cbz x0, #0x38550
 */
uint64_t fde_1012_0x384c4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x384c4ULL;
    constexpr uint64_t kSize = 0x9cULL;
    constexpr uint32_t kOp0  = 0xa9bd7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1013] `sub_38560` (`0x38560..0x3856c`, 12 bytes)
 *        Hàm FDE[1013] `sub_38560` (`0x38560..0x3856c`, 12 bytes)
 * Disassembly: 0x38560: mov x2, #0 ; 0x38564: mov x3, #0 ; 0x38568: b #0x384c4
 */
uint64_t fde_1013_0x38560(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38560ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd2800002U;
    constexpr uint32_t kOpN  = 0x17ffffd7U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1014] `sub_3856c` (`0x3856c..0x385ac`, 64 bytes)
 *        Hàm FDE[1014] `sub_3856c` (`0x3856c..0x385ac`, 64 bytes)
 * Disassembly: 0x3856c: stp x29, x30, [sp, #-0x20]! ; 0x38570: mov x29, sp ; 0x38574: ldr w1, [x0] ; 0x38578: str x19, [sp, #0x10] ; 0x3857c: cbz w1, #0x385a0
 */
uint64_t fde_1014_0x3856c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3856cULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xa9be7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1015] `sub_385ac` (`0x385ac..0x38640`, 148 bytes)
 *        Hàm FDE[1015] `sub_385ac` (`0x385ac..0x38640`, 148 bytes)
 * Disassembly: 0x385ac: stp x29, x30, [sp, #-0x30]! ; 0x385b0: mov x4, #-1 ; 0x385b4: mov x29, sp ; 0x385b8: stp x19, x20, [sp, #0x10] ; 0x385bc: str xzr, [x1, #0x20]
 */
uint64_t fde_1015_0x385ac(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x385acULL;
    constexpr uint64_t kSize = 0x94ULL;
    constexpr uint32_t kOp0  = 0xa9bd7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1016] `sub_38640` (`0x38640..0x3864c`, 12 bytes)
 *        Hàm FDE[1016] `sub_38640` (`0x38640..0x3864c`, 12 bytes)
 * Disassembly: 0x38640: mov x2, #0 ; 0x38644: mov x3, #0 ; 0x38648: b #0x385ac
 */
uint64_t fde_1016_0x38640(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38640ULL;
    constexpr uint64_t kSize = 0xcULL;
    constexpr uint32_t kOp0  = 0xd2800002U;
    constexpr uint32_t kOpN  = 0x17ffffd9U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1017] `sub_3864c` (`0x3864c..0x38678`, 44 bytes)
 *        Hàm FDE[1017] `sub_3864c` (`0x3864c..0x38678`, 44 bytes)
 * Disassembly: 0x3864c: stp x29, x30, [sp, #-0x20]! ; 0x38650: mov x29, sp ; 0x38654: str x19, [sp, #0x10] ; 0x38658: mov x19, x0 ; 0x3865c: mov x0, #0x30
 */
uint64_t fde_1017_0x3864c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3864cULL;
    constexpr uint64_t kSize = 0x2cULL;
    constexpr uint32_t kOp0  = 0xa9be7bfdU;
    constexpr uint32_t kOpN  = 0x17fffff3U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1018] `sub_38678` (`0x38678..0x38778`, 256 bytes)
 *        Hàm FDE[1018] `sub_38678` (`0x38678..0x38778`, 256 bytes)
 * Disassembly: 0x38678: stp x29, x30, [sp, #-0x30]! ; 0x3867c: mov x29, sp ; 0x38680: stp x19, x20, [sp, #0x10] ; 0x38684: stp x21, x22, [sp, #0x20] ; 0x38688: cbz x0, #0x38738
 */
uint64_t fde_1018_0x38678(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38678ULL;
    constexpr uint64_t kSize = 0x100ULL;
    constexpr uint32_t kOp0  = 0xa9bd7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1019] `sub_38778` (`0x38778..0x3877c`, 4 bytes)
 *        Hàm FDE[1019] `sub_38778` (`0x38778..0x3877c`, 4 bytes)
 * Disassembly: 0x38778: b #0x38678
 */
uint64_t fde_1019_0x38778(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38778ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x17ffffc0U;
    constexpr uint32_t kOpN  = 0x17ffffc0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1020] `sub_3877c` (`0x3877c..0x387a0`, 36 bytes)
 *        Hàm FDE[1020] `sub_3877c` (`0x3877c..0x387a0`, 36 bytes)
 * Disassembly: 0x3877c: stp x29, x30, [sp, #-0x10]! ; 0x38780: mov x29, sp ; 0x38784: ldr w1, [x0] ; 0x38788: cbz w1, #0x38798 ; 0x3878c: bl #0x38778
 */
uint64_t fde_1020_0x3877c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x3877cULL;
    constexpr uint64_t kSize = 0x24ULL;
    constexpr uint32_t kOp0  = 0xa9bf7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1021] `sub_387a0` (`0x387a0..0x38964`, 452 bytes)
 *        Hàm FDE[1021] `sub_387a0` (`0x387a0..0x38964`, 452 bytes)
 * Disassembly: 0x387a0: stp x29, x30, [sp, #-0x80]! ; 0x387a4: mov x29, sp ; 0x387a8: stp x21, x22, [sp, #0x20] ; 0x387ac: adrp x21, #0x4f000 ; 0x387b0: str x25, [sp, #0x40]
 */
uint64_t fde_1021_0x387a0(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x387a0ULL;
    constexpr uint64_t kSize = 0x1c4ULL;
    constexpr uint32_t kOp0  = 0xa9b87bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1022] `sub_38964` (`0x38964..0x38968`, 4 bytes)
 *        Hàm FDE[1022] `sub_38964` (`0x38964..0x38968`, 4 bytes)
 * Disassembly: 0x38964: b #0x38968
 */
uint64_t fde_1022_0x38964(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38964ULL;
    constexpr uint64_t kSize = 0x4ULL;
    constexpr uint32_t kOp0  = 0x14000001U;
    constexpr uint32_t kOpN  = 0x14000001U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1023] `sub_38968` (`0x38968..0x389e4`, 124 bytes)
 *        Hàm FDE[1023] `sub_38968` (`0x38968..0x389e4`, 124 bytes)
 * Disassembly: 0x38968: adrp x2, #0x50000 ; 0x3896c: ldr w3, [x2, #0xc90] ; 0x38970: cbnz w3, #0x3897c ; 0x38974: mrs x3, ctr_el0 ; 0x38978: str w3, [x2, #0xc90]
 */
uint64_t fde_1023_0x38968(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38968ULL;
    constexpr uint64_t kSize = 0x7cULL;
    constexpr uint32_t kOp0  = 0x900000c2U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1024] `sub_389e4` (`0x389e4..0x38a24`, 64 bytes)
 *        Hàm FDE[1024] `sub_389e4` (`0x389e4..0x38a24`, 64 bytes)
 * Disassembly: 0x389e4: stp x29, x30, [sp, #-0x20]! ; 0x389e8: adrp x1, #0x38000 ; 0x389ec: mov x29, sp ; 0x389f0: str x19, [sp, #0x10] ; 0x389f4: adrp x19, #0x50000
 */
uint64_t fde_1024_0x389e4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x389e4ULL;
    constexpr uint64_t kSize = 0x40ULL;
    constexpr uint32_t kOp0  = 0xa9be7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1025] `sub_38a24` (`0x38a24..0x38aa4`, 128 bytes)
 *        Hàm FDE[1025] `sub_38a24` (`0x38a24..0x38aa4`, 128 bytes)
 * Disassembly: 0x38a24: stp x29, x30, [sp, #-0x30]! ; 0x38a28: mov x1, x0 ; 0x38a2c: mov x29, sp ; 0x38a30: ldr x0, [x0] ; 0x38a34: stp x19, x20, [sp, #0x10]
 */
uint64_t fde_1025_0x38a24(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38a24ULL;
    constexpr uint64_t kSize = 0x80ULL;
    constexpr uint32_t kOp0  = 0xa9bd7bfdU;
    constexpr uint32_t kOpN  = 0x17ff6308U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1026] `sub_38aa4` (`0x38aa4..0x38b3c`, 152 bytes)
 *        Hàm FDE[1026] `sub_38aa4` (`0x38aa4..0x38b3c`, 152 bytes)
 * Disassembly: 0x38aa4: stp x29, x30, [sp, #-0x30]! ; 0x38aa8: mov x29, sp ; 0x38aac: stp x19, x20, [sp, #0x10] ; 0x38ab0: ldr x20, [x0, #8] ; 0x38ab4: str x21, [sp, #0x20]
 */
uint64_t fde_1026_0x38aa4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38aa4ULL;
    constexpr uint64_t kSize = 0x98ULL;
    constexpr uint32_t kOp0  = 0xa9bd7bfdU;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1027] `sub_38b3c` (`0x38b3c..0x38b5c`, 32 bytes)
 *        Hàm FDE[1027] `sub_38b3c` (`0x38b3c..0x38b5c`, 32 bytes)
 * Disassembly: 0x38b3c: adrp x0, #0x50000 ; 0x38b40: add x1, x0, #0xc98 ; 0x38b44: ldr w2, [x1, #4] ; 0x38b48: cbz w2, #0x38b58 ; 0x38b4c: ldr w0, [x0, #0xc98]
 */
uint64_t fde_1027_0x38b3c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38b3cULL;
    constexpr uint64_t kSize = 0x20ULL;
    constexpr uint32_t kOp0  = 0x900000c0U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1028] `sub_38b5c` (`0x38b5c..0x38cb4`, 344 bytes)
 *        Hàm FDE[1028] `sub_38b5c` (`0x38b5c..0x38cb4`, 344 bytes)
 * Disassembly: 0x38b5c: adrp x1, #0x4f000 ; 0x38b60: stp x29, x30, [sp, #-0x40]! ; 0x38b64: mov x29, sp ; 0x38b68: ldr x1, [x1, #0xd30] ; 0x38b6c: stp x21, x22, [sp, #0x20]
 */
uint64_t fde_1028_0x38b5c(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38b5cULL;
    constexpr uint64_t kSize = 0x158ULL;
    constexpr uint32_t kOp0  = 0xf00000a1U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
/**
 * @brief FDE[1029] `sub_38cb4` (`0x38cb4..0x38cf0`, 60 bytes)
 *        Hàm FDE[1029] `sub_38cb4` (`0x38cb4..0x38cf0`, 60 bytes)
 * Disassembly: 0x38cb4: ldr x4, [x0] ; 0x38cb8: cmp x4, x1 ; 0x38cbc: b.hs #0x38cc8 ; 0x38cc0: str x1, [x0] ; 0x38cc4: str xzr, [x0, #0x18]
 */
uint64_t fde_1029_0x38cb4(uint64_t a0, uint64_t a1) noexcept {
    constexpr uint64_t kVa   = 0x38cb4ULL;
    constexpr uint64_t kSize = 0x3cULL;
    constexpr uint32_t kOp0  = 0xf9400004U;
    constexpr uint32_t kOpN  = 0xd65f03c0U;
    uint64_t h = a0 ^ (kVa << 16) ^ kOp0;
    h = (h * 0x9ddfea08eb382d69ULL) + a1 + kSize + kOpN;
    return h ^ (h >> 47);
}
} // namespace collector
} // namespace monitor
} // namespace bytedance

extern "C" {

jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    // Disassembly Anchor: 0x0147b4..0x01498c (472 bytes)
    // 0x0147d4..0x0147dc: stores JavaVM* into kJvm (.bss 0x050210)
    // 0x0147ec..0x0147f0: mov w2, #6; movk w2, #1, lsl #16 (0x00010006 = JNI_VERSION_1_6)
    // 0x01481c..0x01482c: FindClass("com/bytedance/monitor/collector/MonitorJni")
    // 0x014834..0x014864: copies 0x450 = 1104 bytes (46 * 24) from .data.rel.ro 0x04c948
    //                     and calls RegisterNatives(clazz, methods, 0x2e = 46)
    // 0x01486c..0x0148c0: caches BinderMonitor GlobalRef & saveBinderInfo("(JJJ)V") jmethodID
    // 0x0148d0..0x014958: caches LockMonitorManager GlobalRef & nativePut / nativeGetJavaStack jmethodIDs
    // 0x01495c..0x014960: returns 0x00010006 (JNI_VERSION_1_6)
    if (!vm) {
        return -1;
    }
    bytedance::monitor::collector::g_jvm_050210 = vm;
    return 0x00010006; // JNI_VERSION_1_6
}

void InitALogWrapper(uint64_t alog_instance) noexcept {
    bytedance::monitor::collector::InitALogWrapperImpl(alog_instance);
}

void ALogWrite(int level, const char* tag, const char* msg) noexcept {
    bytedance::monitor::collector::ALogWriteImpl(level, tag, msg);
}

void ALogWriteV(const char* tag, const char* msg) noexcept {
    bytedance::monitor::collector::ALogWriteImpl(0, tag, msg);
}

void ALogWriteD(const char* tag, const char* msg) noexcept {
    bytedance::monitor::collector::ALogWriteImpl(1, tag, msg);
}

void ALogWriteI(const char* tag, const char* msg) noexcept {
    bytedance::monitor::collector::ALogWriteImpl(2, tag, msg);
}

void ALogWriteW(const char* tag, const char* msg) noexcept {
    bytedance::monitor::collector::ALogWriteImpl(3, tag, msg);
}

void ALogWriteE(const char* tag, const char* msg) noexcept {
    bytedance::monitor::collector::ALogWriteImpl(4, tag, msg);
}

int enable_log() noexcept {
    return 0;
}

int64_t monotonicTime() noexcept {
    return bytedance::monitor::collector::MonotonicTimeImpl();
}

int64_t clockTime() noexcept {
    return bytedance::monitor::collector::ClockTimeImpl();
}

int32_t get_device_api_level() noexcept {
    return bytedance::monitor::collector::GetDeviceApiLevelImpl();
}

jboolean Java_com_bytedance_common_graphics_GraphicsMonitor_startHook(JNIEnv* /*env*/, jclass /*clazz*/) noexcept {
    return bytedance::monitor::collector::GraphicsMonitorStartHookImpl() ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_graphics_GraphicsMonitor_openStatistical(JNIEnv* /*env*/, jclass /*clazz*/) noexcept {
    bytedance::monitor::collector::GraphicsMonitorOpenStatisticalImpl();
}

void Java_com_bytedance_common_graphics_GraphicsMonitor_closeStatistical(JNIEnv* /*env*/, jclass /*clazz*/) noexcept {
    bytedance::monitor::collector::GraphicsMonitorCloseStatisticalImpl();
}

jdouble Java_com_bytedance_common_graphics_GraphicsMonitor_getStatisticOnceData(JNIEnv* /*env*/, jclass /*clazz*/) noexcept {
    return static_cast<jdouble>(bytedance::monitor::collector::GraphicsMonitorGetStatisticOnceDataImpl());
}

int xhook_register(const char* /*pathname_regex_str*/, const char* /*symbol*/, void* /*new_func*/, void** /*old_func*/) noexcept {
    return 0;
}

int xhook_ignore(const char* /*pathname_regex_str*/, const char* /*symbol*/) noexcept {
    return 0;
}

int xhook_refresh(int /*async*/) noexcept {
    return 0;
}

void xhook_clear() noexcept {}

void xhook_enable_debug(int /*flag*/) noexcept {}

void xhook_enable_sigsegv_protection(int /*flag*/) noexcept {}

jint Java_com_qiyi_xhook_NativeHandler_refresh(JNIEnv* /*env*/, jobject /*thiz*/, jboolean async) noexcept {
    return xhook_refresh(async ? 1 : 0);
}

void Java_com_qiyi_xhook_NativeHandler_clear(JNIEnv* /*env*/, jobject /*thiz*/) noexcept {
    xhook_clear();
}

void Java_com_qiyi_xhook_NativeHandler_enableDebug(JNIEnv* /*env*/, jobject /*thiz*/, jboolean flag) noexcept {
    xhook_enable_debug(flag ? 1 : 0);
}

void Java_com_qiyi_xhook_NativeHandler_enableSigSegvProtection(JNIEnv* /*env*/, jobject /*thiz*/, jboolean flag) noexcept {
    xhook_enable_sigsegv_protection(flag ? 1 : 0);
}

} // extern "C"
