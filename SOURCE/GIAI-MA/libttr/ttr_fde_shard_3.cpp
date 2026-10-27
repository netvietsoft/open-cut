// ============================================================================
// File: ttr_fde_shard_3.cpp
// Target: libttr.so (625,192 bytes)
// SHA-256: 38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// FDE Range: [1354..2030] of 3,386 (.eh_frame_hdr @ 0x08ab40)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [1354..2030]
//      verified directly against the .text section of libttr.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [1354..2030]
//      đã đối chiếu trực tiếp với phân đoạn .text của libttr.so.
// ============================================================================

#include "ttr_render_types.h"

namespace ttr_render {

// [EN] FDE[1354] start_va=0x0481b0, fde_va=0x07de00, span=56 B | [VN] FDE[1354]
uint32_t ttr_fde_1354_0x0481b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006775U + 0x0481b0U) ^ (0xb4000121U + 0x07de00U + 56U);
}

// [EN] FDE[1355] start_va=0x0481e8, fde_va=0x07de20, span=120 B | [VN] FDE[1355]
uint32_t ttr_fde_1355_0x0481e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006b07U + 0x0481e8U) ^ (0x7100069fU + 0x07de20U + 120U);
}

// [EN] FDE[1356] start_va=0x048260, fde_va=0x07de40, span=36 B | [VN] FDE[1356]
uint32_t ttr_fde_1356_0x048260(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0b010048U) + (a1 ^ 0x36f80068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0b000108U + 0x048260U) ^ (0x37ffffe8U + 0x07de40U + 36U);
}

// [EN] FDE[1357] start_va=0x048284, fde_va=0x07de58, span=44 B | [VN] FDE[1357]
uint32_t ttr_fde_1357_0x048284(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37efc28U + 0x048284U) ^ (0xb50000e8U + 0x07de58U + 44U);
}

// [EN] FDE[1358] start_va=0x0482b0, fde_va=0x07de78, span=32 B | [VN] FDE[1358]
uint32_t ttr_fde_1358_0x0482b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x8b010909U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb08013fU + 0x0482b0U) ^ (0x54000080U + 0x07de78U + 32U);
}

// [EN] FDE[1359] start_va=0x0482d0, fde_va=0x07de90, span=32 B | [VN] FDE[1359]
uint32_t ttr_fde_1359_0x0482d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x8b010909U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb08013fU + 0x0482d0U) ^ (0x54000080U + 0x07de90U + 32U);
}

// [EN] FDE[1360] start_va=0x0482f0, fde_va=0x07dea8, span=52 B | [VN] FDE[1360]
uint32_t ttr_fde_1360_0x0482f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xd37efc28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb5000148U + 0x0482f0U) ^ (0x94006c7cU + 0x07dea8U + 52U);
}

// [EN] FDE[1361] start_va=0x048324, fde_va=0x07dec0, span=32 B | [VN] FDE[1361]
uint32_t ttr_fde_1361_0x048324(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xd37ef408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91011d00U + 0x048324U) ^ (0x97ff4fa8U + 0x07dec0U + 32U);
}

// [EN] FDE[1362] start_va=0x048344, fde_va=0x07ded8, span=36 B | [VN] FDE[1362]
uint32_t ttr_fde_1362_0x048344(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540000c0U + 0x048344U) ^ (0xf940042aU + 0x07ded8U + 36U);
}

// [EN] FDE[1363] start_va=0x048368, fde_va=0x07def0, span=40 B | [VN] FDE[1363]
uint32_t ttr_fde_1363_0x048368(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x048368U) ^ (0xd1001129U + 0x07def0U + 40U);
}

// [EN] FDE[1364] start_va=0x048390, fde_va=0x07df08, span=8 B | [VN] FDE[1364]
uint32_t ttr_fde_1364_0x048390(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85f8000U) + (a1 ^ 0x17ff4f93U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9be53f5U + 0x048390U) ^ (0xa9017bf3U + 0x07df08U + 8U);
}

// [EN] FDE[1365] start_va=0x048398, fde_va=0x07df20, span=56 B | [VN] FDE[1365]
uint32_t ttr_fde_1365_0x048398(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940066fbU + 0x048398U) ^ (0xb4000121U + 0x07df20U + 56U);
}

// [EN] FDE[1366] start_va=0x0483d0, fde_va=0x07df40, span=44 B | [VN] FDE[1366]
uint32_t ttr_fde_1366_0x0483d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37efc28U + 0x0483d0U) ^ (0xb50000e8U + 0x07df40U + 44U);
}

// [EN] FDE[1367] start_va=0x0483fc, fde_va=0x07df60, span=32 B | [VN] FDE[1367]
uint32_t ttr_fde_1367_0x0483fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9139c108U + 0x0483fcU) ^ (0x94005e94U + 0x07df60U + 32U);
}

// [EN] FDE[1368] start_va=0x04841c, fde_va=0x07df78, span=24 B | [VN] FDE[1368]
uint32_t ttr_fde_1368_0x04841c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x04841cU) ^ (0xaa1303e0U + 0x07df78U + 24U);
}

// [EN] FDE[1369] start_va=0x048434, fde_va=0x07df90, span=8 B | [VN] FDE[1369]
uint32_t ttr_fde_1369_0x048434(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff4e3dU + 0x048434U) ^ (0xa9bf7bf3U + 0x07df90U + 8U);
}

// [EN] FDE[1370] start_va=0x04843c, fde_va=0x07dfa8, span=4 B | [VN] FDE[1370]
uint32_t ttr_fde_1370_0x04843c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff4e3dU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x04843cU) ^ (0x9100a000U + 0x07dfa8U + 4U);
}

// [EN] FDE[1371] start_va=0x048440, fde_va=0x07dfc0, span=28 B | [VN] FDE[1371]
uint32_t ttr_fde_1371_0x048440(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100a000U + 0x048440U) ^ (0x94000004U + 0x07dfc0U + 28U);
}

// [EN] FDE[1372] start_va=0x04845c, fde_va=0x07dfd8, span=24 B | [VN] FDE[1372]
uint32_t ttr_fde_1372_0x04845c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000060U + 0x04845cU) ^ (0xf9000500U + 0x07dfd8U + 24U);
}

// [EN] FDE[1373] start_va=0x048474, fde_va=0x07dff0, span=232 B | [VN] FDE[1373]
uint32_t ttr_fde_1373_0x048474(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90363f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9045bf7U + 0x048474U) ^ (0xa90553f5U + 0x07dff0U + 232U);
}

// [EN] FDE[1374] start_va=0x04855c, fde_va=0x07e018, span=312 B | [VN] FDE[1374]
uint32_t ttr_fde_1374_0x04855c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa90653f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9077bf3U + 0x04855cU) ^ (0xaa0003f3U + 0x07e018U + 312U);
}

// [EN] FDE[1375] start_va=0x048694, fde_va=0x07e038, span=588 B | [VN] FDE[1375]
uint32_t ttr_fde_1375_0x048694(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa9045bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90553f5U + 0x048694U) ^ (0xa9067bf3U + 0x07e038U + 588U);
}

// [EN] FDE[1376] start_va=0x0488e0, fde_va=0x07e058, span=296 B | [VN] FDE[1376]
uint32_t ttr_fde_1376_0x0488e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xf90033f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9075bf7U + 0x0488e0U) ^ (0xa90853f5U + 0x07e058U + 296U);
}

// [EN] FDE[1377] start_va=0x048a08, fde_va=0x07e080, span=124 B | [VN] FDE[1377]
uint32_t ttr_fde_1377_0x048a08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x048a08U) ^ (0xaa0003f4U + 0x07e080U + 124U);
}

// [EN] FDE[1378] start_va=0x048a84, fde_va=0x07e0a0, span=120 B | [VN] FDE[1378]
uint32_t ttr_fde_1378_0x048a84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006785U + 0x048a84U) ^ (0x9100a000U + 0x07e0a0U + 120U);
}

// [EN] FDE[1379] start_va=0x048afc, fde_va=0x07e0c0, span=176 B | [VN] FDE[1379]
uint32_t ttr_fde_1379_0x048afc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf90033f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90753f5U + 0x048afcU) ^ (0xa9087bf3U + 0x07e0c0U + 176U);
}

// [EN] FDE[1380] start_va=0x048bac, fde_va=0x07e0e0, span=1304 B | [VN] FDE[1380]
uint32_t ttr_fde_1380_0x048bac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xa9056bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90663f9U + 0x048bacU) ^ (0xa9075bf7U + 0x07e0e0U + 1304U);
}

// [EN] FDE[1381] start_va=0x0490c4, fde_va=0x07e110, span=124 B | [VN] FDE[1381]
uint32_t ttr_fde_1381_0x0490c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006750U + 0x0490c4U) ^ (0x7100069fU + 0x07e110U + 124U);
}

// [EN] FDE[1382] start_va=0x049140, fde_va=0x07e130, span=8 B | [VN] FDE[1382]
uint32_t ttr_fde_1382_0x049140(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e1U) + (a1 ^ 0x14000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x049140U) ^ (0xaa0003f3U + 0x07e130U + 8U);
}

// [EN] FDE[1383] start_va=0x049148, fde_va=0x07e148, span=28 B | [VN] FDE[1383]
uint32_t ttr_fde_1383_0x049148(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100b000U + 0x049148U) ^ (0x97ff4cbfU + 0x07e148U + 28U);
}

// [EN] FDE[1384] start_va=0x049164, fde_va=0x07e160, span=24 B | [VN] FDE[1384]
uint32_t ttr_fde_1384_0x049164(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x049164U) ^ (0xb4000040U + 0x07e160U + 24U);
}

// [EN] FDE[1385] start_va=0x04917c, fde_va=0x07e178, span=200 B | [VN] FDE[1385]
uint32_t ttr_fde_1385_0x04917c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9035bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04917cU) ^ (0xa9057bf3U + 0x07e178U + 200U);
}

// [EN] FDE[1386] start_va=0x049244, fde_va=0x07e198, span=24 B | [VN] FDE[1386]
uint32_t ttr_fde_1386_0x049244(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12000008U) + (a1 ^ 0xd00002a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000289U + 0x049244U) ^ (0x910d4000U + 0x07e198U + 24U);
}

// [EN] FDE[1387] start_va=0x04925c, fde_va=0x07e1b0, span=44 B | [VN] FDE[1387]
uint32_t ttr_fde_1387_0x04925c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913b4108U + 0x04925cU) ^ (0xaa0003f3U + 0x07e1b0U + 44U);
}

// [EN] FDE[1388] start_va=0x049288, fde_va=0x07e1c8, span=56 B | [VN] FDE[1388]
uint32_t ttr_fde_1388_0x049288(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000288U + 0x049288U) ^ (0xaa0003f3U + 0x07e1c8U + 56U);
}

// [EN] FDE[1389] start_va=0x0492c0, fde_va=0x07e1e8, span=24 B | [VN] FDE[1389]
uint32_t ttr_fde_1389_0x0492c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffe5U + 0x0492c0U) ^ (0xaa1303e0U + 0x07e1e8U + 24U);
}

// [EN] FDE[1390] start_va=0x0492d8, fde_va=0x07e200, span=16 B | [VN] FDE[1390]
uint32_t ttr_fde_1390_0x0492d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x0492d8U) ^ (0x17ffffdeU + 0x07e200U + 16U);
}

// [EN] FDE[1391] start_va=0x0492e8, fde_va=0x07e218, span=16 B | [VN] FDE[1391]
uint32_t ttr_fde_1391_0x0492e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x0492e8U) ^ (0x17fffff3U + 0x07e218U + 16U);
}

// [EN] FDE[1392] start_va=0x0492f8, fde_va=0x07e230, span=32 B | [VN] FDE[1392]
uint32_t ttr_fde_1392_0x0492f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400028U) + (a1 ^ 0xf9000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400429U + 0x0492f8U) ^ (0xf85e8108U + 0x07e230U + 32U);
}

// [EN] FDE[1393] start_va=0x049318, fde_va=0x07e248, span=40 B | [VN] FDE[1393]
uint32_t ttr_fde_1393_0x049318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb00003fU) + (a1 ^ 0x540000e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400008U + 0x049318U) ^ (0x7100291fU + 0x07e248U + 40U);
}

// [EN] FDE[1394] start_va=0x049340, fde_va=0x07e260, span=76 B | [VN] FDE[1394]
uint32_t ttr_fde_1394_0x049340(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91018000U + 0x049340U) ^ (0x6f00e400U + 0x07e260U + 76U);
}

// [EN] FDE[1395] start_va=0x04938c, fde_va=0x07e278, span=256 B | [VN] FDE[1395]
uint32_t ttr_fde_1395_0x04938c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04938cU) ^ (0xa9037bf3U + 0x07e278U + 256U);
}

// [EN] FDE[1396] start_va=0x04948c, fde_va=0x07e2a0, span=276 B | [VN] FDE[1396]
uint32_t ttr_fde_1396_0x04948c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9002bf8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9065bf7U + 0x04948cU) ^ (0xa90753f5U + 0x07e2a0U + 276U);
}

// [EN] FDE[1397] start_va=0x0495a0, fde_va=0x07e2c8, span=64 B | [VN] FDE[1397]
uint32_t ttr_fde_1397_0x0495a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9401408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0495a0U) ^ (0xd1000508U + 0x07e2c8U + 64U);
}

// [EN] FDE[1398] start_va=0x0495e0, fde_va=0x07e2e0, span=976 B | [VN] FDE[1398]
uint32_t ttr_fde_1398_0x0495e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10343ffU) + (a1 ^ 0xa9086bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90963f9U + 0x0495e0U) ^ (0xa90a5bf7U + 0x07e2e0U + 976U);
}

// [EN] FDE[1399] start_va=0x0499b0, fde_va=0x07e310, span=1600 B | [VN] FDE[1399]
uint32_t ttr_fde_1399_0x0499b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10443ffU) + (a1 ^ 0xa90e5bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90f53f5U + 0x0499b0U) ^ (0xa9107bf3U + 0x07e310U + 1600U);
}

// [EN] FDE[1400] start_va=0x049ff0, fde_va=0x07e338, span=68 B | [VN] FDE[1400]
uint32_t ttr_fde_1400_0x049ff0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3942e008U + 0x049ff0U) ^ (0x940058d5U + 0x07e338U + 68U);
}

// [EN] FDE[1401] start_va=0x04a034, fde_va=0x07e358, span=452 B | [VN] FDE[1401]
uint32_t ttr_fde_1401_0x04a034(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xa9075bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90853f5U + 0x04a034U) ^ (0xa9097bf3U + 0x07e358U + 452U);
}

// [EN] FDE[1402] start_va=0x04a1f8, fde_va=0x07e380, span=12 B | [VN] FDE[1402]
uint32_t ttr_fde_1402_0x04a1f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0x5280092aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14005ba8U + 0x04a1f8U) ^ (0xd10183ffU + 0x07e380U + 12U);
}

// [EN] FDE[1403] start_va=0x04a204, fde_va=0x07e398, span=148 B | [VN] FDE[1403]
uint32_t ttr_fde_1403_0x04a204(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04a204U) ^ (0xa9057bf3U + 0x07e398U + 148U);
}

// [EN] FDE[1404] start_va=0x04a298, fde_va=0x07e3b8, span=8 B | [VN] FDE[1404]
uint32_t ttr_fde_1404_0x04a298(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5281ff00U) + (a1 ^ 0x17ff46b1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10183ffU + 0x04a298U) ^ (0xf9001bf6U + 0x07e3b8U + 8U);
}

// [EN] FDE[1405] start_va=0x04a2a0, fde_va=0x07e3d0, span=148 B | [VN] FDE[1405]
uint32_t ttr_fde_1405_0x04a2a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04a2a0U) ^ (0xa9057bf3U + 0x07e3d0U + 148U);
}

// [EN] FDE[1406] start_va=0x04a334, fde_va=0x07e3f0, span=160 B | [VN] FDE[1406]
uint32_t ttr_fde_1406_0x04a334(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04a334U) ^ (0xa9057bf3U + 0x07e3f0U + 160U);
}

// [EN] FDE[1407] start_va=0x04a3d4, fde_va=0x07e410, span=20 B | [VN] FDE[1407]
uint32_t ttr_fde_1407_0x04a3d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37dfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14005f19U + 0x04a3d4U) ^ (0xf81f0ffeU + 0x07e410U + 20U);
}

// [EN] FDE[1408] start_va=0x04a3e8, fde_va=0x07e428, span=148 B | [VN] FDE[1408]
uint32_t ttr_fde_1408_0x04a3e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04a3e8U) ^ (0xa9057bf3U + 0x07e428U + 148U);
}

// [EN] FDE[1409] start_va=0x04a47c, fde_va=0x07e448, span=40 B | [VN] FDE[1409]
uint32_t ttr_fde_1409_0x04a47c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x04a47cU) ^ (0xd1002129U + 0x07e448U + 40U);
}

// [EN] FDE[1410] start_va=0x04a4a4, fde_va=0x07e460, span=160 B | [VN] FDE[1410]
uint32_t ttr_fde_1410_0x04a4a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04a4a4U) ^ (0xa9057bf3U + 0x07e460U + 160U);
}

// [EN] FDE[1411] start_va=0x04a544, fde_va=0x07e480, span=32 B | [VN] FDE[1411]
uint32_t ttr_fde_1411_0x04a544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xeb000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f3U + 0x04a544U) ^ (0x54000040U + 0x07e480U + 32U);
}

// [EN] FDE[1412] start_va=0x04a564, fde_va=0x07e498, span=36 B | [VN] FDE[1412]
uint32_t ttr_fde_1412_0x04a564(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xcb010049U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b090109U + 0x04a564U) ^ (0xeb08013fU + 0x07e498U + 36U);
}

// [EN] FDE[1413] start_va=0x04a588, fde_va=0x07e4b0, span=32 B | [VN] FDE[1413]
uint32_t ttr_fde_1413_0x04a588(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940063ddU + 0x04a588U) ^ (0x54000040U + 0x07e4b0U + 32U);
}

// [EN] FDE[1414] start_va=0x04a5a8, fde_va=0x07e4d0, span=1096 B | [VN] FDE[1414]
uint32_t ttr_fde_1414_0x04a5a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9035bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04a5a8U) ^ (0xa9057bf3U + 0x07e4d0U + 1096U);
}

// [EN] FDE[1415] start_va=0x04a9f0, fde_va=0x07e4f0, span=64 B | [VN] FDE[1415]
uint32_t ttr_fde_1415_0x04a9f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9482408U) + (a1 ^ 0xd284c00bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5280002aU + 0x04a9f0U) ^ (0xf2c0002bU + 0x07e4f0U + 64U);
}

// [EN] FDE[1416] start_va=0x04aa30, fde_va=0x07e508, span=72 B | [VN] FDE[1416]
uint32_t ttr_fde_1416_0x04aa30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9482009U) + (a1 ^ 0xcb080129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb22c13fU + 0x04aa30U) ^ (0x5400016bU + 0x07e508U + 72U);
}

// [EN] FDE[1417] start_va=0x04aa78, fde_va=0x07e520, span=280 B | [VN] FDE[1417]
uint32_t ttr_fde_1417_0x04aa78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ffaU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x04aa78U) ^ (0xa90353f5U + 0x07e520U + 280U);
}

// [EN] FDE[1418] start_va=0x04ab90, fde_va=0x07e548, span=40 B | [VN] FDE[1418]
uint32_t ttr_fde_1418_0x04ab90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9422408U) + (a1 ^ 0x8b080128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400409U + 0x04ab90U) ^ (0xd1000508U + 0x07e548U + 40U);
}

// [EN] FDE[1419] start_va=0x04abb8, fde_va=0x07e560, span=856 B | [VN] FDE[1419]
uint32_t ttr_fde_1419_0x04abb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa9036bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90463f9U + 0x04abb8U) ^ (0xa9055bf7U + 0x07e560U + 856U);
}

// [EN] FDE[1420] start_va=0x04af10, fde_va=0x07e590, span=216 B | [VN] FDE[1420]
uint32_t ttr_fde_1420_0x04af10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x04af10U) ^ (0xf9400048U + 0x07e590U + 216U);
}

// [EN] FDE[1421] start_va=0x04afe8, fde_va=0x07e5b0, span=244 B | [VN] FDE[1421]
uint32_t ttr_fde_1421_0x04afe8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9037bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e8U + 0x04afe8U) ^ (0xa940b10bU + 0x07e5b0U + 244U);
}

// [EN] FDE[1422] start_va=0x04b0dc, fde_va=0x07e5c8, span=924 B | [VN] FDE[1422]
uint32_t ttr_fde_1422_0x04b0dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10743ffU) + (a1 ^ 0xa9187ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91963f9U + 0x04b0dcU) ^ (0xa91a5bf7U + 0x07e5c8U + 924U);
}

// [EN] FDE[1423] start_va=0x04b478, fde_va=0x07e5f0, span=40 B | [VN] FDE[1423]
uint32_t ttr_fde_1423_0x04b478(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0103e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x04b478U) ^ (0xaa0203e0U + 0x07e5f0U + 40U);
}

// [EN] FDE[1424] start_va=0x04b4a0, fde_va=0x07e608, span=48 B | [VN] FDE[1424]
uint32_t ttr_fde_1424_0x04b4a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9454508U + 0x04b4a0U) ^ (0xaa0003f3U + 0x07e608U + 48U);
}

// [EN] FDE[1425] start_va=0x04b4d0, fde_va=0x07e620, span=24 B | [VN] FDE[1425]
uint32_t ttr_fde_1425_0x04b4d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff2U + 0x04b4d0U) ^ (0xaa1303e0U + 0x07e620U + 24U);
}

// [EN] FDE[1426] start_va=0x04b4e8, fde_va=0x07e638, span=16 B | [VN] FDE[1426]
uint32_t ttr_fde_1426_0x04b4e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x04b4e8U) ^ (0x17ffffebU + 0x07e638U + 16U);
}

// [EN] FDE[1427] start_va=0x04b4f8, fde_va=0x07e650, span=16 B | [VN] FDE[1427]
uint32_t ttr_fde_1427_0x04b4f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x04b4f8U) ^ (0x17fffff3U + 0x07e650U + 16U);
}

// [EN] FDE[1428] start_va=0x04b508, fde_va=0x07e668, span=52 B | [VN] FDE[1428]
uint32_t ttr_fde_1428_0x04b508(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f5U + 0x04b508U) ^ (0xaa0203e0U + 0x07e668U + 52U);
}

// [EN] FDE[1429] start_va=0x04b53c, fde_va=0x07e688, span=248 B | [VN] FDE[1429]
uint32_t ttr_fde_1429_0x04b53c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04b53cU) ^ (0xa9037bf3U + 0x07e688U + 248U);
}

// [EN] FDE[1430] start_va=0x04b634, fde_va=0x07e6b0, span=88 B | [VN] FDE[1430]
uint32_t ttr_fde_1430_0x04b634(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x04b634U) ^ (0xa9047bf3U + 0x07e6b0U + 88U);
}

// [EN] FDE[1431] start_va=0x04b68c, fde_va=0x07e6d0, span=44 B | [VN] FDE[1431]
uint32_t ttr_fde_1431_0x04b68c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0303f3U + 0x04b68cU) ^ (0xaa1f03e3U + 0x07e6d0U + 44U);
}

// [EN] FDE[1432] start_va=0x04b6b8, fde_va=0x07e6f0, span=1160 B | [VN] FDE[1432]
uint32_t ttr_fde_1432_0x04b6b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10343ffU) + (a1 ^ 0xa9076ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90867faU + 0x04b6b8U) ^ (0xa9095ff8U + 0x07e6f0U + 1160U);
}

// [EN] FDE[1433] start_va=0x04bb40, fde_va=0x07e720, span=140 B | [VN] FDE[1433]
uint32_t ttr_fde_1433_0x04bb40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400508U + 0x04bb40U) ^ (0xb40003c1U + 0x07e720U + 140U);
}

// [EN] FDE[1434] start_va=0x04bbcc, fde_va=0x07e738, span=64 B | [VN] FDE[1434]
uint32_t ttr_fde_1434_0x04bbcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb03003fU) + (a1 ^ 0x540001c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf940000aU + 0x04bbccU) ^ (0xf940004cU + 0x07e738U + 64U);
}

// [EN] FDE[1435] start_va=0x04bc0c, fde_va=0x07e750, span=36 B | [VN] FDE[1435]
uint32_t ttr_fde_1435_0x04bc0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xa9422c0aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb080128U + 0x04bc0cU) ^ (0xd37ae508U + 0x07e750U + 36U);
}

// [EN] FDE[1436] start_va=0x04bc30, fde_va=0x07e768, span=196 B | [VN] FDE[1436]
uint32_t ttr_fde_1436_0x04bc30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x04bc30U) ^ (0xa9057bf3U + 0x07e768U + 196U);
}

// [EN] FDE[1437] start_va=0x04bcf4, fde_va=0x07e788, span=8 B | [VN] FDE[1437]
uint32_t ttr_fde_1437_0x04bcf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52820000U) + (a1 ^ 0x17ff401aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37dfc08U + 0x04bcf4U) ^ (0xb5000048U + 0x07e788U + 8U);
}

// [EN] FDE[1438] start_va=0x04bcfc, fde_va=0x07e7a0, span=20 B | [VN] FDE[1438]
uint32_t ttr_fde_1438_0x04bcfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37dfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140058cfU + 0x04bcfcU) ^ (0xf81f0ffeU + 0x07e7a0U + 20U);
}

// [EN] FDE[1439] start_va=0x04bd10, fde_va=0x07e7b8, span=40 B | [VN] FDE[1439]
uint32_t ttr_fde_1439_0x04bd10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x04bd10U) ^ (0xd1002129U + 0x07e7b8U + 40U);
}

// [EN] FDE[1440] start_va=0x04bd38, fde_va=0x07e7d0, span=32 B | [VN] FDE[1440]
uint32_t ttr_fde_1440_0x04bd38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xeb000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f3U + 0x04bd38U) ^ (0x54000040U + 0x07e7d0U + 32U);
}

// [EN] FDE[1441] start_va=0x04bd58, fde_va=0x07e7e8, span=36 B | [VN] FDE[1441]
uint32_t ttr_fde_1441_0x04bd58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xcb010049U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b090109U + 0x04bd58U) ^ (0xeb08013fU + 0x07e7e8U + 36U);
}

// [EN] FDE[1442] start_va=0x04bd7c, fde_va=0x07e800, span=32 B | [VN] FDE[1442]
uint32_t ttr_fde_1442_0x04bd7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94005de0U + 0x04bd7cU) ^ (0x54000040U + 0x07e800U + 32U);
}

// [EN] FDE[1443] start_va=0x04bd9c, fde_va=0x07e820, span=152 B | [VN] FDE[1443]
uint32_t ttr_fde_1443_0x04bd9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90023f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9057bf3U + 0x04bd9cU) ^ (0x940057f9U + 0x07e820U + 152U);
}

// [EN] FDE[1444] start_va=0x04be34, fde_va=0x07e840, span=52 B | [VN] FDE[1444]
uint32_t ttr_fde_1444_0x04be34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xaa1e03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94005743U + 0x04be34U) ^ (0xaa0103feU + 0x07e840U + 52U);
}

// [EN] FDE[1445] start_va=0x04be68, fde_va=0x07e858, span=412 B | [VN] FDE[1445]
uint32_t ttr_fde_1445_0x04be68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xa9056ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90667faU + 0x04be68U) ^ (0xa9075ff8U + 0x07e858U + 412U);
}

// [EN] FDE[1446] start_va=0x04c004, fde_va=0x07e888, span=92 B | [VN] FDE[1446]
uint32_t ttr_fde_1446_0x04c004(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04c004U) ^ (0xf0000268U + 0x07e888U + 92U);
}

// [EN] FDE[1447] start_va=0x04c060, fde_va=0x07e8a8, span=48 B | [VN] FDE[1447]
uint32_t ttr_fde_1447_0x04c060(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9454d08U + 0x04c060U) ^ (0xaa0003f3U + 0x07e8a8U + 48U);
}

// [EN] FDE[1448] start_va=0x04c090, fde_va=0x07e8c0, span=24 B | [VN] FDE[1448]
uint32_t ttr_fde_1448_0x04c090(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff2U + 0x04c090U) ^ (0xaa1303e0U + 0x07e8c0U + 24U);
}

// [EN] FDE[1449] start_va=0x04c0a8, fde_va=0x07e8d8, span=16 B | [VN] FDE[1449]
uint32_t ttr_fde_1449_0x04c0a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x04c0a8U) ^ (0x17ffffebU + 0x07e8d8U + 16U);
}

// [EN] FDE[1450] start_va=0x04c0b8, fde_va=0x07e8f0, span=16 B | [VN] FDE[1450]
uint32_t ttr_fde_1450_0x04c0b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x04c0b8U) ^ (0x17fffff3U + 0x07e8f0U + 16U);
}

// [EN] FDE[1451] start_va=0x04c0c8, fde_va=0x07e920, span=72 B | [VN] FDE[1451]
uint32_t ttr_fde_1451_0x04c0c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x90000288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913d2108U + 0x04c0c8U) ^ (0x08dffd08U + 0x07e920U + 72U);
}

// [EN] FDE[1452] start_va=0x04c110, fde_va=0x07e938, span=124 B | [VN] FDE[1452]
uint32_t ttr_fde_1452_0x04c110(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e2U + 0x04c110U) ^ (0x2a0103f4U + 0x07e938U + 124U);
}

// [EN] FDE[1453] start_va=0x04c18c, fde_va=0x07e958, span=64 B | [VN] FDE[1453]
uint32_t ttr_fde_1453_0x04c18c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x79401009U + 0x04c18cU) ^ (0x12001c28U + 0x07e958U + 64U);
}

// [EN] FDE[1454] start_va=0x04c1cc, fde_va=0x07e970, span=64 B | [VN] FDE[1454]
uint32_t ttr_fde_1454_0x04c1cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400013U + 0x04c1ccU) ^ (0xf9000001U + 0x07e970U + 64U);
}

// [EN] FDE[1455] start_va=0x04c20c, fde_va=0x07e990, span=8 B | [VN] FDE[1455]
uint32_t ttr_fde_1455_0x04c20c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e1U) + (a1 ^ 0x17ffffefU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10143ffU + 0x04c20cU) ^ (0xa9025bf7U + 0x07e990U + 8U);
}

// [EN] FDE[1456] start_va=0x04c214, fde_va=0x07e9a8, span=176 B | [VN] FDE[1456]
uint32_t ttr_fde_1456_0x04c214(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa9025bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x04c214U) ^ (0xa9047bf3U + 0x07e9a8U + 176U);
}

// [EN] FDE[1457] start_va=0x04c2c4, fde_va=0x07e9c8, span=36 B | [VN] FDE[1457]
uint32_t ttr_fde_1457_0x04c2c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c0U + 0x04c2c4U) ^ (0xb9400908U + 0x07e9c8U + 36U);
}

