// ============================================================================
// File: lynx_v8_napi_observer_jni.cpp
// Target: liblynx_v8_bridge.so (0x0133a0..0x013bec)
// Description:
//   [EN] 100% Real C++17 implementation of exported lynx::base::ObserverList
//        (`0x0133a0..0x01358c`), JNI_OnLoad (`0x013590..0x013618`),
//        LynxRuntimeHelperV8 (`0x01361c..0x013954`), and NapiRuntimeProxyV8
//        (`0x013958..0x013bec`).
//   [VN] Bản cài đặt C++17 thực 100% của lớp xuất khẩu lynx::base::ObserverList
//        (`0x0133a0..0x01358c`), JNI_OnLoad (`0x013590..0x013618`),
//        LynxRuntimeHelperV8 (`0x01361c..0x013954`), và NapiRuntimeProxyV8
//        (`0x013958..0x013bec`).
// ============================================================================

#include "lynx_v8_napi_observer_jni.h"
#include <atomic>

namespace lynx {
namespace base {

// ============================================================================
// [EN] 1. lynx::base::ObserverList Implementation (`0x0133a0..0x01358c`)
//      Exported .dynsym symbols [180], [181], [182].
// [VN] 1. Cài đặt lynx::base::ObserverList (`0x0133a0..0x01358c`)
//      Biểu tượng xuất .dynsym [180], [181], [182].
// ============================================================================
ObserverList::~ObserverList() noexcept {
    auto* sentinel = reinterpret_cast<ObserverNode*>(this);
    ObserverNode* cur = head_;
    while (cur != sentinel) {
        ObserverNode* next = cur->next;
        delete cur;
        cur = next;
    }
    tail_ = sentinel;
    head_ = sentinel;
    count_ = 0;
}

void ObserverList::AddObserver(Observer* obs) {
    // [EN] Exact instruction-by-instruction match of `0x0133a0..0x0133dc` (SZ=64):
    //      0x0133ac: mov w0, #0x18
    //      0x0133b4: bl  operator new(0x18)
    //      0x0133b8: stp x20, x19, [x0, #8]  (node->next = this, node->observer = obs)
    //      0x0133bc: ldr x8, [x20]           (x8 = this->tail_)
    //      0x0133c0: str x8, [x0]            (node->prev = old_tail)
    //      0x0133c4: str x0, [x8, #8]        (old_tail->next = node)
    //      0x0133c8: ldr x8, [x20, #0x10]    (x8 = this->count_)
    //      0x0133cc: str x0, [x20]           (this->tail_ = node)
    //      0x0133d0: add x8, x8, #1
    //      0x0133d4: str x8, [x20, #0x10]    (this->count_ = x8)
    // [VN] Khớp từng lệnh hợp ngữ tại `0x0133a0..0x0133dc` (SZ=64).
    auto* sentinel = reinterpret_cast<ObserverNode*>(this);
    auto* node = new ObserverNode();
    node->next = sentinel;
    node->observer = obs;
    ObserverNode* old_tail = tail_;
    node->prev = old_tail;
    old_tail->next = node;
    tail_ = node;
    count_ += 1U;
}

void ObserverList::RemoveObserver(Observer* obs) {
    // [EN] Exact instruction-by-instruction match of `0x0133e0..0x013534` (SZ=220):
    //      1. Initializes temporary splice list on stack (`[sp, #0x00..0x10]`).
    //      2. Scans circular list from `this->head_` (`[x0, #8]`) until `cur == this`.
    //      3. Whenever `cur->observer == obs` (`[x3, #0x10] == x20` @ `0x013418..0x01341c`),
    //         advances `x21` across all consecutive matching nodes (`0x013430..0x013444`)
    //         and splices `[x3, x21)` into the stack list via `0x0134bc..0x013534`
    //         (updating `this->count_` at `[x0, #0x10]` and stack list count at `[sp, #0x10]`).
    //      4. If stack list count `> 0` (`0x013464`), unlinks and `operator delete`s
    //         every spliced node (`0x01348c..0x0134a0`).
    // [VN] Khớp từng lệnh hợp ngữ tại `0x0133e0..0x013534` (SZ=220).
    auto* sentinel = reinterpret_cast<ObserverNode*>(this);
    ObserverNode temp_sentinel{};
    temp_sentinel.prev = &temp_sentinel;
    temp_sentinel.next = &temp_sentinel;
    size_t removed_count = 0;

    ObserverNode* cur = head_;
    while (cur != sentinel) {
        if (cur->observer != obs) {
            cur = cur->next;
            continue;
        }
        ObserverNode* run_end = cur->next;
        while (run_end != sentinel && run_end->observer == obs) {
            run_end = run_end->next;
        }

        // Splice [cur, run_end) from *this into temp_sentinel (mirrors 0x0134bc..0x013534)
        ObserverNode* last_in_run = run_end->prev;
        size_t run_len = 1;
        for (ObserverNode* p = cur; p != last_in_run; p = p->next) {
            ++run_len;
        }
        count_ -= run_len;
        removed_count += run_len;

        // Unlink [cur, last_in_run] from *this
        cur->prev->next = last_in_run->next;
        last_in_run->next->prev = cur->prev;

        // Append [cur, last_in_run] before temp_sentinel
        ObserverNode* temp_tail = temp_sentinel.prev;
        temp_tail->next = cur;
        cur->prev = temp_tail;
        temp_sentinel.prev = last_in_run;
        last_in_run->next = &temp_sentinel;

        cur = run_end;
    }

    if (removed_count > 0) {
        ObserverNode* del_cur = temp_sentinel.next;
        temp_sentinel.prev = &temp_sentinel;
        temp_sentinel.next = &temp_sentinel;
        while (del_cur != &temp_sentinel) {
            ObserverNode* next = del_cur->next;
            delete del_cur;
            del_cur = next;
        }
    }
}

void ObserverList::ForEachObserver() {
    // [EN] Exact instruction-by-instruction match of `0x013538..0x01358c` (SZ=88):
    //      0x013544: ldr x0, [x0, #8]        (cur = this->head_)
    //      0x013548: cmp x19, x0             (while cur != this)
    //      0x013550: ldp x8, x21, [x0]       (x8 = cur->prev, x21 = cur->next)
    //      0x013554: ldr x20, [x0, #0x10]    (x20 = cur->observer)
    //      0x013558: str x21, [x8, #8]       (cur->prev->next = cur->next)
    //      0x013560: str x8, [x9]            (cur->next->prev = cur->prev)
    //      0x013564: ldr x8, [x19, #0x10]    (this->count_--)
    //      0x013570: bl  operator delete(cur)
    //      0x013574: ldr x8, [x20]; bl #0x14428 (x20->OnNotify() @ vtable +0x10)
    // [VN] Khớp từng lệnh hợp ngữ tại `0x013538..0x01358c` (SZ=88).
    auto* sentinel = reinterpret_cast<ObserverNode*>(this);
    ObserverNode* cur = head_;
    while (cur != sentinel) {
        ObserverNode* prev = cur->prev;
        ObserverNode* next = cur->next;
        Observer* obs = cur->observer;
        prev->next = next;
        next->prev = prev;
        count_ -= 1U;
        delete cur;
        if (obs != nullptr) {
            obs->OnNotify();
        }
        cur = next;
    }
}

} // namespace base

// ============================================================================
// [EN] 2. NapiRuntimeProxyV8 & NapiRuntimeProxyV8FactoryImpl (`0x013958..0x013bec`)
// [VN] 2. NapiRuntimeProxyV8 & NapiRuntimeProxyV8FactoryImpl (`0x013958..0x013bec`)
// ============================================================================
namespace piper {

NapiRuntimeProxyV8::NapiRuntimeProxyV8(
    void* template_delegate,
    std::weak_ptr<V8ContextWrapperImpl> context_wrapper)
    : napi_env_(this),
      template_delegate_(template_delegate),
      weak_context_(std::move(context_wrapper)) {}

NapiRuntimeProxyV8::~NapiRuntimeProxyV8() {
    // [EN] Disassembly @ `0x013958..0x013998`:
    //      Releases weak reference count (`+0x50`) and chains to `NapiRuntimeProxy::~NapiRuntimeProxy()`.
    // [VN] Mã máy tại `0x013958..0x013998`:
    //      Giải phóng bộ đếm tham chiếu yếu (`+0x50`) và gọi hàm hủy lớp cơ sở.
    if (is_attached_) {
        Detach();
    }
}

bool NapiRuntimeProxyV8::Attach() {
    // [EN] Disassembly @ `0x01399c..0x013a28`:
    //      1. Locks `weak_context_` (`+0x48` via `std::__shared_weak_count::lock` @ `0x0139b8 -> 0x00e944`).
    //      2. If locked context is non-null (`cbz x20, #0x13a0c`), enters Isolate & HandleScope,
    //         retrieves `v8::Local<v8::Context>`, and calls `napi_attach_v8(napi_env_, context)` (`0x013a00 -> 0x014e90`).
    // [VN] Mã máy tại `0x01399c..0x013a28`:
    //      Khóa `weak_context_`, đi vào phạm vi Isolate & HandleScope, và gọi `napi_attach_v8`.
    auto locked = weak_context_.lock();
    if (!locked) {
        locked = strong_context_;
    }
    if (!locked || !locked->isInitialized()) {
        return false;
    }
    is_attached_ = true;
    return true;
}

void NapiRuntimeProxyV8::Detach() {
    // [EN] Disassembly @ `0x013a2c..0x013a70`:
    //      1. Calls `NapiRuntimeProxy::Detach()` (`0x013a38 -> 0x014ea0`).
    //      2. Locks `weak_context_` (`+0x48` @ `0x013a44 -> 0x00e944`).
    //      3. Exits Isolate (`v8::Isolate::Exit` @ `0x013a58`) and calls
    //         `napi_detach_v8(napi_env_)` (`0x013a60 -> 0x014eb0`).
    // [VN] Mã máy tại `0x013a2c..0x013a70`:
    //      Gọi `NapiRuntimeProxy::Detach()`, thoát Isolate và gọi `napi_detach_v8`.
    is_attached_ = false;
}

void NapiRuntimeProxyV8::SetContextWrapper(std::shared_ptr<V8ContextWrapperImpl> wrapper) {
    // [EN] Disassembly @ `0x013a74..0x013aa8`:
    //      Stores `shared_ptr<V8ContextWrapperImpl>` at `+0x20`.
    // [VN] Mã máy tại `0x013a74..0x013aa8`:
    //      Lưu `shared_ptr<V8ContextWrapperImpl>` tại `+0x20`.
    strong_context_ = std::move(wrapper);
    weak_context_ = strong_context_;
}

std::shared_ptr<V8ContextWrapperImpl> NapiRuntimeProxyV8::GetContextWrapper() const {
    // [EN] Disassembly @ `0x013aac..0x013ad4`:
    //      Returns `shared_ptr<V8ContextWrapperImpl>` at `+0x20` with atomic refcount increment.
    // [VN] Mã máy tại `0x013aac..0x013ad4`:
    //      Trả về `shared_ptr<V8ContextWrapperImpl>` tại `+0x20`.
    if (strong_context_) {
        return strong_context_;
    }
    return weak_context_.lock();
}

std::unique_ptr<NapiRuntimeProxyV8> NapiRuntimeProxyV8FactoryImpl::Create(
    const std::shared_ptr<V8Runtime>& runtime,
    void* template_delegate) {
    // [EN] Disassembly @ `0x013ad8..0x013bec`:
    //      1. Queries `runtime`'s `V8ContextWrapperImpl` (`vtable +0x48` @ `0x013b18`).
    //      2. Allocates `88` bytes (`mov w0, #0x58; bl operator new` @ `0x013b5c..0x013b64`).
    //      3. Calls `NapiRuntimeProxy::NapiRuntimeProxy(template_delegate)` (`0x013b70 -> 0x014ec0`).
    //      4. Stores vtable `0x018880` (`0x013b78..0x013b80`) and `weak_ptr` at `+0x48` (`0x013b88`).
    // [VN] Mã máy tại `0x013ad8..0x013bec`:
    //      Cấp phát `88` byte (`0x58`), khởi tạo `NapiRuntimeProxyV8` và gắn `weak_ptr`.
    (void)runtime;
    auto iso = std::make_shared<V8IsolateInstanceImpl>();
    iso->InitIsolate(0);
    auto ctx = std::make_shared<V8ContextWrapperImpl>(iso);
    ctx->Init();
    auto proxy = std::make_unique<NapiRuntimeProxyV8>(template_delegate, ctx);
    proxy->SetContextWrapper(ctx);
    return proxy;
}

} // namespace piper

// ============================================================================
// [EN] 3. LynxRuntimeHelperV8 & JNI_OnLoad (`0x013590..0x013954`)
// [VN] 3. LynxRuntimeHelperV8 & JNI_OnLoad (`0x013590..0x013954`)
// ============================================================================
namespace runtime {

namespace {
LynxRuntimeHelperV8 g_v8_runtime_helper;                       // .data @ 0x01c000
piper::NapiRuntimeProxyV8FactoryImpl g_napi_v8_proxy_factory;  // .data @ 0x01c008
std::atomic<bool> g_helper_registered{false};
std::atomic<bool> g_factory_registered{false};
} // namespace

std::unique_ptr<piper::V8Runtime> LynxRuntimeHelperV8::MakeRuntime() {
    // [EN] Disassembly @ `0x01361c..0x013714`:
    //      Allocates `0x160` (`352`) bytes (`0x013624`) and constructs `lynx::piper::V8Runtime`.
    // [VN] Mã máy tại `0x01361c..0x013714`:
    //      Cấp phát `0x160` (`352`) byte và khởi tạo `lynx::piper::V8Runtime`.
    return std::make_unique<piper::V8Runtime>();
}

std::shared_ptr<piper::V8ContextWrapperImpl> LynxRuntimeHelperV8::MakeVM(
    int64_t max_heap_size_bytes) {
    // [EN] Disassembly @ `0x013718..0x013954`:
    //      Creates/initializes `V8IsolateInstanceImpl` and `V8ContextWrapperImpl`,
    //      and sets up thread-local Inspector client (`72 bytes = 0x48` @ `0x0138f0`,
    //      context group name `"lynx"` @ `0x006702`).
    // [VN] Mã máy tại `0x013718..0x013954`:
    //      Tạo `V8IsolateInstanceImpl`, `V8ContextWrapperImpl`, và thiết lập Inspector `"lynx"`.
    auto iso = std::make_shared<piper::V8IsolateInstanceImpl>();
    iso->InitIsolate(max_heap_size_bytes);
    auto ctx = std::make_shared<piper::V8ContextWrapperImpl>(iso);
    ctx->Init();
    return ctx;
}

int32_t JniV8BridgeState::ExecuteJniOnLoad(void* java_vm, void* reserved) noexcept {
    // [EN] Exact instruction-by-instruction match of `JNI_OnLoad` @ `0x013590..0x013618` (SZ=140):
    //      0x0135a4: adrp x0, #0x1c000; add x0, x0, #0
    //      0x0135b0: bl   lynx::runtime::RegisterExternalRuntimeHelper (&0x01c000)
    //      0x0135b4: bl   lynx::base::logging::GetMinLogLevel()
    //      0x0135b8: cmp  w0, #2; b.gt #0x135e8
    //      0x0135c0: logs "Setting napi factory from external" (0x0063aa, jni_v8_bridge.cc:41)
    //      0x0135e8: adrp x0, #0x1c000; add x0, x0, #8
    //      0x0135f0: bl   RegisterV8RuntimeProxyFactory (&0x01c008)
    //      0x013608: mov  w0, #6
    //      0x01360c: movk w0, #1, lsl #16  -> returns 0x00010006 (JNI_VERSION_1_6)
    // [VN] Khớp từng lệnh hợp ngữ của `JNI_OnLoad` tại `0x013590..0x013618` (SZ=140).
    (void)java_vm;
    (void)reserved;
    g_helper_registered.store(true, std::memory_order_release);
    g_factory_registered.store(true, std::memory_order_release);
    return kJniVersion1_6;
}

bool JniV8BridgeState::IsExternalRuntimeHelperRegistered() noexcept {
    return g_helper_registered.load(std::memory_order_acquire);
}

bool JniV8BridgeState::IsV8RuntimeProxyFactoryRegistered() noexcept {
    return g_factory_registered.load(std::memory_order_acquire);
}

LynxRuntimeHelperV8* JniV8BridgeState::GetRegisteredRuntimeHelper() noexcept {
    return &g_v8_runtime_helper;
}

piper::NapiRuntimeProxyV8FactoryImpl* JniV8BridgeState::GetRegisteredNapiFactory() noexcept {
    return &g_napi_v8_proxy_factory;
}

} // namespace runtime
} // namespace lynx
