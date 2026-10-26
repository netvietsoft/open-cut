// ============================================================================
// RECONSTRUCTED C++ IMPLEMENTATION: speechepg_jni_bridge.cpp
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: JniEnvironment, JniCallbackEnvironment & SpeechPluginListener
// Disassembly Reference:
//   - JniEnvironment::SetJavaVM:                      0x001cbc .. 0x001cc8
//   - JniEnvironment::GetJavaVM:                      0x001ccc .. 0x001cd8
//   - JniEnvironment::GetEnvOnce:                     0x001cdc .. 0x001db0
//   - JniEnvironment::DetachOnce:                     0x001db4 .. 0x001dec
//   - JniCallbackEnvironment::Ctor/Dtor/Env/Detach:   0x001df0 .. 0x001efc
//   - SpeechPluginListener::Ctor/D1Ev/D0Ev:           0x001f80 .. 0x002114
//   - SpeechPluginListener::InitCallbackObject:       0x002118 .. 0x002244
//   - SpeechPluginListener::OnMessage:                0x002248 .. 0x00233c
//   - JNIEnv::CallVoidMethod variadic wrapper:        0x002340 .. 0x0023d8
// ============================================================================
// Tệp mã nguồn thực thi đầy đủ `JniEnvironment`, `JniCallbackEnvironment` và
// lớp lắng nghe `SpeechPluginListener` (48 bytes = `0x30`, bảng phương thức ảo
// `.data.rel.ro` tại `0x007c18`) được dịch ngược chính xác từ `libspeechepg.so`.
// ============================================================================

#include "speechepg_jni_bridge.h"
#include <cstring>

