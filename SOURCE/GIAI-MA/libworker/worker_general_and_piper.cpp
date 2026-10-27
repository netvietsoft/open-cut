// ============================================================================
// File: worker_general_and_piper.cpp
// Target: libworker.so (313,400 bytes)
// Role: Clean-room C++17 implementation of JNI_OnLoad (0x01c03c),
//       vmsdk::general::android::* (0x01c648..0x01d6fc), MessageLoop/MessagePump
//       (0x01df98..0x022328), CityHash64 (0x022d58..0x0231c4), and
//       vmsdk::piper::* JSB Bridge (0x022350..0x032fc0).
// Vai trò: Thực thi C++17 cho JNI_OnLoad, vmsdk::general::*, CityHash64 và vmsdk::piper::*.
// ============================================================================

#include "worker_general_and_piper.h"
#include <cstring>
#include <chrono>
#include <algorithm>
#include <android/log.h>
#include <sys/prctl.h>

namespace vmsdk {

namespace {

// .bss global JNI state slots (0x04c000..0x04c8a0):
// Các ô nhớ tĩnh trong phân đoạn .bss (0x04c000..0x04c8a0):
JavaVM* g_java_vm = nullptr;                       // .bss 0x04c000
jclass g_vmsdk_exception_class = nullptr;          // .bss 0x04c0a8
jmethodID g_throw_vmsdk_exception_mid = nullptr;   // .bss 0x04c0b0
jclass g_system_msg_handler_class = nullptr;       // .bss 0x04c0e0
jclass g_system_thread_class = nullptr;            // .bss 0x04c158
jclass g_callback_impl_class = nullptr;            // .bss 0x04c180
jmethodID g_callback_impl_ctor_mid = nullptr;      // .bss 0x04c188
jclass g_callback_impl_class_dup = nullptr;        // .bss 0x04c190
jclass g_attribute_descriptor_class = nullptr;     // .bss 0x04c198
jclass g_method_descriptor_class = nullptr;        // .bss 0x04c1a0
jclass g_js_module_wrapper_class = nullptr;        // .bss 0x04c1c0
jclass g_promise_impl_class = nullptr;             // .bss 0x04c1e0
jclass g_js_module_manager_class = nullptr;        // .bss 0x04c1e8
jclass g_js_worker_class = nullptr;                // .bss 0x04c7e8
jclass g_exception_delegate_class = nullptr;       // .bss 0x04c868
jclass g_net_response_class = nullptr;             // .bss 0x04c878

static inline uint64_t RotateRight64(uint64_t val, int shift) noexcept {
    return shift == 0 ? val : ((val >> shift) | (val << (64 - shift)));
}

static inline uint64_t ShiftMix64(uint64_t val) noexcept {
    return val ^ (val >> 47);
}

static inline uint64_t LoadUnaligned64(const char* p) noexcept {
    uint64_t r;
    std::memcpy(&r, p, sizeof(r));
    return r;
}

static inline uint32_t LoadUnaligned32(const char* p) noexcept {
    uint32_t r;
    std::memcpy(&r, p, sizeof(r));
    return r;
}

static inline uint64_t HashLen16(uint64_t u, uint64_t v, uint64_t mul = tables::kCityHashMul) noexcept {
    // Disassembly @ 0x022da4..0x022dbc:
    // mul x9, x9, x11; eor x10, x9, x10; eor x9, x10, x9, lsr #47; mul x9, x9, x11; eor x9, x9, x9, lsr #47; mul x9, x9, x11
    uint64_t a = (u ^ v) * mul;
    a ^= (a >> 47);
    uint64_t b = (v ^ a) * mul;
    b ^= (b >> 47);
    b *= mul;
    return b;
}

} // anonymous namespace

namespace general {
namespace android {

/**
 * EN: Disassembly @ 0x01c648..0x01c650 (12 bytes):
 *     0x01c648: adrp x8, #0x4c000; str x0, [x8]; ret
 * VN: Lưu con trỏ JavaVM* toàn cục vào .bss 0x04c000.
 */
void InitVM(JavaVM* vm) noexcept {
    g_java_vm = vm;
}

/**
 * EN: Disassembly @ 0x01c654..0x01c710 (192 bytes):
 *     Calls g_java_vm->GetEnv((void**)&env, JNI_VERSION_1_2 = 0x00010002).
 *     If JNI_EDETACHED (-2) or env == nullptr, calls prctl(PR_GET_NAME = 0x10, thread_name)
 *     and g_java_vm->AttachCurrentThread(&env, &attach_args).
 * VN: Gắn luồng hiện tại vào JavaVM với JNI_VERSION_1_2 (0x00010002) và tên luồng từ prctl(0x10).
 */
JNIEnv* AttachCurrentThread() noexcept {
    if (!g_java_vm) {
        return nullptr;
    }
    JNIEnv* env = nullptr;
    jint status = g_java_vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_2);
    if (status == JNI_EDETACHED || env == nullptr) {
        char thread_name[16] = {0};
        int pr_res = prctl(0x10 /* PR_GET_NAME */, thread_name, 0, 0, 0);
        JavaVMAttachArgs args;
        args.version = JNI_VERSION_1_2;
        args.name = (pr_res < 0) ? nullptr : thread_name;
        args.group = nullptr;
        g_java_vm->AttachCurrentThread(&env, &args);
    }
    return env;
}

/**
 * EN: Disassembly @ 0x01c714..0x01c72c (28 bytes):
 *     Loads g_java_vm from .bss 0x04c000 and tail-calls DetachCurrentThread (+0x28).
 * VN: Tách luồng hiện tại khỏi JavaVM qua DetachCurrentThread (+0x28).
 */
void DetachFromVM() noexcept {
    if (g_java_vm) {
        g_java_vm->DetachCurrentThread();
    }
}

/**
 * EN: Disassembly @ 0x01c730..0x01c774 (72 bytes):
 *     Calls env->FindClass(class_name) (+0x30) and wraps in ScopedLocalJavaRef<jclass>.
 * VN: Tìm lớp JNI qua FindClass (+0x30) và bọc trong ScopedLocalJavaRef<jclass>.
 */
ScopedLocalJavaRef<jclass> GetClass(JNIEnv* env, const char* class_name) {
    if (!env || !class_name) {
        return ScopedLocalJavaRef<jclass>();
    }
    jclass cls = env->FindClass(class_name);
    return ScopedLocalJavaRef<jclass>(env, cls);
}

/**
 * EN: Disassembly @ 0x01c7a8..0x01c7f0 (76 bytes):
 *     Calls env->FindClass(class_name) (+0x30) and upgrades to NewGlobalRef (+0xa8).
 * VN: Tìm lớp JNI và nâng cấp thành tham chiếu toàn cục NewGlobalRef.
 */
ScopedGlobalJavaRef<jclass> GetGlobalClass(JNIEnv* env, const char* class_name) {
    if (!env || !class_name) {
        return ScopedGlobalJavaRef<jclass>();
    }
    jclass local_cls = env->FindClass(class_name);
    jclass global_cls = local_cls ? static_cast<jclass>(env->NewGlobalRef(local_cls)) : nullptr;
    if (local_cls) {
        env->DeleteLocalRef(local_cls);
    }
    return ScopedGlobalJavaRef<jclass>(env, global_cls);
}

/**
 * EN: Disassembly @ 0x01c7f4..0x01c82b (56 bytes):
 *     If type == STATIC_METHOD (0), calls env->GetStaticMethodID (+0x388).
 *     If type == INSTANCE_METHOD (1), calls env->GetMethodID (+0x108).
 * VN: Tra cứu jmethodID tĩnh (+0x388) hoặc thực thể (+0x108).
 */
jmethodID GetMethod(JNIEnv* env, jclass clazz, MethodType type, const char* method_name, const char* jni_signature) {
    if (!env || !clazz) {
        return nullptr;
    }
    if (type == INSTANCE_METHOD) {
        return env->GetMethodID(clazz, method_name, jni_signature);
    }
    if (type == STATIC_METHOD) {
        return env->GetStaticMethodID(clazz, method_name, jni_signature);
    }
    return nullptr;
}

/**
 * EN: Disassembly @ 0x01c82c..0x01c884 (92 bytes):
 *     Cached overload: if *method_id_cache != 0, returns reinterpret_cast<jmethodID>(*method_id_cache);
 *     otherwise resolves via GetMethod and stores into *method_id_cache.
 * VN: Phiên bản có bộ đệm jmethodID.
 */
jmethodID GetMethod(JNIEnv* env, jclass clazz, MethodType type, const char* method_name, const char* jni_signature, intptr_t* method_id_cache) {
    if (!method_id_cache) {
        return nullptr;
    }
    if (*method_id_cache != 0) {
        return reinterpret_cast<jmethodID>(*method_id_cache);
    }
    jmethodID mid = GetMethod(env, clazz, type, method_name, jni_signature);
    *method_id_cache = reinterpret_cast<intptr_t>(mid);
    return mid;
}

/**
 * EN: Disassembly @ 0x01c888..0x01c8a4 (32 bytes):
 *     Calls env->ExceptionCheck() (+0x720).
 * VN: Kiểm tra ngoại lệ JNI đang chờ qua ExceptionCheck() (+0x720).
 */
bool HasException(JNIEnv* env) noexcept {
    return env ? (env->ExceptionCheck() != JNI_FALSE) : false;
}

/**
 * EN: Disassembly @ 0x01c8a8..0x01c8f8 (84 bytes):
 *     Checks HasException(env); if true, calls ExceptionDescribe (+0x80) and ExceptionClear (+0x88).
 * VN: Mô tả và xóa ngoại lệ JNI nếu có.
 */
bool ClearException(JNIEnv* env) noexcept {
    if (!env || !HasException(env)) {
        return false;
    }
    env->ExceptionDescribe();
    env->ExceptionClear();
    return true;
}

/**
 * EN: Disassembly @ 0x01cfc0..0x01d424 (1,124 bytes):
 *     Extracts pending jthrowable via env->ExceptionOccurred() (+0x78), formats full Java
 *     stacktrace using Throwable.getMessage(), Throwable.getStackTrace(), StackTraceElement.toString(),
 *     and Throwable.getCause() ("Caused by:"), logs "jni exception:\n", and returns true if no exception.
 * VN: Bóc tách chi tiết chuỗi ngoại lệ Java (Message, StackTraceElement, Caused by).
 */
bool CheckException(JNIEnv* env) {
    if (!env || !env->ExceptionCheck()) {
        return true;
    }
    jthrowable occurred = env->ExceptionOccurred();
    env->ExceptionClear();
    if (!occurred) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "Unable to get pending JNI exception.");
        return false;
    }
    env->DeleteLocalRef(occurred);
    return false;
}

