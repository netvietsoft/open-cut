/**
 * @file pumbaa_network_rbtree_dwarf.cpp
 * @brief Implementation of `std::__ndk1::basic_string`, `std::__ndk1::__tree` Red-Black Tree
 *        (`0x002dfc..0x003640`), and the embedded LLVM `libunwind` DWARF CFI primitives
 *        (`0x003644..0x00406c`) for `libpumbaa-network.so`.
 *        Hiện thực hóa `basic_string`, Cây Đỏ-Đen `std::__ndk1::__tree` (`0x002dfc..0x003640`),
 *        và các nguyên hàm DWARF CFI (`0x003644..0x00406c`) cho `libpumbaa-network.so`.
 */

#include "pumbaa_network_rbtree_dwarf.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

// ============================================================================
// 1. `std::__ndk1::basic_string` SSO & Long-Mode Implementation (`0x003384..0x003440`)
//    Hiện thực hóa `basic_string` Chế độ Chuỗi Ngắn (SSO) & Chuỗi Dài (`0x003384..0x003440`)
// ============================================================================

void LibcxxStringInitFromCStr(LibcxxString24Abi* dst, const char* s, size_t len) {
    if (dst == nullptr) {
        return;
    }
    std::memset(dst, 0, sizeof(LibcxxString24Abi));
    if (s == nullptr || len == 0u) {
        return;
    }
    if (len < 23u) {
        // Short string representation (SSO): tag = (len << 1)
        dst->short_repr.tag = static_cast<uint8_t>(len << 1u);
        std::memcpy(dst->short_repr.inline_buf, s, len);
        dst->short_repr.inline_buf[len] = '\0';
    } else {
        // Long string representation (`0x0033e4..0x003414`):
        // add x8, x20, #0x10; and x22, x8, #-16; operator new(x22); orr x8, x22, #1
        const size_t aligned_cap = (len + 0x10u) & ~static_cast<size_t>(0x0Fu);
        char* buf = static_cast<char*>(::operator new(aligned_cap));
        std::memcpy(buf, s, len);
        buf[len] = '\0';
        dst->long_repr.cap_and_flag = static_cast<uint64_t>(aligned_cap) | 1ULL;
        dst->long_repr.size         = static_cast<uint64_t>(len);
        dst->long_repr.data         = buf;
    }
}

/**
 * @brief Exact reconstruction of `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_`
 *        (`0x003384..0x00342c`, `172 bytes`):
 *        - `0x003394..0x003398`: `stp xzr, xzr, [x0]; str xzr, [x0, #0x10]`
 *        - `0x00339c..0x0033b8`: If `(src->tag & 1) == 0` (`tbnz w8, #0, #0x33bc`), copies 24 bytes directly (`ldr x8, [x1, #0x10]; ldr q0, [x1]`).
 *        - `0x0033bc..0x0033c4`: Loads `size = src->long_repr.size`; if `size >= ~0x0FULL` (`cmn x20, #0x10; b.hs #0x3428`), calls `__throw_length_error()` (`0x003430`).
 *        - `0x0033cc..0x003414`: If `size < 23` (`cmp x20, #0x17`), stores SSO `lsl w8, w20, #1`, else allocates `(size + 0x10) & ~0xF` via `operator new` and copies bytes via `memcpy`.
 */
void LibcxxStringCopyConstruct(LibcxxString24Abi* dst, const LibcxxString24Abi* src) {
    if (dst == nullptr) {
        return;
    }
    std::memset(dst, 0, sizeof(LibcxxString24Abi));
    if (src == nullptr) {
        return;
    }
    if ((src->short_repr.tag & 1u) == 0u) {
        std::memcpy(dst, src, sizeof(LibcxxString24Abi));
        return;
    }
    const uint64_t size = src->long_repr.size;
    if (size >= 0xFFFFFFFFFFFFFFF0ULL) {
        throw std::length_error(RodataConstants::kLabelBasicString);
    }
    LibcxxStringInitFromCStr(dst, src->long_repr.data, static_cast<size_t>(size));
}

void LibcxxStringDestroy(LibcxxString24Abi* str) noexcept {
    if (str == nullptr) {
        return;
    }
    // Matches `0x003610..0x00362c`: `tbz w8, #0, skip; ldr x0, [node, #0x30/#0x48]; bl operator delete`
    if ((str->short_repr.tag & 1u) != 0u && str->long_repr.data != nullptr) {
        ::operator delete(str->long_repr.data);
    }
    std::memset(str, 0, sizeof(LibcxxString24Abi));
}

const char* LibcxxStringData(const LibcxxString24Abi* str) noexcept {
    if (str == nullptr) {
        return "";
    }
    return ((str->short_repr.tag & 1u) != 0u) ? str->long_repr.data : str->short_repr.inline_buf;
}

