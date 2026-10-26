// ============================================================================
// FILE: npth_unw_elf_tree.h
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64)
// ROLE: Red-Black Tree for ELF BuildId Deduplication & 3-Mode Frame Formatter
//       Cây Đỏ-Đen khử trùng lặp ELF BuildId & Bộ định dạng khung ngăn xếp 3 chế độ
// ============================================================================
// [EN] Reconstructs the internal helper routines in `.text`:
//      - `0x003d4c` (`DestroyStringVectorRange` — `std::vector<std::string>::__destruct_at_end`)
//      - `0x003d98` (`ConstructSsoStringFromCString` — `std::string::basic_string(const char*)`)
//      - `0x004198` (`FormatSingleFrame` — 3-mode frame line formatter: Default,
//                    Compact `<...>` `0x10000`, and Hex PC `0x%016lx` `0x20000`)
//      - `0x0047a0` (`DestroyBuildIdRbTree` — `std::__tree<std::string>::destroy`)
//      - `0x0047dc` (`InsertAndFormatBuildIdSummary` — filters `.vdex`/`.jar`, queries
//                    `MapInfo::GetFullName()` & `MapInfo::GetPrintableBuildID()`, and
//                    inserts into the 56-byte Red-Black Tree with left/right rotations)
//      - `0x004c7c` (`DereferenceSharedStringOrEmpty` — returns `shared_ptr<string>` or
//                    lazy-initialized `g_empty_string_fallback` at `.bss 0x00eac8`)
//      - `0x004cf8` (`CompareStringSuffix` — `memcmp` suffix check for `.vdex` and `.jar`)
//      - `0x004d40` (`CompareSsoStringsLess` — `std::less<std::string>` comparator)
//      - `0x004db4` (`SafeSnprintfFormatter` — `__vsnprintf_chk` variadic wrapper)
// [VN] Phục dựng các hàm bổ trợ nội bộ trong `.text` (từ `0x003d4c` đến `0x004e24`).
// ============================================================================

#pragma once

#include "npth_unw_types.h"
#include <cstdarg>
#include <string>
#include <vector>

namespace NextAI {
namespace OpenCut {
namespace NpthUnw {

class NpthUnwElfTreeAndFormatter {
public:
    // ------------------------------------------------------------------------
    // [EN] `0x004db4..0x004e24`: Variadic `__vsnprintf_chk` wrapper used across
    //      `FormatSingleFrame`, `InsertAndFormatBuildIdSummary`, and `UnwindEntireProcess`.
    // [VN] `0x004db4..0x004e24`: Hàm bọc định dạng chuỗi an toàn `__vsnprintf_chk`.
    // ------------------------------------------------------------------------
    static int SafeSnprintf(char* buffer, size_t buf_size, size_t chk_size, const char* fmt, ...);

    // ------------------------------------------------------------------------
    // [EN] `0x004c7c..0x004cf4`: Dereferences a `std::shared_ptr<std::string>`
    //      (`MapInfo::name` or `FrameData::function_name`), returning a reference
    //      to the global empty string at `.bss 0x00eac8` (guarded by `0x00eae0`)
    //      when the `shared_ptr` is null.
    // [VN] `0x004c7c..0x004cf4`: Giải tham chiếu `std::shared_ptr<std::string>`,
    //      trả về chuỗi rỗng toàn cục tại `.bss 0x00eac8` nếu con trỏ rỗng.
    // ------------------------------------------------------------------------
    static const std::string& DereferenceSharedStringOrEmpty(const std::shared_ptr<std::string>& ptr);

    // ------------------------------------------------------------------------
    // [EN] `0x004cf8..0x004d3c`: Compares `(str_data + str_len - suffix_len)`
    //      with `suffix` (`".vdex"` len 5 or `".jar"` len 4) via `memcmp` (`0x0064f0`).
    //      Returns 0 when equal, negative when `<`, positive when `>`.
    // [VN] `0x004cf8..0x004d3c`: So sánh hậu tố chuỗi (`".vdex"` hoặc `".jar"`)
    //      thông qua `memcmp` (`0x0064f0`).
    // ------------------------------------------------------------------------
    static int CompareByteSlice(const char* lhs, size_t lhs_len, const char* rhs, size_t rhs_len);

    // ------------------------------------------------------------------------
    // [EN] `0x004d40..0x004db0`: Lexicographical `operator<` on two `std::string`
    //      instances (`memcmp(a.data(), b.data(), min(a.size(), b.size()))`,
    //      breaking ties by `a.size() < b.size()` and extracting sign bit `lsr w0, w0, #31`).
    // [VN] `0x004d40..0x004db0`: Phép so sánh từ điển `a < b` giữa hai chuỗi `std::string`.
    // ------------------------------------------------------------------------
    static bool CompareStringsLess(const std::string& lhs, const std::string& rhs);

    // ------------------------------------------------------------------------
    // [EN] `0x0047a0..0x0047d8`: Post-order recursive destruction of the 56-byte
    //      Red-Black Tree nodes (`DestroyBuildIdRbTree(node->left)`,
    //      `DestroyBuildIdRbTree(node->right)`, free string heap buffer if long,
    //      and `operator delete(node)`).
    // [VN] `0x0047a0..0x0047d8`: Hủy đệ quy hậu thứ tự toàn bộ nút Cây Đỏ-Đen 56 byte.
    // ------------------------------------------------------------------------
    static void DestroyBuildIdRbTree(BuildIdRbTreeNode* node);