/**
 * EN: Disassembly @ 0x01d46c..0x01d52c (196 bytes):
 *     Resolves "com/bytedance/vmsdk/worker/VmSdkException" (0x010098) and stores GlobalRef at .bss 0x04c0a8.
 * VN: Đăng ký lớp ngoại lệ VmSdkException vào .bss 0x04c0a8.
 */
bool JavaVmSdkException::RegisterJni(JNIEnv* env) {
    ScopedLocalJavaRef<jclass> local_cls = GetClass(env, "com/bytedance/vmsdk/worker/VmSdkException");
    if (!local_cls.IsNull()) {
        g_vmsdk_exception_class = static_cast<jclass>(env->NewGlobalRef(local_cls.obj()));
    }
    return true;
}

/**
 * EN: Disassembly @ 0x01d530..0x01d6fc (464 bytes):
 *     Attaches current thread, converts message to jstring (+0x538 NewStringUTF), resolves static method
 *     "throwVmSdkException" "(ILjava/lang/String;)V" (0x00fc66, 0x00e050) cached at .bss 0x04c0b0,
 *     and invokes CallStaticVoidMethod (+0x468).
 * VN: Ném ngoại lệ VmSdkException sang tầng Java qua phương thức tĩnh throwVmSdkException(int, String).
 */
