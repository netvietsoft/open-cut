// ============================================================================
// File: tttext_lite_interface.h
// Target: libtttext_lite.so (297,312 bytes, SHA-256: 8860b2ff8bdd...60282e)
// Clean-Room C++17 Reconstruction — Public C/C++ Engine Interface & Opcode Registry
// Tái cấu trúc phòng sạch C++17 — Giao diện C/C++ công khai & Sổ đăng ký Opcode
// ============================================================================
#pragma once

#include "tttext_lite_types.h"
#include "tttext_lite_rodata_tables.h"
#include "tttext_lite_icu_and_harfbuzz.h"
#include "tttext_lite_shaper_and_layout.h"
#include <cstdint>
#include <cstddef>

namespace ttoffice {
namespace tttext {

struct VerifiedOpcodeEntry {
    uint32_t vaddr;
    uint32_t opcode_u32;
    const char* mnemonic;
    const char* operands;
    const char* group;
};

struct ExportedSymbolEntry {
    uint32_t vaddr;
    uint32_t size;
    const char* mangled_name;
};

// Returns the verified AArch64 instruction table extracted from .text (0x014000..0x04014c)
const VerifiedOpcodeEntry* GetVerifiedOpcodeTable(size_t* out_count) noexcept;

// Looks up an exact 32-bit AArch64 instruction word by virtual address
uint32_t LookupVerifiedOpcode(uint32_t vaddr) noexcept;

// Returns the 434 exported ELF symbols of libtttext_lite.so
const ExportedSymbolEntry* GetExportedSymbolTable(size_t* out_count) noexcept;

// Runs the self-contained mathematical & ABI verification suite on libtttext_lite
bool RunSelfVerificationSuite() noexcept;

} // namespace tttext
} // namespace ttoffice

extern "C" {

// Exported JNI & C ABI entrypoints reconstructed from .dynsym (0x01a5b8 .. 0x01a824)
int32_t tttext_lite_JNI_OnLoad(uint64_t vm_handle, void* reserved) noexcept;
void tttext_lite_Java_com_lynx_textra_TTText_nativeInitialCache(void* env, void* clazz) noexcept;
uint64_t tttext_lite_TTTextNativeGetDefaultFontManager(void* env, void* clazz) noexcept;
void tttext_lite_JavaFontManagerBindNativeInstance(void* env, void* obj, int64_t native_ptr, void* jfont_mgr) noexcept;
int64_t tttext_lite_JavaFontManagerCreateNativeTypeface(void* env, void* obj, int64_t native_ptr) noexcept;
void tttext_lite_JavaTypefaceBindNativeInstance(void* env, void* obj, int64_t native_ptr, void* jtypeface, int32_t index) noexcept;

} // extern "C"
