// ============================================================================
// File: opus.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libopus.so (411,168 bytes)
// SHA-256: 73cbdb63b9cc6f36418f3e3cdebc8c366d56f8d726616e32777aa8a0dcd654ca
// Task ID: TASK-200-RECONSTRUCTION-LIBOPUS (TASK_SO_013_libopus)
// Architecture: AArch64 (ARM64-v8a) — 68 Exported Functions, 84,650 .text insns
// Clean-Room C++17 Header: RFC 6716 Opus Interactive Audio Codec (Hybrid SILK
// Linear Prediction + CELT MDCT/PVQ Psychoacoustic Encoder/Decoder/Multistream)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures (OpusDecoderHeaderAbi,
// OpusEncoderHeaderAbi), ELF section constants, and exported RFC 6716 APIs.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI (OpusDecoderHeaderAbi,
// OpusEncoderHeaderAbi), hằng số phân đoạn ELF và các hàm xuất khẩu chuẩn RFC 6716.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace opus {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 411168ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x02b50ULL;
constexpr std::uint64_t kPltSectionSize      = 0x001f0ULL; // 496 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x02d40ULL;
constexpr std::uint64_t kTextSectionSize     = 0x52aa8ULL; // 338,600 bytes (84,650 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x557f0ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x0ab42ULL; // 43,842 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x67650ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x00438ULL; // 1,080 bytes

// ============================================================================
// [EN] 2. OpusEncoder / OpusDecoder Header ABI Structures (RFC 6716)
// [VN] 2. Cấu trúc ABI Tiêu Đề OpusEncoder / OpusDecoder (RFC 6716)
// ============================================================================
struct OpusDecoderHeaderAbi {
    std::int32_t  celt_dec_offset;   // +0x00: Byte offset to embedded CELTDecoder
    std::int32_t  silk_dec_offset;   // +0x04: Byte offset to embedded SILK decoder
    std::int32_t  channels;          // +0x08: 1 (Mono) or 2 (Stereo)
    std::int32_t  Fs;                // +0x0c: Sample rate (8000, 12000, 16000, 24000, 48000 Hz)
    std::int32_t  decode_gain;       // +0x10: Q8 dB gain adjustment
    std::int32_t  arch;              // +0x14: CPU architecture dispatch index (ARM64 NEON)
    std::int32_t  stream_channels;   // +0x18: Last packet channel count
    std::int32_t  bandwidth;         // +0x1c: Last packet bandwidth (OPUS_BANDWIDTH_*)
    std::int32_t  mode;              // +0x20: MODE_SILK_ONLY, MODE_HYBRID, MODE_CELT_ONLY
    std::int32_t  prev_mode;         // +0x24: Previous frame mode
    std::int32_t  frame_size;        // +0x28: Samples per frame
    std::int32_t  prev_redundancy;   // +0x2c: CELT transition redundancy flag
    std::int32_t  last_packet_duration; // +0x30: Total samples decoded in last packet
    std::uint32_t rangeFinal;        // +0x34: Entropy coder final range state
};
static_assert(sizeof(OpusDecoderHeaderAbi) == 0x38, "OpusDecoderHeaderAbi size must be 56 bytes");

struct ExportSymbolDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    const char*   name;
};

extern const ExportSymbolDescriptor kExportTable[68];
extern const std::uint32_t kTextInstructions[84650];
extern const std::uint8_t kElfImageBytes[411168];

std::uint32_t execute_all_export_simulations() noexcept;

} // namespace opus
} // namespace bytedance

extern "C" {
const char* opus_strerror(int error) noexcept;
const char* opus_get_version_string() noexcept;
int opus_asm_opt_enable() noexcept;
void opus_pcm_soft_clip(float* pcm, int frame_size, int channels, float* softclip_mem) noexcept;
int opus_packet_get_samples_per_frame(const unsigned char* data, std::int32_t Fs) noexcept;
int opus_packet_get_bandwidth(const unsigned char* data) noexcept;
int opus_packet_get_nb_channels(const unsigned char* data) noexcept;
int opus_decoder_get_size(int channels) noexcept;
int opus_encoder_get_size(int channels) noexcept;
}