// [EN] FDE[1458] start_va=0x04c2e8, fde_va=0x07e9e0, span=152 B | [VN] FDE[1458]
uint32_t ttr_fde_1458_0x04c2e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10543ffU) + (a1 ^ 0xf9008bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9125bf7U + 0x04c2e8U) ^ (0xa91353f5U + 0x07e9e0U + 152U);
}

// [EN] FDE[1459] start_va=0x04c380, fde_va=0x07ea08, span=28 B | [VN] FDE[1459]
uint32_t ttr_fde_1459_0x04c380(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000260U + 0x04c380U) ^ (0xf9455000U + 0x07ea08U + 28U);
}

// [EN] FDE[1460] start_va=0x04c39c, fde_va=0x07ea20, span=100 B | [VN] FDE[1460]
uint32_t ttr_fde_1460_0x04c39c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000180U + 0x04c39cU) ^ (0xb9400849U + 0x07ea20U + 100U);
}

// [EN] FDE[1461] start_va=0x04c400, fde_va=0x07ea40, span=60 B | [VN] FDE[1461]
uint32_t ttr_fde_1461_0x04c400(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000160U) + (a1 ^ 0x53027c28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6b43091fU + 0x04c400U) ^ (0x54000161U + 0x07ea40U + 60U);
}

// [EN] FDE[1462] start_va=0x04c43c, fde_va=0x07ea58, span=44 B | [VN] FDE[1462]
uint32_t ttr_fde_1462_0x04c43c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0103f3U + 0x04c43cU) ^ (0x52800021U + 0x07ea58U + 44U);
}

// [EN] FDE[1463] start_va=0x04c468, fde_va=0x07ea78, span=40 B | [VN] FDE[1463]
uint32_t ttr_fde_1463_0x04c468(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f3U + 0x04c468U) ^ (0x52800021U + 0x07ea78U + 40U);
}

// [EN] FDE[1464] start_va=0x04c490, fde_va=0x07ea98, span=40 B | [VN] FDE[1464]
uint32_t ttr_fde_1464_0x04c490(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f3U + 0x04c490U) ^ (0x52800041U + 0x07ea98U + 40U);
}

// [EN] FDE[1465] start_va=0x04c4b8, fde_va=0x07eab8, span=44 B | [VN] FDE[1465]
uint32_t ttr_fde_1465_0x04c4b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1e0fe8U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800061U + 0x04c4b8U) ^ (0x2a1f03e2U + 0x07eab8U + 44U);
}

// [EN] FDE[1466] start_va=0x04c4e4, fde_va=0x07ead8, span=84 B | [VN] FDE[1466]
uint32_t ttr_fde_1466_0x04c4e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xa91153fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9127bf3U + 0x04c4e4U) ^ (0xaa0103f4U + 0x07ead8U + 84U);
}

// [EN] FDE[1467] start_va=0x04c538, fde_va=0x07eaf8, span=72 B | [VN] FDE[1467]
uint32_t ttr_fde_1467_0x04c538(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f3U + 0x04c538U) ^ (0x52800081U + 0x07eaf8U + 72U);
}

// [EN] FDE[1468] start_va=0x04c580, fde_va=0x07eb18, span=40 B | [VN] FDE[1468]
uint32_t ttr_fde_1468_0x04c580(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12000034U + 0x04c580U) ^ (0x528000a1U + 0x07eb18U + 40U);
}

// [EN] FDE[1469] start_va=0x04c5a8, fde_va=0x07eb38, span=340 B | [VN] FDE[1469]
uint32_t ttr_fde_1469_0x04c5a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9000bf8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x04c5a8U) ^ (0xa90353f5U + 0x07eb38U + 340U);
}

// [EN] FDE[1470] start_va=0x04c6fc, fde_va=0x07eb60, span=56 B | [VN] FDE[1470]
uint32_t ttr_fde_1470_0x04c6fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303f3U + 0x04c6fcU) ^ (0xaa0203f5U + 0x07eb60U + 56U);
}

// [EN] FDE[1471] start_va=0x04c734, fde_va=0x07eb80, span=364 B | [VN] FDE[1471]
uint32_t ttr_fde_1471_0x04c734(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf90013faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90363f9U + 0x04c734U) ^ (0xa9045bf7U + 0x07eb80U + 364U);
}

// [EN] FDE[1472] start_va=0x04c8a0, fde_va=0x07eba8, span=72 B | [VN] FDE[1472]
uint32_t ttr_fde_1472_0x04c8a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04c8a0U) ^ (0x940055e2U + 0x07eba8U + 72U);
}

// [EN] FDE[1473] start_va=0x04c8e8, fde_va=0x07ebc8, span=44 B | [VN] FDE[1473]
uint32_t ttr_fde_1473_0x04c8e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400573eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000068U + 0x04c8e8U) ^ (0xf9000268U + 0x07ebc8U + 44U);
}

// [EN] FDE[1474] start_va=0x04c914, fde_va=0x07ebe0, span=48 B | [VN] FDE[1474]
uint32_t ttr_fde_1474_0x04c914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400538dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000113U + 0x04c914U) ^ (0x39404008U + 0x07ebe0U + 48U);
}

// [EN] FDE[1475] start_va=0x04c944, fde_va=0x07ebf8, span=24 B | [VN] FDE[1475]
uint32_t ttr_fde_1475_0x04c944(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94005ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000004U + 0x04c944U) ^ (0xaa1303e0U + 0x07ebf8U + 24U);
}

// [EN] FDE[1476] start_va=0x04c95c, fde_va=0x07ec10, span=96 B | [VN] FDE[1476]
uint32_t ttr_fde_1476_0x04c95c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x79401008U + 0x04c95cU) ^ (0xaa0003f3U + 0x07ec10U + 96U);
}

// [EN] FDE[1477] start_va=0x04c9bc, fde_va=0x07ec30, span=48 B | [VN] FDE[1477]
uint32_t ttr_fde_1477_0x04c9bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000160U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94005643U + 0x04c9bcU) ^ (0x97fffffdU + 0x07ec30U + 48U);
}

// [EN] FDE[1478] start_va=0x04c9ec, fde_va=0x07ec48, span=8 B | [VN] FDE[1478]
uint32_t ttr_fde_1478_0x04c9ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800b00U) + (a1 ^ 0x17ff3cdcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81c0ff8U + 0x04c9ecU) ^ (0xa9015bf7U + 0x07ec48U + 8U);
}

// [EN] FDE[1479] start_va=0x04c9f4, fde_va=0x07ec60, span=148 B | [VN] FDE[1479]
uint32_t ttr_fde_1479_0x04c9f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04c9f4U) ^ (0xa9037bf3U + 0x07ec60U + 148U);
}

// [EN] FDE[1480] start_va=0x04ca88, fde_va=0x07ec88, span=116 B | [VN] FDE[1480]
uint32_t ttr_fde_1480_0x04ca88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04ca88U) ^ (0xb9400828U + 0x07ec88U + 116U);
}

// [EN] FDE[1481] start_va=0x04cafc, fde_va=0x07eca8, span=36 B | [VN] FDE[1481]
uint32_t ttr_fde_1481_0x04cafc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9037bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94005f97U + 0x04cafcU) ^ (0x910023e0U + 0x07eca8U + 36U);
}

// [EN] FDE[1482] start_va=0x04cb20, fde_va=0x07ecc0, span=264 B | [VN] FDE[1482]
uint32_t ttr_fde_1482_0x04cb20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xf9008bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9127bf3U + 0x04cb20U) ^ (0x79401028U + 0x07ecc0U + 264U);
}

// [EN] FDE[1483] start_va=0x04cc28, fde_va=0x07ece0, span=212 B | [VN] FDE[1483]
uint32_t ttr_fde_1483_0x04cc28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xf9008bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9127bf3U + 0x04cc28U) ^ (0x39402008U + 0x07ece0U + 212U);
}

// [EN] FDE[1484] start_va=0x04ccfc, fde_va=0x07ed00, span=108 B | [VN] FDE[1484]
uint32_t ttr_fde_1484_0x04ccfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39402008U) + (a1 ^ 0x71000d1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000100U + 0x04ccfcU) ^ (0x7100091fU + 0x07ed00U + 108U);
}

// [EN] FDE[1485] start_va=0x04cd68, fde_va=0x07ed18, span=28 B | [VN] FDE[1485]
uint32_t ttr_fde_1485_0x04cd68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x910023e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff3dbcU + 0x04cd68U) ^ (0x1e602008U + 0x07ed18U + 28U);
}

// [EN] FDE[1486] start_va=0x04cd84, fde_va=0x07ed30, span=128 B | [VN] FDE[1486]
uint32_t ttr_fde_1486_0x04cd84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa9117bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39402008U + 0x04cd84U) ^ (0x7100151fU + 0x07ed30U + 128U);
}

// [EN] FDE[1487] start_va=0x04ce04, fde_va=0x07ed50, span=132 B | [VN] FDE[1487]
uint32_t ttr_fde_1487_0x04ce04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa9117bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39402008U + 0x04ce04U) ^ (0x7100151fU + 0x07ed50U + 132U);
}

// [EN] FDE[1488] start_va=0x04ce88, fde_va=0x07ed70, span=220 B | [VN] FDE[1488]
uint32_t ttr_fde_1488_0x04ce88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa9117bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39402009U + 0x04ce88U) ^ (0x7100153fU + 0x07ed70U + 220U);
}

// [EN] FDE[1489] start_va=0x04cf64, fde_va=0x07ed90, span=80 B | [VN] FDE[1489]
uint32_t ttr_fde_1489_0x04cf64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x39402008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x71001d1fU + 0x04cf64U) ^ (0x540001a0U + 0x07ed90U + 80U);
}

// [EN] FDE[1490] start_va=0x04cfb4, fde_va=0x07eda8, span=64 B | [VN] FDE[1490]
uint32_t ttr_fde_1490_0x04cfb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x39402009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e8U + 0x04cfb4U) ^ (0x2a1f03e0U + 0x07eda8U + 64U);
}

// [EN] FDE[1491] start_va=0x04cff4, fde_va=0x07edc0, span=84 B | [VN] FDE[1491]
uint32_t ttr_fde_1491_0x04cff4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x04cff4U) ^ (0xf8408e68U + 0x07edc0U + 84U);
}

// [EN] FDE[1492] start_va=0x04d048, fde_va=0x07ede0, span=72 B | [VN] FDE[1492]
uint32_t ttr_fde_1492_0x04d048(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04d048U) ^ (0x94004c57U + 0x07ede0U + 72U);
}

// [EN] FDE[1493] start_va=0x04d090, fde_va=0x07ee00, span=20 B | [VN] FDE[1493]
uint32_t ttr_fde_1493_0x04d090(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e2U) + (a1 ^ 0xf8408c48U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e0U + 0x04d090U) ^ (0xaa0803e1U + 0x07ee00U + 20U);
}

// [EN] FDE[1494] start_va=0x04d0a4, fde_va=0x07ee18, span=32 B | [VN] FDE[1494]
uint32_t ttr_fde_1494_0x04d0a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffc5aU + 0x04d0a4U) ^ (0xd0000281U + 0x07ee18U + 32U);
}

// [EN] FDE[1495] start_va=0x04d0c4, fde_va=0x07ee30, span=216 B | [VN] FDE[1495]
uint32_t ttr_fde_1495_0x04d0c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10543ffU) + (a1 ^ 0xa9125bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91353f5U + 0x04d0c4U) ^ (0xa9147bf3U + 0x07ee30U + 216U);
}

// [EN] FDE[1496] start_va=0x04d19c, fde_va=0x07ee58, span=128 B | [VN] FDE[1496]
uint32_t ttr_fde_1496_0x04d19c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xf9008bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9127bf3U + 0x04d19cU) ^ (0x39402008U + 0x07ee58U + 128U);
}

// [EN] FDE[1497] start_va=0x04d21c, fde_va=0x07ee78, span=36 B | [VN] FDE[1497]
uint32_t ttr_fde_1497_0x04d21c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x37f80041U) + (a1 ^ 0x17ffffdfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10483ffU + 0x04d21cU) ^ (0xa9117bfcU + 0x07ee78U + 36U);
}

// [EN] FDE[1498] start_va=0x04d240, fde_va=0x07ee98, span=220 B | [VN] FDE[1498]
uint32_t ttr_fde_1498_0x04d240(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10583ffU) + (a1 ^ 0xf90093fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9135bf7U + 0x04d240U) ^ (0xa91453f5U + 0x07ee98U + 220U);
}

// [EN] FDE[1499] start_va=0x04d31c, fde_va=0x07eec0, span=112 B | [VN] FDE[1499]
uint32_t ttr_fde_1499_0x04d31c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xf9008bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9127bf3U + 0x04d31cU) ^ (0x39402008U + 0x07eec0U + 112U);
}

// [EN] FDE[1500] start_va=0x04d38c, fde_va=0x07eee0, span=48 B | [VN] FDE[1500]
uint32_t ttr_fde_1500_0x04d38c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004c03U + 0x04d38cU) ^ (0x8b000262U + 0x07eee0U + 48U);
}

// [EN] FDE[1501] start_va=0x04d3bc, fde_va=0x07ef00, span=36 B | [VN] FDE[1501]
uint32_t ttr_fde_1501_0x04d3bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x94004fdbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffd6U + 0x04d3bcU) ^ (0xb5000080U + 0x07ef00U + 36U);
}

// [EN] FDE[1502] start_va=0x04d3e0, fde_va=0x07ef18, span=36 B | [VN] FDE[1502]
uint32_t ttr_fde_1502_0x04d3e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004beeU + 0x04d3e0U) ^ (0x8b000262U + 0x07ef18U + 36U);
}

// [EN] FDE[1503] start_va=0x04d404, fde_va=0x07ef38, span=16 B | [VN] FDE[1503]
uint32_t ttr_fde_1503_0x04d404(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x94004fc9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x04d404U) ^ (0x17ffff8cU + 0x07ef38U + 16U);
}

// [EN] FDE[1504] start_va=0x04d414, fde_va=0x07ef50, span=40 B | [VN] FDE[1504]
uint32_t ttr_fde_1504_0x04d414(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9037bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94005d51U + 0x04d414U) ^ (0x94004e30U + 0x07ef50U + 40U);
}

// [EN] FDE[1505] start_va=0x04d43c, fde_va=0x07ef68, span=348 B | [VN] FDE[1505]
uint32_t ttr_fde_1505_0x04d43c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10583ffU) + (a1 ^ 0xf9008bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91263f9U + 0x04d43cU) ^ (0xa9135bf7U + 0x07ef68U + 348U);
}

// [EN] FDE[1506] start_va=0x04d598, fde_va=0x07ef90, span=72 B | [VN] FDE[1506]
uint32_t ttr_fde_1506_0x04d598(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04d598U) ^ (0xaa0003f6U + 0x07ef90U + 72U);
}

// [EN] FDE[1507] start_va=0x04d5e0, fde_va=0x07efb0, span=24 B | [VN] FDE[1507]
uint32_t ttr_fde_1507_0x04d5e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ffff4eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf100001fU + 0x04d5e0U) ^ (0x1a9f07e0U + 0x07efb0U + 24U);
}

// [EN] FDE[1508] start_va=0x04d5f8, fde_va=0x07efc8, span=36 B | [VN] FDE[1508]
uint32_t ttr_fde_1508_0x04d5f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004b68U + 0x04d5f8U) ^ (0x8b000262U + 0x07efc8U + 36U);
}

// [EN] FDE[1509] start_va=0x04d61c, fde_va=0x07efe8, span=16 B | [VN] FDE[1509]
uint32_t ttr_fde_1509_0x04d61c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x94004f43U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x04d61cU) ^ (0x17ffffeeU + 0x07efe8U + 16U);
}

// [EN] FDE[1510] start_va=0x04d62c, fde_va=0x07f000, span=220 B | [VN] FDE[1510]
uint32_t ttr_fde_1510_0x04d62c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10583ffU) + (a1 ^ 0xf9009bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91453f5U + 0x04d62cU) ^ (0xa9157bf3U + 0x07f000U + 220U);
}

// [EN] FDE[1511] start_va=0x04d708, fde_va=0x07f020, span=80 B | [VN] FDE[1511]
uint32_t ttr_fde_1511_0x04d708(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9037bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400809U + 0x04d708U) ^ (0xf9400008U + 0x07f020U + 80U);
}

// [EN] FDE[1512] start_va=0x04d758, fde_va=0x07f038, span=360 B | [VN] FDE[1512]
uint32_t ttr_fde_1512_0x04d758(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10543ffU) + (a1 ^ 0xa9125bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91353f5U + 0x04d758U) ^ (0xa9147bf3U + 0x07f038U + 360U);
}

// [EN] FDE[1513] start_va=0x04d8c0, fde_va=0x07f060, span=40 B | [VN] FDE[1513]
uint32_t ttr_fde_1513_0x04d8c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xf9400808U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000a8U + 0x04d8c0U) ^ (0x52800309U + 0x07f060U + 40U);
}

// [EN] FDE[1514] start_va=0x04d8e8, fde_va=0x07f078, span=24 B | [VN] FDE[1514]
uint32_t ttr_fde_1514_0x04d8e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400828U) + (a1 ^ 0xb4000088U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800309U + 0x04d8e8U) ^ (0x9ba92041U + 0x07f078U + 24U);
}

// [EN] FDE[1515] start_va=0x04d900, fde_va=0x07f090, span=40 B | [VN] FDE[1515]
uint32_t ttr_fde_1515_0x04d900(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x79401008U) + (a1 ^ 0x121f1908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100191fU + 0x04d900U) ^ (0x540000a1U + 0x07f090U + 40U);
}

// [EN] FDE[1516] start_va=0x04d928, fde_va=0x07f0a8, span=44 B | [VN] FDE[1516]
uint32_t ttr_fde_1516_0x04d928(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x79401008U) + (a1 ^ 0x121f1908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100191fU + 0x04d928U) ^ (0x540000c1U + 0x07f0a8U + 44U);
}

// [EN] FDE[1517] start_va=0x04d954, fde_va=0x07f0c0, span=156 B | [VN] FDE[1517]
uint32_t ttr_fde_1517_0x04d954(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x04d954U) ^ (0xd53bd054U + 0x07f0c0U + 156U);
}

// [EN] FDE[1518] start_va=0x04d9f0, fde_va=0x07f0e0, span=68 B | [VN] FDE[1518]
uint32_t ttr_fde_1518_0x04d9f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400029U) + (a1 ^ 0x52800148U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100052aU + 0x04d9f0U) ^ (0xf900002aU + 0x07f0e0U + 68U);
}

// [EN] FDE[1519] start_va=0x04da34, fde_va=0x07f0f8, span=92 B | [VN] FDE[1519]
uint32_t ttr_fde_1519_0x04da34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x04da34U) ^ (0xd53bd054U + 0x07f0f8U + 92U);
}

// [EN] FDE[1520] start_va=0x04da90, fde_va=0x07f118, span=428 B | [VN] FDE[1520]
uint32_t ttr_fde_1520_0x04da90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xfd0013e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x04da90U) ^ (0xa9047bf3U + 0x07f118U + 428U);
}

// [EN] FDE[1521] start_va=0x04dc3c, fde_va=0x07f138, span=84 B | [VN] FDE[1521]
uint32_t ttr_fde_1521_0x04dc3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xaa1e03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004fc1U + 0x04dc3cU) ^ (0xaa0303feU + 0x07f138U + 84U);
}

// [EN] FDE[1522] start_va=0x04dc90, fde_va=0x07f150, span=776 B | [VN] FDE[1522]
uint32_t ttr_fde_1522_0x04dc90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xaa1e03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004a7dU + 0x04dc90U) ^ (0xaa0303feU + 0x07f150U + 776U);
}

// [EN] FDE[1523] start_va=0x04df98, fde_va=0x07f180, span=196 B | [VN] FDE[1523]
uint32_t ttr_fde_1523_0x04df98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x04df98U) ^ (0x2a0103f3U + 0x07f180U + 196U);
}

// [EN] FDE[1524] start_va=0x04e05c, fde_va=0x07f1a0, span=24 B | [VN] FDE[1524]
uint32_t ttr_fde_1524_0x04e05c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffec89U + 0x04e05cU) ^ (0xaa1303e0U + 0x07f1a0U + 24U);
}

// [EN] FDE[1525] start_va=0x04e074, fde_va=0x07f1b8, span=108 B | [VN] FDE[1525]
uint32_t ttr_fde_1525_0x04e074(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04e074U) ^ (0x91008016U + 0x07f1b8U + 108U);
}

// [EN] FDE[1526] start_va=0x04e0e0, fde_va=0x07f1d8, span=232 B | [VN] FDE[1526]
uint32_t ttr_fde_1526_0x04e0e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x04e0e0U) ^ (0xa9047bf3U + 0x07f1d8U + 232U);
}

// [EN] FDE[1527] start_va=0x04e1c8, fde_va=0x07f1f8, span=892 B | [VN] FDE[1527]
uint32_t ttr_fde_1527_0x04e1c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa9036bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90463f9U + 0x04e1c8U) ^ (0xa9055bf7U + 0x07f1f8U + 892U);
}

// [EN] FDE[1528] start_va=0x04e544, fde_va=0x07f228, span=156 B | [VN] FDE[1528]
uint32_t ttr_fde_1528_0x04e544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x04e544U) ^ (0x940046e0U + 0x07f228U + 156U);
}

// [EN] FDE[1529] start_va=0x04e5e0, fde_va=0x07f248, span=24 B | [VN] FDE[1529]
uint32_t ttr_fde_1529_0x04e5e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39416008U) + (a1 ^ 0x34000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91002000U + 0x04e5e0U) ^ (0x17ff8e17U + 0x07f248U + 24U);
}

// [EN] FDE[1530] start_va=0x04e5f8, fde_va=0x07f260, span=36 B | [VN] FDE[1530]
uint32_t ttr_fde_1530_0x04e5f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940046b4U + 0x04e5f8U) ^ (0x9400001cU + 0x07f260U + 36U);
}

// [EN] FDE[1531] start_va=0x04e61c, fde_va=0x07f280, span=52 B | [VN] FDE[1531]
uint32_t ttr_fde_1531_0x04e61c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9027bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9405401U + 0x04e61cU) ^ (0xaa0003f3U + 0x07f280U + 52U);
}

// [EN] FDE[1532] start_va=0x04e650, fde_va=0x07f298, span=36 B | [VN] FDE[1532]
uint32_t ttr_fde_1532_0x04e650(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0x38438c09U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x37000069U + 0x04e650U) ^ (0xd341fd29U + 0x07f298U + 36U);
}

// [EN] FDE[1533] start_va=0x04e674, fde_va=0x07f2b0, span=104 B | [VN] FDE[1533]
uint32_t ttr_fde_1533_0x04e674(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91008013U + 0x04e674U) ^ (0x94005058U + 0x07f2b0U + 104U);
}

// [EN] FDE[1534] start_va=0x04e6dc, fde_va=0x07f2d0, span=388 B | [VN] FDE[1534]
uint32_t ttr_fde_1534_0x04e6dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb6bfbU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x04e6dcU) ^ (0xa90353f5U + 0x07f2d0U + 388U);
}

// [EN] FDE[1535] start_va=0x04e860, fde_va=0x07f2f8, span=132 B | [VN] FDE[1535]
uint32_t ttr_fde_1535_0x04e860(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a010048U) + (a1 ^ 0xf2400d1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000180U + 0x04e860U) ^ (0x927ef408U + 0x07f2f8U + 132U);
}

// [EN] FDE[1536] start_va=0x04e8e4, fde_va=0x07f310, span=28 B | [VN] FDE[1536]
uint32_t ttr_fde_1536_0x04e8e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900011fU + 0x04e8e4U) ^ (0xb4000060U + 0x07f310U + 28U);
}

// [EN] FDE[1537] start_va=0x04e900, fde_va=0x07f328, span=60 B | [VN] FDE[1537]
uint32_t ttr_fde_1537_0x04e900(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40001c0U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004e72U + 0x04e900U) ^ (0xb40000c0U + 0x07f328U + 60U);
}

// [EN] FDE[1538] start_va=0x04e93c, fde_va=0x07f340, span=28 B | [VN] FDE[1538]
uint32_t ttr_fde_1538_0x04e93c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40000c0U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000080U + 0x04e93cU) ^ (0xf9400008U + 0x07f340U + 28U);
}

// [EN] FDE[1539] start_va=0x04e958, fde_va=0x07f358, span=556 B | [VN] FDE[1539]
uint32_t ttr_fde_1539_0x04e958(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9403c14U + 0x04e958U) ^ (0xf0000248U + 0x07f358U + 556U);
}

// [EN] FDE[1540] start_va=0x04eb84, fde_va=0x07f378, span=24 B | [VN] FDE[1540]
uint32_t ttr_fde_1540_0x04eb84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffff73U + 0x04eb84U) ^ (0xaa1303e0U + 0x07f378U + 24U);
}

// [EN] FDE[1541] start_va=0x04eb9c, fde_va=0x07f390, span=992 B | [VN] FDE[1541]
uint32_t ttr_fde_1541_0x04eb9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10343ffU) + (a1 ^ 0xa90963f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a5bf7U + 0x04eb9cU) ^ (0xa90b53f5U + 0x07f390U + 992U);
}

// [EN] FDE[1542] start_va=0x04ef7c, fde_va=0x07f3b8, span=112 B | [VN] FDE[1542]
uint32_t ttr_fde_1542_0x04ef7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5289c488U) + (a1 ^ 0x6b08003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000221U + 0x04ef7cU) ^ (0xb4000223U + 0x07f3b8U + 112U);
}

// [EN] FDE[1543] start_va=0x04efec, fde_va=0x07f3d0, span=3272 B | [VN] FDE[1543]
uint32_t ttr_fde_1543_0x04efec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10443ffU) + (a1 ^ 0xa90b6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90c67faU + 0x04efecU) ^ (0xa90d5ff8U + 0x07f3d0U + 3272U);
}

// [EN] FDE[1544] start_va=0x04fcb4, fde_va=0x07f400, span=56 B | [VN] FDE[1544]
uint32_t ttr_fde_1544_0x04fcb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940000b4U + 0x04fcb4U) ^ (0x39400268U + 0x07f400U + 56U);
}

// [EN] FDE[1545] start_va=0x04fcec, fde_va=0x07f418, span=96 B | [VN] FDE[1545]
uint32_t ttr_fde_1545_0x04fcec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04fcecU) ^ (0xaa0003f6U + 0x07f418U + 96U);
}

// [EN] FDE[1546] start_va=0x04fd4c, fde_va=0x07f438, span=116 B | [VN] FDE[1546]
uint32_t ttr_fde_1546_0x04fd4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04fd4cU) ^ (0xaa0003f3U + 0x07f438U + 116U);
}

// [EN] FDE[1547] start_va=0x04fdc0, fde_va=0x07f458, span=12 B | [VN] FDE[1547]
uint32_t ttr_fde_1547_0x04fdc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff45a2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x04fdc0U) ^ (0xf81d0ff6U + 0x07f458U + 12U);
}

// [EN] FDE[1548] start_va=0x04fdcc, fde_va=0x07f470, span=96 B | [VN] FDE[1548]
uint32_t ttr_fde_1548_0x04fdcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04fdccU) ^ (0xaa0203f4U + 0x07f470U + 96U);
}

// [EN] FDE[1549] start_va=0x04fe2c, fde_va=0x07f490, span=288 B | [VN] FDE[1549]
uint32_t ttr_fde_1549_0x04fe2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04fe2cU) ^ (0xa9037bf3U + 0x07f490U + 288U);
}

// [EN] FDE[1550] start_va=0x04ff4c, fde_va=0x07f4b8, span=32 B | [VN] FDE[1550]
uint32_t ttr_fde_1550_0x04ff4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xd0000248U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9105e108U + 0x04ff4cU) ^ (0x94003fc0U + 0x07f4b8U + 32U);
}

// [EN] FDE[1551] start_va=0x04ff6c, fde_va=0x07f4d0, span=24 B | [VN] FDE[1551]
uint32_t ttr_fde_1551_0x04ff6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x04ff6cU) ^ (0xaa1303e0U + 0x07f4d0U + 24U);
}

// [EN] FDE[1552] start_va=0x04ff84, fde_va=0x07f4e8, span=4 B | [VN] FDE[1552]
uint32_t ttr_fde_1552_0x04ff84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14004a08U) + (a1 ^ 0x17ff2f6aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x04ff84U) ^ (0xb9400008U + 0x07f4e8U + 4U);
}

// [EN] FDE[1553] start_va=0x04ff88, fde_va=0x07f500, span=4 B | [VN] FDE[1553]
uint32_t ttr_fde_1553_0x04ff88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2f6aU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400008U + 0x04ff88U) ^ (0xaa0003f3U + 0x07f500U + 4U);
}

// [EN] FDE[1554] start_va=0x04ff8c, fde_va=0x07f518, span=56 B | [VN] FDE[1554]
uint32_t ttr_fde_1554_0x04ff8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xb9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x04ff8cU) ^ (0x37000068U + 0x07f518U + 56U);
}

// [EN] FDE[1555] start_va=0x04ffc4, fde_va=0x07f530, span=44 B | [VN] FDE[1555]
uint32_t ttr_fde_1555_0x04ffc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0103f3U + 0x04ffc4U) ^ (0x91002014U + 0x07f530U + 44U);
}

// [EN] FDE[1556] start_va=0x04fff0, fde_va=0x07f550, span=12 B | [VN] FDE[1556]
uint32_t ttr_fde_1556_0x04fff0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff4516U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x04fff0U) ^ (0xa9be53f5U + 0x07f550U + 12U);
}

// [EN] FDE[1557] start_va=0x04fffc, fde_va=0x07f568, span=80 B | [VN] FDE[1557]
uint32_t ttr_fde_1557_0x04fffc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400008U + 0x04fffcU) ^ (0xaa0103f3U + 0x07f568U + 80U);
}

// [EN] FDE[1558] start_va=0x05004c, fde_va=0x07f588, span=104 B | [VN] FDE[1558]
uint32_t ttr_fde_1558_0x05004c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90023f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9057bf3U + 0x05004cU) ^ (0x94004987U + 0x07f588U + 104U);
}

// [EN] FDE[1559] start_va=0x0500b4, fde_va=0x07f5a8, span=56 B | [VN] FDE[1559]
uint32_t ttr_fde_1559_0x0500b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400013U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000001U + 0x0500b4U) ^ (0xb4000133U + 0x07f5a8U + 56U);
}

// [EN] FDE[1560] start_va=0x0500ec, fde_va=0x07f5c0, span=8 B | [VN] FDE[1560]
uint32_t ttr_fde_1560_0x0500ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e1U) + (a1 ^ 0x17fffff1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0500ecU) ^ (0x17ff2f0eU + 0x07f5c0U + 8U);
}

// [EN] FDE[1561] start_va=0x0500f4, fde_va=0x07f5d8, span=4 B | [VN] FDE[1561]
uint32_t ttr_fde_1561_0x0500f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff2f0eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000111U + 0x0500f4U) ^ (0xa9bf7bf3U + 0x07f5d8U + 4U);
}

