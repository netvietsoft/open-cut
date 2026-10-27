// ============================================================================
// File: ttr_engine_core.h
// Target: libttr.so (625,192 bytes)
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// ============================================================================
// [EN] Declarations for TTRAudioEngine (0x029200..0x029703), TTRVideoEngine
//      (0x02d910..0x02e567), and embedded GLSL shaders (.rodata 0x068dce..0x0697e0).
// [VN] Khai báo cho TTRAudioEngine (0x029200..0x029703), TTRVideoEngine
//      (0x02d910..0x02e567) và các shader GLSL nhúng (.rodata 0x068dce..0x0697e0).
// ============================================================================

#pragma once

#include "ttr_render_types.h"

namespace ttr_render {

// [EN] TTRAudioEngine (0x029200..0x029703).
// [VN] Động cơ xử lý âm thanh TTRAudioEngine (0x029200..0x029703).
class TTRAudioEngine {
public:
    TTRAudioEngine();                                                // 0x029200
    virtual ~TTRAudioEngine();                                       // 0x029258

    int32_t Open(TTRAudioInfo& info);                                // 0x0292c4
    int32_t SetupPipeline();                                         // 0x0292d8
    void Close();                                                    // 0x0293c8
    void DestroyPipeline();                                          // 0x0293cc
    void Pause();                                                    // 0x029414
    void Resume();                                                   // 0x029424
    void Flush();                                                    // 0x02943c
    int32_t Process(AVFrame* frame);                                 // 0x029454
    int32_t AddFilter(uint64_t filter_id, TTRMessage* msg);          // 0x0294ac
    int32_t RemoveFilter(uint64_t filter_id);                        // 0x0294f8
    int32_t SetParameter(uint64_t filter_id, TTRMessage* msg);       // 0x02952c
    void SetVolume(float volume) noexcept;                           // 0x029560
    float GetVolume() const noexcept;                                // 0x02959c
    void SetMute(bool mute) noexcept;                                // 0x0295bc
    bool GetMute() const noexcept;                                   // 0x029674
    int32_t GetLatency() const noexcept;                             // 0x02969c
    void SetExtLatency(int32_t ext_latency) noexcept;                // 0x0296b0
    int32_t SetupDevice() noexcept;                                  // 0x0296c0
    void DestroyDevice() noexcept;                                   // 0x0296c4

private:
    float volume_{1.0f};       // +0x2c (0x3f800000)
    double speed_{1.0};        // +0x30 (0x3ff0000000000000)
    int32_t device_id_{-1};    // +0x40 (-1)
    int32_t latency_ms_{0};
    int32_t ext_latency_ms_{0};
    bool is_muted_{false};
    bool is_paused_{false};
    std::unordered_map<uint64_t, TTRMessage> filters_;
};

// [EN] TTRVideoEngine (0x02d910..0x02e567, sizeof == 0x50 = 80 bytes @ 0x02d920: mov w0, #0x50).
// [VN] Động cơ kết xuất video TTRVideoEngine (0x02d910..0x02e567, kích thước 0x50 = 80 byte).
class TTRVideoEngine {
public:
    TTRVideoEngine();                                                // 0x02d940
    virtual ~TTRVideoEngine();                                       // 0x02da18

    static TTRVideoEngine* Create();                                 // 0x02d910
    static void Delete(TTRVideoEngine* engine);                      // 0x02db0c
    void Release();                                                  // 0x02da80

    int32_t Init(TTREnvConfig& config);                              // 0x02db18
    void DoSetSurfaceSize(int32_t width, int32_t height);            // 0x02de40
    void Pause();                                                    // 0x02df94
    void Resume();                                                   // 0x02dfec
    int32_t SetParameter(uint64_t key, TTRMessage& msg);             // 0x02e044
    int32_t GetParameter(int32_t key, TTRMessage& msg, uint64_t sub, bool flag); // 0x02e1ec
    void* GetDecodeSurface() const noexcept;                         // 0x02e248
    int32_t SetSurface(void* surface, bool immediate);               // 0x02e25c
    void SetSurfaceSize(int32_t width, int32_t height, bool immediate); // 0x02e300
    int32_t Draw(TTRVideoFrame* frame);                              // 0x02e318
    void DoAdaptViewSize();                                          // 0x02e3a4
    int32_t DoRender();                                              // 0x02e418
    int32_t AddFilter(uint64_t filter_id, TTRMessage* msg);          // 0x02e4e8
    int32_t RemoveFilter(uint64_t filter_id);                        // 0x02e544

    static const char* GetSharpenSuppressionFragmentShaderGles3() noexcept; // .rodata 0x068dce

private:
    void* surface_{nullptr};
    int32_t surface_width_{0};
    int32_t surface_height_{0};
    bool is_paused_{false};
    std::unordered_map<uint64_t, TTRMessage> video_filters_;
};

} // namespace ttr_render
