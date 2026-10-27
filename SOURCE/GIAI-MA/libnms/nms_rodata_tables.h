/**
 * @file nms_rodata_tables.h
 * @brief Exact .rodata (0x00b100..0x010be9), .data (0x04eea8..0x04f0e8), and .bss (0x04f6c4) tables for libnms.so.
 *        Các bảng dữ liệu chính xác từ .rodata (0x00b100..0x010be9), .data (0x04eea8..0x04f0e8) và .bss (0x04f6c4) của libnms.so.
 *
 * Binary target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libnms.so (293,272 bytes)
 *   All ciphertexts, keys, .rela.dyn addends, and sentinel magic constants are byte-for-byte
 *   extracted from the AArch64 ELF binary (OBSERVED).
 */

#ifndef NEXTAI_OPENCUT_NMS_RODATA_TABLES_H_
#define NEXTAI_OPENCUT_NMS_RODATA_TABLES_H_

#include "nms_types.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <string>

namespace nextai {
namespace opencut {
namespace nms {

/**
 * @brief Plaintext .rodata constants at 0x00b152..0x00b164 (OBSERVED).
 *        Các hằng số chuỗi .rodata dạng rõ tại 0x00b152..0x00b164 (QUAN SÁT ĐƯỢC).
 *
 * Note: At 0x014e74..0x014f74 in sub_14ddc, "com.pgl.ssdk.ces.a" (0x00b152) is copied to the
 * stack and every '.' (0x2e) is replaced in-place with '/' (0x2f) before calling FindClass.
 */
extern const char kRodataCesClassNameDotted[]; // .rodata 0x00b152: "com.pgl.ssdk.ces.a"
extern const char kRodataCesClassNameSlashed[]; // stack-transformed: "com/pgl/ssdk/ces/a"

/**
 * @brief .init_array (0x049fe0) and .fini_array (0x049fc8) function pointer tables (OBSERVED).
 *        Bảng con trỏ hàm .init_array (0x049fe0) và .fini_array (0x049fc8) (QUAN SÁT ĐƯỢC).
 */
extern const std::array<uint64_t, 1> kInitArrayTable; // [0x01432c]
extern const std::array<uint64_t, 3> kFiniArrayTable; // [0x014288, 0x014ddc, 0x014270]

/**
 * @brief Catalog of 30 verified .rodata null-terminated key XOR entries decrypted via sub_14bd4 (OBSERVED).
 *        Danh mục 30 bản ghi XOR khóa kết thúc null trong .rodata giải mã qua sub_14bd4 (QUAN SÁT ĐƯỢC).
 */
extern const std::array<NmsXorEntry, 30> kNmsXorCatalog;

/**
 * @brief Catalog of 19 verified .rodata 4-byte-key RC4 entries decrypted via sub_1bde4 / sub_1ba38 (OBSERVED).
 *        Danh mục 19 bản ghi RC4 khóa 4-byte trong .rodata giải mã qua sub_1bde4 / sub_1ba38 (QUAN SÁT ĐƯỢC).
 */
extern const std::array<NmsRc4Entry, 19> kNmsRc4Catalog;

/**
 * @brief MBA-encoded .rela.dyn relocation table in .data (0x04ef70..0x04f0e0, 47 slots) (OBSERVED).
 *        Bảng định vị lại .rela.dyn mã hóa MBA trong .data (0x04ef70..0x04f0e0, 47 ô) (QUAN SÁT ĐƯỢC).
 *
 * Each slot stores an R_AARCH64_RELATIVE addend such that adding the MBA offset
 * -0x875128 (0xFFFFFFFFFF78AED8ULL) computed at 0x03c690..0x03c700 yields the exact
 * virtual address in .rodata (0x010850..0x010bb0) or .bss (0x050358..0x0504c4).
 */
extern const std::array<NmsMbaRelocEntry, 47> kNmsDataMbaRelocTable;

/**
 * @brief MBA-encoded .rela.dyn relocation pair at .data 0x04eea8..0x04eeb0 used by sub_38a58 (OBSERVED).
 *        Cặp con trỏ .rela.dyn mã hóa MBA tại .data 0x04eea8..0x04eeb0 dùng bởi sub_38a58 (QUAN SÁT ĐƯỢC).
 *
 * Adding MBA offset -0xA991C0 (0xFFFFFFFFFF566E40ULL) computed at 0x038b04..0x038b70 yields:
 *   0x04eea8: 0x00AA8DFFULL + 0xFFFFFFFFFF566E40ULL == 0x0000FC3FULL (RC4 ciphertext for "38816")
 *   0x04eeb0: 0x00AA8E04ULL + 0xFFFFFFFFFF566E40ULL == 0x0000FC44ULL (4-byte RC4 key for "38816")
 */
extern const std::array<NmsMbaRelocEntry, 2> kNmsMetaEntryMbaRelocPair;

/**
 * @brief Unaligned 12-slot integrity sentinel specification at .bss 0x04f6c4 checked by sub_34ab0 (OBSERVED).
 *        Đặc tả 12 ô sentinel kiểm tra toàn vẹn lệch biên tại .bss 0x04f6c4 trong sub_34ab0 (QUAN SÁT ĐƯỢC).
 */
extern const std::array<NmsSentinelSlot, 11> kNmsSentinelSlots;

/**
 * @brief Complete list of 38 emulator/virtualization file paths probed by sub_205fc (0x0205fc..0x020b8c) (OBSERVED).
 *        Danh sách 38 đường dẫn file giả lập/ảo hóa được dò quét bởi sub_205fc (QUAN SÁT ĐƯỢC).
 */
extern const std::array<const char*, 38> kNmsEmulatorFilePaths;

/**
 * @brief Lookup a verified XOR entry by its ciphertext virtual address in .rodata.
 *        Tra cứu bản ghi XOR đã xác minh theo địa chỉ ảo ciphertext trong .rodata.
 */
const NmsXorEntry* find_xor_entry_by_ct_vaddr(uint32_t ct_vaddr) noexcept;

/**
 * @brief Lookup a verified RC4 entry by its ciphertext virtual address in .rodata.
 *        Tra cứu bản ghi RC4 đã xác minh theo địa chỉ ảo ciphertext trong .rodata.
 */
const NmsRc4Entry* find_rc4_entry_by_ct_vaddr(uint32_t ct_vaddr) noexcept;

/**
 * @brief Lookup a resolved .data MBA pointer by its .data slot virtual address (0x04ef70..0x04f0e0).
 *        Tra cứu con trỏ MBA trong .data theo địa chỉ ảo của ô .data (0x04ef70..0x04f0e0).
 */
uint64_t lookup_data_mba_resolved_vaddr(uint32_t data_vaddr) noexcept;

} // namespace nms
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NMS_RODATA_TABLES_H_
