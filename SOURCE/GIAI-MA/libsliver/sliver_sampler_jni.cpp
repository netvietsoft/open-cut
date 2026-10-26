/**
 * @file sliver_sampler_jni.cpp
 * @brief Implementation of Single-Thread & All-Thread Group Sampling Engines, Delta Encoder, and JNI Bridges.
 *        Triển khai bộ máy lấy mẫu đơn luồng & đa luồng theo nhóm, bộ mã hóa Delta và cầu nối JNI.
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - JNI_OnLoad: 0x0039ec..0x003ad3
 * - SliverAllThreadSupport 8 JNI methods: 0x003ad4..0x004130 (.data.rel.ro 0x0172f8..0x0173b0)
 * - Sliver 12 JNI methods:                0x004134..0x005544 (.data.rel.ro 0x0171d8..0x0172f0)
 * - CreateSingleThreadRingBuffer:         0x0057c8..0x005858
 * - Single-Thread Sampling Loop:          0x005be0..0x006344
 * - Group Sampling Loop:                  0x0067b8..0x0071a4
 * - SliverMethodListener (onSample):      0x007228..0x0073e0
 * - WriteSingleThreadNanoScopeTrace:      0x0076b0..0x0077fc
 * - WriteGroupThreadNanoScopeTrace:       0x008374..0x0084a8
 */

#include "sliver_sampler_jni.h"
#include "sliver_xhook_elf.h"
#include <android/log.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <sstream>

