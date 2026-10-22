/**
 * @file bh_core.h
 * @brief ByteDance ByteHook Core Engine API and Task Manager
 *        Giao diện API và quản lý tác vụ động cơ lõi ByteDance ByteHook
 *
 * Exposes core hook registration, unhooking, mode configuration and auditing routines.
 * Cung cấp đăng ký hook cốt lõi, gỡ hook, cấu hình chế độ và các quy trình kiểm toán.
 */

#ifndef BH_CORE_H
#define BH_CORE_H

#include "bh_types.h"
#include "bh_elf.h"
#include "bh_trampoline.h"
#include "bh_hub.h"
#include "bh_dl_monitor.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Retrieve library version string
 *        Lấy chuỗi phiên bản thư viện ByteHook
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_version' at VAddr 0x0000c6cc.
 *
 * @return Read-only version string constant "bytehook version 1.1.2-alpha.0"
 */
const char* bytehook_get_version(void);

/**
 * @brief Initialize ByteHook engine
 *        Khởi tạo động cơ ByteHook
 *
 * Exported C API matching ARM64 symbol 'bytehook_init' at VAddr 0x0000c6d8.
 *
 * @param mode Operation mode: BYTEHOOK_MODE_AUTOMATIC (0) or BYTEHOOK_MODE_MANUAL (1)
 *             Chế độ vận hành: Tự động (0) hoặc Thủ công (1)
 * @param debug Enable debug logging / Bật nhật ký gỡ lỗi
 * @return 0 on success, negative error code on failure
 *         0 nếu thành công, mã âm nếu lỗi
 */
int bytehook_init(int mode, bool debug);

/**
 * @brief Get current operational mode
 *        Lấy chế độ vận hành hiện tại
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_mode' at VAddr 0x0000c840.
 *
 * @return Active bytehook_mode_t enum value / Giá trị enum chế độ đang hoạt động
 */
int bytehook_get_mode(void);

/**
 * @brief Hook symbol in a single specified caller library
 *        Hook biểu tượng trong một thư viện gọi được chỉ định cụ thể
 *
 * Exported C API matching ARM64 symbol 'bytehook_hook_single' at VAddr 0x0000c84c.
 *
 * @param caller_path_name Path to caller ELF / Đường dẫn ELF người gọi
 * @param callee_path_name Path to callee ELF / Đường dẫn ELF người được gọi
 * @param sym_name Symbol name to hook / Tên hàm cần hook
 * @param new_func Replacement function / Hàm thay thế mới
 * @param hooked Notification callback / Hàm gọi lại kết quả
 * @param arg User argument / Tham số người dùng
 * @return Opaque bytehook_stub_t handle or NULL / Con trỏ đại diện stub hoặc NULL
 */
bytehook_stub_t bytehook_hook_single(const char* caller_path_name, const char* callee_path_name,
                                     const char* sym_name, void* new_func,
                                     bytehook_hooked_t hooked, void* arg);

/**
 * @brief Hook symbol in caller libraries matching a filter predicate
 *        Hook biểu tượng trong các thư viện thỏa mãn hàm lọc
 *
 * Exported C API matching ARM64 symbol 'bytehook_hook_partial' at VAddr 0x0000c8e0.
 */
bytehook_stub_t bytehook_hook_partial(bytehook_caller_allow_filter_t caller_allow_filter,
                                      void* caller_allow_filter_arg,
                                      const char* callee_path_name,
                                      const char* sym_name, void* new_func,
                                      bytehook_hooked_t hooked, void* arg);

/**
 * @brief Hook symbol across all loaded and future libraries
 *        Hook biểu tượng trên toàn bộ các thư viện hiện có và nạp trong tương lai
 *
 * Exported C API matching ARM64 symbol 'bytehook_hook_all' at VAddr 0x0000c978.
 */
bytehook_stub_t bytehook_hook_all(const char* callee_path_name, const char* sym_name,
                                  void* new_func, bytehook_hooked_t hooked, void* arg);

/**
 * @brief Remove hook associated with stub handle
 *        Gỡ bỏ hook gắn liền với định danh stub
 *
 * Exported C API matching ARM64 symbol 'bytehook_unhook' at VAddr 0x0000c9f8.
 *
 * @param stub Hook handle returned from hook_* functions / Con trỏ handle của hook
 * @return 0 on success, negative error code on failure / 0 nếu thành công, mã âm nếu lỗi
 */
int bytehook_unhook(bytehook_stub_t stub);

/**
 * @brief Add library to ignore list (will never be hooked)
 *        Thêm thư viện vào danh sách bỏ qua (không bao giờ bị hook)
 *
 * Exported C API matching ARM64 symbol 'bytehook_add_ignore' at VAddr 0x0000ca90.
 *
 * @param caller_path_name Library path / Đường dẫn thư viện
 * @return 0 on success / 0 nếu thành công
 */
int bytehook_add_ignore(const char* caller_path_name);

/**
 * @brief Query debug status flag
 *        Truy vấn cờ trạng thái gỡ lỗi
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_debug' at VAddr 0x0000cab0.
 */
bool bytehook_get_debug(void);

/**
 * @brief Set debug status flag
 *        Thiết lập cờ trạng thái gỡ lỗi
 *
 * Exported C API matching ARM64 symbol 'bytehook_set_debug' at VAddr 0x0000cab4.
 */
void bytehook_set_debug(bool debug);

/**
 * @brief Query recordable status flag
 *        Truy vấn cờ ghi nhật ký lịch sử hook
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_recordable' at VAddr 0x0000cabc.
 */
bool bytehook_get_recordable(void);

/**
 * @brief Set recordable status flag
 *        Thiết lập cờ ghi nhật ký lịch sử hook
 *
 * Exported C API matching ARM64 symbol 'bytehook_set_recordable' at VAddr 0x0000cac0.
 */
void bytehook_set_recordable(bool recordable);

/**
 * @brief Retrieve serialized record log string
 *        Lấy chuỗi nhật ký bản ghi hook đã tuần tự hóa
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_records' at VAddr 0x0000cac8.
 *
 * @param item_flags Filter flags / Cờ lọc
 * @return Formatted record string (heap-allocated, caller frees) / Chuỗi bản ghi đã định dạng
 */
char* bytehook_get_records(uint32_t item_flags);

/**
 * @brief Dump hook records to file descriptor
 *        Xuất các bản ghi hook ra file descriptor
 *
 * Exported C API matching ARM64 symbol 'bytehook_dump_records' at VAddr 0x0000cacc.
 *
 * @param fd File descriptor / Bộ mô tả tệp
 */
void bytehook_dump_records(int fd);

#ifdef __cplusplus
}
#endif

#endif // BH_CORE_H
