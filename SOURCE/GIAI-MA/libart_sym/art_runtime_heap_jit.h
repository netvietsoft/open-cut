/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_runtime_heap_jit.h
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — ArtRuntime, Heap, ArtInstrumentation, Jit, JitCodeCache,
 *                    ReaderWriterMutex, and Locks Subsystem
 * ============================================================================
 *
 * [EN] Clean-room C++17 declarations for `art::Heap`, `art::instrumentation::ArtInstrumentation`,
 * `art::InstrumentationStackPopper`, `art::jit::Jit`, `art::jit::JitCodeCache`,
 * `art::jit::JitOptions`, `art::ReaderWriterMutex`, `art::ReaderWriterMutexMock`,
 * `art::Locks`, and `art::ArtRuntime`, reconstructed from AArch64 disassembly
 * (`0x016144..0x01a18b` and `0x01a9b0..0x01ab87`).
 *
 * [VN] Khai báo C++17 clean-room cho `art::Heap`, `art::instrumentation::ArtInstrumentation`,
 * `art::InstrumentationStackPopper`, `art::jit::Jit`, `art::jit::JitCodeCache`,
 * `art::jit::JitOptions`, `art::ReaderWriterMutex`, `art::ReaderWriterMutexMock`,
 * `art::Locks`, và `art::ArtRuntime`, được tái dựng từ mã máy AArch64
 * (`0x016144..0x01a18b` và `0x01a9b0..0x01ab87`).
 * ============================================================================
 */

#ifndef NEXTAI_OPENCUT_LIBART_SYM_RUNTIME_HEAP_JIT_H_
#define NEXTAI_OPENCUT_LIBART_SYM_RUNTIME_HEAP_JIT_H_

#include <set>
#include <string>
#include "art_method_field_modifier.h"
#include "art_sym_types.h"

namespace art {

// ============================================================================
// 1. art::Heap — Moving GC Control & Android 5/6 Mutex Offset Discovery
//    Điều khiển bộ thu gom rác di chuyển (Moving GC) & Dò tìm Mutex trên Android 5/6
//    Addresses / Địa chỉ: 0x016144 .. 0x016a9f
// ============================================================================

/**
 * [EN] Size = 40 bytes (`0x28`):
 * - `+0x00`: vtable (`_ZTVN3art4HeapE + 0x10`)
 * - `+0x08`: `void* thiz_` (`ArtSymbolObject::thiz_`, pointer to `art::gc::Heap`)
 * - `+0x10`: `bool has_init_`
 * - `+0x11`: `bool init_success_`
 * - `+0x18`: `void* backtrace_lock_` (`art::Mutex*` discovered on API <= 23)
 * - `+0x20`: `void* gc_complete_lock_` (`art::Mutex*` discovered on API <= 23)
 *
 * [VN] Kích thước = 40 byte (`0x28`):
 * - `+0x00`: vtable (`_ZTVN3art4HeapE + 0x10`)
 * - `+0x08`: `void* thiz_` (`ArtSymbolObject::thiz_`, con trỏ tới `art::gc::Heap`)
 * - `+0x10`: `bool has_init_`
 * - `+0x11`: `bool init_success_`
 * - `+0x18`: `void* backtrace_lock_` (`art::Mutex*` dò tìm trên API <= 23)
 * - `+0x20`: `void* gc_complete_lock_` (`art::Mutex*` dò tìm trên API <= 23)
 */
class Heap : public ArtSymbolObject {
 public:
  // [0x016144] Initializes Heap wrapper (`has_init_ = false, init_success_ = false`)
  explicit Heap(void* obj) noexcept;

  // [0x016178] Returns true if android_get_device_api_level() <= 23
  static bool UseCompatGCSection() noexcept;

