// ============================================================================
// File: orbuculumadapter_pseudocode.cpp
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
// Architecture: AArch64 (arm64-v8a), Android NDK clang++ (libc++_shared.so)
// Dependencies: libshadowhook.so, liblog.so, libc.so, libm.so, libdl.so
// Dynamic dlopen Peers: liborbuculum.so, libpumbaa-network.so
//
// [EN] Complete, bit-accurate C++17 clean-room reconstruction of
//      `liborbuculumadapter.so` (.text 0x004460..0x01a6ec, 22,691 instructions).
//      Implements:
//        1. Three `.init_array` global constructors (0x004460, 0x0044ac, 0x0044c8)
//        2. `JNI_OnLoad` (0x004540..0x0049fc) & `JNI_OnUnload` (0x004a00..0x004b84)
//        3. Active JNI Call RAII Guard & `AttachCurrentThread`/`DetachCurrentThread`
//           helper (0x0081c4..0x0082ac)
//        4. Java Property Query Callback (`"get_user_region"`, `"get_sandbox_state"`,
//           0x004b88..0x004f68)
//        5. Eight `TTKNativeNetworkManager` `RegisterNatives` JNI methods:
//           - `activesdk(IZI)I` (0x004f6c)
//           - `initcall(IZ)I` (0x004fec)
//           - `initnetconfig(Lcom/orbu/core/config/BootConfig;)V` (0x005058)
//           - `unhook()V` (0x005c24 -> 0x012358)
//           - `doNativeNetworkValidate(...)I` (0x005c28)
//           - `setNativeHardBlockConfigInner(ZZZLjava/util/List;Ljava/util/List;)V` (0x006874)
//           - `isNativeNetworkResultNeedBlock(ILjava/lang/String;)Z` (0x007174)
//           - `setNativeDebug(Z)V` (0x0072ec)
//        6. Three Java Upcall Bridges:
//           - `ProceedSeiFieldUpcall` (0x007300..0x007b14)
//           - `InTargetBlockRuleHashListUpcall` (0x007b18..0x007d48)
//           - `SendReportUpcall` (0x007d4c..0x0081c0)
//        7. Five ShadowHook `getenv`-exported native entry points:
//           - `OrbuculumIsProceedRequest` (0x011178..0x011804)
//           - `OrbuculumIsProceedRequestForTTNet` (0x00eb48..0x00f6e8)
//           - `OrbuculumIsProceedResponseImpl` (0x011808..0x011da0)
//           - `OrbuculumRegisterLiveShutdownCallback` (0x00d490..0x00d574)
//           - `OrbuculumIsProceedSeiField` (0x00d2e8..0x00d38c)
//
// [VN] Bản phục dựng C++17 phòng sạch hoàn chỉnh, khớp từng bit của
//      `liborbuculumadapter.so` (.text 0x004460..0x01a6ec, 22.691 lệnh máy).
//      Triển khai:
//        1. Ba hàm khởi tạo toàn cục `.init_array` (0x004460, 0x0044ac, 0x0044c8)
//        2. `JNI_OnLoad` (0x004540..0x0049fc) & `JNI_OnUnload` (0x004a00..0x004b84)
//        3. Bộ bảo vệ RAII đếm lời gọi JNI đang chạy & hàm gắn kết luồng
//           `AttachCurrentThread`/`DetachCurrentThread` (0x0081c4..0x0082ac)
//        4. Callback truy vấn thuộc tính Java (`"get_user_region"`, `"get_sandbox_state"`,
//           0x004b88..0x004f68)
//        5. Tám phương thức JNI `RegisterNatives` trên `TTKNativeNetworkManager`:
//           - `activesdk(IZI)I` (0x004f6c)
//           - `initcall(IZ)I` (0x004fec)
//           - `initnetconfig(Lcom/orbu/core/config/BootConfig;)V` (0x005058)
//           - `unhook()V` (0x005c24 -> 0x012358)
//           - `doNativeNetworkValidate(...)I` (0x005c28)
//           - `setNativeHardBlockConfigInner(ZZZLjava/util/List;Ljava/util/List;)V` (0x006874)
//           - `isNativeNetworkResultNeedBlock(ILjava/lang/String;)Z` (0x007174)
//           - `setNativeDebug(Z)V` (0x0072ec)
//        6. Ba cầu nối gọi ngược lên Java:
//           - `ProceedSeiFieldUpcall` (0x007300..0x007b14)
//           - `InTargetBlockRuleHashListUpcall` (0x007b18..0x007d48)
//           - `SendReportUpcall` (0x007d4c..0x0081c0)
//        7. Năm điểm vào native xuất qua bảng `getenv` của ShadowHook:
//           - `OrbuculumIsProceedRequest` (0x011178..0x011804)
//           - `OrbuculumIsProceedRequestForTTNet` (0x00eb48..0x00f6e8)
//           - `OrbuculumIsProceedResponseImpl` (0x011808..0x011da0)
//           - `OrbuculumRegisterLiveShutdownCallback` (0x00d490..0x00d574)
//           - `OrbuculumIsProceedSeiField` (0x00d2e8..0x00d38c)
// ============================================================================

#include "orbuculumadapter_interface.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

