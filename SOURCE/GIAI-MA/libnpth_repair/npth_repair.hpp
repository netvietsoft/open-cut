/**
 * @file npth_repair.hpp
 * @brief Clean-room C++17 Reconstruction of ByteDance Npth Native Crash Repair & Signal Monitor (`libnpth_repair.so`).
 *        Tái cấu trúc sạch C++17 của Bộ sửa lỗi Crash Native Npth & Giám sát Tín hiệu (`libnpth_repair.so`).
 *
 * Binary Metadata / Siêu dữ liệu nhị phân:
 *   - File Size / Dung lượng: 27,896 bytes
 *   - SHA-256: ddf5f8b8929bd70444c23ac90cc8b5434d7f681755f56d7c14f8300a2393338e
 *   - Architecture / Kiến trúc: AArch64 (ARM64-v8a, BTI/PAC-enabled)
 *   - .rodata:       0x002070..0x0026a8 (1,592 bytes)
 *   - .eh_frame_hdr: 0x0026a8..0x0028a4 (508 bytes, 62 FDEs)
 *   - .eh_frame:     0x0028a8..0x003294 (2,540 bytes)
 *   - .text:         0x0032a0..0x00590c (9,836 bytes, 2,459 AArch64 instructions)
 *   - .plt:          0x005910..0x005d60 (1,104 bytes, 276 AArch64 instructions)
 *   - .data.rel.ro:  0x009d60..0x009e70 (272 bytes, file offset 0x005d60)
 *   - .init_array:   0x009e80..0x009e90 (16 bytes, file offset 0x005e80)
 *   - .data:         0x00e2d0..0x00e4b8 (488 bytes, file offset 0x0062d0)
 *   - .bss:          0x00e4c0..0x00e620 (352 bytes, file offset 0x0064b8)
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <jni.h>
#include <pthread.h>

namespace nextai::opencut::npth_repair {

/**
 * @brief Constants verified directly from AArch64 opcodes in `libnpth_repair.so`:
 *        Các hằng số được xác minh trực tiếp từ mã máy AArch64 trong `libnpth_repair.so`:
 */
constexpr int32_t  kRepairJniVersion1_6      = 0x00010006;           // mov w2, #6; movk w2, #1, lsl #16 @ 0x38bc..0x38c8
constexpr int32_t  kErrNotSupportedNeg111    = -0x6f;                // mov w0, #-0x6f (0x12800dc0) @ 0x3520, 0x3e1c, 0x3e3c, 0x3e44, 0x3e64
constexpr uint32_t kPrSetVmaOption           = 0x53564d41U;          // mov w8, #0x4d41; movk w8, #0x5356, lsl #16 ('SVMA' @ 0x3fb8..0x3fbc)
constexpr size_t   kScudoMaxVmaSize          = 0xa000U;              // cmp x21, #0xa, lsl #12 (40,960 B @ 0x3fcc)
constexpr int64_t  kMagicUsecToMsMultiplier  = 0x20c49ba5e353f7cfLL; // mov/movk x10 @ 0x373c..0x3748 for signed / 1000
constexpr size_t   kHookTableEntryStride     = 0x30U;                // 48 bytes per HookTableItem (@ 0x3488)
constexpr size_t   kSignalRecordStructSize   = 0x28U;                // 40 bytes per SignalMonitorRecord (calloc(1, 0x28) @ 0x50e0)
constexpr size_t   kSignalTableSlotCount     = 0x40U;                // 64 slots = 32 signals * 2 (calloc(0x40, 8) @ 0x43e4..0x43e8)

/**
 * @brief 48-byte (`0x30`) hook descriptor used by `hook_table` (`0x33f0..0x34d4`, FDE[08], 228 B).
 *        Cấu trúc mô tả hook 48 byte (`0x30`) dùng trong `hook_table` (`.data 0xe2d8..0xe4b8`, 10 phần tử).
 */
