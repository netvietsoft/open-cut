/**
 * @file pumbaa_network_rbtree_dwarf.h
 * @brief Declarations for the `std::__ndk1::__tree` Red-Black Tree & `basic_string`
 *        methods exported in `.dynsym` (`0x002dfc..0x003640`) and the embedded
 *        LLVM `libunwind` DWARF CFI unwinder (`0x003644..0x006df0`) of
 *        `libpumbaa-network.so`.
 *        Khai báo các phương thức Cây Đỏ-Đen `std::__ndk1::__tree` & `basic_string`
 *        xuất trong `.dynsym` (`0x002dfc..0x003640`) và bộ giải gỡ ngăn xếp DWARF CFI
 *        nhúng (`0x003644..0x006df0`) của `libpumbaa-network.so`.
 */

#ifndef NEXTAI_OPENCUT_PUMBAA_NETWORK_RBTREE_DWARF_H_
#define NEXTAI_OPENCUT_PUMBAA_NETWORK_RBTREE_DWARF_H_

#include "pumbaa_network_types.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

// ============================================================================
// 1. `std::__ndk1::basic_string` & `std::__ndk1::__tree` Reconstructed Engine
//    Động cơ `basic_string` & Cây Đỏ-Đen `std::__ndk1::__tree` (`0x002dfc..0x003640`)
// ============================================================================

void LibcxxStringInitFromCStr(LibcxxString24Abi* dst, const char* s, size_t len);
void LibcxxStringCopyConstruct(LibcxxString24Abi* dst, const LibcxxString24Abi* src);
void LibcxxStringDestroy(LibcxxString24Abi* str) noexcept;
const char* LibcxxStringData(const LibcxxString24Abi* str) noexcept;
size_t LibcxxStringSize(const LibcxxString24Abi* str) noexcept;
int LibcxxStringCompare(const LibcxxString24Abi* a, const LibcxxString24Abi* b) noexcept;

/**
 * @brief Reconstructs `_ZNSt6__ndk127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_`
 *        (`0x003444..0x0035e0`, `416 bytes`).
 *        Tái dựng thuật toán cân bằng lại Cây Đỏ-Đen sau khi chèn (`0x003444..0x0035e0`).
 */
void RbTreeBalanceAfterInsert(RbTreeNodeStringPairAbi* root, RbTreeNodeStringPairAbi* x) noexcept;

/**
 * @brief Reconstructs `_ZNSt6__ndk16__tree<...>::__find_equal(root)` (`0x0031e4..0x003300`, `288 bytes`).
 *        Tái dựng hàm tìm vị trí chèn khóa trên Cây Đỏ-Đen từ gốc (`0x0031e4..0x003300`).
 */
RbTreeNodeStringPairAbi** RbTreeFindEqualRoot(
    LibcxxMapStringAbi* tree,
    RbTreeNodeStringPairAbi** out_parent,
    const LibcxxString24Abi& key) noexcept;

/**
 * @brief Reconstructs `_ZNSt6__ndk16__tree<...>::__find_equal(hint)` (`0x002f08..0x0031e0`, `732 bytes`).
 *        Tái dựng hàm tìm vị trí chèn khóa có gợi ý (`hint`) trên Cây Đỏ-Đen (`0x002f08..0x0031e0`).
 */
RbTreeNodeStringPairAbi** RbTreeFindEqualHint(
    LibcxxMapStringAbi* tree,
    RbTreeNodeStringPairAbi* hint,
    RbTreeNodeStringPairAbi** out_parent,
    RbTreeNodeStringPairAbi** out_dummy,
    const LibcxxString24Abi& key) noexcept;

