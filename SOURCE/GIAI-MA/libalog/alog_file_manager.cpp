/**
 * @file alog_file_manager.cpp
 * @brief ByteDance ALog Disk File Lifecycle & Log Rotation Manager Implementation.
 *        Hiện thực quản lý vòng đời tệp nhật ký trên đĩa và xoay vòng log của ALog.
 */

#include "alog_file_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <fnmatch.h>
#include <errno.h>

static int ensure_dir_exists(const char* dir) {
    if (!dir || dir[0] == '\0') return -1;
    struct stat st;
    if (stat(dir, &st) == 0) {
        if (S_ISDIR(st.st_mode)) return 0;
        return -1;
    }
    // Attempt to create directory recursively or directly
    return mkdir(dir, 0755);
}

AlogFileManager* alog_file_manager_create(const AlogConfig* config,
                                          AlogDeleteCallback cb,
                                          void* user_data) {
    if (!config) return NULL;

    AlogFileManager* mgr = (AlogFileManager*)calloc(1, sizeof(AlogFileManager));
    if (!mgr) return NULL;

    pthread_mutex_init(&mgr->lock, NULL);
    mgr->active_fd = -1;
    mgr->active_file_bytes = 0;
    mgr->on_delete_cb = cb;
    mgr->cb_user_data = user_data;

    strncpy(mgr->log_dir, config->log_dir, sizeof(mgr->log_dir) - 1);
    strncpy(mgr->cache_dir, config->cache_dir, sizeof(mgr->cache_dir) - 1);
    strncpy(mgr->prefix, (config->file_prefix[0] != '\0') ? config->file_prefix : "alog", sizeof(mgr->prefix) - 1);
    strncpy(mgr->process_name, (config->process_name[0] != '\0') ? config->process_name : "main", sizeof(mgr->process_name) - 1);

    mgr->max_dir_size_mb = (config->max_dir_size_mb > 0) ? config->max_dir_size_mb : 50;
    mgr->max_file_size_mb = (config->max_file_size_mb > 0) ? config->max_file_size_mb : 5;
    mgr->max_history_days = (config->max_history_days > 0) ? config->max_history_days : 7;

    ensure_dir_exists(mgr->log_dir);
    ensure_dir_exists(mgr->cache_dir);

    // Initial log rotation to open first hot file
    alog_file_manager_rotate(mgr);

    return mgr;
}

