// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Real & Complex Fast Fourier Transform Engine
// File: afp_fft.cpp
// Description: Implementation of PocketFFT/RFFT/CFFT routines matching AArch64
//              binary opcodes in libaudio_fingerprint_sdk.so.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "afp_fft.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

constexpr double kDoublePI = 3.141592653589793238462643383279502884;

// ==============================================================================
// EN: Internal Plan Structures
// VN: Cấu trúc bộ nhớ lưu trữ bảng hệ số lượng giác quay (Twiddle Factors)
// ==============================================================================
struct cfft_plan_i {
    size_t length;
    std::vector<double> twiddle_cos;
    std::vector<double> twiddle_sin;
    std::vector<size_t> bit_reverse;
};

struct rfft_plan_i {
    size_t length;
    cfft_plan cplan;
    std::vector<double> twiddle_cos;
    std::vector<double> twiddle_sin;
};

// Helper: Bit reversal permutation index calculation
static size_t ReverseBits(size_t index, size_t num_bits) {
    size_t rev = 0;
    for (size_t i = 0; i < num_bits; ++i) {
        if ((index >> i) & 1) {
            rev |= (1ULL << (num_bits - 1 - i));
        }
    }
    return rev;
}

extern "C" {

/**
 * @brief make_cfft_plan: Creates complex FFT plan.
 * Matches AArch64 opcode 0x96c8 (196 bytes).
 */
cfft_plan make_cfft_plan(size_t length) {
    if (length == 0) return nullptr;

    auto* plan = new cfft_plan_i();
    plan->length = length;

    // Precompute twiddle factors for e^(-2*pi*i*k/N)
    plan->twiddle_cos.resize(length);
    plan->twiddle_sin.resize(length);
    for (size_t k = 0; k < length; ++k) {
        double angle = -2.0 * kDoublePI * static_cast<double>(k) / static_cast<double>(length);
        plan->twiddle_cos[k] = std::cos(angle);
        plan->twiddle_sin[k] = std::sin(angle);
    }

    // Precompute bit-reversal table if length is power-of-two
    size_t num_bits = 0;
    size_t temp = length;
    while (temp > 1) {
        if (temp & 1) {
            num_bits = 0; // Not power of 2
            break;
        }
        temp >>= 1;
        num_bits++;
    }

    if (num_bits > 0 && (1ULL << num_bits) == length) {
        plan->bit_reverse.resize(length);
        for (size_t i = 0; i < length; ++i) {
            plan->bit_reverse[i] = ReverseBits(i, num_bits);
        }
    }

    return plan;
}

/**
 * @brief destroy_cfft_plan: Releases complex FFT plan.
 * Matches AArch64 opcode 0x9c0c (68 bytes).
 */
void destroy_cfft_plan(cfft_plan plan) {
    delete plan;
}

/**
 * @brief cfft_length: Returns plan size.
 * Matches AArch64 opcode 0xa014 (28 bytes).
 */
size_t cfft_length(cfft_plan plan) {
    return plan ? plan->length : 0;
}

/**
 * @brief cfft_forward: Forward Complex FFT.
 * Matches AArch64 opcode 0x9cb4 (28 bytes).
 * c array layout: [Re(0), Im(0), Re(1), Im(1), ..., Re(N-1), Im(N-1)]
 */
int cfft_forward(cfft_plan plan, double c[]) {
    if (!plan || !c) return -1;
    size_t n = plan->length;

    // Bit-reversal reordering
    if (!plan->bit_reverse.empty()) {
        for (size_t i = 0; i < n; ++i) {
            size_t j = plan->bit_reverse[i];
            if (i < j) {
                std::swap(c[2 * i], c[2 * j]);
                std::swap(c[2 * i + 1], c[2 * j + 1]);
            }
        }
    }

    // Cooley-Tukey Radix-2 Butterfly stages
    for (size_t len = 2; len <= n; len <<= 1) {
        size_t half_len = len >> 1;
        size_t step = n / len;

        for (size_t i = 0; i < n; i += len) {
            for (size_t j = 0; j < half_len; ++j) {
                size_t k = j * step;
                double u_re = c[2 * (i + j)];
                double u_im = c[2 * (i + j) + 1];

                double v_re = c[2 * (i + j + half_len)];
                double v_im = c[2 * (i + j + half_len) + 1];

                double tw_re = plan->twiddle_cos[k];
                double tw_im = plan->twiddle_sin[k];

                // (v_re + i*v_im) * (tw_re + i*tw_im)
                double t_re = v_re * tw_re - v_im * tw_im;
                double t_im = v_re * tw_im + v_im * tw_re;

                c[2 * (i + j)]             = u_re + t_re;
                c[2 * (i + j) + 1]         = u_im + t_im;
                c[2 * (i + j + half_len)]     = u_re - t_re;
                c[2 * (i + j + half_len) + 1] = u_im - t_im;
            }
        }
    }

    return 0;
}

/**
 * @brief cfft_backward: Backward (Inverse) Complex FFT.
 * Matches AArch64 opcode 0x9c90 (28 bytes).
 */
int cfft_backward(cfft_plan plan, double c[]) {
    if (!plan || !c) return -1;
    size_t n = plan->length;

    // Conjugate input
    for (size_t i = 0; i < n; ++i) {
        c[2 * i + 1] = -c[2 * i + 1];
    }

    // Forward FFT
    cfft_forward(plan, c);

    // Conjugate output and scale by 1/N
    double inv_n = 1.0 / static_cast<double>(n);
    for (size_t i = 0; i < n; ++i) {
        c[2 * i] *= inv_n;
        c[2 * i + 1] = -c[2 * i + 1] * inv_n;
    }

    return 0;
}

/**
 * @brief make_rfft_plan: Creates real FFT plan.
 * Matches AArch64 opcode 0x9cd8 (200 bytes).
 */
rfft_plan make_rfft_plan(size_t length) {
    if (length == 0 || (length & 1)) return nullptr; // Must be even

    auto* plan = new rfft_plan_i();
    plan->length = length;
    plan->cplan = make_cfft_plan(length / 2);

    // Split-radix real-to-complex twiddle factors
    size_t half = length / 2;
    plan->twiddle_cos.resize(half + 1);
    plan->twiddle_sin.resize(half + 1);
    for (size_t k = 0; k <= half; ++k) {
        double angle = -kDoublePI * static_cast<double>(k) / static_cast<double>(half);
        plan->twiddle_cos[k] = std::cos(angle);
        plan->twiddle_sin[k] = std::sin(angle);
    }

    return plan;
}

/**
 * @brief destroy_rfft_plan: Releases real FFT plan.
 * Matches AArch64 opcode 0x9f98 (56 bytes).
 */
void destroy_rfft_plan(rfft_plan plan) {
    if (plan) {
        destroy_cfft_plan(plan->cplan);
        delete plan;
    }
}

/**
 * @brief rfft_length: Returns plan size.
 * Matches AArch64 opcode 0x9ff8 (28 bytes).
 */
size_t rfft_length(rfft_plan plan) {
    return plan ? plan->length : 0;
}

/**
 * @brief rfft_forward: Real-to-half-complex forward FFT.
 * Matches AArch64 opcode 0xa3e8 (840 bytes).
 * Takes N real values in c, returns half-complex array in c:
 * [Re(0), Re(1), Im(1), Re(2), Im(2), ..., Re(N/2-1), Im(N/2-1), Re(N/2)]
 */
int rfft_forward(rfft_plan plan, double c[]) {
    if (!plan || !c) return -1;
    size_t n = plan->length;
    size_t half = n / 2;

    // Treat N real inputs as N/2 complex numbers and execute N/2 CFFT
    cfft_forward(plan->cplan, c);

    // Unpack and reconstruct full spectrum via twiddle rotation
    double h1_re, h1_im, h2_re, h2_im;
    double f0_re = c[0];
    double f0_im = c[1];

    c[0] = f0_re + f0_im; // DC component (pure real)
    double f_half_re = f0_re - f0_im; // Nyquist component (stored at end or packed)

    std::vector<double> out(n);
    out[0] = c[0];

    for (size_t k = 1; k < half; ++k) {
        size_t sym = half - k;

        double ck_re = c[2 * k];
        double ck_im = c[2 * k + 1];
        double csym_re = c[2 * sym];
        double csym_im = c[2 * sym + 1];

        h1_re = 0.5 * (ck_re + csym_re);
        h1_im = 0.5 * (ck_im - csym_im);
        h2_re = 0.5 * (ck_im + csym_im);
        h2_im = -0.5 * (ck_re - csym_re);

        double w_re = plan->twiddle_cos[k];
        double w_im = plan->twiddle_sin[k];

        out[2 * k - 1] = h1_re + w_re * h2_re - w_im * h2_im;
        out[2 * k]     = h1_im + w_re * h2_im + w_im * h2_re;
    }

    out[n - 1] = f_half_re; // Nyquist

    // Copy back into c array
    std::memcpy(c, out.data(), n * sizeof(double));
    return 0;
}

/**
 * @brief rfft_backward: Half-complex to real inverse FFT.
 * Matches AArch64 opcode 0xa030 (952 bytes).
 */
int rfft_backward(rfft_plan plan, double c[]) {
    if (!plan || !c) return -1;
    size_t n = plan->length;
    size_t half = n / 2;

    std::vector<double> in(n);
    std::memcpy(in.data(), c, n * sizeof(double));

    double dc = in[0];
    double nyquist = in[n - 1];

    std::vector<double> c_half(n);
    c_half[0] = 0.5 * (dc + nyquist);
    c_half[1] = 0.5 * (dc - nyquist);

    for (size_t k = 1; k < half; ++k) {
        size_t sym = half - k;

        double xk_re = in[2 * k - 1];
        double xk_im = in[2 * k];
        double xsym_re = in[2 * sym - 1];
        double xsym_im = in[2 * sym];

        double h1_re = 0.5 * (xk_re + xsym_re);
        double h1_im = 0.5 * (xk_im - xsym_im);
        double h2_re = 0.5 * (xk_im + xsym_im);
        double h2_im = -0.5 * (xk_re - xsym_re);

        double w_re = plan->twiddle_cos[k];
        double w_im = -plan->twiddle_sin[k]; // Conjugate twiddle

        double a_re = h1_re - (w_re * h2_re - w_im * h2_im);
        double a_im = h1_im - (w_re * h2_im + w_im * h2_re);

        c_half[2 * k]     = a_re;
        c_half[2 * k + 1] = a_im;
    }

    // Run inverse complex FFT on half array
    cfft_backward(plan->cplan, c_half.data());

    // Scale and copy back
    for (size_t i = 0; i < n; ++i) {
        c[i] = c_half[i];
    }

    return 0;
}

} // extern "C"

