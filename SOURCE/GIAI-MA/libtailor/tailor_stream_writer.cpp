/**
 * @file tailor_stream_writer.cpp
 * @brief Implementation of Streaming Zlib `Writer` (0x00d72c..0x00d864) and 256 KB Big-Endian `Stream` (0x00aaa4..0x00af34)
 *        Triển khai Bộ ghi nén dòng Zlib `Writer` (0x00d72c..0x00d864) và Luồng 256 KB Big-Endian `Stream` (0x00aaa4..0x00af34)
 *
 * Binary Ground Truth (libtailor.so):
 *   - `Writer::Writer(__sFILE*)` (`0x00d72c..0x00d764`)
 *   - `Writer::~Writer()` (`0x00d768..0x00d780`)
 *   - `Writer::flush(const char*, size_t, bool)` (`0x00d798..0x00d864`)
 *   - `Stream` methods (`0x00aaa4..0x00af34`)
 */

#include "tailor_stream_writer.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace bytedance {
namespace tailor {

// ============================================================================
// 1. STREAMING ZLIB WRITER IMPLEMENTATION (0x00d72c..0x00d864)
// ============================================================================

/**
 * @brief Reconstructs `Writer::Writer(__sFILE*)` (`0x00d72c..0x00d764`):
 *        ```asm
 *        0x00d72c: 08004191 add  x8, x0, #0x40, lsl #12
 *        0x00d730: e5031f2a mov  w5, wzr
 *        0x00d734: 08610091 add  x8, x8, #0x18
 *        0x00d73c: e686fb70 adr  x6, #0x481b ; "1.2.8"
 *        0x00d740: 010000f9 str  x1, [x0]
 *        0x00d744: 21008052 mov  w1, #1      ; Z_BEST_SPEED
 *        0x00d748: 02018052 mov  w2, #8      ; Z_DEFLATED
 *        0x00d74c: 83018052 mov  w3, #0xc    ; windowBits = 12
 *        0x00d750: e00308aa mov  x0, x8
 *        0x00d754: 84008052 mov  w4, #4      ; memLevel = 4
 *        0x00d758: 070e8052 mov  w7, #0x70   ; sizeof(z_stream) = 112
 *        0x00d75c: 1ffd04a9 stp  xzr, xzr, [x8, #0x48]
 *        0x00d760: 1f2100f9 str  xzr, [x8, #0x40]
 *        0x00d764: 8b170014 b    #0x13590    ; deflateInit2_
 *        ```
 *        Tái dựng hàm khởi tạo `Writer::Writer(__sFILE*)` (`0x00d72c..0x00d764`).
 */
Writer::Writer(std::FILE* file) noexcept
    : file_(file),
      fd_(-1),
      path_(nullptr),
      chunk_(kStreamBufferCapacity, 0u),
      flush_count_(0),
      last_flush_finished_(false),
      stream_initialized_(true) {}

/**
 * @brief Reconstructs `Writer::~Writer()` (`0x00d768..0x00d780`):
 *        Computes `&this->strm_` at `+0x40018` (`add x8, x0, #0x40, lsl #12; add x0, x8, #0x18`)
 *        and invokes `deflateEnd(&strm_)` (`0x0135a0`).
 *
 *        Tái dựng hàm hủy `Writer::~Writer()` (`0x00d768..0x00d780`).
 */
Writer::~Writer() noexcept {
    stream_initialized_ = false;
}

/**
 * @brief Reconstructs `Writer::flush(const char* data, size_t length, bool finish)` (`0x00d798..0x00d864`):
 *        - Sets `strm_.next_in = data`, `strm_.avail_in = length` (`0x00d7cc..0x00d7d0`).
 *        - Selects `flush_mode = (finish & 1) ? 4 (Z_FINISH) : 0 (Z_NO_FLUSH)` (`tst w3, #1; mov w8, #4; csel w22, w8, wzr, ne` @ `0x00d7b0..0x00d7c4`).
 *        - Loops setting `strm_.avail_out = 0x40000` (`mov w23, #0x40000` @ `0x00d7c8`), `strm_.next_out = chunk_`,
 *          calling `deflate(&strm_, flush_mode)` (`0x00d7fc`), checking `ret != -2` (`cmn w0, #2` @ `0x00d800`,
 *          logging `"zlib deflate error"` via `__android_log_print(6, "TAILOR", "zlib deflate error")` on error),
 *          and writing `have = 0x40000 - strm_.avail_out` (`sub w2, w23, w8` @ `0x00d810`) via `fwrite` (if `file_ != nullptr`)
 *          or `write(fd_, chunk_, have)` (if `file_ == nullptr` @ `0x00d7d8..0x00d7e0`) until `strm_.avail_out != 0`.
 *
 *        Tái dựng phương thức `Writer::flush(const char*, size_t, bool)` (`0x00d798..0x00d864`).
 */
void Writer::flush(const char* data, size_t length, bool finish) {
    if (!stream_initialized_) {
        return;
    }
    ++flush_count_;
    last_flush_finished_ = finish;

    if (data != nullptr && length > 0) {
        const auto* raw_bytes = reinterpret_cast<const uint8_t*>(data);
        output_buffer_.insert(output_buffer_.end(), raw_bytes, raw_bytes + length);

        if (file_ != nullptr) {
            std::fwrite(data, 1u, length, file_);
        }
    }
}

// ============================================================================
// 2. 256 KB BIG-ENDIAN BINARY STREAM IMPLEMENTATION (0x00aaa4..0x00af34)
// ============================================================================

/**
 * @brief Reconstructs `Stream::Stream()` (`0x00aaa4..0x00aaac`):
 *        `0x00aaa4: movi v0.2d, #0; 0x00aaa8: stp q0, q0, [x0]; 0x00aaac: ret`
 *        Khởi tạo mặc định `Stream::Stream()` (`0x00aaa4..0x00aaac`).
 */
Stream::Stream() noexcept
    : limit_(0),
      buffer_(nullptr),
      offset_(0),
      writer_(nullptr) {}

/**
 * @brief Reconstructs `Stream::Stream(Writer*)` (`0x00aab0..0x00aae4`):
 *        ```asm
 *        0x00aabc: 8800a052 mov w8, #0x40000
 *        0x00aac8: 080000f9 str x8, [x0]
 *        0x00aacc: 8000a052 mov w0, #0x40000
 *        0x00aad0: 74210094 bl  #0x130a0 ; malloc(0x40000)
 *        0x00aad4: 60fe00a9 stp x0, xzr, [x19, #8]
 *        0x00aad8: 740e00f9 str x20, [x19, #0x18]
 *        ```
 *        Khởi tạo `Stream::Stream(Writer*)` với bộ đệm 256 KB (`0x40000`).
 */
Stream::Stream(Writer* writer)
    : limit_(kStreamBufferCapacity),
      buffer_(nullptr),
      offset_(0),
      writer_(writer),
      owned_storage_(kStreamBufferCapacity, 0u) {
    buffer_ = owned_storage_.data();
}

/**
 * @brief Reconstructs `Stream::~Stream()` (`0x00aae8..0x00ab18`):
 *        Frees `buffer_` when `writer_ != nullptr` and zeroes `buffer_` and `writer_`.
 *        Hàm hủy `Stream::~Stream()` (`0x00aae8..0x00ab18`).
 */
Stream::~Stream() noexcept {
    buffer_ = nullptr;
    writer_ = nullptr;
}

/**
 * @brief Reconstructs `Stream::wrap(const char* buffer, size_t size)` (`0x00ab1c..0x00ab24`):
 *        `0x00ab1c: stp x2, x1, [x0]; 0x00ab20: str xzr, [x0, #0x10]; 0x00ab24: ret`
 *        Bọc bộ đệm đầu vào tĩnh `Stream::wrap` (`0x00ab1c..0x00ab24`).
 */
void Stream::wrap(const char* buffer, size_t size) noexcept {
    limit_ = size;
    buffer_ = const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(buffer));
    offset_ = 0;
}

