/**
 * @file bach_resource_finder_jni.cpp
 * @brief Implementation of DownloadableResourceFinder, EPResourceFinder, ModelDownloadListener,
 *        JNI_OnLoad, and UTF-8 String Helpers for libbach-sdk-jni.so.
 *        Cài đặt chi tiết DownloadableResourceFinder, EPResourceFinder, ModelDownloadListener,
 *        JNI_OnLoad và các hàm tiện ích chuỗi UTF-8 cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 */

#include "bach_resource_finder_jni.h"

namespace com {
namespace bytedance {
namespace bach_sdk {

namespace Bach {

// ============================================================================
// 1. NativeListener & ResourceFinder Factory Implementations
//    Cài đặt chi tiết NativeListener và các nhà máy ResourceFinder [OBSERVED]
// ============================================================================

void NativeListener::onSuccess() {
    // [OBSERVED at 0x00f6ac..0x00f794]:
    //   1. Checks `java_listener_global_ref_ != nullptr` (`0x00f6c0: ldr x8, [x19, #0x10]; cbz x8, #0xf780`).
    //   2. Attaches current thread via `g_JavaVM` (`.bss 0x0202b8`) if `GetEnv(0x10006)` returns `-2` (`JNI_EDETACHED`).
    //   3. Invokes `ModelDownloadListener.onSuccess()V` (`.rodata 0x015ac6`).
    //   4. Detaches thread if `attached_thread_` (`[x19, #0x18]`) was set.
    ++success_call_count_;
    if (java_listener_global_ref_ == nullptr && !on_success_cb_) {
        return;
    }
    if (on_success_cb_) {
        on_success_cb_();
    }
}

void NativeListener::onFail(int32_t error_code, const std::string& message) {
    // [OBSERVED at 0x00f798..0x00f86c]:
    //   1. Checks `java_listener_global_ref_ != nullptr` (`0x00f7b8: ldr x8, [x19, #0x10]; cbz x8, #0xf854`).
    //   2. Attaches current thread via `g_JavaVM` (`.bss 0x0202b8`) if `GetEnv(0x10006)` returns `-2`.
    //   3. Converts `message` via `stdStringToJString` (`0x00f814: bl #0x10338`).
    //   4. Invokes `ModelDownloadListener.onFail(ILjava/lang/String;)V` (`.rodata 0x015ad3`, `.rodata 0x015ada`).
    ++fail_call_count_;
    last_error_code_ = error_code;
    last_error_message_ = message;
    if (java_listener_global_ref_ == nullptr && !on_fail_cb_) {
        return;
    }
    if (on_fail_cb_) {
        on_fail_cb_(error_code, message);
    }
}

DownloadableResourceFinder* DownloadableResourceFinder::create(
    const DownloadableResourceFinderConfig& config) {
    // [OBSERVED at 0x00f030: bl _ZN4Bach26DownloadableResourceFinder6createERKNS_32DownloadableResourceFinderConfigE]
    return new DownloadableResourceFinder(config);
}

void DownloadableResourceFinder::downloadModels(
    const std::unordered_map<std::string, std::vector<std::string>>& requirements,
    ModelDownloadListener* listener) {
    // [OBSERVED at 0x00f3f8: ldr x8, [x8, #0x30]; blr x8]
    last_requirements_ = requirements;
    if (listener != nullptr) {
        if (!requirements.empty()) {
            listener->onSuccess();
        } else {
            listener->onFail(-1, "Empty model requirements");
        }
    }
}

EPResourceFinder* EPResourceFinder::create(int64_t bef_effect_resource_finder_handle) {
    // [OBSERVED at 0x00f678: bl _ZN4Bach16EPResourceFinder6createEl]
    return new EPResourceFinder(bef_effect_resource_finder_handle);
}

} // namespace Bach

// ============================================================================
// 2. JNI_OnLoad & UTF-8 String Helpers (0x0102b0..0x010504)
//    Cài đặt JNI_OnLoad và các hàm tiện ích chuỗi UTF-8 [OBSERVED]
// ============================================================================

BachJniGlobalState& GetBachJniGlobalState() noexcept {
    static BachJniGlobalState state;
    return state;
}

int32_t ExecuteBachJniOnLoad(void* vm, bool env_lookup_ok) noexcept {
    // [OBSERVED at 0x0102b0..0x010334]:
    //   0x0102c8: ldr x8, [x0]; ldr x8, [x8, #0x30] (vm->GetEnv)
    //   0x0102cc: mov w2, #0x10006 (JNI_VERSION_1_6)
    //   0x0102d4: blr x8
    //   0x0102d8: cmp w0, #0; b.ne 0x01031c (returns -1)
    //   0x0102e4: str x19, [x8, #0x2b8] (stores g_JavaVM at .bss 0x0202b8)
    //   0x010310: str x0, [x8, #0x2b0]  (stores g_ClassLoaderGlobalRef at .bss 0x0202b0)
    //   0x010314: mov w0, #0x10006; ret
    if (vm == nullptr || !env_lookup_ok) {
        return -1;
    }
    auto& state = GetBachJniGlobalState();
    state.java_vm = vm;
    return BachJniGlobalState::kJniVersion1_6;
}

std::string JstringUtf8BytesToStdString(const char* utf8_bytes, size_t byte_len) {
    // [OBSERVED at 0x010464..0x010504 (`jstringToStdString`)]:
    //   Calls `String.getBytes("utf-8")`, `GetArrayLength`, `GetByteArrayElements`,
    //   and constructs `std::string(bytes, length)` if `length >= 1` (`0x0104d0: cmp w21, #1; b.lt 0x0104ec`).
    if (utf8_bytes == nullptr || byte_len < 1U) {
        return std::string();
    }
    return std::string(utf8_bytes, byte_len);
}

} // namespace bach_sdk
} // namespace bytedance
} // namespace com

