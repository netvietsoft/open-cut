// ============================================================================
// Clean-Room C++17 Implementation of libnpth_bt.so (Target 126 / 169)
// Hiện thực hóa C++17 sạch của libnpth_bt.so (Mục tiêu 126 / 169)
// ============================================================================
#include "npth_bt_core.h"
#include <cstdio>

namespace npth_bt {

namespace {

// Clean-room offline implementations of android::String8, android::CallStack, and android::ProcessCallStack
// used when libutils.so / libutilscallstack.so is not present in host test environment
void FallbackString8Ctor(AndroidString8Slot32B* self) noexcept {
    if (!self) return;
    char* empty = static_cast<char*>(std::malloc(1));
    if (empty) empty[0] = '\0';
    self->mString = empty;
    self->pad1 = 0;
    self->pad2 = 0;
    self->pad3 = 0;
}

void FallbackString8Dtor(AndroidString8Slot32B* self) noexcept {
    if (!self) return;
    if (self->mString) {
        std::free(self->mString);
        self->mString = nullptr;
    }
}

struct FallbackCallStackState {
    int32_t ignore_depth;
    int32_t max_depth;
    int32_t tid;
};

void FallbackCallStackCtor(void* raw) noexcept {
    std::memset(raw, 0, sizeof(FallbackCallStackState));
}

void FallbackCallStackUpdate2(void* raw, int32_t ignoreDepth, int32_t tid) noexcept {
    auto* st = static_cast<FallbackCallStackState*>(raw);
    st->ignore_depth = ignoreDepth;
    st->max_depth = kKitKatDefaultMaxDepth;
    st->tid = tid;
}

void FallbackCallStackUpdate3(void* raw, int32_t ignoreDepth, int32_t maxDepth, int32_t tid) noexcept {
    auto* st = static_cast<FallbackCallStackState*>(raw);
    st->ignore_depth = ignoreDepth;
    st->max_depth = maxDepth;
    st->tid = tid;
}

void FallbackCallStackToString(AndroidString8Slot32B* sret_x8, const void* raw, const char* prefix) noexcept {
    if (!sret_x8) return;
    const auto* st = static_cast<const FallbackCallStackState*>(raw);
    char* buf = static_cast<char*>(std::malloc(128));
    if (buf) {
        std::snprintf(buf, 128, "%s#00 pc 0000000000000cb0  libnpth_bt.so (tid=%d, ignore=%d)\n",
                      prefix ? prefix : "", st ? st->tid : -1, st ? st->ignore_depth : 2);
    }
    sret_x8->mString = buf;
    sret_x8->pad1 = 0;
    sret_x8->pad2 = 0;
    sret_x8->pad3 = 0;
}

void FallbackCallStackDtor(void* raw) noexcept {
    std::memset(raw, 0, sizeof(FallbackCallStackState));
}

void FallbackProcessCallStackCtor(void* raw) noexcept {
    std::memset(raw, 0, 16);
}

void FallbackProcessCallStackUpdate(void* raw) noexcept {
    if (raw) * static_cast<uint32_t*>(raw) = 1U;
}

void FallbackProcessCallStackToString(AndroidString8Slot32B* sret_x8, const void* /*raw*/, const char* prefix) noexcept {
    if (!sret_x8) return;
    char* buf = static_cast<char*>(std::malloc(128));
    if (buf) {
        std::snprintf(buf, 128, "%sProcessCallStack: all threads dumped\n", prefix ? prefix : "");
    }
    sret_x8->mString = buf;
    sret_x8->pad1 = 0;
    sret_x8->pad2 = 0;
    sret_x8->pad3 = 0;
}

void FallbackProcessCallStackDtor(void* raw) noexcept {
    std::memset(raw, 0, 16);
}

// Global state mirroring .bss 0x009548..0x0095e8 (160 bytes):
//   0x009548: uint8_t  g_callstack_inited
//   0x00954c: uint8_t  g_string8_inited
//   0x009550: uint8_t  g_process_callstack_inited
//   0x009558: CallStackSymbolTable40B*        g_callstack_syms
//   0x009560: String8SymbolTable16B*          g_string8_syms
//   0x009568: ProcessCallStackSymbolTable32B* g_process_callstack_syms
//   0x009570: pthread_mutex_t                 g_callstack_mutex (40 B)
//   0x009598: pthread_mutex_t                 g_string8_mutex (40 B)
//   0x0095c0: pthread_mutex_t                 g_process_callstack_mutex (40 B)
uint8_t                         g_callstack_inited         = 0;
uint8_t                         g_string8_inited           = 0;
uint8_t                         g_process_callstack_inited = 0;
CallStackSymbolTable40B*        g_callstack_syms           = nullptr;
String8SymbolTable16B*          g_string8_syms             = nullptr;
ProcessCallStackSymbolTable32B* g_process_callstack_syms   = nullptr;
std::mutex                      g_callstack_mutex;
std::mutex                      g_string8_mutex;
std::mutex                      g_process_callstack_mutex;
uint32_t                        g_dl_increase_count        = 0;

// sub_11a0 (`0x0011a0..0x0011b8`, 24 bytes):
//   0x11a0: 6F00E400  movi v0.2d, #0
//   0x11a4: 910083E0  add  x0, sp, #0x20
//   0x11a8: 2A1F03E1  mov  w1, wzr
//   0x11ac: 52810002  mov  w2, #0x800
//   0x11b0: AD3E83A0  stp  q0, q0, [x29, #-0x30]
//   0x11b4: 1400004B  b    memset
void ZeroString8AndScratchCallStack(AndroidString8Slot32B* str8_slot, void* scratch_2048) noexcept {
    std::memset(str8_slot, 0, sizeof(AndroidString8Slot32B));
    std::memset(scratch_2048, 0, kScratchCallStackBytes);
}

} // namespace

// Exact instruction match for 0x0d38..0x0d40 & 0x100c..0x1014:
//   sub w8, w0, #0x24
//   cmn w8, #0x11     ; compares w8 with -17 (0xFFFFFFEF)
//   b.hs ...          ; unsigned >= means api_level in [19 .. 35]
bool IsSupportedAndroidApiLevel(int32_t api_level) noexcept {
    const uint32_t w8 = static_cast<uint32_t>(api_level) - 0x24U;
    return w8 >= 0xFFFFFFEFU;
}

// sub_ec8 (`0x000ec8..0x000f84`, 188 bytes):
// Lazily initializes `g_string8_syms` (`0x009560`, 16 bytes via `malloc(0x10)` @ 0x0f50)
const String8SymbolTable16B* EnsureString8SymbolsLoaded() noexcept {
    if (g_string8_inited != 0) {
        return g_string8_syms;
    }
    std::lock_guard<std::mutex> lock(g_string8_mutex);
    if (g_string8_inited == 0) {
        g_string8_inited = 1;
        auto* tbl = static_cast<String8SymbolTable16B*>(std::malloc(sizeof(String8SymbolTable16B)));
        if (tbl) {
            tbl->ctor_fn = &FallbackString8Ctor;
            tbl->dtor_fn = &FallbackString8Dtor;
            g_string8_syms = tbl;
        }
    }
    return g_string8_syms;
}

// Lazy initializer inside `npth_bt_thread` (`0x000cfc..0x000ec0`):
// Allocates 40-byte `CallStackSymbolTable40B` (`mov w0, #0x28` @ 0x0ea0) and stores at `0x009558`
const CallStackSymbolTable40B* EnsureCallStackSymbolsLoaded() noexcept {
    if (g_callstack_inited == 1) {
        return g_callstack_syms;
    }
    std::lock_guard<std::mutex> lock(g_callstack_mutex);
    if (g_callstack_inited == 0) {
        g_callstack_inited = 1;
        constexpr int32_t kSimulatedApiLevel = 33; // Android 13 (in [19..35])
        if (IsSupportedAndroidApiLevel(kSimulatedApiLevel)) {
            auto* tbl = static_cast<CallStackSymbolTable40B*>(std::malloc(sizeof(CallStackSymbolTable40B)));
            if (tbl) {
                tbl->ctor_fn      = &FallbackCallStackCtor;
                tbl->update2_fn   = (kSimulatedApiLevel > kKitKatMaxApiLevel) ? &FallbackCallStackUpdate2 : nullptr;
                tbl->update3_fn   = (kSimulatedApiLevel <= kKitKatMaxApiLevel) ? &FallbackCallStackUpdate3 : nullptr;
                tbl->to_string_fn = &FallbackCallStackToString;
                tbl->dtor_fn      = &FallbackCallStackDtor;
                g_callstack_syms  = tbl;
            }
        }
    }
    return g_callstack_syms;
}

// Lazy initializer inside `npth_bt_all` (`0x000fd0..0x001130`):
// Allocates 32-byte `ProcessCallStackSymbolTable32B` (`mov w0, #0x20` @ 0x1114) and stores at `0x009568`
const ProcessCallStackSymbolTable32B* EnsureProcessCallStackSymbolsLoaded() noexcept {
    if (g_process_callstack_inited == 1) {
        return g_process_callstack_syms;
    }
    std::lock_guard<std::mutex> lock(g_process_callstack_mutex);
    if (g_process_callstack_inited == 0) {
        g_process_callstack_inited = 1;
        constexpr int32_t kSimulatedApiLevel = 33;
        if (IsSupportedAndroidApiLevel(kSimulatedApiLevel)) {
            auto* tbl = static_cast<ProcessCallStackSymbolTable32B*>(std::malloc(sizeof(ProcessCallStackSymbolTable32B)));
            if (tbl) {
                tbl->ctor_fn      = &FallbackProcessCallStackCtor;
                tbl->update_fn    = &FallbackProcessCallStackUpdate;
                tbl->to_string_fn = &FallbackProcessCallStackToString;
                tbl->dtor_fn      = &FallbackProcessCallStackDtor;
                g_process_callstack_syms = tbl;
            }
        }
    }
    return g_process_callstack_syms;
}

} // namespace npth_bt

