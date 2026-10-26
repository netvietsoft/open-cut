/**
 * @file animax_textra_types.h
 * @brief Exact ABI Structures, VTable Layouts, .rodata Constants, and CityHash64 Primitives for libanimax_textra.so
 *        Cấu trúc ABI chuẩn xác, bố cục VTable, hằng số .rodata và thuật toán CityHash64 cho libanimax_textra.so
 *
 * Binary Ground Truth / Bằng chứng nhị phân thực tế:
 * - File: libanimax_textra.so (83,952 bytes, 24 ELF64 AArch64 sections)
 * - .dynsym:       0x000330 .. 0x000d08 (2,520 bytes, 105 entries: 100 imports [001..100], 1 export [101] JNI_OnLoad @ 0x00b7cc)
 * - .rela.dyn:     0x002108 .. 0x002c00 (2,808 bytes, 117 entries: 100 R_AARCH64_RELATIVE, 1 GLOB_DAT, 16 ABS64)
 * - .rela.plt:     0x002c00 .. 0x003518 (2,328 bytes, 97 entries)
 * - .rodata:       0x003518 .. 0x00358e (118 bytes)
 * - .text:         0x008000 .. 0x00ba84 (14,980 bytes)
 * - .plt:          0x00ba90 .. 0x00c0c0 (1,584 bytes)
 * - .data.rel.ro:  0x010000 .. 0x010480 (1,152 bytes — VTables for FontAssetImplTextra, TypefaceTextra, FontManagerTextra, TextLayerImplTextra, CanvasHelperTextra, TextHelperTextra)
 * - .fini_array:   0x010480 .. 0x010490 (16 bytes: 0x008010, 0x008000)
 * - .bss:          0x014000 .. 0x014038 (56 bytes: static counters, guard variables, TextHelperTextra singleton)
 */