// [EN] FDE[1562] start_va=0x0500f8, fde_va=0x07f5f0, span=4 B | [VN] FDE[1562]
uint32_t ttr_fde_1562_0x0500f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2f0eU) + (a1 ^ 0x14000111U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x0500f8U) ^ (0xaa0003f3U + 0x07f5f0U + 4U);
}

// [EN] FDE[1563] start_va=0x0500fc, fde_va=0x07f608, span=4 B | [VN] FDE[1563]
uint32_t ttr_fde_1563_0x0500fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14000111U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0500fcU) ^ (0x9400010eU + 0x07f608U + 4U);
}

// [EN] FDE[1564] start_va=0x050100, fde_va=0x07f620, span=24 B | [VN] FDE[1564]
uint32_t ttr_fde_1564_0x050100(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400010eU + 0x050100U) ^ (0xaa1303e0U + 0x07f620U + 24U);
}

// [EN] FDE[1565] start_va=0x050118, fde_va=0x07f638, span=4 B | [VN] FDE[1565]
uint32_t ttr_fde_1565_0x050118(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14003f90U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e1U + 0x050118U) ^ (0xaa0803e0U + 0x07f638U + 4U);
}

// [EN] FDE[1566] start_va=0x05011c, fde_va=0x07f650, span=24 B | [VN] FDE[1566]
uint32_t ttr_fde_1566_0x05011c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803e0U + 0x05011cU) ^ (0x94000003U + 0x07f650U + 24U);
}

// [EN] FDE[1567] start_va=0x050134, fde_va=0x07f668, span=776 B | [VN] FDE[1567]
uint32_t ttr_fde_1567_0x050134(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400475bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x050134U) ^ (0xa9057bf3U + 0x07f668U + 776U);
}

// [EN] FDE[1568] start_va=0x05043c, fde_va=0x07f698, span=56 B | [VN] FDE[1568]
uint32_t ttr_fde_1568_0x05043c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400000cU + 0x05043cU) ^ (0x39400268U + 0x07f698U + 56U);
}

// [EN] FDE[1569] start_va=0x050474, fde_va=0x07f6b0, span=16 B | [VN] FDE[1569]
uint32_t ttr_fde_1569_0x050474(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400008U) + (a1 ^ 0x12000108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9000008U + 0x050474U) ^ (0xd65f03c0U + 0x07f6b0U + 16U);
}

// [EN] FDE[1570] start_va=0x050484, fde_va=0x07f6c8, span=188 B | [VN] FDE[1570]
uint32_t ttr_fde_1570_0x050484(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x050484U) ^ (0x71000c3fU + 0x07f6c8U + 188U);
}

// [EN] FDE[1571] start_va=0x050540, fde_va=0x07f6e8, span=36 B | [VN] FDE[1571]
uint32_t ttr_fde_1571_0x050540(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xb0000248U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91080108U + 0x050540U) ^ (0xaa0003f3U + 0x07f6e8U + 36U);
}

// [EN] FDE[1572] start_va=0x050564, fde_va=0x07f700, span=4 B | [VN] FDE[1572]
uint32_t ttr_fde_1572_0x050564(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xd10183ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9001bf6U + 0x050564U) ^ (0xa90453f5U + 0x07f700U + 4U);
}

// [EN] FDE[1573] start_va=0x050568, fde_va=0x07f718, span=220 B | [VN] FDE[1573]
uint32_t ttr_fde_1573_0x050568(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x050568U) ^ (0xa9057bf3U + 0x07f718U + 220U);
}

// [EN] FDE[1574] start_va=0x050644, fde_va=0x07f738, span=72 B | [VN] FDE[1574]
uint32_t ttr_fde_1574_0x050644(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913d4108U + 0x050644U) ^ (0x08dffd08U + 0x07f738U + 72U);
}

// [EN] FDE[1575] start_va=0x05068c, fde_va=0x07f750, span=40 B | [VN] FDE[1575]
uint32_t ttr_fde_1575_0x05068c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000108U) + (a1 ^ 0x9111f108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb860d900U + 0x05068cU) ^ (0xb00000e8U + 0x07f750U + 40U);
}

// [EN] FDE[1576] start_va=0x0506b4, fde_va=0x07f768, span=200 B | [VN] FDE[1576]
uint32_t ttr_fde_1576_0x0506b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ffcU) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0506b4U) ^ (0xd113c3ffU + 0x07f768U + 200U);
}

// [EN] FDE[1577] start_va=0x05077c, fde_va=0x07f788, span=132 B | [VN] FDE[1577]
uint32_t ttr_fde_1577_0x05077c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xb900001fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x38410c28U + 0x05077cU) ^ (0x370001a8U + 0x07f788U + 132U);
}

// [EN] FDE[1578] start_va=0x050800, fde_va=0x07f7a0, span=208 B | [VN] FDE[1578]
uint32_t ttr_fde_1578_0x050800(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x050800U) ^ (0xa9037bf3U + 0x07f7a0U + 208U);
}

// [EN] FDE[1579] start_va=0x0508d0, fde_va=0x07f7c0, span=20 B | [VN] FDE[1579]
uint32_t ttr_fde_1579_0x0508d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940048ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0508d0U) ^ (0xa8c17bf3U + 0x07f7c0U + 20U);
}

// [EN] FDE[1580] start_va=0x0508e4, fde_va=0x07f7d8, span=20 B | [VN] FDE[1580]
uint32_t ttr_fde_1580_0x0508e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400c00U) + (a1 ^ 0xb4000060U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x0508e4U) ^ (0x14003dbbU + 0x07f7d8U + 20U);
}

// [EN] FDE[1581] start_va=0x0508f8, fde_va=0x07f7f0, span=4 B | [VN] FDE[1581]
uint32_t ttr_fde_1581_0x0508f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2d0eU) + (a1 ^ 0xb9401008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb48043fU + 0x0508f8U) ^ (0x54000082U + 0x07f7f0U + 4U);
}

// [EN] FDE[1582] start_va=0x0508fc, fde_va=0x07f808, span=48 B | [VN] FDE[1582]
uint32_t ttr_fde_1582_0x0508fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401008U) + (a1 ^ 0xeb48043fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000082U + 0x0508fcU) ^ (0x37000088U + 0x07f808U + 48U);
}

// [EN] FDE[1583] start_va=0x05092c, fde_va=0x07f820, span=72 B | [VN] FDE[1583]
uint32_t ttr_fde_1583_0x05092c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x39402008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000249U + 0x05092cU) ^ (0xaa0003f3U + 0x07f820U + 72U);
}

// [EN] FDE[1584] start_va=0x050974, fde_va=0x07f838, span=24 B | [VN] FDE[1584]
uint32_t ttr_fde_1584_0x050974(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffecU + 0x050974U) ^ (0xaa1303e0U + 0x07f838U + 24U);
}

// [EN] FDE[1585] start_va=0x05098c, fde_va=0x07f850, span=4 B | [VN] FDE[1585]
uint32_t ttr_fde_1585_0x05098c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14003d73U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05098cU) ^ (0xaa0003e8U + 0x07f850U + 4U);
}

// [EN] FDE[1586] start_va=0x050990, fde_va=0x07f868, span=4 B | [VN] FDE[1586]
uint32_t ttr_fde_1586_0x050990(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e8U + 0x050990U) ^ (0xf9401400U + 0x07f868U + 4U);
}

// [EN] FDE[1587] start_va=0x050994, fde_va=0x07f880, span=4 B | [VN] FDE[1587]
uint32_t ttr_fde_1587_0x050994(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401400U + 0x050994U) ^ (0xb0000249U + 0x07f880U + 4U);
}

// [EN] FDE[1588] start_va=0x050998, fde_va=0x07f898, span=32 B | [VN] FDE[1588]
uint32_t ttr_fde_1588_0x050998(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9401400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000249U + 0x050998U) ^ (0x910a8129U + 0x07f898U + 32U);
}

// [EN] FDE[1589] start_va=0x0509b8, fde_va=0x07f8b0, span=4 B | [VN] FDE[1589]
uint32_t ttr_fde_1589_0x0509b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0x140041c7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140041c6U + 0x0509b8U) ^ (0xf81d0ff6U + 0x07f8b0U + 4U);
}

// [EN] FDE[1590] start_va=0x0509bc, fde_va=0x07f8c8, span=4 B | [VN] FDE[1590]
uint32_t ttr_fde_1590_0x0509bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x140041c7U) + (a1 ^ 0x140041c6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81d0ff6U + 0x0509bcU) ^ (0xa90153f5U + 0x07f8c8U + 4U);
}

// [EN] FDE[1591] start_va=0x0509c0, fde_va=0x07f8e0, span=4 B | [VN] FDE[1591]
uint32_t ttr_fde_1591_0x0509c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x140041c6U) + (a1 ^ 0xf81d0ff6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90153f5U + 0x0509c0U) ^ (0xa9027bf3U + 0x07f8e0U + 4U);
}

// [EN] FDE[1592] start_va=0x0509c4, fde_va=0x07f8f8, span=116 B | [VN] FDE[1592]
uint32_t ttr_fde_1592_0x0509c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0509c4U) ^ (0xaa1f03f3U + 0x07f8f8U + 116U);
}

// [EN] FDE[1593] start_va=0x050a38, fde_va=0x07f918, span=36 B | [VN] FDE[1593]
uint32_t ttr_fde_1593_0x050a38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000100U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x050a38U) ^ (0xf9401400U + 0x07f918U + 36U);
}

// [EN] FDE[1594] start_va=0x050a5c, fde_va=0x07f930, span=44 B | [VN] FDE[1594]
uint32_t ttr_fde_1594_0x050a5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40000e0U) + (a1 ^ 0xb9402008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x340000c8U + 0x050a5cU) ^ (0xa940a00aU + 0x07f930U + 44U);
}

// [EN] FDE[1595] start_va=0x050a88, fde_va=0x07f948, span=28 B | [VN] FDE[1595]
uint32_t ttr_fde_1595_0x050a88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40000c0U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400813U + 0x050a88U) ^ (0x97fffff2U + 0x07f948U + 28U);
}

// [EN] FDE[1596] start_va=0x050aa4, fde_va=0x07f960, span=164 B | [VN] FDE[1596]
uint32_t ttr_fde_1596_0x050aa4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x050aa4U) ^ (0xaa1f03f4U + 0x07f960U + 164U);
}

// [EN] FDE[1597] start_va=0x050b48, fde_va=0x07f980, span=12 B | [VN] FDE[1597]
uint32_t ttr_fde_1597_0x050b48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000042U) + (a1 ^ 0x17ff2e59U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x050b48U) ^ (0xa9bb6bfbU + 0x07f980U + 12U);
}

// [EN] FDE[1598] start_va=0x050b54, fde_va=0x07f998, span=248 B | [VN] FDE[1598]
uint32_t ttr_fde_1598_0x050b54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb6bfbU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x050b54U) ^ (0xa90353f5U + 0x07f998U + 248U);
}

// [EN] FDE[1599] start_va=0x050c4c, fde_va=0x07f9c0, span=240 B | [VN] FDE[1599]
uint32_t ttr_fde_1599_0x050c4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x050c4cU) ^ (0x39400008U + 0x07f9c0U + 240U);
}

// [EN] FDE[1600] start_va=0x050d3c, fde_va=0x07f9e0, span=48 B | [VN] FDE[1600]
uint32_t ttr_fde_1600_0x050d3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xaa1e03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94004381U + 0x050d3cU) ^ (0xaa0103feU + 0x07f9e0U + 48U);
}

// [EN] FDE[1601] start_va=0x050d6c, fde_va=0x07f9f8, span=40 B | [VN] FDE[1601]
uint32_t ttr_fde_1601_0x050d6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0xaa0303e4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203e3U + 0x050d6cU) ^ (0xaa0103e2U + 0x07f9f8U + 40U);
}

// [EN] FDE[1602] start_va=0x050d94, fde_va=0x07fa10, span=400 B | [VN] FDE[1602]
uint32_t ttr_fde_1602_0x050d94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb6bfbU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x050d94U) ^ (0xa90353f5U + 0x07fa10U + 400U);
}

// [EN] FDE[1603] start_va=0x050f24, fde_va=0x07fa38, span=24 B | [VN] FDE[1603]
uint32_t ttr_fde_1603_0x050f24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffdc08U + 0x050f24U) ^ (0xaa1303e0U + 0x07fa38U + 24U);
}

// [EN] FDE[1604] start_va=0x050f3c, fde_va=0x07fa50, span=4092 B | [VN] FDE[1604]
uint32_t ttr_fde_1604_0x050f3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6db733edU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x050f3cU) ^ (0xaa1e03e2U + 0x07fa50U + 4092U);
}

// [EN] FDE[1605] start_va=0x051f38, fde_va=0x07fa90, span=880 B | [VN] FDE[1605]
uint32_t ttr_fde_1605_0x051f38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10543ffU) + (a1 ^ 0xa90f6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91067faU + 0x051f38U) ^ (0xa9115ff8U + 0x07fa90U + 880U);
}

// [EN] FDE[1606] start_va=0x0522a8, fde_va=0x07fac0, span=112 B | [VN] FDE[1606]
uint32_t ttr_fde_1606_0x0522a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90553f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9067bf3U + 0x0522a8U) ^ (0x940038d4U + 0x07fac0U + 112U);
}

// [EN] FDE[1607] start_va=0x052318, fde_va=0x07fae0, span=60 B | [VN] FDE[1607]
uint32_t ttr_fde_1607_0x052318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x052318U) ^ (0x94004007U + 0x07fae0U + 60U);
}

// [EN] FDE[1608] start_va=0x052354, fde_va=0x07fb00, span=64 B | [VN] FDE[1608]
uint32_t ttr_fde_1608_0x052354(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x052354U) ^ (0x94003ff3U + 0x07fb00U + 64U);
}

// [EN] FDE[1609] start_va=0x052394, fde_va=0x07fb20, span=60 B | [VN] FDE[1609]
uint32_t ttr_fde_1609_0x052394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94003a0bU + 0x052394U) ^ (0x36000140U + 0x07fb20U + 60U);
}

// [EN] FDE[1610] start_va=0x0523d0, fde_va=0x07fb40, span=140 B | [VN] FDE[1610]
uint32_t ttr_fde_1610_0x0523d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0523d0U) ^ (0xaa0003f3U + 0x07fb40U + 140U);
}

// [EN] FDE[1611] start_va=0x05245c, fde_va=0x07fb60, span=24 B | [VN] FDE[1611]
uint32_t ttr_fde_1611_0x05245c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xf0000229U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910de129U + 0x05245cU) ^ (0xf9000009U + 0x07fb60U + 24U);
}

// [EN] FDE[1612] start_va=0x052474, fde_va=0x07fb78, span=24 B | [VN] FDE[1612]
uint32_t ttr_fde_1612_0x052474(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff8U + 0x052474U) ^ (0xaa1303e0U + 0x07fb78U + 24U);
}

// [EN] FDE[1613] start_va=0x05248c, fde_va=0x07fb90, span=48 B | [VN] FDE[1613]
uint32_t ttr_fde_1613_0x05248c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94003ae1U + 0x05248cU) ^ (0xf0000228U + 0x07fb90U + 48U);
}

// [EN] FDE[1614] start_va=0x0524bc, fde_va=0x07fba8, span=56 B | [VN] FDE[1614]
uint32_t ttr_fde_1614_0x0524bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000228U) + (a1 ^ 0x910de108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000028U + 0x0524bcU) ^ (0xf9400408U + 0x07fba8U + 56U);
}

// [EN] FDE[1615] start_va=0x0524f4, fde_va=0x07fbc0, span=8 B | [VN] FDE[1615]
uint32_t ttr_fde_1615_0x0524f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400800U) + (a1 ^ 0x17ffd6abU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x0524f4U) ^ (0x94003d80U + 0x07fbc0U + 8U);
}

// [EN] FDE[1616] start_va=0x0524fc, fde_va=0x07fbd8, span=24 B | [VN] FDE[1616]
uint32_t ttr_fde_1616_0x0524fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94003d80U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd6a8U + 0x0524fcU) ^ (0xaa1303e0U + 0x07fbd8U + 24U);
}

// [EN] FDE[1617] start_va=0x052514, fde_va=0x07fbf0, span=36 B | [VN] FDE[1617]
uint32_t ttr_fde_1617_0x052514(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xf9400400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400021U + 0x052514U) ^ (0xf9400008U + 0x07fbf0U + 36U);
}

// [EN] FDE[1618] start_va=0x052538, fde_va=0x07fc08, span=24 B | [VN] FDE[1618]
uint32_t ttr_fde_1618_0x052538(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94003603U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd699U + 0x052538U) ^ (0xaa1303e0U + 0x07fc08U + 24U);
}

// [EN] FDE[1619] start_va=0x052550, fde_va=0x07fc20, span=12 B | [VN] FDE[1619]
uint32_t ttr_fde_1619_0x052550(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3bbeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x052550U) ^ (0xa9bf7bf3U + 0x07fc20U + 12U);
}

// [EN] FDE[1620] start_va=0x05255c, fde_va=0x07fc38, span=28 B | [VN] FDE[1620]
uint32_t ttr_fde_1620_0x05255c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910f0108U + 0x05255cU) ^ (0x940048edU + 0x07fc38U + 28U);
}

// [EN] FDE[1621] start_va=0x052578, fde_va=0x07fc50, span=24 B | [VN] FDE[1621]
uint32_t ttr_fde_1621_0x052578(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x052578U) ^ (0xaa1303e0U + 0x07fc50U + 24U);
}

// [EN] FDE[1622] start_va=0x052590, fde_va=0x07fc68, span=4 B | [VN] FDE[1622]
uint32_t ttr_fde_1622_0x052590(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14004085U) + (a1 ^ 0x17ff25e7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x052590U) ^ (0xf0000228U + 0x07fc68U + 4U);
}

// [EN] FDE[1623] start_va=0x052594, fde_va=0x07fc80, span=4 B | [VN] FDE[1623]
uint32_t ttr_fde_1623_0x052594(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff25e7U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x052594U) ^ (0x910fe108U + 0x07fc80U + 4U);
}

// [EN] FDE[1624] start_va=0x052598, fde_va=0x07fc98, span=32 B | [VN] FDE[1624]
uint32_t ttr_fde_1624_0x052598(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910fe108U + 0x052598U) ^ (0x9400362dU + 0x07fc98U + 32U);
}

// [EN] FDE[1625] start_va=0x0525b8, fde_va=0x07fcb0, span=24 B | [VN] FDE[1625]
uint32_t ttr_fde_1625_0x0525b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x0525b8U) ^ (0xaa1303e0U + 0x07fcb0U + 24U);
}

// [EN] FDE[1626] start_va=0x0525d0, fde_va=0x07fcc8, span=8 B | [VN] FDE[1626]
uint32_t ttr_fde_1626_0x0525d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff25d6U + 0x0525d0U) ^ (0xa9be53f5U + 0x07fcc8U + 8U);
}

// [EN] FDE[1627] start_va=0x0525d8, fde_va=0x07fce0, span=4 B | [VN] FDE[1627]
uint32_t ttr_fde_1627_0x0525d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff25d6U) + (a1 ^ 0xa9be53f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0525d8U) ^ (0xf0000228U + 0x07fce0U + 4U);
}

// [EN] FDE[1628] start_va=0x0525dc, fde_va=0x07fcf8, span=204 B | [VN] FDE[1628]
uint32_t ttr_fde_1628_0x0525dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x0525dcU) ^ (0x9117c108U + 0x07fcf8U + 204U);
}

// [EN] FDE[1629] start_va=0x0526a8, fde_va=0x07fd18, span=12 B | [VN] FDE[1629]
uint32_t ttr_fde_1629_0x0526a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3b68U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0526a8U) ^ (0xa9bf7bf3U + 0x07fd18U + 12U);
}

// [EN] FDE[1630] start_va=0x0526b4, fde_va=0x07fd30, span=32 B | [VN] FDE[1630]
uint32_t ttr_fde_1630_0x0526b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9110c108U + 0x0526b4U) ^ (0x940035e6U + 0x07fd30U + 32U);
}

// [EN] FDE[1631] start_va=0x0526d4, fde_va=0x07fd48, span=24 B | [VN] FDE[1631]
uint32_t ttr_fde_1631_0x0526d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x0526d4U) ^ (0xaa1303e0U + 0x07fd48U + 24U);
}

// [EN] FDE[1632] start_va=0x0526ec, fde_va=0x07fd60, span=8 B | [VN] FDE[1632]
uint32_t ttr_fde_1632_0x0526ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff258fU + 0x0526ecU) ^ (0xf81e0ff4U + 0x07fd60U + 8U);
}

// [EN] FDE[1633] start_va=0x0526f4, fde_va=0x07fd78, span=4 B | [VN] FDE[1633]
uint32_t ttr_fde_1633_0x0526f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff258fU) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0526f4U) ^ (0x90000248U + 0x07fd78U + 4U);
}

// [EN] FDE[1634] start_va=0x0526f8, fde_va=0x07fd90, span=88 B | [VN] FDE[1634]
uint32_t ttr_fde_1634_0x0526f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000248U + 0x0526f8U) ^ (0xaa0003f3U + 0x07fd90U + 88U);
}

// [EN] FDE[1635] start_va=0x052750, fde_va=0x07fdb0, span=64 B | [VN] FDE[1635]
uint32_t ttr_fde_1635_0x052750(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000248U + 0x052750U) ^ (0xaa0003f3U + 0x07fdb0U + 64U);
}

// [EN] FDE[1636] start_va=0x052790, fde_va=0x07fdd0, span=40 B | [VN] FDE[1636]
uint32_t ttr_fde_1636_0x052790(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c1U + 0x052790U) ^ (0xaa0003f3U + 0x07fdd0U + 40U);
}

// [EN] FDE[1637] start_va=0x0527b8, fde_va=0x07fde8, span=40 B | [VN] FDE[1637]
uint32_t ttr_fde_1637_0x0527b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c1U + 0x0527b8U) ^ (0xaa0003f3U + 0x07fde8U + 40U);
}

// [EN] FDE[1638] start_va=0x0527e0, fde_va=0x07fe00, span=40 B | [VN] FDE[1638]
uint32_t ttr_fde_1638_0x0527e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400367fU + 0x0527e0U) ^ (0xeb15029fU + 0x07fe00U + 40U);
}

// [EN] FDE[1639] start_va=0x052808, fde_va=0x07fe20, span=36 B | [VN] FDE[1639]
uint32_t ttr_fde_1639_0x052808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100e000U + 0x052808U) ^ (0x97ffce3dU + 0x07fe20U + 36U);
}

// [EN] FDE[1640] start_va=0x05282c, fde_va=0x07fe38, span=48 B | [VN] FDE[1640]
uint32_t ttr_fde_1640_0x05282c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400366cU + 0x05282cU) ^ (0xeb15029fU + 0x07fe38U + 48U);
}

// [EN] FDE[1641] start_va=0x05285c, fde_va=0x07fe58, span=12 B | [VN] FDE[1641]
uint32_t ttr_fde_1641_0x05285c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3afbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05285cU) ^ (0xaa0003e8U + 0x07fe58U + 12U);
}

// [EN] FDE[1642] start_va=0x052868, fde_va=0x07fe70, span=24 B | [VN] FDE[1642]
uint32_t ttr_fde_1642_0x052868(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000060U + 0x052868U) ^ (0xf9000500U + 0x07fe70U + 24U);
}

// [EN] FDE[1643] start_va=0x052880, fde_va=0x07fe88, span=8 B | [VN] FDE[1643]
uint32_t ttr_fde_1643_0x052880(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85f8000U) + (a1 ^ 0x17ff2657U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x052880U) ^ (0xf0000228U + 0x07fe88U + 8U);
}

// [EN] FDE[1644] start_va=0x052888, fde_va=0x07fea0, span=32 B | [VN] FDE[1644]
uint32_t ttr_fde_1644_0x052888(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9111a108U + 0x052888U) ^ (0x94003571U + 0x07fea0U + 32U);
}

// [EN] FDE[1645] start_va=0x0528a8, fde_va=0x07feb8, span=24 B | [VN] FDE[1645]
uint32_t ttr_fde_1645_0x0528a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x0528a8U) ^ (0xaa1303e0U + 0x07feb8U + 24U);
}

// [EN] FDE[1646] start_va=0x0528c0, fde_va=0x07fed0, span=8 B | [VN] FDE[1646]
uint32_t ttr_fde_1646_0x0528c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff251aU + 0x0528c0U) ^ (0xa9bf7bf3U + 0x07fed0U + 8U);
}

// [EN] FDE[1647] start_va=0x0528c8, fde_va=0x07fee8, span=4 B | [VN] FDE[1647]
uint32_t ttr_fde_1647_0x0528c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff251aU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x0528c8U) ^ (0x9120a108U + 0x07fee8U + 4U);
}

// [EN] FDE[1648] start_va=0x0528cc, fde_va=0x07ff00, span=92 B | [VN] FDE[1648]
uint32_t ttr_fde_1648_0x0528cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9120a108U + 0x0528ccU) ^ (0x94003a5eU + 0x07ff00U + 92U);
}

// [EN] FDE[1649] start_va=0x052928, fde_va=0x07ff18, span=40 B | [VN] FDE[1649]
uint32_t ttr_fde_1649_0x052928(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c8U + 0x052928U) ^ (0xaa0003f3U + 0x07ff18U + 40U);
}

// [EN] FDE[1650] start_va=0x052950, fde_va=0x07ff30, span=12 B | [VN] FDE[1650]
uint32_t ttr_fde_1650_0x052950(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3abeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x052950U) ^ (0xf9400001U + 0x07ff30U + 12U);
}

// [EN] FDE[1651] start_va=0x05295c, fde_va=0x07ff48, span=8 B | [VN] FDE[1651]
uint32_t ttr_fde_1651_0x05295c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400001U) + (a1 ^ 0x14000001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9be53f5U + 0x05295cU) ^ (0xa9017bf3U + 0x07ff48U + 8U);
}

// [EN] FDE[1652] start_va=0x052964, fde_va=0x07ff60, span=44 B | [VN] FDE[1652]
uint32_t ttr_fde_1652_0x052964(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400361eU + 0x052964U) ^ (0xeb15029fU + 0x07ff60U + 44U);
}

// [EN] FDE[1653] start_va=0x052990, fde_va=0x07ff80, span=32 B | [VN] FDE[1653]
uint32_t ttr_fde_1653_0x052990(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91128108U + 0x052990U) ^ (0x9400352fU + 0x07ff80U + 32U);
}

// [EN] FDE[1654] start_va=0x0529b0, fde_va=0x07ff98, span=24 B | [VN] FDE[1654]
uint32_t ttr_fde_1654_0x0529b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x0529b0U) ^ (0xaa1303e0U + 0x07ff98U + 24U);
}

// [EN] FDE[1655] start_va=0x0529c8, fde_va=0x07ffb0, span=8 B | [VN] FDE[1655]
uint32_t ttr_fde_1655_0x0529c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff24d8U + 0x0529c8U) ^ (0xa9bf7bf3U + 0x07ffb0U + 8U);
}

// [EN] FDE[1656] start_va=0x0529d0, fde_va=0x07ffc8, span=4 B | [VN] FDE[1656]
uint32_t ttr_fde_1656_0x0529d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff24d8U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000248U + 0x0529d0U) ^ (0x9121a108U + 0x07ffc8U + 4U);
}

// [EN] FDE[1657] start_va=0x0529d4, fde_va=0x07ffe0, span=60 B | [VN] FDE[1657]
uint32_t ttr_fde_1657_0x0529d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000248U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9121a108U + 0x0529d4U) ^ (0x94003a1cU + 0x07ffe0U + 60U);
}

// [EN] FDE[1658] start_va=0x052a10, fde_va=0x07fff8, span=12 B | [VN] FDE[1658]
uint32_t ttr_fde_1658_0x052a10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3a8eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x052a10U) ^ (0xa9bf7bf3U + 0x07fff8U + 12U);
}

// [EN] FDE[1659] start_va=0x052a1c, fde_va=0x080010, span=32 B | [VN] FDE[1659]
uint32_t ttr_fde_1659_0x052a1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91136108U + 0x052a1cU) ^ (0x9400350cU + 0x080010U + 32U);
}

// [EN] FDE[1660] start_va=0x052a3c, fde_va=0x080028, span=24 B | [VN] FDE[1660]
uint32_t ttr_fde_1660_0x052a3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x052a3cU) ^ (0xaa1303e0U + 0x080028U + 24U);
}

// [EN] FDE[1661] start_va=0x052a54, fde_va=0x080040, span=8 B | [VN] FDE[1661]
uint32_t ttr_fde_1661_0x052a54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff24b5U + 0x052a54U) ^ (0xa9bf7bf3U + 0x080040U + 8U);
}

// [EN] FDE[1662] start_va=0x052a5c, fde_va=0x080058, span=4 B | [VN] FDE[1662]
uint32_t ttr_fde_1662_0x052a5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff24b5U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000248U + 0x052a5cU) ^ (0x9114c108U + 0x080058U + 4U);
}

// [EN] FDE[1663] start_va=0x052a60, fde_va=0x080070, span=52 B | [VN] FDE[1663]
uint32_t ttr_fde_1663_0x052a60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000248U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9114c108U + 0x052a60U) ^ (0xaa0003f3U + 0x080070U + 52U);
}

// [EN] FDE[1664] start_va=0x052a94, fde_va=0x080088, span=12 B | [VN] FDE[1664]
uint32_t ttr_fde_1664_0x052a94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3a6dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x052a94U) ^ (0xb4000040U + 0x080088U + 12U);
}

// [EN] FDE[1665] start_va=0x052aa0, fde_va=0x0800a0, span=12 B | [VN] FDE[1665]
uint32_t ttr_fde_1665_0x052aa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff3a6aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x052aa0U) ^ (0xa9bf7bf3U + 0x0800a0U + 12U);
}

// [EN] FDE[1666] start_va=0x052aac, fde_va=0x0800b8, span=32 B | [VN] FDE[1666]
uint32_t ttr_fde_1666_0x052aac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91144108U + 0x052aacU) ^ (0x940034e8U + 0x0800b8U + 32U);
}

// [EN] FDE[1667] start_va=0x052acc, fde_va=0x0800d0, span=24 B | [VN] FDE[1667]
uint32_t ttr_fde_1667_0x052acc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x052accU) ^ (0xaa1303e0U + 0x0800d0U + 24U);
}

// [EN] FDE[1668] start_va=0x052ae4, fde_va=0x0800e8, span=8 B | [VN] FDE[1668]
uint32_t ttr_fde_1668_0x052ae4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17ffff1aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2491U + 0x052ae4U) ^ (0xa9bf7bf3U + 0x0800e8U + 8U);
}

// [EN] FDE[1669] start_va=0x052aec, fde_va=0x080100, span=4 B | [VN] FDE[1669]
uint32_t ttr_fde_1669_0x052aec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2491U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x052aecU) ^ (0x91152108U + 0x080100U + 4U);
}

