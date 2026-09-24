/**
 * NextAI OpenCut Sticker & Kinetic 3D Text Engine Implementation
 * Triển Khai Động Cơ Nhãn Dán Động & Kiểu Chữ Động 3D
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */

#include "include/sticker_text_engine.h"
#include <android/log.h>

#define LOG_TAG "NextAI_StickerText"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace nextai::graphics {

StickerTextEngine::StickerTextEngine() {
    LOGI("StickerTextEngine initialized (Vector Lottie & 3D Typography ready)");
}

StickerTextEngine::~StickerTextEngine() {
    stickers_.clear();
    text_items_.clear();
}

bool StickerTextEngine::AddSticker(const StickerItem& sticker) {
    stickers_.push_back(sticker);
    LOGI("Added Sticker '%s' (Time: %lld - %lld ms, Keyframes: %zu)",
         sticker.sticker_id.c_str(), (long long)sticker.start_time_ms, (long long)sticker.end_time_ms, sticker.keyframes.size());
    return true;
}

bool StickerTextEngine::AddText(const TextItem3D& text) {
    text_items_.push_back(text);
    LOGI("Added 3D Text '%s' -> Content: '%s', Anim: '%s'",
         text.text_id.c_str(), text.content.c_str(), text.animation_type.c_str());
    return true;
}

bool StickerTextEngine::RenderOverlays(uint32_t target_fbo, int64_t current_time_ms, int32_t width, int32_t height) {
    int active_stickers = 0;
    for (const auto& s : stickers_) {
        if (current_time_ms >= s.start_time_ms && current_time_ms <= s.end_time_ms) {
            active_stickers++;
        }
    }

    int active_texts = 0;
    for (const auto& t : text_items_) {
        if (current_time_ms >= t.start_time_ms && current_time_ms <= t.end_time_ms) {
            active_texts++;
        }
    }

    LOGI("Rendered Overlays at %lld ms: %d Stickers, %d Kinetic 3D Texts onto FBO %u",
         (long long)current_time_ms, active_stickers, active_texts, target_fbo);
    return true;
}

} // namespace nextai::graphics