#ifndef NEXTAI_OPENCUT_ANIMAX_TEXTRA_TYPES_H_
#define NEXTAI_OPENCUT_ANIMAX_TEXTRA_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace lynx {
namespace animax {

// ============================================================================
// 1. .rodata Float & String Constants (0x003518 .. 0x00358e)
//    Hằng số dấu phẩy động & chuỗi trong phân vùng .rodata (0x003518 .. 0x00358e)
// ============================================================================

namespace rodata {

// 0x003518: 0xc8f42400 -> -500000.0f (Right-align / Center-align layout region half-offset @ 0x00aa54)
// 0x003518: 0xc8f42400 -> -500000.0f (Độ lệch nửa vùng bố cục căn phải/căn giữa tại 0x00aa54)
constexpr uint32_t kLayoutOffsetNegHalfMillionBits = 0xc8f42400U;
constexpr float kLayoutOffsetNegHalfMillion = -500000.0f;

// 0x00351c: 0xc9742400 -> -1000000.0f (Right-align layout region full-offset @ 0x00aa60)
// 0x00351c: 0xc9742400 -> -1000000.0f (Độ lệch toàn vùng bố cục căn phải tại 0x00aa60)
constexpr uint32_t kLayoutOffsetNegOneMillionBits = 0xc9742400U;
constexpr float kLayoutOffsetNegOneMillion = -1000000.0f;

// 0x003520: 0x49742400 -> +1000000.0f (Unconstrained LayoutRegion width/height @ 0x00a9a8)
// 0x003520: 0x49742400 -> +1000000.0f (Chiều rộng/cao vùng bố cục không giới hạn tại 0x00a9a8)
constexpr uint32_t kLayoutUnconstrainedMaxDimensionBits = 0x49742400U;
constexpr float kLayoutUnconstrainedMaxDimension = 1000000.0f;

// 0x00a598: mov w8, #0x42c80000 -> 100.0f (Divisor for tracking calculation: (text_size * tracking) / 100.0f)
// 0x00a598: mov w8, #0x42c80000 -> 100.0f (Hệ số chia khi tính khoảng cách chữ: (text_size * tracking) / 100.0f)
constexpr float kTrackingDivisor100 = 100.0f;

// 0x00af84: fmov s0, #-0.25000000 (0xbe800000) -> Faux italic skew factor in CanvasHelperTextra::DrawGlyphs
// 0x00af84: fmov s0, #-0.25000000 (0xbe800000) -> Hệ số nghiêng chữ giả lập trong CanvasHelperTextra::DrawGlyphs
constexpr float kFauxItalicSkewX = -0.25f;

// 0x00a534..0x00a53c: Bit-packed paragraph horizontal alignment LUT (0x0000030303030102ULL)
// 0x00a534..0x00a53c: Bảng tra cứu căn lề ngang đóng gói bit (0x0000030303030102ULL)
constexpr uint64_t kParagraphAlignBitLut = 0x0000030303030102ULL;

// 0x00b348..0x00b354: Max capacity for std::vector<skity::TextRun> where sizeof(skity::TextRun) == 0x68 (104 bytes)
// 2^64 / 104 = 0x0276276276276277ULL
// 0x00b348..0x00b354: Sức chứa tối đa cho std::vector<skity::TextRun> với sizeof(skity::TextRun) == 104 byte
constexpr uint64_t kMaxTextRunVectorCapacity = 0x0276276276276277ULL;
constexpr size_t kSkityTextRunByteSize = 0x68; // 104 bytes

// .rodata string literals (0x003524 .. 0x00358e)
// Các hằng chuỗi trong .rodata (0x003524 .. 0x00358e)
constexpr const char* kStrUseTextraTextImpl = "use textra text impl";       // 0x003524
constexpr const char* kStrPingFang          = "pingfang";                   // 0x003539
constexpr const char* kStrSansSerif         = "sans-serif";                 // 0x003542
constexpr const char* kStrJniOnLoadLog      = "animax textra JNI_OnLoad";   // 0x00354d
constexpr const char* kStrFileTextraJni     = "textra_jni.cc";              // 0x003566
constexpr const char* kStrFileTextHelper    = "text_helper_textra.cc";      // 0x003574
constexpr const char* kStrFontKeyDelimiter  = "@_@";                        // 0x00358a

}  // namespace rodata

// ============================================================================
// 2. CityHash64 Constants & Implementation (0x008424 .. 0x008484 & 0x008dbc .. 0x009254)
//    Hằng số và thuật toán băm CityHash64 chuẩn libc++ NDK (0x008424 .. 0x008484)
// ============================================================================

namespace cityhash {

constexpr uint64_t k0   = 0xc3a5c85c97cb3127ULL;
constexpr uint64_t k1   = 0xb492b66fbe98f273ULL;
constexpr uint64_t k2   = 0x9ae16a3b2f90404fULL;
constexpr uint64_t k3   = 0xc949d7c7509e6557ULL;
constexpr uint64_t kMul = 0x9ddfea08eb382d69ULL;

/**
 * @brief Rotate right 64-bit integer (matches AArch64 `ror` instruction).
 *        Xoay phải số nguyên 64-bit (khớp lệnh `ror` trên AArch64).
 */
inline uint64_t RotateRight64(uint64_t val, unsigned int shift) noexcept {
    return (shift == 0U) ? val : ((val >> shift) | (val << (64U - shift)));
}

/**
 * @brief Unaligned 64-bit little-endian load.
 *        Đọc 64-bit little-endian không căn lề.
 */
inline uint64_t Load64LE(const char* p) noexcept {
    uint64_t result = 0;
    std::memcpy(&result, p, sizeof(uint64_t));
    return result;
}

/**
 * @brief Unaligned 32-bit little-endian load.
 *        Đọc 32-bit little-endian không căn lề.
 */
inline uint32_t Load32LE(const char* p) noexcept {
    uint32_t result = 0;
    std::memcpy(&result, p, sizeof(uint32_t));
    return result;
}

/**
 * @brief Hash128to64 reduction step using `kMul = 0x9ddfea08eb382d69ULL` (@ 0x0085a8 .. 0x0085cc).
 *        Bước rút gọn Hash128to64 dùng hằng số `kMul = 0x9ddfea08eb382d69ULL` (@ 0x0085a8 .. 0x0085cc).
 */
inline uint64_t HashLen16(uint64_t u, uint64_t v) noexcept {
    uint64_t a = (u ^ v) * kMul;
    a ^= (a >> 47);
    uint64_t b = (v ^ a) * kMul;
    b ^= (b >> 47);
    b *= kMul;
    return b;
}

/**
 * @brief Exact NDK `std::__ndk1::__murmur2_or_cityhash<size_t, 64>::operator()` (@ 0x008424 .. 0x0089d8).
 *        Hàm băm chuỗi `std::__ndk1::__murmur2_or_cityhash<size_t, 64>` khớp từng nhánh lệnh tại 0x008424 .. 0x0089d8.
 */
inline uint64_t CityHash64(const char* s, size_t len) noexcept {
    if (len <= 16) {
        if (len >= 9) {
            // 0x00858c .. 0x0085cc: len in [9..16]
            const uint64_t a = Load64LE(s);
            const uint64_t b = Load64LE(s + len - 8);
            const uint64_t c = RotateRight64(b + len, static_cast<unsigned int>(len)) + a;
            return HashLen16(c, b ^ k2);
        }
        if (len >= 4) {
            // 0x0085cc .. 0x008600: len in [4..8]
            const uint64_t a = Load32LE(s);
            const uint64_t b = Load32LE(s + len - 4);
            return HashLen16(len + (a << 3), b);
        }
        if (len > 0) {
            // 0x008604 .. 0x008644: len in [1..3]
            const uint8_t a = static_cast<uint8_t>(s[0]);
            const uint8_t b = static_cast<uint8_t>(s[len >> 1]);
            const uint8_t c = static_cast<uint8_t>(s[len - 1]);
            const uint32_t y = static_cast<uint32_t>(a) + (static_cast<uint32_t>(b) << 8);
            const uint32_t z = static_cast<uint32_t>(len) + (static_cast<uint32_t>(c) << 2);
            const uint64_t mix = (static_cast<uint64_t>(y) * k2) ^ (static_cast<uint64_t>(z) * k3);
            return (mix ^ (mix >> 47)) * k2;
        }
        // 0x008648: len == 0 -> returns k2 (0x9ae16a3b2f90404fULL)
        return k2;
    }

    if (len <= 32) {
        // 0x0084f4 .. 0x008588: len in [17..32]
        const uint64_t a = Load64LE(s) * k1;
        const uint64_t b = Load64LE(s + 8);
        const uint64_t c = Load64LE(s + len - 8) * k2;
        const uint64_t d = Load64LE(s + len - 16) * k0;
        const uint64_t u = RotateRight64(a - b, 43) + RotateRight64(c, 30) + d;
        const uint64_t v = a + RotateRight64(b ^ k3, 20) - c + len;
        return HashLen16(u, v);
    }

    if (len <= 64) {
        // 0x008658 .. 0x008770: len in [33..64]
        const uint64_t z = Load64LE(s + 24);
        const uint64_t a = Load64LE(s) + (len + Load64LE(s + len - 16)) * k0;
        const uint64_t b = RotateRight64(a + z, 52);
        const uint64_t c = RotateRight64(a, 37);
        const uint64_t a2 = a + Load64LE(s + 8);
        const uint64_t c2 = c + RotateRight64(a2, 7);
        const uint64_t a3 = a2 + Load64LE(s + 16);
        const uint64_t vf = a3 + z;
        const uint64_t vs = b + RotateRight64(a3, 31) + c2;

        const uint64_t a4 = Load64LE(s + 16) + Load64LE(s + len - 32);
        const uint64_t z2 = Load64LE(s + len - 8);
        const uint64_t b2 = RotateRight64(a4 + z2, 52);
        const uint64_t c3 = RotateRight64(a4, 37);
        const uint64_t a5 = a4 + Load64LE(s + len - 24);
        const uint64_t c4 = c3 + RotateRight64(a5, 7);
        const uint64_t a6 = a5 + Load64LE(s + len - 16);
        const uint64_t wf = a6 + z2;
        const uint64_t ws = b2 + RotateRight64(a6, 31) + c4;
        const uint64_t r = (vf + ws) * k2 + (wf + vs) * k0;
        return ((r ^ (r >> 47)) + vs) * k2;
    }

    // len > 64 (@ 0x008774 .. 0x0089d8)
    uint64_t x = Load64LE(s + len - 40);
    uint64_t y = Load64LE(s + len - 16) + Load64LE(s + len - 56);
    uint64_t z = HashLen16(Load64LE(s + len - 48) + len, Load64LE(s + len - 24));
    for (size_t offset = 0; offset + 64 <= len; offset += 64) {
        x = RotateRight64(x + y + Load64LE(s + offset + 8), 37) * k1;
        y = RotateRight64(y + Load64LE(s + offset + 48), 42) * k1;
        x ^= z;
        y += Load64LE(s + offset + 40);
        z = RotateRight64(z + Load64LE(s + offset), 33) * k1;
    }
    return HashLen16(HashLen16(x, y) + ((z ^ (z >> 47)) * k1) + z, x);
}

/**
 * @brief Exact bucket index calculation matching AArch64 NEON popcount check (@ 0x0090c8 .. 0x0090e4):
 *        `fmov d0, x21; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w8, s0; cmp w8, #1`
 *        Tính chỉ số bucket khớp lệnh NEON đếm bit kiểm tra lũy thừa của 2 tại 0x0090c8 .. 0x0090e4.
 */
inline size_t ComputeBucketIndex(uint64_t hash, size_t bucket_count) noexcept {
    if (bucket_count == 0) {
        return 0;
    }
    const bool is_power_of_two = (bucket_count & (bucket_count - 1)) == 0;
    return is_power_of_two ? (hash & (bucket_count - 1)) : (hash % bucket_count);
}

}  // namespace cityhash

}  // namespace animax
}  // namespace lynx

