/**
 * @file bh_types.h
 * @brief ByteDance ByteHook PLT/GOT Hooking Engine Core Type Definitions
 *        Định nghĩa kiểu dữ liệu lõi cho động cơ PLT/GOT Hook ByteDance ByteHook
 *
 * Cleanroom implementation reconstructed from ByteDance libbytehook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libbytehook.so (AArch64) của ByteDance.
 */

#ifndef BH_TYPES_H
#define BH_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Version string constant / Hằng số chuỗi phiên bản
#define BYTEHOOK_VERSION_STRING "bytehook version 1.1.2-alpha.0"

// ByteHook Operation Modes / Các chế độ vận hành của ByteHook
typedef enum {
    BYTEHOOK_MODE_AUTOMATIC = 0, ///< Automatic mode: monitors dlopen and auto-hooks / Tự động hook khi nạp so
    BYTEHOOK_MODE_MANUAL    = 1  ///< Manual mode: only hooks currently loaded ELFs / Thủ công chỉ hook ELF hiện hành
} bytehook_mode_t;

// ByteHook Return Status Codes / Mã trạng thái trả về của ByteHook
#define BYTEHOOK_STATUS_OK                 0   ///< Operation succeeded / Thành công
#define BYTEHOOK_STATUS_ERROR_INIT        -1   ///< Initialization error / Lỗi khởi tạo
#define BYTEHOOK_STATUS_ERROR_PARAM       -2   ///< Invalid parameter / Tham số không hợp lệ
#define BYTEHOOK_STATUS_ERROR_ELF         -3   ///< ELF parsing error / Lỗi phân giải ELF
#define BYTEHOOK_STATUS_ERROR_MPROTECT    -4   ///< Memory protection failed / Lỗi thay đổi bảo vệ bộ nhớ
#define BYTEHOOK_STATUS_ERROR_NOT_FOUND   -5   ///< Symbol not found / Không tìm thấy biểu tượng
#define BYTEHOOK_STATUS_ERROR_HOOKED      -6   ///< Already hooked / Đã được hook trước đó
#define BYTEHOOK_STATUS_ERROR_UNHOOK      -7   ///< Unhook failed / Gỡ hook thất bại

// Opaque hook stub handle / Con trỏ đại diện stub của một hook
typedef void* bytehook_stub_t;

// Hook callback signatures / Chữ ký các hàm gọi lại hook
typedef void (*bytehook_hooked_t)(bytehook_stub_t stub, int error_number, const char* caller_path_name,
                                  const char* sym_name, void* new_func, void* prev_func, void* arg);

typedef bool (*bytehook_caller_allow_filter_t)(const char* caller_path_name, void* arg);

typedef void (*bytehook_dlopen_cb_t)(const char* filename, void* data);

/**
 * @struct bytehook_record_t
 * @brief Record structure capturing a hook operation event
 *        Cấu trúc bản ghi lưu trữ sự kiện thực hiện hook
 */
typedef struct bytehook_record {
    uint64_t timestamp_us;         ///< Timestamp in microseconds / Dấu thời gian micro giây
    char caller_path[128];         ///< Caller library path / Đường dẫn thư viện gọi
    char sym_name[64];             ///< Target symbol name / Tên biểu tượng mục tiêu
    void* new_func;                ///< Replacement function / Hàm thay thế
    void* prev_func;               ///< Predecessor function / Hàm tiền nhiệm
    int status;                    ///< Result status code / Mã trạng thái kết quả
    struct bytehook_record* next;  ///< Linked list next / Phần tử kế tiếp trong danh sách liên kết
} bytehook_record_t;

/**
 * @struct bytehook_task_t
 * @brief Internal tracking structure for an active hook task
 *        Cấu trúc nội bộ theo dõi một tác vụ hook đang hoạt động
 */
typedef struct bytehook_task {
    bytehook_stub_t stub;          ///< Unique stub identifier / Định danh duy nhất của stub
    char* caller_path_name;        ///< Target caller path / Đường dẫn thư viện người gọi
    char* callee_path_name;        ///< Target callee path / Đường dẫn thư viện người được gọi
    char* sym_name;                ///< Hooked symbol name / Tên hàm được hook
    void* new_func;                ///< New hook handler / Hàm xử lý mới
    bytehook_hooked_t hooked_cb;   ///< Notification callback / Hàm gọi lại thông báo
    void* hook_arg;                ///< User context argument / Tham số ngữ cảnh người dùng
    bool is_finished;              ///< Task completion flag / Cờ hoàn thành tác vụ
    struct bytehook_task* next;    ///< Linked list chain / Chuỗi liên kết tác vụ
} bytehook_task_t;

#ifdef __cplusplus
}
#endif

#endif // BH_TYPES_H