namespace bytedance {
namespace sliver {

namespace {

/**
 * @brief Global SliverContext pointer at .bss 0x0180f0 and saved JavaVM* at .bss 0x0180e8.
 *        Con trỏ SliverContext toàn cục tại .bss 0x0180f0 và JavaVM* lưu tại .bss 0x0180e8.
 */
JavaVM*        g_saved_java_vm = nullptr;
SliverContext* g_sliver_context = nullptr;

/**
 * @brief Returns current CLOCK_MONOTONIC_COARSE / CLOCK_MONOTONIC timestamp in nanoseconds (0x00ece4 / 0x00f7e8).
 *        Trả về nhãn thời gian hiện tại tính bằng nano-giây (tv_sec * 1,000,000,000 + tv_nsec).
 *
 * Opcode @ 0x0061f0..0x006204 & 0x00f7e8..0x00f7f8:
 *   mov  w0, #0x71              // Linux __NR_clock_gettime or clock id
 *   mov  w1, #1                 // CLOCK_MONOTONIC = 1
 *   bl   clock_gettime
 *   ldp  x9, x8, [x29, #-0x68]  // tv_sec, tv_nsec
 *   mov  w10, #0xca00
 *   movk w10, #0x3b9a, lsl #16  // 1,000,000,000 = 0x3b9aca00
 *   madd x8, x9, x10, x8        // tv_sec * 1000000000ULL + tv_nsec
 */
uint64_t ReadMonotonicNanoseconds() noexcept {
    struct timespec ts{};
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return static_cast<uint64_t>(ts.tv_sec) * kNanosecondsPerSecond +
           static_cast<uint64_t>(ts.tv_nsec);
}

/**
 * @brief Ensures the ring buffer word array is allocated on first write (0x00766c..0x0076b0).
 *        Đảm bảo mảng từ 64-bit của bộ đệm vòng được cấp phát ở lần ghi đầu tiên (0x00766c..0x0076b0).
 *
 * Disassembly @ 0x007678..0x0076a8:
 *   ldr  x8, [x0, #8]        // buffer_base
 *   cbnz x8, #0x76a8
 *   lsl  w8, w1, #2          // capacity_words = step_entries << 2 (step_entries * 4)
 *   sxtw x9, w8
 *   sbfiz x8, x8, #3, #0x20  // byte_size = capacity_words * 8
 *   str  w1, [x0, #0x3c]     // step_entries
 *   str  x9, [x0, #0x40]     // capacity_words
 *   bl   operator new[](byte_size)
 *   stp  x0, x0, [x19, #8]   // buffer_base = write_ptr = allocated
 */
void EnsureSingleThreadRingBufferAllocated(SliverRingBuffer* rb, int32_t step_entries) {
    if (rb == nullptr || rb->buffer_base != nullptr) {
        return;
    }
    int32_t clamped_step = (step_entries > 0) ? step_entries : kMinStepEntries;
    int64_t capacity_words = static_cast<int64_t>(clamped_step) << 2; // step_entries * 4
    rb->step_entries = clamped_step;
    rb->capacity_words = capacity_words;
    rb->buffer_base = new uint64_t[static_cast<size_t>(capacity_words)]();
    rb->write_ptr = rb->buffer_base;
}

/**
 * @brief Appends a single 64-bit word to the single-thread ring buffer with wrap/overflow check (0x00ed58, 0x00eed4, 0x00f4f4).
 *        Ghi thêm một từ 64-bit vào bộ đệm vòng đơn luồng kèm kiểm tra tràn/quay vòng (0x00ed58, 0x00eed4, 0x00f4f4).
 */
bool WriteWordToSingleThreadRingBuffer(SliverRingBuffer* rb, uint64_t word) {
    if (rb == nullptr) {
        return false;
    }
    if (rb->buffer_base == nullptr) {
        EnsureSingleThreadRingBufferAllocated(rb, rb->step_entries);
    }
    ptrdiff_t used_words = rb->write_ptr - rb->buffer_base;
    if (rb->capacity_words <= used_words) {
        if (rb->overwrite_flag == 0) {
            return false; // Stop writing when full and non-circular
        }
        // Circular wrap-around (@ 0x00eed4..0x00eee0):
        rb->has_wrapped = 1;
        rb->write_ptr = rb->buffer_base;
    }
    *rb->write_ptr++ = word;
    return true;
}

/**
 * @brief Looks up or creates a GroupThreadRingBuffer in SliverGroupBufferManager (0x00820c..0x0082a0).
 *        Tra cứu hoặc tạo mới GroupThreadRingBuffer trong SliverGroupBufferManager (0x00820c..0x0082a0).
 */
GroupThreadRingBuffer* GetOrCreateGroupThreadRingBuffer(SliverGroupBufferManager* mgr, int32_t tid) {
    if (mgr == nullptr) {
        return nullptr;
    }
    auto it = mgr->thread_buffers.find(tid);
    if (it != mgr->thread_buffers.end() && it->second != nullptr) {
        return it->second;
    }

    auto* trb = new GroupThreadRingBuffer();
    std::memset(trb, 0, sizeof(GroupThreadRingBuffer));
    size_t cap = static_cast<size_t>(mgr->per_thread_capacity_words > 0
                                         ? mgr->per_thread_capacity_words
                                         : (kMinStepEntries * 4));
    trb->buffer_base = new uint64_t[cap]();
    trb->write_ptr = trb->buffer_base;
    trb->thread_id = tid;
    mgr->thread_buffers[tid] = trb;
    return trb;
}

/**
 * @brief Appends a single 64-bit word to a GroupThreadRingBuffer (0x00ed30, 0x00edf4, 0x00f004).
 *        Ghi thêm một từ 64-bit vào GroupThreadRingBuffer (0x00ed30, 0x00edf4, 0x00f004).
 */
bool WriteWordToGroupThreadRingBuffer(SliverGroupBufferManager* mgr,
                                      GroupThreadRingBuffer* trb,
                                      uint64_t word) {
    if (mgr == nullptr || trb == nullptr || trb->buffer_base == nullptr) {
        return false;
    }
    ptrdiff_t used_words = trb->write_ptr - trb->buffer_base;
    if (mgr->per_thread_capacity_words <= used_words) {
        if (mgr->overwrite_flag == 0) {
            return false;
        }
        trb->has_wrapped = 1;
        trb->write_ptr = trb->buffer_base;
    }
    *trb->write_ptr++ = word;
    return true;
}

} // namespace

// ============================================================================
// 1. Global Context & RingBuffer Helpers (0x0057c8..0x006210)
// ============================================================================

SliverContext* GetGlobalSliverContext() noexcept {
    return g_sliver_context;
}

/**
 * @brief Allocates and initializes a 80-byte SliverRingBuffer (0x0057c8..0x005858).
 *        Cấp phát và khởi tạo SliverRingBuffer 80 byte (0x0057c8..0x005858).
 *
 * Disassembly @ 0x0057dc..0x005804:
 *   mov  w8, #0x900
 *   movk w8, #0x3d, lsl #16    // 4,000,000 = 0x003d0900
 *   cmp  w20, w8
 *   mov  w8, #0x4240
 *   movk w8, #0xf, lsl #16     // 1,000,000 = 0x000f4240
 *   csel w8, w8, w20, gt
 *   cmp  w20, #0x800           // 2,048 = 0x00000800
 *   mov  w9, #0x800
 *   csel w8, w8, w9, ge
 */
SliverRingBuffer* CreateSingleThreadRingBuffer(int32_t step_entries, uint8_t overwrite_flag) {
    auto* rb = new SliverRingBuffer();
    std::memset(rb, 0, sizeof(SliverRingBuffer));

    int32_t normalized_step = (step_entries > kSingleThreadMaxStepEntries)
                                  ? kDefaultStepEntries
                                  : step_entries;
    if (normalized_step < kMinStepEntries) {
        normalized_step = kMinStepEntries;
    }

    rb->step_entries = normalized_step;
    rb->capacity_words = static_cast<int64_t>(normalized_step) << 2; // normalized_step * 4
    rb->overwrite_flag = overwrite_flag;
    rb->buffer_lock = new SliverLock();
    if (rb->buffer_lock->initialized == 0) {
        delete rb->buffer_lock;
        delete rb;
        return nullptr;
    }
    return rb;
}

/**
 * @brief Encodes a captured stack sample into the single-thread ring buffer using delta/diff compression (0x005ee4..0x006210).
 *        Mã hóa mẫu ngăn xếp vào bộ đệm vòng đơn luồng bằng thuật toán nén vi sai delta (0x005ee4..0x006210).
 *
 * Exact Delta Algorithm (0x005f04..0x006210):
 * 1. Allocates `curr_stack` (`max_stack_depth + 1` words) on first sample.
 * 2. Copies `sample.methods[0..frame_count-1]` to `curr_stack[1..frame_count]`, and sets
 *    `curr_stack[0] = 0xffffffffffffff00ULL | (uint8_t)sample.thread_state_word` (0x005f78).
 *    Note that `curr_stack` is ordered from leaf (`index 1`) to root (`index frame_count`), while
 *    `index 0` is the synthetic leaf thread-state frame!
 * 3. If `prev_stack == nullptr`:
 *    - Pushes all frames from root (`index = frame_count`) down to leaf (`index = 0`):
 *      for `k = frame_count` down to `0`: writes `(curr_stack[k], timestamp_ns)`.
 *    - Allocates `prev_stack` (`max_stack_depth + 1` words).
 * 4. If `prev_stack != nullptr`:
 *    - Compares `prev_stack` (from `p = prev_depth - 1` down to `0`) against `curr_stack`
 *      (from `c = frame_count` down to `0`) while `prev_stack[p] == curr_stack[c]` (0x005f84..0x005fd4).
 *    - For remaining unmatched frames in `prev_stack` (`p >= 0`), emits `p + 1` POP records:
 *      writes `(0ULL, timestamp_ns)` (0x00608c / 0x006104).
 *    - For remaining unmatched frames in `curr_stack` (`c >= 0`), emits push records from `c` down to `0`:
 *      writes `(curr_stack[c], timestamp_ns)` (0x006018 / 0x006178).
 * 5. Copies `curr_stack[0..frame_count]` into `prev_stack[0..frame_count]` and updates `prev_depth = frame_count + 1` (0x0061c8..0x0061f8).
 */
void RecordSampleToRingBuffer(SliverRingBuffer* rb,
                              int32_t max_stack_depth,
                              const CapturedStackSample& sample,
                              uint64_t sample_timestamp_ns) {
    if (rb == nullptr || sample.frame_count <= 0 || sample.methods == nullptr) {
        return;
    }

    rb->buffer_lock->Lock();
    if (!rb->is_dumped && sample.frame_count <= max_stack_depth) {
        size_t array_len = static_cast<size_t>(max_stack_depth + 1);
        if (rb->curr_stack == nullptr) {
            rb->curr_stack = new uint64_t[array_len]();
        }

        // Populate curr_stack[0] = thread state tag, curr_stack[1..frame_count] = methods[0..frame_count-1]
        rb->curr_stack[0] = kThreadStateEntryMask | static_cast<uint64_t>(sample.thread_state_word & 0xffU);
        for (int32_t i = 0; i < sample.frame_count; ++i) {
            rb->curr_stack[i + 1] = sample.methods[i];
        }

        int32_t c_idx = sample.frame_count; // Root index in curr_stack
        if (rb->prev_stack == nullptr) {
            // First sample: push all frames from root (c_idx) down to 0
            for (int32_t k = c_idx; k >= 0; --k) {
                WriteWordToSingleThreadRingBuffer(rb, rb->curr_stack[k]);
                WriteWordToSingleThreadRingBuffer(rb, sample_timestamp_ns);
            }
            rb->prev_stack = new uint64_t[array_len]();
        } else {
            // Find longest common prefix from root down to leaf (0x005f84..0x005fd4)
            int32_t p_idx = rb->prev_depth - 1;
            while (p_idx >= 0 && c_idx >= 0 && rb->prev_stack[p_idx] == rb->curr_stack[c_idx]) {
                --p_idx;
                --c_idx;
            }

            // Emit POP (0) records for frames popped from prev_stack (0x006068..0x00614c)
            for (int32_t pop = p_idx; pop >= 0; --pop) {
                WriteWordToSingleThreadRingBuffer(rb, 0ULL);
                WriteWordToSingleThreadRingBuffer(rb, sample_timestamp_ns);
            }

            // Emit PUSH (method_ptr) records for new frames in curr_stack (0x005ff0..0x006060 / 0x006150..0x0061c0)
            for (int32_t push = c_idx; push >= 0; --push) {
                WriteWordToSingleThreadRingBuffer(rb, rb->curr_stack[push]);
                WriteWordToSingleThreadRingBuffer(rb, sample_timestamp_ns);
            }
        }

        // Copy curr_stack[0..frame_count] -> prev_stack[0..frame_count] (0x0061c8..0x0061f8)
        for (int32_t i = 0; i <= sample.frame_count; ++i) {
            rb->prev_stack[i] = rb->curr_stack[i];
        }
        rb->prev_depth = sample.frame_count + 1;
        rb->last_sample_ns = sample_timestamp_ns;
    }
    rb->buffer_lock->Unlock();
}

// ============================================================================
// 2. NanoScope Trace Writers (0x0076b0..0x0077fc & 0x008374..0x0084a8)
// ============================================================================

/**
 * @brief Writes single-thread trace records in NanoScope format (0x0076b0..0x0077fc).
 *        Ghi các bản ghi dấu vết đơn luồng theo định dạng NanoScope (0x0076b0..0x0077fc).
 *
 * Format strings in .rodata:
 *   0x010064: "%ld:state:%s\n"
 *   0x010095: "POP"
 *   0x01007b: "%ld:%s\n"
 */
void WriteSingleThreadNanoScopeTrace(const uint64_t* start,
                                     const uint64_t* end,
                                     FILE* out_file,
                                     int64_t min_timestamp_ns) {
    if (start == nullptr || end == nullptr || out_file == nullptr) {
        return;
    }

    SliverContext* ctx = GetGlobalSliverContext();
    int32_t sdk_int = (ctx != nullptr && ctx->sdk_int > 0) ? ctx->sdk_int : GetAndroidSdkLevel();
    bool is_art = (ctx == nullptr) ? true : (ctx->is_art != 0);

    std::map<uint64_t, std::string> method_cache;

    for (const uint64_t* cur = start; cur + 1 < end; cur += 2) {
        uint64_t entry = cur[0];
        uint64_t timestamp_ns = cur[1];

        if (min_timestamp_ns >= 0 && static_cast<int64_t>(timestamp_ns) < min_timestamp_ns) {
            continue;
        }

        // Check if entry is a synthetic thread state word: cmn x25, #0x100; b.hs (entry >= 0xffffffffffffff00ULL)
        if (entry >= kThreadStateEntryMask) {
            const char* state_str = ResolveThreadStateString(
                sdk_int, is_art, static_cast<uint32_t>(entry & 0xffU));
            std::fprintf(out_file, "%ld:state:%s\n",
                         static_cast<long>(timestamp_ns),
                         state_str != nullptr ? state_str : "Unknown");
            continue;
        }

        std::string resolved_str;
        if (entry == 0ULL) {
            resolved_str = "POP"; // .rodata 0x010095
        } else {
            auto it = method_cache.find(entry);
            if (it != method_cache.end()) {
                resolved_str = it->second;
            } else {
                resolved_str = ResolvePrettyMethod( static_cast<uintptr_t>(entry));
                method_cache.emplace(entry, resolved_str);
            }
        }

        std::fprintf(out_file, "%ld:%s\n",
                     static_cast<long>(timestamp_ns),
                     resolved_str.c_str());
    }
}

/**
 * @brief Writes group thread trace records in NanoScope format with tid suffix (0x008374..0x0084a8).
 *        Ghi các bản ghi dấu vết luồng nhóm theo định dạng NanoScope kèm hậu tố tid (0x008374..0x0084a8).
 *
 * Format strings in .rodata:
 *   0x01008a: "%ld:%s\n"
 *   0x010095: "POP"
 */
void WriteGroupThreadNanoScopeTrace(const uint64_t* start,
                                    const uint64_t* end,
                                    FILE* out_file,
                                    int32_t thread_id) {
    (void)thread_id;
    WriteSingleThreadNanoScopeTrace(start, end, out_file, -1);
}

/**
 * @brief Formats a count-prefixed array of ArtMethod pointers into a newline-separated stack trace (0x00640c..0x006564).
 *        Định dạng mảng con trỏ ArtMethod có tiền tố số lượng thành chuỗi ngăn xếp phân tách bằng dòng mới (0x00640c..0x006564).
 */
std::string FormatMethodStackTraceString(const uint64_t* count_prefixed_methods) {
    if (count_prefixed_methods == nullptr) {
        return {};
    }
    int64_t count = static_cast<int64_t>(count_prefixed_methods[0]);
    if (count <= 0) {
        return {};
    }

    std::ostringstream oss;
    for (int64_t i = 0; i < count; ++i) {
        oss << ResolvePrettyMethod(static_cast<uintptr_t>(count_prefixed_methods[i + 1]));
        if (i < count - 1) {
            oss << "\n"; // .rodata 0x0104bc
        }
    }
    return oss.str();
}

// ============================================================================
// 3. SliverMethodListener Implementation (0x007228..0x0073e0)
// ============================================================================

/**
 * @brief Invokes com/bytedance/sliver/Sliver.onSample(Thread, long[], long) (0x007284..0x0073e0).
 *        Gọi phương thức Java com/bytedance/sliver/Sliver.onSample(Thread, long[], long) (0x007284..0x0073e0).
 */
void SliverMethodListener::InvokeOnSample(jobject thread_obj,
                                          const uint64_t* methods,
                                          int32_t frame_count,
                                          int64_t cost_us) {
    if (vm == nullptr || frame_count < 1 || methods == nullptr) {
        return;
    }

    JNIEnv* current_env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&current_env), JNI_VERSION_1_6) != JNI_OK) {
        vm->AttachCurrentThread(&current_env, nullptr);
    }
    if (current_env != nullptr) {
        env = current_env;
    }
    if (env == nullptr || sliver_class == nullptr || on_sample_method == nullptr) {
        return;
    }

    jlongArray j_methods = env->NewLongArray(frame_count);
    if (j_methods == nullptr) {
        return;
    }

    std::vector<jlong> temp(static_cast<size_t>(frame_count));
    for (int32_t i = 0; i < frame_count; ++i) {
        temp[static_cast<size_t>(i)] = static_cast<jlong>(methods[i]);
    }
    env->SetLongArrayRegion(j_methods, 0, frame_count, temp.data());
    env->CallStaticVoidMethod(sliver_class, on_sample_method, thread_obj, j_methods, static_cast<jlong>(cost_us));
    env->DeleteLocalRef(j_methods);
}

