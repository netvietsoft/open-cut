// ============================================================================
// File: tttext_lite_types.h
// Target: libtttext_lite.so (297,312 bytes, SHA-256: 8860b2ff8bdd...60282e)
// Clean-Room C++17 Reconstruction — Exact ABI Structs, Enums & Constants
// Tái cấu trúc phòng sạch C++17 — Cấu trúc ABI, Enum và Hằng số chính xác
// ============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <array>

namespace ttoffice {
namespace tttext {

// ============================================================================
// 1. IEEE-754 Floating-Point Tolerance & Default Style Constants
//    Hằng số sai số dấu phẩy động IEEE-754 và hằng số kiểu mặc định (.rodata)
// ============================================================================
// Observed at 0x03d29c..0x03d2a0, 0x03d840..0x03d844, 0x03da9c..0x03daa4:
//   mov w8, #0xb717; movk w8, #0x38d1, lsl #16 -> 0x38d1b717 = 1.0e-4f (0.0001f)
constexpr uint32_t kFloatEpsilonBits = 0x38D1B717u;
constexpr float kFloatEpsilon = 1.0e-4f;

// Observed at .rodata 0x00dab8: 55 55 55 41 00 00 80 3f
//   0x41555555 = 13.333333f (40.0f / 3.0f default text size in px)
//   0x3f800000 = 1.0f (default text scale factor)
constexpr uint32_t kDefaultTextSizeBits = 0x41555555u;
constexpr float kDefaultTextSizePx = 13.333333015441895f;
constexpr uint32_t kDefaultTextScaleBits = 0x3F800000u;
constexpr float kDefaultTextScale = 1.0f;

// Observed at 0x033a58..0x033a64:
//   mov w8, #0x190; movk w8, #5, lsl #16 -> 0x00050190 (Weight=400, Width=5, Slant=0)
constexpr uint32_t kDefaultFontStylePacked = 0x00050190u;

// Observed at 0x033a6c: mov w10, #-0x1000000 -> 0xFF000000 (Opaque Black ARGB)
constexpr uint32_t kDefaultForegroundColor = 0xFF000000u;

// ============================================================================
// 2. Core Enumerations (Observed from Demangled Symbols & Disassembly)
//    Các kiểu liệt kê cốt lõi (Quan sát từ ký hiệu giải mã và mã máy)
// ============================================================================
enum class WriteDirection : uint8_t {
    kAuto = 0,
    kLTR  = 1,
    kRTL  = 2,
};

enum class BoundaryType : uint8_t {
    kNone      = 0,
    kChar      = 1,
    kWord      = 2,
    kLineBreak = 3,
    kMustBreak = 4,
    kParagraph = 5,
};

enum class LineBreakStrategy : uint8_t {
    kSimple       = 0,
    kHighQuality  = 1,
    kBalanced     = 2,
};

enum class CharacterVerticalAlignment : uint8_t {
    kTop        = 0,
    kTextTop    = 1,
    kMiddle     = 2,
    kCenter     = 3,
    kBaseLine   = 4,
    kSubScript  = 5,
    kSuperScript= 6,
    kTextBottom = 7,
    kBottom     = 8,
};

enum class ParagraphHorizontalAlignment : uint8_t {
    kLeft       = 0,
    kCenter     = 1,
    kRight      = 2,
    kJustify    = 3,
    kDistributed= 4,
};

enum class RulerType : uint8_t {
    kNormal  = 0,
    kAtLeast = 1,
    kExact   = 2,
};

enum class LayoutMode : uint8_t {
    kDefinite = 0,
    kAtMost   = 1,
    kIndefinite = 2,
};

enum class OverflowWrap : uint8_t {
    kNormal     = 0,
    kBreakWord  = 1,
    kAnywhere   = 2,
};

enum class ShaperType : uint8_t {
    kPlatform = 0,
    kSkShaper = 1,
    kHarfBuzz = 2,
};

enum class PlatformType : uint8_t {
    kUnknown = 0,
    kAndroid = 1,
    kIOS     = 2,
    kHarmony = 3,
};

// Observed at StyleManager::GetStyleValue (0x033990): sub w8, w1, #6; cmp w8, #0xd
enum class AttributeType : uint32_t {
    kFontDescriptor             = 0,
    kTextSize                   = 1,
    kTextScale                  = 2,
    kLetterSpacing              = 3,
    kBaselineOffset             = 4,
    kWordSpacing                = 5,
    kForegroundColor            = 6,   // case 0 -> +0x30 (u32)
    kBackgroundColor            = 7,   // case 1 -> +0x34 (u32)
    kDecorationColor            = 8,   // case 2 -> +0x38 (u32)
    kDecorationType             = 9,   // case 3 -> +0x3c (u8)
    kDecorationStyle            = 10,  // case 4 -> +0x3d (u8)
    kDecorationThickness        = 11,  // case 5 -> +0x40 (f32 bits)
    kFontFeatureSettings        = 12,  // case 6 -> +0x48 (u64)
    kBold                       = 13,  // case 7 -> +0x50 (u8)
    kItalic                     = 14,  // case 8 -> +0x51 (u8)
    kTextShadowList             = 15,  // case 9 -> +0x78 (ptr)
    kForegroundPainter          = 16,  // case 10 -> +0x60 (u64)
    kBackgroundPainter          = 17,  // case 11 -> +0x68 (u64)
    kWordBreak                  = 18,  // case 12 -> +0x70 (u8)
    kSubSupType                 = 19,  // case 13 -> +0x74 (u32)
};

enum class MethodType : uint32_t {
    kStaticMethod   = 0,
    kInstanceMethod = 1,
};

enum class LayoutResult : uint32_t {
    kNormal   = 0,
    kBreakLine= 1,
    kOverflow = 2,
    kRelayout = 3,
};

// ============================================================================
// 3. Geometric & Range Primitives (Observed at 0x03d28c .. 0x03db98)
//    Các cấu trúc hình học và khoảng giá trị (Quan sát tại 0x03d28c .. 0x03db98)
// ============================================================================
struct PointF {
    float x{0.0f};
    float y{0.0f};

