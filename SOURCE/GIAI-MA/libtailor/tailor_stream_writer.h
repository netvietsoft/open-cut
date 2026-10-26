/**
 * @file tailor_stream_writer.h
 * @brief Streaming Zlib Deflate `Writer` (0x00d72c..0x00d864) and 256 KB Big-Endian `Stream` (0x00aaa4..0x00af34)
 *        Bộ ghi nén dòng Zlib `Writer` (0x00d72c..0x00d864) và Luồng 256 KB Big-Endian `Stream` (0x00aaa4..0x00af34)
 *
 * Binary Ground Truth (libtailor.so):
 *   - `Writer::Writer(__sFILE*)` (`0x00d72c..0x00d764`: `add x8, x0, #0x40, lsl #12; add x8, x8, #0x18; deflateInit2_(..., 1, 8, 12, 4, 0, "1.2.8", 0x70)`)
 *   - `Writer::~Writer()` (`0x00d768..0x00d780`: calls `deflateEnd(&strm)`)
 *   - `Writer::flush(const char*, size_t, bool)` (`0x00d798..0x00d864`: loops `deflate(&strm, finish ? Z_FINISH(4) : Z_NO_FLUSH(0))` into 256 KB `chunk`)
 *   - `Stream` (`32 bytes = 0x20` @ `0x00aaa4..0x00af34`: `Stream()`, `Stream(Writer*)`, `~Stream()`, `wrap`, `isAvailable`, `tell`, `peek`, `peekAndSeek`, `seek`, `peekBytes`, `peekBytesAndSeek`, `peekChars`, `fill(int, size_t)`, `fill(const char*, size_t)`, `copy(Stream*, size_t)`, `flush()`)
 */

#ifndef OPENCUT_TAILOR_STREAM_WRITER_H_
#define OPENCUT_TAILOR_STREAM_WRITER_H_

#include "tailor_types.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <vector>

namespace bytedance {
namespace tailor {

// ============================================================================
// 1. STREAMING ZLIB WRITER (0x00d72c..0x00d864, sizeof = 0x40088 = 262,280 B)
// ============================================================================

/**
 * @brief Reconstructs `Writer` (`0x00d72c..0x00d864`, `262,280 bytes = 0x40088` allocated at `0x00dc70..0x00dc74`):
 *        - `+0x00000`: `FILE* file_` (`str x1, [x0]` @ `0x00d740`)
 *        - `+0x00008`: `int32_t fd_` (`str w0, [x8, #8]` in `open_proxy` @ `0x00dabc`)
 *        - `+0x00010`: `const char* path_` (`str x0, [x8, #0x10]` in `open_tailor` @ `0x00dcb0`)
 *        - `+0x00018`: `char chunk_[0x40000]` (`262,144 bytes = 256 KB`)
 *        - `+0x40018`: `z_stream strm_` (`112 bytes = 0x70`) initialized via:
 *          `deflateInit2_(&strm_, Z_BEST_SPEED=1, Z_DEFLATED=8, windowBits=12, memLevel=4, Z_DEFAULT_STRATEGY=0, "1.2.8", 0x70)`
 *
 *        Tái dựng lớp `Writer` (`0x00d72c..0x00d864`, `262,280 bytes = 0x40088` cấp phát tại `0x00dc70..0x00dc74`).
 */
class Writer {
public:
    static constexpr int32_t kZlibCompressionLevel = 1;     // Z_BEST_SPEED (@ 0x00d744: mov w1, #1)
    static constexpr int32_t kZlibMethodDeflated   = 8;     // Z_DEFLATED (@ 0x00d748: mov w2, #8)
    static constexpr int32_t kZlibWindowBits       = 12;    // 0x0c (@ 0x00d74c: mov w3, #0xc)
    static constexpr int32_t kZlibMemLevel         = 4;     // 4 (@ 0x00d754: mov w4, #4)
    static constexpr int32_t kZlibStrategyDefault  = 0;     // Z_DEFAULT_STRATEGY (@ 0x00d730: mov w5, wzr)
    static constexpr int32_t kZlibNoFlush          = 0;     // Z_NO_FLUSH (@ 0x00d7c4)
    static constexpr int32_t kZlibFinish           = 4;     // Z_FINISH (@ 0x00d7b8: mov w8, #4)
    static constexpr int32_t kZlibStreamError      = -2;    // Z_STREAM_ERROR (@ 0x00d800: cmn w0, #2)

