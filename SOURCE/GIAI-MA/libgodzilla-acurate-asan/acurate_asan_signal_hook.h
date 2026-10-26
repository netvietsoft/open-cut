// ============================================================================
// File: acurate_asan_signal_hook.h
// Target: libgodzilla-acurate-asan.so (160,168 bytes)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Declarations for AcurateAsan JSON config parser,
//                   ELF NT_GNU_BUILD_ID note scanner, SIGSEGV crash report
//                   generator (`tombstone.txt`, `glog.txt`, `maps.txt`),
//                   FP/DWARF unwinders, ShadowHook/ByteHook allocator hooks,
//                   and Scudo Proxy Fault Handler (`initProxyFaultHandler`).
// Mô tả (VN): Khai báo cho bộ phân tích cấu hình JSON AcurateAsan, bộ quét
//             NT_GNU_BUILD_ID ELF, trình tạo báo cáo sự cố SIGSEGV, bộ lần
//             ngược ngăn xếp FP/DWARF, các hook cấp phát ShadowHook/ByteHook
//             và bộ xử lý lỗi ủy nhiệm Scudo (`initProxyFaultHandler`).
// ============================================================================

#pragma once

#include "godzilla_acurate_asan_types.h"
#include "guarded_pool_allocator.h"

namespace godzilla_asan {

// ============================================================================
// [EN] Global state in .data (@ 0x02e8dc..0x02e8ec) and .bss (@ 0x02e930..0x05e9f0)
// [VN] Trạng thái toàn cục trong .data (@ 0x02e8dc..0x02e8ec) và .bss (@ 0x02e930..0x05e9f0)
// ============================================================================
extern int g_tombstone_fd;                          // .data @ 0x02e8dc (-1)
extern int g_glog_fd;                               // .data @ 0x02e8e0 (-1)
extern pthread_key_t g_signal_reentrancy_key;       // .data @ 0x02e8e4 (-1)
extern pthread_key_t g_custom_hook_tls_key;         // .data @ 0x02e8e8 (0x7a8b9cde)
extern pthread_key_t g_dwarf_unwind_tls_key;        // .data @ 0x02e8ec (0x7a8b9cef)

extern char g_build_id_map_values[512][128];        // .bss @ 0x02e930 (65,536 B)
extern char g_build_id_map_keys[512][256];          // .bss @ 0x03e930 (131,072 B)
extern uint32_t g_build_id_map_count;               // .bss @ 0x05e930
extern struct sigaction g_previous_sigsegv_action;  // .bss @ 0x05e938 (32 B)
extern bool g_signal_handler_installed;             // .bss @ 0x05e958
extern gwp_asan::GuardedPoolAllocator* g_signal_allocator; // .bss @ 0x05e960
extern std::string g_dump_dir;                      // .bss @ 0x05e968
extern pthread_mutex_t g_signal_dump_mutex;         // .bss @ 0x05e980
extern bool g_bytehook_initialized;                 // .bss @ 0x05e9a8
extern void* g_libc_free_hook_stub;                 // .bss @ 0x05e9b0
extern gwp_asan::GuardedPoolAllocator* g_hook_allocator; // .bss @ 0x05e9b8
extern std::vector<CustomHookContext*> g_custom_hook_contexts; // .bss @ 0x05e9c0

// [EN] Parse JSON string into AcurateAsanConfig (@ 0x00ec3c)
// [VN] Phân tích chuỗi JSON thành cấu trúc AcurateAsanConfig (@ 0x00ec3c)
bool parseAcurateAsanConfig(AcurateAsanConfig* out_config, const char* json_str);

// [EN] Format AcurateAsanConfig as human-readable log string (@ 0x00f8e8)
// [VN] Định dạng cấu hình AcurateAsanConfig thành chuỗi nhật ký (@ 0x00f8e8)
std::string formatAcurateAsanConfig(const AcurateAsanConfig& cfg);

// [EN] Scan loaded ELF phdrs via dl_iterate_phdr to populate BuildId cache (@ 0x01305c)
// [VN] Quét các chương trình ELF qua dl_iterate_phdr để lưu bộ nhớ đệm BuildId (@ 0x01305c)
void cacheLoadedSharedLibBuildIds();

// [EN] Look up cached NT_GNU_BUILD_ID hex string for a shared library path (@ 0x013250)
// [VN] Tra cứu chuỗi hex NT_GNU_BUILD_ID đã lưu cho đường dẫn thư viện (@ 0x013250)
const char* findCachedBuildId(const char* dli_fname);

// [EN] Write formatted GWP-ASan crash report to tombstone.txt & logcat (@ 0x0132b8)
// [VN] Ghi báo cáo sự cố GWP-ASan định dạng đầy đủ vào tombstone.txt & logcat (@ 0x0132b8)
void dumpErrorReport(const gwp_asan::AllocatorState* state,
                     const gwp_asan::AllocationMetadata* metadata,
                     uintptr_t fault_addr,
                     bool recoverable,
                     gwp_asan::Options::Backtrace_t backtrace_fn);

// [EN] Install SIGSEGV handler and initialize dump directory (@ 0x014344)
// [VN] Cài đặt trình xử lý tín hiệu SIGSEGV và khởi tạo thư mục lưu vết (@ 0x014344)
void initSignalAndBacktrace(gwp_asan::GuardedPoolAllocator* alloc,
                            const std::string& dump_dir,
                            bool enable_dwarf,
                            bool recoverable);

// [EN] Fast AArch64 frame-pointer (x29) unwinder (@ 0x01d5a8)
// [VN] Bộ lần ngược ngăn xếp nhanh qua thanh ghi con trỏ khung x29 (@ 0x01d5a8)
size_t getBacktraceFastFP(uintptr_t* trace_buffer, size_t max_depth);

// [EN] DWARF/unwindstack unwinder with TLS reentrancy guard 0xdeadbeef (@ 0x01d684)
// [VN] Bộ lần ngược ngăn xếp DWARF/unwindstack có khóa chống đệ quy TLS 0xdeadbeef (@ 0x01d684)
size_t getBacktraceDwarf(uintptr_t* trace_buffer, size_t max_depth);

// [EN] Install ShadowHook / ByteHook custom allocator hooks (@ 0x014ce8)
// [VN] Cài đặt các hook bộ cấp phát tùy chỉnh qua ShadowHook / ByteHook (@ 0x014ce8)
void startCustomHooks(gwp_asan::GuardedPoolAllocator* alloc,
                      const AcurateAsanConfig& cfg);

// [EN] Parse JSON config for Proxy Fault Handler (@ 0x01dfd4)
// [VN] Phân tích cấu hình JSON cho Proxy Fault Handler (@ 0x01dfd4)
bool parseFaultHandlerConfig(FaultHandlerConfig* out_cfg, const char* json_str);

// [EN] Check whether `/proc/self/maps` contains `"scudo"` (@ 0x01f3e4)
// [VN] Kiểm tra `/proc/self/maps` có chứa chuỗi `"scudo"` hay không (@ 0x01f3e4)
bool isScudoMemoryAllocator();

// [EN] Resolve symbol address via xdl_open / xdl_sym / xdl_dsym (@ 0x01f30c)
// [VN] Phân giải địa chỉ biểu tượng qua xdl_open / xdl_sym / xdl_dsym (@ 0x01f30c)
uintptr_t resolveSymbolAddr(const char* lib_name, const char* sym_name);

// [EN] Patch target function prologue with `ret` (0xd65f03c0) and flush I-cache (@ 0x01f4ac)
// [VN] Vá lệnh đầu hàm mục tiêu bằng lệnh `ret` (0xd65f03c0) và xóa bộ đệm lệnh (@ 0x01f4ac)
bool patchInstructionWithRet(uintptr_t target_addr, uint32_t insn_word = 0xd65f03c0U);

} // namespace godzilla_asan
