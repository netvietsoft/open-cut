// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so (CapCut Template Creator Core & ILA SDK)
// File: cccreator_interface.h
// Description: Unified coordinator interface for CCModel, Filters, and ILASDK
// ===================================================================================

#pragma once

#include "cccreator_types.h"
#include "cccreator_clip.h"
#include "cccreator_filter_factory.h"
#include "cccreator_ilasdk_matcher.h"
#include <jni.h>
#include <memory>
#include <string>
#include <vector>

namespace NextAI::OpenCut::cccreator {

/**
 * @brief CapCut Template Creator Engine Coordinator
 * Bộ điều phối trung tâm lõi sinh mẫu video và ghép mẫu tự động
 */
class CccreatorEngine {
public:
    CccreatorEngine();
    virtual ~CccreatorEngine();

    /**
     * @brief Initializes the Creator Engine environment
     */
    bool initialize(const std::string& template_root_dir);

    /**
     * @brief Loads and parses a CapCut template draft bundle
     */
    bool loadTemplateBundle(const vesdk::ccmodel::TEBundle& bundle);

    /**
     * @brief Adds a clip segment to the template project
     */
    bool addClip(const std::shared_ptr<vesdk::ccmodel::CCClip>& clip);

    /**
     * @brief Adds a filter to the current template model
     */
    bool addFilter(const std::shared_ptr<vesdk::ccmodel::CCFilter>& filter);

    /**
     * @brief Executes intelligent CutSame template auto-assembly
     */
    std::vector<vesdk::ccmodel::ilasdk::TemplateSlotMatch> assembleCutSameTemplate(
        const std::vector<vesdk::ccmodel::ilasdk::TemplateSlotRequirement>& slots,
        const std::vector<vesdk::ccmodel::ilasdk::AssetInfo>& user_assets,
        const std::vector<vesdk::ccmodel::ilasdk::FaceQuality>& face_qualities
    );

    /**
     * @brief Executes comprehensive self-test suite verifying ARM64 opcode parity
     */
    bool runSelfTest();

private:
    std::string m_template_dir;
    std::vector<std::shared_ptr<vesdk::ccmodel::CCClip>> m_clips;
    std::vector<std::shared_ptr<vesdk::ccmodel::CCFilter>> m_filters;
    bool m_initialized;
};

} // namespace NextAI::OpenCut::cccreator
