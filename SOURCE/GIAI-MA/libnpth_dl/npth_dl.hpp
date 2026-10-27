/**
 * @file npth_dl.hpp
 * @brief Clean-room C++17 Reconstruction of ByteDance Npth Dynamic Linker & XZ-Debuginfo Resolver (`libnpth_dl.so`).
 *        Tái cấu trúc sạch C++17 của Bộ liên kết động Npth & Bộ giải mã ký hiệu XZ-Debuginfo (`libnpth_dl.so`).
 *
 * Binary Metadata / Siêu dữ liệu nhị phân:
 *   - File Size / Dung lượng: 27,352 bytes
 *   - SHA-256: 6e8562b698541ea8c948e0cf3335b08d195a9bac2795279aeb7540f31480df63
 *   - Architecture / Kiến trúc: AArch64 (ARM64-v8a, BTI-enabled)
 *   - .rodata:       0x0014d0..0x001978 (1,192 bytes)
 *   - .eh_frame_hdr: 0x001978..0x001b8c (532 bytes, 65 FDEs)
 *   - .eh_frame:     0x001b90..0x002600 (2,672 bytes)
 *   - .text:         0x002600..0x005c14 (13,844 bytes, 3,461 AArch64 instructions)
 *   - .plt:          0x005c20..0x005f10 (752 bytes, 188 AArch64 instructions)
 *   - .data.rel.ro:  0x009f10..0x009f60 (80 bytes, file offset 0x005f10)
 *   - .fini_array:   0x009f60..0x009f70 (16 bytes, file offset 0x005f60)
 *   - .data:         0x00e2b8..0x00e2e0 (40 bytes, file offset 0x0062b8)
 *   - .bss:          0x00e2e0..0x00e3d0 (240 bytes, file offset 0x0062e0)
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>

namespace nextai::opencut::npth_dl {

/**
 * @brief ELF64 Program Header (`Elf64_Phdr`, 56 bytes = 0x38 stride @ 0x26d4, 0x295c, 0x36e8, 0x4120).
 *        Tiêu đề chương trình ELF64 (`Elf64_Phdr`, kích thước 56 byte = 0x38).
 */
struct Elf64Phdr {
    uint32_t p_type;    // +0x00: PT_LOAD=1, PT_DYNAMIC=2, PT_NOTE=4
    uint32_t p_flags;   // +0x04: PF_X=1, PF_W=2, PF_R=4 (PF_R|PF_W == 6 @ 0x4144)
    uint64_t p_offset;  // +0x08: Segment file offset
    uint64_t p_vaddr;   // +0x10: Segment virtual address
    uint64_t p_paddr;   // +0x18: Segment physical address
    uint64_t p_filesz;  // +0x20: Segment size in file
    uint64_t p_memsz;   // +0x28: Segment size in memory
    uint64_t p_align;   // +0x30: Segment alignment
};
static_assert(sizeof(Elf64Phdr) == 0x38, "Elf64Phdr must be 0x38 (56) bytes");

/**
 * @brief ELF64 Section Header (`Elf64_Shdr`, 64 bytes = 0x40 stride @ 0x34d8, 0x4a90).
 *        Tiêu đề phân đoạn ELF64 (`Elf64_Shdr`, kích thước 64 byte = 0x40).
 */
struct Elf64Shdr {
    uint32_t sh_name;       // +0x00: Section name (.shstrtab index)
    uint32_t sh_type;       // +0x04: SHT_PROGBITS=1, SHT_SYMTAB=2, SHT_STRTAB=3, SHT_NOTE=7
    uint64_t sh_flags;      // +0x08: Section flags
    uint64_t sh_addr;       // +0x10: Section virtual address
    uint64_t sh_offset;     // +0x18: Section file offset
    uint64_t sh_size;       // +0x20: Section size in bytes
    uint32_t sh_link;       // +0x28: Link to another section
    uint32_t sh_info;       // +0x2c: Additional section information
    uint64_t sh_addralign;  // +0x30: Section alignment
    uint64_t sh_entsize;    // +0x38: Entry size if section holds table
};
static_assert(sizeof(Elf64Shdr) == 0x40, "Elf64Shdr must be 0x40 (64) bytes");

