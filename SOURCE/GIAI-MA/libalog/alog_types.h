/**
 * @file alog_types.h
 * @brief ByteDance ALog Native Types and Data Structures Definition.
 *        Định nghĩa các kiểu dữ liệu và cấu trúc nền tảng cho hệ thống ALog ByteDance.
 *
 * Reconstructed from libalog.so (ByteDance Asynchronous Native Logger Engine).
 * Tái cấu trúc sạch từ thư viện nhị phân libalog.so của CapCut / ByteDance.
 */

#ifndef BYTEDANCE_ALOG_TYPES_H
#define BYTEDANCE_ALOG_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// HẰNG SỐ & PHÂN LOẠI CẤU HÌNH (CONSTANTS & CONFIGURATION ENUMS)
// ============================================================================

/**
 * @brief Log levels matching Android Log Priority and ByteDance ALog specification.
 *        Các cấp độ ghi nhật ký tương thích chuẩn Android Log và quy cách ALog.
 */
typedef enum {
    ALOG_LEVEL_VERBOSE = 2,
    ALOG_LEVEL_DEBUG   = 3,
    ALOG_LEVEL_INFO    = 4,
    ALOG_LEVEL_WARN    = 5,
    ALOG_LEVEL_ERROR   = 6,
    ALOG_LEVEL_ASSERT  = 7,
    ALOG_LEVEL_OFF     = 8
} AlogLevel;

/**
 * @brief Log compressor types.
 *        Các loại động cơ nén dữ liệu nhật ký.
 */
typedef enum {
    ALOG_COMPRESS_NONE = 0,
    ALOG_COMPRESS_ZLIB = 1,
    ALOG_COMPRESS_ZSTD = 2
} AlogCompressorType;

/**
 * @brief Log encryptor types.
 *        Các loại thuật toán mã hóa bảo mật dữ liệu.
 */
typedef enum {
    ALOG_ENCRYPT_NONE   = 0,
    ALOG_ENCRYPT_AES_CFB = 1,
    ALOG_ENCRYPT_CHACHA20 = 2
} AlogEncryptorType;

/**
 * @brief Magic numbers for cache guard and log files.
 *        Số ma thuật nhận diện tính toàn vẹn của tệp cache guard và tệp nhật ký.
 */
#define ALOG_FILE_MAGIC         0x474F4C41  // "ALOG" in Little Endian
#define ALOG_CACHE_GUARD_MAGIC   0x44524743  // "CGRD" in Little Endian
#define ALOG_CURRENT_VERSION    0x00010000  // Version 1.0

#define ALOG_DEFAULT_BUFFER_SIZE (64 * 1024)   // 64 KB ring buffer
#define ALOG_ASYNC_QUEUE_SIZE    (32 * 1024)   // 32 KB async queue (0x7d00 approx)
#define ALOG_MAX_PATH_LEN        512
#define ALOG_MAX_TAG_LEN         128

// ============================================================================
// CẤU TRÚC FILE HEADER NHẬT KÝ (LOG FILE HEADER STRUCTURE)
// ============================================================================

/**
 * @struct AlogFileHeader
 * @brief Header recorded at the beginning of each .alog.hot / .alog.cache file.
 *        Phần đầu tệp được ghi tại vị trí 0 của mỗi tệp nhật ký nén/mã hóa.
 */
#pragma pack(push, 1)
typedef struct {
    uint32_t magic;           ///< Magic identifier (ALOG_FILE_MAGIC = 0x474F4C41)
    uint32_t version;         ///< Format version (0x00010000)
    uint16_t compressor_type; ///< Compressor algorithm (0=None, 1=Zlib, 2=Zstd)
    uint16_t encryptor_type;  ///< Encryption algorithm (0=None, 1=AES, 2=ChaCha)
    uint32_t header_size;     ///< Size of this header in bytes (typically 48 bytes)
    uint64_t create_timestamp;///< Creation epoch time in microseconds
    uint64_t instance_id;     ///< Unique instance identifier
    uint32_t payload_crc32;   ///< IEEE 802.3 CRC32 checksum of data blocks
    uint8_t  pubkey[16];      ///< Public key seed / IV initialization vector
} AlogFileHeader;
#pragma pack(pop)