// ============================================================================
// 3. Skity 2D Graphics Engine ABI Types (Imported from libanimax.so / libskity.so)
//    Các kiểu dữ liệu ABI của Engine đồ họa 2D Skity (Nhập từ libanimax.so / libskity.so)
// ============================================================================

namespace skity {

using GlyphID = uint16_t;
using Unichar = uint32_t;

struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;
};

struct Vec4 {
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 0.0f;
};

/**
 * @brief 16-byte bounding rectangle (`left, top, right, bottom`) used in `TypefaceTextra::GetWidthBound` (@ 0x0097f8).
 *        Hình chữ nhật bao 16-byte (`left, top, right, bottom`) dùng trong `TypefaceTextra::GetWidthBound` (@ 0x0097f8).
 */
struct Rect {
    float left   = 0.0f; // +0x00
    float top    = 0.0f; // +0x04
    float right  = 0.0f; // +0x08
    float bottom = 0.0f; // +0x0c
};

enum class BlurStyle : int32_t {
    kNormal = 1, // Used @ 0x00b0ac: mov w0, #1; bl skity::MaskFilter::MakeBlur
    kSolid  = 2,
    kOuter  = 3,
    kInner  = 4,
};

/**
 * @brief `skity::FontStyle` packed 32-bit word (`weight` in low 16 bits, `width` in bits 16..23, `slant` in bits 24..31).
 *        Default at 0x00a5c4: `mov w8, #0x190; movk w8, #5, lsl #16` -> weight=400, width=5, slant=0.
 *        Cấu trúc `skity::FontStyle` đóng gói 32-bit (weight 16 bit thấp, width bit 16..23, slant bit 24..31).
 */
struct FontStyle {
    uint16_t weight = 400; // 0x0190
    uint8_t  width  = 5;   // 0x05 (Normal)
    uint8_t  slant  = 0;   // 0 = Upright, 1 = Italic, 2 = Oblique

    constexpr FontStyle() noexcept = default;
    constexpr FontStyle(uint16_t w, uint8_t wd, uint8_t sl) noexcept
        : weight(w), width(wd), slant(sl) {}

    uint32_t ToPackedU32() const noexcept {
        return static_cast<uint32_t>(weight) |
               (static_cast<uint32_t>(width) << 16) |
               (static_cast<uint32_t>(slant) << 24);
    }

    static FontStyle FromPackedU32(uint32_t packed) noexcept {
        return FontStyle(
            static_cast<uint16_t>(packed & 0xFFFFU),
            static_cast<uint8_t>((packed >> 16) & 0xFFU),
            static_cast<uint8_t>((packed >> 24) & 0xFFU));
    }
};

/**
 * @brief `skity::FontMetrics` (60 bytes = 0x3c bytes copied into TypefaceTextra::GetFontMetrics @ 0x009bb4 .. 0x009bcc).
 *        Thông số `skity::FontMetrics` (60 byte = 0x3c byte được sao chép trong TypefaceTextra::GetFontMetrics @ 0x009bb4 .. 0x009bcc).
 */
struct FontMetrics {
    float top                 = -12.0f; // +0x00
    float ascent              = -10.0f; // +0x04
    float descent             = 3.0f;   // +0x08
    float bottom              = 4.0f;   // +0x0c
    float leading             = 0.0f;   // +0x10
    float avg_char_width      = 8.0f;   // +0x14
    float max_char_width      = 16.0f;  // +0x18
    float x_min               = -2.0f;  // +0x1c
    float x_max               = 16.0f;  // +0x20
    float x_height            = 7.0f;   // +0x24
    float cap_height          = 10.0f;  // +0x28
    float underline_thickness = 1.0f;   // +0x2c
    float underline_position  = 2.0f;   // +0x30
    float strikeout_thickness = 1.0f;   // +0x34
    float strikeout_position  = -4.0f;  // +0x38
};
static_assert(sizeof(FontMetrics) == 0x3c, "skity::FontMetrics must be exactly 0x3c (60) bytes");