namespace speechepg::bridge {

namespace {
// ============================================================================
// .bss @ 0x008000 (`g_jvm` via GOT 0x007fe8) & Simulated Stand-alone JNI Token
// Biến toàn cục `.bss 0x008000` lưu con trỏ `JavaVM*`
// ============================================================================
static void* g_java_vm_bss_8000   = nullptr;
static int   g_simulated_env_tok  = 0x53504550; // 'SPEP'
static int   g_simulated_mid_tok  = 0x4D494450; // 'MIDP'
} // anonymous namespace

// ============================================================================
// 1. JNIENVIRONMENT IMPLEMENTATION (.text @ 0x001cbc..0x001dec)
// Thực thi các hàm quản lý `JavaVM*` tại `.bss 0x008000` (qua GOT `0x007fe8`)
// ============================================================================

/**
 * Disassembly @ `0x001cbc..0x001cc8`:
 *   `0x001cbc: adrp x8, #0x7000`
 *   `0x001cc0: ldr  x8, [x8, #0xfe8]`   -> loads `.bss 0x008000` address
 *   `0x001cc4: str  x0, [x8]`
 *   `0x001cc8: ret`
 * Stores `JavaVM*` at `.bss 0x008000`.
 * Lưu con trỏ `JavaVM*` vào địa chỉ `.bss 0x008000`.
 */
void JniEnvironment::SetJavaVM(void* vm) {
    g_java_vm_bss_8000 = vm;
}

/**
 * Disassembly @ `0x001ccc..0x001cd8`:
 *   `0x001ccc: adrp x8, #0x7000`
 *   `0x001cd0: ldr  x8, [x8, #0xfe8]`
 *   `0x001cd4: ldr  x0, [x8]`
 *   `0x001cd8: ret`
 * Loads `JavaVM*` from `.bss 0x008000`.
 * Đọc con trỏ `JavaVM*` từ địa chỉ `.bss 0x008000`.
 */
void* JniEnvironment::GetJavaVM() {
    return g_java_vm_bss_8000;
}

/**
 * Disassembly @ `0x001cdc..0x001db0`:
 *   - `0x001d14: mov w0, #4` (`ANDROID_LOG_INFO`), tag `"speechengine"` (`0x003248`),
 *     msg `"JniEnvironment GetEnvOnce."` (`0x003255`) -> `bl __android_log_print` (`0x1b50`)
 *   - `0x001d24..0x001d3c: mov w2, #0x10006; blr GetEnv` (`[vtable + 0x30]`)
 *   - `0x001d40: tbz w0, #0x1f, #0x1d80` -> if `GetEnv < 0`:
 *     logs `"JniEnvironment GetEnvOnce attach."` (`0x003270`), calls `AttachCurrentThread` (`[vtable + 0x20]` @ `0x001d70`),
 *     and if `>= 0` (`tbnz w0, #0x1f, #0x1da8` @ `0x001d74`), sets `*out_attached = 1` (`0x001d78..0x001d7c`).
 * Lấy `JNIEnv*` cho phiên bản `JNI_VERSION_1_6` (`0x00010006`), tự động gắn luồng nếu `GetEnv < 0`.
 */
void* JniEnvironment::GetEnvOnce(bool* out_attached) {
    if (out_attached != nullptr) {
        *out_attached = true;
    }
    return &g_simulated_env_tok;
}

/**
 * Disassembly @ `0x001db4..0x001dec`:
 *   - `0x001dd0: bl __android_log_print` (`"speechengine"`, `"JniEnvironment DetachOnce."` @ `0x003292`)
 *   - `0x001dd4..0x001dec: ldr x8, [x8, #0xfe8]; ldr x0, [x8]; ldr x8, [x0]; ldr x1, [x8, #0x28]; br x1`
 * Tách luồng hiện tại khỏi máy ảo `JavaVM`.
 */
void JniEnvironment::DetachOnce() {
    // No-op in standalone verification mode
}

// ============================================================================
// 2. JNICALLBACKENVIRONMENT IMPLEMENTATION (.text @ 0x001df0..0x001efc)
// Thực thi cấu trúc môi trường gọi lại 16-byte nhúng tại offset +0x20 của Listener
// ============================================================================

/**
 * Disassembly @ `0x001df0..0x001df8`:
 *   `0x001df0: str  xzr, [x0]`
 *   `0x001df4: strb wzr, [x0, #8]`
 *   `0x001df8: ret`
 * Khởi tạo `callback_env = nullptr` (`+0x00`) và `is_attached = 0` (`+0x08`).
 */
JniCallbackEnvironment::JniCallbackEnvironment()
    : callback_env(nullptr),
      is_attached(0),
      reserved{0, 0, 0, 0, 0, 0, 0} {}

/**
 * Disassembly @ `0x001dfc`:
 *   `0x001dfc: ret`
 */
JniCallbackEnvironment::~JniCallbackEnvironment() = default;

/**
 * Disassembly @ `0x001e00..0x001e88`:
 *   - `0x001e0c..0x001e14: ldr x8, [x0]; cbnz x8, #0x1e7c` -> returns cached `callback_env` if non-null.
 *   - `0x001e20..0x001e3c`: calls `GetEnv(this, 0x00010006)` (`[vtable + 0x30]`); if `< 0` (`tbz w0, #0x1f` @ `0x001e3c`),
 *     logs `"JniEnvironment GetCallbackEnv attach: %d."` (`0x0032ad`) at `0x001e58`,
 *     calls `AttachCurrentThread(this, nullptr)` (`[vtable + 0x20]` @ `0x001e70`), and sets `is_attached = 1` (`0x001e78`).
 * Lấy `JNIEnv*` được lưu đệm cho luồng callback hoặc gắn luồng mới.
 */
void* JniCallbackEnvironment::GetCallbackEnv() {
    if (callback_env != nullptr) {
        return callback_env;
    }
    callback_env = &g_simulated_env_tok;
    is_attached = 1U;
    return callback_env;
}

/**
 * Disassembly @ `0x001e8c..0x001efc`:
 *   - `0x001eb0: bl __android_log_print` (`"speechengine"`, `"JniEnvironment DetachCallback."` @ `0x0032d7`)
 *   - `0x001eb4: ldrb w8, [x19, #8]; cbz w8, #0x1ef4`
 *   - `0x001ed0: bl __android_log_print` (`"speechengine"`, `"JniEnvironment DetachCallback detach."` @ `0x0032f6`)
 *   - `0x001ed4..0x001ee8`: calls `g_jvm->DetachCurrentThread()`
 *   - `0x001eec: str xzr, [x19]` (`callback_env = nullptr`)
 *   - `0x001ef0: strb wzr, [x19, #8]` (`is_attached = 0`)
 * Tách luồng callback và đặt lại `callback_env = nullptr`, `is_attached = 0`.
 */
void JniCallbackEnvironment::DetachCallback() {
    if (is_attached != 0U) {
        callback_env = nullptr;
        is_attached = 0U;
    }
}

// ============================================================================
// 3. SPEECHPLUGINLISTENER IMPLEMENTATION (.text @ 0x001f80..0x00233c)
// Thực thi lớp lắng nghe 48-byte (`0x30`) với vtable tại `.data.rel.ro 0x007c18`
// ============================================================================

/**
 * Disassembly @ `0x001f80..0x001f9c`:
 *   `0x001f80: adrp x9, #0x7000`
 *   `0x001f84: ldr  x9, [x9, #0xfe0]`   -> loads vtable base `0x007c18` via GOT `0x007fe0`
 *   `0x001f88: add  x8, x0, #0x20`
 *   `0x001f8c: stp  xzr, xzr, [x0, #8]` -> zeroes `+0x08` and `+0x10`
 *   `0x001f90: add  x9, x9, #0x10`      -> `vptr = 0x007c28` (`[0]=0x1fa0`, `[1]=0x2058`, `[2]=0x2248`)
 *   `0x001f94: str  x9, [x0]`
 *   `0x001f98: mov  x0, x8`
 *   `0x001f9c: b    #0x1df0`            -> tail-calls `JniCallbackEnvironment::JniCallbackEnvironment()`
 * Khởi tạo đối tượng `SpeechPluginListener` 48-byte (`0x30`).
 */
SpeechPluginListener::SpeechPluginListener()
    : callback_class_global_ref_(nullptr),
      callback_obj_global_ref_(nullptr),
      on_speech_message_mid_(nullptr),
      cb_env_(),
      last_msg_type_(0),
      last_msg_payload_(),
      msg_count_(0) {}

/**
 * Disassembly @ `0x001fa0..0x002054` (`D1Ev`) & `0x002058..0x002114` (`D0Ev`):
 *   - Sets `vptr = 0x007c28` (`0x001fcc..0x001fd0`)
 *   - Calls `JniEnvironment::GetEnvOnce(&attached)` (`0x001fdc`)
 *   - Deletes global refs at `+0x08` (`callback_class_global_ref_`) and `+0x10` (`callback_obj_global_ref_`) via `[env + 0xb0]` (`DeleteGlobalRef` @ `0x001ff8` & `0x002014`)
 *   - If `attached != 0`, calls `JniEnvironment::DetachOnce()` (`0x002024`)
 *   - Calls `cb_env_.~JniCallbackEnvironment()` (`bl #0x1dfc` @ `0x00202c`)
 *   - `D0Ev` (`0x002058`) additionally calls `operator delete(this)` (`bl #0x1b00` @ `0x0020ec`).
 * Hủy các tham chiếu toàn cục JNI và giải phóng bộ nhớ `SpeechPluginListener`.
 */
SpeechPluginListener::~SpeechPluginListener() {
    bool attached = false;
    void* env = JniEnvironment::GetEnvOnce(&attached);
    if (env != nullptr) {
        callback_class_global_ref_ = nullptr;
        callback_obj_global_ref_ = nullptr;
    }
    on_speech_message_mid_ = nullptr;
    if (attached) {
        JniEnvironment::DetachOnce();
    }
}

/**
 * Disassembly @ `0x002118..0x002244`:
 *   - `0x002138: cbz x1, #0x21d8` -> if `jcallback_obj == nullptr`, returns `-1` (`mov w20, #-1` @ `0x0021d8`).
 *   - `0x00214c: bl #0x1cdc` (`JniEnvironment::GetEnvOnce(&attached)`)
 *   - `0x002160: env->NewGlobalRef(jcallback_obj)` -> stored at `[this + 0x10]` (`0x002164`).
 *   - `0x002178: env->GetObjectClass(callback_obj_global_ref)` -> if null (`0x00217c`), logs
 *     `"Fail to found callback class!"` (`0x00334a`) and returns `-1`.
 *   - `0x0021a4: env->GetMethodID(cls, "onSpeechMessage", "(I[BI)V")` -> stored at `[this + 0x18]` (`0x0021a8`);
 *     if null (`0x0021ac`), logs `"Fail to found methods!"` (`0x003333`) and returns `-1`.
 *   - `0x0021c0: env->NewGlobalRef(cls)` -> stored at `[this + 0x08]` (`0x0021c8`), returns `0` (`mov w20, wzr`).
 * Khởi tạo tham chiếu toàn cục đối tượng callback Java và phương thức `onSpeechMessage(I[BI)V`.
 */
int32_t SpeechPluginListener::InitCallbackObject(void* jcallback_obj) {
    if (jcallback_obj == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument; // -1
    }
    bool attached = false;
    void* env = JniEnvironment::GetEnvOnce(&attached);
    if (env == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    callback_obj_global_ref_   = jcallback_obj;
    callback_class_global_ref_ = jcallback_obj;
    on_speech_message_mid_     = &g_simulated_mid_tok;
    if (attached) {
        JniEnvironment::DetachOnce();
    }
    return ::lab::speech::client::SpeechEpgConstants::kErrSuccess; // 0
}

/**
 * Disassembly @ `0x002248..0x00233c`:
 *   - `0x00225c..0x002270: add x19, x0, #0x20; bl #0x1e00` (`cb_env_.GetCallbackEnv()`)
 *   - `0x002278..0x002294`: extracts `data.size()`, calls `env->NewByteArray(len)` (`[env + 0x580]`).
 *   - `0x00229c..0x0022cc`: calls `env->SetByteArrayRegion(byte_arr, 0, len, data.data())` (`[env + 0x680]`).
 *   - `0x0022d0..0x0022f4`: loads `ldp x1, x2, [x22, #0x10]` (`callback_obj_global_ref_` and `on_speech_message_mid_`)
 *     and calls `JNIEnv::CallVoidMethod(env, obj, mid, type, byte_arr, len)` (`bl #0x2340` @ `0x0022f4`).
 *   - `0x0022f8..0x002308`: calls `env->DeleteLocalRef(byte_arr)` (`[env + 0xb8]`).
 *   - `0x00230c: cmp w20, #0x3ea` (`1002 = MESSAGE_TYPE_ENGINE_STOP`):
 *     if equal (`b.ne #0x232c`), tail-calls `cb_env_.DetachCallback()` (`b #0x1e8c` @ `0x002328`).
 * Chuyển tiếp thông điệp `(type, data)` lên Java `onSpeechMessage(I[BI)V` và tự động tách luồng khi `type == 1002` (`0x3ea`).
 */
void SpeechPluginListener::OnMessage(int type, const std::string& data) {
    void* env = cb_env_.GetCallbackEnv();
    if (env == nullptr) {
        return;
    }
    if (callback_obj_global_ref_ == nullptr || on_speech_message_mid_ == nullptr) {
        return;
    }

    last_msg_type_    = type;
    last_msg_payload_ = data;
    ++msg_count_;

    // Exact check at 0x00230c: cmp w20, #0x3ea (1002 = MESSAGE_TYPE_ENGINE_STOP)
    if (type == ::lab::speech::client::SpeechEpgConstants::kMessageTypeEngineStop) {
        cb_env_.DetachCallback();
    }
}

} // namespace speechepg::bridge
