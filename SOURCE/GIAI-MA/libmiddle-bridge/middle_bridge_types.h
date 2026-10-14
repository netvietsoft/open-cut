// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_types.h
// Description: Core data types, memory layouts, and SWIG interfaces reverse-engineered from AArch64 ABI
// ===================================================================================

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <memory>

#ifdef __cplusplus
namespace vesdk {
namespace pub {

// ===================================================================================
// 1. BEZIER VELOCITY POINT & TIME RANGE STRUCTURES
// Cấu trúc Điểm Đường cong Vận tốc Bezier và Khoảng Thời gian
// ===================================================================================

/**
 * @brief 2D Point with Bezier tangents for velocity ramping curves.
 * Điểm 2D biểu diễn đường cong vận tốc với hai tay nắm tiếp tuyến Bezier.
 */
struct Point {
    double x;                    // 0x00: Tọa độ thời gian (0.0 .. 1.0 hoặc micro-giây)
    double y;                    // 0x08: Hệ số tốc độ (0.1x .. 100.0x)
    double control_point_left_x; // 0x10: Tay nắm tiếp tuyến bên trái X
    double control_point_left_y; // 0x18: Tay nắm tiếp tuyến bên trái Y
    double control_point_right_x;// 0x20: Tay nắm tiếp tuyến bên phải X
    double control_point_right_y;// 0x28: Tay nắm tiếp tuyến bên phải Y

    Point() : x(0.0), y(1.0),
              control_point_left_x(0.0), control_point_left_y(1.0),
              control_point_right_x(0.0), control_point_right_y(1.0) {}

    Point(double px, double py) : x(px), y(py),
                                  control_point_left_x(px), control_point_left_y(py),
                                  control_point_right_x(px), control_point_right_y(py) {}
};

/**
 * @brief 16-byte TimeRange structure representing start time and duration in microseconds.
 * Cấu trúc khoảng thời gian 16 bytes khớp thanh ghi SIMD q0 tại opcode 0x01fa72e8 và 0x020de894.
 */
struct TimeRange {
    int64_t start_time_us;       // 0x00: Thời điểm bắt đầu (micro-giây)
    int64_t duration_us;         // 0x08: Thời lượng phân đoạn (micro-giây)

    TimeRange() : start_time_us(0), duration_us(0) {}
    TimeRange(int64_t start, int64_t dur) : start_time_us(start), duration_us(dur) {}
};


// ===================================================================================
// 2. VELOCITY ALGORITHM REQUEST & RESPONSE STRUCTURES
// Cấu trúc Tham số Yêu cầu & Kết quả Thuật toán Vận tốc CapCut
// ===================================================================================

/**
 * @brief RunVelocityAlgorithmReqStruct holding parameters for audio-synced velocity curves.
 * Cấu trúc yêu cầu tính toán đường cong tốc độ khớp nhịp âm thanh.
 */
struct RunVelocityAlgorithmReqStruct {
    uint8_t header_pad[0x48];            // 0x00..0x47: Base class / SWIG header
    std::string video_path;              // 0x48..0x5f: Đường dẫn tệp video (opcode 0x01e3b4b4)
    TimeRange video_time_range;          // 0x60..0x6f: Khoảng thời gian video (opcode 0x01fa72ec)
    uint8_t mid_pad[0x10];               // 0x70..0x7f
    std::vector<int64_t> audio_beats;    // 0x80..0x97: Mảng các mốc nhịp âm thanh (audio beats)
    uint8_t pad_98[8];                   // 0x98..0x9f
    int32_t algo_mode;                   // 0xa0: Chế độ thuật toán (opcode 0x01e3b694)
    int32_t algo_phase;                  // 0xa4: Giai đoạn xử lý (opcode 0x01e3b6c0)
    uint8_t pad_a8[8];                   // 0xa8..0xaf
    std::string config_path;             // 0xb0..0xbf: Đường dẫn cấu hình JSON
    std::string cache_dir;               // 0xc0..0xd7: Thư mục đệm kết quả
    TimeRange audio_source_time_range;   // 0xd8..0xe7: Khoảng thời gian nguồn âm thanh (opcode 0x020de898)
    double video_speed;                  // 0xe8..0xef: Tốc độ cơ bản video (opcode 0x01f0538c)