    // _ZNK8ttoffice6tttext6PointFeqERKS1_ (0x03d28c, 100 B)
    bool operator==(const PointF& rhs) const noexcept;
};

struct Range {
    uint32_t start{0};
    uint32_t end{0};

    constexpr uint32_t GetLength() const noexcept {
        return (end >= start) ? (end - start) : 0u;
    }
    constexpr bool IsEmpty() const noexcept {
        return GetLength() == 0u;
    }

    // Observed methods at 0x03d2f0 .. 0x03d578
    void SetLength(uint32_t len) noexcept;
    void Merge(const Range& other) noexcept;
    static Range Intersect(const Range& a, const Range& b) noexcept;
    void Intersect(const Range& other) noexcept;
    Range Difference(const Range& other) noexcept;
    void Swap() noexcept;
    bool operator==(const Range& rhs) const noexcept;
    bool operator<(const Range& rhs) const noexcept;
    bool operator>(const Range& rhs) const noexcept;
};

struct RangeF {
    float start{0.0f};
    float end{0.0f};

    // Observed methods at 0x03d57c .. 0x03d81f
    void Merge(const RangeF& other) noexcept;
    RangeF Difference(const RangeF& other) noexcept;
};

struct RectF {
    float left{0.0f};
    float top{0.0f};
    float width{0.0f};
    float height{0.0f};

    // Observed methods at 0x03d820 .. 0x03db98
    bool Contains(float px, float py) const noexcept;
    bool InterSects(float l, float t, float r, float b) const noexcept;
    bool InterSects(const RectF& other) const noexcept;
    bool IsEmpty() const noexcept;
    bool operator==(const RectF& other) const noexcept;
};

// ============================================================================
// 4. Typography & Styling ABI Structures (Observed at 0x02ca84 .. 0x034707)
//    Cấu trúc ABI kiểu dáng và định dạng chữ (Quan sát tại 0x02ca84 .. 0x034707)
// ============================================================================
struct TTColor {
    uint32_t argb{kDefaultForegroundColor};

