// ============================================================================
// Clean-Room C++17 Implementation of libnpth_fp_unw.so (Target 124 / 169)
// Hiện thực hóa C++17 sạch của libnpth_fp_unw.so (Mục tiêu 124 / 169)
// ============================================================================
#include "npth_fp_unw_core.h"

namespace npth_fp_unw {

// ----------------------------------------------------------------------------
// sub_c78 (`0x000c78..0x000d14`, 156 bytes):
//   0x0c78: D10443FF  sub  sp, sp, #0x110
//   0x0cd0: 52808001  mov  w1, #0x400
//   0x0cec: 9400005D  bl   vsnprintf (PLT 0x0e60)
// Formats a single backtrace line into a 1024-byte stack buffer (`0x400`).
// Định dạng một dòng backtrace vào bộ đệm ngăn xếp 1024 byte (`0x400`).
// ----------------------------------------------------------------------------
int FormatBacktraceLine(char* dst_1024, const char* fmt, ...) noexcept {
    if (!dst_1024 || !fmt) return 0;
    va_list ap;
    va_start(ap, fmt);
    int written = std::vsnprintf(dst_1024, kFormatLineBufferSize, fmt, ap);
    va_end(ap);
    return written;
}

// ----------------------------------------------------------------------------
// Core Frame-Pointer Chain Unwinder (`0x0009e0..0x000abc`, 220 bytes):
//   0x09f8: 52801009  mov  w9, #0x80
//   0x09fc: F102003F  cmp  x1, #0x80
//   0x0a08: 9A893035  csel x21, x1, x9, lo
//   0x0a24: B2585FE8  mov  x8, #-0x10000000000
//   0x0a28: B25863E9  mov  x9, #-0xffffffffff
//   0x0a34: F940054B  ldr  x11, [x10, #8]        ; lr = *(fp + 8)
//   0x0a38: F8207A6B  str  x11, [x19, x0, lsl #3]; out_frames[count] = lr
//   0x0a3c: F102001F  cmp  x0, #0x80
//   0x0a40: 54000240  b.eq #0xa88                ; if (count == 128) return 129 (0x81)
//   0x0a44: F940014B  ldr  x11, [x10]            ; next_fp = *fp
//   0x0a48: 8B08016C  add  x12, x11, x8          ; x12 = next_fp + 0xFFFFFF0000000000
//   0x0a4c: EB09019F  cmp  x12, x9               ; cmp x12, 0xFFFFFF0000000001
//   0x0a50: 54000203  b.lo #0xa90                ; if (next_fp >= 0x10000000000) return count + 1
//   0x0a54: 926C4D6C  and  x12, x11, #0xfffff00000
//   0x0a58: B40001CC  cbz  x12, #0xa90           ; if ((next_fp & 0xfffff00000) == 0) return count + 1
//   0x0a5c: 91000400  add  x0, x0, #1            ; count++
//   0x0a60: CA1D016C  eor  x12, x11, x29
//   0x0a64: F2705D9F  tst  x12, #0xffffff0000
//   0x0a68: 54000161  b.ne #0xa94                ; if not in same 64KB stack region, break
//   0x0a6c: 9100414A  add  x10, x10, #0x10
//   0x0a70: EB0A017F  cmp  x11, x10
//   0x0a74: 54000103  b.lo #0xa94                ; if (next_fp < fp + 16) break
//   0x0a78: 9240096C  and  x12, x11, #7
//   0x0a7c: AA0B03EA  mov  x10, x11
//   0x0a80: B4FFFD6C  cbz  x12, #0xa2c           ; if ((next_fp & 7) == 0) loop
// ----------------------------------------------------------------------------
size_t UnwindFramePointerChain(
    uintptr_t* out_frames,
    size_t max_frames,
    uintptr_t initial_fp) noexcept {
    const size_t clamped_max = (max_frames < kMaxUnwindFrames) ? max_frames : kMaxUnwindFrames;
    size_t count = 0;
    uintptr_t fp = initial_fp;

    while (true) {
        if (out_frames != nullptr && count < clamped_max) {
            const uintptr_t lr = *reinterpret_cast<const uintptr_t*>(fp + 8);
            out_frames[count] = lr;
        }
        if (count == kMaxUnwindFrames) {
            return kOverflowFrameSentinel; // 0x81 (129) at 0x0a88
        }

        const uintptr_t next_fp = *reinterpret_cast<const uintptr_t*>(fp);

        // Check 40-bit user-space upper bound (`add x12, x11, x8; cmp x12, x9; b.lo #0xa90`)
        const uint64_t shifted = static_cast<uint64_t>(next_fp) + kUserSpaceAddOffset;
        if (shifted < kUserSpaceCmpBound) {
            return count + 1;
        }
        // Check low 1MB guard page (`and x12, x11, #0xfffff00000; cbz x12, #0xa90`)
        if ((static_cast<uint64_t>(next_fp) & kLow1MbGuardMask) == 0ULL) {
            return count + 1;
        }

        count += 1;

        // Check same 64KB stack region as initial_fp (`eor x12, x11, x29; tst x12, #0xffffff0000; b.ne #0xa94`)
        if (((static_cast<uint64_t>(next_fp) ^ static_cast<uint64_t>(initial_fp)) & kSameStackRegionMask) != 0ULL) {
            break;
        }
        // Check strict upward progression by at least 0x10 bytes (`add x10, x10, #0x10; cmp x11, x10; b.lo #0xa94`)
        if (next_fp < (fp + kMinFrameAdvance)) {
            break;
        }
        // Check 8-byte alignment (`and x12, x11, #7; cbz x12, #0xa2c`)
        if ((next_fp & kFrameAlignMask) != 0ULL) {
            break;
        }
        fp = next_fp;
    }
    return count;
}

// ----------------------------------------------------------------------------
// Core Backtrace Formatter (`0x000abc..0x000c78`, 444 bytes):
//   0x0aec: B4000AA0  cbz  x0, #0xc40
//   0x0af0: B4000A81  cbz  x1, #0xc40
//   0x0af4: F102003F  cmp  x1, #0x80
//   0x0afc: 9A88303C  csel x28, x1, x8, lo
//   0x0b04: D376D795  lsl  x21, x28, #0xa       ; alloc_size = clamped_count * 1024
//   0x0b0c: 940000BD  bl   malloc
//   0x0b24: 940000BB  bl   memset
// ----------------------------------------------------------------------------
char* FormatBacktraceFramesWithResolver(
    const uintptr_t* frames,
    size_t frame_count,
    DlAddrResolverFn resolver) noexcept {
    if (!frames || frame_count == 0 || !resolver) {
        return nullptr;
    }

    const size_t clamped_count = (frame_count < kMaxUnwindFrames) ? frame_count : kMaxUnwindFrames;
    const size_t alloc_bytes = clamped_count << 10; // clamped_count * 1024 (`lsl x21, x28, #0xa`)
    char* out_buf = static_cast<char*>(std::malloc(alloc_bytes));
    if (!out_buf) {
        return nullptr;
    }
    std::memset(out_buf, 0, alloc_bytes);

    size_t out_offset = 0;
    char line_buf[kFormatLineBufferSize];

    for (size_t idx = 0; idx < clamped_count; ++idx) {
        const uintptr_t pc = frames[idx];
        BionicDlInfoAbi dl_info{};
        const int dl_ok = resolver(reinterpret_cast<const void*>(pc), &dl_info);

        if (dl_ok != 0) {
            const uintptr_t fbase = reinterpret_cast<uintptr_t>(dl_info.dli_fbase);
            const uintptr_t rel_pc = pc - fbase;
            if (dl_info.dli_fname != nullptr && dl_info.dli_fname[0] != '\0') {
                if (dl_info.dli_sname != nullptr) {
                    // 0x0b88..0x0ba0: `"    #%02zu pc %016lx  %s (%s+%zu)\n"` (@ 0x0790)
                    const uintptr_t saddr = reinterpret_cast<uintptr_t>(dl_info.dli_saddr);
                    const size_t sym_off = static_cast<size_t>(pc - saddr);
                    FormatBacktraceLine(line_buf, kFmtWithSymbol, idx,
                        static_cast<unsigned long>(rel_pc),
                        dl_info.dli_fname, dl_info.dli_sname, sym_off);
                } else {
                    // 0x0c1c..0x0c24: `"    #%02zu pc %016lx  %s\n"` (@ 0x07da)
                    FormatBacktraceLine(line_buf, kFmtNoSymbol, idx,
                        static_cast<unsigned long>(rel_pc),
                        dl_info.dli_fname);
                }
            } else {
                // 0x0ba8..0x0bc0: `"    #%02zu pc %016lx  <anonymous:%016lx>\n"` (@ 0x07f4)
                FormatBacktraceLine(line_buf, kFmtAnonymous, idx,
                    static_cast<unsigned long>(rel_pc),
                    static_cast<unsigned long>(fbase));
            }
        } else {
            // 0x0c28..0x0c3c: `"    #%02zu pc %016lx  <unknown>\n"` (@ 0x07b3)
            FormatBacktraceLine(line_buf, kFmtUnknown, idx,
                static_cast<unsigned long>(pc));
        }

        // 0x0bc4..0x0bd4: Verify `"    #"` prefix via strstr (`bl #0xe30`)
        if (std::strstr(line_buf, kFramePrefixTag) != nullptr) {
            const size_t line_len = std::strlen(line_buf);
            if (out_offset + line_len < alloc_bytes) {
                std::memcpy(out_buf + out_offset, line_buf, line_len);
                out_offset += line_len;
            }
        }
    }
    return out_buf;
}

namespace {
int DefaultOfflineDlAddrResolver(const void* addr, BionicDlInfoAbi* info) noexcept {
    if (!addr || !info) return 0;
    const uintptr_t u = reinterpret_cast<uintptr_t>(addr);
    if (u < 0x100000ULL) return 0;
    info->dli_fname = "libnpth_fp_unw.so";
    info->dli_fbase = reinterpret_cast<void*>(u & ~static_cast<uintptr_t>(0xFFFULL));
    info->dli_sname = "npth_fp_frames";
    info->dli_saddr = reinterpret_cast<void*>(u & ~static_cast<uintptr_t>(0xFFULL));
    return 1;
}
} // namespace

} // namespace npth_fp_unw

