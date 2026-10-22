/**
 * @file bh_dl_monitor.h
 * @brief Dynamic Linker (dlopen/android_dlopen_ext) Monitor for ByteHook
 *        Bộ giám sát trình liên kết động (dlopen/android_dlopen_ext) cho ByteHook
 *
 * Intercepts shared library loading events and propagates active hook tasks automatically.
 * Bắt giữ sự kiện nạp thư viện dùng chung và tự động áp dụng các tác vụ hook đang kích hoạt.
 */

#ifndef BH_DL_MONITOR_H
#define BH_DL_MONITOR_H

#include "bh_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BH_MAX_DLOPEN_CBS 16

/**
 * @struct bh_dlopen_cb_entry_t
 * @brief Callback registration item
 *        Mục đăng ký hàm gọi lại khi dlopen
 */
typedef struct bh_dlopen_cb_entry {
    bytehook_dlopen_cb_t cb;       ///< Callback function pointer / Con trỏ hàm gọi lại
    void* data;                    ///< User data pointer / Con trỏ dữ liệu người dùng
    bool in_use;                   ///< Active flag / Cờ kích hoạt
} bh_dlopen_cb_entry_t;

/**
 * @brief Initialize dynamic linker monitor
 *        Khởi tạo bộ giám sát trình liên kết động
 * @return 0 on success, negative error on failure / 0 nếu thành công, mã âm nếu thất bại
 */
int bh_dl_monitor_init(void);

/**
 * @brief Register callback invoked whenever a new shared library is loaded
 *        Đăng ký hàm gọi lại được kích hoạt mỗi khi thư viện dùng chung mới được nạp
 *
 * Exported C API matching ARM64 symbol 'bytehook_add_dlopen_callback' at VAddr 0x0000cb24.
 *
 * @param cb Callback function / Hàm gọi lại
 * @param data User argument pointer / Con trỏ tham số người dùng
 * @return 0 on success, negative code on failure / 0 nếu thành công, mã âm nếu lỗi
 */
int bytehook_add_dlopen_callback(bytehook_dlopen_cb_t cb, void* data);

/**
 * @brief Unregister previously registered dlopen callback
 *        Hủy đăng ký hàm gọi lại dlopen đã đăng ký trước đó
 *
 * Exported C API matching ARM64 symbol 'bytehook_del_dlopen_callback' at VAddr 0x0000cb28.
 *
 * @param cb Callback function / Hàm gọi lại
 * @param data User argument pointer / Con trỏ tham số người dùng
 * @return 0 on success, negative code on failure / 0 nếu thành công, mã âm nếu lỗi
 */
int bytehook_del_dlopen_callback(bytehook_dlopen_cb_t cb, void* data);

/**
 * @brief Notify monitor of a newly loaded library
 *        Thông báo tới bộ giám sát về thư viện vừa được nạp
 * @param filename Library path / Đường dẫn thư viện
 */
void bh_dl_monitor_notify(const char* filename);

#ifdef __cplusplus
}
#endif

#endif // BH_DL_MONITOR_H