/**
 * @brief `skity::GlyphData` (`sizeof == 0x50 = 80 bytes`, allocated in `TypefaceTextra` methods @ 0x0096dc / 0x00976c / 0x00981c / 0x0098c0).
 *        Holds advance (`+0x28`) and bounding metrics (`+0x2c`: horiBearingX, `+0x30`: horiBearingY, `+0x34`: width, `+0x38`: height).
 *        Cấu trúc `skity::GlyphData` (`sizeof == 0x50 = 80 byte`) lưu độ tiến ngang và khung bao glyph.
 */
struct GlyphData {
    GlyphID  id             = 0;     // +0x00
    uint16_t reserved0      = 0;     // +0x02
    uint32_t flags          = 0;     // +0x04
    uint64_t path_data[4]   = {0};   // +0x08 .. +0x27
    float    advance_x      = 0.0f;  // +0x28 (Read by skity::GlyphData::GetHoriAdvance)
    float    bearing_x      = 0.0f;  // +0x2c (left = bearing_x)
    float    bearing_y      = 0.0f;  // +0x30 (top = -bearing_y)
    float    width          = 0.0f;  // +0x34 (right = bearing_x + width)
    float    height         = 0.0f;  // +0x38 (bottom = -bearing_y + height)
    float    font_size      = 12.0f; // +0x3c
    uint64_t reserved_tail[2] = {0}; // +0x40 .. +0x4f

    float GetHoriAdvance() const noexcept { return advance_x; }
    float GetWidth() const noexcept { return width; }
    float GetHeight() const noexcept { return height; }
    float GetHoriBearingX() const noexcept { return bearing_x; }
    float GetHoriBearingY() const noexcept { return bearing_y; }
};
static_assert(sizeof(GlyphData) == 0x50, "skity::GlyphData must be exactly 0x50 (80) bytes");

class Data {
public:
    Data() = default;
    Data(const uint8_t* bytes, size_t size) : bytes_(bytes, bytes + size) {}
    const uint8_t* RawData() const noexcept { return bytes_.data(); }
    size_t Size() const noexcept { return bytes_.size(); }

private:
    std::vector<uint8_t> bytes_;
};

class Typeface {
public:
    explicit Typeface(std::string family_name = "sans-serif",
                      FontStyle style = FontStyle(),
                      uint16_t units_per_em = 1000)
        : family_name_(std::move(family_name)),
          style_(style),
          units_per_em_(units_per_em),
          data_(std::make_shared<Data>()) {}

    static std::shared_ptr<Typeface> MakeFromFile(const char* path);

    FontStyle GetFontStyle() const noexcept { return style_; }
    std::shared_ptr<Data> GetData() const noexcept { return data_; }
    uint16_t GetUnitsPerEm() const noexcept { return units_per_em_; }
    GlyphID UnicharToGlyph(Unichar codepoint) const noexcept;
    void UnicharsToGlyphs(const Unichar* chars, uint32_t count, GlyphID* glyphs) const noexcept;
    bool ContainGlyph(Unichar codepoint) const noexcept { return codepoint != 0; }
    const std::string& GetFamilyName() const noexcept { return family_name_; }

private:
    std::string family_name_;
    FontStyle style_;
    uint16_t units_per_em_ = 1000;
    std::shared_ptr<Data> data_;
};

class FontManager {
public:
    FontManager();
    static std::shared_ptr<FontManager> RefDefault();

    int32_t CountFamilies() const noexcept;
    std::string GetFamilyName(int32_t index) const;
    std::shared_ptr<Typeface> MatchFamilyStyle(const char* family_name, const FontStyle& style);
    std::shared_ptr<Typeface> MatchFamilyStyleCharacter(
        const char* family_name, const FontStyle& style,
        const char** bcp47, int32_t bcp47_count, Unichar character);

private:
    std::vector<std::string> families_;
};

class MaskFilter {
public:
    MaskFilter(BlurStyle style, float radius) : style_(style), radius_(radius) {}
    static std::shared_ptr<MaskFilter> MakeBlur(BlurStyle style, float radius) {
        return std::make_shared<MaskFilter>(style, radius);
    }
    BlurStyle GetBlurStyle() const noexcept { return style_; }
    float GetBlurRadius() const noexcept { return radius_; }

private:
    BlurStyle style_;
    float radius_;
};

/**
 * @brief `skity::Paint` (`sizeof == 0xa8 = 168 bytes`, embedded inside `TypefaceTextra` @ `+0x20` and `CanvasHelperTextra` @ `+0x10`).
 *        Disassembly proof: `add x0, x19, #0x20; bl skity::Paint::Paint()` @ `0x009588` and `TypefaceTextra` size `0x98` (`0x20` to `0xc8` in control block).
 *        Cấu trúc `skity::Paint` (nhúng trực tiếp trong `TypefaceTextra` và `CanvasHelperTextra`).
 */
class Paint {
public:
    enum Style : uint8_t {
        kFill_Style          = 0,
        kStroke_Style        = 1,
        kStrokeAndFill_Style = 2,
    };

    Paint() noexcept = default;
    ~Paint() noexcept = default;

    void Reset() noexcept {
        style_ = kFill_Style;
        stroke_width_ = 1.0f;
        text_size_ = 14.0f;
        alpha_f_ = 1.0f;
        fill_color_ = {0.0f, 0.0f, 0.0f, 1.0f};
        stroke_color_ = {0.0f, 0.0f, 0.0f, 1.0f};
        mask_filter_.reset();
    }