  // [0x016194] Initializes Heap symbol offsets:
  // - On API <= 23: scans `thiz_` for `min_alloc_space_size_for_sticky_mark_sweep_`
  //   (`== 3 * getpagesize()`), reads `"dalvik.vm.heapsize"` & `"dalvik.vm.heapgrowthlimit"`
  //   (parsing megabyte integer and shifting left by 20 bits `<< 0x14`), and locates
  //   `backtrace_lock_` (+0x18) and `gc_complete_lock_` (+0x20) by checking `_ZTVN3art5MutexE + 0x10`.
  // - On API 24..25: checks `_ZN3art2gc23ScopedGCCriticalSectionC2EPNS_6ThreadENS0_7GcCauseENS0_13CollectorTypeE`.
  // - On API >= 26: checks `IncrementDisableMovingGC` and `DecrementDisableMovingGC`.
  bool Init() noexcept;

  // [0x016668] Returns true if `thiz_ != nullptr && Init()`
  bool IsValid() noexcept override;

  // [0x016694] Calls `_ZN3art2gc4Heap24IncrementDisableMovingGCEPNS_6ThreadE`
  void IncrementDisableMovingGC(ArtThread* self) noexcept;

  // [0x016734] Calls `_ZN3art2gc4Heap24DecrementDisableMovingGCEPNS_6ThreadE`
  void DecrementDisableMovingGC(ArtThread* self) noexcept;

  void* GetBacktraceLock() const noexcept { return backtrace_lock_; }
  void* GetGcCompleteLock() const noexcept { return gc_complete_lock_; }

 private:
  bool has_init_;           // +0x10
  bool init_success_;       // +0x11
  void* backtrace_lock_;    // +0x18
  void* gc_complete_lock_;  // +0x20
};

// ============================================================================
// 2. art::instrumentation::ArtInstrumentation & InstrumentationStackPopper
//    Hệ thống kiểm soát Instrumentation & Gỡ khung ngăn xếp Instrumentation
//    Addresses / Địa chỉ: 0x016aa0 .. 0x01734f
// ============================================================================

namespace instrumentation {

class ArtInstrumentation : public ArtSymbolObject {
 public:
  explicit ArtInstrumentation(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x016aa0] Calls `_ZNK3art15instrumentation15Instrumentation21HaveExitStubInstalledEv` (API <= 29)
  bool HaveExitStubInstalled() noexcept;

  // [0x016b40] Calls `Instrumentation::DisableMethodTracing(const char*, bool)`
  void DisableMethodTracing(const char* key, bool Flush) noexcept;

  // [0x016be8] Calls `Instrumentation::EnableMethodTracing(const char*, bool, bool)` (API <= 30 vs >= 31)
  void EnableMethodTracing(const char* key, bool needs_interpreter) noexcept;

  // [0x016cf4] Calls `_ZN3art15instrumentation15Instrumentation12InstrumentThreadStackEPNS_6ThreadE` (API >= 31)
  void InstrumentThreadStack(ArtThread* thread) noexcept;

  // [0x016d88] Calls `Instrumentation::InitializeMethodsCode(ArtMethod*, const void*)`
  // or `UpdateMethodsCodeImpl(ArtMethod*, const void*)` across API levels
  void InitializeOrUpdateMethodsCode(ArtMethod* method, const void* quick_code) noexcept;

  // [0x016ec8] Returns true if `IsDeoptimized(ArtMethod*)` symbol exists
  bool SupportIsDeoptimized() noexcept;

  // [0x016f14] Calls `_ZNK3art15instrumentation15Instrumentation13IsDeoptimizedEPNS_9ArtMethodE`
  bool IsDeoptimized(ArtMethod* method) noexcept;

  // [0x016fb0] Calls `_ZN3art15instrumentation15Instrumentation21DisableDeoptimizationEPKc`
  bool DisableDeoptimization(const char* key) noexcept;

  // [0x017068] Calls `_ZN3art15instrumentation15Instrumentation11UndeoptimizeEPNS_9ArtMethodE`
  bool Undeoptimize(ArtMethod* method) noexcept;