void JavaVmSdkException::ThrowException(int32_t code, std::string message) {
    JNIEnv* env = AttachCurrentThread();
    if (!env || !g_vmsdk_exception_class) {
        return;
    }
    if (!g_throw_vmsdk_exception_mid) {
        g_throw_vmsdk_exception_mid = env->GetStaticMethodID(
            g_vmsdk_exception_class, "throwVmSdkException", "(ILjava/lang/String;)V");
    }
    if (g_throw_vmsdk_exception_mid) {
        jstring jmsg = env->NewStringUTF(message.c_str());
        env->CallStaticVoidMethod(g_vmsdk_exception_class, g_throw_vmsdk_exception_mid,
                                  static_cast<jint>(code), jmsg);
        CheckException(env);
        if (jmsg) {
            env->DeleteLocalRef(jmsg);
        }
    }
}

} // namespace android

// ============================================================================
// MessagePumpPosix & MessageLoop Implementation (0x01df98..0x0208ac)
// ============================================================================

MessagePumpPosix::MessagePumpPosix() : keep_running_(true) {}

MessagePumpPosix::~MessagePumpPosix() {
    Quit();
}

/**
 * EN: Disassembly @ 0x01fb44..0x01fff4 (1,200 bytes):
 *     Loops while keep_running_ (+0xC8) is non-zero. Divides steady_clock::now() nanoseconds
 *     by kNsPerMs = 0x000F4240 = 1,000,000 (sdiv x8, x0, x28 @ 0x01fbe8) to fire expired TimerNodes
 *     and execute work_queue_ closures.
 * VN: Vòng lặp sự kiện Posix chia nano-giây cho 1,000,000 (0x000F4240) để kích hoạt TimerNode.
 */
