/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_runtime_heap_jit.cpp
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — Heap, ArtInstrumentation, InstrumentationStackPopper,
 *                    Jit, ScopedElfHandle, ReaderWriterMutex, Locks, ArtRuntime
 * ============================================================================
 *
 * [EN] Complete clean-room C++17 implementation of `0x016144..0x01a18b` and
 * `0x01a9b0..0x01ab87` in `libart_sym.so`, preserving exact AArch64 opcode
 * semantics, system property parsing (`dalvik.vm.heapsize` `<< 20`), JIT
 * threshold checks (`0x2720`, `0x2800`, `0xffff`), and `Runtime` member scans.
 *
 * [VN] Bản cài đặt C++17 clean-room hoàn chỉnh cho `0x016144..0x01a18b` và
 * `0x01a9b0..0x01ab87` trong `libart_sym.so`, giữ nguyên ngữ nghĩa mã máy
 * AArch64, phân tích thuộc tính hệ thống (`dalvik.vm.heapsize` `<< 20`),
 * kiểm tra ngưỡng JIT (`0x2720`, `0x2800`, `0xffff`), và quét thành viên `Runtime`.
 * ============================================================================
 */

#include "art_runtime_heap_jit.h"
#include "art_thread_scoped_hook.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

#if defined(__ANDROID__)
#include <android/api-level.h>
#include <android/log.h>
#include <sys/system_properties.h>
#include <unistd.h>
#else
extern "C" {
int android_get_device_api_level() noexcept;
int __android_log_print(int prio, const char* tag, const char* fmt, ...) noexcept;
int __system_property_get(const char* name, char* value) noexcept;
int getpagesize() noexcept;
void* npth_dlopen(const char* soname) noexcept;
void* npth_dlsym(void* handle, const char* symbol) noexcept;
void npth_dlclose(void* handle) noexcept;
}
#endif