    void SetStyle(Style style) noexcept { style_ = style; }
    Style GetStyle() const noexcept { return style_; }

    void SetStrokeWidth(float width) noexcept { stroke_width_ = width; }
    float GetStrokeWidth() const noexcept { return stroke_width_; }

    void SetTextSize(float size) noexcept { text_size_ = size; }
    float GetTextSize() const noexcept { return text_size_; }

    void SetFillColor(float r, float g, float b, float a) noexcept { fill_color_ = {r, g, b, a}; }
    void SetStrokeColor(float r, float g, float b, float a) noexcept { stroke_color_ = {r, g, b, a}; }
    void SetColor(uint32_t argb) noexcept {
        const float a = static_cast<float>((argb >> 24) & 0xFFU) / 255.0f;
        const float r = static_cast<float>((argb >> 16) & 0xFFU) / 255.0f;
        const float g = static_cast<float>((argb >> 8) & 0xFFU) / 255.0f;
        const float b = static_cast<float>(argb & 0xFFU) / 255.0f;
        fill_color_ = {r, g, b, a};
        stroke_color_ = {r, g, b, a};
    }

    void SetAlphaF(float alpha) noexcept { alpha_f_ = alpha; }
    float GetAlphaF() const noexcept { return alpha_f_; }

    void SetAntiAlias(bool aa) noexcept { anti_alias_ = aa; }
    bool IsAntiAlias() const noexcept { return anti_alias_; }

    void SetMaskFilter(std::shared_ptr<MaskFilter> filter) noexcept { mask_filter_ = std::move(filter); }
    std::shared_ptr<MaskFilter> GetMaskFilter() const noexcept { return mask_filter_; }

    static uint32_t ColorMakeARGB(uint8_t a, uint8_t r, uint8_t g, uint8_t b) noexcept {
        return (static_cast<uint32_t>(a) << 24) |
               (static_cast<uint32_t>(r) << 16) |
               (static_cast<uint32_t>(g) << 8)  |
               static_cast<uint32_t>(b);
    }

    static Vec4 Color4fFromColor(uint32_t argb) noexcept {
        return Vec4{
            static_cast<float>((argb >> 16) & 0xFFU) / 255.0f,
            static_cast<float>((argb >> 8) & 0xFFU) / 255.0f,
            static_cast<float>(argb & 0xFFU) / 255.0f,
            static_cast<float>((argb >> 24) & 0xFFU) / 255.0f,
        };
    }

private:
    Style style_        = kFill_Style;
    bool anti_alias_    = true;
    float stroke_width_ = 1.0f;
    float text_size_    = 14.0f;
    float alpha_f_      = 1.0f;
    Vec4 fill_color_    = {0.0f, 0.0f, 0.0f, 1.0f};
    Vec4 stroke_color_  = {0.0f, 0.0f, 0.0f, 1.0f};
    std::shared_ptr<MaskFilter> mask_filter_;
};

/**
 * @brief `skity::Font` (`sizeof == 0x20 = 32 bytes`, constructed @ `0x0096fc` / `0x00af58`).
 *        Font wrapper around `std::shared_ptr<Typeface>`, `size` (`+0x10`), `scale_x` (`+0x14`), `skew_x` (`+0x18`).
 *        Disassembly proof:
 *        `0x00af68: str s11, [sp, #0x48]` (size at Font+0x10)
 *        `0x00af84..0x00af88: fmov s0, #-0.25000000; str s0, [sp, #0x50]` (skew_x at Font+0x18)
 *        Cấu trúc `skity::Font` (32 byte) bao quanh `Typeface`, kích thước chữ (`+0x10`), hệ số co giãn (`+0x14`) và độ nghiêng (`+0x18`).
 */
class Font {
public:
    Font() noexcept = default;
    explicit Font(std::shared_ptr<Typeface> typeface) noexcept
        : typeface_(std::move(typeface)) {}
    ~Font() noexcept = default;

    void SetSize(float size) noexcept { size_ = size; }
    float GetSize() const noexcept { return size_; }

    void SetSkewX(float skew_x) noexcept { skew_x_ = skew_x; }
    float GetSkewX() const noexcept { return skew_x_; }

    void LoadGlyphMetrics(const GlyphID* glyphs, uint32_t count, GlyphData* glyph_data, const Paint& paint) const noexcept;
    void GetMetrics(FontMetrics* metrics) const noexcept;

    const std::shared_ptr<Typeface>& GetTypeface() const noexcept { return typeface_; }

private:
    std::shared_ptr<Typeface> typeface_; // +0x00 (16 bytes)
    float size_    = 12.0f;              // +0x10
    float scale_x_ = 1.0f;               // +0x14
    float skew_x_  = 0.0f;               // +0x18
    uint32_t flags_ = 0;                 // +0x1c
};
static_assert(sizeof(Font) == 0x20, "skity::Font must be exactly 0x20 (32) bytes");

/**
 * @brief `skity::TextRun` (`sizeof == 0x68 = 104 bytes`, constructed @ `0x00afd0` and pushed via `__emplace_back_slow_path` @ `0x00b318`).
 *        Cấu trúc `skity::TextRun` (104 byte) lưu chuỗi glyph và vị trí vẽ trong `CanvasHelperTextra::DrawGlyphs`.
 */
class TextRun {
public:
    TextRun(const Font& font, std::vector<GlyphData> glyphs, std::vector<Vec2> positions)
        : font_(font), glyphs_(std::move(glyphs)), positions_(std::move(positions)) {
        std::memset(reserved_padding_, 0, sizeof(reserved_padding_));
    }
    TextRun(const TextRun&) = default;
    TextRun(TextRun&&) noexcept = default;
    TextRun& operator=(const TextRun&) = default;
    TextRun& operator=(TextRun&&) noexcept = default;
    ~TextRun() = default;

