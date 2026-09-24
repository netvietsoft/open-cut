/**
 * MiddleBridge C++ Header / Tệp Khai Báo Cầu Nối C++ Native
 * Defines timeline, track management, video cut/split, and render pipeline.
 * Định nghĩa cấu trúc dòng thời gian, quản lý track, cắt video và đường ống render.
 */

#ifndef NEXTAI_MIDDLE_BRIDGE_H
#define NEXTAI_MIDDLE_BRIDGE_H

#include <string>
#include <vector>
#include <memory>
#include <cstdint>

namespace nextai::engine {

struct VideoSegment {
    int64_t segment_id;
    int64_t start_time_ms;
    int64_t end_time_ms;
    std::string source_path;
    float speed;
    float volume;
};

struct TimelineTrack {
    int32_t track_id;
    std::string track_type; // "video", "audio", "text", "effect"
    std::vector<VideoSegment> segments;
};

class TimelineEngine {
public:
    TimelineEngine();
    ~TimelineEngine();

    /**
     * Add or update track in timeline / Thêm hoặc cập nhật track trong dòng thời gian
     */
    bool AddTrack(int32_t track_id, const std::string& track_type);

    /**
     * Split video segment at timestamp / Cắt tách đoạn video tại mốc thời gian
     */
    bool SplitSegment(int32_t track_id, int64_t split_time_ms);

    /**
     * Apply transition between two clips / Thêm hiệu ứng chuyển cảnh
     */
    bool ApplyTransition(int32_t track_id, int64_t position_ms, const std::string& transition_name, int64_t duration_ms);

    /**
     * Render timeline to output file / Kết xuất dòng thời gian ra tệp video hoàn chỉnh
     */
    bool RenderExport(const std::string& output_path, int32_t width, int32_t height, int32_t fps, int32_t bitrate_kbps);

    /**
     * Get total timeline duration / Lấy tổng thời lượng dòng thời gian
     */
    int64_t GetDurationMs() const;

private:
    std::vector<TimelineTrack> tracks_;
    int64_t total_duration_ms_;
};

} // namespace nextai::engine

#endif // NEXTAI_MIDDLE_BRIDGE_H
