/**
 * @file animax_textra_font_typeface.h
 * @brief Exact Reconstruction of FontAssetImplTextra, TypefaceTextra, and FontManagerTextra (0x0089ec .. 0x009f8c)
 *        Tái dựng chuẩn xác FontAssetImplTextra, TypefaceTextra và FontManagerTextra (0x0089ec .. 0x009f8c)
 *
 * Binary Ground Truth / Bằng chứng nhị phân:
 * - lynx::animax::FontAssetImplTextra:
 *   - Size: 0x58 (88 bytes), allocated in TextHelperTextra::CreateFontAsset @ 0x00b5c0 (mov w0, #0x58; bl operator new)
 *   - VTable: 0x010018 .. 0x010030 (.data.rel.ro)
 *   - Methods: ~FontAssetImplTextra (0x0089ec / 0x008a28), GetFontmgrCollection (0x008a40), GetFontFamilyName (0x008c0c)
 * - lynx::animax::TypefaceTextra:
 *   - Size: 0x98 (152 bytes) inside 0xb0 (176 bytes) std::__shared_ptr_emplace<TypefaceTextra> @ 0x009560
 *   - VTable: 0x010110 .. 0x010170 (.data.rel.ro)
 *   - Methods: Ctor (0x009550), Dtor (0x009678 / 0x0096a0), GetHorizontalAdvance (0x0096b8),
 *     GetHorizontalAdvances (0x009744), GetWidthBound (0x0097f8), GetWidthBounds (0x00989c),
 *     UnicharToGlyph (0x009a28), UnicharsToGlyphs (0x009a30), GetUnitsPerEm (0x009a38),
 *     GetFontMetrics (0x009a40), GetFontData (0x009c00), GetFontDataSize (0x009c1c),
 *     GetFontIndex (0x009c24), GetCreateArgs (0x009c2c)
 * - lynx::animax::FontManagerTextra:
 *   - Size: 0x40 (64 bytes) inside 0x50 (80 bytes) std::__shared_ptr_emplace<FontManagerTextra> @ 0x008b2c
 *   - VTables: 0x010080 .. 0x0100c0 & 0x010238 .. 0x010278 (.data.rel.ro)
 */

#ifndef NEXTAI_OPENCUT_ANIMAX_TEXTRA_FONT_TYPEFACE_H_
#define NEXTAI_OPENCUT_ANIMAX_TEXTRA_FONT_TYPEFACE_H_

#include "animax_textra_types.h"

#include <atomic>
#include <cmath>
#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace lynx {
namespace animax {

/**
 * @brief `lynx::animax::FontAsset` — Host font asset holding custom `skity::Typeface` map and asset family name.
 *        Exact field offsets verified in `FontManagerTextra::onMatchFamilyStyle` (@ `0x009360`: `ldr x8, [x8, #8]; add x0, x8, #8`)
 *        and `FontAssetImplTextra::GetFontFamilyName` (@ `0x008ca8`: `ldr x8, [x19, #8]; add x2, x8, #0x30`).
 *        Đối tượng tài nguyên phông chữ chứa bảng ánh xạ `skity::Typeface` tại `+0x08` và tên phông tại `+0x30`.
 */
class FontAsset {
public:
    explicit FontAsset(std::string name = "PingFang") : name_(std::move(name)) {}

    void RegisterTypeface(const std::string& key, std::shared_ptr<skity::Typeface> typeface) {
        typeface_map_[key] = std::move(typeface);
    }

    const std::unordered_map<std::string, std::shared_ptr<skity::Typeface>>& GetTypefaceMap() const noexcept {
        return typeface_map_;
    }

    const std::string& GetName() const noexcept { return name_; }
    void SetName(std::string name) noexcept { name_ = std::move(name); }

private:
    void* reserved_header_ = nullptr; // +0x00
    std::unordered_map<std::string, std::shared_ptr<skity::Typeface>> typeface_map_; // +0x08 (40 bytes)
    std::string name_; // +0x30 (24 bytes)
};

/**
 * @brief `lynx::animax::FontAssetImpl` — Base interface for `FontAssetImplTextra`.
 *        Giao diện cơ sở cho `FontAssetImplTextra`.
 */
class FontAssetImpl {
public:
    explicit FontAssetImpl(FontAsset* font_asset) noexcept : font_asset_(font_asset) {}
    virtual ~FontAssetImpl() = default;

