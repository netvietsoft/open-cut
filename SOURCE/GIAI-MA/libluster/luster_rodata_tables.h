/**
 * @file luster_rodata_tables.h
 * @brief Clean-Room C++17 Declarations for libluster.so .rodata & .data.rel.ro Tables
 *        Khai báo C++17 cho các bảng dữ liệu .rodata (0x167d0..0x366be) & .data.rel.ro (0x3f730..0x3fd58)
 */

#ifndef NEXTAI_OPENCUT_LUSTER_RODATA_TABLES_H_
#define NEXTAI_OPENCUT_LUSTER_RODATA_TABLES_H_

#include "luster_types.h"

namespace nextai {
namespace opencut {
namespace luster {

extern const LusterClassRegEntry kLusterProtectedClasses[kLusterProtectedClassCount];
extern const LusterMethodRegEntry kLusterVirtualizedMethods[kLusterVirtualizedMethodCount];
extern const int32_t kLusterHotStringIndices[kLusterHotStringTableCapacity];
extern const LusterFieldDesc kLusterFieldDescriptors[kLusterFieldDescriptorCount];
extern const LusterMethodDesc kLusterMethodDescriptors[kLusterMethodDescriptorCount];

struct LusterBytecodeUnitInfo {
    uint32_t unit_index;
    uint64_t data_slot_vaddr;
    uint64_t obfuscated_reloc;
    uint64_t real_rodata_vaddr;
    uint8_t  header_bytes[16];
};

extern const LusterBytecodeUnitInfo kLusterBytecodeUnits[kLusterBytecodeUnitCount];

/**
 * @brief Stream XOR decryptor matching sub_16328 (0x16328..0x16354).
 *        Hàm giải mã chuỗi XOR khớp tuyệt đối sub_16328 (0x16328..0x16354).
 *
 * Disassembly:
 *   0x16328: ldrb w8, [x2]
 *   0x1632c: cbz  w8, #0x16354
 *   0x16330: mov  x9, xzr
 *   0x16334: mov  w10, #1
 *   0x16338: ldrb w11, [x0, x9]
 *   0x1633c: eor  w8, w11, w8
 *   0x16340: strb w8, [x1, x9]
 *   0x16344: sxtw x9, w10
 *   0x16348: ldrb w8, [x2, x9]
 *   0x1634c: add  w10, w10, #1
 *   0x16350: cbnz w8, #0x16338
 *   0x16354: ret
 */
void sub_16328(const uint8_t* cipher_bytes, uint8_t* out_plaintext, const uint8_t* key_bytes) noexcept;

/**
 * @brief Decrypts one of the 6 core XOR-obfuscated strings (S1..S6) in libluster.so.
 *        Giải mã 1 trong 6 chuỗi XOR cốt lõi (S1..S6) trong libluster.so.
 */
const char* DecryptLusterCoreXorString(uint32_t slot_index) noexcept;

/**
 * @brief Looks up a string in the reconstructed string table by its string index (0..1789).
 *        Tra cứu chuỗi trong bảng chuỗi đã khôi phục theo chỉ mục (0..1789).
 */
const char* GetLusterPooledString(uint32_t str_idx) noexcept;

/**
 * @brief Resolves an internal class name via double-indirection: 0x16a0c + 0x29380[0x2af78[class_id]].
 *        Phân giải tên lớp nội bộ qua bảng gián tiếp kép: 0x16a0c + 0x29380[0x2af78[class_id]].
 */
const char* ResolveLusterClassNameById(uint32_t class_id) noexcept;

} // namespace luster
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LUSTER_RODATA_TABLES_H_
