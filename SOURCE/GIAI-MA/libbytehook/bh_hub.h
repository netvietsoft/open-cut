/**
 * @file bh_hub.h
 * @brief Multi-Hook Hub Dispatcher and Thread-Local Call Stack Management for ByteHook
 *        Bộ điều phối đa Hook (Hub) và quản lý ngăn xếp gọi cục bộ theo luồng (TLS)
 *
 * Implements bytehook_get_prev_func, bytehook_get_return_address, bytehook_pop_stack via TLS.
 * Thực thi các hàm lấy con trỏ hàm tiền nhiệm, địa chỉ trả về và giải phóng ngăn xếp qua TLS.
 */

#ifndef BH_HUB_H
#define BH_HUB_H

#include "bh_types.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BH_STACK_MAX_DEPTH 32

/**
 * @struct bh_stack_frame_t
 * @brief Single call frame stored in thread-local call stack
 *        Một khung gọi đơn lẻ lưu trong ngăn xếp cục bộ theo luồng
 */
typedef struct bh_stack_frame {
    void* hook_func;               ///< Current replacement hook function / Hàm hook hiện hành
    void* prev_func;               ///< Predecessor or original function / Hàm tiền nhiệm hoặc hàm gốc
    void* return_address;          ///< Caller return address / Địa chỉ quay về của bên gọi
} bh_stack_frame_t;

/**
 * @struct bh_stack_t
 * @brief Per-thread call stack structure
 *        Cấu trúc ngăn xếp cuộc gọi theo từng luồng
 */
typedef struct bh_stack {
    bh_stack_frame_t frames[BH_STACK_MAX_DEPTH]; ///< Array of active frames / Mảng các khung gọi
    int32_t top;                   ///< Current top index / Chỉ số đỉnh ngăn xếp
} bh_stack_t;

/**
 * @brief Initialize hook hub subsystem and allocate pthread TLS key
 *        Khởi tạo phân hệ hook hub và cấp phát khóa TLS pthread
 * @return 0 on success, negative code on failure / 0 nếu thành công, mã âm nếu thất bại
 */
int bh_hub_init(void);

/**
 * @brief Push a new frame onto thread-local call stack
 *        Đẩy một khung gọi mới vào ngăn xếp cục bộ theo luồng
 * @param hook_func Current hook function / Hàm hook hiện hành
 * @param prev_func Predecessor function / Hàm tiền nhiệm
 * @param return_addr Caller return address / Địa chỉ quay về
 * @return 0 on success, -1 on overflow / 0 nếu thành công, -1 nếu tràn ngăn xếp
 */
int bh_hub_push_stack(void* hook_func, void* prev_func, void* return_addr);

/**
 * @brief Retrieve predecessor function pointer in the hook chain
 *        Lấy con trỏ hàm tiền nhiệm trong chuỗi hook
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_prev_func' at VAddr 0x0000cad0.
 *
 * @param func Pointer to current hook function / Con trỏ hàm hook hiện hành
 * @return Address of predecessor function or original symbol
 *         Địa chỉ hàm tiền nhiệm hoặc hàm gốc ban đầu
 */
void* bytehook_get_prev_func(void* func);

/**
 * @brief Retrieve caller return address from thread call stack
 *        Lấy địa chỉ quay về của bên gọi từ ngăn xếp luồng
 *
 * Exported C API matching ARM64 symbol 'bytehook_get_return_address' at VAddr 0x0000caec.
 *
 * @return Return address pointer / Con trỏ địa chỉ quay về
 */
void* bytehook_get_return_address(void);

/**
 * @brief Pop current frame off the thread-local call stack
 *        Rút khung gọi hiện hành ra khỏi ngăn xếp cục bộ luồng
 *
 * Exported C API matching ARM64 symbol 'bytehook_pop_stack' at VAddr 0x0000cb08.
 *
 * @param func Current hook function / Con trỏ hàm hook hiện hành
 */
void bytehook_pop_stack(void* func);

#ifdef __cplusplus
}
#endif

#endif // BH_HUB_H