/**
 * @brief ELF64 Symbol Table Entry (`Elf64_Sym`, 24 bytes = 0x18 stride @ 0x43c0, 0x446c, 0x47b8, 0x48bc).
 *        Bản ghi bảng ký hiệu ELF64 (`Elf64_Sym`, kích thước 24 byte = 0x18).
 */
struct Elf64Sym {
    uint32_t st_name;   // +0x00: Symbol name (.strtab/.dynstr offset)
    uint8_t  st_info;   // +0x04: Type & binding (low 4 bits: STT_OBJECT=1, STT_FUNC=2, STT_TLS=6, STT_GNU_IFUNC=10)
    uint8_t  st_other;  // +0x05: Symbol visibility
    uint16_t st_shndx;  // +0x06: Section index (SHN_UNDEF == 0 checked @ 0x440c, 0x47dc, 0x48c8)
    uint64_t st_value;  // +0x08: Symbol value / virtual address offset
    uint64_t st_size;   // +0x10: Symbol size in bytes
};
static_assert(sizeof(Elf64Sym) == 0x18, "Elf64Sym must be 0x18 (24) bytes");

/**
 * @brief ELF64 Relocation Entry with Addend (`Elf64_Rela`, 24 bytes = 0x18 stride @ 0x46f0, 0x4704).
 *        Bản ghi định vị lại ELF64 (`Elf64_Rela`, kích thước 24 byte = 0x18).
 */
struct Elf64Rela {
    uint64_t r_offset;  // +0x00: Relocation virtual address offset
    uint64_t r_info;    // +0x08: Low 32 bits = type (R_AARCH64_JUMP_SLOT = 0x402 @ 0x4714), High 32 bits = sym index
    int64_t  r_addend;  // +0x10: Constant addend
};
static_assert(sizeof(Elf64Rela) == 0x18, "Elf64Rela must be 0x18 (24) bytes");

/**
 * @brief Dynamic Symbol & Relocation Context (`0x88` = 136 bytes allocated via `calloc(1, 0x88)` @ 0x44e0).
 *        Ngữ cảnh bảng ký hiệu động & định vị lại (`0x88` = 136 byte cấp phát qua `calloc(1, 0x88)` @ 0x44e0).
 */
struct NpthDynSymCtx {
    const Elf64Sym*  dynsym;          // +0x00: DT_SYMTAB (6) + load_bias
    const char*      dynstr;          // +0x08: DT_STRTAB (5) + load_bias
    const void*      pltrel_or_rel;   // +0x10: DT_REL (17) + load_bias
    const Elf64Rela* jmprel;          // +0x18: DT_JMPREL (23) + load_bias
    uint64_t         pltrel_type;     // +0x20: DT_PLTREL (20)
    uint64_t         rela_count;      // +0x28: DT_RELASZ (8) / 24 (via umulh 0xaaaaaaaaaaaaaaab >> 4 @ 0x4674)
    uint64_t         jmprel_count;    // +0x30: DT_PLTRELSZ (2) / 24 (via umulh 0xaaaaaaaaaaaaaaab >> 4 @ 0x4604)
    uint64_t         hash_flags;      // +0x38: bit 0 = has SysV .hash (1), bit 1 = has .gnu.hash (2)
    uint64_t         gnu_nbuckets;    // +0x40: .gnu.hash nbuckets
    const uint32_t*  gnu_buckets;     // +0x48: .gnu.hash buckets array
    const uint32_t*  gnu_chains;      // +0x50: .gnu.hash chains base (adjusted by -symoffset)
    uint32_t         gnu_maskwords;   // +0x58: .gnu.hash maskwords - 1 (bitmask)
    uint32_t         gnu_shift2;      // +0x5c: .gnu.hash shift2
    const uint64_t*  gnu_bloom;       // +0x60: .gnu.hash 64-bit bloom filter array
    uint64_t         sysv_nbuckets;   // +0x68: SysV .hash nbuckets
    uint64_t         sysv_nchains;    // +0x70: SysV .hash nchains
    const uint32_t*  sysv_buckets;    // +0x78: SysV .hash buckets array
    const uint32_t*  sysv_chains;     // +0x80: SysV .hash chains array
};
static_assert(sizeof(NpthDynSymCtx) == 0x88, "NpthDynSymCtx must be 0x88 (136) bytes");

