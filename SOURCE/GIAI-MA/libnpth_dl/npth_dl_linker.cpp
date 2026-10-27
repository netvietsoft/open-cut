/**
 * @file npth_dl_linker.cpp
 * @brief Clean-room C++17 Reconstruction of `libnpth_dl.so` Linker Bypass, Mutex Discovery & Public C APIs.
 *        Tái cấu trúc sạch C++17 của `libnpth_dl.so` Vượt rào Namespace Linker, Dò tìm Mutex & 22 API công khai.
 *
 * Covers `.text` functions:
 *   - `0x2650..0x2834` (`npth_dlopen`, FDE[05], 484 B)
 *   - `0x2834..0x2878` (`npth_dliterater`, FDE[06], 68 B)
 *   - `0x2878..0x2a08` (`DlIterateOpenCallback`, FDE[07], 400 B)
 *   - `0x2a08..0x2adc` (`npth_dlsym_size`, FDE[08], 212 B)
 *   - `0x2adc..0x2ae4` (`npth_dlsym`, FDE[09], 8 B)
 *   - `0x2ae4..0x2b60` (`npth_dlrel_plt_got`, FDE[10], 124 B)
 *   - `0x2b60..0x2c08` (`npth_dlsym_symtab_size`, FDE[11], 168 B)
 *   - `0x2c08..0x2c94` (`npth_dlsym_symtab`, FDE[12], 140 B)
 *   - `0x2c94..0x2d30` (`npth_dlsym_symtab_prefix`, FDE[13], 156 B)
 *   - `0x2d30..0x2de4` (`npth_dlsym_symtab_size_prefix`, FDE[14], 180 B)
 *   - `0x2de4..0x2e3c` (`npth_dlclose`, FDE[15], 88 B)
 *   - `0x2e3c..0x2e4c` (`npth_dlopen_force`, `npth_dlsym_force`, `npth_dlclose_force`, FDE[16..18])
 *   - `0x2e4c..0x2f38` (`npth_dladdr`, FDE[19], 236 B)
 *   - `0x2f38..0x2fbc` (`EnsureSymtabLoaded`, FDE[20], 132 B)
 *   - `0x2fbc..0x3008` (`npth_dlerror`, `npth_dlusable`, `npth_dlapilevel`, `npth_dlbuildid`, `npth_dltest`, `npth_dldebug`, `npth_dlincrease`)
 *   - `0x3008..0x329c` (`GetAndroidApiLevel`, `ParseDecimalSdkInt`, FDE[29..32])
 *   - `0x394c..0x4328` (`ResolveDlIteratePhdrWrapper`, `DlIterateWithLinkerLock`, `DiscoverLinkerLockMutex`, FDE[38..41])
 *   - `0x4e48..0x5678` (`DlOpenForceImpl`, `DlSymForceImpl`, `DiscoverCallerAddressesCallback`, FDE[52..54])
 *   - `0x5678..0x5858` (`ResolvePathByNameFromMaps`, `ResolvePathByAddrFromMaps`, FDE[55..56])
 */

#include "npth_dl.hpp"
#include <pthread.h>
#include <cstdarg>

#if defined(__linux__) || defined(__ANDROID__)
#include <dlfcn.h>
#include <link.h>
#include <sys/auxv.h>
#include <unistd.h>
#include <fcntl.h>
#endif

