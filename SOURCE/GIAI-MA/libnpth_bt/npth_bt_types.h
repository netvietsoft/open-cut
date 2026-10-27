// ============================================================================
// Clean-Room C++17 Types, Struct Layouts & .rodata Symbols for libnpth_bt.so
// Định nghĩa kiểu dữ liệu, cấu trúc ABI & biểu tượng .rodata cho libnpth_bt.so
// Binary: 7,344 bytes | SHA-256: da4df4ef3b317309cbb3363bdf8e352ecdb8ae45a670d87ee1b426c32abdd150
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <mutex>

namespace npth_bt {

// API Level Range Constants observed at 0x0d38..0x0d40 & 0x100c..0x1014:
//   `sub w8, w0, #0x24; cmn w8, #0x11; b.hs` -> (uint32_t)(api - 36) >= (uint32_t)(-17)
//   Valid Android API levels: [19 .. 35] (Android 4.4 KitKat .. Android 15)
constexpr int32_t kMinSupportedApiLevel  = 19;   // 0x24 - 0x11 = 19
constexpr int32_t kMaxSupportedApiLevel  = 35;   // 0x24 - 1    = 35
constexpr int32_t kKitKatMaxApiLevel     = 20;   // `cmp w24, #0x14` (@ 0x0e4c)
constexpr int32_t kPieSplitLibApiLevel   = 28;   // `cmp w0, #0x1c`  (@ 0x0dfc, 0x109c)
constexpr int32_t kDefaultIgnoreDepth    = 2;    // `mov w1, #2`     (@ 0x0d80, 0x0d9c)
constexpr int32_t kKitKatDefaultMaxDepth = 31;   // `mov w2, #0x1f`  (@ 0x0da0)
constexpr int32_t kCurrentThreadSentinel = -1;   // `mov w0, #-1`    (@ 0x0f84)
constexpr size_t  kScratchCallStackBytes = 0x800; // 2,048 bytes (`mov w2, #0x800` @ 0x11ac)

// Exact .rodata Mangled Symbol & Library Names (0x0870..0x09f1, 385 bytes):
// Các chuỗi tên thư viện và biểu tượng C++ mangled trong .rodata (0x0870..0x09f1):
constexpr const char* kSymProcessCallStackToString = "_ZNK7android16ProcessCallStack8toStringEPKc"; // 0x0870
constexpr const char* kLibUtilsSo                  = "libutils.so";                                  // 0x089c
constexpr const char* kLibUtilsCallStackSo         = "libutilscallstack.so";                         // 0x08a8
constexpr const char* kSymCallStackToString        = "_ZNK7android9CallStack8toStringEPKc";          // 0x08bd
constexpr const char* kSymProcessCallStackCtor     = "_ZN7android16ProcessCallStackC1Ev";            // 0x08e1
constexpr const char* kSymCallStackCtor            = "_ZN7android9CallStackC1Ev";                    // 0x0903
constexpr const char* kSymCallStackUpdate2         = "_ZN7android9CallStack6updateEii";              // 0x091d
constexpr const char* kSymString8Dtor              = "_ZN7android7String8D1Ev";                      // 0x093d
constexpr const char* kSymCallStackUpdate3         = "_ZN7android9CallStack6updateEiii";             // 0x0955
constexpr const char* kSymCallStackDtor            = "_ZN7android9CallStackD1Ev";                    // 0x0976
constexpr const char* kSymProcessCallStackUpdate   = "_ZN7android16ProcessCallStack6updateEv";       // 0x0990
constexpr const char* kSymProcessCallStackDtor     = "_ZN7android16ProcessCallStackD1Ev";            // 0x09b7
constexpr const char* kSymString8Ctor              = "_ZN7android7String8C1Ev";                      // 0x09d9

// 32-Byte AArch64 Stack Slot for `android::String8` (`[x29 - 0x30]` in npth_bt_thread/npth_bt_all,
// and `[sp + 0x08]` in npth_bt_free @ 0x1164..0x1168):
struct AndroidString8Slot32B {
    char*    mString; // +0x00 (returned as char* by npth_bt_thread / npth_bt_all @ 0x0dc4, 0x106c)
    uint64_t pad1;    // +0x08
    uint64_t pad2;    // +0x10
    uint64_t pad3;    // +0x18
};
static_assert(sizeof(AndroidString8Slot32B) == 32, "AndroidString8Slot32B must be 32 bytes");

// Function Pointer Signatures resolved via npth_dlsym:
using CallStackCtorFn            = void (*)(void* this_ptr);
using CallStackUpdate2Fn         = void (*)(void* this_ptr, int32_t ignoreDepth, int32_t tid);
using CallStackUpdate3Fn         = void (*)(void* this_ptr, int32_t ignoreDepth, int32_t maxDepth, int32_t tid);
using CallStackToStringFn        = void (*)(AndroidString8Slot32B* sret_x8, const void* this_ptr, const char* prefix);
using CallStackDtorFn            = void (*)(void* this_ptr);

using ProcessCallStackCtorFn     = void (*)(void* this_ptr);
using ProcessCallStackUpdateFn   = void (*)(void* this_ptr);
using ProcessCallStackToStringFn = void (*)(AndroidString8Slot32B* sret_x8, const void* this_ptr, const char* prefix);
using ProcessCallStackDtorFn     = void (*)(void* this_ptr);

using String8CtorFn              = void (*)(AndroidString8Slot32B* this_ptr);
using String8DtorFn              = void (*)(AndroidString8Slot32B* this_ptr);

// 40-Byte `CallStackSymbolTable` allocated via `malloc(0x28)` at 0x0ea0..0x0ebc and stored at `.bss` `0x009558`:
// Bảng 5 con trỏ hàm CallStack 40 byte (`mov w0, #0x28` @ 0x0ea0) lưu tại `.bss` `0x009558`:
struct CallStackSymbolTable40B {
    CallStackCtorFn     ctor_fn;      // +0x00 (x20: _ZN7android9CallStackC1Ev)
    CallStackUpdate2Fn  update2_fn;   // +0x08 (x25: _ZN7android9CallStack6updateEii, API >= 21)
    CallStackUpdate3Fn  update3_fn;   // +0x10 (x24: _ZN7android9CallStack6updateEiii, API 19..20)
    CallStackToStringFn to_string_fn; // +0x18 (x22: _ZNK7android9CallStack8toStringEPKc)
    CallStackDtorFn     dtor_fn;      // +0x20 (x21: _ZN7android9CallStackD1Ev)
};
static_assert(sizeof(CallStackSymbolTable40B) == 40, "CallStackSymbolTable40B must be 40 bytes (0x28)");

// 16-Byte `String8SymbolTable` allocated via `malloc(0x10)` at 0x0f50..0x0f60 and stored at `.bss` `0x009560`:
// Bảng 2 con trỏ hàm String8 16 byte (`mov w0, #0x10` @ 0x0f50) lưu tại `.bss` `0x009560`:
struct String8SymbolTable16B {
    String8CtorFn ctor_fn; // +0x00 (x19: _ZN7android7String8C1Ev)
    String8DtorFn dtor_fn; // +0x08 (x20: _ZN7android7String8D1Ev)
};
static_assert(sizeof(String8SymbolTable16B) == 16, "String8SymbolTable16B must be 16 bytes (0x10)");

// 32-Byte `ProcessCallStackSymbolTable` allocated via `malloc(0x20)` at 0x1114..0x112c and stored at `.bss` `0x009568`:
// Bảng 4 con trỏ hàm ProcessCallStack 32 byte (`mov w0, #0x20` @ 0x1114) lưu tại `.bss` `0x009568`:
struct ProcessCallStackSymbolTable32B {
    ProcessCallStackCtorFn     ctor_fn;      // +0x00 (x19: _ZN7android16ProcessCallStackC1Ev)
    ProcessCallStackUpdateFn   update_fn;    // +0x08 (x23: _ZN7android16ProcessCallStack6updateEv)
    ProcessCallStackToStringFn to_string_fn; // +0x10 (x21: _ZNK7android16ProcessCallStack8toStringEPKc)
    ProcessCallStackDtorFn     dtor_fn;      // +0x18 (x20: _ZN7android16ProcessCallStackD1Ev)
};
static_assert(sizeof(ProcessCallStackSymbolTable32B) == 32, "ProcessCallStackSymbolTable32B must be 32 bytes (0x20)");

} // namespace npth_bt