    virtual ttoffice::tttext::FontmgrCollection* GetFontmgrCollection() = 0;
    virtual const std::string& GetFontFamilyName() = 0;

    FontAsset* GetFontAsset() const noexcept { return font_asset_; }

protected:
    FontAsset* font_asset_ = nullptr; // +0x08
};

/**
 * @brief `lynx::animax::TypefaceTextra` (`sizeof == 0x98 = 152 bytes`, vtable @ `0x010110 .. 0x010170`).
 *        Adapter bridging `ttoffice::tttext::ITypefaceHelper` to `skity::Typeface` and `skity::Font`.
 *        Lớp chuyển đổi kết nối `ttoffice::tttext::ITypefaceHelper` sang `skity::Typeface` và `skity::Font`.
 */
class TypefaceTextra final : public ttoffice::tttext::ITypefaceHelper {
public:
    /**
     * @brief Constructor matching `0x009550 .. 0x009674`.
     *        Hàm khởi tạo khớp địa chỉ `0x009550 .. 0x009674`.
     */
    TypefaceTextra(std::shared_ptr<skity::Typeface> skity_typeface, uint64_t unique_id = 0);

    /**
     * @brief Virtual destructor matching `0x009678` (D1) and `0x0096a0` (D0).
     *        Hàm hủy ảo khớp địa chỉ `0x009678` (D1) và `0x0096a0` (D0).
     */
    ~TypefaceTextra() override;

    // ITypefaceHelper overrides (VTable @ 0x010120 .. 0x010170):
    float GetHorizontalAdvance(uint16_t glyph_id, float font_size) const override;
    void GetHorizontalAdvances(uint16_t* glyph_ids, uint32_t count, float* advances, float font_size) const override;
    void GetWidthBound(float* rect_ltwh, uint16_t glyph_id, float font_size) const override;
    void GetWidthBounds(float* rect_ltrb, uint16_t* glyph_ids, uint32_t count, float font_size) override;
    const void* GetFontData() const override;
    size_t GetFontDataSize() const override;
    int GetFontIndex() const override;
    uint16_t UnicharToGlyph(uint32_t codepoint, uint32_t variation_selector = 0) const override;
    void UnicharsToGlyphs(const uint32_t* chars, uint32_t count, uint16_t* glyphs) const override;
    const void* GetCreateArgs() const override;
    void OnCreateFontInfo(ttoffice::tttext::FontInfo* out_info, float font_size) const override;

    // Non-virtual helper matching symbol `_ZNK4lynx6animax14TypefaceTextra13GetUnitsPerEmEv` @ 0x009a38
    uint16_t GetUnitsPerEm() const;

    // Alias matching symbol `_ZNK4lynx6animax14TypefaceTextra14GetFontMetricsEf` @ 0x009a40
    ttoffice::tttext::FontInfo GetFontMetrics(float font_size) const;

    const std::shared_ptr<skity::Typeface>& GetSkityTypeface() const noexcept {
        return skity_typeface_;
    }

private:
    void GetBoundRects(skity::Rect* out_rects, const uint16_t* glyph_ids, uint32_t count, float font_size) const;

    std::shared_ptr<skity::Typeface> skity_typeface_; // +0x18 (16 bytes)
    mutable skity::Paint paint_;                      // +0x28 .. +0x97
};

class FontAssetImplTextra;

/**
 * @brief `lynx::animax::FontManagerTextra` (`sizeof == 0x40 = 64 bytes`, vtables @ `0x010080` and `0x010238`).
 *        Implements `ttoffice::tttext::IFontManager` for both asset-backed fonts (`font_asset_impl_ != nullptr`)
 *        and default system fonts (`font_asset_impl_ == nullptr`).
 *        Thực thi `ttoffice::tttext::IFontManager` cho cả phông tài nguyên tùy chỉnh và phông hệ thống mặc định.
 */
class FontManagerTextra final : public ttoffice::tttext::IFontManager {
public:
    explicit FontManagerTextra(FontAssetImplTextra* font_asset_impl = nullptr);
    ~FontManagerTextra() override;