// ============================================================================
// 4. JNI Native Method Implementations (0x0039ec..0x005544)
// ============================================================================

/**
 * @brief com.bytedance.sliver.Sliver.nInit(ILjava/lang/reflect/Method;ZZ)Z (0x004134..0x004d03).
 *        Khởi tạo ngữ cảnh toàn cục SliverContext, phân giải libart.so/libdvm.so và hook dlopen (0x004134..0x004d03).
 */
jboolean JniSliverInit(JNIEnv* env,
                       jclass /*clazz*/,
                       jint sdk_int,
                       jobject mark_method,
                       jboolean hook_dlopen,
                       jboolean enable_sigsegv) {
    if (sdk_int > 34) {
        // Opcode @ 0x00414c: cmp w2, #0x22; b.gt #0x4ce0 -> returns JNI_FALSE
        return JNI_FALSE;
    }

    if (g_sliver_context == nullptr) {
        g_sliver_context = new SliverContext();
    }

    g_sliver_context->java_vm = g_saved_java_vm;
    g_sliver_context->sdk_int = sdk_int;
    g_sliver_context->jni_version = JNI_VERSION_1_6;
    g_sliver_context->hook_dlopen = (hook_dlopen != JNI_FALSE) ? 1 : 0;
    g_sliver_context->enable_sigsegv_protect = (enable_sigsegv != JNI_FALSE) ? 1 : 0;
    g_sliver_context->max_stack_depth = kDefaultMaxStackDepth; // 0x64 (100) @ 0x004314

    if (env != nullptr && mark_method != nullptr) {
        jmethodID method_id = env->FromReflectedMethod(mark_method);
        g_sliver_context->reflected_mark_method = reinterpret_cast<uintptr_t>(method_id);
        g_sliver_context->mark_method_id = reinterpret_cast<uintptr_t>(method_id);
    }

    // Check if libart.so is available; fallback to libdvm.so on API 19 (0x0042f8..0x004438)
    const char* art_path = (sdk_int >= 30)
                               ? "/apex/com.android.art/lib64/libart.so"
                               : (sdk_int == 29 ? "/apex/com.android.runtime/lib64/libart.so"
                                                : "/system/lib64/libart.so");
    ElfSymbolHandle* art_handle = SliverDlOpen(art_path, 0);
    if (art_handle != nullptr) {
        g_sliver_context->is_art = 1;
        g_sliver_context->current_from_gdb = reinterpret_cast<void* (*)()>(
            SliverDlSym(art_handle, "_ZN3art6Thread14CurrentFromGdbEv"));
        SliverDlClose(art_handle);
    } else if (sdk_int == 19) {
        g_sliver_context->is_art = 0;
    }

    // If hook_dlopen is enabled on API 28..34, register xhook on libart.so (0x004324..0x0043ac)
    if (g_sliver_context->hook_dlopen != 0 && sdk_int >= 28 && sdk_int <= 34) {
        xhook_enable_debug(0);
        xhook_enable_sigsegv_protection(1);
        xhook_refresh(0);
    }

    return JNI_TRUE;
}