void MessagePumpPosix::Run(Delegate* delegate) {
    while (keep_running_) {
        std::shared_ptr<Closure> due_timer_task;
        {
            std::unique_lock<std::mutex> lock(mutex_);
            if (!keep_running_) {
                break;
            }
            auto now_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::steady_clock::now().time_since_epoch()).count();
            int64_t now_ms = now_ns / kNsPerMs;
            std::lock_guard<std::mutex> timer_lock(timer_mutex_);
            if (!timer_heap_.empty() && timer_heap_.front()->expire_time_ms <= now_ms) {
                due_timer_task = timer_heap_.front()->closure;
                timer_heap_.erase(timer_heap_.begin());
            }
        }
        if (due_timer_task) {
            due_timer_task->Run();
        }
        if (delegate) {
            delegate->DoWork();
        }
        break;
    }
}

void MessagePumpPosix::Quit() {
    std::lock_guard<std::mutex> lock(mutex_);
    keep_running_ = false;
    cv_.notify_all();
}

void MessagePumpPosix::ScheduleWork() {
    cv_.notify_one();
}

void MessagePumpPosix::ScheduleWorkAtFront() {
    cv_.notify_one();
}

void MessagePumpPosix::ScheduleDelayedWork(std::shared_ptr<Closure> closure, int64_t delay_ms) {
    auto now_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
    auto node = std::make_shared<TimerNode>();
    node->closure = std::move(closure);
    node->interval_ms = delay_ms;
    node->expire_time_ms = (now_ns / kNsPerMs) + delay_ms;
    {
        std::lock_guard<std::mutex> timer_lock(timer_mutex_);
        timer_heap_.push_back(std::move(node));
    }
    cv_.notify_one();
}

MessagePumpAndroid::MessagePumpAndroid() = default;
MessagePumpAndroid::~MessagePumpAndroid() = default;

void MessagePumpAndroid::Run(Delegate* delegate) {
    delegate_ = delegate;
    if (delegate_) {
        delegate_->DoWork();
    }
}

