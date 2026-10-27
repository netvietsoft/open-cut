// ============================================================================
// File: jato_types.h
// Target: libjato.so (362,800 bytes, SHA-256: 0333b9ad7314644975997ba1a375bec370225ee72f7adf1123c83637e09fa3fc)
// Task ID: TASK-138-RECONSTRUCTION-LIBJATO / TASK_SO_109_libjato
// Description:
//   [EN] Clean-room C++17 type definitions, ART runtime proxy structures,
//        ByteHook/ShadowHook/NpthDl FFI declarations, and all 126 exported
//        JNI signatures for ByteDance Jato (Java Android Tuning Optimizer).
//   [VN] Định nghĩa kiểu dữ liệu C++17 sạch, cấu trúc proxy ART runtime,
//        khai báo FFI ByteHook/ShadowHook/NpthDl và toàn bộ 126 chữ ký JNI
//        xuất khẩu của thư viện tối ưu hóa hiệu năng ByteDance Jato.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <atomic>
#include <mutex>
#include <string>
#include <vector>
#include <unordered_map>

// [EN] Minimal JNI types for standalone compilation / [VN] Kiểu JNI tối thiểu để biên dịch độc lập
#ifndef JNI_VERSION_1_6
typedef uint8_t jboolean;
typedef int8_t jbyte;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
typedef jint jsize;
struct _jobject;
typedef _jobject* jobject;
typedef jobject jclass;
typedef jobject jstring;
typedef jobject jarray;
typedef jobject jobjectArray;
typedef jobject jintArray;
typedef jobject jlongArray;
struct _jmethodID;
typedef _jmethodID* jmethodID;
struct _jfieldID;
typedef _jfieldID* jfieldID;

struct JNINativeInterface_Table {
    void* reserved[216];
};

struct _JNIEnv {
    const JNINativeInterface_Table* functions;
};
typedef _JNIEnv JNIEnv;

struct _JavaVM {
    const void* functions;
};
typedef _JavaVM JavaVM;
#define JNI_VERSION_1_6 0x00010006
#define JNI_TRUE 1
#define JNI_FALSE 0
#endif

namespace bytedance {
namespace jato {

// ============================================================================
// [EN] Global Page Size & Architecture State (.init_array[6] @ 0x00b9fc, .data @ 0x05c000)
// [VN] Trạng thái kích thước trang bộ nhớ và kiến trúc toàn cục (.init_array[6] @ 0x00b9fc)
// ============================================================================
struct JatoGlobalState {
    int32_t page_size;                      // .got 0x05b4c0 -> .bss (sysconf(39))
    int32_t page_mask;                      // .got 0x05b6b8 -> .bss (-sysconf(39))
    int32_t arch_bits;                      // .data 0x05c048 = 64 (0x40)
    int32_t art_apex_version;               // .data 0x05c010 = -1 (lazy initialized @ 0x0177b8)
    int32_t render_thread_tid;              // .bss 0x05c0e0
    uint8_t prio_protect_enabled;           // .bss 0x05c0e4
    uint8_t los_use_new_free;               // .bss 0x05c258
    uint8_t los_need_gc_block;              // .bss 0x05c25c
    uint64_t* los_threshold_ptr;            // .bss 0x05c260
    void* los_space_instance;               // .bss 0x05c270
    uint64_t (*los_get_bytes_allocated)(void*); // .bss 0x05c278
    uint64_t* los_allocated_bytes_fallback; // .bss 0x05c280
    void* force_process_profiles_fn;        // .bss 0x05c130
    uint64_t* max_spins_before_inflation;   // .bss 0x05c668
    uint8_t scheduler_inited;               // .bss 0x05bcf8
    uint8_t buffer_barrier_hook_logs;       // .bss 0x05d598
    uint8_t buffer_barrier_active;          // .bss 0x05d599
    uint8_t jit_mprotect_phase1_ok;         // .bss 0x05d769
    uint64_t jit_code_cache_start;          // .bss 0x05d770 (40-bit masked @ 0x03086c)
    uint64_t jit_code_cache_end;            // .bss 0x05d778 (40-bit masked @ 0x030874)
};

extern JatoGlobalState g_jato_state;

// ============================================================================
// [EN] Thread Statistics Structure returned by /proc/<pid>/task/<tid>/stat parser (0x018c88)
// [VN] Cấu trúc thống kê luồng trả về bởi bộ phân tích /proc/<pid>/task/<tid>/stat (0x018c88)
// ============================================================================
struct ThreadProcStat {
    int32_t tid;
    char state;
    int32_t ppid;
    uint64_t utime_ticks;
    uint64_t stime_ticks;
    int64_t priority;
    int64_t nice;
    int32_t processor;
};

// ============================================================================
// [EN] PriorityManagerV2 & CpusetManager Saved Thread Entry (.bss 0x05d2b0, 0x05d4d0)
// [VN] Bản ghi lưu độ ưu tiên và mặt nạ CPU của luồng (.bss 0x05d2b0, 0x05d4d0)
// ============================================================================
struct SavedThreadPriority {
    int32_t tid;
    int32_t original_nice;
    int32_t target_nice;
};

struct SavedThreadCpuSet {
    int32_t tid;
    uint8_t cpu_mask[128]; // 0x80 bytes sched_getaffinity/sched_setaffinity mask
};

} // namespace jato
} // namespace bytedance

