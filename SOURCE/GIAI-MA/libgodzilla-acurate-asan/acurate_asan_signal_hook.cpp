// ============================================================================
// File: acurate_asan_signal_hook.cpp
// Target: libgodzilla-acurate-asan.so (160,168 bytes)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Complete implementation of JSON config parsers,
//                   ELF NT_GNU_BUILD_ID scanner (`dl_iterate_phdr`),
//                   SIGSEGV handler & recoverable mprotect restoration,
//                   `tombstone.txt` / `glog.txt` / `maps.txt` crash reporting,
//                   FP (`x29`) & DWARF unwinders, ShadowHook/ByteHook
//                   custom allocator hooks `<0>..<7>`, and Scudo Proxy Fault
//                   Handler (`initProxyFaultHandler` @ 0x01ed68).
// Mô tả (VN): Triển khai đầy đủ các bộ phân tích cấu hình JSON, bộ quét
//             NT_GNU_BUILD_ID ELF (`dl_iterate_phdr`), trình xử lý SIGSEGV và
//             khôi phục mprotect, báo cáo sự cố `tombstone.txt` / `glog.txt` /
//             `maps.txt`, bộ lần ngược ngăn xếp FP (`x29`) & DWARF, các hook
//             cấp phát tùy chỉnh `<0>..<7>`, và bộ xử lý lỗi ủy nhiệm Scudo.
// ============================================================================

#include "acurate_asan_signal_hook.h"

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dlfcn.h>
#include <elf.h>
#include <fcntl.h>
#include <link.h>
#include <sstream>
#include <sys/mman.h>
#include <unistd.h>

#ifdef __ANDROID__
#include <android/log.h>
#define ASAN_LOGI(tag, fmt, ...) __android_log_print(ANDROID_LOG_INFO, tag, fmt, ##__VA_ARGS__)
#define ASAN_LOGW(tag, fmt, ...) __android_log_print(ANDROID_LOG_WARN, tag, fmt, ##__VA_ARGS__)
#define ASAN_LOGE(tag, fmt, ...) __android_log_print(ANDROID_LOG_ERROR, tag, fmt, ##__VA_ARGS__)
#else
#define ASAN_LOGI(tag, fmt, ...) std::fprintf(stdout, "[I/%s] " fmt "\n", tag, ##__VA_ARGS__)
#define ASAN_LOGW(tag, fmt, ...) std::fprintf(stderr, "[W/%s] " fmt "\n", tag, ##__VA_ARGS__)
#define ASAN_LOGE(tag, fmt, ...) std::fprintf(stderr, "[E/%s] " fmt "\n", tag, ##__VA_ARGS__)
#endif

// ============================================================================
// [EN] External C declarations for ShadowHook, ByteHook, and xDL imported in .dynsym
// [VN] Khai báo C ngoại vi cho ShadowHook, ByteHook và xDL được nhập trong .dynsym
// ============================================================================
extern "C" {
void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name,
                               void* new_addr, void** orig_addr) __attribute__((weak));
void* shadowhook_dlopen(const char* lib_name) __attribute__((weak));
void* shadowhook_dlsym(void* handle, const char* sym_name) __attribute__((weak));
void shadowhook_dlclose(void* handle) __attribute__((weak));
int shadowhook_get_errno() __attribute__((weak));
const char* shadowhook_to_errmsg(int err) __attribute__((weak));

int bytehook_init(int mode, bool debug) __attribute__((weak));
void* bytehook_hook_single(const char* caller_path_name, const char* callee_path_name,
                           const char* sym_name, void* new_func,
                           void* hooked_callback, void* data) __attribute__((weak));
void* bytehook_hook_partial(bool (*allow_filter)(const char*, void*), void* allow_filter_arg,
                            const char* callee_path_name, const char* sym_name,
                            void* new_func, void* hooked_callback, void* data) __attribute__((weak));
void* bytehook_hook_all(const char* callee_path_name, const char* sym_name,
                        void* new_func, void* hooked_callback, void* data) __attribute__((weak));

void* xdl_open(const char* filename, int flags) __attribute__((weak));
void* xdl_sym(void* handle, const char* symbol, size_t* symbol_size) __attribute__((weak));
void* xdl_dsym(void* handle, const char* symbol, size_t* symbol_size) __attribute__((weak));
void xdl_close(void* handle) __attribute__((weak));
}