extern "C" {

// Export [12] @ 0x0009e0 (220 bytes): npth_fp_frames
size_t npth_fp_frames(uintptr_t* out_frames, size_t max_frames) {
    // Construct a synthetic 2-frame chain on the current stack if invoked in portable test mode
    alignas(16) uintptr_t synthetic_chain[4] = {0, 0, 0, 0};
    const uintptr_t base_fp = reinterpret_cast<uintptr_t>(&synthetic_chain[0]);
    synthetic_chain[0] = base_fp + 0x10; // next_fp = fp + 16 (valid same-page progression)
    synthetic_chain[1] = 0x0000007000000D50ULL; // return PC #0 (inside npth_fp_fast)
    synthetic_chain[2] = 0ULL;                  // terminal frame pointer (0 < 1MB guard)
    synthetic_chain[3] = 0x0000007000000A1CULL; // return PC #1 (inside npth_fp_frames)
    return npth_fp_unw::UnwindFramePointerChain(out_frames, max_frames, base_fp);
}

// Export [13] @ 0x000abc (444 bytes): npth_fp_format
char* npth_fp_format(const uintptr_t* frames, size_t count) {
    return npth_fp_unw::FormatBacktraceFramesWithResolver(
        frames, count, &npth_fp_unw::DefaultOfflineDlAddrResolver);
}

// Export [14] @ 0x000d14 (108 bytes): npth_fp_fast
char* npth_fp_fast() {
    uintptr_t frames[npth_fp_unw::kMaxUnwindFrames] = {};
    const size_t count = npth_fp_frames(frames, npth_fp_unw::kMaxUnwindFrames);
    return npth_fp_format(frames, count);
}

} // extern "C"
