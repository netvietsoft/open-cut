// ============================================================================
// File: tt_ugen_layout_jni_and_cxxabi.h
// Target: libtt_ugen_layout.so (360,968 bytes)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Declarations for YGJNIVanilla::registerNatives (0x026650), PtrJNodeMapVanilla
//     (0x027580), facebook::yoga::vanillajni::YogaJniException (0x035514..0x035a64),
//     facebook::yoga::Event (0x0361d0..0x036388), and JNI_OnLoad (0x0365b4).
// VN: Khai báo cho YGJNIVanilla::registerNatives (0x026650), PtrJNodeMapVanilla
//     (0x027580), facebook::yoga::vanillajni::YogaJniException (0x035514..0x035a64),
//     facebook::yoga::Event (0x0361d0..0x036388), và JNI_OnLoad (0x0365b4).
// ============================================================================

#pragma once

#include "tt_ugen_layout_types.h"
#include "tt_ugen_layout_rodata_tables.h"
#include "tt_ugen_layout_yoga_core.h"
#include <cstdint>
#include <cstddef>
#include <map>
#include <exception>

struct _JNIEnv;
struct _JavaVM;
struct _jobject;
struct _jclass;
struct _jthrowable;
struct _jlongArray;
struct _jobjectArray;

struct JNINativeMethod {
    const char* name;
    const char* signature;
    void*       fnPtr;
};

// EN: Reconstructs YGJNIVanilla::registerNatives(_JNIEnv*) at 0x026650..0x026668 (24 bytes):
//     Registers 95 native methods (0x5f) on "com/bytedance/adsdk/ugeno/yoga/YogaNative".
// VN: Tái tạo YGJNIVanilla::registerNatives(_JNIEnv*) tại 0x026650..0x026668 (24 byte):
//     Đăng ký 95 phương thức native (0x5f) trên lớp "com/bytedance/adsdk/ugeno/yoga/YogaNative".
struct YGJNIVanilla {
    static void registerNatives(_JNIEnv* env) noexcept;
};

// EN: Reconstructs PtrJNodeMapVanilla at 0x027580..0x0277cc (588 bytes):
//     Maps native YGNode* pointers to Java YogaNodeJNIBase jobject indices during batch layout.
// VN: Tái tạo PtrJNodeMapVanilla tại 0x027580..0x0277cc (588 byte).
class PtrJNodeMapVanilla {
public:
    PtrJNodeMapVanilla() noexcept = default;
    PtrJNodeMapVanilla(const int64_t* native_ptrs, size_t count) noexcept;
    size_t findIndex(YGNode* node) const noexcept;
private:
    std::map<YGNode*, size_t> ptrs_to_idxs_;
};

namespace facebook {
namespace yoga {
namespace vanillajni {

// EN: Reconstructs facebook::yoga::vanillajni::YogaJniException (0x035514..0x035a64).
// VN: Tái tạo facebook::yoga::vanillajni::YogaJniException (0x035514..0x035a64).
class YogaJniException : public std::exception {
public:
    YogaJniException() noexcept;
    explicit YogaJniException(_jthrowable* throwable) noexcept;
    YogaJniException(const YogaJniException& rhs) noexcept;
    YogaJniException(YogaJniException&& rhs) noexcept;
    ~YogaJniException() noexcept override;
    _jthrowable* getThrowable() const noexcept;
    const char* what() const noexcept override { return "YogaJniException"; }
private:
    _jthrowable* throwable_;
};

void registerNatives(_JNIEnv* env, const char* className, const JNINativeMethod* methods, size_t numMethods) noexcept;
int  ensureInitialized(_JNIEnv** envOut, _JavaVM* vm) noexcept;
_JNIEnv* getCurrentEnv() noexcept;

} // namespace vanillajni
} // namespace yoga
} // namespace facebook

extern "C" {
// EN: Exported JNI_OnLoad at 0x0365b4..0x036614 (96 bytes).
// VN: Hàm xuất JNI_OnLoad tại 0x0365b4..0x036614 (96 byte).
int JNI_OnLoad(_JavaVM* vm, void* reserved);
}