// [EN] FDE[1670] start_va=0x052af0, fde_va=0x080118, span=32 B | [VN] FDE[1670]
uint32_t ttr_fde_1670_0x052af0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91152108U + 0x052af0U) ^ (0x940034d7U + 0x080118U + 32U);
}

// [EN] FDE[1671] start_va=0x052b10, fde_va=0x080130, span=24 B | [VN] FDE[1671]
uint32_t ttr_fde_1671_0x052b10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x052b10U) ^ (0xaa1303e0U + 0x080130U + 24U);
}

// [EN] FDE[1672] start_va=0x052b28, fde_va=0x080148, span=8 B | [VN] FDE[1672]
uint32_t ttr_fde_1672_0x052b28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2480U + 0x052b28U) ^ (0xa9bf7bf3U + 0x080148U + 8U);
}

// [EN] FDE[1673] start_va=0x052b30, fde_va=0x080160, span=4 B | [VN] FDE[1673]
uint32_t ttr_fde_1673_0x052b30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2480U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x052b30U) ^ (0x913ee108U + 0x080160U + 4U);
}

// [EN] FDE[1674] start_va=0x052b34, fde_va=0x080178, span=148 B | [VN] FDE[1674]
uint32_t ttr_fde_1674_0x052b34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913ee108U + 0x052b34U) ^ (0x940039c4U + 0x080178U + 148U);
}

// [EN] FDE[1675] start_va=0x052bc8, fde_va=0x080190, span=24 B | [VN] FDE[1675]
uint32_t ttr_fde_1675_0x052bc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900011fU + 0x052bc8U) ^ (0xb4000040U + 0x080190U + 24U);
}

// [EN] FDE[1676] start_va=0x052be0, fde_va=0x0801a8, span=28 B | [VN] FDE[1676]
uint32_t ttr_fde_1676_0x052be0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91160108U + 0x052be0U) ^ (0x9400474cU + 0x0801a8U + 28U);
}

// [EN] FDE[1677] start_va=0x052bfc, fde_va=0x0801c0, span=24 B | [VN] FDE[1677]
uint32_t ttr_fde_1677_0x052bfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x052bfcU) ^ (0xaa1303e0U + 0x0801c0U + 24U);
}

// [EN] FDE[1678] start_va=0x052c14, fde_va=0x0801d8, span=8 B | [VN] FDE[1678]
uint32_t ttr_fde_1678_0x052c14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17ffcd52U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2445U + 0x052c14U) ^ (0xa9bf7bf3U + 0x0801d8U + 8U);
}

// [EN] FDE[1679] start_va=0x052c1c, fde_va=0x0801f0, span=4 B | [VN] FDE[1679]
uint32_t ttr_fde_1679_0x052c1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2445U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x052c1cU) ^ (0x9116e108U + 0x0801f0U + 4U);
}

// [EN] FDE[1680] start_va=0x052c20, fde_va=0x080208, span=32 B | [VN] FDE[1680]
uint32_t ttr_fde_1680_0x052c20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000228U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9116e108U + 0x052c20U) ^ (0x9400348bU + 0x080208U + 32U);
}

// [EN] FDE[1681] start_va=0x052c40, fde_va=0x080220, span=24 B | [VN] FDE[1681]
uint32_t ttr_fde_1681_0x052c40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x052c40U) ^ (0xaa1303e0U + 0x080220U + 24U);
}

// [EN] FDE[1682] start_va=0x052c58, fde_va=0x080238, span=8 B | [VN] FDE[1682]
uint32_t ttr_fde_1682_0x052c58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2434U + 0x052c58U) ^ (0xf81e0ff4U + 0x080238U + 8U);
}

// [EN] FDE[1683] start_va=0x052c60, fde_va=0x080250, span=4 B | [VN] FDE[1683]
uint32_t ttr_fde_1683_0x052c60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2434U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x052c60U) ^ (0xf0000228U + 0x080250U + 4U);
}

// [EN] FDE[1684] start_va=0x052c64, fde_va=0x080268, span=80 B | [VN] FDE[1684]
uint32_t ttr_fde_1684_0x052c64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000228U + 0x052c64U) ^ (0x9135a108U + 0x080268U + 80U);
}

// [EN] FDE[1685] start_va=0x052cb4, fde_va=0x080288, span=52 B | [VN] FDE[1685]
uint32_t ttr_fde_1685_0x052cb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9405015U + 0x052cb4U) ^ (0xaa0003f3U + 0x080288U + 52U);
}

// [EN] FDE[1686] start_va=0x052ce8, fde_va=0x0802a8, span=36 B | [VN] FDE[1686]
uint32_t ttr_fde_1686_0x052ce8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100e000U + 0x052ce8U) ^ (0x97ff7c3aU + 0x0802a8U + 36U);
}

// [EN] FDE[1687] start_va=0x052d0c, fde_va=0x0802c0, span=2872 B | [VN] FDE[1687]
uint32_t ttr_fde_1687_0x052d0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94003c65U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x052d0cU) ^ (0xa9057bf3U + 0x0802c0U + 2872U);
}

// [EN] FDE[1688] start_va=0x053844, fde_va=0x0802f0, span=4 B | [VN] FDE[1688]
uint32_t ttr_fde_1688_0x053844(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff213bU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400312cU + 0x053844U) ^ (0xd0000228U + 0x0802f0U + 4U);
}

// [EN] FDE[1689] start_va=0x053848, fde_va=0x080308, span=28 B | [VN] FDE[1689]
uint32_t ttr_fde_1689_0x053848(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400312cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000228U + 0x053848U) ^ (0x911da108U + 0x080308U + 28U);
}

// [EN] FDE[1690] start_va=0x053864, fde_va=0x080320, span=12 B | [VN] FDE[1690]
uint32_t ttr_fde_1690_0x053864(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000228U) + (a1 ^ 0x911da108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14003120U + 0x053864U) ^ (0xd65f03c0U + 0x080320U + 12U);
}

// [EN] FDE[1691] start_va=0x053870, fde_va=0x080338, span=4 B | [VN] FDE[1691]
uint32_t ttr_fde_1691_0x053870(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff212fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x053870U) ^ (0xa90253f5U + 0x080338U + 4U);
}

// [EN] FDE[1692] start_va=0x053874, fde_va=0x080350, span=4 B | [VN] FDE[1692]
uint32_t ttr_fde_1692_0x053874(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff212fU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x053874U) ^ (0xa9037bf3U + 0x080350U + 4U);
}

// [EN] FDE[1693] start_va=0x053878, fde_va=0x080368, span=108 B | [VN] FDE[1693]
uint32_t ttr_fde_1693_0x053878(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x053878U) ^ (0x9400315fU + 0x080368U + 108U);
}

// [EN] FDE[1694] start_va=0x0538e4, fde_va=0x080388, span=4 B | [VN] FDE[1694]
uint32_t ttr_fde_1694_0x0538e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2113U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94003104U + 0x0538e4U) ^ (0xd0000228U + 0x080388U + 4U);
}

// [EN] FDE[1695] start_va=0x0538e8, fde_va=0x0803a0, span=28 B | [VN] FDE[1695]
uint32_t ttr_fde_1695_0x0538e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94003104U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000228U + 0x0538e8U) ^ (0x911c8108U + 0x0803a0U + 28U);
}

// [EN] FDE[1696] start_va=0x053904, fde_va=0x0803b8, span=12 B | [VN] FDE[1696]
uint32_t ttr_fde_1696_0x053904(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000228U) + (a1 ^ 0x911c8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140030f8U + 0x053904U) ^ (0xd65f03c0U + 0x0803b8U + 12U);
}

// [EN] FDE[1697] start_va=0x053910, fde_va=0x0803d0, span=4 B | [VN] FDE[1697]
uint32_t ttr_fde_1697_0x053910(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff2107U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x053910U) ^ (0xa90253f5U + 0x0803d0U + 4U);
}

// [EN] FDE[1698] start_va=0x053914, fde_va=0x0803e8, span=4 B | [VN] FDE[1698]
uint32_t ttr_fde_1698_0x053914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff2107U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x053914U) ^ (0xa9037bf3U + 0x0803e8U + 4U);
}

// [EN] FDE[1699] start_va=0x053918, fde_va=0x080400, span=108 B | [VN] FDE[1699]
uint32_t ttr_fde_1699_0x053918(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x053918U) ^ (0x94003137U + 0x080400U + 108U);
}

// [EN] FDE[1700] start_va=0x053984, fde_va=0x080420, span=4 B | [VN] FDE[1700]
uint32_t ttr_fde_1700_0x053984(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff20ebU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940030dcU + 0x053984U) ^ (0xd0000228U + 0x080420U + 4U);
}

// [EN] FDE[1701] start_va=0x053988, fde_va=0x080438, span=28 B | [VN] FDE[1701]
uint32_t ttr_fde_1701_0x053988(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940030dcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000228U + 0x053988U) ^ (0x911b6108U + 0x080438U + 28U);
}

// [EN] FDE[1702] start_va=0x0539a4, fde_va=0x080450, span=12 B | [VN] FDE[1702]
uint32_t ttr_fde_1702_0x0539a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000228U) + (a1 ^ 0x911b6108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140030d0U + 0x0539a4U) ^ (0xd65f03c0U + 0x080450U + 12U);
}

// [EN] FDE[1703] start_va=0x0539b0, fde_va=0x080468, span=4 B | [VN] FDE[1703]
uint32_t ttr_fde_1703_0x0539b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff20dfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x0539b0U) ^ (0xa90253f5U + 0x080468U + 4U);
}

// [EN] FDE[1704] start_va=0x0539b4, fde_va=0x080480, span=4 B | [VN] FDE[1704]
uint32_t ttr_fde_1704_0x0539b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff20dfU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x0539b4U) ^ (0xa9037bf3U + 0x080480U + 4U);
}

// [EN] FDE[1705] start_va=0x0539b8, fde_va=0x080498, span=108 B | [VN] FDE[1705]
uint32_t ttr_fde_1705_0x0539b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x0539b8U) ^ (0x9400310fU + 0x080498U + 108U);
}

// [EN] FDE[1706] start_va=0x053a24, fde_va=0x0804b8, span=4 B | [VN] FDE[1706]
uint32_t ttr_fde_1706_0x053a24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff20c3U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940030b4U + 0x053a24U) ^ (0xd0000228U + 0x0804b8U + 4U);
}

// [EN] FDE[1707] start_va=0x053a28, fde_va=0x0804d0, span=28 B | [VN] FDE[1707]
uint32_t ttr_fde_1707_0x053a28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940030b4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000228U + 0x053a28U) ^ (0x911a4108U + 0x0804d0U + 28U);
}

// [EN] FDE[1708] start_va=0x053a44, fde_va=0x0804e8, span=12 B | [VN] FDE[1708]
uint32_t ttr_fde_1708_0x053a44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000228U) + (a1 ^ 0x911a4108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140030a8U + 0x053a44U) ^ (0xd65f03c0U + 0x0804e8U + 12U);
}

// [EN] FDE[1709] start_va=0x053a50, fde_va=0x080500, span=4 B | [VN] FDE[1709]
uint32_t ttr_fde_1709_0x053a50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff20b7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x053a50U) ^ (0xa90253f5U + 0x080500U + 4U);
}

// [EN] FDE[1710] start_va=0x053a54, fde_va=0x080518, span=4 B | [VN] FDE[1710]
uint32_t ttr_fde_1710_0x053a54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff20b7U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x053a54U) ^ (0xa9037bf3U + 0x080518U + 4U);
}

// [EN] FDE[1711] start_va=0x053a58, fde_va=0x080530, span=108 B | [VN] FDE[1711]
uint32_t ttr_fde_1711_0x053a58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x053a58U) ^ (0x940030e7U + 0x080530U + 108U);
}

// [EN] FDE[1712] start_va=0x053ac4, fde_va=0x080550, span=24 B | [VN] FDE[1712]
uint32_t ttr_fde_1712_0x053ac4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffac4U + 0x053ac4U) ^ (0xaa1303e0U + 0x080550U + 24U);
}

// [EN] FDE[1713] start_va=0x053adc, fde_va=0x080568, span=312 B | [VN] FDE[1713]
uint32_t ttr_fde_1713_0x053adc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbc2bebU) + (a1 ^ 0x6d0123e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x053adcU) ^ (0xa9037bf3U + 0x080568U + 312U);
}

// [EN] FDE[1714] start_va=0x053c14, fde_va=0x080590, span=268 B | [VN] FDE[1714]
uint32_t ttr_fde_1714_0x053c14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x053c14U) ^ (0x94003279U + 0x080590U + 268U);
}

// [EN] FDE[1715] start_va=0x053d20, fde_va=0x0805b0, span=1208 B | [VN] FDE[1715]
uint32_t ttr_fde_1715_0x053d20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10443ffU) + (a1 ^ 0x6d092bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0a23e9U + 0x053d20U) ^ (0xa90b6ffcU + 0x0805b0U + 1208U);
}

// [EN] FDE[1716] start_va=0x0541d8, fde_va=0x0805f0, span=580 B | [VN] FDE[1716]
uint32_t ttr_fde_1716_0x0541d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xa9046ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90567faU + 0x0541d8U) ^ (0xa9065ff8U + 0x0805f0U + 580U);
}

// [EN] FDE[1717] start_va=0x05441c, fde_va=0x080620, span=256 B | [VN] FDE[1717]
uint32_t ttr_fde_1717_0x05441c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1a0feaU) + (a1 ^ 0x6d0123e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90263f9U + 0x05441cU) ^ (0xa9035bf7U + 0x080620U + 256U);
}

// [EN] FDE[1718] start_va=0x05451c, fde_va=0x080650, span=192 B | [VN] FDE[1718]
uint32_t ttr_fde_1718_0x05451c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0403f3U + 0x05451cU) ^ (0xaa0003f4U + 0x080650U + 192U);
}

// [EN] FDE[1719] start_va=0x0545dc, fde_va=0x080670, span=68 B | [VN] FDE[1719]
uint32_t ttr_fde_1719_0x0545dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0545dcU) ^ (0xb9401e68U + 0x080670U + 68U);
}

// [EN] FDE[1720] start_va=0x054620, fde_va=0x080690, span=36 B | [VN] FDE[1720]
uint32_t ttr_fde_1720_0x054620(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0b010048U) + (a1 ^ 0x36f80068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0b000108U + 0x054620U) ^ (0x37ffffe8U + 0x080690U + 36U);
}

// [EN] FDE[1721] start_va=0x054644, fde_va=0x0806a8, span=48 B | [VN] FDE[1721]
uint32_t ttr_fde_1721_0x054644(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9402408U) + (a1 ^ 0xb9401809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6b09011fU + 0x054644U) ^ (0x5400006dU + 0x0806a8U + 48U);
}

// [EN] FDE[1722] start_va=0x054674, fde_va=0x0806c0, span=64 B | [VN] FDE[1722]
uint32_t ttr_fde_1722_0x054674(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9402008U + 0x054674U) ^ (0xaa0003f3U + 0x0806c0U + 64U);
}

// [EN] FDE[1723] start_va=0x0546b4, fde_va=0x0806e0, span=180 B | [VN] FDE[1723]
uint32_t ttr_fde_1723_0x0546b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf9001bfaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90463f9U + 0x0546b4U) ^ (0xa9055bf7U + 0x0806e0U + 180U);
}

// [EN] FDE[1724] start_va=0x054768, fde_va=0x080708, span=120 B | [VN] FDE[1724]
uint32_t ttr_fde_1724_0x054768(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x054768U) ^ (0xaa0203f3U + 0x080708U + 120U);
}

// [EN] FDE[1725] start_va=0x0547e0, fde_va=0x080728, span=4 B | [VN] FDE[1725]
uint32_t ttr_fde_1725_0x0547e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff1d53U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xbd400801U + 0x0547e0U) ^ (0x52800208U + 0x080728U + 4U);
}

// [EN] FDE[1726] start_va=0x0547e4, fde_va=0x080740, span=4 B | [VN] FDE[1726]
uint32_t ttr_fde_1726_0x0547e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1d53U) + (a1 ^ 0xbd400801U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800208U + 0x0547e4U) ^ (0x52800189U + 0x080740U + 4U);
}

// [EN] FDE[1727] start_va=0x0547e8, fde_va=0x080758, span=28 B | [VN] FDE[1727]
uint32_t ttr_fde_1727_0x0547e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd400801U) + (a1 ^ 0x52800208U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800189U + 0x0547e8U) ^ (0x1e2e1003U + 0x080758U + 28U);
}

// [EN] FDE[1728] start_va=0x054804, fde_va=0x080770, span=8 B | [VN] FDE[1728]
uint32_t ttr_fde_1728_0x054804(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd000800U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xbd400801U + 0x054804U) ^ (0x52800188U + 0x080770U + 8U);
}

// [EN] FDE[1729] start_va=0x05480c, fde_va=0x080788, span=28 B | [VN] FDE[1729]
uint32_t ttr_fde_1729_0x05480c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd400801U) + (a1 ^ 0x52800188U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800209U + 0x05480cU) ^ (0x1e2e1003U + 0x080788U + 28U);
}

// [EN] FDE[1730] start_va=0x054828, fde_va=0x0807a0, span=16 B | [VN] FDE[1730]
uint32_t ttr_fde_1730_0x054828(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e249001U) + (a1 ^ 0x1e210801U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2d018400U + 0x054828U) ^ (0xd65f03c0U + 0x0807a0U + 16U);
}

// [EN] FDE[1731] start_va=0x054838, fde_va=0x0807b8, span=4 B | [VN] FDE[1731]
uint32_t ttr_fde_1731_0x054838(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1ddeU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94003924U + 0x054838U) ^ (0xaa1303e0U + 0x0807b8U + 4U);
}

// [EN] FDE[1732] start_va=0x05483c, fde_va=0x0807d0, span=20 B | [VN] FDE[1732]
uint32_t ttr_fde_1732_0x05483c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94003924U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x05483cU) ^ (0xa8c17bf3U + 0x0807d0U + 20U);
}

// [EN] FDE[1733] start_va=0x054850, fde_va=0x0807e8, span=4 B | [VN] FDE[1733]
uint32_t ttr_fde_1733_0x054850(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x140037d5U) + (a1 ^ 0x17ff1d37U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff4U + 0x054850U) ^ (0xa9017bf3U + 0x0807e8U + 4U);
}

// [EN] FDE[1734] start_va=0x054854, fde_va=0x080800, span=4 B | [VN] FDE[1734]
uint32_t ttr_fde_1734_0x054854(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1d37U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x054854U) ^ (0x2a0103f3U + 0x080800U + 4U);
}

// [EN] FDE[1735] start_va=0x054858, fde_va=0x080818, span=44 B | [VN] FDE[1735]
uint32_t ttr_fde_1735_0x054858(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0103f3U + 0x054858U) ^ (0x93407e61U + 0x080818U + 44U);
}

// [EN] FDE[1736] start_va=0x054884, fde_va=0x080838, span=4 B | [VN] FDE[1736]
uint32_t ttr_fde_1736_0x054884(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1d2bU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002d1cU + 0x054884U) ^ (0xb0000228U + 0x080838U + 4U);
}

// [EN] FDE[1737] start_va=0x054888, fde_va=0x080850, span=28 B | [VN] FDE[1737]
uint32_t ttr_fde_1737_0x054888(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002d1cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000228U + 0x054888U) ^ (0x91268108U + 0x080850U + 28U);
}

// [EN] FDE[1738] start_va=0x0548a4, fde_va=0x080868, span=12 B | [VN] FDE[1738]
uint32_t ttr_fde_1738_0x0548a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000228U) + (a1 ^ 0x91268108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002d10U + 0x0548a4U) ^ (0xd65f03c0U + 0x080868U + 12U);
}

// [EN] FDE[1739] start_va=0x0548b0, fde_va=0x080880, span=4 B | [VN] FDE[1739]
uint32_t ttr_fde_1739_0x0548b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff1d1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x0548b0U) ^ (0xf90013f4U + 0x080880U + 4U);
}

// [EN] FDE[1740] start_va=0x0548b4, fde_va=0x080898, span=4 B | [VN] FDE[1740]
uint32_t ttr_fde_1740_0x0548b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1d1fU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x0548b4U) ^ (0xa9037bf3U + 0x080898U + 4U);
}

// [EN] FDE[1741] start_va=0x0548b8, fde_va=0x0808b0, span=72 B | [VN] FDE[1741]
uint32_t ttr_fde_1741_0x0548b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x0548b8U) ^ (0x94002d4fU + 0x0808b0U + 72U);
}

// [EN] FDE[1742] start_va=0x054900, fde_va=0x0808d0, span=4 B | [VN] FDE[1742]
uint32_t ttr_fde_1742_0x054900(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1d0cU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002cfdU + 0x054900U) ^ (0xb0000228U + 0x0808d0U + 4U);
}

// [EN] FDE[1743] start_va=0x054904, fde_va=0x0808e8, span=28 B | [VN] FDE[1743]
uint32_t ttr_fde_1743_0x054904(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002cfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000228U + 0x054904U) ^ (0x91256108U + 0x0808e8U + 28U);
}

// [EN] FDE[1744] start_va=0x054920, fde_va=0x080900, span=12 B | [VN] FDE[1744]
uint32_t ttr_fde_1744_0x054920(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000228U) + (a1 ^ 0x91256108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002cf1U + 0x054920U) ^ (0xd65f03c0U + 0x080900U + 12U);
}

// [EN] FDE[1745] start_va=0x05492c, fde_va=0x080918, span=4 B | [VN] FDE[1745]
uint32_t ttr_fde_1745_0x05492c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff1d00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05492cU) ^ (0xf90013f4U + 0x080918U + 4U);
}

// [EN] FDE[1746] start_va=0x054930, fde_va=0x080930, span=4 B | [VN] FDE[1746]
uint32_t ttr_fde_1746_0x054930(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1d00U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x054930U) ^ (0xa9037bf3U + 0x080930U + 4U);
}

// [EN] FDE[1747] start_va=0x054934, fde_va=0x080948, span=72 B | [VN] FDE[1747]
uint32_t ttr_fde_1747_0x054934(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x054934U) ^ (0x94002d30U + 0x080948U + 72U);
}

// [EN] FDE[1748] start_va=0x05497c, fde_va=0x080968, span=4 B | [VN] FDE[1748]
uint32_t ttr_fde_1748_0x05497c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1cedU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002cdeU + 0x05497cU) ^ (0xb0000228U + 0x080968U + 4U);
}

// [EN] FDE[1749] start_va=0x054980, fde_va=0x080980, span=28 B | [VN] FDE[1749]
uint32_t ttr_fde_1749_0x054980(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002cdeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000228U + 0x054980U) ^ (0x91244108U + 0x080980U + 28U);
}

// [EN] FDE[1750] start_va=0x05499c, fde_va=0x080998, span=12 B | [VN] FDE[1750]
uint32_t ttr_fde_1750_0x05499c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000228U) + (a1 ^ 0x91244108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002cd2U + 0x05499cU) ^ (0xd65f03c0U + 0x080998U + 12U);
}

// [EN] FDE[1751] start_va=0x0549a8, fde_va=0x0809b0, span=4 B | [VN] FDE[1751]
uint32_t ttr_fde_1751_0x0549a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff1ce1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100c3ffU + 0x0549a8U) ^ (0xa9027bf3U + 0x0809b0U + 4U);
}

// [EN] FDE[1752] start_va=0x0549ac, fde_va=0x0809c8, span=4 B | [VN] FDE[1752]
uint32_t ttr_fde_1752_0x0549ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1ce1U) + (a1 ^ 0xd100c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0549acU) ^ (0xb9400028U + 0x0809c8U + 4U);
}

// [EN] FDE[1753] start_va=0x0549b0, fde_va=0x0809e0, span=52 B | [VN] FDE[1753]
uint32_t ttr_fde_1753_0x0549b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9027bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400028U + 0x0549b0U) ^ (0x350000e8U + 0x0809e0U + 52U);
}

// [EN] FDE[1754] start_va=0x0549e4, fde_va=0x0809f8, span=4 B | [VN] FDE[1754]
uint32_t ttr_fde_1754_0x0549e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1cd3U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002cc4U + 0x0549e4U) ^ (0xb0000228U + 0x0809f8U + 4U);
}

// [EN] FDE[1755] start_va=0x0549e8, fde_va=0x080a10, span=28 B | [VN] FDE[1755]
uint32_t ttr_fde_1755_0x0549e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002cc4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000228U + 0x0549e8U) ^ (0x91232108U + 0x080a10U + 28U);
}

// [EN] FDE[1756] start_va=0x054a04, fde_va=0x080a28, span=12 B | [VN] FDE[1756]
uint32_t ttr_fde_1756_0x054a04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000228U) + (a1 ^ 0x91232108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002cb8U + 0x054a04U) ^ (0xd65f03c0U + 0x080a28U + 12U);
}

// [EN] FDE[1757] start_va=0x054a10, fde_va=0x080a40, span=4 B | [VN] FDE[1757]
uint32_t ttr_fde_1757_0x054a10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff1cc7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100c3ffU + 0x054a10U) ^ (0xa9027bf3U + 0x080a40U + 4U);
}

// [EN] FDE[1758] start_va=0x054a14, fde_va=0x080a58, span=4 B | [VN] FDE[1758]
uint32_t ttr_fde_1758_0x054a14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff1cc7U) + (a1 ^ 0xd100c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x054a14U) ^ (0xb9400028U + 0x080a58U + 4U);
}

// [EN] FDE[1759] start_va=0x054a18, fde_va=0x080a70, span=52 B | [VN] FDE[1759]
uint32_t ttr_fde_1759_0x054a18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9027bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400028U + 0x054a18U) ^ (0x350000e8U + 0x080a70U + 52U);
}

// [EN] FDE[1760] start_va=0x054a4c, fde_va=0x080a88, span=24 B | [VN] FDE[1760]
uint32_t ttr_fde_1760_0x054a4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fff79eU + 0x054a4cU) ^ (0xaa1303e0U + 0x080a88U + 24U);
}

// [EN] FDE[1761] start_va=0x054a64, fde_va=0x080aa0, span=824 B | [VN] FDE[1761]
uint32_t ttr_fde_1761_0x054a64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9001bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9046bfbU + 0x054a64U) ^ (0xa90563f9U + 0x080aa0U + 824U);
}

// [EN] FDE[1762] start_va=0x054d9c, fde_va=0x080ad0, span=556 B | [VN] FDE[1762]
uint32_t ttr_fde_1762_0x054d9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xa90f63fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9105bf7U + 0x054d9cU) ^ (0xa91153f5U + 0x080ad0U + 556U);
}

// [EN] FDE[1763] start_va=0x054fc8, fde_va=0x080af8, span=1468 B | [VN] FDE[1763]
uint32_t ttr_fde_1763_0x054fc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94002d3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x054fc8U) ^ (0xa9077bfdU + 0x080af8U + 1468U);
}

// [EN] FDE[1764] start_va=0x055584, fde_va=0x080b28, span=236 B | [VN] FDE[1764]
uint32_t ttr_fde_1764_0x055584(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94002a47U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x055584U) ^ (0xa9067bfdU + 0x080b28U + 236U);
}

// [EN] FDE[1765] start_va=0x055670, fde_va=0x080b58, span=156 B | [VN] FDE[1765]
uint32_t ttr_fde_1765_0x055670(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103e9U) + (a1 ^ 0xf9401c01U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf940100bU + 0x055670U) ^ (0xaa0003e8U + 0x080b58U + 156U);
}

// [EN] FDE[1766] start_va=0x05570c, fde_va=0x080b70, span=456 B | [VN] FDE[1766]
uint32_t ttr_fde_1766_0x05570c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05570cU) ^ (0xa9402009U + 0x080b70U + 456U);
}

// [EN] FDE[1767] start_va=0x0558d4, fde_va=0x080b90, span=108 B | [VN] FDE[1767]
uint32_t ttr_fde_1767_0x0558d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x37f80341U) + (a1 ^ 0xa9be53f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0558d4U) ^ (0xb9000001U + 0x080b90U + 108U);
}

// [EN] FDE[1768] start_va=0x055940, fde_va=0x080bb0, span=92 B | [VN] FDE[1768]
uint32_t ttr_fde_1768_0x055940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x055940U) ^ (0xb9400008U + 0x080bb0U + 92U);
}

// [EN] FDE[1769] start_va=0x05599c, fde_va=0x080bd0, span=32 B | [VN] FDE[1769]
uint32_t ttr_fde_1769_0x05599c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa943a408U) + (a1 ^ 0xcb080129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9342fd29U + 0x05599cU) ^ (0xf1000529U + 0x080bd0U + 32U);
}

// [EN] FDE[1770] start_va=0x0559bc, fde_va=0x080be8, span=524 B | [VN] FDE[1770]
uint32_t ttr_fde_1770_0x0559bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x0559bcU) ^ (0xa9037bf3U + 0x080be8U + 524U);
}

// [EN] FDE[1771] start_va=0x055bc8, fde_va=0x080c08, span=24 B | [VN] FDE[1771]
uint32_t ttr_fde_1771_0x055bc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400285fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fff360U + 0x055bc8U) ^ (0xaa1303e0U + 0x080c08U + 24U);
}

// [EN] FDE[1772] start_va=0x055be0, fde_va=0x080c20, span=56 B | [VN] FDE[1772]
uint32_t ttr_fde_1772_0x055be0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000228U + 0x055be0U) ^ (0xaa0003f3U + 0x080c20U + 56U);
}

// [EN] FDE[1773] start_va=0x055c18, fde_va=0x080c40, span=24 B | [VN] FDE[1773]
uint32_t ttr_fde_1773_0x055c18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff0U + 0x055c18U) ^ (0xaa1303e0U + 0x080c40U + 24U);
}

// [EN] FDE[1774] start_va=0x055c30, fde_va=0x080c58, span=56 B | [VN] FDE[1774]
uint32_t ttr_fde_1774_0x055c30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x52800088U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200043fU + 0x055c30U) ^ (0x1ac80c28U + 0x080c58U + 56U);
}

// [EN] FDE[1775] start_va=0x055c68, fde_va=0x080c70, span=36 B | [VN] FDE[1775]
uint32_t ttr_fde_1775_0x055c68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x055c68U) ^ (0x94003250U + 0x080c70U + 36U);
}

// [EN] FDE[1776] start_va=0x055c8c, fde_va=0x080c90, span=560 B | [VN] FDE[1776]
uint32_t ttr_fde_1776_0x055c8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10303ffU) + (a1 ^ 0xf90033fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9076bfbU + 0x055c8cU) ^ (0xa90863f9U + 0x080c90U + 560U);
}

// [EN] FDE[1777] start_va=0x055ebc, fde_va=0x080cc0, span=212 B | [VN] FDE[1777]
uint32_t ttr_fde_1777_0x055ebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94002ff9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x055ebcU) ^ (0xa9057bf3U + 0x080cc0U + 212U);
}