int alog_file_manager_rotate(AlogFileManager* mgr) {
    if (!mgr) return -1;

    pthread_mutex_lock(&mgr->lock);

    // Close previous active file if open
    // Đóng tệp đang mở trước đó nếu có
    if (mgr->active_fd >= 0) {
        fsync(mgr->active_fd);
        close(mgr->active_fd);
        mgr->active_fd = -1;

        // Rename sealed file from .hot to .alog
        // Đổi tên tệp đã khóa từ đuôi .hot thành .alog chính thức
        char sealed_path[ALOG_MAX_PATH_LEN];
        size_t len = strlen(mgr->active_file_path);
        if (len > 4 && strcmp(mgr->active_file_path + len - 4, ".hot") == 0) {
            strncpy(sealed_path, mgr->active_file_path, len - 4);
            sealed_path[len - 4] = '\0';
            rename(mgr->active_file_path, sealed_path);
        }
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm tm_info;
    localtime_r(&tv.tv_sec, &tm_info);

    // Format: %s/%04d_%02d_%02d_%lu__%s__%s.alog.hot
    // Định dạng tên tệp: Năm_Tháng_Ngày_Giây__TiềnTố__TênTiếnTrình.alog.hot
    snprintf(mgr->active_file_path, sizeof(mgr->active_file_path),
             "%s/%04d_%02d_%02d_%lu__%s__%s.alog.hot",
             mgr->log_dir,
             tm_info.tm_year + 1900,
             tm_info.tm_mon + 1,
             tm_info.tm_mday,
             (unsigned long)tv.tv_sec,
             mgr->prefix,
             mgr->process_name);

    mgr->active_fd = open(mgr->active_file_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    mgr->active_file_bytes = 0;

    pthread_mutex_unlock(&mgr->lock);
    return (mgr->active_fd >= 0) ? 0 : -1;
}

int alog_file_manager_write(AlogFileManager* mgr, const uint8_t* data, size_t len) {
    if (!mgr || !data || len == 0) return -1;

    pthread_mutex_lock(&mgr->lock);

    // Check if current file exceeds maximum single file size threshold
    // Kiểm tra xem tệp hiện tại có vượt quá ngưỡng kích thước tối đa cho phép
    size_t max_bytes = (size_t)mgr->max_file_size_mb * 1024 * 1024;
    if (mgr->active_file_bytes + len > max_bytes) {
        pthread_mutex_unlock(&mgr->lock);
        alog_file_manager_rotate(mgr);
        pthread_mutex_lock(&mgr->lock);
    }

    if (mgr->active_fd < 0) {
        pthread_mutex_unlock(&mgr->lock);
        return -1;
    }

    ssize_t written = write(mgr->active_fd, data, len);
    if (written > 0) {
        mgr->active_file_bytes += (size_t)written;
    }

    pthread_mutex_unlock(&mgr->lock);
    return (written == (ssize_t)len) ? 0 : -1;
}

int alog_file_manager_sync(AlogFileManager* mgr) {
    if (!mgr) return -1;
    pthread_mutex_lock(&mgr->lock);
    int res = 0;
    if (mgr->active_fd >= 0) {
        res = fsync(mgr->active_fd);
    }
    pthread_mutex_unlock(&mgr->lock);
    return res;
}

static int filter_log_files(const struct dirent* entry) {
    if (!entry) return 0;
    return (fnmatch("*.alog*", entry->d_name, 0) == 0);
}

int alog_file_manager_prune_expired(AlogFileManager* mgr) {
    if (!mgr) return -1;

    pthread_mutex_lock(&mgr->lock);

    struct dirent** namelist = NULL;
    int n = scandir(mgr->log_dir, &namelist, filter_log_files, alphasort);
    if (n < 0) {
        pthread_mutex_unlock(&mgr->lock);
        return -1;
    }

    time_t now = time(NULL);
    time_t expire_threshold = now - (time_t)mgr->max_history_days * 86400;

    size_t total_dir_size = 0;
    for (int i = 0; i < n; ++i) {
        char full_path[ALOG_MAX_PATH_LEN];
        snprintf(full_path, sizeof(full_path), "%s/%s", mgr->log_dir, namelist[i]->d_name);

        struct stat st;
        if (stat(full_path, &st) == 0) {
            total_dir_size += (size_t)st.st_size;

            // Prune if older than max history days
            // Xóa tệp nếu thời gian sửa đổi cũ hơn ngưỡng số ngày lưu trữ
            if (st.st_mtime < expire_threshold && strcmp(full_path, mgr->active_file_path) != 0) {
                unlink(full_path);
                if (mgr->on_delete_cb) {
                    mgr->on_delete_cb(full_path, mgr->cb_user_data);
                }
            }
        }
        free(namelist[i]);
    }
    free(namelist);

    pthread_mutex_unlock(&mgr->lock);
    return 0;
}

int alog_file_manager_recover_cache(AlogFileManager* mgr) {
    if (!mgr) return -1;

    pthread_mutex_lock(&mgr->lock);

    struct dirent** namelist = NULL;
    int n = scandir(mgr->cache_dir, &namelist, filter_log_files, alphasort);
    if (n < 0) {
        pthread_mutex_unlock(&mgr->lock);
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        char cache_file[ALOG_MAX_PATH_LEN];
        snprintf(cache_file, sizeof(cache_file), "%s/%s", mgr->cache_dir, namelist[i]->d_name);

        // Read cache content and migrate to active hot file
        // Đọc nội dung bộ nhớ đệm còn sót lại và di chuyển vào tệp hot hiện tại
        int fd = open(cache_file, O_RDONLY);
        if (fd >= 0) {
            uint8_t buffer[4096];
            ssize_t r;
            while ((r = read(fd, buffer, sizeof(buffer))) > 0) {
                if (mgr->active_fd >= 0) {
                    write(mgr->active_fd, buffer, (size_t)r);
                    mgr->active_file_bytes += (size_t)r;
                }
            }
            close(fd);
            unlink(cache_file); // Remove migrated cache
        }
        free(namelist[i]);
    }
    free(namelist);

    pthread_mutex_unlock(&mgr->lock);
    return 0;
}

void alog_file_manager_destroy(AlogFileManager* mgr) {
    if (!mgr) return;

    pthread_mutex_lock(&mgr->lock);
    if (mgr->active_fd >= 0) {
        fsync(mgr->active_fd);
        close(mgr->active_fd);
        mgr->active_fd = -1;
    }
    pthread_mutex_unlock(&mgr->lock);

    pthread_mutex_destroy(&mgr->lock);
    free(mgr);
}
