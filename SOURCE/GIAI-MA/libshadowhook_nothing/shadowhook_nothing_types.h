// ============================================================================
// Clean-Room C++17 ELF64 & ShadowHook soinfo Probe Types for libshadowhook_nothing.so
// Định nghĩa kiểu dữ liệu ELF64 & bộ dò soinfo ShadowHook cho libshadowhook_nothing.so
// Binary: 1,112 bytes | SHA-256: f2cc6a6f94d7361be915daafff1d25b7b3af34972e7308ac540982cfd608bd32
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <array>

namespace shadowhook_nothing {

constexpr size_t kShadowhookNothingBinarySize = 1112; // 0x0458 bytes

// Exact ELF64 offsets and virtual addresses in libshadowhook_nothing.so:
// Địa chỉ ảo và offset tệp chuẩn xác trong libshadowhook_nothing.so:
constexpr uint64_t kOffElfEhdr    = 0x000000;
constexpr uint64_t kOffElfPhdr    = 0x000040; // 5 * 56 = 280 bytes (0x0040..0x0158)
constexpr uint64_t kOffDynsym     = 0x000190; // 24 bytes (1 STN_UNDEF symbol)
constexpr uint64_t kOffSysvHash   = 0x0001A8; // 16 bytes (nbucket=1, nchain=1, bucket[0]=0, chain[0]=0)
constexpr uint64_t kOffDynstr     = 0x0001B8; // 26 bytes ("\0libshadowhook_nothing.so\0")
constexpr uint64_t kOffDynamic    = 0x0001D8; // 144 bytes (9 * 16-byte Elf64_Dyn entries)
constexpr uint64_t kVaddrDynamic  = 0x0041D8; // PT_DYNAMIC vaddr = 0x41d8
constexpr uint64_t kOffShstrtab   = 0x000268; // 48 bytes
constexpr uint64_t kOffElfShdr    = 0x000298; // 7 * 64 = 448 bytes (0x0298..0x0458)

// Dynamic Tag Constants observed at 0x01d8..0x0268:
constexpr int64_t kDtNull    = 0x00000000;
constexpr int64_t kDtHash    = 0x00000004; // d_val = 0x000001A8
constexpr int64_t kDtStrtab  = 0x00000005; // d_val = 0x000001B8
constexpr int64_t kDtSymtab  = 0x00000006; // d_val = 0x00000190
constexpr int64_t kDtStrsz   = 0x0000000A; // d_val = 0x0000001A (26)
constexpr int64_t kDtSyment  = 0x0000000B; // d_val = 0x00000018 (24)
constexpr int64_t kDtSoname  = 0x0000000E; // d_val = 0x00000001 ("libshadowhook_nothing.so")
constexpr int64_t kDtFlags   = 0x0000001E; // d_val = 0x00000008 (DF_BIND_NOW)
constexpr int64_t kDtFlags1  = 0x6FFFFFFB; // d_val = 0x00000001 (DF_1_NOW)

struct Elf64DynEntry {
    int64_t d_tag;
    uint64_t d_un;
};

struct SysvHashHeader {
    uint32_t nbucket;
    uint32_t nchain;
    uint32_t bucket0;
    uint32_t chain0;
};

// Discovered Bionic linker64 `soinfo` field offsets probed via libshadowhook_nothing.so
// Các offset trường cấu trúc `soinfo` của Bionic linker64 được dò thông qua libshadowhook_nothing.so
struct ShadowhookSoinfoOffsets {
    size_t phdr_off{0};
    size_t phnum_off{0};
    size_t base_off{0};
    size_t size_off{0};
    size_t dynamic_off{0};
    size_t next_off{0};
    size_t strtab_off{0};
    size_t symtab_off{0};
    size_t nbucket_off{0};
    size_t nchain_off{0};
    size_t load_bias_off{0};
    bool valid{false};
};

} // namespace shadowhook_nothing
