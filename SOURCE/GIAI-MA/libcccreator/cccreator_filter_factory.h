// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so
// File: cccreator_filter_factory.h
// Description: RecModelBundleHelper and filter factory reverse-engineered from AArch64
//              jump table at opcode 0x852c8c
// ===================================================================================

#pragma once

#include "cccreator_types.h"
#include <memory>
#include <string>

namespace vesdk {
namespace ccmodel {

/**
 * @brief RecModelBundleHelper recreates CapCut filters from serialized project bundles
 *        Khôi phục 100% logic hàm RecModelBundleHelper::createCCFilterFromBundle tại opcode 0x852c30
 */
class RecModelBundleHelper {
public:
    /**
     * @brief Factory creating specific CCFilter instances by parsing TEBundle key-values
     */
    static std::shared_ptr<CCFilter> createCCFilterFromBundle(
        const TEBundle& bundle,
        std::shared_ptr<CCClip>& parent_clip
    );

    /**
     * @brief Helper to extract string from bundle or return default
     */
    static std::string getStringParam(const TEBundle& bundle, const std::string& key, const std::string& def_val = "");

    /**
     * @brief Helper to extract int64 from bundle
     */
    static int64_t getInt64Param(const TEBundle& bundle, const std::string& key, int64_t def_val = 0);

    /**
     * @brief Helper to extract double from bundle
     */
    static double getDoubleParam(const TEBundle& bundle, const std::string& key, double def_val = 0.0);
};

} // namespace ccmodel
} // namespace vesdk
