/**
 * @file npth_dumper_tombstone.h
 * @brief Out-of-process Tombstone, smaps, threads, reg_memory, and native.summary generator.
 *        Bộ tạo Tombstone ngoài tiến trình, smaps, threads, reg_memory và native.summary.
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (`0x008a00..0x00d54c`).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (`0x008a00..0x00d54c`).
 */

#ifndef OPENCUT_NPTH_DUMPER_TOMBSTONE_H_
#define OPENCUT_NPTH_DUMPER_TOMBSTONE_H_

#include "npth_dumper_ptrace_unwinder.h"
#include "npth_dumper_types.h"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace npth {
namespace dumper {

/**
 * @brief Tombstone, register memory, stack, build-id, and crash summary writer (`0x009260..0x00d54c`).
 *        Bộ ghi Tombstone, bộ nhớ quanh thanh ghi, ngăn xếp, build-id và tóm tắt lỗi (`0x009260..0x00d54c`).
 */
class TombstoneGenerator {
public:
    /**
     * @brief Write all bytes to `DumperFileWriter` retrying on `EINTR` (`0x00e25c..0x00e2ec`).
     *        Ghi toàn bộ byte vào `DumperFileWriter` và thử lại khi gặp `EINTR` (`0x00e25c..0x00e2ec`).
     */
    static void WriteRaw(DumperFileWriter* writer, const void* data, size_t len) noexcept;

    /**
     * @brief Formatted printf into `DumperFileWriter` with `1024`-byte stack buffer and heap fallback (`0x00b5ac..0x00b6f0`).
     *        Ghi định dạng printf vào `DumperFileWriter` với bộ đệm ngăn xếp `1024` byte và dự phòng heap (`0x00b5ac..0x00b6f0`).
     */
    static void WriteFormatted(DumperFileWriter* writer, const char* fmt, ...);

    /**
     * @brief Dump AArch64 registers (`x0..x29, sp, lr, pc, pst`) for a thread (`0x00b778..0x00b808`).
     *        Kết xuất các thanh ghi AArch64 (`x0..x29, sp, lr, pc, pst`) cho một luồng (`0x00b778..0x00b808`).
     */
    static void DumpThreadRegisters(DumperFileWriter* writer, const AArch64UContext* uctx);

    /**
     * @brief Dump `backtrace:\n` frames (`#00 pc ...`) (`0x00b970..0x00bcec`).
     *        Kết xuất các khung `backtrace:\n` (`#00 pc ...`) (`0x00b970..0x00bcec`).
     */
    static void DumpBacktraceFrames(DumperFileWriter* writer,
                                    const std::vector<UnwoundFrameInfo>& frames);

    /**
     * @brief Dump `build id:\n` deduplicated ELF build IDs (`0x00bcf0..0x00be00`, `0x00cbac..0x00cf54`).
     *        Kết xuất danh sách `build id:\n` đã khử trùng lặp (`0x00bcf0..0x00be00`, `0x00cbac..0x00cf54`).
     */
    static void DumpBuildIds(DumperFileWriter* writer,
                             const std::vector<UnwoundFrameInfo>& frames);

    /**
     * @brief Dump modified general-purpose (`x0..x29`) and SIMD (`v0..v31`) registers per frame (`0x00be04..0x00c098`).
     *        Kết xuất các thanh ghi đa dụng (`x0..x29`) và SIMD (`v0..v31`) thay đổi theo từng khung (`0x00be04..0x00c098`).
     */
    static void DumpFrameRegisterDiffs(DumperFileWriter* writer,
                                       size_t frame_index,
                                       const AArch64UContext* prev_regs,
                                       const AArch64UContext* curr_regs,
                                       const char* map_soname);

    /**
     * @brief Dump `stack:\n` words with symbol resolution (`#00 sp..sp+N` or `16` words) (`0x00c09c..0x00c40c`).
     *        Kết xuất các từ `stack:\n` kèm phân giải ký hiệu (`#00 sp..sp+N` hoặc `16` từ) (`0x00c09c..0x00c40c`).
     */
    static void DumpStackSegment(DumperFileWriter* writer,
                                 int32_t pid,
                                 uint64_t* io_sp,
                                 size_t word_count,
                                 int32_t frame_num,
                                 uint64_t* io_non_null_stack_frames);

    /**
     * @brief Dump `memory near xN` / `code around pc/lr` (`16` lines x `16` bytes) (`0x00c410..0x00c980`).
     *        Kết xuất `memory near xN` / `code around pc/lr` (`16` dòng x `16` byte) (`0x00c410..0x00c980`).
     */
    static void DumpMemoryAroundRegister(DumperFileWriter* writer,
                                         int32_t pid,
                                         const char* reg_name,
                                         uint64_t reg_val,
                                         uint64_t frame_num,
                                         uint64_t max_bytes,
                                         const char* map_name);

    /**
     * @brief Generate `tombstone.txt`, `reg_memory.txt`, `smaps.txt`, `threads.txt`, and `native.summary` (`0x009260..0x00ab70`).
     *        Tạo `tombstone.txt`, `reg_memory.txt`, `smaps.txt`, `threads.txt` và `native.summary` (`0x009260..0x00ab70`).
     */
    static int GenerateFullTombstoneAndSummary(const ParsedCrashContext& ctx,
                                               const std::vector<AttachedThread>& attached_threads,
                                               const std::vector<UnwoundFrameInfo>& main_frames);
};

} // namespace dumper
} // namespace npth

#endif // OPENCUT_NPTH_DUMPER_TOMBSTONE_H_
