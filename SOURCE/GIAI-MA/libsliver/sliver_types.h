/**
 * @file sliver_types.h
 * @brief Core ABI Structures, Constants, and Type Definitions for libsliver.so.
 *        Các cấu trúc ABI cốt lõi, hằng số và định nghĩa kiểu cho libsliver.so.
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - Target Binary: libsliver.so (83,984 bytes, AArch64 ELF64 shared object, 24 sections)
 * - Build ID: b5e3bd671e77aa1a306fb91c348c6fa1da7dfec8
 * - Subsystems:
 *   1. ByteDance Sliver Sampling Profiler & NanoScope Trace Writer (0x0039ec..0x008504)
 *   2. ELF64 Dynamic Linker & .gnu_debugdata XZ/LZMA Symbol Resolver (0x008508..0x0099f4)
 *   3. Embedded libxhook 1.2.0 PLT/GOT Hooker & SIGSEGV Protection (0x0099f8..0x00bd64)
 *   4. Multi-Android Dalvik/ART StackVisitor & Thread Unwinder for API 19..34 (0x00bd68..0x00fb88)
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <atomic>
#include <map>
#include <mutex>
#include <string>
#include <vector>
#include <pthread.h>
#include <setjmp.h>
#include <signal.h>

namespace bytedance {
namespace sliver {

// ============================================================================
// 1. Binary Constants & Bitmasks / Hằng số Nhị phân & Mặt nạ Bit (OBSERVED)
// ============================================================================

/**
 * @brief Supported Android SDK bitmask (API 19..34).
 *        Mặt nạ bit các phiên bản Android SDK được hỗ trợ (API 19..34).
 *
 * Opcode @ 0x003b18..0x003b20 & 0x004d4c..0x004d50:
 *   mov  x11, #0xffe80000
 *   movk x11, #0x7, lsl #32   // 0x00000007ffe80000ULL = bits 19..34 set
 */
constexpr uint64_t kSupportedSdkMask = 0x00000007ffe80000ULL;

/**
 * @brief Android 11..14 (API 30..34) bitmask for APEX libart.so dlopen xhook.
 *        Mặt nạ bit Android 11..14 (API 30..34) để hook dlopen cho APEX libart.so.
 *
 * Opcode @ 0x004338..0x00433c:
 *   mov  x11, #0xc0000000
 *   movk x11, #0x6, lsl #32   // 0x00000006c0000000ULL (bits 30, 31, 33, 34; bit 32 handled at 0x004330)
 */
constexpr uint64_t kApexDlopenHookMask = 0x00000006c0000000ULL;

/**
 * @brief Android 9..10 (API 28..29) bitmask for system libart.so dlopen xhook.
 *        Mặt nạ bit Android 9..10 (API 28..29) để hook dlopen cho system libart.so.
 *
 * Opcode @ 0x004390:
 *   mov  w9, #0x30000000      // (1u << 28) | (1u << 29)
 */
constexpr uint32_t kPieQDlopenHookMask = 0x30000000U;

/**
 * @brief Default maximum stack depth initialized in nInit (100 frames).
 *        Độ sâu ngăn xếp tối đa mặc định khởi tạo trong nInit (100 khung).
 *
 * Opcode @ 0x004314..0x00431c:
 *   mov  w8, #0x64
 *   str  x8, [x20, #0x28]
 */
constexpr int64_t kDefaultMaxStackDepth = 100;

/**
 * @brief Ring buffer capacity & step constants (OBSERVED).
 *        Các hằng số dung lượng và bước nhảy của bộ đệm vòng (QUAN SÁT ĐƯỢC).
 *
 * Single-Thread RingBuffer (0x0057dc..0x0057f0):
 *   max_capacity = 4,000,000 (0x003d0900)
 *   default_step = 1,000,000 (0x000f4240)
 *   min_step     =     2,048 (0x00000800)
 *
 * Group RingBufferManager (0x003b94..0x003ba4):
 *   max_capacity = 6,000,000 (0x005b8d80)
 *   default_step = 1,000,000 (0x000f4240)
 *   min_step     =     2,048 (0x00000800)
 */
