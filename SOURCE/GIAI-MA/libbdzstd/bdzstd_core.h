/**
 * @file bdzstd_core.h
 * @brief ByteDance Zstandard Engine - Core Compression & Decompression Algorithms.
 *        Thuật toán nén/giải nén cốt lõi của Zstandard: FSE, Huffman, Block & Frame.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDZSTD_CORE_H
#define BDZSTD_CORE_H

#include "bdzstd_types.h"
#include <vector>
#include <string>
#include <cstdint>
#include <cstddef>

namespace bytedance {
namespace compression {
namespace zstd {

/**
 * @brief Block Types in Zstandard frame specification
 *        Các loại khối dữ liệu trong tiêu chuẩn khung Zstandard
 */
enum class ZstdBlockType : uint8_t {
    Raw        = 0, /**< Khối dữ liệu thô không nén (Uncompressed) */
    RLE        = 1, /**< Khối lặp lại một byte duy nhất (Run-length encoded) */
    Compressed = 2, /**< Khối nén Entropy FSE + Huffman */
    Reserved   = 3  /**< Dành riêng (Không dùng) */
};

/**
 * @brief ZstdCoreEngine: Pure Cleanroom Implementation of Zstandard core logic.
 *        Bộ máy tính toán giải thuật nén/giải nén Zstandard sạch.
 */
class ZstdCoreEngine {
public:
    // ========================================================================
    // MATHEMATICAL & BINARY CONVERSION UTILITIES
    // Các tiện ích toán học và chuyển đổi nhị phân khớp opcode AArch64
    // ========================================================================

    /**
     * @brief Computes maximum compressed bound for given source size.
     *        Tính chặn trên kích thước dữ liệu nén theo đúng công thức opcode:
     *        bound = srcSize + (srcSize >> 8) + (srcSize < 128KB ? ((128KB - srcSize) >> 11) : 0)
     *        Opcode AArch64 tại 0x006750 và 0x0303b0:
     *        mov w9, #0x20000; sub x9, x9, x0; lsr x9, x9, #0xb;
     *        cmp x0, #0x20, lsl #12; add x8, x0, x0, lsr #8;
     *        csel x9, x9, xzr, lo; add x0, x8, x9; ret
     */
    static size_t compressBound(size_t srcSize) noexcept;

    /**
     * @brief Determines if return code indicates a Zstandard error.
     *        Kiểm tra mã trả về có phải lỗi không. Khớp opcode:
     *        0x0040f8: cmn x0, #0x78; cset w0, hi; ret
     */
    static bool isError(size_t code) noexcept;

    /**
     * @brief Extracts normalized error code from signed/unsigned error value.
     *        Trích xuất mã lỗi chuẩn hóa. Khớp opcode:
     *        0x02fc60: neg w8, w2; cmn x2, #0x77; csel x0, xzr, x8, lo; ret
     */
    static size_t getErrorCode(size_t code) noexcept;

    /**
     * @brief Stripped error name resolver. Always returns "Error strings stripped"
     *        Trả về tên lỗi bị lược bỏ (.rodata offset 0x31d7c).
     */
    static const char* getErrorName(size_t code) noexcept;

    // ========================================================================
    // CHECKSUM ALGORITHM (xxHash64 32-bit truncation)
    // Giải thuật kiểm tra tính toàn vẹn frame bằng xxHash64
    // ========================================================================
    static uint32_t computeXXH32(const void* data, size_t length, uint32_t seed = 0) noexcept;
    static uint64_t computeXXH64(const void* data, size_t length, uint64_t seed = 0) noexcept;

    // ========================================================================
    // COMPRESSION & DECOMPRESSION WORKFLOWS
    // Các luồng nén và giải nén khối hoàn chỉnh
    // ========================================================================

    /**
     * @brief Compresses input buffer into a complete single Zstandard frame.
     *        Nén bộ đệm đầu vào thành một khung Zstandard hoàn chỉnh.
     */
    static size_t compressFrame(const ZstdCompressCtxNative& ctx,
                               void* dst, size_t dstCapacity,
                               const void* src, size_t srcSize,
                               const std::vector<uint8_t>& dict);

    /**
     * @brief Decompresses a complete Zstandard frame into output buffer.
     *        Giải nén một khung Zstandard hoàn chỉnh vào bộ đệm đầu ra.
     */
    static size_t decompressFrame(ZstdDecompressCtxNative& ctx,
                                 void* dst, size_t dstCapacity,
                                 const void* src, size_t srcSize,
                                 const std::vector<uint8_t>& dict);

    /**
     * @brief Inspects frame header to discover uncompressed content size.
     *        Đọc kích thước gốc từ tiêu đề khung Zstandard.
     */
    static uint64_t getDecompressedSize(const void* src, size_t srcSize) noexcept;

    // ========================================================================
    // FINITE STATE ENTROPY & HUFFMAN ENGINE
    // Bộ mã hóa trạng thái hữu hạn FSE & Huffman
    // ========================================================================
    static size_t encodeFSEBlock(const uint8_t* src, size_t srcSize,
                                 uint8_t* dst, size_t dstCapacity);
    static size_t decodeFSEBlock(const uint8_t* src, size_t srcSize,
                                 uint8_t* dst, size_t dstCapacity);

    static size_t encodeRLEBlock(uint8_t symbol, size_t runLength,
                                 uint8_t* dst, size_t dstCapacity);
};

} // namespace zstd
} // namespace compression
} // namespace bytedance

#endif // BDZSTD_CORE_H