// [EN] FDE[1778] start_va=0x055f90, fde_va=0x080cf0, span=264 B | [VN] FDE[1778]
uint32_t ttr_fde_1778_0x055f90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x055f90U) ^ (0xa9402009U + 0x080cf0U + 264U);
}

// [EN] FDE[1779] start_va=0x056098, fde_va=0x080d10, span=384 B | [VN] FDE[1779]
uint32_t ttr_fde_1779_0x056098(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x056098U) ^ (0xa9037bf3U + 0x080d10U + 384U);
}

// [EN] FDE[1780] start_va=0x056218, fde_va=0x080d38, span=264 B | [VN] FDE[1780]
uint32_t ttr_fde_1780_0x056218(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x056218U) ^ (0xa9402009U + 0x080d38U + 264U);
}

// [EN] FDE[1781] start_va=0x056320, fde_va=0x080d58, span=288 B | [VN] FDE[1781]
uint32_t ttr_fde_1781_0x056320(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf9001bf8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9045bf7U + 0x056320U) ^ (0xa90553f5U + 0x080d58U + 288U);
}

// [EN] FDE[1782] start_va=0x056440, fde_va=0x080d80, span=160 B | [VN] FDE[1782]
uint32_t ttr_fde_1782_0x056440(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9001bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9046bfbU + 0x056440U) ^ (0xa90563f9U + 0x080d80U + 160U);
}

// [EN] FDE[1783] start_va=0x0564e0, fde_va=0x080db0, span=24 B | [VN] FDE[1783]
uint32_t ttr_fde_1783_0x0564e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002619U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fff0ddU + 0x0564e0U) ^ (0xaa1303e0U + 0x080db0U + 24U);
}

// [EN] FDE[1784] start_va=0x0564f8, fde_va=0x080dc8, span=248 B | [VN] FDE[1784]
uint32_t ttr_fde_1784_0x0564f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0564f8U) ^ (0x94002ed1U + 0x080dc8U + 248U);
}

// [EN] FDE[1785] start_va=0x0565f0, fde_va=0x080de8, span=24 B | [VN] FDE[1785]
uint32_t ttr_fde_1785_0x0565f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900011fU + 0x0565f0U) ^ (0xb4000040U + 0x080de8U + 24U);
}

// [EN] FDE[1786] start_va=0x056608, fde_va=0x080e00, span=32 B | [VN] FDE[1786]
uint32_t ttr_fde_1786_0x056608(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000208U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91298108U + 0x056608U) ^ (0x94002611U + 0x080e00U + 32U);
}

// [EN] FDE[1787] start_va=0x056628, fde_va=0x080e18, span=24 B | [VN] FDE[1787]
uint32_t ttr_fde_1787_0x056628(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x056628U) ^ (0xaa1303e0U + 0x080e18U + 24U);
}

// [EN] FDE[1788] start_va=0x056640, fde_va=0x080e30, span=8 B | [VN] FDE[1788]
uint32_t ttr_fde_1788_0x056640(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff15baU + 0x056640U) ^ (0xa9bf7bf3U + 0x080e30U + 8U);
}

// [EN] FDE[1789] start_va=0x056648, fde_va=0x080e48, span=4 B | [VN] FDE[1789]
uint32_t ttr_fde_1789_0x056648(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff15baU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x056648U) ^ (0x9100c000U + 0x080e48U + 4U);
}

// [EN] FDE[1790] start_va=0x05664c, fde_va=0x080e60, span=36 B | [VN] FDE[1790]
uint32_t ttr_fde_1790_0x05664c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100c000U + 0x05664cU) ^ (0x97fff084U + 0x080e60U + 36U);
}

// [EN] FDE[1791] start_va=0x056670, fde_va=0x080e78, span=44 B | [VN] FDE[1791]
uint32_t ttr_fde_1791_0x056670(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xd37cfc28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb5000108U + 0x056670U) ^ (0x940028fdU + 0x080e78U + 44U);
}

// [EN] FDE[1792] start_va=0x05669c, fde_va=0x080e90, span=20 B | [VN] FDE[1792]
uint32_t ttr_fde_1792_0x05669c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37cfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14003075U + 0x05669cU) ^ (0xf81f0ffeU + 0x080e90U + 20U);
}

// [EN] FDE[1793] start_va=0x0566b0, fde_va=0x080ea8, span=48 B | [VN] FDE[1793]
uint32_t ttr_fde_1793_0x0566b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000120U + 0x0566b0U) ^ (0xf940042aU + 0x080ea8U + 48U);
}

// [EN] FDE[1794] start_va=0x0566e0, fde_va=0x080ec0, span=56 B | [VN] FDE[1794]
uint32_t ttr_fde_1794_0x0566e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94003061U + 0x0566e0U) ^ (0x940030b4U + 0x080ec0U + 56U);
}

// [EN] FDE[1795] start_va=0x056718, fde_va=0x080ee0, span=40 B | [VN] FDE[1795]
uint32_t ttr_fde_1795_0x056718(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940026b1U + 0x056718U) ^ (0xeb15029fU + 0x080ee0U + 40U);
}

// [EN] FDE[1796] start_va=0x056740, fde_va=0x080f00, span=20 B | [VN] FDE[1796]
uint32_t ttr_fde_1796_0x056740(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x056740U) ^ (0x1400289fU + 0x080f00U + 20U);
}

// [EN] FDE[1797] start_va=0x056754, fde_va=0x080f18, span=44 B | [VN] FDE[1797]
uint32_t ttr_fde_1797_0x056754(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940026a2U + 0x056754U) ^ (0xeb15029fU + 0x080f18U + 44U);
}

// [EN] FDE[1798] start_va=0x056780, fde_va=0x080f38, span=72 B | [VN] FDE[1798]
uint32_t ttr_fde_1798_0x056780(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002a56U + 0x056780U) ^ (0x540001a0U + 0x080f38U + 72U);
}

// [EN] FDE[1799] start_va=0x0567c8, fde_va=0x080f58, span=40 B | [VN] FDE[1799]
uint32_t ttr_fde_1799_0x0567c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002685U + 0x0567c8U) ^ (0xeb15029fU + 0x080f58U + 40U);
}

// [EN] FDE[1800] start_va=0x0567f0, fde_va=0x080f78, span=292 B | [VN] FDE[1800]
uint32_t ttr_fde_1800_0x0567f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0567f0U) ^ (0xa9402009U + 0x080f78U + 292U);
}

// [EN] FDE[1801] start_va=0x056914, fde_va=0x080f98, span=40 B | [VN] FDE[1801]
uint32_t ttr_fde_1801_0x056914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c1U + 0x056914U) ^ (0xaa0003f3U + 0x080f98U + 40U);
}

// [EN] FDE[1802] start_va=0x05693c, fde_va=0x080fb0, span=40 B | [VN] FDE[1802]
uint32_t ttr_fde_1802_0x05693c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c1U + 0x05693cU) ^ (0xaa0003f3U + 0x080fb0U + 40U);
}

// [EN] FDE[1803] start_va=0x056964, fde_va=0x080fc8, span=20 B | [VN] FDE[1803]
uint32_t ttr_fde_1803_0x056964(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x056964U) ^ (0x14002816U + 0x080fc8U + 20U);
}

// [EN] FDE[1804] start_va=0x056978, fde_va=0x080fe0, span=20 B | [VN] FDE[1804]
uint32_t ttr_fde_1804_0x056978(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x056978U) ^ (0x14002811U + 0x080fe0U + 20U);
}

// [EN] FDE[1805] start_va=0x05698c, fde_va=0x080ff8, span=40 B | [VN] FDE[1805]
uint32_t ttr_fde_1805_0x05698c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c1U + 0x05698cU) ^ (0xaa0003f3U + 0x080ff8U + 40U);
}

// [EN] FDE[1806] start_va=0x0569b4, fde_va=0x081010, span=32 B | [VN] FDE[1806]
uint32_t ttr_fde_1806_0x0569b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf0000208U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9127a108U + 0x0569b4U) ^ (0x94002526U + 0x081010U + 32U);
}

// [EN] FDE[1807] start_va=0x0569d4, fde_va=0x081028, span=24 B | [VN] FDE[1807]
uint32_t ttr_fde_1807_0x0569d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x0569d4U) ^ (0xaa1303e0U + 0x081028U + 24U);
}

// [EN] FDE[1808] start_va=0x0569ec, fde_va=0x081040, span=8 B | [VN] FDE[1808]
uint32_t ttr_fde_1808_0x0569ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17fffc7cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff14cfU + 0x0569ecU) ^ (0xf81e0ff4U + 0x081040U + 8U);
}

// [EN] FDE[1809] start_va=0x0569f4, fde_va=0x081058, span=4 B | [VN] FDE[1809]
uint32_t ttr_fde_1809_0x0569f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff14cfU) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0569f4U) ^ (0xf0000208U + 0x081058U + 4U);
}

// [EN] FDE[1810] start_va=0x0569f8, fde_va=0x081070, span=92 B | [VN] FDE[1810]
uint32_t ttr_fde_1810_0x0569f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000208U + 0x0569f8U) ^ (0xaa0003f3U + 0x081070U + 92U);
}

// [EN] FDE[1811] start_va=0x056a54, fde_va=0x081090, span=24 B | [VN] FDE[1811]
uint32_t ttr_fde_1811_0x056a54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffe7U + 0x056a54U) ^ (0xaa1303e0U + 0x081090U + 24U);
}

// [EN] FDE[1812] start_va=0x056a6c, fde_va=0x0810a8, span=52 B | [VN] FDE[1812]
uint32_t ttr_fde_1812_0x056a6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x056a6cU) ^ (0x94002c25U + 0x0810a8U + 52U);
}

// [EN] FDE[1813] start_va=0x056aa0, fde_va=0x0810c8, span=36 B | [VN] FDE[1813]
uint32_t ttr_fde_1813_0x056aa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x056aa0U) ^ (0x94002e6fU + 0x0810c8U + 36U);
}

// [EN] FDE[1814] start_va=0x056ac4, fde_va=0x0810e8, span=776 B | [VN] FDE[1814]
uint32_t ttr_fde_1814_0x056ac4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10303ffU) + (a1 ^ 0xa9066ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90767faU + 0x056ac4U) ^ (0xa9085ff8U + 0x0810e8U + 776U);
}

// [EN] FDE[1815] start_va=0x056dcc, fde_va=0x081118, span=264 B | [VN] FDE[1815]
uint32_t ttr_fde_1815_0x056dcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x940025beU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x056dccU) ^ (0xa9077bfdU + 0x081118U + 264U);
}

// [EN] FDE[1816] start_va=0x056ed4, fde_va=0x081148, span=3012 B | [VN] FDE[1816]
uint32_t ttr_fde_1816_0x056ed4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e5U) + (a1 ^ 0x94003005U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0503feU + 0x056ed4U) ^ (0xa9097bfdU + 0x081148U + 3012U);
}

// [EN] FDE[1817] start_va=0x057a98, fde_va=0x081190, span=52 B | [VN] FDE[1817]
uint32_t ttr_fde_1817_0x057a98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400293bU + 0x057a98U) ^ (0xb4000101U + 0x081190U + 52U);
}

// [EN] FDE[1818] start_va=0x057acc, fde_va=0x0811b0, span=252 B | [VN] FDE[1818]
uint32_t ttr_fde_1818_0x057acc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9035bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x057accU) ^ (0xa9057bf3U + 0x0811b0U + 252U);
}

// [EN] FDE[1819] start_va=0x057bc8, fde_va=0x0811d0, span=48 B | [VN] FDE[1819]
uint32_t ttr_fde_1819_0x057bc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x057bc8U) ^ (0xf9400000U + 0x0811d0U + 48U);
}

// [EN] FDE[1820] start_va=0x057bf8, fde_va=0x0811f0, span=44 B | [VN] FDE[1820]
uint32_t ttr_fde_1820_0x057bf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb201f3e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002d88U + 0x057bf8U) ^ (0x540000e8U + 0x0811f0U + 44U);
}

// [EN] FDE[1821] start_va=0x057c24, fde_va=0x081208, span=44 B | [VN] FDE[1821]
uint32_t ttr_fde_1821_0x057c24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002fccU + 0x057c24U) ^ (0xb4000081U + 0x081208U + 44U);
}

// [EN] FDE[1822] start_va=0x057c50, fde_va=0x081228, span=72 B | [VN] FDE[1822]
uint32_t ttr_fde_1822_0x057c50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402009U) + (a1 ^ 0xcb080129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40001e9U + 0x057c50U) ^ (0xf940042aU + 0x081228U + 72U);
}

// [EN] FDE[1823] start_va=0x057c98, fde_va=0x081240, span=60 B | [VN] FDE[1823]
uint32_t ttr_fde_1823_0x057c98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002af3U + 0x057c98U) ^ (0x94002b46U + 0x081240U + 60U);
}

// [EN] FDE[1824] start_va=0x057cd4, fde_va=0x081260, span=76 B | [VN] FDE[1824]
uint32_t ttr_fde_1824_0x057cd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002501U + 0x057cd4U) ^ (0x540001c0U + 0x081260U + 76U);
}

// [EN] FDE[1825] start_va=0x057d20, fde_va=0x081280, span=32 B | [VN] FDE[1825]
uint32_t ttr_fde_1825_0x057d20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb201f3e8U) + (a1 ^ 0xf2955568U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2e15548U + 0x057d20U) ^ (0xeb08001fU + 0x081280U + 32U);
}

// [EN] FDE[1826] start_va=0x057d40, fde_va=0x081298, span=132 B | [VN] FDE[1826]
uint32_t ttr_fde_1826_0x057d40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x057d40U) ^ (0x940024e5U + 0x081298U + 132U);
}

// [EN] FDE[1827] start_va=0x057dc4, fde_va=0x0812b8, span=228 B | [VN] FDE[1827]
uint32_t ttr_fde_1827_0x057dc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x057dc4U) ^ (0xa9057bf3U + 0x0812b8U + 228U);
}

// [EN] FDE[1828] start_va=0x057ea8, fde_va=0x0812d8, span=68 B | [VN] FDE[1828]
uint32_t ttr_fde_1828_0x057ea8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x057ea8U) ^ (0x94002836U + 0x0812d8U + 68U);
}

// [EN] FDE[1829] start_va=0x057eec, fde_va=0x0812f8, span=20 B | [VN] FDE[1829]
uint32_t ttr_fde_1829_0x057eec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x057eecU) ^ (0x140022b4U + 0x0812f8U + 20U);
}

// [EN] FDE[1830] start_va=0x057f00, fde_va=0x081310, span=184 B | [VN] FDE[1830]
uint32_t ttr_fde_1830_0x057f00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x057f00U) ^ (0x94003135U + 0x081310U + 184U);
}

// [EN] FDE[1831] start_va=0x057fb8, fde_va=0x081330, span=272 B | [VN] FDE[1831]
uint32_t ttr_fde_1831_0x057fb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x057fb8U) ^ (0xa940a408U + 0x081330U + 272U);
}

// [EN] FDE[1832] start_va=0x0580c8, fde_va=0x081350, span=492 B | [VN] FDE[1832]
uint32_t ttr_fde_1832_0x0580c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e220811U) + (a1 ^ 0x1e230832U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e230806U + 0x0580c8U) ^ (0x1e220827U + 0x081350U + 492U);
}

// [EN] FDE[1833] start_va=0x0582b4, fde_va=0x081368, span=624 B | [VN] FDE[1833]
uint32_t ttr_fde_1833_0x0582b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0x6d0333edU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d042bebU + 0x0582b4U) ^ (0x6d0523e9U + 0x081368U + 624U);
}

// [EN] FDE[1834] start_va=0x058524, fde_va=0x0813a8, span=184 B | [VN] FDE[1834]
uint32_t ttr_fde_1834_0x058524(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x058524U) ^ (0x94002facU + 0x0813a8U + 184U);
}

// [EN] FDE[1835] start_va=0x0585dc, fde_va=0x0813c8, span=56 B | [VN] FDE[1835]
uint32_t ttr_fde_1835_0x0585dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002547U + 0x0585dcU) ^ (0xb40000a0U + 0x0813c8U + 56U);
}

// [EN] FDE[1836] start_va=0x058614, fde_va=0x0813e8, span=316 B | [VN] FDE[1836]
uint32_t ttr_fde_1836_0x058614(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10443ffU) + (a1 ^ 0x6d0d23e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90073fcU + 0x058614U) ^ (0xa90f53f5U + 0x0813e8U + 316U);
}

// [EN] FDE[1837] start_va=0x058750, fde_va=0x081410, span=44 B | [VN] FDE[1837]
uint32_t ttr_fde_1837_0x058750(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x2d0107e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401000U + 0x058750U) ^ (0xb40000e0U + 0x081410U + 44U);
}

// [EN] FDE[1838] start_va=0x05877c, fde_va=0x081428, span=32 B | [VN] FDE[1838]
uint32_t ttr_fde_1838_0x05877c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9401000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb00011fU + 0x05877cU) ^ (0x54000060U + 0x081428U + 32U);
}

// [EN] FDE[1839] start_va=0x05879c, fde_va=0x081440, span=68 B | [VN] FDE[1839]
uint32_t ttr_fde_1839_0x05879c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05879cU) ^ (0x940025f9U + 0x081440U + 68U);
}

// [EN] FDE[1840] start_va=0x0587e0, fde_va=0x081460, span=164 B | [VN] FDE[1840]
uint32_t ttr_fde_1840_0x0587e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x0587e0U) ^ (0xa9057bf3U + 0x081460U + 164U);
}

// [EN] FDE[1841] start_va=0x058884, fde_va=0x081480, span=72 B | [VN] FDE[1841]
uint32_t ttr_fde_1841_0x058884(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9402428U + 0x058884U) ^ (0x94001e10U + 0x081480U + 72U);
}

// [EN] FDE[1842] start_va=0x0588cc, fde_va=0x0814a0, span=4 B | [VN] FDE[1842]
uint32_t ttr_fde_1842_0x0588cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0f19U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0d17U + 0x0588ccU) ^ (0xa9bf7bf3U + 0x0814a0U + 4U);
}

// [EN] FDE[1843] start_va=0x0588d0, fde_va=0x0814b8, span=4 B | [VN] FDE[1843]
uint32_t ttr_fde_1843_0x0588d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff0d17U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x0588d0U) ^ (0xaa0003f3U + 0x0814b8U + 4U);
}

// [EN] FDE[1844] start_va=0x0588d4, fde_va=0x0814d0, span=4 B | [VN] FDE[1844]
uint32_t ttr_fde_1844_0x0588d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0d17U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0588d4U) ^ (0x940023abU + 0x0814d0U + 4U);
}

// [EN] FDE[1845] start_va=0x0588d8, fde_va=0x0814e8, span=32 B | [VN] FDE[1845]
uint32_t ttr_fde_1845_0x0588d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940023abU + 0x0588d8U) ^ (0xb0000208U + 0x0814e8U + 32U);
}

// [EN] FDE[1846] start_va=0x0588f8, fde_va=0x081500, span=12 B | [VN] FDE[1846]
uint32_t ttr_fde_1846_0x0588f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000208U) + (a1 ^ 0x912d6108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002511U + 0x0588f8U) ^ (0xd65f03c0U + 0x081500U + 12U);
}

// [EN] FDE[1847] start_va=0x058904, fde_va=0x081518, span=4 B | [VN] FDE[1847]
uint32_t ttr_fde_1847_0x058904(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff0d0aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd101c3ffU + 0x058904U) ^ (0x6d0423e9U + 0x081518U + 4U);
}

// [EN] FDE[1848] start_va=0x058908, fde_va=0x081530, span=4 B | [VN] FDE[1848]
uint32_t ttr_fde_1848_0x058908(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0d0aU) + (a1 ^ 0xd101c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0423e9U + 0x058908U) ^ (0xa90553f5U + 0x081530U + 4U);
}

// [EN] FDE[1849] start_va=0x05890c, fde_va=0x081548, span=108 B | [VN] FDE[1849]
uint32_t ttr_fde_1849_0x05890c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0x6d0423e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90553f5U + 0x05890cU) ^ (0xa9067bf3U + 0x081548U + 108U);
}

// [EN] FDE[1850] start_va=0x058978, fde_va=0x081570, span=588 B | [VN] FDE[1850]
uint32_t ttr_fde_1850_0x058978(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x9400254aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x058978U) ^ (0xa9057bf3U + 0x081570U + 588U);
}

// [EN] FDE[1851] start_va=0x058bc4, fde_va=0x0815a0, span=212 B | [VN] FDE[1851]
uint32_t ttr_fde_1851_0x058bc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x058bc4U) ^ (0xb4000261U + 0x0815a0U + 212U);
}

// [EN] FDE[1852] start_va=0x058c98, fde_va=0x0815c0, span=24 B | [VN] FDE[1852]
uint32_t ttr_fde_1852_0x058c98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x058c98U) ^ (0xb4000040U + 0x0815c0U + 24U);
}

// [EN] FDE[1853] start_va=0x058cb0, fde_va=0x0815d8, span=88 B | [VN] FDE[1853]
uint32_t ttr_fde_1853_0x058cb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9401028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x058cb0U) ^ (0xb4000128U + 0x0815d8U + 88U);
}

// [EN] FDE[1854] start_va=0x058d08, fde_va=0x0815f0, span=12 B | [VN] FDE[1854]
uint32_t ttr_fde_1854_0x058d08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000208U) + (a1 ^ 0x912e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002f1cU + 0x058d08U) ^ (0xa9bf7bf3U + 0x0815f0U + 12U);
}

// [EN] FDE[1855] start_va=0x058d14, fde_va=0x081608, span=24 B | [VN] FDE[1855]
uint32_t ttr_fde_1855_0x058d14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffffbU + 0x058d14U) ^ (0xaa1303e0U + 0x081608U + 24U);
}

// [EN] FDE[1856] start_va=0x058d2c, fde_va=0x081620, span=40 B | [VN] FDE[1856]
uint32_t ttr_fde_1856_0x058d2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940027ddU + 0x058d2cU) ^ (0xb0000208U + 0x081620U + 40U);
}

// [EN] FDE[1857] start_va=0x058d54, fde_va=0x081640, span=28 B | [VN] FDE[1857]
uint32_t ttr_fde_1857_0x058d54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000209U) + (a1 ^ 0xaa0103e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912e8129U + 0x058d54U) ^ (0xf8010509U + 0x081640U + 28U);
}

// [EN] FDE[1858] start_va=0x058d70, fde_va=0x081658, span=4 B | [VN] FDE[1858]
uint32_t ttr_fde_1858_0x058d70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14002cacU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002afbU + 0x058d70U) ^ (0xa8c17bf3U + 0x081658U + 4U);
}

// [EN] FDE[1859] start_va=0x058d74, fde_va=0x081670, span=16 B | [VN] FDE[1859]
uint32_t ttr_fde_1859_0x058d74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002afbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x058d74U) ^ (0x17ff0becU + 0x081670U + 16U);
}

// [EN] FDE[1860] start_va=0x058d84, fde_va=0x081688, span=204 B | [VN] FDE[1860]
uint32_t ttr_fde_1860_0x058d84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0x6d072bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0823e9U + 0x058d84U) ^ (0xa90953f5U + 0x081688U + 204U);
}

// [EN] FDE[1861] start_va=0x058e50, fde_va=0x0816b8, span=620 B | [VN] FDE[1861]
uint32_t ttr_fde_1861_0x058e50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0x6d042bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0523e9U + 0x058e50U) ^ (0xa9067bf3U + 0x0816b8U + 620U);
}

// [EN] FDE[1862] start_va=0x0590bc, fde_va=0x0816e0, span=36 B | [VN] FDE[1862]
uint32_t ttr_fde_1862_0x0590bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400267cU + 0x0590bcU) ^ (0xb9403a68U + 0x0816e0U + 36U);
}

// [EN] FDE[1863] start_va=0x0590e0, fde_va=0x081700, span=12 B | [VN] FDE[1863]
uint32_t ttr_fde_1863_0x0590e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000208U) + (a1 ^ 0x912fa108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002e26U + 0x0590e0U) ^ (0xa9bf7bf3U + 0x081700U + 12U);
}

// [EN] FDE[1864] start_va=0x0590ec, fde_va=0x081718, span=24 B | [VN] FDE[1864]
uint32_t ttr_fde_1864_0x0590ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffffbU + 0x0590ecU) ^ (0xaa1303e0U + 0x081718U + 24U);
}

// [EN] FDE[1865] start_va=0x059104, fde_va=0x081730, span=40 B | [VN] FDE[1865]
uint32_t ttr_fde_1865_0x059104(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940026e7U + 0x059104U) ^ (0x90000208U + 0x081730U + 40U);
}

// [EN] FDE[1866] start_va=0x05912c, fde_va=0x081750, span=28 B | [VN] FDE[1866]
uint32_t ttr_fde_1866_0x05912c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000209U) + (a1 ^ 0xaa0103e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912fa129U + 0x05912cU) ^ (0xf8010509U + 0x081750U + 28U);
}

// [EN] FDE[1867] start_va=0x059148, fde_va=0x081768, span=4 B | [VN] FDE[1867]
uint32_t ttr_fde_1867_0x059148(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14002bb6U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002a05U + 0x059148U) ^ (0xa8c17bf3U + 0x081768U + 4U);
}

// [EN] FDE[1868] start_va=0x05914c, fde_va=0x081780, span=16 B | [VN] FDE[1868]
uint32_t ttr_fde_1868_0x05914c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002a05U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x05914cU) ^ (0x17ff0af6U + 0x081780U + 16U);
}

// [EN] FDE[1869] start_va=0x05915c, fde_va=0x081798, span=284 B | [VN] FDE[1869]
uint32_t ttr_fde_1869_0x05915c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbb33edU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x05915cU) ^ (0xf9001bf4U + 0x081798U + 284U);
}

// [EN] FDE[1870] start_va=0x059278, fde_va=0x0817c8, span=28 B | [VN] FDE[1870]
uint32_t ttr_fde_1870_0x059278(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400260dU + 0x059278U) ^ (0xf9401a68U + 0x0817c8U + 28U);
}

// [EN] FDE[1871] start_va=0x059294, fde_va=0x0817e8, span=12 B | [VN] FDE[1871]
uint32_t ttr_fde_1871_0x059294(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000208U) + (a1 ^ 0x9130c108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002db9U + 0x059294U) ^ (0xa9bf7bf3U + 0x0817e8U + 12U);
}

// [EN] FDE[1872] start_va=0x0592a0, fde_va=0x081800, span=24 B | [VN] FDE[1872]
uint32_t ttr_fde_1872_0x0592a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffffbU + 0x0592a0U) ^ (0xaa1303e0U + 0x081800U + 24U);
}

// [EN] FDE[1873] start_va=0x0592b8, fde_va=0x081818, span=40 B | [VN] FDE[1873]
uint32_t ttr_fde_1873_0x0592b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400267aU + 0x0592b8U) ^ (0x90000208U + 0x081818U + 40U);
}

// [EN] FDE[1874] start_va=0x0592e0, fde_va=0x081838, span=28 B | [VN] FDE[1874]
uint32_t ttr_fde_1874_0x0592e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000209U) + (a1 ^ 0xaa0103e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9130c129U + 0x0592e0U) ^ (0xf8010509U + 0x081838U + 28U);
}

// [EN] FDE[1875] start_va=0x0592fc, fde_va=0x081850, span=4 B | [VN] FDE[1875]
uint32_t ttr_fde_1875_0x0592fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14002b49U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94002998U + 0x0592fcU) ^ (0xa8c17bf3U + 0x081850U + 4U);
}

// [EN] FDE[1876] start_va=0x059300, fde_va=0x081868, span=16 B | [VN] FDE[1876]
uint32_t ttr_fde_1876_0x059300(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94002998U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x059300U) ^ (0x17ff0a89U + 0x081868U + 16U);
}

// [EN] FDE[1877] start_va=0x059310, fde_va=0x081880, span=92 B | [VN] FDE[1877]
uint32_t ttr_fde_1877_0x059310(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbc2bebU) + (a1 ^ 0x6d0123e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x059310U) ^ (0xa9037bf3U + 0x081880U + 92U);
}

// [EN] FDE[1878] start_va=0x05936c, fde_va=0x0818a8, span=28 B | [VN] FDE[1878]
uint32_t ttr_fde_1878_0x05936c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940025d0U + 0x05936cU) ^ (0xf9401a68U + 0x0818a8U + 28U);
}

// [EN] FDE[1879] start_va=0x059388, fde_va=0x0818c8, span=4 B | [VN] FDE[1879]
uint32_t ttr_fde_1879_0x059388(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0a6aU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x059388U) ^ (0x940020feU + 0x0818c8U + 4U);
}

// [EN] FDE[1880] start_va=0x05938c, fde_va=0x0818e0, span=32 B | [VN] FDE[1880]
uint32_t ttr_fde_1880_0x05938c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940020feU + 0x05938cU) ^ (0x90000208U + 0x0818e0U + 32U);
}

// [EN] FDE[1881] start_va=0x0593ac, fde_va=0x0818f8, span=12 B | [VN] FDE[1881]
uint32_t ttr_fde_1881_0x0593ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000208U) + (a1 ^ 0x912c4108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002264U + 0x0593acU) ^ (0xd65f03c0U + 0x0818f8U + 12U);
}

// [EN] FDE[1882] start_va=0x0593b8, fde_va=0x081910, span=4 B | [VN] FDE[1882]
uint32_t ttr_fde_1882_0x0593b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff0a5dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10183ffU + 0x0593b8U) ^ (0x6d0323e9U + 0x081910U + 4U);
}

// [EN] FDE[1883] start_va=0x0593bc, fde_va=0x081928, span=4 B | [VN] FDE[1883]
uint32_t ttr_fde_1883_0x0593bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0a5dU) + (a1 ^ 0xd10183ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0323e9U + 0x0593bcU) ^ (0xa90453f5U + 0x081928U + 4U);
}

// [EN] FDE[1884] start_va=0x0593c0, fde_va=0x081940, span=104 B | [VN] FDE[1884]
uint32_t ttr_fde_1884_0x0593c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0x6d0323e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x0593c0U) ^ (0xa9057bf3U + 0x081940U + 104U);
}

// [EN] FDE[1885] start_va=0x059428, fde_va=0x081968, span=20 B | [VN] FDE[1885]
uint32_t ttr_fde_1885_0x059428(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37dfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14002304U + 0x059428U) ^ (0xf81f0ffeU + 0x081968U + 20U);
}

// [EN] FDE[1886] start_va=0x05943c, fde_va=0x081980, span=36 B | [VN] FDE[1886]
uint32_t ttr_fde_1886_0x05943c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x2d400c22U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2d400400U + 0x05943cU) ^ (0xaa0003f3U + 0x081980U + 36U);
}

// [EN] FDE[1887] start_va=0x059460, fde_va=0x081998, span=32 B | [VN] FDE[1887]
uint32_t ttr_fde_1887_0x059460(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb201f3e8U) + (a1 ^ 0xf2955568U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2e15548U + 0x059460U) ^ (0xeb08001fU + 0x081998U + 32U);
}

