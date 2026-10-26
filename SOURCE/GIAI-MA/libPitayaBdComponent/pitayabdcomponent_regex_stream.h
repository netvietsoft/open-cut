/**
 * @file pitayabdcomponent_regex_stream.h
 * @brief Reconstructed libc++ StreamBuffer, Regex NFA Engine & Container Algorithms in libPitayaBdComponent.so (Target 46).
 *        Tái tạo bộ đệm luồng libc++, động cơ NFA biểu thức chính quy và thuật toán container trong libPitayaBdComponent.so (Mục tiêu 46).
 *
 * Binary Ground Truth / Thực tế Nhị phân (.text 0x0047dc..0x01205f & .data.rel.ro 0x01b5c0..0x01bc1f):
 * - 0x0047dc (220 B): std::__ndk1::basic_string<char>::operator=(const basic_string&)
 * - 0x0048b8 (804 B): std::__ndk1::vector<ThreadStackInfo>::insert(const_iterator, const ThreadStackInfo&)
 * - 0x005044 (296 B): std::__ndk1::basic_stringbuf<char>::seekoff(off_type, ios_base::seekdir, ios_base::openmode)
 * - 0x00516c ( 20 B): std::__ndk1::basic_stringbuf<char>::seekpos(pos_type, ios_base::openmode)
 * - 0x005190 (304 B): std::__ndk1::basic_streambuf<char>::xsgetn(char*, streamsize)
 * - 0x0052c0 (176 B): std::__ndk1::basic_stringbuf<char>::underflow()
 * - 0x005370 (212 B): std::__ndk1::basic_stringbuf<char>::pbackfail(int_type)
 * - 0x005444 (604 B): std::__ndk1::basic_stringbuf<char>::overflow(int_type)
 * - 0x005b90 (192 B): ThreadStackInfo::~ThreadStackInfo() (96-byte destructor)
 * - 0x005c50 (372 B): std::__ndk1::basic_stringbuf<char>::str(const basic_string&)
 * - 0x005dc4 ( 80 B): std::__ndk1::__tree<std::string>::destroy(__tree_node*)
 * - 0x005e14 (464 B): std::__ndk1::getline(basic_istream<char>&, basic_string<char>&, char)
 * - 0x0060d4..0x00ddff: std::__ndk1::basic_regex<char> parser & NFA node builders
 * - 0x00de34 (588 B): std::__ndk1::regex_search(const char*, const char*, match_results&, const basic_regex&, match_flag_type)
 * - 0x00e080 (460 B): std::__ndk1::basic_regex<char>::__search(match_results&)
 * - 0x00e24c..0x0102a0: NFA state machine execution (__match_at_start_ecma, __push_lookahead, character classes)
 */

#ifndef NEXTAI_OPENCUT_PITAYABDCOMPONENT_REGEX_STREAM_H_
#define NEXTAI_OPENCUT_PITAYABDCOMPONENT_REGEX_STREAM_H_

#include "pitayabdcomponent_types.h"

#include <cstddef>
#include <cstdint>
#include <ios>
#include <string>
#include <vector>

namespace pitaya {
namespace bdcomponent {

// ============================================================================
// 1. Reconstructed NDK basic_stringbuf<char> (seekoff @ 0x005044, overflow @ 0x005444)
//    Tái tạo NDK basic_stringbuf<char> (seekoff @ 0x005044, overflow @ 0x005444)
// ============================================================================
/**
 * Mirrors the exact pointer layout of std::__ndk1::basic_stringbuf<char> in libPitayaBdComponent.so:
 * - +0x00: vptr (_ZTVNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEEE @ 0x01b660)
 * - +0x08: locale (8B)
 * - +0x10: __binp_ (eback, 8B)
 * - +0x18: __ninp_ (gptr,  8B)
 * - +0x20: __einp_ (egptr, 8B)
 * - +0x28: __bout_ (pbase, 8B)
 * - +0x30: __nout_ (pptr,  8B)
 * - +0x38: __eout_ (epptr, 8B)
 * - +0x40..+0x57: __str_ (24B std::string buffer)
 * - +0x58: __hm_ (high-water mark char* pointer, 8B — see 0x005044: ldr x8, [x0, #0x58])
 * - +0x60: __mode_ (ios_base::openmode, 4B)
 */
class NdkStringBuf {
public:
    explicit NdkStringBuf(std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
    explicit NdkStringBuf(const std::string& initial_str,
                          std::ios_base::openmode mode = std::ios_base::in);
    ~NdkStringBuf() = default;

    /**
     * Sets the underlying buffer content and resets get/put pointers.
     * Thiết lập nội dung bộ đệm bên dưới và đặt lại các con trỏ đọc/ghi.
     * Disassembly @ 0x005c50..0x005dc0 (372 bytes).
     */
    void SetStr(const std::string& s);

    /**
     * Returns the current buffer string from [pbase..hm) or [eback..egptr).
     * Trả về chuỗi bộ đệm hiện tại từ [pbase..hm) hoặc [eback..egptr).
     */
    std::string GetStr() const;

    /**
     * Repositions the input/output sequence pointers relative to beg/cur/end.
     * Định vị lại con trỏ chuỗi đầu vào/đầu ra tương ứng với beg/cur/end.
     * Disassembly @ 0x005044..0x005168 (296 bytes).
     */
    int64_t SeekOff(int64_t off, std::ios_base::seekdir way, std::ios_base::openmode which);

    /**
     * Repositions to an absolute offset via SeekOff(sp, ios_base::beg, which).
     * Định vị tới độ lệch tuyệt đối qua SeekOff(sp, ios_base::beg, which).
     * Disassembly @ 0x00516c..0x00517c (20 bytes).
     */
    int64_t SeekPos(int64_t sp, std::ios_base::openmode which);

    /**
     * Reads up to n characters from the input sequence into s.
     * Đọc tối đa n ký tự từ chuỗi đầu vào vào bộ đệm s.
     * Disassembly @ 0x005190..0x0052bc (304 bytes).
     */
    std::streamsize Xsgetn(char* s, std::streamsize n);

    /**
     * Handles input buffer underflow by advancing high-water mark if pptr > hm.
     * Xử lý cạn bộ đệm đầu vào bằng cách đẩy mốc nước cao nếu pptr > hm.
     * Disassembly @ 0x0052c0..0x00536c (176 bytes).
     */
    int Underflow();

    /**
     * Puts a character back into the input sequence.
     * Đẩy ngược một ký tự vào chuỗi đầu vào.
     * Disassembly @ 0x005370..0x005440 (212 bytes).
     */
    int Pbackfail(int c);

    /**
     * Appends character c to the output sequence, growing buffer capacity when needed.
     * Nối ký tự c vào chuỗi đầu ra, mở rộng dung lượng bộ đệm khi cần thiết.
     * Disassembly @ 0x005444..0x00569c (604 bytes).
     */
    int Overflow(int c);

private:
    void SyncPointersAfterResize(ptrdiff_t in_off, ptrdiff_t out_off, ptrdiff_t hm_off);

    std::string storage_;
    char* binp_ = nullptr;  // +0x10
    char* ninp_ = nullptr;  // +0x18
    char* einp_ = nullptr;  // +0x20
    char* bout_ = nullptr;  // +0x28
    char* nout_ = nullptr;  // +0x30
    char* eout_ = nullptr;  // +0x38
    char* hm_   = nullptr;  // +0x58
    std::ios_base::openmode mode_; // +0x60
};

// ============================================================================
// 2. RegexStreamEngine (getline @ 0x005e14, regex_search @ 0x00de34, vector::insert @ 0x0048b8)
//    Động cơ luồng & biểu thức chính quy RegexStreamEngine
// ============================================================================
class RegexStreamEngine {
public:
    explicit RegexStreamEngine(const std::string& input);
    ~RegexStreamEngine() = default;

