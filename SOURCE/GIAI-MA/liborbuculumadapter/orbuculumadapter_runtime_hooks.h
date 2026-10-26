// ============================================================================
// File: orbuculumadapter_runtime_hooks.h
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
//
// [EN] Declarations for ShadowHook libc `setenv`/`getenv` symbol export table,
//      2-thread asynchronous `SandboxTP-%zu` ThreadPool, `sendAsync` telemetry
//      dispatcher, dynamic `dlopen`/`dlsym` bridges for `liborbuculum.so` and
//      `libpumbaa-network.so`, and TLS `sigsetjmp`/`siglongjmp` SignalCrashGuard
//      (0x00c5e0, 0x00d390..0x015ff0).
// [VN] Khai báo cho bảng xuất biểu tượng qua ShadowHook `setenv`/`getenv` của libc,
//      hồ luồng bất đồng bộ 2 luồng `SandboxTP-%zu`, bộ điều phối báo cáo
//      `sendAsync`, cầu nối `dlopen`/`dlsym` động tới `liborbuculum.so` và
//      `libpumbaa-network.so`, cùng cơ chế bảo vệ chống sập tín hiệu TLS
//      `sigsetjmp`/`siglongjmp` SignalCrashGuard (0x00c5e0, 0x00d390..0x015ff0).
// ============================================================================

#ifndef NEXTAI_OPENCUT_ORBUCULUMADAPTER_RUNTIME_HOOKS_H_
#define NEXTAI_OPENCUT_ORBUCULUMADAPTER_RUNTIME_HOOKS_H_

#include "orbuculumadapter_types.h"

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

// ============================================================================
// 1. SHADOWHOOK SETENV / GETENV HOOKS & EXPORT TABLE (0x011db4..0x012468)
// ============================================================================

/**
 * @brief [EN] Hooked `setenv` implementation (0x011db4..0x011e70).
 *             Acquires exclusive write lock on `g_env_rw_mutex` (`0x0287b8`),
 *             calls original `setenv(name, value, overwrite)`, and releases lock.
 *        [VN] Hàm `setenv` đã hook (0x011db4..0x011e70).
 *             Khóa ghi độc quyền trên `g_env_rw_mutex` (`0x0287b8`),
 *             gọi `setenv(name, value, overwrite)` gốc, và mở khóa.
 */
int HookedSetenv(const char* name, const char* value, int overwrite);

/**
 * @brief [EN] Hooked `getenv` implementation (0x011e74..0x01204c).
 *             1. If `g_env_table_initialized` (`0x028d34`) is true and `name != nullptr`,
 *                searches the 5-entry `g_env_export_table` (`0x028930`, stride 128 bytes)
 *                using `strcmp`: if matched, returns the `"%p"` address string at `+0x40`!
 *             2. Otherwise acquires shared read lock on `g_env_rw_mutex` (`0x0287b8`)
 *                and calls original `getenv(name)`.
 *        [VN] Hàm `getenv` đã hook (0x011e74..0x01204c).
 *             1. Nếu `g_env_table_initialized` (`0x028d34`) bật và `name != nullptr`,
 *                tìm kiếm trong bảng 5 mục `g_env_export_table` (`0x028930`, bước nhảy 128 byte)
 *                bằng `strcmp`: nếu khớp, trả về chuỗi địa chỉ `"%p"` tại `+0x40`!
 *             2. Ngược lại khóa đọc chia sẻ trên `g_env_rw_mutex` (`0x0287b8`)
 *                và gọi `getenv(name)` gốc.
 */
char* HookedGetenv(const char* name);

/**
 * @brief [EN] Populate the 5-entry `getenv` export table at `.bss 0x028930` (0x012174..0x012354).
 *        [VN] Điền bảng xuất 5 mục qua `getenv` tại `.bss 0x028930` (0x012174..0x012354).
 */
bool SetupEnvExportTable(
    void* fn_is_proceed_request,
    void* fn_is_proceed_request_ttnet,
    void* fn_is_proceed_response,
    void* fn_register_live_shutdown,
    void* fn_is_proceed_sei_field);