struct RepairHookItem {
    int32_t     hook_by_addr; // +0x00: 0 = shadowhook_hook_sym_name, 1 = shadowhook_hook_sym_addr (ldur w8, [x23, #-0x28] @ 0x345c)
    int32_t     hook_id;      // +0x04: Diagnostic hook identifier logged on failure (ldur w3, [x23, #-0x24] @ 0x34a4)
    int32_t     min_api;      // +0x08: Minimum Android SDK API level (ldp w0, w1, [x23, #-0x20] @ 0x3450)
    int32_t     max_api;      // +0x0c: Maximum Android SDK API level
    const char* lib_name;     // +0x10: Target library name ("libc.so" / "libsigchain.so", ldp x0, x1, [x23, #-0x18] @ 0x3434)
    const char* sym_name;     // +0x18: Target symbol name ("signal" / "bsd_signal" / "sigaction" / "sigaction64")
    void*       sym_addr;     // +0x20: Explicit symbol address if hook_by_addr != 0 (ldur x0, [x23, #-8] @ 0x3464)
    void*       new_func;     // +0x28: Replacement hook proxy function (ldr x2, [x23] @ 0x343c)
};
static_assert(sizeof(RepairHookItem) == kHookTableEntryStride, "RepairHookItem must be 0x30 (48) bytes");

/**
 * @brief 40-byte (`0x28`) signal registration record allocated in `RecordSignalRegistration` (`0x506c..0x514c`, FDE[53], 224 B).
 *        Bản ghi đăng ký tín hiệu 40 byte (`0x28`) cấp phát qua `calloc(1, 0x28)` tại `0x50e0`.
 */
struct SignalMonitorRecord {
    int32_t  sig_num;      // +0x00: Signal number (1..31) (stp w22, w21, [x23] @ 0x5100)
    int32_t  reg_type;     // +0x04: Registration API type (0..6: signal, sigaction, bsd_signal, sigaction64)
    int32_t  tid;          // +0x08: Thread ID from gettid() (str w0, [x23, #8] @ 0x5114)
    int32_t  _pad0;        // +0x0c: Alignment padding
    void*    handler_addr; // +0x10: Signal handler / sa_sigaction pointer (str x20, [x23, #0x10] @ 0x5108)
    void*    caller_ret;   // +0x18: Return address (xpaclri-stripped LR) (stp x19, x0, [x23, #0x18] @ 0x5104)
    int64_t  timestamp_ms; // +0x20: Registration timestamp in ms from get_time_millis()
};
static_assert(sizeof(SignalMonitorRecord) == kSignalRecordStructSize, "SignalMonitorRecord must be 0x28 (40) bytes");

int64_t ComputeTimeMillisFromTimeval(int64_t tv_sec, int64_t tv_usec) noexcept;
bool    VerifyNpthRepairBinaryParity() noexcept;

} // namespace nextai::opencut::npth_repair

extern "C" {

// 2 Exported Global Objects in .dynsym ([46], [65])
extern pthread_key_t tlk;                   // .bss  0x00e4c0 (4 B)
extern int32_t       npth_repair_log_prior; // .data 0x00e2d0 (4 B, initialized to 5)

// 30 Exported Functions in .dynsym ([47]..[64], [66]..[77])
int     hook_init(void);
int     hook_single(const char* lib_name, const char* sym_name, void* new_func, void** stub_out, void* orig_out);
int     unhook_single(void** stub_ptr);
int     hook_table(const nextai::opencut::npth_repair::RepairHookItem* table, int count, void** stubs_out);
void    unhook_table(void** stubs, int count);
int     search_and_replace_inst(void);
int     repair_log_get_debuggable(void);
void    repair_log_set_debuggable(int debuggable);
void    set_api_level(int api_level);
int     get_api_level(void);
int     check_api_level(int min_api, int max_api);
int     register_jni_method(JNIEnv* env, const char* class_name, const JNINativeMethod* methods, int num_methods);
int     check_state(volatile int32_t* state_ptr, int32_t expected, int32_t desired);
int64_t get_time_millis(void);
int     npth_repair_init(int api_level, int debuggable);
int     check_init(void);
jint    JNI_OnLoad(JavaVM* vm, void* reserved);
int     fix_art_dump_native_stack(void);
void    unfix_art_dump_native_stack(void);
int     register_nr_art_jni_method(JNIEnv* env);
int     suspend_time_4_4_opt(void);
int     register_nr_dvm_jni_method(JNIEnv* env);
int     opt_mtk_buffer(void);
int     register_nr_mtk_jni_method(JNIEnv* env);
int     fix_scudo_vma_leak(void);
int     register_nr_scudo_jni_method(JNIEnv* env);
int     start_sig_register_monitor(const int32_t* sig_list, int count);
void    stop_sig_register_monitor(void);
int     dump_signal_monitor(const char* file_path, int keep_records);
int     register_nr_sigMonitor_jni_method(JNIEnv* env);

} // extern "C"