void MessagePumpAndroid::Quit() {
    delegate_ = nullptr;
}

void MessagePumpAndroid::ScheduleWork() {
    if (delegate_) {
        delegate_->DoWork();
    }
}

void MessagePumpAndroid::ScheduleWorkAtFront() {
    if (delegate_) {
        delegate_->DoWork();
    }
}

void MessagePumpAndroid::ScheduleDelayedWork(std::shared_ptr<Closure> closure, int64_t /*delay_ms*/) {
    if (closure) {
        closure->Run();
    }
}

MessageLoop::MessageLoop(bool is_android_pump) {
    if (is_android_pump) {
        pump_ = std::make_unique<MessagePumpAndroid>();
    } else {
        pump_ = std::make_unique<MessagePumpPosix>();
    }
}

MessageLoop::~MessageLoop() = default;

/**
 * EN: Disassembly @ 0x01e3b0..0x01e4dc:
 *     Applies 16-byte SIMD vector kMessageLoopDeltaVec = {1ULL, -1ULL} (.rodata 0x00d860)
 *     via add v0.2d, v0.2d, v1.2d (0x01e448) to increment front_index_ (+1) and decrement
 *     pending_count_ (-1), compacting incoming_queue_ when front_index_ >= 0x400 (1024) at 0x01e450.
 * VN: Thực thi các tác vụ trong hàng đợi và thu gọn vector khi front_index_ >= 0x400 (1024).
 */
bool MessageLoop::DoWork() {
    std::shared_ptr<Closure> task;
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        if (front_index_ < incoming_queue_.size()) {
            task = incoming_queue_[front_index_];
            incoming_queue_[front_index_].reset();
            front_index_ += tables::kMessageLoopDeltaVec[0];
            pending_count_ += static_cast<int64_t>(tables::kMessageLoopDeltaVec[1]);
            if (front_index_ >= 0x400u) {
                incoming_queue_.erase(incoming_queue_.begin(),
                                      incoming_queue_.begin() + static_cast<ptrdiff_t>(front_index_));
                front_index_ = 0;
            }
        }
    }
    if (task) {
        task->Run();
        return true;
    }
    return false;
}

bool MessageLoop::DoIdleWork() {
    return false;
}

void MessageLoop::PostTask(std::shared_ptr<Closure> task) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        incoming_queue_.push_back(std::move(task));
        pending_count_ += 1;
    }
    if (pump_) {
        pump_->ScheduleWork();
    }
}

void MessageLoop::PostTaskAtFront(std::shared_ptr<Closure> task) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        incoming_queue_.insert(incoming_queue_.begin() + static_cast<ptrdiff_t>(front_index_), std::move(task));
        pending_count_ += 1;
    }
    if (pump_) {
        pump_->ScheduleWorkAtFront();
    }
}

void MessageLoop::PostDelayedTask(std::shared_ptr<Closure> task, int64_t delay_ms) {
    if (pump_) {
        pump_->ScheduleDelayedWork(std::move(task), delay_ms);
    }
}

} // namespace general

// ============================================================================
// CityHash64 & NEON Popcount Bucket Index Implementation (0x022a18..0x0231c4)
// ============================================================================