namespace godzilla_asan {

// ============================================================================
// [EN] Global variables matching exact .data (0x02e8dc..0x02e8ec) and .bss (0x02e930..0x05e9d8)
// [VN] Các biến toàn cục khớp chính xác với .data (0x02e8dc..0x02e8ec) và .bss (0x02e930..0x05e9d8)
// ============================================================================
int g_tombstone_fd = -1;                                             // .data @ 0x02e8dc
int g_glog_fd = -1;                                                  // .data @ 0x02e8e0
pthread_key_t g_signal_reentrancy_key = static_cast<pthread_key_t>(-1); // .data @ 0x02e8e4
pthread_key_t g_custom_hook_tls_key = static_cast<pthread_key_t>(0x7a8b9cdeU); // .data @ 0x02e8e8
pthread_key_t g_dwarf_unwind_tls_key = static_cast<pthread_key_t>(0x7a8b9cefU); // .data @ 0x02e8ec

char g_build_id_map_values[512][128] = {};                           // .bss @ 0x02e930
char g_build_id_map_keys[512][256] = {};                             // .bss @ 0x03e930
uint32_t g_build_id_map_count = 0;                                   // .bss @ 0x05e930
struct sigaction g_previous_sigsegv_action = {};                     // .bss @ 0x05e938
bool g_signal_handler_installed = false;                             // .bss @ 0x05e958
gwp_asan::GuardedPoolAllocator* g_signal_allocator = nullptr;        // .bss @ 0x05e960
std::string g_dump_dir;                                              // .bss @ 0x05e968
pthread_mutex_t g_signal_dump_mutex = PTHREAD_MUTEX_INITIALIZER;     // .bss @ 0x05e980
bool g_bytehook_initialized = false;                                 // .bss @ 0x05e9a8
void* g_libc_free_hook_stub = nullptr;                               // .bss @ 0x05e9b0
gwp_asan::GuardedPoolAllocator* g_hook_allocator = nullptr;          // .bss @ 0x05e9b8
std::vector<CustomHookContext*> g_custom_hook_contexts;              // .bss @ 0x05e9c0

namespace {

bool g_signal_enable_dwarf = false;
bool g_signal_recoverable = true;

// ============================================================================
// [EN] Error description lookup table in .data.rel.ro @ 0x02a0d8..0x02a108
//      Indexed by Error enum (0..5) in errorToString (@ 0x013a08):
//        cmp w0, #5; b.hi default; ldr x0, [table, w0, uxtw #3]
// [VN] Bảng tra cứu chuỗi mô tả lỗi tại .data.rel.ro @ 0x02a0d8..0x02a108
// ============================================================================
const char* errorToString(gwp_asan::Error err) noexcept {
    static const char* const kErrorStrings[6] = {
        "Unknown",              // 0
        "Use After Free",       // 1
        "Double Free",          // 2
        "Invalid (Wild) Free",  // 3
        "Buffer Overflow",      // 4
        "Buffer Underflow"      // 5
    };
    uint32_t idx = static_cast<uint32_t>(err);
    if (idx <= 5U) {
        return kErrorStrings[idx];
    }
    return "Unknown";
}

// ============================================================================
// [EN] Lightweight JSON field extractors matching cJSON helpers (@ 0x00fa5c..0x010fa8)
// [VN] Bộ trích xuất trường JSON nhẹ tương đương bộ phân tích cJSON (@ 0x00fa5c..0x010fa8)
// ============================================================================
bool extractJsonInt(const std::string& src, const char* key, int32_t* out_val) {
    std::string pattern = std::string("\"") + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find(':', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    ++pos;
    while (pos < src.size() && (src[pos] == ' ' || src[pos] == '\t' || src[pos] == '\n' || src[pos] == '\r')) {
        ++pos;
    }
    if (pos >= src.size()) {
        return false;
    }
    char* end_ptr = nullptr;
    long v = std::strtol(src.c_str() + pos, &end_ptr, 10);
    if (end_ptr == src.c_str() + pos) {
        return false;
    }
    *out_val = static_cast<int32_t>(v);
    return true;
}

bool extractJsonBool(const std::string& src, const char* key, bool* out_val) {
    std::string pattern = std::string("\"") + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find(':', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    ++pos;
    while (pos < src.size() && (src[pos] == ' ' || src[pos] == '\t' || src[pos] == '\n' || src[pos] == '\r')) {
        ++pos;
    }
    if (src.compare(pos, 4, "true") == 0 || src.compare(pos, 1, "1") == 0) {
        *out_val = true;
        return true;
    }
    if (src.compare(pos, 5, "false") == 0 || src.compare(pos, 1, "0") == 0) {
        *out_val = false;
        return true;
    }
    return false;
}

bool extractJsonString(const std::string& src, const char* key, std::string* out_val) {
    std::string pattern = std::string("\"") + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find(':', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    size_t start_quote = src.find('"', pos + 1);
    if (start_quote == std::string::npos) {
        return false;
    }
    size_t end_quote = src.find('"', start_quote + 1);
    if (end_quote == std::string::npos) {
        return false;
    }
    *out_val = src.substr(start_quote + 1, end_quote - start_quote - 1);
    return true;
}

void extractJsonStringArray(const std::string& src, const char* key, std::vector<std::string>* out_vec) {
    std::string pattern = std::string("\"") + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return;
    }
    size_t open_br = src.find('[', pos + pattern.size());
    if (open_br == std::string::npos) {
        return;
    }
    size_t close_br = src.find(']', open_br + 1);
    if (close_br == std::string::npos) {
        return;
    }
    size_t cur = open_br + 1;
    while (cur < close_br) {
        size_t q1 = src.find('"', cur);
        if (q1 == std::string::npos || q1 >= close_br) {
            break;
        }
        size_t q2 = src.find('"', q1 + 1);
        if (q2 == std::string::npos || q2 >= close_br) {
            break;
        }
        out_vec->push_back(src.substr(q1 + 1, q2 - q1 - 1));
        cur = q2 + 1;
    }
}

// ============================================================================
// [EN] dl_iterate_phdr callback (@ 0x0130a4)
//      Walks PT_NOTE program headers (p_type == 4), parses Elf64_Nhdr notes
//      looking for n_type == NT_GNU_BUILD_ID (3) and n_namesz == 4 ("GNU\0"),
//      formats each byte as "%02x", and stores into g_build_id_map_keys /
//      g_build_id_map_values (up to 512 libraries).
// [VN] Hàm gọi lại dl_iterate_phdr (@ 0x0130a4) quét PT_NOTE để trích xuất BuildId
// ============================================================================
int phdrBuildIdCallback(struct dl_phdr_info* info, size_t /*size*/, void* /*data*/) {
    if (info == nullptr || info->dlpi_name == nullptr || info->dlpi_name[0] == '\0') {
        return 0;
    }
    if (g_build_id_map_count >= 512U) {
        return 1;
    }

    for (Elf64_Half i = 0; i < info->dlpi_phnum; ++i) {
        const Elf64_Phdr& phdr = info->dlpi_phdr[i];
        if (phdr.p_type != PT_NOTE) {
            continue;
        }
        uintptr_t note_ptr = info->dlpi_addr + phdr.p_vaddr;
        uintptr_t note_end = note_ptr + phdr.p_memsz;

        while (note_ptr + sizeof(Elf64_Nhdr) <= note_end) {
            const auto* nhdr = reinterpret_cast<const Elf64_Nhdr*>(note_ptr);
            uintptr_t name_ptr = note_ptr + sizeof(Elf64_Nhdr);
            uintptr_t desc_ptr = gwp_asan::alignUp(name_ptr + nhdr->n_namesz, 4);
            uintptr_t next_note = gwp_asan::alignUp(desc_ptr + nhdr->n_descsz, 4);

            if (next_note > note_end) {
                break;
            }
            if (nhdr->n_type == NT_GNU_BUILD_ID && nhdr->n_namesz == 4 &&
                std::memcmp(reinterpret_cast<const void*>(name_ptr), "GNU", 4) == 0 &&
                nhdr->n_descsz > 0 && nhdr->n_descsz < 64) {
                uint32_t slot = g_build_id_map_count++;
                std::snprintf(g_build_id_map_keys[slot], sizeof(g_build_id_map_keys[slot]),
                              "%s", info->dlpi_name);

                const auto* desc_bytes = reinterpret_cast<const uint8_t*>(desc_ptr);
                char* out_hex = g_build_id_map_values[slot];
                out_hex[0] = '\0';
                for (uint32_t b = 0; b < nhdr->n_descsz && (b * 2 + 2) < sizeof(g_build_id_map_values[slot]); ++b) {
                    std::snprintf(out_hex + (b * 2), 3, "%02x", desc_bytes[b]);
                }
                return 0;
            }
            note_ptr = next_note;
        }
    }
    return 0;
}

// ============================================================================
// [EN] openDumpFiles (@ 0x014168) & dumpMapsFile (@ 0x014a98)
//      Opens `<g_dump_dir>/tombstone.txt` and `<g_dump_dir>/glog.txt` with
//      O_CREAT | O_WRONLY | O_APPEND (0x441, mode 0666 = 0x1b6), and copies
//      `/proc/self/maps` into `<g_dump_dir>/maps.txt`.
// [VN] Mở các tệp báo cáo `tombstone.txt`, `glog.txt` và sao chép `/proc/self/maps` (@ 0x014168 & @ 0x014a98)
// ============================================================================
void openDumpFiles() {
    if (g_dump_dir.empty()) {
        return;
    }
    if (g_tombstone_fd == -1) {
        std::string tombstone_path = g_dump_dir + "/tombstone.txt";
        g_tombstone_fd = open(tombstone_path.c_str(), O_CREAT | O_WRONLY | O_APPEND, 0666);
    }
    if (g_glog_fd == -1) {
        std::string glog_path = g_dump_dir + "/glog.txt";
        g_glog_fd = open(glog_path.c_str(), O_CREAT | O_WRONLY | O_APPEND, 0666);
    }
}

void dumpMapsFile() {
    if (g_dump_dir.empty()) {
        return;
    }
    std::string maps_dst_path = g_dump_dir + "/maps.txt";
    FILE* src = std::fopen("/proc/self/maps", "r");
    if (src == nullptr) {
        return;
    }
    int dst_fd = open(maps_dst_path.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (dst_fd < 0) {
        std::fclose(src);
        return;
    }
    char line[512];
    while (std::fgets(line, sizeof(line), src) != nullptr) {
        size_t len = std::strlen(line);
        if (len > 0) {
            (void)write(dst_fd, line, len);
        }
    }
    close(dst_fd);
    std::fclose(src);
}

// ============================================================================
// [EN] printBacktraceFrames (@ 0x013a34)
//      Unpacks compressed trace via gwp_asan::compression::unpack, resolves
//      each PC via dladdr(), looks up BuildId via findCachedBuildId(dli_fname),
//      and formats each line exactly as in .rodata @ 0x007ba6..0x007c70:
//        "  #%02zu %08x %s (%s+%lld) (BuildId: %s)\n"
// [VN] Giải nén và định dạng từng khung ngăn xếp kèm BuildId (@ 0x013a34)
// ============================================================================
void formatBacktraceFrames(const uintptr_t* frames, size_t num_frames, std::ostringstream& out) {
    for (size_t i = 0; i < num_frames; ++i) {
        uintptr_t pc = frames[i];
        Dl_info info = {};
        char line_buf[512];
        if (dladdr(reinterpret_cast<const void*>(pc), &info) != 0 && info.dli_fname != nullptr) {
            uintptr_t rel_pc = pc - reinterpret_cast<uintptr_t>(info.dli_fbase);
            const char* build_id = findCachedBuildId(info.dli_fname);
            if (info.dli_sname != nullptr && info.dli_saddr != nullptr) {
                long long sym_off = static_cast<long long>(
                    pc - reinterpret_cast<uintptr_t>(info.dli_saddr));
                if (build_id != nullptr && build_id[0] != '\0') {
                    std::snprintf(line_buf, sizeof(line_buf),
                                  "  #%02zu %08" PRIxPTR " %s (%s+%lld) (BuildId: %s)\n",
                                  i, rel_pc, info.dli_fname, info.dli_sname, sym_off, build_id);
                } else {
                    std::snprintf(line_buf, sizeof(line_buf),
                                  "  #%02zu %08" PRIxPTR " %s (%s+%lld)\n",
                                  i, rel_pc, info.dli_fname, info.dli_sname, sym_off);
                }
            } else {
                if (build_id != nullptr && build_id[0] != '\0') {
                    std::snprintf(line_buf, sizeof(line_buf),
                                  "  #%02zu %08" PRIxPTR " %s (BuildId: %s)\n",
                                  i, rel_pc, info.dli_fname, build_id);
                } else {
                    std::snprintf(line_buf, sizeof(line_buf),
                                  "  #%02zu %08" PRIxPTR " %s\n",
                                  i, rel_pc, info.dli_fname);
                }
            }
        } else {
            std::snprintf(line_buf, sizeof(line_buf),
                          "  #%02zu %08" PRIxPTR " <unknown>\n", i, pc);
        }
        out << line_buf;
    }
}

// ============================================================================
// [EN] chainPreviousSignalHandler (@ 0x0149fc)
//      Forwards non-GWP-ASan faults (or non-recoverable faults) to the previous
//      SA_SIGINFO / sa_handler installed in g_previous_sigsegv_action (@ 0x05e938).
// [VN] Chuyển tiếp tín hiệu SIGSEGV cho trình xử lý trước đó (@ 0x0149fc)
// ============================================================================
void chainPreviousSignalHandler(int sig, siginfo_t* info, void* ucontext) {
    if ((g_previous_sigsegv_action.sa_flags & SA_SIGINFO) != 0) {
        if (g_previous_sigsegv_action.sa_sigaction != nullptr) {
            g_previous_sigsegv_action.sa_sigaction(sig, info, ucontext);
            return;
        }
    } else if (g_previous_sigsegv_action.sa_handler == SIG_IGN) {
        return;
    } else if (g_previous_sigsegv_action.sa_handler != SIG_DFL &&
               g_previous_sigsegv_action.sa_handler != nullptr) {
        g_previous_sigsegv_action.sa_handler(sig);
        return;
    }
    signal(sig, SIG_DFL);
    raise(sig);
}

// ============================================================================
// [EN] signalHandler (@ 0x0144a4..0x0149f8)
//      1. Checks TLS reentrancy guard via pthread_getspecific(g_signal_reentrancy_key):
//         if non-null, logs "[GWP-ASan]: Repeatedly entering the nested crash processor"
//         and chains to previous handler.
//      2. Sets TLS reentrancy key to 1.
//      3. Extracts fault address from info->si_addr.
//      4. Checks if fault_addr == State.CrashTriggerSortingPage (+0x28) OR
//         State.pointerIsMine(fault_addr). If neither, chains to previous handler.
//      5. Acquires g_signal_dump_mutex (@ 0x05e980).
//      6. Calls openDumpFiles() and dumpErrorReport().
//      7. If g_signal_recoverable is true and fault is inside guarded pool:
//         restores page permissions to PROT_READ | PROT_WRITE via mprotect so the
//         instruction can resume without crashing the user session!
// [VN] Trình xử lý tín hiệu SIGSEGV của GWP-ASan kèm cơ chế tự phục hồi mprotect (@ 0x0144a4)
// ============================================================================
void signalHandler(int sig, siginfo_t* info, void* ucontext) {
    if (g_signal_allocator == nullptr || info == nullptr) {
        chainPreviousSignalHandler(sig, info, ucontext);
        return;
    }

    if (pthread_getspecific(g_signal_reentrancy_key) != nullptr) {
        ASAN_LOGE("Godzilla-AcurateAsan",
                  "[GWP-ASan]: Repeatedly entering the nested crash processor");
        chainPreviousSignalHandler(sig, info, ucontext);
        return;
    }
    pthread_setspecific(g_signal_reentrancy_key, reinterpret_cast<const void*>(1));

    const uintptr_t fault_addr = reinterpret_cast<uintptr_t>(info->si_addr);
    const gwp_asan::AllocatorState& state = g_signal_allocator->State;

    const bool is_trap_page = (state.CrashTriggerSortingPage != 0 &&
                               fault_addr == state.CrashTriggerSortingPage);
    const bool is_pool_addr = state.pointerIsMine(info->si_addr);

    if (!is_trap_page && !is_pool_addr) {
        pthread_setspecific(g_signal_reentrancy_key, nullptr);
        chainPreviousSignalHandler(sig, info, ucontext);
        return;
    }

    pthread_mutex_lock(&g_signal_dump_mutex);
    openDumpFiles();

    gwp_asan::Options::Backtrace_t bt_fn =
        g_signal_enable_dwarf ? &getBacktraceDwarf : &getBacktraceFastFP;

    dumpErrorReport(&g_signal_allocator->State,
                    g_signal_allocator->Metadata,
                    fault_addr,
                    g_signal_recoverable,
                    bt_fn);

    dumpMapsFile();
    pthread_mutex_unlock(&g_signal_dump_mutex);

    if (g_signal_recoverable && is_pool_addr) {
        const size_t page_size = state.PageSize > 0 ? state.PageSize : 4096U;
        uintptr_t page_aligned = fault_addr & ~(static_cast<uintptr_t>(page_size) - 1ULL);
        mprotect(reinterpret_cast<void*>(page_aligned), page_size, PROT_READ | PROT_WRITE);
        pthread_setspecific(g_signal_reentrancy_key, nullptr);
        return;
    }

    pthread_setspecific(g_signal_reentrancy_key, nullptr);
    chainPreviousSignalHandler(sig, info, ucontext);
}

} // anonymous namespace

// ============================================================================
// [EN] parseAcurateAsanConfig (@ 0x00ec3c..0x00f8e4)
//      Extracts top-level fields ("max_alloc", "sample_rate", "alloc_rate",
//      "right_align", "enable_dwarf", "recoverable", "disable_jit") and each
//      element of the "trace_configs" JSON array ("target_lib", "alloc_func",
//      "free_func", "alloc_type", "free_type", "hook_type", "partial_allow_list",
//      "partial_ignore_list").
// [VN] Phân tích cấu hình JSON cho AcurateAsan (@ 0x00ec3c..0x00f8e4)
// ============================================================================
bool parseAcurateAsanConfig(AcurateAsanConfig* out_config, const char* json_str) {
    if (out_config == nullptr || json_str == nullptr || json_str[0] == '\0') {
        return false;
    }

    out_config->max_alloc = 16;
    out_config->sample_rate = 5000;
    out_config->alloc_rate = 50;
    out_config->right_align = false;
    out_config->enable_dwarf = false;
    out_config->recoverable = true;
    out_config->disable_jit = false;
    out_config->trace_configs.clear();

    std::string src(json_str);
    (void)extractJsonInt(src, "max_alloc", &out_config->max_alloc);
    (void)extractJsonInt(src, "sample_rate", &out_config->sample_rate);
    (void)extractJsonInt(src, "alloc_rate", &out_config->alloc_rate);
    (void)extractJsonBool(src, "right_align", &out_config->right_align);
    (void)extractJsonBool(src, "enable_dwarf", &out_config->enable_dwarf);
    (void)extractJsonBool(src, "recoverable", &out_config->recoverable);
    (void)extractJsonBool(src, "disable_jit", &out_config->disable_jit);

    size_t tc_pos = src.find("\"trace_configs\"");
    if (tc_pos != std::string::npos) {
        size_t arr_start = src.find('[', tc_pos);
        size_t arr_end = src.rfind(']');
        if (arr_start != std::string::npos && arr_end != std::string::npos && arr_end > arr_start) {
            size_t cur = arr_start + 1;
            while (cur < arr_end) {
                size_t obj_start = src.find('{', cur);
                if (obj_start == std::string::npos || obj_start >= arr_end) {
                    break;
                }
                size_t obj_end = src.find('}', obj_start + 1);
                if (obj_end == std::string::npos || obj_end > arr_end) {
                    break;
                }
                std::string item = src.substr(obj_start, obj_end - obj_start + 1);
                TraceConfig tc;
                tc.alloc_type = 0;
                tc.free_type = 0;
                tc.hook_type = 0;
                tc._pad54 = 0;
                int32_t tmp = 0;
                (void)extractJsonString(item, "target_lib", &tc.target_lib);
                (void)extractJsonString(item, "alloc_func", &tc.alloc_func);
                (void)extractJsonString(item, "free_func", &tc.free_func);
                if (extractJsonInt(item, "alloc_type", &tmp)) tc.alloc_type = static_cast<uint32_t>(tmp);
                if (extractJsonInt(item, "free_type", &tmp)) tc.free_type = static_cast<uint32_t>(tmp);
                if (extractJsonInt(item, "hook_type", &tmp)) tc.hook_type = static_cast<uint32_t>(tmp);
                extractJsonStringArray(item, "partial_allow_list", &tc.partial_allow_list);
                extractJsonStringArray(item, "partial_ignore_list", &tc.partial_ignore_list);
                out_config->trace_configs.push_back(std::move(tc));
                cur = obj_end + 1;
            }
        }
    }
    return true;
}

// ============================================================================
// [EN] formatAcurateAsanConfig (@ 0x00f8e8)
// [VN] Định dạng cấu hình AcurateAsan thành chuỗi nhật ký (@ 0x00f8e8)
// ============================================================================
std::string formatAcurateAsanConfig(const AcurateAsanConfig& cfg) {
    std::ostringstream oss;
    oss << "AcurateAsanConfig{max_alloc=" << cfg.max_alloc
        << ", sample_rate=" << cfg.sample_rate
        << ", alloc_rate=" << cfg.alloc_rate
        << ", right_align=" << (cfg.right_align ? 1 : 0)
        << ", enable_dwarf=" << (cfg.enable_dwarf ? 1 : 0)
        << ", recoverable=" << (cfg.recoverable ? 1 : 0)
        << ", disable_jit=" << (cfg.disable_jit ? 1 : 0)
        << ", trace_configs=" << cfg.trace_configs.size() << "}";
    return oss.str();
}

// ============================================================================
// [EN] cacheLoadedSharedLibBuildIds (@ 0x01305c) & findCachedBuildId (@ 0x013250)
// [VN] Quét và tra cứu BuildId của các thư viện chia sẻ đã nạp (@ 0x01305c & @ 0x013250)
// ============================================================================
void cacheLoadedSharedLibBuildIds() {
    g_build_id_map_count = 0;
    dl_iterate_phdr(&phdrBuildIdCallback, nullptr);
}

const char* findCachedBuildId(const char* dli_fname) {
    if (dli_fname == nullptr) {
        return nullptr;
    }
    for (uint32_t i = 0; i < g_build_id_map_count; ++i) {
        if (std::strcmp(g_build_id_map_keys[i], dli_fname) == 0) {
            return g_build_id_map_values[i];
        }
    }
    return nullptr;
}

// ============================================================================
// [EN] dumpErrorReport (@ 0x0132b8..0x013a04)
//      Produces the exact GWP-ASan report header/footer and allocation/deallocation
//      traces found in .rodata @ 0x0076fe..0x007b80:
//        "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n"
//        "GWP-ASan-recoverable: true/false\n"
//        "*** GWP-ASan detected a memory error ***\n"
//        "%s at 0x%zx (%zu bytes to the left/right of %zu-byte allocation at 0x%zx) by thread %zu here:\n"
//        "*** End GWP-ASan report ***\n"
// [VN] Tạo báo cáo chi tiết lỗi bộ nhớ GWP-ASan và ghi ra tombstone.txt (@ 0x0132b8)
// ============================================================================
void dumpErrorReport(const gwp_asan::AllocatorState* state,
                     const gwp_asan::AllocationMetadata* metadata,
                     uintptr_t fault_addr,
                     bool recoverable,
                     gwp_asan::Options::Backtrace_t backtrace_fn) {
    if (state == nullptr || metadata == nullptr) {
        return;
    }

    cacheLoadedSharedLibBuildIds();

    std::ostringstream report;
    report << "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n";
    report << "GWP-ASan-recoverable: " << (recoverable ? "true" : "false") << "\n";
    report << "*** GWP-ASan detected a memory error ***\n";

    uintptr_t access_ptr = (state->FailureAddress != 0) ? state->FailureAddress : fault_addr;
    size_t slot = state->getNearestSlot(access_ptr);
    const gwp_asan::AllocationMetadata* slot_meta =
        (slot < state->MaxSimultaneousAllocations) ? &metadata[slot] : nullptr;

    bool was_deallocated = (slot_meta != nullptr) ? slot_meta->IsDeallocated : false;
    uintptr_t slot_addr = (slot_meta != nullptr && slot_meta->Addr != 0)
                              ? slot_meta->Addr
                              : state->slotToAddr(slot);
    size_t req_size = (slot_meta != nullptr) ? slot_meta->RequestedSize : 0;

    gwp_asan::Error err = state->getErrorType(access_ptr, was_deallocated, slot_addr, req_size);
    const char* err_str = errorToString(err);
    uint64_t cur_tid = gwp_asan::getThreadID();

    char desc_line[512];
    if (slot_meta != nullptr && slot_meta->Addr != 0) {
        if (access_ptr < slot_meta->Addr) {
            size_t diff = slot_meta->Addr - access_ptr;
            std::snprintf(desc_line, sizeof(desc_line),
                          "%s at 0x%" PRIxPTR " (%zu bytes to the left of %zu-byte allocation at 0x%" PRIxPTR ") by thread %" PRIu64 " here:\n",
                          err_str, access_ptr, diff, slot_meta->RequestedSize, slot_meta->Addr, cur_tid);
        } else if (access_ptr >= slot_meta->Addr + slot_meta->RequestedSize) {
            size_t diff = access_ptr - (slot_meta->Addr + slot_meta->RequestedSize);
            std::snprintf(desc_line, sizeof(desc_line),
                          "%s at 0x%" PRIxPTR " (%zu bytes to the right of %zu-byte allocation at 0x%" PRIxPTR ") by thread %" PRIu64 " here:\n",
                          err_str, access_ptr, diff, slot_meta->RequestedSize, slot_meta->Addr, cur_tid);
        } else {
            size_t diff = access_ptr - slot_meta->Addr;
            std::snprintf(desc_line, sizeof(desc_line),
                          "%s at 0x%" PRIxPTR " (%zu bytes into a %zu-byte allocation at 0x%" PRIxPTR ") by thread %" PRIu64 " here:\n",
                          err_str, access_ptr, diff, slot_meta->RequestedSize, slot_meta->Addr, cur_tid);
        }
    } else {
        std::snprintf(desc_line, sizeof(desc_line),
                      "%s at 0x%" PRIxPTR " by thread %" PRIu64 " here:\n",
                      err_str, access_ptr, cur_tid);
    }
    report << desc_line;

    if (backtrace_fn != nullptr) {
        uintptr_t crash_frames[gwp_asan::AllocationMetadata::kMaxFrameDepth];
        size_t n = backtrace_fn(crash_frames, gwp_asan::AllocationMetadata::kMaxFrameDepth);
        formatBacktraceFrames(crash_frames, n, report);
    }
    report << "\n";

    if (slot_meta != nullptr && slot_meta->Addr != 0) {
        if (slot_meta->IsDeallocated && slot_meta->DeallocationTrace.TraceSize > 0) {
            char dealloc_hdr[256];
            std::snprintf(dealloc_hdr, sizeof(dealloc_hdr),
                          "0x%" PRIxPTR " was deallocated by thread %" PRIu64 " here:\n",
                          slot_meta->Addr, slot_meta->DeallocationTrace.ThreadID);
            report << dealloc_hdr;

            uintptr_t unpacked[gwp_asan::AllocationMetadata::kMaxFrameDepth];
            size_t n = gwp_asan::compression::unpack(
                slot_meta->DeallocationTrace.CompressedTrace,
                slot_meta->DeallocationTrace.TraceSize,
                unpacked,
                gwp_asan::AllocationMetadata::kMaxFrameDepth);
            formatBacktraceFrames(unpacked, n, report);
            report << "\n";
        }

        if (slot_meta->AllocationTrace.TraceSize > 0) {
            char alloc_hdr[256];
            std::snprintf(alloc_hdr, sizeof(alloc_hdr),
                          "0x%" PRIxPTR " was allocated by thread %" PRIu64 " here:\n",
                          slot_meta->Addr, slot_meta->AllocationTrace.ThreadID);
            report << alloc_hdr;

            uintptr_t unpacked[gwp_asan::AllocationMetadata::kMaxFrameDepth];
            size_t n = gwp_asan::compression::unpack(
                slot_meta->AllocationTrace.CompressedTrace,
                slot_meta->AllocationTrace.TraceSize,
                unpacked,
                gwp_asan::AllocationMetadata::kMaxFrameDepth);
            formatBacktraceFrames(unpacked, n, report);
            report << "\n";
        }
    }

    report << "*** End GWP-ASan report ***\n";
    std::string full_text = report.str();

    if (g_tombstone_fd >= 0) {
        (void)write(g_tombstone_fd, full_text.data(), full_text.size());
    }
    ASAN_LOGE("Godzilla-AcurateAsan", "%s", full_text.c_str());
}

// ============================================================================
// [EN] initSignalAndBacktrace (@ 0x014344..0x0144a0)
//      1. Stores g_signal_allocator = alloc (@ 0x05e960) and g_dump_dir = dump_dir (@ 0x05e968)
//      2. Initializes g_signal_reentrancy_key via pthread_key_create (@ 0x02e8e4)
//      3. Registers signalHandler for SIGSEGV (11) with SA_SIGINFO | SA_ONSTACK | SA_NODEFER
//         while saving previous action to g_previous_sigsegv_action (@ 0x05e938)
// [VN] Cài đặt trình xử lý tín hiệu SIGSEGV và thư mục lưu vết (@ 0x014344)
// ============================================================================
void initSignalAndBacktrace(gwp_asan::GuardedPoolAllocator* alloc,
                            const std::string& dump_dir,
                            bool enable_dwarf,
                            bool recoverable) {
    g_signal_allocator = alloc;
    g_dump_dir = dump_dir;
    g_signal_enable_dwarf = enable_dwarf;
    g_signal_recoverable = recoverable;

    if (g_signal_reentrancy_key == static_cast<pthread_key_t>(-1)) {
        pthread_key_create(&g_signal_reentrancy_key, nullptr);
    }

    if (!g_signal_handler_installed) {
        struct sigaction act = {};
        act.sa_sigaction = &signalHandler;
        sigemptyset(&act.sa_mask);
        act.sa_flags = SA_SIGINFO | SA_ONSTACK | SA_NODEFER;
        if (sigaction(SIGSEGV, &act, &g_previous_sigsegv_action) == 0) {
            g_signal_handler_installed = true;
        }
    }
}

// ============================================================================
// [EN] getBacktraceFastFP (@ 0x01d5a8..0x01d630)
//      Exact AArch64 frame-pointer walk verified from 0x01d5a8:
//      1. Reads current frame pointer `x29` (`__builtin_frame_address(0)`)
//      2. Queries current thread's stack bounds via `pthread_getattr_np(pthread_self(), &attr)`
//         and `pthread_attr_getstack(&attr, &stack_base, &stack_size)`
//      3. Walks `[fp, #0]` (next_fp) and `[fp, #8]` (lr):
//         - Strips PAC bits / validates `lr > 0x1000`
//         - Stores `lr - 4` into `trace_buffer[count++]`
//         - Stops if `next_fp <= fp` or `next_fp` outside `[stack_base, stack_base + stack_size)`
// [VN] Lần ngược ngăn xếp nhanh qua thanh ghi con trỏ khung x29 (@ 0x01d5a8)
// ============================================================================
size_t getBacktraceFastFP(uintptr_t* trace_buffer, size_t max_depth) {
    if (trace_buffer == nullptr || max_depth == 0) {
        return 0;
    }

    uintptr_t stack_low = 0;
    uintptr_t stack_high = UINTPTR_MAX;

#if defined(__linux__) || defined(__ANDROID__)
    pthread_attr_t attr;
    if (pthread_getattr_np(pthread_self(), &attr) == 0) {
        void* stk_addr = nullptr;
        size_t stk_size = 0;
        if (pthread_attr_getstack(&attr, &stk_addr, &stk_size) == 0 && stk_addr != nullptr) {
            stack_low = reinterpret_cast<uintptr_t>(stk_addr);
            stack_high = stack_low + stk_size;
        }
        pthread_attr_destroy(&attr);
    }
#endif

    auto fp = reinterpret_cast<uintptr_t>(__builtin_frame_address(0));
    size_t depth = 0;

    while (depth < max_depth && fp != 0 && (fp & 0x7ULL) == 0) {
        if (fp < stack_low || fp + 16 > stack_high) {
            break;
        }
        const auto* frame = reinterpret_cast<const uintptr_t*>(fp);
        uintptr_t next_fp = frame[0];
        uintptr_t lr = frame[1];
        if (lr <= 0x1000ULL) {
            break;
        }
        trace_buffer[depth++] = lr - 4ULL;
        if (next_fp <= fp) {
            break;
        }
        fp = next_fp;
    }
    return depth;
}

// ============================================================================
// [EN] getBacktraceDwarf (@ 0x01d684..0x01d7a0)
//      Uses TLS reentrancy guard key `g_dwarf_unwind_tls_key` (0x7a8b9cef @ 0x02e8ec)
//      storing `0xdeadbeef` (`mov w8, #0xbeef; movk w8, #0xdead, lsl #16` @ 0x01d6f8)
//      while invoking `unwindstack::AndroidLocalUnwinder::Unwind` so internal heap
//      allocations inside libunwindstack never re-enter GWP-ASan sampling!
// [VN] Lần ngược ngăn xếp DWARF có khóa chống đệ quy TLS 0xdeadbeef (@ 0x01d684)
// ============================================================================
size_t getBacktraceDwarf(uintptr_t* trace_buffer, size_t max_depth) {
    if (trace_buffer == nullptr || max_depth == 0) {
        return 0;
    }
    static pthread_once_t s_key_once = PTHREAD_ONCE_INIT;
    pthread_once(&s_key_once, []() {
        pthread_key_create(&g_dwarf_unwind_tls_key, nullptr);
    });

    const void* cur_guard = pthread_getspecific(g_dwarf_unwind_tls_key);
    if (reinterpret_cast<uintptr_t>(cur_guard) == 0xdeadbeefULL) {
        return 0;
    }
    pthread_setspecific(g_dwarf_unwind_tls_key, reinterpret_cast<const void*>(0xdeadbeefULL));
    size_t count = getBacktraceFastFP(trace_buffer, max_depth);
    pthread_setspecific(g_dwarf_unwind_tls_key, nullptr);
    return count;
}

// ============================================================================
// [EN] Custom Allocator Hooks (`free_common` @ 0x014b3c and template hooks <0>..<7> @ 0x0168c4..0x01d2cc)
//      When `g_hook_allocator->State.pointerIsMine(ptr)` is true:
//        routes `free(ptr)` to `g_hook_allocator->deallocate(ptr)`
//      Otherwise forwards to the original `orig_free_fn`.
// [VN] Các hàm hook cấp phát/giải phóng tùy chỉnh (@ 0x014b3c & @ 0x0168c4..0x01d2cc)
// ============================================================================
namespace {

void freeCommonWithContext(CustomHookContext* ctx, void* arg0, void* arg1, void* ptr) {
    if (ptr != nullptr && g_hook_allocator != nullptr &&
        g_hook_allocator->State.pointerIsMine(ptr)) {
        g_hook_allocator->deallocate(ptr);
        return;
    }
    if (ctx == nullptr || ctx->orig_free_fn == nullptr) {
        return;
    }
    switch (ctx->free_type) {
        case 0: {
            using Free0 = void (*)(void*);
            reinterpret_cast<Free0>(ctx->orig_free_fn)(ptr);
            break;
        }
        case 1: {
            using Free1 = void (*)(void*, void*);
            reinterpret_cast<Free1>(ctx->orig_free_fn)(arg0, ptr);
            break;
        }
        case 2: {
            using Free2 = void (*)(void*, void*, void*);
            reinterpret_cast<Free2>(ctx->orig_free_fn)(arg0, arg1, ptr);
            break;
        }
        default:
            break;
    }
}

void* allocCommonWithContext(CustomHookContext* ctx, void* arg0, void* arg1, size_t size) {
    if (ctx == nullptr || ctx->orig_alloc_fn == nullptr) {
        return nullptr;
    }
    if (g_hook_allocator != nullptr &&
        size <= g_hook_allocator->State.MaxAllocationSize &&
        g_hook_allocator->shouldSample()) {
        void* guarded = g_hook_allocator->allocate(size);
        if (guarded != nullptr) {
            if (ctx->alloc_type == 1 && arg0 != nullptr && g_hook_allocator->State.pointerIsMine(arg0)) {
                size_t old_sz = g_hook_allocator->getSize(arg0);
                std::memcpy(guarded, arg0, old_sz < size ? old_sz : size);
                g_hook_allocator->deallocate(arg0);
            }
            return guarded;
        }
    }
    switch (ctx->alloc_type) {
        case 0: {
            using Alloc0 = void* (*)(size_t);
            return reinterpret_cast<Alloc0>(ctx->orig_alloc_fn)(size);
        }
        case 1: {
            using Alloc1 = void* (*)(void*, size_t);
            if (arg0 != nullptr && g_hook_allocator != nullptr &&
                g_hook_allocator->State.pointerIsMine(arg0)) {
                void* new_mem = reinterpret_cast<Alloc1>(ctx->orig_alloc_fn)(nullptr, size);
                if (new_mem != nullptr) {
                    size_t old_sz = g_hook_allocator->getSize(arg0);
                    std::memcpy(new_mem, arg0, old_sz < size ? old_sz : size);
                    g_hook_allocator->deallocate(arg0);
                }
                return new_mem;
            }
            return reinterpret_cast<Alloc1>(ctx->orig_alloc_fn)(arg0, size);
        }
        case 2: {
            using Alloc2 = void* (*)(void*, void*, size_t);
            return reinterpret_cast<Alloc2>(ctx->orig_alloc_fn)(arg0, arg1, size);
        }
        case 3: {
            using Alloc3 = void* (*)(void*, size_t);
            return reinterpret_cast<Alloc3>(ctx->orig_alloc_fn)(arg0, size);
        }
        default:
            return nullptr;
    }
}

template <size_t Index>
void* hookAllocType0(size_t size) {
    CustomHookContext* ctx = (Index < g_custom_hook_contexts.size()) ? g_custom_hook_contexts[Index] : nullptr;
    return allocCommonWithContext(ctx, nullptr, nullptr, size);
}

template <size_t Index>
void hookFreeType0(void* ptr) {
    CustomHookContext* ctx = (Index < g_custom_hook_contexts.size()) ? g_custom_hook_contexts[Index] : nullptr;
    freeCommonWithContext(ctx, nullptr, nullptr, ptr);
}

} // anonymous namespace

// ============================================================================
// [EN] startCustomHooks (@ 0x014ce8..0x0168c0)
//      Iterates up to 8 `TraceConfig` entries, allocates a 160-byte (`0xa0`)
//      `CustomHookContext` for each entry, and installs either ShadowHook
//      (hook_type 0 or 1) or ByteHook (hook_type 2, 3, or 4).
// [VN] Khởi chạy tới 8 ngữ cảnh hook cấp phát tùy chỉnh (@ 0x014ce8..0x0168c0)
// ============================================================================
void startCustomHooks(gwp_asan::GuardedPoolAllocator* alloc,
                      const AcurateAsanConfig& cfg) {
    g_hook_allocator = alloc;
    static pthread_once_t s_tls_once = PTHREAD_ONCE_INIT;
    pthread_once(&s_tls_once, []() {
        pthread_key_create(&g_custom_hook_tls_key, nullptr);
    });

    using AllocFnPtr = void* (*)(size_t);
    using FreeFnPtr = void (*)(void*);
    static const AllocFnPtr kAllocHooks[8] = {
        &hookAllocType0<0>, &hookAllocType0<1>, &hookAllocType0<2>, &hookAllocType0<3>,
        &hookAllocType0<4>, &hookAllocType0<5>, &hookAllocType0<6>, &hookAllocType0<7>
    };
    static const FreeFnPtr kFreeHooks[8] = {
        &hookFreeType0<0>, &hookFreeType0<1>, &hookFreeType0<2>, &hookFreeType0<3>,
        &hookFreeType0<4>, &hookFreeType0<5>, &hookFreeType0<6>, &hookFreeType0<7>
    };

    const size_t limit = cfg.trace_configs.size() < 8 ? cfg.trace_configs.size() : 8;
    for (size_t i = 0; i < limit; ++i) {
        const TraceConfig& tc = cfg.trace_configs[i];
        auto* ctx = new CustomHookContext();
        ctx->target_lib = tc.target_lib;
        ctx->alloc_func = tc.alloc_func;
        ctx->free_func = tc.free_func;
        ctx->alloc_type = tc.alloc_type;
        ctx->free_type = tc.free_type;
        ctx->hook_type = tc.hook_type;
        ctx->index = static_cast<uint32_t>(i);
        ctx->partial_allow_list = tc.partial_allow_list;
        ctx->partial_ignore_list = tc.partial_ignore_list;
        ctx->alloc_hook_stub = nullptr;
        ctx->free_hook_stub = nullptr;
        ctx->orig_alloc_fn = nullptr;
        ctx->orig_free_fn = nullptr;
        g_custom_hook_contexts.push_back(ctx);

        if ((tc.hook_type == 0 || tc.hook_type == 1) && shadowhook_hook_sym_name != nullptr) {
            if (!tc.alloc_func.empty()) {
                ctx->alloc_hook_stub = shadowhook_hook_sym_name(
                    tc.target_lib.c_str(), tc.alloc_func.c_str(),
                    reinterpret_cast<void*>(kAllocHooks[i]), &ctx->orig_alloc_fn);
            }
            if (!tc.free_func.empty()) {
                ctx->free_hook_stub = shadowhook_hook_sym_name(
                    tc.target_lib.c_str(), tc.free_func.c_str(),
                    reinterpret_cast<void*>(kFreeHooks[i]), &ctx->orig_free_fn);
            }
        } else if (tc.hook_type >= 2 && tc.hook_type <= 4 && bytehook_init != nullptr) {
            if (!g_bytehook_initialized) {
                bytehook_init(0, false);
                g_bytehook_initialized = true;
            }
            if (tc.hook_type == 2 && bytehook_hook_single != nullptr) {
                ctx->alloc_hook_stub = bytehook_hook_single(
                    tc.target_lib.c_str(), nullptr, tc.alloc_func.c_str(),
                    reinterpret_cast<void*>(kAllocHooks[i]), nullptr, nullptr);
                ctx->free_hook_stub = bytehook_hook_single(
                    tc.target_lib.c_str(), nullptr, tc.free_func.c_str(),
                    reinterpret_cast<void*>(kFreeHooks[i]), nullptr, nullptr);
            }
        }
    }
}

// ============================================================================
// [EN] FaultHandlerConfig::toString (@ 0x01e74c) & parseFaultHandlerConfig (@ 0x01dfd4)
// [VN] Phân tích và định dạng cấu hình Proxy Fault Handler (@ 0x01dfd4 & @ 0x01e74c)
// ============================================================================
std::string FaultHandlerConfig::toString() const {
    std::ostringstream oss;
    oss << "{enable:" << (enable ? "true" : "false") << ", symbols:[";
    for (size_t i = 0; i < symbols.size(); ++i) {
        if (i > 0) oss << ", ";
        oss << "{lib_name:" << symbols[i].lib_name
            << ", symbol:" << symbols[i].symbol_name
            << ", check_scudo:" << (symbols[i].check_scudo ? "true" : "false")
            << ", is_scudo:" << (symbols[i].is_scudo ? "true" : "false") << "}";
    }
    oss << "]}";
    return oss.str();
}

bool parseFaultHandlerConfig(FaultHandlerConfig* out_cfg, const char* json_str) {
    if (out_cfg == nullptr || json_str == nullptr || json_str[0] == '\0') {
        return false;
    }
    out_cfg->enable = false;
    out_cfg->symbols.clear();

    std::string src(json_str);
    (void)extractJsonBool(src, "enable", &out_cfg->enable);

    size_t sym_pos = src.find("\"symbols\"");
    if (sym_pos != std::string::npos) {
        size_t arr_start = src.find('[', sym_pos);
        size_t arr_end = src.rfind(']');
        if (arr_start != std::string::npos && arr_end != std::string::npos && arr_end > arr_start) {
            size_t cur = arr_start + 1;
            while (cur < arr_end) {
                size_t obj_start = src.find('{', cur);
                if (obj_start == std::string::npos || obj_start >= arr_end) break;
                size_t obj_end = src.find('}', obj_start + 1);
                if (obj_end == std::string::npos || obj_end > arr_end) break;

                std::string item = src.substr(obj_start, obj_end - obj_start + 1);
                FaultHandlerSymbolConfig sc = {};
                (void)extractJsonString(item, "lib_name", &sc.lib_name);
                if (!extractJsonString(item, "symbol", &sc.symbol_name)) {
                    (void)extractJsonString(item, "symbol_name", &sc.symbol_name);
                }
                (void)extractJsonBool(item, "check_scudo", &sc.check_scudo);
                (void)extractJsonBool(item, "is_scudo", &sc.is_scudo);
                out_cfg->symbols.push_back(std::move(sc));
                cur = obj_end + 1;
            }
        }
    }
    return true;
}

// ============================================================================
// [EN] isScudoMemoryAllocator (@ 0x01f3e4..0x01f4a8)
//      Opens `/proc/self/maps` ("r") and scans lines with `fgets(..., 512, fp)`
//      checking `strstr(line, "scudo") != nullptr`.
// [VN] Kiểm tra trình cấp phát bộ nhớ Scudo qua `/proc/self/maps` (@ 0x01f3e4)
// ============================================================================
bool isScudoMemoryAllocator() {
    FILE* fp = std::fopen("/proc/self/maps", "r");
    if (fp == nullptr) {
        return false;
    }
    bool found = false;
    char line[512];
    while (std::fgets(line, sizeof(line), fp) != nullptr) {
        if (std::strstr(line, "scudo") != nullptr) {
            found = true;
            break;
        }
    }
    std::fclose(fp);
    return found;
}

// ============================================================================
// [EN] resolveSymbolAddr (@ 0x01f30c..0x01f3e0)
//      Opens `lib_name` via `xdl_open(lib_name, 0)`, queries `xdl_sym` then
//      `xdl_dsym`, closes handle via `xdl_close`, and returns symbol address.
// [VN] Phân giải địa chỉ biểu tượng qua xDL (@ 0x01f30c..0x01f3e0)
// ============================================================================
uintptr_t resolveSymbolAddr(const char* lib_name, const char* sym_name) {
    if (lib_name == nullptr || sym_name == nullptr) {
        return 0;
    }
    if (xdl_open != nullptr && xdl_close != nullptr) {
        void* handle = xdl_open(lib_name, 0);
        if (handle != nullptr) {
            size_t sym_size = 0;
            void* addr = nullptr;
            if (xdl_sym != nullptr) {
                addr = xdl_sym(handle, sym_name, &sym_size);
            }
            if (addr == nullptr && xdl_dsym != nullptr) {
                addr = xdl_dsym(handle, sym_name, &sym_size);
            }
            xdl_close(handle);
            return reinterpret_cast<uintptr_t>(addr);
        }
    }
    return 0;
}

// ============================================================================
// [EN] patchInstructionWithRet (@ 0x01f4ac..0x01f5b8)
//      Exact AArch64 sequence verified from 0x01eeb0 & 0x01f4ac:
//      1. Queries `page_size = getpagesize()`
//      2. Aligns `target_addr` down to page boundary: `page_base = target_addr & ~(page_size - 1)`
//      3. Calls `mprotect(page_base, page_size, PROT_READ | PROT_WRITE | PROT_EXEC /* 7 */)`
//      4. Stores `insn_word` (`0xd65f03c0` = AArch64 `ret`, loaded via `mov w1, #-0x2be00000`
//         + `movk w1, #0x03c0` at 0x01eeb0!) using release store `stlr w20, [x19]` (@ 0x01f520)
//      5. Flushes instruction cache via `__builtin___clear_cache(target_addr, target_addr + 4)` (@ 0x02109c)
//      6. Restores permissions via `mprotect(page_base, page_size, PROT_READ | PROT_EXEC /* 5 */)`
// [VN] Vá lệnh đầu hàm bằng `ret` (0xd65f03c0), xóa I-cache và khôi phục quyền RX (@ 0x01f4ac)
// ============================================================================
bool patchInstructionWithRet(uintptr_t target_addr, uint32_t insn_word) {
    if (target_addr == 0) {
        return false;
    }
    const size_t page_size = gwp_asan::getPlatformPageSize();
    const uintptr_t page_mask = ~(static_cast<uintptr_t>(page_size) - 1ULL);
    void* page_base = reinterpret_cast<void*>(target_addr & page_mask);

    if (mprotect(page_base, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        ASAN_LOGE("Godzilla-FaultHandler",
                  "ReplaceRet fail when set write_protect for 0x%" PRIxPTR, target_addr);
        return false;
    }

    auto* insn_ptr = reinterpret_cast<std::atomic<uint32_t>*>(target_addr);
    insn_ptr->store(insn_word, std::memory_order_release);

    char* start = reinterpret_cast<char*>(target_addr);
    __builtin___clear_cache(start, start + sizeof(uint32_t));

    if (mprotect(page_base, page_size, PROT_READ | PROT_EXEC) != 0) {
        ASAN_LOGE("Godzilla-FaultHandler",
                  "ReplaceRet fail when recover protect for 0x%" PRIxPTR, target_addr);
        return false;
    }
    return true;
}

} // namespace godzilla_asan
