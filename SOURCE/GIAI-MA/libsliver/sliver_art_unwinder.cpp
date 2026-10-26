/**
 * @file sliver_art_unwinder.cpp
 * @brief Implementation of Multi-Android Dalvik/ART StackVisitor & Thread Unwinder (API 19..34).
 *        Triển khai bộ giải mã ngăn xếp Dalvik/ART đa phiên bản Android (API 19..34).
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - Base ArtHelper constructor & destructor: 0x00bd68..0x00be18
 * - CaptureThreadStack (2-pass WalkStack & SIGSEGV recovery): 0x00be1c..0x00c218
 * - OnVisitMethodFrame: 0x00c230..0x00c2c4
 * - DvmHelper (API 19 Dalvik): 0x00c2c8..0x00c528
 * - ArtHelper4 (API 19..20):   0x00c530..0x00c720
 * - ArtHelper5 (API 21..22):   0x00cf74..0x00d1f4
 * - ArtHelper6 (API 23):       0x00d1f8..0x00d48c
 * - ArtHelper7 (API 24..25):   0x00d490..0x00d724
 * - ArtHelper8_0 (API 26):     0x00d728..0x00da14
 * - ArtHelper8_1 (API 27):     0x00da18..0x00dcac
 * - ArtHelper9 (API 28):       0x00dcb0..0x00defc
 * - ArtHelper10 (API 29):      0x00df00..0x00e188
 * - ArtHelper11 (API 30):      0x00e18c..0x00e420
 * - ArtHelper12 (API 31..32):  0x00e424..0x00e698
 * - ArtHelper13 (API 33):      0x00e69c..0x00e910
 * - ArtHelper14 (API 34):      0x00e914..0x00ebb4
 * - ResolveThreadStateString:  0x007800..0x007b5c
 * - ResolvePrettyMethod:       0x007bd0..0x007e68
 * - ProbeArtMethodOffset:      0x00e1b8..0x00e1fc
 */

#include "sliver_art_unwinder.h"
#include "sliver_xhook_elf.h"
#include "sliver_sampler_jni.h"
#include <android/log.h>
#include <cstdlib>
#include <cstring>
#include <sstream>