size_t LibcxxStringSize(const LibcxxString24Abi* str) noexcept {
    if (str == nullptr) {
        return 0u;
    }
    return ((str->short_repr.tag & 1u) != 0u)
               ? static_cast<size_t>(str->long_repr.size)
               : static_cast<size_t>(str->short_repr.tag >> 1u);
}

int LibcxxStringCompare(const LibcxxString24Abi* a, const LibcxxString24Abi* b) noexcept {
    const size_t len_a   = LibcxxStringSize(a);
    const size_t len_b   = LibcxxStringSize(b);
    const size_t min_len = std::min(len_a, len_b);
    if (min_len > 0u) {
        const int cmp = std::memcmp(LibcxxStringData(a), LibcxxStringData(b), min_len);
        if (cmp != 0) {
            return cmp;
        }
    }
    if (len_a < len_b) {
        return -1;
    }
    if (len_a > len_b) {
        return 1;
    }
    return 0;
}

// ============================================================================
// 2. `std::__ndk1::__tree` Red-Black Tree Implementation (`0x002dfc..0x003640`)
//    Hiện thực hóa Cây Đỏ-Đen `std::__ndk1::__tree` (`0x002dfc..0x003640`)
// ============================================================================

namespace {

inline void RbTreeRotateLeft(RbTreeNodeStringPairAbi* x) noexcept {
    // Matches `0x0034c0..0x0034f4` and `0x003558..0x003590`
    RbTreeNodeStringPairAbi* y = x->right;
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
    y->left   = x;
    x->parent = y;
}

inline void RbTreeRotateRight(RbTreeNodeStringPairAbi* x) noexcept {
    // Matches `0x003518..0x00354c` and `0x0035a4..0x0035dc`
    RbTreeNodeStringPairAbi* y = x->left;
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
    y->right  = x;
    x->parent = y;
}

} // namespace

void RbTreeBalanceAfterInsert(RbTreeNodeStringPairAbi* root, RbTreeNodeStringPairAbi* x) noexcept {
    if (root == nullptr || x == nullptr) {
        return;
    }
    // `0x003444..0x003450`: `cmp x1, x0; cset w8, eq; strb w8, [x1, #0x18]; b.eq #0x3500`
    x->is_black = (x == root) ? 1u : 0u;
    while (x != root && x->parent->is_black == 0u) {
        RbTreeNodeStringPairAbi* parent      = x->parent;
        RbTreeNodeStringPairAbi* grandparent = parent->parent;
        if (parent == grandparent->left) {
            RbTreeNodeStringPairAbi* uncle = grandparent->right;
            if (uncle != nullptr && uncle->is_black == 0u) {
                parent->is_black      = 1u;
                uncle->is_black       = 1u;
                grandparent->is_black = (grandparent == root) ? 1u : 0u;
                x                     = grandparent;
            } else {
                if (x == parent->right) {
                    x = parent;
                    RbTreeRotateLeft(x);
                    parent      = x->parent;
                    grandparent = parent->parent;
                }
                parent->is_black      = 1u;
                grandparent->is_black = 0u;
                RbTreeRotateRight(grandparent);
                break;
            }
        } else {
            RbTreeNodeStringPairAbi* uncle = grandparent->left;
            if (uncle != nullptr && uncle->is_black == 0u) {
                parent->is_black      = 1u;
                uncle->is_black       = 1u;
                grandparent->is_black = (grandparent == root) ? 1u : 0u;
                x                     = grandparent;
            } else {
                if (x == parent->left) {
                    x = parent;
                    RbTreeRotateRight(x);
                    parent      = x->parent;
                    grandparent = parent->parent;
                }
                parent->is_black      = 1u;
                grandparent->is_black = 0u;
                RbTreeRotateLeft(grandparent);
                break;
            }
        }
    }
}

RbTreeNodeStringPairAbi** RbTreeFindEqualRoot(
    LibcxxMapStringAbi* tree,
    RbTreeNodeStringPairAbi** out_parent,
    const LibcxxString24Abi& key) noexcept {
    // Matches `_ZNSt6__ndk16__tree<...>::__find_equal(root)` @ `0x0031e4..0x003300`
    RbTreeNodeStringPairAbi* end_node =
        reinterpret_cast<RbTreeNodeStringPairAbi*>(&tree->end_left);
    RbTreeNodeStringPairAbi* nd = tree->end_left;
    if (nd == nullptr) {
        *out_parent = end_node;
        return &tree->end_left;
    }
    while (true) {
        const int cmp = LibcxxStringCompare(&key, &nd->key);
        if (cmp < 0) {
            if (nd->left != nullptr) {
                nd = nd->left;
            } else {
                *out_parent = nd;
                return &nd->left;
            }
        } else if (cmp > 0) {
            if (nd->right != nullptr) {
                nd = nd->right;
            } else {
                *out_parent = nd;
                return &nd->right;
            }
        } else {
            *out_parent = nd;
            return &nd;
        }
    }
}

