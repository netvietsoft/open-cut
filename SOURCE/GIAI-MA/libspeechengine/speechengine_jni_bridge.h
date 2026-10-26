// ============================================================================
// RECONSTRUCTED C++ HEADER: speechengine_jni_bridge.h
// Target Library: libspeechengine.so (18,256 bytes, ELF64 AArch64)
// Module: JniEnvironment, JniCallbackEnvironment, SpeechEngineListener & Handler
// Reference Disassembly:
//   - JniEnvironment:         0x001cac .. 0x001ddc (.bss 0x008000 JavaVM*)
//   - JniCallbackEnvironment: 0x001de0 .. 0x001eec (16 bytes at Listener + 0x20)
//   - SpeechEngineHandler:    0x002068 .. 0x0022ac (24 bytes = 0x18)
//   - SpeechEngineListener:   0x002dd0 .. 0x00318c (48 bytes = 0x30, vtable 0x007c28)
// ============================================================================
// Tệp tiêu đề định nghĩa các cấu trúc quản lý môi trường JNI (`JniEnvironment`,
// `JniCallbackEnvironment`), bộ lắng nghe sự kiện đa hình `SpeechEngineListener`
// (48 bytes, vtable tại `0x007c28`) và khối quản lý `SpeechEngineHandler` (24 bytes).
// ============================================================================

#pragma once

#include "speechengine_types.h"
#include "speechengine_sdk_client.h"
#include <cstdint>
#include <string>
#include <vector>

namespace speechengine::bridge {

// ============================================================================
// 1. JNIENVIRONMENT — GLOBAL JAVAVM & ONE-SHOT THREAD ATTACH MANAGER
// Phục hồi từ .text @ 0x001cac..0x001ddc & .bss @ 0x008000
// ============================================================================
class JniEnvironment {
public:
    /**
     * @brief `sub_1cac` (`0x001cac..0x001cb8`): Stores `JavaVM*` at `.bss 0x008000`.
     * Lưu con trỏ `JavaVM*` vào địa chỉ `.bss 0x008000`.
     */
    static void SetJavaVM(void* vm);

    /**
     * @brief `sub_1cbc` (`0x001cbc..0x001cc8`): Loads `JavaVM*` from `.bss 0x008000`.
     * Đọc con trỏ `JavaVM*` từ địa chỉ `.bss 0x008000`.
     */
    static void* GetJavaVM();

    /**
     * @brief `sub_1ccc` (`0x001ccc..0x001da0`): Retrieves `JNIEnv*` for `JNI_VERSION_1_6` (`0x00010006`).
     * Logs `"JniEnvironment GetEnvOnce."` (`0x003245`); if detached, logs
     * `"JniEnvironment GetEnvOnce attach."` (`0x003260`), attaches thread, and sets `*out_attached = true`.
     * Lấy `JNIEnv*` một lần và tự động gắn luồng nếu cần thiết.
     */
    static void* GetEnvOnce(bool* out_attached);

    /**
     * @brief `sub_1da4` (`0x001da4..0x001ddc`): Logs `"JniEnvironment DetachOnce."` (`0x003282`)
     * and calls `g_jvm->DetachCurrentThread()` (`+0x28` in `JNIInvokeInterface`).
     * Tách luồng hiện tại khỏi máy ảo `JavaVM`.
     */
    static void DetachOnce();
};

// ============================================================================
// 2. JNICALLBACKENVIRONMENT — EMBEDDED 16-BYTE CALLBACK THREAD ENV (AT +0x20)
// Phục hồi từ .text @ 0x001de0..0x001eec
// ============================================================================
struct JniCallbackEnvironment {
    static constexpr size_t kAbiSize = 16U; // +0x00 JNIEnv*, +0x08 uint8_t is_attached (+7B pad)

    void*   callback_env{nullptr}; // +0x00 (`str xzr, [x0]` @ 0x001de0)
    uint8_t is_attached{0};        // +0x08 (`strb wzr, [x0, #8]` @ 0x001de4)
    uint8_t reserved[7]{};

    // 0x001de0..0x001de8
    JniCallbackEnvironment();
    // 0x001dec
    ~JniCallbackEnvironment();

    /**
     * @brief `sub_1df0` (`0x001df0..0x001e78`): Returns cached `callback_env` or attaches thread.
     * Logs `"JniEnvironment GetCallbackEnv attach: %d."` (`0x00329d`) when attaching.
     * Lấy hoặc gắn `JNIEnv*` cho luồng gọi lại (Callback Thread).
     */
    void* GetCallbackEnv();

