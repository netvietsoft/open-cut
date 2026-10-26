/**
 * @file animax_textra_interface.h
 * @brief Public Verification & Diagnostic Interface for Reconstructed libanimax_textra.so
 *        Giao diện kiểm định và chẩn đoán công khai cho thư viện tái dựng libanimax_textra.so
 *
 * Binary Ground Truth / Bằng chứng nhị phân:
 * - File size: 83,952 bytes (24 ELF64 AArch64 sections)
 * - Exported symbol [101]: JNI_OnLoad @ 0x00b7cc (248 bytes, returns 0x00010006)
 * - Core Classes:
 *   1. lynx::animax::FontAssetImplTextra (sizeof = 0x58 = 88 bytes, vtable @ 0x010018)
 *   2. lynx::animax::TypefaceTextra (sizeof = 0x98 = 152 bytes, vtable @ 0x010110)
 *   3. lynx::animax::FontManagerTextra (sizeof = 0x40 = 64 bytes, vtables @ 0x010080 & 0x010238)
 *   4. lynx::animax::TextLayerImplTextra (sizeof = 0x28 = 40 bytes, vtable @ 0x0102c0)
 *   5. lynx::animax::CanvasHelperTextra (vtable @ 0x0102e8)
 *   6. lynx::animax::ParagraphStyleTextra (0x00b45c .. 0x00b52c)
 *   7. lynx::animax::TextHelperTextra (vtable @ 0x010460, singleton @ .bss 0x014018)
 */

#ifndef NEXTAI_OPENCUT_ANIMAX_TEXTRA_INTERFACE_H_
#define NEXTAI_OPENCUT_ANIMAX_TEXTRA_INTERFACE_H_

#include "animax_textra_layer_canvas.h"

#include <cstdint>
#include <string>

namespace NextAI {
namespace OpenCut {
namespace animax_textra {

struct AnimaxTextraDiagnosticReport {
    uint32_t jni_onload_version            = 0;
    bool     text_helper_registered        = false;
    bool     font_family_key_has_delimiter = false;
    bool     text_supported_ascii          = false;
    bool     text_supported_utf8_cjk       = false;
    bool     align_lut_matches_binary      = false;
    bool     tracking_math_matches_binary  = false;
    bool     unconstrained_offsets_match   = false;
    bool     cityhash64_matches_binary     = false;
    size_t   drawn_text_blob_runs          = 0;
};

class AnimaxTextraEngine {
public:
    AnimaxTextraEngine() = default;
    virtual ~AnimaxTextraEngine() = default;

    /**
     * @brief Executes an end-to-end self-verification of all reconstructed `libanimax_textra.so` components.
     *        Thực thi kiểm định đầu-cuối toàn bộ các thành phần tái dựng của `libanimax_textra.so`.
     */
    static AnimaxTextraDiagnosticReport RunFullSelfTest();

    /**
     * @brief Returns true if every invariant in `RunFullSelfTest()` passes 100%.
     *        Trả về true nếu mọi bất biến trong `RunFullSelfTest()` đạt 100%.
     */
    static bool VerifyAllInvariants();
};

}  // namespace animax_textra
}  // namespace OpenCut
}  // namespace NextAI

#endif  // NEXTAI_OPENCUT_ANIMAX_TEXTRA_INTERFACE_H_