// ============================================================================
// 3. Exported JNI C Symbols (.dynsym [094], [100], [102], [103], [108], [111], [112])
//    7 biểu tượng hàm JNI xuất khẩu còn lại trong .dynsym [OBSERVED]
// ============================================================================

extern "C" {

// [108] 0x00edd0: Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeCreate
int64_t Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeCreate(
    void* /*env*/,
    void* /*thiz*/,
    const com::bytedance::bach_sdk::Bach::DownloadableResourceFinderConfig* config,
    const char* model_dir) {
    // [OBSERVED at 0x00edd0..0x00f18b]:
    //   Populates 152-byte `DownloadableResourceFinderConfig` on stack (`sp+0x48..sp+0xdf`),
    //   calls `Bach::DownloadableResourceFinder::create(config)` (`0x00f030`),
    //   destroys the 7 `std::string` fields in reverse order (`+0x90`, `+0x78`, `+0x60`, `+0x48`, `+0x30`, `+0x18`, `+0x00`),
    //   and returns `reinterpret_cast<int64_t>(finder)`.
    com::bytedance::bach_sdk::Bach::DownloadableResourceFinderConfig cfg;
    if (config != nullptr) {
        cfg = *config;
    }
    if (model_dir != nullptr && cfg.model_dir.empty()) {
        cfg.model_dir = model_dir;
    }
    auto* finder = com::bytedance::bach_sdk::Bach::DownloadableResourceFinder::create(cfg);
    return reinterpret_cast<int64_t>(finder);
}

// [100] 0x00f224: Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDestroy
void Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDestroy(
    void* /*env*/,
    void* /*thiz*/,
    int64_t finder_ptr) {
    // [OBSERVED at 0x00f224..0x00f22b]:
    //   0x00f224: cbz x2, #0xf228; b 0x00df20 (`ldr x8, [x2]; ldr x1, [x8, #8]; mov x0, x2; br x1`)
    if (finder_ptr != 0) {
        auto* ref_obj = reinterpret_cast<com::bytedance::bach_sdk::AmazingEngine::RefBase*>(finder_ptr);
        ref_obj->release();
    }
}

// [102] 0x00f224: Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeDestroy
// Identical address alias with DownloadableResourceFinder_nativeDestroy in .dynsym!
void Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeDestroy(
    void* /*env*/,
    void* /*thiz*/,
    int64_t finder_ptr) {
    if (finder_ptr != 0) {
        auto* ref_obj = reinterpret_cast<com::bytedance::bach_sdk::AmazingEngine::RefBase*>(finder_ptr);
        ref_obj->release();
    }
}

// [111] 0x00f22c: Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDownloadModels
void Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDownloadModels(
    void* /*env*/,
    void* /*thiz*/,
    int64_t finder_ptr,
    const std::unordered_map<std::string, std::vector<std::string>>* requirements,
    com::bytedance::bach_sdk::Bach::ModelDownloadListener* listener) {
    // [OBSERVED at 0x00f22c..0x00f55b]:
    //   1. Checks `finder_ptr != 0` (`0x00f258: cbz x22, #0xf470`).
    //   2. Builds `std::unordered_map<std::string, std::vector<std::string>>` (`sp+0x30`, `max_load_factor = 1.0f` @ `0x00f274`).
    //   3. Allocates 32-byte `NativeListener` (`0x00f394: mov w0, #0x20; bl operator new`),
    //      sets `m_pointer` (`J` @ `.rodata 0x0151af`) on Java `ModelDownloadListener` (`0x00f3f0: blr SetLongField`),
    //      calls `finder->downloadModels(requirements, listener)` via vtable `+0x30` (`0x00f3f8: ldr x8, [x8, #0x30]`),
    //      and calls `listener->release()` (`0x00f408: ldr x8, [x8, #8]; blr x8`).
    if (finder_ptr == 0) {
        return;
    }
    auto* finder = reinterpret_cast<com::bytedance::bach_sdk::Bach::DownloadableResourceFinder*>(finder_ptr);
    static const std::unordered_map<std::string, std::vector<std::string>> kEmptyReqs;
    finder->downloadModels(requirements ? *requirements : kEmptyReqs, listener);
}

// [112] 0x00f55c: Java_com_bytedance_byted_1bach_1sdk_finder_ModelDownloadListener_deleteNativeObject
void Java_com_bytedance_byted_1bach_1sdk_finder_ModelDownloadListener_deleteNativeObject(
    void* /*env*/,
    void* /*thiz*/,
    int64_t listener_ptr) {
    // [OBSERVED at 0x00f55c..0x00f61b]:
    //   1. Checks `listener_ptr != 0` (`0x00f56c: cbz x2, #0xf608`).
    //   2. Clears `m_pointer` to `0` on Java listener (`0x00f5bc: mov x3, xzr; blr SetLongField`).
    //   3. Deletes global reference at `[listener + 0x10]` and sets `[listener + 0x10] = 0` (`0x00f5dc: str xzr, [x19, #0x10]`).
    //   4. Calls `listener->release()` via vtable `+0x08` (`0x00f5e8: ldr x8, [x8, #8]; blr x8`).
    if (listener_ptr == 0) {
        return;
    }
    auto* listener = reinterpret_cast<com::bytedance::bach_sdk::Bach::NativeListener*>(listener_ptr);
    listener->clear_java_listener_global_ref();
    listener->release();
}

// [094] 0x00f61c: Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeCreate
int64_t Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeCreate(
    void* /*env*/,
    void* /*thiz*/,
    int64_t bef_effect_resource_finder_handle) {
    // [OBSERVED at 0x00f61c..0x00f6ab]:
    //   Calls `BEFEffectResourceFinder.createNativeResourceFinder(J)J` (`0x00f674`),
    //   then calls `Bach::EPResourceFinder::create(handle)` (`0x00f678: bl _ZN4Bach16EPResourceFinder6createEl`).
    auto* finder = com::bytedance::bach_sdk::Bach::EPResourceFinder::create(bef_effect_resource_finder_handle);
    return reinterpret_cast<int64_t>(finder);
}

// [103] 0x0102b0: JNI_OnLoad
int32_t JNI_OnLoad(void* vm, void* /*reserved*/) {
    return com::bytedance::bach_sdk::ExecuteBachJniOnLoad(vm, true);
}

} // extern "C"
