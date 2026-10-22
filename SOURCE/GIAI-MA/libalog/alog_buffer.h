/**
 * @file alog_buffer.h
 * @brief ByteDance ALog Ring Buffer & MMAP Cache Management Interface.
 *        Giao diện quản lý bộ đệm xoay vòng và tệp ánh xạ bộ nhớ MMAP của ALog.
 */

#ifndef BYTEDANCE_ALOG_BUFFER_H
#define BYTEDANCE_ALOG_BUFFER_H

#include "alog_types.h"
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AlogBuffer_t {
    uint8_t*        mmap_addr;          ///< Address mapped by mmap()
    size_t          capacity;           ///< Total capacity of buffer
    size_t          write_pos;          ///< Current write offset
    size_t          read_pos;           ///< Current read offset (for drain/flush)
    int             fd;                 ///< File descriptor of cache file
    char            cache_path[ALOG_MAX_PATH_LEN]; ///< Path to current .alog.cache file
    bool            is_mmap;            ///< True if memory is mmap-backed, false if calloc
    pthread_mutex_t lock;               ///< Buffer access lock
} AlogBuffer;

/**
 * @brief Create and initialize a ring buffer, preferably backed by mmap.
 *        Khởi tạo bộ đệm xoay vòng, ưu tiên phân bổ bằng tệp ánh xạ mmap.
 */
AlogBuffer* alog_buffer_create(const char* cache_dir, const char* prefix, size_t capacity);

/**
 * @brief Write raw bytes into ring buffer. Handles wrap-around or auto-commit.
 *        Ghi mảng byte vào bộ đệm xoay vòng. Xử lý cuốn vòng hoặc đẩy ghi đĩa.
 */
int alog_buffer_write(AlogBuffer* buf, const uint8_t* data, size_t len);

/**
 * @brief Reserve a contiguous block in buffer for zero-copy formatting.
 *        Đặt trước một khối liên tục trong bộ đệm để ghi trực tiếp định dạng.
 */
uint8_t* alog_buffer_reserve(AlogBuffer* buf, size_t len);

/**
 * @brief Commit reserved bytes into the active buffer position.
 *        Xác nhận số byte đã ghi vào vị trí con trỏ hoạt động.
 */
void alog_buffer_commit(AlogBuffer* buf, size_t len);

/**
 * @brief Flush and sync buffer content to disk using msync or fsync.
 *        Đồng bộ nội dung bộ đệm ra đĩa vật lý bằng msync hoặc fsync.
 */
int alog_buffer_sync(AlogBuffer* buf);

/**
 * @brief Resize or re-map buffer when expansion is required.
 *        Thay đổi kích thước hoặc tái ánh xạ bộ đệm khi cần mở rộng.
 */
int alog_buffer_resize(AlogBuffer* buf, size_t new_capacity);

/**
 * @brief Clear buffer content and reset offsets.
 *        Xóa sạch nội dung bộ đệm và đặt lại các con trỏ offset.
 */
void alog_buffer_reset(AlogBuffer* buf);

/**
 * @brief Destroy buffer, unmap virtual address and close file descriptor.
 *        Hủy giải phóng bộ đệm, hủy ánh xạ vùng nhớ ảo và đóng file descriptor.
 */
void alog_buffer_destroy(AlogBuffer* buf);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_BUFFER_H
