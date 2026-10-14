// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: ttffmpeg_types.h
// Description: Core data types and memory layouts reverse-engineered from AArch64 ABI
// ===================================================================================

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ===================================================================================
// 1. H.264 / H.265 NAL UNIT & PARAMETER SET STRUCTURES
// Cấu trúc NAL Unit và Bộ tham số H.264 / H.265
// ===================================================================================

/**
 * @brief H2645NAL structure representing a Network Abstraction Layer unit.
 * Kích thước cấp phát: 0x68 (104 bytes) tại offset opcode 0x1c8298.
 */
typedef struct H2645NAL {
    void* raw_data;          // 0x00: Con trỏ dữ liệu thô / Raw buffer pointer
    void* internal_ref;      // 0x08: Con trỏ tham chiếu nội bộ / Internal reference
    int32_t size;            // 0x0c: Kích thước dữ liệu NAL / NAL payload size
    uint8_t* data;           // 0x10: Con trỏ payload đã trích xuất RBSP / Extracted RBSP data pointer
    int32_t type;            // 0x18: Loại NAL (SPS, PPS, IDR, Non-IDR...) / NAL unit type
    int32_t temporal_id;     // 0x1c: Temporal ID cho SVC/HEVC
    uint8_t padding[0x38];   // 0x20..0x57: Reserved metadata
    void* extra_alloc;       // 0x58: Con trỏ bộ nhớ phụ được giải phóng tại 0x1c82c4
    uint8_t tail_padding[8]; // 0x60..0x67
} H2645NAL;

/**
 * @brief SPS (Sequence Parameter Set) structure.
 * Kích thước cấp phát: 0x14b8 (5,304 bytes) tại opcode 0x1c8390.
 */
typedef struct SPS {
    uint32_t sps_id;              // 0x00: SPS ID
    uint32_t profile_idc;         // 0x04 / 0x14: Profile IDC (Baseline, Main, High...)
    uint32_t level_idc;           // 0x08 / 0x40: Level IDC (3.1, 4.0, 5.1...)
    uint32_t chroma_format_idc;   // 0x18: Định dạng màu (4:2:0, 4:2:2, 4:4:4)
    uint32_t bit_depth_luma;      // 0x1c: Độ sâu màu Luma (8-bit, 10-bit)
    uint32_t bit_depth_chroma;    // 0x20: Độ sâu màu Chroma (8-bit, 10-bit)
    uint32_t log2_max_frame_num;  // 0x24: Số khung hình tối đa log2
    uint32_t pic_order_cnt_type;  // 0x28: Kiểu tính POC (0, 1, 2)
    uint8_t reserved[0x26c];      // 0x2c..0x297: Các cờ VUI và thông số cắt cúp
    uint32_t max_num_reorder;     // 0x298: Số khung hình sắp xếp lại tối đa (sar/reorder)
    uint8_t extended[0x121c];     // 0x29c..0x14b7: Mở rộng tham số VUI timing
} SPS;

/**
 * @brief PPS (Picture Parameter Set) structure.
 * Kích thước cấp phát: 0x2a740 (173,888 bytes) tại opcode 0x1c8364.
 */
typedef struct PPS {
    uint32_t sps_id;              // 0x00: Tham chiếu tới SPS ID
    uint32_t pps_id;              // 0x04: PPS ID
    int32_t pic_order_present;    // 0x08: Cờ pic_order_present_flag
    uint32_t num_ref_idx_l0;      // 0x0c: Số ảnh tham chiếu List 0
    uint32_t num_ref_idx_l1;      // 0x10: Số ảnh tham chiếu List 1
    uint8_t payload[0x2a72c];     // 0x14..0x2a73f: Bảng ma trận lượng tử hóa (Scaling lists)
} PPS;

/**
 * @brief H264ParamSets structure managing SPS and PPS lists.
 * Kích thước cấp phát: 0x920 (2,336 bytes) tại opcode 0x1c82f8.
 */
typedef struct H264ParamSets {
    SPS* sps_list[32];            // 0x000..0x0ff: 32 con trỏ SPS (0x20 con trỏ x 8 bytes)
    PPS* pps_list[256];           // 0x100..0x8ff: 256 con trỏ PPS (0x100 con trỏ x 8 bytes)
    PPS* current_pps;             // 0x900 / 0x910: Con trỏ PPS hiện hành
    SPS* current_sps;             // 0x918: Con trỏ SPS hiện hành
} H264ParamSets;

/**
 * @brief H264POCContext structure for Picture Order Count tracking.
 * Kích thước cấp phát: 0x2c (44 bytes) tại opcode 0x1c8408.
 */
typedef struct H264POCContext {
    int32_t field_00;             // 0x00: POC index 7 (poc_msb / prev_poc)
    int32_t field_04;             // 0x04: POC index 6 (poc_lsb)
    int32_t field_08;             // 0x08: POC index 8 (prev_frame_num)
    int32_t delta_poc[2];         // 0x0c, 0x10: Mảng delta POC [0] và [1] (offset 0x0c + idx*4)
    int32_t field_14;             // 0x14: POC index 4 (delta_poc_bottom)
    int32_t field_18;             // 0x18: POC index 2 (prev_poc_msb)
    int32_t field_1c;             // 0x1c: POC index 3 (prev_poc_lsb)
    int32_t field_20;             // 0x20: POC index 5 (prev_frame_num_offset)
    int32_t field_24;             // 0x24: POC index 1 (poc_cycle)
    int32_t field_28;             // 0x28: POC index 0 (current_poc)
} H264POCContext;


// ===================================================================================
// 2. NETWORK PROTOCOLS & URL PROTOCOL HOOKS
// Cấu trúc Giao thức Mạng và Hooks của ByteDance
// ===================================================================================