    const Font& GetFont() const noexcept { return font_; }
    const std::vector<GlyphData>& GetGlyphInfo() const noexcept { return glyphs_; }
    const std::vector<Vec2>& GetPositions() const noexcept { return positions_; }

private:
    Font font_;                         // +0x00 (32 bytes)
    std::vector<GlyphData> glyphs_;     // +0x20 (24 bytes)
    std::vector<Vec2> positions_;       // +0x38 (24 bytes)
    uint8_t reserved_padding_[24] = {}; // +0x50 .. +0x67 (24 bytes -> total 0x68 = 104 bytes)
};
static_assert(sizeof(TextRun) == 0x68, "skity::TextRun must be exactly 0x68 (104) bytes");

class TextBlob {
public:
    explicit TextBlob(std::vector<TextRun> runs) : runs_(std::move(runs)) {}
    const std::vector<TextRun>& GetRuns() const noexcept { return runs_; }

private:
    std::vector<TextRun> runs_;
};

class Canvas {
public:
    virtual ~Canvas() = default;

    virtual void Save() { ++save_count_; }
    virtual void Restore() { if (save_count_ > 0) --save_count_; }
    virtual void Translate(float dx, float dy) { translate_x_ += dx; translate_y_ += dy; }
    virtual void Scale(float sx, float sy) { scale_x_ *= sx; scale_y_ *= sy; }
    virtual void Rotate(float degrees) { rotation_deg_ += degrees; }
    virtual void Skew(float sx, float sy) { skew_x_ += sx; skew_y_ += sy; }
    virtual void ClipRect(const Rect& rect) { clip_rect_ = rect; }
    virtual void DrawColor(uint32_t color) { last_color_ = color; }
    virtual void DrawLine(float x0, float y0, float x1, float y1, const Paint& paint) {
        last_line_ = {x0, y0, x1, y1};
        last_paint_ = paint;
    }
    virtual void DrawRect(const Rect& rect, const Paint& paint) {
        last_rect_ = rect;
        last_paint_ = paint;
    }
    virtual void DrawTextBlob(const TextBlob* blob, float x, float y, const Paint& paint) {
        if (blob != nullptr) {
            drawn_blobs_count_ += blob->GetRuns().size();
        }
        last_blob_origin_ = {x, y};
        last_paint_ = paint;
    }

    int32_t GetSaveCount() const noexcept { return save_count_; }
    Vec2 GetTranslation() const noexcept { return {translate_x_, translate_y_}; }
    size_t GetDrawnBlobsCount() const noexcept { return drawn_blobs_count_; }
    const Paint& GetLastPaint() const noexcept { return last_paint_; }

private:
    int32_t save_count_      = 0;
    float translate_x_       = 0.0f;
    float translate_y_       = 0.0f;
    float scale_x_           = 1.0f;
    float scale_y_           = 1.0f;
    float rotation_deg_      = 0.0f;
    float skew_x_            = 0.0f;
    float skew_y_            = 0.0f;
    Rect clip_rect_          = {};
    Rect last_line_          = {};
    Rect last_rect_          = {};
    uint32_t last_color_     = 0;
    Vec2 last_blob_origin_   = {};
    size_t drawn_blobs_count_ = 0;
    Paint last_paint_        = {};
};

}  // namespace skity

// ============================================================================
// 4. TTText (`ttoffice::tttext::*`) Types & Virtual Interfaces
//    Các kiểu dữ liệu và giao diện ảo của TTText (`ttoffice::tttext::*`)
// ============================================================================

namespace ttoffice {
namespace tttext {

enum class ParagraphHorizontalAlignment : uint32_t {
    kLeft    = 0,
    kRight   = 1,
    kCenter  = 2,
    kJustify = 3,
};

enum class LayoutMode : uint32_t {
    kDefinite   = 0,
    kAtMost     = 1, // Used @ 0x00a988 when text box size > (0, 0)
    kIndefinite = 2, // Used @ 0x00a9b0 when unconstrained (1000000.0f)
};

enum class WriteDirection : uint32_t {
    kAuto = 0,
    kLTR  = 1,
    kRTL  = 2,
};

enum class CharacterVerticalAlignment : uint32_t {
    kBaseLine = 0,
    kTop      = 1,
    kMiddle   = 2,
    kBottom   = 3,
};

enum class LineType : uint32_t {
    kNone   = 0,
    kSolid  = 1,
    kDouble = 2,
    kDotted = 3,
    kDashed = 4,
    kWavy   = 5,
};

enum class DecorationType : uint32_t {
    kNone        = 0,
    kUnderLine   = 1,
    kOverLine    = 2,
    kLineThrough = 4,
};

enum class RulerType : uint32_t {
    kNormal     = 0,
    kExact      = 1, // Used @ 0x00a640: mov w1, #1; bl Style::SetLineHeightOverride
    kAtLeast    = 2,
};

/**
 * @brief `ttoffice::tttext::FontStyle` packed 32-bit word (`weight` in bits 0..15, `width` in bits 16..23, `slant` in bits 24..31).
 *        Cấu trúc `ttoffice::tttext::FontStyle` đóng gói 32-bit.
 */
struct FontStyle {
    uint16_t weight = 400; // 0x0190
    uint8_t  width  = 5;
    uint8_t  slant  = 0;   // 0 = Upright, 1 = Italic

