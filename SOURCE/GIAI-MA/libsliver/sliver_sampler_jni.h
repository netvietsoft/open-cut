/**
 * @file sliver_sampler_jni.h
 * @brief Single-Thread & All-Thread Group Sampling Engines, Delta Encoder, and JNI Bridges.
 *        Bộ máy lấy mẫu đơn luồng & đa luồng theo nhóm, bộ mã hóa Delta và cầu nối JNI.
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - JNI_OnLoad: 0x0039ec..0x003ad3
 * - com/bytedance/sliver/SliverAllThreadSupport (8 native methods @ 0x0172f8..0x0173b0):
 *   - nStartSliverGroup:  0x003ad4
 *   - nNotifySliverGroup: 0x003e30
 *   - nStopSliverGroup:   0x003f70
 *   - nDumpSliverGroup:   0x003f90
 *   - nPauseSliverGroup:  0x0040b0
 *   - nResumeSliverGroup: 0x0040d0
 *   - nClearSliverGroup:  0x0040f0
 *   - nGetThreadId:       0x004110
 * - com/bytedance/sliver/Sliver (12 native methods @ 0x0171d8..0x0172f0):
 *   - nInit:                0x004134
 *   - nStart:               0x004d04
 *   - nPause:               0x004e34
 *   - nResume:              0x004e60
 *   - nStop:                0x004e94
 *   - nDump:                0x004ec8
 *   - nClear:               0x005044
 *   - nGetMethodStackTrace: 0x00509c
 *   - nGetStackTrace([J):   0x00517c
 *   - nGetStackTrace(Thread,J): 0x005264
 *   - nGetStackTrace3([J):  0x0052f4
 *   - nResetSamplingMs:     0x005538
 * - Sampling Pthreads & NanoScope Trace Writers:
 *   - Single-Thread Sampling Loop: 0x005be0..0x006344
 *   - Group Sampling Loop:         0x0067b8..0x0071a4
 *   - Single-Thread Trace Writer:  0x0076b0..0x0077fc
 *   - Group Trace Writer:          0x008374..0x0084a8
 */

#pragma once

#include "sliver_types.h"
#include "sliver_art_unwinder.h"
#include <jni.h>
#include <cstdio>
#include <string>
#include <vector>

namespace bytedance {
namespace sliver {

/**
 * @brief Java Callback Listener for SamplingMode::kMethodCallback (32 bytes = 0x20 @ 0x007228).
 *        Bộ lắng nghe gọi lại Java cho chế độ SamplingMode::kMethodCallback (32 byte = 0x20 @ 0x007228).
 *
 * Binary Layout (0x007228..0x0073e0):
 *   +0x00: JavaVM*   vm
 *   +0x08: JNIEnv*   env
 *   +0x10: jclass    sliver_class       ("com/bytedance/sliver/Sliver")
 *   +0x18: jmethodID on_sample_method   ("onSample", "(Ljava/lang/Thread;[JJ)V")
 */
struct SliverMethodListener {
    JavaVM*   vm{nullptr};               // +0x00
    JNIEnv*   env{nullptr};              // +0x08
    jclass    sliver_class{nullptr};     // +0x10
    jmethodID on_sample_method{nullptr}; // +0x18