/**
 * @brief [EN] Initialize ShadowHook (`shadowhook_init(0, false)`), hook `"libc.so"`
 *             `"setenv"` and `"getenv"`, and populate the export table (0x012050..0x012170).
 *        [VN] Khởi tạo ShadowHook (`shadowhook_init(0, false)`), hook `"libc.so"`
 *             `"setenv"` và `"getenv"`, đồng thời điền bảng xuất hàm (0x012050..0x012170).
 */
int32_t HookAndSetupEnv(
    void* fn_is_proceed_request,
    void* fn_is_proceed_request_ttnet,
    void* fn_is_proceed_response,
    void* fn_register_live_shutdown,
    void* fn_is_proceed_sei_field);

/**
 * @brief [EN] Unhook `"setenv"` (`0x028868`) and `"getenv"` (`0x028870`) via
 *             `shadowhook_unhook` (0x012358..0x012438, called by JNI `unhook` at 0x005c24).
 *        [VN] Gỡ hook `"setenv"` (`0x028868`) và `"getenv"` (`0x028870`) qua
 *             `shadowhook_unhook` (0x012358..0x012438, được gọi bởi JNI `unhook` tại 0x005c24).
 */
void UnhookSetenvAndGetenv();

/**
 * @brief [EN] Register or clear the Java property query callback at `.bss 0x028d40` (0x012440).
 *        [VN] Đăng ký hoặc xóa callback truy vấn thuộc tính Java tại `.bss 0x028d40` (0x012440).
 */
void RegisterJavaPropertyCallback(QueryJavaPropertyCallbackFn cb);

/**
 * @brief [EN] Invoke the registered Java property callback (`"get_user_region"` or
 *             `"get_sandbox_state"`) from `.bss 0x028d40` (0x01246c..0x0124cc).
 *        [VN] Gọi callback thuộc tính Java đã đăng ký (`"get_user_region"` hoặc
 *             `"get_sandbox_state"`) từ `.bss 0x028d40` (0x01246c..0x0124cc).
 */
std::string InvokeJavaPropertyCallback(const std::string& key);

// ============================================================================
// 2. SANDBOX THREAD POOL & ASYNC TELEMETRY REPORTER (0x00c5e0, 0x0124d0..0x013124)
// ============================================================================

/**
 * @brief [EN] Enqueue an asynchronous task onto the 2-thread `SandboxTP-%zu` worker pool
 *             (0x0124d0..0x012ff4).
 *        [VN] Đưa một tác vụ bất đồng bộ vào hàng đợi của hồ 2 luồng `SandboxTP-%zu`
 *             (0x0124d0..0x012ff4).
 */
void EnqueueSandboxTask(std::function<void()> task);

/**
 * @brief [EN] Shut down the `SandboxTP-%zu` worker pool cleanly on process exit (0x013008).
 *        [VN] Đóng hồ luồng `SandboxTP-%zu` an toàn khi kết thúc tiến trình (0x013008).
 */
void ShutdownSandboxThreadPool();

/**
 * @brief [EN] Dispatch a sandbox validation telemetry event asynchronously via
 *             `SandboxTP-%zu` to `g_send_report_cb` (`0x028230`) (0x00c5e0..0x00c860).
 *        [VN] Gửi sự kiện telemetry xác thực sandbox bất đồng bộ qua `SandboxTP-%zu`
 *             tới `g_send_report_cb` (`0x028230`) (0x00c5e0..0x00c860).
 */
void SendReportAsync(
    const std::string& channel,
    const std::string& url_or_key,
    const std::string& method_or_val,
    const std::string& headers_str,
    const std::string& body_str,
    int32_t dataflow_id,
    int32_t sandbox_result,
    bool is_hit_rule,
    int64_t duration_us);

// ============================================================================
// 3. SIGNAL CRASH GUARD & DYNAMIC PEER BRIDGES (0x00d390..0x015ff0)
// ============================================================================

