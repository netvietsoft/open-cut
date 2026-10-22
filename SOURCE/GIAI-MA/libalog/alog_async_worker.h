/**
 * @file alog_async_worker.h
 * @brief ByteDance ALog Dedicated Background Worker Thread Interface.
 *        Giao diện luồng xử lý nền bất đồng bộ chuyên biệt của hệ thống ALog.
 */

#ifndef BYTEDANCE_ALOG_ASYNC_WORKER_H
#define BYTEDANCE_ALOG_ASYNC_WORKER_H

#include "alog_types.h"
#include "alog_buffer.h"
#include "alog_compressor.h"
#include "alog_encryptor.h"
#include "alog_file_manager.h"
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AlogAsyncWorker_t {
    pthread_t           worker_thread;      ///< POSIX background thread handle ("alog_native_wkr")
    bool                is_running;         ///< Running state flag
    bool                should_stop;        ///< Stop request signal
    pthread_mutex_t     queue_lock;         ///< Queue synchronization lock
    pthread_cond_t      queue_cond;         ///< Condition variable to wake up worker
    int                 notify_event_fd;    ///< Linux eventfd for zero-latency wake-up
    uint8_t*            queue_buf;          ///< Circular message queue buffer
    size_t              queue_capacity;     ///< Maximum queue capacity (approx 32 KB / 0x7d00)
    size_t              queue_head;         ///< Head offset
    size_t              queue_tail;         ///< Tail offset
    size_t              msg_count;          ///< Queued messages count
    int32_t             flush_interval_sec; ///< Periodic timed flush interval
    AlogBuffer*         target_buffer;      ///< Target ring buffer
    AlogCompressor*     compressor;         ///< Compressor instance
    AlogEncryptor*      encryptor;          ///< Encryptor instance
    AlogFileManager*    file_mgr;           ///< File manager
} AlogAsyncWorker;

/**
 * @brief Create and start the background worker thread.
 *        Khởi tạo và kích hoạt luồng xử lý nền bất đồng bộ.
 */
AlogAsyncWorker* alog_async_worker_create(AlogBuffer* buf,
                                          AlogCompressor* comp,
                                          AlogEncryptor* enc,
                                          AlogFileManager* file_mgr,
                                          size_t queue_size,
                                          int32_t flush_interval);

/**
 * @brief Push a new formatted log message into the async queue.
 *        Đẩy một bản ghi nhật ký đã định dạng vào hàng đợi bất đồng bộ.
 */
int alog_async_worker_enqueue(AlogAsyncWorker* worker,
                              int level,
                              const char* tag,
                              const char* msg,
                              int64_t arg1,
                              int64_t arg2);

/**
 * @brief Signal worker to immediately drain and flush queued messages to disk.
 *        Báo hiệu cho luồng worker xả ngay lập tức toàn bộ hàng đợi xuống đĩa.
 */
void alog_async_worker_flush_async(AlogAsyncWorker* worker);

/**
 * @brief Block until all currently queued messages are drained and synced to disk.
 *        Chặn luồng gọi cho đến khi toàn bộ thông điệp trong hàng đợi được ghi và đồng bộ đĩa.
 */
void alog_async_worker_flush_sync(AlogAsyncWorker* worker, int timeout_ms);

/**
 * @brief Stop worker thread and drain remaining messages before shutdown.
 *        Dừng luồng worker và giải phóng hàng đợi trước khi hệ thống ngừng hoạt động.
 */
void alog_async_worker_destroy(AlogAsyncWorker* worker);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_ASYNC_WORKER_H
