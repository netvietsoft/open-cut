/**
 * @file alog_file_manager.h
 * @brief ByteDance ALog Disk File Lifecycle & Log Rotation Manager Interface.
 *        Giao diện quản lý vòng đời tệp nhật ký trên đĩa và xoay vòng log của ALog.
 */

#ifndef BYTEDANCE_ALOG_FILE_MANAGER_H
#define BYTEDANCE_ALOG_FILE_MANAGER_H

#include "alog_types.h"
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*AlogDeleteCallback)(const char* deleted_file_path, void* user_data);

typedef struct AlogFileManager_t {
    char                log_dir[ALOG_MAX_PATH_LEN];     ///< Primary storage dir for .alog.hot
    char                cache_dir[ALOG_MAX_PATH_LEN];   ///< Cache dir for .alog.cache
    char                prefix[64];                     ///< File prefix
    char                process_name[64];               ///< Process name identifier
    int32_t             max_dir_size_mb;                ///< Maximum directory size in MB
    int32_t             max_file_size_mb;               ///< Maximum file size in MB
    int32_t             max_history_days;               ///< Retention days limit
    int                 active_fd;                      ///< Active hot log file descriptor
    char                active_file_path[ALOG_MAX_PATH_LEN]; ///< Path of active .alog.hot file
    size_t              active_file_bytes;              ///< Bytes currently written to active file
    AlogDeleteCallback  on_delete_cb;                   ///< Callback when old log file is pruned
    void*               cb_user_data;                   ///< User context for deletion callback
    pthread_mutex_t     lock;                           ///< Concurrency lock
} AlogFileManager;

/**
 * @brief Create and configure disk file manager instance.
 *        Khởi tạo và cấu hình bộ quản lý tệp nhật ký trên đĩa.
 */
AlogFileManager* alog_file_manager_create(const AlogConfig* config,
                                          AlogDeleteCallback cb,
                                          void* user_data);

/**
 * @brief Write a chunk of data to the active hot log file. Automatically rotates file if limit exceeded.
 *        Ghi một khối dữ liệu vào tệp log đang mở. Tự động xoay tệp nếu vượt dung lượng.
 */
int alog_file_manager_write(AlogFileManager* mgr, const uint8_t* data, size_t len);

/**
 * @brief Force flush and sync active file to persistent storage.
 *        Buộc xả đệm và đồng bộ tệp đang mở xuống đĩa lưu trữ.
 */
int alog_file_manager_sync(AlogFileManager* mgr);

/**
 * @brief Roll over active log file to sealed format and start new log file.
 *        Đóng tệp nhật ký hiện tại và tạo tệp mới với dấu thời gian cập nhật.
 */
int alog_file_manager_rotate(AlogFileManager* mgr);

/**
 * @brief Clean up expired log files or prune files when total directory size exceeds threshold.
 *        Dọn dẹp các tệp nhật ký quá hạn hoặc lược bỏ bớt tệp khi vượt ngưỡng dung lượng.
 */
int alog_file_manager_prune_expired(AlogFileManager* mgr);

/**
 * @brief Scan and recover crashed .alog.cache files left over from prior application sessions.
 *        Quét và phục hồi các tệp cache dở dang từ các phiên làm việc trước bị ngắt đột ngột.
 */
int alog_file_manager_recover_cache(AlogFileManager* mgr);

/**
 * @brief Destroy file manager, seal active files and free resources.
 *        Giải phóng bộ quản lý tệp, đóng an toàn các file descriptor và giải phóng bộ nhớ.
 */
void alog_file_manager_destroy(AlogFileManager* mgr);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_FILE_MANAGER_H