constexpr int32_t kSingleThreadMaxStepEntries = 4000000;  // 0x003d0900
constexpr int32_t kGroupMaxStepEntries        = 6000000;  // 0x005b8d80
constexpr int32_t kDefaultStepEntries         = 1000000;  // 0x000f4240
constexpr int32_t kMinStepEntries             = 2048;     // 0x00000800

/**
 * @brief Nanoseconds per second & per millisecond constants.
 *        Hằng số nano-giây mỗi giây và mỗi mili-giây.
 *
 * Opcode @ 0x005cb8..0x005cbc & 0x00f7bc..0x00f7c0:
 *   mov  w8, #0xca00
 *   movk w8, #0x3b9a, lsl #16   // 1,000,000,000 = 0x3b9aca00
 * Opcode @ 0x006228..0x00622c:
 *   mov  w8, #0x4240
 *   movk w8, #0xf, lsl #16      // 1,000,000 = 0x000f4240
 */
constexpr uint64_t kNanosecondsPerSecond      = 1000000000ULL; // 0x3b9aca00ULL
constexpr uint64_t kNanosecondsPerMillisecond = 1000000ULL;    // 0x000f4240ULL
constexpr uint64_t kMicrosecondsPerMillisecond = 1000ULL;      // 0x3e8ULL

/**
 * @brief Synthetic thread-state tag mask stored in curr_stack[0].
 *        Mặt nạ thẻ trạng thái luồng tổng hợp lưu tại curr_stack[0].
 *
 * Opcode @ 0x005f78 & 0x006b6c:
 *   orr  x8, x22, #0xffffffffffffff00
 *   str  x8, [x27]
 */
constexpr uint64_t kThreadStateEntryMask = 0xffffffffffffff00ULL;

/**
 * @brief ELF64 and Hash constants used by xdl / xhook (OBSERVED).
 *        Các hằng số ELF64 và Hash được sử dụng bởi xdl / xhook (QUAN SÁT ĐƯỢC).
 */
constexpr uint32_t kElfMagicLe       = 0x464c457fU; // "\x7fELF" @ 0x008620 / 0x00b0f8
constexpr uint32_t kDtGnuHashTag     = 0x6ffffef5U; // DT_GNU_HASH @ 0x008b28 / 0x00a6cc
constexpr uint32_t kDjb2InitialSeed  = 5381U;       // 0x1505 @ 0x0089c8 / 0x00aa94
constexpr uint32_t kAArch64RJumpSlot = 1026U;       // R_AARCH64_JUMP_SLOT (0x402) @ 0x00b1c8
constexpr uint32_t kAArch64RGlobDat  = 1025U;       // R_AARCH64_GLOB_DAT  (0x401) @ 0x00b390
constexpr uint32_t kAArch64RAbs64    = 257U;        // R_AARCH64_ABS64     (0x101) @ 0x00b398

// ============================================================================
// 2. Enumerations / Các kiểu Liệt kê (OBSERVED)
// ============================================================================

/**
 * @brief Sliver task / group runtime status codes.
 *        Mã trạng thái thời gian chạy của tác vụ / nhóm Sliver.
 *
 * Jump table @ 0x005de8 (single-thread) & 0x0069c4 (group):
 *   0 = RUNNING (default sampling state)
 *   1 = PAUSED  (nPause / nPauseSliverGroup)
 *   2 = STOPPED (nStop / nStopSliverGroup)
 *   3 = DUMP    (nDump / nDumpSliverGroup)
 *   4 = CLEAR   (nClear / nClearSliverGroup)
 */
enum class SliverStatus : int32_t {
    kRunning = 0,
    kPaused  = 1,
    kStopped = 2,
    kDump    = 3,
    kClear   = 4,
};

/**
 * @brief Ring buffer sampling mode.
 *        Chế độ lấy mẫu của bộ đệm vòng.
 */
enum class SamplingMode : int32_t {
    kRingGrowable = 0,  // Grows up to max_capacity, stops when full
    kRingCircular = 1,  // Overwrites from start when full (overwrite_flag = 1)
    kMethodCallback = 2 // Invokes Sliver.onSample Java callback in addition to ring buffer
};