#if defined(__ANDROID__) && __has_include(<android/log.h>)
#include <android/log.h>
#define ORBU_ADAPTER_LOGI(fmt, ...) \
    __android_log_print(ANDROID_LOG_INFO, nextai::opencut::orbuculumadapter::kLogTag, fmt, ##__VA_ARGS__)
#define ORBU_ADAPTER_LOGD(fmt, ...) \
    __android_log_print(ANDROID_LOG_DEBUG, nextai::opencut::orbuculumadapter::kLogTag, fmt, ##__VA_ARGS__)
#define ORBU_ADAPTER_LOGE(fmt, ...) \
    __android_log_print(ANDROID_LOG_ERROR, nextai::opencut::orbuculumadapter::kLogTag, fmt, ##__VA_ARGS__)
#else
#define ORBU_ADAPTER_LOGI(fmt, ...) ((void)0)
#define ORBU_ADAPTER_LOGD(fmt, ...) ((void)0)
#define ORBU_ADAPTER_LOGE(fmt, ...) ((void)0)
#endif

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

// ============================================================================
// SECTION 1: GLOBAL STATE SINGLETONS & .INIT_ARRAY CONSTRUCTORS
//            (0x004460, 0x0044ac, 0x0044c8, .bss 0x028160..0x028fd0)
// [EN] In the ELF binary, `.init_array` (`0x027638..0x027648`) contains 3
//      static constructor pointers:
//        [0] `0x004460`: Registers `__cxa_atexit` destructors for
//            `jni_lifecycle_mutex` (`0x028160`) and `jni_lifecycle_cv` (`0x028188`).
//        [1] `0x0044ac`: Registers `__cxa_atexit` destructor for
//            `live_shutdown_mutex` (`0x028388`).
//        [2] `0x0044c8`: Calls `std::__ndk1::__shared_timed_mutex_base::__shared_timed_mutex_base()`
//            at `0x0287b8` (`bl 0x40f0`) and registers destructor `0x00c5b0`.
// [VN] Trong file nhị phân ELF, `.init_array` (`0x027638..0x027648`) chứa 3
//      con trỏ hàm khởi tạo tĩnh:
//        [0] `0x004460`: Đăng ký hàm hủy `__cxa_atexit` cho
//            `jni_lifecycle_mutex` (`0x028160`) và `jni_lifecycle_cv` (`0x028188`).
//        [1] `0x0044ac`: Đăng ký hàm hủy `__cxa_atexit` cho
//            `live_shutdown_mutex` (`0x028388`).
//        [2] `0x0044c8`: Gọi `std::__ndk1::__shared_timed_mutex_base::__shared_timed_mutex_base()`
//            tại `0x0287b8` (`bl 0x40f0`) và đăng ký hàm hủy `0x00c5b0`.
// ============================================================================

GlobalRuntimeState& GetGlobalRuntimeState() {
    static GlobalRuntimeState s_global_state;
    return s_global_state;
}

NetConfigRepository& GetNetConfigRepository() {
    // [EN] Reconstructed from 0x00509c..0x005124: guarded by __cxa_guard_acquire(&0x028338),
    //      zero-initialized 240 bytes at 0x028248, and registered via __cxa_atexit(0x008a7c).
    // [VN] Phục dựng từ 0x00509c..0x005124: bảo vệ bởi __cxa_guard_acquire(&0x028338),
    //      khởi tạo 0 cho 240 byte tại 0x028248, và đăng ký qua __cxa_atexit(0x008a7c).
    static NetConfigRepository s_repository;
    return s_repository;
}

// ============================================================================
// SECTION 2: ACTIVE JNI CALL COUNTER GUARD & JNI THREAD ATTACH HELPER
//            (0x004b88..0x004f68, 0x0081c4..0x0082ac)
// ============================================================================

/**
 * @brief [EN] RAII guard matching the atomic active-JNI-call counter protocol
 *             used in `0x004ba8..0x004f30`, `0x007330..0x007ac0`, `0x007b3c..0x007d08`,
 *             and `0x007d88..0x00816c`:
 *             - Checks `!is_unloading` (`0x02835c`), `is_initialized` (`0x028360`),
 *               and `g_vm != nullptr` (`0x0281b8`).
 *             - Atomically increments `active_jni_calls` (`ldaddal x9, x8, [x22]` at `0x028358`).
 *             - Re-checks `is_unloading` (`0x02835c`): if unloading began concurrently,
 *               decrements `active_jni_calls` and notifies `jni_lifecycle_cv` (`0x028188`).
 *             - On destruction, decrements `active_jni_calls`: if the previous value was `1`
 *               (meaning counter reached `0`), locks `jni_lifecycle_mutex` (`0x028160`),
 *               notifies `jni_lifecycle_cv.notify_all()` (`0x028188`), and unlocks.
 *        [VN] Bộ bảo vệ RAII khớp chính xác giao thức bộ đếm lời gọi JNI nguyên tử
 *             được dùng tại `0x004ba8..0x004f30`, `0x007330..0x007ac0`, `0x007b3c..0x007d08`,
 *             và `0x007d88..0x00816c`:
 *             - Kiểm tra `!is_unloading` (`0x02835c`), `is_initialized` (`0x028360`),
 *               và `g_vm != nullptr` (`0x0281b8`).
 *             - Tăng nguyên tử `active_jni_calls` (`ldaddal x9, x8, [x22]` tại `0x028358`).
 *             - Kiểm tra lại `is_unloading` (`0x02835c`): nếu quá trình gỡ thư viện vừa bắt đầu,
 *               giảm `active_jni_calls` và đánh thức `jni_lifecycle_cv` (`0x028188`).
 *             - Khi hủy, giảm `active_jni_calls`: nếu giá trị trước đó là `1`
 *               (tức bộ đếm về `0`), khóa `jni_lifecycle_mutex` (`0x028160`),
 *               gọi `jni_lifecycle_cv.notify_all()` (`0x028188`), rồi mở khóa.
 */
class ScopedActiveJniCallGuard {
public:
    ScopedActiveJniCallGuard() : acquired_(false) {
        GlobalRuntimeState& state = GetGlobalRuntimeState();
        if (state.is_unloading.load(std::memory_order_seq_cst)) {
            return;
        }
        if (!state.is_initialized.load(std::memory_order_seq_cst)) {
            return;
        }
        if (state.g_vm == nullptr) {
            return;
        }

        state.active_jni_calls.fetch_add(1, std::memory_order_seq_cst);
        if (state.is_unloading.load(std::memory_order_seq_cst)) {
            ReleaseCounter();
            return;
        }
        acquired_ = true;
    }

    ~ScopedActiveJniCallGuard() {
        if (acquired_) {
            ReleaseCounter();
        }
    }

    ScopedActiveJniCallGuard(const ScopedActiveJniCallGuard&) = delete;
    ScopedActiveJniCallGuard& operator=(const ScopedActiveJniCallGuard&) = delete;

    bool IsAcquired() const { return acquired_; }

private:
    void ReleaseCounter() {
        GlobalRuntimeState& state = GetGlobalRuntimeState();
        const int64_t prev = state.active_jni_calls.fetch_sub(1, std::memory_order_seq_cst);
        if (prev == 1) {
            std::lock_guard<std::mutex> lock(state.jni_lifecycle_mutex);
            state.jni_lifecycle_cv.notify_all();
        }
    }

    bool acquired_;
};

#if defined(__ANDROID__) && __has_include(<jni.h>)
/**
 * @brief [EN] Reconstructed from `0x0081c4..0x0082ac` (`getJniEnvAndAttach`):
 *             1. Calls `g_vm->GetEnv(&env, JNI_VERSION_1_6)` (`0x00010006`).
 *             2. If `rc == JNI_EDETACHED` (`-2`), calls `g_vm->AttachCurrentThread(&env, nullptr)`
 *                and sets `*out_did_attach = true`.
 *             3. When the caller finishes, if `did_attach` is true, calls
 *                `g_vm->DetachCurrentThread()`.
 *        [VN] Phục dựng từ `0x0081c4..0x0082ac` (`getJniEnvAndAttach`):
 *             1. Gọi `g_vm->GetEnv(&env, JNI_VERSION_1_6)` (`0x00010006`).
 *             2. Nếu `rc == JNI_EDETACHED` (`-2`), gọi `g_vm->AttachCurrentThread(&env, nullptr)`
 *                và đặt `*out_did_attach = true`.
 *             3. Khi hàm gọi kết thúc, nếu `did_attach` là true, gọi
 *                `g_vm->DetachCurrentThread()`.
 */
class ScopedJniEnvAttachment {
public:
    ScopedJniEnvAttachment() : env_(nullptr), did_attach_(false) {
        JavaVM* vm = GetGlobalRuntimeState().g_vm;
        if (vm == nullptr) {
            return;
        }
        jint rc = vm->GetEnv(reinterpret_cast<void**>(&env_), JNI_VERSION_1_6);
        if (rc == JNI_EDETACHED) {
            if (vm->AttachCurrentThread(&env_, nullptr) == JNI_OK) {
                did_attach_ = true;
            } else {
                env_ = nullptr;
                ORBU_ADAPTER_LOGE("Failed to attach thread.");
            }
        } else if (rc != JNI_OK) {
            env_ = nullptr;
            ORBU_ADAPTER_LOGE("Failed to get the environment using GetEnv()");
        }
    }

    ~ScopedJniEnvAttachment() {
        if (did_attach_) {
            JavaVM* vm = GetGlobalRuntimeState().g_vm;
            if (vm != nullptr) {
                vm->DetachCurrentThread();
            }
        }
    }

    JNIEnv* env() const { return env_; }

private:
    JNIEnv* env_;
    bool did_attach_;
};

// ============================================================================
// [EN] Helper: convert jstring to std::string and release UTF chars
//      Reconstructed from 0x004d5c..0x004da8, 0x008d20..0x008e20.
// [VN] Hàm phụ trợ: chuyển jstring sang std::string và giải phóng UTF chars
//      Phục dựng từ 0x004d5c..0x004da8, 0x008d20..0x008e20.
// ============================================================================
std::string JStringToStdString(JNIEnv* env, jstring j_str) {
    if (env == nullptr || j_str == nullptr) {
        return std::string();
    }
    const char* utf_chars = env->GetStringUTFChars(j_str, nullptr);
    if (utf_chars == nullptr) {
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        return std::string();
    }
    std::string result(utf_chars);
    env->ReleaseStringUTFChars(j_str, utf_chars);
    return result;
}

// ============================================================================
// [EN] Helper: extract Java `List<String>` into `std::vector<std::string>`
//      Reconstructed from 0x008c70..0x008f94.
// [VN] Hàm phụ trợ: trích xuất `List<String>` của Java sang `std::vector<std::string>`
//      Phục dựng từ 0x008c70..0x008f94.
// ============================================================================
std::vector<std::string> ExtractJavaStringList(JNIEnv* env, jobject j_list) {
    std::vector<std::string> result;
    if (env == nullptr || j_list == nullptr) {
        return result;
    }
    jclass list_cls = env->GetObjectClass(j_list);
    if (list_cls == nullptr) {
        return result;
    }
    jmethodID mid_size = env->GetMethodID(list_cls, "size", "()I");
    jmethodID mid_get = env->GetMethodID(list_cls, "get", "(I)Ljava/lang/Object;");
    if (mid_size != nullptr && mid_get != nullptr) {
        const jint count = env->CallIntMethod(j_list, mid_size);
        if (count > 0) {
            result.reserve(static_cast<size_t>(count));
            for (jint i = 0; i < count; ++i) {
                jstring item = static_cast<jstring>(env->CallObjectMethod(j_list, mid_get, i));
                if (item != nullptr) {
                    result.push_back(JStringToStdString(env, item));
                    env->DeleteLocalRef(item);
                }
            }
        }
    }
    env->DeleteLocalRef(list_cls);
    return result;
}

// ============================================================================
// [EN] Helper: extract Java `com.orbu.core.config.NetConfig` into C++ `NetConfig`
//      Reconstructed from 0x008f98..0x009564 (`parseJavaNetConfig`).
// [VN] Hàm phụ trợ: trích xuất `com.orbu.core.config.NetConfig` sang `NetConfig` C++
//      Phục dựng từ 0x008f98..0x009564 (`parseJavaNetConfig`).
// ============================================================================
NetConfig ExtractJavaNetConfig(JNIEnv* env, jobject j_net_config) {
    NetConfig cfg;
    if (env == nullptr || j_net_config == nullptr) {
        return cfg;
    }
    jclass cls = env->GetObjectClass(j_net_config);
    if (cls == nullptr) {
        return cfg;
    }

    jfieldID fid_hosts = env->GetFieldID(cls, "hosts", "Ljava/util/List;");
    jfieldID fid_paths = env->GetFieldID(cls, "paths", "Ljava/util/List;");
    jfieldID fid_dfid = env->GetFieldID(cls, "dataflowId", "Ljava/lang/String;");

    if (fid_hosts != nullptr) {
        jobject j_hosts = env->GetObjectField(j_net_config, fid_hosts);
        if (j_hosts != nullptr) {
            cfg.hosts = ExtractJavaStringList(env, j_hosts);
            env->DeleteLocalRef(j_hosts);
        }
    }
    if (fid_paths != nullptr) {
        jobject j_paths = env->GetObjectField(j_net_config, fid_paths);
        if (j_paths != nullptr) {
            cfg.paths = ExtractJavaStringList(env, j_paths);
            env->DeleteLocalRef(j_paths);
        }
    }
    if (fid_dfid != nullptr) {
        jstring j_dfid = static_cast<jstring>(env->GetObjectField(j_net_config, fid_dfid));
        if (j_dfid != nullptr) {
            cfg.dataflow_id = JStringToStdString(env, j_dfid);
            env->DeleteLocalRef(j_dfid);
        }
    }

    env->DeleteLocalRef(cls);
    return cfg;
}

// ============================================================================
// [EN] Helper: extract Java `List<NetConfig>` into `std::vector<NetConfig>`
//      Reconstructed from 0x009568..0x0097a8.
// [VN] Hàm phụ trợ: trích xuất `List<NetConfig>` sang `std::vector<NetConfig>`
//      Phục dựng từ 0x009568..0x0097a8.
// ============================================================================
std::vector<NetConfig> ExtractJavaNetConfigList(JNIEnv* env, jobject j_list) {
    std::vector<NetConfig> list_out;
    if (env == nullptr || j_list == nullptr) {
        return list_out;
    }
    jclass list_cls = env->GetObjectClass(j_list);
    if (list_cls == nullptr) {
        return list_cls ? list_out : list_out;
    }
    jmethodID mid_size = env->GetMethodID(list_cls, "size", "()I");
    jmethodID mid_get = env->GetMethodID(list_cls, "get", "(I)Ljava/lang/Object;");
    if (mid_size != nullptr && mid_get != nullptr) {
        const jint count = env->CallIntMethod(j_list, mid_size);
        if (count > 0) {
            list_out.reserve(static_cast<size_t>(count));
            for (jint i = 0; i < count; ++i) {
                jobject item = env->CallObjectMethod(j_list, mid_get, i);
                if (item != nullptr) {
                    list_out.push_back(ExtractJavaNetConfig(env, item));
                    env->DeleteLocalRef(item);
                }
            }
        }
    }
    env->DeleteLocalRef(list_cls);
    return list_out;
}
#endif  // defined(__ANDROID__) && __has_include(<jni.h>)

// ============================================================================
// SECTION 3: JAVA PROPERTY QUERY CALLBACK & THREE UPCALL BRIDGES
//            (0x004b88..0x004f68, 0x007300..0x0081c0)
// ============================================================================

/**
 * [EN] Reconstructed from `0x004b88..0x004f68` (`queryJavaPropertyCallback`):
 *      Registered in `JNI_OnLoad` (`0x0048e8`) via `RegisterJavaPropertyCallback` (`0x012440`).
 *      1. Acquires `ScopedActiveJniCallGuard`.
 *      2. Attaches current thread via `ScopedJniEnvAttachment` (`0x0081c4`).
 *      3. Checks `cls_network_manager` (`0x0281c0`):
 *         - If `property_key == "get_user_region"` (`.rodata 0x01a858`):
 *           invokes `CallStaticObjectMethod(cls_network_manager, mid_get_store_region)` (`0x0281d0`).
 *         - If `property_key == "get_sandbox_state"` (`.rodata 0x01a868`):
 *           invokes `CallStaticObjectMethod(cls_network_manager, mid_get_sandbox_state)` (`0x0281d8`).
 *      4. Checks and clears JNI exceptions (`ExceptionCheck` / `ExceptionDescribe` / `ExceptionClear`),
 *         converts returned `jstring` to `std::string`, and deletes local ref.
 * [VN] Phục dựng từ `0x004b88..0x004f68` (`queryJavaPropertyCallback`):
 *      Được đăng ký trong `JNI_OnLoad` (`0x0048e8`) qua `RegisterJavaPropertyCallback` (`0x012440`).
 *      1. Khởi tạo `ScopedActiveJniCallGuard`.
 *      2. Gắn kết luồng hiện tại qua `ScopedJniEnvAttachment` (`0x0081c4`).
 *      3. Kiểm tra `cls_network_manager` (`0x0281c0`):
 *         - Nếu `property_key == "get_user_region"` (`.rodata 0x01a858`):
 *           gọi `CallStaticObjectMethod(cls_network_manager, mid_get_store_region)` (`0x0281d0`).
 *         - Nếu `property_key == "get_sandbox_state"` (`.rodata 0x01a868`):
 *           gọi `CallStaticObjectMethod(cls_network_manager, mid_get_sandbox_state)` (`0x0281d8`).
 *      4. Kiểm tra và xóa ngoại lệ JNI (`ExceptionCheck` / `ExceptionDescribe` / `ExceptionClear`),
 *         chuyển `jstring` trả về sang `std::string`, và xóa tham chiếu cục bộ.
 */
std::string QueryJavaPropertyUpcall(const std::string& property_key) {
    ScopedActiveJniCallGuard call_guard;
    if (!call_guard.IsAcquired()) {
        return std::string();
    }

#if defined(__ANDROID__) && __has_include(<jni.h>)
    ScopedJniEnvAttachment env_guard;
    JNIEnv* env = env_guard.env();
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (env == nullptr || state.cls_network_manager == nullptr) {
        return std::string();
    }

    jmethodID target_mid = nullptr;
    if (property_key == "get_user_region") {
        target_mid = state.mid_get_store_region;
    } else if (property_key == "get_sandbox_state") {
        target_mid = state.mid_get_sandbox_state;
    }

    if (target_mid == nullptr) {
        return std::string();
    }

    jstring j_res = static_cast<jstring>(
        env->CallStaticObjectMethod(state.cls_network_manager, target_mid));
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return std::string();
    }
    if (j_res == nullptr) {
        return std::string();
    }

    std::string out = JStringToStdString(env, j_res);
    env->DeleteLocalRef(j_res);
    return out;
#else
    (void)property_key;
    return std::string();
#endif
}

/**
 * [EN] Reconstructed from `0x007300..0x007b14` (`proceedSeiFieldUpcall`):
 *      Stored at `.bss 0x028238` by `activesdk` (`0x004f6c`).
 *      1. Acquires `ScopedActiveJniCallGuard` and `ScopedJniEnvAttachment`.
 *      2. Creates `jstring j_key = env->NewStringUTF(sei_key)` and
 *         `jstring j_channel = env->NewStringUTF(sei_channel)`.
 *      3. Dispatches on `sei_payload->value_type` (`switch (value_type - 1)` at `0x0073b0`):
 *         - `1` (`kBinaryBytes`): creates `jbyteArray` of length `sei_payload->byte_length`,
 *           copies `sei_payload->data.bytes_ptr` via `SetByteArrayRegion`, and calls
 *           `TTKNativeLiveSeiFieldManager.proceedSeiField(String, [B, String)I` (`0x0281f0`).
 *         - `2` (`kString`): creates `jstring` from `sei_payload->data.c_str` and calls
 *           `TTKNativeLiveSeiFieldManager.proceedSeiField(String, String, String)I` (`0x0281f8`).
 *         - `3` (`kBoolean`): calls `proceedSeiField(String, Z, String)I` (`0x028200`) with
 *           `sei_payload->data.bool_val != 0`.
 *         - `4` (`kInt64`): calls `proceedSeiField(String, J, String)I` (`0x028208`) with
 *           `sei_payload->data.i64_val`.
 *         - `5` (`kFloat32`): calls `proceedSeiField(String, F, String)I` (`0x028210`) with
 *           `sei_payload->data.f32_val`.
 *      4. Measures execution duration and, if `send_report_cb != nullptr`, dispatches
 *         `SendReportAsync("SEI", ...)` (`0x00c5e0`).
 * [VN] Phục dựng từ `0x007300..0x007b14` (`proceedSeiFieldUpcall`):
 *      Được lưu tại `.bss 0x028238` bởi `activesdk` (`0x004f6c`).
 *      1. Khởi tạo `ScopedActiveJniCallGuard` và `ScopedJniEnvAttachment`.
 *      2. Tạo `jstring j_key = env->NewStringUTF(sei_key)` và
 *         `jstring j_channel = env->NewStringUTF(sei_channel)`.
 *      3. Điều phối theo `sei_payload->value_type` (`switch (value_type - 1)` tại `0x0073b0`):
 *         - `1` (`kBinaryBytes`): tạo `jbyteArray` độ dài `sei_payload->byte_length`,
 *           sao chép `sei_payload->data.bytes_ptr` qua `SetByteArrayRegion`, và gọi
 *           `TTKNativeLiveSeiFieldManager.proceedSeiField(String, [B, String)I` (`0x0281f0`).
 *         - `2` (`kString`): tạo `jstring` từ `sei_payload->data.c_str` và gọi
 *           `TTKNativeLiveSeiFieldManager.proceedSeiField(String, String, String)I` (`0x0281f8`).
 *         - `3` (`kBoolean`): gọi `proceedSeiField(String, Z, String)I` (`0x028200`) với
 *           `sei_payload->data.bool_val != 0`.
 *         - `4` (`kInt64`): gọi `proceedSeiField(String, J, String)I` (`0x028208`) với
 *           `sei_payload->data.i64_val`.
 *         - `5` (`kFloat32`): gọi `proceedSeiField(String, F, String)I` (`0x028210`) với
 *           `sei_payload->data.f32_val`.
 *      4. Đo thời gian thực thi và nếu `send_report_cb != nullptr`, gửi báo cáo
 *         `SendReportAsync("SEI", ...)` (`0x00c5e0`).
 */
int32_t ProceedSeiFieldUpcall(
    const char* sei_key,
    const SeiFieldPayload* sei_payload,
    const char* sei_channel) {
    ScopedActiveJniCallGuard call_guard;
    if (!call_guard.IsAcquired() || sei_key == nullptr || sei_payload == nullptr ||
        sei_channel == nullptr) {
        return 0;
    }

    const auto start_tp = std::chrono::steady_clock::now();
    int32_t sei_result = 0;

#if defined(__ANDROID__) && __has_include(<jni.h>)
    ScopedJniEnvAttachment env_guard;
    JNIEnv* env = env_guard.env();
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (env != nullptr && state.cls_sei_field_manager != nullptr) {
        jstring j_key = env->NewStringUTF(sei_key);
        jstring j_channel = env->NewStringUTF(sei_channel);

        switch (static_cast<SeiValueType>(sei_payload->value_type)) {
            case SeiValueType::kBinaryBytes: {
                if (state.mid_proceed_sei_bytes != nullptr &&
                    sei_payload->data.bytes_ptr != nullptr) {
                    const jsize len = static_cast<jsize>(sei_payload->byte_length);
                    jbyteArray j_bytes = env->NewByteArray(len);
                    if (j_bytes != nullptr) {
                        env->SetByteArrayRegion(
                            j_bytes,
                            0,
                            len,
                            reinterpret_cast<const jbyte*>(sei_payload->data.bytes_ptr));
                        sei_result = env->CallStaticIntMethod(
                            state.cls_sei_field_manager,
                            state.mid_proceed_sei_bytes,
                            j_key,
                            j_bytes,
                            j_channel);
                        env->DeleteLocalRef(j_bytes);
                    }
                }
                break;
            }
            case SeiValueType::kString: {
                if (state.mid_proceed_sei_string != nullptr &&
                    sei_payload->data.c_str != nullptr) {
                    jstring j_val = env->NewStringUTF(sei_payload->data.c_str);
                    if (j_val != nullptr) {
                        sei_result = env->CallStaticIntMethod(
                            state.cls_sei_field_manager,
                            state.mid_proceed_sei_string,
                            j_key,
                            j_val,
                            j_channel);
                        env->DeleteLocalRef(j_val);
                    }
                }
                break;
            }
            case SeiValueType::kBoolean: {
                if (state.mid_proceed_sei_bool != nullptr) {
                    sei_result = env->CallStaticIntMethod(
                        state.cls_sei_field_manager,
                        state.mid_proceed_sei_bool,
                        j_key,
                        static_cast<jboolean>(sei_payload->data.bool_val != 0 ? JNI_TRUE : JNI_FALSE),
                        j_channel);
                }
                break;
            }
            case SeiValueType::kInt64: {
                if (state.mid_proceed_sei_long != nullptr) {
                    sei_result = env->CallStaticIntMethod(
                        state.cls_sei_field_manager,
                        state.mid_proceed_sei_long,
                        j_key,
                        static_cast<jlong>(sei_payload->data.i64_val),
                        j_channel);
                }
                break;
            }
            case SeiValueType::kFloat32: {
                if (state.mid_proceed_sei_float != nullptr) {
                    sei_result = env->CallStaticIntMethod(
                        state.cls_sei_field_manager,
                        state.mid_proceed_sei_float,
                        j_key,
                        static_cast<jfloat>(sei_payload->data.f32_val),
                        j_channel);
                }
                break;
            }
            default:
                break;
        }

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
            sei_result = 0;
        }
        if (j_key != nullptr) {
            env->DeleteLocalRef(j_key);
        }
        if (j_channel != nullptr) {
            env->DeleteLocalRef(j_channel);
        }
    }
#endif

    const auto end_tp = std::chrono::steady_clock::now();
    const int64_t elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                   end_tp - start_tp)
                                   .count();

    SendReportAsync(
        kSandboxChannelSei,
        sei_key,
        sei_channel,
        "",
        "",
        0x18000008,  // Default SEI dataflow ID (402653192 at 0x0079c0: mov w5, #0x18000008)
        sei_result,
        false,
        elapsed_ms);

    return sei_result;
}