/**
 * @brief URLProtocol structure matching FFmpeg standard protocol contract.
 * Kích thước xác thực ABI: 0xc0 (192 bytes) tại opcode 0x343c1c và 0x343d6c.
 */
typedef struct URLProtocol {
    const char* name;                              // 0x00: Tên giao thức ("mdl", "httpx", "quic"...)
    int (*url_open)(void *h, const char *url, int flags);       // 0x08: Hàm mở URL
    int (*url_open2)(void *h, const char *url, int flags, void **options); // 0x10
    int (*url_accept)(void *s, void **c);          // 0x18
    int (*url_handshake)(void *c);                 // 0x20
    int (*url_read)(void *h, unsigned char *buf, int size);     // 0x28: Hàm đọc dữ liệu
    int (*url_write)(void *h, const unsigned char *buf, int size); // 0x30: Hàm ghi dữ liệu
    int64_t (*url_seek)(void *h, int64_t pos, int whence);      // 0x38: Hàm tua vị trí
    int (*url_close)(void *h);                     // 0x40: Hàm đóng kết nối
    int (*url_read_pause)(void *h, int pause);     // 0x48: Tạm dừng đọc stream
    int64_t (*url_read_seek)(void *h, int stream_index, int64_t timestamp, int flags); // 0x50
    int (*url_get_file_handle)(void *h);           // 0x58
    int (*url_get_multi_file_handle)(void *h, int **handles, int *numhandles); // 0x60
    int (*url_get_short_seek)(void *h);            // 0x68
    int (*url_shutdown)(void *h, int flags);       // 0x70
    int priv_data_size;                            // 0x78: Kích thước context riêng
    const void *priv_data_class;                   // 0x80: AVClass con trỏ
    int flags;                                     // 0x88: Cờ giao thức (URL_PROTOCOL_FLAG_*)
    int (*url_check)(void *h, int mask);           // 0x90
    int (*url_open_dir)(void *h);                  // 0x98
    int (*url_read_dir)(void *h, void *next);      // 0xa0
    int (*url_close_dir)(void *h);                 // 0xa8
    int (*url_delete)(void *h);                    // 0xb0
    int (*url_move)(void *h_src, void *h_dst);     // 0xb8
} URLProtocol;

/**
 * @brief TTNetworkIOHooks for routing DNS and socket calls through TTNet/Cronet.
 * Bảng hooks tại địa chỉ toàn cục 0x7be350.
 */
typedef struct TTNetworkIOHooks {
    int (*dns_resolve)(const char *host, char *ip_buf, int ip_buf_len); // 0x7be350 + 0x00
    int (*dns_cancel)(const char *host);                                // 0x7be350 + 0x08
    void (*dns_free)(void *ctx);                                        // 0x7be350 + 0x10
    void* (*io_open)(const char *url, int flags);                       // 0x7be350 + 0x18
    int (*io_read)(void *handle, uint8_t *buf, int size);               // 0x7be350 + 0x20
    int64_t (*io_seek)(void *handle, int64_t offset, int whence);       // 0x7be350 + 0x28
    int (*io_close)(void *handle);                                      // 0x7be350 + 0x30
} TTNetworkIOHooks;


// ===================================================================================
// 3. DRM CRYPTOGRAPHY & DECRYPTION CONTEXT
// Cấu trúc Giải mã DRM và Mở rộng Crypto
// ===================================================================================

/**
 * @brief TTDRMCallbacks structure for custom DRM decryption engine.
 * Đăng ký tại địa chỉ toàn cục 0x7c57d0 (opcode 0x364974).
 */
typedef struct TTDRMCallbacks {
    int (*drm_init)(void *ctx, const uint8_t *key, int key_len);       // 0x7c57d0 + 0x00
    int (*drm_decrypt)(void *ctx, uint8_t *data, int data_len);        // 0x7c57d0 + 0x08
    void (*drm_free)(void *ctx);                                       // 0x7c57d0 + 0x10
} TTDRMCallbacks;

/**
 * @brief TTDeprecatedCtx for Rijndael / Galois Field GF(2^8) stream cipher.
 * Kích thước cấp phát: 0x130 (304 bytes) tại opcode 0x3636c0.
 * Khởi tạo bảng GF(2^8) đa thức tối giản 0x11b tại opcode 0x36373c.
 */
typedef struct TTDeprecatedCtx {
    void* user_data;              // 0x000: Con trỏ dữ liệu người dùng
    uint8_t sbox[256];            // 0x008..0x107: Bảng S-box 256 phần tử
    uint8_t inv_sbox[256];        // Bảng S-box nghịch đảo
    uint32_t key_schedule[60];    // Bảng khóa vòng
    uint64_t processed_bytes;     // 0x128: Số byte đã xử lý
} TTDeprecatedCtx;


// ===================================================================================
// 4. TTM APPLICATION IDENTIFIER & BRIDGE
// Định danh Ứng dụng TTM và Cầu nối FFmpeg
// ===================================================================================

#define TTM_APP_CALLBACK_VERSION 0x01343f0f // 20201231 in hex (opcode 0x3775e4, 0x3775e8)

/**
 * @brief TTMApp structure passed into av_ttm_app_cast.
 */
typedef struct TTMApp {
    const void* magic;            // 0x00: Con trỏ magic khớp với av_ttm_app_magic()
    uint32_t version;             // 0x08: Phiên bản callback (phải khớp TTM_APP_CALLBACK_VERSION)
    void* player_context;         // 0x10: Con trỏ context của TTPlayer
    void* callback_table;         // 0x18: Bảng callback điều khiển luồng
} TTMApp;

#ifdef __cplusplus
}
#endif
