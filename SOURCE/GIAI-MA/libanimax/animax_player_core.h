// ============================================================================
// File: animax_player_core.h
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Declarations for lynx::animax::PlayerEventTracker, ColorUtil, Color,
//     DocumentData, AnimaXPlayerBuilder, TextContentDataSource, TextHelper,
//     YUVFrameInfo, VideoPlayerCustom, and AArch64 FDE dispatchers.
// VI: Khai báo cho lynx::animax::PlayerEventTracker, ColorUtil, Color,
//     DocumentData, AnimaXPlayerBuilder, TextContentDataSource, TextHelper,
//     YUVFrameInfo, VideoPlayerCustom và bộ điều phối FDE AArch64.
// ============================================================================
#pragma once

#include "animax_types.h"

namespace lynx {
namespace animax {

class PlayerEventTracker {
public:
    // 0x04c844..0x04c84c
    PlayerEventTracker() noexcept;
    // 0x04c84c..0x04c864
    void Reset() noexcept;
    // 0x04c868..0x04c870
    void MarkEvent(int32_t event_type) noexcept;
    // 0x04c874..0x04c878
    bool GetEventValue(int32_t event_type) const noexcept;

private:
    PlayerEventTrackerAbiLayout abi_{};
};

class ColorUtil {
public:
    // 0x04dc78..0x04de78: Parses "#RRGGBB" or "#RRGGBBAA" into 32-bit ARGB
    static uint32_t ParseHexColor(const std::string& hex_str) noexcept;
};

class Color {
public:
    // 0x0683d8..0x068408
    explicit Color(int32_t argb) noexcept;

    uint8_t A() const noexcept { return abi_.a; }
    uint8_t R() const noexcept { return abi_.r; }
    uint8_t G() const noexcept { return abi_.g; }
    uint8_t B() const noexcept { return abi_.b; }
    const ColorAbiLayout& Abi() const noexcept { return abi_; }

private:
    ColorAbiLayout abi_{};
};

class DocumentData {
public:
    // 0x068454..0x06849c
    DocumentData() noexcept;
    // 0x05cd9c..0x05cda0: `mov w0, #6; ret`
    int32_t GetValueType() const noexcept;
    // 0x068500..0x068508
    bool IsEmpty() const noexcept;

private:
    std::string text_;
    std::string font_name_;
    float size_{0.0f};
    DocumentJustification justification_{DocumentJustification::kLeftJustify};
    uint32_t tracking_{0};
    float line_height_{0.0f};
    float baseline_shift_{0.0f};
    int32_t fill_color_{0};
    int32_t stroke_color_{0};
    float stroke_width_{0.0f};
    bool stroke_over_fill_{false};
};

class AnimaXPlayerBuilder {
public:
    AnimaXPlayerBuilder() noexcept;
    // 0x0588d0..0x0588d4: `str s0, [x0]; ret`
    AnimaXPlayerBuilder& SetDevicePixelRatio(float dpr) noexcept;
    // 0x0588fc..0x058904: `and w8, w1, #1; strb w8, [x0, #0x18]; ret`
    AnimaXPlayerBuilder& EnableMultiThreadAccelerate(bool enable) noexcept;
    // 0x058908..0x058910: `and w8, w1, #1; strb w8, [x0, #0x19]; ret`
    AnimaXPlayerBuilder& SetSkipCountDownEvent(bool skip) noexcept;

    const AnimaXPlayerBuilderAbiLayout& Abi() const noexcept { return abi_; }

private:
    AnimaXPlayerBuilderAbiLayout abi_{};
};

class TextContentDataSource {
public:
    // 0x064dd8..0x064ddc: `stp x1, x2, [x0]; ret`
    TextContentDataSource(const void* text_layer, const void* layer_matrix) noexcept;
    const void* GetTextLayer() const noexcept { return abi_.text_layer_ptr; }
    const void* GetLayerMatrix() const noexcept { return abi_.layer_matrix_ptr; }

private:
    TextContentDataSourceAbiLayout abi_{};
};

class TextHelper {
public:
    // 0x065f8c..0x065f98: stores impl pointer into .bss @ 0x0a00e0
    static void RegisterImpl(void* impl) noexcept;
    static void*& ImplRef() noexcept;
};

class YUVFrameInfo {
public:
    YUVFrameInfo() noexcept;

    // 0x073f08..0x073f14
    uint32_t GetWidth() const noexcept;
    uint32_t GetHeight() const noexcept;

    // 0x073f18..0x073f58
    void SetLineSize(uint32_t channel, uint32_t size) noexcept;
    void SetLineWidth(uint32_t channel, uint32_t width) noexcept;
    void SetWidth(uint32_t width) noexcept;
    void SetHeight(uint32_t height) noexcept;
    void SetBitDepth(uint32_t bit_depth) noexcept;
    void SetYUVPixFmt(YUVPixFmt fmt) noexcept;

    // 0x073f5c..0x073ffc
    const std::vector<uint8_t>& GetChannelData(uint32_t channel) const noexcept;
    uint32_t GetChannelDataWidth(uint32_t channel) const noexcept;
    uint32_t GetChannelDataHeight(uint32_t channel) const noexcept;
    float GetVerticalSubsamplingFactor(uint32_t channel) const noexcept;
    void UpdateChannelData(uint32_t channel, const uint8_t* src) noexcept;

private:
    YUVFrameInfoAbiLayout abi_{};
    std::vector<uint8_t> channels_[3];
};

uint64_t ExecuteAnimaXFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;

} // namespace animax
} // namespace lynx