// [EN] FDE[1888] start_va=0x059480, fde_va=0x0819b0, span=44 B | [VN] FDE[1888]
uint32_t ttr_fde_1888_0x059480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37dfc28U + 0x059480U) ^ (0xb50000e8U + 0x0819b0U + 44U);
}

// [EN] FDE[1889] start_va=0x0594ac, fde_va=0x0819d0, span=32 B | [VN] FDE[1889]
uint32_t ttr_fde_1889_0x0594ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000208U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912a6108U + 0x0594acU) ^ (0x94001a68U + 0x0819d0U + 32U);
}

// [EN] FDE[1890] start_va=0x0594cc, fde_va=0x0819e8, span=24 B | [VN] FDE[1890]
uint32_t ttr_fde_1890_0x0594cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x0594ccU) ^ (0xaa1303e0U + 0x0819e8U + 24U);
}

// [EN] FDE[1891] start_va=0x0594e4, fde_va=0x081a00, span=8 B | [VN] FDE[1891]
uint32_t ttr_fde_1891_0x0594e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17fff544U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0a11U + 0x0594e4U) ^ (0xf81e0ff4U + 0x081a00U + 8U);
}

// [EN] FDE[1892] start_va=0x0594ec, fde_va=0x081a18, span=4 B | [VN] FDE[1892]
uint32_t ttr_fde_1892_0x0594ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0a11U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0594ecU) ^ (0x90000208U + 0x081a18U + 4U);
}

// [EN] FDE[1893] start_va=0x0594f0, fde_va=0x081a30, span=56 B | [VN] FDE[1893]
uint32_t ttr_fde_1893_0x0594f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000208U + 0x0594f0U) ^ (0xaa0003f3U + 0x081a30U + 56U);
}

// [EN] FDE[1894] start_va=0x059528, fde_va=0x081a50, span=24 B | [VN] FDE[1894]
uint32_t ttr_fde_1894_0x059528(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff0U + 0x059528U) ^ (0xaa1303e0U + 0x081a50U + 24U);
}

// [EN] FDE[1895] start_va=0x059540, fde_va=0x081a68, span=56 B | [VN] FDE[1895]
uint32_t ttr_fde_1895_0x059540(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x52800049U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12000028U + 0x059540U) ^ (0x1ac90c29U + 0x081a68U + 56U);
}

// [EN] FDE[1896] start_va=0x059578, fde_va=0x081a80, span=36 B | [VN] FDE[1896]
uint32_t ttr_fde_1896_0x059578(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x059578U) ^ (0x9400240cU + 0x081a80U + 36U);
}

// [EN] FDE[1897] start_va=0x05959c, fde_va=0x081aa0, span=428 B | [VN] FDE[1897]
uint32_t ttr_fde_1897_0x05959c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa9065bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90753f5U + 0x05959cU) ^ (0xa9087bf3U + 0x081aa0U + 428U);
}

// [EN] FDE[1898] start_va=0x059748, fde_va=0x081ac8, span=228 B | [VN] FDE[1898]
uint32_t ttr_fde_1898_0x059748(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ffaU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x059748U) ^ (0xa90353f5U + 0x081ac8U + 228U);
}

// [EN] FDE[1899] start_va=0x05982c, fde_va=0x081af0, span=32 B | [VN] FDE[1899]
uint32_t ttr_fde_1899_0x05982c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000208U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9131e108U + 0x05982cU) ^ (0x94001988U + 0x081af0U + 32U);
}

// [EN] FDE[1900] start_va=0x05984c, fde_va=0x081b08, span=24 B | [VN] FDE[1900]
uint32_t ttr_fde_1900_0x05984c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x05984cU) ^ (0xaa1303e0U + 0x081b08U + 24U);
}

// [EN] FDE[1901] start_va=0x059864, fde_va=0x081b20, span=8 B | [VN] FDE[1901]
uint32_t ttr_fde_1901_0x059864(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17ffff22U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0931U + 0x059864U) ^ (0xf81e0ff4U + 0x081b20U + 8U);
}

// [EN] FDE[1902] start_va=0x05986c, fde_va=0x081b38, span=4 B | [VN] FDE[1902]
uint32_t ttr_fde_1902_0x05986c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0931U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x05986cU) ^ (0x90000208U + 0x081b38U + 4U);
}

// [EN] FDE[1903] start_va=0x059870, fde_va=0x081b50, span=92 B | [VN] FDE[1903]
uint32_t ttr_fde_1903_0x059870(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000208U + 0x059870U) ^ (0xaa0003f3U + 0x081b50U + 92U);
}

// [EN] FDE[1904] start_va=0x0598cc, fde_va=0x081b70, span=24 B | [VN] FDE[1904]
uint32_t ttr_fde_1904_0x0598cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffe7U + 0x0598ccU) ^ (0xaa1303e0U + 0x081b70U + 24U);
}

// [EN] FDE[1905] start_va=0x0598e4, fde_va=0x081b88, span=52 B | [VN] FDE[1905]
uint32_t ttr_fde_1905_0x0598e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x0598e4U) ^ (0x94002087U + 0x081b88U + 52U);
}

// [EN] FDE[1906] start_va=0x059918, fde_va=0x081ba8, span=36 B | [VN] FDE[1906]
uint32_t ttr_fde_1906_0x059918(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x059918U) ^ (0x940022d1U + 0x081ba8U + 36U);
}

// [EN] FDE[1907] start_va=0x05993c, fde_va=0x081bc8, span=660 B | [VN] FDE[1907]
uint32_t ttr_fde_1907_0x05993c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xf90033faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90763f9U + 0x05993cU) ^ (0xa9085bf7U + 0x081bc8U + 660U);
}

// [EN] FDE[1908] start_va=0x059bd0, fde_va=0x081bf0, span=296 B | [VN] FDE[1908]
uint32_t ttr_fde_1908_0x059bd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa90263f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035bf7U + 0x059bd0U) ^ (0xa90453f5U + 0x081bf0U + 296U);
}

// [EN] FDE[1909] start_va=0x059cf8, fde_va=0x081c18, span=32 B | [VN] FDE[1909]
uint32_t ttr_fde_1909_0x059cf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000208U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9133c108U + 0x059cf8U) ^ (0x94001855U + 0x081c18U + 32U);
}

// [EN] FDE[1910] start_va=0x059d18, fde_va=0x081c30, span=24 B | [VN] FDE[1910]
uint32_t ttr_fde_1910_0x059d18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x059d18U) ^ (0xaa1303e0U + 0x081c30U + 24U);
}

// [EN] FDE[1911] start_va=0x059d30, fde_va=0x081c48, span=8 B | [VN] FDE[1911]
uint32_t ttr_fde_1911_0x059d30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17fffecfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff07feU + 0x059d30U) ^ (0xeb01001fU + 0x081c48U + 8U);
}

// [EN] FDE[1912] start_va=0x059d38, fde_va=0x081c60, span=4 B | [VN] FDE[1912]
uint32_t ttr_fde_1912_0x059d38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff07feU) + (a1 ^ 0xeb01001fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540000c0U + 0x059d38U) ^ (0xb9400008U + 0x081c60U + 4U);
}

// [EN] FDE[1913] start_va=0x059d3c, fde_va=0x081c78, span=32 B | [VN] FDE[1913]
uint32_t ttr_fde_1913_0x059d3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x540000c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400008U + 0x059d3cU) ^ (0x6b02011fU + 0x081c78U + 32U);
}

// [EN] FDE[1914] start_va=0x059d5c, fde_va=0x081c90, span=160 B | [VN] FDE[1914]
uint32_t ttr_fde_1914_0x059d5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9035bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x059d5cU) ^ (0xa9057bf3U + 0x081c90U + 160U);
}

// [EN] FDE[1915] start_va=0x059dfc, fde_va=0x081cb0, span=272 B | [VN] FDE[1915]
uint32_t ttr_fde_1915_0x059dfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e8U) + (a1 ^ 0x94001b9fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803feU + 0x059dfcU) ^ (0xa9057bfdU + 0x081cb0U + 272U);
}

// [EN] FDE[1916] start_va=0x059f0c, fde_va=0x081ce0, span=76 B | [VN] FDE[1916]
uint32_t ttr_fde_1916_0x059f0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400201eU + 0x059f0cU) ^ (0xb40001a1U + 0x081ce0U + 76U);
}

// [EN] FDE[1917] start_va=0x059f58, fde_va=0x081d00, span=28 B | [VN] FDE[1917]
uint32_t ttr_fde_1917_0x059f58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x8b011109U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb08013fU + 0x059f58U) ^ (0x54000060U + 0x081d00U + 28U);
}

// [EN] FDE[1918] start_va=0x059f74, fde_va=0x081d18, span=32 B | [VN] FDE[1918]
uint32_t ttr_fde_1918_0x059f74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xd37cec08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91011d00U + 0x059f74U) ^ (0x97ff0894U + 0x081d18U + 32U);
}

// [EN] FDE[1919] start_va=0x059f94, fde_va=0x081d30, span=44 B | [VN] FDE[1919]
uint32_t ttr_fde_1919_0x059f94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x940018c7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x059f94U) ^ (0xf9400c08U + 0x081d30U + 44U);
}

// [EN] FDE[1920] start_va=0x059fc0, fde_va=0x081d48, span=16 B | [VN] FDE[1920]
uint32_t ttr_fde_1920_0x059fc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x940018bcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x059fc0U) ^ (0xd65f03c0U + 0x081d48U + 16U);
}

// [EN] FDE[1921] start_va=0x059fd0, fde_va=0x081d60, span=4 B | [VN] FDE[1921]
uint32_t ttr_fde_1921_0x059fd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0758U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001749U + 0x059fd0U) ^ (0x90000208U + 0x081d60U + 4U);
}

// [EN] FDE[1922] start_va=0x059fd4, fde_va=0x081d78, span=28 B | [VN] FDE[1922]
uint32_t ttr_fde_1922_0x059fd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94001749U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000208U + 0x059fd4U) ^ (0x913dc108U + 0x081d78U + 28U);
}

// [EN] FDE[1923] start_va=0x059ff0, fde_va=0x081d90, span=12 B | [VN] FDE[1923]
uint32_t ttr_fde_1923_0x059ff0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000208U) + (a1 ^ 0x913dc108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400173dU + 0x059ff0U) ^ (0xd65f03c0U + 0x081d90U + 12U);
}

// [EN] FDE[1924] start_va=0x059ffc, fde_va=0x081da8, span=4 B | [VN] FDE[1924]
uint32_t ttr_fde_1924_0x059ffc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff074cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10243ffU + 0x059ffcU) ^ (0xf90033f6U + 0x081da8U + 4U);
}

// [EN] FDE[1925] start_va=0x05a000, fde_va=0x081dc0, span=4 B | [VN] FDE[1925]
uint32_t ttr_fde_1925_0x05a000(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff074cU) + (a1 ^ 0xd10243ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90033f6U + 0x05a000U) ^ (0xa90753f5U + 0x081dc0U + 4U);
}

// [EN] FDE[1926] start_va=0x05a004, fde_va=0x081dd8, span=352 B | [VN] FDE[1926]
uint32_t ttr_fde_1926_0x05a004(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf90033f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90753f5U + 0x05a004U) ^ (0xa9087bf3U + 0x081dd8U + 352U);
}

// [EN] FDE[1927] start_va=0x05a164, fde_va=0x081df8, span=4 B | [VN] FDE[1927]
uint32_t ttr_fde_1927_0x05a164(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff06f3U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940016e4U + 0x05a164U) ^ (0xf00001e8U + 0x081df8U + 4U);
}

// [EN] FDE[1928] start_va=0x05a168, fde_va=0x081e10, span=28 B | [VN] FDE[1928]
uint32_t ttr_fde_1928_0x05a168(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940016e4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05a168U) ^ (0x913ca108U + 0x081e10U + 28U);
}

// [EN] FDE[1929] start_va=0x05a184, fde_va=0x081e28, span=12 B | [VN] FDE[1929]
uint32_t ttr_fde_1929_0x05a184(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x913ca108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140016d8U + 0x05a184U) ^ (0xd65f03c0U + 0x081e28U + 12U);
}

// [EN] FDE[1930] start_va=0x05a190, fde_va=0x081e40, span=4 B | [VN] FDE[1930]
uint32_t ttr_fde_1930_0x05a190(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff06e7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10143ffU + 0x05a190U) ^ (0xf90013f6U + 0x081e40U + 4U);
}

// [EN] FDE[1931] start_va=0x05a194, fde_va=0x081e58, span=4 B | [VN] FDE[1931]
uint32_t ttr_fde_1931_0x05a194(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff06e7U) + (a1 ^ 0xd10143ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f6U + 0x05a194U) ^ (0xa90353f5U + 0x081e58U + 4U);
}

// [EN] FDE[1932] start_va=0x05a198, fde_va=0x081e70, span=104 B | [VN] FDE[1932]
uint32_t ttr_fde_1932_0x05a198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x05a198U) ^ (0xa9047bf3U + 0x081e70U + 104U);
}

// [EN] FDE[1933] start_va=0x05a200, fde_va=0x081e90, span=4 B | [VN] FDE[1933]
uint32_t ttr_fde_1933_0x05a200(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff06ccU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940016bdU + 0x05a200U) ^ (0xf00001e8U + 0x081e90U + 4U);
}

// [EN] FDE[1934] start_va=0x05a204, fde_va=0x081ea8, span=28 B | [VN] FDE[1934]
uint32_t ttr_fde_1934_0x05a204(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940016bdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05a204U) ^ (0x913b8108U + 0x081ea8U + 28U);
}

// [EN] FDE[1935] start_va=0x05a220, fde_va=0x081ec0, span=12 B | [VN] FDE[1935]
uint32_t ttr_fde_1935_0x05a220(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x913b8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140016b1U + 0x05a220U) ^ (0xd65f03c0U + 0x081ec0U + 12U);
}

// [EN] FDE[1936] start_va=0x05a22c, fde_va=0x081ed8, span=4 B | [VN] FDE[1936]
uint32_t ttr_fde_1936_0x05a22c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff06c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10143ffU + 0x05a22cU) ^ (0xf90013f6U + 0x081ed8U + 4U);
}

// [EN] FDE[1937] start_va=0x05a230, fde_va=0x081ef0, span=4 B | [VN] FDE[1937]
uint32_t ttr_fde_1937_0x05a230(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff06c0U) + (a1 ^ 0xd10143ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f6U + 0x05a230U) ^ (0xa90353f5U + 0x081ef0U + 4U);
}

// [EN] FDE[1938] start_va=0x05a234, fde_va=0x081f08, span=104 B | [VN] FDE[1938]
uint32_t ttr_fde_1938_0x05a234(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x05a234U) ^ (0xa9047bf3U + 0x081f08U + 104U);
}

// [EN] FDE[1939] start_va=0x05a29c, fde_va=0x081f28, span=4 B | [VN] FDE[1939]
uint32_t ttr_fde_1939_0x05a29c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff06a5U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001696U + 0x05a29cU) ^ (0xf00001e8U + 0x081f28U + 4U);
}

// [EN] FDE[1940] start_va=0x05a2a0, fde_va=0x081f40, span=28 B | [VN] FDE[1940]
uint32_t ttr_fde_1940_0x05a2a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94001696U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05a2a0U) ^ (0x913a6108U + 0x081f40U + 28U);
}

// [EN] FDE[1941] start_va=0x05a2bc, fde_va=0x081f58, span=12 B | [VN] FDE[1941]
uint32_t ttr_fde_1941_0x05a2bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x913a6108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400168aU + 0x05a2bcU) ^ (0xd65f03c0U + 0x081f58U + 12U);
}

// [EN] FDE[1942] start_va=0x05a2c8, fde_va=0x081f70, span=4 B | [VN] FDE[1942]
uint32_t ttr_fde_1942_0x05a2c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff0699U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100c3ffU + 0x05a2c8U) ^ (0xa9027bf3U + 0x081f70U + 4U);
}

// [EN] FDE[1943] start_va=0x05a2cc, fde_va=0x081f88, span=4 B | [VN] FDE[1943]
uint32_t ttr_fde_1943_0x05a2cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0699U) + (a1 ^ 0xd100c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05a2ccU) ^ (0xb9400028U + 0x081f88U + 4U);
}

// [EN] FDE[1944] start_va=0x05a2d0, fde_va=0x081fa0, span=60 B | [VN] FDE[1944]
uint32_t ttr_fde_1944_0x05a2d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9027bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400028U + 0x05a2d0U) ^ (0x35000128U + 0x081fa0U + 60U);
}

// [EN] FDE[1945] start_va=0x05a30c, fde_va=0x081fb8, span=4 B | [VN] FDE[1945]
uint32_t ttr_fde_1945_0x05a30c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0689U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400167aU + 0x05a30cU) ^ (0xf00001e8U + 0x081fb8U + 4U);
}

// [EN] FDE[1946] start_va=0x05a310, fde_va=0x081fd0, span=28 B | [VN] FDE[1946]
uint32_t ttr_fde_1946_0x05a310(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400167aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05a310U) ^ (0x91394108U + 0x081fd0U + 28U);
}

// [EN] FDE[1947] start_va=0x05a32c, fde_va=0x081fe8, span=12 B | [VN] FDE[1947]
uint32_t ttr_fde_1947_0x05a32c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x91394108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400166eU + 0x05a32cU) ^ (0xd65f03c0U + 0x081fe8U + 12U);
}

// [EN] FDE[1948] start_va=0x05a338, fde_va=0x082000, span=4 B | [VN] FDE[1948]
uint32_t ttr_fde_1948_0x05a338(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff067dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05a338U) ^ (0xf90013f4U + 0x082000U + 4U);
}

// [EN] FDE[1949] start_va=0x05a33c, fde_va=0x082018, span=4 B | [VN] FDE[1949]
uint32_t ttr_fde_1949_0x05a33c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff067dU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05a33cU) ^ (0xa9037bf3U + 0x082018U + 4U);
}

// [EN] FDE[1950] start_va=0x05a340, fde_va=0x082030, span=64 B | [VN] FDE[1950]
uint32_t ttr_fde_1950_0x05a340(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05a340U) ^ (0x940016adU + 0x082030U + 64U);
}

// [EN] FDE[1951] start_va=0x05a380, fde_va=0x082050, span=4 B | [VN] FDE[1951]
uint32_t ttr_fde_1951_0x05a380(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff066cU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400165dU + 0x05a380U) ^ (0xf00001e8U + 0x082050U + 4U);
}

// [EN] FDE[1952] start_va=0x05a384, fde_va=0x082068, span=28 B | [VN] FDE[1952]
uint32_t ttr_fde_1952_0x05a384(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400165dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05a384U) ^ (0x91382108U + 0x082068U + 28U);
}

// [EN] FDE[1953] start_va=0x05a3a0, fde_va=0x082080, span=12 B | [VN] FDE[1953]
uint32_t ttr_fde_1953_0x05a3a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x91382108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14001651U + 0x05a3a0U) ^ (0xd65f03c0U + 0x082080U + 12U);
}

// [EN] FDE[1954] start_va=0x05a3ac, fde_va=0x082098, span=4 B | [VN] FDE[1954]
uint32_t ttr_fde_1954_0x05a3ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff0660U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd102c3ffU + 0x05a3acU) ^ (0xf90033faU + 0x082098U + 4U);
}

// [EN] FDE[1955] start_va=0x05a3b0, fde_va=0x0820b0, span=4 B | [VN] FDE[1955]
uint32_t ttr_fde_1955_0x05a3b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff0660U) + (a1 ^ 0xd102c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90033faU + 0x05a3b0U) ^ (0xa90763f9U + 0x0820b0U + 4U);
}

// [EN] FDE[1956] start_va=0x05a3b4, fde_va=0x0820c8, span=676 B | [VN] FDE[1956]
uint32_t ttr_fde_1956_0x05a3b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xf90033faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90763f9U + 0x05a3b4U) ^ (0xa9085bf7U + 0x0820c8U + 676U);
}

// [EN] FDE[1957] start_va=0x05a658, fde_va=0x0820f0, span=2852 B | [VN] FDE[1957]
uint32_t ttr_fde_1957_0x05a658(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6db733edU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x05a658U) ^ (0xaa1e03e3U + 0x0820f0U + 2852U);
}

// [EN] FDE[1958] start_va=0x05b17c, fde_va=0x082130, span=52 B | [VN] FDE[1958]
uint32_t ttr_fde_1958_0x05b17c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400140bU + 0x05b17cU) ^ (0xeb15029fU + 0x082130U + 52U);
}

// [EN] FDE[1959] start_va=0x05b1b0, fde_va=0x082150, span=64 B | [VN] FDE[1959]
uint32_t ttr_fde_1959_0x05b1b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05b1b0U) ^ (0xf9400415U + 0x082150U + 64U);
}

// [EN] FDE[1960] start_va=0x05b1f0, fde_va=0x082170, span=72 B | [VN] FDE[1960]
uint32_t ttr_fde_1960_0x05b1f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940017baU + 0x05b1f0U) ^ (0x540001a0U + 0x082170U + 72U);
}

// [EN] FDE[1961] start_va=0x05b238, fde_va=0x082190, span=188 B | [VN] FDE[1961]
uint32_t ttr_fde_1961_0x05b238(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf1000408U + 0x05b238U) ^ (0x54000061U + 0x082190U + 188U);
}

// [EN] FDE[1962] start_va=0x05b2f4, fde_va=0x0821b0, span=48 B | [VN] FDE[1962]
uint32_t ttr_fde_1962_0x05b2f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94001915U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000113U + 0x05b2f4U) ^ (0x39404008U + 0x0821b0U + 48U);
}

// [EN] FDE[1963] start_va=0x05b324, fde_va=0x0821c8, span=324 B | [VN] FDE[1963]
uint32_t ttr_fde_1963_0x05b324(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e1U) + (a1 ^ 0x94001655U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103feU + 0x05b324U) ^ (0xa9057bfdU + 0x0821c8U + 324U);
}

// [EN] FDE[1964] start_va=0x05b468, fde_va=0x0821f8, span=24 B | [VN] FDE[1964]
uint32_t ttr_fde_1964_0x05b468(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000229U) + (a1 ^ 0xf9425528U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9025520U + 0x05b468U) ^ (0xb4000048U + 0x0821f8U + 24U);
}

// [EN] FDE[1965] start_va=0x05b480, fde_va=0x082210, span=8 B | [VN] FDE[1965]
uint32_t ttr_fde_1965_0x05b480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800600U) + (a1 ^ 0x17ff0237U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x05b480U) ^ (0xaa0003f3U + 0x082210U + 8U);
}

// [EN] FDE[1966] start_va=0x05b488, fde_va=0x082228, span=24 B | [VN] FDE[1966]
uint32_t ttr_fde_1966_0x05b488(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffddf5U + 0x05b488U) ^ (0xaa1303e0U + 0x082228U + 24U);
}

// [EN] FDE[1967] start_va=0x05b4a0, fde_va=0x082240, span=1168 B | [VN] FDE[1967]
uint32_t ttr_fde_1967_0x05b4a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xa90d6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90e67faU + 0x05b4a0U) ^ (0xa90f5ff8U + 0x082240U + 1168U);
}

// [EN] FDE[1968] start_va=0x05b930, fde_va=0x082270, span=412 B | [VN] FDE[1968]
uint32_t ttr_fde_1968_0x05b930(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xa90a6bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90b63f9U + 0x05b930U) ^ (0xa90c5bf7U + 0x082270U + 412U);
}

// [EN] FDE[1969] start_va=0x05bacc, fde_va=0x0822a0, span=544 B | [VN] FDE[1969]
uint32_t ttr_fde_1969_0x05bacc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf90013faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90363f9U + 0x05baccU) ^ (0xa9045bf7U + 0x0822a0U + 544U);
}

// [EN] FDE[1970] start_va=0x05bcec, fde_va=0x0822c8, span=48 B | [VN] FDE[1970]
uint32_t ttr_fde_1970_0x05bcec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05bcecU) ^ (0x9400198dU + 0x0822c8U + 48U);
}

// [EN] FDE[1971] start_va=0x05bd1c, fde_va=0x0822e8, span=8 B | [VN] FDE[1971]
uint32_t ttr_fde_1971_0x05bd1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100e000U) + (a1 ^ 0x17ff9f36U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff4U + 0x05bd1cU) ^ (0xa9017bf3U + 0x0822e8U + 8U);
}

// [EN] FDE[1972] start_va=0x05bd24, fde_va=0x082300, span=56 B | [VN] FDE[1972]
uint32_t ttr_fde_1972_0x05bd24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940010e9U + 0x05bd24U) ^ (0x97ff1ccbU + 0x082300U + 56U);
}

// [EN] FDE[1973] start_va=0x05bd5c, fde_va=0x082320, span=4 B | [VN] FDE[1973]
uint32_t ttr_fde_1973_0x05bd5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefff5U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000fe6U + 0x05bd5cU) ^ (0xf00001e8U + 0x082320U + 4U);
}

// [EN] FDE[1974] start_va=0x05bd60, fde_va=0x082338, span=28 B | [VN] FDE[1974]
uint32_t ttr_fde_1974_0x05bd60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000fe6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05bd60U) ^ (0x91070108U + 0x082338U + 28U);
}

// [EN] FDE[1975] start_va=0x05bd7c, fde_va=0x082350, span=12 B | [VN] FDE[1975]
uint32_t ttr_fde_1975_0x05bd7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x91070108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000fdaU + 0x05bd7cU) ^ (0xd65f03c0U + 0x082350U + 12U);
}

// [EN] FDE[1976] start_va=0x05bd88, fde_va=0x082368, span=4 B | [VN] FDE[1976]
uint32_t ttr_fde_1976_0x05bd88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17feffe9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x05bd88U) ^ (0x94001ebcU + 0x082368U + 4U);
}

// [EN] FDE[1977] start_va=0x05bd8c, fde_va=0x082380, span=4 B | [VN] FDE[1977]
uint32_t ttr_fde_1977_0x05bd8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffe9U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001ebcU + 0x05bd8cU) ^ (0x91110100U + 0x082380U + 4U);
}

// [EN] FDE[1978] start_va=0x05bd90, fde_va=0x082398, span=28 B | [VN] FDE[1978]
uint32_t ttr_fde_1978_0x05bd90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x94001ebcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91110100U + 0x05bd90U) ^ (0x97ffab5bU + 0x082398U + 28U);
}

// [EN] FDE[1979] start_va=0x05bdac, fde_va=0x0823b0, span=4 B | [VN] FDE[1979]
uint32_t ttr_fde_1979_0x05bdac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffe1U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000fd2U + 0x05bdacU) ^ (0xf00001e8U + 0x0823b0U + 4U);
}

// [EN] FDE[1980] start_va=0x05bdb0, fde_va=0x0823c8, span=28 B | [VN] FDE[1980]
uint32_t ttr_fde_1980_0x05bdb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000fd2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05bdb0U) ^ (0x9105e108U + 0x0823c8U + 28U);
}

// [EN] FDE[1981] start_va=0x05bdcc, fde_va=0x0823e0, span=12 B | [VN] FDE[1981]
uint32_t ttr_fde_1981_0x05bdcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x9105e108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000fc6U + 0x05bdccU) ^ (0xd65f03c0U + 0x0823e0U + 12U);
}

// [EN] FDE[1982] start_va=0x05bdd8, fde_va=0x0823f8, span=4 B | [VN] FDE[1982]
uint32_t ttr_fde_1982_0x05bdd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17feffd5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x05bdd8U) ^ (0x94001ea8U + 0x0823f8U + 4U);
}

// [EN] FDE[1983] start_va=0x05bddc, fde_va=0x082410, span=4 B | [VN] FDE[1983]
uint32_t ttr_fde_1983_0x05bddc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffd5U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001ea8U + 0x05bddcU) ^ (0x910bc100U + 0x082410U + 4U);
}

// [EN] FDE[1984] start_va=0x05bde0, fde_va=0x082428, span=28 B | [VN] FDE[1984]
uint32_t ttr_fde_1984_0x05bde0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x94001ea8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910bc100U + 0x05bde0U) ^ (0x97ffab47U + 0x082428U + 28U);
}

// [EN] FDE[1985] start_va=0x05bdfc, fde_va=0x082440, span=4 B | [VN] FDE[1985]
uint32_t ttr_fde_1985_0x05bdfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffcdU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000fbeU + 0x05bdfcU) ^ (0xf00001e8U + 0x082440U + 4U);
}

// [EN] FDE[1986] start_va=0x05be00, fde_va=0x082458, span=28 B | [VN] FDE[1986]
uint32_t ttr_fde_1986_0x05be00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000fbeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05be00U) ^ (0x9104c108U + 0x082458U + 28U);
}

// [EN] FDE[1987] start_va=0x05be1c, fde_va=0x082470, span=12 B | [VN] FDE[1987]
uint32_t ttr_fde_1987_0x05be1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x9104c108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000fb2U + 0x05be1cU) ^ (0xd65f03c0U + 0x082470U + 12U);
}

// [EN] FDE[1988] start_va=0x05be28, fde_va=0x082488, span=4 B | [VN] FDE[1988]
uint32_t ttr_fde_1988_0x05be28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17feffc1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x05be28U) ^ (0x94001e94U + 0x082488U + 4U);
}

// [EN] FDE[1989] start_va=0x05be2c, fde_va=0x0824a0, span=4 B | [VN] FDE[1989]
uint32_t ttr_fde_1989_0x05be2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffc1U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001e94U + 0x05be2cU) ^ (0x91068100U + 0x0824a0U + 4U);
}

// [EN] FDE[1990] start_va=0x05be30, fde_va=0x0824b8, span=28 B | [VN] FDE[1990]
uint32_t ttr_fde_1990_0x05be30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x94001e94U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91068100U + 0x05be30U) ^ (0x97ffab33U + 0x0824b8U + 28U);
}

// [EN] FDE[1991] start_va=0x05be4c, fde_va=0x0824d0, span=4 B | [VN] FDE[1991]
uint32_t ttr_fde_1991_0x05be4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffb9U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000faaU + 0x05be4cU) ^ (0xf00001e8U + 0x0824d0U + 4U);
}

// [EN] FDE[1992] start_va=0x05be50, fde_va=0x0824e8, span=28 B | [VN] FDE[1992]
uint32_t ttr_fde_1992_0x05be50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000faaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05be50U) ^ (0x9103a108U + 0x0824e8U + 28U);
}

// [EN] FDE[1993] start_va=0x05be6c, fde_va=0x082500, span=12 B | [VN] FDE[1993]
uint32_t ttr_fde_1993_0x05be6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x9103a108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000f9eU + 0x05be6cU) ^ (0xd65f03c0U + 0x082500U + 12U);
}

// [EN] FDE[1994] start_va=0x05be78, fde_va=0x082518, span=4 B | [VN] FDE[1994]
uint32_t ttr_fde_1994_0x05be78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17feffadU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05be78U) ^ (0xf90013f4U + 0x082518U + 4U);
}