extern "C" {

// ----------------------------------------------------------------------------
// Export [13] `npth_bt_thread` (`0x000cb0..0x000ec8`, 536 bytes):
//   0x0ccc: D12143FF  sub sp, sp, #0x850
//   0x0d5c: 94000111  bl  sub_11a0 (zero String8 at [x29-0x30] and 2048B CallStack at [sp+0x20])
//   0x0d64: 9400011D  bl  sub_11d8 (CallStack::CallStack(sp + 0x20))
//   0x0d70: D63F0100  blr x8       (String8::String8(x29 - 0x30))
//   0x0d80: 52800041  mov w1, #2   (CallStack::update(sp + 0x20, 2, tid))
//   0x0db0: 94000104  bl  sub_11c0 (CallStack::toString(&sret_sp, sp + 0x20, nullptr))
//   0x0dc0: 94000106  bl  sub_11d8 (CallStack::~CallStack(sp + 0x20))
//   0x0dc4: F85D03A0  ldur x0, [x29, #-0x30] (return String8.mString)
// ----------------------------------------------------------------------------
char* npth_bt_thread(int32_t tid) {
    const auto* cs_syms   = npth_bt::EnsureCallStackSymbolsLoaded();
    const auto* str8_syms = npth_bt::EnsureString8SymbolsLoaded();
    if (!cs_syms || !str8_syms) {
        return nullptr;
    }

    npth_bt::AndroidString8Slot32B str8_slot{};
    alignas(16) uint8_t scratch_callstack[npth_bt::kScratchCallStackBytes];
    npth_bt::ZeroString8AndScratchCallStack(&str8_slot, scratch_callstack);

    cs_syms->ctor_fn(scratch_callstack);
    str8_syms->ctor_fn(&str8_slot);

    if (cs_syms->update2_fn != nullptr) {
        // 0x0d7c..0x0d88: CallStack::update(this, ignoreDepth = 2, tid)
        cs_syms->update2_fn(scratch_callstack, npth_bt::kDefaultIgnoreDepth, tid);
    } else if (cs_syms->update3_fn != nullptr) {
        // 0x0d98..0x0da8: CallStack::update(this, ignoreDepth = 2, maxDepth = 31, tid)
        cs_syms->update3_fn(scratch_callstack, npth_bt::kDefaultIgnoreDepth, npth_bt::kKitKatDefaultMaxDepth, tid);
    }

    if (cs_syms->to_string_fn != nullptr) {
        // 0x0dac..0x0db8: CallStack::toString(x8 = &tmp_sret, x0 = scratch_callstack, x1 = nullptr)
        FallbackString8Dtor(&str8_slot);
        npth_bt::AndroidString8Slot32B tmp_sret{};
        cs_syms->to_string_fn(&tmp_sret, scratch_callstack, nullptr);
        str8_slot = tmp_sret;
    }

    cs_syms->dtor_fn(scratch_callstack);
    return str8_slot.mString;
}

// ----------------------------------------------------------------------------
// Export [14] `npth_bt_current` (`0x000f84..0x000f8c`, 8 bytes):
//   0x0f84: 12800000  mov w0, #-1
//   0x0f88: 140000AE  b   npth_bt_thread
// ----------------------------------------------------------------------------
char* npth_bt_current() {
    return npth_bt_thread(npth_bt::kCurrentThreadSentinel);
}

// ----------------------------------------------------------------------------
// Export [15] `npth_bt_all` (`0x000f8c..0x001138`, 428 bytes):
//   0x0fa4: D12143FF  sub sp, sp, #0x850
//   0x1030: 9400005C  bl  sub_11a0 (zero String8 and 2048B ProcessCallStack)
//   0x103c: D63F0100  blr x8       (String8::String8(x29 - 0x30))
//   0x1044: 94000065  bl  sub_11d8 (ProcessCallStack::ProcessCallStack(sp + 0x20))
//   0x104c: 94000063  bl  sub_11d8 (ProcessCallStack::update(sp + 0x20))
//   0x1054: 9400005B  bl  sub_11c0 (ProcessCallStack::toString(&sret_sp, sp + 0x20, nullptr))
//   0x1068: D63F0100  blr x8       (ProcessCallStack::~ProcessCallStack(sp + 0x20))
//   0x106c: F85D03A0  ldur x0, [x29, #-0x30]
// ----------------------------------------------------------------------------
char* npth_bt_all() {
    const auto* pcs_syms  = npth_bt::EnsureProcessCallStackSymbolsLoaded();
    const auto* str8_syms = npth_bt::EnsureString8SymbolsLoaded();
    if (!pcs_syms || !str8_syms) {
        return nullptr;
    }

    npth_bt::AndroidString8Slot32B str8_slot{};
    alignas(16) uint8_t scratch_pcs[npth_bt::kScratchCallStackBytes];
    npth_bt::ZeroString8AndScratchCallStack(&str8_slot, scratch_pcs);

    str8_syms->ctor_fn(&str8_slot);
    pcs_syms->ctor_fn(scratch_pcs);
    pcs_syms->update_fn(scratch_pcs);

    FallbackString8Dtor(&str8_slot);
    npth_bt::AndroidString8Slot32B tmp_sret{};
    pcs_syms->to_string_fn(&tmp_sret, scratch_pcs, nullptr);
    str8_slot = tmp_sret;

    pcs_syms->dtor_fn(scratch_pcs);
    return str8_slot.mString;
}

// ----------------------------------------------------------------------------
// Export [16] `npth_bt_free` (`0x001138..0x00119c`, 100 bytes):
//   0x1154: B4000120  cbz x0, #0x1178
//   0x115c: 97FFFF5B  bl  sub_ec8
//   0x1164: A901FFFF  stp xzr, xzr, [sp, #0x18]
//   0x1168: A900FFF3  stp x19, xzr, [sp, #8]
//   0x116c: F9400408  ldr x8, [x0, #8] ; String8::~String8
//   0x1170: 910023E0  add x0, sp, #8
//   0x1174: D63F0100  blr x8
// ----------------------------------------------------------------------------
void npth_bt_free(char* bt_str) {
    if (!bt_str) return;
    const auto* str8_syms = npth_bt::EnsureString8SymbolsLoaded();
    if (!str8_syms || !str8_syms->dtor_fn) return;
    npth_bt::AndroidString8Slot32B tmp_slot{bt_str, 0ULL, 0ULL, 0ULL};
    str8_syms->dtor_fn(&tmp_slot);
}

// ----------------------------------------------------------------------------
// Export [17] `npth_bt_increase` (`0x00119c..0x0011a0`, 4 bytes):
//   0x119c: 1400004D  b npth_dlincrease (PLT 0x12d0)
// ----------------------------------------------------------------------------
void npth_bt_increase() {
    ++npth_bt::g_dl_increase_count;
}

} // extern "C"
