/**
 * @file alog_core.cpp
 * @brief ByteDance ALog Core Engine & Native C Export Functions Implementation.
 *        Hiện thực động cơ lõi ALog và các hàm xuất khẩu C của libalog.so.
 */

#include "alog_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#ifdef __ANDROID__
#include <android/log.h>
#else
// Fallback logger for test verification on non-Android platforms
// Bộ ghi log dự phòng khi chạy kiểm chứng trên nền tảng không phải Android
static void __android_log_write(int prio, const char* tag, const char* text) {
    (void)prio; (void)tag; (void)text;
}
#endif

// Global default instance pointer (Address 0x14270 area)
// Con trỏ thể hiện mặc định toàn cục
static AlogHandle g_default_instance = NULL;
static pthread_mutex_t g_default_lock = PTHREAD_MUTEX_INITIALIZER;

static void alog_internal_delete_callback(const char* deleted_file, void* user_data) {
    (void)user_data;
    // Log file pruning notification
    // Thông báo sự kiện dọn dẹp tệp nhật ký
}

int alog_create(AlogHandle* out_handle, const AlogConfig* config) {
    if (!out_handle || !config) return -1;

    AlogInstance* inst = (AlogInstance*)calloc(1, sizeof(AlogInstance));
    if (!inst) return -1;

    memcpy(&inst->config, config, sizeof(AlogConfig));
    inst->current_level = (AlogLevel)config->min_log_level;
    inst->enable_syslog = config->enable_syslog;
    inst->enable_write = true;

    pthread_rwlock_init(&inst->rwlock, NULL);

    // 1. Initialize Ring Buffer
    inst->buffer = alog_buffer_create(config->cache_dir, config->file_prefix, (size_t)config->buffer_size);

    // 2. Initialize Compressor
    inst->compressor = alog_compressor_create((AlogCompressorType)config->compressor_type, config->compress_level);

    // 3. Initialize Encryptor
    inst->encryptor = alog_encryptor_create((AlogEncryptorType)config->encryptor_type, config->pub_key);

    // 4. Initialize File Manager
    inst->file_mgr = alog_file_manager_create(config, alog_internal_delete_callback, inst);

    // 5. Initialize Async Worker Thread (if mode is async or mode == 0)
    inst->async_worker = alog_async_worker_create(inst->buffer,
                                                  inst->compressor,
                                                  inst->encryptor,
                                                  inst->file_mgr,
                                                  (size_t)config->async_queue_size,
                                                  config->flush_interval_sec);

    *out_handle = (AlogHandle)inst;

    // Auto set default if none set yet
    pthread_mutex_lock(&g_default_lock);
    if (!g_default_instance) {
        g_default_instance = (AlogHandle)inst;
    }
    pthread_mutex_unlock(&g_default_lock);

    return 0;
}

void alog_write(AlogHandle handle, int level, const char* tag, const char* msg) {
    if (!handle || !msg) return;
    AlogInstance* inst = (AlogInstance*)handle;

    if (!inst->enable_write || level < (int)inst->current_level) {
        return;
    }

    // Echo to Android syslog if enabled
    // Chuyển tiếp tới Android Logcat nếu được cấu hình
    if (inst->enable_syslog) {
        __android_log_write(level, tag ? tag : "ALOG", msg);
    }

    if (inst->async_worker) {
        alog_async_worker_enqueue(inst->async_worker, level, tag, msg, 0, 0);
    } else {
        // Direct synchronous write
        // Ghi trực tiếp đồng bộ vào đệm và file
        size_t tlen = tag ? strlen(tag) : 0;
        size_t mlen = strlen(msg);
        char line_buf[2048];
        int written = snprintf(line_buf, sizeof(line_buf), "[%d][%s] %s\n", level, tag ? tag : "ALOG", msg);
        if (written > 0) {
            uint8_t comp_buf[2048 + 64];
            int32_t clen = alog_compressor_compress(inst->compressor, (uint8_t*)line_buf, (size_t)written,
                                                    comp_buf, sizeof(comp_buf), true);
            if (clen > 0) {
                uint8_t enc_buf[2048 + 64];
                int32_t elen = alog_encryptor_encrypt(inst->encryptor, comp_buf, (size_t)clen,
                                                      enc_buf, sizeof(enc_buf));
                if (elen > 0) {
                    alog_file_manager_write(inst->file_mgr, enc_buf, (size_t)elen);
                }
            }
        }
    }
}

