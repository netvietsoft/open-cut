// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Adversarial Verification Test Suite
// File: afp_verification_test.cpp
// Description: Implementation of rigorous mathematical tests for acoustic fingerprinting.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "afp_verification_test.h"
#include "afp_types.h"
#include "afp_fft.h"
#include "afp_landmark_detector.h"
#include "afp_peak_compressor.h"
#include "afp_sdk.h"

#include <cmath>
#include <algorithm>
#include <iostream>

namespace audio_fingerprint_sdk {

bool AFPVerificationTest::RunAllTests(std::vector<TestResult>* out_results) {
    std::vector<TestResult> results = {
        TestHammingWindowMath(),
        TestRFFTForwardAndBackwardInvertibility(),
        TestSpectrogramMagnitudeDB(),
        TestFrequencyBin9BitCompression(),
        TestTimeDeltaVLQCompression(),
        TestWriteSizeAheadBigEndianRev(),
        TestLandmarkPairKeyComputation(),
        TestEndToEndFingerprintGeneration(),
        TestVersionStringParity(),
    };

    bool all_passed = true;
    for (const auto& r : results) {
        if (!r.passed) {
            all_passed = false;
        }
    }

    if (out_results) {
        *out_results = results;
    }
    return all_passed;
}

/**
 * @brief Test 1: Hamming Window Math and Symmetry.
 * Opcode: 0x3914 (gen_ham_win).
 * Formula: w[n] = 0.54 - 0.46 * cos(2*pi*n / (N - 1)).
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestHammingWindowMath() {
    TestResult r;
    r.test_name = "AFP_HammingWindowMath";

    const int N = 1024;
    std::vector<float> win;
    landmark_peak_afp_t::gen_ham_win(win, N);

    bool size_ok = (win.size() == N);
    bool start_ok = std::fabs(win[0] - 0.08f) < 1e-4f;
    bool end_ok = std::fabs(win[N - 1] - 0.08f) < 1e-4f;
    bool center_ok = std::fabs(win[N / 2] - 1.0f) < 1e-2f;

    bool sym_ok = true;
    for (int i = 0; i < N / 2; ++i) {
        if (std::fabs(win[i] - win[N - 1 - i]) > 1e-5f) {
            sym_ok = false;
            break;
        }
    }

    r.passed = size_ok && start_ok && end_ok && center_ok && sym_ok;
    r.error_margin = std::fabs(win[0] - 0.08f);
    r.message = r.passed ? "gen_ham_win (Opcode 0x3914): w[0]=0.08, w[N/2]=1.00, đối xứng hoàn hảo"
                         : "Lỗi cửa sổ Hamming";
    return r;
}

/**
 * @brief Test 2: RFFT Forward and Backward Invertibility.
 * Opcodes: 0xa3e8 (rfft_forward), 0xa030 (rfft_backward).
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestRFFTForwardAndBackwardInvertibility() {
    TestResult r;
    r.test_name = "AFP_RFFTForwardAndBackwardInvertibilityMath";

    const size_t N = 1024;
    rfft_plan plan = make_rfft_plan(N);

    std::vector<double> original(N);
    std::vector<double> buffer(N);

    for (size_t i = 0; i < N; ++i) {
        double t = static_cast<double>(i) / 16000.0;
        original[i] = 0.5 * std::sin(2.0 * kPI * 440.0 * t) +
                      0.3 * std::cos(2.0 * kPI * 1000.0 * t);
        buffer[i] = original[i];
    }

    rfft_forward(plan, buffer.data());
    rfft_backward(plan, buffer.data());

    double max_err = 0.0;
    for (size_t i = 0; i < N; ++i) {
        max_err = std::max(max_err, std::fabs(original[i] - buffer[i]));
    }

    destroy_rfft_plan(plan);

    r.passed = (max_err < 1e-5);
    r.error_margin = max_err;
    r.message = r.passed ? "rfft_forward (0xa3e8) & rfft_backward (0xa030): Khả nghịch hoàn hảo, max_err < 1e-5"
                         : "Lỗi biến đổi RFFT không khả nghịch";
    return r;
}

/**
 * @brief Test 3: Spectrogram Power and Decibel Magnitude.
 * Frequency bin peak tracking.
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestSpectrogramMagnitudeDB() {
    TestResult r;
    r.test_name = "AFP_SpectrogramMagnitudeDBMath";

    const size_t N = 1024;
    FastFourierTransform fft(N);

    // Pure 440 Hz tone at 16000 Hz sample rate
    // Expected bin: 440 * 1024 / 16000 = 28.16 -> Bin 28
    std::vector<float> time_signal(N);
    for (size_t i = 0; i < N; ++i) {
        float t = static_cast<float>(i) / 16000.0f;
        time_signal[i] = std::sin(2.0f * kPI * 440.0f * t);
    }

    size_t num_bins = N / 2 + 1;
    std::vector<float> mag_db(num_bins);
    fft.ComputeMagnitudeDB(time_signal.data(), mag_db.data(), N);

    int peak_bin = 0;
    float max_mag = -999.0f;
    for (size_t k = 0; k < num_bins; ++k) {
        if (mag_db[k] > max_mag) {
            max_mag = mag_db[k];
            peak_bin = static_cast<int>(k);
        }
    }

    bool bin_ok = (peak_bin == 28);
    bool mag_ok = (max_mag > 10.0f); // Positive dB peak

    r.passed = bin_ok && mag_ok;
    r.error_margin = std::fabs(peak_bin - 28);
    r.message = r.passed ? "ComputeMagnitudeDB: Đỉnh phổ tần số 440 Hz rơi chính xác vào Bin 28"
                         : "Lỗi tính toán phổ decibel";
    return r;
}

/**
 * @brief Test 4: Frequency Bin 9-bit Compression and Exact Decompression.
 * Opcode: 0x56cc (compress_frequency_data).
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestFrequencyBin9BitCompression() {
    TestResult r;
    r.test_name = "AFP_FrequencyBin9BitCompressionMath";

    std::vector<int> original_freqs = { 15, 250, 480, 10, 511, 0, 128, 300 };
    std::vector<unsigned char> compressed;
    PeakCompressor::compress_frequency_data(compressed, original_freqs);

    // Output length: 2 (header) + ceil(9 * 8 / 8) = 2 + 9 = 11 bytes
    bool len_ok = (compressed.size() == 11);

    std::vector<int> decompressed;
    PeakCompressor::decompress_frequency_data(compressed, decompressed);

    bool exact_match = (decompressed == original_freqs);

    r.passed = len_ok && exact_match;
    r.error_margin = 0.0;
    r.message = r.passed ? "compress_frequency_data (Opcode 0x56cc): Đóng gói 9-bit chính xác 100% (11 bytes cho 8 đỉnh)"
                         : "Lỗi nén thùng tần số 9-bit";
    return r;
}

/**
 * @brief Test 5: Time-Delta VLQ Compression and Decompression.
 * Opcode: 0x48ec (compress_time_data).
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestTimeDeltaVLQCompression() {
    TestResult r;
    r.test_name = "AFP_TimeDeltaVLQCompressionMath";

    std::vector<int> time_series = { 5, 12, 19, 150, 280, 5000, 5100 };
    std::vector<unsigned char> compressed;
    PeakCompressor::compress_time_data(compressed, time_series);

    std::vector<int> decompressed;
    PeakCompressor::decompress_time_data(compressed, decompressed);

    bool match = (decompressed == time_series);

    r.passed = match;
    r.error_margin = 0.0;
    r.message = r.passed ? "compress_time_data (Opcode 0x48ec): Nén delta-time VLQ giải mã 100% khớp chuỗi thời gian"
                         : "Lỗi nén delta-time";
    return r;
}

/**
 * @brief Test 6: write_size_ahead Big-Endian 32-bit Header.
 * Opcode: 0x6950 (write_size_ahead).
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestWriteSizeAheadBigEndianRev() {
    TestResult r;
    r.test_name = "AFP_WriteSizeAheadBigEndianRev";

    std::vector<unsigned char> payload(0x1234, 0xAA);
    PeakCompressor::write_size_ahead(payload);

    // 4-byte header prepended
    bool len_ok = (payload.size() == 0x1234 + 4);
    uint32_t read_size = (static_cast<uint32_t>(payload[0]) << 24) |
                         (static_cast<uint32_t>(payload[1]) << 16) |
                         (static_cast<uint32_t>(payload[2]) << 8) |
                         payload[3];

    bool header_ok = (read_size == 0x1234);

    r.passed = len_ok && header_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "write_size_ahead (Opcode 0x6950): Header Big-Endian 'rev w8, w8' khớp 0x00001234"
                         : "Lỗi ghi kích thước payload";
    return r;
}

/**
 * @brief Test 7: Landmark Pair Key 32-bit Hash Computation.
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestLandmarkPairKeyComputation() {
    TestResult r;
    r.test_name = "AFP_LandmarkPairKeyComputationMath";

    uint32_t f1 = 120;  // 9 bits
    uint32_t f2 = 350;  // 9 bits
    uint32_t dt = 25;   // 14 bits
    uint32_t t1 = 1000;

    LandmarkPair pair(f1, f2, dt, t1);
    uint32_t key = pair.ComputeKey();

    uint32_t extracted_f1 = (key >> 23) & 0x1FF;
    uint32_t extracted_f2 = (key >> 14) & 0x1FF;
    uint32_t extracted_dt = key & 0x3FFF;

    bool match = (extracted_f1 == f1 && extracted_f2 == f2 && extracted_dt == dt);

    r.passed = match;
    r.error_margin = 0.0;
    r.message = r.passed ? "LandmarkPair::ComputeKey: Khóa băm 32-bit bảo tồn tuyệt đối (f1=120, f2=350, dt=25)"
                         : "Lỗi mã băm cặp landmark";
    return r;
}

/**
 * @brief Test 8: End-to-End Fingerprint Generation on Synthetic Audio.
 * Opcodes: 0x9230 (ctor), 0x9570 (Process), 0x9574 (GetAudioFingerPrint).
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestEndToEndFingerprintGeneration() {
    TestResult r;
    r.test_name = "AFP_EndToEndFingerprintGeneration";

    AFP_SDK sdk;
    sdk.Init(16000, 1024, 256);

    // Generate 1 second of multi-frequency audio tone
    const int sample_rate = 16000;
    const int num_samples = sample_rate * 1;
    std::vector<int16_t> pcm(num_samples);

    for (int i = 0; i < num_samples; ++i) {
        float t = static_cast<float>(i) / static_cast<float>(sample_rate);
        float s = 0.4f * std::sin(2.0f * kPI * 440.0f * t) +
                  0.3f * std::sin(2.0f * kPI * 880.0f * t) +
                  0.3f * std::sin(2.0f * kPI * 1760.0f * t);
        pcm[i] = static_cast<int16_t>(s * 30000.0f);
    }

    int p_res = sdk.Process(reinterpret_cast<unsigned char*>(pcm.data()), num_samples * sizeof(int16_t));

    std::string fp_base64;
    int fp_res = sdk.GetAudioFingerPrint(fp_base64);

    bool ok = (p_res == 0 && fp_res == 0 && !fp_base64.empty() && fp_base64.size() > 16);

    r.passed = ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "AFP_SDK::GetAudioFingerPrint (0x9574): Tạo thành công chuỗi Base64 dấu vân tay âm thanh"
                         : "Lỗi xuất dấu vân tay âm thanh";
    return r;
}

/**
 * @brief Test 9: SDK Version String Parity.
 * Opcode: 0x94c4 (GetVersion) -> "0.0.3".
 */
AFPVerificationTest::TestResult AFPVerificationTest::TestVersionStringParity() {
    TestResult r;
    r.test_name = "AFP_VersionStringParity";

    std::string ver = AFP_SDK::GetVersion();
    bool ver_ok = (ver == "0.0.3");

    r.passed = ver_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "AFP_SDK::GetVersion (Opcode 0x94c4): Trả về '0.0.3' khớp hằng số tại 0x17c30"
                         : "Lỗi phiên bản SDK";
    return r;
}

} // namespace audio_fingerprint_sdk
