/**
 * @file iesapplogger_rbtree_stl.cpp
 * @brief Exact Implementation of NDK libc++ Red-Black Tree (__tree<std::string>) & SSO String
 *        Triển khai Chính xác Cây Đỏ-Đen (__tree<std::string>) & Chuỗi SSO của NDK libc++
 *
 * Reconstructed from .text addresses 0x004a1c..0x004c6c, 0x00537c..0x005874, 0x0083f4..0x008b48.
 * Tái dựng từ các địa chỉ .text 0x004a1c..0x004c6c, 0x00537c..0x005874, 0x0083f4..0x008b48.
 */

#include "iesapplogger_rbtree_stl.h"
#include <algorithm>
#include <cstring>
#include <new>
#include <stdexcept>

namespace iesapplogger {

// ============================================================================
// 1. NDK libc++ SSO String Implementation (0x0083f4..0x008b48)
//    Triển khai Chuỗi SSO NDK libc++ (0x0083f4..0x008b48)
// ============================================================================

void sso_string_init_empty(LibcppSsoStringAbi* str) noexcept {
    // Matches `stp xzr, xzr, [x8]; str xzr, [x8, #0x10]` @ 0x008848..0x00884c
    // Khớp với lệnh xóa 24 byte về 0 tại 0x008848..0x00884c
    std::memset(str, 0, sizeof(LibcppSsoStringAbi));
}

bool sso_string_is_long(const LibcppSsoStringAbi* str) noexcept {
    // Matches `ldrb w8, [x0]; tbnz w8, #0, ...` @ 0x008570..0x008580
    // Khớp với kiểm tra bit 0 của byte đầu tiên tại 0x008570..0x008580
    return (str->short_rep.size_shifted & 1U) != 0U;
}

size_t sso_string_size(const LibcppSsoStringAbi* str) noexcept {
    // Short mode: `lsr x21, x8, #1` (@ 0x008584); Long mode: `ldr x21, [x19, #8]` (@ 0x008590)
    // Chế độ ngắn: dịch phải 1 bit; Chế độ dài: đọc 8 byte tại +0x08
    if (sso_string_is_long(str)) {
        return static_cast<size_t>(str->long_rep.size);
    }
    return static_cast<size_t>(str->short_rep.size_shifted >> 1U);
}

size_t sso_string_capacity(const LibcppSsoStringAbi* str) noexcept {
    // Short mode: `mov w1, #0x16` (22 chars @ 0x008588)
    // Long mode: `and x9, x9, #~1; sub x1, x9, #1` (@ 0x008594..0x008598)
    // Chế độ ngắn: 22 ký tự; Chế độ dài: (cap_and_flag & ~1ULL) - 1
    if (sso_string_is_long(str)) {
        return static_cast<size_t>((str->long_rep.cap_and_flag & ~1ULL) - 1ULL);
    }
    return 22ULL;
}

const char* sso_string_data(const LibcppSsoStringAbi* str) noexcept {
    if (sso_string_is_long(str)) {
        return str->long_rep.data;
    }
    return str->short_rep.inline_buf;
}

char* sso_string_mutable_data(LibcppSsoStringAbi* str) noexcept {
    if (sso_string_is_long(str)) {
        return str->long_rep.data;
    }
    return str->short_rep.inline_buf;
}

void sso_string_destroy(LibcppSsoStringAbi* str) noexcept {
    // Matches `ldrb w8, [sp, ...]; tbz w8, #0, skip; ldr x0, [sp, #+0x10]; bl _ZdlPv`
    // Giải phóng bộ nhớ heap nếu bit 0 == 1
    if (sso_string_is_long(str) && str->long_rep.data != nullptr) {
        ::operator delete(str->long_rep.data);
    }
    sso_string_init_empty(str);
}

/**
 * @brief Reconstructs `std::__ndk1::basic_string<char>::reserve(unsigned long)`
 *        at 0x0083f4..0x00855c (.dynsym [054]).
 *        Tái dựng chính xác hàm `reserve(unsigned long)` tại 0x0083f4..0x00855c (.dynsym [054]).
 */
void sso_string_reserve(LibcppSsoStringAbi* str, size_t requested_cap) {
    // 0x00840c: cmn x1, #0x10 ; b.hs #0x853c (__throw_length_error)
    // Kiểm tra tràn dung lượng tối đa (max_size = 0xfffffffffffffff0 - 1)
    if (requested_cap >= static_cast<size_t>(-16LL)) {
        throw std::length_error(RodataStrings::kBasicStringErr);
    }

    const bool was_long = sso_string_is_long(str);
    const size_t cur_size = sso_string_size(str);
    const size_t cur_cap = sso_string_capacity(str);

    // 0x008438: cmp x22, x1 ; csel x9, x22, x1, hi -> target = max(cur_size, requested_cap)
    // Dung lượng đích tối thiểu phải chứa đủ độ dài hiện tại
    size_t target_cap = (cur_size > requested_cap) ? cur_size : requested_cap;

    // 0x008440..0x00847c:
    // If target_cap < 23 (0x17), aligned_cap = 22 (0x16);
    // else aligned_cap = ((target_cap + 16) & ~15ULL) - 1
    size_t new_cap = 22ULL;
    if (target_cap >= 23ULL) {
        size_t alloc_bytes = (target_cap + 16ULL) & ~15ULL;
        new_cap = alloc_bytes - 1ULL;
    }

    // 0x00844c & 0x008480: cmp x23, x8 ; b.eq #0x8524 (no-op if new_cap == cur_cap)
    if (new_cap == cur_cap) {
        return;
    }

    // Shrinking to short mode (new_cap == 22 && was_long):
    // Thu nhỏ từ chế độ Long về chế độ Short (new_cap == 22):
    if (new_cap == 22ULL) {
        char* old_heap = str->long_rep.data;
        str->short_rep.size_shifted = static_cast<uint8_t>(cur_size << 1U);
        if (cur_size + 1ULL > 0ULL) {
            std::memcpy(str->short_rep.inline_buf, old_heap, cur_size + 1ULL);
        }
        ::operator delete(old_heap);
        return;
    }

    // Allocating new heap buffer of size `new_cap + 1` (`0x008490: add x0, x23, #1; bl _Znwm`)
    // Cấp phát vùng nhớ mới kích thước `new_cap + 1` trên heap
    char* new_buf = static_cast<char*>(::operator new(new_cap + 1ULL));
    const char* old_data = was_long ? str->long_rep.data : str->short_rep.inline_buf;

    if (cur_size + 1ULL > 0ULL) {
        std::memcpy(new_buf, old_data, cur_size + 1ULL);
    }

    if (was_long && str->long_rep.data != nullptr) {
        ::operator delete(str->long_rep.data);
    }

    // 0x0084fc..0x008508:
    // add x8, x23, #1 ; orr x8, x8, #1 ; stp x8, x22, [x19] ; str x20, [x19, #0x10]
    str->long_rep.cap_and_flag = (new_cap + 1ULL) | 1ULL;
    str->long_rep.size = cur_size;
    str->long_rep.data = new_buf;
}

/**
 * @brief Reconstructs `std::__ndk1::basic_string<char>::__grow_by_and_replace(...)`
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
                                    const char* src) {
    // 0x008640..0x008650: mov x8, #-0x12 ; sub x8, x8, x1 ; cmp x8, x2 ; b.lo #0x8754
    const size_t max_sz = static_cast<size_t>(-18LL);
    if (max_sz - old_cap < delta_cap) {
        throw std::length_error(RodataStrings::kBasicStringErr);
    }

    const bool was_long = sso_string_is_long(str);
    char* old_p = was_long ? str->long_rep.data : str->short_rep.inline_buf;

    // 0x008680..0x0086bc: compute new allocation size x27
    // Tính toán kích thước cấp phát mới x27 (nhân đôi dung lượng hoặc căn chỉnh 16 byte)
    size_t alloc_bytes = 0;
    const size_t half_max = 0x7fffffffffffffe6ULL;
    if (old_cap > half_max) {
        alloc_bytes = static_cast<size_t>(-17LL);
    } else {
        size_t req = old_cap + delta_cap;
        size_t doubled = old_cap << 1U;
        size_t target = (req < doubled) ? doubled : req;
        if (target < 23ULL) {
            alloc_bytes = 23ULL;
        } else {
            alloc_bytes = (target + 16ULL) & ~15ULL;
        }
    }

    char* new_buf = static_cast<char*>(::operator new(alloc_bytes));

    // 0x0086cc..0x0086dc: copy prefix [0..n_copy)
    if (n_copy != 0) {
        std::memcpy(new_buf, old_p, n_copy);
    }
    // 0x0086e0..0x0086f0: copy inserted segment [src..src+n_add)
    if (n_add != 0) {
        std::memcpy(new_buf + n_copy, src, n_add);
    }
    // 0x0086f4..0x008710: copy suffix after (n_copy + n_del)
    size_t sec_cp_sz = (old_sz - n_del) - n_copy;
    if (sec_cp_sz != 0) {
        std::memcpy(new_buf + n_copy + n_add, old_p + n_copy + n_del, sec_cp_sz);
    }

    if (old_cap != 22ULL && was_long && old_p != nullptr) {
        ::operator delete(old_p);
    }

    size_t new_sz = (old_sz - n_del) + n_add;
    str->long_rep.cap_and_flag = alloc_bytes | 1ULL;
    str->long_rep.size = new_sz;
    str->long_rep.data = new_buf;
    new_buf[new_sz] = '\0';
}

/**
 * @brief Reconstructs `std::__ndk1::basic_string<char>::append(const char*, unsigned long)`
 *        at 0x008560..0x008620 (.dynsym [114]).
 *        Tái dựng chính xác hàm `append(const char*, unsigned long)` tại 0x008560..0x008620 (.dynsym [114]).
 */
LibcppSsoStringAbi* sso_string_append(LibcppSsoStringAbi* str, const char* s, size_t n) {
    const size_t cap = sso_string_capacity(str);
    const size_t sz = sso_string_size(str);

    // 0x00859c..0x0085c4: if (cap - sz < n) -> __grow_by_and_replace
    if (cap - sz < n) {
        sso_string_grow_by_and_replace(str, cap, (sz + n) - cap, sz, sz, 0, n, s);
        return str;
    }

    // 0x0085cc..0x00860c: in-place memcpy + update size + null-terminate
    if (n != 0) {
        char* p = sso_string_mutable_data(str);
        std::memcpy(p + sz, s, n);
        size_t new_sz = sz + n;
        if (sso_string_is_long(str)) {
            str->long_rep.size = new_sz;
        } else {
            str->short_rep.size_shifted = static_cast<uint8_t>(new_sz << 1U);
        }
        p[new_sz] = '\0';
    }
    return str;
}

/**
 * @brief Reconstructs `std::__ndk1::basic_string<char>::assign(const char*, unsigned long)`
 *        at 0x00875c..0x008820 (.dynsym [107]).
 *        Tái dựng chính xác hàm `assign(const char*, unsigned long)` tại 0x00875c..0x008820 (.dynsym [107]).
 */
LibcppSsoStringAbi* sso_string_assign(LibcppSsoStringAbi* str, const char* s, size_t n) {
    const size_t cap = sso_string_capacity(str);
    if (cap >= n) {
        char* p = sso_string_mutable_data(str);
        if (n != 0) {
            std::memmove(p, s, n);
        }
        p[n] = '\0';
        if (sso_string_is_long(str)) {
            str->long_rep.size = n;
        } else {
            str->short_rep.size_shifted = static_cast<uint8_t>(n << 1U);
        }
        return str;
    }
    const size_t sz = sso_string_size(str);
    sso_string_grow_by_and_replace(str, cap, n - cap, sz, 0, sz, n, s);
    return str;
}

/**
 * @brief Reconstructs `std::__ndk1::basic_string<char>::insert(unsigned long, const char*, unsigned long)`
 *        at 0x008928..0x008a48 (.dynsym [062]).
 *        Tái dựng chính xác hàm `insert(unsigned long, const char*, unsigned long)` tại 0x008928..0x008a48 (.dynsym [062]).
 */
LibcppSsoStringAbi* sso_string_insert(LibcppSsoStringAbi* str, size_t pos, const char* s, size_t n) {
    const size_t sz = sso_string_size(str);
    // 0x008958..0x008964: if (sz < pos) __throw_out_of_range()
    if (pos > sz) {
        throw std::out_of_range(RodataStrings::kBasicStringErr);
    }
    const size_t cap = sso_string_capacity(str);
    if (cap - sz < n) {
        sso_string_grow_by_and_replace(str, cap, (sz + n) - cap, sz, pos, 0, n, s);
        return str;
    }
    if (n != 0) {
        char* p = sso_string_mutable_data(str);
        size_t n_move = sz - pos;
        if (n_move != 0) {
            // Handle overlapping source pointer inside [p + pos, p + sz] (@ 0x0089e4..0x008a00)
            const char* src_ptr = s;
            if (p + pos <= src_ptr && src_ptr < p + sz) {
                src_ptr += n;
            }
            std::memmove(p + pos + n, p + pos, n_move);
            std::memmove(p + pos, src_ptr, n);
        } else {
            std::memmove(p + pos, s, n);
        }
        size_t new_sz = sz + n;
        if (sso_string_is_long(str)) {
            str->long_rep.size = new_sz;
        } else {
            str->short_rep.size_shifted = static_cast<uint8_t>(new_sz << 1U);
        }
        p[new_sz] = '\0';
    }
    return str;
}

/**
 * @brief Reconstructs `std::__ndk1::operator+(const char*, const basic_string<char>&)`
 *        at 0x008824..0x008924 (.dynsym [092]).
 *        Tái dựng chính xác toán tử `operator+(const char*, const basic_string<char>&)` tại 0x008824..0x008924 (.dynsym [092]).
 */
void sso_string_concat_cstr_lhs(LibcppSsoStringAbi* out_str,
                                const char* lhs_cstr,
                                const LibcppSsoStringAbi* rhs_str) {
    sso_string_init_empty(out_str);
    const size_t lhs_len = std::strlen(lhs_cstr);
    const size_t rhs_len = sso_string_size(rhs_str);
    const size_t total_len = lhs_len + rhs_len;

    if (total_len >= static_cast<size_t>(-16LL)) {
        throw std::length_error(RodataStrings::kBasicStringErr);
    }

    if (total_len <= 22ULL) {
        out_str->short_rep.size_shifted = static_cast<uint8_t>( lhs_len << 1U );
        if (lhs_len != 0) {
            std::memcpy(out_str->short_rep.inline_buf, lhs_cstr, lhs_len);
        }
        out_str->short_rep.inline_buf[lhs_len] = '\0';
    } else {
        size_t alloc_bytes = (total_len + 16ULL) & ~15ULL;
        char* buf = static_cast<char*>(::operator new(alloc_bytes));
        out_str->long_rep.cap_and_flag = alloc_bytes | 1ULL;
        out_str->long_rep.size = lhs_len;
        out_str->long_rep.data = buf;
        if (lhs_len != 0) {
            std::memcpy(buf, lhs_cstr, lhs_len);
        }
        buf[lhs_len] = '\0';
    }
    sso_string_append(out_str, sso_string_data(rhs_str), rhs_len);
}

/**
 * @brief Reconstructs `std::__ndk1::operator<(const basic_string<char>&, const basic_string<char>&)`
 *        at 0x005804..0x005874 (.dynsym [056]).
 *        Tái dựng chính xác toán tử so sánh `operator<` tại 0x005804..0x005874 (.dynsym [056]).
 */
bool sso_string_less_than(const LibcppSsoStringAbi* lhs, const LibcppSsoStringAbi* rhs) noexcept {
    const size_t lhs_sz = sso_string_size(lhs);
    const size_t rhs_sz = sso_string_size(rhs);
    const size_t min_sz = (lhs_sz < rhs_sz) ? lhs_sz : rhs_sz;
    if (min_sz != 0) {
        int cmp = std::memcmp(sso_string_data(lhs), sso_string_data(rhs), min_sz);
        if (cmp != 0) {
            return cmp < 0;
        }
    }
    return lhs_sz < rhs_sz;
}

// ============================================================================
// 2. NDK libc++ Red-Black Tree (__tree<std::string>) Implementation
//    Triển khai Cây Đỏ-Đen (__tree<std::string>) của NDK libc++
// ============================================================================

void rbtree_init(RbTreeSetHeaderAbi* tree) noexcept {
    // Matches `add x8, x0, #0x40; str x8, [x0, #0x38]; stp xzr, xzr, [x0, #0x40]` @ 0x004d0c..0x004d1c
    tree->begin_node = &tree->root_left;
    tree->root_left = nullptr;
    tree->node_count = 0;
}

void rbtree_destroy_subtree(RbTreeSetHeaderAbi* tree, RbTreeNodeStringAbi* node) noexcept {
    // Matches `_ZNSt6__ndk16__tree...7destroyEPNS_11__tree_node...` @ 0x004a1c..0x004a6c
    if (node == nullptr) {
        return;
    }
    rbtree_destroy_subtree(tree, node->left);
    rbtree_destroy_subtree(tree, node->right);
    sso_string_destroy(&node->value);
    ::operator delete(node);
}

void rbtree_clear(RbTreeSetHeaderAbi* tree) noexcept {
    // Matches `_ZNSt6__ndk16__tree...5clearEv` @ 0x005600..0x005634
    rbtree_destroy_subtree(tree, tree->root_left);
    tree->begin_node = &tree->root_left;
    tree->root_left = nullptr;
    tree->node_count = 0;
}

RbTreeNodeStringAbi* rbtree_construct_node(const LibcppSsoStringAbi* key) {
    // Matches `__construct_node` @ 0x00537c..0x005428: `mov w0, #0x38; bl _Znwm` (56 bytes)
    auto* node = static_cast<RbTreeNodeStringAbi*>(::operator new(sizeof(RbTreeNodeStringAbi)));
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    node->is_black = false;
    std::memset(node->pad, 0, sizeof(node->pad));

    if (!sso_string_is_long(key)) {
        node->value = *key;
    } else {
        sso_string_init_empty(&node->value);
        try {
            sso_string_assign(&node->value, sso_string_data(key), sso_string_size(key));
        } catch (...) {
            ::operator delete(node);
            throw;
        }
    }
    return node;
}

RbTreeNodeStringAbi** rbtree_find_equal(RbTreeSetHeaderAbi* tree,
                                        RbTreeNodeStringAbi** parent_out,
                                        const LibcppSsoStringAbi* key) noexcept {
    // Matches `__find_equal` @ 0x0054dc..0x0055a0
    RbTreeNodeStringAbi* nd = tree->root_left;
    auto* end_node = reinterpret_cast<RbTreeNodeStringAbi*>(&tree->root_left);
    if (nd == nullptr) {
        *parent_out = end_node;
        return &tree->root_left;
    }
    while (true) {
        if (sso_string_less_than(key, &nd->value)) {
            if (nd->left != nullptr) {
                nd = nd->left;
            } else {
                *parent_out = nd;
                return &nd->left;
            }
        } else if (sso_string_less_than(&nd->value, key)) {
            if (nd->right != nullptr) {
                nd = nd->right;
            } else {
                *parent_out = nd;
                return &nd->right;
            }
        } else {
            *parent_out = nd;
            return (nd->parent != nullptr && nd->parent->left == nd) ? &nd->parent->left : &nd->parent->right;
        }
    }
}

namespace {

inline void rbtree_left_rotate(RbTreeNodeStringAbi* x) noexcept {
    RbTreeNodeStringAbi* y = x->right;
    x->right = y->left;
    if (x->right != nullptr) {
        x->right->parent = x;
    }
    y->parent = x->parent;
    if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

inline void rbtree_right_rotate(RbTreeNodeStringAbi* x) noexcept {
    RbTreeNodeStringAbi* y = x->left;
    x->left = y->right;
    if (x->left != nullptr) {
        x->left->parent = x;
    }
    y->parent = x->parent;
    if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

}  // namespace

void rbtree_balance_after_insert(RbTreeNodeStringAbi* root, RbTreeNodeStringAbi* x) noexcept {
    // Matches `std::__ndk1::__tree_balance_after_insert` @ 0x005638..0x005800 (.dynsym [059])
    x->is_black = (x == root);
    while (x != root && !x->parent->is_black) {
        if (x->parent == x->parent->parent->left) {
            RbTreeNodeStringAbi* y = x->parent->parent->right;
            if (y != nullptr && !y->is_black) {
                x = x->parent;
                x->is_black = true;
                x = x->parent;
                x->is_black = (x == root);
                y->is_black = true;
            } else {
                if (x != x->parent->left) {
                    x = x->parent;
                    rbtree_left_rotate(x);
                }
                x = x->parent;
                x->is_black = true;
                x = x->parent;
                x->is_black = false;
                rbtree_right_rotate(x);
                break;
            }
        } else {
            RbTreeNodeStringAbi* y = x->parent->parent->left;
            if (y != nullptr && !y->is_black) {
                x = x->parent;
                x->is_black = true;
                x = x->parent;
                x->is_black = (x == root);
                y->is_black = true;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    rbtree_right_rotate(x);
                }
                x = x->parent;
                x->is_black = true;
                x = x->parent;
                x->is_black = false;
                rbtree_left_rotate(x);
                break;
            }
        }
    }
}

void rbtree_insert_node_at(RbTreeSetHeaderAbi* tree,
                           RbTreeNodeStringAbi* parent,
                           RbTreeNodeStringAbi** child_slot,
                           RbTreeNodeStringAbi* new_node) noexcept {
    // Matches `__insert_node_at` @ 0x0055a4..0x0055fc (.dynsym [052])
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->parent = parent;
    *child_slot = new_node;

    auto* begin_ptr = static_cast<RbTreeNodeStringAbi*>(tree->begin_node);
    if (begin_ptr->left != nullptr) {
        tree->begin_node = begin_ptr->left;
    }
    rbtree_balance_after_insert(tree->root_left, new_node);
    tree->node_count += 1ULL;
}

std::pair<RbTreeNodeStringAbi*, bool> rbtree_emplace_unique(RbTreeSetHeaderAbi* tree,
                                                            const LibcppSsoStringAbi* key) {
    // Matches `__emplace_unique_key_args` @ 0x00542c..0x0054d8 (.dynsym [102])
    RbTreeNodeStringAbi* parent = nullptr;
    RbTreeNodeStringAbi** slot = rbtree_find_equal(tree, &parent, key);
    if (*slot == nullptr) {
        RbTreeNodeStringAbi* node = rbtree_construct_node(key);
        rbtree_insert_node_at(tree, parent, slot, node);
        return {node, true};
    }
    return {*slot, false};
}

const RbTreeNodeStringAbi* rbtree_find(const RbTreeSetHeaderAbi* tree,
                                       const LibcppSsoStringAbi* key) noexcept {
    // Matches `__tree::find` @ 0x004c18..0x004c6c (.dynsym [051])
    const auto* end_node = reinterpret_cast<const RbTreeNodeStringAbi*>(&tree->root_left);
    const RbTreeNodeStringAbi* cur = tree->root_left;
    const RbTreeNodeStringAbi* result = end_node;

    while (cur != nullptr) {
        if (!sso_string_less_than(&cur->value, key)) {
            result = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (result == end_node || sso_string_less_than(key, &result->value)) {
        return end_node;
    }
    return result;
}

RbTreeNodeStringAbi* rbtree_next_iter(RbTreeNodeStringAbi* node) noexcept {
    // Matches `std::__ndk1::__tree_next_iter` @ 0x004b94..0x004bd4 (.dynsym [058])
    if (node->right != nullptr) {
        RbTreeNodeStringAbi* min_node = node->right;
        while (min_node->left != nullptr) {
            min_node = min_node->left;
        }
        return min_node;
    }
    while (node != node->parent->left) {
        node = node->parent;
    }
    return node->parent;
}

void rbtree_copy_assign(RbTreeSetHeaderAbi* dst, const RbTreeSetHeaderAbi* src) {
    // Matches `__assign_multi` / `setSampler` copy @ 0x0045d0..0x0046e4 & 0x004ad4..0x004b90
    if (dst == src) {
        return;
    }
    rbtree_clear(dst);
    const auto* end_node = reinterpret_cast<const RbTreeNodeStringAbi*>(&src->root_left);
    auto* cur = static_cast<RbTreeNodeStringAbi*>(src->begin_node);
    while (cur != end_node && cur != nullptr) {
        rbtree_emplace_unique(dst, &cur->value);
        cur = rbtree_next_iter(cur);
    }
}

}  // namespace iesapplogger
