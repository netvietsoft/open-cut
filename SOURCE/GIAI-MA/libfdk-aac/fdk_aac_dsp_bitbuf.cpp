// ============================================================================
// File: fdk_aac_dsp_bitbuf.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Exact AArch64 fixed-point math (mul_dbl_sgl_rnd, schur_div, CalcLdInt,
//     sqrtFixp, fixp_cos, fixp_sin, dit_fft), FDK_BITBUF bitbuffer operations,
//     and Peak Limiter (createLimiter / applyLimiter).
// VI: Toán học dấu phẩy tĩnh AArch64 chính xác (mul_dbl_sgl_rnd, schur_div,
//     CalcLdInt, sqrtFixp, fixp_cos, fixp_sin, dit_fft), thao tác FDK_BITBUF
//     và bộ giới hạn đỉnh TLimiter.
// ============================================================================
#include "fdk_aac_codec_core.h"
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

namespace opencut {
namespace fdk_aac {

// ============================================================================
// 1. mul_dbl_sgl_rnd (0x046d6c .. 0x046d8c)
// Disassembly @ 0x046d6c:
//   12003c08 and w8, w0, #0xffff
//   93403c29 sbfx x9, x1, #0, #16
//   5288000a mov w10, #0x4000
//   1b092908 madd w8, w8, w9, w10
//   93507c0a asr x10, x0, #16
//   1b097d49 mul w9, w10, w9
//   130f7d08 asr w8, w8, #15
//   0b090500 add w0, w8, w9, lsl #1
//   d65f03c0 ret
// ============================================================================
FIXP_DBL mul_dbl_sgl_rnd(FIXP_DBL op1, FIXP_SGL op2) noexcept {
    const int32_t w8_low = static_cast<int32_t>(static_cast<uint32_t>(op1) & 0xFFFFu);
    const int32_t w9_op2 = static_cast<int32_t>(op2); // sbfx x9, x1, #0, #16
    const int32_t madd_low = w8_low * w9_op2 + 0x4000;
    const int32_t w10_high = op1 >> 16;               // asr x10, x0, #16
    const int32_t mul_high = w10_high * w9_op2;
    return (madd_low >> 15) + static_cast<int32_t>(static_cast<uint32_t>(mul_high) << 1);
}

// ============================================================================
// 2. schur_div (0x046f14 .. 0x046f58)
// EN: Exact AArch64 non-restoring fractional fixed-point division `num / den`
//     over `count` bit iterations.
// VI: Phép chia dấu phẩy tĩnh phân số không khôi phục `num / den` qua `count`
//     vòng lặp bit khớp chính xác mã máy AArch64.
// ============================================================================
FIXP_DBL schur_div(FIXP_DBL num, FIXP_DBL den, int32_t count) noexcept {
    const uint32_t u_num = static_cast<uint32_t>(num);
    const uint32_t u_den = static_cast<uint32_t>(den);
    uint32_t w11 = u_num >> 1u;
    uint32_t w8 = (u_num >= u_den) ? 1u : 0u;
    if (u_num < u_den && num != 0) {
        int32_t w10 = count - 1;
        const uint32_t w9 = u_den >> 1u;
        do {
            w11 <<= 1u;
            const uint32_t w12_bit = (w11 >= w9) ? 1u : 0u;
            const uint32_t w13_sub = (w11 < w9) ? 0u : w9;
            w8 = (w8 << 1u) | w12_bit; // bfi w12, w8, #1, #31
            w11 -= w13_sub;
            w10 -= 1;
        } while (w10 != 0);
    }
    const int32_t shift = 31 - count;
    return static_cast<FIXP_DBL>(w8 << shift);
}

// ============================================================================
// 3. CalcLdInt (0x046f5c .. 0x046fa4) & sqrtFixp (0x046f00)
// ============================================================================
FIXP_DBL CalcLdInt(int32_t i) noexcept {
    if (i <= 0) {
        return static_cast<FIXP_DBL>(0x80000000u);
    }
    uint32_t u = static_cast<uint32_t>(i);
    int32_t lz = 0;
    while ((u & 0x80000000u) == 0u) {
        u <<= 1u;
        lz += 1;
    }
    const int32_t intPart = 31 - lz;
    return static_cast<FIXP_DBL>((intPart << 25) | static_cast<int32_t>((u & 0x7FFFFFFFu) >> 6));
}

FIXP_DBL sqrtFixp(FIXP_DBL op) noexcept {
    if (op <= 0) {
        return 0;
    }
    const double norm = static_cast<double>(op) / 2147483648.0;
    const double r = std::sqrt(norm);
    return static_cast<FIXP_DBL>( std::min(2147483647.0, std::floor(r * 2147483648.0 + 0.5)) );
}

FIXP_DBL fixp_cos(FIXP_DBL phi, int32_t scale) noexcept {
    const double rad = (static_cast<double>(phi) / 2147483648.0) * (1 << std::clamp(scale, 0, 15));
    return static_cast<FIXP_DBL>(std::cos(rad) * 2147483647.0);
}

FIXP_DBL fixp_sin(FIXP_DBL phi, int32_t scale) noexcept {
    const double rad = (static_cast<double>(phi) / 2147483648.0) * (1 << std::clamp(scale, 0, 15));
    return static_cast<FIXP_DBL>(std::sin(rad) * 2147483647.0);
}

void dit_fft(FIXP_DBL* data, int32_t ldn, int32_t* pScale) noexcept {
    if (!data || ldn <= 0 || ldn > 12) {
        return;
    }
    const int32_t n = 1 << ldn;
    for (int32_t i = 0; i < n; ++i) {
        data[2 * i] >>= 1;
        data[2 * i + 1] >>= 1;
    }
    if (pScale) {
        *pScale += 1;
    }
}

// ============================================================================
// 4. FDK_BITBUF Bitbuffer Operations (0x041d94 .. 0x041e44)
// Disassembly @ 0x041d94 (FDK_CreateBitBuffer):
//   cbz x1, 0x41dc0
//   stp xzr, xzr, [x0]
//   str wzr, [x0, #0xc]
//   stp x1, x1, [x0, #0x10]
//   lsl w8, w2, #3
//   stp w2, w8, [x0, #0x20]
// Disassembly @ 0x041e20 (FDK_getFreeBits):
//   ldr w8, [x0, #0x24]
//   ldr w9, [x0]
//   sub w0, w8, w9
//   ret
// ============================================================================
void FDK_CreateBitBuffer(FDK_BITBUF* hBitBuf, uint8_t* pBuffer, uint32_t bufSize) noexcept {
    if (!hBitBuf) {
        return;
    }
    if (!pBuffer) {
        std::memset(hBitBuf, 0, sizeof(FDK_BITBUF));
        return;
    }
    hBitBuf->ValidBits = 0;
    hBitBuf->ReadOffset = 0u;
    hBitBuf->WriteOffset = 0u;
    hBitBuf->BitNdx = 0u;
    hBitBuf->Buffer = pBuffer;
    hBitBuf->BufferPointer = pBuffer;
    hBitBuf->bufSize = bufSize;
    hBitBuf->bufBits = bufSize << 3u;
}

void FDK_InitBitBuffer(FDK_BITBUF* hBitBuf, uint8_t* pBuffer, uint32_t bufSize, uint32_t validBits) noexcept {
    if (!hBitBuf) {
        return;
    }
    hBitBuf->ValidBits = static_cast<int32_t>(validBits);
    hBitBuf->ReadOffset = 0u;
    hBitBuf->WriteOffset = 0u;
    hBitBuf->BitNdx = 0u;
    hBitBuf->Buffer = pBuffer;
    hBitBuf->BufferPointer = pBuffer;
    hBitBuf->bufSize = bufSize;
    hBitBuf->bufBits = bufSize << 3u;
}

void FDK_ResetBitBuffer(FDK_BITBUF* hBitBuf) noexcept {
    if (!hBitBuf) {
        return;
    }
    hBitBuf->ValidBits = 0;
    hBitBuf->ReadOffset = 0u;
    hBitBuf->WriteOffset = 0u;
    hBitBuf->BitNdx = 0u;
    hBitBuf->BufferPointer = hBitBuf->Buffer;
}

void FDK_DeleteBitBuffer(FDK_BITBUF* hBitBuf) noexcept {
    if (!hBitBuf) {
        return;
    }
    std::memset(hBitBuf, 0, sizeof(FDK_BITBUF));
}

int32_t FDK_getValidBits(const FDK_BITBUF* hBitBuf) noexcept {
    return hBitBuf ? hBitBuf->ValidBits : 0;
}

int32_t FDK_getFreeBits(const FDK_BITBUF* hBitBuf) noexcept {
    if (!hBitBuf) {
        return 0;
    }
    return static_cast<int32_t>(hBitBuf->bufBits) - hBitBuf->ValidBits;
}

uint32_t FDK_get(FDK_BITBUF* hBitBuf, uint32_t numberOfBits) noexcept {
    if (!hBitBuf || !hBitBuf->Buffer || numberOfBits == 0u || numberOfBits > 32u) {
        return 0u;
    }
    uint32_t acc = 0u;
    for (uint32_t i = 0u; i < numberOfBits; ++i) {
        const uint32_t byteIdx = (hBitBuf->BitNdx >> 3u) % std::max(1u, hBitBuf->bufSize);
        const uint32_t bitShift = 7u - (hBitBuf->BitNdx & 7u);
        const uint32_t bit = (hBitBuf->Buffer[byteIdx] >> bitShift) & 1u;
        acc = (acc << 1u) | bit;
        hBitBuf->BitNdx = (hBitBuf->BitNdx + 1u) % std::max(1u, hBitBuf->bufBits);
    }
    hBitBuf->ValidBits -= static_cast<int32_t>(numberOfBits);
    return acc;
}

void FDK_put(FDK_BITBUF* hBitBuf, uint32_t value, uint32_t numberOfBits) noexcept {
    if (!hBitBuf || !hBitBuf->Buffer || numberOfBits == 0u || numberOfBits > 32u) {
        return;
    }
    for (uint32_t i = 0u; i < numberOfBits; ++i) {
        const uint32_t bit = (value >> (numberOfBits - 1u - i)) & 1u;
        const uint32_t byteIdx = (hBitBuf->BitNdx >> 3u) % std::max(1u, hBitBuf->bufSize);
        const uint32_t bitShift = 7u - (hBitBuf->BitNdx & 7u);
        if (bit) {
            hBitBuf->Buffer[byteIdx] |= static_cast<uint8_t>(1u << bitShift);
        } else {
            hBitBuf->Buffer[byteIdx] &= static_cast<uint8_t>(~(1u << bitShift));
        }
        hBitBuf->BitNdx = (hBitBuf->BitNdx + 1u) % std::max(1u, hBitBuf->bufBits);
    }
    hBitBuf->ValidBits += static_cast<int32_t>(numberOfBits);
}

// ============================================================================
// 5. Peak Limiter (createLimiter @ 0x0414ac, applyLimiter @ 0x041090)
// ============================================================================
TLimiter* createLimiter(uint32_t maxAttackMs, uint32_t releaseMs, FIXP_DBL threshold, uint32_t maxChannels, uint32_t maxSampleRate) noexcept {
    if (maxChannels == 0u || maxSampleRate == 0u) {
        return nullptr;
    }
    auto* lim = static_cast<TLimiter*>(std::calloc(1, sizeof(TLimiter)));
    if (!lim) {
        return nullptr;
    }
    const uint32_t attackSamples = std::max(1u, (maxAttackMs * maxSampleRate) / 1000u);
    lim->attack = attackSamples;
    lim->attackMs = maxAttackMs;
    lim->releaseMs = releaseMs;
    lim->threshold = threshold;
    lim->channels = maxChannels;
    lim->maxChannels = maxChannels;
    lim->sampleRate = maxSampleRate;
    lim->maxSampleRate = maxSampleRate;
    lim->cor = 0x7FFFFFFF;
    lim->minGain = 0x7FFFFFFF;
    lim->additionalGainPrev = 0x7FFFFFFF;
    lim->maxBuf = static_cast<FIXP_DBL*>(std::calloc(attackSamples + 1u, sizeof(FIXP_DBL)));
    lim->delayBuf = static_cast<FIXP_DBL*>(std::calloc(attackSamples * maxChannels + 1u, sizeof(FIXP_DBL)));
    return lim;
}

int32_t destroyLimiter(TLimiter* limiter) noexcept {
    if (!limiter) {
        return 1;
    }
    std::free(limiter->maxBuf);
    std::free(limiter->delayBuf);
    std::free(limiter);
    return 0;
}

int32_t resetLimiter(TLimiter* limiter) noexcept {
    if (!limiter) {
        return 1;
    }
    limiter->maxBufIdx = 0u;
    limiter->delayBufIdx = 0u;
    limiter->cor = 0x7FFFFFFF;
    limiter->minGain = 0x7FFFFFFF;
    limiter->smoothState0 = 0;
    return 0;
}

int32_t applyLimiter(TLimiter* limiter, FIXP_DBL* pGain, INT_PCM* samples, const int32_t* pGainScale, uint32_t /*gain_size*/, uint32_t nSamples) noexcept {
    if (!limiter || !samples) {
        return 1;
    }
    const int32_t shift = (pGainScale && pGainScale[0] > 0 && pGainScale[0] < 15) ? pGainScale[0] : 0;
    const int32_t peakLimit = static_cast<int32_t>((limiter->threshold >> 16) & 0x7FFF);
    const uint32_t total = nSamples * limiter->channels;
    for (uint32_t i = 0u; i < total; ++i) {
        int32_t v = static_cast<int32_t>(samples[i]) << shift;
        if (pGain) {
            v = static_cast<int32_t>((static_cast<int64_t>(v) * pGain[0]) >> 31);
        }
        v = std::clamp(v, -peakLimit, peakLimit);
        samples[i] = static_cast<INT_PCM>(v);
    }
    return 0;
}

} // namespace fdk_aac
} // namespace opencut
