// ============================================================================
// File: godzilla_ref_debug.cpp
// Target: libgodzilla-acurate-asan.so (160,168 bytes)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Complete implementation of GodzillaRefDebug JNI GlobalRef
//                   ring-buffer recorder, ShadowHook ART JNI interceptors,
//                   bucket index hashing `(ref >> 2) % g_ref_bundle_size`,
//                   and sorting/dumping logic (`0x01f810..0x021098`).
// Mô tả (VN): Triển khai đầy đủ bộ ghi vòng đời tham chiếu toàn cục JNI
//             (GodzillaRefDebug), các trình chặn ART JNI qua ShadowHook,
//             hàm băm chỉ số bucket `(ref >> 2) % g_ref_bundle_size`,
//             và thuật toán sắp xếp/kết xuất (`0x01f810..0x021098`).
// ============================================================================

#include "godzilla_ref_debug.h"
#include "acurate_asan_signal_hook.h"

#include <algorithm>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dlfcn.h>

#ifdef __ANDROID__
#include <android/log.h>
#define REF_LOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO, "Godzilla-RefDebug", fmt, ##__VA_ARGS__)
#define REF_LOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, "Godzilla-RefDebug", fmt, ##__VA_ARGS__)
#define REF_LOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, "Godzilla-RefDebug", fmt, ##__VA_ARGS__)
#else
#define REF_LOGI(fmt, ...) std::fprintf(stdout, "[I/Godzilla-RefDebug] " fmt "\n", ##__VA_ARGS__)
#define REF_LOGD(fmt, ...) std::fprintf(stdout, "[D/Godzilla-RefDebug] " fmt "\n", ##__VA_ARGS__)
#define REF_LOGE(fmt, ...) std::fprintf(stderr, "[E/Godzilla-RefDebug] " fmt "\n", ##__VA_ARGS__)
#endif

extern "C" {
void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name,
                               void* new_addr, void** orig_addr) __attribute__((weak));
int shadowhook_get_errno() __attribute__((weak));
const char* shadowhook_to_errmsg(int err) __attribute__((weak));
}