    int32_t onCountFamilies() const override;
    std::string onGetFamilyName(int32_t index) const override;
    std::shared_ptr<ttoffice::tttext::ITypefaceHelper> onMatchFamilyStyle(
        const char* family_name, const ttoffice::tttext::FontStyle& style) override;
    std::shared_ptr<ttoffice::tttext::ITypefaceHelper> onMatchFamilyStyleCharacter(
        const char* family_name, const ttoffice::tttext::FontStyle& style,
        const char** bcp47, int32_t bcp47_count, uint32_t character) override;
    std::shared_ptr<ttoffice::tttext::ITypefaceHelper> onMakeFromFile(
        const char* path, int32_t ttc_index) override;
    std::shared_ptr<ttoffice::tttext::ITypefaceHelper> onLegacyMakeTypeface(
        const char* family_name, ttoffice::tttext::FontStyle style) const override;
    void* getPlatformFontFromTypeface(
        std::shared_ptr<ttoffice::tttext::ITypefaceHelper> typeface) override;

private:
    FontAssetImplTextra* font_asset_impl_ = nullptr; // +0x08
    std::unordered_map<std::string, std::shared_ptr<ttoffice::tttext::ITypefaceHelper>> typeface_cache_; // +0x10 (40 bytes)
};

/**
 * @brief `lynx::animax::FontAssetImplTextra` (`sizeof == 0x58 = 88 bytes`, vtable @ `0x010018 .. 0x010030`).
 *        Manages unique `@_@`-delimited font family keys and lazy `FontmgrCollection` initialization.
 *        Quản lý khóa họ phông phân tách bởi `@_@` và khởi tạo trễ `FontmgrCollection`.
 */
class FontAssetImplTextra final : public FontAssetImpl {
public:
    explicit FontAssetImplTextra(FontAsset* font_asset);
    ~FontAssetImplTextra() override;

    /**
     * @brief Matches `0x008a40 .. 0x008c08`:
     *        Lazily allocates `FontManagerTextra` (`0x50` bytes control block) and `FontmgrCollection` (`0x38` bytes).
     *        Khớp `0x008a40 .. 0x008c08`: Khởi tạo trễ `FontManagerTextra` và `FontmgrCollection`.
     */
    ttoffice::tttext::FontmgrCollection* GetFontmgrCollection() override;

    /**
     * @brief Matches `0x008c0c .. 0x008db8`:
     *        Generates `<counter>@_@<FontAsset::GetName()>` using `.bss 0x014000` counter and `.rodata 0x00358a` `"@_@"`.
     *        Khớp `0x008c0c .. 0x008db8`: Tạo chuỗi khóa `<counter>@_@<FontAsset::GetName()>`.
     */
    const std::string& GetFontFamilyName() override;

    std::unordered_map<std::string, std::shared_ptr<ttoffice::tttext::ITypefaceHelper>>& GetTypefaceCache() noexcept {
        return typeface_cache_;
    }

    static uint64_t GetCurrentFontKeyCounter() noexcept;

private:
    std::string unique_key_; // +0x10 .. +0x27 (24 bytes)
    std::unordered_map<std::string, std::shared_ptr<ttoffice::tttext::ITypefaceHelper>> typeface_cache_; // +0x28 .. +0x4f (40 bytes)
    std::unique_ptr<ttoffice::tttext::FontmgrCollection> fontmgr_collection_; // +0x50 (8 bytes -> total 0x58 = 88 bytes)
};

}  // namespace animax
}  // namespace lynx

#endif  // NEXTAI_OPENCUT_ANIMAX_TEXTRA_FONT_TYPEFACE_H_
