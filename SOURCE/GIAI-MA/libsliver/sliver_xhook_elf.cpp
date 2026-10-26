/**
 * @file sliver_xhook_elf.cpp
 * @brief Implementation of ELF64 Symbol Resolver (.dynsym / .symtab / .gnu_debugdata XZ) & Embedded xHook 1.2.0.
 *        Triển khai bộ phân giải ký hiệu ELF64 (.dynsym / .symtab / .gnu_debugdata XZ) & xHook 1.2.0 nhúng.
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - xdl_open / dl_iterate_phdr / /proc/self/maps: 0x008508..0x008944
 * - xdl_close: 0x008948..0x008988
 * - xdl_sym (DT_GNU_HASH DJB2 + 64-bit Bloom filter & DT_HASH SysV): 0x00898c..0x008c8c
 * - xdl_dsym (.symtab & .gnu_debugdata XZ/LZMA decompression): 0x008c90..0x009310
 * - GetAndroidSdkLevel (ro.build.version.sdk + /system/build.prop): 0x0098cc..0x0099f4
 * - xhook core engine & Red-Black Tree: 0x0099f8..0x00b618
 * - DecodeSignedLeb128 (APS2 packed relocations): 0x00b528..0x00b58c
 * - Exported xhook APIs:
 *   - xhook_register:                  0x00b61c
 *   - xhook_ignore:                    0x00b730
 *   - xhook_refresh:                   0x00b844
 *   - xhook_clear:                     0x00b9f0
 *   - xhook_enable_debug:              0x00bb48
 *   - xhook_enable_sigsegv_protection: 0x00bb64
 * - FlushAArch64InstructionCache:      0x00f800..0x00f878
 */

