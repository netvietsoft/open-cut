// ============================================================================
// File: tttext_lite_rodata_tables.h
// Target: libtttext_lite.so (297,312 bytes)
// Clean-Room C++17 Reconstruction — Exact .rodata & .data Tables
// Tái cấu trúc phòng sạch C++17 — Bảng hằng số .rodata & .data chính xác
// ============================================================================
#pragma once

#include "tttext_lite_types.h"
#include <cstdint>
#include <cstddef>

namespace ttoffice {
namespace tttext {

// 1. SIMD & Vector Constants in .rodata (0x00d9c0 .. 0x00d9fb)
//    Hằng số SIMD & Vector trong .rodata (0x00d9c0 .. 0x00d9fb)
extern const uint8_t kRodataVecMaskD9C0[16];
extern const uint8_t kRodataVecMaskD9D0[16];
extern const uint32_t kRodataBidiIndexVecD9E0[4];
extern const uint8_t kRodataShaperJumpTableD9F0[12];

// 2. BoundaryAnalyst Relative Byte-Offset Jump Tables (0x00d9fc .. 0x00daaf)
//    Bảng nhảy tương đối (relative byte-offset) của BoundaryAnalyst (0x00d9fc .. 0x00daaf)
extern const uint8_t kBoundaryCharJumpTableD9FC[175];
extern const uint8_t kBoundaryStrategyJumpTableDAAB[5];

// 3. Default Style & Switch Jump Tables (0x00dab0 .. 0x00db4d)
//    Hằng số kiểu mặc định & bảng nhảy switch (0x00dab0 .. 0x00db4d)
extern const uint64_t kRodataDefaultCapDAB0;
extern const uint32_t kRodataDefaultStyleScaleBitsDAB8[2];
extern const uint8_t kStyleAndLayoutJumpTablesDAC0[142];

// 4. HarfBuzz Dynamic Symbol Table (39 symbols resolved in HarfbuzzLib::LoadHarfbuzzLib)
//    Bảng 39 tên ký hiệu HarfBuzz nạp động trong HarfbuzzLib::LoadHarfbuzzLib (0x01d798)
struct SymbolStringEntry {
    uint32_t rodata_vaddr;
    const char* name;
};

constexpr size_t kHarfbuzzSymbolCount = 39;
extern const SymbolStringEntry kHarfbuzzSymbolTable[kHarfbuzzSymbolCount];

// 5. ICU Dynamic Symbol Table (15 symbols resolved via 0x01aaa4 dlsym wrapper)
//    Bảng 15 tên ký hiệu ICU nạp động qua trình bọc dlsym tại 0x01aaa4
constexpr size_t kIcuSymbolCount = 15;
extern const SymbolStringEntry kIcuSymbolTable[kIcuSymbolCount];

// 6. .data ControlRunList (0x048008) & SpaceList (0x048068)
//    Danh sách ControlRunList (0x048008) & SpaceList (0x048068) trong .data
constexpr size_t kControlRunListCount = 6;
extern const ControlRunEntry kDataControlRunList[kControlRunListCount];

constexpr size_t kSpaceListCount = 3;
extern const char* const kDataSpaceList[kSpaceListCount];

// 7. .data JNINativeMethod Registration Table (0x048080 .. 0x0480df)
//    Bảng đăng ký JNINativeMethod trong .data (0x048080 .. 0x0480df)
constexpr size_t kJniNativeMethodCount = 4;
extern const JniNativeMethodEntry kDataJniNativeMethods[kJniNativeMethodCount];

} // namespace tttext
} // namespace ttoffice
