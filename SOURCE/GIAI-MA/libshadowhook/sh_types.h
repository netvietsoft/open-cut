/**
 * @file sh_types.h
 * @brief ByteDance ShadowHook Android Inline Hook Engine Core Type Definitions
 *        Định nghĩa kiểu dữ liệu lõi cho động cơ Inline Hook Android ByteDance ShadowHook
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#ifndef SH_TYPES_H
#define SH_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Version string constant / Hằng số chuỗi phiên bản
#define SHADOWHOOK_VERSION_STRING "shadowhook version 2.0.1-rc.9"

// ShadowHook Operation Modes / Các chế độ vận hành của ShadowHook
typedef enum {
    SHADOWHOOK_MODE_SHARED = 0, ///< Shared mode: multiple hooks chained on same address / Chế độ chia sẻ đa hook
    SHADOWHOOK_MODE_UNIQUE = 1  ///< Unique mode: only one exclusive hook allowed / Chế độ độc quyền duy nhất
} shadowhook_mode_t;

// ShadowHook Error Codes / Mã lỗi ShadowHook
#define SHADOWHOOK_ERRNO_OK                     0   ///< OK / Thành công
#define SHADOWHOOK_ERRNO_PENDING                1   ///< Task pending for dynamic library load / Tác vụ đang chờ nạp thư viện
#define SHADOWHOOK_ERRNO_UNHOOK_ON_UNFINISHED   2   ///< Cannot unhook unfinished task / Không thể gỡ tác vụ chưa xong
#define SHADOWHOOK_ERRNO_LOAD_LIBRARY           3   ///< Load library failed / Nạp thư viện thất bại
#define SHADOWHOOK_ERRNO_FIND_SYMBOL            4   ///< Find symbol failed / Không tìm thấy biểu tượng
#define SHADOWHOOK_ERRNO_RESOLVE_TRAMPOLINE     5   ///< Trampoline resolution failed / Lỗi giải quyết đoạn đệm
#define SHADOWHOOK_ERRNO_MPROTECT               6   ///< Memory protection failed / Lỗi thay đổi quyền bảo vệ bộ nhớ
#define SHADOWHOOK_ERRNO_MEM_ALLOC              7   ///< Memory allocation failed / Lỗi cấp phát bộ nhớ
#define SHADOWHOOK_ERRNO_NOT_FOUND              8   ///< Target not found / Không tìm thấy mục tiêu
#define SHADOWHOOK_ERRNO_DISABLE                9   ///< ShadowHook is globally disabled / ShadowHook đang bị vô hiệu hóa
#define SHADOWHOOK_ERRNO_INVALID_PARAM          10  ///< Invalid argument / Tham số không hợp lệ

// Opaque hook stub handle / Con trỏ đại diện stub của một inline hook
typedef void* shadowhook_stub_t;

// Hook callback signatures / Chữ ký hàm gọi lại hook
typedef void (*shadowhook_hooked_t)(int error_number, const char* lib_name, const char* sym_name,
                                   void* sym_addr, void* new_addr, void* orig_addr, void* arg);

typedef void (*shadowhook_dl_callback_t)(const char* lib_name, void* data);

/**
 * @struct shadowhook_task_t
 * @brief Active inline hook task descriptor
 *        Bộ mô tả tác vụ inline hook đang hoạt động
 */
typedef struct shadowhook_task {
    shadowhook_stub_t stub;        ///< Unique stub handle / Định danh handle duy nhất
    char* lib_name;                ///< Target library name / Tên thư viện mục tiêu
    char* sym_name;                ///< Target symbol name / Tên biểu tượng
    void* target_addr;             ///< Original function address / Địa chỉ hàm gốc
    void* new_addr;                ///< Replacement hook function / Hàm thay thế mới
    void* orig_addr;               ///< Backup trampoline calling original / Đoạn đệm gọi lại hàm gốc
    shadowhook_hooked_t hooked_cb; ///< Notification callback / Hàm gọi lại kết quả
    void* hook_arg;                ///< User context / Ngữ cảnh người dùng
    bool is_finished;              ///< Finished status / Trạng thái hoàn tất
    bool is_interceptor;           ///< Interceptor mode / Chế độ chặn trước/sau
    struct shadowhook_task* next;  ///< Linked list chain / Chuỗi liên kết tác vụ
} shadowhook_task_t;

#ifdef __cplusplus
}
#endif

#endif // SH_TYPES_H
