// ============================================================================
// File: whisper.hpp
// Target: libwhisper.so (38,584 bytes, SHA-256: 03cd8fc0d2b50f1f7e0a6e77258eb704db5cb7c52a167c7581b4bce1f9b73406)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance Audio Spread-Spectrum Watermark & GF(2^m) BCH + Real FFT Engine
//         (Exports: InitWMInfo, FreeWMInfo, EmbedAudioChannelFloat, EmbedAudioChannelInt16)
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <vector>

namespace nextai::opencut::whisper {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của libwhisper.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 38584U;
inline constexpr const char* kBinarySha256Hex          = "03cd8fc0d2b50f1f7e0a6e77258eb704db5cb7c52a167c7581b4bce1f9b73406";
inline constexpr std::uint64_t kPltStartVa             = 0x000006F0ULL;
inline constexpr std::size_t kPltSizeBytes             = 144U;          // 7 PLT slots
inline constexpr std::uint64_t kTextStartVa            = 0x00000780ULL;
inline constexpr std::uint64_t kTextEndVa              = 0x00003788ULL;
inline constexpr std::size_t kTextSizeBytes            = 12296U;        // 3,074 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 3074U;
inline constexpr std::uint64_t kRodataStartVa          = 0x00003790ULL;
inline constexpr std::size_t kRodataSizeBytes          = 17720U;        // 0x3790..0x7CC8
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x00007CC8ULL;
inline constexpr std::size_t kSubroutineCount          = 13U;

// ============================================================================
// 2. Watermark & BCH Codec Constants (Observed in 0x07bc..0x31d8)
//    Hằng số thủy vân âm thanh (Watermark) và mã sửa lỗi BCH GF(2^m)
// ============================================================================
inline constexpr std::uint32_t kWmBitBufferLength      = 106U;     // 0x6A bytes allocated in InitWMInfo (@ 0x1d40)
inline constexpr std::uint32_t kWmMaxPayload10Bit      = 0x03FFU;  // 1023 max 10-bit payload (@ 0x1d58)
inline constexpr std::int32_t  kWmOk                   = 0;
inline constexpr std::int32_t  kWmErrInvalidPayload    = -2;       // mov w0, #-2 (@ 0x1d64)
inline constexpr std::int32_t  kWmErrInvalidSampleRate = -3;
inline constexpr std::int32_t  kWmErrFrameSizeMismatch = -4;       // mov w0, #-4 (@ 0x28e0, 0x2fb0)
inline constexpr std::int32_t  kWmWarmupFrames         = 20;       // cmp w8, #0x13 (@ 0x28b8, 0x2f94)
inline constexpr std::uint32_t kReciprocalDiv85Magic   = 0x4D4873EDU; // (@ 0x28f8..0x28fc, 0x2fbc..0x2fc0)

// Default primitive polynomials for GF(2^m), m = 5..15 at .rodata 0x3798
// Đa thức nguyên thủy mặc định cho trường hữu hạn GF(2^m) với m = 5..15 tại .rodata 0x3798
extern const std::array<std::uint32_t, 11> kDefaultPrimitivePolynomials_3798;

// ============================================================================
// 3. Reconstructed ABI Structures (BchControl 128B & WMInfoContext 64B)
//    Cấu trúc ABI được tái tạo từ mã máy (BchControl 128B & WMInfoContext 64B)
// ============================================================================
struct BchControl {
    std::int32_t  m;              // +0x00: GF degree m (5 <= m <= 15)
    std::int32_t  n;              // +0x04: codeword length 2^m - 1
    std::int32_t  ecc_bits;       // +0x08: number of parity bits (m * t)
    std::int32_t  ecc_bytes;      // +0x0C: (ecc_bits + 7) / 8
    std::int32_t  t;              // +0x10: error-correction capability
    std::int32_t  pad_14;         // +0x14
    std::uint16_t* alpha_to;      // +0x18: GF exponential table
    std::uint16_t* index_of;      // +0x20: GF logarithmic table
    std::uint32_t* gen_poly;      // +0x28: packed generator polynomial words
    std::uint32_t* ecc_buf;       // +0x30: working syndrome/parity buffer
    void*          table_38;      // +0x38..+0x78: auxiliary lookup buffers freed in BchFreeCodec_19e8
    void*          table_40;
    void*          table_48;
    void*          table_50;
    void*          table_58;
    void*          table_60;
    void*          table_68;
    void*          table_70;
    void*          table_78;
};

struct WMInfoContext {
    std::uint8_t* bit_sequence;   // +0x00: 106-byte (0x6A) spread-spectrum bit array
    std::int32_t  bit_index;      // +0x08: current bit/frame counter
    std::int32_t  frame_phase;    // +0x0C: sub-frame phase counter
    std::int32_t  frame_size;     // +0x10: expected PCM frame length (power of 2, e.g. 512 or 1024)
    std::int32_t  sample_rate;    // +0x14: audio sample rate (e.g. 44100 or 48000)
    float         embed_gain;     // +0x24: psychoacoustic embedding scale factor
    float*        window_buf;     // +0x28: analysis/synthesis window buffer
    float*        work_fft_buf;   // +0x30: frequency-domain work buffer
    std::int32_t  warmup_count;   // +0x38: warmup frame counter (skips first 20 frames)
};

struct SubroutineDescriptor {
    std::uint32_t index;
    std::uint64_t start_va;
    std::uint64_t end_va;
    std::uint32_t size_bytes;
    const char*   symbol_name;
    const char*   description;
};

extern const std::array<SubroutineDescriptor, kSubroutineCount> kSubroutineTable;
extern const std::array<std::uint32_t, kTextInstructionCount> kTextInstructionWords;
extern const std::array<std::uint8_t, kRodataSizeBytes> kRodataBytes_3790;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

// ============================================================================
// 4. Clean-Room Reconstructed Internal & Exported C APIs
//    Khai báo các hàm nội bộ và 4 hàm C xuất khẩu của libwhisper.so
// ============================================================================
void BchEncodeBytes_1a78(
    const std::uint8_t* data,
    std::uint8_t* ecc_out,
    std::int32_t len,
    std::int32_t pad) noexcept;

std::int32_t EmbedWatermarkFrameDsp_298c(
    float* pcm_frame,
    WMInfoContext* ctx) noexcept;

void RealFftForward_31d8(const float* input, float* output, std::size_t n) noexcept;
void RealFftInverse_338c(const float* input, float* output, std::size_t n) noexcept;

extern "C" {

// Export [14] 0x1d1c..0x2864 (2,888 bytes) — InitWMInfo
int InitWMInfo(
    WMInfoContext* out_ctx,
    std::uint32_t sample_rate,
    const void* config_ptr,
    std::uint32_t wm_payload_10bit) noexcept;

// Export [20] 0x2864..0x2894 (48 bytes) — FreeWMInfo
void FreeWMInfo(WMInfoContext* ctx) noexcept;

// Export [17] 0x2894..0x298c (248 bytes) — EmbedAudioChannelFloat
int EmbedAudioChannelFloat(
    WMInfoContext* ctx,
    float* pcm_samples,
    std::int32_t num_samples) noexcept;

// Export [11] 0x2f68..0x31d8 (624 bytes) — EmbedAudioChannelInt16
int EmbedAudioChannelInt16(
    WMInfoContext* ctx,
    std::int16_t* pcm_samples,
    std::int32_t num_samples) noexcept;

} // extern "C"

} // namespace nextai::opencut::whisper
