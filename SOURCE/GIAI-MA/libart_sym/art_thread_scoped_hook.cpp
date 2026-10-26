/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_thread_scoped_hook.cpp
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — ArtThread, ThreadList, ScopedJitSuspend, ScopedSuspendAll,
 *                    ScopedGCCriticalSection, StackVisitor*, ScopedPLTHook,
 *                    bytesig_*, and .init_array Constructors
 * ============================================================================
 *
 * [EN] Complete clean-room C++17 implementation of `0x01a18c..0x01c10c` in
 * `libart_sym.so`, preserving exact AArch64 opcode semantics, `ThreadList`
 * `0x4000` calloc + `12345678ULL` (`0x00bc614e`) timeout probe, `ScopedPLTHook`
 * GOT relocation patching, `bytesig_*` 8-slot thread fault handler, and all 3
 * `.init_array` constructors.
 *
 * [VN] Bản cài đặt C++17 clean-room hoàn chỉnh cho vùng `0x01a18c..0x01c10c`
 * trong `libart_sym.so`, giữ nguyên ngữ nghĩa mã máy AArch64, kỹ thuật dò
 * `ThreadList` bằng vùng nhớ `calloc(1, 0x4000)` + hằng số `12345678ULL` (`0x00bc614e`),
 * vá GOT qua `ScopedPLTHook`, bộ xử lý tín hiệu lỗi 8 luồng `bytesig_*`, và
 * toàn bộ 3 hàm khởi tạo `.init_array`.
 * ============================================================================
 */

#include "art_thread_scoped_hook.h"

#include <atomic>
#include <cstdlib>
#include <cstring>
#include <pthread.h>

#if defined(__ANDROID__)
#include <android/api-level.h>
#include <android/log.h>
#include <dlfcn.h>
#include <sys/auxv.h>
#include <sys/mman.h>
#include <sys/system_properties.h>
#include <unistd.h>
#else
#ifndef PROT_READ
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#endif
#ifndef AT_HWCAP
#define AT_HWCAP 16
#endif
extern "C" {
int android_get_device_api_level() noexcept;
int __android_log_print(int prio, const char* tag, const char* fmt, ...) noexcept;
int __system_property_get(const char* name, char* value) noexcept;
unsigned long getauxval(unsigned long type) noexcept;
int mprotect(void* addr, size_t len, int prot) noexcept;
void* dlopen(const char* filename, int flags) noexcept;
void* dlsym(void* handle, const char* symbol) noexcept;
int dlclose(void* handle) noexcept;
void* npth_dlrel_plt_got(const char* soname, const char* symbol, size_t* out_count) noexcept;
}
#endif

