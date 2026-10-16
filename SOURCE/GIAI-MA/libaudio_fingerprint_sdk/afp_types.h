// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Acoustic Landmark Fingerprint Engine
// File: afp_types.h
// Description: Core data types, structures, and constants for audio fingerprinting,
//              constellation map peak extraction, and bitstream compression.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_AFP_TYPES_H_
#define NEXTAI_OPENCUT_AFP_TYPES_H_

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <utility>

namespace audio_fingerprint_sdk {

// ==============================================================================
// EN: Audio Fingerprint Engine Constants
// VN: Các hằng số định cấu hình bộ tạo dấu vân tay âm thanh
// ==============================================================================
constexpr int kDefaultSampleRate       = 16000;  // 16 kHz mono audio
constexpr int kDefaultFrameSize        = 1024;   // 1024-point FFT frame
constexpr int kDefaultHopSize          = 256;    // 75% overlap (hop = 256 samples)
constexpr int kDefaultFreqBins         = 513;    // 1024 / 2 + 1 frequency bins
constexpr int kDefaultMaxPeaksPerFrame = 5;      // Top-5 peaks per time slice
constexpr int kDefaultTimeDeltaBits    = 16;     // Bit length for delta time
constexpr int kDefaultFreqBits         = 9;      // 9 bits per frequency bin (0..511)
constexpr float kMinPeakEnergyDB       = -60.0f; // Silence threshold (-60 dB)
constexpr float kPI                    = 3.14159265358979323846f;

// ==============================================================================
// EN: Landmark Peak Parameters Struct (Offset 0x0..0x30 in landmark_peak_afp_t)
// VN: Cấu trúc tham số dò tìm đỉnh mốc quang phổ (Khớp nạp q0, q1, q2 tại 0x323c)
// ==============================================================================
#pragma pack(push, 4)
struct landmark_peak_para_t {
    int sample_rate;          // +0x00: Tần số lấy mẫu (e.g., 16000 Hz)
    int frame_size;           // +0x04: Độ dài khung biến đổi FFT (1024)
    int hop_size;             // +0x08: Bước nhảy khung thời gian (256)
    int max_peaks_per_frame;  // +0x0C: Số đỉnh cực đại tối đa mỗi khung (5)
    float min_freq_hz;        // +0x10: Tần số quét cận dưới (e.g., 200 Hz)
    float max_freq_hz;        // +0x14: Tần số quét cận trên (e.g., 5000 Hz)
    float threshold_db;       // +0x18: Ngưỡng năng lượng tối thiểu theo dB (-50 dB)
    int neighborhood_time;    // +0x1C: Bán kính lân cận thời gian Delta-T (3 frames)
    int neighborhood_freq;    // +0x20: Bán kính lân cận tần số Delta-F (5 bins)
    int target_pair_count;    // +0x24: Số điểm kết cặp mốc landmark tối đa (3)
    int max_time_delta;       // +0x28: Khoảng cách thời gian tối đa khi ghép cặp
    int format_version;       // +0x2C: Phiên bản định dạng payload nhị phân (1)

    landmark_peak_para_t()
        : sample_rate(kDefaultSampleRate),
          frame_size(kDefaultFrameSize),
          hop_size(kDefaultHopSize),
          max_peaks_per_frame(kDefaultMaxPeaksPerFrame),
          min_freq_hz(200.0f),
          max_freq_hz(5000.0f),
          threshold_db(-50.0f),
          neighborhood_time(3),
          neighborhood_freq(5),
          target_pair_count(3),
          max_time_delta(64),
          format_version(1) {}
};
#pragma pack(pop)

// ==============================================================================
// EN: Time-Frequency Spectral Peak Landmark
// VN: Điểm cực đại mốc thời gian - tần số trong bản đồ chòm sao (Constellation Map)
// ==============================================================================
struct PeakLandmark {
    int time_frame;    // Chỉ số khung thời gian (t)
    int freq_bin;      // Chỉ số thùng tần số (f)
    float magnitude;   // Cường độ năng lượng (dB)

    PeakLandmark() : time_frame(0), freq_bin(0), magnitude(0.0f) {}
    PeakLandmark(int t, int f, float mag) : time_frame(t), freq_bin(f), magnitude(mag) {}
};

// ==============================================================================
// EN: Paired Landmark Hash (Anchor Peak -> Target Peak)
// VN: Cặp điểm mốc liên kết dùng để nhận diện bài hát (Shazam-style landmark hash)
// ==============================================================================
struct LandmarkPair {
    uint32_t anchor_freq : 9;   // f1 (0..511, 9 bits)
    uint32_t target_freq : 9;   // f2 (0..511, 9 bits)
    uint32_t delta_time  : 14;  // dt = t2 - t1 (0..16383, 14 bits)
    uint32_t anchor_time;       // t1 (Khung thời gian gốc)

    LandmarkPair() : anchor_freq(0), target_freq(0), delta_time(0), anchor_time(0) {}
    LandmarkPair(uint32_t f1, uint32_t f2, uint32_t dt, uint32_t t1)
        : anchor_freq(f1 & 0x1FF), target_freq(f2 & 0x1FF),
          delta_time(dt & 0x3FFF), anchor_time(t1) {}

    // EN: Computes 32-bit compact hash key for rapid index lookup
    // VN: Tính mã băm compact 32-bit phục vụ đối chiếu cơ sở dữ liệu nhanh
    uint32_t ComputeKey() const {
        return (anchor_freq << 23) | (target_freq << 14) | (delta_time & 0x3FFF);
    }
};

// ==============================================================================
// EN: Audio Fingerprint Status Codes
// VN: Các mã trạng thái hoạt động của SDK
// ==============================================================================
enum class AFPStatus {
    SUCCESS            = 0,  // Thành công
    INVALID_PARAM      = 1,  // Tham số không hợp lệ
    BUFFER_TOO_SMALL   = 2,  // Bộ đệm âm thanh quá nhỏ
    OUT_OF_MEMORY      = 3,  // Tràn bộ nhớ
    NOT_INITIALIZED    = 4,  // Chưa khởi tạo SDK
    ENCODING_ERROR     = 5   // Lỗi nén chuỗi bit
};

} // namespace audio_fingerprint_sdk

#endif // NEXTAI_OPENCUT_AFP_TYPES_H_
