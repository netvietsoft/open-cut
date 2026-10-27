// ============================================================================
// Clean-Room C++17 Core Implementation for libshadowhook_nothing.so (Target 123 / 169)
// Hiện thực hóa lõi C++17 sạch cho libshadowhook_nothing.so (Mục tiêu 123 / 169)
// ============================================================================
#include "shadowhook_nothing_core.h"

namespace shadowhook_nothing {

// Standard SVR4 / ELF64 SysV Hash Function:
//   uint32_t h = 0, g;
//   while (*name) {
//       h = (h << 4) + static_cast<uint8_t>(*name++);
//       if ((g = (h & 0xF0000000U)) != 0) h ^= (g >> 24);
//       h &= ~g;
//   }
// Hàm băm SVR4 / ELF64 SysV tiêu chuẩn phục vụ tra cứu bảng .hash tại 0x0001a8
uint32_t ComputeElfSysvHash(const char* symbol_name) noexcept {
    if (!symbol_name) return 0U;
    uint32_t h = 0U;
    while (*symbol_name != '\0') {
        h = (h << 4U) + static_cast<uint8_t>(*symbol_name++);
        uint32_t g = h & 0xF0000000U;
        if (g != 0U) {
            h ^= (g >> 24U);
        }
        h &= ~g;
    }
    return h;
}

// Reconstructed verification of the 9-entry .dynamic section at 0x0001d8..0x000268 (vaddr 0x0041d8):
//   [0] DT_SONAME  (0x0000000e) = 0x00000001 ("libshadowhook_nothing.so")
//   [1] DT_FLAGS   (0x0000001e) = 0x00000008 (DF_BIND_NOW)
//   [2] DT_FLAGS_1 (0x6ffffffb) = 0x00000001 (DF_1_NOW)
//   [3] DT_SYMTAB  (0x00000006) = 0x00000190
//   [4] DT_SYMENT  (0x0000000b) = 0x00000018 (24 bytes)
//   [5] DT_STRTAB  (0x00000005) = 0x000001b8
//   [6] DT_STRSZ   (0x0000000a) = 0x0000001a (26 bytes)
//   [7] DT_HASH    (0x00000004) = 0x000001a8
//   [8] DT_NULL    (0x00000000) = 0x00000000
bool VerifyDynamicSection9Entries(const uint8_t* elf_bytes, size_t len) noexcept {
    if (!elf_bytes || len < kShadowhookNothingBinarySize) {
        return false;
    }
    const auto* dyn = reinterpret_cast<const Elf64DynEntry*>(elf_bytes + kOffDynamic);
    return dyn[0].d_tag == kDtSoname && dyn[0].d_un == 0x01ULL &&
           dyn[1].d_tag == kDtFlags  && dyn[1].d_un == 0x08ULL &&
           dyn[2].d_tag == kDtFlags1 && dyn[2].d_un == 0x01ULL &&
           dyn[3].d_tag == kDtSymtab && dyn[3].d_un == kOffDynsym &&
           dyn[4].d_tag == kDtSyment && dyn[4].d_un == 24ULL &&
           dyn[5].d_tag == kDtStrtab && dyn[5].d_un == kOffDynstr &&
           dyn[6].d_tag == kDtStrsz  && dyn[6].d_un == 26ULL &&
           dyn[7].d_tag == kDtHash   && dyn[7].d_un == kOffSysvHash &&
           dyn[8].d_tag == kDtNull   && dyn[8].d_un == 0ULL;
}

} // namespace shadowhook_nothing
