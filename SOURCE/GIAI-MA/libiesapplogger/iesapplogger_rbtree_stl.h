/**
 * @file iesapplogger_rbtree_stl.h
 * @brief NDK libc++ Red-Black Tree (__tree<std::string>) & SSO String Operations for libiesapplogger.so
 *        Các toán tử Cây Đỏ-Đen (__tree<std::string>) & Chuỗi SSO của NDK libc++ cho libiesapplogger.so
 *
 * Reconstructed from .text addresses 0x004a1c..0x004c6c, 0x00537c..0x005874, 0x0083f4..0x008b48.
 * Tái dựng từ các địa chỉ .text 0x004a1c..0x004c6c, 0x00537c..0x005874, 0x0083f4..0x008b48.
 */

#ifndef NEXTAI_OPENCUT_IESAPPLOGGER_RBTREE_STL_H_
#define NEXTAI_OPENCUT_IESAPPLOGGER_RBTREE_STL_H_

#include "iesapplogger_types.h"
#include <cstddef>
#include <cstdint>
#include <string>

namespace iesapplogger {

// ============================================================================
// 1. NDK libc++ SSO String Manipulation (0x0083f4..0x008b48)
//    Các hàm thao tác Chuỗi SSO NDK libc++ (0x0083f4..0x008b48)
// ============================================================================

/**
 * @brief Initializes a 24-byte LibcppSsoStringAbi to empty short string (zero-filled).
 *        Khởi tạo cấu trúc chuỗi 24 byte LibcppSsoStringAbi về chuỗi ngắn rỗng (điền 0).
 */
void sso_string_init_empty(LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Returns true if the 24-byte SSO string is in heap-allocated Long mode (bit 0 == 1).
 *        Trả về true nếu chuỗi SSO 24 byte đang ở chế độ Long cấp phát heap (bit 0 == 1).
 */
bool sso_string_is_long(const LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Returns the length of the 24-byte SSO string (`byte[0] >> 1` if short, `+0x08` if long).
 *        Trả về độ dài chuỗi SSO 24 byte (`byte[0] >> 1` nếu ngắn, `+0x08` nếu dài).
 */
size_t sso_string_size(const LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Returns capacity excluding null terminator (`22` if short, `(cap & ~1ULL) - 1` if long).
 *        Trả về dung lượng trừ ký tự kết thúc null (`22` nếu ngắn, `(cap & ~1ULL) - 1` nếu dài).
 */
size_t sso_string_capacity(const LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Returns const pointer to character buffer (`+0x01` if short, `*(+0x10)` if long).
 *        Trả về con trỏ hằng tới vùng đệm ký tự (`+0x01` nếu ngắn, `*(+0x10)` nếu dài).
 */
const char* sso_string_data(const LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Returns mutable pointer to character buffer (`+0x01` if short, `*(+0x10)` if long).
 *        Trả về con trỏ khả biến tới vùng đệm ký tự (`+0x01` nếu ngắn, `*(+0x10)` nếu dài).
 */
char* sso_string_mutable_data(LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Destroys heap buffer if in Long mode (`tbnz w8, #0` -> `_ZdlPv(*(str + 0x10))`).
 *        Giải phóng vùng đệm heap nếu ở chế độ Long (`tbnz w8, #0` -> `_ZdlPv(*(str + 0x10))`).
 */
void sso_string_destroy(LibcppSsoStringAbi* str) noexcept;

/**
 * @brief Exact reconstruction of `std::__ndk1::basic_string<char>::reserve(unsigned long)`
 *        at 0x0083f4..0x00855c (.dynsym [054]).
 *        Tái dựng chính xác hàm `reserve(unsigned long)` tại 0x0083f4..0x00855c (.dynsym [054]).
 */
void sso_string_reserve(LibcppSsoStringAbi* str, size_t requested_cap);

/**
 * @brief Exact reconstruction of `std::__ndk1::basic_string<char>::__grow_by_and_replace(...)`
 *        at 0x008624..0x008758 (.dynsym [115]).
 *        Tái dựng chính xác hàm `__grow_by_and_replace(...)` tại 0x008624..0x008758 (.dynsym [115]).
 */
void sso_string_grow_by_and_replace(LibcppSsoStringAbi* str,
                                    size_t old_cap,
                                    size_t delta_cap,
                                    size_t old_sz,
                                    size_t n_copy,
                                    size_t n_del,
                                    size_t n_add,
                                    const char* src);

/**
 * @brief Exact reconstruction of `std::__ndk1::basic_string<char>::append(const char*, unsigned long)`
 *        at 0x008560..0x008620 (.dynsym [114]).
 *        Tái dựng chính xác hàm `append(const char*, unsigned long)` tại 0x008560..0x008620 (.dynsym [114]).
 */
LibcppSsoStringAbi* sso_string_append(LibcppSsoStringAbi* str, const char* s, size_t n);

/**
 * @brief Exact reconstruction of `std::__ndk1::basic_string<char>::assign(const char*, unsigned long)`
 *        at 0x00875c..0x008820 (.dynsym [107]).
 *        Tái dựng chính xác hàm `assign(const char*, unsigned long)` tại 0x00875c..0x008820 (.dynsym [107]).
 */
LibcppSsoStringAbi* sso_string_assign(LibcppSsoStringAbi* str, const char* s, size_t n);

/**
 * @brief Exact reconstruction of `std::__ndk1::basic_string<char>::insert(unsigned long, const char*, unsigned long)`
 *        at 0x008928..0x008a48 (.dynsym [062]).
 *        Tái dựng chính xác hàm `insert(unsigned long, const char*, unsigned long)` tại 0x008928..0x008a48 (.dynsym [062]).
 */
LibcppSsoStringAbi* sso_string_insert(LibcppSsoStringAbi* str, size_t pos, const char* s, size_t n);

/**
 * @brief Exact reconstruction of `std::__ndk1::operator+(const char*, const basic_string<char>&)`
 *        at 0x008824..0x008924 (.dynsym [092]).
 *        Tái dựng chính xác toán tử `operator+(const char*, const basic_string<char>&)` tại 0x008824..0x008924 (.dynsym [092]).
 */
void sso_string_concat_cstr_lhs(LibcppSsoStringAbi* out_str,
                                const char* lhs_cstr,
                                const LibcppSsoStringAbi* rhs_str);

/**
 * @brief Exact reconstruction of `std::__ndk1::operator<(const basic_string<char>&, const basic_string<char>&)`
 *        at 0x005804..0x005874 (.dynsym [056]).
 *        Tái dựng chính xác toán tử so sánh `operator<` tại 0x005804..0x005874 (.dynsym [056]).
 */
bool sso_string_less_than(const LibcppSsoStringAbi* lhs, const LibcppSsoStringAbi* rhs) noexcept;

// ============================================================================
// 2. NDK libc++ Red-Black Tree (__tree<std::string>) Operations
//    Các toán tử Cây Đỏ-Đen (__tree<std::string>) của NDK libc++
// ============================================================================

/**
 * @brief Initializes an empty RbTreeSetHeaderAbi (`begin_node = &root_left`, `root_left = nullptr`, `node_count = 0`).
 *        Khởi tạo cấu trúc RbTreeSetHeaderAbi rỗng (`begin_node = &root_left`, `root_left = nullptr`, `node_count = 0`).
 */
void rbtree_init(RbTreeSetHeaderAbi* tree) noexcept;

/**
 * @brief Reconstructs `__tree::destroy(__tree_node*)` at 0x004a1c..0x004a6c (.dynsym [060]).
 *        Recursively destroys left/right subtrees, frees long string buffer, and calls `_ZdlPv`.
 *        Tái dựng `__tree::destroy(__tree_node*)` tại 0x004a1c..0x004a6c (.dynsym [060]).
 */
void rbtree_destroy_subtree(RbTreeSetHeaderAbi* tree, RbTreeNodeStringAbi* node) noexcept;

/**
 * @brief Reconstructs `__tree::clear()` at 0x005600..0x005634 (.dynsym [061]).
 *        Destroys root subtree and resets `begin_node = &root_left`, `root_left = nullptr`, `node_count = 0`.
 *        Tái dựng `__tree::clear()` tại 0x005600..0x005634 (.dynsym [061]).
 */
void rbtree_clear(RbTreeSetHeaderAbi* tree) noexcept;

/**
 * @brief Reconstructs `__tree::__construct_node(const basic_string&)` at 0x00537c..0x005428 (.dynsym [049]).
 *        Allocates a 56-byte (`0x38`) node and copies the key string into `+0x20`.
 *        Tái dựng `__tree::__construct_node` tại 0x00537c..0x005428 (.dynsym [049]).
 */
RbTreeNodeStringAbi* rbtree_construct_node(const LibcppSsoStringAbi* key);

/**
 * @brief Reconstructs `__tree::__find_equal(parent_out, const basic_string&)` at 0x0054dc..0x0055a0 (.dynsym [057]).
 *        Finds insertion slot pointer and sets `*parent_out`.
 *        Tái dựng `__tree::__find_equal` tại 0x0054dc..0x0055a0 (.dynsym [057]).
 */
RbTreeNodeStringAbi** rbtree_find_equal(RbTreeSetHeaderAbi* tree,
                                        RbTreeNodeStringAbi** parent_out,
                                        const LibcppSsoStringAbi* key) noexcept;

/**
 * @brief Reconstructs `std::__ndk1::__tree_balance_after_insert` at 0x005638..0x005800 (.dynsym [059]).
 *        Balances the Red-Black Tree after inserting `new_node` under `root`.
 *        Tái dựng hàm cân bằng Cây Đỏ-Đen sau khi chèn nút tại 0x005638..0x005800 (.dynsym [059]).
 */
void rbtree_balance_after_insert(RbTreeNodeStringAbi* root, RbTreeNodeStringAbi* new_node) noexcept;

/**
 * @brief Reconstructs `__tree::__insert_node_at(parent, child_slot, new_node)` at 0x0055a4..0x0055fc (.dynsym [052]).
 *        Links `new_node`, updates `begin_node`, balances RB-tree, and increments `node_count`.
 *        Tái dựng `__tree::__insert_node_at` tại 0x0055a4..0x0055fc (.dynsym [052]).
 */
void rbtree_insert_node_at(RbTreeSetHeaderAbi* tree,
                           RbTreeNodeStringAbi* parent,
                           RbTreeNodeStringAbi** child_slot,
                           RbTreeNodeStringAbi* new_node) noexcept;

/**
 * @brief Reconstructs `__tree::__emplace_unique_key_args(key, args...)` at 0x00542c..0x0054d8 (.dynsym [102]).
 *        Inserts `key` into the Red-Black Tree if not already present.
 *        Tái dựng `__tree::__emplace_unique_key_args` tại 0x00542c..0x0054d8 (.dynsym [102]).
 */
std::pair<RbTreeNodeStringAbi*, bool> rbtree_emplace_unique(RbTreeSetHeaderAbi* tree,
                                                            const LibcppSsoStringAbi* key);

/**
 * @brief Reconstructs `__tree::find(const basic_string&)` at 0x004c18..0x004c6c (.dynsym [051]).
 *        Performs lower_bound + equality check on the Red-Black Tree; returns end-node (`&tree->root_left`) if not found.
 *        Tái dựng `__tree::find(const basic_string&)` tại 0x004c18..0x004c6c (.dynsym [051]).
 */
const RbTreeNodeStringAbi* rbtree_find(const RbTreeSetHeaderAbi* tree,
                                       const LibcppSsoStringAbi* key) noexcept;

/**
 * @brief Reconstructs `std::__ndk1::__tree_next_iter(__tree_end_node*)` at 0x004b94..0x004bd4 (.dynsym [058]).
 *        Advances an RB-tree pointer to the in-order successor node.
 *        Tái dựng hàm tìm nút kế tiếp theo thứ tự trung thứ tự tại 0x004b94..0x004bd4 (.dynsym [058]).
 */
RbTreeNodeStringAbi* rbtree_next_iter(RbTreeNodeStringAbi* node) noexcept;

/**
 * @brief Reconstructs `__tree::__assign_multi` / copy assignment at 0x004a70..0x004b90 (.dynsym [050, 055]).
 *        Copies all keys from `src` tree into `dst` tree, reusing existing allocated nodes where possible.
 *        Tái dựng phép gán sao chép cây `__tree::__assign_multi` tại 0x004a70..0x004b90 (.dynsym [050, 055]).
 */
void rbtree_copy_assign(RbTreeSetHeaderAbi* dst, const RbTreeSetHeaderAbi* src);

}  // namespace iesapplogger

#endif  // NEXTAI_OPENCUT_IESAPPLOGGER_RBTREE_STL_H_
