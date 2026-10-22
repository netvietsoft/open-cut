/**
 * @file alog_async_worker.cpp
 * @brief ByteDance ALog Dedicated Background Worker Thread Implementation.
 *        Hiện thực luồng xử lý nền bất đồng bộ chuyên biệt của hệ thống ALog.
 */

#include "alog_async_worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

#if defined(__linux__) || defined(__ANDROID__)
#include <sys/eventfd.h>
#endif

static void* alog_worker_thread_func(void* arg);

AlogAsyncWorker* alog_async_worker_create(AlogBuffer* buf,
                                          AlogCompressor* comp,
                                          AlogEncryptor* enc,
                                          AlogFileManager* file_mgr,
                                          size_t queue_size,
                                          int32_t flush_interval) {
    if (queue_size == 0) {
        queue_size = ALOG_ASYNC_QUEUE_SIZE; // Default 32 KB (matching opcode 0x7d00)
    }

    AlogAsyncWorker* worker = (AlogAsyncWorker*)calloc(1, sizeof(AlogAsyncWorker));
    if (!worker) return NULL;

    worker->target_buffer = buf;
    worker->compressor = comp;
    worker->encryptor = enc;
    worker->file_mgr = file_mgr;
    worker->queue_capacity = queue_size;
    worker->flush_interval_sec = (flush_interval > 0) ? flush_interval : 2;
    worker->is_running = true;
    worker->should_stop = false;

    worker->queue_buf = (uint8_t*)calloc(1, queue_size);
    if (!worker->queue_buf) {
        free(worker);
        return NULL;
    }

    pthread_mutex_init(&worker->queue_lock, NULL);
    pthread_cond_init(&worker->queue_cond, NULL);

#if defined(__linux__) || defined(__ANDROID__)
    worker->notify_event_fd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
#else
    worker->notify_event_fd = -1;
#endif

    // Launch dedicated background POSIX thread
    // Khởi chạy luồng POSIX chuyên biệt xử lý ngầm
    if (pthread_create(&worker->worker_thread, NULL, alog_worker_thread_func, worker) != 0) {
        pthread_cond_destroy(&worker->queue_cond);
        pthread_mutex_destroy(&worker->queue_lock);
        free(worker->queue_buf);
        free(worker);
        return NULL;
    }

    return worker;
}

static void drain_worker_queue(AlogAsyncWorker* worker) {
    uint8_t batch_buffer[4096];
    size_t batch_len = 0;

    pthread_mutex_lock(&worker->queue_lock);
    while (worker->queue_head != worker->queue_tail && worker->msg_count > 0) {
        // Read message header
        // Đọc phần tiêu đề bản ghi nhật ký
        uint32_t total_msg_bytes = 0;
        memcpy(&total_msg_bytes, worker->queue_buf + worker->queue_head, sizeof(uint32_t));

        if (total_msg_bytes == 0 || total_msg_bytes > worker->queue_capacity) {
            // Corruption guard: reset queue pointers
            worker->queue_head = worker->queue_tail;
            worker->msg_count = 0;
            break;
        }

        if (batch_len + total_msg_bytes > sizeof(batch_buffer)) {
            // Flush current accumulated batch
            pthread_mutex_unlock(&worker->queue_lock);

            // Compress and write to disk
            uint8_t comp_buf[4096 + 128];
            int32_t comp_len = alog_compressor_compress(worker->compressor,
                                                        batch_buffer, batch_len,
                                                        comp_buf, sizeof(comp_buf), true);
            if (comp_len > 0) {
                uint8_t enc_buf[4096 + 128];
                int32_t enc_len = alog_encryptor_encrypt(worker->encryptor,
                                                         comp_buf, (size_t)comp_len,
                                                         enc_buf, sizeof(enc_buf));
                if (enc_len > 0) {
                    alog_file_manager_write(worker->file_mgr, enc_buf, (size_t)enc_len);
                }
            }
            batch_len = 0;
            pthread_mutex_lock(&worker->queue_lock);
        }

        // Copy message into batch buffer
        memcpy(batch_buffer + batch_len, worker->queue_buf + worker->queue_head, total_msg_bytes);
        batch_len += total_msg_bytes;

        worker->queue_head = (worker->queue_head + total_msg_bytes) % worker->queue_capacity;
        worker->msg_count--;
    }
    pthread_mutex_unlock(&worker->queue_lock);

    // Write final batch
    if (batch_len > 0) {
        uint8_t comp_buf[4096 + 128];
        int32_t comp_len = alog_compressor_compress(worker->compressor,
                                                    batch_buffer, batch_len,
                                                    comp_buf, sizeof(comp_buf), true);
        if (comp_len > 0) {
            uint8_t enc_buf[4096 + 128];
            int32_t enc_len = alog_encryptor_encrypt(worker->encryptor,
                                                     comp_buf, (size_t)comp_len,
                                                     enc_buf, sizeof(enc_buf));
            if (enc_len > 0) {
                alog_file_manager_write(worker->file_mgr, enc_buf, (size_t)enc_len);
            }
        }
    }

    alog_file_manager_sync(worker->file_mgr);
}

