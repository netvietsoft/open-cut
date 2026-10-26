// ============================================================================
// File: lynx_v8_napi_observer_jni.h
// Target: liblynx_v8_bridge.so (0x0133a0..0x013bec)
// Description:
//   [EN] Exported lynx::base::ObserverList (`0x0133a0..0x01358c`),
//        JNI_OnLoad (`0x013590..0x013618`), LynxRuntimeHelperV8 (`0x01361c..0x013954`),
//        and NapiRuntimeProxyV8 / NapiRuntimeProxyV8Factory (`0x013958..0x013bec`).
//   [VN] Lớp xuất khẩu lynx::base::ObserverList (`0x0133a0..0x01358c`),
//        JNI_OnLoad (`0x013590..0x013618`), LynxRuntimeHelperV8 (`0x01361c..0x013954`),
//        và NapiRuntimeProxyV8 / NapiRuntimeProxyV8Factory (`0x013958..0x013bec`).
// ============================================================================

#pragma once

#include "lynx_v8_bridge_types.h"
#include "lynx_v8_runtime.h"
#include <cstdint>
#include <memory>
#include <string>

namespace lynx {
namespace piper {

// ============================================================================
// [EN] 1. NapiRuntimeProxyV8 (`88 bytes = 0x58`, vtable @ `0x018880`)
//      Reconstructed from `0x013958..0x013bec`.
// [VN] 1. NapiRuntimeProxyV8 (`88 bytes = 0x58`, vtable tại `0x018880`)
//      Tái dựng từ `0x013958..0x013bec`.
// ============================================================================
class NapiRuntimeProxyV8 {
public:
    explicit NapiRuntimeProxyV8(void* template_delegate,
                                std::weak_ptr<V8ContextWrapperImpl> context_wrapper);
    virtual ~NapiRuntimeProxyV8();

    // Disassembly @ `0x01399c..0x013a28` (`napi_attach_v8`)
    bool Attach();

    // Disassembly @ `0x013a2c..0x013a70` (`NapiRuntimeProxy::Detach` + `napi_detach_v8`)
    void Detach();

    // Disassembly @ `0x013a74..0x013ad4`
    void SetContextWrapper(std::shared_ptr<V8ContextWrapperImpl> wrapper);
    std::shared_ptr<V8ContextWrapperImpl> GetContextWrapper() const;

    bool is_attached() const noexcept { return is_attached_; }
    void* napi_env_handle() const noexcept { return napi_env_; }

private:
    void* napi_env_{nullptr};                                  // +0x08
    void* template_delegate_{nullptr};                         // +0x10
    std::shared_ptr<V8ContextWrapperImpl> strong_context_;     // +0x20..0x2f
    std::weak_ptr<V8ContextWrapperImpl> weak_context_;         // +0x48..0x57
    bool is_attached_{false};
};

// ============================================================================
// [EN] 2. NapiRuntimeProxyV8FactoryImpl (instance @ `0x01c008`, vtable @ `0x018868`)
//      Reconstructed from `0x013ad8..0x013bec`.
// [VN] 2. NapiRuntimeProxyV8FactoryImpl (thể hiện tại `0x01c008`, vtable tại `0x018868`)
//      Tái dựng từ `0x013ad8..0x013bec`.
// ============================================================================
class NapiRuntimeProxyV8FactoryImpl {
public:
    virtual ~NapiRuntimeProxyV8FactoryImpl() = default;

    // Disassembly @ `0x013ad8..0x013bec`:
    //   Allocates `88` bytes (`0x58` @ `0x013b5c`), initializes `NapiRuntimeProxy`,
    //   and binds `weak_ptr<V8ContextWrapperImpl>` at `+0x48`.
    virtual std::unique_ptr<NapiRuntimeProxyV8> Create(
        const std::shared_ptr<V8Runtime>& runtime,
        void* template_delegate = nullptr);
};

} // namespace piper

namespace runtime {

// ============================================================================
// [EN] 3. LynxRuntimeHelperV8 (instance @ `0x01c000`, vtable @ `0x018850`)
//      Reconstructed from `0x01361c..0x013954`.
// [VN] 3. LynxRuntimeHelperV8 (thể hiện tại `0x01c000`, vtable tại `0x018850`)
//      Tái dựng từ `0x01361c..0x013954`.
// ============================================================================
class LynxRuntimeHelperV8 {
public:
    virtual ~LynxRuntimeHelperV8() = default;

    // Vtable slot +0x00 -> `0x01361c..0x013714`:
    //   Allocates `352`-byte (`0x160`) `lynx::piper::V8Runtime` instance.
    virtual std::unique_ptr<piper::V8Runtime> MakeRuntime();

    // Vtable slot +0x08 -> `0x013718..0x013954`:
    //   Creates or reuses thread-local V8 Isolate + Inspector session (`"lynx"` @ `0x006702`).
    virtual std::shared_ptr<piper::V8ContextWrapperImpl> MakeVM(
        int64_t max_heap_size_bytes = 0);
};

// ============================================================================
// [EN] 4. JNI_OnLoad Bridge Registration State (`0x013590..0x013618`)
// [VN] 4. Trạng thái đăng ký cầu nối JNI_OnLoad (`0x013590..0x013618`)
// ============================================================================
struct JniV8BridgeState {
    static constexpr int32_t kJniVersion1_6 = 0x00010006; // mov w0, #6; movk w0, #1, lsl #16

    static int32_t ExecuteJniOnLoad(void* java_vm, void* reserved) noexcept;
    static bool IsExternalRuntimeHelperRegistered() noexcept;
    static bool IsV8RuntimeProxyFactoryRegistered() noexcept;
    static LynxRuntimeHelperV8* GetRegisteredRuntimeHelper() noexcept;
    static piper::NapiRuntimeProxyV8FactoryImpl* GetRegisteredNapiFactory() noexcept;
};

} // namespace runtime
} // namespace lynx
