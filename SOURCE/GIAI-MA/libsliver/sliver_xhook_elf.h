/**
 * @file sliver_xhook_elf.h
 * @brief ELF64 Symbol Resolver (.dynsym / .symtab / .gnu_debugdata XZ) & Embedded xHook 1.2.0.
 *        Bộ phân giải ký hiệu ELF64 (.dynsym / .symtab / .gnu_debugdata XZ) & xHook 1.2.0 nhúng.
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - xdl / ELF Symbol Resolver: 0x008508..0x0099f4
 *   - xdl_open / dl_iterate_phdr / /proc/self/maps parser: 0x008508..0x008944
 *   - xdl_close: 0x008948..0x008988
 *   - xdl_sym (DT_GNU_HASH DJB2 + 64-bit Bloom filter & DT_HASH SysV): 0x00898c..0x008c8c
 *   - xdl_dsym (.symtab & .gnu_debugdata XZ/LZMA decompression via liblzma.so): 0x008c90..0x009310
 *   - Read Android API level (ro.build.version.sdk + /system/build.prop fallback): 0x0098cc..0x0099f4
 * - Embedded libxhook 1.2.0 (aarch64): 0x0099f8..0x00bd64
 *   - xhook_register:                  0x00b61c
 *   - xhook_ignore:                    0x00b730
 *   - xhook_refresh:                   0x00b844
 *   - xhook_clear:                     0x00b9f0
 *   - xhook_enable_debug:              0x00bb48
 *   - xhook_enable_sigsegv_protection: 0x00bb64
 *   - Signed SLEB128 APS2 relocation decoder: 0x00b528..0x00b58c
 *   - AArch64 I-Cache / D-Cache maintenance (ctr_el0, dc cvau, ic ivau): 0x00f800..0x00f878
 */

#pragma once