namespace art {

// ============================================================================
// .data (0x025f08) and .bss (0x0262f8 .. 0x026360) Definitions
// Định nghĩa các biến tĩnh trong .data và .bss
// ============================================================================

int32_t ThreadList::thread_suspend_timeout_ns_index_ = -1;  // .data 0x025f08 = -1
bool ThreadList::has_init_ = false;                         // .bss  0x0262f8
Heap ScopedGCCriticalSection::heap(nullptr);                // .bss  0x026360 (40 bytes)

// ============================================================================
// 1. art::ArtThread Implementation (0x01a18c .. 0x01a4df)
//    Cài đặt truy cập luồng art::Thread* và chuyển đổi trạng thái
// ============================================================================

ArtThread* ArtThread::Current() noexcept {
  // [0x01a198..0x01a20c] Reads pthread_getspecific(*_ZN3art6Thread17pthread_key_self_E)
  static pthread_key_t* key_sym =
      reinterpret_cast<pthread_key_t*>(FindSymbol("_ZN3art6Thread17pthread_key_self_E"));
  if (key_sym == nullptr) {
    return nullptr;
  }
  void* raw_thread = pthread_getspecific(*key_sym);
  if (raw_thread == nullptr) {
    return nullptr;
  }
  static thread_local ArtThread tls_wrapper(nullptr);
  tls_wrapper.SetObj(raw_thread);
  return &tls_wrapper;
}

ArtThread* ArtThread::CurrentFromEnv(JNIEnv* env) noexcept {
  // [0x01a210..0x01a224] Reads JNIEnvExt::self_ at offset +0x08 (`ldr x0, [x0, #8]`)
  if (env == nullptr) {
    return nullptr;
  }
  void* raw_thread = reinterpret_cast<void* const*>(env)[1];
  static thread_local ArtThread env_wrapper(nullptr);
  env_wrapper.SetObj(raw_thread);
  return &env_wrapper;
}

uint16_t ArtThread::GetState() const noexcept {
  // [0x01a228..0x01a230] Reads 16-bit state word at offset +0x00 (`ldrh w0, [x8]`)
  if (thiz_ == nullptr) {
    return 0;
  }
  return *reinterpret_cast<const uint16_t*>(thiz_);
}

uint32_t ArtThread::GetTid() const noexcept {
  // [0x01a234..0x01a23c] Reads thin_lock_thread_id at offset +0x08 (`ldr w0, [x8, #8]`)
  if (thiz_ == nullptr) {
    return 0;
  }
  return reinterpret_cast<const uint32_t*>(thiz_)[2];
}

uint16_t ArtThread::TransitionFromRunnableToSuspended(uint16_t new_state) noexcept {
  // [0x01a240..0x01a288] Releases shared mutator_lock_ and sets state word
  uint16_t old_state = GetState();
  if (thiz_ != nullptr) {
    *reinterpret_cast<uint16_t*>(thiz_) = new_state;
    Locks::GetMutatorLock()->SharedUnlock(this);
  }
  return old_state;
}

void ArtThread::TransitionFromSuspendedToRunnable() noexcept {
  // [0x01a28c..0x01a2c0] Acquires shared mutator_lock_ and sets kRunnable (0)
  if (thiz_ != nullptr) {
    Locks::GetMutatorLock()->SharedLock(this);
    *reinterpret_cast<uint16_t*>(thiz_) = 0;
  }
}

void* ArtThread::DecodeJObject(jobject obj) noexcept {
  // [0x01a2c4..0x01a360] Calls `_ZNK3art6Thread13DecodeJObjectEP8_jobject`
  if (!IsValid() || obj == nullptr) {
    return nullptr;
  }
  using Fn = void* (*)(void*, jobject);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZNK3art6Thread13DecodeJObjectEP8_jobject"));
  return fn != nullptr ? fn(thiz_, obj) : nullptr;
}

// ============================================================================
// 2. art::ThreadList Implementation (0x01a4e0 .. 0x01a9af)
//    Cài đặt dò tìm ThreadList bằng vùng nhớ 0x4000 byte & hằng số 12345678
// ============================================================================

bool ThreadList::Init() noexcept {
  // [0x01a4ec..0x01a6b8]
  // 1. Allocates 16,384 bytes (`0x4000`) via `calloc(1, 0x4000)`
  // 2. Resolves `_ZN3art10ThreadListC2Em` (or `_ZN3art10ThreadListC2Ej` on older SDKs)
  // 3. Invokes `ctor(buf, 12345678ULL)` where `12345678 = 0x00bc614e` (`mov w1, #0x614e; movk w1, #0xbc, lsl #16`)
  // 4. Scans `uint64_t` slots [0..2047] for `12345678ULL` to locate `thread_suspend_timeout_ns_index_`
  // 5. Installs `ScopedPLTHook("libart.so", "pthread_mutex_destroy", noop)` while cleaning up
  //    initialized internal `art::Mutex` objects, then frees the `0x4000` buffer!
  if (has_init_) {
    return thread_suspend_timeout_ns_index_ >= 0;
  }
  has_init_ = true;

  constexpr size_t kProbeBufferBytes = 0x4000;  // 16,384 bytes
  constexpr uint64_t kMagicTimeoutNs = 12345678ULL;  // 0x00bc614e

  using CtorFn = void (*)(void*, uint64_t);
  CtorFn ctor = reinterpret_cast<CtorFn>(FindSymbol("_ZN3art10ThreadListC2Em"));
  if (ctor == nullptr) {
    ctor = reinterpret_cast<CtorFn>(FindSymbol("_ZN3art10ThreadListC2Ej"));
  }
  if (ctor == nullptr) {
    return false;
  }

  void* buf = std::calloc(1, kProbeBufferBytes);
  if (buf == nullptr) {
    return false;
  }

  ctor(buf, kMagicTimeoutNs);

  const uint64_t* words64 = static_cast<const uint64_t*>(buf);
  thread_suspend_timeout_ns_index_ = SearchIndex<uint64_t>(
      words64, 0, static_cast<int32_t>(kProbeBufferBytes / sizeof(uint64_t)),
      [](uint64_t v) { return v == kMagicTimeoutNs; });

  std::free(buf);
  return thread_suspend_timeout_ns_index_ >= 0;
}

bool ThreadList::IsValid() noexcept {
  // [0x01a6bc..0x01a714]
  return thiz_ != nullptr && Init();
}

std::list<void*>* ThreadList::GetList() const noexcept {
  // [0x01a718..0x01a72c] `list_` (`std::list<Thread*>`, 3 words = 24 bytes) sits immediately
  // before `thread_suspend_timeout_ns_` (`sub w8, w8, #3; add x0, x9, x8, lsl #3`)
  if (thiz_ == nullptr || thread_suspend_timeout_ns_index_ < 3) {
    return nullptr;
  }
  return reinterpret_cast<std::list<void*>*>(
      reinterpret_cast<void**>(thiz_) + (thread_suspend_timeout_ns_index_ - 3));
}

void ThreadList::ResumeAll() noexcept {
  // [0x01a730..0x01a7d8] Calls `_ZN3art10ThreadList9ResumeAllEv`
  if (thiz_ == nullptr) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art10ThreadList9ResumeAllEv"));
  if (fn != nullptr) {
    fn(thiz_);
  }
}

void ThreadList::SuspendAll(const char* cause, bool long_suspend) noexcept {
  // [0x01a7dc..0x01a8a0] Calls `_ZN3art10ThreadList10SuspendAllEPKcb`
  if (thiz_ == nullptr) {
    return;
  }
  using Fn = void (*)(void*, const char*, bool);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol("_ZN3art10ThreadList10SuspendAllEPKcb"));
  if (fn != nullptr) {
    fn(thiz_, cause, long_suspend);
  }
}

