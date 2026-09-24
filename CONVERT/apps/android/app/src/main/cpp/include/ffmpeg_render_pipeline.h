/**
 * NextAI OpenCut FFmpeg Render Pipeline Header
 * Tệp Khai Báo Đường Ống Kết Xuất FFmpeg Filtergraph Pipeline 4K/60fps
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */

#ifndef NEXTAI_FFMPEG_RENDER_PIPELINE_H
#define NEXTAI_FFMPEG_RENDER_PIPELINE_H

#include <string>
#include <vector>
#include <cstdint>

namespace nextai::render {

/**
 * Render Export Settings
 * Cấu hình kết xuất chất lượng cao 4K/60fps
 */
struct RenderExportOptions {
    std::string output_path;
    int32_t width;
    int32_t height;
    int32_t fps;
    int32_t video_bitrate_kbps;
    int32_t audio_bitrate_kbps;
    std::string video_codec;    // "h264_mediacodec", "hevc_mediacodec", "libx264", "libx265"
    std::string audio_codec;    // "aac", "mp3"
    std::string color_lut_path; // 3D LUT Cube file path
    bool enable_hdr_10bit;
    bool enable_audio_ducking;
};

/**
 * FFmpeg Filtergraph Generator & Hardware Render Pipeline
 * Động Cơ Biên Dịch Filtergraph & Kết Xuất Video Đa Track
 */
class FFmpegRenderPipeline {
public:
    FFmpegRenderPipeline();
    ~FFmpegRenderPipeline();

    /**
     * Build complex multi-track filtergraph string
     * Sinh chuỗi Filtergraph phức hợp kết hợp đa track, transition, LUT và sticker
     */
    std::string BuildFiltergraphString(const std::vector<std::string>& video_inputs,
                                       const std::vector<std::string>& audio_inputs,
                                       const RenderExportOptions& options);

    /**
     * Execute rendering export task asynchronously
     * Thực thi tác vụ kết xuất video đa luồng
     */
    bool ExecuteRender(const RenderExportOptions& options, 
                       void (*progress_callback)(float progress_percent));

    /**
     * Cancel ongoing render job
     * Hủy tác vụ kết xuất đang chạy
     */
    void CancelRender();

private:
    bool is_cancelled_;
};

} // namespace nextai::render

#endif // NEXTAI_FFMPEG_RENDER_PIPELINE_H
