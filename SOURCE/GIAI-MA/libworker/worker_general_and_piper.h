// ============================================================================
// File: worker_general_and_piper.h
// Target: libworker.so (313,400 bytes)
// Role: Clean-room C++17 declarations for vmsdk::general::* (JNI, MessageLoop,
//       MessagePumpPosix/Android, ThreadImplPosix/Android), CityHash64, and
//       vmsdk::piper::* (VmsdkModuleWrap, MethodInvoker, ModuleManagerAndroid).
// Vai trò: Khai báo C++17 cho vmsdk::general::* và cầu nối JSB vmsdk::piper::*.
// ============================================================================

#pragma once

#include "worker_types.h"
#include "worker_rodata_tables.h"

namespace vmsdk {

namespace general {
namespace android {

void InitVM(JavaVM* vm) noexcept;
JNIEnv* AttachCurrentThread() noexcept;
void DetachFromVM() noexcept;
ScopedLocalJavaRef<jclass> GetClass(JNIEnv* env, const char* class_name);
ScopedGlobalJavaRef<jclass> GetGlobalClass(JNIEnv* env, const char* class_name);
jmethodID GetMethod(JNIEnv* env, jclass clazz, MethodType type, const char* method_name, const char* jni_signature);
jmethodID GetMethod(JNIEnv* env, jclass clazz, MethodType type, const char* method_name, const char* jni_signature, intptr_t* method_id_cache);
bool HasException(JNIEnv* env) noexcept;
bool ClearException(JNIEnv* env) noexcept;
bool CheckException(JNIEnv* env);

} // namespace android
} // namespace general

namespace piper {

/**
 * EN: 64-bit Google CityHash64 implementation at 0x022d58..0x0231c4 (1,132 bytes)
 *     used for hashing JSB module and method names in VmsdkModuleWrap & ModuleManagerAndroid.
 * VN: Hàm băm 64-bit Google CityHash64 tại 0x022d58..0x0231c4 (1,132 byte).
 */
uint64_t ComputeCityHash64(const char* buf, size_t len) noexcept;

/**
 * EN: AArch64 NEON population-count bucket index selector (0x022a68..0x022aa0 & 0x0374b8..0x0374ec):
 *     cnt v0.8b, v0.8b; uaddlv h0, v0.8b -> if popcount(bucket_count) <= 1, uses (hash & (bucket_count - 1)),
 *     else uses (hash % bucket_count) via udiv + msub.
 * VN: Bộ chọn chỉ mục xô băm dùng lệnh đếm bit NEON cnt + uaddlv tại 0x022a68 & 0x0374b8.
 */
size_t ComputeHashBucketIndex(uint64_t hash, size_t bucket_count) noexcept;

class ModuleCallback {
public:
    int64_t callback_id_{0};
    explicit ModuleCallback(int64_t id) noexcept : callback_id_(id) {}
    virtual ~ModuleCallback() = default;
};

class ModuleCallbackAndroid : public ModuleCallback {
public:
    std::weak_ptr<class MethodInvoker> method_invoker_;
    jobject writable_array_ref_{nullptr};
    explicit ModuleCallbackAndroid(int64_t id) noexcept : ModuleCallback(id) {}
    ~ModuleCallbackAndroid() override = default;
};

class ModuleDelegate {
public:
    virtual ~ModuleDelegate() = default;
    virtual void CallJSCallback(const std::shared_ptr<ModuleCallback>& callback, int64_t callback_id) = 0;
    virtual void RunOnJSThread(std::function<void()> task) = 0;
    virtual void OnErrorOccurred(const std::string& module_name, const std::string& method_name, const std::string& error) = 0;
    virtual void Terminate() = 0;
};

class ModuleDelegateImpl : public ModuleDelegate {
public:
    std::shared_ptr<void> js_runtime_;
    std::weak_ptr<runtime::JSRuntimeDelegate> runtime_delegate_;
    std::atomic<bool> terminated_{false};

    ModuleDelegateImpl(std::shared_ptr<void> js_rt, std::weak_ptr<runtime::JSRuntimeDelegate> rt_del);
    ~ModuleDelegateImpl() override;
    void CallJSCallback(const std::shared_ptr<ModuleCallback>& callback, int64_t callback_id) override;
    void RunOnJSThread(std::function<void()> task) override;
    void OnErrorOccurred(const std::string& module_name, const std::string& method_name, const std::string& error) override;
    void Terminate() override;
};

class VmsdkModule {
public:
    struct MethodMetadata {
        std::string name;
        size_t arg_count{0};
        MethodMetadata(std::string n, size_t c) : name(std::move(n)), arg_count(c) {}
    };
    virtual ~VmsdkModule() = default;
    virtual std::string getName() const = 0;
    virtual void Destroy() = 0;
};

class MethodInvoker : public std::enable_shared_from_this<MethodInvoker> {
public:
    jmethodID method_id_{nullptr};
    std::string signature_;
    std::string module_name_;
    std::string method_name_;
    char return_type_{'V'};

    MethodInvoker(jmethodID mid, std::string sig, std::string mod_name, std::string fn_name);
    ~MethodInvoker() = default;
    bool VerifySignature() const noexcept;
    void InvokeCallback(const std::shared_ptr<ModuleCallbackAndroid>& cb);
};

class VmsdkModuleAndroid : public VmsdkModule {
public:
    std::string name_;
    general::android::ScopedWeakGlobalJavaRef<jobject> wrapper_ref_;
    std::unordered_map<std::string, std::shared_ptr<MethodInvoker>> method_invokers_;

    VmsdkModuleAndroid(JNIEnv* env, jobject module_wrapper, std::shared_ptr<ModuleDelegate> delegate);
    ~VmsdkModuleAndroid() override;
    std::string getName() const override { return name_; }
    void Destroy() override;
};

class ModuleManagerAndroid {
public:
    general::android::ScopedGlobalJavaRef<jobject> java_module_manager_;
    std::unordered_map<std::string, std::shared_ptr<VmsdkModuleAndroid>> module_map_;
    std::shared_ptr<ModuleDelegate> delegate_;

    ModuleManagerAndroid(JNIEnv* env, jobject module_manager_obj);
    virtual ~ModuleManagerAndroid();
    std::shared_ptr<VmsdkModule> getModule(const std::string& name);
};

} // namespace piper
} // namespace vmsdk