  // [0x017120] Calls `_ZN3art15instrumentation15Instrumentation16UninstrumentMethodsEPKc`
  bool UninstrumentMethods(const char* key) noexcept;
};

}  // namespace instrumentation

/**
 * [EN] Inherits from `StackVisitor` (`0x210 = 528 bytes`: `StackVisitor` base at
 * `+0x00..+0x207`, `std::set<jmethodID>* methods_to_pop_` at `+0x208`).
 * Walks all thread stacks and replaces `art_quick_instrumentation_exit` return PCs
 * if any method in `methods_to_pop_` is present on the stack.
 *
 * [VN] Kế thừa từ `StackVisitor` (`0x210 = 528 byte`: lớp cơ sở `StackVisitor` tại
 * `+0x00..+0x207`, con trỏ `std::set<jmethodID>* methods_to_pop_` tại `+0x208`).
 * Duyệt ngăn xếp luồng để gỡ các khung cài đặt `art_quick_instrumentation_exit`.
 * Addresses / Địa chỉ: 0x0171dc .. 0x01734f
 */
class InstrumentationStackPopper : public StackVisitor {
 public:
  // [0x0171dc] Constructs popper for `thread` and `methods`
  InstrumentationStackPopper(ArtThread* thread, const std::set<jmethodID>& methods) noexcept;

  // [0x017230] Visits current frame, reads ArtMethod* at +0x18 (or +0x10), and checks membership in `methods_`
  bool VisitFrame() override;

  // [0x0172b8] Walks stack if HaveExitStubInstalled() is true; if matched, invokes
  // `_ZN3art15instrumentation15Instrumentation24PopFramesForDeoptimizationEPNS_6ThreadE`
  void PopFramesIfNeeded() noexcept;

 private:
  const std::set<jmethodID>* methods_;  // +0x208
};

// ============================================================================
// 3. art::jit::Jit, JitOptions, JitCodeCache (0x017350..0x0179e7, 0x01a9b0..0x01ab87)
//    Hệ thống quản lý biên dịch động JIT và Bộ nhớ đệm mã máy JIT
// ============================================================================

namespace jit {

class JitOptions : public ArtSymbolObject {
 public:
  JitOptions() noexcept : ArtSymbolObject(nullptr) {}
  explicit JitOptions(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x01898c] Validates whether `thiz_` points to a valid `art::jit::JitOptions`
  // by checking `compile_threshold_` (16-bit or 32-bit word):
  // - API 29 (Android 10 Q): expects `0x2720` (`10016`)
  // - API 30 (Android 11 R): expects `0x2800` (`10240`)
  // - API >= 31 (Android 12+ S/T): expects `0x2800` (`10240`) or `0xffff` (`65535`)
  bool IsValid() noexcept override;

  // [0x018a60] Sets `use_jit_compilation_` / `use_tiered_jit_compilation_`
  void SetUseJitCompilation(bool enabled) noexcept;
};

class JitCodeCache : public ArtSymbolObject {
 public:
  JitCodeCache() noexcept : ArtSymbolObject(nullptr) {}
  explicit JitCodeCache(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x01a9b0] Calls `_ZN3art3jit12JitCodeCache19InvalidateAllMethodsEv` or
  // `_ZN3art3jit12JitCodeCache24NotifyMethodRedefinedEPNS_9ArtMethodE`
  void ClearPreCompiledMethods(const std::set<jmethodID>& methods, bool invalidate_all) noexcept;

  // [0x01aad0] Calls `_ZN3art3jit12JitCodeCache27SetGarbageCollectCodeEb`
  bool SetGarbageCollectCode(bool enabled) noexcept;
};

class Jit : public ArtSymbolObject {
 public:
  Jit() noexcept : ArtSymbolObject(nullptr) {}
  explicit Jit(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x017350] Checks whether `StopThreadPool` and `StartThreadPool` exist
  bool SupportStopAndStartThreadPool() noexcept;

  // [0x0173c4] Calls `_ZN3art3jit3Jit14StopThreadPoolEv`
  void StopThreadPool() noexcept;

  // [0x017440] Calls `_ZN3art3jit3Jit15StartThreadPoolEv`
  void StartThreadPool() noexcept;

