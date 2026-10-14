// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_cutout_brush.h
// Description: AI Cutout, Interactive Brush Rasterization, and Intelligent Masking
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <mutex>
#include <atomic>
#include <cstdint>

#include "middleware_types.h"

namespace retouch::middleware {

/**
 * @brief Chế độ cọ quét tách nền (Cutout Brush Operations)
 */
enum class CutoutBrushMode : int32_t {
    PAINT = 1,          ///< Tô thêm vùng chọn (Thêm vào mặt nạ) / Add to mask
    ERASE = 2,          ///< Xóa bớt vùng chọn (Khấu trừ mặt nạ) / Subtract from mask
    SMART_SELECT = 3,   ///< Chọn thông minh AI / AI Smart edge snapping
    RESTORE = 4         ///< Khôi phục vùng gốc / Restore original content
};

/**
 * @brief Điểm dập cọ đơn lẻ (Single brush stamp point with elliptical rotation)
 */
struct BrushStamp {
    float x{0.0f};                  ///< Tọa độ X tâm cọ / Stamp center X
    float y{0.0f};                  ///< Tọa độ Y tâm cọ / Stamp center Y
    float radius{20.0f};            ///< Bán kính cọ / Brush radius
    float hardness{0.5f};          ///< Độ cứng viền [0.0f = mềm mịn, 1.0f = sắc nét] / Edge hardness
    float opacity{1.0f};           ///< Độ mờ đục [0.0f, 1.0f] / Brush flow / opacity
    float aspect_ratio{1.0f};      ///< Tỷ lệ elip (r_y / r_x) / Elliptical aspect ratio
    float angle_deg{0.0f};         ///< Góc xoay cọ / Brush stamp rotation in degrees

    BrushStamp() = default;
    BrushStamp(float px, float py, float r, float hard, float opac, float aspect = 1.0f, float angle = 0.0f)
        : x(px), y(py), radius(r), hardness(hard), opacity(opac), aspect_ratio(aspect), angle_deg(angle) {}
};

/**
 * @brief Một nét vẽ hoàn chỉnh gồm nhiều điểm dập (A continuous brush stroke)
 */
struct BrushStroke {
    int32_t stroke_id{0};           ///< Định danh nét vẽ / Unique stroke ID
    int32_t layer_id{0};            ///< Lớp áp dụng / Target layer ID
    CutoutBrushMode mode{CutoutBrushMode::PAINT}; ///< Chế độ nét vẽ / Brush mode
    std::vector<BrushStamp> stamps; ///< Danh sách các điểm dập / Stamp points
    RectF bounding_box{0.0f, 0.0f, 0.0f, 0.0f}; ///< Khung bao ảnh hưởng / Affected bounding box

    BrushStroke() = default;
};

/**
 * @brief Bộ đệm mặt nạ nhị phân / đơn kênh 8-bit (Single-channel 8-bit Alpha Mask Buffer)
 */
class CutoutMaskBuffer {
public:
    CutoutMaskBuffer();
    CutoutMaskBuffer(int32_t width, int32_t height);
    ~CutoutMaskBuffer() = default;

    bool allocate(int32_t width, int32_t height);
    void clear(uint8_t value = 0);

    int32_t getWidth() const { return m_width; }
    int32_t getHeight() const { return m_height; }
    int32_t getStride() const { return m_stride; }
    const uint8_t* getData() const { return m_data.data(); }
    uint8_t* getData() { return m_data.data(); }
    size_t getSize() const { return m_data.size(); }

    uint8_t getPixel(int32_t x, int32_t y) const;
    void setPixel(int32_t x, int32_t y, uint8_t val);

    /**
     * @brief Sao chép dữ liệu từ vùng đệm ngoài (Copy from external raw buffer)
     */
    bool copyFrom(const uint8_t* src, int32_t src_width, int32_t src_height, int32_t src_stride);

private:
    int32_t m_width{0};
    int32_t m_height{0};
    int32_t m_stride{0};
    std::vector<uint8_t> m_data;
};

/**
 * @brief Trình quản lý Tách nền AI và Cọ quét thông minh (Cutout & Brush Manager)
 * Khôi phục từ JNI RetouchSceneModelApi & IntelligentMaskCallbackJniImpl
 * (Opcode 0x12f4f48, 0x12f2f10, 0x12f6730, 0x12f55f0, 0x12f6548)
 */
class CutoutBrushManager {
public:
    CutoutBrushManager();
    ~CutoutBrushManager() = default;

    /**
     * @brief Thiết lập dữ liệu cọ quét và dập điểm lên mặt nạ lớp
     * Khớp opcode 0x12f4f48: Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_setCutoutBrushData
     *
     * @param x Tọa độ X (thực thể vector SIMD v0)
     * @param y Tọa độ Y (thực thể vector SIMD v1)
     * @param radius Bán kính cọ (SIMD v2)
     * @param hardness Độ cứng viền [0..1] (SIMD v3)
     * @param opacity Độ đậm cọ [0..1] (SIMD v4)
     * @param aspect_ratio Tỷ lệ elip cọ (SIMD v5)
     * @param angle_deg Góc xoay cọ (SIMD v6)
     * @param mode Chế độ (w5: 1=PAINT, 2=ERASE, 3=SMART, 4=RESTORE)
     * @param stroke_id Mã nét cọ (w6)
     * @param layer_id Mã layer đích (w7)
     * @return true nếu dập cọ thành công, false nếu layer_id hoặc tham số bất hợp lệ
     */
    bool setCutoutBrushData(float x, float y, float radius, float hardness, float opacity,
                            float aspect_ratio, float angle_deg,
                            int32_t mode, int32_t stroke_id, int32_t layer_id);

    /**
     * @brief Tiếp nhận kết quả mặt nạ thông minh từ AI Engine (xt_middleware_brush_cutout_recognition)
     * Khớp opcode 0x12f2f10: Java_com_bytedance_retouch_middleware_cutout_IntelligentMaskCallbackJniImpl_nativeOnIntelligentMaskResult
     *
     * @param status_code Mã trạng thái (0 = Thành công, khác 0 = Lỗi)
     * @param mask_data Con trỏ dữ liệu mặt nạ 8-bit
     * @param width Chiều rộng ảnh mặt nạ
     * @param height Chiều cao ảnh mặt nạ
     * @param stride Độ sải hàng (bytes per row)
     * @param target_layer_id Lớp áp dụng
     * @return true nếu tiếp nhận hợp lệ
     */
    bool onIntelligentMaskResult(int32_t status_code, const uint8_t* mask_data,
                                int32_t width, int32_t height, int32_t stride,
                                int32_t target_layer_id);

    /**
     * @brief Hủy tác vụ tạo trước ảnh nền AI đang chạy nền
     * Khớp opcode 0x12f6730: Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_cancelAIBackgroundPreview
     */
    void cancelAIBackgroundPreview();

    /**
     * @brief Kiểm tra xem tác vụ xem trước AI có đang bị hủy hay không
     */
    bool isAIBackgroundPreviewCancelled() const;

    /**
     * @brief Vào không gian làm việc tách nền AI
     * Khớp opcode 0x12f55f0: Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_enterAiBackgroundScene
     */
    bool enterAiBackgroundScene(int32_t layer_id);

    /**
     * @brief Thoát khỏi không gian tách nền AI
     */
    bool exitAiBackgroundScene(bool apply_changes);

    /**
     * @brief Cập nhật xem trước ảnh nền AI
     * Khớp opcode 0x12f6548: Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_updateAIBackgroundPreview
     */
    bool updateAIBackgroundPreview(int32_t layer_id, const std::string& prompt, float strength);

    /**
     * @brief Lấy tham chiếu mặt nạ của layer
     */
    CutoutMaskBuffer* getLayerMask(int32_t layer_id);

    /**
     * @brief Khởi tạo mặt nạ cho layer với kích thước xác định
     */
    bool initLayerMask(int32_t layer_id, int32_t width, int32_t height);

    /**
     * @brief Thuật toán quét dập cọ elip với làm mịn viền Hermite Smoothstep
     * Mathematical Subpixel Distance Field Brush Stamp Rasterization
     */
    static void rasterizeStamp(CutoutMaskBuffer& mask, const BrushStamp& stamp, CutoutBrushMode mode);

    /**
     * @brief Hòa trộn mặt nạ AI và nét cọ người dùng
     * Composite AI Segmentation Mask with User Brush Corrections
     */
    static bool compositeMasks(const CutoutMaskBuffer& ai_mask, const CutoutMaskBuffer& user_brush,
                              CutoutMaskBuffer& out_result, CutoutBrushMode blend_mode);

    /**
     * @brief Tự kiểm chứng tính đúng đắn của module (Self-Test Suite)
     */
    static bool runSelfTest();

private:
    std::map<int32_t, CutoutMaskBuffer> m_layer_masks;
    std::map<int32_t, CutoutMaskBuffer> m_ai_masks;
    std::vector<BrushStroke> m_stroke_history;
    std::atomic<bool> m_ai_preview_cancelled{false};
    std::atomic<bool> m_in_ai_scene{false};
    int32_t m_current_ai_layer_id{-1};
    mutable std::mutex m_mutex;
};

} // namespace retouch::middleware