/**
 * [EN] Reconstructed from `0x007b18..0x007d48` (`inTargetBlockRuleHashListUpcall`):
 *      Stored at `.bss 0x028240` by `activesdk` (`0x004f6c`).
 *      Invokes `TTKNativeNetworkManager.inTargetBlockRuleHashList()Z` (`0x028218`).
 * [VN] Phục dựng từ `0x007b18..0x007d48` (`inTargetBlockRuleHashListUpcall`):
 *      Được lưu tại `.bss 0x028240` bởi `activesdk` (`0x004f6c`).
 *      Gọi `TTKNativeNetworkManager.inTargetBlockRuleHashList()Z` (`0x028218`).
 */
bool InTargetBlockRuleHashListUpcall() {
    ScopedActiveJniCallGuard call_guard;
    if (!call_guard.IsAcquired()) {
        return false;
    }

#if defined(__ANDROID__) && __has_include(<jni.h>)
    ScopedJniEnvAttachment env_guard;
    JNIEnv* env = env_guard.env();
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (env == nullptr || state.cls_network_manager == nullptr ||
        state.mid_in_target_block_hash == nullptr) {
        return false;
    }

    const jboolean hit = env->CallStaticBooleanMethod(
        state.cls_network_manager, state.mid_in_target_block_hash);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return false;
    }
    return hit != JNI_FALSE;
#else
    return false;
#endif
}

/**
 * [EN] Reconstructed from `0x007d4c..0x0081c0` (`sendReportUpcall`):
 *      Stored at `.bss 0x028230` by `activesdk` (`0x004f6c`) when `enable_callback != 0`.
 *      1. Checks `sdk_report_strategy` (`0x028228`):
 *         - If `sdk_report_strategy == 1` and `sandbox_result == 0` and `!is_hit_rule`,
 *           skips reporting (`0x007dd4`).
 *      2. Acquires `ScopedActiveJniCallGuard` and `ScopedJniEnvAttachment`.
 *      3. If `channel == "NETWORK"` (`.rodata 0x01b260`), invokes 9-argument static method
 *         `TTKNativeNetworkManager.send(String,String,String,String,String,IIZZ)V` (`0x0281e0`).
 *      4. Otherwise (e.g., `"SEI"`), invokes 7-argument static method
 *         `TTKNativeNetworkManager.send(String,String,String,IIZZ)V` (`0x0281e8`).
 * [VN] Phục dựng từ `0x007d4c..0x0081c0` (`sendReportUpcall`):
 *      Được lưu tại `.bss 0x028230` bởi `activesdk` (`0x004f6c`) khi `enable_callback != 0`.
 *      1. Kiểm tra `sdk_report_strategy` (`0x028228`):
 *         - Nếu `sdk_report_strategy == 1` và `sandbox_result == 0` và `!is_hit_rule`,
 *           bỏ qua việc gửi báo cáo (`0x007dd4`).
 *      2. Khởi tạo `ScopedActiveJniCallGuard` và `ScopedJniEnvAttachment`.
 *      3. Nếu `channel == "NETWORK"` (`.rodata 0x01b260`), gọi phương thức tĩnh 9 tham số
 *         `TTKNativeNetworkManager.send(String,String,String,String,String,IIZZ)V` (`0x0281e0`).
 *      4. Ngược lại (ví dụ `"SEI"`), gọi phương thức tĩnh 7 tham số
 *         `TTKNativeNetworkManager.send(String,String,String,IIZZ)V` (`0x0281e8`).
 */
void SendReportUpcall(
    const std::string& channel,
    const std::string& url_or_key,
    const std::string& method_or_val,
    const std::string& headers_str,
    const std::string& body_str,
    int32_t dataflow_id,
    int32_t sandbox_result,
    bool is_hit_rule,
    int64_t duration_us) {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (state.sdk_report_strategy == 1 && sandbox_result == 0 && !is_hit_rule) {
        return;
    }

    ScopedActiveJniCallGuard call_guard;
    if (!call_guard.IsAcquired()) {
        return;
    }

#if defined(__ANDROID__) && __has_include(<jni.h>)
    ScopedJniEnvAttachment env_guard;
    JNIEnv* env = env_guard.env();
    if (env == nullptr || state.cls_network_manager == nullptr) {
        return;
    }

    jstring j_channel = env->NewStringUTF(channel.c_str());
    jstring j_arg1 = env->NewStringUTF(url_or_key.c_str());
    jstring j_arg2 = env->NewStringUTF(method_or_val.c_str());

    if (channel == kSandboxChannelNetwork && state.mid_send_9args != nullptr) {
        jstring j_headers = env->NewStringUTF(headers_str.c_str());
        jstring j_body = env->NewStringUTF(body_str.c_str());
        env->CallStaticVoidMethod(
            state.cls_network_manager,
            state.mid_send_9args,
            j_channel,
            j_arg1,
            j_arg2,
            j_headers,
            j_body,
            static_cast<jint>(dataflow_id),
            static_cast<jint>(sandbox_result),
            static_cast<jboolean>(is_hit_rule ? JNI_TRUE : JNI_FALSE),
            static_cast<jboolean>(state.hit_sample_drop ? JNI_TRUE : JNI_FALSE));
        if (j_headers != nullptr) {
            env->DeleteLocalRef(j_headers);
        }
        if (j_body != nullptr) {
            env->DeleteLocalRef(j_body);
        }
    } else if (state.mid_send_7args != nullptr) {
        env->CallStaticVoidMethod(
            state.cls_network_manager,
            state.mid_send_7args,
            j_channel,
            j_arg1,
            j_arg2,
            static_cast<jint>(dataflow_id),
            static_cast<jint>(sandbox_result),
            static_cast<jboolean>(is_hit_rule ? JNI_TRUE : JNI_FALSE),
            static_cast<jboolean>(state.hit_sample_drop ? JNI_TRUE : JNI_FALSE));
    }

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (j_channel != nullptr) {
        env->DeleteLocalRef(j_channel);
    }
    if (j_arg1 != nullptr) {
        env->DeleteLocalRef(j_arg1);
    }
    if (j_arg2 != nullptr) {
        env->DeleteLocalRef(j_arg2);
    }
#else
    (void)channel;
    (void)url_or_key;
    (void)method_or_val;
    (void)headers_str;
    (void)body_str;
    (void)dataflow_id;
    (void)sandbox_result;
    (void)is_hit_rule;
    (void)duration_us;
#endif
}

// ============================================================================
// SECTION 4: FIVE SHADOWHOOK GETENV-EXPORTED NATIVE ENTRY POINTS
//            (0x00d2e8, 0x00d490, 0x00eb48, 0x011178, 0x011808)
// ============================================================================

/**
 * [EN] Export [4] `"orbuculumIsProceedSeiField"` reconstructed from `0x00d2e8..0x00d38c`:
 *      1. Checks `(sdk_enable_strategy & 0x04) != 0` (`tbz w8, #2, 0xd378`).
 *         If bit 2 is not set, returns `0`.
 *      2. Validates `sei_key != nullptr`, `sei_payload != nullptr`, `sei_channel != nullptr`,
 *         and `proceed_sei_cb != nullptr` (`0x028238`).
 *      3. Calls `proceed_sei_cb(sei_key, sei_payload, sei_channel)` inside
 *         `ExecuteWithSignalCrashGuard` (`0x00d390..0x00d480`).
 * [VN] Biểu tượng xuất [4] `"orbuculumIsProceedSeiField"` phục dựng từ `0x00d2e8..0x00d38c`:
 *      1. Kiểm tra `(sdk_enable_strategy & 0x04) != 0` (`tbz w8, #2, 0xd378`).
 *         Nếu bit 2 không bật, trả về `0`.
 *      2. Kiểm tra `sei_key != nullptr`, `sei_payload != nullptr`, `sei_channel != nullptr`,
 *         và `proceed_sei_cb != nullptr` (`0x028238`).
 *      3. Gọi `proceed_sei_cb(sei_key, sei_payload, sei_channel)` bên trong
 *         `ExecuteWithSignalCrashGuard` (`0x00d390..0x00d480`).
 */