/**
 * @brief Static Symbol Table Context (`0x20` = 32 bytes allocated via `malloc(0x20)` @ 0x4930).
 *        Ngữ cảnh bảng ký hiệu tĩnh `.symtab` / `.gnu_debugdata` (`0x20` = 32 byte cấp phát tại `0x4930`).
 */
struct NpthSymtabCtx {
    Elf64Sym* symtab;       // +0x00: Heap-allocated copy of .symtab
    char*     strtab;       // +0x08: Heap-allocated copy of .strtab
    uint64_t  sym_count;    // +0x10: sh_size / sh_entsize (@ 0x4cd4)
    uint64_t  strtab_size;  // +0x18: .strtab sh_size (@ 0x4ce0)
};
static_assert(sizeof(NpthSymtabCtx) == 0x20, "NpthSymtabCtx must be 0x20 (32) bytes");

/**
 * @brief Npth Dynamic Library Handle (`0x40` = 64 bytes allocated via `calloc(1, 0x40)` @ 0x26b8, 0x2730, 0x27b0).
 *        Cấu trúc quản lý thư viện động Npth (`0x40` = 64 byte cấp phát tại `0x26b8`, `0x2730`, `0x27b0`).
 */
struct NpthDlHandle {
    const char*      pathname;    // +0x00: Requested library name or ELF base for pseudo-handles 1/2
    uintptr_t        load_bias;   // +0x08: ELF load bias (dlpi_addr)
    char*            realpath;    // +0x10: Resolved full path (strdup'd or /proc/self/maps resolved)
    uintptr_t        min_vaddr;   // +0x18: Minimum PT_LOAD virtual address + dlpi_addr
    const Elf64Phdr* phdr;        // +0x20: Pointer to Elf64_Phdr array
    uint64_t         phnum;       // +0x28: Number of program headers (e_phnum / dlpi_phnum)
    NpthDynSymCtx*   dynsym_ctx;  // +0x30: Lazily initialized PT_DYNAMIC context
    NpthSymtabCtx*   symtab_ctx;  // +0x38: Lazily initialized .symtab / .gnu_debugdata context
};
static_assert(sizeof(NpthDlHandle) == 0x40, "NpthDlHandle must be 0x40 (64) bytes");

/**
 * @brief Standard `dl_phdr_info` structure passed to `dl_iterate_phdr` callbacks (`0x40` = 64 bytes @ 0x3f1c).
 *        Cấu trúc `dl_phdr_info` chuẩn truyền cho hàm gọi lại `dl_iterate_phdr` (`0x40` = 64 byte @ 0x3f1c).
 */
struct DlPhdrInfo {
    uintptr_t        dlpi_addr;   // +0x00: Module load bias
    const char*      dlpi_name;   // +0x08: Module pathname
    const Elf64Phdr* dlpi_phdr;   // +0x10: Pointer to module's Phdr array
    uint16_t         dlpi_phnum;  // +0x18: Number of Phdr entries
    uint16_t         _pad[3];
    uint64_t         dlpi_adds;   // +0x20
    uint64_t         dlpi_subs;   // +0x28
    size_t           dlpi_tls_modid; // +0x30
    void*            dlpi_tls_data;  // +0x38
};
static_assert(sizeof(DlPhdrInfo) == 0x40, "DlPhdrInfo must be 0x40 (64) bytes");

