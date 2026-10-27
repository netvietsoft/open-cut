/**
 * @file npth_dl_symtab.cpp
 * @brief ELF64 `.dynsym` (GNU Hash + SysV Hash), `.symtab`, `.gnu_debugdata` XZ Unpacker & `.note.gnu.build-id` Parser.
 *        Bộ phân tích `.dynsym` (GNU Hash + SysV Hash), `.symtab`, giải nén XZ `.gnu_debugdata` & `.note.gnu.build-id`.
 *
 * Covers `.text` functions:
 *   - `0x329c..0x3354` (`npth_dlbuildid` entry, FDE[33], 184 B)
 *   - `0x3354..0x3648` (`ReadBuildIdFromElfFile`, FDE[34], 756 B)
 *   - `0x3648..0x3848` (`DlIterateBuildIdCallback`, FDE[35], 512 B)
 *   - `0x3848..0x38c0` (`FormatHexByte`, FDE[36], 120 B)
 *   - `0x38c0..0x394c` (`SeekAndReadLog`, FDE[37], 140 B)
 *   - `0x4328..0x44b8` (`LookupDynSym`, FDE[42], 400 B)
 *   - `0x44b8..0x44c4` (`FreeDynSymCtx`, FDE[43], 12 B)
 *   - `0x44c4..0x46c4` (`ParseDynamicPhdr`, FDE[44], 512 B)
 *   - `0x46c4..0x4760` (`LookupJumpSlotReloc`, FDE[45], 156 B)
 *   - `0x4760..0x4898` (`LookupSymtabByName`, FDE[46], 312 B)
 *   - `0x4898..0x48a8` (`GetSymtabString`, FDE[47], 16 B)
 *   - `0x48a8..0x490c` (`LookupSymtabByAddr`, FDE[48], 100 B)
 *   - `0x490c..0x4da0` (`LoadSymtabOrDebugdata`, FDE[49], 1,172 B)
 *   - `0x4da0..0x4e08` (`ReadExactAtOffset`, FDE[50], 104 B)
 *   - `0x4e08..0x4e48` (`FreeSymtabCtx`, FDE[51], 64 B)
 *   - `0x5858..0x5b54` (`npth_dllzma_decompress` internal body, FDE[57], 764 B)
 */

#include "npth_dl.hpp"
#include <vector>
#include <algorithm>

#if defined(__linux__) || defined(__ANDROID__)
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>
#endif