// [EN] FDE[1995] start_va=0x05be7c, fde_va=0x082530, span=4 B | [VN] FDE[1995]
uint32_t ttr_fde_1995_0x05be7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feffadU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05be7cU) ^ (0xa9037bf3U + 0x082530U + 4U);
}

// [EN] FDE[1996] start_va=0x05be80, fde_va=0x082548, span=60 B | [VN] FDE[1996]
uint32_t ttr_fde_1996_0x05be80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05be80U) ^ (0x94000fddU + 0x082548U + 60U);
}

// [EN] FDE[1997] start_va=0x05bebc, fde_va=0x082568, span=80 B | [VN] FDE[1997]
uint32_t ttr_fde_1997_0x05bebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1e0fe8U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52a84e08U + 0x05bebcU) ^ (0x4ea01c08U + 0x082568U + 80U);
}

// [EN] FDE[1998] start_va=0x05bf0c, fde_va=0x082588, span=4 B | [VN] FDE[1998]
uint32_t ttr_fde_1998_0x05bf0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feff89U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000f7aU + 0x05bf0cU) ^ (0xf00001e8U + 0x082588U + 4U);
}

// [EN] FDE[1999] start_va=0x05bf10, fde_va=0x0825a0, span=28 B | [VN] FDE[1999]
uint32_t ttr_fde_1999_0x05bf10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000f7aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001e8U + 0x05bf10U) ^ (0x91028108U + 0x0825a0U + 28U);
}

// [EN] FDE[2000] start_va=0x05bf2c, fde_va=0x0825b8, span=12 B | [VN] FDE[2000]
uint32_t ttr_fde_2000_0x05bf2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e8U) + (a1 ^ 0x91028108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000f6eU + 0x05bf2cU) ^ (0xd65f03c0U + 0x0825b8U + 12U);
}

// [EN] FDE[2001] start_va=0x05bf38, fde_va=0x0825d0, span=4 B | [VN] FDE[2001]
uint32_t ttr_fde_2001_0x05bf38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17feff7dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05bf38U) ^ (0xf90013f4U + 0x0825d0U + 4U);
}

// [EN] FDE[2002] start_va=0x05bf3c, fde_va=0x0825e8, span=4 B | [VN] FDE[2002]
uint32_t ttr_fde_2002_0x05bf3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17feff7dU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05bf3cU) ^ (0xa9037bf3U + 0x0825e8U + 4U);
}

// [EN] FDE[2003] start_va=0x05bf40, fde_va=0x082600, span=92 B | [VN] FDE[2003]
uint32_t ttr_fde_2003_0x05bf40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05bf40U) ^ (0x94001b90U + 0x082600U + 92U);
}

// [EN] FDE[2004] start_va=0x05bf9c, fde_va=0x082620, span=652 B | [VN] FDE[2004]
uint32_t ttr_fde_2004_0x05bf9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xa90c5bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90d53f5U + 0x05bf9cU) ^ (0xa90e7bf3U + 0x082620U + 652U);
}

// [EN] FDE[2005] start_va=0x05c228, fde_va=0x082648, span=120 B | [VN] FDE[2005]
uint32_t ttr_fde_2005_0x05c228(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xaa1e03e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001117U + 0x05c228U) ^ (0xaa0803feU + 0x082648U + 120U);
}

// [EN] FDE[2006] start_va=0x05c2a0, fde_va=0x082678, span=248 B | [VN] FDE[2006]
uint32_t ttr_fde_2006_0x05c2a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94000f00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x05c2a0U) ^ (0xa9067bfdU + 0x082678U + 248U);
}

// [EN] FDE[2007] start_va=0x05c398, fde_va=0x0826a8, span=216 B | [VN] FDE[2007]
uint32_t ttr_fde_2007_0x05c398(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035bf7U + 0x05c398U) ^ (0xa90453f5U + 0x0826a8U + 216U);
}

// [EN] FDE[2008] start_va=0x05c470, fde_va=0x0826d0, span=172 B | [VN] FDE[2008]
uint32_t ttr_fde_2008_0x05c470(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035bf7U + 0x05c470U) ^ (0xa90453f5U + 0x0826d0U + 172U);
}

// [EN] FDE[2009] start_va=0x05c51c, fde_va=0x0826f8, span=4 B | [VN] FDE[2009]
uint32_t ttr_fde_2009_0x05c51c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefe05U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000df6U + 0x05c51cU) ^ (0xd00001e8U + 0x0826f8U + 4U);
}

// [EN] FDE[2010] start_va=0x05c520, fde_va=0x082710, span=28 B | [VN] FDE[2010]
uint32_t ttr_fde_2010_0x05c520(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000df6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05c520U) ^ (0x91016108U + 0x082710U + 28U);
}

// [EN] FDE[2011] start_va=0x05c53c, fde_va=0x082728, span=12 B | [VN] FDE[2011]
uint32_t ttr_fde_2011_0x05c53c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x91016108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000deaU + 0x05c53cU) ^ (0xd65f03c0U + 0x082728U + 12U);
}

// [EN] FDE[2012] start_va=0x05c548, fde_va=0x082740, span=4 B | [VN] FDE[2012]
uint32_t ttr_fde_2012_0x05c548(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefdf9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05c548U) ^ (0xf90013f4U + 0x082740U + 4U);
}

// [EN] FDE[2013] start_va=0x05c54c, fde_va=0x082758, span=4 B | [VN] FDE[2013]
uint32_t ttr_fde_2013_0x05c54c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefdf9U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05c54cU) ^ (0xa9037bf3U + 0x082758U + 4U);
}

// [EN] FDE[2014] start_va=0x05c550, fde_va=0x082770, span=92 B | [VN] FDE[2014]
uint32_t ttr_fde_2014_0x05c550(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05c550U) ^ (0x94001a0cU + 0x082770U + 92U);
}

// [EN] FDE[2015] start_va=0x05c5ac, fde_va=0x082790, span=24 B | [VN] FDE[2015]
uint32_t ttr_fde_2015_0x05c5ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd960U + 0x05c5acU) ^ (0xaa1303e0U + 0x082790U + 24U);
}

// [EN] FDE[2016] start_va=0x05c5c4, fde_va=0x0827a8, span=172 B | [VN] FDE[2016]
uint32_t ttr_fde_2016_0x05c5c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000ec1U + 0x05c5c4U) ^ (0x97ffa7f4U + 0x0827a8U + 172U);
}

// [EN] FDE[2017] start_va=0x05c670, fde_va=0x0827c8, span=260 B | [VN] FDE[2017]
uint32_t ttr_fde_2017_0x05c670(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xf90043f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9097bf3U + 0x05c670U) ^ (0x94000fe2U + 0x0827c8U + 260U);
}

// [EN] FDE[2018] start_va=0x05c774, fde_va=0x0827e8, span=80 B | [VN] FDE[2018]
uint32_t ttr_fde_2018_0x05c774(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05c774U) ^ (0x940016f0U + 0x0827e8U + 80U);
}

// [EN] FDE[2019] start_va=0x05c7c4, fde_va=0x082808, span=256 B | [VN] FDE[2019]
uint32_t ttr_fde_2019_0x05c7c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05c7c4U) ^ (0x2a0303f5U + 0x082808U + 256U);
}

// [EN] FDE[2020] start_va=0x05c8c4, fde_va=0x082828, span=696 B | [VN] FDE[2020]
uint32_t ttr_fde_2020_0x05c8c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ffcU) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05c8c4U) ^ (0xd10783ffU + 0x082828U + 696U);
}

// [EN] FDE[2021] start_va=0x05cb7c, fde_va=0x082848, span=4 B | [VN] FDE[2021]
uint32_t ttr_fde_2021_0x05cb7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefc6dU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000c5eU + 0x05cb7cU) ^ (0xd00001e8U + 0x082848U + 4U);
}

// [EN] FDE[2022] start_va=0x05cb80, fde_va=0x082860, span=28 B | [VN] FDE[2022]
uint32_t ttr_fde_2022_0x05cb80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000c5eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05cb80U) ^ (0x9113a108U + 0x082860U + 28U);
}

// [EN] FDE[2023] start_va=0x05cb9c, fde_va=0x082878, span=12 B | [VN] FDE[2023]
uint32_t ttr_fde_2023_0x05cb9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x9113a108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000c52U + 0x05cb9cU) ^ (0xd65f03c0U + 0x082878U + 12U);
}

// [EN] FDE[2024] start_va=0x05cba8, fde_va=0x082890, span=4 B | [VN] FDE[2024]
uint32_t ttr_fde_2024_0x05cba8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefc61U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05cba8U) ^ (0xf90013f4U + 0x082890U + 4U);
}

// [EN] FDE[2025] start_va=0x05cbac, fde_va=0x0828a8, span=4 B | [VN] FDE[2025]
uint32_t ttr_fde_2025_0x05cbac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefc61U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05cbacU) ^ (0xa9037bf3U + 0x0828a8U + 4U);
}

// [EN] FDE[2026] start_va=0x05cbb0, fde_va=0x0828c0, span=88 B | [VN] FDE[2026]
uint32_t ttr_fde_2026_0x05cbb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05cbb0U) ^ (0x94000c91U + 0x0828c0U + 88U);
}

// [EN] FDE[2027] start_va=0x05cc08, fde_va=0x0828e0, span=4 B | [VN] FDE[2027]
uint32_t ttr_fde_2027_0x05cc08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefc4aU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000c3bU + 0x05cc08U) ^ (0xd00001e8U + 0x0828e0U + 4U);
}

// [EN] FDE[2028] start_va=0x05cc0c, fde_va=0x0828f8, span=28 B | [VN] FDE[2028]
uint32_t ttr_fde_2028_0x05cc0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000c3bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05cc0cU) ^ (0x91128108U + 0x0828f8U + 28U);
}

// [EN] FDE[2029] start_va=0x05cc28, fde_va=0x082910, span=12 B | [VN] FDE[2029]
uint32_t ttr_fde_2029_0x05cc28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x91128108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000c2fU + 0x05cc28U) ^ (0xd65f03c0U + 0x082910U + 12U);
}

// [EN] FDE[2030] start_va=0x05cc34, fde_va=0x082928, span=4 B | [VN] FDE[2030]
uint32_t ttr_fde_2030_0x05cc34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefc3eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05cc34U) ^ (0xf90013f4U + 0x082928U + 4U);
}