/**
 * @brief xHook error codes returned by xhook_register / xhook_ignore / xhook_refresh.
 *        Mã lỗi xHook trả về từ xhook_register / xhook_ignore / xhook_refresh.
 *
 * Opcodes @ 0x009e10, 0x00b0f4..0x00b9d4:
 *   0    = XHOOK_ERRNO_OK
 *   1001 = 0x3e9 = XHOOK_ERRNO_UNKNOWN
 *   1002 = 0x3ea = XHOOK_ERRNO_INVAL
 *   1003 = 0x3eb = XHOOK_ERRNO_NOMEM
 *   1006 = 0x3ee = XHOOK_ERRNO_NOSYM / MAPS open failure
 *   1007 = 0x3ef = XHOOK_ERRNO_ELFINVAL
 *   1009 = 0x3f1 = XHOOK_ERRNO_SEGVERR
 */
enum XHookError : int32_t {
    kXHookOk       = 0,
    kXHookUnknown  = 1001, // 0x3e9
    kXHookInval    = 1002, // 0x3ea
    kXHookNoMem    = 1003, // 0x3eb
    kXHookNoMaps   = 1006, // 0x3ee
    kXHookElfInval = 1007, // 0x3ef
    kXHookSegvErr  = 1009, // 0x3f1
};

// ============================================================================
// 3. Synchronization & Context ABI Structs / Cấu trúc Đồng bộ & Ngữ cảnh
// ============================================================================

/**
 * @brief SliverLock (96 bytes = 0x60 allocated at 0x0059fc).
 *        Cấu trúc khóa đồng bộ và biến điều kiện của Sliver (96 byte = 0x60).
 *
 * Binary Layout (0x0059fc..0x005ba4, 0x006348..0x006378):
 *   +0x00: pthread_mutex_t mutex (40 bytes on AArch64 Bionic)
 *   +0x28: pthread_cond_t  cond  (48 bytes on AArch64 Bionic)
 *   +0x58: uint8_t         initialized (1 if active, 0 if destroyed)
 */
struct SliverLock {
    pthread_mutex_t mutex{};      // +0x00 (40 bytes)
    pthread_cond_t  cond{};       // +0x28 (48 bytes)
    uint8_t         initialized{0}; // +0x58 (1 byte)
    uint8_t         padding[7]{}; // +0x59..+0x5f

    SliverLock();
    ~SliverLock();

    void Lock() noexcept;
    void Unlock() noexcept;
    void Wait() noexcept;
    void Signal() noexcept;
    void Broadcast() noexcept;
};

/**
 * @brief Global SliverContext (64 bytes = 0x40 allocated in nInit @ 0x004158, stored at .bss 0x0180f0).
 *        Ngữ cảnh toàn cục SliverContext (64 byte = 0x40 cấp phát trong nInit @ 0x004158).
 */
struct SliverContext {
    void*     java_vm{nullptr};           // +0x00: JavaVM*
    uint8_t   is_art{1};                  // +0x08: 1 = ART (libart.so), 0 = Dalvik (libdvm.so)
    uint8_t   pad_09[3]{};                // +0x09..+0x0b
    int32_t   sdk_int{0};                 // +0x0c: Android API level (19..34)
    int32_t   jni_version{0x00010006};    // +0x10: JNI_VERSION_1_6
    int32_t   pad_14{0};                  // +0x14
    uintptr_t reflected_mark_method{0};   // +0x18: FromReflectedMethod(markMethod)
    uint8_t   enable_sigsegv_protect{0};  // +0x20: z2 flag from nInit
    uint8_t   hook_dlopen{0};             // +0x21: z1 flag from nInit
    uint8_t   pad_22[6]{};                // +0x22..+0x27
    int64_t   max_stack_depth{kDefaultMaxStackDepth}; // +0x28: 100 (0x64)
    uintptr_t mark_method_id{0};          // +0x30: art::ArtMethod* for markMethod
    void*     (*current_from_gdb)(){nullptr}; // +0x38: _ZN3art6Thread14CurrentFromGdbEv
};

/**
 * @brief TLS Signal Recovery Buffer (8 bytes allocated at 0x00bcd4, stored at .bss 0x018060).
 *        Bộ đệm khôi phục tín hiệu lỗi phân đoạn trên TLS (8 byte tại 0x00bcd4).
 *
 * Layout:
 *   +0x00: pthread_key_t tls_key (4 bytes)
 *   +0x04: uint8_t       key_created (1 byte)
 */