    constexpr FontStyle() noexcept = default;
    constexpr FontStyle(uint16_t w, uint8_t wd, uint8_t sl) noexcept
        : weight(w), width(wd), slant(sl) {}
};

struct FontDescriptor {
    std::vector<std::string> font_family_list_; // +0x00 (24 bytes)
    FontStyle font_style_;                      // +0x18 (4 bytes)
    uint32_t padding_ = 0;                      // +0x1c (4 bytes)
    uint64_t platform_font_ = 0;                // +0x20 (8 bytes -> total 0x28 = 40 bytes)
};
static_assert(sizeof(FontDescriptor) == 0x28, "ttoffice::tttext::FontDescriptor must be 0x28 (40) bytes");

/**
 * @brief `ttoffice::tttext::FontInfo` (`sizeof == 0x40 = 64 bytes`, returned by `TypefaceTextra::GetFontMetrics` @ 0x009a40).
 *        Matches exact assembly store instructions at `0x009bb4 .. 0x009bcc`:
 *        `stp q1, q0, [x8]; ldr d0, [sp, #4]; str q2, [x8, #0x20]; str d0, [x8, #0x30]; str s3, [x8, #0x38]; str s4, [x8, #0x3c]`
 *        Cấu trúc `ttoffice::tttext::FontInfo` (64 byte) khớp chính xác các lệnh ghi thanh ghi NEON tại `0x009bb4 .. 0x009bcc`.
 */
struct FontInfo {
    skity::FontMetrics metrics_; // +0x00 .. +0x3b (60 bytes)
    float font_size_ = 12.0f;    // +0x3c (4 bytes)

    FontInfo(const skity::FontMetrics& m, float size) noexcept
        : metrics_(m), font_size_(size) {}
};
static_assert(sizeof(FontInfo) == 0x40, "ttoffice::tttext::FontInfo must be 0x40 (64) bytes");

/**
 * @brief `ttoffice::tttext::TTColor` (`sizeof == 8 bytes`, read in `CanvasHelperTextra` via `[x, #4]` for ARGB when `[x] & 1 == 0`).
 *        Disassembly proof at `0x00ae08`:
 *        `ldrb w8, [x22]; tbz w8, #0, 0xae1c; mov x0, x22; bl TTColor::GetPlainColor; b 0xae20; ldr w0, [x22, #4]`
 *        Cấu trúc `ttoffice::tttext::TTColor` (8 byte).
 */
struct TTColor {
    uint32_t flags_ = 0;       // +0x00 (bit 0 == 1 -> dynamic/theme color, 0 -> plain ARGB in argb_)
    uint32_t argb_  = 0xFF000000U; // +0x04

    constexpr TTColor() noexcept = default;
    constexpr explicit TTColor(uint32_t argb) noexcept : flags_(0), argb_(argb) {}
    TTColor(const TTColor& other) noexcept = default;

    uint32_t GetPlainColor() const noexcept { return argb_; }
};
static_assert(sizeof(TTColor) == 0x08, "ttoffice::tttext::TTColor must be 8 bytes");

/**
 * @brief `ttoffice::tttext::IPaintHelper` — Paint configuration passed into `ICanvasHelper` drawing methods.
 *        Disassembly offsets verified in `CanvasHelperTextra::DrawGlyphs` (@ `0x00ad70 .. 0x00b0a8`):
 *        - `+0x08`: `uint8_t draw_style_` (`0`=Fill, `1`=Stroke, `2`=FillAndStroke)
 *        - `+0x0c`: `float stroke_width_` (`ldr s0, [x22, #0xc]`)
 *        - `+0x10`: `TTColor color_` (`add x22, x23, #0x10`)
 *        - `+0x18`: `float text_size_` (`ldr s0, [x23, #0x18]`)
 *        - `+0x22`: `bool bold_` (`ldrb w8, [x23, #0x22]`)
 *        - `+0x23`: `bool italic_` (`ldrb w8, [x23, #0x23]`)
 *        - `+0x28`: `float blur_radius_` (`ldr s0, [x23, #0x28]`)
 */
struct IPaintHelper {
    void*    vtable_       = nullptr; // +0x00
    uint8_t  draw_style_   = 0;       // +0x08 (0=Fill, 1=Stroke, 2=StrokeAndFill)
    uint8_t  padding0_[3]  = {0};     // +0x09 .. +0x0b
    float    stroke_width_ = 1.0f;    // +0x0c
    TTColor  color_        = {};      // +0x10 (8 bytes)
    float    text_size_    = 14.0f;   // +0x18
    uint8_t  padding1_[6]  = {0};     // +0x1c .. +0x21
    uint8_t  bold_         = 0;       // +0x22
    uint8_t  italic_       = 0;       // +0x23
    uint32_t padding2_     = 0;       // +0x24
    float    blur_radius_  = 0.0f;    // +0x28
};

/**
 * @brief `ttoffice::tttext::ITypefaceHelper` — Base class of `lynx::animax::TypefaceTextra` (`vtable @ 0x010110 .. 0x010170`).
 *        Exact base fields verified at `0x009564 .. 0x009598`:
 *        - `+0x00`: `vptr`
 *        - `+0x08`: `uint64_t unique_id_`
 *        - `+0x10`: `FontStyle font_style_` (4 bytes)
 *        Lớp cơ sở `ITypefaceHelper` của `TypefaceTextra` với bảng hàm ảo tại `0x010110 .. 0x010170`.
 */
class ITypefaceHelper {
public:
    explicit ITypefaceHelper(uint64_t unique_id) noexcept
        : unique_id_(unique_id), font_style_() {}
    virtual ~ITypefaceHelper() = default;

    // VTable slots matching 0x010120 .. 0x010170:
    virtual float GetHorizontalAdvance(uint16_t glyph_id, float font_size) const = 0;
    virtual void GetHorizontalAdvances(uint16_t* glyph_ids, uint32_t count, float* advances, float font_size) const = 0;
    virtual void GetWidthBound(float* rect_ltwh, uint16_t glyph_id, float font_size) const = 0;
    virtual void GetWidthBounds(float* rect_ltrb, uint16_t* glyph_ids, uint32_t count, float font_size) = 0;
    virtual const void* GetFontData() const = 0;
    virtual size_t GetFontDataSize() const = 0;
    virtual int GetFontIndex() const = 0;
    virtual uint16_t UnicharToGlyph(uint32_t codepoint, uint32_t variation_selector = 0) const = 0;
    virtual void UnicharsToGlyphs(const uint32_t* chars, uint32_t count, uint16_t* glyphs) const = 0;
    virtual const void* GetCreateArgs() const = 0;
    virtual void OnCreateFontInfo(FontInfo* out_info, float font_size) const = 0;

