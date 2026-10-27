// ============================================================================
// File: terrain_vm_engine.h
// Target: libterrain.so (336,672 bytes)
// Task ID: TASK-136-RECONSTRUCTION-LIBTERRAIN (TASK_SO_062_libterrain)
// EN: Declarations for the Native Dalvik Bytecode Virtual Machine (vmInterpret),
//     Mixed Boolean-Arithmetic (MBA) deobfuscation primitives, LEB128/SLEB128
//     exception stream decoders, and packed-switch / sparse-switch / fill-array-data
//     payload handlers at 0x01231c..0x01cb30.
// VN: Khai báo cho Máy ảo Bytecode Dalvik Native (vmInterpret), các hàm nguyên thủy
//     giải mã Mixed Boolean-Arithmetic (MBA), bộ giải mã luồng ngoại lệ LEB128/SLEB128,
//     và trình xử lý payload packed-switch / sparse-switch / fill-array-data tại
//     0x01231c..0x01cb30.
// ============================================================================

#pragma once

#include "terrain_types.h"
#include "terrain_rodata_tables.h"
#include <cstdint>
#include <cstddef>

namespace nextai {
namespace opencut {
namespace terrain {

// EN: Exact Mixed Boolean-Arithmetic (MBA) identities used throughout 0x01231c..0x02673b:
//     - MbaAverageFloor32 (0x012340..0x012358): (((low | high) << 1) - (low ^ high)) >> 1
//     - MbaSub32 (0x013070..0x013078): (a ^ b) - ((~b & a) << 1) == a - b (wait: bic w8, w8, w20; eor w9, w8, w20; subs w8, w9, w8, lsl #1 -> (a ^ b) - ((a & ~b) << 1) == b - a or a - b!)
//     - MbaAdd64_XorAnd (0x013870..0x01387c): (a ^ b) + ((a & b) << 1) == a + b
//     - MbaAdd64_OrrXor (0x013664..0x013670): ((a | b) << 1) - (a ^ b) == a + b
//     - MbaXor8_OrrAnd (0x012fe8..0x012ff0): (a | b) - (a & b) == a ^ b
// VN: Các đồng nhất thức Mixed Boolean-Arithmetic (MBA) chính xác được dùng xuyên suốt 0x01231c..0x02673b.
int32_t  MbaAverageFloor32_012340(int32_t low, int32_t high) noexcept;
int32_t  MbaSubKey_013070(int32_t key, int32_t first_key) noexcept;
uint64_t MbaAdd64_XorAnd_013870(uint64_t a, uint64_t b) noexcept;
uint64_t MbaAdd64_OrrXor_013664(uint64_t a, uint64_t b) noexcept;
uint8_t  MbaXor8_OrrAnd_012fe8(uint8_t a, uint8_t b) noexcept;

// EN: Computes the runtime MBA pointer delta from code anchor 0x0135ac (0x013700..0x013774):
//     Returns 0xFFFFFFFFFF722DE0ULL (-0x008DD220).
// VN: Tính toán độ lệch con trỏ MBA lúc chạy từ điểm neo mã 0x0135ac (0x013700..0x013774):
//     Trả về 0xFFFFFFFFFF722DE0ULL (-0x008DD220).
uint64_t ComputeMbaPointerDelta_013700(uint64_t anchor_va = kTerrainMbaAnchorVa_0135ac) noexcept;

// EN: Decodes an XOR-obfuscated string using MBA XOR (0x012fd8, 0x01cb30, 0x027678).
// VN: Giải mã chuỗi bị làm rối XOR bằng phép toán MBA XOR (0x012fd8, 0x01cb30, 0x027678).
size_t DecodeXorString_012fd8(const uint8_t* enc, char* out, const uint8_t* key) noexcept;

// EN: Variable-length 5-byte Unsigned & Signed LEB128 decoders (0x0123b4..0x0124c8).
// VN: Bộ giải mã LEB128 không dấu và có dấu độ dài biến thiên 5 byte (0x0123b4..0x0124c8).
uint32_t DecodeUleb128_0123b4(const uint8_t** p_stream) noexcept;
int32_t  DecodeSleb128_012420(const uint8_t** p_stream) noexcept;

// EN: Binary search over try-catch ranges (0x01231c..0x0123b0) + SLEB128 catch list scan.
// VN: Tìm kiếm nhị phân trên các phạm vi try-catch (0x01231c..0x0123b0) + quét danh sách SLEB128.
int32_t SearchExceptionCatchHandler_01231c(
    const TerrainCatchRangeEntry* ranges,
    int32_t range_count,
    uint32_t rel_pc) noexcept;

// EN: Dalvik switch & array payload handlers (0x013010..0x01337c):
//     - HandlePackedSwitch_013010: verifies ident == 0x0100, returns branch target or +3
//     - HandleSparseSwitch_0130bc: verifies ident == 0x0200, binary searches sorted keys
//     - HandleFillArrayData_0131b4: verifies ident == 0x0300, copies width 1/2/4/8 elements
// VN: Trình xử lý payload switch & mảng của Dalvik (0x013010..0x01337c).
int32_t HandlePackedSwitch_013010(
    const uint16_t* payload_ptr,
    int32_t test_key,
    bool* out_bad_magic = nullptr) noexcept;

int32_t HandleSparseSwitch_0130bc(
    const uint16_t* payload_ptr,
    int32_t test_key,
    bool* out_bad_magic = nullptr) noexcept;

bool HandleFillArrayData_0131b4(
    void* dest_array_data,
    uint32_t dest_array_len,
    const uint16_t* payload_ptr,
    int* out_error_code = nullptr) noexcept;

// EN: Core threaded-code Dalvik bytecode interpreter loop (FDE #023 at 0x0135ac..0x01cb30)
//     and exported entry point `vmInterpret` (FDE #022 at 0x0133c0..0x0135ac).
// VN: Vòng lặp thông dịch bytecode Dalvik threaded-code cốt lõi (FDE #023 tại 0x0135ac..0x01cb30)
//     và điểm vào xuất `vmInterpret` (FDE #022 tại 0x0133c0..0x0135ac).
void VmInterpretThreadedLoop_0135ac(
    void* jni_env,
    const TerrainVmMethodCode* method_code,
    TerrainJValue* vregs,
    uint8_t* reg_obj_flags,
    TerrainJValue* out_result) noexcept;

} // namespace terrain
} // namespace opencut
} // namespace nextai

extern "C" {
// EN: Exported C symbol `vmInterpret` at 0x0133c0 (size = 492 bytes).
// VN: Biểu tượng C xuất `vmInterpret` tại 0x0133c0 (kích thước = 492 byte).
void vmInterpret(
    void* jni_env,
    const nextai::opencut::terrain::TerrainVmMethodCode* method_code,
    nextai::opencut::terrain::TerrainJValue* args,
    nextai::opencut::terrain::TerrainJValue* out_result);
}