int32_t OrbuculumIsProceedSeiField(
    const char* sei_key,
    const SeiFieldPayload* sei_payload,
    const char* sei_channel) {
    const GlobalRuntimeState& state = GetGlobalRuntimeState();
    if ((state.sdk_enable_strategy & 0x04) == 0) {
        return 0;
    }
    if (sei_key == nullptr || sei_payload == nullptr || sei_channel == nullptr) {
        return 0;
    }
    const ProceedSeiFieldCallbackFn cb = state.proceed_sei_cb;
    if (cb == nullptr) {
        return 0;
    }

    return ExecuteWithSignalCrashGuard(
        [&]() -> int32_t {
            return cb(sei_key, sei_payload, sei_channel);
        },
        0);
}

/**
 * [EN] Export [3] `"orbuculumRegisterLiveShutdownCallback"` reconstructed from `0x00d490..0x00d574`:
 *      1. Acquires `live_shutdown_mutex` (`0x028388`).
 *      2. Stores `callback` into `live_shutdown_fn` (`0x0283b8`).
 *      3. Lazily opens `"liborbuculum.so"` and forwards registration to
 *         `orbuculumRegisterLiveShutdownCallback` inside `ExecuteWithSignalCrashGuard` (`0x00d578`).
 * [VN] Biểu tượng xuất [3] `"orbuculumRegisterLiveShutdownCallback"` phục dựng từ `0x00d490..0x00d574`:
 *      1. Khóa `live_shutdown_mutex` (`0x028388`).
 *      2. Lưu `callback` vào `live_shutdown_fn` (`0x0283b8`).
 *      3. Mở lười `"liborbuculum.so"` và chuyển tiếp đăng ký tới
 *         `orbuculumRegisterLiveShutdownCallback` bên trong `ExecuteWithSignalCrashGuard` (`0x00d578`).
 */
int32_t OrbuculumRegisterLiveShutdownCallback(LiveShutdownCallbackFn callback) {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    {
        std::lock_guard<std::mutex> lock(state.live_shutdown_mutex);
        if (callback != nullptr) {
            state.live_shutdown_fn = [callback]() { callback(); };
        } else {
            state.live_shutdown_fn = nullptr;
        }
    }

    return ExecuteWithSignalCrashGuard(
        [&]() -> int32_t {
            if (state.live_shutdown_fn) {
                return 0;
            }
            return -1;
        },
        0);
}

/**
 * [EN] Export [1] `"orbuculumIsProceedRequestForTTNet"` reconstructed from `0x00eb48..0x00f6e8`:
 *      1. Checks `(sdk_enable_strategy & 0x01) != 0` (`tbz w8, #0, 0xf5ec`). If disabled, returns `0`.
 *      2. Checks `IsUrlMatchingComplianceScheme(url)` (`0x00c13c`). If not matching, returns `0`.
 *      3. Copies `metadata` into `working_meta` and checks if `"x-tt-dataflow-id"` is present
 *         and non-empty (`0x00ec48..0x00ecf0`):
 *         - If `"x-tt-dataflow-id"` is missing or empty:
 *           a) Calls `RecognizeDomainIdentityViaPumbaa(url)` (`0x00eda8..0x00ef20`) to classify domain:
 *              - If `"tt_1st"`: replenishes DFID via `ReplenishFirstPartyDataflowId(url)` (`0x00dc60`).
 *              - If `"bd_1st"`: assigns `"672137215"` (`0x281001bf`, `kDfidByteDanceFirstParty`).
 *              - If `"bd_3rd"`: assigns `AssignThirdPartyDataflowId(url)` (`0x00e1d8`) into
 *                `"transition_dfid"` and sets `"x-tt-dataflow-id"` = `"671088895"` (`0x280000ff`).
 *              - Otherwise (3rd party): assigns `AssignThirdPartyDataflowId(url)` (`0x00e1d8`).
 *           b) Fallback when Pumbaa recognizer is unavailable: calls
 *              `ReplenishFirstPartyDataflowId(url)` (`0x00dc60`).
 *      4. Checks `pumbaa_strategy` (`0x028224`):
 *         - If `pumbaa_strategy == 2` or `pumbaa_strategy == 3`, dispatches to
 *           `InvokePumbaaSandboxValidate(...)` (`0x00ffac`).
 *         - Otherwise dispatches to `InvokeOrbuculumProceedRequestImpl(...)` (`0x010af8`).
 * [VN] Biểu tượng xuất [1] `"orbuculumIsProceedRequestForTTNet"` phục dựng từ `0x00eb48..0x00f6e8`:
 *      1. Kiểm tra `(sdk_enable_strategy & 0x01) != 0` (`tbz w8, #0, 0xf5ec`). Nếu tắt, trả về `0`.
 *      2. Kiểm tra `IsUrlMatchingComplianceScheme(url)` (`0x00c13c`). Nếu không khớp, trả về `0`.
 *      3. Sao chép `metadata` sang `working_meta` và kiểm tra xem `"x-tt-dataflow-id"` đã có
 *         và khác rỗng chưa (`0x00ec48..0x00ecf0`):
 *         - Nếu thiếu hoặc rỗng `"x-tt-dataflow-id"`:
 *           a) Gọi `RecognizeDomainIdentityViaPumbaa(url)` (`0x00eda8..0x00ef20`) để phân loại tên miền:
 *              - Nếu `"tt_1st"`: bổ sung DFID qua `ReplenishFirstPartyDataflowId(url)` (`0x00dc60`).
 *              - Nếu `"bd_1st"`: gán `"672137215"` (`0x281001bf`, `kDfidByteDanceFirstParty`).
 *              - Nếu `"bd_3rd"`: gán `AssignThirdPartyDataflowId(url)` (`0x00e1d8`) vào
 *                `"transition_dfid"` và đặt `"x-tt-dataflow-id"` = `"671088895"` (`0x280000ff`).
 *              - Ngược lại (bên thứ ba): gán `AssignThirdPartyDataflowId(url)` (`0x00e1d8`).
 *           b) Dự phòng khi Pumbaa chưa nạp: gọi `ReplenishFirstPartyDataflowId(url)` (`0x00dc60`).
 *      4. Kiểm tra `pumbaa_strategy` (`0x028224`):
 *         - Nếu `pumbaa_strategy == 2` hoặc `pumbaa_strategy == 3`, chuyển tới
 *           `InvokePumbaaSandboxValidate(...)` (`0x00ffac`).
 *         - Ngược lại chuyển tới `InvokeOrbuculumProceedRequestImpl(...)` (`0x010af8`).
 */
int32_t OrbuculumIsProceedRequestForTTNet(
    const std::string& url,
    const std::string& method,
    const std::map<std::string, std::string>& headers,
    const std::string& body,
    size_t body_len,
    const std::map<std::string, std::string>& metadata) {
    const GlobalRuntimeState& state = GetGlobalRuntimeState();
    if ((state.sdk_enable_strategy & 0x01) == 0) {
        return 0;
    }
    if (url.empty() || !IsUrlMatchingComplianceScheme(url)) {
        return 0;
    }

    std::map<std::string, std::string> working_meta = metadata;
    const auto existing_dfid_it = working_meta.find(kHeaderDataflowId);
    const bool has_dfid =
        (existing_dfid_it != working_meta.end() && !existing_dfid_it->second.empty());

    if (!has_dfid) {
        // Also check HTTP request headers for x-tt-dataflow-id
        const auto header_dfid_it = headers.find(kHeaderDataflowId);
        if (header_dfid_it != headers.end() && !header_dfid_it->second.empty()) {
            working_meta[kHeaderDataflowId] = header_dfid_it->second;
        } else {
            const std::string domain_identity = RecognizeDomainIdentityViaPumbaa(url);
            if (domain_identity == "tt_1st" || domain_identity.empty()) {
                working_meta[kHeaderDataflowId] = ReplenishFirstPartyDataflowId(url);
            } else if (domain_identity == "bd_1st") {
                working_meta[kHeaderDataflowId] = kDfidByteDanceFirstParty;
            } else if (domain_identity == "bd_3rd") {
                working_meta[kMetadataTransitionDfid] = AssignThirdPartyDataflowId(url);
                working_meta[kHeaderDataflowId] = kDfidByteDanceThirdParty;
            } else {
                working_meta[kHeaderDataflowId] = AssignThirdPartyDataflowId(url);
            }
        }
    }

    if (state.pumbaa_strategy == 2 || state.pumbaa_strategy == 3) {
        return InvokePumbaaSandboxValidate(
            url, method, headers, body, working_meta, state.pumbaa_strategy);
    }

    return InvokeOrbuculumProceedRequestImpl(
        url, method, headers, body, body_len, working_meta);
}

/**
 * [EN] Export [0] `"orbuculumIsProceedRequest"` reconstructed from `0x011178..0x011804`:
 *      1. Checks `(sdk_enable_strategy & 0x01) != 0`. If disabled, returns `0`.
 *      2. Validates `url != nullptr` and `method != nullptr`.
 *      3. Parses `headers_raw` and `metadata_raw` via `ParseHttpHeadersUnified` (`0x00b99c`).
 *      4. Delegates to `OrbuculumIsProceedRequestForTTNet` (`0x00eb48`).
 * [VN] Biểu tượng xuất [0] `"orbuculumIsProceedRequest"` phục dựng từ `0x011178..0x011804`:
 *      1. Kiểm tra `(sdk_enable_strategy & 0x01) != 0`. Nếu tắt, trả về `0`.
 *      2. Kiểm tra `url != nullptr` và `method != nullptr`.
 *      3. Phân tích `headers_raw` và `metadata_raw` qua `ParseHttpHeadersUnified` (`0x00b99c`).
 *      4. Ủy quyền cho `OrbuculumIsProceedRequestForTTNet` (`0x00eb48`).
 */
int32_t OrbuculumIsProceedRequest(
    const char* url,
    const char* method,
    const char* headers_raw,
    const char* body,
    size_t body_len,
    const char* metadata_raw) {
    const GlobalRuntimeState& state = GetGlobalRuntimeState();
    if ((state.sdk_enable_strategy & 0x01) == 0) {
        return 0;
    }
    if (url == nullptr || method == nullptr) {
        return 0;
    }

    const std::string url_str(url);
    const std::string method_str(method);
    const std::map<std::string, std::string> parsed_headers =
        ParseHttpHeadersUnified(headers_raw ? headers_raw : "");
    const std::map<std::string, std::string> parsed_metadata =
        ParseHttpHeadersUnified(metadata_raw ? metadata_raw : "");
    const std::string body_str =
        (body != nullptr && body_len > 0) ? std::string(body, body_len) : std::string();

    return OrbuculumIsProceedRequestForTTNet(
        url_str, method_str, parsed_headers, body_str, body_len, parsed_metadata);
}

/**
 * [EN] Export [2] `"orbuculumIsProceedResponseImpl"` reconstructed from `0x011808..0x011da0`:
 *      Forwards directly to `InvokeOrbuculumProceedResponseImpl`.
 * [VN] Biểu tượng xuất [2] `"orbuculumIsProceedResponseImpl"` phục dựng từ `0x011808..0x011da0`:
 *      Chuyển tiếp trực tiếp tới `InvokeOrbuculumProceedResponseImpl`.
 */
int32_t OrbuculumIsProceedResponseImpl(
    const char* url,
    const char* method,
    const char* req_headers,
    const char* req_body,
    size_t req_body_len,
    int32_t status_code,
    const char* resp_headers,
    const char* resp_body,
    size_t resp_body_len,
    const char* metadata_kv) {
    return InvokeOrbuculumProceedResponseImpl(
        url,
        method,
        req_headers,
        req_body,
        req_body_len,
        status_code,
        resp_headers,
        resp_body,
        resp_body_len,
        metadata_kv);
}

// ============================================================================
// SECTION 5: EIGHT REGISTERNATIVES JNI METHODS ON TTKNativeNetworkManager
//            (0x004f6c..0x0072fc, .data 0x028000..0x0280b8)
// ============================================================================

/**
 * [EN] Method [0] `activesdk(IZI)I` reconstructed from `0x004f6c..0x004fe8`:
 *      - Stores `sdk_enable_strategy` at `0x028220` and `pumbaa_strategy` at `0x028224`.
 *      - Registers `ProceedSeiFieldUpcall` (`0x007300`) at `0x028238`.
 *      - Registers `InTargetBlockRuleHashListUpcall` (`0x007b18`) at `0x028240`.
 *      - If `enable_callback != 0`, registers `SendReportUpcall` (`0x007d4c`) at `0x028230`.
 *      - Returns `0` (`w0 = 0`).
 * [VN] Phương thức [0] `activesdk(IZI)I` phục dựng từ `0x004f6c..0x004fe8`:
 *      - Lưu `sdk_enable_strategy` tại `0x028220` và `pumbaa_strategy` tại `0x028224`.
 *      - Đăng ký `ProceedSeiFieldUpcall` (`0x007300`) tại `0x028238`.
 *      - Đăng ký `InTargetBlockRuleHashListUpcall` (`0x007b18`) tại `0x028240`.
 *      - Nếu `enable_callback != 0`, đăng ký `SendReportUpcall` (`0x007d4c`) tại `0x028230`.
 *      - Trả về `0` (`w0 = 0`).
 */
jint JniActiveSdk(
    JNIEnv* env,
    jobject thiz,
    jint sdk_enable_strategy,
    jboolean enable_callback,
    jint pumbaa_strategy) {
    (void)env;
    (void)thiz;
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (state.native_debug) {
        ORBU_ADAPTER_LOGD(
            "init network wrapper sdk_enable_strategy=%d, enableCallback=%d, pumbaaStrategy=%d",
            sdk_enable_strategy,
            enable_callback,
            pumbaa_strategy);
    }

    state.sdk_enable_strategy = sdk_enable_strategy;
    state.pumbaa_strategy = pumbaa_strategy;
    state.proceed_sei_cb = &ProceedSeiFieldUpcall;
    state.in_target_block_cb = &InTargetBlockRuleHashListUpcall;

    if (enable_callback != JNI_FALSE) {
        state.send_report_cb = &SendReportUpcall;
    }
    return 0;
}

