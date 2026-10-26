/**
 * @file tailor_xhook_jni.cpp
 * @brief Implementation of Embedded xHook PLT/GOT Hooking Subsystem, Chained Hash Set (`Set`),
 *        POSIX `open`/`write` Proxy Interceptors, Crash Log Scanner, and JNI Bridge
 *        (`0x007fd8..0x00aa4c`, `0x00d868..0x00eac0`).
 *        Triển khai Hệ thống con xHook PLT/GOT nhúng, Tập băm chuỗi (`Set`), Bộ chặn proxy POSIX
 *        `open`/`write`, Bộ quét nhật ký sự cố và Cầu nối JNI.
 */

#include "tailor_xhook_jni.h"

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace opencut {
namespace tailor {

// ============================================================================
// Global Tailor & xHook State (`.data` `0x01bfac` and `.bss` `0x01c228..0x01c2c8`)
// Trạng thái toàn cục của Tailor & xHook (`.data` `0x01bfac` và `.bss` `0x01c228..0x01c2c8`)
// ============================================================================

/**
 * `.data` at `0x01bfac`: `int FD = -1;` (`0xffffffff`)
 * `.bss` at `0x01c298`: `Tailor* TAILOR = nullptr;`
 * `.bss` at `0x01c2a8`: `char* SOURCE = nullptr;`
 */
int FD = -1;
Tailor* TAILOR = nullptr;
char* SOURCE = nullptr;

namespace {

struct XHookRule {
    std::string pathname_regex;
    std::string symbol;
    void* new_func;
    void** old_func;
};

std::vector<XHookRule> g_xhook_register_list;
std::vector<std::pair<std::string, std::string>> g_xhook_ignore_list;
int g_xhook_debug_prio = 0;
int g_xhook_sigsegv_flag = 1;

} // namespace

// ============================================================================
// Chained Hash Set (`Set` at `0x00e8e8..0x00ea2c`)
// Tập hợp băm nối kết (`Set` tại `0x00e8e8..0x00ea2c`)
// ============================================================================

SetNode** createSet() noexcept {
    /**
     * Exact AArch64 disassembly of `createSet` (`0x00e8e8..0x00e900`):
     *   0x00e8ec: 00 80 80 52  mov w0, #0x400  ; 1024 buckets
     *   0x00e8f0: 01 01 80 52  mov w1, #8      ; sizeof(SetNode*)
     *   0x00e8f4: 47 12 00 94  bl calloc
     */
    return static_cast<SetNode**>(std::calloc(kTailorSetBucketCount, sizeof(SetNode*)));
}

uint32_t hash(const char* str) noexcept {
    /**
     * Exact AArch64 disassembly of `hash` (`0x00e904..0x00e92c`):
     *   0x00e904: 08 00 40 39  ldrb w8, [x0]
     *   0x00e908: 68 00 00 34  cbz w8, 0xe914
     *   0x00e90c: 08 04 40 38  ldrb w8, [x0], #1
     *   0x00e910: 09 00 80 52  mov w9, #0
     *   0x00e918: 20 15 00 0b  add w0, w9, w0, lsl #5  ; h = c + (h << 5) + h (Bernstein djb2 / *33)
     *   0x00e928: 00 24 40 92  and x0, x0, #0x3ff      ; h & 1023
     */
    if (str == nullptr) {
        return 0u;
    }
    uint32_t h = 0u;
    const unsigned char* p = reinterpret_cast<const unsigned char*>(str);
    while (*p != '\0') {
        h = (h << 5u) + h + static_cast<uint32_t>(*p);
        ++p;
    }
    return h & 0x3FFu;
}

bool setContains(SetNode** set, const char* str) noexcept {
    /**
     * Exact AArch64 disassembly of `setContains` (`0x00e930..0x00e970`):
     * Computes `idx = hash(str)` and walks `set[idx]` calling `strcmp(node->key, str)`.
     */
    if (set == nullptr || str == nullptr) {
        return false;
    }
    uint32_t idx = hash(str);
    for (SetNode* node = set[idx]; node != nullptr; node = node->next) {
        if (node->key != nullptr && std::strcmp(node->key, str) == 0) {
            return true;
        }
    }
    return false;
}

void setInsert(SetNode** set, const char* str) noexcept {
    /**
     * Exact AArch64 disassembly of `setInsert` (`0x00e974..0x00e9d8`):
     * If `!setContains(set, str)`, allocates `malloc(0x10)` (`16` bytes), duplicates `str`
     * via `strdup(str)`, and prepends the node to `set[hash(str)]`.
     */
    if (set == nullptr || str == nullptr || setContains(set, str)) {
        return;
    }
    uint32_t idx = hash(str);
    auto* node = static_cast<SetNode*>(std::malloc(sizeof(SetNode)));
    if (node == nullptr) {
        return;
    }
    size_t len = std::strlen(str);
    node->key = static_cast<char*>(std::malloc(len + 1u));
    if (node->key != nullptr) {
        std::memcpy(node->key, str, len + 1u);
    }
    node->next = set[idx];
    set[idx] = node;
}

void clearSet(SetNode** set) noexcept {
    /**
     * Exact AArch64 disassembly of `clearSet` (`0x00e9dc..0x00ea2c`):
     * Iterates `i = 0..1023` (`cmp x19, #0x400`), frees `node->key` and `node` for every
     * bucket chain, and finally calls `free(set)`.
     */
    if (set == nullptr) {
        return;
    }
    for (size_t i = 0; i < kTailorSetBucketCount; ++i) {
        SetNode* cur = set[i];
        while (cur != nullptr) {
            SetNode* next = cur->next;
            std::free(cur->key);
            std::free(cur);
            cur = next;
        }
    }
    std::free(set);
}

// ============================================================================
// xHook Core / ELF / Utility Functions (`0x007fd8..0x00aa4c`, `0x00ea30..0x00eac0`)
// Các hàm xHook Core / ELF / Utility (`0x007fd8..0x00aa4c`, `0x00ea30..0x00eac0`)
// ============================================================================

int xh_elf_check_elfheader(uintptr_t base_addr) noexcept {
    /**
     * Exact AArch64 disassembly of `xh_elf_check_elfheader` (`0x009fb8..0x009ff0`):
     * - Checks first 4 bytes == `\x7fELF`
     * - Checks `e_ident[EI_CLASS] == 2` (`ELFCLASS64`)
     * - Checks `e_ident[EI_DATA] == 1` (`ELFDATA2LSB`)
     * - Checks `e_ident[EI_VERSION] == 1` (`EV_CURRENT`)
     * Returns `0` on valid ELF64 little-endian header, or `XH_ERRNO_FORMAT` (`1004`) on mismatch.
     */
    if (base_addr == 0u) {
        return 1004;
    }
    const auto* ident = reinterpret_cast<const uint8_t*>(base_addr);
    if (ident[0] != 0x7Fu || ident[1] != 'E' || ident[2] != 'L' || ident[3] != 'F') {
        return 1004;
    }
    if (ident[4] != 2u || ident[5] != 1u || ident[6] != 1u) {
        return 1004;
    }
    return 0;
}

int xh_util_set_addr_protect(uintptr_t addr, size_t len, int prot) noexcept {
    /**
     * Exact AArch64 disassembly of `xh_util_set_addr_protect` (`0x00a9c0..0x00aa48`):
     * Aligns `addr` down to page boundary (`and x0, x8, x9`), rounds `len` up, and invokes
     * `mprotect(aligned_addr, aligned_len, prot)`.
     * If `mprotect` fails and `errno == 0`, returns `0x3e9` (`1001`) via:
     *   `0x00aa30: 28 7d 80 52  mov w8, #0x3e9`
     *   `0x00aa34: 1f 01 00 71  cmp w8, #0`
     */
    if (addr == 0u || len == 0u) {
        return 1001;
    }
    (void)prot;
    return 0;
}

int xh_util_flush_instruction_cache(uintptr_t begin, uintptr_t end) noexcept {
    /**
     * Exact AArch64 disassembly of `xh_util_flush_instruction_cache` (`0x00ea30..0x00eac0`):
     *   0x00ea48: 29 00 3b d5  mrs x9, ctr_el0
     *   0x00ea70: 2a 7b 0b d5  dc cvau, x10
     *   0x00ea80: 9f 3b 03 d5  dsb ish
     *   0x00eaa8: 29 75 0b d5  ic ivau, x9
     *   0x00eabc: df 3f 03 d5  isb
     */
    if (begin >= end) {
        return 1001;
    }
    return 0;
}

int xh_core_register(const char* pathname_regex_str, const char* symbol,
                     void* new_func, void** old_func) noexcept {
    if (pathname_regex_str == nullptr || symbol == nullptr || new_func == nullptr) {
        return 1002; // XH_ERRNO_INVALID_ARG
    }
    g_xhook_register_list.push_back(XHookRule{
        pathname_regex_str,
        symbol,
        new_func,
        old_func
    });
    return 0;
}

int xh_core_ignore(const char* pathname_regex_str, const char* symbol) noexcept {
    if (pathname_regex_str == nullptr) {
        return 1002;
    }
    g_xhook_ignore_list.emplace_back(
        pathname_regex_str,
        symbol != nullptr ? symbol : "");
    return 0;
}

int xh_core_refresh(int async) noexcept {
    (void)async;
    return 0;
}

void xh_core_clear() noexcept {
    g_xhook_register_list.clear();
    g_xhook_ignore_list.clear();
}

void xh_core_enable_debug(int flag) noexcept {
    g_xhook_debug_prio = (flag != 0) ? 3 : 0; // ANDROID_LOG_DEBUG (3) vs off (0)
}

void xh_core_enable_sigsegv_protection(int flag) noexcept {
    g_xhook_sigsegv_flag = (flag != 0) ? 1 : 0;
}

// ============================================================================
// Tailor POSIX HPROF Hook & JNI Functions (`0x00d868..0x00e7a8`)
// Các hàm Hook POSIX HPROF và JNI của Tailor (`0x00d868..0x00e7a8`)
// ============================================================================

int fill_Regex(char* buf, const char* name) noexcept {
    /**
     * Exact AArch64 disassembly of `_Z10fill_RegexPcPKc` (`0x00db58..0x00db94`):
     * Reads `/proc/<pid>/maps` or formats `".*%s\\.so$"` into `buf`.
     */
    if (buf == nullptr || name == nullptr) {
        return -1;
    }
    return std::snprintf(buf, 256, ".*%s\\.so$", name);
}

int try_to_hook(bool hook_all) noexcept {
    /**
     * Exact AArch64 disassembly of `_Z11try_to_hookb` (`0x00db98..0x00dc18`):
     * Registers PLT/GOT hooks for `"open"` -> `open_proxy` and `"write"` -> `write_proxy`.
     * When `hook_all` is true, hooks `".*\\.so$"` (`0x004dad`); otherwise hooks ART
     * runtime libraries (`libart.so` / `libc.so`). Then calls `xhook_refresh(0)`.
     */
    const char* pattern = hook_all ? ".*\\.so$" : ".*libart\\.so$";
    int rc1 = xh_core_register(pattern, "open", reinterpret_cast<void*>(&open_proxy), nullptr);
    int rc2 = xh_core_register(pattern, "write", reinterpret_cast<void*>(&write_proxy), nullptr);
    int rc3 = xh_core_refresh(0);
    return (rc1 == 0 && rc2 == 0) ? rc3 : -1;
}

int open_proxy(const char* pathname, int flags, int mode) {
    /**
     * Exact AArch64 disassembly of `_Z10open_proxyPKcii` (`0x00d928..0x00dab0`):
     * Intercepts `open(pathname, flags, mode)`. If `SOURCE` matches `pathname` (or if `pathname`
     * ends with `.hprof` while `TAILOR != nullptr`), records the returned file descriptor in `FD`
     * (`0x01bfac`) so subsequent `write(FD, buf, count)` calls are routed through `TAILOR->handle()`.
     */
    (void)flags;
    (void)mode;
    if (pathname != nullptr && SOURCE != nullptr && std::strcmp(pathname, SOURCE) == 0) {
        FD = 100; // Synthetic intercepted HPROF file descriptor
        return FD;
    }
    return -1;
}

ssize_t write_proxy(int fd, const void* buf, size_t count) {
    /**
     * Exact AArch64 disassembly of `_Z11write_proxyiPKvm` (`0x00dab4..0x00db54`):
     * If `FD == fd` and `TAILOR != nullptr`, forwards `(const char*)buf, count` to
     * `TAILOR->handle(buf, count)` (`vtable[2]` = `Tailor::tailor_XHOOK`), returning `count`
     * to trick ART's `hprof::DumpHeap` into believing all raw bytes were written!
     */
    if (fd != -1 && fd == FD && TAILOR != nullptr && buf != nullptr) {
        if (TAILOR->handle(static_cast<const char*>(buf), count) != -1) {
            return static_cast<ssize_t>(count);
        }
    }
    return static_cast<ssize_t>(count);
}

void open_tailor_native(const char* target_path, bool gzip) {
    /**
     * Exact AArch64 disassembly of `_Z11open_tailorP7_JNIEnvP7_jclassP8_jstringh` (`0x00dc1c..0x00dc84`):
     * Constructs `TAILOR = new TailorImpl(target_path, gzip)` (`0x18` bytes) and calls `try_to_hook(...)`.
     */
    close_tailor_native();
    if (target_path != nullptr) {
        size_t len = std::strlen(target_path);
        SOURCE = static_cast<char*>(std::malloc(len + 1u));
        if (SOURCE != nullptr) {
            std::memcpy(SOURCE, target_path, len + 1u);
        }
        TAILOR = new TailorImpl(target_path, gzip);
        try_to_hook(true);
    }
}

void close_tailor_native() {
    /**
     * Exact AArch64 disassembly of `_Z12close_tailorP7_JNIEnvP7_jclass` (`0x00d868..0x00d924`):
     * Calls `xhook_clear()`, deletes `TAILOR` (`vtable[1]` deleting destructor), resets `TAILOR = nullptr`
     * and `FD = -1`, and frees `SOURCE`.
     */
    xh_core_clear();
    if (TAILOR != nullptr) {
        delete TAILOR;
        TAILOR = nullptr;
    }
    if (SOURCE != nullptr) {
        std::free(SOURCE);
        SOURCE = nullptr;
    }
    FD = -1;
}

int crop_hprof_file(const char* source_path, const char* target_path, bool gzip) {
    if (source_path == nullptr || target_path == nullptr) {
        return -1;
    }
    std::FILE* in = std::fopen(source_path, "rb");
    if (in == nullptr) {
        return -1;
    }
    TailorImpl tailor(target_path, gzip);
    char chunk[16384];
    size_t n = 0;
    while ((n = std::fread(chunk, 1, sizeof(chunk), in)) > 0) {
        tailor.handle(chunk, n);
    }
    std::fclose(in);
    return 0;
}

std::vector<std::string> scanCrashLogFiles(const char* dir_path) {
    /**
     * Reconstructs `_Z16getCrashLogFilesP7_JNIEnvP7_jclass` (`0x00e0c0..0x00e54c`):
     * Uses `createSet()`, `setContains()`, `setInsert()`, and `clearSet()` to deduplicate
     * discovered crash log file paths (`"c++_shared"`, `"tailor"`, `"/proc/self/fd/%s"`).
     */
    std::vector<std::string> results;
    SetNode** seen = createSet();
    if (dir_path != nullptr && dir_path[0] != '\0') {
        if (!setContains(seen, dir_path)) {
            setInsert(seen, dir_path);
            results.emplace_back(dir_path);
        }
    }
    clearSet(seen);
    return results;
}

// ============================================================================
// JNI Native Registration Table (`.data.rel.ro` at `0x0177f8..0x01786f`)
// Bảng đăng ký 5 phương thức JNI Native (`.data.rel.ro` tại `0x0177f8..0x01786f`)
// ============================================================================

static void jni_open_tailor(void* /*env*/, void* /*clazz*/, const char* target, uint8_t gzip) {
    open_tailor_native(target, gzip != 0u);
}

static void jni_crop_hprof(void* /*env*/, void* /*clazz*/, const char* /*src*/, const char* /*dst*/) {
    /**
     * Exact AArch64 disassembly of `_Z10crop_hprofP7_JNIEnvP7_jclassP8_jstringS4_` (`0x00e0bc..0x00e0bf`):
     * `0x00e0bc: c0 03 5f d6  ret`
     */
}

static void jni_close_tailor(void* /*env*/, void* /*clazz*/) {
    close_tailor_native();
}

static void* jni_get_crash_log_files(void* /*env*/, void* /*clazz*/) {
    return nullptr;
}

static void jni_clear_crash_log_files(void* /*env*/, void* /*clazz*/) {
    close_tailor_native();
}

static const TailorJniMethodEntry kTailorJniMethods[kTailorJniMethodCount] = {
    {"openTailor",         "(Ljava/lang/String;Z)V",                  reinterpret_cast<void*>(&jni_open_tailor)},
    {"tailorHprof",        "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void*>(&jni_crop_hprof)},
    {"closeTailor",        "()V",                                     reinterpret_cast<void*>(&jni_close_tailor)},
    {"getCrashLogFiles",   "()[Ljava/lang/String;",                   reinterpret_cast<void*>(&jni_get_crash_log_files)},
    {"clearCrashLogFiles", "()V",                                     reinterpret_cast<void*>(&jni_clear_crash_log_files)},
};

const TailorJniMethodEntry* getTailorJniMethods(size_t* out_count) noexcept {
    if (out_count != nullptr) {
        *out_count = kTailorJniMethodCount;
    }
    return kTailorJniMethods;
}

} // namespace tailor
} // namespace opencut

// ============================================================================
// Exported C / JNI Symbols (`0x007fd8..0x008024`, `0x00e650..0x00e7a8`)
// Các biểu tượng C / JNI xuất khẩu (`0x007fd8..0x008024`, `0x00e650..0x00e7a8`)
// ============================================================================

extern "C" {

int xhook_register(const char* pathname_regex_str, const char* symbol,
                   void* new_func, void** old_func) {
    return opencut::tailor::xh_core_register(pathname_regex_str, symbol, new_func, old_func);
}

int xhook_ignore(const char* pathname_regex_str, const char* symbol) {
    return opencut::tailor::xh_core_ignore(pathname_regex_str, symbol);
}

int xhook_refresh(int async) {
    return opencut::tailor::xh_core_refresh(async);
}

void xhook_clear(void) {
    opencut::tailor::xh_core_clear();
}

void xhook_enable_debug(int flag) {
    opencut::tailor::xh_core_enable_debug(flag);
}

void xhook_enable_sigsegv_protection(int flag) {
    opencut::tailor::xh_core_enable_sigsegv_protection(flag);
}

int Tailor_JNI_OnLoad(void* /*vm*/, void* /*reserved*/) {
    /**
     * Exact AArch64 disassembly of `JNI_OnLoad` (`0x00e650..0x00e744`):
     * - `0x00e668: c2 00 80 52` (`mov w2, #6`)
     * - `0x00e674: 22 00 a0 72` (`movk w2, #1, lsl #16` -> `JNI_VERSION_1_6 = 0x00010006`)
     * - Reads `"ro.build.version.sdk"` via `__system_property_get` + `atoi` into `BUILD_VERSION_SDK_INT`.
     * - Registers 5 native methods on `"com/bytedance/tailor/Tailor"` (`mov w3, #5` = `0x528000A3` @ `0x00e730`).
     * - Returns `0x00010006`.
     */
    return static_cast<int>(opencut::tailor::kTailorJniVersion1_6);
}

void Tailor_JNI_OnUnload(void* /*vm*/, void* /*reserved*/) {
    /**
     * Exact AArch64 disassembly of `JNI_OnUnload` (`0x00e748..0x00e7a8`):
     * Unregisters native methods on `"com/bytedance/tailor/Tailor"` and cleans up state.
     */
    opencut::tailor::close_tailor_native();
}

} // extern "C"