struct SigsegvTlsGuard {
    pthread_key_t tls_key{0};
    uint8_t       key_created{0};
    uint8_t       pad[3]{};
};

/**
 * @brief UnwindFrameBuffer (72 bytes = 0x48 allocated at 0x00bd84).
 *        Bộ đệm lưu trữ kết quả giải mã khung ngăn xếp (72 byte = 0x48).
 *
 * Binary Layout (0x00bd84..0x00bde0, 0x00c010..0x00c230):
 *   +0x00: void*     owner_helper       (ArtHelperBase*)
 *   +0x08: int32_t   pass_mode          (0 = first pass, 1 = second pass after realloc, -1 = failed)
 *   +0x0c: int32_t   thread_id          (tid)
 *   +0x10: uint64_t* native_frames      (optional native PC array)
 *   +0x18: int32_t   primary_capacity   (default max_stack_depth = 100)
 *   +0x1c: int32_t   collected_count    (number of frames written)
 *   +0x20: uint64_t* primary_methods    (allocated array of size primary_capacity * 8)
 *   +0x28: int32_t   overflow_capacity  (allocated capacity of overflow_methods)
 *   +0x2c: int32_t   total_walked_count (total frames encountered in WalkStack)
 *   +0x30: uint64_t* overflow_methods   (dynamically grown array when total_walked_count > primary_capacity)
 *   +0x38: uint64_t  extra_info         (wait monitor / state info)
 *   +0x40: int32_t   extra_status       (0)
 *   +0x44: uint16_t  thread_state_word  (suspend_count & state from art::Thread +0x02 or Dalvik +0x358)
 */
struct UnwindFrameBuffer {
    void*     owner_helper{nullptr};     // +0x00
    int32_t   pass_mode{0};              // +0x08
    int32_t   thread_id{0};              // +0x0c
    uint64_t* native_frames{nullptr};    // +0x10
    int32_t   primary_capacity{0};       // +0x18
    int32_t   collected_count{0};        // +0x1c
    uint64_t* primary_methods{nullptr};  // +0x20
    int32_t   overflow_capacity{0};      // +0x28
    int32_t   total_walked_count{0};     // +0x2c
    uint64_t* overflow_methods{nullptr}; // +0x30
    uint64_t  extra_info{0};             // +0x38
    int32_t   extra_status{0};           // +0x40
    uint16_t  thread_state_word{0};      // +0x44
    uint16_t  pad_46{0};                 // +0x46
};

/**
 * @brief CapturedStackSample (32 bytes = 0x20 allocated at 0x00c108 via 0x00f768).
 *        Mẫu ngăn xếp đã thu thập từ một lần quét luồng (32 byte = 0x20).
 *
 * Binary Layout (0x00c108..0x00c214):
 *   +0x00: int32_t   frame_count
 *   +0x04: int32_t   thread_id          (read from art::Thread +0x10 or Dalvik +0x35c)
 *   +0x08: uint64_t* methods            (pointer to primary_methods or overflow_methods)
 *   +0x10: uint64_t  extra_info
 *   +0x18: int32_t   extra_status
 *   +0x1c: uint16_t  thread_state_word
 */
struct CapturedStackSample {
    int32_t   frame_count{0};            // +0x00
    int32_t   thread_id{0};              // +0x04
    uint64_t* methods{nullptr};          // +0x08
    uint64_t  extra_info{0};             // +0x10
    int32_t   extra_status{0};           // +0x18
    uint16_t  thread_state_word{0};      // +0x1c
    uint16_t  pad_1e{0};                 // +0x1e
};

/**
 * @brief Single-Thread SliverRingBuffer (80 bytes = 0x50 allocated at 0x0057c8).
 *        Bộ đệm vòng đơn luồng SliverRingBuffer (80 byte = 0x50 cấp phát tại 0x0057c8).
 */
