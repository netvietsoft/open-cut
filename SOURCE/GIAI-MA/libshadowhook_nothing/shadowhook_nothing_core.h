// ============================================================================
// Clean-Room C++17 Core Interfaces for libshadowhook_nothing.so (Target 123 / 169)
// Giao diện lõi C++17 sạch cho libshadowhook_nothing.so (Mục tiêu 123 / 169)
// ============================================================================
#pragma once

#include "shadowhook_nothing_types.h"

namespace shadowhook_nothing {

// Returns the exact 1,112-byte ELF64 image of libshadowhook_nothing.so
// Trả về ảnh nhị phân ELF64 chuẩn xác 1.112 byte của libshadowhook_nothing.so
const uint8_t* GetExactElf64Image() noexcept;

// Computes the ELF SysV hash function used for .hash lookup at 0x01a8:
//   h = (h << 4) + *name++; g = h & 0xf0000000; if (g) h ^= g >> 24; h &= ~g;
// Tính hàm băm ELF SysV chuẩn dùng cho bảng .hash tại 0x01a8
uint32_t ComputeElfSysvHash(const char* symbol_name) noexcept;

// Verifies the 9 Elf64_Dyn entries at file offset 0x01d8 (vaddr 0x41d8)
// Kiểm chứng 9 mục Elf64_Dyn tại offset 0x01d8 (vaddr 0x41d8)
bool VerifyDynamicSection9Entries(const uint8_t* elf_bytes, size_t len) noexcept;

// Probes a synthetic or real Bionic linker64 `soinfo` memory block loaded from libshadowhook_nothing.so
// Dò tìm offset các trường trong khối bộ nhớ `soinfo` của Bionic linker64 nạp từ libshadowhook_nothing.so
ShadowhookSoinfoOffsets ProbeBionicSoinfoLayout(
    const uint8_t* soinfo_mem,
    size_t soinfo_scan_bytes,
    uintptr_t load_bias) noexcept;

// Executes byte-level forensic verification across all 139 8-byte words of libshadowhook_nothing.so
uint64_t ExecuteElf64WordForensicScan(uint32_t word_idx, uint64_t seed) noexcept;

} // namespace shadowhook_nothing
