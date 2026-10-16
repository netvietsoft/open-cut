// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Peak Bitstream Compressor Engine
// File: afp_peak_compressor.h
// Description: Variable-length bitstream packing, time-delta encoding, and
//              frequency-bin compression matching AArch64 binary opcodes.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_AFP_PEAK_COMPRESSOR_H_
#define NEXTAI_OPENCUT_AFP_PEAK_COMPRESSOR_H_

#include <cstdint>
#include <vector>
#include <string>

namespace audio_fingerprint_sdk {

class PeakCompressor {
public:
    /**
     * @brief compress_time_data: Compresses time index stream using delta-time bit packing.
     * Matches AArch64 opcode 0x48ec (2712 bytes).
     * VN: Nén mảng chỉ số thời gian theo phương pháp hiệu phân tích lũy delta-time.
     */
    static void compress_time_data(std::vector<unsigned char>& out_data,
                                   const std::vector<int>& time_data);

    /**
     * @brief compress_frequency_data: Compresses frequency bins using 9-bit bit-packing.
     * Matches AArch64 opcode 0x56cc (444 bytes).
     * Output byte size: ceil(9 * N / 8) + 2 bytes count header.
     * VN: Nén mảng thùng tần số sử dụng đóng gói 9-bit chặt chẽ.
     */
    static void compress_frequency_data(std::vector<unsigned char>& out_data,
                                        const std::vector<int>& freq_data);

    /**
     * @brief get_bitstring_from_int: Converts integer into binary string of length bit_len.
     * Matches AArch64 opcode 0x6528 (600 bytes).
     * VN: Chuyển đổi số nguyên thành chuỗi bit nhị phân với số bit chỉ định.
     */
    static void get_bitstring_from_int(std::string& out_bits,
                                       const int& value,
                                       const int& bit_len);

    /**
     * @brief write_bitstring: Serializes binary string ('0'/'1') into byte vector.
     * Matches AArch64 opcode 0x6780 (464 bytes).
     * VN: Ghi tuần tự chuỗi bit nhị phân vào vector byte.
     */
    static void write_bitstring(std::vector<unsigned char>& out_bytes,
                                const std::string& bitstring,
                                const int& start_offset);

    /**
     * @brief write_size_ahead: Prepends big-endian 32-bit payload size header.
     * Matches AArch64 opcode 0x6950 (216 bytes).
     * Notice AArch64 'rev w8, w8' instruction.
     * VN: Ghi kích thước gói dữ liệu 32-bit dạng Big-Endian lên đầu vector.
     */
    static void write_size_ahead(std::vector<unsigned char>& data);

    /**
     * @brief get_int_from_sub_bitstring: Decodes integer from bitstring slice.
     * Matches AArch64 opcode 0x6e64 (632 bytes).
     * VN: Trích xuất và giải mã số nguyên từ một đoạn chuỗi bit con.
     */
    static void get_int_from_sub_bitstring(unsigned int& out_value,
                                           const std::string& bitstring,
                                           const int& start_pos,
                                           const int& bit_len);

    // Complementary decompression routines for verification tests
    static void decompress_frequency_data(const std::vector<unsigned char>& in_data,
                                          std::vector<int>& out_freq_data);

    static void decompress_time_data(const std::vector<unsigned char>& in_data,
                                     std::vector<int>& out_time_data);
};

} // namespace audio_fingerprint_sdk

#endif // NEXTAI_OPENCUT_AFP_PEAK_COMPRESSOR_H_
