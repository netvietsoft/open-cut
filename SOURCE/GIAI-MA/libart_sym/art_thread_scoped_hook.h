/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_thread_scoped_hook.h
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — ArtThread, ThreadList, ScopedJitSuspend, ScopedSuspendAll,
 *                    ScopedGCCriticalSection, and .init_array Subsystem
 * ============================================================================
 *
 * [EN] Clean-room C++17 declarations for `art::ArtThread`, `art::ThreadList`,
 * `art::ScopedJitSuspend`, `art::ScopedSuspendAll`, `art::ScopedGCCriticalSection`,
 * and the 3 ELF `.init_array` constructors (`0x01b30c`, `0x01baa8`, `0x01c074`),
 * reconstructed from AArch64 disassembly (`0x01a18c..0x01c10c`).
 *
 * [VN] Khai báo C++17 clean-room cho `art::ArtThread`, `art::ThreadList`,
 * `art::ScopedJitSuspend`, `art::ScopedSuspendAll`, `art::ScopedGCCriticalSection`,
 * và 3 hàm khởi tạo `.init_array` (`0x01b30c`, `0x01baa8`, `0x01c074`),
 * được tái dựng từ mã máy AArch64 (`0x01a18c..0x01c10c`).
 * ============================================================================
 */

#ifndef NEXTAI_OPENCUT_LIBART_SYM_THREAD_SCOPED_HOOK_H_
#define NEXTAI_OPENCUT_LIBART_SYM_THREAD_SCOPED_HOOK_H_

#include "art_runtime_heap_jit.h"
#include "art_sym_types.h"

namespace art {

// ============================================================================
// 1. art::ArtThread — Internal `art::Thread*` Access & State Transitions
//    Truy cập luồng nội bộ `art::Thread*` và chuyển đổi trạng thái Mutator/Runnable
//    Addresses / Địa chỉ: 0x01a18c .. 0x01a4df
// ============================================================================

class ArtThread : public ArtSymbolObject {
 public:
  // [0x01a18c] Wraps raw `art::Thread*` pointer
  explicit ArtThread(void* thread) noexcept : ArtSymbolObject(thread) {}

  // [0x01a198] Retrieves current `art::Thread*` via pthread_getspecific(_ZN3art6Thread17pthread_key_self_E)
  static ArtThread* Current() noexcept;

  // [0x01a210] Extracts `art::Thread*` from `JNIEnvExt*` at offset `+0x08` (`env->self_`)
  static ArtThread* CurrentFromEnv(JNIEnv* env) noexcept;

  // [0x01a228] Returns `state_and_flags` 16-bit state word at offset `+0x00` of `tls32_`
  uint16_t GetState() const noexcept;

  // [0x01a234] Returns `tid` (`tls32_.thin_lock_thread_id`) at offset `+0x08` of `art::Thread`
  uint32_t GetTid() const noexcept;

  // [0x01a240] Transitions thread state (`old_state` -> `new_state`) via
  // `Locks::mutator_lock_->SharedLock` / `SharedUnlock`
  uint16_t TransitionFromRunnableToSuspended(uint16_t new_state) noexcept;
  void TransitionFromSuspendedToRunnable() noexcept;

  // [0x01a2c4] Calls `_ZNK3art6Thread13DecodeJObjectEP8_jobject`
  void* DecodeJObject(jobject obj) noexcept;
};

// ============================================================================
// 2. art::ThreadList — Thread Enumeration, ResumeAll/SuspendAll & Timeout Probe
//    Quản lý danh sách luồng, Tạm dừng/Tiếp tục toàn bộ luồng & Dò tìm Timeout
//    Addresses / Địa chỉ: 0x01a4e0 .. 0x01a9af
// ============================================================================

class ThreadList : public ArtSymbolObject {
 public:
  // [0x01a4e0] Constructs wrapper around `art::ThreadList*`
  explicit ThreadList(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x01a4ec] Probes `thread_suspend_timeout_ns_index_` by allocating a 16,384-byte
  // (`0x4000`) zeroed buffer via `calloc(1, 0x4000)`, invoking constructor
  // `_ZN3art10ThreadListC2Em(buf, 12345678ULL)` (where `0x00bc614e = 12345678`),
  // scanning `uint64_t` slots for `12345678ULL`, and hooking `pthread_mutex_destroy`
  // via `ScopedPLTHook` to safely clean up internal mutexes without aborting!
  static bool Init() noexcept;

  // [0x01a6bc] Returns true if `thiz_ != nullptr` and `Init()` succeeded
  bool IsValid() noexcept override;

  // [0x01a718] Reads `list_` (`std::list<Thread*>`) at offset `(thread_suspend_timeout_ns_index_ - 3) * 8`
  std::list<void*>* GetList() const noexcept;

  // [0x01a730] Calls `_ZN3art10ThreadList9ResumeAllEv`
  void ResumeAll() noexcept;

  // [0x01a7dc] Calls `_ZN3art10ThreadList10SuspendAllEPKcb`
  void SuspendAll(const char* cause, bool long_suspend) noexcept;

  // [0x01a8a4] Calls `_ZN3art10ThreadList17WaitForOtherThreadsToBeSuspendedEv` or `SuspendAllDaemonThreads`
  void SuspendAllInternal(ArtThread* self) noexcept;

