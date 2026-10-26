/**
 * @file npth_dumper_tombstone.cpp
 * @brief Implementation of Tombstone, register/stack memory, build-id, and crash summary generation.
 *        Triển khai tạo Tombstone, bộ nhớ thanh ghi/ngăn xếp, build-id và tóm tắt lỗi.
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (`0x008a00..0x00d54c`, `0x00e25c..0x00e2ec`).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (`0x008a00..0x00d54c`, `0x00e25c..0x00e2ec`).
 */

#include "npth_dumper_tombstone.h"
#include "npth_dumper_minidump_protector.h"

#include <cinttypes>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(__linux__)
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <unistd.h>
#endif

namespace npth {
namespace dumper {

namespace {

/**
 * @brief Register names from `.data.rel.ro` `0x018a90..0x018c5f` (`0x009eb4: adr x8, #0x18a90`, `0x00beec`, `0x00bfbc`).
 *        Tên các thanh ghi từ `.data.rel.ro` `0x018a90..0x018c5f`.
 */
static const char* const kGprNames[34] = {
    "x0",  "x1",  "x2",  "x3",  "x4",  "x5",  "x6",  "x7",
    "x8",  "x9",  "x10", "x11", "x12", "x13", "x14", "x15",
    "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23",
    "x24", "x25", "x26", "x27", "x28", "x29", "lr",  "sp",
    "pc",  "pst"
};

static const char* const kSimdLowNames[8] = {
    "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15"
};

/**
 * @brief Fault type suffix classification table at `.data.rel.ro` `0x018c60..0x018caf` (`0x00a830`).
 *        Bảng phân loại hậu tố loại lỗi tại `.data.rel.ro` `0x018c60..0x018caf`.
 */
struct SuffixRule {
    const char* suffix;
    size_t      len;
};

static const SuffixRule kMapTypeSuffixes[5] = {
    { ".dex",  4U }, // 0x005bfc (skip leading '/')
    { ".odex", 5U }, // 0x005bfb (skip leading '/')
    { ".vdex", 5U }, // 0x004ec5
    { ".oat",  4U }, // 0x005f7f
    { ".art",  4U }  // 0x0052d9
};

} // namespace

/**
 * @brief Write all bytes to `DumperFileWriter` retrying on `EINTR` (`0x00e25c..0x00e2ec`).
 *        Ghi toàn bộ byte vào `DumperFileWriter` và thử lại khi gặp `EINTR` (`0x00e25c..0x00e2ec`).
 *
 * Disassembly:
 *   - `0x00e26c`: `ldrb w8, [x0, #4]; cbnz w8, #0xe2e0` (aborts if `error_code != 0`)
 *   - `0x00e2d4`: Logs `"[dumper] failed to write file %d"` (`0x005f16`) and sets `error_code = 6` (`mov w8, #6; strb w8, [x19, #4]` @ `0x00e2d8..0x00e2dc`).
 */
void TombstoneGenerator::WriteRaw(DumperFileWriter* writer, const void* data, size_t len) noexcept {
    if (writer == nullptr || writer->error_code != 0 || data == nullptr || len == 0U) {
        return;
    }
#if defined(__linux__)
    const uint8_t* ptr = static_cast<const uint8_t*>(data);
    size_t rem = len;
    while (rem > 0U) {
        ssize_t n = write(writer->fd, ptr, rem);
        if (n < 0) {
            if (errno == EINTR) {
                continue;
            }
            PtraceUnwinderEngine::LogMessage(4, "[dumper] failed to write file %d", writer->fd);
            writer->error_code = 6U;
            return;
        }
        ptr += static_cast<size_t>(n);
        rem -= static_cast<size_t>(n);
    }
#else
    (void)writer;
    (void)data;
    (void)len;
#endif
}

/**
 * @brief Formatted printf into `DumperFileWriter` (`0x00b5ac..0x00b6f0`).
 *        Ghi định dạng printf vào `DumperFileWriter` (`0x00b5ac..0x00b6f0`).
 *
 * Uses a `1024`-byte (`0x400`) stack buffer; if `vsnprintf` returns `> 0x3ff` (`1023`),
 * allocates `ret + 1` bytes via `malloc` (`0x00b678`), formats again, writes via `WriteRaw`,
 * and frees via `free` (`0x00b6c0`).
 */
void TombstoneGenerator::WriteFormatted(DumperFileWriter* writer, const char* fmt, ...) {
    if (writer == nullptr || writer->error_code != 0 || fmt == nullptr) {
        return;
    }
    char stack_buf[1024];
    va_list args;
    va_start(args, fmt);
    va_list args_copy;
    va_copy(args_copy, args);
    int n = std::vsnprintf(stack_buf, sizeof(stack_buf), fmt, args);
    va_end(args);

    if (n > 1023) {
        size_t alloc_sz = static_cast<size_t>(n) + 1U;
        char* heap_buf = static_cast<char*>(std::malloc(alloc_sz));
        if (heap_buf != nullptr) {
            int n2 = std::vsnprintf(heap_buf, alloc_sz, fmt, args_copy);
            if (n2 >= 1 && n2 <= n) {
                WriteRaw(writer, heap_buf, static_cast<size_t>(n2));
            }
            std::free(heap_buf);
        }
    } else if (n >= 1) {
        WriteRaw(writer, stack_buf, static_cast<size_t>(n));
    }
    va_end(args_copy);
}

/**
 * @brief Dump AArch64 registers (`x0..x29, sp, lr, pc, pst`) (`0x00b778..0x00b808`).
 *        Kết xuất các thanh ghi AArch64 (`x0..x29, sp, lr, pc, pst`) (`0x00b778..0x00b808`).
 *
 * Format string at `.rodata` `0x00570f` (`0x00b7a0..0x00b7a4`).
 */
void TombstoneGenerator::DumpThreadRegisters(DumperFileWriter* writer, const AArch64UContext* uctx) {
    if (writer == nullptr || uctx == nullptr) {
        return;
    }
    WriteFormatted(writer,
        "    x0  %016" PRIx64 "  x1  %016" PRIx64 "  x2  %016" PRIx64 "  x3  %016" PRIx64 "\n"
        "    x4  %016" PRIx64 "  x5  %016" PRIx64 "  x6  %016" PRIx64 "  x7  %016" PRIx64 "\n"
        "    x8  %016" PRIx64 "  x9  %016" PRIx64 "  x10 %016" PRIx64 "  x11 %016" PRIx64 "\n"
        "    x12 %016" PRIx64 "  x13 %016" PRIx64 "  x14 %016" PRIx64 "  x15 %016" PRIx64 "\n"
        "    x16 %016" PRIx64 "  x17 %016" PRIx64 "  x18 %016" PRIx64 "  x19 %016" PRIx64 "\n"
        "    x20 %016" PRIx64 "  x21 %016" PRIx64 "  x22 %016" PRIx64 "  x23 %016" PRIx64 "\n"
        "    x24 %016" PRIx64 "  x25 %016" PRIx64 "  x26 %016" PRIx64 "  x27 %016" PRIx64 "\n"
        "    x28 %016" PRIx64 "  x29 %016" PRIx64 "\n"
        "    sp  %016" PRIx64 "  lr  %016" PRIx64 "  pc  %016" PRIx64 "  pst %016" PRIx64 "\n\n",
        uctx->regs[0],  uctx->regs[1],  uctx->regs[2],  uctx->regs[3],
        uctx->regs[4],  uctx->regs[5],  uctx->regs[6],  uctx->regs[7],
        uctx->regs[8],  uctx->regs[9],  uctx->regs[10], uctx->regs[11],
        uctx->regs[12], uctx->regs[13], uctx->regs[14], uctx->regs[15],
        uctx->regs[16], uctx->regs[17], uctx->regs[18], uctx->regs[19],
        uctx->regs[20], uctx->regs[21], uctx->regs[22], uctx->regs[23],
        uctx->regs[24], uctx->regs[25], uctx->regs[26], uctx->regs[27],
        uctx->regs[28], uctx->regs[29],
        uctx->sp,       uctx->regs[30], uctx->pc,       uctx->pstate);
}

/**
 * @brief Dump `backtrace:\n` frames (`0x00b970..0x00bcec`).
 *        Kết xuất các khung `backtrace:\n` (`0x00b970..0x00bcec`).
 *
 * Format string at `.rodata` `0x00532e`: `"    #%02zu pc %016llx  %s%s%s%s\n"`.
 */
void TombstoneGenerator::DumpBacktraceFrames(DumperFileWriter* writer,
                                             const std::vector<UnwoundFrameInfo>& frames) {
    if (writer == nullptr) {
        return;
    }
    WriteRaw(writer, "backtrace:\n", 11U);
    for (const auto& f : frames) {
        char map_desc[512] = {0};
        if (!f.map_name.empty()) {
            std::snprintf(map_desc, sizeof(map_desc), "%s", f.map_name.c_str());
        } else if (f.map_start != 0ULL) {
            std::snprintf(map_desc, sizeof(map_desc), "<anonymous:%016" PRIx64 ">", f.map_start);
        } else {
            std::snprintf(map_desc, sizeof(map_desc), "<unknown>");
        }

        char offset_desc[64] = {0};
        if (f.elf_start_offset != 0ULL) {
            std::snprintf(offset_desc, sizeof(offset_desc), " (offset 0x%" PRIx64 ")", f.elf_start_offset);
        }

        char func_desc[512] = {0};
        if (!f.function_name.empty()) {
            if (f.function_offset != 0ULL) {
                std::snprintf(func_desc, sizeof(func_desc), " (%s+%" PRIu64 ")",
                              f.function_name.c_str(), f.function_offset);
            } else {
                std::snprintf(func_desc, sizeof(func_desc), " (%s)", f.function_name.c_str());
            }
        }

        char extra_desc[256] = {0};
        if (f.dex_Warning == 2U) {
            std::snprintf(extra_desc, sizeof(extra_desc), " (DEX_PC, INTERPRETER)");
        } else if (f.dex_Warning == 3U) {
            std::snprintf(extra_desc, sizeof(extra_desc), " (DEX_PC, JIT_CACHE, NOT_EXECUTABLE)");
        }

        WriteFormatted(writer, "    #%02zu pc %016" PRIx64 "  %s%s%s%s\n",
                       static_cast<size_t>(f.num),
                       f.rel_pc,
                       map_desc,
                       offset_desc,
                       func_desc,
                       extra_desc);
    }
    WriteRaw(writer, "\n", 1U);
}

/**
 * @brief Dump `build id:\n` deduplicated ELF build IDs (`0x00bcf0..0x00be00`, `0x00cbac..0x00cf54`).
 *        Kết xuất danh sách `build id:\n` đã khử trùng lặp (`0x00bcf0..0x00be00`, `0x00cbac..0x00cf54`).
 */
void TombstoneGenerator::DumpBuildIds(DumperFileWriter* writer,
                                      const std::vector<UnwoundFrameInfo>& frames) {
    if (writer == nullptr) {
        return;
    }
    WriteRaw(writer, "build id:\n", 10U);
    std::vector<std::string> seen_maps;
    for (const auto& f : frames) {
        if (f.map_name.empty() || f.map_name[0] != '/') {
            continue;
        }
        if (f.map_name.size() >= 5U && f.map_name.compare(f.map_name.size() - 5U, 5U, ".odex") == 0) {
            continue;
        }
        if (f.map_name.size() >= 4U && f.map_name.compare(f.map_name.size() - 4U, 4U, ".oat") == 0) {
            continue;
        }
        bool duplicate = false;
        for (const auto& s : seen_maps) {
            if (s == f.map_name) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            continue;
        }
        seen_maps.push_back(f.map_name);
        WriteFormatted(writer, "    %s (BuildId: unknown)\n", f.map_name.c_str());
    }
    WriteRaw(writer, "\n", 1U);
}

/**
 * @brief Dump modified general-purpose (`x0..x29`) and SIMD (`d8..d15`) registers per frame (`0x00be04..0x00c098`).
 *        Kết xuất các thanh ghi đa dụng (`x0..x29`) và SIMD (`d8..d15`) thay đổi theo từng khung (`0x00be04..0x00c098`).
 */
void TombstoneGenerator::DumpFrameRegisterDiffs(DumperFileWriter* writer,
                                                size_t frame_index,
                                                const AArch64UContext* prev_regs,
                                                const AArch64UContext* curr_regs,
                                                const char* map_soname) {
    if (writer == nullptr || curr_regs == nullptr) {
        return;
    }
    if (map_soname != nullptr && map_soname[0] != '\0') {
        WriteFormatted(writer, "    #%02zu (%s)\n", frame_index, map_soname);
        frame_index += 1U;
    }
    char line[512] = {0};
    int prefix_len = std::snprintf(line, sizeof(line), "    #%02zu ", frame_index);
    if (prefix_len < 0) {
        prefix_len = 0;
    }
    int cur_pos = prefix_len;
    int col_count = 0;

    // Compare `x19..x29` (`0x98..0xe8` offset in `unwindstack::Registers`, `0x00bee8..0x00bf80`)
    for (int r = 19; r <= 29; ++r) {
        if (r == 30) {
            continue;
        }
        uint64_t val = curr_regs->regs[r];
        if (prev_regs != nullptr && prev_regs->regs[r] == val) {
            continue;
        }
        int added = std::snprintf(line + cur_pos, sizeof(line) - static_cast<size_t>(cur_pos),
                                  "%s=%016" PRIx64 " ", kGprNames[r], val);
        if (added > 0) {
            cur_pos += added;
        }
        ++col_count;
        if ((col_count & 3) == 0) {
            line[cur_pos++] = '\n';
            WriteRaw(writer, line, static_cast<size_t>(cur_pos));
            std::memset(line, ' ', static_cast<size_t>(prefix_len));
            cur_pos = prefix_len;
        }
    }

    // Compare callee-saved SIMD registers `d8..d15` (`0x00bfbc..0x00c03c`)
    for (int d = 0; d < 8; ++d) {
        uint64_t val = curr_regs->vregs[(8 + d) * 2];
        if (prev_regs != nullptr && prev_regs->vregs[(8 + d) * 2] == val) {
            continue;
        }
        int added = std::snprintf(line + cur_pos, sizeof(line) - static_cast<size_t>(cur_pos),
                                  "%s=%016" PRIx64 " ", kSimdLowNames[d], val);
        if (added > 0) {
            cur_pos += added;
        }
        ++col_count;
        if ((col_count & 3) == 0) {
            line[cur_pos++] = '\n';
            WriteRaw(writer, line, static_cast<size_t>(cur_pos));
            std::memset(line, ' ', static_cast<size_t>(prefix_len));
            cur_pos = prefix_len;
        }
    }

    if (cur_pos > prefix_len) {
        line[cur_pos++] = '\n';
        WriteRaw(writer, line, static_cast<size_t>(cur_pos));
    }
}

/**
 * @brief Dump `stack:\n` words with symbol resolution (`0x00c09c..0x00c40c`).
 *        Kết xuất các từ `stack:\n` kèm phân giải ký hiệu (`0x00c09c..0x00c40c`).
 */
void TombstoneGenerator::DumpStackSegment(DumperFileWriter* writer,
                                          int32_t pid,
                                          uint64_t* io_sp,
                                          size_t word_count,
                                          int32_t frame_num,
                                          uint64_t* io_non_null_stack_frames) {
    if (writer == nullptr || io_sp == nullptr || word_count == 0U) {
        return;
    }
    for (size_t i = 0; i < word_count; ++i) {
        uint64_t val = 0ULL;
        if (PtraceUnwinderEngine::PtracePeekWord(pid, *io_sp, &val) != 0) {
            break;
        }
        char line[512] = {0};
        int pos = 0;
        if (frame_num >= 0 && i == 0U) {
            if (io_non_null_stack_frames != nullptr) {
                *io_non_null_stack_frames += 1ULL;
            }
            pos = std::snprintf(line, sizeof(line), "    #%02d ", frame_num);
        } else {
            pos = std::snprintf(line, sizeof(line), "        ");
        }
        pos += std::snprintf(line + pos, sizeof(line) - static_cast<size_t>(pos),
                             "%016" PRIx64 "  %016" PRIx64 "\n", *io_sp, val);
        WriteRaw(writer, line, static_cast<size_t>(pos));
        *io_sp += 8ULL;
    }
}

/**
 * @brief Dump `memory near xN` / `code around pc/lr` (`16` lines x `16` bytes) (`0x00c410..0x00c980`).
 *        Kết xuất `memory near xN` / `code around pc/lr` (`16` dòng x `16` byte) (`0x00c410..0x00c980`).
 *
 * Disassembly highlights:
 *   - Checks if `reg_name` is `"pc"`, `"lr"`, or `"dex"` (`0x00c478..0x00c4d8`):
 *     if so, prints `"code around %s"` (`0x00c578..0x00c61c`) from `aligned_addr - 0xe0` (`-0x20 - 0xc0`)
 *     without ASCII column; otherwise prints `"memory near %s (%s):"` with 16-char ASCII column (`'.'` = `0x2e`
 *     for bytes outside `0x20..0x7e`, `0x00c80c..0x00c828`, or `"................"` = `0x2e2e2e2e2e2e2e2e`
 *     for unreadable 8-byte words @ `0x00c87c..0x00c894`).
 */
void TombstoneGenerator::DumpMemoryAroundRegister(DumperFileWriter* writer,
                                                  int32_t pid,
                                                  const char* reg_name,
                                                  uint64_t reg_val,
                                                  uint64_t frame_num,
                                                  uint64_t max_bytes,
                                                  const char* map_name) {
    if (writer == nullptr || reg_name == nullptr) {
        return;
    }
    bool is_code = (std::strcmp(reg_name, "pc") == 0 ||
                    std::strcmp(reg_name, "lr") == 0 ||
                    std::strcmp(reg_name, "dex") == 0);

    uint64_t aligned = reg_val & ~7ULL;
    uint64_t base_addr = ( (reg_val >> 5) > 0x80ULL ) ? (aligned - 0x20ULL) : aligned;
    // Reject kernel addresses (`0x00c4f0..0x00c504`)
    if (base_addr < 0x1000ULL) {
        return;
    }

    char frame_tag[32] = {0};
    char range_tag[32] = {0};
    if (frame_num != 0ULL) {
        std::snprintf(frame_tag, sizeof(frame_tag), "#%02" PRIu64 " ", frame_num);
        if (is_code && max_bytes > 0ULL) {
            std::snprintf(range_tag, sizeof(range_tag), " (%" PRIu64 " bytes)", max_bytes);
        }
    }

    if (is_code) {
        base_addr -= 0xc0ULL;
        if (map_name != nullptr && map_name[0] != '\0') {
            WriteFormatted(writer, "code around %s %s(%s)%s:\n",
                           reg_name, frame_tag, map_name, range_tag);
        } else {
            WriteFormatted(writer, "code around %s %s%s:\n",
                           reg_name, frame_tag, range_tag);
        }
    } else {
        if (map_name != nullptr && map_name[0] != '\0') {
            WriteFormatted(writer, "memory near %s %s(%s):\n",
                           reg_name, frame_tag, map_name);
        } else {
            WriteFormatted(writer, "memory near %s %s:\n",
                           reg_name, frame_tag);
        }
    }

    for (size_t row = 0; row < 16U; ++row) {
        uint64_t row_addr = base_addr + row * 16ULL;
        char hex_part[128] = {0};
        char ascii_part[32] = {0};
        int hex_pos = std::snprintf(hex_part, sizeof(hex_part), "    %016" PRIx64, row_addr);
        size_t ascii_pos = 0U;

        for (size_t w = 0; w < 2U; ++w) {
            uint64_t word = 0ULL;
            if (PtraceUnwinderEngine::PtracePeekWord(pid, row_addr + w * 8ULL, &word) == 0) {
                hex_pos += std::snprintf(hex_part + hex_pos,
                                         sizeof(hex_part) - static_cast<size_t>(hex_pos),
                                         " %016" PRIx64, word);
                const uint8_t* b = reinterpret_cast<const uint8_t*>(&word);
                for (size_t k = 0; k < 8U; ++k) {
                    uint8_t ch = b[k];
                    ascii_part[ascii_pos++] = (ch >= 0x20U && ch <= 0x7eU) ? static_cast<char>(ch) : '.';
                }
            } else {
                hex_pos += std::snprintf(hex_part + hex_pos,
                                         sizeof(hex_part) - static_cast<size_t>(hex_pos),
                                         " ----------------");
                std::memcpy(ascii_part + ascii_pos, "........", 8U);
                ascii_pos += 8U;
            }
        }
        ascii_part[ascii_pos] = '\0';
        if (is_code) {
            WriteFormatted(writer, "%s\n", hex_part);
        } else {
            WriteFormatted(writer, "%s  %s\n", hex_part, ascii_part);
        }
    }
    WriteRaw(writer, "\n", 1U);
}

/**
 * @brief Generate `tombstone.txt`, `reg_memory.txt`, `smaps.txt`, `threads.txt`, and `native.summary` (`0x009260..0x00ab70`).
 *        Tạo `tombstone.txt`, `reg_memory.txt`, `smaps.txt`, `threads.txt` và `native.summary` (`0x009260..0x00ab70`).
 */
int TombstoneGenerator::GenerateFullTombstoneAndSummary(
    const ParsedCrashContext& ctx,
    const std::vector<AttachedThread>& attached_threads,
    const std::vector<UnwoundFrameInfo>& main_frames) {

    std::string tombstone_path = ctx.dump_dir + "/tombstone.txt";
    DumperFileWriter writer {};
#if defined(__linux__)
    do {
        writer.fd = open(tombstone_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0600);
    } while (writer.fd == -1 && errno == EINTR);
#endif
    if (writer.fd < 0) {
        PtraceUnwinderEngine::LogMessage(4, "[dumper] failed to open %s, %d", tombstone_path.c_str(), 0);
    }

    // 1. Tombstone banner (`0x0092d8..0x009360`)
    WriteRaw(&writer, "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n", 64U);
    WriteFormatted(&writer, "pid: %d, tid: %d, name: %s  >>> %s <<<\n",
                   ctx.pid, ctx.tid, ctx.thread_name.c_str(), ctx.process_name.c_str());

    // 2. Signal & fault addr / sender pid (`0x009368..0x00944c`)
    if (ctx.siginfo_ptr != nullptr) {
        const AArch64SigInfo& si = *ctx.siginfo_ptr;
        char fault_buf[64] = {0};
        char from_buf[64]  = {0};
        uint32_t code_shift = static_cast<uint32_t>(si.si_code + 6);
        bool has_fault_addr = !(code_shift <= 6U && ((1U << code_shift) & 0x61U) != 0U);
        if (has_fault_addr && si.si_signo <= 11 && ((1U << si.si_signo) & 0x1b0U) != 0U) {
            std::snprintf(fault_buf, sizeof(fault_buf), "0x%016" PRIx64, si.si_addr);
        } else {
            std::snprintf(fault_buf, sizeof(fault_buf), "--------");
        }
        if (si.si_code <= 0 && static_cast<int32_t>(si.si_addr) != 0 &&
            static_cast<int32_t>(si.si_addr) != ctx.pid) {
            std::snprintf(from_buf, sizeof(from_buf), " (from pid %d, uid %d)",
                          static_cast<int32_t>(si.si_addr), si.si_uid);
        }
        WriteFormatted(&writer, "signal %d (%s), code %d (%s), fault addr %s%s\n",
                       si.si_signo,
                       PtraceUnwinderEngine::GetSignalName(si.si_signo),
                       si.si_code,
                       PtraceUnwinderEngine::GetSignalCodeName(si),
                       fault_buf,
                       from_buf);
    }

    // 3. Registers & Backtrace (`0x009700..0x0098a4`)
    DumpThreadRegisters(&writer, ctx.ucontext_ptr);
    DumpBacktraceFrames(&writer, main_frames);
    DumpBuildIds(&writer, main_frames);

    // 4. `stack:\n` (`0x00995c..0x009a88`)
    WriteRaw(&writer, "stack:\n", 7U);
    if (ctx.ucontext_ptr != nullptr) {
        uint64_t sp_cursor = ctx.ucontext_ptr->sp;
        uint64_t non_null_stack = 0ULL;
        DumpStackSegment(&writer, ctx.pid, &sp_cursor, 16U, 0, &non_null_stack);
        WriteRaw(&writer, "\n", 1U);
    }

    // 5. `reg_memory.txt` (`0x009c00..0x00a01c`)
    std::string reg_mem_path = ctx.dump_dir + "/reg_memory.txt";
    DumperFileWriter reg_writer {};
#if defined(__linux__)
    do {
        reg_writer.fd = open(reg_mem_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0600);
    } while (reg_writer.fd == -1 && errno == EINTR);
#endif
    if (reg_writer.fd >= 0 && ctx.ucontext_ptr != nullptr) {
        DumpMemoryAroundRegister(&reg_writer, ctx.pid, "pc", ctx.ucontext_ptr->pc, 1ULL, 0ULL, nullptr);
        DumpMemoryAroundRegister(&reg_writer, ctx.pid, "lr", ctx.ucontext_ptr->regs[30], 1ULL, 0ULL, nullptr);
#if defined(__linux__)
        close(reg_writer.fd);
#endif
    }

    // 6. `summary:\n` (`0x00a38c..0x00ab04`)
    WriteRaw(&writer, "summary:\n", 9U);
    WriteFormatted(&writer, "    maps count: %zu\n", main_frames.size());
    WriteFormatted(&writer, "    threads count: %zu\n", attached_threads.size());
    WriteFormatted(&writer, "    frames count: %zu\n", main_frames.size());

    bool protector_resumed = CrashProtectorEngine::EvaluateAndApplyProtection(ctx, main_frames);
    WriteFormatted(&writer, "    protector: %s\n", protector_resumed ? "true" : "false");

#if defined(__linux__)
    if (writer.fd >= 0) {
        close(writer.fd);
    }
#endif
    return writer.error_code;
}

} // namespace dumper
} // namespace npth