/**
 * @struct AlogCacheGuard
 * @brief Guard structure to recover uncommitted log blocks after application crash.
 *        Cấu trúc bảo vệ cache giúp phục hồi khối log dở dang khi ứng dụng dừng đột ngột.
 */
#pragma pack(push, 1)
typedef struct {
    uint32_t magic;           ///< ALOG_CACHE_GUARD_MAGIC
    uint32_t version;         ///< Format version
    uint32_t write_offset;    ///< Current write position in active cache file
    uint32_t block_count;     ///< Number of un-flushed log blocks
    uint64_t last_active_ts;  ///< Last heartbeat timestamp
    uint32_t checksum;        ///< Integrity checksum of guard meta
} AlogCacheGuard;
#pragma pack(pop)

// ============================================================================
// CẤU HÌNH KHỞI TẠO ALOG (INITIALIZATION CONFIGURATION)
// ============================================================================

/**
 * @struct AlogConfig
 * @brief Comprehensive configuration parsed from JNI nativeCreate parameters.
 *        Cấu hình toàn diện được trích xuất từ các tham số của JNI nativeCreate.
 */
typedef struct {
    int32_t  mode;                    ///< Run mode (Async / Sync)
    bool     enable_syslog;           ///< Echo log to Android logcat (__android_log_write)
    char     log_dir[ALOG_MAX_PATH_LEN];    ///< Destination directory for .alog files
    char     cache_dir[ALOG_MAX_PATH_LEN];  ///< Directory for .alog.cache files
    int32_t  max_dir_size_mb;         ///< Maximum total directory size before rotation
    int32_t  max_file_size_mb;        ///< Maximum single file size before chunking
    int32_t  max_history_days;        ///< Maximum file retention period in days
    char     file_prefix[64];         ///< Log file prefix string
    int32_t  compressor_type;         ///< 0: None, 1: Zlib, 2: Zstd
    int32_t  compress_level;          ///< Compression level (e.g., Zlib 1-9, Zstd 1-19)
    char     pub_key[128];            ///< Encryption public key or secret token
    int32_t  encryptor_type;          ///< 0: None, 1: AES-CFB, 2: ChaCha20
    int32_t  buffer_size;             ///< In-memory ring buffer size in bytes
    int32_t  async_queue_size;        ///< Async message queue capacity in bytes
    int32_t  min_log_level;           ///< Minimal log level to record (AlogLevel)
    int32_t  flush_interval_sec;      ///< Timed flush interval in seconds
    int32_t  cache_size_limit;        ///< Memory cache size threshold
    char     process_name[64];        ///< Name of current host process
    int64_t  sub_module_mask;         ///< Bitmask filter for sub-modules
    bool     enable_memory_dump;      ///< Allow dumping memory buffer on crash
    int32_t  reserved_flag;           ///< Reserved options flag
} AlogConfig;

// ============================================================================
// THÔNG ĐIỆP BẤT ĐỒNG BỘ (ASYNC LOG MESSAGE ENVELOPE)
// ============================================================================

/**
 * @struct AlogAsyncMessage
 * @brief Envelope for queued asynchronous log records.
 *        Bao thư chứa bản ghi nhật ký bất đồng bộ xếp trong hàng đợi.
 */
typedef struct {
    int32_t  level;
    uint32_t tag_len;
    uint32_t msg_len;
    uint64_t timestamp_us;
    int32_t  tid;
    int64_t  arg1;
    int64_t  arg2;
    char     data[1];                 ///< Flexible array member: tag followed by msg
} AlogAsyncMessage;

// Opaque instance handle pointer
typedef struct AlogInstance_t* AlogHandle;

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_TYPES_H
