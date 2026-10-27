// ============================================================================
// File: gaia_rodata_tables.h
// Target: libgaia_lib.so (329,704 bytes)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Description:
//   EN: Exact .rodata (0x0437a0..0x0461b7), .data (0x054000), and .init_array
//       (0x052628..0x052638) lookup tables and constants extracted from
//       libgaia_lib.so.
//   VN: Cac bang tra cuu va hang so trich xuat chinh xac tu .rodata
//       (0x0437a0..0x0461b7), .data (0x054000) va .init_array (0x052628..0x052638).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>

namespace AmazingEngine {
namespace rodata {

// .init_array (va=0x052628, off=0x04e628, 24 bytes = 3 global constructor VAs)
extern const uint64_t kInitArrayConstructors_052628[3];

// .data (va=0x054000, off=0x050000, 4 bytes): DefaultMemoryAlignment = 0x00000010 (16)
extern const uint32_t kDefaultMemoryAlignment_054000;

// .rodata 0x043ae0 .. 0x043edf: Ken Perlin 256-entry permutation table (int32_t[256])
extern const int32_t kPerlinPermTable_043ae0[256];

// .rodata 0x043a60 .. 0x043adf: 8 Perlin3D gradient dispatch jump tables (8 x 16 bytes)
extern const uint8_t kPerlin3DGradJumpTables_043a60[8][16];

// .rodata 0x043f10 .. 0x043f2f: Exported Vector2f IEEE-754 constants
constexpr uint32_t kVector2fEpsilonBits_043f10  = 0x3727C5ACu; // 1.0e-5f
constexpr uint32_t kVector2fInfinityBits_043f14 = 0x7F800000u; // +INFINITY
constexpr uint32_t kSlerpLinearThreshold_018770 = 0x3F733333u; // 0.95f

// .rodata 0x045f00 .. 0x045f07: stb_truetype contour flatten jump tables
constexpr uint32_t kStbttFlattenJumpTable1_045f00 = 0x35004D22u;
constexpr uint32_t kStbttFlattenJumpTable2_045f04 = 0x37004F22u;

// .rodata 0x045ee0 .. 0x046127: stb_truetype CFF/Expert charset lookup table (292 uint16_t)
extern const uint16_t kStbttCharsetTable_045ee0[292];

// .rodata 0x045286 .. 0x045d02: 61 Cronet C API symbols dynamically loaded from libsscronet.so
extern const char* const kCronetMethodNames_045286[61];

} // namespace rodata
} // namespace AmazingEngine