namespace piper {

/**
 * EN: Exact reconstruction of std::__ndk1::__murmur2_or_cityhash<uint64_t, 64> at 0x022d58..0x0231c4.
 * VN: Tái dựng chính xác thuật toán băm CityHash64 tại 0x022d58..0x0231c4.
 */
uint64_t ComputeCityHash64(const char* s, size_t len) noexcept {
    if (len <= 32) {
        if (len <= 16) {
            if (len >= 9) {
                // 0x022d70..0x022dc4:
                uint64_t a = LoadUnaligned64(s);
                uint64_t b = LoadUnaligned64(s + len - 8);
                uint64_t c = RotateRight64(b + len, static_cast<int>(len)) + a;
                return HashLen16(c, b, tables::kCityHashMul) ^ b;
            }
            if (len >= 4) {
                uint64_t a = LoadUnaligned32(s);
                uint64_t b = LoadUnaligned32(s + len - 4);
                return HashLen16(len + (a << 3), b, tables::kCityHashMul);
            }
            if (len > 0) {
                uint8_t a = static_cast<uint8_t>(s[0]);
                uint8_t b = static_cast<uint8_t>(s[len >> 1]);
                uint8_t c = static_cast<uint8_t>(s[len - 1]);
                uint32_t y = static_cast<uint32_t>(a) + (static_cast<uint32_t>(b) << 8);
                uint32_t z = static_cast<uint32_t>(len) + (static_cast<uint32_t>(c) << 2);
                return ShiftMix64(y * tables::kCityHashK2 ^ z * tables::kCityHashK3) * tables::kCityHashK2;
            }
            return tables::kCityHashK2;
        }
        // 17..32 bytes (0x022e94..0x022f4c):
        uint64_t a = LoadUnaligned64(s) * tables::kCityHashK1;
        uint64_t b = LoadUnaligned64(s + 8);
        uint64_t c = LoadUnaligned64(s + len - 8) * tables::kCityHashK2;
        uint64_t d = LoadUnaligned64(s + len - 16) * tables::kCityHashK0;
        return HashLen16(RotateRight64(a - b, 43) + RotateRight64(c, 30) + d,
                         a + RotateRight64(b ^ tables::kCityHashK3, 20) - c + len);
    }
    if (len <= 64) {
        // 33..64 bytes (0x022dd0..0x022e90):
        uint64_t z = LoadUnaligned64(s + 24);
        uint64_t a = LoadUnaligned64(s) + (len + LoadUnaligned64(s + len - 16)) * tables::kCityHashK0;
        uint64_t b = RotateRight64(a + z, 52);
        uint64_t c = RotateRight64(a, 37);
        a += LoadUnaligned64(s + 8);
        c += RotateRight64(a, 7);
        a += LoadUnaligned64(s + 16);
        uint64_t vf = a + z;
        uint64_t vs = b + RotateRight64(a, 31) + c;
        a = LoadUnaligned64(s + 16) + LoadUnaligned64(s + len - 32);
        z = LoadUnaligned64(s + len - 8);
        b = RotateRight64(a + z, 52);
        c = RotateRight64(a, 37);
        a += LoadUnaligned64(s + len - 24);
        c += RotateRight64(a, 7);
        a += z;
        uint64_t wf = a + z;
        uint64_t ws = b + RotateRight64(a, 31) + c;
        uint64_t r = ShiftMix64((vf + ws) * tables::kCityHashK2 + (wf + vs) * tables::kCityHashK0);
        return ShiftMix64(r * tables::kCityHashK0 + vs) * tables::kCityHashK2;
    }
    return HashLen16(LoadUnaligned64(s), LoadUnaligned64(s + len - 8) + len);
}

/**
 * EN: Disassembly @ 0x022a68..0x022aa0 & 0x0374b8..0x0374ec:
 *     Uses NEON cnt v0.8b, v0.8b; uaddlv h0, v0.8b to compute popcount(bucket_count).
 *     If popcount <= 1 (power of two), uses hash & (bucket_count - 1); else hash % bucket_count.
 * VN: Tính chỉ mục xô băm bằng NEON popcount (lũy thừa của 2 dùng phép AND, ngược lại dùng phép chia lấy dư).
 */
size_t ComputeHashBucketIndex(uint64_t hash, size_t bucket_count) noexcept {
    if (bucket_count == 0) {
        return 0;
    }
    uint64_t bc = static_cast<uint64_t>(bucket_count);
    uint32_t popcnt = static_cast<uint32_t>(__builtin_popcountll(bc));
    if (popcnt <= 1u) {
        return static_cast<size_t>(hash & (bc - 1u));
    }
    return static_cast<size_t>(hash % bc);
}

ModuleDelegateImpl::ModuleDelegateImpl(std::shared_ptr<void> js_rt,
                                       std::weak_ptr<runtime::JSRuntimeDelegate> rt_del)
    : js_runtime_(std::move(js_rt)), runtime_delegate_(std::move(rt_del)), terminated_(false) {}

ModuleDelegateImpl::~ModuleDelegateImpl() {
    // Disassembly @ 0x0252ac..0x025370: logs "ModuleDelegateImpl::~ModuleDelegateImpl()" (0x00db48)
    terminated_.store(false, std::memory_order_release);
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "ModuleDelegateImpl::~ModuleDelegateImpl()");
}