/**
 * @brief Reconstructs `_ZNSt6__ndk16__tree<...>::__emplace_hint_unique_key_args` (`0x002dfc..0x002f04`, `268 bytes`).
 *        Allocates an 80-byte (`0x50`) node via `operator new(0x50)` (`0x002e44`), copy-constructs
 *        `key` at `+0x20` (`0x002e50`) and `value` at `+0x38` (`0x002e60`), links into the tree,
 *        calls `RbTreeBalanceAfterInsert` (`0x002e9c`), and increments `node_count` at `+0x10` (`0x002ea0`).
 */
RbTreeNodeStringPairAbi* RbTreeEmplaceHintUnique(
    LibcxxMapStringAbi* tree,
    RbTreeNodeStringPairAbi* hint,
    const LibcxxString24Abi& key,
    const std::pair<LibcxxString24Abi, LibcxxString24Abi>& kv_pair);

/**
 * @brief Reconstructs `_ZNSt6__ndk16__tree<...>::destroy` (`0x0035e4..0x003640`, `96 bytes`).
 *        Recursively destroys `left` (`+0x00`) and `right` (`+0x08`), frees heap buffers for
 *        `value` (`+0x38`, if `bit 0 == 1` frees `[+0x48]`) and `key` (`+0x20`, if `bit 0 == 1` frees `[+0x30]`),
 *        and calls `operator delete(node)`.
 */
void RbTreeDestroy(LibcxxMapStringAbi* tree, RbTreeNodeStringPairAbi* node) noexcept;

/**
 * @brief Advances to the in-order successor of an RB-tree node (`0x002258..0x00229c`, `0x002904..0x002948`).
 *        Di chuyển tới nút kế tiếp theo thứ tự trung thứ tự (in-order successor) trên Cây Đỏ-Đen.
 */
RbTreeNodeStringPairAbi* RbTreeNextNode(RbTreeNodeStringPairAbi* node) noexcept;

// ============================================================================
// 2. Embedded LLVM `libunwind` DWARF CFI Primitives (`0x003644..0x00406c`)
//    Các Nguyên hàm Giải gỡ Ngăn xếp DWARF CFI Nhúng (`0x003644..0x00406c`)
// ============================================================================

/**
 * @brief Reconstructs `readULEB128` (`0x003644..0x003668`, `40 bytes`).
 *        Giải mã số nguyên không dấu độ dài biến thiên ULEB128 (`0x003644..0x003668`).
 */
const uint8_t* DecodeDwarfULEB128(const uint8_t* p, uint64_t* out_val) noexcept;

/**
 * @brief Reconstructs `readSLEB128` (`0x00366c..0x0036a8`, `64 bytes`).
 *        Giải mã số nguyên có dấu độ dài biến thiên SLEB128 (`0x00366c..0x0036a8`).
 */
const uint8_t* DecodeDwarfSLEB128(const uint8_t* p, int64_t* out_val) noexcept;

/**
 * @brief Reconstructs `readEncodedPointer` (`0x0036ac..0x003798`, `240 bytes`) using the
 *        13-entry relative jump table at `.rodata 0x007060`.
 *        Giải mã con trỏ mã hóa DWARF (`DW_EH_PE_*`) tại `0x0036ac..0x003798`.
 */
const uint8_t* DecodeDwarfEncodedPointer(
    uint8_t encoding,
    uint64_t datarel_base,
    const uint8_t* p,
    uint64_t* out_val) noexcept;

/**
 * @brief Reconstructs `initDwarfRegisterSizeTable` (`0x00379c..0x0038ac`, `276 bytes`):
 *        writes `8` (`mov w0, #8`) to `.bss 0x010070..0x01008f` (registers `x0..x31`)
 *        and `.bss 0x0100b0..0x0100d0` (SIMD registers `v0..v31` + return column `96`).
 *        Khởi tạo bảng kích thước thanh ghi DWARF tại `.bss 0x010070..0x0100d0`.
 */
void InitDwarfRegisterSizeTable(PumbaaNetworkBssSegment& bss) noexcept;

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_PUMBAA_NETWORK_RBTREE_DWARF_H_
