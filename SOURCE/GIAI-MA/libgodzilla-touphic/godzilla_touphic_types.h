/**
 * @file godzilla_touphic_types.h
 * @brief Exact ABI Structs, Memory Map, Constants, and External Hook Declarations for libgodzilla-touphic.so
 *        Cấu trúc ABI chính xác, Bản đồ bộ nhớ, Hằng số và Khai báo Hook ngoại vi cho libgodzilla-touphic.so
 *
 * BinaryTarget / Đích nhị phân:
 *   apktool-res/lib/arm64-v8a/libgodzilla-touphic.so (65,304 bytes, 26 ELF64 sections, 112 .dynsym entries)
 * Package / Gói:
 *   com.bytedance.platform.godzilla.touphic (ByteDance Godzilla Touphic Crash-Mitigation Framework)
 * Evidence Classification / Phân loại bằng chứng:
 *   OBSERVED — Directly verified from AArch64 machine code (.text 0x0070e0..0x00e92c) and ELF64 sections.
 */

#ifndef OPENCUT_GODZILLA_TOUPHIC_TYPES_H_
#define OPENCUT_GODZILLA_TOUPHIC_TYPES_H_

#include <jni.h>
#include <pthread.h>
#include <semaphore.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <mutex>
#include <string>

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {

// ============================================================================
// 1. BINARY CONSTANTS & MAGIC VALUES / HẰNG SỐ NHỊ PHÂN & GIÁ TRỊ MA THUẬT
// ============================================================================

/**
 * @brief Magic cookie stored in TryExecuteTask::magic (`0x1a2b3c4d`) to verify active safe_execute frame.
 *        Giá trị ma thuật lưu tại TryExecuteTask::magic (`0x1a2b3c4d`) để xác thực khung safe_execute đang hoạt động.
 * Disassembly:
 *   0x007144: mov  w9, #0x3c4d
 *   0x007154: movk w9, #0x1a2b, lsl #16
 */
static constexpr uint32_t kTryExecuteMagic = 0x1a2b3c4dU;

/**
 * @brief Signal callback return code (`0x00aabbcc`) indicating signal should be bypassed via siglongjmp.
 *        Mã trả về của callback tín hiệu (`0x00aabbcc`) báo hiệu cần bỏ qua tín hiệu qua siglongjmp.
 * Disassembly:
 *   0x0072ec: mov  w0, #0xbbcc
 *   0x0072f0: movk w0, #0xaa, lsl #16
 */
static constexpr uint32_t kSignalBypassReturn = 0x00aabbccU;

/**
 * @brief Signal callback return code (`0x00112358`) indicating signal should NOT be bypassed (chain/resend).
 *        Mã trả về của callback tín hiệu (`0x00112358`) báo hiệu KHÔNG bỏ qua tín hiệu (chuyển tiếp/gửi lại).
 * Disassembly:
 *   0x007320: mov  w0, #0x2358
 *   0x007324: movk w0, #0x11, lsl #16
 *   0x00de2c: sub  w8, w21, #0x112, lsl #12
 *   0x00de30: cmp  w8, #0x358
 */
static constexpr uint32_t kSignalPassThroughReturn = 0x00112358U;

/**
 * @brief CityHash64 / MurmurHash64A multiplier `kMul = 0x9ddfea08eb382d69ULL` used in pointer hash tables.
 *        Hệ số nhân CityHash64 / MurmurHash64A `kMul = 0x9ddfea08eb382d69ULL` dùng trong bảng băm con trỏ.
 * Disassembly:
 *   0x007c58: mov  x11, #0x2d69
 *   0x007c60: movk x11, #0xeb38, lsl #16
 *   0x007c6c: movk x11, #0xea08, lsl #32
 *   0x007c74: movk x11, #0x9ddf, lsl #48
 */
static constexpr uint64_t kCityHash64Mul = 0x9ddfea08eb382d69ULL;

/**
 * @brief Intentional damage words (`0xabcdabcd`, `0x1122abcd`) used in ChromeSupportOpt_setDamageWebview.
 *        Các từ làm hỏng chủ đích (`0xabcdabcd`, `0x1122abcd`) dùng trong ChromeSupportOpt_setDamageWebview.
 * Disassembly:
 *   0x0089b4: mov  w8, #0xabcd
 *   0x0089b8: mov  w9, #0xabcd
 *   0x0089bc: movk w8, #0xabcd, lsl #16
 *   0x0089c0: movk w9, #0x1122, lsl #16
 */
static constexpr uint32_t kWebviewDamageLow  = 0xabcdabcdU;
static constexpr uint32_t kWebviewDamageHigh = 0x1122abcdU;

/**
 * @brief Packed 8-byte ASCII constant `"GWP-ASan"` (`0x6e6153412d505747ULL`) checked in `/proc/%d/maps`.
 *        Hằng số ASCII 8 byte đóng gói `"GWP-ASan"` (`0x6e6153412d505747ULL`) kiểm tra trong `/proc/%d/maps`.
 * Disassembly:
 *   0x00ac14: mov  x28, #0x5747         // 'GW'
 *   0x00ac1c: movk x28, #0x2d50, lsl #16 // 'P-'
 *   0x00ac24: movk x28, #0x5341, lsl #32 // 'AS'
 *   0x00ac2c: movk x28, #0x6e61, lsl #48 // 'an'
 */
static constexpr uint64_t kGwpAsanSignature = 0x6e6153412d505747ULL;

/**
 * @brief HWUI Layer tile alignment (`LAYER_SIZE = 64`, mask `0x3f`) in CreateLayerOpt.
 *        Căn chỉnh ô lớp HWUI (`LAYER_SIZE = 64`, mặt nạ `0x3f`) trong CreateLayerOpt.
 * Disassembly:
 *   0x009590: tst w20, #0x3f
 *   0x009764: sub w8, w8, #0x3f
 */
static constexpr int32_t kHwuiLayerSize     = 64;
static constexpr int32_t kHwuiLayerSizeMask = 0x3f;

/**
 * @brief Linux AArch64 `tgkill` syscall number (`__NR_tgkill = 240 = 0xf0`).
 *        Số syscall `tgkill` trên Linux AArch64 (`__NR_tgkill = 240 = 0xf0`).
 * Disassembly:
 *   0x00df10: mov w0, #0xf0
 *   0x00df1c: bl  #0xedf0 (syscall)
 */
static constexpr long kSysTgkillAArch64 = 240L;

// ============================================================================
// 2. ABI STRUCTURES / CẤU TRÚC ABI CHUẨN XÁC
// ============================================================================

/**
 * @brief 32-byte task descriptor passed to `safe_execute(TryExecuteTask*, void*)` (`0x00db4c`).
 *        Cấu trúc mô tả tác vụ 32 byte truyền vào `safe_execute(TryExecuteTask*, void*)` (`0x00db4c`).
 *
 * Layout verified at `0x007170..0x00717c`, `0x0074d4..0x0074dc`, `0x00db5c..0x00dc28`:
 *   - `+0x00`: `uint32_t magic` (`0x1a2b3c4d` while executing, cleared to `0` on exit/longjmp)
 *   - `+0x04`: `uint32_t reserved` (`0`)
 *   - `+0x08`: `uint64_t result` (return value of `target_fn(arg)` stored at `[x19, #8]` @ `0x00dc28`)
 *   - `+0x10`: `uint64_t (*target_fn)(void*)` (invoked at `0x00dc10..0x00dc18`)
 *   - `+0x18`: `uint32_t (*sig_callback)(int* sig_ptr)` (optional signal filter invoked at `0x00ddf8..0x00de04`)
 */
struct TryExecuteTask {
    uint32_t magic;                            // +0x00: 0x1a2b3c4d
    uint32_t reserved;                         // +0x04: padding
    uint64_t result;                           // +0x08: return value from target_fn
    uint64_t (*target_fn)(void* arg);          // +0x10: function to execute under sigsetjmp
    uint32_t (*sig_callback)(int* signo_ptr);  // +0x18: optional signal filter callback
};
static_assert(sizeof(TryExecuteTask) == 0x20, "TryExecuteTask must be 32 bytes");

/**
 * @brief 40-byte (`0x28`) signal slot entry in `.data` `sSignalSlots[4]` (`0x017620..0x0176b8`).
 *        Phần tử khe tín hiệu 40 byte (`0x28`) trong `.data` `sSignalSlots[4]` (`0x017620..0x0176b8`).
 *
 * Verified at `0x00dc98..0x00dd6c` and `0x00de64..0x00dedc` (`umaddl x8, w8, w9, x10` with `w9 = 0x28`):
 *   - `[0]` (`0x017620`): `signo = 6`  (`SIGABRT`)
 *   - `[1]` (`0x017648`): `signo = 5`  (`SIGTRAP`)
 *   - `[2]` (`0x017670`): `signo = 11` (`SIGSEGV`)
 *   - `[3]` (`0x017698`): `signo = 7`  (`SIGBUS`)
 */
struct SignalSlot {
    int32_t signo;                  // +0x00: signal number (6, 5, 11, 7)
    int32_t padding;                // +0x04: alignment padding
    struct sigaction old_action;    // +0x08: previous sigaction (32 bytes on AArch64 Bionic)
};
static_assert(sizeof(SignalSlot) == 0x28, "SignalSlot must be 40 bytes");

/**
 * @brief Per-thread UFFD GC backoff state (`8 bytes`) stored in `sUffdGcTlsKey` (`0x017808`).
 *        Trạng thái lùi UFFD GC theo luồng (`8 bytes`) lưu tại `sUffdGcTlsKey` (`0x017808`).
 *
 * Verified at `0x00a360..0x00a3f0`:
 *   - `+0x00`: `int32_t depth` (recursion depth of SignalChain::Handler)
 *   - `+0x04`: `int32_t retry_count` (number of backoff `usleep` retries executed)
 */
struct UffdGcTlsState {
    int32_t depth;        // +0x00
    int32_t retry_count;  // +0x04
};
static_assert(sizeof(UffdGcTlsState) == 0x08, "UffdGcTlsState must be 8 bytes");

/**
 * @brief Node in `MakeFromTextureOptS` unordered_map<AutoBackendTextureRelease*, bool> (`32 bytes = 0x20`).
 *        Nút trong bảng băm `MakeFromTextureOptS` unordered_map<AutoBackendTextureRelease*, bool> (`32 bytes = 0x20`).
 *
 * Verified at `0x008148..0x00816c`:
 *   - `+0x00`: `TextureReleaseHashNode* next`
 *   - `+0x08`: `uint64_t hash`
 *   - `+0x10`: `void* key` (`AutoBackendTextureRelease*`)
 *   - `+0x18`: `uint8_t is_making_image` (`bool`)
 */
struct TextureReleaseHashNode {
    TextureReleaseHashNode* next;  // +0x00
    uint64_t hash;                 // +0x08
    void* key;                     // +0x10
    uint8_t is_making_image;       // +0x18
    uint8_t padding[7];            // +0x19..0x1f
};
static_assert(sizeof(TextureReleaseHashNode) == 0x20, "TextureReleaseHashNode must be 32 bytes");

/**
 * @brief Node in `GLESAdrenoOpt` Double-Free Quarantine hash set (`24 bytes = 0x18`).
 *        Nút trong tập băm cách ly Double-Free của `GLESAdrenoOpt` (`24 bytes = 0x18`).
 *
 * Verified at `0x00b7b8..0x00b7cc`:
 *   - `+0x00`: `AdrenoFreeHashNode* next`
 *   - `+0x08`: `uint64_t hash`
 *   - `+0x10`: `void* ptr` (quarantined heap pointer)
 */
struct AdrenoFreeHashNode {
    AdrenoFreeHashNode* next;  // +0x00
    uint64_t hash;             // +0x08
    void* ptr;                 // +0x10
};
static_assert(sizeof(AdrenoFreeHashNode) == 0x18, "AdrenoFreeHashNode must be 24 bytes");

/**
 * @brief Per-thread quarantine table (`56 bytes = 0x38`) for `GLESAdrenoOpt_nativeInitDoubleFreeOpt`.
 *        Bảng cách ly theo luồng (`56 bytes = 0x38`) cho `GLESAdrenoOpt_nativeInitDoubleFreeOpt`.
 *
 * Verified at `0x00b0dc`, `0x00b23c`, `0x00b2cc..0x00b31c`:
 *   - `+0x00`: `uint8_t is_destroying` (set to `1` in `egl_destruct_tls_data_proxy` @ `0x00b260`)
 *   - `+0x04`: `int32_t dtor_calls` (incremented up to 3 times in `free_tls_destructor` @ `0x00af0c..0x00af18`)
 *   - `+0x08`: `AdrenoFreeHashNode** buckets`
 *   - `+0x10`: `uint64_t bucket_count`
 *   - `+0x18`: `AdrenoFreeHashNode* before_begin`
 *   - `+0x20`: `uint64_t element_count`
 *   - `+0x28`: `float max_load_factor` (`0.2f = 0x3e4ccccd` @ `0x00b2e0..0x00b2fc`)
 *   - `+0x30`: `uint64_t max_slot_capacity` (`sSlotSize` from `0x017618`)
 */
struct AdrenoDoubleFreeQuarantine {
    uint8_t is_destroying;             // +0x00
    uint8_t pad0[3];                   // +0x01..0x03
    int32_t dtor_calls;                // +0x04
    AdrenoFreeHashNode** buckets;      // +0x08
    uint64_t bucket_count;             // +0x10
    AdrenoFreeHashNode* before_begin;  // +0x18
    uint64_t element_count;            // +0x20
    float max_load_factor;             // +0x28: 0.2f (0x3e4ccccd)
    uint32_t pad1;                     // +0x2c
    uint64_t max_slot_capacity;        // +0x30
};
static_assert(sizeof(AdrenoDoubleFreeQuarantine) == 0x38, "AdrenoDoubleFreeQuarantine must be 56 bytes");

/**
 * @brief Mode 1 (Alpha) configuration struct (`128 bytes = 0x80`) for `GLESAdrenoOpt_nativeInitUafOpt`.
 *        Cấu trúc cấu hình Chế độ 1 (Alpha) (`128 bytes = 0x80`) cho `GLESAdrenoOpt_nativeInitUafOpt`.
 *
 * Allocated via `operator new(0x80)` at `0x00c994`, `0x00cd38`, `0x00cedc` and stored at `0x017850`.
 */
struct AdrenoUafAlphaConfig {
    pthread_key_t tls_key;                 // +0x00: TLS key for AlphaPerThreadState (24 bytes)
    uint32_t pad0;                         // +0x04
    std::string target_symbol;             // +0x08..0x1f (24 bytes)
    std::string list_node_insert_symbol;   // +0x20..0x37 (24 bytes)
    std::string find_or_insert_symbol;     // +0x38..0x4f (24 bytes)
    int32_t call_calloc_offset;            // +0x50
    int32_t call_free_offset;              // +0x54
    int32_t point_state_list_mgr_offset;   // +0x58
    int32_t slot_entry_temp_buffer_offset; // +0x5c
    int32_t slot_entry_flags_offset;       // +0x60
    int32_t pad1;                          // +0x64
    uintptr_t target_addr;                 // +0x68
    uintptr_t find_or_insert_node_addr;    // +0x70
    uintptr_t list_node_insert_addr;       // +0x78
};
static_assert(sizeof(AdrenoUafAlphaConfig) == 0x80, "AdrenoUafAlphaConfig must be 128 bytes");

/**
 * @brief Per-thread state (`24 bytes = 0x18`) stored in `AdrenoUafAlphaConfig::tls_key` (`0x00cc08`).
 *        Trạng thái theo luồng (`24 bytes = 0x18`) lưu tại `AdrenoUafAlphaConfig::tls_key` (`0x00cc08`).
 */
struct AdrenoUafAlphaTlsState {
    uint64_t temp_buffer_size;  // +0x00: nmemb * size from before_calloc tracepoint (0x00cc2c)
    uintptr_t temp_buffer_addr; // +0x08: returned pointer from after_calloc tracepoint (0x00cb7c)
    uintptr_t current_ps_addr;  // +0x10: active point_state pointer during findOrInsertNode (0x00ccac)
};
static_assert(sizeof(AdrenoUafAlphaTlsState) == 0x18, "AdrenoUafAlphaTlsState must be 24 bytes");

/**
 * @brief Mode 2 (Beta) configuration struct (`96 bytes = 0x60`) for `GLESAdrenoOpt_nativeInitUafOpt`.
 *        Cấu trúc cấu hình Chế độ 2 (Beta) (`96 bytes = 0x60`) cho `GLESAdrenoOpt_nativeInitUafOpt`.
 *
 * Allocated via `operator new(0x60)` at `0x00c9d4` and stored at `0x017860`.
 */
struct AdrenoUafBetaConfig {
    pthread_key_t tls_key;                 // +0x00: TLS key for BetaPerThreadState (16 bytes)
    uint32_t pad0;                         // +0x04
    std::string target_symbol;             // +0x08..0x1f (24 bytes)
    int32_t call_calloc_offset;            // +0x20
    int32_t call_free_offset;              // +0x24
    int32_t call_list_foreach_offset;      // +0x28
    int32_t point_state_register_number;   // +0x2c
    int32_t point_state_node_count_offset; // +0x30
    int32_t point_state_list_head_offset;  // +0x34
    int32_t point_state_list_tail_offset;  // +0x38
    int32_t list_node_slot_entry_offset;   // +0x3c
    int32_t list_node_prev_offset;         // +0x40
    int32_t list_node_next_offset;         // +0x44
    int32_t slot_entry_temp_buffer_offset; // +0x48
    int32_t slot_entry_flags_offset;       // +0x4c
    int32_t size_of_per_temp_buffer;       // +0x50
    int32_t pad1;                          // +0x54
    uintptr_t target_addr;                 // +0x58
};
static_assert(sizeof(AdrenoUafBetaConfig) == 0x60, "AdrenoUafBetaConfig must be 96 bytes");

/**
 * @brief Per-thread state (`16 bytes = 0x10`) stored in `AdrenoUafBetaConfig::tls_key` (`0x00d3b0`).
 *        Trạng thái theo luồng (`16 bytes = 0x10`) lưu tại `AdrenoUafBetaConfig::tls_key` (`0x00d3b0`).
 */
struct AdrenoUafBetaTlsState {
    uint64_t temp_buffer_size;  // +0x00: nmemb * size from before_calloc tracepoint (0x00d3d0)
    uintptr_t temp_buffer_addr; // +0x08: returned pointer from after_calloc tracepoint (0x00d324)
};
static_assert(sizeof(AdrenoUafBetaTlsState) == 0x10, "AdrenoUafBetaTlsState must be 16 bytes");

/**
 * @brief Node in the instruction tracepoint Red-Black Tree (`48 bytes = 0x30`) at `0x0176c0..0x0176d0`.
 *        Nút trong Cây Đỏ-Đen điểm vết lệnh (`48 bytes = 0x30`) tại `0x0176c0..0x0176d0`.
 *
 * Verified at `0x00e23c..0x00e428`:
 *   - `+0x00`: `TracepointRbNode* left`
 *   - `+0x08`: `TracepointRbNode* right`
 *   - `+0x10`: `TracepointRbNode* parent`
 *   - `+0x18`: `uint8_t is_black`
 *   - `+0x20`: `void* stub_token` (returned by `shadowhook_intercept_instr_addr`)
 *   - `+0x28`: `void* closure_box` (64-byte `std::function<void(ShadowHookCpuContext*)>` box)
 */
struct TracepointRbNode {
    TracepointRbNode* left;        // +0x00
    TracepointRbNode* right;       // +0x08
    TracepointRbNode* parent;      // +0x10
    uint8_t is_black;              // +0x18
    uint8_t pad[7];                // +0x19..0x1f
    void* stub_token;              // +0x20
    void* closure_box;             // +0x28
};
static_assert(sizeof(TracepointRbNode) == 0x30, "TracepointRbNode must be 48 bytes");

/**
 * @brief AArch64 CPU context passed by ShadowHook to instruction interceptors (`shadowhook_cpu_context_t`).
 *        Ngữ cảnh CPU AArch64 được ShadowHook truyền vào các hàm chặn lệnh (`shadowhook_cpu_context_t`).
 *
 * Verified at `0x00a260..0x00a2b4` (`GLESMaliOpt` reads `regs[8]` at `+0x40` and `regs[20]` at `+0xa0`):
 *   - `regs[0..30]` at `+0x00..+0xf0` (`regs[8]` = `+0x40`, `regs[20]` = `+0xa0`)
 *   - `sp` at `+0xf8`
 *   - `pc` at `+0x100`
 *   - `pstate` at `+0x108`
 */
struct ShadowHookCpuContext {
    uint64_t regs[31];  // +0x00..+0xf0 (x0..x30)
    uint64_t sp;        // +0xf8
    uint64_t pc;        // +0x100
    uint64_t pstate;    // +0x108
};

}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance

// ============================================================================
// 3. EXTERNAL HOOK & DLOPEN DECLARATIONS / KHAI BÁO HÀM HOOK & DLOPEN NGOẠI VI
// ============================================================================

extern "C" {

// ShadowHook API (.dynsym [004..008], [014], [029..031], [033], [035..036], [042], [059], [061])
int shadowhook_init(int mode, bool debuggable);
void* shadowhook_hook_sym_addr(void* sym_addr, void* new_addr, void** orig_addr);
void* shadowhook_hook_sym_addr_2(void* sym_addr, void* new_addr, void** orig_addr, uint32_t flags);
void* shadowhook_hook_func_addr(void* func_addr, void* new_addr, void** orig_addr);
void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr);
void* shadowhook_intercept_sym_name(const char* lib_name, const char* sym_name,
                                    void (*pre)(bytedance::platform::godzilla::touphic::ShadowHookCpuContext*, void*),
                                    void* data, uint32_t flags);
void* shadowhook_intercept_instr_addr(void* instr_addr,
                                      void (*pre)(bytedance::platform::godzilla::touphic::ShadowHookCpuContext*, void*),
                                      void* data, uint32_t flags);
int shadowhook_unhook(void* stub);
void* shadowhook_get_prev_func(void* func);
void shadowhook_pop_stack(void* return_address);
int shadowhook_get_errno(void);
const char* shadowhook_to_errmsg(int error_number);
void* shadowhook_dlopen(const char* lib_name);
void shadowhook_dlclose(void* handle);
void* shadowhook_dlsym(void* handle, const char* sym_name);

// ByteHook API (.dynsym [019..023], [032], [066])
int bytehook_init(int mode, bool debug);
void* bytehook_hook_single(const char* caller_path_name, const char* callee_path_name,
                           const char* sym_name, void* new_func,
                           void (*hooked)(void* task_stub, int status_code, const char* caller_path_name,
                                          const char* sym_name, void* new_func, void* prev_func, void* arg),
                           void* arg);
int bytehook_unhook(void* stub);
void* bytehook_get_prev_func(void* func);
void bytehook_pop_stack(void* return_address);
int bytehook_get_mode(void);
void bytehook_set_debug(bool debug);

// NPTH Symbol Resolver API (.dynsym [009..012], [056], [076..077])
void* npth_dlopen(const char* filename);
void npth_dlclose(void* handle);
void* npth_dlsym(void* handle, const char* symbol);
void* npth_dlsym_symtab(void* handle, const char* symbol);
void* npth_dlsym_size(void* handle, const char* symbol, size_t* out_size);
void* npth_dlsym_symtab_size(void* handle, const char* symbol, size_t* out_size);
const char* npth_dlerror(void);

}  // extern "C"

#endif  // OPENCUT_GODZILLA_TOUPHIC_TYPES_H_
