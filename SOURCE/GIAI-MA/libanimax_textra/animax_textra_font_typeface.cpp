/**
 * @file animax_textra_font_typeface.cpp
 * @brief Complete Implementation of FontAssetImplTextra, TypefaceTextra, and FontManagerTextra (0x0089ec .. 0x009f8c)
 *        Triển khai đầy đủ FontAssetImplTextra, TypefaceTextra và FontManagerTextra (0x0089ec .. 0x009f8c)
 *
 * Binary Ground Truth / Bằng chứng nhị phân:
 * - 0x0089ec .. 0x008a3f: FontAssetImplTextra::~FontAssetImplTextra (D1 & D0)
 * - 0x008a40 .. 0x008c08: FontAssetImplTextra::GetFontmgrCollection()
 * - 0x008c0c .. 0x008db8: FontAssetImplTextra::GetFontFamilyName()
 * - 0x008dbc .. 0x009254: std::__hash_table<std::__hash_value_type<std::string, shared_ptr<Typeface>>>::find & __emplace_unique_key_args
 * - 0x0092a0 .. 0x00954c: FontManagerTextra custom asset vtable methods (onCountFamilies, onGetFamilyName, onMatchFamilyStyle, onLegacyMakeTypeface)
 * - 0x009550 .. 0x009c34: TypefaceTextra methods (Ctor, Dtor, GetHorizontalAdvance, GetHorizontalAdvances, GetWidthBound, GetWidthBounds, UnicharToGlyph, UnicharsToGlyphs, GetUnitsPerEm, GetFontMetrics)
 * - 0x009c38 .. 0x009f8c: FontManagerTextra default system font vtable methods (onMatchFamilyStyleCharacter, onMakeFromFile, onCountFamilies, onMatchFamilyStyle)
 */

#include "animax_textra_font_typeface.h"

#include <algorithm>
#include <cmath>
#include <cstring>

// ============================================================================
// 1. Skity Font & Typeface Support Implementations
//    Triển khai hỗ trợ cho Skity Font và Typeface
// ============================================================================