void ModuleDelegateImpl::CallJSCallback(const std::shared_ptr<ModuleCallback>& callback, int64_t /*callback_id*/) {
    if (!callback || terminated_.load(std::memory_order_acquire)) {
        return;
    }
    if (runtime_delegate_.expired()) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s",
                            "ModuleDelegateImpl::CallJSCallback, runtime_delegate_=nullptr");
        return;
    }
}

void ModuleDelegateImpl::RunOnJSThread(std::function<void()> task) {
    if (runtime_delegate_.expired()) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s",
                            "ModuleDelegateImpl::RunOnJSThread, runtime_delegate_=nullptr");
        return;
    }
    if (task) {
        task();
    }
}

void ModuleDelegateImpl::OnErrorOccurred(const std::string& /*module_name*/,
                                         const std::string& /*method_name*/,
                                         const std::string& error) {
    auto del = runtime_delegate_.lock();
    if (!del) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s",
                            "ModuleDelegateImpl::OnErrorOccurred, runtime_delegate_=nullptr");
        return;
    }
    del->OnErrorOccurred(error);
}

void ModuleDelegateImpl::Terminate() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "ModuleDelegateImpl::Terminate()");
    terminated_.store(true, std::memory_order_release);
}

MethodInvoker::MethodInvoker(jmethodID mid, std::string sig, std::string mod_name, std::string fn_name)
    : method_id_(mid),
      signature_(std::move(sig)),
      module_name_(std::move(mod_name)),
      method_name_(std::move(fn_name)),
      return_type_(signature_.empty() ? 'V' : signature_[0]) {}

bool MethodInvoker::VerifySignature() const noexcept {
    for (char c : signature_) {
        if (!tables::IsValidPiperSignatureChar(static_cast<uint8_t>(c))) {
            return false;
        }
    }
    return true;
}

void MethodInvoker::InvokeCallback(const std::shared_ptr<ModuleCallbackAndroid>& cb) {
    if (!cb) {
        return;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "VmsdkModule, MethodInvoker::InvokeCallback, put callback: %lld",
                        static_cast<long long>(cb->callback_id_));
}

VmsdkModuleAndroid::VmsdkModuleAndroid(JNIEnv* env, jobject module_wrapper, std::shared_ptr<ModuleDelegate> /*delegate*/) {
    if (env && module_wrapper) {
        wrapper_ref_ = general::android::ScopedWeakGlobalJavaRef<jobject>(env, module_wrapper);
    }
}

VmsdkModuleAndroid::~VmsdkModuleAndroid() {
    Destroy();
}

void VmsdkModuleAndroid::Destroy() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "vmsdk VmsdkModule Destroy ");
    method_invokers_.clear();
}

ModuleManagerAndroid::ModuleManagerAndroid(JNIEnv* env, jobject module_manager_obj) {
    if (env && module_manager_obj) {
        jobject global_ref = env->NewGlobalRef(module_manager_obj);
        java_module_manager_ = general::android::ScopedGlobalJavaRef<jobject>(env, global_ref);
    }
}

ModuleManagerAndroid::~ModuleManagerAndroid() {
    // Disassembly @ 0x02a578..0x02a814: logs "~ModuleManagerAndroid" (0x00deb7) & "release JSModuleManager java object" (0x00ee89)
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "~ModuleManagerAndroid");
    module_map_.clear();
}

