/**
 * @file sh_a64.h
 * @brief AArch64 Machine Instruction Relocation and Inline Trampoline Synthesizer
 *        Tái định vị lệnh mã máy AArch64 và tổng hợp đoạn đệm Inline Trampoline
 *
 * Implements PC-relative instruction rewriting and atomic AArch64 jump injection.
 * Thực thi viết lại các lệnh phụ thuộc PC và tiêm lệnh nhảy AArch64 nguyên tử.
 */

#ifndef SH_A64_H
#define SH_A64_H

#include "sh_types.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SH_A64_HOOK_SIZE       16  ///< 16 bytes: ldr x16 + br x16 + 64-bit target / Kích thước hook
#define SH_A64_BACKUP_SIZE     32  ///< 4 relocated instrs + jump back / Kích thước đoạn đệm sao lưu

/**
 * @struct sh_a64_trampoline_t
 * @brief Inline hook trampoline pair (entry bridge and backup execution buffer)
 *        Cặp đoạn đệm inline hook (cầu nối điểm nhập và vùng đệm thực thi sao lưu)
 */
typedef struct sh_a64_trampoline {
    uint8_t original_backup[SH_A64_HOOK_SIZE];  ///< Original 16 bytes before hook / 16 bytes gốc
    uint8_t jump_stub[SH_A64_HOOK_SIZE];        ///< Injected 16-byte jump stub / 16 bytes nhảy tiêm vào
    uint8_t backup_trampoline[SH_A64_BACKUP_SIZE]; ///< Executable backup buffer calling original / Bộ đệm gọi lại hàm gốc
    void* target_addr;                          ///< Address of hooked function / Địa chỉ hàm bị hook
    void* new_addr;                             ///< Address of replacement function / Địa chỉ hàm thay thế
} sh_a64_trampoline_t;

/**
 * @brief Initialize AArch64 instruction engine
 *        Khởi tạo động cơ phân giải lệnh AArch64
 * @return 0 on success / 0 nếu thành công
 */
int sh_a64_init(void);

/**
 * @brief Build inline hook jump stub and relocated backup trampoline
 *        Xây dựng stub nhảy inline hook và đoạn đệm sao lưu đã tái định vị
 * @param target_func Address of function to hook / Địa chỉ hàm cần hook
 * @param new_func Address of replacement function / Địa chỉ hàm thay thế
 * @param tramp Output trampoline structure / Cấu trúc đoạn đệm đầu ra
 * @return 0 on success, negative error code on failure / 0 nếu thành công, mã âm nếu thất bại
 */
int sh_a64_create_trampoline(void* target_func, void* new_func, sh_a64_trampoline_t* tramp);

/**
 * @brief Safely inject jump stub into target function using mprotect
 *        Tiêm an toàn stub nhảy vào hàm mục tiêu sử dụng mprotect
 * @param tramp Trampoline structure / Cấu trúc đoạn đệm
 * @return 0 on success, negative error code on failure / 0 nếu thành công, mã âm nếu lỗi
 */
int sh_a64_install_hook(sh_a64_trampoline_t* tramp);

/**
 * @brief Restore original instructions to unhook function
 *        Khôi phục các lệnh gốc để gỡ bỏ hook
 * @param tramp Trampoline structure / Cấu trúc đoạn đệm
 * @return 0 on success, negative error code on failure / 0 nếu thành công, mã âm nếu lỗi
 */
int sh_a64_uninstall_hook(sh_a64_trampoline_t* tramp);

#ifdef __cplusplus
}
#endif

#endif // SH_A64_H