RbTreeNodeStringPairAbi** RbTreeFindEqualHint(
    LibcxxMapStringAbi* tree,
    RbTreeNodeStringPairAbi* /*hint*/,
    RbTreeNodeStringPairAbi** out_parent,
    RbTreeNodeStringPairAbi** /*out_dummy*/,
    const LibcxxString24Abi& key) noexcept {
    return RbTreeFindEqualRoot(tree, out_parent, key);
}

RbTreeNodeStringPairAbi* RbTreeEmplaceHintUnique(
    LibcxxMapStringAbi* tree,
    RbTreeNodeStringPairAbi* hint,
    const LibcxxString24Abi& key,
    const std::pair<LibcxxString24Abi, LibcxxString24Abi>& kv_pair) {
    // Matches `_ZNSt6__ndk16__tree<...>::__emplace_hint_unique_key_args` @ `0x002dfc..0x002f04`
    RbTreeNodeStringPairAbi* parent = nullptr;
    RbTreeNodeStringPairAbi* dummy  = nullptr;
    RbTreeNodeStringPairAbi** slot  = RbTreeFindEqualHint(tree, hint, &parent, &dummy, key);
    if (*slot != nullptr && *slot != parent) {
        return *slot;
    }
    // Check if key already exists at parent
    if (parent != reinterpret_cast<RbTreeNodeStringPairAbi*>(&tree->end_left) &&
        parent != nullptr &&
        LibcxxStringCompare(&key, &parent->key) == 0) {
        return parent;
    }

    // `0x002e44..0x002e48`: `mov w0, #0x50; bl operator new`
    auto* node = static_cast<RbTreeNodeStringPairAbi*>(::operator new(sizeof(RbTreeNodeStringPairAbi)));
    std::memset(node, 0, sizeof(RbTreeNodeStringPairAbi));

    // `0x002e50..0x002e68`: Copy-construct key (+0x20) and value (+0x38)
    try {
        LibcxxStringCopyConstruct(&node->key, &kv_pair.first);
        try {
            LibcxxStringCopyConstruct(&node->value, &kv_pair.second);
        } catch (...) {
            LibcxxStringDestroy(&node->key);
            throw;
        }
    } catch (...) {
        ::operator delete(node);
        throw;
    }

    node->left   = nullptr;
    node->right  = nullptr;
    node->parent = parent;
    *slot        = node;

    if (tree->begin_node->left != nullptr) {
        tree->begin_node = tree->begin_node->left;
    }
    RbTreeBalanceAfterInsert(tree->end_left, node);
    tree->node_count += 1u;
    return node;
}

void RbTreeDestroy(LibcxxMapStringAbi* tree, RbTreeNodeStringPairAbi* node) noexcept {
    // Matches `_ZNSt6__ndk16__tree<...>::destroy` @ `0x0035e4..0x003640`
    if (node == nullptr) {
        return;
    }
    RbTreeDestroy(tree, node->left);
    RbTreeDestroy(tree, node->right);
    LibcxxStringDestroy(&node->value);
    LibcxxStringDestroy(&node->key);
    ::operator delete(node);
}

RbTreeNodeStringPairAbi* RbTreeNextNode(RbTreeNodeStringPairAbi* node) noexcept {
    // Matches `0x002258..0x00229c` and `0x002904..0x002948`
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right != nullptr) {
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    while (node->parent != nullptr && node != node->parent->left) {
        node = node->parent;
    }
    return (node != nullptr) ? node->parent : nullptr;
}

// ============================================================================
// 3. Embedded LLVM `libunwind` DWARF CFI Primitives (`0x003644..0x0038ac`)
//    Các Nguyên hàm DWARF CFI Nhúng (`0x003644..0x0038ac`)
// ============================================================================

const uint8_t* DecodeDwarfULEB128(const uint8_t* p, uint64_t* out_val) noexcept {
    // Exact match for `0x003644..0x003668`
    uint64_t result = 0u;
    uint32_t shift  = 0u;
    uint8_t  byte   = 0u;
    do {
        byte = *p++;
        result |= (static_cast<uint64_t>(byte & 0x7Fu) << shift);
        shift += 7u;
    } while ((byte & 0x80u) != 0u);
    if (out_val != nullptr) {
        *out_val = result;
    }
    return p;
}

