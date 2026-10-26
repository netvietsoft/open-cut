/**
 * @file iesapplogger_reporter_jni.cpp
 * @brief Exact Implementation of AppLogReporter Singleton & JNI Bridge for libiesapplogger.so
 *        Triển khai Chính xác Singleton AppLogReporter & Cầu nối JNI cho libiesapplogger.so
 *
 * Reconstructed from .text addresses 0x003eac..0x004a18, 0x004c70..0x005378.
 * Tái dựng từ các địa chỉ .text 0x003eac..0x004a18, 0x004c70..0x005378.
 */

#include "iesapplogger_reporter_jni.h"
#include <cstring>
#include <memory>
#include <mutex>

namespace iesapplogger {

// ============================================================================
// 1. Simulated .bss Globals (0x014010..0x014048) (OBSERVED)
//    Các biến Toàn cục .bss Mô phỏng (0x014010..0x014048) (QUAN SÁT TRỰC TIẾP)
// ============================================================================

// .dynsym [053] gJvm @ 0x014010
MockJavaVM* gJvm = nullptr;

namespace {

// 0x014018: AppLogReporter* sReporterSingleton
AppLogReporter* gReporterSingleton = nullptr;

// 0x014020: std::once_flag sReporterOnceFlag
std::once_flag gReporterOnceFlag;

// 0x014028: jmethodID gAppLogOnEventMethodId
jmethodID gAppLogOnEventMethodId = reinterpret_cast<jmethodID>(0x1028);

// 0x014030: jobject gIesAppLoggerInstance
jobject gIesAppLoggerInstance = reinterpret_cast<jobject>(0x1030);

// 0x014038: jclass gJavaLangStringClass
jclass gJavaLangStringClass = reinterpret_cast<jclass>(0x1038);

// 0x014040: jmethodID gJavaLangStringCtorMethodId
jmethodID gJavaLangStringCtorMethodId = reinterpret_cast<jmethodID>(0x1040);

// 0x014048: uint8_t gJniIdsInitialized
bool gJniIdsInitialized = false;

}  // namespace

// ============================================================================
// 2. MockJavaVM & MockJNIEnv Definition for Deterministic Verification
//    Định nghĩa MockJavaVM & MockJNIEnv để Xác minh Tất định
// ============================================================================
struct MockJNIEnv {
    bool exception_pending = false;
    uint64_t events_dispatched = 0;
    std::string last_app_id;
    std::string last_event_name;
    std::string last_params_json;
    bool last_report_to_business = false;
};

struct MockJavaVM {
    MockJNIEnv env;
    bool thread_attached = true;
    uint32_t attach_calls = 0;
    uint32_t detach_calls = 0;

    jint GetEnv(void** out_env, jint version) noexcept {
        if (version != kJniVersion1_6 || !thread_attached) {
            *out_env = nullptr;
            return kJniErr;
        }
        *out_env = &env;
        return kJniOk;
    }

    jint AttachCurrentThread(MockJNIEnv** out_env, void* /*args*/) noexcept {
        thread_attached = true;
        attach_calls += 1U;
        *out_env = &env;
        return kJniOk;
    }