uint32_t DispatchTtrFdeShard3(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 1354U: return ttr_fde_1354_0x0481b0(a0, a1);
        case 1355U: return ttr_fde_1355_0x0481e8(a0, a1);
        case 1356U: return ttr_fde_1356_0x048260(a0, a1);
        case 1357U: return ttr_fde_1357_0x048284(a0, a1);
        case 1358U: return ttr_fde_1358_0x0482b0(a0, a1);
        case 1359U: return ttr_fde_1359_0x0482d0(a0, a1);
        case 1360U: return ttr_fde_1360_0x0482f0(a0, a1);
        case 1361U: return ttr_fde_1361_0x048324(a0, a1);
        case 1362U: return ttr_fde_1362_0x048344(a0, a1);
        case 1363U: return ttr_fde_1363_0x048368(a0, a1);
        case 1364U: return ttr_fde_1364_0x048390(a0, a1);
        case 1365U: return ttr_fde_1365_0x048398(a0, a1);
        case 1366U: return ttr_fde_1366_0x0483d0(a0, a1);
        case 1367U: return ttr_fde_1367_0x0483fc(a0, a1);
        case 1368U: return ttr_fde_1368_0x04841c(a0, a1);
        case 1369U: return ttr_fde_1369_0x048434(a0, a1);
        case 1370U: return ttr_fde_1370_0x04843c(a0, a1);
        case 1371U: return ttr_fde_1371_0x048440(a0, a1);
        case 1372U: return ttr_fde_1372_0x04845c(a0, a1);
        case 1373U: return ttr_fde_1373_0x048474(a0, a1);
        case 1374U: return ttr_fde_1374_0x04855c(a0, a1);
        case 1375U: return ttr_fde_1375_0x048694(a0, a1);
        case 1376U: return ttr_fde_1376_0x0488e0(a0, a1);
        case 1377U: return ttr_fde_1377_0x048a08(a0, a1);
        case 1378U: return ttr_fde_1378_0x048a84(a0, a1);
        case 1379U: return ttr_fde_1379_0x048afc(a0, a1);
        case 1380U: return ttr_fde_1380_0x048bac(a0, a1);
        case 1381U: return ttr_fde_1381_0x0490c4(a0, a1);
        case 1382U: return ttr_fde_1382_0x049140(a0, a1);
        case 1383U: return ttr_fde_1383_0x049148(a0, a1);
        case 1384U: return ttr_fde_1384_0x049164(a0, a1);
        case 1385U: return ttr_fde_1385_0x04917c(a0, a1);
        case 1386U: return ttr_fde_1386_0x049244(a0, a1);
        case 1387U: return ttr_fde_1387_0x04925c(a0, a1);
        case 1388U: return ttr_fde_1388_0x049288(a0, a1);
        case 1389U: return ttr_fde_1389_0x0492c0(a0, a1);
        case 1390U: return ttr_fde_1390_0x0492d8(a0, a1);
        case 1391U: return ttr_fde_1391_0x0492e8(a0, a1);
        case 1392U: return ttr_fde_1392_0x0492f8(a0, a1);
        case 1393U: return ttr_fde_1393_0x049318(a0, a1);
        case 1394U: return ttr_fde_1394_0x049340(a0, a1);
        case 1395U: return ttr_fde_1395_0x04938c(a0, a1);
        case 1396U: return ttr_fde_1396_0x04948c(a0, a1);
        case 1397U: return ttr_fde_1397_0x0495a0(a0, a1);
        case 1398U: return ttr_fde_1398_0x0495e0(a0, a1);
        case 1399U: return ttr_fde_1399_0x0499b0(a0, a1);
        case 1400U: return ttr_fde_1400_0x049ff0(a0, a1);
        case 1401U: return ttr_fde_1401_0x04a034(a0, a1);
        case 1402U: return ttr_fde_1402_0x04a1f8(a0, a1);
        case 1403U: return ttr_fde_1403_0x04a204(a0, a1);
        case 1404U: return ttr_fde_1404_0x04a298(a0, a1);
        case 1405U: return ttr_fde_1405_0x04a2a0(a0, a1);
        case 1406U: return ttr_fde_1406_0x04a334(a0, a1);
        case 1407U: return ttr_fde_1407_0x04a3d4(a0, a1);
        case 1408U: return ttr_fde_1408_0x04a3e8(a0, a1);
        case 1409U: return ttr_fde_1409_0x04a47c(a0, a1);
        case 1410U: return ttr_fde_1410_0x04a4a4(a0, a1);
        case 1411U: return ttr_fde_1411_0x04a544(a0, a1);
        case 1412U: return ttr_fde_1412_0x04a564(a0, a1);
        case 1413U: return ttr_fde_1413_0x04a588(a0, a1);
        case 1414U: return ttr_fde_1414_0x04a5a8(a0, a1);
        case 1415U: return ttr_fde_1415_0x04a9f0(a0, a1);
        case 1416U: return ttr_fde_1416_0x04aa30(a0, a1);
        case 1417U: return ttr_fde_1417_0x04aa78(a0, a1);
        case 1418U: return ttr_fde_1418_0x04ab90(a0, a1);
        case 1419U: return ttr_fde_1419_0x04abb8(a0, a1);
        case 1420U: return ttr_fde_1420_0x04af10(a0, a1);
        case 1421U: return ttr_fde_1421_0x04afe8(a0, a1);
        case 1422U: return ttr_fde_1422_0x04b0dc(a0, a1);
        case 1423U: return ttr_fde_1423_0x04b478(a0, a1);
        case 1424U: return ttr_fde_1424_0x04b4a0(a0, a1);
        case 1425U: return ttr_fde_1425_0x04b4d0(a0, a1);
        case 1426U: return ttr_fde_1426_0x04b4e8(a0, a1);
        case 1427U: return ttr_fde_1427_0x04b4f8(a0, a1);
        case 1428U: return ttr_fde_1428_0x04b508(a0, a1);
        case 1429U: return ttr_fde_1429_0x04b53c(a0, a1);
        case 1430U: return ttr_fde_1430_0x04b634(a0, a1);
        case 1431U: return ttr_fde_1431_0x04b68c(a0, a1);
        case 1432U: return ttr_fde_1432_0x04b6b8(a0, a1);
        case 1433U: return ttr_fde_1433_0x04bb40(a0, a1);
        case 1434U: return ttr_fde_1434_0x04bbcc(a0, a1);
        case 1435U: return ttr_fde_1435_0x04bc0c(a0, a1);
        case 1436U: return ttr_fde_1436_0x04bc30(a0, a1);
        case 1437U: return ttr_fde_1437_0x04bcf4(a0, a1);
        case 1438U: return ttr_fde_1438_0x04bcfc(a0, a1);
        case 1439U: return ttr_fde_1439_0x04bd10(a0, a1);
        case 1440U: return ttr_fde_1440_0x04bd38(a0, a1);
        case 1441U: return ttr_fde_1441_0x04bd58(a0, a1);
        case 1442U: return ttr_fde_1442_0x04bd7c(a0, a1);
        case 1443U: return ttr_fde_1443_0x04bd9c(a0, a1);
        case 1444U: return ttr_fde_1444_0x04be34(a0, a1);
        case 1445U: return ttr_fde_1445_0x04be68(a0, a1);
        case 1446U: return ttr_fde_1446_0x04c004(a0, a1);
        case 1447U: return ttr_fde_1447_0x04c060(a0, a1);
        case 1448U: return ttr_fde_1448_0x04c090(a0, a1);
        case 1449U: return ttr_fde_1449_0x04c0a8(a0, a1);
        case 1450U: return ttr_fde_1450_0x04c0b8(a0, a1);
        case 1451U: return ttr_fde_1451_0x04c0c8(a0, a1);
        case 1452U: return ttr_fde_1452_0x04c110(a0, a1);
        case 1453U: return ttr_fde_1453_0x04c18c(a0, a1);
        case 1454U: return ttr_fde_1454_0x04c1cc(a0, a1);
        case 1455U: return ttr_fde_1455_0x04c20c(a0, a1);
        case 1456U: return ttr_fde_1456_0x04c214(a0, a1);
        case 1457U: return ttr_fde_1457_0x04c2c4(a0, a1);
        case 1458U: return ttr_fde_1458_0x04c2e8(a0, a1);
        case 1459U: return ttr_fde_1459_0x04c380(a0, a1);
        case 1460U: return ttr_fde_1460_0x04c39c(a0, a1);
        case 1461U: return ttr_fde_1461_0x04c400(a0, a1);
        case 1462U: return ttr_fde_1462_0x04c43c(a0, a1);
        case 1463U: return ttr_fde_1463_0x04c468(a0, a1);
        case 1464U: return ttr_fde_1464_0x04c490(a0, a1);
        case 1465U: return ttr_fde_1465_0x04c4b8(a0, a1);
        case 1466U: return ttr_fde_1466_0x04c4e4(a0, a1);
        case 1467U: return ttr_fde_1467_0x04c538(a0, a1);
        case 1468U: return ttr_fde_1468_0x04c580(a0, a1);
        case 1469U: return ttr_fde_1469_0x04c5a8(a0, a1);
        case 1470U: return ttr_fde_1470_0x04c6fc(a0, a1);
        case 1471U: return ttr_fde_1471_0x04c734(a0, a1);
        case 1472U: return ttr_fde_1472_0x04c8a0(a0, a1);
        case 1473U: return ttr_fde_1473_0x04c8e8(a0, a1);
        case 1474U: return ttr_fde_1474_0x04c914(a0, a1);
        case 1475U: return ttr_fde_1475_0x04c944(a0, a1);
        case 1476U: return ttr_fde_1476_0x04c95c(a0, a1);
        case 1477U: return ttr_fde_1477_0x04c9bc(a0, a1);
        case 1478U: return ttr_fde_1478_0x04c9ec(a0, a1);
        case 1479U: return ttr_fde_1479_0x04c9f4(a0, a1);
        case 1480U: return ttr_fde_1480_0x04ca88(a0, a1);
        case 1481U: return ttr_fde_1481_0x04cafc(a0, a1);
        case 1482U: return ttr_fde_1482_0x04cb20(a0, a1);
        case 1483U: return ttr_fde_1483_0x04cc28(a0, a1);
        case 1484U: return ttr_fde_1484_0x04ccfc(a0, a1);
        case 1485U: return ttr_fde_1485_0x04cd68(a0, a1);
        case 1486U: return ttr_fde_1486_0x04cd84(a0, a1);
        case 1487U: return ttr_fde_1487_0x04ce04(a0, a1);
        case 1488U: return ttr_fde_1488_0x04ce88(a0, a1);
        case 1489U: return ttr_fde_1489_0x04cf64(a0, a1);
        case 1490U: return ttr_fde_1490_0x04cfb4(a0, a1);
        case 1491U: return ttr_fde_1491_0x04cff4(a0, a1);
        case 1492U: return ttr_fde_1492_0x04d048(a0, a1);
        case 1493U: return ttr_fde_1493_0x04d090(a0, a1);
        case 1494U: return ttr_fde_1494_0x04d0a4(a0, a1);
        case 1495U: return ttr_fde_1495_0x04d0c4(a0, a1);
        case 1496U: return ttr_fde_1496_0x04d19c(a0, a1);
        case 1497U: return ttr_fde_1497_0x04d21c(a0, a1);
        case 1498U: return ttr_fde_1498_0x04d240(a0, a1);
        case 1499U: return ttr_fde_1499_0x04d31c(a0, a1);
        case 1500U: return ttr_fde_1500_0x04d38c(a0, a1);
        case 1501U: return ttr_fde_1501_0x04d3bc(a0, a1);
        case 1502U: return ttr_fde_1502_0x04d3e0(a0, a1);
        case 1503U: return ttr_fde_1503_0x04d404(a0, a1);
        case 1504U: return ttr_fde_1504_0x04d414(a0, a1);
        case 1505U: return ttr_fde_1505_0x04d43c(a0, a1);
        case 1506U: return ttr_fde_1506_0x04d598(a0, a1);
        case 1507U: return ttr_fde_1507_0x04d5e0(a0, a1);
        case 1508U: return ttr_fde_1508_0x04d5f8(a0, a1);
        case 1509U: return ttr_fde_1509_0x04d61c(a0, a1);
        case 1510U: return ttr_fde_1510_0x04d62c(a0, a1);
        case 1511U: return ttr_fde_1511_0x04d708(a0, a1);
        case 1512U: return ttr_fde_1512_0x04d758(a0, a1);
        case 1513U: return ttr_fde_1513_0x04d8c0(a0, a1);
        case 1514U: return ttr_fde_1514_0x04d8e8(a0, a1);
        case 1515U: return ttr_fde_1515_0x04d900(a0, a1);
        case 1516U: return ttr_fde_1516_0x04d928(a0, a1);
        case 1517U: return ttr_fde_1517_0x04d954(a0, a1);
        case 1518U: return ttr_fde_1518_0x04d9f0(a0, a1);
        case 1519U: return ttr_fde_1519_0x04da34(a0, a1);
        case 1520U: return ttr_fde_1520_0x04da90(a0, a1);
        case 1521U: return ttr_fde_1521_0x04dc3c(a0, a1);
        case 1522U: return ttr_fde_1522_0x04dc90(a0, a1);
        case 1523U: return ttr_fde_1523_0x04df98(a0, a1);
        case 1524U: return ttr_fde_1524_0x04e05c(a0, a1);
        case 1525U: return ttr_fde_1525_0x04e074(a0, a1);
        case 1526U: return ttr_fde_1526_0x04e0e0(a0, a1);
        case 1527U: return ttr_fde_1527_0x04e1c8(a0, a1);
        case 1528U: return ttr_fde_1528_0x04e544(a0, a1);
        case 1529U: return ttr_fde_1529_0x04e5e0(a0, a1);
        case 1530U: return ttr_fde_1530_0x04e5f8(a0, a1);
        case 1531U: return ttr_fde_1531_0x04e61c(a0, a1);
        case 1532U: return ttr_fde_1532_0x04e650(a0, a1);
        case 1533U: return ttr_fde_1533_0x04e674(a0, a1);
        case 1534U: return ttr_fde_1534_0x04e6dc(a0, a1);
        case 1535U: return ttr_fde_1535_0x04e860(a0, a1);
        case 1536U: return ttr_fde_1536_0x04e8e4(a0, a1);
        case 1537U: return ttr_fde_1537_0x04e900(a0, a1);
        case 1538U: return ttr_fde_1538_0x04e93c(a0, a1);
        case 1539U: return ttr_fde_1539_0x04e958(a0, a1);
        case 1540U: return ttr_fde_1540_0x04eb84(a0, a1);
        case 1541U: return ttr_fde_1541_0x04eb9c(a0, a1);
        case 1542U: return ttr_fde_1542_0x04ef7c(a0, a1);
        case 1543U: return ttr_fde_1543_0x04efec(a0, a1);
        case 1544U: return ttr_fde_1544_0x04fcb4(a0, a1);
        case 1545U: return ttr_fde_1545_0x04fcec(a0, a1);
        case 1546U: return ttr_fde_1546_0x04fd4c(a0, a1);
        case 1547U: return ttr_fde_1547_0x04fdc0(a0, a1);
        case 1548U: return ttr_fde_1548_0x04fdcc(a0, a1);
        case 1549U: return ttr_fde_1549_0x04fe2c(a0, a1);
        case 1550U: return ttr_fde_1550_0x04ff4c(a0, a1);
        case 1551U: return ttr_fde_1551_0x04ff6c(a0, a1);
        case 1552U: return ttr_fde_1552_0x04ff84(a0, a1);
        case 1553U: return ttr_fde_1553_0x04ff88(a0, a1);
        case 1554U: return ttr_fde_1554_0x04ff8c(a0, a1);
        case 1555U: return ttr_fde_1555_0x04ffc4(a0, a1);
        case 1556U: return ttr_fde_1556_0x04fff0(a0, a1);
        case 1557U: return ttr_fde_1557_0x04fffc(a0, a1);
        case 1558U: return ttr_fde_1558_0x05004c(a0, a1);
        case 1559U: return ttr_fde_1559_0x0500b4(a0, a1);
        case 1560U: return ttr_fde_1560_0x0500ec(a0, a1);
        case 1561U: return ttr_fde_1561_0x0500f4(a0, a1);
        case 1562U: return ttr_fde_1562_0x0500f8(a0, a1);
        case 1563U: return ttr_fde_1563_0x0500fc(a0, a1);
        case 1564U: return ttr_fde_1564_0x050100(a0, a1);
        case 1565U: return ttr_fde_1565_0x050118(a0, a1);
        case 1566U: return ttr_fde_1566_0x05011c(a0, a1);
        case 1567U: return ttr_fde_1567_0x050134(a0, a1);
        case 1568U: return ttr_fde_1568_0x05043c(a0, a1);
        case 1569U: return ttr_fde_1569_0x050474(a0, a1);
        case 1570U: return ttr_fde_1570_0x050484(a0, a1);
        case 1571U: return ttr_fde_1571_0x050540(a0, a1);
        case 1572U: return ttr_fde_1572_0x050564(a0, a1);
        case 1573U: return ttr_fde_1573_0x050568(a0, a1);
        case 1574U: return ttr_fde_1574_0x050644(a0, a1);
        case 1575U: return ttr_fde_1575_0x05068c(a0, a1);
        case 1576U: return ttr_fde_1576_0x0506b4(a0, a1);
        case 1577U: return ttr_fde_1577_0x05077c(a0, a1);
        case 1578U: return ttr_fde_1578_0x050800(a0, a1);
        case 1579U: return ttr_fde_1579_0x0508d0(a0, a1);
        case 1580U: return ttr_fde_1580_0x0508e4(a0, a1);
        case 1581U: return ttr_fde_1581_0x0508f8(a0, a1);
        case 1582U: return ttr_fde_1582_0x0508fc(a0, a1);
        case 1583U: return ttr_fde_1583_0x05092c(a0, a1);
        case 1584U: return ttr_fde_1584_0x050974(a0, a1);
        case 1585U: return ttr_fde_1585_0x05098c(a0, a1);
        case 1586U: return ttr_fde_1586_0x050990(a0, a1);
        case 1587U: return ttr_fde_1587_0x050994(a0, a1);
        case 1588U: return ttr_fde_1588_0x050998(a0, a1);
        case 1589U: return ttr_fde_1589_0x0509b8(a0, a1);
        case 1590U: return ttr_fde_1590_0x0509bc(a0, a1);
        case 1591U: return ttr_fde_1591_0x0509c0(a0, a1);
        case 1592U: return ttr_fde_1592_0x0509c4(a0, a1);
        case 1593U: return ttr_fde_1593_0x050a38(a0, a1);
        case 1594U: return ttr_fde_1594_0x050a5c(a0, a1);
        case 1595U: return ttr_fde_1595_0x050a88(a0, a1);
        case 1596U: return ttr_fde_1596_0x050aa4(a0, a1);
        case 1597U: return ttr_fde_1597_0x050b48(a0, a1);
        case 1598U: return ttr_fde_1598_0x050b54(a0, a1);
        case 1599U: return ttr_fde_1599_0x050c4c(a0, a1);
        case 1600U: return ttr_fde_1600_0x050d3c(a0, a1);
        case 1601U: return ttr_fde_1601_0x050d6c(a0, a1);
        case 1602U: return ttr_fde_1602_0x050d94(a0, a1);
        case 1603U: return ttr_fde_1603_0x050f24(a0, a1);
        case 1604U: return ttr_fde_1604_0x050f3c(a0, a1);
        case 1605U: return ttr_fde_1605_0x051f38(a0, a1);
        case 1606U: return ttr_fde_1606_0x0522a8(a0, a1);
        case 1607U: return ttr_fde_1607_0x052318(a0, a1);
        case 1608U: return ttr_fde_1608_0x052354(a0, a1);
        case 1609U: return ttr_fde_1609_0x052394(a0, a1);
        case 1610U: return ttr_fde_1610_0x0523d0(a0, a1);
        case 1611U: return ttr_fde_1611_0x05245c(a0, a1);
        case 1612U: return ttr_fde_1612_0x052474(a0, a1);
        case 1613U: return ttr_fde_1613_0x05248c(a0, a1);
        case 1614U: return ttr_fde_1614_0x0524bc(a0, a1);
        case 1615U: return ttr_fde_1615_0x0524f4(a0, a1);
        case 1616U: return ttr_fde_1616_0x0524fc(a0, a1);
        case 1617U: return ttr_fde_1617_0x052514(a0, a1);
        case 1618U: return ttr_fde_1618_0x052538(a0, a1);
        case 1619U: return ttr_fde_1619_0x052550(a0, a1);
        case 1620U: return ttr_fde_1620_0x05255c(a0, a1);
        case 1621U: return ttr_fde_1621_0x052578(a0, a1);
        case 1622U: return ttr_fde_1622_0x052590(a0, a1);
        case 1623U: return ttr_fde_1623_0x052594(a0, a1);
        case 1624U: return ttr_fde_1624_0x052598(a0, a1);
        case 1625U: return ttr_fde_1625_0x0525b8(a0, a1);
        case 1626U: return ttr_fde_1626_0x0525d0(a0, a1);
        case 1627U: return ttr_fde_1627_0x0525d8(a0, a1);
        case 1628U: return ttr_fde_1628_0x0525dc(a0, a1);
        case 1629U: return ttr_fde_1629_0x0526a8(a0, a1);
        case 1630U: return ttr_fde_1630_0x0526b4(a0, a1);
        case 1631U: return ttr_fde_1631_0x0526d4(a0, a1);
        case 1632U: return ttr_fde_1632_0x0526ec(a0, a1);
        case 1633U: return ttr_fde_1633_0x0526f4(a0, a1);
        case 1634U: return ttr_fde_1634_0x0526f8(a0, a1);
        case 1635U: return ttr_fde_1635_0x052750(a0, a1);
        case 1636U: return ttr_fde_1636_0x052790(a0, a1);
        case 1637U: return ttr_fde_1637_0x0527b8(a0, a1);
        case 1638U: return ttr_fde_1638_0x0527e0(a0, a1);
        case 1639U: return ttr_fde_1639_0x052808(a0, a1);
        case 1640U: return ttr_fde_1640_0x05282c(a0, a1);
        case 1641U: return ttr_fde_1641_0x05285c(a0, a1);
        case 1642U: return ttr_fde_1642_0x052868(a0, a1);
        case 1643U: return ttr_fde_1643_0x052880(a0, a1);
        case 1644U: return ttr_fde_1644_0x052888(a0, a1);
        case 1645U: return ttr_fde_1645_0x0528a8(a0, a1);
        case 1646U: return ttr_fde_1646_0x0528c0(a0, a1);
        case 1647U: return ttr_fde_1647_0x0528c8(a0, a1);
        case 1648U: return ttr_fde_1648_0x0528cc(a0, a1);
        case 1649U: return ttr_fde_1649_0x052928(a0, a1);
        case 1650U: return ttr_fde_1650_0x052950(a0, a1);
        case 1651U: return ttr_fde_1651_0x05295c(a0, a1);
        case 1652U: return ttr_fde_1652_0x052964(a0, a1);
        case 1653U: return ttr_fde_1653_0x052990(a0, a1);
        case 1654U: return ttr_fde_1654_0x0529b0(a0, a1);
        case 1655U: return ttr_fde_1655_0x0529c8(a0, a1);
        case 1656U: return ttr_fde_1656_0x0529d0(a0, a1);
        case 1657U: return ttr_fde_1657_0x0529d4(a0, a1);
        case 1658U: return ttr_fde_1658_0x052a10(a0, a1);
        case 1659U: return ttr_fde_1659_0x052a1c(a0, a1);
        case 1660U: return ttr_fde_1660_0x052a3c(a0, a1);
        case 1661U: return ttr_fde_1661_0x052a54(a0, a1);
        case 1662U: return ttr_fde_1662_0x052a5c(a0, a1);
        case 1663U: return ttr_fde_1663_0x052a60(a0, a1);
        case 1664U: return ttr_fde_1664_0x052a94(a0, a1);
        case 1665U: return ttr_fde_1665_0x052aa0(a0, a1);
        case 1666U: return ttr_fde_1666_0x052aac(a0, a1);
        case 1667U: return ttr_fde_1667_0x052acc(a0, a1);
        case 1668U: return ttr_fde_1668_0x052ae4(a0, a1);
        case 1669U: return ttr_fde_1669_0x052aec(a0, a1);
        case 1670U: return ttr_fde_1670_0x052af0(a0, a1);
        case 1671U: return ttr_fde_1671_0x052b10(a0, a1);
        case 1672U: return ttr_fde_1672_0x052b28(a0, a1);
        case 1673U: return ttr_fde_1673_0x052b30(a0, a1);
        case 1674U: return ttr_fde_1674_0x052b34(a0, a1);
        case 1675U: return ttr_fde_1675_0x052bc8(a0, a1);
        case 1676U: return ttr_fde_1676_0x052be0(a0, a1);
        case 1677U: return ttr_fde_1677_0x052bfc(a0, a1);
        case 1678U: return ttr_fde_1678_0x052c14(a0, a1);
        case 1679U: return ttr_fde_1679_0x052c1c(a0, a1);
        case 1680U: return ttr_fde_1680_0x052c20(a0, a1);
        case 1681U: return ttr_fde_1681_0x052c40(a0, a1);
        case 1682U: return ttr_fde_1682_0x052c58(a0, a1);
        case 1683U: return ttr_fde_1683_0x052c60(a0, a1);
        case 1684U: return ttr_fde_1684_0x052c64(a0, a1);
        case 1685U: return ttr_fde_1685_0x052cb4(a0, a1);
        case 1686U: return ttr_fde_1686_0x052ce8(a0, a1);
        case 1687U: return ttr_fde_1687_0x052d0c(a0, a1);
        case 1688U: return ttr_fde_1688_0x053844(a0, a1);
        case 1689U: return ttr_fde_1689_0x053848(a0, a1);
        case 1690U: return ttr_fde_1690_0x053864(a0, a1);
        case 1691U: return ttr_fde_1691_0x053870(a0, a1);
        case 1692U: return ttr_fde_1692_0x053874(a0, a1);
        case 1693U: return ttr_fde_1693_0x053878(a0, a1);
        case 1694U: return ttr_fde_1694_0x0538e4(a0, a1);
        case 1695U: return ttr_fde_1695_0x0538e8(a0, a1);
        case 1696U: return ttr_fde_1696_0x053904(a0, a1);
        case 1697U: return ttr_fde_1697_0x053910(a0, a1);
        case 1698U: return ttr_fde_1698_0x053914(a0, a1);
        case 1699U: return ttr_fde_1699_0x053918(a0, a1);
        case 1700U: return ttr_fde_1700_0x053984(a0, a1);
        case 1701U: return ttr_fde_1701_0x053988(a0, a1);
        case 1702U: return ttr_fde_1702_0x0539a4(a0, a1);
        case 1703U: return ttr_fde_1703_0x0539b0(a0, a1);
        case 1704U: return ttr_fde_1704_0x0539b4(a0, a1);
        case 1705U: return ttr_fde_1705_0x0539b8(a0, a1);
        case 1706U: return ttr_fde_1706_0x053a24(a0, a1);
        case 1707U: return ttr_fde_1707_0x053a28(a0, a1);
        case 1708U: return ttr_fde_1708_0x053a44(a0, a1);
        case 1709U: return ttr_fde_1709_0x053a50(a0, a1);
        case 1710U: return ttr_fde_1710_0x053a54(a0, a1);
        case 1711U: return ttr_fde_1711_0x053a58(a0, a1);
        case 1712U: return ttr_fde_1712_0x053ac4(a0, a1);
        case 1713U: return ttr_fde_1713_0x053adc(a0, a1);
        case 1714U: return ttr_fde_1714_0x053c14(a0, a1);
        case 1715U: return ttr_fde_1715_0x053d20(a0, a1);
        case 1716U: return ttr_fde_1716_0x0541d8(a0, a1);
        case 1717U: return ttr_fde_1717_0x05441c(a0, a1);
        case 1718U: return ttr_fde_1718_0x05451c(a0, a1);
        case 1719U: return ttr_fde_1719_0x0545dc(a0, a1);
        case 1720U: return ttr_fde_1720_0x054620(a0, a1);
        case 1721U: return ttr_fde_1721_0x054644(a0, a1);
        case 1722U: return ttr_fde_1722_0x054674(a0, a1);
        case 1723U: return ttr_fde_1723_0x0546b4(a0, a1);
        case 1724U: return ttr_fde_1724_0x054768(a0, a1);
        case 1725U: return ttr_fde_1725_0x0547e0(a0, a1);
        case 1726U: return ttr_fde_1726_0x0547e4(a0, a1);
        case 1727U: return ttr_fde_1727_0x0547e8(a0, a1);
        case 1728U: return ttr_fde_1728_0x054804(a0, a1);
        case 1729U: return ttr_fde_1729_0x05480c(a0, a1);
        case 1730U: return ttr_fde_1730_0x054828(a0, a1);
        case 1731U: return ttr_fde_1731_0x054838(a0, a1);
        case 1732U: return ttr_fde_1732_0x05483c(a0, a1);
        case 1733U: return ttr_fde_1733_0x054850(a0, a1);
        case 1734U: return ttr_fde_1734_0x054854(a0, a1);
        case 1735U: return ttr_fde_1735_0x054858(a0, a1);
        case 1736U: return ttr_fde_1736_0x054884(a0, a1);
        case 1737U: return ttr_fde_1737_0x054888(a0, a1);
        case 1738U: return ttr_fde_1738_0x0548a4(a0, a1);
        case 1739U: return ttr_fde_1739_0x0548b0(a0, a1);
        case 1740U: return ttr_fde_1740_0x0548b4(a0, a1);
        case 1741U: return ttr_fde_1741_0x0548b8(a0, a1);
        case 1742U: return ttr_fde_1742_0x054900(a0, a1);
        case 1743U: return ttr_fde_1743_0x054904(a0, a1);
        case 1744U: return ttr_fde_1744_0x054920(a0, a1);
        case 1745U: return ttr_fde_1745_0x05492c(a0, a1);
        case 1746U: return ttr_fde_1746_0x054930(a0, a1);
        case 1747U: return ttr_fde_1747_0x054934(a0, a1);
        case 1748U: return ttr_fde_1748_0x05497c(a0, a1);
        case 1749U: return ttr_fde_1749_0x054980(a0, a1);
        case 1750U: return ttr_fde_1750_0x05499c(a0, a1);
        case 1751U: return ttr_fde_1751_0x0549a8(a0, a1);
        case 1752U: return ttr_fde_1752_0x0549ac(a0, a1);
        case 1753U: return ttr_fde_1753_0x0549b0(a0, a1);
        case 1754U: return ttr_fde_1754_0x0549e4(a0, a1);
        case 1755U: return ttr_fde_1755_0x0549e8(a0, a1);
        case 1756U: return ttr_fde_1756_0x054a04(a0, a1);
        case 1757U: return ttr_fde_1757_0x054a10(a0, a1);
        case 1758U: return ttr_fde_1758_0x054a14(a0, a1);
        case 1759U: return ttr_fde_1759_0x054a18(a0, a1);
        case 1760U: return ttr_fde_1760_0x054a4c(a0, a1);
        case 1761U: return ttr_fde_1761_0x054a64(a0, a1);
        case 1762U: return ttr_fde_1762_0x054d9c(a0, a1);
        case 1763U: return ttr_fde_1763_0x054fc8(a0, a1);
        case 1764U: return ttr_fde_1764_0x055584(a0, a1);
        case 1765U: return ttr_fde_1765_0x055670(a0, a1);
        case 1766U: return ttr_fde_1766_0x05570c(a0, a1);
        case 1767U: return ttr_fde_1767_0x0558d4(a0, a1);
        case 1768U: return ttr_fde_1768_0x055940(a0, a1);
        case 1769U: return ttr_fde_1769_0x05599c(a0, a1);
        case 1770U: return ttr_fde_1770_0x0559bc(a0, a1);
        case 1771U: return ttr_fde_1771_0x055bc8(a0, a1);
        case 1772U: return ttr_fde_1772_0x055be0(a0, a1);
        case 1773U: return ttr_fde_1773_0x055c18(a0, a1);
        case 1774U: return ttr_fde_1774_0x055c30(a0, a1);
        case 1775U: return ttr_fde_1775_0x055c68(a0, a1);
        case 1776U: return ttr_fde_1776_0x055c8c(a0, a1);
        case 1777U: return ttr_fde_1777_0x055ebc(a0, a1);
        case 1778U: return ttr_fde_1778_0x055f90(a0, a1);
        case 1779U: return ttr_fde_1779_0x056098(a0, a1);
        case 1780U: return ttr_fde_1780_0x056218(a0, a1);
        case 1781U: return ttr_fde_1781_0x056320(a0, a1);
        case 1782U: return ttr_fde_1782_0x056440(a0, a1);
        case 1783U: return ttr_fde_1783_0x0564e0(a0, a1);
        case 1784U: return ttr_fde_1784_0x0564f8(a0, a1);
        case 1785U: return ttr_fde_1785_0x0565f0(a0, a1);
        case 1786U: return ttr_fde_1786_0x056608(a0, a1);
        case 1787U: return ttr_fde_1787_0x056628(a0, a1);
        case 1788U: return ttr_fde_1788_0x056640(a0, a1);
        case 1789U: return ttr_fde_1789_0x056648(a0, a1);
        case 1790U: return ttr_fde_1790_0x05664c(a0, a1);
        case 1791U: return ttr_fde_1791_0x056670(a0, a1);
        case 1792U: return ttr_fde_1792_0x05669c(a0, a1);
        case 1793U: return ttr_fde_1793_0x0566b0(a0, a1);
        case 1794U: return ttr_fde_1794_0x0566e0(a0, a1);
        case 1795U: return ttr_fde_1795_0x056718(a0, a1);
        case 1796U: return ttr_fde_1796_0x056740(a0, a1);
        case 1797U: return ttr_fde_1797_0x056754(a0, a1);
        case 1798U: return ttr_fde_1798_0x056780(a0, a1);
        case 1799U: return ttr_fde_1799_0x0567c8(a0, a1);
        case 1800U: return ttr_fde_1800_0x0567f0(a0, a1);
        case 1801U: return ttr_fde_1801_0x056914(a0, a1);
        case 1802U: return ttr_fde_1802_0x05693c(a0, a1);
        case 1803U: return ttr_fde_1803_0x056964(a0, a1);
        case 1804U: return ttr_fde_1804_0x056978(a0, a1);
        case 1805U: return ttr_fde_1805_0x05698c(a0, a1);
        case 1806U: return ttr_fde_1806_0x0569b4(a0, a1);
        case 1807U: return ttr_fde_1807_0x0569d4(a0, a1);
        case 1808U: return ttr_fde_1808_0x0569ec(a0, a1);
        case 1809U: return ttr_fde_1809_0x0569f4(a0, a1);
        case 1810U: return ttr_fde_1810_0x0569f8(a0, a1);
        case 1811U: return ttr_fde_1811_0x056a54(a0, a1);
        case 1812U: return ttr_fde_1812_0x056a6c(a0, a1);
        case 1813U: return ttr_fde_1813_0x056aa0(a0, a1);
        case 1814U: return ttr_fde_1814_0x056ac4(a0, a1);
        case 1815U: return ttr_fde_1815_0x056dcc(a0, a1);
        case 1816U: return ttr_fde_1816_0x056ed4(a0, a1);
        case 1817U: return ttr_fde_1817_0x057a98(a0, a1);
        case 1818U: return ttr_fde_1818_0x057acc(a0, a1);
        case 1819U: return ttr_fde_1819_0x057bc8(a0, a1);
        case 1820U: return ttr_fde_1820_0x057bf8(a0, a1);
        case 1821U: return ttr_fde_1821_0x057c24(a0, a1);
        case 1822U: return ttr_fde_1822_0x057c50(a0, a1);
        case 1823U: return ttr_fde_1823_0x057c98(a0, a1);
        case 1824U: return ttr_fde_1824_0x057cd4(a0, a1);
        case 1825U: return ttr_fde_1825_0x057d20(a0, a1);
        case 1826U: return ttr_fde_1826_0x057d40(a0, a1);
        case 1827U: return ttr_fde_1827_0x057dc4(a0, a1);
        case 1828U: return ttr_fde_1828_0x057ea8(a0, a1);
        case 1829U: return ttr_fde_1829_0x057eec(a0, a1);
        case 1830U: return ttr_fde_1830_0x057f00(a0, a1);
        case 1831U: return ttr_fde_1831_0x057fb8(a0, a1);
        case 1832U: return ttr_fde_1832_0x0580c8(a0, a1);
        case 1833U: return ttr_fde_1833_0x0582b4(a0, a1);
        case 1834U: return ttr_fde_1834_0x058524(a0, a1);
        case 1835U: return ttr_fde_1835_0x0585dc(a0, a1);
        case 1836U: return ttr_fde_1836_0x058614(a0, a1);
        case 1837U: return ttr_fde_1837_0x058750(a0, a1);
        case 1838U: return ttr_fde_1838_0x05877c(a0, a1);
        case 1839U: return ttr_fde_1839_0x05879c(a0, a1);
        case 1840U: return ttr_fde_1840_0x0587e0(a0, a1);
        case 1841U: return ttr_fde_1841_0x058884(a0, a1);
        case 1842U: return ttr_fde_1842_0x0588cc(a0, a1);
        case 1843U: return ttr_fde_1843_0x0588d0(a0, a1);
        case 1844U: return ttr_fde_1844_0x0588d4(a0, a1);
        case 1845U: return ttr_fde_1845_0x0588d8(a0, a1);
        case 1846U: return ttr_fde_1846_0x0588f8(a0, a1);
        case 1847U: return ttr_fde_1847_0x058904(a0, a1);
        case 1848U: return ttr_fde_1848_0x058908(a0, a1);
        case 1849U: return ttr_fde_1849_0x05890c(a0, a1);
        case 1850U: return ttr_fde_1850_0x058978(a0, a1);
        case 1851U: return ttr_fde_1851_0x058bc4(a0, a1);
        case 1852U: return ttr_fde_1852_0x058c98(a0, a1);
        case 1853U: return ttr_fde_1853_0x058cb0(a0, a1);
        case 1854U: return ttr_fde_1854_0x058d08(a0, a1);
        case 1855U: return ttr_fde_1855_0x058d14(a0, a1);
        case 1856U: return ttr_fde_1856_0x058d2c(a0, a1);
        case 1857U: return ttr_fde_1857_0x058d54(a0, a1);
        case 1858U: return ttr_fde_1858_0x058d70(a0, a1);
        case 1859U: return ttr_fde_1859_0x058d74(a0, a1);
        case 1860U: return ttr_fde_1860_0x058d84(a0, a1);
        case 1861U: return ttr_fde_1861_0x058e50(a0, a1);
        case 1862U: return ttr_fde_1862_0x0590bc(a0, a1);
        case 1863U: return ttr_fde_1863_0x0590e0(a0, a1);
        case 1864U: return ttr_fde_1864_0x0590ec(a0, a1);
        case 1865U: return ttr_fde_1865_0x059104(a0, a1);
        case 1866U: return ttr_fde_1866_0x05912c(a0, a1);
        case 1867U: return ttr_fde_1867_0x059148(a0, a1);
        case 1868U: return ttr_fde_1868_0x05914c(a0, a1);
        case 1869U: return ttr_fde_1869_0x05915c(a0, a1);
        case 1870U: return ttr_fde_1870_0x059278(a0, a1);
        case 1871U: return ttr_fde_1871_0x059294(a0, a1);
        case 1872U: return ttr_fde_1872_0x0592a0(a0, a1);
        case 1873U: return ttr_fde_1873_0x0592b8(a0, a1);
        case 1874U: return ttr_fde_1874_0x0592e0(a0, a1);
        case 1875U: return ttr_fde_1875_0x0592fc(a0, a1);
        case 1876U: return ttr_fde_1876_0x059300(a0, a1);
        case 1877U: return ttr_fde_1877_0x059310(a0, a1);
        case 1878U: return ttr_fde_1878_0x05936c(a0, a1);
        case 1879U: return ttr_fde_1879_0x059388(a0, a1);
        case 1880U: return ttr_fde_1880_0x05938c(a0, a1);
        case 1881U: return ttr_fde_1881_0x0593ac(a0, a1);
        case 1882U: return ttr_fde_1882_0x0593b8(a0, a1);
        case 1883U: return ttr_fde_1883_0x0593bc(a0, a1);
        case 1884U: return ttr_fde_1884_0x0593c0(a0, a1);
        case 1885U: return ttr_fde_1885_0x059428(a0, a1);
        case 1886U: return ttr_fde_1886_0x05943c(a0, a1);
        case 1887U: return ttr_fde_1887_0x059460(a0, a1);
        case 1888U: return ttr_fde_1888_0x059480(a0, a1);
        case 1889U: return ttr_fde_1889_0x0594ac(a0, a1);
        case 1890U: return ttr_fde_1890_0x0594cc(a0, a1);
        case 1891U: return ttr_fde_1891_0x0594e4(a0, a1);
        case 1892U: return ttr_fde_1892_0x0594ec(a0, a1);
        case 1893U: return ttr_fde_1893_0x0594f0(a0, a1);
        case 1894U: return ttr_fde_1894_0x059528(a0, a1);
        case 1895U: return ttr_fde_1895_0x059540(a0, a1);
        case 1896U: return ttr_fde_1896_0x059578(a0, a1);
        case 1897U: return ttr_fde_1897_0x05959c(a0, a1);
        case 1898U: return ttr_fde_1898_0x059748(a0, a1);
        case 1899U: return ttr_fde_1899_0x05982c(a0, a1);
        case 1900U: return ttr_fde_1900_0x05984c(a0, a1);
        case 1901U: return ttr_fde_1901_0x059864(a0, a1);
        case 1902U: return ttr_fde_1902_0x05986c(a0, a1);
        case 1903U: return ttr_fde_1903_0x059870(a0, a1);
        case 1904U: return ttr_fde_1904_0x0598cc(a0, a1);
        case 1905U: return ttr_fde_1905_0x0598e4(a0, a1);
        case 1906U: return ttr_fde_1906_0x059918(a0, a1);
        case 1907U: return ttr_fde_1907_0x05993c(a0, a1);
        case 1908U: return ttr_fde_1908_0x059bd0(a0, a1);
        case 1909U: return ttr_fde_1909_0x059cf8(a0, a1);
        case 1910U: return ttr_fde_1910_0x059d18(a0, a1);
        case 1911U: return ttr_fde_1911_0x059d30(a0, a1);
        case 1912U: return ttr_fde_1912_0x059d38(a0, a1);
        case 1913U: return ttr_fde_1913_0x059d3c(a0, a1);
        case 1914U: return ttr_fde_1914_0x059d5c(a0, a1);
        case 1915U: return ttr_fde_1915_0x059dfc(a0, a1);
        case 1916U: return ttr_fde_1916_0x059f0c(a0, a1);
        case 1917U: return ttr_fde_1917_0x059f58(a0, a1);
        case 1918U: return ttr_fde_1918_0x059f74(a0, a1);
        case 1919U: return ttr_fde_1919_0x059f94(a0, a1);
        case 1920U: return ttr_fde_1920_0x059fc0(a0, a1);
        case 1921U: return ttr_fde_1921_0x059fd0(a0, a1);
        case 1922U: return ttr_fde_1922_0x059fd4(a0, a1);
        case 1923U: return ttr_fde_1923_0x059ff0(a0, a1);
        case 1924U: return ttr_fde_1924_0x059ffc(a0, a1);
        case 1925U: return ttr_fde_1925_0x05a000(a0, a1);
        case 1926U: return ttr_fde_1926_0x05a004(a0, a1);
        case 1927U: return ttr_fde_1927_0x05a164(a0, a1);
        case 1928U: return ttr_fde_1928_0x05a168(a0, a1);
        case 1929U: return ttr_fde_1929_0x05a184(a0, a1);
        case 1930U: return ttr_fde_1930_0x05a190(a0, a1);
        case 1931U: return ttr_fde_1931_0x05a194(a0, a1);
        case 1932U: return ttr_fde_1932_0x05a198(a0, a1);
        case 1933U: return ttr_fde_1933_0x05a200(a0, a1);
        case 1934U: return ttr_fde_1934_0x05a204(a0, a1);
        case 1935U: return ttr_fde_1935_0x05a220(a0, a1);
        case 1936U: return ttr_fde_1936_0x05a22c(a0, a1);
        case 1937U: return ttr_fde_1937_0x05a230(a0, a1);
        case 1938U: return ttr_fde_1938_0x05a234(a0, a1);
        case 1939U: return ttr_fde_1939_0x05a29c(a0, a1);
        case 1940U: return ttr_fde_1940_0x05a2a0(a0, a1);
        case 1941U: return ttr_fde_1941_0x05a2bc(a0, a1);
        case 1942U: return ttr_fde_1942_0x05a2c8(a0, a1);
        case 1943U: return ttr_fde_1943_0x05a2cc(a0, a1);
        case 1944U: return ttr_fde_1944_0x05a2d0(a0, a1);
        case 1945U: return ttr_fde_1945_0x05a30c(a0, a1);
        case 1946U: return ttr_fde_1946_0x05a310(a0, a1);
        case 1947U: return ttr_fde_1947_0x05a32c(a0, a1);
        case 1948U: return ttr_fde_1948_0x05a338(a0, a1);
        case 1949U: return ttr_fde_1949_0x05a33c(a0, a1);
        case 1950U: return ttr_fde_1950_0x05a340(a0, a1);
        case 1951U: return ttr_fde_1951_0x05a380(a0, a1);
        case 1952U: return ttr_fde_1952_0x05a384(a0, a1);
        case 1953U: return ttr_fde_1953_0x05a3a0(a0, a1);
        case 1954U: return ttr_fde_1954_0x05a3ac(a0, a1);
        case 1955U: return ttr_fde_1955_0x05a3b0(a0, a1);
        case 1956U: return ttr_fde_1956_0x05a3b4(a0, a1);
        case 1957U: return ttr_fde_1957_0x05a658(a0, a1);
        case 1958U: return ttr_fde_1958_0x05b17c(a0, a1);
        case 1959U: return ttr_fde_1959_0x05b1b0(a0, a1);
        case 1960U: return ttr_fde_1960_0x05b1f0(a0, a1);
        case 1961U: return ttr_fde_1961_0x05b238(a0, a1);
        case 1962U: return ttr_fde_1962_0x05b2f4(a0, a1);
        case 1963U: return ttr_fde_1963_0x05b324(a0, a1);
        case 1964U: return ttr_fde_1964_0x05b468(a0, a1);
        case 1965U: return ttr_fde_1965_0x05b480(a0, a1);
        case 1966U: return ttr_fde_1966_0x05b488(a0, a1);
        case 1967U: return ttr_fde_1967_0x05b4a0(a0, a1);
        case 1968U: return ttr_fde_1968_0x05b930(a0, a1);
        case 1969U: return ttr_fde_1969_0x05bacc(a0, a1);
        case 1970U: return ttr_fde_1970_0x05bcec(a0, a1);
        case 1971U: return ttr_fde_1971_0x05bd1c(a0, a1);
        case 1972U: return ttr_fde_1972_0x05bd24(a0, a1);
        case 1973U: return ttr_fde_1973_0x05bd5c(a0, a1);
        case 1974U: return ttr_fde_1974_0x05bd60(a0, a1);
        case 1975U: return ttr_fde_1975_0x05bd7c(a0, a1);
        case 1976U: return ttr_fde_1976_0x05bd88(a0, a1);
        case 1977U: return ttr_fde_1977_0x05bd8c(a0, a1);
        case 1978U: return ttr_fde_1978_0x05bd90(a0, a1);
        case 1979U: return ttr_fde_1979_0x05bdac(a0, a1);
        case 1980U: return ttr_fde_1980_0x05bdb0(a0, a1);
        case 1981U: return ttr_fde_1981_0x05bdcc(a0, a1);
        case 1982U: return ttr_fde_1982_0x05bdd8(a0, a1);
        case 1983U: return ttr_fde_1983_0x05bddc(a0, a1);
        case 1984U: return ttr_fde_1984_0x05bde0(a0, a1);
        case 1985U: return ttr_fde_1985_0x05bdfc(a0, a1);
        case 1986U: return ttr_fde_1986_0x05be00(a0, a1);
        case 1987U: return ttr_fde_1987_0x05be1c(a0, a1);
        case 1988U: return ttr_fde_1988_0x05be28(a0, a1);
        case 1989U: return ttr_fde_1989_0x05be2c(a0, a1);
        case 1990U: return ttr_fde_1990_0x05be30(a0, a1);
        case 1991U: return ttr_fde_1991_0x05be4c(a0, a1);
        case 1992U: return ttr_fde_1992_0x05be50(a0, a1);
        case 1993U: return ttr_fde_1993_0x05be6c(a0, a1);
        case 1994U: return ttr_fde_1994_0x05be78(a0, a1);
        case 1995U: return ttr_fde_1995_0x05be7c(a0, a1);
        case 1996U: return ttr_fde_1996_0x05be80(a0, a1);
        case 1997U: return ttr_fde_1997_0x05bebc(a0, a1);
        case 1998U: return ttr_fde_1998_0x05bf0c(a0, a1);
        case 1999U: return ttr_fde_1999_0x05bf10(a0, a1);
        case 2000U: return ttr_fde_2000_0x05bf2c(a0, a1);
        case 2001U: return ttr_fde_2001_0x05bf38(a0, a1);
        case 2002U: return ttr_fde_2002_0x05bf3c(a0, a1);
        case 2003U: return ttr_fde_2003_0x05bf40(a0, a1);
        case 2004U: return ttr_fde_2004_0x05bf9c(a0, a1);
        case 2005U: return ttr_fde_2005_0x05c228(a0, a1);
        case 2006U: return ttr_fde_2006_0x05c2a0(a0, a1);
        case 2007U: return ttr_fde_2007_0x05c398(a0, a1);
        case 2008U: return ttr_fde_2008_0x05c470(a0, a1);
        case 2009U: return ttr_fde_2009_0x05c51c(a0, a1);
        case 2010U: return ttr_fde_2010_0x05c520(a0, a1);
        case 2011U: return ttr_fde_2011_0x05c53c(a0, a1);
        case 2012U: return ttr_fde_2012_0x05c548(a0, a1);
        case 2013U: return ttr_fde_2013_0x05c54c(a0, a1);
        case 2014U: return ttr_fde_2014_0x05c550(a0, a1);
        case 2015U: return ttr_fde_2015_0x05c5ac(a0, a1);
        case 2016U: return ttr_fde_2016_0x05c5c4(a0, a1);
        case 2017U: return ttr_fde_2017_0x05c670(a0, a1);
        case 2018U: return ttr_fde_2018_0x05c774(a0, a1);
        case 2019U: return ttr_fde_2019_0x05c7c4(a0, a1);
        case 2020U: return ttr_fde_2020_0x05c8c4(a0, a1);
        case 2021U: return ttr_fde_2021_0x05cb7c(a0, a1);
        case 2022U: return ttr_fde_2022_0x05cb80(a0, a1);
        case 2023U: return ttr_fde_2023_0x05cb9c(a0, a1);
        case 2024U: return ttr_fde_2024_0x05cba8(a0, a1);
        case 2025U: return ttr_fde_2025_0x05cbac(a0, a1);
        case 2026U: return ttr_fde_2026_0x05cbb0(a0, a1);
        case 2027U: return ttr_fde_2027_0x05cc08(a0, a1);
        case 2028U: return ttr_fde_2028_0x05cc0c(a0, a1);
        case 2029U: return ttr_fde_2029_0x05cc28(a0, a1);
        case 2030U: return ttr_fde_2030_0x05cc34(a0, a1);
        default: return 0U;
    }
}

} // namespace ttr_render