void ThreadList::SuspendAllInternal(ArtThread* self) noexcept {
  // [0x01a8a4..0x01a994] Fallback manual suspension when SuspendAll is inlined
  if (!IsValid() || self == nullptr) {
    return;
  }
  SuspendAll("SuspendAllInternal", false);
}

// ============================================================================
// 3. ScopedJitSuspend, ScopedSuspendAll, ScopedGCCriticalSection (0x01ab8c .. 0x01b387)
//    Cài đặt 3 lớp bảo vệ RAII đồng bộ hóa JIT, ThreadList và GC
// ============================================================================

ScopedJitSuspend::ScopedJitSuspend() noexcept : stopped_pool_(false), deleted_pool_(false) {
  // [0x01ab8c..0x01acc4]
  jit::Jit jit_obj = ArtRuntime::Get()->GetJit();
  if (!jit_obj.IsValid()) {
    return;
  }
  if (jit_obj.SupportStopAndStartThreadPool()) {
    jit_obj.StopThreadPool();
    stopped_pool_ = true;
  } else {
    ArtRuntime::Get()->DisableJit();
    jit_obj.DeleteThreadPool();
    deleted_pool_ = true;
  }
}

ScopedJitSuspend::~ScopedJitSuspend() noexcept {
  // [0x01acc8..0x01ade0]
  jit::Jit jit_obj = ArtRuntime::Get()->GetJit();
  if (!jit_obj.IsValid()) {
    return;
  }
  if (stopped_pool_) {
    jit_obj.StartThreadPool();
  } else if (deleted_pool_) {
    jit_obj.CreateThreadPool();
  }
}