void alog_write_default_instance(int level, const char* tag, const char* msg) {
    pthread_mutex_lock(&g_default_lock);
    AlogHandle h = g_default_instance;
    pthread_mutex_unlock(&g_default_lock);

    if (h) {
        alog_write(h, level, tag, msg);
    } else {
        // Fallback to syslog directly
        __android_log_write(level, tag ? tag : "ALOG", msg);
    }
}

void alog_write_default_instance_async(int level, const char* tag, const char* msg, int64_t arg1, int64_t arg2) {
    pthread_mutex_lock(&g_default_lock);
    AlogHandle h = g_default_instance;
    pthread_mutex_unlock(&g_default_lock);

    if (h) {
        AlogInstance* inst = (AlogInstance*)h;
        if (inst->async_worker) {
            alog_async_worker_enqueue(inst->async_worker, level, tag, msg, arg1, arg2);
            return;
        }
        alog_write(h, level, tag, msg);
    }
}

void alog_vprint(AlogHandle handle, int level, const char* tag, const char* fmt, va_list args) {
    if (!handle || !fmt) return;
    char buffer[2048];
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    alog_write(handle, level, tag, buffer);
}

void alog_print(AlogHandle handle, int level, const char* tag, const char* fmt, ...) {
    if (!handle || !fmt) return;
    va_list args;
    va_start(args, fmt);
    alog_vprint(handle, level, tag, fmt, args);
    va_end(args);
}

void alog_async_flush(AlogHandle handle) {
    if (!handle) return;
    AlogInstance* inst = (AlogInstance*)handle;
    if (inst->async_worker) {
        alog_async_worker_flush_async(inst->async_worker);
    }
}

void alog_sync_flush(AlogHandle handle) {
    if (!handle) return;
    AlogInstance* inst = (AlogInstance*)handle;
    if (inst->async_worker) {
        alog_async_worker_flush_sync(inst->async_worker, 5000);
    }
    if (inst->file_mgr) {
        alog_file_manager_sync(inst->file_mgr);
    }
}

void alog_timed_sync_flush(AlogHandle handle, int timeout_ms) {
    if (!handle) return;
    AlogInstance* inst = (AlogInstance*)handle;
    if (inst->async_worker) {
        alog_async_worker_flush_sync(inst->async_worker, timeout_ms);
    }
    if (inst->file_mgr) {
        alog_file_manager_sync(inst->file_mgr);
    }
}

void alog_set_level(AlogHandle handle, int level) {
    if (!handle) return;
    AlogInstance* inst = (AlogInstance*)handle;
    pthread_rwlock_wrlock(&inst->rwlock);
    inst->current_level = (AlogLevel)level;
    pthread_rwlock_unlock(&inst->rwlock);
}

void alog_set_syslog(AlogHandle handle, bool enable) {
    if (!handle) return;
    AlogInstance* inst = (AlogInstance*)handle;
    pthread_rwlock_wrlock(&inst->rwlock);
    inst->enable_syslog = enable;
    pthread_rwlock_unlock(&inst->rwlock);
}

void alog_destroy(AlogHandle handle) {
    if (!handle) return;
    AlogInstance* inst = (AlogInstance*)handle;

    pthread_mutex_lock(&g_default_lock);
    if (g_default_instance == handle) {
        g_default_instance = NULL;
    }
    pthread_mutex_unlock(&g_default_lock);

    if (inst->async_worker) {
        alog_async_worker_destroy(inst->async_worker);
        inst->async_worker = NULL;
    }

    if (inst->file_mgr) {
        alog_file_manager_destroy(inst->file_mgr);
        inst->file_mgr = NULL;
    }

    if (inst->compressor) {
        alog_compressor_destroy(inst->compressor);
        inst->compressor = NULL;
    }

    if (inst->encryptor) {
        alog_encryptor_destroy(inst->encryptor);
        inst->encryptor = NULL;
    }

    if (inst->buffer) {
        alog_buffer_destroy(inst->buffer);
        inst->buffer = NULL;
    }

    pthread_rwlock_destroy(&inst->rwlock);
    free(inst);
}

int init_async_logging(void) {
    // Legacy async subsystem initialization
    // Khởi tạo phân hệ ghi log bất đồng bộ legacy (Khớp opcode 0x4390)
    return 0;
}

void alog_set_default_instance(AlogHandle handle) {
    pthread_mutex_lock(&g_default_lock);
    g_default_instance = handle;
    pthread_mutex_unlock(&g_default_lock);
}

AlogHandle alog_get_default_instance(void) {
    pthread_mutex_lock(&g_default_lock);
    AlogHandle h = g_default_instance;
    pthread_mutex_unlock(&g_default_lock);
    return h;
}