namespace godzilla_asan {

// ============================================================================
// [EN] Global variables in .data (@ 0x02e8f0..0x02e8fc) and .bss (@ 0x05e9f8..0x05ea58)
// [VN] Các biến toàn cục trong .data (@ 0x02e8f0..0x02e8fc) và .bss (@ 0x05e9f8..0x05ea58)
// ============================================================================
uint32_t g_ref_alloc_seq = 1;                // .data @ 0x02e8f0
uint32_t g_ref_free_seq = 1;                 // .data @ 0x02e8f4
uint32_t g_ref_bundle_size = 512;            // .data @ 0x02e8f8 (0x200)
uint32_t g_ref_local_size = 8;               // .data @ 0x02e8fc (0x08)

RefHookContext g_ref_hook_ctx = {};          // .bss @ 0x05e9f8 (80 B)
bool g_refdebug_debuglog = false;            // .bss @ 0x05ea48
int32_t g_ref_hook_add_global_ref = 0;       // .bss @ 0x05ea50
RefDebugState* g_ref_debug_state = nullptr;  // .bss @ 0x05ea58

namespace {

// ============================================================================
// [EN] Hook callbacks installed by initRefHooks (@ 0x01f810):
//      1. proxyJniFalseNewGlobalRef (@ 0x01fcd4):
//         Calls orig `_ZN3art3JNIILb0EE12NewGlobalRefEP7_JNIEnvP8_jobject`,
//         logs if `g_refdebug_debuglog`, calls `recordRefAlloc(res, 1)`.
//      2. proxyJniTrueNewGlobalRef (@ 0x01fd50):
//         Calls orig `_ZN3art3JNIILb1EE12NewGlobalRefEP7_JNIEnvP8_jobject`,
//         logs if `g_refdebug_debuglog`, calls `recordRefAlloc(res, 1)`.
//      3. proxyJavaVMExtAddGlobalRef (@ 0x01fdcc):
//         Calls orig `_ZN3art9JavaVMExt12AddGlobalRefEPNS_6ThreadENS_6ObjPtrINS_6mirror6ObjectEEE`,
//         logs if `g_refdebug_debuglog`, calls `recordRefAlloc(res, 2)`.
//      4. proxyJniFalseDeleteGlobalRef (@ 0x01fe48):
//         Logs if `g_refdebug_debuglog`, calls `recordRefFree(obj)`, then calls
//         orig `_ZN3art3JNIILb0EE15DeleteGlobalRefEP7_JNIEnvP8_jobject`.
//      5. proxyJniTrueDeleteGlobalRef (@ 0x01feb4):
//         Logs if `g_refdebug_debuglog`, calls `recordRefFree(obj)`, then calls
//         orig `_ZN3art3JNIILb1EE15DeleteGlobalRefEP7_JNIEnvP8_jobject`.
// [VN] Các hàm chặn (proxy) cho NewGlobalRef, AddGlobalRef và DeleteGlobalRef (@ 0x01fcd4..0x01feb4)
// ============================================================================
using NewGlobalRefFn = jobject (*)(JNIEnv*, jobject);
using AddGlobalRefFn = jobject (*)(void* self_vm, void* thread, void* obj_ptr);
using DeleteGlobalRefFn = void (*)(JNIEnv*, jobject);

jobject proxyJniFalseNewGlobalRef(JNIEnv* env, jobject obj) {
    auto orig = reinterpret_cast<NewGlobalRefFn>(g_ref_hook_ctx.orig_jni_false_new_global_ref);
    jobject res = (orig != nullptr) ? orig(env, obj) : nullptr;
    if (g_refdebug_debuglog) {
        REF_LOGD("NewGlobalRef %p", res);
    }
    recordRefAlloc(res, 1);
    return res;
}

jobject proxyJniTrueNewGlobalRef(JNIEnv* env, jobject obj) {
    auto orig = reinterpret_cast<NewGlobalRefFn>(g_ref_hook_ctx.orig_jni_true_new_global_ref);
    jobject res = (orig != nullptr) ? orig(env, obj) : nullptr;
    if (g_refdebug_debuglog) {
        REF_LOGD("NewGlobalRef %p", res);
    }
    recordRefAlloc(res, 1);
    return res;
}

jobject proxyJavaVMExtAddGlobalRef(void* self_vm, void* thread, void* obj_ptr) {
    auto orig = reinterpret_cast<AddGlobalRefFn>(g_ref_hook_ctx.orig_javavmext_add_global_ref);
    jobject res = (orig != nullptr) ? orig(self_vm, thread, obj_ptr) : nullptr;
    if (g_refdebug_debuglog) {
        REF_LOGD("AddGlobalRef %p", res);
    }
    recordRefAlloc(res, 2);
    return res;
}

void proxyJniFalseDeleteGlobalRef(JNIEnv* env, jobject obj) {
    if (g_refdebug_debuglog) {
        REF_LOGD("DeleteGlobalRef %p", obj);
    }
    recordRefFree(obj);
    auto orig = reinterpret_cast<DeleteGlobalRefFn>(g_ref_hook_ctx.orig_jni_false_delete_global_ref);
    if (orig != nullptr) {
        orig(env, obj);
    }
}

void proxyJniTrueDeleteGlobalRef(JNIEnv* env, jobject obj) {
    if (g_refdebug_debuglog) {
        REF_LOGD("DeleteGlobalRef %p", obj);
    }
    recordRefFree(obj);
    auto orig = reinterpret_cast<DeleteGlobalRefFn>(g_ref_hook_ctx.orig_jni_true_delete_global_ref);
    if (orig != nullptr) {
        orig(env, obj);
    }
}

} // anonymous namespace

// ============================================================================
// [EN] RefDebugState::init (@ 0x0201bc..0x02036c)
//      Exact allocation math verified from disassembly:
//      1. `records_pool = new RefRecordEntry[bundle_size * local_size]`
//         (`mul w8, w9, w8; add x0, x8, x8, lsl #1; lsl x0, x0, #4; bl _Znam`)
//      2. `mutex_array = new std::mutex[bundle_size]`
//      3. `buckets = new RefBucket[bundle_size]` (`lsl x0, x21, #4; bl _Znam`)
//      4. Initializes each `buckets[i].records = records_pool + i * local_size`,
//         `buckets[i].write_idx = 0`, `buckets[i].count = 0` (vectorized using
//         AArch64 NEON `umlal`/`st2` loop at `0x0202ac..0x020354`).
// [VN] Khởi tạo bộ nhớ cho RefDebugState (@ 0x0201bc..0x02036c)
// ============================================================================
void RefDebugState::init(uint32_t bundle_size, uint32_t local_size) {
    const size_t total_records = static_cast<size_t>(bundle_size) * static_cast<size_t>(local_size);
    records_pool = new RefRecordEntry[total_records]();
    mutex_array = new std::mutex[bundle_size]();
    buckets = new RefBucket[bundle_size]();

    for (uint32_t i = 0; i < bundle_size; ++i) {
        buckets[i].records = records_pool + (static_cast<size_t>(i) * local_size);
        buckets[i].write_idx = 0;
        buckets[i].count = 0;
    }
}

// ============================================================================
// [EN] initRefDebug (@ 0x020190 & @ 0x01f810)
//      Allocates `g_ref_debug_state` (`24` bytes at `0x05ea58`), initializes
//      pools with `(g_ref_bundle_size, g_ref_local_size)`, and hooks ART JNI
//      GlobalRef functions in `libart.so` via `shadowhook_hook_sym_name`.
// [VN] Khởi tạo GodzillaRefDebug và đặt bẫy ShadowHook trên libart.so (@ 0x020190 & @ 0x01f810)
// ============================================================================
void initRefDebug() {
    if (g_ref_debug_state == nullptr) {
        g_ref_debug_state = new RefDebugState();
        g_ref_debug_state->init(g_ref_bundle_size, g_ref_local_size);
    }

    if (shadowhook_hook_sym_name == nullptr) {
        return;
    }

    if (g_ref_hook_add_global_ref == 0) {
        g_ref_hook_ctx.stub_jni_false_new_global_ref = shadowhook_hook_sym_name(
            "libart.so",
            "_ZN3art3JNIILb0EE12NewGlobalRefEP7_JNIEnvP8_jobject",
            reinterpret_cast<void*>(&proxyJniFalseNewGlobalRef),
            &g_ref_hook_ctx.orig_jni_false_new_global_ref);

        g_ref_hook_ctx.stub_jni_true_new_global_ref = shadowhook_hook_sym_name(
            "libart.so",
            "_ZN3art3JNIILb1EE12NewGlobalRefEP7_JNIEnvP8_jobject",
            reinterpret_cast<void*>(&proxyJniTrueNewGlobalRef),
            &g_ref_hook_ctx.orig_jni_true_new_global_ref);
    } else {
        g_ref_hook_ctx.stub_javavmext_add_global_ref = shadowhook_hook_sym_name(
            "libart.so",
            "_ZN3art9JavaVMExt12AddGlobalRefEPNS_6ThreadENS_6ObjPtrINS_6mirror6ObjectEEE",
            reinterpret_cast<void*>(&proxyJavaVMExtAddGlobalRef),
            &g_ref_hook_ctx.orig_javavmext_add_global_ref);
    }

    g_ref_hook_ctx.stub_jni_false_delete_global_ref = shadowhook_hook_sym_name(
        "libart.so",
        "_ZN3art3JNIILb0EE15DeleteGlobalRefEP7_JNIEnvP8_jobject",
        reinterpret_cast<void*>(&proxyJniFalseDeleteGlobalRef),
        &g_ref_hook_ctx.orig_jni_false_delete_global_ref);

    g_ref_hook_ctx.stub_jni_true_delete_global_ref = shadowhook_hook_sym_name(
        "libart.so",
        "_ZN3art3JNIILb1EE15DeleteGlobalRefEP7_JNIEnvP8_jobject",
        reinterpret_cast<void*>(&proxyJniTrueDeleteGlobalRef),
        &g_ref_hook_ctx.orig_jni_true_delete_global_ref);
}

// ============================================================================
// [EN] configureRefDebug (@ 0x0208e0..0x020934)
//      Exact bounds checks from disassembly @ 0x0208e0:
//        sub w8, w0, #1; cmp w8, #9999 -> if (bundle_size in [1, 10000]) g_ref_bundle_size = bundle_size
//        sub w8, w1, #1; cmp w8, #127  -> if (local_size in [1, 128]) g_ref_local_size = local_size
//        str w2, [0x05ea50]            -> g_ref_hook_add_global_ref = hook_add_global_ref
// [VN] Cấu hình kích thước bộ đệm vòng của GodzillaRefDebug (@ 0x0208e0)
// ============================================================================
void configureRefDebug(int32_t bundle_size, int32_t local_size, int32_t hook_add_global_ref) {
    if (bundle_size >= 1 && bundle_size <= 10000) {
        g_ref_bundle_size = static_cast<uint32_t>(bundle_size);
    }
    if (local_size >= 1 && local_size <= 128) {
        g_ref_local_size = static_cast<uint32_t>(local_size);
    }
    g_ref_hook_add_global_ref = hook_add_global_ref;
    REF_LOGI("refrecord_config: %d, %d, %d, after configuration: %u, %u, %d",
             bundle_size, local_size, hook_add_global_ref,
             g_ref_bundle_size, g_ref_local_size, g_ref_hook_add_global_ref);
}

// ============================================================================
// [EN] recordRefAlloc (@ 0x0203d8 / @ 0x020464 / @ 0x020938)
//      Exact bucket index & ring-buffer update from disassembly @ 0x020938..0x020b4c:
//      1. Extracts 32-bit `ref_val = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ref))`
//      2. Computes `bucket_idx = (ref_val >> 2) % g_ref_bundle_size`
//         (`lsr w10, w19, #2; udiv w11, w10, w9; msub w22, w11, w9, w10` @ 0x02097c)
//      3. Locks `g_ref_debug_state->mutex_array[bucket_idx]`
//      4. Selects slot `entry = &bucket.records[bucket.write_idx]`
//      5. Advances `bucket.write_idx = (bucket.write_idx + 1) % g_ref_local_size`
//         and `bucket.count = min(bucket.count + 1, g_ref_local_size)`
//      6. Captures up to 6 frames via `getBacktraceFastFP`, skips the top 2 hook
//         frames, and stores up to 4 caller frames into `entry->frames[0..3]`
//      7. Sets `entry->ref_value = ref_val`, `entry->seq_id = g_ref_alloc_seq++`,
//         `entry->action_type = action_type` (1 or 2)
// [VN] Ghi nhận cấp phát GlobalRef vào bucket băm `(ref >> 2) % g_ref_bundle_size` (@ 0x020938)
// ============================================================================
void recordRefAlloc(jobject ref, int16_t action_type) {
    if (g_ref_debug_state == nullptr || g_ref_bundle_size == 0 || g_ref_local_size == 0) {
        return;
    }

    const uint32_t ref_val = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ref));
    const uint32_t bucket_idx = (ref_val >> 2U) % g_ref_bundle_size;

    std::lock_guard<std::mutex> lock(g_ref_debug_state->mutex_array[bucket_idx]);
    RefBucket& bucket = g_ref_debug_state->buckets[bucket_idx];
    RefRecordEntry& entry = bucket.records[bucket.write_idx];

    bucket.write_idx = (bucket.write_idx + 1U) % g_ref_local_size;
    if (bucket.count < g_ref_local_size) {
        bucket.count++;
    }

    entry.ref_value = ref_val;
    entry.seq_id = g_ref_alloc_seq++;
    entry.action_type = action_type;
    std::memset(entry.frames, 0, sizeof(entry.frames));

    uintptr_t raw_frames[7] = {};
    size_t n = getBacktraceFastFP(raw_frames, 6);
    if (n > 2) {
        size_t copy_cnt = (n - 2) <= 4 ? (n - 2) : 4;
        for (size_t i = 0; i < copy_cnt; ++i) {
            entry.frames[i] = raw_frames[i + 2];
        }
        entry.trace_depth = static_cast<int16_t>(copy_cnt);
    } else {
        entry.trace_depth = 0;
    }
}