  // [0x0174bc] Calls `_ZN3art3jit3Jit16DeleteThreadPoolEv`
  void DeleteThreadPool() noexcept;

  // [0x017538] Calls `_ZN3art3jit3Jit16CreateThreadPoolEv`
  void CreateThreadPool() noexcept;

  // [0x0175b4] Calls `Jit::CompileMethod(ArtMethod*, Thread*, bool, bool, bool)` across API 24..34
  bool CompileMethod(ArtMethod* method, ArtThread* self, bool baseline, bool osr) noexcept;

  // [0x017930] Calls `_ZN3art3jit3Jit27WaitForCompilationToFinishEPNS_6ThreadE`
  bool WaitForCompilationToFinish(ArtThread* self) noexcept;
};

}  // namespace jit

// ============================================================================
// 4. art::ReaderWriterMutex, ReaderWriterMutexMock, and art::Locks
//    Hệ thống Khóa Đọc-Ghi (ReaderWriterMutex) và Bảng Khóa Toàn Cục (art::Locks)
//    Addresses / Địa chỉ: 0x017ae0 .. 0x01871b
// ============================================================================

class ReaderWriterMutex : public ArtSymbolObject {
 public:
  ReaderWriterMutex() noexcept : ArtSymbolObject(nullptr) {}
  explicit ReaderWriterMutex(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x017ae0] Calls `_ZN3art17ReaderWriterMutex13ExclusiveLockEPNS_6ThreadE`
  void ExclusiveLock(ArtThread* self) noexcept;

  // [0x017b7c] Calls `_ZN3art17ReaderWriterMutex15ExclusiveUnlockEPNS_6ThreadE`
  void ExclusiveUnlock(ArtThread* self) noexcept;

  // [0x017c18] Calls `_ZN3art17ReaderWriterMutex10SharedLockEPNS_6ThreadE`
  void SharedLock(ArtThread* self) noexcept;

  // [0x017cf4] Calls `_ZN3art17ReaderWriterMutex12SharedUnlockEPNS_6ThreadE`
  void SharedUnlock(ArtThread* self) noexcept;

  // [0x017dd0] Calls `_ZN3art17ReaderWriterMutex13SharedTryLockEPNS_6ThreadE`
  bool SharedTryLock(ArtThread* self) noexcept;

  // [0x017e70] Detects exact byte/word size of `art::ReaderWriterMutex` via `DetectObjectSizeWithPointerAlign`
  static size_t Size() noexcept;
};

class ReaderWriterMutexMock : public ReaderWriterMutex {
 public:
  // [0x017f18] Allocates a mock buffer filled with `fill_byte` (`0x12` or `0x24`),
  // calls `_ZN3art17ReaderWriterMutexC2EPKcNS_9LockLevelE("mock mutex", 0)`,
  // and locates the `name_` pointer slot matching `"mock mutex"`
  explicit ReaderWriterMutexMock(int fill_byte) noexcept;

  // [0x01800c] Destructor: frees mock buffer
  ~ReaderWriterMutexMock() noexcept override;

  // [0x018054] Returns true if `state_index_ >= 0 && contender_index_ >= 0`
  bool IsValid() noexcept override;

  // [0x018080] Probes `state_` and `num_contenders_` offsets by calling `SharedTryLock` / `SharedUnlock`
  bool InitIndex(ArtThread* self) noexcept;

  int32_t GetNameIndex() const noexcept { return name_index_; }
  int32_t GetStateIndex() const noexcept { return state_index_; }
  int32_t GetContenderIndex() const noexcept { return contender_index_; }

 private:
  int32_t name_index_;       // +0x10
  int32_t state_index_;      // +0x14
  int32_t contender_index_;  // +0x18
};

class Locks {
 public:
  // [0x018150] Resolves `mutator_lock_` (`_ZN3art5Locks13mutator_lock_E`),
  // `heap_bitmap_lock_` (`_ZN3art5Locks17heap_bitmap_lock_E`),
  // `classlinker_classes_lock_` (`_ZN3art5Locks25classlinker_classes_lock_E`),
  // `jit_lock_` (`_ZN3art5Locks9jit_lock_E`), etc., or scans adjacent globals if hidden
  static bool Init(ArtThread* self) noexcept;