  // .data 0x025f08 = -1
  static int32_t thread_suspend_timeout_ns_index_;
  // .bss 0x0262f8
  static bool has_init_;
};

// ============================================================================
// 3. art::ScopedJitSuspend — RAII JIT Thread Pool Suspension Guard
//    Lớp bảo vệ RAII tạm dừng luồng biên dịch JIT trong khi chỉnh sửa ArtMethod
//    Addresses / Địa chỉ: 0x01ab8c .. 0x01ade3
// ============================================================================

class ScopedJitSuspend {
 public:
  // [0x01ab8c] Stops JIT thread pool (`Jit::StopThreadPool`), or if unsupported,
  // deletes thread pool (`Jit::DeleteThreadPool`) and disables JIT compilation
  ScopedJitSuspend() noexcept;

  // [0x01acc8] Restarts or recreates JIT thread pool (`Jit::StartThreadPool` / `CreateThreadPool`)
  ~ScopedJitSuspend() noexcept;

 private:
  bool stopped_pool_;  // +0x00
  bool deleted_pool_;  // +0x01
};

// ============================================================================
// 4. art::ScopedSuspendAll — RAII Global Mutator Suspension Guard
//    Lớp bảo vệ RAII tạm dừng toàn bộ các luồng thực thi Java (Stop-The-World)
//    Addresses / Địa chỉ: 0x01ade4 .. 0x01b087
// ============================================================================

class ScopedSuspendAll {
 public:
  // [0x01ade4] Calls `_ZN3art16ScopedSuspendAllC2EPKcb(this, cause, long_suspend)`
  // or falls back to `ThreadList::SuspendAll(cause, long_suspend)`
  ScopedSuspendAll(const char* cause, bool long_suspend) noexcept;

  // [0x01af48] Calls `_ZN3art16ScopedSuspendAllD2Ev(this)`
  // or falls back to `ThreadList::ResumeAll()`
  ~ScopedSuspendAll() noexcept;

  // [0x01b070] Returns true if `SuspendAll` symbols or `ThreadList` fallback are available
  static bool Supported() noexcept;

 private:
  uint64_t reserved_;  // +0x00 (8 bytes)
};

// ============================================================================
// 5. art::ScopedGCCriticalSection — RAII Moving-GC Prevention Guard
//    Lớp bảo vệ RAII ngăn chặn GC di chuyển đối tượng trong vùng găng
//    Addresses / Địa chỉ: 0x01b088 .. 0x01b387
// ============================================================================

class ScopedGCCriticalSection {
 public:
  // [0x01b088] Prevents Moving GC across all Android versions:
  // - API <= 23 (`Heap::UseCompatGCSection()`): acquires `backtrace_lock_` and `gc_complete_lock_`
  // - API 24..25: calls `_ZN3art2gc23ScopedGCCriticalSectionC2EPNS_6ThreadENS0_7GcCauseENS0_13CollectorTypeE`
  // - API >= 26: calls `Heap::IncrementDisableMovingGC(self)`
  ScopedGCCriticalSection(ArtThread* self, uint32_t gc_cause, uint32_t collector_type) noexcept;

  // [0x01b214] Releases GC critical section (`DecrementDisableMovingGC`, `~ScopedGCCriticalSection`,
  // or unlocks `gc_complete_lock_` and `backtrace_lock_`)
  ~ScopedGCCriticalSection() noexcept;

  // [0x01b340] Initializes static `heap` wrapper (`0x026360`) from `ArtRuntime::Get()->GetHeap()`
  static bool Init() noexcept;

  // .bss 0x026360 (40 bytes, initialized by .init_array[0] at 0x01b30c)
  static Heap heap;

 private:
  ArtThread* self_;         // +0x00
  uint8_t opaque_buf_[64];  // +0x08 .. +0x47
};

}  // namespace art

// ============================================================================
// 6. ELF .init_array Constructors & LSE Atomic Helper (0x01b30c, 0x01baa8, 0x01c040)
//    3 hàm khởi tạo tĩnh trong .init_array và hàm nguyên tử ARMv8.1 LSE
// ============================================================================

extern "C" {

// [0x01b30c] .init_array[0]: _GLOBAL__sub_I_scoped_gc_critical_section.cpp
// Initializes `art::ScopedGCCriticalSection::heap` (.bss 0x026360) with `art::Heap(nullptr)`
void init_array_0_scoped_gc_critical_section() noexcept;

// [0x01baa8] .init_array[1]: bytesig_libc_init
// Opens "libc.so" via dlopen and resolves sigprocmask64/sigprocmask and sigaction64/sigaction
void init_array_1_bytesig_libc_resolve() noexcept;

// [0x01c074] .init_array[2]: init_have_lse_atomics
// Queries getauxval(AT_HWCAP=16) & HWCAP_ATOMICS (0x100) and checks "ro.arch" != "exynos9810"
void init_array_2_lse_atomics_probe() noexcept;

// [0x01c040] ARMv8.1-A LSE compare-and-swap helper (`casa w0, w1, [x2]` vs `ldaxr/stxr`)
uint32_t aarch64_cas4_acq(uint32_t expected, uint32_t desired, volatile uint32_t* addr) noexcept;

}  // extern "C"

#endif  // NEXTAI_OPENCUT_LIBART_SYM_THREAD_SCOPED_HOOK_H_