    /**
     * @brief `sub_1e7c` (`0x001e7c..0x001eec`): Logs `"JniEnvironment DetachCallback."` (`0x0032c7`),
     * and if `is_attached != 0`, logs `"JniEnvironment DetachCallback detach."` (`0x0032e6`),
     * detaches thread, and resets `callback_env = nullptr`, `is_attached = 0`.
     * Tách luồng gọi lại khi nhận thông điệp kết thúc `MESSAGE_TYPE_ENGINE_STOP` (`1002 = 0x3ea`).
     */
    void DetachCallback();
};

// ============================================================================
// 3. SPEECHENGINELISTENER — 48-BYTE (0x30) LISTENER SUBCLASS (VTABLE @ 0x007c28)
// Phục hồi từ .text @ 0x002dd0..0x00318c & .data.rel.ro @ 0x007c28..0x007c48
// ============================================================================
/**
 * Exact 48-byte (`0x30`) ABI layout verified from `0x002108`, `0x002dd0..0x00318c`:
 *   +0x00: `void* vptr` (`0x007c28 + 0x10 = 0x007c38`: `[0]=0x2df0 D1Ev`, `[1]=0x2ea8 D0Ev`, `[2]=0x3098 OnMessage`)
 *   +0x08: `void* callback_class_global_ref` (`str x0, [x19, #8]` @ `0x003018`)
 *   +0x10: `void* callback_obj_global_ref` (`str x0, [x19, #0x10]` @ `0x002fb4`)
 *   +0x18: `void* on_speech_message_mid` (`str x0, [x19, #0x18]` @ `0x002ff8`)
 *   +0x20: `JniCallbackEnvironment cb_env` (`16 bytes`: `+0x20 callback_env`, `+0x28 is_attached`)
 */
class SpeechEngineListener : public ::lab::speech::client::Listener {
public:
    static constexpr size_t   kAbiSize     = 48U;        // `mov w0, #0x30` @ 0x002108
    static constexpr uint64_t kVtableVaddr = 0x007c28ULL;// 5 pointers (40 B) in .data.rel.ro
    static constexpr uint64_t kVptrVaddr   = 0x007c38ULL;// `add x9, x9, #0x10` @ 0x002de0

    // 0x002dd0..0x002dec
    SpeechEngineListener();

    // 0x002df0..0x002ea4 (D1Ev) & 0x002ea8..0x002f64 (D0Ev)
    ~SpeechEngineListener() override;

    /**
     * @brief `sub_2f68` (`0x002f68..0x003094`): Initializes global JNI references and resolves
     * `onSpeechMessage(I[BI)V` (`.rodata 0x0034b6` & `0x0034c6`).
     * Khởi tạo tham chiếu toàn cục đối tượng Java callback và tìm phương thức `onSpeechMessage(I[BI)V`.
     */
    int32_t InitCallbackObject(void* jcallback_obj);

    /**
     * @brief `sub_3098` (`0x003098..0x00318c`): Virtual slot `[2]` at `0x007c48`.
     * Marshals `data` into a `jbyteArray`, calls `onSpeechMessage(type, byteArray, len)`,
     * deletes the local reference, and if `type == 1002` (`0x3ea` @ `0x00315c`), calls
     * `cb_env_.DetachCallback()` (`b #0x1e7c` @ `0x003178`).
     * Hàm ảo nhận thông điệp từ `Engine` và chuyển tiếp lên phương thức Java `onSpeechMessage`.
     */
    void OnMessage(int type, const std::string& data) override;

    // Inspection helpers for verification test suite / Hàm hỗ trợ kiểm thử
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
// Phục hồi từ `createEngineToNative` @ 0x002080 (`mov w0, #0x18; bl operator new(nothrow)`)
// ============================================================================
/**
 * Exact 24-byte (`0x18`) ABI layout verified across `0x002068..0x002d50`:
 *   +0x00: `lab::speech::client::Engine* engine` (`str x20, [x19]` @ `0x002160`)
 *   +0x08: `SpeechEngineListener* listener` (`str x21, [x19, #8]` @ `0x002124`)
 *   +0x10: `lab::speech::client::Options* options` (`str x21, [x19, #0x10]` @ `0x0020d4`)
 */
struct SpeechEngineHandler {
    static constexpr size_t kAbiSize = 24U; // 0x18 bytes

    ::lab::speech::client::Engine*  engine{nullptr};   // +0x00
    SpeechEngineListener*           listener{nullptr}; // +0x08
    ::lab::speech::client::Options* options{nullptr};  // +0x10
};

static_assert(sizeof(SpeechEngineHandler) == 24U, "SpeechEngineHandler must be exactly 24 bytes (0x18)");

} // namespace speechengine::bridge
