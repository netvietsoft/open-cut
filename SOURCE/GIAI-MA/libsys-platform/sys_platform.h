// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libsys-platform.so (18,184 bytes)
// SHA-256       : 98d6a70902356f55fa38a2e62808865ada53250a97e2698ae19b37c8d785988b
// Task ID       : TASK-172-RECONSTRUCTION-LIBSYS-PLATFORM
// Legacy Task   : TASK_SO_088_libsys_platform
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance Vega Push Keep-Alive System
//     Platform Plugin (`libsys-platform.so`, .text 0x0bb0..0x0fb4, 8 FDEs @
//     0x0fc0, 257 AArch64 instructions, 7 exported functions).
// VI: File header C++17 phòng sạch song ngữ cho Plugin Hệ thống Giữ Sống Tiến
//     Trình Đẩy Vega (`libsys-platform.so`, .text 0x0bb0..0x0fb4, 8 FDE @
//     0x0fc0, 257 lệnh AArch64, 7 hàm xuất khẩu).
// ============================================================================

#ifndef NEXTAI_OPENCUT_SYS_PLATFORM_H_
#define NEXTAI_OPENCUT_SYS_PLATFORM_H_

#include <cstddef>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace sys_platform {

// EN: Constants verified from AArch64 opcodes in `libsys-platform.so`:
//     - JNINativeInterface offsets in `SysPlatform_lockfNonBlock` (0x0bf8..0x0cac):
//       `GetStringUTFChars` @ +0x548 (0x0c18), `ReleaseStringUTFChars` @ +0x550 (0x0c44).
//     - `open` flags & mode at 0x0c24..0x0c28: `O_RDWR | O_CREAT = 0x42`, mode `0660 = 0x1b0`.
//     - `flock` operation at 0x0c58 & 0x0c78: `LOCK_EX | LOCK_NB = 6`, retry sleep `5 us` (0x0c6c).
//     - `get_current_time` reciprocal constant at 0x0ce4..0x0cf4: `0x20C49BA5E353F7CFULL`.
//     - `prctl` options in `modify_process_name` / `get_process_name`: `PR_SET_NAME = 15` (0x0d50),
//       `PR_GET_NAME = 16` (0x0da0).
//     - `get_main_process_pid` poll interval at 0x0e64..0x0e68: `0x003D0900` (4,000,000 us = 4 sec).
// VI: Các hằng số xác minh từ mã máy AArch64 trong `libsys-platform.so`.
constexpr size_t   kJniOffsetGetStringUTFChars     = 0x548U;
constexpr size_t   kJniOffsetReleaseStringUTFChars = 0x550U;
constexpr int32_t  kLockFileOpenFlags              = 0x42;        // O_RDWR | O_CREAT
constexpr int32_t  kLockFileOpenMode               = 0x1B0;       // 0660
constexpr int32_t  kFlockExNonBlock                = 6;           // LOCK_EX (2) | LOCK_NB (4)
constexpr uint32_t kFlockRetryUsleep               = 5U;          // 5 microseconds
constexpr uint64_t kUsecToMsReciprocal64           = 0x20C49BA5E353F7CFULL;
constexpr int32_t  kPrctlSetName                   = 15;          // PR_SET_NAME
constexpr int32_t  kPrctlGetName                   = 16;          // PR_GET_NAME
constexpr uint32_t kPidofPollSleepUs               = 0x003D0900U; // 4,000,000 us (4s)

// EN: 2-pointer structure passed as first argument to `modify_process_name` (0x0d0c..0x0d80),
//     populated by `libpush_ka.so` (`KAImpl_getRuntimeAddr`):
//       - `+0x00`: `android::AndroidRuntime::getRuntime()` (`ldr x8, [x20]` @ 0x0d24)
//       - `+0x08`: `android::AndroidRuntime::setArgv0(const char*, bool)` (`ldr x9, [x20, #8]` @ 0x0d2c)
// VI: Cấu trúc 2 con trỏ hàm truyền vào tham số đầu của `modify_process_name` (0x0d0c..0x0d80).
struct AndroidRuntimeFunctionPair {
    void* (*get_runtime)();
    void  (*set_argv0)(void* runtime_self, const char* argv0, int set_proc_name);
};
static_assert(sizeof(AndroidRuntimeFunctionPair) == 16, "ABI size must be 16 bytes");

struct SysPlatformInsnRecord {
    uint32_t    va;
    uint32_t    opcode_word;
    const char* mnemonic;
    const char* operands;
    int32_t     fde_index;
};

extern const uint8_t               kSysPlatformRodata11[11];
extern const uint8_t               kSysPlatformLoadSegment0_4552[4552];
extern const uint32_t              kSysPlatformPltWords68[68];
extern const uint32_t              kSysPlatformTextWords257[257];
extern const SysPlatformInsnRecord kSysPlatformDisassemblyTable325[325];

extern "C" {
// EN: All 7 exported functions of `libsys-platform.so` (.dynsym indices 19, 20, 21, 22, 24, 27, 29).
// VI: Toàn bộ 7 hàm xuất khẩu của `libsys-platform.so` (.dynsym chỉ mục 19, 20, 21, 22, 24, 27, 29).
int32_t Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_lockfNonBlock(
    void* env, void* thiz, void* jpath) noexcept;
int32_t Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_unlockfNonBlock(
    void* env, void* thiz, int32_t fd) noexcept;
int64_t get_current_time() noexcept;
int32_t modify_process_name(const AndroidRuntimeFunctionPair* rt_pair, const char* new_name) noexcept;
const char* get_process_name() noexcept;
int32_t get_main_process_pid(const char* pkg_name) noexcept;
int32_t Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_waitpid(
    void* env, void* thiz, int32_t pid) noexcept;
}  // extern "C"

int64_t ComputeEpochMillisecondsFromTimeval(int64_t tv_sec, uint64_t tv_usec) noexcept;
int FormatPidofCommand(char* dst, size_t dst_cap, const char* pkg_name) noexcept;

}  // namespace sys_platform
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_SYS_PLATFORM_H_