// ============================================================================
// [EN] recordRefFree (@ 0x0205b8 / @ 0x020ea0)
//      Same bucket hash `(ref_val >> 2) % g_ref_bundle_size`, sets
//      `entry.seq_id = g_ref_free_seq++` and `entry.action_type = -1`.
// [VN] Ghi nhận giải phóng DeleteGlobalRef (`action_type = -1`) (@ 0x0205b8 / @ 0x020ea0)
// ============================================================================
void recordRefFree(jobject ref) {
    if (g_ref_debug_state == nullptr || g_ref_bundle_size == 0 || g_ref_local_size == 0) {
        return;
    }

    const uint32_t ref_val = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ref));
    const uint32_t bucket_idx = (ref_val >> 2U) % g_ref_bundle_size;

    std::lock_guard<std::mutex> lock(g_ref_debug_state->mutex_array[bucket_idx]);
    RefBucket& bucket = g_ref_debug_state->buckets[bucket_idx];
    RefRecordEntry& entry = bucket.records[bucket.write_idx];

    bucket.write_idx = (bucket.write_idx + 1U) % g_ref_local_size;
    if (bucket.count < g_ref_local_size) {
        bucket.count++;
    }

    entry.ref_value = ref_val;
    entry.seq_id = g_ref_free_seq++;
    entry.action_type = -1;
    std::memset(entry.frames, 0, sizeof(entry.frames));

    uintptr_t raw_frames[7] = {};
    size_t n = getBacktraceFastFP(raw_frames, 6);
    if (n > 2) {
        size_t copy_cnt = (n - 2) <= 4 ? (n - 2) : 4;
        for (size_t i = 0; i < copy_cnt; ++i) {
            entry.frames[i] = raw_frames[i + 2];
        }
        entry.trace_depth = static_cast<int16_t>(copy_cnt);
    } else {
        entry.trace_depth = 0;
    }
}

