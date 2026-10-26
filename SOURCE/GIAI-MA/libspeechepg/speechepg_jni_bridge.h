// ============================================================================
// RECONSTRUCTED C++ HEADER: speechepg_jni_bridge.h
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: JniEnvironment, JniCallbackEnvironment, SpeechPluginListener & Handler
// Reference Disassembly:
//   - JniEnvironment:         0x001cbc .. 0x001dec (.bss 0x008000 JavaVM* via GOT 0x007fe8)
//   - JniCallbackEnvironment: 0x001df0 .. 0x001efc (16 bytes at Listener + 0x20)
//   - SpeechPluginListener:   0x001f80 .. 0x00233c (48 bytes = 0x30, vtable 0x007c18)
//   - SpeechEngineHandler:    0x0024e0 .. 0x002724 (24 bytes = 0x18)
// ============================================================================
// Tệp tiêu đề định nghĩa các cấu trúc quản lý môi trường JNI (`JniEnvironment`,
// `JniCallbackEnvironment`), bộ lắng nghe sự kiện đa hình `SpeechPluginListener`
// (48 bytes, vtable tại `0x007c18`) và khối quản lý `SpeechEngineHandler` (24 bytes).
// ============================================================================

#pragma once

#include "speechepg_types.h"
#include "speechepg_sdk_client.h"
#include <cstdint>
#include <string>

namespace speechepg::bridge {

// ============================================================================
// 1. JNIENVIRONMENT — GLOBAL JAVAVM & ONE-SHOT THREAD ATTACH MANAGER
// Phục hồi từ .text @ 0x001cbc..0x001dec & .bss @ 0x008000 (via GOT 0x007fe8)
// ============================================================================
class JniEnvironment {
public:
    /**
     * @brief `sub_1cbc` (`0x001cbc..0x001cc8`): Stores `JavaVM*` at `.bss 0x008000` (via GOT `0x007fe8`).
     * Lưu con trỏ `JavaVM*` vào địa chỉ `.bss 0x008000`.
     */
    static void SetJavaVM(void* vm);

    /**
     * @brief `sub_1ccc` (`0x001ccc..0x001cd8`): Loads `JavaVM*` from `.bss 0x008000` (via GOT `0x007fe8`).
     * Đọc con trỏ `JavaVM*` từ địa chỉ `.bss 0x008000`.
     */
    static void* GetJavaVM();

    /**
     * @brief `sub_1cdc` (`0x001cdc..0x001db0`): Retrieves `JNIEnv*` for `JNI_VERSION_1_6` (`0x00010006`).
     * Logs `"JniEnvironment GetEnvOnce."` (`0x003255`) with priority `ANDROID_LOG_INFO = 4` (`mov w0, #4` @ `0x001d14`),
     * and if `GetEnv < 0` (`tbz w0, #0x1f, #0x1d80` @ `0x001d40`), attaches thread (`0x001d70`).
     * Lấy `JNIEnv*` một lần và tự động gắn luồng nếu cần thiết.
     */
    static void* GetEnvOnce(bool* out_attached);

    /**
     * @brief `sub_1db4` (`0x001db4..0x001dec`): Logs `"JniEnvironment DetachOnce."` (`0x003292`)
     * and tail-calls `g_jvm->DetachCurrentThread()` (`br x1` @ `0x001dec`).
     * Tách luồng hiện tại khỏi máy ảo `JavaVM`.
     */
    static void DetachOnce();
};

// ============================================================================
// 2. JNICALLBACKENVIRONMENT — EMBEDDED 16-BYTE CALLBACK THREAD ENV (AT +0x20)
// Phục hồi từ .text @ 0x001df0..0x001efc
// ============================================================================
struct JniCallbackEnvironment {
    static constexpr size_t kAbiSize = 16U; // +0x00 JNIEnv*, +0x08 uint8_t is_attached (+7B pad)

    void*   callback_env{nullptr}; // +0x00 (`str xzr, [x0]` @ 0x001df0)
    uint8_t is_attached{0};        // +0x08 (`strb wzr, [x0, #8]` @ 0x001df4)
    uint8_t reserved[7]{};

    // 0x001df0..0x001df8
    JniCallbackEnvironment();
    // 0x001dfc
    ~JniCallbackEnvironment();

    /**
     * @brief `sub_1e00` (`0x001e00..0x001e88`): Returns cached `callback_env` or attaches thread.
     * Logs `"JniEnvironment GetCallbackEnv attach: %d."` (`0x0032ad`) when `GetEnv < 0` (`tbz w0, #0x1f` @ `0x001e3c`).
     * Lấy hoặc gắn `JNIEnv*` cho luồng gọi lại (Callback Thread).
     */
    void* GetCallbackEnv();