struct SliverRingBuffer {
    SliverLock* buffer_lock{nullptr};    // +0x00: 96-byte SliverLock
    uint64_t*   buffer_base{nullptr};    // +0x08: base pointer of trace word ring buffer
    uint64_t*   write_ptr{nullptr};      // +0x10: current write cursor inside buffer_base
    uint64_t    last_sample_ns{0};       // +0x18: timestamp of most recent sample
    uint64_t*   prev_stack{nullptr};     // +0x20: previous sample stack (depth + 1 entries)
    uint64_t*   curr_stack{nullptr};     // +0x28: current sample stack (depth + 1 entries)
    int32_t     prev_depth{0};           // +0x30: previous stack frame count + 1
    int32_t     pad_34{0};               // +0x34
    uint8_t     is_dumped{0};            // +0x38: 1 if already dumped/cleared
    uint8_t     has_wrapped{0};          // +0x39: 1 if circular buffer wrapped around
    uint16_t    pad_3a{0};               // +0x3a
    int32_t     step_entries{0};         // +0x3c: step size in entries (2048..4000000)
    int64_t     capacity_words{0};       // +0x40: total capacity in 64-bit words (step_entries * 4)
    uint8_t     overwrite_flag{0};       // +0x48: 1 if circular overwrite enabled, 0 if growable
    uint8_t     pad_49[7]{};             // +0x49..+0x4f
};

/**
 * @brief Per-Thread Ring Buffer inside SliverGroup (56 bytes = 0x38 allocated at 0x008234).
 *        Bộ đệm vòng của từng luồng trong SliverGroup (56 byte = 0x38 cấp phát tại 0x008234).
 *
 * Binary Layout (0x00820c..0x0082a0, 0x006a00..0x006df4):
 *   +0x00: uint64_t* buffer_base
 *   +0x08: uint64_t* write_ptr
 *   +0x10: uint64_t  last_sample_ns
 *   +0x18: uint64_t* prev_stack
 *   +0x20: uint64_t* curr_stack
 *   +0x28: int32_t   prev_depth
 *   +0x2c: int32_t   thread_id
 *   +0x30: uint8_t   has_wrapped
 */
struct GroupThreadRingBuffer {
    uint64_t* buffer_base{nullptr};      // +0x00
    uint64_t* write_ptr{nullptr};        // +0x08
    uint64_t  last_sample_ns{0};         // +0x10
    uint64_t* prev_stack{nullptr};       // +0x18
    uint64_t* curr_stack{nullptr};       // +0x20
    int32_t   prev_depth{0};             // +0x28
    int32_t   thread_id{0};              // +0x2c
    uint8_t   has_wrapped{0};            // +0x30
    uint8_t   pad_31[7]{};               // +0x31..+0x37
};

/**
 * @brief SliverGroupBufferManager (64 bytes = 0x40 allocated at 0x003b84).
 *        Bộ quản lý các bộ đệm vòng theo luồng của SliverGroup (64 byte = 0x40).
 *
 * Binary Layout (0x003b84..0x003bfc, 0x0069dc..0x006fb8):
 *   +0x00: SliverLock* buffer_lock
 *   +0x08..+0x18: std::map<int32_t, GroupThreadRingBuffer*> thread_buffers (24 bytes RB-tree header)
 *   +0x20: int32_t     max_stack_depth
 *   +0x24: uint8_t     is_cleared
 *   +0x28: int32_t     step_entries
 *   +0x30: int64_t     per_thread_capacity_words (step_entries * 4)
 *   +0x38: uint8_t     overwrite_flag
 */
struct SliverGroupBufferManager {
    SliverLock* buffer_lock{nullptr};                               // +0x00
    std::map<int32_t, GroupThreadRingBuffer*> thread_buffers{};     // +0x08..+0x1f
    int32_t     max_stack_depth{0};                                 // +0x20
    uint8_t     is_cleared{0};                                      // +0x24
    uint8_t     pad_25[3]{};                                        // +0x25..+0x27
    int32_t     step_entries{0};                                    // +0x28
    int32_t     pad_2c{0};                                          // +0x2c
    int64_t     per_thread_capacity_words{0};                       // +0x30
    uint8_t     overwrite_flag{1};                                  // +0x38
    uint8_t     pad_39[7]{};                                        // +0x39..+0x3f
};

} // namespace sliver
} // namespace bytedance