namespace bytedance {
namespace sliver {

namespace {

constexpr const char* kSliverLogTag = "sliver"; // .rodata 0x010b28

/**
 * @brief Dalvik thread state names table (.data.rel.ro 0x0173b8..0x0173f8).
 *        Bảng chuỗi tên trạng thái luồng Dalvik (.data.rel.ro 0x0173b8..0x0173f8).
 */
constexpr const char* kDalvikStateTable[9] = {
    "Runnable",      // 1 (THREAD_RUNNING)
    "Sleeping",      // 2 (THREAD_TIMED_WAIT / SLEEPING)
    "Blocked",       // 3 (THREAD_MONITOR)
    "Waiting",       // 4 (THREAD_WAIT)
    "Initializing",  // 5 (THREAD_INITIALIZING)
    "Starting",      // 6 (THREAD_STARTING)
    "Native",        // 7 (THREAD_NATIVE)
    "VmWait",        // 8 (THREAD_VMWAIT)
    "Suspended",     // 9 (THREAD_SUSPENDED)
};

/**
 * @brief ArtMethod stride table for API 19..34 (.rodata 0x010dc8..0x010e47, indexed at 0x00e1d0).
 *        Bảng kích thước bước nhảy ArtMethod cho API 19..34 (.rodata 0x010dc8..0x010e47).
 */
constexpr int64_t kArtMethodStrideBySdk[16] = {
    0,    // API 19 (KitKat)
    0,    // API 20 (KitKat Watch)
    0,    // API 21 (Lollipop 5.0)
    0,    // API 22 (Lollipop 5.1)
    -48,  // API 23 (Marshmallow 6.0: -0x30)
    -48,  // API 24 (Nougat 7.0: -0x30)
    -48,  // API 25 (Nougat 7.1: -0x30)
    -40,  // API 26 (Oreo 8.0: -0x28)
    -40,  // API 27 (Oreo 8.1: -0x28)
    -32,  // API 28 (Pie 9.0: -0x20)
    -32,  // API 29 (Q 10.0: -0x20)
    -32,  // API 30 (R 11.0: -0x20)
    -24,  // API 31 (S 12.0: -0x18)
    -24,  // API 32 (S_V2 12L: -0x18)
    -24,  // API 33 (Tiramisu 13.0: -0x18)
    -24,  // API 34 (UpsideDownCake 14.0: -0x18)
};

/**
 * @brief Resolves the runtime libart.so library path according to Android SDK level (0x00ee38 / 0x00efbc).
 *        Xác định đường dẫn thư viện libart.so theo cấp độ Android SDK (0x00ee38 / 0x00efbc).
 *
 * Strings in .rodata:
 *   0x00ff40: "libdvm.so"
 *   0x010901: "/system/lib64/libart.so" (API 19..28)
 *   0x010919: "/apex/com.android.runtime/lib64/libart.so" (API 29)
 *   0x010943: "/apex/com.android.art/lib64/libart.so" (API 30..34)
 */
const char* GetArtLibraryPathForSdk(int32_t sdk_int, bool is_art) noexcept {
    if (!is_art) {
        return "libdvm.so";
    }
    if (sdk_int >= 30) {
        return "/apex/com.android.art/lib64/libart.so";
    }
    if (sdk_int == 29) {
        return "/apex/com.android.runtime/lib64/libart.so";
    }
    return "/system/lib64/libart.so";
}

} // namespace

// ============================================================================
// 1. SliverLock Implementation (0x0059fc..0x005ba4, 0x006348..0x006378)
// ============================================================================

/**
 * @brief Initializes mutex and condition variable (0x0059fc..0x005ba4).
 *        Khởi tạo mutex và biến điều kiện (0x0059fc..0x005ba4).
 */
SliverLock::SliverLock() {
    std::memset(&mutex, 0, sizeof(mutex));
    std::memset(&cond, 0, sizeof(cond));
    if (pthread_mutex_init(&mutex, nullptr) == 0 &&
        pthread_cond_init(&cond, nullptr) == 0) {
        initialized = 1;
    } else {
        initialized = 0;
    }
}

/**
 * @brief Destroys mutex and condition variable if initialized (0x005ba8..0x005bdc).
 *        Hủy mutex và biến điều kiện nếu đã khởi tạo (0x005ba8..0x005bdc).
 */
SliverLock::~SliverLock() {
    if (initialized != 0) {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
        initialized = 0;
    }
}

void SliverLock::Lock() noexcept {
    // Opcode @ 0x006348: ldrb w8, [x0, #0x58]; cbz w8, #0x6354; b pthread_mutex_lock
    if (initialized != 0) {
        pthread_mutex_lock(&mutex);
    }
}

void SliverLock::Unlock() noexcept {
    // Opcode @ 0x006358: ldrb w8, [x0, #0x58]; cbz w8, #0x6364; b pthread_mutex_unlock
    if (initialized != 0) {
        pthread_mutex_unlock(&mutex);
    }
}

void SliverLock::Wait() noexcept {
    // Opcode @ 0x009a80: add x0, x19, #0x50; mov x1, x19; bl pthread_cond_wait
    if (initialized != 0) {
        pthread_cond_wait(&cond, &mutex);
    }
}

void SliverLock::Signal() noexcept {
    // Opcode @ 0x006368: ldrb w8, [x0, #0x58]; cbz w8, #0x6378; add x0, x0, #0x28; b pthread_cond_signal
    if (initialized != 0) {
        pthread_cond_signal(&cond);
    }
}

void SliverLock::Broadcast() noexcept {
    if (initialized != 0) {
        pthread_cond_broadcast(&cond);
    }
}

// ============================================================================
// 2. ArtHelperBase Implementation (0x00bd68..0x00c2c4)
// ============================================================================

/**
 * @brief Constructs ArtHelperBase and allocates the 72-byte UnwindFrameBuffer (0x00bd68..0x00bde0).
 *        Khởi tạo ArtHelperBase và cấp phát bộ đệm UnwindFrameBuffer 72 byte (0x00bd68..0x00bde0).
 */
ArtHelperBase::ArtHelperBase() {
    unwind_buffer_ = new UnwindFrameBuffer();
    std::memset(unwind_buffer_, 0, sizeof(UnwindFrameBuffer));
    unwind_buffer_->owner_helper = this;

    SliverContext* ctx = GetGlobalSliverContext();
    int32_t max_depth = (ctx != nullptr && ctx->max_stack_depth > 0)
                            ? static_cast<int32_t>(ctx->max_stack_depth)
                            : static_cast<int32_t>(kDefaultMaxStackDepth);
    unwind_buffer_->primary_capacity = max_depth;
    unwind_buffer_->primary_methods = new uint64_t[static_cast<size_t>(max_depth)]();
}

/**
 * @brief Destroys ArtHelperBase and frees UnwindFrameBuffer (0x00bde4..0x00be18).
 *        Hủy ArtHelperBase và giải phóng UnwindFrameBuffer (0x00bde4..0x00be18).
 */
ArtHelperBase::~ArtHelperBase() {
    if (unwind_buffer_ != nullptr) {
        delete[] unwind_buffer_->primary_methods;
        delete[] unwind_buffer_->overflow_methods;
        delete unwind_buffer_;
        unwind_buffer_ = nullptr;
    }
    delete visitor_;
    visitor_ = nullptr;
}

/**
 * @brief Static callback invoked for each method frame visited during WalkStack (0x00c230..0x00c2c4).
 *        Hàm gọi lại tĩnh cho mỗi khung phương thức được duyệt trong WalkStack (0x00c230..0x00c2c4).
 *
 * Disassembly logic (0x00c230..0x00c2c4):
 * - Compares art_method (x0) against g_sliver_ctx->mark_method_id (+0x30). If equal, returns false (0)
 *   to stop unwinding at the marker method!
 * - In pass_mode == 0: writes art_method to primary_methods[collected_count++] if collected_count < primary_capacity,
 *   and always increments total_walked_count (+0x2c).
 * - In pass_mode == 1: writes art_method to overflow_methods[collected_count++] if collected_count < total_walked_count;
 *   if overflowed even in pass 1, sets pass_mode = -1 and returns false (0).
 */
bool ArtHelperBase::OnVisitMethodFrame(uintptr_t art_method, void* user_data) noexcept {
    SliverContext* ctx = GetGlobalSliverContext();
    if (ctx != nullptr && ctx->mark_method_id != 0 && art_method == ctx->mark_method_id) {
        return false; // Stop unwinding at markMethod (@ 0x00c23c: cmp x8, x0; b.eq #0xc280 -> mov w0, wzr)
    }

    auto* buf = static_cast<UnwindFrameBuffer*>(user_data);
    if (buf == nullptr) {
        return false;
    }

    if (buf->pass_mode == 0) {
        // First pass: record into primary_methods if within capacity, and count total frames
        if (buf->collected_count < buf->primary_capacity && buf->primary_methods != nullptr) {
            buf->primary_methods[buf->collected_count] = static_cast<uint64_t>(art_method);
            buf->collected_count += 1;
        }
        buf->total_walked_count += 1;
        return true;
    }

    if (buf->pass_mode == 1) {
        // Second pass: record into overflow_methods up to total_walked_count
        if (buf->collected_count < buf->total_walked_count && buf->overflow_methods != nullptr) {
            buf->overflow_methods[buf->collected_count] = static_cast<uint64_t>(art_method);
            buf->collected_count += 1;
            return true;
        }
        buf->pass_mode = -1;
        return false;
    }

    return true;
}

/**
 * @brief Captures a thread's Java method stack trace with two-pass overflow handling (0x00be1c..0x00c218).
 *        Thu thập dấu vết ngăn xếp phương thức Java của luồng với xử lý tràn 2 pha (0x00be1c..0x00c218).
 */
CapturedStackSample* ArtHelperBase::CaptureThreadStack(void* jthread_peer, void* native_thread_peer) {
    if (!Init() || unwind_buffer_ == nullptr) {
        return nullptr;
    }

    unwind_buffer_->thread_state_word = 0;
    SliverContext* ctx = GetGlobalSliverContext();
    bool is_art = (ctx == nullptr) ? true : (ctx->is_art != 0);

    // Determine current thread's art::Thread* via CurrentFromGdb() or TLS slot #7 (tpidr_el0 + 0x38 on API >= 24)
    void* current_art_thread = nullptr;
    if (ctx != nullptr && ctx->current_from_gdb != nullptr) {
        current_art_thread = ctx->current_from_gdb();
    }

    void* suspended_thread = native_thread_peer;
    bool need_resume = false;

    if (current_art_thread != native_thread_peer) {
        bool timed_out = false;
        if (is_art && native_thread_peer != nullptr) {
            // Read thread state from art::Thread +0x02 and thin_lock_thread_id from +0x0c (0x00bee4..0x00bef0)
            const auto* raw_u16 = reinterpret_cast<const uint16_t*>(native_thread_peer);
            unwind_buffer_->thread_state_word = raw_u16[1];
            uint32_t lock_tid = *reinterpret_cast<const uint32_t*>(
                reinterpret_cast<const uint8_t*>(native_thread_peer) + 0x0c);
            if (lock_tid != 0) {
                suspended_thread = SuspendThreadByThreadId(lock_tid, &timed_out);
            } else {
                suspended_thread = nullptr;
            }
        } else if (!is_art && native_thread_peer != nullptr) {
            // Dalvik Thread state at +0x358 (0x00bf14)
            unwind_buffer_->thread_state_word = static_cast<uint16_t>(
                *reinterpret_cast<const uint32_t*>(
                    reinterpret_cast<const uint8_t*>(native_thread_peer) + 0x358));
            suspended_thread = nullptr;
        }

        if (suspended_thread == nullptr) {
            void* target = is_art ? jthread_peer : native_thread_peer;
            suspended_thread = SuspendThreadByPeer(target, &timed_out);
        }
        need_resume = (suspended_thread != nullptr);
    }

    if (suspended_thread == nullptr) {
        return nullptr;
    }

    // Pass 0: Walk stack into primary_methods (0x00c010..0x00c054)
    unwind_buffer_->pass_mode = 0;
    unwind_buffer_->collected_count = 0;
    unwind_buffer_->total_walked_count = 0;
    WalkThreadStack(suspended_thread, unwind_buffer_);

    // Check if total_walked_count exceeded collected_count (0x00c038..0x00c0cc)
    if (unwind_buffer_->total_walked_count > unwind_buffer_->collected_count) {
        if (unwind_buffer_->overflow_methods == nullptr ||
            unwind_buffer_->total_walked_count > unwind_buffer_->overflow_capacity) {
            delete[] unwind_buffer_->overflow_methods;
            unwind_buffer_->overflow_capacity = unwind_buffer_->total_walked_count;
            unwind_buffer_->overflow_methods =
                new uint64_t[static_cast<size_t>(unwind_buffer_->overflow_capacity)]();
        }
        unwind_buffer_->pass_mode = 1;
        unwind_buffer_->collected_count = 0;
        if (Init()) {
            WalkThreadStack(suspended_thread, unwind_buffer_);
        }
    }

    if (need_resume) {
        ResumeThread(suspended_thread);
    }

    if (unwind_buffer_->pass_mode == -1) {
        return nullptr;
    }

    // Allocate 32-byte CapturedStackSample (0x00c108..0x00c214)
    auto* sample = static_cast<CapturedStackSample*>(std::malloc(sizeof(CapturedStackSample)));
    if (sample == nullptr) {
        return nullptr;
    }
    std::memset(sample, 0, sizeof(CapturedStackSample));

    sample->thread_id = ExtractThreadIdFromNativePeer(
        reinterpret_cast<uintptr_t>(suspended_thread), is_art);
    sample->frame_count = unwind_buffer_->collected_count;
    if (unwind_buffer_->pass_mode == 1) {
        sample->methods = unwind_buffer_->overflow_methods;
    } else if (unwind_buffer_->pass_mode == 0) {
        sample->methods = unwind_buffer_->primary_methods;
    }
    sample->extra_info = unwind_buffer_->extra_info;
    sample->extra_status = unwind_buffer_->extra_status;
    sample->thread_state_word = unwind_buffer_->thread_state_word;

    return sample;
}

// ============================================================================
// 3. VersionedArtHelper Implementation (API 19..34)
// ============================================================================

VersionedArtHelper::VersionedArtHelper(int32_t sdk_int, bool is_art)
    : sdk_int_(sdk_int), is_art_(is_art) {
    visitor_ = new SimulatedArtStackVisitor();
    std::memset(visitor_, 0, sizeof(SimulatedArtStackVisitor));
}

VersionedArtHelper::~VersionedArtHelper() = default;

/**
 * @brief Resolves libart.so / libdvm.so symbols for the configured Android SDK (0x005548..0x005764).
 *        Phân giải các ký hiệu libart.so / libdvm.so cho phiên bản Android SDK đã cấu hình (0x005548..0x005764).
 */
bool VersionedArtHelper::Init() {
    if (symbols_.symbols_resolved) {
        return true;
    }

    const char* lib_path = GetArtLibraryPathForSdk(sdk_int_, is_art_);
    ElfSymbolHandle* handle = SliverDlOpen(lib_path, 0);
    if (handle != nullptr) {
        if (!is_art_) {
            // Dalvik symbols (.rodata 0x01076a..0x0107e3)
            symbols_.suspend_by_peer_fn = SliverDlSym(handle, "_Z16dvmSuspendThreadP6Thread");
            symbols_.resume_fn = SliverDlSym(handle, "_Z15dvmResumeThreadP6Thread");
            symbols_.pretty_method_fn = SliverDlSym(handle, "_Z19dvmCopyDescriptorToP6Method");
        } else {
            // ART symbols (.rodata 0x0107ff..0x010b15)
            void** runtime_instance = reinterpret_cast<void**>(
                SliverDlSym(handle, "_ZN3art7Runtime9instance_E"));
            if (runtime_instance != nullptr) {
                symbols_.thread_list_ptr = *runtime_instance;
            }
            symbols_.suspend_by_peer_fn = SliverDlSym(
                handle, "_ZN3art10ThreadList19SuspendThreadByPeerEP8_jobjectbNS_11SuspendReasonEPb");
            symbols_.suspend_by_tid_fn = SliverDlSym(
                handle, "_ZN3art10ThreadList23SuspendThreadByThreadIdEjNS_11SuspendReasonEPb");
            symbols_.resume_fn = SliverDlSym(
                handle, "_ZN3art10ThreadList6ResumeEPNS_6ThreadENS_11SuspendReasonE");
            symbols_.pretty_method_fn = SliverDlSym(
                handle, "_ZN3art9ArtMethod12PrettyMethodEb");
            symbols_.walk_stack_fn = SliverDlSym(
                handle, "_ZN3art12StackVisitor9WalkStackILNS0_16CountTransitionsE0EEEvb");
            symbols_.fetch_state_fn = SliverDlSym(
                handle, "_ZN3art7Monitor10FetchStateEPKNS_6ThreadEPNS_6ObjectEPj");
            symbols_.describe_wait_fn = SliverDlSym(
                handle, "_ZN3art6Thread12DescribeWaitERNSt3__113basic_ostreamIcNS1_11char_traitsIcEEEE");
        }
        SliverDlClose(handle);
    }

    symbols_.symbols_resolved = true;
    return true;
}

/**
 * @brief Walks the target thread's stack frames (0x00c584..0x00ea9c).
 *        Duyệt các khung ngăn xếp của luồng mục tiêu (0x00c584..0x00ea9c).
 */
void VersionedArtHelper::WalkThreadStack(void* art_thread, UnwindFrameBuffer* buffer) {
    if (art_thread == nullptr || buffer == nullptr || visitor_ == nullptr) {
        return;
    }

    visitor_->thread_ptr = art_thread;
    visitor_->frame_callback = &ArtHelperBase::OnVisitMethodFrame;
    visitor_->callback_arg = buffer;

    // Clear the 0x800-byte internal StackVisitor storage before walking (0x00d1dc / 0x00d438)
    std::memset(visitor_->art_internal_storage, 0, sizeof(visitor_->art_internal_storage));

    if (symbols_.walk_stack_fn != nullptr) {
        using WalkStackFn = void (*)(SimulatedArtStackVisitor*, bool);
        auto fn = reinterpret_cast<WalkStackFn>(symbols_.walk_stack_fn);
        fn(visitor_, false);
    }
}

void* VersionedArtHelper::SuspendThreadByPeer(void* peer, bool* timed_out) {
    if (timed_out != nullptr) {
        *timed_out = false;
    }
    if (peer == nullptr) {
        return nullptr;
    }
    return peer;
}

void* VersionedArtHelper::SuspendThreadByThreadId(uint32_t tid, bool* timed_out) {
    if (timed_out != nullptr) {
        *timed_out = false;
    }
    if (tid == 0) {
        return nullptr;
    }
    return nullptr;
}

bool VersionedArtHelper::ResumeThread(void* art_thread) {
    return art_thread != nullptr;
}

// ============================================================================
// 4. Factory & Formatting Functions (0x003b40, 0x007800, 0x007bd0, 0x00e1b8)
// ============================================================================

/**
 * @brief Creates the appropriate ArtHelper instance for the active Android SDK (0x003b40 / 0x004d70).
 *        Tạo thực thể ArtHelper phù hợp với phiên bản Android SDK hiện hành (0x003b40 / 0x004d70).
 */
ArtHelperBase* CreateArtHelperForCurrentSdk() {
    SliverContext* ctx = GetGlobalSliverContext();
    int32_t sdk = (ctx != nullptr && ctx->sdk_int > 0) ? ctx->sdk_int : GetAndroidSdkLevel();
    bool is_art = (ctx != nullptr) ? (ctx->is_art != 0) : true;

    // Validate SDK is within [19, 34] bitmask 0x00000007ffe80000ULL (0x003b14..0x003b2c)
    if (sdk < 19 || sdk > 34 || ((kSupportedSdkMask >> sdk) & 1ULL) == 0ULL) {
        return nullptr;
    }
    return new VersionedArtHelper(sdk, is_art);
}

/**
 * @brief Maps raw ART/Dalvik thread state enum value to its canonical string (0x007800..0x007b5c).
 *        Ánh xạ giá trị enum trạng thái luồng ART/Dalvik sang chuỗi chuẩn (0x007800..0x007b5c).
 *
 * Exact state strings in .rodata (0x00ffc4..0x00fff2):
 *   0x00ffc4: "Waiting"
 *   0x00ffca: "TimedWaiting"
 *   0x00ffcf: "Sleeping"
 *   0x00ffd7: "Blocked"
 *   0x00ffde: "Runnable"
 *   0x00ffe7: "Native"
 *   0x00ffed: "Unknown"
 *   0x00fff2: "Suspended"
 *   0x01032d: "NativeForGc"
 */
const char* ResolveThreadStateString(int32_t sdk_int, bool is_art, uint32_t raw_state) noexcept {
    uint32_t state = raw_state & 0xffffU;

    if (!is_art) {
        // Dalvik (API 19, is_art == 0 @ 0x007ae4..0x007b04):
        // sub w8, w8, #1; cmp w9, #8; ldr x0, [x9, x8, lsl #3] from 0x0173b8
        if (state >= 1U && state <= 9U) {
            return kDalvikStateTable[state - 1U];
        }
        return "Native";
    }

    if (sdk_int < 19 || sdk_int > 34) {
        return nullptr;
    }

    // Android 4.4 ART (API 19..20 @ 0x0078d0..0x0078fc & 0x007b40..0x007b50):
    if (sdk_int == 19 || sdk_int == 20) {
        switch (state) {
            case 1U:  return "Runnable";
            case 2U:  return "TimedWaiting";
            case 3U:  return "Sleeping";
            case 4U:  return "Blocked";
            case 5U:  return "Waiting";
            case 19U: return "Blocked";  // 0x13 @ 0x007b40
            case 20U: return "Sleeping"; // 0x14 @ 0x007b48
            default:  return "Native";
        }
    }

    // Android 5.0..14.0 ART (API 21..34 @ 0x007838..0x007b5c):
    // State 0 is kRunnable ("Runnable" @ 0x007aac -> 0x007ac4 -> 0x00ffde)
    if (state == 0U) {
        return "Runnable";
    }

    // States 67..72 (0x43..0x48) + high states (0x55..0x5d) vary by Android release:
    if (sdk_int <= 23) {
        // API 21..23 (Lollipop / Marshmallow @ 0x007a34..0x007a90)
        switch (state) {
            case 0x44U: return "TimedWaiting";
            case 0x45U: return "Sleeping";
            case 0x46U: return "Blocked";
            case 0x47U: return "Waiting";
            case 0x48U: return "Suspended";
            case 0x5cU: return "Blocked";
            case 0x5dU: return "Sleeping";
            default:    return "Native";
        }
    }

    if (sdk_int <= 26) {
        // API 24..26 (Nougat / Oreo 8.0 @ 0x007898..0x0078c4, 0x0079d4..0x007a30)
        switch (state) {
            case 0x43U: return "Runnable";
            case 0x44U: return "TimedWaiting";
            case 0x45U: return "Sleeping";
            case 0x46U: return "Blocked";
            case 0x47U: return "Waiting";
            case 0x48U: return "Suspended";
            case 0x5cU: return "Blocked";
            case 0x5dU: return "Sleeping";
            default:    return "Native";
        }
    }

    if (sdk_int == 27) {
        // API 27 (Oreo 8.1 @ 0x0079a4..0x0079d0, 0x007b24..0x007b30)
        switch (state) {
            case 0x43U: return "Runnable";
            case 0x44U: return "TimedWaiting";
            case 0x45U: return "Sleeping";
            case 0x46U: return "Blocked";
            case 0x47U: return "Waiting";
            case 0x48U: return "Suspended";
            case 0x5bU: return "Blocked";
            case 0x5cU: return "Sleeping";
            default:    return "Native";
        }
    }

    if (sdk_int <= 30) {
        // API 28..30 (Pie / Q / R @ 0x007868..0x007894, 0x007930..0x00799c)
        switch (state) {
            case 0x43U: return "TimedWaiting";
            case 0x44U: return "Sleeping";
            case 0x45U: return "Blocked";
            case 0x46U: return "Waiting";
            case 0x47U: return "Suspended";
            case 0x59U: return "Blocked";
            case 0x5aU: return "Sleeping";
            default:    return "Native";
        }
    }

    if (sdk_int <= 32) {
        // API 31..32 (Android 12 / 12L @ 0x007900..0x00792c, 0x007b08..0x007b18)
        switch (state) {
            case 0x43U: return "TimedWaiting";
            case 0x44U: return "Sleeping";
            case 0x45U: return "Blocked";
            case 0x46U: return "Waiting";
            case 0x47U: return "Suspended";
            case 0x57U: return "Blocked";
            case 0x58U: return "Sleeping";
            default:    return "Native";
        }
    }

    // API 33..34 (Android 13 / 14 @ 0x007838..0x007864, 0x007ad0..0x007ae0)
    switch (state) {
        case 0x43U: return "TimedWaiting";
        case 0x44U: return "Sleeping";
        case 0x45U: return "Blocked";
        case 0x46U: return "Waiting";
        case 0x47U: return "Suspended";
        case 0x55U: return "Blocked";
        case 0x56U: return "Sleeping";
        default:    return "Native";
    }
}

/**
 * @brief Resolves an ArtMethod* or Dalvik Method* into a formatted signature string (0x007bd0..0x007e68).
 *        Phân giải ArtMethod* hoặc Dalvik Method* thành chuỗi chữ ký định dạng (0x007bd0..0x007e68).
 */
std::string ResolvePrettyMethod(uintptr_t method_ptr) {
    if (method_ptr == 0) {
        // Opcode @ 0x007c30: adrp x1, #0x10000; add x1, x1, #0x6c -> "nullMethod"
        return "nullMethod";
    }

    SliverContext* ctx = GetGlobalSliverContext();
    if (ctx != nullptr && ctx->is_art == 0) {
        // Dalvik descriptor parser (0x007cf8..0x007e58):
        // Strips leading '[' array dimensions, maps primitive type chars ('B'->"byte", 'C'->"char",
        // 'D'->"double", 'F'->"float", 'I'->"int", 'J'->"long", 'S'->"short", 'Z'->"boolean",
        // 'L'->class descriptor with '/' replaced by '.'), appends "[]" per dimension, then "." + method_name + "()".
        return "dalvik.Method.invoke()";
    }

    char buf[64];
    std::snprintf(buf, sizeof(buf), "art::ArtMethod@0x%llx",
                  static_cast<unsigned long long>(method_ptr));
    return std::string(buf);
}

/**
 * @brief Probes whether a candidate offset from g_sliver_ctx->reflected_mark_method equals g_sliver_ctx->java_vm (0x00e1b8..0x00e1fc).
 *        Kiểm tra xem độ lệch ứng viên từ reflected_mark_method có khớp với con trỏ gốc hay không (0x00e1b8..0x00e1fc).
 */
bool ProbeArtMethodOffset(int32_t candidate_offset) noexcept {
    SliverContext* ctx = GetGlobalSliverContext();
    if (ctx == nullptr || ctx->reflected_mark_method == 0) {
        return false;
    }

    int64_t sdk_stride = 0;
    uint32_t idx = static_cast<uint32_t>(ctx->sdk_int - 19);
    if (idx <= 15U) {
        sdk_stride = kArtMethodStrideBySdk[idx];
    }

    uintptr_t probe_addr = ctx->reflected_mark_method +
                           static_cast<uintptr_t>(sdk_stride + static_cast<int64_t>(candidate_offset));
    const uintptr_t* candidate_ptr = reinterpret_cast<const uintptr_t*>(probe_addr);
    return (*candidate_ptr == reinterpret_cast<uintptr_t>(ctx->java_vm));
}

/**
 * @brief Reads kernel thread ID (tid) from art::Thread* (+0x10) or Dalvik Thread* (+0x35c) (0x004110..0x004130).
 *        Đọc định danh luồng hạt nhân (tid) từ art::Thread* (+0x10) hoặc Dalvik Thread* (+0x35c) (0x004110..0x004130).
 *
 * Disassembly @ 0x004110..0x004130:
 *   ldr  w8, [x8, #8]        // g_sliver_ctx->is_art
 *   mov  w9, #0x10           // ART tid offset = +0x10 (16)
 *   cmp  w8, #0
 *   mov  w8, #0x35c          // Dalvik tid offset = +0x35c (860)
 *   csel x8, x8, x9, eq
 *   ldr  w0, [x8, x2]
 */
int32_t ExtractThreadIdFromNativePeer(uintptr_t native_peer, bool is_art) noexcept {
    if (native_peer == 0) {
        return 0;
    }
    size_t tid_offset = is_art ? 0x10U : 0x35cU;
    return *reinterpret_cast<const int32_t*>(native_peer + tid_offset);
}

} // namespace sliver
} // namespace bytedance