    /**
     * @brief `sub_1e8c` (`0x001e8c..0x001efc`): Logs `"JniEnvironment DetachCallback."` (`0x0032d7`),
     * and if `is_attached != 0`, logs `"JniEnvironment DetachCallback detach."` (`0x0032f6`),
     * detaches thread, and resets `callback_env = nullptr`, `is_attached = 0`.
     * Tách luồng gọi lại khi nhận thông điệp kết thúc `MESSAGE_TYPE_ENGINE_STOP` (`1002 = 0x3ea` @ `0x00230c`).
     */
    void DetachCallback();
};

// ============================================================================
// 3. SPEECHPLUGINLISTENER — 48-BYTE (0x30) LISTENER SUBCLASS (VTABLE @ 0x007c18)
// Phục hồi từ .text @ 0x001f80..0x00233c & .data.rel.ro @ 0x007c18..0x007c38
// ============================================================================
/**
 * Exact 48-byte (`0x30`) ABI layout verified from `0x002580`, `0x001f80..0x00233c`:
 *   +0x00: `void* vptr` (`0x007c18 + 0x10 = 0x007c28`: `[0]=0x1fa0 D1Ev`, `[1]=0x2058 D0Ev`, `[2]=0x2248 OnMessage`)
 *   +0x08: `void* callback_class_global_ref` (`str x0, [x19, #8]` @ `0x0021c8`)
 *   +0x10: `void* callback_obj_global_ref` (`str x0, [x19, #0x10]` @ `0x002164`)
 *   +0x18: `void* on_speech_message_mid` (`str x0, [x19, #0x18]` @ `0x0021a8`)
 *   +0x20: `JniCallbackEnvironment cb_env` (`16 bytes`: `+0x20 callback_env`, `+0x28 is_attached`)
 */
class SpeechPluginListener : public ::lab::speech::client::Listener {
public:
    static constexpr size_t   kAbiSize     = 48U;        // `mov w0, #0x30` @ 0x002580
    static constexpr uint64_t kVtableVaddr = 0x007c18ULL;// 5 pointers (40 B) in .data.rel.ro
    static constexpr uint64_t kVptrVaddr   = 0x007c28ULL;// `add x9, x9, #0x10` @ 0x001f90

    // 0x001f80..0x001f9c
    SpeechPluginListener();

    // 0x001fa0..0x002054 (D1Ev) & 0x002058..0x002114 (D0Ev)
    ~SpeechPluginListener() override;

    /**
     * @brief `sub_2118` (`0x002118..0x002244`): Initializes global JNI references and resolves
     * `onSpeechMessage(I[BI)V` (`.rodata 0x003368` & `0x003378`).
     * Khởi tạo tham chiếu toàn cục đối tượng Java callback và tìm phương thức `onSpeechMessage(I[BI)V`.
     */
    int32_t InitCallbackObject(void* jcallback_obj);

    /**
     * @brief `sub_2248` (`0x002248..0x00233c`): Virtual slot `[2]` at `0x007c38`.
     * Marshals `data` into a `jbyteArray`, calls `onSpeechMessage(type, byteArray, len)` via `0x002340`,
     * deletes the local reference, and if `type == 1002` (`0x3ea` @ `0x00230c`), tail-calls
     * `cb_env_.DetachCallback()` (`b #0x1e8c` @ `0x002328`).
     * Hàm ảo nhận thông điệp từ `Engine` và chuyển tiếp lên phương thức Java `onSpeechMessage`.
     */
    void OnMessage(int type, const std::string& data) override;

    int32_t lastMessageType() const { return last_msg_type_; }
    const std::string& lastMessagePayload() const { return last_msg_payload_; }
    uint32_t messageCount() const { return msg_count_; }
    const JniCallbackEnvironment& callbackEnv() const { return cb_env_; }

private:
    void*                  callback_class_global_ref_{nullptr}; // +0x08
    void*                  callback_obj_global_ref_{nullptr};   // +0x10
    void*                  on_speech_message_mid_{nullptr};     // +0x18
    JniCallbackEnvironment cb_env_{};                           // +0x20..+0x2f
    int32_t                last_msg_type_{0};
    std::string            last_msg_payload_{};
    uint32_t               msg_count_{0};
};

// ============================================================================
// 4. SPEECHENGINEHANDLER — 24-BYTE (0x18) ENGINE CONTEXT HANDLE
// Phục hồi từ `createEngineToNative` @ 0x0024f8 (`mov w0, #0x18; bl operator new(nothrow)`)
// ============================================================================
struct SpeechEngineHandler {
    static constexpr size_t kAbiSize = 24U; // 0x18 bytes

    ::lab::speech::client::Engine*  engine{nullptr};   // +0x00 (`str x20, [x19]` @ 0x0025d8)
    SpeechPluginListener*           listener{nullptr}; // +0x08 (`str x21, [x19, #8]` @ 0x00259c)
    ::lab::speech::client::Options* options{nullptr};  // +0x10 (`str x21, [x19, #0x10]` @ 0x00254c)
};

static_assert(sizeof(SpeechEngineHandler) == 24U, "SpeechEngineHandler must be exactly 24 bytes (0x18)");

} // namespace speechepg::bridge