    jint DetachCurrentThread() noexcept {
        thread_attached = false;
        detach_calls += 1U;
        return kJniOk;
    }
};

// ============================================================================
// 3. _Z6getEnvPi (0x003eac..0x003f5c) & JNI_OnLoad (0x003f60..0x004128)
//    Hàm lấy JNIEnv* (0x003eac..0x003f5c) & JNI_OnLoad (0x003f60..0x004128)
// ============================================================================

/**
 * @brief Reconstructs `_Z6getEnvPi` at 0x003eac..0x003f5c (.dynsym [112]).
 *
 * Disassembly trace:
 *   0x003ecc: ldr x20, [x8]           ; x20 = gJvm (0x014010)
 *   0x003ed0: cbz x20, #0x3f24        ; if (!gJvm) return nullptr
 *   0x003ee4: mov w2, #0x10006        ; JNI_VERSION_1_6 (0x00010006)
 *   0x003eec: blr x8                  ; gJvm->GetEnv(&env, 0x00010006)
 *   0x003ef0: cbnz w0, #0x3f04        ; if (rc != JNI_OK) goto attach
 *   0x003ef8: mov w8, #1
 *   0x003efc: str w8, [x19]           ; *attached = 1 (already attached)
 *   0x003f04: ...                     ; gJvm->AttachCurrentThread(&env, nullptr)
 *   0x003f18: cbz w0, #0x3f30         ; if (rc == 0) *attached = 0 (newly attached)
 */
MockJNIEnv* getEnv(int* attached) noexcept {
    if (gJvm == nullptr) {
        return nullptr;
    }
    void* env_void = nullptr;
    if (gJvm->GetEnv(&env_void, kJniVersion1_6) == kJniOk) {
        if (attached != nullptr) {
            *attached = 1;
        }
        return static_cast<MockJNIEnv*>(env_void);
    }
    MockJNIEnv* env_attached = nullptr;
    if (gJvm->AttachCurrentThread(&env_attached, nullptr) == kJniOk) {
        if (attached != nullptr) {
            *attached = 0;
        }
        return env_attached;
    }
    return nullptr;
}

namespace {

/**
 * @brief Reconstructs `initJniIds(JNIEnv*)` at 0x00412c..0x0043bc.
 *        Caches `IESAppLogger.sharedInstance()`, `appLogOnEvent`, `java/lang/String`,
 *        and `String.<init>([BLjava/lang/String;)V`, then sets `0x014048` = 1.
 *        Tái dựng `initJniIds(JNIEnv*)` tại 0x00412c..0x0043bc.
 */
bool initJniIds(MockJNIEnv* env) noexcept {
    if (env == nullptr || env->exception_pending) {
        return false;
    }
    // 0x00413c: ldrb w8, [x8, #0x48]; tbnz w8, #0, #0x43b0
    if (gJniIdsInitialized) {
        return true;
    }
    // Simulated caching of:
    // 1. FindClass("com/bytedance/ies/common/IESAppLogger") @ 0x00c28c
    // 2. GetStaticMethodID("sharedInstance", "()Lcom/bytedance/ies/common/IESAppLogger;") @ 0x00c2b2
    // 3. GetMethodID("appLogOnEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V") -> 0x014028
    // 4. CallStaticObjectMethod + NewGlobalRef -> 0x014030
    // 5. FindClass("java/lang/String") + NewGlobalRef -> 0x014038
    // 6. GetMethodID("<init>", "([BLjava/lang/String;)V") -> 0x014040
    gAppLogOnEventMethodId      = reinterpret_cast<jmethodID>(0x1028);
    gIesAppLoggerInstance       = reinterpret_cast<jobject>(0x1030);
    gJavaLangStringClass        = reinterpret_cast<jclass>(0x1038);
    gJavaLangStringCtorMethodId = reinterpret_cast<jmethodID>(0x1040);
    gJniIdsInitialized          = true;
    return true;
}

}  // namespace

/**
 * @brief Reconstructs `JNI_OnLoad` at 0x003f60..0x004128 (.dynsym [109]).
 *        Tái dựng `JNI_OnLoad` tại 0x003f60..0x004128 (.dynsym [109]).
 */
jint JNI_OnLoad_Reconstructed(MockJavaVM* vm, void* /*reserved*/) {
    // 0x003f8c: str x0, [x8] (gJvm = vm)
    gJvm = vm;
    int attached = 0;
    MockJNIEnv* env = getEnv(&attached);

    // 0x003fac..0x003fcc: std::shared_ptr<int> thread detach guard (`Z10JNI_OnLoadE3$_0`, vtable 0x013ae0)
    // Deleter at 0x004c70: if (*p == 0 && gJvm != nullptr) gJvm->DetachCurrentThread()
    std::shared_ptr<int> detach_guard(&attached, [](int* p) {
        if (p != nullptr && *p == 0 && gJvm != nullptr) {
            gJvm->DetachCurrentThread();
        }
    });

    if (env == nullptr) {
        return kJniErr;
    }

    // 0x003fe0: bl #0x412c (initJniIds)
    // 0x003fe4..0x003ff0: tst w0, #1 ; mov w8, #-1 ; mov w9, #0x10006 ; csel w19, w9, w8, ne
    const bool ok = initJniIds(env);
    return ok ? kJniVersion1_6 : kJniErr;
}

// ============================================================================
// 4. charPtrToJString (0x005110..0x005230) & appLogFunc (0x004d3c..0x00510c)
//    Hàm chuyển đổi Chuỗi JNI (0x005110..0x005230) & appLogFunc (0x004d3c..0x00510c)
// ============================================================================

/**
 * @brief Reconstructs `charPtrToJString(JNIEnv*, const char*)` at 0x005110..0x005230.
 *        Creates a Java `byte[]` of length `strlen(str)`, copies bytes via `SetByteArrayRegion`,
 *        creates `NewStringUTF("utf-8")` (@ 0x00c457), and constructs `new String(bytes, "utf-8")`.
 *        Tái dựng `charPtrToJString(JNIEnv*, const char*)` tại 0x005110..0x005230.
 */
std::string charPtrToJString_Reconstructed(MockJNIEnv* env, const char* cstr) {
    if (env == nullptr || cstr == nullptr || env->exception_pending) {
        return std::string();
    }
    const size_t len = std::strlen(cstr);
    return std::string(cstr, len);
}

/**
 * @brief Reconstructs `appLogFunc(const char*, const char*, const char*, bool)` at 0x004d3c..0x00510c.
 *        Default callback stored at `AppLogReporter + 0x28` (@ 0x004d04).
 *        Tái dựng `appLogFunc` tại 0x004d3c..0x00510c.
 */
int appLogFunc(const char* app_id,
               const char* event_name,
               const char* params_json,
               bool report_to_business) {
    int attached = 0;
    MockJNIEnv* env = getEnv(&attached);

    // 0x004dd0..0x004df0: std::shared_ptr<int> thread detach guard (`ZL10appLogFuncPKcS3_S3_bE3$_2`, vtable 0x013b30)
    std::shared_ptr<int> detach_guard(&attached, [](int* p) {
        if (p != nullptr && *p == 0 && gJvm != nullptr) {
            gJvm->DetachCurrentThread();
        }
    });

    if (env == nullptr) {
        return 0;
    }
    if (!initJniIds(env)) {
        return 0;
    }

    // 0x004e0c..0x004e54: convert app_id, event_name, params_json via charPtrToJString (0x005110)
    env->last_app_id = charPtrToJString_Reconstructed(env, app_id);
    env->last_event_name = charPtrToJString_Reconstructed(env, event_name);
    env->last_params_json = charPtrToJString_Reconstructed(env, params_json);
    env->last_report_to_business = report_to_business;
    env->events_dispatched += 1ULL;

    // 0x004f0c: mov w20, #1 (returns 1 on successful JNI dispatch)
    return 1;
}

// ============================================================================
// 5. AppLogReporter Implementation (0x0043c0..0x0046e4)
//    Triển khai lớp AppLogReporter (0x0043c0..0x0046e4)
// ============================================================================

AppLogReporter::AppLogReporter() {
    // Matches `0x004cf0..0x004d24`:
    //   +0x00..+0x27: zero-initialized std::mutex (40 bytes)
    //   +0x28:        report_func = &appLogFunc (0x004d3c)
    //   +0x30:        enabled = 1 (true)
    //   +0x38..+0x4F: empty RbTreeSetHeaderAbi (`begin_node = &root_left`, `root_left = nullptr`, `node_count = 0`)
    std::memset(abi_.mutex_storage, 0, sizeof(abi_.mutex_storage));
    abi_.report_func = &appLogFunc;
    abi_.enabled = true;
    std::memset(abi_.pad_31, 0, sizeof(abi_.pad_31));
    rbtree_init(&abi_.sampler_set);
}

AppLogReporter::~AppLogReporter() {
    rbtree_clear(&abi_.sampler_set);
}

AppLogReporter* AppLogReporter::GetSingleton() {
    // Matches `_ZN14AppLogReporter12GetSingletonEv` @ 0x0043c0..0x00443c (.dynsym [090])
    std::call_once(gReporterOnceFlag, []() {
        gReporterSingleton = new AppLogReporter();
    });
    return gReporterSingleton;
}

int AppLogReporter::report(const char* app_id,
                           const char* event_name,
                           const char* params_json,
                           bool report_to_business) {
    // Matches `_ZN14AppLogReporter6reportEPKcS1_S1_b` @ 0x004440..0x004534 (.dynsym [065]):
    //   0x004464: ldrb w8, [x0, #0x30]
    //   0x00446c: tbz  w8, #0, #0x4504  ; if (!enabled_) return 0
    if (!abi_.enabled) {
        return 0;
    }

    //   0x004474: ldr  x8, [x0, #0x48]  ; sampler_set_.node_count
    //   0x004478: cbz  x8, #0x44d8      ; if (sampler_set_.empty()) goto invoke
    if (abi_.sampler_set.node_count != 0) {
        LibcppSsoStringAbi key_str;
        sso_string_init_empty(&key_str);
        if (event_name != nullptr) {
            sso_string_assign(&key_str, event_name, std::strlen(event_name));
        }
        const auto* end_node = reinterpret_cast<const RbTreeNodeStringAbi*>(&abi_.sampler_set.root_left);
        const RbTreeNodeStringAbi* found = rbtree_find(&abi_.sampler_set, &key_str);
        sso_string_destroy(&key_str);

        // 0x0044a0..0x0044a4: cmp x24, x25 ; b.eq #0x4504 (not in sampler whitelist -> return 0)
        if (found == end_node) {
            return 0;
        }
    }

    //   0x0044ac..0x0044fc:
    //   ldr x8, [x19, #0x28] ; cbz x8, #0x4504
    //   bl _ZNSt6__ndk15mutex4lockEv
    //   blr x8 (report_func(app_id, event_name, params_json, report_to_business))
    //   bl _ZNSt6__ndk15mutex6unlockEv
    if (abi_.report_func == nullptr) {
        return 0;
    }
    std::lock_guard<std::mutex> lock(host_mutex_);
    return abi_.report_func(app_id, event_name, params_json, report_to_business);
}

bool AppLogReporter::isSampled(const std::string& event_name) {
    // Matches `_ZN14AppLogReporter9isSampledERK...` @ 0x004538..0x0045c4 (.dynsym [122]):
    //   1. Locks `mutex_` (+0x00)
    //   2. Checks `enabled_` (+0x30): if 0, returns false
    //   3. Checks `sampler_set_.node_count` (+0x48): if 0, returns true
    //   4. Calls `__tree::find(&sampler_set_, event_name)`: returns (found != end_node)
    //   5. Unlocks `mutex_`
    std::lock_guard<std::mutex> lock(host_mutex_);
    if (!abi_.enabled) {
        return false;
    }
    if (abi_.sampler_set.node_count == 0) {
        return true;
    }
    LibcppSsoStringAbi key_str;
    sso_string_init_empty(&key_str);
    sso_string_assign(&key_str, event_name.data(), event_name.size());
    const auto* end_node = reinterpret_cast<const RbTreeNodeStringAbi*>(&abi_.sampler_set.root_left);
    const RbTreeNodeStringAbi* found = rbtree_find(&abi_.sampler_set, &key_str);
    sso_string_destroy(&key_str);
    return found != end_node;
}

void AppLogReporter::setReportFunc(AppLogReportCallback func) noexcept {
    // Matches `_ZN14AppLogReporter13setReportFuncEPFiPKcS1_S1_bE` @ 0x0045c8..0x0045cc (.dynsym [116]):
    //   0x0045c8: f9001401 str x1, [x0, #0x28]
    //   0x0045cc: d65f03c0 ret
    abi_.report_func = func;
}

void AppLogReporter::setSamplerAbi(const RbTreeSetHeaderAbi& new_sampler) {
    // Matches `setSampler` @ 0x0045d0..0x0046e4:
    //   Locks `mutex_`, copies `new_sampler` into `abi_.sampler_set`, unlocks `mutex_`
    std::lock_guard<std::mutex> lock(host_mutex_);
    rbtree_copy_assign(&abi_.sampler_set, &new_sampler);
}

void AppLogReporter::setSampler(const std::set<std::string>& events) {
    RbTreeSetHeaderAbi temp_set;
    rbtree_init(&temp_set);
    for (const std::string& ev : events) {
        LibcppSsoStringAbi sso_ev;
        sso_string_init_empty(&sso_ev);
        sso_string_assign(&sso_ev, ev.data(), ev.size());
        rbtree_emplace_unique(&temp_set, &sso_ev);
        sso_string_destroy(&sso_ev);
    }
    setSamplerAbi(temp_set);
    rbtree_clear(&temp_set);
}

void AppLogReporter::setEnabled(bool enabled) noexcept {
    abi_.enabled = enabled;
}

bool AppLogReporter::isEnabled() const noexcept {
    return abi_.enabled;
}

// ============================================================================
// 6. Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler (0x0046e8..0x004a18)
//    Triển khai hàm JNI nativeSetSampler (0x0046e8..0x004a18)
// ============================================================================

void Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler_Reconstructed(
    MockJNIEnv* /*env*/,
    jobject /*thiz*/,
    const std::vector<std::string>& java_sampler_set) {
    // Matches 0x0046e8..0x004a18 (.dynsym [099]):
    //   1. Initializes stack RbTreeSetHeaderAbi (`sp + 0x18..0x28`)
    //   2. Iterates Java `Set<String>` via `iterator()`, `hasNext()`, `next()`
    //   3. For each non-empty string, allocates a 56-byte (`0x38` @ 0x004888) RB-tree node
    //      and inserts it via `__find_equal` + `__insert_node_at`
    //   4. Calls `AppLogReporter::GetSingleton()->setSampler(stack_set)` (@ 0x004930)
    //   5. Destroys `stack_set` via `__tree::destroy` (@ 0x00493c)
    RbTreeSetHeaderAbi stack_set;
    rbtree_init(&stack_set);

    for (const std::string& item : java_sampler_set) {
        if (!item.empty()) {
            LibcppSsoStringAbi key;
            sso_string_init_empty(&key);
            sso_string_assign(&key, item.data(), item.size());
            rbtree_emplace_unique(&stack_set, &key);
            sso_string_destroy(&key);
        }
    }

    AppLogReporter::GetSingleton()->setSamplerAbi(stack_set);
    rbtree_clear(&stack_set);
}

}  // namespace iesapplogger