namespace nextai::opencut::npth_dl {

namespace {

/**
 * @brief Counts set bits in a 32-bit unsigned integer (`cnt v0.8b; uaddlv h0, v0.8b` @ 0x45d0..0x45dc).
 *        Đếm số bit 1 trong số nguyên 32-bit không dấu (`cnt v0.8b; uaddlv h0, v0.8b` @ 0x45d0..0x45dc).
 */
inline uint32_t PopCount32(uint32_t x) noexcept {
    x = x - ((x >> 1) & 0x55555555U);
    x = (x & 0x33333333U) + ((x >> 2) & 0x33333333U);
    return (((x + (x >> 4)) & 0x0F0F0F0FU) * 0x01010101U) >> 24;
}

/**
 * @brief Computes GNU Hash (DJB2 with seed `0x1505`, `h = h * 33 + c` @ 0x4360..0x4378).
 *        Tính giá trị băm GNU Hash (DJB2 với hạt giống `0x1505`, `h = h * 33 + c` @ 0x4360..0x4378).
 */
inline uint32_t ComputeGnuHash(const char* name) noexcept {
    uint32_t h = 0x1505U; // mov w22, #0x1505 @ 0x4360
    const uint8_t* p = reinterpret_cast<const uint8_t*>(name);
    while (*p != 0) {
        h = (h + (h << 5)) + (*p++); // add w10, w22, w22, lsl #5; add w22, w10, w8 @ 0x4364..0x4368
    }
    return h;
}

/**
 * @brief Computes SysV ELF Hash (`0x4420..0x444c`).
 *        Tính giá trị băm SysV ELF Hash (`0x4420..0x444c`).
 */
inline uint32_t ComputeSysvHash(const char* name) noexcept {
    uint32_t h = 0;
    const uint8_t* p = reinterpret_cast<const uint8_t*>(name);
    while (*p != 0) {
        h = (h << 4) + (*p++);               // add w8, w10, w8, lsl #4 @ 0x4430
        uint32_t low28 = h & 0x0fffffffU;    // and w11, w8, #0xfffffff @ 0x4434
        uint32_t high4 = h >> 28;            // lsr w8, w8, #0x1c @ 0x4438
        h = low28 ^ (high4 << 4);            // eor w8, w11, w8, lsl #4 @ 0x4440
    }
    return h;
}

/**
 * @brief Jump-table offsets in `.rodata` at `0x1949` (`DT_PLTRELSZ=2..DT_JMPREL=23` @ 0x454c..0x457c).
 *        Bảng nhảy trong `.rodata` tại `0x1949` dùng để phân tích các thẻ `DT_*` trong `PT_DYNAMIC`.
 */
constexpr uint64_t kDtPltRelSz = 2;
constexpr uint64_t kDtHash     = 4;
constexpr uint64_t kDtStrTab   = 5;
constexpr uint64_t kDtSymTab   = 6;
constexpr uint64_t kDtRela     = 7;
constexpr uint64_t kDtRelaSz   = 8;
constexpr uint64_t kDtRelaEnt  = 9;
constexpr uint64_t kDtRel      = 17;
constexpr uint64_t kDtPltRel   = 20;
constexpr uint64_t kDtJmpRel   = 23;
constexpr uint64_t kDtGnuHash  = 0x6ffffef5ULL; // mov w12, #0xfef5; movk w12, #0x6fff, lsl #16 @ 0x4528..0x4540

/**
 * @brief 64-bit magic multiplier `0xaaaaaaaaaaaaaaab` for unsigned division by 24 (`sizeof(Elf64_Rela)` @ 0x452c..0x4544).
 *        Hệ số nhân ma thuật 64-bit `0xaaaaaaaaaaaaaaab` để chia nguyên không dấu cho 24 (`sizeof(Elf64_Rela)`).
 */
inline uint64_t DivideBy24Magic(uint64_t bytes) noexcept {
    // umulh x15, x15, x13; lsr x15, x15, #4 @ 0x4604..0x4608, 0x4674..0x4678
    __uint128_t prod = static_cast<__uint128_t>(bytes) * static_cast<__uint128_t>(0xaaaaaaaaaaaaaaabULL);
    uint64_t high = static_cast<uint64_t>(prod >> 64);
    return high >> 4;
}

/**
 * @brief XZ Allocator callbacks (`0x5b54` `SzAlloc` -> `malloc(size)`, `0x5b5c` `SzFree` -> `free(address)`).
 *        Hàm cấp phát/giải phóng bộ nhớ cho bộ giải nén XZ (`0x5b54` & `0x5b5c` trong `.data.rel.ro` @ `0x9f50`).
 */
void* XzAllocCallback(void* /*p*/, size_t size) noexcept {
    return std::malloc(size); // mov x0, x1; b malloc @ 0x5b54..0x5b58
}

void XzFreeCallback(void* /*p*/, void* address) noexcept {
    std::free(address); // mov x0, x1; b free @ 0x5b5c..0x5b60
}

struct ISzAlloc {
    void* (*Alloc)(void* p, size_t size);
    void  (*Free)(void* p, void* address);
};

// Cached liblzma.so function pointers in .bss (0xe398..0xe3c8)
struct LzmaRuntimeTable {
    bool initialized;                                                                   // 0xe3c8
    void (*XzUnpacker_Construct)(void* p, const ISzAlloc* alloc);                       // 0xe398
    void (*XzUnpacker_Free)(void* p);                                                   // 0xe3a0
    int  (*XzUnpacker_Code_Pre28)(void* p, uint8_t* dest, size_t* destLen,
                                  const uint8_t* src, size_t* srcLen,
                                  int finishMode, int* status);                         // 0xe3a8 (API <= 28)
    int  (*XzUnpacker_Code_Api29)(void* p, uint8_t* dest, size_t* destLen,
                                  const uint8_t* src, size_t* srcLen,
                                  int srcFinished, int finishMode, int* status);        // 0xe3a8 (API > 28 @ 0x595c)
    int  (*XzUnpacker_IsStreamWasFinished)(const void* p);                              // 0xe3b0
    void (*CrcGenerateTable)(void);                                                     // 0xe3b8
    void (*Crc64GenerateTable)(void);                                                   // 0xe3c0
};

LzmaRuntimeTable g_lzma_table = {false, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

} // namespace

/**
 * @brief Parses `PT_DYNAMIC` segment and builds `NpthDynSymCtx` (`0x44c4..0x46c4`, FDE[44], 512 B).
 *        Phân tích phân đoạn `PT_DYNAMIC` và khởi tạo `NpthDynSymCtx` (`0x44c4..0x46c4`, FDE[44], 512 B).
 */
NpthDynSymCtx* ParseDynamicPhdr(const Elf64Phdr* phdr, uint64_t phnum, uintptr_t load_bias) noexcept {
    NpthDynSymCtx* ctx = static_cast<NpthDynSymCtx*>(std::calloc(1, sizeof(NpthDynSymCtx))); // 0x44e0: mov w1, #0x88
    if (!ctx) {
        return nullptr;
    }
    if (phnum < 1 || !phdr) {
        std::free(ctx);
        return nullptr;
    }

    const Elf64Phdr* dyn_phdr = nullptr;
    for (uint64_t i = 0; i < phnum; ++i) {
        if (phdr[i].p_type == 2U) { // PT_DYNAMIC == 2 @ 0x4504
            dyn_phdr = &phdr[i];
            break;
        }
    }
    if (!dyn_phdr || dyn_phdr->p_vaddr == 0) {
        std::free(ctx);
        return nullptr;
    }

    const uint64_t* dyn = reinterpret_cast<const uint64_t*>(load_bias + dyn_phdr->p_vaddr);
    uint64_t hash_flags = 0;
    const char* dynstr = nullptr;
    const Elf64Sym* dynsym = nullptr;

    for (; dyn[0] != 0; dyn += 2) {
        uint64_t tag = dyn[0];
        uint64_t val = dyn[1];
        if (tag <= 0x17ULL) {
            switch (tag) {
                case kDtPltRelSz: // 2 -> 0x4600
                    ctx->jmprel_count = DivideBy24Magic(val);
                    break;
                case kDtHash: { // 4 -> 0x4614
                    const uint32_t* h = reinterpret_cast<const uint32_t*>(load_bias + val);
                    uint32_t nbuckets = h[0];
                    uint32_t nchains  = h[1];
                    ctx->sysv_nbuckets = nbuckets;
                    ctx->sysv_nchains  = nchains;
                    ctx->sysv_buckets  = h + 2;
                    ctx->sysv_chains   = h + 2 + nbuckets;
                    hash_flags |= 1ULL;
                    ctx->hash_flags = hash_flags;
                    break;
                }
                case kDtStrTab: // 5 -> 0x4640
                    dynstr = reinterpret_cast<const char*>(load_bias + val);
                    ctx->dynstr = dynstr;
                    break;
                case kDtSymTab: // 6 -> 0x4650
                    dynsym = reinterpret_cast<const Elf64Sym*>(load_bias + val);
                    ctx->dynsym = dynsym;
                    break;
                case kDtRela: // 7 -> 0x4660
                    ctx->pltrel_or_rel = reinterpret_cast<const void*>(load_bias + val);
                    break;
                case kDtRelaSz: // 8 -> 0x4670
                    ctx->rela_count = DivideBy24Magic(val);
                    break;
                case kDtRelaEnt: // 9 -> 0x4580: must equal 0x18 (24)
                    if (val != 0x18ULL) {
                        std::free(ctx);
                        return nullptr;
                    }
                    break;
                case kDtRel: // 17 -> 0x4660
                    ctx->pltrel_or_rel = reinterpret_cast<const void*>(load_bias + val);
                    break;
                case kDtPltRel: // 20 -> 0x4684: must be DT_RELA (7) Checked at 0x4558
                    if (val != 7ULL) {
                        std::free(ctx);
                        return nullptr;
                    }
                    ctx->pltrel_type = val;
                    break;
                case kDtJmpRel: // 23 -> 0x4690
                    ctx->jmprel = reinterpret_cast<const Elf64Rela*>(load_bias + val);
                    break;
                default:
                    break;
            }
        } else if (tag == kDtGnuHash) { // 0x6ffffef5 @ 0x4590
            const uint32_t* gh = reinterpret_cast<const uint32_t*>(load_bias + val);
            uint32_t nbuckets  = gh[0];
            uint32_t symoffset = gh[1];
            uint32_t maskwords = gh[2];
            uint32_t shift2    = gh[3];
            const uint64_t* bloom = reinterpret_cast<const uint64_t*>(gh + 4);
            const uint32_t* buckets = reinterpret_cast<const uint32_t*>(bloom + maskwords);
            const uint32_t* chains  = buckets + nbuckets - symoffset;

            ctx->gnu_bloom     = bloom;
            ctx->gnu_maskwords = maskwords;
            ctx->gnu_shift2    = shift2;
            ctx->gnu_nbuckets  = nbuckets;
            ctx->gnu_buckets   = buckets;
            ctx->gnu_chains    = chains;

            // Power-of-two validation on maskwords (cnt v0.8b; uaddlv h0, v0.8b <= 1 @ 0x45cc..0x45e4)
            if (maskwords == 0 || PopCount32(maskwords) <= 1U) {
                ctx->gnu_maskwords = maskwords - 1U;
                hash_flags |= 2ULL;
                ctx->hash_flags = hash_flags;
            }
        }
    }

    if (hash_flags == 0 || !dynstr || !dynsym) { // 0x46a0..0x46a8
        std::free(ctx);
        return nullptr;
    }
    return ctx;
}

/**
 * @brief Frees `NpthDynSymCtx` (`0x44b8..0x44c4`, FDE[43], 12 B).
 *        Giải phóng `NpthDynSymCtx` (`0x44b8..0x44c4`, FDE[43], 12 B).
 */
void FreeDynSymCtx(NpthDynSymCtx* ctx) noexcept {
    if (ctx) {
        std::free(ctx);
    }
}

/**
 * @brief Looks up a symbol in `.dynsym` using `.gnu.hash` and/or SysV `.hash` (`0x4328..0x44b8`, FDE[42], 400 B).
 *        Tra cứu ký hiệu trong `.dynsym` bằng `.gnu.hash` và/hoặc SysV `.hash` (`0x4328..0x44b8`, FDE[42], 400 B).
 */
const Elf64Sym* LookupDynSym(const NpthDynSymCtx* ctx, const char* sym_name) noexcept {
    if (!ctx || !sym_name) {
        return nullptr;
    }

    // 1. Try .gnu.hash if bit 1 of hash_flags is set (tbz w21, #1, #0x441c @ 0x4350)
    if ((ctx->hash_flags & 2ULL) != 0 && ctx->gnu_nbuckets > 0) {
        uint32_t h1 = ComputeGnuHash(sym_name);
        uint32_t h2 = h1 >> ctx->gnu_shift2;
        uint64_t word_idx = (h1 >> 6) & ctx->gnu_maskwords;
        uint64_t bloom_word = ctx->gnu_bloom[word_idx];

        // 64-bit Bloom filter test (lsr x11, x9, x22; lsr x9, x9, x10; and w9, w11, w9 @ 0x4394..0x43a0)
        if (((bloom_word >> (h1 & 63U)) & (bloom_word >> (h2 & 63U)) & 1ULL) != 0) {
            uint32_t sym_idx = ctx->gnu_buckets[h1 % ctx->gnu_nbuckets];
            if (sym_idx != 0) {
                while (true) {
                    uint32_t chain_hash = ctx->gnu_chains[sym_idx];
                    // Compare top 31 bits of hash (eor w8, w27, w22; cmp w8, #1; b.hi @ 0x43d4..0x43dc)
                    if ((chain_hash ^ h1) <= 1U) {
                        const Elf64Sym* sym = &ctx->dynsym[sym_idx];
                        if (std::strcmp(ctx->dynstr + sym->st_name, sym_name) == 0) {
                            return (sym->st_shndx == 0) ? nullptr : sym; // ldrh w9, [x8, #6]; csel @ 0x440c..0x4414
                        }
                    }
                    if ((chain_hash & 1U) != 0) { // End of chain bit 0 (tbnz w27, #0, #0x441c @ 0x43cc)
                        break;
                    }
                    ++sym_idx;
                }
            }
        }
    }

    // 2. Fallback to SysV .hash if bit 0 of hash_flags is set (tbz w21, #0, #0x4498 @ 0x441c)
    if ((ctx->hash_flags & 1ULL) != 0 && ctx->sysv_nbuckets > 0) {
        uint32_t h = ComputeSysvHash(sym_name);
        uint32_t sym_idx = ctx->sysv_buckets[h % ctx->sysv_nbuckets];
        while (sym_idx != 0) {
            const Elf64Sym* sym = &ctx->dynsym[sym_idx];
            if (std::strcmp(ctx->dynstr + sym->st_name, sym_name) == 0) {
                return (sym->st_shndx == 0) ? nullptr : sym;
            }
            sym_idx = ctx->sysv_chains[sym_idx];
        }
    }

    return nullptr;
}

/**
 * @brief Scans `DT_JMPREL` for `R_AARCH64_JUMP_SLOT` (`0x402`) matching `sym_name` (`0x46c4..0x4760`, FDE[45], 156 B).
 *        Quét bảng `DT_JMPREL` tìm mục `R_AARCH64_JUMP_SLOT` (`0x402`) khớp với `sym_name` (`0x46c4..0x4760`).
 */
uintptr_t LookupJumpSlotReloc(const NpthDynSymCtx* ctx, const char* sym_name) noexcept {
    if (!ctx || !ctx->jmprel || ctx->jmprel_count < 1 || !sym_name) {
        return 0;
    }
    for (uint64_t i = 0; i < ctx->jmprel_count; ++i) {
        const Elf64Rela& rela = ctx->jmprel[i];
        if (static_cast<uint32_t>(rela.r_info) == 0x402U) { // R_AARCH64_JUMP_SLOT == 1026 (0x402) @ 0x4714
            uint32_t sym_idx = static_cast<uint32_t>(rela.r_info >> 32);
            const Elf64Sym& sym = ctx->dynsym[sym_idx];
            if (std::strcmp(sym_name, ctx->dynstr + sym.st_name) == 0) {
                return static_cast<uintptr_t>(rela.r_offset);
            }
        }
    }
    return 0;
}

/**
 * @brief Looks up a symbol in `.symtab` by exact name or compiler-clone `.` prefix (`0x4760..0x4898`, FDE[46], 312 B).
 *        Tra cứu ký hiệu trong `.symtab` theo tên chính xác hoặc tiền tố dấu chấm `.` (`0x4760..0x4898`, FDE[46], 312 B).
 */
const Elf64Sym* LookupSymtabByName(const NpthSymtabCtx* ctx, const char* sym_name, int prefix_match) noexcept {
    if (!ctx || !ctx->symtab || !ctx->strtab || ctx->sym_count == 0 || !sym_name) {
        return nullptr;
    }
    size_t target_len = std::strlen(sym_name);
    if (target_len + 1 < 2) { // cmp x25, #2; b.lo @ 0x47f8
        return nullptr;
    }

    for (uint64_t i = 0; i < ctx->sym_count; ++i) {
        const Elf64Sym* sym = &ctx->symtab[i];
        if (sym->st_shndx == 0) { // SHN_UNDEF @ 0x47dc
            continue;
        }
        if (sym->st_name >= ctx->strtab_size) { // cmp x8, x28; b.ls @ 0x47f0
            continue;
        }
        const char* candidate = ctx->strtab + sym->st_name;
        size_t cand_len = std::strlen(candidate);
        if (cand_len < target_len) {
            continue;
        }

        size_t k = 0;
        while (k < target_len && candidate[k] == sym_name[k]) {
            ++k;
        }
        if (k == target_len) {
            if (candidate[k] == '\0') {
                return sym;
            }
            // Compiler clone suffix check: `candidate[target_len] == '.'` (0x2e @ 0x4860) when prefix_match != 0
            if (prefix_match != 0 && candidate[k] == '.') {
                return sym;
            }
        }
    }
    return nullptr;
}

/**
 * @brief Resolves symbol string from `NpthSymtabCtx` (`0x4898..0x48a8`, FDE[47], 16 B).
 *        Lấy chuỗi tên ký hiệu từ `NpthSymtabCtx` (`0x4898..0x48a8`, FDE[47], 16 B).
 */
const char* GetSymtabString(const NpthSymtabCtx* ctx, const Elf64Sym* sym) noexcept {
    return ctx->strtab + sym->st_name;
}

/**
 * @brief Finds the `.symtab` symbol covering `offset` (`st_value <= offset < st_value + st_size`, `0x48a8..0x490c`, FDE[48], 100 B).
 *        Tìm ký hiệu `.symtab` chứa địa chỉ `offset` (`st_value <= offset < st_value + st_size`, `0x48a8..0x490c`).
 */
const Elf64Sym* LookupSymtabByAddr(const NpthSymtabCtx* ctx, uintptr_t offset) noexcept {
    if (!ctx || ctx->sym_count == 0 || !ctx->symtab) {
        return nullptr;
    }
    for (uint64_t i = 0; i < ctx->sym_count; ++i) {
        const Elf64Sym* sym = &ctx->symtab[i];
        if (sym->st_shndx == 0) {
            continue;
        }
        uint8_t type = sym->st_info & 0x0fU;
        // Excludes STT_SECTION (3) and STT_FILE (4): `sub w9, w9, #3; cmn w9, #2; b.lo` @ 0x48d8..0x48e0
        if (type == 3U || type == 4U) {
            continue;
        }
        if (offset >= sym->st_value && offset < sym->st_value + sym->st_size) {
            return sym;
        }
    }
    return nullptr;
}

/**
 * @brief Helper that `lseek`s and reads exact bytes from an ELF file descriptor (`0x4da0..0x4e08`, FDE[50], 104 B).
 *        Hàm phụ trợ `lseek` và đọc chính xác số byte từ file descriptor ELF (`0x4da0..0x4e08`, FDE[50], 104 B).
 */
int ReadExactAtOffset(int fd, uint64_t offset, void* buf, size_t size) noexcept {
#if defined(__linux__) || defined(__ANDROID__)
    if (::lseek(fd, static_cast<off_t>(offset), SEEK_SET) != static_cast<off_t>(offset)) {
        return -1; // mov w0, #-1 @ 0x4df4
    }
    ssize_t n = ::read(fd, buf, size);
    return (static_cast<size_t>(n) == size) ? 0 : -2; // mov w8, #-2; csel w0, wzr, w8, eq @ 0x4de4..0x4dec
#else
    (void)fd;
    (void)offset;
    (void)buf;
    (void)size;
    return -1;
#endif
}

/**
 * @brief Frees `NpthSymtabCtx` (`0x4e08..0x4e48`, FDE[51], 64 B).
 *        Giải phóng `NpthSymtabCtx` (`0x4e08..0x4e48`, FDE[51], 64 B).
 */
void FreeSymtabCtx(NpthSymtabCtx* ctx) noexcept {
    if (!ctx) {
        return;
    }
    if (ctx->symtab) {
        std::free(ctx->symtab);
    }
    if (ctx->strtab) {
        std::free(ctx->strtab);
    }
    std::free(ctx);
}

/**
 * @brief Loads `.symtab`/`.strtab` from `filepath`, recursively unpacking `.gnu_debugdata` if needed (`0x490c..0x4da0`, FDE[49], 1,172 B).
 *        Tải `.symtab`/`.strtab` từ `filepath`, giải nén đệ quy `.gnu_debugdata` bằng XZ nếu cần (`0x490c..0x4da0`, FDE[49], 1,172 B).
 */
NpthSymtabCtx* LoadSymtabOrDebugdata(const char* filepath, const uint8_t* elf_base) noexcept {
    if (!filepath || !elf_base) {
        return nullptr;
    }
    NpthSymtabCtx* ctx = static_cast<NpthSymtabCtx*>(std::malloc(sizeof(NpthSymtabCtx)));
    if (!ctx) {
        return nullptr;
    }
    std::memset(ctx, 0, sizeof(NpthSymtabCtx));

#if defined(__linux__) || defined(__ANDROID__)
    int fd = ::open(filepath, O_RDONLY | O_CLOEXEC); // mov w1, #0x80000 @ 0x4948
    if (fd < 0) {
        std::free(ctx);
        return nullptr;
    }
    off_t file_size_off = ::lseek(fd, 0, SEEK_END);
    if (file_size_off < 0) {
        ::close(fd);
        std::free(ctx);
        return nullptr;
    }
    uint64_t file_size = static_cast<uint64_t>(file_size_off);

    uint16_t e_shentsize = *reinterpret_cast<const uint16_t*>(elf_base + 0x3a);
    uint16_t e_shnum     = *reinterpret_cast<const uint16_t*>(elf_base + 0x3c);
    uint16_t e_shstrndx  = *reinterpret_cast<const uint16_t*>(elf_base + 0x3e);
    uint64_t e_shoff     = *reinterpret_cast<const uint64_t*>(elf_base + 0x28);

    uint64_t shdr_bytes = static_cast<uint64_t>(e_shnum) * static_cast<uint64_t>(e_shentsize);
    if (e_shnum == 0 || e_shoff + shdr_bytes > file_size) {
        ::close(fd);
        std::free(ctx);
        return nullptr;
    }

    Elf64Shdr* shdrs = static_cast<Elf64Shdr*>(std::malloc(shdr_bytes));
    if (!shdrs) {
        ::close(fd);
        std::free(ctx);
        return nullptr;
    }
    if (ReadExactAtOffset(fd, e_shoff, shdrs, shdr_bytes) != 0) {
        std::free(shdrs);
        ::close(fd);
        std::free(ctx);
        return nullptr;
    }

    uint64_t shstr_size = shdrs[e_shstrndx].sh_size;
    char* shstrtab = static_cast<char*>(std::malloc(shstr_size));
    if (!shstrtab || ReadExactAtOffset(fd, shdrs[e_shstrndx].sh_offset, shstrtab, shstr_size) != 0) {
        std::free(shstrtab);
        std::free(shdrs);
        ::close(fd);
        std::free(ctx);
        return nullptr;
    }

    const uint8_t* debugdata_elf = nullptr;
    size_t debugdata_len = 0;

    for (int pass = 0; pass < 2; ++pass) {
        const Elf64Shdr* symtab_sh = nullptr;
        const Elf64Shdr* strtab_sh = nullptr;
        const Elf64Shdr* debugdata_sh = nullptr;

        for (uint16_t i = 0; i < e_shnum; ++i) {
            if (i == e_shstrndx) {
                continue;
            }
            const char* sec_name = shstrtab + shdrs[i].sh_name;
            if (shdrs[i].sh_type == 2U && !symtab_sh && std::strcmp(".symtab", sec_name) == 0) {
                symtab_sh = &shdrs[i];
            } else if (shdrs[i].sh_type == 3U && !strtab_sh && std::strcmp(".strtab", sec_name) == 0) {
                strtab_sh = &shdrs[i];
            } else if (shdrs[i].sh_type == 1U && !debugdata_sh && std::strcmp(".gnu_debugdata", sec_name) == 0) {
                debugdata_sh = &shdrs[i];
            }
        }

        if (symtab_sh && strtab_sh && symtab_sh->sh_entsize > 0) {
            ctx->symtab = static_cast<Elf64Sym*>(std::malloc(symtab_sh->sh_size));
            ctx->strtab = static_cast<char*>(std::malloc(strtab_sh->sh_size));
            if (ctx->symtab && ctx->strtab) {
                bool ok = false;
                if (debugdata_elf) {
                    std::memcpy(ctx->symtab, debugdata_elf + symtab_sh->sh_offset, symtab_sh->sh_size);
                    std::memcpy(ctx->strtab, debugdata_elf + strtab_sh->sh_offset, strtab_sh->sh_size);
                    ok = true;
                } else {
                    ok = (ReadExactAtOffset(fd, symtab_sh->sh_offset, ctx->symtab, symtab_sh->sh_size) == 0 &&
                          ReadExactAtOffset(fd, strtab_sh->sh_offset, ctx->strtab, strtab_sh->sh_size) == 0);
                }
                if (ok) {
                    ctx->sym_count   = symtab_sh->sh_size / symtab_sh->sh_entsize;
                    ctx->strtab_size = strtab_sh->sh_size;
                    break;
                }
            }
            FreeSymtabCtx(ctx);
            ctx = nullptr;
            break;
        }

        if (!debugdata_sh || pass == 1) {
            FreeSymtabCtx(ctx);
            ctx = nullptr;
            break;
        }

        // Unpack .gnu_debugdata via npth_dllzma_decompress (bl #0x5858 @ 0x4b58, 0x4bfc)
        uint8_t* compressed = static_cast<uint8_t*>(std::malloc(debugdata_sh->sh_size));
        if (!compressed || ReadExactAtOffset(fd, debugdata_sh->sh_offset, compressed, debugdata_sh->sh_size) != 0) {
            std::free(compressed);
            FreeSymtabCtx(ctx);
            ctx = nullptr;
            break;
        }
        uint8_t* unpacked = nullptr;
        size_t unpacked_size = file_size;
        int rc = npth_dllzma_decompress(compressed, debugdata_sh->sh_size, &unpacked, &unpacked_size);
        std::free(compressed);
        if (rc != 0 || !unpacked) {
            std::free(unpacked);
            FreeSymtabCtx(ctx);
            ctx = nullptr;
            break;
        }

        debugdata_elf = unpacked;
        debugdata_len = unpacked_size;
        e_shoff     = *reinterpret_cast<const uint64_t*>(debugdata_elf + 0x28);
        e_shentsize = *reinterpret_cast<const uint16_t*>(debugdata_elf + 0x3a);
        e_shnum     = *reinterpret_cast<const uint16_t*>(debugdata_elf + 0x3c);
        e_shstrndx  = *reinterpret_cast<const uint16_t*>(debugdata_elf + 0x3e);
        if (e_shoff + static_cast<uint64_t>(e_shnum) * e_shentsize > debugdata_len) {
            std::free(unpacked);
            debugdata_elf = nullptr;
            FreeSymtabCtx(ctx);
            ctx = nullptr;
            break;
        }
        std::free(shstrtab);
        std::free(shdrs);
        shdrs = const_cast<Elf64Shdr*>(reinterpret_cast<const Elf64Shdr*>(debugdata_elf + e_shoff));
        shstrtab = const_cast<char*>(reinterpret_cast<const char*>(debugdata_elf + shdrs[e_shstrndx].sh_offset));
    }

    if (debugdata_elf) {
        std::free(const_cast<uint8_t*>(debugdata_elf));
    } else {
        std::free(shstrtab);
        std::free(shdrs);
    }
    ::close(fd);
    return ctx;
#else
    std::free(ctx);
    return nullptr;
#endif
}

} // namespace nextai::opencut::npth_dl

extern "C" {

/**
 * @brief Decompresses an XZ stream (`.gnu_debugdata`) using Android's `liblzma.so` (`0x2ff8` -> `0x5858..0x5b54`, FDE[57], 764 B).
 *        Giải nén luồng XZ (`.gnu_debugdata`) bằng thư viện hệ thống `liblzma.so` (`0x2ff8` -> `0x5858..0x5b54`, FDE[57], 764 B).
 */
int npth_dllzma_decompress(const uint8_t* src, size_t src_len, uint8_t** dst_out, size_t* dst_len_out) {
    using namespace nextai::opencut::npth_dl;
    if (!src || src_len == 0 || !dst_out || !dst_len_out) {
        return -1;
    }

    if (!g_lzma_table.initialized) {
        if (npth_dlapilevel() < 24) { // cmp w0, #0x18; b.lo #0x5ac0 @ 0x599c
            return -1;
        }
        void* handle = npth_dlopen("liblzma.so");
        bool used_sys_dlopen = false;
        if (!handle) {
#if defined(__linux__) || defined(__ANDROID__)
            handle = ::dlopen("liblzma.so", RTLD_NOW);
            used_sys_dlopen = true;
            if (handle) {
                ::dlclose(handle);
            }
#endif
            handle = npth_dlopen("liblzma.so");
            (void)used_sys_dlopen;
        }
        if (!handle) {
            return -1;
        }

        g_lzma_table.XzUnpacker_Construct = reinterpret_cast<decltype(g_lzma_table.XzUnpacker_Construct)>(
            npth_dlsym_symtab(handle, "XzUnpacker_Construct"));
        g_lzma_table.XzUnpacker_Free = reinterpret_cast<decltype(g_lzma_table.XzUnpacker_Free)>(
            npth_dlsym_symtab(handle, "XzUnpacker_Free"));
        void* code_fn = npth_dlsym_symtab(handle, "XzUnpacker_Code");
        g_lzma_table.XzUnpacker_Code_Pre28 = reinterpret_cast<decltype(g_lzma_table.XzUnpacker_Code_Pre28)>(code_fn);
        g_lzma_table.XzUnpacker_Code_Api29 = reinterpret_cast<decltype(g_lzma_table.XzUnpacker_Code_Api29)>(code_fn);
        g_lzma_table.XzUnpacker_IsStreamWasFinished = reinterpret_cast<decltype(g_lzma_table.XzUnpacker_IsStreamWasFinished)>(
            npth_dlsym_symtab(handle, "XzUnpacker_IsStreamWasFinished"));
        g_lzma_table.CrcGenerateTable = reinterpret_cast<decltype(g_lzma_table.CrcGenerateTable)>(
            npth_dlsym_symtab(handle, "CrcGenerateTable"));
        g_lzma_table.Crc64GenerateTable = reinterpret_cast<decltype(g_lzma_table.Crc64GenerateTable)>(
            npth_dlsym_symtab(handle, "Crc64GenerateTable"));
        npth_dlclose(handle);

        if (!g_lzma_table.XzUnpacker_Construct || !g_lzma_table.XzUnpacker_Free ||
            !code_fn || !g_lzma_table.XzUnpacker_IsStreamWasFinished ||
            !g_lzma_table.CrcGenerateTable || !g_lzma_table.Crc64GenerateTable) {
            return -1;
        }
        g_lzma_table.CrcGenerateTable();
        g_lzma_table.Crc64GenerateTable();
        g_lzma_table.initialized = true;
    }

    // Stack state buffer for CXzUnpacker (sub sp, sp, #1, lsl #12; sub sp, sp, #0x40 = 4160 bytes @ 0x5874..0x5878)
    alignas(16) uint8_t unpacker_state[4160];
    std::memset(unpacker_state, 0, sizeof(unpacker_state));
    ISzAlloc alloc{XzAllocCallback, XzFreeCallback};
    g_lzma_table.XzUnpacker_Construct(unpacker_state, &alloc);

    if (*dst_len_out == 0) {
        *dst_len_out = src_len << 1; // lsl x8, x21, #1 @ 0x58c8
    }
    *dst_out = nullptr;
    int api_level = npth_dlapilevel();
    size_t dst_offset = 0;
    size_t src_offset = 0;

    while (true) {
        uint8_t* new_buf = static_cast<uint8_t*>(std::realloc(*dst_out, *dst_len_out)); // bl realloc @ 0x592c
        *dst_out = new_buf;
        if (!new_buf) {
            g_lzma_table.XzUnpacker_Free(unpacker_state);
            return -1;
        }

        size_t rem_dst = *dst_len_out - dst_offset;
        size_t rem_src = src_len - src_offset;
        int status = 0;
        int res = 0;
        if (api_level > 28) { // cmp w23, #0x1c; b.hi #0x58f0 @ 0x595c..0x5964
            res = g_lzma_table.XzUnpacker_Code_Api29(
                unpacker_state, new_buf + dst_offset, &rem_dst,
                src + src_offset, &rem_src, 1, 0, &status);
        } else {
            res = g_lzma_table.XzUnpacker_Code_Pre28(
                unpacker_state, new_buf + dst_offset, &rem_dst,
                src + src_offset, &rem_src, 0, &status);
        }

        if (res != 0) {
            std::free(*dst_out);
            *dst_out = nullptr;
            g_lzma_table.XzUnpacker_Free(unpacker_state);
            return -2;
        }

        dst_offset += rem_dst;
        src_offset += rem_src;
        *dst_len_out <<= 1; // lsl x1, x8, #1 @ 0x5914

        if (status != 2) { // CODER_STATUS_NOT_FINISHED == 2 @ 0x591c
            break;
        }
    }

    g_lzma_table.XzUnpacker_Free(unpacker_state);
    if ((g_lzma_table.XzUnpacker_IsStreamWasFinished(unpacker_state) & 0xff) != 0) {
        *dst_len_out = dst_offset;
        return 0;
    }
    std::free(*dst_out);
    *dst_out = nullptr;
    return -2;
}

} // extern "C"