// ============================================================================
// [EN] printRecordEntry (@ 0x020c74..0x020e9c)
//      Formats action string ("Add" for action_type > 0, "Delete" for -1),
//      `entry.ref_value`, `entry.seq_id`, and up to 4 caller frames resolved
//      via `dladdr()` into logcat under tag `"Godzilla-RefDebug"`.
// [VN] In thông tin chi tiết một bản ghi RefRecordEntry kèm ký hiệu dladdr (@ 0x020c74)
// ============================================================================
void printRecordEntry(const RefRecordEntry& entry) {
    const char* action_str = (entry.action_type > 0) ? "Add" : "Delete";
    REF_LOGI("%s GlobalRef 0x%x (seq=%u, depth=%d):",
             action_str, entry.ref_value, entry.seq_id, static_cast<int>(entry.trace_depth));

    int16_t depth = entry.trace_depth;
    if (depth > 4) depth = 4;
    for (int16_t i = 0; i < depth; ++i) {
        uintptr_t pc = entry.frames[i];
        if (pc == 0) continue;
        Dl_info info = {};
        if (dladdr(reinterpret_cast<const void*>(pc), &info) != 0 && info.dli_fname != nullptr) {
            uintptr_t rel_pc = pc - reinterpret_cast<uintptr_t>(info.dli_fbase);
            REF_LOGI("  #%02d pc %016" PRIxPTR " %s (%s)",
                     static_cast<int>(i), rel_pc, info.dli_fname,
                     info.dli_sname != nullptr ? info.dli_sname : "unknown");
        } else {
            REF_LOGI("  #%02d pc %016" PRIxPTR " <unknown>", static_cast<int>(i), pc);
        }
    }
}