    /**
     * Extracts a line delimited by delim (default '\n' = 0x0a @ 0x002c64: mov w1, #0xa).
     * Trích xuất một dòng phân cách bởi delim (mặc định '\n' = 0x0a @ 0x002c64: mov w1, #0xa).
     * Disassembly @ 0x005e14..0x005fe0 (464 bytes).
     */
    bool GetLine(std::string* out_line, char delim = '\n');

    /**
     * Executes ECMAScript regex_search and populates capture groups (group[0] = full match, group[1..N] = submatches).
     * Thực thi tìm kiếm biểu thức chính quy ECMAScript và điền các nhóm bắt giữ (group[0] = toàn bộ, group[1..N] = nhóm con).
     * Disassembly @ 0x0060d4 (basic_regex ctor), 0x00de34 (regex_search), 0x00e080 (__search).
     */
    static bool RegexSearchGroups(const std::string& input,
                                  const char* pattern,
                                  std::vector<std::string>* out_groups);

    /**
     * Computes the number of 24-byte sub_match elements from byte span using the exact AArch64
     * multiplicative inverse instruction sequence at 0x002e54..0x002e68:
     *   sub x8, x8, x9
     *   asr x8, x8, #3
     *   mul x8, x8, x10   (where x10 = 0xaaaaaaaaaaaaaaabULL = -0x5555555555555555)
     * Tính số lượng phần tử sub_match 24-byte từ khoảng cách byte bằng đúng chuỗi lệnh
     * nghịch đảo nhân AArch64 tại 0x002e54..0x002e68.
     */
    static uint64_t ComputeSubMatchCountDiv24(uint64_t byte_diff) noexcept {
        const int64_t shifted = static_cast<int64_t>(byte_diff) >> 3;
        return static_cast<uint64_t>(shifted) * BinaryConstants::kMagicMulInv3;
    }

    /**
     * Computes the number of 96-byte (0x60) ThreadStackInfo elements from byte span using the exact
     * AArch64 multiplicative inverse instruction sequence at 0x0048e0..0x00490c:
     *   sub x11, x1, x25
     *   asr x11, x11, #5
     *   mul x24, x11, x10 (where x10 = 0xaaaaaaaaaaaaaaabULL)
     * Tính số lượng phần tử ThreadStackInfo 96-byte (0x60) từ khoảng cách byte bằng đúng chuỗi lệnh
     * nghịch đảo nhân AArch64 tại 0x0048e0..0x00490c.
     */
    static uint64_t ComputeThreadInfoCountDiv96(uint64_t byte_diff) noexcept {
        const int64_t shifted = static_cast<int64_t>(byte_diff) >> 5;
        return static_cast<uint64_t>(shifted) * BinaryConstants::kMagicMulInv3;
    }

    /**
     * Inserts a 96-byte ThreadStackInfo at the front of the vector (used for "pty-ord-t" Pitaya threads).
     * Chèn một cấu trúc ThreadStackInfo 96-byte vào đầu vector (dùng cho các luồng Pitaya "pty-ord-t").
     * Disassembly @ 0x0048b8..0x004bd8 (804 bytes).
     */
    static void InsertThreadStackInfoAtFront(
        std::vector<ThreadStackInfo>* vec,
        const ThreadStackInfo& info);

private:
    NdkStringBuf buf_;
    bool eof_ = false;
};

}  // namespace bdcomponent
}  // namespace pitaya

#endif  // NEXTAI_OPENCUT_PITAYABDCOMPONENT_REGEX_STREAM_H_