/**
 * @brief [EN] Execute a callable inside the TLS `sigsetjmp`/`siglongjmp` crash guard
 *             for `SIGSEGV` (11), `SIGBUS` (7), and `SIGABRT` (6) (0x014400..0x014928).
 *             If a signal is caught during execution, returns `fallback_return_value`.
 *        [VN] Thực thi một hàm bên trong lớp bảo vệ chống sập TLS `sigsetjmp`/`siglongjmp`
 *             cho `SIGSEGV` (11), `SIGBUS` (7), và `SIGABRT` (6) (0x014400..0x014928).
 *             Nếu bắt được tín hiệu lỗi trong lúc chạy, trả về `fallback_return_value`.
 */
int32_t ExecuteWithSignalCrashGuard(
    const std::function<int32_t()>& protected_fn,
    int32_t fallback_return_value = 0);

/**
 * @brief [EN] Query domain classification (`"tt_1st"`, `"bd_1st"`, `"bd_3rd"`, etc.)
 *             from `libpumbaa-network.so` (`domainIdentityRecognizeV2` or
 *             `domainIdentityRecognize`) via `dlopen`/`dlsym` (0x00eb48..0x00ef20).
 *        [VN] Truy vấn phân loại tên miền (`"tt_1st"`, `"bd_1st"`, `"bd_3rd"`, v.v.)
 *             từ `libpumbaa-network.so` (`domainIdentityRecognizeV2` hoặc
 *             `domainIdentityRecognize`) qua `dlopen`/`dlsym` (0x00eb48..0x00ef20).
 */
std::string RecognizeDomainIdentityViaPumbaa(const std::string& url);

/**
 * @brief [EN] Invoke `handleByPumbaaForSandbox` in `libpumbaa-network.so` (0x00ffac..0x010920).
 *             Returns `true` (`1`) if intercepted (`result == 0x1002 = 4098`), `false` (`0`) otherwise.
 *        [VN] Gọi `handleByPumbaaForSandbox` trong `libpumbaa-network.so` (0x00ffac..0x010920).
 *             Trả về `true` (`1`) nếu bị chặn (`result == 0x1002 = 4098`), `false` (`0`) nếu cho phép.
 */
int32_t InvokePumbaaSandboxValidate(
    const std::string& url,
    const std::string& method,
    const std::map<std::string, std::string>& headers,
    const std::string& body,
    const std::map<std::string, std::string>& metadata,
    int32_t pumbaa_strategy);

/**
 * @brief [EN] Invoke `orbuculumIsProceedRequestImpl` in `liborbuculum.so` inside the
 *             signal crash guard and dispatch async telemetry (0x010af8..0x011174).
 *        [VN] Gọi `orbuculumIsProceedRequestImpl` trong `liborbuculum.so` bên trong
 *             lớp bảo vệ tín hiệu và gửi báo cáo telemetry bất đồng bộ (0x010af8..0x011174).
 */
int32_t InvokeOrbuculumProceedRequestImpl(
    const std::string& url,
    const std::string& method,
    const std::map<std::string, std::string>& headers,
    const std::string& body,
    size_t body_len,
    const std::map<std::string, std::string>& metadata);

/**
 * @brief [EN] Invoke `orbuculumIsProceedResponseImpl` in `liborbuculum.so` inside the
 *             signal crash guard (0x011808..0x011da0).
 *        [VN] Gọi `orbuculumIsProceedResponseImpl` trong `liborbuculum.so` bên trong
 *             lớp bảo vệ tín hiệu (0x011808..0x011da0).
 */
int32_t InvokeOrbuculumProceedResponseImpl(
    const char* url,
    const char* method,
    const char* req_headers,
    const char* req_body,
    size_t req_body_len,
    int32_t status_code,
    const char* resp_headers,
    const char* resp_body,
    size_t resp_body_len,
    const char* metadata_kv);

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_ORBUCULUMADAPTER_RUNTIME_HOOKS_H_