    explicit Writer(std::FILE* file = nullptr) noexcept;
    ~Writer() noexcept;

    /**
     * @brief Reconstructs `_ZN6Writer5flushEPKcmb` (`0x00d798..0x00d864`):
     *        Feeds `data[0..length)` into `strm_` (`flush_mode = finish ? 4 : 0`), writing output chunks
     *        to `file_` (`fwrite` @ `0x00d820`) or `fd_` (`write` @ `0x00d7e0`) and accumulating into `output_buffer_`.
     *
     *        Tái dựng `_ZN6Writer5flushEPKcmb` (`0x00d798..0x00d864`).
     */
    void flush(const char* data, size_t length, bool finish);

    void setFd(int32_t fd) noexcept { fd_ = fd; }
    int32_t fd() const noexcept { return fd_; }

    void setPath(const char* path) noexcept { path_ = path; }
    const char* path() const noexcept { return path_; }

    const std::vector<uint8_t>& outputBuffer() const noexcept { return output_buffer_; }
    uint32_t flushCount() const noexcept { return flush_count_; }
    bool lastFlushFinished() const noexcept { return last_flush_finished_; }

private:
    std::FILE* file_;
    int32_t fd_;
    const char* path_;
    std::vector<uint8_t> chunk_;
    std::vector<uint8_t> output_buffer_;
    uint32_t flush_count_;
    bool last_flush_finished_;
    bool stream_initialized_;
};

// ============================================================================
// 2. 256 KB BIG-ENDIAN BINARY STREAM (0x00aaa4..0x00af34, sizeof = 32 B = 0x20)
// ============================================================================

/**
 * @brief Reconstructs `Stream` (`32 bytes = 0x20` @ `0x00aaa4..0x00af34`):
 *        - `+0x00`: `size_t limit_` (`0x40000` when constructed with `Writer*` @ `0x00aabc`)
 *        - `+0x08`: `uint8_t* buffer_` (`malloc(0x40000)` @ `0x00aad0` or wrapped pointer @ `0x00ab1c`)
 *        - `+0x10`: `size_t offset_` (`0` on init/flush)
 *        - `+0x18`: `Writer* writer_` (`nullptr` for input stream, `pWriter` for output stream)
 *
 *        Tái dựng lớp `Stream` (`32 bytes = 0x20` tại `0x00aaa4..0x00af34`).
 */
class Stream {
public:
    /** @brief `_ZN6StreamC1Ev` (`0x00aaa4..0x00aaac`: zeroes 32 bytes via `movi v0.2d, #0; stp q0, q0, [x0]`). */
    Stream() noexcept;

    /** @brief `_ZN6StreamC1EP6Writer` (`0x00aab0..0x00aae4`: allocates `0x40000` buffer and binds `writer`). */
    explicit Stream(Writer* writer);

    /** @brief `_ZN6StreamD1Ev` (`0x00aae8..0x00ab18`: frees `buffer_` if `writer_ != nullptr`). */
    ~Stream() noexcept;

    Stream(const Stream&) = delete;
    Stream& operator=(const Stream&) = delete;

    /** @brief `_ZN6Stream4wrapEPKcm` (`0x00ab1c..0x00ab24`: `stp x2, x1, [x0]; str xzr, [x0, #0x10]`). */
    void wrap(const char* buffer, size_t size) noexcept;

    /** @brief `_ZN6Stream11isAvailableEv` (`0x00ab28..0x00ab40`: `buffer_ != nullptr && limit_ >= offset_ + 1`). */
    bool isAvailable() const noexcept;

    /** @brief `_ZN6Stream11isAvailableEm` (`0x00ab44..0x00ab5c`: `buffer_ != nullptr && limit_ >= offset_ + count`). */
    bool isAvailable(size_t count) const noexcept;