// ============================================================================
// [EN] All 126 Exported Symbols from .dynsym of libjato.so (0x00c658..0x038a30)
// [VN] Toàn bộ 126 biểu tượng xuất khẩu từ bảng .dynsym của libjato.so (0x00c658..0x038a30)
// ============================================================================
extern "C" {

jboolean Java_com_bytedance_common_jato_jit_JitCompiler_nativeCompile(JNIEnv* env, jclass clazz, jint api_level, jobject method, jstring method_desc);
jboolean Java_com_bytedance_common_jato_jit_JitCompiler_nativeHookProfileSaverBug(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitCompiler_nativeForceSaveProfile(JNIEnv* env, jclass clazz);

void Java_com_bytedance_common_jato_logcut_LogCut_initLogCutInternal(JNIEnv* env, jclass clazz, jint type, jint min_priority);
void Java_com_bytedance_common_jato_logcut_LogCut_logCutStartInternal(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_logcut_LogCut_logCutStopInternal(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_memory_MinFreeHeapOpt_nativeSetMinFreeHeapPecent(JNIEnv* env, jclass clazz, jdouble percent);
jboolean Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_nativeExcludeLOS(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_nativeSetLargeObjectThreshold(JNIEnv* env, jclass clazz, jint threshold_pages);
void Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_nativeUseNewFree(JNIEnv* env, jclass clazz);
jlong Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_getLargeObjectAllocatedBytes(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_needGcBlock(JNIEnv* env, jclass clazz, jboolean need);

jint Java_com_bytedance_common_jato_threads_ThreadNative_nativeGetThreadTid(JNIEnv* env, jclass clazz, jobject thread_peer);
jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeSuspendThread(JNIEnv* env, jclass clazz, jint tid);
jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeResumeThread(JNIEnv* env, jclass clazz, jint tid);
jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeSuspendThreadByName(JNIEnv* env, jclass clazz, jstring thread_name);
jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeResumeThreadByName(JNIEnv* env, jclass clazz, jstring thread_name);
jobjectArray Java_com_bytedance_common_jato_threads_ThreadNative_nativeGetAllThreadInfo(JNIEnv* env, jclass clazz, jboolean need_lock);
jlongArray Java_com_bytedance_common_jato_threads_ThreadNative_nativeGetThreadStats(JNIEnv* env, jclass clazz, jint tid);

void Java_com_bytedance_common_jato_interpreter_InterpreterBridge_initInterpreterBridgeInternal(JNIEnv* env, jclass clazz, jint mode);
jboolean Java_com_bytedance_common_jato_debug_DebugOptimizer_openInstrumentationCrashFix(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_debug_DebugOptimizer_closeInstrumentationCrashFix(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_util_DeviceInfoUtils_nGetArtApexVersion(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_lock_LockMaxSpinsOpt_nativeSetMaxSpins(JNIEnv* env, jclass clazz, jint max_spins);
jboolean Java_com_bytedance_common_jato_boost_PosionDeadObjectOpt_nBypassPoisonDeadObjects(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_boost_MalloptOptimizer_nMalloptOptimize(JNIEnv* env, jclass clazz, jint flags);
jboolean Java_com_bytedance_common_jato_boost_RemoveWaitingForGCOpt_nEnable(JNIEnv* env, jclass clazz, jboolean enable);
jboolean Java_com_bytedance_common_jato_classlinker_AnnotationResolvingOpt_nativeOptimize(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_boost_RSpaceLiveRatioOpt_nRegionSpaceLiveRatioOpt(JNIEnv* env, jclass clazz, jint live_percent, jint api_level);

jboolean Java_com_bytedance_common_jato_gfx_GLESInitBoost_nativeBoost(JNIEnv* env, jclass clazz, jboolean enable);
jboolean Java_com_bytedance_common_jato_gfx_GraphicsUtil_nativeEnableResourceCleanup(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_gfx_HwuiBoost_nativeBoost(JNIEnv* env, jclass clazz, jboolean boost_compile, jboolean boost_shader);
jboolean Java_com_bytedance_common_jato_boost_HandleGetEnvOpt_nativeInit(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_gfx_RenderThreadOpt_nativeChangeRenderPipelineType(JNIEnv* env, jclass clazz, jboolean use_skiagl);
jboolean Java_com_bytedance_common_jato_gfx_RenderThreadOpt_nativeResourceCacheOpt(JNIEnv* env, jclass clazz, jint max_bytes);
jboolean Java_com_bytedance_common_jato_gfx_RenderThreadOpt_nativePinImagesOpt(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_scheduler_SchedulerNativeHolder_nativeInit(JNIEnv* env, jclass clazz, jint min_sdk, jint flags);
jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_nativeSetPriority(JNIEnv* env, jclass clazz, jint tid, jint prio);
jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_nativeResetPriority(JNIEnv* env, jclass clazz, jint tid);
jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_nativeInit(JNIEnv* env, jclass clazz, jboolean hook_setpriority);
void Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_fetchRenderThreadTid(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_getRenderThreadTid(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_boost_sched_ThreadPrioProtector_nativeInit(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_boost_sched_ThreadPrioProtector_addThreadPrioProtect(JNIEnv* env, jclass clazz, jint tid, jint min_prio, jint max_prio);
void Java_com_bytedance_common_jato_boost_sched_ThreadPrioProtector_setPrioProtectEnabled(JNIEnv* env, jclass clazz, jboolean enabled);

jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkWebviewNative(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_shrinker_MemTrim_trimVdex(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_boost_CpusetManager_setCpuSetTid(JNIEnv* env, jclass clazz, jint tid, jintArray cpus);
void Java_com_bytedance_common_jato_boost_CpusetManager_resetCpuSetTid(JNIEnv* env, jclass clazz, jint tid);

jboolean Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeInit(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeBegin(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeEnd(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeHookLogs(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_boost_TextureOpt_nativeUnblockJNISurfaceTexture(JNIEnv* env, jclass clazz);

void Java_com_bytedance_common_jato_jit_JitCodeCacheMProtectOpt_nStartPharse1(JNIEnv* env, jclass clazz, jlong start_addr, jlong end_addr);
void Java_com_bytedance_common_jato_jit_JitCodeCacheMProtectOpt_nStartPharse2(JNIEnv* env, jclass clazz);

jint JNI_OnLoad(JavaVM* vm, void* reserved);

jboolean Java_com_bytedance_common_jato_memory_gcblocker_DvmGcBlocker_nativeInit(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_memory_gcblocker_DvmGcBlocker_nativeDalvikStartBlockGc(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_memory_gcblocker_DvmGcBlocker_nativeDalvikStopBlockGc(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeCreateToken(JNIEnv* env, jclass clazz, jboolean critical);
void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeReleaseToken(JNIEnv* env, jclass clazz, jint token);
jboolean Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeRequestBlockGc(JNIEnv* env, jclass clazz, jlong duration_ms);
void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeSetMaxGcBlockTime(JNIEnv* env, jclass clazz, jint max_time_ms);
jint Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeSetHeapLimit(JNIEnv* env, jclass clazz, jboolean enable, jint limit_mb);
void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeSetIsSupportApex(JNIEnv* env, jclass clazz, jboolean support);
jint Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeStartBlockGc(JNIEnv* env, jclass clazz, jint token);
void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeStopBlockGc(JNIEnv* env, jclass clazz, jint token);

jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkMallocNative(JNIEnv* env, jclass clazz, jint kb, jint max_mb);
jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkHeapNative(JNIEnv* env, jclass clazz, jint kb);
jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkRegionNative(JNIEnv* env, jclass clazz, jint kb);

jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyNoneNative(JNIEnv* env, jclass clazz, jint sdk_int, jint arch);
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyEnableNative(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyNoneAbove15Native(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyEnableAbove15Native(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_dvmVerifyNoneNative(JNIEnv* env, jclass clazz);
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_dvmVerifyEnableNative(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_gfx_GLBoost_nativePromote(JNIEnv* env, jclass clazz, jintArray mask);
jboolean Java_com_bytedance_common_jato_jit_JitSuspend_nativeInit(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitSuspend_nativeBegin(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitSuspend_nativeEnd(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitSuspend_nativeEnableJitDump(JNIEnv* env, jclass clazz, jint mode);
jstring Java_com_bytedance_common_jato_jit_JitSuspend_getJitDumpNativeMethod(JNIEnv* env, jclass clazz);

jint Java_com_bytedance_common_jato_boost_ProcTidFetcher_nativeGetRenderThreadTid(JNIEnv* env, jclass clazz, jint pid);
jboolean Java_com_bytedance_common_jato_fastnative_FastNative_getMethodsNative(JNIEnv* env, jclass clazz, jobjectArray class_names, jobjectArray method_names, jobjectArray signatures, jobjectArray out_methods);
jboolean Java_com_bytedance_common_jato_fastnative_FastNative_nativeModifyFastNativeInner(JNIEnv* env, jclass clazz, jobjectArray methods, jboolean is_fast_native, jboolean is_critical_native);

jboolean Java_com_bytedance_common_jato_jit_ProfileInfo_init(JNIEnv* env, jclass clazz);
jobject Java_com_bytedance_common_jato_jit_ProfileInfo_getMethod(JNIEnv* env, jclass clazz, jstring class_name, jstring method_name, jstring signature);
jboolean Java_com_bytedance_common_jato_jit_ProfileInfo_createProfileForMethod(JNIEnv* env, jclass clazz, jobject method, jintArray classes, jobject dex_location);
void Java_com_bytedance_common_jato_jit_ProfileInfo_forceSaveProfile(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_ProfileInfo_jitMethod(JNIEnv* env, jclass clazz, jobject method);

void Java_com_bytedance_common_jato_jit_JitCodeCacheGc_enable(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitCodeCacheGc_disable(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_jit_JitCodeCacheGc_isEnable(JNIEnv* env, jclass clazz);

void Java_com_bytedance_common_jato_jit_JitOptions_setCompileThreshold(JNIEnv* env, jclass clazz, jint compile_threshold, jint warmup_threshold, jint osr_threshold, jint priority_thread_weight, jint invoke_transition_weight);
void Java_com_bytedance_common_jato_jit_JitOptions_setCompilerOptions(JNIEnv* env, jclass clazz, jobjectArray options);
void Java_com_bytedance_common_jato_jit_JitOptions_compilerOptionsSupport14(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_boost_HiddenApiOpt_nOptimize(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_threads_ThreadSuspendTimeout_setSuspendTimeoutInSeconds(JNIEnv* env, jclass clazz, jlong timeout_seconds);
jboolean Java_com_bytedance_common_jato_boost_PrePageFaultOpt_prePageFaultInner(JNIEnv* env, jclass clazz, jint madvise_mode, jint mincore_threshold);
jboolean Java_com_bytedance_common_jato_boost_PrePageFaultOpt_reclaimCodeItem(JNIEnv* env, jclass clazz, jint reclaim_mode);
jboolean Java_com_bytedance_common_jato_boost_PrePageFaultOpt_mlockCodeItem(JNIEnv* env, jclass clazz, jint mlock_mode);
void Java_com_bytedance_common_jato_boost_PrePageFaultOpt_munlockInBackground(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_boost_DexCacheExpandOpt_expandInner(JNIEnv* env, jclass clazz, jobject class_loader, jint method_field_size, jint class_size, jint string_size, jint method_type_size);
void Java_com_bytedance_common_jato_boost_DexCacheExpandOpt_checkHitExpand(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_memory_MadviseFreeOpt_replaceDontNeedToFree(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_memory_NonMovingSpaceOpt_optimizeNonMovingSpace(JNIEnv* env, jclass clazz, jint max_free, jint min_free);
void Java_com_bytedance_common_jato_memory_NonMovingSpaceOpt_printHeapStatus(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_memory_YoungGcOpt_doYoungGcOpt(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_memory_WeakRefUnblockOpt_init(JNIEnv* env, jclass clazz);
jboolean Java_com_bytedance_common_jato_boost_ThrowableUnwindOpt_optimizeFileExistUnwind(JNIEnv* env, jclass clazz);

void Java_com_bytedance_common_jato_jit_JitCodeCacheExpand_keepAlive(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitCodeCacheExpand_enableSmallPattern(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_jit_JitCodeCacheExpand_testSmallPattern(JNIEnv* env, jclass clazz);

jboolean Java_com_bytedance_common_jato_boost_DecodeJObjectOpt_nOptimizeDecodeJObject(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_soload_StaticJNIOpt_nativeInitStaticJNIOpt(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_soload_StaticJNIOpt_nativeLoadMethodProfile(JNIEnv* env, jclass clazz, jstring profile_path);

void Java_com_bytedance_common_jato_scheduler_ClassVisiblyInitializedOpt_enable(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_scheduler_ClassVisiblyInitializedOpt_setMax(JNIEnv* env, jclass clazz, jint max_count);
void Java_com_bytedance_common_jato_scheduler_ClassVisiblyInitializedOpt_setUseMembarrier(JNIEnv* env, jclass clazz, jboolean use_membarrier);

void Java_com_bytedance_common_jato_gfx_RenderThreadUnblockOpt_nativeUnblockRenderThreadTask(JNIEnv* env, jclass clazz, jint tid);
jobject Java_com_bytedance_common_jato_util_ViewMethodInvokeHelper_invokeViewConstruct(JNIEnv* env, jclass clazz, jclass view_class, jobject view_obj, jobject context, jobject attrs);
jobject Java_com_bytedance_common_jato_util_ViewMethodInvokeHelper_getViewConstructMethod(JNIEnv* env, jclass clazz, jclass view_class);
void Java_com_bytedance_common_jato_util_JNIHook_nativePlaceHolder(JNIEnv* env, jclass clazz);
void Java_com_bytedance_common_jato_util_JNIHook_nativeInit(JNIEnv* env, jclass clazz, jobject placeholder_method);
void Java_com_bytedance_common_jato_gfx_BlastBufferQueueOpt_nativeHookPreload(JNIEnv* env, jclass clazz);

} // extern "C"