// ============================================================================
// [EN] dumpLatestRefRecords (@ 0x020694 / @ 0x0206b4..0x0208dc)
//      1. If `ref_value != 0`: dumps all records in `bucket[(ref_value >> 2) % g_ref_bundle_size]`
//      2. If `max_count > 0`: collects all valid records across all buckets,
//         sorts descending by `seq_id`, and prints the top `max_count` records.
// [VN] Kết xuất các bản ghi trong bucket của `ref_value` và `max_count` bản ghi mới nhất (@ 0x0206b4)
// ============================================================================
void dumpLatestRefRecords(uint32_t ref_value, int32_t max_count) {
    if (g_ref_debug_state == nullptr) {
        return;
    }

    if (ref_value != 0 && g_ref_bundle_size > 0) {
        uint32_t bucket_idx = (ref_value >> 2U) % g_ref_bundle_size;
        REF_LOGI("dump the records at the same slot with 0x%x :", ref_value);
        std::lock_guard<std::mutex> lock(g_ref_debug_state->mutex_array[bucket_idx]);
        const RefBucket& bucket = g_ref_debug_state->buckets[bucket_idx];
        for (uint32_t i = 0; i < bucket.count; ++i) {
            printRecordEntry(bucket.records[i]);
        }
    }

    if (max_count > 0) {
        REF_LOGI("dump the latest %d records:", max_count);
        std::vector<RefRecordEntry> all_entries;
        for (uint32_t b = 0; b < g_ref_bundle_size; ++b) {
            std::lock_guard<std::mutex> lock(g_ref_debug_state->mutex_array[b]);
            const RefBucket& bucket = g_ref_debug_state->buckets[b];
            for (uint32_t i = 0; i < bucket.count; ++i) {
                all_entries.push_back(bucket.records[i]);
            }
        }
        std::sort(all_entries.begin(), all_entries.end(),
                  [](const RefRecordEntry& a, const RefRecordEntry& b) {
                      return a.seq_id > b.seq_id;
                  });
        size_t limit = static_cast<size_t>(max_count);
        if (limit > all_entries.size()) {
            limit = all_entries.size();
        }
        for (size_t i = 0; i < limit; ++i) {
            printRecordEntry(all_entries[i]);
        }
    }
}

} // namespace godzilla_asan