    // ------------------------------------------------------------------------
    // [EN] `0x0047dc..0x004c78`: Inspects `map_info`, filters out empty names,
    //      non-absolute paths (`name[0] != '/'`), and `.vdex` / `.jar` files,
    //      looks up `full_name = map_info->GetFullName()` in `tree`, and if not
    //      already present:
    //      1. Calls `build_id = map_info->GetPrintableBuildID()`.
    //      2. If `!build_id.empty()`, appends `"    " + full_name + " (BuildId: " + build_id + ")\n"`
    //         to `out_summary`.
    //      3. Allocates a `56-byte` (`0x38`) `BuildIdRbTreeNode`, inserts `full_name`,
    //         and rebalances the Red-Black Tree (`0x004ab4..0x004c38`).
    // [VN] `0x0047dc..0x004c78`: Kiểm tra `map_info`, lọc bỏ `.vdex`/`.jar`,
    //      ghi dòng `"    <full_name> (BuildId: <id>)\n"` vào `out_summary`, và
    //      chèn khóa vào Cây Đỏ-Đen kèm cân bằng xoay trái/phải.
    // ------------------------------------------------------------------------
    static void InsertAndFormatBuildIdSummary(
        std::string& out_summary,
        const UnwindStackMapInfoAbi* map_info,
        BuildIdRbTreeHeader* tree);

    // ------------------------------------------------------------------------
    // [EN] `0x004198..0x004798`: Formats a single `UnwindStackFrameDataAbi` into
    //      `out_trace` according to `option`:
    //      - Mode `0x20000` (`(option & 0xF0000) == 0x20000` @ `0x004270..0x00460c`):
    //        Hex PC format `"0x%016lx %s%s%s%s\n"`
    //      - Mode `0x10000` (`(option & 0xF0000) == 0x10000` @ `0x0041cc..0x00426c` & `0x004610..0x004798`):
    //        Compact angle-bracket format `"    #%02zu %s%s%s\n"`
    //      - Default Mode (`0x0042e4..0x0043dc`):
    //        Standard `AndroidUnwinder::FormatFrame(frame, (option >> 3) & 1)` +
    //        optional `" (position at " + dex_pos + ")"` + `'\n'`.
    // [VN] `0x004198..0x004798`: Định dạng một khung ngăn xếp `FrameData` vào
    //      chuỗi kết quả `out_trace` theo 3 chế độ trong `option`.
    // ------------------------------------------------------------------------
    static void FormatSingleFrame(
        std::string& out_trace,
        const UnwindStackFrameDataAbi& frame,
        const std::string* dex_position,
        uint32_t option);

    // ------------------------------------------------------------------------
    // [EN] Mathematical helper verifying the exact unsigned/signed division by
    //      constants used in `libnpth_unw.so`:
    //      1. Division by 80 (`sizeof(FrameData) = 0x50`) @ `0x003898..0x0038a4` & `0x004104..0x00410c`:
    //         `count = ((bytes_diff >> 4) * 0xcccccccccccccccdULL)`
    //      2. Division by 24 (`sizeof(std::string) = 0x18`) @ `0x00395c..0x003968`:
    //         `count = ((bytes_diff >> 3) * 0xaaaaaaaaaaaaaaabULL)`
    // [VN] Hàm toán học kiểm chứng phép chia cho hằng số 80 (`FrameData`) và
    //      24 (`std::string`) bằng phép nhân nghịch đảo modulo $2^{64}$.
    // ------------------------------------------------------------------------
    static constexpr size_t DivideByteDiffBy80(ptrdiff_t byte_diff) noexcept {
        // [EN] Exact AArch64 sequence at 0x003898..0x0038a4:
        //      asr x8, x8, #4
        //      mov x9, #-0x3333333333333333 (0xcccccccccccccccdULL)
        //      mul x20, x8, x9
        // [VN] Dãy lệnh AArch64 chính xác tại 0x003898..0x0038a4.
        const uint64_t shifted = static_cast<uint64_t>(byte_diff >> 4);
        return static_cast<size_t>(shifted * 0xCCCCCCCCCCCCCCCDULL);
    }

    static constexpr size_t DivideByteDiffBy24(ptrdiff_t byte_diff) noexcept {
        // [EN] Exact AArch64 sequence at 0x00395c..0x003968:
        //      asr x10, x9, #3
        //      mov x9, #-0x5555555555555555 (0xaaaaaaaaaaaaaaabULL)
        //      mul x10, x10, x9
        // [VN] Dãy lệnh AArch64 chính xác tại 0x00395c..0x003968.
        const uint64_t shifted = static_cast<uint64_t>(byte_diff >> 3);
        return static_cast<size_t>(shifted * 0xAAAAAAAAAAAAAAABULL);
    }

private:
    static void RebalanceAfterInsert(BuildIdRbTreeNode* x, BuildIdRbTreeNode** root_slot);
    static void RotateLeft(BuildIdRbTreeNode* x, BuildIdRbTreeNode** root_slot);
    static void RotateRight(BuildIdRbTreeNode* x, BuildIdRbTreeNode** root_slot);
};

} // namespace NpthUnw
} // namespace OpenCut
} // namespace NextAI