  // [0x01856c] Checks if `candidate` matches a `ReaderWriterMutex` whose `name_` equals `expected_name`
  static bool CheckMutex(void* candidate, const ReaderWriterMutexMock& mock,
                         const char* expected_name) noexcept;

  // [0x018634] Returns `mutator_lock_` wrapper
  static ReaderWriterMutex* GetMutatorLock() noexcept;

  // [0x018668] Returns `jit_lock_` wrapper
  static ReaderWriterMutex* GetJitLock() noexcept;

  // [0x01869c] Returns `heap_bitmap_lock_` wrapper
  static ReaderWriterMutex* GetHeapBitmapLock() noexcept;

  // [0x0186d0] Returns `classlinker_classes_lock_` wrapper
  static ReaderWriterMutex* GetClassLinkerClassesLock() noexcept;
};

// ============================================================================
// 5. art::ArtRuntime — Central ART `Runtime::instance_` Member Offset Engine
//    Bộ máy dò tìm tự động toàn bộ trường thành viên của `art::Runtime::instance_`
//    Addresses / Địa chỉ: 0x01871c .. 0x01a18b
// ============================================================================

/**
 * [EN] Size = 152 bytes (`0x98` in `.bss 0x026248`):
 * - `+0x00`: vtable (`_ZTVN3art10ArtRuntimeE + 0x10`)
 * - `+0x08`: `void* thiz_` (`_ZN3art7Runtime9instance_E`)
 * - `+0x10`: `bool has_init_`
 * - `+0x14`: `int32_t callee_save_methods_index_`
 * - `+0x18`: `int32_t pre_allocated_OutOfMemoryError_index_`
 * - `+0x1c`: `int32_t resolution_method_index_`
 * - `+0x20`: `int32_t imt_conflict_method_index_`
 * - `+0x24`: `int32_t imt_unimplemented_method_index_`
 * - `+0x28`: `int32_t sentinel_index_`
 * - `+0x2c`: `int32_t instruction_set_index_`
 * - `+0x30`: `int32_t compiler_callbacks_index_`
 * - `+0x34`: `int32_t is_zygote_index_`
 * - `+0x38`: `int32_t must_relocate_index_`
 * - `+0x3c`: `int32_t is_concurrent_gc_enabled_index_`
 * - `+0x40`: `int32_t is_explicit_gc_disabled_index_`
 * - `+0x44`: `int32_t dex2oat_enabled_index_`
 * - `+0x48`: `int32_t image_dex2oat_enabled_index_`
 * - `+0x50`: `std::string compiler_executable_` (24 bytes)
 * - `+0x68`: `int32_t heap_index_`
 * - `+0x6c`: `int32_t thread_list_index_`
 * - `+0x70`: `int32_t intern_table_index_`
 * - `+0x74`: `int32_t class_linker_index_`
 * - `+0x78`: `int32_t signal_catcher_index_`
 * - `+0x7c`: `int32_t java_vm_index_`
 * - `+0x80`: `int32_t jit_index_`
 * - `+0x84`: `int32_t jit_code_cache_index_`
 * - `+0x88`: `int32_t jit_options_index_`
 * - `+0x8c`: `int32_t instrumentation_index_`
 * - `+0x90`: `int32_t main_thread_group_index_`
 *
 * [VN] Kích thước = 152 byte (`0x98` tại `.bss 0x026248`), lưu giữ toàn bộ chỉ số
 * offset của các thành phần bên trong đối tượng `art::Runtime::instance_`.
 */
class ArtRuntime : public ArtSymbolObject {
 public:
  // [0x018a90] Initializes all member indices to -1 and resolves `_ZN3art7Runtime9instance_E`
  ArtRuntime() noexcept;

