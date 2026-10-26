// ============================================================================
// File: godzilla_ref_debug.h
// Target: libgodzilla-acurate-asan.so (160,168 bytes)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Declarations for GodzillaRefDebug JNI GlobalRef allocation
//                   & deallocation ring-buffer recorder, ShadowHook ART JNI
//                   interceptors, and JNI testcases (`0x01f810..0x021098`).
// Mô tả (VN): Khai báo cho hệ thống ghi nhận vòng đời tham chiếu toàn cục JNI
//             (GodzillaRefDebug), các trình chặn ART JNI qua ShadowHook, và
//             các kịch bản kiểm thử JNI (`0x01f810..0x021098`).
// ============================================================================

#pragma once

#include "godzilla_acurate_asan_types.h"

namespace godzilla_asan {

// ============================================================================
// [EN] Global variables in .data (@ 0x02e8f0..0x02e8fc) and .bss (@ 0x05e9f8..0x05ea58)
// [VN] Các biến toàn cục trong .data (@ 0x02e8f0..0x02e8fc) và .bss (@ 0x05e9f8..0x05ea58)
// ============================================================================
extern uint32_t g_ref_alloc_seq;           // .data @ 0x02e8f0 (initial = 1)
extern uint32_t g_ref_free_seq;            // .data @ 0x02e8f4 (initial = 1)
extern uint32_t g_ref_bundle_size;         // .data @ 0x02e8f8 (initial = 512 = 0x200)
extern uint32_t g_ref_local_size;          // .data @ 0x02e8fc (initial = 8 = 0x08)

extern RefHookContext g_ref_hook_ctx;      // .bss @ 0x05e9f8 (80 B)
extern bool g_refdebug_debuglog;           // .bss @ 0x05ea48 (referenced via .data.rel.ro @ 0x02a3b0)
extern int32_t g_ref_hook_add_global_ref;  // .bss @ 0x05ea50
extern RefDebugState* g_ref_debug_state;   // .bss @ 0x05ea58

// [EN] Initialize RefDebugState and install ShadowHook on ART NewGlobalRef/DeleteGlobalRef (@ 0x020190 & @ 0x01f810)
// [VN] Khởi tạo RefDebugState và cài đặt ShadowHook lên ART NewGlobalRef/DeleteGlobalRef (@ 0x020190 & @ 0x01f810)
void initRefDebug();

// [EN] Configure bundle_size (clamped to <= 10000), local_size (clamped to <= 128), and add_global_ref mode (@ 0x0208e0)
// [VN] Cấu hình bundle_size (<= 10000), local_size (<= 128) và chế độ add_global_ref (@ 0x0208e0)
void configureRefDebug(int32_t bundle_size, int32_t local_size, int32_t hook_add_global_ref);

// [EN] Record a NewGlobalRef (action_type=1) or AddGlobalRef (action_type=2) event (@ 0x0203d8 / @ 0x020464 / @ 0x020938)
// [VN] Ghi nhận sự kiện NewGlobalRef (action_type=1) hoặc AddGlobalRef (action_type=2) (@ 0x0203d8 / @ 0x020464 / @ 0x020938)
void recordRefAlloc(jobject ref, int16_t action_type);

// [EN] Record a DeleteGlobalRef (action_type=-1) event (@ 0x0205b8 / @ 0x020ea0)
// [VN] Ghi nhận sự kiện DeleteGlobalRef (action_type=-1) (@ 0x0205b8 / @ 0x020ea0)
void recordRefFree(jobject ref);

// [EN] Dump all records in the bucket matching `ref_value` or the latest `max_count` records (@ 0x020694 / @ 0x0206b4)
// [VN] Kết xuất toàn bộ bản ghi trong bucket khớp `ref_value` hoặc `max_count` bản ghi mới nhất (@ 0x020694 / @ 0x0206b4)
void dumpLatestRefRecords(uint32_t ref_value, int32_t max_count);

// [EN] Format and log a single RefRecordEntry with dladdr() symbol resolution (@ 0x020c74)
// [VN] Định dạng và ghi nhật ký một bản ghi RefRecordEntry kèm phân giải ký hiệu dladdr() (@ 0x020c74)
void printRecordEntry(const RefRecordEntry& entry);

} // namespace godzilla_asan