namespace audio_fingerprint_sdk {

FastFourierTransform::FastFourierTransform(size_t frame_size)
    : frame_size_(frame_size), work_buffer_(frame_size, 0.0) {
    plan_ = make_rfft_plan(frame_size_);
}

FastFourierTransform::~FastFourierTransform() {
    if (plan_) {
        destroy_rfft_plan(plan_);
        plan_ = nullptr;
    }
}

void FastFourierTransform::ComputePowerSpectrum(const float* time_domain, float* power_spectrum, size_t n) {
    if (!time_domain || !power_spectrum || n != frame_size_ || !plan_) return;

    for (size_t i = 0; i < frame_size_; ++i) {
        work_buffer_[i] = static_cast<double>(time_domain[i]);
    }

    rfft_forward(plan_, work_buffer_.data());

    size_t num_bins = frame_size_ / 2 + 1;
    // DC component
    power_spectrum[0] = static_cast<float>(work_buffer_[0] * work_buffer_[0]);

    // Intermediate bins
    for (size_t k = 1; k < frame_size_ / 2; ++k) {
        double re = work_buffer_[2 * k - 1];
        double im = work_buffer_[2 * k];
        power_spectrum[k] = static_cast<float>(re * re + im * im);
    }

    // Nyquist component
    double nyquist = work_buffer_[frame_size_ - 1];
    power_spectrum[num_bins - 1] = static_cast<float>(nyquist * nyquist);
}

void FastFourierTransform::ComputeMagnitudeDB(const float* time_domain, float* mag_db, size_t n) {
    if (!time_domain || !mag_db || n != frame_size_) return;

    size_t num_bins = frame_size_ / 2 + 1;
    std::vector<float> power(num_bins, 0.0f);
    ComputePowerSpectrum(time_domain, power.data(), n);

    for (size_t k = 0; k < num_bins; ++k) {
        float p = std::max(1e-12f, power[k]);
        mag_db[k] = 10.0f * std::log10(p);
    }
}

} // namespace audio_fingerprint_sdk