    // _ZNK8ttoffice6tttext7TTColor11ToHexStringEv (0x03453c, 200 B)
    std::string ToHexString() const;
    // _ZN8ttoffice6tttext7TTColor13ReadHexStringEPKc (0x0346a0, 104 B)
    static TTColor ReadHexString(const char* hex_str) noexcept;
};

struct FontStyle {
    uint16_t weight{400};  // bits [0..15]: 0x0190 = 400
    uint8_t width{5};      // bits [16..23]: 5 = Normal
    uint8_t slant{0};      // bits [24..31]: 0 = Upright, 1 = Italic, 2 = Oblique

    constexpr uint32_t Pack() const noexcept {
        return static_cast<uint32_t>(weight) |
               (static_cast<uint32_t>(width) << 16) |
               (static_cast<uint32_t>(slant) << 24);
    }
    static constexpr FontStyle Unpack(uint32_t packed) noexcept {
        return FontStyle{
            static_cast<uint16_t>(packed & 0xFFFFu),
            static_cast<uint8_t>((packed >> 16) & 0xFFu),
            static_cast<uint8_t>((packed >> 24) & 0xFFu)
        };
    }
};

struct FontDescriptor {
    std::vector<std::string> family_name_list{};
    FontStyle font_style{};
    uint64_t platform_font_handle{0};
};

// Observed at LayoutMeasurer::CalcRunHeightByLinePitch (0x02ca84)
// and ParagraphStyle::GetSpacing/SetSpacing (0x031A60..0x031C10):
//   +0x00: float after_px
//   +0x04: float before_px
//   +0x08: float line_space_before_px
//   +0x0C: float line_space_after_px
//   +0x10: float reserved_px
//   +0x14: float line_height_px (loaded at 0x02cac0 & 0x02cb0c: ldr s2, [x0, #0x14])
//   +0x18: float line_height_percent (loaded at 0x02cacc: ldr s2, [x0, #0x18])
//   +0x1C: RulerType line_height_rule (loaded at 0x02ca84: ldrb w8, [x0, #0x1c])
struct Spacing {
    float after_px{0.0f};            // +0x00
    float before_px{0.0f};           // +0x04
    float line_space_before_px{0.0f};// +0x08
    float line_space_after_px{0.0f}; // +0x0C
    float reserved_px{0.0f};         // +0x10
    float line_height_px{0.0f};      // +0x14
    float line_height_percent{1.0f}; // +0x18
    RulerType line_height_rule{RulerType::kNormal}; // +0x1C
    uint8_t pad[3]{0, 0, 0};         // +0x1D..+0x1F
};

struct TextShadow {
    uint32_t color{0};
    float offset_x{0.0f};
    float offset_y{0.0f};
    float blur_radius{0.0f};
};

// Exact ABI layout verified from StyleManager::GetStyle (0x033a2c) & GetStyleValue (0x033990)
struct Style {
    std::string font_family{};                     // +0x00..+0x17 (24B)
    uint32_t font_style_packed{kDefaultFontStylePacked}; // +0x18 (4B: 0x00050190)
    uint32_t pad_1c{0};                            // +0x1C (4B)
    uint64_t platform_typeface_ref{0};             // +0x20 (8B)
    float text_size{kDefaultTextSizePx};           // +0x28 (4B: 13.333333f)
    float text_scale{kDefaultTextScale};           // +0x2C (4B: 1.0f)
    uint32_t fg_color{kDefaultForegroundColor};    // +0x30 (4B: 0xFF000000, Attr 6)
    uint32_t bg_color{0};                          // +0x34 (4B: 0, Attr 7)
    uint32_t decoration_color{0};                  // +0x38 (4B: 0, Attr 8)
    uint8_t decoration_type{0};                    // +0x3C (1B: 0, Attr 9)
    uint8_t decoration_style{2};                   // +0x3D (1B: 2, Attr 10)
    uint16_t pad_3e{0};                            // +0x3E (2B)
    float decoration_thickness_multiplier{1.0f};   // +0x40 (4B: 1.0f, Attr 11)
    float letter_spacing{0.0f};                    // +0x44 (4B)
    uint64_t font_feature_flags{0x0002000A00000000ULL}; // +0x48 (8B, Attr 12)
    uint8_t bold{0};                               // +0x50 (1B, Attr 13)
    uint8_t italic{0};                             // +0x51 (1B, Attr 14)
    CharacterVerticalAlignment vertical_alignment{CharacterVerticalAlignment::kBaseLine}; // +0x52 (1B: 4)
    uint8_t pad_53{0};                             // +0x53 (1B)
    float baseline_offset{0.0f};                   // +0x54 (4B)
    float word_spacing{0.0f};                      // +0x58 (4B)
    uint32_t pad_5c{0};                            // +0x5C (4B)
    uint64_t foreground_painter{0};                // +0x60 (8B, Attr 16)
    uint64_t background_painter{0};                // +0x68 (8B, Attr 17)
    uint8_t word_break{0};                         // +0x70 (1B, Attr 18)
    uint8_t pad_71[3]{0, 0, 0};                    // +0x71..+0x73 (3B)
    uint32_t sub_sup_type{0};                      // +0x74 (4B, Attr 19)
    std::vector<TextShadow> text_shadows{};        // +0x78..+0x8F (24B, Attr 15)
    uint64_t locale_or_extra{0};                   // +0x90 (8B)
    mutable uint64_t cached_shape_style_ptr{0};    // +0x98 (8B)