    void InvokeOnSample(jobject thread_obj, const uint64_t* methods, int32_t frame_count, int64_t cost_us);
};

/**
 * @brief Single-Thread Sampling Task (72 bytes = 0x48 allocated at 0x004d60).
 *        Tác vụ lấy mẫu đơn luồng (72 byte = 0x48 cấp phát tại 0x004d60).
 */
struct SliverTask {
    int32_t               sampling_ms{10};             // +0x00
    int32_t               max_stack_depth{100};        // +0x04
    int32_t               mode{0};                     // +0x08
    int32_t               pad_0c{0};                   // +0x0c
    jobject               thread_global_ref{nullptr};  // +0x10
    uint64_t              thread_peer{0};              // +0x18
    ArtHelperBase*        art_helper{nullptr};         // +0x20
    SliverRingBuffer*     ring_buffer{nullptr};        // +0x28
    SliverMethodListener* method_listener{nullptr};    // +0x30
    SliverLock*           state_lock{nullptr};         // +0x38
    int32_t               status{0};                   // +0x40
    int32_t               pad_44{0};                   // +0x44
};

/**
 * @brief All-Thread Group Sampling Task (88 bytes = 0x58 allocated at 0x003b30).
 *        Tác vụ lấy mẫu đa luồng theo nhóm (88 byte = 0x58 cấp phát tại 0x003b30).
 */
struct SliverGroup {
    int32_t                   sampling_ms{10};             // +0x00
    int32_t                   step_entries{kDefaultStepEntries}; // +0x04
    int32_t                   mode{0};                     // +0x08
    int32_t                   max_threads_capacity{0};     // +0x0c
    int32_t                   group_id{0};                 // +0x10
    uint8_t                   thread_list_updated{0};      // +0x14
    uint8_t                   pad_15[3]{};                 // +0x15..+0x17
    int32_t                   active_thread_count{0};      // +0x18
    uint8_t                   thread_capacity_grown{0};    // +0x1c
    uint8_t                   pad_1d[3]{};                 // +0x1d..+0x1f
    jobject*                  thread_refs{nullptr};        // +0x20
    uint64_t*                 thread_peers{nullptr};       // +0x28
    ArtHelperBase*            art_helper{nullptr};         // +0x30
    SliverGroupBufferManager* group_buffer_mgr{nullptr};   // +0x38
    SliverMethodListener*     method_listener{nullptr};    // +0x40
    SliverLock*               state_lock{nullptr};         // +0x48
    int32_t                   status{0};                   // +0x50
    int32_t                   pad_54{0};                   // +0x54
};

// ============================================================================
// Core Profiler & RingBuffer Operations / Các hàm xử lý Bộ đệm & Lấy mẫu
// ============================================================================

/**
 * @brief Returns the global SliverContext singleton (.bss 0x0180f0).
 *        Trả về đối tượng đơn bản SliverContext toàn cục (.bss 0x0180f0).
 */
SliverContext* GetGlobalSliverContext() noexcept;

/**
 * @brief Allocates and initializes a Single-Thread SliverRingBuffer (0x0057c8..0x005858).
 *        Cấp phát và khởi tạo SliverRingBuffer đơn luồng (0x0057c8..0x005858).
 */
SliverRingBuffer* CreateSingleThreadRingBuffer(int32_t step_entries, uint8_t overwrite_flag);

/**
 * @brief Appends a captured stack sample into a single-thread ring buffer using delta/diff encoding (0x005ee4..0x006210).
 *        Ghi thêm một mẫu ngăn xếp vào bộ đệm vòng đơn luồng bằng mã hóa vi sai delta (0x005ee4..0x006210).
 */
void RecordSampleToRingBuffer(SliverRingBuffer* rb,
                              int32_t max_stack_depth,
                              const CapturedStackSample& sample,
                              uint64_t sample_timestamp_ns);

/**
 * @brief Writes NanoScope trace entries from a single-thread buffer to a FILE* stream (0x0076b0..0x0077fc).
 *        Ghi các mục dấu vết NanoScope từ bộ đệm đơn luồng ra luồng FILE* (0x0076b0..0x0077fc).
 */
void WriteSingleThreadNanoScopeTrace(const uint64_t* start,
                                     const uint64_t* end,
                                     FILE* out_file,
                                     int64_t min_timestamp_ns);

/**
 * @brief Writes NanoScope trace entries from a group thread buffer to a FILE* stream (0x008374..0x0084a8).
 *        Ghi các mục dấu vết NanoScope từ bộ đệm luồng nhóm ra luồng FILE* (0x008374..0x0084a8).
 */
void WriteGroupThreadNanoScopeTrace(const uint64_t* start,
                                    const uint64_t* end,
                                    FILE* out_file,
                                    int32_t thread_id);

/**
 * @brief Formats an array of ArtMethod pointers (with leading count at methods[0]) into a multi-line string (0x00640c..0x006564).
 *        Định dạng mảng con trỏ ArtMethod (với số lượng phần tử ở methods[0]) thành chuỗi nhiều dòng (0x00640c..0x006564).
 */
std::string FormatMethodStackTraceString(const uint64_t* count_prefixed_methods);

// ============================================================================
// JNI Native Methods / Các phương thức JNI Gốc (.data.rel.ro 0x0171d8..0x0173b0)
// ============================================================================

jboolean JniSliverInit(JNIEnv* env, jclass clazz, jint sdk_int, jobject mark_method, jboolean hook_dlopen, jboolean enable_sigsegv);
jlong    JniSliverStart(JNIEnv* env, jclass clazz, jobject thread, jlong thread_peer, jint sampling_ms, jint step_entries, jint mode);
void     JniSliverPause(JNIEnv* env, jclass clazz, jlong task_handle);
void     JniSliverResume(JNIEnv* env, jclass clazz, jlong task_handle);
void     JniSliverStop(JNIEnv* env, jclass clazz, jlong task_handle);
void     JniSliverDump(JNIEnv* env, jclass clazz, jlong task_handle, jstring path, jlong min_timestamp_ms);
void     JniSliverClear(JNIEnv* env, jclass clazz, jlong task_handle);
jlongArray JniSliverGetMethodStackTrace(JNIEnv* env, jclass clazz, jobject thread, jlong thread_peer);
jstring  JniSliverGetStackTraceFromMethods(JNIEnv* env, jclass clazz, jlongArray methods);
jstring  JniSliverGetStackTraceFromThread(JNIEnv* env, jclass clazz, jobject thread, jlong thread_peer);
jobjectArray JniSliverGetStackTraceArray(JNIEnv* env, jclass clazz, jlongArray methods);
void     JniSliverResetSamplingMs(JNIEnv* env, jclass clazz, jlong task_handle, jint sampling_ms);

jlong    JniStartSliverGroup(JNIEnv* env, jclass clazz, jint group_id, jint sampling_ms, jint step_entries, jint mode);
void     JniNotifySliverGroup(JNIEnv* env, jclass clazz, jlong group_handle, jobjectArray threads, jlongArray peers);
void     JniStopSliverGroup(JNIEnv* env, jclass clazz, jlong group_handle);
void     JniDumpSliverGroup(JNIEnv* env, jclass clazz, jlong group_handle, jstring path);
void     JniPauseSliverGroup(JNIEnv* env, jclass clazz, jlong group_handle);
void     JniResumeSliverGroup(JNIEnv* env, jclass clazz, jlong group_handle);
void     JniClearSliverGroup(JNIEnv* env, jclass clazz, jlong group_handle);
jint     JniGetThreadId(JNIEnv* env, jclass clazz, jlong thread_peer);

} // namespace sliver
} // namespace bytedance