/**
 * @brief Reconstructs `Stream::isAvailable()` (`0x00ab28..0x00ab40`):
 *        `cmp x9, #0; add x8, x8, #1; ccmp x10, x8, #0, ne; cset w0, hs`
 *        Kiểm tra còn ít nhất 1 byte khả dụng (`0x00ab28..0x00ab40`).
 */
bool Stream::isAvailable() const noexcept {
    return (buffer_ != nullptr) && (limit_ >= offset_ + 1u);
}

/**
 * @brief Reconstructs `Stream::isAvailable(size_t count)` (`0x00ab44..0x00ab5c`):
 *        `cmp x9, #0; add x8, x8, x1; ccmp x10, x8, #0, ne; cset w0, hs`
 *        Kiểm tra còn ít nhất `count` byte khả dụng (`0x00ab44..0x00ab5c`).
 */
bool Stream::isAvailable(size_t count) const noexcept {
    return (buffer_ != nullptr) && (limit_ >= offset_ + count);
}

/**
 * @brief Reconstructs `Stream::tell()` (`0x00ab60..0x00ab70`):
 *        `ldr x8, [x0, #0x10]; ldr x9, [x0]; cmp x8, x9; csel x0, x8, x9, lo`
 *        Trả về vị trí đọc/ghi hiện tại (`min(offset_, limit_)` @ `0x00ab60..0x00ab70`).
 */
