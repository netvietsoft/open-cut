// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Real & Complex Fast Fourier Transform Engine
// File: afp_fft.h
// Description: Implementation of PocketFFT/RFFT/CFFT routines matching AArch64
//              binary opcodes in libaudio_fingerprint_sdk.so.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_AFP_FFT_H_
#define NEXTAI_OPENCUT_AFP_FFT_H_

#include <cstddef>
#include <vector>
#include <complex>

extern "C" {

// CFFT Plan & Functions
struct cfft_plan_i;
typedef struct cfft_plan_i* cfft_plan;

// RFFT Plan & Functions
struct rfft_plan_i;
typedef struct rfft_plan_i* rfft_plan;

/**
 * @brief make_cfft_plan: Creates plan for complex FFT.
 * Opcode: 0x96c8 (196 bytes).
 */
cfft_plan make_cfft_plan(size_t length);

/**
 * @brief destroy_cfft_plan: Releases complex FFT plan.
 * Opcode: 0x9c0c (68 bytes).
 */
void destroy_cfft_plan(cfft_plan plan);

/**
 * @brief cfft_forward: Forward Complex FFT.
 * Opcode: 0x9cb4 (28 bytes).
 */
int cfft_forward(cfft_plan plan, double c[]);

/**
 * @brief cfft_backward: Backward (Inverse) Complex FFT.
 * Opcode: 0x9c90 (28 bytes).
 */
int cfft_backward(cfft_plan plan, double c[]);

/**
 * @brief cfft_length: Returns length of complex FFT plan.
 * Opcode: 0xa014 (28 bytes).
 */
size_t cfft_length(cfft_plan plan);

/**
 * @brief make_rfft_plan: Creates plan for real-to-complex FFT.
 * Opcode: 0x9cd8 (200 bytes).
 */
rfft_plan make_rfft_plan(size_t length);

/**
 * @brief destroy_rfft_plan: Releases real FFT plan.
 * Opcode: 0x9f98 (56 bytes).
 */
void destroy_rfft_plan(rfft_plan plan);

/**
 * @brief rfft_length: Returns length of real FFT plan.
 * Opcode: 0x9ff8 (28 bytes).
 */
size_t rfft_length(rfft_plan plan);

/**
 * @brief rfft_forward: Real-to-half-complex forward FFT.
 * Opcode: 0xa3e8 (840 bytes).
 * Packs [Re(0), Re(1), Im(1), Re(2), Im(2), ..., Re(N/2)].
 */
int rfft_forward(rfft_plan plan, double c[]);

/**
 * @brief rfft_backward: Half-complex-to-real inverse FFT.
 * Opcode: 0xa030 (952 bytes).
 */
int rfft_backward(rfft_plan plan, double c[]);

} // extern "C"

namespace audio_fingerprint_sdk {

// C++ Helper wrapper for convenient Spectrogram computations
class FastFourierTransform {
public:
    explicit FastFourierTransform(size_t frame_size);
    ~FastFourierTransform();

    // EN: Computes power spectrum from real-valued audio frame: P[k] = Re^2 + Im^2
    // VN: Tính phổ năng lượng từ khung âm thanh thực
    void ComputePowerSpectrum(const float* time_domain, float* power_spectrum, size_t n);

    // EN: Computes magnitude spectrum in dB: Mag[k] = 10 * log10(P[k] + 1e-12)
    // VN: Tính phổ biên độ tính bằng đơn vị decibel (dB)
    void ComputeMagnitudeDB(const float* time_domain, float* mag_db, size_t n);

    size_t Length() const { return frame_size_; }

private:
    size_t frame_size_;
    rfft_plan plan_;
    std::vector<double> work_buffer_;
};

} // namespace audio_fingerprint_sdk

#endif // NEXTAI_OPENCUT_AFP_FFT_H_
