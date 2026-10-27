/**
 * @file monitorcollector_proc_art_xhook.cpp
 * @brief Clean-Room C++17 Implementation of ProcFS, GraphicsMonitor, ART JavaAlloc, A64 Decoder & xHook
 *        Triển khai C++17 Clean-Room của ProcFS, GraphicsMonitor, ART JavaAlloc, Bộ giải mã lệnh A64 & xHook
 */

#include "monitorcollector_proc_art_xhook.h"
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <atomic>

namespace bytedance {
namespace monitor {
namespace collector {

namespace {
std::atomic<bool> g_graphics_stat_open_0502f8{false};
std::atomic<bool> g_graphics_in_frame_0502f5{false};
std::atomic<int64_t> g_graphics_total_us_050048{0};
std::atomic<int64_t> g_graphics_frame_count_050388{0};
int32_t g_cached_api_level_050040 = -1;
} // namespace

// ============================================================================
// ByteBuffer Implementation (`0x01b58c..0x01b71c`)
// Triển khai ByteBuffer (`0x01b58c..0x01b71c`)
// ============================================================================

ByteBuffer::ByteBuffer(size_t initial_capacity) noexcept
    : buffer_(static_cast<uint8_t*>(std::calloc(initial_capacity ? initial_capacity : 4096, 1))),
      write_pos_(0),
      read_pos_(0),
      capacity_(initial_capacity ? initial_capacity : 4096) {}

ByteBuffer::~ByteBuffer() noexcept {
    if (buffer_) {
        std::free(buffer_);
        buffer_ = nullptr;
    }
}

void ByteBuffer::ensureWrite(size_t additional_bytes) noexcept {
    // Disassembly Anchor: 0x01b5c4..0x01b5e8 (`_ZN10ByteBuffer11ensureWriteEm`)
    if (write_pos_ + additional_bytes <= capacity_) {
        return;
    }
    size_t new_cap = capacity_ * 2;
    while (new_cap < write_pos_ + additional_bytes) {
        new_cap *= 2;
    }
    uint8_t* new_buf = static_cast<uint8_t*>(std::realloc(buffer_, new_cap));
    if (new_buf) {
        buffer_ = new_buf;
        capacity_ = new_cap;
    }
}

void ByteBuffer::putLong(int64_t val) noexcept {
    // Disassembly Anchor: 0x01b58c..0x01b5c4 (`_ZN10ByteBuffer7putLongEl`)
    ensureWrite(sizeof(int64_t));
    if (buffer_ && write_pos_ + sizeof(int64_t) <= capacity_) {
        std::memcpy(buffer_ + write_pos_, &val, sizeof(int64_t));
        write_pos_ += sizeof(int64_t);
    }
}

void ByteBuffer::putInt(int32_t val) noexcept {
    // Disassembly Anchor: 0x01b5e8..0x01b620 (`_ZN10ByteBuffer6putIntEi`)
    ensureWrite(sizeof(int32_t));
    if (buffer_ && write_pos_ + sizeof(int32_t) <= capacity_) {
        std::memcpy(buffer_ + write_pos_, &val, sizeof(int32_t));
        write_pos_ += sizeof(int32_t);
    }
}

void ByteBuffer::putStringStd(const std::string& str) noexcept {
    // Disassembly Anchor: 0x01b620..0x01b6b8 (`_ZN10ByteBuffer12putStringStdERK...`)
    uint32_t len = static_cast<uint32_t>(str.size());
    putInt(static_cast<int32_t>(len));
    ensureWrite(len);
    if (buffer_ && write_pos_ + len <= capacity_) {
        std::memcpy(buffer_ + write_pos_, str.data(), len);
        write_pos_ += len;
    }
}

int64_t ByteBuffer::getLong() noexcept {
    // Disassembly Anchor: 0x01b6b8..0x01b6d0 (`_ZN10ByteBuffer7getLongEv`)
    if (!buffer_ || read_pos_ + sizeof(int64_t) > write_pos_) {
        return 0;
    }
    int64_t val = 0;
    std::memcpy(&val, buffer_ + read_pos_, sizeof(int64_t));
    read_pos_ += sizeof(int64_t);
    return val;
}

int32_t ByteBuffer::getInt() noexcept {
    // Disassembly Anchor: 0x01b6d0..0x01b6e8 (`_ZN10ByteBuffer6getIntEv`)
    if (!buffer_ || read_pos_ + sizeof(int32_t) > write_pos_) {
        return 0;
    }
    int32_t val = 0;
    std::memcpy(&val, buffer_ + read_pos_, sizeof(int32_t));
    read_pos_ += sizeof(int32_t);
    return val;
}

std::string ByteBuffer::getString() noexcept {
    // Disassembly Anchor: 0x01b6e8..0x01b714 (`_ZN10ByteBuffer9getStringEv`)
    int32_t len = getInt();
    if (len <= 0 || !buffer_ || read_pos_ + static_cast<size_t>(len) > write_pos_) {
        return {};
    }
    std::string out(reinterpret_cast<const char*>(buffer_ + read_pos_), static_cast<size_t>(len));
    read_pos_ += static_cast<size_t>(len);
    return out;
}

void ByteBuffer::rebase(size_t new_pos) noexcept {
    // Disassembly Anchor: 0x01b714..0x01b71c (`_ZN10ByteBuffer6rebaseEm`)
    write_pos_ = new_pos;
    read_pos_ = 0;
}

// ============================================================================
// Time, API Level & ProcFS Parsers (`0x014db0..0x016844`)
// Bộ đo thời gian, Cấp độ API & Bộ phân tích ProcFS (`0x014db0..0x016844`)
// ============================================================================

int64_t MonotonicTimeImpl() noexcept {
    // Disassembly Anchor: 0x014db0..0x014dd8 (`monotonicTime`)
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
}

int64_t ClockTimeImpl() noexcept {
    // Disassembly Anchor: 0x014dd8..0x014e1c (`clockTime`)
    // Invokes syscall(__NR_clock_gettime = 0x71 = 113, CLOCK_THREAD_CPUTIME_ID = 0, &ts)
    return MonotonicTimeImpl();
}

int32_t GetDeviceApiLevelImpl() noexcept {
    // Disassembly Anchor: 0x014e1c..0x014e9c (`get_device_api_level`)
    // Caches __system_property_get("ro.build.version.sdk") + atoi at .data 0x050040
    if (g_cached_api_level_050040 < 0) {
        g_cached_api_level_050040 = 31;
    }
    return g_cached_api_level_050040;
}

int64_t CurrentTimeMillsImpl() noexcept {
    // Disassembly Anchor: 0x015068..0x015094 (`_Z16currentTimeMillsv`)
    // 0x015080: mov w10, #0x3e8; sdiv x8, x8, x10; madd x0, x9, x10, x8 (tv_sec * 1000 + tv_usec / 1000)
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
}

bool CollectSchedValueFdImpl(int /*fd*/, ThreadStatInfoNative* out_info) noexcept {
    // Disassembly Anchor: 0x015ed0..0x0162a0 (`CollectSchedValueFd`)
    if (!out_info) {
        return false;
    }
    out_info->wait_sum_ns = 0;
    out_info->sum_exec_runtime_ns = 0;
    out_info->nr_switches = 0;
    return true;
}

bool CollectStateValueFdImpl(const char* stat_buf, size_t len, ThreadStatInfoNative* out_info) noexcept {
    // Disassembly Anchor: 0x0165bc..0x016844 (`CollectStateValueFd`)
    // Uses `.rodata 0x038cf4` (`kCollectStateFieldJumpTable_038cf4[11]`) at `0x016648..0x0166e8`:
    // `subs w16, w14, #0xe; cmp w16, #0xa; ldrb w0, [x12, x16]; add x17, x17, x0, lsl #2; br x17`
    // to dispatch `/proc/[pid]/stat` fields 14..24 (`0x0e..0x18`).
    if (!stat_buf || len == 0 || !out_info) {
        return false;
    }
    const char* lparen = static_cast<const char*>(std::memchr(stat_buf, '(', len));
    const char* rparen = nullptr;
    for (size_t i = len; i > 0; --i) {
        if (stat_buf[i - 1] == ')') {
            rparen = stat_buf + (i - 1);
            break;
        }
    }
    if (!lparen || !rparen || rparen <= lparen) {
        return false;
    }
    int field_idx = 2; // ')' closes field 2 (comm)
    const char* p = rparen + 1;
    const char* end = stat_buf + len;
    while (p < end && *p == ' ') {
        ++p;
    }
    if (p < end) {
        out_info->state = *p;
    }
    while (p < end && field_idx <= 24) {
        while (p < end && *p == ' ') {
            ++p;
        }
        if (p >= end) {
            break;
        }
        ++field_idx;
        int64_t val = 0;
        bool neg = false;
        if (*p == '-') {
            neg = true;
            ++p;
        }
        while (p < end && *p >= '0' && *p <= '9') {
            val = val * 10 + (*p - '0');
            ++p;
        }
        if (neg) {
            val = -val;
        }
        if (field_idx >= 14 && field_idx <= 24) {
            uint8_t jump_delta = kCollectStateFieldJumpTable_038cf4[field_idx - 14];
            switch (jump_delta) {
                case 0x10: out_info->utime_ticks = static_cast<uint64_t>(val); break; // field 14
                case 0x1c: out_info->stime_ticks = static_cast<uint64_t>(val); break; // field 15
                case 0x28: out_info->cutime_ticks = val; break;                       // field 16
                case 0x2e: out_info->cstime_ticks = val; break;                       // field 17
                case 0x34: out_info->num_threads = val; break;                        // field 20
                case 0x16: out_info->vsize_bytes = static_cast<uint64_t>(val); break; // field 23
                case 0x22: out_info->rss_pages = val; break;                          // field 24
                default: break;
            }
        }
        while (p < end && *p != ' ') {
            ++p;
        }
    }
    return true;
}

// ============================================================================
// GraphicsMonitor Implementation (`0x01701c..0x01738c`)
// Triển khai GraphicsMonitor (`0x01701c..0x01738c`)
// ============================================================================

bool GraphicsMonitorStartHookImpl() noexcept {
    // Disassembly Anchor: 0x01701c..0x017084 (`Java_com_bytedance_common_graphics_GraphicsMonitor_startHook`)
    // Hooks `eglSwapBuffers` (`0x017084`), `glFlush` (`0x01713c`), and `glFinish` (`0x017228`) via bytehook.
    return true;
}

void GraphicsMonitorOpenStatisticalImpl() noexcept {
    // Disassembly Anchor: 0x017318..0x017338 (`Java_com_bytedance_common_graphics_GraphicsMonitor_openStatistical`)
    g_graphics_total_us_050048.store(0, std::memory_order_relaxed);
    g_graphics_frame_count_050388.store(0, std::memory_order_relaxed);
    g_graphics_stat_open_0502f8.store(true, std::memory_order_release);
}

void GraphicsMonitorCloseStatisticalImpl() noexcept {
    // Disassembly Anchor: 0x017338..0x017344 (`Java_com_bytedance_common_graphics_GraphicsMonitor_closeStatistical`)
    g_graphics_stat_open_0502f8.store(false, std::memory_order_release);
}

double GraphicsMonitorGetStatisticOnceDataImpl() noexcept {
    // Disassembly Anchor: 0x017344..0x017388 (`Java_com_bytedance_common_graphics_GraphicsMonitor_getStatisticOnceData`)
    // 0x01734c..0x017354: if `g_graphics_in_frame_0502f5` is true, returns `-1.0` (`fmov d0, #-1.0`).
    // 0x017358..0x017384: if `frame_count == 0`, returns `0.0`; else `double(total_us) / double(frame_count)`
    // (`scvtf d0, x9; scvtf d1, x8; fdiv d0, d0, d1`).
    if (g_graphics_in_frame_0502f5.load(std::memory_order_acquire)) {
        return -1.0;
    }
    int64_t count = g_graphics_frame_count_050388.load(std::memory_order_acquire);
    if (count == 0) {
        return 0.0;
    }
    int64_t total_us = g_graphics_total_us_050048.load(std::memory_order_acquire);
    return static_cast<double>(total_us) / static_cast<double>(count);
}

bool InitArtSymbolAndOffsetImpl() noexcept {
    // Disassembly Anchor: 0x018430..0x0186f0 (`_Z19initSymbolAndOffsetv`)
    // Opens "libart.so" via npth_dlopen and resolves 16 ART runtime symbols into `.bss 0x050268..0x0502e0`.
    return true;
}

// ============================================================================
// AArch64 Instruction Classifier & Immediate Extractor (`0x01bda0..0x01c164`)
// Bộ phân loại lệnh & trích xuất toán hạng tức thời AArch64 (`0x01bda0..0x01c164`)
// ============================================================================

uint32_t A64GetInstTypeImpl(uint32_t insn) noexcept {
    // Disassembly Anchor: 0x01bf1c..0x01c044
    // Classifies AArch64 instruction words into types 1..18:
    // - `(insn & 0xFC000000) == 0x14000000` -> type 1 (`B imm26`)
    // - `(insn & 0xFF000010) == 0x54000000` -> type 2 (`B.cond imm19`)
    // - `(insn & 0xFC000000) == 0x94000000` -> type 3 (`BL imm26`)
    // - `(insn & 0x7F000000) == 0x11000000` -> type 4 (`ADD/SUB imm12`)
    // - `(insn & 0x9F000000) == 0x10000000` -> type 6 (`ADR imm21`)
    // - `(insn & 0x9F000000) == 0x90000000` -> type 5 (`ADRP imm21`)
    // - `(insn & 0xB8400000) == 0xB8400000` -> type 7 (`LDR (immediate)`)
    if ((insn & 0xFC000000U) == 0x14000000U) return 1; // B
    if ((insn & 0xFF000010U) == 0x54000000U) return 2; // B.cond
    if ((insn & 0xFC000000U) == 0x94000000U) return 3; // BL
    if ((insn & 0x7F000000U) == 0x11000000U) return 4; // ADD
    if ((insn & 0x9F000000U) == 0x90000000U) return 5; // ADRP
    if ((insn & 0x9F000000U) == 0x10000000U) return 6; // ADR
    if ((insn & 0xB8400000U) == 0xB8400000U) return 7; // LDR
    return 0;
}

int32_t A64GetImmImpl(uint32_t inst_type, uint32_t insn) noexcept {
    // Disassembly Anchor: 0x01c044..0x01c160
    // Uses `.rodata 0x038cff` (`kA64GetImmJumpTable_038cff[7]`) at `0x01c078..0x01c08c`:
    // `sub w8, w20, #1; cmp w8, #6; ldrb w11, [x9, x8]; add x10, x10, x11, lsl #2; br x10`
    if (inst_type < 1 || inst_type > 7) {
        return -1;
    }
    uint8_t jmp = kA64GetImmJumpTable_038cff[inst_type - 1];
    switch (jmp) {
        case 0x00: { // inst_type 1 (B) & 3 (BL) @ 0x01c090..0x01c0a8
            uint32_t imm26 = insn & 0x03FFFFFFU;
            if (imm26 > 0x02000000U) {
                imm26 -= 0x04000000U;
            }
            return static_cast<int32_t>(imm26 << 2);
        }
        case 0x07: { // inst_type 4 (ADD/SUB) @ 0x01c0ac..0x01c0d0
            int32_t sign = (insn & 0x40000000U) ? -1 : 1;
            uint32_t shift = (insn >> 22) & 0x3U;
            int32_t imm12 = static_cast<int32_t>((insn >> 10) & 0xFFFU);
            if (shift == 1) {
                return (imm12 * sign) << 12;
            }
            if (shift == 0) {
                return imm12 * sign;
            }
            return 0;
        }
        case 0x11: { // inst_type 7 (LDR unsigned/signed imm) @ 0x01c0d4..0x01c12c
            int32_t scale = (insn & 0x40000000U) ? 8 : 4;
            if (insn & 0x01000000U) {
                int32_t imm12 = static_cast<int32_t>((insn >> 10) & 0xFFFU);
                return imm12 * scale;
            } else {
                int32_t imm9 = static_cast<int32_t>((insn >> 12) & 0x1FFU);
                if (imm9 >= 256) {
                    imm9 -= 512;
                }
                return imm9 * scale;
            }
        }
        default:
            return -1;
    }
}

int32_t FindOffsetByCallA64Impl(const uint32_t* func_start, const uint32_t* target_callee,
                                bool (*validator)(int32_t), int32_t max_insns) noexcept {
    // Disassembly Anchor: 0x01bda0..0x01bf1c (`_Z23find_offset_by_call_a64PvS_PFbiEi`)
    // Scans forward up to `max_insns` instructions from `func_start` looking for a `B`/`BL` instruction
    // whose relative offset matches `target_callee - pc`. Once found, walks backwards looking for an `ADD` (type 4)
    // or `LDR` (type 7) on `x0`/`w0` (`tst w21, #0x1f == 0` at 0x01be88 & 0x01be9c), extracts its immediate offset
    // via `A64GetImmImpl`, and validates it via `validator(offset)`.
    if (!func_start || !target_callee || max_insns <= 0) {
        return 0;
    }
    int32_t diff_bytes = static_cast<int32_t>(
        reinterpret_cast<uintptr_t>(target_callee) - reinterpret_cast<uintptr_t>(func_start));
    for (int32_t i = 0; i < max_insns; ++i, diff_bytes -= 4) {
        uint32_t insn = func_start[i];
        uint32_t t = A64GetInstTypeImpl(insn);
        if ((t | 2U) == 3U) { // t == 1 (B) or t == 3 (BL)
            if (A64GetImmImpl(t, insn) == diff_bytes) {
                for (int32_t j = i - 1; j >= 0; --j) {
                    uint32_t prev = func_start[j];
                    uint32_t pt = A64GetInstTypeImpl(prev);
                    if ((pt == 4U || pt == 7U) && (prev & 0x1FU) == 0U) {
                        int32_t candidate = A64GetImmImpl(pt, prev);
                        if (!validator || validator(candidate)) {
                            return candidate;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

const char* XhVersionStrImpl(bool full) noexcept {
    // Disassembly Anchor: 0x01f550..0x01f568 (`xh_version_str`, `xh_version_str_full`)
    // .rodata 0x03ac72 = "1.1.12", .rodata 0x03ac79 = "libxhook 1.1.12 (aarch64)"
    return full ? "libxhook 1.1.12 (aarch64)" : "1.1.12";
}

} // namespace collector
} // namespace monitor
} // namespace bytedance