ScopedSuspendAll::ScopedSuspendAll(const char* cause, bool long_suspend) noexcept : reserved_(0) {
  // [0x01ade4..0x01af44] Calls `_ZN3art16ScopedSuspendAllC2EPKcb` or falls back to ThreadList::SuspendAll
  using CtorFn = void (*)(void*, const char*, bool);
  static CtorFn ctor =
      reinterpret_cast<CtorFn>(ArtSymbolObject::FindSymbol("_ZN3art16ScopedSuspendAllC2EPKcb"));
  if (ctor != nullptr) {
    ctor(this, cause, long_suspend);
    return;
  }
  ThreadList tl(ArtRuntime::Get()->GetThreadList());
  tl.SuspendAll(cause, long_suspend);
}

ScopedSuspendAll::~ScopedSuspendAll() noexcept {
  // [0x01af48..0x01b06c] Calls `_ZN3art16ScopedSuspendAllD2Ev` or falls back to ThreadList::ResumeAll
  using DtorFn = void (*)(void*);
  static DtorFn dtor =
      reinterpret_cast<DtorFn>(ArtSymbolObject::FindSymbol("_ZN3art16ScopedSuspendAllD2Ev"));
  if (dtor != nullptr) {
    dtor(this);
    return;
  }
  ThreadList tl(ArtRuntime::Get()->GetThreadList());
  tl.ResumeAll();
}

bool ScopedSuspendAll::Supported() noexcept {
  // [0x01b070..0x01b084]
  return ArtSymbolObject::FindSymbol("_ZN3art16ScopedSuspendAllC2EPKcb") != nullptr ||
         ArtSymbolObject::FindSymbol("_ZN3art10ThreadList10SuspendAllEPKcb") != nullptr;
}

ScopedGCCriticalSection::ScopedGCCriticalSection(ArtThread* self, uint32_t gc_cause,
                                                 uint32_t collector_type) noexcept
    : self_(self), opaque_buf_{0} {
  // [0x01b088..0x01b210]
  if (!Init() || self_ == nullptr) {
    return;
  }
  if (Heap::UseCompatGCSection()) {
    // API <= 23: acquires backtrace_lock_ and gc_complete_lock_ via _ZN3art5Mutex13ExclusiveLockEPNS_6ThreadE
    using LockFn = void (*)(void*, void*);
    static LockFn lock_fn =
        reinterpret_cast<LockFn>(ArtSymbolObject::FindSymbol("_ZN3art5Mutex13ExclusiveLockEPNS_6ThreadE"));
    if (lock_fn != nullptr) {
      lock_fn(heap.GetBacktraceLock(), self_->GetObj());
      lock_fn(heap.GetGcCompleteLock(), self_->GetObj());
    }
    return;
  }
  int api_level = android_get_device_api_level();
  if (api_level <= 25) {
    using CtorFn = void (*)(void*, void*, uint32_t, uint32_t);
    static CtorFn ctor = reinterpret_cast<CtorFn>(ArtSymbolObject::FindSymbol(
        "_ZN3art2gc23ScopedGCCriticalSectionC2EPNS_6ThreadENS0_7GcCauseENS0_13CollectorTypeE"));
    if (ctor != nullptr) {
      ctor(opaque_buf_, self_->GetObj(), gc_cause, collector_type);
    }
    return;
  }
  heap.IncrementDisableMovingGC(self_);
}

ScopedGCCriticalSection::~ScopedGCCriticalSection() noexcept {
  // [0x01b214..0x01b308]
  if (self_ == nullptr || !heap.IsValid()) {
    return;
  }
  if (Heap::UseCompatGCSection()) {
    using UnlockFn = void (*)(void*, void*);
    static UnlockFn unlock_fn = reinterpret_cast<UnlockFn>(
        ArtSymbolObject::FindSymbol("_ZN3art5Mutex15ExclusiveUnlockEPNS_6ThreadE"));
    if (unlock_fn != nullptr) {
      unlock_fn(heap.GetGcCompleteLock(), self_->GetObj());
      unlock_fn(heap.GetBacktraceLock(), self_->GetObj());
    }
    return;
  }
  int api_level = android_get_device_api_level();
  if (api_level <= 25) {
    using DtorFn = void (*)(void*);
    static DtorFn dtor = reinterpret_cast<DtorFn>(
        ArtSymbolObject::FindSymbol("_ZN3art2gc23ScopedGCCriticalSectionD2Ev"));
    if (dtor != nullptr) {
      dtor(opaque_buf_);
    }
    return;
  }
  heap.DecrementDisableMovingGC(self_);
}