    RunVelocityAlgorithmReqStruct() : algo_mode(0), algo_phase(0), video_speed(1.0) {}
};

/**
 * @brief RunVelocityAlgorithmRespStruct holding generated speed curve and beat marks.
 * Cấu trúc kết quả trả về chứa mảng điểm đường cong tốc độ và nhịp nhạc.
 */
struct RunVelocityAlgorithmRespStruct {
    uint8_t header_pad[0x20];            // 0x00..0x1f
    float progress;                      // 0x20: Tiến độ xử lý (0.0 .. 1.0)
    int32_t callback_type;               // 0x24: Loại callback thông báo
    uint8_t pad_28[0x18];                // 0x28..0x3f
    std::vector<int64_t> beats;          // 0x40..0x57: Các mốc nhịp drop đã tối ưu
    uint8_t pad_58[0x10];                // 0x58..0x67
    std::vector<Point> curve_speed;      // 0x68..0x7f: Mảng điểm đường cong Bezier (opcode 0x01f7d048)
    std::string error_info;              // 0x88..0x9f: Thông báo lỗi nếu có

    RunVelocityAlgorithmRespStruct() : progress(1.0f), callback_type(0) {}
};


// ===================================================================================
// 3. MATERIAL MASK STRUCTURES (VIDEO & PHOTO MASKS)
// Cấu trúc Mặt nạ Video & Ảnh (Tuyến tính, Gương, Hình tròn, Hình chữ nhật)
// ===================================================================================

enum class MaskType {
    LINEAR = 0,    // Mặt nạ tuyến tính chia đôi khung hình
    MIRROR = 1,    // Mặt nạ gương đối xứng hai bên
    CIRCLE = 2,    // Mặt nạ hình tròn / elip
    RECTANGLE = 3, // Mặt nạ hình chữ nhật bo góc
    STAR = 4,      // Mặt nạ ngôi sao nghệ thuật
    HEART = 5      // Mặt nạ trái tim tình yêu
};

/**
 * @brief MaskPositionInfo located at offset 0x90 in MaterialMask.
 * Thông số vị trí và hình học mặt nạ tại offset 0x90 (opcode 0x024ed08c).
 */
struct MaskPositionInfo {
    float center_x;                      // 0x00: Tọa độ tâm X (-1.0 .. 1.0 hoặc pixel)
    float center_y;                      // 0x04: Tọa độ tâm Y (-1.0 .. 1.0 hoặc pixel)
    float width;                         // 0x08: Chiều rộng mặt nạ
    float height;                        // 0x0c: Chiều cao mặt nạ
    float rotation_deg;                  // 0x10: Góc quay tính bằng độ
    float feather;                       // 0x14: Độ mờ viền mặt nạ (feathering 0.0 .. 1.0)
    float corner_radius;                 // 0x18: Bán kính bo góc (dùng cho Rectangle)
    bool invert;                         // 0x1c: Cờ đảo ngược vùng che mặt nạ

    MaskPositionInfo() : center_x(0.0f), center_y(0.0f),
                         width(0.5f), height(0.5f),
                         rotation_deg(0.0f), feather(0.0f),
                         corner_radius(0.0f), invert(false) {}
};

/**
 * @brief MaterialMask class managing masking shaders and canvas clipping.
 */
class MaterialMask {
public:
    uint8_t base_pad[0x90];              // 0x00..0x8f: Header & Resource IDs
    MaskPositionInfo position_info;      // 0x90..0xaf: Thông số hình học tại offset 0x90
    std::string resource_id;             // Định danh tài nguyên
    std::string path;                    // Đường dẫn tệp shader/config
    std::string node_name;               // Tên node đồ họa
    MaskType type;                       // Loại mặt nạ

    MaterialMask() : type(MaskType::LINEAR) {}
    virtual ~MaterialMask() {}

    MaskPositionInfo& getPositionInfo() { return position_info; }
    const MaskPositionInfo& getPositionInfo() const { return position_info; }
};


// ===================================================================================
// 4. COMPOSITION REPLACE STRUCTURES (NLE TRACK CLIP REPLACEMENT)
// Cấu trúc Thay thế Phân đoạn NLE (Composition Replace)
// ===================================================================================

/**
 * @brief CompositionReplaceParam for replacing a timeline clip preserving keyframes and speed.
 * Tham số thay thế clip trên timeline giữ nguyên keyframes, tốc độ và hiệu ứng.
 */
struct CompositionReplaceParam {
    uint8_t pad_00[8];                   // 0x00..0x07
    std::string seg_id;                  // 0x08..0x1f: ID phân đoạn clip cần thay thế
    std::string composition_param;       // 0x20..0x37: Cấu hình JSON composition mới

    CompositionReplaceParam() {}
};

} // namespace pub
} // namespace vesdk
#endif