  // [0x018818] Returns Meyer's singleton `ArtRuntime` instance (`.bss 0x026248`)
  static ArtRuntime* Get() noexcept;

  // [0x018bd4] Discovers all `Runtime` member indices (`java_vm_index_`, `class_linker_index_`,
  // `thread_list_index_`, `intern_table_index_`, `heap_index_`, `jit_index_`, `jit_code_cache_index_`,
  // `jit_options_index_`, `instrumentation_index_`) usingJNIEnv/JavaVM anchors and vtable probes
  bool Init(JNIEnv* env) noexcept;

  // [0x01955c] Calls `_ZN3art7Runtime22CreateResolutionMethodEv`
  jmethodID CreateResolutionMethod() noexcept;

  // [0x01960c] Calls `_ZN3art7Runtime13AppendToBootClassPathEPKcS2_...`
  void AppendToBootClassPath(const char* filename, const char* location) noexcept;

  // [0x01972c] Returns `ArtClassLinker` wrapper for `thiz_[class_linker_index_]`
  ArtClassLinker GetClassLinker() const noexcept;

  // [0x0197c8] Returns `ArtInstrumentation` wrapper for `thiz_ + instrumentation_index_`
  instrumentation::ArtInstrumentation GetInstrumentation() const noexcept;

  // [0x019888] Returns `jit::Jit` wrapper for `thiz_[jit_index_]`
  jit::Jit GetJit() const noexcept;

  // [0x019950] Returns `jit::JitCodeCache` wrapper for `thiz_[jit_code_cache_index_]`
  jit::JitCodeCache GetJitCodeCache() const noexcept;

  // [0x019a0c] Returns `jit::JitOptions` wrapper for `thiz_[jit_options_index_]`
  jit::JitOptions GetJitOptions() const noexcept;

  // [0x019ac8] Returns `ThreadList*` pointer at `thiz_[thread_list_index_]`
  void* GetThreadList() const noexcept;

  // [0x019b7c] Returns `Heap` wrapper for `thiz_[heap_index_]`
  Heap GetHeap() const noexcept;

  // [0x019c40] Returns `JavaVMExt*` pointer at `thiz_[java_vm_index_]`
  void* GetJavaVM() const noexcept;

  // [0x019cc0] Sets `jit_options_` compilation flag or clears `jit_`
  void DisableJit() noexcept;

 private:
  bool has_init_;                           // +0x10
  int32_t callee_save_methods_index_;       // +0x14
  int32_t pre_allocated_oom_index_;         // +0x18
  int32_t resolution_method_index_;         // +0x1c
  int32_t imt_conflict_method_index_;       // +0x20
  int32_t imt_unimplemented_method_index_;  // +0x24
  int32_t sentinel_index_;                  // +0x28
  int32_t instruction_set_index_;           // +0x2c
  int32_t compiler_callbacks_index_;        // +0x30
  int32_t is_zygote_index_;                 // +0x34
  int32_t must_relocate_index_;             // +0x38
  int32_t is_concurrent_gc_enabled_index_;  // +0x3c
  int32_t is_explicit_gc_disabled_index_;   // +0x40
  int32_t dex2oat_enabled_index_;           // +0x44
  int32_t image_dex2oat_enabled_index_;     // +0x48
  std::string compiler_executable_;         // +0x50 .. +0x67
  int32_t heap_index_;                      // +0x68
  int32_t thread_list_index_;               // +0x6c
  int32_t intern_table_index_;              // +0x70
  int32_t class_linker_index_;              // +0x74
  int32_t signal_catcher_index_;            // +0x78
  int32_t java_vm_index_;                   // +0x7c
  int32_t jit_index_;                       // +0x80
  int32_t jit_code_cache_index_;            // +0x84
  int32_t jit_options_index_;               // +0x88
  int32_t instrumentation_index_;           // +0x8c
  int32_t main_thread_group_index_;         // +0x90
};

}  // namespace art

#endif  // NEXTAI_OPENCUT_LIBART_SYM_RUNTIME_HEAP_JIT_H_