    uint64_t GetUniqueId() const noexcept { return unique_id_; }
    FontStyle GetFontStyle() const noexcept { return font_style_; }

protected:
    uint64_t  unique_id_  = 0;  // +0x08
    FontStyle font_style_ = {}; // +0x10
    uint32_t  reserved_   = 0;  // +0x14
};
static_assert(sizeof(ITypefaceHelper) == 0x18, "ttoffice::tttext::ITypefaceHelper must be 0x18 (24) bytes");

/**
 * @brief `ttoffice::tttext::IFontManager` — Base class of `lynx::animax::FontManagerTextra` (`vtable @ 0x010080 .. 0x0100c0`).
 *        Lớp cơ sở `IFontManager` của `FontManagerTextra` với bảng hàm ảo tại `0x010080 .. 0x0100c0`.
 */
class IFontManager {
public:
    virtual ~IFontManager() = default;

    // VTable slots matching 0x010090 .. 0x0100c0:
    virtual int32_t onCountFamilies() const = 0;
    virtual std::string onGetFamilyName(int32_t index) const = 0;
    virtual std::shared_ptr<ITypefaceHelper> onMatchFamilyStyle(const char* family_name, const FontStyle& style) = 0;
    virtual std::shared_ptr<ITypefaceHelper> onMatchFamilyStyleCharacter(
        const char* family_name, const FontStyle& style,
        const char** bcp47, int32_t bcp47_count, uint32_t character) = 0;
    virtual std::shared_ptr<ITypefaceHelper> onMakeFromFile(const char* path, int32_t ttc_index) = 0;
    virtual std::shared_ptr<ITypefaceHelper> onLegacyMakeTypeface(const char* family_name, FontStyle style) const = 0;
    virtual void* getPlatformFontFromTypeface(std::shared_ptr<ITypefaceHelper> typeface) = 0;
};

class FontmgrCollection {
public:
    explicit FontmgrCollection(std::shared_ptr<IFontManager> default_mgr)
        : default_manager_(std::move(default_mgr)) {}

    std::shared_ptr<IFontManager> GetDefaultFontManager() const noexcept { return default_manager_; }

private:
    std::shared_ptr<IFontManager> default_manager_;
};

/**
 * @brief `ttoffice::tttext::ICanvasHelper` — Base class of `lynx::animax::CanvasHelperTextra` (`vtable @ 0x0102e8 .. 0x0103d0`).
 *        Lớp cơ sở `ICanvasHelper` của `CanvasHelperTextra` với bảng hàm ảo tại `0x0102e8 .. 0x0103d0`.
 */
class ICanvasHelper {
public:
    ICanvasHelper() = default;
    virtual ~ICanvasHelper() = default;

    // VTable slots matching 0x0102f8 .. 0x0103d0:
    virtual std::unique_ptr<IPaintHelper> CreatePaint() = 0;
    virtual void* GetCanvas() = 0;
    virtual void Save() = 0;
    virtual void Restore() = 0;
    virtual void Translate(float dx, float dy) = 0;
    virtual void Scale(float sx, float sy) = 0;
    virtual void Rotate(float degrees) = 0;
    virtual void Skew(float sx, float sy) = 0;
    virtual void ClipRect(float left, float top, float right, float bottom, bool do_anti_alias) = 0;
    virtual void Clear() = 0;
    virtual void ClearRect(float left, float top, float right, float bottom) = 0;
    virtual void FillRect(float left, float top, float right, float bottom, uint32_t color) = 0;
    virtual void DrawColor(uint32_t color) = 0;
    virtual void DrawLine(float x0, float y0, float x1, float y1, IPaintHelper* paint) = 0;
    virtual void DrawRect(float left, float top, float right, float bottom, IPaintHelper* paint) = 0;
    virtual void DrawOval(float left, float top, float right, float bottom, IPaintHelper* paint) = 0;
    virtual void DrawCircle(float x, float y, float radius, IPaintHelper* paint) = 0;
    virtual void DrawArc(float left, float top, float right, float bottom,
                         float start_angle, float sweep_angle, bool use_center, IPaintHelper* paint) = 0;
    virtual void DrawPath(void* path, IPaintHelper* paint) = 0;
    virtual void DrawArcTo(float x1, float y1, float x2, float y2, float radius, IPaintHelper* paint) = 0;
    virtual void DrawText(const ITypefaceHelper* typeface, const char* text, uint32_t text_bytes,
                          float x, float y, IPaintHelper* paint) = 0;
    virtual void DrawGlyphs(const ITypefaceHelper* typeface, uint32_t glyph_count,
                            const uint16_t* glyphs, const char* text, uint32_t text_len,
                            float origin_x, float origin_y, const float* x_positions, const float* y_positions,
                            IPaintHelper* paint) = 0;
    virtual void DrawRunDelegate(const void* delegate, float left, float top, float right, float bottom,
                                 IPaintHelper* paint) = 0;
    virtual void DrawBackgroundDelegate(const void* delegate, IPaintHelper* paint) = 0;
    virtual void DrawImage(const char* src, float left, float top, float right, float bottom,
                           IPaintHelper* paint) = 0;
    virtual void DrawImageRect(const char* src, float src_left, float src_top, float src_right, float src_bottom,
                               float dst_left, float dst_top, float dst_right, float dst_bottom,
                               IPaintHelper* paint, bool fill_background) = 0;
};

}  // namespace tttext
}  // namespace ttoffice

#endif  // NEXTAI_OPENCUT_ANIMAX_TEXTRA_TYPES_H_
