/**
 * @file bh_trampoline.h
 * @brief PLT Trampoline Generation and Executable Buffer Allocator for ByteHook
 *        Bộ tạo đoạn đệm chuyển tiếp Trampoline PLT và cấp phát vùng nhớ thực thi
 *
 * Generates AArch64 instruction bridges (ldr x16, [pc, #8]; br x16) on PROT_EXEC memory pages.
 * Tạo cầu nối lệnh AArch64 (ldr x16, [pc, #8]; br x16) trên các trang bộ nhớ có quyền thực thi.
 */

#ifndef BH_TRAMPOLINE_H
#define BH_TRAMPOLINE_H

#include "bh_types.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BH_TRAMPOLINE_SIZE 16

/**
 * @struct bh_trampoline_t
 * @brief Trampoline stub holding machine instructions and target address
 *        Đoạn đệm chuyển tiếp chứa lệnh mã máy và địa chỉ đích
 */
typedef struct bh_trampoline {
    uint32_t instr_ldr;            ///< 0x58000050: ldr x16, [pc, #8] / Lệnh nạp địa chỉ vào x16
    uint32_t instr_br;             ///< 0xd61f0200: br x16 / Lệnh nhảy tới địa chỉ trong x16
    uint64_t target_address;       ///< 64-bit destination function / Địa chỉ hàm đích 64-bit
} bh_trampoline_t;

/**
 * @brief Initialize trampoline allocator subsystem
 *        Khởi tạo phân hệ cấp phát đoạn đệm trampoline
 * @return 0 on success, negative code on failure / 0 nếu thành công, mã âm nếu thất bại
 */
int bh_trampoline_init(void);

/**
 * @brief Allocate and assemble an executable AArch64 trampoline stub
 *        Cấp phát và hợp dịch một đoạn đệm trampoline AArch64 có quyền thực thi
 * @param target_func Address of function to jump to / Địa chỉ hàm cần nhảy tới
 * @return Pointer to executable trampoline or NULL / Con trỏ đoạn đệm thực thi hoặc NULL
 */
bh_trampoline_t* bh_trampoline_create(void* target_func);

/**
 * @brief Free allocated trampoline stub
 *        Giải phóng đoạn đệm trampoline đã cấp phát
 * @param tramp Pointer to trampoline / Con trỏ đoạn đệm
 */
void bh_trampoline_destroy(bh_trampoline_t* tramp);

#ifdef __cplusplus
}
#endif

#endif // BH_TRAMPOLINE_H
