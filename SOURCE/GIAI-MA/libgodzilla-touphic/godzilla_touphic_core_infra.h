/**
 * @file godzilla_touphic_core_infra.h
 * @brief Core Signal-Safe Execution (`safe_execute`), Symbol Resolution, Tracepoint RB-Tree, and Native Alog/FFmpeg Helpers
 *        Hạ tầng Thực thi An toàn Tín hiệu (`safe_execute`), Phân giải Biểu tượng, Cây Đỏ-Đen Tracepoint, và Tiện ích Alog/FFmpeg
 *
 * Binary Verified Addresses / Địa chỉ nhị phân đã xác minh:
 *   - `TouphicInitUtil_initNativeAlog`: `0x009400..0x009478` (124 B)
 *   - `AvLockRegisterHelper_nativeIgnoreAVLockMgrRegister`: `0x00947c..0x0094e4` (108 B)
 *   - `av_lockmgr_register_proxy`: `0x0094e8..0x009534` (76 B)
 *   - `safe_execute`: `0x00db4c..0x00dc48` (252 B)
 *   - `init_sigaction`: `0x00dc4c..0x00dd8c` (324 B)
 *   - `signal_handler`: `0x00dd9c..0x00df60` (452 B)
 *   - `find_symbol_in_so`: `0x00df64..0x00e098` (308 B)
 *   - `tracepoint_trampoline`: `0x00e09c..0x00e0dc` (64 B)
 *   - `add_tracepoint`: `0x00e0f0..0x00e440` (848 B)
 *   - `clear_tracepoints`: `0x00e444..0x00e538` (244 B)
 *   - `destroy_tracepoint_rbtree`: `0x00e53c..0x00e570` (52 B)
 *   - `convert_java_string_to_utf8`: `0x00e814..0x00e928` (276 B)
 */

#ifndef OPENCUT_GODZILLA_TOUPHIC_CORE_INFRA_H_
#define OPENCUT_GODZILLA_TOUPHIC_CORE_INFRA_H_

#include "godzilla_touphic_types.h"
#include <functional>

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {

/**
 * @brief Executes `task->target_fn(arg)` inside a thread-local `sigsetjmp` frame (`0x00db4c..0x00dc48`).
 *        Thực thi `task->target_fn(arg)` bên trong khung `sigsetjmp` cục bộ luồng (`0x00db4c..0x00dc48`).
 *
 * @param task Pointer to `TryExecuteTask` (`magic = 0x1a2b3c4d`).
 * @param arg  Opaque argument block passed to `task->target_fn`.
 * @return `0` on normal completion, `1` if a fatal signal (`SIGABRT`, `SIGTRAP`, `SIGSEGV`, `SIGBUS`) was caught and recovered.
 */
int safe_execute(TryExecuteTask* task, void* arg);

/**
 * @brief One-time initializer (`pthread_once` at `0x0178c0`) registering signal handlers (`0x00dc4c..0x00dd8c`).
 *        Hàm khởi tạo một lần (`pthread_once` tại `0x0178c0`) đăng ký các trình xử lý tín hiệu (`0x00dc4c..0x00dd8c`).
 */
void init_sigaction();

/**
 * @brief Signal handler (`SA_SIGINFO | SA_NODEFER`) for `SIGABRT(6)`, `SIGTRAP(5)`, `SIGSEGV(11)`, `SIGBUS(7)` (`0x00dd9c..0x00df60`).
 *        Trình xử lý tín hiệu (`SA_SIGINFO | SA_NODEFER`) cho `SIGABRT(6)`, `SIGTRAP(5)`, `SIGSEGV(11)`, `SIGBUS(7)` (`0x00dd9c..0x00df60`).
 */
void signal_handler(int signo, siginfo_t* info, void* ucontext);

/**
 * @brief Resolves a symbol address in a shared library via `npth_dlopen` (`npth_dlsym_size` / `npth_dlsym_symtab_size`)
 *        or fallback `shadowhook_dlopen` (`shadowhook_dlsym`) (`0x00df64..0x00e098`).
 *        Phân giải địa chỉ biểu tượng trong thư viện chia sẻ qua `npth_dlopen` hoặc `shadowhook_dlopen` (`0x00df64..0x00e098`).
 */
void* find_symbol_in_so(const char* so_name, const char* sym_name);

/**
 * @brief Installs an instruction-level tracepoint at `base_addr + offset` via `shadowhook_intercept_instr_addr`
 *        and inserts its stub token into the global Red-Black Tree (`0x00e0f0..0x00e440`).
 *        Cài đặt điểm vết lệnh tại `base_addr + offset` qua `shadowhook_intercept_instr_addr` và chèn vào Cây Đỏ-Đen (`0x00e0f0..0x00e440`).
 */
bool add_tracepoint(uintptr_t base_addr, int64_t offset,
                    std::function<void(ShadowHookCpuContext*)> callback);

/**
 * @brief Unhooks all registered instruction tracepoints and clears the Red-Black Tree (`0x00e444..0x00e538`).
 *        Gỡ toàn bộ các điểm vết lệnh đã đăng ký và xóa Cây Đỏ-Đen (`0x00e444..0x00e538`).
 */
void clear_tracepoints();

/**
 * @brief Converts a `jstring` to `std::string` UTF-8 safely (`0x00e814..0x00e928`).
 *        Chuyển đổi `jstring` sang `std::string` UTF-8 an toàn (`0x00e814..0x00e928`).
 */
std::string convert_java_string_to_utf8(JNIEnv* env, jstring jstr);

/**
 * @brief Formatted log helper (`0x009d9c`, `0x00ae7c`, `0x00ca08`, `0x00d020`, `0x00e574`).
 *        Hàm hỗ trợ định dạng chuỗi log (`__vsnprintf_chk`).
 */
void format_buffer(char* buf, size_t buf_size, const char* fmt, ...);

/**
 * @brief Initializes `libalog.so` (`alog_write` & `alog_write_default_instance`) (`0x009400..0x009478`).
 *        Khởi tạo `libalog.so` (`alog_write` & `alog_write_default_instance`) (`0x009400..0x009478`).
 */
jboolean init_native_alog_impl(JNIEnv* env, jclass clazz);

/**
 * @brief Hooks `av_lockmgr_register` in `libttffmpeg.so` to ignore conflicting lock managers (`0x00947c..0x009534`).
 *        Hook `av_lockmgr_register` trong `libttffmpeg.so` để bỏ qua trình quản lý khóa xung đột (`0x00947c..0x009534`).
 */
jboolean ignore_av_lockmgr_register_impl(JNIEnv* env, jclass clazz);

}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance

#endif  // OPENCUT_GODZILLA_TOUPHIC_CORE_INFRA_H_
