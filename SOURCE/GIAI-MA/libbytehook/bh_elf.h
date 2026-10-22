/**
 * @file bh_elf.h
 * @brief ELF Dynamic Binary Parsing and GOT Relocation Engine for ByteHook
 *        Bộ phân giải nhị phân ELF và điều phối bảng nạp lại GOT cho ByteHook
 *
 * Implements symbol resolution, GOT table location, mprotect page protection toggling.
 * Thực thi phân giải biểu tượng, xác định bảng GOT, thay đổi quyền bảo vệ trang bộ nhớ qua mprotect.
 */

#ifndef BH_ELF_H
#define BH_ELF_H

#include "bh_types.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct bh_elf_info_t
 * @brief Parsed ELF module descriptor
 *        Bộ mô tả mô-đun ELF đã phân giải
 */
typedef struct bh_elf_info {
    char path[256];                ///< Loaded library path / Đường dẫn tệp thư viện
    uintptr_t base_addr;           ///< Virtual memory base load address / Địa chỉ nạp gốc trong bộ nhớ ảo
    uintptr_t bias_addr;           ///< Load bias offset / Độ lệch nạp
    void* dynsym;                  ///< Pointer to .dynsym section / Con trỏ phân vùng .dynsym
    const char* dynstr;            ///< Pointer to .dynstr string table / Con trỏ bảng chuỗi .dynstr
    void* rela_plt;                ///< Pointer to .rela.plt relocations / Con trỏ bảng relocations .rela.plt
    size_t rela_plt_count;         ///< Count of PLT relocations / Số lượng mục nạp lại PLT
    uintptr_t got_start;           ///< GOT table start address / Địa chỉ bắt đầu bảng GOT
    size_t got_size;               ///< GOT table size in bytes / Kích thước bảng GOT
    struct bh_elf_info* next;      ///< Linked list chain / Con trỏ danh sách liên kết
} bh_elf_info_t;

/**
 * @brief Initialize ELF manager and scan currently loaded shared objects
 *        Khởi tạo bộ quản lý ELF và quét các thư viện dùng chung đang nạp
 * @return 0 on success, negative error code on failure / 0 nếu thành công, mã âm nếu lỗi
 */
int bh_elf_init(void);

/**
 * @brief Find parsed ELF module by path name
 *        Tìm mô-đun ELF đã phân giải theo tên đường dẫn
 * @param path Library path / Đường dẫn thư viện
 * @return Pointer to bh_elf_info_t or NULL / Con trỏ tới bh_elf_info_t hoặc NULL
 */
bh_elf_info_t* bh_elf_find_by_path(const char* path);

/**
 * @brief Resolve symbol GOT slot address in target ELF module
 *        Phân giải địa chỉ ô nhớ GOT của biểu tượng trong mô-đun ELF mục tiêu
 * @param elf Target ELF descriptor / Bộ mô tả ELF mục tiêu
 * @param sym_name Symbol name to look up / Tên biểu tượng cần tìm
 * @return Address of GOT pointer slot or NULL if not found
 *         Địa chỉ ô nhớ con trỏ GOT hoặc NULL nếu không tìm thấy
 */
void** bh_elf_find_got_slot(bh_elf_info_t* elf, const char* sym_name);

/**
 * @brief Safely replace pointer in GOT table using mprotect and atomic exchange
 *        Thay thế an toàn con trỏ trong bảng GOT bằng mprotect và trao đổi nguyên tử
 * @param got_slot Address of GOT slot / Địa chỉ ô nhớ GOT
 * @param new_func Replacement function pointer / Con trỏ hàm thay thế mới
 * @param orig_func Output original function pointer / Con trỏ hàm gốc ban đầu
 * @return 0 on success, negative error code on failure
 *         0 nếu thành công, mã âm nếu thất bại
 */
int bh_elf_replace_got_slot(void** got_slot, void* new_func, void** orig_func);

#ifdef __cplusplus
}
#endif

#endif // BH_ELF_H