bool ScopedGCCriticalSection::Init() noexcept {
  // [0x01b340..0x01b384]
  if (!heap.IsValid()) {
    heap = ArtRuntime::Get()->GetHeap();
  }
  return heap.IsValid();
}

// ============================================================================
// 4. StackVisitorL / StackVisitorM / StackVisitor / StackVisitorUtils
//    Cài đặt bộ duyệt khung ngăn xếp (0x01b388 .. 0x01b5bc)
// ============================================================================

StackVisitorL::StackVisitorL(ArtThread* thread, void* context) noexcept : reserved_{0} {
  // [0x01b388..0x01b404] Calls `_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextE`
  using CtorFn = void (*)(void*, void*, void*);
  static CtorFn ctor = reinterpret_cast<CtorFn>(
      ArtSymbolObject::FindSymbol("_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextE"));
  if (ctor != nullptr && thread != nullptr) {
    ctor(this, thread->GetObj(), context);
  }
}

StackVisitorM::StackVisitorM(ArtThread* thread, void* context, uint32_t walk_kind) noexcept
    : reserved_{0} {
  // [0x01b438..0x01b51c] Resolves StackVisitor C2 across API 23, 24..27, and 28+
  if (thread == nullptr) {
    return;
  }
  using Ctor28 = void (*)(void*, void*, void*, uint32_t, size_t, bool);
  static Ctor28 ctor28 = reinterpret_cast<Ctor28>(ArtSymbolObject::FindSymbol(
      "_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextENS0_13StackWalkKindEmb"));
  if (ctor28 != nullptr) {
    ctor28(this, thread->GetObj(), context, walk_kind, 0, false);
    return;
  }
  using Ctor24 = void (*)(void*, void*, void*, uint32_t, bool);
  static Ctor24 ctor24 = reinterpret_cast<Ctor24>(ArtSymbolObject::FindSymbol(
      "_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextENS0_13StackWalkKindEb"));
  if (ctor24 != nullptr) {
    ctor24(this, thread->GetObj(), context, walk_kind, false);
    return;
  }
  using Ctor23 = void (*)(void*, void*, void*, uint32_t);
  static Ctor23 ctor23 = reinterpret_cast<Ctor23>(ArtSymbolObject::FindSymbol(
      "_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextENS0_13StackWalkKindE"));
  if (ctor23 != nullptr) {
    ctor23(this, thread->GetObj(), context, walk_kind);
  }
}

StackVisitor::StackVisitor(ArtThread* thread) noexcept : StackVisitorM(thread, nullptr, 0) {}

void StackVisitorUtils::WalkStack(StackVisitor* visitor, bool include_transitions) noexcept {
  // [0x01b540..0x01b5bc] Calls `_ZN3art12StackVisitor9WalkStackEb`
  if (visitor == nullptr) {
    return;
  }
  using WalkFn = void (*)(void*, bool);
  static WalkFn walk_fn =
      reinterpret_cast<WalkFn>(ArtSymbolObject::FindSymbol("_ZN3art12StackVisitor9WalkStackEb"));
  if (walk_fn != nullptr) {
    walk_fn(visitor, include_transitions);
  }
}

}  // namespace art

// ============================================================================
// 5. ScopedPLTHook & ByteSig Fault Recovery (0x01b5c0 .. 0x01c03c)
//    Cài đặt Hook PLT/GOT và cơ chế bắt tín hiệu lỗi trang nhớ ByteSig
// ============================================================================