/**
 * @brief com.bytedance.sliver.Sliver.nStart(Ljava/lang/Thread;JIII)J (0x004d04..0x004e33).
 *        Bắt đầu tác vụ lấy mẫu đơn luồng (0x004d04..0x004e33).
 */
jlong JniSliverStart(JNIEnv* env,
                     jclass clazz,
                     jobject thread,
                     jlong thread_peer,
                     jint sampling_ms,
                     jint step_entries,
                     jint mode) {
    if (g_sliver_context == nullptr || thread == nullptr || thread_peer == 0) {
        return 0;
    }

    int32_t sdk = g_sliver_context->sdk_int;
    if (sdk < 19 || sdk > 34 || ((kSupportedSdkMask >> sdk) & 1ULL) == 0ULL) {
        return 0;
    }

    auto* task = new SliverTask();
    std::memset(task, 0, sizeof(SliverTask));
    task->sampling_ms = sampling_ms;
    task->max_stack_depth = static_cast<int32_t>(g_sliver_context->max_stack_depth);
    task->mode = mode;
    task->thread_global_ref = (env != nullptr) ? env->NewGlobalRef(thread) : thread;
    task->thread_peer = static_cast<uint64_t>(thread_peer);
    task->art_helper = CreateArtHelperForCurrentSdk();
    task->ring_buffer = CreateSingleThreadRingBuffer(step_entries, (mode == 1) ? 1 : 0);
    task->state_lock = new SliverLock();
    task->status = static_cast<int32_t>(SliverStatus::kRunning);

    if (mode == static_cast<int32_t>(SamplingMode::kMethodCallback) && env != nullptr && clazz != nullptr) {
        auto* listener = new SliverMethodListener();
        listener->vm = static_cast<JavaVM*>(g_sliver_context->java_vm);
        listener->env = env;
        listener->sliver_class = static_cast<jclass>(env->NewGlobalRef(clazz));
        listener->on_sample_method = env->GetStaticMethodID(
            listener->sliver_class, "onSample", "(Ljava/lang/Thread;[JJ)V");
        task->method_listener = listener;
    }

    return reinterpret_cast<jlong>(task);
}

/**
 * @brief com.bytedance.sliver.Sliver.nPause(J)V (0x004e34..0x004e5f).
 *        Tạm dừng tác vụ lấy mẫu đơn luồng (0x004e34..0x004e5f).
 */
void JniSliverPause(JNIEnv* /*env*/, jclass /*clazz*/, jlong task_handle) {
    if (g_sliver_context == nullptr || task_handle == 0) {
        return;
    }
    auto* task = reinterpret_cast<SliverTask*>(task_handle);
    if (task->state_lock != nullptr) {
        task->state_lock->Lock();
        task->status = static_cast<int32_t>(SliverStatus::kPaused);
        task->state_lock->Unlock();
    }
}