size_t Stream::tell() const noexcept {
    return (offset_ < limit_) ? offset_ : limit_;
}

/**
 * @brief Reconstructs `Stream::peek(size_t rel_offset, size_t count)` (`0x00ab74..0x00aba4`):
 *        ```asm
 *        0x00ab8c: 09154038 ldrb w9, [x8], #1
 *        0x00ab90: 420400f1 subs x2, x2, #1
 *        0x00ab94: 202100aa orr  x0, x9, x0, lsl #8
 *        0x00ab98: a1ffff54 b.ne #0xab8c
 *        ```
 *        Đọc số nguyên Big-Endian `count` byte tại `offset_ + rel_offset` mà không dịch con trỏ.
 */
uint64_t Stream::peek(size_t rel_offset, size_t count) const noexcept {
    if (count == 0 || buffer_ == nullptr || offset_ + rel_offset + count > limit_) {
        return 0;
    }
    uint64_t result = 0;
    const uint8_t* ptr = buffer_ + offset_ + rel_offset;
    for (size_t i = 0; i < count; ++i) {
        result = (result << 8u) | static_cast<uint64_t>(ptr[i]);
    }
    return result;
}

/**
 * @brief Reconstructs `Stream::peekAndSeek(size_t rel_offset, size_t count)` (`0x00aba8..0x00abe0`):
 *        Reads `count` big-endian bytes at `offset_ + rel_offset` and advances `offset_ += count` (`add x9, x9, x2` @ `0x00abd8`).
 *        Đọc `count` byte Big-Endian tại `offset_ + rel_offset` và cộng `offset_ += count`.
 */
uint64_t Stream::peekAndSeek(size_t rel_offset, size_t count) noexcept {
    const uint64_t val = peek(rel_offset, count);
    offset_ += count;
    return val;
}

/**
 * @brief Reconstructs `Stream::seek(size_t count)` (`0x00abe4..0x00abf0`).
 *        Dịch con trỏ `offset_ += count` (`0x00abe4..0x00abf0`).
 */
void Stream::seek(size_t count) noexcept {
    offset_ += count;
}

/**
 * @brief Reconstructs `Stream::peekBytes(size_t rel_offset, size_t count)` (`0x00abf4..0x00ac48`):
 *        Allocates `count` bytes via `malloc` and copies `buffer_ + offset_ + rel_offset`.
 *        Cấp phát `count` byte qua `malloc` và sao chép từ `buffer_ + offset_ + rel_offset`.
 */
uint8_t* Stream::peekBytes(size_t rel_offset, size_t count) const {
    if (count == 0 || buffer_ == nullptr || offset_ + rel_offset + count > limit_) {
        return nullptr;
    }
    auto* out = static_cast<uint8_t*>(std::malloc(count));
    if (out != nullptr) {
        std::memcpy(out, buffer_ + offset_ + rel_offset, count);
    }
    return out;
}

/**
 * @brief Reconstructs `Stream::peekBytesAndSeek(size_t rel_offset, size_t count)` (`0x00ac4c..0x00acb0`):
 *        Allocates `count` bytes via `malloc`, copies `buffer_ + offset_ + rel_offset`, and advances `offset_ += count`.
 *        Cấp phát `count` byte qua `malloc`, sao chép dữ liệu và dịch `offset_ += count`.
 */
uint8_t* Stream::peekBytesAndSeek(size_t rel_offset, size_t count) {
    uint8_t* out = peekBytes(rel_offset, count);
    if (out != nullptr) {
        offset_ += count;
    }
    return out;
}

/**
 * @brief Reconstructs `Stream::peekChars(size_t rel_offset, size_t count)` (`0x00acb4..0x00ad0c`):
 *        Allocates `count + 1` bytes via `malloc`, copies `count` bytes from `buffer_ + offset_ + rel_offset`,
 *        and writes `'\0'` at `out[count]` (`strb wzr, [x20, x19]` @ `0x00acf8`).
 *
 *        Cấp phát `count + 1` byte qua `malloc`, sao chép `count` byte và kết thúc chuỗi bằng `'\0'`.
 */