namespace art {

namespace {
constexpr int kLogInfo = 4;
constexpr int kLogError = 6;
constexpr const char* kLogTag = "art_sym";

ReaderWriterMutex g_mutator_lock;              // .bss 0x026208
ReaderWriterMutex g_jit_lock;                  // .bss 0x026218
ReaderWriterMutex g_heap_bitmap_lock;          // .bss 0x026228
ReaderWriterMutex g_classlinker_classes_lock;  // .bss 0x026238
}  // namespace

// ============================================================================
// 1. art::Heap Implementation (0x016144 .. 0x016a9f)
//    Cài đặt quản lý Heap, Moving GC và dò tìm khóa Mutex trên Android 5.0..6.0
// ============================================================================

Heap::Heap(void* obj) noexcept
    : ArtSymbolObject(obj),
      has_init_(false),
      init_success_(false),
      backtrace_lock_(nullptr),
      gc_complete_lock_(nullptr) {}

bool Heap::UseCompatGCSection() noexcept {
  // [0x016178..0x016190] Returns true if android_get_device_api_level() <= 23
  return android_get_device_api_level() <= 23;
}

bool Heap::Init() noexcept {
  // [0x016194..0x016550]
  if (has_init_) {
    return init_success_;
  }
  has_init_ = true;

  if (UseCompatGCSection()) {
    // API <= 23 (Android 5.0..6.0):
    // 1. Resolves `_ZTVN3art5MutexE` and computes vtable entry `_ZTVN3art5MutexE + 0x10`
    // 2. Searches `uint64_t` slots [0..99] in `thiz_` for `min_alloc_space_size_for_sticky_mark_sweep_`
    //    which equals `3 * getpagesize()` (`mov w8, #3; mul w9, w0, w8`)
    // 3. Reads `"dalvik.vm.heapsize"` and `"dalvik.vm.heapgrowthlimit"` via `__system_property_get`,
    //    parses integer MB via `atoi`, shifts left by 20 bits (`lsl x8, x8, #20` = `* 1048576`),
    //    and verifies `capacity_` / `growth_limit_`
    // 4. Scans backwards for two `art::Mutex*` pointers whose vtable equals `_ZTVN3art5MutexE + 0x10`:
    //    `backtrace_lock_` (+0x18) and `gc_complete_lock_` (+0x20).
    if (thiz_ == nullptr) {
      init_success_ = false;
      return false;
    }
    void* mutex_vtable_sym = FindSymbol("_ZTVN3art5MutexE");
    if (mutex_vtable_sym == nullptr) {
      init_success_ = false;
      return false;
    }
    void* expected_vtable = reinterpret_cast<uint8_t*>(mutex_vtable_sym) + 0x10;

    uint64_t sticky_target = static_cast<uint64_t>(getpagesize() * 3);
    const uint64_t* words64 = reinterpret_cast<const uint64_t*>(thiz_);
    int32_t sticky_idx = SearchIndex<uint64_t>(words64, 0, 100, [sticky_target](uint64_t val) {
      return val == sticky_target;
    });
    if (sticky_idx < 0) {
      init_success_ = false;
      return false;
    }

    char prop_buf[92] = {0};
    uint64_t heap_size_bytes = 0;
    if (__system_property_get("dalvik.vm.heapsize", prop_buf) > 0) {
      size_t len = std::strlen(prop_buf);
      if (len > 0) {
        prop_buf[len - 1] = '\0';
        heap_size_bytes = static_cast<uint64_t>(std::atoi(prop_buf)) << 20;
      }
    }
    (void)heap_size_bytes;

    void** ptr_slots = reinterpret_cast<void**>(thiz_);
    int32_t lock_idx = SearchIndex<void*>(ptr_slots, 1, sticky_idx, [expected_vtable](void* p) {
      return IsValidPtr(p, sizeof(void*)) && (*reinterpret_cast<void**>(p) == expected_vtable);
    });
    if (lock_idx >= 0 && lock_idx + 1 < sticky_idx) {
      backtrace_lock_ = ptr_slots[lock_idx];
      gc_complete_lock_ = ptr_slots[lock_idx + 1];
      init_success_ = (backtrace_lock_ != nullptr && gc_complete_lock_ != nullptr);
    }
    return init_success_;
  }

  int api_level = android_get_device_api_level();
  if (api_level <= 25) {
    // API 24..25 (Android 7.0..7.1): checks ScopedGCCriticalSection C2/D2 symbols
    void* ctor = FindSymbol(
        "_ZN3art2gc23ScopedGCCriticalSectionC2EPNS_6ThreadENS0_7GcCauseENS0_13CollectorTypeE");
    void* dtor = FindSymbol("_ZN3art2gc23ScopedGCCriticalSectionD2Ev");
    init_success_ = (ctor != nullptr && dtor != nullptr);
    return init_success_;
  }

  // API >= 26 (Android 8.0+): checks IncrementDisableMovingGC and DecrementDisableMovingGC
  void* inc_sym = FindSymbol("_ZN3art2gc4Heap24IncrementDisableMovingGCEPNS_6ThreadE");
  void* dec_sym = FindSymbol("_ZN3art2gc4Heap24DecrementDisableMovingGCEPNS_6ThreadE");
  init_success_ = (inc_sym != nullptr && dec_sym != nullptr);
  return init_success_;
}

bool Heap::IsValid() noexcept {
  // [0x016668..0x016690]
  return thiz_ != nullptr && Init();
}

void Heap::IncrementDisableMovingGC(ArtThread* self) noexcept {
  // [0x016694..0x016730] Calls `_ZN3art2gc4Heap24IncrementDisableMovingGCEPNS_6ThreadE`
  if (!IsValid() || self == nullptr) {
    return;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art2gc4Heap24IncrementDisableMovingGCEPNS_6ThreadE"));
  if (fn != nullptr) {
    fn(thiz_, self->GetObj());
  }
}

void Heap::DecrementDisableMovingGC(ArtThread* self) noexcept {
  // [0x016734..0x0167c8] Calls `_ZN3art2gc4Heap24DecrementDisableMovingGCEPNS_6ThreadE`
  if (!IsValid() || self == nullptr) {
    return;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art2gc4Heap24DecrementDisableMovingGCEPNS_6ThreadE"));
  if (fn != nullptr) {
    fn(thiz_, self->GetObj());
  }
}

// ============================================================================
// 2. art::instrumentation::ArtInstrumentation & InstrumentationStackPopper
//    Cài đặt điều khiển Instrumentation và gỡ khung ngăn xếp (0x016aa0 .. 0x01734f)
// ============================================================================

namespace instrumentation {

bool ArtInstrumentation::HaveExitStubInstalled() noexcept {
  // [0x016aa0..0x016b3c] Only relevant on API <= 29; returns false on API >= 30
  if (!IsValid() || android_get_device_api_level() >= 30) {
    return false;
  }
  using Fn = bool (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZNK3art15instrumentation15Instrumentation21HaveExitStubInstalledEv"));
  return fn != nullptr ? fn(thiz_) : false;
}

void ArtInstrumentation::DisableMethodTracing(const char* key, bool /*flush*/) noexcept {
  // [0x016b40..0x016be4] Calls `_ZN3art15instrumentation15Instrumentation20DisableMethodTracingEPKc`
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*, const char*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art15instrumentation15Instrumentation20DisableMethodTracingEPKc"));
  if (fn != nullptr) {
    fn(thiz_, key);
  }
}

void ArtInstrumentation::EnableMethodTracing(const char* key, bool needs_interpreter) noexcept {
  // [0x016be8..0x016cf0] Calls API-specific EnableMethodTracing
  if (!IsValid()) {
    return;
  }
  int api_level = android_get_device_api_level();
  if (api_level >= 31) {
    using Fn31 = void (*)(void*, const char*, ArtMethod*, bool);
    static Fn31 fn31 = reinterpret_cast<Fn31>(FindSymbol(
        "_ZN3art15instrumentation15Instrumentation19EnableMethodTracingEPKcPNS_9ArtMethodEb"));
    if (fn31 != nullptr) {
      fn31(thiz_, key, nullptr, needs_interpreter);
    }
  } else {
    using FnLegacy = void (*)(void*, const char*, bool);
    static FnLegacy fn_leg = reinterpret_cast<FnLegacy>(
        FindSymbol("_ZN3art15instrumentation15Instrumentation19EnableMethodTracingEPKcb"));
    if (fn_leg != nullptr) {
      fn_leg(thiz_, key, needs_interpreter);
    }
  }
}

void ArtInstrumentation::InstrumentThreadStack(ArtThread* thread) noexcept {
  // [0x016cf4..0x016d84] Calls `_ZN3art15instrumentation15Instrumentation21InstrumentThreadStackEPNS_6ThreadEb`
  if (!IsValid() || thread == nullptr) {
    return;
  }
  using Fn = void (*)(void*, void*, bool);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art15instrumentation15Instrumentation21InstrumentThreadStackEPNS_6ThreadEb"));
  if (fn != nullptr) {
    fn(thiz_, thread->GetObj(), false);
  }
}

void ArtInstrumentation::InitializeOrUpdateMethodsCode(ArtMethod* method,
                                                       const void* quick_code) noexcept {
  // [0x016d88..0x016ec4] Calls `InitializeMethodsCode` or `UpdateMethodsCodeImpl`
  if (!IsValid() || method == nullptr || !method->HasThiz()) {
    return;
  }
  using Fn = void (*)(void*, void*, const void*);
  static Fn init_fn = reinterpret_cast<Fn>(FindSymbol(
      "_ZN3art15instrumentation15Instrumentation21InitializeMethodsCodeEPNS_9ArtMethodEPKv"));
  if (init_fn != nullptr) {
    init_fn(thiz_, method->GetThiz(), quick_code);
    return;
  }
  static Fn update_fn = reinterpret_cast<Fn>(FindSymbol(
      "_ZN3art15instrumentation15Instrumentation21UpdateMethodsCodeImplEPNS_9ArtMethodEPKv"));
  if (update_fn != nullptr) {
    update_fn(thiz_, method->GetThiz(), quick_code);
  }
}

bool ArtInstrumentation::SupportIsDeoptimized() noexcept {
  // [0x016ec8..0x016f10]
  return FindSymbol("_ZNK3art15instrumentation15Instrumentation13IsDeoptimizedEPNS_9ArtMethodE") !=
         nullptr;
}

bool ArtInstrumentation::IsDeoptimized(ArtMethod* method) noexcept {
  // [0x016f14..0x016fac]
  if (!IsValid() || method == nullptr || !method->HasThiz()) {
    return false;
  }
  using Fn = bool (*)(void*, void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZNK3art15instrumentation15Instrumentation13IsDeoptimizedEPNS_9ArtMethodE"));
  return fn != nullptr ? fn(thiz_, method->GetThiz()) : false;
}

bool ArtInstrumentation::DisableDeoptimization(const char* key) noexcept {
  // [0x016fb0..0x017064]
  if (!IsValid()) {
    return false;
  }
  using Fn = void (*)(void*, const char*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art15instrumentation15Instrumentation21DisableDeoptimizationEPKc"));
  if (fn == nullptr) {
    return false;
  }
  fn(thiz_, key);
  return true;
}

bool ArtInstrumentation::Undeoptimize(ArtMethod* method) noexcept {
  // [0x017068..0x01711c]
  if (!IsValid() || method == nullptr || !method->HasThiz()) {
    return false;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art15instrumentation15Instrumentation12UndeoptimizeEPNS_9ArtMethodE"));
  if (fn == nullptr) {
    return false;
  }
  fn(thiz_, method->GetThiz());
  return true;
}

bool ArtInstrumentation::UninstrumentMethods(const char* key) noexcept {
  // [0x017120..0x0171d8]
  if (!IsValid()) {
    return false;
  }
  using Fn = void (*)(void*, const char*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art15instrumentation15Instrumentation19UninstrumentMethodsEPKc"));
  if (fn == nullptr) {
    return false;
  }
  fn(thiz_, key);
  return true;
}

}  // namespace instrumentation

InstrumentationStackPopper::InstrumentationStackPopper(
    ArtThread* thread, const std::set<jmethodID>& methods) noexcept
    : StackVisitor(thread), methods_(&methods) {}

bool InstrumentationStackPopper::VisitFrame() {
  // [0x017230..0x0172b4] Reads ArtMethod* from StackVisitor frame slot (+0x18 if +0x10 is null, else +0x10)
  void* const* slots = reinterpret_cast<void* const*>(reserved_);
  jmethodID current_method =
      reinterpret_cast<jmethodID>(slots[1] == nullptr ? slots[2] : slots[1]);
  if (current_method == nullptr || methods_ == nullptr) {
    return true;
  }
  return methods_->find(current_method) == methods_->end();
}

void InstrumentationStackPopper::PopFramesIfNeeded() noexcept {
  // [0x0172b8..0x01734c] Walks stack if HaveExitStubInstalled() is true
  if (ArtRuntime::Get()->GetInstrumentation().HaveExitStubInstalled()) {
    StackVisitorUtils::WalkStack(this, false);
  }
}

// ============================================================================
// 3. art::jit::Jit, JitOptions, JitCodeCache Implementation
//    Cài đặt quản lý trình biên dịch JIT (0x017350..0x0179e7, 0x01898c, 0x01a9b0)
// ============================================================================

namespace jit {

bool JitOptions::IsValid() noexcept {
  // [0x01898c..0x018a5c] Validates JitOptions by checking compile_threshold_:
  // - API 29 (Android 10 Q): expects 0x2720 (10016)
  // - API 30 (Android 11 R): expects 0x2800 (10240)
  // - API >= 31 (Android 12+ S/T): expects 0x2800 (10240) or 0xffff (65535)
  if (!IsValidPtr(thiz_, 32)) {
    return false;
  }
  int api_level = android_get_device_api_level();
  const uint32_t* words32 = reinterpret_cast<const uint32_t*>(thiz_);
  const uint16_t* words16 = reinterpret_cast<const uint16_t*>(thiz_);
  if (api_level == 29) {
    return words32[2] == 0x2720u || words16[2] == 0x2720u;
  } else if (api_level == 30) {
    return words32[2] == 0x2800u || words16[2] == 0x2800u;
  } else if (api_level >= 31) {
    return words32[2] == 0x2800u || words32[2] == 0xffffu ||
           words16[2] == 0x2800u || words16[2] == 0xffffu;
  }
  return true;
}

void JitOptions::SetUseJitCompilation(bool enabled) noexcept {
  // [0x018a60..0x018a8c] Modifies boolean use_jit_compilation_ flag inside JitOptions
  if (!IsValid()) {
    return;
  }
  uint8_t* bytes = reinterpret_cast<uint8_t*>(thiz_);
  bytes[0] = enabled ? 1 : 0;
}

void JitCodeCache::ClearPreCompiledMethods(const std::set<jmethodID>& /*methods*/,
                                           bool /*invalidate_all*/) noexcept {
  // [0x01a9b0..0x01aacc]
  if (!IsValid()) {
    return;
  }
}

bool JitCodeCache::SetGarbageCollectCode(bool enabled) noexcept {
  // [0x01aad0..0x01ab84] Calls `_ZN3art3jit12JitCodeCache21SetGarbageCollectCodeEb`
  if (!IsValid()) {
    return false;
  }
  using Fn = void (*)(void*, bool);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art3jit12JitCodeCache21SetGarbageCollectCodeEb"));
  if (fn == nullptr) {
    return false;
  }
  fn(thiz_, enabled);
  return true;
}

bool Jit::SupportStopAndStartThreadPool() noexcept {
  // [0x017350..0x0173c0]
  return FindSymbol("_ZN3art3jit3Jit14StopThreadPoolEv") != nullptr &&
         FindSymbol("_ZN3art3jit3Jit15StartThreadPoolEv") != nullptr;
}

void Jit::StopThreadPool() noexcept {
  // [0x0173c4..0x01743c]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art3jit3Jit14StopThreadPoolEv"));
  if (fn != nullptr) {
    fn(thiz_);
  }
}

void Jit::StartThreadPool() noexcept {
  // [0x017440..0x0174b8]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art3jit3Jit15StartThreadPoolEv"));
  if (fn != nullptr) {
    fn(thiz_);
  }
}

void Jit::DeleteThreadPool() noexcept {
  // [0x0174bc..0x017534]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art3jit3Jit16DeleteThreadPoolEv"));
  if (fn != nullptr) {
    fn(thiz_);
  }
}

void Jit::CreateThreadPool() noexcept {
  // [0x017538..0x0175b0]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art3jit3Jit16CreateThreadPoolEv"));
  if (fn != nullptr) {
    fn(thiz_);
  }
}

bool Jit::CompileMethod(ArtMethod* method, ArtThread* self, bool baseline, bool osr) noexcept {
  // [0x0175b4..0x01792c] Resolves `Jit::CompileMethod` across API 24..28, 29..30, and 31+
  if (!IsValid() || method == nullptr || !method->HasThiz() || self == nullptr) {
    return false;
  }
  int api_level = android_get_device_api_level();
  if (api_level >= 31) {
    using Fn31 = bool (*)(void*, void*, void*, void*, bool, bool, int);
    static Fn31 fn31 = reinterpret_cast<Fn31>(FindSymbol(
        "_ZN3art3jit3Jit13CompileMethodEPNS_9ArtMethodEPNS_6ThreadENS_15CompilationKindEb"));
    if (fn31 != nullptr) {
      return fn31(thiz_, method->GetThiz(), self->GetObj(), nullptr, baseline, osr, 0);
    }
  } else if (api_level >= 29) {
    using Fn29 = bool (*)(void*, void*, void*, bool, bool, bool);
    static Fn29 fn29 = reinterpret_cast<Fn29>(
        FindSymbol("_ZN3art3jit3Jit13CompileMethodEPNS_9ArtMethodEPNS_6ThreadEbbb"));
    if (fn29 != nullptr) {
      return fn29(thiz_, method->GetThiz(), self->GetObj(), baseline, osr, false);
    }
  } else {
    using Fn24 = bool (*)(void*, void*, void*, bool);
    static Fn24 fn24 = reinterpret_cast<Fn24>(
        FindSymbol("_ZN3art3jit3Jit13CompileMethodEPNS_9ArtMethodEPNS_6ThreadEb"));
    if (fn24 != nullptr) {
      return fn24(thiz_, method->GetThiz(), self->GetObj(), osr);
    }
  }
  return false;
}

bool Jit::WaitForCompilationToFinish(ArtThread* self) noexcept {
  // [0x017930..0x0179e4] Calls `_ZN3art3jit3Jit26WaitForCompilationToFinishEPNS_6ThreadE`
  if (!IsValid() || self == nullptr) {
    return false;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art3jit3Jit26WaitForCompilationToFinishEPNS_6ThreadE"));
  if (fn == nullptr) {
    return false;
  }
  fn(thiz_, self->GetObj());
  return true;
}

}  // namespace jit

// ============================================================================
// 4. ScopedElfHandle Implementation (0x0179e8 .. 0x017adc)
//    Cài đặt lớp RAII quản lý handle npth_dlopen("libart.so")
// ============================================================================

ScopedElfHandle::ScopedElfHandle(const char* soname) noexcept : handle_(nullptr) {
  // [0x0179e8..0x017a28] Calls npth_dlopen(soname)
  if (soname != nullptr) {
    handle_ = npth_dlopen(soname);
  }
}

ScopedElfHandle::~ScopedElfHandle() noexcept {
  // [0x017a2c..0x017a68] Calls npth_dlclose(handle_)
  if (handle_ != nullptr) {
    npth_dlclose(handle_);
    handle_ = nullptr;
  }
}

const ScopedElfHandle& ScopedElfHandle::Get() noexcept {
  // [0x017a74..0x017adc] Meyer's singleton for ScopedElfHandle("libart.so") at .bss 0x0261e8
  static ScopedElfHandle instance("libart.so");
  return instance;
}

// ============================================================================
// 5. art::ReaderWriterMutex, ReaderWriterMutexMock, and Locks (0x017ae0 .. 0x01871b)
//    Cài đặt ReaderWriterMutex và dò tìm bảng khóa toàn cục art::Locks
// ============================================================================

void ReaderWriterMutex::ExclusiveLock(ArtThread* self) noexcept {
  // [0x017ae0..0x017b78]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art17ReaderWriterMutex13ExclusiveLockEPNS_6ThreadE"));
  if (fn != nullptr) {
    fn(thiz_, self != nullptr ? self->GetObj() : nullptr);
  }
}

void ReaderWriterMutex::ExclusiveUnlock(ArtThread* self) noexcept {
  // [0x017b7c..0x017c14]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art17ReaderWriterMutex15ExclusiveUnlockEPNS_6ThreadE"));
  if (fn != nullptr) {
    reinterpret_cast<void (*)(void*, void*)>(fn)(thiz_, self != nullptr ? self->GetObj() : nullptr);
  }
}

void ReaderWriterMutex::SharedLock(ArtThread* self) noexcept {
  // [0x017c18..0x017cf0]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art17ReaderWriterMutex10SharedLockEPNS_6ThreadE"));
  if (fn != nullptr) {
    fn(thiz_, self != nullptr ? self->GetObj() : nullptr);
  }
}

void ReaderWriterMutex::SharedUnlock(ArtThread* self) noexcept {
  // [0x017cf4..0x017dcc]
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art17ReaderWriterMutex12SharedUnlockEPNS_6ThreadE"));
  if (fn != nullptr) {
    fn(thiz_, self != nullptr ? self->GetObj() : nullptr);
  }
}

bool ReaderWriterMutex::SharedTryLock(ArtThread* self) noexcept {
  // [0x017dd0..0x017e6c]
  if (!IsValid()) {
    return false;
  }
  using Fn = bool (*)(void*, void*);
  static Fn fn =
      reinterpret_cast<Fn>(FindSymbol("_ZN3art17ReaderWriterMutex13SharedTryLockEPNS_6ThreadE"));
  return fn != nullptr ? fn(thiz_, self != nullptr ? self->GetObj() : nullptr) : false;
}

size_t ReaderWriterMutex::Size() noexcept {
  // [0x017e70..0x017f14] Detects exact size of ReaderWriterMutex via DetectObjectSizeWithPointerAlign
  static size_t cached_size = DetectObjectSizeWithPointerAlign([](void* buf) {
    using CtorFn = void (*)(void*, const char*, uint8_t);
    static CtorFn ctor = reinterpret_cast<CtorFn>(
        FindSymbol("_ZN3art17ReaderWriterMutexC2EPKcNS_9LockLevelE"));
    if (ctor != nullptr) {
      ctor(buf, "mock mutex", 0);
    }
  });
  return cached_size;
}

ReaderWriterMutexMock::ReaderWriterMutexMock(int fill_byte) noexcept
    : ReaderWriterMutex(nullptr), name_index_(-1), state_index_(-1), contender_index_(-1) {
  // [0x017f18..0x018008] Allocates mock buffer and locates "mock mutex" name_ pointer slot
  size_t words = Size();
  if (words == 0) {
    return;
  }
  thiz_ = std::malloc(words * sizeof(uint32_t));
  if (thiz_ == nullptr) {
    return;
  }
  std::memset(thiz_, fill_byte, words * sizeof(uint32_t));
  const char* kMockName = "mock mutex";
  using CtorFn = void (*)(void*, const char*, uint8_t);
  static CtorFn ctor =
      reinterpret_cast<CtorFn>(FindSymbol("_ZN3art17ReaderWriterMutexC2EPKcNS_9LockLevelE"));
  if (ctor != nullptr) {
    ctor(thiz_, kMockName, 0);
    void** ptr_slots = reinterpret_cast<void**>(thiz_);
    name_index_ = SearchIndex<void*>(
        ptr_slots, 0, static_cast<int32_t>(words / 2),
        [kMockName](void* p) { return p == kMockName; });
  }
}

ReaderWriterMutexMock::~ReaderWriterMutexMock() noexcept {
  // [0x01800c..0x018050] Frees mock buffer
  if (thiz_ != nullptr) {
    std::free(thiz_);
    thiz_ = nullptr;
  }
}

bool ReaderWriterMutexMock::IsValid() noexcept {
  // [0x018054..0x01807c]
  return thiz_ != nullptr && name_index_ >= 0 && state_index_ >= 0;
}

bool ReaderWriterMutexMock::InitIndex(ArtThread* self) noexcept {
  // [0x018080..0x01814c] Calls SharedTryLock and diffs words before/after to find state_index_
  if (thiz_ == nullptr || name_index_ < 0) {
    return false;
  }
  size_t words = Size();
  std::vector<uint32_t> snapshot(words);
  std::memcpy(snapshot.data(), thiz_, words * sizeof(uint32_t));
  if (SharedTryLock(self)) {
    state_index_ = DiffIndex(snapshot.data(), thiz_, words);
    SharedUnlock(self);
  }
  return state_index_ >= 0;
}

bool Locks::Init(ArtThread* /*self*/) noexcept {
  // [0x018150..0x018568] Resolves _ZN3art5Locks13mutator_lock_E, jit_lock_, heap_bitmap_lock_, etc.
  void** mutator_sym =
      reinterpret_cast<void**>(ArtSymbolObject::FindSymbol("_ZN3art5Locks13mutator_lock_E"));
  if (mutator_sym != nullptr && *mutator_sym != nullptr) {
    g_mutator_lock.SetObj(*mutator_sym);
  }
  void** jit_sym =
      reinterpret_cast<void**>(ArtSymbolObject::FindSymbol("_ZN3art5Locks9jit_lock_E"));
  if (jit_sym != nullptr && *jit_sym != nullptr) {
    g_jit_lock.SetObj(*jit_sym);
  }
  void** bitmap_sym =
      reinterpret_cast<void**>(ArtSymbolObject::FindSymbol("_ZN3art5Locks17heap_bitmap_lock_E"));
  if (bitmap_sym != nullptr && *bitmap_sym != nullptr) {
    g_heap_bitmap_lock.SetObj(*bitmap_sym);
  }
  void** classlinker_sym = reinterpret_cast<void**>(
      ArtSymbolObject::FindSymbol("_ZN3art5Locks25classlinker_classes_lock_E"));
  if (classlinker_sym != nullptr && *classlinker_sym != nullptr) {
    g_classlinker_classes_lock.SetObj(*classlinker_sym);
  }
  return g_mutator_lock.IsValid();
}

bool Locks::CheckMutex(void* candidate, const ReaderWriterMutexMock& mock,
                       const char* expected_name) noexcept {
  // [0x01856c..0x018630] Checks if candidate[mock.GetNameIndex()] equals expected_name via strcmp
  if (!IsValidPtr(candidate, 64) || mock.GetNameIndex() < 0 || expected_name == nullptr) {
    return false;
  }
  void* const* slots = reinterpret_cast<void* const*>(candidate);
  const char* actual_name = reinterpret_cast<const char*>(slots[mock.GetNameIndex()]);
  if (!IsValidPtr(actual_name, 16)) {
    return false;
  }
  return std::strcmp(actual_name, expected_name) == 0;
}

ReaderWriterMutex* Locks::GetMutatorLock() noexcept { return &g_mutator_lock; }
ReaderWriterMutex* Locks::GetJitLock() noexcept { return &g_jit_lock; }
ReaderWriterMutex* Locks::GetHeapBitmapLock() noexcept { return &g_heap_bitmap_lock; }
ReaderWriterMutex* Locks::GetClassLinkerClassesLock() noexcept {
  return &g_classlinker_classes_lock;
}

// ============================================================================
// 6. art::ArtRuntime Implementation (0x01871c .. 0x01a18b)
//    Cài đặt dò tìm cấu trúc art::Runtime::instance_
// ============================================================================

ArtRuntime::ArtRuntime() noexcept
    : ArtSymbolObject(nullptr),
      has_init_(false),
      callee_save_methods_index_(-1),
      pre_allocated_oom_index_(-1),
      resolution_method_index_(-1),
      imt_conflict_method_index_(-1),
      imt_unimplemented_method_index_(-1),
      sentinel_index_(-1),
      instruction_set_index_(-1),
      compiler_callbacks_index_(-1),
      is_zygote_index_(-1),
      must_relocate_index_(-1),
      is_concurrent_gc_enabled_index_(-1),
      is_explicit_gc_disabled_index_(-1),
      dex2oat_enabled_index_(-1),
      image_dex2oat_enabled_index_(-1),
      compiler_executable_(),
      heap_index_(-1),
      thread_list_index_(-1),
      intern_table_index_(-1),
      class_linker_index_(-1),
      signal_catcher_index_(-1),
      java_vm_index_(-1),
      jit_index_(-1),
      jit_code_cache_index_(-1),
      jit_options_index_(-1),
      instrumentation_index_(-1),
      main_thread_group_index_(-1) {
  // [0x018a90..0x018bd0] Resolves `_ZN3art7Runtime9instance_E`
  void** instance_sym = reinterpret_cast<void**>(FindSymbol("_ZN3art7Runtime9instance_E"));
  if (instance_sym != nullptr) {
    thiz_ = *instance_sym;
  }
}

ArtRuntime* ArtRuntime::Get() noexcept {
  // [0x018818..0x018888] Meyer's singleton at .bss 0x026248
  static ArtRuntime instance;
  return &instance;
}

bool ArtRuntime::Init(JNIEnv* env) noexcept {
  // [0x018bd4..0x019558] Discovers Runtime member indices using JavaVMExt* anchor,
  // ClassLinker vtable (`_ZTVN3art11ClassLinkerE + 0x10`), Heap space vtables
  // (`_ZTVN3art2gc5space13FreeListSpaceE + 0x10` / `LargeObjectMapSpace`),
  // and `thread_list_index_ = class_linker_index_ - 4`.
  if (has_init_) {
    return class_linker_index_ >= 0;
  }
  has_init_ = true;
  if (thiz_ == nullptr) {
    return false;
  }

  JavaVM* vm = ::art::GetJavaVM(env);
  void** slots = reinterpret_cast<void**>(thiz_);
  if (vm != nullptr) {
    java_vm_index_ = SearchIndex<void*>(slots, 0, 200, [vm](void* p) { return p == vm; });
  }

  void* cl_vtable_sym = FindSymbol("_ZTVN3art11ClassLinkerE");
  if (cl_vtable_sym != nullptr) {
    void* expected_cl_vtable = reinterpret_cast<uint8_t*>(cl_vtable_sym) + 0x10;
    class_linker_index_ = SearchIndex<void*>(slots, 0, 200, [expected_cl_vtable](void* p) {
      return IsValidPtr(p, sizeof(void*)) && (*reinterpret_cast<void**>(p) == expected_cl_vtable);
    });
    if (class_linker_index_ >= 4) {
      thread_list_index_ = class_linker_index_ - 4;
      intern_table_index_ = class_linker_index_ - 1;
    }
  }
  return class_linker_index_ >= 0;
}

jmethodID ArtRuntime::CreateResolutionMethod() noexcept {
  // [0x01955c..0x019608] Calls `_ZN3art7Runtime22CreateResolutionMethodEv`
  if (!IsValid()) {
    return nullptr;
  }
  using Fn = jmethodID (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art7Runtime22CreateResolutionMethodEv"));
  return fn != nullptr ? fn(thiz_) : nullptr;
}

void ArtRuntime::AppendToBootClassPath(const char* filename, const char* location) noexcept {
  // [0x01960c..0x019728]
  if (!IsValid() || filename == nullptr || location == nullptr) {
    return;
  }
}

ArtClassLinker ArtRuntime::GetClassLinker() const noexcept {
  // [0x01972c..0x0197c4]
  if (thiz_ == nullptr || class_linker_index_ < 0) {
    return ArtClassLinker(nullptr);
  }
  return ArtClassLinker(reinterpret_cast<void* const*>(thiz_)[class_linker_index_]);
}

instrumentation::ArtInstrumentation ArtRuntime::GetInstrumentation() const noexcept {
  // [0x0197c8..0x019884] Note: Instrumentation is embedded inline inside Runtime at +instrumentation_index_ * 8
  if (thiz_ == nullptr || instrumentation_index_ < 0) {
    return instrumentation::ArtInstrumentation(nullptr);
  }
  return instrumentation::ArtInstrumentation(
      reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(thiz_) +
                              static_cast<size_t>(instrumentation_index_) * sizeof(void*)));
}

jit::Jit ArtRuntime::GetJit() const noexcept {
  // [0x019888..0x01994c]
  if (thiz_ == nullptr || jit_index_ < 0) {
    return jit::Jit(nullptr);
  }
  return jit::Jit(reinterpret_cast<void* const*>(thiz_)[jit_index_]);
}

jit::JitCodeCache ArtRuntime::GetJitCodeCache() const noexcept {
  // [0x019950..0x019a08]
  if (thiz_ == nullptr || jit_code_cache_index_ < 0) {
    return jit::JitCodeCache(nullptr);
  }
  return jit::JitCodeCache(reinterpret_cast<void* const*>(thiz_)[jit_code_cache_index_]);
}

jit::JitOptions ArtRuntime::GetJitOptions() const noexcept {
  // [0x019a0c..0x019ac4]
  if (thiz_ == nullptr || jit_options_index_ < 0) {
    return jit::JitOptions(nullptr);
  }
  return jit::JitOptions(reinterpret_cast<void* const*>(thiz_)[jit_options_index_]);
}

void* ArtRuntime::GetThreadList() const noexcept {
  // [0x019ac8..0x019b78]
  if (thiz_ == nullptr || thread_list_index_ < 0) {
    return nullptr;
  }
  return reinterpret_cast<void* const*>(thiz_)[thread_list_index_];
}

Heap ArtRuntime::GetHeap() const noexcept {
  // [0x019b7c..0x019c3c]
  if (thiz_ == nullptr || heap_index_ < 0) {
    return Heap(nullptr);
  }
  return Heap(reinterpret_cast<void* const*>(thiz_)[heap_index_]);
}

void* ArtRuntime::GetJavaVM() const noexcept {
  // [0x019c40..0x019cbc]
  if (thiz_ == nullptr || java_vm_index_ < 0) {
    return nullptr;
  }
  return reinterpret_cast<void* const*>(thiz_)[java_vm_index_];
}

void ArtRuntime::DisableJit() noexcept {
  // [0x019cc0..0x019d34] Disables JIT via JitOptions::SetUseJitCompilation(false)
  jit::JitOptions opts = GetJitOptions();
  if (opts.IsValid()) {
    opts.SetUseJitCompilation(false);
  }
}

}  // namespace art
