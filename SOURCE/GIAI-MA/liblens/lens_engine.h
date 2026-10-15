// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_engine.h
// Description: Central Lens Engine Implementation, Pipeline FlowGraph & JNI Bridge
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "lens_engine_interface.h"
#include <unordered_map>
#include <mutex>

namespace LENS::FRAMEWORK {

// EN: Central Engine Implementation matching symbol N4LENS9FRAMEWORK14LensEngineImplE
// VN: Hiện thực hóa động cơ Lens trung tâm khớp biểu tượng N4LENS9FRAMEWORK14LensEngineImplE
class LensEngineImpl : public ILensEngineInterface {
public:
    LensEngineImpl();
    ~LensEngineImpl() override;

    bool Initialize(const std::string& config_json) override;
    bool SetAlgorithm(LensAlgorithmType type, const LensAlgorithmJsonInfo& info) override;
    bool ProcessFrame(const LensImageFrame& in_frame, LensImageFrame& out_frame) override;
    void Release() override;
    std::string GetVersion() const override;

    bool IsReady() const { return m_is_initialized; }

private:
    mutable std::mutex m_engine_mutex;
    bool m_is_initialized = false;
    LensAlgorithmType m_active_algorithm_type = LensAlgorithmType::LENS_ALGO_BILATERAL;
    std::unique_ptr<ILensAlgorithmInterface> m_active_algorithm;
    std::vector<std::unique_ptr<ILensAlgorithmInterface>> m_pipeline_graph;
};

} // namespace LENS::FRAMEWORK
