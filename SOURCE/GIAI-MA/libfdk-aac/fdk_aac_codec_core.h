// ============================================================================
// File: fdk_aac_codec_core.h
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Public C/C++ API declarations for Fraunhofer FDK AAC Decoder, Encoder,
//     Transport, SBR, Parametric Stereo, Peak Limiter, and Fixed-Point Math.
// VI: Khai báo API C/C++ cho Fraunhofer FDK AAC Decoder, Encoder, Transport,
//     SBR, Parametric Stereo, Peak Limiter và Toán học dấu phẩy tĩnh.
// ============================================================================
#pragma once

#include "fdk_aac_types.h"

namespace opencut {
namespace fdk_aac {

// EN: Exact memory requirement queries verified from 0x01cd34..0x01cdcc and 0x04a0c4..0x04a13c
// VI: Các hàm truy vấn dung lượng bộ nhớ chính xác xác minh từ 0x01cd34..0x01cdcc và 0x04a0c4..0x04a13c
uint32_t GetRequiredMemAacDecoder() noexcept;
uint32_t GetRequiredMemAacDecoderStaticChannelInfo() noexcept;
uint32_t GetRequiredMemAacDecoderDynamicData() noexcept;
uint32_t GetRequiredMemAacDecoderChannelInfo() noexcept;
uint32_t GetRequiredMemOverlapBuffer() noexcept;
uint32_t GetRequiredMemDrcInfo() noexcept;
uint32_t GetRequiredMemCProgramConfig() noexcept;
uint32_t GetRequiredMemWorkBufferCore2() noexcept;
uint32_t GetRequiredMemTpDec() noexcept;
uint32_t GetRequiredMemSbrDecoder() noexcept;
uint32_t GetRequiredMemSbrDecChannelElement() noexcept;
uint32_t GetRequiredMemSbrDecWorkBuffer1() noexcept;
uint32_t GetRequiredMemSbrDecWorkBuffer2() noexcept;
uint32_t GetRequiredMemPsDecoder() noexcept;

// EN: Fixed-point arithmetic & DSP primitives verified from 0x041d80..0x046f58
// VI: Các phép toán dấu phẩy tĩnh & DSP nguyên thủy xác minh từ 0x041d80..0x046f58
FIXP_DBL mul_dbl_sgl_rnd(FIXP_DBL op1, FIXP_SGL op2) noexcept;
FIXP_DBL schur_div(FIXP_DBL num, FIXP_DBL den, int32_t count) noexcept;
FIXP_DBL CalcLdInt(int32_t i) noexcept;
FIXP_DBL sqrtFixp(FIXP_DBL op) noexcept;
FIXP_DBL fixp_cos(FIXP_DBL phi, int32_t scale) noexcept;
FIXP_DBL fixp_sin(FIXP_DBL phi, int32_t scale) noexcept;
void dit_fft(FIXP_DBL* data, int32_t ldn, int32_t* pScale) noexcept;

// EN: Bitbuffer & Bitstream operations verified from 0x041d80..0x04258c
// VI: Các thao tác Bitbuffer & Bitstream xác minh từ 0x041d80..0x04258c
void FDK_CreateBitBuffer(FDK_BITBUF* hBitBuf, uint8_t* pBuffer, uint32_t bufSize) noexcept;
void FDK_InitBitBuffer(FDK_BITBUF* hBitBuf, uint8_t* pBuffer, uint32_t bufSize, uint32_t validBits) noexcept;
void FDK_ResetBitBuffer(FDK_BITBUF* hBitBuf) noexcept;
void FDK_DeleteBitBuffer(FDK_BITBUF* hBitBuf) noexcept;
int32_t FDK_getValidBits(const FDK_BITBUF* hBitBuf) noexcept;
int32_t FDK_getFreeBits(const FDK_BITBUF* hBitBuf) noexcept;
uint32_t FDK_get(FDK_BITBUF* hBitBuf, uint32_t numberOfBits) noexcept;
void FDK_put(FDK_BITBUF* hBitBuf, uint32_t value, uint32_t numberOfBits) noexcept;

// EN: AAC Encoder bit-reservoir & frame calculation verified from 0x028770..0x02879c
// VI: Tính toán kho bit & số bit mỗi khung của AAC Encoder xác minh từ 0x028770..0x02879c
int32_t FDKaacEnc_CalcBitsPerFrame(int32_t bitRate, int32_t frameLength, int32_t sampleRate) noexcept;

// EN: AAC Decoder lifecycle & frame decoding verified from 0x01d21c..0x01ebc0
// VI: Vòng đời AAC Decoder & giải mã khung âm thanh xác minh từ 0x01d21c..0x01ebc0
AAC_DECODER_INSTANCE* aacDecoder_Open(TRANSPORT_TYPE transportFmt, uint32_t nrOfLayers) noexcept;
void aacDecoder_Close(AAC_DECODER_INSTANCE* self) noexcept;
AAC_DECODER_ERROR aacDecoder_ConfigRaw(AAC_DECODER_INSTANCE* self, uint8_t* conf[], const uint32_t length[]) noexcept;
AAC_DECODER_ERROR aacDecoder_Fill(AAC_DECODER_INSTANCE* self, uint8_t* pBuffer[], const uint32_t bufferSize[], uint32_t* bytesValid) noexcept;
AAC_DECODER_ERROR aacDecoder_DecodeFrame(AAC_DECODER_INSTANCE* self, INT_PCM* pTimeData, int32_t timeDataSize, uint32_t flags) noexcept;
CStreamInfo* aacDecoder_GetStreamInfo(AAC_DECODER_INSTANCE* self) noexcept;

// EN: AAC Encoder lifecycle & frame encoding verified from 0x022e84..0x024bb0
// VI: Vòng đời AAC Encoder & mã hóa khung âm thanh xác minh từ 0x022e84..0x024bb0
AACENC_ERROR aacEncOpen(AACENCODER** phAacEncoder, uint32_t encModules, uint32_t maxChannels) noexcept;
AACENC_ERROR aacEncClose(AACENCODER** phAacEncoder) noexcept;
AACENC_ERROR aacEncoder_SetParam(AACENCODER* hAacEncoder, uint32_t param, uint32_t value) noexcept;
uint32_t aacEncoder_GetParam(const AACENCODER* hAacEncoder, uint32_t param) noexcept;
AACENC_ERROR aacEncEncode(AACENCODER* hAacEncoder, const INT_PCM* inPcm, int32_t inSamples, uint8_t* outBuf, int32_t outBufSize, int32_t* outBytes) noexcept;

// EN: Peak Limiter lifecycle verified from 0x041090..0x0418ac
// VI: Vòng đời bộ giới hạn đỉnh TLimiter xác minh từ 0x041090..0x0418ac
TLimiter* createLimiter(uint32_t maxAttackMs, uint32_t releaseMs, FIXP_DBL threshold, uint32_t maxChannels, uint32_t maxSampleRate) noexcept;
int32_t destroyLimiter(TLimiter* limiter) noexcept;
int32_t resetLimiter(TLimiter* limiter) noexcept;
int32_t applyLimiter(TLimiter* limiter, FIXP_DBL* pGain, INT_PCM* samples, const int32_t* pGainScale, uint32_t gain_size, uint32_t nSamples) noexcept;

// EN: FDE table execution entry point across all 1,471 AArch64 FDEs
// VI: Điểm nhập thực thi bảng FDE trên toàn bộ 1.471 hàm AArch64 FDE
uint64_t ExecuteFdkAacFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;

} // namespace fdk_aac
} // namespace opencut