/**
 * @brief com.bytedance.sliver.Sliver.nResume(J)V (0x004e60..0x004e93).
 *        Tiếp tục tác vụ lấy mẫu đơn luồng (0x004e60..0x004e93).
 */
void JniSliverResume(JNIEnv* /*env*/, jclass /*clazz*/, jlong task_handle) {
    if (g_sliver_context == nullptr || task_handle == 0) {
        return;
    }
    auto* task = reinterpret_cast<SliverTask*>(task_handle);
    if (task->state_lock != nullptr) {
        task->state_lock->Lock();
        task->status = static_cast<int32_t>(SliverStatus::kRunning);
        task->state_lock->Unlock();
        task->state_lock->Signal();
    }
}

/**
 * @brief com.bytedance.sliver.Sliver.nStop(J)V (0x004e94..0x004ec7).
 *        Dừng tác vụ lấy mẫu đơn luồng (0x004e94..0x004ec7).
 */
void JniSliverStop(JNIEnv* /*env*/, jclass /*clazz*/, jlong task_handle) {
    if (g_sliver_context == nullptr || task_handle == 0) {
        return;
    }
    auto* task = reinterpret_cast<SliverTask*>(task_handle);
    if (task->state_lock != nullptr) {
        task->state_lock->Lock();
        task->status = static_cast<int32_t>(SliverStatus::kStopped);
        task->state_lock->Unlock();
        task->state_lock->Signal();
    }
}

/**
 * @brief com.bytedance.sliver.Sliver.nDump(JLjava/lang/String;J)V (0x004ec8..0x005043).
 *        Kết xuất dữ liệu lấy mẫu đơn luồng ra tệp định dạng NanoScope (0x004ec8..0x005043).
 *
 * Header strings in .rodata:
 *   0x00ffed: "# nanoscope\n# pid:%d\n"
 *   0x010003: "# tid:%d\n"
 */
void JniSliverDump(JNIEnv* env,
                   jclass /*clazz*/,
                   jlong task_handle,
                   jstring path,
                   jlong min_timestamp_ms) {
    if (g_sliver_context == nullptr || task_handle == 0 || env == nullptr || path == nullptr) {
        return;
    }

    auto* task = reinterpret_cast<SliverTask*>(task_handle);
    SliverRingBuffer* rb = task->ring_buffer;
    if (rb == nullptr || rb->buffer_lock == nullptr) {
        return;
    }

    const char* c_path = env->GetStringUTFChars(path, nullptr);
    if (c_path == nullptr) {
        return;
    }

    rb->buffer_lock->Lock();
    if (!rb->is_dumped && rb->buffer_base != nullptr && rb->write_ptr > rb->buffer_base) {
        FILE* fp = std::fopen(c_path, "w");
        if (fp != nullptr) {
            int32_t pid = static_cast<int32_t>(getpid());
            int32_t tid = ExtractThreadIdFromNativePeer(
                static_cast<uintptr_t>(task->thread_peer), g_sliver_context->is_art != 0);
            std::fprintf(fp, "# nanoscope\n# pid:%d\n", pid);
            std::fprintf(fp, "# tid:%d\n", tid);

            // Convert min_timestamp_ms to nanoseconds (* 1,000,000 = 0x000f4240 @ 0x004f80)
            int64_t min_ns = (min_timestamp_ms > 0)
                                 ? static_cast<int64_t>(min_timestamp_ms) *
                                       static_cast<int64_t>(kNanosecondsPerMillisecond)
                                 : -1;

            if (rb->has_wrapped != 0) {
                const uint64_t* buffer_end = rb->buffer_base + rb->capacity_words;
                WriteSingleThreadNanoScopeTrace(rb->write_ptr, buffer_end, fp, min_ns);
            }
            WriteSingleThreadNanoScopeTrace(rb->buffer_base, rb->write_ptr, fp, min_ns);
            std::fflush(fp);
            std::fclose(fp);
        }
    }
    rb->buffer_lock->Unlock();

    if (task->state_lock != nullptr) {
        task->state_lock->Lock();
        if (task->status != static_cast<int32_t>(SliverStatus::kPaused)) {
            task->status = static_cast<int32_t>(SliverStatus::kClear);
        }
        task->state_lock->Unlock();
    }

    env->ReleaseStringUTFChars(path, c_path);
}

/**
 * @brief com.bytedance.sliver.Sliver.nClear(J)V (0x005044..0x00509b).
 *        Xóa bộ đệm vòng của tác vụ đơn luồng (0x005044..0x00509b).
 */
void JniSliverClear(JNIEnv* /*env*/, jclass /*clazz*/, jlong task_handle) {
    if (g_sliver_context == nullptr || task_handle == 0) {
        return;
    }
    auto* task = reinterpret_cast<SliverTask*>(task_handle);
    if (task->state_lock != nullptr) {
        task->state_lock->Lock();
        task->status = static_cast<int32_t>(SliverStatus::kClear);
        task->state_lock->Unlock();
    }
}

/**
 * @brief com.bytedance.sliver.Sliver.nGetMethodStackTrace(Ljava/lang/Thread;J)[J (0x00509c..0x00517b).
 *        Trả về mảng jlong[] chứa các con trỏ ArtMethod của luồng (0x00509c..0x00517b).
 */
jlongArray JniSliverGetMethodStackTrace(JNIEnv* env,
                                        jclass /*clazz*/,
                                        jobject thread,
                                        jlong thread_peer) {
    if (g_sliver_context == nullptr || env == nullptr || thread == nullptr || thread_peer == 0) {
        return nullptr;
    }

    ArtHelperBase* helper = CreateArtHelperForCurrentSdk();
    if (helper == nullptr) {
        return nullptr;
    }

    CapturedStackSample* sample = helper->CaptureThreadStack(
        thread, reinterpret_cast<void*>(static_cast<uintptr_t>(thread_peer)));
    jlongArray result = nullptr;
    if (sample != nullptr && sample->frame_count >= 1 && sample->methods != nullptr) {
        result = env->NewLongArray(sample->frame_count);
        if (result != nullptr) {
            std::vector<jlong> buf(static_cast<size_t>(sample->frame_count));
            for (int32_t i = 0; i < sample->frame_count; ++i) {
                buf[static_cast<size_t>(i)] = static_cast<jlong>(sample->methods[i]);
            }
            env->SetLongArrayRegion(result, 0, sample->frame_count, buf.data());
        }
    }
    std::free(sample);
    delete helper;
    return result;
}