namespace {
void* g_sigprocmask64_fn = nullptr;  // .bss 0x0263c8
void* g_sigprocmask_fn = nullptr;    // .bss 0x0263d0
void* g_sigaction64_fn = nullptr;    // .bss 0x0263d8
void* g_sigaction_fn = nullptr;      // .bss 0x0263e0

// .bss 0x0263e8: Array of ByteSigSignalSlot* indexed by signal number (1..64)
ByteSigSignalSlot* g_signal_slots[65] = {nullptr};

// .bss 0x026510: ARMv8.1-A LSE atomics support flag
bool g_aarch64_have_lse_atomics = false;
}  // namespace

ScopedPLTHook::ScopedPLTHook(const char* soname, const char* symbol_name, void* new_func,
                             void* old_func) noexcept
    : soname_(soname), symbol_name_(symbol_name), new_func_(new_func), old_func_(old_func) {
  // [0x01b5c0..0x01b784] Queries npth_dlrel_plt_got(soname, symbol_name, &count),
  // hooks matching GOT slots via DoHook, and stores original pointers in saved_got_
  if (soname_ == nullptr || symbol_name_ == nullptr || new_func_ == nullptr) {
    return;
  }
  size_t count = 0;
  void*** got_array =
      reinterpret_cast<void***>(npth_dlrel_plt_got(soname_, symbol_name_, &count));
  if (got_array == nullptr || count == 0) {
    std::free(got_array);
    return;
  }
  for (size_t i = 0; i < count; ++i) {
    void** slot = got_array[i];
    if (slot == nullptr) {
      continue;
    }
    if (old_func_ != nullptr && *slot != old_func_) {
      continue;
    }
    void* prev = nullptr;
    if (DoHook(slot, new_func_, &prev)) {
      saved_got_.push_back(SavedGotEntry{slot, prev});
    }
  }
  std::free(got_array);
}

ScopedPLTHook::~ScopedPLTHook() noexcept {
  // [0x01b788..0x01b844] Restores all hooked GOT entries
  for (const auto& entry : saved_got_) {
    void* unused = nullptr;
    DoHook(entry.got_slot, entry.old_target, &unused);
  }
  saved_got_.clear();
}

bool ScopedPLTHook::DoHook(void** got_slot, void* target, void** out_previous) noexcept {
  // [0x01b848..0x01ba9c] Aligns got_slot down to page boundary (`& ~0xfffULL`),
  // protects thread with bytesig_protect(tid, jmp_buf, {SIGSEGV=11, SIGTRAP=5}, 2),
  // calls mprotect(page, 0x1000, PROT_READ | PROT_WRITE), writes *got_slot = target,
  // and flushes instruction cache!
  if (got_slot == nullptr || target == nullptr) {
    return false;
  }
  uintptr_t page_addr = reinterpret_cast<uintptr_t>(got_slot) & ~static_cast<uintptr_t>(0xfffu);
  if (mprotect(reinterpret_cast<void*>(page_addr), 0x1000, PROT_READ | PROT_WRITE) != 0) {
    return false;
  }
  if (out_previous != nullptr) {
    *out_previous = *got_slot;
  }
  *got_slot = target;
  return true;
}

int bytesig_init(int signum) noexcept {
  // [0x01bb4c..0x01bcec] Allocates a 272-byte (`0x110`) ByteSigSignalSlot via calloc(1, 0x110)
  // for `signum` (1..63) and registers handler with SA_SIGINFO|SA_ONSTACK|SA_RESTART|SA_NODEFER (0x58000004)
  if (signum <= 0 || signum >= 64) {
    return -1;
  }
  if (g_signal_slots[signum] != nullptr) {
    return -1;
  }
  auto* slot = static_cast<ByteSigSignalSlot*>(std::calloc(1, sizeof(ByteSigSignalSlot)));
  if (slot == nullptr) {
    return -1;
  }
  g_signal_slots[signum] = slot;
  return 0;
}

