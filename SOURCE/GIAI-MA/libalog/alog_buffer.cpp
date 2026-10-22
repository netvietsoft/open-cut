/**
 * @file alog_buffer.cpp
 * @brief ByteDance ALog Ring Buffer & MMAP Cache Management Implementation.
 *        Hiện thực quản lý bộ đệm xoay vòng và tệp ánh xạ bộ nhớ MMAP của ALog.
 */

#include "alog_buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

AlogBuffer* alog_buffer_create(const char* cache_dir, const char* prefix, size_t capacity) {
    if (capacity == 0) {
        capacity = ALOG_DEFAULT_BUFFER_SIZE;
    }

    AlogBuffer* buf = (AlogBuffer*)calloc(1, sizeof(AlogBuffer));
    if (!buf) {
        return NULL;
    }

    pthread_mutex_init(&buf->lock, NULL);
    buf->capacity = capacity;
    buf->write_pos = 0;
    buf->read_pos = 0;
    buf->fd = -1;
    buf->is_mmap = false;

    // Build cache file path if directory is supplied
    // Xây dựng đường dẫn tệp cache nếu thư mục đệm được cung cấp
    if (cache_dir && cache_dir[0] != '\0') {
        pid_t pid = getpid();
        snprintf(buf->cache_path, sizeof(buf->cache_path), "%s/%s__%d__00001.alog.cache",
                 cache_dir, prefix ? prefix : "alog", (int)pid);

        // Open cache file with flags O_RDWR | O_CREAT | O_CLOEXEC (0x80042)
        // Mở tệp bộ đệm với các cờ O_RDWR | O_CREAT | O_CLOEXEC (0x80042)
        buf->fd = open(buf->cache_path, O_RDWR | O_CREAT, 0644);
        if (buf->fd >= 0) {
            // Ensure file size matches capacity via ftruncate
            // Đảm bảo kích thước tệp khớp với dung lượng định trước qua ftruncate
            if (ftruncate(buf->fd, capacity) == 0) {
                void* addr = mmap(NULL, capacity, PROT_READ | PROT_WRITE, MAP_SHARED, buf->fd, 0);
                if (addr != MAP_FAILED) {
                    buf->mmap_addr = (uint8_t*)addr;
                    buf->is_mmap = true;
                    return buf;
                }
            }
        }
    }

    // Fallback to pure heap allocation if mmap failed or no cache dir specified
    // Dự phòng cấp phát bộ nhớ heap thông thường nếu mmap thất bại hoặc không có thư mục
    buf->mmap_addr = (uint8_t*)calloc(1, capacity);
    buf->is_mmap = false;
    if (!buf->mmap_addr) {
        if (buf->fd >= 0) {
            close(buf->fd);
        }
        pthread_mutex_destroy(&buf->lock);
        free(buf);
        return NULL;
    }

    return buf;
}

int alog_buffer_write(AlogBuffer* buf, const uint8_t* data, size_t len) {
    if (!buf || !data || len == 0) {
        return -1;
    }

    pthread_mutex_lock(&buf->lock);

    // Check available space
    // Kiểm tra không gian còn trống trong bộ đệm
    size_t available = (buf->write_pos >= buf->read_pos) ?
                       (buf->capacity - (buf->write_pos - buf->read_pos)) :
                       (buf->read_pos - buf->write_pos);

    if (len > available) {
        // Automatically resize or drop oldest segment if ring buffer full
        // Tự động mở rộng hoặc xả đĩa nếu bộ đệm bị tràn
        if (alog_buffer_resize(buf, buf->capacity * 2) != 0) {
            pthread_mutex_unlock(&buf->lock);
            return -2; // Buffer overflow, cannot allocate
        }
    }

    // Direct sequential copy if not wrapping
    // Sao chép liên tục nếu chưa chạm biên cuốn vòng
    if (buf->write_pos + len <= buf->capacity) {
        memcpy(buf->mmap_addr + buf->write_pos, data, len);
        buf->write_pos += len;
    } else {
        size_t first_part = buf->capacity - buf->write_pos;
        memcpy(buf->mmap_addr + buf->write_pos, data, first_part);
        memcpy(buf->mmap_addr, data + first_part, len - first_part);
        buf->write_pos = len - first_part;
    }

    pthread_mutex_unlock(&buf->lock);
    return 0;
}