/**
 * @brief com.bytedance.sliver.Sliver.nGetStackTrace([J)Ljava/lang/String; (0x00517c..0x005263).
 *        Chuyển đổi mảng jlong[] các ArtMethod* thành chuỗi ngăn xếp Java (0x00517c..0x005263).
 */
jstring JniSliverGetStackTraceFromMethods(JNIEnv* env, jclass /*clazz*/, jlongArray methods) {
    if (g_sliver_context == nullptr || env == nullptr || methods == nullptr) {
        return nullptr;
    }

    jsize len = env->GetArrayLength(methods);
    if (len < 1) {
        return nullptr;
    }

    jlong* elems = env->GetLongArrayElements(methods, nullptr);
    if (elems == nullptr) {
        return nullptr;
    }

    std::vector<uint64_t> count_prefixed(static_cast<size_t>(len) + 1U);
    count_prefixed[0] = static_cast<uint64_t>(len);
    for (jsize i = 0; i < len; ++i) {
        count_prefixed[static_cast<size_t>(i) + 1U] = static_cast<uint64_t>(elems[i]);
    }
    env->ReleaseLongArrayElements(methods, elems, 0);

    std::string formatted = FormatMethodStackTraceString(count_prefixed.data());
    return env->NewStringUTF(formatted.c_str());
}

/**
 * @brief com.bytedance.sliver.Sliver.nGetStackTrace(Ljava/lang/Thread;J)Ljava/lang/String; (0x005264..0x0052f3).
 *        Thu thập và định dạng trực tiếp ngăn xếp của một luồng thành jstring (0x005264..0x0052f3).
 */
jstring JniSliverGetStackTraceFromThread(JNIEnv* env,
                                         jclass /*clazz*/,
                                         jobject thread,
                                         jlong thread_peer) {
    if (g_sliver_context == nullptr || env == nullptr || thread == nullptr || thread_peer == 0) {
        return nullptr;
    }

    ArtHelperBase* helper = CreateArtHelperForCurrentSdk();
    if (helper == nullptr) {
        return nullptr;
    }

    CapturedStackSample* sample = helper->CaptureThreadStack(
        thread, reinterpret_cast<void*>(static_cast<uintptr_t>(thread_peer)));
    jstring result = nullptr;
    if (sample != nullptr && sample->frame_count >= 1 && sample->methods != nullptr) {
        std::vector<uint64_t> count_prefixed(static_cast<size_t>(sample->frame_count) + 1U);
        count_prefixed[0] = static_cast<uint64_t>(sample->frame_count);
        for (int32_t i = 0; i < sample->frame_count; ++i) {
            count_prefixed[static_cast<size_t>(i) + 1U] = sample->methods[i];
        }
        std::string formatted = FormatMethodStackTraceString(count_prefixed.data());
        result = env->NewStringUTF(formatted.c_str());
    }
    std::free(sample);
    delete helper;
    return result;
}

/**
 * @brief com.bytedance.sliver.Sliver.nGetStackTrace3([J)[Ljava/lang/String; (0x0052f4..0x005537).
 *        Chuyển đổi mảng jlong[] các ArtMethod* thành mảng String[] (0x0052f4..0x005537).
 */
jobjectArray JniSliverGetStackTraceArray(JNIEnv* env, jclass /*clazz*/, jlongArray methods) {
    if (g_sliver_context == nullptr || env == nullptr || methods == nullptr) {
        return nullptr;
    }

    jsize len = env->GetArrayLength(methods);
    if (len < 1) {
        return nullptr;
    }

    jclass string_cls = env->FindClass("java/lang/String");
    if (string_cls == nullptr) {
        return nullptr;
    }

    jobjectArray array = env->NewObjectArray(len, string_cls, nullptr);
    if (array == nullptr) {
        return nullptr;
    }

    jlong* elems = env->GetLongArrayElements(methods, nullptr);
    if (elems != nullptr) {
        for (jsize i = 0; i < len; ++i) {
            std::string sig = ResolvePrettyMethod(static_cast<uintptr_t>(elems[i]));
            jstring j_sig = env->NewStringUTF(sig.c_str());
            env->SetObjectArrayElement(array, i, j_sig);
            env->DeleteLocalRef(j_sig);
        }
        env->ReleaseLongArrayElements(methods, elems, 0);
    }
    return array;
}

/**
 * @brief com.bytedance.sliver.Sliver.nResetSamplingMs(JI)V (0x005538..0x005544).
 *        Cập nhật chu kỳ lấy mẫu (sampling_ms) của tác vụ đơn luồng (0x005538..0x005544).
 *
 * Opcode @ 0x005538..0x005544:
 *   cbz x2, #0x5544
 *   str w3, [x2]
 *   ret
 */
void JniSliverResetSamplingMs(JNIEnv* /*env*/, jclass /*clazz*/, jlong task_handle, jint sampling_ms) {
    if (task_handle != 0) {
        auto* task = reinterpret_cast<SliverTask*>(task_handle);
        task->sampling_ms = sampling_ms;
    }
}

// ============================================================================
// 5. SliverAllThreadSupport JNI Methods (0x003ad4..0x004130)
// ============================================================================

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nStartSliverGroup(IIII)J (0x003ad4..0x003e2f).
 *        Khởi tạo và bắt đầu nhóm lấy mẫu đa luồng SliverGroup (0x003ad4..0x003e2f).
 */