    /** @brief `_ZN6Stream4tellEv` (`0x00ab60..0x00ab70`: `csel x0, x8, x9, lo` = `min(offset_, limit_)`). */
    size_t tell() const noexcept;

    /**
     * @brief `_ZN6Stream4peekEmm` (`0x00ab74..0x00aba4`):
     *        Reads `count` big-endian bytes starting at `offset_ + rel_offset`:
     *        `ldrb w9, [x8], #1; subs x2, x2, #1; orr x0, x9, x0, lsl #8; b.ne` (`0x00ab8c..0x00ab98`).
     */
    uint64_t peek(size_t rel_offset, size_t count) const noexcept;

    /**
     * @brief `_ZN6Stream11peekAndSeekEmm` (`0x00aba8..0x00abe0`):
     *        Reads `count` big-endian bytes starting at `offset_ + rel_offset` and advances `offset_ += count`.
     */
    uint64_t peekAndSeek(size_t rel_offset, size_t count) noexcept;

    /** @brief `_ZN6Stream4seekEm` (`0x00abe4..0x00abf0`: `offset_ += count`). */
    void seek(size_t count) noexcept;

    /**
     * @brief `_ZN6Stream9peekBytesEmm` (`0x00abf4..0x00ac48`):
     *        Allocates `count` bytes via `malloc` and copies `buffer_ + offset_ + rel_offset`.
     */
    uint8_t* peekBytes(size_t rel_offset, size_t count) const;

    /**
     * @brief `_ZN6Stream16peekBytesAndSeekEmm` (`0x00ac4c..0x00acb0`):
     *        Allocates `count` bytes via `malloc`, copies `buffer_ + offset_ + rel_offset`, and advances `offset_ += count`.
     */
    uint8_t* peekBytesAndSeek(size_t rel_offset, size_t count);

    /**
     * @brief `_ZN6Stream9peekCharsEmm` (`0x00acb4..0x00ad0c`):
     *        Allocates `count + 1` bytes via `malloc`, copies `buffer_ + offset_ + rel_offset`, and null-terminates (`strb wzr, [x20, x19]`).
     */
    char* peekChars(size_t rel_offset, size_t count) const;

    /**
     * @brief `_ZN6Stream4fillEim` (`0x00ad10..0x00adc0`):
     *        Writes `count` big-endian bytes of `val` into `buffer_` (`strb w20, [x11, x9]; asr w20, w20, #8` @ `0x00ad90..0x00ad94`),
     *        flushing to `writer_` (`finish = false`) whenever `limit_ - offset_ < count`.
     */
    void fill(int32_t val, size_t count);

    /**
     * @brief `_ZN6Stream4fillEPKcm` (`0x00adc4..0x00ae5c`):
     *        Appends `count` raw bytes from `data` into `buffer_`, flushing to `writer_` when full.
     */
    void fill(const char* data, size_t count);

    /**
     * @brief `_ZN6Stream4copyEPS_m` (`0x00ae60..0x00af04`):
     *        Copies `count` bytes from `source` (`source->buffer_ + source->offset_`) into `this`,
     *        advancing both `this->offset_` and `source->offset_` (`0x00aee0..0x00aef0`).
     */
    void copy(Stream* source, size_t count);

    /**
     * @brief `_ZN6Stream5flushEv` (`0x00af08..0x00af34`):
     *        Calls `writer_->flush(buffer_, offset_, true)` (`mov w3, #1` @ `0x00af1c`) and resets `offset_ = 0`.
     */
    void flush();

    size_t limit() const noexcept { return limit_; }
    const uint8_t* buffer() const noexcept { return buffer_; }
    size_t offset() const noexcept { return offset_; }
    Writer* writer() const noexcept { return writer_; }

private:
    size_t limit_;
    uint8_t* buffer_;
    size_t offset_;
    Writer* writer_;
    std::vector<uint8_t> owned_storage_;
};

}  // namespace tailor
}  // namespace bytedance

#endif  // OPENCUT_TAILOR_STREAM_WRITER_H_
