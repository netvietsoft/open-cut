/**
 * @file alog_core.h
 * @brief ByteDance ALog Core Engine & Native C Export Functions Header.
 *        Định nghĩa giao diện động cơ lõi ALog và các hàm xuất khẩu C của libalog.so.
 */

#ifndef BYTEDANCE_ALOG_CORE_H
#define BYTEDANCE_ALOG_CORE_H

#include "alog_types.h"
#include "alog_buffer.h"
#include "alog_compressor.h"
#include "alog_encryptor.h"
#include "alog_file_manager.h"
#include "alog_async_worker.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct AlogInstance_t
 * @brief Master runtime instance representing an active logger configuration.
 *        Đối tượng quản lý toàn diện một thể hiện ghi nhật ký của ALog.
 */
typedef struct AlogInstance_t {
    AlogConfig          config;             ///< Parsed initialization configuration
    AlogLevel           current_level;      ///< Current active filtering log level
    bool                enable_syslog;      ///< Echo to Android logcat
    bool                enable_write;       ///< Master switch for logging
    AlogBuffer*         buffer;             ///< Ring buffer (mmap/calloc)
    AlogCompressor*     compressor;         ///< Compression engine (Zlib/Zstd)
    AlogEncryptor*      encryptor;          ///< Stream cipher engine
    AlogFileManager*    file_mgr;           ///< File rotation & lifecycle manager
    AlogAsyncWorker*    async_worker;       ///< Background worker thread
    pthread_rwlock_t    rwlock;             ///< Multi-reader single-writer lock
} AlogInstance;

// ============================================================================
// NATIVE C EXPORTED API MATCHING libalog.so .dynsym
// ============================================================================

/**
 * @brief Create a new ALog logger instance.
 *        Khởi tạo một thể hiện ghi nhật ký ALog mới (Khớp VAddr 0x2c8c).
 */
int alog_create(AlogHandle* out_handle, const AlogConfig* config);

/**
 * @brief Synchronous or direct write of log payload.
 *        Ghi trực tiếp nội dung nhật ký vào thể hiện (Khớp VAddr 0x3cbc).
 */
void alog_write(AlogHandle handle, int level, const char* tag, const char* msg);

/**
 * @brief Write log to global default instance.
 *        Ghi nhật ký vào thể hiện mặc định toàn cục (Khớp VAddr 0x4230).
 */
void alog_write_default_instance(int level, const char* tag, const char* msg);

/**
 * @brief Asynchronous write of log to global default instance.
 *        Ghi nhật ký bất đồng bộ vào thể hiện mặc định toàn cục (Khớp VAddr 0x44a8).
 */
void alog_write_default_instance_async(int level, const char* tag, const char* msg, int64_t arg1, int64_t arg2);

/**
 * @brief Formatted print into logger instance.
 *        Ghi nhật ký có định dạng chuỗi vào thể hiện (Khớp VAddr 0x4030).
 */
void alog_print(AlogHandle handle, int level, const char* tag, const char* fmt, ...);

/**
 * @brief Variable argument formatted print into logger instance.
 *        Ghi nhật ký có định dạng danh sách đối số va_list (Khớp VAddr 0x412c).
 */
void alog_vprint(AlogHandle handle, int level, const char* tag, const char* fmt, va_list args);

/**
 * @brief Request asynchronous flush.
 *        Yêu cầu xả bộ đệm bất đồng bộ (Khớp VAddr 0x4204).
 */
void alog_async_flush(AlogHandle handle);

/**
 * @brief Request synchronous flush.
 *        Yêu cầu xả bộ đệm đồng bộ có khóa (Khớp VAddr 0x420c).
 */
void alog_sync_flush(AlogHandle handle);

/**
 * @brief Request timed synchronous flush with timeout.
 *        Yêu cầu xả bộ đệm đồng bộ có giới hạn thời gian chờ (Khớp VAddr 0x4218).
 */
void alog_timed_sync_flush(AlogHandle handle, int timeout_ms);

/**
 * @brief Set minimum log level.
 *        Thiết lập cấp độ lọc log tối thiểu (Khớp VAddr 0x4220).
 */
void alog_set_level(AlogHandle handle, int level);

/**
 * @brief Enable or disable Android logcat syslog echo.
 *        Bật hoặc tắt chức năng chuyển tiếp log sang Android logcat (Khớp VAddr 0x4228).
 */
void alog_set_syslog(AlogHandle handle, bool enable);

/**
 * @brief Destroy logger instance and release resources.
 *        Hủy giải phóng thể hiện nhật ký và tài nguyên liên quan (Khớp VAddr 0x3c40).
 */
void alog_destroy(AlogHandle handle);

/**
 * @brief Initialize legacy async logging subsystem.
 *        Khởi tạo hệ thống phụ trợ ghi log bất đồng bộ legacy (Khớp VAddr 0x4390).
 */
int init_async_logging(void);

/**
 * @brief Set global default logger instance.
 *        Đặt thể hiện ghi log mặc định toàn cục.
 */
void alog_set_default_instance(AlogHandle handle);

/**
 * @brief Get global default logger instance.
 *        Lấy con trỏ thể hiện ghi log mặc định toàn cục.
 */
AlogHandle alog_get_default_instance(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_CORE_H