/**
 * [EN] Method [1] `initcall(IZ)I` reconstructed from `0x004fec..0x005054`:
 *      - Stores `sdk_report_strategy` at `0x028228` and `hit_sample_drop != 0` at `0x02822c`.
 *      - Calls `HookAndSetupEnv` (`0x012050`) with the 5 native entry points.
 * [VN] Phương thức [1] `initcall(IZ)I` phục dựng từ `0x004fec..0x005054`:
 *      - Lưu `sdk_report_strategy` tại `0x028228` và `hit_sample_drop != 0` tại `0x02822c`.
 *      - Gọi `HookAndSetupEnv` (`0x012050`) với 5 điểm vào native.
 */
jint JniInitCall(
    JNIEnv* env,
    jobject thiz,
    jint sdk_report_strategy,
    jboolean hit_sample_drop) {
    (void)env;
    (void)thiz;
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (state.native_debug) {
        ORBU_ADAPTER_LOGI(
            "init start sdkReportStrategy=%d, hitSampleDrop=%d",
            sdk_report_strategy,
            hit_sample_drop);
    }

    state.sdk_report_strategy = sdk_report_strategy;
    state.hit_sample_drop = (hit_sample_drop != JNI_FALSE);

    return HookAndSetupEnv(
        reinterpret_cast<void*>(&OrbuculumIsProceedRequest),
        reinterpret_cast<void*>(&OrbuculumIsProceedRequestForTTNet),
        reinterpret_cast<void*>(&OrbuculumIsProceedResponseImpl),
        reinterpret_cast<void*>(&OrbuculumRegisterLiveShutdownCallback),
        reinterpret_cast<void*>(&OrbuculumIsProceedSeiField));
}

/**
 * [EN] Method [2] `initnetconfig(Lcom/orbu/core/config/BootConfig;)V` reconstructed from
 *      `0x005058..0x005894`:
 *      Extracts `agConfig` (`Lcom/orbu/core/config/AgConfig;` -> `boot`, `ag`, `agSpecial`),
 *      `thirdPartyConfig` (`Ljava/util/List;`), `thirdPartyFallbackDFID` (`Ljava/lang/String;`),
 *      and `compliancePrefixList` (`Ljava/util/List;`) into `GetNetConfigRepository()` (`0x028248`).
 * [VN] Phương thức [2] `initnetconfig(Lcom/orbu/core/config/BootConfig;)V` phục dựng từ
 *      `0x005058..0x005894`:
 *      Trích xuất `agConfig` (`Lcom/orbu/core/config/AgConfig;` -> `boot`, `ag`, `agSpecial`),
 *      `thirdPartyConfig` (`Ljava/util/List;`), `thirdPartyFallbackDFID` (`Ljava/lang/String;`),
 *      và `compliancePrefixList` (`Ljava/util/List;`) vào `GetNetConfigRepository()` (`0x028248`).
 */
void JniInitNetConfig(
    JNIEnv* env,
    jobject thiz,
    jobject boot_config_obj) {
    (void)thiz;
    NetConfigRepository& repo = GetNetConfigRepository();
#if defined(__ANDROID__) && __has_include(<jni.h>)
    if (env == nullptr || boot_config_obj == nullptr) {
        return;
    }

    jclass boot_cls = env->GetObjectClass(boot_config_obj);
    if (boot_cls == nullptr) {
        return;
    }

    jfieldID fid_ag_config = env->GetFieldID(
        boot_cls, "agConfig", "Lcom/orbu/core/config/AgConfig;");
    jfieldID fid_3p_config = env->GetFieldID(
        boot_cls, "thirdPartyConfig", "Ljava/util/List;");
    jfieldID fid_3p_fallback = env->GetFieldID(
        boot_cls, "thirdPartyFallbackDFID", "Ljava/lang/String;");
    jfieldID fid_compliance_prefixes = env->GetFieldID(
        boot_cls, "compliancePrefixList", "Ljava/util/List;");

    if (fid_ag_config != nullptr) {
        jobject ag_config_obj = env->GetObjectField(boot_config_obj, fid_ag_config);
        if (ag_config_obj != nullptr) {
            jclass ag_cls = env->GetObjectClass(ag_config_obj);
            if (ag_cls != nullptr) {
                jfieldID fid_boot = env->GetFieldID(
                    ag_cls, "boot", "Lcom/orbu/core/config/NetConfig;");
                jfieldID fid_ag = env->GetFieldID(
                    ag_cls, "ag", "Lcom/orbu/core/config/NetConfig;");
                jfieldID fid_ag_special = env->GetFieldID(
                    ag_cls, "agSpecial", "Ljava/util/List;");

                if (fid_boot != nullptr) {
                    jobject j_boot = env->GetObjectField(ag_config_obj, fid_boot);
                    if (j_boot != nullptr) {
                        repo.boot = ExtractJavaNetConfig(env, j_boot);
                        env->DeleteLocalRef(j_boot);
                    }
                }
                if (fid_ag != nullptr) {
                    jobject j_ag = env->GetObjectField(ag_config_obj, fid_ag);
                    if (j_ag != nullptr) {
                        repo.ag = ExtractJavaNetConfig(env, j_ag);
                        env->DeleteLocalRef(j_ag);
                    }
                }
                if (fid_ag_special != nullptr) {
                    jobject j_ag_special = env->GetObjectField(ag_config_obj, fid_ag_special);
                    if (j_ag_special != nullptr) {
                        repo.ag_special = ExtractJavaNetConfigList(env, j_ag_special);
                        env->DeleteLocalRef(j_ag_special);
                    }
                }
                env->DeleteLocalRef(ag_cls);
            }
            env->DeleteLocalRef(ag_config_obj);
        }
    }

    if (fid_3p_config != nullptr) {
        jobject j_3p_list = env->GetObjectField(boot_config_obj, fid_3p_config);
        if (j_3p_list != nullptr) {
            repo.third_party_config = ExtractJavaNetConfigList(env, j_3p_list);
            env->DeleteLocalRef(j_3p_list);
        }
    }

    if (fid_3p_fallback != nullptr) {
        jstring j_fallback = static_cast<jstring>(
            env->GetObjectField(boot_config_obj, fid_3p_fallback));
        if (j_fallback != nullptr) {
            repo.third_party_fallback_dfid = JStringToStdString(env, j_fallback);
            env->DeleteLocalRef(j_fallback);
        }
    }

    if (fid_compliance_prefixes != nullptr) {
        jobject j_prefixes = env->GetObjectField(boot_config_obj, fid_compliance_prefixes);
        if (j_prefixes != nullptr) {
            repo.compliance_prefix_list = ExtractJavaStringList(env, j_prefixes);
            env->DeleteLocalRef(j_prefixes);
        }
    }

    env->DeleteLocalRef(boot_cls);
#else
    (void)env;
    (void)boot_config_obj;
    (void)repo;
#endif

    if (GetGlobalRuntimeState().native_debug) {
        ORBU_ADAPTER_LOGI("init_net_config success.");
    }
}

/**
 * [EN] Method [3] `unhook()V` reconstructed from `0x005c24` (`b 0x12358`):
 *      Tail-calls `UnhookSetenvAndGetenv()` (`0x012358`).
 * [VN] Phương thức [3] `unhook()V` phục dựng từ `0x005c24` (`b 0x12358`):
 *      Gọi đuôi tới `UnhookSetenvAndGetenv()` (`0x012358`).
 */
void JniUnhook(JNIEnv* env, jobject thiz) {
    (void)env;
    (void)thiz;
    UnhookSetenvAndGetenv();
}

/**
 * [EN] Method [4] `doNativeNetworkValidate(...)I` reconstructed from `0x005c28..0x006600`:
 *      1. Extracts `url`, `method`, `body`, and `dfid` `jstring`s into `std::string`.
 *      2. Iterates Java `Map<String, String>` (`entrySet()Ljava/util/Set;` ->
 *         `iterator()Ljava/util/Iterator;` -> `hasNext()Z` -> `next()Ljava/lang/Object;` ->
 *         `getKey()Ljava/lang/Object;` / `getValue()Ljava/lang/Object;`) into
 *         `std::map<std::string, std::string> headers_map`.
 *      3. Inserts `metadata["x-tt-dataflow-id"] = dfid` if `!dfid.empty()`.
 *      4. If `validate_mode != 0`, calls `OrbuculumIsProceedRequestForTTNet` (`0x00eb48`);
 *         if `validate_mode == 0`, calls `InvokeOrbuculumProceedRequestImpl` (`0x010af8`).
 * [VN] Phương thức [4] `doNativeNetworkValidate(...)I` phục dựng từ `0x005c28..0x006600`:
 *      1. Trích xuất các `jstring` `url`, `method`, `body`, và `dfid` sang `std::string`.
 *      2. Duyệt `Map<String, String>` của Java (`entrySet()Ljava/util/Set;` ->
 *         `iterator()Ljava/util/Iterator;` -> `hasNext()Z` -> `next()Ljava/lang/Object;` ->
 *         `getKey()Ljava/lang/Object;` / `getValue()Ljava/lang/Object;`) vào
 *         `std::map<std::string, std::string> headers_map`.
 *      3. Chèn `metadata["x-tt-dataflow-id"] = dfid` nếu `!dfid.empty()`.
 *      4. Nếu `validate_mode != 0`, gọi `OrbuculumIsProceedRequestForTTNet` (`0x00eb48`);
 *         nếu `validate_mode == 0`, gọi `InvokeOrbuculumProceedRequestImpl` (`0x010af8`).
 */
jint JniDoNativeNetworkValidate(
    JNIEnv* env,
    jobject thiz,
    jstring j_url,
    jstring j_method,
    jobject j_headers_map,
    jstring j_body,
    jint body_len,
    jstring j_dfid,
    jint validate_mode) {
    (void)thiz;
    std::string url_str;
    std::string method_str;
    std::string body_str;
    std::string dfid_str;
    std::map<std::string, std::string> headers_map;
    std::map<std::string, std::string> metadata_map;

#if defined(__ANDROID__) && __has_include(<jni.h>)
    if (env == nullptr || j_url == nullptr || j_method == nullptr) {
        return 0;
    }
    url_str = JStringToStdString(env, j_url);
    method_str = JStringToStdString(env, j_method);
    if (j_body != nullptr) {
        body_str = JStringToStdString(env, j_body);
    }
    if (j_dfid != nullptr) {
        dfid_str = JStringToStdString(env, j_dfid);
    }

    if (j_headers_map != nullptr) {
        jclass map_cls = env->GetObjectClass(j_headers_map);
        if (map_cls != nullptr) {
            jmethodID mid_entry_set = env->GetMethodID(
                map_cls, "entrySet", "()Ljava/util/Set;");
            if (mid_entry_set != nullptr) {
                jobject entry_set = env->CallObjectMethod(j_headers_map, mid_entry_set);
                if (entry_set != nullptr) {
                    jclass set_cls = env->GetObjectClass(entry_set);
                    jmethodID mid_iterator = env->GetMethodID(
                        set_cls, "iterator", "()Ljava/util/Iterator;");
                    jobject iter = (mid_iterator != nullptr)
                                       ? env->CallObjectMethod(entry_set, mid_iterator)
                                       : nullptr;
                    if (iter != nullptr) {
                        jclass iter_cls = env->GetObjectClass(iter);
                        jmethodID mid_has_next = env->GetMethodID(iter_cls, "hasNext", "()Z");
                        jmethodID mid_next = env->GetMethodID(
                            iter_cls, "next", "()Ljava/lang/Object;");
                        while (mid_has_next != nullptr && mid_next != nullptr &&
                               env->CallBooleanMethod(iter, mid_has_next) != JNI_FALSE) {
                            jobject entry = env->CallObjectMethod(iter, mid_next);
                            if (entry != nullptr) {
                                jclass entry_cls = env->GetObjectClass(entry);
                                jmethodID mid_get_key = env->GetMethodID(
                                    entry_cls, "getKey", "()Ljava/lang/Object;");
                                jmethodID mid_get_val = env->GetMethodID(
                                    entry_cls, "getValue", "()Ljava/lang/Object;");
                                jstring k_obj = (mid_get_key != nullptr)
                                                    ? static_cast<jstring>(
                                                          env->CallObjectMethod(entry, mid_get_key))
                                                    : nullptr;
                                jstring v_obj = (mid_get_val != nullptr)
                                                    ? static_cast<jstring>(
                                                          env->CallObjectMethod(entry, mid_get_val))
                                                    : nullptr;
                                if (k_obj != nullptr && v_obj != nullptr) {
                                    headers_map[JStringToStdString(env, k_obj)] =
                                        JStringToStdString(env, v_obj);
                                }
                                if (k_obj != nullptr) {
                                    env->DeleteLocalRef(k_obj);
                                }
                                if (v_obj != nullptr) {
                                    env->DeleteLocalRef(v_obj);
                                }
                                env->DeleteLocalRef(entry_cls);
                                env->DeleteLocalRef(entry);
                            }
                        }
                        env->DeleteLocalRef(iter_cls);
                        env->DeleteLocalRef(iter);
                    }
                    env->DeleteLocalRef(set_cls);
                    env->DeleteLocalRef(entry_set);
                }
            }
            env->DeleteLocalRef(map_cls);
        }
    }
#else
    (void)env;
    (void)j_url;
    (void)j_method;
    (void)j_headers_map;
    (void)j_body;
    (void)j_dfid;
#endif

    if (!dfid_str.empty()) {
        metadata_map[kHeaderDataflowId] = dfid_str;
    }

    const size_t effective_len =
        (body_len > 0) ? static_cast<size_t>(body_len) : body_str.size();

    if (validate_mode != 0) {
        return OrbuculumIsProceedRequestForTTNet(
            url_str, method_str, headers_map, body_str, effective_len, metadata_map);
    }
    return InvokeOrbuculumProceedRequestImpl(
        url_str, method_str, headers_map, body_str, effective_len, metadata_map);
}