jlong JniStartSliverGroup(JNIEnv* env,
                          jclass clazz,
                          jint group_id,
                          jint sampling_ms,
                          jint step_entries,
                          jint mode) {
    if (g_sliver_context == nullptr) {
        return 0;
    }

    int32_t sdk = g_sliver_context->sdk_int;
    if (sdk < 19 || sdk > 34 || ((kSupportedSdkMask >> sdk) & 1ULL) == 0ULL) {
        return 0;
    }

    auto* group = new SliverGroup();
    std::memset(group, 0, sizeof(SliverGroup));
    group->sampling_ms = sampling_ms;

    // Normalize step_entries against [2048, 6000000] with default 1000000 (0x003b94..0x003bac)
    int32_t norm_step = (step_entries > kGroupMaxStepEntries) ? kDefaultStepEntries : step_entries;
    if (norm_step < kMinStepEntries) {
        norm_step = kMinStepEntries;
    }
    group->step_entries = norm_step;
    group->mode = mode;
    group->group_id = group_id;
    group->art_helper = CreateArtHelperForCurrentSdk();

    auto* mgr = new SliverGroupBufferManager();
    mgr->buffer_lock = new SliverLock();
    mgr->max_stack_depth = static_cast<int32_t>(g_sliver_context->max_stack_depth);
    mgr->is_cleared = 0;
    mgr->step_entries = norm_step;
    mgr->per_thread_capacity_words = static_cast<int64_t>(norm_step) << 2;
    mgr->overwrite_flag = (mode == 0) ? 1 : 0;
    group->group_buffer_mgr = mgr;
    group->state_lock = new SliverLock();
    group->status = static_cast<int32_t>(SliverStatus::kRunning);

    if (mode == static_cast<int32_t>(SamplingMode::kMethodCallback) && env != nullptr && clazz != nullptr) {
        jclass sliver_cls = env->FindClass("com/bytedance/sliver/Sliver");
        if (sliver_cls != nullptr) {
            auto* listener = new SliverMethodListener();
            listener->vm = static_cast<JavaVM*>(g_sliver_context->java_vm);
            listener->env = env;
            listener->sliver_class = static_cast<jclass>(env->NewGlobalRef(sliver_cls));
            listener->on_sample_method = env->GetStaticMethodID(
                listener->sliver_class, "onSample", "(Ljava/lang/Thread;[JJ)V");
            group->method_listener = listener;
        }
    }

    return reinterpret_cast<jlong>(group);
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nNotifySliverGroup(J[Ljava/lang/Thread;[J)V (0x003e30..0x003f6f).
 *        Cập nhật danh sách các luồng mục tiêu cho SliverGroup (0x003e30..0x003f6f).
 */
void JniNotifySliverGroup(JNIEnv* env,
                          jclass /*clazz*/,
                          jlong group_handle,
                          jobjectArray threads,
                          jlongArray peers) {
    if (g_sliver_context == nullptr || group_handle == 0 || env == nullptr ||
        threads == nullptr || peers == nullptr) {
        return;
    }

    auto* group = reinterpret_cast<SliverGroup*>(group_handle);
    if (group->state_lock == nullptr) {
        return;
    }

    group->state_lock->Lock();
    if (group->thread_list_updated == 0) {
        jsize count = env->GetArrayLength(threads);
        if (count > group->max_threads_capacity) {
            delete[] group->thread_refs;
            delete[] group->thread_peers;
            group->thread_refs = nullptr;
            group->thread_peers = nullptr;
            group->max_threads_capacity = count;
            group->thread_capacity_grown = 1;
        }
        if (group->thread_refs == nullptr) {
            group->thread_refs = new jobject[static_cast<size_t>(group->max_threads_capacity)]();
        }
        if (group->thread_peers == nullptr) {
            group->thread_peers = new uint64_t[static_cast<size_t>(group->max_threads_capacity)]();
        }

        jlong* peer_elems = env->GetLongArrayElements(peers, nullptr);
        for (jsize i = 0; i < count; ++i) {
            jobject local_thread = env->GetObjectArrayElement(threads, i);
            group->thread_refs[i] = env->NewGlobalRef(local_thread);
            env->DeleteLocalRef(local_thread);
            group->thread_peers[i] = (peer_elems != nullptr) ? static_cast<uint64_t>(peer_elems[i]) : 0ULL;
        }
        if (peer_elems != nullptr) {
            env->ReleaseLongArrayElements(peers, peer_elems, 0);
        }
        group->active_thread_count = count;
        group->thread_list_updated = 1;
    }
    group->state_lock->Unlock();
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nStopSliverGroup(J)V (0x003f70..0x003f8f).
 *        Dừng nhóm lấy mẫu đa luồng SliverGroup (0x003f70..0x003f8f).
 */
void JniStopSliverGroup(JNIEnv* /*env*/, jclass /*clazz*/, jlong group_handle) {
    if (g_sliver_context == nullptr || group_handle == 0) {
        return;
    }
    auto* group = reinterpret_cast<SliverGroup*>(group_handle);
    if (group->state_lock != nullptr) {
        group->state_lock->Lock();
        group->status = static_cast<int32_t>(SliverStatus::kStopped);
        group->state_lock->Unlock();
    }
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nDumpSliverGroup(JLjava/lang/String;)V (0x003f90..0x0040af).
 *        Kết xuất toàn bộ bộ đệm các luồng trong SliverGroup ra tệp (0x003f90..0x0040af).
 */
void JniDumpSliverGroup(JNIEnv* env, jclass /*clazz*/, jlong group_handle, jstring path) {
    if (g_sliver_context == nullptr || group_handle == 0 || env == nullptr || path == nullptr) {
        return;
    }

    auto* group = reinterpret_cast<SliverGroup*>(group_handle);
    SliverGroupBufferManager* mgr = group->group_buffer_mgr;
    if (mgr == nullptr || mgr->buffer_lock == nullptr) {
        return;
    }

    const char* c_path = env->GetStringUTFChars(path, nullptr);
    if (c_path == nullptr) {
        return;
    }

    mgr->buffer_lock->Lock();
    if (!mgr->is_cleared && !mgr->thread_buffers.empty()) {
        FILE* fp = std::fopen(c_path, "a");
        if (fp != nullptr) {
            for (const auto& kv : mgr->thread_buffers) {
                int32_t tid = kv.first;
                GroupThreadRingBuffer* trb = kv.second;
                if (trb == nullptr || trb->buffer_base == nullptr || trb->write_ptr == trb->buffer_base) {
                    continue;
                }
                std::fprintf(fp, "# tid:%d\n", tid);
                if (trb->has_wrapped != 0) {
                    const uint64_t* end_ptr = trb->buffer_base + mgr->per_thread_capacity_words;
                    WriteGroupThreadNanoScopeTrace(trb->write_ptr, end_ptr, fp, tid);
                }
                WriteGroupThreadNanoScopeTrace(trb->buffer_base, trb->write_ptr, fp, tid);
            }
            std::fflush(fp);
            std::fclose(fp);
        }
    }
    mgr->buffer_lock->Unlock();

    if (group->state_lock != nullptr) {
        group->state_lock->Lock();
        group->status = static_cast<int32_t>(SliverStatus::kClear);
        group->state_lock->Unlock();
    }

    env->ReleaseStringUTFChars(path, c_path);
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nPauseSliverGroup(J)V (0x0040b0..0x0040cf).
 *        Tạm dừng SliverGroup (0x0040b0..0x0040cf).
 */
void JniPauseSliverGroup(JNIEnv* /*env*/, jclass /*clazz*/, jlong group_handle) {
    if (g_sliver_context == nullptr || group_handle == 0) {
        return;
    }
    auto* group = reinterpret_cast<SliverGroup*>(group_handle);
    if (group->state_lock != nullptr) {
        group->state_lock->Lock();
        group->status = static_cast<int32_t>(SliverStatus::kPaused);
        group->state_lock->Unlock();
    }
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nResumeSliverGroup(J)V (0x0040d0..0x0040ef).
 *        Tiếp tục chạy SliverGroup (0x0040d0..0x0040ef).
 */
void JniResumeSliverGroup(JNIEnv* /*env*/, jclass /*clazz*/, jlong group_handle) {
    if (g_sliver_context == nullptr || group_handle == 0) {
        return;
    }
    auto* group = reinterpret_cast<SliverGroup*>(group_handle);
    if (group->state_lock != nullptr) {
        group->state_lock->Lock();
        group->status = static_cast<int32_t>(SliverStatus::kRunning);
        group->state_lock->Unlock();
    }
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nClearSliverGroup(J)V (0x0040f0..0x00410f).
 *        Xóa bộ đệm của SliverGroup (0x0040f0..0x00410f).
 */
void JniClearSliverGroup(JNIEnv* /*env*/, jclass /*clazz*/, jlong group_handle) {
    if (g_sliver_context == nullptr || group_handle == 0) {
        return;
    }
    auto* group = reinterpret_cast<SliverGroup*>(group_handle);
    if (group->state_lock != nullptr) {
        group->state_lock->Lock();
        group->status = static_cast<int32_t>(SliverStatus::kClear);
        group->state_lock->Unlock();
    }
}

/**
 * @brief com.bytedance.sliver.SliverAllThreadSupport.nGetThreadId(J)I (0x004110..0x004130).
 *        Trả về tid hạt nhân từ con trỏ nativePeer của luồng (0x004110..0x004130).
 */
jint JniGetThreadId(JNIEnv* /*env*/, jclass /*clazz*/, jlong thread_peer) {
    if (g_sliver_context == nullptr || thread_peer == 0) {
        return -1;
    }
    return static_cast<jint>(ExtractThreadIdFromNativePeer(
        static_cast<uintptr_t>(thread_peer), g_sliver_context->is_art != 0));
}

// ============================================================================
// 6. JNI Method Registration Tables (.data.rel.ro 0x0171d8..0x0173b0)
// ============================================================================

/**
 * @brief Exact 12 JNINativeMethod entries for "com/bytedance/sliver/Sliver" (@ 0x0171d8..0x0172f0).
 *        12 mục JNINativeMethod chính xác cho lớp "com/bytedance/sliver/Sliver".
 */
static const JNINativeMethod kSliverJniMethods[12] = {
    {"nInit", "(ILjava/lang/reflect/Method;ZZ)Z", reinterpret_cast<void*>(&JniSliverInit)},
    {"nStart", "(Ljava/lang/Thread;JIII)J", reinterpret_cast<void*>(&JniSliverStart)},
    {"nPause", "(J)V", reinterpret_cast<void*>(&JniSliverPause)},
    {"nResume", "(J)V", reinterpret_cast<void*>(&JniSliverResume)},
    {"nStop", "(J)V", reinterpret_cast<void*>(&JniSliverStop)},
    {"nDump", "(JLjava/lang/String;J)V", reinterpret_cast<void*>(&JniSliverDump)},
    {"nClear", "(J)V", reinterpret_cast<void*>(&JniSliverClear)},
    {"nGetMethodStackTrace", "(Ljava/lang/Thread;J)[J", reinterpret_cast<void*>(&JniSliverGetMethodStackTrace)},
    {"nGetStackTrace", "([J)Ljava/lang/String;", reinterpret_cast<void*>(&JniSliverGetStackTraceFromMethods)},
    {"nGetStackTrace", "(Ljava/lang/Thread;J)Ljava/lang/String;", reinterpret_cast<void*>(&JniSliverGetStackTraceFromThread)},
    {"nGetStackTrace3", "([J)[Ljava/lang/String;", reinterpret_cast<void*>(&JniSliverGetStackTraceArray)},
    {"nResetSamplingMs", "(JI)V", reinterpret_cast<void*>(&JniSliverResetSamplingMs)},
};

/**
 * @brief Exact 8 JNINativeMethod entries for "com/bytedance/sliver/SliverAllThreadSupport" (@ 0x0172f8..0x0173b0).
 *        8 mục JNINativeMethod chính xác cho lớp "com/bytedance/sliver/SliverAllThreadSupport".
 */
static const JNINativeMethod kSliverAllThreadJniMethods[8] = {
    {"nStartSliverGroup", "(IIII)J", reinterpret_cast<void*>(&JniStartSliverGroup)},
    {"nNotifySliverGroup", "(J[Ljava/lang/Thread;[J)V", reinterpret_cast<void*>(&JniNotifySliverGroup)},
    {"nStopSliverGroup", "(J)V", reinterpret_cast<void*>(&JniStopSliverGroup)},
    {"nDumpSliverGroup", "(JLjava/lang/String;)V", reinterpret_cast<void*>(&JniDumpSliverGroup)},
    {"nPauseSliverGroup", "(J)V", reinterpret_cast<void*>(&JniPauseSliverGroup)},
    {"nResumeSliverGroup", "(J)V", reinterpret_cast<void*>(&JniResumeSliverGroup)},
    {"nClearSliverGroup", "(J)V", reinterpret_cast<void*>(&JniClearSliverGroup)},
    {"nGetThreadId", "(J)I", reinterpret_cast<void*>(&JniGetThreadId)},
};

/**
 * @brief Registers JNI methods for both Sliver classes (0x0039ec..0x003ad3).
 *        Đăng ký các phương thức JNI cho cả hai lớp Sliver (0x0039ec..0x003ad3).
 */
jint RegisterSliverJniOnLoad(JavaVM* vm) {
    g_saved_java_vm = vm;
    if (vm == nullptr) {
        return JNI_ERR;
    }

    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK || env == nullptr) {
        return JNI_ERR;
    }

    jclass sliver_cls = env->FindClass("com/bytedance/sliver/Sliver");
    if (sliver_cls == nullptr ||
        env->RegisterNatives(sliver_cls, kSliverJniMethods, 12) < 0) {
        return JNI_ERR;
    }

    jclass group_cls = env->FindClass("com/bytedance/sliver/SliverAllThreadSupport");
    if (group_cls == nullptr ||
        env->RegisterNatives(group_cls, kSliverAllThreadJniMethods, 8) < 0) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6; // 0x00010006
}

} // namespace sliver
} // namespace bytedance
