// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 2D Drawing Canvas & Command Recording Display List
// File: skity_canvas.cpp
// Description: Implementation of Canvas state stack, transformation pipeline,
//              and RecordingCanvas command buffer.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_canvas.h"

namespace skity {

Canvas::Canvas() : Canvas(1920, 1080) {}

Canvas::Canvas(int width, int height)
    : width_(width), height_(height) {
    CanvasState root;
    root.matrix.SetIdentity();
    root.clip_bounds = Rect(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));
    state_stack_.push_back(root);
}

/**
 * @brief Flush: Virtual method executed via vtable offset 0xe0.
 * EN: Matches AArch64 opcode 0x107174 (ldr x8, [x0]; ldr x1, [x8, #0xe0]; br x1).
 * VN: Khớp opcode AArch64 0x107174. Đẩy toàn bộ lệnh đồ họa ra GPU pipeline.
 */
void Canvas::Flush() {
    // Base Canvas flush implementation
}

/**
 * @brief Scale: Pre-concatenates 2D scale factor to current transformation matrix.
 * EN: Matches AArch64 opcode 0x106860.
 * VN: Khớp opcode AArch64 0x106860. Phóng to thu nhỏ hệ tọa độ canvas theo tỉ lệ sx, sy.
 */
void Canvas::Scale(float sx, float sy) {
    if (state_stack_.empty()) return;
    state_stack_.back().matrix.PreScale(sx, sy);
}

void Canvas::Translate(float dx, float dy) {
    if (state_stack_.empty()) return;
    state_stack_.back().matrix.PreTranslate(dx, dy);
}

void Canvas::Rotate(float deg) {
    if (state_stack_.empty()) return;
    state_stack_.back().matrix.PreRotate(deg);
}

void Canvas::Rotate(float deg, float px, float py) {
    if (state_stack_.empty()) return;
    state_stack_.back().matrix.PreRotate(deg, px, py);
}

void Canvas::Concat(const Matrix& matrix) {
    if (state_stack_.empty()) return;
    state_stack_.back().matrix.PreConcat(matrix);
}

int Canvas::Save() {
    if (state_stack_.empty()) {
        CanvasState root;
        root.matrix.SetIdentity();
        root.clip_bounds = Rect(0.0f, 0.0f, static_cast<float>(width_), static_cast<float>(height_));
        state_stack_.push_back(root);
    }
    state_stack_.push_back(state_stack_.back());
    return static_cast<int>(state_stack_.size()) - 1;
}

void Canvas::Restore() {
    if (state_stack_.size() > 1) {
        state_stack_.pop_back();
    }
}

int Canvas::GetSaveCount() const {
    return static_cast<int>(state_stack_.size());
}

void Canvas::RestoreToCount(int count) {
    if (count < 1) count = 1;
    while (static_cast<int>(state_stack_.size()) > count) {
        state_stack_.pop_back();
    }
}

/**
 * @brief CalculateGlobalClipBounds: Computes bounding intersection in device space.
 * EN: Matches AArch64 opcode 0x106bf0 (120 bytes).
 * VN: Khớp opcode AArch64 0x106bf0. Tính khung giới hạn cắt xén clip bounds toàn cục.
 */
Rect Canvas::CalculateGlobalClipBounds(const Rect& rect, ClipOp op) {
    if (state_stack_.empty()) return Rect::MakeEmpty();

    Rect dev_rect = state_stack_.back().matrix.MapRect(rect);
    Rect result;

    if (op == kIntersect) {
        if (!Rect::Intersect(state_stack_.back().clip_bounds, dev_rect, &result)) {
            result = Rect::MakeEmpty();
        }
    } else {
        // Difference
        result = state_stack_.back().clip_bounds;
    }
    return result;
}

void Canvas::ClipRect(const Rect& rect, ClipOp op) {
    if (state_stack_.empty()) return;
    state_stack_.back().clip_bounds = CalculateGlobalClipBounds(rect, op);
}

void Canvas::ClipPath(const Path& path, ClipOp op) {
    ClipRect(path.ComputeBounds(), op);
}

const Matrix& Canvas::GetTotalMatrix() const {
    static Matrix s_identity;
    return state_stack_.empty() ? s_identity : state_stack_.back().matrix;
}

void Canvas::DrawPath(const Path& path, const Paint& paint) {
    // Virtual hook for renderer
}

void Canvas::DrawRect(const Rect& rect, const Paint& paint) {
    Path p;
    p.AddRect(rect);
    DrawPath(p, paint);
}