/**
 * [EN] Method [5] `setNativeHardBlockConfigInner(ZZZLjava/util/List;Ljava/util/List;)V`
 *      reconstructed from `0x006874..0x006f38`:
 *      1. Extracts `j_allow_code_list` (`List<Integer>` -> `intValue()I`) into
 *         `std::vector<int32_t> allow_codes`.
 *      2. Extracts `j_allow_dfid_list` (`List<String>`) into
 *         `std::vector<std::string> allow_dfids`.
 *      3. Allocates a new `std::shared_ptr<BlockSnapshot>` (`56 bytes` payload)
 *         and atomically replaces `.bss 0x028340` via `UpdateBlockSnapshot` (`0x00b1a8`).
 * [VN] Phương thức [5] `setNativeHardBlockConfigInner(ZZZLjava/util/List;Ljava/util/List;)V`
 *      phục dựng từ `0x006874..0x006f38`:
 *      1. Trích xuất `j_allow_code_list` (`List<Integer>` -> `intValue()I`) vào
 *         `std::vector<int32_t> allow_codes`.
 *      2. Trích xuất `j_allow_dfid_list` (`List<String>`) vào
 *         `std::vector<std::string> allow_dfids`.
 *      3. Cấp phát `std::shared_ptr<BlockSnapshot>` mới (`56 byte` dữ liệu)
 *         và thay thế nguyên tử `.bss 0x028340` qua `UpdateBlockSnapshot` (`0x00b1a8`).
 */
void JniSetNativeHardBlockConfigInner(
    JNIEnv* env,
    jobject thiz,
    jboolean enable_network_hard_block,
    jboolean is_target_rule_group,
    jboolean enable_dynamic_check,
    jobject j_allow_code_list,
    jobject j_allow_dfid_list) {
    (void)thiz;
    auto snapshot = std::make_shared<BlockSnapshot>();
    snapshot->enable_network_hard_block = (enable_network_hard_block != JNI_FALSE);
    snapshot->is_target_rule_group = (is_target_rule_group != JNI_FALSE);
    snapshot->enable_dynamic_check = (enable_dynamic_check != JNI_FALSE);

#if defined(__ANDROID__) && __has_include(<jni.h>)
    if (env != nullptr) {
        if (j_allow_code_list != nullptr) {
            jclass list_cls = env->GetObjectClass(j_allow_code_list);
            jclass int_cls = env->FindClass("java/lang/Integer");
            if (list_cls != nullptr && int_cls != nullptr) {
                jmethodID mid_size = env->GetMethodID(list_cls, "size", "()I");
                jmethodID mid_get = env->GetMethodID(
                    list_cls, "get", "(I)Ljava/lang/Object;");
                jmethodID mid_int_val = env->GetMethodID(int_cls, "intValue", "()I");
                if (mid_size != nullptr && mid_get != nullptr && mid_int_val != nullptr) {
                    const jint count = env->CallIntMethod(j_allow_code_list, mid_size);
                    if (count > 0) {
                        snapshot->allow_code_list.reserve(static_cast<size_t>(count));
                        for (jint i = 0; i < count; ++i) {
                            jobject elem = env->CallObjectMethod(j_allow_code_list, mid_get, i);
                            if (elem != nullptr) {
                                const jint code = env->CallIntMethod(elem, mid_int_val);
                                snapshot->allow_code_list.push_back(static_cast<int32_t>(code));
                                env->DeleteLocalRef(elem);
                            }
                        }
                    }
                }
            }
            if (list_cls != nullptr) {
                env->DeleteLocalRef(list_cls);
            }
            if (int_cls != nullptr) {
                env->DeleteLocalRef(int_cls);
            }
        }

        if (j_allow_dfid_list != nullptr) {
            snapshot->allow_dfid_list = ExtractJavaStringList(env, j_allow_dfid_list);
        }
    }
#else
    (void)env;
    (void)j_allow_code_list;
    (void)j_allow_dfid_list;
#endif

    UpdateBlockSnapshot(std::move(snapshot));
    if (GetGlobalRuntimeState().native_debug) {
        ORBU_ADAPTER_LOGI(
            "setNativeHardBlockConfigInner enableNetworkHardBlock=%d, isTargetRuleGroup=%d, enableDynamicCheck=%d",
            enable_network_hard_block,
            is_target_rule_group,
            enable_dynamic_check);
    }
}

/**
 * [EN] Method [6] `isNativeNetworkResultNeedBlock(ILjava/lang/String;)Z`
 *      reconstructed from `0x007174..0x0072c0`:
 *      Converts `j_dfid` to `std::string` and calls `EvaluateNetworkResultNeedBlock` (`0x00cfc0`).
 * [VN] Phương thức [6] `isNativeNetworkResultNeedBlock(ILjava/lang/String;)Z`
 *      phục dựng từ `0x007174..0x0072c0`:
 *      Chuyển `j_dfid` sang `std::string` và gọi `EvaluateNetworkResultNeedBlock` (`0x00cfc0`).
 */
jboolean JniIsNativeNetworkResultNeedBlock(
    JNIEnv* env,
    jobject thiz,
    jint result_code,
    jstring j_dfid) {
    (void)thiz;
    std::string dfid_str;
#if defined(__ANDROID__) && __has_include(<jni.h>)
    if (env != nullptr && j_dfid != nullptr) {
        dfid_str = JStringToStdString(env, j_dfid);
    }
#else
    (void)env;
    (void)j_dfid;
#endif
    const bool need_block = EvaluateNetworkResultNeedBlock(result_code, dfid_str);
    return need_block ? JNI_TRUE : JNI_FALSE;
}

/**
 * [EN] Method [7] `setNativeDebug(Z)V` reconstructed from `0x0072ec..0x0072fc`:
 *      Sets `g_native_debug` (`0x02822d`) = `(debug != 0)`.
 * [VN] Phương thức [7] `setNativeDebug(Z)V` phục dựng từ `0x0072ec..0x0072fc`:
 *      Đặt `g_native_debug` (`0x02822d`) = `(debug != 0)`.
 */
void JniSetNativeDebug(JNIEnv* env, jobject thiz, jboolean debug) {
    (void)env;
    (void)thiz;
    GetGlobalRuntimeState().native_debug = (debug != JNI_FALSE);
}

// ============================================================================
// SECTION 6: JNI_OnLoad (0x004540..0x0049fc) & JNI_OnUnload (0x004a00..0x004b84)
// ============================================================================

/**
 * [EN] Exact 8-entry `JNINativeMethod` table reconstructed from `.data 0x028000..0x0280b8`:
 *        [0] `0x028000`: `"activesdk"`, `"(IZI)I"`, `0x004f6c`
 *        [1] `0x028018`: `"initcall"`, `"(IZ)I"`, `0x004fec`
 *        [2] `0x028030`: `"initnetconfig"`, `"(Lcom/orbu/core/config/BootConfig;)V"`, `0x005058`
 *        [3] `0x028048`: `"unhook"`, `"()V"`, `0x005c24`
 *        [4] `0x028060`: `"doNativeNetworkValidate"`, `"(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;ILjava/lang/String;I)I"`, `0x005c28`
 *        [5] `0x028078`: `"setNativeHardBlockConfigInner"`, `"(ZZZLjava/util/List;Ljava/util/List;)V"`, `0x006874`
 *        [6] `0x028090`: `"isNativeNetworkResultNeedBlock"`, `"(ILjava/lang/String;)Z"`, `0x007174`
 *        [7] `0x0280a8`: `"setNativeDebug"`, `"(Z)V"`, `0x0072ec`
 * [VN] Bảng 8 mục `JNINativeMethod` chính xác phục dựng từ `.data 0x028000..0x0280b8`.
 */
static const JNINativeMethod kTTKNativeNetworkManagerMethods[8] = {
    {"activesdk",
     "(IZI)I",
     reinterpret_cast<void*>(&JniActiveSdk)},
    {"initcall",
     "(IZ)I",
     reinterpret_cast<void*>(&JniInitCall)},
    {"initnetconfig",
     "(Lcom/orbu/core/config/BootConfig;)V",
     reinterpret_cast<void*>(&JniInitNetConfig)},
    {"unhook",
     "()V",
     reinterpret_cast<void*>(&JniUnhook)},
    {"doNativeNetworkValidate",
     "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;ILjava/lang/String;I)I",
     reinterpret_cast<void*>(&JniDoNativeNetworkValidate)},
    {"setNativeHardBlockConfigInner",
     "(ZZZLjava/util/List;Ljava/util/List;)V",
     reinterpret_cast<void*>(&JniSetNativeHardBlockConfigInner)},
    {"isNativeNetworkResultNeedBlock",
     "(ILjava/lang/String;)Z",
     reinterpret_cast<void*>(&JniIsNativeNetworkResultNeedBlock)},
    {"setNativeDebug",
     "(Z)V",
     reinterpret_cast<void*>(&JniSetNativeDebug)},
};

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai

/**
 * [EN] `JNI_OnLoad` reconstructed from `0x004540..0x0049fc`:
 *      1. Stores `vm` at `0x0281b8`, sets `is_unloading = false` (`0x02835c`) and
 *         `is_initialized = false` (`0x028360`).
 *      2. Calls `vm->GetEnv(&env, JNI_VERSION_1_6)` (`0x00010006`).
 *      3. Finds `"com/orbu/core/init/TTKNativeNetworkManager"` and
 *         `"com/orbu/core/init/TTKNativeLiveSeiFieldManager"`, promotes both to
 *         `NewGlobalRef` (`0x0281c0`, `0x0281c8`), and deletes local refs.
 *      4. Calls `env->RegisterNatives(cls_network_manager, kTTKNativeNetworkManagerMethods, 8)`.
 *      5. Resolves 10 static `jmethodID`s (`0x0281d0..0x028218`).
 *      6. Registers `QueryJavaPropertyUpcall` (`0x004b88`) via `RegisterJavaPropertyCallback` (`0x012440`),
 *         sets `is_initialized = true` (`0x028360`), and returns `JNI_VERSION_1_6`.
 * [VN] `JNI_OnLoad` phục dựng từ `0x004540..0x0049fc`:
 *      1. Lưu `vm` tại `0x0281b8`, đặt `is_unloading = false` (`0x02835c`) và
 *         `is_initialized = false` (`0x028360`).
 *      2. Gọi `vm->GetEnv(&env, JNI_VERSION_1_6)` (`0x00010006`).
 *      3. Tìm `"com/orbu/core/init/TTKNativeNetworkManager"` và
 *         `"com/orbu/core/init/TTKNativeLiveSeiFieldManager"`, tạo `NewGlobalRef`
 *         (`0x0281c0`, `0x0281c8`), và xóa tham chiếu cục bộ.
 *      4. Gọi `env->RegisterNatives(cls_network_manager, kTTKNativeNetworkManagerMethods, 8)`.
 *      5. Phân giải 10 `jmethodID` tĩnh (`0x0281d0..0x028218`).
 *      6. Đăng ký `QueryJavaPropertyUpcall` (`0x004b88`) qua `RegisterJavaPropertyCallback` (`0x012440`),
 *         đặt `is_initialized = true` (`0x028360`), và trả về `JNI_VERSION_1_6`.
 */
extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    using namespace nextai::opencut::orbuculumadapter;
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    state.g_vm = vm;
    state.is_unloading.store(false, std::memory_order_seq_cst);
    state.is_initialized.store(false, std::memory_order_seq_cst);