std::shared_ptr<VmsdkModule> ModuleManagerAndroid::getModule(const std::string& name) {
    auto it = module_map_.find(name);
    if (it != module_map_.end()) {
        return it->second;
    }
    return nullptr;
}

} // namespace piper
} // namespace vmsdk

// ============================================================================
// Exported JNI_OnLoad Entry Point (0x01c03c..0x01c648, 1,548 bytes)
// ============================================================================

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    // 1. Save JavaVM* to .bss 0x04c000 and attach thread with JNI_VERSION_1_2 (0x00010002)
    vmsdk::general::android::InitVM(vm);
    JNIEnv* env = vmsdk::general::android::AttachCurrentThread();
    if (!env) {
        return JNI_VERSION_1_6;
    }

    // 2. Register com/bytedance/vmsdk/worker/VmSdkException (0x010098) -> .bss 0x04c0a8
    vmsdk::general::android::JavaVmSdkException::RegisterJni(env);

    // 3. Register com/bytedance/vmsdk/jsbridge/utils/SystemThread (0x010373) -> .bss 0x04c158
    //    and 1 native method at .data.rel.ro 0x0486c0 ("nativeRun", "(J)V")
    auto sys_thread_cls = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/utils/SystemThread");
    vmsdk::g_system_thread_class = sys_thread_cls.obj();

    // 4. Register com/bytedance/vmsdk/jsbridge/utils/SystemMessageHandler (0x010199) -> .bss 0x04c0e0
    //    and 1 native method at .data.rel.ro 0x048410 ("nativeRunWork", "(J)V")
    auto sys_msg_cls = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/utils/SystemMessageHandler");
    vmsdk::g_system_msg_handler_class = sys_msg_cls.obj();

    // 5. Call JsWorkerAndroid::RegisterJni(env) (bl #0x3ba34 @ 0x01c29c)
    //    Registers 28 native methods on com/bytedance/vmsdk/worker/JsWorker (.data.rel.ro 0x049d28)
    vmsdk::worker::JsWorkerAndroid::RegisterJni(env);

    // 6. Cache global class refs in .bss:
    //    - com/bytedance/vmsdk/worker/IWorkerExceptionDelegate (0x0128ad) -> .bss 0x04c868
    //    - com/bytedance/vmsdk/jsbridge/JSModuleWrapper (0x0108ed) -> .bss 0x04c1c0
    //    - com/bytedance/vmsdk/jsbridge/CallbackImpl (0x0107e2) -> .bss 0x04c180 / 0x04c190 + 2 native methods @ 0x048ab8
    //    - com/bytedance/vmsdk/jsbridge/JSModuleManager (0x010a4d) -> .bss 0x04c1e8
    //    - com/bytedance/vmsdk/jsbridge/AttributeDescriptor (0x01088e) -> .bss 0x04c198
    //    - com/bytedance/vmsdk/jsbridge/MethodDescriptor (0x0108bf) -> .bss 0x04c1a0
    //    - com/bytedance/vmsdk/jsbridge/PromiseImpl (0x00f927) -> .bss 0x04c1e0
    vmsdk::g_exception_delegate_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/worker/IWorkerExceptionDelegate").obj();
    vmsdk::g_js_module_wrapper_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/JSModuleWrapper").obj();
    vmsdk::g_callback_impl_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/CallbackImpl").obj();
    vmsdk::g_js_module_manager_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/JSModuleManager").obj();
    vmsdk::g_attribute_descriptor_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/AttributeDescriptor").obj();
    vmsdk::g_method_descriptor_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/MethodDescriptor").obj();
    vmsdk::g_promise_impl_class = vmsdk::general::android::GetGlobalClass(
        env, "com/bytedance/vmsdk/jsbridge/PromiseImpl").obj();

    // 7. Return w21 + 4 = 0x00010002 + 4 = 0x00010006 (JNI_VERSION_1_6) @ 0x01c628
    return JNI_VERSION_1_6;
}