namespace skity {

std::shared_ptr<Typeface> Typeface::MakeFromFile(const char* path) {
    if (path == nullptr || path[0] == '\0') {
        return nullptr;
    }
    return std::make_shared<Typeface>(std::string(path), FontStyle(), 1000);
}

GlyphID Typeface::UnicharToGlyph(Unichar codepoint) const noexcept {
    if (codepoint == 0) {
        return 0;
    }
    return static_cast<GlyphID>(codepoint & 0xFFFFU);
}

void Typeface::UnicharsToGlyphs(const Unichar* chars, uint32_t count, GlyphID* glyphs) const noexcept {
    if (chars == nullptr || glyphs == nullptr) {
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        glyphs[i] = UnicharToGlyph(chars[i]);
    }
}

FontManager::FontManager() {
    families_.emplace_back(lynx::animax::rodata::kStrPingFang);
    families_.emplace_back(lynx::animax::rodata::kStrSansSerif);
}

std::shared_ptr<FontManager> FontManager::RefDefault() {
    static std::shared_ptr<FontManager> s_default_mgr = std::make_shared<FontManager>();
    return s_default_mgr;
}

int32_t FontManager::CountFamilies() const noexcept {
    return static_cast<int32_t>(families_.size());
}

std::string FontManager::GetFamilyName(int32_t index) const {
    if (index < 0 || static_cast<size_t>(index) >= families_.size()) {
        return "";
    }
    return families_[static_cast<size_t>(index)];
}

std::shared_ptr<Typeface> FontManager::MatchFamilyStyle(const char* family_name, const FontStyle& style) {
    const std::string resolved_family =
        (family_name != nullptr && family_name[0] != '\0')
            ? std::string(family_name)
            : std::string(lynx::animax::rodata::kStrSansSerif);
    return std::make_shared<Typeface>(resolved_family, style, 1000);
}

std::shared_ptr<Typeface> FontManager::MatchFamilyStyleCharacter(
    const char* family_name, const FontStyle& style,
    const char** bcp47, int32_t bcp47_count, Unichar character) {
    (void)bcp47;
    (void)bcp47_count;
    (void)character;
    return MatchFamilyStyle(family_name, style);
}

void Font::LoadGlyphMetrics(
    const GlyphID* glyphs, uint32_t count, GlyphData* glyph_data, const Paint& paint) const noexcept {
    if (glyph_data == nullptr || count == 0) {
        return;
    }
    const float effective_size = (size_ > 0.0f) ? size_ : paint.GetTextSize();
    const float base_advance   = effective_size * 0.6f;
    const float base_width     = effective_size * 0.5f;
    const float base_height    = effective_size * 0.85f;
    const float bearing_x      = effective_size * 0.05f;
    const float bearing_y      = effective_size * 0.72f;

    for (uint32_t i = 0; i < count; ++i) {
        const GlyphID gid = (glyphs != nullptr) ? glyphs[i] : 0;
        glyph_data[i].id        = gid;
        glyph_data[i].font_size = effective_size;
        if (gid == 0) {
            glyph_data[i].advance_x = 0.0f;
            glyph_data[i].bearing_x = 0.0f;
            glyph_data[i].bearing_y = 0.0f;
            glyph_data[i].width     = 0.0f;
            glyph_data[i].height    = 0.0f;
        } else {
            glyph_data[i].advance_x = base_advance;
            glyph_data[i].bearing_x = bearing_x;
            glyph_data[i].bearing_y = bearing_y;
            glyph_data[i].width     = base_width;
            glyph_data[i].height    = base_height;
        }
    }
}

void Font::GetMetrics(FontMetrics* metrics) const noexcept {
    if (metrics == nullptr) {
        return;
    }
    const float s = (size_ > 0.0f) ? size_ : 12.0f;
    metrics->top                 = -s * 1.05f;
    metrics->ascent              = -s * 0.88f;
    metrics->descent             =  s * 0.22f;
    metrics->bottom              =  s * 0.28f;
    metrics->leading             =  s * 0.05f;
    metrics->avg_char_width      =  s * 0.60f;
    metrics->max_char_width      =  s * 1.20f;
    metrics->x_min               = -s * 0.10f;
    metrics->x_max               =  s * 1.10f;
    metrics->x_height            =  s * 0.52f;
    metrics->cap_height          =  s * 0.72f;
    metrics->underline_thickness =  s * 0.07f;
    metrics->underline_position  =  s * 0.14f;
    metrics->strikeout_thickness =  s * 0.07f;
    metrics->strikeout_position  = -s * 0.30f;
}

}  // namespace skity

namespace lynx {
namespace animax {

// ============================================================================
// 2. Static .bss Variables (0x014000 .. 0x014038)
//    Biến tĩnh trong phân vùng .bss (0x014000 .. 0x014038)
// ============================================================================

namespace {

// .bss 0x014000: Static monotonic counter for FontAssetImplTextra::GetFontFamilyName (@ 0x008c78)
// .bss 0x014000: Bộ đếm tĩnh đơn điệu cho FontAssetImplTextra::GetFontFamilyName (@ 0x008c78)
std::atomic<uint64_t> g_font_family_key_counter{0};

// .bss 0x014008 (guard) & 0x014020 (std::string): Static delimiter string "@_@" (@ 0x008c44 .. 0x008c70)
// .bss 0x014008 (guard) & 0x014020 (std::string): Chuỗi phân tách tĩnh "@_@" (@ 0x008c44 .. 0x008c70)
const std::string& GetStaticFontKeyDelimiter() {
    static const std::string kDelimiter(rodata::kStrFontKeyDelimiter);
    return kDelimiter;
}

}  // namespace

// ============================================================================
// 3. FontAssetImplTextra Implementation (0x0089ec .. 0x008db8)
//    Triển khai FontAssetImplTextra (0x0089ec .. 0x008db8)
// ============================================================================

FontAssetImplTextra::FontAssetImplTextra(FontAsset* font_asset)
    : FontAssetImpl(font_asset),
      unique_key_(),
      typeface_cache_(),
      fontmgr_collection_(nullptr) {}

/**
 * @brief Destructor matching `0x0089ec .. 0x008a3f`:
 *        Releases `fontmgr_collection_` (`+0x50`), clears `typeface_cache_` (`+0x28`),
 *        releases `unique_key_` (`+0x10`) if heap-allocated (`tbz w8, #0, 0x8a20`),
 *        and invokes `operator delete(this)` in D0 (`0x008a28`).
 *        Hàm hủy khớp `0x0089ec .. 0x008a3f`: giải phóng `fontmgr_collection_`, `typeface_cache_` và `unique_key_`.
 */
FontAssetImplTextra::~FontAssetImplTextra() = default;

/**
 * @brief `FontAssetImplTextra::GetFontmgrCollection` (`0x008a40 .. 0x008c08`):
 *        Disassembly trace:
 *        - `0x008a58: ldr x0, [x19, #0x50]; cbnz x0, 0x008bec` (returns cached pointer if non-null)
 *        - `0x008b2c: mov w0, #0x50; bl operator new` (allocates `shared_ptr_emplace<FontManagerTextra>`)
 *        - `0x008ba8: mov w0, #0x38; bl operator new` (allocates `FontmgrCollection`)
 *        - `0x008bb8: bl ttoffice::tttext::FontmgrCollection::FontmgrCollection(shared_ptr<IFontManager>)`
 *        - `0x008bc0: ldr x8, [x19, #0x50]; str x20, [x19, #0x50]`
 */
ttoffice::tttext::FontmgrCollection* FontAssetImplTextra::GetFontmgrCollection() {
    if (fontmgr_collection_ == nullptr) {
        auto font_mgr = std::make_shared<FontManagerTextra>(this);
        fontmgr_collection_ = std::make_unique<ttoffice::tttext::FontmgrCollection>(std::move(font_mgr));
    }
    return fontmgr_collection_.get();
}

/**
 * @brief `FontAssetImplTextra::GetFontFamilyName` (`0x008c0c .. 0x008db8`):
 *        Disassembly trace:
 *        - `0x008c20..0x008c34`: Checks SSO/long length of `this->unique_key_` (`+0x10`).
 *        - `0x008c44..0x008c70`: Thread-safe guard (`__cxa_guard_acquire` @ `0x014008`) initializing `std::string("@_@")` @ `0x014020`.
 *        - `0x008c78..0x008c84`: `ldr x0, [x8]; add x0, x0, #1; str x0, [x8]; bl std::to_string(unsigned long)`
 *        - `0x008c90..0x008cb0`: Appends `"@_@"` (`0x014020`) and `font_asset_->GetName()` (`[x19, #8] + 0x30`).
 */
const std::string& FontAssetImplTextra::GetFontFamilyName() {
    if (unique_key_.empty()) {
        const uint64_t next_id = g_font_family_key_counter.fetch_add(1, std::memory_order_relaxed) + 1;
        std::string prefix = std::to_string(next_id);
        prefix.append(GetStaticFontKeyDelimiter());
        if (font_asset_ != nullptr) {
            prefix.append(font_asset_->GetName());
        }
        unique_key_ = std::move(prefix);
    }
    return unique_key_;
}

uint64_t FontAssetImplTextra::GetCurrentFontKeyCounter() noexcept {
    return g_font_family_key_counter.load(std::memory_order_relaxed);
}

// ============================================================================
// 4. TypefaceTextra Implementation (0x009550 .. 0x009c34)
//    Triển khai TypefaceTextra (0x009550 .. 0x009c34)
// ============================================================================

/**
 * @brief `TypefaceTextra::TypefaceTextra` (`0x009550 .. 0x009674`):
 *        Disassembly trace:
 *        - `0x009564`: Calls `ttoffice::tttext::ITypefaceHelper::ITypefaceHelper(unique_id)`
 *        - `0x009588`: Calls `skity::Paint::Paint()` at `this + 0x20` (`paint_`)
 *        - `0x0095a0..0x0095b8`: Calls `skity::Typeface::GetFontStyle()`, converts `slant` (`bits 24..31 != 0 ? 1 : 0`) via
 *          `tst w0, #0xff000000; cset w8, ne; bfi w21, w8, #0x18, #8` and stores into `this->font_style_` (`+0x10`).
 */
TypefaceTextra::TypefaceTextra(std::shared_ptr<skity::Typeface> skity_typeface, uint64_t unique_id)
    : ttoffice::tttext::ITypefaceHelper(unique_id),
      skity_typeface_(std::move(skity_typeface)),
      paint_() {
    if (skity_typeface_ != nullptr) {
        const skity::FontStyle sk_style = skity_typeface_->GetFontStyle();
        const uint8_t tt_slant = (sk_style.slant != 0) ? 1U : 0U;
        font_style_ = ttoffice::tttext::FontStyle(sk_style.weight, sk_style.width, tt_slant);
    }
}

/**
 * @brief `TypefaceTextra::~TypefaceTextra` (`0x009678 .. 0x0096b7`):
 *        Destroys `paint_`, releases `skity_typeface_` shared_ptr control block, and calls `ITypefaceHelper::~ITypefaceHelper()`.
 */
TypefaceTextra::~TypefaceTextra() = default;

/**
 * @brief `TypefaceTextra::GetHorizontalAdvance` (`0x0096b8 .. 0x009740`):
 *        Disassembly trace:
 *        - `0x0096dc: mov w0, #0x50; bl operator new` (allocates 1 `skity::GlyphData` of 80 bytes)
 *        - `0x0096ec: add x0, x19, #0x20; mov v0.16b, v8.16b; bl skity::Paint::SetTextSize(float)`
 *        - `0x0096fc: bl skity::Font::Font(shared_ptr<skity::Typeface>)`
 *        - `0x009708: mov v0.16b, v8.16b; bl skity::Font::SetSize(float)`
 *        - `0x009718: mov w2, #1; bl skity::Font::LoadGlyphMetrics`
 *        - `0x009720: mov x0, x20; bl skity::GlyphData::GetHoriAdvance() const`
 */
float TypefaceTextra::GetHorizontalAdvance(uint16_t glyph_id, float font_size) const {
    auto glyph_data = std::make_unique<skity::GlyphData>();
    paint_.SetTextSize(font_size);
    skity::Font font(skity_typeface_);
    font.SetSize(font_size);
    font.LoadGlyphMetrics(&glyph_id, 1U, glyph_data.get(), paint_);
    return glyph_data->GetHoriAdvance();
}

/**
 * @brief `TypefaceTextra::GetHorizontalAdvances` (`0x009744 .. 0x0097f4`):
 *        Disassembly trace:
 *        - `0x009760..0x00976c`: `mov w8, #0x50; umull x9, w21, w8; cmp x8, x21; csel x0, xzr, x9, hs; bl operator new`
 *        - `0x009778..0x0097ac`: Sets `paint_.SetTextSize(font_size)`, constructs `skity::Font`, calls `LoadGlyphMetrics(glyph_ids, count, glyph_data, paint_)`.
 *        - `0x0097b4..0x0097cc`: Loops `count` times, advancing `glyph_data` by `0x50` (80 bytes) and storing `GetHoriAdvance()` to `advances[i]`.
 */
void TypefaceTextra::GetHorizontalAdvances(
    uint16_t* glyph_ids, uint32_t count, float* advances, float font_size) const {
    if (count == 0 || advances == nullptr) {
        return;
    }
    std::vector<skity::GlyphData> glyph_data(count);
    paint_.SetTextSize(font_size);
    skity::Font font(skity_typeface_);
    font.SetSize(font_size);
    font.LoadGlyphMetrics(glyph_ids, count, glyph_data.data(), paint_);
    for (uint32_t i = 0; i < count; ++i) {
        advances[i] = glyph_data[i].GetHoriAdvance();
    }
}

/**
 * @brief `TypefaceTextra::GetWidthBound` (`0x0097f8 .. 0x009898`):
 *        Disassembly trace:
 *        - Loads 1 `skity::GlyphData` (`0x50` bytes) via `skity::Font::LoadGlyphMetrics`.
 *        - `0x009844`: `s9 = GetHoriBearingX()` (`left`)
 *        - `0x00984c..0x009850`: `s8 = -GetHoriBearingY()` (`fneg s8, s0` -> `top`)
 *        - `0x009858`: `s10 = GetWidth()` (`right = s9 + s10`)
 *        - `0x009860`: `s0 = GetHeight()` (`bottom = s8 + s0`)
 *        - `0x009868`: `fsub v0.2s, v1.2s, v0.2s` -> converts `[right, bottom]` to `[right - left, bottom - top]` (`[width, height]`)
 *        - `0x009874`: `stp d2, d0, [x19]` -> writes `[left, top, width, height]` to `rect_ltwh[0..3]`.
 */
void TypefaceTextra::GetWidthBound(float* rect_ltwh, uint16_t glyph_id, float font_size) const {
    if (rect_ltwh == nullptr) {
        return;
    }
    skity::Rect rect{};
    GetBoundRects(&rect, &glyph_id, 1U, font_size);
    const float width  = rect.right - rect.left;
    const float height = rect.bottom - rect.top;
    rect_ltwh[0] = rect.left;
    rect_ltwh[1] = rect.top;
    rect_ltwh[2] = width;
    rect_ltwh[3] = height;
}

/**
 * @brief Helper computing `[left, top, right, bottom]` bounding boxes for `count` glyphs (`0x009998 .. 0x009a1c`).
 *        Hàm phụ tính khung bao `[left, top, right, bottom]` cho `count` glyph (`0x009998 .. 0x009a1c`).
 */
void TypefaceTextra::GetBoundRects(
    skity::Rect* out_rects, const uint16_t* glyph_ids, uint32_t count, float font_size) const {
    if (out_rects == nullptr || count == 0) {
        return;
    }
    std::vector<skity::GlyphData> glyph_data(count);
    paint_.SetTextSize(font_size);
    skity::Font font(skity_typeface_);
    font.SetSize(font_size);
    font.LoadGlyphMetrics(glyph_ids, count, glyph_data.data(), paint_);
    for (uint32_t i = 0; i < count; ++i) {
        const float left   = glyph_data[i].GetHoriBearingX();
        const float top    = -glyph_data[i].GetHoriBearingY();
        const float right  = left + glyph_data[i].GetWidth();
        const float bottom = top + glyph_data[i].GetHeight();
        out_rects[i] = skity::Rect{left, top, right, bottom};
    }
}

/**
 * @brief `TypefaceTextra::GetWidthBounds` (`0x00989c .. 0x009a24`):
 *        Disassembly trace:
 *        - `0x0098ac: cbz w3, 0x009990` -> if `count == 0`, `stp xzr, xzr, [x19]; ret` (zeros all 4 floats).
 *        - `0x009930..0x009970`: Loops over `count` 16-byte `skity::Rect` elements:
 *          - `fminnm s1, s1, s4` (`min_top = fmin(min_top, rect[i].top)`)
 *          - `fmaxnm s2, s2, s3` (`max_bottom = fmax(max_bottom, rect[i].bottom)`)
 *          - `fsub s3, s5, s3; fadd s0, s0, s3` (`total_width += (rect[i].right - rect[i].left)`)
 *        - `0x009974..0x00997c`: `fmov s3, wzr; stp s3, s1, [x19]; stp s0, s2, [x19, #8]`
 *          Stores `[0.0f, min_top, total_width, max_bottom]` into `rect_ltrb[0..3]`.
 */
void TypefaceTextra::GetWidthBounds(
    float* rect_ltrb, uint16_t* glyph_ids, uint32_t count, float font_size) {
    if (rect_ltrb == nullptr) {
        return;
    }
    if (count == 0) {
        rect_ltrb[0] = 0.0f;
        rect_ltrb[1] = 0.0f;
        rect_ltrb[2] = 0.0f;
        rect_ltrb[3] = 0.0f;
        return;
    }

    std::vector<skity::Rect> rects(count);
    GetBoundRects(rects.data(), glyph_ids, count, font_size);

    float total_width = 0.0f;
    float min_top     = 0.0f;
    float max_bottom  = 0.0f;

    for (uint32_t i = 0; i < count; ++i) {
        const float left   = rects[i].left;
        const float top    = rects[i].top;
        const float right  = rects[i].right;
        const float bottom = rects[i].bottom;
        min_top     = std::fmin(min_top, top);
        max_bottom  = std::fmax(max_bottom, bottom);
        total_width += (right - left);
    }

    rect_ltrb[0] = 0.0f;
    rect_ltrb[1] = min_top;
    rect_ltrb[2] = total_width;
    rect_ltrb[3] = max_bottom;
}

/**
 * @brief `TypefaceTextra::GetFontData` (`0x009c00 .. 0x009c1b`):
 *        Returns `nullptr` (`mov x0, xzr; ret` @ `0x009c14`).
 */
const void* TypefaceTextra::GetFontData() const {
    return nullptr;
}

/**
 * @brief `TypefaceTextra::GetFontDataSize` (`0x009c1c .. 0x009c23`):
 *        Returns `0` (`mov x0, xzr; ret`).
 */
size_t TypefaceTextra::GetFontDataSize() const {
    return 0;
}

/**
 * @brief `TypefaceTextra::GetFontIndex` (`0x009c24 .. 0x009c2b`):
 *        Returns `0` (`mov w0, wzr; ret`).
 */
int TypefaceTextra::GetFontIndex() const {
    return 0;
}

/**
 * @brief `TypefaceTextra::UnicharToGlyph` (`0x009a28 .. 0x009a2f`):
 *        `ldr x0, [x0, #0x18]; b skity::Typeface::UnicharToGlyph(unsigned int) const`
 */
uint16_t TypefaceTextra::UnicharToGlyph(uint32_t codepoint, uint32_t variation_selector) const {
    (void)variation_selector;
    if (skity_typeface_ == nullptr) {
        return 0;
    }
    return skity_typeface_->UnicharToGlyph(codepoint);
}

/**
 * @brief `TypefaceTextra::UnicharsToGlyphs` (`0x009a30 .. 0x009a37`):
 *        `ldr x0, [x0, #0x18]; b skity::Typeface::UnicharsToGlyphs(unsigned int const*, unsigned int, unsigned short*) const`
 */
void TypefaceTextra::UnicharsToGlyphs(const uint32_t* chars, uint32_t count, uint16_t* glyphs) const {
    if (skity_typeface_ == nullptr) {
        return;
    }
    skity_typeface_->UnicharsToGlyphs(chars, count, glyphs);
}

/**
 * @brief `TypefaceTextra::GetUnitsPerEm` (`0x009a38 .. 0x009a3f`):
 *        `ldr x0, [x0, #0x18]; b skity::Typeface::GetUnitsPerEm() const`
 */
uint16_t TypefaceTextra::GetUnitsPerEm() const {
    if (skity_typeface_ == nullptr) {
        return 1000;
    }
    return skity_typeface_->GetUnitsPerEm();
}

/**
 * @brief `TypefaceTextra::GetCreateArgs` (`0x009c2c .. 0x009c33`):
 *        Returns `nullptr` (`mov x0, xzr; ret`).
 */
const void* TypefaceTextra::GetCreateArgs() const {
    return nullptr;
}

/**
 * @brief `TypefaceTextra::GetFontMetrics` (`0x009a40 .. 0x009bfc`):
 *        Disassembly trace:
 *        - `0x009a64`: `paint_.SetTextSize(font_size)`
 *        - `0x009a74..0x009a9c`: Constructs `skity::Font(skity_typeface_)`, calls `SetSize(font_size)`, and `GetMetrics(&metrics)`.
 *        - `0x009aa8`: Calls `ttoffice::tttext::FontInfo::FontInfo(metrics, font_size)` and copies all `0x40` (64) bytes into `out_info`.
 */
ttoffice::tttext::FontInfo TypefaceTextra::GetFontMetrics(float font_size) const {
    paint_.SetTextSize(font_size);
    skity::Font font(skity_typeface_);
    font.SetSize(font_size);
    skity::FontMetrics metrics{};
    font.GetMetrics(&metrics);
    return ttoffice::tttext::FontInfo(metrics, font_size);
}

void TypefaceTextra::OnCreateFontInfo(ttoffice::tttext::FontInfo* out_info, float font_size) const {
    if (out_info == nullptr) {
        return;
    }
    *out_info = GetFontMetrics(font_size);
}

// ============================================================================
// 5. FontManagerTextra Implementation (0x0092a0 .. 0x00954c & 0x009c38 .. 0x009f8c)
//    Triển khai FontManagerTextra (0x0092a0 .. 0x00954c & 0x009c38 .. 0x009f8c)
// ============================================================================

FontManagerTextra::FontManagerTextra(FontAssetImplTextra* font_asset_impl)
    : font_asset_impl_(font_asset_impl),
      typeface_cache_() {}

FontManagerTextra::~FontManagerTextra() = default;

/**
 * @brief `FontManagerTextra::onCountFamilies` (`0x0092dc` for asset-backed, `0x009db4` for default system manager):
 *        - When `font_asset_impl_ != nullptr` (`0x0092dc`): `mov w0, #1; ret`
 *        - When `font_asset_impl_ == nullptr` (`0x009db4`): delegates to `skity::FontManager::RefDefault()->CountFamilies()`
 */
int32_t FontManagerTextra::onCountFamilies() const {
    if (font_asset_impl_ != nullptr) {
        return 1;
    }
    return skity::FontManager::RefDefault()->CountFamilies();
}

/**
 * @brief `FontManagerTextra::onGetFamilyName` (`0x0092ec` for asset-backed):
 *        `stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret` (returns empty string `""` for asset manager).
 */
std::string FontManagerTextra::onGetFamilyName(int32_t index) const {
    if (font_asset_impl_ != nullptr) {
        return "";
    }
    return skity::FontManager::RefDefault()->GetFamilyName(index);
}

/**
 * @brief `FontManagerTextra::onMatchFamilyStyle` (`0x0092f4 .. 0x00950c` for asset-backed, `0x009dbc .. 0x009f8c` for system):
 *        Disassembly trace:
 *        1. If `font_asset_impl_ != nullptr` (`0x0092f4`):
 *           - Constructs `std::string key(family_name)` (`0x009314`).
 *           - Searches `font_asset_impl_->typeface_cache_` (`+0x28`) via `__hash_table::find` (`0x008dbc`, using CityHash64).
 *           - If not cached, searches `font_asset_impl_->GetFontAsset()->GetTypefaceMap()` (`[x8, #8] + 0x08`) via `__hash_table::find` (`0x009368`).
 *           - If found in `FontAsset`, allocates `std::__shared_ptr_emplace<TypefaceTextra>` (`0xb0 = 176 bytes` @ `0x0093a4`),
 *             initializes `TypefaceTextra` (`0x0093cc`), and inserts into `font_asset_impl_->typeface_cache_` (`0x009428`).
 *        2. If `font_asset_impl_ == nullptr` (`0x009dbc`):
 *           - Looks up `this->typeface_cache_` (`+0x10`).
 *           - Converts `ttoffice::tttext::FontStyle` to `skity::FontStyle` (`slant != 0 ? 1 : 0`) and calls
 *             `skity::FontManager::RefDefault()->MatchFamilyStyle(family_name, sk_style)` (`0x009ea8`).
 *           - Wraps in `TypefaceTextra` (`0xb0 = 176 bytes` @ `0x009ec8`), caches, and returns.
 */
std::shared_ptr<ttoffice::tttext::ITypefaceHelper> FontManagerTextra::onMatchFamilyStyle(
    const char* family_name, const ttoffice::tttext::FontStyle& style) {
    const std::string key = (family_name != nullptr) ? std::string(family_name) : std::string();

    if (font_asset_impl_ != nullptr) {
        auto& asset_cache = font_asset_impl_->GetTypefaceCache();
        auto cached_it = asset_cache.find(key);
        if (cached_it != asset_cache.end()) {
            return cached_it->second;
        }

        FontAsset* host_asset = font_asset_impl_->GetFontAsset();
        if (host_asset != nullptr) {
            const auto& tf_map = host_asset->GetTypefaceMap();
            auto tf_it = tf_map.find(key);
            if (tf_it != tf_map.end() && tf_it->second != nullptr) {
                const uint64_t uid = cityhash::CityHash64(key.data(), key.size());
                auto wrapped = std::make_shared<TypefaceTextra>(tf_it->second, uid);
                asset_cache[key] = wrapped;
                return wrapped;
            }
        }
        return nullptr;
    }

    // Default system font manager path (0x009dbc .. 0x009f8c)
    const std::string cache_key =
        key + "#" + std::to_string(style.weight) + ":" + std::to_string(style.width) + ":" + std::to_string(style.slant);
    auto sys_it = typeface_cache_.find(cache_key);
    if (sys_it != typeface_cache_.end()) {
        return sys_it->second;
    }

    const skity::FontStyle sk_style(style.weight, style.width, (style.slant != 0) ? 1U : 0U);
    auto sk_tf = skity::FontManager::RefDefault()->MatchFamilyStyle(
        key.empty() ? rodata::kStrSansSerif : key.c_str(), sk_style);
    if (sk_tf == nullptr) {
        return nullptr;
    }
    const uint64_t uid = cityhash::CityHash64(cache_key.data(), cache_key.size());
    auto wrapped = std::make_shared<TypefaceTextra>(std::move(sk_tf), uid);
    typeface_cache_[cache_key] = wrapped;
    return wrapped;
}

/**
 * @brief `FontManagerTextra::onMatchFamilyStyleCharacter` (`0x009c80 .. 0x009d40`):
 *        Disassembly trace:
 *        - Converts `ttoffice::tttext::FontStyle` to `skity::FontStyle` (`tst w2, #0xff000000; cset w8, ne; bfi w23, w8, #0x18, #8` @ `0x009cb8`).
 *        - Calls `skity::FontManager::MatchFamilyStyleCharacter` (`0x009cd4`).
 *        - Allocates `0xb0` (176 bytes) `std::__shared_ptr_emplace<TypefaceTextra>` (`0x009cfc`) and constructs `TypefaceTextra` (`0x009d18`).
 */
std::shared_ptr<ttoffice::tttext::ITypefaceHelper> FontManagerTextra::onMatchFamilyStyleCharacter(
    const char* family_name, const ttoffice::tttext::FontStyle& style,
    const char** bcp47, int32_t bcp47_count, uint32_t character) {
    const skity::FontStyle sk_style(style.weight, style.width, (style.slant != 0) ? 1U : 0U);
    auto sk_tf = skity::FontManager::RefDefault()->MatchFamilyStyleCharacter(
        family_name, sk_style, bcp47, bcp47_count, character);
    if (sk_tf == nullptr) {
        return nullptr;
    }
    return std::make_shared<TypefaceTextra>(std::move(sk_tf), static_cast<uint64_t>(character));
}

/**
 * @brief `FontManagerTextra::onMakeFromFile` (`0x009d44 .. 0x009da8`):
 *        Calls `skity::Typeface::MakeFromFile(path)` (`0x009d58`), allocates `0xb0` (176 bytes) control block (`0x009d68`),
 *        and constructs `TypefaceTextra` (`0x009d84`).
 */
std::shared_ptr<ttoffice::tttext::ITypefaceHelper> FontManagerTextra::onMakeFromFile(
    const char* path, int32_t ttc_index) {
    (void)ttc_index;
    auto sk_tf = skity::Typeface::MakeFromFile(path);
    if (sk_tf == nullptr) {
        return nullptr;
    }
    const size_t len = (path != nullptr) ? std::strlen(path) : 0;
    const uint64_t uid = cityhash::CityHash64((path != nullptr) ? path : "", len);
    return std::make_shared<TypefaceTextra>(std::move(sk_tf), uid);
}

/**
 * @brief `FontManagerTextra::onLegacyMakeTypeface` (`0x009510 .. 0x00954c`):
 *        Dispatches through vtable slot `#0x20` (`onMatchFamilyStyle`):
 *        `ldr x8, [x0]; ldr x8, [x8, #0x20]; blr x8` (@ `0x009530 .. 0x009538`).
 */
std::shared_ptr<ttoffice::tttext::ITypefaceHelper> FontManagerTextra::onLegacyMakeTypeface(
    const char* family_name, ttoffice::tttext::FontStyle style) const {
    return const_cast<FontManagerTextra*>(this)->onMatchFamilyStyle(family_name, style);
}

/**
 * @brief `FontManagerTextra::getPlatformFontFromTypeface` (`0x00954c`):
 *        Returns `nullptr` (`mov x0, xzr; ret`).
 */
void* FontManagerTextra::getPlatformFontFromTypeface(
    std::shared_ptr<ttoffice::tttext::ITypefaceHelper> typeface) {
    (void)typeface;
    return nullptr;
}

}  // namespace animax
}  // namespace lynx
