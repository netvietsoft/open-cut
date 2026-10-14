// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_nodes.h
// Description: Concrete Video Editing DAG Task Nodes
//              (VideoDecode, AudioMix, FilterShader, SmartCutout, RenderEncode,
//               TransitionCrossfade, KeyframeEval, SubtitleRender)
// ===================================================================================

#pragma once

#include "clipflow_types.h"
#include <string>
#include <vector>
#include <memory>

namespace clipflow {

/**
 * @brief Nút giải mã video (Video Decode Task Node)
 */
class VideoDecodeTaskNode : public IClipFlowTask {
public:
    VideoDecodeTaskNode(std::string task_id, std::string source_path, int64_t start_time_ms, int64_t end_time_ms);
    ~VideoDecodeTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 10; } // Ưu tiên giải mã cao

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

    int32_t getDecodedFrameCount() const { return m_decoded_frames; }

private:
    std::string m_task_id;
    std::string m_task_type;
    std::string m_source_path;
    int64_t m_start_time_ms;
    int64_t m_end_time_ms;
    int32_t m_decoded_frames;
    bool m_is_cancelled;
};

/**
 * @brief Nút hòa trộn âm thanh đa rãnh (Audio Mixing Task Node)
 */
class AudioMixTaskNode : public IClipFlowTask {
public:
    AudioMixTaskNode(std::string task_id, std::vector<std::string> audio_track_paths);
    ~AudioMixTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 8; }

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

private:
    std::string m_task_id;
    std::string m_task_type;
    std::vector<std::string> m_tracks;
    bool m_is_cancelled;
};

/**
 * @brief Nút áp dụng hiệu ứng và bộ lọc đồ họa (Filter & Shader Task Node)
 */
class FilterShaderTaskNode : public IClipFlowTask {
public:
    FilterShaderTaskNode(std::string task_id, std::string filter_name, float intensity = 1.0f);
    ~FilterShaderTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 5; }

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

private:
    std::string m_task_id;
    std::string m_task_type;
    std::string m_filter_name;
    float m_intensity;
    bool m_is_cancelled;
};

/**
 * @brief Nút chuyển cảnh giữa các phân đoạn clip (Transition Crossfade Node)
 */
class TransitionCrossfadeTaskNode : public IClipFlowTask {
public:
    TransitionCrossfadeTaskNode(std::string task_id, std::string from_clip_id, std::string to_clip_id, int64_t duration_ms);
    ~TransitionCrossfadeTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 6; }

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

private:
    std::string m_task_id;
    std::string m_task_type;
    std::string m_from_clip;
    std::string m_to_clip;
    int64_t m_duration_ms;
    bool m_is_cancelled;
};

/**
 * @brief Nút tính toán nội suy khung hình chính (Keyframe Animation Evaluator Node)
 */
class KeyframeEvalTaskNode : public IClipFlowTask {
public:
    KeyframeEvalTaskNode(std::string task_id, std::string property_name);
    ~KeyframeEvalTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 7; }

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

    void addKeyframe(int64_t time_ms, float value);
    float evaluate(int64_t time_ms) const;

private:
    std::string m_task_id;
    std::string m_task_type;
    std::string m_property;
    std::vector<std::pair<int64_t, float>> m_keyframes;
    bool m_is_cancelled;
};

/**
 * @brief Nút render phụ đề hoạt họa (Subtitle Animation Render Node)
 */
class SubtitleRenderTaskNode : public IClipFlowTask {
public:
    SubtitleRenderTaskNode(std::string task_id, std::string text, int64_t start_ms, int64_t end_ms);
    ~SubtitleRenderTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 4; }

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

private:
    std::string m_task_id;
    std::string m_task_type;
    std::string m_text;
    int64_t m_start_ms;
    int64_t m_end_ms;
    bool m_is_cancelled;
};

/**
 * @brief Nút render và đóng gói mã hóa video (Render & Encode Task Node)
 */
class RenderEncodeTaskNode : public IClipFlowTask {
public:
    RenderEncodeTaskNode(std::string task_id, std::string output_path, int32_t width, int32_t height, int32_t fps);
    ~RenderEncodeTaskNode() override = default;

    const std::string& getTaskId() const override { return m_task_id; }
    const std::string& getTaskType() const override { return m_task_type; }
    int32_t getPriority() const override { return 1; }

    ClipFlowTaskExecuteState execute() override;
    void cancel() override { m_is_cancelled = true; }

    const std::string& getOutputPath() const { return m_output_path; }

private:
    std::string m_task_id;
    std::string m_task_type;
    std::string m_output_path;
    int32_t m_width;
    int32_t m_height;
    int32_t m_fps;
    bool m_is_cancelled;
};

} // namespace clipflow