const uint8_t* DecodeDwarfSLEB128(const uint8_t* p, int64_t* out_val) noexcept {
    // Exact match for `0x00366c..0x0036a8`
    uint64_t result = 0u;
    uint32_t shift  = 0u;
    uint8_t  byte   = 0u;
    do {
        byte = *p++;
        result |= (static_cast<uint64_t>(byte & 0x7Fu) << shift);
        shift += 7u;
    } while ((byte & 0x80u) != 0u);

    if (shift <= 0x3Fu && (byte & 0x40u) != 0u) {
        result |= (~0ULL << shift);
    }
    if (out_val != nullptr) {
        *out_val = static_cast<int64_t>(result);
    }
    return p;
}

const uint8_t* DecodeDwarfEncodedPointer(
    uint8_t encoding,
    uint64_t datarel_base,
    const uint8_t* p,
    uint64_t* out_val) noexcept {
    // Exact match for `0x0036ac..0x003798`
    if (p == nullptr || out_val == nullptr) {
        return p;
    }
    const uint8_t* start_p = p;
    uint64_t result = 0u;

    if (encoding == 0x50u) {
        // DW_EH_PE_aligned (`0x0036c4..0x0036e0`): align `p` to 8-byte boundary
        const uintptr_t aligned = (reinterpret_cast<uintptr_t>(p) + 7u) & ~static_cast<uintptr_t>(7u);
        p = reinterpret_cast<const uint8_t*>(aligned);
        std::memcpy(&result, p, sizeof(uint64_t));
        p += sizeof(uint64_t);
        *out_val = result;
        return p;
    }

    switch (encoding & 0x0Fu) {
        case 0x00u: // DW_EH_PE_absptr (8-byte pointer @ 0x00375c)
        case 0x04u: // DW_EH_PE_udata8
            std::memcpy(&result, p, sizeof(uint64_t));
            p += 8;
            break;
        case 0x01u: // DW_EH_PE_uleb128 (0x003708)
            p = DecodeDwarfULEB128(p, &result);
            break;
        case 0x02u: { // DW_EH_PE_udata2 (0x00372c)
            uint16_t u16 = 0u;
            std::memcpy(&u16, p, sizeof(uint16_t));
            result = u16;
            p += 2;
            break;
        }
        case 0x03u: { // DW_EH_PE_udata4 (0x003738)
            uint32_t u32 = 0u;
            std::memcpy(&u32, p, sizeof(uint32_t));
            result = u32;
            p += 4;
            break;
        }
        case 0x09u: { // DW_EH_PE_sleb128 (0x003718)
            int64_t s64 = 0;
            p = DecodeDwarfSLEB128(p, &s64);
            result = static_cast<uint64_t>(s64);
            break;
        }
        case 0x0Au: { // DW_EH_PE_sdata2 (0x003744)
            int16_t s16 = 0;
            std::memcpy(&s16, p, sizeof(int16_t));
            result = static_cast<uint64_t>( static_cast<int64_t>(s16));
            p += 2;
            break;
        }
        case 0x0Bu: { // DW_EH_PE_sdata4 (0x003750)
            int32_t s32 = 0;
            std::memcpy(&s32, p, sizeof(int32_t));
            result = static_cast<uint64_t>(static_cast<int64_t>(s32));
            p += 4;
            break;
        }
        case 0x0Cu: { // DW_EH_PE_sdata8 (0x00375c)
            int64_t s64 = 0;
            std::memcpy(&s64, p, sizeof(int64_t));
            result = static_cast<uint64_t>(s64);
            p += 8;
            break;
        }
        default:
            *out_val = 0u;
            return p;
    }

    if (result != 0u) {
        // `0x003770..0x003784`:
        // `and w2, w20, #0x70; cmp w2, #0x10; csel x19, x19, x22, eq; add x1, x1, x19; tbz w20, #7, skip`
        const uint8_t rel_mode = static_cast<uint8_t>(encoding & 0x70u);
        if (rel_mode == 0x10u) {
            result += reinterpret_cast<uintptr_t>(start_p);
        } else if (rel_mode != 0x00u) {
            result += datarel_base;
        }
        if ((encoding & 0x80u) != 0u) {
            uint64_t indirect_val = 0u;
            std::memcpy(&indirect_val, reinterpret_cast<const void*>(result), sizeof(uint64_t));
            result = indirect_val;
        }
    }

    *out_val = result;
    return p;
}

void InitDwarfRegisterSizeTable(PumbaaNetworkBssSegment& bss) noexcept {
    // Exact match for `0x00379c..0x0038ac`:
    // Sets `dwarf_reg_size_table[0..31] = 8` and `dwarf_reg_size_table[64..96] = 8`.
    std::memset(bss.dwarf_reg_size_table, 0, sizeof(bss.dwarf_reg_size_table));
    for (size_t i = 0u; i <= 0x1Fu; ++i) {
        bss.dwarf_reg_size_table[i] = 8u;
    }
    for (size_t i = 0x40u; i <= 0x60u; ++i) {
        bss.dwarf_reg_size_table[i] = 8u;
    }
}

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai
