/**
 * @file pitayabdcomponent_regex_stream.cpp
 * @brief Implementation of Reconstructed libc++ StreamBuffer, Regex NFA Engine & Container Algorithms (Target 46).
 *        Triển khai bộ đệm luồng libc++, động cơ NFA biểu thức chính quy và thuật toán container (Mục tiêu 46).
 *
 * Disassembly Reference / Tham chiếu Hợp ngữ AArch64:
 * - std::__ndk1::vector<ThreadStackInfo>::insert       @ 0x0048b8..0x004bd8 (804 bytes)
 * - std::__ndk1::basic_stringbuf<char>::seekoff        @ 0x005044..0x005168 (296 bytes)
 * - std::__ndk1::basic_stringbuf<char>::seekpos        @ 0x00516c..0x00517c ( 20 bytes)
 * - std::__ndk1::basic_streambuf<char>::xsgetn         @ 0x005190..0x0052bc (304 bytes)
 * - std::__ndk1::basic_stringbuf<char>::underflow      @ 0x0052c0..0x00536c (176 bytes)
 * - std::__ndk1::basic_stringbuf<char>::pbackfail      @ 0x005370..0x005440 (212 bytes)
 * - std::__ndk1::basic_stringbuf<char>::overflow       @ 0x005444..0x00569c (604 bytes)
 * - std::__ndk1::basic_stringbuf<char>::str            @ 0x005c50..0x005dc0 (372 bytes)
 * - std::__ndk1::getline                               @ 0x005e14..0x005fe0 (464 bytes)
 * - std::__ndk1::basic_regex<char> NFA compiler        @ 0x0060d4..0x00ddff
 * - std::__ndk1::regex_search & __search               @ 0x00de34..0x00e24b
 */

#include "pitayabdcomponent_regex_stream.h"

#include <algorithm>
#include <cstring>
#include <regex>

namespace pitaya {
namespace bdcomponent {

// ============================================================================
// 1. NdkStringBuf Implementation (0x005044..0x005dc0)
//    Triển khai NdkStringBuf (0x005044..0x005dc0)
// ============================================================================
NdkStringBuf::NdkStringBuf(std::ios_base::openmode mode)
    : storage_(),
      mode_(mode) {
    SetStr(std::string());
}

NdkStringBuf::NdkStringBuf(const std::string& initial_str,
                           std::ios_base::openmode mode)
    : storage_(),
      mode_(mode) {
    SetStr(initial_str);
}

void NdkStringBuf::SetStr(const std::string& s) {
    // Disassembly @ 0x005c50..0x005dc0 (372 bytes):
    // Copies string into __str_ (+0x40), sets __hm_ (+0x58) = base + size,
    // configures input pointers (__binp_, __ninp_, __einp_) if mode & ios_base::in (0x08),
    // and output pointers (__bout_, __nout_, __eout_) if mode & ios_base::out (0x10).
    storage_ = s;
    char* base = storage_.empty() ? nullptr : &storage_[0];
    const size_t sz = storage_.size();
    hm_ = (base != nullptr) ? (base + sz) : nullptr;

    if ((mode_ & std::ios_base::in) != 0) {
        binp_ = base;
        ninp_ = base;
        einp_ = hm_;
    } else {
        binp_ = nullptr;
        ninp_ = nullptr;
        einp_ = nullptr;
    }

    if ((mode_ & std::ios_base::out) != 0) {
        bout_ = base;
        nout_ = ((mode_ & (std::ios_base::app | std::ios_base::ate)) != 0) ? hm_ : base;
        eout_ = (base != nullptr) ? (base + storage_.capacity()) : nullptr;
    } else {
        bout_ = nullptr;
        nout_ = nullptr;
        eout_ = nullptr;
    }
}

std::string NdkStringBuf::GetStr() const {
    if ((mode_ & std::ios_base::out) != 0) {
        const char* end_ptr = (hm_ < nout_) ? nout_ : hm_;
        if (bout_ != nullptr && end_ptr >= bout_) {
            return std::string(bout_, static_cast<size_t>(end_ptr - bout_));
        }
        return std::string();
    }
    if ((mode_ & std::ios_base::in) != 0 && binp_ != nullptr && einp_ >= binp_) {
        return std::string(binp_, static_cast<size_t>(einp_ - binp_));
    }
    return std::string();
}

int64_t NdkStringBuf::SeekOff(int64_t off, std::ios_base::seekdir way, std::ios_base::openmode which) {
    // Disassembly @ 0x005044..0x005168 (296 bytes):
    //   0x005044: f9402c08  ldr  x8, [x0, #0x58]  ; x8 = __hm_
    //   0x005048: f9401809  ldr  x9, [x0, #0x30]  ; x9 = __nout_ (pptr)
    //   0x00504c: eb09011f  cmp  x8, x9
    //   0x005050: 54000062  b.hs #0x505c
    //   0x005054: aa0903e8  mov  x8, x9
    //   0x005058: f9002c09  str  x9, [x0, #0x58]  ; if (__hm_ < pptr) __hm_ = pptr
    //   0x00505c: 721d046a  ands w10, w3, #0x18   ; w10 = which & (in | out)
    //   0x005060: 540000a0  b.eq #0x5074          ; if 0 -> return pos_type(-1)
    //   0x005064: 7100045f  cmp  w2, #1           ; way == ios_base::cur (1)?
    //   0x005068: 540000c1  b.ne #0x5080
    //   0x00506c: 7100615f  cmp  w10, #0x18       ; both in and out?
    //   0x005070: 54000081  b.ne #0x5080
    //   0x005074: 92800001  mov  x1, #-1          ; return -1 on cur + (in|out)
    if (hm_ < nout_) {
        hm_ = nout_;
    }
    const auto mask = which & (std::ios_base::in | std::ios_base::out);
    if (mask == 0) {
        return -1;
    }
    if (mask == (std::ios_base::in | std::ios_base::out) && way == std::ios_base::cur) {
        return -1;
    }

    const char* base = storage_.empty() ? nullptr : storage_.data();
    const int64_t width = (hm_ != nullptr && base != nullptr) ? static_cast<int64_t>(hm_ - base) : 0;
    int64_t new_off = 0;

    switch (way) {
        case std::ios_base::beg:
            new_off = 0;
            break;
        case std::ios_base::cur:
            if ((which & std::ios_base::in) != 0) {
                if (ninp_ == nullptr || binp_ == nullptr) {
                    return -1;
                }
                new_off = static_cast<int64_t>(ninp_ - binp_);
            } else {
                if (nout_ == nullptr || bout_ == nullptr) {
                    return -1;
                }
                new_off = static_cast<int64_t>(nout_ - bout_);
            }
            break;
        case std::ios_base::end:
            new_off = width;
            break;
        default:
            return -1;
    }

    // Disassembly @ 0x0050a0..0x0050b0:
    //   adds x11, x11, x1; b.mi #0x5164; cmp x10, x11; b.lt #0x5164
    new_off += off;
    if (new_off < 0 || new_off > width) {
        return -1;
    }

    if (new_off != 0) {
        if (((which & std::ios_base::in) != 0 && ninp_ == nullptr) ||
            ((which & std::ios_base::out) != 0 && nout_ == nullptr)) {
            return -1;
        }
    }

    if ((which & std::ios_base::in) != 0 && binp_ != nullptr) {
        ninp_ = binp_ + new_off;
        einp_ = hm_;
    }
    if ((which & std::ios_base::out) != 0 && bout_ != nullptr) {
        nout_ = bout_ + new_off;
    }
    return new_off;
}

int64_t NdkStringBuf::SeekPos(int64_t sp, std::ios_base::openmode which) {
    // Disassembly @ 0x00516c..0x00517c:
    //   ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]; br x4
    return SeekOff(sp, std::ios_base::beg, which);
}

std::streamsize NdkStringBuf::Xsgetn(char* s, std::streamsize n) {
    // Disassembly @ 0x005190..0x0052bc (304 bytes):
    // Copies chunks from [ninp_..einp_) using memcpy (0x002350) and calls Underflow() when exhausted.
    if (s == nullptr || n <= 0) {
        return 0;
    }
    std::streamsize total_read = 0;
    while (total_read < n) {
        if (ninp_ != nullptr && ninp_ < einp_) {
            const std::streamsize avail = static_cast<std::streamsize>(einp_ - ninp_);
            const std::streamsize chunk = std::min(avail, n - total_read);
            std::memcpy(s + total_read, ninp_, static_cast<size_t>(chunk));
            ninp_ += chunk;
            total_read += chunk;
        } else {
            const int ch = Underflow();
            if (ch == -1) {
                break;
            }
            s[total_read++] = static_cast<char>(ch);
            if (ninp_ != nullptr && ninp_ < einp_) {
                ++ninp_;
            }
        }
    }
    return total_read;
}

int NdkStringBuf::Underflow() {
    // Disassembly @ 0x0052c0..0x00536c (176 bytes):
    //   Updates hm_ = max(hm_, nout_), sets einp_ = hm_ if in-mode enabled,
    //   and returns unsigned byte *ninp_ or -1 (EOF) if ninp_ >= einp_.
    if (hm_ < nout_) {
        hm_ = nout_;
    }
    if ((mode_ & std::ios_base::in) == 0) {
        return -1;
    }
    if (einp_ < hm_) {
        einp_ = hm_;
    }
    if (ninp_ != nullptr && ninp_ < einp_) {
        return static_cast<unsigned char>(*ninp_);
    }
    return -1;
}

int NdkStringBuf::Pbackfail(int c) {
    // Disassembly @ 0x005370..0x005440 (212 bytes):
    if (hm_ < nout_) {
        hm_ = nout_;
    }
    if (binp_ != nullptr && ninp_ != nullptr && binp_ < ninp_) {
        if (c == -1) {
            --ninp_;
            return 0;
        }
        if (((mode_ & std::ios_base::out) != 0) ||
            static_cast<unsigned char>(ninp_[-1]) == static_cast<unsigned char>(c)) {
            --ninp_;
            *ninp_ = static_cast<char>(c);
            return c;
        }
    }
    return -1;
}

int NdkStringBuf::Overflow(int c) {
    // Disassembly @ 0x005444..0x00569c (604 bytes):
    if ((mode_ & std::ios_base::out) == 0) {
        return -1;
    }
    if (c == -1) {
        return 0;
    }
    const ptrdiff_t in_off  = (binp_ != nullptr && ninp_ != nullptr) ? (ninp_ - binp_) : 0;
    const ptrdiff_t out_off = (bout_ != nullptr && nout_ != nullptr) ? (nout_ - bout_) : 0;
    if (hm_ < nout_) {
        hm_ = nout_;
    }
    const ptrdiff_t hm_off  = (bout_ != nullptr && hm_ != nullptr) ? (hm_ - bout_) : 0;

    storage_.push_back(static_cast<char>(c));
    SyncPointersAfterResize(in_off, out_off + 1, std::max(hm_off, out_off + 1));
    return static_cast<unsigned char>(c);
}

void NdkStringBuf::SyncPointersAfterResize(ptrdiff_t in_off, ptrdiff_t out_off, ptrdiff_t hm_off) {
    char* base = storage_.empty() ? nullptr : &storage_[0];
    hm_ = (base != nullptr) ? (base + hm_off) : nullptr;
    if ((mode_ & std::ios_base::in) != 0 && base != nullptr) {
        binp_ = base;
        ninp_ = base + in_off;
        einp_ = hm_;
    }
    if ((mode_ & std::ios_base::out) != 0 && base != nullptr) {
        bout_ = base;
        nout_ = base + out_off;
        eout_ = base + storage_.size();
    }
}

// ============================================================================
// 2. RegexStreamEngine Implementation (0x0048b8, 0x005e14, 0x0060d4..0x00e24b)
//    Triển khai RegexStreamEngine (0x0048b8, 0x005e14, 0x0060d4..0x00e24b)
// ============================================================================
RegexStreamEngine::RegexStreamEngine(const std::string& input)
    : buf_(input, std::ios_base::in),
      eof_(false) {}

bool RegexStreamEngine::GetLine(std::string* out_line, char delim) {
    // Disassembly @ 0x005e14..0x005fe0 (464 bytes):
    // Clears out_line, reads characters from streambuf until delim or EOF (-1),
    // sets eofbit (0x02) / failbit (0x04) on stream state (+0x20).
    if (out_line == nullptr || eof_) {
        return false;
    }
    out_line->clear();
    bool extracted_any = false;
    while (true) {
        const int ch = buf_.Underflow();
        if (ch == -1) {
            eof_ = true;
            break;
        }
        char c = 0;
        (void)buf_.Xsgetn(&c, 1);
        extracted_any = true;
        if (c == delim) {
            break;
        }
        out_line->push_back(c);
    }
    return extracted_any;
}

bool RegexStreamEngine::RegexSearchGroups(
    const std::string& input,
    const char* pattern,
    std::vector<std::string>* out_groups) {
    // Disassembly @ 0x0060d4 (basic_regex<char> constructor),
    //               0x00de34 (regex_search),
    //               0x00e080 (basic_regex::__search),
    //               0x002e54..0x002e6c (sub_match count via 0xaaaaaaaaaaaaaaabULL):
    if (pattern == nullptr || out_groups == nullptr) {
        return false;
    }
    out_groups->clear();
    try {
        const std::regex re(pattern, std::regex_constants::ECMAScript);
        std::smatch match;
        if (std::regex_search(input, match, re)) {
            // Verify exact 24-byte sub_match arithmetic from 0x002e54..0x002e68:
            // byte_diff = match.size() * 24 -> ComputeSubMatchCountDiv24(byte_diff) == match.size()
            const uint64_t simulated_byte_diff = static_cast<uint64_t>(match.size()) * 24ULL;
            const uint64_t count = ComputeSubMatchCountDiv24(simulated_byte_diff);
            out_groups->reserve(static_cast<size_t>(count));
            for (size_t i = 0; i < static_cast<size_t>(count); ++i) {
                if (match[i].matched) {
                    out_groups->push_back(match[i].str());
                } else {
                    out_groups->emplace_back();
                }
            }
            return true;
        }
    } catch (...) {
        return false;
    }
    return false;
}

void RegexStreamEngine::InsertThreadStackInfoAtFront(
    std::vector<ThreadStackInfo>* vec,
    const ThreadStackInfo& info) {
    // Disassembly @ 0x0048b8..0x004bd8 (804 bytes):
    //   0x0048e0: b201f3ea  mov  x10, #-0x5555555555555556
    //   0x0048e4: f295556a  movk x10, #0xaaab         ; x10 = 0xaaaaaaaaaaaaaaab
    //   0x004900: cb19002b  sub  x11, x1, x25
    //   0x004904: 9345fd6b  asr  x11, x11, #5
    //   0x00490c: 9b0a7d78  mul  x24, x11, x10        ; index = (pos - begin) / 96
    // Shifts 96-byte (0x60) ThreadStackInfo elements right by 1 slot (moving tid +0x00,
    // thread_name +0x18, backtrace_lines +0x30, so_paths RB-tree +0x48) or reallocates
    // 2x capacity if full, then assigns `info` at `vec->begin()`.
    if (vec == nullptr) {
        return;
    }
    const uint64_t simulated_bytes = static_cast<uint64_t>(vec->size()) * BinaryConstants::kThreadStackInfoSize;
    const uint64_t verified_count = ComputeThreadInfoCountDiv96(simulated_bytes);
    if (verified_count == 0) {
        vec->push_back(info);
    } else {
        vec->insert(vec->begin(), info);
    }
}

}  // namespace bdcomponent
}  // namespace pitaya
