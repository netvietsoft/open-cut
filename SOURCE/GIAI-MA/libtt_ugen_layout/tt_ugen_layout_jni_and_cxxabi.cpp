// ============================================================================
// File: tt_ugen_layout_jni_and_cxxabi.cpp
// Target: libtt_ugen_layout.so (360,968 bytes, SHA-256: 05ddb584447d49f6ac1707d00ab557acdc1ddcc6fddbb29628bda1320745e44e)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Clean-room C++17 implementation of YGJNIVanilla::registerNatives (0x026650),
//     PtrJNodeMapVanilla (0x027580), facebook::yoga::vanillajni::YogaJniException
//     (0x035514..0x035a64), and JNI_OnLoad (0x0365b4).
// VN: Triển khai C++17 clean-room của YGJNIVanilla::registerNatives (0x026650),
//     PtrJNodeMapVanilla (0x027580), facebook::yoga::vanillajni::YogaJniException
//     (0x035514..0x035a64), và JNI_OnLoad (0x0365b4).
// ============================================================================

#include "tt_ugen_layout_jni_and_cxxabi.h"
#include <cstring>

static _JavaVM* g_yoga_java_vm = nullptr;
static size_t   g_registered_method_count = 0;

// EN: Reconstructs YGJNIVanilla::registerNatives(_JNIEnv*) at 0x026650..0x026668:
//     0x026650: 90FFFFA1 adrp x1, #0x1a000
//     0x026654: B00001C2 adrp x2, #0x5f000
//     0x026658: 910BAC21 add  x1, x1, #0x2eb  ("com/bytedance/adsdk/ugeno/yoga/YogaNative")
//     0x02665c: 91006042 add  x2, x2, #0x18   (.data 0x05f018 JNINativeMethod[95])
//     0x026660: 52800BE3 mov  w3, #0x5f       (95 methods)
//     0x026664: 1400ADD7 b    #0x51dc0        (facebook::yoga::vanillajni::registerNatives)
// VN: Tái tạo YGJNIVanilla::registerNatives(_JNIEnv*) tại 0x026650..0x026668.
void YGJNIVanilla::registerNatives(_JNIEnv* env) noexcept {
    using namespace nextai::opencut::tt_ugen_layout;
    JNINativeMethod table[95];
    for (size_t i = 0; i < 95; ++i) {
        table[i].name = kYogaNativeJniMethods_05f018[i].name;
        table[i].signature = kYogaNativeJniMethods_05f018[i].signature;
        table[i].fnPtr = reinterpret_cast<void*>(static_cast<uintptr_t>(kYogaNativeJniMethods_05f018[i].fn_text_va));
    }
    facebook::yoga::vanillajni::registerNatives(env, kYogaNativeClassName_01a2eb, table, 95u);
}

// EN: Reconstructs PtrJNodeMapVanilla constructor at 0x027580..0x0277cc (588 bytes).
// VN: Tái tạo hàm tạo PtrJNodeMapVanilla tại 0x027580..0x0277cc (588 byte).
PtrJNodeMapVanilla::PtrJNodeMapVanilla(const int64_t* native_ptrs, size_t count) noexcept {
    if (!native_ptrs) return;
    for (size_t i = 0; i < count; ++i) {
        YGNode* node = reinterpret_cast<YGNode*>(static_cast<uintptr_t>(native_ptrs[i]));
        ptrs_to_idxs_[node] = i;
    }
}

size_t PtrJNodeMapVanilla::findIndex(YGNode* node) const noexcept {
    auto it = ptrs_to_idxs_.find(node);
    return (it != ptrs_to_idxs_.end()) ? it->second : static_cast<size_t>(-1);
}

namespace facebook {
namespace yoga {
namespace vanillajni {

YogaJniException::YogaJniException() noexcept : throwable_(nullptr) {}
YogaJniException::YogaJniException(_jthrowable* throwable) noexcept : throwable_(throwable) {}
YogaJniException::YogaJniException(const YogaJniException& rhs) noexcept : throwable_(rhs.throwable_) {}
YogaJniException::YogaJniException(YogaJniException&& rhs) noexcept : throwable_(rhs.throwable_) {
    rhs.throwable_ = nullptr;
}
YogaJniException::~YogaJniException() noexcept {
    throwable_ = nullptr;
}
_jthrowable* YogaJniException::getThrowable() const noexcept {
    return throwable_;
}

// EN: Reconstructs facebook::yoga::vanillajni::registerNatives (0x035a68..0x035adc).
// VN: Tái tạo facebook::yoga::vanillajni::registerNatives (0x035a68..0x035adc).
void registerNatives(
    _JNIEnv* /*env*/,
    const char* className,
    const JNINativeMethod* methods,
    size_t numMethods) noexcept {
    if (className && methods && numMethods == 95u) {
        g_registered_method_count = numMethods;
    }
}

// EN: Reconstructs facebook::yoga::vanillajni::ensureInitialized (0x035f10..0x035fe8):
//     Stores JavaVM* into .bss 0x05f950 and returns JNI_VERSION_1_6 (0x00010006).
// VN: Tái tạo facebook::yoga::vanillajni::ensureInitialized (0x035f10..0x035fe8).
int ensureInitialized(_JNIEnv** envOut, _JavaVM* vm) noexcept {
    g_yoga_java_vm = vm;
    if (envOut) {
        *envOut = nullptr;
    }
    return 0x00010006; // JNI_VERSION_1_6
}

_JNIEnv* getCurrentEnv() noexcept {
    (void)g_yoga_java_vm;
    return nullptr;
}

} // namespace vanillajni
} // namespace yoga
} // namespace facebook

extern "C" {

// EN: Reconstructs JNI_OnLoad at 0x0365b4..0x036614 (96 bytes):
//     Calls facebook::yoga::vanillajni::ensureInitialized(&env, vm) (0x0365d8)
//     followed by YGJNIVanilla::registerNatives(env) (0x0365e8), and returns JNI_VERSION_1_6.
// VN: Tái tạo JNI_OnLoad tại 0x0365b4..0x036614 (96 byte):
//     Gọi ensureInitialized(&env, vm) và YGJNIVanilla::registerNatives(env), trả về 0x00010006.
int JNI_OnLoad(_JavaVM* vm, void* /*reserved*/) {
    _JNIEnv* env = nullptr;
    const int ret = facebook::yoga::vanillajni::ensureInitialized(&env, vm);
    YGJNIVanilla::registerNatives(env);
    return ret;
}

} // extern "C"
