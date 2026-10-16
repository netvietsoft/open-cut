// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Acoustic Landmark & Constellation Map Engine
// File: afp_landmark_detector.h
// Description: Landmark peak extraction, 2D local maxima detection, and
//              spectral filtering matching AArch64 binary opcodes.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_AFP_LANDMARK_DETECTOR_H_
#define NEXTAI_OPENCUT_AFP_LANDMARK_DETECTOR_H_

#include "afp_types.h"
#include "afp_fft.h"

#include <vector>
#include <deque>
#include <utility>
#include <memory>

namespace audio_fingerprint_sdk {

class landmark_peak_afp_t {
public:
    landmark_peak_afp_t();
    ~landmark_peak_afp_t();

    /**
     * @brief init: Initializes detector with configuration parameters.
     * Matches AArch64 opcode 0x323c (24 bytes).
     */
    void init(const landmark_peak_para_t& para);

    /**
     * @brief inner_init: Allocates FFT buffers, tables, and window functions.
     * Matches AArch64 opcode 0x3254 (1728 bytes).
     */
    void inner_init();

    /**
     * @brief gen_ham_win: Generates symmetric Hamming window of length n.
     * Matches AArch64 opcode 0x3914 (448 bytes).
     * Formula: w[i] = 0.54 - 0.46 * cos(2*pi*i / (n - 1)).
     */
    static void gen_ham_win(std::vector<float>& win, int n);

    /**
     * @brief reset: Resets internal state, queues, and frame counters.
     * Matches AArch64 opcode 0x3b80 (84 bytes).
     */
    void reset();

    /**
     * @brief process: Ingests raw audio PCM bytes (16-bit signed LE).
     * Matches AArch64 opcode 0x3bd4 (304 bytes).
     */
    int process(unsigned char* pcm_data, int length_bytes);

    /**
     * @brief push_frames: Pushes audio samples, applies windowing and FFT.
     * Matches AArch64 opcode 0x3d04 (1364 bytes).
     */
    void push_frames(const int16_t* pcm_begin, const int16_t* pcm_end);

    /**
     * @brief locate_peaks: Extracts local maxima peaks in 2D time-frequency neighborhood.
     * Matches AArch64 opcode 0x4258 (608 bytes).
     */
    void locate_peaks(std::vector<std::pair<int, int>>& out_peaks,
                      const std::vector<std::vector<std::pair<float, bool>>>& spec_matrix,
                      int start_frame, int end_frame);

    /**
     * @brief filter_peaks: Applies density suppression to retain top-K peaks.
     * Matches AArch64 opcode 0x5eb4 (808 bytes).
     */
    void filter_peaks(std::vector<std::vector<std::pair<float, bool>>>& spec_matrix, int max_peaks);

    /**
     * @brief get_afp: Generates serialized audio fingerprint byte vector.
     * Matches AArch64 opcode 0x44b8 (1076 bytes).
     */
    int get_afp(std::vector<unsigned char>& out_fingerprint);

    /**
     * @brief get_afp (3D matrix): Generates constellation map vector of vectors.
     * Matches AArch64 opcode 0x5888 (1580 bytes).
     */
    void get_afp(std::vector<std::vector<std::vector<int>>>& out_constellation);

    // Getters for internal telemetry and inspection
    const landmark_peak_para_t& GetParams() const { return para_; }
    size_t GetTotalFramesProcessed() const { return total_frames_processed_; }
    const std::vector<PeakLandmark>& GetLandmarks() const { return detected_landmarks_; }

private:
    void GeneratePairs();

    landmark_peak_para_t para_;
    bool initialized_;
    size_t total_frames_processed_;

    std::vector<float> hamming_window_;
    std::unique_ptr<FastFourierTransform> fft_;

    std::vector<int16_t> pcm_residual_buffer_;
    // 2D Spectrogram history: [frame_index][freq_bin] -> (magnitude_db, is_peak)
    std::vector<std::vector<std::pair<float, bool>>> spectrogram_history_;
    std::vector<PeakLandmark> detected_landmarks_;
    std::vector<LandmarkPair> landmark_pairs_;
};

} // namespace audio_fingerprint_sdk

#endif // NEXTAI_OPENCUT_AFP_LANDMARK_DETECTOR_H_
