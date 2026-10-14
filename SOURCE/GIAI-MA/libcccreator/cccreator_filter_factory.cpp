// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so
// File: cccreator_filter_factory.cpp
// Description: Full implementation of RecModelBundleHelper and filter constructors
// ===================================================================================

#include "cccreator_filter_factory.h"
#include <sstream>
#include <cstdlib>

namespace vesdk {
namespace ccmodel {

std::string RecModelBundleHelper::getStringParam(const TEBundle& bundle, const std::string& key, const std::string& def_val) {
    auto it = bundle.find(key);
    if (it != bundle.end()) {
        return it->second;
    }
    return def_val;
}

int64_t RecModelBundleHelper::getInt64Param(const TEBundle& bundle, const std::string& key, int64_t def_val) {
    auto it = bundle.find(key);
    if (it != bundle.end()) {
        try {
            return std::stoll(it->second);
        } catch (...) {
            return def_val;
        }
    }
    return def_val;
}

double RecModelBundleHelper::getDoubleParam(const TEBundle& bundle, const std::string& key, double def_val) {
    auto it = bundle.find(key);
    if (it != bundle.end()) {
        try {
            return std::stod(it->second);
        } catch (...) {
            return def_val;
        }
    }
    return def_val;
}

/**
 * @brief createCCFilterFromBundle
 * 
 * Reconstructed from ARM64 Opcode 0x852c30..0x853c58:
 * Reads "filterType", "filterSeqIn", "filterDuration", and dispatches through the jump table.
 */
std::shared_ptr<CCFilter> RecModelBundleHelper::createCCFilterFromBundle(
    const TEBundle& bundle,
    std::shared_ptr<CCClip>& parent_clip
) {
    int32_t filter_type_raw = static_cast<int32_t>(getInt64Param(bundle, BundleKeys::FILTER_TYPE, 0));
    VETimeCode seq_in = getInt64Param(bundle, BundleKeys::FILTER_SEQ_IN, 0);
    VETimeCode duration = getInt64Param(bundle, BundleKeys::FILTER_DURATION, 0);
    VETimeCode seq_out = seq_in + duration;

    std::string filter_id = getStringParam(bundle, "filterId", "cc_filter_auto");

    std::shared_ptr<CCFilter> filter = nullptr;

    switch (static_cast<CCFilterType>(filter_type_raw)) {
        case CCFilterType::FILTER_AUDIO_FADE: {
            // Opcode 0x74e910 (createCCAudioFadeFilter)
            auto audio_fade = std::make_shared<CCAudioFadeFilter>();
            audio_fade->filter_id = filter_id;
            audio_fade->seq_in = seq_in;
            audio_fade->seq_out = seq_out;
            audio_fade->fade_in_duration = getInt64Param(bundle, "fadeInDuration", 0);
            audio_fade->fade_out_duration = getInt64Param(bundle, "fadeOutDuration", 0);
            audio_fade->curve_type = static_cast<AudioFadingCurveType>(getInt64Param(bundle, "fadingCurveType", 0));
            filter = audio_fade;
            break;
        }

        case CCFilterType::FILTER_LENS_VFI: {
            // Opcode 0x74f7e0 (createCCLensVFIFilter)
            auto vfi = std::make_shared<CCLensVFIFilter>();
            vfi->filter_id = filter_id;
            vfi->seq_in = seq_in;
            vfi->seq_out = seq_out;
            vfi->vfi_type = static_cast<LensVFIType>(getInt64Param(bundle, "vfiType", static_cast<int64_t>(LensVFIType::RIFE_OPTICAL)));
            vfi->model_path = getStringParam(bundle, "modelPath", "");
            vfi->fps_ratio = getDoubleParam(bundle, "fpsRatio", 2.0);
            filter = vfi;
            break;
        }

        case CCFilterType::FILTER_MOTION_BLUR: {
            // Opcode 0x74f99c (createCCMotionBlurFilter)
            auto mb = std::make_shared<CCMotionBlurFilter>();
            mb->filter_id = filter_id;
            mb->seq_in = seq_in;
            mb->seq_out = seq_out;
            mb->algo = static_cast<MotionBlurAlgorithmType>(getInt64Param(bundle, "motionBlurAlgo", 1));
            mb->merge = static_cast<MotionBlurMergeType>(getInt64Param(bundle, "motionBlurMerge", 1));
            mb->enable_forward = getInt64Param(bundle, "enableForward", 1) != 0;
            mb->enable_backward = getInt64Param(bundle, "enableBackward", 0) != 0;
            mb->blur_intensity = static_cast<float>(getDoubleParam(bundle, "blurIntensity", 0.5));
            mb->shutter_angle = static_cast<float>(getDoubleParam(bundle, "shutterAngle", 180.0));
            filter = mb;
            break;
        }

        case CCFilterType::FILTER_VIDEO_BLUR: {
            // Opcode 0x609d38 (CCVideoBlurFilter)
            auto vb = std::make_shared<CCVideoBlurFilter>();
            vb->filter_id = filter_id;
            vb->seq_in = seq_in;
            vb->seq_out = seq_out;
            vb->blur_radius = static_cast<float>(getDoubleParam(bundle, "blurRadius", 0.0));
            filter = vb;
            break;
        }

        case CCFilterType::FILTER_RADIUS_CORNER_BORDER: {
            // Opcode 0x60b3b4 (CCRadiusCornerBorderFilter)
            auto rc = std::make_shared<CCRadiusCornerBorderFilter>();
            rc->filter_id = filter_id;
            rc->seq_in = seq_in;
            rc->seq_out = seq_out;
            rc->border_width = getDoubleParam(bundle, "borderWidth", 0.0);
            rc->corner_radius = getDoubleParam(bundle, "cornerRadius", 0.0);
            rc->border_enabled = getInt64Param(bundle, "borderEnabled", 1) != 0;
            filter = rc;
            break;
        }

        case CCFilterType::FILTER_TRANSFORM:
        default: {
            // Opcode 0x158c430 / 0x158c994 (CCTransformFilter)
            auto tf = std::make_shared<CCTransformFilter>();
            tf->filter_id = filter_id;
            tf->seq_in = seq_in;
            tf->seq_out = seq_out;
            tf->scale_x = getDoubleParam(bundle, "scaleX", 1.0);
            tf->scale_y = getDoubleParam(bundle, "scaleY", 1.0);
            tf->trans_x = getDoubleParam(bundle, "transX", 0.0);
            tf->trans_y = getDoubleParam(bundle, "transY", 0.0);
            double rot = getDoubleParam(bundle, "rotation", 0.0);
            // Verify angle normalization modulo 360
            tf->rotation_deg = static_cast<double>(CCTransformFilter::checkRotationValue(rot));
            filter = tf;
            break;
        }
    }

    return filter;
}

} // namespace ccmodel
} // namespace vesdk