    static const Style& DefaultStyle();
    void ClearShapeStyle() const noexcept { cached_shape_style_ptr = 0; }
};

struct ParagraphStyle {
    float start_indent_px{0.0f};
    int32_t start_indent_chars{0};
    float end_indent_px{0.0f};
    int32_t end_indent_chars{0};
    float first_line_indent_px{0.0f};
    int32_t first_line_indent_chars{0};
    float hanging_indent_px{0.0f};
    int32_t hanging_indent_chars{0};
    Spacing spacing{};
    ParagraphHorizontalAlignment horizontal_alignment{ParagraphHorizontalAlignment::kLeft};
    WriteDirection write_direction{WriteDirection::kAuto};
    LineBreakStrategy line_break_strategy{LineBreakStrategy::kSimple};
    OverflowWrap overflow_wrap{OverflowWrap::kNormal};
    uint32_t max_lines{0xFFFFFFFFu};
    bool allow_break_around_punctuation{false};
    std::u16string ellipsis_u16{};
    std::string ellipsis_u8{};
};

// ============================================================================
// 5. ControlRun & SpaceList Entries in .data (0x048008 .. 0x04807F)
//    Bảng ký tự điều khiển và khoảng trắng trong .data (0x048008 .. 0x04807F)
// ============================================================================
struct ControlRunEntry {
    uint64_t control_type_id;
    const char* utf8_sequence;
};

// ============================================================================
// 6. Dynamic HarfBuzz API Table (39 Function Pointers = 0x138 Bytes)
//    Bảng hàm API HarfBuzz nạp động tại HarfbuzzLib::LoadHarfbuzzLib (0x01d798)
// ============================================================================
struct HarfbuzzFuncTable {
    void* hb_font_create;                             // +0x000
    void* hb_font_funcs_create;                       // +0x008
    void* hb_font_funcs_set_variation_glyph_func;     // +0x010
    void* hb_font_funcs_set_nominal_glyph_func;       // +0x018
    void* hb_font_funcs_set_nominal_glyphs_func;      // +0x020
    void* hb_font_funcs_set_glyph_h_advance_func;     // +0x028
    void* hb_font_funcs_set_glyph_h_advances_func;    // +0x030
    void* hb_font_funcs_set_glyph_extents_func;       // +0x038
    void* hb_font_funcs_make_immutable;               // +0x040
    void* hb_font_create_sub_font;                    // +0x048
    void* hb_font_set_funcs;                          // +0x050
    void* hb_font_set_scale;                          // +0x058
    void* hb_ot_font_set_funcs;                       // +0x060
    void* hb_face_create;                             // +0x068
    void* hb_face_set_index;                          // +0x070
    void* hb_face_set_upem;                           // +0x078
    void* hb_blob_create;                             // +0x080
    void* hb_blob_make_immutable;                     // +0x088
    void* hb_script_from_iso15924_tag;                // +0x090
    void* hb_language_from_string;                    // +0x098
    void* hb_buffer_set_content_type;                 // +0x0A0
    void* hb_buffer_set_cluster_level;                // +0x0A8
    void* hb_buffer_add_utf32;                        // +0x0B0
    void* hb_buffer_add;                              // +0x0B8
    void* hb_buffer_set_direction;                    // +0x0C0
    void* hb_buffer_set_script;                       // +0x0C8
    void* hb_buffer_set_language;                     // +0x0D0
    void* hb_buffer_guess_segment_properties;         // +0x0D8
    void* hb_buffer_get_length;                       // +0x0E0
    void* hb_buffer_reverse;                          // +0x0E8
    void* hb_buffer_get_glyph_infos;                  // +0x0F0
    void* hb_buffer_get_glyph_positions;              // +0x0F8
    void* hb_buffer_create;                           // +0x100
    void* hb_shape;                                   // +0x108
    void* hb_font_destroy;                            // +0x110
    void* hb_face_destroy;                            // +0x118
    void* hb_blob_destroy;                            // +0x120
    void* hb_buffer_destroy;                          // +0x128
    void* hb_buffer_clear_contents;                   // +0x130
};
static_assert(sizeof(HarfbuzzFuncTable) == 0x138, "HarfbuzzFuncTable must be exactly 0x138 (312) bytes");

// ============================================================================
// 7. JNI Method Descriptor & Proxy Cache (.data 0x048080 & .bss 0x048180)
//    Bảng phương thức JNI và bộ nhớ đệm Proxy (.data 0x048080 & .bss 0x048180)
// ============================================================================
struct JniNativeMethodEntry {
    uint64_t data_vaddr;
    const char* class_name;
    const char* method_name;
    const char* signature;
    uint64_t target_func_vaddr;
};

struct TTTextJniCacheState {
    uint64_t java_shaper_class{0};                     // 0x048180
    uint64_t java_font_manager_class{0};               // 0x048188
    uint64_t java_vm{0};                               // 0x048190
    uint64_t shape_result_field_glyph_count{0};        // 0x048198
    uint64_t shape_result_field_glyphs{0};             // 0x0481A0
    uint64_t shape_result_field_advances{0};           // 0x0481A8
    uint64_t shape_result_field_position_x{0};         // 0x0481B0
    uint64_t shape_result_field_position_y{0};         // 0x0481B8
    uint64_t shape_result_field_typeface_instance{0};  // 0x0481C0
    uint64_t java_shaper_method_init{0};               // 0x0481C8
    uint64_t java_shaper_method_on_shape_text{0};      // 0x0481D0
    uint64_t java_shaper_method_on_shape_text_new{0};  // 0x0481D8
    uint64_t java_font_manager_method_init{0};         // 0x0481E0
    uint64_t java_font_manager_method_match_family{0}; // 0x0481E8
    uint64_t java_font_manager_method_match_index{0};  // 0x0481F0
    uint64_t java_typeface_method_get_font_metrics{0}; // 0x0481F8
    uint64_t java_typeface_method_get_text_bounds{0};  // 0x048200
};

} // namespace tttext
} // namespace ttoffice
