// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libpush_ka.so (18,184 bytes)
// SHA-256       : e8a32d5847f22373b03950fe22ee6ffa53a667ce77c57e018a2db9d409914281
// Task ID       : TASK-171-RECONSTRUCTION-LIBPUSH-KA
// Legacy Task   : TASK_SO_162_libpush_ka
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance Vega Push Keep-Alive Runtime
//     Address Resolver (`libpush_ka.so`, .text 0x0720..0x0824, 1 FDE @ 0x0890,
//     65 AArch64 instructions, 1 exported JNI symbol).
// VI: File header C++17 phòng sạch song ngữ cho Bộ phân giải Địa chỉ Runtime
//     Giữ Sống Tiến Trình Đẩy Vega (`libpush_ka.so`, .text 0x0720..0x0824,
//     1 FDE @ 0x0890, 65 lệnh AArch64, 1 biểu tượng JNI xuất khẩu).
// ============================================================================

#ifndef NEXTAI_OPENCUT_PUSH_KA_H_
#define NEXTAI_OPENCUT_PUSH_KA_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace push_ka {

// EN: Exact JNINativeInterface vtable byte offsets verified from AArch64 opcodes
//     inside `Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr`
//     (0x07c0..0x080c):
//       - `+0x5A0` (slot 180): `NewLongArray(JNIEnv*, jsize)` (`ldr x8, [x8, #0x5a0]` @ 0x07cc)
//       - `+0x5E0` (slot 188): `GetLongArrayElements(JNIEnv*, jlongArray, jboolean*)` (`ldr x8, [x8, #0x5e0]` @ 0x07e4)
//       - `+0x620` (slot 196): `ReleaseLongArrayElements(JNIEnv*, jlongArray, jlong*, jint)` (`ldr x8, [x8, #0x620]` @ 0x0804)
// VI: Các độ lệch byte chính xác trong bảng hàm ảo `JNINativeInterface` xác minh từ
//     mã máy AArch64 tại `0x07c0..0x080c`:
//       - `+0x5A0` (ô 180): `NewLongArray` (0x07cc)
//       - `+0x5E0` (ô 188): `GetLongArrayElements` (0x07e4)
//       - `+0x620` (ô 196): `ReleaseLongArrayElements` (0x0804)
constexpr size_t kJniVtableOffsetNewLongArray         = 0x5A0U;
constexpr size_t kJniVtableOffsetGetLongArrayElements = 0x5E0U;
constexpr size_t kJniVtableOffsetReleaseLongArrayElem = 0x620U;
constexpr int32_t kReturnedAddressPairLength          = 2;

// EN: Exact `.rodata` strings (0x0824..0x088e, 106 bytes):
//     - `0x0824`: `"libandroid_runtime.so"`
//     - `0x083A`: `"_ZN7android14AndroidRuntime10getRuntimeEv"` (`android::AndroidRuntime::getRuntime()`)
//     - `0x0864`: `"_ZN7android14AndroidRuntime8setArgv0EPKcb"` (`android::AndroidRuntime::setArgv0(char const*, bool)`)
// VI: Các chuỗi hằng trong `.rodata` (0x0824..0x088e, 106 byte).
constexpr const char* kTargetRuntimeLibraryName  = "libandroid_runtime.so";
constexpr const char* kSymAndroidRuntimeGet      = "_ZN7android14AndroidRuntime10getRuntimeEv";
constexpr const char* kSymAndroidRuntimeSetArgv0 = "_ZN7android14AndroidRuntime8setArgv0EPKcb";

// EN: Clean-room JNI types modeling the AArch64 `JNIEnv` dispatch table at
//     offsets `+0x5A0`, `+0x5E0`, and `+0x620`.
// VI: Các kiểu JNI phòng sạch mô hình hóa bảng điều phối `JNIEnv` tại
//     offset `+0x5A0`, `+0x5E0` và `+0x620`.
struct PushKaJlongArrayObject {
    int64_t elements[2]{0, 0};
    int32_t length = 2;
    bool    pinned = false;
};

struct PushKaJniEnv;

using FnNewLongArray = PushKaJlongArrayObject* (*)(PushKaJniEnv* env, int32_t len);
using FnGetLongArrayElements = int64_t* (*)(PushKaJniEnv* env, PushKaJlongArrayObject* arr, uint8_t* is_copy);
using FnReleaseLongArrayElements = void (*)(PushKaJniEnv* env, PushKaJlongArrayObject* arr, int64_t* elems, int32_t mode);

struct alignas(8) PushKaJniNativeInterface {
    uint8_t                    reserved_000_59f[0x5A0];
    FnNewLongArray             NewLongArray;              // +0x5A0
    uint8_t                    reserved_5a8_5df[0x38];
    FnGetLongArrayElements     GetLongArrayElements;      // +0x5E0
    uint8_t                    reserved_5e8_61f[0x38];
    FnReleaseLongArrayElements ReleaseLongArrayElements;  // +0x620
};
static_assert(offsetof(PushKaJniNativeInterface, NewLongArray) == 0x5A0,
              "NewLongArray must be at vtable offset 0x5A0");
static_assert(offsetof(PushKaJniNativeInterface, GetLongArrayElements) == 0x5E0,
              "GetLongArrayElements must be at vtable offset 0x5E0");
static_assert(offsetof(PushKaJniNativeInterface, ReleaseLongArrayElements) == 0x620,
              "ReleaseLongArrayElements must be at vtable offset 0x620");

struct PushKaJniEnv {
    const PushKaJniNativeInterface* functions;
    PushKaJlongArrayObject          last_allocated_array;
};

// EN: Clean-room `android::AndroidRuntime` representation resolved via `npth_dlsym`.
// VI: Biểu diễn phòng sạch `android::AndroidRuntime` được phân giải qua `npth_dlsym`.
class CleanRoomAndroidRuntime {
public:
    static CleanRoomAndroidRuntime* getRuntime() noexcept;
    void setArgv0(const char* argv0, bool set_proc_name) noexcept;

    const std::string& argv0() const noexcept { return argv0_; }
    bool proc_name_updated() const noexcept { return proc_name_updated_; }

private:
    std::string argv0_ = "com.nextai.opencut";
    bool        proc_name_updated_ = false;
};

struct PushKaInsnRecord {
    uint32_t    va;
    uint32_t    opcode_word;
    const char* mnemonic;
    const char* operands;
};

extern const uint8_t          kPushKaRodata106[106];
extern const uint8_t          kPushKaLoadSegment0_2432[2432];
extern const uint8_t          kPushKaLoadSegment1_1007[1007];
extern const uint32_t         kPushKaPltWords32[32];
extern const uint32_t         kPushKaTextWords65[65];
extern const PushKaInsnRecord kPushKaDisassemblyTable97[97];

extern "C" {
void* npth_dlopen(const char* filename) noexcept;
void* npth_dlsym(void* handle, const char* symbol) noexcept;
int   npth_dlclose(void* handle) noexcept;

// EN: Exported JNI function at .dynsym[10] (VA 0x0768, size 188 bytes).
// VI: Hàm JNI xuất khẩu tại .dynsym[10] (VA 0x0768, kích thước 188 byte).
PushKaJlongArrayObject*
Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr(
    PushKaJniEnv* env, void* clazz) noexcept;
}  // extern "C"

void InitializePushKaJniEnv(PushKaJniEnv* env, PushKaJniNativeInterface* vtable) noexcept;
bool VerifyPushKaSelfTest() noexcept;

}  // namespace push_ka
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_PUSH_KA_H_