/**
 * @brief Standard `Dl_info` structure for `npth_dladdr` (`0x2e4c`).
 *        Cấu trúc `Dl_info` chuẩn dùng trong `npth_dladdr` (`0x2e4c`).
 */
struct DlInfo {
    const char* dli_fname;  // +0x00: Pathname of shared object
    void*       dli_fbase;  // +0x08: Base address of shared object
    const char* dli_sname;  // +0x10: Name of nearest symbol
    void*       dli_saddr;  // +0x18: Exact address of nearest symbol
};

// Internal functions across translation units / Các hàm nội bộ liên kết giữa các phân hệ
NpthDynSymCtx* ParseDynamicPhdr(const Elf64Phdr* phdr, uint64_t phnum, uintptr_t load_bias) noexcept;
void FreeDynSymCtx(NpthDynSymCtx* ctx) noexcept;
const Elf64Sym* LookupDynSym(const NpthDynSymCtx* ctx, const char* sym_name) noexcept;
uintptr_t LookupJumpSlotReloc(const NpthDynSymCtx* ctx, const char* sym_name) noexcept;

NpthSymtabCtx* LoadSymtabOrDebugdata(const char* filepath, const uint8_t* elf_base) noexcept;
void FreeSymtabCtx(NpthSymtabCtx* ctx) noexcept;
const Elf64Sym* LookupSymtabByName(const NpthSymtabCtx* ctx, const char* sym_name, int prefix_match) noexcept;
const Elf64Sym* LookupSymtabByAddr(const NpthSymtabCtx* ctx, uintptr_t offset) noexcept;
const char* GetSymtabString(const NpthSymtabCtx* ctx, const Elf64Sym* sym) noexcept;

char* ResolvePathByNameFromMaps(const char* soname) noexcept;
char* ResolvePathByAddrFromMaps(uintptr_t base_addr) noexcept;
int ParseDecimalSdkInt(const char* str) noexcept;
int ReadExactAtOffset(int fd, uint64_t offset, void* buf, size_t size) noexcept;

using DlIteratePhdrCallback = int (*)(DlPhdrInfo* info, size_t size, void* data);
using DlIteratePhdrFn = int (*)(DlIteratePhdrCallback cb, void* data);
DlIteratePhdrFn ResolveDlIteratePhdrWrapper() noexcept;

} // namespace nextai::opencut::npth_dl

extern "C" {

// 22 Exported Symbols in .dynsym ([39]..[60]) / 22 ký hiệu xuất khẩu trong .dynsym ([39]..[60])
void* npth_dlopen(const char* pathname);
int   npth_dliterater(nextai::opencut::npth_dl::DlIteratePhdrCallback cb, void* data);
void* npth_dlsym_size(void* handle, const char* symbol, size_t* size_out);
void* npth_dlsym(void* handle, const char* symbol);
void* npth_dlrel_plt_got(void* handle, const char* symbol);
void* npth_dlsym_symtab_size(void* handle, const char* symbol, size_t* size_out);
void* npth_dlsym_symtab(void* handle, const char* symbol);
void* npth_dlsym_symtab_prefix(void* handle, const char* symbol);
void* npth_dlsym_symtab_size_prefix(void* handle, const char* symbol, size_t* size_out);
int   npth_dlclose(void* handle);
void* npth_dlopen_force(const char* pathname);
void* npth_dlsym_force(void* handle, const char* symbol);
int   npth_dlclose_force(void* handle);
int   npth_dladdr(const void* addr, nextai::opencut::npth_dl::DlInfo* info);
char* npth_dlerror(void);
int   npth_dlusable(int mode);
int   npth_dlapilevel(void);
char* npth_dlbuildid(const char* pathname);
int   npth_dllzma_decompress(const uint8_t* src, size_t src_len, uint8_t** dst_out, size_t* dst_len_out);
int   npth_dltest(void);
void  npth_dldebug(int enable);
void  npth_dlincrease(int target_api_level);

} // extern "C"