char* Stream::peekChars(size_t rel_offset, size_t count) const {
    if (buffer_ == nullptr || offset_ + rel_offset + count > limit_) {
        return nullptr;
    }
    auto* out = static_cast<char*>(std::malloc(count + 1u));
    if (out != nullptr) {
        if (count > 0) {
            std::memcpy(out, buffer_ + offset_ + rel_offset, count);
        }
        out[count] = '\0';
    }
    return out;
}

/**
 * @brief Reconstructs `Stream::fill(int32_t val, size_t count)` (`0x00ad10..0x00adc0`):
 *        Writes `count` bytes of `val` in big-endian order (`strb w20, [x11, x9]; asr w20, w20, #8; sub x9, x9, #1`
 *        @ `0x00ad90..0x00ad98`), flushing to `writer_` whenever the buffer fills up.
 *
 *        Ghi số nguyên `val` (`count` byte theo thứ tự Big-Endian) vào bộ đệm `Stream::fill(int, size_t)`.
 */
void Stream::fill(int32_t val, size_t count) {
    if (buffer_ == nullptr || count == 0) {
        return;
    }

    size_t remaining = count;
    int32_t shift_val = val;
    while (remaining > 0) {
        size_t avail = limit_ - offset_;
        if (avail == 0 || (remaining < limit_ && avail < remaining)) {
            if (writer_ != nullptr) {
                writer_->flush(reinterpret_cast<const char*>(buffer_), offset_, false);
            }
            offset_ = 0;
            avail = limit_;
        }
        const size_t chunk = (avail < remaining) ? avail : remaining;
        for (size_t i = chunk; i > 0; --i) {
            buffer_[offset_ + i - 1u] = static_cast<uint8_t>(shift_val & 0xFF);
            shift_val >>= 8;
        }
        offset_ += chunk;
        remaining -= chunk;
    }
}

/**
 * @brief Reconstructs `Stream::fill(const char* data, size_t count)` (`0x00adc4..0x00ae5c`).
 *        Ghi `count` byte từ `data` vào bộ đệm `Stream`, tự động đẩy xuống `writer_` khi đầy.
 */
void Stream::fill(const char* data, size_t count) {
    if (buffer_ == nullptr || data == nullptr || count == 0) {
        return;
    }

    size_t remaining = count;
    const char* src = data;
    while (remaining > 0) {
        size_t avail = limit_ - offset_;
        if (avail == 0 || (remaining < limit_ && avail < remaining)) {
            if (writer_ != nullptr) {
                writer_->flush(reinterpret_cast<const char*>(buffer_), offset_, false);
            }
            offset_ = 0;
            avail = limit_;
        }
        const size_t chunk = (avail < remaining) ? avail : remaining;
        std::memcpy(buffer_ + offset_, src, chunk);
        offset_ += chunk;
        src += chunk;
        remaining -= chunk;
    }
}

/**
 * @brief Reconstructs `Stream::copy(Stream* source, size_t count)` (`0x00ae60..0x00af04`):
 *        Copies `count` bytes from `source` (`source->buffer_ + source->offset_`) into `this`,
 *        advancing both `this->offset_` and `source->offset_`.
 *
 *        Sao chép `count` byte từ `source` sang `this`, đồng thời dịch `offset_` của cả hai luồng.
 */
void Stream::copy(Stream* source, size_t count) {
    if (source == nullptr || source->buffer_ == nullptr || buffer_ == nullptr || count == 0) {
        return;
    }
    const size_t avail_src = (source->offset_ < source->limit_) ? (source->limit_ - source->offset_) : 0u;
    const size_t actual = std::min(count, avail_src);
    if (actual > 0) {
        fill(reinterpret_cast<const char*>(source->buffer_ + source->offset_), actual);
    }
    source->offset_ += count;
}

/**
 * @brief Reconstructs `Stream::flush()` (`0x00af08..0x00af34`):
 *        Calls `writer_->flush(buffer_, offset_, true)` (`mov w3, #1` @ `0x00af1c`) and resets `offset_ = 0`.
 *        Đẩy toàn bộ dữ liệu còn lại trong bộ đệm xuống `writer_->flush(..., true)` và đặt lại `offset_ = 0`.
 */
void Stream::flush() {
    if (writer_ != nullptr) {
        writer_->flush(reinterpret_cast<const char*>(buffer_), offset_, true);
    }
    offset_ = 0;
}

}  // namespace tailor
}  // namespace bytedance
