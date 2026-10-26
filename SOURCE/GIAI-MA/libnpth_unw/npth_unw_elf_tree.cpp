// ============================================================================
// FILE: npth_unw_elf_tree.cpp
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64)
// ROLE: Implementation of Red-Black Tree BuildId Deduplicator & Frame Formatter
//       Triển khai Cây Đỏ-Đen khử trùng lặp BuildId & Bộ định dạng khung ngăn xếp
// ============================================================================

#include "npth_unw_elf_tree.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>

namespace NextAI {
namespace OpenCut {
namespace NpthUnw {

namespace {

// [EN] Global empty string fallback at `.bss 0x00eac8` guarded by `.bss 0x00eae0`
//      (verified at `0x004c7c..0x004cf4`).
// [VN] Chuỗi rỗng dự phòng toàn cục tại `.bss 0x00eac8` được bảo vệ bởi `.bss 0x00eae0`
//      (xác minh tại `0x004c7c..0x004cf4`).
std::once_flag g_empty_string_once;
std::string*   g_empty_string_ptr = nullptr;

std::string ResolveMapFullName(const UnwindStackMapInfoAbi* map_info) {
    if (!map_info || !map_info->name) {
        return std::string();
    }
    return *(map_info->name);
}

} // namespace

// ============================================================================
// 1. SafeSnprintf (`0x004db4..0x004e24`)
// ============================================================================
// [EN] Disassembly at `0x004db4..0x004e24`:
//        sub  sp, sp, #0xf0
//        ...
//        mov  w2, wzr               ; flag = 0
//        mov  x3, x1                ; slen = chk_size
//        mov  x1, x2                ; maxlen = buf_size
//        mov  x4, x8                ; format = fmt
//        bl   #0x6420               ; __vsnprintf_chk(buf, maxlen, 0, slen, fmt, ap)
// [VN] Hàm bọc `__vsnprintf_chk` tại `0x004db4..0x004e24`.
// ============================================================================
int NpthUnwElfTreeAndFormatter::SafeSnprintf(
    char* buffer,
    size_t buf_size,
    size_t chk_size,
    const char* fmt,
    ...) {
    if (!buffer || buf_size == 0 || !fmt) {
        return 0;
    }
    const size_t effective_max = (chk_size < buf_size) ? chk_size : buf_size;
    va_list args;
    va_start(args, fmt);
    const int written = std::vsnprintf(buffer, effective_max, fmt, args);
    va_end(args);
    return written;
}

// ============================================================================
// 2. DereferenceSharedStringOrEmpty (`0x004c7c..0x004cf4`)
// ============================================================================
// [EN] Disassembly at `0x004c7c..0x004cf4`:
//        adr   x8, #0xeae0          ; guard variable for g_empty_string
//        adr   x9, #0xeac8          ; g_empty_string storage (24 bytes)
//        ldarb w8, [x8]
//        tbz   w8, #0, #0x4cac      ; __cxa_guard_acquire(&0xeae0) -> zero-init 24B -> __cxa_guard_release
//        ldr   x8, [x0]             ; shared_ptr.get()
//        cmp   x8, #0
//        csel  x0, x9, x8, eq       ; return ptr ? *ptr : g_empty_string
// [VN] Giải tham chiếu `shared_ptr<string>` hoặc trả về chuỗi rỗng tĩnh tại `0x00eac8`.
// ============================================================================
const std::string& NpthUnwElfTreeAndFormatter::DereferenceSharedStringOrEmpty(
    const std::shared_ptr<std::string>& ptr) {
    std::call_once(g_empty_string_once, []() {
        g_empty_string_ptr = new std::string();
    });
    if (ptr) {
        return *ptr;
    }
    return *g_empty_string_ptr;
}

// ============================================================================
// 3. CompareByteSlice (`0x004cf8..0x004d3c`)
// ============================================================================
// [EN] Disassembly at `0x004cf8..0x004d3c`:
//        cmp   x3, x1               ; compare rhs_len (x3) vs lhs_len (x1)
//        csel  x8, x3, x1, lo       ; min_len = min(rhs_len, lhs_len)
//        cbz   x8, #0x4d24
//        bl    #0x64f0              ; memcmp(lhs, rhs, min_len)
//        cbnz  w0, #0x4d34          ; if non-zero, return memcmp result
//        cmp   x19, x20             ; compare rhs_len vs lhs_len
//        mov   w8, #-1
//        cneg  w8, w8, ls           ; if rhs_len <= lhs_len -> +1 else -1
//        csel  w0, wzr, w8, eq      ; if equal -> 0
// [VN] So sánh hai vùng byte bằng `memcmp` và độ dài chuỗi tại `0x004cf8..0x004d3c`.
// ============================================================================
int NpthUnwElfTreeAndFormatter::CompareByteSlice(
    const char* lhs,
    size_t lhs_len,
    const char* rhs,
    size_t rhs_len) {
    const size_t min_len = (rhs_len < lhs_len) ? rhs_len : lhs_len;
    if (min_len > 0) {
        const int cmp = std::memcmp(lhs, rhs, min_len);
        if (cmp != 0) {
            return cmp;
        }
    }
    if (rhs_len == lhs_len) {
        return 0;
    }
    return (rhs_len <= lhs_len) ? 1 : -1;
}

// ============================================================================
// 4. CompareStringsLess (`0x004d40..0x004db0`)
// ============================================================================
// [EN] Disassembly at `0x004d40..0x004db0`:
//      Extracts SSO/long lengths `lhs_len` (`x20`) and `rhs_len` (`x19`), calls
//      `memcmp(lhs_data, rhs_data, min(lhs_len, rhs_len))` (`0x0064f0`), and if
//      `memcmp == 0`, evaluates `lhs_len < rhs_len` via `csinv w0, w8, wzr, hs` +
//      `lsr w0, w0, #0x1f`.
// [VN] So sánh nhỏ hơn (`lhs < rhs`) giữa hai chuỗi `std::string` phục vụ Cây Đỏ-Đen.
// ============================================================================
bool NpthUnwElfTreeAndFormatter::CompareStringsLess(
    const std::string& lhs,
    const std::string& rhs) {
    const size_t lhs_len = lhs.size();
    const size_t rhs_len = rhs.size();
    const size_t min_len = (rhs_len < lhs_len) ? rhs_len : lhs_len;
    if (min_len > 0) {
        const int cmp = std::memcmp(lhs.data(), rhs.data(), min_len);
        if (cmp != 0) {
            return (static_cast<uint32_t>(cmp) >> 31) != 0u;
        }
    }
    return lhs_len < rhs_len;
}

// ============================================================================
// 5. DestroyBuildIdRbTree (`0x0047a0..0x0047d8`)
// ============================================================================
// [EN] Disassembly at `0x0047a0..0x0047d8`:
//        cbz   x0, #0x47d8
//        stp   x30, x19, [sp, #-0x10]!
//        mov   x19, x0
//        ldr   x0, [x0]             ; node->left (+0x00)
//        bl    #0x47a0              ; recursive destroy left
//        ldr   x0, [x19, #8]        ; node->right (+0x08)
//        bl    #0x47a0              ; recursive destroy right
//        ldrb  w8, [x19, #0x20]     ; node->key is_long bit (+0x20)
//        tbz   w8, #0, #0x47cc
//        ldr   x0, [x19, #0x30]     ; node->key heap buffer (+0x30)
//        bl    #0x6220              ; operator delete(void*)
//        mov   x0, x19
//        ldp   x30, x19, [sp], #0x10
//        b     #0x6220              ; tail-call operator delete(node)
// [VN] Hủy đệ quy hậu thứ tự Cây Đỏ-Đen tại `0x0047a0..0x0047d8`.
// ============================================================================
void NpthUnwElfTreeAndFormatter::DestroyBuildIdRbTree(BuildIdRbTreeNode* node) {
    if (!node) {
        return;
    }
    DestroyBuildIdRbTree(node->left);
    DestroyBuildIdRbTree(node->right);
    delete node;
}

// ============================================================================
// 6. Red-Black Tree Rotations & Rebalancing (`0x004aa0..0x004c38`)
// ============================================================================
// [EN] Exact libc++ `__tree_balance_after_insert` reconstructed from `0x004aa0..0x004c38`:
//      - `node->is_black` (`+0x18`) is set to `1` if `node == root`, else `0` (Red).
//      - While `node != root` and `node->parent->is_black == 0`:
//        * Checks uncle color; if uncle is Red (`is_black == 0`), recolors parent
//          and uncle to Black (`1`), grandparent to Red (`(grandparent == root) ? 1 : 0`),
//          and moves `node = grandparent` (`0x004af4..0x004b0c`).
//        * Otherwise performs Left-Right / Left-Left (`0x004b14..0x004bf0`) or
//          Right-Left / Right-Right (`0x004b28..0x004c34`) rotations and recolors.
// [VN] Cân bằng Cây Đỏ-Đen sau khi thêm nút mới (`0x004aa0..0x004c38`).
// ============================================================================
void NpthUnwElfTreeAndFormatter::RotateLeft(
    BuildIdRbTreeNode* x,
    BuildIdRbTreeNode** root_slot) {
    BuildIdRbTreeNode* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x == *root_slot) {
        *root_slot = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void NpthUnwElfTreeAndFormatter::RotateRight(
    BuildIdRbTreeNode* x,
    BuildIdRbTreeNode** root_slot) {
    BuildIdRbTreeNode* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x == *root_slot) {
        *root_slot = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void NpthUnwElfTreeAndFormatter::RebalanceAfterInsert(
    BuildIdRbTreeNode* x,
    BuildIdRbTreeNode** root_slot) {
    x->is_black = (x == *root_slot) ? 1u : 0u;
    while (x != *root_slot && x->parent && x->parent->is_black == 0u) {
        BuildIdRbTreeNode* parent = x->parent;
        BuildIdRbTreeNode* grandparent = parent->parent;
        if (!grandparent) {
            break;
        }
        if (parent == grandparent->left) {
            BuildIdRbTreeNode* uncle = grandparent->right;
            if (uncle != nullptr && uncle->is_black == 0u) {
                parent->is_black = 1u;
                uncle->is_black = 1u;
                grandparent->is_black = (grandparent == *root_slot) ? 1u : 0u;
                x = grandparent;
            } else {
                if (x == parent->right) {
                    x = parent;
                    RotateLeft(x, root_slot);
                    parent = x->parent;
                    grandparent = parent ? parent->parent : nullptr;
                }
                if (parent) {
                    parent->is_black = 1u;
                }
                if (grandparent) {
                    grandparent->is_black = 0u;
                    RotateRight(grandparent, root_slot);
                }
                break;
            }
        } else {
            BuildIdRbTreeNode* uncle = grandparent->left;
            if (uncle != nullptr && uncle->is_black == 0u) {
                parent->is_black = 1u;
                uncle->is_black = 1u;
                grandparent->is_black = (grandparent == *root_slot) ? 1u : 0u;
                x = grandparent;
            } else {
                if (x == parent->left) {
                    x = parent;
                    RotateRight(x, root_slot);
                    parent = x->parent;
                    grandparent = parent ? parent->parent : nullptr;
                }
                if (parent) {
                    parent->is_black = 1u;
                }
                if (grandparent) {
                    grandparent->is_black = 0u;
                    RotateLeft(grandparent, root_slot);
                }
                break;
            }
        }
    }
    if (*root_slot) {
        (*root_slot)->is_black = 1u;
    }
}

// ============================================================================
// 7. InsertAndFormatBuildIdSummary (`0x0047dc..0x004c78`)
// ============================================================================
// [EN] Disassembly at `0x0047dc..0x004c78`:
//      1. Checks `if (!map_info) return;` (`cbz x1, #0x4c64` @ `0x0047f0`).
//      2. Calls `DereferenceSharedStringOrEmpty(map_info->name)` (`0x004804`).
//      3. Checks `!name.empty() && name[0] == '/'` (`cmp w8, #0x2f` @ `0x004828`).
//      4. If `name.size() >= 5`, checks `CompareByteSlice(name.end()-5, 5, ".vdex", 5) != 0`
//         (`0x004844..0x004860`), and if `name.size() >= 4`, checks
//         `CompareByteSlice(name.end()-4, 4, ".jar", 4) != 0` (`0x004864..0x004880`).
//      5. Calls `full_name = map_info->GetFullName()` (`bl #0x64c0` @ `0x00488c`).
//      6. Searches `tree->root_node` (`0x004894..0x0048d8`) using `CompareStringsLess` (`0x004d40`).
//         If `full_name` already exists in the tree, returns early (`tbz w0, #0, #0x4c54`).
//      7. Calls `build_id = map_info->GetPrintableBuildID()` (`bl #0x64d0` @ `0x0048e8`).
//      8. If `!build_id.empty()`, appends `"    " + full_name + " (BuildId: " + build_id + " )\n"`
//         to `out_summary` (`0x004904..0x004a08`).
//      9. Allocates `new BuildIdRbTreeNode` (`56 bytes` @ `0x004a60`), links it into
//         the BST, updates `tree->begin_node` (`0x004a8c..0x004a98`), calls
//         `RebalanceAfterInsert` (`0x004aa0..0x004c38`), and increments `tree->node_count`
//         (`ldr x8, [x19, #0x10]; add x8, x8, #1; str x8, [x19, #0x10]` @ `0x004c38..0x004c40`).
// [VN] Kiểm tra `map_info`, lọc bỏ `.vdex`/`.jar`, định dạng dòng BuildId và chèn
//      vào Cây Đỏ-Đen để khử trùng lặp.
// ============================================================================
void NpthUnwElfTreeAndFormatter::InsertAndFormatBuildIdSummary(
    std::string& out_summary,
    const UnwindStackMapInfoAbi* map_info,
    BuildIdRbTreeHeader* tree) {
    if (!map_info || !tree) {
        return;
    }

    const std::string& raw_name = DereferenceSharedStringOrEmpty(map_info->name);
    if (raw_name.empty() || raw_name[0] != '/') {
        return;
    }

    // [EN] Filter out ".vdex" (len 5) and ".jar" (len 4) at 0x004830..0x004880.
    // [VN] Lọc bỏ tệp ".vdex" (độ dài 5) và ".jar" (độ dài 4) tại 0x004830..0x004880.
    if (raw_name.size() >= 5) {
        if (CompareByteSlice(
                raw_name.data() + raw_name.size() - 5,
                5,
                NpthUnwRodataStrings::kExtVdex,
                5) == 0) {
            return;
        }
    }
    if (raw_name.size() >= 4) {
        if (CompareByteSlice(
                raw_name.data() + raw_name.size() - 4,
                4,
                NpthUnwRodataStrings::kExtJar,
                4) == 0) {
            return;
        }
    }

    const std::string full_name = ResolveMapFullName(map_info);

    // [EN] Lower-bound lookup in Red-Black Tree (`0x004894..0x0048d8`).
    // [VN] Tìm kiếm cận dưới trong Cây Đỏ-Đen (`0x004894..0x0048d8`).
    BuildIdRbTreeNode* cur = tree->root_node;
    BuildIdRbTreeNode* candidate = nullptr;
    while (cur != nullptr) {
        if (!CompareStringsLess(cur->key, full_name)) {
            candidate = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (candidate != nullptr && !CompareStringsLess(full_name, candidate->key)) {
        // Already present in tree!
        return;
    }

    // [EN] Format `"    " + full_name + " (BuildId: " + build_id + " )\n"` (`0x004900..0x004a08`).
    // [VN] Định dạng chuỗi BuildId nếu `build_id` khác rỗng (`0x004900..0x004a08`).
    if (!map_info->build_id.empty()) {
        std::string line = std::string(NpthUnwRodataStrings::kIndentFourSpaces) + full_name;
        line.append(NpthUnwRodataStrings::kBuildIdPrefix);
        line.append(map_info->build_id);
        line.append(NpthUnwRodataStrings::kCloseParenNewline);
        out_summary.append(line);
    }

    // [EN] Find insertion parent (`0x004a0c..0x004a5c`) and allocate 56-byte node (`0x004a60`).
    // [VN] Tìm nút cha để chèn (`0x004a0c..0x004a5c`) và cấp phát nút 56 byte (`0x004a60`).
    BuildIdRbTreeNode* parent = nullptr;
    BuildIdRbTreeNode** link = &tree->root_node;
    while (*link != nullptr) {
        parent = *link;
        if (CompareStringsLess(full_name, parent->key)) {
            link = &parent->left;
        } else {
            link = &parent->right;
        }
    }

    auto* new_node = new BuildIdRbTreeNode{
        nullptr,
        nullptr,
        parent,
        0u,
        {0, 0, 0, 0, 0, 0, 0},
        full_name
    };
    *link = new_node;

    if (tree->begin_node == nullptr || (parent == tree->begin_node && link == &parent->left)) {
        tree->begin_node = new_node;
    }

    RebalanceAfterInsert(new_node, &tree->root_node);
    tree->node_count += 1u;
}

// ============================================================================
// 8. FormatSingleFrame (`0x004198..0x004798`)
// ============================================================================
// [EN] Exact reconstruction of all 3 formatting branches in `FormatSingleFrame`:
//      - Branch A (`(option & 0xF0000) == 0x20000` @ `0x004270..0x00460c`):
//        Hex PC format `"0x%016lx %s%s%s%s\n"` (`0x002650`):
//        * `map_buf` (`512 B`): `map_info->GetFullName()`, or `"<anonymous:%lx>"`
//          (`map_info->start`), or `"<unknown>"`.
//        * `offset_buf` (`64 B`): `" (offset 0x%zx)"` if `elf_start_offset != 0`.
//        * `func_buf` (`512 B`): `" (%s + %zu)"` if `function_offset != 0`, else `" (%s)"`.
//        * `extra_buf` (`256 B`): `" (BuildId: %s)"` (if `option & 0x08` and build_id non-empty)
//          followed by `" (position at %s)"` (if `dex_position` non-empty).
//      - Branch B (`(option & 0xF0000) == 0x10000` @ `0x0041cc..0x00426c` & `0x004610..0x004798`):
//        Compact format `"    #%02zu %s%s%s\n"` (`0x00276c`):
//        * Extracts basename after last `'/'` (`0x004228..0x00426c`) formatted as `"<%s>"`,
//          or `"<anonymous:%lx>"`, or `"<unknown>"`.
//        * `func_buf` (`512 B`): `" (%s)"` if `!function_name.empty()`, else `"<%lx>"` (`rel_pc`).
//        * `extra_buf` (`128 B`): `"<BuildId:%s>"` (if `option & 0x08`) + `"<%s>"` (if `dex_position`).
//      - Branch C (Default @ `0x0042e4..0x0043dc`):
//        Standard `AndroidUnwinder::FormatFrame(frame, (option >> 3) & 1)` +
//        optional `" (position at " + *dex_position + ")"` + `'\n'`.
// [VN] Tái cấu trúc chính xác cả 3 nhánh định dạng khung ngăn xếp tại `0x004198..0x004798`.
// ============================================================================
void NpthUnwElfTreeAndFormatter::FormatSingleFrame(
    std::string& out_trace,
    const UnwindStackFrameDataAbi& frame,
    const std::string* dex_position,
    uint32_t option) {
    const uint32_t fmt_mode = option & NPTH_UNW_OPT_FMT_MASK;
    const bool include_build_id = ((option & NPTH_UNW_OPT_FRAME_BUILD_ID) != 0u);
    const UnwindStackMapInfoAbi* map_info = frame.map_info.get();
    const std::string& func_name = DereferenceSharedStringOrEmpty(frame.function_name);

    // ------------------------------------------------------------------------
    // Branch A: Hex PC Mode (`(option & 0xF0000) == 0x20000`, `0x004270..0x00460c`)
    // ------------------------------------------------------------------------
    if (fmt_mode == NPTH_UNW_OPT_FMT_HEX_PC) {
        char map_buf[512];
        std::memset(map_buf, 0, sizeof(map_buf));
        if (map_info != nullptr) {
            const std::string& raw_map_name = DereferenceSharedStringOrEmpty(map_info->name);
            if (!raw_map_name.empty()) {
                const std::string full_name = ResolveMapFullName(map_info);
                std::strncpy(map_buf, full_name.c_str(), sizeof(map_buf) - 1);
            } else {
                SafeSnprintf(
                    map_buf,
                    sizeof(map_buf),
                    sizeof(map_buf),
                    NpthUnwRodataStrings::kAnonymousMapFmt,
                    static_cast<unsigned long>(map_info->start));
            }
        } else {
            std::strncpy(map_buf, NpthUnwRodataStrings::kUnknownSymbol, sizeof(map_buf) - 1);
        }

        char offset_buf[64];
        std::memset(offset_buf, 0, sizeof(offset_buf));
        if (map_info != nullptr && map_info->elf_fields.elf_start_offset != 0u) {
            SafeSnprintf(
                offset_buf,
                sizeof(offset_buf),
                sizeof(offset_buf),
                NpthUnwRodataStrings::kElfOffsetFmt,
                static_cast<size_t>(map_info->elf_fields.elf_start_offset));
        }

        char func_buf[512];
        std::memset(func_buf, 0, sizeof(func_buf));
        if (!func_name.empty()) {
            if (frame.function_offset != 0u) {
                SafeSnprintf(
                    func_buf,
                    sizeof(func_buf),
                    sizeof(func_buf),
                    NpthUnwRodataStrings::kFuncPlusOffsetFmt,
                    func_name.c_str(),
                    static_cast<size_t>(frame.function_offset));
            } else {
                SafeSnprintf(
                    func_buf,
                    sizeof(func_buf),
                    sizeof(func_buf),
                    NpthUnwRodataStrings::kParenStringFmt,
                    func_name.c_str());
            }
        }

        char extra_buf[256];
        std::memset(extra_buf, 0, sizeof(extra_buf));
        size_t extra_len = 0u;
        if (include_build_id && map_info != nullptr && !map_info->build_id.empty()) {
            const int n = SafeSnprintf(
                extra_buf,
                sizeof(extra_buf),
                sizeof(extra_buf),
                NpthUnwRodataStrings::kParenBuildIdFmt,
                map_info->build_id.c_str());
            if (n > 0) {
                extra_len = static_cast<size_t>(n);
            }
        }
        if (dex_position != nullptr && !dex_position->empty() && extra_len < sizeof(extra_buf)) {
            SafeSnprintf(
                extra_buf + extra_len,
                sizeof(extra_buf) - extra_len,
                sizeof(extra_buf) - extra_len,
                NpthUnwRodataStrings::kPositionAtFmt,
                dex_position->c_str());
        }

        char line_buf[1024];
        const int line_len = SafeSnprintf(
            line_buf,
            sizeof(line_buf),
            sizeof(line_buf),
            NpthUnwRodataStrings::kHexPcFrameLineFmt,
            static_cast<unsigned long>(frame.rel_pc),
            map_buf,
            offset_buf,
            func_buf,
            extra_buf);
        if (line_len > 0) {
            out_trace.append(line_buf, static_cast<size_t>(line_len));
        }
        return;
    }

    // ------------------------------------------------------------------------
    // Branch B: Compact `<...>` Mode (`(option & 0xF0000) == 0x10000`, `0x0041cc..0x004798`)
    // ------------------------------------------------------------------------
    if (fmt_mode == NPTH_UNW_OPT_FMT_COMPACT) {
        char map_buf[512];
        std::memset(map_buf, 0, sizeof(map_buf));
        if (map_info != nullptr) {
            const std::string& raw_map_name = DereferenceSharedStringOrEmpty(map_info->name);
            if (!raw_map_name.empty()) {
                // [EN] Backward scan for last '/' (`0x004228..0x00426c`).
                // [VN] Quét ngược tìm ký tự '/' cuối cùng (`0x004228..0x00426c`).
                const char* base_ptr = raw_map_name.c_str();
                const size_t len = raw_map_name.size();
                size_t slash_pos = len;
                while (slash_pos > 0) {
                    if (base_ptr[slash_pos - 1] == '/') {
                        break;
                    }
                    --slash_pos;
                }
                const char* short_name = (slash_pos < len) ? (base_ptr + slash_pos) : "";
                SafeSnprintf(
                    map_buf,
                    sizeof(map_buf),
                    sizeof(map_buf),
                    NpthUnwRodataStrings::kAngleStringFmt,
                    short_name);
            } else {
                SafeSnprintf(
                    map_buf,
                    sizeof(map_buf),
                    sizeof(map_buf),
                    NpthUnwRodataStrings::kAnonymousMapFmt,
                    static_cast<unsigned long>(map_info->start));
            }
        } else {
            std::strncpy(map_buf, NpthUnwRodataStrings::kUnknownSymbol, sizeof(map_buf) - 1);
        }

        char func_buf[512];
        std::memset(func_buf, 0, sizeof(func_buf));
        if (!func_name.empty()) {
            SafeSnprintf(
                func_buf,
                sizeof(func_buf),
                sizeof(func_buf),
                NpthUnwRodataStrings::kAngleStringFmt,
                func_name.c_str());
        } else {
            SafeSnprintf(
                func_buf,
                sizeof(func_buf),
                sizeof(func_buf),
                NpthUnwRodataStrings::kHexAngleFmt,
                static_cast<unsigned long>(frame.rel_pc));
        }

        char extra_buf[128];
        std::memset(extra_buf, 0, sizeof(extra_buf));
        size_t extra_len = 0u;
        if (include_build_id && map_info != nullptr && !map_info->build_id.empty()) {
            const int n = SafeSnprintf(
                extra_buf,
                sizeof(extra_buf),
                sizeof(extra_buf),
                NpthUnwRodataStrings::kCompactBuildIdFmt,
                map_info->build_id.c_str());
            if (n > 0) {
                extra_len = static_cast<size_t>(n);
            }
        }
        if (dex_position != nullptr && !dex_position->empty() && extra_len < sizeof(extra_buf)) {
            SafeSnprintf(
                extra_buf + extra_len,
                sizeof(extra_buf) - extra_len,
                sizeof(extra_buf) - extra_len,
                NpthUnwRodataStrings::kAngleStringFmt,
                dex_position->c_str());
        }

        char line_buf[1024];
        const int line_len = SafeSnprintf(
            line_buf,
            sizeof(line_buf),
            sizeof(line_buf),
            NpthUnwRodataStrings::kCompactFrameLineFmt,
            static_cast<size_t>(frame.num),
            map_buf,
            func_buf,
            extra_buf);
        if (line_len > 0) {
            out_trace.append(line_buf, static_cast<size_t>(line_len));
        }
        return;
    }

    // ------------------------------------------------------------------------
    // Branch C: Default `AndroidUnwinder::FormatFrame` (`0x0042e4..0x0043dc`)
    // ------------------------------------------------------------------------
    char default_buf[1024];
    const std::string map_name = (map_info != nullptr && map_info->name) ? *(map_info->name) : "<unknown>";
    if (!func_name.empty()) {
        if (frame.function_offset != 0u) {
            SafeSnprintf(
                default_buf,
                sizeof(default_buf),
                sizeof(default_buf),
                "    #%02zu pc %016lx  %s (%s+%zu)",
                static_cast<size_t>(frame.num),
                static_cast<unsigned long>(frame.rel_pc),
                map_name.c_str(),
                func_name.c_str(),
                static_cast<size_t>(frame.function_offset));
        } else {
            SafeSnprintf(
                default_buf,
                sizeof(default_buf),
                sizeof(default_buf),
                "    #%02zu pc %016lx  %s (%s)",
                static_cast<size_t>(frame.num),
                static_cast<unsigned long>(frame.rel_pc),
                map_name.c_str(),
                func_name.c_str());
        }
    } else {
        SafeSnprintf(
            default_buf,
            sizeof(default_buf),
            sizeof(default_buf),
            "    #%02zu pc %016lx  %s",
            static_cast<size_t>(frame.num),
            static_cast<unsigned long>(frame.rel_pc),
            map_name.c_str());
    }
    out_trace.append(default_buf);
    if (include_build_id && map_info != nullptr && !map_info->build_id.empty()) {
        out_trace.append(" (BuildId: ");
        out_trace.append(map_info->build_id);
        out_trace.push_back(')');
    }
    if (dex_position != nullptr && !dex_position->empty()) {
        std::string pos_str = std::string(NpthUnwRodataStrings::kPositionAtPrefix) + *dex_position;
        pos_str.push_back(')');
        out_trace.append(pos_str);
    }
    out_trace.push_back('\n');
}

} // namespace NpthUnw
} // namespace OpenCut
} // namespace NextAI
