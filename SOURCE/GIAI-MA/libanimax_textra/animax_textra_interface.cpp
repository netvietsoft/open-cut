/**
 * @file animax_textra_interface.cpp
 * @brief End-to-End Self-Test & Invariant Verification for Reconstructed libanimax_textra.so
 *        Kiểm thử tự động đầu-cuối & xác minh bất biến cho thư viện tái dựng libanimax_textra.so
 */

#include "animax_textra_interface.h"

#include <cmath>

namespace NextAI {
namespace OpenCut {
namespace animax_textra {

AnimaxTextraDiagnosticReport AnimaxTextraEngine::RunFullSelfTest() {
    AnimaxTextraDiagnosticReport report{};

    // 1. Verify JNI_OnLoad (0x00b7cc .. 0x00b8c3) returns 0x00010006 and registers TextHelperTextra
    //    Xác minh JNI_OnLoad trả về 0x00010006 và đăng ký TextHelperTextra
    report.jni_onload_version = static_cast<uint32_t>(AnimaxTextra_JNI_OnLoad(nullptr, nullptr));
    lynx::animax::TextHelper* helper = lynx::animax::TextHelper::GetRegisteredImpl();
    report.text_helper_registered = (helper != nullptr && helper == lynx::animax::TextHelperTextra::GetSingletonInstance());

    // 2. Verify FontAssetImplTextra::GetFontFamilyName (0x008c0c) produces "<counter>@_@<name>"
    //    Xác minh FontAssetImplTextra::GetFontFamilyName tạo khóa "<counter>@_@<name>"
    lynx::animax::FontAsset font_asset("PingFangSC-Regular");
    auto custom_tf = std::make_shared<skity::Typeface>("PingFangSC-Regular", skity::FontStyle(400, 5, 0), 1000);
    auto asset_impl = helper->CreateFontAsset(&font_asset);
    const std::string& family_key = asset_impl->GetFontFamilyName();
    font_asset.RegisterTypeface(family_key, custom_tf);
    report.font_family_key_has_delimiter =
        (family_key.find(lynx::animax::rodata::kStrFontKeyDelimiter) != std::string::npos) &&
        (family_key.find("PingFangSC-Regular") != std::string::npos);

    // 3. Verify TextHelperTextra::CheckIfTextSupported (0x00b604) on ASCII and UTF-8 CJK strings
    //    Xác minh CheckIfTextSupported với chuỗi ASCII và UTF-8 tiếng Việt / CJK
    report.text_supported_ascii    = helper->CheckIfTextSupported(&font_asset, "NextAI OpenCut 2026");
    report.text_supported_utf8_cjk = helper->CheckIfTextSupported(&font_asset, "Xin chào Chủ tịch — 剪映专业版");

    // 4. Verify 64-bit alignment LUT 0x0000030303030102ULL (0x00a52c .. 0x00a54c)
    //    Xác minh bảng tra căn lề 64-bit 0x0000030303030102ULL
    using Align = ttoffice::tttext::ParagraphHorizontalAlignment;
    const bool lut_ok =
        (lynx::animax::TextLayerImplTextra::MapJustifyToAlignment(0) == Align::kLeft) &&
        (lynx::animax::TextLayerImplTextra::MapJustifyToAlignment(1) == Align::kCenter) &&
        (lynx::animax::TextLayerImplTextra::MapJustifyToAlignment(2) == Align::kRight) &&
        (lynx::animax::TextLayerImplTextra::MapJustifyToAlignment(3) == Align::kJustify) &&
        (lynx::animax::TextLayerImplTextra::MapJustifyToAlignment(6) == Align::kJustify) &&
        (lynx::animax::TextLayerImplTextra::MapJustifyToAlignment(7) == Align::kLeft);
    report.align_lut_matches_binary = lut_ok;

    // 5. Verify tracking pixel formula (text_size * tracking) / 100.0f (0x00a594 .. 0x00a5a8)
    //    Xác minh công thức khoảng cách chữ (text_size * tracking) / 100.0f
    const float trk = lynx::animax::TextLayerImplTextra::ComputeTrackingPixels(32.0f, 25);
    report.tracking_math_matches_binary = (std::fabs(trk - 8.0f) < 1e-5f);

    // 6. Verify unconstrained layout offsets (-500000.0f @ 0x003518, -1000000.0f @ 0x00351c)
    //    Xác minh độ lệch ngang vùng không giới hạn (-500000.0f @ 0x003518, -1000000.0f @ 0x00351c)
    const float off_left   = lynx::animax::TextLayerImplTextra::ComputeUnconstrainedHorizontalOffset(Align::kLeft);
    const float off_center = lynx::animax::TextLayerImplTextra::ComputeUnconstrainedHorizontalOffset(Align::kCenter);
    const float off_right  = lynx::animax::TextLayerImplTextra::ComputeUnconstrainedHorizontalOffset(Align::kRight);
    report.unconstrained_offsets_match =
        (std::fabs(off_left - 0.0f) < 1e-5f) &&
        (std::fabs(off_center - (-500000.0f)) < 1e-2f) &&
        (std::fabs(off_right - (-1000000.0f)) < 1e-2f);

    // 7. Verify CityHash64 (0x008424 .. 0x0089d8) empty and non-empty string hashes
    //    Xác minh hàm băm CityHash64 (0x008424 .. 0x0089d8)
    const uint64_t h_empty = lynx::animax::cityhash::CityHash64("", 0);
    const uint64_t h_ping  = lynx::animax::cityhash::CityHash64("pingfang", 8);
    report.cityhash64_matches_binary =
        (h_empty == lynx::animax::cityhash::k2) &&
        (h_ping != 0ULL) &&
        (lynx::animax::cityhash::ComputeBucketIndex(h_ping, 16) == (h_ping & 15ULL)) &&
        (lynx::animax::cityhash::ComputeBucketIndex(h_ping, 13) == (h_ping % 13ULL));

    // 8. Execute full TextLayerImplTextra::OnDraw -> LayoutDrawer -> CanvasHelperTextra::DrawGlyphs pipeline
    //    Thực thi toàn bộ đường ống TextLayerImplTextra::OnDraw -> LayoutDrawer -> CanvasHelperTextra::DrawGlyphs
    lynx::animax::Composition comp(15.0f);
    lynx::animax::TextLayer text_layer;
    text_layer.SetComposition(&comp);
    text_layer.SetFontAsset(&font_asset, asset_impl.get());

    auto& doc = text_layer.MutableDocumentData();
    doc.text             = "Hello NextAI OpenCut";
    doc.font_name        = "PingFangSC-Regular";
    doc.size             = 36.0f;
    doc.justify          = 1U; // kCenter
    doc.tracking         = 10;
    doc.line_height      = 42.0f;
    doc.baseline_shift   = 2.0f;
    doc.fill_color       = 0xFFFFFFFFU;
    doc.stroke_color     = 0xFF000000U;
    doc.stroke_width     = 2.0f;
    doc.stroke_over_fill = false;
    doc.box_size         = {0.0f, 0.0f}; // Unconstrained -> 1000000.0f (0x003520)

    auto& selector = text_layer.MutableRangeSelector();
    selector.enabled     = true;
    selector.start_index = 6U;
    selector.end_index   = 12U;

    lynx::animax::TextAnimator anim{};
    anim.has_fill_color   = true;
    anim.fill_color       = 0xFFFFCC00U;
    anim.has_blur         = true;
    anim.blur_radius      = {4.0f, 4.0f};
    anim.font_style_flags = 3; // Bold + Italic (faux skew -0.25f)
    text_layer.MutableAnimators().push_back(anim);

    auto layer_impl = helper->CreateTextLayer(&text_layer);
    skity::Canvas canvas;
    layer_impl->OnDraw(&canvas, 0.85f);
    report.drawn_text_blob_runs = canvas.GetDrawnBlobsCount();

    return report;
}

bool AnimaxTextraEngine::VerifyAllInvariants() {
    const AnimaxTextraDiagnosticReport r = RunFullSelfTest();
    return (r.jni_onload_version == 0x00010006U) &&
           r.text_helper_registered &&
           r.font_family_key_has_delimiter &&
           r.text_supported_ascii &&
           r.text_supported_utf8_cjk &&
           r.align_lut_matches_binary &&
           r.tracking_math_matches_binary &&
           r.unconstrained_offsets_match &&
           r.cityhash64_matches_binary &&
           (r.drawn_text_blob_runs >= 3U);
}

}  // namespace animax_textra
}  // namespace OpenCut
}  // namespace NextAI