#include "sliver_types.h"
#include <elf.h>
#include <regex.h>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace bytedance {
namespace sliver {

// ============================================================================
// 1. xdl / ELF64 Symbol Resolver Handle (208 bytes = 0xd0 @ 0x00887c)
// ============================================================================

/**
 * @brief Loaded ELF64 Library Handle (208 bytes = 0xd0 allocated via calloc(1, 0xd0) @ 0x00887c).
 *        Cấu trúc quản lý thư viện ELF64 đã nạp (208 byte = 0xd0 cấp phát qua calloc(1, 0xd0)).
 *
 * Binary Layout (0x00887c..0x009310):
 *   +0x00: char*          pathname          (strdup of library path)
 *   +0x08: uintptr_t      load_bias         (base virtual address delta)
 *   +0x10: const Elf64_Phdr* phdr           (program header table pointer)
 *   +0x18: uint16_t       phnum             (number of program headers)
 *   +0x28: void*          dlopen_handle     (optional linker handle from dlopen/loader_dlopen)
 *   +0x30: uint8_t        dynsym_resolved   (1 if PT_DYNAMIC parsed)
 *   +0x38: const Elf64_Sym* dynsym          (DT_SYMTAB)
 *   +0x40: const char*    dynstr            (DT_STRTAB)
 *   +0x48: const uint32_t* sysv_buckets     (DT_HASH buckets)
 *   +0x50: uint32_t       sysv_nbuckets     (DT_HASH nbucket)
 *   +0x58: const uint32_t* sysv_chains      (DT_HASH chains)
 *   +0x60: uint32_t       sysv_nchains      (DT_HASH nchain)
 *   +0x68: const uint32_t* gnu_buckets      (DT_GNU_HASH buckets)
 *   +0x70: uint32_t       gnu_nbuckets      (DT_GNU_HASH nbuckets)
 *   +0x78: const uint32_t* gnu_chains       (DT_GNU_HASH chains)
 *   +0x80: uint32_t       gnu_symoffset     (DT_GNU_HASH symoffset)
 *   +0x88: const uint64_t* gnu_bloom        (DT_GNU_HASH 64-bit bloom filter array)
 *   +0x90: uint32_t       gnu_bloom_sz      (DT_GNU_HASH bloom_size)
 *   +0x94: uint32_t       gnu_bloom_shift   (DT_GNU_HASH bloom_shift)
 *   +0x98: uint8_t        symtab_resolved   (1 if .symtab / .gnu_debugdata parsed)
 *   +0xa0: const Elf64_Ehdr* ehdr           (mapped ELF header)
 *   +0xa8: uint8_t*       debugdata_elf     (decompressed .gnu_debugdata ELF buffer)
 *   +0xb0: Elf64_Sym*     symtab            (.symtab symbol array)
 *   +0xb8: size_t         symtab_count      (number of symbols in .symtab)
 *   +0xc0: char*          strtab            (.strtab string buffer)
 *   +0xc8: size_t         strtab_size       (size of .strtab in bytes)
 */
struct ElfSymbolHandle {
    char*             pathname{nullptr};        // +0x00
    uintptr_t         load_bias{0};             // +0x08
    const Elf64_Phdr* phdr{nullptr};            // +0x10
    uint16_t          phnum{0};                 // +0x18
    uint16_t          pad_1a[7]{};              // +0x1a..+0x27
    void*             dlopen_handle{nullptr};   // +0x28
    uint8_t           dynsym_resolved{0};       // +0x30
    uint8_t           pad_31[7]{};              // +0x31..+0x37
    const Elf64_Sym*  dynsym{nullptr};          // +0x38
    const char*       dynstr{nullptr};          // +0x40
    const uint32_t*   sysv_buckets{nullptr};    // +0x48
    uint32_t          sysv_nbuckets{0};         // +0x50
    uint32_t          pad_54{0};                // +0x54
    const uint32_t*   sysv_chains{nullptr};     // +0x58
    uint32_t          sysv_nchains{0};          // +0x60
    uint32_t          pad_64{0};                // +0x64
    const uint32_t*   gnu_buckets{nullptr};     // +0x68
    uint32_t          gnu_nbuckets{0};          // +0x70
    uint32_t          pad_74{0};                // +0x74
    const uint32_t*   gnu_chains{nullptr};      // +0x78
    uint32_t          gnu_symoffset{0};         // +0x80
    uint32_t          pad_84{0};                // +0x84
    const uint64_t*   gnu_bloom{nullptr};       // +0x88
    uint32_t          gnu_bloom_sz{0};          // +0x90
    uint32_t          gnu_bloom_shift{0};       // +0x94
    uint8_t           symtab_resolved{0};       // +0x98
    uint8_t           pad_99[7]{};              // +0x99..+0x9f
    const Elf64_Ehdr* ehdr{nullptr};            // +0xa0
    uint8_t*          debugdata_elf{nullptr};   // +0xa8
    Elf64_Sym*        symtab{nullptr};          // +0xb0
    size_t            symtab_count{0};          // +0xb8
    char*             strtab{nullptr};          // +0xc0
    size_t            strtab_size{0};           // +0xc8
};

// ============================================================================
// 2. xHook Red-Black Tree & Hook Registration Structs (OBSERVED)
// ============================================================================

/**
 * @brief Hook Registration Entry (72 bytes = 0x48 allocated at 0x00b6b4).
 *        Mục đăng ký hook (72 byte = 0x48 cấp phát tại 0x00b6b4).
 *
 * Binary Layout:
 *   +0x00: regex_t                 pathname_regex (32 bytes on AArch64 Bionic)
 *   +0x20: char*                   symbol_name
 *   +0x28: void*                   new_func
 *   +0x30: void**                  old_func
 *   +0x38: XHookHookEntry*         next
 *   +0x40: XHookHookEntry**        prev_next
 */
struct XHookRegisterEntry {
    regex_t              pathname_regex{};     // +0x00 (32 bytes)
    char*                symbol_name{nullptr}; // +0x20
    void*                new_func{nullptr};    // +0x28
    void**               old_func{nullptr};    // +0x30
    XHookRegisterEntry*  next{nullptr};        // +0x38
    XHookRegisterEntry** prev_next{nullptr};   // +0x40
};

/**
 * @brief Ignore Registration Entry (56 bytes = 0x38 allocated at 0x00b7c4).
 *        Mục đăng ký bỏ qua hook (56 byte = 0x38 cấp phát tại 0x00b7c4).
 */
struct XHookIgnoreEntry {
    regex_t            pathname_regex{};     // +0x00 (32 bytes)
    char*              symbol_name{nullptr}; // +0x20 (nullptr = ignore entire library)
    XHookIgnoreEntry*  next{nullptr};        // +0x28
    XHookIgnoreEntry** prev_next{nullptr};   // +0x30
};

/**
 * @brief Red-Black Tree Node for Mapped ELF Libraries in xHook (224 bytes = 0xe0 @ 0x009c90).
 *        Nút cây Đỏ-Đen lưu thông tin thư viện ELF trong xHook (224 byte = 0xe0 @ 0x009c90).
 */
struct XHookElfMapNode {
    char*            pathname{nullptr};       // +0x00
    uintptr_t        base_addr{0};            // +0x08
    uint8_t          elf_inspector[0xb0]{};   // +0x10..+0xbf: parsed ELF PLT/GOT tables
    XHookElfMapNode* left{nullptr};           // +0xc0
    XHookElfMapNode* right{nullptr};          // +0xc8
    XHookElfMapNode* parent{nullptr};         // +0xd0
    int32_t          color{0};                // +0xd8 (1 = RED, 0 = BLACK)
    int32_t          pad_dc{0};               // +0xdc
};

// ============================================================================
// 3. Symbol Resolution, SLEB128, & Cache Maintenance APIs
// ============================================================================

/**
 * @brief Computes GNU Hash (DJB2: seed 5381, h = h * 33 + c) (0x0089c8..0x0089e4 & 0x00aa94..0x00aab0).
 *        Tính giá trị băm GNU Hash (DJB2: khởi tạo 5381, h = h * 33 + c).
 */
uint32_t ComputeElfGnuHash(const char* symbol_name) noexcept;

/**
 * @brief Computes SysV ELF Hash (0x008ab4..0x008adc & 0x00aab4..0x00aad0).
 *        Tính giá trị băm SysV ELF Hash.
 */
uint32_t ComputeElfSysvHash(const char* symbol_name) noexcept;

/**
 * @brief Opens an ELF library for symbol resolution (0x008508..0x008824).
 *        Mở thư viện ELF để phân giải ký hiệu (0x008508..0x008824).
 */
ElfSymbolHandle* SliverDlOpen(const char* filename, int32_t flags = 0);

/**
 * @brief Closes an ElfSymbolHandle and frees all buffers (0x008948..0x008988).
 *        Đóng ElfSymbolHandle và giải phóng toàn bộ bộ đệm (0x008948..0x008988).
 */
void SliverDlClose(ElfSymbolHandle* handle) noexcept;

/**
 * @brief Resolves a symbol from .dynsym (via DT_GNU_HASH / DT_HASH) or .symtab/.gnu_debugdata (0x00898c..0x009310).
 *        Phân giải ký hiệu từ .dynsym hoặc .symtab/.gnu_debugdata (0x00898c..0x009310).
 */
void* SliverDlSym(ElfSymbolHandle* handle, const char* symbol_name);

/**
 * @brief Reads Android API level via __system_property_get("ro.build.version.sdk") or /system/build.prop (0x0098cc..0x0099f4).
 *        Đọc cấp độ API Android qua __system_property_get("ro.build.version.sdk") hoặc /system/build.prop.
 */
int32_t GetAndroidSdkLevel() noexcept;

/**
 * @brief Decodes a signed SLEB128 integer from an Android packed relocation stream (APS2) (0x00b528..0x00b58c).
 *        Giải mã số nguyên có dấu SLEB128 từ luồng định vị lại nén của Android (APS2) (0x00b528..0x00b58c).
 */
int32_t DecodeSignedLeb128(const uint8_t** cursor, const uint8_t* end, int64_t* out_value) noexcept;

/**
 * @brief Validates an AArch64 ELF64 header (0x00b0f4..0x00b164).
 *        Xác thực tiêu đề ELF64 kiến trúc AArch64 (0x00b0f4..0x00b164).
 */
int32_t ValidateAArch64ElfHeader(const Elf64_Ehdr* ehdr) noexcept;

/**
 * @brief Flushes AArch64 data cache (dc cvau) and instruction cache (ic ivau) (0x00f800..0x00f878).
 *        Làm sạch bộ nhớ đệm dữ liệu (dc cvau) và bộ nhớ đệm lệnh (ic ivau) trên AArch64 (0x00f800..0x00f878).
 */
void FlushAArch64InstructionCache(uintptr_t start_addr, uintptr_t end_addr) noexcept;

// ============================================================================
// 4. Exported xHook C APIs (.dynsym [100..106])
// ============================================================================

extern "C" {

int xhook_register(const char* pathname_regex_str,
                   const char* symbol,
                   void* new_func,
                   void** old_func);

int xhook_ignore(const char* pathname_regex_str,
                 const char* symbol);

int xhook_refresh(int async);

void xhook_clear();

void xhook_enable_debug(int flag);

void xhook_enable_sigsegv_protection(int flag);

} // extern "C"

} // namespace sliver
} // namespace bytedance
