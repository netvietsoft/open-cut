/**
 * @file bdzstd_types.h
 * @brief ByteDance Zstandard Compression Engine - ABI Types, Enums & Structs.
 *        Kiểu dữ liệu ABI, hằng số nhị phân và cấu trúc ngữ cảnh của libbdzstd.so.
 *
 * Reconstructed Cleanroom Implementation based on CapCut AArch64 binary analysis.
 * Tái dựng sạch dựa trên phân tích nhị phân AArch64 của CapCut.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary proof).
 */

#ifndef BDZSTD_TYPES_H
#define BDZSTD_TYPES_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <atomic>
#include <mutex>

namespace bytedance {
namespace compression {
namespace zstd {

// ============================================================================
// 1. ZSTANDARD BINARY CONSTANTS & MAGIC NUMBERS
//    Hằng số nhị phân và giá trị nhận diện Zstandard
// ============================================================================

/** @brief Standard Zstandard Frame Magic Number (0xFD2FB528 / Little-endian: 28 B5 2F FD) */
constexpr uint32_t ZSTD_MAGICNUMBER = 0xFD2FB528U;

/** @brief Standard Zstandard Dictionary Magic Number (0xEC30A437 / Little-endian: 37 A4 30 EC) */
constexpr uint32_t ZSTD_MAGIC_DICTIONARY = 0xEC30A437U;

/** @brief Zstandard Skippable Frame Magic Range Start (0x184D2A50) */
constexpr uint32_t ZSTD_MAGIC_SKIPPABLE_START = 0x184D2A50U;
constexpr uint32_t ZSTD_MAGIC_SKIPPABLE_MASK  = 0xFFFFFFF0U;

/** @brief Default and extreme compression levels in ByteDance ZSTD */
constexpr int32_t ZSTD_MIN_COMPRESSION_LEVEL     = -131072; // -0x20000 (AArch64: mov w0, #-0x20000)
constexpr int32_t ZSTD_MAX_COMPRESSION_LEVEL     = 22;      // 0x16     (AArch64: mov w0, #0x16)
constexpr int32_t ZSTD_DEFAULT_COMPRESSION_LEVEL = 3;       // 0x03     (AArch64: mov w0, #3)

/** @brief Error code thresholds and special error numbers (AArch64: cmn x, #0x78) */
constexpr size_t ZSTD_ERROR_THRESHOLD = 0x78; // 120
constexpr int64_t ZSTD_ERR_GENERIC    = 1;
constexpr int64_t ZSTD_ERR_DST_SIZE_TOO_SMALL = -72; // -0x48 (AArch64: mov x22, #-0x48)

/** @brief Stripped error message string in libbdzstd.so (.rodata offset 0x31d7c) */
constexpr const char* ZSTD_STRIPPED_ERROR_STRING = "Error strings stripped";

/** @brief Buffer sizes recommended by ByteDance streaming engine */
constexpr size_t ZSTD_BLOCKSIZE_MAX         = 131072; // 128 KB
constexpr size_t ZSTD_RECOMMENDED_COUT_SIZE = 131591; // 128 KB + 519 (0x207 + (2 << 16))
constexpr size_t ZSTD_RECOMMENDED_DIN_SIZE  = 131075; // 128 KB + 3   (3 + (2 << 16))
constexpr size_t ZSTD_RECOMMENDED_DOUT_SIZE = 131072; // 128 KB       (0x20000)

/** @brief Fixed allocation size for ZstdCompressCtx wrapper structure (0x030410: mov w0, #0xdf8) */
constexpr size_t ZSTD_COMPRESS_CTX_ALLOC_SIZE = 3576; // 0xdf8 bytes

// ============================================================================
// 2. ENUMS & PARAMETER IDENTIFIERS
//    Định danh tham số cấu hình Zstandard
// ============================================================================

/**
 * @brief ZSTD Compression Parameters / Tham số nén ZSTD
 */
enum class ZstdCParameter : int32_t {
    CompressionLevel          = 100, // ZSTD_c_compressionLevel
    WindowLog                 = 101, // ZSTD_c_windowLog
    HashLog                   = 102, // ZSTD_c_hashLog
    ChainLog                  = 103, // ZSTD_c_chainLog
    SearchLog                 = 104, // ZSTD_c_searchLog
    MinMatch                  = 105, // ZSTD_c_minMatch
    TargetLength              = 106, // ZSTD_c_targetLength
    Strategy                  = 107, // ZSTD_c_strategy
    ContentSizeFlag           = 200, // ZSTD_c_contentSizeFlag
    ChecksumFlag              = 201, // ZSTD_c_checksumFlag
    DictIDFlag                = 202, // ZSTD_c_dictIDFlag
    NbWorkers                 = 400, // ZSTD_c_nbWorkers
    JobSize                   = 401, // ZSTD_c_jobSize
    OverlapLog                = 402  // ZSTD_c_overlapLog
};

/**
 * @brief ZSTD Compression Strategy / Chiến lược nén
 */
enum class ZstdStrategy : int32_t {
    Fast    = 1,
    DrmFast = 2,
    Greedy  = 3,
    Lazy    = 4,
    Lazy2   = 5,
    Btlazy2 = 6,
    Btopt   = 7,
    Btultra = 8,
    Btultra2 = 9
};

/**
 * @brief Streaming Flush Directives / Chỉ thị xả dữ liệu dòng nén
 */
enum class ZstdEndDirective : int32_t {
    Continue = 0, // Tiếp tục nạp dữ liệu
    Flush    = 1, // Xả dữ liệu ra output nhưng chưa đóng frame
    End      = 2  // Kết thúc frame và ghi checksum
};

// ============================================================================
// 3. STREAMING BUFFER STRUCTURES (ABI MATCHING C ZSTD)
//    Cấu trúc buffer dòng (Tương thích nhị phân với ZSTD C API)
// ============================================================================

/**
 * @brief ZSTD_inBuffer: Input stream tracking structure.
 *        Cấu trúc theo dõi bộ đệm đầu vào.
 */
struct ZSTD_inBuffer {
    const void* src;  /**< Pointer to start of input buffer / Con trỏ đầu vào */
    size_t      size; /**< Total byte size of input buffer / Kích thước tổng */
    size_t      pos;  /**< Current read position / Vị trí đọc hiện tại */
};

/**
 * @brief ZSTD_outBuffer: Output stream tracking structure.
 *        Cấu trúc theo dõi bộ đệm đầu ra.
 */
struct ZSTD_outBuffer {
    void*  dst;  /**< Pointer to start of output buffer / Con trỏ đầu ra */
    size_t size; /**< Maximum capacity of output buffer / Dung lượng tối đa */
    size_t pos;  /**< Current write position / Vị trí ghi hiện tại */
};

// ============================================================================
// 4. COMPRESS CONTEXT NATIVE LAYOUT (0xdf8 / 3,576 BYTES)
//    Bố cục bộ nhớ ngữ cảnh nén gốc (khớp chính xác AArch64 offsets)
// ============================================================================

#pragma pack(push, 8)
/**
 * @brief Native layout matching the 3,576-byte buffer allocated at 0x030410.
 *        Bố cục bộ nhớ chuẩn xác của struct C++ trong libbdzstd.so.
 */
struct ZstdCompressCtxNative {
    void*     vtable;             /**< 0x00: Optional internal table pointer */
    uint32_t  modified_flags;     /**< 0x04: Bitmask of altered parameter states */
    uint8_t   pad_08_30[0x28];    /**< 0x08 - 0x2F: Internal workspace pointers */
    uint32_t  contentSizeFlag;    /**< 0x30: Emit content size in frame header (1/0) */
    uint32_t  checksumFlag;       /**< 0x34: Emit XXH64 checksum at frame end (1/0) */
    uint32_t  dictIDFlag;         /**< 0x38: Emit dictionary ID in frame header (1/0) */
    int32_t   compressionLevel;   /**< 0x3C: Clamped level [-131072, 22], fallback 3 */
    uint64_t  pledgedSrcSize;     /**< 0x40: Expected input size announced in advance */
    uint8_t   pad_48_d80[0xd38];  /**< 0x48 - 0xd7F: Hash table, match finder, entropy */
    uint32_t  state_flags;        /**< 0xd80: Context initialization state / status */
    uint8_t   pad_d84_df8[0x74];  /**< 0xd84 - 0xdf7: Trailing alignment padding (total 3576B) */
};
#pragma pack(pop)

// Verify exact struct layout constraints at compile time
static_assert(sizeof(ZstdCompressCtxNative) == ZSTD_COMPRESS_CTX_ALLOC_SIZE,
              "ZstdCompressCtxNative size must match 0xdf8 (3576 bytes) exactly!");
static_assert(offsetof(ZstdCompressCtxNative, contentSizeFlag) == 0x30,
              "contentSizeFlag must be at offset 0x30!");
static_assert(offsetof(ZstdCompressCtxNative, checksumFlag) == 0x34,
              "checksumFlag must be at offset 0x34!");
static_assert(offsetof(ZstdCompressCtxNative, dictIDFlag) == 0x38,
              "dictIDFlag must be at offset 0x38!");
static_assert(offsetof(ZstdCompressCtxNative, compressionLevel) == 0x3C,
              "compressionLevel must be at offset 0x3C!");
static_assert(offsetof(ZstdCompressCtxNative, state_flags) == 0xd80,
              "state_flags must be at offset 0xd80!");

// ============================================================================
// 5. DECOMPRESS CONTEXT NATIVE LAYOUT
//    Bố cục bộ nhớ ngữ cảnh giải nén gốc
// ============================================================================

struct ZstdDecompressCtxNative {
    void*     vtable;             /**< Internal state / table pointer */
    uint32_t  state;              /**< Decompressor state machine tracker */
    uint32_t  dictID;             /**< Loaded dictionary ID */
    uint64_t  frameContentSize;   /**< Uncompressed size read from frame header */
    uint64_t  currentProcessed;   /**< Number of uncompressed bytes produced */
    uint32_t  checksum;           /**< Running XXH64 / 32 checksum */
    uint32_t  flags;              /**< Decompression flags */
    std::vector<uint8_t> dictBuffer; /**< Custom dictionary buffer */
};

// ============================================================================
// 6. DICTIONARY STRUCTURES (CDict & DDict)
//    Cấu trúc từ điển nén và giải nén
// ============================================================================

struct ZstdDictCompressNative {
    uint32_t dictID;
    int32_t  compressionLevel;
    std::vector<uint8_t> dictData;
    std::vector<uint32_t> customHashTab;
};

struct ZstdDictDecompressNative {
    uint32_t dictID;
    std::vector<uint8_t> dictData;
    std::vector<uint16_t> fseTable;
};

// ============================================================================
// 7. STREAM CONTEXT WRAPPER STRUCTURES
//    Cấu trúc bao gói dòng nén/giải nén không cần finalizer
// ============================================================================

struct ZstdStreamNative {
    bool isCompressor;
    std::unique_ptr<ZstdCompressCtxNative> cctx;
    std::unique_ptr<ZstdDecompressCtxNative> dctx;
    std::vector<uint8_t> internalBuffer;
    size_t internalPos;
    std::mutex streamLock;
};

} // namespace zstd
} // namespace compression
} // namespace bytedance

#endif // BDZSTD_TYPES_H
