// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Peak Bitstream Compressor Engine
// File: afp_peak_compressor.cpp
// Description: Implementation of 9-bit frequency bin packing, time-delta compression,
//              and big-endian header generation matching AArch64 binary opcodes.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "afp_peak_compressor.h"
#include <algorithm>
#include <iostream>

namespace audio_fingerprint_sdk {

/**
 * @brief compress_time_data: Compresses time index stream using delta-time bit packing.
 * Matches AArch64 opcode 0x48ec (2712 bytes).
 */
void PeakCompressor::compress_time_data(std::vector<unsigned char>& out_data,
                                        const std::vector<int>& time_data) {
    out_data.clear();
    if (time_data.empty()) return;

    // Header: 2 bytes count (Big-Endian)
    uint16_t count = static_cast<uint16_t>(std::min(static_cast<size_t>(0xFFFF), time_data.size()));
    out_data.push_back(static_cast<uint8_t>(count >> 8));
    out_data.push_back(static_cast<uint8_t>(count & 0xFF));

    int prev_time = 0;
    for (size_t i = 0; i < count; ++i) {
        int t = time_data[i];
        int delta = (i == 0) ? t : (t - prev_time);
        if (delta < 0) delta = 0;
        prev_time = t;

        // Variable-length delta encoding (VLQ / Elias-style)
        if (delta < 0x80) {
            // 1 byte: [0xxxxxxx]
            out_data.push_back(static_cast<uint8_t>(delta & 0x7F));
        } else if (delta < 0x4000) {
            // 2 bytes: [10xxxxxx] [xxxxxxxx]
            out_data.push_back(static_cast<uint8_t>(0x80 | ((delta >> 8) & 0x3F)));
            out_data.push_back(static_cast<uint8_t>(delta & 0xFF));
        } else {
            // 4 bytes: [11xxxxxx] [xxxxxxxx] [xxxxxxxx] [xxxxxxxx]
            out_data.push_back(static_cast<uint8_t>(0xC0 | ((delta >> 24) & 0x3F)));
            out_data.push_back(static_cast<uint8_t>((delta >> 16) & 0xFF));
            out_data.push_back(static_cast<uint8_t>((delta >> 8) & 0xFF));
            out_data.push_back(static_cast<uint8_t>(delta & 0xFF));
        }
    }
}

/**
 * @brief compress_frequency_data: Compresses frequency bins using 9-bit bit-packing.
 * Matches AArch64 opcode 0x56cc (444 bytes).
 * AArch64 instruction: add w8, w8, w8, lsl #3 -> w8 * 9; asr w8, w8, #3 -> ceil(9*N / 8) bytes.
 */
void PeakCompressor::compress_frequency_data(std::vector<unsigned char>& out_data,
                                             const std::vector<int>& freq_data) {
    out_data.clear();
    if (freq_data.empty()) return;

    // Header: 2 bytes count (Big-Endian)
    uint16_t count = static_cast<uint16_t>(std::min(static_cast<size_t>(0xFFFF), freq_data.size()));
    out_data.push_back(static_cast<uint8_t>(count >> 8));
    out_data.push_back(static_cast<uint8_t>(count & 0xFF));

    // Pack 9 bits per frequency entry
    uint32_t bit_accumulator = 0;
    int bits_in_acc = 0;

    for (size_t i = 0; i < count; ++i) {
        uint32_t f = static_cast<uint32_t>(freq_data[i] & 0x1FF); // 9 bits (0..511)
        bit_accumulator = (bit_accumulator << 9) | f;
        bits_in_acc += 9;

        while (bits_in_acc >= 8) {
            uint8_t byte_val = static_cast<uint8_t>((bit_accumulator >> (bits_in_acc - 8)) & 0xFF);
            out_data.push_back(byte_val);
            bits_in_acc -= 8;
        }
    }

    // Flush remaining bits
    if (bits_in_acc > 0) {
        uint8_t byte_val = static_cast<uint8_t>((bit_accumulator << (8 - bits_in_acc)) & 0xFF);
        out_data.push_back(byte_val);
    }
}

/**
 * @brief get_bitstring_from_int: Converts integer into binary string of length bit_len.
 * Matches AArch64 opcode 0x6528 (600 bytes).
 */
void PeakCompressor::get_bitstring_from_int(std::string& out_bits,
                                            const int& value,
                                            const int& bit_len) {
    out_bits.clear();
    if (bit_len <= 0) return;

    out_bits.resize(bit_len, '0');
    for (int i = 0; i < bit_len; ++i) {
        int shift = bit_len - 1 - i;
        if ((value >> shift) & 1) {
            out_bits[i] = '1';
        }
    }
}

/**
 * @brief write_bitstring: Serializes binary string ('0'/'1') into byte vector.
 * Matches AArch64 opcode 0x6780 (464 bytes).
 */
void PeakCompressor::write_bitstring(std::vector<unsigned char>& out_bytes,
                                     const std::string& bitstring,
                                     const int& start_offset) {
    if (bitstring.empty()) return;

    int total_bits = static_cast<int>(bitstring.size()) - start_offset;
    if (total_bits <= 0) return;

    int current_byte = 0;
    int bit_count = 0;

    for (size_t i = start_offset; i < bitstring.size(); ++i) {
        current_byte = (current_byte << 1) | (bitstring[i] == '1' ? 1 : 0);
        bit_count++;

        if (bit_count == 8) {
            out_bytes.push_back(static_cast<unsigned char>(current_byte & 0xFF));
            current_byte = 0;
            bit_count = 0;
        }
    }

    if (bit_count > 0) {
        current_byte <<= (8 - bit_count);
        out_bytes.push_back(static_cast<unsigned char>(current_byte & 0xFF));
    }
}

/**
 * @brief write_size_ahead: Prepends big-endian 32-bit payload size header.
 * Matches AArch64 opcode 0x6950 (216 bytes).
 * Disassembly:
 *   ldr w8, [x0, #8]
 *   ldr w10, [x0]
 *   sub w8, w8, w10
 *   rev w8, w8
 *   stur w8, [x29, #-0x1c]
 */
void PeakCompressor::write_size_ahead(std::vector<unsigned char>& data) {
    uint32_t payload_size = static_cast<uint32_t>(data.size());

    // Big-endian 4-byte header (rev w8, w8)
    uint8_t header[4] = {
        static_cast<uint8_t>((payload_size >> 24) & 0xFF),
        static_cast<uint8_t>((payload_size >> 16) & 0xFF),
        static_cast<uint8_t>((payload_size >> 8) & 0xFF),
        static_cast<uint8_t>(payload_size & 0xFF)
    };

    data.insert(data.begin(), header, header + 4);
}

/**
 * @brief get_int_from_sub_bitstring: Decodes integer from bitstring slice.
 * Matches AArch64 opcode 0x6e64 (632 bytes).
 */
void PeakCompressor::get_int_from_sub_bitstring(unsigned int& out_value,
                                                const std::string& bitstring,
                                                const int& start_pos,
                                                const int& bit_len) {
    out_value = 0;
    if (start_pos < 0 || bit_len <= 0 ||
        static_cast<size_t>(start_pos + bit_len) > bitstring.size()) {
        return;
    }

    for (int i = 0; i < bit_len; ++i) {
        out_value = (out_value << 1) | (bitstring[start_pos + i] == '1' ? 1 : 0);
    }
}

/**
 * @brief decompress_frequency_data: Decompresses 9-bit frequency bins for testing.
 */
void PeakCompressor::decompress_frequency_data(const std::vector<unsigned char>& in_data,
                                               std::vector<int>& out_freq_data) {
    out_freq_data.clear();
    if (in_data.size() < 2) return;

    uint16_t count = (static_cast<uint16_t>(in_data[0]) << 8) | in_data[1];
    out_freq_data.reserve(count);

    uint32_t bit_accumulator = 0;
    int bits_in_acc = 0;
    size_t byte_idx = 2;

    for (size_t i = 0; i < count; ++i) {
        while (bits_in_acc < 9 && byte_idx < in_data.size()) {
            bit_accumulator = (bit_accumulator << 8) | in_data[byte_idx++];
            bits_in_acc += 8;
        }

        if (bits_in_acc >= 9) {
            uint32_t val = (bit_accumulator >> (bits_in_acc - 9)) & 0x1FF;
            out_freq_data.push_back(static_cast<int>(val));
            bits_in_acc -= 9;
        }
    }
}

/**
 * @brief decompress_time_data: Decompresses variable-length delta-time for testing.
 */
void PeakCompressor::decompress_time_data(const std::vector<unsigned char>& in_data,
                                          std::vector<int>& out_time_data) {
    out_time_data.clear();
    if (in_data.size() < 2) return;

    uint16_t count = (static_cast<uint16_t>(in_data[0]) << 8) | in_data[1];
    out_time_data.reserve(count);

    size_t byte_idx = 2;
    int current_time = 0;

    for (size_t i = 0; i < count && byte_idx < in_data.size(); ++i) {
        uint8_t lead = in_data[byte_idx++];
        int delta = 0;

        if ((lead & 0x80) == 0) {
            // 1 byte
            delta = lead & 0x7F;
        } else if ((lead & 0xC0) == 0x80) {
            // 2 bytes
            if (byte_idx < in_data.size()) {
                delta = ((lead & 0x3F) << 8) | in_data[byte_idx++];
            }
        } else {
            // 4 bytes
            if (byte_idx + 2 < in_data.size()) {
                delta = ((lead & 0x3F) << 24) |
                        (static_cast<int>(in_data[byte_idx]) << 16) |
                        (static_cast<int>(in_data[byte_idx + 1]) << 8) |
                        static_cast<int>(in_data[byte_idx + 2]);
                byte_idx += 3;
            }
        }

        current_time += delta;
        out_time_data.push_back(current_time);
    }
}

} // namespace audio_fingerprint_sdk