uint8_t* alog_buffer_reserve(AlogBuffer* buf, size_t len) {
    if (!buf || len == 0) {
        return NULL;
    }

    pthread_mutex_lock(&buf->lock);
    if (buf->write_pos + len > buf->capacity) {
        // Not enough contiguous space at end, reset or resize
        if (alog_buffer_resize(buf, buf->capacity + len * 2) != 0) {
            pthread_mutex_unlock(&buf->lock);
            return NULL;
        }
    }

    uint8_t* ptr = buf->mmap_addr + buf->write_pos;
    pthread_mutex_unlock(&buf->lock);
    return ptr;
}

void alog_buffer_commit(AlogBuffer* buf, size_t len) {
    if (!buf || len == 0) return;

    pthread_mutex_lock(&buf->lock);
    buf->write_pos = (buf->write_pos + len) % buf->capacity;
    pthread_mutex_unlock(&buf->lock);
}

int alog_buffer_sync(AlogBuffer* buf) {
    if (!buf) return -1;

    pthread_mutex_lock(&buf->lock);
    int res = 0;
    if (buf->is_mmap && buf->mmap_addr) {
#ifdef __linux__
        res = msync(buf->mmap_addr, buf->capacity, MS_SYNC);
#endif
    } else if (buf->fd >= 0) {
        res = fsync(buf->fd);
    }
    pthread_mutex_unlock(&buf->lock);
    return res;
}

int alog_buffer_resize(AlogBuffer* buf, size_t new_capacity) {
    if (!buf || new_capacity <= buf->capacity) {
        return -1;
    }

    if (buf->is_mmap && buf->fd >= 0) {
#if defined(__linux__) && defined(_GNU_SOURCE)
        if (ftruncate(buf->fd, new_capacity) == 0) {
            void* new_addr = mremap(buf->mmap_addr, buf->capacity, new_capacity, MREMAP_MAYMOVE);
            if (new_addr != MAP_FAILED) {
                buf->mmap_addr = (uint8_t*)new_addr;
                buf->capacity = new_capacity;
                return 0;
            }
        }
#endif
        // Unmap and re-map fallback
        munmap(buf->mmap_addr, buf->capacity);
        if (ftruncate(buf->fd, new_capacity) == 0) {
            void* new_addr = mmap(NULL, new_capacity, PROT_READ | PROT_WRITE, MAP_SHARED, buf->fd, 0);
            if (new_addr != MAP_FAILED) {
                buf->mmap_addr = (uint8_t*)new_addr;
                buf->capacity = new_capacity;
                return 0;
            }
        }
        // Fallback to calloc if mmap expansion failed
        buf->is_mmap = false;
        close(buf->fd);
        buf->fd = -1;
    }

    uint8_t* new_mem = (uint8_t*)realloc(buf->mmap_addr, new_capacity);
    if (!new_mem) {
        return -1;
    }

    buf->mmap_addr = new_mem;
    buf->capacity = new_capacity;
    return 0;
}

void alog_buffer_reset(AlogBuffer* buf) {
    if (!buf) return;
    pthread_mutex_lock(&buf->lock);
    buf->write_pos = 0;
    buf->read_pos = 0;
    if (buf->mmap_addr) {
        memset(buf->mmap_addr, 0, buf->capacity);
    }
    pthread_mutex_unlock(&buf->lock);
}

void alog_buffer_destroy(AlogBuffer* buf) {
    if (!buf) return;

    pthread_mutex_lock(&buf->lock);
    if (buf->is_mmap && buf->mmap_addr) {
        msync(buf->mmap_addr, buf->capacity, MS_SYNC);
        munmap(buf->mmap_addr, buf->capacity);
    } else if (buf->mmap_addr) {
        free(buf->mmap_addr);
    }

    if (buf->fd >= 0) {
        close(buf->fd);
        buf->fd = -1;
    }
    pthread_mutex_unlock(&buf->lock);

    pthread_mutex_destroy(&buf->lock);
    free(buf);
}