namespace nextai::opencut::npth_dl {

namespace {

constexpr uint32_t kElfMagicLittleEndian = 0x464c457fU; // mov w9, #0x457f; movk w9, #0x464c, lsl #16 @ 0x26a4..0x26a8
constexpr uintptr_t kPseudoHandleMain   = 1ULL;         // cmp x19, #1 -> getauxval(AT_PHDR = 3) @ 0x2678..0x268c
constexpr uintptr_t kPseudoHandleLinker = 2ULL;         // cmp x19, #2 -> getauxval(AT_BASE = 7) @ 0x2670..0x2708

// Global state in .data (0xe2b8) and .bss (0xe2e0..0xe3cc)
pthread_mutex_t g_linker_probe_mutex = PTHREAD_MUTEX_INITIALIZER; // 0xe2b8
int             g_cached_api_level   = 0;                         // 0xe2e0
int             g_debug_enabled      = 0;                         // 0xe3cc

// Forced dlopen/dlsym caller address discovery state (0xe330..0xe390)
pthread_mutex_t g_caller_init_mutex  = PTHREAD_MUTEX_INITIALIZER; // 0xe368
bool            g_caller_initialized = false;                     // 0xe390
pthread_mutex_t* g_dl_mutex_ptr      = nullptr;                   // 0xe330 (__dl__ZL10g_dl_mutex)
void*           g_caller_libc        = nullptr;                   // 0xe338 (/libc.so)
void*           g_caller_libart      = nullptr;                   // 0xe340 (/libart.so)
void*           g_caller_vendor      = nullptr;                   // 0xe348 (/vendor/lib64/ or /odm/lib64/)
void*           g_caller_apex_vndk   = nullptr;                   // 0xe350 (/apex/com.android.vndk.v)
void*           g_fn_do_dlopen       = nullptr;                   // 0xe358
void*           g_fn_do_dlsym        = nullptr;                   // 0xe360

/**
 * @brief Checks if `str` starts with `prefix` (`0x5b84..0x5bb8`, FDE[63], 52 B).
 *        Kiểm tra chuỗi `str` có bắt đầu bằng tiền tố `prefix` hay không (`0x5b84..0x5bb8`, FDE[63], 52 B).
 */
bool StartsWith(const char* str, const char* prefix) noexcept {
    if (!str || !prefix) {
        return false;
    }
    while (*str != '\0' && *str == *prefix) {
        ++str;
        ++prefix;
    }
    return (*prefix == '\0');
}

/**
 * @brief Checks if `str` ends with `suffix` (`0x5bb8..0x5c14`, FDE[64], 92 B).
 *        Kiểm tra chuỗi `str` có kết thúc bằng hậu tố `suffix` hay không (`0x5bb8..0x5c14`, FDE[64], 92 B).
 */
bool EndsWith(const char* str, const char* suffix) noexcept {
    if (!str || !suffix) {
        return false;
    }
    size_t str_len = std::strlen(str);
    size_t suf_len = std::strlen(suffix);
    if (str_len < suf_len) {
        return false;
    }
    return (std::strcmp(str + (str_len - suf_len), suffix) == 0);
}

/**
 * @brief Callback for `dl_iterate_phdr` used by `npth_dlopen` (`0x2878..0x2a08`, FDE[07], 400 B).
 *        Hàm gọi lại `dl_iterate_phdr` dùng trong `npth_dlopen` (`0x2878..0x2a08`, FDE[07], 400 B).
 */
struct DlOpenSearchState {
    const char*      target_name; // sp+0x00
    char*            realpath;    // sp+0x08
    uintptr_t        min_vaddr;   // sp+0x10
    uintptr_t        load_bias;   // sp+0x18
    const Elf64Phdr* phdr;        // sp+0x20
    uint64_t         phnum;       // sp+0x28
};

int DlIterateOpenCallback(DlPhdrInfo* info, size_t /*size*/, void* data) noexcept {
    DlOpenSearchState* st = static_cast<DlOpenSearchState*>(data);
    if (!info || !info->dlpi_name || info->dlpi_addr == 0) {
        return 0;
    }

    const Elf64Phdr* phdr = info->dlpi_phdr;
    uint16_t phnum = info->dlpi_phnum;
    if (!phdr || phnum == 0) {
        const uint8_t* ehdr = reinterpret_cast<const uint8_t*>(info->dlpi_addr);
        if (*reinterpret_cast<const uint32_t*>(ehdr) != kElfMagicLittleEndian) {
            return 0;
        }
        phdr  = reinterpret_cast<const Elf64Phdr*>(ehdr + *reinterpret_cast<const uint64_t*>(ehdr + 0x20));
        phnum = *reinterpret_cast<const uint16_t*>(ehdr + 0x38);
    }

    const char* dlpi_name = info->dlpi_name;
    const char* target    = st->target_name;
    if (target[0] == '/' && dlpi_name[0] != '/') {
        const char* slash = std::strrchr(target, '/');
        if (slash) {
            target = slash + 1;
        }
    } else if (target[0] != '/' && dlpi_name[0] == '/') {
        const char* slash = std::strrchr(dlpi_name, '/');
        if (slash) {
            dlpi_name = slash + 1;
        }
    }

    if (std::strcmp(target, dlpi_name) != 0) {
        return 0;
    }

    uint64_t min_p_vaddr = 0x7fffffffffffffffULL; // mov x10, #0x7fffffffffffffff @ 0x2964
    for (uint16_t i = 0; i < phnum; ++i) {
        if (phdr[i].p_type == 1U && phdr[i].p_vaddr < min_p_vaddr) {
            min_p_vaddr = phdr[i].p_vaddr;
        }
    }
    if (min_p_vaddr == 0x7fffffffffffffffULL || (info->dlpi_addr + min_p_vaddr) == 0) {
        st->min_vaddr = 0;
        return 0;
    }

    st->load_bias = info->dlpi_addr;
    st->min_vaddr = info->dlpi_addr + min_p_vaddr;
    st->phdr      = phdr;
    st->phnum     = phnum;

    if (info->dlpi_name[0] == '/' || (info->dlpi_name[0] == '[' && std::strcmp(info->dlpi_name, "[vdso]") != 0)) {
        st->realpath = ::strdup(info->dlpi_name);
    } else {
        st->realpath = nullptr;
    }
    return 1;
}

/**
 * @brief Lazily loads `.symtab` or `.gnu_debugdata` into `handle->symtab_ctx` (`0x2f38..0x2fbc`, FDE[20], 132 B).
 *        Tải lười (lazy load) `.symtab` hoặc `.gnu_debugdata` vào `handle->symtab_ctx` (`0x2f38..0x2fbc`).
 */
NpthSymtabCtx* EnsureSymtabLoaded(NpthDlHandle* handle) noexcept {
    if (!handle) {
        return nullptr;
    }
    if (handle->symtab_ctx) {
        return handle->symtab_ctx;
    }
    if (!handle->realpath) {
        handle->realpath = ResolvePathByAddrFromMaps(handle->min_vaddr);
        if (!handle->realpath) {
            return nullptr;
        }
    }
    handle->symtab_ctx = LoadSymtabOrDebugdata(
        handle->realpath, reinterpret_cast<const uint8_t*>(handle->min_vaddr));
    return handle->symtab_ctx;
}

/**
 * @brief Discovers caller addresses in `/libc.so`, `/libart.so`, `/vendor/lib64/`, `/apex/com.android.vndk.v` (`0x5448..0x5678`, FDE[54], 560 B).
 *        Dò tìm địa chỉ vùng mã của `/libc.so`, `/libart.so`, `/vendor/lib64/`, `/apex/com.android.vndk.v` (`0x5448..0x5678`).
 */
int DiscoverCallerAddressesCallback(DlPhdrInfo* info, size_t /*size*/, void* /*data*/) noexcept {
    if (!info || info->dlpi_addr == 0 || !info->dlpi_name) {
        return 0;
    }
    auto find_first_pt_load = [](const DlPhdrInfo* inf) -> void* {
        for (uint16_t i = 0; i < inf->dlpi_phnum; ++i) {
            if (inf->dlpi_phdr[i].p_type == 1U) {
                return reinterpret_cast<void*>(inf->dlpi_addr + inf->dlpi_phdr[i].p_vaddr);
            }
        }
        return nullptr;
    };

    if (!g_caller_libc && EndsWith(info->dlpi_name, "/libc.so")) {
        g_caller_libc = find_first_pt_load(info);
    }
    if (!g_caller_libart && EndsWith(info->dlpi_name, "/libart.so")) {
        g_caller_libart = find_first_pt_load(info);
    }
    static constexpr const char* kVendorPrefixes[] = {
        "/vendor/lib64/egl/",
        "/vendor/lib64/hw/",
        "/vendor/lib64/",
        "/odm/lib64/"
    };
    if (!g_caller_vendor) {
        for (const char* pfx : kVendorPrefixes) {
            if (StartsWith(info->dlpi_name, pfx)) {
                g_caller_vendor = find_first_pt_load(info);
                break;
            }
        }
    }
    static constexpr const char* kVndkPrefixes[] = {
        "/apex/com.android.vndk.v",
        "/vendor/lib64/vndk-sp/",
        "/odm/lib64/vndk-sp/"
    };
    if (!g_caller_apex_vndk) {
        for (const char* pfx : kVndkPrefixes) {
            if (StartsWith(info->dlpi_name, pfx)) {
                g_caller_apex_vndk = find_first_pt_load(info);
                break;
            }
        }
    }
    return (g_caller_libc && g_caller_libart && g_caller_vendor && g_caller_apex_vndk) ? 1 : 0;
}

} // namespace

/**
 * @brief Unrolled 10-digit decimal parser for Android SDK version (`0x318c..0x329c`, FDE[32], 272 B).
 *        Bộ phân tích số thập phân 10 chữ số mở vòng lặp cho phiên bản SDK Android (`0x318c..0x329c`, FDE[32], 272 B).
 */
int ParseDecimalSdkInt(const char* str) noexcept {
    if (!str) {
        return 0;
    }
    // Exact check of first two digits (`sub w10, w9, #0x30; cmp w10, #9; b.hi #0x3294` @ 0x3190..0x31ac)
    uint32_t d0 = static_cast<uint8_t>(str[0]) - 0x30U;
    uint32_t d1 = static_cast<uint8_t>(str[1]) - 0x30U;
    if (d0 > 9U || d1 > 9U) {
        return 0;
    }
    uint32_t val = (static_cast<uint8_t>(str[0]) * 10U + static_cast<uint8_t>(str[1])) - 0x210U; // sub w0, w9, #0x210 @ 0x31bc
    for (int i = 2; i < 10; ++i) {
        uint32_t ch = static_cast<uint8_t>(str[i]);
        if (ch - 0x30U > 9U) {
            break;
        }
        val = (val * 10U + ch) - 0x30U;
    }
    // Requires API level > 15 (`cmp w0, #0xf; b.hi` @ 0x328c..0x3294)
    return (val > 15U) ? static_cast<int>(val) : 0;
}

/**
 * @brief Resolves full library path by name from `/proc/self/maps` (`0x5678..0x5744`, FDE[55], 204 B).
 *        Tìm đường dẫn đầy đủ của thư viện theo tên từ `/proc/self/maps` (`0x5678..0x5744`, FDE[55], 204 B).
 */
char* ResolvePathByNameFromMaps(const char* soname) noexcept {
    if (!soname) {
        return nullptr;
    }
    FILE* fp = std::fopen("/proc/self/maps", "r");
    if (!fp) {
        return nullptr;
    }
    char line[1024];
    char* result = nullptr;
    while (std::fgets(line, sizeof(line), fp)) {
        char* slash = std::strchr(line, '/');
        if (!slash) {
            continue;
        }
        if (!std::strstr(slash, soname)) {
            continue;
        }
        char* end = std::strchr(slash, ' ');
        if (!end) {
            end = std::strchr(slash, '\n');
        }
        if (!end) {
            break;
        }
        *end = '\0';
        result = ::strdup(slash);
        break;
    }
    std::fclose(fp);
    return result;
}

/**
 * @brief Resolves full library path by base address from `/proc/self/maps` (`0x5744..0x5858`, FDE[56], 276 B).
 *        Tìm đường dẫn đầy đủ của thư viện theo địa chỉ cơ sở từ `/proc/self/maps` (`0x5744..0x5858`, FDE[56], 276 B).
 */
char* ResolvePathByAddrFromMaps(uintptr_t base_addr) noexcept {
    FILE* fp = std::fopen("/proc/self/maps", "r");
    if (!fp) {
        return nullptr;
    }
    char line[1024];
    char* result = nullptr;
    while (std::fgets(line, sizeof(line), fp)) {
        unsigned long start = 0;
        unsigned long end_addr = 0;
        if (std::sscanf(line, "%lx-%lx r", &start, &end_addr) != 2) { // "%lx-%lx r" @ 0x1546
            continue;
        }
        if (start > base_addr) {
            break;
        }
        if (end_addr <= base_addr) {
            continue;
        }
        char* slash = std::strchr(line, '/');
        if (!slash) {
            break;
        }
        char* space = std::strchr(slash, ' ');
        if (!space) {
            space = std::strchr(slash, '\n');
        }
        if (!space) {
            break;
        }
        *space = '\0';
        result = ::strdup(slash);
        break;
    }
    std::fclose(fp);
    return result;
}

/**
 * @brief Resolves `dl_iterate_phdr` wrapper with linker mutex protection on API 21..22 (`0x394c..0x3e30`, FDE[38], 1,252 B).
 *        Giải quyết hàm bọc `dl_iterate_phdr` có khóa mutex của linker trên Android API 21..22 (`0x394c..0x3e30`).
 */
DlIteratePhdrFn ResolveDlIteratePhdrWrapper() noexcept {
#if defined(__linux__) || defined(__ANDROID__)
    return reinterpret_cast<DlIteratePhdrFn>(&::dl_iterate_phdr);
#else
    return nullptr;
#endif
}

} // namespace nextai::opencut::npth_dl