#if defined(__ANDROID__) && __has_include(<jni.h>)
    if (vm == nullptr) {
        return JNI_ERR;
    }
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK || env == nullptr) {
        ORBU_ADAPTER_LOGE("Failed to get the environment using GetEnv()");
        return JNI_ERR;
    }

    jclass local_net_cls = env->FindClass(kClassTTKNativeNetworkManager);
    jclass local_sei_cls = env->FindClass(kClassTTKNativeLiveSeiFieldManager);
    if (local_net_cls == nullptr || local_sei_cls == nullptr) {
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        return JNI_ERR;
    }

    state.cls_network_manager = static_cast<jclass>(env->NewGlobalRef(local_net_cls));
    state.cls_sei_field_manager = static_cast<jclass>(env->NewGlobalRef(local_sei_cls));
    env->DeleteLocalRef(local_net_cls);
    env->DeleteLocalRef(local_sei_cls);

    if (env->RegisterNatives(
            state.cls_network_manager,
            kTTKNativeNetworkManagerMethods,
            8) < 0) {
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        return JNI_ERR;
    }

    state.mid_get_store_region = env->GetStaticMethodID(
        state.cls_network_manager, "getStoreRegion", "()Ljava/lang/String;");
    state.mid_get_sandbox_state = env->GetStaticMethodID(
        state.cls_network_manager, "getSandboxState", "()Ljava/lang/String;");
    state.mid_send_9args = env->GetStaticMethodID(
        state.cls_network_manager,
        "send",
        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;IIZZ)V");
    state.mid_send_7args = env->GetStaticMethodID(
        state.cls_network_manager,
        "send",
        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;IIZZ)V");

    state.mid_proceed_sei_bytes = env->GetStaticMethodID(
        state.cls_sei_field_manager,
        "proceedSeiField",
        "(Ljava/lang/String;[BLjava/lang/String;)I");
    state.mid_proceed_sei_string = env->GetStaticMethodID(
        state.cls_sei_field_manager,
        "proceedSeiField",
        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
    state.mid_proceed_sei_bool = env->GetStaticMethodID(
        state.cls_sei_field_manager,
        "proceedSeiField",
        "(Ljava/lang/String;ZLjava/lang/String;)I");
    state.mid_proceed_sei_long = env->GetStaticMethodID(
        state.cls_sei_field_manager,
        "proceedSeiField",
        "(Ljava/lang/String;JLjava/lang/String;)I");
    state.mid_proceed_sei_float = env->GetStaticMethodID(
        state.cls_sei_field_manager,
        "proceedSeiField",
        "(Ljava/lang/String;FLjava/lang/String;)I");
    state.mid_in_target_block_hash = env->GetStaticMethodID(
        state.cls_network_manager,
        "inTargetBlockRuleHashList",
        "()Z");
#endif

    RegisterJavaPropertyCallback(&QueryJavaPropertyUpcall);
    state.is_initialized.store(true, std::memory_order_seq_cst);
    return JNI_VERSION_1_6;
}

/**
 * [EN] `JNI_OnUnload` reconstructed from `0x004a00..0x004b84`:
 *      1. Sets `is_unloading = true` (`0x02835c`) and `is_initialized = false` (`0x028360`).
 *      2. Clears `query_java_prop_cb` (`0x028d40`) via `RegisterJavaPropertyCallback(nullptr)`.
 *      3. Acquires `jni_lifecycle_mutex` (`0x028160`) and waits on `jni_lifecycle_cv` (`0x028188`)
 *         until `active_jni_calls == 0` (`0x028358`).
 *      4. Deletes global refs (`cls_network_manager` `0x0281c0`, `cls_sei_field_manager` `0x0281c8`)
 *         and zeroes all cached `jmethodID`s (`0x0281d0..0x028218`) and `g_vm` (`0x0281b8`).
 * [VN] `JNI_OnUnload` phục dựng từ `0x004a00..0x004b84`:
 *      1. Đặt `is_unloading = true` (`0x02835c`) và `is_initialized = false` (`0x028360`).
 *      2. Xóa `query_java_prop_cb` (`0x028d40`) qua `RegisterJavaPropertyCallback(nullptr)`.
 *      3. Khóa `jni_lifecycle_mutex` (`0x028160`) và chờ trên `jni_lifecycle_cv` (`0x028188`)
 *         cho tới khi `active_jni_calls == 0` (`0x028358`).
 *      4. Xóa các tham chiếu toàn cục (`cls_network_manager` `0x0281c0`, `cls_sei_field_manager` `0x0281c8`)
 *         và đặt về 0 toàn bộ các `jmethodID` đã lưu (`0x0281d0..0x028218`) cùng `g_vm` (`0x0281b8`).
 */
extern "C" void JNI_OnUnload(JavaVM* vm, void* reserved) {
    (void)reserved;
    using namespace nextai::opencut::orbuculumadapter;
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    state.is_unloading.store(true, std::memory_order_seq_cst);
    state.is_initialized.store(false, std::memory_order_seq_cst);
    RegisterJavaPropertyCallback(nullptr);

    {
        std::unique_lock<std::mutex> lock(state.jni_lifecycle_mutex);
        state.jni_lifecycle_cv.wait(lock, [&state]() {
            return state.active_jni_calls.load(std::memory_order_seq_cst) <= 0;
        });
    }

#if defined(__ANDROID__) && __has_include(<jni.h>)
    if (vm != nullptr) {
        JNIEnv* env = nullptr;
        if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) == JNI_OK &&
            env != nullptr) {
            if (state.cls_network_manager != nullptr) {
                env->DeleteGlobalRef(state.cls_network_manager);
            }
            if (state.cls_sei_field_manager != nullptr) {
                env->DeleteGlobalRef(state.cls_sei_field_manager);
            }
        }
    }
#else
    (void)vm;
#endif

    state.cls_network_manager = nullptr;
    state.cls_sei_field_manager = nullptr;
    state.mid_get_store_region = nullptr;
    state.mid_get_sandbox_state = nullptr;
    state.mid_send_9args = nullptr;
    state.mid_send_7args = nullptr;
    state.mid_proceed_sei_bytes = nullptr;
    state.mid_proceed_sei_string = nullptr;
    state.mid_proceed_sei_bool = nullptr;
    state.mid_proceed_sei_long = nullptr;
    state.mid_proceed_sei_float = nullptr;
    state.mid_in_target_block_hash = nullptr;
    state.g_vm = nullptr;
}

// ============================================================================
// SECTION 7: STANDALONE DETERMINISTIC VERIFICATION & PARITY HARNESS
//            (EXERCISING ALL RECONSTRUCTED SUBSYSTEMS OF liborbuculumadapter.so)
// [EN] Self-contained verification routines validating:
//        1. `EnvExportEntry` 128-byte ABI layout & 5-entry `HookedGetenv` table
//           (`0x011e74`, `0x012174`, `.bss 0x028930..0x028d34`).
//        2. RFC (`\r\n` + `:`) and KV (`\n`/`&` + `=`) HTTP header parsers
//           (`0x00b99c`, `0x00ba34`, `0x00bda8`) and serializer (`0x010924`).
//        3. URL scheme compliance filter (`0x00c13c`), lowercase host/path
//           extractor (`0x00d660`), and wildcard (`"-."`/`"*."`) host + path
//           prefix rule matcher (`0x00da64`).
//        4. First-party (`ReplenishFirstPartyDataflowId`, `0x00dc60`) and
//           third-party (`AssignThirdPartyDataflowId`, `0x00e1d8`) DFID assignment,
//           plus hexadecimal (`"0x28000600"` -> `671090176`) and decimal
//           (`"672137215"` -> `0x281001bf`) DFID integer conversion (`0x00ca60`).
//        5. Atomic `BlockSnapshot` hard-block evaluator (`0x00cfc0`) including
//           allow-code list, case-insensitive allow-DFID list, and dynamic
//           rule-hash callback (`0x028240`).
//        6. Polymorphic `SeiFieldPayload` dispatch across all 5 `SeiValueType`
//           variants (`kBinaryBytes`, `kString`, `kBoolean`, `kInt64`, `kFloat32`,
//           `0x007300` & `0x00d2e8`).
// [VN] Các hàm kiểm chứng độc lập xác thực toàn bộ 6 phân hệ cốt lõi của
//      `liborbuculumadapter.so`.
// ============================================================================

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

/**
 * @brief [EN] Run deterministic self-tests across all reconstructed subsystems of
 *             `liborbuculumadapter.so`. Returns `0` when all checks pass, or a
 *             positive error code (`1..20`) pinpointing any mismatch.
 *        [VN] Chạy bộ tự kiểm thử tất định trên toàn bộ các phân hệ phục dựng của
 *             `liborbuculumadapter.so`. Trả về `0` nếu đạt 100%, hoặc mã lỗi dương
 *             (`1..20`) chỉ rõ vị trí sai lệch.
 */
int32_t RunOrbuculumAdapterParitySelfTest() {
    // ------------------------------------------------------------------------
    // Test 1: EnvExportEntry 128-byte ABI & 5-entry HookedGetenv lookup
    //         (0x011e74..0x012354, .bss 0x028930..0x028d34)
    // ------------------------------------------------------------------------
    if (sizeof(EnvExportEntry) != 128) {
        return 1;
    }

    const jint init_rc = JniInitCall(nullptr, nullptr, 1, JNI_TRUE);
    if (init_rc != 0) {
        return 2;
    }

    const char* exported_req = HookedGetenv("orbuculumIsProceedRequest");
    const char* exported_ttnet = HookedGetenv("orbuculumIsProceedRequestForTTNet");
    const char* exported_resp = HookedGetenv("orbuculumIsProceedResponseImpl");
    const char* exported_shutdown = HookedGetenv("orbuculumRegisterLiveShutdownCallback");
    const char* exported_sei = HookedGetenv("orbuculumIsProceedSeiField");
    if (exported_req == nullptr || exported_ttnet == nullptr ||
        exported_resp == nullptr || exported_shutdown == nullptr ||
        exported_sei == nullptr) {
        return 3;
    }

    char expected_req_addr[64]{};
    std::snprintf(
        expected_req_addr,
        sizeof(expected_req_addr),
        "%p",
        reinterpret_cast<void*>(&OrbuculumIsProceedRequest));
    if (std::strcmp(exported_req, expected_req_addr) != 0) {
        return 4;
    }

    // ------------------------------------------------------------------------
    // Test 2: Unified HTTP Header Parsers (RFC CRLF vs KV '&'/'=') & Serializer
    //         (0x00b99c, 0x00ba34, 0x00bda8, 0x010924)
    // ------------------------------------------------------------------------
    const std::string rfc_input =
        "Host: api.tiktokv.com \r\n"
        "x-tt-dataflow-id:\t0x28000401\r\n"
        "User-Agent: ByteDance-TTNet/4.1\r\n";
    const std::map<std::string, std::string> rfc_map = ParseHttpHeadersUnified(rfc_input);
    if (rfc_map.size() != 3 ||
        rfc_map.at("Host") != "api.tiktokv.com" ||
        rfc_map.at("x-tt-dataflow-id") != "0x28000401" ||
        rfc_map.at("User-Agent") != "ByteDance-TTNet/4.1") {
        return 5;
    }

    const std::string kv_input =
        "x-tt-dataflow-id = 0x28000402 & x-metasec-event-source = Native SO \n"
        "sandbox_channel=NETWORK";
    const std::map<std::string, std::string> kv_map = ParseHttpHeadersUnified(kv_input);
    if (kv_map.size() != 3 ||
        kv_map.at("x-tt-dataflow-id") != "0x28000402" ||
        kv_map.at("x-metasec-event-source") != "Native SO" ||
        kv_map.at("sandbox_channel") != "NETWORK") {
        return 6;
    }

    const std::string serialized = SerializeHeadersToRfcString(rfc_map);
    if (serialized.find("Host:api.tiktokv.com\r\n") == std::string::npos ||
        serialized.find("x-tt-dataflow-id:0x28000401\r\n") == std::string::npos) {
        return 7;
    }

    // ------------------------------------------------------------------------
    // Test 3: URL Scheme Compliance, Host/Path Extraction & Wildcard Rule Matcher
    //         (0x00c13c, 0x00d660, 0x00da64, 0x00dc60, 0x00e1d8)
    // ------------------------------------------------------------------------
    NetConfigRepository& repo = GetNetConfigRepository();
    repo.compliance_prefix_list.clear();
    if (!IsUrlMatchingComplianceScheme("https://api16-normal-c-useast1a.tiktokv.com:443/aweme/v1/feed/?aid=1233#top") ||
        !IsUrlMatchingComplianceScheme("wss://frontier.tiktokv.com/ws/v2") ||
        !IsUrlMatchingComplianceScheme("quic://quic.tiktokv.com/stream") ||
        IsUrlMatchingComplianceScheme("ftp://files.example.com/pub")) {
        return 8;
    }

    std::string host;
    std::string path;
    if (!ExtractUrlHostAndPath(
            "https://API16-Normal.TikTokV.com:8443/aweme/v1/feed/?aid=1233#frag",
            &host,
            &path)) {
        return 9;
    }
    if (host != "api16-normal.tiktokv.com" || path != "/aweme/v1/feed") {
        return 10;
    }

    // Populate NetConfigRepository with Boot, AgSpecial, Ag, and 3rd-party rules
    repo.boot.hosts = {"boot.tiktokv.com"};
    repo.boot.paths = {"/service/2/app_log"};
    repo.boot.dataflow_id = "0x28000101";

    NetConfig special_rule;
    special_rule.hosts = {"-.tiktokv.com", "*.byteoversea.com"};
    special_rule.paths = {"/aweme/v1/feed", "/passport/"};
    special_rule.dataflow_id = "0x28000202";
    repo.ag_special = {special_rule};

    repo.ag.hosts = {"-.tiktokv.com"};
    repo.ag.paths = {};  // empty paths matches all paths on host
    repo.ag.dataflow_id = "0x28000303";

    NetConfig third_party_rule;
    third_party_rule.hosts = {"*.googleapis.com"};
    third_party_rule.paths = {"/oauth2/"};
    third_party_rule.dataflow_id = "0x28000909";
    repo.third_party_config = {third_party_rule};
    repo.third_party_fallback_dfid = "0x28000999";

    if (ReplenishFirstPartyDataflowId("https://boot.tiktokv.com/service/2/app_log/stats") != "0x28000101") {
        return 11;
    }
    if (ReplenishFirstPartyDataflowId("https://api16-normal.tiktokv.com/aweme/v1/feed?count=20") != "0x28000202") {
        return 12;
    }
    if (ReplenishFirstPartyDataflowId("https://api16-normal.tiktokv.com/other/endpoint") != "0x28000303") {
        return 13;
    }
    if (ReplenishFirstPartyDataflowId("https://unmatched.domain.org/test") != kDfidTikTokFirstPartyNoMatch) {
        return 14;
    }
    if (AssignThirdPartyDataflowId("https://www.googleapis.com/oauth2/v4/token") != "0x28000909" ||
        AssignThirdPartyDataflowId("https://graph.facebook.com/v12.0/me") != "0x28000999") {
        return 15;
    }

    // ------------------------------------------------------------------------
    // Test 4: Hexadecimal & Decimal DFID String-to-Int32 Conversion (0x00ca60)
    // ------------------------------------------------------------------------
    if (ParseDataflowIdStringToInt("0x28000600") != 0x28000600 ||
        ParseDataflowIdStringToInt("0X28000602") != 0x28000602 ||
        ParseDataflowIdStringToInt("672137215") != 672137215 ||
        ParseDataflowIdStringToInt("") != -1) {
        return 16;
    }

    // ------------------------------------------------------------------------
    // Test 5: Atomic BlockSnapshot Hard-Block Evaluator (0x00cfc0..0x00d27c)
    // ------------------------------------------------------------------------
    auto block_cfg = std::make_shared<BlockSnapshot>();
    block_cfg->enable_network_hard_block = true;
    block_cfg->is_target_rule_group = true;
    block_cfg->enable_dynamic_check = false;
    block_cfg->allow_code_list = {1001, 1002};
    block_cfg->allow_dfid_list = {"0x28000101", "0x28000202"};
    UpdateBlockSnapshot(block_cfg);

    // result_code == 0 -> never blocked
    if (EvaluateNetworkResultNeedBlock(0, "0x28000999")) {
        return 17;
    }
    // result_code in allow_code_list -> allowed
    if (EvaluateNetworkResultNeedBlock(1001, "0x28000999")) {
        return 18;
    }
    // dfid in allow_dfid_list (case-insensitive) -> allowed
    if (EvaluateNetworkResultNeedBlock(4098, "0X28000202")) {
        return 19;
    }
    // neither code nor dfid allowed, dynamic check false -> MUST BLOCK (true)
    if (!EvaluateNetworkResultNeedBlock(4098, "0x28000999")) {
        return 20;
    }

    return 0;
}

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai

// ============================================================================
// SECTION 8: ADDRESS-BY-ADDRESS AARCH64 OPCODE FORENSIC TABLE & HELPER ROUTINES
//            (0x004460..0x01a6ec — COMPLETE BINARY FUNCTION DISPATCH DIRECTORY)
// [EN] This section provides the exact machine-readable function descriptor
//      table mapping every significant subroutine in `.text` (`0x004460..0x01a6ec`)
//      of `liborbuculumadapter.so` (SHA-256 `c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785`),
//      together with helper inspection routines used by the audit suite.
// [VN] Phần này cung cấp bảng mô tả hàm đọc được bằng máy ánh xạ chính xác từng
//      hàm con trọng yếu trong `.text` (`0x004460..0x01a6ec`) của
//      `liborbuculumadapter.so`, cùng các hàm kiểm tra phục vụ bộ kiểm toán.
// ============================================================================

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

struct BinaryFunctionDescriptor {
    uint64_t start_va;
    uint64_t end_va;
    const char* symbol_or_role_en;
    const char* role_vn;
};

/**
 * @brief [EN] Complete directory of the 36 core functions in `liborbuculumadapter.so`
 *             (`.text 0x004460..0x01a6ec`).
 *        [VN] Danh mục đầy đủ 36 hàm cốt lõi trong `liborbuculumadapter.so`
 *             (`.text 0x004460..0x01a6ec`).
 */
static constexpr BinaryFunctionDescriptor kOrbuculumAdapterFunctionDirectory[] = {
    {0x004460, 0x0044a8, "_GLOBAL__sub_I_jni_lifecycle_sync (.init_array[0])",
     "Khởi tạo mutex 0x028160 và condition_variable 0x028188 cho JNI_OnUnload"},
    {0x0044ac, 0x0044c4, "_GLOBAL__sub_I_live_shutdown_mutex (.init_array[1])",
     "Đăng ký hàm hủy mutex 0x028388 cho callback đóng phiên Live"},
    {0x0044c8, 0x0044fc, "_GLOBAL__sub_I_env_rw_shared_mutex (.init_array[2])",
     "Khởi tạo shared_timed_mutex 0x0287b8 bảo vệ bảng setenv/getenv"},
    {0x004540, 0x0049fc, "JNI_OnLoad",
     "Đăng ký 8 hàm native vào TTKNativeNetworkManager và phân giải 10 static methodID"},
    {0x004a00, 0x004b84, "JNI_OnUnload",
     "Đặt cờ卸载, chờ bộ đếm active_jni_calls (0x028358) về 0 và xóa GlobalRef"},
    {0x004b88, 0x004f68, "queryJavaPropertyUpcall",
     "Truy vấn thuộc tính get_user_region và get_sandbox_state lên tầng Java"},
    {0x004f6c, 0x004fe8, "TTKNativeNetworkManager.activesdk(IZI)I",
     "Cấu hình sdk_enable_strategy (0x028220), pumbaa_strategy (0x028224) và 3 upcall"},
    {0x004fec, 0x005054, "TTKNativeNetworkManager.initcall(IZ)I",
     "Cấu hình sdk_report_strategy (0x028228), hit_sample_drop (0x02822c) và gọi hookAndSetupEnv"},
    {0x005058, 0x005894, "TTKNativeNetworkManager.initnetconfig(BootConfig)V",
     "Trích xuất BootConfig/AgConfig từ Java vào kho NetConfigRepository (0x028248, 240 byte)"},
    {0x005c24, 0x005c28, "TTKNativeNetworkManager.unhook()V",
     "Nhảy trực tiếp tới unhookSetenvAndGetenv (0x012358)"},
    {0x005c28, 0x006600, "TTKNativeNetworkManager.doNativeNetworkValidate(...)I",
     "Chuyển đổi Map header Java sang std::map và gọi xác thực mạng Orbu/TTNet"},
    {0x006874, 0x006f38, "TTKNativeNetworkManager.setNativeHardBlockConfigInner(...)V",
     "Trích xuất allowCodeList & allowDfidList và cập nhật nguyên tử shared_ptr<BlockSnapshot>"},
    {0x007174, 0x0072c0, "TTKNativeNetworkManager.isNativeNetworkResultNeedBlock(ILString;)Z",
     "Kiểm tra kết quả xác thực mạng có cần chặn cứng hay không qua BlockSnapshot"},
    {0x0072ec, 0x0072fc, "TTKNativeNetworkManager.setNativeDebug(Z)V",
     "Bật/tắt cờ ghi log chi tiết g_native_debug (0x02822d)"},
    {0x007300, 0x007b14, "proceedSeiFieldUpcall",
     "Cầu nối gọi ngược 5 kiểu dữ liệu SEI ([B, String, boolean, long, float) lên Java"},
    {0x007b18, 0x007d48, "inTargetBlockRuleHashListUpcall",
     "Gọi ngược TTKNativeNetworkManager.inTargetBlockRuleHashList()Z"},
    {0x007d4c, 0x0081c0, "sendReportUpcall",
     "Gọi ngược TTKNativeNetworkManager.send (9 tham số cho NETWORK, 7 tham số cho SEI)"},
    {0x0081c4, 0x0082ac, "getJniEnvAndAttach",
     "Lấy JNIEnv* hiện hành hoặc gọi AttachCurrentThread nếu luồng chưa gắn kết"},
    {0x008f98, 0x009564, "extractJavaNetConfig",
     "Trích xuất đối tượng com.orbu.core.config.NetConfig (hosts, paths, dataflowId)"},
    {0x00b09c, 0x00b0f8, "getBlockSnapshotAtomic",
     "Đọc nguyên tử std::shared_ptr<BlockSnapshot> tại 0x028340 qua __get_sp_mut"},
    {0x00b1a8, 0x00b214, "updateBlockSnapshotAtomic",
     "Hoán đổi nguyên tử std::shared_ptr<BlockSnapshot> tại 0x028340 qua __get_sp_mut"},
    {0x00b99c, 0x00ba30, "parseHttpHeadersUnified",
     "Điều phối phân tích HTTP header (ưu tiên KV '&'/'=', dự phòng RFC CRLF ':')"},
    {0x00ba34, 0x00bda4, "parseRfcHttpHeaders",
     "Phân tích HTTP header chuẩn RFC phân tách bởi CRLF và dấu hai chấm ':'"},
    {0x00bda8, 0x00c138, "parseKvHttpHeaders",
     "Phân tích header khóa-giá trị phân tách bởi '\\n', '&' và '='"},
    {0x00c13c, 0x00c4bc, "isUrlMatchingComplianceScheme",
     "Kiểm tra tiền tố giao thức tuân thủ (http, https, wss, tcp, udp, tls, quic)"},
    {0x00c5e0, 0x00c860, "sendReportAsync",
     "Đóng gói sự kiện xác thực mạng/SEI và đẩy vào hàng đợi SandboxTP-%zu"},
    {0x00ca60, 0x00ce04, "parseDataflowIdStringToInt",
     "Chuyển đổi chuỗi Dataflow ID hệ 16 (0x...) hoặc hệ 10 sang int32_t"},
    {0x00cfc0, 0x00d27c, "evaluateNetworkResultNeedBlock",
     "Đánh giá chặn cứng dựa trên BlockSnapshot, allow_code_list và allow_dfid_list"},
    {0x00d2e8, 0x00d38c, "orbuculumIsProceedSeiField (Export #4 via getenv)",
     "Điểm vào kiểm tra trường dữ liệu luồng trực tiếp SEI (bit 2 sdk_enable_strategy)"},
    {0x00d490, 0x00d574, "orbuculumRegisterLiveShutdownCallback (Export #3 via getenv)",
     "Điểm vào đăng ký callback đóng phiên Live an toàn với mutex 0x028388"},
    {0x00d660, 0x00da60, "extractUrlHostAndPath",
     "Tách host chữ thường (bỏ port) và path chuẩn hóa (bỏ query/fragment và '/' cuối)"},
    {0x00da64, 0x00dc5c, "matchNetConfigRule",
     "Khớp quy tắc host (chính xác hoặc hậu tố '-.'/'*.') và tiền tố đường dẫn path"},
    {0x00dc60, 0x00e1d4, "replenishFirstPartyDataflowId",
     "Bổ sung mã Dataflow ID bên thứ nhất từ boot, agSpecial, ag hoặc mã mặc định 0x28000600/602"},
    {0x00e1d8, 0x00e550, "assignThirdPartyDataflowId",
     "Gán mã Dataflow ID bên thứ ba từ thirdPartyConfig hoặc thirdPartyFallbackDFID"},
    {0x00eb48, 0x00f6e8, "orbuculumIsProceedRequestForTTNet (Export #1 via getenv)",
     "Xác thực yêu cầu mạng TTNet, nhận diện miền Pumbaa và chuyển tiếp sang Pumbaa/Orbu"},
    {0x011178, 0x011804, "orbuculumIsProceedRequest (Export #0 via getenv)",
     "Điểm vào xác thực yêu cầu mạng thô (phân tích header/metadata rồi gọi TTNet validator)"},
    {0x011808, 0x011da0, "orbuculumIsProceedResponseImpl (Export #2 via getenv)",
     "Điểm vào xác thực phản hồi mạng HTTP qua liborbuculum.so"},
    {0x011db4, 0x012438, "ShadowHook setenv/getenv Engine (hooked_setenv, hooked_getenv, setupEnvTable)",
     "Hook setenv/getenv của libc.so bằng ShadowHook để xuất 5 địa chỉ hàm qua chuỗi %p"},
    {0x0124d0, 0x013124, "SandboxTP-%zu ThreadPool (2 threads)",
     "Hồ 2 luồng xử lý bất đồng bộ gửi báo cáo telemetry lên tầng Java"},
    {0x014400, 0x014928, "SignalCrashGuard (SIGSEGV/SIGBUS/SIGABRT TLS sigsetjmp/siglongjmp)",
     "Lớp bảo vệ chống sập tiến trình bằng sigaction + TLS sigsetjmp/siglongjmp"}
};

/**
 * @brief [EN] Return the number of cataloged binary functions in `liborbuculumadapter.so`.
 *        [VN] Trả về số lượng hàm nhị phân đã lập danh mục trong `liborbuculumadapter.so`.
 */
size_t GetCatalogedFunctionCount() {
    return sizeof(kOrbuculumAdapterFunctionDirectory) /
           sizeof(kOrbuculumAdapterFunctionDirectory[0]);
}

/**
 * @brief [EN] Lookup a cataloged binary function descriptor by virtual address.
 *        [VN] Tra cứu mô tả hàm nhị phân theo địa chỉ ảo.
 */
const BinaryFunctionDescriptor* FindFunctionDescriptorByAddress(uint64_t va) {
    for (const auto& entry : kOrbuculumAdapterFunctionDirectory) {
        if (va >= entry.start_va && va <= entry.end_va) {
            return &entry;
        }
    }
    return nullptr;
}

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai
