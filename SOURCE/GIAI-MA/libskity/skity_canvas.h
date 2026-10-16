// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 2D Drawing Canvas & Command Recording Display List
// File: skity_canvas.h
// Description: Skity Canvas abstraction and RecordingCanvas display list
//              for hardware-accelerated vector graphics rendering.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_CANVAS_H_
#define NEXTAI_OPENCUT_SKITY_CANVAS_H_

#include <vector>
#include <memory>
#include "skity_geometry.h"
#include "skity_matrix.h"
#include "skity_path.h"
#include "skity_paint_effects.h"

namespace skity {

class Image {
public:
    Image(uint32_t width, uint32_t height) : width_(width), height_(height) {}
    uint32_t width() const { return width_; }
    uint32_t height() const { return height_; }
private:
    uint32_t width_;
    uint32_t height_;
};

class Canvas {
public:
    enum ClipOp {
        kDifference = 0,
        kIntersect = 1,
    };

    Canvas();
    Canvas(int width, int height);
    virtual ~Canvas() = default;

    // Opcode 0x107174: Flush (virtual tail call via vtable offset 0xe0)
    virtual void Flush();

    // Opcode 0x106860: Scale
    void Scale(float sx, float sy);
    void Translate(float dx, float dy);
    void Rotate(float deg);
    void Rotate(float deg, float px, float py);
    void Concat(const Matrix& matrix);

    // Save & Restore stack
    int Save();
    void Restore();
    int GetSaveCount() const;
    void RestoreToCount(int count);

    // Clipping
    void ClipRect(const Rect& rect, ClipOp op = kIntersect);
    void ClipPath(const Path& path, ClipOp op = kIntersect);

    // Opcode 0x106bf0: CalculateGlobalClipBounds
    Rect CalculateGlobalClipBounds(const Rect& rect, ClipOp op);

    // Drawing primitives
    virtual void DrawPath(const Path& path, const Paint& paint);
    virtual void DrawRect(const Rect& rect, const Paint& paint);

    // Opcode 0x106448: DrawOval
    virtual void DrawOval(const Rect& oval, const Paint& paint);

    // Opcode 0x106f0c: DrawRRect
    virtual void DrawRRect(const RRect& rrect, const Paint& paint);

    // Opcode 0x1077a4: DrawImage
    virtual void DrawImage(const std::shared_ptr<Image>& image, const Rect& dst,
                           const Paint* paint = nullptr);

    // Matrix & Dimensions
    const Matrix& GetTotalMatrix() const;
    int width() const { return width_; }
    int height() const { return height_; }

protected:
    struct CanvasState {
        Matrix matrix;
        Rect clip_bounds;
    };

    int width_;
    int height_;
    std::vector<CanvasState> state_stack_;
};

// ==============================================================================
// RecordingCanvas: Display list recording engine
// ==============================================================================
class RecordingCanvas : public Canvas {
public:
    enum CommandType {
        kCmdSave = 0,
        kCmdRestore = 1,
        kCmdConcat = 2,
        kCmdClipRect = 3,
        kCmdDrawPath = 4,
        kCmdDrawRect = 5,
        kCmdDrawRRect = 6,
        kCmdDrawGlyphs = 7,
        kCmdDrawImage = 8,
    };

    struct DrawCommand {
        CommandType type;
        Path path;
        Rect rect;
        RRect rrect;
        Paint paint;
        Matrix matrix;
        std::vector<uint16_t> glyphs;
        std::vector<float> glyph_positions;
    };

    // Opcode 0x104d88: RecordingCanvas Constructor
    RecordingCanvas();
    RecordingCanvas(int width, int height);
    ~RecordingCanvas() override = default;

    // Opcode 0x105978: OnGetWidth
    int OnGetWidth() const { return width_; }
    int OnGetHeight() const { return height_; }

    void Flush() override;

    // Opcode 0x104f74: OnDrawRRect
    void OnDrawRRect(const RRect& rrect, const Paint& paint);

    // Opcode 0x10537c: OnDrawGlyphs
    void OnDrawGlyphs(uint32_t count, const uint16_t* glyphs,
                      const float* x_positions, const float* y_positions,
                      const Paint& paint);

    void DrawPath(const Path& path, const Paint& paint) override;
    void DrawRect(const Rect& rect, const Paint& paint) override;
    void DrawRRect(const RRect& rrect, const Paint& paint) override;

    const std::vector<DrawCommand>& GetCommands() const { return commands_; }
    size_t CommandCount() const { return commands_.size(); }
    void ClearCommands() { commands_.clear(); }

private:
    std::vector<DrawCommand> commands_;
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_CANVAS_H_