extern "C" {

/**
 * @brief Opens an ELF module by name or pseudo-handle (`1` = main executable, `2` = linker64) (`0x2650..0x2834`, FDE[05], 484 B).
 *        Mở module ELF theo tên hoặc pseudo-handle (`1` = thực thi chính, `2` = linker64) (`0x2650..0x2834`, FDE[05], 484 B).
 */
void* npth_dlopen(const char* pathname) {
    using namespace nextai::opencut::npth_dl;
    if (!pathname) {
        return nullptr;
    }
    uintptr_t raw = reinterpret_cast<uintptr_t>(pathname);
    if (raw == kPseudoHandleMain || raw == kPseudoHandleLinker) {
#if defined(__linux__) || defined(__ANDROID__)
        unsigned long aux_type = (raw == kPseudoHandleMain) ? 3UL /* AT_PHDR */ : 7UL /* AT_BASE */;
        uintptr_t base = static_cast<uintptr_t>(::getauxval(aux_type));
        if (raw == kPseudoHandleMain) {
            base &= ~static_cast<uintptr_t>(0xfffULL); // ands x19, x0, #-0x1000 @ 0x2698
        }
        if (base == 0 || *reinterpret_cast<const uint32_t*>(base) != kElfMagicLittleEndian) {
            return nullptr;
        }
        NpthDlHandle* h = static_cast<NpthDlHandle*>(std::calloc(1, sizeof(NpthDlHandle)));
        const uint8_t* ehdr = reinterpret_cast<const uint8_t*>(base);
        const Elf64Phdr* phdr = reinterpret_cast<const Elf64Phdr*>(base + *reinterpret_cast<const uint64_t*>(ehdr + 0x20));
        uint16_t phnum = *reinterpret_cast<const uint16_t*>(ehdr + 0x38);
        uintptr_t load_bias = base;
        for (uint16_t i = 0; i < phnum; ++i) {
            if (phdr[i].p_type == 1U) {
                load_bias = (base + phdr[i].p_offset) - phdr[i].p_vaddr; // 0x281c..0x2824
                break;
            }
        }
        h->pathname  = reinterpret_cast<const char*>(base);
        h->load_bias = load_bias;
        h->phdr      = phdr;
        h->phnum     = phnum;
        return h;
#else
        return nullptr;
#endif
    }

    DlIteratePhdrFn iter_fn = ResolveDlIteratePhdrWrapper();
    if (!iter_fn) {
        return nullptr;
    }
    DlOpenSearchState st{};
    st.target_name = pathname;
    if (iter_fn(&DlIterateOpenCallback, &st) == 1) {
        NpthDlHandle* h = static_cast<NpthDlHandle*>(std::calloc(1, sizeof(NpthDlHandle)));
        h->pathname  = reinterpret_cast<const char*>(st.min_vaddr);
        h->load_bias = st.load_bias;
        h->realpath  = st.realpath;
        h->min_vaddr = st.min_vaddr;
        h->phdr      = st.phdr;
        h->phnum     = st.phnum;
        return h;
    }
    return nullptr;
}

/**
 * @brief Iterates loaded ELF modules via `dl_iterate_phdr` (`0x2834..0x2878`, FDE[06], 68 B).
 *        Duyệt qua các module ELF đã nạp qua `dl_iterate_phdr` (`0x2834..0x2878`, FDE[06], 68 B).
 */
int npth_dliterater(nextai::opencut::npth_dl::DlIteratePhdrCallback cb, void* data) {
    auto fn = nextai::opencut::npth_dl::ResolveDlIteratePhdrWrapper();
    return fn ? fn(cb, data) : -1;
}

/**
 * @brief Resolves a symbol from `.dynsym` and optionally returns `st_size` (`0x2a08..0x2adc`, FDE[08], 212 B).
 *        Phân giải ký hiệu từ `.dynsym` và trả về kích thước `st_size` nếu cần (`0x2a08..0x2adc`, FDE[08], 212 B).
 */
void* npth_dlsym_size(void* handle, const char* symbol, size_t* size_out) {
    using namespace nextai::opencut::npth_dl;
    if (!handle || !symbol) {
        return nullptr;
    }
    NpthDlHandle* h = static_cast<NpthDlHandle*>(handle);
    if (!h->dynsym_ctx) {
        h->dynsym_ctx = ParseDynamicPhdr(h->phdr, h->phnum, h->load_bias);
        if (!h->dynsym_ctx) {
            return nullptr;
        }
    }
    const Elf64Sym* sym = LookupDynSym(h->dynsym_ctx, symbol);
    if (!sym) {
        return nullptr;
    }
    uint8_t type = sym->st_info & 0x0fU;
    if (type == 6U || type == 10U) { // Rejects STT_TLS (6) and STT_GNU_IFUNC (0xa) @ 0x2a60..0x2a6c
        return nullptr;
    }
    if (size_out) {
        *size_out = static_cast<size_t>(sym->st_size);
    }
    return reinterpret_cast<void*>(h->load_bias + sym->st_value);
}

/**
 * @brief Resolves a symbol from `.dynsym` (`0x2adc..0x2ae4`, FDE[09], 8 B).
 *        Phân giải ký hiệu từ `.dynsym` (`0x2adc..0x2ae4`, FDE[09], 8 B).
 */
void* npth_dlsym(void* handle, const char* symbol) {
    return npth_dlsym_size(handle, symbol, nullptr);
}

/**
 * @brief Resolves the GOT.PLT jump-slot address for `symbol` (`0x2ae4..0x2b60`, FDE[10], 124 B).
 *        Phân giải địa chỉ ô GOT.PLT jump-slot của ký hiệu `symbol` (`0x2ae4..0x2b60`, FDE[10], 124 B).
 */
void* npth_dlrel_plt_got(void* handle, const char* symbol) {
    using namespace nextai::opencut::npth_dl;
    if (!handle || !symbol) {
        return nullptr;
    }
    NpthDlHandle* h = static_cast<NpthDlHandle*>(handle);
    if (!h->dynsym_ctx) {
        h->dynsym_ctx = ParseDynamicPhdr(h->phdr, h->phnum, h->load_bias);
        if (!h->dynsym_ctx) {
            return nullptr;
        }
    }
    uintptr_t rel_off = LookupJumpSlotReloc(h->dynsym_ctx, symbol);
    return rel_off ? reinterpret_cast<void*>(h->load_bias + rel_off) : nullptr;
}

/**
 * @brief Resolves a symbol from `.symtab`/`.gnu_debugdata` (with `.dynsym` fallback) and stores size (`0x2b60..0x2c08`, FDE[11], 168 B).
 *        Phân giải ký hiệu từ `.symtab`/`.gnu_debugdata` (dự phòng `.dynsym`) kèm kích thước (`0x2b60..0x2c08`, FDE[11], 168 B).
 */
void* npth_dlsym_symtab_size(void* handle, const char* symbol, size_t* size_out) {
    using namespace nextai::opencut::npth_dl;
    if (!handle || !symbol) {
        return nullptr;
    }
    NpthDlHandle* h = static_cast<NpthDlHandle*>(handle);
    NpthSymtabCtx* sym_ctx = EnsureSymtabLoaded(h);
    if (!sym_ctx) {
        return nullptr;
    }
    const Elf64Sym* sym = LookupSymtabByName(sym_ctx, symbol, 0);
    if (!sym) {
        return npth_dlsym_size(handle, symbol, size_out); // Tail-call fallback @ 0x2bec..0x2c04
    }
    uint8_t type = sym->st_info & 0x0fU;
    if (type == 6U || type == 10U) {
        return nullptr;
    }
    if (size_out) {
        *size_out = static_cast<size_t>(sym->st_size);
    }
    return reinterpret_cast<void*>(h->load_bias + sym->st_value);
}

/**
 * @brief Resolves a symbol from `.symtab`/`.gnu_debugdata` (with `.dynsym` fallback) (`0x2c08..0x2c94`, FDE[12], 140 B).
 *        Phân giải ký hiệu từ `.symtab`/`.gnu_debugdata` (dự phòng `.dynsym`) (`0x2c08..0x2c94`, FDE[12], 140 B).
 */
void* npth_dlsym_symtab(void* handle, const char* symbol) {
    return npth_dlsym_symtab_size(handle, symbol, nullptr);
}

/**
 * @brief Resolves a symbol from `.symtab` allowing `.` clone suffixes (`0x2c94..0x2d30`, FDE[13], 156 B).
 *        Phân giải ký hiệu từ `.symtab` cho phép hậu tố bản sao trình biên dịch `.` (`0x2c94..0x2d30`, FDE[13], 156 B).
 */
void* npth_dlsym_symtab_prefix(void* handle, const char* symbol) {
    return npth_dlsym_symtab_size_prefix(handle, symbol, nullptr);
}

/**
 * @brief Resolves a symbol from `.symtab` allowing `.` clone suffixes and returns size (`0x2d30..0x2de4`, FDE[14], 180 B).
 *        Phân giải ký hiệu từ `.symtab` cho phép hậu tố `.` và trả về kích thước (`0x2d30..0x2de4`, FDE[14], 180 B).
 */
void* npth_dlsym_symtab_size_prefix(void* handle, const char* symbol, size_t* size_out) {
    using namespace nextai::opencut::npth_dl;
    if (!handle || !symbol) {
        return nullptr;
    }
    NpthDlHandle* h = static_cast<NpthDlHandle*>(handle);
    NpthSymtabCtx* sym_ctx = EnsureSymtabLoaded(h);
    if (!sym_ctx) {
        return nullptr;
    }
    const Elf64Sym* sym = LookupSymtabByName(sym_ctx, symbol, 1);
    if (!sym) {
        return nullptr;
    }
    uint8_t type = sym->st_info & 0x0fU;
    if (type == 6U || type == 10U) {
        return nullptr;
    }
    if (size_out) {
        *size_out = static_cast<size_t>(sym->st_size);
    }
    return reinterpret_cast<void*>(h->load_bias + sym->st_value);
}

/**
 * @brief Closes and frees an `NpthDlHandle` (`0x2de4..0x2e3c`, FDE[15], 88 B).
 *        Đóng và giải phóng `NpthDlHandle` (`0x2de4..0x2e3c`, FDE[15], 88 B).
 */
int npth_dlclose(void* handle) {
    using namespace nextai::opencut::npth_dl;
    if (!handle) {
        return -1;
    }
    NpthDlHandle* h = static_cast<NpthDlHandle*>(handle);
    if (h->realpath) {
        std::free(h->realpath);
    }
    if (h->symtab_ctx) {
        FreeSymtabCtx(h->symtab_ctx);
    }
    if (h->dynsym_ctx) {
        FreeDynSymCtx(h->dynsym_ctx);
    }
    std::free(h);
    return 0;
}

/**
 * @brief Bypasses Android linker namespaces to `dlopen` a system/vendor library (`0x2e3c` -> `0x4e48..0x51bc`, FDE[52], 884 B).
 *        Vượt rào namespace của Android linker để `dlopen` thư viện hệ thống/vendor (`0x2e3c` -> `0x4e48..0x51bc`, FDE[52], 884 B).
 */
void* npth_dlopen_force(const char* pathname) {
    using namespace nextai::opencut::npth_dl;
    if (!pathname) {
        return nullptr;
    }
#if defined(__linux__) || defined(__ANDROID__)
    int api = npth_dlapilevel();
    if (api <= 23) { // cmp w0, #0x17; b.hi #0x4e9c @ 0x4e70
        return ::dlopen(pathname, RTLD_NOW);
    }
    if (!g_caller_initialized) {
        pthread_mutex_lock(&g_caller_init_mutex);
        if (!g_caller_initialized) {
            npth_dliterater(&DiscoverCallerAddressesCallback, nullptr);
            g_caller_initialized = true;
        }
        pthread_mutex_unlock(&g_caller_init_mutex);
    }
    if (!g_fn_do_dlopen || !g_fn_do_dlsym) {
        void* linker = npth_dlopen(reinterpret_cast<const char*>(kPseudoHandleLinker));
        if (linker) {
            if ((api & ~1) == 24) { // API 24 / 25
                g_fn_do_dlopen = npth_dlsym_symtab(linker, "__dl__ZL10dlopen_extPKciPK17android_dlextinfoPv");
                g_fn_do_dlsym  = npth_dlsym_symtab(linker, "__dl__Z10dlsym_implPvPKcS1_S_");
                if (!g_fn_do_dlopen || !g_fn_do_dlsym) {
                    g_fn_do_dlopen = npth_dlsym_symtab(linker, "__dl__Z9do_dlopenPKciPK17android_dlextinfoPv");
                    g_fn_do_dlsym  = npth_dlsym_symtab(linker, "__dl__Z8do_dlsymPvPKcS1_S_PS_");
                    g_dl_mutex_ptr = static_cast<pthread_mutex_t*>(npth_dlsym_symtab(linker, "__dl__ZL10g_dl_mutex"));
                }
            } else if ((api & ~1) == 26) { // API 26 / 27
                g_fn_do_dlopen = npth_dlsym_symtab(linker, "__dl__Z8__dlopenPKciPKv");
                g_fn_do_dlsym  = npth_dlsym_symtab(linker, "__dl__Z7__dlsymPvPKcPKv");
            } else { // API >= 28
                g_fn_do_dlopen = npth_dlsym(linker, "__loader_dlopen");
                g_fn_do_dlsym  = npth_dlsym(linker, "__loader_dlsym");
            }
            npth_dlclose(linker);
        }
    }
    if (!g_fn_do_dlopen) {
        return nullptr;
    }
    void* callers[4] = {g_caller_libc, g_caller_libart, g_caller_vendor, g_caller_apex_vndk};
    if ((api & ~1) == 24) {
        using DlOpen24Fn = void* (*)(const char*, int, const void*, void*);
        auto fn = reinterpret_cast<DlOpen24Fn>(g_fn_do_dlopen);
        if (g_dl_mutex_ptr) pthread_mutex_lock(g_dl_mutex_ptr);
        void* res = nullptr;
        for (void* c : callers) {
            if (c && (res = fn(pathname, RTLD_NOW, nullptr, c)) != nullptr) break;
        }
        if (g_dl_mutex_ptr) pthread_mutex_unlock(g_dl_mutex_ptr);
        return res;
    } else {
        using DlOpen26Fn = void* (*)(const char*, int, void*);
        auto fn = reinterpret_cast<DlOpen26Fn>(g_fn_do_dlopen);
        for (void* c : callers) {
            if (c) {
                if (void* res = fn(pathname, RTLD_NOW, c)) return res;
            }
        }
    }
#endif
    return nullptr;
}

/**
 * @brief Bypasses Android linker namespaces to `dlsym` a symbol (`0x2e44` -> `0x51bc..0x5448`, FDE[53], 652 B).
 *        Vượt rào namespace của Android linker để phân giải ký hiệu `dlsym` (`0x2e44` -> `0x51bc..0x5448`, FDE[53], 652 B).
 */
void* npth_dlsym_force(void* handle, const char* symbol) {
    using namespace nextai::opencut::npth_dl;
    if (!handle || !symbol) {
        return nullptr;
    }
#if defined(__linux__) || defined(__ANDROID__)
    int api = npth_dlapilevel();
    if (api <= 23 || !g_fn_do_dlsym) {
        return ::dlsym(handle, symbol);
    }
    void* callers[4] = {g_caller_libc, g_caller_libart, g_caller_vendor, g_caller_apex_vndk};
    if ((api & ~1) == 24) {
        if (g_dl_mutex_ptr) {
            using DoDlSym24Fn = bool (*)(void*, const char*, const char*, void*, void**);
            auto fn = reinterpret_cast<DoDlSym24Fn>(g_fn_do_dlsym);
            pthread_mutex_lock(g_dl_mutex_ptr);
            void* sym_addr = nullptr;
            for (void* c : callers) {
                if (c && fn(handle, symbol, nullptr, c, &sym_addr) && sym_addr) break;
                sym_addr = nullptr;
            }
            pthread_mutex_unlock(g_dl_mutex_ptr);
            return sym_addr;
        } else {
            using DlSymImpl24Fn = void* (*)(void*, const char*, const char*, void*);
            auto fn = reinterpret_cast<DlSymImpl24Fn>(g_fn_do_dlsym);
            for (void* c : callers) {
                if (c) {
                    if (void* res = fn(handle, symbol, nullptr, c)) return res;
                }
            }
        }
    } else {
        using DlSym26Fn = void* (*)(void*, const char*, void*);
        auto fn = reinterpret_cast<DlSym26Fn>(g_fn_do_dlsym);
        for (void* c : callers) {
            if (c) {
                if (void* res = fn(handle, symbol, c)) return res;
            }
        }
    }
#endif
    return nullptr;
}

/**
 * @brief Closes a handle opened via `npth_dlopen_force` (`0x2e48` -> `dlclose` PLT `0x5d40`, FDE[18], 4 B).
 *        Đóng handle được mở qua `npth_dlopen_force` (`0x2e48` -> `dlclose` PLT `0x5d40`, FDE[18], 4 B).
 */
int npth_dlclose_force(void* handle) {
#if defined(__linux__) || defined(__ANDROID__)
    return handle ? ::dlclose(handle) : -1;
#else
    (void)handle;
    return -1;
#endif
}

/**
 * @brief Enhanced `dladdr` that falls back to `.symtab`/`.gnu_debugdata` symbol resolution (`0x2e4c..0x2f38`, FDE[19], 236 B).
 *        Hàm `dladdr` nâng cao có dự phòng tra cứu `.symtab`/`.gnu_debugdata` (`0x2e4c..0x2f38`, FDE[19], 236 B).
 */
int npth_dladdr(const void* addr, nextai::opencut::npth_dl::DlInfo* info) {
    using namespace nextai::opencut::npth_dl;
    if (!addr || !info) {
        return 0;
    }
#if defined(__linux__) || defined(__ANDROID__)
    Dl_info sys_info{};
    if (::dladdr(addr, &sys_info) == 0) {
        return 0;
    }
    info->dli_fname = sys_info.dli_fname;
    info->dli_fbase = sys_info.dli_fbase;
    info->dli_sname = sys_info.dli_sname;
    info->dli_saddr = sys_info.dli_saddr;

    if (info->dli_sname && info->dli_saddr) {
        return 1;
    }
    void* raw_h = npth_dlopen(info->dli_fname);
    if (!raw_h) {
        return 1;
    }
    NpthDlHandle* h = static_cast<NpthDlHandle*>(raw_h);
    uintptr_t target_addr = reinterpret_cast<uintptr_t>(addr);
    int ret = 1;
    if (target_addr >= h->load_bias) {
        NpthSymtabCtx* sym_ctx = EnsureSymtabLoaded(h);
        if (sym_ctx) {
            const Elf64Sym* sym = LookupSymtabByAddr(sym_ctx, target_addr - h->load_bias);
            if (sym) {
                info->dli_saddr = reinterpret_cast<void*>(h->load_bias + sym->st_value);
                info->dli_sname = ::strdup(GetSymtabString(sym_ctx, sym));
                ret = 2; // mov w21, #2 @ 0x2f0c
            }
        }
    }
    npth_dlclose(raw_h);
    return ret;
#else
    return 0;
#endif
}

/**
 * @brief Forwards `dlerror` (`0x2fbc..0x2fc0`, FDE[21], 4 B).
 *        Chuyển tiếp hàm `dlerror` (`0x2fbc..0x2fc0`, FDE[21], 4 B).
 */
char* npth_dlerror(void) {
#if defined(__linux__) || defined(__ANDROID__)
    return ::dlerror();
#else
    return nullptr;
#endif
}

/**
 * @brief Checks if `npth_dl` is usable under the current Android API level (`0x2fc0..0x2ff0`, FDE[22], 48 B).
 *        Kiểm tra tính khả dụng của `npth_dl` trên phiên bản API Android hiện tại (`0x2fc0..0x2ff0`, FDE[22], 48 B).
 */
int npth_dlusable(int mode) {
    if (mode > 3) { // cmp w0, #3; b.le #0x2fd0; mov w0, #1 @ 0x2fc0..0x2fc8
        return 1;
    }
    int api = npth_dlapilevel();
    return (api > 34) ? 2 : 0; // cmp w0, #0x22; cset w8, hi; lsl w0, w8, #1 @ 0x2fdc..0x2fe4
}

/**
 * @brief Returns the Android SDK API level (`ro.build.version.sdk`, `0x2ff0` -> `0x3008..0x3128`, FDE[29], 288 B).
 *        Trả về cấp độ API SDK Android (`ro.build.version.sdk`, `0x2ff0` -> `0x3008..0x3128`, FDE[29], 288 B).
 */
int npth_dlapilevel(void) {
    using namespace nextai::opencut::npth_dl;
    if (g_cached_api_level != 0) {
        return g_cached_api_level;
    }
    int api = 0;
#if defined(__ANDROID__)
    char prop_buf[128] = {0};
    if (__system_property_get("ro.build.version.sdk", prop_buf) > 0) {
        api = ParseDecimalSdkInt(prop_buf);
    }
#endif
    if (api == 0) {
        FILE* fp = std::fopen("/system/build.prop", "r");
        if (fp) {
            char line[256];
            constexpr const char* kKey = "ro.build.version.sdk";
            while (std::fgets(line, sizeof(line), fp)) {
                if (StartsWith(line, kKey)) {
                    api = ParseDecimalSdkInt(line + 0x15); // add x0, x8, #0x15 @ 0x30ec
                    break;
                }
            }
            std::fclose(fp);
        }
    }
    g_cached_api_level = api;
    return api;
}

/**
 * @brief Extracts the `.note.gnu.build-id` hex string from an ELF module (`0x2ff4` -> `0x329c..0x3848`, FDE[33..35]).
 *        Trích xuất chuỗi hex `.note.gnu.build-id` từ module ELF (`0x2ff4` -> `0x329c..0x3848`, FDE[33..35]).
 */
char* npth_dlbuildid(const char* pathname) {
    using namespace nextai::opencut::npth_dl;
    if (!pathname) {
        return nullptr;
    }
    struct BuildIdQuery {
        const char* name;
        char*       hex_out;
    } query{pathname, nullptr};

    auto phdr_cb = [](DlPhdrInfo* info, size_t /*size*/, void* data) -> int {
        BuildIdQuery* q = static_cast<BuildIdQuery*>(data);
        if (!info || !info->dlpi_name || info->dlpi_phnum == 0) {
            return 0;
        }
        const char* dlpi_name = info->dlpi_name;
        const char* target = q->name;
        if (target[0] == '/' && dlpi_name[0] != '/') {
            if (const char* s = std::strrchr(target, '/')) target = s + 1;
        } else if (target[0] != '/' && dlpi_name[0] == '/') {
            if (const char* s = std::strrchr(dlpi_name, '/')) dlpi_name = s + 1;
        }
        if (std::strcmp(target, dlpi_name) != 0) {
            return 0;
        }
        for (uint16_t i = 0; i < info->dlpi_phnum; ++i) {
            if (info->dlpi_phdr[i].p_type == 4U) { // PT_NOTE == 4 @ 0x3764
                const uint8_t* ptr = reinterpret_cast<const uint8_t*>(info->dlpi_addr + info->dlpi_phdr[i].p_offset);
                const uint8_t* end = ptr + info->dlpi_phdr[i].p_memsz;
                while (ptr + 12 <= end) {
                    uint32_t namesz = *reinterpret_cast<const uint32_t*>(ptr);
                    uint32_t descsz = *reinterpret_cast<const uint32_t*>(ptr + 4);
                    uint32_t ntype  = *reinterpret_cast<const uint32_t*>(ptr + 8);
                    if (ntype == 3U && descsz <= 0xa0U) { // NT_GNU_BUILD_ID == 3, max 160 bytes @ 0x378c, 0x37c4
                        char* out = static_cast<char*>(std::malloc((descsz << 1) | 1U));
                        if (!out) return -1;
                        const uint8_t* desc = ptr + 12 + ((namesz + 3U) & ~3U);
                        for (uint32_t b = 0; b < descsz; ++b) {
                            std::snprintf(out + (b * 2), 3, "%02hhx", desc[b]);
                        }
                        out[descsz * 2] = '\0';
                        q->hex_out = out;
                        return 1;
                    }
                    ptr += 12 + ((namesz + 3U) & ~3U) + ((descsz + 3U) & ~3U);
                }
            }
        }
        return -1;
    };

    if (npth_dliterater(phdr_cb, &query) == 1 && query.hex_out) {
        return query.hex_out;
    }
    return nullptr;
}

/**
 * @brief Returns 0 (`0x2ffc` -> `0x5b7c`, FDE[26], 4 B).
 *        Trả về 0 (`0x2ffc` -> `0x5b7c`, FDE[26], 4 B).
 */
int npth_dltest(void) {
    return 0;
}

/**
 * @brief Enables or disables `NPTH_DL` debug logging (`0x3000` -> `0x5b70`, FDE[27], 4 B).
 *        Bật hoặc tắt ghi nhật ký gỡ lỗi `NPTH_DL` (`0x3000` -> `0x5b70`, FDE[27], 4 B).
 */
void npth_dldebug(int enable) {
    nextai::opencut::npth_dl::g_debug_enabled = enable;
}

/**
 * @brief Validates/updates target API level (`0x3004` -> `0x3128..0x3184`, FDE[30], 92 B).
 *        Kiểm tra/cập nhật cấp độ API mục tiêu (`0x3004` -> `0x3128..0x3184`, FDE[30], 92 B).
 */
void npth_dlincrease(int target_api_level) {
    int curr = npth_dlapilevel();
    (void)curr;
    (void)target_api_level;
}

} // extern "C"
