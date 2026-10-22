/**
 * @file sh_hub.h
 * @brief ShadowHook Multi-Hook Hub and Thread-Local Storage Stack Manager
 *        Trung tâm điều phối đa hook và quản lý ngăn xếp lưu trữ cục bộ luồng (TLS)
 *
 * Implements call stack unwinding, reentrancy guards, and caller bridge routing.
 * Thực thi tháo ngăn xếp gọi, chốt chống lặp vô hạn và định tuyến cầu nối người gọi.
 */

#ifndef SH_HUB_H
#define SH_HUB_H

#include "sh_types.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SH_HUB_STACK_MAX_DEPTH 64

/**
 * @struct sh_hub_frame_t
 * @brief Stack frame record for active hook dispatch
 *        Bản ghi khung ngăn xếp cho việc điều phối hook đang kích hoạt
 */
typedef struct sh_hub_frame {
    void* target_addr;     ///< Target hooked function / Địa chỉ hàm bị hook
    void* orig_addr;       ///< Backup trampoline address / Địa chỉ đoạn đệm hàm gốc
    void* caller_addr;     ///< Return address of caller / Địa chỉ trả về của bên gọi
    bool allow_reentrant;  ///< Whether reentrancy is enabled / Cho phép gọi đệ quy lặp lại
} sh_hub_frame_t;

/**
 * @struct sh_hub_stack_t
 * @brief Thread-local execution stack for ShadowHook
 *        Ngăn xếp thực thi cục bộ luồng cho ShadowHook
 */
typedef struct sh_hub_stack {
    sh_hub_frame_t frames[SH_HUB_STACK_MAX_DEPTH];
    size_t depth;
    bool global_disallow_reentrant;
} sh_hub_stack_t;

/**
 * @brief Initialize Hub TLS keys and subsystem
 *        Khởi tạo khóa TLS và phân hệ Hub
 * @return 0 on success / 0 nếu thành công
 */
int sh_hub_init(void);

/**
 * @brief Push hook frame to current thread stack
 *        Đẩy khung hook vào ngăn xếp luồng hiện tại
 */
int sh_hub_push_frame(void* target_addr, void* orig_addr, void* caller_addr);

/**
 * @brief Pop top hook frame from current thread stack
 *        Rút khung hook trên cùng khỏi ngăn xếp luồng
 */
void shadowhook_pop_stack(void* target_addr);

/**
 * @brief Get previous function in hook chain
 *        Lấy con trỏ hàm liền trước trong chuỗi hook
 */
void* shadowhook_get_prev_func(void* func);

/**
 * @brief Get return address of caller frame
 *        Lấy địa chỉ trả về của khung người gọi
 */
void* shadowhook_get_return_address(void);

/**
 * @brief Enable reentrant calling for current hook
 *        Cho phép gọi lặp lại (reentrant) cho hook hiện tại
 */
void shadowhook_allow_reentrant(void* func);

/**
 * @brief Disable reentrant calling for current hook
 *        Vô hiệu hóa gọi lặp lại cho hook hiện tại
 */
void shadowhook_disallow_reentrant(void* func);

#ifdef __cplusplus
}
#endif

#endif // SH_HUB_H