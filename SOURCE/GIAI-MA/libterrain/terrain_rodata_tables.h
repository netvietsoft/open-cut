// ============================================================================
// File: terrain_rodata_tables.h
// Target: libterrain.so (336,672 bytes)
// Task ID: TASK-136-RECONSTRUCTION-LIBTERRAIN (TASK_SO_062_libterrain)
// EN: Read-only data (.rodata 0x03f530..0x0427b9) and initialized data (.data
//     0x054000..0x055a00) tables extracted byte-for-byte from libterrain.so.
// VN: Các bảng dữ liệu chỉ đọc (.rodata 0x03f530..0x0427b9) và dữ liệu khởi tạo
//     (.data 0x054000..0x055a00) được trích xuất chuẩn từng byte từ libterrain.so.
// ============================================================================

#pragma once

#include "terrain_types.h"
#include <cstdint>
#include <cstddef>

namespace nextai {
namespace opencut {
namespace terrain {

// EN: Descriptor for each XOR-encrypted string entry in .rodata (0x03f530..0x040310).
// VN: Bộ mô tả cho từng mục chuỗi mã hóa XOR trong .rodata (0x03f530..0x040310).
struct TerrainXorStringEntry {
    const char*    symbol_name;
    uint32_t       enc_va;
    uint32_t       key_va;
    uint32_t       bss_target_va;
    uint32_t       length;
    const uint8_t* enc_bytes;
    const uint8_t* key_bytes;
    const char*    expected_plaintext;
};

// EN: 35 XOR-encoded JNI & VM diagnostic strings from .rodata.
// VN: 35 chuỗi chẩn đoán VM & JNI được mã hóa XOR từ .rodata.
extern const TerrainXorStringEntry kTerrainXorStringTable[35];

// EN: 25-byte switch jump index table at .rodata 0x03fde4 used by getCacheClass (0x0275ec)
//     for descriptor characters 'B' (0x42) through 'Z' (0x5A).
// VN: Bảng chỉ mục nhảy switch 25 byte tại .rodata 0x03fde4 được sử dụng bởi getCacheClass
//     (0x0275ec) cho các ký tự mô tả từ 'B' (0x42) đến 'Z' (0x5A).
extern const uint8_t kGetCacheClassJumpOffsets_03fde4[25];

// EN: 8-entry relative jump offset table (int32_t) at .rodata 0x03f614 used by
//     HandleFillArrayData_0131b4 for element_width in {1, 2, 4, 8}.
// VN: Bảng độ lệch nhảy tương đối 8 mục (int32_t) tại .rodata 0x03f614 được dùng bởi
//     HandleFillArrayData_0131b4 cho element_width thuộc {1, 2, 4, 8}.
extern const int32_t kFillArrayWidthJumpOffsets_03f614[8];

// EN: 16 NEON 64-bit shift constant vectors at .rodata 0x03fbe8..0x03fc68 used by
//     FDE #027 JNI invocation bridge (0x01cc3c..0x01cd04).
// VN: 16 vector hằng số dịch bit NEON 64-bit tại .rodata 0x03fbe8..0x03fc68 được dùng
//     bởi cầu nối gọi hàm JNI FDE #027 (0x01cc3c..0x01cd04).
extern const uint64_t kNeonShiftVectors_03fbe8[16];

// EN: 256-entry 64-bit threaded-code opcode handler VA table at .data 0x054000..0x054800
//     (entry 0 is 0; entries 1..255 hold the 255 Dalvik handler addresses in .text).
// VN: Bảng địa chỉ ảo trình xử lý opcode threaded-code 64-bit gồm 256 mục tại .data
//     0x054000..0x054800 (mục 0 bằng 0; mục 1..255 chứa 255 địa chỉ trình xử lý Dalvik).
extern const uint64_t kVmOpcodeHandlerTable_054000[256];

// EN: 32 MBA-shifted 64-bit pointers at .data 0x055900..0x0559f8 (each pointer is stored
//     as real_va + 0x008DD220 and deobfuscated at runtime by adding kTerrainMbaExpectedDelta).
// VN: 32 con trỏ 64-bit dịch MBA tại .data 0x055900..0x0559f8 (mỗi con trỏ được lưu dưới
//     dạng real_va + 0x008DD220 và giải mã lúc chạy bằng cách cộng kTerrainMbaExpectedDelta).
extern const uint64_t kMbaShiftedDataPointers_055900[32];

} // namespace terrain
} // namespace opencut
} // namespace nextai