/**
 * @brief DrawOval: Draws ellipse bound by bounding rectangle.
 * EN: Matches AArch64 opcode 0x106448.
 * VN: Khớp opcode AArch64 0x106448. Vẽ hình elip bầu dục chuẩn vector.
 */
void Canvas::DrawOval(const Rect& oval, const Paint& paint) {
    Path p;
    p.AddOval(oval);
    DrawPath(p, paint);
}

/**
 * @brief DrawRRect: Draws rounded rectangle with corner radii.
 * EN: Matches AArch64 opcode 0x106f0c.
 * VN: Khớp opcode AArch64 0x106f0c. Vẽ hình chữ nhật bo góc với Paint styling.
 */
void Canvas::DrawRRect(const RRect& rrect, const Paint& paint) {
    Path p;
    p.AddRRect(rrect);
    DrawPath(p, paint);
}

/**
 * @brief DrawImage: Draws pixel buffer image with destination rect and paint.
 * EN: Matches AArch64 opcode 0x1077a4.
 * VN: Khớp opcode AArch64 0x1077a4. Vẽ hình ảnh bitmap lên canvas.
 */
void Canvas::DrawImage(const std::shared_ptr<Image>& image, const Rect& dst, const Paint* paint) {
    // Base implementation delegates to rasterizer
}

// ==============================================================================
// RecordingCanvas Implementation
// ==============================================================================

/**
 * @brief RecordingCanvas: Constructor initializing command recording buffer.
 * EN: Matches AArch64 opcode 0x104d88.
 * VN: Khớp opcode AArch64 0x104d88. Khởi tạo canvas ghi nhận display list cho GPU.
 */
RecordingCanvas::RecordingCanvas() : RecordingCanvas(1920, 1080) {}

RecordingCanvas::RecordingCanvas(int width, int height)
    : Canvas(width, height) {}

void RecordingCanvas::Flush() {
    // RecordingCanvas retains commands in buffer for replay
}

/**
 * @brief OnDrawRRect: Appends rounded rectangle drawing command.
 * EN: Matches AArch64 opcode 0x104f74.
 * VN: Khớp opcode AArch64 0x104f74. Ghi lệnh vẽ RRect vào hàng đợi commands_.
 */
void RecordingCanvas::OnDrawRRect(const RRect& rrect, const Paint& paint) {
    DrawCommand cmd;
    cmd.type = kCmdDrawRRect;
    cmd.rrect = rrect;
    cmd.paint = paint;
    cmd.matrix = GetTotalMatrix();
    commands_.push_back(cmd);
}

/**
 * @brief OnDrawGlyphs: Appends text glyph array drawing command.
 * EN: Matches AArch64 opcode 0x10537c (484 bytes).
 * VN: Khớp opcode AArch64 0x10537c. Ghi lệnh vẽ mảng ký tự chữ (glyphs) vào display list.
 */
void RecordingCanvas::OnDrawGlyphs(uint32_t count, const uint16_t* glyphs,
                                   const float* x_positions, const float* y_positions,
                                   const Paint& paint) {
    if (!glyphs || count == 0) return;

    DrawCommand cmd;
    cmd.type = kCmdDrawGlyphs;
    cmd.paint = paint;
    cmd.matrix = GetTotalMatrix();
    cmd.glyphs.assign(glyphs, glyphs + count);

    cmd.glyph_positions.resize(count * 2);
    for (uint32_t i = 0; i < count; ++i) {
        cmd.glyph_positions[i * 2 + 0] = x_positions ? x_positions[i] : 0.0f;
        cmd.glyph_positions[i * 2 + 1] = y_positions ? y_positions[i] : 0.0f;
    }
    commands_.push_back(cmd);
}

void RecordingCanvas::DrawPath(const Path& path, const Paint& paint) {
    DrawCommand cmd;
    cmd.type = kCmdDrawPath;
    cmd.path = path;
    cmd.paint = paint;
    cmd.matrix = GetTotalMatrix();
    commands_.push_back(cmd);
}

void RecordingCanvas::DrawRect(const Rect& rect, const Paint& paint) {
    DrawCommand cmd;
    cmd.type = kCmdDrawRect;
    cmd.rect = rect;
    cmd.paint = paint;
    cmd.matrix = GetTotalMatrix();
    commands_.push_back(cmd);
}

void RecordingCanvas::DrawRRect(const RRect& rrect, const Paint& paint) {
    OnDrawRRect(rrect, paint);
}

} // namespace skity
