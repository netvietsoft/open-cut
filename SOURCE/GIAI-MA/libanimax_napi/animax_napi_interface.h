/**
 * @file animax_napi_interface.h
 * @brief Master Public C++17 & C ABI Interface for libanimax_napi.so (Lynx AnimaX NAPI Composition Bridge)
 *        Giao diện C++17 & C ABI Công khai Tổng thể cho libanimax_napi.so (Cầu nối NAPI Composition của Lynx AnimaX)
 *
 * Binary Ground Truth (libanimax_napi.so — 84,064 bytes, 25 ELF64 sections):
 *   - `.text`:        `0x008000..0x00c448` (`17,480 bytes`)
 *   - `.plt`:         `0x00c450..0x00c9dc` (`1,420 bytes`, 87 PLT thunks)
 *   - `.rodata`:      `0x003198..0x00348f` (`760 bytes`)
 *   - `.data.rel.ro`: `0x010000..0x0103f7` (`1,016 bytes`, 8 vtables + typeinfo)
 *   - `.init_array`:  `0x010408..0x01040f` (`8 bytes` -> `0x00803c` `__cxx_global_var_init`)
 *   - `.data`:        `0x014000..0x014027` (`40 bytes` `NapiModuleXxDescriptor` for `"animax"`)
 */

#ifndef OPENCUT_ANIMAX_NAPI_INTERFACE_H_
#define OPENCUT_ANIMAX_NAPI_INTERFACE_H_

#include "animax_napi_types.h"
#include "animax_napi_hash_stl.h"
#include "animax_napi_task_value.h"
#include "animax_napi_composition.h"
#include <cstdint>
#include <string>
#include <vector>

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. ELF64 BINARY METADATA & RELOCATION DESCRIPTORS
// ============================================================================

/**
 * @brief Exact ELF64 section descriptor for `libanimax_napi.so` (`84,064 bytes`).
 *        Mô tả phân đoạn ELF64 chính xác của `libanimax_napi.so` (`84,064 bytes`).
 */
struct ElfSectionMetadata {
    uint32_t index;
    const char* name;
    uint64_t virtual_address;
    uint64_t file_offset;
    uint64_t size_bytes;
};

/**
 * @brief Exact `.rela.plt` jump-slot relocation entry (`87 entries` in `0x002490..0x002cb8`).
 *        Mục relocation nhảy `.rela.plt` chính xác (`87 mục` tại `0x002490..0x002cb8`).
 */
struct PltImportEntry {
    uint32_t plt_index;
    uint64_t plt_stub_vaddr;
    uint64_t got_slot_vaddr;
    const char* symbol_name;
    const char* demangled_purpose;
};

/**
 * @brief Exact `.data.rel.ro` vtable / RTTI / descriptor entry (`0x010000..0x0103f7`).
 *        Mục bảng hàm ảo vtable / RTTI / descriptor trong `.data.rel.ro` (`0x010000..0x0103f7`).
 */
struct DataRelRoObjectEntry {
    uint64_t vaddr;
    uint64_t size_bytes;
    const char* symbol_or_role;
    const char* target_details;
};

/**
 * @brief Diagnostic report produced by the end-to-end `libanimax_napi.so` verification harness.
 *        Báo cáo chẩn đoán tạo bởi bộ kiểm thử xác minh toàn diện `libanimax_napi.so`.
 */
struct AnimaXNapiVerificationReport {
    bool all_passed{false};
    uint32_t total_checks{0};
    uint32_t passed_checks{0};
    uint64_t sample_cityhash64{0};
    uint32_t sample_prime_bucket{0};
    int32_t sample_parsed_color{0};
    std::string failure_reason;
};

// ============================================================================
// 2. CATALOG & SELF-VERIFICATION API
// ============================================================================

/**
 * @brief Returns the complete 25-section ELF64 table of `libanimax_napi.so`.
 *        Trả về bảng 25 phân đoạn ELF64 đầy đủ của `libanimax_napi.so`.
 */
const std::vector<ElfSectionMetadata>& GetAnimaXNapiElfSections();

/**
 * @brief Returns all key `.plt` / `.rela.plt` external symbol bindings (`0x00c450..0x00c9dc`).
 *        Trả về danh sách các liên kết biểu tượng ngoại vi `.plt` / `.rela.plt` (`0x00c450..0x00c9dc`).
 */
const std::vector<PltImportEntry>& GetAnimaXNapiPltImports();

/**
 * @brief Returns all `.data.rel.ro` vtables and function descriptors (`0x010000..0x0103f7`).
 *        Trả về toàn bộ các bảng vtable và descriptor hàm trong `.data.rel.ro` (`0x010000..0x0103f7`).
 */
const std::vector<DataRelRoObjectEntry>& GetAnimaXNapiDataRelRoEntries();

/**
 * @brief Runs the deterministic mathematical and behavioral verification suite for `libanimax_napi.so`.
 *        Chạy bộ kiểm thử xác minh toán học và hành vi tất định cho `libanimax_napi.so`.
 */
AnimaXNapiVerificationReport RunAnimaXNapiSelfVerification();

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx

#endif  // OPENCUT_ANIMAX_NAPI_INTERFACE_H_