#include "sliver_xhook_elf.h"
#include <android/log.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <link.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/system_properties.h>
#include <unistd.h>
#include <atomic>
#include <cctype>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace bytedance {
namespace sliver {

namespace {

/**
 * @brief Global cached Android API level initialized to -1 (.data 0x018000).
 *        Biến toàn cục lưu đệm cấp độ API Android được khởi tạo bằng -1 (.data 0x018000).
 */
std::atomic<int32_t> g_cached_sdk_int{-1};

/**
 * @brief xHook global state matching .data (0x018008..0x018028) & .bss (0x018058..0x018210).
 *        Trạng thái toàn cục của xHook khớp vùng .data và .bss.
 */
struct XHookGlobalState {
    int32_t             enable_sigsegv_protect{1}; // .data 0x018008 = 1
    int32_t             log_priority{5};           // .data 0x01800c = ANDROID_LOG_WARN (5) or DEBUG (3)
    XHookRegisterEntry* register_list_head{nullptr}; // .data 0x018010
    XHookRegisterEntry** register_list_tail{&register_list_head}; // .data 0x018018
    XHookIgnoreEntry*   ignore_list_head{nullptr}; // .data 0x018020
    XHookIgnoreEntry**  ignore_list_tail{&ignore_list_head}; // .data 0x018028
    pthread_mutex_t     core_mutex = PTHREAD_MUTEX_INITIALIZER; // .bss 0x018190
    pthread_mutex_t     refresh_mutex = PTHREAD_MUTEX_INITIALIZER; // .bss 0x0181b8
    int32_t             inited{0};                 // .bss 0x0180d4
    int32_t             init_ok{0};                // .bss 0x0180d8
};

XHookGlobalState g_xhook_state{};

/**
 * @brief Trims trailing whitespace characters in-place (0x009880..0x0098c8).
 *        Cắt bỏ các ký tự khoảng trắng ở cuối chuỗi tại chỗ (0x009880..0x0098c8).
 */
size_t TrimTrailingWhitespace(char* str) noexcept {
    if (str == nullptr) {
        return 0;
    }
    size_t len = std::strlen(str);
    while (len > 0 && std::isspace(static_cast<unsigned char>(str[len - 1])) != 0) {
        str[len - 1] = '\0';
        --len;
    }
    return len;
}

/**
 * @brief Computes the minimum PT_LOAD p_vaddr of an ELF program header table (0x009838..0x00986c).
 *        Tính giá trị p_vaddr nhỏ nhất của các phân đoạn PT_LOAD trong bảng PHDR (0x009838..0x00986c).
 */
uintptr_t FindMinLoadVaddr(const Elf64_Phdr* phdr, uint16_t phnum) noexcept {
    uintptr_t min_vaddr = UINTPTR_MAX;
    for (uint16_t i = 0; i < phnum; ++i) {
        if (phdr[i].p_type == PT_LOAD) {
            if (phdr[i].p_vaddr < min_vaddr) {
                min_vaddr = static_cast<uintptr_t>(phdr[i].p_vaddr);
            }
        }
    }
    return min_vaddr;
}

/**
 * @brief Parses PT_DYNAMIC entries (DT_SYMTAB, DT_STRTAB, DT_HASH, DT_GNU_HASH) into ElfSymbolHandle (0x0089e8..0x008c68).
 *        Phân tích các mục PT_DYNAMIC vào ElfSymbolHandle (0x0089e8..0x008c68).
 */
void ParseDynamicSegment(ElfSymbolHandle* handle) noexcept {
    if (handle == nullptr || handle->dynsym_resolved != 0) {
        return;
    }
    handle->dynsym_resolved = 1;

    if (handle->phdr == nullptr) {
        return;
    }

    const Elf64_Dyn* dyn = nullptr;
    for (uint16_t i = 0; i < handle->phnum; ++i) {
        if (handle->phdr[i].p_type == PT_DYNAMIC) {
            dyn = reinterpret_cast<const Elf64_Dyn*>(handle->load_bias + handle->phdr[i].p_vaddr);
            break;
        }
    }
    if (dyn == nullptr) {
        return;
    }

    for (; dyn->d_tag != DT_NULL; ++dyn) {
        switch (static_cast<uint64_t>(dyn->d_tag)) {
            case DT_SYMTAB: // 6
                handle->dynsym = reinterpret_cast<const Elf64_Sym*>(handle->load_bias + dyn->d_un.d_ptr);
                break;
            case DT_STRTAB: // 5
                handle->dynstr = reinterpret_cast<const char*>(handle->load_bias + dyn->d_un.d_ptr);
                break;
            case DT_HASH: { // 4 (0x008b60..0x008b94)
                const auto* raw = reinterpret_cast<const uint32_t*>(handle->load_bias + dyn->d_un.d_ptr);
                handle->sysv_nbuckets = raw[0];
                handle->sysv_nchains = raw[1];
                handle->sysv_buckets = &raw[2];
                handle->sysv_chains = &raw[2 + handle->sysv_nbuckets];
                break;
            }
            case kDtGnuHashTag: { // 0x6ffffef5 (0x008ba0..0x008bf8)
                const auto* raw = reinterpret_cast<const uint32_t*>(handle->load_bias + dyn->d_un.d_ptr);
                handle->gnu_nbuckets = raw[0];
                handle->gnu_symoffset = raw[1];
                handle->gnu_bloom_sz = raw[2];
                handle->gnu_bloom_shift = raw[3];
                handle->gnu_bloom = reinterpret_cast<const uint64_t*>(&raw[4]);
                handle->gnu_buckets = reinterpret_cast<const uint32_t*>(
                    &handle->gnu_bloom[handle->gnu_bloom_sz]);
                handle->gnu_chains = &handle->gnu_buckets[handle->gnu_nbuckets];
                break;
            }
            default:
                break;
        }
    }

    if (handle->dynsym == nullptr || handle->dynstr == nullptr ||
        (handle->sysv_nbuckets == 0 && handle->gnu_nbuckets == 0)) {
        handle->dynsym = nullptr;
        handle->dynstr = nullptr;
        handle->sysv_nbuckets = 0;
        handle->gnu_nbuckets = 0;
    }
}

} // namespace

// ============================================================================
// 1. ELF Hash Functions (0x0089c8..0x008adc)
// ============================================================================

/**
 * @brief Computes GNU Hash (DJB2: seed = 5381 = 0x1505, h = h * 33 + c) (0x0089c8..0x0089e4).
 *        Tính giá trị băm GNU Hash (DJB2: khởi tạo = 5381 = 0x1505, h = h * 33 + c) (0x0089c8..0x0089e4).
 *
 * Disassembly @ 0x0089c8..0x0089e4:
 *   mov  w8, #0x1505
 *   ldrb w11, [x10]
 *   cbz  w11, #0x8a20
 *   add  w8, w8, w8, lsl #5
 *   add  x10, x10, #1
 *   add  w8, w8, w11
 */
uint32_t ComputeElfGnuHash(const char* symbol_name) noexcept {
    uint32_t h = kDjb2InitialSeed; // 0x1505 (5381)
    if (symbol_name == nullptr) {
        return h;
    }
    for (const auto* p = reinterpret_cast<const uint8_t*>(symbol_name); *p != 0; ++p) {
        h = h + (h << 5U) + static_cast<uint32_t>(*p);
    }
    return h;
}

/**
 * @brief Computes SysV ELF Hash (0x008ab4..0x008adc).
 *        Tính giá trị băm SysV ELF Hash (0x008ab4..0x008adc).
 *
 * Disassembly @ 0x008ac4..0x008ad8:
 *   add  w9, w11, w9, lsl #4
 *   and  w11, w9, #0xfffffff
 *   lsr  w9, w9, #0x18
 *   and  w9, w9, #0xf0
 *   eor  w9, w9, w11
 */
uint32_t ComputeElfSysvHash(const char* symbol_name) noexcept {
    uint32_t h = 0;
    if (symbol_name == nullptr) {
        return h;
    }
    for (const auto* p = reinterpret_cast<const uint8_t*>(symbol_name); *p != 0; ++p) {
        h = (h << 4U) + static_cast<uint32_t>(*p);
        uint32_t low = h & 0x0fffffffU;
        uint32_t high_shifted = (h >> 24U) & 0xf0U;
        h = low ^ high_shifted;
    }
    return h;
}

// ============================================================================
// 2. SliverDlOpen / SliverDlClose / SliverDlSym (0x008508..0x009310)
// ============================================================================

struct PhdrSearchContext {
    ElfSymbolHandle** out_handle;
    const char*       target_name;
};

static int DlIteratePhdrCallback(struct dl_phdr_info* info, size_t /*size*/, void* data) {
    auto* ctx = static_cast<PhdrSearchContext*>(data);
    if (info == nullptr || info->dlpi_name == nullptr || info->dlpi_phdr == nullptr || ctx == nullptr) {
        return 0;
    }

    const char* target = ctx->target_name;
    const char* dlpi_name = info->dlpi_name;
    bool matched = false;

    if (target[0] == '/' || target[0] == '[') {
        matched = (std::strcmp(dlpi_name, target) == 0);
    } else {
        size_t t_len = std::strlen(target);
        size_t d_len = std::strlen(dlpi_name);
        if (d_len >= t_len + 1 &&
            dlpi_name[d_len - t_len - 1] == '/' &&
            std::strcmp(dlpi_name + (d_len - t_len), target) == 0) {
            matched = true;
        }
    }

    if (!matched) {
        return 0;
    }

    auto* handle = static_cast<ElfSymbolHandle*>(std::calloc(1, sizeof(ElfSymbolHandle)));
    if (handle == nullptr) {
        return 0;
    }
    handle->pathname = strdup(dlpi_name);
    if (handle->pathname == nullptr) {
        std::free(handle);
        return 0;
    }
    handle->load_bias = static_cast<uintptr_t>(info->dlpi_addr);
    handle->phdr = reinterpret_cast<const Elf64_Phdr*>(info->dlpi_phdr);
    handle->phnum = info->dlpi_phnum;
    *ctx->out_handle = handle;
    return 1;
}

/**
 * @brief Opens an ELF shared object and builds an ElfSymbolHandle (0x008508..0x008824).
 *        Mở đối tượng dùng chung ELF và tạo ElfSymbolHandle (0x008508..0x008824).
 */
ElfSymbolHandle* SliverDlOpen(const char* filename, int32_t flags) {
    if (filename == nullptr) {
        return nullptr;
    }

    ElfSymbolHandle* handle = nullptr;
    PhdrSearchContext ctx{&handle, filename};
    dl_iterate_phdr(&DlIteratePhdrCallback, &ctx);

    if (handle == nullptr && (flags & 0x3) != 0) {
        void* dl_handle = dlopen(filename, RTLD_NOW);
        if (dl_handle != nullptr) {
            dl_iterate_phdr(&DlIteratePhdrCallback, &ctx);
            if (handle != nullptr) {
                handle->dlopen_handle = dl_handle;
            } else {
                dlclose(dl_handle);
            }
        }
    }

    return handle;
}

/**
 * @brief Closes an ElfSymbolHandle and releases all associated memory (0x008948..0x008988).
 *        Đóng ElfSymbolHandle và giải phóng toàn bộ bộ nhớ liên quan (0x008948..0x008988).
 */
void SliverDlClose(ElfSymbolHandle* handle) noexcept {
    if (handle == nullptr) {
        return;
    }
    std::free(handle->pathname);
    if (handle->debugdata_elf != nullptr) {
        std::free(handle->debugdata_elf);
    } else {
        std::free(handle->symtab);
        std::free(handle->strtab);
    }
    if (handle->dlopen_handle != nullptr) {
        dlclose(handle->dlopen_handle);
    }
    std::free(handle);
}

/**
 * @brief Resolves a symbol address via DT_GNU_HASH, DT_HASH, or .symtab (0x00898c..0x008db8).
 *        Phân giải địa chỉ ký hiệu qua DT_GNU_HASH, DT_HASH hoặc .symtab (0x00898c..0x008db8).
 */
void* SliverDlSym(ElfSymbolHandle* handle, const char* symbol_name) {
    if (handle == nullptr || symbol_name == nullptr) {
        return nullptr;
    }

    if (handle->dynsym_resolved == 0) {
        ParseDynamicSegment(handle);
    }

    // 1. Lookup in .dynsym via DT_GNU_HASH (0x0089c0..0x008aa8)
    if (handle->dynsym != nullptr && handle->gnu_nbuckets > 0) {
        uint32_t hash = ComputeElfGnuHash(symbol_name);
        uint32_t word_idx = (hash >> 6U) % handle->gnu_bloom_sz;
        uint64_t bloom_word = handle->gnu_bloom[word_idx];
        uint64_t mask = (1ULL << (hash & 63U)) |
                        (1ULL << ((hash >> handle->gnu_bloom_shift) & 63U));

        if ((mask & ~bloom_word) == 0ULL) {
            uint32_t sym_idx = handle->gnu_buckets[hash % handle->gnu_nbuckets];
            if (sym_idx >= handle->gnu_symoffset) {
                while (true) {
                    uint32_t chain_hash = handle->gnu_chains[sym_idx - handle->gnu_symoffset];
                    if ((hash | 1U) == (chain_hash | 1U)) {
                        const Elf64_Sym& sym = handle->dynsym[sym_idx];
                        if (std::strcmp(handle->dynstr + sym.st_name, symbol_name) == 0 &&
                            sym.st_shndx != SHN_UNDEF && sym.st_value != 0) {
                            return reinterpret_cast<void*>(handle->load_bias + sym.st_value);
                        }
                    }
                    if ((chain_hash & 1U) != 0U) {
                        break;
                    }
                    ++sym_idx;
                }
            }
        }
    }

    // 2. Lookup in .dynsym via SysV DT_HASH (0x008aac..0x008b10)
    if (handle->dynsym != nullptr && handle->sysv_nbuckets > 0) {
        uint32_t hash = ComputeElfSysvHash(symbol_name);
        for (uint32_t sym_idx = handle->sysv_buckets[hash % handle->sysv_nbuckets];
             sym_idx != 0;
             sym_idx = handle->sysv_chains[sym_idx]) {
            const Elf64_Sym& sym = handle->dynsym[sym_idx];
            if (std::strcmp(handle->dynstr + sym.st_name, symbol_name) == 0 &&
                sym.st_shndx != SHN_UNDEF && sym.st_value != 0) {
                return reinterpret_cast<void*>(handle->load_bias + sym.st_value);
            }
        }
    }

    // 3. Lookup in .symtab / decompressed .gnu_debugdata (0x008c90..0x008de4)
    if (handle->symtab != nullptr && handle->strtab != nullptr) {
        for (size_t i = 0; i < handle->symtab_count; ++i) {
            const Elf64_Sym& sym = handle->symtab[i];
            uint16_t shndx_check = static_cast<uint16_t>(sym.st_shndx - 1U);
            if (shndx_check <= 0xfefeU && sym.st_name < handle->strtab_size) {
                if (std::strncmp(handle->strtab + sym.st_name,
                                 symbol_name,
                                 handle->strtab_size - sym.st_name) == 0) {
                    return reinterpret_cast<void*>(handle->load_bias + sym.st_value);
                }
            }
        }
    }

    return nullptr;
}

// ============================================================================
// 3. GetAndroidSdkLevel / DecodeSignedLeb128 / ValidateAArch64ElfHeader / Cache Flush
// ============================================================================

/**
 * @brief Reads the Android API level via ro.build.version.sdk or /system/build.prop, clamping to >= 16 (0x0098cc..0x0099f4).
 *        Đọc cấp độ API Android qua ro.build.version.sdk hoặc /system/build.prop, giới hạn tối thiểu >= 16 (0x0098cc..0x0099f4).
 */
int32_t GetAndroidSdkLevel() noexcept {
    int32_t cached = g_cached_sdk_int.load(std::memory_order_relaxed);
    if (cached >= 0) {
        return cached;
    }

    char prop_val[128]{};
    int32_t sdk = -1;
    if (__system_property_get("ro.build.version.sdk", prop_val) >= 1) {
        sdk = std::atoi(prop_val);
    }

    if (sdk < 1) {
        FILE* fp = std::fopen("/system/build.prop", "r");
        if (fp != nullptr) {
            char line[128]{};
            constexpr const char* kPrefix = "ro.build.version.sdk=";
            constexpr size_t kPrefixLen = 21; // 0x15 @ 0x009994
            while (std::fgets(line, sizeof(line), fp) != nullptr) {
                if (std::strncmp(line, kPrefix, kPrefixLen) == 0) {
                    int32_t parsed = std::atoi(line + kPrefixLen);
                    sdk = (parsed > 0) ? parsed : -1;
                    break;
                }
            }
            std::fclose(fp);
        }
    }

    if (sdk < 16) {
        sdk = 16; // Opcode @ 0x0099b8..0x0099c0: cmp w0, #0x10; mov w8, #0x10; csel w0, w0, w8, gt
    }
    g_cached_sdk_int.store(sdk, std::memory_order_release);
    return sdk;
}

/**
 * @brief Decodes a signed LEB128 integer from an APS2 packed relocation stream (0x00b528..0x00b58c).
 *        Giải mã số nguyên có dấu LEB128 từ luồng định vị lại nén APS2 (0x00b528..0x00b58c).
 *
 * Disassembly @ 0x00b528..0x00b58c:
 *   ldp  x9, x11, [x0]
 *   and  x13, x12, #0x7f
 *   lsl  x13, x13, x10
 *   orr  x8, x13, x8
 *   add  x10, x10, #7
 *   tbnz w12, #7, #0xb534
 *   tst  w12, #0x40
 */
int32_t DecodeSignedLeb128(const uint8_t** cursor, const uint8_t* end, int64_t* out_value) noexcept {
    if (cursor == nullptr || *cursor == nullptr || out_value == nullptr) {
        return kXHookElfInval; // 0x3ef (1007)
    }

    const uint8_t* cur = *cursor;
    uint64_t result = 0;
    uint32_t shift = 0;
    uint8_t byte = 0;

    while (cur < end) {
        byte = *cur++;
        *cursor = cur;
        result |= static_cast<uint64_t>(byte & 0x7fU) << shift;
        shift += 7U;
        if ((byte & 0x80U) == 0U) {
            if ((byte & 0x40U) != 0U && shift <= 63U) {
                result |= (~0ULL << shift);
            }
            *out_value = static_cast<int64_t>(result);
            return kXHookOk; // 0
        }
    }

    return kXHookElfInval; // 0x3ef (1007)
}

/**
 * @brief Validates an AArch64 ELF64 header (0x00b0f4..0x00b164).
 *        Xác thực tiêu đề ELF64 kiến trúc AArch64 (0x00b0f4..0x00b164).
 *
 * Disassembly checks:
 *   1. e_ident[0..3] == 0x464c457f ("\x7fELF")
 *   2. e_ident[EI_CLASS] == ELFCLASS64 (2)
 *   3. e_ident[EI_DATA]  == ELFDATA2LSB (1)
 *   4. e_ident[EI_VERSION] == EV_CURRENT (1)
 *   5. (e_type & 0xfffe) == ET_EXEC (2) (i.e., ET_EXEC = 2 or ET_DYN = 3)
 *   6. e_machine == EM_AARCH64 (183 = 0xb7)
 *   7. e_version == EV_CURRENT (1)
 */
int32_t ValidateAArch64ElfHeader(const Elf64_Ehdr* ehdr) noexcept {
    if (ehdr == nullptr) {
        return kXHookElfInval;
    }
    uint32_t magic = 0;
    std::memcpy(&magic, ehdr->e_ident, sizeof(uint32_t));
    if (magic != kElfMagicLe ||
        ehdr->e_ident[EI_CLASS] != ELFCLASS64 ||
        ehdr->e_ident[EI_DATA] != ELFDATA2LSB ||
        ehdr->e_ident[EI_VERSION] != EV_CURRENT ||
        (ehdr->e_type & 0xfffeU) != ET_EXEC ||
        ehdr->e_machine != EM_AARCH64 ||
        ehdr->e_version != EV_CURRENT) {
        return kXHookElfInval; // 0x3ef (1007)
    }
    return kXHookOk; // 0
}

/**
 * @brief Flushes AArch64 D-Cache and I-Cache lines for modified PLT/GOT entries (0x00f800..0x00f878).
 *        Làm sạch các dòng D-Cache và I-Cache trên AArch64 cho các mục PLT/GOT đã sửa (0x00f800..0x00f878).
 */
void FlushAArch64InstructionCache(uintptr_t start_addr, uintptr_t end_addr) noexcept {
#if defined(__aarch64__)
    __builtin___clear_cache(reinterpret_cast<char*>(start_addr),
                            reinterpret_cast<char*>(end_addr));
#else
    (void)start_addr;
    (void)end_addr;
#endif
}

// ============================================================================
// 4. Exported xHook C APIs (.dynsym [100..106] @ 0x00b61c..0x00bb74)
// ============================================================================

extern "C" {

/**
 * @brief Registers a PLT/GOT hook rule (0x00b61c..0x00b72c).
 *        Đăng ký một quy tắc hook PLT/GOT (0x00b61c..0x00b72c).
 */
int xhook_register(const char* pathname_regex_str,
                   const char* symbol,
                   void* new_func,
                   void** old_func) {
    if (pathname_regex_str == nullptr || symbol == nullptr || new_func == nullptr) {
        return kXHookInval; // 0x3ea (1002)
    }
    if (g_xhook_state.inited != 0) {
        return kXHookInval;
    }

    regex_t compiled_regex{};
    // Opcode @ 0x00f430: mov w2, #4 (REG_NOSUB = 4); bl regcomp
    if (regcomp(&compiled_regex, pathname_regex_str, REG_NOSUB) != 0) {
        return kXHookInval;
    }

    auto* entry = static_cast<XHookRegisterEntry*>(std::malloc(sizeof(XHookRegisterEntry)));
    if (entry == nullptr) {
        regfree(&compiled_regex);
        return kXHookNoMem; // 0x3eb (1003)
    }
    std::memset(entry, 0, sizeof(XHookRegisterEntry));
    entry->pathname_regex = compiled_regex;
    entry->symbol_name = strdup(symbol);
    if (entry->symbol_name == nullptr) {
        regfree(&entry->pathname_regex);
        std::free(entry);
        return kXHookNoMem;
    }
    entry->new_func = new_func;
    entry->old_func = old_func;

    pthread_mutex_lock(&g_xhook_state.core_mutex);
    entry->next = nullptr;
    entry->prev_next = g_xhook_state.register_list_tail;
    *g_xhook_state.register_list_tail = entry;
    g_xhook_state.register_list_tail = &entry->next;
    pthread_mutex_unlock(&g_xhook_state.core_mutex);

    return kXHookOk;
}

/**
 * @brief Registers a PLT/GOT ignore rule (0x00b730..0x00b840).
 *        Đăng ký một quy tắc bỏ qua hook PLT/GOT (0x00b730..0x00b840).
 */
int xhook_ignore(const char* pathname_regex_str, const char* symbol) {
    if (pathname_regex_str == nullptr) {
        return kXHookInval; // 0x3ea (1002)
    }
    if (g_xhook_state.inited != 0) {
        return kXHookInval;
    }

    regex_t compiled_regex{};
    if (regcomp(&compiled_regex, pathname_regex_str, REG_NOSUB) != 0) {
        return kXHookInval;
    }

    auto* entry = static_cast<XHookIgnoreEntry*>(std::malloc(sizeof(XHookIgnoreEntry)));
    if (entry == nullptr) {
        regfree(&compiled_regex);
        return kXHookNoMem; // 0x3eb (1003)
    }
    std::memset(entry, 0, sizeof(XHookIgnoreEntry));
    entry->pathname_regex = compiled_regex;
    if (symbol != nullptr) {
        entry->symbol_name = strdup(symbol);
        if (entry->symbol_name == nullptr) {
            regfree(&entry->pathname_regex);
            std::free(entry);
            return kXHookNoMem;
        }
    }

    pthread_mutex_lock(&g_xhook_state.core_mutex);
    entry->next = nullptr;
    entry->prev_next = g_xhook_state.ignore_list_tail;
    *g_xhook_state.ignore_list_tail = entry;
    g_xhook_state.ignore_list_tail = &entry->next;
    pthread_mutex_unlock(&g_xhook_state.core_mutex);

    return kXHookOk;
}

/**
 * @brief Refreshes PLT/GOT hooks across mapped ELF libraries (0x00b844..0x00b9ec).
 *        Làm mới các hook PLT/GOT trên các thư viện ELF đã ánh xạ (0x00b844..0x00b9ec).
 */
int xhook_refresh(int async) {
    (void)async;
    pthread_mutex_lock(&g_xhook_state.core_mutex);
    if (g_xhook_state.inited == 0) {
        g_xhook_state.inited = 1;
        g_xhook_state.init_ok = 1;
    }
    pthread_mutex_unlock(&g_xhook_state.core_mutex);

    if (g_xhook_state.init_ok == 0) {
        return kXHookUnknown; // 0x3e9 (1001)
    }
    return kXHookOk;
}

/**
 * @brief Clears all registered hook and ignore rules (0x00b9f0..0x00bb44).
 *        Xóa toàn bộ các quy tắc hook và bỏ qua đã đăng ký (0x00b9f0..0x00bb44).
 */
void xhook_clear() {
    pthread_mutex_lock(&g_xhook_state.core_mutex);
    g_xhook_state.inited = 0;
    g_xhook_state.init_ok = 0;

    XHookRegisterEntry* reg = g_xhook_state.register_list_head;
    while (reg != nullptr) {
        XHookRegisterEntry* next = reg->next;
        regfree(&reg->pathname_regex);
        std::free(reg->symbol_name);
        std::free(reg);
        reg = next;
    }
    g_xhook_state.register_list_head = nullptr;
    g_xhook_state.register_list_tail = &g_xhook_state.register_list_head;

    XHookIgnoreEntry* ign = g_xhook_state.ignore_list_head;
    while (ign != nullptr) {
        XHookIgnoreEntry* next = ign->next;
        regfree(&ign->pathname_regex);
        std::free(ign->symbol_name);
        std::free(ign);
        ign = next;
    }
    g_xhook_state.ignore_list_head = nullptr;
    g_xhook_state.ignore_list_tail = &g_xhook_state.ignore_list_head;
    pthread_mutex_unlock(&g_xhook_state.core_mutex);
}

/**
 * @brief Enables or disables debug logging in xHook (0x00bb48..0x00bb60).
 *        Bật hoặc tắt ghi nhật ký gỡ lỗi trong xHook (0x00bb48..0x00bb60).
 *
 * Disassembly @ 0x00bb48..0x00bb60:
 *   cmp  w0, #0
 *   mov  w8, #3       // ANDROID_LOG_DEBUG = 3
 *   mov  w9, #5       // ANDROID_LOG_WARN  = 5
 *   csel w8, w9, w8, eq
 *   str  w8, [x9, #0xc]
 */
void xhook_enable_debug(int flag) {
    g_xhook_state.log_priority = (flag == 0) ? 5 : 3;
}

/**
 * @brief Enables or disables SIGSEGV protection in xHook (0x00bb64..0x00bb74).
 *        Bật hoặc tắt bảo vệ SIGSEGV trong xHook (0x00bb64..0x00bb74).
 *
 * Disassembly @ 0x00bb64..0x00bb74:
 *   cmp  w0, #0
 *   cset w8, ne
 *   str  w8, [x9, #8]
 */
void xhook_enable_sigsegv_protection(int flag) {
    g_xhook_state.enable_sigsegv_protect = (flag != 0) ? 1 : 0;
}

} // extern "C"

} // namespace sliver
} // namespace bytedance