static void* alog_worker_thread_func(void* arg) {
    AlogAsyncWorker* worker = (AlogAsyncWorker*)arg;

#if defined(__linux__) || defined(__ANDROID__)
    // Set thread name matching binary string "alog_native_wkr"
    // Đặt tên định danh cho luồng khớp chính xác chuỗi "alog_native_wkr"
    pthread_setname_np(pthread_self(), "alog_native_wkr");
#endif

    while (!worker->should_stop) {
        pthread_mutex_lock(&worker->queue_lock);

        struct timeval now;
        gettimeofday(&now, NULL);
        struct timespec timeout;
        timeout.tv_sec = now.tv_sec + worker->flush_interval_sec;
        timeout.tv_nsec = now.tv_usec * 1000;

        while (worker->msg_count == 0 && !worker->should_stop) {
            int r = pthread_cond_timedwait(&worker->queue_cond, &worker->queue_lock, &timeout);
            if (r == ETIMEDOUT) {
                break;
            }
        }
        pthread_mutex_unlock(&worker->queue_lock);

        drain_worker_queue(worker);
    }

    // Final drain before thread termination
    // Xả sạch nốt hàng đợi trước khi kết thúc luồng hoàn toàn
    drain_worker_queue(worker);
    return NULL;
}

int alog_async_worker_enqueue(AlogAsyncWorker* worker,
                              int level,
                              const char* tag,
                              const char* msg,
                              int64_t arg1,
                              int64_t arg2) {
    if (!worker || !msg) return -1;

    size_t tag_len = tag ? strlen(tag) : 0;
    size_t msg_len = strlen(msg);
    uint32_t payload_len = sizeof(uint32_t) + sizeof(AlogAsyncMessage) + tag_len + msg_len + 1;

    pthread_mutex_lock(&worker->queue_lock);

    // Calculate remaining queue space
    // Tính toán dung lượng trống khả dụng trong hàng đợi
    size_t used = (worker->queue_tail >= worker->queue_head) ?
                  (worker->queue_tail - worker->queue_head) :
                  (worker->queue_capacity - (worker->queue_head - worker->queue_tail));

    if (used + payload_len >= worker->queue_capacity) {
        // Queue full, trigger emergency wake up and drop or fallback
        pthread_cond_signal(&worker->queue_cond);
        pthread_mutex_unlock(&worker->queue_lock);
        return -2;
    }

    // Write size prefix
    memcpy(worker->queue_buf + worker->queue_tail, &payload_len, sizeof(uint32_t));
    size_t pos = worker->queue_tail + sizeof(uint32_t);

    // Write envelope
    AlogAsyncMessage env;
    env.level = level;
    env.tag_len = (uint32_t)tag_len;
    env.msg_len = (uint32_t)msg_len;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    env.timestamp_us = (uint64_t)tv.tv_sec * 1000000ULL + tv.tv_usec;
    env.tid = (int32_t)getpid();
    env.arg1 = arg1;
    env.arg2 = arg2;

    memcpy(worker->queue_buf + pos, &env, sizeof(AlogAsyncMessage) - 1);
    pos += (sizeof(AlogAsyncMessage) - 1);

    if (tag_len > 0) {
        memcpy(worker->queue_buf + pos, tag, tag_len);
        pos += tag_len;
    }
    memcpy(worker->queue_buf + pos, msg, msg_len + 1);
    pos += (msg_len + 1);

    worker->queue_tail = (worker->queue_tail + payload_len) % worker->queue_capacity;
    worker->msg_count++;

    pthread_cond_signal(&worker->queue_cond);
    pthread_mutex_unlock(&worker->queue_lock);
    return 0;
}

void alog_async_worker_flush_async(AlogAsyncWorker* worker) {
    if (!worker) return;
    pthread_mutex_lock(&worker->queue_lock);
    pthread_cond_signal(&worker->queue_cond);
    pthread_mutex_unlock(&worker->queue_lock);
}

void alog_async_worker_flush_sync(AlogAsyncWorker* worker, int timeout_ms) {
    if (!worker) return;
    drain_worker_queue(worker);
}

void alog_async_worker_destroy(AlogAsyncWorker* worker) {
    if (!worker) return;

    pthread_mutex_lock(&worker->queue_lock);
    worker->should_stop = true;
    pthread_cond_signal(&worker->queue_cond);
    pthread_mutex_unlock(&worker->queue_lock);

    pthread_join(worker->worker_thread, NULL);

    pthread_cond_destroy(&worker->queue_cond);
    pthread_mutex_destroy(&worker->queue_lock);

    if (worker->notify_event_fd >= 0) {
        close(worker->notify_event_fd);
    }

    if (worker->queue_buf) {
        free(worker->queue_buf);
    }
    free(worker);
}