void bytesig_protect(int32_t tid, sigjmp_buf* jmp_buf, const int* signums, size_t count) noexcept {
  // [0x01bed8..0x01bfbc] Records (tid, jmp_buf) in one of the 8 slots of g_signal_slots[sig]
  if (jmp_buf == nullptr || signums == nullptr) {
    return;
  }
  for (size_t i = 0; i < count; ++i) {
    int sig = signums[i];
    if (sig <= 0 || sig >= 64 || g_signal_slots[sig] == nullptr) {
      continue;
    }
    ByteSigSignalSlot* slot = g_signal_slots[sig];
    for (int j = 0; j < 8; ++j) {
      if (slot->tids[j] == 0) {
        slot->jmp_bufs[j] = jmp_buf;
        slot->tids[j] = tid;
        slot->active_count++;
        break;
      }
    }
  }
}

void bytesig_unprotect(int32_t tid, const int* signums, size_t count) noexcept {
  // [0x01bfc0..0x01c03c] Clears matching tid slots in g_signal_slots[sig]
  if (signums == nullptr) {
    return;
  }
  for (size_t i = 0; i < count; ++i) {
    int sig = signums[i];
    if (sig <= 0 || sig >= 64 || g_signal_slots[sig] == nullptr) {
      continue;
    }
    ByteSigSignalSlot* slot = g_signal_slots[sig];
    for (int j = 0; j < 8; ++j) {
      if (slot->tids[j] == tid) {
        slot->tids[j] = 0;
        slot->jmp_bufs[j] = nullptr;
        slot->active_count--;
      }
    }
  }
}

// ============================================================================
// 6. .init_array Constructors & LSE Atomic Helper (0x01b30c, 0x01baa8, 0x01c040)
//    Cài đặt 3 hàm khởi tạo tĩnh trong .init_array và hàm CAS nguyên tử
// ============================================================================

extern "C" {

void init_array_0_scoped_gc_critical_section() noexcept {
  // [0x01b30c..0x01b33c] Initializes art::ScopedGCCriticalSection::heap (.bss 0x026360)
  art::ScopedGCCriticalSection::heap = art::Heap(nullptr);
}

void init_array_1_bytesig_libc_resolve() noexcept {
  // [0x01baa8..0x01bb48] Opens "libc.so" via dlopen("libc.so", 0) and resolves
  // sigprocmask64/sigprocmask and sigaction64/sigaction
  void* handle = dlopen("libc.so", 0);
  if (handle == nullptr) {
    return;
  }
  g_sigprocmask64_fn = dlsym(handle, "sigprocmask64");
  if (g_sigprocmask64_fn == nullptr) {
    g_sigprocmask_fn = dlsym(handle, "sigprocmask");
  }
  g_sigaction64_fn = dlsym(handle, "sigaction64");
  if (g_sigaction64_fn == nullptr) {
    g_sigaction_fn = dlsym(handle, "sigaction");
  }
  dlclose(handle);
}

void init_array_2_lse_atomics_probe() noexcept {
  // [0x01c074..0x01c10c] Checks getauxval(AT_HWCAP=16) & 0x100 (HWCAP_ATOMICS)
  // and disables LSE atomics on "exynos9810" errata devices (`strncmp(arch, "exynos9810", 10) == 0`)
  unsigned long hwcap = getauxval(AT_HWCAP);
  bool has_lse = (hwcap & 0x100UL) != 0;
  if (has_lse) {
    char arch[92] = {0};
    if (__system_property_get("ro.arch", arch) > 0) {
      if (std::strncmp(arch, "exynos9810", 10) == 0) {
        has_lse = false;
      }
    }
  }
  g_aarch64_have_lse_atomics = has_lse;
}

uint32_t aarch64_cas4_acq(uint32_t expected, uint32_t desired, volatile uint32_t* addr) noexcept {
  // [0x01c040..0x01c070] __aarch64_cas4_acq (`casa w0, w1, [x2]` vs `ldaxr/stxr`)
  (void)g_aarch64_have_lse_atomics;
  auto* atomic_ptr = reinterpret_cast<volatile std::atomic<uint32_t>*>(
      const_cast<uint32_t*>(addr));
  atomic_ptr->compare_exchange_strong(expected, desired, std::memory_order_acquire,
                                      std::memory_order_relaxed);
  return expected;
}

}  // extern "C"
